// File Line: 17
// RVA: 0x469150
UFG::CoverDataInventory *__fastcall UFG::CoverDataInventory::Initialize()
{
  return UFG::CoverDataInventory::GetInstance();
}

// File Line: 22
// RVA: 0x466880
UFG::CoverDataInventory *__fastcall UFG::CoverDataInventory::GetInstance()
{
  if ( !(_S9_12 & 1) )
  {
    _S9_12 |= 1u;
    UFG::qResourceInventory::qResourceInventory(
      (UFG::qResourceInventory *)&sCoverDataInventory.vfptr,
      "CoverDataInventory",
      0x8DADDB7E,
      0x5DEB3457u,
      0,
      0);
    sCoverDataInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::CoverDataInventory::`vftable;
    sCoverDataInventory.m_CornerGrid.mGridNodes = 0i64;
    *(_QWORD *)&sCoverDataInventory.m_CornerGrid.mGridSize = 0i64;
    *(_QWORD *)&sCoverDataInventory.m_CornerGrid.mXDim = 0i64;
    *(_QWORD *)&sCoverDataInventory.m_CornerGrid.mXMin = 0i64;
    *(_QWORD *)&sCoverDataInventory.m_CornerGrid.mYMin = 0i64;
    sCoverDataInventory.m_CornerGrid.mNodeCount = 0;
    atexit(UFG::CoverDataInventory::GetInstance_::_2_::_dynamic_atexit_destructor_for__sCoverDataInventory__);
  }
  return &sCoverDataInventory;
}

// File Line: 39
// RVA: 0x454910
void __fastcall UFG::CoverDataInventory::Add(UFG::CoverDataInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::CoverDataInventory *v3; // rdi
  UFG::qBaseNodeRB *v4; // rax
  unsigned int v5; // er9
  signed __int64 v6; // r10
  signed __int64 v7; // r8
  __int64 *v8; // rdx
  __int64 v9; // rax

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
  v4 = v2[1].mNode.mChild[0];
  v5 = 0;
  if ( v4 )
    v6 = (signed __int64)v2[1].mNode.mChild + (_QWORD)v4;
  else
    v6 = 0i64;
  if ( HIDWORD(v2[1].mNode.mParent) > 0 )
  {
    do
    {
      v7 = v6 + 48i64 * v5;
      if ( v7 )
      {
        *(_QWORD *)v7 = v7;
        *(_QWORD *)(v7 + 8) = v7;
      }
      *(_BYTE *)(v7 + 38) = 0;
      v8 = (__int64 *)&v3->m_CornerGrid.mGridNodes[(signed int)(float)((float)(*(float *)(v7 + 16)
                                                                             - v3->m_CornerGrid.mXMin)
                                                                     * v3->m_CornerGrid.mGridSizeInv)
                                                 + v3->m_CornerGrid.mXDim
                                                 * (signed int)(float)((float)(*(float *)(v7 + 20)
                                                                             - v3->m_CornerGrid.mYMin)
                                                                     * v3->m_CornerGrid.mGridSizeInv)];
      v9 = *v8;
      *(_QWORD *)(v9 + 8) = v7;
      *(_QWORD *)v7 = v9;
      *(_QWORD *)(v7 + 8) = v8;
      *v8 = v7;
      ++v3->m_CornerGrid.mNodeCount;
      ++v5;
    }
    while ( v5 < HIDWORD(v2[1].mNode.mParent) );
  }
}

// File Line: 69
// RVA: 0x472FF0
void __fastcall UFG::CoverDataInventory::Remove(UFG::CoverDataInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qBaseNodeRB *v2; // rax
  unsigned int v3; // er8
  UFG::qResourceData *v4; // r9
  UFG::CoverDataInventory *v5; // r10
  char *v6; // r11
  __int64 v7; // rax
  char *v8; // rdx
  __int64 v9; // rcx
  _QWORD *v10; // rax
  UFG::AICoverComponent *v11; // rcx
  UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *v12; // rbx

  v2 = resource_data[1].mNode.mChild[0];
  v3 = 0;
  v4 = resource_data;
  v5 = this;
  if ( v2 )
    v6 = (char *)resource_data[1].mNode.mChild + (_QWORD)v2;
  else
    v6 = 0i64;
  if ( HIDWORD(resource_data[1].mNode.mParent) > 0 )
  {
    do
    {
      v7 = v3++;
      v8 = &v6[48 * v7];
      v9 = *(_QWORD *)v8;
      v10 = (_QWORD *)*((_QWORD *)v8 + 1);
      *(_QWORD *)(v9 + 8) = v10;
      *v10 = v9;
      *(_QWORD *)v8 = v8;
      *((_QWORD *)v8 + 1) = v8;
      --v5->m_CornerGrid.mNodeCount;
    }
    while ( v3 < HIDWORD(v4[1].mNode.mParent) );
  }
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&v5->vfptr, v4);
  v11 = (UFG::AICoverComponent *)&UFG::AICoverComponent::s_AICoverComponentList.mNode.mNext[-4];
  if ( (UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *)&UFG::AICoverComponent::s_AICoverComponentList.mNode.mNext[-4] != &UFG::AICoverComponent::s_AICoverComponentList - 4 )
  {
    do
    {
      v12 = (UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *)&v11->mNext[-4];
      UFG::AICoverComponent::ValidateCover(v11, 0);
      v11 = (UFG::AICoverComponent *)v12;
    }
    while ( v12 != &UFG::AICoverComponent::s_AICoverComponentList - 4 );
  }
}

