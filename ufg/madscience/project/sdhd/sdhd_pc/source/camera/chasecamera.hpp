// File Line: 140
// RVA: 0x3BED20
UFG::ComponentIDDesc *__fastcall UFG::ChaseCameraComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::ChaseCameraComponent::_DescInit )
  {
    v0 = UFG::GameCameraComponent::AccessComponentDesc();
    ++UFG::BaseCameraComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::BaseCameraComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::ChaseCameraComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::ChaseCameraComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::ChaseCameraComponent::_TypeIDesc.mChildren = 0;
    UFG::ChaseCameraComponent::_DescInit = 1;
    UFG::ChaseCameraComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::ChaseCameraComponent::_TypeIDesc;
}

// File Line: 154
// RVA: 0x3CE4C0
void __fastcall UFG::ChaseCameraComponent::SnapToDesired(UFG::ChaseCameraComponent *this)
{
  UFG::ChaseCameraComponent::Snap(this);
}

// File Line: 155
// RVA: 0x3CE4A0
void __fastcall UFG::ChaseCameraComponent::SnapToCurrent(UFG::ChaseCameraComponent *this)
{
  UFG::ChaseCameraComponent::SnapCurrent(this);
}

// File Line: 159
// RVA: 0x3C39D0
UFG::qVector4 *__fastcall UFG::GameCameraComponent::GetStreamingPosition(UFG::GameCameraComponent *this)
{
  return &this->mCamera.mTransformation.v3;
}

// File Line: 160
// RVA: 0x3C5ED0
bool __fastcall UFG::ChaseCameraComponent::IsAiming(UFG::ChaseCameraComponent *this)
{
  UFG::ChaseCameraParameters *v1; // rax

  v1 = this->pChaseParameters;
  return v1 && v1->mContext == eCHASE_CONTEXT_AIM;
}

// File Line: 163
// RVA: 0x3C3E00
UFG::TargetingSystemBaseComponent *__fastcall UFG::ChaseCameraComponent::GetTargetingSystem(UFG::ChaseCameraComponent *this)
{
  JUMPOUT(this->mTarget.m_pSimComponent, 0i64, UFG::VehicleSubjectComponent::GetTargetingSystem);
  return 0i64;
}

// File Line: 168
// RVA: 0x3C3DA0
UFG::SimObject *__fastcall UFG::ChaseCameraComponent::GetTarget(UFG::ChaseCameraComponent *this)
{
  UFG::SimObject *result; // rax

  result = (UFG::SimObject *)this->mTarget.m_pSimComponent;
  if ( result )
    result = (UFG::SimObject *)result->mNode.mParent;
  return result;
}

// File Line: 172
// RVA: 0x3C3440
float __fastcall UFG::ChaseCameraComponent::GetFov(UFG::ChaseCameraComponent *this)
{
  return (float)(this->mFov.p0 * 3.1415927) * 0.0055555557;
}

