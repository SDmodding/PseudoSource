// File Line: 52
// RVA: 0x20BD30
float __fastcall UFG::Editor::Camera::GetFOVHorz(UFG::Editor::Camera *this)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  UFG::BaseCameraComponent *v4; // rcx
  float x; // xmm1_4
  float result; // xmm0_4

  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && (p_mCamera = &mCurrentCamera->mCamera) != 0i64 && !p_mCamera->bUseOverrideMatrices )
  {
    v4 = UFG::Director::Get()->mCurrentCamera;
    if ( v4 )
      x = UFG::Camera::GetViewProjection(&v4->mCamera)->v0.x;
    else
      x = UFG::Camera::GetViewProjection(0i64)->v0.x;
  }
  else
  {
    x = this->mProj.v0.x;
  }
  result = 0.0;
  if ( x != 0.0 )
    return atan2f(1.0, x) * 2.0;
  return result;
}

// File Line: 61
// RVA: 0x20BDB0
float __fastcall UFG::Editor::Camera::GetFOVVert(UFG::Editor::Camera *this)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  UFG::BaseCameraComponent *v4; // rcx
  float y; // xmm1_4
  float result; // xmm0_4

  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && (p_mCamera = &mCurrentCamera->mCamera) != 0i64 && !p_mCamera->bUseOverrideMatrices )
  {
    v4 = UFG::Director::Get()->mCurrentCamera;
    if ( v4 )
      y = UFG::Camera::GetViewProjection(&v4->mCamera)->v1.y;
    else
      y = UFG::Camera::GetViewProjection(0i64)->v1.y;
  }
  else
  {
    y = this->mProj.v1.y;
  }
  result = 0.0;
  if ( y != 0.0 )
    return atan2f(1.0, y) * 2.0;
  return result;
}

// File Line: 116
// RVA: 0x21E2D0
bool __fastcall UFG::Editor::Camera::UsingGameCamera(UFG::Editor::Camera *this)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax

  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  return mCurrentCamera && (p_mCamera = &mCurrentCamera->mCamera) != 0i64 && !p_mCamera->bUseOverrideMatrices;
}

