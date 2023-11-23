// File Line: 22
// RVA: 0xB9280
void __fastcall UFG::Camera::Camera(UFG::Camera *this)
{
  UFG::qVector4 v2; // xmm2
  UFG::qVector4 v3; // xmm3
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm1
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  float x; // xmm0_4

  Render::DepthOfField::Focus::Focus(&this->mDepthOfFieldFocus);
  this->mFOVOffset = 0.0;
  UFG::qPerspectiveMatrix(&this->mProjection, 1.0471976, 1.7777778, 0.33000001, 4200.0);
  v2 = 0i64;
  this->mMotionBlur = 0.0;
  this->mMotionBlurIsTimeLimited = 0;
  this->mDesaturation = 0.0;
  v2.x = (float)1;
  this->mView.v0 = v2;
  this->mView.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 81);
  this->mView.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 69);
  this->mView.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 21);
  this->mTransformation.v0 = v2;
  this->mTransformation.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 81);
  this->mTransformation.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 69);
  this->mTransformation.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 21);
  this->bUseOverrideMatrices = 0;
  this->mOverrideView.v0 = v2;
  this->mOverrideView.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 81);
  this->mOverrideView.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 69);
  this->mOverrideView.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 21);
  this->mOverrideTrans.v0 = v2;
  this->mOverrideTrans.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 81);
  this->mOverrideTrans.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 69);
  this->mOverrideTrans.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 21);
  this->mOverrideProj.v0 = v2;
  this->mOverrideProj.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 81);
  this->mOverrideProj.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 69);
  this->mOverrideProj.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 21);
  v3 = this->mView.v1;
  v4 = this->mView.v2;
  v5 = this->mView.v3;
  this->mPreviousView.v0 = this->mView.v0;
  this->mPreviousView.v1 = v3;
  this->mPreviousView.v2 = v4;
  this->mPreviousView.v3 = v5;
  v6 = this->mTransformation.v1;
  v7 = this->mTransformation.v2;
  v8 = this->mTransformation.v3;
  this->mPreviousTransformation.v0 = this->mTransformation.v0;
  this->mPreviousTransformation.v1 = v6;
  this->mPreviousTransformation.v2 = v7;
  this->mPreviousTransformation.v3 = v8;
  v7.x = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  this->mVelocity.y = UFG::qVector3::msZero.y;
  this->mVelocity.x = x;
  this->mVelocity.z = v7.x;
}

// File Line: 42
// RVA: 0xB99F0
void __fastcall UFG::Camera::ApplyDutch(UFG::Camera *this, float radians)
{
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-48h] BYREF

  UFG::qRotationMatrixZ(&dest, radians);
  UFG::qMatrix44::operator*=(&this->mView, &dest);
  UFG::qInverseAffine(&this->mTransformation, &this->mView);
}

// File Line: 51
// RVA: 0xBA680
void __fastcall UFG::Camera::SetLookAtMatrix(
        UFG::Camera *this,
        UFG::qVector3 *eye,
        UFG::qVector3 *look,
        UFG::qVector3 *up)
{
  UFG::qLookAtMatrix(&this->mView, eye, look, up);
  UFG::qInverseAffine(&this->mTransformation, &this->mView);
}

// File Line: 85
// RVA: 0xBA6E0
void __fastcall UFG::Camera::SetViewProjection(
        UFG::Camera *this,
        float fov,
        float aspect,
        float nearPlane,
        float farPlane,
        float xOffset,
        float yOffset,
        bool applyFovOffset)
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
  UFG::qMatrix44 *p_mProjection; // rbx
  float near_plane; // [rsp+40h] [rbp-28h] BYREF
  float aspect; // [rsp+44h] [rbp-24h] BYREF
  float v5; // [rsp+48h] [rbp-20h] BYREF
  float pan_y; // [rsp+70h] [rbp+8h] BYREF
  float pan_x; // [rsp+80h] [rbp+18h] BYREF
  float far_plane; // [rsp+88h] [rbp+20h] BYREF

  p_mProjection = &this->mProjection;
  UFG::qDecomposePerspective(&v5, &aspect, &near_plane, &far_plane, &pan_x, &pan_y, &this->mProjection);
  UFG::qPerspectiveObliqueMatrix(p_mProjection, fov, aspect, near_plane, far_plane, pan_x, pan_y);
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
    return &this->mView;
  return result;
}

// File Line: 129
// RVA: 0xB9C70
UFG::qMatrix44 *__fastcall UFG::Camera::GetViewWorld(UFG::Camera *this)
{
  UFG::qMatrix44 *result; // rax

  result = &this->mOverrideTrans;
  if ( !this->bUseOverrideMatrices )
    return &this->mTransformation;
  return result;
}

// File Line: 135
// RVA: 0xB9C50
UFG::qMatrix44 *__fastcall UFG::Camera::GetViewProjection(UFG::Camera *this)
{
  UFG::qMatrix44 *result; // rax

  result = &this->mOverrideProj;
  if ( !this->bUseOverrideMatrices )
    return &this->mProjection;
  return result;
}

// File Line: 140
// RVA: 0xB9B70
UFG::qVector3 *__fastcall UFG::Camera::GetScreenCoord(
        UFG::Camera *this,
        UFG::qVector3 *result,
        UFG::qVector3 *world_pos,
        UFG::qVector2 *viewport_scale,
        bool *is_on_screen)
{
  UFG::qMatrix44 *p_mOverrideProj; // r8
  UFG::qMatrix44 *p_mOverrideView; // rcx
  UFG::qMatrix44 *v10; // rax
  UFG::qVector4 v11; // xmm3
  UFG::qVector4 v12; // xmm0
  UFG::qVector4 v13; // xmm1
  UFG::qMatrix44 resulta; // [rsp+30h] [rbp-48h] BYREF

  if ( this->bUseOverrideMatrices )
  {
    p_mOverrideProj = &this->mOverrideProj;
    p_mOverrideView = &this->mOverrideView;
  }
  else
  {
    p_mOverrideProj = &this->mProjection;
    p_mOverrideView = &this->mView;
  }
  v10 = UFG::qMatrix44::operator*(p_mOverrideView, &resulta, p_mOverrideProj);
  v11 = v10->v1;
  v12 = v10->v0;
  v13 = v10->v3;
  resulta.v2 = v10->v2;
  resulta.v1 = v11;
  resulta.v3 = v13;
  resulta.v0 = v12;
  UFG::qGetScreenCoord(result, world_pos, &resulta, viewport_scale, is_on_screen);
  return result;
}

// File Line: 198
// RVA: 0xBA0B0
UFG::qVector3 *__fastcall UFG::Camera::ScreenToWorldRay(
        UFG::Camera *this,
        UFG::qVector3 *result,
        UFG::qVector2 *screen_pos,
        UFG::qVector2 *viewport_scale)
{
  float x; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm6_4
  float v11; // xmm9_4
  __m128 x_low; // xmm10
  float v13; // xmm6_4
  UFG::qMatrix44 *p_mOverrideTrans; // rbx
  __m128 v15; // xmm2
  float v16; // xmm7_4
  UFG::qVector3 *v17; // rax
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm5_4
  float v22; // xmm6_4

  x = this->mProjection.v0.x;
  if ( x == 0.0 )
    v9 = 0.0;
  else
    v9 = atan2f(1.0, x) * 2.0;
  v10 = viewport_scale->x * 0.5;
  x_low = (__m128)LODWORD(screen_pos->x);
  v11 = (float)(viewport_scale->y * 0.5) - screen_pos->y;
  x_low.m128_f32[0] = x_low.m128_f32[0] - v10;
  LODWORD(v13) = COERCE_UNSIGNED_INT(v10 / tanf(v9 * 0.5)) ^ _xmm[0];
  if ( this->bUseOverrideMatrices )
    p_mOverrideTrans = &this->mOverrideTrans;
  else
    p_mOverrideTrans = &this->mTransformation;
  v15 = x_low;
  v15.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
  if ( v15.m128_f32[0] == 0.0 )
    v16 = 0.0;
  else
    v16 = 1.0 / _mm_sqrt_ps(v15).m128_f32[0];
  v17 = result;
  v18 = (float)(v16 * v11) * p_mOverrideTrans->v1.y;
  v19 = (float)(v16 * x_low.m128_f32[0]) * p_mOverrideTrans->v0.y;
  v20 = v13 * v16;
  v21 = (float)((float)(v16 * v11) * p_mOverrideTrans->v1.z)
      + (float)((float)(v16 * x_low.m128_f32[0]) * p_mOverrideTrans->v0.z);
  result->x = (float)((float)((float)(v16 * v11) * p_mOverrideTrans->v1.x)
                    + (float)((float)(v16 * x_low.m128_f32[0]) * p_mOverrideTrans->v0.x))
            + (float)((float)(v13 * v16) * p_mOverrideTrans->v2.x);
  v22 = (float)(v13 * v16) * p_mOverrideTrans->v2.z;
  result->y = (float)(v18 + v19) + (float)(v20 * p_mOverrideTrans->v2.y);
  result->z = v21 + v22;
  return v17;
}

