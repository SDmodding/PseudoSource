// File Line: 220
// RVA: 0x807DE0
void __fastcall Scaleform::Render::Matrix4x4<double>::Prepend(Scaleform::Render::Matrix4x4<double> *this, Scaleform::Render::Matrix4x4<double> *matrixA)
{
  Scaleform::Render::Matrix4x4<double> m1; // [rsp+20h] [rbp-88h]

  *(_OWORD *)&m1.M[0][0] = *(_OWORD *)&this->M[0][0];
  *(_OWORD *)&m1.M[0][2] = *(_OWORD *)&this->M[0][2];
  *(_OWORD *)&m1.M[1][0] = *(_OWORD *)&this->M[1][0];
  *(_OWORD *)&m1.M[1][2] = *(_OWORD *)&this->M[1][2];
  *(_OWORD *)&m1.M[2][0] = *(_OWORD *)&this->M[2][0];
  *(_OWORD *)&m1.M[2][2] = *(_OWORD *)&this->M[2][2];
  *(_OWORD *)&m1.M[3][0] = *(_OWORD *)&this->M[3][0];
  *(_OWORD *)&m1.M[3][2] = *(_OWORD *)&this->M[3][2];
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(this, &m1, matrixA);
}

// File Line: 238
// RVA: 0x7B0570
void __fastcall Scaleform::Render::Matrix4x4<double>::Append(Scaleform::Render::Matrix4x4<double> *this, Scaleform::Render::Matrix4x4<double> *matrixA)
{
  Scaleform::Render::Matrix4x4<double> m2; // [rsp+20h] [rbp-88h]

  *(_OWORD *)&m2.M[0][0] = *(_OWORD *)&this->M[0][0];
  *(_OWORD *)&m2.M[0][2] = *(_OWORD *)&this->M[0][2];
  *(_OWORD *)&m2.M[1][0] = *(_OWORD *)&this->M[1][0];
  *(_OWORD *)&m2.M[1][2] = *(_OWORD *)&this->M[1][2];
  *(_OWORD *)&m2.M[2][0] = *(_OWORD *)&this->M[2][0];
  *(_OWORD *)&m2.M[2][2] = *(_OWORD *)&this->M[2][2];
  *(_OWORD *)&m2.M[3][0] = *(_OWORD *)&this->M[3][0];
  *(_OWORD *)&m2.M[3][2] = *(_OWORD *)&this->M[3][2];
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(this, matrixA, &m2);
}

// File Line: 323
// RVA: 0x9B0D90
void __fastcall Scaleform::Render::Matrix4x4<float>::SetInverse(Scaleform::Render::Matrix4x4<float> *this, Scaleform::Render::Matrix4x4<float> *mIn)
{
  Scaleform::Render::Matrix4x4<float> *v2; // rbx
  Scaleform::Render::Matrix4x4<float> *v3; // rax
  Scaleform::Render::Matrix4x4<float> result; // [rsp+20h] [rbp-48h]

  v2 = this;
  v3 = Scaleform::Render::Matrix4x4<float>::GetInverse(mIn, &result);
  v2->M[0][0] = v3->M[0][0];
  v2->M[0][1] = v3->M[0][1];
  v2->M[0][2] = v3->M[0][2];
  v2->M[0][3] = v3->M[0][3];
  v2->M[1][0] = v3->M[1][0];
  v2->M[1][1] = v3->M[1][1];
  v2->M[1][2] = v3->M[1][2];
  v2->M[1][3] = v3->M[1][3];
  v2->M[2][0] = v3->M[2][0];
  v2->M[2][1] = v3->M[2][1];
  v2->M[2][2] = v3->M[2][2];
  v2->M[2][3] = v3->M[2][3];
  v2->M[3][0] = v3->M[3][0];
  v2->M[3][1] = v3->M[3][1];
  v2->M[3][2] = v3->M[3][2];
  v2->M[3][3] = v3->M[3][3];
}

// File Line: 324
// RVA: 0x7F6910
void __fastcall Scaleform::Render::Matrix4x4<double>::Invert(Scaleform::Render::Matrix4x4<double> *this)
{
  Scaleform::Render::Matrix4x4<double> *v1; // rbx
  Scaleform::Render::Matrix4x4<double> *v2; // rax
  Scaleform::Render::Matrix4x4<double> result; // [rsp+20h] [rbp-88h]

  v1 = this;
  v2 = Scaleform::Render::Matrix4x4<double>::GetInverse(this, &result);
  v1->M[0][0] = v2->M[0][0];
  v1->M[0][1] = v2->M[0][1];
  v1->M[0][2] = v2->M[0][2];
  v1->M[0][3] = v2->M[0][3];
  v1->M[1][0] = v2->M[1][0];
  v1->M[1][1] = v2->M[1][1];
  v1->M[1][2] = v2->M[1][2];
  v1->M[1][3] = v2->M[1][3];
  v1->M[2][0] = v2->M[2][0];
  v1->M[2][1] = v2->M[2][1];
  v1->M[2][2] = v2->M[2][2];
  v1->M[2][3] = v2->M[2][3];
  v1->M[3][0] = v2->M[3][0];
  v1->M[3][1] = v2->M[3][1];
  v1->M[3][2] = v2->M[3][2];
  v1->M[3][3] = v2->M[3][3];
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
  Scaleform::Render::Matrix4x4<double> *v1; // rbx

  v1 = this;
  memset(this, 0, 0x80ui64);
  v1->M[0][0] = 1.0;
  v1->M[1][1] = 1.0;
  v1->M[2][2] = 1.0;
  v1->M[3][3] = 1.0;
}

// File Line: 606
// RVA: 0x801BA0
void __fastcall Scaleform::Render::Matrix4x4<double>::MultiplyMatrix(Scaleform::Render::Matrix4x4<double> *this, Scaleform::Render::Matrix4x4<double> *m1, Scaleform::Render::Matrix4x4<double> *m2)
{
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(this, m1, m2);
}

// File Line: 681
// RVA: 0x801BB0
void __fastcall Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(Scaleform::Render::Matrix4x4<double> *this, Scaleform::Render::Matrix4x4<double> *m1, Scaleform::Render::Matrix4x4<double> *m2)
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
Scaleform::Render::Matrix4x4<double> *__fastcall Scaleform::Render::Matrix4x4<double>::Rotation(Scaleform::Render::Matrix4x4<double> *result, long double angle, Scaleform::Render::Point3<double> *axis)
{
  Scaleform::Render::Point3<double> *v3; // rbx
  Scaleform::Render::Matrix4x4<double> *v4; // rdi
  float v5; // xmm6_4
  double v6; // xmm11_8
  float v7; // xmm0_4
  double v8; // xmm9_8
  double v9; // xmm8_8
  Scaleform::Render::Matrix4x4<double> *v10; // rax
  double v11; // xmm1_8
  double v12; // xmm0_8
  long double v13; // xmm5_8
  long double v14; // xmm7_8
  double v15; // xmm6_8
  double v16; // xmm0_8
  long double v17; // xmm7_8

  v3 = axis;
  v4 = result;
  memset(result, 0, 0x80ui64);
  v5 = angle;
  v4->M[3][3] = 1.0;
  v6 = cosf(v5);
  v7 = sinf(v5);
  v8 = v3->z;
  v9 = v3->y;
  v10 = v4;
  v11 = v7;
  v12 = v3->x;
  v13 = v3->x * v11;
  v14 = v8 * v3->x;
  v15 = v8 * v9 * (1.0 - v6);
  v4->M[0][0] = v12 * v12 * (1.0 - v6) + v6;
  v16 = v12 * v9 * (1.0 - v6);
  v17 = v14 * (1.0 - v6);
  v4->M[0][1] = v16 - v8 * v11;
  v4->M[1][1] = v9 * v9 * (1.0 - v6) + v6;
  v4->M[2][0] = v17 - v9 * v11;
  v4->M[2][2] = v8 * v8 * (1.0 - v6) + v6;
  v4->M[2][1] = v13 + v15;
  v4->M[0][2] = v9 * v11 + v17;
  v4->M[1][0] = v8 * v11 + v16;
  v4->M[1][2] = v15 - v13;
  return v10;
}

// File Line: 941
// RVA: 0x816D30
Scaleform::Render::Matrix4x4<double> *__fastcall Scaleform::Render::Matrix4x4<double>::Rotation(Scaleform::Render::Matrix4x4<double> *result, long double angle, Scaleform::Render::Point3<double> *axis, Scaleform::Render::Point3<double> *pivot)
{
  Scaleform::Render::Matrix4x4<double> *v4; // rsi
  Scaleform::Render::Point3<double> *v5; // rdi
  Scaleform::Render::Point3<double> *v6; // rbx
  __int64 v7; // xmm7_8
  __int64 v8; // xmm9_8
  __int64 v9; // xmm10_8
  Scaleform::Render::Matrix4x4<double> *v10; // rax
  long double Dst; // [rsp+20h] [rbp-1D8h]
  __int64 v13; // [rsp+38h] [rbp-1C0h]
  long double v14; // [rsp+48h] [rbp-1B0h]
  __int64 v15; // [rsp+58h] [rbp-1A0h]
  long double v16; // [rsp+70h] [rbp-188h]
  __int64 v17; // [rsp+78h] [rbp-180h]
  long double v18; // [rsp+98h] [rbp-160h]
  Scaleform::Render::Matrix4x4<double> m2; // [rsp+A0h] [rbp-158h]
  Scaleform::Render::Matrix4x4<double> resulta; // [rsp+120h] [rbp-D8h]

  v4 = result;
  v5 = axis;
  v6 = pivot;
  memset(&Dst, 0, 0x80ui64);
  v7 = *(_QWORD *)&v6->x;
  v8 = *(_QWORD *)&v6->y;
  v9 = *(_QWORD *)&v6->z;
  Dst = DOUBLE_1_0;
  v14 = DOUBLE_1_0;
  v16 = DOUBLE_1_0;
  v18 = DOUBLE_1_0;
  v13 = v7;
  v15 = v8;
  v17 = v9;
  v10 = Scaleform::Render::Matrix4x4<double>::Rotation(&resulta, angle, v5);
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(&m2, v10, (Scaleform::Render::Matrix4x4<double> *)&Dst);
  memset(&Dst, 0, 0x80ui64);
  Dst = DOUBLE_1_0;
  v14 = DOUBLE_1_0;
  v16 = DOUBLE_1_0;
  v18 = DOUBLE_1_0;
  v13 = v7 ^ _xmm[0];
  v15 = v8 ^ _xmm[0];
  v17 = v9 ^ _xmm[0];
  Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(v4, (Scaleform::Render::Matrix4x4<double> *)&Dst, &m2);
  return v4;
}

// File Line: 1003
// RVA: 0x829940
void __fastcall Scaleform::Render::Matrix4x4<double>::ViewRH(Scaleform::Render::Matrix4x4<double> *this, Scaleform::Render::Point3<double> *eyePt, Scaleform::Render::Point3<double> *lookAtPt, Scaleform::Render::Point3<double> *upVec)
{
  long double v4; // xmm5_8
  long double v5; // xmm4_8
  long double v6; // xmm3_8
  double v7; // xmm0_8
  Scaleform::Render::Point3<double> zAxis; // [rsp+20h] [rbp-28h]

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
void __fastcall Scaleform::Render::Matrix4x4<double>::View(Scaleform::Render::Matrix4x4<double> *this, Scaleform::Render::Point3<double> *eyePt, Scaleform::Render::Point3<double> *zAxis, Scaleform::Render::Point3<double> *upVec)
{
  Scaleform::Render::Matrix4x4<double> *v4; // rbx
  __int128 v5; // [rsp+30h] [rbp-88h]
  __int128 v6; // [rsp+40h] [rbp-78h]
  __int128 v7; // [rsp+50h] [rbp-68h]
  __int128 v8; // [rsp+60h] [rbp-58h]
  __int128 v9; // [rsp+70h] [rbp-48h]
  __int128 v10; // [rsp+80h] [rbp-38h]

  v4 = this;
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
  v4->M[3][0] = 0.0;
  v4->M[3][1] = 0.0;
  v4->M[3][2] = 0.0;
  v4->M[3][3] = 1.0;
}

// File Line: 1130
// RVA: 0x8EFC80
void __fastcall Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterRH(Scaleform::Render::Matrix4x4<float> *this, float focalLength, float viewMinX, float viewMaxX, float viewMinY, float viewMaxY, float fNearZ, float fFarZ)
{
  Scaleform::Render::Matrix4x4<float> *v8; // rbx
  float v9; // xmm0_4
  float v10; // xmm12_4
  float v11; // xmm2_4
  float v12; // xmm3_4

  v8 = this;
  memset(this, 0, 0x40ui64);
  v8->M[3][2] = -1.0;
  v9 = viewMaxX - viewMinX;
  v10 = viewMinX + viewMaxX;
  v11 = 1.0 / (float)(viewMaxY - viewMinY);
  v12 = 1.0 / (float)(fNearZ - fFarZ);
  v8->M[0][2] = v10 * (float)(1.0 / v9);
  v8->M[0][0] = (float)(1.0 / v9) * (float)(focalLength * 2.0);
  v8->M[2][3] = (float)(fNearZ * fFarZ) * v12;
  v8->M[1][2] = (float)(viewMinY + viewMaxY) * v11;
  v8->M[1][1] = v11 * (float)(focalLength * 2.0);
  v8->M[2][2] = v12 * fFarZ;
}

// File Line: 1146
// RVA: 0x8EFB90
void __fastcall Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterLH(Scaleform::Render::Matrix4x4<float> *this, float focalLength, float viewMinX, float viewMaxX, float viewMinY, float viewMaxY, float fNearZ, float fFarZ)
{
  Scaleform::Render::Matrix4x4<float> *v8; // rbx

  v8 = this;
  memset(this, 0, 0x40ui64);
  v8->M[3][2] = 1.0;
  v8->M[0][0] = (float)(focalLength * 2.0) / (float)(viewMaxX - viewMinX);
  v8->M[1][1] = (float)(focalLength * 2.0) / (float)(viewMaxY - viewMinY);
  v8->M[2][2] = fFarZ / (float)(fFarZ - fNearZ);
  v8->M[2][3] = (float)(fNearZ * fFarZ) / (float)(fNearZ - fFarZ);
  v8->M[0][2] = (float)(viewMinX + viewMaxX) / (float)(viewMinX - viewMaxX);
  v8->M[1][2] = (float)(viewMinY + viewMaxY) / (float)(viewMinY - viewMaxY);
}

// File Line: 1189
// RVA: 0x8EF140
void __fastcall Scaleform::Render::Matrix4x4<float>::OrthoOffCenterRH(Scaleform::Render::Matrix4x4<float> *this, float viewMinX, float viewMaxX, float viewMinY, float viewMaxY, float fNearZ, float fFarZ)
{
  Scaleform::Render::Matrix4x4<float> *v7; // rbx

  v7 = this;
  memset(this, 0, 0x40ui64);
  v7->M[3][3] = 1.0;
  v7->M[0][0] = 2.0 / (float)(viewMaxX - viewMinX);
  v7->M[1][1] = 2.0 / (float)(viewMaxY - viewMinY);
  v7->M[2][2] = 1.0 / (float)(fNearZ - fFarZ);
  v7->M[0][3] = (float)(viewMinX + viewMaxX) / (float)(viewMinX - viewMaxX);
  v7->M[2][3] = (float)(1.0 / (float)(fNearZ - fFarZ)) * fNearZ;
  v7->M[1][3] = (float)(viewMinY + viewMaxY) / (float)(viewMinY - viewMaxY);
}

// File Line: 1205
// RVA: 0x8EF050
void __fastcall Scaleform::Render::Matrix4x4<float>::OrthoOffCenterLH(Scaleform::Render::Matrix4x4<float> *this, float viewMinX, float viewMaxX, float viewMinY, float viewMaxY, float fNearZ, float fFarZ)
{
  Scaleform::Render::Matrix4x4<float> *v7; // rbx

  v7 = this;
  memset(this, 0, 0x40ui64);
  v7->M[3][3] = 1.0;
  v7->M[0][0] = 2.0 / (float)(viewMaxX - viewMinX);
  v7->M[1][1] = 2.0 / (float)(viewMaxY - viewMinY);
  v7->M[2][2] = 1.0 / (float)(fFarZ - fNearZ);
  v7->M[2][3] = fNearZ / (float)(fNearZ - fFarZ);
  v7->M[0][3] = (float)(viewMinX + viewMaxX) / (float)(viewMinX - viewMaxX);
  v7->M[1][3] = (float)(viewMinY + viewMaxY) / (float)(viewMinY - viewMaxY);
}

// File Line: 1300
// RVA: 0x7E89F0
long double __fastcall Scaleform::Render::Matrix4x4<double>::GetDeterminant(Scaleform::Render::Matrix4x4<double> *this)
{
  double v1; // xmm2_8
  double v2; // xmm3_8
  double v3; // xmm7_8
  double v4; // xmm1_8
  double v5; // xmm6_8
  double v6; // xmm13_8
  long double v7; // xmm11_8
  long double v8; // xmm12_8
  long double v9; // xmm14_8
  long double v10; // xmm8_8
  long double v11; // xmm13_8
  long double v12; // xmm10_8

  v1 = this->M[2][3];
  v2 = this->M[3][3];
  v3 = this->M[2][2];
  v4 = this->M[3][0];
  v5 = this->M[3][2];
  v6 = this->M[2][0];
  v7 = this->M[2][2] * v2 - this->M[2][3] * v5;
  v8 = this->M[2][1] * v2 - this->M[3][1] * v1;
  v9 = this->M[2][1] * v5 - this->M[3][1] * v3;
  v10 = v6 * v2 - this->M[3][0] * v1;
  v11 = v6 * this->M[3][1] - v4 * this->M[2][1];
  v12 = this->M[2][0] * v5 - v4 * v3;
  return (this->M[1][1] * v7 - this->M[1][2] * v8 + this->M[1][3] * v9) * this->M[0][0]
       - (this->M[1][0] * v7 - v10 * this->M[1][2] + v12 * this->M[1][3]) * this->M[0][1]
       + (this->M[1][0] * v8 - v10 * this->M[1][1] + v11 * this->M[1][3]) * this->M[0][2]
       - (this->M[1][0] * v9 - v12 * this->M[1][1] + v11 * this->M[1][2]) * this->M[0][3];
}

// File Line: 1311
// RVA: 0x987610
Scaleform::Render::Matrix4x4<float> *__fastcall Scaleform::Render::Matrix4x4<float>::GetInverse(Scaleform::Render::Matrix4x4<float> *this, Scaleform::Render::Matrix4x4<float> *result)
{
  float v2; // xmm5_4
  float v3; // xmm3_4
  float v4; // xmm1_4
  Scaleform::Render::Matrix4x4<float> *v5; // rbx
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm13_4
  float v9; // xmm12_4
  float v10; // xmm15_4
  float v11; // xmm10_4
  float v12; // xmm2_4
  float v13; // xmm9_4
  float v14; // xmm5_4
  float v15; // xmm8_4
  float v16; // xmm13_4
  float v17; // xmm14_4
  float v18; // xmm2_4
  int v19; // xmm0_4
  int v20; // xmm1_4
  int v21; // xmm0_4
  int v22; // xmm1_4
  int v23; // xmm0_4
  int v24; // xmm0_4
  int v25; // xmm0_4
  int v26; // xmm1_4
  int v27; // xmm0_4
  float v28; // xmm12_4
  float v29; // xmm11_4
  float v30; // xmm5_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm9_4
  float v34; // xmm10_4
  float v35; // xmm8_4
  float v36; // ST2C_4
  unsigned int v37; // xmm11_4
  float v38; // xmm4_4
  unsigned int v39; // ST24_4
  float v40; // xmm3_4
  float v41; // xmm2_4
  float v42; // xmm10_4
  float v43; // xmm9_4
  float v44; // xmm5_4
  float v45; // xmm6_4
  float v46; // xmm10_4
  float v47; // xmm9_4
  float v48; // xmm11_4
  float v49; // xmm5_4
  float v50; // xmm9_4
  float v51; // xmm2_4
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm10_4
  float v55; // xmm4_4
  float v56; // xmm9_4
  float v57; // xmm8_4
  float v58; // xmm7_4
  float v59; // xmm1_4
  float v60; // xmm7_4
  float v61; // xmm4_4
  float v62; // xmm5_4
  float v63; // xmm3_4
  float v64; // xmm15_4
  float v65; // xmm2_4
  float v66; // xmm2_4
  float v67; // xmm2_4
  float v68; // xmm0_4
  float v69; // xmm4_4
  float v70; // xmm1_4
  float v71; // xmm7_4
  float v72; // xmm15_4
  float v73; // xmm0_4
  float v74; // xmm8_4
  float v76; // [rsp+20h] [rbp-108h]
  float v77; // [rsp+28h] [rbp-100h]
  float v78; // [rsp+30h] [rbp-F8h]
  char Dst; // [rsp+40h] [rbp-E8h]
  int v80; // [rsp+44h] [rbp-E4h]
  int v81; // [rsp+48h] [rbp-E0h]
  int v82; // [rsp+50h] [rbp-D8h]
  int v83; // [rsp+58h] [rbp-D0h]
  int v84; // [rsp+60h] [rbp-C8h]
  int v85; // [rsp+64h] [rbp-C4h]
  int v86; // [rsp+70h] [rbp-B8h]
  int v87; // [rsp+74h] [rbp-B4h]
  int v88; // [rsp+78h] [rbp-B0h]
  float v89; // [rsp+130h] [rbp+8h]
  float v90; // [rsp+130h] [rbp+8h]
  float v91; // [rsp+140h] [rbp+18h]
  unsigned int v92; // [rsp+140h] [rbp+18h]
  float v93; // [rsp+148h] [rbp+20h]

  v2 = this->M[3][0];
  v3 = this->M[2][0];
  v4 = this->M[3][3];
  v5 = result;
  v6 = this->M[2][1];
  v7 = this->M[1][3];
  v8 = this->M[2][2];
  v9 = this->M[0][3];
  v78 = this->M[0][0];
  v10 = this->M[2][3];
  v93 = this->M[1][2];
  v11 = (float)(this->M[3][1] * v3) - (float)(v2 * v6);
  v12 = (float)(this->M[3][2] * v3) - (float)(v2 * v8);
  v91 = v12;
  v89 = (float)(this->M[3][3] * v3) - (float)(this->M[3][0] * v10);
  v13 = (float)(this->M[3][2] * v6) - (float)(this->M[3][1] * v8);
  v14 = (float)(v4 * v6) - (float)(this->M[3][1] * v10);
  v15 = (float)(v4 * v8) - (float)(this->M[3][2] * v10);
  v77 = (float)((float)(v15 * this->M[1][1]) - (float)(v14 * v93)) + (float)(v13 * v7);
  LODWORD(v16) = COERCE_UNSIGNED_INT((float)((float)(v15 * this->M[1][0]) - (float)(v89 * v93)) + (float)(v12 * v7)) ^ _xmm[0];
  v76 = (float)((float)(v14 * this->M[1][0]) - (float)(v89 * this->M[1][1])) + (float)(v11 * v7);
  LODWORD(v17) = COERCE_UNSIGNED_INT((float)((float)(v13 * this->M[1][0]) - (float)(v12 * this->M[1][1])) + (float)(v11 * this->M[1][2])) ^ _xmm[0];
  v18 = (float)((float)((float)(v16 * this->M[0][1]) + (float)(v77 * this->M[0][0])) + (float)(v76 * this->M[0][2]))
      + (float)(v17 * v9);
  if ( v18 == 0.0 )
  {
    memset(&Dst, 0, 0x40ui64);
    v19 = v80;
    v20 = v81;
    LODWORD(v5->M[0][0]) = (_DWORD)FLOAT_1_0;
    LODWORD(v5->M[0][1]) = v19;
    v21 = v82;
    LODWORD(v5->M[0][2]) = v20;
    v22 = v85;
    LODWORD(v5->M[0][3]) = LODWORD(v9) ^ _xmm[0];
    LODWORD(v5->M[1][0]) = v21;
    v23 = v83;
    LODWORD(v5->M[1][1]) = (_DWORD)FLOAT_1_0;
    LODWORD(v5->M[1][2]) = v23;
    v24 = v84;
    LODWORD(v5->M[1][3]) = LODWORD(v7) ^ _xmm[0];
    LODWORD(v5->M[2][0]) = v24;
    v25 = v86;
    LODWORD(v5->M[2][1]) = v22;
    v26 = v87;
    LODWORD(v5->M[2][2]) = (_DWORD)FLOAT_1_0;
    LODWORD(v5->M[2][3]) = LODWORD(v10) ^ _xmm[0];
    LODWORD(v5->M[3][0]) = v25;
    v27 = v88;
    LODWORD(v5->M[3][1]) = v26;
    LODWORD(v5->M[3][2]) = v27;
    LODWORD(v5->M[3][3]) = (_DWORD)FLOAT_1_0;
  }
  else
  {
    v28 = 1.0 / v18;
    v29 = (float)((float)(v15 * this->M[0][1]) - (float)(v14 * this->M[0][2])) + (float)(v13 * this->M[0][3]);
    v30 = (float)(v14 * this->M[0][0]) - (float)(v89 * this->M[0][1]);
    v31 = v11;
    v32 = this->M[1][0];
    v33 = (float)((float)(v13 * this->M[0][0]) - (float)(v91 * this->M[0][1])) + (float)(v11 * this->M[0][2]);
    v34 = this->M[3][0];
    v90 = (float)((float)((float)(v15 * this->M[0][0]) - (float)(v89 * this->M[0][2])) + (float)(v91 * this->M[0][3]))
        * (float)(1.0 / v18);
    v35 = this->M[0][3];
    v36 = v33 * (float)(1.0 / v18);
    v37 = COERCE_UNSIGNED_INT(v29 * (float)(1.0 / v18)) ^ _xmm[0];
    v38 = (float)(this->M[3][1] * v32) - (float)(v34 * this->M[1][1]);
    v39 = COERCE_UNSIGNED_INT((float)(v30 + (float)(v31 * v35)) * (float)(1.0 / v18)) ^ _xmm[0];
    v40 = (float)(this->M[3][2] * v32) - (float)(v34 * this->M[1][2]);
    v41 = (float)(this->M[3][3] * v32) - (float)(v34 * v7);
    v42 = (float)(this->M[3][2] * this->M[1][1]) - (float)(this->M[3][1] * this->M[1][2]);
    v43 = (float)(this->M[3][3] * this->M[1][1]) - (float)(this->M[3][1] * v7);
    v44 = (float)(this->M[3][3] * v93) - (float)(this->M[3][2] * v7);
    v45 = (float)((float)((float)(v44 * this->M[0][1]) - (float)(v43 * this->M[0][2])) + (float)(v42 * v35)) * v28;
    v46 = v42 * this->M[0][0];
    v47 = v43 * this->M[0][0];
    LODWORD(result->M[0][1]) = v37;
    v48 = this->M[0][3];
    result->M[0][2] = v45;
    v49 = (float)(v44 * v78) - (float)(v41 * this->M[0][2]);
    v50 = v47 - (float)(v41 * this->M[0][1]);
    v51 = this->M[1][1];
    v52 = v38 * v35;
    v53 = this->M[1][0];
    v54 = (float)(v46 - (float)(v40 * this->M[0][1])) + (float)(v38 * this->M[0][2]);
    v55 = v10 * v53;
    v92 = COERCE_UNSIGNED_INT((float)(v49 + (float)(v40 * v35)) * v28) ^ _xmm[0];
    v56 = (float)(v50 + v52) * v28;
    v57 = (float)(this->M[2][1] * v53) - (float)(this->M[2][0] * v51);
    v58 = this->M[2][2] * v53;
    v59 = this->M[1][3];
    v60 = v58 - (float)(this->M[2][0] * this->M[1][2]);
    v61 = v55 - (float)(this->M[2][0] * v59);
    v62 = (float)(this->M[2][2] * v51) - (float)(this->M[2][1] * this->M[1][2]);
    v63 = (float)(v10 * v51) - (float)(this->M[2][1] * v59);
    v64 = (float)(v10 * this->M[1][2]) - (float)(this->M[2][2] * v59);
    v65 = v64 * this->M[0][1];
    result->M[0][0] = v28 * v77;
    v66 = (float)((float)(v65 - (float)(v63 * this->M[0][2])) + (float)(v62 * v48)) * v28;
    result->M[1][1] = v90;
    LODWORD(result->M[0][3]) = LODWORD(v66) ^ _xmm[0];
    v67 = this->M[0][0];
    result->M[1][0] = v28 * v16;
    LODWORD(result->M[1][2]) = v92;
    v68 = v61;
    v69 = v61 * this->M[0][1];
    v70 = v60;
    result->M[2][2] = v56;
    LODWORD(result->M[3][2]) = COERCE_UNSIGNED_INT(v54 * v28) ^ _xmm[0];
    v71 = v60 * this->M[0][1];
    v72 = (float)((float)(v64 * v67) - (float)(v68 * this->M[0][2])) + (float)(v70 * v48);
    result->M[2][0] = v28 * v76;
    LODWORD(result->M[2][1]) = v39;
    v73 = v57;
    v74 = v57 * this->M[0][2];
    result->M[1][3] = v72 * v28;
    result->M[3][0] = v28 * v17;
    result->M[3][1] = v36;
    result->M[3][3] = (float)((float)((float)(v62 * v67) - v71) + v74) * v28;
    LODWORD(result->M[2][3]) = COERCE_UNSIGNED_INT((float)((float)((float)(v63 * v67) - v69) + (float)(v73 * v48)) * v28) ^ _xmm[0];
  }
  return v5;
}t)((float)(v63 * v67) - v69) + (float)(v73 * v48)) * v28) ^ _xmm[0];
  }
  return v5;
}

