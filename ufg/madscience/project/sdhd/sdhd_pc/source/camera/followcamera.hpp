// File Line: 66
// RVA: 0x3BEDB0
UFG::ComponentIDDesc *__fastcall UFG::FollowCameraComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::FollowCameraComponent::_DescInit )
  {
    v0 = UFG::GameCameraComponent::AccessComponentDesc();
    ++UFG::BaseCameraComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::BaseCameraComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::FollowCameraComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::FollowCameraComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::FollowCameraComponent::_TypeIDesc.mChildren = 0;
    UFG::FollowCameraComponent::_DescInit = 1;
    UFG::FollowCameraComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::FollowCameraComponent::_FollowCameraComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::FollowCameraComponent::_TypeIDesc;
}

// File Line: 80
// RVA: 0x3C3460
float __fastcall UFG::FollowCameraComponent::GetFov(UFG::FollowCameraComponent *this)
{
  return (float)(this->mFov.p0 * 3.1415927) * 0.0055555557;
}

// File Line: 91
// RVA: 0x3CE4D0
void __fastcall UFG::FollowCameraComponent::SnapToDesired(UFG::FollowCameraComponent *this)
{
  UFG::FollowCameraComponent::Snap(this);
}

// File Line: 92
// RVA: 0x3CE4B0
void __fastcall UFG::FollowCameraComponent::SnapToCurrent(UFG::FollowCameraComponent *this)
{
  UFG::FollowCameraComponent::SnapCurrent(this);
}

// File Line: 97
// RVA: 0x3C6D50
UFG::qVector3 *__fastcall UFG::FollowCameraComponent::MotionRelativeDirection(UFG::FollowCameraComponent *this)
{
  return &this->mControllerForward;
}

// File Line: 98
// RVA: 0x3C5F70
bool __fastcall UFG::FollowCameraComponent::IsUsingHighZoom(UFG::FollowCameraComponent *this)
{
  return this->mContext == 6;
}

// File Line: 100
// RVA: 0x3C5EF0
bool __fastcall UFG::FollowCameraComponent::IsAiming(UFG::FollowCameraComponent *this)
{
  return this->mType == 1;
}

// File Line: 107
// RVA: 0x3C3E20
UFG::TargetingSystemBaseComponent *__fastcall UFG::FollowCameraComponent::GetTargetingSystem(UFG::FollowCameraComponent *this)
{
  JUMPOUT(this->mTarget.m_pSimComponent, 0i64, UFG::CharacterSubjectComponent::GetTargetingSystem);
  return 0i64;
}

// File Line: 112
// RVA: 0x3C3DC0
UFG::SimObject *__fastcall UFG::FollowCameraComponent::GetTarget(UFG::FollowCameraComponent *this)
{
  UFG::SimObject *result; // rax

  result = (UFG::SimObject *)this->mTarget.m_pSimComponent;
  if ( result )
    result = (UFG::SimObject *)result->mNode.mParent;
  return result;
}

// File Line: 261
// RVA: 0x3C2D60
float __fastcall UFG::FollowCameraComponent::GetDofDamageMultiplier(UFG::FollowCameraComponent *this)
{
  return this->mBlendedParams.mDamageMultiplier;
}

