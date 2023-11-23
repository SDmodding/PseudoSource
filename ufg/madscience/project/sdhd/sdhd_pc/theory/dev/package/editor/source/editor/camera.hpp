// File Line: 97
// RVA: 0x145C60
UFG::qVector3 *__fastcall UFG::Editor::Camera::GetDirForward(UFG::Editor::Camera *this, UFG::qVector3 *result)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  int v5; // xmm2_4
  float z; // xmm1_4
  float y; // xmm0_4
  UFG::qVector3 *v8; // rax

  if ( UFG::Editor::Camera::UsingGameCamera(this) )
  {
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
    v5 = _xmm[0];
    z = mCurrentCamera->mCamera.mView.v1.z;
    LODWORD(result->x) = LODWORD(mCurrentCamera->mCamera.mView.v1.x) ^ _xmm[0];
    y = mCurrentCamera->mCamera.mView.v1.y;
  }
  else
  {
    v5 = _xmm[0];
    z = this->mCamera.v2.z;
    LODWORD(result->x) = LODWORD(this->mCamera.v2.x) ^ _xmm[0];
    y = this->mCamera.v2.y;
  }
  v8 = result;
  LODWORD(result->z) = LODWORD(z) ^ v5;
  LODWORD(result->y) = LODWORD(y) ^ v5;
  return v8;
}

// File Line: 136
// RVA: 0x1463C0
UFG::qVector3 *__fastcall UFG::Editor::Camera::GetPosition(UFG::Editor::Camera *this, UFG::qVector3 *result)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rcx

  if ( UFG::Editor::Camera::UsingGameCamera(this) )
  {
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
    result->x = mCurrentCamera->mCamera.mView.v2.x;
    result->y = mCurrentCamera->mCamera.mView.v2.y;
    result->z = mCurrentCamera->mCamera.mView.v2.z;
    return result;
  }
  else
  {
    result->x = this->mCamera.v3.x;
    result->y = this->mCamera.v3.y;
    result->z = this->mCamera.v3.z;
    return result;
  }
}

// File Line: 154
// RVA: 0x20C0A0
UFG::qMatrix44 *__fastcall UFG::Editor::Camera::GetMatView(UFG::Editor::Camera *this, UFG::qMatrix44 *result)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  UFG::Camera *v6; // rcx
  UFG::qMatrix44 *WorldView; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  float w; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qMatrix44 *v20; // rax
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float x; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  UFG::qMatrix44 d; // [rsp+20h] [rbp-48h] BYREF

  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && (p_mCamera = &mCurrentCamera->mCamera) != 0i64 && !p_mCamera->bUseOverrideMatrices )
  {
    v6 = (UFG::Camera *)UFG::Director::Get()->mCurrentCamera;
    if ( v6 )
      v6 = (UFG::Camera *)((char *)v6 + 80);
    WorldView = UFG::Camera::GetWorldView(v6);
    y = WorldView->v0.y;
    z = WorldView->v0.z;
    w = WorldView->v0.w;
    result->v0.x = WorldView->v0.x;
    result->v0.y = y;
    result->v0.z = z;
    result->v0.w = w;
    v11 = WorldView->v1.y;
    v12 = WorldView->v1.z;
    v13 = WorldView->v1.w;
    result->v1.x = WorldView->v1.x;
    result->v1.y = v11;
    result->v1.z = v12;
    result->v1.w = v13;
    v14 = WorldView->v2.y;
    v15 = WorldView->v2.z;
    v16 = WorldView->v2.w;
    result->v2.x = WorldView->v2.x;
    result->v2.y = v14;
    result->v2.z = v15;
    result->v2.w = v16;
    v17 = WorldView->v3.y;
    v18 = WorldView->v3.z;
    v19 = WorldView->v3.w;
    result->v3.x = WorldView->v3.x;
    v20 = result;
    result->v3.y = v17;
    result->v3.z = v18;
    result->v3.w = v19;
  }
  else
  {
    UFG::qInverseAffine(&d, &this->mCamera);
    v20 = result;
    v21 = d.v0.y;
    result->v0.x = d.v0.x;
    v22 = d.v0.z;
    result->v0.y = v21;
    v23 = d.v0.w;
    result->v0.z = v22;
    x = d.v1.x;
    result->v0.w = v23;
    v25 = d.v1.y;
    result->v1.x = x;
    v26 = d.v1.z;
    result->v1.y = v25;
    v27 = d.v1.w;
    result->v1.z = v26;
    v28 = d.v2.x;
    result->v1.w = v27;
    v29 = d.v2.y;
    result->v2.x = v28;
    v30 = d.v2.z;
    result->v2.y = v29;
    v31 = d.v2.w;
    result->v2.z = v30;
    v32 = d.v3.x;
    result->v2.w = v31;
    v33 = d.v3.y;
    result->v3.x = v32;
    v34 = d.v3.z;
    result->v3.y = v33;
    v35 = d.v3.w;
    result->v3.z = v34;
    result->v3.w = v35;
  }
  return v20;
}

