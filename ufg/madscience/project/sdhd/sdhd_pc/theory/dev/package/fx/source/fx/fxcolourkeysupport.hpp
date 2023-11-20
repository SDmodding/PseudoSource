// File Line: 12
// RVA: 0x1E0E00
float __fastcall Render::ComputeInterpolatedAlpha(const float (*colourAlphaKeys)[4], const float *keyPos, float lifetime)
{
  float *v3; // r9
  float v4; // xmm9_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  signed int v7; // ecx
  signed int v8; // er8
  float v9; // xmm1_4

  v3 = (float *)colourAlphaKeys;
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
  return (float)((float)((float)((float)((float)(v3[11] - v3[7]) * (float)((float)(v4 - v6) / (float)(keyPos[2] - v6)))
                               + v3[7])
                       * (float)v8)
               + (float)((float)((float)((float)(v3[7] - v3[3]) * (float)((float)(v4 - *keyPos) / (float)(v6 - *keyPos)))
                               + v3[3])
                       * (float)(v6 > v4)))
       + (float)((float)((float)((float)(v3[15] - v3[11]) * (float)((float)(v4 - v9) / (float)(v5 - v9))) + v3[11])
               * (float)v7);
}

// File Line: 32
// RVA: 0x1E4CC0
float __fastcall Render::ComputeInterpolatedAlpha(UFG::qColour *colourAlphaKeys, const float *keyPos, float lifetime)
{
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
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
  float v19; // [rsp+20h] [rbp-48h]
  float v20; // [rsp+24h] [rbp-44h]
  float v21; // [rsp+28h] [rbp-40h]
  float v22; // [rsp+2Ch] [rbp-3Ch]
  float v23; // [rsp+30h] [rbp-38h]
  float v24; // [rsp+34h] [rbp-34h]
  float v25; // [rsp+38h] [rbp-30h]
  float v26; // [rsp+3Ch] [rbp-2Ch]
  float v27; // [rsp+40h] [rbp-28h]
  float v28; // [rsp+44h] [rbp-24h]
  float v29; // [rsp+48h] [rbp-20h]
  float v30; // [rsp+4Ch] [rbp-1Ch]
  float v31; // [rsp+50h] [rbp-18h]
  float v32; // [rsp+54h] [rbp-14h]
  float v33; // [rsp+58h] [rbp-10h]
  float v34; // [rsp+5Ch] [rbp-Ch]

  v3 = colourAlphaKeys->g;
  v19 = colourAlphaKeys->r;
  v4 = colourAlphaKeys->b;
  v20 = v3;
  v5 = colourAlphaKeys->a;
  v21 = v4;
  v6 = colourAlphaKeys[1].r;
  v22 = v5;
  v7 = colourAlphaKeys[1].g;
  v23 = v6;
  v8 = colourAlphaKeys[1].b;
  v24 = v7;
  v9 = colourAlphaKeys[1].a;
  v25 = v8;
  v10 = colourAlphaKeys[2].r;
  v26 = v9;
  v11 = colourAlphaKeys[2].g;
  v27 = v10;
  v12 = colourAlphaKeys[2].b;
  v28 = v11;
  v13 = colourAlphaKeys[2].a;
  v29 = v12;
  v14 = colourAlphaKeys[3].r;
  v30 = v13;
  v15 = colourAlphaKeys[3].g;
  v31 = v14;
  v16 = colourAlphaKeys[3].b;
  v32 = v15;
  v17 = colourAlphaKeys[3].a;
  v33 = v16;
  v34 = v17;
  return Render::ComputeInterpolatedAlpha((const float (*)[4])&v19, keyPos, lifetime);
}

// File Line: 59
// RVA: 0x1E4D80
UFG::qColour *__fastcall Render::ComputeInterpolatedColour(UFG::qColour *result, UFG::qColour *colourAlphaKeys, const float *colourKeyPos, const float *alphaKeyPos, float lifetime)
{
  float v5; // xmm5_4
  UFG::qColour *v6; // r10
  UFG::qColour *v7; // rbx
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm6_4
  signed int v11; // ecx
  signed int v12; // edx
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm3_4
  bool v16; // al
  float v17; // xmm2_4
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm15_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm7_4
  float v26; // xmm6_4
  float v27; // xmm15_4
  float v28; // xmm0_4
  UFG::qColour *v29; // rax
  float v30; // [rsp+B0h] [rbp+8h]
  float v31; // [rsp+B8h] [rbp+10h]

  v5 = *colourKeyPos;
  v6 = colourAlphaKeys;
  v7 = result;
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
  v16 = v10 > v8;
  LOBYTE(v11) = v8 >= v13;
  v17 = (float)(v8 - v13) / (float)(v9 - v13);
  v18 = v6[1].r;
  v19 = v15 / (float)(v10 - v5);
  v20 = (float)(v14 - v10) / (float)(colourKeyPos[2] - v10);
  v21 = v6[1].b;
  v22 = (float)(v21 - v6->b) * v19;
  v30 = (float)((float)(v6[1].g - v6->g) * v19) + v6->g;
  v31 = (float)((float)(v18 - v6->r) * v19) + v6->r;
  v23 = (float)((float)((float)(v6[2].g - v6[1].g) * v20) + v6[1].g) * (float)v12;
  v24 = (float)((float)(v6[2].b - v21) * v20) + v21;
  v25 = (float)((float)(v31 * (float)v16) + (float)((float)((float)((float)(v6[2].r - v18) * v20) + v18) * (float)v12))
      + (float)((float)((float)((float)(v6[3].r - v6[2].r) * v17) + v6[2].r) * (float)v11);
  v26 = (float)((float)(v30 * (float)v16) + v23)
      + (float)((float)((float)((float)(v6[3].g - v6[2].g) * v17) + v6[2].g) * (float)v11);
  v27 = (float)((float)((float)(v22 + v6->b) * (float)v16) + (float)(v24 * (float)v12))
      + (float)((float)((float)((float)(v6[3].b - v6[2].b) * v17) + v6[2].b) * (float)v11);
  v28 = Render::ComputeInterpolatedAlpha(v6, alphaKeyPos, lifetime);
  v29 = v7;
  v7->r = v25;
  v7->g = v26;
  v7->b = v27;
  v7->a = v28;
  return v29;
}

