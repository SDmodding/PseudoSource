// File Line: 34
// RVA: 0x3B9E60
UFG::qVector3 *__fastcall UFG::NoiseInterpolated<UFG::qVector3>(UFG::qVector3 *result, float *x, bool circular)
{
  float v3; // xmm6_4
  __m128 v5; // xmm1
  int v6; // edx
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  int v10; // eax
  int v11; // eax
  UFG::qVector3 *v12; // rax
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  UFG::qVector3 v17; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 resulta; // [rsp+30h] [rbp-38h] BYREF
  float v19; // [rsp+70h] [rbp+8h] BYREF
  float xa; // [rsp+80h] [rbp+18h] BYREF

  v3 = *x;
  v5 = (__m128)*(unsigned int *)x;
  v6 = (int)v5.m128_f32[0];
  if ( (int)v5.m128_f32[0] != 0x80000000 && (float)v6 != v5.m128_f32[0] )
    v5.m128_f32[0] = (float)(v6 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
  xa = v5.m128_f32[0];
  v19 = v5.m128_f32[0] + 1.0;
  v7 = (float)(v5.m128_f32[0] + 1.0) - v3;
  v8 = v3 - v5.m128_f32[0];
  if ( circular )
  {
    v9 = sinf(v8 * 1.5707964);
    v8 = v9 * v9;
    v7 = 1.0 - (float)(v9 * v9);
  }
  v10 = UFG::NoiseSeed<float>(&xa);
  UFG::NoiseRandom<UFG::qVector3>(&resulta, v10);
  v11 = UFG::NoiseSeed<float>(&v19);
  UFG::NoiseRandom<UFG::qVector3>(&v17, v11);
  v12 = result;
  v13 = v17.y * v8;
  v14 = v17.z * v8;
  v15 = resulta.y * v7;
  v16 = resulta.z * v7;
  result->x = (float)(resulta.x * v7) + (float)(v17.x * v8);
  result->y = v15 + v13;
  result->z = v16 + v14;
  return v12;
}

// File Line: 90
// RVA: 0x3B9F90
UFG::qVector3 *__fastcall UFG::NoiseInterpolated<UFG::qVector3>(UFG::qVector3 *result, UFG::qVector3 *v, bool circular)
{
  float x; // xmm3_4
  float y; // xmm7_4
  float z; // xmm8_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm3_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm9_4
  float v16; // xmm7_4
  float v17; // xmm0_4
  int v18; // eax
  UFG::qVector3 *v19; // rax
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm8_4
  int v23; // eax
  UFG::qVector3 *v24; // rax
  float v25; // xmm9_4
  float v26; // xmm10_4
  float v27; // xmm12_4
  int v28; // eax
  UFG::qVector3 *v29; // rax
  float v30; // xmm11_4
  float v31; // xmm13_4
  float v32; // xmm15_4
  int v33; // eax
  UFG::qVector3 *v34; // rax
  float v35; // xmm1_4
  float v36; // xmm14_4
  int v37; // eax
  int *v38; // rax
  float v39; // xmm1_4
  float v40; // xmm2_4
  int v41; // eax
  int *v42; // rax
  float v43; // xmm1_4
  float v44; // xmm2_4
  int v45; // eax
  int *v46; // rax
  float v47; // xmm1_4
  float v48; // xmm2_4
  int v49; // eax
  UFG::qVector3 *v50; // rax
  float v51; // xmm2_4
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm3_4
  float v55; // xmm14_4
  float v56; // xmm4_4
  float v57; // xmm6_4
  float v58; // xmm7_4
  float v59; // xmm5_4
  float v60; // xmm0_4
  float v61; // xmm2_4
  float v62; // xmm1_4
  float v63; // xmm3_4
  float v64; // xmm6_4
  float v65; // xmm7_4
  float v66; // xmm4_4
  float v67; // xmm1_4
  float v68; // xmm0_4
  UFG::qVector3 *v69; // rax
  float v70; // xmm5_4
  float v71; // xmm0_4
  UFG::qVector3 va; // [rsp+20h] [rbp-C0h] BYREF
  UFG::qVector3 resulta; // [rsp+30h] [rbp-B0h] BYREF
  UFG::qVector3 v74; // [rsp+40h] [rbp-A0h] BYREF
  float v75; // [rsp+50h] [rbp-90h]
  float v76; // [rsp+54h] [rbp-8Ch]
  UFG::qVector3 v77; // [rsp+58h] [rbp-88h] BYREF
  float v78; // [rsp+64h] [rbp-7Ch]
  float v79; // [rsp+68h] [rbp-78h]
  float v80; // [rsp+6Ch] [rbp-74h]
  float v81; // [rsp+70h] [rbp-70h]
  float v82; // [rsp+74h] [rbp-6Ch]
  float v83; // [rsp+78h] [rbp-68h]
  float v84; // [rsp+7Ch] [rbp-64h]
  float v85; // [rsp+140h] [rbp+60h]
  float v86; // [rsp+148h] [rbp+68h]
  float vars0; // [rsp+150h] [rbp+70h]
  void *retaddr; // [rsp+158h] [rbp+78h]

  UFG::qFloor(&resulta, v);
  x = v->x;
  y = v->y;
  z = v->z;
  v74.x = resulta.x + 1.0;
  v9 = (float)(resulta.x + 1.0) - x;
  v74.y = resulta.y + 1.0;
  v10 = (float)(resulta.y + 1.0) - y;
  v74.z = resulta.z + 1.0;
  v11 = (float)(resulta.z + 1.0) - z;
  v12 = x - resulta.x;
  v13 = y - resulta.y;
  v14 = z - resulta.z;
  *(float *)&retaddr = v12;
  v85 = v13;
  v76 = v14;
  v86 = v9;
  vars0 = v10;
  v75 = v11;
  if ( circular )
  {
    v15 = sinf(v12 * 1.5707964);
    v16 = sinf(v13 * 1.5707964);
    v17 = sinf(v14 * 1.5707964);
    *(float *)&retaddr = v15 * v15;
    v86 = 1.0 - (float)(v15 * v15);
    v85 = v16 * v16;
    v76 = v17 * v17;
    vars0 = 1.0 - (float)(v16 * v16);
    v75 = 1.0 - (float)(v17 * v17);
  }
  v18 = UFG::NoiseSeed<UFG::qVector3>(&resulta);
  v19 = UFG::NoiseRandom<UFG::qVector3>(&va, v18);
  v20 = v19->x;
  v21 = v19->y;
  v22 = v19->z;
  va.x = resulta.x;
  va.y = resulta.y;
  va.z = v74.z;
  v23 = UFG::NoiseSeed<UFG::qVector3>(&va);
  v24 = UFG::NoiseRandom<UFG::qVector3>(&v77, v23);
  v25 = v24->x;
  v26 = v24->y;
  v27 = v24->z;
  va.x = resulta.x;
  va.y = v74.y;
  va.z = resulta.z;
  v28 = UFG::NoiseSeed<UFG::qVector3>(&va);
  v29 = UFG::NoiseRandom<UFG::qVector3>(&v77, v28);
  v30 = v29->x;
  v31 = v29->y;
  v32 = v29->z;
  va.x = resulta.x;
  va.y = v74.y;
  va.z = v74.z;
  v33 = UFG::NoiseSeed<UFG::qVector3>(&va);
  v34 = UFG::NoiseRandom<UFG::qVector3>(&v77, v33);
  v35 = v34->z;
  v36 = v34->x;
  v81 = v34->y;
  v82 = v35;
  va.x = v74.x;
  *(_QWORD *)&va.y = *(_QWORD *)&resulta.y;
  v37 = UFG::NoiseSeed<UFG::qVector3>(&va);
  v38 = (int *)UFG::NoiseRandom<UFG::qVector3>(&v77, v37);
  v39 = *((float *)v38 + 1);
  v40 = *((float *)v38 + 2);
  v84 = *(float *)v38;
  v78 = v39;
  va.x = v74.x;
  va.z = v74.z;
  v80 = v40;
  va.y = resulta.y;
  v41 = UFG::NoiseSeed<UFG::qVector3>(&va);
  v42 = (int *)UFG::NoiseRandom<UFG::qVector3>(&v77, v41);
  v43 = *((float *)v42 + 1);
  v44 = *((float *)v42 + 2);
  v79 = *(float *)v42;
  v78 = v43;
  va.x = v74.x;
  v77.z = v44;
  va.z = resulta.z;
  va.y = v74.y;
  v45 = UFG::NoiseSeed<UFG::qVector3>(&va);
  v46 = (int *)UFG::NoiseRandom<UFG::qVector3>(&v77, v45);
  v47 = *((float *)v46 + 1);
  v48 = *((float *)v46 + 2);
  v83 = *(float *)v46;
  v79 = v47;
  v80 = v48;
  v49 = UFG::NoiseSeed<UFG::qVector3>(&v74);
  v50 = UFG::NoiseRandom<UFG::qVector3>(&v77, v49);
  v51 = v75 * (float)(v86 * v85);
  v52 = v75 * (float)(vars0 * v86);
  v53 = (float)(vars0 * v86) * v76;
  v86 = (float)(v86 * v85) * v76;
  vars0 = vars0 * *(float *)&retaddr;
  v54 = v75 * vars0;
  vars0 = vars0 * v76;
  v55 = (float)(v36 * v86) + (float)((float)(v30 * v51) + (float)((float)(v25 * v53) + (float)(v20 * v52)));
  v56 = v75 * (float)(v85 * *(float *)&retaddr);
  v85 = (float)(v85 * *(float *)&retaddr) * v76;
  v57 = (float)(v78 * v54)
      + (float)((float)(v81 * v86) + (float)((float)(v31 * v51) + (float)((float)(v26 * v53) + (float)(v21 * v52))));
  v58 = (float)(v80 * v54)
      + (float)((float)(v82 * v86) + (float)((float)(v32 * v51) + (float)((float)(v27 * v53) + (float)(v22 * v52))));
  v59 = v50->y;
  v60 = (float)(v79 * vars0) + (float)((float)(v84 * v54) + v55);
  v61 = (float)(v78 * vars0) + v57;
  v62 = v83 * v56;
  v63 = (float)(v77.z * vars0) + v58;
  v64 = v79 * v56;
  v65 = v80 * v56;
  v66 = v50->x;
  v67 = v62 + v60;
  v68 = v50->z;
  v69 = result;
  v70 = (float)(v59 * v85) + (float)(v64 + v61);
  v71 = (float)(v68 * v85) + (float)(v65 + v63);
  result->x = (float)(v66 * v85) + v67;
  result->y = v70;
  result->z = v71;
  return v69;
}

// File Line: 199
// RVA: 0x3BA770
void __fastcall UFG::qNoise<UFG::qVector3,float>::qNoise<UFG::qVector3,float>(UFG::qNoise<UFG::qVector3,float> *this)
{
  UFG::qVector3 v1; // [rsp+30h] [rbp-38h] BYREF
  UFG::qVector3 v2; // [rsp+40h] [rbp-28h] BYREF
  UFG::qVector3 v3; // [rsp+50h] [rbp-18h] BYREF

  v1.x = 1.0;
  v1.y = 1.0;
  v1.z = 1.0;
  v2.x = -1.0;
  v2.y = -1.0;
  v2.z = -1.0;
  v3.x = 0.5;
  v3.y = 0.5;
  v3.z = 0.5;
  this->bCircular = 0;
  UFG::qNoise<UFG::qVector3,float>::SetParameters(this, 6, 1.0, &v3, &v2, &v1);
}

// File Line: 213
// RVA: 0x3CD120
void __fastcall UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetParameters(
        UFG::qNoise<UFG::qVector3,UFG::qVector3> *this,
        int octaves,
        UFG::qVector3 *frequency,
        UFG::qVector3 *decay,
        UFG::qVector3 *min,
        UFG::qVector3 *max)
{
  float z; // xmm4_4
  float v7; // xmm0_4
  float y; // xmm2_4
  float x; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm0_4

  z = decay->z;
  v7 = *(float *)&FLOAT_1_0;
  if ( z <= 0.0 )
  {
    z = 0.0;
  }
  else if ( z >= 1.0 )
  {
    z = *(float *)&FLOAT_1_0;
  }
  y = decay->y;
  if ( y <= 0.0 )
  {
    y = 0.0;
  }
  else if ( y >= 1.0 )
  {
    y = *(float *)&FLOAT_1_0;
  }
  x = decay->x;
  if ( decay->x <= 0.0 )
  {
    x = 0.0;
    goto LABEL_13;
  }
  if ( x < 1.0 )
LABEL_13:
    v7 = x;
  this->tDecay.x = v7;
  this->tDecay.y = y;
  this->tDecay.z = z;
  if ( octaves <= 1 )
  {
    octaves = 1;
  }
  else if ( octaves >= 31 )
  {
    octaves = 31;
  }
  this->nOctaves = octaves;
  v10 = frequency->z;
  if ( v10 < 0.0 )
    LODWORD(v10) ^= _xmm[0];
  v11 = frequency->y;
  if ( v11 < 0.0 )
    LODWORD(v11) ^= _xmm[0];
  v12 = frequency->x;
  if ( frequency->x < 0.0 )
    LODWORD(v12) ^= _xmm[0];
  this->tFrequency.x = v12;
  this->tFrequency.y = v11;
  this->tFrequency.z = v10;
  *(_QWORD *)&this->tOffset.x = 0i64;
  this->tOffset.z = 0.0;
  v13 = min->z;
  if ( v13 >= max->z )
    v13 = max->z;
  v14 = min->y;
  if ( v14 >= max->y )
    v14 = max->y;
  v15 = min->x;
  if ( min->x >= max->x )
    v15 = max->x;
  this->tRangeMin.x = v15;
  this->tRangeMin.y = v14;
  this->tRangeMin.z = v13;
  v16 = min->z;
  if ( v16 <= max->z )
    v16 = max->z;
  v17 = min->y;
  if ( v17 <= max->y )
    v17 = max->y;
  v18 = min->x;
  if ( min->x <= max->x )
    v18 = max->x;
  this->tRangeMax.x = v18;
  this->tRangeMax.y = v17;
  this->tRangeMax.z = v16;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(this);
}

// File Line: 240
// RVA: 0x3CD390
void __fastcall UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(
        UFG::qNoise<UFG::qVector3,UFG::qVector3> *this,
        UFG::qVector3 *min,
        UFG::qVector3 *max)
{
  float z; // xmm2_4
  float y; // xmm1_4
  float x; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm0_4

  z = min->z;
  if ( z >= max->z )
    z = max->z;
  y = min->y;
  if ( y >= max->y )
    y = max->y;
  x = min->x;
  if ( min->x >= max->x )
    x = max->x;
  this->tRangeMin.x = x;
  this->tRangeMin.y = y;
  this->tRangeMin.z = z;
  v6 = min->z;
  if ( v6 <= max->z )
    v6 = max->z;
  v7 = min->y;
  if ( v7 <= max->y )
    v7 = max->y;
  v8 = min->x;
  if ( min->x <= max->x )
    v8 = max->x;
  this->tRangeMax.x = v8;
  this->tRangeMax.y = v7;
  this->tRangeMax.z = v6;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(this);
}

// File Line: 247
// RVA: 0x3CCA20
void __fastcall UFG::qNoise<float,float>::SetFrequency(
        UFG::qNoise<float,float> *this,
        float frequency,
        float calibrate)
{
  float v3; // xmm0_4
  float v4; // xmm3_4
  __int64 nOctaves; // rax
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4

  v3 = FLOAT_0_000099999997;
  LODWORD(v4) = LODWORD(frequency) & _xmm;
  if ( COERCE_FLOAT(LODWORD(frequency) & _xmm) > 0.000099999997 )
    LODWORD(v3) = LODWORD(frequency) & _xmm;
  nOctaves = (unsigned int)this->nOctaves;
  v6 = 1.0 / v3;
  v7 = calibrate + this->tOffset;
  v8 = v6 * this->tFrequency;
  this->tFrequency = v4;
  v9 = v8 * v7;
  v10 = *(float *)&FLOAT_1_0;
  v11 = v9 - calibrate;
  v12 = 0.0;
  this->tOffset = v11;
  if ( (int)nOctaves > 0 )
  {
    do
    {
      v12 = v12 + v10;
      v10 = v10 * this->tDecay;
      --nOctaves;
    }
    while ( nOctaves );
  }
  this->tAmplitude = 1.0 / v12;
}

// File Line: 256
// RVA: 0x3C4170
UFG::qVector3 *__fastcall UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(
        UFG::qNoise<UFG::qVector3,UFG::qVector3> *this,
        UFG::qVector3 *result,
        UFG::qVector3 *t)
{
  float v3; // xmm6_4
  int v4; // esi
  float x; // xmm9_4
  float y; // xmm10_4
  float z; // xmm11_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm14_4
  float v14; // xmm7_4
  float i; // xmm8_4
  bool bCircular; // r8
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::qVector3 *v19; // rax
  float v20; // xmm2_4
  float v21; // xmm4_4
  UFG::qVector3 *v22; // rax
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  UFG::qVector3 v; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qVector3 resulta; // [rsp+2Ch] [rbp-BCh] BYREF

  v3 = 0.0;
  v4 = 0;
  x = this->tAmplitude.x;
  y = this->tAmplitude.y;
  z = this->tAmplitude.z;
  v11 = this->tFrequency.x;
  v12 = this->tFrequency.y;
  v13 = this->tFrequency.z;
  v14 = 0.0;
  for ( i = 0.0; v4 < this->nOctaves; v13 = v13 * 2.0 )
  {
    bCircular = this->bCircular;
    v17 = (float)(this->tOffset.y + t->y) * v12;
    v18 = (float)(this->tOffset.z + t->z) * v13;
    v.x = (float)(this->tOffset.x + t->x) * v11;
    v.y = v17;
    v.z = v18;
    v19 = UFG::NoiseInterpolated<UFG::qVector3>(&resulta, &v, bCircular);
    v20 = x;
    x = x * this->tDecay.x;
    ++v4;
    v3 = v3 + (float)(v20 * v19->x);
    v14 = v14 + (float)(y * v19->y);
    i = i + (float)(z * v19->z);
    y = y * this->tDecay.y;
    z = z * this->tDecay.z;
    v11 = v11 * 2.0;
    v12 = v12 * 2.0;
  }
  v21 = this->tRangeMin.y;
  v22 = result;
  v23 = this->tRangeMin.z;
  v24 = this->tRangeMax.y;
  v25 = this->tRangeMax.z;
  result->x = this->tRangeMin.x
            + (float)((float)(this->tRangeMax.x - this->tRangeMin.x) * (float)((float)(v3 + 1.0) * 0.5));
  result->y = v21 + (float)((float)(v24 - v21) * (float)((float)(v14 + 1.0) * 0.5));
  result->z = v23 + (float)((float)(v25 - v23) * (float)((float)(i + 1.0) * 0.5));
  return v22;
}

// File Line: 289
// RVA: 0x3C5710
void __fastcall UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(UFG::qNoise<UFG::qVector3,UFG::qVector3> *this)
{
  int nOctaves; // r8d
  float v2; // xmm3_4
  int v3; // eax
  float v5; // xmm4_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm5_4
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  unsigned int v13; // eax
  __int64 v14; // rcx
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  __int64 v33; // rax

  nOctaves = this->nOctaves;
  v2 = 0.0;
  v3 = 0;
  v5 = 0.0;
  v6 = *(float *)&FLOAT_1_0;
  v7 = *(float *)&FLOAT_1_0;
  v8 = *(float *)&FLOAT_1_0;
  v9 = 0.0;
  if ( nOctaves >= 4 )
  {
    x = this->tDecay.x;
    y = this->tDecay.y;
    z = this->tDecay.z;
    v13 = ((unsigned int)(nOctaves - 4) >> 2) + 1;
    v14 = v13;
    v3 = 4 * v13;
    do
    {
      v15 = v2 + v6;
      v16 = v5 + v7;
      v17 = v9 + v8;
      v18 = v6 * x;
      v19 = v7 * y;
      v20 = v8 * z;
      v21 = v15 + v18;
      v22 = v16 + v19;
      v23 = v17 + v20;
      v24 = v18 * x;
      v25 = v19 * y;
      v26 = v20 * z;
      v27 = v21 + v24;
      v28 = v22 + v25;
      v29 = v23 + v26;
      v30 = v24 * x;
      v31 = v25 * y;
      v32 = v26 * z;
      v2 = v27 + v30;
      v5 = v28 + v31;
      v9 = v29 + v32;
      v6 = v30 * x;
      v7 = v31 * y;
      v8 = v32 * z;
      --v14;
    }
    while ( v14 );
  }
  if ( v3 < nOctaves )
  {
    v33 = (unsigned int)(nOctaves - v3);
    do
    {
      v2 = v2 + v6;
      v5 = v5 + v7;
      v9 = v9 + v8;
      v6 = v6 * this->tDecay.x;
      v7 = v7 * this->tDecay.y;
      v8 = v8 * this->tDecay.z;
      --v33;
    }
    while ( v33 );
  }
  this->tAmplitude.z = 1.0 / v9;
  this->tAmplitude.x = 1.0 / v2;
  this->tAmplitude.y = 1.0 / v5;
}

