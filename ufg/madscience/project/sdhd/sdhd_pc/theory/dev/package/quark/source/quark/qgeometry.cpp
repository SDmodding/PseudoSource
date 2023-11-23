// File Line: 66
// RVA: 0x187CA0
void __fastcall UFG::qNearestRaySeg(
        UFG::qVector3 *ray_pos,
        UFG::qVector3 *ray_dir,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qVector3 *ray_pos_p,
        UFG::qVector3 *seg_pos_p)
{
  float x; // xmm7_4
  char v8; // r11
  float y; // xmm8_4
  float z; // xmm9_4
  float v11; // xmm10_4
  float v12; // xmm11_4
  float v13; // xmm12_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm14_4
  float v17; // xmm4_4
  float v18; // xmm15_4
  float v19; // xmm3_4
  char v20; // cl
  float v21; // xmm3_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm8_4
  float v26; // xmm9_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  float v34; // [rsp+0h] [rbp-C8h]
  float v35; // [rsp+4h] [rbp-C4h]
  float v36; // [rsp+8h] [rbp-C0h]
  float v37; // [rsp+Ch] [rbp-BCh]
  float v38; // [rsp+10h] [rbp-B8h]
  float v39; // [rsp+14h] [rbp-B4h]
  float v40; // [rsp+18h] [rbp-B0h]
  float v41; // [rsp+D0h] [rbp+8h]
  float v42; // [rsp+D8h] [rbp+10h]
  float v43; // [rsp+E0h] [rbp+18h]
  float v44; // [rsp+E8h] [rbp+20h]

  x = end->x;
  v8 = 0;
  y = end->y;
  z = end->z;
  v11 = ray_dir->y;
  v12 = ray_dir->z;
  v13 = ray_dir->x;
  v14 = z - start->z;
  v15 = y - start->y;
  v16 = ray_pos->x;
  v17 = end->x - start->x;
  v18 = ray_pos->y;
  v43 = (float)(v11 * v14) - (float)(v12 * v15);
  v42 = (float)(v12 * v17) - (float)(ray_dir->x * v14);
  v44 = (float)(ray_dir->x * v15) - (float)(v11 * v17);
  v41 = start->y - v18;
  v38 = ray_pos->z;
  v35 = start->z - v38;
  v39 = ray_pos->x;
  v36 = start->x - ray_pos->x;
  v40 = v18;
  v37 = 1.0 / (float)((float)((float)(v42 * v42) + (float)(v43 * v43)) + (float)(v44 * v44));
  v34 = v38;
  v19 = (float)((float)((float)((float)((float)(v35 * v17) - (float)(v36 * v14)) * v42)
                      + (float)((float)((float)(v41 * v14) - (float)(v35 * v15)) * v43))
              + (float)((float)((float)(v36 * v15) - (float)(v41 * v17)) * v44))
      * v37;
  if ( v19 > 0.0 )
  {
    v8 = 1;
    v18 = v18 + (float)(v11 * v19);
    v16 = v16 + (float)(v13 * v19);
    v34 = v38 + (float)(v12 * v19);
  }
  v20 = 0;
  v21 = (float)((float)((float)((float)((float)(v13 * v35) - (float)(v12 * v36)) * v42)
                      + (float)((float)((float)(v12 * v41) - (float)(v11 * v35)) * v43))
              + (float)((float)((float)(v11 * v36) - (float)(v13 * v41)) * v44))
      * v37;
  if ( v21 < 1.0 )
  {
    x = start->x;
    y = start->y;
    z = start->z;
    if ( v21 > 0.0 )
    {
      v20 = 1;
      x = x + (float)(v17 * v21);
      y = y + (float)(v15 * v21);
      z = z + (float)(v14 * v21);
    }
  }
  if ( ray_pos_p )
  {
    if ( v20 )
    {
      ray_pos_p->x = v16;
      ray_pos_p->y = v18;
      ray_pos_p->z = v34;
    }
    else
    {
      ray_pos_p->x = v39;
      ray_pos_p->y = v40;
      ray_pos_p->z = v38;
      v22 = (float)((float)((float)(v13 * x) + (float)(v11 * y)) + (float)(v12 * z))
          - (float)((float)((float)(v39 * v13) + (float)(v40 * v11)) + (float)(v38 * v12));
      if ( v22 > 0.0 )
      {
        v23 = (float)(v22 * ray_dir->x) + ray_pos->x;
        v24 = (float)(v22 * ray_dir->y) + ray_pos->y;
        ray_pos_p->z = (float)(v22 * ray_dir->z) + ray_pos->z;
        ray_pos_p->x = v23;
        ray_pos_p->y = v24;
      }
    }
  }
  if ( seg_pos_p )
  {
    if ( v8 )
    {
      seg_pos_p->x = x;
      seg_pos_p->y = y;
      seg_pos_p->z = z;
    }
    else
    {
      v25 = start->y;
      v26 = start->z;
      v27 = (float)((float)((float)(v15 * ray_pos->y) + (float)(v17 * ray_pos->x)) + (float)(v14 * ray_pos->z))
          - (float)((float)((float)(v25 * v15) + (float)(start->x * v17)) + (float)(v26 * v14));
      v28 = (float)((float)(v15 * v15) + (float)(v17 * v17)) + (float)(v14 * v14);
      if ( v27 < v28 )
      {
        seg_pos_p->x = start->x;
        seg_pos_p->y = v25;
        seg_pos_p->z = v26;
        if ( v27 > 0.0 )
        {
          v31 = v27 / v28;
          v32 = (float)(v15 * v31) + start->y;
          v33 = (float)(v14 * v31) + start->z;
          seg_pos_p->x = (float)(v17 * v31) + start->x;
          seg_pos_p->y = v32;
          seg_pos_p->z = v33;
        }
      }
      else
      {
        v29 = end->y;
        v30 = end->z;
        seg_pos_p->x = end->x;
        seg_pos_p->y = v29;
        seg_pos_p->z = v30;
      }
    }
  }
}

// File Line: 549
// RVA: 0x1871F0
_BOOL8 __fastcall UFG::qIsBoundPointPolyXY(UFG::qVector3 *posXY, UFG::qVector3 *pPolyVerts, unsigned int polyVertCount)
{
  bool v3; // r10
  UFG::qVector3 *v4; // r9
  float y; // xmm3_4
  float x; // xmm6_4
  UFG::qVector3 *v7; // r11
  UFG::qVector3 *v8; // r8
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm5_4
  float v15; // xmm4_4

  v3 = 0;
  v4 = pPolyVerts;
  if ( !polyVertCount )
    return 0i64;
  y = posXY->y;
  x = posXY->x;
  v7 = &pPolyVerts[polyVertCount - 1];
  v8 = &pPolyVerts[polyVertCount];
  if ( pPolyVerts < v8 )
  {
    if ( ((char *)v8 - (char *)pPolyVerts + 11) / 12 >= 4 )
    {
      do
      {
        v9 = v4->y;
        if ( v9 <= y && (v10 = v7->y, y < v10) || (v10 = v7->y, v10 <= y) && y < v9 )
        {
          if ( x < (float)((float)((float)((float)(v7->x - v4->x) * (float)(y - v9)) / (float)(v10 - v9)) + v4->x) )
            v3 = !v3;
        }
        v11 = v4[1].y;
        if ( (v11 <= y && y < v9 || v9 <= y && y < v11)
          && x < (float)((float)((float)((float)(y - v11) * (float)(v4->x - v4[1].x)) / (float)(v9 - v11)) + v4[1].x) )
        {
          v3 = !v3;
        }
        v12 = v4[2].y;
        if ( v12 <= y && y < v11 || (v11 = v4[1].y, v11 <= y) && y < v12 )
        {
          if ( x < (float)((float)((float)((float)(v4[1].x - v4[2].x) * (float)(y - v12)) / (float)(v11 - v12)) + v4[2].x) )
            v3 = !v3;
        }
        v13 = v4[3].y;
        if ( (v13 <= y && y < v12 || v12 <= y && y < v13)
          && x < (float)((float)((float)((float)(v4[2].x - v4[3].x) * (float)(y - v13)) / (float)(v12 - v13)) + v4[3].x) )
        {
          v3 = !v3;
        }
        v7 = v4 + 3;
        v4 += 4;
      }
      while ( (__int64)v4 < (__int64)&v8[-3] );
    }
    for ( ; v4 < v8; ++v4 )
    {
      v14 = v4->y;
      if ( v14 <= y && (v15 = v7->y, y < v15) || (v15 = v7->y, v15 <= y) && y < v14 )
      {
        if ( x < (float)((float)((float)((float)(y - v14) * (float)(v7->x - v4->x)) / (float)(v15 - v14)) + v4->x) )
          v3 = !v3;
      }
      v7 = v4;
    }
  }
  return v3;
}

// File Line: 611
// RVA: 0x185E20
char __fastcall UFG::qIntersectSegPolyXY(
        UFG::qVector2 *startXY,
        UFG::qVector2 *endXY,
        UFG::qVector2 *pPolyVerts,
        unsigned int polyVertCount,
        float *pPDist,
        UFG::qVector3 *pHitPos)
{
  UFG::qVector2 *v6; // rbx
  __int64 v8; // rsi
  float y; // xmm0_4
  float x; // xmm1_4
  float v13; // xmm6_4
  UFG::qVector2 *v14; // rbp
  UFG::qVector2 *v15; // r9
  float v16; // xmm4_4
  float v17; // xmm3_4
  float pdista_p[4]; // [rsp+30h] [rbp-28h] BYREF

  v6 = pPolyVerts;
  v8 = polyVertCount;
  if ( UFG::qIsBoundPointPolyXY((UFG::qVector3 *)startXY, (UFG::qVector3 *)pPolyVerts, polyVertCount) )
  {
    if ( pPDist )
      *pPDist = 0.0;
    if ( pHitPos )
    {
      y = startXY->y;
      x = startXY[1].x;
      pHitPos->x = startXY->x;
      pHitPos->y = y;
      pHitPos->z = x;
    }
    return 1;
  }
  else
  {
    v13 = FLOAT_3_4028235e38;
    v14 = (UFG::qVector2 *)((char *)v6 + 12 * v8);
    v15 = (UFG::qVector2 *)((char *)v6 + 12 * (unsigned int)(v8 - 1));
    if ( v6 >= v14 )
      return 0;
    do
    {
      if ( UFG::qIntersectSegSeg2D(startXY, endXY, v6, v15, pdista_p, 0i64) && pdista_p[0] < v13 )
        v13 = pdista_p[0];
      v15 = v6;
      v6 = (UFG::qVector2 *)((char *)v6 + 12);
    }
    while ( v6 < v14 );
    if ( v13 == 3.4028235e38 )
    {
      return 0;
    }
    else
    {
      if ( pPDist )
        *pPDist = v13;
      if ( pHitPos )
      {
        v16 = (float)((float)(endXY->y - startXY->y) * v13) + startXY->y;
        v17 = (float)((float)(endXY[1].x - startXY[1].x) * v13) + startXY[1].x;
        pHitPos->x = (float)((float)(endXY->x - startXY->x) * v13) + startXY->x;
        pHitPos->y = v16;
        pHitPos->z = v17;
      }
      return 1;
    }
  }
}

// File Line: 679
// RVA: 0x185010
__int64 __fastcall UFG::qIntersectPlanePlane(
        UFG::qVector4 *plane1,
        UFG::qVector4 *plane2,
        UFG::qVector3 *ray_pos,
        UFG::qVector3 *ray_dir)
{
  float x; // xmm3_4
  float z; // xmm4_4
  float y; // xmm6_4
  float v7; // xmm8_4
  float v8; // xmm11_4
  float v9; // xmm10_4
  int v10; // xmm12_4
  int v11; // xmm9_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  float v14; // xmm13_4
  float v15; // xmm12_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm9_4
  float v20; // xmm15_4
  float v21; // xmm14_4
  __int64 result; // rax
  int v23; // ecx
  float v24; // xmm1_4
  float v25; // xmm5_4
  int v26; // ecx
  int v27; // ecx
  float v28; // xmm8_4
  float v29; // xmm3_4
  float v30; // xmm0_4
  float v31; // xmm4_4
  float v32; // xmm6_4
  float v33; // [rsp+0h] [rbp-C8h]
  float v34; // [rsp+4h] [rbp-C4h]
  float v35; // [rsp+8h] [rbp-C0h]
  float v36; // [rsp+Ch] [rbp-BCh]
  float v37; // [rsp+10h] [rbp-B8h]
  float v38; // [rsp+D0h] [rbp+8h]
  float v39; // [rsp+D8h] [rbp+10h]

  x = plane1->x;
  z = plane1->z;
  y = plane1->y;
  v7 = plane2->x;
  v8 = plane2->y;
  v9 = plane2->z;
  v10 = LODWORD(plane1->w) ^ _xmm[0];
  v11 = LODWORD(plane2->w) ^ _xmm[0];
  v12 = 1.0 / (float)((float)((float)(y * y) + (float)(x * x)) + (float)(z * z));
  v13 = (float)(*(float *)&v10 * plane1->x) * v12;
  v14 = (float)(*(float *)&v10 * y) * v12;
  v15 = (float)(*(float *)&v10 * z) * v12;
  v16 = 1.0 / (float)((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9));
  v17 = (float)(*(float *)&v11 * plane2->x) * v16;
  v18 = (float)(*(float *)&v11 * v8) * v16;
  v19 = (float)(*(float *)&v11 * v9) * v16;
  v38 = (float)(y * v9) - (float)(v8 * z);
  v33 = (float)(plane2->x * z) - (float)(plane1->x * v9);
  LODWORD(v20) = LODWORD(v33) & _xmm;
  v39 = (float)(plane1->x * v8) - (float)(plane2->x * y);
  LODWORD(v21) = LODWORD(v38) & _xmm;
  LODWORD(v34) = LODWORD(v39) & _xmm;
  if ( (float)((float)(COERCE_FLOAT(LODWORD(v33) & _xmm) + COERCE_FLOAT(LODWORD(v38) & _xmm))
             + COERCE_FLOAT(LODWORD(v39) & _xmm)) < 0.000001 )
    return COERCE_FLOAT(COERCE_UNSIGNED_INT(
                          (float)((float)((float)(v17 - v13) * x) + (float)((float)(v18 - v14) * y))
                        + (float)((float)(v19 - v15) * z)) & _xmm) < 0.000001;
  if ( v21 <= v20 )
  {
    v23 = (v20 <= v34) + 2;
  }
  else
  {
    v23 = 3;
    if ( v21 > v34 )
      v23 = 1;
  }
  LODWORD(v24) = COERCE_UNSIGNED_INT((float)((float)(v17 * v7) + (float)(v18 * v8)) + (float)(v19 * v9)) ^ _xmm[0];
  LODWORD(v25) = COERCE_UNSIGNED_INT((float)((float)(v13 * x) + (float)(v14 * y)) + (float)(v15 * z)) ^ _xmm[0];
  v26 = v23 - 1;
  if ( !v26 )
  {
    v31 = (float)((float)(z * v24) - (float)(v9 * v25)) * (float)(1.0 / v38);
    v29 = (float)((float)(v8 * v25) - (float)(y * v24)) * (float)(1.0 / v38);
    v30 = 0.0;
LABEL_15:
    v32 = v33;
    goto LABEL_16;
  }
  v27 = v26 - 1;
  if ( v27 )
  {
    if ( v27 == 1 )
    {
      v28 = (float)((float)(v7 * v25) - (float)(x * v24)) * (float)(1.0 / v39);
      v29 = 0.0;
      v30 = (float)((float)(y * v24) - (float)(v8 * v25)) * (float)(1.0 / v39);
      v31 = v28;
    }
    else
    {
      v29 = v37;
      v31 = v36;
      v30 = v35;
    }
    goto LABEL_15;
  }
  v32 = v33;
  v30 = (float)((float)(v9 * v25) - (float)(z * v24)) * (float)(1.0 / v33);
  v29 = (float)((float)(x * v24) - (float)(v7 * v25)) * (float)(1.0 / v33);
  v31 = 0.0;
LABEL_16:
  ray_pos->x = v30;
  ray_pos->y = v31;
  result = 2i64;
  ray_pos->z = v29;
  ray_dir->z = v39;
  ray_dir->x = v38;
  ray_dir->y = v32;
  return result;
}

// File Line: 879
// RVA: 0x185980
__int64 __fastcall UFG::qIntersectRaySphere(
        UFG::qVector3 *ray_pos,
        UFG::qVector3 *ray_dir,
        UFG::qVector3 *origin,
        const float radius,
        UFG::qVector3 *entry_p,
        UFG::qVector3 *exit_p)
{
  float y; // xmm4_4
  float z; // xmm5_4
  float x; // xmm11_4
  float v10; // xmm8_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm14_4
  float v15; // xmm3_4
  float v16; // xmm15_4
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm10_4
  float v20; // xmm0_4
  float v21; // xmm9_4
  float v22; // xmm2_4
  char v24; // dl
  float v25; // xmm5_4
  float v26; // xmm4_4
  float v27; // xmm10_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // [rsp+C8h] [rbp+20h]

  y = origin->y;
  z = origin->z;
  v32 = ray_pos->z;
  x = ray_dir->x;
  v10 = v32;
  v11 = ray_dir->y;
  v12 = ray_dir->z;
  v13 = ray_pos->x;
  v15 = origin->x;
  v16 = ray_pos->y;
  v17 = ray_pos->x;
  v18 = v16;
  v19 = (float)((float)((float)(origin->x * ray_dir->x) + (float)(y * v11)) + (float)(z * v12))
      - (float)((float)((float)(v11 * v16) + (float)(ray_dir->x * ray_pos->x)) + (float)(v12 * v32));
  if ( v19 > 0.0 )
  {
    v20 = v19 / (float)((float)((float)(x * x) + (float)(v11 * v11)) + (float)(v12 * v12));
    v17 = v13 + (float)(x * v20);
    v18 = v16 + (float)(v11 * v20);
    v10 = v32 + (float)(v12 * v20);
  }
  v21 = radius * radius;
  v22 = (float)((float)((float)(y - v18) * (float)(y - v18)) + (float)((float)(v15 - v17) * (float)(v15 - v17)))
      + (float)((float)(z - v10) * (float)(z - v10));
  if ( v22 > v21 )
    return 0i64;
  v24 = 0;
  if ( v19 <= 0.0
    || (float)((float)((float)((float)(y - v16) * (float)(y - v16)) + (float)((float)(v15 - v13) * (float)(v15 - v13)))
             + (float)((float)(z - v32) * (float)(z - v32))) <= v21 )
  {
    entry_p->x = v13;
    entry_p->y = v16;
    entry_p->z = v32;
    if ( !exit_p )
      return 2i64;
    v24 = 1;
    if ( v19 <= 0.0 )
    {
      v25 = ray_dir->y;
      v26 = ray_dir->z;
      v27 = v19 / (float)((float)((float)(ray_dir->x * ray_dir->x) + (float)(v25 * v25)) + (float)(v26 * v26));
      v17 = v17 + (float)(ray_dir->x * v27);
      v18 = v18 + (float)(v25 * v27);
      v10 = v10 + (float)(v26 * v27);
      v22 = (float)((float)((float)(origin->y - v18) * (float)(origin->y - v18))
                  + (float)((float)(origin->x - v17) * (float)(origin->x - v17)))
          + (float)((float)(origin->z - v10) * (float)(origin->z - v10));
    }
  }
  v28 = fsqrt(v21 - v22);
  v29 = ray_dir->x * v28;
  v30 = ray_dir->y * v28;
  v31 = ray_dir->z * v28;
  if ( !v24 )
  {
    entry_p->x = v17 - v29;
    entry_p->y = v18 - v30;
    entry_p->z = v10 - v31;
  }
  if ( exit_p )
  {
    exit_p->x = v17 + v29;
    exit_p->y = v18 + v30;
    exit_p->z = v10 + v31;
  }
  return 3 - (unsigned int)(v24 != 0);
}

// File Line: 1048
// RVA: 0x186340
__int64 __fastcall UFG::qIntersectSegSphere(
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qVector3 *origin,
        float radius,
        UFG::qVector3 *entry_p,
        UFG::qVector3 *exit_p)
{
  float v7; // xmm3_4
  float y; // xmm13_4
  float x; // xmm12_4
  float z; // xmm14_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm11_4
  unsigned int v16; // r9d
  float v17; // xmm15_4
  int v18; // ecx
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm4_4
  float v22; // xmm10_4
  char v23; // r11
  bool v24; // r10
  float v25; // xmm0_4
  float v26; // xmm7_4
  float v27; // xmm8_4
  float v28; // xmm9_4

  v7 = radius * radius;
  y = start->y;
  x = start->x;
  z = start->z;
  v11 = end->y - y;
  v12 = end->x - start->x;
  v13 = end->z - z;
  v14 = (float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v13 * v13);
  if ( v14 > 0.000001 )
  {
    v16 = 0;
    v17 = (float)((float)((float)(origin->y * v11) + (float)(origin->x * v12)) + (float)(origin->z * v13))
        - (float)((float)((float)(x * v12) + (float)(y * v11)) + (float)(z * v13));
    if ( v17 > 0.0 )
      v18 = (v17 < v14) + 2;
    else
      v18 = 1;
    v19 = x;
    v20 = y;
    v21 = z;
    if ( v18 == 2 )
    {
      v19 = end->x;
      v20 = end->y;
      v21 = end->z;
    }
    else if ( v18 == 3 )
    {
      v21 = z + (float)((float)(v17 / v14) * v13);
      v19 = x + (float)((float)(v17 / v14) * v12);
      v20 = y + (float)((float)(v17 / v14) * v11);
    }
    v22 = (float)((float)((float)(origin->y - v20) * (float)(origin->y - v20))
                + (float)((float)(origin->x - v19) * (float)(origin->x - v19)))
        + (float)((float)(origin->z - v21) * (float)(origin->z - v21));
    if ( v22 <= v7 )
    {
      v23 = 0;
      if ( v18 == 1
        || (float)((float)((float)((float)(origin->y - y) * (float)(origin->y - y))
                         + (float)((float)(origin->x - x) * (float)(origin->x - x)))
                 + (float)((float)(origin->z - z) * (float)(origin->z - z))) <= v7 )
      {
        entry_p->x = x;
        entry_p->y = y;
        entry_p->z = z;
        v23 = 1;
      }
      v24 = !exit_p
         || v18 == 2
         || (float)((float)((float)((float)(origin->y - end->y) * (float)(origin->y - end->y))
                          + (float)((float)(origin->x - end->x) * (float)(origin->x - end->x)))
                  + (float)((float)(origin->z - end->z) * (float)(origin->z - end->z))) <= v7;
      if ( v23 && v24 )
      {
        return 4i64;
      }
      else
      {
        if ( v18 != 3 )
        {
          v21 = (float)((float)(v17 / v14) * v13) + start->z;
          v19 = (float)((float)(v17 / v14) * v12) + start->x;
          v20 = (float)((float)(v17 / v14) * v11) + start->y;
          v22 = (float)((float)((float)(origin->y - v20) * (float)(origin->y - v20))
                      + (float)((float)(origin->x - v19) * (float)(origin->x - v19)))
              + (float)((float)(origin->z - v21) * (float)(origin->z - v21));
        }
        v25 = fsqrt((float)(v7 - v22) / v14);
        v26 = v12 * v25;
        v27 = v11 * v25;
        v28 = v13 * v25;
        if ( !v23 )
        {
          v16 = 1;
          entry_p->x = v19 - v26;
          entry_p->y = v20 - v27;
          entry_p->z = v21 - v28;
        }
        if ( !v24 )
        {
          v16 |= 2u;
          exit_p->x = v19 + v26;
          exit_p->y = v20 + v27;
          exit_p->z = v21 + v28;
        }
        return v16;
      }
    }
    else
    {
      return 0i64;
    }
  }
  else if ( (float)((float)((float)((float)(y - origin->y) * (float)(y - origin->y))
                          + (float)((float)(x - origin->x) * (float)(x - origin->x)))
                  + (float)((float)(z - origin->z) * (float)(z - origin->z))) > v7 )
  {
    return 0i64;
  }
  else
  {
    entry_p->x = x;
    entry_p->y = y;
    entry_p->z = z;
    return 4i64;
  }
} > v7 )
  {
    return 0i64;
  }
  else
  {
    entry_p->x = x;
    entry_p->y = y;
    entry_p->z = z;
    return 

// File Line: 1220
// RVA: 0x185CB0
bool __fastcall UFG::qIntersectSegCircleOrigin(
        UFG::qVector2 *start,
        UFG::qVector2 *end,
        const float radius,
        float *pPDist)
{
  float y; // xmm6_4
  float x; // xmm7_4
  float v6; // xmm3_4
  bool result; // al
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm8_4
  float v11; // xmm9_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  char v14; // al
  float v15; // xmm2_4

  y = start->y;
  x = start->x;
  v6 = radius * radius;
  if ( (float)((float)(x * x) + (float)(y * y)) > (float)(radius * radius) )
  {
    v8 = end->x;
    v9 = end->y;
    v10 = end->x - x;
    v11 = v9 - y;
    v12 = (float)(v10 * v10) + (float)(v11 * v11);
    LODWORD(v13) = COERCE_UNSIGNED_INT((float)(x * v10) + (float)(y * (float)(v9 - y))) ^ _xmm[0];
    if ( v13 <= 0.0 || v12 <= 0.000001 )
      return 0;
    v14 = 0;
    if ( v13 < v12 )
    {
      v9 = (float)((float)(v13 / v12) * v11) + y;
      v8 = (float)((float)(v13 / v12) * v10) + x;
    }
    else
    {
      v14 = 1;
    }
    v15 = (float)(v9 * v9) + (float)(v8 * v8);
    if ( v15 > v6 )
    {
      return 0;
    }
    else
    {
      if ( v14 )
        v15 = (float)((float)((float)((float)(v13 / v12) * v11) + y) * (float)((float)((float)(v13 / v12) * v11) + y))
            + (float)((float)((float)((float)(v13 / v12) * v10) + x) * (float)((float)((float)(v13 / v12) * v10) + x));
      result = 1;
      *pPDist = (float)((float)(1.0 / v12) * v13) - fsqrt((float)(v6 - v15) * (float)(1.0 / v12));
    }
  }
  else
  {
    *pPDist = 0.0;
    return 1;
  }
  return result;
}

// File Line: 1375
// RVA: 0x185510
__int64 __fastcall UFG::qIntersectRaySlab(
        UFG::qVector3 *ray_pos,
        UFG::qVector3 *ray_dir,
        UFG::qVector3 *slab_normal,
        float slab_below,
        float slab_above,
        UFG::qVector3 *hit_enter_p,
        UFG::qVector3 *hit_exit_p)
{
  float y; // xmm5_4
  float z; // xmm6_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  int v15; // r8d
  float v16; // xmm4_4
  UFG::qVector3 *v17; // r11
  int v18; // edx
  UFG::qVector3 *v19; // r10
  float v20; // xmm5_4
  float x; // xmm3_4
  float v22; // xmm6_4
  float v23; // xmm8_4
  __int64 result; // rax
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm7_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm0_4

  y = ray_pos->y;
  z = ray_pos->z;
  v12 = y * slab_normal->y;
  v13 = ray_pos->x * slab_normal->x;
  v14 = z * slab_normal->z;
  v15 = 0;
  v16 = (float)(v12 + v13) + v14;
  if ( v16 >= slab_below )
  {
    v17 = hit_exit_p;
    if ( v16 > slab_above )
    {
      v19 = hit_enter_p;
      v18 = 2;
      goto LABEL_7;
    }
    v18 = 1;
    hit_enter_p->x = ray_pos->x;
    hit_enter_p->y = y;
    hit_enter_p->z = z;
  }
  else
  {
    v17 = hit_enter_p;
    v18 = 0;
  }
  v19 = hit_exit_p;
LABEL_7:
  v20 = ray_dir->y;
  x = ray_dir->x;
  v22 = ray_dir->z;
  v23 = (float)((float)(v20 * slab_normal->y) + (float)(ray_dir->x * slab_normal->x)) + (float)(v22 * slab_normal->z);
  if ( v23 == 0.0 )
  {
    if ( v18 == 1 )
    {
      result = 4i64;
      v25 = (float)(v20 * 10000.0) + ray_pos->y;
      v26 = (float)(v22 * 10000.0) + ray_pos->z;
      hit_exit_p->x = (float)(x * 10000.0) + ray_pos->x;
      hit_exit_p->y = v25;
      hit_exit_p->z = v26;
      return result;
    }
    return 0i64;
  }
  v27 = (float)(slab_below - v16) * (float)(1.0 / v23);
  if ( v27 >= 0.0 )
  {
    v28 = (float)(v20 * v27) + ray_pos->y;
    v29 = (float)(v22 * v27) + ray_pos->z;
    v17->x = (float)(x * v27) + ray_pos->x;
    v17->y = v28;
    v17->z = v29;
  }
  else if ( !v18 )
  {
    return 0i64;
  }
  v30 = (float)(slab_above - v16) * (float)(1.0 / v23);
  if ( v30 >= 0.0 )
  {
    v31 = (float)(v30 * ray_dir->x) + ray_pos->x;
    v32 = (float)(v30 * ray_dir->y) + ray_pos->y;
    v19->z = (float)(v30 * ray_dir->z) + ray_pos->z;
    v19->x = v31;
    v19->y = v32;
  }
  else if ( v18 == 2 )
  {
    return 0i64;
  }
  LOBYTE(v15) = v18 != 1;
  return (unsigned int)(v15 + 2);
}

// File Line: 1573
// RVA: 0x1856F0
__int64 __fastcall UFG::qIntersectRaySlabZ(
        UFG::qVector3 *ray_pos,
        UFG::qVector3 *ray_dir,
        float slab_below,
        float slab_above,
        UFG::qVector3 *hit_enter_p,
        UFG::qVector3 *hit_exit_p)
{
  float z; // xmm6_4
  float v8; // xmm3_4
  float y; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm5_4
  float v24; // xmm7_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm5_4
  float v28; // xmm2_4
  float v29; // xmm2_4
  float x; // eax
  float v31; // xmm5_4
  float v32; // xmm2_4
  float v33; // xmm4_4

  z = ray_pos->z;
  v8 = ray_dir->z;
  if ( v8 == 0.0 )
  {
    if ( slab_below <= z && z <= slab_above )
    {
      y = ray_pos->y;
      hit_enter_p->x = ray_pos->x;
      hit_enter_p->y = y;
      hit_enter_p->z = z;
      v10 = (float)(ray_dir->y * 10000.0) + ray_pos->y;
      v11 = (float)(ray_dir->z * 10000.0) + ray_pos->z;
      hit_exit_p->x = (float)(ray_dir->x * 10000.0) + ray_pos->x;
      hit_exit_p->y = v10;
      hit_exit_p->z = v11;
      return 4i64;
    }
    return 0i64;
  }
  if ( z < slab_below )
  {
    if ( v8 >= 0.0 )
    {
      v13 = (float)(slab_below - z) * ray_dir->x;
      v14 = (float)(slab_below - z) * v8;
      v15 = slab_above - z;
      v16 = (float)((float)(1.0 / v8) * (float)((float)(slab_below - z) * ray_dir->y)) + ray_pos->y;
      hit_enter_p->x = (float)((float)(1.0 / v8) * v13) + ray_pos->x;
      hit_enter_p->y = v16;
      v17 = 1.0 / v8;
      v18 = v17;
      hit_enter_p->z = (float)(v17 * v14) + z;
      v19 = slab_above - z;
      v20 = v17 * (float)((float)(slab_above - z) * ray_dir->z);
LABEL_9:
      v21 = (float)(v17 * (float)(v15 * ray_dir->x)) + ray_pos->x;
      v22 = (float)(v18 * (float)(v19 * ray_dir->y)) + ray_pos->y;
      hit_exit_p->z = v20 + ray_pos->z;
      hit_exit_p->x = v21;
      hit_exit_p->y = v22;
      return 3i64;
    }
    return 0i64;
  }
  if ( z > slab_above )
  {
    if ( v8 <= 0.0 )
    {
      v23 = slab_above - z;
      v24 = slab_below - z;
      v25 = v23 * ray_dir->x;
      v26 = v23 * ray_dir->y;
      v27 = v23 * v8;
      v28 = (float)(1.0 / v8) * v26;
      v15 = v24;
      v29 = v28 + ray_pos->y;
      hit_enter_p->x = (float)((float)(1.0 / v8) * v25) + ray_pos->x;
      hit_enter_p->y = v29;
      v17 = 1.0 / v8;
      v18 = v17;
      hit_enter_p->z = (float)(v17 * v27) + z;
      v19 = v24;
      v20 = v17 * (float)(v24 * ray_dir->z);
      goto LABEL_9;
    }
    return 0i64;
  }
  if ( v8 <= 0.0 )
    slab_above = slab_below;
  x = ray_pos->x;
  v31 = slab_above - z;
  hit_enter_p->y = ray_pos->y;
  hit_enter_p->z = z;
  hit_enter_p->x = x;
  v32 = (float)((float)(1.0 / v8) * (float)(v31 * ray_dir->y)) + ray_pos->y;
  v33 = (float)((float)(1.0 / v8) * (float)(v31 * ray_dir->z)) + ray_pos->z;
  hit_exit_p->x = (float)((float)(1.0 / v8) * (float)(v31 * ray_dir->x)) + ray_pos->x;
  hit_exit_p->y = v32;
  hit_exit_p->z = v33;
  return 2i64;
}

// File Line: 1659
// RVA: 0x186120
__int64 __fastcall UFG::qIntersectSegSlab(
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qVector3 *slab_normal,
        float slab_below,
        float slab_above,
        UFG::qVector3 *hit_enter_p,
        UFG::qVector3 *hit_exit_p)
{
  float y; // xmm5_4
  __int64 result; // rax
  float z; // xmm6_4
  unsigned int v13; // edx
  float v14; // xmm4_4
  int v15; // ecx
  float v16; // xmm6_4
  float v17; // xmm7_4
  UFG::qVector3 *v18; // r10
  float v19; // xmm2_4
  int v20; // r8d
  float v21; // xmm5_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm8_4
  UFG::qVector3 *v25; // rax
  float v26; // xmm9_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm6_4
  float v31; // xmm7_4

  y = start->y;
  result = 0i64;
  z = start->z;
  v13 = 2;
  v14 = (float)((float)(y * slab_normal->y) + (float)(start->x * slab_normal->x)) + (float)(z * slab_normal->z);
  if ( v14 >= slab_below )
  {
    if ( v14 <= slab_above )
    {
      hit_enter_p->x = start->x;
      hit_enter_p->y = y;
      hit_enter_p->z = z;
      v15 = 1;
    }
    else
    {
      v15 = 2;
    }
  }
  else
  {
    v15 = 0;
  }
  v16 = end->y;
  v17 = end->z;
  v18 = hit_exit_p;
  v19 = (float)((float)(v16 * slab_normal->y) + (float)(end->x * slab_normal->x)) + (float)(v17 * slab_normal->z);
  if ( v19 >= slab_below )
  {
    if ( v19 <= slab_above )
    {
      hit_exit_p->x = end->x;
      hit_exit_p->y = v16;
      hit_exit_p->z = v17;
      v20 = 1;
    }
    else
    {
      v20 = 2;
    }
  }
  else
  {
    v20 = 0;
  }
  if ( v15 == v20 )
  {
    if ( v15 == 1 )
      return 4i64;
  }
  else
  {
    v21 = end->x - start->x;
    v22 = end->y - start->y;
    v23 = end->z - start->z;
    v24 = (float)((float)(v21 * slab_normal->x) + (float)(v22 * slab_normal->y)) + (float)(v23 * slab_normal->z);
    if ( !v15 || !v20 )
    {
      v25 = hit_exit_p;
      if ( !v15 )
        v25 = hit_enter_p;
      v26 = (float)(slab_below - v14) / v24;
      v27 = (float)(v22 * v26) + start->y;
      v28 = (float)(v23 * v26) + start->z;
      v25->x = (float)(v21 * v26) + start->x;
      v25->y = v27;
      v25->z = v28;
    }
    if ( v15 == 2 || v20 == 2 )
    {
      if ( v15 == 2 )
        v18 = hit_enter_p;
      v29 = (float)(slab_above - v14) / v24;
      v30 = (float)(v22 * v29) + start->y;
      v31 = (float)(v23 * v29) + start->z;
      v18->x = (float)(v21 * v29) + start->x;
      v18->y = v30;
      v18->z = v31;
    }
    if ( v15 != 1 )
    {
      v13 = 3;
      if ( v20 == 1 )
        return 1;
    }
    return v13;
  }
  return result;
}

