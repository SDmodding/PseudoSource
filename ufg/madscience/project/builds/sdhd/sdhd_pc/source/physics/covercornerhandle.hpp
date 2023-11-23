// File Line: 31
// RVA: 0x3595C0
UFG::qResourceData *__fastcall UFG::CoverCornerHandle::Get(UFG::CoverCornerHandle *this)
{
  UFG::DynamicCoverCorner *m_pPointer; // rax
  UFG::qResourceData *result; // rax
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *v3; // rdx

  m_pPointer = this->m_pDynamicCoverCorner.m_pPointer;
  if ( m_pPointer )
    return (UFG::qResourceData *)&m_pPointer->UFG::CoverCorner;
  result = this->m_ResourceHandle.mData;
  if ( result )
  {
    v3 = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)result[1].mNode.mChild[0];
    if ( v3 )
      return (UFG::qResourceData *)((char *)&v3[3 * this->m_uCoverCornerIndex + 6] + (_QWORD)result);
    else
      return (UFG::qResourceData *)(48i64 * this->m_uCoverCornerIndex);
  }
  return result;
}

// File Line: 51
// RVA: 0x382990
void __fastcall UFG::CoverCornerHandle::Reset(UFG::CoverCornerHandle *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qSafePointer<UFG::DynamicCoverCorner,UFG::DynamicCoverCorner> *p_m_pDynamicCoverCorner; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *mNext; // rax

  this->m_uCoverCornerIndex = -1;
  Inventory = `UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x8DADDB7E);
    `UFG::qGetResourceInventory<UFG::CoverDataResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->m_ResourceHandle, Inventory);
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
  this->m_pDynamicCoverCorner.m_pPointer = 0i64;
}

