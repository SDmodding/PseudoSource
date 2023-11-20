// File Line: 313
// RVA: 0x94EE20
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::operator*(Scaleform::Render::Matrix2x4<float> *result, Scaleform::Render::Matrix2x4<float> *m1, Scaleform::Render::Matrix2x4<float> *m2)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm5_4
  Scaleform::Render::Matrix2x4<float> *v6; // rax
  float v7; // xmm3_4
  float v8; // xmm12_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm13_4
  float v12; // xmm11_4
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4

  v3 = m2->M[1][0];
  v4 = m2->M[1][1];
  v5 = m2->M[0][1];
  result->M[0][2] = 0.0;
  result->M[1][2] = 0.0;
  v6 = result;
  v7 = m2->M[1][3];
  v8 = m1->M[0][3];
  v9 = v5;
  v10 = v5 * m1->M[1][0];
  v11 = m1->M[1][3];
  v12 = (float)(m2->M[0][0] * m1->M[1][0]) + (float)(v3 * m1->M[1][1]);
  result->M[0][0] = (float)(v3 * m1->M[0][1]) + (float)(m2->M[0][0] * m1->M[0][0]);
  result->M[1][0] = v12;
  v13 = v10 + (float)(v4 * m1->M[1][1]);
  v14 = (float)(v9 * m1->M[0][0]) + (float)(v4 * m1->M[0][1]);
  v15 = m2->M[0][3] * m1->M[0][0];
  v16 = v7 * m1->M[0][1];
  v17 = m2->M[0][3] * m1->M[1][0];
  result->M[0][1] = v14;
  result->M[1][1] = v13;
  result->M[0][3] = v8 + (float)(v15 + v16);
  result->M[1][3] = v11 + (float)(v17 + (float)(v7 * m1->M[1][1]));
  return v6;
}

// File Line: 505
// RVA: 0x6FDCE0
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::Matrix2x4<float>::Invert(Scaleform::Render::Matrix2x4<float> *this)
{
  float v1; // xmm1_4
  Scaleform::Render::Matrix2x4<float> *v2; // rbx
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v10; // [rsp+20h] [rbp-28h]
  float v11; // [rsp+24h] [rbp-24h]
  float v12; // [rsp+28h] [rbp-20h]
  float v13; // [rsp+2Ch] [rbp-1Ch]
  float v14; // [rsp+30h] [rbp-18h]
  float v15; // [rsp+34h] [rbp-14h]
  float v16; // [rsp+38h] [rbp-10h]
  float v17; // [rsp+3Ch] [rbp-Ch]

  v1 = this->M[0][1];
  v2 = this;
  v10 = this->M[0][0];
  v3 = this->M[0][2];
  v11 = v1;
  v4 = this->M[0][3];
  v12 = v3;
  v5 = this->M[1][0];
  v13 = v4;
  v6 = this->M[1][1];
  v14 = v5;
  v7 = this->M[1][2];
  v15 = v6;
  v8 = this->M[1][3];
  v16 = v7;
  v17 = v8;
  Scaleform::Render::Matrix2x4<float>::SetInverse(this, (Scaleform::Render::Matrix2x4<float> *)&v10);
  return v2;
}

// File Line: 618
// RVA: 0x807E80
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::Matrix2x4<float>::PrependScaling(Scaleform::Render::Matrix2x4<float> *this, float sx, float sy)
{
  float v3; // xmm3_4
  float v4; // xmm5_4
  Scaleform::Render::Matrix2x4<float> *result; // rax
  float v6; // xmm8_4
  float v7; // xmm9_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm8_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm8_4

  v3 = this->M[0][1];
  v4 = this->M[1][1];
  this->M[1][2] = 0.0;
  this->M[0][2] = 0.0;
  result = this;
  v6 = this->M[1][0];
  v7 = this->M[0][0] * 0.0;
  v8 = v4;
  this->M[0][0] = (float)(this->M[0][0] * sx) + (float)(v3 * 0.0);
  v9 = v6;
  v10 = v6 * 0.0;
  v11 = (float)(v4 * sy) + v10;
  v12 = v8 * 0.0;
  v13 = (float)(v10 + v12) + this->M[1][3];
  this->M[0][3] = (float)(v7 + (float)(v3 * 0.0)) + this->M[0][3];
  this->M[1][0] = (float)(v9 * sx) + v12;
  this->M[1][3] = v13;
  this->M[0][1] = (float)(v3 * sy) + v7;
  this->M[1][1] = v11;
  return result;
}

// File Line: 637
// RVA: 0x6DA810
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::Matrix2x4<float>::AppendScaling(Scaleform::Render::Matrix2x4<float> *this, float sx, float sy)
{
  Scaleform::Render::Matrix2x4<float> *result; // rax
  float v4; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4

  result = this;
  v4 = sx * this->M[0][1];
  this->M[0][0] = sx * this->M[0][0];
  this->M[0][1] = v4;
  v5 = sx * this->M[0][2];
  v6 = sx * this->M[0][3];
  this->M[0][2] = v5;
  this->M[0][3] = v6;
  v7 = sy * this->M[1][1];
  this->M[1][0] = sy * this->M[1][0];
  this->M[1][1] = v7;
  v8 = sy * this->M[1][2];
  v9 = sy * this->M[1][3];
  this->M[1][2] = v8;
  this->M[1][3] = v9;
  return result;
}

// File Line: 681
// RVA: 0x6DA790
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::Matrix2x4<float>::AppendRotation(Scaleform::Render::Matrix2x4<float> *this, float radians)
{
  Scaleform::Render::Matrix2x4<float> *v2; // rbx
  float v3; // xmm7_4
  float v4; // xmm0_4
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-48h]

  v2 = this;
  v3 = cosf(radians);
  v4 = sinf(radians);
  m.M[0][0] = v3;
  *(_QWORD *)&m.M[0][2] = 0i64;
  *(_OWORD *)&m.M[1][0] = __PAIR__(LODWORD(v3), LODWORD(v4));
  *(_QWORD *)&m.M[0][1] = (unsigned int)(LODWORD(v4) ^ _xmm[0]);
  return Scaleform::Render::Matrix2x4<float>::Append(v2, &m);
}

// File Line: 703
// RVA: 0x997810
bool __fastcall Scaleform::Render::Matrix2x4<float>::IsFreeRotation(Scaleform::Render::Matrix2x4<float> *this, float epsilon)
{
  return COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(this->M[0][1] * 0.0) + this->M[0][0]) & _xmm) > epsilon
      && COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(this->M[1][1] * 0.0) + this->M[1][0]) & _xmm) > epsilon;
}

// File Line: 713
// RVA: 0x700F20
bool __fastcall Scaleform::Render::Matrix2x4<float>::IsValid(Scaleform::Render::Matrix2x4<float> *this)
{
  float v1; // xmm2_4
  float v2; // xmm2_4
  float v3; // xmm2_4
  float v4; // xmm2_4
  float v5; // xmm2_4
  float v6; // xmm2_4
  float v7; // xmm2_4
  bool result; // al

  result = 0;
  if ( this->M[0][0] >= -3.4028235e38 && this->M[0][0] <= 3.4028235e38 )
  {
    v1 = this->M[0][1];
    if ( v1 >= -3.4028235e38 && v1 <= 3.4028235e38 )
    {
      v2 = this->M[0][2];
      if ( v2 >= -3.4028235e38 && v2 <= 3.4028235e38 )
      {
        v3 = this->M[0][3];
        if ( v3 >= -3.4028235e38 && v3 <= 3.4028235e38 )
        {
          v4 = this->M[1][0];
          if ( v4 >= -3.4028235e38 && v4 <= 3.4028235e38 )
          {
            v5 = this->M[1][1];
            if ( v5 >= -3.4028235e38 && v5 <= 3.4028235e38 )
            {
              v6 = this->M[1][2];
              if ( v6 >= -3.4028235e38 && v6 <= 3.4028235e38 )
              {
                v7 = this->M[1][3];
                if ( v7 >= -3.4028235e38 && v7 <= 3.4028235e38 )
                  result = 1;
              }
            }
          }
        }
      }
    }
  }
  return result;
}

// File Line: 727
// RVA: 0x819A00
void __fastcall Scaleform::Render::Matrix2x4<double>::SetIdentity(Scaleform::Render::Matrix2x4<double> *this)
{
  *(_OWORD *)&this->M[0][0] = 0x3FF0000000000000ui64;
  *(_OWORD *)&this->M[0][2] = 0ui64;
  this->M[1][0] = 0.0;
  *(_OWORD *)&this->M[1][1] = 0x3FF0000000000000ui64;
  this->M[1][3] = 0.0;
}

// File Line: 741
// RVA: 0x9B6010
void __fastcall Scaleform::Render::Matrix2x4<float>::SetZero(Scaleform::Render::Matrix2x4<float> *this)
{
  *(_OWORD *)&this->M[0][0] = 0ui64;
  *(_OWORD *)&this->M[1][0] = 0ui64;
}

// File Line: 756
// RVA: 0x530F0
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::Matrix2x4<float>::Prepend(Scaleform::Render::Matrix2x4<float> *this, Scaleform::Render::Matrix2x4<float> *m)
{
  float v2; // xmm3_4
  float v3; // xmm4_4
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  Scaleform::Render::Matrix2x4<float> *result; // rax

  v2 = this->M[0][0];
  v3 = this->M[0][1];
  v4 = this->M[1][0];
  v5 = this->M[1][1];
  v6 = this->M[1][1];
  v7 = this->M[1][0];
  this->M[0][0] = (float)(this->M[0][1] * m->M[1][0]) + (float)(this->M[0][0] * m->M[0][0]);
  this->M[1][0] = (float)(v6 * m->M[1][0]) + (float)(v7 * m->M[0][0]);
  this->M[0][1] = (float)(v3 * m->M[1][1]) + (float)(v2 * m->M[0][1]);
  v8 = v5 * m->M[1][1];
  v9 = v4 * m->M[0][1];
  this->M[1][2] = 0.0;
  this->M[0][2] = 0.0;
  result = this;
  this->M[1][1] = v8 + v9;
  this->M[0][3] = (float)((float)(v3 * m->M[1][3]) + (float)(v2 * m->M[0][3])) + this->M[0][3];
  this->M[1][3] = (float)((float)(v5 * m->M[1][3]) + (float)(v4 * m->M[0][3])) + this->M[1][3];
  return result;
}

// File Line: 833
// RVA: 0x7B0560
Scaleform::Render::Matrix2x4<double> *__fastcall Scaleform::Render::Matrix2x4<double>::Append(Scaleform::Render::Matrix2x4<double> *this, Scaleform::Render::Matrix2x4<double> *m)
{
  return Scaleform::Render::Matrix2x4<double>::Append_NonOpt(this, m);
}

// File Line: 839
// RVA: 0x7B0AE0
Scaleform::Render::Matrix2x4<double> *__fastcall Scaleform::Render::Matrix2x4<double>::Append_NonOpt(Scaleform::Render::Matrix2x4<double> *this, Scaleform::Render::Matrix2x4<double> *m)
{
  double v2; // xmm3_8
  double v3; // xmm2_8
  double v4; // xmm5_8
  double v5; // xmm7_8
  double v6; // xmm6_8
  double v7; // xmm4_8
  double v8; // xmm0_8
  long double v9; // xmm4_8
  long double v10; // xmm5_8
  Scaleform::Render::Matrix2x4<double> *result; // rax

  v2 = this->M[0][0];
  v3 = this->M[1][0];
  v4 = this->M[0][1];
  v5 = this->M[0][3];
  v6 = this->M[1][3];
  v7 = this->M[1][1];
  v8 = this->M[0][1];
  this->M[0][0] = this->M[1][0] * m->M[0][1] + this->M[0][0] * m->M[0][0];
  this->M[1][0] = v3 * m->M[1][1] + v2 * m->M[1][0];
  this->M[0][1] = v7 * m->M[0][1] + v8 * m->M[0][0];
  v9 = v7 * m->M[1][1];
  v10 = v4 * m->M[1][0];
  this->M[0][2] = 0.0;
  this->M[1][2] = 0.0;
  result = this;
  this->M[1][1] = v9 + v10;
  this->M[0][3] = v6 * m->M[0][1] + v5 * m->M[0][0] + m->M[0][3];
  this->M[1][3] = v6 * m->M[1][1] + v5 * m->M[1][0] + m->M[1][3];
  return result;
}

// File Line: 855
// RVA: 0x9B1010
void __fastcall Scaleform::Render::Matrix2x4<float>::SetLerp(Scaleform::Render::Matrix2x4<float> *this, Scaleform::Render::Matrix2x4<float> *m1, Scaleform::Render::Matrix2x4<float> *m2, float t)
{
  this->M[0][0] = (float)((float)(m2->M[0][0] - m1->M[0][0]) * t) + m1->M[0][0];
  this->M[1][0] = (float)((float)(m2->M[1][0] - m1->M[1][0]) * t) + m1->M[1][0];
  this->M[0][1] = (float)((float)(m2->M[0][1] - m1->M[0][1]) * t) + m1->M[0][1];
  this->M[1][1] = (float)((float)(m2->M[1][1] - m1->M[1][1]) * t) + m1->M[1][1];
  this->M[0][2] = (float)((float)(m2->M[0][2] - m1->M[0][2]) * t) + m1->M[0][2];
  this->M[1][2] = (float)((float)(m2->M[1][2] - m1->M[1][2]) * t) + m1->M[1][2];
  this->M[0][3] = (float)((float)(m2->M[0][3] - m1->M[0][3]) * t) + m1->M[0][3];
  this->M[1][3] = (float)((float)(m2->M[1][3] - m1->M[1][3]) * t) + m1->M[1][3];
}

// File Line: 870
// RVA: 0x7228D0
void __fastcall Scaleform::Render::Matrix2x4<float>::Transform(Scaleform::Render::Matrix2x4<float> *this, Scaleform::Render::Point<float> *result, Scaleform::Render::Point<float> *p)
{
  result->x = (float)((float)(this->M[0][1] * p->y) + (float)(p->x * this->M[0][0])) + this->M[0][3];
  result->y = (float)((float)(this->M[1][0] * p->x) + (float)(this->M[1][1] * p->y)) + this->M[1][3];
}

// File Line: 891
// RVA: 0x722920
void __fastcall Scaleform::Render::Matrix2x4<float>::TransformByInverse(Scaleform::Render::Matrix2x4<float> *this, Scaleform::Render::Point<float> *result, Scaleform::Render::Point<float> *p)
{
  float v3; // xmm5_4
  float v4; // xmm4_4
  float v5; // xmm3_4
  Scaleform::Render::Point<float> *v6; // rdi
  Scaleform::Render::Point<float> *v7; // rbx
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  Scaleform::Render::Matrix2x4<float> v14; // [rsp+20h] [rbp-60h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+40h] [rbp-40h]

  v3 = this->M[0][2];
  v4 = this->M[0][3];
  v5 = this->M[1][0];
  v6 = result;
  v7 = p;
  v8 = this->M[0][1];
  v9 = this->M[1][1];
  v10 = this->M[1][2];
  v11 = this->M[1][3];
  v14.M[0][0] = this->M[0][0];
  *(_QWORD *)&m.M[0][0] = __PAIR__(LODWORD(v8), LODWORD(v14.M[0][0]));
  *(_QWORD *)&v14.M[0][1] = __PAIR__(LODWORD(v3), LODWORD(v8));
  v14.M[0][3] = v4;
  *(_QWORD *)&v14.M[1][0] = __PAIR__(LODWORD(v9), LODWORD(v5));
  *(_QWORD *)&v14.M[1][2] = __PAIR__(LODWORD(v11), LODWORD(v10));
  *(_QWORD *)&m.M[0][2] = __PAIR__(LODWORD(v4), LODWORD(v3));
  *(_QWORD *)&m.M[1][0] = __PAIR__(LODWORD(v9), LODWORD(v5));
  *(_QWORD *)&m.M[1][2] = __PAIR__(LODWORD(v11), LODWORD(v10));
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v14, &m);
  v12 = v14.M[1][1];
  v13 = v14.M[1][0];
  v6->x = (float)((float)(v14.M[0][1] * v7->y) + (float)(v14.M[0][0] * v7->x)) + v14.M[0][3];
  v6->y = (float)((float)(v12 * v7->y) + (float)(v13 * v7->x)) + v14.M[1][3];
}

// File Line: 899
// RVA: 0x714C20
void __fastcall Scaleform::Render::Matrix2x4<float>::SetInverse(Scaleform::Render::Matrix2x4<float> *this, Scaleform::Render::Matrix2x4<float> *m)
{
  float v2; // xmm1_4
  float v3; // xmm6_4
  float v4; // xmm4_4
  float v5; // xmm2_4
  float v6; // xmm5_4

  v2 = (float)(m->M[1][1] * m->M[0][0]) - (float)(m->M[0][1] * m->M[1][0]);
  if ( v2 == 0.0 )
  {
    *(_QWORD *)&this->M[0][0] = 1065353216i64;
    *(_QWORD *)&this->M[1][1] = 1065353216i64;
    *(_QWORD *)&this->M[0][2] = 0i64;
    this->M[1][3] = 0.0;
    this->M[1][0] = 0.0;
    LODWORD(this->M[0][3]) = LODWORD(m->M[0][3]) ^ _xmm[0];
    LODWORD(this->M[1][3]) = LODWORD(m->M[1][3]) ^ _xmm[0];
  }
  else
  {
    v3 = m->M[1][1] * (float)(1.0 / v2);
    this->M[0][0] = v3;
    v4 = (float)(1.0 / v2) * m->M[0][0];
    this->M[1][1] = v4;
    LODWORD(v5) = COERCE_UNSIGNED_INT((float)(1.0 / v2) * m->M[0][1]) ^ _xmm[0];
    this->M[0][1] = v5;
    LODWORD(v6) = COERCE_UNSIGNED_INT((float)(1.0 / v2) * m->M[1][0]) ^ _xmm[0];
    this->M[1][0] = v6;
    LODWORD(this->M[0][3]) = COERCE_UNSIGNED_INT((float)(m->M[0][3] * v3) + (float)(m->M[1][3] * v5)) ^ _xmm[0];
    LODWORD(this->M[1][3]) = COERCE_UNSIGNED_INT((float)(m->M[1][3] * v4) + (float)(m->M[0][3] * v6)) ^ _xmm[0];
  }
}

// File Line: 939
// RVA: 0x982D10
float __fastcall Scaleform::Render::Matrix2x4<float>::GetDeterminant(Scaleform::Render::Matrix2x4<float> *this)
{
  return (float)(this->M[1][1] * this->M[0][0]) - (float)(this->M[1][0] * this->M[0][1]);
}

// File Line: 948
// RVA: 0x989030
float __fastcall Scaleform::Render::Matrix2x4<float>::GetMaxScale(Scaleform::Render::Matrix2x4<float> *this)
{
  __m128 v1; // xmm2
  __m128 v2; // xmm0
  float result; // xmm0_4

  v1 = (__m128)LODWORD(this->M[0][0]);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] * v1.m128_f32[0]) + (float)(this->M[1][0] * this->M[1][0]);
  v2 = (__m128)LODWORD(this->M[0][1]);
  v2.m128_f32[0] = (float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(this->M[1][1] * this->M[1][1]);
  if ( v2.m128_f32[0] >= v1.m128_f32[0] )
    LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v2);
  else
    LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v1);
  return result;
}

// File Line: 976
// RVA: 0x4FC00
float __fastcall Scaleform::Render::Matrix2x4<float>::GetXScale(Scaleform::Render::Matrix2x4<float> *this)
{
  __m128 v1; // xmm1
  float result; // xmm0_4

  v1 = (__m128)LODWORD(this->M[0][0]);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] * v1.m128_f32[0]) + (float)(this->M[1][0] * this->M[1][0]);
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v1);
  return result;
}

// File Line: 982
// RVA: 0x4FC20
float __fastcall Scaleform::Render::Matrix2x4<float>::GetYScale(Scaleform::Render::Matrix2x4<float> *this)
{
  __m128 v1; // xmm1
  float result; // xmm0_4

  v1 = (__m128)LODWORD(this->M[0][1]);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] * v1.m128_f32[0]) + (float)(this->M[1][1] * this->M[1][1]);
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v1);
  return result;
}

// File Line: 988
// RVA: 0x98B250
void __fastcall Scaleform::Render::Matrix2x4<float>::GetRotation(Scaleform::Render::Matrix2x4<float> *this)
{
  atan2f(this->M[1][0], this->M[0][0]);
}

// File Line: 994
// RVA: 0x6F88E0
long double __fastcall Scaleform::Render::Matrix2x4<float>::GetXScaleDouble(Scaleform::Render::Matrix2x4<float> *this)
{
  __m128d v1; // xmm1
  long double result; // xmm0_8

  v1 = _mm_cvtps_pd((__m128)LODWORD(this->M[0][0]));
  v1.m128d_f64[0] = v1.m128d_f64[0] * v1.m128d_f64[0] + this->M[1][0] * this->M[1][0];
  *(_QWORD *)&result = (unsigned __int128)_mm_sqrt_pd(v1);
  return result;
}

// File Line: 1000
// RVA: 0x6F8900
long double __fastcall Scaleform::Render::Matrix2x4<float>::GetYScaleDouble(Scaleform::Render::Matrix2x4<float> *this)
{
  __m128d v1; // xmm1
  long double result; // xmm0_8

  v1 = _mm_cvtps_pd((__m128)LODWORD(this->M[0][1]));
  v1.m128d_f64[0] = v1.m128d_f64[0] * v1.m128d_f64[0] + this->M[1][1] * this->M[1][1];
  *(_QWORD *)&result = (unsigned __int128)_mm_sqrt_pd(v1);
  return result;
}

// File Line: 1006
// RVA: 0x6F53A0
void __fastcall Scaleform::Render::Matrix2x4<float>::GetRotationDouble(Scaleform::Render::Matrix2x4<float> *this)
{
  atan2(this->M[1][0], this->M[0][0]);
}

// File Line: 1013
// RVA: 0x8DDF50
float __fastcall Scaleform::Render::Matrix2x4<float>::GetScale(Scaleform::Render::Matrix2x4<float> *this)
{
  __m128 v1; // xmm1
  float result; // xmm0_4

  v1 = (__m128)LODWORD(this->M[1][1]);
  v1.m128_f32[0] = (float)((float)((float)(v1.m128_f32[0] + this->M[1][0]) * 0.70710677)
                         * (float)((float)(v1.m128_f32[0] + this->M[1][0]) * 0.70710677))
                 + (float)((float)((float)(this->M[0][1] + this->M[0][0]) * 0.70710677)
                         * (float)((float)(this->M[0][1] + this->M[0][0]) * 0.70710677));
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v1);
  return result;
}

// File Line: 1095
// RVA: 0x9B2790
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::Matrix2x4<float>::SetParlToParl(Scaleform::Render::Matrix2x4<float> *this, const float *src, const float *dst)
{
  float v3; // xmm2_4
  float v4; // xmm5_4
  float v5; // xmm1_4
  Scaleform::Render::Matrix2x4<float> *v6; // rbx
  __m128 v7; // ST20_16
  __m128 v8; // ST30_16
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  Scaleform::Render::Matrix2x4<float> *result; // rax
  __m128 v14; // xmm7
  __m128 v15; // xmm5
  __m128 v16; // xmm0

  v3 = *src;
  v4 = src[1];
  v5 = src[4];
  v6 = this;
  v7.m128_i32[2] = 0;
  v8.m128_i32[2] = 0;
  v9 = src[2];
  v10 = src[5];
  v11 = src[3];
  this->M[0][2] = 0.0;
  this->M[1][2] = 0.0;
  this->M[0][3] = v3;
  this->M[0][0] = v9 - v3;
  this->M[0][1] = v5 - v3;
  this->M[1][3] = v4;
  this->M[1][0] = v11 - v4;
  this->M[1][1] = v10 - v4;
  v7.m128_f32[3] = *dst;
  v12 = dst[1];
  v7.m128_f32[0] = dst[2] - *dst;
  v7.m128_f32[1] = dst[4] - *dst;
  v8.m128_f32[3] = dst[1];
  v8.m128_f32[0] = dst[3] - v12;
  v8.m128_f32[1] = dst[5] - v12;
  Scaleform::Render::Matrix2x4<float>::Invert(this);
  result = v6;
  v14 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
  v15 = _mm_and_ps(v8, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
  v16 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), *(__m128 *)&v6->M[0][0]);
  *(__m128 *)&v6->M[0][0] = _mm_and_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), *(__m128 *)&v6->M[1][0]),
                                  _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), *(__m128 *)&v6->M[0][0])),
                                _mm_and_ps(
                                  v7,
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
  *(__m128 *)&v6->M[1][0] = _mm_and_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), *(__m128 *)&v6->M[1][0]), v16),
                                v15),
                              v14);
  return result;
}

