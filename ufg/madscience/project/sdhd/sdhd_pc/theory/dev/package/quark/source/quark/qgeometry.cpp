// File Line: 66
// RVA: 0x187CA0
void __fastcall UFG::qNearestRaySeg(UFG::qVector3 *ray_pos, UFG::qVector3 *ray_dir, UFG::qVector3 *start, UFG::qVector3 *end, UFG::qVector3 *ray_pos_p, UFG::qVector3 *seg_pos_p)
{
  float v6; // xmm7_4
  UFG::qVector3 *v7; // r10
  char v8; // r11
  float v9; // xmm8_4
  float v10; // xmm9_4
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
  __int64 v39; // [rsp+14h] [rbp-B4h]
  float v40; // [rsp+D0h] [rbp+8h]
  float v41; // [rsp+D8h] [rbp+10h]
  float v42; // [rsp+E0h] [rbp+18h]
  float v43; // [rsp+E8h] [rbp+20h]

  v6 = end->x;
  v7 = ray_pos;
  v8 = 0;
  v9 = end->y;
  v10 = end->z;
  v11 = ray_dir->y;
  v12 = ray_dir->z;
  v13 = ray_dir->x;
  v14 = end->z - start->z;
  v15 = end->y - start->y;
  v16 = ray_pos->x;
  v17 = end->x - start->x;
  v18 = ray_pos->y;
  v42 = (float)(ray_dir->y * v14) - (float)(v12 * v15);
  v41 = (float)(ray_dir->z * v17) - (float)(ray_dir->x * v14);
  v43 = (float)(ray_dir->x * v15) - (float)(v11 * v17);
  v40 = start->y - v18;
  v38 = ray_pos->z;
  v35 = start->z - v38;
  *(float *)&v39 = ray_pos->x;
  v36 = start->x - ray_pos->x;
  HIDWORD(v39) = LODWORD(ray_pos->y);
  v37 = 1.0 / (float)((float)((float)(v41 * v41) + (float)(v42 * v42)) + (float)(v43 * v43));
  v34 = ray_pos->z;
  v19 = (float)((float)((float)((float)((float)(v35 * v17) - (float)(v36 * v14)) * v41)
                      + (float)((float)((float)(v40 * v14) - (float)(v35 * v15)) * v42))
              + (float)((float)((float)(v36 * v15) - (float)(v40 * v17)) * v43))
      * v37;
  if ( v19 > 0.0 )
  {
    v8 = 1;
    v18 = v18 + (float)(v11 * v19);
    v16 = v16 + (float)(v13 * v19);
    v34 = v34 + (float)(v12 * v19);
  }
  v20 = 0;
  v21 = (float)((float)((float)((float)((float)(v13 * v35) - (float)(v12 * v36)) * v41)
                      + (float)((float)((float)(v12 * v40) - (float)(v11 * v35)) * v42))
              + (float)((float)((float)(v11 * v36) - (float)(v13 * v40)) * v43))
      * v37;
  if ( v21 < 1.0 )
  {
    v6 = start->x;
    v9 = start->y;
    v10 = start->z;
    if ( v21 > 0.0 )
    {
      v20 = 1;
      v6 = v6 + (float)(v17 * v21);
      v9 = v9 + (float)(v15 * v21);
      v10 = v10 + (float)(v14 * v21);
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
      *(_QWORD *)&ray_pos_p->x = v39;
      ray_pos_p->z = v38;
      v22 = (float)((float)((float)(v13 * v6) + (float)(v11 * v9)) + (float)(v12 * v10))
          - (float)((float)((float)(*(float *)&v39 * v13) + (float)(*((float *)&v39 + 1) * v11)) + (float)(v38 * v12));
      if ( v22 > 0.0 )
      {
        v23 = (float)(v22 * ray_dir->x) + v7->x;
        v24 = (float)(v22 * ray_dir->y) + v7->y;
        ray_pos_p->z = (float)(v22 * ray_dir->z) + v7->z;
        ray_pos_p->x = v23;
        ray_pos_p->y = v24;
      }
    }
  }
  if ( seg_pos_p )
  {
    if ( v8 )
    {
      seg_pos_p->x = v6;
      seg_pos_p->y = v9;
      seg_pos_p->z = v10;
    }
    else
    {
      v25 = start->y;
      v26 = start->z;
      v27 = (float)((float)((float)(v15 * v7->y) + (float)(v17 * v7->x)) + (float)(v14 * v7->z))
          - (float)((float)((float)(start->y * v15) + (float)(start->x * v17)) + (float)(start->z * v14));
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
  float v5; // xmm3_4
  float v6; // xmm6_4
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
  v5 = posXY->y;
  v6 = posXY->x;
  v7 = &pPolyVerts[polyVertCount - 1];
  v8 = &pPolyVerts[polyVertCount];
  if ( pPolyVerts < v8 )
  {
    if ( (signed __int64)(((unsigned __int64)((unsigned __int128)(((char *)v8 - (char *)pPolyVerts + 11)
                                                                * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                        + ((signed __int64)((unsigned __int128)(((char *)v8 - (char *)pPolyVerts + 11)
                                                              * (signed __int128)3074457345618258603i64) >> 64) >> 1)) >= 4 )
    {
      do
      {
        v9 = v4->y;
        if ( v9 <= v5 && (v10 = v7->y, v5 < v10) || (v10 = v7->y, v10 <= v5) && v5 < v9 )
        {
          if ( v6 < (float)((float)((float)((float)(v7->x - v4->x) * (float)(v5 - v9)) / (float)(v10 - v9)) + v4->x) )
            v3 = v3 == 0;
        }
        v11 = v4[1].y;
        if ( (v11 <= v5 && v5 < v9 || v9 <= v5 && v5 < v11)
          && v6 < (float)((float)((float)((float)(v5 - v11) * (float)(v4->x - v4[1].x)) / (float)(v9 - v11)) + v4[1].x) )
        {
          v3 = v3 == 0;
        }
        v12 = v4[2].y;
        if ( v12 <= v5 && v5 < v11 || (v11 = v4[1].y, v11 <= v5) && v5 < v12 )
        {
          if ( v6 < (float)((float)((float)((float)(v4[1].x - v4[2].x) * (float)(v5 - v12)) / (float)(v11 - v12))
                          + v4[2].x) )
            v3 = v3 == 0;
        }
        v13 = v4[3].y;
        if ( (v13 <= v5 && v5 < v12 || v12 <= v5 && v5 < v13)
          && v6 < (float)((float)((float)((float)(v4[2].x - v4[3].x) * (float)(v5 - v13)) / (float)(v12 - v13)) + v4[3].x) )
        {
          v3 = v3 == 0;
        }
        v7 = v4 + 3;
        v4 += 4;
      }
      while ( (signed __int64)v4 < (signed __int64)&v8[-3] );
    }
    for ( ; v4 < v8; ++v4 )
    {
      v14 = v4->y;
      if ( v14 <= v5 && (v15 = v7->y, v5 < v15) || (v15 = v7->y, v15 <= v5) && v5 < v14 )
      {
        if ( v6 < (float)((float)((float)((float)(v5 - v14) * (float)(v7->x - v4->x)) / (float)(v15 - v14)) + v4->x) )
          v3 = v3 == 0;
      }
      v7 = v4;
    }
  }
  return v3;
}

// File Line: 611
// RVA: 0x185E20
char __fastcall UFG::qIntersectSegPolyXY(UFG::qVector3 *startXY, UFG::qVector3 *endXY, UFG::qVector3 *pPolyVerts, unsigned int polyVertCount, float *pPDist, UFG::qVector3 *pHitPos)
{
  UFG::qVector2 *v6; // rbx
  UFG::qVector2 *v7; // r14
  __int64 v8; // rsi
  UFG::qVector3 *v9; // rdi
  float v10; // xmm0_4
  float v11; // xmm1_4
  char result; // al
  float v13; // xmm6_4
  unsigned __int64 v14; // rbp
  UFG::qVector2 *v15; // r9
  float v16; // xmm4_4
  float v17; // xmm3_4
  float pdista_p; // [rsp+30h] [rbp-28h]

  v6 = (UFG::qVector2 *)pPolyVerts;
  v7 = (UFG::qVector2 *)endXY;
  v8 = polyVertCount;
  v9 = startXY;
  if ( UFG::qIsBoundPointPolyXY(startXY, pPolyVerts, polyVertCount) )
  {
    if ( pPDist )
      *pPDist = 0.0;
    if ( pHitPos )
    {
      v10 = v9->y;
      v11 = v9->z;
      pHitPos->x = v9->x;
      pHitPos->y = v10;
      pHitPos->z = v11;
    }
    result = 1;
  }
  else
  {
    v13 = FLOAT_3_4028235e38;
    v14 = (unsigned __int64)v6 + 12 * v8;
    v15 = (UFG::qVector2 *)((char *)v6 + 12 * (unsigned int)(v8 - 1));
    if ( (unsigned __int64)v6 >= v14 )
      goto LABEL_21;
    do
    {
      if ( UFG::qIntersectSegSeg2D((UFG::qVector2 *)v9, v7, v6, v15, &pdista_p, 0i64) && pdista_p < v13 )
        v13 = pdista_p;
      v15 = v6;
      v6 = (UFG::qVector2 *)((char *)v6 + 12);
    }
    while ( (unsigned __int64)v6 < v14 );
    if ( v13 == 3.4028235e38 )
    {
LABEL_21:
      result = 0;
    }
    else
    {
      if ( pPDist )
        *pPDist = v13;
      if ( pHitPos )
      {
        v16 = (float)((float)(v7->y - v9->y) * v13) + v9->y;
        v17 = (float)((float)(v7[1].x - v9->z) * v13) + v9->z;
        pHitPos->x = (float)((float)(v7->x - v9->x) * v13) + v9->x;
        pHitPos->y = v16;
        pHitPos->z = v17;
      }
      result = 1;
    }
  }
  return result;
}

// File Line: 679
// RVA: 0x185010
signed __int64 __fastcall UFG::qIntersectPlanePlane(UFG::qVector4 *plane1, UFG::qVector4 *plane2, UFG::qVector3 *ray_pos, UFG::qVector3 *ray_dir)
{
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm6_4
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
  signed __int64 result; // rax
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

  v4 = plane1->x;
  v5 = plane1->z;
  v6 = plane1->y;
  v7 = plane2->x;
  v8 = plane2->y;
  v9 = plane2->z;
  v10 = LODWORD(plane1->w) ^ _xmm[0];
  v11 = LODWORD(plane2->w) ^ _xmm[0];
  v12 = 1.0 / (float)((float)((float)(v6 * v6) + (float)(v4 * v4)) + (float)(plane1->z * v5));
  v13 = (float)(*(float *)&v10 * plane1->x) * v12;
  v14 = (float)(*(float *)&v10 * v6) * v12;
  v15 = (float)(*(float *)&v10 * v5) * v12;
  v16 = 1.0 / (float)((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(plane2->z * v9));
  v17 = (float)(*(float *)&v11 * plane2->x) * v16;
  v18 = (float)(*(float *)&v11 * v8) * v16;
  v19 = (float)(*(float *)&v11 * v9) * v16;
  v38 = (float)(plane1->y * v9) - (float)(plane2->y * v5);
  v33 = (float)(plane2->x * v5) - (float)(plane1->x * v9);
  LODWORD(v20) = LODWORD(v33) & _xmm;
  v39 = (float)(plane1->x * v8) - (float)(plane2->x * v6);
  LODWORD(v21) = LODWORD(v38) & _xmm;
  LODWORD(v34) = LODWORD(v39) & _xmm;
  if ( (float)((float)(COERCE_FLOAT(LODWORD(v33) & _xmm) + COERCE_FLOAT(LODWORD(v38) & _xmm))
             + COERCE_FLOAT(LODWORD(v39) & _xmm)) < 0.000001 )
    return COERCE_FLOAT(COERCE_UNSIGNED_INT(
                          (float)((float)((float)(v17 - v13) * v4) + (float)((float)(v18 - v14) * v6))
                        + (float)((float)(v19 - v15) * v5)) & _xmm) < 0.000001;
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
  LODWORD(v25) = COERCE_UNSIGNED_INT((float)((float)(v13 * v4) + (float)(v14 * v6)) + (float)(v15 * v5)) ^ _xmm[0];
  v26 = v23 - 1;
  if ( !v26 )
  {
    v31 = (float)((float)(v5 * v24) - (float)(v9 * v25)) * (float)(1.0 / v38);
    v29 = (float)((float)(v8 * v25) - (float)(v6 * v24)) * (float)(1.0 / v38);
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
      v28 = (float)((float)(v7 * v25) - (float)(v4 * v24)) * (float)(1.0 / v39);
      v29 = 0.0;
      v30 = (float)((float)(v6 * v24) - (float)(v8 * v25)) * (float)(1.0 / v39);
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
  v30 = (float)((float)(v9 * v25) - (float)(v5 * v24)) * (float)(1.0 / v33);
  v29 = (float)((float)(v4 * v24) - (float)(v7 * v25)) * (float)(1.0 / v33);
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
signed __int64 __fastcall UFG::qIntersectRaySphere(UFG::qVector3 *ray_pos, UFG::qVector3 *ray_dir, UFG::qVector3 *origin, const float radius, UFG::qVector3 *entry_p, UFG::qVector3 *exit_p)
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  UFG::qVector3 *v8; // r9
  float v9; // xmm11_4
  float v10; // xmm8_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm14_4
  float v14; // xmm9_4
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

  v6 = origin->y;
  v7 = origin->z;
  v8 = ray_dir;
  v32 = ray_pos->z;
  v9 = ray_dir->x;
  v10 = v32;
  v11 = ray_dir->y;
  v12 = ray_dir->z;
  v13 = ray_pos->x;
  v14 = radius;
  v15 = origin->x;
  v16 = ray_pos->y;
  v17 = ray_pos->x;
  v18 = ray_pos->y;
  v19 = (float)((float)((float)(origin->x * ray_dir->x) + (float)(v6 * v11)) + (float)(v7 * v12))
      - (float)((float)((float)(ray_dir->y * v16) + (float)(ray_dir->x * ray_pos->x)) + (float)(ray_dir->z * v32));
  if ( v19 > 0.0 )
  {
    v20 = v19 / (float)((float)((float)(v9 * v9) + (float)(v11 * v11)) + (float)(v12 * v12));
    v17 = v13 + (float)(v9 * v20);
    v18 = v18 + (float)(v11 * v20);
    v10 = v32 + (float)(v12 * v20);
  }
  v21 = v14 * v14;
  v22 = (float)((float)((float)(v6 - v18) * (float)(v6 - v18)) + (float)((float)(v15 - v17) * (float)(v15 - v17)))
      + (float)((float)(v7 - v10) * (float)(v7 - v10));
  if ( v22 > v21 )
    return 0i64;
  v24 = 0;
  if ( v19 <= 0.0
    || (float)((float)((float)((float)(v6 - v16) * (float)(v6 - v16)) + (float)((float)(v15 - v13) * (float)(v15 - v13)))
             + (float)((float)(v7 - v32) * (float)(v7 - v32))) <= v21 )
  {
    entry_p->x = v13;
    entry_p->y = v16;
    entry_p->z = v32;
    if ( !exit_p )
      return 2i64;
    v24 = 1;
    if ( v19 <= 0.0 )
    {
      v25 = v8->y;
      v26 = v8->z;
      v27 = v19 / (float)((float)((float)(v8->x * v8->x) + (float)(v25 * v25)) + (float)(v26 * v26));
      v17 = v17 + (float)(v8->x * v27);
      v18 = v18 + (float)(v25 * v27);
      v10 = v10 + (float)(v26 * v27);
      v22 = (float)((float)((float)(origin->y - v18) * (float)(origin->y - v18))
                  + (float)((float)(origin->x - v17) * (float)(origin->x - v17)))
          + (float)((float)(origin->z - v10) * (float)(origin->z - v10));
    }
  }
  v28 = fsqrt(v21 - v22);
  v29 = v8->x * v28;
  v30 = v8->y * v28;
  v31 = v8->z * v28;
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
signed __int64 __fastcall UFG::qIntersectSegSphere(UFG::qVector3 *start, UFG::qVector3 *end, UFG::qVector3 *origin, float radius, UFG::qVector3 *entry_p, UFG::qVector3 *exit_p)
{
  UFG::qVector3 *v6; // rbx
  float v7; // xmm3_4
  float v8; // xmm13_4
  float v9; // xmm12_4
  float v10; // xmm14_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm11_4
  signed __int64 result; // rax
  unsigned int v16; // er9
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

  v6 = start;
  v7 = radius * radius;
  v8 = start->y;
  v9 = start->x;
  v10 = start->z;
  v11 = end->y - v8;
  v12 = end->x - start->x;
  v13 = end->z - v10;
  v14 = (float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v13 * v13);
  if ( v14 > 0.000001 )
  {
    v16 = 0;
    v17 = (float)((float)((float)(origin->y * v11) + (float)(origin->x * v12)) + (float)(origin->z * v13))
        - (float)((float)((float)(v9 * v12) + (float)(v8 * v11)) + (float)(v10 * v13));
    if ( v17 > 0.0 )
      v18 = (v17 < v14) + 2;
    else
      v18 = 1;
    v19 = v9;
    v20 = v8;
    v21 = v10;
    if ( v18 == 2 )
    {
      v19 = end->x;
      v20 = end->y;
      v21 = end->z;
    }
    else if ( v18 == 3 )
    {
      v21 = v10 + (float)((float)(v17 / v14) * v13);
      v19 = v9 + (float)((float)(v17 / v14) * v12);
      v20 = v8 + (float)((float)(v17 / v14) * v11);
    }
    v22 = (float)((float)((float)(origin->y - v20) * (float)(origin->y - v20))
                + (float)((float)(origin->x - v19) * (float)(origin->x - v19)))
        + (float)((float)(origin->z - v21) * (float)(origin->z - v21));
    if ( v22 <= v7 )
    {
      v23 = 0;
      if ( v18 == 1
        || (float)((float)((float)((float)(origin->y - v8) * (float)(origin->y - v8))
                         + (float)((float)(origin->x - v9) * (float)(origin->x - v9)))
                 + (float)((float)(origin->z - v10) * (float)(origin->z - v10))) <= v7 )
      {
        entry_p->x = v9;
        entry_p->y = v8;
        entry_p->z = v10;
        v23 = 1;
      }
      v24 = !exit_p
         || v18 == 2
         || (float)((float)((float)((float)(origin->y - end->y) * (float)(origin->y - end->y))
                          + (float)((float)(origin->x - end->x) * (float)(origin->x - end->x)))
                  + (float)((float)(origin->z - end->z) * (float)(origin->z - end->z))) <= v7;
      if ( v23 && v24 )
      {
        result = 4i64;
      }
      else
      {
        if ( v18 != 3 )
        {
          v21 = (float)((float)(v17 / v14) * v13) + v6->z;
          v19 = (float)((float)(v17 / v14) * v12) + v6->x;
          v20 = (float)((float)(v17 / v14) * v11) + v6->y;
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
        result = v16;
      }
    }
    else
    {
      result = 0i64;
    }
  }
  else if ( (float)((float)((float)((float)(v8 - origin->y) * (float)(v8 - origin->y))
                          + (float)((float)(v9 - origin->x) * (float)(v9 - origin->x)))
                  + (float)((float)(v10 - origin->z) * (float)(v10 - origin->z))) > v7 )
  {
    result = 0i64;
  }
  else
  {
    entry_p->x = v9;
    entry_p->y = v8;
    entry_p->z = v10;
    result = 4i64;
  }
  return result;
}i64;
  }
  else
  {
   

// File Line: 1220
// RVA: 0x185CB0
char __fastcall UFG::qIntersectSegCircleOrigin(UFG::qVector2 *start, UFG::qVector2 *end, const float radius, float *pPDist)
{
  float v4; // xmm6_4
  float v5; // xmm7_4
  float v6; // xmm3_4
  char result; // al
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm8_4
  float v11; // xmm9_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  char v14; // al
  float v15; // xmm2_4

  v4 = start->y;
  v5 = start->x;
  v6 = radius * radius;
  if ( (float)((float)(v5 * v5) + (float)(v4 * v4)) > (float)(radius * radius) )
  {
    v8 = end->x;
    v9 = end->y;
    v10 = end->x - v5;
    v11 = end->y - v4;
    v12 = (float)(v10 * v10) + (float)(v11 * v11);
    LODWORD(v13) = COERCE_UNSIGNED_INT((float)(v5 * v10) + (float)(v4 * v11)) ^ _xmm[0];
    if ( v13 <= 0.0
      || v12 <= 0.000001
      || ((v14 = 0, v13 < v12) ? (v9 = (float)((float)(v13 / v12) * v11) + v4,
                                  v8 = (float)((float)(v13 / v12) * v10) + v5) : (v14 = 1),
          v15 = (float)(v9 * v9) + (float)(v8 * v8),
          v15 > v6) )
    {
      result = 0;
    }
    else
    {
      if ( v14 )
        v15 = (float)((float)((float)((float)(v13 / v12) * v11) + v4) * (float)((float)((float)(v13 / v12) * v11) + v4))
            + (float)((float)((float)((float)(v13 / v12) * v10) + v5) * (float)((float)((float)(v13 / v12) * v10) + v5));
      result = 1;
      *pPDist = (float)((float)(1.0 / v12) * v13) - fsqrt((float)(v6 - v15) * (float)(1.0 / v12));
    }
  }
  else
  {
    *pPDist = 0.0;
    result = 1;
  }
  return result;
}

// File Line: 1375
// RVA: 0x185510
signed __int64 __fastcall UFG::qIntersectRaySlab(UFG::qVector3 *ray_pos, UFG::qVector3 *ray_dir, UFG::qVector3 *slab_normal, float slab_below, float slab_above, UFG::qVector3 *hit_enter_p, UFG::qVector3 *hit_exit_p)
{
  float v7; // xmm5_4
  float v8; // xmm7_4
  UFG::qVector3 *v9; // rbx
  UFG::qVector3 *v10; // rdi
  float v11; // xmm6_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  int v15; // er8
  float v16; // xmm4_4
  UFG::qVector3 *v17; // r11
  signed int v18; // edx
  UFG::qVector3 *v19; // r10
  float v20; // xmm5_4
  float v21; // xmm3_4
  float v22; // xmm6_4
  float v23; // xmm8_4
  signed __int64 result; // rax
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm7_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm0_4

  v7 = ray_pos->y;
  v8 = slab_below;
  v9 = slab_normal;
  v10 = ray_dir;
  v11 = ray_pos->z;
  v12 = ray_pos->y * slab_normal->y;
  v13 = ray_pos->x * slab_normal->x;
  v14 = v11 * slab_normal->z;
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
    hit_enter_p->y = v7;
    hit_enter_p->z = v11;
  }
  else
  {
    v17 = hit_enter_p;
    v18 = 0;
  }
  v19 = hit_exit_p;
LABEL_7:
  v20 = v10->y;
  v21 = v10->x;
  v22 = v10->z;
  v23 = (float)((float)(v10->y * v9->y) + (float)(v10->x * v9->x)) + (float)(v10->z * v9->z);
  if ( v23 == 0.0 )
  {
    if ( v18 == 1 )
    {
      result = 4i64;
      v25 = (float)(v20 * 10000.0) + ray_pos->y;
      v26 = (float)(v22 * 10000.0) + ray_pos->z;
      hit_exit_p->x = (float)(v21 * 10000.0) + ray_pos->x;
      hit_exit_p->y = v25;
      hit_exit_p->z = v26;
      return result;
    }
    return 0i64;
  }
  v27 = (float)(v8 - v16) * (float)(1.0 / v23);
  if ( v27 >= 0.0 )
  {
    v28 = (float)(v20 * v27) + ray_pos->y;
    v29 = (float)(v22 * v27) + ray_pos->z;
    v17->x = (float)(v21 * v27) + ray_pos->x;
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
    v31 = (float)(v30 * v10->x) + ray_pos->x;
    v32 = (float)(v30 * v10->y) + ray_pos->y;
    v19->z = (float)(v30 * v10->z) + ray_pos->z;
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
signed __int64 __fastcall UFG::qIntersectRaySlabZ(UFG::qVector3 *ray_pos, UFG::qVector3 *ray_dir, float slab_below, float slab_above, UFG::qVector3 *hit_enter_p, UFG::qVector3 *hit_exit_p)
{
  float v6; // xmm6_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm4_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm7_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm5_4
  float v30; // xmm2_4
  float v31; // xmm2_4
  float v32; // eax
  float v33; // xmm5_4
  float v34; // xmm2_4
  float v35; // xmm4_4

  v6 = ray_pos->z;
  v7 = slab_above;
  v8 = ray_dir->z;
  if ( v8 == 0.0 )
  {
    if ( slab_below <= v6 && v6 <= v7 )
    {
      v9 = ray_pos->y;
      hit_enter_p->x = ray_pos->x;
      hit_enter_p->y = v9;
      hit_enter_p->z = v6;
      v10 = (float)(ray_dir->y * 10000.0) + ray_pos->y;
      v11 = (float)(ray_dir->z * 10000.0) + ray_pos->z;
      hit_exit_p->x = (float)(ray_dir->x * 10000.0) + ray_pos->x;
      hit_exit_p->y = v10;
      hit_exit_p->z = v11;
      return 4i64;
    }
    return 0i64;
  }
  if ( v6 < slab_below )
  {
    if ( v8 >= 0.0 )
    {
      v13 = 1.0 / v8;
      v14 = (float)(slab_below - v6) * ray_dir->x;
      v15 = (float)(slab_below - v6) * v8;
      v16 = v7 - v6;
      v17 = (float)((float)(1.0 / v8) * (float)((float)(slab_below - v6) * ray_dir->y)) + ray_pos->y;
      hit_enter_p->x = (float)((float)(1.0 / v8) * v14) + ray_pos->x;
      hit_enter_p->y = v17;
      v18 = v13;
      v19 = v13;
      hit_enter_p->z = (float)(v13 * v15) + v6;
      v20 = v7 - v6;
      v21 = v13 * (float)((float)(v7 - v6) * ray_dir->z);
LABEL_9:
      v22 = (float)(v18 * (float)(v16 * ray_dir->x)) + ray_pos->x;
      v23 = (float)(v19 * (float)(v20 * ray_dir->y)) + ray_pos->y;
      hit_exit_p->z = v21 + ray_pos->z;
      hit_exit_p->x = v22;
      hit_exit_p->y = v23;
      return 3i64;
    }
    return 0i64;
  }
  if ( v6 > v7 )
  {
    if ( v8 <= 0.0 )
    {
      v24 = v7 - v6;
      v25 = 1.0 / v8;
      v26 = slab_below - v6;
      v27 = v24 * ray_dir->x;
      v28 = v24 * ray_dir->y;
      v29 = v24 * v8;
      v30 = (float)(1.0 / v8) * v28;
      v16 = v26;
      v31 = v30 + ray_pos->y;
      hit_enter_p->x = (float)((float)(1.0 / v8) * v27) + ray_pos->x;
      hit_enter_p->y = v31;
      v18 = v25;
      v19 = v25;
      hit_enter_p->z = (float)(v25 * v29) + v6;
      v20 = v26;
      v21 = v25 * (float)(v26 * ray_dir->z);
      goto LABEL_9;
    }
    return 0i64;
  }
  if ( v8 <= 0.0 )
    v7 = slab_below;
  v32 = ray_pos->x;
  v33 = v7 - v6;
  hit_enter_p->y = ray_pos->y;
  hit_enter_p->z = v6;
  hit_enter_p->x = v32;
  v34 = (float)((float)(1.0 / v8) * (float)(v33 * ray_dir->y)) + ray_pos->y;
  v35 = (float)((float)(1.0 / v8) * (float)(v33 * ray_dir->z)) + ray_pos->z;
  hit_exit_p->x = (float)((float)(1.0 / v8) * (float)(v33 * ray_dir->x)) + ray_pos->x;
  hit_exit_p->y = v34;
  hit_exit_p->z = v35;
  return 2i64;
}

// File Line: 1659
// RVA: 0x186120
signed __int64 __fastcall UFG::qIntersectSegSlab(UFG::qVector3 *start, UFG::qVector3 *end, UFG::qVector3 *slab_normal, float slab_below, float slab_above, UFG::qVector3 *hit_enter_p, UFG::qVector3 *hit_exit_p)
{
  float v7; // xmm5_4
  signed __int64 result; // rax
  UFG::qVector3 *v9; // rbx
  UFG::qVector3 *v10; // r9
  UFG::qVector3 *v11; // r11
  float v12; // xmm6_4
  unsigned int v13; // edx
  float v14; // xmm4_4
  signed int v15; // ecx
  float v16; // xmm6_4
  float v17; // xmm7_4
  UFG::qVector3 *v18; // r10
  float v19; // xmm2_4
  signed int v20; // er8
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

  v7 = start->y;
  result = 0i64;
  v9 = end;
  v10 = slab_normal;
  v11 = start;
  v12 = start->z;
  v13 = 2;
  v14 = (float)((float)(start->y * slab_normal->y) + (float)(start->x * slab_normal->x))
      + (float)(start->z * slab_normal->z);
  if ( v14 >= slab_below )
  {
    if ( v14 <= slab_above )
    {
      hit_enter_p->x = start->x;
      hit_enter_p->y = v7;
      hit_enter_p->z = v12;
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
  v16 = v9->y;
  v17 = v9->z;
  v18 = hit_exit_p;
  v19 = (float)((float)(v9->y * slab_normal->y) + (float)(v9->x * slab_normal->x)) + (float)(v9->z * slab_normal->z);
  if ( v19 >= slab_below )
  {
    if ( v19 <= slab_above )
    {
      hit_exit_p->x = v9->x;
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
      result = 4i64;
  }
  else
  {
    v21 = v9->x - v11->x;
    v22 = v9->y - v11->y;
    v23 = v9->z - v11->z;
    v24 = (float)((float)(v21 * v10->x) + (float)(v22 * v10->y)) + (float)(v23 * v10->z);
    if ( !v15 || !v20 )
    {
      v25 = hit_exit_p;
      if ( !v15 )
        v25 = hit_enter_p;
      v26 = (float)(slab_below - v14) / v24;
      v27 = (float)(v22 * v26) + v11->y;
      v28 = (float)(v23 * v26) + v11->z;
      v25->x = (float)(v21 * v26) + v11->x;
      v25->y = v27;
      v25->z = v28;
    }
    if ( v15 == 2 || v20 == 2 )
    {
      if ( v15 == 2 )
        v18 = hit_enter_p;
      v29 = (float)(slab_above - v14) / v24;
      v30 = (float)(v22 * v29) + v11->y;
      v31 = (float)(v23 * v29) + v11->z;
      v18->x = (float)(v21 * v29) + v11->x;
      v18->y = v30;
      v18->z = v31;
    }
    if ( v15 != 1 )
    {
      v13 = 3;
      if ( v20 == 1 )
        v13 = 1;
    }
    result = v13;
  }
  return result;
}

