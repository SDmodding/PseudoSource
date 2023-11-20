// File Line: 41
// RVA: 0x1470250
__int64 UFG::_dynamic_initializer_for__gFarGroundLayoutInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gFarGroundLayoutInventory.vfptr,
    "FarGroundLayout",
    0x2A05C2B9u,
    0xF40E78D9,
    0,
    0);
  UFG::gFarGroundLayoutInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::FarGroundLayoutInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gFarGroundLayoutInventory__);
}

// File Line: 49
// RVA: 0x22FF40
void __fastcall UFG::FarGroundLayoutInventory::Add(UFG::FarGroundLayoutInventory *this, UFG::qResourceData *resource_data)
{
  UFG::FarGroundLayout *v2; // rdi
  UFG::FarGroundLayoutInventory *v3; // rbp
  unsigned int v4; // esi
  __int64 v5; // rax
  signed __int64 v6; // rcx
  UFG::qResourceHandle *v7; // rbx
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax

  v2 = (UFG::FarGroundLayout *)resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  v4 = 0;
  if ( v2->mClusterCount )
  {
    do
    {
      v5 = v2->mClusters.mOffset;
      if ( v5 )
        v6 = (signed __int64)&v2->mClusters + v5;
      else
        v6 = 0i64;
      v7 = (UFG::qResourceHandle *)(v6 + 112i64 * v4);
      if ( v7 )
        UFG::qResourceHandle::qResourceHandle(v7 + 2);
      v8 = `UFG::qGetResourceInventory<UFG::SceneryGroup>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<UFG::SceneryGroup>'::`2'::result )
      {
        v9 = UFG::qResourceWarehouse::Instance();
        v8 = UFG::qResourceWarehouse::GetInventory(v9, 0xF0A07244);
        `UFG::qGetResourceInventory<UFG::SceneryGroup>'::`2'::result = v8;
      }
      UFG::qResourceHandle::Init(v7 + 2, 0xF0A07244, v7[2].mNameUID, v8);
      ++v4;
    }
    while ( v4 < v2->mClusterCount );
  }
  UFG::gFarGroundLayout = v2;
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v2->mNode);
}

// File Line: 73
// RVA: 0x234D10
void __fastcall UFG::FarGroundLayoutInventory::Remove(UFG::FarGroundLayoutInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rsi
  unsigned int v3; // edi
  UFG::qBaseNodeRB *v4; // rax
  signed __int64 v5; // rcx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceHandle *v7; // rbx
  UFG::qResourceWarehouse *v8; // rax

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3 = 0;
  if ( LODWORD(v2[1].mNode.mParent) )
  {
    do
    {
      v4 = v2[1].mNode.mChild[0];
      if ( v4 )
        v5 = (signed __int64)v2[1].mNode.mChild + (_QWORD)v4;
      else
        v5 = 0i64;
      v6 = `UFG::qGetResourceInventory<UFG::SceneryGroup>'::`2'::result;
      v7 = (UFG::qResourceHandle *)(v5 + 112i64 * v3);
      if ( !`UFG::qGetResourceInventory<UFG::SceneryGroup>'::`2'::result )
      {
        v8 = UFG::qResourceWarehouse::Instance();
        v6 = UFG::qResourceWarehouse::GetInventory(v8, 0xF0A07244);
        `UFG::qGetResourceInventory<UFG::SceneryGroup>'::`2'::result = v6;
      }
      UFG::qResourceHandle::Close(v7 + 2, v6);
      ++v3;
    }
    while ( v3 < LODWORD(v2[1].mNode.mParent) );
    UFG::gFarGroundLayout = 0i64;
  }
  else
  {
    UFG::gFarGroundLayout = 0i64;
  }
}

// File Line: 170
// RVA: 0x234140
void __fastcall UFG::FarGroundLayout::OnFarGroundSceneryGroupLoad(UFG::SceneryGroup *pSceneryGroup)
{
  UFG::SceneryGroup *v1; // r15
  unsigned int v2; // er9
  unsigned int v3; // eax
  __int64 v4; // r8
  __int64 v5; // rdx
  UFG::qOffset64<UFG::Cluster *> *v6; // rcx
  UFG::qOffset64<UFG::Cluster *> *v7; // rdi
  __int64 v8; // rax
  signed __int64 v9; // r12
  unsigned int v10; // ebp
  UFG::SectionChooser::SectionInfo *v11; // rsi
  __int64 v12; // rax
  signed __int64 v13; // rcx
  signed __int64 v14; // r14
  unsigned int v15; // ebx
  unsigned int v16; // eax
  signed __int64 v17; // rax
  unsigned int v18; // eax
  signed __int64 v19; // rcx
  __int64 v20; // rax
  signed __int64 v21; // rcx
  int v22; // er11
  unsigned int v23; // er8
  __int64 v24; // r9
  __int64 v25; // rdx
  signed __int64 v26; // rax
  signed __int64 v27; // rcx

  v1 = pSceneryGroup;
  v2 = UFG::gFarGroundLayout->mClusterCount;
  v3 = 0;
  if ( v2 )
  {
    v4 = UFG::gFarGroundLayout->mClusters.mOffset;
    v5 = 0i64;
    while ( 1 )
    {
      v6 = v4 ? (UFG::qOffset64<UFG::Cluster *> *)((char *)&UFG::gFarGroundLayout->mClusters + v4) : 0i64;
      v7 = &v6[v5];
      if ( (UFG::SceneryGroup *)v6[v5 + 10].mOffset == v1 )
        break;
      ++v3;
      v5 += 14i64;
      if ( v3 >= v2 )
        return;
    }
    v8 = v7[6].mOffset;
    if ( v8 )
      v9 = (signed __int64)&v7[6] + v8;
    else
      v9 = 0i64;
    v10 = 0;
    if ( HIDWORD(v7[2].mOffset) > 0 )
    {
      v11 = UFG::SectionChooser::mSectionInfo;
      do
      {
        v12 = v7[3].mOffset;
        if ( v12 )
          v13 = (signed __int64)&v7[3] + v12;
        else
          v13 = 0i64;
        v14 = 4i64 * v10;
        v15 = *(_DWORD *)(v14 + v13);
        v16 = UFG::SectionChooser::GetCellToLoadFromVisIndex(*(_DWORD *)(v14 + v13), 1);
        if ( v16 < 1
          || v11 && (v17 = v16, v11[v17].meLODLevelCurrent.mValue == 2) && v11[v17].meLoadStateSTD.mValue == 2
          || (v18 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v15, 1), v18 < 1)
          || v11
          && ((v19 = (signed __int64)&v11[v18], *(_BYTE *)(v19 + 4) != 2)
           || *(_BYTE *)(v19 + 1) != 2
           || *(_DWORD *)(v19 + 160) >= UFG::Metrics::msFrameCount - 2)
          && UFG::SectionChooser::meSuppressLOD != 1
          && *(_BYTE *)v19 == 2 )
        {
          v20 = v7[4].mOffset;
          v21 = (signed __int64)(v20 ? (UFG::qOffset64<UFG::Cluster *> *)((char *)&v7[4] + v20) : 0i64);
          v22 = *(_DWORD *)(v14 + v21);
          v23 = 0;
          if ( v1->mNumInstances )
          {
            v24 = v1->mInstances.mOffset;
            v25 = 0i64;
            while ( 1 )
            {
              v26 = (signed __int64)(v24 ? (UFG::qOffset64<UFG::SceneryInstance *> *)((char *)&v1->mInstances + v24) : 0i64);
              v27 = v25 + v26;
              if ( *(_DWORD *)(v25 + v26) == v22 )
                break;
              ++v23;
              v25 += 96i64;
              if ( v23 >= v1->mNumInstances )
                goto LABEL_40;
            }
            *(_DWORD *)(v14 + v9) = *(_DWORD *)(v27 + 16);
            *(_QWORD *)(v27 + 16) = 0i64;
            v11 = UFG::SectionChooser::mSectionInfo;
          }
        }
LABEL_40:
        ++v10;
      }
      while ( v10 < HIDWORD(v7[2].mOffset) );
    }
  }
}

// File Line: 219
// RVA: 0x234330
void __fastcall UFG::FarGroundLayout::OnFarGroundSceneryGroupUnload(UFG::SceneryGroup *pSceneryGroup)
{
  UFG::SceneryGroup *v1; // rsi
  __int64 v2; // r8
  UFG::qOffset64<UFG::Cluster *> *v3; // rax
  signed __int64 v4; // rdi
  __int64 v5; // rax
  signed __int64 v6; // rbp
  unsigned int v7; // er11
  __int64 v8; // rax
  signed __int64 v9; // rcx
  signed __int64 v10; // r9
  unsigned int v11; // er10
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // rdx
  signed __int64 v15; // rax

  v1 = pSceneryGroup;
  if ( UFG::gFarGroundLayout )
  {
    v2 = UFG::gFarGroundLayout->mClusters.mOffset;
    v3 = v2 ? (UFG::qOffset64<UFG::Cluster *> *)((char *)&UFG::gFarGroundLayout->mClusters + v2) : 0i64;
    v4 = (signed __int64)&v3[14 * ((unsigned int)pSceneryGroup->mSectionCellIndex - 1024)];
    v5 = *(_QWORD *)(v4 + 48);
    v6 = v5 ? v4 + v5 + 48 : 0i64;
    v7 = 1;
    if ( pSceneryGroup->mNumInstances > 1u )
    {
      do
      {
        v8 = v1->mInstances.mOffset;
        if ( v8 )
          v9 = (signed __int64)&v1->mInstances + v8;
        else
          v9 = 0i64;
        v10 = v9 + 96i64 * v7;
        if ( !*(_QWORD *)(v10 + 16) )
        {
          v11 = *(_DWORD *)(v4 + 20);
          v12 = 0i64;
          if ( v11 )
          {
            v13 = *(_QWORD *)(v4 + 32);
            v14 = 0i64;
            while ( 1 )
            {
              v15 = v13 ? v4 + v13 + 32 : 0i64;
              if ( *(_DWORD *)(v14 + v15) == *(_DWORD *)v10 )
                break;
              v12 = (unsigned int)(v12 + 1);
              v14 += 4i64;
              if ( (unsigned int)v12 >= v11 )
                goto LABEL_22;
            }
            *(_QWORD *)(v10 + 16) = *(unsigned int *)(v6 + 4 * v12);
          }
        }
LABEL_22:
        ++v7;
      }
      while ( v7 < v1->mNumInstances );
    }
  }
}

