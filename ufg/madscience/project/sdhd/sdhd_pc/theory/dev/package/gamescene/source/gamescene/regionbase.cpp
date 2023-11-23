// File Line: 86
// RVA: 0x23D3E0
UFG::qVector3 *__fastcall UFG::RegionBase::GetClosestPointOutside(
        UFG::RegionBase *this,
        UFG::qVector3 *result,
        UFG::qVector3 *pos)
{
  *result = *pos;
  return result;
}

// File Line: 121
// RVA: 0x23A3C0
UFG::allocator::free_link *__fastcall UFG::RegionSphere::Clone(UFG::RegionSphere *this)
{
  UFG::allocator::free_link *result; // rax

  result = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
  if ( !result )
    return 0i64;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable;
  LODWORD(result[1].mNext) = 0;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionSphere::`vftable;
  *(float *)&result[2].mNext = this->mRadius;
  return result;
}

// File Line: 128
// RVA: 0x23D1A0
void __fastcall UFG::RegionSphere::GetBoundingBox(UFG::RegionSphere *this, UFG::qBox *pBox)
{
  int v2; // xmm0_4
  float mRadius; // xmm0_4

  v2 = LODWORD(this->mRadius) ^ _xmm[0];
  LODWORD(pBox->mMin.x) = v2;
  LODWORD(pBox->mMin.y) = v2;
  LODWORD(pBox->mMin.z) = v2;
  mRadius = this->mRadius;
  pBox->mMax.x = mRadius;
  pBox->mMax.y = mRadius;
  pBox->mMax.z = mRadius;
}

// File Line: 149
// RVA: 0x23DE60
UFG::qVector3 *__fastcall UFG::RegionSphere::GetRandomPosition(UFG::RegionSphere *this, UFG::qVector3 *result)
{
  float v4; // xmm7_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  UFG::qVector3 *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm2_4

  v4 = UFG::qRandom(360.0, (unsigned int *)&UFG::qDefaultSeed);
  v5 = UFG::qRandom(360.0, (unsigned int *)&UFG::qDefaultSeed);
  UFG::qSphericalToCartesian(result, v4, v5);
  v6 = UFG::qRandom(this->mRadius, (unsigned int *)&UFG::qDefaultSeed);
  v7 = result;
  v8 = v6 * result->x;
  v9 = v6 * result->y;
  result->z = v6 * result->z;
  result->x = v8;
  result->y = v9;
  return v7;
}

// File Line: 172
// RVA: 0x23E1F0
__int64 __fastcall CAkMatrixAwareCtx::SeekPercent(hkpCapsuleShape *this)
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
bool __fastcall UFG::RegionSphere::IsHitPointWS(
        UFG::RegionSphere *this,
        UFG::qVector3 *pos,
        UFG::qMatrix44 *localWorld)
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
bool __fastcall UFG::RegionSphere::IsHitSegment(
        UFG::RegionSphere *this,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qVector3 *pHitPos)
{
  float mRadius; // xmm6_4
  UFG::qVector3 *v6; // rax
  bool v7; // al
  char v8; // al
  float y; // xmm1_4
  float z; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  UFG::qVector3 entry_p; // [rsp+30h] [rbp-38h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-28h] BYREF

  if ( pHitPos )
  {
    v8 = UFG::qIntersectSegSphere(start, end, &UFG::qVector3::msZero, this->mRadius, &entry_p, &result);
    if ( (v8 & 1) != 0 )
    {
      y = entry_p.y;
      v7 = 1;
      pHitPos->x = entry_p.x;
      z = entry_p.z;
      pHitPos->y = y;
      pHitPos->z = z;
    }
    else if ( (v8 & 2) != 0 )
    {
      v11 = result.y;
      v7 = 1;
      pHitPos->x = result.x;
      v12 = result.z;
      pHitPos->y = v11;
      pHitPos->z = v12;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    mRadius = this->mRadius;
    v6 = UFG::qNearestSegPoint(&result, start, end, &UFG::qVector3::msZero);
    return (float)(mRadius * mRadius) >= (float)((float)((float)((float)(UFG::qVector3::msZero.y - v6->y)
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
bool __fastcall UFG::RegionSphere::IsHitSegmentWS(
        UFG::RegionSphere *this,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qMatrix44 *localWorld,
        UFG::qVector3 *pHitPos)
{
  __m128 x_low; // xmm2
  float v7; // xmm0_4
  float v8; // xmm1_4
  float y; // xmm6_4
  float x; // xmm8_4
  float z; // xmm9_4
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
  UFG::qVector3 pos; // [rsp+30h] [rbp-98h] BYREF
  UFG::qVector3 entry_p; // [rsp+40h] [rbp-88h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-78h] BYREF
  UFG::qVector4 row_vec4; // [rsp+60h] [rbp-68h] BYREF
  UFG::qVector4 v33; // [rsp+70h] [rbp-58h] BYREF

  x_low = (__m128)LODWORD(localWorld->v2.x);
  v7 = localWorld->v2.y * localWorld->v2.y;
  v8 = localWorld->v2.z * localWorld->v2.z;
  y = localWorld->v3.y;
  x = localWorld->v3.x;
  z = localWorld->v3.z;
  pos.x = x;
  pos.y = y;
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + v7) + v8;
  pos.z = z;
  v12 = _mm_sqrt_ps(x_low).m128_f32[0] * this->mRadius;
  if ( pHitPos )
  {
    v15 = UFG::qIntersectSegSphere(start, end, &pos, v12, &entry_p, &result);
    if ( (v15 & 1) != 0 )
    {
      v16 = entry_p.x;
      v17 = entry_p.y;
      v18 = entry_p.z;
      v14 = 1;
      v19 = entry_p.y;
      pHitPos->y = entry_p.y;
      pHitPos->x = v16;
      pHitPos->z = v18;
      v20 = (float)((float)((float)(v17 * localWorld->v1.x) + (float)(v16 * localWorld->v0.x))
                  + (float)(v18 * localWorld->v2.x))
          + localWorld->v3.x;
      v21 = (float)((float)((float)(v17 * localWorld->v1.z) + (float)(v16 * localWorld->v0.z))
                  + (float)(v18 * localWorld->v2.z))
          + localWorld->v3.z;
      pHitPos->y = (float)((float)((float)(v19 * localWorld->v1.y) + (float)(v16 * localWorld->v0.y))
                         + (float)(v18 * localWorld->v2.y))
                 + localWorld->v3.y;
      pHitPos->x = v20;
      pHitPos->z = v21;
    }
    else if ( (v15 & 2) != 0 )
    {
      v22 = result.z;
      v23 = result.x;
      v24 = result.y;
      pHitPos->z = result.z;
      row_vec4.z = v22;
      LODWORD(row_vec4.w) = (_DWORD)FLOAT_1_0;
      pHitPos->x = v23;
      pHitPos->y = v24;
      row_vec4.x = v23;
      row_vec4.y = v24;
      v25 = UFG::operator*(&v33, &row_vec4, localWorld);
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
      return 0;
    }
  }
  else
  {
    v13 = UFG::qNearestSegPoint(&result, start, end, &pos);
    return (float)(v12 * v12) >= (float)((float)((float)((float)(y - v13->y) * (float)(y - v13->y))
                                               + (float)((float)(x - v13->x) * (float)(x - v13->x)))
                                       + (float)((float)(z - v13->z) * (float)(z - v13->z)));
  }
  return v14;
}

// File Line: 329
// RVA: 0x240F60
char __fastcall UFG::RegionSphere::IsHitRay(
        UFG::RegionSphere *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qVector3 *pHitPos)
{
  UFG::qVector3 *exit_p; // rax
  int v6; // eax
  float v7; // xmm1_4
  float v8; // xmm0_4
  int v10[6]; // [rsp+30h] [rbp-18h] BYREF

  exit_p = (UFG::qVector3 *)v10;
  if ( !pHitPos )
    exit_p = 0i64;
  v6 = UFG::qIntersectRaySphere(rayPos, rayDir, &UFG::qVector3::msZero, this->mRadius, pHitPos, exit_p);
  if ( v6 == 3 )
    return 1;
  if ( v6 == 2 )
  {
    v7 = *(float *)&v10[1];
    LODWORD(pHitPos->x) = v10[0];
    v8 = *(float *)&v10[2];
    pHitPos->y = v7;
    pHitPos->z = v8;
    return 1;
  }
  return 0;
}

// File Line: 366
// RVA: 0x241880
char __fastcall UFG::RegionSphere::IsHitRayWS(
        UFG::RegionSphere *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qMatrix44 *localWorld,
        UFG::qVector3 *pHitPos)
{
  float y; // xmm1_4
  __m128 x_low; // xmm2
  UFG::qVector3 *exit_p; // rax
  float z; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  int v12; // eax
  float v13; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm6_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  UFG::qVector3 origin; // [rsp+30h] [rbp-38h] BYREF
  int v22[4]; // [rsp+40h] [rbp-28h] BYREF

  y = localWorld->v3.y;
  x_low = (__m128)LODWORD(localWorld->v2.x);
  exit_p = (UFG::qVector3 *)v22;
  origin.x = localWorld->v3.x;
  z = localWorld->v3.z;
  origin.y = y;
  v10 = localWorld->v2.y;
  origin.z = z;
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v10 * v10))
                    + (float)(localWorld->v2.z * localWorld->v2.z);
  v11 = _mm_sqrt_ps(x_low).m128_f32[0] * this->mRadius;
  if ( !pHitPos )
    exit_p = 0i64;
  v12 = UFG::qIntersectRaySphere(rayPos, rayDir, &origin, v11, pHitPos, exit_p);
  if ( pHitPos )
  {
    v13 = pHitPos->z;
    v14 = pHitPos->y;
    v15 = v14 * localWorld->v1.z;
    v16 = (float)((float)((float)(v14 * localWorld->v1.x) + (float)(pHitPos->x * localWorld->v0.x))
                + (float)(v13 * localWorld->v2.x))
        + localWorld->v3.x;
    v17 = (float)((float)((float)(v14 * localWorld->v1.y) + (float)(pHitPos->x * localWorld->v0.y))
                + (float)(v13 * localWorld->v2.y))
        + localWorld->v3.y;
    pHitPos->z = (float)((float)(v15 + (float)(pHitPos->x * localWorld->v0.z)) + (float)(v13 * localWorld->v2.z))
               + localWorld->v3.z;
    pHitPos->x = v16;
    pHitPos->y = v17;
  }
  if ( v12 == 3 )
    return 1;
  if ( v12 == 2 )
  {
    v18 = *(float *)&v22[1];
    LODWORD(pHitPos->x) = v22[0];
    v19 = *(float *)&v22[2];
    pHitPos->y = v18;
    pHitPos->z = v19;
    return 1;
  }
  return 0;
}

// File Line: 411
// RVA: 0x23F980
char __fastcall UFG::RegionSphere::IsHitPlaneRay(
        UFG::RegionSphere *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qVector3 *pHitPos)
{
  float mRadius; // xmm7_4
  float y; // xmm5_4
  float z; // xmm6_4
  UFG::qVector3 plane_pos; // [rsp+30h] [rbp-48h] BYREF
  UFG::qVector3 hit_pos_p; // [rsp+40h] [rbp-38h] BYREF

  mRadius = this->mRadius;
  *(_QWORD *)&plane_pos.x = 0i64;
  plane_pos.z = 0.0;
  if ( !UFG::qIntersectRayPlane(rayPos, rayDir, &UFG::qVector3::msDirUp, &plane_pos, &hit_pos_p) )
    return 0;
  y = hit_pos_p.y;
  z = hit_pos_p.z;
  if ( (float)((float)((float)(COERCE_FLOAT(LODWORD(hit_pos_p.y) ^ _xmm[0])
                             * COERCE_FLOAT(LODWORD(hit_pos_p.y) ^ _xmm[0]))
                     + (float)(COERCE_FLOAT(LODWORD(hit_pos_p.x) ^ _xmm[0])
                             * COERCE_FLOAT(LODWORD(hit_pos_p.x) ^ _xmm[0])))
             + (float)(COERCE_FLOAT(LODWORD(hit_pos_p.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(hit_pos_p.z) ^ _xmm[0]))) > (float)(mRadius * mRadius) )
    return 0;
  if ( pHitPos )
  {
    pHitPos->x = hit_pos_p.x;
    pHitPos->y = y;
    pHitPos->z = z;
  }
  return 1;
}

// File Line: 432
// RVA: 0x240280
char __fastcall UFG::RegionSphere::IsHitPlaneRayWS(
        UFG::RegionSphere *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qMatrix44 *localWorld,
        UFG::qVector3 *pHitPos)
{
  __m128 x_low; // xmm2
  float v6; // xmm0_4
  float v7; // xmm1_4
  float x; // xmm7_4
  float y; // xmm6_4
  float z; // xmm8_4
  float v11; // xmm9_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::qVector3 v15; // [rsp+30h] [rbp-68h] BYREF
  UFG::qVector3 v16; // [rsp+40h] [rbp-58h] BYREF

  x_low = (__m128)LODWORD(localWorld->v2.x);
  v6 = localWorld->v2.y * localWorld->v2.y;
  v7 = localWorld->v2.z * localWorld->v2.z;
  x = localWorld->v3.x;
  y = localWorld->v3.y;
  z = localWorld->v3.z;
  v15.x = x;
  v15.y = y;
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + v6) + v7;
  v15.z = z;
  v11 = _mm_sqrt_ps(x_low).m128_f32[0] * this->mRadius;
  if ( !UFG::qIntersectRayPlane(rayPos, rayDir, &UFG::qVector3::msDirUp, &v15, &v16) )
    return 0;
  v12 = v16.y;
  v13 = v16.z;
  if ( (float)((float)((float)((float)(y - v16.y) * (float)(y - v16.y))
                     + (float)((float)(x - v16.x) * (float)(x - v16.x)))
             + (float)((float)(z - v16.z) * (float)(z - v16.z))) > (float)(v11 * v11) )
    return 0;
  if ( pHitPos )
  {
    pHitPos->x = v16.x;
    pHitPos->y = v12;
    pHitPos->z = v13;
  }
  return 1;
}

// File Line: 448
// RVA: 0x246430
void __fastcall UFG::RegionSphere::TranslateAspect(UFG::RegionSphere *this, unsigned int aspect, UFG::qVector3 *delta)
{
  UFG::qVector3 *v5; // rax
  __m128 x_low; // xmm0
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  char v10[24]; // [rsp+20h] [rbp-18h] BYREF

  v5 = this->vfptr->GetAspectCenter(this, v10, aspect);
  x_low = (__m128)LODWORD(v5->x);
  v7 = delta->y + v5->y;
  v8 = delta->z + v5->z;
  x_low.m128_f32[0] = x_low.m128_f32[0] + delta->x;
  v5->y = v7;
  v5->z = v8;
  LODWORD(v5->x) = x_low.m128_i32[0];
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v7 * v7)) + (float)(v8 * v8);
  v9 = _mm_sqrt_ps(x_low).m128_f32[0];
  this->mRadius = v9;
  if ( v9 < 0.0 )
    this->mRadius = 0.0;
}

// File Line: 503
// RVA: 0x23A270
UFG::allocator::free_link *__fastcall UFG::RegionBox::Clone(UFG::RegionBox *this)
{
  UFG::allocator::free_link *result; // rax
  float y; // xmm1_4
  int z_low; // xmm2_4
  float v5; // xmm1_4
  float z; // xmm2_4

  result = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  if ( !result )
    return 0i64;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable;
  LODWORD(result[1].mNext) = 0;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionBox::`vftable;
  y = this->mBox.mMin.y;
  z_low = LODWORD(this->mBox.mMin.z);
  *(float *)&result[2].mNext = this->mBox.mMin.x;
  *((float *)&result[2].mNext + 1) = y;
  LODWORD(result[3].mNext) = z_low;
  v5 = this->mBox.mMax.y;
  z = this->mBox.mMax.z;
  HIDWORD(result[3].mNext) = LODWORD(this->mBox.mMax.x);
  *(float *)&result[4].mNext = v5;
  *((float *)&result[4].mNext + 1) = z;
  return result;
}

// File Line: 512
// RVA: 0x23D1D0
void __fastcall UFG::RegionBox::GetCenter(UFG::RegionBox *this, UFG::qVector3 *pPos)
{
  float y; // xmm2_4
  float z; // xmm3_4
  float v4; // xmm3_4
  float v5; // xmm0_4

  y = this->mBox.mMin.y;
  z = this->mBox.mMin.z;
  pPos->x = this->mBox.mMin.x;
  pPos->y = y;
  pPos->z = z;
  v4 = (float)(z + this->mBox.mMax.z) * 0.5;
  v5 = this->mBox.mMax.x + pPos->x;
  pPos->y = (float)(y + this->mBox.mMax.y) * 0.5;
  pPos->z = v4;
  pPos->x = v5 * 0.5;
}

// File Line: 522
// RVA: 0x23DB10
UFG::qVector3 *__fastcall UFG::RegionBox::GetRandomPosition(UFG::RegionBox *this, UFG::qVector3 *result)
{
  UFG::qBox::GetRandomPosition(&this->mBox, result);
  return result;
}

// File Line: 544
// RVA: 0x23E2B0
void __fastcall UFG::RegionBox::GetVisualAnchor(UFG::RegionBox *this, UFG::qVector3 *vPos)
{
  float y; // xmm0_4
  float z; // xmm1_4

  y = this->mBox.mMax.y;
  z = this->mBox.mMax.z;
  vPos->x = this->mBox.mMax.x;
  vPos->y = y;
  vPos->z = z;
}

// File Line: 556
// RVA: 0x2403A0
bool __fastcall UFG::RegionBox::IsHitPoint(UFG::RegionBox *this, UFG::qVector3 *pos)
{
  float y; // xmm0_4
  float z; // xmm0_4
  bool result; // al

  result = 0;
  if ( pos->x >= this->mBox.mMin.x && pos->x <= this->mBox.mMax.x )
  {
    y = pos->y;
    if ( y >= this->mBox.mMin.y && y <= this->mBox.mMax.y )
    {
      z = pos->z;
      if ( z >= this->mBox.mMin.z && z <= this->mBox.mMax.z )
        return 1;
    }
  }
  return result;
}

// File Line: 568
// RVA: 0x240670
bool __fastcall UFG::RegionBox::IsHitPointWS(UFG::RegionBox *this, UFG::qVector3 *pos, UFG::qMatrix44 *localWorld)
{
  __m128 x_low; // xmm3
  float v7; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm9_4
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm9_4
  float v13; // xmm6_4
  double v14; // xmm0_8
  __m128 y_low; // xmm3
  float y; // xmm2_4
  float z; // xmm4_4
  float v19; // xmm7_4
  float v20; // xmm6_4
  float v21; // xmm5_4
  UFG::qMatrix44 d; // [rsp+20h] [rbp-88h] BYREF

  x_low = (__m128)LODWORD(localWorld->v2.x);
  v7 = (float)(this->mBox.mMin.x + this->mBox.mMax.x) * 0.5;
  v8 = (float)(this->mBox.mMax.z + this->mBox.mMin.z) * 0.5;
  v9 = (float)(this->mBox.mMax.y + this->mBox.mMin.y) * 0.5;
  v10 = (float)((float)((float)(v9 * localWorld->v1.x) + (float)(v7 * localWorld->v0.x)) + (float)(localWorld->v2.x * v8))
      + localWorld->v3.x;
  v11 = (float)((float)((float)(v9 * localWorld->v1.y) + (float)(v7 * localWorld->v0.y)) + (float)(v8 * localWorld->v2.y))
      + localWorld->v3.y;
  v12 = (float)((float)((float)(v9 * localWorld->v1.z) + (float)(v7 * localWorld->v0.z)) + (float)(v8 * localWorld->v2.z))
      + localWorld->v3.z;
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                            + (float)(localWorld->v2.y * localWorld->v2.y))
                    + (float)(localWorld->v2.z * localWorld->v2.z);
  v13 = _mm_sqrt_ps(x_low).m128_f32[0];
  v14 = ((double (*)(void))this->vfptr->GetRadius)();
  y_low = (__m128)LODWORD(pos->y);
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v11) * (float)(y_low.m128_f32[0] - v11))
                            + (float)((float)(pos->x - v10) * (float)(pos->x - v10)))
                    + (float)((float)(pos->z - v12) * (float)(pos->z - v12));
  if ( _mm_sqrt_ps(y_low).m128_f32[0] > (float)(*(float *)&v14 * v13) )
    return 0;
  UFG::qInverse(&d, localWorld);
  y = pos->y;
  z = pos->z;
  v19 = (float)((float)((float)(d.v1.x * y) + (float)(d.v0.x * pos->x)) + (float)(d.v2.x * z)) + d.v3.x;
  v20 = (float)((float)((float)(d.v1.y * y) + (float)(d.v0.y * pos->x)) + (float)(d.v2.y * z)) + d.v3.y;
  v21 = (float)((float)((float)(d.v1.z * y) + (float)(d.v0.z * pos->x)) + (float)(d.v2.z * z)) + d.v3.z;
  return v19 >= this->mBox.mMin.x
      && v19 <= this->mBox.mMax.x
      && v20 >= this->mBox.mMin.y
      && v20 <= this->mBox.mMax.y
      && v21 >= this->mBox.mMin.z
      && v21 <= this->mBox.mMax.z;
}

// File Line: 601
// RVA: 0x2419F0
char __fastcall UFG::RegionBox::IsHitSegment(
        UFG::RegionBox *this,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qVector3 *pHitPos)
{
  return UFG::qBox::IsHitSeg(&this->mBox, start, end, 0i64, pHitPos);
}

// File Line: 622
// RVA: 0x242340
char __fastcall UFG::RegionBox::IsHitSegmentWS(
        UFG::RegionBox *this,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qMatrix44 *localWorld,
        UFG::qVector3 *pHitPos)
{
  __m128 x_low; // xmm4
  UFG::qBox *p_mBox; // r14
  UFG::RegionBaseVtbl *vfptr; // rax
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
  float y; // xmm0_4
  float v23; // xmm8_4
  float v24; // xmm1_4
  float v25; // xmm8_4
  float v26; // xmm10_4
  float v27; // xmm6_4
  double v28; // xmm0_8
  UFG::qVector3 *v29; // rax
  char IsHitSeg; // al
  float x; // xmm3_4
  float v32; // xmm2_4
  float z; // xmm4_4
  float v34; // xmm0_4
  float v35; // xmm13_4
  float v36; // xmm5_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm6_4
  UFG::qVector3 pos; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-A8h] BYREF
  UFG::qMatrix44 d; // [rsp+50h] [rbp-98h] BYREF
  float v45; // [rsp+118h] [rbp+30h]
  float v46; // [rsp+130h] [rbp+48h]
  UFG::qVector3 *v47; // [rsp+138h] [rbp+50h]

  x_low = (__m128)LODWORD(localWorld->v2.x);
  p_mBox = &this->mBox;
  vfptr = this->vfptr;
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
  v21 = v15 + v18;
  y = localWorld->v2.y;
  v23 = v21 + v19;
  v24 = localWorld->v2.z * localWorld->v2.z;
  v25 = v23 + localWorld->v3.y;
  v26 = (float)((float)(v16 + v20) + (float)(v12 * localWorld->v2.z)) + localWorld->v3.z;
  pos.y = v25;
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + v24;
  pos.z = v26;
  v27 = _mm_sqrt_ps(x_low).m128_f32[0];
  v28 = ((double (*)(void))vfptr->GetRadius)();
  v29 = UFG::qNearestSegPoint(&result, start, end, &pos);
  if ( (float)((float)((float)((float)(v25 - v29->y) * (float)(v25 - v29->y))
                     + (float)((float)(v17 - v29->x) * (float)(v17 - v29->x)))
             + (float)((float)(v26 - v29->z) * (float)(v26 - v29->z))) > (float)((float)(*(float *)&v28 * v27)
                                                                               * (float)(*(float *)&v28 * v27)) )
    return 0;
  UFG::qInverse(&d, localWorld);
  x = start->x;
  v32 = start->y;
  z = start->z;
  v34 = d.v0.y * start->x;
  v35 = d.v1.z * v32;
  v45 = (float)((float)((float)(d.v1.x * v32) + (float)(d.v0.x * start->x)) + (float)(d.v2.x * z)) + d.v1.z;
  v36 = d.v1.y * v32;
  v37 = end->z;
  v46 = (float)((float)(v36 + v34) + (float)(d.v2.y * z)) + d.v1.w;
  v38 = end->y;
  v39 = end->x;
  result.x = v45;
  pos.x = (float)((float)((float)(d.v1.x * v38) + (float)(d.v0.x * v39)) + (float)(d.v2.x * v37)) + d.v1.z;
  pos.y = (float)((float)((float)(d.v1.y * v38) + (float)(d.v0.y * v39)) + (float)(d.v2.y * v37)) + d.v1.w;
  pos.z = (float)((float)((float)(d.v1.z * v38) + (float)(d.v0.z * v39)) + (float)(d.v2.z * v37)) + d.v2.x;
  result.y = v46;
  result.z = (float)((float)(v35 + (float)(d.v0.z * x)) + (float)(d.v2.z * z)) + d.v2.x;
  IsHitSeg = UFG::qBox::IsHitSeg(p_mBox, &result, &pos, 0i64, v47);
  if ( v47 )
  {
    v40 = (float)((float)((float)(v47->y * localWorld->v1.y) + (float)(v47->x * localWorld->v0.y))
                + (float)(v47->z * localWorld->v2.y))
        + localWorld->v3.y;
    v41 = (float)((float)((float)(v47->y * localWorld->v1.z) + (float)(v47->x * localWorld->v0.z))
                + (float)(v47->z * localWorld->v2.z))
        + localWorld->v3.z;
    v47->x = (float)((float)((float)(v47->y * localWorld->v1.x) + (float)(v47->x * localWorld->v0.x))
                   + (float)(v47->z * localWorld->v2.x))
           + localWorld->v3.x;
    v47->y = v40;
    v47->z = v41;
  }
  return IsHitSeg;
}

// File Line: 662
// RVA: 0x240C10
char __fastcall UFG::RegionBox::IsHitRay(
        UFG::RegionBox *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qVector3 *pHitPos)
{
  return UFG::qBox::IsHitRay(&this->mBox, rayPos, rayDir, 0i64, pHitPos);
}

// File Line: 683
// RVA: 0x240FE0
char __fastcall UFG::RegionBox::IsHitRayWS(
        UFG::RegionBox *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qMatrix44 *localWorld)
{
  UFG::RegionBaseVtbl *vfptr; // rax
  UFG::qBox *p_mBox; // rsi
  float v9; // xmm4_4
  float v10; // xmm5_4
  __m128 x_low; // xmm6
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm5_4
  float v20; // xmm2_4
  float y; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm7_4
  double v25; // xmm0_8
  float v26; // xmm7_4
  char result; // al
  float x; // xmm3_4
  float v29; // xmm2_4
  float z; // xmm4_4
  float v31; // xmm6_4
  float v32; // xmm0_4
  float v33; // xmm5_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm5_4
  float v37; // xmm3_4
  float v38; // xmm4_4
  float v39; // xmm2_4
  float v40; // xmm6_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-49h] BYREF
  UFG::qVector3 rayPosa; // [rsp+30h] [rbp-39h] BYREF
  UFG::qMatrix44 d; // [rsp+48h] [rbp-21h] BYREF
  float v44; // [rsp+C8h] [rbp+5Fh]
  UFG::qVector3 *v45; // [rsp+E8h] [rbp+7Fh]

  vfptr = this->vfptr;
  p_mBox = &this->mBox;
  v9 = (float)(this->mBox.mMin.z + this->mBox.mMax.z) * 0.5;
  v10 = (float)(this->mBox.mMin.x + this->mBox.mMax.x) * 0.5;
  x_low = (__m128)LODWORD(localWorld->v2.x);
  v12 = (float)(this->mBox.mMin.y + this->mBox.mMax.y) * 0.5;
  v13 = v12 * localWorld->v1.x;
  v14 = v12 * localWorld->v1.y;
  v15 = v12 * localWorld->v1.z;
  v16 = (float)((float)((float)(v10 * localWorld->v0.x) + v13) + (float)(localWorld->v2.x * v9)) + localWorld->v3.x;
  v17 = v10 * localWorld->v0.y;
  v18 = v9 * localWorld->v2.y;
  v19 = v10 * localWorld->v0.z;
  pos.x = v16;
  v20 = v14 + v17;
  y = localWorld->v2.y;
  v22 = v20 + v18;
  v23 = localWorld->v2.z * localWorld->v2.z;
  v24 = (float)((float)(v15 + v19) + (float)(v9 * localWorld->v2.z)) + localWorld->v3.z;
  pos.y = v22 + localWorld->v3.y;
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + v23;
  pos.z = v24;
  v25 = ((double (__fastcall *)(UFG::RegionBox *, UFG::qVector3 *))vfptr->GetRadius)(this, rayPos);
  v26 = *(float *)&v25 * _mm_sqrt_ps(x_low).m128_f32[0];
  if ( UFG::qDistanceSqrRayPoint(rayPos, rayDir, &pos) > (float)(v26 * v26) )
    return 0;
  UFG::qInverse(&d, localWorld);
  x = rayPos->x;
  v29 = rayPos->y;
  z = rayPos->z;
  v31 = rayDir->x;
  v32 = d.v0.y * rayPos->x;
  v44 = (float)((float)((float)(d.v1.x * v29) + (float)(d.v0.x * rayPos->x)) + (float)(d.v2.x * z)) + d.v3.x;
  v33 = (float)(d.v1.y * v29) + v32;
  v34 = d.v0.z * x;
  v35 = d.v2.z * z;
  v36 = (float)(v33 + (float)(d.v2.y * z)) + d.v3.y;
  v37 = rayDir->y;
  v38 = rayDir->z;
  pos.x = (float)((float)(v31 * d.v0.x) + (float)(v37 * d.v1.x)) + (float)(v38 * d.v2.x);
  rayPosa.x = v44;
  rayPosa.y = v36;
  rayPosa.z = (float)((float)((float)(d.v1.z * v29) + v34) + v35) + d.v3.z;
  pos.y = (float)((float)(v31 * d.v0.y) + (float)(v37 * d.v1.y)) + (float)(v38 * d.v2.y);
  pos.z = (float)((float)(v31 * d.v0.z) + (float)(v37 * d.v1.z)) + (float)(v38 * d.v2.z);
  result = UFG::qBox::IsHitRay(p_mBox, &rayPosa, &pos, 0i64, *(UFG::qVector3 **)&pos.x);
  if ( v45 )
  {
    v39 = (float)((float)((float)(v45->y * localWorld->v1.y) + (float)(v45->x * localWorld->v0.y))
                + (float)(v45->z * localWorld->v2.y))
        + localWorld->v3.y;
    v40 = (float)((float)((float)(v45->y * localWorld->v1.z) + (float)(v45->x * localWorld->v0.z))
                + (float)(v45->z * localWorld->v2.z))
        + localWorld->v3.z;
    v45->x = (float)((float)((float)(v45->y * localWorld->v1.x) + (float)(v45->x * localWorld->v0.x))
                   + (float)(v45->z * localWorld->v2.x))
           + localWorld->v3.x;
    v45->y = v39;
    v45->z = v40;
  }
  return result;
}

// File Line: 723
// RVA: 0x23F7E0
char __fastcall UFG::RegionBox::IsHitPlaneRay(
        UFG::RegionBox *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qVector3 *pHitPos)
{
  return UFG::qBox::IsHitFaceBottomRay(&this->mBox, rayPos, rayDir, pHitPos);
}

// File Line: 745
// RVA: 0x23FA60
char __fastcall UFG::RegionBox::IsHitPlaneRayWS(
        UFG::RegionBox *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qMatrix44 *localWorld)
{
  UFG::qBox *p_mBox; // r14
  float v7; // xmm4_4
  float v8; // xmm5_4
  float x; // xmm1_4
  float v10; // xmm6_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float z; // xmm0_4
  float v15; // xmm2_4
  __m128 y_low; // xmm1
  float v17; // xmm3_4
  __m128 v18; // xmm4
  float v19; // xmm6_4
  char result; // al
  float v21; // xmm3_4
  float y; // xmm2_4
  float v23; // xmm4_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm6_4
  UFG::qVector3 pos; // [rsp+10h] [rbp-59h] BYREF
  UFG::qVector3 rayPosa; // [rsp+20h] [rbp-49h] BYREF
  UFG::qMatrix44 d; // [rsp+38h] [rbp-31h] BYREF
  float v30; // [rsp+C8h] [rbp+5Fh]
  UFG::qVector3 *v31; // [rsp+E8h] [rbp+7Fh]

  p_mBox = &this->mBox;
  v7 = (float)(this->mBox.mMin.z + this->mBox.mMax.z) * 0.5;
  v8 = (float)(this->mBox.mMin.x + this->mBox.mMax.x) * 0.5;
  x = localWorld->v2.x;
  v10 = x * x;
  v11 = (float)(this->mBox.mMin.y + this->mBox.mMax.y) * 0.5;
  v12 = (float)((float)(v8 * localWorld->v0.x) + (float)(v11 * localWorld->v1.x)) + (float)(x * v7);
  v13 = (float)(v11 * localWorld->v1.y) + (float)(v8 * localWorld->v0.y);
  z = localWorld->v2.z;
  pos.x = v12 + localWorld->v3.x;
  v15 = v13 + (float)(v7 * localWorld->v2.y);
  y_low = (__m128)LODWORD(localWorld->v2.y);
  v17 = (float)(this->mBox.mMax.x - this->mBox.mMin.x) * (float)(this->mBox.mMax.x - this->mBox.mMin.x);
  v18 = (__m128)LODWORD(this->mBox.mMax.y);
  pos.y = v15 + localWorld->v3.y;
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + v10) + (float)(z * z);
  v18.m128_f32[0] = (float)((float)((float)(v18.m128_f32[0] - p_mBox->mMin.y) * (float)(v18.m128_f32[0] - p_mBox->mMin.y))
                          + v17)
                  + (float)((float)(p_mBox->mMax.z - p_mBox->mMin.z) * (float)(p_mBox->mMax.z - p_mBox->mMin.z));
  v19 = _mm_sqrt_ps(y_low).m128_f32[0] * (float)(_mm_sqrt_ps(v18).m128_f32[0] * 0.5);
  if ( UFG::qDistanceSqrRayPoint(rayPos, rayDir, (UFG::qVector3 *)&rayPosa.z) > (float)(v19 * v19) )
    return 0;
  UFG::qInverse(&d, localWorld);
  v21 = rayPos->x;
  y = rayPos->y;
  v23 = rayPos->z;
  v24 = d.v0.y * rayPos->x;
  v30 = (float)((float)((float)(d.v1.x * y) + (float)(d.v0.x * rayPos->x)) + (float)(d.v2.x * v23)) + d.v3.x;
  rayPosa.x = v30;
  rayPosa.y = (float)((float)((float)(d.v1.y * y) + v24) + (float)(d.v2.y * v23)) + d.v3.y;
  rayPosa.z = (float)((float)((float)(d.v1.z * y) + (float)(d.v0.z * v21)) + (float)(d.v2.z * v23)) + d.v3.z;
  result = UFG::qBox::IsHitFaceBottomRay(p_mBox, &rayPosa, &pos, v31);
  if ( v31 )
  {
    v25 = (float)((float)((float)(v31->y * localWorld->v1.y) + (float)(v31->x * localWorld->v0.y))
                + (float)(v31->z * localWorld->v2.y))
        + localWorld->v3.y;
    v26 = (float)((float)((float)(v31->y * localWorld->v1.z) + (float)(v31->x * localWorld->v0.z))
                + (float)(v31->z * localWorld->v2.z))
        + localWorld->v3.z;
    v31->x = (float)((float)((float)(v31->y * localWorld->v1.x) + (float)(v31->x * localWorld->v0.x))
                   + (float)(v31->z * localWorld->v2.x))
           + localWorld->v3.x;
    v31->y = v25;
    v31->z = v26;
  }
  return result;
}

// File Line: 851
// RVA: 0x23A300
UFG::allocator::free_link *__fastcall UFG::RegionDisc::Clone(UFG::RegionDisc *this)
{
  UFG::allocator::free_link *result; // rax

  result = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
  if ( !result )
    return 0i64;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable;
  LODWORD(result[1].mNext) = 0;
  result->mNext = (UFG::allocator::free_link *)&UFG::RegionDisc::`vftable;
  *(float *)&result[2].mNext = this->mRadius;
  HIDWORD(result[2].mNext) = LODWORD(this->mExtentAbove);
  *(float *)&result[3].mNext = this->mExtentBelow;
  return result;
}

// File Line: 858
// RVA: 0x23D120
void __fastcall UFG::RegionDisc::GetBoundingBox(UFG::RegionDisc *this, UFG::qBox *pBox)
{
  int v2; // xmm0_4
  float mRadius; // xmm0_4

  v2 = LODWORD(this->mRadius) ^ _xmm[0];
  pBox->mMin.z = this->mExtentBelow;
  LODWORD(pBox->mMin.x) = v2;
  LODWORD(pBox->mMin.y) = v2;
  mRadius = this->mRadius;
  pBox->mMax.z = this->mExtentAbove;
  pBox->mMax.x = mRadius;
  pBox->mMax.y = mRadius;
}

// File Line: 868
// RVA: 0x23D370
void __fastcall UFG::AIInterestComponent::GetAngularVelocity(UFG::AIInterestComponent *this, UFG::qVector3 *outAngVel)
{
  float y; // xmm1_4
  float z; // xmm2_4

  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  outAngVel->x = UFG::qVector3::msZero.x;
  outAngVel->y = y;
  outAngVel->z = z;
}

// File Line: 878
// RVA: 0x23DC70
UFG::qVector3 *__fastcall UFG::RegionDisc::GetRandomPosition(UFG::RegionDisc *this, UFG::qVector3 *result)
{
  float v4; // xmm7_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float y; // xmm7_4
  __m128 x_low; // xmm4
  float z; // xmm6_4
  __m128 v10; // xmm3
  float v11; // xmm5_4
  float v12; // xmm0_4
  UFG::qVector3 *v13; // rax

  v4 = UFG::qRandom(360.0, (unsigned int *)&UFG::qDefaultSeed);
  v5 = UFG::qRandom(360.0, (unsigned int *)&UFG::qDefaultSeed);
  UFG::qSphericalToCartesian(result, v4, v5);
  result->z = 0.0;
  v6 = UFG::qRandom(this->mRadius, (unsigned int *)&UFG::qDefaultSeed);
  y = result->y;
  x_low = (__m128)LODWORD(result->x);
  z = result->z;
  v10 = x_low;
  v10.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
  v11 = v6 / _mm_sqrt_ps(v10).m128_f32[0];
  result->x = x_low.m128_f32[0] * v11;
  result->y = y * v11;
  result->z = z * v11;
  v12 = UFG::qRandom(this->mExtentAbove - this->mExtentBelow, (unsigned int *)&UFG::qDefaultSeed);
  v13 = result;
  result->z = v12 + this->mExtentBelow;
  return v13;
}

// File Line: 917
// RVA: 0x240570
bool __fastcall UFG::RegionDisc::IsHitPoint(UFG::RegionDisc *this, UFG::qVector3 *pos)
{
  float z; // xmm0_4

  z = pos->z;
  return z >= this->mExtentBelow
      && z <= this->mExtentAbove
      && (float)((float)(pos->x * pos->x) + (float)(pos->y * pos->y)) <= (float)(this->mRadius * this->mRadius);
}

// File Line: 930
// RVA: 0x2408C0
bool __fastcall UFG::RegionDisc::IsHitPointWS(UFG::RegionDisc *this, UFG::qVector3 *pos, UFG::qMatrix44 *localWorld)
{
  float z; // xmm4_4
  float v4; // xmm1_4
  bool result; // al

  z = pos->z;
  result = 0;
  if ( (float)(localWorld->v3.z + this->mExtentBelow) <= z && z <= (float)(localWorld->v3.z + this->mExtentAbove) )
  {
    v4 = pos->y - localWorld->v3.y;
    if ( (float)((float)(v4 * v4) + (float)((float)(pos->x - localWorld->v3.x) * (float)(pos->x - localWorld->v3.x))) <= (float)(this->mRadius * this->mRadius) )
      return 1;
  }
  return result;
}

// File Line: 957
// RVA: 0x241EE0
char __fastcall UFG::RegionDisc::IsHitSegment(
        UFG::RegionDisc *this,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qVector3 *pHitPos)
{
  float v8; // xmm5_4
  float v9; // xmm4_4
  UFG::qVector3 enda; // [rsp+40h] [rbp-38h] BYREF
  UFG::qVector3 starta; // [rsp+50h] [rbp-28h] BYREF
  float pPDist; // [rsp+80h] [rbp+8h] BYREF

  if ( !(unsigned int)UFG::qIntersectSegSlab(
                        start,
                        end,
                        &UFG::qVector3::msDirUp,
                        this->mExtentBelow,
                        this->mExtentAbove,
                        &starta,
                        &enda)
    || !UFG::qIntersectSegCircleOrigin((UFG::qVector2 *)&starta, (UFG::qVector2 *)&enda, this->mRadius, &pPDist) )
  {
    return 0;
  }
  if ( pHitPos )
  {
    v8 = start->y + (float)((float)(end->y - start->y) * pPDist);
    v9 = start->z + (float)((float)(end->z - start->z) * pPDist);
    pHitPos->x = start->x + (float)((float)(end->x - start->x) * pPDist);
    pHitPos->y = v8;
    pHitPos->z = v9;
  }
  return 1;
}

// File Line: 996
// RVA: 0x242740
char __fastcall UFG::RegionDisc::IsHitSegmentWS(
        UFG::RegionDisc *this,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qMatrix44 *localWorld,
        UFG::qVector3 *pHitPos)
{
  float mExtentAbove; // xmm3_4
  float v8; // xmm1_4
  float mExtentBelow; // xmm2_4
  float y; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  UFG::qVector3 *v13; // rcx
  float v14; // xmm0_4
  float x; // xmm1_4
  float v16; // xmm7_4
  float z; // xmm8_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  UFG::qVector3 enda; // [rsp+30h] [rbp-78h] BYREF
  UFG::qVector3 hit_enter_p; // [rsp+40h] [rbp-68h] BYREF
  UFG::qVector3 ray_dir; // [rsp+50h] [rbp-58h] BYREF
  UFG::qVector3 ray_pos; // [rsp+5Ch] [rbp-4Ch] BYREF
  float pPDist; // [rsp+B0h] [rbp+8h] BYREF

  mExtentAbove = this->mExtentAbove;
  v8 = start->x - localWorld->v3.x;
  mExtentBelow = this->mExtentBelow;
  ray_dir.x = end->x - localWorld->v3.x;
  y = end->y;
  ray_pos.x = v8;
  v11 = start->z - localWorld->v3.z;
  ray_dir.y = y - localWorld->v3.y;
  v12 = end->z - localWorld->v3.z;
  ray_pos.z = v11;
  ray_dir.z = v12;
  ray_pos.y = start->y - localWorld->v3.y;
  if ( !(unsigned int)UFG::qIntersectRaySlabZ(&ray_pos, &ray_dir, mExtentBelow, mExtentAbove, &hit_enter_p, &enda)
    || !UFG::qIntersectSegCircleOrigin((UFG::qVector2 *)&hit_enter_p, (UFG::qVector2 *)&enda, this->mRadius, &pPDist) )
  {
    return 0;
  }
  v13 = pHitPos;
  if ( pHitPos )
  {
    v14 = pPDist;
    x = hit_enter_p.x;
    v16 = localWorld->v3.y;
    z = localWorld->v3.z;
    v18 = enda.z;
    pHitPos->x = localWorld->v3.x;
    v19 = (float)(x + v13->x) + (float)((float)(enda.x - x) * v14);
    v20 = (float)(hit_enter_p.y + v16) + (float)((float)(enda.y - hit_enter_p.y) * v14);
    v13->z = (float)(hit_enter_p.z + z) + (float)((float)(v18 - hit_enter_p.z) * v14);
    v13->x = v19;
    v13->y = v20;
  }
  return 1;
}

// File Line: 1037
// RVA: 0x240C30
char __fastcall UFG::RegionDisc::IsHitRay(
        UFG::RegionDisc *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qVector3 *pHitPos)
{
  float v6; // xmm4_4
  float v7; // xmm6_4
  UFG::qVector3 hit_exit_p; // [rsp+30h] [rbp-38h] BYREF
  UFG::qVector3 hit_enter_p; // [rsp+40h] [rbp-28h] BYREF
  float pPDist; // [rsp+70h] [rbp+8h] BYREF

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
          this->mRadius,
          &pPDist) )
  {
    return 0;
  }
  if ( pHitPos )
  {
    v6 = (float)((float)(hit_exit_p.z - hit_enter_p.z) * pPDist) + hit_enter_p.z;
    v7 = (float)((float)(hit_exit_p.x - hit_enter_p.x) * pPDist) + hit_enter_p.x;
    pHitPos->y = (float)((float)(hit_exit_p.y - hit_enter_p.y) * pPDist) + hit_enter_p.y;
    pHitPos->z = v6;
    pHitPos->x = v7;
  }
  return 1;
}

// File Line: 1075
// RVA: 0x241320
char __fastcall UFG::RegionDisc::IsHitRayWS(
        UFG::RegionDisc *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qMatrix44 *localWorld,
        UFG::qVector3 *pHitPos)
{
  float mExtentAbove; // xmm3_4
  float v8; // xmm1_4
  float mExtentBelow; // xmm2_4
  float z; // xmm0_4
  UFG::qVector3 *v11; // rcx
  float v12; // xmm0_4
  float x; // xmm1_4
  float y; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm6_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  UFG::qVector3 hit_exit_p; // [rsp+30h] [rbp-68h] BYREF
  UFG::qVector3 hit_enter_p; // [rsp+40h] [rbp-58h] BYREF
  UFG::qVector3 ray_pos; // [rsp+50h] [rbp-48h] BYREF
  float pPDist; // [rsp+A0h] [rbp+8h] BYREF

  mExtentAbove = this->mExtentAbove;
  v8 = rayPos->y - localWorld->v3.y;
  mExtentBelow = this->mExtentBelow;
  ray_pos.x = rayPos->x - localWorld->v3.x;
  z = rayPos->z;
  ray_pos.y = v8;
  ray_pos.z = z - localWorld->v3.z;
  if ( !(unsigned int)UFG::qIntersectRaySlabZ(&ray_pos, rayDir, mExtentBelow, mExtentAbove, &hit_enter_p, &hit_exit_p)
    || !UFG::qIntersectSegCircleOrigin(
          (UFG::qVector2 *)&hit_enter_p,
          (UFG::qVector2 *)&hit_exit_p,
          this->mRadius,
          &pPDist) )
  {
    return 0;
  }
  v11 = pHitPos;
  if ( pHitPos )
  {
    v12 = pPDist;
    x = hit_enter_p.x;
    y = localWorld->v3.y;
    v15 = localWorld->v3.z;
    v16 = hit_exit_p.z;
    pHitPos->x = localWorld->v3.x;
    v17 = (float)(x + v11->x) + (float)((float)(hit_exit_p.x - x) * v12);
    v18 = (float)(hit_enter_p.y + y) + (float)((float)(hit_exit_p.y - hit_enter_p.y) * v12);
    v11->z = (float)(hit_enter_p.z + v15) + (float)((float)(v16 - hit_enter_p.z) * v12);
    v11->x = v17;
    v11->y = v18;
  }
  return 1;
}

// File Line: 1116
// RVA: 0x23F7F0
char __fastcall UFG::RegionDisc::IsHitPlaneRay(
        UFG::RegionDisc *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qVector3 *pHitPos)
{
  float mRadius; // xmm6_4
  float y; // xmm4_4
  float z; // xmm5_4
  UFG::qVector3 hit_pos_p; // [rsp+30h] [rbp-28h] BYREF

  mRadius = this->mRadius;
  if ( !UFG::qIntersectRayPlane(rayPos, rayDir, &UFG::qVector3::msDirUp, &UFG::qVector3::msZero, &hit_pos_p) )
    return 0;
  y = hit_pos_p.y;
  z = hit_pos_p.z;
  if ( (float)((float)((float)((float)(UFG::qVector3::msZero.y - hit_pos_p.y)
                             * (float)(UFG::qVector3::msZero.y - hit_pos_p.y))
                     + (float)((float)(UFG::qVector3::msZero.x - hit_pos_p.x)
                             * (float)(UFG::qVector3::msZero.x - hit_pos_p.x)))
             + (float)((float)(UFG::qVector3::msZero.z - hit_pos_p.z) * (float)(UFG::qVector3::msZero.z - hit_pos_p.z))) > (float)(mRadius * mRadius) )
    return 0;
  if ( pHitPos )
  {
    pHitPos->x = hit_pos_p.x;
    pHitPos->y = y;
    pHitPos->z = z;
  }
  return 1;
}

// File Line: 1139
// RVA: 0x23FDE0
char __fastcall UFG::RegionDisc::IsHitPlaneRayWS(
        UFG::RegionDisc *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qMatrix44 *localWorld,
        UFG::qVector3 *pHitPos)
{
  UFG::qVector4 *v5; // rbx
  float mRadius; // xmm6_4
  float y; // xmm4_4
  float z; // xmm5_4
  UFG::qVector3 hit_pos_p; // [rsp+30h] [rbp-28h] BYREF

  v5 = &localWorld->v3;
  mRadius = this->mRadius;
  if ( !UFG::qIntersectRayPlane(rayPos, rayDir, &UFG::qVector3::msDirUp, (UFG::qVector3 *)&localWorld->v3, &hit_pos_p) )
    return 0;
  y = hit_pos_p.y;
  z = hit_pos_p.z;
  if ( (float)((float)((float)((float)(v5->x - hit_pos_p.x) * (float)(v5->x - hit_pos_p.x))
                     + (float)((float)(v5->y - hit_pos_p.y) * (float)(v5->y - hit_pos_p.y)))
             + (float)((float)(v5->z - hit_pos_p.z) * (float)(v5->z - hit_pos_p.z))) > (float)(mRadius * mRadius) )
    return 0;
  if ( pHitPos )
  {
    pHitPos->x = hit_pos_p.x;
    pHitPos->y = y;
    pHitPos->z = z;
  }
  return 1;
}

// File Line: 1160
// RVA: 0x23A7B0
__int64 __fastcall UFG::RegionDisc::CycleAspect(UFG::RegionDisc *this, unsigned int aspect, bool forward)
{
  unsigned int v3; // edx
  __int64 result; // rax

  if ( forward )
  {
    v3 = aspect + 1;
    if ( v3 > 2 )
      return 0;
    return v3;
  }
  else
  {
    result = 2i64;
    if ( aspect )
      return aspect - 1;
  }
  return result;
}

// File Line: 1187
// RVA: 0x23C2F0
UFG::qVector3 *__fastcall UFG::RegionDisc::GetAspectCenter(
        UFG::RegionDisc *this,
        UFG::qVector3 *result,
        unsigned int aspect)
{
  UFG::qVector3 *v3; // rax
  int v4; // r8d
  float mRadius; // xmm2_4
  float v6; // xmm1_4
  float z; // xmm0_4
  float mExtentBelow; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  v3 = result;
  v4 = aspect - 1;
  if ( v4 )
  {
    if ( v4 != 1 )
    {
      mRadius = this->mRadius;
      v6 = UFG::qVector3::msDirFront.y * mRadius;
      result->x = UFG::qVector3::msDirFront.x * mRadius;
      z = UFG::qVector3::msDirFront.z;
      result->y = v6;
      result->z = z * mRadius;
      return v3;
    }
    mExtentBelow = this->mExtentBelow;
  }
  else
  {
    mExtentBelow = this->mExtentAbove;
  }
  v9 = UFG::qVector3::msDirUp.y * mExtentBelow;
  result->x = UFG::qVector3::msDirUp.x * mExtentBelow;
  v10 = UFG::qVector3::msDirUp.z;
  result->y = v9;
  result->z = v10 * mExtentBelow;
  return v3;
}

// File Line: 1207
// RVA: 0x23C620
UFG::qVector3 *__fastcall UFG::RegionDisc::GetAspectNormal(
        UFG::RegionDisc *this,
        UFG::qVector3 *result,
        unsigned int aspect)
{
  UFG::qVector3 *v3; // rax
  int v4; // r8d
  float y; // xmm1_4
  float z; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4

  v3 = result;
  v4 = aspect - 1;
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      y = UFG::qVector3::msDirDown.y;
      result->x = UFG::qVector3::msDirDown.x;
      z = UFG::qVector3::msDirDown.z;
    }
    else
    {
      y = UFG::qVector3::msDirFront.y;
      result->x = UFG::qVector3::msDirFront.x;
      z = UFG::qVector3::msDirFront.z;
    }
    result->y = y;
    result->z = z;
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
char __fastcall UFG::RegionDisc::IsHitAspect(
        UFG::RegionDisc *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        unsigned int *pHitAspect)
{
  UFG::RegionBaseVtbl *vfptr; // rax
  char result; // al
  float mExtentBelow; // xmm0_4
  unsigned int v9; // eax
  char v10; // cl
  char v11; // [rsp+20h] [rbp-18h] BYREF
  float v12; // [rsp+28h] [rbp-10h]

  vfptr = this->vfptr;
  if ( !pHitAspect )
    return ((__int64 (__fastcall *)(UFG::RegionDisc *, UFG::qVector3 *, UFG::qVector3 *))vfptr->IsHitRay)(
             this,
             rayPos,
             rayDir);
  if ( !vfptr->IsHitRay(this, rayPos, rayDir, (UFG::qVector3 *)&v11) )
    return 0;
  mExtentBelow = this->mExtentBelow;
  if ( mExtentBelow > v12 || v12 > (float)(mExtentBelow * 0.5) )
  {
    v9 = 0;
    if ( (float)(this->mExtentAbove * 0.5) > v12 || (v10 = 1, v12 > this->mExtentAbove) )
      v10 = 0;
    LOBYTE(v9) = v10 != 0;
    *pHitAspect = v9;
    return 1;
  }
  else
  {
    result = 1;
    *pHitAspect = 2;
  }
  return result;
}

// File Line: 1265
// RVA: 0x246210
void __fastcall UFG::RegionDisc::TranslateAspect(UFG::RegionDisc *this, unsigned int aspect, UFG::qVector3 *delta)
{
  int v3; // edx
  float v4; // xmm0_4
  float v5; // xmm0_4
  float mRadius; // xmm0_4
  __m128 y_low; // xmm3
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
    mRadius = this->mRadius;
    y_low = (__m128)LODWORD(UFG::qVector3::msDirFront.y);
    y_low.m128_f32[0] = (float)((float)((float)((float)(UFG::qVector3::msDirFront.y * mRadius) + delta->y)
                                      * (float)((float)(UFG::qVector3::msDirFront.y * mRadius) + delta->y))
                              + (float)((float)((float)(UFG::qVector3::msDirFront.x * mRadius) + delta->x)
                                      * (float)((float)(UFG::qVector3::msDirFront.x * mRadius) + delta->x)))
                      + (float)((float)((float)(UFG::qVector3::msDirFront.z * mRadius) + delta->z)
                              * (float)((float)(UFG::qVector3::msDirFront.z * mRadius) + delta->z));
    v8 = _mm_sqrt_ps(y_low).m128_f32[0];
    if ( v8 <= 0.0 )
      v8 = 0.0;
    this->mRadius = v8;
  }
}

