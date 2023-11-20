// File Line: 22
// RVA: 0xB9280
void __fastcall UFG::Camera::Camera(UFG::Camera *this)
{
  UFG::Camera *v1; // rbx
  __m128 v2; // xmm2
  UFG::qVector4 v3; // xmm3
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm1
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  float v9; // xmm0_4

  v1 = this;
  Render::DepthOfField::Focus::Focus(&this->mDepthOfFieldFocus);
  v1->mFOVOffset = 0.0;
  UFG::qPerspectiveMatrix(&v1->mProjection, 1.0471976, 1.7777778, 0.33000001, 4200.0);
  v2 = 0i64;
  v1->mMotionBlur = 0.0;
  v1->mMotionBlurIsTimeLimited = 0;
  v1->mDesaturation = 0.0;
  v2.m128_f32[0] = (float)1;
  v1->mView.v0 = (UFG::qVector4)v2;
  v1->mView.v1 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 81);
  v1->mView.v2 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 69);
  v1->mView.v3 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 21);
  v1->mTransformation.v0 = (UFG::qVector4)v2;
  v1->mTransformation.v1 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 81);
  v1->mTransformation.v2 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 69);
  v1->mTransformation.v3 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 21);
  v1->bUseOverrideMatrices = 0;
  v1->mOverrideView.v0 = (UFG::qVector4)v2;
  v1->mOverrideView.v1 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 81);
  v1->mOverrideView.v2 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 69);
  v1->mOverrideView.v3 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 21);
  v1->mOverrideTrans.v0 = (UFG::qVector4)v2;
  v1->mOverrideTrans.v1 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 81);
  v1->mOverrideTrans.v2 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 69);
  v1->mOverrideTrans.v3 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 21);
  v1->mOverrideProj.v0 = (UFG::qVector4)v2;
  v1->mOverrideProj.v1 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 81);
  v1->mOverrideProj.v2 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 69);
  v1->mOverrideProj.v3 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 21);
  v3 = v1->mView.v1;
  v4 = v1->mView.v2;
  v5 = v1->mView.v3;
  v1->mPreviousView.v0 = v1->mView.v0;
  v1->mPreviousView.v1 = v3;
  v1->mPreviousView.v2 = v4;
  v1->mPreviousView.v3 = v5;
  v6 = v1->mTransformation.v1;
  v7 = v1->mTransformation.v2;
  v8 = v1->mTransformation.v3;
  v1->mPreviousTransformation.v0 = v1->mTransformation.v0;
  v1->mPreviousTransformation.v1 = v6;
  v1->mPreviousTransformation.v2 = v7;
  v1->mPreviousTransformation.v3 = v8;
  v7.x = UFG::qVector3::msZero.z;
  v9 = UFG::qVector3::msZero.x;
  v1->mVelocity.y = UFG::qVector3::msZero.y;
  v1->mVelocity.x = v9;
  v1->mVelocity.z = v7.x;
}

// File Line: 42
// RVA: 0xB99F0
void __fastcall UFG::Camera::ApplyDutch(UFG::Camera *this, float radians)
{
  UFG::Camera *v2; // rdi
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-48h]

  v2 = this;
  UFG::qRotationMatrixZ(&dest, radians);
  UFG::qMatrix44::operator*=(&v2->mView, &dest);
  UFG::qInverseAffine(&v2->mTransformation, &v2->mView);
}

// File Line: 51
// RVA: 0xBA680
void __fastcall UFG::Camera::SetLookAtMatrix(UFG::Camera *this, UFG::qVector3 *eye, UFG::qVector3 *look, UFG::qVector3 *up)
{
  UFG::Camera *v4; // rdi

  v4 = this;
  UFG::qLookAtMatrix(&this->mView, eye, look, up);
  UFG::qInverseAffine(&v4->mTransformation, &v4->mView);
}

// File Line: 85
// RVA: 0xBA6E0
void __fastcall UFG::Camera::SetViewProjection(UFG::Camera *this, float fov, float aspect, float nearPlane, float farPlane, float xOffset, float yOffset, bool applyFovOffset)
{
  float v8; // xmm4_4

  v8 = fov;
  if ( applyFovOffset )
    v8 = fov + this->mFOVOffset;
  if ( UFG::gCameraOverrideFOVEnabled )
    v8 = (float)(UFG::gCameraOverrideFOV * 3.1415927) * 0.0055555557;
  UFG::qPerspectiveObliqueMatrix(&this->mProjection, v8, aspect, nearPlane, farPlane, xOffset, yOffset);
}

// File Line: 95
// RVA: 0xBA5E0
void __fastcall UFG::Camera::SetFov(UFG::Camera *this, float fov)
{
  UFG::qMatrix44 *v2; // rbx
  float near_plane; // [rsp+40h] [rbp-28h]
  float aspect; // [rsp+44h] [rbp-24h]
  __int64 v5; // [rsp+48h] [rbp-20h]
  float pan_y; // [rsp+70h] [rbp+8h]
  float pan_x; // [rsp+80h] [rbp+18h]
  float far_plane; // [rsp+88h] [rbp+20h]

  v2 = &this->mProjection;
  UFG::qDecomposePerspective((float *)&v5, &aspect, &near_plane, &far_plane, &pan_x, &pan_y, &this->mProjection);
  UFG::qPerspectiveObliqueMatrix(v2, fov, aspect, near_plane, far_plane, pan_x, pan_y);
}

// File Line: 103
// RVA: 0xBA940
void __fastcall UFG::Camera::Update(UFG::Camera *this, float elapsed_seconds)
{
  float v2; // xmm3_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm3
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1

  if ( elapsed_seconds > 0.001 )
  {
    v2 = 1.0 / elapsed_seconds;
    v3 = (float)(this->mTransformation.v3.z - this->mPreviousTransformation.v3.z) * (float)(1.0 / elapsed_seconds);
    v4 = this->mTransformation.v3.y - this->mPreviousTransformation.v3.y;
    this->mVelocity.x = (float)(this->mTransformation.v3.x - this->mPreviousTransformation.v3.x) * v2;
    this->mVelocity.z = v3;
    this->mVelocity.y = v4 * v2;
    v5 = this->mView.v1;
    v6 = this->mView.v2;
    v7 = this->mView.v3;
    this->mPreviousView.v0 = this->mView.v0;
    this->mPreviousView.v1 = v5;
    this->mPreviousView.v2 = v6;
    this->mPreviousView.v3 = v7;
    v8 = this->mTransformation.v1;
    v9 = this->mTransformation.v2;
    v10 = this->mTransformation.v3;
    this->mPreviousTransformation.v0 = this->mTransformation.v0;
    this->mPreviousTransformation.v1 = v8;
    this->mPreviousTransformation.v2 = v9;
    this->mPreviousTransformation.v3 = v10;
  }
}

// File Line: 123
// RVA: 0xB9C90
UFG::qMatrix44 *__fastcall UFG::Camera::GetWorldView(UFG::Camera *this)
{
  UFG::qMatrix44 *result; // rax

  result = &this->mOverrideView;
  if ( !this->bUseOverrideMatrices )
    result = &this->mView;
  return result;
}

// File Line: 129
// RVA: 0xB9C70
UFG::qMatrix44 *__fastcall UFG::Camera::GetViewWorld(UFG::Camera *this)
{
  UFG::qMatrix44 *result; // rax

  result = &this->mOverrideTrans;
  if ( !this->bUseOverrideMatrices )
    result = &this->mTransformation;
  return result;
}

// File Line: 135
// RVA: 0xB9C50
UFG::qMatrix44 *__fastcall UFG::Camera::GetViewProjection(UFG::Camera *this)
{
  UFG::qMatrix44 *result; // rax

  result = &this->mOverrideProj;
  if ( !this->bUseOverrideMatrices )
    result = &this->mProjection;
  return result;
}

// File Line: 140
// RVA: 0xB9B70
UFG::qVector3 *__fastcall UFG::Camera::GetScreenCoord(UFG::Camera *this, UFG::qVector3 *result, UFG::qVector3 *world_pos, UFG::qVector2 *viewport_scale, bool *is_on_screen)
{
  UFG::qVector3 *v5; // rbx
  UFG::qVector2 *v6; // rdi
  UFG::qVector3 *v7; // rsi
  UFG::qMatrix44 *v8; // r8
  UFG::qMatrix44 *v9; // rcx
  UFG::qMatrix44 *v10; // rax
  UFG::qVector4 v11; // xmm3
  UFG::qVector4 v12; // xmm0
  UFG::qVector4 v13; // xmm1
  UFG::qMatrix44 resulta; // [rsp+30h] [rbp-48h]

  v5 = result;
  v6 = viewport_scale;
  v7 = world_pos;
  if ( this->bUseOverrideMatrices )
  {
    v8 = &this->mOverrideProj;
    v9 = &this->mOverrideView;
  }
  else
  {
    v8 = &this->mProjection;
    v9 = &this->mView;
  }
  v10 = UFG::qMatrix44::operator*(v9, &resulta, v8);
  v11 = v10->v1;
  v12 = v10->v0;
  v13 = v10->v3;
  resulta.v2 = v10->v2;
  resulta.v1 = v11;
  resulta.v3 = v13;
  resulta.v0 = v12;
  UFG::qGetScreenCoord(v5, v7, &resulta, v6, is_on_screen);
  return v5;
}

// File Line: 198
// RVA: 0xBA0B0
UFG::qVector3 *__fastcall UFG::Camera::ScreenToWorldRay(UFG::Camera *this, UFG::qVector3 *result, UFG::qVector2 *screen_pos, UFG::qVector2 *viewport_scale)
{
  float v4; // xmm1_4
  UFG::qVector2 *v5; // rdi
  UFG::qVector2 *v6; // rsi
  UFG::qVector3 *v7; // rbp
  UFG::Camera *v8; // rbx
  float v9; // xmm0_4
  float v10; // xmm6_4
  float v11; // xmm9_4
  __m128 v12; // xmm10
  float v13; // xmm6_4
  float *v14; // rbx
  __m128 v15; // xmm2
  float v16; // xmm7_4
  UFG::qVector3 *v17; // rax
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm5_4
  float v22; // xmm6_4

  v4 = this->mProjection.v0.x;
  v5 = viewport_scale;
  v6 = screen_pos;
  v7 = result;
  v8 = this;
  if ( v4 == 0.0 )
    v9 = 0.0;
  else
    v9 = atan2f(1.0, v4) * 2.0;
  v10 = v5->x * 0.5;
  v12 = (__m128)LODWORD(v6->x);
  v11 = (float)(v5->y * 0.5) - v6->y;
  v12.m128_f32[0] = v12.m128_f32[0] - v10;
  LODWORD(v13) = COERCE_UNSIGNED_INT(v10 / tanf(v9 * 0.5)) ^ _xmm[0];
  if ( v8->bUseOverrideMatrices )
    v14 = &v8->mOverrideTrans.v0.x;
  else
    v14 = &v8->mTransformation.v0.x;
  v15 = v12;
  v15.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
  if ( v15.m128_f32[0] == 0.0 )
    v16 = 0.0;
  else
    v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v15));
  v17 = v7;
  v18 = (float)(v16 * v11) * v14[5];
  v19 = (float)(v16 * v12.m128_f32[0]) * v14[1];
  v20 = v13 * v16;
  v21 = (float)((float)(v16 * v11) * v14[6]) + (float)((float)(v16 * v12.m128_f32[0]) * v14[2]);
  v7->x = (float)((float)((float)(v16 * v11) * v14[4]) + (float)((float)(v16 * v12.m128_f32[0]) * *v14))
        + (float)((float)(v13 * v16) * v14[8]);
  v22 = (float)(v13 * v16) * v14[10];
  v7->y = (float)(v18 + v19) + (float)(v20 * v14[9]);
  v7->z = v21 + v22;
  return v17;
}

