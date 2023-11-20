// File Line: 55
// RVA: 0x51EE60
UFG::ComponentIDDesc *__fastcall UFG::FaceActionComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::FaceActionComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::FaceActionComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::FaceActionComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::FaceActionComponent::_DescInit = 1;
    UFG::FaceActionComponent::_TypeUID = UFG::FaceActionComponent::_TypeIDesc.mChildBitMask | (UFG::FaceActionComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::FaceActionComponent::_FaceActionComponentTypeUID = UFG::FaceActionComponent::_TypeIDesc.mChildBitMask | (UFG::FaceActionComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::FaceActionComponent::_TypeIDesc;
}

// File Line: 234
// RVA: 0x27AB60
char __fastcall UFG::FaceActionComponent::AreAnimsLoaded(UFG::FaceActionComponent *this)
{
  const char **v1; // rdi
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v2; // rbx
  AnimationGroup *v3; // rcx

  v1 = &this->mScriptCommandDebugText;
  v2 = this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext - 1;
  if ( v2 == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&this->mScriptCommandDebugText )
    return 1;
  while ( 1 )
  {
    v3 = (AnimationGroup *)v2[3].mNext;
    if ( !v3 || !AnimationGroup::IsStreamedIn(v3) )
      break;
    v2 = v2[1].mNext - 1;
    if ( v2 == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)v1 )
      return 1;
  }
  return 0;
}

