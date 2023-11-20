// File Line: 25
// RVA: 0x14BFFA0
__int64 dynamic_initializer_for__UFG::TurfCameraComponent::s_TurfCameraComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TurfCameraComponent::s_TurfCameraComponentList__);
}

// File Line: 26
// RVA: 0x3C2D50
UFG::ComponentIDDesc *__fastcall UFG::TurfCameraComponent::GetDesc(UFG::TurfCameraComponent *this)
{
  return &UFG::TurfCameraComponent::_TypeIDesc;
}

// File Line: 45
// RVA: 0x3BD850
void __fastcall UFG::TurfCameraComponent::TurfCameraComponent(UFG::TurfCameraComponent *this, unsigned int uid, UFG::SimObject *director)
{
  UFG::SimObject *v3; // rbx
  UFG::TurfCameraComponent *v4; // rdi
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *v5; // rdx
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *v30; // rax
  UFG::SimObjectModifier v31; // [rsp+28h] [rbp-30h]

  v3 = director;
  v4 = this;
  UFG::BaseCameraComponent::BaseCameraComponent((UFG::BaseCameraComponent *)&this->vfptr, uid);
  v5 = (UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TurfCameraComponent::`vftable';
  v4->mCameraMarkerName.mUID = -1;
  *(_QWORD *)&v4->mPOV = 0i64;
  *(_QWORD *)&v4->mPitch = 0i64;
  v4->mTurfRotateParam = 0.0;
  v6 = UFG::qMatrix44::msIdentity.v0.y;
  v7 = UFG::qMatrix44::msIdentity.v0.z;
  v8 = UFG::qMatrix44::msIdentity.v0.w;
  v4->mTurfTransform.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  v4->mTurfTransform.v0.y = v6;
  v4->mTurfTransform.v0.z = v7;
  v4->mTurfTransform.v0.w = v8;
  v9 = UFG::qMatrix44::msIdentity.v1.y;
  v10 = UFG::qMatrix44::msIdentity.v1.z;
  v11 = UFG::qMatrix44::msIdentity.v1.w;
  v4->mTurfTransform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  v4->mTurfTransform.v1.y = v9;
  v4->mTurfTransform.v1.z = v10;
  v4->mTurfTransform.v1.w = v11;
  v12 = UFG::qMatrix44::msIdentity.v2.y;
  v13 = UFG::qMatrix44::msIdentity.v2.z;
  v14 = UFG::qMatrix44::msIdentity.v2.w;
  v4->mTurfTransform.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  v4->mTurfTransform.v2.y = v12;
  v4->mTurfTransform.v2.z = v13;
  v4->mTurfTransform.v2.w = v14;
  v15 = UFG::qMatrix44::msIdentity.v3.y;
  v16 = UFG::qMatrix44::msIdentity.v3.z;
  v17 = UFG::qMatrix44::msIdentity.v3.w;
  v4->mTurfTransform.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  v4->mTurfTransform.v3.y = v15;
  v4->mTurfTransform.v3.z = v16;
  v4->mTurfTransform.v3.w = v17;
  v18 = UFG::qMatrix44::msIdentity.v0.y;
  v19 = UFG::qMatrix44::msIdentity.v0.z;
  v20 = UFG::qMatrix44::msIdentity.v0.w;
  v4->mRacketTransform.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  v4->mRacketTransform.v0.y = v18;
  v4->mRacketTransform.v0.z = v19;
  v4->mRacketTransform.v0.w = v20;
  v21 = UFG::qMatrix44::msIdentity.v1.y;
  v22 = UFG::qMatrix44::msIdentity.v1.z;
  v23 = UFG::qMatrix44::msIdentity.v1.w;
  v4->mRacketTransform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  v4->mRacketTransform.v1.y = v21;
  v4->mRacketTransform.v1.z = v22;
  v4->mRacketTransform.v1.w = v23;
  v24 = UFG::qMatrix44::msIdentity.v2.y;
  v25 = UFG::qMatrix44::msIdentity.v2.z;
  v26 = UFG::qMatrix44::msIdentity.v2.w;
  v4->mRacketTransform.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  v4->mRacketTransform.v2.y = v24;
  v4->mRacketTransform.v2.z = v25;
  v4->mRacketTransform.v2.w = v26;
  v27 = UFG::qMatrix44::msIdentity.v3.y;
  v28 = UFG::qMatrix44::msIdentity.v3.z;
  v29 = UFG::qMatrix44::msIdentity.v3.w;
  v4->mRacketTransform.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  v4->mRacketTransform.v3.y = v27;
  v4->mRacketTransform.v3.z = v28;
  v4->mRacketTransform.v3.w = v29;
  v30 = UFG::TurfCameraComponent::s_TurfCameraComponentList.mNode.mPrev;
  UFG::TurfCameraComponent::s_TurfCameraComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *)&v4->mPrev;
  v5->mPrev = v30;
  v4->mNext = (UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *)&UFG::TurfCameraComponent::s_TurfCameraComponentList;
  UFG::TurfCameraComponent::s_TurfCameraComponentList.mNode.mPrev = (UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::TurfCameraComponent::_TurfCameraComponentTypeUID,
    "TurfCameraComponent");
  UFG::SimObjectModifier::SimObjectModifier(&v31, v3, 1);
  UFG::SimObjectModifier::AttachComponent(&v31, (UFG::SimComponent *)&v4->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v31);
  UFG::SimObjectModifier::~SimObjectModifier(&v31);
  ++UFG::TurfCameraComponent::mInstanceCount;
}

// File Line: 61
// RVA: 0x3BE240
void __fastcall UFG::TurfCameraComponent::~TurfCameraComponent(UFG::TurfCameraComponent *this)
{
  UFG::TurfCameraComponent *v1; // r8
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *v2; // rdx
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *v3; // rcx
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *v4; // rax
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *v5; // rcx
  UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TurfCameraComponent::`vftable';
  --UFG::TurfCameraComponent::mInstanceCount;
  if ( this == UFG::TurfCameraComponent::s_TurfCameraComponentpCurrentIterator )
    UFG::TurfCameraComponent::s_TurfCameraComponentpCurrentIterator = (UFG::TurfCameraComponent *)&this->mPrev[-47];
  v2 = (UFG::qNode<UFG::TurfCameraComponent,UFG::TurfCameraComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BaseCameraComponent::~BaseCameraComponent((UFG::BaseCameraComponent *)&v1->vfptr);
}

// File Line: 110
// RVA: 0x3C8380
void __fastcall UFG::TurfCameraComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax

  v1 = sceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x430ui64, "TurfCameraComponent", 0i64, 1u);
  if ( v3 )
    UFG::TurfCameraComponent::TurfCameraComponent((UFG::TurfCameraComponent *)v3, v1->m_NameUID, v1->m_pSimObject);
}

// File Line: 221
// RVA: 0x3C5DD0
UFG::qMatrix44 *__fastcall UFG::TurfCameraComponent::InterpolateTransform(UFG::TurfCameraComponent *this, UFG::qMatrix44 *result, UFG::qMatrix44 *fromTrans, UFG::qMatrix44 *toTrans, float progress)
{
  UFG::qMatrix44 *v5; // rdi
  UFG::qMatrix44 *v6; // rbx
  float v7; // xmm7_4
  float v8; // xmm9_4
  float v9; // xmm8_4
  UFG::qQuaternion b; // [rsp+30h] [rbp-78h]
  UFG::qQuaternion a; // [rsp+40h] [rbp-68h]
  UFG::qQuaternion resulta; // [rsp+50h] [rbp-58h]

  v5 = result;
  v6 = toTrans;
  v7 = (float)((float)(toTrans->v3.x - fromTrans->v3.x) * progress) + fromTrans->v3.x;
  v8 = (float)((float)(toTrans->v3.z - fromTrans->v3.z) * progress) + fromTrans->v3.z;
  v9 = (float)((float)(toTrans->v3.y - fromTrans->v3.y) * progress) + fromTrans->v3.y;
  UFG::qQuaternion::Set(&a, fromTrans);
  UFG::qQuaternion::Set(&b, v6);
  UFG::qSlerp(&resulta, &a, &b, progress, 0);
  UFG::qQuaternion::GetMatrix(&resulta, v5, &UFG::qVector3::msZero);
  v5->v3.w = 1.0;
  v5->v3.x = v7;
  v5->v3.y = v9;
  v5->v3.z = v8;
  return v5;
}

// File Line: 237
// RVA: 0x3D7D60
void __fastcall UFG::TurfCameraComponent::Update(UFG::TurfCameraComponent *this, float dt)
{
  UFG::TurfCameraComponent *v2; // rdi
  float v3; // xmm8_4
  UFG::qBaseTreeRB *v4; // rax
  UFG::CameraMarker *v5; // rsi
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  __m128 v14; // xmm2
  float v15; // xmm1_4
  UFG::qMatrix44 *v16; // rax
  UFG::qVector4 v17; // xmm3
  UFG::qVector4 v18; // xmm2
  UFG::qVector4 v19; // xmm1
  float v20; // xmm2_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  UFG::qQuaternion v23; // [rsp+40h] [rbp-C0h]
  Render::DepthOfField::Focus v24; // [rsp+50h] [rbp-B0h]
  UFG::qVector3 t; // [rsp+68h] [rbp-98h]
  UFG::qMatrix44 mat; // [rsp+80h] [rbp-80h]
  UFG::qMatrix44 result; // [rsp+C0h] [rbp-40h]
  UFG::qMatrix44 v28; // [rsp+100h] [rbp+0h]

  v2 = this;
  v3 = dt;
  if ( (!UFG::gFlowController.mCurrentState
     || !UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED))
    && v2->mCameraMarkerName.mUID != -1 )
  {
    v4 = UFG::MarkerBase::GetNamed(&v2->mCameraMarkerName);
    if ( v4 )
    {
      v5 = (UFG::CameraMarker *)_RTDynamicCast(
                                  v4,
                                  0,
                                  &UFG::MarkerBase `RTTI Type Descriptor',
                                  &UFG::CameraMarker `RTTI Type Descriptor',
                                  0);
      if ( v5 )
      {
        Render::DepthOfField::Focus::Focus(&v24);
        v24.mFocalDistance = UFG::CameraMarker::GetDofFocalDist(v5);
        v24.mInFocusRange = UFG::CameraMarker::GetDofInFocusRange(v5);
        v24.mNearRange = UFG::CameraMarker::GetDofNearRange(v5);
        v24.mNearBlurRadius = UFG::CameraMarker::GetDofNearBlurRadius(v5);
        v24.mFarRange = UFG::CameraMarker::GetDofFarRange(v5);
        v6 = UFG::CameraMarker::GetDofFarBlurRadius(v5);
        v7 = v24.mInFocusRange;
        v8 = dt;
        v2->mCamera.mDepthOfFieldFocus.mFocalDistance = v24.mFocalDistance;
        v9 = v24.mNearRange;
        v2->mCamera.mDepthOfFieldFocus.mInFocusRange = v7;
        v10 = v24.mNearBlurRadius;
        v2->mCamera.mDepthOfFieldFocus.mNearRange = v9;
        v11 = v24.mFarRange;
        v2->mCamera.mDepthOfFieldFocus.mNearBlurRadius = v10;
        v12 = v2->mTurfRotateParam;
        v2->mCamera.mDepthOfFieldFocus.mFarRange = v11;
        v24.mFarBlurRadius = v6;
        v2->mCamera.mDepthOfFieldFocus.mFarBlurRadius = v6;
        UFG::qApproach(
          &v2->mTurfRotateParam,
          1.0,
          COERCE_FLOAT(COERCE_UNSIGNED_INT(v12 - 1.0) & _xmm) * sTurfCamTransitionSpeed,
          v8);
        UFG::TurfCameraComponent::InterpolateTransform(
          v2,
          &result,
          &v2->mOldTurfTransform,
          &v2->mTurfTransform,
          v2->mTurfRotateParam);
        if ( v2->mPOV )
          v13 = *(float *)&FLOAT_1_0;
        else
          v13 = 0.0;
        UFG::qApproach(
          &v2->mRacketZoomParam,
          v13,
          COERCE_FLOAT(COERCE_UNSIGNED_INT(v2->mRacketZoomParam - v13) & _xmm) * sTurfCamTransitionSpeed,
          v3);
        UFG::TurfCameraComponent::InterpolateTransform(v2, &mat, &result, &v2->mRacketTransform, v2->mRacketZoomParam);
        UFG::qQuaternion::Set(&v23, &mat);
        v14 = (__m128)LODWORD(v23.x);
        v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v23.y * v23.y))
                                + (float)(v23.z * v23.z))
                        + (float)(v23.w * v23.w);
        if ( v14.m128_f32[0] == 0.0 )
          v15 = 0.0;
        else
          v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
        t = *(UFG::qVector3 *)&mat.v3.x;
        v23.x = v23.x * v15;
        v23.y = v23.y * v15;
        v23.z = v23.z * v15;
        v23.w = v23.w * v15;
        v16 = UFG::qQuaternion::GetMatrix(&v23, &v28, &t);
        v17 = v16->v1;
        v18 = v16->v2;
        v19 = v16->v3;
        v2->mCamera.mTransformation.v0 = v16->v0;
        v2->mCamera.mTransformation.v1 = v17;
        v2->mCamera.mTransformation.v2 = v18;
        v2->mCamera.mTransformation.v3 = v19;
        UFG::qInverseAffine(&v2->mCamera.mView, v16);
        if ( v2->mPOV == 1 )
        {
          v20 = (float)(v2->mRacketZoomParam - (float)(sTurfCamMotionBlurTightness * 0.5))
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
          v2->mCamera.mMotionBlur = (float)((float)(cosf((float)(v20 * 6.2831855) - 3.1415927) + 1.0) * 0.5)
                                  * sTurfCamMotionBlurMag;
        }
        v21 = (float)(UFG::CameraMarker::GetFovH(v5) * 3.1415927) * 0.0055555557;
        if ( !Render::GetRenderFeatures()->mForceLetterBox )
          v21 = Render::GetExtraWideAspectCorrectedFOV(v21);
        v22 = Render::GetDisplayAspectRatio();
        UFG::Camera::SetViewProjection(
          &v2->mCamera,
          v21,
          v22,
          UFG::gCameraDefaultNear,
          UFG::gCameraDefaultFar,
          0.0,
          0.0,
          1);
      }
    }
  }
}

