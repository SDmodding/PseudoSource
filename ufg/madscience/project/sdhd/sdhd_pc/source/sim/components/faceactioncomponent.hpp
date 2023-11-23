// File Line: 55
// RVA: 0x51EE60
UFG::ComponentIDDesc *__fastcall UFG::FaceActionComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::FaceActionComponent::_DescInit )
  {
    UFG::FaceActionComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
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
  const char **p_mScriptCommandDebugText; // rdi
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v2; // rbx
  AnimationGroup *mNext; // rcx

  p_mScriptCommandDebugText = &this->mScriptCommandDebugText;
  v2 = this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext - 1;
  if ( v2 == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&this->mScriptCommandDebugText )
    return 1;
  while ( 1 )
  {
    mNext = (AnimationGroup *)v2[3].mNext;
    if ( !mNext || !AnimationGroup::IsStreamedIn(mNext) )
      break;
    v2 = v2[1].mNext - 1;
    if ( v2 == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)p_mScriptCommandDebugText )
      return 1;
  }
  return 0;
}

