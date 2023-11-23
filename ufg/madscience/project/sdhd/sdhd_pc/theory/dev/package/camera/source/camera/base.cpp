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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BaseCameraComponent::s_BaseCameraComponentList__);
}

// File Line: 20
// RVA: 0xB9190
void __fastcall UFG::BaseCameraComponent::BaseCameraComponent(UFG::BaseCameraComponent *this, unsigned int name_uid)
{
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *mPrev; // rax
  float y; // xmm1_4
  float z; // xmm2_4

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent>;
  this->mNext = &this->UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BaseCameraComponent::`vftable;
  UFG::Camera::Camera(&this->mCamera);
  mPrev = UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mPrev;
  UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)&UFG::BaseCameraComponent::s_BaseCameraComponentList;
  UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mPrev = &this->UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent>;
  UFG::SimComponent::AddType(this, UFG::BaseCameraComponent::_BaseCameraComponentTypeUID, "BaseCameraComponent");
  *(_WORD *)&this->mActive = 0;
  this->mControllersEnabled = 1;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mEyeCurr.x = UFG::qVector3::msZero.x;
  this->mEyeCurr.y = y;
  this->mEyeCurr.z = z;
  *(_QWORD *)&this->mLookCurr.x = 1065353216i64;
  *(_QWORD *)&this->mLookCurr.z = 0i64;
  this->mUpCurr.y = 0.0;
  this->mUpCurr.z = 1.0;
  UFG::BaseCameraComponent::Reset(this);
}

// File Line: 38
// RVA: 0xB9630
void __fastcall UFG::BaseCameraComponent::~BaseCameraComponent(UFG::BaseCameraComponent *this)
{
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v2; // rdx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *mPrev; // rcx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *mNext; // rax
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v5; // rcx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BaseCameraComponent::`vftable;
  if ( this == UFG::BaseCameraComponent::s_BaseCameraComponentpCurrentIterator )
    UFG::BaseCameraComponent::s_BaseCameraComponentpCurrentIterator = (UFG::BaseCameraComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent>;
  mPrev = this->mPrev;
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
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 44
// RVA: 0xB9FA0
void __fastcall UFG::BaseCameraComponent::Reset(UFG::BaseCameraComponent *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  UFG::qVector4 v10; // xmm3
  float x; // xmm0_4

  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mLookVelocity.x = UFG::qVector3::msZero.x;
  this->mLookVelocity.y = y;
  this->mLookVelocity.z = z;
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
  x = UFG::qVector3::msZero.x;
  this->mCamera.mVelocity.y = UFG::qVector3::msZero.y;
  this->mCamera.mVelocity.z = v8.x;
  this->mCamera.mVelocity.x = x;
}

// File Line: 53
// RVA: 0xBA930
void __fastcall UFG::BaseCameraComponent::Update(UFG::BaseCameraComponent *this, float delta_seconds)
{
  UFG::Camera::Update(&this->mCamera, delta_seconds);
}

// File Line: 59
// RVA: 0xBA720
void __fastcall UFG::BaseCameraComponent::TransitionFrom(
        UFG::BaseCameraComponent *this,
        UFG::BaseCameraComponent *camera,
        bool withVelocity)
{
  float x; // eax
  UFG::qVector3 *p_mLookVelocity; // rcx
  float z; // xmm1_4
  float y; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  UFG::qVector3 *p_mEyeVelocity; // rax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  __int64 *v18; // r8
  __int64 *v19; // r8
  __int64 v20; // [rsp+20h] [rbp-60h] BYREF
  int v21; // [rsp+28h] [rbp-58h]
  __int64 v22; // [rsp+30h] [rbp-50h] BYREF
  int v23; // [rsp+38h] [rbp-48h]
  __int64 v24; // [rsp+3Ch] [rbp-44h] BYREF
  int v25; // [rsp+44h] [rbp-3Ch]
  __int64 v26; // [rsp+48h] [rbp-38h] BYREF
  int v27; // [rsp+50h] [rbp-30h]
  char v28[16]; // [rsp+58h] [rbp-28h] BYREF
  char v29[24]; // [rsp+68h] [rbp-18h] BYREF
  int v30; // [rsp+A0h] [rbp+20h] BYREF
  int v31; // [rsp+B0h] [rbp+30h] BYREF

  ((void (__fastcall *)(UFG::BaseCameraComponent *, int *, int *))camera->vfptr[23].__vecDelDtor)(camera, &v30, &v31);
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, __int64 *))camera->vfptr[25].__vecDelDtor)(
    camera,
    v28,
    &v20);
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, __int64 *))camera->vfptr[26].__vecDelDtor)(
    camera,
    v29,
    &v26);
  x = camera->mEyeCurr.x;
  p_mLookVelocity = &UFG::qVector3::msZero;
  z = camera->mEyeCurr.z;
  this->mEyeCurr.y = camera->mEyeCurr.y;
  this->mEyeCurr.z = z;
  this->mEyeCurr.x = x;
  y = camera->mLookCurr.y;
  v10 = camera->mLookCurr.z;
  this->mLookCurr.x = camera->mLookCurr.x;
  this->mLookCurr.y = y;
  this->mLookCurr.z = v10;
  v11 = camera->mUpCurr.y;
  v12 = camera->mUpCurr.z;
  this->mUpCurr.x = camera->mUpCurr.x;
  p_mEyeVelocity = &camera->mEyeVelocity;
  this->mUpCurr.y = v11;
  this->mUpCurr.z = v12;
  if ( !withVelocity )
    p_mEyeVelocity = &UFG::qVector3::msZero;
  v14 = p_mEyeVelocity->y;
  v15 = p_mEyeVelocity->z;
  this->mEyeVelocity.x = p_mEyeVelocity->x;
  this->mEyeVelocity.y = v14;
  this->mEyeVelocity.z = v15;
  if ( withVelocity )
    p_mLookVelocity = &camera->mLookVelocity;
  v16 = p_mLookVelocity->y;
  v17 = p_mLookVelocity->z;
  this->mLookVelocity.x = p_mLookVelocity->x;
  this->mLookVelocity.y = v16;
  this->mLookVelocity.z = v17;
  ((void (__fastcall *)(UFG::BaseCameraComponent *))this->vfptr[24].__vecDelDtor)(this);
  if ( withVelocity )
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
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, __int64 *))this->vfptr[27].__vecDelDtor)(this, v28, v18);
  if ( withVelocity )
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
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, __int64 *))this->vfptr[28].__vecDelDtor)(this, v29, v19);
}

// File Line: 91
// RVA: 0xBA2E0
void __fastcall UFG::BaseCameraComponent::SetEyeLookUp(
        UFG::BaseCameraComponent *this,
        float dt,
        UFG::qVector3 *eye,
        UFG::qVector3 *loook,
        UFG::qVector3 *up)
{
  float x; // xmm3_4
  __int128 y_low; // xmm4
  float z; // xmm5_4
  float v9; // xmm10_4
  float y; // xmm11_4
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
  UFG::qMatrix44 *p_mView; // rcx
  float v25; // eax
  float v26; // xmm1_4
  UFG::qVector3 target; // [rsp+20h] [rbp-98h] BYREF

  x = loook->x;
  y_low = LODWORD(loook->y);
  z = loook->z;
  target.x = x;
  LODWORD(target.y) = y_low;
  target.z = z;
  v9 = eye->x;
  if ( eye->x == x && *(float *)&y_low == eye->y && z == eye->z )
  {
    x = x + 0.0099999998;
    target.x = x;
  }
  y = eye->y;
  v12 = eye->z;
  v13 = (__m128)y_low;
  v13.m128_f32[0] = *(float *)&y_low - y;
  v14 = x - v9;
  v15 = z - v12;
  v16 = v13;
  v16.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v14 * v14)) + (float)(v15 * v15);
  v17 = 0.0;
  if ( v16.m128_f32[0] != 0.0 )
    v17 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                      (float)((float)((float)(v13.m128_f32[0] * v17) * up->y) + (float)((float)(v14 * v17) * up->x))
                    + (float)((float)(v15 * v17) * up->z)) & _xmm) > 0.99984771 )
  {
    x = v9 + 1.0;
    *(float *)&y_low = y + 1.0;
    z = v12 + 1.0;
    target.x = v9 + 1.0;
    target.y = y + 1.0;
    target.z = v12 + 1.0;
  }
  if ( dt > 0.001 )
  {
    if ( this->mResetEyeLook )
    {
      this->mResetEyeLook = 0;
    }
    else
    {
      v18 = (float)(y - this->mEyeCurr.y) * (float)(1.0 / dt);
      v19 = (float)(v12 - this->mEyeCurr.z) * (float)(1.0 / dt);
      this->mEyeVelocity.x = (float)(v9 - this->mEyeCurr.x) * (float)(1.0 / dt);
      this->mEyeVelocity.y = v18;
      this->mEyeVelocity.z = v19;
      v20 = (float)(*(float *)&y_low - this->mLookCurr.y) * (float)(1.0 / dt);
      v21 = (float)(z - this->mLookCurr.z) * (float)(1.0 / dt);
      this->mLookVelocity.x = (float)(x - this->mLookCurr.x) * (float)(1.0 / dt);
      this->mLookVelocity.y = v20;
      this->mLookVelocity.z = v21;
    }
  }
  v22 = eye->y;
  v23 = eye->z;
  this->mEyeCurr.x = eye->x;
  p_mView = &this->mCamera.mView;
  p_mView[8].v2.z = v22;
  p_mView[8].v2.w = v23;
  p_mView[8].v3.x = x;
  LODWORD(p_mView[8].v3.y) = y_low;
  p_mView[8].v3.z = z;
  v25 = up->x;
  v26 = up->z;
  p_mView[9].v0.x = up->y;
  p_mView[8].v3.w = v25;
  p_mView[9].v0.y = v26;
  UFG::qLookAtMatrix(p_mView, eye, &target, up);
  UFG::qInverseAffine(&this->mCamera.mTransformation, &this->mCamera.mView);
}

