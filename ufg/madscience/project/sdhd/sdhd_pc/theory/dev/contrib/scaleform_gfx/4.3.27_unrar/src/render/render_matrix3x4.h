// File Line: 201
// RVA: 0x8F0C60
void __fastcall Scaleform::Render::Matrix3x4<float>::Prepend(Scaleform::Render::Matrix3x4<float> *this, Scaleform::Render::Matrix3x4<float> *matrixA)
{
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+20h] [rbp-38h]

  *(_OWORD *)&m1.M[0][0] = *(_OWORD *)&this->M[0][0];
  *(_OWORD *)&m1.M[1][0] = *(_OWORD *)&this->M[1][0];
  *(_OWORD *)&m1.M[2][0] = *(_OWORD *)&this->M[2][0];
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(this, &m1, matrixA);
}

// File Line: 294
// RVA: 0x9133F0
void __fastcall Scaleform::Render::Matrix3x4<float>::Transform(Scaleform::Render::Matrix3x4<float> *this, Scaleform::Render::Point<float> *result, Scaleform::Render::Point<float> *p)
{
  float v3; // xmm3_4

  v3 = (float)((float)((float)(p->y * this->M[0][1]) + (float)(p->x * this->M[0][0])) + this->M[0][2]) + this->M[0][3];
  result->y = (float)((float)((float)(p->x * this->M[1][0]) + (float)(p->y * this->M[1][1])) + this->M[1][2])
            + this->M[1][3];
  result->x = v3;
}

// File Line: 296
// RVA: 0x9133A0
Scaleform::Render::Point<float> *__fastcall Scaleform::Render::Matrix3x4<float>::Transform(Scaleform::Render::Matrix3x4<float> *this, Scaleform::Render::Point<float> *result, Scaleform::Render::Point<float> *p)
{
  Scaleform::Render::Point<float> *v3; // rax
  float v4; // xmm3_4

  v3 = result;
  v4 = (float)((float)((float)(p->x * this->M[1][0]) + (float)(p->y * this->M[1][1])) + this->M[1][2]) + this->M[1][3];
  result->x = (float)((float)((float)(p->y * this->M[0][1]) + (float)(p->x * this->M[0][0])) + this->M[0][2])
            + this->M[0][3];
  result->y = v4;
  return v3;
}

// File Line: 311
// RVA: 0x8C8100
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::Matrix3x4<float>::EncloseTransform(Scaleform::Render::Matrix3x4<float> *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Rect<float> *r)
{
  Scaleform::Render::Rect<float> *v3; // rbx

  v3 = result;
  Scaleform::Render::Matrix3x4<float>::EncloseTransform(this, result, r);
  return v3;
}

// File Line: 423
// RVA: 0x700FB0
char __fastcall Scaleform::Render::Matrix3x4<float>::IsValid(Scaleform::Render::Matrix3x4<float> *this)
{
  float v1; // xmm2_4
  float v2; // xmm2_4
  float v3; // xmm2_4
  float v4; // xmm2_4
  float v5; // xmm2_4
  float v6; // xmm2_4
  float v7; // xmm2_4
  float v8; // xmm2_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm2_4
  char result; // al

  if ( this->M[0][0] < -3.4028235e38 )
    goto LABEL_29;
  if ( this->M[0][0] > 3.4028235e38 )
    goto LABEL_29;
  v1 = this->M[0][1];
  if ( v1 < -3.4028235e38 )
    goto LABEL_29;
  if ( v1 > 3.4028235e38 )
    goto LABEL_29;
  v2 = this->M[0][2];
  if ( v2 < -3.4028235e38 )
    goto LABEL_29;
  if ( v2 > 3.4028235e38 )
    goto LABEL_29;
  v3 = this->M[0][3];
  if ( v3 < -3.4028235e38 )
    goto LABEL_29;
  if ( v3 > 3.4028235e38 )
    goto LABEL_29;
  v4 = this->M[1][0];
  if ( v4 < -3.4028235e38
    || v4 > 3.4028235e38
    || (v5 = this->M[1][1], v5 < -3.4028235e38)
    || v5 > 3.4028235e38
    || (v6 = this->M[1][2], v6 < -3.4028235e38)
    || v6 > 3.4028235e38
    || (v7 = this->M[1][3], v7 < -3.4028235e38)
    || v7 > 3.4028235e38
    || (v8 = this->M[2][0], v8 < -3.4028235e38)
    || v8 > 3.4028235e38
    || (v9 = this->M[2][1], v9 < -3.4028235e38)
    || v9 > 3.4028235e38
    || (v10 = this->M[2][2], v10 < -3.4028235e38)
    || v10 > 3.4028235e38
    || (v11 = this->M[2][3], v11 < -3.4028235e38)
    || v11 > 3.4028235e38 )
  {
LABEL_29:
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

// File Line: 475
// RVA: 0x5AF50
void __fastcall Scaleform::Render::Matrix3x4<float>::SetIdentity(Scaleform::Render::Matrix3x4<float> *this)
{
  Scaleform::Render::Matrix3x4<float> *v1; // rbx

  v1 = this;
  memset(this, 0, 0x30ui64);
  v1->M[0][0] = 1.0;
  v1->M[1][1] = 1.0;
  v1->M[2][2] = 1.0;
}

// File Line: 564
// RVA: 0x6EF850
void __fastcall Scaleform::Render::Matrix3x4<float>::GetEulerAngles(Scaleform::Render::Matrix3x4<float> *this, float *eX, float *eY, float *eZ)
{
  float *v4; // rbx
  float *v5; // rdi
  float v6; // xmm7_4
  float v7; // xmm8_4
  __m128 v8; // xmm9
  __m128 v9; // xmm11
  __m128 v10; // xmm6
  __m128 v11; // xmm2
  float v12; // xmm10_4
  float v13; // ST2C_4
  float v14; // ST3C_4
  float v15; // ST4C_4
  float v16; // xmm0_4
  __m128 v17; // xmm2
  float v18; // xmm1_4
  __m128 v19; // xmm0
  float v20; // xmm9_4
  float v21; // xmm7_4
  float v22; // xmm11_4
  float v23; // xmm4_4
  float v24; // xmm8_4
  float v25; // xmm6_4
  float v26; // xmm10_4

  v4 = eZ;
  v5 = eX;
  v6 = this->M[2][0];
  v7 = this->M[0][2];
  v8 = (__m128)LODWORD(this->M[1][0]);
  v9 = (__m128)LODWORD(this->M[1][1]);
  v10 = (__m128)LODWORD(this->M[1][2]);
  v11 = v8;
  v12 = this->M[2][2];
  v13 = this->M[0][3];
  v14 = this->M[1][3];
  v15 = this->M[2][3];
  v11.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(this->M[0][0] * this->M[0][0]))
                  + (float)(v6 * v6);
  LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v11);
  v17 = v10;
  v18 = 1.0 / v16;
  v19 = v9;
  v20 = v8.m128_f32[0] * v18;
  v21 = v6 * v18;
  v19.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(this->M[0][1] * this->M[0][1]))
                  + (float)(this->M[2][1] * this->M[2][1]);
  v22 = v9.m128_f32[0] * (float)(1.0 / COERCE_FLOAT(_mm_sqrt_ps(v19)));
  v17.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v7 * v7)) + (float)(v12 * v12);
  v23 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v17));
  v24 = v7 * v23;
  v25 = v10.m128_f32[0] * v23;
  v26 = v12 * v23;
  if ( v20 <= 0.99800003 )
  {
    if ( v20 >= -0.99800003 )
    {
      if ( eY )
        *eY = atan2f(COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]), this->M[0][0] * v18);
      if ( v5 )
        *v5 = atan2f(COERCE_FLOAT(LODWORD(v25) ^ _xmm[0]), v22);
      if ( v4 )
        *v4 = asinf(v20);
    }
    else
    {
      if ( eY )
        *eY = atan2f(v24, v26);
      if ( v4 )
        *v4 = -1.5707964;
      if ( v5 )
        *v5 = 0.0;
    }
  }
  else
  {
    if ( eY )
      *eY = atan2f(v24, v26);
    if ( v4 )
      *v4 = 1.5707964;
    if ( v5 )
      *v5 = 0.0;
  }
}

// File Line: 771
// RVA: 0x919380
void __fastcall Scaleform::Render::Matrix3x4<float>::ViewRH(Scaleform::Render::Matrix3x4<float> *this, Scaleform::Render::Point3<float> *eyePt, Scaleform::Render::Point3<float> *lookAtPt, Scaleform::Render::Point3<float> *upVec)
{
  __m128 v4; // xmm5
  float v5; // xmm4_4
  float v6; // xmm3_4
  __m128 v7; // xmm2
  float v8; // xmm0_4
  Scaleform::Render::Point3<float> zAxis; // [rsp+20h] [rbp-18h]

  v4 = (__m128)LODWORD(eyePt->x);
  v4.m128_f32[0] = v4.m128_f32[0] - lookAtPt->x;
  v5 = eyePt->y - lookAtPt->y;
  v6 = eyePt->z - lookAtPt->z;
  v7 = v4;
  v7.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v5 * v5)) + (float)(v6 * v6);
  LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v7);
  zAxis.x = v4.m128_f32[0] * (float)(1.0 / v8);
  zAxis.y = v5 * (float)(1.0 / v8);
  zAxis.z = v6 * (float)(1.0 / v8);
  Scaleform::Render::Matrix3x4<float>::View(this, eyePt, &zAxis, upVec);
}

// File Line: 781
// RVA: 0x919300
void __fastcall Scaleform::Render::Matrix3x4<float>::ViewLH(Scaleform::Render::Matrix3x4<float> *this, Scaleform::Render::Point3<float> *eyePt, Scaleform::Render::Point3<float> *lookAtPt, Scaleform::Render::Point3<float> *upVec)
{
  __m128 v4; // xmm5
  float v5; // xmm4_4
  float v6; // xmm3_4
  __m128 v7; // xmm2
  float v8; // xmm0_4
  Scaleform::Render::Point3<float> zAxis; // [rsp+20h] [rbp-18h]

  v4 = (__m128)LODWORD(lookAtPt->x);
  v4.m128_f32[0] = v4.m128_f32[0] - eyePt->x;
  v5 = lookAtPt->y - eyePt->y;
  v6 = lookAtPt->z - eyePt->z;
  v7 = v4;
  v7.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v5 * v5)) + (float)(v6 * v6);
  LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v7);
  zAxis.x = v4.m128_f32[0] * (float)(1.0 / v8);
  zAxis.y = v5 * (float)(1.0 / v8);
  zAxis.z = v6 * (float)(1.0 / v8);
  Scaleform::Render::Matrix3x4<float>::View(this, eyePt, &zAxis, upVec);
}

// File Line: 790
// RVA: 0x919170
void __fastcall Scaleform::Render::Matrix3x4<float>::View(Scaleform::Render::Matrix3x4<float> *this, Scaleform::Render::Point3<float> *eyePt, Scaleform::Render::Point3<float> *zAxis, Scaleform::Render::Point3<float> *upVec)
{
  float v4; // xmm3_4
  float v5; // xmm8_4
  float v6; // xmm7_4
  __m128 v7; // xmm4
  float v8; // xmm6_4
  __m128 v9; // xmm2
  float v10; // xmm5_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm5_4
  float v15; // xmm8_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm6_4
  float v19; // xmm8_4
  float v20; // xmm5_4
  float v21; // xmm7_4
  float v22; // xmm7_4

  v4 = zAxis->y;
  v5 = zAxis->z;
  v6 = zAxis->x;
  v7 = (__m128)LODWORD(zAxis->x);
  v8 = (float)(upVec->y * v5) - (float)(upVec->z * v4);
  v7.m128_f32[0] = (float)(v7.m128_f32[0] * upVec->z) - (float)(upVec->x * v5);
  v9 = v7;
  v10 = (float)(upVec->x * v4) - (float)(zAxis->x * upVec->y);
  v9.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
  v11 = zAxis->y;
  v9.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
  v12 = zAxis->z;
  v13 = v8 * v9.m128_f32[0];
  v7.m128_f32[0] = v7.m128_f32[0] * v9.m128_f32[0];
  v14 = v10 * v9.m128_f32[0];
  this->M[0][0] = v13;
  LODWORD(this->M[0][1]) = v7.m128_i32[0];
  this->M[0][2] = v14;
  v15 = v5 * v13;
  v16 = (float)(v11 * v14) - (float)(v12 * v7.m128_f32[0]);
  v17 = v4 * v13;
  v18 = v13 * eyePt->x;
  v19 = v15 - (float)(v6 * v14);
  v20 = v14 * eyePt->z;
  v21 = v6 * v7.m128_f32[0];
  v7.m128_f32[0] = v7.m128_f32[0] * eyePt->y;
  this->M[1][0] = v16;
  this->M[1][1] = v19;
  v22 = v21 - v17;
  this->M[1][2] = v22;
  LODWORD(this->M[0][3]) = COERCE_UNSIGNED_INT((float)(v18 + v7.m128_f32[0]) + v20) ^ _xmm[0];
  LODWORD(this->M[1][3]) = COERCE_UNSIGNED_INT((float)((float)(v16 * eyePt->x) + (float)(v19 * eyePt->y)) + (float)(v22 * eyePt->z)) ^ _xmm[0];
  *(_QWORD *)&this->M[2][0] = *(_QWORD *)&zAxis->x;
  this->M[2][2] = zAxis->z;
  LODWORD(this->M[2][3]) = COERCE_UNSIGNED_INT(
                             (float)((float)(zAxis->y * eyePt->y) + (float)(eyePt->x * zAxis->x))
                           + (float)(eyePt->z * zAxis->z)) ^ _xmm[0];
}

// File Line: 821
// RVA: 0x8C8120
void __fastcall Scaleform::Render::Matrix3x4<float>::EncloseTransform(Scaleform::Render::Matrix3x4<float> *this, Scaleform::Render::Rect<float> *pr, Scaleform::Render::Rect<float> *r)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm4_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm8_4
  float v9; // xmm9_4
  float v10; // xmm3_4
  float v11; // xmm5_4
  float v12; // xmm13_4
  float v13; // xmm12_4
  float v14; // xmm15_4
  float v15; // xmm10_4
  float v16; // xmm11_4
  float v17; // xmm0_4
  float v18; // xmm14_4
  float v19; // xmm1_4
  float v20; // xmm14_4
  float v21; // xmm15_4
  float v22; // xmm13_4
  float v23; // xmm2_4
  float v24; // xmm12_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // [rsp+B8h] [rbp+10h]

  v3 = r->y1;
  v4 = r->x2;
  v5 = this->M[1][0];
  v6 = this->M[0][1];
  v7 = this->M[0][2];
  v8 = this->M[0][3];
  v9 = r->x1;
  v10 = this->M[1][2];
  v11 = this->M[1][3];
  v12 = this->M[0][0];
  v13 = this->M[1][1];
  v14 = this->M[0][0];
  v15 = (float)((float)((float)(this->M[0][0] * r->x1) + (float)(this->M[0][1] * v3)) + v7) + v8;
  v16 = (float)((float)((float)(this->M[1][1] * v3) + (float)(this->M[1][0] * r->x1)) + v10) + v11;
  v17 = this->M[1][0] * v4;
  v27 = (float)((float)((float)(this->M[0][0] * v4) + (float)(this->M[0][1] * v3)) + v7) + v8;
  v18 = v13 * v3;
  v19 = r->y2;
  pr->x1 = v15;
  pr->y1 = v16;
  pr->x2 = v15;
  pr->y2 = v16;
  v20 = (float)((float)(v18 + v17) + v10) + v11;
  v21 = (float)((float)((float)(v14 * v4) + (float)(v6 * v19)) + v7) + v8;
  v22 = (float)((float)((float)(v12 * v9) + (float)(v6 * v19)) + v7) + v8;
  v23 = (float)((float)((float)(v13 * v19) + (float)(v5 * v4)) + v10) + v11;
  v24 = (float)((float)((float)(v13 * v19) + (float)(v5 * v9)) + v10) + v11;
  if ( v15 >= v27 )
    v25 = v27;
  else
    v25 = v15;
  pr->x1 = v25;
  if ( v16 >= v20 )
    v26 = v20;
  else
    v26 = v16;
  pr->y1 = v26;
  if ( v27 >= v15 )
    v15 = v27;
  pr->x2 = v15;
  if ( v20 >= v16 )
    v16 = v20;
  pr->y2 = v16;
  if ( v25 >= v21 )
    v25 = v21;
  pr->x1 = v25;
  if ( v26 >= v23 )
    v26 = v23;
  pr->y1 = v26;
  if ( v21 >= v15 )
    v15 = v21;
  pr->x2 = v15;
  if ( v23 >= v16 )
    v16 = v23;
  pr->y2 = v16;
  if ( v25 >= v22 )
    v25 = v22;
  pr->x1 = v25;
  if ( v26 >= v24 )
    v26 = v24;
  pr->y1 = v26;
  if ( v22 >= v15 )
    v15 = v22;
  pr->x2 = v15;
  if ( v24 >= v16 )
    pr->y2 = v24;
  else
    pr->y2 = v16;
}

// File Line: 838
// RVA: 0x7EAA80
Scaleform::Render::Matrix3x4<float> *__fastcall Scaleform::Render::Matrix3x4<float>::GetInverse(Scaleform::Render::Matrix3x4<float> *this, Scaleform::Render::Matrix3x4<float> *result)
{
  Scaleform::Render::Matrix3x4<float> *v2; // rbx
  float v3; // xmm7_4
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm12_4
  float v8; // xmm10_4
  float v9; // xmm8_4
  float v10; // xmm14_4
  float v11; // xmm4_4
  float v12; // xmm8_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  float v15; // xmm6_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm15_4
  float v19; // xmm11_4
  float v20; // xmm3_4
  int v21; // xmm0_4
  int v22; // xmm1_4
  int v23; // xmm0_4
  int v24; // xmm1_4
  int v25; // xmm0_4
  int v26; // xmm0_4
  float v27; // xmm10_4
  float v28; // xmm8_4
  float v29; // xmm1_4
  float v30; // xmm5_4
  float v31; // xmm7_4
  float v32; // xmm9_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm6_4
  float v36; // xmm0_4
  float v37; // xmm9_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  float v40; // xmm7_4
  float v41; // xmm9_4
  float v42; // xmm0_4
  float v43; // xmm3_4
  float v44; // xmm14_4
  float v45; // xmm3_4
  float v46; // xmm0_4
  float v47; // xmm0_4
  float v48; // xmm12_4
  float v49; // xmm6_4
  float v50; // xmm14_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm14_4
  float v54; // xmm15_4
  float v55; // xmm0_4
  float v56; // xmm2_4
  float v57; // xmm12_4
  float v58; // xmm2_4
  float v59; // xmm0_4
  float v60; // xmm15_4
  float v61; // xmm3_4
  float v62; // xmm1_4
  float v63; // xmm0_4
  float v64; // xmm6_4
  float v65; // xmm14_4
  float v66; // xmm3_4
  float v68; // [rsp+20h] [rbp-E8h]
  float v69; // [rsp+24h] [rbp-E4h]
  char Dst; // [rsp+30h] [rbp-D8h]
  int v71; // [rsp+34h] [rbp-D4h]
  int v72; // [rsp+38h] [rbp-D0h]
  int v73; // [rsp+40h] [rbp-C8h]
  int v74; // [rsp+48h] [rbp-C0h]
  int v75; // [rsp+50h] [rbp-B8h]
  int v76; // [rsp+54h] [rbp-B4h]
  float v77; // [rsp+110h] [rbp+8h]
  float v78; // [rsp+120h] [rbp+18h]
  unsigned int v79; // [rsp+120h] [rbp+18h]
  float v80; // [rsp+128h] [rbp+20h]

  v2 = result;
  v3 = this->M[0][3];
  v4 = this->M[2][2] * 0.0;
  v5 = this->M[2][0] * 0.0;
  v6 = this->M[2][1] * 0.0;
  v7 = this->M[1][3];
  v8 = this->M[1][0];
  v9 = v5;
  v10 = this->M[2][3];
  v11 = v5 - v4;
  v12 = v9 - v6;
  v13 = v6 - v4;
  v14 = this->M[2][3] * 0.0;
  v15 = this->M[2][2] - v14;
  v16 = this->M[2][0] - v14;
  v17 = this->M[2][1] - v14;
  v80 = v16;
  v18 = (float)((float)(v15 * this->M[1][1]) - (float)(v17 * this->M[1][2])) + (float)(v13 * v7);
  v78 = this->M[2][1] - v14;
  v68 = v12;
  LODWORD(v19) = COERCE_UNSIGNED_INT((float)((float)(v15 * v8) - (float)(v16 * this->M[1][2])) + (float)(v11 * v7)) ^ _xmm[0];
  v69 = (float)((float)(v17 * v8) - (float)(v16 * this->M[1][1])) + (float)(v12 * v7);
  v20 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v13 * v8) - (float)(v11 * this->M[1][1])) + (float)(v12 * this->M[1][2])) ^ _xmm[0])
              * v3)
      + (float)((float)((float)(v19 * this->M[0][1]) + (float)(v18 * this->M[0][0])) + (float)(v69 * this->M[0][2]));
  if ( v20 == 0.0 )
  {
    memset(&Dst, 0, 0x30ui64);
    v21 = v71;
    v22 = v72;
    LODWORD(v2->M[0][0]) = (_DWORD)FLOAT_1_0;
    LODWORD(v2->M[0][1]) = v21;
    v23 = v73;
    LODWORD(v2->M[0][2]) = v22;
    v24 = v76;
    LODWORD(v2->M[0][3]) = LODWORD(v3) ^ _xmm[0];
    LODWORD(v2->M[1][0]) = v23;
    v25 = v74;
    LODWORD(v2->M[1][1]) = (_DWORD)FLOAT_1_0;
    LODWORD(v2->M[1][2]) = v25;
    v26 = v75;
    LODWORD(v2->M[1][3]) = LODWORD(v7) ^ _xmm[0];
    LODWORD(v2->M[2][0]) = v26;
    LODWORD(v2->M[2][1]) = v24;
    LODWORD(v2->M[2][2]) = (_DWORD)FLOAT_1_0;
    LODWORD(v2->M[2][3]) = LODWORD(v10) ^ _xmm[0];
  }
  else
  {
    v27 = 1.0 / v20;
    v28 = (float)((float)((float)(v15 * this->M[0][1]) - (float)(v78 * this->M[0][2])) + (float)(v13 * v3))
        * (float)(1.0 / v20);
    v29 = (float)((float)(v78 * this->M[0][0]) - (float)(v80 * this->M[0][1])) + (float)(v68 * v3);
    v77 = (float)((float)((float)(v15 * this->M[0][0]) - (float)(v80 * this->M[0][2])) + (float)(v11 * v3))
        * (float)(1.0 / v20);
    v30 = this->M[1][0] - (float)(v7 * 0.0);
    v31 = this->M[1][2] - (float)(v7 * 0.0);
    v79 = COERCE_UNSIGNED_INT(v29 * (float)(1.0 / v20)) ^ _xmm[0];
    v33 = this->M[1][2] * 0.0;
    v32 = this->M[1][1] - (float)(v7 * 0.0);
    v34 = this->M[1][0] * 0.0;
    v35 = (float)((float)(v31 * this->M[0][1]) - (float)(v32 * this->M[0][2]))
        + (float)((float)((float)(this->M[1][1] * 0.0) - v33) * this->M[0][3]);
    v36 = v30 * this->M[0][2];
    v37 = (float)(v32 * this->M[0][0]) - (float)(v30 * this->M[0][1]);
    v38 = this->M[0][3];
    v39 = (float)(v10 * this->M[1][0]) - (float)(this->M[2][0] * v7);
    v40 = (float)((float)((float)(v31 * this->M[0][0]) - v36) + (float)((float)(v34 - v33) * this->M[0][3])) * v27;
    v41 = (float)(v37 + (float)((float)(v34 - (float)(this->M[1][1] * 0.0)) * v38)) * v27;
    v42 = this->M[2][1];
    v43 = this->M[2][3];
    v44 = v10 * this->M[1][2];
    result->M[0][2] = v35 * v27;
    LODWORD(result->M[0][1]) = LODWORD(v28) ^ _xmm[0];
    v45 = (float)(v43 * this->M[1][1]) - (float)(v42 * v7);
    v46 = this->M[2][2];
    result->M[1][1] = v77;
    v47 = v46 * v7;
    v48 = this->M[2][1];
    v49 = this->M[2][0];
    v50 = v44 - v47;
    v51 = v27 * v18;
    v52 = v50 * this->M[0][1];
    v53 = v50 * this->M[0][0];
    v54 = this->M[2][2];
    result->M[0][0] = v51;
    LODWORD(result->M[1][2]) = LODWORD(v40) ^ _xmm[0];
    v55 = v48 * this->M[1][2];
    v56 = v54 * this->M[1][1];
    v57 = v48 * this->M[1][0];
    result->M[2][2] = v41;
    v58 = v56 - v55;
    v59 = v45 * this->M[0][2];
    v60 = v54 * this->M[1][0];
    v61 = v45 * this->M[0][0];
    v62 = v52 - v59;
    result->M[1][0] = v27 * v19;
    v63 = v49 * this->M[1][2];
    v64 = v49 * this->M[1][1];
    v65 = v53 - (float)(v39 * this->M[0][2]);
    v66 = v61 - (float)(v39 * this->M[0][1]);
    LODWORD(result->M[0][3]) = COERCE_UNSIGNED_INT((float)((float)(v58 * v38) + v62) * v27) ^ _xmm[0];
    result->M[2][0] = v27 * v69;
    LODWORD(result->M[2][1]) = v79;
    result->M[1][3] = (float)((float)((float)(v60 - v63) * v38) + v65) * v27;
    LODWORD(result->M[2][3]) = COERCE_UNSIGNED_INT((float)((float)((float)(v57 - v64) * v38) + v66) * v27) ^ _xmm[0];
  }
  return v2;
}

