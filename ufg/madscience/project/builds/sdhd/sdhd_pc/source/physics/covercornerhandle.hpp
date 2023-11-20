// File Line: 31
// RVA: 0x3595C0
signed __int64 __fastcall UFG::CoverCornerHandle::Get(UFG::CoverCornerHandle *this)
{
  UFG::DynamicCoverCorner *v1; // rax
  signed __int64 result; // rax
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *v3; // rdx

  v1 = this->m_pDynamicCoverCorner.m_pPointer;
  if ( v1 )
    return (signed __int64)&v1->mPrev;
  result = (signed __int64)this->m_ResourceHandle.mData;
  if ( result )
  {
    v3 = *(UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> **)(result + 96);
    if ( v3 )
      result += (signed __int64)&v3[3 * this->m_uCoverCornerIndex + 6];
    else
      result = 48i64 * this->m_uCoverCornerIndex;
  }
  return result;
}

// File Line: 51
// RVA: 0x382990
void __fastcall UFG::CoverCornerHandle::Reset(UFG::CoverCornerHandle *this)
{
  UFG::CoverCornerHandle *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qSafePointer<UFG::DynamicCoverCorner,UFG::DynamicCoverCorner> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  this->m_uCoverCornerIndex = -1;
  v2 = `UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x8DADDB7E);
    `UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->m_ResourceHandle.mPrev, v2);
  v4 = &v1->m_pDynamicCoverCorner;
  if ( v1->m_pDynamicCoverCorner.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v1->m_pDynamicCoverCorner.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v1->m_pDynamicCoverCorner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v1->m_pDynamicCoverCorner.mPrev;
  }
  v1->m_pDynamicCoverCorner.m_pPointer = 0i64;
}

