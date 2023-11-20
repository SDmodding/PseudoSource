// File Line: 97
// RVA: 0x145C60
UFG::qVector3 *__fastcall UFG::Editor::Camera::GetDirForward(UFG::Editor::Camera *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx
  UFG::Editor::Camera *v3; // rdi
  UFG::BaseCameraComponent *v4; // rax
  int v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  UFG::qVector3 *v8; // rax

  v2 = result;
  v3 = this;
  if ( UFG::Editor::Camera::UsingGameCamera(this) )
  {
    v4 = UFG::Director::Get()->mCurrentCamera;
    if ( v4 )
      v4 = (UFG::BaseCameraComponent *)((char *)v4 + 80);
    v5 = _xmm[0];
    v6 = v4->mCamera.mView.v1.z;
    LODWORD(v2->x) = LODWORD(v4->mCamera.mView.v1.x) ^ _xmm[0];
    v7 = v4->mCamera.mView.v1.y;
  }
  else
  {
    v5 = _xmm[0];
    v6 = v3->mCamera.v2.z;
    LODWORD(v2->x) = LODWORD(v3->mCamera.v2.x) ^ _xmm[0];
    v7 = v3->mCamera.v2.y;
  }
  v8 = v2;
  LODWORD(v2->z) = LODWORD(v6) ^ v5;
  LODWORD(v2->y) = LODWORD(v7) ^ v5;
  return v8;
}

// File Line: 136
// RVA: 0x1463C0
UFG::qVector3 *__fastcall UFG::Editor::Camera::GetPosition(UFG::Editor::Camera *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx
  UFG::Editor::Camera *v3; // rdi
  UFG::BaseCameraComponent *v4; // rcx
  UFG::qVector3 *v5; // rax

  v2 = result;
  v3 = this;
  if ( UFG::Editor::Camera::UsingGameCamera(this) )
  {
    v4 = UFG::Director::Get()->mCurrentCamera;
    if ( v4 )
      v4 = (UFG::BaseCameraComponent *)((char *)v4 + 80);
    v2->x = v4->mCamera.mView.v2.x;
    v2->y = v4->mCamera.mView.v2.y;
    v2->z = v4->mCamera.mView.v2.z;
    v5 = v2;
  }
  else
  {
    v2->x = v3->mCamera.v3.x;
    v2->y = v3->mCamera.v3.y;
    v2->z = v3->mCamera.v3.z;
    v5 = v2;
  }
  return v5;
}

// File Line: 154
// RVA: 0x20C0A0
UFG::qMatrix44 *__fastcall UFG::Editor::Camera::GetMatView(UFG::Editor::Camera *this, UFG::qMatrix44 *result)
{
  UFG::qMatrix44 *v2; // rbx
  UFG::Editor::Camera *v3; // rdi
  UFG::BaseCameraComponent *v4; // rax
  signed __int64 v5; // rax
  UFG::Camera *v6; // rcx
  UFG::qMatrix44 *v7; // rax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
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
  float v24; // xmm0_4
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
  UFG::qMatrix44 d; // [rsp+20h] [rbp-48h]

  v2 = result;
  v3 = this;
  v4 = UFG::Director::Get()->mCurrentCamera;
  if ( v4 && (v5 = (signed __int64)&v4->mCamera) != 0 && !*(_BYTE *)(v5 + 256) )
  {
    v6 = (UFG::Camera *)UFG::Director::Get()->mCurrentCamera;
    if ( v6 )
      v6 = (UFG::Camera *)((char *)v6 + 80);
    v7 = UFG::Camera::GetWorldView(v6);
    v8 = v7->v0.y;
    v9 = v7->v0.z;
    v10 = v7->v0.w;
    v2->v0.x = v7->v0.x;
    v2->v0.y = v8;
    v2->v0.z = v9;
    v2->v0.w = v10;
    v11 = v7->v1.y;
    v12 = v7->v1.z;
    v13 = v7->v1.w;
    v2->v1.x = v7->v1.x;
    v2->v1.y = v11;
    v2->v1.z = v12;
    v2->v1.w = v13;
    v14 = v7->v2.y;
    v15 = v7->v2.z;
    v16 = v7->v2.w;
    v2->v2.x = v7->v2.x;
    v2->v2.y = v14;
    v2->v2.z = v15;
    v2->v2.w = v16;
    v17 = v7->v3.y;
    v18 = v7->v3.z;
    v19 = v7->v3.w;
    v2->v3.x = v7->v3.x;
    v20 = v2;
    v2->v3.y = v17;
    v2->v3.z = v18;
    v2->v3.w = v19;
  }
  else
  {
    UFG::qInverseAffine(&d, &v3->mCamera);
    v20 = v2;
    v21 = d.v0.y;
    v2->v0.x = d.v0.x;
    v22 = d.v0.z;
    v2->v0.y = v21;
    v23 = d.v0.w;
    v2->v0.z = v22;
    v24 = d.v1.x;
    v2->v0.w = v23;
    v25 = d.v1.y;
    v2->v1.x = v24;
    v26 = d.v1.z;
    v2->v1.y = v25;
    v27 = d.v1.w;
    v2->v1.z = v26;
    v28 = d.v2.x;
    v2->v1.w = v27;
    v29 = d.v2.y;
    v2->v2.x = v28;
    v30 = d.v2.z;
    v2->v2.y = v29;
    v31 = d.v2.w;
    v2->v2.z = v30;
    v32 = d.v3.x;
    v2->v2.w = v31;
    v33 = d.v3.y;
    v2->v3.x = v32;
    v34 = d.v3.z;
    v2->v3.y = v33;
    v35 = d.v3.w;
    v2->v3.z = v34;
    v2->v3.w = v35;
  }
  return v20;
}

