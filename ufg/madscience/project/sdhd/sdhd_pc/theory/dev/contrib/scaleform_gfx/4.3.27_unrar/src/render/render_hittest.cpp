// File Line: 37
// RVA: 0x95E5D0
bool __fastcall Scaleform::Render::Math2D::CheckMonoQuadIntersection(
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x,
        float y)
{
  int v12; // ecx
  float v13; // xmm9_4
  BOOL v14; // edx
  float v15; // xmm4_4
  float v16; // xmm1_4
  bool v17; // cf
  bool v18; // zf
  float v19; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm0_4

  if ( y < y1 || y >= y3 )
    return 0;
  v12 = 0;
  v13 = x2 - x1;
  v14 = (float)((float)((float)(y2 - y1) * (float)(x - x2)) - (float)((float)(y - y2) * (float)(x2 - x1))) > 0.0;
  v15 = (float)(x3 - x1) * (float)(y - y3);
  v16 = (float)((float)(y3 - y2) * (float)(x - x3)) - (float)((float)(y - y3) * (float)(x3 - x2));
  v17 = v16 < 0.0;
  v18 = v16 == 0.0;
  v19 = y3 - y1;
  if ( !v17 && !v18 && (float)((float)((float)(y3 - y1) * (float)(x - x3)) - v15) > 0.0 && v14 )
    return 1;
  LOBYTE(v12) = (float)((float)((float)(y3 - y1) * (float)(x - x3)) - v15) > 0.0;
  if ( ((v17 || v18) & (v12 ^ 1) & !v14) != 0 )
    return 0;
  v21 = FLOAT_N1_0;
  v22 = (float)(y1 - (float)(y2 * 2.0)) + y3;
  if ( v22 == 0.0 )
  {
    if ( v19 != 0.0 )
      v21 = (float)(y - y1) / v19;
  }
  else
  {
    v23 = (float)((float)((float)(y2 * y2) - (float)((float)(y3 - y) * y1)) - (float)((float)(y * 2.0) * y2))
        + (float)(y3 * y);
    v24 = 0.0;
    if ( v23 > 0.0 )
      v24 = fsqrt(v23);
    v21 = (float)((float)(v24 + y1) - y2) / v22;
  }
  return x > (float)((float)((float)((float)((float)((float)(x3 - x2) * v21) + x2) - (float)((float)(v13 * v21) + x1))
                           * v21)
                   + (float)((float)(v13 * v21) + x1));
}

// File Line: 93
// RVA: 0x95E810
bool __fastcall Scaleform::Render::Math2D::CheckQuadIntersection(
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x,
        float y)
{
  float v10; // xmm8_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm13_4
  float v16; // xmm14_4
  float v17; // xmm10_4
  float v18; // xmm9_4
  float v19; // xmm12_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm15_4
  float v23; // xmm4_4
  float v24; // xmm0_4
  float v25; // xmm4_4
  float v26; // xmm11_4
  bool v27; // bl
  float v28; // [rsp+F8h] [rbp+10h]

  v10 = y3;
  if ( y2 >= y1 && y2 <= y3 )
    return Scaleform::Render::Math2D::CheckMonoQuadIntersection(x1, y1, x2, y2, x3, y3, x, y);
  v12 = (float)((float)(y2 * 2.0) - y1) - y3;
  if ( v12 == 0.0 )
    v13 = FLOAT_N1_0;
  else
    v13 = (float)(y2 - y1) / v12;
  v14 = x3;
  v15 = x1;
  v16 = y1;
  v17 = (float)((float)(y2 - y1) * v13) + y1;
  v18 = (float)((float)(x2 - x1) * v13) + x1;
  v19 = (float)((float)(x3 - x2) * v13) + x2;
  v20 = (float)((float)(y3 - y2) * v13) + y2;
  v21 = (float)((float)(v19 - v18) * v13) + v18;
  v22 = v21;
  v23 = (float)(v20 - v17) * v13;
  v24 = v21;
  v25 = v23 + v17;
  v28 = v25;
  v26 = v25;
  if ( y1 > v25 )
  {
    v28 = y1;
    v15 = v21;
    v22 = x1;
    v16 = v25;
  }
  if ( v25 > y3 )
  {
    v24 = x3;
    v26 = y3;
    v14 = v21;
    v10 = v25;
  }
  v27 = Scaleform::Render::Math2D::CheckMonoQuadIntersection(v24, v26, v19, v20, v14, v10, x, y);
  return Scaleform::Render::Math2D::CheckMonoQuadIntersection(v15, v16, v18, v17, v22, v28, x, y) != v27;
}

// File Line: 150
// RVA: 0x9351C0
void __fastcall Scaleform::Render::Math2D::SubdivideCubicToQuads<Scaleform::Render::Math2D::QuadCurvePath>(
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4,
        Scaleform::Render::Math2D::QuadCurvePath *path)
{
  float v12; // xmm7_4
  float v15; // xmm9_4
  float v16; // xmm10_4
  float v17; // xmm3_4
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  float v20; // xmm11_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm9_4
  float v24; // xmm10_4
  float v25; // xmm1_4
  float v26; // xmm6_4
  float v27; // xmm0_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  float v30; // [rsp+50h] [rbp-C8h]
  Scaleform::Render::Math2D::QuadCoord val; // [rsp+58h] [rbp-C0h] BYREF
  float y1a; // [rsp+120h] [rbp+8h]
  float x1a; // [rsp+128h] [rbp+10h]
  float x2a; // [rsp+130h] [rbp+18h]
  float y2a; // [rsp+138h] [rbp+20h]
  float x3a; // [rsp+140h] [rbp+28h]
  float y3a; // [rsp+148h] [rbp+30h]

  x2a = x2;
  v12 = x2;
  while ( 1 )
  {
    v18 = (__m128)LODWORD(y4);
    v15 = v12 - x1;
    v16 = y2 - y1;
    v17 = x4 - x3;
    v18.m128_f32[0] = y4 - y3;
    v19 = v18;
    v19.m128_f32[0] = (float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)(v17 * v17);
    v20 = (float)((float)(fsqrt(
                            (float)((float)(y3 - y2) * (float)(y3 - y2))
                          + (float)((float)(x3 - v12) * (float)(x3 - v12)))
                        + fsqrt((float)(v16 * v16) + (float)(v15 * v15)))
                + _mm_sqrt_ps(v19).m128_f32[0])
        * 0.0049999999;
    v21 = (float)((float)(y4 - y3) * (float)(v12 - x1)) - (float)((float)(x4 - x3) * (float)(y2 - y1));
    if ( COERCE_FLOAT(LODWORD(v21) & _xmm) < v20 )
    {
      v23 = (float)(v12 + x3) * 0.5;
      v24 = (float)(y2 + y3) * 0.5;
    }
    else
    {
      v22 = (float)((float)((float)(y1 - y3) * v17) - (float)((float)(x1 - x3) * v18.m128_f32[0])) / v21;
      v23 = (float)(v15 * v22) + x1;
      v24 = (float)(v16 * v22) + y1;
    }
    v25 = y1 + y2;
    v26 = (float)(y2 + y3) * 0.5;
    y3 = (float)(y3 + y4) * 0.5;
    v27 = (float)(x2a + x3) * 0.5;
    x3 = (float)(x3 + x4) * 0.5;
    v30 = (float)(x1 + x2a) * 0.5;
    x1a = (float)(v27 + v30) * 0.5;
    x2a = (float)(x3 + v27) * 0.5;
    y2a = (float)(y3 + v26) * 0.5;
    x3a = (float)(x2a + x1a) * 0.5;
    y3a = (float)(y2a + (float)((float)(v26 + (float)(v25 * 0.5)) * 0.5)) * 0.5;
    y1a = (float)(v26 + (float)(v25 * 0.5)) * 0.5;
    LODWORD(v28) = COERCE_UNSIGNED_INT(
                     Scaleform::Render::Math2D::LinePointDistance(
                       x1,
                       y1,
                       x4,
                       y4,
                       (float)((float)((float)(v23 + x1) * 0.5) + (float)((float)(v23 + x4) * 0.5)) * 0.5,
                       (float)((float)((float)(v24 + y1) * 0.5) + (float)((float)(v24 + y4) * 0.5)) * 0.5)) & _xmm;
    v29 = Scaleform::Render::Math2D::LinePointDistance(x1, y1, x4, y4, x3a, y3a);
    v12 = x2a;
    if ( (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v28 - COERCE_FLOAT(LODWORD(v29) & _xmm)) & _xmm)
               + COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                Scaleform::Render::Math2D::LinePointDistance(
                                  x1a,
                                  y1a,
                                  x2a,
                                  y2a,
                                  (float)((float)((float)(v23 + x1) * 0.5) + (float)((float)(v23 + x4) * 0.5)) * 0.5,
                                  (float)((float)((float)(v24 + y1) * 0.5) + (float)((float)(v24 + y4) * 0.5)) * 0.5)) & _xmm)) < v20 )
      break;
    Scaleform::Render::Math2D::SubdivideCubicToQuads<Scaleform::Render::Math2D::QuadCurvePath>(
      x1,
      y1,
      v30,
      v25 * 0.5,
      x1a,
      y1a,
      x3a,
      y3a,
      path);
    x1 = (float)(x2a + x1a) * 0.5;
    y2 = y2a;
    y1 = y3a;
  }
  val.ax = x4;
  val.cx = v23;
  val.ay = y4;
  val.cy = v24;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Math2D::QuadCoord,32,2>::PushBack(&path->Quads, &val);
}

// File Line: 209
// RVA: 0x934FD0
void __fastcall Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(
        Scaleform::Render::Math2D::CubicCurveCoord *c,
        float t,
        Scaleform::Render::Math2D::CubicCurveCoord *c1,
        Scaleform::Render::Math2D::CubicCurveCoord *c2)
{
  float x2; // xmm2_4
  float y4; // xmm9_4
  float x4; // xmm11_4
  float v7; // xmm12_4
  float v8; // xmm15_4
  float v9; // xmm7_4
  float v10; // xmm10_4
  float v11; // xmm6_4
  float v12; // xmm8_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float y1; // [rsp+B8h] [rbp+10h]

  x2 = c->x2;
  y4 = c->y4;
  x4 = c->x4;
  y1 = c->y1;
  v7 = (float)((float)(c->y2 - y1) * t) + y1;
  v8 = (float)((float)(x2 - c->x1) * t) + c->x1;
  v9 = (float)((float)(c->x3 - x2) * t) + x2;
  v10 = (float)((float)(x4 - c->x3) * t) + c->x3;
  v11 = (float)((float)(c->y3 - c->y2) * t) + c->y2;
  v12 = (float)((float)(y4 - c->y3) * t) + c->y3;
  c1->x1 = c->x1;
  c1->x2 = v8;
  c1->y2 = v7;
  v13 = (float)((float)(v12 - v11) * t) + v11;
  c1->y1 = y1;
  v14 = (float)((float)(v11 - v7) * t) + v7;
  c1->y3 = v14;
  v15 = (float)((float)(v9 - v8) * t) + v8;
  v16 = (float)((float)(v10 - v9) * t) + v9;
  c1->x3 = v15;
  v17 = (float)((float)(v13 - v14) * t) + v14;
  v18 = (float)((float)(v16 - v15) * t) + v15;
  c1->y4 = v17;
  c1->x4 = v18;
  c2->x1 = v18;
  c2->y1 = v17;
  c2->x2 = v16;
  c2->y2 = v13;
  c2->x3 = v10;
  c2->y3 = v12;
  c2->x4 = x4;
  c2->y4 = y4;
}

// File Line: 251
// RVA: 0x92B340
void __fastcall Scaleform::Render::Math2D::CubicToQuadratic<Scaleform::Render::Math2D::QuadCurvePath>(
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4,
        Scaleform::Render::Math2D::QuadCurvePath *path)
{
  float v9; // xmm7_4
  float v11; // xmm10_4
  float v12; // xmm8_4
  float v14; // xmm9_4
  float v15; // xmm6_4
  float v16; // xmm11_4
  float v17; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm6_4
  int v21; // eax
  unsigned int v22; // ecx
  int v23; // edx
  int v24; // edx
  int v25; // edx
  int v26; // edx
  float v27; // xmm0_4
  float *p_x4; // rbx
  __int64 v29; // rdi
  Scaleform::Render::Math2D::CubicCurveCoord c; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::Render::Math2D::CubicCurveCoord c1; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Render::Math2D::CubicCurveCoord c2; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::Render::Math2D::CubicCurveCoord v33; // [rsp+B0h] [rbp-50h] BYREF
  float v34; // [rsp+198h] [rbp+98h]

  v9 = FLOAT_N1_0;
  v11 = (float)((float)((float)(x2 * 3.0) - x1) - (float)(x3 * 3.0)) + x4;
  v12 = (float)(x2 * 3.0) - (float)(x1 * 3.0);
  v14 = (float)(y2 * 3.0) - (float)(y1 * 3.0);
  v34 = (float)((float)(x1 * 3.0) - (float)(x2 * 6.0)) + (float)(x3 * 3.0);
  v15 = FLOAT_N1_0;
  v16 = (float)((float)((float)(y2 * 3.0) - y1) - (float)(y3 * 3.0)) + y4;
  v17 = (float)((float)(y1 * 3.0) - (float)(y2 * 6.0)) + (float)(y3 * 3.0);
  v18 = (float)(v34 * v16) - (float)(v17 * v11);
  if ( v18 != 0.0 )
  {
    v19 = (float)((float)((float)(v12 * v16) - (float)(v14 * v11)) * -0.5) / v18;
    v20 = fsqrt((float)(v19 * v19) - (float)((float)((float)(v12 * v17) - (float)(v14 * v34)) / (float)(v18 * 3.0)));
    v9 = v19 - v20;
    v15 = v20 + v19;
  }
  v21 = 0;
  v22 = 1;
  c.x1 = x1;
  c.x3 = x3;
  c.y1 = y1;
  c.y3 = y3;
  c.x2 = x2;
  c.x4 = x4;
  c.y2 = y2;
  c.y4 = y4;
  if ( v15 <= 0.0 || (v23 = 1, v15 >= 1.0) )
    v23 = 0;
  if ( v9 > 0.0 && v9 < 1.0 )
    v21 = 1;
  v24 = v21 + 2 * v23;
  if ( v24 )
  {
    v25 = v24 - 1;
    if ( v25 )
    {
      v26 = v25 - 1;
      if ( v26 )
      {
        if ( v26 == 1 )
        {
          if ( v15 < v9 )
          {
            v27 = v9;
            v9 = v15;
            v15 = v27;
          }
          Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(&c, v9, &c1, &c2);
          Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(
            &c2,
            (float)(v15 - v9) / (float)(1.0 - v9),
            &c2,
            &v33);
          v22 = 3;
        }
      }
      else
      {
        Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(&c, v15, &c1, &c2);
        v22 = 2;
      }
    }
    else
    {
      Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(&c, v9, &c1, &c2);
      v22 = 2;
    }
  }
  else
  {
    c1 = c;
  }
  p_x4 = &c1.x4;
  v29 = v22;
  do
  {
    Scaleform::Render::Math2D::SubdivideCubicToQuads<Scaleform::Render::Math2D::QuadCurvePath>(
      *(p_x4 - 6),
      *(p_x4 - 5),
      *(p_x4 - 4),
      *(p_x4 - 3),
      *(p_x4 - 2),
      *(p_x4 - 1),
      *p_x4,
      p_x4[1],
      path);
    p_x4 += 8;
    --v29;
  }
  while ( v29 );
}

// File Line: 347
// RVA: 0x95EA80
__int64 __fastcall Scaleform::Render::Math2D::CheckQuadraticIntersection(
        unsigned int styleCount,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x,
        float y)
{
  float v10; // xmm2_4
  float v12; // xmm5_4
  float v13; // xmm0_4
  float v14; // xmm6_4

  v10 = y3;
  v12 = x1;
  if ( y1 <= y3 )
  {
    v14 = x3;
  }
  else
  {
    v12 = x3;
    v13 = y1;
    y1 = y3;
    v10 = v13;
    v14 = x1;
  }
  if ( Scaleform::Render::Math2D::CheckQuadIntersection(v12, y1, x2, y2, v14, v10, x, y) )
    styleCount ^= 1u;
  return styleCount;
}

// File Line: 364
// RVA: 0x95E2B0
__int64 __fastcall Scaleform::Render::Math2D::CheckCubicIntersection(
        unsigned int styleCount,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4,
        float x,
        float y)
{
  float v11; // xmm6_4
  float v12; // xmm7_4
  float *p_ax; // rdi
  __int64 Size_low; // rsi
  float v16; // xmm8_4
  float v17; // xmm1_4
  float v18; // xmm9_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  Scaleform::Render::Math2D::QuadCurvePath path; // [rsp+60h] [rbp-288h] BYREF

  v11 = y1;
  v12 = x1;
  path.Quads.pHeap = Scaleform::Memory::pGlobalHeap;
  path.Quads.Size = 0i64;
  path.Quads.Reserved = 32i64;
  path.Quads.Data = path.Quads.Static;
  Scaleform::Render::Math2D::CubicToQuadratic<Scaleform::Render::Math2D::QuadCurvePath>(
    x1,
    y1,
    x2,
    y2,
    x3,
    y3,
    x4,
    y4,
    &path);
  if ( LODWORD(path.Quads.Size) )
  {
    p_ax = &path.Quads.Data->ax;
    Size_low = LODWORD(path.Quads.Size);
    do
    {
      v16 = p_ax[1];
      v17 = v16;
      v18 = *p_ax;
      v19 = *p_ax;
      v20 = v11;
      v21 = v12;
      if ( v11 > v16 )
      {
        v21 = *p_ax;
        v19 = v12;
        v20 = p_ax[1];
        v17 = v11;
      }
      if ( Scaleform::Render::Math2D::CheckQuadIntersection(v21, v20, *(p_ax - 2), *(p_ax - 1), v19, v17, x, y) )
        styleCount ^= 1u;
      v12 = v18;
      v11 = v16;
      p_ax += 4;
      --Size_low;
    }
    while ( Size_low );
  }
  if ( path.Quads.Data != path.Quads.Static )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return styleCount;
}

// File Line: 387
// RVA: 0x991C10
char __fastcall Scaleform::Render::HitTestRoundStroke(Scaleform::Render::VertexPath *path, float w, float x, float y)
{
  unsigned __int64 Size; // r12
  unsigned int v5; // ebp
  unsigned int v7; // r14d
  float v8; // xmm14_4
  Scaleform::Render::PathBasic **Pages; // rcx
  unsigned __int64 v10; // rdx
  unsigned __int64 v11; // rax
  __int64 v12; // rdx
  unsigned int v13; // ebx
  Scaleform::Render::PathBasic *v14; // rcx
  unsigned int Count; // esi
  Scaleform::Render::VertexBasic **v16; // r15
  unsigned int v17; // edi
  __int64 v18; // rdx
  Scaleform::Render::VertexBasic *v19; // r8
  __int64 v20; // r9
  float v21; // xmm12_4
  float v22; // xmm13_4
  Scaleform::Render::VertexBasic *v23; // rcx
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm11_4
  unsigned __int64 v28; // r8
  float v29; // xmm14_4
  unsigned __int64 v30; // rdx
  unsigned __int64 v31; // rax
  __int64 v32; // rdx
  Scaleform::Render::VertexBasic *v33; // rcx
  float v34; // xmm0_4

  Size = path->Paths.Size;
  v5 = 0;
  v7 = 0;
  v8 = w * 0.5;
  if ( Size )
  {
    Pages = path->Paths.Pages;
    v10 = 0i64;
    while ( 1 )
    {
      v11 = v10;
      v12 = v10 & 3;
      v13 = 1;
      v14 = Pages[v11 >> 2];
      Count = v14[v12].Count;
      if ( Count > 1 )
        break;
LABEL_9:
      v10 = ++v7;
      if ( v7 >= Size )
        goto LABEL_12;
      Pages = path->Paths.Pages;
    }
    v16 = path->Vertices.Pages;
    v17 = v14[v12].Start + 1;
    while ( 1 )
    {
      v18 = v17 & 0xF;
      v19 = v16[(unsigned __int64)(v17 - 1) >> 4];
      v20 = ((_BYTE)v17 - 1) & 0xF;
      v21 = v19[v20].x;
      v22 = v19[v20].y;
      v23 = v16[(unsigned __int64)v17 >> 4];
      v24 = v23[v18].x - v21;
      v25 = v23[v18].y - v22;
      if ( (float)((float)((float)((float)(v22 + v24) - v22) * (float)(x - (float)(v21 - v25)))
                 - (float)((float)((float)(v21 - v25) - v21) * (float)(y - (float)(v22 + v24)))) >= 0.0 )
      {
        v26 = v23[v18].y + v24;
        if ( (float)((float)((float)(v26 - v23[v18].y) * (float)(x - (float)(v23[v18].x - v25)))
                   - (float)((float)((float)(v23[v18].x - v25) - v23[v18].x) * (float)(y - v26))) <= 0.0
          && COERCE_FLOAT(COERCE_UNSIGNED_INT(Scaleform::Render::Math2D::LinePointDistance(v21, v19[v20].y, v23[v18].x, v23[v18].y, x, y)) & _xmm) <= v8 )
        {
          return 1;
        }
      }
      ++v13;
      ++v17;
      if ( v13 >= Count )
        goto LABEL_9;
    }
  }
LABEL_12:
  v28 = path->Vertices.Size;
  v29 = v8 * v8;
  if ( v28 )
  {
    v30 = 0i64;
    while ( 1 )
    {
      v31 = v30;
      v32 = v30 & 0xF;
      v33 = path->Vertices.Pages[v31 >> 4];
      v34 = y - v33[v32].y;
      if ( (float)((float)(v34 * v34) + (float)((float)(x - v33[v32].x) * (float)(x - v33[v32].x))) <= v29 )
        break;
      v30 = ++v5;
      if ( v5 >= v28 )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 426
// RVA: 0x9917E0
bool __fastcall Scaleform::Render::HitTestGeneralStroke(Scaleform::Render::VertexPath *path, float x, float y)
{
  unsigned __int64 Size; // rbx
  int v5; // r8d
  unsigned int v6; // r12d
  Scaleform::Render::PathBasic **Pages; // rcx
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // rax
  __int64 v10; // rdi
  unsigned int v11; // r14d
  Scaleform::Render::PathBasic *v12; // r15
  unsigned int Count; // esi
  Scaleform::Render::VertexBasic **v14; // r11
  unsigned int v15; // r10d
  unsigned int v16; // eax
  __int64 v17; // rbx
  float v18; // xmm0_4
  float v19; // xmm4_4
  int v20; // edx
  Scaleform::Render::VertexBasic v21; // rcx
  float v22; // xmm0_4
  float v23; // xmm4_4
  int v24; // edx
  Scaleform::Render::VertexBasic v25; // rcx
  float v26; // xmm0_4
  float v27; // xmm4_4
  int v28; // edx
  Scaleform::Render::VertexBasic v29; // rcx
  float v30; // xmm4_4
  float v31; // xmm0_4
  int v32; // edx
  Scaleform::Render::VertexBasic **v33; // r11
  unsigned int v34; // r9d
  __int64 v35; // r10
  Scaleform::Render::VertexBasic v36; // rax
  float v37; // xmm0_4
  float v38; // xmm4_4
  int v39; // edx
  Scaleform::Render::VertexBasic v41; // [rsp+50h] [rbp+28h]
  Scaleform::Render::VertexBasic v42; // [rsp+50h] [rbp+28h]
  Scaleform::Render::VertexBasic v43; // [rsp+50h] [rbp+28h]
  Scaleform::Render::VertexBasic v44; // [rsp+50h] [rbp+28h]
  Scaleform::Render::VertexBasic v45; // [rsp+50h] [rbp+28h]
  Scaleform::Render::VertexBasic v46; // [rsp+68h] [rbp+40h]
  Scaleform::Render::VertexBasic v47; // [rsp+68h] [rbp+40h]
  Scaleform::Render::VertexBasic v48; // [rsp+68h] [rbp+40h]
  Scaleform::Render::VertexBasic v49; // [rsp+68h] [rbp+40h]
  Scaleform::Render::VertexBasic v50; // [rsp+68h] [rbp+40h]

  Size = path->Paths.Size;
  v5 = 0;
  v6 = 0;
  if ( Size )
  {
    Pages = path->Paths.Pages;
    v8 = 0i64;
    do
    {
      v9 = v8;
      v10 = v8 & 3;
      v11 = 1;
      v12 = Pages[v9 >> 2];
      Count = v12[v10].Count;
      if ( Count > 1 )
      {
        if ( (int)(Count - 1) >= 4 )
        {
          v14 = path->Vertices.Pages;
          v15 = v12[v10].Start + 1;
          v16 = ((Count - 5) >> 2) + 1;
          v17 = v16;
          v11 = 4 * v16 + 1;
          do
          {
            v46 = v14[(unsigned __int64)(v15 - 1) >> 4][((_BYTE)v15 - 1) & 0xF];
            v18 = v46.y;
            v41 = v14[(unsigned __int64)v15 >> 4][v15 & 0xF];
            v19 = v41.y;
            if ( v46.y != v41.y )
            {
              v20 = 1;
              if ( v46.y > v41.y )
              {
                v46 = v14[(unsigned __int64)v15 >> 4][v15 & 0xF];
                v18 = v46.y;
                v41 = v14[(unsigned __int64)(v15 - 1) >> 4][((_BYTE)v15 - 1) & 0xF];
                v19 = v41.y;
                v20 = -1;
              }
              if ( y >= v18
                && y < v19
                && (float)((float)((float)(v19 - v18) * (float)(x - v41.x))
                         - (float)((float)(v41.x - v46.x) * (float)(y - v19))) > 0.0 )
              {
                v5 += v20;
              }
            }
            v21 = v14[(unsigned __int64)v15 >> 4][v15 & 0xF];
            v22 = v21.y;
            v47.x = v21.x;
            v42 = v14[(unsigned __int64)(v15 + 1) >> 4][((_BYTE)v15 + 1) & 0xF];
            v23 = v42.y;
            if ( v21.y != v42.y )
            {
              v24 = 1;
              if ( v21.y > v42.y )
              {
                v47 = v14[(unsigned __int64)(v15 + 1) >> 4][((_BYTE)v15 + 1) & 0xF];
                v22 = v47.y;
                v42 = v14[(unsigned __int64)v15 >> 4][v15 & 0xF];
                v23 = v21.y;
                v24 = -1;
              }
              if ( y >= v22
                && y < v23
                && (float)((float)((float)(v23 - v22) * (float)(x - v42.x))
                         - (float)((float)(v42.x - v47.x) * (float)(y - v23))) > 0.0 )
              {
                v5 += v24;
              }
            }
            v25 = v14[(unsigned __int64)(v15 + 1) >> 4][(v15 + 1) & 0xF];
            v26 = v25.y;
            v48.x = v25.x;
            v43 = v14[(unsigned __int64)(v15 + 2) >> 4][((_BYTE)v15 + 2) & 0xF];
            v27 = v43.y;
            if ( v25.y != v43.y )
            {
              v28 = 1;
              if ( v25.y > v43.y )
              {
                v48 = v14[(unsigned __int64)(v15 + 2) >> 4][((_BYTE)v15 + 2) & 0xF];
                v26 = v48.y;
                v43 = v14[(unsigned __int64)(v15 + 1) >> 4][(v15 + 1) & 0xF];
                v27 = v25.y;
                v28 = -1;
              }
              if ( y >= v26
                && y < v27
                && (float)((float)((float)(v27 - v26) * (float)(x - v43.x))
                         - (float)((float)(v43.x - v48.x) * (float)(y - v27))) > 0.0 )
              {
                v5 += v28;
              }
            }
            v29 = v14[(unsigned __int64)(v15 + 2) >> 4][((_BYTE)v15 + 2) & 0xF];
            v44 = v14[(unsigned __int64)(v15 + 3) >> 4][((_BYTE)v15 + 3) & 0xF];
            v49.x = v29.x;
            v30 = v44.y;
            v31 = v29.y;
            if ( v29.y != v44.y )
            {
              v32 = 1;
              if ( v29.y > v44.y )
              {
                v49 = v14[(unsigned __int64)(v15 + 3) >> 4][((_BYTE)v15 + 3) & 0xF];
                v31 = v49.y;
                v44 = v14[(unsigned __int64)(v15 + 2) >> 4][((_BYTE)v15 + 2) & 0xF];
                v30 = v29.y;
                v32 = -1;
              }
              if ( y >= v31
                && y < v30
                && (float)((float)((float)(v30 - v31) * (float)(x - v44.x))
                         - (float)((float)(v44.x - v49.x) * (float)(y - v30))) > 0.0 )
              {
                v5 += v32;
              }
            }
            v15 += 4;
            --v17;
          }
          while ( v17 );
          Size = path->Paths.Size;
        }
        if ( v11 < Count )
        {
          v33 = path->Vertices.Pages;
          v34 = v11 + v12[v10].Start;
          v35 = Count - v11;
          do
          {
            v50 = v33[(unsigned __int64)(v34 - 1) >> 4][((_BYTE)v34 - 1) & 0xF];
            v36 = v33[(unsigned __int64)v34 >> 4][v34 & 0xF];
            v37 = v50.y;
            v45.x = v36.x;
            v38 = v36.y;
            if ( v50.y != v36.y )
            {
              v39 = 1;
              if ( v50.y > v36.y )
              {
                v50 = v33[(unsigned __int64)v34 >> 4][v34 & 0xF];
                v37 = v36.y;
                v45 = v33[(unsigned __int64)(v34 - 1) >> 4][((_BYTE)v34 - 1) & 0xF];
                v38 = v45.y;
                v39 = -1;
              }
              if ( y >= v37
                && y < v38
                && (float)((float)((float)(v38 - v37) * (float)(x - v45.x))
                         - (float)((float)(v45.x - v50.x) * (float)(y - v38))) > 0.0 )
              {
                v5 += v39;
              }
            }
            ++v34;
            --v35;
          }
          while ( v35 );
        }
      }
      Pages = path->Paths.Pages;
      v8 = ++v6;
    }
    while ( v6 < Size );
  }
  return v5 != 0;
}

