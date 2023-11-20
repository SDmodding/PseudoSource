// File Line: 28
// RVA: 0xA45D50
float __fastcall AkMath::ToRadians(float in_fDegrees)
{
  return (float)(in_fDegrees - (float)(signed int)(float)(in_fDegrees * 0.0027777778)) * 0.017453292;
}

// File Line: 52
// RVA: 0xA45CE0
void __fastcall AkMath::Normalise(AkVector *io_Vector)
{
  float v1; // xmm3_4
  __m128 v2; // xmm4
  float v3; // xmm5_4
  __m128 v4; // xmm2
  float v5; // xmm1_4

  v1 = io_Vector->Y;
  v2 = (__m128)LODWORD(io_Vector->X);
  v3 = io_Vector->Z;
  v4 = v2;
  v4.m128_f32[0] = (float)((float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(v1 * v1)) + (float)(v3 * v3);
  LODWORD(v5) = (unsigned __int128)_mm_sqrt_ps(v4);
  if ( v5 != 0.0 )
  {
    io_Vector->Z = (float)(1.0 / v5) * v3;
    io_Vector->X = (float)(1.0 / v5) * v2.m128_f32[0];
    io_Vector->Y = (float)(1.0 / v5) * v1;
  }
}

// File Line: 82
// RVA: 0xA45CB0
float __fastcall AkMath::Magnitude(AkVector *in_rVector)
{
  __m128 v1; // xmm2
  float result; // xmm0_4

  v1 = (__m128)LODWORD(in_rVector->X);
  v1.m128_f32[0] = (float)((float)(v1.m128_f32[0] * v1.m128_f32[0]) + (float)(in_rVector->Y * in_rVector->Y))
                 + (float)(in_rVector->Z * in_rVector->Z);
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v1);
  return result;
}

// File Line: 96
// RVA: 0xA45C40
float __fastcall AkMath::DotProduct(AkVector *Vector1, AkVector *Vector2)
{
  return (float)((float)(Vector1->Y * Vector2->Y) + (float)(Vector1->X * Vector2->X)) + (float)(Vector1->Z * Vector2->Z);
}

// File Line: 102
// RVA: 0xA45BA0
AkVector *__fastcall AkMath::CrossProduct(AkVector *result, AkVector *Vector1, AkVector *Vector2)
{
  float v3; // xmm5_4
  float v4; // xmm3_4
  AkVector *v5; // rax
  float v6; // xmm0_4
  float v7; // xmm4_4
  float v8; // xmm4_4

  v3 = Vector2->Z;
  v4 = Vector2->X;
  v5 = result;
  v6 = Vector1->X;
  v7 = Vector1->X * Vector2->Y;
  result->X = (float)(Vector2->Z * Vector1->Y) - (float)(Vector2->Y * Vector1->Z);
  v8 = v7 - (float)(v4 * Vector1->Y);
  result->Y = (float)(v4 * Vector1->Z) - (float)(v6 * v3);
  result->Z = v8;
  return v5;
}

// File Line: 114
// RVA: 0xA45C00
float __fastcall AkMath::Distance(AkVector *Position1, AkVector *Position2)
{
  __m128 v2; // xmm2
  float v3; // xmm0_4
  float result; // xmm0_4

  v2 = (__m128)LODWORD(Position1->Y);
  v3 = Position1->Z - Position2->Z;
  v2.m128_f32[0] = (float)((float)((float)(v2.m128_f32[0] - Position2->Y) * (float)(v2.m128_f32[0] - Position2->Y))
                         + (float)((float)(Position1->X - Position2->X) * (float)(Position1->X - Position2->X)))
                 + (float)(v3 * v3);
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v2);
  return result;
}

// File Line: 130
// RVA: 0xA45C70
float __fastcall AkMath::Interpolate(float in_fLowerX, float in_fLowerY, float in_fUpperX, float in_fUpperY, float in_fX)
{
  if ( in_fX <= in_fLowerX )
    return in_fLowerY;
  if ( in_fX < in_fUpperX )
    return (float)((float)((float)(in_fX - in_fLowerX) / (float)(in_fUpperX - in_fLowerX))
                 * (float)(in_fUpperY - in_fLowerY))
         + in_fLowerY;
  return in_fUpperY;
}

