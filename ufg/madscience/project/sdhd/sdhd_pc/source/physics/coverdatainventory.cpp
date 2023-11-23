// File Line: 17
// RVA: 0x469150
// attributes: thunk
UFG::CoverDataInventory *__fastcall UFG::CoverDataInventory::Initialize()
{
  return UFG::CoverDataInventory::GetInstance();
}

// File Line: 22
// RVA: 0x466880
UFG::CoverDataInventory *__fastcall UFG::CoverDataInventory::GetInstance()
{
  if ( (_S9_12 & 1) == 0 )
  {
    _S9_12 |= 1u;
    UFG::qResourceInventory::qResourceInventory(
      &sCoverDataInventory,
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
  UFG::qBaseNodeRB *v4; // rax
  unsigned int v5; // r9d
  char *v6; // r10
  char *v7; // r8
  UFG::qList<UFG::CoverCorner,UFG::CoverCorner,1,0> *v8; // rdx
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *mPrev; // rax

  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
  v4 = resource_data[1].mNode.mChild[0];
  v5 = 0;
  if ( v4 )
    v6 = (char *)resource_data[1].mNode.mChild + (_QWORD)v4;
  else
    v6 = 0i64;
  if ( HIDWORD(resource_data[1].mNode.mParent) )
  {
    do
    {
      v7 = &v6[48 * v5];
      if ( v7 )
      {
        *(_QWORD *)v7 = v7;
        *((_QWORD *)v7 + 1) = v7;
      }
      v7[38] = 0;
      v8 = &this->m_CornerGrid.mGridNodes[(int)(float)((float)(*((float *)v7 + 4) - this->m_CornerGrid.mXMin)
                                                     * this->m_CornerGrid.mGridSizeInv)
                                        + this->m_CornerGrid.mXDim
                                        * (int)(float)((float)(*((float *)v7 + 5) - this->m_CornerGrid.mYMin)
                                                     * this->m_CornerGrid.mGridSizeInv)];
      mPrev = v8->mNode.mPrev;
      mPrev->mNext = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)v7;
      *(_QWORD *)v7 = mPrev;
      *((_QWORD *)v7 + 1) = v8;
      v8->mNode.mPrev = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)v7;
      ++this->m_CornerGrid.mNodeCount;
      ++v5;
    }
    while ( v5 < HIDWORD(resource_data[1].mNode.mParent) );
  }
}

// File Line: 69
// RVA: 0x472FF0
void __fastcall UFG::CoverDataInventory::Remove(UFG::CoverDataInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qBaseNodeRB *v2; // rax
  unsigned int v3; // r8d
  char *v6; // r11
  __int64 v7; // rax
  char *v8; // rdx
  __int64 v9; // rcx
  _QWORD *v10; // rax
  UFG::AICoverComponent *v11; // rcx
  UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *v12; // rbx

  v2 = resource_data[1].mNode.mChild[0];
  v3 = 0;
  if ( v2 )
    v6 = (char *)resource_data[1].mNode.mChild + (_QWORD)v2;
  else
    v6 = 0i64;
  if ( HIDWORD(resource_data[1].mNode.mParent) )
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
      --this->m_CornerGrid.mNodeCount;
    }
    while ( v3 < HIDWORD(resource_data[1].mNode.mParent) );
  }
  UFG::qResourceInventory::Remove(this, resource_data);
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

