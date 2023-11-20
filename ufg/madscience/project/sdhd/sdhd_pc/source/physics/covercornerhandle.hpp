// File Line: 45
// RVA: 0x27B910
signed __int64 __fastcall UFG::CoverCornerHandle::Get(UFG::CoverCornerHandle *this)
{
  UFG::CoverCornerHandle *v1; // rbx
  UFG::DynamicCoverCorner *v2; // rcx
  UFG::DynamicCoverCorner *v3; // rax
  signed __int64 result; // rax
  UFG::qResourceData *v5; // rax
  UFG::qBaseNodeRB *v6; // rcx
  signed __int64 v7; // rax

  v1 = this;
  if ( !this->m_ResourceHandle.mData || this->m_uCoverCornerIndex == -1 )
  {
    v2 = this->m_pDynamicCoverCorner.m_pPointer;
    if ( !v2 || !UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)v2->m_pParentInstance.m_pPointer) )
      return 0i64;
  }
  v3 = v1->m_pDynamicCoverCorner.m_pPointer;
  if ( v3 )
    return (signed __int64)&v3->mPrev;
  v5 = v1->m_ResourceHandle.mData;
  v6 = v5[1].mNode.mChild[0];
  v7 = (signed __int64)v5[1].mNode.mChild;
  if ( v6 )
    result = (signed __int64)v6 + 48 * v1->m_uCoverCornerIndex + v7;
  else
    result = 48i64 * v1->m_uCoverCornerIndex;
  return result;
}

