// File Line: 28
// RVA: 0xA45D50
float __fastcall AkMath::ToRadians(float in_fDegrees)
{
  return (float)(in_fDegrees - (float)(int)(float)(in_fDegrees * 0.0027777778)) * 0.017453292;
}

// File Line: 52
// RVA: 0xA45CE0
void __fastcall AkMath::Normalise(AkVector *io_Vector)
{
  float Y; // xmm3_4
  __m128 X_low; // xmm4
  float Z; // xmm5_4
  __m128 v4; // xmm2
  float v5; // xmm1_4

  Y = io_Vector->Y;
  X_low = (__m128)LODWORD(io_Vector->X);
  Z = io_Vector->Z;
  v4 = X_low;
  v4.m128_f32[0] = (float)((float)(X_low.m128_f32[0] * X_low.m128_f32[0]) + (float)(Y * Y)) + (float)(Z * Z);
  v5 = _mm_sqrt_ps(v4).m128_f32[0];
  if ( v5 != 0.0 )
  {
    io_Vector->Z = (float)(1.0 / v5) * Z;
    io_Vector->X = (float)(1.0 / v5) * X_low.m128_f32[0];
    io_Vector->Y = (float)(1.0 / v5) * Y;
  }
}

// File Line: 82
// RVA: 0xA45CB0
float __fastcall AkMath::Magnitude(AkVector *in_rVector)
{
  __m128 X_low; // xmm2
  float result; // xmm0_4

  X_low = (__m128)LODWORD(in_rVector->X);
  X_low.m128_f32[0] = (float)((float)(X_low.m128_f32[0] * X_low.m128_f32[0]) + (float)(in_rVector->Y * in_rVector->Y))
                    + (float)(in_rVector->Z * in_rVector->Z);
  LODWORD(result) = _mm_sqrt_ps(X_low).m128_u32[0];
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
  float Z; // xmm5_4
  float X; // xmm3_4
  AkVector *v5; // rax
  float v6; // xmm0_4
  float v7; // xmm4_4
  float v8; // xmm4_4

  Z = Vector2->Z;
  X = Vector2->X;
  v5 = result;
  v6 = Vector1->X;
  v7 = Vector1->X * Vector2->Y;
  result->X = (float)(Z * Vector1->Y) - (float)(Vector2->Y * Vector1->Z);
  v8 = v7 - (float)(X * Vector1->Y);
  result->Y = (float)(X * Vector1->Z) - (float)(v6 * Z);
  result->Z = v8;
  return v5;
}

// File Line: 114
// RVA: 0xA45C00
float __fastcall AkMath::Distance(AkVector *Position1, AkVector *Position2)
{
  __m128 Y_low; // xmm2
  float v3; // xmm0_4
  float result; // xmm0_4

  Y_low = (__m128)LODWORD(Position1->Y);
  v3 = Position1->Z - Position2->Z;
  Y_low.m128_f32[0] = (float)((float)((float)(Y_low.m128_f32[0] - Position2->Y)
                                    * (float)(Y_low.m128_f32[0] - Position2->Y))
                            + (float)((float)(Position1->X - Position2->X) * (float)(Position1->X - Position2->X)))
                    + (float)(v3 * v3);
  LODWORD(result) = _mm_sqrt_ps(Y_low).m128_u32[0];
  return result;
}

// File Line: 130
// RVA: 0xA45C70
float __fastcall AkMath::Interpolate(
        float in_fLowerX,
        float in_fLowerY,
        float in_fUpperX,
        float in_fUpperY,
        float in_fX)
{
  if ( in_fX <= in_fLowerX )
    return in_fLowerY;
  if ( in_fX < in_fUpperX )
    return (float)((float)((float)(in_fX - in_fLowerX) / (float)(in_fUpperX - in_fLowerX))
                 * (float)(in_fUpperY - in_fLowerY))
         + in_fLowerY;
  return in_fUpperY;
}

