// File Line: 201
// RVA: 0x8F0C60
void __fastcall Scaleform::Render::Matrix3x4<float>::Prepend(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Matrix3x4<float> *matrixA)
{
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+20h] [rbp-38h] BYREF

  m1 = *this;
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(this, &m1, matrixA);
}

// File Line: 294
// RVA: 0x9133F0
void __fastcall Scaleform::Render::Matrix3x4<float>::Transform(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Point<float> *result,
        Scaleform::Render::Point<float> *p)
{
  float v3; // xmm3_4

  v3 = (float)((float)((float)(p->y * this->M[0][1]) + (float)(p->x * this->M[0][0])) + this->M[0][2]) + this->M[0][3];
  result->y = (float)((float)((float)(p->x * this->M[1][0]) + (float)(p->y * this->M[1][1])) + this->M[1][2])
            + this->M[1][3];
  result->x = v3;
}

// File Line: 296
// RVA: 0x9133A0
Scaleform::Render::Point<float> *__fastcall Scaleform::Render::Matrix3x4<float>::Transform(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Point<float> *result,
        Scaleform::Render::Point<float> *p)
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
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::Matrix3x4<float>::EncloseTransform(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Rect<float> *r)
{
  Scaleform::Render::Matrix3x4<float>::EncloseTransform(this, result, r);
  return result;
}

// File Line: 423
// RVA: 0x700FB0
bool __fastcall Scaleform::Render::Matrix3x4<float>::IsValid(Scaleform::Render::Matrix3x4<float> *this)
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

  if ( this->M[0][0] < -3.4028235e38 )
    return 0;
  if ( this->M[0][0] > 3.4028235e38 )
    return 0;
  v1 = this->M[0][1];
  if ( v1 < -3.4028235e38 )
    return 0;
  if ( v1 > 3.4028235e38 )
    return 0;
  v2 = this->M[0][2];
  if ( v2 < -3.4028235e38 )
    return 0;
  if ( v2 > 3.4028235e38 )
    return 0;
  v3 = this->M[0][3];
  if ( v3 < -3.4028235e38 )
    return 0;
  if ( v3 > 3.4028235e38 )
    return 0;
  v4 = this->M[1][0];
  if ( v4 < -3.4028235e38 )
    return 0;
  if ( v4 > 3.4028235e38 )
    return 0;
  v5 = this->M[1][1];
  if ( v5 < -3.4028235e38 )
    return 0;
  if ( v5 > 3.4028235e38 )
    return 0;
  v6 = this->M[1][2];
  if ( v6 < -3.4028235e38 )
    return 0;
  if ( v6 > 3.4028235e38 )
    return 0;
  v7 = this->M[1][3];
  if ( v7 < -3.4028235e38 )
    return 0;
  if ( v7 > 3.4028235e38 )
    return 0;
  v8 = this->M[2][0];
  if ( v8 < -3.4028235e38 )
    return 0;
  if ( v8 > 3.4028235e38 )
    return 0;
  v9 = this->M[2][1];
  if ( v9 < -3.4028235e38 )
    return 0;
  if ( v9 > 3.4028235e38 )
    return 0;
  v10 = this->M[2][2];
  if ( v10 < -3.4028235e38 )
    return 0;
  if ( v10 > 3.4028235e38 )
    return 0;
  v11 = this->M[2][3];
  return v11 >= -3.4028235e38 && v11 <= 3.4028235e38;
}

// File Line: 475
// RVA: 0x5AF50
void __fastcall Scaleform::Render::Matrix3x4<float>::SetIdentity(Scaleform::Render::Matrix3x4<float> *this)
{
  memset(this, 0, sizeof(Scaleform::Render::Matrix3x4<float>));
  this->M[0][0] = 1.0;
  this->M[1][1] = 1.0;
  this->M[2][2] = 1.0;
}

// File Line: 564
// RVA: 0x6EF850
void __fastcall Scaleform::Render::Matrix3x4<float>::GetEulerAngles(
        Scaleform::Render::Matrix3x4<float> *this,
        float *eX,
        float *eY,
        float *eZ)
{
  float v6; // xmm7_4
  float v7; // xmm8_4
  __m128 v8; // xmm9
  __m128 v9; // xmm11
  __m128 v10; // xmm6
  __m128 v11; // xmm2
  float v12; // xmm10_4
  float v13; // xmm0_4
  __m128 v14; // xmm2
  float v15; // xmm1_4
  __m128 v16; // xmm0
  float v17; // xmm9_4
  float v18; // xmm7_4
  float v19; // xmm11_4
  float v20; // xmm4_4
  float v21; // xmm8_4
  float v22; // xmm6_4
  float v23; // xmm10_4

  v6 = this->M[2][0];
  v7 = this->M[0][2];
  v8 = (__m128)LODWORD(this->M[1][0]);
  v9 = (__m128)LODWORD(this->M[1][1]);
  v10 = (__m128)LODWORD(this->M[1][2]);
  v11 = v8;
  v12 = this->M[2][2];
  v11.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(this->M[0][0] * this->M[0][0]))
                  + (float)(v6 * v6);
  v13 = _mm_sqrt_ps(v11).m128_f32[0];
  v14 = v10;
  v15 = 1.0 / v13;
  v16 = v9;
  v17 = v8.m128_f32[0] * v15;
  v18 = v6 * v15;
  v16.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(this->M[0][1] * this->M[0][1]))
                  + (float)(this->M[2][1] * this->M[2][1]);
  v19 = v9.m128_f32[0] * (float)(1.0 / _mm_sqrt_ps(v16).m128_f32[0]);
  v14.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v7 * v7)) + (float)(v12 * v12);
  v20 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
  v21 = v7 * v20;
  v22 = v10.m128_f32[0] * v20;
  v23 = v12 * v20;
  if ( v17 <= 0.99800003 )
  {
    if ( v17 >= -0.99800003 )
    {
      if ( eY )
        *eY = atan2f(COERCE_FLOAT(LODWORD(v18) ^ _xmm[0]), this->M[0][0] * v15);
      if ( eX )
        *eX = atan2f(COERCE_FLOAT(LODWORD(v22) ^ _xmm[0]), v19);
      if ( eZ )
        *eZ = asinf(v17);
    }
    else
    {
      if ( eY )
        *eY = atan2f(v21, v23);
      if ( eZ )
        *eZ = -1.5707964;
      if ( eX )
        *eX = 0.0;
    }
  }
  else
  {
    if ( eY )
      *eY = atan2f(v21, v23);
    if ( eZ )
      *eZ = 1.5707964;
    if ( eX )
      *eX = 0.0;
  }
}

// File Line: 771
// RVA: 0x919380
void __fastcall Scaleform::Render::Matrix3x4<float>::ViewRH(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Point3<float> *eyePt,
        Scaleform::Render::Point3<float> *lookAtPt,
        Scaleform::Render::Point3<float> *upVec)
{
  __m128 x_low; // xmm5
  float v5; // xmm4_4
  float v6; // xmm3_4
  __m128 v7; // xmm2
  float v8; // xmm0_4
  Scaleform::Render::Point3<float> zAxis; // [rsp+20h] [rbp-18h] BYREF

  x_low = (__m128)LODWORD(eyePt->x);
  x_low.m128_f32[0] = x_low.m128_f32[0] - lookAtPt->x;
  v5 = eyePt->y - lookAtPt->y;
  v6 = eyePt->z - lookAtPt->z;
  v7 = x_low;
  v7.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v5 * v5)) + (float)(v6 * v6);
  v8 = _mm_sqrt_ps(v7).m128_f32[0];
  zAxis.x = x_low.m128_f32[0] * (float)(1.0 / v8);
  zAxis.y = v5 * (float)(1.0 / v8);
  zAxis.z = v6 * (float)(1.0 / v8);
  Scaleform::Render::Matrix3x4<float>::View(this, eyePt, &zAxis, upVec);
}

// File Line: 781
// RVA: 0x919300
void __fastcall Scaleform::Render::Matrix3x4<float>::ViewLH(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Point3<float> *eyePt,
        Scaleform::Render::Point3<float> *lookAtPt,
        Scaleform::Render::Point3<float> *upVec)
{
  __m128 x_low; // xmm5
  float v5; // xmm4_4
  float v6; // xmm3_4
  __m128 v7; // xmm2
  float v8; // xmm0_4
  Scaleform::Render::Point3<float> zAxis; // [rsp+20h] [rbp-18h] BYREF

  x_low = (__m128)LODWORD(lookAtPt->x);
  x_low.m128_f32[0] = x_low.m128_f32[0] - eyePt->x;
  v5 = lookAtPt->y - eyePt->y;
  v6 = lookAtPt->z - eyePt->z;
  v7 = x_low;
  v7.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v5 * v5)) + (float)(v6 * v6);
  v8 = _mm_sqrt_ps(v7).m128_f32[0];
  zAxis.x = x_low.m128_f32[0] * (float)(1.0 / v8);
  zAxis.y = v5 * (float)(1.0 / v8);
  zAxis.z = v6 * (float)(1.0 / v8);
  Scaleform::Render::Matrix3x4<float>::View(this, eyePt, &zAxis, upVec);
}

// File Line: 790
// RVA: 0x919170
void __fastcall Scaleform::Render::Matrix3x4<float>::View(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Point3<float> *eyePt,
        Scaleform::Render::Point3<float> *zAxis,
        Scaleform::Render::Point3<float> *upVec)
{
  float y; // xmm3_4
  float z; // xmm8_4
  float x; // xmm7_4
  __m128 x_low; // xmm4
  float v8; // xmm6_4
  __m128 v9; // xmm2
  float v10; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm5_4
  float v14; // xmm8_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm6_4
  float v18; // xmm8_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  float v21; // xmm7_4

  y = zAxis->y;
  z = zAxis->z;
  x = zAxis->x;
  x_low = (__m128)LODWORD(zAxis->x);
  v8 = (float)(upVec->y * z) - (float)(upVec->z * y);
  x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * upVec->z) - (float)(upVec->x * z);
  v9 = x_low;
  v10 = (float)(upVec->x * y) - (float)(zAxis->x * upVec->y);
  v9.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
  v9.m128_f32[0] = 1.0 / _mm_sqrt_ps(v9).m128_f32[0];
  v11 = z;
  v12 = v8 * v9.m128_f32[0];
  x_low.m128_f32[0] = x_low.m128_f32[0] * v9.m128_f32[0];
  v13 = v10 * v9.m128_f32[0];
  this->M[0][0] = v12;
  LODWORD(this->M[0][1]) = x_low.m128_i32[0];
  this->M[0][2] = v13;
  v14 = z * v12;
  v15 = (float)(y * v13) - (float)(v11 * x_low.m128_f32[0]);
  v16 = y * v12;
  v17 = v12 * eyePt->x;
  v18 = v14 - (float)(x * v13);
  v19 = v13 * eyePt->z;
  v20 = x * x_low.m128_f32[0];
  x_low.m128_f32[0] = x_low.m128_f32[0] * eyePt->y;
  this->M[1][0] = v15;
  this->M[1][1] = v18;
  v21 = v20 - v16;
  this->M[1][2] = v21;
  LODWORD(this->M[0][3]) = COERCE_UNSIGNED_INT((float)(v17 + x_low.m128_f32[0]) + v19) ^ _xmm[0];
  LODWORD(this->M[1][3]) = COERCE_UNSIGNED_INT((float)((float)(v15 * eyePt->x) + (float)(v18 * eyePt->y)) + (float)(v21 * eyePt->z)) ^ _xmm[0];
  *(Scaleform::Render::Point3<float> *)&this->M[2][0] = *zAxis;
  LODWORD(this->M[2][3]) = COERCE_UNSIGNED_INT(
                             (float)((float)(zAxis->y * eyePt->y) + (float)(eyePt->x * zAxis->x))
                           + (float)(eyePt->z * zAxis->z)) ^ _xmm[0];
}

// File Line: 821
// RVA: 0x8C8120
void __fastcall Scaleform::Render::Matrix3x4<float>::EncloseTransform(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Rect<float> *pr,
        Scaleform::Render::Rect<float> *r)
{
  float y1; // xmm1_4
  float x2; // xmm2_4
  float v5; // xmm4_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm8_4
  float x1; // xmm9_4
  float v10; // xmm3_4
  float v11; // xmm5_4
  float v12; // xmm13_4
  float v13; // xmm12_4
  float v14; // xmm15_4
  float v15; // xmm10_4
  float v16; // xmm11_4
  float v17; // xmm14_4
  float y2; // xmm1_4
  float v19; // xmm14_4
  float v20; // xmm15_4
  float v21; // xmm13_4
  float v22; // xmm2_4
  float v23; // xmm12_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // [rsp+B8h] [rbp+10h]

  y1 = r->y1;
  x2 = r->x2;
  v5 = this->M[1][0];
  v6 = this->M[0][1];
  v7 = this->M[0][2];
  v8 = this->M[0][3];
  x1 = r->x1;
  v10 = this->M[1][2];
  v11 = this->M[1][3];
  v12 = this->M[0][0];
  v13 = this->M[1][1];
  v14 = this->M[0][0];
  v15 = (float)((float)((float)(this->M[0][0] * r->x1) + (float)(v6 * y1)) + v7) + v8;
  v16 = (float)((float)((float)(v13 * y1) + (float)(v5 * r->x1)) + v10) + v11;
  v26 = (float)((float)((float)(this->M[0][0] * x2) + (float)(v6 * y1)) + v7) + v8;
  v17 = v13 * y1;
  y2 = r->y2;
  pr->x1 = v15;
  pr->y1 = v16;
  pr->x2 = v15;
  pr->y2 = v16;
  v19 = (float)((float)(v17 + (float)(v5 * x2)) + v10) + v11;
  v20 = (float)((float)((float)(v14 * x2) + (float)(v6 * y2)) + v7) + v8;
  v21 = (float)((float)((float)(v12 * x1) + (float)(v6 * y2)) + v7) + v8;
  v22 = (float)((float)((float)(v13 * y2) + (float)(v5 * x2)) + v10) + v11;
  v23 = (float)((float)((float)(v13 * y2) + (float)(v5 * x1)) + v10) + v11;
  if ( v15 >= v26 )
    v24 = v26;
  else
    v24 = v15;
  pr->x1 = v24;
  if ( v16 >= v19 )
    v25 = v19;
  else
    v25 = v16;
  pr->y1 = v25;
  if ( v26 >= v15 )
    v15 = v26;
  pr->x2 = v15;
  if ( v19 >= v16 )
    v16 = v19;
  pr->y2 = v16;
  if ( v24 >= v20 )
    v24 = v20;
  pr->x1 = v24;
  if ( v25 >= v22 )
    v25 = v22;
  pr->y1 = v25;
  if ( v20 >= v15 )
    v15 = v20;
  pr->x2 = v15;
  if ( v22 >= v16 )
    v16 = v22;
  pr->y2 = v16;
  if ( v24 >= v21 )
    v24 = v21;
  pr->x1 = v24;
  if ( v25 >= v23 )
    v25 = v23;
  pr->y1 = v25;
  if ( v21 >= v15 )
    v15 = v21;
  pr->x2 = v15;
  if ( v23 >= v16 )
    pr->y2 = v23;
  else
    pr->y2 = v16;
}

// File Line: 838
// RVA: 0x7EAA80
Scaleform::Render::Matrix3x4<float> *__fastcall Scaleform::Render::Matrix3x4<float>::GetInverse(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Matrix3x4<float> *result)
{
  float v3; // xmm7_4
  float v4; // xmm1_4
  float v5; // xmm5_4
  float v6; // xmm12_4
  float v7; // xmm10_4
  float v8; // xmm8_4
  float v9; // xmm14_4
  float v10; // xmm4_4
  float v11; // xmm8_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  float v14; // xmm2_4
  float v15; // xmm15_4
  float v16; // xmm11_4
  float v17; // xmm3_4
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm0_4
  int v21; // xmm1_4
  int v22; // xmm0_4
  int v23; // xmm0_4
  float v24; // xmm10_4
  float v25; // xmm8_4
  float v26; // xmm1_4
  float v27; // xmm5_4
  float v28; // xmm7_4
  float v29; // xmm4_4
  float v30; // xmm9_4
  float v31; // xmm4_4
  float v32; // xmm2_4
  float v33; // xmm6_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm3_4
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
  int Dst[12]; // [rsp+30h] [rbp-D8h] BYREF
  float v71; // [rsp+110h] [rbp+8h]
  unsigned int v72; // [rsp+120h] [rbp+18h]
  float v73; // [rsp+128h] [rbp+20h]

  v3 = this->M[0][3];
  v4 = this->M[2][2] * 0.0;
  v5 = this->M[2][1] * 0.0;
  v6 = this->M[1][3];
  v7 = this->M[1][0];
  v8 = this->M[2][0] * 0.0;
  v9 = this->M[2][3];
  v10 = v8 - v4;
  v11 = v8 - v5;
  v12 = v5 - v4;
  v13 = this->M[2][2] - (float)(v9 * 0.0);
  v14 = this->M[2][1] - (float)(v9 * 0.0);
  v73 = this->M[2][0] - (float)(v9 * 0.0);
  v15 = (float)((float)(v13 * this->M[1][1]) - (float)(v14 * this->M[1][2])) + (float)(v12 * v6);
  v68 = v11;
  LODWORD(v16) = COERCE_UNSIGNED_INT((float)((float)(v13 * v7) - (float)(v73 * this->M[1][2])) + (float)(v10 * v6)) ^ _xmm[0];
  v69 = (float)((float)(v14 * v7) - (float)(v73 * this->M[1][1])) + (float)(v11 * v6);
  v17 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v12 * v7) - (float)(v10 * this->M[1][1])) + (float)(v11 * this->M[1][2])) ^ _xmm[0])
              * v3)
      + (float)((float)((float)(v16 * this->M[0][1]) + (float)(v15 * this->M[0][0])) + (float)(v69 * this->M[0][2]));
  if ( v17 == 0.0 )
  {
    memset(Dst, 0, sizeof(Dst));
    v18 = Dst[1];
    v19 = Dst[2];
    LODWORD(result->M[0][0]) = (_DWORD)FLOAT_1_0;
    LODWORD(result->M[0][1]) = v18;
    v20 = Dst[4];
    LODWORD(result->M[0][2]) = v19;
    v21 = Dst[9];
    LODWORD(result->M[0][3]) = LODWORD(v3) ^ _xmm[0];
    LODWORD(result->M[1][0]) = v20;
    v22 = Dst[6];
    LODWORD(result->M[1][1]) = (_DWORD)FLOAT_1_0;
    LODWORD(result->M[1][2]) = v22;
    v23 = Dst[8];
    LODWORD(result->M[1][3]) = LODWORD(v6) ^ _xmm[0];
    LODWORD(result->M[2][0]) = v23;
    LODWORD(result->M[2][1]) = v21;
    LODWORD(result->M[2][2]) = (_DWORD)FLOAT_1_0;
    LODWORD(result->M[2][3]) = LODWORD(v9) ^ _xmm[0];
  }
  else
  {
    v24 = 1.0 / v17;
    v25 = (float)((float)((float)(v13 * this->M[0][1]) - (float)(v14 * this->M[0][2])) + (float)(v12 * v3))
        * (float)(1.0 / v17);
    v26 = (float)((float)(v14 * this->M[0][0]) - (float)(v73 * this->M[0][1])) + (float)(v68 * v3);
    v71 = (float)((float)((float)(v13 * this->M[0][0]) - (float)(v73 * this->M[0][2])) + (float)(v10 * v3))
        * (float)(1.0 / v17);
    v27 = this->M[1][0] - (float)(v6 * 0.0);
    v28 = this->M[1][2] - (float)(v6 * 0.0);
    v72 = COERCE_UNSIGNED_INT(v26 * (float)(1.0 / v17)) ^ _xmm[0];
    v29 = this->M[1][1];
    v30 = v29 - (float)(v6 * 0.0);
    v31 = v29 * 0.0;
    v32 = this->M[1][2] * 0.0;
    v33 = (float)((float)(v28 * this->M[0][1]) - (float)(v30 * this->M[0][2]))
        + (float)((float)(v31 - v32) * this->M[0][3]);
    v34 = v27 * this->M[0][2];
    v35 = this->M[1][0] * 0.0;
    v36 = v35 - v31;
    v37 = (float)(v30 * this->M[0][0]) - (float)(v27 * this->M[0][1]);
    v38 = this->M[0][3];
    v39 = (float)(v9 * this->M[1][0]) - (float)(this->M[2][0] * v6);
    v40 = (float)((float)((float)(v28 * this->M[0][0]) - v34) + (float)((float)(v35 - v32) * v38)) * v24;
    v41 = (float)(v37 + (float)(v36 * v38)) * v24;
    v42 = this->M[2][1];
    v43 = this->M[2][3];
    v44 = v9 * this->M[1][2];
    result->M[0][2] = v33 * v24;
    LODWORD(result->M[0][1]) = LODWORD(v25) ^ _xmm[0];
    v45 = (float)(v43 * this->M[1][1]) - (float)(v42 * v6);
    v46 = this->M[2][2];
    result->M[1][1] = v71;
    v47 = v46 * v6;
    v48 = this->M[2][1];
    v49 = this->M[2][0];
    v50 = v44 - v47;
    v51 = v24 * v15;
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
    result->M[1][0] = v24 * v16;
    v63 = v49 * this->M[1][2];
    v64 = v49 * this->M[1][1];
    v65 = v53 - (float)(v39 * this->M[0][2]);
    v66 = v61 - (float)(v39 * this->M[0][1]);
    LODWORD(result->M[0][3]) = COERCE_UNSIGNED_INT((float)((float)(v58 * v38) + v62) * v24) ^ _xmm[0];
    result->M[2][0] = v24 * v69;
    LODWORD(result->M[2][1]) = v72;
    result->M[1][3] = (float)((float)((float)(v60 - v63) * v38) + v65) * v24;
    LODWORD(result->M[2][3]) = COERCE_UNSIGNED_INT((float)((float)((float)(v57 - v64) * v38) + v66) * v24) ^ _xmm[0];
  }
  return result;
}

