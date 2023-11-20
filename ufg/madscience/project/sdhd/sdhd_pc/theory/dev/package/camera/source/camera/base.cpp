// File Line: 14
// RVA: 0xB9A50
UFG::ComponentIDDesc *__fastcall UFG::BaseCameraComponent::GetDesc(UFG::BaseCameraComponent *this)
{
  return &UFG::BaseCameraComponent::_TypeIDesc;
}

// File Line: 15
// RVA: 0x1459250
__int64 dynamic_initializer_for__UFG::BaseCameraComponent::s_BaseCameraComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::BaseCameraComponent::s_BaseCameraComponentList__);
}

// File Line: 20
// RVA: 0xB9190
void __fastcall UFG::BaseCameraComponent::BaseCameraComponent(UFG::BaseCameraComponent *this, unsigned int name_uid)
{
  UFG::BaseCameraComponent *v2; // rdi
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v3; // rbx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm2_4

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BaseCameraComponent::`vftable;
  UFG::Camera::Camera(&v2->mCamera);
  v4 = UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mPrev;
  UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)&UFG::BaseCameraComponent::s_BaseCameraComponentList;
  UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mPrev = (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::BaseCameraComponent::_BaseCameraComponentTypeUID,
    "BaseCameraComponent");
  *(_WORD *)&v2->mActive = 0;
  v2->mControllersEnabled = 1;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  v2->mEyeCurr.x = UFG::qVector3::msZero.x;
  v2->mEyeCurr.y = v5;
  v2->mEyeCurr.z = v6;
  *(_QWORD *)&v2->mLookCurr.x = 1065353216i64;
  *(_QWORD *)&v2->mLookCurr.z = 0i64;
  v2->mUpCurr.y = 0.0;
  v2->mUpCurr.z = 1.0;
  UFG::BaseCameraComponent::Reset(v2);
}

// File Line: 38
// RVA: 0xB9630
void __fastcall UFG::BaseCameraComponent::~BaseCameraComponent(UFG::BaseCameraComponent *this)
{
  UFG::BaseCameraComponent *v1; // r8
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v2; // rdx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v3; // rcx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v4; // rax
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v5; // rcx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BaseCameraComponent::`vftable;
  if ( this == UFG::BaseCameraComponent::s_BaseCameraComponentpCurrentIterator )
    UFG::BaseCameraComponent::s_BaseCameraComponentpCurrentIterator = (UFG::BaseCameraComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)&this->mPrev;
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
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 44
// RVA: 0xB9FA0
void __fastcall UFG::BaseCameraComponent::Reset(UFG::BaseCameraComponent *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  UFG::qVector4 v10; // xmm3
  float v11; // xmm0_4

  v1 = UFG::qVector3::msZero.y;
  v2 = UFG::qVector3::msZero.z;
  this->mLookVelocity.x = UFG::qVector3::msZero.x;
  this->mLookVelocity.y = v1;
  this->mLookVelocity.z = v2;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->mEyeVelocity.x = UFG::qVector3::msZero.x;
  this->mEyeVelocity.y = v3;
  this->mEyeVelocity.z = v4;
  this->mResetEyeLook = 1;
  v5 = this->mCamera.mView.v1;
  v6 = this->mCamera.mView.v2;
  v7 = this->mCamera.mView.v3;
  this->mCamera.mPreviousView.v0 = this->mCamera.mView.v0;
  this->mCamera.mPreviousView.v1 = v5;
  this->mCamera.mPreviousView.v2 = v6;
  this->mCamera.mPreviousView.v3 = v7;
  v8 = this->mCamera.mTransformation.v2;
  v9 = this->mCamera.mTransformation.v3;
  v10 = this->mCamera.mTransformation.v1;
  this->mCamera.mPreviousTransformation.v0 = this->mCamera.mTransformation.v0;
  this->mCamera.mPreviousTransformation.v1 = v10;
  this->mCamera.mPreviousTransformation.v2 = v8;
  this->mCamera.mPreviousTransformation.v3 = v9;
  v8.x = UFG::qVector3::msZero.z;
  v11 = UFG::qVector3::msZero.x;
  this->mCamera.mVelocity.y = UFG::qVector3::msZero.y;
  this->mCamera.mVelocity.z = v8.x;
  this->mCamera.mVelocity.x = v11;
}

// File Line: 53
// RVA: 0xBA930
void __fastcall UFG::BaseCameraComponent::Update(UFG::BaseCameraComponent *this, float delta_seconds)
{
  UFG::Camera::Update(&this->mCamera, delta_seconds);
}

// File Line: 59
// RVA: 0xBA720
void __fastcall UFG::BaseCameraComponent::TransitionFrom(UFG::BaseCameraComponent *this, UFG::BaseCameraComponent *camera, bool withVelocity)
{
  UFG::BaseCameraComponent *v3; // rdi
  bool v4; // si
  UFG::BaseCameraComponent *v5; // rbx
  float v6; // eax
  UFG::qVector3 *v7; // rcx
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  UFG::qVector3 *v13; // rax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  __int64 *v18; // r8
  __int64 *v19; // r8
  __int64 v20; // [rsp+20h] [rbp-60h]
  int v21; // [rsp+28h] [rbp-58h]
  __int64 v22; // [rsp+30h] [rbp-50h]
  int v23; // [rsp+38h] [rbp-48h]
  __int64 v24; // [rsp+3Ch] [rbp-44h]
  int v25; // [rsp+44h] [rbp-3Ch]
  __int64 v26; // [rsp+48h] [rbp-38h]
  int v27; // [rsp+50h] [rbp-30h]
  char v28; // [rsp+58h] [rbp-28h]
  char v29; // [rsp+68h] [rbp-18h]
  int v30; // [rsp+A0h] [rbp+20h]
  int v31; // [rsp+B0h] [rbp+30h]

  v3 = camera;
  v4 = withVelocity;
  v5 = this;
  ((void (__fastcall *)(UFG::BaseCameraComponent *, int *, int *))camera->vfptr[23].__vecDelDtor)(camera, &v30, &v31);
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, __int64 *))v3->vfptr[25].__vecDelDtor)(v3, &v28, &v20);
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, __int64 *))v3->vfptr[26].__vecDelDtor)(v3, &v29, &v26);
  v6 = v3->mEyeCurr.x;
  v7 = &UFG::qVector3::msZero;
  v8 = v3->mEyeCurr.z;
  v5->mEyeCurr.y = v3->mEyeCurr.y;
  v5->mEyeCurr.z = v8;
  v5->mEyeCurr.x = v6;
  v9 = v3->mLookCurr.y;
  v10 = v3->mLookCurr.z;
  v5->mLookCurr.x = v3->mLookCurr.x;
  v5->mLookCurr.y = v9;
  v5->mLookCurr.z = v10;
  v11 = v3->mUpCurr.y;
  v12 = v3->mUpCurr.z;
  v5->mUpCurr.x = v3->mUpCurr.x;
  v13 = &v3->mEyeVelocity;
  v5->mUpCurr.y = v11;
  v5->mUpCurr.z = v12;
  if ( !v4 )
    v13 = &UFG::qVector3::msZero;
  v14 = v13->y;
  v15 = v13->z;
  v5->mEyeVelocity.x = v13->x;
  v5->mEyeVelocity.y = v14;
  v5->mEyeVelocity.z = v15;
  if ( v4 )
    v7 = &v3->mLookVelocity;
  v16 = v7->y;
  v17 = v7->z;
  v5->mLookVelocity.x = v7->x;
  v5->mLookVelocity.y = v16;
  v5->mLookVelocity.z = v17;
  ((void (__fastcall *)(UFG::BaseCameraComponent *))v5->vfptr[24].__vecDelDtor)(v5);
  if ( v4 )
  {
    v18 = &v22;
    v22 = v20;
    v23 = v21;
  }
  else
  {
    v24 = 0i64;
    v25 = 0;
    v18 = &v24;
  }
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, __int64 *))v5->vfptr[27].__vecDelDtor)(v5, &v28, v18);
  if ( v4 )
  {
    v19 = &v24;
    v24 = v26;
    v25 = v27;
  }
  else
  {
    v22 = 0i64;
    v23 = 0;
    v19 = &v22;
  }
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, __int64 *))v5->vfptr[28].__vecDelDtor)(v5, &v29, v19);
}

// File Line: 91
// RVA: 0xBA2E0
void __fastcall UFG::BaseCameraComponent::SetEyeLookUp(UFG::BaseCameraComponent *this, float dt, UFG::qVector3 *eye, UFG::qVector3 *loook, UFG::qVector3 *up)
{
  float v5; // xmm3_4
  __int128 v6; // xmm4
  float v7; // xmm5_4
  UFG::BaseCameraComponent *v8; // rdi
  float v9; // xmm10_4
  float v10; // xmm13_4
  float v11; // xmm11_4
  float v12; // xmm12_4
  __m128 v13; // xmm2
  float v14; // xmm7_4
  float v15; // xmm8_4
  __m128 v16; // xmm6
  float v17; // xmm1_4
  float v18; // xmm11_4
  float v19; // xmm12_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  UFG::qMatrix44 *v24; // rcx
  float v25; // eax
  float v26; // xmm1_4
  UFG::qVector3 target; // [rsp+20h] [rbp-98h]

  v5 = loook->x;
  v6 = LODWORD(loook->y);
  v7 = loook->z;
  v8 = this;
  target.x = v5;
  LODWORD(target.y) = v6;
  target.z = v7;
  v9 = eye->x;
  v10 = dt;
  if ( eye->x == v5 && *(float *)&v6 == eye->y && v7 == eye->z )
  {
    v5 = v5 + 0.0099999998;
    target.x = v5;
  }
  v11 = eye->y;
  v12 = eye->z;
  v13 = (__m128)v6;
  v13.m128_f32[0] = *(float *)&v6 - v11;
  v14 = v5 - v9;
  v15 = v7 - v12;
  v16 = v13;
  v16.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v14 * v14)) + (float)(v15 * v15);
  v17 = 0.0;
  if ( v16.m128_f32[0] != 0.0 )
    v17 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                      (float)((float)((float)(v13.m128_f32[0] * v17) * up->y) + (float)((float)(v14 * v17) * up->x))
                    + (float)((float)(v15 * v17) * up->z)) & _xmm) > 0.99984771 )
  {
    v5 = v9 + 1.0;
    *(float *)&v6 = v11 + 1.0;
    v7 = v12 + 1.0;
    target.x = v9 + 1.0;
    target.y = v11 + 1.0;
    target.z = v12 + 1.0;
  }
  if ( v10 > 0.001 )
  {
    if ( this->mResetEyeLook )
    {
      this->mResetEyeLook = 0;
    }
    else
    {
      v18 = (float)(v11 - this->mEyeCurr.y) * (float)(1.0 / v10);
      v19 = (float)(v12 - this->mEyeCurr.z) * (float)(1.0 / v10);
      this->mEyeVelocity.x = (float)(v9 - this->mEyeCurr.x) * (float)(1.0 / v10);
      this->mEyeVelocity.y = v18;
      this->mEyeVelocity.z = v19;
      v20 = (float)(*(float *)&v6 - this->mLookCurr.y) * (float)(1.0 / v10);
      v21 = (float)(v7 - this->mLookCurr.z) * (float)(1.0 / v10);
      this->mLookVelocity.x = (float)(v5 - this->mLookCurr.x) * (float)(1.0 / v10);
      this->mLookVelocity.y = v20;
      this->mLookVelocity.z = v21;
    }
  }
  v22 = eye->y;
  v23 = eye->z;
  this->mEyeCurr.x = eye->x;
  v24 = &this->mCamera.mView;
  v24[8].v2.z = v22;
  v24[8].v2.w = v23;
  v24[8].v3.x = v5;
  LODWORD(v24[8].v3.y) = v6;
  v24[8].v3.z = v7;
  v25 = up->x;
  v26 = up->z;
  v24[9].v0.x = up->y;
  v24[8].v3.w = v25;
  v24[9].v0.y = v26;
  UFG::qLookAtMatrix(v24, eye, &target, up);
  UFG::qInverseAffine(&v8->mCamera.mTransformation, &v8->mCamera.mView);
}

