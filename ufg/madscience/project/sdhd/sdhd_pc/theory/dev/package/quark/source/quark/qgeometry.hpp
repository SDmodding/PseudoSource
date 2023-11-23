// File Line: 447
// RVA: 0x3D980
float __fastcall UFG::qDistanceRayPoint(UFG::qVector3 *ray_pos, UFG::qVector3 *ray_dir, UFG::qVector3 *pos)
{
  __m128 y_low; // xmm3
  float y; // xmm8_4
  float x; // xmm7_4
  float v6; // xmm11_4
  float v7; // xmm10_4
  float z; // xmm9_4
  float v9; // xmm12_4
  float v10; // xmm6_4
  float v11; // xmm6_4
  float result; // xmm0_4

  y_low = (__m128)LODWORD(pos->y);
  y = ray_pos->y;
  x = ray_pos->x;
  v6 = ray_dir->y;
  v7 = ray_dir->x;
  z = ray_pos->z;
  v9 = ray_dir->z;
  v10 = (float)((float)((float)(pos->x * v7) + (float)(pos->y * v6)) + (float)(pos->z * v9))
      - (float)((float)((float)(ray_pos->x * v7) + (float)(y * v6)) + (float)(z * v9));
  if ( v10 >= 0.0 )
  {
    v11 = v10 / (float)((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v9 * v9));
    x = x + (float)(v7 * v11);
    y = y + (float)(v6 * v11);
    z = z + (float)(v9 * v11);
  }
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                            + (float)((float)(pos->x - x) * (float)(pos->x - x)))
                    + (float)((float)(pos->z - z) * (float)(pos->z - z));
  LODWORD(result) = _mm_sqrt_ps(y_low).m128_u32[0];
  return result;
}

// File Line: 476
// RVA: 0x246A00
float __fastcall UFG::qDistanceSqrRayPoint(UFG::qVector3 *ray_pos, UFG::qVector3 *ray_dir, UFG::qVector3 *pos)
{
  float y; // xmm4_4
  float x; // xmm3_4
  float z; // xmm5_4
  float v6; // xmm8_4
  float v7; // xmm7_4
  float v8; // xmm11_4
  float v9; // xmm10_4
  float v10; // xmm9_4
  float v11; // xmm12_4
  float v12; // xmm6_4
  float v14; // xmm6_4

  y = pos->y;
  x = pos->x;
  z = pos->z;
  v6 = ray_pos->y;
  v7 = ray_pos->x;
  v8 = ray_dir->y;
  v9 = ray_dir->x;
  v10 = ray_pos->z;
  v11 = ray_dir->z;
  v12 = (float)((float)((float)(pos->x * v9) + (float)(y * v8)) + (float)(z * v11))
      - (float)((float)((float)(ray_pos->x * v9) + (float)(v6 * v8)) + (float)(v10 * v11));
  if ( v12 < 0.0 )
    return (float)((float)((float)(x - v7) * (float)(x - v7)) + (float)((float)(y - v6) * (float)(y - v6)))
         + (float)((float)(z - v10) * (float)(z - v10));
  v14 = v12 / (float)((float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v11 * v11));
  return (float)((float)((float)(y - (float)(v6 + (float)(v8 * v14))) * (float)(y - (float)(v6 + (float)(v8 * v14))))
               + (float)((float)(x - (float)(v7 + (float)(v9 * v14))) * (float)(x - (float)(v7 + (float)(v9 * v14)))))
       + (float)((float)(z - (float)(v10 + (float)(v11 * v14))) * (float)(z - (float)(v10 + (float)(v11 * v14))));
}

// File Line: 662
// RVA: 0x185F90
char __fastcall UFG::qIntersectSegSeg2D(
        UFG::qVector2 *starta,
        UFG::qVector2 *enda,
        UFG::qVector2 *startb,
        UFG::qVector2 *endb,
        float *pdista_p,
        UFG::qVector2 *hit_pos_p)
{
  float y; // xmm5_4
  float v7; // xmm6_4
  float x; // xmm7_4
  float v9; // xmm4_4
  float v10; // xmm8_4
  float v11; // xmm9_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm4_4
  float v16; // xmm2_4

  y = startb->y;
  v7 = endb->y;
  x = endb->x;
  v9 = startb->x;
  v10 = (float)((float)(starta->x - x) * (float)(enda->y - v7))
      - (float)((float)(enda->x - x) * (float)(starta->y - v7));
  v11 = (float)((float)(starta->x - v9) * (float)(enda->y - y))
      - (float)((float)(enda->x - v9) * (float)(starta->y - y));
  if ( (float)(v11 * v10) >= 0.0 )
    return 0;
  v13 = (float)((float)(v9 - starta->x) * (float)(v7 - starta->y))
      - (float)((float)(y - starta->y) * (float)(x - starta->x));
  v14 = (float)(v13 + v11) - v10;
  if ( (float)(v14 * v13) >= 0.0 )
    return 0;
  if ( pdista_p || hit_pos_p )
  {
    v15 = v13 / (float)(v13 - v14);
    if ( pdista_p )
      *pdista_p = v15;
    if ( hit_pos_p )
    {
      v16 = (float)((float)(enda->y - starta->y) * v15) + starta->y;
      hit_pos_p->x = (float)((float)(enda->x - starta->x) * v15) + starta->x;
      hit_pos_p->y = v16;
    }
  }
  return 1;
}

// File Line: 729
// RVA: 0x246C90
UFG::qVector3 *__fastcall UFG::qNearestSegPoint(
        UFG::qVector3 *result,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qVector3 *pos)
{
  float x; // xmm8_4
  float y; // xmm9_4
  float z; // xmm10_4
  float v7; // xmm12_4
  float v8; // xmm4_4
  float v9; // xmm13_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm3_4
  UFG::qVector3 *v14; // rax
  float v15; // xmm3_4

  x = start->x;
  y = start->y;
  z = start->z;
  v7 = end->y;
  v8 = end->x - start->x;
  v9 = end->z;
  v10 = v7 - y;
  v11 = v9 - z;
  v12 = (float)((float)(v10 * v10) + (float)(v8 * v8)) + (float)(v11 * v11);
  if ( v12 <= 0.00000011920929
    || (v13 = (float)((float)((float)(v10 * pos->y) + (float)(v8 * pos->x)) + (float)(v11 * pos->z))
            - (float)((float)((float)(y * v10) + (float)(x * v8)) + (float)(z * v11)),
        v13 < 0.0)
    || v12 <= 0.00000011920929 )
  {
    result->z = z;
    result->y = y;
    result->x = x;
    return result;
  }
  else
  {
    v14 = result;
    if ( v13 <= v12 )
    {
      v15 = v13 / v12;
      result->x = (float)(v8 * v15) + x;
      result->y = (float)(v10 * v15) + y;
      result->z = (float)(v11 * v15) + z;
    }
    else
    {
      result->x = end->x;
      result->y = v7;
      result->z = v9;
    }
  }
  return v14;
}

// File Line: 1041
// RVA: 0x16BF0
char __fastcall UFG::qIntersectDirLinePlane(
        UFG::qVector3 *line_pos,
        UFG::qVector3 *line_dir,
        UFG::qVector3 *plane_normal,
        float plane_dist,
        UFG::qVector3 *hit_pos_p)
{
  float y; // xmm9_4
  float z; // xmm10_4
  float v7; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm5_4
  float v11; // xmm4_4

  y = line_dir->y;
  z = line_dir->z;
  v7 = (float)((float)(plane_normal->x * line_dir->x) + (float)(plane_normal->y * y)) + (float)(plane_normal->z * z);
  if ( v7 == 0.0 )
    return 0;
  if ( hit_pos_p )
  {
    v9 = (float)(plane_dist
               - (float)((float)((float)(line_pos->x * plane_normal->x) + (float)(line_pos->y * plane_normal->y))
                       + (float)(line_pos->z * plane_normal->z)))
       / v7;
    v10 = line_pos->y + (float)(y * v9);
    v11 = line_pos->z + (float)(z * v9);
    hit_pos_p->x = line_pos->x + (float)(line_dir->x * v9);
    hit_pos_p->y = v10;
    hit_pos_p->z = v11;
  }
  return 1;
}

// File Line: 1067
// RVA: 0x16CF0
char __fastcall UFG::qIntersectDirLinePlane(
        UFG::qVector3 *line_pos,
        UFG::qVector3 *line_dir,
        UFG::qVector4 *plane,
        UFG::qVector3 *hit_pos_p)
{
  float y; // xmm1_4
  int v5; // xmm3_4
  float z; // xmm0_4
  UFG::qVector3 plane_normal; // [rsp+30h] [rbp-18h] BYREF

  y = plane->y;
  v5 = LODWORD(plane->w) ^ _xmm[0];
  plane_normal.x = plane->x;
  z = plane->z;
  plane_normal.y = y;
  plane_normal.z = z;
  return UFG::qIntersectDirLinePlane(line_pos, line_dir, &plane_normal, *(float *)&v5, hit_pos_p);
}

// File Line: 1089
// RVA: 0x1853C0
char __fastcall UFG::qIntersectRayPlane(
        UFG::qVector3 *ray_pos,
        UFG::qVector3 *ray_dir,
        UFG::qVector3 *plane_normal,
        UFG::qVector3 *plane_pos,
        UFG::qVector3 *hit_pos_p)
{
  float y; // xmm6_4
  float z; // xmm7_4
  float v7; // xmm4_4
  float v9; // xmm9_4
  float v10; // xmm10_4
  float v11; // xmm3_4

  y = ray_dir->y;
  z = ray_dir->z;
  v7 = (float)((float)(plane_normal->x * ray_dir->x) + (float)(plane_normal->y * y)) + (float)(plane_normal->z * z);
  if ( v7 == 0.0 )
    return 0;
  v9 = ray_pos->y;
  v10 = ray_pos->z;
  v11 = (float)((float)((float)(plane_normal->x * (float)(plane_pos->x - ray_pos->x))
                      + (float)(plane_normal->y * (float)(plane_pos->y - v9)))
              + (float)(plane_normal->z * (float)(plane_pos->z - v10)))
      / v7;
  if ( v11 < 0.0 )
    return 0;
  if ( hit_pos_p )
  {
    hit_pos_p->x = ray_pos->x + (float)(ray_dir->x * v11);
    hit_pos_p->y = v9 + (float)(y * v11);
    hit_pos_p->z = v10 + (float)(z * v11);
  }
  return 1;
}

// File Line: 1134
// RVA: 0x246B70
char __fastcall UFG::qIntersectRayPlane(
        UFG::qVector3 *ray_pos,
        UFG::qVector3 *ray_dir,
        UFG::qVector3 *plane_normal,
        float plane_dist,
        UFG::qVector3 *hit_pos_p)
{
  float y; // xmm9_4
  float z; // xmm10_4
  float v7; // xmm4_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm3_4

  y = ray_dir->y;
  z = ray_dir->z;
  v7 = (float)((float)(plane_normal->x * ray_dir->x) + (float)(plane_normal->y * y)) + (float)(plane_normal->z * z);
  if ( v7 == 0.0 )
    return 0;
  v9 = ray_pos->y;
  v10 = ray_pos->z;
  v11 = (float)(plane_dist
              - (float)((float)((float)(ray_pos->x * plane_normal->x) + (float)(v9 * plane_normal->y))
                      + (float)(v10 * plane_normal->z)))
      / v7;
  if ( v11 < 0.0 )
    return 0;
  if ( hit_pos_p )
  {
    hit_pos_p->x = ray_pos->x + (float)(ray_dir->x * v11);
    hit_pos_p->y = v9 + (float)(y * v11);
    hit_pos_p->z = v10 + (float)(z * v11);
  }
  return 1;
}

// File Line: 1386
// RVA: 0x187430
bool __fastcall UFG::qIsBoundPointQuad(
        UFG::qVector3 *pos,
        UFG::qVector3 *quad1,
        UFG::qVector3 *quad2,
        UFG::qVector3 *quad3,
        UFG::qVector3 *quad4)
{
  float y; // xmm5_4
  float z; // xmm8_4
  float v7; // xmm12_4
  float v8; // xmm10_4
  float x; // xmm11_4
  float v10; // xmm14_4
  float v11; // xmm7_4
  float v12; // xmm4_4
  float v13; // xmm15_4
  float v15; // xmm9_4
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm8_4
  float v19; // [rsp+B0h] [rbp+8h]
  float v20; // [rsp+B8h] [rbp+10h]
  float v21; // [rsp+C0h] [rbp+18h]

  y = quad2->y;
  z = quad2->z;
  v7 = pos->y;
  v8 = pos->z;
  x = pos->x;
  v10 = quad1->y;
  v11 = pos->x - quad1->x;
  v12 = quad2->x - quad1->x;
  v13 = quad1->z;
  v21 = (float)(v11 * (float)(y - v10)) - (float)((float)(v7 - v10) * v12);
  v20 = (float)((float)(v8 - v13) * v12) - (float)(v11 * (float)(z - v13));
  v19 = (float)((float)(v7 - v10) * (float)(z - v13)) - (float)((float)(v8 - v13) * (float)(y - v10));
  if ( (float)((float)((float)((float)((float)((float)(v8 - z) * (float)(quad3->x - quad2->x))
                                     - (float)((float)(x - quad2->x) * (float)(quad3->z - z)))
                             * v20)
                     + (float)((float)((float)((float)(v7 - y) * (float)(quad3->z - z))
                                     - (float)((float)(v8 - z) * (float)(quad3->y - y)))
                             * v19))
             + (float)((float)((float)((float)(x - quad2->x) * (float)(quad3->y - y))
                             - (float)((float)(v7 - y) * (float)(quad3->x - quad2->x)))
                     * v21)) < 0.0 )
    return 0;
  v16 = quad4->y - quad3->y;
  v17 = quad4->z - quad3->z;
  if ( (float)((float)((float)((float)((float)((float)(v8 - quad3->z) * (float)(quad4->x - quad3->x))
                                     - (float)((float)(x - quad3->x) * v17))
                             * v20)
                     + (float)((float)((float)((float)(v7 - quad3->y) * v17) - (float)((float)(v8 - quad3->z) * v16))
                             * v19))
             + (float)((float)((float)((float)(x - quad3->x) * v16)
                             - (float)((float)(v7 - quad3->y) * (float)(quad4->x - quad3->x)))
                     * v21)) < 0.0 )
    return 0;
  v18 = quad4->x;
  v15 = quad4->y;
  return (float)((float)((float)((float)((float)((float)(v8 - quad4->z) * (float)(quad1->x - v18))
                                       - (float)((float)(x - v18) * (float)(v13 - quad4->z)))
                               * v20)
                       + (float)((float)((float)((float)(v7 - v15) * (float)(v13 - quad4->z))
                                       - (float)((float)(v8 - quad4->z) * (float)(v10 - v15)))
                               * v19))
               + (float)((float)((float)((float)(x - v18) * (float)(v10 - v15))
                               - (float)((float)(v7 - v15) * (float)(quad1->x - v18)))
                       * v21)) >= 0.0;
}

