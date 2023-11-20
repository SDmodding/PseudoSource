// File Line: 37
// RVA: 0x1E8880
__int64 __fastcall ClipToSlab(UFG::qVector4 *inpts, UFG::qVector4 *outpts, unsigned int numpts, UFG::qVector3 *axis, float width)
{
  unsigned int v5; // er10
  int v6; // er11
  UFG::qVector4 *v7; // rbx
  int v8; // xmm10_4
  unsigned int v9; // esi
  float v10; // xmm11_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  signed int v17; // eax
  float v18; // xmm2_4
  signed int v19; // edx
  float v20; // xmm0_4
  signed __int64 v21; // rax
  float v22; // xmm4_4
  float v23; // xmm4_4
  float *v24; // rax
  float v25; // xmm8_4
  float v26; // xmm8_4
  float *v27; // rax
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm7_4

  v5 = 0;
  v6 = 0;
  v7 = outpts;
  if ( !numpts )
    return v5;
  v8 = LODWORD(width) ^ _xmm[0];
  while ( 1 )
  {
    v9 = v6 + 1;
    v10 = inpts[v6].x;
    v11 = inpts[v6].y;
    v12 = inpts[v6].z;
    v13 = (float)((float)(axis->x * v10) + (float)(axis->y * v11)) + (float)(axis->z * v12);
    v14 = inpts[(v6 + 1) % numpts].x;
    v15 = inpts[(v6 + 1) % numpts].y;
    v16 = inpts[(v6 + 1) % numpts].z;
    if ( v13 >= *(float *)&v8 )
    {
      v17 = 0;
      if ( v13 > width )
        v17 = 2;
    }
    else
    {
      v17 = 1;
    }
    v18 = (float)((float)(axis->x * v14) + (float)(axis->y * v15)) + (float)(axis->z * v16);
    if ( v18 >= *(float *)&v8 )
    {
      v19 = 0;
      if ( v18 > width )
        v19 = 2;
    }
    else
    {
      v19 = 1;
    }
    if ( v17 )
    {
      if ( v17 == v19 )
        goto LABEL_28;
      if ( v17 == 1 )
      {
        LODWORD(v22) = LODWORD(width) ^ _xmm[0];
      }
      else
      {
        if ( v17 != 2 )
          goto LABEL_22;
        v22 = width;
      }
      v23 = (float)(v22 - v13) / (float)(v18 - v13);
      if ( v5 == 128 )
        return 0i64;
      v24 = &v7[v5].x;
      v24[3] = (float)((float)(inpts[(v6 + 1) % numpts].w - inpts[v6].w) * v23) + inpts[v6].w;
      v24[2] = (float)((float)(v16 - v12) * v23) + v12;
      v24[1] = (float)((float)(v15 - v11) * v23) + v11;
      *v24 = (float)((float)(v14 - v10) * v23) + v10;
    }
    else
    {
      if ( v5 == 128 )
        return 0i64;
      v20 = inpts[v6].w;
      v21 = (signed __int64)&v7[v5];
      *(float *)v21 = v10;
      *(float *)(v21 + 4) = v11;
      *(float *)(v21 + 8) = v12;
      *(float *)(v21 + 12) = v20;
    }
    ++v5;
LABEL_22:
    if ( v19 == 1 )
    {
      LODWORD(v25) = LODWORD(width) ^ _xmm[0];
      goto LABEL_26;
    }
    if ( v19 == 2 )
      break;
LABEL_28:
    ++v6;
    if ( v9 >= numpts )
      return v5;
  }
  v25 = width;
LABEL_26:
  v26 = (float)(v25 - v13) / (float)(v18 - v13);
  if ( v5 != 128 )
  {
    v27 = &v7[v5++].x;
    v28 = (float)((float)(inpts[(v6 + 1) % numpts].z - inpts[v6].z) * v26) + inpts[v6].z;
    v29 = (float)((float)(inpts[(v6 + 1) % numpts].y - inpts[v6].y) * v26) + inpts[v6].y;
    v30 = (float)((float)(inpts[(v6 + 1) % numpts].x - inpts[v6].x) * v26) + inpts[v6].x;
    v27[3] = (float)((float)(inpts[(v6 + 1) % numpts].w - inpts[v6].w) * v26) + inpts[v6].w;
    v27[2] = v28;
    v27[1] = v29;
    *v27 = v30;
    goto LABEL_28;
  }
  return 0i64;
}

