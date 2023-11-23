// File Line: 25
// RVA: 0x14BFFA0
__int64 dynamic_initializer_for__UFG::TurfCameraComponent::s_TurfCameraComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TurfCameraComponent::s_TurfCameraComponentList__);
}

// File Line: 26
// RVA: 0x3C2D50
UFG::ComponentIDDesc *__fastcall UFG::TurfCameraComponent::GetDesc(UFG::TurfCameraComponent *this)
{
  return &UFG::TurfCameraComponent::_TypeIDesc;
}

// File Line: 45
// RVA: 0x3BD850
void __fastcall UFG::TurfCameraComponent::TurfCameraComponent(
        UFG::TurfCameraComponent *this,
        unsigned int uid,
        UFG::SimObject *director)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *mPrev; // rax
  UFG::SimObjectModifier v30; // [rsp+28h] [rbp-30h] BYREF

  UFG::BaseCameraComponent::BaseCameraComponent(this, uid);
  this->UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent>::mPrev = &this->UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent>;
  this->UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent>::mNext = &this->UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TurfCameraComponent::`vftable;
  this->mCameraMarkerName.mUID = -1;
  *(_QWORD *)&this->mPOV = 0i64;
  *(_QWORD *)&this->mPitch = 0i64;
  this->mTurfRotateParam = 0.0;
  y = UFG::qMatrix44::msIdentity.v0.y;
  z = UFG::qMatrix44::msIdentity.v0.z;
  w = UFG::qMatrix44::msIdentity.v0.w;
  this->mTurfTransform.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->mTurfTransform.v0.y = y;
  this->mTurfTransform.v0.z = z;
  this->mTurfTransform.v0.w = w;
  v8 = UFG::qMatrix44::msIdentity.v1.y;
  v9 = UFG::qMatrix44::msIdentity.v1.z;
  v10 = UFG::qMatrix44::msIdentity.v1.w;
  this->mTurfTransform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->mTurfTransform.v1.y = v8;
  this->mTurfTransform.v1.z = v9;
  this->mTurfTransform.v1.w = v10;
  v11 = UFG::qMatrix44::msIdentity.v2.y;
  v12 = UFG::qMatrix44::msIdentity.v2.z;
  v13 = UFG::qMatrix44::msIdentity.v2.w;
  this->mTurfTransform.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  this->mTurfTransform.v2.y = v11;
  this->mTurfTransform.v2.z = v12;
  this->mTurfTransform.v2.w = v13;
  v14 = UFG::qMatrix44::msIdentity.v3.y;
  v15 = UFG::qMatrix44::msIdentity.v3.z;
  v16 = UFG::qMatrix44::msIdentity.v3.w;
  this->mTurfTransform.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->mTurfTransform.v3.y = v14;
  this->mTurfTransform.v3.z = v15;
  this->mTurfTransform.v3.w = v16;
  v17 = UFG::qMatrix44::msIdentity.v0.y;
  v18 = UFG::qMatrix44::msIdentity.v0.z;
  v19 = UFG::qMatrix44::msIdentity.v0.w;
  this->mRacketTransform.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->mRacketTransform.v0.y = v17;
  this->mRacketTransform.v0.z = v18;
  this->mRacketTransform.v0.w = v19;
  v20 = UFG::qMatrix44::msIdentity.v1.y;
  v21 = UFG::qMatrix44::msIdentity.v1.z;
  v22 = UFG::qMatrix44::msIdentity.v1.w;
  this->mRacketTransform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->mRacketTransform.v1.y = v20;
  this->mRacketTransform.v1.z = v21;
  this->mRacketTransform.v1.w = v22;
  v23 = UFG::qMatrix44::msIdentity.v2.y;
  v24 = UFG::qMatrix44::msIdentity.v2.z;
  v25 = UFG::qMatrix44::msIdentity.v2.w;
  this->mRacketTransform.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  this->mRacketTransform.v2.y = v23;
  this->mRacketTransform.v2.z = v24;
  this->mRacketTransform.v2.w = v25;
  v26 = UFG::qMatrix44::msIdentity.v3.y;
  v27 = UFG::qMatrix44::msIdentity.v3.z;
  v28 = UFG::qMatrix44::msIdentity.v3.w;
  this->mRacketTransform.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->mRacketTransform.v3.y = v26;
  this->mRacketTransform.v3.z = v27;
  this->mRacketTransform.v3.w = v28;
  mPrev = UFG::TurfCameraComponent::s_TurfCameraComponentList.mNode.mPrev;
  UFG::TurfCameraComponent::s_TurfCameraComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent>;
  this->UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent>::mNext = (UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *)&UFG::TurfCameraComponent::s_TurfCameraComponentList;
  UFG::TurfCameraComponent::s_TurfCameraComponentList.mNode.mPrev = &this->UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent>;
  UFG::SimComponent::AddType(this, UFG::TurfCameraComponent::_TurfCameraComponentTypeUID, "TurfCameraComponent");
  UFG::SimObjectModifier::SimObjectModifier(&v30, director, 1);
  UFG::SimObjectModifier::AttachComponent(&v30, this, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v30);
  UFG::SimObjectModifier::~SimObjectModifier(&v30);
  ++UFG::TurfCameraComponent::mInstanceCount;
}

// File Line: 61
// RVA: 0x3BE240
void __fastcall UFG::TurfCameraComponent::~TurfCameraComponent(UFG::TurfCameraComponent *this)
{
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *v2; // rdx
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *mPrev; // rcx
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *mNext; // rax
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *v5; // rcx
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TurfCameraComponent::`vftable;
  --UFG::TurfCameraComponent::mInstanceCount;
  if ( this == UFG::TurfCameraComponent::s_TurfCameraComponentpCurrentIterator )
    UFG::TurfCameraComponent::s_TurfCameraComponentpCurrentIterator = (UFG::TurfCameraComponent *)&this->UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent>::mPrev[-47];
  v2 = &this->UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent>;
  mPrev = this->UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BaseCameraComponent::~BaseCameraComponent(this);
}

// File Line: 110
// RVA: 0x3C8380
void __fastcall UFG::TurfCameraComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x430ui64, "TurfCameraComponent", 0i64, 1u);
  if ( v3 )
    UFG::TurfCameraComponent::TurfCameraComponent(
      (UFG::TurfCameraComponent *)v3,
      sceneObj->m_NameUID,
      sceneObj->m_pSimObject);
}

// File Line: 221
// RVA: 0x3C5DD0
UFG::qMatrix44 *__fastcall UFG::TurfCameraComponent::InterpolateTransform(
        UFG::TurfCameraComponent *this,
        UFG::qMatrix44 *result,
        UFG::qMatrix44 *fromTrans,
        UFG::qMatrix44 *toTrans,
        float progress)
{
  float v7; // xmm7_4
  float v8; // xmm9_4
  float v9; // xmm8_4
  UFG::qQuaternion b; // [rsp+30h] [rbp-78h] BYREF
  UFG::qQuaternion a; // [rsp+40h] [rbp-68h] BYREF
  UFG::qQuaternion resulta; // [rsp+50h] [rbp-58h] BYREF

  v7 = (float)((float)(toTrans->v3.x - fromTrans->v3.x) * progress) + fromTrans->v3.x;
  v8 = (float)((float)(toTrans->v3.z - fromTrans->v3.z) * progress) + fromTrans->v3.z;
  v9 = (float)((float)(toTrans->v3.y - fromTrans->v3.y) * progress) + fromTrans->v3.y;
  UFG::qQuaternion::Set(&a, fromTrans);
  UFG::qQuaternion::Set(&b, toTrans);
  UFG::qSlerp(&resulta, &a, &b, progress, qAngularPath_Shortest);
  UFG::qQuaternion::GetMatrix(&resulta, result, &UFG::qVector3::msZero);
  result->v3.w = 1.0;
  result->v3.x = v7;
  result->v3.y = v9;
  result->v3.z = v8;
  return result;
}

// File Line: 237
// RVA: 0x3D7D60
void __fastcall UFG::TurfCameraComponent::Update(UFG::TurfCameraComponent *this, float dt)
{
  UFG::qBaseTreeRB *Named; // rax
  UFG::CameraMarker *v5; // rsi
  float DofFarBlurRadius; // xmm0_4
  float mInFocusRange; // xmm2_4
  float mNearRange; // xmm1_4
  float mNearBlurRadius; // xmm2_4
  float mFarRange; // xmm1_4
  float mTurfRotateParam; // xmm2_4
  float v13; // xmm1_4
  __m128 x_low; // xmm2
  float v15; // xmm1_4
  UFG::qMatrix44 *Matrix; // rax
  UFG::qVector4 v17; // xmm3
  UFG::qVector4 v18; // xmm2
  UFG::qVector4 v19; // xmm1
  float v20; // xmm2_4
  float ExtraWideAspectCorrectedFOV; // xmm6_4
  float DisplayAspectRatio; // xmm0_4
  UFG::qQuaternion v23; // [rsp+40h] [rbp-C0h] BYREF
  Render::DepthOfField::Focus v24; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qVector3 t; // [rsp+68h] [rbp-98h] BYREF
  UFG::qMatrix44 mat; // [rsp+80h] [rbp-80h] BYREF
  UFG::qMatrix44 result; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qMatrix44 v28; // [rsp+100h] [rbp+0h] BYREF

  if ( (!UFG::gFlowController.mCurrentState
     || !UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED))
    && this->mCameraMarkerName.mUID != -1 )
  {
    Named = UFG::MarkerBase::GetNamed(&this->mCameraMarkerName);
    if ( Named )
    {
      v5 = (UFG::CameraMarker *)_RTDynamicCast(
                                  Named,
                                  0,
                                  &UFG::MarkerBase `RTTI Type Descriptor,
                                  &UFG::CameraMarker `RTTI Type Descriptor,
                                  0);
      if ( v5 )
      {
        Render::DepthOfField::Focus::Focus(&v24);
        v24.mFocalDistance = UFG::CameraMarker::GetDofFocalDist(v5);
        v24.mInFocusRange = UFG::CameraMarker::GetDofInFocusRange(v5);
        v24.mNearRange = UFG::CameraMarker::GetDofNearRange(v5);
        v24.mNearBlurRadius = UFG::CameraMarker::GetDofNearBlurRadius(v5);
        v24.mFarRange = UFG::CameraMarker::GetDofFarRange(v5);
        DofFarBlurRadius = UFG::CameraMarker::GetDofFarBlurRadius(v5);
        mInFocusRange = v24.mInFocusRange;
        this->mCamera.mDepthOfFieldFocus.mFocalDistance = v24.mFocalDistance;
        mNearRange = v24.mNearRange;
        this->mCamera.mDepthOfFieldFocus.mInFocusRange = mInFocusRange;
        mNearBlurRadius = v24.mNearBlurRadius;
        this->mCamera.mDepthOfFieldFocus.mNearRange = mNearRange;
        mFarRange = v24.mFarRange;
        this->mCamera.mDepthOfFieldFocus.mNearBlurRadius = mNearBlurRadius;
        mTurfRotateParam = this->mTurfRotateParam;
        this->mCamera.mDepthOfFieldFocus.mFarRange = mFarRange;
        v24.mFarBlurRadius = DofFarBlurRadius;
        this->mCamera.mDepthOfFieldFocus.mFarBlurRadius = DofFarBlurRadius;
        UFG::qApproach(
          &this->mTurfRotateParam,
          1.0,
          COERCE_FLOAT(COERCE_UNSIGNED_INT(mTurfRotateParam - 1.0) & _xmm) * sTurfCamTransitionSpeed,
          dt);
        UFG::TurfCameraComponent::InterpolateTransform(
          this,
          &result,
          &this->mOldTurfTransform,
          &this->mTurfTransform,
          this->mTurfRotateParam);
        if ( this->mPOV )
          v13 = *(float *)&FLOAT_1_0;
        else
          v13 = 0.0;
        UFG::qApproach(
          &this->mRacketZoomParam,
          v13,
          COERCE_FLOAT(COERCE_UNSIGNED_INT(this->mRacketZoomParam - v13) & _xmm) * sTurfCamTransitionSpeed,
          dt);
        UFG::TurfCameraComponent::InterpolateTransform(
          this,
          &mat,
          &result,
          &this->mRacketTransform,
          this->mRacketZoomParam);
        UFG::qQuaternion::Set(&v23, &mat);
        x_low = (__m128)LODWORD(v23.x);
        x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v23.y * v23.y))
                                  + (float)(v23.z * v23.z))
                          + (float)(v23.w * v23.w);
        if ( x_low.m128_f32[0] == 0.0 )
          v15 = 0.0;
        else
          v15 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
        t.x = mat.v3.x;
        v23.x = v23.x * v15;
        v23.y = v23.y * v15;
        v23.z = v23.z * v15;
        v23.w = v23.w * v15;
        *(_QWORD *)&t.y = *(_QWORD *)&mat.v3.y;
        Matrix = UFG::qQuaternion::GetMatrix(&v23, &v28, &t);
        v17 = Matrix->v1;
        v18 = Matrix->v2;
        v19 = Matrix->v3;
        this->mCamera.mTransformation.v0 = Matrix->v0;
        this->mCamera.mTransformation.v1 = v17;
        this->mCamera.mTransformation.v2 = v18;
        this->mCamera.mTransformation.v3 = v19;
        UFG::qInverseAffine(&this->mCamera.mView, Matrix);
        if ( this->mPOV == POV_RacketSelected )
        {
          v20 = (float)(this->mRacketZoomParam - (float)(sTurfCamMotionBlurTightness * 0.5))
              / (float)((float)(1.0 - (float)(sTurfCamMotionBlurTightness * 0.5))
                      - (float)(sTurfCamMotionBlurTightness * 0.5));
          if ( v20 <= 0.0 )
          {
            v20 = 0.0;
          }
          else if ( v20 >= 1.0 )
          {
            v20 = *(float *)&FLOAT_1_0;
          }
          this->mCamera.mMotionBlur = (float)((float)(cosf((float)(v20 * 6.2831855) - 3.1415927) + 1.0) * 0.5)
                                    * sTurfCamMotionBlurMag;
        }
        ExtraWideAspectCorrectedFOV = (float)(UFG::CameraMarker::GetFovH(v5) * 3.1415927) * 0.0055555557;
        if ( !Render::GetRenderFeatures()->mForceLetterBox )
          ExtraWideAspectCorrectedFOV = Render::GetExtraWideAspectCorrectedFOV(ExtraWideAspectCorrectedFOV);
        DisplayAspectRatio = Render::GetDisplayAspectRatio();
        UFG::Camera::SetViewProjection(
          &this->mCamera,
          ExtraWideAspectCorrectedFOV,
          DisplayAspectRatio,
          UFG::gCameraDefaultNear,
          UFG::gCameraDefaultFar,
          0.0,
          0.0,
          1);
      }
    }
  }
}

