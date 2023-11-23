// File Line: 220
// RVA: 0x807DE0
void __fastcall Scaleform::Render::Matrix4x4<double>::Prepend(
        Scaleform::Render::Matrix4x4<double> *this,
        Scaleform::Render::Matrix4x4<double> *matrixA)
{
  Scaleform::Render::Matrix4x4<double> m1; // [rsp+20h] [rbp-88h] BYREF

  m1 = *this;
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(this, &m1, matrixA);
}

// File Line: 238
// RVA: 0x7B0570
void __fastcall Scaleform::Render::Matrix4x4<double>::Append(
        Scaleform::Render::Matrix4x4<double> *this,
        Scaleform::Render::Matrix4x4<double> *matrixA)
{
  Scaleform::Render::Matrix4x4<double> m2; // [rsp+20h] [rbp-88h] BYREF

  m2 = *this;
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(this, matrixA, &m2);
}

// File Line: 323
// RVA: 0x9B0D90
void __fastcall Scaleform::Render::Matrix4x4<float>::SetInverse(
        Scaleform::Render::Matrix4x4<float> *this,
        Scaleform::Render::Matrix4x4<float> *mIn)
{
  Scaleform::Render::Matrix4x4<float> result; // [rsp+20h] [rbp-48h] BYREF

  *this = *Scaleform::Render::Matrix4x4<float>::GetInverse(mIn, &result);
}

// File Line: 324
// RVA: 0x7F6910
void __fastcall Scaleform::Render::Matrix4x4<double>::Invert(Scaleform::Render::Matrix4x4<double> *this)
{
  Scaleform::Render::Matrix4x4<double> result; // [rsp+20h] [rbp-88h] BYREF

  *this = *Scaleform::Render::Matrix4x4<double>::GetInverse(this, &result);
}

// File Line: 582
// RVA: 0x722A30
void __fastcall Scaleform::Render::Matrix4x4<float>::Transpose(Scaleform::Render::Matrix4x4<float> *this)
{
  float v1; // xmm2_4
  float v2; // xmm1_4
  float v3; // xmm7_4
  float v4; // xmm6_4
  float v5; // xmm8_4
  float v6; // xmm11_4
  float v7; // xmm10_4
  float v8; // xmm9_4
  float v9; // xmm14_4
  float v10; // xmm13_4
  float v11; // xmm12_4
  float v12; // xmm15_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm4_4

  v1 = this->M[1][0];
  v2 = this->M[2][0];
  v3 = this->M[0][1];
  v4 = this->M[1][1];
  v5 = this->M[3][2];
  v6 = this->M[0][2];
  v7 = this->M[1][2];
  v8 = this->M[2][2];
  v9 = this->M[1][3];
  v10 = this->M[2][3];
  v11 = this->M[3][3];
  v12 = this->M[0][3];
  v13 = this->M[3][0];
  v14 = this->M[2][1];
  v15 = this->M[3][1];
  this->M[0][0] = this->M[0][0];
  this->M[0][1] = v1;
  this->M[0][2] = v2;
  this->M[0][3] = v13;
  this->M[1][0] = v3;
  this->M[1][1] = v4;
  this->M[1][2] = v14;
  this->M[1][3] = v15;
  this->M[2][0] = v6;
  this->M[2][1] = v7;
  this->M[2][2] = v8;
  this->M[2][3] = v5;
  this->M[3][0] = v12;
  this->M[3][1] = v9;
  this->M[3][2] = v10;
  this->M[3][3] = v11;
}

// File Line: 594
// RVA: 0x819A30
void __fastcall Scaleform::Render::Matrix4x4<double>::SetIdentity(Scaleform::Render::Matrix4x4<double> *this)
{
  memset(this, 0, sizeof(Scaleform::Render::Matrix4x4<double>));
  this->M[0][0] = 1.0;
  this->M[1][1] = 1.0;
  this->M[2][2] = 1.0;
  this->M[3][3] = 1.0;
}

// File Line: 606
// RVA: 0x801BA0
// attributes: thunk
void __fastcall Scaleform::Render::Matrix4x4<double>::MultiplyMatrix(
        Scaleform::Render::Matrix4x4<double> *this,
        Scaleform::Render::Matrix4x4<double> *m1,
        Scaleform::Render::Matrix4x4<double> *m2)
{
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(this, m1, m2);
}

// File Line: 681
// RVA: 0x801BB0
void __fastcall Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(
        Scaleform::Render::Matrix4x4<double> *this,
        Scaleform::Render::Matrix4x4<double> *m1,
        Scaleform::Render::Matrix4x4<double> *m2)
{
  this->M[0][0] = m1->M[0][0] * m2->M[0][0]
                + m1->M[0][1] * m2->M[1][0]
                + m1->M[0][2] * m2->M[2][0]
                + m1->M[0][3] * m2->M[3][0];
  this->M[0][1] = m2->M[0][1] * m1->M[0][0]
                + m2->M[1][1] * m1->M[0][1]
                + m2->M[2][1] * m1->M[0][2]
                + m1->M[0][3] * m2->M[3][1];
  this->M[0][2] = m2->M[0][2] * m1->M[0][0]
                + m2->M[1][2] * m1->M[0][1]
                + m1->M[0][2] * m2->M[2][2]
                + m1->M[0][3] * m2->M[3][2];
  this->M[0][3] = m1->M[0][0] * m2->M[0][3]
                + m1->M[0][1] * m2->M[1][3]
                + m1->M[0][2] * m2->M[2][3]
                + m2->M[3][3] * m1->M[0][3];
  this->M[1][0] = m1->M[1][0] * m2->M[0][0]
                + m1->M[1][1] * m2->M[1][0]
                + m1->M[1][2] * m2->M[2][0]
                + m1->M[1][3] * m2->M[3][0];
  this->M[1][1] = m2->M[1][1] * m1->M[1][1]
                + m2->M[0][1] * m1->M[1][0]
                + m2->M[2][1] * m1->M[1][2]
                + m1->M[1][3] * m2->M[3][1];
  this->M[1][2] = m2->M[1][2] * m1->M[1][1]
                + m2->M[0][2] * m1->M[1][0]
                + m1->M[1][2] * m2->M[2][2]
                + m1->M[1][3] * m2->M[3][2];
  this->M[1][3] = m1->M[1][1] * m2->M[1][3]
                + m1->M[1][0] * m2->M[0][3]
                + m1->M[1][2] * m2->M[2][3]
                + m1->M[1][3] * m2->M[3][3];
  this->M[2][0] = m1->M[2][0] * m2->M[0][0]
                + m1->M[2][1] * m2->M[1][0]
                + m1->M[2][2] * m2->M[2][0]
                + m1->M[2][3] * m2->M[3][0];
  this->M[2][1] = m2->M[1][1] * m1->M[2][1]
                + m2->M[0][1] * m1->M[2][0]
                + m2->M[2][1] * m1->M[2][2]
                + m1->M[2][3] * m2->M[3][1];
  this->M[2][2] = m2->M[1][2] * m1->M[2][1]
                + m2->M[0][2] * m1->M[2][0]
                + m1->M[2][2] * m2->M[2][2]
                + m1->M[2][3] * m2->M[3][2];
  this->M[2][3] = m1->M[2][1] * m2->M[1][3]
                + m1->M[2][0] * m2->M[0][3]
                + m1->M[2][2] * m2->M[2][3]
                + m1->M[2][3] * m2->M[3][3];
  this->M[3][0] = m1->M[3][0] * m2->M[0][0]
                + m1->M[3][1] * m2->M[1][0]
                + m1->M[3][2] * m2->M[2][0]
                + m1->M[3][3] * m2->M[3][0];
  this->M[3][1] = m2->M[1][1] * m1->M[3][1]
                + m2->M[0][1] * m1->M[3][0]
                + m2->M[2][1] * m1->M[3][2]
                + m1->M[3][3] * m2->M[3][1];
  this->M[3][2] = m2->M[1][2] * m1->M[3][1]
                + m2->M[0][2] * m1->M[3][0]
                + m1->M[3][2] * m2->M[2][2]
                + m1->M[3][3] * m2->M[3][2];
  this->M[3][3] = m1->M[3][1] * m2->M[1][3]
                + m1->M[3][0] * m2->M[0][3]
                + m1->M[3][2] * m2->M[2][3]
                + m2->M[3][3] * m1->M[3][3];
}

// File Line: 909
// RVA: 0x816E90
Scaleform::Render::Matrix4x4<double> *__fastcall Scaleform::Render::Matrix4x4<double>::Rotation(
        Scaleform::Render::Matrix4x4<double> *result,
        long double angle,
        Scaleform::Render::Point3<double> *axis)
{
  float v5; // xmm6_4
  double v6; // xmm11_8
  float v7; // xmm0_4
  double z; // xmm9_8
  double y; // xmm8_8
  Scaleform::Render::Matrix4x4<double> *v10; // rax
  double v11; // xmm1_8
  double x; // xmm0_8
  long double v13; // xmm5_8
  double v14; // xmm4_8
  double v15; // xmm6_8
  double v16; // xmm7_8

  memset(result, 0, sizeof(Scaleform::Render::Matrix4x4<double>));
  v5 = angle;
  result->M[3][3] = 1.0;
  v6 = cosf(v5);
  v7 = sinf(v5);
  z = axis->z;
  y = axis->y;
  v10 = result;
  v11 = v7;
  x = axis->x;
  v13 = axis->x * v11;
  v15 = z * y * (1.0 - v6);
  result->M[0][0] = axis->x * axis->x * (1.0 - v6) + v6;
  v14 = x * y * (1.0 - v6);
  v16 = z * x * (1.0 - v6);
  result->M[0][1] = v14 - z * v11;
  result->M[1][1] = y * y * (1.0 - v6) + v6;
  result->M[2][0] = v16 - y * v11;
  result->M[2][2] = z * z * (1.0 - v6) + v6;
  result->M[2][1] = v13 + v15;
  result->M[0][2] = y * v11 + v16;
  result->M[1][0] = z * v11 + v14;
  result->M[1][2] = v15 - v13;
  return v10;
}

// File Line: 941
// RVA: 0x816D30
Scaleform::Render::Matrix4x4<double> *__fastcall Scaleform::Render::Matrix4x4<double>::Rotation(
        Scaleform::Render::Matrix4x4<double> *result,
        long double angle,
        Scaleform::Render::Point3<double> *axis,
        Scaleform::Render::Point3<double> *pivot)
{
  long double x; // xmm7_8
  long double y; // xmm9_8
  long double z; // xmm10_8
  Scaleform::Render::Matrix4x4<double> *v10; // rax
  Scaleform::Render::Matrix4x4<double> Dst; // [rsp+20h] [rbp-1D8h] BYREF
  Scaleform::Render::Matrix4x4<double> m2; // [rsp+A0h] [rbp-158h] BYREF
  Scaleform::Render::Matrix4x4<double> resulta; // [rsp+120h] [rbp-D8h] BYREF

  memset(&Dst, 0, sizeof(Dst));
  x = pivot->x;
  y = pivot->y;
  z = pivot->z;
  Dst.M[0][0] = DOUBLE_1_0;
  Dst.M[1][1] = DOUBLE_1_0;
  Dst.M[2][2] = DOUBLE_1_0;
  Dst.M[3][3] = DOUBLE_1_0;
  Dst.M[0][3] = x;
  Dst.M[1][3] = y;
  Dst.M[2][3] = z;
  v10 = Scaleform::Render::Matrix4x4<double>::Rotation(&resulta, angle, axis);
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(&m2, v10, &Dst);
  memset(&Dst, 0, sizeof(Dst));
  Dst.M[0][0] = DOUBLE_1_0;
  Dst.M[1][1] = DOUBLE_1_0;
  Dst.M[2][2] = DOUBLE_1_0;
  Dst.M[3][3] = DOUBLE_1_0;
  *(_QWORD *)&Dst.M[0][3] = *(_QWORD *)&x ^ _xmm[0];
  *(_QWORD *)&Dst.M[1][3] = *(_QWORD *)&y ^ _xmm[0];
  *(_QWORD *)&Dst.M[2][3] = *(_QWORD *)&z ^ _xmm[0];
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(result, &Dst, &m2);
  return result;
}

// File Line: 1003
// RVA: 0x829940
void __fastcall Scaleform::Render::Matrix4x4<double>::ViewRH(
        Scaleform::Render::Matrix4x4<double> *this,
        Scaleform::Render::Point3<double> *eyePt,
        Scaleform::Render::Point3<double> *lookAtPt,
        Scaleform::Render::Point3<double> *upVec)
{
  long double v4; // xmm5_8
  long double v5; // xmm4_8
  long double v6; // xmm3_8
  double v7; // xmm0_8
  Scaleform::Render::Point3<double> zAxis; // [rsp+20h] [rbp-28h] BYREF

  v4 = eyePt->x - lookAtPt->x;
  v5 = eyePt->y - lookAtPt->y;
  v6 = eyePt->z - lookAtPt->z;
  v7 = sqrt(v4 * v4 + v5 * v5 + v6 * v6);
  zAxis.x = v4 * (1.0 / v7);
  zAxis.y = v5 * (1.0 / v7);
  zAxis.z = v6 * (1.0 / v7);
  Scaleform::Render::Matrix4x4<double>::View(this, eyePt, &zAxis, upVec);
}

// File Line: 1022
// RVA: 0x829860
void __fastcall Scaleform::Render::Matrix4x4<double>::View(
        Scaleform::Render::Matrix4x4<double> *this,
        Scaleform::Render::Point3<double> *eyePt,
        Scaleform::Render::Point3<double> *zAxis,
        Scaleform::Render::Point3<double> *upVec)
{
  __int128 v5; // [rsp+30h] [rbp-88h]
  __int128 v6; // [rsp+40h] [rbp-78h]
  __int128 v7; // [rsp+50h] [rbp-68h]
  __int128 v8; // [rsp+60h] [rbp-58h]
  __int128 v9; // [rsp+70h] [rbp-48h]
  __int128 v10; // [rsp+80h] [rbp-38h]

  if ( this )
  {
    *(_OWORD *)&this->M[0][0] = v5;
    *(_OWORD *)&this->M[0][2] = v6;
    *(_OWORD *)&this->M[1][0] = v7;
    *(_OWORD *)&this->M[1][2] = v8;
    *(_OWORD *)&this->M[2][0] = v9;
    *(_OWORD *)&this->M[2][2] = v10;
  }
  Scaleform::Render::Matrix3x4<double>::View((Scaleform::Render::Matrix3x4<double> *)this, eyePt, zAxis, upVec);
  this->M[3][0] = 0.0;
  this->M[3][1] = 0.0;
  this->M[3][2] = 0.0;
  this->M[3][3] = 1.0;
}

// File Line: 1130
// RVA: 0x8EFC80
void __fastcall Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterRH(
        Scaleform::Render::Matrix4x4<float> *this,
        float focalLength,
        float viewMinX,
        float viewMaxX,
        float viewMinY,
        float viewMaxY,
        float fNearZ,
        float fFarZ)
{
  float v9; // xmm0_4
  float v10; // xmm12_4
  float v11; // xmm2_4
  float v12; // xmm3_4

  memset(this, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  this->M[3][2] = -1.0;
  v9 = viewMaxX - viewMinX;
  v10 = viewMinX + viewMaxX;
  v11 = 1.0 / (float)(viewMaxY - viewMinY);
  v12 = 1.0 / (float)(fNearZ - fFarZ);
  this->M[0][2] = v10 * (float)(1.0 / v9);
  this->M[0][0] = (float)(1.0 / v9) * (float)(focalLength * 2.0);
  this->M[2][3] = (float)(fNearZ * fFarZ) * v12;
  this->M[1][2] = (float)(viewMinY + viewMaxY) * v11;
  this->M[1][1] = v11 * (float)(focalLength * 2.0);
  this->M[2][2] = v12 * fFarZ;
}

// File Line: 1146
// RVA: 0x8EFB90
void __fastcall Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterLH(
        Scaleform::Render::Matrix4x4<float> *this,
        float focalLength,
        float viewMinX,
        float viewMaxX,
        float viewMinY,
        float viewMaxY,
        float fNearZ,
        float fFarZ)
{
  memset(this, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  this->M[3][2] = 1.0;
  this->M[0][0] = (float)(focalLength * 2.0) / (float)(viewMaxX - viewMinX);
  this->M[1][1] = (float)(focalLength * 2.0) / (float)(viewMaxY - viewMinY);
  this->M[2][2] = fFarZ / (float)(fFarZ - fNearZ);
  this->M[2][3] = (float)(fNearZ * fFarZ) / (float)(fNearZ - fFarZ);
  this->M[0][2] = (float)(viewMinX + viewMaxX) / (float)(viewMinX - viewMaxX);
  this->M[1][2] = (float)(viewMinY + viewMaxY) / (float)(viewMinY - viewMaxY);
}

// File Line: 1189
// RVA: 0x8EF140
void __fastcall Scaleform::Render::Matrix4x4<float>::OrthoOffCenterRH(
        Scaleform::Render::Matrix4x4<float> *this,
        float viewMinX,
        float viewMaxX,
        float viewMinY,
        float viewMaxY,
        float fNearZ,
        float fFarZ)
{
  memset(this, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  this->M[3][3] = 1.0;
  this->M[0][0] = 2.0 / (float)(viewMaxX - viewMinX);
  this->M[1][1] = 2.0 / (float)(viewMaxY - viewMinY);
  this->M[2][2] = 1.0 / (float)(fNearZ - fFarZ);
  this->M[0][3] = (float)(viewMinX + viewMaxX) / (float)(viewMinX - viewMaxX);
  this->M[2][3] = (float)(1.0 / (float)(fNearZ - fFarZ)) * fNearZ;
  this->M[1][3] = (float)(viewMinY + viewMaxY) / (float)(viewMinY - viewMaxY);
}

// File Line: 1205
// RVA: 0x8EF050
void __fastcall Scaleform::Render::Matrix4x4<float>::OrthoOffCenterLH(
        Scaleform::Render::Matrix4x4<float> *this,
        float viewMinX,
        float viewMaxX,
        float viewMinY,
        float viewMaxY,
        float fNearZ,
        float fFarZ)
{
  memset(this, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  this->M[3][3] = 1.0;
  this->M[0][0] = 2.0 / (float)(viewMaxX - viewMinX);
  this->M[1][1] = 2.0 / (float)(viewMaxY - viewMinY);
  this->M[2][2] = 1.0 / (float)(fFarZ - fNearZ);
  this->M[2][3] = fNearZ / (float)(fNearZ - fFarZ);
  this->M[0][3] = (float)(viewMinX + viewMaxX) / (float)(viewMinX - viewMaxX);
  this->M[1][3] = (float)(viewMinY + viewMaxY) / (float)(viewMinY - viewMaxY);
}

// File Line: 1300
// RVA: 0x7E89F0
long double __fastcall Scaleform::Render::Matrix4x4<double>::GetDeterminant(Scaleform::Render::Matrix4x4<double> *this)
{
  double v1; // xmm2_8
  double v2; // xmm3_8
  double v3; // xmm7_8
  double v4; // xmm6_8
  double v5; // xmm13_8
  long double v6; // xmm12_8
  long double v7; // xmm14_8
  long double v8; // xmm8_8
  double v9; // xmm0_8
  long double v10; // xmm13_8
  long double v11; // xmm10_8

  v1 = this->M[2][3];
  v2 = this->M[3][3];
  v3 = this->M[2][2];
  v4 = this->M[3][2];
  v5 = this->M[2][0];
  v6 = this->M[2][1] * v2 - this->M[3][1] * v1;
  v7 = this->M[2][1] * v4 - this->M[3][1] * v3;
  v8 = v5 * v2 - this->M[3][0] * v1;
  v9 = this->M[3][0];
  v10 = v5 * this->M[3][1] - v9 * this->M[2][1];
  v11 = this->M[2][0] * v4 - v9 * v3;
  return (this->M[1][1] * (v3 * v2 - v1 * v4) - this->M[1][2] * v6 + this->M[1][3] * v7) * this->M[0][0]
       - (this->M[1][0] * (v3 * v2 - v1 * v4) - v8 * this->M[1][2] + v11 * this->M[1][3]) * this->M[0][1]
       + (this->M[1][0] * v6 - v8 * this->M[1][1] + v10 * this->M[1][3]) * this->M[0][2]
       - (this->M[1][0] * v7 - v11 * this->M[1][1] + v10 * this->M[1][2]) * this->M[0][3];
}

// File Line: 1311
// RVA: 0x987610
Scaleform::Render::Matrix4x4<float> *__fastcall Scaleform::Render::Matrix4x4<float>::GetInverse(
        Scaleform::Render::Matrix4x4<float> *this,
        Scaleform::Render::Matrix4x4<float> *result)
{
  float v2; // xmm5_4
  float v3; // xmm3_4
  float v4; // xmm1_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm13_4
  float v9; // xmm12_4
  float v10; // xmm15_4
  float v11; // xmm10_4
  float v12; // xmm9_4
  float v13; // xmm5_4
  float v14; // xmm8_4
  float v15; // xmm13_4
  float v16; // xmm14_4
  float v17; // xmm2_4
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm0_4
  int v21; // xmm1_4
  int v22; // xmm0_4
  int v23; // xmm0_4
  int v24; // xmm0_4
  int v25; // xmm1_4
  int v26; // xmm0_4
  float v27; // xmm12_4
  float v28; // xmm11_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm9_4
  float v33; // xmm10_4
  float v34; // xmm8_4
  unsigned int v35; // xmm11_4
  float v36; // xmm4_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float v39; // xmm10_4
  float v40; // xmm9_4
  float v41; // xmm5_4
  float v42; // xmm6_4
  float v43; // xmm10_4
  float v44; // xmm9_4
  float v45; // xmm11_4
  float v46; // xmm5_4
  float v47; // xmm9_4
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm10_4
  float v52; // xmm4_4
  float v53; // xmm9_4
  float v54; // xmm8_4
  float v55; // xmm7_4
  float v56; // xmm1_4
  float v57; // xmm7_4
  float v58; // xmm4_4
  float v59; // xmm5_4
  float v60; // xmm3_4
  float v61; // xmm15_4
  float v62; // xmm2_4
  float v63; // xmm2_4
  float v64; // xmm2_4
  float v65; // xmm0_4
  float v66; // xmm4_4
  float v67; // xmm1_4
  float v68; // xmm7_4
  float v69; // xmm15_4
  float v70; // xmm0_4
  float v71; // xmm8_4
  float v73; // [rsp+20h] [rbp-108h]
  unsigned int v74; // [rsp+24h] [rbp-104h]
  float v75; // [rsp+28h] [rbp-100h]
  float v76; // [rsp+2Ch] [rbp-FCh]
  float v77; // [rsp+30h] [rbp-F8h]
  int Dst[16]; // [rsp+40h] [rbp-E8h] BYREF
  float v79; // [rsp+130h] [rbp+8h]
  float v80; // [rsp+130h] [rbp+8h]
  float v81; // [rsp+140h] [rbp+18h]
  unsigned int v82; // [rsp+140h] [rbp+18h]
  float v83; // [rsp+148h] [rbp+20h]

  v2 = this->M[3][0];
  v3 = this->M[2][0];
  v4 = this->M[3][3];
  v6 = this->M[2][1];
  v7 = this->M[1][3];
  v8 = this->M[2][2];
  v9 = this->M[0][3];
  v77 = this->M[0][0];
  v10 = this->M[2][3];
  v83 = this->M[1][2];
  v11 = (float)(this->M[3][1] * v3) - (float)(v2 * v6);
  v81 = (float)(this->M[3][2] * v3) - (float)(v2 * v8);
  v79 = (float)(v4 * v3) - (float)(v2 * v10);
  v12 = (float)(this->M[3][2] * v6) - (float)(this->M[3][1] * v8);
  v13 = (float)(v4 * v6) - (float)(this->M[3][1] * v10);
  v14 = (float)(v4 * v8) - (float)(this->M[3][2] * v10);
  v75 = (float)((float)(v14 * this->M[1][1]) - (float)(v13 * v83)) + (float)(v12 * v7);
  LODWORD(v15) = COERCE_UNSIGNED_INT((float)((float)(v14 * this->M[1][0]) - (float)(v79 * v83)) + (float)(v81 * v7)) ^ _xmm[0];
  v73 = (float)((float)(v13 * this->M[1][0]) - (float)(v79 * this->M[1][1])) + (float)(v11 * v7);
  LODWORD(v16) = COERCE_UNSIGNED_INT((float)((float)(v12 * this->M[1][0]) - (float)(v81 * this->M[1][1])) + (float)(v11 * v83)) ^ _xmm[0];
  v17 = (float)((float)((float)(v15 * this->M[0][1]) + (float)(v75 * this->M[0][0])) + (float)(v73 * this->M[0][2]))
      + (float)(v16 * v9);
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
    LODWORD(result->M[0][3]) = LODWORD(v9) ^ _xmm[0];
    LODWORD(result->M[1][0]) = v20;
    v22 = Dst[6];
    LODWORD(result->M[1][1]) = (_DWORD)FLOAT_1_0;
    LODWORD(result->M[1][2]) = v22;
    v23 = Dst[8];
    LODWORD(result->M[1][3]) = LODWORD(v7) ^ _xmm[0];
    LODWORD(result->M[2][0]) = v23;
    v24 = Dst[12];
    LODWORD(result->M[2][1]) = v21;
    v25 = Dst[13];
    LODWORD(result->M[2][2]) = (_DWORD)FLOAT_1_0;
    LODWORD(result->M[2][3]) = LODWORD(v10) ^ _xmm[0];
    LODWORD(result->M[3][0]) = v24;
    v26 = Dst[14];
    LODWORD(result->M[3][1]) = v25;
    LODWORD(result->M[3][2]) = v26;
    LODWORD(result->M[3][3]) = (_DWORD)FLOAT_1_0;
  }
  else
  {
    v27 = 1.0 / v17;
    v28 = (float)((float)(v14 * this->M[0][1]) - (float)(v13 * this->M[0][2])) + (float)(v12 * this->M[0][3]);
    v29 = (float)(v13 * this->M[0][0]) - (float)(v79 * this->M[0][1]);
    v30 = v11;
    v31 = this->M[1][0];
    v32 = (float)((float)(v12 * this->M[0][0]) - (float)(v81 * this->M[0][1])) + (float)(v11 * this->M[0][2]);
    v33 = this->M[3][0];
    v80 = (float)((float)((float)(v14 * this->M[0][0]) - (float)(v79 * this->M[0][2])) + (float)(v81 * this->M[0][3]))
        * (float)(1.0 / v17);
    v34 = this->M[0][3];
    v76 = v32 * (float)(1.0 / v17);
    v35 = COERCE_UNSIGNED_INT(v28 * (float)(1.0 / v17)) ^ _xmm[0];
    v36 = (float)(this->M[3][1] * v31) - (float)(v33 * this->M[1][1]);
    v74 = COERCE_UNSIGNED_INT((float)(v29 + (float)(v30 * v34)) * (float)(1.0 / v17)) ^ _xmm[0];
    v37 = (float)(this->M[3][2] * v31) - (float)(v33 * this->M[1][2]);
    v38 = (float)(this->M[3][3] * v31) - (float)(v33 * v7);
    v39 = (float)(this->M[3][2] * this->M[1][1]) - (float)(this->M[3][1] * this->M[1][2]);
    v40 = (float)(this->M[3][3] * this->M[1][1]) - (float)(this->M[3][1] * v7);
    v41 = (float)(this->M[3][3] * v83) - (float)(this->M[3][2] * v7);
    v42 = (float)((float)((float)(v41 * this->M[0][1]) - (float)(v40 * this->M[0][2])) + (float)(v39 * v34)) * v27;
    v43 = v39 * this->M[0][0];
    v44 = v40 * this->M[0][0];
    LODWORD(result->M[0][1]) = v35;
    v45 = this->M[0][3];
    result->M[0][2] = v42;
    v46 = (float)(v41 * v77) - (float)(v38 * this->M[0][2]);
    v47 = v44 - (float)(v38 * this->M[0][1]);
    v48 = this->M[1][1];
    v49 = v36 * v34;
    v50 = this->M[1][0];
    v51 = (float)(v43 - (float)(v37 * this->M[0][1])) + (float)(v36 * this->M[0][2]);
    v52 = v10 * v50;
    v82 = COERCE_UNSIGNED_INT((float)(v46 + (float)(v37 * v34)) * v27) ^ _xmm[0];
    v53 = (float)(v47 + v49) * v27;
    v54 = (float)(this->M[2][1] * v50) - (float)(this->M[2][0] * v48);
    v55 = this->M[2][2] * v50;
    v56 = this->M[1][3];
    v57 = v55 - (float)(this->M[2][0] * this->M[1][2]);
    v58 = v52 - (float)(this->M[2][0] * v56);
    v59 = (float)(this->M[2][2] * v48) - (float)(this->M[2][1] * this->M[1][2]);
    v60 = (float)(v10 * v48) - (float)(this->M[2][1] * v56);
    v61 = (float)(v10 * this->M[1][2]) - (float)(this->M[2][2] * v56);
    v62 = v61 * this->M[0][1];
    result->M[0][0] = v27 * v75;
    v63 = (float)((float)(v62 - (float)(v60 * this->M[0][2])) + (float)(v59 * v45)) * v27;
    result->M[1][1] = v80;
    LODWORD(result->M[0][3]) = LODWORD(v63) ^ _xmm[0];
    v64 = this->M[0][0];
    result->M[1][0] = v27 * v15;
    LODWORD(result->M[1][2]) = v82;
    v65 = v58;
    v66 = v58 * this->M[0][1];
    v67 = v57;
    result->M[2][2] = v53;
    LODWORD(result->M[3][2]) = COERCE_UNSIGNED_INT(v51 * v27) ^ _xmm[0];
    v68 = v57 * this->M[0][1];
    v69 = (float)((float)(v61 * v64) - (float)(v65 * this->M[0][2])) + (float)(v67 * v45);
    result->M[2][0] = v27 * v73;
    LODWORD(result->M[2][1]) = v74;
    v70 = v54;
    v71 = v54 * this->M[0][2];
    result->M[1][3] = v69 * v27;
    result->M[3][0] = v27 * v16;
    result->M[3][1] = v76;
    result->M[3][3] = (float)((float)((float)(v59 * v64) - v68) + v71) * v27;
    LODWORD(result->M[2][3]) = COERCE_UNSIGNED_INT((float)((float)((float)(v60 * v64) - v66) + (float)(v70 * v45)) * v27) ^ _xmm[0];
  }
  return result;
}

