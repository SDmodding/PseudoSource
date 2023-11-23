// File Line: 36
// RVA: 0x160200
void __fastcall UFG::HermiteCurve::HermiteCurve(
        UFG::HermiteCurve *this,
        int maxNumControlPoints,
        UFG::qMemoryPool *pMemPool,
        char *allocCustomName)
{
  const char *v7; // r8
  char *v8; // rax
  unsigned __int64 v9; // rsi
  UFG::qMemoryPool *v10; // rcx
  const char *v11; // r8

  this->mNumControlPoints = 0;
  this->mMaxNumControlPoints = maxNumControlPoints;
  this->mpMemoryPool = pMemPool;
  if ( pMemPool )
  {
    v7 = "HermiteCurve.mControlPoints";
    if ( allocCustomName )
      v7 = allocCustomName;
    v8 = UFG::qMemoryPool::Allocate(pMemPool, 24i64 * maxNumControlPoints, v7, 0x1000ui64, 1u);
  }
  else
  {
    v9 = 24i64 * maxNumControlPoints;
    if ( !is_mul_ok(maxNumControlPoints, 0x18ui64) )
      v9 = -1i64;
    v10 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v10 = UFG::gMainMemoryPool;
    }
    v11 = "HermiteCurve.mControlPoints";
    if ( allocCustomName )
      v11 = allocCustomName;
    v8 = UFG::qMemoryPool::Allocate(v10, v9, v11, 0x1000ui64, 1u);
  }
  this->mControlPoints = (UFG::HermiteControlPoint *)v8;
}

// File Line: 53
// RVA: 0x162E20
void __fastcall UFG::HermiteCurve::~HermiteCurve(UFG::HermiteCurve *this)
{
  UFG::qMemoryPool *mpMemoryPool; // rax
  UFG::HermiteControlPoint *mControlPoints; // rdx

  mpMemoryPool = this->mpMemoryPool;
  mControlPoints = this->mControlPoints;
  if ( mpMemoryPool )
  {
    UFG::qMemoryPool::Free(mpMemoryPool, mControlPoints);
  }
  else if ( mControlPoints )
  {
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mControlPoints);
  }
}

// File Line: 102
// RVA: 0x1716D0
// local variable allocation has failed, the output may be wrong!
void __fastcall UFG::HermiteCurve::GetPosition(UFG::HermiteCurve *this, double t, UFG::qVector3 *vOutPosition)
{
  __m128 v4; // xmm4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  __m128 v9; // xmm0
  __m128 v10; // xmm0
  float v11; // xmm1_4
  int v12; // ecx
  float v13; // xmm4_4
  int v14; // eax
  int v15; // edx
  __int64 v16; // rcx
  UFG::HermiteControlPoint *v17; // rax
  float v18; // xmm0_4
  float v19; // xmm1_4
  UFG::HermiteControlPoint *v20; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::HermiteControlPoint *mControlPoints; // r8
  __int64 v24; // rdx
  float v25; // xmm11_4
  float v26; // xmm3_4
  float v27; // xmm6_4
  float v28; // xmm12_4
  float v29; // xmm11_4
  float v30; // xmm12_4
  float v31; // xmm3_4
  float v32; // xmm14_4
  float v33; // xmm15_4

  v4 = *(__m128 *)&t;
  if ( this->mNumControlPoints >= 2 )
  {
    v8 = (float)this->mNumControlPoints - 1.0;
    if ( *(float *)&t >= 0.0 )
    {
      if ( *(float *)&t > v8 )
      {
        v10 = *(__m128 *)&t;
        v10.m128_f32[0] = fmodf(*(float *)&t, v8);
        v4 = v10;
      }
    }
    else
    {
      v9 = *(__m128 *)&t;
      v9.m128_f32[0] = fmodf(*(float *)&t, v8);
      v4 = v9;
      v4.m128_f32[0] = v9.m128_f32[0] + v8;
    }
    v11 = v4.m128_f32[0];
    v12 = (int)v4.m128_f32[0];
    if ( (int)v4.m128_f32[0] != 0x80000000 && (float)v12 != v4.m128_f32[0] )
      v11 = (float)(v12 - (_mm_movemask_ps(_mm_unpacklo_ps(v4, v4)) & 1));
    v13 = v4.m128_f32[0] - v11;
    v14 = (int)v11;
    v15 = (int)v11 + 1;
    if ( v13 >= 0.001 )
    {
      if ( v13 <= UFG::HermiteCurve::kOneMinusEpsilon )
      {
        mControlPoints = this->mControlPoints;
        v24 = v15;
        v25 = (float)(v13 * v13) * 3.0;
        v26 = (float)(v13 * v13) * v13;
        v27 = v26 - (float)(v13 * v13);
        v28 = (float)(v26 * 2.0) - v25;
        v29 = v25 - (float)(v26 * 2.0);
        v30 = v28 + 1.0;
        v31 = (float)(v26 - (float)((float)(v13 * v13) * 2.0)) + v13;
        v32 = (float)((float)((float)(mControlPoints[v14].mPosition.y * v30)
                            + (float)(mControlPoints[v24].mPosition.y * v29))
                    + (float)(mControlPoints[v14].mTangent.y * v31))
            + (float)(mControlPoints[v24].mTangent.y * v27);
        v33 = (float)((float)((float)(mControlPoints[v14].mPosition.z * v30)
                            + (float)(mControlPoints[v24].mPosition.z * v29))
                    + (float)(mControlPoints[v14].mTangent.z * v31))
            + (float)(mControlPoints[v24].mTangent.z * v27);
        vOutPosition->x = (float)((float)((float)(mControlPoints[v14].mPosition.x * v30)
                                        + (float)(mControlPoints[v24].mPosition.x * v29))
                                + (float)(mControlPoints[v14].mTangent.x * v31))
                        + (float)(mControlPoints[v24].mTangent.x * v27);
        vOutPosition->y = v32;
        vOutPosition->z = v33;
      }
      else
      {
        v20 = this->mControlPoints;
        y = v20[v15].mPosition.y;
        z = v20[v15].mPosition.z;
        vOutPosition->x = v20[v15].mPosition.x;
        vOutPosition->y = y;
        vOutPosition->z = z;
      }
    }
    else
    {
      v16 = v14;
      v17 = this->mControlPoints;
      v18 = v17[v16].mPosition.y;
      v19 = v17[v16].mPosition.z;
      vOutPosition->x = v17[v16].mPosition.x;
      vOutPosition->y = v18;
      vOutPosition->z = v19;
    }
  }
  else
  {
    v6 = UFG::qVector3::msZero.y;
    v7 = UFG::qVector3::msZero.z;
    vOutPosition->x = UFG::qVector3::msZero.x;
    vOutPosition->y = v6;
    vOutPosition->z = v7;
  }
}

// File Line: 204
// RVA: 0x172620
void __fastcall UFG::HermiteCurve::GetTangent(UFG::HermiteCurve *this, float t, UFG::qVector3 *vOutTangent)
{
  int mNumControlPoints; // edi
  float v5; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  UFG::HermiteControlPoint *v11; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  signed int v14; // ecx
  UFG::HermiteControlPoint *mControlPoints; // r8
  __m128i v16; // xmm0
  __int64 v17; // rdx
  __int64 v18; // rcx
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm15_4
  float v29; // [rsp+D0h] [rbp+8h]

  mNumControlPoints = this->mNumControlPoints;
  v5 = t;
  if ( this->mNumControlPoints >= 2 )
  {
    v9 = (float)mNumControlPoints - 1.0;
    if ( t >= 0.0 )
    {
      if ( t > v9 )
        v5 = fmodf(t, v9);
    }
    else
    {
      v5 = fmodf(t, v9) + v9;
    }
    v10 = v5 - (float)(int)(float)(v5 + 0.5);
    if ( v10 < 0.0 )
      LODWORD(v10) ^= _xmm[0];
    if ( v10 >= 0.001 )
    {
      v14 = (int)v5;
      if ( (int)v5 == mNumControlPoints - 1 )
        v14 = mNumControlPoints - 2;
      mControlPoints = this->mControlPoints;
      v16 = _mm_cvtsi32_si128(v14);
      v17 = v14;
      v18 = v14 + 1;
      v19 = v5 - _mm_cvtepi32_ps(v16).m128_f32[0];
      v20 = v19 * v19;
      v29 = v19;
      v21 = v19 * 6.0;
      v22 = v20 * 6.0;
      v23 = v20 * 3.0;
      v24 = v22 - v21;
      v25 = v21 - v22;
      v26 = (float)(v23 - (float)(v29 * 4.0)) + 1.0;
      v27 = v23 - (float)(v29 * 2.0);
      v28 = (float)((float)((float)(mControlPoints[v17].mPosition.y * v24)
                          + (float)(mControlPoints[v18].mPosition.y * v25))
                  + (float)(mControlPoints[v17].mTangent.y * v26))
          + (float)(mControlPoints[v18].mTangent.y * v27);
      *(float *)v16.m128i_i32 = (float)((float)((float)(mControlPoints[v17].mPosition.z * v24)
                                              + (float)(mControlPoints[v18].mPosition.z * v25))
                                      + (float)(mControlPoints[v17].mTangent.z * v26))
                              + (float)(mControlPoints[v18].mTangent.z * v27);
      vOutTangent->x = (float)((float)((float)(mControlPoints[v17].mPosition.x * v24)
                                     + (float)(mControlPoints[v18].mPosition.x * v25))
                             + (float)(mControlPoints[v17].mTangent.x * v26))
                     + (float)(mControlPoints[v18].mTangent.x * v27);
      vOutTangent->y = v28;
      LODWORD(vOutTangent->z) = v16.m128i_i32[0];
    }
    else
    {
      v11 = this->mControlPoints;
      y = v11[(float)(v5 + 0.5)].mTangent.y;
      z = v11[(float)(v5 + 0.5)].mTangent.z;
      vOutTangent->x = v11[(float)(v5 + 0.5)].mTangent.x;
      vOutTangent->y = y;
      vOutTangent->z = z;
    }
  }
  else
  {
    v7 = UFG::qVector3::msZero.y;
    v8 = UFG::qVector3::msZero.z;
    vOutTangent->x = UFG::qVector3::msZero.x;
    vOutTangent->y = v7;
    vOutTangent->z = v8;
  }
}

// File Line: 376
// RVA: 0x165F40
void __fastcall UFG::HermiteCurve::AddControlPoint(
        UFG::HermiteCurve *this,
        UFG::qVector3 *position,
        UFG::qVector3 *tangent)
{
  __int64 mNumControlPoints; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::HermiteControlPoint *mControlPoints; // r9
  __int64 v8; // r10
  __int64 v9; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4
  UFG::HermiteControlPoint *v12; // rcx
  __int64 v13; // rdx

  mNumControlPoints = this->mNumControlPoints;
  if ( (_DWORD)mNumControlPoints != this->mMaxNumControlPoints )
  {
    y = position->y;
    z = position->z;
    mControlPoints = this->mControlPoints;
    v8 = mNumControlPoints;
    mControlPoints[v8].mPosition.x = position->x;
    mControlPoints[v8].mPosition.y = y;
    mControlPoints[v8].mPosition.z = z;
    v9 = this->mNumControlPoints;
    v10 = tangent->y;
    v11 = tangent->z;
    v12 = this->mControlPoints;
    v13 = v9;
    v12[v13].mTangent.x = tangent->x;
    v12[v13].mTangent.y = v10;
    v12[v13].mTangent.z = v11;
    ++this->mNumControlPoints;
  }
}

// File Line: 404
// RVA: 0x17CC70
void __fastcall UFG::HermiteCurve::SetControlPointTangent(UFG::HermiteCurve *this, int i, UFG::qVector3 *tangent)
{
  UFG::HermiteControlPoint *mControlPoints; // rcx
  float y; // xmm0_4
  float z; // xmm1_4
  __int64 v6; // rdx

  if ( i >= 0 && i < this->mNumControlPoints )
  {
    mControlPoints = this->mControlPoints;
    y = tangent->y;
    z = tangent->z;
    v6 = i;
    mControlPoints[v6].mTangent.x = tangent->x;
    mControlPoints[v6].mTangent.y = y;
    mControlPoints[v6].mTangent.z = z;
  }
}

// File Line: 418
// RVA: 0x167E50
void __fastcall UFG::HermiteCurve::ClearControlPoints(UFG::HermiteCurve *this, int startingFrom)
{
  if ( this->mNumControlPoints > startingFrom )
    this->mNumControlPoints = startingFrom;
}

// File Line: 504
// RVA: 0x170EB0
float __fastcall UFG::HermiteCurve::GetLocalClosestPoint(
        UFG::HermiteCurve *this,
        UFG::qVector3 *target_point,
        UFG::qVector3 *closest_point,
        float fHintT,
        float precision,
        float fSpanT,
        unsigned int *nOutIterations)
{
  int mNumControlPoints; // edi
  float v12; // xmm0_4
  float v13; // xmm8_4
  float v14; // xmm10_4
  float v15; // xmm9_4
  float x; // xmm14_4
  float y; // xmm15_4
  float v18; // xmm6_4
  unsigned int v19; // ebx
  float v20; // xmm6_4
  UFG::qVector3 vOutPosition; // [rsp+20h] [rbp-B8h] BYREF

  mNumControlPoints = this->mNumControlPoints;
  if ( this->mNumControlPoints < 2 )
    return 0.0;
  v12 = precision;
  v13 = 0.0;
  if ( precision == 0.0 )
    v12 = FLOAT_10_0;
  v14 = 1.0 / v12;
  v15 = FLOAT_1000000_0;
  if ( fSpanT != -1.234 )
    v14 = v14 * fSpanT;
  x = target_point->x;
  y = target_point->y;
  v18 = fHintT;
  v19 = 0;
  do
  {
    ++v19;
    UFG::HermiteCurve::GetPosition(this, v18, &vOutPosition);
    if ( (float)((float)((float)((float)(vOutPosition.y - y) * (float)(vOutPosition.y - y))
                       + (float)((float)(vOutPosition.x - x) * (float)(vOutPosition.x - x)))
               + (float)((float)(vOutPosition.z - target_point->z) * (float)(vOutPosition.z - target_point->z))) > v15 )
      break;
    v13 = v18;
    v18 = v18 + v14;
    v15 = (float)((float)((float)(vOutPosition.y - y) * (float)(vOutPosition.y - y))
                + (float)((float)(vOutPosition.x - x) * (float)(vOutPosition.x - x)))
        + (float)((float)(vOutPosition.z - target_point->z) * (float)(vOutPosition.z - target_point->z));
    if ( fSpanT != -1.234 && v18 >= (float)(fHintT + fSpanT) )
      break;
  }
  while ( v18 <= (float)((float)mNumControlPoints * 2.0) && v19 < 0x1F4 );
  v20 = fHintT;
  if ( v19 < 0x1F4 )
  {
    do
    {
      v20 = v20 - v14;
      ++v19;
      UFG::HermiteCurve::GetPosition(this, v20, &vOutPosition);
      if ( (float)((float)((float)((float)(vOutPosition.y - y) * (float)(vOutPosition.y - y))
                         + (float)((float)(vOutPosition.x - x) * (float)(vOutPosition.x - x)))
                 + (float)((float)(vOutPosition.z - target_point->z) * (float)(vOutPosition.z - target_point->z))) > v15 )
        break;
      v15 = (float)((float)((float)(vOutPosition.y - y) * (float)(vOutPosition.y - y))
                  + (float)((float)(vOutPosition.x - x) * (float)(vOutPosition.x - x)))
          + (float)((float)(vOutPosition.z - target_point->z) * (float)(vOutPosition.z - target_point->z));
      v13 = v20;
      if ( fSpanT != -1.234 && v20 <= (float)(fHintT - fSpanT) )
        break;
    }
    while ( v20 >= (float)((float)mNumControlPoints * -2.0) && v19 < 0x1F4 );
  }
  UFG::HermiteCurve::GetPosition(this, v13, closest_point);
  if ( nOutIterations )
    *nOutIterations = v19;
  return v13;
}

// File Line: 599
// RVA: 0x170C30
float __fastcall UFG::HermiteCurve::GetLocalClosestPoint(
        UFG::HermiteCurve *this,
        UFG::qVector3 *target_point,
        UFG::qVector3 *closest_point,
        float fHintT,
        float fStartT,
        float fEndT,
        float precision,
        unsigned int *nOutIterations)
{
  float v9; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm10_4
  float v14; // xmm9_4
  float v15; // xmm11_4
  float v16; // xmm8_4
  float x; // xmm13_4
  float y; // xmm14_4
  float z; // xmm15_4
  float v20; // xmm12_4
  float v21; // xmm7_4
  unsigned int v22; // ebx
  float v23; // xmm0_4
  float v24; // xmm0_4
  UFG::qVector3 vOutPosition; // [rsp+20h] [rbp-B8h] BYREF

  v9 = fHintT;
  if ( this->mNumControlPoints < 2 )
    return 0.0;
  v12 = precision;
  v13 = 0.0;
  if ( precision == 0.0 )
    v12 = FLOAT_10_0;
  v14 = fStartT;
  v15 = FLOAT_1000000_0;
  if ( fStartT == -1.234 )
    v14 = 0.0;
  v16 = fEndT;
  if ( fEndT == -1.234 )
    v16 = (float)this->mNumControlPoints - 1.0;
  x = target_point->x;
  y = target_point->y;
  z = target_point->z;
  v20 = 1.0 / v12;
  v21 = fHintT;
  v22 = 0;
  do
  {
    ++v22;
    UFG::HermiteCurve::GetPosition(this, v21, &vOutPosition);
    if ( (float)((float)((float)((float)(vOutPosition.y - y) * (float)(vOutPosition.y - y))
                       + (float)((float)(vOutPosition.x - x) * (float)(vOutPosition.x - x)))
               + (float)((float)(vOutPosition.z - z) * (float)(vOutPosition.z - z))) > v15 )
      break;
    v23 = v21;
    v13 = v21;
    v15 = (float)((float)((float)(vOutPosition.y - y) * (float)(vOutPosition.y - y))
                + (float)((float)(vOutPosition.x - x) * (float)(vOutPosition.x - x)))
        + (float)((float)(vOutPosition.z - z) * (float)(vOutPosition.z - z));
    v21 = v21 + v20;
    if ( v23 >= v16 )
      break;
    if ( v21 > v16 )
      v21 = v16;
  }
  while ( v22 < 0x1F4 );
  for ( ; v22 < 0x1F4; v13 = v9 )
  {
    v24 = v9;
    ++v22;
    v9 = v9 - v20;
    if ( v24 <= v14 )
      break;
    if ( v9 < v14 )
      v9 = v14;
    UFG::HermiteCurve::GetPosition(this, v9, &vOutPosition);
    if ( (float)((float)((float)((float)(vOutPosition.y - y) * (float)(vOutPosition.y - y))
                       + (float)((float)(vOutPosition.x - x) * (float)(vOutPosition.x - x)))
               + (float)((float)(vOutPosition.z - z) * (float)(vOutPosition.z - z))) > v15 )
      break;
    v15 = (float)((float)((float)(vOutPosition.y - y) * (float)(vOutPosition.y - y))
                + (float)((float)(vOutPosition.x - x) * (float)(vOutPosition.x - x)))
        + (float)((float)(vOutPosition.z - z) * (float)(vOutPosition.z - z));
  }
  UFG::HermiteCurve::GetPosition(this, v13, closest_point);
  if ( nOutIterations )
    *nOutIterations = v22;
  return v13;
}

// File Line: 741
// RVA: 0x168E10
float __fastcall UFG::HermiteCurve::ClosestPointEx(
        UFG::HermiteCurve *this,
        UFG::qVector3 *target_point,
        UFG::qVector3 *closest_point,
        float fStartT,
        float fEndT,
        float fSubdivisions,
        float fStopThreshold,
        float fHeightCoeff)
{
  UFG::qVector3 *v8; // rdi
  float v11; // xmm14_4
  float v12; // xmm13_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm11_4
  char v16; // r14
  float v17; // xmm9_4
  int v18; // r12d
  float v19; // xmm10_4
  int v20; // xmm3_4
  float v21; // xmm5_4
  int v22; // ebx
  __int64 v23; // rsi
  float v24; // xmm13_4
  float *v25; // rdi
  int v26; // xmm1_4
  float v27; // xmm11_4
  float v28; // xmm10_4
  float v29; // xmm9_4
  float v30; // xmm7_4
  float x; // xmm15_4
  float v32; // xmm6_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  int v35; // ecx
  float *v36; // rax
  float *v37; // rax
  __int64 v38; // rdx
  __int64 *v39; // r8
  __int64 v40; // r9
  int v41; // eax
  __int64 v42; // rdx
  float v43; // xmm0_4
  int v44; // r9d
  __int64 v45; // rdx
  float v46; // xmm4_4
  unsigned __int64 v47; // rcx
  unsigned int v48; // eax
  __int64 v49; // r8
  float v50; // xmm3_4
  float v51; // xmm0_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm1_4
  float v57; // xmm0_4
  float v58; // xmm2_4
  float v59; // xmm1_4
  float v60; // xmm0_4
  float v61; // xmm2_4
  float v62; // xmm1_4
  __int64 v63; // rdx
  __int64 v64; // rcx
  float v65; // xmm0_4
  float v66; // xmm2_4
  float v67; // xmm1_4
  float v68; // xmm6_4
  __int64 v70; // [rsp+20h] [rbp-E0h]
  unsigned __int64 v71; // [rsp+28h] [rbp-D8h] BYREF
  __int64 v72; // [rsp+30h] [rbp-D0h]
  __int64 v73; // [rsp+38h] [rbp-C8h]
  __int64 v74; // [rsp+40h] [rbp-C0h]
  __int64 v75; // [rsp+48h] [rbp-B8h]
  float v76; // [rsp+50h] [rbp-B0h]
  float v77; // [rsp+54h] [rbp-ACh]
  int v78[2]; // [rsp+58h] [rbp-A8h]
  __int64 v79; // [rsp+60h] [rbp-A0h] BYREF
  unsigned __int64 v80; // [rsp+68h] [rbp-98h]
  __int64 v81; // [rsp+70h] [rbp-90h]
  __int64 v82; // [rsp+78h] [rbp-88h]
  __int64 v83; // [rsp+80h] [rbp-80h] BYREF
  __int64 v84; // [rsp+88h] [rbp-78h]
  int v85[2]; // [rsp+90h] [rbp-70h]
  UFG::qVector3 v86; // [rsp+98h] [rbp-68h] BYREF
  int v87; // [rsp+A8h] [rbp-58h]
  UFG::qVector3 vOutPosition; // [rsp+B0h] [rbp-50h] BYREF
  char v89; // [rsp+1A0h] [rbp+A0h]
  float v91; // [rsp+1B8h] [rbp+B8h]

  v91 = fStartT;
  v8 = closest_point;
  v11 = fStartT;
  if ( fStartT == -1.234 )
  {
    v11 = 0.0;
    v91 = 0.0;
  }
  v12 = fEndT;
  v13 = *(float *)&FLOAT_1_0;
  if ( fEndT == -1.234 )
  {
    v12 = (float)this->mNumControlPoints - 1.0;
    fEndT = v12;
  }
  v14 = fSubdivisions;
  if ( fSubdivisions <= 0.0 )
  {
    v14 = FLOAT_15_0;
    fSubdivisions = FLOAT_15_0;
  }
  v15 = fStopThreshold;
  if ( fStopThreshold == -1.234 )
  {
    v15 = *(float *)&FLOAT_1_0;
    fStopThreshold = *(float *)&FLOAT_1_0;
  }
  v16 = 0;
  v89 = 0;
  UFG::HermiteCurve::GetPosition(this, v11, &vOutPosition);
  UFG::HermiteCurve::GetPosition(this, v12, &v86);
  if ( (float)((float)((float)((float)(vOutPosition.y - v86.y) * (float)(vOutPosition.y - v86.y))
                     + (float)((float)(vOutPosition.x - v86.x) * (float)(vOutPosition.x - v86.x)))
             + (float)((float)(vOutPosition.z - v86.z) * (float)(vOutPosition.z - v86.z))) > 9.0 )
  {
    if ( v11 <= 0.0 )
    {
      v11 = 0.0;
      v91 = 0.0;
    }
    if ( v12 >= (float)((float)this->mNumControlPoints - 1.0) )
    {
      v12 = (float)this->mNumControlPoints - 1.0;
      fEndT = v12;
    }
  }
  else
  {
    v16 = 1;
    v89 = 1;
  }
  v17 = FLOAT_1000000_0;
  v18 = 0;
  v19 = 0.0;
  v70 = 0x7F7FFFFFBF800000i64;
  v72 = 0x7F7FFFFFBF800000i64;
  *(float *)&v20 = 0.0;
  v21 = FLOAT_1000000_0;
  v74 = 0x7F7FFFFFBF800000i64;
  v22 = 1;
  *(float *)v85 = FLOAT_1000000_0;
  v78[0] = 0;
  v77 = FLOAT_1000000_0;
  v76 = 0.0;
  *(float *)&v73 = *((float *)&v73 + 1) - 1.0;
  *(float *)&v75 = *((float *)&v75 + 1) - 1.0;
  v71 = __PAIR64__(LODWORD(v12), LODWORD(v11));
  if ( (float)(v15 * 2.0) > v15 )
  {
    do
    {
      if ( v17 <= v15 || v18 >= 500 )
        break;
      v23 = v22;
      v79 = v70;
      v80 = v71;
      v81 = v72;
      v82 = v73;
      v83 = v74;
      v84 = v75;
      if ( v22 > 0 )
      {
        v24 = v77;
        v25 = (float *)&v71 + 1;
        *(float *)&v26 = v13 / (float)(fSubdivisions - v13);
        v87 = v26;
        do
        {
          v27 = *v25;
          v28 = *(v25 - 1);
          v29 = 0.0;
          v30 = (float)(*v25 - v28) * *(float *)&v26;
          if ( fSubdivisions > 0.0 )
          {
            x = target_point->x;
            do
            {
              ++v18;
              v32 = (float)(v29 * v30) + v28;
              UFG::HermiteCurve::GetPosition(this, v32, &v86);
              v33 = (float)(v86.z - target_point->z) * (float)(v86.z - target_point->z);
              v34 = (float)((float)((float)(v86.y - target_point->y) * (float)(v86.y - target_point->y))
                          + (float)((float)(v86.x - x) * (float)(v86.x - x)))
                  + v33;
              if ( fHeightCoeff != -1.234 )
                v34 = v34 + (float)(v33 * fHeightCoeff);
              if ( v34 >= v24 )
              {
                *(float *)&v20 = v76;
              }
              else
              {
                *(float *)&v20 = (float)(v29 * v30) + v28;
                v24 = v34;
                v76 = *(float *)&v20;
              }
              v35 = 0;
              if ( v22 <= 0 )
              {
LABEL_32:
                v22 = 0;
                v37 = (float *)&v79 + 1;
                v38 = 0i64;
                while ( v34 >= *v37 )
                {
                  ++v38;
                  v37 += 4;
                  if ( v38 >= 3 )
                    goto LABEL_40;
                }
                if ( v38 <= 1 )
                {
                  v39 = &v83;
                  v40 = 2 - v38;
                  do
                  {
                    v41 = *((_DWORD *)v39 - 4);
                    v39 -= 2;
                    *((_DWORD *)v39 + 4) = v41;
                    *((_DWORD *)v39 + 5) = *((_DWORD *)v39 + 1);
                    *((_DWORD *)v39 + 6) = *((_DWORD *)v39 + 2);
                    *((_DWORD *)v39 + 7) = *((_DWORD *)v39 + 3);
                    --v40;
                  }
                  while ( v40 );
                }
                v42 = 2 * v38;
                *((float *)&v79 + 2 * v42 + 1) = v34;
                *((float *)&v79 + 2 * v42) = v32;
                *((float *)&v80 + 2 * v42) = v28;
                *((float *)&v80 + 2 * v42 + 1) = v27;
LABEL_40:
                if ( *(float *)&v79 >= 0.0 )
                  v22 = 1;
                if ( *(float *)&v81 >= 0.0 )
                  ++v22;
                if ( *(float *)&v83 >= 0.0 )
                  ++v22;
              }
              else
              {
                v36 = (float *)&v79;
                while ( *v36 < 0.0 || COERCE_FLOAT(COERCE_UNSIGNED_INT(*v36 - v32) & _xmm) >= v30 )
                {
                  ++v35;
                  v36 += 4;
                  if ( v35 >= v22 )
                    goto LABEL_32;
                }
              }
              v29 = v29 + 1.0;
            }
            while ( v29 < fSubdivisions );
            v26 = v87;
            v77 = v24;
          }
          v25 += 4;
          --v23;
        }
        while ( v23 );
        v12 = fEndT;
        v11 = v91;
        v21 = v77;
        v16 = v89;
        v13 = *(float *)&FLOAT_1_0;
        v14 = fSubdivisions;
        v17 = *(float *)v85;
        v19 = *(float *)v78;
        v15 = fStopThreshold;
      }
      v43 = fsqrt(v21);
      if ( v43 >= v17 )
      {
        v46 = 0.0;
      }
      else
      {
        v19 = *(float *)&v20;
        v44 = 0;
        v45 = 0i64;
        v78[0] = v20;
        v46 = v17 - v43;
        v17 = v43;
        *(float *)v85 = v43;
        if ( v22 >= 4 )
        {
          v47 = 0i64;
          v48 = ((unsigned int)(v22 - 4) >> 2) + 1;
          v49 = v48;
          v44 = 4 * v48;
          v45 = 4i64 * v48;
          v50 = v13 / (float)(v14 - v13);
          do
          {
            *(_DWORD *)((char *)&v70 + v47) = *(_DWORD *)((char *)&v79 + v47);
            *(_DWORD *)((char *)&v70 + v47 + 4) = *(_DWORD *)((char *)&v79 + v47 + 4);
            *(_DWORD *)((char *)&v71 + v47) = *(_DWORD *)((char *)&v80 + v47);
            *(_DWORD *)((char *)&v71 + v47 + 4) = *(_DWORD *)((char *)&v80 + v47 + 4);
            v51 = (float)(*(float *)((char *)&v71 + v47 + 4) - *(float *)((char *)&v71 + v47)) * v50;
            v52 = *(float *)((char *)&v70 + v47) - v51;
            v53 = *(float *)((char *)&v70 + v47) + v51;
            *(float *)((char *)&v71 + v47) = v52;
            *(float *)((char *)&v71 + v47 + 4) = v53;
            if ( !v16 )
            {
              if ( v52 <= v11 )
                v52 = v11;
              *(float *)((char *)&v71 + v47) = v52;
              if ( v53 >= v12 )
                v53 = v12;
              *(float *)((char *)&v71 + v47 + 4) = v53;
            }
            *(_DWORD *)((char *)&v72 + v47) = *(_DWORD *)((char *)&v81 + v47);
            *(_DWORD *)((char *)&v72 + v47 + 4) = *(_DWORD *)((char *)&v81 + v47 + 4);
            *(_DWORD *)((char *)&v73 + v47) = *(_DWORD *)((char *)&v82 + v47);
            *(_DWORD *)((char *)&v73 + v47 + 4) = *(_DWORD *)((char *)&v82 + v47 + 4);
            v54 = (float)(*(float *)((char *)&v73 + v47 + 4) - *(float *)((char *)&v73 + v47)) * v50;
            v55 = *(float *)((char *)&v72 + v47) - v54;
            v56 = *(float *)((char *)&v72 + v47) + v54;
            *(float *)((char *)&v73 + v47) = v55;
            *(float *)((char *)&v73 + v47 + 4) = v56;
            if ( !v16 )
            {
              if ( v55 <= v11 )
                v55 = v11;
              *(float *)((char *)&v73 + v47) = v55;
              if ( v56 >= v12 )
                v56 = v12;
              *(float *)((char *)&v73 + v47 + 4) = v56;
            }
            *(_DWORD *)((char *)&v74 + v47) = *(_DWORD *)((char *)&v83 + v47);
            *(_DWORD *)((char *)&v74 + v47 + 4) = *(_DWORD *)((char *)&v83 + v47 + 4);
            *(_DWORD *)((char *)&v75 + v47) = v85[v47 / 4 - 2];
            *(_DWORD *)((char *)&v75 + v47 + 4) = v85[v47 / 4 - 1];
            v57 = (float)(*(float *)((char *)&v75 + v47 + 4) - *(float *)((char *)&v75 + v47)) * v50;
            v58 = *(float *)((char *)&v74 + v47) - v57;
            v59 = *(float *)((char *)&v74 + v47) + v57;
            *(float *)((char *)&v75 + v47) = v58;
            *(float *)((char *)&v75 + v47 + 4) = v59;
            if ( !v16 )
            {
              if ( v58 <= v11 )
                v58 = v11;
              *(float *)((char *)&v75 + v47) = v58;
              if ( v59 >= v12 )
                v59 = v12;
              *(float *)((char *)&v75 + v47 + 4) = v59;
            }
            *(_DWORD *)((char *)&v76 + v47) = v85[v47 / 4];
            v78[v47 / 4 - 1] = v85[v47 / 4 + 1];
            v78[v47 / 4] = *(_DWORD *)((char *)&v86.x + v47);
            v78[v47 / 4 + 1] = *(_DWORD *)((char *)&v86.y + v47);
            v60 = (float)(*(float *)&v78[v47 / 4 + 1] - *(float *)&v78[v47 / 4]) * v50;
            v61 = *(float *)((char *)&v76 + v47) - v60;
            v62 = *(float *)((char *)&v76 + v47) + v60;
            *(float *)&v78[v47 / 4] = v61;
            *(float *)&v78[v47 / 4 + 1] = v62;
            if ( !v16 )
            {
              if ( v61 <= v11 )
                v61 = v11;
              *(float *)&v78[v47 / 4] = v61;
              if ( v62 >= v12 )
                v62 = v12;
              *(float *)&v78[v47 / 4 + 1] = v62;
            }
            v47 += 64i64;
            --v49;
          }
          while ( v49 );
        }
        if ( v44 < v22 )
        {
          v63 = 16 * v45;
          v64 = (unsigned int)(v22 - v44);
          do
          {
            *(_DWORD *)((char *)&v70 + v63) = *(_DWORD *)((char *)&v79 + v63);
            *(_DWORD *)((char *)&v70 + v63 + 4) = *(_DWORD *)((char *)&v79 + v63 + 4);
            *(_DWORD *)((char *)&v71 + v63) = *(_DWORD *)((char *)&v80 + v63);
            *(_DWORD *)((char *)&v71 + v63 + 4) = *(_DWORD *)((char *)&v80 + v63 + 4);
            v65 = (float)(*(float *)((char *)&v71 + v63 + 4) - *(float *)((char *)&v71 + v63))
                * (float)(v13 / (float)(v14 - v13));
            v66 = *(float *)((char *)&v70 + v63) - v65;
            v67 = *(float *)((char *)&v70 + v63) + v65;
            *(float *)((char *)&v71 + v63) = v66;
            *(float *)((char *)&v71 + v63 + 4) = v67;
            if ( !v16 )
            {
              if ( v66 <= v11 )
                v66 = v11;
              *(float *)((char *)&v71 + v63) = v66;
              if ( v67 >= v12 )
                v67 = v12;
              *(float *)((char *)&v71 + v63 + 4) = v67;
            }
            v63 += 16i64;
            --v64;
          }
          while ( v64 );
        }
      }
      *(float *)&v20 = v76;
    }
    while ( v46 > v15 );
    v8 = closest_point;
  }
  v68 = (float)this->mNumControlPoints - v13;
  if ( v19 >= 0.0 )
  {
    if ( v19 > v68 )
      v19 = fmodf(v19, v68);
  }
  else
  {
    v19 = fmodf(v19, v68) + v68;
  }
  UFG::HermiteCurve::GetPosition(this, v19, v8);
  return v19;
}

// File Line: 953
// RVA: 0x16D4A0
float __fastcall UFG::HermiteCurve::EstimateLength(UFG::HermiteCurve *this, int nSamplePoints)
{
  int v3; // r11d
  float v4; // xmm8_4
  int v5; // r10d
  __int64 v6; // r9
  UFG::HermiteControlPoint *v7; // rax
  unsigned __int64 v8; // rcx
  float x; // xmm4_4
  __m128 y_low; // xmm6
  __m128 v11; // xmm2
  float z; // xmm3_4
  float v13; // xmm0_4
  __m128 v14; // xmm7
  float v15; // xmm5_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  __m128 v18; // xmm4
  float v19; // xmm0_4
  float v20; // xmm3_4
  __int64 v21; // rdx
  UFG::HermiteControlPoint *v22; // r8
  float *p_z; // rax
  __m128 v24; // xmm2
  float v25; // xmm0_4
  float v26; // xmm1_4

  v3 = this->mNumControlPoints - 1;
  v4 = 0.0;
  v5 = v3;
  if ( nSamplePoints < v3 )
    v5 = nSamplePoints;
  if ( v5 > 0 )
  {
    v6 = 0i64;
    if ( v5 >= 4i64 )
    {
      v7 = this->mControlPoints + 1;
      v8 = ((unsigned __int64)(v5 - 4i64) >> 2) + 1;
      v6 = 4 * v8;
      do
      {
        x = v7->mPosition.x;
        y_low = (__m128)LODWORD(v7->mPosition.y);
        v11 = (__m128)LODWORD(v7[-1].mPosition.y);
        z = v7->mPosition.z;
        v13 = v7[-1].mPosition.z;
        v14 = (__m128)LODWORD(v7[1].mPosition.y);
        v15 = v7[1].mPosition.x;
        v16 = v7[-1].mPosition.x - v7->mPosition.x;
        v7 += 4;
        v11.m128_f32[0] = (float)((float)(v11.m128_f32[0] - y_low.m128_f32[0])
                                * (float)(v11.m128_f32[0] - y_low.m128_f32[0]))
                        + (float)(v16 * v16);
        v17 = v7[-2].mPosition.z;
        v11.m128_f32[0] = v11.m128_f32[0] + (float)((float)(v13 - z) * (float)(v13 - z));
        y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - v14.m128_f32[0])
                                  * (float)(y_low.m128_f32[0] - v14.m128_f32[0]))
                          + (float)((float)(x - v15) * (float)(x - v15));
        v18 = (__m128)LODWORD(v7[-2].mPosition.y);
        v19 = _mm_sqrt_ps(v11).m128_f32[0];
        v11.m128_i32[0] = LODWORD(v7[-3].mPosition.z);
        y_low.m128_f32[0] = y_low.m128_f32[0] + (float)((float)(z - v11.m128_f32[0]) * (float)(z - v11.m128_f32[0]));
        v20 = v7[-2].mPosition.x;
        v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] - v18.m128_f32[0])
                                        * (float)(v14.m128_f32[0] - v18.m128_f32[0]))
                                + (float)((float)(v15 - v20) * (float)(v15 - v20)))
                        + (float)((float)(v11.m128_f32[0] - v17) * (float)(v11.m128_f32[0] - v17));
        v18.m128_f32[0] = (float)((float)((float)(v18.m128_f32[0] - v7[-1].mPosition.y)
                                        * (float)(v18.m128_f32[0] - v7[-1].mPosition.y))
                                + (float)((float)(v20 - v7[-1].mPosition.x) * (float)(v20 - v7[-1].mPosition.x)))
                        + (float)((float)(v17 - v7[-1].mPosition.z) * (float)(v17 - v7[-1].mPosition.z));
        v4 = (float)((float)((float)(v4 + v19) + _mm_sqrt_ps(y_low).m128_f32[0]) + _mm_sqrt_ps(v14).m128_f32[0])
           + _mm_sqrt_ps(v18).m128_f32[0];
        --v8;
      }
      while ( v8 );
    }
    if ( v6 < v5 )
    {
      v21 = v5 - v6;
      v22 = &this->mControlPoints[v6];
      p_z = &v22[1].mPosition.z;
      do
      {
        v24 = (__m128)*((unsigned int *)p_z - 7);
        v25 = *(p_z - 6);
        v26 = v22->mPosition.x;
        ++v22;
        p_z += 6;
        v24.m128_f32[0] = (float)((float)((float)(v24.m128_f32[0] - *(p_z - 7)) * (float)(v24.m128_f32[0] - *(p_z - 7)))
                                + (float)((float)(v26 - *(p_z - 8)) * (float)(v26 - *(p_z - 8))))
                        + (float)((float)(v25 - *(p_z - 6)) * (float)(v25 - *(p_z - 6)));
        v4 = v4 + _mm_sqrt_ps(v24).m128_f32[0];
        --v21;
      }
      while ( v21 );
    }
    return (float)(v4 / (float)v5) * (float)v3;
  }
  return v4;
}

// File Line: 999
// RVA: 0x16F6F0
float __fastcall UFG::HermiteCurveWalker::GetClosestPoint(
        UFG::HermiteCurveWalker *this,
        UFG::qVector3 *outPos,
        UFG::qVector3 *outTangent,
        UFG::qVector3 *vCurrentPos,
        float fOffsetDist,
        float fStartT,
        float fEndT,
        int localPrecision,
        float fHeightCoeff)
{
  UFG::HermiteCurve *mpCurve; // rdi
  float v15; // xmm0_4
  float v16; // xmm9_4
  float v17; // xmm8_4
  char v18; // bp
  float v19; // xmm1_4
  int v20; // r9d
  float mNumControlPoints; // xmm1_4
  UFG::HermiteControlPoint *mControlPoints; // r8
  float v23; // xmm2_4
  float v24; // xmm0_4
  float mfLastT; // xmm5_4
  float v26; // xmm0_4
  float v27; // xmm4_4
  float precision; // xmm0_4
  float LocalClosestPoint; // xmm0_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  float v32; // xmm6_4
  float v33; // xmm0_4
  float y; // xmm0_4
  float z; // xmm1_4

  mpCurve = this->mpCurve;
  if ( !this->mpCurve )
    return 0.0;
  if ( this->mfCurveLength <= 0.0 )
  {
    v15 = UFG::HermiteCurve::EstimateLength(mpCurve, mpCurve->mNumControlPoints);
    this->mfCurveLength = v15;
    if ( v15 == 0.0 )
      return 0.0;
  }
  v16 = fStartT;
  if ( fStartT == -1.234 )
    v16 = 0.0;
  v17 = fEndT;
  if ( fEndT == -1.234 )
    v17 = (float)mpCurve->mNumControlPoints - 1.0;
  if ( v17 == v16 )
  {
    v18 = 1;
  }
  else
  {
    v19 = (float)(int)(float)(v16 + 0.5);
    if ( v19 < 0.0 )
      v19 = 0.0;
    v20 = (int)v19;
    mNumControlPoints = (float)mpCurve->mNumControlPoints;
    if ( mNumControlPoints >= (float)(int)(float)(v17 + 0.5) )
      mNumControlPoints = (float)(int)(float)(v17 + 0.5);
    mControlPoints = mpCurve->mControlPoints;
    v18 = 0;
    v23 = mControlPoints[v20].mPosition.y - mControlPoints[mNumControlPoints].mPosition.y;
    v24 = mControlPoints[v20].mPosition.z - mControlPoints[mNumControlPoints].mPosition.z;
    if ( (float)((float)((float)(v23 * v23)
                       + (float)((float)(mControlPoints[v20].mPosition.x - mControlPoints[mNumControlPoints].mPosition.x)
                               * (float)(mControlPoints[v20].mPosition.x - mControlPoints[mNumControlPoints].mPosition.x)))
               + (float)(v24 * v24)) < 9.0 )
      v18 = 1;
  }
  mfLastT = this->mfLastT;
  if ( mfLastT < 0.0
    || (v26 = vCurrentPos->y - this->mvLastPos.y,
        v27 = vCurrentPos->z - this->mvLastPos.z,
        (float)((float)((float)(v26 * v26)
                      + (float)((float)(vCurrentPos->x - this->mvLastPos.x) * (float)(vCurrentPos->x - this->mvLastPos.x)))
              + (float)(v27 * v27)) > (float)((float)(COERCE_FLOAT(LODWORD(fOffsetDist) & _xmm)
                                                    + this->mfGlobalSearchDist)
                                            * (float)(COERCE_FLOAT(LODWORD(fOffsetDist) & _xmm)
                                                    + this->mfGlobalSearchDist))) )
  {
    if ( v18 )
      LocalClosestPoint = UFG::HermiteCurve::ClosestPointEx(
                            mpCurve,
                            vCurrentPos,
                            outPos,
                            -1.234,
                            -1.234,
                            -1.0,
                            -1.234,
                            fHeightCoeff);
    else
      LocalClosestPoint = UFG::HermiteCurve::ClosestPointEx(
                            mpCurve,
                            vCurrentPos,
                            outPos,
                            v16,
                            v17,
                            -1.0,
                            -1.234,
                            fHeightCoeff);
  }
  else
  {
    precision = (float)localPrecision;
    if ( v18 )
      LocalClosestPoint = UFG::HermiteCurve::GetLocalClosestPoint(
                            mpCurve,
                            vCurrentPos,
                            outPos,
                            mfLastT,
                            precision,
                            -1.234,
                            0i64);
    else
      LocalClosestPoint = UFG::HermiteCurve::GetLocalClosestPoint(
                            mpCurve,
                            vCurrentPos,
                            outPos,
                            mfLastT,
                            v16,
                            v17,
                            precision,
                            0i64);
  }
  v30 = LocalClosestPoint;
  v31 = 0.0;
  if ( COERCE_FLOAT(LODWORD(fOffsetDist) & _xmm) > 0.0 )
    v31 = (float)(this->mpCurve->mNumControlPoints - 1) * (float)(fOffsetDist / this->mfCurveLength);
  v32 = v30 + v31;
  v33 = (float)(this->mpCurve->mNumControlPoints - 1);
  if ( v18 )
  {
    if ( v32 >= 0.0 )
    {
      if ( v32 > v33 )
        v32 = v32 - v33;
    }
    else
    {
      v32 = v32 + v33;
    }
  }
  else
  {
    if ( v32 <= v16 )
      v32 = v16;
    if ( v32 >= v17 )
      v32 = v17;
  }
  UFG::HermiteCurve::GetPosition(this->mpCurve, v32, outPos);
  UFG::HermiteCurve::GetTangent(this->mpCurve, v32, outTangent);
  this->mfLastT = v32;
  y = outPos->y;
  z = outPos->z;
  this->mvLastPos.x = outPos->x;
  this->mvLastPos.y = y;
  this->mvLastPos.z = z;
  return v32;
}

