// File Line: 28
// RVA: 0x1459270
__int64 dynamic_initializer_for__UFG::DebugCameraComponent::s_DebugCameraComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::DebugCameraComponent::s_DebugCameraComponentList__);
}

// File Line: 29
// RVA: 0xB9C40
signed __int64 __fastcall UFG::DebugCameraComponent::GetTypeSize(UFG::DebugCameraComponent *this)
{
  return 848i64;
}

// File Line: 45
// RVA: 0xB9480
void __fastcall UFG::DebugCameraComponent::DebugCameraComponent(UFG::DebugCameraComponent *this, unsigned int name_uid)
{
  UFG::DebugCameraComponent *v2; // rdi
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *v3; // rbx
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *v4; // rax
  UFG::Controller *v5; // rax

  v2 = this;
  UFG::BaseCameraComponent::BaseCameraComponent((UFG::BaseCameraComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DebugCameraComponent::`vftable';
  v2->mController = 0i64;
  v2->mPreviousCameraComponent = 0i64;
  *(_WORD *)&v2->mDebugCameraOn = 256;
  Render::DepthOfField::Focus::Focus(&v2->mDofParameters);
  v4 = UFG::DebugCameraComponent::s_DebugCameraComponentList.mNode.mPrev;
  UFG::DebugCameraComponent::s_DebugCameraComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *)&UFG::DebugCameraComponent::s_DebugCameraComponentList;
  UFG::DebugCameraComponent::s_DebugCameraComponentList.mNode.mPrev = (UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::DebugCameraComponent::_DebugCameraComponentTypeUID,
    "DebugCameraComponent");
  v5 = UFG::InputSystem::AcquireController(UFG::gInputSystem, 0);
  v2->mController = v5;
  if ( !v5 )
    v2->mController = UFG::InputSystem::AcquireController(UFG::gInputSystem, -1);
  *(_QWORD *)&v2->mDesaturation = 0i64;
  *(_QWORD *)&v2->mDutch = 0i64;
  v2->mLongitude = 0.0;
  v2->mFov = 1.7453293;
  *(_QWORD *)&v2->mDofParameters.mFarRange = 1092616192i64;
  *(_QWORD *)&v2->mDofParameters.mNearRange = 1092616192i64;
  v2->mDofParameters.mInFocusRange = 10.0;
  v2->mDofParameters.mFocalDistance = 40.0;
}

// File Line: 87
// RVA: 0xB96B0
void __fastcall UFG::DebugCameraComponent::~DebugCameraComponent(UFG::DebugCameraComponent *this)
{
  UFG::DebugCameraComponent *v1; // rbx
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *v2; // rdx
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *v3; // rcx
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *v4; // rax
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *v5; // rcx
  UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DebugCameraComponent::`vftable';
  UFG::InputSystem::ReleaseController(UFG::gInputSystem, this->mController);
  if ( v1 == UFG::DebugCameraComponent::s_DebugCameraComponentpCurrentIterator )
    UFG::DebugCameraComponent::s_DebugCameraComponentpCurrentIterator = (UFG::DebugCameraComponent *)&v1->mPrev[-47];
  v2 = (UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v1->mNext = (UFG::qNode<UFG::DebugCameraComponent,UFG::DebugCameraComponent> *)&v1->mPrev;
  UFG::BaseCameraComponent::~BaseCameraComponent((UFG::BaseCameraComponent *)&v1->vfptr);
}

// File Line: 94
// RVA: 0xBAA20
void __fastcall UFG::DebugCameraComponent::Update(UFG::DebugCameraComponent *this, float delta_sec)
{
  UFG::DebugCameraComponent *v2; // rbx
  UFG::Controller *v3; // rax
  float v4; // xmm6_4
  float v5; // xmm1_4

  v2 = this;
  if ( this->mDebugCameraOn )
  {
    v3 = UFG::InputSystem::AcquireController(UFG::gInputSystem, 0);
    v2->mController = v3;
    if ( !v3 )
      v2->mController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    v4 = v2->mFov;
    if ( !Render::GetRenderFeatures()->mForceLetterBox )
      v4 = Render::GetExtraWideAspectCorrectedFOV(v4);
    v5 = Render::GetDisplayAspectRatio();
    if ( UFG::gCameraOverrideFOVEnabled )
      v4 = (float)(UFG::gCameraOverrideFOV * 3.1415927) * 0.0055555557;
    UFG::qPerspectiveObliqueMatrix(&v2->mCamera.mProjection, v4, v5, 0.25, 4200.0, 0.0, 0.0);
  }
}

