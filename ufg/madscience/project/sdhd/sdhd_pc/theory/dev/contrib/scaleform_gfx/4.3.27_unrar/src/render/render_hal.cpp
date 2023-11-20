// File Line: 26
// RVA: 0x93EF90
void __fastcall Scaleform::Render::MatrixState::MatrixState(Scaleform::Render::MatrixState *this, Scaleform::Render::HAL *phal)
{
  Scaleform::Render::HAL *v2; // rdi
  Scaleform::Render::MatrixState *v3; // rsi

  v2 = phal;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,65>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MatrixState,65>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MatrixState::`vftable';
  *(_OWORD *)&this->View2D.M[0][0] = 0x3F800000ui64;
  this->View2D.M[1][0] = 0.0;
  *(_QWORD *)&this->View2D.M[1][1] = 1065353216i64;
  this->View2D.M[1][3] = 0.0;
  memset(&this->View3D, 0, 0x30ui64);
  v3->View3D.M[0][0] = 1.0;
  v3->View3D.M[1][1] = 1.0;
  v3->View3D.M[2][2] = 1.0;
  memset(&v3->Proj3D, 0, 0x40ui64);
  v3->Proj3D.M[0][0] = 1.0;
  v3->Proj3D.M[1][1] = 1.0;
  v3->Proj3D.M[2][2] = 1.0;
  v3->Proj3D.M[3][3] = 1.0;
  memset(&v3->Proj3DLeft, 0, 0x40ui64);
  v3->Proj3DLeft.M[0][0] = 1.0;
  v3->Proj3DLeft.M[1][1] = 1.0;
  v3->Proj3DLeft.M[2][2] = 1.0;
  v3->Proj3DLeft.M[3][3] = 1.0;
  memset(&v3->Proj3DRight, 0, 0x40ui64);
  v3->Proj3DRight.M[0][0] = 1.0;
  v3->Proj3DRight.M[1][1] = 1.0;
  v3->Proj3DRight.M[2][2] = 1.0;
  v3->Proj3DRight.M[3][3] = 1.0;
  *(_QWORD *)&v3->User.M[0][0] = 1065353216i64;
  *(_QWORD *)&v3->User.M[0][2] = 0i64;
  v3->User.M[1][0] = 0.0;
  *(_QWORD *)&v3->User.M[1][1] = 1065353216i64;
  v3->User.M[1][3] = 0.0;
  *(_QWORD *)&v3->User3D.M[0][0] = 1065353216i64;
  *(_QWORD *)&v3->User3D.M[0][2] = 0i64;
  v3->User3D.M[1][0] = 0.0;
  *(_QWORD *)&v3->User3D.M[1][1] = 1065353216i64;
  v3->User3D.M[1][3] = 0.0;
  *(_QWORD *)&v3->Orient2D.M[0][0] = 1065353216i64;
  *(_QWORD *)&v3->Orient2D.M[0][2] = 0i64;
  v3->Orient2D.M[1][0] = 0.0;
  *(_QWORD *)&v3->Orient2D.M[1][1] = 1065353216i64;
  v3->Orient2D.M[1][3] = 0.0;
  memset(&v3->Orient3D, 0, 0x40ui64);
  v3->Orient3D.M[0][0] = 1.0;
  v3->Orient3D.M[1][1] = 1.0;
  v3->Orient3D.M[2][2] = 1.0;
  *(_QWORD *)&v3->Orient3D.M[3][3] = 1065353216i64;
  *(_QWORD *)&v3->ViewRectOriginal.y1 = 0i64;
  *(_QWORD *)&v3->ViewRectOriginal.y2 = 0i64;
  *(_QWORD *)&v3->ViewRect.y1 = 0i64;
  v3->ViewRect.y2 = 0;
  *(_QWORD *)&v3->UserView.M[0][0] = 1065353216i64;
  *(_QWORD *)&v3->UserView.M[0][2] = 0i64;
  v3->UserView.M[1][0] = 0.0;
  *(_QWORD *)&v3->UserView.M[1][1] = 1065353216i64;
  v3->UserView.M[1][3] = 0.0;
  memset(&v3->UVPO, 0, 0x40ui64);
  v3->UVPO.M[0][0] = 1.0;
  v3->UVPO.M[1][1] = 1.0;
  v3->UVPO.M[2][2] = 1.0;
  v3->UVPO.M[3][3] = 1.0;
  memset(&v3->ViewRectCompensated3D, 0, 0x40ui64);
  v3->ViewRectCompensated3D.M[0][0] = 1.0;
  v3->ViewRectCompensated3D.M[1][1] = 1.0;
  v3->ViewRectCompensated3D.M[2][2] = 1.0;
  v3->ViewRectCompensated3D.M[3][3] = 1.0;
  *(_WORD *)&v3->UVPOChanged = 0;
  v3->S3DDisplay = 0;
  v3->S3DImpl.pObject = 0i64;
  v3->pHAL = v2;
  *(_QWORD *)&v3->FullViewportMVP.M[0][0] = 1065353216i64;
  *(_QWORD *)&v3->FullViewportMVP.M[0][2] = 0i64;
  *(_QWORD *)&v3->FullViewportMVP.M[1][1] = 1065353216i64;
  *(_QWORD *)&v3->FullViewportMVP.M[1][2] = 0i64;
  *(_QWORD *)&v3->FullViewportMVP.M[0][0] = 0x40000000i64;
  v3->FullViewportMVP.M[0][2] = 0.0;
  v3->FullViewportMVP.M[0][3] = -1.0;
  v3->FullViewportMVP.M[1][0] = 0.0;
  v3->FullViewportMVP.M[1][1] = -2.0;
  v3->FullViewportMVP.M[1][3] = 1.0;
}

// File Line: 34
// RVA: 0x93F2E0
void __fastcall Scaleform::Render::MatrixState::MatrixState(Scaleform::Render::MatrixState *this)
{
  Scaleform::Render::MatrixState *v1; // rdi

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,65>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MatrixState,65>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MatrixState::`vftable';
  *(_OWORD *)&this->View2D.M[0][0] = 0x3F800000ui64;
  this->View2D.M[1][0] = 0.0;
  *(_QWORD *)&this->View2D.M[1][1] = 1065353216i64;
  this->View2D.M[1][3] = 0.0;
  memset(&this->View3D, 0, 0x30ui64);
  v1->View3D.M[0][0] = 1.0;
  v1->View3D.M[1][1] = 1.0;
  v1->View3D.M[2][2] = 1.0;
  memset(&v1->Proj3D, 0, 0x40ui64);
  v1->Proj3D.M[0][0] = 1.0;
  v1->Proj3D.M[1][1] = 1.0;
  v1->Proj3D.M[2][2] = 1.0;
  v1->Proj3D.M[3][3] = 1.0;
  memset(&v1->Proj3DLeft, 0, 0x40ui64);
  v1->Proj3DLeft.M[0][0] = 1.0;
  v1->Proj3DLeft.M[1][1] = 1.0;
  v1->Proj3DLeft.M[2][2] = 1.0;
  v1->Proj3DLeft.M[3][3] = 1.0;
  memset(&v1->Proj3DRight, 0, 0x40ui64);
  v1->Proj3DRight.M[0][0] = 1.0;
  v1->Proj3DRight.M[1][1] = 1.0;
  v1->Proj3DRight.M[2][2] = 1.0;
  v1->Proj3DRight.M[3][3] = 1.0;
  *(_QWORD *)&v1->User.M[0][0] = 1065353216i64;
  *(_QWORD *)&v1->User.M[0][2] = 0i64;
  v1->User.M[1][0] = 0.0;
  *(_QWORD *)&v1->User.M[1][1] = 1065353216i64;
  v1->User.M[1][3] = 0.0;
  *(_QWORD *)&v1->User3D.M[0][0] = 1065353216i64;
  *(_QWORD *)&v1->User3D.M[0][2] = 0i64;
  v1->User3D.M[1][0] = 0.0;
  *(_QWORD *)&v1->User3D.M[1][1] = 1065353216i64;
  v1->User3D.M[1][3] = 0.0;
  *(_QWORD *)&v1->Orient2D.M[0][0] = 1065353216i64;
  *(_QWORD *)&v1->Orient2D.M[0][2] = 0i64;
  v1->Orient2D.M[1][0] = 0.0;
  *(_QWORD *)&v1->Orient2D.M[1][1] = 1065353216i64;
  v1->Orient2D.M[1][3] = 0.0;
  memset(&v1->Orient3D, 0, 0x40ui64);
  v1->Orient3D.M[0][0] = 1.0;
  v1->Orient3D.M[1][1] = 1.0;
  v1->Orient3D.M[2][2] = 1.0;
  *(_QWORD *)&v1->Orient3D.M[3][3] = 1065353216i64;
  *(_QWORD *)&v1->ViewRectOriginal.y1 = 0i64;
  *(_QWORD *)&v1->ViewRectOriginal.y2 = 0i64;
  *(_QWORD *)&v1->ViewRect.y1 = 0i64;
  v1->ViewRect.y2 = 0;
  *(_QWORD *)&v1->UserView.M[0][0] = 1065353216i64;
  *(_QWORD *)&v1->UserView.M[0][2] = 0i64;
  v1->UserView.M[1][0] = 0.0;
  *(_QWORD *)&v1->UserView.M[1][1] = 1065353216i64;
  v1->UserView.M[1][3] = 0.0;
  memset(&v1->UVPO, 0, 0x40ui64);
  v1->UVPO.M[0][0] = 1.0;
  v1->UVPO.M[1][1] = 1.0;
  v1->UVPO.M[2][2] = 1.0;
  v1->UVPO.M[3][3] = 1.0;
  memset(&v1->ViewRectCompensated3D, 0, 0x40ui64);
  v1->ViewRectCompensated3D.M[0][0] = 1.0;
  v1->ViewRectCompensated3D.M[1][1] = 1.0;
  v1->ViewRectCompensated3D.M[2][2] = 1.0;
  v1->ViewRectCompensated3D.M[3][3] = 1.0;
  *(_WORD *)&v1->UVPOChanged = 0;
  v1->S3DDisplay = 0;
  v1->S3DImpl.pObject = 0i64;
  v1->pHAL = 0i64;
  *(_QWORD *)&v1->FullViewportMVP.M[0][0] = 1065353216i64;
  *(_QWORD *)&v1->FullViewportMVP.M[0][2] = 0i64;
  *(_QWORD *)&v1->FullViewportMVP.M[1][1] = 1065353216i64;
  *(_QWORD *)&v1->FullViewportMVP.M[1][2] = 0i64;
  *(_QWORD *)&v1->FullViewportMVP.M[0][0] = 0x40000000i64;
  v1->FullViewportMVP.M[0][2] = 0.0;
  v1->FullViewportMVP.M[0][3] = -1.0;
  v1->FullViewportMVP.M[1][0] = 0.0;
  v1->FullViewportMVP.M[1][1] = -2.0;
  v1->FullViewportMVP.M[1][3] = 1.0;
}

// File Line: 39
// RVA: 0x9B5390
void __fastcall Scaleform::Render::MatrixState::SetUserMatrix(Scaleform::Render::MatrixState *this, Scaleform::Render::Matrix2x4<float> *user, Scaleform::Render::Matrix2x4<float> *user3D)
{
  Scaleform::Render::Matrix2x4<float> *v3; // r9
  Scaleform::Render::Matrix2x4<float> *v4; // rdx
  Scaleform::Render::MatrixState *v5; // rdi
  Scaleform::Render::Matrix2x4<float> *v6; // rbx
  Scaleform::Render::Matrix2x4<float> *v7; // rax
  Scaleform::Render::Matrix2x4<float> *v8; // rax
  float v9; // xmm7_4
  int v10; // eax
  float v11; // xmm5_4
  float v12; // xmm1_4
  Scaleform::Render::Matrix2x4<float> result; // [rsp+20h] [rbp-68h]
  Scaleform::Render::Matrix2x4<float> v14; // [rsp+40h] [rbp-48h]

  this->UVPOChanged = 1;
  v3 = user;
  v4 = &this->User;
  v5 = this;
  *(_QWORD *)&this->User.M[0][0] = *(_QWORD *)&v3->M[0][0];
  v6 = user3D;
  *(_QWORD *)&this->User.M[0][2] = *(_QWORD *)&v3->M[0][2];
  v4->M[1][0] = v3->M[1][0];
  v4->M[1][1] = v3->M[1][1];
  v4->M[1][2] = v3->M[1][2];
  v4->M[1][3] = v3->M[1][3];
  v7 = Scaleform::Render::operator*(&result, &this->User, &this->Orient2D);
  v8 = Scaleform::Render::operator*(&v14, &v5->View2D, v7);
  v5->UserView.M[0][0] = v8->M[0][0];
  v5->UserView.M[0][1] = v8->M[0][1];
  v5->UserView.M[0][2] = v8->M[0][2];
  v5->UserView.M[0][3] = v8->M[0][3];
  v5->UserView.M[1][0] = v8->M[1][0];
  v5->UserView.M[1][1] = v8->M[1][1];
  v5->UserView.M[1][2] = v8->M[1][2];
  v5->UserView.M[1][3] = v8->M[1][3];
  v5->User3D.M[0][0] = v6->M[0][0];
  v5->User3D.M[0][1] = v6->M[0][1];
  v5->User3D.M[0][2] = v6->M[0][2];
  v5->User3D.M[0][3] = v6->M[0][3];
  v5->User3D.M[1][0] = v6->M[1][0];
  v5->User3D.M[1][1] = v6->M[1][1];
  v5->User3D.M[1][2] = v6->M[1][2];
  v9 = v6->M[1][3];
  v5->User3D.M[1][3] = v9;
  if ( v5->ViewRect.x2 - v5->ViewRect.x1 <= 0 || (v10 = v5->ViewRect.y2 - v5->ViewRect.y1, v10 <= 0) )
  {
    v5->User3D.M[0][3] = 0.0;
    v5->User3D.M[1][3] = 0.0;
  }
  else
  {
    v11 = (float)(v5->ViewRect.x2 - v5->ViewRect.x1);
    v12 = (float)((float)((float)((float)((float)((float)v10 * 0.5) * v5->User3D.M[1][1])
                                + (float)((float)(v11 * 0.5) * v5->User3D.M[1][0]))
                        + v9)
                - (float)((float)v10 * 0.5))
        * -2.0;
    v5->User3D.M[0][3] = (float)((float)((float)((float)((float)((float)(v11 * 0.5) * v5->User3D.M[0][0])
                                                       + (float)((float)((float)v10 * 0.5) * v5->User3D.M[0][1]))
                                               + v5->User3D.M[0][3])
                                       - (float)(v11 * 0.5))
                               * 2.0)
                       / v11;
    v5->User3D.M[1][3] = v12 / (float)v10;
  }
}

// File Line: 63
// RVA: 0x9B55A0
void __fastcall Scaleform::Render::MatrixState::SetUserMatrix(Scaleform::Render::MatrixState *this, Scaleform::Render::Matrix2x4<float> *user)
{
  ((void (__fastcall *)(Scaleform::Render::MatrixState *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *))this->vfptr[2].__vecDelDtor)(
    this,
    user,
    user);
}

// File Line: 68
// RVA: 0x9B5DA0
void __fastcall Scaleform::Render::MatrixState::SetViewportMatrix(Scaleform::Render::MatrixState *this, Scaleform::Render::Matrix2x4<float> *vp)
{
  Scaleform::Render::MatrixState *v2; // rdi
  Scaleform::Render::Matrix2x4<float> *v3; // rax
  Scaleform::Render::Matrix2x4<float> *v4; // rax
  Scaleform::Render::Matrix2x4<float> result; // [rsp+20h] [rbp-48h]
  Scaleform::Render::Matrix2x4<float> v6; // [rsp+40h] [rbp-28h]

  v2 = this;
  this->View2D = *vp;
  v3 = Scaleform::Render::operator*(&result, &this->User, &this->Orient2D);
  v4 = Scaleform::Render::operator*(&v6, &v2->View2D, v3);
  v2->UserView.M[0][0] = v4->M[0][0];
  v2->UserView.M[0][1] = v4->M[0][1];
  v2->UserView.M[0][2] = v4->M[0][2];
  v2->UserView.M[0][3] = v4->M[0][3];
  v2->UserView.M[1][0] = v4->M[1][0];
  v2->UserView.M[1][1] = v4->M[1][1];
  v2->UserView.M[1][2] = v4->M[1][2];
  v2->UserView.M[1][3] = v4->M[1][3];
}

// File Line: 74
// RVA: 0x9B1F10
Scaleform::Render::Viewport *__fastcall Scaleform::Render::MatrixState::SetOrientation(Scaleform::Render::MatrixState *this, Scaleform::Render::Viewport *result, Scaleform::Render::Viewport *vp)
{
  Scaleform::Render::Viewport *v3; // r14
  Scaleform::Render::Viewport *v4; // rsi
  Scaleform::Render::MatrixState *v5; // rdi
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  Scaleform::Render::Matrix2x4<float> *v9; // rax
  Scaleform::Render::Matrix2x4<float> *v10; // rax
  float v11; // ecx
  float v12; // ecx
  float v13; // ecx
  signed int v14; // ecx
  signed int v15; // edx
  float v16; // xmm9_4
  __m128 v17; // xmm6
  float v18; // xmm10_4
  float v19; // xmm0_4
  unsigned int v20; // er8
  __m128 v21; // xmm5
  float v22; // xmm11_4
  float v23; // xmm12_4
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  float v26; // xmm1_4
  __m128 v27; // xmm7
  __m128 v28; // xmm8
  __m128 v29; // xmm1
  signed int v30; // ecx
  __m128 v31; // xmm1
  signed int v32; // ecx
  __m128 v33; // xmm4
  signed int v34; // ecx
  __m128 v35; // xmm3
  signed int v36; // ecx
  signed int v37; // ecx
  signed int v38; // edx
  int v39; // eax
  __m128 v40; // xmm4
  __m128 v41; // xmm3
  float v42; // xmm0_4
  __m128 v43; // xmm1
  signed int v44; // ecx
  __m128 v45; // xmm1
  signed int v46; // ecx
  __m128 v47; // xmm4
  signed int v48; // ecx
  __m128 v49; // xmm3
  signed int v50; // ecx
  Scaleform::Render::Matrix2x4<float> resulta; // [rsp+20h] [rbp-B8h]
  Scaleform::Render::Matrix2x4<float> v53; // [rsp+40h] [rbp-98h]

  *(_WORD *)&this->UVPOChanged = 1;
  v3 = vp;
  v4 = result;
  v5 = this;
  if ( vp->Flags & 0x30 )
  {
    if ( !(((vp->Flags & 0x30) - 16) & 0xFFFFFFDF) )
    {
      this->OrientationSet = 1;
      if ( (vp->Flags & 0x30) == 48 )
      {
        v6 = FLOAT_N1_0;
        v7 = 0.0;
        v8 = (float)vp->BufferHeight;
      }
      else
      {
        v6 = *(float *)&FLOAT_1_0;
        v8 = 0.0;
        v7 = (float)vp->BufferWidth;
      }
      this->Orient2D.M[0][3] = v7;
      this->Orient2D.M[1][0] = v6;
      this->Orient2D.M[1][3] = v8;
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
    memset(&this->Orient3D, 0, 0x40ui64);
    v5->Orient3D.M[0][0] = 1.0;
    v5->Orient3D.M[1][1] = 1.0;
    v5->Orient3D.M[2][2] = 1.0;
    v5->Orient3D.M[3][3] = 1.0;
  }
  v9 = Scaleform::Render::operator*(&resulta, &v5->User, &v5->Orient2D);
  v10 = Scaleform::Render::operator*(&v53, &v5->View2D, v9);
  *(_QWORD *)&v4->BufferWidth = 0i64;
  *(_QWORD *)&v4->Left = 0i64;
  v11 = v10->M[0][0];
  v4->Height = 1;
  v4->Width = 1;
  v5->UserView.M[0][0] = v11;
  v12 = v10->M[0][1];
  *(_QWORD *)&v4->ScissorWidth = 0i64;
  v5->UserView.M[0][1] = v12;
  v13 = v10->M[0][2];
  *(_QWORD *)&v4->ScissorLeft = 0i64;
  v5->UserView.M[0][2] = v13;
  v5->UserView.M[0][3] = v10->M[0][3];
  v5->UserView.M[1][0] = v10->M[1][0];
  v5->UserView.M[1][1] = v10->M[1][1];
  v5->UserView.M[1][2] = v10->M[1][2];
  v5->UserView.M[1][3] = v10->M[1][3];
  v14 = v3->Left;
  v15 = v3->Top;
  v16 = v5->Orient2D.M[0][1];
  v17 = (__m128)LODWORD(v5->Orient2D.M[0][0]);
  v18 = v5->Orient2D.M[1][1];
  v19 = v5->Orient2D.M[0][1];
  v24 = v17;
  v27 = (__m128)LODWORD(v5->Orient2D.M[0][0]);
  v20 = v3->Flags;
  v21 = (__m128)LODWORD(v5->Orient2D.M[1][0]);
  v22 = v5->Orient2D.M[0][3];
  v23 = v5->Orient2D.M[1][3];
  LODWORD(v10) = v14 + v3->Width;
  v4->Flags = v20;
  v25 = v21;
  v28 = v21;
  v24.m128_f32[0] = (float)((float)(v17.m128_f32[0] * (float)v14) + (float)(v19 * (float)v15)) + v22;
  v25.m128_f32[0] = (float)((float)(v21.m128_f32[0] * (float)v14) + (float)(v18 * (float)v15)) + v23;
  v26 = (float)(v15 + v3->Height);
  v27.m128_f32[0] = (float)((float)(v27.m128_f32[0] * (float)(signed int)v10) + (float)(v16 * v26)) + v22;
  v28.m128_f32[0] = (float)((float)(v21.m128_f32[0] * (float)(signed int)v10) + (float)(v18 * v26)) + v23;
  if ( v24.m128_f32[0] >= v27.m128_f32[0] )
    v29 = v27;
  else
    v29 = v24;
  v30 = (signed int)v29.m128_f32[0];
  if ( (signed int)v29.m128_f32[0] != 0x80000000 && (float)v30 != v29.m128_f32[0] )
    v29.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v29, v29)) & 1 ^ 1) + v30);
  v4->Left = (signed int)v29.m128_f32[0];
  if ( v25.m128_f32[0] >= v28.m128_f32[0] )
    v31 = v28;
  else
    v31 = v25;
  v32 = (signed int)v31.m128_f32[0];
  if ( (signed int)v31.m128_f32[0] != 0x80000000 && (float)v32 != v31.m128_f32[0] )
    v31.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v31, v31)) & 1 ^ 1) + v32);
  v24.m128_f32[0] = v24.m128_f32[0] - v27.m128_f32[0];
  v33 = _mm_and_ps(v24, (__m128)(unsigned int)_xmm);
  v4->Top = (signed int)v31.m128_f32[0];
  v34 = (signed int)v33.m128_f32[0];
  if ( (signed int)v33.m128_f32[0] != 0x80000000 && (float)v34 != v33.m128_f32[0] )
    v33.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v33, v33)) & 1 ^ 1) + v34);
  v25.m128_f32[0] = v25.m128_f32[0] - v28.m128_f32[0];
  v35 = _mm_and_ps(v25, (__m128)(unsigned int)_xmm);
  v4->Width = (signed int)v33.m128_f32[0];
  v36 = (signed int)v35.m128_f32[0];
  if ( (signed int)v35.m128_f32[0] != 0x80000000 && (float)v36 != v35.m128_f32[0] )
    v35.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v35, v35)) & 1 ^ 1) + v36);
  v4->Height = (signed int)v35.m128_f32[0];
  if ( v20 & 4 )
  {
    v37 = v3->ScissorLeft;
    v38 = v3->ScissorTop;
    v40 = v17;
    v41 = v21;
    v39 = v37 + v3->ScissorWidth;
    v4->Flags = v20;
    v40.m128_f32[0] = (float)((float)(v17.m128_f32[0] * (float)v37) + (float)(v16 * (float)v38)) + v22;
    v41.m128_f32[0] = (float)((float)(v21.m128_f32[0] * (float)v37) + (float)(v18 * (float)v38)) + v23;
    v42 = (float)(v38 + v3->ScissorHeight);
    v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] * (float)v39) + (float)(v16 * v42)) + v22;
    v21.m128_f32[0] = (float)((float)(v21.m128_f32[0] * (float)v39) + (float)(v18 * v42)) + v23;
    if ( v40.m128_f32[0] >= v17.m128_f32[0] )
      v43 = v17;
    else
      v43 = v40;
    v44 = (signed int)v43.m128_f32[0];
    if ( (signed int)v43.m128_f32[0] != 0x80000000 && (float)v44 != v43.m128_f32[0] )
      v43.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v43, v43)) & 1 ^ 1) + v44);
    v4->ScissorLeft = (signed int)v43.m128_f32[0];
    if ( v41.m128_f32[0] >= v21.m128_f32[0] )
      v45 = v21;
    else
      v45 = v41;
    v46 = (signed int)v45.m128_f32[0];
    if ( (signed int)v45.m128_f32[0] != 0x80000000 && (float)v46 != v45.m128_f32[0] )
      v45.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v45, v45)) & 1 ^ 1) + v46);
    v40.m128_f32[0] = v40.m128_f32[0] - v17.m128_f32[0];
    v47 = _mm_and_ps(v40, (__m128)(unsigned int)_xmm);
    v4->ScissorTop = (signed int)v45.m128_f32[0];
    v48 = (signed int)v47.m128_f32[0];
    if ( (signed int)v47.m128_f32[0] != 0x80000000 && (float)v48 != v47.m128_f32[0] )
      v47.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v47, v47)) & 1 ^ 1) + v48);
    v41.m128_f32[0] = v41.m128_f32[0] - v21.m128_f32[0];
    v49 = _mm_and_ps(v41, (__m128)(unsigned int)_xmm);
    v4->ScissorWidth = (signed int)v47.m128_f32[0];
    v50 = (signed int)v49.m128_f32[0];
    if ( (signed int)v49.m128_f32[0] != 0x80000000 && (float)v50 != v49.m128_f32[0] )
      v49.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v49, v49)) & 1 ^ 1) + v50);
    v4->ScissorHeight = (signed int)v49.m128_f32[0];
  }
  v4->BufferWidth = v3->BufferWidth;
  v4->BufferHeight = v3->BufferHeight;
  return v4;
}th = v3->BufferWidth;
  v4->BufferHeight = v3->BufferHeight;
  return v4;
}

// File Line: 129
// RVA: 0x9EF3E0
void __fastcall Scaleform::Render::MatrixState::recalculateUVPOC(Scaleform::Render::MatrixState *this)
{
  Scaleform::Render::MatrixState *v1; // r13
  int v2; // er9
  int v3; // er12
  int v4; // ecx
  signed __int64 v5; // rbx
  int v6; // ebx
  int v7; // edi
  int v8; // er14
  int v9; // er15
  int v10; // esi
  int v11; // ebp
  int v12; // ecx
  int v13; // er12
  __m128i v14; // xmm0
  int v15; // eax
  Scaleform::Render::Matrix4x4<float> *v16; // rax
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
  Scaleform::Render::Matrix4x4<float> m1; // [rsp+20h] [rbp-118h]
  __m128 Dst; // [rsp+60h] [rbp-D8h]
  __m128 v37; // [rsp+70h] [rbp-C8h]
  __m128 v38; // [rsp+80h] [rbp-B8h]
  __m128 v39; // [rsp+90h] [rbp-A8h]

  v1 = this;
  if ( this->UVPOChanged )
  {
    v2 = this->ViewRect.x1;
    v3 = this->ViewRectOriginal.x1;
    if ( (v2 != v3
       || *(_QWORD *)&this->ViewRect.y1 != *(_QWORD *)&this->ViewRectOriginal.y1
       || this->ViewRect.y2 != this->ViewRectOriginal.y2)
      && ((v4 = this->ViewRectOriginal.x2, v4 != v3) || v1->ViewRectOriginal.y2 != v1->ViewRectOriginal.y1) )
    {
      v6 = v1->ViewRectOriginal.y1;
      v7 = v1->ViewRectOriginal.y2;
      v8 = v1->ViewRect.y1;
      v9 = v1->ViewRect.y2;
      v10 = (v2 + v1->ViewRect.x2) / 2 - (v4 + v3) / 2;
      v11 = (v9 + v8) / 2 - (v7 + v6) / 2;
      memset(&Dst, 0, 0x40ui64);
      v12 = v1->ViewRectOriginal.x2 - v3;
      v13 = v1->ViewRect.x1;
      v14 = _mm_cvtsi32_si128(v1->ViewRect.x2 - v13);
      v39.m128_i32[3] = 1065353216;
      v38.m128_i32[2] = 1065353216;
      Dst.m128_f32[0] = (float)v12 / COERCE_FLOAT(_mm_cvtepi32_ps(v14));
      v37.m128_f32[1] = (float)(v7 - v6) / (float)(v9 - v8);
      memset(&m1, 0, 0x40ui64);
      v15 = v1->ViewRect.x2 - v13;
      m1.M[0][0] = 1.0;
      m1.M[1][1] = 1.0;
      *(_QWORD *)&m1.M[2][2] = 1065353216i64;
      m1.M[3][3] = 1.0;
      LODWORD(m1.M[0][3]) = COERCE_UNSIGNED_INT((float)((float)v10 * 2.0) / (float)v15) ^ _xmm[0];
      v5 = (signed __int64)&v1->ViewRectCompensated3D;
      m1.M[1][3] = (float)((float)v11 * 2.0) / (float)(v9 - v8);
      Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(
        &v1->ViewRectCompensated3D,
        &m1,
        (Scaleform::Render::Matrix4x4<float> *)&Dst);
    }
    else
    {
      v5 = (signed __int64)&v1->ViewRectCompensated3D;
      *(_OWORD *)v5 = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[0][0];
      *(_OWORD *)(v5 + 16) = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[1][0];
      *(_OWORD *)(v5 + 32) = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[2][0];
      *(_OWORD *)(v5 + 48) = *(_OWORD *)&Scaleform::Render::Matrix4x4<float>::Identity.M[3][0];
    }
    v16 = Scaleform::Render::MatrixState::updateStereoProjection(v1, 1.0);
    v17 = *(__m128 *)&v1->User3D.M[0][0];
    v18 = *(__m128 *)&v1->User3D.M[1][0];
    v19 = *(__m128 *)(v5 + 32);
    v20 = *(__m128 *)(v5 + 48);
    v21 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), *(__m128 *)(v5 + 16)),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v1->User3D.M[1][0], v18, 0), *(__m128 *)v5)),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v1->User3D.M[1][0], v18, 170), v19)),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 255), v20));
    v22 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), *(__m128 *)(v5 + 16)),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v1->User3D.M[0][0], v17, 0), *(__m128 *)v5)),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v1->User3D.M[0][0], v17, 170), v19)),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), v20));
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix((Scaleform::Render::Matrix4x4<float> *)&Dst, &v1->Orient3D, v16);
    v23 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v37), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), Dst)),
              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v38)),
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 255), v39));
    v24 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v37), _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), Dst)),
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v38)),
            _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v39));
    v25 = *(__m128 *)&v1->View3D.M[0][0];
    v26 = *(__m128 *)&v1->View3D.M[1][0];
    v27 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v37), _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), Dst)),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v38)),
            _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v39));
    v28 = *(__m128 *)&v1->View3D.M[2][0];
    v29 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v37), _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), Dst)),
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v38)),
            _mm_mul_ps(_mm_shuffle_ps(v19, v19, 255), v39));
    v30 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v;
    v31 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v26),
                         _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v25)),
                       _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v28)),
                     _mm_and_ps(v24, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
    v32 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v26),
                         _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v25)),
                       _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v28)),
                     _mm_and_ps(v23, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
    LODWORD(v1->UVPO.M[0][0]) = _mm_cvtsi128_si32(v32);
    v33 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v26),
                         _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v25)),
                       _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v28)),
                     _mm_and_ps(v29, v30));
    LODWORD(v1->UVPO.M[0][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v32, 4));
    v34 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v26),
                         _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v25)),
                       _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v28)),
                     _mm_and_ps(v27, v30));
    LODWORD(v1->UVPO.M[0][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v32, 8));
    LODWORD(v1->UVPO.M[0][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v32, 12));
    LODWORD(v1->UVPO.M[1][0]) = _mm_cvtsi128_si32(v31);
    LODWORD(v1->UVPO.M[1][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v31, 4));
    LODWORD(v1->UVPO.M[1][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v31, 8));
    LODWORD(v1->UVPO.M[1][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v31, 12));
    LODWORD(v1->UVPO.M[2][0]) = _mm_cvtsi128_si32(v33);
    LODWORD(v1->UVPO.M[2][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v33, 4));
    LODWORD(v1->UVPO.M[2][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v33, 8));
    LODWORD(v1->UVPO.M[2][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v33, 12));
    LODWORD(v1->UVPO.M[3][0]) = _mm_cvtsi128_si32(v34);
    LODWORD(v1->UVPO.M[3][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v34, 4));
    LODWORD(v1->UVPO.M[3][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v34, 8));
    LODWORD(v1->UVPO.M[3][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v34, 12));
    v1->UVPOChanged = 0;
  }
}

// File Line: 156
// RVA: 0x963B10
void __fastcall Scaleform::Render::MatrixState::Copy(Scaleform::Render::MatrixState *this, Scaleform::Render::MatrixState *outmat, Scaleform::Render::MatrixState *inmat)
{
  Scaleform::Render::MatrixState *v3; // rsi
  Scaleform::Render::MatrixState *v4; // rbp
  int v5; // er8
  int v6; // ecx
  int v7; // eax
  int v8; // er8
  int v9; // edx
  int v10; // ecx
  Scaleform::Render::StereoImplBase *v11; // rcx
  Scaleform::Render::StereoImplBase *v12; // rcx
  Scaleform::Render::StereoImplBase *v13; // rdi
  Scaleform::RefCountImplCoreVtbl *v14; // rbx
  __int64 v15; // rax

  v3 = inmat;
  v4 = outmat;
  *(_OWORD *)&outmat->View2D.M[0][0] = *(_OWORD *)&inmat->View2D.M[0][0];
  *(_OWORD *)&outmat->View2D.M[1][0] = *(_OWORD *)&inmat->View2D.M[1][0];
  *(_OWORD *)&outmat->View3D.M[0][0] = *(_OWORD *)&inmat->View3D.M[0][0];
  *(_OWORD *)&outmat->View3D.M[1][0] = *(_OWORD *)&inmat->View3D.M[1][0];
  *(_OWORD *)&outmat->View3D.M[2][0] = *(_OWORD *)&inmat->View3D.M[2][0];
  *(_OWORD *)&outmat->Proj3D.M[0][0] = *(_OWORD *)&inmat->Proj3D.M[0][0];
  *(_OWORD *)&outmat->Proj3D.M[1][0] = *(_OWORD *)&inmat->Proj3D.M[1][0];
  *(_OWORD *)&outmat->Proj3D.M[2][0] = *(_OWORD *)&inmat->Proj3D.M[2][0];
  *(_OWORD *)&outmat->Proj3D.M[3][0] = *(_OWORD *)&inmat->Proj3D.M[3][0];
  *(_OWORD *)&outmat->Proj3DLeft.M[0][0] = *(_OWORD *)&inmat->Proj3DLeft.M[0][0];
  *(_OWORD *)&outmat->Proj3DLeft.M[1][0] = *(_OWORD *)&inmat->Proj3DLeft.M[1][0];
  *(_OWORD *)&outmat->Proj3DLeft.M[2][0] = *(_OWORD *)&inmat->Proj3DLeft.M[2][0];
  *(_OWORD *)&outmat->Proj3DLeft.M[3][0] = *(_OWORD *)&inmat->Proj3DLeft.M[3][0];
  *(_OWORD *)&outmat->Proj3DRight.M[0][0] = *(_OWORD *)&inmat->Proj3DRight.M[0][0];
  *(_OWORD *)&outmat->Proj3DRight.M[1][0] = *(_OWORD *)&inmat->Proj3DRight.M[1][0];
  *(_OWORD *)&outmat->Proj3DRight.M[2][0] = *(_OWORD *)&inmat->Proj3DRight.M[2][0];
  *(_OWORD *)&outmat->Proj3DRight.M[3][0] = *(_OWORD *)&inmat->Proj3DRight.M[3][0];
  *(_OWORD *)&outmat->User.M[0][0] = *(_OWORD *)&inmat->User.M[0][0];
  *(_OWORD *)&outmat->User.M[1][0] = *(_OWORD *)&inmat->User.M[1][0];
  *(_OWORD *)&outmat->User3D.M[0][0] = *(_OWORD *)&inmat->User3D.M[0][0];
  *(_OWORD *)&outmat->User3D.M[1][0] = *(_OWORD *)&inmat->User3D.M[1][0];
  *(_OWORD *)&outmat->Orient2D.M[0][0] = *(_OWORD *)&inmat->Orient2D.M[0][0];
  *(_OWORD *)&outmat->Orient2D.M[1][0] = *(_OWORD *)&inmat->Orient2D.M[1][0];
  *(_OWORD *)&outmat->Orient3D.M[0][0] = *(_OWORD *)&inmat->Orient3D.M[0][0];
  *(_OWORD *)&outmat->Orient3D.M[1][0] = *(_OWORD *)&inmat->Orient3D.M[1][0];
  *(_OWORD *)&outmat->Orient3D.M[2][0] = *(_OWORD *)&inmat->Orient3D.M[2][0];
  *(_OWORD *)&outmat->Orient3D.M[3][0] = *(_OWORD *)&inmat->Orient3D.M[3][0];
  v5 = inmat->ViewRectOriginal.y2;
  v6 = v3->ViewRectOriginal.y1;
  v7 = v3->ViewRectOriginal.x1;
  outmat->ViewRectOriginal.x2 = v3->ViewRectOriginal.x2;
  outmat->ViewRectOriginal.x1 = v7;
  outmat->ViewRectOriginal.y1 = v6;
  outmat->ViewRectOriginal.y2 = v5;
  v8 = v3->ViewRect.y2;
  v9 = v3->ViewRect.x2;
  v10 = v3->ViewRect.y1;
  v4->ViewRect.x1 = v3->ViewRect.x1;
  v4->ViewRect.x2 = v9;
  v4->ViewRect.y1 = v10;
  v4->ViewRect.y2 = v8;
  v4->UserView.M[0][0] = v3->UserView.M[0][0];
  v4->UserView.M[0][1] = v3->UserView.M[0][1];
  v4->UserView.M[0][2] = v3->UserView.M[0][2];
  v4->UserView.M[0][3] = v3->UserView.M[0][3];
  v4->UserView.M[1][0] = v3->UserView.M[1][0];
  v4->UserView.M[1][1] = v3->UserView.M[1][1];
  v4->UserView.M[1][2] = v3->UserView.M[1][2];
  v4->UserView.M[1][3] = v3->UserView.M[1][3];
  v4->UVPO.M[0][0] = v3->UVPO.M[0][0];
  v4->UVPO.M[0][1] = v3->UVPO.M[0][1];
  v4->UVPO.M[0][2] = v3->UVPO.M[0][2];
  v4->UVPO.M[0][3] = v3->UVPO.M[0][3];
  v4->UVPO.M[1][0] = v3->UVPO.M[1][0];
  v4->UVPO.M[1][1] = v3->UVPO.M[1][1];
  v4->UVPO.M[1][2] = v3->UVPO.M[1][2];
  v4->UVPO.M[1][3] = v3->UVPO.M[1][3];
  v4->UVPO.M[2][0] = v3->UVPO.M[2][0];
  v4->UVPO.M[2][1] = v3->UVPO.M[2][1];
  v4->UVPO.M[2][2] = v3->UVPO.M[2][2];
  v4->UVPO.M[2][3] = v3->UVPO.M[2][3];
  v4->UVPO.M[3][0] = v3->UVPO.M[3][0];
  v4->UVPO.M[3][1] = v3->UVPO.M[3][1];
  v4->UVPO.M[3][2] = v3->UVPO.M[3][2];
  v4->UVPO.M[3][3] = v3->UVPO.M[3][3];
  v4->ViewRectCompensated3D.M[0][0] = v3->ViewRectCompensated3D.M[0][0];
  v4->ViewRectCompensated3D.M[0][1] = v3->ViewRectCompensated3D.M[0][1];
  v4->ViewRectCompensated3D.M[0][2] = v3->ViewRectCompensated3D.M[0][2];
  v4->ViewRectCompensated3D.M[0][3] = v3->ViewRectCompensated3D.M[0][3];
  v4->ViewRectCompensated3D.M[1][0] = v3->ViewRectCompensated3D.M[1][0];
  v4->ViewRectCompensated3D.M[1][1] = v3->ViewRectCompensated3D.M[1][1];
  v4->ViewRectCompensated3D.M[1][2] = v3->ViewRectCompensated3D.M[1][2];
  v4->ViewRectCompensated3D.M[1][3] = v3->ViewRectCompensated3D.M[1][3];
  v4->ViewRectCompensated3D.M[2][0] = v3->ViewRectCompensated3D.M[2][0];
  v4->ViewRectCompensated3D.M[2][1] = v3->ViewRectCompensated3D.M[2][1];
  v4->ViewRectCompensated3D.M[2][2] = v3->ViewRectCompensated3D.M[2][2];
  v4->ViewRectCompensated3D.M[2][3] = v3->ViewRectCompensated3D.M[2][3];
  v4->ViewRectCompensated3D.M[3][0] = v3->ViewRectCompensated3D.M[3][0];
  v4->ViewRectCompensated3D.M[3][1] = v3->ViewRectCompensated3D.M[3][1];
  v4->ViewRectCompensated3D.M[3][2] = v3->ViewRectCompensated3D.M[3][2];
  v4->ViewRectCompensated3D.M[3][3] = v3->ViewRectCompensated3D.M[3][3];
  v4->UVPOChanged = 1;
  v4->OrientationSet = v3->OrientationSet;
  if ( v3->S3DImpl.pObject )
  {
    v11 = v3->S3DImpl.pObject;
    if ( v11 )
      _InterlockedExchangeAdd(&v11->RefCount, 1u);
    v12 = v4->S3DImpl.pObject;
    if ( v12 && !_InterlockedDecrement(&v12->RefCount) && v12 )
      v12->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, 1u);
    v13 = v3->S3DImpl.pObject;
    v4->S3DImpl.pObject = v13;
    v14 = v13->vfptr;
    v15 = ((__int64 (*)(void))v3->S3DImpl.pObject->vfptr[2].__vecDelDtor)();
    v14[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, v15);
  }
  v4->S3DDisplay = v3->S3DDisplay;
  v4->pHAL = v3->pHAL;
}

// File Line: 195
// RVA: 0x9648F0
void __fastcall Scaleform::Render::MatrixState::CopyFrom(Scaleform::Render::MatrixState *this, Scaleform::Render::MatrixState *state)
{
  ((void (__fastcall *)(Scaleform::Render::MatrixState *, Scaleform::Render::MatrixState *, Scaleform::Render::MatrixState *))this->vfptr[8].__vecDelDtor)(
    this,
    this,
    state);
}

// File Line: 200
// RVA: 0x965260
void __fastcall Scaleform::Render::MatrixState::CopyTo(Scaleform::Render::MatrixState *this, Scaleform::Render::MatrixState *state)
{
  ((void (__fastcall *)(Scaleform::Render::MatrixState *, Scaleform::Render::MatrixState *, Scaleform::Render::MatrixState *))this->vfptr[8].__vecDelDtor)(
    this,
    state,
    this);
}

// File Line: 205
// RVA: 0x9FAAA0
Scaleform::Render::Matrix4x4<float> *__fastcall Scaleform::Render::MatrixState::updateStereoProjection(Scaleform::Render::MatrixState *this, float factor)
{
  Scaleform::Render::StereoDisplay v2; // edx
  Scaleform::Render::StereoImplBase *v3; // rax
  __m128 v4; // xmm2
  Scaleform::Render::Matrix4x4<float> *v5; // rbx
  float v6; // ST28_4
  Scaleform::Render::Matrix4x4<float> *v8; // rbx
  float v9; // ST28_4

  v2 = this->S3DDisplay;
  if ( v2 == StereoCenter )
    return &this->Proj3D;
  v3 = this->S3DImpl.pObject;
  if ( !v3 )
    return &this->Proj3D;
  v4 = _mm_xor_ps((__m128)LODWORD(this->View3D.M[2][3]), *(__m128 *)_xmm);
  if ( v2 == 1 )
  {
    v5 = &this->Proj3DLeft;
    v6 = factor;
    ((void (__fastcall *)(Scaleform::Render::StereoImplBase *, Scaleform::Render::Matrix4x4<float> *, Scaleform::RefCountImplCoreVtbl *, Scaleform::Render::Matrix4x4<float> *, _QWORD, float))v3->vfptr[3].__vecDelDtor)(
      v3,
      &this->Proj3D,
      v3->vfptr,
      &this->Proj3DLeft,
      0i64,
      COERCE_FLOAT(LODWORD(v6)));
    return v5;
  }
  if ( v2 != 2 )
    return &this->Proj3D;
  v8 = &this->Proj3DRight;
  v9 = factor;
  ((void (__fastcall *)(Scaleform::Render::StereoImplBase *, Scaleform::Render::Matrix4x4<float> *, Scaleform::RefCountImplCoreVtbl *, _QWORD, Scaleform::Render::Matrix4x4<float> *, float))v3->vfptr[3].__vecDelDtor)(
    v3,
    &this->Proj3D,
    v3->vfptr,
    0i64,
    &this->Proj3DRight,
    COERCE_FLOAT(LODWORD(v9)));
  return v8;
}

// File Line: 257
// RVA: 0x98BC20
void __fastcall Scaleform::Render::StereoImplBase::GetStereoProj(Scaleform::Render::StereoImplBase *this, Scaleform::Render::Matrix4x4<float> *original, float screenDist, Scaleform::Render::Matrix4x4<float> *left, Scaleform::Render::Matrix4x4<float> *right, float factor)
{
  Scaleform::Render::Matrix4x4<float> *v6; // rdi
  Scaleform::Render::StereoImplBase *v7; // rbx
  Scaleform::Render::Matrix4x4<float> *v8; // rsi
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
  Scaleform::Render::Matrix4x4<float> v37; // [rsp+60h] [rbp-98h]
  __int64 v38; // [rsp+A0h] [rbp-58h]
  __m128 v39; // [rsp+A8h] [rbp-50h]
  __m128 v40; // [rsp+B8h] [rbp-40h]
  __m128 v41; // [rsp+C8h] [rbp-30h]
  Scaleform::Render::Matrix4x4<float> m2; // [rsp+D8h] [rbp-20h]
  _DWORD *v43; // [rsp+1E8h] [rbp+F0h]

  v6 = original;
  v7 = this;
  v8 = left;
  memset(&v38, 0, 0x40ui64);
  v37.M[3][2] = 1.0;
  v39.m128_i32[1] = 1065353216;
  v40.m128_i32[2] = 1065353216;
  v41.m128_i32[3] = 1065353216;
  memset(&m2, 0, 0x40ui64);
  m2.M[0][0] = 1.0;
  v9 = *(float *)&right * v7->S3DParams.Distortion;
  m2.M[1][1] = 1.0;
  m2.M[2][2] = 1.0;
  m2.M[3][3] = 1.0;
  v10 = (float)(v9 * v7->S3DParams.EyeSeparationCm) / v7->S3DParams.DisplayWidthCm;
  LODWORD(v11) = COERCE_UNSIGNED_INT((float)((float)(v10 * screenDist) * v6->M[3][2]) / v6->M[0][0]) ^ _xmm[0];
  if ( v11 < 0.0 )
    LODWORD(v11) ^= _xmm[0];
  v12 = v41;
  v13 = v40;
  v14 = v39;
  if ( v8 )
  {
    m2.M[0][3] = v11;
    HIDWORD(v38) = LODWORD(v10) ^ _xmm[0];
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v37, v6, &m2);
    v15 = *(__m128 *)&v37.M[0][0];
    v16 = *(__m128 *)&v37.M[1][0];
    v17 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), *(__m128 *)&v37.M[1][0]);
    v18 = *(__m128 *)&v37.M[1][2];
    v19 = *(__m128 *)&v37.M[2][2];
    v20 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(*(__m128 *)&v37.M[3][2], *(__m128 *)&v37.M[3][2], 85),
                           *(__m128 *)&v37.M[1][0]),
                         _mm_mul_ps(
                           _mm_shuffle_ps(*(__m128 *)&v37.M[3][2], *(__m128 *)&v37.M[3][2], 0),
                           *(__m128 *)&v37.M[0][0])),
                       _mm_mul_ps(
                         _mm_shuffle_ps(*(__m128 *)&v37.M[3][2], *(__m128 *)&v37.M[3][2], 170),
                         *(__m128 *)&v37.M[1][2])),
                     _mm_mul_ps(
                       _mm_shuffle_ps(*(__m128 *)&v37.M[3][2], *(__m128 *)&v37.M[3][2], 255),
                       *(__m128 *)&v37.M[2][2]));
    v21 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), *(__m128 *)&v37.M[0][0]);
    v22 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), *(__m128 *)&v37.M[1][2]);
    LODWORD(v8->M[0][0]) = _mm_cvtsi128_si32(v20);
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
    LODWORD(v8->M[0][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v20, 4));
    LODWORD(v8->M[0][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v20, 8));
    LODWORD(v8->M[0][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v20, 12));
    LODWORD(v8->M[1][0]) = _mm_cvtsi128_si32(v23);
    LODWORD(v8->M[1][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v23, 4));
    LODWORD(v8->M[1][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v23, 8));
    LODWORD(v8->M[1][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v23, 12));
    LODWORD(v8->M[2][0]) = _mm_cvtsi128_si32(v24);
    LODWORD(v8->M[2][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v24, 4));
    LODWORD(v8->M[2][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v24, 8));
    LODWORD(v8->M[2][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v24, 12));
    LODWORD(v8->M[3][0]) = _mm_cvtsi128_si32(v25);
    LODWORD(v8->M[3][1]) = _mm_cvtsi128_si32(_mm_srli_si128(v25, 4));
    LODWORD(v8->M[3][2]) = _mm_cvtsi128_si32(_mm_srli_si128(v25, 8));
    LODWORD(v8->M[3][3]) = _mm_cvtsi128_si32(_mm_srli_si128(v25, 12));
  }
  if ( v43 )
  {
    *((float *)&v38 + 1) = v10;
    LODWORD(m2.M[0][3]) = LODWORD(v11) ^ _xmm[0];
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v37, v6, &m2);
    v26 = *(__m128 *)&v37.M[0][0];
    v27 = *(__m128 *)&v37.M[1][0];
    v28 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), *(__m128 *)&v37.M[1][0]);
    v29 = *(__m128 *)&v37.M[1][2];
    v30 = *(__m128 *)&v37.M[2][2];
    v31 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(*(__m128 *)&v37.M[3][2], *(__m128 *)&v37.M[3][2], 85),
                           *(__m128 *)&v37.M[1][0]),
                         _mm_mul_ps(
                           _mm_shuffle_ps(*(__m128 *)&v37.M[3][2], *(__m128 *)&v37.M[3][2], 0),
                           *(__m128 *)&v37.M[0][0])),
                       _mm_mul_ps(
                         _mm_shuffle_ps(*(__m128 *)&v37.M[3][2], *(__m128 *)&v37.M[3][2], 170),
                         *(__m128 *)&v37.M[1][2])),
                     _mm_mul_ps(
                       _mm_shuffle_ps(*(__m128 *)&v37.M[3][2], *(__m128 *)&v37.M[3][2], 255),
                       *(__m128 *)&v37.M[2][2]));
    v32 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), *(__m128 *)&v37.M[0][0]);
    v33 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), *(__m128 *)&v37.M[1][2]);
    *v43 = _mm_cvtsi128_si32(v31);
    v43[1] = _mm_cvtsi128_si32(_mm_srli_si128(v31, 4));
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
    v43[2] = _mm_cvtsi128_si32(_mm_srli_si128(v31, 8));
    v43[3] = _mm_cvtsi128_si32(_mm_srli_si128(v31, 12));
    v43[4] = _mm_cvtsi128_si32(v34);
    v43[5] = _mm_cvtsi128_si32(_mm_srli_si128(v34, 4));
    v43[6] = _mm_cvtsi128_si32(_mm_srli_si128(v34, 8));
    v43[7] = _mm_cvtsi128_si32(_mm_srli_si128(v34, 12));
    v43[8] = _mm_cvtsi128_si32(v36);
    v43[9] = _mm_cvtsi128_si32(_mm_srli_si128(v36, 4));
    v43[10] = _mm_cvtsi128_si32(_mm_srli_si128(v36, 8));
    v43[11] = _mm_cvtsi128_si32(_mm_srli_si128(v36, 12));
    v43[12] = _mm_cvtsi128_si32(v35);
    v43[13] = _mm_cvtsi128_si32(_mm_srli_si128(v35, 4));
    v43[14] = _mm_cvtsi128_si32(_mm_srli_si128(v35, 8));
    v43[15] = _mm_cvtsi128_si32(_mm_srli_si128(v35, 12));
  }
}

// File Line: 288
// RVA: 0x984D50
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::MatrixState::GetFullViewportMatrix(Scaleform::Render::MatrixState *this, Scaleform::Render::Size<int> *rtSize)
{
  return &this->FullViewportMVP;
}

// File Line: 294
// RVA: 0x98E6E0
Scaleform::Render::Matrix4x4<float> *__fastcall Scaleform::Render::MatrixState::GetUVP(Scaleform::Render::MatrixState *this)
{
  Scaleform::Render::MatrixState *v1; // rbx

  v1 = this;
  ((void (*)(void))this->vfptr[9].__vecDelDtor)();
  return &v1->UVPO;
}

// File Line: 334
// RVA: 0x93D6A0
void __fastcall Scaleform::Render::HAL::HAL(Scaleform::Render::HAL *this, Scaleform::Render::ThreadCommandQueue *commandQueue)
{
  Scaleform::Render::ThreadCommandQueue *v2; // r8
  Scaleform::Render::HALNotify *v3; // rdx
  Scaleform::Render::RenderQueue *v4; // rax
  Scaleform::Render::ProfileViews *v5; // [rsp+28h] [rbp+10h]
  Scaleform::ArrayLH<Scaleform::Render::Matrix3x4<float>,2,Scaleform::ArrayConstPolicy<0,8,1> > *v6; // [rsp+28h] [rbp+10h]
  Scaleform::ArrayLH<Scaleform::Render::Matrix4x4<float>,2,Scaleform::ArrayConstPolicy<0,8,1> > *v7; // [rsp+28h] [rbp+10h]
  Scaleform::ArrayLH<Scaleform::Render::HAL::BlendStackEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *v8; // [rsp+28h] [rbp+10h]
  Scaleform::ArrayLH<Scaleform::Render::HAL::MaskStackEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *v9; // [rsp+28h] [rbp+10h]
  Scaleform::ArrayLH<Scaleform::Render::HAL::RenderTargetEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *v10; // [rsp+28h] [rbp+10h]
  Scaleform::ArrayLH<Scaleform::Render::HAL::FilterStackEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *v11; // [rsp+28h] [rbp+10h]
  Scaleform::ListAllocLH_POD<Scaleform::Render::BeginDisplayData,127,2> *v12; // [rsp+28h] [rbp+10h]
  Scaleform::ArrayLH<Scaleform::Render::UserDataState::Data const *,2,Scaleform::ArrayConstPolicy<0,8,1> > *v13; // [rsp+28h] [rbp+10h]

  v2 = commandQueue;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,65>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::HAL,65>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::HAL::`vftable';
  this->FullSceneBlendTarget.pObject = 0i64;
  this->HALState = 0;
  this->CurrentPass = 3;
  v3 = (Scaleform::Render::HALNotify *)&this->HALState;
  if ( this == (Scaleform::Render::HAL *)-32i64 )
    v3 = 0i64;
  this->NotifyList.Root.pPrev = v3;
  this->NotifyList.Root.pNext = v3;
  this->Matrices.pObject = 0i64;
  v5 = &this->Profiler;
  v5->vfptr = (Scaleform::Render::ProfileViewsVtbl *)&Scaleform::Render::ProfileViews::`vftable';
  v5->PMDefault.vfptr = (Scaleform::Render::ProfileModifierVtbl *)&Scaleform::Render::ProfileModifier::`vftable';
  v5->PMDefault.FillFlags = 0;
  *(_QWORD *)&this->AccumulatedStats.Primitives = 0i64;
  *(_QWORD *)&this->AccumulatedStats.Triangles = 0i64;
  *(_QWORD *)&this->AccumulatedStats.RTChanges = 0i64;
  *(_QWORD *)&this->VMCFlags = 0i64;
  this->RenderThreadID = 0i64;
  this->pHeap = 0i64;
  this->pRTCommandQueue = v2;
  v4 = &this->Queue;
  v4->QueueSize = 0;
  v4->pQueue = 0i64;
  *(_QWORD *)&v4->QueueHead = 0i64;
  v4->HeadReserved = 0;
  this->pRenderBufferManager.pObject = 0i64;
  this->QueueProcessor.pHAL = this;
  this->QueueProcessor.Caches.LockFlags = 0;
  this->QueueProcessor.Caches.pCaches[0] = 0i64;
  this->QueueProcessor.Caches.pCaches[1] = 0i64;
  this->QueueProcessor.Queue = &this->Queue;
  *(_QWORD *)&this->QueueProcessor.QueueMode = 0i64;
  this->QueueProcessor.QueueEmitFilter = 0;
  this->QueueProcessor.CurrentItem.pQueue = 0i64;
  this->QueueProcessor.CurrentItem.QueuePos = 0;
  this->QueueProcessor.PrepareItemBuffer.pItem = 0i64;
  this->QueueProcessor.EmitItemBuffer.pItem = 0i64;
  v6 = &this->ViewMatrix3DStack;
  *(_OWORD *)&v6->Data.Data = 0ui64;
  v6->Data.Policy.Capacity = 0i64;
  v7 = &this->ProjectionMatrix3DStack;
  *(_OWORD *)&v7->Data.Data = 0ui64;
  v7->Data.Policy.Capacity = 0i64;
  this->CurrentBlendState.Mode = 0;
  *(_WORD *)&this->CurrentBlendState.SourceAc = 0;
  this->CurrentBlendState.BlendEnable = 0;
  *(_QWORD *)&this->CurrentDepthStencilState = 1i64;
  *(_DWORD *)&this->StencilChecked = 0;
  *(_QWORD *)&this->NextSceneRasterMode = 0i64;
  this->AppliedSceneRasterMode = 0;
  v8 = &this->BlendModeStack;
  *(_OWORD *)&v8->Data.Data = 0ui64;
  v8->Data.Policy.Capacity = 0i64;
  v9 = &this->MaskStack;
  *(_OWORD *)&v9->Data.Data = 0ui64;
  v9->Data.Policy.Capacity = 0i64;
  this->MaskStackTop = 0;
  v10 = &this->RenderTargetStack;
  *(_OWORD *)&v10->Data.Data = 0ui64;
  v10->Data.Policy.Capacity = 0i64;
  v11 = &this->FilterStack;
  *(_OWORD *)&v11->Data.Data = 0ui64;
  v11->Data.Policy.Capacity = 0i64;
  *(_QWORD *)&this->CacheableIndex = -1i64;
  this->CacheablePrepStart = -1;
  v12 = &this->BeginDisplayDataList;
  *(_OWORD *)&v12->FirstPage = 0ui64;
  v12->NumElementsInPage = 127;
  v12->FirstEmptySlot = 0i64;
  v12->pHeapOrPtr = v12;
  v13 = &this->UserDataStack;
  *(_OWORD *)&v13->Data.Data = 0ui64;
  v13->Data.Policy.Capacity = 0i64;
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
  Scaleform::Render::HALInitParams *v2; // rbp
  Scaleform::Render::HAL *v3; // rdi
  __int64 v4; // rbx
  Scaleform::Render::MatrixState *v5; // rsi
  Scaleform::Render::StereoImplBase *v6; // rcx
  void *v7; // rax

  v2 = params;
  v3 = this;
  ((void (__cdecl *)(Scaleform::Render::HAL *))this->vfptr[2].__vecDelDtor)(this);
  v4 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
         Scaleform::Memory::pGlobalHeap,
         40i64);
  if ( v4 )
  {
    *(_QWORD *)v4 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v4 + 8) = 1;
    *(_QWORD *)v4 = &Scaleform::RefCountImpl::`vftable';
    *(_QWORD *)v4 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
    *(_QWORD *)v4 = &Scaleform::RefCountBase<Scaleform::Render::StereoImplBase,2>::`vftable';
    *(_QWORD *)v4 = &Scaleform::Render::StereoImplBase::`vftable';
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
  v5 = v3->Matrices.pObject;
  v6 = v5->S3DImpl.pObject;
  if ( v6 && !_InterlockedDecrement(&v6->RefCount) && v6 )
    v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
  v5->S3DImpl.pObject = (Scaleform::Render::StereoImplBase *)v4;
  v3->VMCFlags = v2->ConfigFlags;
  v7 = v2->RenderThreadId;
  v3->RenderThreadID = v7;
  if ( !v7 )
    v3->RenderThreadID = UFG::qGetCurrentThreadID();
  return Scaleform::Render::RenderQueue::Initialize(&v3->Queue, v2->RenderQueueSize);
}

// File Line: 364
// RVA: 0x9E8490
void __fastcall Scaleform::Render::HAL::initMatrices(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rbx
  Scaleform::Render::MatrixState *v2; // rax
  Scaleform::Render::MatrixState *v3; // rax
  Scaleform::Render::MatrixState *v4; // rdi
  Scaleform::Render::MatrixState *v5; // rcx
  int v6; // [rsp+48h] [rbp+10h]
  Scaleform::Render::MatrixState *v7; // [rsp+50h] [rbp+18h]

  v1 = this;
  v6 = 65;
  v2 = (Scaleform::Render::MatrixState *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::HAL *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           704i64,
                                           &v6,
                                           -2i64);
  v7 = v2;
  if ( v2 )
  {
    Scaleform::Render::MatrixState::MatrixState(v2, v1);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  v5 = v1->Matrices.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount) && v5 )
    v5->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
  v1->Matrices.pObject = v4;
}

// File Line: 370
// RVA: 0x9F2390
char __fastcall Scaleform::Render::HAL::shutdownHAL(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rsi
  Scaleform::Render::HALNotify *i; // rcx
  signed __int64 v3; // rax
  Scaleform::Render::HALNotify *v4; // rbx

  v1 = this;
  if ( this->HALState & 1 )
  {
    for ( i = this->NotifyList.Root.pNext; ; i = v4 )
    {
      v3 = (signed __int64)(v1 == (Scaleform::Render::HAL *)-32i64 ? 0i64 : &v1->HALState);
      if ( i == (Scaleform::Render::HALNotify *)v3 )
        break;
      v4 = i->pNext;
      i->vfptr->OnHALEvent(i, HAL_Shutdown);
    }
    if ( v1->Queue.pQueue )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->Queue.pQueue = 0i64;
    }
    v1->HALState = 0;
  }
  return 1;
}

// File Line: 388
// RVA: 0x95A580
char __fastcall Scaleform::Render::HAL::BeginFrame(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rbx
  void *v2; // rax
  unsigned int v3; // eax
  __int64 v5; // rax
  Scaleform::Render::RenderQueueProcessor *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax

  v1 = this;
  v2 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 1u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v2 + 16i64))(v2, "Scaleform::Render::HAL::BeginFrame");
  v3 = v1->HALState;
  if ( !(v3 & 1) || _bittest((const signed int *)&v3, 0xDu) )
    return 0;
  v1->HALState = v3 | 2;
  if ( ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[65].__vecDelDtor)(v1) )
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[65].__vecDelDtor)(v1);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 8i64))(v5);
  }
  v6 = (Scaleform::Render::RenderQueueProcessor *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[64].__vecDelDtor)(v1);
  Scaleform::Render::RenderQueueProcessor::BeginFrame(v6);
  v7 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[62].__vecDelDtor)(v1);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 24i64))(v7);
  v8 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[61].__vecDelDtor)(v1);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 72i64))(v8);
  return 1;
}

// File Line: 409
// RVA: 0x9705D0
void __fastcall Scaleform::Render::HAL::EndFrame(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rbx
  void *v2; // rdi
  __int64 v3; // rax
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rax

  v1 = this;
  v2 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 1u);
  if ( (v1->HALState & 3) == 3 )
  {
    if ( ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[65].__vecDelDtor)(v1) )
    {
      v3 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[65].__vecDelDtor)(v1);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 16i64))(v3);
    }
    v4 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[19].__vecDelDtor)(v1);
    if ( v4 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 24i64))(v4);
    v5 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[62].__vecDelDtor)(v1);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 32i64))(v5);
    v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[61].__vecDelDtor)(v1);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 80i64))(v6);
    v1->HALState &= 0xFFFFFFFD;
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
}

// File Line: 438
// RVA: 0x96FEA0
void __fastcall Scaleform::Render::HALBeginDisplayItem::EmitToHAL(Scaleform::Render::HALBeginDisplayItem *this, Scaleform::Render::RenderQueueItem *item, Scaleform::Render::RenderQueueProcessor *qp)
{
  qp->pHAL->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)qp->pHAL, (unsigned int)item->Data);
}

// File Line: 448
// RVA: 0x96FEB0
void __fastcall Scaleform::Render::HALEndDisplayItem::EmitToHAL(Scaleform::Render::HALEndDisplayItem *this, Scaleform::Render::RenderQueueItem *__formal, Scaleform::Render::RenderQueueProcessor *qp)
{
  qp->pHAL->vfptr[12].__vecDelDtor((Scaleform::RefCountImplCore *)qp->pHAL, (unsigned int)__formal);
}

// File Line: 452
// RVA: 0x159C7F0
__int64 dynamic_initializer_for__Scaleform::Render::HALBeginDisplayItem::Instance__()
{
  Scaleform::Render::HALBeginDisplayItem::Instance.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::HALBeginDisplayItem::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::HALBeginDisplayItem::Instance__);
}

// File Line: 453
// RVA: 0x159C820
__int64 dynamic_initializer_for__Scaleform::Render::HALEndDisplayItem::Instance__()
{
  Scaleform::Render::HALEndDisplayItem::Instance.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::HALEndDisplayItem::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::HALEndDisplayItem::Instance__);
}

// File Line: 456
// RVA: 0x95A430
void __fastcall Scaleform::Render::HAL::BeginDisplay(Scaleform::Render::HAL *this, __int64 backgroundColor, Scaleform::Render::Viewport *vpin)
{
  int v3; // ebx
  int v4; // ebp
  int v5; // esi
  int v6; // edi
  int v7; // er12
  unsigned int v8; // ST28_4
  int v9; // er13
  int v10; // er14
  int v11; // ST20_4
  int v12; // er15
  int v13; // ST24_4
  Scaleform::Render::FenceFrame *v14; // rax
  Scaleform::Render::HALBeginDisplayItem *v15; // [rsp+30h] [rbp-88h]
  Scaleform::Render::FenceFrame *v16; // [rsp+38h] [rbp-80h]
  Scaleform::ListNode<Scaleform::Render::FenceFrame> v17; // [rsp+40h] [rbp-78h]
  Scaleform::Render::HAL *v18; // [rsp+C0h] [rbp+8h]
  int v19; // [rsp+D8h] [rbp+20h]

  v18 = this;
  if ( this->HALState & 2 )
  {
    v3 = *(_DWORD *)backgroundColor;
    v4 = vpin->Left;
    v5 = vpin->BufferHeight;
    v6 = vpin->BufferWidth;
    v7 = vpin->Height;
    v8 = vpin->Flags;
    v9 = vpin->ScissorLeft;
    v19 = vpin->ScissorTop;
    v10 = vpin->Top;
    v11 = vpin->ScissorWidth;
    v12 = vpin->Width;
    v13 = vpin->ScissorHeight;
    v14 = Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2>>::allocate((Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> > *)&this->BeginDisplayDataList);
    v14->0 = v17;
    LODWORD(v14->RSContext) = v3;
    HIDWORD(v14->RSContext) = v6;
    *(_DWORD *)&v14->WrappedAround = v5;
    *((_DWORD *)&v14->WrappedAround + 1) = v4;
    LODWORD(v14->Fences.Data.Data) = v10;
    HIDWORD(v14->Fences.Data.Data) = v12;
    LODWORD(v14->Fences.Data.Size) = v7;
    HIDWORD(v14->Fences.Data.Size) = v9;
    LODWORD(v14->Fences.Data.Policy.Capacity) = v19;
    HIDWORD(v14->Fences.Data.Policy.Capacity) = v11;
    LODWORD(v14->FrameEndFence.pObject) = v13;
    HIDWORD(v14->FrameEndFence.pObject) = v8;
    if ( v18->HALState & 4 )
    {
      v16 = v14;
      v15 = &Scaleform::Render::HALBeginDisplayItem::Instance;
      v18->vfptr[33].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, (unsigned int)&v15);
    }
    else
    {
      ((void (*)(void))v18->vfptr[11].__vecDelDtor)();
    }
  }
}

// File Line: 476
// RVA: 0x970580
void __fastcall Scaleform::Render::HAL::EndDisplay(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rbx
  Scaleform::Render::HALEndDisplayItem *v2; // [rsp+20h] [rbp-18h]
  __int64 v3; // [rsp+28h] [rbp-10h]

  v1 = this;
  if ( this->HALState & 0x400 )
  {
    ((void (*)(void))this->vfptr[8].__vecDelDtor)();
    ((void (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[12].__vecDelDtor)(v1);
  }
  else
  {
    v3 = 0i64;
    v2 = &Scaleform::Render::HALEndDisplayItem::Instance;
    this->vfptr[33].__vecDelDtor((Scaleform::RefCountImplCore *)this, (unsigned int)&v2);
  }
}

// File Line: 492
// RVA: 0x9CF260
void __fastcall Scaleform::Render::HAL::beginDisplay(Scaleform::Render::HAL *this, Scaleform::Render::BeginDisplayData *data)
{
  Scaleform::Render::BeginDisplayData *v2; // rsi
  Scaleform::Render::HAL *v3; // rdi
  void *v4; // rax
  unsigned int v5; // eax
  int v6; // ebx
  bool v7; // zf
  int *v8; // rax
  Scaleform::Render::Viewport *v9; // r9
  __int64 v10; // r8
  __int64 v11; // r9
  __int64 v12; // rax
  Scaleform::Render::RenderTarget *v13; // rcx
  Scaleform::Render::RenderTarget *v14; // r14
  Scaleform::RefCountImplCoreVtbl *v15; // rax
  float v16; // xmm1_4
  float v17; // xmm0_4
  Scaleform::RefCountImplCoreVtbl *v18; // rax
  __int64 v19; // [rsp+30h] [rbp-58h]
  float v20; // [rsp+38h] [rbp-50h]
  float v21; // [rsp+3Ch] [rbp-4Ch]
  char v22; // [rsp+40h] [rbp-48h]
  int v23; // [rsp+90h] [rbp+8h]
  int v24; // [rsp+94h] [rbp+Ch]
  int v25; // [rsp+A0h] [rbp+18h]

  v2 = data;
  v3 = this;
  v4 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 4u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v4 + 16i64))(v4, "Scaleform::Render::HAL::beginDisplay");
  v5 = v3->HALState;
  if ( v5 & 2 )
  {
    v3->HALState = v5 | 8;
    v6 = v2->BackgroundColor.Raw;
    v2->pPrev = (Scaleform::Render::BeginDisplayData *)v3->BeginDisplayDataList.FirstEmptySlot;
    v3->BeginDisplayDataList.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2> >::NodeType *)v2;
    v7 = (v3->HALState & 4) == 0;
    v25 = v6;
    if ( v7 )
    {
      ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[9].__vecDelDtor)(v3);
      v3->HALState |= 0x400u;
    }
    Scaleform::Render::HAL::applyBlendMode(
      v3,
      (unsigned int)v3->CurrentBlendState.Mode,
      v3->CurrentBlendState.SourceAc,
      v3->CurrentBlendState.ForceAc);
    ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[82].__vecDelDtor)(v3);
    v8 = (int *)((__int64 (__fastcall *)(Scaleform::Render::MatrixState *, char *, Scaleform::Render::Viewport *))v3->Matrices.pObject->vfptr[5].__vecDelDtor)(
                  v3->Matrices.pObject,
                  &v22,
                  &v2->VP);
    v9 = &v3->VP;
    v9->BufferWidth = *v8;
    v9->BufferHeight = v8[1];
    v9->Left = v8[2];
    v9->Top = v8[3];
    v9->Width = v8[4];
    v9->Height = v8[5];
    v9->ScissorLeft = v8[6];
    v9->ScissorTop = v8[7];
    v9->ScissorWidth = v8[8];
    v9->ScissorHeight = v8[9];
    v9->Flags = v8[10];
    if ( Scaleform::Render::Viewport::GetClippedRect<int>(&v3->VP, &v3->ViewRect, 0) )
      v3->HALState |= 0x20u;
    else
      v3->HALState &= 0xFFFFFFDF;
    ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[17].__vecDelDtor)(v3);
    if ( (v3->HALState & 0x810) == 2048 )
    {
      LOBYTE(v10) = 1;
      v23 = v3->ViewRect.x2 - v3->ViewRect.x1;
      v24 = v3->ViewRect.y2 - v3->ViewRect.y1;
      v12 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, int *, __int64))v3->vfptr[22].__vecDelDtor)(
              v3,
              &v23,
              v10);
      v13 = v3->FullSceneBlendTarget.pObject;
      v14 = (Scaleform::Render::RenderTarget *)v12;
      if ( v13 )
        ((void (*)(void))v13->vfptr[2].__vecDelDtor)();
      v3->FullSceneBlendTarget.pObject = v14;
      v15 = v3->vfptr;
      v16 = (float)(v3->ViewRect.x2 - v3->ViewRect.x1);
      v17 = (float)(v3->ViewRect.y2 - v3->ViewRect.y1);
      v19 = 0i64;
      v20 = v16;
      v21 = v17;
      v23 = 0;
      ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, Scaleform::Render::RenderTarget *, _QWORD, int *))v15[24].__vecDelDtor)(
        v3,
        &v19,
        v14,
        0i64,
        &v23);
    }
    if ( HIBYTE(v25) )
    {
      if ( !(v2->VP.Flags & 0x200) )
      {
        v20 = *(float *)&v2->VP.Width;
        LOBYTE(v11) = 1;
        v21 = *(float *)&v2->VP.Height;
        v18 = v3->vfptr;
        v23 = v6;
        v19 = 0i64;
        ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, int *, __int64))v18[18].__vecDelDtor)(
          v3,
          &v19,
          &v23,
          v11);
      }
    }
  }
}

// File Line: 538
// RVA: 0x9E1A50
void __fastcall Scaleform::Render::HAL::endDisplay(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rdi
  void *v2; // r14
  signed __int64 v3; // rsi
  Scaleform::Render::HAL::RenderTargetEntry *v4; // r15
  __int64 v5; // rbx
  int v6; // edx
  int *v7; // rax
  __m128 v8; // xmm0
  float v9; // xmm3_4
  __m128 v10; // xmm3
  Scaleform::RefCountImplCoreVtbl *v11; // rax
  Scaleform::Render::Matrix2x4<float> v12; // [rsp+18h] [rbp-69h]
  int v13; // [rsp+38h] [rbp-49h]
  int v14; // [rsp+3Ch] [rbp-45h]
  int v15; // [rsp+40h] [rbp-41h]
  int v16; // [rsp+44h] [rbp-3Dh]
  int v17; // [rsp+48h] [rbp-39h]
  int v18; // [rsp+4Ch] [rbp-35h]
  int v19; // [rsp+50h] [rbp-31h]
  int v20; // [rsp+54h] [rbp-2Dh]
  int v21; // [rsp+E8h] [rbp+67h]
  int v22; // [rsp+ECh] [rbp+6Bh]
  void *v23; // [rsp+F0h] [rbp+6Fh]

  v1 = this;
  v2 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 4u);
  v23 = v2;
  if ( v1->HALState & 8 )
  {
    ((void (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[83].__vecDelDtor)(v1);
    if ( v1->HALState & 0x800 )
    {
      if ( v1->RenderTargetStack.Data.Size )
      {
        v3 = v1->RenderTargetStack.Data.Size;
        v4 = v1->RenderTargetStack.Data.Data;
        if ( v4[v3 - 1].pRenderTarget.pObject == v1->FullSceneBlendTarget.pObject )
        {
          v1->vfptr[25].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 0);
          Scaleform::Render::HAL::applyBlendMode(v1, 1i64, 1, 1);
          v5 = ((__int64 (*)(void))v4[v3 - 1].pRenderTarget.pObject->vfptr[3].__vecDelDtor)();
          v6 = *(_DWORD *)(v5 + 52);
          v21 = *(_DWORD *)(v5 + 48);
          v22 = v6;
          v7 = (int *)v1->Matrices.pObject->vfptr[1].__vecDelDtor(
                        (Scaleform::RefCountImplCore *)&v1->Matrices.pObject->vfptr,
                        (unsigned int)&v21);
          v13 = *v7;
          v14 = v7[1];
          v15 = v7[2];
          v16 = v7[3];
          v17 = v7[4];
          v18 = v7[5];
          v19 = v7[6];
          v20 = v7[7];
          v12 = Scaleform::Render::Matrix2x4<float>::Identity;
          v8 = (__m128)COERCE_UNSIGNED_INT((float)(v4[v3 - 1].pRenderTarget.pObject->ViewRect.x2
                                                 - v4[v3 - 1].pRenderTarget.pObject->ViewRect.x1));
          v9 = (float)(v4[v3 - 1].pRenderTarget.pObject->ViewRect.y2 - v4[v3 - 1].pRenderTarget.pObject->ViewRect.y1)
             / (float)*(signed int *)(v5 + 52);
          v8.m128_f32[0] = v8.m128_f32[0] / (float)*(signed int *)(v5 + 48);
          v12.M[0][0] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][0] * v8.m128_f32[0];
          v12.M[0][1] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][1] * v8.m128_f32[0];
          v12.M[0][2] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][2] * v8.m128_f32[0];
          v12.M[0][3] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][3] * v8.m128_f32[0];
          v12.M[1][0] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][0] * v9;
          v12.M[1][1] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][1] * v9;
          v12.M[1][2] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][2] * v9;
          v12.M[1][3] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][3] * v9;
          ((void (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[71].__vecDelDtor)(v1);
          v10 = _mm_xor_ps(v8, *(__m128 *)_xmm);
          *(__m128 *)&v12.M[1][0] = _mm_mul_ps(*(__m128 *)&v12.M[1][0], _mm_shuffle_ps(v10, v10, 0));
          v11 = v1->vfptr;
          v12.M[0][2] = 0.0;
          ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, int *, Scaleform::Render::Matrix2x4<float> *))v11[58].__vecDelDtor)(
            v1,
            v5,
            &v13,
            &v12);
          v4[v3 - 1].pRenderTarget.pObject->vfptr[5].__vecDelDtor(
            (Scaleform::RefCountImplCore *)v4[v3 - 1].pRenderTarget.pObject,
            0);
        }
      }
    }
    if ( v1->HALState & 0x400 )
    {
      ((void (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[10].__vecDelDtor)(v1);
      v1->HALState &= 0xFFFFFBFF;
    }
    v1->HALState &= 0xFFFFFFF7;
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
}

// File Line: 577
// RVA: 0x95BD00
void __fastcall Scaleform::Render::HAL::CalcHWViewMatrix(Scaleform::Render::HAL *this, unsigned int vpFlags, Scaleform::Render::Matrix2x4<float> *pmatrix, Scaleform::Render::Rect<int> *viewRect, int dx, int dy)
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm0_4

  v6 = 0.0;
  v7 = 0.0;
  v8 = (float)(viewRect->x2 - viewRect->x1);
  v9 = (float)(viewRect->y2 - viewRect->y1);
  if ( _bittest((const signed int *)&vpFlags, 8u) )
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
  if ( vpFlags & 1 )
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

  v1 = (Scaleform::Render::RenderQueueProcessor *)((__int64 (*)(void))this->vfptr[64].__vecDelDtor)();
  Scaleform::Render::RenderQueueProcessor::ProcessQueue(v1, QPM_All);
  v1->PrepareItemBuffer.pItem = 0i64;
  v1->EmitItemBuffer.pItem = 0i64;
}

// File Line: 613
// RVA: 0x95AB20
char __fastcall Scaleform::Render::HAL::BeginScene(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rbx
  void *v2; // rax
  __int64 v4; // rax
  __int64 v5; // rdx
  Scaleform::RefCountImplCoreVtbl *v6; // rax
  Scaleform::Render::HAL::RasterModeType v7; // edi

  v1 = this;
  v2 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 2u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v2 + 16i64))(v2, "Scaleform::Render::HAL::BeginScene");
  if ( !(v1->HALState & 2) )
    return 0;
  if ( ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[61].__vecDelDtor)(v1) )
  {
    v4 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[61].__vecDelDtor)(v1);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 88i64))(v4);
  }
  v1->CurrentBlendState.Mode = 20;
  v1->CurrentBlendState.BlendEnable = 0;
  Scaleform::Render::HAL::applyBlendMode(v1, 0, 0, 0);
  LOBYTE(v5) = 1;
  v1->vfptr[41].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, v5);
  v6 = v1->vfptr;
  v1->CurrentDepthStencilState = 0;
  v1->CurrentStencilRef = -1;
  v6[78].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 1u);
  v7 = v1->NextSceneRasterMode;
  v1->CurrentSceneRasterMode = v7;
  v1->AppliedSceneRasterMode = 3;
  if ( v7 != 3 )
  {
    v1->vfptr[84].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, v7);
    v1->AppliedSceneRasterMode = v7;
  }
  v1->HALState |= 4u;
  return 1;
}

// File Line: 643
// RVA: 0x970C20
__int64 __fastcall Scaleform::Render::HAL::EndScene(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rbx
  void *v2; // rdi
  unsigned __int8 v3; // bl
  __int64 v4; // rax

  v1 = this;
  v2 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 2u);
  if ( (v1->HALState & 6) == 6 )
  {
    ((void (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[8].__vecDelDtor)(v1);
    if ( ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[61].__vecDelDtor)(v1) )
    {
      v4 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[61].__vecDelDtor)(v1);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 96i64))(v4);
    }
    v1->HALState &= 0xFFFFFFFB;
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
Scaleform::Render::RenderTarget *__fastcall Scaleform::Render::HAL::GetDefaultRenderTarget(Scaleform::Render::HAL *this)
{
  Scaleform::Render::RenderTarget *result; // rax

  if ( this->RenderTargetStack.Data.Size )
    result = this->RenderTargetStack.Data.Data->pRenderTarget.pObject;
  else
    result = 0i64;
  return result;
}

// File Line: 667
// RVA: 0x9DFF00
void __fastcall Scaleform::Render::HAL::destroyRenderBuffers(Scaleform::Render::HAL *this)
{
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&this->RenderTargetStack.Data.Data,
    &this->RenderTargetStack,
    0i64);
}

// File Line: 672
// RVA: 0x9692E0
void __fastcall Scaleform::Render::HAL::CreatePrimitiveFill(Scaleform::Render::HAL *this, Scaleform::Render::PrimitiveFillData *data)
{
  Scaleform::Render::PrimitiveFillData *v2; // rbx
  Scaleform::Render::PrimitiveFill *v3; // rax

  v2 = data;
  v3 = (Scaleform::Render::PrimitiveFill *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pHeap->vfptr->Alloc)(
                                             this->pHeap,
                                             64i64);
  if ( v3 )
    Scaleform::Render::PrimitiveFill::PrimitiveFill(v3, v2, 0i64);
}

// File Line: 714
// RVA: 0x96F110
void __fastcall Scaleform::Render::HAL::DrawBundleEntries(Scaleform::Render::HAL *this, Scaleform::Render::BundleIterator *ibundles, Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::Render::Renderer2DImpl *v3; // rsi
  Scaleform::Render::BundleIterator *v4; // rbx
  Scaleform::Render::HAL *v5; // rdi
  Scaleform::Render::DisplayPass v6; // eax
  __int64 v7; // rax
  __int64 *v8; // [rsp+20h] [rbp-18h]
  Scaleform::Render::BundleEntry *v9; // [rsp+28h] [rbp-10h]

  v3 = r2d;
  v4 = ibundles;
  v5 = this;
  if ( this->CurrentPass == 3 && ((unsigned __int8 (*)(void))this->vfptr[29].__vecDelDtor)() )
  {
    v5->vfptr[30].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
    v8 = (__int64 *)v4->pFirst;
    v9 = v4->pLast;
    ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 **, Scaleform::Render::Renderer2DImpl *))v5->vfptr[32].__vecDelDtor)(
      v5,
      &v8,
      v3);
    v5->vfptr[30].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 2u);
    v8 = (__int64 *)v4->pFirst;
    v9 = v4->pLast;
    ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 **, Scaleform::Render::Renderer2DImpl *))v5->vfptr[32].__vecDelDtor)(
      v5,
      &v8,
      v3);
    v5->vfptr[30].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 3u);
  }
  else
  {
    v6 = v5->CurrentPass;
    if ( v6 == 1 )
    {
      *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))v5->vfptr[64].__vecDelDtor)(v5) + 48) = 1;
      *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))v5->vfptr[64].__vecDelDtor)(v5) + 44) = 1;
    }
    else if ( (unsigned int)(v6 - 2) <= 1 )
    {
      *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))v5->vfptr[64].__vecDelDtor)(v5) + 48) = 0;
      *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))v5->vfptr[64].__vecDelDtor)(v5) + 44) = 0;
    }
    v7 = (__int64)v4->pFirst;
    if ( v4->pFirst )
    {
      while ( 1 )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD, __int64, Scaleform::Render::Renderer2DImpl *))(**(_QWORD **)(v7 + 24)
                                                                                             + 40i64))(
          *(_QWORD *)(v7 + 24),
          *(_QWORD *)(v7 + 32),
          v7,
          v3);
        if ( v4->pFirst == v4->pLast )
          break;
        v7 = (__int64)v4->pFirst->pNextPattern;
        v4->pFirst = (Scaleform::Render::BundleEntry *)v7;
        if ( !v7 )
          return;
      }
      v4->pLast = 0i64;
      v4->pFirst = 0i64;
    }
  }
}

// File Line: 749
// RVA: 0x96EB50
void __fastcall Scaleform::Render::HAL::Draw(Scaleform::Render::HAL *this, Scaleform::Render::RenderQueueItem *item)
{
  Scaleform::Render::RenderQueueItem *v2; // rdi
  Scaleform::Render::HAL *v3; // rbx
  Scaleform::Render::RenderQueueProcessor *v4; // rax
  __int64 v5; // rdx
  unsigned int v6; // ecx
  Scaleform::Render::RenderQueueProcessor *v7; // rsi
  bool v8; // zf
  Scaleform::Render::RenderQueueItem *v9; // rcx
  __int64 v10; // rdx
  unsigned int v11; // ecx
  unsigned int v12; // ecx

  v2 = item;
  v3 = this;
  if ( (Scaleform::Render::HALBeginDisplayItem *)item->pImpl != &Scaleform::Render::HALBeginDisplayItem::Instance
    && !(this->HALState & 8) )
  {
    return;
  }
  v4 = (Scaleform::Render::RenderQueueProcessor *)((__int64 (*)(void))this->vfptr[64].__vecDelDtor)();
  v5 = v3->Queue.QueueHead;
  v6 = v3->Queue.QueueTail;
  v7 = v4;
  if ( (unsigned int)v5 > v6 )
    v8 = v3->Queue.QueueSize + v6 == (_DWORD)v5 + 1;
  else
    v8 = v6 - (_DWORD)v5 == 1;
  if ( v8 || (v3->Queue.HeadReserved = 1, (v9 = &v3->Queue.pQueue[v5]) == 0i64) )
  {
    Scaleform::Render::RenderQueueProcessor::ProcessQueue(v4, QPM_One);
    v10 = v3->Queue.QueueHead;
    v11 = v3->Queue.QueueTail;
    if ( (unsigned int)v10 > v11 )
    {
      if ( v3->Queue.QueueSize + v11 == (_DWORD)v10 + 1 )
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
    v3->Queue.HeadReserved = 1;
    v9 = &v3->Queue.pQueue[v10];
  }
LABEL_14:
  v9->pImpl = v2->pImpl;
  v9->Data = v2->Data;
  v8 = ++v3->Queue.QueueHead == v3->Queue.QueueSize;
  v12 = v3->Queue.QueueHead;
  v3->Queue.HeadReserved = 0;
  if ( v8 )
    v12 = 0;
  v3->Queue.QueueHead = v12;
  Scaleform::Render::RenderQueueProcessor::ProcessQueue(v7, 0);
}

// File Line: 798
// RVA: 0x9A3450
void __fastcall Scaleform::Render::HAL::PushMask_BeginSubmit(Scaleform::Render::HAL *this, Scaleform::Render::MaskPrimitive *prim)
{
  Scaleform::Render::MaskPrimitive *v2; // rbp
  Scaleform::Render::HAL *v3; // rdi
  void *v4; // rax
  unsigned __int64 v5; // r8
  char v6; // si
  Scaleform::Render::MaskPrimitive *v7; // rdx
  signed __int64 v8; // r14
  __int64 v9; // rcx
  int v10; // er8
  int v11; // edx
  int v12; // ecx
  signed __int64 v13; // rdx
  Scaleform::RefCountImplCoreVtbl *v14; // rax

  v2 = prim;
  v3 = this;
  v4 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 6u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v4 + 16i64))(
    v4,
    "Scaleform::Render::HAL::PushMask_BeginSubmit");
  if ( v3->HALState & 8 && ((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[79].__vecDelDtor)(v3) )
  {
    if ( v3->AppliedSceneRasterMode )
    {
      v3->vfptr[84].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 0);
      v3->AppliedSceneRasterMode = 0;
    }
    v5 = v3->MaskStackTop;
    v6 = (v3->HALState >> 5) & 1;
    if ( (_DWORD)v5 && v3->MaskStack.Data.Size > v5 && v6 && v3->StencilAvailable && v3->MultiBitStencil )
    {
      v3->vfptr[78].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 3u);
      v7 = v3->MaskStack.Data.Data[v3->MaskStackTop].pPrimitive.pObject;
      ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::MatrixPoolImpl::HMatrix *, unsigned __int64))v3->vfptr[81].__vecDelDtor)(
        v3,
        v7->MaskAreas.Data.Data,
        v7->MaskAreas.Data.Size);
    }
    Scaleform::ArrayData<Scaleform::Render::HAL::MaskStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
      &v3->MaskStack.Data,
      v3->MaskStackTop + 1);
    v8 = (signed __int64)&v3->MaskStack.Data.Data[v3->MaskStackTop];
    if ( v2 )
      _InterlockedExchangeAdd(&v2->RefCount, 1u);
    v9 = *(_QWORD *)v8;
    if ( *(_QWORD *)v8 && !_InterlockedDecrement((volatile signed __int32 *)(v9 + 8)) && v9 )
      (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
    *(_QWORD *)v8 = v2;
    *(_BYTE *)(v8 + 8) = v6;
    v10 = v3->ViewRect.y2;
    v11 = v3->ViewRect.x2;
    v12 = v3->ViewRect.y1;
    *(_DWORD *)(v8 + 12) = v3->ViewRect.x1;
    *(_DWORD *)(v8 + 16) = v12;
    *(_DWORD *)(v8 + 20) = v11;
    *(_DWORD *)(v8 + 24) = v10;
    ++v3->MaskStackTop;
    v3->HALState |= 0x40u;
    if ( v3->MaskStackTop == 1 && v6 )
    {
      v13 = 2i64;
      if ( !v3->StencilAvailable )
        v13 = 6i64;
      v3->vfptr[78].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, v13);
      ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::MatrixPoolImpl::HMatrix *, unsigned __int64))v3->vfptr[81].__vecDelDtor)(
        v3,
        v2->MaskAreas.Data.Data,
        v2->MaskAreas.Data.Size);
    }
    if ( v3->StencilAvailable )
    {
      v14 = v3->vfptr;
      if ( v3->MultiBitStencil )
      {
        ((void (__fastcall *)(Scaleform::Render::HAL *, signed __int64, _QWORD))v14[78].__vecDelDtor)(
          v3,
          4i64,
          v3->MaskStackTop - 1);
        ++v3->AccumulatedStats.Masks;
        return;
      }
      ((void (__fastcall *)(Scaleform::Render::HAL *, signed __int64, signed __int64))v14[78].__vecDelDtor)(
        v3,
        2i64,
        1i64);
      if ( !warned )
      {
        warned = v3->MaskStackTop > 1;
        ++v3->AccumulatedStats.Masks;
        return;
      }
    }
    else if ( v3->DepthBufferAvailable )
    {
      v3->vfptr[78].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 6u);
      if ( !warned_0 )
        warned_0 = v3->MaskStackTop > 1;
    }
    ++v3->AccumulatedStats.Masks;
  }
}

// File Line: 878
// RVA: 0x970A40
void __fastcall Scaleform::Render::HAL::EndMaskSubmit(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rbx
  void *v2; // rsi
  __int64 v3; // r8
  signed __int64 v4; // rdx
  Scaleform::Render::HAL::RasterModeType v5; // edi

  v1 = this;
  v2 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 6u);
  if ( (v1->HALState & 0x48) != 72 )
    goto LABEL_9;
  v1->HALState &= 0xFFFFFFBF;
  if ( v1->StencilAvailable )
  {
    v3 = v1->MaskStackTop;
    v4 = 5i64;
  }
  else
  {
    if ( !v1->DepthBufferAvailable )
      goto LABEL_7;
    v3 = 0i64;
    v4 = 7i64;
  }
  ((void (__fastcall *)(Scaleform::Render::HAL *, signed __int64, __int64))v1->vfptr[78].__vecDelDtor)(v1, v4, v3);
LABEL_7:
  v5 = v1->CurrentSceneRasterMode;
  if ( v5 != v1->AppliedSceneRasterMode )
  {
    v1->vfptr[84].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, v5);
    v1->AppliedSceneRasterMode = v5;
  }
LABEL_9:
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
}

// File Line: 904
// RVA: 0x99F410
void __fastcall Scaleform::Render::HAL::PopMask(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rbx
  void *v2; // rdi
  Scaleform::RefCountImplCoreVtbl *v3; // rax
  Scaleform::Render::HAL *v4; // rcx
  signed __int64 v5; // rdx

  v1 = this;
  v2 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 7u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v2 + 16i64))(v2, "Scaleform::Render::HAL::PopMask");
  if ( v1->HALState & 8 && ((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[79].__vecDelDtor)(v1) )
  {
    --v1->MaskStackTop;
    if ( v1->StencilAvailable )
    {
      v3 = v1->vfptr;
      v4 = v1;
      if ( v1->MaskStackTop )
      {
        v5 = 5i64;
LABEL_9:
        v3[78].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, v5);
        goto LABEL_10;
      }
LABEL_8:
      v5 = 1i64;
      goto LABEL_9;
    }
    if ( v1->DepthBufferAvailable )
    {
      v3 = v1->vfptr;
      v4 = v1;
      goto LABEL_8;
    }
  }
LABEL_10:
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
}

// File Line: 979
// RVA: 0x9A2EB0
void __fastcall Scaleform::Render::HAL::PushBlendMode(Scaleform::Render::HAL *this, Scaleform::Render::BlendPrimitive *prim)
{
  Scaleform::Render::BlendPrimitive *v2; // rdi
  Scaleform::Render::HAL *v3; // rbp
  Scaleform::Render::BlendMode v4; // er12
  signed __int64 v5; // rbx
  Scaleform::Render::BlendPrimitive *v6; // [rsp+28h] [rbp-50h]

  v2 = prim;
  v3 = this;
  if ( this->HALState & 8 )
  {
    v4 = prim->BlendModeValue;
    _InterlockedExchangeAdd(&prim->RefCount, 1u);
    v6 = prim;
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::BlendStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::BlendStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Render::HAL::BlendStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::BlendStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&this->BlendModeStack.Data.Data,
      &this->BlendModeStack,
      this->BlendModeStack.Data.Size + 1);
    v5 = (signed __int64)&v3->BlendModeStack.Data.Data[v3->BlendModeStack.Data.Size - 1];
    if ( v5 )
    {
      if ( v2 )
      {
        _InterlockedExchangeAdd(&v2->RefCount, 1u);
        v2 = v6;
      }
      *(_QWORD *)v5 = v2;
      *(_QWORD *)(v5 + 8) = 0i64;
      *(_QWORD *)(v5 + 16) = 0i64;
      *(_BYTE *)(v5 + 24) = 0;
      *(_BYTE *)(v5 + 25) = 0;
    }
    Scaleform::Render::HAL::applyBlendMode(v3, v4, 0, (v3->HALState >> 4) & 1);
    if ( v2 )
    {
      if ( !_InterlockedDecrement(&v2->RefCount) )
        v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
    }
  }
}

// File Line: 992
// RVA: 0x99F0C0
void __fastcall Scaleform::Render::HAL::PopBlendMode(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rbp
  Scaleform::ArrayData<Scaleform::Render::HAL::BlendStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::BlendStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *v2; // r14
  Scaleform::Render::HAL::BlendStackEntry *v3; // rbx
  Scaleform::Render::BlendPrimitive *v4; // rcx
  Scaleform::Render::BlendPrimitive *v5; // rsi
  Scaleform::Render::RenderTarget *v6; // rcx
  Scaleform::Render::RenderTarget *v7; // rdi
  Scaleform::Render::RenderTarget *v8; // rcx
  Scaleform::Render::RenderTarget *v9; // r15
  bool v10; // ST40_1
  bool v11; // ST41_1
  Scaleform::Render::BlendMode v12; // edx
  Scaleform::Render::BlendPrimitive *v13; // [rsp+28h] [rbp-40h]

  v1 = this;
  if ( this->HALState & 8 )
  {
    v2 = &this->BlendModeStack.Data;
    v3 = &this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size];
    v4 = v3[-1].pPrimitive.pObject;
    if ( v4 )
      _InterlockedExchangeAdd(&v4->RefCount, 1u);
    v5 = v3[-1].pPrimitive.pObject;
    v13 = v3[-1].pPrimitive.pObject;
    v6 = v3[-1].pRenderTarget.pObject;
    if ( v6 )
      ((void (__cdecl *)(Scaleform::Render::RenderTarget *))v6->vfptr[1].__vecDelDtor)(v6);
    v7 = v3[-1].pRenderTarget.pObject;
    v8 = v3[-1].pLayerAlpha.pObject;
    if ( v8 )
      ((void (__cdecl *)(Scaleform::Render::RenderTarget *))v8->vfptr[1].__vecDelDtor)(v8);
    v9 = v3[-1].pLayerAlpha.pObject;
    v10 = v3[-1].LayerAlphaCleared;
    v11 = v3[-1].NoLayerParent;
    Scaleform::ArrayData<Scaleform::Render::HAL::BlendStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::BlendStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
      v2,
      v2->Size - 1);
    if ( v1->BlendModeStack.Data.Size < 1 )
      v12 = 1;
    else
      v12 = v2->Data[v2->Size - 1].pPrimitive.pObject->BlendModeValue;
    Scaleform::Render::HAL::applyBlendMode(v1, v12, 0, (v1->HALState >> 4) & 1);
    if ( v9 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v9->vfptr[2].__vecDelDtor)(v9);
    if ( v7 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v7->vfptr[2].__vecDelDtor)(v7);
    if ( v5 )
    {
      if ( !_InterlockedDecrement(&v5->RefCount) )
        v13->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, 1u);
    }
  }
}

// File Line: 1011
// RVA: 0x9CE8A0
void __fastcall Scaleform::Render::HAL::applyBlendMode(Scaleform::Render::HAL *this, __int64 mode, bool sourceAc, bool forceAc)
{
  bool v4; // di
  bool v5; // si
  Scaleform::Render::HAL *v6; // rbx
  Scaleform::Render::BlendMode v7; // eax
  unsigned int v8; // edx
  Scaleform::Render::BlendMode v9; // er10
  Scaleform::RefCountImplCoreVtbl *v10; // rax

  v4 = forceAc;
  v5 = sourceAc;
  v6 = this;
  if ( this->CurrentBlendState.Mode != (_DWORD)mode
    || this->CurrentBlendState.SourceAc != sourceAc
    || this->CurrentBlendState.ForceAc != forceAc )
  {
    if ( (unsigned int)mode >= 0x14 )
      mode = 0i64;
    v7 = (unsigned int)this->Profiler.vfptr->GetBlendMode(&this->Profiler, (Scaleform::Render::BlendMode)mode);
    v6->FillFlags &= 0xFFFFFFFC;
    v8 = v6->FillFlags;
    v9 = v7;
    if ( (unsigned int)(v7 - 3) <= 1 )
    {
      v6->FillFlags = v8 | 1;
    }
    else if ( v7 == 10 )
    {
      v6->FillFlags = v8 | 2;
      v6->FillFlags |= 0x20u;
LABEL_13:
      v6->CurrentBlendState.Mode = v7;
      v10 = v6->vfptr;
      v6->CurrentBlendState.SourceAc = v5;
      v6->CurrentBlendState.ForceAc = v4;
      ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, bool, bool))v10[42].__vecDelDtor)(
        v6,
        (unsigned int)v9,
        v5,
        v4);
      return;
    }
    if ( (signed int)v7 <= 1 )
      v6->FillFlags &= 0xFFFFFFDF;
    else
      v6->FillFlags |= 0x20u;
    goto LABEL_13;
  }
}

// File Line: 1079
// RVA: 0x9CE880
void __fastcall Scaleform::Render::HAL::applyBlendMode(Scaleform::Render::HAL *this, Scaleform::Render::HAL::HALBlendState *state)
{
  Scaleform::Render::HAL::applyBlendMode(this, state->Mode, state->SourceAc, state->ForceAc);
}

// File Line: 1084
// RVA: 0x9CE960
void __fastcall Scaleform::Render::HAL::applyBlendModeEnable(Scaleform::Render::HAL *this, bool enabled)
{
  bool v2; // di
  Scaleform::Render::HAL *v3; // rbx

  v2 = enabled;
  v3 = this;
  if ( this->CurrentBlendState.BlendEnable != enabled )
  {
    ((void (*)(void))this->vfptr[43].__vecDelDtor)();
    v3->CurrentBlendState.BlendEnable = v2;
  }
}

// File Line: 1093
// RVA: 0x9E70D0
signed __int64 __fastcall Scaleform::Render::HAL::getLastBlendModeOrDefault(Scaleform::Render::HAL *this)
{
  signed __int64 result; // rax

  if ( this->BlendModeStack.Data.Size < 1 )
    result = 1i64;
  else
    result = (unsigned int)this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1].pPrimitive.pObject->BlendModeValue;
  return result;
}

// File Line: 1120
// RVA: 0x9E02B0
void __fastcall Scaleform::Render::HAL::drawMaskClearRectangles(Scaleform::Render::HAL *this, Scaleform::Render::MatrixPoolImpl::HMatrix *matrices, unsigned __int64 count)
{
  unsigned __int64 v3; // rdi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // r14
  __int64 v5; // rbp
  Scaleform::Render::HAL *v6; // rsi
  unsigned __int64 v7; // rbx
  signed int v8; // ecx
  char *v9; // rax
  unsigned int v10; // er10
  __m128 *v11; // r8
  __m128 v12; // xmm6
  __m128 v13; // xmm7
  __int64 v14; // r9
  __m128 v15; // xmm5
  __int64 v16; // rax
  signed __int64 v17; // r9
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v18; // rcx
  __int64 v19; // rax
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  char v22[8]; // [rsp+20h] [rbp-438h]
  char v23; // [rsp+28h] [rbp-430h]
  __int128 v24[63]; // [rsp+30h] [rbp-428h]

  if ( count )
  {
    v3 = count;
    v4 = matrices;
    v5 = 0i64;
    v6 = this;
    do
    {
      v7 = 32i64;
      v8 = 31;
      v9 = &v23;
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
      if ( v7 )
      {
        v11 = (__m128 *)v6->Matrices.pObject;
        v12 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v;
        v13 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v;
        v14 = 0i64;
        do
        {
          v15 = v11[31];
          v16 = v14 + v5;
          v17 = 2 * v14;
          ++v10;
          v18 = v4[v16].pHandle;
          v19 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v18->pHeader->Format & 0xF].Offsets[4];
          v20 = (__m128)v18->pHeader[v19 + 1];
          v21 = (__m128)v18->pHeader[v19 + 2];
          *(__m128 *)&v22[v17 * 16] = _mm_and_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps(v11[30], v11[30], 85), v21),
                                            _mm_mul_ps(_mm_shuffle_ps(v11[30], v11[30], 0), v20)),
                                          _mm_and_ps(v11[30], v12)),
                                        v13);
          v24[v17] = (__int128)_mm_and_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v21),
                                     _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v20)),
                                   _mm_and_ps(v15, v12)),
                                 v13);
          v14 = v10;
        }
        while ( v10 < v7 );
      }
      ((void (__fastcall *)(Scaleform::Render::HAL *, char *, unsigned __int64))v6->vfptr[80].__vecDelDtor)(v6, v22, v7);
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
  this->HALState &= 0xFFFFFFBF;
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
void __fastcall Scaleform::Render::HAL::applyRasterMode(Scaleform::Render::HAL *this, Scaleform::Render::HAL::RasterModeType mode)
{
  Scaleform::Render::HAL::RasterModeType v2; // edi
  Scaleform::Render::HAL *v3; // rbx

  v2 = mode;
  v3 = this;
  if ( mode != this->AppliedSceneRasterMode )
  {
    ((void (*)(void))this->vfptr[84].__vecDelDtor)();
    v3->AppliedSceneRasterMode = v2;
  }
}

// File Line: 1164
// RVA: 0x99F880
void __fastcall Scaleform::Render::HAL::PrepareCacheable(Scaleform::Render::HAL *this, Scaleform::Render::CacheablePrimitive *prim, bool unprepare)
{
  Scaleform::Render::CacheablePrimitive *v3; // r12
  Scaleform::Render::HAL *v4; // rbx
  int v5; // eax
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *v6; // rsi
  bool v7; // r13
  unsigned int v8; // ebp
  Scaleform::Render::RenderTarget **v9; // r14
  Scaleform::Render::RenderTarget *v10; // rdi
  signed __int64 v11; // rdi
  Scaleform::Render::RenderTarget **v12; // rsi
  signed __int64 v13; // rdi
  int v14; // eax
  bool v15; // zf
  Scaleform::RefCountImplCoreVtbl *v16; // rax
  Scaleform::Render::RenderTarget *v17; // [rsp+20h] [rbp-38h]
  Scaleform::Render::RenderTarget *v18; // [rsp+28h] [rbp-30h]

  v3 = prim;
  v4 = this;
  if ( !(this->HALState & 8) )
    return;
  if ( prim->Caching )
  {
    if ( !unprepare )
    {
      v6 = prim->CacheResults;
      v17 = prim->CacheResults[0].pObject;
      v7 = 1;
      v8 = 0;
      v18 = prim->CacheResults[1].pObject;
      v9 = &v17;
      while ( 1 )
      {
        v10 = *v9;
        if ( !*v9 )
          break;
        if ( ((unsigned int (__fastcall *)(Scaleform::Render::RenderTarget *))v10->vfptr[4].__vecDelDtor)(*v9) == 3
          || ((unsigned int (__fastcall *)(Scaleform::Render::RenderTarget *))v10->vfptr[4].__vecDelDtor)(v10) == 2
          || (Scaleform::Render::CacheablePrimitive *)v10->pRenderTargetData->CacheID != v3 )
        {
          v7 = 0;
          goto LABEL_18;
        }
        ++v8;
        ++v9;
        if ( v8 >= 2 )
          goto LABEL_18;
      }
      v7 = v8 != 0;
LABEL_18:
      ++v4->CacheablePrepIndex;
      if ( v7 )
      {
        if ( v4->CacheablePrepStart < 0 )
        {
          v12 = &v17;
          v13 = 2i64;
          do
          {
            if ( *v12 )
              (*v12)->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&(*v12)->vfptr, 1u);
            ++v12;
            --v13;
          }
          while ( v13 );
          *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))v4->vfptr[64].__vecDelDtor)(v4) + 44) = 1;
          v4->CacheablePrepStart = v4->CacheablePrepIndex;
        }
      }
      else
      {
        v3->Caching = 0;
        v11 = 2i64;
        do
        {
          if ( v6->pObject )
            ((void (__cdecl *)(Scaleform::Render::RenderTarget *, Scaleform::Render::CacheablePrimitive *))v6->pObject->vfptr[2].__vecDelDtor)(
              v6->pObject,
              prim);
          v6->pObject = 0i64;
          ++v6;
          --v11;
        }
        while ( v11 );
        v3->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 0);
      }
      return;
    }
  }
  else if ( !unprepare )
  {
    if ( this->CurrentPass == 1 )
      *(_DWORD *)(((__int64 (*)(void))this->vfptr[64].__vecDelDtor)() + 44) = 0;
    v5 = v4->CacheablePrepIndex;
    if ( v5 >= 0 )
      v4->CacheablePrepIndex = v5 + 1;
    return;
  }
  v14 = this->CacheablePrepIndex;
  if ( v14 >= 0 )
  {
    if ( v14 == this->CacheablePrepStart )
    {
      v15 = this->CurrentPass == 1;
      v16 = this->vfptr;
      this->CacheablePrepStart = -1;
      if ( !v15 )
      {
        *(_DWORD *)(((__int64 (*)(void))v16[64].__vecDelDtor)() + 44) = 0;
        --v4->CacheablePrepIndex;
        return;
      }
      *(_DWORD *)(((__int64 (*)(void))v16[64].__vecDelDtor)() + 44) = 1;
    }
    --v4->CacheablePrepIndex;
  }
}

// File Line: 1255
// RVA: 0x9A3010
void __fastcall Scaleform::Render::HAL::PushFilters(Scaleform::Render::HAL *this, Scaleform::Render::FilterPrimitive *prim)
{
  Scaleform::Render::FilterPrimitive *v2; // r14
  Scaleform::Render::HAL *v3; // rsi
  void *v4; // rax
  _DWORD *v5; // r15
  Scaleform::Render::HAL::FilterStackEntry *v6; // rdx
  Scaleform::Render::HAL::FilterStackEntry *v7; // rdx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v8; // rdi
  int v9; // ecx
  __int64 v10; // rbx
  signed int v11; // ecx
  int v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  signed __int64 v15; // rdx
  int v16; // ecx
  __int64 v17; // rax
  Scaleform::Render::HAL::FilterStackEntry *v18; // rbx
  _DWORD *v19; // [rsp+50h] [rbp-20h]
  int v20; // [rsp+60h] [rbp-10h]
  int v21; // [rsp+64h] [rbp-Ch]
  float v22; // [rsp+68h] [rbp-8h]
  float v23; // [rsp+6Ch] [rbp-4h]
  int v24; // [rsp+A0h] [rbp+30h]
  AMD_HD3D *v25; // [rsp+B0h] [rbp+40h]
  int v26; // [rsp+B8h] [rbp+48h]
  int v27; // [rsp+BCh] [rbp+4Ch]

  v2 = prim;
  v3 = this;
  v4 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 12u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v4 + 16i64))(v4, "Scaleform::Render::HAL::PushFilters");
  if ( !(v3->HALState & 8) )
    return;
  if ( v2 )
    _InterlockedExchangeAdd(&v2->RefCount, 1u);
  v5 = 0i64;
  v19 = 0i64;
  if ( v3->vfptr[74].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)v2) )
  {
    if ( v3->HALState & 0x300 )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&v3->FilterStack.Data.Data,
        &v3->FilterStack,
        v3->FilterStack.Data.Size + 1);
      v7 = &v3->FilterStack.Data.Data[v3->FilterStack.Data.Size - 1];
      if ( v7 )
      {
        if ( v2 )
        {
          _InterlockedExchangeAdd(&v2->RefCount, 1u);
          v5 = 0i64;
        }
        v7->pPrimitive.pObject = v2;
        v7->pRenderTarget.pObject = 0i64;
      }
      goto LABEL_34;
    }
    if ( v3->MaskStackTop && !v2->MaskPresent && v2->Caching != 2 )
      v3->vfptr[78].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
    v3->vfptr[84].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 0);
    v3->HALState |= 0x80u;
    if ( v2->Caching )
    {
      v3->HALState |= 0x100u;
      v3->CacheableIndex = v3->FilterStack.Data.Size;
      *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[64].__vecDelDtor)(v3) + 48) = 1;
    }
    else
    {
      v8 = v2->PrimitiveArea.Data.Data->pHandle->pHeader;
      v9 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v8->Format & 0xF].Offsets[4];
      v10 = v9 * 16;
      v11 = (signed int)*((float *)&v8[v9 + 2].pHandle + 1);
      LODWORD(v25) = (signed int)*(float *)((char *)&v8[1].pHandle + v10);
      HIDWORD(v25) = v11;
      v5 = (_DWORD *)((__int64 (__fastcall *)(Scaleform::Render::HAL *, AMD_HD3D **, bool))v3->vfptr[22].__vecDelDtor)(
                       v3,
                       &v25,
                       v2->MaskPresent);
      v19 = v5;
      v12 = *(_DWORD *)((char *)&v8[2].DataPageOffset + v10);
      v13 = *(float *)((char *)&v8[2].DataPageOffset + v10) + *(float *)((char *)&v8[2].pHandle + v10 + 4);
      v14 = *(float *)((char *)&v8[1].DataPageOffset + v10) + *(float *)((char *)&v8[1].pHandle + v10);
      v20 = *(_DWORD *)((char *)&v8[1].DataPageOffset + v10);
      v21 = v12;
      v22 = v14;
      v23 = v13;
      v24 = 0;
      ((void (__fastcall *)(Scaleform::Render::HAL *, int *, _DWORD *, _QWORD, int *))v3->vfptr[24].__vecDelDtor)(
        v3,
        &v20,
        v5,
        0i64,
        &v24);
      Scaleform::Render::HAL::applyBlendMode(v3, Blend_Normal, 0, 1);
      if ( v2->MaskPresent && ((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[79].__vecDelDtor)(v3) )
      {
        if ( v3->StencilAvailable )
        {
          v15 = 2i64;
        }
        else
        {
          if ( !v3->DepthBufferAvailable )
          {
LABEL_28:
            v16 = v5[11];
            v26 = v5[10];
            v27 = v16;
            v17 = (__int64)v3->Matrices.pObject->vfptr[1].__vecDelDtor(
                             (Scaleform::RefCountImplCore *)&v3->Matrices.pObject->vfptr,
                             (unsigned int)&v26);
            ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, signed __int64))v3->vfptr[80].__vecDelDtor)(
              v3,
              v17,
              1i64);
            ((void (__fastcall *)(Scaleform::Render::HAL *, signed __int64, _QWORD))v3->vfptr[78].__vecDelDtor)(
              v3,
              1i64,
              v3->MaskStackTop);
            goto LABEL_30;
          }
          v15 = 6i64;
        }
        ((void (__fastcall *)(Scaleform::Render::HAL *, signed __int64, _QWORD))v3->vfptr[78].__vecDelDtor)(
          v3,
          v15,
          v3->MaskStackTop);
        goto LABEL_28;
      }
    }
LABEL_30:
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&v3->FilterStack.Data.Data,
      &v3->FilterStack,
      v3->FilterStack.Data.Size + 1);
    v18 = &v3->FilterStack.Data.Data[v3->FilterStack.Data.Size - 1];
    if ( v18 )
    {
      _InterlockedExchangeAdd(&v2->RefCount, 1u);
      v18->pPrimitive.pObject = v2;
      v5 = v19;
      if ( v19 )
        (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v19 + 8i64))(v19);
      v18->pRenderTarget.pObject = (Scaleform::Render::RenderTarget *)v19;
    }
    goto LABEL_34;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&v3->FilterStack.Data.Data,
    &v3->FilterStack,
    v3->FilterStack.Data.Size + 1);
  v6 = &v3->FilterStack.Data.Data[v3->FilterStack.Data.Size - 1];
  if ( v6 )
  {
    if ( v2 )
    {
      _InterlockedExchangeAdd(&v2->RefCount, 1u);
      v5 = 0i64;
    }
    v6->pPrimitive.pObject = v2;
    v6->pRenderTarget.pObject = 0i64;
  }
LABEL_34:
  if ( v5 )
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v5 + 16i64))(v5);
  if ( v2 )
  {
    if ( !_InterlockedDecrement(&v2->RefCount) )
      v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  }
}

// File Line: 1322
// RVA: 0x98B9D0
void __fastcall Scaleform::Render::HAL::GetStats(Scaleform::Render::HAL *this, Scaleform::Render::HAL::Stats *pstats, bool clear)
{
  pstats->Primitives = this->AccumulatedStats.Primitives;
  pstats->Meshes = this->AccumulatedStats.Meshes;
  pstats->Triangles = this->AccumulatedStats.Triangles;
  pstats->Masks = this->AccumulatedStats.Masks;
  pstats->RTChanges = this->AccumulatedStats.RTChanges;
  pstats->Filters = this->AccumulatedStats.Filters;
  if ( clear )
  {
    *(_QWORD *)&this->AccumulatedStats.RTChanges = 0i64;
    *(_QWORD *)&this->AccumulatedStats.Triangles = 0i64;
    *(_QWORD *)&this->AccumulatedStats.Primitives = 0i64;
  }
}

// File Line: 1333
// RVA: 0x982EC0
Scaleform::Render::RenderEvent *__fastcall Scaleform::Render::HAL::GetEvent(Scaleform::Render::HAL *this, Scaleform::Render::EventType __formal)
{
  if ( !(_S5_12 & 1) )
  {
    _S5_12 |= 1u;
    defaultEvent.vfptr = (Scaleform::Render::RenderEventVtbl *)&Scaleform::Render::RenderEvent::`vftable';
    atexit(Scaleform::Render::HAL::GetEvent_::_2_::_dynamic_atexit_destructor_for__defaultEvent__);
  }
  return &defaultEvent;
}

// File Line: 1339
// RVA: 0x99F200
void __fastcall Scaleform::Render::HAL::PopFilters(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rdi
  void *v2; // r14
  Scaleform::Render::FilterPrimitive *v3; // rcx
  Scaleform::Render::HAL::FilterStackEntry *v4; // rax
  __int64 *v5; // rsi
  Scaleform::Render::FilterPrimitive *v6; // rax
  __int64 v7; // rcx
  Scaleform::Render::FilterPrimitive *v8; // rcx
  unsigned int v9; // ecx
  Scaleform::RefCountImplCoreVtbl *v10; // rax
  Scaleform::Render::FilterPrimitive *v11; // [rsp+28h] [rbp-40h]
  __int64 v12; // [rsp+30h] [rbp-38h]
  Scaleform::Render::HAL::FilterStackEntry result; // [rsp+38h] [rbp-30h]
  Scaleform::Render::HAL::FilterStackEntry v14; // [rsp+48h] [rbp-20h]

  v1 = this;
  v2 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 12u);
  if ( v1->vfptr[74].__vecDelDtor(
         (Scaleform::RefCountImplCore *)&v1->vfptr,
         (unsigned int)v1->FilterStack.Data.Data[v1->FilterStack.Data.Size - 1].pPrimitive.pObject) )
  {
    v11 = 0i64;
    v12 = 0i64;
    v4 = Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::Pop(
           (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > > *)&v1->FilterStack.Data,
           &v14);
    v5 = (__int64 *)v4;
    v6 = v4->pPrimitive.pObject;
    if ( v6 )
      _InterlockedExchangeAdd(&v6->RefCount, 1u);
    if ( v11 && !_InterlockedDecrement(&v11->RefCount) && v11 )
      v11->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, 1u);
    v11 = (Scaleform::Render::FilterPrimitive *)*v5;
    v7 = v5[1];
    if ( v7 )
      (*(void (**)(void))(*(_QWORD *)v7 + 8i64))();
    if ( v12 )
      (*(void (**)(void))(*(_QWORD *)v12 + 16i64))();
    v12 = v5[1];
    if ( v14.pRenderTarget.pObject )
      ((void (*)(void))v14.pRenderTarget.pObject->vfptr[2].__vecDelDtor)();
    v8 = v14.pPrimitive.pObject;
    if ( v14.pPrimitive.pObject && !_InterlockedDecrement(&v14.pPrimitive.pObject->RefCount) && v8 )
      v8->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, 1u);
    v9 = v1->HALState;
    if ( !_bittest((const signed int *)&v9, 9u)
      && (!_bittest((const signed int *)&v9, 8u) || v1->CacheableIndex >= (signed int)v1->FilterStack.Data.Size) )
    {
      v1->CacheableIndex = -1;
      v10 = v1->vfptr;
      if ( v9 & 0x300 )
      {
        v10[50].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, (unsigned int)v11);
        *(_DWORD *)(((__int64 (__fastcall *)(Scaleform::Render::HAL *))v1->vfptr[64].__vecDelDtor)(v1) + 48) = 0;
        v1->HALState &= 0xFFFFFCFF;
      }
      else
      {
        v10[49].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, (unsigned int)&v11);
      }
      if ( !v1->FilterStack.Data.Size )
        v1->HALState &= 0xFFFFFF7F;
    }
    if ( v12 )
      (*(void (**)(void))(*(_QWORD *)v12 + 16i64))();
    v3 = v11;
  }
  else
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::Pop(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > > *)&v1->FilterStack.Data,
      &result);
    if ( result.pRenderTarget.pObject )
      ((void (*)(void))result.pRenderTarget.pObject->vfptr[2].__vecDelDtor)();
    v3 = result.pPrimitive.pObject;
  }
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) && v3 )
    v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
}

// File Line: 1377
// RVA: 0x9A3940
void __fastcall Scaleform::Render::HAL::PushView3D(Scaleform::Render::HAL *this, Scaleform::Render::Matrix3x4<float> *m)
{
  Scaleform::Render::MatrixState *v2; // r8
  Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *v3; // rcx

  v2 = this->Matrices.pObject;
  v3 = &this->ViewMatrix3DStack.Data;
  v2->View3D = *m;
  LOBYTE(v3[-19].Data[13].M[1][0]) = 1;
  Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
    v3,
    m);
}

// File Line: 1385
// RVA: 0x9A3810
void __fastcall Scaleform::Render::HAL::PushProj3D(Scaleform::Render::HAL *this, Scaleform::Render::Matrix4x4<float> *m)
{
  Scaleform::Render::MatrixState *v2; // r8
  Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *v3; // rcx

  v2 = this->Matrices.pObject;
  v3 = &this->ProjectionMatrix3DStack.Data;
  v2->Proj3D = *m;
  LOBYTE(v3[-20].Data[10].M[0][0]) = 1;
  Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
    v3,
    m);
}

// File Line: 1392
// RVA: 0x99F5D0
void __fastcall Scaleform::Render::HAL::PopView3D(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rdi
  Scaleform::Render::Matrix3x4<float> *v2; // r8
  Scaleform::Render::MatrixState *v3; // rcx

  v1 = this;
  Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->ViewMatrix3DStack.Data,
    this->ViewMatrix3DStack.Data.Size - 1);
  if ( v1->ViewMatrix3DStack.Data.Size )
    v2 = &v1->ViewMatrix3DStack.Data.Data[v1->ViewMatrix3DStack.Data.Size - 1];
  else
    v2 = &Scaleform::Render::Matrix3x4<float>::Identity;
  v3 = v1->Matrices.pObject;
  v3->View3D.M[0][0] = v2->M[0][0];
  v3->View3D.M[0][1] = v2->M[0][1];
  v3->View3D.M[0][2] = v2->M[0][2];
  v3->View3D.M[0][3] = v2->M[0][3];
  v3->View3D.M[1][0] = v2->M[1][0];
  v3->View3D.M[1][1] = v2->M[1][1];
  v3->View3D.M[1][2] = v2->M[1][2];
  v3->View3D.M[1][3] = v2->M[1][3];
  v3->View3D.M[2][0] = v2->M[2][0];
  v3->View3D.M[2][1] = v2->M[2][1];
  v3->View3D.M[2][2] = v2->M[2][2];
  v3->View3D.M[2][3] = v2->M[2][3];
  v1->Matrices.pObject->UVPOChanged = 1;
}

// File Line: 1399
// RVA: 0x99F4C0
void __fastcall Scaleform::Render::HAL::PopProj3D(Scaleform::Render::HAL *this)
{
  Scaleform::Render::HAL *v1; // rdi
  Scaleform::Render::Matrix4x4<float> *v2; // r8
  Scaleform::Render::MatrixState *v3; // rcx

  v1 = this;
  Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->ProjectionMatrix3DStack.Data,
    this->ProjectionMatrix3DStack.Data.Size - 1);
  if ( v1->ProjectionMatrix3DStack.Data.Size )
    v2 = &v1->ProjectionMatrix3DStack.Data.Data[v1->ProjectionMatrix3DStack.Data.Size - 1];
  else
    v2 = &Scaleform::Render::Matrix4x4<float>::Identity;
  v3 = v1->Matrices.pObject;
  v3->Proj3D.M[0][0] = v2->M[0][0];
  v3->Proj3D.M[0][1] = v2->M[0][1];
  v3->Proj3D.M[0][2] = v2->M[0][2];
  v3->Proj3D.M[0][3] = v2->M[0][3];
  v3->Proj3D.M[1][0] = v2->M[1][0];
  v3->Proj3D.M[1][1] = v2->M[1][1];
  v3->Proj3D.M[1][2] = v2->M[1][2];
  v3->Proj3D.M[1][3] = v2->M[1][3];
  v3->Proj3D.M[2][0] = v2->M[2][0];
  v3->Proj3D.M[2][1] = v2->M[2][1];
  v3->Proj3D.M[2][2] = v2->M[2][2];
  v3->Proj3D.M[2][3] = v2->M[2][3];
  v3->Proj3D.M[3][0] = v2->M[3][0];
  v3->Proj3D.M[3][1] = v2->M[3][1];
  v3->Proj3D.M[3][2] = v2->M[3][2];
  v3->Proj3D.M[3][3] = v2->M[3][3];
  v1->Matrices.pObject->UVPOChanged = 1;
}

// File Line: 1406
// RVA: 0x96F410
signed __int64 __fastcall Scaleform::Render::HAL::DrawableCommandGetFlags(Scaleform::Render::HAL *this, Scaleform::Render::DICommand *pcmd)
{
  signed __int64 result; // rax

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
void __fastcall Scaleform::Render::HAL::PushUserData(Scaleform::Render::HAL *this, Scaleform::Render::UserDataState::Data *data)
{
  Scaleform::ArrayLH<Scaleform::Render::UserDataState::Data const *,2,Scaleform::ArrayConstPolicy<0,8,1> > *v2; // rbx
  Scaleform::Render::UserDataState::Data *v3; // rsi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r8
  Scaleform::Render::UserDataState::Data **v7; // rcx
  Scaleform::Render::UserDataState::Data **v8; // rcx

  v2 = &this->UserDataStack;
  v3 = data;
  v4 = this->UserDataStack.Data.Size;
  v5 = v4 + 1;
  if ( v4 + 1 >= v4 )
  {
    if ( v5 <= this->UserDataStack.Data.Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= this->UserDataStack.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = v4 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&this->UserDataStack.Data.Data,
    &this->UserDataStack,
    v6);
LABEL_7:
  v7 = v2->Data.Data;
  v2->Data.Size = v5;
  v8 = &v7[v5 - 1];
  if ( v8 )
    *v8 = v3;
}

// File Line: 1441
// RVA: 0x99F5B0
void __fastcall Scaleform::Render::HAL::PopUserData(Scaleform::Render::HAL *this)
{
  Scaleform::ArrayData<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->UserDataStack.Data,
    this->UserDataStack.Data.Size - 1);
}

