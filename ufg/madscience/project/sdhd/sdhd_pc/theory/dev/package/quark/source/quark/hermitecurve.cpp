// File Line: 36
// RVA: 0x160200
void __fastcall UFG::HermiteCurve::HermiteCurve(UFG::HermiteCurve *this, int maxNumControlPoints, UFG::qMemoryPool *pMemPool, char *allocCustomName)
{
  char *v4; // rdi
  UFG::qMemoryPool *v5; // r10
  UFG::HermiteCurve *v6; // rbx
  char *v7; // r8
  char *v8; // rax
  unsigned __int64 v9; // rsi
  UFG::qMemoryPool *v10; // rcx
  const char *v11; // r8

  v4 = allocCustomName;
  v5 = pMemPool;
  v6 = this;
  this->mNumControlPoints = 0;
  this->mMaxNumControlPoints = maxNumControlPoints;
  this->mpMemoryPool = pMemPool;
  if ( pMemPool )
  {
    v7 = "HermiteCurve.mControlPoints";
    if ( allocCustomName )
      v7 = allocCustomName;
    v8 = UFG::qMemoryPool::Allocate(v5, 24i64 * maxNumControlPoints, v7, 0x1000ui64, 1u);
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
    if ( v4 )
      v11 = v4;
    v8 = UFG::qMemoryPool::Allocate(v10, v9, v11, 0x1000ui64, 1u);
  }
  v6->mControlPoints = (UFG::HermiteControlPoint *)v8;
}

// File Line: 53
// RVA: 0x162E20
void __fastcall UFG::HermiteCurve::~HermiteCurve(UFG::HermiteCurve *this)
{
  UFG::qMemoryPool *v1; // rax
  UFG::HermiteControlPoint *v2; // rdx

  v1 = this->mpMemoryPool;
  v2 = this->mControlPoints;
  if ( v1 )
  {
    UFG::qMemoryPool::Free(v1, v2);
  }
  else if ( v2 )
  {
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v2);
  }
}

// File Line: 102
// RVA: 0x1716D0
int UFG::HermiteCurve::GetPosition(...)
{
  UFG::qVector3 *v3; // rbx
  __m128 v4; // xmm4
  UFG::HermiteCurve *v5; // rdi
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  __m128 v9; // xmm0
  __m128 v10; // xmm0
  float v11; // xmm1_4
  signed int v12; // ecx
  float v13; // xmm4_4
  signed int v14; // eax
  int v15; // edx
  signed __int64 v16; // rcx
  UFG::HermiteControlPoint *v17; // rax
  float v18; // xmm0_4
  float v19; // xmm1_4
  UFG::HermiteControlPoint *v20; // rax
  float v21; // xmm0_4
  float v22; // xmm1_4
  UFG::HermiteControlPoint *v23; // r8
  signed __int64 v24; // rdx
  float v25; // xmm11_4
  float v26; // xmm6_4
  float v27; // xmm3_4
  float v28; // xmm6_4
  float v29; // xmm12_4
  float v30; // xmm11_4
  float v31; // xmm12_4
  float v32; // xmm3_4
  float v33; // xmm14_4
  float v34; // xmm15_4

  v3 = vOutPosition;
  v4 = (__m128)t;
  v5 = this;
  if ( this->mNumControlPoints >= 2 )
  {
    v8 = (float)this->mNumControlPoints - 1.0;
    if ( *(float *)&t >= 0.0 )
    {
      if ( *(float *)&t > v8 )
      {
        v10 = (__m128)t;
        v10.m128_f32[0] = fmodf(*(float *)&t, v8);
        v4 = v10;
      }
    }
    else
    {
      v9 = (__m128)t;
      v9.m128_f32[0] = fmodf(*(float *)&t, v8);
      v4 = v9;
      v4.m128_f32[0] = v9.m128_f32[0] + v8;
    }
    v11 = v4.m128_f32[0];
    v12 = (signed int)v4.m128_f32[0];
    if ( (signed int)v4.m128_f32[0] != 0x80000000 && (float)v12 != v4.m128_f32[0] )
      v11 = (float)(v12 - (_mm_movemask_ps(_mm_unpacklo_ps(v4, v4)) & 1));
    v13 = v4.m128_f32[0] - v11;
    v14 = (signed int)v11;
    v15 = (signed int)v11 + 1;
    if ( v13 >= 0.001 )
    {
      if ( v13 <= UFG::HermiteCurve::kOneMinusEpsilon )
      {
        v23 = v5->mControlPoints;
        v24 = v15;
        v25 = (float)(v13 * v13) * 3.0;
        v26 = (float)(v13 * v13) * v13;
        v27 = v26;
        v28 = v26 - (float)(v13 * v13);
        v29 = (float)((float)((float)(v13 * v13) * v13) * 2.0) - v25;
        v30 = v25 - (float)((float)((float)(v13 * v13) * v13) * 2.0);
        v31 = v29 + 1.0;
        v32 = (float)(v27 - (float)((float)(v13 * v13) * 2.0)) + v13;
        v33 = (float)((float)((float)(v23[v14].mPosition.y * v31) + (float)(v23[v24].mPosition.y * v30))
                    + (float)(v23[v14].mTangent.y * v32))
            + (float)(v23[v24].mTangent.y * v28);
        v34 = (float)((float)((float)(v23[v14].mPosition.z * v31) + (float)(v23[v24].mPosition.z * v30))
                    + (float)(v23[v14].mTangent.z * v32))
            + (float)(v23[v24].mTangent.z * v28);
        v3->x = (float)((float)((float)(v23[v14].mPosition.x * v31) + (float)(v23[v24].mPosition.x * v30))
                      + (float)(v23[v14].mTangent.x * v32))
              + (float)(v23[v24].mTangent.x * v28);
        v3->y = v33;
        v3->z = v34;
      }
      else
      {
        v20 = v5->mControlPoints;
        v21 = v20[v15].mPosition.y;
        v22 = v20[v15].mPosition.z;
        v3->x = v20[v15].mPosition.x;
        v3->y = v21;
        v3->z = v22;
      }
    }
    else
    {
      v16 = v14;
      v17 = v5->mControlPoints;
      v18 = v17[v16].mPosition.y;
      v19 = v17[v16].mPosition.z;
      v3->x = v17[v16].mPosition.x;
      v3->y = v18;
      v3->z = v19;
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
  int v3; // edi
  UFG::qVector3 *v4; // rbx
  float v5; // xmm2_4
  UFG::HermiteCurve *v6; // rsi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  UFG::HermiteControlPoint *v11; // rax
  float v12; // xmm0_4
  float v13; // xmm1_4
  signed int v14; // ecx
  UFG::HermiteControlPoint *v15; // r8
  __m128i v16; // xmm0
  signed __int64 v17; // rdx
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

  v3 = this->mNumControlPoints;
  v4 = vOutTangent;
  v5 = t;
  v6 = this;
  if ( this->mNumControlPoints >= 2 )
  {
    v9 = (float)v3 - 1.0;
    if ( t >= 0.0 )
    {
      if ( t > v9 )
        v5 = fmodf(t, v9);
    }
    else
    {
      v5 = fmodf(t, v9) + v9;
    }
    v10 = v5 - (float)(signed int)(float)(v5 + 0.5);
    if ( v10 < 0.0 )
      LODWORD(v10) ^= _xmm[0];
    if ( v10 >= 0.001 )
    {
      v14 = (signed int)v5;
      if ( (signed int)v5 == v3 - 1 )
        v14 = v3 - 2;
      v15 = v6->mControlPoints;
      v16 = _mm_cvtsi32_si128(v14);
      v17 = v14;
      v18 = v14 + 1;
      v19 = v5 - COERCE_FLOAT(_mm_cvtepi32_ps(v16));
      v20 = v19 * v19;
      v29 = v19;
      v21 = v19 * 6.0;
      v22 = v20 * 6.0;
      v23 = v20 * 3.0;
      v24 = v22 - v21;
      v25 = v21 - v22;
      v26 = (float)(v23 - (float)(v29 * 4.0)) + 1.0;
      v27 = v23 - (float)(v29 * 2.0);
      v28 = (float)((float)((float)(v15[v17].mPosition.y * v24) + (float)(v15[v18].mPosition.y * v25))
                  + (float)(v15[v17].mTangent.y * v26))
          + (float)(v15[v18].mTangent.y * v27);
      *(float *)v16.m128i_i32 = (float)((float)((float)(v15[v17].mPosition.z * v24) + (float)(v15[v18].mPosition.z * v25))
                                      + (float)(v15[v17].mTangent.z * v26))
                              + (float)(v15[v18].mTangent.z * v27);
      v4->x = (float)((float)((float)(v15[v17].mPosition.x * v24) + (float)(v15[v18].mPosition.x * v25))
                    + (float)(v15[v17].mTangent.x * v26))
            + (float)(v15[v18].mTangent.x * v27);
      v4->y = v28;
      LODWORD(v4->z) = v16.m128i_i32[0];
    }
    else
    {
      v11 = v6->mControlPoints;
      v12 = v11[(float)(v5 + 0.5)].mTangent.y;
      v13 = v11[(float)(v5 + 0.5)].mTangent.z;
      v4->x = v11[(float)(v5 + 0.5)].mTangent.x;
      v4->y = v12;
      v4->z = v13;
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
void __fastcall UFG::HermiteCurve::AddControlPoint(UFG::HermiteCurve *this, UFG::qVector3 *position, UFG::qVector3 *tangent)
{
  signed __int64 v3; // rax
  UFG::HermiteCurve *v4; // r11
  float v5; // xmm0_4
  float v6; // xmm1_4
  UFG::HermiteControlPoint *v7; // r9
  signed __int64 v8; // r10
  signed __int64 v9; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4
  UFG::HermiteControlPoint *v12; // rcx
  signed __int64 v13; // rdx

  v3 = this->mNumControlPoints;
  v4 = this;
  if ( (_DWORD)v3 != this->mMaxNumControlPoints )
  {
    v5 = position->y;
    v6 = position->z;
    v7 = this->mControlPoints;
    v8 = v3;
    v7[v8].mPosition.x = position->x;
    v7[v8].mPosition.y = v5;
    v7[v8].mPosition.z = v6;
    v9 = this->mNumControlPoints;
    v10 = tangent->y;
    v11 = tangent->z;
    v12 = this->mControlPoints;
    v13 = v9;
    v12[v13].mTangent.x = tangent->x;
    v12[v13].mTangent.y = v10;
    v12[v13].mTangent.z = v11;
    ++v4->mNumControlPoints;
  }
}

// File Line: 404
// RVA: 0x17CC70
void __fastcall UFG::HermiteCurve::SetControlPointTangent(UFG::HermiteCurve *this, int i, UFG::qVector3 *tangent)
{
  UFG::HermiteControlPoint *v3; // rcx
  float v4; // xmm0_4
  float v5; // xmm1_4
  signed __int64 v6; // rdx

  if ( i >= 0 && i < this->mNumControlPoints )
  {
    v3 = this->mControlPoints;
    v4 = tangent->y;
    v5 = tangent->z;
    v6 = i;
    v3[v6].mTangent.x = tangent->x;
    v3[v6].mTangent.y = v4;
    v3[v6].mTangent.z = v5;
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
float __fastcall UFG::HermiteCurve::GetLocalClosestPoint(UFG::HermiteCurve *this, UFG::qVector3 *target_point, UFG::qVector3 *closest_point, float fHintT, float precision, float fSpanT, unsigned int *nOutIterations)
{
  int v7; // edi
  UFG::qVector3 *v8; // rbp
  UFG::qVector3 *v9; // rsi
  UFG::HermiteCurve *v10; // r14
  float v12; // xmm0_4
  float v13; // xmm8_4
  float v14; // xmm10_4
  float v15; // xmm9_4
  float v16; // xmm14_4
  float v17; // xmm15_4
  float v18; // xmm6_4
  unsigned int v19; // ebx
  float v20; // xmm6_4
  UFG::qVector3 vOutPosition; // [rsp+20h] [rbp-B8h]

  v7 = this->mNumControlPoints;
  v8 = closest_point;
  v9 = target_point;
  v10 = this;
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
  v16 = target_point->x;
  v17 = target_point->y;
  v18 = fHintT;
  v19 = 0;
  do
  {
    ++v19;
    UFG::HermiteCurve::GetPosition(v10, v18, &vOutPosition);
    if ( (float)((float)((float)((float)(vOutPosition.y - v17) * (float)(vOutPosition.y - v17))
                       + (float)((float)(vOutPosition.x - v16) * (float)(vOutPosition.x - v16)))
               + (float)((float)(vOutPosition.z - v9->z) * (float)(vOutPosition.z - v9->z))) > v15 )
      break;
    v13 = v18;
    v18 = v18 + v14;
    v15 = (float)((float)((float)(vOutPosition.y - v17) * (float)(vOutPosition.y - v17))
                + (float)((float)(vOutPosition.x - v16) * (float)(vOutPosition.x - v16)))
        + (float)((float)(vOutPosition.z - v9->z) * (float)(vOutPosition.z - v9->z));
    if ( fSpanT != -1.234 && v18 >= (float)(fHintT + fSpanT) )
      break;
  }
  while ( v18 <= (float)((float)v7 * 2.0) && v19 < 0x1F4 );
  v20 = fHintT;
  if ( v19 < 0x1F4 )
  {
    do
    {
      v20 = v20 - v14;
      ++v19;
      UFG::HermiteCurve::GetPosition(v10, v20, &vOutPosition);
      if ( (float)((float)((float)((float)(vOutPosition.y - v17) * (float)(vOutPosition.y - v17))
                         + (float)((float)(vOutPosition.x - v16) * (float)(vOutPosition.x - v16)))
                 + (float)((float)(vOutPosition.z - v9->z) * (float)(vOutPosition.z - v9->z))) > v15 )
        break;
      v15 = (float)((float)((float)(vOutPosition.y - v17) * (float)(vOutPosition.y - v17))
                  + (float)((float)(vOutPosition.x - v16) * (float)(vOutPosition.x - v16)))
          + (float)((float)(vOutPosition.z - v9->z) * (float)(vOutPosition.z - v9->z));
      v13 = v20;
      if ( fSpanT != -1.234 && v20 <= (float)(fHintT - fSpanT) )
        break;
    }
    while ( v20 >= (float)((float)v7 * -2.0) && v19 < 0x1F4 );
  }
  UFG::HermiteCurve::GetPosition(v10, v13, v8);
  if ( nOutIterations )
    *nOutIterations = v19;
  return v13;
}

// File Line: 599
// RVA: 0x170C30
float __fastcall UFG::HermiteCurve::GetLocalClosestPoint(UFG::HermiteCurve *this, UFG::qVector3 *target_point, UFG::qVector3 *closest_point, float fHintT, float fStartT, float fEndT, float precision, unsigned int *nOutIterations)
{
  UFG::qVector3 *v8; // rsi
  float v9; // xmm6_4
  UFG::HermiteCurve *v10; // rdi
  float v12; // xmm0_4
  float v13; // xmm10_4
  float v14; // xmm9_4
  float v15; // xmm11_4
  float v16; // xmm8_4
  float v17; // xmm13_4
  float v18; // xmm14_4
  float v19; // xmm15_4
  float v20; // xmm12_4
  float v21; // xmm7_4
  unsigned int v22; // ebx
  float v23; // xmm0_4
  float v24; // xmm0_4
  UFG::qVector3 vOutPosition; // [rsp+20h] [rbp-B8h]

  v8 = closest_point;
  v9 = fHintT;
  v10 = this;
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
  v17 = target_point->x;
  v18 = target_point->y;
  v19 = target_point->z;
  v20 = 1.0 / v12;
  v21 = fHintT;
  v22 = 0;
  do
  {
    ++v22;
    UFG::HermiteCurve::GetPosition(v10, v21, &vOutPosition);
    if ( (float)((float)((float)((float)(vOutPosition.y - v18) * (float)(vOutPosition.y - v18))
                       + (float)((float)(vOutPosition.x - v17) * (float)(vOutPosition.x - v17)))
               + (float)((float)(vOutPosition.z - v19) * (float)(vOutPosition.z - v19))) > v15 )
      break;
    v23 = v21;
    v13 = v21;
    v15 = (float)((float)((float)(vOutPosition.y - v18) * (float)(vOutPosition.y - v18))
                + (float)((float)(vOutPosition.x - v17) * (float)(vOutPosition.x - v17)))
        + (float)((float)(vOutPosition.z - v19) * (float)(vOutPosition.z - v19));
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
    UFG::HermiteCurve::GetPosition(v10, v9, &vOutPosition);
    if ( (float)((float)((float)((float)(vOutPosition.y - v18) * (float)(vOutPosition.y - v18))
                       + (float)((float)(vOutPosition.x - v17) * (float)(vOutPosition.x - v17)))
               + (float)((float)(vOutPosition.z - v19) * (float)(vOutPosition.z - v19))) > v15 )
      break;
    v15 = (float)((float)((float)(vOutPosition.y - v18) * (float)(vOutPosition.y - v18))
                + (float)((float)(vOutPosition.x - v17) * (float)(vOutPosition.x - v17)))
        + (float)((float)(vOutPosition.z - v19) * (float)(vOutPosition.z - v19));
  }
  UFG::HermiteCurve::GetPosition(v10, v13, v8);
  if ( nOutIterations )
    *nOutIterations = v22;
  return v13;
}

// File Line: 741
// RVA: 0x168E10
float __fastcall UFG::HermiteCurve::ClosestPointEx(UFG::HermiteCurve *this, UFG::qVector3 *target_point, UFG::qVector3 *closest_point, float fStartT, float fEndT, float fSubdivisions, float fStopThreshold, float fHeightCoeff)
{
  UFG::qVector3 *v8; // rdi
  UFG::HermiteCurve *v9; // r13
  UFG::qVector3 *v10; // r15
  float v11; // xmm14_4
  float v12; // xmm13_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm11_4
  char v16; // r14
  float v17; // xmm9_4
  signed int v18; // er12
  float v19; // xmm10_4
  float v20; // xmm3_4
  float v21; // xmm5_4
  signed int v22; // ebx
  __int64 v23; // rsi
  float v24; // xmm13_4
  float *v25; // rdi
  float v26; // xmm1_4
  float v27; // xmm11_4
  float v28; // xmm10_4
  float v29; // xmm9_4
  float v30; // xmm7_4
  float v31; // xmm15_4
  float v32; // xmm6_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  signed int v35; // ecx
  float *v36; // rax
  float *v37; // rax
  signed __int64 v38; // rdx
  __int64 *v39; // r8
  signed __int64 v40; // r9
  int v41; // eax
  signed __int64 v42; // rdx
  float v43; // xmm0_4
  int v44; // er9
  signed __int64 v45; // rdx
  float v46; // xmm4_4
  __int64 v47; // rcx
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
  signed __int64 v63; // rdx
  __int64 v64; // rcx
  float v65; // xmm0_4
  float v66; // xmm2_4
  float v67; // xmm1_4
  float v68; // xmm6_4
  __int64 v70; // [rsp+20h] [rbp-E0h]
  unsigned __int64 v71; // [rsp+28h] [rbp-D8h]
  __int64 v72; // [rsp+30h] [rbp-D0h]
  __int64 v73; // [rsp+38h] [rbp-C8h]
  __int64 v74; // [rsp+40h] [rbp-C0h]
  __int64 v75; // [rsp+48h] [rbp-B8h]
  float v76; // [rsp+50h] [rbp-B0h]
  float v77; // [rsp+54h] [rbp-ACh]
  float v78; // [rsp+58h] [rbp-A8h]
  int v79; // [rsp+5Ch] [rbp-A4h]
  __int64 v80; // [rsp+60h] [rbp-A0h]
  unsigned __int64 v81; // [rsp+68h] [rbp-98h]
  __int64 v82; // [rsp+70h] [rbp-90h]
  __int64 v83; // [rsp+78h] [rbp-88h]
  __int64 v84; // [rsp+80h] [rbp-80h]
  __int64 v85; // [rsp+88h] [rbp-78h]
  float v86; // [rsp+90h] [rbp-70h]
  int v87; // [rsp+94h] [rbp-6Ch]
  UFG::qVector3 v88; // [rsp+98h] [rbp-68h]
  float v89; // [rsp+A8h] [rbp-58h]
  UFG::qVector3 vOutPosition; // [rsp+B0h] [rbp-50h]
  char v91; // [rsp+1A0h] [rbp+A0h]
  UFG::qVector3 *v92; // [rsp+1B0h] [rbp+B0h]
  float v93; // [rsp+1B8h] [rbp+B8h]

  v93 = fStartT;
  v92 = closest_point;
  v8 = closest_point;
  v9 = this;
  v10 = target_point;
  v11 = fStartT;
  if ( fStartT == -1.234 )
  {
    v11 = 0.0;
    v93 = 0.0;
  }
  v12 = fEndT;
  v13 = *(float *)&FLOAT_1_0;
  if ( fEndT == -1.234 )
  {
    v12 = (float)this->mNumControlPoints - 1.0;
    fEndT = (float)this->mNumControlPoints - 1.0;
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
  v91 = 0;
  UFG::HermiteCurve::GetPosition(this, v11, &vOutPosition);
  UFG::HermiteCurve::GetPosition(v9, v12, &v88);
  if ( (float)((float)((float)((float)(vOutPosition.y - v88.y) * (float)(vOutPosition.y - v88.y))
                     + (float)((float)(vOutPosition.x - v88.x) * (float)(vOutPosition.x - v88.x)))
             + (float)((float)(vOutPosition.z - v88.z) * (float)(vOutPosition.z - v88.z))) > 9.0 )
  {
    if ( v11 <= 0.0 )
    {
      v11 = 0.0;
      v93 = 0.0;
    }
    if ( v12 >= (float)((float)v9->mNumControlPoints - 1.0) )
    {
      v12 = (float)v9->mNumControlPoints - 1.0;
      fEndT = (float)v9->mNumControlPoints - 1.0;
    }
  }
  else
  {
    v16 = 1;
    v91 = 1;
  }
  v17 = FLOAT_1000000_0;
  v18 = 0;
  v19 = 0.0;
  v70 = 9187343238753681408i64;
  v72 = 9187343238753681408i64;
  v20 = 0.0;
  v21 = FLOAT_1000000_0;
  v74 = 9187343238753681408i64;
  v22 = 1;
  v86 = FLOAT_1000000_0;
  v78 = 0.0;
  v77 = FLOAT_1000000_0;
  v76 = 0.0;
  *(float *)&v73 = *((float *)&v73 + 1) - 1.0;
  *(float *)&v75 = *((float *)&v75 + 1) - 1.0;
  v71 = __PAIR__(LODWORD(v12), LODWORD(v11));
  if ( (float)(v15 * 2.0) > v15 )
  {
    do
    {
      if ( v17 <= v15 || v18 >= 500 )
        break;
      v23 = v22;
      v80 = v70;
      v81 = v71;
      v82 = v72;
      v83 = v73;
      v84 = v74;
      v85 = v75;
      if ( v22 > 0 )
      {
        v24 = v77;
        v25 = (float *)((char *)&v71 + 4);
        v26 = v13 / (float)(fSubdivisions - v13);
        v89 = v13 / (float)(fSubdivisions - v13);
        do
        {
          v27 = *v25;
          v28 = *(v25 - 1);
          v29 = 0.0;
          v30 = (float)(*v25 - v28) * v26;
          if ( fSubdivisions > 0.0 )
          {
            v31 = v10->x;
            do
            {
              ++v18;
              v32 = (float)(v29 * v30) + v28;
              UFG::HermiteCurve::GetPosition(v9, v32, &v88);
              v33 = (float)(v88.z - v10->z) * (float)(v88.z - v10->z);
              v34 = (float)((float)((float)(v88.y - v10->y) * (float)(v88.y - v10->y))
                          + (float)((float)(v88.x - v31) * (float)(v88.x - v31)))
                  + v33;
              if ( fHeightCoeff != -1.234 )
                v34 = v34 + (float)(v33 * fHeightCoeff);
              if ( v34 >= v24 )
              {
                v20 = v76;
              }
              else
              {
                v20 = (float)(v29 * v30) + v28;
                v24 = v34;
                v76 = (float)(v29 * v30) + v28;
              }
              v35 = 0;
              if ( v22 <= 0 )
              {
LABEL_32:
                v22 = 0;
                v37 = (float *)((char *)&v80 + 4);
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
                  v39 = &v84;
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
                *((float *)&v80 + 2 * v42 + 1) = v34;
                *((float *)&v80 + 2 * v42) = v32;
                *((float *)&v81 + 2 * v42) = v28;
                *((float *)&v81 + 2 * v42 + 1) = v27;
LABEL_40:
                if ( *(float *)&v80 >= 0.0 )
                  v22 = 1;
                if ( *(float *)&v82 >= 0.0 )
                  ++v22;
                if ( *(float *)&v84 >= 0.0 )
                  ++v22;
              }
              else
              {
                v36 = (float *)&v80;
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
            v26 = v89;
            v77 = v24;
          }
          v25 += 4;
          --v23;
        }
        while ( v23 );
        v12 = fEndT;
        v11 = v93;
        v21 = v77;
        v16 = v91;
        v13 = *(float *)&FLOAT_1_0;
        v14 = fSubdivisions;
        v17 = v86;
        v19 = v78;
        v15 = fStopThreshold;
      }
      v43 = fsqrt(v21);
      if ( v43 >= v17 )
      {
        v46 = 0.0;
      }
      else
      {
        v19 = v20;
        v44 = 0;
        v45 = 0i64;
        v78 = v20;
        v46 = v17 - v43;
        v17 = v43;
        v86 = v43;
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
            *(_DWORD *)((char *)&v70 + v47) = *(_DWORD *)((char *)&v80 + v47);
            *(_DWORD *)((char *)&v70 + v47 + 4) = *(_DWORD *)((char *)&v80 + v47 + 4);
            *(_DWORD *)((char *)&v71 + v47) = *(_DWORD *)((char *)&v81 + v47);
            *(_DWORD *)((char *)&v71 + v47 + 4) = *(_DWORD *)((char *)&v81 + v47 + 4);
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
            *(_DWORD *)((char *)&v72 + v47) = *(_DWORD *)((char *)&v82 + v47);
            *(_DWORD *)((char *)&v72 + v47 + 4) = *(_DWORD *)((char *)&v82 + v47 + 4);
            *(_DWORD *)((char *)&v73 + v47) = *(_DWORD *)((char *)&v83 + v47);
            *(_DWORD *)((char *)&v73 + v47 + 4) = *(_DWORD *)((char *)&v83 + v47 + 4);
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
            *(_DWORD *)((char *)&v74 + v47) = *(_DWORD *)((char *)&v84 + v47);
            *(_DWORD *)((char *)&v74 + v47 + 4) = *(_DWORD *)((char *)&v84 + v47 + 4);
            *(_DWORD *)((char *)&v75 + v47) = *(_DWORD *)((char *)&v85 + v47);
            *(_DWORD *)((char *)&v75 + v47 + 4) = *(_DWORD *)((char *)&v85 + v47 + 4);
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
            *(float *)((char *)&v76 + v47) = *(float *)((char *)&v86 + v47);
            *(_DWORD *)((char *)&v77 + v47) = *(int *)((char *)&v87 + v47);
            *(float *)((char *)&v78 + v47) = *(float *)((char *)&v88.x + v47);
            *(int *)((char *)&v79 + v47) = *(_DWORD *)((char *)&v88.y + v47);
            v60 = (float)(*(float *)((char *)&v79 + v47) - *(float *)((char *)&v78 + v47)) * v50;
            v61 = *(float *)((char *)&v76 + v47) - v60;
            v62 = *(float *)((char *)&v76 + v47) + v60;
            *(float *)((char *)&v78 + v47) = v61;
            *(float *)((char *)&v79 + v47) = v62;
            if ( !v16 )
            {
              if ( v61 <= v11 )
                v61 = v11;
              *(float *)((char *)&v78 + v47) = v61;
              if ( v62 >= v12 )
                v62 = v12;
              *(float *)((char *)&v79 + v47) = v62;
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
            *(_DWORD *)((char *)&v70 + v63) = *(_DWORD *)((char *)&v80 + v63);
            *(_DWORD *)((char *)&v70 + v63 + 4) = *(_DWORD *)((char *)&v80 + v63 + 4);
            *(_DWORD *)((char *)&v71 + v63) = *(_DWORD *)((char *)&v81 + v63);
            *(_DWORD *)((char *)&v71 + v63 + 4) = *(_DWORD *)((char *)&v81 + v63 + 4);
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
      v20 = v76;
    }
    while ( v46 > v15 );
    v8 = v92;
  }
  v68 = (float)v9->mNumControlPoints - v13;
  if ( v19 >= 0.0 )
  {
    if ( v19 > v68 )
      v19 = fmodf(v19, v68);
  }
  else
  {
    v19 = fmodf(v19, v68) + v68;
  }
  UFG::HermiteCurve::GetPosition(v9, v19, v8);
  return v19;
}

// File Line: 953
// RVA: 0x16D4A0
float __fastcall UFG::HermiteCurve::EstimateLength(UFG::HermiteCurve *this, int nSamplePoints)
{
  UFG::HermiteCurve *v2; // r8
  int v3; // er11
  float v4; // xmm8_4
  int v5; // er10
  signed __int64 v6; // r9
  UFG::HermiteControlPoint *v7; // rax
  unsigned __int64 v8; // rcx
  float v9; // xmm4_4
  __m128 v10; // xmm6
  __m128 v11; // xmm2
  float v12; // xmm3_4
  float v13; // xmm0_4
  __m128 v14; // xmm7
  float v15; // xmm5_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  __m128 v18; // xmm4
  float v19; // xmm0_4
  float v20; // xmm3_4
  signed __int64 v21; // rdx
  float *v22; // r8
  signed __int64 v23; // rax
  __m128 v24; // xmm2
  float v25; // xmm0_4
  float v26; // xmm1_4

  v2 = this;
  v3 = this->mNumControlPoints - 1;
  v4 = 0.0;
  v5 = this->mNumControlPoints - 1;
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
        v9 = v7->mPosition.x;
        v10 = (__m128)LODWORD(v7->mPosition.y);
        v11 = (__m128)LODWORD(v7[-1].mPosition.y);
        v12 = v7->mPosition.z;
        v13 = v7[-1].mPosition.z;
        v14 = (__m128)LODWORD(v7[1].mPosition.y);
        v15 = v7[1].mPosition.x;
        v16 = v7[-1].mPosition.x - v7->mPosition.x;
        v7 += 4;
        v11.m128_f32[0] = (float)((float)(v11.m128_f32[0] - v10.m128_f32[0]) * (float)(v11.m128_f32[0] - v10.m128_f32[0]))
                        + (float)(v16 * v16);
        v17 = v7[-2].mPosition.z;
        v11.m128_f32[0] = v11.m128_f32[0] + (float)((float)(v13 - v12) * (float)(v13 - v12));
        v10.m128_f32[0] = (float)((float)(v10.m128_f32[0] - v14.m128_f32[0]) * (float)(v10.m128_f32[0] - v14.m128_f32[0]))
                        + (float)((float)(v9 - v15) * (float)(v9 - v15));
        v18 = (__m128)LODWORD(v7[-2].mPosition.y);
        LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v11);
        v11.m128_i32[0] = LODWORD(v7[-3].mPosition.z);
        v10.m128_f32[0] = v10.m128_f32[0] + (float)((float)(v12 - v11.m128_f32[0]) * (float)(v12 - v11.m128_f32[0]));
        v20 = v7[-2].mPosition.x;
        v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] - v18.m128_f32[0])
                                        * (float)(v14.m128_f32[0] - v18.m128_f32[0]))
                                + (float)((float)(v15 - v20) * (float)(v15 - v20)))
                        + (float)((float)(v11.m128_f32[0] - v17) * (float)(v11.m128_f32[0] - v17));
        v18.m128_f32[0] = (float)((float)((float)(v18.m128_f32[0] - v7[-1].mPosition.y)
                                        * (float)(v18.m128_f32[0] - v7[-1].mPosition.y))
                                + (float)((float)(v20 - v7[-1].mPosition.x) * (float)(v20 - v7[-1].mPosition.x)))
                        + (float)((float)(v17 - v7[-1].mPosition.z) * (float)(v17 - v7[-1].mPosition.z));
        v4 = (float)((float)((float)(v4 + v19) + COERCE_FLOAT(_mm_sqrt_ps(v10))) + COERCE_FLOAT(_mm_sqrt_ps(v14)))
           + COERCE_FLOAT(_mm_sqrt_ps(v18));
        --v8;
      }
      while ( v8 );
    }
    if ( v6 < v5 )
    {
      v21 = v5 - v6;
      v22 = &v2->mControlPoints[v6].mPosition.x;
      v23 = (signed __int64)(v22 + 8);
      do
      {
        v24 = (__m128)*(unsigned int *)(v23 - 28);
        v25 = *(float *)(v23 - 24);
        v26 = *v22;
        v22 += 6;
        v23 += 24i64;
        v24.m128_f32[0] = (float)((float)((float)(v24.m128_f32[0] - *(float *)(v23 - 28))
                                        * (float)(v24.m128_f32[0] - *(float *)(v23 - 28)))
                                + (float)((float)(v26 - *(float *)(v23 - 32)) * (float)(v26 - *(float *)(v23 - 32))))
                        + (float)((float)(v25 - *(float *)(v23 - 24)) * (float)(v25 - *(float *)(v23 - 24)));
        v4 = v4 + COERCE_FLOAT(_mm_sqrt_ps(v24));
        --v21;
      }
      while ( v21 );
    }
    v4 = (float)(v4 / (float)v5) * (float)v3;
  }
  return v4;
}   }
      while ( v21 );
    }
    v4 = (float)(v4 / (float)v5) *

// File Line: 999
// RVA: 0x16F6F0
float __fastcall UFG::HermiteCurveWalker::GetClosestPoint(UFG::HermiteCurveWalker *this, UFG::qVector3 *outPos, UFG::qVector3 *outTangent, UFG::qVector3 *vCurrentPos, float fOffsetDist, float fStartT, float fEndT, int localPrecision, float fHeightCoeff)
{
  UFG::HermiteCurve *v9; // rdi
  UFG::qVector3 *v10; // r14
  UFG::qVector3 *v11; // r15
  UFG::qVector3 *v12; // rsi
  UFG::HermiteCurveWalker *v13; // rbx
  float v15; // xmm0_4
  float v16; // xmm9_4
  float v17; // xmm8_4
  char v18; // bp
  float v19; // xmm1_4
  signed int v20; // er9
  float v21; // xmm1_4
  UFG::HermiteControlPoint *v22; // r8
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm5_4
  float v26; // xmm0_4
  float v27; // xmm4_4
  float precision; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  float v32; // xmm6_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm1_4

  v9 = this->mpCurve;
  v10 = vCurrentPos;
  v11 = outTangent;
  v12 = outPos;
  v13 = this;
  if ( !this->mpCurve )
    return 0.0;
  if ( this->mfCurveLength <= 0.0 )
  {
    v15 = UFG::HermiteCurve::EstimateLength(v9, v9->mNumControlPoints);
    v13->mfCurveLength = v15;
    if ( v15 == 0.0 )
      return 0.0;
  }
  v16 = fStartT;
  if ( fStartT == -1.234 )
    v16 = 0.0;
  v17 = fEndT;
  if ( fEndT == -1.234 )
    v17 = (float)v9->mNumControlPoints - 1.0;
  if ( v17 == v16 )
  {
    v18 = 1;
  }
  else
  {
    v19 = (float)(signed int)(float)(v16 + 0.5);
    if ( v19 < 0.0 )
      v19 = 0.0;
    v20 = (signed int)v19;
    v21 = (float)v9->mNumControlPoints;
    if ( v21 >= (float)(signed int)(float)(v17 + 0.5) )
      v21 = (float)(signed int)(float)(v17 + 0.5);
    v22 = v9->mControlPoints;
    v18 = 0;
    v23 = v22[v20].mPosition.y - v22[v21].mPosition.y;
    v24 = v22[v20].mPosition.z - v22[v21].mPosition.z;
    if ( (float)((float)((float)(v23 * v23)
                       + (float)((float)(v22[v20].mPosition.x - v22[v21].mPosition.x)
                               * (float)(v22[v20].mPosition.x - v22[v21].mPosition.x)))
               + (float)(v24 * v24)) < 9.0 )
      v18 = 1;
  }
  v25 = v13->mfLastT;
  if ( v25 < 0.0
    || (v26 = v10->y - v13->mvLastPos.y,
        v27 = v10->z - v13->mvLastPos.z,
        (float)((float)((float)(v26 * v26)
                      + (float)((float)(v10->x - v13->mvLastPos.x) * (float)(v10->x - v13->mvLastPos.x)))
              + (float)(v27 * v27)) > (float)((float)(COERCE_FLOAT(LODWORD(fOffsetDist) & _xmm) + v13->mfGlobalSearchDist)
                                            * (float)(COERCE_FLOAT(LODWORD(fOffsetDist) & _xmm) + v13->mfGlobalSearchDist))) )
  {
    if ( v18 )
      v29 = UFG::HermiteCurve::ClosestPointEx(v9, v10, v12, -1.234, -1.234, -1.0, -1.234, fHeightCoeff);
    else
      v29 = UFG::HermiteCurve::ClosestPointEx(v9, v10, v12, v16, v17, -1.0, -1.234, fHeightCoeff);
  }
  else
  {
    precision = (float)localPrecision;
    if ( v18 )
      v29 = UFG::HermiteCurve::GetLocalClosestPoint(v9, v10, v12, v25, precision, -1.234, 0i64);
    else
      v29 = UFG::HermiteCurve::GetLocalClosestPoint(v9, v10, v12, v25, v16, v17, precision, 0i64);
  }
  v30 = v29;
  v31 = 0.0;
  if ( COERCE_FLOAT(LODWORD(fOffsetDist) & _xmm) > 0.0 )
    v31 = (float)(v13->mpCurve->mNumControlPoints - 1) * (float)(fOffsetDist / v13->mfCurveLength);
  v32 = v30 + v31;
  v33 = (float)(v13->mpCurve->mNumControlPoints - 1);
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
  UFG::HermiteCurve::GetPosition(v13->mpCurve, v32, v12);
  UFG::HermiteCurve::GetTangent(v13->mpCurve, v32, v11);
  v13->mfLastT = v32;
  v34 = v12->y;
  v35 = v12->z;
  v13->mvLastPos.x = v12->x;
  v13->mvLastPos.y = v34;
  v13->mvLastPos.z = v35;
  return v32;
}

