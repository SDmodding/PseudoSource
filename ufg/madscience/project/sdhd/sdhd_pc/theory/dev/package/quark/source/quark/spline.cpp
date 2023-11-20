// File Line: 347
// RVA: 0x16DCC0
void __fastcall UFG::qBezierSplineMemImaged::FindCurveByLookup(UFG::qBezierSplineMemImaged *this, const float splineT, float *curveT, unsigned int *curveIndex)
{
  unsigned int *v4; // r14
  float *v5; // r15
  UFG::qBezierSplineMemImaged *v6; // r10
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // er11
  float v10; // xmm4_4
  int v11; // er9
  unsigned int v12; // ebx
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  __int64 v16; // r8
  int v17; // edi
  __int64 v18; // rax
  signed __int64 v19; // rdx
  signed __int64 v20; // rdx

  v4 = curveIndex;
  v5 = curveT;
  v6 = this;
  if ( splineT == 0.0 )
  {
    *curveIndex = 0;
    *curveT = 0.0;
  }
  else
  {
    v7 = this->mNumKnots;
    v8 = this->mNumKnots - 1;
    v9 = this->mNumKnots - 2;
    if ( splineT == 1.0 )
    {
      *curveIndex = v9;
      *curveT = 1.0;
    }
    else
    {
      v10 = this->mLength;
      v11 = 0;
      LODWORD(this) = 0;
      v12 = 0;
      v13 = 0.0;
      v14 = v10;
      v15 = v10 * splineT;
      if ( v7 != 1 )
      {
        v16 = v6->mLookupTable.mOffset;
        v17 = v7 - 2;
        do
        {
          this = (UFG::qBezierSplineMemImaged *)(v11 + ((v9 - v11) >> 1));
          if ( (_DWORD)this )
          {
            v18 = (unsigned int)((_DWORD)this - 1);
            if ( v16 )
              v19 = (signed __int64)&v6->mLookupTable + v16;
            else
              v19 = 0i64;
            if ( (_DWORD)v18 == v17 )
              v13 = v10;
            else
              v13 = *(float *)(v19 + 4 * v18);
          }
          else
          {
            v13 = 0.0;
          }
          if ( v16 )
            v20 = (signed __int64)&v6->mLookupTable + v16;
          else
            v20 = 0i64;
          if ( (_DWORD)this == v17 )
            v14 = v10;
          else
            v14 = *(float *)(v20 + 4i64 * (_QWORD)this);
          if ( v15 >= v13 )
          {
            if ( v15 <= v14 )
              break;
            v11 = (_DWORD)this + 1;
          }
          else
          {
            v9 = (_DWORD)this - 1;
          }
          ++v12;
        }
        while ( v12 < v8 );
      }
      *v4 = (unsigned int)this;
      *v5 = (float)(v15 - v13) / (float)(v14 - v13);
    }
  }
}

// File Line: 397
// RVA: 0x171C70
void __fastcall UFG::qBezierSplineMemImaged::GetPositionAndTangent(UFG::qBezierSplineMemImaged *this, const float splineT, UFG::qVector3 *position, UFG::qVector3 *tangent)
{
  __int64 v4; // rax
  UFG::qVector3 *v5; // rdi
  UFG::qVector3 *v6; // rsi
  UFG::qBezierSplineMemImaged *v7; // rbx
  unsigned int v8; // edx
  float v9; // xmm13_4
  unsigned int v10; // er8
  unsigned int v11; // ecx
  float v12; // xmm13_4
  unsigned int v13; // er9
  __int64 v14; // rax
  unsigned int v15; // er10
  float v16; // xmm14_4
  signed __int64 v17; // r8
  __int64 v18; // rax
  signed __int64 v19; // rcx
  __int64 v20; // rax
  float v21; // xmm10_4
  float v22; // xmm8_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm6_4
  float v26; // xmm9_4
  float v27; // xmm11_4
  float v28; // xmm10_4
  float v29; // xmm5_4
  float v30; // xmm3_4
  unsigned int v31; // [rsp+C0h] [rbp+8h]
  float v32; // [rsp+D0h] [rbp+18h]

  v4 = this->mLookupTable.mOffset;
  v5 = tangent;
  v6 = position;
  v7 = this;
  if ( v4 && (UFG::qOffset64<UFG::qBezierLookup *> *)((char *)&this->mLookupTable + v4) && this->mLength > 0.0 )
  {
    UFG::qBezierSplineMemImaged::FindCurveByLookup(this, splineT, &v32, &v31);
    v8 = v31;
    v9 = v32;
  }
  else
  {
    v10 = this->mNumKnots;
    v11 = this->mNumKnots - 1;
    v12 = (float)(signed int)v11 * splineT;
    v8 = (signed int)v12;
    if ( (signed int)v12 >= v11 )
      v8 = v10 - 2;
    v9 = v12 - (float)(signed int)v8;
  }
  v13 = v7->mNumKnots;
  v14 = v7->mKnotTable.mOffset;
  v15 = v7->mNumKnots - 1;
  v16 = 1.0 - v9;
  if ( v14 )
    v17 = (signed __int64)&v7->mKnotTable + v14;
  else
    v17 = 0i64;
  v18 = v8;
  if ( v8 >= v13 )
    v18 = v15;
  v19 = 9 * v18;
  v20 = v8 + 1;
  if ( (unsigned int)v20 >= v13 )
    v20 = v15;
  v21 = (float)((float)(v9 * *(float *)(v17 + 36 * v20 + 16)) * v9) * v9;
  v22 = (float)((float)((float)(*(float *)(v17 + 36 * v20 + 8) * 3.0) * v9) * v9) * v16;
  v23 = (float)((float)((float)(v16 * *(float *)(v17 + 4 * v19 + 16)) * v16) * v16)
      + (float)((float)((float)((float)(*(float *)(v17 + 4 * v19 + 28) * 3.0) * v9) * v16) * v16);
  v24 = (float)((float)((float)(v16 * *(float *)(v17 + 4 * v19 + 20)) * v16) * v16)
      + (float)((float)((float)((float)(*(float *)(v17 + 4 * v19 + 32) * 3.0) * v9) * v16) * v16);
  v25 = (float)((float)((float)(*(float *)(v17 + 36 * v20 + 4) * 3.0) * v9) * v9) * v16;
  v26 = (float)(v9 * *(float *)(v17 + 36 * v20 + 20)) * v9;
  v6->x = (float)((float)((float)(v9 * *(float *)(v17 + 36 * v20 + 12)) * v9) * v9)
        + (float)((float)((float)((float)((float)(*(float *)(v17 + 36 * v20) * 3.0) * v9) * v9) * v16)
                + (float)((float)((float)((float)(v16 * *(float *)(v17 + 4 * v19 + 12)) * v16) * v16)
                        + (float)((float)((float)((float)(*(float *)(v17 + 4 * v19 + 24) * 3.0) * v9) * v16) * v16)));
  v6->y = v21 + (float)(v25 + v23);
  v6->z = (float)(v22 + v24) + (float)(v26 * v9);
  v27 = (float)((float)((float)(*(float *)(v17 + 4 * v19 + 24) - *(float *)(v17 + 4 * v19 + 12)) * 3.0) * v16) * v16;
  v28 = (float)((float)((float)(*(float *)(v17 + 4 * v19 + 28) - *(float *)(v17 + 4 * v19 + 16)) * 3.0) * v16) * v16;
  v29 = (float)((float)((float)((float)(*(float *)(v17 + 36 * v20 + 12) - *(float *)(v17 + 36 * v20)) * 3.0) * v9) * v9)
      + (float)((float)((float)((float)(*(float *)(v17 + 36 * v20) - *(float *)(v17 + 4 * v19 + 24)) * 6.0) * v16) * v9);
  v30 = (float)((float)((float)((float)(*(float *)(v17 + 36 * v20 + 16) - *(float *)(v17 + 36 * v20 + 4)) * 3.0) * v9)
              * v9)
      + (float)((float)((float)((float)(*(float *)(v17 + 36 * v20 + 4) - *(float *)(v17 + 4 * v19 + 28)) * 6.0) * v16)
              * v9);
  v5->z = (float)((float)((float)((float)((float)(*(float *)(v17 + 36 * v20 + 20) - *(float *)(v17 + 36 * v20 + 8)) * 3.0)
                                * v9)
                        * v9)
                + (float)((float)((float)((float)(*(float *)(v17 + 36 * v20 + 8) - *(float *)(v17 + 4 * v19 + 32)) * 6.0)
                                * v16)
                        * v9))
        + (float)((float)((float)((float)(*(float *)(v17 + 4 * v19 + 32) - *(float *)(v17 + 4 * v19 + 20)) * 3.0) * v16)
                * v16);
  v5->x = v29 + v27;
  v5->y = v30 + v28;
}

// File Line: 437
// RVA: 0x1719F0
UFG::qVector3 *__fastcall UFG::qBezierSplineMemImaged::GetPosition(UFG::qBezierSplineMemImaged *this, UFG::qVector3 *result, float splineT)
{
  __int64 v3; // rax
  UFG::qVector3 *v4; // rdi
  UFG::qBezierSplineMemImaged *v5; // rbx
  unsigned int v6; // er8
  float v7; // xmm1_4
  unsigned int v8; // edx
  unsigned int v9; // ecx
  float v10; // xmm1_4
  unsigned int v11; // ecx
  __int64 v12; // rax
  unsigned int v13; // er10
  float v14; // xmm12_4
  signed __int64 v15; // r9
  __int64 v16; // rax
  signed __int64 v17; // rdx
  __int64 v18; // rax
  signed __int64 v19; // rcx
  UFG::qVector3 *v20; // rax
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm5_4
  float v24; // xmm11_4
  float v25; // xmm10_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  unsigned int v29; // [rsp+A0h] [rbp+8h]
  float v30; // [rsp+A8h] [rbp+10h]

  v3 = this->mLookupTable.mOffset;
  v4 = result;
  v5 = this;
  if ( v3 && (UFG::qOffset64<UFG::qBezierLookup *> *)((char *)&this->mLookupTable + v3) && this->mLength > 0.0 )
  {
    UFG::qBezierSplineMemImaged::FindCurveByLookup(this, splineT, &v30, &v29);
    v6 = v29;
    v7 = v30;
  }
  else
  {
    v8 = this->mNumKnots;
    v9 = this->mNumKnots - 1;
    v10 = (float)(signed int)v9 * splineT;
    v6 = (signed int)v10;
    if ( (signed int)v10 >= v9 )
      v6 = v8 - 2;
    v7 = v10 - (float)(signed int)v6;
  }
  v11 = v5->mNumKnots;
  v12 = v5->mKnotTable.mOffset;
  v13 = v5->mNumKnots - 1;
  v14 = 1.0 - v7;
  if ( v12 )
    v15 = (signed __int64)&v5->mKnotTable + v12;
  else
    v15 = 0i64;
  v16 = v6;
  if ( v6 >= v11 )
    v16 = v13;
  v17 = 9 * v16;
  v18 = v6 + 1;
  if ( (unsigned int)v18 >= v11 )
    v18 = v13;
  v19 = 9 * v18;
  v20 = v4;
  v21 = (float)((float)(*(float *)(v15 + 4 * v19 + 4) * 3.0) * v7) * v7;
  v22 = (float)((float)(*(float *)(v15 + 4 * v19 + 8) * 3.0) * v7) * v7;
  v23 = (float)(*(float *)(v15 + 4 * v17 + 32) * 3.0) * v7;
  v24 = (float)((float)(v7 * *(float *)(v15 + 4 * v19 + 20)) * v7) * v7;
  v25 = (float)((float)(v7 * *(float *)(v15 + 4 * v19 + 16)) * v7) * v7;
  v26 = (float)((float)((float)((float)((float)(v14 * *(float *)(v15 + 4 * v17 + 12)) * v14) * v14)
                      + (float)((float)((float)((float)(*(float *)(v15 + 4 * v17 + 24) * 3.0) * v7) * v14) * v14))
              + (float)((float)((float)((float)(*(float *)(v15 + 4 * v19) * 3.0) * v7) * v7) * v14))
      + (float)((float)((float)(v7 * *(float *)(v15 + 4 * v19 + 12)) * v7) * v7);
  v27 = (float)((float)((float)(v14 * *(float *)(v15 + 4 * v17 + 16)) * v14) * v14)
      + (float)((float)((float)((float)(*(float *)(v15 + 4 * v17 + 28) * 3.0) * v7) * v14) * v14);
  v28 = (float)((float)((float)(v14 * *(float *)(v15 + 4 * v17 + 20)) * v14) * v14) + (float)((float)(v23 * v14) * v14);
  v4->x = v26;
  v4->y = (float)(v27 + (float)(v21 * v14)) + v25;
  v4->z = (float)(v28 + (float)(v22 * v14)) + v24;
  return v20;
}

// File Line: 467
// RVA: 0x172930
UFG::qVector3 *__fastcall UFG::qBezierSplineMemImaged::GetTangent(UFG::qBezierSplineMemImaged *this, UFG::qVector3 *result, float splineT)
{
  UFG::qVector3 *v3; // rdi
  UFG::qBezierSplineMemImaged *v4; // rbx
  float v5; // xmm1_4
  __int64 v6; // rax
  unsigned int v7; // edx
  float v8; // xmm12_4
  unsigned int v9; // er8
  unsigned int v10; // ecx
  float v11; // xmm12_4
  unsigned int v12; // er9
  __int64 v13; // rax
  unsigned int v14; // er10
  float v15; // xmm13_4
  signed __int64 v16; // r8
  __int64 v17; // rax
  signed __int64 v18; // rcx
  __int64 v19; // rax
  signed __int64 v20; // rdx
  UFG::qVector3 *v21; // rax
  float v22; // xmm10_4
  float v23; // xmm9_4
  float v24; // xmm3_4
  float v25; // xmm5_4
  float v26; // xmm4_4
  float curveT; // [rsp+B0h] [rbp+8h]
  unsigned int curveIndex; // [rsp+C0h] [rbp+18h]

  v3 = result;
  v4 = this;
  if ( splineT <= 0.001 )
  {
    splineT = FLOAT_0_001;
  }
  else
  {
    v5 = FLOAT_0_99900001;
    if ( splineT >= 0.99900001 )
      goto LABEL_6;
  }
  v5 = splineT;
LABEL_6:
  v6 = this->mLookupTable.mOffset;
  if ( v6 && (UFG::qOffset64<UFG::qBezierLookup *> *)((char *)&this->mLookupTable + v6) && this->mLength > 0.0 )
  {
    UFG::qBezierSplineMemImaged::FindCurveByLookup(this, v5, &curveT, &curveIndex);
    v7 = curveIndex;
    v8 = curveT;
  }
  else
  {
    v9 = this->mNumKnots;
    v10 = this->mNumKnots - 1;
    v11 = (float)(signed int)v10 * v5;
    v7 = (signed int)v11;
    if ( (signed int)v11 >= v10 )
      v7 = v9 - 2;
    v8 = v11 - (float)(signed int)v7;
  }
  v12 = v4->mNumKnots;
  v13 = v4->mKnotTable.mOffset;
  v14 = v4->mNumKnots - 1;
  v15 = 1.0 - v8;
  if ( v13 )
    v16 = (signed __int64)&v4->mKnotTable + v13;
  else
    v16 = 0i64;
  v17 = v7;
  if ( v7 == v12 )
    v17 = v14;
  v18 = 9 * v17;
  v19 = v7 + 1;
  if ( (_DWORD)v19 == v12 )
    v19 = v14;
  v20 = 9 * v19;
  v21 = v3;
  v22 = (float)((float)((float)(*(float *)(v16 + 4 * v18 + 28) - *(float *)(v16 + 4 * v18 + 16)) * 3.0) * v15) * v15;
  v23 = (float)((float)((float)(*(float *)(v16 + 4 * v18 + 32) - *(float *)(v16 + 4 * v18 + 20)) * 3.0) * v15) * v15;
  v24 = (float)((float)((float)(*(float *)(v16 + 4 * v20 + 20) - *(float *)(v16 + 4 * v20 + 8)) * 3.0) * v8) * v8;
  v25 = (float)((float)((float)(*(float *)(v16 + 4 * v20 + 8) - *(float *)(v16 + 4 * v18 + 32)) * 6.0) * v15) * v8;
  v26 = (float)((float)((float)((float)(*(float *)(v16 + 4 * v20 + 16) - *(float *)(v16 + 4 * v20 + 4)) * 3.0) * v8) * v8)
      + (float)((float)((float)((float)(*(float *)(v16 + 4 * v20 + 4) - *(float *)(v16 + 4 * v18 + 28)) * 6.0) * v15)
              * v8);
  v3->x = (float)((float)((float)((float)(*(float *)(v16 + 4 * v18 + 24) - *(float *)(v16 + 4 * v18 + 12)) * 3.0) * v15)
                * v15)
        + (float)((float)((float)((float)((float)(*(float *)(v16 + 4 * v20 + 12) - *(float *)(v16 + 4 * v20)) * 3.0) * v8)
                        * v8)
                + (float)((float)((float)((float)(*(float *)(v16 + 4 * v20) - *(float *)(v16 + 4 * v18 + 24)) * 6.0)
                                * v15)
                        * v8));
  v3->y = v22 + v26;
  v3->z = v23 + (float)(v24 + v25);
  return v21;
}

// File Line: 790
// RVA: 0x1685D0
void __fastcall UFG::qBezierSplineMemImaged::ClosestPoint3D_CurveFast(UFG::qBezierSplineMemImaged *this, UFG::qVector3 *pos, unsigned int curveIndex, float *curveT, UFG::qVector3 *closestPoint)
{
  UFG::qVector3 *v5; // r11
  __int64 v6; // rax
  char *v7; // r10
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  signed __int64 v12; // rdx
  signed __int64 v13; // r8
  __int64 v14; // rax
  float v15; // xmm11_4
  float v16; // xmm8_4
  float v17; // xmm9_4
  float v18; // xmm13_4
  float v19; // xmm14_4
  float v20; // xmm15_4
  float v21; // xmm10_4
  __int128 v22; // xmm12
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm0_4
  __int128 v26; // xmm11
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm3_4
  float v31; // xmm5_4
  float v32; // xmm8_4
  float v33; // xmm9_4
  float v34; // xmm10_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // [rsp+B0h] [rbp+8h]
  float v38; // [rsp+B8h] [rbp+10h]
  float v39; // [rsp+C0h] [rbp+18h]
  float v40; // [rsp+C8h] [rbp+20h]

  v5 = pos;
  v6 = this->mKnotTable.mOffset;
  if ( v6 )
    v7 = (char *)&this->mKnotTable + v6;
  else
    v7 = 0i64;
  v8 = pos->x;
  v9 = pos->y;
  v10 = pos->z;
  v11 = 0.0;
  v12 = 9i64 * curveIndex;
  v13 = 9i64 * (curveIndex + 1);
  v14 = g_SplineInterations;
  v15 = *(float *)&v7[4 * v12 + 12];
  v16 = *(float *)&v7[4 * v12 + 16];
  v17 = *(float *)&v7[4 * v12 + 20];
  v18 = *(float *)&v7[4 * v13 + 12];
  v19 = *(float *)&v7[4 * v13 + 16];
  v20 = *(float *)&v7[4 * v13 + 20];
  v21 = *(float *)&FLOAT_1_0;
  v22 = (unsigned int)FLOAT_1_0;
  v39 = 0.0;
  v37 = *(float *)&v7[4 * v12 + 12];
  v38 = *(float *)&v7[4 * v12 + 16];
  v23 = (float)((float)((float)(v9 - v16) * (float)(v9 - v16)) + (float)((float)(v5->x - v15) * (float)(v5->x - v15)))
      + (float)((float)(v5->z - v17) * (float)(v5->z - v17));
  v40 = *(float *)&v7[4 * v12 + 20];
  v24 = (float)((float)((float)(v5->y - v19) * (float)(v5->y - v19)) + (float)((float)(v8 - v18) * (float)(v8 - v18)))
      + (float)((float)(v10 - v20) * (float)(v10 - v20));
  v25 = FLOAT_0_5;
  if ( g_SplineInterations )
  {
    do
    {
      v26 = v22;
      *(float *)&v26 = (float)(*(float *)&v22 + v11) * v25;
      v27 = v21 - *(float *)&v26;
      v28 = (float)(*(float *)&v26 * *(float *)&v26) * *(float *)&v26;
      v29 = (float)(v27 * v27) * v27;
      v30 = (float)((float)(*(float *)&v26 * 3.0) * v27) * v27;
      v31 = (float)((float)(*(float *)&v26 * 3.0) * *(float *)&v26) * (float)(v21 - *(float *)&v26);
      v32 = (float)((float)((float)(*(float *)&v7[4 * v12 + 12] * v29) + (float)(*(float *)&v7[4 * v12 + 24] * v30))
                  + (float)(*(float *)&v7[4 * v13] * v31))
          + (float)(*(float *)&v7[4 * v13 + 12] * v28);
      v33 = (float)((float)((float)(*(float *)&v7[4 * v12 + 16] * v29) + (float)(*(float *)&v7[4 * v12 + 28] * v30))
                  + (float)(*(float *)&v7[4 * v13 + 4] * v31))
          + (float)(*(float *)&v7[4 * v13 + 16] * v28);
      v34 = (float)((float)((float)(*(float *)&v7[4 * v12 + 20] * v29) + (float)(*(float *)&v7[4 * v12 + 32] * v30))
                  + (float)(*(float *)&v7[4 * v13 + 8] * v31))
          + (float)(*(float *)&v7[4 * v13 + 20] * v28);
      v35 = (float)(v5->x - v32) * (float)(v5->x - v32);
      v36 = (float)(v5->z - v34) * (float)(v5->z - v34);
      if ( v23 >= v24 )
      {
        v11 = *(float *)&v26;
        v15 = v32;
        v38 = v33;
        v40 = v34;
        v39 = v11;
        v37 = v32;
        v23 = (float)((float)((float)(v5->y - v33) * (float)(v5->y - v33)) + v35) + v36;
      }
      else
      {
        v11 = v39;
        v22 = v26;
        v18 = v32;
        v19 = v33;
        v20 = v34;
        v15 = v37;
        v24 = (float)((float)((float)(v5->y - v33) * (float)(v5->y - v33)) + v35) + v36;
      }
      v25 = FLOAT_0_5;
      v21 = *(float *)&FLOAT_1_0;
      --v14;
    }
    while ( v14 );
    v16 = v38;
    v17 = v40;
  }
  *curveT = (float)(*(float *)&v22 + v11) * v25;
  closestPoint->x = (float)(v18 + v15) * v25;
  closestPoint->y = (float)(v19 + v16) * v25;
  closestPoint->z = (float)(v20 + v17) * v25;
}

// File Line: 848
// RVA: 0x16B690
float __fastcall UFG::qBezierSplineMemImaged::CurveIndexAndCurveTtoSplineT(UFG::qBezierSplineMemImaged *this, unsigned int curveIndex, float curveT)
{
  __int64 v3; // rax
  float v4; // xmm3_4
  char *v5; // r8
  float v6; // xmm1_4
  __int64 v7; // r9
  float v8; // xmm0_4
  float result; // xmm0_4

  v3 = this->mLookupTable.mOffset;
  v4 = 0.0;
  if ( v3 && (v5 = (char *)&this->mLookupTable + v3) != 0i64 && (v6 = this->mLength, v6 > 0.0) )
  {
    if ( curveIndex )
    {
      v7 = curveIndex - 1;
      if ( (_DWORD)v7 == this->mNumKnots - 2 )
        v4 = this->mLength;
      else
        v4 = *(float *)&v5[4 * v7];
    }
    if ( curveIndex == this->mNumKnots - 2 )
      v8 = this->mLength;
    else
      v8 = *(float *)&v5[4 * curveIndex];
    result = (float)((float)((float)(v8 - v4) * curveT) + v4) / v6;
  }
  else
  {
    result = (float)((float)(signed int)curveIndex * (float)(1.0 / (float)(this->mNumKnots - 1)))
           + (float)((float)(1.0 / (float)(this->mNumKnots - 1)) * curveT);
    if ( result >= 1.0 )
    {
      result = *(float *)&FLOAT_1_0;
    }
    else if ( result <= 0.0 )
    {
      result = 0.0;
    }
  }
  return result;
}

// File Line: 871
// RVA: 0x168980
UFG::qVector3 *__fastcall UFG::qBezierSplineMemImaged::ClosestPoint3D_Fast(UFG::qBezierSplineMemImaged *this, UFG::qVector3 *result, UFG::qVector3 *pos, float *splineT)
{
  __int64 v4; // rax
  float v5; // xmm3_4
  unsigned int v6; // ebx
  unsigned int v7; // er10
  float *v8; // r12
  UFG::qVector3 *v9; // r14
  UFG::qVector3 *v10; // rdi
  UFG::qBezierSplineMemImaged *v11; // rsi
  char *v12; // r11
  unsigned int v13; // er8
  signed __int64 v14; // rax
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm6_4
  signed int v18; // edx
  float *v19; // rcx
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float *v23; // rcx
  float v24; // xmm6_4
  __int64 v25; // rax
  float *v26; // rcx
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm9_4
  float v38; // xmm10_4
  float v39; // xmm8_4
  float v40; // xmm11_4
  float v41; // xmm0_4
  float v43; // [rsp+30h] [rbp-59h]
  UFG::qVector3 closestPoint; // [rsp+38h] [rbp-51h]
  UFG::qVector3 v45; // [rsp+48h] [rbp-41h]
  float curveT; // [rsp+F0h] [rbp+67h]

  v4 = this->mKnotTable.mOffset;
  v5 = FLOAT_3_4028235e38;
  v6 = -1;
  v7 = 0;
  v8 = splineT;
  v9 = pos;
  v10 = result;
  v11 = this;
  if ( v4 )
    v12 = (char *)&this->mKnotTable + v4;
  else
    v12 = 0i64;
  v13 = this->mNumKnots;
  v14 = 0i64;
  if ( (signed int)this->mNumKnots >= 4 )
  {
    v15 = v9->x;
    v16 = v9->y;
    v17 = v9->z;
    v18 = 2;
    v19 = (float *)(v12 + 20);
    v14 = 4i64 * (((v13 - 4) >> 2) + 1);
    do
    {
      if ( (float)((float)((float)((float)(v15 - *(v19 - 2)) * (float)(v15 - *(v19 - 2)))
                         + (float)((float)(v16 - *(v19 - 1)) * (float)(v16 - *(v19 - 1))))
                 + (float)((float)(v17 - *v19) * (float)(v17 - *v19))) < v5 )
      {
        v5 = (float)((float)((float)(v15 - *(v19 - 2)) * (float)(v15 - *(v19 - 2)))
                   + (float)((float)(v16 - *(v19 - 1)) * (float)(v16 - *(v19 - 1))))
           + (float)((float)(v17 - *v19) * (float)(v17 - *v19));
        v6 = v7;
      }
      if ( (float)((float)((float)((float)(v15 - v19[7]) * (float)(v15 - v19[7]))
                         + (float)((float)(v16 - v19[8]) * (float)(v16 - v19[8])))
                 + (float)((float)(v17 - v19[9]) * (float)(v17 - v19[9]))) < v5 )
      {
        v5 = (float)((float)((float)(v15 - v19[7]) * (float)(v15 - v19[7]))
                   + (float)((float)(v16 - v19[8]) * (float)(v16 - v19[8])))
           + (float)((float)(v17 - v19[9]) * (float)(v17 - v19[9]));
        v6 = v18 - 1;
      }
      if ( (float)((float)((float)((float)(v15 - v19[16]) * (float)(v15 - v19[16]))
                         + (float)((float)(v16 - v19[17]) * (float)(v16 - v19[17])))
                 + (float)((float)(v17 - v19[18]) * (float)(v17 - v19[18]))) < v5 )
      {
        v5 = (float)((float)((float)(v15 - v19[16]) * (float)(v15 - v19[16]))
                   + (float)((float)(v16 - v19[17]) * (float)(v16 - v19[17])))
           + (float)((float)(v17 - v19[18]) * (float)(v17 - v19[18]));
        v6 = v18;
      }
      if ( (float)((float)((float)((float)(v15 - v19[25]) * (float)(v15 - v19[25]))
                         + (float)((float)(v16 - v19[26]) * (float)(v16 - v19[26])))
                 + (float)((float)(v17 - v19[27]) * (float)(v17 - v19[27]))) < v5 )
      {
        v5 = (float)((float)((float)(v15 - v19[25]) * (float)(v15 - v19[25]))
                   + (float)((float)(v16 - v19[26]) * (float)(v16 - v19[26])))
           + (float)((float)(v17 - v19[27]) * (float)(v17 - v19[27]));
        v6 = v18 + 1;
      }
      v7 += 4;
      v19 += 36;
      v18 += 4;
    }
    while ( v7 < v13 - 3 );
  }
  if ( v7 < v13 )
  {
    v23 = (float *)&v12[4 * (v14 + 8 * v14 + 5)];
    do
    {
      v20 = v9->x;
      v21 = v9->y;
      v22 = v9->z;
      if ( (float)((float)((float)((float)(v20 - *(v23 - 2)) * (float)(v20 - *(v23 - 2)))
                         + (float)((float)(v21 - *(v23 - 1)) * (float)(v21 - *(v23 - 1))))
                 + (float)((float)(v22 - *v23) * (float)(v22 - *v23))) < v5 )
      {
        v5 = (float)((float)((float)(v20 - *(v23 - 2)) * (float)(v20 - *(v23 - 2)))
                   + (float)((float)(v21 - *(v23 - 1)) * (float)(v21 - *(v23 - 1))))
           + (float)((float)(v22 - *v23) * (float)(v22 - *v23));
        v6 = v7;
      }
      ++v7;
      v23 += 9;
    }
    while ( v7 < v13 );
  }
  if ( !v6 )
  {
    v24 = 0.0;
    curveT = 0.0;
    UFG::qBezierSplineMemImaged::ClosestPoint3D_CurveFast(v11, v9, 0, &curveT, &closestPoint);
    v25 = v11->mLookupTable.mOffset;
    if ( v25 )
    {
      v26 = (float *)((char *)&v11->mLookupTable + v25);
      if ( v26 )
      {
        v27 = v11->mLength;
        if ( v27 > 0.0 )
        {
          if ( v11->mNumKnots == 2 )
            v24 = (float)(v27 * curveT) / v27;
          else
            v24 = (float)(*v26 * curveT) / v27;
          goto LABEL_32;
        }
      }
    }
    v28 = (float)((float)(1.0 / (float)(v11->mNumKnots - 1)) * curveT)
        + (float)((float)(1.0 / (float)(v11->mNumKnots - 1)) * 0.0);
    if ( v28 >= 1.0 )
    {
      v28 = *(float *)&FLOAT_1_0;
    }
    else if ( v28 <= 0.0 )
    {
      goto LABEL_32;
    }
    v24 = v28;
LABEL_32:
    v29 = closestPoint.x;
    v30 = closestPoint.y;
    *v8 = v24;
    v10->x = v29;
    v31 = closestPoint.z;
    v10->y = v30;
    v10->z = v31;
    return v10;
  }
  if ( v6 == v13 - 1 )
  {
    curveT = 0.0;
    UFG::qBezierSplineMemImaged::ClosestPoint3D_CurveFast(v11, v9, v13 - 2, &curveT, &closestPoint);
    v32 = UFG::qBezierSplineMemImaged::CurveIndexAndCurveTtoSplineT(v11, v11->mNumKnots - 2, curveT);
    v10->x = closestPoint.x;
    v33 = closestPoint.z;
    *v8 = v32;
    v34 = closestPoint.y;
    v10->z = v33;
    v10->y = v34;
  }
  else
  {
    curveT = 0.0;
    UFG::qBezierSplineMemImaged::ClosestPoint3D_CurveFast(v11, v9, v6 - 1, &curveT, &closestPoint);
    v43 = 0.0;
    UFG::qBezierSplineMemImaged::ClosestPoint3D_CurveFast(v11, v9, v6, &v43, &v45);
    v35 = closestPoint.x;
    v36 = closestPoint.y;
    v37 = v45.x;
    v38 = v45.y;
    v39 = closestPoint.z;
    v40 = v45.z;
    if ( (float)((float)((float)((float)(v9->y - closestPoint.y) * (float)(v9->y - closestPoint.y))
                       + (float)((float)(v9->x - closestPoint.x) * (float)(v9->x - closestPoint.x)))
               + (float)((float)(v9->z - closestPoint.z) * (float)(v9->z - closestPoint.z))) >= (float)((float)((float)((float)(v9->y - v45.y) * (float)(v9->y - v45.y)) + (float)((float)(v9->x - v45.x) * (float)(v9->x - v45.x))) + (float)((float)(v9->z - v45.z) * (float)(v9->z - v45.z))) )
    {
      v41 = UFG::qBezierSplineMemImaged::CurveIndexAndCurveTtoSplineT(v11, v6, v43);
      v10->x = v37;
      v10->y = v38;
      v10->z = v40;
    }
    else
    {
      v41 = UFG::qBezierSplineMemImaged::CurveIndexAndCurveTtoSplineT(v11, v6 - 1, curveT);
      v10->x = v35;
      v10->y = v36;
      v10->z = v39;
    }
    *v8 = v41;
  }
  return v10;
}

// File Line: 978
// RVA: 0x171620
float __fastcall UFG::qBezierPathMemImaged::GetPathTFromSplineT(UFG::qBezierPathMemImaged *this, const unsigned int splineIndex, float splineT)
{
  unsigned int v3; // ebx
  signed __int64 v4; // r8
  __int64 v5; // r11
  UFG::qBezierPathMemImaged *v6; // r10
  float v7; // xmm0_4
  unsigned int v8; // eax
  __int64 v9; // r9
  __int64 v10; // rcx
  signed __int64 v11; // rdx
  signed __int64 v12; // rcx
  __int64 v13; // rdx
  signed __int64 v14; // rcx
  __int64 v16; // rax
  signed __int64 v17; // rcx
  __int64 v18; // rax

  v3 = this->mNumSplines;
  v4 = 0i64;
  v5 = splineIndex;
  v6 = this;
  v7 = 0.0;
  v8 = 0;
  if ( this->mNumSplines )
  {
    v9 = 0i64;
    while ( v8 != (_DWORD)v5 )
    {
      v10 = v6->mSplineOffsetTable.mOffset;
      if ( v10 )
        v11 = (signed __int64)&v6->mSplineOffsetTable + v10;
      else
        v11 = 0i64;
      v12 = v9 + v11;
      v13 = *(_QWORD *)(v9 + v11);
      if ( v13 )
        v14 = v13 + v12;
      else
        v14 = 0i64;
      v7 = v7 + *(float *)(v14 + 4);
      ++v8;
      v9 += 8i64;
      if ( v8 >= v3 )
        return v7 / v6->mLength;
    }
    v16 = v6->mSplineOffsetTable.mOffset;
    if ( v16 )
      v17 = (signed __int64)&v6->mSplineOffsetTable + v16;
    else
      v17 = 0i64;
    v18 = *(_QWORD *)(v17 + 8 * v5);
    if ( v18 )
      v4 = v18 + v17 + 8 * v5;
    v7 = v7 + (float)(splineT * *(float *)(v4 + 4));
  }
  return v7 / v6->mLength;
}

// File Line: 1060
// RVA: 0x1723A0
__int64 __fastcall UFG::qBezierPathMemImaged::GetSplineParameters(UFG::qBezierPathMemImaged *this, const float pathT, float *splineT)
{
  unsigned int v3; // er11
  float v4; // xmm1_4
  unsigned int v5; // edx
  float *v6; // rbx
  UFG::qBezierPathMemImaged *v7; // r10
  __int64 v8; // r9
  __int64 v9; // r8
  signed __int64 v10; // rax
  signed __int64 v11; // rcx
  __int64 v12; // rax
  float v13; // xmm0_4
  __int64 result; // rax

  v3 = this->mNumSplines;
  v4 = pathT * this->mLength;
  v5 = 0;
  v6 = splineT;
  v7 = this;
  if ( this->mNumSplines )
  {
    v8 = this->mSplineOffsetTable.mOffset;
    v9 = 0i64;
    while ( 1 )
    {
      v10 = (signed __int64)(v8 ? (UFG::qOffset64<UFG::qOffset64<UFG::qBezierSplineMemImaged *> *> *)((char *)&v7->mSplineOffsetTable + v8) : 0i64);
      v11 = v9 + v10;
      v12 = *(_QWORD *)(v9 + v10);
      if ( v12 )
        v12 += v11;
      v13 = *(float *)(v12 + 4);
      if ( v4 < v13 )
        break;
      ++v5;
      v9 += 8i64;
      v4 = v4 - v13;
      if ( v5 >= v3 )
        goto LABEL_10;
    }
    result = v5;
    *v6 = v4 / v13;
  }
  else
  {
LABEL_10:
    *v6 = 1.0;
    result = v7->mNumSplines - 1;
  }
  return result;
}

// File Line: 1298
// RVA: 0x168450
UFG::qVector3 *__fastcall UFG::qBezierPathMemImaged::ClosestPoint3D(UFG::qBezierPathMemImaged *this, UFG::qVector3 *result, UFG::qVector3 *pos, float *t)
{
  float v4; // xmm1_4
  unsigned int v5; // ebp
  float v6; // xmm7_4
  float v7; // xmm0_4
  unsigned int v8; // er15
  unsigned int v9; // ebx
  float *v10; // r13
  UFG::qVector3 *v11; // rdi
  UFG::qBezierPathMemImaged *v12; // r14
  float v13; // xmm6_4
  UFG::qVector3 *v14; // r12
  __int64 v15; // rsi
  __int64 v16; // rax
  signed __int64 v17; // rcx
  signed __int64 v18; // rax
  UFG::qBezierSplineMemImaged *v19; // rcx
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm2_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-58h]
  float splineT; // [rsp+80h] [rbp+8h]

  v4 = UFG::qVector3::msZero.y;
  v5 = this->mNumSplines;
  v6 = 0.0;
  result->x = UFG::qVector3::msZero.x;
  v7 = UFG::qVector3::msZero.z;
  result->y = v4;
  v8 = 0;
  v9 = 0;
  v10 = t;
  v11 = result;
  v12 = this;
  v13 = FLOAT_3_4028235e38;
  result->z = v7;
  v14 = pos;
  if ( v5 )
  {
    v15 = 0i64;
    do
    {
      v16 = v12->mSplineOffsetTable.mOffset;
      if ( v16 )
        v17 = (signed __int64)&v12->mSplineOffsetTable + v16;
      else
        v17 = 0i64;
      v18 = v15 + v17;
      v19 = *(UFG::qBezierSplineMemImaged **)(v15 + v17);
      if ( v19 )
        v19 = (UFG::qBezierSplineMemImaged *)((char *)v19 + v18);
      splineT = 0.0;
      UFG::qBezierSplineMemImaged::ClosestPoint3D_Fast(v19, &resulta, v14, &splineT);
      v20 = resulta.y;
      v21 = resulta.z;
      v22 = (float)((float)((float)(resulta.y - v14->y) * (float)(resulta.y - v14->y))
                  + (float)((float)(resulta.x - v14->x) * (float)(resulta.x - v14->x)))
          + (float)((float)(resulta.z - v14->z) * (float)(resulta.z - v14->z));
      if ( v22 < v13 )
      {
        v6 = splineT;
        v11->x = resulta.x;
        v11->y = v20;
        v13 = v22;
        v8 = v9;
        v11->z = v21;
      }
      ++v9;
      v15 += 8i64;
    }
    while ( v9 < v5 );
  }
  if ( v10 )
    *v10 = UFG::qBezierPathMemImaged::GetPathTFromSplineT(v12, v8, v6);
  return v11;
}

// File Line: 1356
// RVA: 0x172370
UFG::RoadNetworkLane *__fastcall UFG::qBezierPathCollectionMemImaged::GetPath(UFG::RoadNetworkConnection *this, unsigned int index)
{
  __int64 v2; // rax
  char *v3; // rcx
  __int64 v4; // rax
  signed __int64 v5; // rdx
  UFG::RoadNetworkLane *result; // rax

  v2 = this->mLaneList.mOffset;
  if ( v2 )
    v3 = (char *)&this->mLaneList + v2;
  else
    v3 = 0i64;
  v4 = index;
  v5 = (signed __int64)&v3[8 * v4];
  result = *(UFG::RoadNetworkLane **)&v3[8 * v4];
  if ( result )
    result = (UFG::RoadNetworkLane *)((char *)result + v5);
  return result;
}

