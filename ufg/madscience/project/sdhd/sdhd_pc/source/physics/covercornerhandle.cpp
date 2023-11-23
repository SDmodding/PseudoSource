// File Line: 10
// RVA: 0x4497E0
void __fastcall UFG::CoverCornerHandle::CoverCornerHandle(UFG::CoverCornerHandle *this)
{
  UFG::qResourceHandle::qResourceHandle(&this->m_ResourceHandle);
  this->m_pDynamicCoverCorner.mPrev = &this->m_pDynamicCoverCorner;
  this->m_pDynamicCoverCorner.mNext = &this->m_pDynamicCoverCorner;
  this->m_pDynamicCoverCorner.m_pPointer = 0i64;
  this->m_uCoverCornerIndex = -1;
}

// File Line: 15
// RVA: 0x449670
void __fastcall UFG::CoverCornerHandle::CoverCornerHandle(UFG::CoverCornerHandle *this, UFG::CoverCorner *pCorner)
{
  UFG::qTypedResourceHandle<2376981374,UFG::CoverDataResource> *p_m_ResourceHandle; // r14
  UFG::qSafePointer<UFG::DynamicCoverCorner,UFG::DynamicCoverCorner> *p_m_pDynamicCoverCorner; // r8
  UFG::DynamicCoverCorner *p_z; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::CoverDataInventory *Instance; // rax
  Render::SkinningCacheNode *Head; // rbx
  UFG::CoverDataInventory *v12; // rax
  UFG::qBaseTreeRB *Next; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> *v14; // rax
  __int64 v15; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v17; // rax

  p_m_ResourceHandle = &this->m_ResourceHandle;
  UFG::qResourceHandle::qResourceHandle(&this->m_ResourceHandle);
  p_m_pDynamicCoverCorner = &this->m_pDynamicCoverCorner;
  this->m_pDynamicCoverCorner.mPrev = &this->m_pDynamicCoverCorner;
  this->m_pDynamicCoverCorner.mNext = &this->m_pDynamicCoverCorner;
  this->m_pDynamicCoverCorner.m_pPointer = 0i64;
  if ( pCorner->m_IsDynamic )
  {
    p_z = (UFG::DynamicCoverCorner *)&pCorner[-1].m_vCornerPosition.z;
    if ( this->m_pDynamicCoverCorner.m_pPointer )
    {
      mPrev = p_m_pDynamicCoverCorner->mPrev;
      mNext = this->m_pDynamicCoverCorner.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pDynamicCoverCorner->mPrev = p_m_pDynamicCoverCorner;
      this->m_pDynamicCoverCorner.mNext = &this->m_pDynamicCoverCorner;
    }
    this->m_pDynamicCoverCorner.m_pPointer = p_z;
    if ( pCorner != (UFG::CoverCorner *)24 )
    {
      v9 = p_z->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::DynamicCoverCorner>::mPrev;
      v9->mNext = p_m_pDynamicCoverCorner;
      p_m_pDynamicCoverCorner->mPrev = v9;
      this->m_pDynamicCoverCorner.mNext = &p_z->m_SafePointerList.mNode;
      p_z->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::DynamicCoverCorner>::mPrev = p_m_pDynamicCoverCorner;
    }
    goto LABEL_15;
  }
  UFG::CoverDataInventory::GetInstance();
  Instance = UFG::CoverDataInventory::GetInstance();
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&Instance->mResourceDatas);
  if ( !Head )
  {
LABEL_15:
    this->m_uCoverCornerIndex = -1;
    return;
  }
  while ( 1 )
  {
    v12 = UFG::CoverDataInventory::GetInstance();
    Next = UFG::qBaseTreeRB::GetNext(&v12->mResourceDatas.mTree, (UFG::qBaseNodeRB *)Head);
    v14 = Head[2].mNode.mChild[1];
    if ( v14 )
      v14 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((char *)v14 + (_QWORD)Head + 96);
    v15 = ((char *)pCorner - (char *)v14) / 48;
    if ( (unsigned int)v15 < HIDWORD(Head[2].mNode.mChild0) )
      break;
    Head = (Render::SkinningCacheNode *)Next;
    if ( !Next )
      goto LABEL_15;
  }
  Inventory = `UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result )
  {
    v17 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v17, 0x8DADDB7E);
    `UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(p_m_ResourceHandle, 0x8DADDB7E, Head->mNode.mUID, Inventory);
  this->m_uCoverCornerIndex = v15;
}

// File Line: 65
// RVA: 0x4527A0
UFG::CoverCornerHandle *__fastcall UFG::CoverCornerHandle::operator=(
        UFG::CoverCornerHandle *this,
        UFG::CoverCornerHandle *rhs)
{
  UFG::qResourceData *mData; // rax
  unsigned int mUID; // esi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::DynamicCoverCorner *m_pPointer; // r8
  UFG::qSafePointer<UFG::DynamicCoverCorner,UFG::DynamicCoverCorner> *p_m_pDynamicCoverCorner; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v14; // rax

  UFG::CoverCornerHandle::Reset(this);
  this->m_uCoverCornerIndex = rhs->m_uCoverCornerIndex;
  mData = rhs->m_ResourceHandle.mData;
  if ( mData )
  {
    mUID = mData->mNode.mUID;
    Inventory = `UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x8DADDB7E);
      `UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->m_ResourceHandle, 0x8DADDB7E, mUID, Inventory);
  }
  else
  {
    v8 = `UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x8DADDB7E);
      `UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result = v8;
    }
    UFG::qResourceHandle::Close(&this->m_ResourceHandle, v8);
  }
  m_pPointer = rhs->m_pDynamicCoverCorner.m_pPointer;
  p_m_pDynamicCoverCorner = &this->m_pDynamicCoverCorner;
  if ( this->m_pDynamicCoverCorner.m_pPointer )
  {
    mPrev = p_m_pDynamicCoverCorner->mPrev;
    mNext = this->m_pDynamicCoverCorner.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pDynamicCoverCorner->mPrev = p_m_pDynamicCoverCorner;
    this->m_pDynamicCoverCorner.mNext = &this->m_pDynamicCoverCorner;
  }
  this->m_pDynamicCoverCorner.m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v14 = m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::DynamicCoverCorner>::mPrev;
    v14->mNext = p_m_pDynamicCoverCorner;
    p_m_pDynamicCoverCorner->mPrev = v14;
    this->m_pDynamicCoverCorner.mNext = &m_pPointer->m_SafePointerList.mNode;
    m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::DynamicCoverCorner>::mPrev = p_m_pDynamicCoverCorner;
  }
  return this;
}

// File Line: 86
// RVA: 0x452890
UFG::CoverCornerHandle *__fastcall UFG::CoverCornerHandle::operator=(
        UFG::CoverCornerHandle *this,
        UFG::CoverCorner *pCorner)
{
  UFG::CoverCornerHandle *v3; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::CoverCornerHandle rhs; // [rsp+30h] [rbp-48h] BYREF

  UFG::CoverCornerHandle::CoverCornerHandle(&rhs, pCorner);
  v3 = UFG::CoverCornerHandle::operator=(this, &rhs);
  if ( rhs.m_pDynamicCoverCorner.m_pPointer )
  {
    mPrev = rhs.m_pDynamicCoverCorner.mPrev;
    mNext = rhs.m_pDynamicCoverCorner.mNext;
    rhs.m_pDynamicCoverCorner.mPrev->mNext = rhs.m_pDynamicCoverCorner.mNext;
    mNext->mPrev = mPrev;
    rhs.m_pDynamicCoverCorner.mPrev = &rhs.m_pDynamicCoverCorner;
    rhs.m_pDynamicCoverCorner.mNext = &rhs.m_pDynamicCoverCorner;
  }
  rhs.m_pDynamicCoverCorner.m_pPointer = 0i64;
  v6 = rhs.m_pDynamicCoverCorner.mPrev;
  v7 = rhs.m_pDynamicCoverCorner.mNext;
  rhs.m_pDynamicCoverCorner.mPrev->mNext = rhs.m_pDynamicCoverCorner.mNext;
  v7->mPrev = v6;
  rhs.m_pDynamicCoverCorner.mPrev = &rhs.m_pDynamicCoverCorner;
  rhs.m_pDynamicCoverCorner.mNext = &rhs.m_pDynamicCoverCorner;
  Inventory = `UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v9, 0x8DADDB7E);
    `UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&rhs.m_ResourceHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&rhs.m_ResourceHandle);
  return v3;
}

