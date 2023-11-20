// File Line: 86
// RVA: 0x23D3E0
UFG::qVector3 *__fastcall UFG::RegionBase::GetClosestPointOutside(UFG::RegionBase *this, UFG::qVector3 *result, UFG::qVector3 *pos)
{
  result->x = pos->x;
  result->y = pos->y;
  result->z = pos->z;
  return result;
}

// File Line: 121
// RVA: 0x23A3C0
UFG::allocator::free_link *__fastcall UFG::RegionSphere::Clone(UFG::RegionSphere *this)
{
  UFG::RegionSphere *v1; // rbx
  UFG::allocator::free_link *result; // rax

  v1 = this;
  result = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
  if ( !result )
    return 0i64;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable';
  LODWORD(result[1].mNext) = 0;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionSphere::`vftable';
  *(float *)&result[2].mNext = v1->mRadius;
  return result;
}

// File Line: 128
// RVA: 0x23D1A0
void __fastcall UFG::RegionSphere::GetBoundingBox(UFG::RegionSphere *this, UFG::qBox *pBox)
{
  int v2; // xmm0_4
  float v3; // xmm0_4

  v2 = LODWORD(this->mRadius) ^ _xmm[0];
  LODWORD(pBox->mMin.x) = v2;
  LODWORD(pBox->mMin.y) = v2;
  LODWORD(pBox->mMin.z) = v2;
  v3 = this->mRadius;
  pBox->mMax.x = v3;
  pBox->mMax.y = v3;
  pBox->mMax.z = v3;
}

// File Line: 149
// RVA: 0x23DE60
UFG::qVector3 *__fastcall UFG::RegionSphere::GetRandomPosition(UFG::RegionSphere *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rdi
  UFG::RegionSphere *v3; // rbx
  float v4; // xmm7_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  UFG::qVector3 *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm2_4

  v2 = result;
  v3 = this;
  v4 = UFG::qRandom(360.0, &UFG::qDefaultSeed);
  v5 = UFG::qRandom(360.0, &UFG::qDefaultSeed);
  UFG::qSphericalToCartesian(v2, v4, v5);
  v6 = UFG::qRandom(v3->mRadius, &UFG::qDefaultSeed);
  v7 = v2;
  v8 = v6 * v2->x;
  v9 = v6 * v2->y;
  v2->z = v6 * v2->z;
  v2->x = v8;
  v2->y = v9;
  return v7;
}

// File Line: 172
// RVA: 0x23E1F0
signed __int64 __fastcall CAkMatrixAwareCtx::SeekPercent(hkpCapsuleShape *this)
{
  return 2i64;
}

// File Line: 184
// RVA: 0x240620
bool __fastcall UFG::RegionSphere::IsHitPoint(UFG::RegionSphere *this, UFG::qVector3 *pos)
{
  return (float)(this->mRadius * this->mRadius) >= (float)((float)((float)(pos->x * pos->x) + (float)(pos->y * pos->y))
                                                         + (float)(pos->z * pos->z));
}

// File Line: 197
// RVA: 0x240BA0
bool __fastcall UFG::RegionSphere::IsHitPointWS(UFG::RegionSphere *this, UFG::qVector3 *pos, UFG::qMatrix44 *localWorld)
{
  return (float)((float)((float)((float)(localWorld->v2.x * localWorld->v2.x)
                               + (float)(localWorld->v2.y * localWorld->v2.y))
                       + (float)(localWorld->v2.z * localWorld->v2.z))
               * this->mRadius) >= (float)((float)((float)((float)(pos->y - localWorld->v3.y)
                                                         * (float)(pos->y - localWorld->v3.y))
                                                 + (float)((float)(pos->x - localWorld->v3.x)
                                                         * (float)(pos->x - localWorld->v3.x)))
                                         + (float)((float)(pos->z - localWorld->v3.z)
                                                 * (float)(pos->z - localWorld->v3.z)));
}

// File Line: 223
// RVA: 0x242230
bool __fastcall UFG::RegionSphere::IsHitSegment(UFG::RegionSphere *this, UFG::qVector3 *start, UFG::qVector3 *end, UFG::qVector3 *pHitPos)
{
  UFG::qVector3 *v4; // rbx
  float v5; // xmm6_4
  UFG::qVector3 *v6; // rax
  bool v7; // al
  char v8; // al
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  UFG::qVector3 entry_p; // [rsp+30h] [rbp-38h]
  UFG::qVector3 result; // [rsp+40h] [rbp-28h]

  v4 = pHitPos;
  if ( pHitPos )
  {
    v8 = UFG::qIntersectSegSphere(start, end, &UFG::qVector3::msZero, this->mRadius, &entry_p, &result);
    if ( v8 & 1 )
    {
      v9 = entry_p.y;
      v7 = 1;
      v4->x = entry_p.x;
      v10 = entry_p.z;
      v4->y = v9;
      v4->z = v10;
    }
    else if ( v8 & 2 )
    {
      v11 = result.y;
      v7 = 1;
      v4->x = result.x;
      v12 = result.z;
      v4->y = v11;
      v4->z = v12;
    }
    else
    {
      v7 = 0;
    }
  }
  else
  {
    v5 = this->mRadius;
    v6 = UFG::qNearestSegPoint(&result, start, end, &UFG::qVector3::msZero);
    v7 = (float)(v5 * v5) >= (float)((float)((float)((float)(UFG::qVector3::msZero.y - v6->y)
                                                   * (float)(UFG::qVector3::msZero.y - v6->y))
                                           + (float)((float)(UFG::qVector3::msZero.x - v6->x)
                                                   * (float)(UFG::qVector3::msZero.x - v6->x)))
                                   + (float)((float)(UFG::qVector3::msZero.z - v6->z)
                                           * (float)(UFG::qVector3::msZero.z - v6->z)));
  }
  return v7;
}

// File Line: 270
// RVA: 0x242CF0
bool __fastcall UFG::RegionSphere::IsHitSegmentWS(UFG::RegionSphere *this, UFG::qVector3 *start, UFG::qVector3 *end, UFG::qMatrix44 *localWorld, UFG::qVector3 *pHitPos)
{
  __m128 v5; // xmm2
  UFG::qMatrix44 *v6; // rdi
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm6_4
  float v10; // xmm8_4
  float v11; // xmm9_4
  float v12; // xmm7_4
  UFG::qVector3 *v13; // rax
  bool v14; // al
  char v15; // al
  float v16; // xmm4_4
  float v17; // xmm6_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  UFG::qVector4 *v25; // rax
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::qVector3 pos; // [rsp+30h] [rbp-98h]
  UFG::qVector3 entry_p; // [rsp+40h] [rbp-88h]
  UFG::qVector3 result; // [rsp+50h] [rbp-78h]
  UFG::qVector4 row_vec4; // [rsp+60h] [rbp-68h]
  UFG::qVector4 v33; // [rsp+70h] [rbp-58h]

  v5 = (__m128)LODWORD(localWorld->v2.x);
  v6 = localWorld;
  v7 = localWorld->v2.y * localWorld->v2.y;
  v8 = localWorld->v2.z * localWorld->v2.z;
  v9 = localWorld->v3.y;
  v10 = localWorld->v3.x;
  v11 = localWorld->v3.z;
  pos.x = localWorld->v3.x;
  pos.y = v9;
  v5.m128_f32[0] = (float)((float)(v5.m128_f32[0] * v5.m128_f32[0]) + v7) + v8;
  pos.z = v11;
  v12 = COERCE_FLOAT(_mm_sqrt_ps(v5)) * this->mRadius;
  if ( pHitPos )
  {
    v15 = UFG::qIntersectSegSphere(start, end, &pos, v12, &entry_p, &result);
    if ( v15 & 1 )
    {
      v16 = entry_p.x;
      v17 = entry_p.y;
      v18 = entry_p.z;
      v14 = 1;
      v19 = entry_p.y;
      *(_QWORD *)&pHitPos->x = *(_QWORD *)&entry_p.x;
      pHitPos->z = v18;
      v20 = (float)((float)((float)(v17 * v6->v1.x) + (float)(v16 * v6->v0.x)) + (float)(v18 * v6->v2.x)) + v6->v3.x;
      v21 = (float)((float)((float)(v17 * v6->v1.z) + (float)(v16 * v6->v0.z)) + (float)(v18 * v6->v2.z)) + v6->v3.z;
      pHitPos->y = (float)((float)((float)(v19 * v6->v1.y) + (float)(v16 * v6->v0.y)) + (float)(v18 * v6->v2.y))
                 + v6->v3.y;
      pHitPos->x = v20;
      pHitPos->z = v21;
    }
    else if ( v15 & 2 )
    {
      v22 = result.z;
      v23 = result.x;
      v24 = result.y;
      pHitPos->z = result.z;
      *(_QWORD *)&row_vec4.z = __PAIR__((unsigned int)FLOAT_1_0, LODWORD(v22));
      pHitPos->x = v23;
      pHitPos->y = v24;
      row_vec4.x = v23;
      row_vec4.y = v24;
      v25 = UFG::operator*(&v33, &row_vec4, v6);
      v26 = v25->x;
      v27 = v25->y;
      v28 = v25->z;
      v14 = 1;
      pHitPos->x = v26;
      pHitPos->y = v27;
      pHitPos->z = v28;
    }
    else
    {
      v14 = 0;
    }
  }
  else
  {
    v13 = UFG::qNearestSegPoint(&result, start, end, &pos);
    v14 = (float)(v12 * v12) >= (float)((float)((float)((float)(v9 - v13->y) * (float)(v9 - v13->y))
                                              + (float)((float)(v10 - v13->x) * (float)(v10 - v13->x)))
                                      + (float)((float)(v11 - v13->z) * (float)(v11 - v13->z)));
  }
  return v14;
}

// File Line: 329
// RVA: 0x240F60
char __fastcall UFG::RegionSphere::IsHitRay(UFG::RegionSphere *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qVector3 *pHitPos)
{
  UFG::qVector3 *v4; // rbx
  UFG::qVector3 *exit_p; // rax
  int v6; // eax
  int v7; // xmm1_4
  int v8; // xmm0_4
  float v10; // [rsp+30h] [rbp-18h]
  int v11; // [rsp+34h] [rbp-14h]
  int v12; // [rsp+38h] [rbp-10h]

  v4 = pHitPos;
  exit_p = (UFG::qVector3 *)&v10;
  if ( !pHitPos )
    exit_p = 0i64;
  v6 = UFG::qIntersectRaySphere(rayPos, rayDir, &UFG::qVector3::msZero, this->mRadius, pHitPos, exit_p);
  if ( v6 == 3 )
    return 1;
  if ( v6 == 2 )
  {
    v7 = v11;
    v4->x = v10;
    v8 = v12;
    LODWORD(v4->y) = v7;
    LODWORD(v4->z) = v8;
    return 1;
  }
  return 0;
}

// File Line: 366
// RVA: 0x241880
char __fastcall UFG::RegionSphere::IsHitRayWS(UFG::RegionSphere *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qMatrix44 *localWorld, UFG::qVector3 *pHitPos)
{
  float v5; // xmm1_4
  __m128 v6; // xmm2
  UFG::qVector3 *exit_p; // rax
  float v8; // xmm0_4
  UFG::qMatrix44 *v9; // rdi
  float v10; // xmm1_4
  float v11; // xmm3_4
  int v12; // eax
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  UFG::qVector3 origin; // [rsp+30h] [rbp-38h]
  float v20; // [rsp+40h] [rbp-28h]
  float v21; // [rsp+44h] [rbp-24h]
  float v22; // [rsp+48h] [rbp-20h]

  v5 = localWorld->v3.y;
  v6 = (__m128)LODWORD(localWorld->v2.x);
  exit_p = (UFG::qVector3 *)&v20;
  origin.x = localWorld->v3.x;
  v8 = localWorld->v3.z;
  origin.y = v5;
  v9 = localWorld;
  v10 = localWorld->v2.y;
  origin.z = v8;
  v6.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v10 * v10))
                 + (float)(localWorld->v2.z * localWorld->v2.z);
  v11 = COERCE_FLOAT(_mm_sqrt_ps(v6)) * this->mRadius;
  if ( !pHitPos )
    exit_p = 0i64;
  v12 = UFG::qIntersectRaySphere(rayPos, rayDir, &origin, v11, pHitPos, exit_p);
  if ( pHitPos )
  {
    v13 = pHitPos->z;
    v14 = (float)((float)((float)(pHitPos->y * v9->v1.x) + (float)(pHitPos->x * v9->v0.x)) + (float)(v13 * v9->v2.x))
        + v9->v3.x;
    v15 = (float)((float)((float)(pHitPos->y * v9->v1.y) + (float)(pHitPos->x * v9->v0.y)) + (float)(v13 * v9->v2.y))
        + v9->v3.y;
    pHitPos->z = (float)((float)((float)(pHitPos->y * v9->v1.z) + (float)(pHitPos->x * v9->v0.z))
                       + (float)(v13 * v9->v2.z))
               + v9->v3.z;
    pHitPos->x = v14;
    pHitPos->y = v15;
  }
  if ( v12 == 3 )
    return 1;
  if ( v12 == 2 )
  {
    v16 = v21;
    pHitPos->x = v20;
    v17 = v22;
    pHitPos->y = v16;
    pHitPos->z = v17;
    return 1;
  }
  return 0;
}

// File Line: 411
// RVA: 0x23F980
char __fastcall UFG::RegionSphere::IsHitPlaneRay(UFG::RegionSphere *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qVector3 *pHitPos)
{
  UFG::qVector3 *v4; // rbx
  float v5; // xmm7_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  UFG::qVector3 plane_pos; // [rsp+30h] [rbp-48h]
  UFG::qVector3 hit_pos_p; // [rsp+40h] [rbp-38h]

  v4 = pHitPos;
  v5 = this->mRadius;
  *(_QWORD *)&plane_pos.x = 0i64;
  plane_pos.z = 0.0;
  if ( !UFG::qIntersectRayPlane(rayPos, rayDir, &UFG::qVector3::msDirUp, &plane_pos, &hit_pos_p) )
    return 0;
  v6 = hit_pos_p.y;
  v7 = hit_pos_p.z;
  if ( (float)((float)((float)(COERCE_FLOAT(LODWORD(hit_pos_p.y) ^ _xmm[0])
                             * COERCE_FLOAT(LODWORD(hit_pos_p.y) ^ _xmm[0]))
                     + (float)(COERCE_FLOAT(LODWORD(hit_pos_p.x) ^ _xmm[0])
                             * COERCE_FLOAT(LODWORD(hit_pos_p.x) ^ _xmm[0])))
             + (float)(COERCE_FLOAT(LODWORD(hit_pos_p.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(hit_pos_p.z) ^ _xmm[0]))) > (float)(v5 * v5) )
    return 0;
  if ( v4 )
  {
    v4->x = hit_pos_p.x;
    v4->y = v6;
    v4->z = v7;
  }
  return 1;
}

// File Line: 432
// RVA: 0x240280
char __fastcall UFG::RegionSphere::IsHitPlaneRayWS(UFG::RegionSphere *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qMatrix44 *localWorld, UFG::qVector3 *pHitPos)
{
  __m128 v5; // xmm2
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm7_4
  float v9; // xmm6_4
  float v10; // xmm8_4
  float v11; // xmm9_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v15; // [rsp+30h] [rbp-68h]
  float v16; // [rsp+34h] [rbp-64h]
  float v17; // [rsp+38h] [rbp-60h]
  float v18; // [rsp+40h] [rbp-58h]
  float v19; // [rsp+44h] [rbp-54h]
  float v20; // [rsp+48h] [rbp-50h]

  v5 = (__m128)LODWORD(localWorld->v2.x);
  v6 = localWorld->v2.y * localWorld->v2.y;
  v7 = localWorld->v2.z * localWorld->v2.z;
  v8 = localWorld->v3.x;
  v9 = localWorld->v3.y;
  v10 = localWorld->v3.z;
  v15 = localWorld->v3.x;
  v16 = v9;
  v5.m128_f32[0] = (float)((float)(v5.m128_f32[0] * v5.m128_f32[0]) + v6) + v7;
  v17 = v10;
  v11 = COERCE_FLOAT(_mm_sqrt_ps(v5)) * this->mRadius;
  if ( !UFG::qIntersectRayPlane(rayPos, rayDir, &UFG::qVector3::msDirUp, (UFG::qVector3 *)&v15, (UFG::qVector3 *)&v18) )
    return 0;
  v12 = v19;
  v13 = v20;
  if ( (float)((float)((float)((float)(v9 - v19) * (float)(v9 - v19)) + (float)((float)(v8 - v18) * (float)(v8 - v18)))
             + (float)((float)(v10 - v20) * (float)(v10 - v20))) > (float)(v11 * v11) )
    return 0;
  if ( pHitPos )
  {
    pHitPos->x = v18;
    pHitPos->y = v12;
    pHitPos->z = v13;
  }
  return 1;
}

// File Line: 448
// RVA: 0x246430
void __fastcall UFG::RegionSphere::TranslateAspect(UFG::RegionSphere *this, unsigned int aspect, UFG::qVector3 *delta)
{
  UFG::qVector3 *v3; // rbx
  UFG::RegionSphere *v4; // rdi
  UFG::qVector3 *v5; // rax
  __m128 v6; // xmm0
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  char v10; // [rsp+20h] [rbp-18h]

  v3 = delta;
  v4 = this;
  v5 = this->vfptr->GetAspectCenter((UFG::RegionBase *)this, (UFG::qVector3 *)&v10, aspect);
  v6 = (__m128)LODWORD(v5->x);
  v7 = v3->y + v5->y;
  v8 = v3->z + v5->z;
  v6.m128_f32[0] = v6.m128_f32[0] + v3->x;
  v5->y = v7;
  v5->z = v8;
  LODWORD(v5->x) = v6.m128_i32[0];
  v6.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v7 * v7)) + (float)(v8 * v8);
  LODWORD(v9) = (unsigned __int128)_mm_sqrt_ps(v6);
  v4->mRadius = v9;
  if ( v9 < 0.0 )
    v4->mRadius = 0.0;
}

// File Line: 503
// RVA: 0x23A270
UFG::allocator::free_link *__fastcall UFG::RegionBox::Clone(UFG::RegionBox *this)
{
  UFG::RegionBox *v1; // rbx
  UFG::allocator::free_link *result; // rax
  float v3; // xmm1_4
  int v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  v1 = this;
  result = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  if ( !result )
    return 0i64;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable';
  LODWORD(result[1].mNext) = 0;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionBox::`vftable';
  v3 = v1->mBox.mMin.y;
  v4 = LODWORD(v1->mBox.mMin.z);
  *(float *)&result[2].mNext = v1->mBox.mMin.x;
  *((float *)&result[2].mNext + 1) = v3;
  LODWORD(result[3].mNext) = v4;
  v5 = v1->mBox.mMax.y;
  v6 = v1->mBox.mMax.z;
  HIDWORD(result[3].mNext) = LODWORD(v1->mBox.mMax.x);
  *(float *)&result[4].mNext = v5;
  *((float *)&result[4].mNext + 1) = v6;
  return result;
}

// File Line: 512
// RVA: 0x23D1D0
void __fastcall UFG::RegionBox::GetCenter(UFG::RegionBox *this, UFG::qVector3 *pPos)
{
  float v2; // xmm2_4
  float v3; // xmm3_4
  float v4; // xmm3_4
  float v5; // xmm0_4

  v2 = this->mBox.mMin.y;
  v3 = this->mBox.mMin.z;
  pPos->x = this->mBox.mMin.x;
  pPos->y = v2;
  pPos->z = v3;
  v4 = (float)(v3 + this->mBox.mMax.z) * 0.5;
  v5 = this->mBox.mMax.x + pPos->x;
  pPos->y = (float)(v2 + this->mBox.mMax.y) * 0.5;
  pPos->z = v4;
  pPos->x = v5 * 0.5;
}

// File Line: 522
// RVA: 0x23DB10
UFG::qVector3 *__fastcall UFG::RegionBox::GetRandomPosition(UFG::RegionBox *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx

  v2 = result;
  UFG::qBox::GetRandomPosition(&this->mBox, result);
  return v2;
}

// File Line: 544
// RVA: 0x23E2B0
void __fastcall UFG::RegionBox::GetVisualAnchor(UFG::RegionBox *this, UFG::qVector3 *vPos)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = this->mBox.mMax.y;
  v3 = this->mBox.mMax.z;
  vPos->x = this->mBox.mMax.x;
  vPos->y = v2;
  vPos->z = v3;
}

// File Line: 556
// RVA: 0x2403A0
bool __fastcall UFG::RegionBox::IsHitPoint(UFG::RegionBox *this, UFG::qVector3 *pos)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  bool result; // al

  result = 0;
  if ( pos->x >= this->mBox.mMin.x && pos->x <= this->mBox.mMax.x )
  {
    v2 = pos->y;
    if ( v2 >= this->mBox.mMin.y && v2 <= this->mBox.mMax.y )
    {
      v3 = pos->z;
      if ( v3 >= this->mBox.mMin.z && v3 <= this->mBox.mMax.z )
        result = 1;
    }
  }
  return result;
}

// File Line: 568
// RVA: 0x240670
bool __fastcall UFG::RegionBox::IsHitPointWS(UFG::RegionBox *this, UFG::qVector3 *pos, UFG::qMatrix44 *localWorld)
{
  __m128 v3; // xmm3
  UFG::qMatrix44 *v4; // rsi
  UFG::qVector3 *v5; // rdi
  UFG::RegionBox *v6; // rbx
  float v7; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm9_4
  float v10; // xmm8_4
  float v11; // xmm0_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm6_4
  __m128 v15; // xmm3
  float v17; // xmm2_4
  float v18; // xmm4_4
  float v19; // xmm7_4
  float v20; // xmm6_4
  float v21; // xmm5_4
  UFG::qMatrix44 d; // [rsp+20h] [rbp-88h]

  v3 = (__m128)LODWORD(localWorld->v2.x);
  v4 = localWorld;
  v5 = pos;
  v6 = this;
  v7 = (float)(this->mBox.mMin.x + this->mBox.mMax.x) * 0.5;
  v8 = (float)(this->mBox.mMax.z + this->mBox.mMin.z) * 0.5;
  v9 = (float)(this->mBox.mMax.y + this->mBox.mMin.y) * 0.5;
  v10 = (float)((float)((float)(v9 * localWorld->v1.x) + (float)(v7 * localWorld->v0.x)) + (float)(localWorld->v2.x * v8))
      + localWorld->v3.x;
  v11 = localWorld->v2.y * localWorld->v2.y;
  v12 = (float)((float)((float)(v9 * localWorld->v1.y) + (float)(v7 * localWorld->v0.y)) + (float)(v8 * localWorld->v2.y))
      + localWorld->v3.y;
  v13 = (float)((float)((float)(v9 * localWorld->v1.z) + (float)(v7 * localWorld->v0.z)) + (float)(v8 * localWorld->v2.z))
      + localWorld->v3.z;
  v3.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0]) + v11)
                 + (float)(localWorld->v2.z * localWorld->v2.z);
  LODWORD(v14) = (unsigned __int128)_mm_sqrt_ps(v3);
  ((void (*)(void))this->vfptr->GetRadius)();
  v15 = (__m128)LODWORD(v5->y);
  v15.m128_f32[0] = (float)((float)((float)(v15.m128_f32[0] - v12) * (float)(v15.m128_f32[0] - v12))
                          + (float)((float)(v5->x - v10) * (float)(v5->x - v10)))
                  + (float)((float)(v5->z - v13) * (float)(v5->z - v13));
  if ( COERCE_FLOAT(_mm_sqrt_ps(v15)) > (float)(v11 * v14) )
    return 0;
  UFG::qInverse(&d, v4);
  v17 = v5->y;
  v18 = v5->z;
  v19 = (float)((float)((float)(d.v1.x * v17) + (float)(d.v0.x * v5->x)) + (float)(d.v2.x * v18)) + d.v3.x;
  v20 = (float)((float)((float)(d.v1.y * v17) + (float)(d.v0.y * v5->x)) + (float)(d.v2.y * v18)) + d.v3.y;
  v21 = (float)((float)((float)(d.v1.z * v17) + (float)(d.v0.z * v5->x)) + (float)(d.v2.z * v18)) + d.v3.z;
  return v19 >= v6->mBox.mMin.x
      && v19 <= v6->mBox.mMax.x
      && v20 >= v6->mBox.mMin.y
      && v20 <= v6->mBox.mMax.y
      && v21 >= v6->mBox.mMin.z
      && v21 <= v6->mBox.mMax.z;
}

// File Line: 601
// RVA: 0x2419F0
char __fastcall UFG::RegionBox::IsHitSegment(UFG::RegionBox *this, UFG::qVector3 *start, UFG::qVector3 *end, UFG::qVector3 *pHitPos)
{
  return UFG::qBox::IsHitSeg(&this->mBox, start, end, 0i64, pHitPos);
}

// File Line: 622
// RVA: 0x242340
char __fastcall UFG::RegionBox::IsHitSegmentWS(UFG::RegionBox *this, UFG::qVector3 *start, UFG::qVector3 *end, UFG::qMatrix44 *localWorld, UFG::qVector3 *pHitPos)
{
  __m128 v5; // xmm4
  UFG::qBox *v6; // r14
  UFG::qMatrix44 *v7; // rbx
  UFG::qVector3 *v8; // rdi
  UFG::qVector3 *v9; // rsi
  UFG::RegionBaseVtbl *v10; // rax
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm10_4
  float v14; // xmm9_4
  float v15; // xmm8_4
  float v16; // xmm10_4
  float v17; // xmm9_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm8_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm8_4
  float v25; // xmm10_4
  float v26; // xmm6_4
  UFG::qVector3 *v27; // rax
  char v28; // al
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  float v33; // xmm13_4
  float v34; // xmm5_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm6_4
  UFG::qVector3 pos; // [rsp+30h] [rbp-B8h]
  UFG::qVector3 result; // [rsp+40h] [rbp-A8h]
  UFG::qMatrix44 d; // [rsp+50h] [rbp-98h]
  float v43; // [rsp+118h] [rbp+30h]
  float v44; // [rsp+130h] [rbp+48h]
  UFG::qVector3 *v45; // [rsp+138h] [rbp+50h]

  v5 = (__m128)LODWORD(localWorld->v2.x);
  v6 = &this->mBox;
  v7 = localWorld;
  v8 = end;
  v9 = start;
  v10 = this->vfptr;
  v11 = (float)(this->mBox.mMin.x + this->mBox.mMax.x) * 0.5;
  v12 = (float)(this->mBox.mMin.z + this->mBox.mMax.z) * 0.5;
  v13 = (float)(this->mBox.mMin.y + this->mBox.mMax.y) * 0.5;
  v14 = v13 * localWorld->v1.x;
  v15 = v13 * localWorld->v1.y;
  v16 = v13 * localWorld->v1.z;
  v17 = (float)((float)(v14 + (float)(v11 * localWorld->v0.x)) + (float)(localWorld->v2.x * v12)) + localWorld->v3.x;
  v18 = v11 * localWorld->v0.y;
  v19 = v12 * localWorld->v2.y;
  v20 = v11 * localWorld->v0.z;
  pos.x = v17;
  v21 = (float)(v15 + v18) + v19;
  v22 = localWorld->v2.y * localWorld->v2.y;
  v23 = localWorld->v2.z * localWorld->v2.z;
  v24 = v21 + localWorld->v3.y;
  v25 = (float)((float)(v16 + v20) + (float)(v12 * localWorld->v2.z)) + localWorld->v3.z;
  pos.y = v24;
  v5.m128_f32[0] = (float)((float)(v5.m128_f32[0] * v5.m128_f32[0]) + v22) + v23;
  pos.z = v25;
  LODWORD(v26) = (unsigned __int128)_mm_sqrt_ps(v5);
  ((void (*)(void))v10->GetRadius)();
  v27 = UFG::qNearestSegPoint(&result, v9, v8, &pos);
  if ( (float)((float)((float)((float)(v24 - v27->y) * (float)(v24 - v27->y))
                     + (float)((float)(v17 - v27->x) * (float)(v17 - v27->x)))
             + (float)((float)(v25 - v27->z) * (float)(v25 - v27->z))) > (float)((float)(v22 * v26) * (float)(v22 * v26)) )
    return 0;
  UFG::qInverse(&d, v7);
  v29 = v9->x;
  v30 = v9->y;
  v31 = v9->z;
  v32 = d.v0.y * v9->x;
  v33 = d.v1.z * v30;
  v43 = (float)((float)((float)(d.v1.x * v30) + (float)(d.v0.x * v9->x)) + (float)(d.v2.x * v31)) + d.v1.z;
  v34 = d.v1.y * v30;
  v35 = v8->z;
  v44 = (float)((float)(v34 + v32) + (float)(d.v2.y * v31)) + d.v1.w;
  v36 = v8->y;
  v37 = v8->x;
  result.x = v43;
  pos.x = (float)((float)((float)(d.v1.x * v36) + (float)(d.v0.x * v37)) + (float)(d.v2.x * v35)) + d.v1.z;
  pos.y = (float)((float)((float)(d.v1.y * v36) + (float)(d.v0.y * v37)) + (float)(d.v2.y * v35)) + d.v1.w;
  pos.z = (float)((float)((float)(d.v1.z * v36) + (float)(d.v0.z * v37)) + (float)(d.v2.z * v35)) + d.v2.x;
  result.y = v44;
  result.z = (float)((float)(v33 + (float)(d.v0.z * v29)) + (float)(d.v2.z * v31)) + d.v2.x;
  v28 = UFG::qBox::IsHitSeg(v6, &result, &pos, 0i64, v45);
  if ( v45 )
  {
    v38 = (float)((float)((float)(v45->y * v7->v1.y) + (float)(v45->x * v7->v0.y)) + (float)(v45->z * v7->v2.y))
        + v7->v3.y;
    v39 = (float)((float)((float)(v45->y * v7->v1.z) + (float)(v45->x * v7->v0.z)) + (float)(v45->z * v7->v2.z))
        + v7->v3.z;
    v45->x = (float)((float)((float)(v45->y * v7->v1.x) + (float)(v45->x * v7->v0.x)) + (float)(v45->z * v7->v2.x))
           + v7->v3.x;
    v45->y = v38;
    v45->z = v39;
  }
  return v28;
}t)(v45->z * v7->v2.x))
           + v7->v3.x;
    

// File Line: 662
// RVA: 0x240C10
char __fastcall UFG::RegionBox::IsHitRay(UFG::RegionBox *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qVector3 *pHitPos)
{
  return UFG::qBox::IsHitRay(&this->mBox, rayPos, rayDir, 0i64, pHitPos);
}

// File Line: 683
// RVA: 0x240FE0
char __fastcall UFG::RegionBox::IsHitRayWS(UFG::RegionBox *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qMatrix44 *localWorld)
{
  UFG::RegionBaseVtbl *v4; // rax
  UFG::qBox *v5; // rsi
  UFG::qMatrix44 *v6; // rbx
  UFG::qVector3 *v7; // rdi
  UFG::qVector3 *v8; // r14
  float v9; // xmm4_4
  float v10; // xmm5_4
  __m128 v11; // xmm6
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm5_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm7_4
  float v24; // xmm7_4
  char result; // al
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm4_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  float v31; // xmm5_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm5_4
  float v35; // xmm3_4
  float v36; // xmm4_4
  float v37; // xmm2_4
  float v38; // xmm6_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-49h]
  UFG::qVector3 rayPosa; // [rsp+30h] [rbp-39h]
  UFG::qMatrix44 d; // [rsp+48h] [rbp-21h]
  float v42; // [rsp+C8h] [rbp+5Fh]
  UFG::qVector3 *v43; // [rsp+E8h] [rbp+7Fh]

  v4 = this->vfptr;
  v5 = &this->mBox;
  v6 = localWorld;
  v7 = rayDir;
  v8 = rayPos;
  v9 = (float)(this->mBox.mMin.z + this->mBox.mMax.z) * 0.5;
  v10 = (float)(this->mBox.mMin.x + this->mBox.mMax.x) * 0.5;
  v11 = (__m128)LODWORD(localWorld->v2.x);
  v12 = (float)(this->mBox.mMin.y + this->mBox.mMax.y) * 0.5;
  v13 = v12 * localWorld->v1.x;
  v14 = v12 * localWorld->v1.y;
  v15 = v12 * localWorld->v1.z;
  v16 = (float)((float)((float)(v10 * localWorld->v0.x) + v13) + (float)(localWorld->v2.x * v9)) + localWorld->v3.x;
  v17 = v10 * localWorld->v0.y;
  v18 = v9 * localWorld->v2.y;
  v19 = v10 * localWorld->v0.z;
  pos.x = v16;
  v20 = (float)(v14 + v17) + v18;
  v21 = localWorld->v2.y * localWorld->v2.y;
  v22 = localWorld->v2.z * localWorld->v2.z;
  v23 = (float)((float)(v15 + v19) + (float)(v9 * localWorld->v2.z)) + localWorld->v3.z;
  pos.y = v20 + localWorld->v3.y;
  v11.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + v21) + v22;
  pos.z = v23;
  ((void (__cdecl *)(UFG::RegionBox *, UFG::qVector3 *))v4->GetRadius)(this, rayPos);
  v24 = v21 * COERCE_FLOAT(_mm_sqrt_ps(v11));
  if ( UFG::qDistanceSqrRayPoint(v8, v7, &pos) > (float)(v24 * v24) )
    return 0;
  UFG::qInverse(&d, v6);
  v26 = v8->x;
  v27 = v8->y;
  v28 = v8->z;
  v29 = v7->x;
  v30 = d.v0.y * v8->x;
  v42 = (float)((float)((float)(d.v1.x * v27) + (float)(d.v0.x * v8->x)) + (float)(d.v2.x * v28)) + d.v3.x;
  v31 = (float)(d.v1.y * v27) + v30;
  v32 = d.v0.z * v26;
  v33 = d.v2.z * v28;
  v34 = (float)(v31 + (float)(d.v2.y * v28)) + d.v3.y;
  v35 = v7->y;
  v36 = v7->z;
  pos.x = (float)((float)(v29 * d.v0.x) + (float)(v35 * d.v1.x)) + (float)(v36 * d.v2.x);
  rayPosa.x = v42;
  rayPosa.y = v34;
  rayPosa.z = (float)((float)((float)(d.v1.z * v27) + v32) + v33) + d.v3.z;
  pos.y = (float)((float)(v29 * d.v0.y) + (float)(v35 * d.v1.y)) + (float)(v36 * d.v2.y);
  pos.z = (float)((float)(v29 * d.v0.z) + (float)(v35 * d.v1.z)) + (float)(v36 * d.v2.z);
  result = UFG::qBox::IsHitRay(v5, &rayPosa, &pos, 0i64, *(UFG::qVector3 **)&pos.x);
  if ( v43 )
  {
    v37 = (float)((float)((float)(v43->y * v6->v1.y) + (float)(v43->x * v6->v0.y)) + (float)(v43->z * v6->v2.y))
        + v6->v3.y;
    v38 = (float)((float)((float)(v43->y * v6->v1.z) + (float)(v43->x * v6->v0.z)) + (float)(v43->z * v6->v2.z))
        + v6->v3.z;
    v43->x = (float)((float)((float)(v43->y * v6->v1.x) + (float)(v43->x * v6->v0.x)) + (float)(v43->z * v6->v2.x))
           + v6->v3.x;
    v43->y = v37;
    v43->z = v38;
  }
  return result;
}

// File Line: 723
// RVA: 0x23F7E0
char __fastcall UFG::RegionBox::IsHitPlaneRay(UFG::RegionBox *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qVector3 *pHitPos)
{
  return UFG::qBox::IsHitFaceBottomRay(&this->mBox, rayPos, rayDir, pHitPos);
}

// File Line: 745
// RVA: 0x23FA60
char __fastcall UFG::RegionBox::IsHitPlaneRayWS(UFG::RegionBox *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qMatrix44 *localWorld)
{
  UFG::qBox *v4; // r14
  UFG::qVector3 *v5; // rdi
  UFG::qVector3 *v6; // rsi
  UFG::qMatrix44 *v7; // rbx
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  __m128 v20; // xmm1
  float v21; // xmm3_4
  float v22; // xmm7_4
  __m128 v23; // xmm4
  float v24; // xmm7_4
  float v25; // xmm6_4
  char result; // al
  float v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  __int128 v30; // xmm6
  float v31; // xmm0_4
  float v32; // xmm5_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm5_4
  __int128 v36; // xmm3
  float v37; // xmm4_4
  float v38; // xmm2_4
  float v39; // xmm6_4
  UFG::qVector3 pos; // [rsp+10h] [rbp-59h]
  UFG::qVector3 rayPosa; // [rsp+20h] [rbp-49h]
  UFG::qMatrix44 d; // [rsp+38h] [rbp-31h]
  float v43; // [rsp+C8h] [rbp+5Fh]
  UFG::qVector3 *v44; // [rsp+E8h] [rbp+7Fh]

  v4 = &this->mBox;
  v5 = rayDir;
  v6 = rayPos;
  v7 = localWorld;
  v8 = (float)(this->mBox.mMin.z + this->mBox.mMax.z) * 0.5;
  v9 = (float)(this->mBox.mMin.x + this->mBox.mMax.x) * 0.5;
  v10 = localWorld->v2.x;
  v11 = this->mBox.mMin.y + this->mBox.mMax.y;
  v12 = v11 * 0.5;
  v13 = (float)(v11 * 0.5) * localWorld->v1.z;
  v14 = (float)((float)(v9 * localWorld->v0.x) + (float)(v12 * localWorld->v1.x)) + (float)(localWorld->v2.x * v8);
  v15 = v9 * localWorld->v0.y;
  v16 = v9 * localWorld->v0.z;
  v17 = (float)(v12 * localWorld->v1.y) + v15;
  v18 = localWorld->v2.z;
  pos.x = v14 + localWorld->v3.x;
  v19 = v17 + (float)(v8 * localWorld->v2.y);
  v20 = (__m128)LODWORD(localWorld->v2.y);
  v21 = (float)(this->mBox.mMax.x - this->mBox.mMin.x) * (float)(this->mBox.mMax.x - this->mBox.mMin.x);
  v22 = (float)(v13 + v16) + (float)(v8 * localWorld->v2.z);
  v23 = (__m128)LODWORD(this->mBox.mMax.y);
  pos.y = v19 + localWorld->v3.y;
  v24 = v22 + localWorld->v3.z;
  v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v10 * v10)) + (float)(v18 * v18);
  v23.m128_f32[0] = (float)((float)((float)(v23.m128_f32[0] - v4->mMin.y) * (float)(v23.m128_f32[0] - v4->mMin.y)) + v21)
                  + (float)((float)(v4->mMax.z - v4->mMin.z) * (float)(v4->mMax.z - v4->mMin.z));
  v25 = COERCE_FLOAT(_mm_sqrt_ps(v20)) * (float)(COERCE_FLOAT(_mm_sqrt_ps(v23)) * 0.5);
  if ( UFG::qDistanceSqrRayPoint(rayPos, rayDir, (UFG::qVector3 *)((char *)&rayPosa + 8)) > (float)(v25 * v25) )
    return 0;
  UFG::qInverse(&d, v7);
  v27 = v6->x;
  v28 = v6->y;
  v29 = v6->z;
  v30 = LODWORD(v5->x);
  v31 = d.v0.y * v6->x;
  v43 = (float)((float)((float)(d.v1.x * v28) + (float)(d.v0.x * v6->x)) + (float)(d.v2.x * v29)) + d.v3.x;
  v32 = (float)(d.v1.y * v28) + v31;
  v33 = d.v0.z * v27;
  v34 = d.v2.z * v29;
  v35 = (float)(v32 + (float)(d.v2.y * v29)) + d.v3.y;
  v36 = LODWORD(v5->y);
  v37 = v5->z;
  rayPosa.x = v43;
  rayPosa.y = v35;
  rayPosa.z = (float)((float)((float)(d.v1.z * v28) + v33) + v34) + d.v3.z;
  result = UFG::qBox::IsHitFaceBottomRay(v4, &rayPosa, &pos, v44);
  if ( v44 )
  {
    v38 = (float)((float)((float)(v44->y * v7->v1.y) + (float)(v44->x * v7->v0.y)) + (float)(v44->z * v7->v2.y))
        + v7->v3.y;
    v39 = (float)((float)((float)(v44->y * v7->v1.z) + (float)(v44->x * v7->v0.z)) + (float)(v44->z * v7->v2.z))
        + v7->v3.z;
    v44->x = (float)((float)((float)(v44->y * v7->v1.x) + (float)(v44->x * v7->v0.x)) + (float)(v44->z * v7->v2.x))
           + v7->v3.x;
    v44->y = v38;
    v44->z = v39;
  }
  return result;
}

// File Line: 851
// RVA: 0x23A300
UFG::allocator::free_link *__fastcall UFG::RegionDisc::Clone(UFG::RegionDisc *this)
{
  UFG::RegionDisc *v1; // rbx
  UFG::allocator::free_link *result; // rax

  v1 = this;
  result = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
  if ( !result )
    return 0i64;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable';
  LODWORD(result[1].mNext) = 0;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionDisc::`vftable';
  *(float *)&result[2].mNext = v1->mRadius;
  HIDWORD(result[2].mNext) = LODWORD(v1->mExtentAbove);
  *(float *)&result[3].mNext = v1->mExtentBelow;
  return result;
}

// File Line: 858
// RVA: 0x23D120
void __fastcall UFG::RegionDisc::GetBoundingBox(UFG::RegionDisc *this, UFG::qBox *pBox)
{
  int v2; // xmm0_4
  float v3; // xmm0_4

  v2 = LODWORD(this->mRadius) ^ _xmm[0];
  pBox->mMin.z = this->mExtentBelow;
  LODWORD(pBox->mMin.x) = v2;
  LODWORD(pBox->mMin.y) = v2;
  v3 = this->mRadius;
  pBox->mMax.z = this->mExtentAbove;
  pBox->mMax.x = v3;
  pBox->mMax.y = v3;
}

// File Line: 868
// RVA: 0x23D370
void __fastcall UFG::AIInterestComponent::GetAngularVelocity(UFG::AIInterestComponent *this, UFG::qVector3 *outAngVel)
{
  float v2; // xmm1_4
  float v3; // xmm2_4

  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  outAngVel->x = UFG::qVector3::msZero.x;
  outAngVel->y = v2;
  outAngVel->z = v3;
}

// File Line: 878
// RVA: 0x23DC70
UFG::qVector3 *__fastcall UFG::RegionDisc::GetRandomPosition(UFG::RegionDisc *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rdi
  UFG::RegionDisc *v3; // rbx
  float v4; // xmm7_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm7_4
  __m128 v8; // xmm4
  float v9; // xmm6_4
  __m128 v10; // xmm3
  float v11; // xmm5_4
  float v12; // xmm0_4
  UFG::qVector3 *v13; // rax

  v2 = result;
  v3 = this;
  v4 = UFG::qRandom(360.0, &UFG::qDefaultSeed);
  v5 = UFG::qRandom(360.0, &UFG::qDefaultSeed);
  UFG::qSphericalToCartesian(v2, v4, v5);
  v2->z = 0.0;
  v6 = UFG::qRandom(v3->mRadius, &UFG::qDefaultSeed);
  v7 = v2->y;
  v8 = (__m128)LODWORD(v2->x);
  v9 = v2->z;
  v10 = v8;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  v11 = v6 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v2->x = v8.m128_f32[0] * v11;
  v2->y = v7 * v11;
  v2->z = v9 * v11;
  v12 = UFG::qRandom(v3->mExtentAbove - v3->mExtentBelow, &UFG::qDefaultSeed);
  v13 = v2;
  v2->z = v12 + v3->mExtentBelow;
  return v13;
}

// File Line: 917
// RVA: 0x240570
bool __fastcall UFG::RegionDisc::IsHitPoint(UFG::RegionDisc *this, UFG::qVector3 *pos)
{
  float v2; // xmm0_4

  v2 = pos->z;
  return v2 >= this->mExtentBelow
      && v2 <= this->mExtentAbove
      && (float)((float)(pos->x * pos->x) + (float)(pos->y * pos->y)) <= (float)(this->mRadius * this->mRadius);
}

// File Line: 930
// RVA: 0x2408C0
bool __fastcall UFG::RegionDisc::IsHitPointWS(UFG::RegionDisc *this, UFG::qVector3 *pos, UFG::qMatrix44 *localWorld)
{
  float v3; // xmm4_4
  float v4; // xmm1_4
  bool result; // al

  v3 = pos->z;
  result = 0;
  if ( (float)(localWorld->v3.z + this->mExtentBelow) <= v3 && v3 <= (float)(localWorld->v3.z + this->mExtentAbove) )
  {
    v4 = pos->y - localWorld->v3.y;
    if ( (float)((float)(v4 * v4) + (float)((float)(pos->x - localWorld->v3.x) * (float)(pos->x - localWorld->v3.x))) <= (float)(this->mRadius * this->mRadius) )
      result = 1;
  }
  return result;
}

// File Line: 957
// RVA: 0x241EE0
char __fastcall UFG::RegionDisc::IsHitSegment(UFG::RegionDisc *this, UFG::qVector3 *start, UFG::qVector3 *end, UFG::qVector3 *pHitPos)
{
  UFG::qVector3 *v4; // rsi
  UFG::qVector3 *v5; // rbp
  UFG::RegionDisc *v6; // rbx
  UFG::qVector3 *v7; // rdi
  float v8; // xmm5_4
  float v9; // xmm4_4
  UFG::qVector2 enda; // [rsp+40h] [rbp-38h]
  UFG::qVector2 starta; // [rsp+50h] [rbp-28h]
  float pPDist; // [rsp+80h] [rbp+8h]

  v4 = end;
  v5 = start;
  v6 = this;
  v7 = pHitPos;
  if ( !(unsigned int)UFG::qIntersectSegSlab(
                        start,
                        end,
                        &UFG::qVector3::msDirUp,
                        this->mExtentBelow,
                        this->mExtentAbove,
                        (UFG::qVector3 *)&starta,
                        (UFG::qVector3 *)&enda)
    || !UFG::qIntersectSegCircleOrigin(&starta, &enda, v6->mRadius, &pPDist) )
  {
    return 0;
  }
  if ( v7 )
  {
    v8 = v5->y + (float)((float)(v4->y - v5->y) * pPDist);
    v9 = v5->z + (float)((float)(v4->z - v5->z) * pPDist);
    v7->x = v5->x + (float)((float)(v4->x - v5->x) * pPDist);
    v7->y = v8;
    v7->z = v9;
  }
  return 1;
}

// File Line: 996
// RVA: 0x242740
char __fastcall UFG::RegionDisc::IsHitSegmentWS(UFG::RegionDisc *this, UFG::qVector3 *start, UFG::qVector3 *end, UFG::qMatrix44 *localWorld, UFG::qVector3 *pHitPos)
{
  float v5; // xmm3_4
  UFG::RegionDisc *v6; // rbx
  UFG::qMatrix44 *v7; // rdi
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  UFG::qVector3 *v13; // rcx
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  UFG::qVector2 enda; // [rsp+30h] [rbp-78h]
  float v23; // [rsp+38h] [rbp-70h]
  UFG::qVector3 hit_enter_p; // [rsp+40h] [rbp-68h]
  UFG::qVector3 ray_dir; // [rsp+50h] [rbp-58h]
  UFG::qVector3 ray_pos; // [rsp+5Ch] [rbp-4Ch]
  float pPDist; // [rsp+B0h] [rbp+8h]

  v5 = this->mExtentAbove;
  v6 = this;
  v7 = localWorld;
  v8 = start->x - localWorld->v3.x;
  v9 = this->mExtentBelow;
  ray_dir.x = end->x - localWorld->v3.x;
  v10 = end->y;
  ray_pos.x = v8;
  v11 = start->z - localWorld->v3.z;
  ray_dir.y = v10 - localWorld->v3.y;
  v12 = end->z - localWorld->v3.z;
  ray_pos.z = v11;
  ray_dir.z = v12;
  ray_pos.y = start->y - localWorld->v3.y;
  if ( !(unsigned int)UFG::qIntersectRaySlabZ(&ray_pos, &ray_dir, v9, v5, &hit_enter_p, (UFG::qVector3 *)&enda)
    || !UFG::qIntersectSegCircleOrigin((UFG::qVector2 *)&hit_enter_p, &enda, v6->mRadius, &pPDist) )
  {
    return 0;
  }
  v13 = pHitPos;
  if ( pHitPos )
  {
    v14 = pPDist;
    v15 = hit_enter_p.x;
    v16 = v7->v3.y;
    v17 = v7->v3.z;
    v18 = v23;
    pHitPos->x = v7->v3.x;
    v19 = (float)(v15 + v13->x) + (float)((float)(enda.x - v15) * v14);
    v20 = (float)(hit_enter_p.y + v16) + (float)((float)(enda.y - hit_enter_p.y) * v14);
    v13->z = (float)(hit_enter_p.z + v17) + (float)((float)(v18 - hit_enter_p.z) * v14);
    v13->x = v19;
    v13->y = v20;
  }
  return 1;
}

// File Line: 1037
// RVA: 0x240C30
char __fastcall UFG::RegionDisc::IsHitRay(UFG::RegionDisc *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qVector3 *pHitPos)
{
  UFG::RegionDisc *v4; // rbx
  UFG::qVector3 *v5; // rdi
  float v6; // xmm4_4
  float v7; // xmm6_4
  UFG::qVector3 hit_exit_p; // [rsp+30h] [rbp-38h]
  UFG::qVector3 hit_enter_p; // [rsp+40h] [rbp-28h]
  float pPDist; // [rsp+70h] [rbp+8h]

  v4 = this;
  v5 = pHitPos;
  if ( !(unsigned int)UFG::qIntersectRaySlabZ(
                        rayPos,
                        rayDir,
                        this->mExtentBelow,
                        this->mExtentAbove,
                        &hit_enter_p,
                        &hit_exit_p)
    || !UFG::qIntersectSegCircleOrigin(
          (UFG::qVector2 *)&hit_enter_p,
          (UFG::qVector2 *)&hit_exit_p,
          v4->mRadius,
          &pPDist) )
  {
    return 0;
  }
  if ( v5 )
  {
    v6 = (float)((float)(hit_exit_p.z - hit_enter_p.z) * pPDist) + hit_enter_p.z;
    v7 = (float)((float)(hit_exit_p.x - hit_enter_p.x) * pPDist) + hit_enter_p.x;
    v5->y = (float)((float)(hit_exit_p.y - hit_enter_p.y) * pPDist) + hit_enter_p.y;
    v5->z = v6;
    v5->x = v7;
  }
  return 1;
}

// File Line: 1075
// RVA: 0x241320
char __fastcall UFG::RegionDisc::IsHitRayWS(UFG::RegionDisc *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qMatrix44 *localWorld, UFG::qVector3 *pHitPos)
{
  float v5; // xmm3_4
  UFG::RegionDisc *v6; // rbx
  UFG::qMatrix44 *v7; // rdi
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  UFG::qVector3 *v11; // rcx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm6_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  UFG::qVector3 hit_exit_p; // [rsp+30h] [rbp-68h]
  UFG::qVector3 hit_enter_p; // [rsp+40h] [rbp-58h]
  UFG::qVector3 ray_pos; // [rsp+50h] [rbp-48h]
  float pPDist; // [rsp+A0h] [rbp+8h]

  v5 = this->mExtentAbove;
  v6 = this;
  v7 = localWorld;
  v8 = rayPos->y - localWorld->v3.y;
  v9 = this->mExtentBelow;
  ray_pos.x = rayPos->x - localWorld->v3.x;
  v10 = rayPos->z;
  ray_pos.y = v8;
  ray_pos.z = v10 - localWorld->v3.z;
  if ( !(unsigned int)UFG::qIntersectRaySlabZ(&ray_pos, rayDir, v9, v5, &hit_enter_p, &hit_exit_p)
    || !UFG::qIntersectSegCircleOrigin(
          (UFG::qVector2 *)&hit_enter_p,
          (UFG::qVector2 *)&hit_exit_p,
          v6->mRadius,
          &pPDist) )
  {
    return 0;
  }
  v11 = pHitPos;
  if ( pHitPos )
  {
    v12 = pPDist;
    v13 = hit_enter_p.x;
    v14 = v7->v3.y;
    v15 = v7->v3.z;
    v16 = hit_exit_p.z;
    pHitPos->x = v7->v3.x;
    v17 = (float)(v13 + v11->x) + (float)((float)(hit_exit_p.x - v13) * v12);
    v18 = (float)(hit_enter_p.y + v14) + (float)((float)(hit_exit_p.y - hit_enter_p.y) * v12);
    v11->z = (float)(hit_enter_p.z + v15) + (float)((float)(v16 - hit_enter_p.z) * v12);
    v11->x = v17;
    v11->y = v18;
  }
  return 1;
}

// File Line: 1116
// RVA: 0x23F7F0
char __fastcall UFG::RegionDisc::IsHitPlaneRay(UFG::RegionDisc *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qVector3 *pHitPos)
{
  UFG::qVector3 *v4; // rbx
  float v5; // xmm6_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  UFG::qVector3 hit_pos_p; // [rsp+30h] [rbp-28h]

  v4 = pHitPos;
  v5 = this->mRadius;
  if ( !UFG::qIntersectRayPlane(rayPos, rayDir, &UFG::qVector3::msDirUp, &UFG::qVector3::msZero, &hit_pos_p) )
    return 0;
  v6 = hit_pos_p.y;
  v7 = hit_pos_p.z;
  if ( (float)((float)((float)((float)(UFG::qVector3::msZero.y - hit_pos_p.y)
                             * (float)(UFG::qVector3::msZero.y - hit_pos_p.y))
                     + (float)((float)(UFG::qVector3::msZero.x - hit_pos_p.x)
                             * (float)(UFG::qVector3::msZero.x - hit_pos_p.x)))
             + (float)((float)(UFG::qVector3::msZero.z - hit_pos_p.z) * (float)(UFG::qVector3::msZero.z - hit_pos_p.z))) > (float)(v5 * v5) )
    return 0;
  if ( v4 )
  {
    v4->x = hit_pos_p.x;
    v4->y = v6;
    v4->z = v7;
  }
  return 1;
}

// File Line: 1139
// RVA: 0x23FDE0
char __fastcall UFG::RegionDisc::IsHitPlaneRayWS(UFG::RegionDisc *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qMatrix44 *localWorld, UFG::qVector3 *pHitPos)
{
  float *v5; // rbx
  float v6; // xmm6_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  UFG::qVector3 hit_pos_p; // [rsp+30h] [rbp-28h]

  v5 = &localWorld->v3.x;
  v6 = this->mRadius;
  if ( !UFG::qIntersectRayPlane(rayPos, rayDir, &UFG::qVector3::msDirUp, (UFG::qVector3 *)&localWorld->v3, &hit_pos_p) )
    return 0;
  v7 = hit_pos_p.y;
  v8 = hit_pos_p.z;
  if ( (float)((float)((float)((float)(*v5 - hit_pos_p.x) * (float)(*v5 - hit_pos_p.x))
                     + (float)((float)(v5[1] - hit_pos_p.y) * (float)(v5[1] - hit_pos_p.y)))
             + (float)((float)(v5[2] - hit_pos_p.z) * (float)(v5[2] - hit_pos_p.z))) > (float)(v6 * v6) )
    return 0;
  if ( pHitPos )
  {
    pHitPos->x = hit_pos_p.x;
    pHitPos->y = v7;
    pHitPos->z = v8;
  }
  return 1;
}

// File Line: 1160
// RVA: 0x23A7B0
signed __int64 __fastcall UFG::RegionDisc::CycleAspect(UFG::RegionDisc *this, unsigned int aspect, bool forward)
{
  unsigned int v3; // edx
  signed __int64 result; // rax

  if ( forward )
  {
    v3 = aspect + 1;
    if ( v3 > 2 )
      v3 = 0;
    result = v3;
  }
  else
  {
    result = 2i64;
    if ( aspect )
      result = aspect - 1;
  }
  return result;
}

// File Line: 1187
// RVA: 0x23C2F0
UFG::qVector3 *__fastcall UFG::RegionDisc::GetAspectCenter(UFG::RegionDisc *this, UFG::qVector3 *result, unsigned int aspect)
{
  UFG::qVector3 *v3; // rax
  unsigned int v4; // er8
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  v3 = result;
  v4 = aspect - 1;
  if ( v4 )
  {
    if ( v4 != 1 )
    {
      v5 = this->mRadius;
      v6 = UFG::qVector3::msDirFront.y * v5;
      result->x = UFG::qVector3::msDirFront.x * v5;
      v7 = UFG::qVector3::msDirFront.z;
      result->y = v6;
      result->z = v7 * v5;
      return v3;
    }
    v8 = this->mExtentBelow;
  }
  else
  {
    v8 = this->mExtentAbove;
  }
  v9 = UFG::qVector3::msDirUp.y * v8;
  result->x = UFG::qVector3::msDirUp.x * v8;
  v10 = UFG::qVector3::msDirUp.z;
  result->y = v9;
  result->z = v10 * v8;
  return v3;
}

// File Line: 1207
// RVA: 0x23C620
UFG::qVector3 *__fastcall UFG::RegionDisc::GetAspectNormal(UFG::RegionDisc *this, UFG::qVector3 *result, unsigned int aspect)
{
  UFG::qVector3 *v3; // rax
  unsigned int v4; // er8
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4

  v3 = result;
  v4 = aspect - 1;
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v5 = UFG::qVector3::msDirDown.y;
      result->x = UFG::qVector3::msDirDown.x;
      v6 = UFG::qVector3::msDirDown.z;
    }
    else
    {
      v5 = UFG::qVector3::msDirFront.y;
      result->x = UFG::qVector3::msDirFront.x;
      v6 = UFG::qVector3::msDirFront.z;
    }
    result->y = v5;
    result->z = v6;
  }
  else
  {
    v7 = UFG::qVector3::msDirUp.y;
    result->x = UFG::qVector3::msDirUp.x;
    v8 = UFG::qVector3::msDirUp.z;
    result->y = v7;
    result->z = v8;
  }
  return v3;
}

// File Line: 1233
// RVA: 0x23F600
char __fastcall UFG::RegionDisc::IsHitAspect(UFG::RegionDisc *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, unsigned int *pHitAspect)
{
  UFG::RegionBaseVtbl *v4; // rax
  unsigned int *v5; // rdi
  UFG::RegionDisc *v6; // rbx
  char result; // al
  float v8; // xmm0_4
  unsigned int v9; // eax
  char v10; // cl
  char v11; // [rsp+20h] [rbp-18h]
  float v12; // [rsp+28h] [rbp-10h]

  v4 = this->vfptr;
  v5 = pHitAspect;
  v6 = this;
  if ( !pHitAspect )
    return ((__int64 (__fastcall *)(UFG::RegionDisc *, UFG::qVector3 *, UFG::qVector3 *))v4->IsHitRay)(
             this,
             rayPos,
             rayDir);
  if ( !v4->IsHitRay((UFG::RegionBase *)&this->vfptr, rayPos, rayDir, (UFG::qVector3 *)&v11) )
    return 0;
  v8 = v6->mExtentBelow;
  if ( v8 > v12 || v12 > (float)(v8 * 0.5) )
  {
    v9 = 0;
    if ( (float)(v6->mExtentAbove * 0.5) > v12 || (v10 = 1, v12 > v6->mExtentAbove) )
      v10 = 0;
    LOBYTE(v9) = v10 != 0;
    *v5 = v9;
    result = 1;
  }
  else
  {
    result = 1;
    *v5 = 2;
  }
  return result;
}

// File Line: 1265
// RVA: 0x246210
void __fastcall UFG::RegionDisc::TranslateAspect(UFG::RegionDisc *this, unsigned int aspect, UFG::qVector3 *delta)
{
  unsigned int v3; // edx
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  __m128 v7; // xmm3
  float v8; // xmm0_4

  if ( aspect )
  {
    v3 = aspect - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        v4 = delta->z + this->mExtentBelow;
        if ( v4 >= 0.0 )
          v4 = 0.0;
        this->mExtentBelow = v4;
      }
    }
    else
    {
      v5 = delta->z + this->mExtentAbove;
      if ( v5 <= 0.0 )
        v5 = 0.0;
      this->mExtentAbove = v5;
    }
  }
  else
  {
    v6 = this->mRadius;
    v7 = (__m128)LODWORD(UFG::qVector3::msDirFront.y);
    v7.m128_f32[0] = (float)((float)((float)((float)(UFG::qVector3::msDirFront.y * v6) + delta->y)
                                   * (float)((float)(UFG::qVector3::msDirFront.y * v6) + delta->y))
                           + (float)((float)((float)(UFG::qVector3::msDirFront.x * v6) + delta->x)
                                   * (float)((float)(UFG::qVector3::msDirFront.x * v6) + delta->x)))
                   + (float)((float)((float)(UFG::qVector3::msDirFront.z * v6) + delta->z)
                           * (float)((float)(UFG::qVector3::msDirFront.z * v6) + delta->z));
    LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v7);
    if ( v8 <= 0.0 )
      v8 = 0.0;
    this->mRadius = v8;
  }
}

