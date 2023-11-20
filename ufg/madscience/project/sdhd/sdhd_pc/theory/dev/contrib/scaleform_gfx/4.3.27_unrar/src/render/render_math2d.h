// File Line: 120
// RVA: 0x9986F0
float __fastcall Scaleform::Render::Math2D::LinePointDistance(float x1, float y1, float x2, float y2, float x, float y)
{
  float v6; // xmm9_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm4_4
  __m128 v10; // xmm0
  float result; // xmm0_4

  v6 = x1;
  v7 = x2 - x1;
  v8 = y2 - y1;
  v9 = fsqrt((float)(v8 * v8) + (float)(v7 * v7));
  if ( v9 != 0.0 )
    return (float)((float)((float)(x - x2) * v8) - (float)((float)(y - y2) * v7)) / v9;
  v10 = (__m128)LODWORD(y);
  v10.m128_f32[0] = (float)((float)(y - y1) * (float)(y - y1)) + (float)((float)(x - v6) * (float)(x - v6));
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v10);
  return result;
}

// File Line: 217
// RVA: 0x935640
float __fastcall Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType>(Scaleform::Render::TessVertex *v1, Scaleform::Render::TessVertex *v2, Scaleform::Render::TessVertex *v3, float len1, float len2)
{
  float v5; // xmm6_4
  float v6; // xmm4_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm7_4

  v5 = v2->x - v1->x;
  v6 = v2->y - v1->y;
  v7 = v3->y - v2->y;
  v8 = v3->x - v2->x;
  v9 = (float)((float)(v7 * v6) + (float)(v8 * v5)) / (float)((float)(len1 * len2) * 2.0);
  if ( (float)(v8 * v6) > (float)(v7 * v5) )
    v9 = 1.0 - v9;
  return v9 - 0.5;
}

// File Line: 275
// RVA: 0x996890
char __fastcall Scaleform::Render::Math2D::Intersection(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, float *x, float *y, float epsilon)
{
  float v11; // xmm2_4
  float v12; // xmm7_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v16; // xmm1_4

  v11 = bx - ax;
  v12 = ay;
  v13 = by - ay;
  v14 = (float)((float)(dy - cy) * v11) - (float)((float)(dx - cx) * v13);
  if ( COERCE_FLOAT(LODWORD(v14) & _xmm) < epsilon )
    return 0;
  v16 = (float)((float)((float)(ay - cy) * (float)(dx - cx)) - (float)((float)(ax - cx) * (float)(dy - cy))) / v14;
  *x = (float)(v11 * v16) + ax;
  *y = (float)(v13 * v16) + v12;
  return 1;
}

// File Line: 454
// RVA: 0x8C4370
void __fastcall Scaleform::Render::Math2D::CubicCurveExtremum(float x1, float x2, float x3, float x4, float *t1, float *t2)
{
  float v6; // xmm6_4
  float v7; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm7_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm3_4

  v6 = x3;
  *t1 = -1.0;
  *t2 = -1.0;
  v7 = x3;
  v8 = x2 - x1;
  v9 = (float)((float)(x4 - (float)(v7 * 3.0)) + (float)(x2 * 3.0)) - x1;
  v10 = (float)(v6 - (float)(x2 * 2.0)) + x1;
  if ( COERCE_FLOAT(LODWORD(v9) & _xmm) <= 0.001 )
  {
    if ( COERCE_FLOAT(LODWORD(v10) & _xmm) > 0.001 )
      *(_DWORD *)t1 = COERCE_UNSIGNED_INT(v8 / (float)(v10 * 2.0)) ^ _xmm[0];
  }
  else
  {
    v11 = (float)(v10 * v10) - (float)(v8 * v9);
    if ( v11 <= 0.0 )
    {
      if ( v11 == 0.0 )
        *(_DWORD *)t1 = COERCE_UNSIGNED_INT(v10 / v9) ^ _xmm[0];
    }
    else
    {
      v12 = fsqrt(v11);
      *(_DWORD *)t1 = COERCE_UNSIGNED_INT((float)(v10 - v12) * (float)(1.0 / v9)) ^ _xmm[0];
      *(_DWORD *)t2 = COERCE_UNSIGNED_INT((float)(v12 + v10) * (float)(1.0 / v9)) ^ _xmm[0];
    }
  }
}

