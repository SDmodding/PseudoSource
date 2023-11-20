// File Line: 29
// RVA: 0xB9880
UFG::ComponentIDDesc *__fastcall UFG::BaseCameraComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::BaseCameraComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::BaseCameraComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::BaseCameraComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::BaseCameraComponent::_DescInit = 1;
    UFG::BaseCameraComponent::_TypeUID = UFG::BaseCameraComponent::_TypeIDesc.mChildBitMask | (UFG::BaseCameraComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::BaseCameraComponent::_BaseCameraComponentTypeUID = UFG::BaseCameraComponent::_TypeIDesc.mChildBitMask | (UFG::BaseCameraComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::BaseCameraComponent::_TypeIDesc;
}

// File Line: 38
// RVA: 0xB9A30
void __fastcall UFG::BaseCameraComponent::EnableControllers(UFG::BaseCameraComponent *this, bool enable)
{
  this->mControllersEnabled = enable;
}

// File Line: 39
// RVA: 0xB9AD0
float __fastcall UFG::BaseCameraComponent::GetFov(UFG::BaseCameraComponent *this)
{
  return FLOAT_1_7453293;
}

// File Line: 42
// RVA: 0xBA250
void __fastcall UFG::BaseCameraComponent::SetActive(UFG::BaseCameraComponent *this, bool active)
{
  this->mActive = active;
}

// File Line: 43
// RVA: 0xB9CB0
_BOOL8 __fastcall UFG::BaseCameraComponent::IsActive(UFG::BaseCameraComponent *this)
{
  return this->mActive;
}

// File Line: 49
// RVA: 0xBA260
void __fastcall UFG::BaseCameraComponent::SetCurrent(UFG::BaseCameraComponent *this, bool current)
{
  this->mCurrent = current;
}

// File Line: 57
// RVA: 0xB9AF0
void __usercall UFG::BaseCameraComponent::GetFovRadians(UFG::BaseCameraComponent *this@<rcx>, float *fov@<rdx>, float *velocity@<r8>, int a4@<xmm0>)
{
  float *v4; // rdi
  float *v5; // rbx

  v4 = velocity;
  v5 = fov;
  ((void (*)(void))this->vfptr[19].__vecDelDtor)();
  *(_DWORD *)v5 = a4;
  *v4 = 0.0;
}

// File Line: 58
// RVA: 0xBA670
void __fastcall UFG::BaseCameraComponent::SetFovRadians(UFG::BaseCameraComponent *this, float fov, float fov_velocity)
{
  UFG::Camera::SetFov(&this->mCamera, fov);
}

// File Line: 60
// RVA: 0xB9A80
void __fastcall UFG::BaseCameraComponent::GetEyeWorld(UFG::BaseCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  v3 = this->mEyeCurr.y;
  v4 = this->mEyeCurr.z;
  position->x = this->mEyeCurr.x;
  position->y = v3;
  position->z = v4;
  v5 = this->mEyeVelocity.y;
  v6 = this->mEyeVelocity.z;
  velocity->x = this->mEyeVelocity.x;
  velocity->y = v5;
  velocity->z = v6;
}

// File Line: 61
// RVA: 0xB9B20
void __fastcall UFG::BaseCameraComponent::GetLookWorld(UFG::BaseCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  v3 = this->mLookCurr.y;
  v4 = this->mLookCurr.z;
  position->x = this->mLookCurr.x;
  position->y = v3;
  position->z = v4;
  v5 = this->mLookVelocity.y;
  v6 = this->mLookVelocity.z;
  velocity->x = this->mLookVelocity.x;
  velocity->y = v5;
  velocity->z = v6;
}

// File Line: 63
// RVA: 0xBA5B0
void __fastcall UFG::BaseCameraComponent::SetEyeWorld(UFG::BaseCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  UFG::BaseCameraComponent::SetEyeLookUp(
    this,
    0.0,
    position,
    &this->mLookCurr,
    (UFG::qVector3 *)&this->mCamera.mTransformation.v1);
}

// File Line: 64
// RVA: 0xBA6B0
void __fastcall UFG::BaseCameraComponent::SetLookWorld(UFG::BaseCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  UFG::BaseCameraComponent::SetEyeLookUp(
    this,
    0.0,
    &this->mEyeCurr,
    position,
    (UFG::qVector3 *)&this->mCamera.mTransformation.v1);
}

