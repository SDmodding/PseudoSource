// File Line: 55
// RVA: 0x64F370
float __fastcall UFG::RacePoint::GetSegmentDistance(UFG::RacePoint *this, UFG::qVector3 *position)
{
  __m128 y_low; // xmm4
  float y; // xmm11_4
  float z; // xmm12_4
  float fLength; // xmm3_4
  float v6; // xmm6_4
  float v7; // xmm5_4
  float result; // xmm0_4

  y_low = (__m128)LODWORD(position->y);
  y = this->vPosition.y;
  z = this->vPosition.z;
  fLength = (float)((float)(this->vDirection.x * (float)(position->x - this->vPosition.x))
                  + (float)(this->vDirection.y * (float)(position->y - y)))
          + (float)(this->vDirection.z * (float)(position->z - z));
  if ( fLength <= 0.0 )
    fLength = 0.0;
  if ( fLength >= this->fLength )
    fLength = this->fLength;
  y_low.m128_f32[0] = y_low.m128_f32[0] - (float)(y + (float)(this->vDirection.y * fLength));
  v6 = position->z - (float)(z + (float)(this->vDirection.z * fLength));
  v7 = position->x - (float)(this->vPosition.x + (float)(this->vDirection.x * fLength));
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v7 * v7)) + (float)(v6 * v6);
  LODWORD(result) = _mm_sqrt_ps(y_low).m128_u32[0];
  return result;
}

// File Line: 69
// RVA: 0x64F490
UFG::qVector3 *__fastcall UFG::RacePoint::GetSegmentPosition(
        UFG::RacePoint *this,
        UFG::qVector3 *result,
        UFG::qVector3 *position)
{
  float y; // xmm8_4
  float v4; // xmm5_4
  float z; // xmm9_4
  float fLength; // xmm3_4
  UFG::qVector3 *v7; // rax
  float v8; // xmm9_4

  y = this->vPosition.y;
  v4 = this->vDirection.y;
  z = this->vPosition.z;
  fLength = (float)((float)(this->vDirection.x * (float)(position->x - this->vPosition.x))
                  + (float)(v4 * (float)(position->y - y)))
          + (float)(this->vDirection.z * (float)(position->z - z));
  if ( fLength <= 0.0 )
    fLength = 0.0;
  if ( fLength >= this->fLength )
    fLength = this->fLength;
  v7 = result;
  v8 = z + (float)(this->vDirection.z * fLength);
  result->x = this->vPosition.x + (float)(this->vDirection.x * fLength);
  result->z = v8;
  result->y = y + (float)(v4 * fLength);
  return v7;
}

// File Line: 75
// RVA: 0x64E960
UFG::qVector3 *__fastcall UFG::RacePoint::GetNextPosition(UFG::RacePoint *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rax
  float fLength; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  v2 = result;
  fLength = this->fLength;
  v4 = (float)(fLength * this->vDirection.z) + this->vPosition.z;
  v5 = (float)(fLength * this->vDirection.x) + this->vPosition.x;
  v6 = (float)(this->fLength * this->vDirection.y) + this->vPosition.y;
  result->z = v4;
  result->x = v5;
  result->y = v6;
  return v2;
}

// File Line: 83
// RVA: 0x642DE0
void __fastcall UFG::RaceTrail::RaceTrail(UFG::RaceTrail *this, int num_points, int raceIndex)
{
  unsigned __int64 v4; // rdi
  UFG::RacePoint *v6; // rbp
  __int64 v7; // rax
  bool v8; // cf
  unsigned __int64 v9; // rax
  UFG::allocator::free_link *v10; // rax

  v4 = num_points;
  UFG::qSafePointerNode<UFG::RaceTrail>::qSafePointerNode<UFG::RaceTrail>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::RaceTrail>Vtbl *)&UFG::RaceTrail::`vftable;
  *(_QWORD *)&this->nLaps = 1i64;
  v6 = 0i64;
  this->fLength = 0.0;
  this->bIsLoop = 0;
  this->mRaceIndex = raceIndex;
  this->nRacePoints = v4;
  v7 = 0x38 * v4;
  if ( !is_mul_ok(v4, 0x38ui64) )
    v7 = -1i64;
  v8 = __CFADD__(v7, 4i64);
  v9 = v7 + 4;
  if ( v8 )
    v9 = -1i64;
  v10 = UFG::qMalloc(v9, "RacePoints", 0i64);
  if ( v10 )
  {
    LODWORD(v10->mNext) = v4;
    v6 = (UFG::RacePoint *)((char *)&v10->mNext + 4);
    `eh vector constructor iterator(
      (char *)&v10->mNext + 4,
      0x38ui64,
      v4,
      (void (__fastcall *)(void *))Assembly::GetRCX);
  }
  this->pRacePoints = v6;
}

// File Line: 95
// RVA: 0x643DB0
void __fastcall UFG::RaceTrail::~RaceTrail(UFG::RaceTrail *this)
{
  UFG::RacePoint *pRacePoints; // rcx
  float *p_fTimeBonus; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *mNext; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::RaceTrail>Vtbl *)&UFG::RaceTrail::`vftable;
  pRacePoints = this->pRacePoints;
  if ( pRacePoints )
  {
    p_fTimeBonus = &pRacePoints[-1].fTimeBonus;
    `eh vector destructor iterator(
      pRacePoints,
      0x38ui64,
      LODWORD(pRacePoints[-1].fTimeBonus),
      (void (__fastcall *)(void *))_);
    operator delete[](p_fTimeBonus);
  }
  this->vfptr = (UFG::qSafePointerNode<UFG::RaceTrail>Vtbl *)&UFG::qSafePointerNode<UFG::RaceTrail>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  mPrev = this->m_SafePointerList.mNode.mPrev;
  mNext = this->m_SafePointerList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_SafePointerList.mNode.mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
}

// File Line: 101
// RVA: 0x6448D0
void __fastcall UFG::RaceTrail::AddRacePoint(UFG::RaceTrail *this, UFG::qVector3 *position, float speed, float bonus)
{
  __int64 nPoint; // rax
  int v6; // eax
  UFG::RacePoint *v7; // rcx
  float v8; // xmm2_4
  float v9; // xmm1_4

  nPoint = this->nPoint;
  if ( (int)nPoint < this->nRacePoints )
  {
    this->pRacePoints[nPoint].fSpeed = speed;
    this->pRacePoints[this->nPoint].fTimeBonus = bonus;
    v6 = this->nPoint;
    v7 = &this->pRacePoints[v6];
    this->nPoint = v6 + 1;
    v8 = (float)(UFG::qVector3::msDirUp.y * 0.5) + position->y;
    v9 = (float)(UFG::qVector3::msDirUp.z * 0.5) + position->z;
    v7->vPosition.x = (float)(UFG::qVector3::msDirUp.x * 0.5) + position->x;
    v7->vPosition.y = v8;
    v7->vPosition.z = v9;
  }
}

// File Line: 123
// RVA: 0x64EFC0
UFG::RacePoint *__fastcall UFG::RaceTrail::GetRacePoint(UFG::RaceTrail *this, UFG::qVector3 *position, float *distSq)
{
  UFG::RacePoint *pRacePoints; // rdi
  int v7; // esi
  float v8; // xmm6_4
  float SegmentDistance; // xmm0_4
  int nRacePoints; // edx
  int v11; // r9d
  float v12; // xmm12_4
  float *p_x; // rcx
  float *p_z; // rax
  float x; // xmm14_4
  float y; // xmm15_4
  float v17; // xmm10_4
  float v18; // xmm11_4
  float v19; // xmm3_4
  float v20; // xmm9_4
  float v21; // xmm3_4
  float v22; // xmm1_4

  pRacePoints = this->pRacePoints;
  v7 = 0;
  v8 = 0.0;
  SegmentDistance = UFG::RacePoint::GetSegmentDistance(pRacePoints, position);
  nRacePoints = this->nRacePoints;
  v11 = 1;
  v12 = SegmentDistance;
  if ( nRacePoints > 1 )
  {
    p_x = &pRacePoints[1].vPosition.x;
    p_z = &pRacePoints[1].vDirection.z;
    x = position->x;
    y = position->y;
    do
    {
      v17 = *(p_z - 5);
      v18 = *(p_z - 4);
      v19 = (float)((float)(*(p_z - 2) * (float)(x - *p_x)) + (float)(*(p_z - 1) * (float)(y - v17)))
          + (float)(*p_z * (float)(position->z - v18));
      if ( v19 <= 0.0 )
        v19 = 0.0;
      if ( v19 >= p_z[1] )
        v19 = p_z[1];
      v20 = *p_x + (float)(*(p_z - 2) * v19);
      v21 = fsqrt(
              (float)((float)((float)(y - (float)(v17 + (float)(*(p_z - 1) * v19)))
                            * (float)(y - (float)(v17 + (float)(*(p_z - 1) * v19))))
                    + (float)((float)(x - v20) * (float)(x - v20)))
            + (float)((float)(position->z - (float)(v18 + (float)(*p_z * v19)))
                    * (float)(position->z - (float)(v18 + (float)(*p_z * v19)))));
      v22 = v21 - v12;
      if ( (float)(v21 - v12) >= 0.0 )
      {
        if ( v11 == 1 || v22 < v8 )
          v8 = v21 - v12;
      }
      else
      {
        v7 = v11;
        v12 = v21;
        LODWORD(v8) = LODWORD(v22) ^ _xmm[0];
      }
      ++v11;
      p_x += 14;
      p_z += 14;
    }
    while ( v11 < nRacePoints );
  }
  *distSq = (float)(v8 * 0.5) * (float)(v8 * 0.5);
  return &this->pRacePoints[v7];
}

// File Line: 149
// RVA: 0x64CD70
void __fastcall UFG::RaceTrail::Finalize(UFG::RaceTrail *this)
{
  int nPoint; // eax
  int v3; // edx
  float v4; // xmm3_4
  __int64 v5; // rcx
  UFG::RacePoint *pRacePoints; // rax
  float v7; // xmm5_4
  __m128 y_low; // xmm6
  float v9; // xmm7_4
  __m128 v10; // xmm2
  float v11; // xmm4_4
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::RacePoint *v14; // rcx
  __int64 v15; // rdx
  float v16; // xmm4_4
  __m128 v17; // xmm5
  float v18; // xmm6_4
  __m128 v19; // xmm2
  float v20; // xmm7_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  UFG::RacePoint *v23; // rdx
  __int64 v24; // rcx
  __m128 v25; // xmm4
  float v26; // xmm5_4
  float v27; // xmm2_4
  __m128 v28; // xmm6
  float v29; // xmm1_4
  int nRacePoints; // ecx
  UFG::RacePoint *v31; // r8
  __int64 v32; // rdx
  __int64 v33; // rcx
  float x; // eax
  float v35; // xmm1_4
  UFG::RacePoint *v36; // rcx
  float v37; // xmm0_4
  float v38; // xmm1_4
  int v39; // esi
  __int64 v40; // rdi
  float v41; // xmm0_4
  UFG::RacePoint *v42; // rax
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm0_4
  __m128 v46; // xmm4
  float v47; // xmm5_4
  __m128 v48; // xmm2
  float v49; // xmm1_4
  UFG::RacePoint *v50; // rax

  nPoint = this->nPoint;
  this->nRacePoints = nPoint;
  v3 = 0;
  v4 = 0.0;
  if ( nPoint - 1 > 0 )
  {
    v5 = 0i64;
    do
    {
      pRacePoints = this->pRacePoints;
      y_low = (__m128)LODWORD(pRacePoints[v5 + 1].vPosition.y);
      v7 = pRacePoints[v5 + 1].vPosition.x - pRacePoints[v5].vPosition.x;
      y_low.m128_f32[0] = y_low.m128_f32[0] - pRacePoints[v5].vPosition.y;
      v9 = pRacePoints[v5 + 1].vPosition.z - pRacePoints[v5].vPosition.z;
      v10 = y_low;
      v10.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
      v11 = _mm_sqrt_ps(v10).m128_f32[0];
      if ( v11 >= 0.0000099999997 )
      {
        z = (float)(1.0 / v11) * v9;
        pRacePoints[v5].vDirection.x = (float)(1.0 / v11) * v7;
        pRacePoints[v5].vDirection.y = (float)(1.0 / v11) * y_low.m128_f32[0];
      }
      else
      {
        y = UFG::qVector3::msDirFront.y;
        z = UFG::qVector3::msDirFront.z;
        pRacePoints[v5].vDirection.x = UFG::qVector3::msDirFront.x;
        pRacePoints[v5].vDirection.y = y;
      }
      pRacePoints[v5].vDirection.z = z;
      ++v3;
      this->pRacePoints[v5++].fRaceDistance = v4;
      v4 = v4 + v11;
      this->pRacePoints[v5 - 1].fLength = v11;
    }
    while ( v3 < this->nRacePoints - 1 );
  }
  this->pRacePoints[this->nRacePoints - 1].fRaceDistance = v4;
  if ( this->bIsLoop )
  {
    v14 = this->pRacePoints;
    v17 = (__m128)LODWORD(v14->vPosition.y);
    v15 = this->nRacePoints - 1;
    v16 = v14->vPosition.x - v14[v15].vPosition.x;
    v17.m128_f32[0] = v17.m128_f32[0] - v14[v15].vPosition.y;
    v18 = v14->vPosition.z - v14[v15].vPosition.z;
    v19 = v17;
    v19.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16)) + (float)(v18 * v18);
    v20 = _mm_sqrt_ps(v19).m128_f32[0];
    if ( v20 >= 0.0000099999997 )
    {
      v22 = (float)(1.0 / v20) * v18;
      v14[v15].vDirection.x = (float)(1.0 / v20) * v16;
      v14[v15].vDirection.y = (float)(1.0 / v20) * v17.m128_f32[0];
    }
    else
    {
      v21 = UFG::qVector3::msDirFront.y;
      v22 = UFG::qVector3::msDirFront.z;
      v14[v15].vDirection.x = UFG::qVector3::msDirFront.x;
      v14[v15].vDirection.y = v21;
    }
    v14[v15].vDirection.z = v22;
    v4 = v4 + v20;
    this->pRacePoints[this->nRacePoints - 1].fLength = v20;
    v23 = this->pRacePoints;
    v25 = (__m128)LODWORD(v23->vDirection.y);
    v24 = this->nRacePoints - 1;
    v25.m128_f32[0] = v25.m128_f32[0] + v23[v24].vDirection.y;
    v26 = v23->vDirection.z + v23[v24].vDirection.z;
    v28 = v25;
    v27 = v23[v24].vDirection.x + v23->vDirection.x;
    v28.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v27 * v27)) + (float)(v26 * v26);
    if ( v28.m128_f32[0] == 0.0 )
      v29 = 0.0;
    else
      v29 = 1.0 / _mm_sqrt_ps(v28).m128_f32[0];
    v23->vDistanceRay.x = v27 * v29;
    v23->vDistanceRay.y = v25.m128_f32[0] * v29;
    v23->vDistanceRay.z = v26 * v29;
  }
  else
  {
    nRacePoints = this->nRacePoints;
    v31 = this->pRacePoints;
    v32 = nRacePoints - 2;
    v33 = nRacePoints - 1;
    x = v31[v32].vDirection.x;
    v35 = v31[v32].vDirection.z;
    v31[v33].vDirection.y = v31[v32].vDirection.y;
    v31[v33].vDirection.z = v35;
    v31[v33].vDirection.x = x;
    this->pRacePoints[this->nRacePoints - 1].fCurvature = 0.0;
    this->pRacePoints[this->nRacePoints - 1].fLength = 0.0;
    v36 = this->pRacePoints;
    v37 = v36->vDirection.y;
    v38 = v36->vDirection.z;
    v36->vDistanceRay.x = v36->vDirection.x;
    v36->vDistanceRay.y = v37;
    v36->vDistanceRay.z = v38;
  }
  v39 = 1;
  this->fLength = v4;
  if ( this->nRacePoints > 1 )
  {
    v40 = 1i64;
    do
    {
      v41 = UFG::qSignedAngleBetween(&this->pRacePoints[v39 - 1].vDirection, &this->pRacePoints[v39].vDirection);
      v42 = this->pRacePoints;
      v43 = v41;
      v46 = (__m128)LODWORD(v42[v40].vDirection.y);
      v44 = v42[v40].vDirection.x + v42[v40 - 1].vDirection.x;
      v45 = (float)(v42[v40 - 1].fLength + v42[v40].fLength) * 0.5;
      v46.m128_f32[0] = v46.m128_f32[0] + v42[v40 - 1].vDirection.y;
      v47 = v42[v40].vDirection.z + v42[v40 - 1].vDirection.z;
      if ( v45 <= 1.0 )
      {
        v45 = *(float *)&FLOAT_1_0;
      }
      else if ( v45 >= 25.0 )
      {
        v45 = FLOAT_25_0;
      }
      v48 = v46;
      v42[v40 - 1].fCurvature = v43 / v45;
      v48.m128_f32[0] = (float)((float)(v46.m128_f32[0] * v46.m128_f32[0]) + (float)(v44 * v44)) + (float)(v47 * v47);
      if ( v48.m128_f32[0] == 0.0 )
        v49 = 0.0;
      else
        v49 = 1.0 / _mm_sqrt_ps(v48).m128_f32[0];
      v50 = this->pRacePoints;
      ++v39;
      v50[v40++].vDistanceRay.x = v44 * v49;
      v50[v40 - 1].vDistanceRay.y = v46.m128_f32[0] * v49;
      v50[v40 - 1].vDistanceRay.z = v47 * v49;
    }
    while ( v39 < this->nRacePoints );
  }
}

// File Line: 269
// RVA: 0x642D30
void __fastcall UFG::RacePosition::RacePosition(UFG::RacePosition *this, UFG::RaceTrail *race_trail)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v5; // rax
  float y; // xmm1_4
  float z; // xmm2_4

  this->pRaceTrail.mPrev = &this->pRaceTrail;
  this->pRaceTrail.mNext = &this->pRaceTrail;
  this->pRaceTrail.m_pPointer = 0i64;
  this->pRacePoint = 0i64;
  if ( this->pRaceTrail.m_pPointer )
  {
    mPrev = this->pRaceTrail.mPrev;
    mNext = this->pRaceTrail.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->pRaceTrail.mPrev = &this->pRaceTrail;
    this->pRaceTrail.mNext = &this->pRaceTrail;
  }
  this->pRaceTrail.m_pPointer = race_trail;
  if ( race_trail )
  {
    v5 = race_trail->m_SafePointerList.mNode.mPrev;
    v5->mNext = &this->pRaceTrail;
    this->pRaceTrail.mPrev = v5;
    this->pRaceTrail.mNext = &race_trail->m_SafePointerList.mNode;
    race_trail->m_SafePointerList.mNode.mPrev = &this->pRaceTrail;
  }
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->vUpdatePosition.x = UFG::qVector3::msZero.x;
  this->vUpdatePosition.y = y;
  this->vUpdatePosition.z = z;
  *(_QWORD *)&this->fUpdateDistanceSq = 0i64;
  *(_QWORD *)&this->fRaceProximity = 0i64;
  *(_QWORD *)&this->fRaceTime = 0i64;
}

// File Line: 289
// RVA: 0x651970
void __fastcall UFG::RacePosition::InitPosition(UFG::RacePosition *this, UFG::qVector3 *position)
{
  UFG::RaceTrail *m_pPointer; // rax
  float fRaceDistance; // xmm1_4
  UFG::RacePoint *pRacePoints; // rax

  this->pRacePoint = 0i64;
  this->fRaceDistance = 0.0;
  this->fBonusDistance = 0.0;
  if ( this->pRaceTrail.m_pPointer )
  {
    UFG::RacePosition::UpdateRacePoint(this, position);
    UFG::RacePosition::UpdateRaceDistance(this, position);
    m_pPointer = this->pRaceTrail.m_pPointer;
    if ( m_pPointer->bIsLoop )
    {
      fRaceDistance = this->fRaceDistance;
      if ( fRaceDistance > (float)(m_pPointer->fLength * 0.5) )
        this->fRaceDistance = fRaceDistance - m_pPointer->fLength;
    }
    else if ( this->fRaceDistance <= 0.0 )
    {
      pRacePoints = m_pPointer->pRacePoints;
      this->pRacePoint = pRacePoints;
      this->fUpdateDistanceSq = (float)((float)((float)(position->y - pRacePoints->vPosition.y)
                                              * (float)(position->y - pRacePoints->vPosition.y))
                                      + (float)((float)(position->x - pRacePoints->vPosition.x)
                                              * (float)(position->x - pRacePoints->vPosition.x)))
                              + (float)((float)(position->z - pRacePoints->vPosition.z)
                                      * (float)(position->z - pRacePoints->vPosition.z));
    }
  }
}

// File Line: 315
// RVA: 0x65F660
void __fastcall UFG::RacePosition::Update(UFG::RacePosition *this, UFG::qVector3 *position, float delta_seconds)
{
  UFG::RacePoint *pRacePoint; // rsi
  float v4; // xmm1_4
  UFG::RacePoint *v7; // rax

  pRacePoint = this->pRacePoint;
  v4 = this->fCountDownTime - delta_seconds;
  this->fRaceTime = delta_seconds + this->fRaceTime;
  this->fCountDownTime = v4;
  UFG::RacePosition::UpdateRacePoint(this, position);
  UFG::RacePosition::UpdateRaceDistance(this, position);
  if ( pRacePoint )
  {
    v7 = this->pRacePoint;
    if ( v7 != pRacePoint && this->fBonusDistance <= this->fRaceDistance )
    {
      this->fBonusDistance = v7->fRaceDistance + v7->fLength;
      this->fCountDownTime = v7->fTimeBonus + this->fCountDownTime;
    }
  }
}

// File Line: 337
// RVA: 0x663450
void __fastcall UFG::RacePosition::UpdateRacePoint(UFG::RacePosition *this, UFG::qVector3 *position)
{
  float y; // xmm0_4
  float z; // xmm1_4

  if ( !this->pRacePoint
    || (float)((float)((float)((float)(position->y - this->vUpdatePosition.y)
                             * (float)(position->y - this->vUpdatePosition.y))
                     + (float)((float)(position->x - this->vUpdatePosition.x)
                             * (float)(position->x - this->vUpdatePosition.x)))
             + (float)((float)(position->z - this->vUpdatePosition.z) * (float)(position->z - this->vUpdatePosition.z))) > this->fUpdateDistanceSq )
  {
    this->pRacePoint = UFG::RaceTrail::GetRacePoint(this->pRaceTrail.m_pPointer, position, &this->fUpdateDistanceSq);
    y = position->y;
    z = position->z;
    this->vUpdatePosition.x = position->x;
    this->vUpdatePosition.y = y;
    this->vUpdatePosition.z = z;
  }
}

// File Line: 347
// RVA: 0x663150
void __fastcall UFG::RacePosition::UpdateRaceDistance(UFG::RacePosition *this, UFG::qVector3 *position)
{
  UFG::RaceTrail *m_pPointer; // rdi
  UFG::RacePoint *pRacePoint; // rbx
  UFG::RacePoint *pRacePoints; // rcx
  int nRacePoints; // eax
  int v8; // edx
  float *p_x; // r14
  double v10; // xmm7_8
  __int64 x_low; // xmm8_8
  double v12; // xmm6_8
  float v13; // xmm1_4
  bool bIsLoop; // dl
  UFG::RacePoint *v15; // rcx
  float fLength; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  __m128 y_low; // xmm2
  float v22; // xmm1_4

  m_pPointer = this->pRaceTrail.m_pPointer;
  pRacePoint = this->pRacePoint;
  pRacePoints = m_pPointer->pRacePoints;
  nRacePoints = m_pPointer->nRacePoints;
  v8 = ((int)pRacePoint - (int)pRacePoints) / 56 + 1;
  if ( v8 >= nRacePoints )
  {
    if ( m_pPointer->bIsLoop )
      v8 = 0;
    else
      v8 = nRacePoints - 1;
  }
  x_low = LODWORD(position->x);
  *(_QWORD *)&v10 = LODWORD(position->y);
  p_x = &pRacePoints[v8].vPosition.x;
  *(float *)&v10 = (float)((float)((float)(*(float *)&v10 - pRacePoint->vPosition.y) * pRacePoint->vDistanceRay.y)
                         + (float)((float)(position->x - pRacePoint->vPosition.x) * pRacePoint->vDistanceRay.x))
                 + (float)((float)(position->z - pRacePoint->vPosition.z) * pRacePoint->vDistanceRay.z);
  *(float *)&x_low = (float)((float)((float)(*(float *)&x_low
                                           - (float)((float)(pRacePoint->fLength * pRacePoint->vDirection.x)
                                                   + pRacePoint->vPosition.x))
                                   * p_x[8])
                           + (float)((float)(position->y
                                           - (float)((float)(pRacePoint->fLength * pRacePoint->vDirection.y)
                                                   + pRacePoint->vPosition.y))
                                   * p_x[9]))
                   + (float)((float)(position->z
                                   - (float)((float)(pRacePoint->fLength * pRacePoint->vDirection.z)
                                           + pRacePoint->vPosition.z))
                           * p_x[10]);
  if ( *(float *)&v10 >= 0.0 )
    v12 = v10;
  else
    v12 = 0.0;
  if ( *(float *)&x_low <= 0.0 )
    v13 = *(float *)&x_low;
  else
    v13 = 0.0;
  if ( (float)(*(float *)&v12 - v13) >= 0.001 )
    *(float *)&v12 = *(float *)&v12 / (float)(*(float *)&v12 - v13);
  else
    *(_QWORD *)&v12 = LODWORD(FLOAT_0_5);
  this->fRaceProximity = UFG::RacePoint::GetSegmentDistance(pRacePoint, position);
  bIsLoop = m_pPointer->bIsLoop;
  if ( !bIsLoop )
  {
    v15 = m_pPointer->pRacePoints;
    if ( pRacePoint == v15 && *(float *)&v10 < 0.0 )
    {
      if ( *(float *)&v10 <= -40.0 )
        *(_QWORD *)&v10 = LODWORD(FLOAT_N40_0);
      fLength = pRacePoint->fLength;
      if ( fLength > 0.001 )
      {
        HIDWORD(v12) = HIDWORD(v10);
        *(float *)&v12 = *(float *)&v10 / fLength;
      }
      v17 = (float)(*(float *)&v10 * pRacePoint->vDistanceRay.y) + pRacePoint->vPosition.y;
      v18 = position->x - (float)((float)(*(float *)&v10 * pRacePoint->vDistanceRay.x) + pRacePoint->vPosition.x);
      v19 = position->z - (float)((float)(*(float *)&v10 * pRacePoint->vDistanceRay.z) + pRacePoint->vPosition.z);
    }
    else
    {
      if ( pRacePoint != &v15[m_pPointer->nRacePoints - 1] || *(float *)&x_low <= 0.0 )
        goto LABEL_30;
      if ( *(float *)&x_low >= 60.0 )
        x_low = LODWORD(FLOAT_60_0);
      v20 = pRacePoint->fLength;
      if ( v20 > 0.001 )
      {
        HIDWORD(v12) = HIDWORD(x_low);
        *(float *)&v12 = *(float *)&x_low / v20;
      }
      v18 = position->x
          - (float)((float)((float)(v20 * pRacePoint->vDirection.x) + pRacePoint->vPosition.x)
                  + (float)(*(float *)&v10 * p_x[8]));
      v17 = (float)((float)(v20 * pRacePoint->vDirection.y) + pRacePoint->vPosition.y)
          + (float)(*(float *)&v10 * p_x[9]);
      v19 = position->z
          - (float)((float)((float)(v20 * pRacePoint->vDirection.z) + pRacePoint->vPosition.z)
                  + (float)(*(float *)&v10 * p_x[10]));
    }
    y_low = (__m128)LODWORD(position->y);
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v17) * (float)(y_low.m128_f32[0] - v17))
                              + (float)(v18 * v18))
                      + (float)(v19 * v19);
    LODWORD(this->fRaceProximity) = _mm_sqrt_ps(y_low).m128_u32[0];
  }
LABEL_30:
  v22 = m_pPointer->fLength;
  *(float *)&v12 = (float)(*(float *)&v12 * pRacePoint->fLength) + pRacePoint->fRaceDistance;
  this->fRaceDistance = *(float *)&v12;
  if ( bIsLoop )
    this->fRaceDistance = UFG::qSignedMod(v12, v22);
}

// File Line: 385
// RVA: 0x64EFA0
signed __int64 __fastcall UFG::RacePosition::GetRaceIndex(UFG::RacePosition *this)
{
  UFG::RaceTrail *m_pPointer; // rax

  m_pPointer = this->pRaceTrail.m_pPointer;
  if ( m_pPointer )
    return (unsigned int)m_pPointer->mRaceIndex;
  else
    return 0xFFFFFFFFi64;
}

// File Line: 417
// RVA: 0x64CA50
bool __fastcall UFG::TimeTrial::Exits(UFG::TimeTrial *this, UFG::qVector3 *p0, UFG::qVector3 *p1, unsigned int exit)
{
  float v4; // xmm5_4
  float v5; // xmm7_4
  float v6; // xmm4_4
  float v7; // xmm8_4
  float v8; // xmm11_4
  float v9; // xmm10_4
  float x; // xmm9_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v13; // xmm6_4
  float v14; // xmm9_4
  float v15; // xmm0_4
  float v16; // xmm0_4

  v4 = p0->y - this->vPosition[exit].y;
  v5 = p1->x - this->vPosition[exit].x;
  v6 = p1->y - this->vPosition[exit].y;
  v7 = p1->z - this->vPosition[exit].z;
  v8 = p0->z - this->vPosition[exit].z;
  v9 = p0->x - this->vPosition[exit].x;
  x = this->vDirection[exit].x;
  y = this->vDirection[exit].y;
  z = this->vDirection[exit].z;
  v13 = (float)((float)(x * v5) + (float)(y * v6)) + (float)(z * v7);
  v14 = (float)((float)(x * v9) + (float)(y * v4)) + (float)(z * v8);
  if ( v14 < 0.0 || v13 >= 0.0 )
    return 0;
  v15 = this->fRadius[exit];
  v16 = v15 * v15;
  return (float)((float)((float)((float)(v4 * v4) + (float)(v9 * v9)) + (float)(v8 * v8)) - (float)(v14 * v14)) < v16
      || (float)((float)((float)((float)(v6 * v6) + (float)(v5 * v5)) + (float)(v7 * v7)) - (float)(v13 * v13)) < v16;
}

// File Line: 476
// RVA: 0x642C70
void __fastcall UFG::RaceManager::RaceManager(UFG::RaceManager *this)
{
  UFG::RaceTrail **v2; // rax
  __int64 v3; // rcx
  UFG::TimeTrial *v4; // rax
  __int64 v5; // rcx

  UFG::TSActor::TSActor(this, &UFG::RaceManager::mClass->i_name, UFG::RaceManager::mClass);
  this->vfptr = (SSObjectBaseVtbl *)&UFG::RaceManager::`vftable;
  v2 = UFG::RaceManager::aRaceTrails;
  v3 = 8i64;
  do
  {
    *v2 = 0i64;
    v2[1] = 0i64;
    v2[2] = 0i64;
    v2 += 8;
    *(v2 - 5) = 0i64;
    *(v2 - 4) = 0i64;
    *(v2 - 3) = 0i64;
    *(v2 - 2) = 0i64;
    *(v2 - 1) = 0i64;
    --v3;
  }
  while ( v3 );
  v4 = (UFG::TimeTrial *)UFG::RaceManager::aTimeTrials;
  v5 = 3i64;
  do
  {
    *(_QWORD *)&v4->nUid = 0i64;
    *(_QWORD *)&v4->fRadius[1] = 0i64;
    *(_QWORD *)&v4->vPosition[0].y = 0i64;
    v4 = (UFG::TimeTrial *)((char *)v4 + 64);
    *(_QWORD *)&v4[-1].vPosition[0].z = 0i64;
    *(_QWORD *)&v4[-1].vPosition[1].y = 0i64;
    *(_QWORD *)&v4[-1].vDirection[0].x = 0i64;
    *(_QWORD *)&v4[-1].vDirection[0].z = 0i64;
    *(_QWORD *)&v4[-1].vDirection[1].y = 0i64;
    --v5;
  }
  while ( v5 );
  *(_QWORD *)&v4->nUid = 0i64;
}

// File Line: 494
// RVA: 0x650FB0
UFG::TimeTrial *__fastcall UFG::RaceManager::GetTimeTrial(unsigned int uid)
{
  UFG::TimeTrial **v1; // rax

  v1 = UFG::RaceManager::aTimeTrials;
  while ( !*v1 || uid != (*v1)->nUid )
  {
    if ( (__int64)++v1 >= (__int64)&UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame )
      return 0i64;
  }
  return *v1;
}

// File Line: 507
// RVA: 0x64F1F0
UFG::RaceTrail *__fastcall UFG::RaceManager::GetRaceTrail(int index)
{
  int v1; // eax

  if ( index <= 0 )
  {
    v1 = 0;
  }
  else
  {
    v1 = index;
    if ( index >= 63 )
      v1 = 63;
  }
  if ( index == v1 )
    return UFG::RaceManager::aRaceTrails[index];
  else
    return 0i64;
}

// File Line: 517
// RVA: 0x657E60
void UFG::RaceManager::Release(void)
{
  UFG::RaceTrail **v0; // rbx
  void **v1; // rbx

  v0 = UFG::RaceManager::aRaceTrails;
  do
  {
    if ( *v0 )
    {
      (*v0)->vfptr->__vecDelDtor(*v0, 1u);
      *v0 = 0i64;
    }
    ++v0;
  }
  while ( (__int64)v0 < (__int64)UFG::RaceManager::aTimeTrials );
  v1 = (void **)UFG::RaceManager::aTimeTrials;
  do
  {
    if ( *v1 )
    {
      operator delete[](*v1);
      *v1 = 0i64;
    }
    ++v1;
  }
  while ( (__int64)v1 < (__int64)&UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame );
}

// File Line: 556
// RVA: 0x64A160
void UFG::RaceManager::Create(void)
{
  UFG::RaceManager *v0; // rax

  v0 = (UFG::RaceManager *)AMemory::c_malloc_func(0xD8ui64, "RaceManager");
  if ( v0 )
    UFG::RaceManager::RaceManager(v0);
  UFG::RaceManager::mInstance = v0;
  ++v0->i_ref_count;
}

// File Line: 571
// RVA: 0x645710
void UFG::RaceManager::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  UFG::RaceManager::mClass = (SSActorClass *)SSBrain::get_class("RaceManager");
  SSClass::register_method_func(UFG::RaceManager::mClass, "time_trial", UFG::RaceManager::MthdC_time_trial, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::RaceManager::mClass,
    "race_release",
    UFG::RaceManager::MthdC_race_release,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    UFG::RaceManager::mClass,
    "race_release_trail",
    UFG::RaceManager::MthdC_race_release_trail,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    UFG::RaceManager::mClass,
    "race_allocate",
    UFG::RaceManager::MthdC_race_allocate,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    UFG::RaceManager::mClass,
    "race_finalize",
    UFG::RaceManager::MthdC_race_finalize,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    UFG::RaceManager::mClass,
    "race_add_xform",
    UFG::RaceManager::MthdC_race_add_xform,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    UFG::RaceManager::mClass,
    "race_set_is_loop",
    UFG::RaceManager::MthdC_race_set_is_loop,
    1,
    rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(
    UFG::RaceManager::mClass,
    "race_set_num_laps",
    UFG::RaceManager::MthdC_race_set_num_laps,
    1,
    rebindg);
}

// File Line: 585
// RVA: 0x65E960
char __fastcall UFG::RaceManager::TimeTrialEntered(
        UFG::qVector3 *p0,
        UFG::qVector3 *p1,
        unsigned int *p_uid,
        unsigned int *p_exit)
{
  unsigned int **v7; // r10
  unsigned int *v8; // r11
  int v9; // r8d
  float *v10; // rdx
  float *v11; // rcx
  __int64 v12; // rax
  float v13; // xmm10_4
  float v14; // xmm5_4
  float v15; // xmm11_4
  float v16; // xmm7_4
  float v17; // xmm4_4
  float v18; // xmm8_4
  float v19; // xmm9_4
  float v20; // xmm6_4
  float v21; // xmm0_4

  v7 = (unsigned int **)UFG::RaceManager::aTimeTrials;
  while ( 1 )
  {
    v8 = *v7;
    if ( *v7 )
      break;
LABEL_9:
    if ( (__int64)++v7 >= (__int64)&UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame )
      return 0;
  }
  v9 = 0;
  v10 = (float *)(v8 + 1);
  v11 = (float *)(v8 + 5);
  v12 = 0i64;
  while ( 1 )
  {
    v13 = p0->x - *(v11 - 2);
    v14 = p0->y - *(v11 - 1);
    v15 = p0->z - *v11;
    v16 = p1->x - *(v11 - 2);
    v17 = p1->y - *(v11 - 1);
    v18 = p1->z - *v11;
    v19 = (float)((float)(v11[4] * v13) + (float)(v11[5] * v14)) + (float)(v11[6] * v15);
    v20 = (float)((float)(v11[4] * v16) + (float)(v11[5] * v17)) + (float)(v11[6] * v18);
    if ( v19 < 0.0 && v20 >= 0.0 )
    {
      v21 = *v10 * *v10;
      if ( (float)((float)((float)((float)(v14 * v14) + (float)(v13 * v13)) + (float)(v15 * v15)) - (float)(v19 * v19)) < v21
        || (float)((float)((float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(v18 * v18)) - (float)(v20 * v20)) < v21 )
      {
        break;
      }
    }
    ++v12;
    ++v9;
    v11 += 3;
    ++v10;
    if ( v12 >= 2 )
      goto LABEL_9;
  }
  *p_exit = v9 ^ 1;
  *p_uid = *v8;
  return 1;
}

// File Line: 600
// RVA: 0x652C00
void __fastcall UFG::RaceManager::MthdC_race_allocate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v3; // ebp
  SSInstance *v4; // rdi
  int v5; // ebx
  UFG::RaceTrail **v6; // rax
  int i_user_data; // esi
  UFG::allocator::free_link *v8; // rax
  UFG::RaceTrail *v9; // rax
  UFG::RaceTrail *v10; // rcx
  SSClass *v11; // rsi
  AObjReusePool<SSInstance> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v14; // eax
  __int64 v15; // rcx
  SSInstance **i_array_p; // rax
  unsigned int v17; // eax

  v3 = -1;
  v4 = 0i64;
  v5 = 0;
  v6 = UFG::RaceManager::aRaceTrails;
  while ( *v6 )
  {
    ++v5;
    if ( (__int64)++v6 >= (__int64)UFG::RaceManager::aTimeTrials )
      goto LABEL_9;
  }
  v3 = v5;
  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v8 = UFG::qMalloc(0x38ui64, "RaceTrail", 0i64);
  if ( v8 )
  {
    UFG::RaceTrail::RaceTrail((UFG::RaceTrail *)v8, i_user_data, v5);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  UFG::RaceManager::aRaceTrails[v5] = v10;
LABEL_9:
  v11 = SSBrain::c_integer_class_p;
  pool = SSInstance::get_pool();
  if ( pool->i_pool.i_count )
  {
    v17 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v17;
    v15 = v17;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_15;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSInstance>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v14 = i_count - 1;
    pool->i_exp_pool.i_count = v14;
    v15 = v14;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_15:
    v4 = i_array_p[v15];
  }
  v4->i_class_p = v11;
  v4->i_user_data = v3;
  v4->i_ref_count = 1;
  v4->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  *ppResult = v4;
}

// File Line: 617
// RVA: 0x652D60
// attributes: thunk
void __fastcall UFG::RaceManager::MthdC_race_release(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RaceManager::Release();
}

// File Line: 622
// RVA: 0x652D70
void __fastcall UFG::RaceManager::MthdC_race_release_trail(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int i_user_data; // ecx
  int v3; // eax
  UFG::RaceTrail **v4; // rbx

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = 0;
  while ( v3 != i_user_data )
  {
    if ( ++v3 >= 64 )
      return;
  }
  v4 = &UFG::RaceManager::aRaceTrails[v3];
  if ( *v4 )
  {
    (*v4)->vfptr->__vecDelDtor(*v4, 1u);
    *v4 = 0i64;
  }
}

// File Line: 628
// RVA: 0x652D20
void __fastcall UFG::RaceManager::MthdC_race_finalize(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  __int64 i_user_data_low; // rcx
  int v3; // eax
  UFG::RaceTrail *v4; // rcx

  i_user_data_low = SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    v3 = 0;
  }
  else
  {
    v3 = i_user_data_low;
    if ( (int)i_user_data_low >= 63 )
      v3 = 63;
  }
  if ( (_DWORD)i_user_data_low == v3 )
  {
    v4 = UFG::RaceManager::aRaceTrails[i_user_data_low];
    if ( v4 )
      UFG::RaceTrail::Finalize(v4);
  }
}

// File Line: 635
// RVA: 0x652B50
void __fastcall UFG::RaceManager::MthdC_race_add_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  float v3; // xmm6_4
  float v4; // xmm7_4
  unsigned __int64 i_user_data; // rdi
  __int64 i_user_data_low; // rax
  int v7; // ecx
  UFG::RaceTrail *v8; // rbx

  i_array_p = pScope->i_data.i_array_p;
  v3 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
  v4 = *(float *)&i_array_p[3]->i_data_p->i_user_data;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  i_user_data_low = SLODWORD((*i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    v7 = 0;
  }
  else
  {
    v7 = (*i_array_p)->i_data_p->i_user_data;
    if ( (int)i_user_data_low >= 63 )
      v7 = 63;
  }
  if ( (_DWORD)i_user_data_low == v7 )
  {
    v8 = UFG::RaceManager::aRaceTrails[i_user_data_low];
    if ( v8 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)i_user_data);
      UFG::RaceTrail::AddRacePoint(v8, (UFG::qVector3 *)(i_user_data + 176), v3 * 0.27777779, v4);
    }
  }
}

// File Line: 648
// RVA: 0x652DD0
void __fastcall UFG::RaceManager::MthdC_race_set_is_loop(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  __int64 i_user_data_low; // rax
  int i_user_data; // ecx
  UFG::RaceTrail *v5; // rdx

  i_array_p = pScope->i_data.i_array_p;
  i_user_data_low = SLODWORD((*i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    i_user_data = 0;
  }
  else
  {
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    if ( (int)i_user_data_low >= 63 )
      i_user_data = 63;
  }
  if ( (_DWORD)i_user_data_low == i_user_data )
  {
    v5 = UFG::RaceManager::aRaceTrails[i_user_data_low];
    if ( v5 )
      v5->bIsLoop = i_array_p[1]->i_data_p->i_user_data != 0;
  }
}

// File Line: 656
// RVA: 0x652E20
void __fastcall UFG::RaceManager::MthdC_race_set_num_laps(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  __int64 i_user_data_low; // rax
  int i_user_data; // ecx
  UFG::RaceTrail *v5; // rdx

  i_array_p = pScope->i_data.i_array_p;
  i_user_data_low = SLODWORD((*i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    i_user_data = 0;
  }
  else
  {
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    if ( (int)i_user_data_low >= 63 )
      i_user_data = 63;
  }
  if ( (_DWORD)i_user_data_low == i_user_data )
  {
    v5 = UFG::RaceManager::aRaceTrails[i_user_data_low];
    if ( v5 )
      v5->nLaps = i_array_p[1]->i_data_p->i_user_data;
  }
}

// File Line: 664
// RVA: 0x652FA0
void __fastcall UFG::RaceManager::MthdC_time_trial(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int v3; // ebx
  UFG::TimeTrial **v4; // rax
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rsi
  unsigned __int64 i_user_data; // rbp
  unsigned __int64 v8; // r14
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rdi
  SSData **v11; // rdx
  int v12; // xmm0_4
  int v13; // xmm1_4
  int v14; // xmm0_4
  int v15; // xmm1_4
  int v16; // xmm0_4
  int v17; // xmm1_4
  int v18; // xmm0_4
  int v19; // xmm1_4

  v3 = 0;
  v4 = UFG::RaceManager::aTimeTrials;
  while ( *v4 )
  {
    ++v3;
    if ( (__int64)++v4 >= (__int64)&UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame )
      return;
  }
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  v8 = i_array_p[3]->i_data_p->i_user_data;
  v9 = UFG::qMalloc(0x3Cui64, "TimeTrial", 0i64);
  v10 = v9;
  if ( v9 )
    LODWORD(v9->mNext) = i_data_p->i_user_data;
  else
    v10 = 0i64;
  UFG::RaceManager::aTimeTrials[v3] = (UFG::TimeTrial *)v10;
  v11 = pScope->i_data.i_array_p;
  HIDWORD(v10->mNext) = v11[2]->i_data_p->i_user_data;
  LODWORD(v10[1].mNext) = v11[4]->i_data_p->i_user_data;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)i_user_data);
  v12 = *(_DWORD *)(i_user_data + 180);
  v13 = *(_DWORD *)(i_user_data + 184);
  HIDWORD(v10[1].mNext) = *(_DWORD *)(i_user_data + 176);
  LODWORD(v10[2].mNext) = v12;
  HIDWORD(v10[2].mNext) = v13;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8);
  v14 = *(_DWORD *)(v8 + 180);
  v15 = *(_DWORD *)(v8 + 184);
  LODWORD(v10[3].mNext) = *(_DWORD *)(v8 + 176);
  HIDWORD(v10[3].mNext) = v14;
  LODWORD(v10[4].mNext) = v15;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)i_user_data);
  v16 = *(_DWORD *)(i_user_data + 132);
  v17 = *(_DWORD *)(i_user_data + 136);
  HIDWORD(v10[4].mNext) = *(_DWORD *)(i_user_data + 128);
  LODWORD(v10[5].mNext) = v16;
  HIDWORD(v10[5].mNext) = v17;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8);
  v18 = *(_DWORD *)(v8 + 132);
  v19 = *(_DWORD *)(v8 + 136);
  LODWORD(v10[6].mNext) = *(_DWORD *)(v8 + 128);
  HIDWORD(v10[6].mNext) = v18;
  LODWORD(v10[7].mNext) = v19;
}

