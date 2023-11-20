// File Line: 148
// RVA: 0x4166A0
void __fastcall UFG::AIEntityComponent::SetGroupComponent(UFG::AIEntityComponent *this, UFG::GroupComponent *value)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&this->m_pGroupComponent.mPrev;
  if ( this->m_pGroupComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)value;
  if ( value )
  {
    v5 = value->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &value->m_SafePointerList.mNode;
    value->m_SafePointerList.mNode.mPrev = v2;
  }
}

