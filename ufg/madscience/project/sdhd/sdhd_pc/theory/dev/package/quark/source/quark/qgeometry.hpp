// File Line: 447
// RVA: 0x3D980
float __fastcall UFG::qDistanceRayPoint(UFG::qVector3 *ray_pos, UFG::qVector3 *ray_dir, UFG::qVector3 *pos)
{
  __m128 v3; // xmm3
  float v4; // xmm8_4
  float v5; // xmm7_4
  float v6; // xmm11_4
  float v7; // xmm10_4
  float v8; // xmm9_4
  float v9; // xmm12_4
  float v10; // xmm6_4
  float v11; // xmm6_4
  float result; // xmm0_4

  v3 = (__m128)LODWORD(pos->y);
  v4 = ray_pos->y;
  v5 = ray_pos->x;
  v6 = ray_dir->y;
  v7 = ray_dir->x;
  v8 = ray_pos->z;
  v9 = ray_dir->z;
  v10 = (float)((float)((float)(pos->x * v7) + (float)(pos->y * v6)) + (float)(pos->z * v9))
      - (float)((float)((float)(ray_pos->x * v7) + (float)(ray_pos->y * v6)) + (float)(ray_pos->z * v9));
  if ( v10 >= 0.0 )
  {
    v11 = v10 / (float)((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v9 * v9));
    v5 = v5 + (float)(v7 * v11);
    v4 = v4 + (float)(v6 * v11);
    v8 = v8 + (float)(v9 * v11);
  }
  v3.m128_f32[0] = (float)((float)((float)(v3.m128_f32[0] - v4) * (float)(v3.m128_f32[0] - v4))
                         + (float)((float)(pos->x - v5) * (float)(pos->x - v5)))
                 + (float)((float)(pos->z - v8) * (float)(pos->z - v8));
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v3);
  return result;
}

// File Line: 476
// RVA: 0x246A00
float __fastcall UFG::qDistanceSqrRayPoint(UFG::qVector3 *ray_pos, UFG::qVector3 *ray_dir, UFG::qVector3 *pos)
{
  float v3; // xmm4_4
  float v4; // xmm3_4
  float v5; // xmm5_4
  float v6; // xmm8_4
  float v7; // xmm7_4
  float v8; // xmm11_4
  float v9; // xmm10_4
  float v10; // xmm9_4
  float v11; // xmm12_4
  float v12; // xmm6_4
  float v14; // xmm6_4

  v3 = pos->y;
  v4 = pos->x;
  v5 = pos->z;
  v6 = ray_pos->y;
  v7 = ray_pos->x;
  v8 = ray_dir->y;
  v9 = ray_dir->x;
  v10 = ray_pos->z;
  v11 = ray_dir->z;
  v12 = (float)((float)((float)(pos->x * v9) + (float)(pos->y * v8)) + (float)(pos->z * v11))
      - (float)((float)((float)(ray_pos->x * v9) + (float)(ray_pos->y * v8)) + (float)(ray_pos->z * v11));
  if ( v12 < 0.0 )
    return (float)((float)((float)(v4 - v7) * (float)(v4 - v7)) + (float)((float)(v3 - v6) * (float)(v3 - v6)))
         + (float)((float)(v5 - v10) * (float)(v5 - v10));
  v14 = v12 / (float)((float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v11 * v11));
  return (float)((float)((float)(v3 - (float)(v6 + (float)(v8 * v14))) * (float)(v3 - (float)(v6 + (float)(v8 * v14))))
               + (float)((float)(v4 - (float)(v7 + (float)(v9 * v14))) * (float)(v4 - (float)(v7 + (float)(v9 * v14)))))
       + (float)((float)(v5 - (float)(v10 + (float)(v11 * v14))) * (float)(v5 - (float)(v10 + (float)(v11 * v14))));
}

// File Line: 662
// RVA: 0x185F90
char __fastcall UFG::qIntersectSegSeg2D(UFG::qVector2 *starta, UFG::qVector2 *enda, UFG::qVector2 *startb, UFG::qVector2 *endb, float *pdista_p, UFG::qVector2 *hit_pos_p)
{
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm4_4
  float v10; // xmm8_4
  float v11; // xmm9_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm4_4
  float v16; // xmm2_4

  v6 = startb->y;
  v7 = endb->y;
  v8 = endb->x;
  v9 = startb->x;
  v10 = (float)((float)(starta->x - v8) * (float)(enda->y - v7))
      - (float)((float)(enda->x - v8) * (float)(starta->y - v7));
  v11 = (float)((float)(starta->x - v9) * (float)(enda->y - v6))
      - (float)((float)(enda->x - v9) * (float)(starta->y - v6));
  if ( (float)(v11 * v10) >= 0.0 )
    return 0;
  v13 = (float)((float)(v9 - starta->x) * (float)(v7 - starta->y))
      - (float)((float)(v6 - starta->y) * (float)(v8 - starta->x));
  v14 = (float)(v13 + v11) - v10;
  if ( (float)(v14 * v13) >= 0.0 )
    return 0;
  if ( __PAIR__((unsigned __int64)hit_pos_p, (unsigned __int64)pdista_p) != 0 )
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
UFG::qVector3 *__fastcall UFG::qNearestSegPoint(UFG::qVector3 *result, UFG::qVector3 *start, UFG::qVector3 *end, UFG::qVector3 *pos)
{
  float v4; // xmm8_4
  float v5; // xmm9_4
  float v6; // xmm10_4
  float v7; // xmm12_4
  float v8; // xmm4_4
  float v9; // xmm13_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm3_4
  UFG::qVector3 *v14; // rax
  float v15; // xmm3_4

  v4 = start->x;
  v5 = start->y;
  v6 = start->z;
  v7 = end->y;
  v8 = end->x - start->x;
  v9 = end->z;
  v10 = end->y - v5;
  v11 = end->z - v6;
  v12 = (float)((float)(v10 * v10) + (float)(v8 * v8)) + (float)(v11 * v11);
  if ( v12 <= 0.00000011920929
    || (v13 = (float)((float)((float)(v10 * pos->y) + (float)(v8 * pos->x)) + (float)(v11 * pos->z))
            - (float)((float)((float)(v5 * v10) + (float)(v4 * v8)) + (float)(v6 * v11)),
        v13 < 0.0)
    || v12 <= 0.00000011920929 )
  {
    result->z = v6;
    result->y = v5;
    result->x = v4;
    v14 = result;
  }
  else
  {
    v14 = result;
    if ( v13 <= v12 )
    {
      v15 = v13 / v12;
      result->x = (float)(v8 * v15) + v4;
      result->y = (float)(v10 * v15) + v5;
      result->z = (float)(v11 * v15) + v6;
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
char __fastcall UFG::qIntersectDirLinePlane(UFG::qVector3 *line_pos, UFG::qVector3 *line_dir, UFG::qVector3 *plane_normal, float plane_dist, UFG::qVector3 *hit_pos_p)
{
  float v5; // xmm9_4
  float v6; // xmm10_4
  float v7; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm5_4
  float v11; // xmm4_4

  v5 = line_dir->y;
  v6 = line_dir->z;
  v7 = (float)((float)(plane_normal->x * line_dir->x) + (float)(plane_normal->y * v5)) + (float)(plane_normal->z * v6);
  if ( v7 == 0.0 )
    return 0;
  if ( hit_pos_p )
  {
    v9 = (float)(plane_dist
               - (float)((float)((float)(line_pos->x * plane_normal->x) + (float)(line_pos->y * plane_normal->y))
                       + (float)(line_pos->z * plane_normal->z)))
       / v7;
    v10 = line_pos->y + (float)(v5 * v9);
    v11 = line_pos->z + (float)(v6 * v9);
    hit_pos_p->x = line_pos->x + (float)(line_dir->x * v9);
    hit_pos_p->y = v10;
    hit_pos_p->z = v11;
  }
  return 1;
}

// File Line: 1067
// RVA: 0x16CF0
char __fastcall UFG::qIntersectDirLinePlane(UFG::qVector3 *line_pos, UFG::qVector3 *line_dir, UFG::qVector4 *plane, UFG::qVector3 *hit_pos_p)
{
  float v4; // xmm1_4
  int v5; // xmm3_4
  float v6; // xmm0_4
  UFG::qVector3 plane_normal; // [rsp+30h] [rbp-18h]

  v4 = plane->y;
  v5 = LODWORD(plane->w) ^ _xmm[0];
  plane_normal.x = plane->x;
  v6 = plane->z;
  plane_normal.y = v4;
  plane_normal.z = v6;
  return UFG::qIntersectDirLinePlane(line_pos, line_dir, &plane_normal, *(float *)&v5, hit_pos_p);
}

// File Line: 1089
// RVA: 0x1853C0
char __fastcall UFG::qIntersectRayPlane(UFG::qVector3 *ray_pos, UFG::qVector3 *ray_dir, UFG::qVector3 *plane_normal, UFG::qVector3 *plane_pos, UFG::qVector3 *hit_pos_p)
{
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm4_4
  float v9; // xmm9_4
  float v10; // xmm10_4
  float v11; // xmm3_4

  v5 = ray_dir->y;
  v6 = ray_dir->z;
  v7 = (float)((float)(plane_normal->x * ray_dir->x) + (float)(plane_normal->y * v5)) + (float)(plane_normal->z * v6);
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
    hit_pos_p->y = v9 + (float)(v5 * v11);
    hit_pos_p->z = v10 + (float)(v6 * v11);
  }
  return 1;
}

// File Line: 1134
// RVA: 0x246B70
char __fastcall UFG::qIntersectRayPlane(UFG::qVector3 *ray_pos, UFG::qVector3 *ray_dir, UFG::qVector3 *plane_normal, float plane_dist, UFG::qVector3 *hit_pos_p)
{
  float v5; // xmm9_4
  float v6; // xmm10_4
  float v7; // xmm4_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm3_4

  v5 = ray_dir->y;
  v6 = ray_dir->z;
  v7 = (float)((float)(plane_normal->x * ray_dir->x) + (float)(plane_normal->y * v5)) + (float)(plane_normal->z * v6);
  if ( v7 == 0.0 )
    return 0;
  v9 = ray_pos->y;
  v10 = ray_pos->z;
  v11 = (float)(plane_dist
              - (float)((float)((float)(ray_pos->x * plane_normal->x) + (float)(v9 * plane_normal->y))
                      + (float)(ray_pos->z * plane_normal->z)))
      / v7;
  if ( v11 < 0.0 )
    return 0;
  if ( hit_pos_p )
  {
    hit_pos_p->x = ray_pos->x + (float)(ray_dir->x * v11);
    hit_pos_p->y = v9 + (float)(v5 * v11);
    hit_pos_p->z = v10 + (float)(v6 * v11);
  }
  return 1;
}

// File Line: 1386
// RVA: 0x187430
bool __fastcall UFG::qIsBoundPointQuad(UFG::qVector3 *pos, UFG::qVector3 *quad1, UFG::qVector3 *quad2, UFG::qVector3 *quad3, UFG::qVector3 *quad4)
{
  float v5; // xmm5_4
  float v6; // xmm8_4
  float v7; // xmm12_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  float v10; // xmm14_4
  float v11; // xmm7_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm15_4
  float v16; // xmm6_4
  float v17; // xmm1_4
  float v19; // xmm9_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm8_4
  float v23; // [rsp+B0h] [rbp+8h]
  float v24; // [rsp+B8h] [rbp+10h]
  float v25; // [rsp+C0h] [rbp+18h]

  v5 = quad2->y;
  v6 = quad2->z;
  v7 = pos->y;
  v8 = pos->z;
  v9 = pos->x;
  v10 = quad1->y;
  v11 = pos->x - quad1->x;
  v12 = quad2->y - v10;
  v13 = pos->y - v10;
  v14 = quad2->x - quad1->x;
  v15 = quad1->z;
  v16 = pos->z - v15;
  v17 = quad2->z - v15;
  v25 = (float)(v11 * v12) - (float)(v13 * v14);
  v24 = (float)(v16 * v14) - (float)(v11 * v17);
  v23 = (float)(v13 * v17) - (float)(v16 * v12);
  if ( (float)((float)((float)((float)((float)((float)(v8 - v6) * (float)(quad3->x - quad2->x))
                                     - (float)((float)(v9 - quad2->x) * (float)(quad3->z - v6)))
                             * v24)
                     + (float)((float)((float)((float)(v7 - v5) * (float)(quad3->z - v6))
                                     - (float)((float)(v8 - v6) * (float)(quad3->y - v5)))
                             * v23))
             + (float)((float)((float)((float)(v9 - quad2->x) * (float)(quad3->y - v5))
                             - (float)((float)(v7 - v5) * (float)(quad3->x - quad2->x)))
                     * v25)) < 0.0 )
    return 0;
  v20 = quad4->y - quad3->y;
  v21 = quad4->z - quad3->z;
  if ( (float)((float)((float)((float)((float)((float)(v8 - quad3->z) * (float)(quad4->x - quad3->x))
                                     - (float)((float)(v9 - quad3->x) * v21))
                             * v24)
                     + (float)((float)((float)((float)(v7 - quad3->y) * v21) - (float)((float)(v8 - quad3->z) * v20))
                             * v23))
             + (float)((float)((float)((float)(v9 - quad3->x) * v20)
                             - (float)((float)(v7 - quad3->y) * (float)(quad4->x - quad3->x)))
                     * v25)) < 0.0 )
    return 0;
  v19 = quad4->y;
  v22 = quad4->x;
  return (float)((float)((float)((float)((float)((float)(v8 - quad4->z) * (float)(quad1->x - v22))
                                       - (float)((float)(v9 - v22) * (float)(v15 - quad4->z)))
                               * v24)
                       + (float)((float)((float)((float)(v7 - v19) * (float)(v15 - quad4->z))
                                       - (float)((float)(v8 - quad4->z) * (float)(v10 - v19)))
                               * v23))
               + (float)((float)((float)((float)(v9 - v22) * (float)(v10 - v19))
                               - (float)((float)(v7 - v19) * (float)(quad1->x - v22)))
                       * v25)) >= 0.0;
}

