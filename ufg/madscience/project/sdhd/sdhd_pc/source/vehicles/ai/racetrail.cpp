// File Line: 55
// RVA: 0x64F370
float __fastcall UFG::RacePoint::GetSegmentDistance(UFG::RacePoint *this, UFG::qVector3 *position)
{
  __m128 v2; // xmm4
  float v3; // xmm11_4
  float v4; // xmm12_4
  float v5; // xmm3_4
  float v6; // xmm6_4
  float v7; // xmm5_4
  float result; // xmm0_4

  v2 = (__m128)LODWORD(position->y);
  v3 = this->vPosition.y;
  v4 = this->vPosition.z;
  v5 = (float)((float)(this->vDirection.x * (float)(position->x - this->vPosition.x))
             + (float)(this->vDirection.y * (float)(position->y - v3)))
     + (float)(this->vDirection.z * (float)(position->z - v4));
  if ( v5 <= 0.0 )
    v5 = 0.0;
  if ( v5 >= this->fLength )
    v5 = this->fLength;
  v2.m128_f32[0] = v2.m128_f32[0] - (float)(v3 + (float)(this->vDirection.y * v5));
  v6 = position->z - (float)(v4 + (float)(this->vDirection.z * v5));
  v7 = position->x - (float)(this->vPosition.x + (float)(this->vDirection.x * v5));
  v2.m128_f32[0] = (float)((float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(v7 * v7)) + (float)(v6 * v6);
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v2);
  return result;
}

// File Line: 69
// RVA: 0x64F490
UFG::qVector3 *__fastcall UFG::RacePoint::GetSegmentPosition(UFG::RacePoint *this, UFG::qVector3 *result, UFG::qVector3 *position)
{
  float v3; // xmm8_4
  float v4; // xmm5_4
  float v5; // xmm9_4
  float v6; // xmm3_4
  UFG::qVector3 *v7; // rax
  float v8; // xmm9_4

  v3 = this->vPosition.y;
  v4 = this->vDirection.y;
  v5 = this->vPosition.z;
  v6 = (float)((float)(this->vDirection.x * (float)(position->x - this->vPosition.x))
             + (float)(this->vDirection.y * (float)(position->y - v3)))
     + (float)(this->vDirection.z * (float)(position->z - v5));
  if ( v6 <= 0.0 )
    v6 = 0.0;
  if ( v6 >= this->fLength )
    v6 = this->fLength;
  v7 = result;
  v8 = v5 + (float)(this->vDirection.z * v6);
  result->x = this->vPosition.x + (float)(this->vDirection.x * v6);
  result->z = v8;
  result->y = v3 + (float)(v4 * v6);
  return v7;
}

// File Line: 75
// RVA: 0x64E960
UFG::qVector3 *__fastcall UFG::RacePoint::GetNextPosition(UFG::RacePoint *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rax
  float v3; // xmm0_4
  float v4; // xmm1_4

  v2 = result;
  v3 = (float)(this->fLength * this->vDirection.x) + this->vPosition.x;
  v4 = (float)(this->fLength * this->vDirection.y) + this->vPosition.y;
  result->z = (float)(this->fLength * this->vDirection.z) + this->vPosition.z;
  result->x = v3;
  result->y = v4;
  return v2;
}

// File Line: 83
// RVA: 0x642DE0
void __fastcall UFG::RaceTrail::RaceTrail(UFG::RaceTrail *this, int num_points, int raceIndex)
{
  int v3; // ebx
  unsigned __int64 v4; // rdi
  UFG::RaceTrail *v5; // rsi
  signed __int64 v6; // rbp
  signed __int64 v7; // rax
  unsigned __int8 v8; // cf
  unsigned __int64 v9; // rax
  UFG::allocator::free_link *v10; // rax

  v3 = raceIndex;
  v4 = num_points;
  v5 = this;
  UFG::qSafePointerNode<UFG::RaceTrail>::qSafePointerNode<UFG::RaceTrail>((UFG::qSafePointerNode<UFG::RaceTrail> *)&this->vfptr);
  v5->vfptr = (UFG::qSafePointerNode<UFG::RaceTrail>Vtbl *)&UFG::RaceTrail::`vftable;
  *(_QWORD *)&v5->nLaps = 1i64;
  v6 = 0i64;
  v5->fLength = 0.0;
  v5->bIsLoop = 0;
  v5->mRaceIndex = v3;
  v5->nRacePoints = v4;
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
    v6 = (signed __int64)&v10->mNext + 4;
    `eh vector constructor iterator(
      (char *)&v10->mNext + 4,
      0x38ui64,
      v4,
      (void (__fastcall *)(void *))Assembly::GetRCX);
  }
  v5->pRacePoints = (UFG::RacePoint *)v6;
}

// File Line: 95
// RVA: 0x643DB0
void __fastcall UFG::RaceTrail::~RaceTrail(UFG::RaceTrail *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v1; // rdi
  UFG::RacePoint *v2; // rcx
  float *v3; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)this;
  this->vfptr = (UFG::qSafePointerNode<UFG::RaceTrail>Vtbl *)&UFG::RaceTrail::`vftable;
  v2 = this->pRacePoints;
  if ( v2 )
  {
    v3 = &v2[-1].fTimeBonus;
    `eh vector destructor iterator(v2, 0x38ui64, LODWORD(v2[-1].fTimeBonus), (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  v1->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::RaceTrail>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v1);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v1->m_SafePointerList);
  v4 = v1->m_SafePointerList.mNode.mPrev;
  v5 = v1->m_SafePointerList.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
}

// File Line: 101
// RVA: 0x6448D0
void __fastcall UFG::RaceTrail::AddRacePoint(UFG::RaceTrail *this, UFG::qVector3 *position, float speed, float bonus)
{
  __int64 v4; // rax
  UFG::RaceTrail *v5; // r9
  int v6; // eax
  UFG::RacePoint *v7; // rcx
  float v8; // xmm2_4
  float v9; // xmm1_4

  v4 = this->nPoint;
  v5 = this;
  if ( (signed int)v4 < this->nRacePoints )
  {
    this->pRacePoints[v4].fSpeed = speed;
    this->pRacePoints[this->nPoint].fTimeBonus = bonus;
    v6 = this->nPoint;
    v7 = &this->pRacePoints[this->nPoint];
    v5->nPoint = v6 + 1;
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
  UFG::RacePoint *v3; // rdi
  UFG::RaceTrail *v4; // rbp
  float *v5; // r14
  UFG::qVector3 *v6; // rbx
  signed int v7; // esi
  float v8; // xmm6_4
  float v9; // xmm0_4
  signed int v10; // edx
  signed int v11; // er9
  float v12; // xmm12_4
  float *v13; // rcx
  float *v14; // rax
  float v15; // xmm14_4
  float v16; // xmm15_4
  float v17; // xmm10_4
  float v18; // xmm11_4
  float v19; // xmm3_4
  float v20; // xmm9_4
  float v21; // xmm3_4
  float v22; // xmm1_4

  v3 = this->pRacePoints;
  v4 = this;
  v5 = distSq;
  v6 = position;
  v7 = 0;
  v8 = 0.0;
  v9 = UFG::RacePoint::GetSegmentDistance(this->pRacePoints, position);
  v10 = v4->nRacePoints;
  v11 = 1;
  v12 = v9;
  if ( v10 > 1 )
  {
    v13 = &v3[1].vPosition.x;
    v14 = &v3[1].vDirection.z;
    v15 = v6->x;
    v16 = v6->y;
    do
    {
      v17 = *(v14 - 5);
      v18 = *(v14 - 4);
      v19 = (float)((float)(*(v14 - 2) * (float)(v15 - *v13)) + (float)(*(v14 - 1) * (float)(v16 - v17)))
          + (float)(*v14 * (float)(v6->z - v18));
      if ( v19 <= 0.0 )
        v19 = 0.0;
      if ( v19 >= v14[1] )
        v19 = v14[1];
      v20 = *v13 + (float)(*(v14 - 2) * v19);
      v21 = fsqrt(
              (float)((float)((float)(v16 - (float)(v17 + (float)(*(v14 - 1) * v19)))
                            * (float)(v16 - (float)(v17 + (float)(*(v14 - 1) * v19))))
                    + (float)((float)(v15 - v20) * (float)(v15 - v20)))
            + (float)((float)(v6->z - (float)(v18 + (float)(*v14 * v19)))
                    * (float)(v6->z - (float)(v18 + (float)(*v14 * v19)))));
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
      v13 += 14;
      v14 += 14;
    }
    while ( v11 < v10 );
  }
  *v5 = (float)(v8 * 0.5) * (float)(v8 * 0.5);
  return &v4->pRacePoints[v7];
}

// File Line: 149
// RVA: 0x64CD70
void __fastcall UFG::RaceTrail::Finalize(UFG::RaceTrail *this)
{
  int v1; // eax
  UFG::RaceTrail *v2; // rbx
  int v3; // edx
  float v4; // xmm3_4
  __int64 v5; // rcx
  UFG::RacePoint *v6; // rax
  float v7; // xmm5_4
  __m128 v8; // xmm6
  float v9; // xmm7_4
  __m128 v10; // xmm2
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::RacePoint *v14; // rcx
  signed __int64 v15; // rdx
  float v16; // xmm4_4
  __m128 v17; // xmm5
  float v18; // xmm6_4
  __m128 v19; // xmm2
  float v20; // xmm7_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  UFG::RacePoint *v23; // rdx
  signed __int64 v24; // rcx
  __m128 v25; // xmm4
  float v26; // xmm5_4
  float v27; // xmm2_4
  __m128 v28; // xmm6
  float v29; // xmm1_4
  int v30; // ecx
  UFG::RacePoint *v31; // r8
  signed __int64 v32; // rdx
  signed __int64 v33; // rcx
  float v34; // eax
  float v35; // xmm1_4
  _DWORD *v36; // rcx
  int v37; // xmm0_4
  int v38; // xmm1_4
  signed int v39; // esi
  signed __int64 v40; // rdi
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

  v1 = this->nPoint;
  this->nRacePoints = v1;
  v2 = this;
  v3 = 0;
  v4 = 0.0;
  if ( v1 - 1 > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v2->pRacePoints;
      v8 = (__m128)LODWORD(v6[v5 + 1].vPosition.y);
      v7 = v6[v5 + 1].vPosition.x - v6[v5].vPosition.x;
      v8.m128_f32[0] = v8.m128_f32[0] - v6[v5].vPosition.y;
      v9 = v6[v5 + 1].vPosition.z - v6[v5].vPosition.z;
      v10 = v8;
      v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
      LODWORD(v11) = (unsigned __int128)_mm_sqrt_ps(v10);
      if ( v11 >= 0.0000099999997 )
      {
        v13 = (float)(1.0 / v11) * v9;
        v6[v5].vDirection.x = (float)(1.0 / v11) * v7;
        v6[v5].vDirection.y = (float)(1.0 / v11) * v8.m128_f32[0];
      }
      else
      {
        v12 = UFG::qVector3::msDirFront.y;
        v13 = UFG::qVector3::msDirFront.z;
        v6[v5].vDirection.x = UFG::qVector3::msDirFront.x;
        v6[v5].vDirection.y = v12;
      }
      v6[v5].vDirection.z = v13;
      ++v3;
      ++v5;
      *((float *)&v2->pRacePoints[v5] - 2) = v4;
      v4 = v4 + v11;
      *((float *)&v2->pRacePoints[v5] - 7) = v11;
    }
    while ( v3 < v2->nRacePoints - 1 );
  }
  *((float *)&v2->pRacePoints[v2->nRacePoints] - 2) = v4;
  if ( v2->bIsLoop )
  {
    v14 = v2->pRacePoints;
    v17 = (__m128)LODWORD(v14->vPosition.y);
    v15 = v2->nRacePoints - 1;
    v16 = v14->vPosition.x - v14[v15].vPosition.x;
    v17.m128_f32[0] = v17.m128_f32[0] - v14[v15].vPosition.y;
    v18 = v14->vPosition.z - v14[v15].vPosition.z;
    v19 = v17;
    v19.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16)) + (float)(v18 * v18);
    LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v19);
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
    *((float *)&v2->pRacePoints[v2->nRacePoints] - 7) = v20;
    v23 = v2->pRacePoints;
    v25 = (__m128)LODWORD(v23->vDirection.y);
    v24 = v2->nRacePoints - 1;
    v25.m128_f32[0] = v25.m128_f32[0] + v23[v24].vDirection.y;
    v26 = v23->vDirection.z + v23[v24].vDirection.z;
    v28 = v25;
    v27 = v23[v24].vDirection.x + v23->vDirection.x;
    v28.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v27 * v27)) + (float)(v26 * v26);
    if ( v28.m128_f32[0] == 0.0 )
      v29 = 0.0;
    else
      v29 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v28));
    v23->vDistanceRay.x = v27 * v29;
    v23->vDistanceRay.y = v25.m128_f32[0] * v29;
    v23->vDistanceRay.z = v26 * v29;
  }
  else
  {
    v30 = v2->nRacePoints;
    v31 = v2->pRacePoints;
    v32 = v30 - 2;
    v33 = v30 - 1;
    v34 = v31[v32].vDirection.x;
    v35 = v31[v32].vDirection.z;
    v31[v33].vDirection.y = v31[v32].vDirection.y;
    v31[v33].vDirection.z = v35;
    v31[v33].vDirection.x = v34;
    *((_DWORD *)&v2->pRacePoints[v2->nRacePoints] - 3) = 0;
    *((_DWORD *)&v2->pRacePoints[v2->nRacePoints] - 7) = 0;
    v36 = (_DWORD *)&v2->pRacePoints->vPosition.x;
    v37 = v36[5];
    v38 = v36[6];
    v36[8] = v36[4];
    v36[9] = v37;
    v36[10] = v38;
  }
  v39 = 1;
  v2->fLength = v4;
  if ( v2->nRacePoints > 1 )
  {
    v40 = 1i64;
    do
    {
      v41 = UFG::qSignedAngleBetween(&v2->pRacePoints[v39 - 1].vDirection, &v2->pRacePoints[v39].vDirection);
      v42 = v2->pRacePoints;
      v43 = v41;
      v46 = (__m128)LODWORD(v42[v40].vDirection.y);
      v44 = v42[v40].vDirection.x + *((float *)&v42[v40] - 10);
      v45 = (float)(*((float *)&v42[v40] - 7) + v42[v40].fLength) * 0.5;
      v46.m128_f32[0] = v46.m128_f32[0] + *((float *)&v42[v40] - 9);
      v47 = v42[v40].vDirection.z + *((float *)&v42[v40] - 8);
      if ( v45 <= 1.0 )
      {
        v45 = *(float *)&FLOAT_1_0;
      }
      else if ( v45 >= 25.0 )
      {
        v45 = FLOAT_25_0;
      }
      v48 = v46;
      *((float *)&v42[v40] - 3) = v43 / v45;
      v48.m128_f32[0] = (float)((float)(v46.m128_f32[0] * v46.m128_f32[0]) + (float)(v44 * v44)) + (float)(v47 * v47);
      if ( v48.m128_f32[0] == 0.0 )
        v49 = 0.0;
      else
        v49 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v48));
      v50 = v2->pRacePoints;
      ++v39;
      ++v40;
      *((float *)&v50[v40] - 6) = v44 * v49;
      *((float *)&v50[v40] - 5) = v46.m128_f32[0] * v49;
      *((float *)&v50[v40] - 4) = v47 * v49;
    }
    while ( v39 < v2->nRacePoints );
  }
}

// File Line: 269
// RVA: 0x642D30
void __fastcall UFG::RacePosition::RacePosition(UFG::RacePosition *this, UFG::RaceTrail *race_trail)
{
  UFG::RacePosition *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4

  v2 = this;
  this->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&this->pRaceTrail.mPrev;
  this->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&this->pRaceTrail.mPrev;
  this->pRaceTrail.m_pPointer = 0i64;
  this->pRacePoint = 0i64;
  if ( this->pRaceTrail.m_pPointer )
  {
    v3 = this->pRaceTrail.mPrev;
    v4 = v2->pRaceTrail.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
    v2->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
  }
  v2->pRaceTrail.m_pPointer = race_trail;
  if ( race_trail )
  {
    v5 = race_trail->m_SafePointerList.mNode.mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
    v2->pRaceTrail.mPrev = v5;
    v2->pRaceTrail.mNext = &race_trail->m_SafePointerList.mNode;
    race_trail->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
  }
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  v2->vUpdatePosition.x = UFG::qVector3::msZero.x;
  v2->vUpdatePosition.y = v6;
  v2->vUpdatePosition.z = v7;
  *(_QWORD *)&v2->fUpdateDistanceSq = 0i64;
  *(_QWORD *)&v2->fRaceProximity = 0i64;
  *(_QWORD *)&v2->fRaceTime = 0i64;
}

// File Line: 289
// RVA: 0x651970
void __fastcall UFG::RacePosition::InitPosition(UFG::RacePosition *this, UFG::qVector3 *position)
{
  UFG::qVector3 *v2; // rdi
  UFG::RacePosition *v3; // rbx
  UFG::RaceTrail *v4; // rax
  float v5; // xmm1_4
  float *v6; // rax

  v2 = position;
  v3 = this;
  this->pRacePoint = 0i64;
  this->fRaceDistance = 0.0;
  this->fBonusDistance = 0.0;
  if ( this->pRaceTrail.m_pPointer )
  {
    UFG::RacePosition::UpdateRacePoint(this, position);
    UFG::RacePosition::UpdateRaceDistance(v3, v2);
    v4 = v3->pRaceTrail.m_pPointer;
    if ( v4->bIsLoop )
    {
      v5 = v3->fRaceDistance;
      if ( v5 > (float)(v4->fLength * 0.5) )
        v3->fRaceDistance = v5 - v4->fLength;
    }
    else if ( v3->fRaceDistance <= 0.0 )
    {
      v6 = &v4->pRacePoints->vPosition.x;
      v3->pRacePoint = (UFG::RacePoint *)v6;
      v3->fUpdateDistanceSq = (float)((float)((float)(v2->y - v6[1]) * (float)(v2->y - v6[1]))
                                    + (float)((float)(v2->x - *v6) * (float)(v2->x - *v6)))
                            + (float)((float)(v2->z - v6[2]) * (float)(v2->z - v6[2]));
    }
  }
}

// File Line: 315
// RVA: 0x65F660
void __fastcall UFG::RacePosition::Update(UFG::RacePosition *this, UFG::qVector3 *position, float delta_seconds)
{
  UFG::RacePoint *v3; // rsi
  float v4; // xmm1_4
  UFG::qVector3 *v5; // rbx
  UFG::RacePosition *v6; // rdi
  float *v7; // rax

  v3 = this->pRacePoint;
  v4 = this->fCountDownTime - delta_seconds;
  v5 = position;
  v6 = this;
  this->fRaceTime = delta_seconds + this->fRaceTime;
  this->fCountDownTime = v4;
  UFG::RacePosition::UpdateRacePoint(this, position);
  UFG::RacePosition::UpdateRaceDistance(v6, v5);
  if ( v3 )
  {
    v7 = &v6->pRacePoint->vPosition.x;
    if ( v7 != (float *)v3 && v6->fBonusDistance <= v6->fRaceDistance )
    {
      v6->fBonusDistance = v7[12] + v7[7];
      v6->fCountDownTime = v7[13] + v6->fCountDownTime;
    }
  }
}

// File Line: 337
// RVA: 0x663450
void __fastcall UFG::RacePosition::UpdateRacePoint(UFG::RacePosition *this, UFG::qVector3 *position)
{
  UFG::qVector3 *v2; // rdi
  UFG::RacePosition *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4

  v2 = position;
  v3 = this;
  if ( !this->pRacePoint
    || (float)((float)((float)((float)(position->y - this->vUpdatePosition.y)
                             * (float)(position->y - this->vUpdatePosition.y))
                     + (float)((float)(position->x - this->vUpdatePosition.x)
                             * (float)(position->x - this->vUpdatePosition.x)))
             + (float)((float)(position->z - this->vUpdatePosition.z) * (float)(position->z - this->vUpdatePosition.z))) > this->fUpdateDistanceSq )
  {
    this->pRacePoint = UFG::RaceTrail::GetRacePoint(this->pRaceTrail.m_pPointer, position, &this->fUpdateDistanceSq);
    v4 = v2->y;
    v5 = v2->z;
    v3->vUpdatePosition.x = v2->x;
    v3->vUpdatePosition.y = v4;
    v3->vUpdatePosition.z = v5;
  }
}

// File Line: 347
// RVA: 0x663150
void __fastcall UFG::RacePosition::UpdateRaceDistance(UFG::RacePosition *this, UFG::qVector3 *position)
{
  UFG::RaceTrail *v2; // rdi
  UFG::RacePoint *v3; // rbx
  UFG::qVector3 *v4; // rbp
  UFG::RacePosition *v5; // rsi
  UFG::RacePoint *v6; // rcx
  int v7; // eax
  int v8; // edx
  float *v9; // r14
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  bool v15; // dl
  UFG::RacePoint *v16; // rcx
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  __m128 v22; // xmm2
  float v23; // xmm1_4
  float v24; // xmm6_4

  v2 = this->pRaceTrail.m_pPointer;
  v3 = this->pRacePoint;
  v4 = position;
  v5 = this;
  v6 = v2->pRacePoints;
  v7 = v2->nRacePoints;
  v8 = ((unsigned __int64)((unsigned __int128)(((char *)v3 - (char *)v6) * (signed __int128)5270498306774157605i64) >> 64) >> 63)
     + ((signed __int64)((unsigned __int128)(((char *)v3 - (char *)v6) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
     + 1;
  if ( v8 >= v7 )
  {
    if ( v2->bIsLoop )
      v8 = 0;
    else
      v8 = v7 - 1;
  }
  v9 = &v6[v8].vPosition.x;
  v10 = (float)((float)((float)(v4->y - v3->vPosition.y) * v3->vDistanceRay.y)
              + (float)((float)(v4->x - v3->vPosition.x) * v3->vDistanceRay.x))
      + (float)((float)(v4->z - v3->vPosition.z) * v3->vDistanceRay.z);
  v11 = (float)((float)((float)(v4->x - (float)((float)(v3->fLength * v3->vDirection.x) + v3->vPosition.x)) * v9[8])
              + (float)((float)(v4->y - (float)((float)(v3->fLength * v3->vDirection.y) + v3->vPosition.y)) * v9[9]))
      + (float)((float)(v4->z - (float)((float)(v3->fLength * v3->vDirection.z) + v3->vPosition.z)) * v9[10]);
  if ( v10 >= 0.0 )
    v12 = (float)((float)((float)(v4->y - v3->vPosition.y) * v3->vDistanceRay.y)
                + (float)((float)(v4->x - v3->vPosition.x) * v3->vDistanceRay.x))
        + (float)((float)(v4->z - v3->vPosition.z) * v3->vDistanceRay.z);
  else
    v12 = 0.0;
  if ( v11 <= 0.0 )
    v13 = (float)((float)((float)(v4->x - (float)((float)(v3->fLength * v3->vDirection.x) + v3->vPosition.x)) * v9[8])
                + (float)((float)(v4->y - (float)((float)(v3->fLength * v3->vDirection.y) + v3->vPosition.y)) * v9[9]))
        + (float)((float)(v4->z - (float)((float)(v3->fLength * v3->vDirection.z) + v3->vPosition.z)) * v9[10]);
  else
    v13 = 0.0;
  if ( (float)(v12 - v13) >= 0.001 )
    v14 = v12 / (float)(v12 - v13);
  else
    v14 = FLOAT_0_5;
  v5->fRaceProximity = UFG::RacePoint::GetSegmentDistance(v3, v4);
  v15 = v2->bIsLoop;
  if ( !v15 )
  {
    v16 = v2->pRacePoints;
    if ( v3 != v16 || v10 >= 0.0 )
    {
      if ( v3 != &v16[v2->nRacePoints - 1] || v11 <= 0.0 )
        goto LABEL_30;
      if ( v11 >= 60.0 )
        v11 = FLOAT_60_0;
      v21 = v3->fLength;
      if ( v21 > 0.001 )
        v14 = v11 / v21;
      v19 = v4->x - (float)((float)((float)(v21 * v3->vDirection.x) + v3->vPosition.x) + (float)(v10 * v9[8]));
      v18 = (float)((float)(v21 * v3->vDirection.y) + v3->vPosition.y) + (float)(v10 * v9[9]);
      v20 = v4->z - (float)((float)((float)(v21 * v3->vDirection.z) + v3->vPosition.z) + (float)(v10 * v9[10]));
    }
    else
    {
      if ( v10 <= -40.0 )
        v10 = FLOAT_N40_0;
      v17 = v3->fLength;
      if ( v17 > 0.001 )
        v14 = v10 / v17;
      v18 = (float)(v10 * v3->vDistanceRay.y) + v3->vPosition.y;
      v19 = v4->x - (float)((float)(v10 * v3->vDistanceRay.x) + v3->vPosition.x);
      v20 = v4->z - (float)((float)(v10 * v3->vDistanceRay.z) + v3->vPosition.z);
    }
    v22 = (__m128)LODWORD(v4->y);
    v22.m128_f32[0] = (float)((float)((float)(v22.m128_f32[0] - v18) * (float)(v22.m128_f32[0] - v18))
                            + (float)(v19 * v19))
                    + (float)(v20 * v20);
    LODWORD(v5->fRaceProximity) = (unsigned __int128)_mm_sqrt_ps(v22);
  }
LABEL_30:
  v23 = v2->fLength;
  v24 = (float)(v14 * v3->fLength) + v3->fRaceDistance;
  v5->fRaceDistance = v24;
  if ( v15 )
    v5->fRaceDistance = UFG::qSignedMod(v24, v23);
}

// File Line: 385
// RVA: 0x64EFA0
signed __int64 __fastcall UFG::RacePosition::GetRaceIndex(UFG::RacePosition *this)
{
  UFG::RaceTrail *v1; // rax
  signed __int64 result; // rax

  v1 = this->pRaceTrail.m_pPointer;
  if ( v1 )
    result = (unsigned int)v1->mRaceIndex;
  else
    result = 0xFFFFFFFFi64;
  return result;
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
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm9_4
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
  v10 = this->fRadius[3 * (exit + 3i64)];
  v11 = this->fRadius[3 * (exit + 3i64) + 1];
  v12 = *((float *)&this->nUid + 3 * (exit + 3i64));
  v13 = (float)((float)(v12 * v5) + (float)(v10 * v6)) + (float)(v11 * v7);
  v14 = (float)((float)(v12 * v9) + (float)(v10 * v4)) + (float)(v11 * v8);
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
  UFG::RaceManager *v1; // rbx
  UFG::RaceTrail **v2; // rax
  signed __int64 v3; // rcx
  UFG::TimeTrial *v4; // rax
  signed __int64 v5; // rcx

  v1 = this;
  UFG::TSActor::TSActor((UFG::TSActor *)&this->vfptr, &UFG::RaceManager::mClass->i_name, UFG::RaceManager::mClass);
  v1->vfptr = (SSObjectBaseVtbl *)&UFG::RaceManager::`vftable;
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
    ++v1;
    if ( (signed __int64)v1 >= (signed __int64)&UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame )
      return 0i64;
  }
  return *v1;
}

// File Line: 507
// RVA: 0x64F1F0
UFG::RaceTrail *__fastcall UFG::RaceManager::GetRaceTrail(int index)
{
  int v1; // eax
  UFG::RaceTrail *result; // rax

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
    result = UFG::RaceManager::aRaceTrails[index];
  else
    result = 0i64;
  return result;
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
      (*v0)->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::RaceTrail> *)&(*v0)->vfptr, 1u);
      *v0 = 0i64;
    }
    ++v0;
  }
  while ( (signed __int64)v0 < (signed __int64)UFG::RaceManager::aTimeTrials );
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
  while ( (signed __int64)v1 < (signed __int64)&UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame );
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
  UFG::RaceManager::mClass = (SSActorClass *)SSBrain::get_class("RaceManager");
  SSClass::register_method_func(
    (SSClass *)&UFG::RaceManager::mClass->vfptr,
    "time_trial",
    UFG::RaceManager::MthdC_time_trial,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::RaceManager::mClass->vfptr,
    "race_release",
    UFG::RaceManager::MthdC_race_release,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::RaceManager::mClass->vfptr,
    "race_release_trail",
    UFG::RaceManager::MthdC_race_release_trail,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::RaceManager::mClass->vfptr,
    "race_allocate",
    UFG::RaceManager::MthdC_race_allocate,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::RaceManager::mClass->vfptr,
    "race_finalize",
    UFG::RaceManager::MthdC_race_finalize,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::RaceManager::mClass->vfptr,
    "race_add_xform",
    UFG::RaceManager::MthdC_race_add_xform,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::RaceManager::mClass->vfptr,
    "race_set_is_loop",
    UFG::RaceManager::MthdC_race_set_is_loop,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::RaceManager::mClass->vfptr,
    "race_set_num_laps",
    UFG::RaceManager::MthdC_race_set_num_laps,
    1,
    0);
}

// File Line: 585
// RVA: 0x65E960
char __fastcall UFG::RaceManager::TimeTrialEntered(UFG::qVector3 *p0, UFG::qVector3 *p1, unsigned int *p_uid, unsigned int *p_exit)
{
  unsigned int *v4; // rsi
  UFG::qVector3 *v5; // rbx
  UFG::qVector3 *v6; // rdi
  UFG::TimeTrial **v7; // r10
  UFG::TimeTrial *v8; // r11
  int v9; // er8
  float *v10; // rdx
  float *v11; // rcx
  signed __int64 v12; // rax
  float v13; // xmm10_4
  float v14; // xmm5_4
  float v15; // xmm11_4
  float v16; // xmm7_4
  float v17; // xmm4_4
  float v18; // xmm8_4
  float v19; // xmm9_4
  float v20; // xmm6_4
  float v21; // xmm0_4

  v4 = p_uid;
  v5 = p1;
  v6 = p0;
  v7 = UFG::RaceManager::aTimeTrials;
  while ( 1 )
  {
    v8 = *v7;
    if ( *v7 )
      break;
LABEL_9:
    ++v7;
    if ( (signed __int64)v7 >= (signed __int64)&UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame )
      return 0;
  }
  v9 = 0;
  v10 = v8->fRadius;
  v11 = &v8->vPosition[0].z;
  v12 = 0i64;
  while ( 1 )
  {
    v13 = v6->x - *(v11 - 2);
    v14 = v6->y - *(v11 - 1);
    v15 = v6->z - *v11;
    v16 = v5->x - *(v11 - 2);
    v17 = v5->y - *(v11 - 1);
    v18 = v5->z - *v11;
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
  *v4 = v8->nUid;
  return 1;
}

// File Line: 600
// RVA: 0x652C00
void __fastcall UFG::RaceManager::MthdC_race_allocate(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r14
  unsigned int v3; // ebp
  SSInstance *v4; // rdi
  int v5; // ebx
  UFG::RaceTrail **v6; // rax
  int v7; // esi
  UFG::allocator::free_link *v8; // rax
  UFG::RaceTrail *v9; // rax
  UFG::RaceTrail *v10; // rcx
  SSClass *v11; // rsi
  AObjReusePool<SSInstance> *v12; // rax
  AObjReusePool<SSInstance> *v13; // rbx
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  __int64 v17; // rcx
  SSInstance **v18; // rax
  unsigned int v19; // eax

  v2 = ppResult;
  v3 = -1;
  v4 = 0i64;
  v5 = 0;
  v6 = UFG::RaceManager::aRaceTrails;
  while ( *v6 )
  {
    ++v5;
    ++v6;
    if ( (signed __int64)v6 >= (signed __int64)UFG::RaceManager::aTimeTrials )
      goto LABEL_9;
  }
  v3 = v5;
  v7 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v8 = UFG::qMalloc(0x38ui64, "RaceTrail", 0i64);
  if ( v8 )
  {
    UFG::RaceTrail::RaceTrail((UFG::RaceTrail *)v8, v7, v5);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  UFG::RaceManager::aRaceTrails[v5] = v10;
LABEL_9:
  v11 = SSBrain::c_integer_class_p;
  v12 = SSInstance::get_pool();
  v13 = v12;
  v14 = v12->i_pool.i_count;
  if ( v14 )
  {
    v19 = v14 - 1;
    v13->i_pool.i_count = v19;
    v17 = v19;
    v18 = v13->i_pool.i_array_p;
    goto LABEL_15;
  }
  if ( !v13->i_exp_pool.i_count )
    AObjReusePool<SSInstance>::append_block(v13, v13->i_expand_size);
  v15 = v13->i_exp_pool.i_count;
  if ( v15 )
  {
    v16 = v15 - 1;
    v13->i_exp_pool.i_count = v16;
    v17 = v16;
    v18 = v13->i_exp_pool.i_array_p;
LABEL_15:
    v4 = v18[v17];
  }
  v4->i_class_p = v11;
  v4->i_user_data = v3;
  v4->i_ref_count = 1;
  v4->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  *v2 = v4;
}

// File Line: 617
// RVA: 0x652D60
void __fastcall UFG::RaceManager::MthdC_race_release(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RaceManager::Release();
}

// File Line: 622
// RVA: 0x652D70
void __fastcall UFG::RaceManager::MthdC_race_release_trail(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int v2; // ecx
  int v3; // eax
  UFG::RaceTrail **v4; // rbx

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = 0;
  while ( v3 != v2 )
  {
    if ( ++v3 >= 64 )
      return;
  }
  v4 = &UFG::RaceManager::aRaceTrails[v3];
  if ( *v4 )
  {
    (*v4)->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::RaceTrail> *)&(*v4)->vfptr, 1u);
    *v4 = 0i64;
  }
}

// File Line: 628
// RVA: 0x652D20
void __fastcall UFG::RaceManager::MthdC_race_finalize(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  __int64 v2; // rcx
  signed int v3; // eax

  v2 = SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( (signed int)v2 <= 0 )
  {
    v3 = 0;
  }
  else
  {
    v3 = v2;
    if ( (signed int)v2 >= 63 )
      v3 = 63;
  }
  if ( (_DWORD)v2 == v3 )
    JUMPOUT(UFG::RaceManager::aRaceTrails[v2], 0i64, UFG::RaceTrail::Finalize);
}

// File Line: 635
// RVA: 0x652B50
void __fastcall UFG::RaceManager::MthdC_race_add_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  float v3; // xmm6_4
  float v4; // xmm7_4
  unsigned __int64 v5; // rdi
  __int64 v6; // rax
  signed int v7; // ecx
  UFG::RaceTrail *v8; // rbx

  v2 = pScope->i_data.i_array_p;
  v3 = *(float *)&v2[2]->i_data_p->i_user_data;
  v4 = *(float *)&v2[3]->i_data_p->i_user_data;
  v5 = v2[1]->i_data_p->i_user_data;
  v6 = SLODWORD((*v2)->i_data_p->i_user_data);
  if ( (signed int)v6 <= 0 )
  {
    v7 = 0;
  }
  else
  {
    v7 = v6;
    if ( (signed int)v6 >= 63 )
      v7 = 63;
  }
  if ( (_DWORD)v6 == v7 )
  {
    v8 = UFG::RaceManager::aRaceTrails[v6];
    if ( v8 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5);
      UFG::RaceTrail::AddRacePoint(v8, (UFG::qVector3 *)(v5 + 176), v3 * 0.27777779, v4);
    }
  }
}

// File Line: 648
// RVA: 0x652DD0
void __fastcall UFG::RaceManager::MthdC_race_set_is_loop(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  __int64 v3; // rax
  signed int v4; // ecx
  UFG::RaceTrail *v5; // rdx

  v2 = pScope->i_data.i_array_p;
  v3 = SLODWORD((*v2)->i_data_p->i_user_data);
  if ( (signed int)v3 <= 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = v3;
    if ( (signed int)v3 >= 63 )
      v4 = 63;
  }
  if ( (_DWORD)v3 == v4 )
  {
    v5 = UFG::RaceManager::aRaceTrails[v3];
    if ( v5 )
      v5->bIsLoop = v2[1]->i_data_p->i_user_data != 0;
  }
}

// File Line: 656
// RVA: 0x652E20
void __fastcall UFG::RaceManager::MthdC_race_set_num_laps(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  __int64 v3; // rax
  signed int v4; // ecx
  UFG::RaceTrail *v5; // rdx

  v2 = pScope->i_data.i_array_p;
  v3 = SLODWORD((*v2)->i_data_p->i_user_data);
  if ( (signed int)v3 <= 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = v3;
    if ( (signed int)v3 >= 63 )
      v4 = 63;
  }
  if ( (_DWORD)v3 == v4 )
  {
    v5 = UFG::RaceManager::aRaceTrails[v3];
    if ( v5 )
      v5->nLaps = v2[1]->i_data_p->i_user_data;
  }
}

// File Line: 664
// RVA: 0x652FA0
void __fastcall UFG::RaceManager::MthdC_time_trial(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r15
  int v3; // ebx
  UFG::TimeTrial **v4; // rax
  SSData **v5; // rdx
  SSInstance *v6; // rsi
  unsigned __int64 v7; // rbp
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

  v2 = pScope;
  v3 = 0;
  v4 = UFG::RaceManager::aTimeTrials;
  while ( *v4 )
  {
    ++v3;
    ++v4;
    if ( (signed __int64)v4 >= (signed __int64)&UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame )
      return;
  }
  v5 = pScope->i_data.i_array_p;
  v6 = (*v5)->i_data_p;
  v7 = v5[1]->i_data_p->i_user_data;
  v8 = v5[3]->i_data_p->i_user_data;
  v9 = UFG::qMalloc(0x3Cui64, "TimeTrial", 0i64);
  v10 = v9;
  if ( v9 )
    LODWORD(v9->mNext) = v6->i_user_data;
  else
    v10 = 0i64;
  UFG::RaceManager::aTimeTrials[v3] = (UFG::TimeTrial *)v10;
  v11 = v2->i_data.i_array_p;
  HIDWORD(v10->mNext) = v11[2]->i_data_p->i_user_data;
  LODWORD(v10[1].mNext) = v11[4]->i_data_p->i_user_data;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
  v12 = *(_DWORD *)(v7 + 180);
  v13 = *(_DWORD *)(v7 + 184);
  HIDWORD(v10[1].mNext) = *(_DWORD *)(v7 + 176);
  LODWORD(v10[2].mNext) = v12;
  HIDWORD(v10[2].mNext) = v13;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8);
  v14 = *(_DWORD *)(v8 + 180);
  v15 = *(_DWORD *)(v8 + 184);
  LODWORD(v10[3].mNext) = *(_DWORD *)(v8 + 176);
  HIDWORD(v10[3].mNext) = v14;
  LODWORD(v10[4].mNext) = v15;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
  v16 = *(_DWORD *)(v7 + 132);
  v17 = *(_DWORD *)(v7 + 136);
  HIDWORD(v10[4].mNext) = *(_DWORD *)(v7 + 128);
  LODWORD(v10[5].mNext) = v16;
  HIDWORD(v10[5].mNext) = v17;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8);
  v18 = *(_DWORD *)(v8 + 132);
  v19 = *(_DWORD *)(v8 + 136);
  LODWORD(v10[6].mNext) = *(_DWORD *)(v8 + 128);
  HIDWORD(v10[6].mNext) = v18;
  LODWORD(v10[7].mNext) = v19;
}

