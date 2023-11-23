// File Line: 347
// RVA: 0x16DCC0
void __fastcall UFG::qBezierSplineMemImaged::FindCurveByLookup(
        UFG::qBezierSplineMemImaged *this,
        const float splineT,
        float *curveT,
        unsigned int *curveIndex)
{
  UFG::qBezierSplineMemImaged *v6; // r10
  unsigned int mNumKnots; // eax
  unsigned int v8; // esi
  int v9; // r11d
  float mLength; // xmm4_4
  int v11; // r9d
  unsigned int v12; // ebx
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  __int64 mOffset; // r8
  unsigned int v17; // edi
  __int64 v18; // rax
  char *v19; // rdx
  char *v20; // rdx

  v6 = this;
  if ( splineT == 0.0 )
  {
    *curveIndex = 0;
    *curveT = 0.0;
  }
  else
  {
    mNumKnots = this->mNumKnots;
    v8 = this->mNumKnots - 1;
    v9 = this->mNumKnots - 2;
    if ( splineT == 1.0 )
    {
      *curveIndex = v9;
      *curveT = 1.0;
    }
    else
    {
      mLength = this->mLength;
      v11 = 0;
      LODWORD(this) = 0;
      v12 = 0;
      v13 = 0.0;
      v14 = mLength;
      v15 = mLength * splineT;
      if ( mNumKnots != 1 )
      {
        mOffset = v6->mLookupTable.mOffset;
        v17 = mNumKnots - 2;
        do
        {
          this = (UFG::qBezierSplineMemImaged *)(v11 + ((unsigned int)(v9 - v11) >> 1));
          if ( (_DWORD)this )
          {
            v18 = (unsigned int)((_DWORD)this - 1);
            if ( mOffset )
              v19 = (char *)&v6->mLookupTable + mOffset;
            else
              v19 = 0i64;
            if ( (_DWORD)v18 == v17 )
              v13 = mLength;
            else
              v13 = *(float *)&v19[4 * v18];
          }
          else
          {
            v13 = 0.0;
          }
          if ( mOffset )
            v20 = (char *)&v6->mLookupTable + mOffset;
          else
            v20 = 0i64;
          if ( (_DWORD)this == v17 )
            v14 = mLength;
          else
            v14 = *(float *)&v20[4 * (_QWORD)this];
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
      *curveIndex = (unsigned int)this;
      *curveT = (float)(v15 - v13) / (float)(v14 - v13);
    }
  }
}

// File Line: 397
// RVA: 0x171C70
void __fastcall UFG::qBezierSplineMemImaged::GetPositionAndTangent(
        UFG::qBezierSplineMemImaged *this,
        float splineT,
        UFG::qVector3 *position,
        UFG::qVector3 *tangent)
{
  __int64 mOffset; // rax
  unsigned int v8; // edx
  float v9; // xmm13_4
  unsigned int mNumKnots; // r8d
  unsigned int v11; // ecx
  float v12; // xmm13_4
  unsigned int v13; // r9d
  __int64 v14; // rax
  unsigned int v15; // r10d
  float v16; // xmm14_4
  char *v17; // r8
  __int64 v18; // rax
  __int64 v19; // rcx
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
  unsigned int v31; // [rsp+C0h] [rbp+8h] BYREF
  float v32; // [rsp+D0h] [rbp+18h] BYREF

  mOffset = this->mLookupTable.mOffset;
  if ( mOffset && (UFG::qOffset64<UFG::qBezierLookup *> *)((char *)&this->mLookupTable + mOffset) && this->mLength > 0.0 )
  {
    UFG::qBezierSplineMemImaged::FindCurveByLookup(this, splineT, &v32, &v31);
    v8 = v31;
    v9 = v32;
  }
  else
  {
    mNumKnots = this->mNumKnots;
    v11 = this->mNumKnots - 1;
    v12 = (float)(int)v11 * splineT;
    v8 = (int)v12;
    if ( (int)v12 >= v11 )
      v8 = mNumKnots - 2;
    v9 = v12 - (float)(int)v8;
  }
  v13 = this->mNumKnots;
  v14 = this->mKnotTable.mOffset;
  v15 = this->mNumKnots - 1;
  v16 = 1.0 - v9;
  if ( v14 )
    v17 = (char *)&this->mKnotTable + v14;
  else
    v17 = 0i64;
  v18 = v8;
  if ( v8 >= v13 )
    v18 = v15;
  v19 = 9 * v18;
  v20 = v8 + 1;
  if ( (unsigned int)v20 >= v13 )
    v20 = v15;
  v21 = (float)((float)(v9 * *(float *)&v17[36 * v20 + 16]) * v9) * v9;
  v22 = (float)((float)((float)(*(float *)&v17[36 * v20 + 8] * 3.0) * v9) * v9) * v16;
  v23 = (float)((float)((float)(v16 * *(float *)&v17[4 * v19 + 16]) * v16) * v16)
      + (float)((float)((float)((float)(*(float *)&v17[4 * v19 + 28] * 3.0) * v9) * v16) * v16);
  v24 = (float)((float)((float)(v16 * *(float *)&v17[4 * v19 + 20]) * v16) * v16)
      + (float)((float)((float)((float)(*(float *)&v17[4 * v19 + 32] * 3.0) * v9) * v16) * v16);
  v25 = (float)((float)((float)(*(float *)&v17[36 * v20 + 4] * 3.0) * v9) * v9) * v16;
  v26 = (float)(v9 * *(float *)&v17[36 * v20 + 20]) * v9;
  position->x = (float)((float)((float)(v9 * *(float *)&v17[36 * v20 + 12]) * v9) * v9)
              + (float)((float)((float)((float)((float)(*(float *)&v17[36 * v20] * 3.0) * v9) * v9) * v16)
                      + (float)((float)((float)((float)(v16 * *(float *)&v17[4 * v19 + 12]) * v16) * v16)
                              + (float)((float)((float)((float)(*(float *)&v17[4 * v19 + 24] * 3.0) * v9) * v16) * v16)));
  position->y = v21 + (float)(v25 + v23);
  position->z = (float)(v22 + v24) + (float)(v26 * v9);
  v27 = (float)((float)((float)(*(float *)&v17[4 * v19 + 24] - *(float *)&v17[4 * v19 + 12]) * 3.0) * v16) * v16;
  v28 = (float)((float)((float)(*(float *)&v17[4 * v19 + 28] - *(float *)&v17[4 * v19 + 16]) * 3.0) * v16) * v16;
  v29 = (float)((float)((float)((float)(*(float *)&v17[36 * v20 + 12] - *(float *)&v17[36 * v20]) * 3.0) * v9) * v9)
      + (float)((float)((float)((float)(*(float *)&v17[36 * v20] - *(float *)&v17[4 * v19 + 24]) * 6.0) * v16) * v9);
  v30 = (float)((float)((float)((float)(*(float *)&v17[36 * v20 + 16] - *(float *)&v17[36 * v20 + 4]) * 3.0) * v9) * v9)
      + (float)((float)((float)((float)(*(float *)&v17[36 * v20 + 4] - *(float *)&v17[4 * v19 + 28]) * 6.0) * v16) * v9);
  tangent->z = (float)((float)((float)((float)((float)(*(float *)&v17[36 * v20 + 20] - *(float *)&v17[36 * v20 + 8])
                                             * 3.0)
                                     * v9)
                             * v9)
                     + (float)((float)((float)((float)(*(float *)&v17[36 * v20 + 8] - *(float *)&v17[4 * v19 + 32]) * 6.0)
                                     * v16)
                             * v9))
             + (float)((float)((float)((float)(*(float *)&v17[4 * v19 + 32] - *(float *)&v17[4 * v19 + 20]) * 3.0) * v16)
                     * v16);
  tangent->x = v29 + v27;
  tangent->y = v30 + v28;
}

// File Line: 437
// RVA: 0x1719F0
UFG::qVector3 *__fastcall UFG::qBezierSplineMemImaged::GetPosition(
        UFG::qBezierSplineMemImaged *this,
        UFG::qVector3 *result,
        float splineT)
{
  __int64 mOffset; // rax
  unsigned int v6; // r8d
  float v7; // xmm1_4
  unsigned int mNumKnots; // edx
  unsigned int v9; // ecx
  float v10; // xmm1_4
  unsigned int v11; // ecx
  __int64 v12; // rax
  unsigned int v13; // r10d
  float v14; // xmm12_4
  char *v15; // r9
  __int64 v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rax
  __int64 v19; // rcx
  UFG::qVector3 *v20; // rax
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm5_4
  float v24; // xmm11_4
  float v25; // xmm10_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  unsigned int v29; // [rsp+A0h] [rbp+8h] BYREF
  float v30; // [rsp+A8h] [rbp+10h] BYREF

  mOffset = this->mLookupTable.mOffset;
  if ( mOffset && (UFG::qOffset64<UFG::qBezierLookup *> *)((char *)&this->mLookupTable + mOffset) && this->mLength > 0.0 )
  {
    UFG::qBezierSplineMemImaged::FindCurveByLookup(this, splineT, &v30, &v29);
    v6 = v29;
    v7 = v30;
  }
  else
  {
    mNumKnots = this->mNumKnots;
    v9 = this->mNumKnots - 1;
    v10 = (float)(int)v9 * splineT;
    v6 = (int)v10;
    if ( (int)v10 >= v9 )
      v6 = mNumKnots - 2;
    v7 = v10 - (float)(int)v6;
  }
  v11 = this->mNumKnots;
  v12 = this->mKnotTable.mOffset;
  v13 = this->mNumKnots - 1;
  v14 = 1.0 - v7;
  if ( v12 )
    v15 = (char *)&this->mKnotTable + v12;
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
  v20 = result;
  v21 = (float)((float)(*(float *)&v15[4 * v19 + 4] * 3.0) * v7) * v7;
  v22 = (float)((float)(*(float *)&v15[4 * v19 + 8] * 3.0) * v7) * v7;
  v23 = (float)(*(float *)&v15[4 * v17 + 32] * 3.0) * v7;
  v24 = (float)((float)(v7 * *(float *)&v15[4 * v19 + 20]) * v7) * v7;
  v25 = (float)((float)(v7 * *(float *)&v15[4 * v19 + 16]) * v7) * v7;
  v26 = (float)((float)((float)((float)((float)(v14 * *(float *)&v15[4 * v17 + 12]) * v14) * v14)
                      + (float)((float)((float)((float)(*(float *)&v15[4 * v17 + 24] * 3.0) * v7) * v14) * v14))
              + (float)((float)((float)((float)(*(float *)&v15[4 * v19] * 3.0) * v7) * v7) * v14))
      + (float)((float)((float)(v7 * *(float *)&v15[4 * v19 + 12]) * v7) * v7);
  v27 = (float)((float)((float)(v14 * *(float *)&v15[4 * v17 + 16]) * v14) * v14)
      + (float)((float)((float)((float)(*(float *)&v15[4 * v17 + 28] * 3.0) * v7) * v14) * v14);
  v28 = (float)((float)((float)(v14 * *(float *)&v15[4 * v17 + 20]) * v14) * v14) + (float)((float)(v23 * v14) * v14);
  result->x = v26;
  result->y = (float)(v27 + (float)(v21 * v14)) + v25;
  result->z = (float)(v28 + (float)(v22 * v14)) + v24;
  return v20;
}

// File Line: 467
// RVA: 0x172930
UFG::qVector3 *__fastcall UFG::qBezierSplineMemImaged::GetTangent(
        UFG::qBezierSplineMemImaged *this,
        UFG::qVector3 *result,
        float splineT)
{
  float v5; // xmm1_4
  __int64 mOffset; // rax
  unsigned int v7; // edx
  float v8; // xmm12_4
  unsigned int mNumKnots; // r8d
  unsigned int v10; // ecx
  float v11; // xmm12_4
  unsigned int v12; // r9d
  __int64 v13; // rax
  unsigned int v14; // r10d
  float v15; // xmm13_4
  char *v16; // r8
  __int64 v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rax
  __int64 v20; // rdx
  UFG::qVector3 *v21; // rax
  float v22; // xmm10_4
  float v23; // xmm9_4
  float v24; // xmm3_4
  float v25; // xmm5_4
  float v26; // xmm4_4
  float curveT; // [rsp+B0h] [rbp+8h] BYREF
  unsigned int curveIndex; // [rsp+C0h] [rbp+18h] BYREF

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
  mOffset = this->mLookupTable.mOffset;
  if ( mOffset && (UFG::qOffset64<UFG::qBezierLookup *> *)((char *)&this->mLookupTable + mOffset) && this->mLength > 0.0 )
  {
    UFG::qBezierSplineMemImaged::FindCurveByLookup(this, v5, &curveT, &curveIndex);
    v7 = curveIndex;
    v8 = curveT;
  }
  else
  {
    mNumKnots = this->mNumKnots;
    v10 = this->mNumKnots - 1;
    v11 = (float)(int)v10 * v5;
    v7 = (int)v11;
    if ( (int)v11 >= v10 )
      v7 = mNumKnots - 2;
    v8 = v11 - (float)(int)v7;
  }
  v12 = this->mNumKnots;
  v13 = this->mKnotTable.mOffset;
  v14 = this->mNumKnots - 1;
  v15 = 1.0 - v8;
  if ( v13 )
    v16 = (char *)&this->mKnotTable + v13;
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
  v21 = result;
  v22 = (float)((float)((float)(*(float *)&v16[4 * v18 + 28] - *(float *)&v16[4 * v18 + 16]) * 3.0) * v15) * v15;
  v23 = (float)((float)((float)(*(float *)&v16[4 * v18 + 32] - *(float *)&v16[4 * v18 + 20]) * 3.0) * v15) * v15;
  v24 = (float)((float)((float)(*(float *)&v16[4 * v20 + 20] - *(float *)&v16[4 * v20 + 8]) * 3.0) * v8) * v8;
  v25 = (float)((float)((float)(*(float *)&v16[4 * v20 + 8] - *(float *)&v16[4 * v18 + 32]) * 6.0) * v15) * v8;
  v26 = (float)((float)((float)((float)(*(float *)&v16[4 * v20 + 16] - *(float *)&v16[4 * v20 + 4]) * 3.0) * v8) * v8)
      + (float)((float)((float)((float)(*(float *)&v16[4 * v20 + 4] - *(float *)&v16[4 * v18 + 28]) * 6.0) * v15) * v8);
  result->x = (float)((float)((float)((float)(*(float *)&v16[4 * v18 + 24] - *(float *)&v16[4 * v18 + 12]) * 3.0) * v15)
                    * v15)
            + (float)((float)((float)((float)((float)(*(float *)&v16[4 * v20 + 12] - *(float *)&v16[4 * v20]) * 3.0) * v8)
                            * v8)
                    + (float)((float)((float)((float)(*(float *)&v16[4 * v20] - *(float *)&v16[4 * v18 + 24]) * 6.0)
                                    * v15)
                            * v8));
  result->y = v22 + v26;
  result->z = v23 + (float)(v24 + v25);
  return v21;
}

// File Line: 790
// RVA: 0x1685D0
void __fastcall UFG::qBezierSplineMemImaged::ClosestPoint3D_CurveFast(
        UFG::qBezierSplineMemImaged *this,
        UFG::qVector3 *pos,
        unsigned int curveIndex,
        float *curveT,
        UFG::qVector3 *closestPoint)
{
  __int64 mOffset; // rax
  char *v7; // r10
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm4_4
  float v11; // xmm5_4
  __int64 v12; // rdx
  __int64 v13; // r8
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

  mOffset = this->mKnotTable.mOffset;
  if ( mOffset )
    v7 = (char *)&this->mKnotTable + mOffset;
  else
    v7 = 0i64;
  x = pos->x;
  y = pos->y;
  z = pos->z;
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
  v37 = v15;
  v38 = v16;
  v23 = (float)((float)((float)(y - v16) * (float)(y - v16)) + (float)((float)(pos->x - v15) * (float)(pos->x - v15)))
      + (float)((float)(pos->z - v17) * (float)(pos->z - v17));
  v40 = v17;
  v24 = (float)((float)((float)(pos->y - v19) * (float)(pos->y - v19)) + (float)((float)(x - v18) * (float)(x - v18)))
      + (float)((float)(z - v20) * (float)(z - v20));
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
      v35 = (float)(pos->x - v32) * (float)(pos->x - v32);
      v36 = (float)(pos->z - v34) * (float)(pos->z - v34);
      if ( v23 >= v24 )
      {
        v11 = *(float *)&v26;
        v15 = v32;
        v38 = v33;
        v40 = v34;
        v39 = v11;
        v37 = v32;
        v23 = (float)((float)((float)(pos->y - v33) * (float)(pos->y - v33)) + v35) + v36;
      }
      else
      {
        v11 = v39;
        v22 = v26;
        v18 = v32;
        v19 = v33;
        v20 = v34;
        v15 = v37;
        v24 = (float)((float)((float)(pos->y - v33) * (float)(pos->y - v33)) + v35) + v36;
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
float __fastcall UFG::qBezierSplineMemImaged::CurveIndexAndCurveTtoSplineT(
        UFG::qBezierSplineMemImaged *this,
        int curveIndex,
        float curveT)
{
  __int64 mOffset; // rax
  float mLength; // xmm3_4
  char *v5; // r8
  float v6; // xmm1_4
  __int64 v7; // r9
  float v8; // xmm0_4
  float result; // xmm0_4

  mOffset = this->mLookupTable.mOffset;
  mLength = 0.0;
  if ( mOffset && (v5 = (char *)&this->mLookupTable + mOffset) != 0i64 && (v6 = this->mLength, v6 > 0.0) )
  {
    if ( curveIndex )
    {
      v7 = (unsigned int)(curveIndex - 1);
      if ( (_DWORD)v7 == this->mNumKnots - 2 )
        mLength = this->mLength;
      else
        mLength = *(float *)&v5[4 * v7];
    }
    if ( curveIndex == this->mNumKnots - 2 )
      v8 = this->mLength;
    else
      v8 = *(float *)&v5[4 * curveIndex];
    return (float)((float)((float)(v8 - mLength) * curveT) + mLength) / v6;
  }
  else
  {
    result = (float)((float)curveIndex * (float)(1.0 / (float)(this->mNumKnots - 1)))
           + (float)((float)(1.0 / (float)(this->mNumKnots - 1)) * curveT);
    if ( result >= 1.0 )
    {
      return *(float *)&FLOAT_1_0;
    }
    else if ( result <= 0.0 )
    {
      return 0.0;
    }
  }
  return result;
}

// File Line: 871
// RVA: 0x168980
UFG::qVector3 *__fastcall UFG::qBezierSplineMemImaged::ClosestPoint3D_Fast(
        UFG::qBezierSplineMemImaged *this,
        UFG::qVector3 *result,
        UFG::qVector3 *pos,
        float *splineT)
{
  __int64 mOffset; // rax
  float v5; // xmm3_4
  unsigned int v6; // ebx
  unsigned int v7; // r10d
  char *v12; // r11
  unsigned int mNumKnots; // r8d
  __int64 v14; // rax
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  int v18; // edx
  float *v19; // rcx
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float *v23; // rcx
  float v24; // xmm6_4
  __int64 v25; // rax
  float *v26; // rcx
  float mLength; // xmm0_4
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
  float v43; // [rsp+30h] [rbp-59h] BYREF
  UFG::qVector3 closestPoint; // [rsp+38h] [rbp-51h] BYREF
  UFG::qVector3 v45; // [rsp+48h] [rbp-41h] BYREF
  float curveT; // [rsp+F0h] [rbp+67h] BYREF

  mOffset = this->mKnotTable.mOffset;
  v5 = FLOAT_3_4028235e38;
  v6 = -1;
  v7 = 0;
  if ( mOffset )
    v12 = (char *)&this->mKnotTable + mOffset;
  else
    v12 = 0i64;
  mNumKnots = this->mNumKnots;
  v14 = 0i64;
  if ( (int)this->mNumKnots >= 4 )
  {
    x = pos->x;
    y = pos->y;
    z = pos->z;
    v18 = 2;
    v19 = (float *)(v12 + 20);
    v14 = 4i64 * (((mNumKnots - 4) >> 2) + 1);
    do
    {
      if ( (float)((float)((float)((float)(x - *(v19 - 2)) * (float)(x - *(v19 - 2)))
                         + (float)((float)(y - *(v19 - 1)) * (float)(y - *(v19 - 1))))
                 + (float)((float)(z - *v19) * (float)(z - *v19))) < v5 )
      {
        v5 = (float)((float)((float)(x - *(v19 - 2)) * (float)(x - *(v19 - 2)))
                   + (float)((float)(y - *(v19 - 1)) * (float)(y - *(v19 - 1))))
           + (float)((float)(z - *v19) * (float)(z - *v19));
        v6 = v7;
      }
      if ( (float)((float)((float)((float)(x - v19[7]) * (float)(x - v19[7]))
                         + (float)((float)(y - v19[8]) * (float)(y - v19[8])))
                 + (float)((float)(z - v19[9]) * (float)(z - v19[9]))) < v5 )
      {
        v5 = (float)((float)((float)(x - v19[7]) * (float)(x - v19[7]))
                   + (float)((float)(y - v19[8]) * (float)(y - v19[8])))
           + (float)((float)(z - v19[9]) * (float)(z - v19[9]));
        v6 = v18 - 1;
      }
      if ( (float)((float)((float)((float)(x - v19[16]) * (float)(x - v19[16]))
                         + (float)((float)(y - v19[17]) * (float)(y - v19[17])))
                 + (float)((float)(z - v19[18]) * (float)(z - v19[18]))) < v5 )
      {
        v5 = (float)((float)((float)(x - v19[16]) * (float)(x - v19[16]))
                   + (float)((float)(y - v19[17]) * (float)(y - v19[17])))
           + (float)((float)(z - v19[18]) * (float)(z - v19[18]));
        v6 = v18;
      }
      if ( (float)((float)((float)((float)(x - v19[25]) * (float)(x - v19[25]))
                         + (float)((float)(y - v19[26]) * (float)(y - v19[26])))
                 + (float)((float)(z - v19[27]) * (float)(z - v19[27]))) < v5 )
      {
        v5 = (float)((float)((float)(x - v19[25]) * (float)(x - v19[25]))
                   + (float)((float)(y - v19[26]) * (float)(y - v19[26])))
           + (float)((float)(z - v19[27]) * (float)(z - v19[27]));
        v6 = v18 + 1;
      }
      v7 += 4;
      v19 += 36;
      v18 += 4;
    }
    while ( v7 < mNumKnots - 3 );
  }
  if ( v7 < mNumKnots )
  {
    v23 = (float *)&v12[32 * v14 + 20 + 4 * v14];
    do
    {
      v20 = pos->x;
      v21 = pos->y;
      v22 = pos->z;
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
    while ( v7 < mNumKnots );
  }
  if ( !v6 )
  {
    v24 = 0.0;
    curveT = 0.0;
    UFG::qBezierSplineMemImaged::ClosestPoint3D_CurveFast(this, pos, 0, &curveT, &closestPoint);
    v25 = this->mLookupTable.mOffset;
    if ( v25 )
    {
      v26 = (float *)((char *)&this->mLookupTable + v25);
      if ( v26 )
      {
        mLength = this->mLength;
        if ( mLength > 0.0 )
        {
          if ( this->mNumKnots == 2 )
            v24 = (float)(mLength * curveT) / mLength;
          else
            v24 = (float)(*v26 * curveT) / mLength;
          goto LABEL_32;
        }
      }
    }
    v28 = (float)((float)(1.0 / (float)(this->mNumKnots - 1)) * curveT)
        + (float)((float)(1.0 / (float)(this->mNumKnots - 1)) * 0.0);
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
    *splineT = v24;
    result->x = v29;
    v31 = closestPoint.z;
    result->y = v30;
    result->z = v31;
    return result;
  }
  if ( v6 == mNumKnots - 1 )
  {
    curveT = 0.0;
    UFG::qBezierSplineMemImaged::ClosestPoint3D_CurveFast(this, pos, mNumKnots - 2, &curveT, &closestPoint);
    v32 = UFG::qBezierSplineMemImaged::CurveIndexAndCurveTtoSplineT(this, this->mNumKnots - 2, curveT);
    result->x = closestPoint.x;
    v33 = closestPoint.z;
    *splineT = v32;
    v34 = closestPoint.y;
    result->z = v33;
    result->y = v34;
  }
  else
  {
    curveT = 0.0;
    UFG::qBezierSplineMemImaged::ClosestPoint3D_CurveFast(this, pos, v6 - 1, &curveT, &closestPoint);
    v43 = 0.0;
    UFG::qBezierSplineMemImaged::ClosestPoint3D_CurveFast(this, pos, v6, &v43, &v45);
    v35 = closestPoint.x;
    v36 = closestPoint.y;
    v37 = v45.x;
    v38 = v45.y;
    v39 = closestPoint.z;
    v40 = v45.z;
    if ( (float)((float)((float)((float)(pos->y - closestPoint.y) * (float)(pos->y - closestPoint.y))
                       + (float)((float)(pos->x - closestPoint.x) * (float)(pos->x - closestPoint.x)))
               + (float)((float)(pos->z - closestPoint.z) * (float)(pos->z - closestPoint.z))) >= (float)((float)((float)((float)(pos->y - v45.y) * (float)(pos->y - v45.y)) + (float)((float)(pos->x - v45.x) * (float)(pos->x - v45.x))) + (float)((float)(pos->z - v45.z) * (float)(pos->z - v45.z))) )
    {
      v41 = UFG::qBezierSplineMemImaged::CurveIndexAndCurveTtoSplineT(this, v6, v43);
      result->x = v37;
      result->y = v38;
      result->z = v40;
    }
    else
    {
      v41 = UFG::qBezierSplineMemImaged::CurveIndexAndCurveTtoSplineT(this, v6 - 1, curveT);
      result->x = v35;
      result->y = v36;
      result->z = v39;
    }
    *splineT = v41;
  }
  return result;
}

// File Line: 978
// RVA: 0x171620
float __fastcall UFG::qBezierPathMemImaged::GetPathTFromSplineT(
        UFG::qBezierPathMemImaged *this,
        const unsigned int splineIndex,
        float splineT)
{
  unsigned int mNumSplines; // ebx
  char *v4; // r8
  __int64 v5; // r11
  float v7; // xmm0_4
  unsigned int v8; // eax
  __int64 v9; // r9
  __int64 mOffset; // rcx
  char *v11; // rdx
  char *v12; // rcx
  __int64 v13; // rdx
  char *v14; // rcx
  __int64 v16; // rax
  char *v17; // rcx
  __int64 v18; // rax

  mNumSplines = this->mNumSplines;
  v4 = 0i64;
  v5 = splineIndex;
  v7 = 0.0;
  v8 = 0;
  if ( this->mNumSplines )
  {
    v9 = 0i64;
    while ( v8 != (_DWORD)v5 )
    {
      mOffset = this->mSplineOffsetTable.mOffset;
      if ( mOffset )
        v11 = (char *)&this->mSplineOffsetTable + mOffset;
      else
        v11 = 0i64;
      v12 = &v11[v9];
      v13 = *(_QWORD *)&v11[v9];
      if ( v13 )
        v14 = &v12[v13];
      else
        v14 = 0i64;
      v7 = v7 + *((float *)v14 + 1);
      ++v8;
      v9 += 8i64;
      if ( v8 >= mNumSplines )
        return v7 / this->mLength;
    }
    v16 = this->mSplineOffsetTable.mOffset;
    if ( v16 )
      v17 = (char *)&this->mSplineOffsetTable + v16;
    else
      v17 = 0i64;
    v18 = *(_QWORD *)&v17[8 * v5];
    if ( v18 )
      v4 = &v17[8 * v5 + v18];
    v7 = v7 + (float)(splineT * *((float *)v4 + 1));
  }
  return v7 / this->mLength;
}

// File Line: 1060
// RVA: 0x1723A0
__int64 __fastcall UFG::qBezierPathMemImaged::GetSplineParameters(
        UFG::qBezierPathMemImaged *this,
        const float pathT,
        float *splineT)
{
  unsigned int mNumSplines; // r11d
  float v4; // xmm1_4
  unsigned int v5; // edx
  __int64 mOffset; // r9
  __int64 v9; // r8
  char *v10; // rax
  char *v11; // rcx
  __int64 v12; // rax
  float v13; // xmm0_4
  __int64 result; // rax

  mNumSplines = this->mNumSplines;
  v4 = pathT * this->mLength;
  v5 = 0;
  if ( this->mNumSplines )
  {
    mOffset = this->mSplineOffsetTable.mOffset;
    v9 = 0i64;
    while ( 1 )
    {
      v10 = mOffset ? (char *)&this->mSplineOffsetTable + mOffset : 0i64;
      v11 = &v10[v9];
      v12 = *(_QWORD *)&v10[v9];
      if ( v12 )
        v12 += (__int64)v11;
      v13 = *(float *)(v12 + 4);
      if ( v4 < v13 )
        break;
      ++v5;
      v9 += 8i64;
      v4 = v4 - v13;
      if ( v5 >= mNumSplines )
        goto LABEL_10;
    }
    result = v5;
    *splineT = v4 / v13;
  }
  else
  {
LABEL_10:
    *splineT = 1.0;
    return this->mNumSplines - 1;
  }
  return result;
}

// File Line: 1298
// RVA: 0x168450
UFG::qVector3 *__fastcall UFG::qBezierPathMemImaged::ClosestPoint3D(
        UFG::qBezierPathMemImaged *this,
        UFG::qVector3 *result,
        UFG::qVector3 *pos,
        float *t)
{
  float y; // xmm1_4
  unsigned int mNumSplines; // ebp
  float v6; // xmm7_4
  float z; // xmm0_4
  unsigned int v8; // r15d
  unsigned int v9; // ebx
  float v13; // xmm6_4
  __int64 v15; // rsi
  __int64 mOffset; // rax
  char *v17; // rcx
  char *v18; // rax
  UFG::qBezierSplineMemImaged *v19; // rcx
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm2_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-58h] BYREF
  float splineT; // [rsp+80h] [rbp+8h] BYREF

  y = UFG::qVector3::msZero.y;
  mNumSplines = this->mNumSplines;
  v6 = 0.0;
  result->x = UFG::qVector3::msZero.x;
  z = UFG::qVector3::msZero.z;
  result->y = y;
  v8 = 0;
  v9 = 0;
  v13 = FLOAT_3_4028235e38;
  result->z = z;
  if ( mNumSplines )
  {
    v15 = 0i64;
    do
    {
      mOffset = this->mSplineOffsetTable.mOffset;
      if ( mOffset )
        v17 = (char *)&this->mSplineOffsetTable + mOffset;
      else
        v17 = 0i64;
      v18 = &v17[v15];
      v19 = *(UFG::qBezierSplineMemImaged **)&v17[v15];
      if ( v19 )
        v19 = (UFG::qBezierSplineMemImaged *)((char *)v19 + (_QWORD)v18);
      splineT = 0.0;
      UFG::qBezierSplineMemImaged::ClosestPoint3D_Fast(v19, &resulta, pos, &splineT);
      v20 = resulta.y;
      v21 = resulta.z;
      v22 = (float)((float)((float)(resulta.y - pos->y) * (float)(resulta.y - pos->y))
                  + (float)((float)(resulta.x - pos->x) * (float)(resulta.x - pos->x)))
          + (float)((float)(resulta.z - pos->z) * (float)(resulta.z - pos->z));
      if ( v22 < v13 )
      {
        v6 = splineT;
        result->x = resulta.x;
        result->y = v20;
        v13 = v22;
        v8 = v9;
        result->z = v21;
      }
      ++v9;
      v15 += 8i64;
    }
    while ( v9 < mNumSplines );
  }
  if ( t )
    *t = UFG::qBezierPathMemImaged::GetPathTFromSplineT(this, v8, v6);
  return result;
}

// File Line: 1356
// RVA: 0x172370
UFG::RoadNetworkLane *__fastcall UFG::qBezierPathCollectionMemImaged::GetPath(
        UFG::RoadNetworkConnection *this,
        unsigned int index)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  UFG::RoadNetworkLane **v4; // rdx
  UFG::RoadNetworkLane *result; // rax

  mOffset = this->mLaneList.mOffset;
  if ( mOffset )
    v3 = (char *)&this->mLaneList + mOffset;
  else
    v3 = 0i64;
  v4 = (UFG::RoadNetworkLane **)&v3[8 * index];
  result = *v4;
  if ( *v4 )
    return (UFG::RoadNetworkLane *)((char *)result + (_QWORD)v4);
  return result;
}

