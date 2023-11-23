// File Line: 26
// RVA: 0x93EF90
void __fastcall Scaleform::Render::MatrixState::MatrixState(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::HAL *phal)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MatrixState,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MatrixState::`vftable;
  *(_OWORD *)&this->View2D.M[0][0] = 0x3F800000ui64;
  this->View2D.M[1][0] = 0.0;
  *(_QWORD *)&this->View2D.M[1][1] = 1065353216i64;
  this->View2D.M[1][3] = 0.0;
  memset(&this->View3D, 0, sizeof(this->View3D));
  this->View3D.M[0][0] = 1.0;
  this->View3D.M[1][1] = 1.0;
  this->View3D.M[2][2] = 1.0;
  memset(&this->Proj3D, 0, sizeof(this->Proj3D));
  this->Proj3D.M[0][0] = 1.0;
  this->Proj3D.M[1][1] = 1.0;
  this->Proj3D.M[2][2] = 1.0;
  this->Proj3D.M[3][3] = 1.0;
  memset(&this->Proj3DLeft, 0, sizeof(this->Proj3DLeft));
  this->Proj3DLeft.M[0][0] = 1.0;
  this->Proj3DLeft.M[1][1] = 1.0;
  this->Proj3DLeft.M[2][2] = 1.0;
  this->Proj3DLeft.M[3][3] = 1.0;
  memset(&this->Proj3DRight, 0, sizeof(this->Proj3DRight));
  this->Proj3DRight.M[0][0] = 1.0;
  this->Proj3DRight.M[1][1] = 1.0;
  this->Proj3DRight.M[2][2] = 1.0;
  this->Proj3DRight.M[3][3] = 1.0;
  *(_QWORD *)&this->User.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->User.M[0][2] = 0i64;
  this->User.M[1][0] = 0.0;
  *(_QWORD *)&this->User.M[1][1] = 1065353216i64;
  this->User.M[1][3] = 0.0;
  *(_QWORD *)&this->User3D.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->User3D.M[0][2] = 0i64;
  this->User3D.M[1][0] = 0.0;
  *(_QWORD *)&this->User3D.M[1][1] = 1065353216i64;
  this->User3D.M[1][3] = 0.0;
  *(_QWORD *)&this->Orient2D.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->Orient2D.M[0][2] = 0i64;
  this->Orient2D.M[1][0] = 0.0;
  *(_QWORD *)&this->Orient2D.M[1][1] = 1065353216i64;
  this->Orient2D.M[1][3] = 0.0;
  memset(&this->Orient3D, 0, sizeof(this->Orient3D));
  this->Orient3D.M[0][0] = 1.0;
  this->Orient3D.M[1][1] = 1.0;
  this->Orient3D.M[2][2] = 1.0;
  *(_QWORD *)&this->Orient3D.M[3][3] = 1065353216i64;
  *(_QWORD *)&this->ViewRectOriginal.y1 = 0i64;
  *(_QWORD *)&this->ViewRectOriginal.y2 = 0i64;
  *(_QWORD *)&this->ViewRect.y1 = 0i64;
  this->ViewRect.y2 = 0;
  *(_QWORD *)&this->UserView.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->UserView.M[0][2] = 0i64;
  this->UserView.M[1][0] = 0.0;
  *(_QWORD *)&this->UserView.M[1][1] = 1065353216i64;
  this->UserView.M[1][3] = 0.0;
  memset(&this->UVPO, 0, sizeof(this->UVPO));
  this->UVPO.M[0][0] = 1.0;
  this->UVPO.M[1][1] = 1.0;
  this->UVPO.M[2][2] = 1.0;
  this->UVPO.M[3][3] = 1.0;
  memset(&this->ViewRectCompensated3D, 0, sizeof(this->ViewRectCompensated3D));
  this->ViewRectCompensated3D.M[0][0] = 1.0;
  this->ViewRectCompensated3D.M[1][1] = 1.0;
  this->ViewRectCompensated3D.M[2][2] = 1.0;
  this->ViewRectCompensated3D.M[3][3] = 1.0;
  *(_WORD *)&this->UVPOChanged = 0;
  this->S3DDisplay = StereoCenter;
  this->S3DImpl.pObject = 0i64;
  this->pHAL = phal;
  *(_QWORD *)&this->FullViewportMVP.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->FullViewportMVP.M[0][2] = 0i64;
  *(_QWORD *)&this->FullViewportMVP.M[1][1] = 1065353216i64;
  *(_QWORD *)&this->FullViewportMVP.M[1][2] = 0i64;
  *(_QWORD *)&this->FullViewportMVP.M[0][0] = 0x40000000i64;
  this->FullViewportMVP.M[0][2] = 0.0;
  this->FullViewportMVP.M[0][3] = -1.0;
  this->FullViewportMVP.M[1][0] = 0.0;
  this->FullViewportMVP.M[1][1] = -2.0;
  this->FullViewportMVP.M[1][3] = 1.0;
}

// File Line: 34
// RVA: 0x93F2E0
void __fastcall Scaleform::Render::MatrixState::MatrixState(Scaleform::Render::MatrixState *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MatrixState,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MatrixState::`vftable;
  *(_OWORD *)&this->View2D.M[0][0] = 0x3F800000ui64;
  this->View2D.M[1][0] = 0.0;
  *(_QWORD *)&this->View2D.M[1][1] = 1065353216i64;
  this->View2D.M[1][3] = 0.0;
  memset(&this->View3D, 0, sizeof(this->View3D));
  this->View3D.M[0][0] = 1.0;
  this->View3D.M[1][1] = 1.0;
  this->View3D.M[2][2] = 1.0;
  memset(&this->Proj3D, 0, sizeof(this->Proj3D));
  this->Proj3D.M[0][0] = 1.0;
  this->Proj3D.M[1][1] = 1.0;
  this->Proj3D.M[2][2] = 1.0;
  this->Proj3D.M[3][3] = 1.0;
  memset(&this->Proj3DLeft, 0, sizeof(this->Proj3DLeft));
  this->Proj3DLeft.M[0][0] = 1.0;
  this->Proj3DLeft.M[1][1] = 1.0;
  this->Proj3DLeft.M[2][2] = 1.0;
  this->Proj3DLeft.M[3][3] = 1.0;
  memset(&this->Proj3DRight, 0, sizeof(this->Proj3DRight));
  this->Proj3DRight.M[0][0] = 1.0;
  this->Proj3DRight.M[1][1] = 1.0;
  this->Proj3DRight.M[2][2] = 1.0;
  this->Proj3DRight.M[3][3] = 1.0;
  *(_QWORD *)&this->User.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->User.M[0][2] = 0i64;
  this->User.M[1][0] = 0.0;
  *(_QWORD *)&this->User.M[1][1] = 1065353216i64;
  this->User.M[1][3] = 0.0;
  *(_QWORD *)&this->User3D.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->User3D.M[0][2] = 0i64;
  this->User3D.M[1][0] = 0.0;
  *(_QWORD *)&this->User3D.M[1][1] = 1065353216i64;
  this->User3D.M[1][3] = 0.0;
  *(_QWORD *)&this->Orient2D.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->Orient2D.M[0][2] = 0i64;
  this->Orient2D.M[1][0] = 0.0;
  *(_QWORD *)&this->Orient2D.M[1][1] = 1065353216i64;
  this->Orient2D.M[1][3] = 0.0;
  memset(&this->Orient3D, 0, sizeof(this->Orient3D));
  this->Orient3D.M[0][0] = 1.0;
  this->Orient3D.M[1][1] = 1.0;
  this->Orient3D.M[2][2] = 1.0;
  *(_QWORD *)&this->Orient3D.M[3][3] = 1065353216i64;
  *(_QWORD *)&this->ViewRectOriginal.y1 = 0i64;
  *(_QWORD *)&this->ViewRectOriginal.y2 = 0i64;
  *(_QWORD *)&this->ViewRect.y1 = 0i64;
  this->ViewRect.y2 = 0;
  *(_QWORD *)&this->UserView.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->UserView.M[0][2] = 0i64;
  this->UserView.M[1][0] = 0.0;
  *(_QWORD *)&this->UserView.M[1][1] = 1065353216i64;
  this->UserView.M[1][3] = 0.0;
  memset(&this->UVPO, 0, sizeof(this->UVPO));
  this->UVPO.M[0][0] = 1.0;
  this->UVPO.M[1][1] = 1.0;
  this->UVPO.M[2][2] = 1.0;
  this->UVPO.M[3][3] = 1.0;
  memset(&this->ViewRectCompensated3D, 0, sizeof(this->ViewRectCompensated3D));
  this->ViewRectCompensated3D.M[0][0] = 1.0;
  this->ViewRectCompensated3D.M[1][1] = 1.0;
  this->ViewRectCompensated3D.M[2][2] = 1.0;
  this->ViewRectCompensated3D.M[3][3] = 1.0;
  *(_WORD *)&this->UVPOChanged = 0;
  this->S3DDisplay = StereoCenter;
  this->S3DImpl.pObject = 0i64;
  this->pHAL = 0i64;
  *(_QWORD *)&this->FullViewportMVP.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->FullViewportMVP.M[0][2] = 0i64;
  *(_QWORD *)&this->FullViewportMVP.M[1][1] = 1065353216i64;
  *(_QWORD *)&this->FullViewportMVP.M[1][2] = 0i64;
  *(_QWORD *)&this->FullViewportMVP.M[0][0] = 0x40000000i64;
  this->FullViewportMVP.M[0][2] = 0.0;
  this->FullViewportMVP.M[0][3] = -1.0;
  this->FullViewportMVP.M[1][0] = 0.0;
  this->FullViewportMVP.M[1][1] = -2.0;
  this->FullViewportMVP.M[1][3] = 1.0;
}

// File Line: 39
// RVA: 0x9B5390
void __fastcall Scaleform::Render::MatrixState::SetUserMatrix(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::Matrix2x4<float> *user,
        Scaleform::Render::Matrix2x4<float> *user3D)
{
  Scaleform::Render::Matrix2x4<float> *v5; // rax
  float v6; // xmm7_4
  int v7; // eax
  float v8; // xmm5_4
  float v9; // xmm1_4
  Scaleform::Render::Matrix2x4<float> result; // [rsp+20h] [rbp-68h] BYREF
  Scaleform::Render::Matrix2x4<float> v11; // [rsp+40h] [rbp-48h] BYREF

  this->UVPOChanged = 1;
  this->User = *user;
  v5 = Scaleform::Render::operator*(&result, &this->User, &this->Orient2D);
  this->UserView = *Scaleform::Render::operator*(&v11, &this->View2D, v5);
  this->User3D.M[0][0] = user3D->M[0][0];
  this->User3D.M[0][1] = user3D->M[0][1];
  this->User3D.M[0][2] = user3D->M[0][2];
  this->User3D.M[0][3] = user3D->M[0][3];
  this->User3D.M[1][0] = user3D->M[1][0];
  this->User3D.M[1][1] = user3D->M[1][1];
  this->User3D.M[1][2] = user3D->M[1][2];
  v6 = user3D->M[1][3];
  this->User3D.M[1][3] = v6;
  if ( this->ViewRect.x2 - this->ViewRect.x1 <= 0 || (v7 = this->ViewRect.y2 - this->ViewRect.y1, v7 <= 0) )
  {
    this->User3D.M[0][3] = 0.0;
    this->User3D.M[1][3] = 0.0;
  }
  else
  {
    v8 = (float)(this->ViewRect.x2 - this->ViewRect.x1);
    v9 = (float)((float)((float)((float)((float)((float)v7 * 0.5) * this->User3D.M[1][1])
                               + (float)((float)(v8 * 0.5) * this->User3D.M[1][0]))
                       + v6)
               - (float)((float)v7 * 0.5))
       * -2.0;
    this->User3D.M[0][3] = (float)((float)((float)((float)((float)((float)(v8 * 0.5) * this->User3D.M[0][0])
                                                         + (float)((float)((float)v7 * 0.5) * this->User3D.M[0][1]))
                                                 + this->User3D.M[0][3])
                                         - (float)(v8 * 0.5))
                                 * 2.0)
                         / v8;
    this->User3D.M[1][3] = v9 / (float)v7;
  }
}

// File Line: 63
// RVA: 0x9B55A0
void __fastcall Scaleform::Render::MatrixState::SetUserMatrix(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::Matrix2x4<float> *user)
{
  ((void (__fastcall *)(Scaleform::Render::MatrixState *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *))this->vfptr[2].__vecDelDtor)(
    this,
    user,
    user);
}

// File Line: 68
// RVA: 0x9B5DA0
void __fastcall Scaleform::Render::MatrixState::SetViewportMatrix(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::Matrix2x4<float> *vp)
{
  Scaleform::Render::Matrix2x4<float> *v3; // rax
  Scaleform::Render::Matrix2x4<float> result; // [rsp+20h] [rbp-48h] BYREF
  Scaleform::Render::Matrix2x4<float> v5; // [rsp+40h] [rbp-28h] BYREF

  this->View2D = *vp;
  v3 = Scaleform::Render::operator*(&result, &this->User, &this->Orient2D);
  this->UserView = *Scaleform::Render::operator*(&v5, &this->View2D, v3);
}

// File Line: 74
// RVA: 0x9B1F10
Scaleform::Render::Viewport *__fastcall Scaleform::Render::MatrixState::SetOrientation(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::Viewport *result,
        Scaleform::Render::Viewport *vp)
{
  float v6; // xmm1_4
  float BufferWidth; // xmm3_4
  float BufferHeight; // xmm2_4
  Scaleform::Render::Matrix2x4<float> *v9; // rax
  Scaleform::Render::Matrix2x4<float> *v10; // rax
  float v11; // ecx
  float v12; // ecx
  float v13; // ecx
  int Left; // ecx
  int Top; // edx
  float v16; // xmm9_4
  __m128 v17; // xmm6
  float v18; // xmm10_4
  unsigned int Flags; // r8d
  __m128 v20; // xmm5
  float v21; // xmm11_4
  float v22; // xmm12_4
  __m128 v23; // xmm4
  __m128 v24; // xmm3
  float v25; // xmm1_4
  __m128 v26; // xmm7
  __m128 v27; // xmm8
  __m128 v28; // xmm1
  int v29; // ecx
  __m128 v30; // xmm1
  int v31; // ecx
  __m128 v32; // xmm4
  int v33; // ecx
  __m128 v34; // xmm3
  int v35; // ecx
  int ScissorLeft; // ecx
  int ScissorTop; // edx
  int v38; // eax
  __m128 v39; // xmm4
  __m128 v40; // xmm3
  float v41; // xmm0_4
  __m128 v42; // xmm1
  int v43; // ecx
  __m128 v44; // xmm1
  int v45; // ecx
  __m128 v46; // xmm4
  int v47; // ecx
  __m128 v48; // xmm3
  int v49; // ecx
  Scaleform::Render::Matrix2x4<float> resulta; // [rsp+20h] [rbp-B8h] BYREF
  Scaleform::Render::Matrix2x4<float> v52; // [rsp+40h] [rbp-98h] BYREF

  *(_WORD *)&this->UVPOChanged = 1;
  if ( (vp->Flags & 0x30) != 0 )
  {
    if ( (((vp->Flags & 0x30) - 16) & 0xFFFFFFDF) == 0 )
    {
      this->OrientationSet = 1;
      if ( (vp->Flags & 0x30) == 48 )
      {
        v6 = FLOAT_N1_0;
        BufferWidth = 0.0;
        BufferHeight = (float)vp->BufferHeight;
      }
      else
      {
        v6 = *(float *)&FLOAT_1_0;
        BufferHeight = 0.0;
        BufferWidth = (float)vp->BufferWidth;
      }
      this->Orient2D.M[0][3] = BufferWidth;
      this->Orient2D.M[1][0] = v6;
      this->Orient2D.M[1][3] = BufferHeight;
      this->Orient2D.M[0][0] = 0.0;
      this->Orient2D.M[0][2] = 0.0;
      *(_QWORD *)&this->Orient2D.M[1][1] = 0i64;
      LODWORD(this->Orient2D.M[0][1]) = LODWORD(v6) ^ _xmm[0];
      this->Orient3D.M[0][1] = v6;
      LODWORD(this->Orient3D.M[1][0]) = LODWORD(v6) ^ _xmm[0];
      this->Orient3D.M[0][0] = 0.0;
      this->Orient3D.M[1][1] = 0.0;
    }
  }
  else
  {
    *(_OWORD *)&this->Orient2D.M[0][0] = 0x3F800000ui64;
    this->Orient2D.M[1][0] = 0.0;
    *(_QWORD *)&this->Orient2D.M[1][1] = 1065353216i64;
    this->Orient2D.M[1][3] = 0.0;
    memset(&this->Orient3D, 0, sizeof(this->Orient3D));
    this->Orient3D.M[0][0] = 1.0;
    this->Orient3D.M[1][1] = 1.0;
    this->Orient3D.M[2][2] = 1.0;
    this->Orient3D.M[3][3] = 1.0;
  }
  v9 = Scaleform::Render::operator*(&resulta, &this->User, &this->Orient2D);
  v10 = Scaleform::Render::operator*(&v52, &this->View2D, v9);
  *(_QWORD *)&result->BufferWidth = 0i64;
  *(_QWORD *)&result->Left = 0i64;
  v11 = v10->M[0][0];
  result->Height = 1;
  result->Width = 1;
  this->UserView.M[0][0] = v11;
  v12 = v10->M[0][1];
  *(_QWORD *)&result->ScissorWidth = 0i64;
  this->UserView.M[0][1] = v12;
  v13 = v10->M[0][2];
  *(_QWORD *)&result->ScissorLeft = 0i64;
  this->UserView.M[0][2] = v13;
  this->UserView.M[0][3] = v10->M[0][3];
  *(_OWORD *)&this->UserView.M[1][0] = *(_OWORD *)&v10->M[1][0];
  Left = vp->Left;
  Top = vp->Top;
  v16 = this->Orient2D.M[0][1];
  v17 = (__m128)LODWORD(this->Orient2D.M[0][0]);
  v18 = this->Orient2D.M[1][1];
  v23 = v17;
  v26 = v17;
  Flags = vp->Flags;
  v20 = (__m128)LODWORD(this->Orient2D.M[1][0]);
  v21 = this->Orient2D.M[0][3];
  v22 = this->Orient2D.M[1][3];
  LODWORD(v10) = Left + vp->Width;
  result->Flags = Flags;
  v24 = v20;
  v27 = v20;
  v23.m128_f32[0] = (float)((float)(v17.m128_f32[0] * (float)Left) + (float)(v16 * (float)Top)) + v21;
  v24.m128_f32[0] = (float)((float)(v20.m128_f32[0] * (float)Left) + (float)(v18 * (float)Top)) + v22;
  v25 = (float)(Top + vp->Height);
  v26.m128_f32[0] = (float)((float)(v17.m128_f32[0] * (float)(int)v10) + (float)(v16 * v25)) + v21;
  v27.m128_f32[0] = (float)((float)(v20.m128_f32[0] * (float)(int)v10) + (float)(v18 * v25)) + v22;
  if ( v23.m128_f32[0] >= v26.m128_f32[0] )
    v28 = v26;
  else
    v28 = v23;
  v29 = (int)v28.m128_f32[0];
  if ( (int)v28.m128_f32[0] != 0x80000000 && (float)v29 != v28.m128_f32[0] )
    v28.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v28, v28)) & 1) + v29);
  result->Left = (int)v28.m128_f32[0];
  if ( v24.m128_f32[0] >= v27.m128_f32[0] )
    v30 = v27;
  else
    v30 = v24;
  v31 = (int)v30.m128_f32[0];
  if ( (int)v30.m128_f32[0] != 0x80000000 && (float)v31 != v30.m128_f32[0] )
    v30.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v30, v30)) & 1) + v31);
  v23.m128_f32[0] = v23.m128_f32[0] - v26.m128_f32[0];
  v32 = _mm_and_ps(v23, (__m128)(unsigned int)_xmm);
  result->Top = (int)v30.m128_f32[0];
  v33 = (int)v32.m128_f32[0];
  if ( (int)v32.m128_f32[0] != 0x80000000 && (float)v33 != v32.m128_f32[0] )
    v32.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v32, v32)) & 1) + v33);
  v24.m128_f32[0] = v24.m128_f32[0] - v27.m128_f32[0];
  v34 = _mm_and_ps(v24, (__m128)(unsigned int)_xmm);
  result->Width = (int)v32.m128_f32[0];
  v35 = (int)v34.m128_f32[0];
  if ( (int)v34.m128_f32[0] != 0x80000000 && (float)v35 != v34.m128_f32[0] )
    v34.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v34, v34)) & 1) + v35);
  result->Height = (int)v34.m128_f32[0];
  if ( (Flags & 4) != 0 )
  {
    ScissorLeft = vp->ScissorLeft;
    ScissorTop = vp->ScissorTop;
    v39 = v17;
    v40 = v20;
    v38 = ScissorLeft + vp->ScissorWidth;
    result->Flags = Flags;
    v39.m128_f32[0] = (float)((float)(v17.m128_f32[0] * (float)ScissorLeft) + (float)(v16 * (float)ScissorTop)) + v21;
    v40.m128_f32[0] = (float)((float)(v20.m128_f32[0] * (float)ScissorLeft) + (float)(v18 * (float)ScissorTop)) + v22;
    v41 = (float)(ScissorTop + vp->ScissorHeight);
    v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] * (float)v38) + (float)(v16 * v41)) + v21;
    v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * (float)v38) + (float)(v18 * v41)) + v22;
    if ( v39.m128_f32[0] >= v17.m128_f32[0] )
      v42 = v17;
    else
      v42 = v39;
    v43 = (int)v42.m128_f32[0];
    if ( (int)v42.m128_f32[0] != 0x80000000 && (float)v43 != v42.m128_f32[0] )
      v42.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v42, v42)) & 1) + v43);
    result->ScissorLeft = (int)v42.m128_f32[0];
    if ( v40.m128_f32[0] >= v20.m128_f32[0] )
      v44 = v20;
    else
      v44 = v40;
    v45 = (int)v44.m128_f32[0];
    if ( (int)v44.m128_f32[0] != 0x80000000 && (float)v45 != v44.m128_f32[0] )
      v44.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v44, v44)) & 1) + v45);
    v39.m128_f32[0] = v39.m128_f32[0] - v17.m128_f32[0];
    v46 = _mm_and_ps(v39, (__m128)(unsigned int)_xmm);
    result->ScissorTop = (int)v44.m128_f32[0];
    v47 = (int)v46.m128_f32[0];
    if ( (int)v46.m128_f32[0] != 0x80000000 && (float)v47 != v46.m128_f32[0] )
      v46.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v46, v46)) & 1) + v47);
    v40.m128_f32[0] = v40.m128_f32[0] - v20.m128_f32[0];
    v48 = _mm_and_ps(v40, (__m128)(unsigned int)_xmm);
    result->ScissorWidth = (int)v46.m128_f32[0];
    v49 = (int)v48.m128_f32[0];
    if ( (int)v48.m128_f32[0] != 0x80000000 && (float)v49 != v48.m128_f32[0] )
      v48.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v48, v48)) & 1) + v49);
    result->ScissorHeight = (int)v48.m128_f32[0];
  }
  result->BufferWidth = vp->BufferWidth;
  result->BufferHeight = vp->BufferHeight;
  return result;
}

// File Line: 129
// RVA: 0x9EF3E0
void __fastcall Scaleform::Render::MatrixState::recalculateUVPOC(Scaleform::Render::MatrixState *this)
{
  int x1; // r9d
  int v3; // r12d
  int x2; // ecx
  Scaleform::Render::Matrix4x4<float> *p_ViewRectCompensated3D; // rbx
  int y1; // ebx
  int y2; // edi
  int v8; // r14d
  int v9; // r15d
  int v10; // esi
  int v11; // ebp
  int v12; // ecx
  int v13; // r12d
  __m128i v14; // xmm0
  int v15; // eax
  Scaleform::Render::Matrix4x4<float> *updated; // rax
  __m128 v17; // xmm3
  __m128 v18; // xmm5
  __m128 v19; // xmm8
  __m128 v20; // xmm9
  __m128 v21; // xmm7
  __m128 v22; // xmm6
  __m128 v23; // xmm12
  __m128 v24; // xmm6
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm10
  __m128 v28; // xmm5
  __m128 v29; // xmm11
  __m128 v30; // xmm8
  __m128i v31; // xmm7
  __m128i v32; // xmm9
  __m128i v33; // xmm6
  __m128i v34; // xmm3
  Scaleform::Render::Matrix4x4<float> m1; // [rsp+20h] [rbp-118h] BYREF
  Scaleform::Render::Matrix4x4<float> Dst; // [rsp+60h] [rbp-D8h] BYREF

  if ( this->UVPOChanged )
  {
    x1 = this->ViewRect.x1;
    v3 = this->ViewRectOriginal.x1;
    if ( x1 == v3
      && this->ViewRect.x2 == this->ViewRectOriginal.x2
      && this->ViewRect.y1 == this->ViewRectOriginal.y1
      && this->ViewRect.y2 == this->ViewRectOriginal.y2
      || (x2 = this->ViewRectOriginal.x2, x2 == v3) && this->ViewRectOriginal.y2 == this->ViewRectOriginal.y1 )
    {
      p_ViewRectCompensated3D = &this->ViewRectCompensated3D;
      this->ViewRectCompensated3D = Scaleform::Render::Matrix4x4<float>::Identity;
    }
    else
    {
      y1 = this->ViewRectOriginal.y1;
      y2 = this->ViewRectOriginal.y2;
      v8 = this->ViewRect.y1;
      v9 = this->ViewRect.y2;
      v10 = (x1 + this->ViewRect.x2) / 2 - (x2 + v3) / 2;
      v11 = (v9 + v8) / 2 - (y2 + y1) / 2;
      memset(&Dst, 0, sizeof(Dst));
      v12 = this->ViewRectOriginal.x2 - v3;
      v13 = this->ViewRect.x1;
      v14 = _mm_cvtsi32_si128(this->ViewRect.x2 - v13);
      Dst.M[3][3] = 1.0;
      Dst.M[2][2] = 1.0;
      Dst.M[0][0] = (float)v12 / _mm_cvtepi32_ps(v14).m128_f32[0];
      Dst.M[1][1] = (float)(y2 - y1) / (float)(v9 - v8);
      memset(&m1, 0, sizeof(m1));
      v15 = this->ViewRect.x2 - v13;
      m1.M[0][0] = 1.0;
      m1.M[1][1] = 1.0;
      *(_QWORD *)&m1.M[2][2] = 1065353216i64;
      m1.M[3][3] = 1.0;
      LODWORD(m1.M[0][3]) = COERCE_UNSIGNED_INT((float)((float)v10 * 2.0) / (float)v15) ^ _xmm[0];
      p_ViewRectCompensated3D = &this->ViewRectCompensated3D;
      m1.M[1][3] = (float)((float)v11 * 2.0) / (float)(v9 - v8);
      Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&this->ViewRectCompensated3D, &m1, &Dst);
    }
    updated = Scaleform::Render::MatrixState::updateStereoProjection(this, 1.0);
    v17 = *(__m128 *)&this->User3D.M[0][0];
    v18 = *(__m128 *)&this->User3D.M[1][0];
    v19 = *(__m128 *)&p_ViewRectCompensated3D->M[2][0];
    v20 = *(__m128 *)&p_ViewRectCompensated3D->M[3][0];
    v21 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), *(__m128 *)&p_ViewRectCompensated3D->M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), *(__m128 *)&p_ViewRectCompensated3D->M[0][0])),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v19)),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 255), v20));
    v22 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), *(__m128 *)&p_ViewRectCompensated3D->M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), *(__m128 *)&p_ViewRectCompensated3D->M[0][0])),
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v19)),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), v20));
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&Dst, &this->Orient3D, updated);
    v23 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), *(__m128 *)&Dst.M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), *(__m128 *)&Dst.M[0][0])),
              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), *(__m128 *)&Dst.M[2][0])),
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 255), *(__m128 *)&Dst.M[3][0]));
    v24 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), *(__m128 *)&Dst.M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), *(__m128 *)&Dst.M[0][0])),
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), *(__m128 *)&Dst.M[2][0])),
            _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), *(__m128 *)&Dst.M[3][0]));
    v25 = *(__m128 *)&this->View3D.M[0][0];
    v26 = *(__m128 *)&this->View3D.M[1][0];
    v27 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), *(__m128 *)&Dst.M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), *(__m128 *)&Dst.M[0][0])),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), *(__m128 *)&Dst.M[2][0])),
            _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), *(__m128 *)&Dst.M[3][0]));
    v28 = *(__m128 *)&this->View3D.M[2][0];
    v29 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), *(__m128 *)&Dst.M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), *(__m128 *)&Dst.M[0][0])),
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), *(__m128 *)&Dst.M[2][0])),
            _mm_mul_ps(_mm_shuffle_ps(v19, v19, 255), *(__m128 *)&Dst.M[3][0]));
    v30 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v;
    v31 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v26),
                         _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v25)),
                       _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v28)),
                     _mm_and_ps(v24, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    v32 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v26),
                         _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v25)),
                       _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v28)),
                     _mm_and_ps(v23, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v));
    LODWORD(this->UVPO.M[0][0]) = _mm_cvtsi128_si32(v32);
    v33 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v26),
                         _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v25)),
                       _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v28)),
                     _mm_and_ps(v29, v30));
    LODWORD(this->UVPO.M[0][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v32, 4));
    v34 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v26),
                         _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v25)),
                       _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v28)),
                     _mm_and_ps(v27, v30));
    LODWORD(this->UVPO.M[0][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v32, 8));
    LODWORD(this->UVPO.M[0][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v32, 12));
    LODWORD(this->UVPO.M[1][0]) = _mm_cvtsi128_si32(v31);
    LODWORD(this->UVPO.M[1][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v31, 4));
    LODWORD(this->UVPO.M[1][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v31, 8));
    LODWORD(this->UVPO.M[1][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v31, 12));
    LODWORD(this->UVPO.M[2][0]) = _mm_cvtsi128_si32(v33);
    LODWORD(this->UVPO.M[2][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v33, 4));
    LODWORD(this->UVPO.M[2][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v33, 8));
    LODWORD(this->UVPO.M[2][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v33, 12));
    LODWORD(this->UVPO.M[3][0]) = _mm_cvtsi128_si32(v34);
    LODWORD(this->UVPO.M[3][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v34, 4));
    LODWORD(this->UVPO.M[3][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v34, 8));
    LODWORD(this->UVPO.M[3][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v34, 12));
    this->UVPOChanged = 0;
  }
}

// File Line: 156
// RVA: 0x963B10
void __fastcall Scaleform::Render::MatrixState::Copy(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::MatrixState *outmat,
        Scaleform::Render::MatrixState *inmat)
{
  int y2; // r8d
  int y1; // ecx
  int x1; // eax
  int v8; // r8d
  int x2; // edx
  int v10; // ecx
  Scaleform::Render::StereoImplBase *pObject; // rcx
  Scaleform::Render::StereoImplBase *v12; // rcx
  Scaleform::Render::StereoImplBase *v13; // rdi
  Scaleform::RefCountImplCoreVtbl *vfptr; // rbx
  __int64 v15; // rax

  outmat->View2D = inmat->View2D;
  outmat->View3D = inmat->View3D;
  outmat->Proj3D = inmat->Proj3D;
  outmat->Proj3DLeft = inmat->Proj3DLeft;
  outmat->Proj3DRight = inmat->Proj3DRight;
  outmat->User = inmat->User;
  outmat->User3D = inmat->User3D;
  outmat->Orient2D = inmat->Orient2D;
  outmat->Orient3D = inmat->Orient3D;
  y2 = inmat->ViewRectOriginal.y2;
  y1 = inmat->ViewRectOriginal.y1;
  x1 = inmat->ViewRectOriginal.x1;
  outmat->ViewRectOriginal.x2 = inmat->ViewRectOriginal.x2;
  outmat->ViewRectOriginal.x1 = x1;
  outmat->ViewRectOriginal.y1 = y1;
  outmat->ViewRectOriginal.y2 = y2;
  v8 = inmat->ViewRect.y2;
  x2 = inmat->ViewRect.x2;
  v10 = inmat->ViewRect.y1;
  outmat->ViewRect.x1 = inmat->ViewRect.x1;
  outmat->ViewRect.x2 = x2;
  outmat->ViewRect.y1 = v10;
  outmat->ViewRect.y2 = v8;
  outmat->UserView = inmat->UserView;
  outmat->UVPO = inmat->UVPO;
  outmat->ViewRectCompensated3D = inmat->ViewRectCompensated3D;
  outmat->UVPOChanged = 1;
  outmat->OrientationSet = inmat->OrientationSet;
  if ( inmat->S3DImpl.pObject )
  {
    pObject = inmat->S3DImpl.pObject;
    if ( pObject )
      _InterlockedExchangeAdd(&pObject->RefCount, 1u);
    v12 = outmat->S3DImpl.pObject;
    if ( v12 && !_InterlockedDecrement(&v12->RefCount) )
      v12->vfptr->__vecDelDtor(v12, 1u);
    v13 = inmat->S3DImpl.pObject;
    outmat->S3DImpl.pObject = v13;
    vfptr = v13->vfptr;
    v15 = ((__int64 (__fastcall *)(Scaleform::Render::StereoImplBase *))inmat->S3DImpl.pObject->vfptr[2].__vecDelDtor)(inmat->S3DImpl.pObject);
    vfptr[1].__vecDelDtor(v13, v15);
  }
  outmat->S3DDisplay = inmat->S3DDisplay;
  outmat->pHAL = inmat->pHAL;
}

// File Line: 195
// RVA: 0x9648F0
void __fastcall Scaleform::Render::MatrixState::CopyFrom(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::MatrixState *state)
{
  ((void (__fastcall *)(Scaleform::Render::MatrixState *, Scaleform::Render::MatrixState *, Scaleform::Render::MatrixState *))this->vfptr[8].__vecDelDtor)(
    this,
    this,
    state);
}

// File Line: 200
// RVA: 0x965260
void __fastcall Scaleform::Render::MatrixState::CopyTo(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::MatrixState *state)
{
  ((void (__fastcall *)(Scaleform::Render::MatrixState *, Scaleform::Render::MatrixState *, Scaleform::Render::MatrixState *))this->vfptr[8].__vecDelDtor)(
    this,
    state,
    this);
}

// File Line: 205
// RVA: 0x9FAAA0
Scaleform::Render::Matrix4x4<float> *__fastcall Scaleform::Render::MatrixState::updateStereoProjection(
        Scaleform::Render::MatrixState *this,
        float factor)
{
  Scaleform::Render::StereoDisplay S3DDisplay; // edx
  Scaleform::Render::StereoImplBase *pObject; // rax
  Scaleform::Render::Matrix4x4<float> *p_Proj3DLeft; // rbx
  Scaleform::Render::Matrix4x4<float> *p_Proj3DRight; // rbx

  S3DDisplay = this->S3DDisplay;
  if ( S3DDisplay == StereoCenter )
    return &this->Proj3D;
  pObject = this->S3DImpl.pObject;
  if ( !pObject )
    return &this->Proj3D;
  if ( S3DDisplay == StereoLeft )
  {
    p_Proj3DLeft = &this->Proj3DLeft;
    ((void (__fastcall *)(Scaleform::Render::StereoImplBase *, Scaleform::Render::Matrix4x4<float> *, Scaleform::RefCountImplCoreVtbl *, Scaleform::Render::Matrix4x4<float> *, _QWORD, _DWORD))pObject->vfptr[3].__vecDelDtor)(
      pObject,
      &this->Proj3D,
      pObject->vfptr,
      &this->Proj3DLeft,
      0i64,
      LODWORD(factor));
    return p_Proj3DLeft;
  }
  if ( S3DDisplay != StereoRight )
    return &this->Proj3D;
  p_Proj3DRight = &this->Proj3DRight;
  ((void (__fastcall *)(Scaleform::Render::StereoImplBase *, Scaleform::Render::Matrix4x4<float> *, Scaleform::RefCountImplCoreVtbl *, _QWORD, Scaleform::Render::Matrix4x4<float> *, _DWORD))pObject->vfptr[3].__vecDelDtor)(
    pObject,
    &this->Proj3D,
    pObject->vfptr,
    0i64,
    &this->Proj3DRight,
    LODWORD(factor));
  return p_Proj3DRight;
}

// File Line: 257
// RVA: 0x98BC20
void __fastcall Scaleform::Render::StereoImplBase::GetStereoProj(
        Scaleform::Render::StereoImplBase *this,
        Scaleform::Render::Matrix4x4<float> *original,
        float screenDist,
        Scaleform::Render::Matrix4x4<float> *left,
        Scaleform::Render::Matrix4x4<float> *right,
        float factor)
{
  float v9; // xmm11_4
  float v10; // xmm11_4
  float v11; // xmm10_4
  __m128 v12; // xmm15
  __m128 v13; // xmm14
  __m128 v14; // xmm13
  __m128 v15; // xmm4
  __m128 v16; // xmm3
  __m128 v17; // xmm8
  __m128 v18; // xmm6
  __m128 v19; // xmm7
  __m128i v20; // xmm9
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128i v23; // xmm8
  __m128i v24; // xmm5
  __m128i v25; // xmm2
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm8
  __m128 v29; // xmm6
  __m128 v30; // xmm7
  __m128i v31; // xmm9
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128i v34; // xmm8
  __m128i v35; // xmm2
  __m128i v36; // xmm5
  __m128 v37; // [rsp+60h] [rbp-98h] BYREF
  _BYTE v38[24]; // [rsp+70h] [rbp-88h]
  __m128 v39; // [rsp+88h] [rbp-70h]
  Scaleform::Render::Matrix4x4<float> v40[3]; // [rsp+98h] [rbp-60h] BYREF
  _DWORD *v41; // [rsp+1E8h] [rbp+F0h]

  memset(&v40[0].M[0][2], 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  v40[0].M[0][0] = 1.0;
  v40[0].M[1][1] = 1.0;
  v40[0].M[2][2] = 1.0;
  v40[0].M[3][3] = 1.0;
  memset(&v40[1], 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  v40[1].M[0][0] = 1.0;
  v9 = *(float *)&right * this->S3DParams.Distortion;
  v40[1].M[1][1] = 1.0;
  v40[1].M[2][2] = 1.0;
  v40[1].M[3][3] = 1.0;
  v10 = (float)(v9 * this->S3DParams.EyeSeparationCm) / this->S3DParams.DisplayWidthCm;
  LODWORD(v11) = COERCE_UNSIGNED_INT((float)((float)(v10 * screenDist) * original->M[3][2]) / original->M[0][0]) ^ _xmm[0];
  if ( v11 < 0.0 )
    v11 = (float)((float)(v10 * screenDist) * original->M[3][2]) / original->M[0][0];
  v12 = *(__m128 *)&v40[0].M[3][0];
  v13 = *(__m128 *)&v40[0].M[2][0];
  v14 = *(__m128 *)&v40[0].M[1][0];
  if ( left )
  {
    v40[1].M[0][3] = v11;
    LODWORD(v40[0].M[0][3]) = LODWORD(v10) ^ _xmm[0];
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix((Scaleform::Render::Matrix4x4<float> *)&v37, original, &v40[1]);
    v15 = v37;
    v16 = *(__m128 *)v38;
    v17 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), *(__m128 *)v38);
    v18 = *(__m128 *)&v38[8];
    v19 = v39;
    v20 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(*(__m128 *)&v40[0].M[0][0], *(__m128 *)&v40[0].M[0][0], 85),
                           *(__m128 *)v38),
                         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[0].M[0][0], *(__m128 *)&v40[0].M[0][0], 0), v37)),
                       _mm_mul_ps(
                         _mm_shuffle_ps(*(__m128 *)&v40[0].M[0][0], *(__m128 *)&v40[0].M[0][0], 170),
                         *(__m128 *)&v38[8])),
                     _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[0].M[0][0], *(__m128 *)&v40[0].M[0][0], 255), v39));
    v21 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v37);
    v22 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), *(__m128 *)&v38[8]);
    LODWORD(left->M[0][0]) = _mm_cvtsi128_si32(v20);
    v23 = (__m128i)_mm_add_ps(_mm_add_ps(_mm_add_ps(v17, v21), v22), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v19));
    v24 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v16),
                         _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v15)),
                       _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v18)),
                     _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), v19));
    v25 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v16),
                         _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v15)),
                       _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v18)),
                     _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), v19));
    LODWORD(left->M[0][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v20, 4));
    LODWORD(left->M[0][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v20, 8));
    LODWORD(left->M[0][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v20, 12));
    LODWORD(left->M[1][0]) = _mm_cvtsi128_si32(v23);
    LODWORD(left->M[1][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v23, 4));
    LODWORD(left->M[1][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v23, 8));
    LODWORD(left->M[1][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v23, 12));
    LODWORD(left->M[2][0]) = _mm_cvtsi128_si32(v24);
    LODWORD(left->M[2][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v24, 4));
    LODWORD(left->M[2][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v24, 8));
    LODWORD(left->M[2][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v24, 12));
    LODWORD(left->M[3][0]) = _mm_cvtsi128_si32(v25);
    LODWORD(left->M[3][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v25, 4));
    LODWORD(left->M[3][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v25, 8));
    LODWORD(left->M[3][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v25, 12));
  }
  if ( v41 )
  {
    v40[0].M[0][3] = v10;
    LODWORD(v40[1].M[0][3]) = LODWORD(v11) ^ _xmm[0];
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix((Scaleform::Render::Matrix4x4<float> *)&v37, original, &v40[1]);
    v26 = v37;
    v27 = *(__m128 *)v38;
    v28 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), *(__m128 *)v38);
    v29 = *(__m128 *)&v38[8];
    v30 = v39;
    v31 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(*(__m128 *)&v40[0].M[0][0], *(__m128 *)&v40[0].M[0][0], 85),
                           *(__m128 *)v38),
                         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[0].M[0][0], *(__m128 *)&v40[0].M[0][0], 0), v37)),
                       _mm_mul_ps(
                         _mm_shuffle_ps(*(__m128 *)&v40[0].M[0][0], *(__m128 *)&v40[0].M[0][0], 170),
                         *(__m128 *)&v38[8])),
                     _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[0].M[0][0], *(__m128 *)&v40[0].M[0][0], 255), v39));
    v32 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v37);
    v33 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), *(__m128 *)&v38[8]);
    *v41 = _mm_cvtsi128_si32(v31);
    v41[1] = _mm_cvtsi128_si32(_mm_srli_si128(v31, 4));
    v34 = (__m128i)_mm_add_ps(_mm_add_ps(_mm_add_ps(v28, v32), v33), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v30));
    v35 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v27),
                         _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v26)),
                       _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v29)),
                     _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), v30));
    v36 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v27),
                         _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v26)),
                       _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v29)),
                     _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), v30));
    v41[2] = _mm_cvtsi128_si32(_mm_srli_si128(v31, 8));
    v41[3] = _mm_cvtsi128_si32(_mm_srli_si128(v31, 12));
    v41[4] = _mm_cvtsi128_si32(v34);
    v41[5] = _mm_cvtsi128_si32(_mm_srli_si128(v34, 4));
    v41[6] = _mm_cvtsi128_si32(_mm_srli_si128(v34, 8));
    v41[7] = _mm_cvtsi128_si32(_mm_srli_si128(v34, 12));
    v41[8] = _mm_cvtsi128_si32(v36);
    v41[9] = _mm_cvtsi128_si32(_mm_srli_si128(v36, 4));
    v41[10] = _mm_cvtsi128_si32(_mm_srli_si128(v36, 8));
    v41[11] = _mm_cvtsi128_si32(_mm_srli_si128(v36, 12));
    v41[12] = _mm_cvtsi128_si32(v35);
    v41[13] = _mm_cvtsi128_si32(_mm_srli_si128(v35, 4));
    v41[14] = _mm_cvtsi128_si32(_mm_srli_si128(v35, 8));
    v41[15] = _mm_cvtsi128_si32(_mm_srli_si128(v35, 12));
  }
} = _mm_cvtsi128_si32(_mm_srli_si128(v35, 4));
    v41[14] = _mm_cvtsi128_si32(_mm_srli_si1

// File Line: 288
// RVA: 0x984D50
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::MatrixState::GetFullViewportMatrix(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::Size<int> *rtSize)
{
  return &this->FullViewportMVP;
}

// File Line: 294
// RVA: 0x98E6E0
Scaleform::Render::Matrix4x4<float> *__fastcall Scaleform::Render::MatrixState::GetUVP(
        Scaleform::Render::MatrixState *this)
{
  ((void (__fastcall *)(Scaleform::Render::MatrixState *))this->vfptr[9].__vecDelDtor)(this);
  return &this->UVPO;
}

// File Line: 334
// RVA: 0x93D6A0
void __fastcall Scaleform::Render::HAL::HAL(
        Scaleform::Render::HAL *this,
        Scaleform::Render::ThreadCommandQueue *commandQueue)
{
  unsigned int *p_HALState; // rdx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::HAL,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::HAL::`vftable;
  this->FullSceneBlendTarget.pObject = 0i64;
  this->HALState = 0;
  this->CurrentPass = Display_All;
  p_HALState = &this->HALState;
  if ( this == (Scaleform::Render::HAL *)-32i64 )
    p_HALState = 0i64;
  this->NotifyList.Root.pPrev = (Scaleform::Render::HALNotify *)p_HALState;
  this->NotifyList.Root.pNext = (Scaleform::Render::HALNotify *)p_HALState;
  this->Matrices.pObject = 0i64;
  this->Profiler.vfptr = (Scaleform::Render::ProfileViewsVtbl *)&Scaleform::Render::ProfileViews::`vftable;
  this->Profiler.PMDefault.vfptr = (Scaleform::Render::ProfileModifierVtbl *)&Scaleform::Render::ProfileModifier::`vftable;
  this->Profiler.PMDefault.FillFlags = 0;
  *(_QWORD *)&this->AccumulatedStats.Primitives = 0i64;
  *(_QWORD *)&this->AccumulatedStats.Triangles = 0i64;
  *(_QWORD *)&this->AccumulatedStats.RTChanges = 0i64;
  *(_QWORD *)&this->VMCFlags = 0i64;
  this->RenderThreadID = 0i64;
  this->pHeap = 0i64;
  this->pRTCommandQueue = commandQueue;
  this->Queue.QueueSize = 0;
  this->Queue.pQueue = 0i64;
  *(_QWORD *)&this->Queue.QueueHead = 0i64;
  this->Queue.HeadReserved = 0;
  this->pRenderBufferManager.pObject = 0i64;
  this->QueueProcessor.pHAL = this;
  this->QueueProcessor.Caches.LockFlags = 0;
  this->QueueProcessor.Caches.pCaches[0] = 0i64;
  this->QueueProcessor.Caches.pCaches[1] = 0i64;
  this->QueueProcessor.Queue = &this->Queue;
  *(_QWORD *)&this->QueueProcessor.QueueMode = 0i64;
  this->QueueProcessor.QueueEmitFilter = QPF_All;
  this->QueueProcessor.CurrentItem.pQueue = 0i64;
  this->QueueProcessor.CurrentItem.QueuePos = 0;
  this->QueueProcessor.PrepareItemBuffer.pItem = 0i64;
  this->QueueProcessor.EmitItemBuffer.pItem = 0i64;
  this->ViewMatrix3DStack.Data.Data = 0i64;
  this->ViewMatrix3DStack.Data.Size = 0i64;
  this->ViewMatrix3DStack.Data.Policy.Capacity = 0i64;
  this->ProjectionMatrix3DStack.Data.Data = 0i64;
  this->ProjectionMatrix3DStack.Data.Size = 0i64;
  this->ProjectionMatrix3DStack.Data.Policy.Capacity = 0i64;
  this->CurrentBlendState.Mode = Blend_None;
  *(_WORD *)&this->CurrentBlendState.SourceAc = 0;
  this->CurrentBlendState.BlendEnable = 0;
  *(_QWORD *)&this->CurrentDepthStencilState = 1i64;
  *(_DWORD *)&this->StencilChecked = 0;
  *(_QWORD *)&this->NextSceneRasterMode = 0i64;
  this->AppliedSceneRasterMode = RasterMode_Solid;
  this->BlendModeStack.Data.Data = 0i64;
  this->BlendModeStack.Data.Size = 0i64;
  this->BlendModeStack.Data.Policy.Capacity = 0i64;
  this->MaskStack.Data.Data = 0i64;
  this->MaskStack.Data.Size = 0i64;
  this->MaskStack.Data.Policy.Capacity = 0i64;
  this->MaskStackTop = 0;
  this->RenderTargetStack.Data.Data = 0i64;
  this->RenderTargetStack.Data.Size = 0i64;
  this->RenderTargetStack.Data.Policy.Capacity = 0i64;
  this->FilterStack.Data.Data = 0i64;
  this->FilterStack.Data.Size = 0i64;
  this->FilterStack.Data.Policy.Capacity = 0i64;
  *(_QWORD *)&this->CacheableIndex = -1i64;
  this->CacheablePrepStart = -1;
  this->BeginDisplayDataList.FirstPage = 0i64;
  this->BeginDisplayDataList.LastPage = 0i64;
  this->BeginDisplayDataList.NumElementsInPage = 127;
  this->BeginDisplayDataList.FirstEmptySlot = 0i64;
  this->BeginDisplayDataList.pHeapOrPtr = &this->BeginDisplayDataList;
  this->UserDataStack.Data.Data = 0i64;
  this->UserDataStack.Data.Size = 0i64;
  this->UserDataStack.Data.Policy.Capacity = 0i64;
  *(_QWORD *)&this->VP.BufferWidth = 0i64;
  *(_QWORD *)&this->VP.Left = 0i64;
  this->VP.Height = 1;
  this->VP.Width = 1;
  *(_QWORD *)&this->VP.ScissorWidth = 0i64;
  *(_QWORD *)&this->VP.ScissorLeft = 0i64;
  *(_QWORD *)&this->VP.Flags = 0i64;
  *(_QWORD *)&this->ViewRect.y1 = 0i64;
  this->ViewRect.y2 = 0;
  this->pHeap = Scaleform::Memory::pGlobalHeap;
}

// File Line: 341
// RVA: 0x9E82F0
char __fastcall Scaleform::Render::HAL::initHAL(Scaleform::Render::HAL *this, Scaleform::Render::HALInitParams *params)
{
  __int64 v4; // rbx
  Scaleform::Render::MatrixState *pObject; // rsi
  Scaleform::Render::StereoImplBase *v6; // rcx
  void *RenderThreadId; // rax

  ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[2].__vecDelDtor)(this);
  v4 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
         Scaleform::Memory::pGlobalHeap,
         40i64);
  if ( v4 )
  {
    *(_QWORD *)v4 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v4 + 8) = 1;
    *(_QWORD *)v4 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v4 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    *(_QWORD *)v4 = &Scaleform::RefCountBase<Scaleform::Render::StereoImplBase,2>::`vftable;
    *(_QWORD *)v4 = &Scaleform::Render::StereoImplBase::`vftable;
    *(_DWORD *)(v4 + 16) = 0;
    *(_DWORD *)(v4 + 20) = 1061158912;
    *(_DWORD *)(v4 + 24) = 1112539136;
    *(_DWORD *)(v4 + 28) = 1058013184;
    *(_DWORD *)(v4 + 32) = 1087163597;
  }
  else
  {
    v4 = 0i64;
  }
  pObject = this->Matrices.pObject;
  v6 = pObject->S3DImpl.pObject;
  if ( v6 && !_InterlockedDecrement(&v6->RefCount) )
    v6->vfptr->__vecDelDtor(v6, 1u);
  pObject->S3DImpl.pObject = (Scaleform::Render::StereoImplBase *)v4;
  this->VMCFlags = params->ConfigFlags;
  RenderThreadId = params->RenderThreadId;
  this->RenderThreadID = RenderThreadId;
  if ( !RenderThreadId )
    this->RenderThreadID = UFG::qGetCurrentThreadID();
  return Scaleform::Render::RenderQueue::Initialize(&this->Queue, params->RenderQueueSize);
}

// File Line: 364
// RVA: 0x9E8490
void __fastcall Scaleform::Render::HAL::initMatrices(Scaleform::Render::HAL *this)
{
  Scaleform::Render::MatrixState *v2; // rax
  Scaleform::Render::MatrixState *v3; // rax
  Scaleform::Render::MatrixState *v4; // rdi
  Scaleform::Render::MatrixState *pObject; // rcx
  int v6; // [rsp+48h] [rbp+10h] BYREF
  Scaleform::Render::MatrixState *v7; // [rsp+50h] [rbp+18h]

  v6 = 65;
  v2 = (Scaleform::Render::MatrixState *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::HAL *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           704i64,
                                           &v6,
                                           -2i64);
  v7 = v2;
  if ( v2 )
  {
    Scaleform::Render::MatrixState::MatrixState(v2, this);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  pObject = this->Matrices.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->Matrices.pObject = v4;
}

// File Line: 370
// RVA: 0x9F2390
char __fastcall Scaleform::Render::HAL::shutdownHAL(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HALNotify *i; // rcx
  unsigned int *v3; // rax
  Scaleform::Render::HALNotify *pNext; // rbx

  if ( (this->HALState & 1) != 0 )
  {
    for ( i = this->NotifyList.Root.pNext; ; i = pNext )
    {
      v3 = this == (Scaleform::Render::HAL *)-32i64 ? 0i64 : &this->HALState;
      if ( i == (Scaleform::Render::HALNotify *)v3 )
        break;
      pNext = i->pNext;
      i->vfptr->OnHALEvent(i, HAL_Shutdown);
    }
    if ( this->Queue.pQueue )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Queue.pQueue = 0i64;
    }
    this->HALState = 0;
  }
  return 1;
}

// File Line: 388
// RVA: 0x95A580
char __fastcall Scaleform::Render::HAL::BeginFrame(Scaleform::Render::HAL *this)
{
  void *v2; // rax
  unsigned int HALState; // eax
  __int64 v5; // rax
  Scaleform::Render::RenderQueueProcessor *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax

  v2 = this->vfptr[60].__vecDelDtor(this, 1i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v2 + 16i64))(v2, "Scaleform::Render::HAL::BeginFrame");
  HALState = this->HALState;
  if ( (HALState & 1) == 0 || (HALState & 0x2000) != 0 )
    return 0;
  this->HALState = HALState | 2;
  if ( ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[65].__vecDelDtor)(this) )
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[65].__vecDelDtor)(this);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 8i64))(v5);
  }
  v6 = (Scaleform::Render::RenderQueueProcessor *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[64].__vecDelDtor)(this);
  Scaleform::Render::RenderQueueProcessor::BeginFrame(v6);
  v7 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[62].__vecDelDtor)(this);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 24i64))(v7);
  v8 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[61].__vecDelDtor)(this);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 72i64))(v8);
  return 1;
}

// File Line: 409
// RVA: 0x9705D0
void __fastcall Scaleform::Render::HAL::EndFrame(Scaleform::Render::HAL *this)
{
  void *v2; // rdi
  __int64 v3; // rax
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rax

  v2 = this->vfptr[60].__vecDelDtor(this, 1i64);
  if ( (this->HALState & 3) == 3 )
  {
    if ( ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[65].__vecDelDtor)(this) )
    {
      v3 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[65].__vecDelDtor)(this);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 16i64))(v3);
    }
    v4 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[19].__vecDelDtor)(this);
    if ( v4 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 24i64))(v4);
    v5 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[62].__vecDelDtor)(this);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 32i64))(v5);
    v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[61].__vecDelDtor)(this);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 80i64))(v6);
    this->HALState &= ~2u;
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
}

// File Line: 438
// RVA: 0x96FEA0
void __fastcall Scaleform::Render::HALBeginDisplayItem::EmitToHAL(
        Scaleform::Render::HALBeginDisplayItem *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  qp->pHAL->vfptr[11].__vecDelDtor(qp->pHAL, (unsigned int)item->Data);
}

// File Line: 448
// RVA: 0x96FEB0
void __fastcall Scaleform::Render::HALEndDisplayItem::EmitToHAL(
        Scaleform::Render::HALEndDisplayItem *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  qp->pHAL->vfptr[12].__vecDelDtor(qp->pHAL, (unsigned int)__formal);
}

// File Line: 452
// RVA: 0x159C7F0
__int64 dynamic_initializer_for__Scaleform::Render::HALBeginDisplayItem::Instance__()
{
  Scaleform::Render::HALBeginDisplayItem::Instance.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::HALBeginDisplayItem::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::HALBeginDisplayItem::Instance__);
}

// File Line: 453
// RVA: 0x159C820
__int64 dynamic_initializer_for__Scaleform::Render::HALEndDisplayItem::Instance__()
{
  Scaleform::Render::HALEndDisplayItem::Instance.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::HALEndDisplayItem::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::HALEndDisplayItem::Instance__);
}

// File Line: 456
// RVA: 0x95A430
void __fastcall Scaleform::Render::HAL::BeginDisplay(
        Scaleform::Render::HAL *this,
        int *backgroundColor,
        Scaleform::Render::Viewport *vpin)
{
  int v3; // ebx
  int Left; // ebp
  int BufferHeight; // esi
  int BufferWidth; // edi
  int Height; // r12d
  int ScissorLeft; // r13d
  int Top; // r14d
  int Width; // r15d
  Scaleform::Render::FenceFrame *v11; // rax
  int ScissorWidth; // [rsp+20h] [rbp-98h]
  Scaleform::Render::Fence *v13; // [rsp+24h] [rbp-94h]
  __int64 v14[2]; // [rsp+30h] [rbp-88h] BYREF
  Scaleform::ListNode<Scaleform::Render::FenceFrame> v15; // [rsp+40h] [rbp-78h]
  int ScissorTop; // [rsp+D8h] [rbp+20h]

  if ( (this->HALState & 2) != 0 )
  {
    v3 = *backgroundColor;
    Left = vpin->Left;
    BufferHeight = vpin->BufferHeight;
    BufferWidth = vpin->BufferWidth;
    Height = vpin->Height;
    v13 = *(Scaleform::Render::Fence **)&vpin->ScissorHeight;
    ScissorLeft = vpin->ScissorLeft;
    ScissorTop = vpin->ScissorTop;
    Top = vpin->Top;
    ScissorWidth = vpin->ScissorWidth;
    Width = vpin->Width;
    v11 = Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2>>::allocate((Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> > *)&this->BeginDisplayDataList);
    v11->Scaleform::ListNode<Scaleform::Render::FenceFrame> = v15;
    LODWORD(v11->RSContext) = v3;
    HIDWORD(v11->RSContext) = BufferWidth;
    *(_DWORD *)&v11->WrappedAround = BufferHeight;
    *((_DWORD *)&v11->WrappedAround + 1) = Left;
    LODWORD(v11->Fences.Data.Data) = Top;
    HIDWORD(v11->Fences.Data.Data) = Width;
    LODWORD(v11->Fences.Data.Size) = Height;
    HIDWORD(v11->Fences.Data.Size) = ScissorLeft;
    LODWORD(v11->Fences.Data.Policy.Capacity) = ScissorTop;
    HIDWORD(v11->Fences.Data.Policy.Capacity) = ScissorWidth;
    v11->FrameEndFence.pObject = v13;
    if ( (this->HALState & 4) != 0 )
    {
      v14[1] = (__int64)v11;
      v14[0] = (__int64)&Scaleform::Render::HALBeginDisplayItem::Instance;
      this->vfptr[33].__vecDelDtor(this, (unsigned int)v14);
    }
    else
    {
      ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[11].__vecDelDtor)(this);
    }
  }
}

// File Line: 476
// RVA: 0x970580
void __fastcall Scaleform::Render::HAL::EndDisplay(Scaleform::Render::HAL *this)
{
  __int64 v2[3]; // [rsp+20h] [rbp-18h] BYREF

  if ( (this->HALState & 0x400) != 0 )
  {
    ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[8].__vecDelDtor)(this);
    ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[12].__vecDelDtor)(this);
  }
  else
  {
    v2[1] = 0i64;
    v2[0] = (__int64)&Scaleform::Render::HALEndDisplayItem::Instance;
    this->vfptr[33].__vecDelDtor(this, (unsigned int)v2);
  }
}

// File Line: 492
// RVA: 0x9CF260
void __fastcall Scaleform::Render::HAL::beginDisplay(
        Scaleform::Render::HAL *this,
        Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2> >::NodeType *data)
{
  void *v4; // rax
  unsigned int HALState; // eax
  unsigned int pNext; // ebx
  bool v7; // zf
  __int64 v8; // rax
  __int64 v9; // r8
  __int64 v10; // r9
  __int64 v11; // rax
  Scaleform::Render::RenderTarget *pObject; // rcx
  Scaleform::Render::RenderTarget *v13; // r14
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  float v15; // xmm1_4
  float v16; // xmm0_4
  Scaleform::RefCountImplCoreVtbl *v17; // rax
  __int64 v18; // [rsp+30h] [rbp-58h] BYREF
  float v19; // [rsp+38h] [rbp-50h]
  float v20; // [rsp+3Ch] [rbp-4Ch]
  char v21[48]; // [rsp+40h] [rbp-48h] BYREF
  unsigned int v22; // [rsp+90h] [rbp+8h] BYREF
  int v23; // [rsp+94h] [rbp+Ch]
  unsigned int v24; // [rsp+A0h] [rbp+18h]

  v4 = this->vfptr[60].__vecDelDtor(this, 4i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v4 + 16i64))(v4, "Scaleform::Render::HAL::beginDisplay");
  HALState = this->HALState;
  if ( (HALState & 2) != 0 )
  {
    this->HALState = HALState | 8;
    pNext = (unsigned int)data[2].pNext;
    data->pNext = this->BeginDisplayDataList.FirstEmptySlot;
    this->BeginDisplayDataList.FirstEmptySlot = data;
    v7 = (this->HALState & 4) == 0;
    v24 = pNext;
    if ( v7 )
    {
      ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[9].__vecDelDtor)(this);
      this->HALState |= 0x400u;
    }
    Scaleform::Render::HAL::applyBlendMode(
      this,
      (unsigned int)this->CurrentBlendState.Mode,
      this->CurrentBlendState.SourceAc,
      this->CurrentBlendState.ForceAc);
    ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[82].__vecDelDtor)(this);
    v8 = ((__int64 (__fastcall *)(Scaleform::Render::MatrixState *, char *, char *))this->Matrices.pObject->vfptr[5].__vecDelDtor)(
           this->Matrices.pObject,
           v21,
           (char *)&data[2].pNext + 4);
    this->VP.BufferWidth = *(_DWORD *)v8;
    this->VP.BufferHeight = *(_DWORD *)(v8 + 4);
    this->VP.Left = *(_DWORD *)(v8 + 8);
    this->VP.Top = *(_DWORD *)(v8 + 12);
    this->VP.Width = *(_DWORD *)(v8 + 16);
    this->VP.Height = *(_DWORD *)(v8 + 20);
    this->VP.ScissorLeft = *(_DWORD *)(v8 + 24);
    this->VP.ScissorTop = *(_DWORD *)(v8 + 28);
    this->VP.ScissorWidth = *(_DWORD *)(v8 + 32);
    this->VP.ScissorHeight = *(_DWORD *)(v8 + 36);
    this->VP.Flags = *(_DWORD *)(v8 + 40);
    if ( Scaleform::Render::Viewport::GetClippedRect<int>(&this->VP, &this->ViewRect, 0) )
      this->HALState |= 0x20u;
    else
      this->HALState &= ~0x20u;
    ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[17].__vecDelDtor)(this);
    if ( (this->HALState & 0x810) == 2048 )
    {
      LOBYTE(v9) = 1;
      v22 = this->ViewRect.x2 - this->ViewRect.x1;
      v23 = this->ViewRect.y2 - this->ViewRect.y1;
      v11 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, unsigned int *, __int64))this->vfptr[22].__vecDelDtor)(
              this,
              &v22,
              v9);
      pObject = this->FullSceneBlendTarget.pObject;
      v13 = (Scaleform::Render::RenderTarget *)v11;
      if ( pObject )
        ((void (__fastcall *)(Scaleform::Render::RenderTarget *))pObject->vfptr[2].__vecDelDtor)(pObject);
      this->FullSceneBlendTarget.pObject = v13;
      vfptr = this->vfptr;
      v15 = (float)(this->ViewRect.x2 - this->ViewRect.x1);
      v16 = (float)(this->ViewRect.y2 - this->ViewRect.y1);
      v18 = 0i64;
      v19 = v15;
      v20 = v16;
      v22 = 0;
      ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, Scaleform::Render::RenderTarget *, _QWORD, unsigned int *))vfptr[24].__vecDelDtor)(
        this,
        &v18,
        v13,
        0i64,
        &v22);
    }
    if ( HIBYTE(v24) )
    {
      if ( (HIDWORD(data[7].pNext) & 0x200) == 0 )
      {
        v19 = *((float *)&data[4].pNext + 1);
        LOBYTE(v10) = 1;
        v20 = *(float *)&data[5].pNext;
        v17 = this->vfptr;
        v22 = pNext;
        v18 = 0i64;
        ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, unsigned int *, __int64))v17[18].__vecDelDtor)(
          this,
          &v18,
          &v22,
          v10);
      }
    }
  }
}

// File Line: 538
// RVA: 0x9E1A50
void __fastcall Scaleform::Render::HAL::endDisplay(Scaleform::Render::HAL *this)
{
  void *v2; // r14
  unsigned __int64 Size; // rsi
  Scaleform::Render::HAL::RenderTargetEntry *Data; // r15
  __int64 v5; // rbx
  int v6; // edx
  int *v7; // rax
  __m128 v8; // xmm0
  float v9; // xmm3_4
  __m128 v10; // xmm3
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::Render::Matrix2x4<float> v12; // [rsp+18h] [rbp-69h] BYREF
  int v13[42]; // [rsp+38h] [rbp-49h] BYREF
  int v14[2]; // [rsp+E8h] [rbp+67h] BYREF
  void *v15; // [rsp+F0h] [rbp+6Fh]

  v2 = this->vfptr[60].__vecDelDtor(this, 4i64);
  v15 = v2;
  if ( (this->HALState & 8) != 0 )
  {
    ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[83].__vecDelDtor)(this);
    if ( (this->HALState & 0x800) != 0 )
    {
      if ( this->RenderTargetStack.Data.Size )
      {
        Size = this->RenderTargetStack.Data.Size;
        Data = this->RenderTargetStack.Data.Data;
        if ( Data[Size - 1].pRenderTarget.pObject == this->FullSceneBlendTarget.pObject )
        {
          this->vfptr[25].__vecDelDtor(this, 0);
          Scaleform::Render::HAL::applyBlendMode(this, 1i64, 1, 1);
          v5 = ((__int64 (__fastcall *)(Scaleform::Render::RenderTarget *))Data[Size - 1].pRenderTarget.pObject->vfptr[3].__vecDelDtor)(Data[Size - 1].pRenderTarget.pObject);
          v6 = *(_DWORD *)(v5 + 52);
          v14[0] = *(_DWORD *)(v5 + 48);
          v14[1] = v6;
          v7 = (int *)this->Matrices.pObject->vfptr[1].__vecDelDtor(this->Matrices.pObject, v14);
          v13[0] = *v7;
          v13[1] = v7[1];
          v13[2] = v7[2];
          v13[3] = v7[3];
          v13[4] = v7[4];
          v13[5] = v7[5];
          v13[6] = v7[6];
          v13[7] = v7[7];
          v12 = Scaleform::Render::Matrix2x4<float>::Identity;
          v8 = (__m128)COERCE_UNSIGNED_INT((float)(Data[Size - 1].pRenderTarget.pObject->ViewRect.x2
                                                 - Data[Size - 1].pRenderTarget.pObject->ViewRect.x1));
          v9 = (float)(Data[Size - 1].pRenderTarget.pObject->ViewRect.y2
                     - Data[Size - 1].pRenderTarget.pObject->ViewRect.y1)
             / (float)*(int *)(v5 + 52);
          v8.m128_f32[0] = v8.m128_f32[0] / (float)*(int *)(v5 + 48);
          v12.M[0][0] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][0] * v8.m128_f32[0];
          v12.M[0][1] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][1] * v8.m128_f32[0];
          v12.M[0][2] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][2] * v8.m128_f32[0];
          v12.M[0][3] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][3] * v8.m128_f32[0];
          v12.M[1][0] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][0] * v9;
          v12.M[1][1] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][1] * v9;
          v12.M[1][2] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][2] * v9;
          v12.M[1][3] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][3] * v9;
          *(double *)v8.m128_u64 = ((double (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[71].__vecDelDtor)(this);
          v10 = _mm_xor_ps(v8, *(__m128 *)_xmm);
          *(__m128 *)&v12.M[1][0] = _mm_mul_ps(*(__m128 *)&v12.M[1][0], _mm_shuffle_ps(v10, v10, 0));
          vfptr = this->vfptr;
          v12.M[0][2] = 0.0;
          ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, int *, Scaleform::Render::Matrix2x4<float> *, _QWORD, _QWORD, _QWORD))vfptr[58].__vecDelDtor)(
            this,
            v5,
            v13,
            &v12,
            *(_QWORD *)&v12.M[0][2],
            *(_QWORD *)&v12.M[1][0],
            *(_QWORD *)&v12.M[1][2]);
          Data[Size - 1].pRenderTarget.pObject->vfptr[5].__vecDelDtor(Data[Size - 1].pRenderTarget.pObject, 0);
        }
      }
    }
    if ( (this->HALState & 0x400) != 0 )
    {
      ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[10].__vecDelDtor)(this);
      this->HALState &= ~0x400u;
    }
    this->HALState &= ~8u;
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
}tate &= ~8u;
  }


// File Line: 577
// RVA: 0x95BD00
void __fastcall Scaleform::Render::HAL::CalcHWViewMatrix(
        Scaleform::Render::HAL *this,
        __int16 vpFlags,
        Scaleform::Render::Matrix2x4<float> *pmatrix,
        Scaleform::Render::Rect<int> *viewRect,
        int dx,
        int dy)
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm0_4

  v6 = 0.0;
  v7 = 0.0;
  v8 = (float)(viewRect->x2 - viewRect->x1);
  v9 = (float)(viewRect->y2 - viewRect->y1);
  if ( (vpFlags & 0x100) != 0 )
  {
    v7 = viewRect->x2 - viewRect->x1 <= 0 ? 0.0 : 1.0 / v8;
    if ( viewRect->y2 - viewRect->y1 > 0 )
      v6 = 1.0 / v9;
  }
  *(_QWORD *)&pmatrix->M[0][0] = 1065353216i64;
  *(_QWORD *)&pmatrix->M[1][1] = 1065353216i64;
  *(_QWORD *)&pmatrix->M[0][2] = 0i64;
  pmatrix->M[1][0] = 0.0;
  pmatrix->M[1][3] = 0.0;
  if ( (vpFlags & 1) != 0 )
  {
    pmatrix->M[1][1] = 2.0 / v9;
    pmatrix->M[0][0] = 2.0 / v8;
    pmatrix->M[0][3] = (float)(-1.0 - (float)((float)dx * (float)(2.0 / v8))) - v7;
    pmatrix->M[1][3] = (float)(-1.0 - (float)((float)dy * (float)(2.0 / v9))) - v6;
  }
  else
  {
    pmatrix->M[0][0] = 2.0 / v8;
    pmatrix->M[1][1] = -2.0 / v9;
    pmatrix->M[0][3] = (float)(-1.0 - (float)((float)dx * (float)(2.0 / v8))) - v7;
    pmatrix->M[1][3] = (float)(1.0 - (float)((float)dy * (float)(-2.0 / v9))) + v6;
  }
}

// File Line: 608
// RVA: 0x97AC40
void __fastcall Scaleform::Render::HAL::Flush(Scaleform::Render::HAL *this)
{
  Scaleform::Render::RenderQueueProcessor *v1; // rbx

  v1 = (Scaleform::Render::RenderQueueProcessor *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[64].__vecDelDtor)(this);
  Scaleform::Render::RenderQueueProcessor::ProcessQueue(v1, QPM_All);
  v1->PrepareItemBuffer.pItem = 0i64;
  v1->EmitItemBuffer.pItem = 0i64;
}

// File Line: 613
// RVA: 0x95AB20
char __fastcall Scaleform::Render::HAL::BeginScene(Scaleform::Render::HAL *this)
{
  void *v2; // rax
  __int64 v4; // rax
  __int64 v5; // rdx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::Render::HAL::RasterModeType NextSceneRasterMode; // edi

  v2 = this->vfptr[60].__vecDelDtor(this, 2i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v2 + 16i64))(v2, "Scaleform::Render::HAL::BeginScene");
  if ( (this->HALState & 2) == 0 )
    return 0;
  if ( ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[61].__vecDelDtor)(this) )
  {
    v4 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[61].__vecDelDtor)(this);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 88i64))(v4);
  }
  this->CurrentBlendState.Mode = Blend_Count;
  this->CurrentBlendState.BlendEnable = 0;
  Scaleform::Render::HAL::applyBlendMode(this, Blend_None, 0, 0);
  LOBYTE(v5) = 1;
  this->vfptr[41].__vecDelDtor(this, v5);
  vfptr = this->vfptr;
  this->CurrentDepthStencilState = DepthStencil_Invalid;
  this->CurrentStencilRef = -1;
  vfptr[78].__vecDelDtor(this, 1u);
  NextSceneRasterMode = this->NextSceneRasterMode;
  this->CurrentSceneRasterMode = NextSceneRasterMode;
  this->AppliedSceneRasterMode = RasterMode_Count;
  if ( NextSceneRasterMode != RasterMode_Count )
  {
    this->vfptr[84].__vecDelDtor(this, NextSceneRasterMode);
    this->AppliedSceneRasterMode = NextSceneRasterMode;
  }
  this->HALState |= 4u;
  return 1;
}

// File Line: 643
// RVA: 0x970C20
__int64 __fastcall Scaleform::Render::HAL::EndScene(Scaleform::Render::HAL *this)
{
  void *v2; // rdi
  unsigned __int8 v3; // bl
  __int64 v4; // rax

  v2 = this->vfptr[60].__vecDelDtor(this, 2i64);
  if ( (this->HALState & 6) == 6 )
  {
    ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[8].__vecDelDtor)(this);
    if ( ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[61].__vecDelDtor)(this) )
    {
      v4 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[61].__vecDelDtor)(this);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 96i64))(v4);
    }
    this->HALState &= ~4u;
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
  return v3;
}

// File Line: 660
// RVA: 0x982CF0
Scaleform::Render::RenderTarget *__fastcall Scaleform::Render::HAL::GetDefaultRenderTarget(
        Scaleform::Render::HAL *this)
{
  if ( this->RenderTargetStack.Data.Size )
    return this->RenderTargetStack.Data.Data->pRenderTarget.pObject;
  else
    return 0i64;
}

// File Line: 667
// RVA: 0x9DFF00
void __fastcall Scaleform::Render::HAL::destroyRenderBuffers(Scaleform::Render::HAL *this)
{
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    &this->RenderTargetStack.Data,
    &this->RenderTargetStack,
    0i64);
}

// File Line: 672
// RVA: 0x9692E0
void __fastcall Scaleform::Render::HAL::CreatePrimitiveFill(
        Scaleform::Render::HAL *this,
        Scaleform::Render::PrimitiveFillData *data)
{
  Scaleform::Render::PrimitiveFill *v3; // rax

  v3 = (Scaleform::Render::PrimitiveFill *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                             this->pHeap,
                                             64i64);
  if ( v3 )
    Scaleform::Render::PrimitiveFill::PrimitiveFill(v3, data, 0i64);
}

// File Line: 714
// RVA: 0x96F110
void __fastcall Scaleform::Render::HAL::DrawBundleEntries(
        Scaleform::Render::HAL *this,
        Scaleform::Render::BundleIterator *ibundles,
        Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::Render::DisplayPass CurrentPass; // eax
  Scaleform::Render::BundleEntry *pNextPattern; // rax
  Scaleform::Render::BundleEntry *pFirst; // [rsp+20h] [rbp-18h] BYREF
  Scaleform::Render::BundleEntry *pLast; // [rsp+28h] [rbp-10h]

  if ( this->CurrentPass == Display_All
    && ((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[29].__vecDelDtor)(this) )
  {
    this->vfptr[30].__vecDelDtor(this, 1u);
    pFirst = ibundles->pFirst;
    pLast = ibundles->pLast;
    ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::BundleEntry **, Scaleform::Render::Renderer2DImpl *))this->vfptr[32].__vecDelDtor)(
      this,
      &pFirst,
      r2d);
    this->vfptr[30].__vecDelDtor(this, 2u);
    pFirst = ibundles->pFirst;
    pLast = ibundles->pLast;
    ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::BundleEntry **, Scaleform::Render::Renderer2DImpl *))this->vfptr[32].__vecDelDtor)(
      this,
      &pFirst,
      r2d);
    this->vfptr[30].__vecDelDtor(this, 3u);
  }
  else
  {
    CurrentPass = this->CurrentPass;
    if ( CurrentPass == Display_Prepass )
    {
      *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[64].__vecDelDtor)(this) + 48) = 1;
      *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[64].__vecDelDtor)(this) + 44) = 1;
    }
    else if ( (unsigned int)(CurrentPass - 2) <= 1 )
    {
      *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[64].__vecDelDtor)(this) + 48) = 0;
      *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[64].__vecDelDtor)(this) + 44) = 0;
    }
    pNextPattern = ibundles->pFirst;
    if ( ibundles->pFirst )
    {
      while ( 1 )
      {
        pNextPattern->Key.pImpl->vfptr->DrawBundleEntry(
          pNextPattern->Key.pImpl,
          pNextPattern->Key.Data,
          pNextPattern,
          r2d);
        if ( ibundles->pFirst == ibundles->pLast )
          break;
        pNextPattern = ibundles->pFirst->pNextPattern;
        ibundles->pFirst = pNextPattern;
        if ( !pNextPattern )
          return;
      }
      ibundles->pLast = 0i64;
      ibundles->pFirst = 0i64;
    }
  }
}

// File Line: 749
// RVA: 0x96EB50
void __fastcall Scaleform::Render::HAL::Draw(Scaleform::Render::HAL *this, Scaleform::Render::RenderQueueItem *item)
{
  Scaleform::Render::RenderQueueProcessor *v4; // rax
  __int64 QueueHead; // rdx
  unsigned int QueueTail; // ecx
  Scaleform::Render::RenderQueueProcessor *v7; // rsi
  bool v8; // zf
  Scaleform::Render::RenderQueueItem *v9; // rcx
  __int64 v10; // rdx
  unsigned int v11; // ecx
  unsigned int v12; // ecx

  if ( item->pImpl != &Scaleform::Render::HALBeginDisplayItem::Instance && (this->HALState & 8) == 0 )
    return;
  v4 = (Scaleform::Render::RenderQueueProcessor *)((__int64 (*)(void))this->vfptr[64].__vecDelDtor)();
  QueueHead = this->Queue.QueueHead;
  QueueTail = this->Queue.QueueTail;
  v7 = v4;
  if ( (unsigned int)QueueHead > QueueTail )
    v8 = this->Queue.QueueSize + QueueTail == (_DWORD)QueueHead + 1;
  else
    v8 = QueueTail - (_DWORD)QueueHead == 1;
  if ( v8 || (this->Queue.HeadReserved = 1, (v9 = &this->Queue.pQueue[QueueHead]) == 0i64) )
  {
    Scaleform::Render::RenderQueueProcessor::ProcessQueue(v4, QPM_One);
    v10 = this->Queue.QueueHead;
    v11 = this->Queue.QueueTail;
    if ( (unsigned int)v10 > v11 )
    {
      if ( this->Queue.QueueSize + v11 == (_DWORD)v10 + 1 )
      {
        v9 = 0i64;
        goto LABEL_14;
      }
    }
    else if ( v11 - (_DWORD)v10 == 1 )
    {
      v9 = 0i64;
      goto LABEL_14;
    }
    this->Queue.HeadReserved = 1;
    v9 = &this->Queue.pQueue[v10];
  }
LABEL_14:
  v9->pImpl = item->pImpl;
  v9->Data = item->Data;
  v8 = ++this->Queue.QueueHead == this->Queue.QueueSize;
  v12 = this->Queue.QueueHead;
  this->Queue.HeadReserved = 0;
  if ( v8 )
    v12 = 0;
  this->Queue.QueueHead = v12;
  Scaleform::Render::RenderQueueProcessor::ProcessQueue(v7, QPM_Any);
}

// File Line: 798
// RVA: 0x9A3450
void __fastcall Scaleform::Render::HAL::PushMask_BeginSubmit(
        Scaleform::Render::HAL *this,
        Scaleform::Render::MaskPrimitive *prim)
{
  void *v4; // rax
  unsigned __int64 MaskStackTop; // r8
  bool v6; // si
  Scaleform::Render::MaskPrimitive *pObject; // rdx
  Scaleform::Render::HAL::MaskStackEntry *v8; // r14
  Scaleform::Render::MaskPrimitive *v9; // rcx
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  __int64 v13; // rdx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax

  v4 = this->vfptr[60].__vecDelDtor(this, 6i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v4 + 16i64))(
    v4,
    "Scaleform::Render::HAL::PushMask_BeginSubmit");
  if ( (this->HALState & 8) != 0
    && ((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[79].__vecDelDtor)(this) )
  {
    if ( this->AppliedSceneRasterMode )
    {
      this->vfptr[84].__vecDelDtor(this, 0);
      this->AppliedSceneRasterMode = RasterMode_Solid;
    }
    MaskStackTop = this->MaskStackTop;
    v6 = (this->HALState & 0x20) != 0;
    if ( (_DWORD)MaskStackTop
      && this->MaskStack.Data.Size > MaskStackTop
      && (this->HALState & 0x20) != 0
      && this->StencilAvailable
      && this->MultiBitStencil )
    {
      this->vfptr[78].__vecDelDtor(this, 3u);
      pObject = this->MaskStack.Data.Data[this->MaskStackTop].pPrimitive.pObject;
      ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::MatrixPoolImpl::HMatrix *, unsigned __int64))this->vfptr[81].__vecDelDtor)(
        this,
        pObject->MaskAreas.Data.Data,
        pObject->MaskAreas.Data.Size);
    }
    Scaleform::ArrayData<Scaleform::Render::HAL::MaskStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
      &this->MaskStack.Data,
      this->MaskStackTop + 1);
    v8 = &this->MaskStack.Data.Data[this->MaskStackTop];
    if ( prim )
      _InterlockedExchangeAdd(&prim->RefCount, 1u);
    v9 = v8->pPrimitive.pObject;
    if ( v8->pPrimitive.pObject && !_InterlockedDecrement(&v9->RefCount) && v9 )
      v9->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
        v9,
        1u);
    v8->pPrimitive.pObject = prim;
    v8->OldViewportValid = v6;
    y2 = this->ViewRect.y2;
    x2 = this->ViewRect.x2;
    y1 = this->ViewRect.y1;
    v8->OldViewRect.x1 = this->ViewRect.x1;
    v8->OldViewRect.y1 = y1;
    v8->OldViewRect.x2 = x2;
    v8->OldViewRect.y2 = y2;
    ++this->MaskStackTop;
    this->HALState |= 0x40u;
    if ( this->MaskStackTop == 1 && v6 )
    {
      v13 = 2i64;
      if ( !this->StencilAvailable )
        v13 = 6i64;
      this->vfptr[78].__vecDelDtor(this, v13);
      ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::MatrixPoolImpl::HMatrix *, unsigned __int64))this->vfptr[81].__vecDelDtor)(
        this,
        prim->MaskAreas.Data.Data,
        prim->MaskAreas.Data.Size);
    }
    if ( this->StencilAvailable )
    {
      vfptr = this->vfptr;
      if ( this->MultiBitStencil )
      {
        ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, _QWORD))vfptr[78].__vecDelDtor)(
          this,
          4i64,
          this->MaskStackTop - 1);
        ++this->AccumulatedStats.Masks;
        return;
      }
      ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, __int64))vfptr[78].__vecDelDtor)(this, 2i64, 1i64);
      if ( !warned )
      {
        warned = this->MaskStackTop > 1;
        ++this->AccumulatedStats.Masks;
        return;
      }
    }
    else if ( this->DepthBufferAvailable )
    {
      this->vfptr[78].__vecDelDtor(this, 6u);
      if ( !warned_0 )
        warned_0 = this->MaskStackTop > 1;
    }
    ++this->AccumulatedStats.Masks;
  }
}

// File Line: 878
// RVA: 0x970A40
void __fastcall Scaleform::Render::HAL::EndMaskSubmit(Scaleform::Render::HAL *this)
{
  void *v2; // rsi
  __int64 MaskStackTop; // r8
  __int64 v4; // rdx
  Scaleform::Render::HAL::RasterModeType CurrentSceneRasterMode; // edi

  v2 = this->vfptr[60].__vecDelDtor(this, 6i64);
  if ( (this->HALState & 0x48) != 72 )
    goto LABEL_9;
  this->HALState &= ~0x40u;
  if ( this->StencilAvailable )
  {
    MaskStackTop = this->MaskStackTop;
    v4 = 5i64;
  }
  else
  {
    if ( !this->DepthBufferAvailable )
      goto LABEL_7;
    MaskStackTop = 0i64;
    v4 = 7i64;
  }
  ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, __int64))this->vfptr[78].__vecDelDtor)(
    this,
    v4,
    MaskStackTop);
LABEL_7:
  CurrentSceneRasterMode = this->CurrentSceneRasterMode;
  if ( CurrentSceneRasterMode != this->AppliedSceneRasterMode )
  {
    this->vfptr[84].__vecDelDtor(this, CurrentSceneRasterMode);
    this->AppliedSceneRasterMode = CurrentSceneRasterMode;
  }
LABEL_9:
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
}

// File Line: 904
// RVA: 0x99F410
void __fastcall Scaleform::Render::HAL::PopMask(Scaleform::Render::HAL *this)
{
  void *v2; // rdi
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::Render::HAL *v4; // rcx
  __int64 v5; // rdx

  v2 = this->vfptr[60].__vecDelDtor(this, 7i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v2 + 16i64))(v2, "Scaleform::Render::HAL::PopMask");
  if ( (this->HALState & 8) != 0
    && ((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[79].__vecDelDtor)(this) )
  {
    --this->MaskStackTop;
    if ( this->StencilAvailable )
    {
      vfptr = this->vfptr;
      v4 = this;
      if ( this->MaskStackTop )
      {
        v5 = 5i64;
LABEL_9:
        vfptr[78].__vecDelDtor(v4, v5);
        goto LABEL_10;
      }
LABEL_8:
      v5 = 1i64;
      goto LABEL_9;
    }
    if ( this->DepthBufferAvailable )
    {
      vfptr = this->vfptr;
      v4 = this;
      goto LABEL_8;
    }
  }
LABEL_10:
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
}

// File Line: 979
// RVA: 0x9A2EB0
void __fastcall Scaleform::Render::HAL::PushBlendMode(
        Scaleform::Render::HAL *this,
        Scaleform::Render::BlendPrimitive *prim)
{
  Scaleform::Render::BlendPrimitive *v2; // rdi
  Scaleform::Render::BlendMode BlendModeValue; // r12d
  Scaleform::Render::HAL::BlendStackEntry *v5; // rbx

  v2 = prim;
  if ( (this->HALState & 8) != 0 )
  {
    BlendModeValue = prim->BlendModeValue;
    _InterlockedExchangeAdd(&prim->RefCount, 1u);
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::BlendStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::BlendStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      &this->BlendModeStack.Data,
      &this->BlendModeStack,
      this->BlendModeStack.Data.Size + 1);
    v5 = &this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
    if ( v5 )
    {
      if ( v2 )
      {
        _InterlockedExchangeAdd(&v2->RefCount, 1u);
        v2 = prim;
      }
      v5->pPrimitive.pObject = v2;
      v5->pRenderTarget.pObject = 0i64;
      v5->pLayerAlpha.pObject = 0i64;
      v5->LayerAlphaCleared = 0;
      v5->NoLayerParent = 0;
    }
    Scaleform::Render::HAL::applyBlendMode(this, BlendModeValue, 0, (this->HALState & 0x10) != 0);
    if ( v2 )
    {
      if ( !_InterlockedDecrement(&v2->RefCount) )
        prim->Scaleform::Render::CacheablePrimitive::Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
          prim,
          1i64);
    }
  }
}

// File Line: 992
// RVA: 0x99F0C0
void __fastcall Scaleform::Render::HAL::PopBlendMode(Scaleform::Render::HAL *this)
{
  Scaleform::ArrayLH<Scaleform::Render::HAL::BlendStackEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_BlendModeStack; // r14
  Scaleform::Render::HAL::BlendStackEntry *v3; // rbx
  Scaleform::Render::BlendPrimitive *pObject; // rcx
  Scaleform::Render::BlendPrimitive *v5; // rsi
  Scaleform::Render::RenderTarget *v6; // rcx
  Scaleform::Render::RenderTarget *v7; // rdi
  Scaleform::Render::RenderTarget *v8; // rcx
  Scaleform::Render::RenderTarget *v9; // r15
  Scaleform::Render::BlendMode BlendModeValue; // edx

  if ( (this->HALState & 8) != 0 )
  {
    p_BlendModeStack = &this->BlendModeStack;
    v3 = &this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size];
    pObject = v3[-1].pPrimitive.pObject;
    if ( pObject )
      _InterlockedExchangeAdd(&pObject->RefCount, 1u);
    v5 = v3[-1].pPrimitive.pObject;
    v6 = v3[-1].pRenderTarget.pObject;
    if ( v6 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v6->vfptr[1].__vecDelDtor)(v6);
    v7 = v3[-1].pRenderTarget.pObject;
    v8 = v3[-1].pLayerAlpha.pObject;
    if ( v8 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v8->vfptr[1].__vecDelDtor)(v8);
    v9 = v3[-1].pLayerAlpha.pObject;
    Scaleform::ArrayData<Scaleform::Render::HAL::BlendStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::BlendStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
      &p_BlendModeStack->Data,
      p_BlendModeStack->Data.Size - 1);
    if ( this->BlendModeStack.Data.Size )
      BlendModeValue = p_BlendModeStack->Data.Data[p_BlendModeStack->Data.Size - 1].pPrimitive.pObject->BlendModeValue;
    else
      BlendModeValue = Blend_Normal;
    Scaleform::Render::HAL::applyBlendMode(this, BlendModeValue, 0, (this->HALState & 0x10) != 0);
    if ( v9 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v9->vfptr[2].__vecDelDtor)(v9);
    if ( v7 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v7->vfptr[2].__vecDelDtor)(v7);
    if ( v5 )
    {
      if ( !_InterlockedDecrement(&v5->RefCount) )
        v5->Scaleform::Render::CacheablePrimitive::Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
          v5,
          1u);
    }
  }
}

// File Line: 1011
// RVA: 0x9CE8A0
void __fastcall Scaleform::Render::HAL::applyBlendMode(
        Scaleform::Render::HAL *this,
        __int64 mode,
        bool sourceAc,
        bool forceAc)
{
  Scaleform::Render::BlendMode v7; // eax
  unsigned int FillFlags; // edx
  Scaleform::Render::BlendMode v9; // r10d
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax

  if ( this->CurrentBlendState.Mode != (_DWORD)mode
    || this->CurrentBlendState.SourceAc != sourceAc
    || this->CurrentBlendState.ForceAc != forceAc )
  {
    if ( (unsigned int)mode >= 0x14 )
      mode = 0i64;
    v7 = this->Profiler.vfptr->GetBlendMode(&this->Profiler, (Scaleform::Render::BlendMode)mode);
    this->FillFlags &= 0xFFFFFFFC;
    FillFlags = this->FillFlags;
    v9 = v7;
    if ( (unsigned int)(v7 - 3) <= 1 )
    {
      this->FillFlags = FillFlags | 1;
    }
    else if ( v7 == Blend_Invert )
    {
      this->FillFlags = FillFlags | 2;
      this->FillFlags |= 0x20u;
LABEL_13:
      this->CurrentBlendState.Mode = v7;
      vfptr = this->vfptr;
      this->CurrentBlendState.SourceAc = sourceAc;
      this->CurrentBlendState.ForceAc = forceAc;
      ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, bool, bool))vfptr[42].__vecDelDtor)(
        this,
        (unsigned int)v9,
        sourceAc,
        forceAc);
      return;
    }
    if ( v7 <= Blend_Normal )
      this->FillFlags &= ~0x20u;
    else
      this->FillFlags |= 0x20u;
    goto LABEL_13;
  }
}

// File Line: 1079
// RVA: 0x9CE880
void __fastcall Scaleform::Render::HAL::applyBlendMode(
        Scaleform::Render::HAL *this,
        Scaleform::Render::HAL::HALBlendState *state)
{
  Scaleform::Render::HAL::applyBlendMode(this, state->Mode, state->SourceAc, state->ForceAc);
}

// File Line: 1084
// RVA: 0x9CE960
void __fastcall Scaleform::Render::HAL::applyBlendModeEnable(Scaleform::Render::HAL *this, bool enabled)
{
  if ( this->CurrentBlendState.BlendEnable != enabled )
  {
    ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[43].__vecDelDtor)(this);
    this->CurrentBlendState.BlendEnable = enabled;
  }
}

// File Line: 1093
// RVA: 0x9E70D0
__int64 __fastcall Scaleform::Render::HAL::getLastBlendModeOrDefault(Scaleform::Render::HAL *this)
{
  if ( this->BlendModeStack.Data.Size )
    return (unsigned int)this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1].pPrimitive.pObject->BlendModeValue;
  else
    return 1i64;
}

// File Line: 1120
// RVA: 0x9E02B0
void __fastcall Scaleform::Render::HAL::drawMaskClearRectangles(
        Scaleform::Render::HAL *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *matrices,
        unsigned __int64 count)
{
  unsigned __int64 v3; // rdi
  __int64 v5; // rbp
  unsigned __int64 v7; // rbx
  int v8; // ecx
  char *v9; // rax
  unsigned int v10; // r10d
  Scaleform::Render::MatrixState *pObject; // r8
  __m128 v12; // xmm6
  __m128 v13; // xmm7
  __int64 v14; // r9
  __m128 v15; // xmm5
  __int64 v16; // rax
  __int64 v17; // r9
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rcx
  __int64 v19; // rax
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  char v22[8]; // [rsp+20h] [rbp-438h] BYREF
  char v23[1016]; // [rsp+28h] [rbp-430h] BYREF

  if ( count )
  {
    v3 = count;
    v5 = 0i64;
    do
    {
      v7 = 32i64;
      v8 = 31;
      v9 = v23;
      if ( v3 < 0x20 )
        v7 = v3;
      do
      {
        --v8;
        *((_QWORD *)v9 - 1) = 1065353216i64;
        *(_QWORD *)v9 = 0i64;
        *((_DWORD *)v9 + 2) = 0;
        *(_QWORD *)(v9 + 12) = 1065353216i64;
        *((_DWORD *)v9 + 5) = 0;
        v9 += 32;
      }
      while ( v8 >= 0 );
      v10 = 0;
      pObject = this->Matrices.pObject;
      v12 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v;
      v13 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
      v14 = 0i64;
      do
      {
        v15 = *(__m128 *)&pObject->UserView.M[1][0];
        v16 = v14 + v5;
        v17 = 32 * v14;
        ++v10;
        pHandle = matrices[v16].pHandle;
        v19 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHandle->pHeader->Format & 0xF].Offsets[4];
        v20 = (__m128)pHandle->pHeader[v19 + 1];
        v21 = (__m128)pHandle->pHeader[v19 + 2];
        *(__m128 *)&v22[v17] = _mm_and_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(
                                         *(__m128 *)&pObject->UserView.M[0][0],
                                         *(__m128 *)&pObject->UserView.M[0][0],
                                         85),
                                       v21),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(
                                         *(__m128 *)&pObject->UserView.M[0][0],
                                         *(__m128 *)&pObject->UserView.M[0][0],
                                         0),
                                       v20)),
                                   _mm_and_ps(*(__m128 *)&pObject->UserView.M[0][0], v12)),
                                 v13);
        *(__m128 *)&v23[v17 + 8] = _mm_and_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v21),
                                         _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v20)),
                                       _mm_and_ps(v15, v12)),
                                     v13);
        v14 = v10;
      }
      while ( v10 < v7 );
      ((void (__fastcall *)(Scaleform::Render::HAL *, char *, unsigned __int64))this->vfptr[80].__vecDelDtor)(
        this,
        v22,
        v7);
      v5 += v7;
      v3 -= v7;
    }
    while ( v3 );
  }
}

// File Line: 1138
// RVA: 0x9CF4D0
void __fastcall Scaleform::Render::HAL::beginMaskDisplay(Scaleform::Render::HAL *this)
{
  this->HALState &= ~0x40u;
  *(_DWORD *)&this->StencilChecked = 0;
}

// File Line: 1148
// RVA: 0x9E1D50
void __fastcall Scaleform::Render::HAL::endMaskDisplay(Scaleform::Render::HAL *this)
{
  this->MaskStackTop = 0;
  Scaleform::ArrayData<Scaleform::Render::HAL::MaskStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->MaskStack.Data,
    0i64);
}

// File Line: 1155
// RVA: 0x9CEB00
void __fastcall Scaleform::Render::HAL::applyRasterMode(
        Scaleform::Render::HAL *this,
        Scaleform::Render::HAL::RasterModeType mode)
{
  if ( mode != this->AppliedSceneRasterMode )
  {
    ((void (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[84].__vecDelDtor)(this);
    this->AppliedSceneRasterMode = mode;
  }
}

// File Line: 1164
// RVA: 0x99F880
void __fastcall Scaleform::Render::HAL::PrepareCacheable(
        Scaleform::Render::HAL *this,
        Scaleform::Render::CacheablePrimitive *prim,
        bool unprepare)
{
  int CacheablePrepIndex; // eax
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *CacheResults; // rsi
  bool v7; // r13
  unsigned int v8; // ebp
  __int128 *v9; // r14
  _QWORD *v10; // rdi
  __int64 v11; // rdi
  __int128 *v12; // rsi
  __int64 v13; // rdi
  int v14; // eax
  bool v15; // zf
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  __int128 v17; // [rsp+20h] [rbp-38h] BYREF

  if ( (this->HALState & 8) == 0 )
    return;
  if ( prim->Caching )
  {
    if ( !unprepare )
    {
      CacheResults = prim->CacheResults;
      v17 = *(_OWORD *)&prim->CacheResults[0].pObject;
      v7 = 1;
      v8 = 0;
      v9 = &v17;
      while ( 1 )
      {
        v10 = *(_QWORD **)v9;
        if ( !*(_QWORD *)v9 )
          break;
        if ( (*(unsigned int (__fastcall **)(_QWORD))(*v10 + 32i64))(*(_QWORD *)v9) == 3
          || (*(unsigned int (__fastcall **)(_QWORD *))(*v10 + 32i64))(v10) == 2
          || *(Scaleform::Render::CacheablePrimitive **)(v10[4] + 24i64) != prim )
        {
          v7 = 0;
          goto LABEL_18;
        }
        ++v8;
        v9 = (__int128 *)((char *)v9 + 8);
        if ( v8 >= 2 )
          goto LABEL_18;
      }
      v7 = v8 != 0;
LABEL_18:
      ++this->CacheablePrepIndex;
      if ( v7 )
      {
        if ( this->CacheablePrepStart < 0 )
        {
          v12 = &v17;
          v13 = 2i64;
          do
          {
            if ( *(_QWORD *)v12 )
              (*(void (__fastcall **)(_QWORD, __int64))(**(_QWORD **)v12 + 40i64))(*(_QWORD *)v12, 1i64);
            v12 = (__int128 *)((char *)v12 + 8);
            --v13;
          }
          while ( v13 );
          *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[64].__vecDelDtor)(this) + 44) = 1;
          this->CacheablePrepStart = this->CacheablePrepIndex;
        }
      }
      else
      {
        prim->Caching = Cache_Mesh;
        v11 = 2i64;
        do
        {
          if ( CacheResults->pObject )
            ((void (__fastcall *)(Scaleform::Render::RenderTarget *))CacheResults->pObject->vfptr[2].__vecDelDtor)(CacheResults->pObject);
          CacheResults->pObject = 0i64;
          ++CacheResults;
          --v11;
        }
        while ( v11 );
        prim->Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor(
          prim,
          0);
      }
      return;
    }
  }
  else if ( !unprepare )
  {
    if ( this->CurrentPass == Display_Prepass )
      *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[64].__vecDelDtor)(this) + 44) = 0;
    CacheablePrepIndex = this->CacheablePrepIndex;
    if ( CacheablePrepIndex >= 0 )
      this->CacheablePrepIndex = CacheablePrepIndex + 1;
    return;
  }
  v14 = this->CacheablePrepIndex;
  if ( v14 >= 0 )
  {
    if ( v14 == this->CacheablePrepStart )
    {
      v15 = this->CurrentPass == Display_Prepass;
      vfptr = this->vfptr;
      this->CacheablePrepStart = -1;
      if ( !v15 )
      {
        *(_DWORD *)(((__int64 (*)(void))vfptr[64].__vecDelDtor)() + 44) = 0;
        --this->CacheablePrepIndex;
        return;
      }
      *(_DWORD *)(((__int64 (*)(void))vfptr[64].__vecDelDtor)() + 44) = 1;
    }
    --this->CacheablePrepIndex;
  }
}

// File Line: 1255
// RVA: 0x9A3010
void __fastcall Scaleform::Render::HAL::PushFilters(
        Scaleform::Render::HAL *this,
        Scaleform::Render::FilterPrimitive *prim)
{
  void *v4; // rax
  _DWORD *v5; // r15
  Scaleform::Render::HAL::FilterStackEntry *v6; // rdx
  Scaleform::Render::HAL::FilterStackEntry *v7; // rdx
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rdi
  __int64 v9; // rbx
  int v10; // ecx
  float v11; // xmm2_4
  int v12; // xmm3_4
  int v13; // xmm1_4
  __int64 v14; // rdx
  int v15; // ecx
  void *v16; // rax
  Scaleform::Render::HAL::FilterStackEntry *v17; // rbx
  _DWORD *v18; // [rsp+50h] [rbp-20h]
  int v19[4]; // [rsp+60h] [rbp-10h] BYREF
  int v20; // [rsp+A0h] [rbp+30h] BYREF
  int v21; // [rsp+B0h] [rbp+40h] BYREF
  int v22; // [rsp+B4h] [rbp+44h]
  int v23; // [rsp+B8h] [rbp+48h] BYREF
  int v24; // [rsp+BCh] [rbp+4Ch]

  v4 = this->vfptr[60].__vecDelDtor(this, 12i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v4 + 16i64))(v4, "Scaleform::Render::HAL::PushFilters");
  if ( (this->HALState & 8) == 0 )
    return;
  if ( prim )
    _InterlockedExchangeAdd(&prim->RefCount, 1u);
  v5 = 0i64;
  v18 = 0i64;
  if ( this->vfptr[74].__vecDelDtor(this, prim) )
  {
    if ( (this->HALState & 0x300) != 0 )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
        &this->FilterStack.Data,
        &this->FilterStack,
        this->FilterStack.Data.Size + 1);
      v7 = &this->FilterStack.Data.Data[this->FilterStack.Data.Size - 1];
      if ( v7 )
      {
        if ( prim )
        {
          _InterlockedExchangeAdd(&prim->RefCount, 1u);
          v5 = 0i64;
        }
        v7->pPrimitive.pObject = prim;
        v7->pRenderTarget.pObject = 0i64;
      }
      goto LABEL_34;
    }
    if ( this->MaskStackTop && !prim->MaskPresent && prim->Caching != Cache_Count )
      this->vfptr[78].__vecDelDtor(this, 1u);
    this->vfptr[84].__vecDelDtor(this, 0);
    this->HALState |= 0x80u;
    if ( prim->Caching )
    {
      this->HALState |= 0x100u;
      this->CacheableIndex = this->FilterStack.Data.Size;
      *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[64].__vecDelDtor)(this) + 48) = 1;
    }
    else
    {
      pHeader = prim->PrimitiveArea.Data.Data->pHandle->pHeader;
      v9 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[4];
      v10 = (int)*((float *)&pHeader[v9 + 2].pHandle + 1);
      v21 = (int)*(float *)&pHeader[v9 + 1].pHandle;
      v22 = v10;
      v5 = (_DWORD *)((__int64 (__fastcall *)(Scaleform::Render::HAL *, int *, bool))this->vfptr[22].__vecDelDtor)(
                       this,
                       &v21,
                       prim->MaskPresent);
      v18 = v5;
      v11 = *(float *)&pHeader[v9 + 2].DataPageOffset;
      *(float *)&v12 = v11 + *((float *)&pHeader[v9 + 2].pHandle + 1);
      *(float *)&v13 = *(float *)&pHeader[v9 + 1].DataPageOffset + *(float *)&pHeader[v9 + 1].pHandle;
      v19[0] = *(_DWORD *)&pHeader[v9 + 1].DataPageOffset;
      *(float *)&v19[1] = v11;
      v19[2] = v13;
      v19[3] = v12;
      v20 = 0;
      ((void (__fastcall *)(Scaleform::Render::HAL *, int *, _DWORD *, _QWORD, int *))this->vfptr[24].__vecDelDtor)(
        this,
        v19,
        v5,
        0i64,
        &v20);
      Scaleform::Render::HAL::applyBlendMode(this, Blend_Normal, 0, 1);
      if ( prim->MaskPresent
        && ((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[79].__vecDelDtor)(this) )
      {
        if ( this->StencilAvailable )
        {
          v14 = 2i64;
        }
        else
        {
          if ( !this->DepthBufferAvailable )
          {
LABEL_28:
            v15 = v5[11];
            v23 = v5[10];
            v24 = v15;
            v16 = this->Matrices.pObject->vfptr[1].__vecDelDtor(this->Matrices.pObject, &v23);
            ((void (__fastcall *)(Scaleform::Render::HAL *, void *, __int64))this->vfptr[80].__vecDelDtor)(
              this,
              v16,
              1i64);
            ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, _QWORD))this->vfptr[78].__vecDelDtor)(
              this,
              1i64,
              this->MaskStackTop);
            goto LABEL_30;
          }
          v14 = 6i64;
        }
        ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, _QWORD))this->vfptr[78].__vecDelDtor)(
          this,
          v14,
          this->MaskStackTop);
        goto LABEL_28;
      }
    }
LABEL_30:
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      &this->FilterStack.Data,
      &this->FilterStack,
      this->FilterStack.Data.Size + 1);
    v17 = &this->FilterStack.Data.Data[this->FilterStack.Data.Size - 1];
    if ( v17 )
    {
      _InterlockedExchangeAdd(&prim->RefCount, 1u);
      v17->pPrimitive.pObject = prim;
      v5 = v18;
      if ( v18 )
        (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v18 + 8i64))(v18);
      v17->pRenderTarget.pObject = (Scaleform::Render::RenderTarget *)v18;
    }
    goto LABEL_34;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    &this->FilterStack.Data,
    &this->FilterStack,
    this->FilterStack.Data.Size + 1);
  v6 = &this->FilterStack.Data.Data[this->FilterStack.Data.Size - 1];
  if ( v6 )
  {
    if ( prim )
    {
      _InterlockedExchangeAdd(&prim->RefCount, 1u);
      v5 = 0i64;
    }
    v6->pPrimitive.pObject = prim;
    v6->pRenderTarget.pObject = 0i64;
  }
LABEL_34:
  if ( v5 )
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v5 + 16i64))(v5);
  if ( prim )
  {
    if ( !_InterlockedDecrement(&prim->RefCount) )
      prim->Scaleform::Render::CacheablePrimitive::Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
        prim,
        1i64);
  }
}

// File Line: 1322
// RVA: 0x98B9D0
void __fastcall Scaleform::Render::HAL::GetStats(
        Scaleform::Render::HAL *this,
        Scaleform::Render::HAL::Stats *pstats,
        bool clear)
{
  *pstats = this->AccumulatedStats;
  if ( clear )
  {
    *(_QWORD *)&this->AccumulatedStats.RTChanges = 0i64;
    *(_QWORD *)&this->AccumulatedStats.Triangles = 0i64;
    *(_QWORD *)&this->AccumulatedStats.Primitives = 0i64;
  }
}

// File Line: 1333
// RVA: 0x982EC0
Scaleform::Render::RenderEvent *__fastcall Scaleform::Render::HAL::GetEvent(
        Scaleform::Render::HAL *this,
        Scaleform::Render::EventType __formal)
{
  if ( (_S5_12 & 1) == 0 )
  {
    _S5_12 |= 1u;
    defaultEvent.vfptr = (Scaleform::Render::RenderEventVtbl *)&Scaleform::Render::RenderEvent::`vftable;
    atexit(Scaleform::Render::HAL::GetEvent_::_2_::_dynamic_atexit_destructor_for__defaultEvent__);
  }
  return &defaultEvent;
}

// File Line: 1339
// RVA: 0x99F200
void __fastcall Scaleform::Render::HAL::PopFilters(Scaleform::Render::HAL *this)
{
  void *v2; // r14
  Scaleform::Render::FilterPrimitive *v3; // rcx
  Scaleform::Render::HAL::FilterStackEntry *v4; // rsi
  Scaleform::Render::RenderTarget *v5; // rcx
  Scaleform::Render::FilterPrimitive *v6; // rcx
  unsigned int HALState; // ecx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::Render::FilterPrimitive *pObject; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::Render::RenderTarget *v10; // [rsp+30h] [rbp-38h]
  Scaleform::Render::HAL::FilterStackEntry result; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::Render::HAL::FilterStackEntry v12; // [rsp+48h] [rbp-20h] BYREF

  v2 = this->vfptr[60].__vecDelDtor(this, 12i64);
  if ( this->vfptr[74].__vecDelDtor(
         this,
         this->FilterStack.Data.Data[this->FilterStack.Data.Size - 1].pPrimitive.pObject) )
  {
    pObject = 0i64;
    v10 = 0i64;
    v4 = Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::Pop(
           &this->FilterStack,
           &v12);
    if ( v4->pPrimitive.pObject )
      _InterlockedExchangeAdd(&v4->pPrimitive.pObject->RefCount, 1u);
    pObject = v4->pPrimitive.pObject;
    v5 = v4->pRenderTarget.pObject;
    if ( v5 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v5->vfptr[1].__vecDelDtor)(v5);
    v10 = v4->pRenderTarget.pObject;
    if ( v12.pRenderTarget.pObject )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v12.pRenderTarget.pObject->vfptr[2].__vecDelDtor)(v12.pRenderTarget.pObject);
    v6 = v12.pPrimitive.pObject;
    if ( v12.pPrimitive.pObject && !_InterlockedDecrement(&v12.pPrimitive.pObject->RefCount) && v6 )
      v6->Scaleform::Render::CacheablePrimitive::Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
        v6,
        1u);
    HALState = this->HALState;
    if ( (HALState & 0x200) == 0
      && ((HALState & 0x100) == 0 || this->CacheableIndex >= (int)this->FilterStack.Data.Size) )
    {
      this->CacheableIndex = -1;
      vfptr = this->vfptr;
      if ( (HALState & 0x300) != 0 )
      {
        vfptr[50].__vecDelDtor(this, (unsigned int)pObject);
        *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->vfptr[64].__vecDelDtor)(this) + 48) = 0;
        this->HALState &= 0xFFFFFCFF;
      }
      else
      {
        vfptr[49].__vecDelDtor(this, (unsigned int)&pObject);
      }
      if ( !this->FilterStack.Data.Size )
        this->HALState &= ~0x80u;
    }
    if ( v10 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v10->vfptr[2].__vecDelDtor)(v10);
    v3 = pObject;
  }
  else
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::Pop(
      &this->FilterStack,
      &result);
    if ( result.pRenderTarget.pObject )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))result.pRenderTarget.pObject->vfptr[2].__vecDelDtor)(result.pRenderTarget.pObject);
    v3 = result.pPrimitive.pObject;
  }
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) )
    v3->Scaleform::Render::CacheablePrimitive::Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      v3,
      1u);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
}

// File Line: 1377
// RVA: 0x9A3940
void __fastcall Scaleform::Render::HAL::PushView3D(
        Scaleform::Render::HAL *this,
        Scaleform::Render::Matrix3x4<float> *m)
{
  Scaleform::Render::MatrixState *pObject; // r8
  Scaleform::ArrayLH<Scaleform::Render::Matrix3x4<float>,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_ViewMatrix3DStack; // rcx

  pObject = this->Matrices.pObject;
  p_ViewMatrix3DStack = &this->ViewMatrix3DStack;
  pObject->View3D = *m;
  LOBYTE(p_ViewMatrix3DStack[-19].Data.Data[13].M[1][0]) = 1;
  Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
    &p_ViewMatrix3DStack->Data,
    m);
}

// File Line: 1385
// RVA: 0x9A3810
void __fastcall Scaleform::Render::HAL::PushProj3D(
        Scaleform::Render::HAL *this,
        Scaleform::Render::Matrix4x4<float> *m)
{
  Scaleform::Render::MatrixState *pObject; // r8
  Scaleform::ArrayLH<Scaleform::Render::Matrix4x4<float>,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_ProjectionMatrix3DStack; // rcx

  pObject = this->Matrices.pObject;
  p_ProjectionMatrix3DStack = &this->ProjectionMatrix3DStack;
  pObject->Proj3D = *m;
  LOBYTE(p_ProjectionMatrix3DStack[-20].Data.Data[10].M[0][0]) = 1;
  Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
    &p_ProjectionMatrix3DStack->Data,
    m);
}

// File Line: 1392
// RVA: 0x99F5D0
void __fastcall Scaleform::Render::HAL::PopView3D(Scaleform::Render::HAL *this)
{
  Scaleform::Render::Matrix3x4<float> *v2; // r8
  Scaleform::Render::MatrixState *pObject; // rcx

  Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->ViewMatrix3DStack.Data,
    this->ViewMatrix3DStack.Data.Size - 1);
  if ( this->ViewMatrix3DStack.Data.Size )
    v2 = &this->ViewMatrix3DStack.Data.Data[this->ViewMatrix3DStack.Data.Size - 1];
  else
    v2 = &Scaleform::Render::Matrix3x4<float>::Identity;
  pObject = this->Matrices.pObject;
  pObject->View3D.M[0][0] = v2->M[0][0];
  pObject->View3D.M[0][1] = v2->M[0][1];
  pObject->View3D.M[0][2] = v2->M[0][2];
  pObject->View3D.M[0][3] = v2->M[0][3];
  pObject->View3D.M[1][0] = v2->M[1][0];
  pObject->View3D.M[1][1] = v2->M[1][1];
  pObject->View3D.M[1][2] = v2->M[1][2];
  pObject->View3D.M[1][3] = v2->M[1][3];
  pObject->View3D.M[2][0] = v2->M[2][0];
  pObject->View3D.M[2][1] = v2->M[2][1];
  pObject->View3D.M[2][2] = v2->M[2][2];
  pObject->View3D.M[2][3] = v2->M[2][3];
  this->Matrices.pObject->UVPOChanged = 1;
}

// File Line: 1399
// RVA: 0x99F4C0
void __fastcall Scaleform::Render::HAL::PopProj3D(Scaleform::Render::HAL *this)
{
  Scaleform::Render::Matrix4x4<float> *v2; // r8
  Scaleform::Render::MatrixState *pObject; // rcx

  Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->ProjectionMatrix3DStack.Data,
    this->ProjectionMatrix3DStack.Data.Size - 1);
  if ( this->ProjectionMatrix3DStack.Data.Size )
    v2 = &this->ProjectionMatrix3DStack.Data.Data[this->ProjectionMatrix3DStack.Data.Size - 1];
  else
    v2 = &Scaleform::Render::Matrix4x4<float>::Identity;
  pObject = this->Matrices.pObject;
  pObject->Proj3D.M[0][0] = v2->M[0][0];
  pObject->Proj3D.M[0][1] = v2->M[0][1];
  pObject->Proj3D.M[0][2] = v2->M[0][2];
  pObject->Proj3D.M[0][3] = v2->M[0][3];
  pObject->Proj3D.M[1][0] = v2->M[1][0];
  pObject->Proj3D.M[1][1] = v2->M[1][1];
  pObject->Proj3D.M[1][2] = v2->M[1][2];
  pObject->Proj3D.M[1][3] = v2->M[1][3];
  pObject->Proj3D.M[2][0] = v2->M[2][0];
  pObject->Proj3D.M[2][1] = v2->M[2][1];
  pObject->Proj3D.M[2][2] = v2->M[2][2];
  pObject->Proj3D.M[2][3] = v2->M[2][3];
  pObject->Proj3D.M[3][0] = v2->M[3][0];
  pObject->Proj3D.M[3][1] = v2->M[3][1];
  pObject->Proj3D.M[3][2] = v2->M[3][2];
  pObject->Proj3D.M[3][3] = v2->M[3][3];
  this->Matrices.pObject->UVPOChanged = 1;
}

// File Line: 1406
// RVA: 0x96F410
__int64 __fastcall Scaleform::Render::HAL::DrawableCommandGetFlags(
        Scaleform::Render::HAL *this,
        Scaleform::Render::DICommand *pcmd)
{
  __int64 result; // rax

  if ( !pcmd )
    return 0i64;
  switch ( (*(unsigned int (__fastcall **)(Scaleform::Render::DICommand *))pcmd->vfptr->gap8)(pcmd) )
  {
    case 0u:
    case 1u:
    case 2u:
      result = 10i64;
      break;
    case 3u:
    case 4u:
    case 5u:
    case 6u:
    case 7u:
    case 8u:
    case 9u:
    case 0xAu:
    case 0x11u:
    case 0x13u:
    case 0x18u:
      result = 6i64;
      break;
    case 0x19u:
      result = 2i64;
      break;
    default:
      return 0i64;
  }
  return result;
}

// File Line: 1436
// RVA: 0x9A38C0
void __fastcall Scaleform::Render::HAL::PushUserData(
        Scaleform::Render::HAL *this,
        Scaleform::Render::UserDataState::Data *data)
{
  Scaleform::ArrayLH<Scaleform::Render::UserDataState::Data const *,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_UserDataStack; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r8
  Scaleform::Render::UserDataState::Data **v7; // rcx
  Scaleform::Render::UserDataState::Data **v8; // rcx

  p_UserDataStack = &this->UserDataStack;
  Size = this->UserDataStack.Data.Size;
  v5 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v5 <= this->UserDataStack.Data.Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= this->UserDataStack.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
    &this->UserDataStack.Data,
    &this->UserDataStack,
    v6);
LABEL_7:
  v7 = p_UserDataStack->Data.Data;
  p_UserDataStack->Data.Size = v5;
  v8 = &v7[v5 - 1];
  if ( v8 )
    *v8 = data;
}

// File Line: 1441
// RVA: 0x99F5B0
void __fastcall Scaleform::Render::HAL::PopUserData(Scaleform::Render::HAL *this)
{
  Scaleform::ArrayData<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->UserDataStack.Data,
    this->UserDataStack.Data.Size - 1);
}

