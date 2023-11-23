// File Line: 45
// RVA: 0x27B910
UFG::CoverCorner *__fastcall UFG::CoverCornerHandle::Get(UFG::CoverCornerHandle *this)
{
  UFG::DynamicCoverCorner *m_pPointer; // rcx
  UFG::DynamicCoverCorner *v3; // rax
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v6; // rcx
  UFG::qBaseNodeRB **mChild; // rax

  if ( !this->m_ResourceHandle.mData || this->m_uCoverCornerIndex == 0xFFFF )
  {
    m_pPointer = this->m_pDynamicCoverCorner.m_pPointer;
    if ( !m_pPointer
      || !UFG::DynamicCoverComponent::IsEnabled((UFG::DynamicCoverComponent *)m_pPointer->m_pParentInstance.m_pPointer) )
    {
      return 0i64;
    }
  }
  v3 = this->m_pDynamicCoverCorner.m_pPointer;
  if ( v3 )
    return &v3->UFG::CoverCorner;
  mData = this->m_ResourceHandle.mData;
  v6 = mData[1].mNode.mChild[0];
  mChild = mData[1].mNode.mChild;
  if ( v6 )
    return (UFG::CoverCorner *)((char *)v6 + 48 * this->m_uCoverCornerIndex + (_QWORD)mChild);
  else
    return (UFG::CoverCorner *)(48i64 * this->m_uCoverCornerIndex);
}

