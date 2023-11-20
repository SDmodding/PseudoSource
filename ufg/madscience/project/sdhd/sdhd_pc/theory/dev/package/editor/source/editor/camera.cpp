// File Line: 52
// RVA: 0x20BD30
float __fastcall UFG::Editor::Camera::GetFOVHorz(UFG::Editor::Camera *this)
{
  UFG::Editor::Camera *v1; // rbx
  UFG::BaseCameraComponent *v2; // rax
  signed __int64 v3; // rax
  UFG::BaseCameraComponent *v4; // rcx
  float v5; // xmm1_4
  float result; // xmm0_4

  v1 = this;
  v2 = UFG::Director::Get()->mCurrentCamera;
  if ( v2 && (v3 = (signed __int64)&v2->mCamera) != 0 && !*(_BYTE *)(v3 + 256) )
  {
    v4 = UFG::Director::Get()->mCurrentCamera;
    if ( v4 )
      v5 = UFG::Camera::GetViewProjection(&v4->mCamera)->v0.x;
    else
      v5 = UFG::Camera::GetViewProjection(0i64)->v0.x;
  }
  else
  {
    v5 = v1->mProj.v0.x;
  }
  result = 0.0;
  if ( v5 != 0.0 )
    result = atan2f(1.0, v5) * 2.0;
  return result;
}

// File Line: 61
// RVA: 0x20BDB0
float __fastcall UFG::Editor::Camera::GetFOVVert(UFG::Editor::Camera *this)
{
  UFG::Editor::Camera *v1; // rbx
  UFG::BaseCameraComponent *v2; // rax
  signed __int64 v3; // rax
  UFG::BaseCameraComponent *v4; // rcx
  float v5; // xmm1_4
  float result; // xmm0_4

  v1 = this;
  v2 = UFG::Director::Get()->mCurrentCamera;
  if ( v2 && (v3 = (signed __int64)&v2->mCamera) != 0 && !*(_BYTE *)(v3 + 256) )
  {
    v4 = UFG::Director::Get()->mCurrentCamera;
    if ( v4 )
      v5 = UFG::Camera::GetViewProjection(&v4->mCamera)->v1.y;
    else
      v5 = UFG::Camera::GetViewProjection(0i64)->v1.y;
  }
  else
  {
    v5 = v1->mProj.v1.y;
  }
  result = 0.0;
  if ( v5 != 0.0 )
    result = atan2f(1.0, v5) * 2.0;
  return result;
}

// File Line: 116
// RVA: 0x21E2D0
bool __fastcall UFG::Editor::Camera::UsingGameCamera(UFG::Editor::Camera *this)
{
  UFG::BaseCameraComponent *v1; // rax
  signed __int64 v2; // rax
  bool result; // al

  v1 = UFG::Director::Get()->mCurrentCamera;
  if ( v1 && (v2 = (signed __int64)&v1->mCamera) != 0 )
    result = *(_BYTE *)(v2 + 256) == 0;
  else
    result = 0;
  return result;
}

