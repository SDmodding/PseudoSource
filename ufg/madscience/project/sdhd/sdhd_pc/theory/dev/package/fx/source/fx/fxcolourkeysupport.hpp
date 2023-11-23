// File Line: 12
// RVA: 0x1E0E00
float __fastcall Render::ComputeInterpolatedAlpha(const float (*colourAlphaKeys)[4], float *keyPos, float lifetime)
{
  float v4; // xmm9_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  int v7; // ecx
  int v8; // r8d
  float v9; // xmm1_4

  v4 = lifetime;
  if ( lifetime <= *keyPos )
    v4 = *keyPos;
  v5 = keyPos[3];
  if ( v4 >= v5 )
    v4 = keyPos[3];
  v6 = keyPos[1];
  v7 = 0;
  if ( v4 < v6 || (v8 = 1, v4 >= keyPos[2]) )
    v8 = 0;
  v9 = keyPos[2];
  LOBYTE(v7) = v4 >= v9;
  return (float)((float)((float)((float)((float)((float)(*colourAlphaKeys)[11] - (float)(*colourAlphaKeys)[7])
                                       * (float)((float)(v4 - v6) / (float)(v9 - v6)))
                               + (float)(*colourAlphaKeys)[7])
                       * (float)v8)
               + (float)((float)((float)((float)((float)(*colourAlphaKeys)[7] - (float)(*colourAlphaKeys)[3])
                                       * (float)((float)(v4 - *keyPos) / (float)(v6 - *keyPos)))
                               + (float)(*colourAlphaKeys)[3])
                       * (float)(v6 > v4)))
       + (float)((float)((float)((float)((float)(*colourAlphaKeys)[15] - (float)(*colourAlphaKeys)[11])
                               * (float)((float)(v4 - v9) / (float)(v5 - v9)))
                       + (float)(*colourAlphaKeys)[11])
               * (float)v7);
}

// File Line: 32
// RVA: 0x1E4CC0
float __fastcall Render::ComputeInterpolatedAlpha(UFG::qColour *colourAlphaKeys, float *keyPos, float lifetime)
{
  float g; // xmm1_4
  float b; // xmm0_4
  float a; // xmm1_4
  float r; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v19[18]; // [rsp+20h] [rbp-48h] BYREF

  g = colourAlphaKeys->g;
  v19[0] = colourAlphaKeys->r;
  b = colourAlphaKeys->b;
  v19[1] = g;
  a = colourAlphaKeys->a;
  v19[2] = b;
  r = colourAlphaKeys[1].r;
  v19[3] = a;
  v7 = colourAlphaKeys[1].g;
  v19[4] = r;
  v8 = colourAlphaKeys[1].b;
  v19[5] = v7;
  v9 = colourAlphaKeys[1].a;
  v19[6] = v8;
  v10 = colourAlphaKeys[2].r;
  v19[7] = v9;
  v11 = colourAlphaKeys[2].g;
  v19[8] = v10;
  v12 = colourAlphaKeys[2].b;
  v19[9] = v11;
  v13 = colourAlphaKeys[2].a;
  v19[10] = v12;
  v14 = colourAlphaKeys[3].r;
  v19[11] = v13;
  v15 = colourAlphaKeys[3].g;
  v19[12] = v14;
  v16 = colourAlphaKeys[3].b;
  v19[13] = v15;
  v17 = colourAlphaKeys[3].a;
  v19[14] = v16;
  v19[15] = v17;
  return Render::ComputeInterpolatedAlpha((const float (*)[4])v19, keyPos, lifetime);
}

// File Line: 59
// RVA: 0x1E4D80
UFG::qColour *__fastcall Render::ComputeInterpolatedColour(
        UFG::qColour *result,
        UFG::qColour *colourAlphaKeys,
        float *colourKeyPos,
        float *alphaKeyPos,
        float lifetime)
{
  float v5; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm6_4
  int v11; // ecx
  int v12; // edx
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float r; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm7_4
  float b; // xmm6_4
  float v21; // xmm15_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  float v26; // xmm15_4
  float v27; // xmm0_4
  UFG::qColour *v28; // rax
  float v29; // [rsp+28h] [rbp-80h]
  float v30; // [rsp+B0h] [rbp+8h]
  float v31; // [rsp+B8h] [rbp+10h]

  v5 = *colourKeyPos;
  if ( lifetime <= *colourKeyPos )
    v8 = *colourKeyPos;
  else
    v8 = lifetime;
  v9 = colourKeyPos[3];
  if ( v8 >= v9 )
    v8 = colourKeyPos[3];
  v10 = colourKeyPos[1];
  v11 = 0;
  if ( v8 < v10 || (v12 = 1, v8 >= colourKeyPos[2]) )
    v12 = 0;
  v13 = colourKeyPos[2];
  v14 = v8;
  v15 = v8 - v5;
  LOBYTE(v11) = v8 >= v13;
  v29 = (float)(v10 > v8);
  v16 = (float)(v8 - v13) / (float)(v9 - v13);
  r = colourAlphaKeys[1].r;
  v18 = v15 / (float)(v10 - v5);
  v19 = (float)(v14 - v10) / (float)(v13 - v10);
  b = colourAlphaKeys[1].b;
  v21 = (float)(b - colourAlphaKeys->b) * v18;
  v30 = (float)((float)(colourAlphaKeys[1].g - colourAlphaKeys->g) * v18) + colourAlphaKeys->g;
  v31 = (float)((float)(r - colourAlphaKeys->r) * v18) + colourAlphaKeys->r;
  v22 = (float)((float)((float)(colourAlphaKeys[2].g - colourAlphaKeys[1].g) * v19) + colourAlphaKeys[1].g) * (float)v12;
  v23 = (float)((float)(colourAlphaKeys[2].b - b) * v19) + b;
  v24 = (float)((float)(v31 * v29) + (float)((float)((float)((float)(colourAlphaKeys[2].r - r) * v19) + r) * (float)v12))
      + (float)((float)((float)((float)(colourAlphaKeys[3].r - colourAlphaKeys[2].r) * v16) + colourAlphaKeys[2].r)
              * (float)v11);
  v25 = (float)((float)(v30 * v29) + v22)
      + (float)((float)((float)((float)(colourAlphaKeys[3].g - colourAlphaKeys[2].g) * v16) + colourAlphaKeys[2].g)
              * (float)v11);
  v26 = (float)((float)((float)(v21 + colourAlphaKeys->b) * v29) + (float)(v23 * (float)v12))
      + (float)((float)((float)((float)(colourAlphaKeys[3].b - colourAlphaKeys[2].b) * v16) + colourAlphaKeys[2].b)
              * (float)v11);
  v27 = Render::ComputeInterpolatedAlpha(colourAlphaKeys, alphaKeyPos, lifetime);
  v28 = result;
  result->r = v24;
  result->g = v25;
  result->b = v26;
  result->a = v27;
  return v28;
}

