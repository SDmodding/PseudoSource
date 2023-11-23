// File Line: 37
// RVA: 0x1E8880
__int64 __fastcall ClipToSlab(
        UFG::qVector4 *inpts,
        UFG::qVector4 *outpts,
        unsigned int numpts,
        UFG::qVector3 *axis,
        float width)
{
  unsigned int v5; // r10d
  int v6; // r11d
  int v8; // xmm10_4
  unsigned int v9; // esi
  float x; // xmm11_4
  float y; // xmm12_4
  float z; // xmm13_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  int v17; // eax
  float v18; // xmm2_4
  int v19; // edx
  float w; // xmm0_4
  UFG::qVector4 *v21; // rax
  float v22; // xmm4_4
  float v23; // xmm4_4
  UFG::qVector4 *v24; // rax
  float v25; // xmm8_4
  float v26; // xmm8_4
  UFG::qVector4 *v27; // rax
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm7_4

  v5 = 0;
  v6 = 0;
  if ( !numpts )
    return v5;
  v8 = LODWORD(width) ^ _xmm[0];
  while ( 1 )
  {
    v9 = v6 + 1;
    x = inpts[v6].x;
    y = inpts[v6].y;
    z = inpts[v6].z;
    v13 = (float)((float)(axis->x * x) + (float)(axis->y * y)) + (float)(axis->z * z);
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
    if ( !v17 )
    {
      if ( v5 == 128 )
        return 0i64;
      w = inpts[v6].w;
      v21 = &outpts[v5];
      v21->x = x;
      v21->y = y;
      v21->z = z;
      v21->w = w;
      goto LABEL_20;
    }
    if ( v17 == v19 )
      goto LABEL_26;
    if ( v17 == 1 )
      LODWORD(v22) = LODWORD(width) ^ _xmm[0];
    else
      v22 = width;
    v23 = (float)(v22 - v13) / (float)(v18 - v13);
    if ( v5 == 128 )
      return 0i64;
    v24 = &outpts[v5];
    v24->w = (float)((float)(inpts[(v6 + 1) % numpts].w - inpts[v6].w) * v23) + inpts[v6].w;
    v24->z = (float)((float)(v16 - z) * v23) + z;
    v24->y = (float)((float)(v15 - y) * v23) + y;
    v24->x = (float)((float)(v14 - x) * v23) + x;
LABEL_20:
    ++v5;
    if ( v19 == 1 )
    {
      LODWORD(v25) = LODWORD(width) ^ _xmm[0];
    }
    else
    {
      if ( v19 != 2 )
        goto LABEL_26;
      v25 = width;
    }
    v26 = (float)(v25 - v13) / (float)(v18 - v13);
    if ( v5 == 128 )
      return 0i64;
    v27 = &outpts[v5++];
    v28 = (float)((float)(inpts[(v6 + 1) % numpts].z - inpts[v6].z) * v26) + inpts[v6].z;
    v29 = (float)((float)(inpts[(v6 + 1) % numpts].y - inpts[v6].y) * v26) + inpts[v6].y;
    v30 = (float)((float)(inpts[(v6 + 1) % numpts].x - inpts[v6].x) * v26) + inpts[v6].x;
    v27->w = (float)((float)(inpts[(v6 + 1) % numpts].w - inpts[v6].w) * v26) + inpts[v6].w;
    v27->z = v28;
    v27->y = v29;
    v27->x = v30;
LABEL_26:
    ++v6;
    if ( v9 >= numpts )
      return v5;
  }
}

