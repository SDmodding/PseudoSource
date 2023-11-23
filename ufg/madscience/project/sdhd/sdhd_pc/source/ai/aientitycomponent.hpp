// File Line: 148
// RVA: 0x4166A0
void __fastcall UFG::AIEntityComponent::SetGroupComponent(UFG::AIEntityComponent *this, UFG::GroupComponent *value)
{
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *p_m_pGroupComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v5; // rax

  p_m_pGroupComponent = &this->m_pGroupComponent;
  if ( this->m_pGroupComponent.m_pPointer )
  {
    mPrev = p_m_pGroupComponent->mPrev;
    mNext = p_m_pGroupComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pGroupComponent->mPrev = p_m_pGroupComponent;
    p_m_pGroupComponent->mNext = p_m_pGroupComponent;
  }
  p_m_pGroupComponent->m_pPointer = value;
  if ( value )
  {
    v5 = value->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev;
    v5->mNext = p_m_pGroupComponent;
    p_m_pGroupComponent->mPrev = v5;
    p_m_pGroupComponent->mNext = &value->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode;
    value->UFG::qSafePointerNode<UFG::GroupComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GroupComponent>::mPrev = p_m_pGroupComponent;
  }
}

