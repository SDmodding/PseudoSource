// File Line: 41
// RVA: 0x1470250
__int64 UFG::_dynamic_initializer_for__gFarGroundLayoutInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gFarGroundLayoutInventory,
    "FarGroundLayout",
    0x2A05C2B9u,
    0xF40E78D9,
    0,
    0);
  UFG::gFarGroundLayoutInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::FarGroundLayoutInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gFarGroundLayoutInventory__);
}

// File Line: 49
// RVA: 0x22FF40
void __fastcall UFG::FarGroundLayoutInventory::Add(
        UFG::FarGroundLayoutInventory *this,
        UFG::FarGroundLayout *resource_data)
{
  unsigned int i; // esi
  UFG::qBaseNodeRB *mOffset; // rax
  char *v6; // rcx
  UFG::qResourceHandle *v7; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v9; // rax

  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  for ( i = 0; i < resource_data->mClusterCount; ++i )
  {
    mOffset = (UFG::qBaseNodeRB *)resource_data->mClusters.mOffset;
    if ( mOffset )
      v6 = (char *)&resource_data->mClusters + (_QWORD)mOffset;
    else
      v6 = 0i64;
    v7 = (UFG::qResourceHandle *)&v6[112 * i];
    if ( v7 )
      UFG::qResourceHandle::qResourceHandle(v7 + 2);
    Inventory = `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v9, 0xF0A07244);
      `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(v7 + 2, 0xF0A07244, v7[2].mNameUID, Inventory);
  }
  UFG::gFarGroundLayout = resource_data;
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 73
// RVA: 0x234D10
void __fastcall UFG::FarGroundLayoutInventory::Remove(
        UFG::FarGroundLayoutInventory *this,
        UFG::qResourceData *resource_data)
{
  unsigned int v3; // edi
  UFG::qBaseNodeRB *v4; // rax
  char *v5; // rcx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceHandle *v7; // rbx
  UFG::qResourceWarehouse *v8; // rax

  UFG::qResourceInventory::Remove(this, resource_data);
  v3 = 0;
  if ( LODWORD(resource_data[1].mNode.mParent) )
  {
    do
    {
      v4 = resource_data[1].mNode.mChild[0];
      if ( v4 )
        v5 = (char *)resource_data[1].mNode.mChild + (_QWORD)v4;
      else
        v5 = 0i64;
      Inventory = `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result;
      v7 = (UFG::qResourceHandle *)&v5[112 * v3];
      if ( !`UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result )
      {
        v8 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v8, 0xF0A07244);
        `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Close(v7 + 2, Inventory);
      ++v3;
    }
    while ( v3 < LODWORD(resource_data[1].mNode.mParent) );
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
  unsigned int mClusterCount; // r9d
  int v3; // eax
  __int64 mOffset; // r8
  __int64 i; // rdx
  char *v6; // rcx
  char *v7; // rdi
  __int64 v8; // rax
  char *v9; // r12
  unsigned int v10; // ebp
  UFG::SectionChooser::SectionInfo *v11; // rsi
  __int64 v12; // rax
  char *v13; // rcx
  __int64 v14; // r14
  unsigned int v15; // ebx
  unsigned int CellToLoadFromVisIndex; // eax
  __int64 v17; // rax
  int v18; // eax
  UFG::SectionChooser::SectionInfo *v19; // rcx
  __int64 v20; // rax
  __int64 v21; // rcx
  int v22; // r11d
  unsigned int v23; // r8d
  __int64 v24; // r9
  __int64 v25; // rdx
  char *v26; // rax
  char *v27; // rcx

  mClusterCount = UFG::gFarGroundLayout->mClusterCount;
  v3 = 0;
  if ( mClusterCount )
  {
    mOffset = UFG::gFarGroundLayout->mClusters.mOffset;
    for ( i = 0i64; ; i += 112i64 )
    {
      v6 = mOffset ? (char *)&UFG::gFarGroundLayout->mClusters + mOffset : 0i64;
      v7 = &v6[i];
      if ( *(UFG::SceneryGroup **)&v6[i + 80] == pSceneryGroup )
        break;
      if ( ++v3 >= mClusterCount )
        return;
    }
    v8 = *((_QWORD *)v7 + 6);
    if ( v8 )
      v9 = &v7[v8 + 48];
    else
      v9 = 0i64;
    v10 = 0;
    if ( *((_DWORD *)v7 + 5) )
    {
      v11 = UFG::SectionChooser::mSectionInfo;
      do
      {
        v12 = *((_QWORD *)v7 + 3);
        if ( v12 )
          v13 = &v7[v12 + 24];
        else
          v13 = 0i64;
        v14 = 4i64 * v10;
        v15 = *(_DWORD *)&v13[v14];
        CellToLoadFromVisIndex = UFG::SectionChooser::GetCellToLoadFromVisIndex(v15, 1);
        if ( !CellToLoadFromVisIndex
          || v11
          && (v17 = CellToLoadFromVisIndex, v11[v17].meLODLevelCurrent.mValue == 2)
          && v11[v17].meLoadStateSTD.mValue == 2
          || (v18 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v15, 1)) == 0
          || v11
          && ((v19 = &v11[v18], v19->meLODLevelCurrent.mValue != 2)
           || v19->meLoadStateSTD.mValue != 2
           || v19->mChangedStateFrameStamp[2] >= UFG::Metrics::msFrameCount - 2)
          && UFG::SectionChooser::meSuppressLOD != SUPRESS_ISLAND
          && v19->meLoadStateMID.mValue == 2 )
        {
          v20 = *((_QWORD *)v7 + 4);
          v21 = v20 ? (__int64)&v7[v20 + 32] : 0i64;
          v22 = *(_DWORD *)(v14 + v21);
          v23 = 0;
          if ( pSceneryGroup->mNumInstances )
          {
            v24 = pSceneryGroup->mInstances.mOffset;
            v25 = 0i64;
            while ( 1 )
            {
              v26 = v24 ? (char *)&pSceneryGroup->mInstances + v24 : 0i64;
              v27 = &v26[v25];
              if ( *(_DWORD *)&v26[v25] == v22 )
                break;
              ++v23;
              v25 += 96i64;
              if ( v23 >= pSceneryGroup->mNumInstances )
                goto LABEL_40;
            }
            *(_DWORD *)&v9[v14] = *((_DWORD *)v27 + 4);
            *((_QWORD *)v27 + 2) = 0i64;
            v11 = UFG::SectionChooser::mSectionInfo;
          }
        }
LABEL_40:
        ++v10;
      }
      while ( v10 < *((_DWORD *)v7 + 5) );
    }
  }
}

// File Line: 219
// RVA: 0x234330
void __fastcall UFG::FarGroundLayout::OnFarGroundSceneryGroupUnload(UFG::SceneryGroup *pSceneryGroup)
{
  __int64 mOffset; // r8
  char *v3; // rax
  char *v4; // rdi
  __int64 v5; // rax
  __int64 v6; // rbp
  unsigned int i; // r11d
  __int64 v8; // rax
  char *v9; // rcx
  char *v10; // r9
  unsigned int v11; // r10d
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // rdx
  __int64 v15; // rax

  if ( UFG::gFarGroundLayout )
  {
    mOffset = UFG::gFarGroundLayout->mClusters.mOffset;
    v3 = mOffset ? (char *)&UFG::gFarGroundLayout->mClusters + mOffset : 0i64;
    v4 = &v3[112 * pSceneryGroup->mSectionCellIndex - 114688];
    v5 = *((_QWORD *)v4 + 6);
    v6 = v5 ? (__int64)&v4[v5 + 48] : 0i64;
    for ( i = 1; i < pSceneryGroup->mNumInstances; ++i )
    {
      v8 = pSceneryGroup->mInstances.mOffset;
      if ( v8 )
        v9 = (char *)&pSceneryGroup->mInstances + v8;
      else
        v9 = 0i64;
      v10 = &v9[96 * i];
      if ( !*((_QWORD *)v10 + 2) )
      {
        v11 = *((_DWORD *)v4 + 5);
        v12 = 0i64;
        if ( v11 )
        {
          v13 = *((_QWORD *)v4 + 4);
          v14 = 0i64;
          while ( 1 )
          {
            v15 = v13 ? (__int64)&v4[v13 + 32] : 0i64;
            if ( *(_DWORD *)(v14 + v15) == *(_DWORD *)v10 )
              break;
            v12 = (unsigned int)(v12 + 1);
            v14 += 4i64;
            if ( (unsigned int)v12 >= v11 )
              goto LABEL_22;
          }
          *((_QWORD *)v10 + 2) = *(unsigned int *)(v6 + 4 * v12);
        }
      }
LABEL_22:
      ;
    }
  }
}

