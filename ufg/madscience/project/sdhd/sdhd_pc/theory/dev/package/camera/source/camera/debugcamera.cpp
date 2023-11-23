// File Line: 28
// RVA: 0x1459270
__int64 dynamic_initializer_for__UFG::DebugCameraComponent::s_DebugCameraComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DebugCameraComponent::s_DebugCameraComponentList__);
}

// File Line: 29
// RVA: 0xB9C40
__int64 __fastcall UFG::DebugCameraComponent::GetTypeSize(UFG::DebugCameraComponent *this)
{
  return 848i64;
}

// File Line: 45
// RVA: 0xB9480
void __fastcall UFG::DebugCameraComponent::DebugCameraComponent(UFG::DebugCameraComponent *this, unsigned int name_uid)
{
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *mPrev; // rax
  UFG::Controller *v4; // rax

  UFG::BaseCameraComponent::BaseCameraComponent(this, name_uid);
  this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mPrev = &this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>;
  this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mNext = &this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DebugCameraComponent::`vftable;
  this->mController = 0i64;
  this->mPreviousCameraComponent = 0i64;
  *(_WORD *)&this->mDebugCameraOn = 256;
  Render::DepthOfField::Focus::Focus(&this->mDofParameters);
  mPrev = UFG::DebugCameraComponent::s_DebugCameraComponentList.mNode.mPrev;
  UFG::DebugCameraComponent::s_DebugCameraComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>;
  this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mNext = (UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *)&UFG::DebugCameraComponent::s_DebugCameraComponentList;
  UFG::DebugCameraComponent::s_DebugCameraComponentList.mNode.mPrev = &this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>;
  UFG::SimComponent::AddType(this, UFG::DebugCameraComponent::_DebugCameraComponentTypeUID, "DebugCameraComponent");
  v4 = UFG::InputSystem::AcquireController(UFG::gInputSystem, 0);
  this->mController = v4;
  if ( !v4 )
    this->mController = UFG::InputSystem::AcquireController(UFG::gInputSystem, -1);
  *(_QWORD *)&this->mDesaturation = 0i64;
  *(_QWORD *)&this->mDutch = 0i64;
  this->mLongitude = 0.0;
  this->mFov = 1.7453293;
  *(_QWORD *)&this->mDofParameters.mFarRange = 1092616192i64;
  *(_QWORD *)&this->mDofParameters.mNearRange = 1092616192i64;
  this->mDofParameters.mInFocusRange = 10.0;
  this->mDofParameters.mFocalDistance = 40.0;
}

// File Line: 87
// RVA: 0xB96B0
void __fastcall UFG::DebugCameraComponent::~DebugCameraComponent(UFG::DebugCameraComponent *this)
{
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *mPrev; // rcx
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *mNext; // rax
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *v4; // rcx
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *v5; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DebugCameraComponent::`vftable;
  UFG::InputSystem::ReleaseController(UFG::gInputSystem, this->mController);
  if ( this == UFG::DebugCameraComponent::s_DebugCameraComponentpCurrentIterator )
    UFG::DebugCameraComponent::s_DebugCameraComponentpCurrentIterator = (UFG::DebugCameraComponent *)&this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mPrev[-47];
  mPrev = this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mPrev;
  mNext = this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mPrev = &this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>;
  this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mNext = &this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>;
  v4 = this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mPrev;
  v5 = this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mPrev = &this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>;
  this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>::mNext = &this->UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent>;
  UFG::BaseCameraComponent::~BaseCameraComponent(this);
}

// File Line: 94
// RVA: 0xBAA20
void __fastcall UFG::DebugCameraComponent::Update(UFG::DebugCameraComponent *this, float delta_sec)
{
  UFG::Controller *v3; // rax
  float mFov; // xmm6_4
  float DisplayAspectRatio; // xmm1_4

  if ( this->mDebugCameraOn )
  {
    v3 = UFG::InputSystem::AcquireController(UFG::gInputSystem, 0);
    this->mController = v3;
    if ( !v3 )
      this->mController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    mFov = this->mFov;
    if ( !Render::GetRenderFeatures()->mForceLetterBox )
      mFov = Render::GetExtraWideAspectCorrectedFOV(mFov);
    DisplayAspectRatio = Render::GetDisplayAspectRatio();
    if ( UFG::gCameraOverrideFOVEnabled )
      mFov = (float)(UFG::gCameraOverrideFOV * 3.1415927) * 0.0055555557;
    UFG::qPerspectiveObliqueMatrix(&this->mCamera.mProjection, mFov, DisplayAspectRatio, 0.25, 4200.0, 0.0, 0.0);
  }
}

