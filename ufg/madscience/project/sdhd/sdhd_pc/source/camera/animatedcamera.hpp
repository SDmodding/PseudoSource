// File Line: 31
// RVA: 0x3BEC20
UFG::ComponentIDDesc *__fastcall UFG::AnimatedCameraComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::AnimatedCameraComponent::_DescInit )
  {
    v0 = UFG::GameCameraComponent::AccessComponentDesc();
    ++UFG::BaseCameraComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::BaseCameraComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AnimatedCameraComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::AnimatedCameraComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::AnimatedCameraComponent::_TypeIDesc.mChildren = 0;
    UFG::AnimatedCameraComponent::_DescInit = 1;
    UFG::AnimatedCameraComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::AnimatedCameraComponent::_TypeIDesc;
}

// File Line: 42
// RVA: 0x3C39C0
UFG::qVector3 *__fastcall UFG::ProgressionCameraComponent::GetStreamingPosition(UFG::ProgressionCameraComponent *this)
{
  return &this->mLookCurr;
}

// File Line: 46
// RVA: 0x3C3420
float __fastcall UFG::AnimatedCameraComponent::GetFov(UFG::AnimatedCameraComponent *this)
{
  return (float)(this->mFov * 3.1415927) * 0.0055555557;
}

// File Line: 50
// RVA: 0x3C3DE0
UFG::qBaseNodeRB *__fastcall UFG::AnimatedCameraComponent::GetTarget(UFG::ProgressionCameraComponent *this)
{
  UFG::qBaseNodeRB *result; // rax

  result = (UFG::qBaseNodeRB *)this->mTarget.m_pSimComponent;
  if ( result )
    return result[1].mChild[0];
  return result;
}

