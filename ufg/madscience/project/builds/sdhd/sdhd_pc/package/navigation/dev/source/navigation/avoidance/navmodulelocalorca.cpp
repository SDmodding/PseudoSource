// File Line: 25
// RVA: 0xF62B0
void __fastcall UFG::NavModuleLocalORCA::NavModuleLocalORCA(UFG::NavModuleLocalORCA *this, UFG::NavComponent *parent)
{
  UFG::NavModuleLocalORCA *v2; // rbx
  UFG::Ticket *v3; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::NavModuleLocal::NavModuleLocal((UFG::NavModuleLocal *)&this->vfptr, parent);
  v2->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocalORCA::`vftable;
  v2->mpStrategy = 0i64;
  *(_QWORD *)&v2->mIndex = 0i64;
  v2->mStuckWaitTimer = 0.0;
  v3 = &v2->mGatherObstaclesTicket;
  v3->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v3->mPrev;
  v2->mGatherObstaclesTicket.mTimestamp = 0i64;
  v2->mGatherObstaclesTicket.mActiveCallback.m_Closure.m_pthis = 0i64;
  v2->mGatherObstaclesTicket.mActiveCallback.m_Closure.m_pFunction = 0i64;
  v2->mGatherObstaclesTicket.mInactiveCallback.m_Closure.m_pthis = 0i64;
  v2->mGatherObstaclesTicket.mInactiveCallback.m_Closure.m_pFunction = 0i64;
}

// File Line: 47
// RVA: 0xF6C20
void __fastcall UFG::NavModuleLocalORCA::Init(UFG::NavModuleLocalORCA *this, UFG::NavAvoidanceStrategyORCA *pStrategy)
{
  RVO::RVOSimulator *v2; // rbx
  UFG::NavModuleLocalORCA *v3; // rdi
  UFG::qVector4 *v4; // rax
  UFG::NavAvoidanceStrategyORCA *v5; // rcx
  __int64 v6; // rdx
  __int64 v7; // r9
  float v8; // xmm0_4
  UFG::NavModuleLocalORCA *v9; // [rsp+20h] [rbp-18h]
  __int64 (__fastcall *v10)(__int64); // [rsp+28h] [rbp-10h]

  this->mpStrategy = pStrategy;
  v2 = pStrategy->mpSimulator;
  v3 = this;
  v4 = UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  v5 = v3->mpStrategy;
  v6 = v5->mNumActiveIndexes;
  v7 = (signed int)v5->mIndexes[v6];
  v5->mNumActiveIndexes = v6 + 1;
  v5->mpSimulator->agents_._Myfirst[(unsigned int)v7]->enabled = 1;
  v3->mIndex = v7;
  v2->agents_._Myfirst[v7]->position_ = *(RVO::Vector2 *)&v4->x;
  v8 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
  v3->mStuckWaitTimer = 0.0;
  v3->mWiggleRandomRange = v8;
  v10 =  UFG::NavModuleLocalORCA::`vcall{96,{flat}};
  v9 = v3;
  UFG::TicketBoothManager::Register(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_NAVLOCAL_GATHEROBSTACLE,
    &v3->mGatherObstaclesTicket,
    (fastdelegate::FastDelegate1<float,void> *)&v9);
}

// File Line: 63
// RVA: 0xF63A0
void __fastcall UFG::NavModuleLocalORCA::~NavModuleLocalORCA(UFG::NavModuleLocalORCA *this)
{
  UFG::NavModuleLocalORCA *v1; // rdi
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v2; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v3; // rax

  v1 = this;
  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocalORCA::`vftable;
  UFG::NavAvoidanceStrategyORCA::ReturnAgentIndex(this->mpStrategy, this->mIndex);
  UFG::TicketBoothManager::Unregister(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_NAVLOCAL_GATHEROBSTACLE,
    &v1->mGatherObstaclesTicket);
  v2 = v1->mGatherObstaclesTicket.mPrev;
  v3 = v1->mGatherObstaclesTicket.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mGatherObstaclesTicket.mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v1->mGatherObstaclesTicket.mPrev;
  v1->mGatherObstaclesTicket.mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v1->mGatherObstaclesTicket.mPrev;
  v1->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocal::`vftable;
  _((AMD_HD3D *)&v1->m_adjustedWaypoint);
}

// File Line: 70
// RVA: 0xF6D30
void __fastcall UFG::NavModuleLocalORCA::Reset(UFG::NavModuleLocalORCA *this)
{
  UFG::NavModuleLocalORCA *v1; // rbx

  v1 = this;
  UFG::NavModuleLocal::Reset((UFG::NavModuleLocal *)&this->vfptr);
  v1->mStuckWaitTimer = 0.0;
}

// File Line: 76
// RVA: 0xF7290
void __fastcall UFG::NavModuleLocalORCA::UpdateAvoidanceProperties(UFG::NavModuleLocalORCA *this)
{
  float v1; // xmm0_4
  RVO::RVOSimulator *v2; // rdi
  UFG::NavModuleLocalORCA *v3; // rbx
  bool v4; // al
  __int64 v5; // rcx
  bool v6; // zf
  RVO::Agent **v7; // rax

  v1 = sORCANeighborDist;
  v2 = this->mpStrategy->mpSimulator;
  v3 = this;
  v2->agents_._Myfirst[this->mIndex]->maxNeighbors_ = sORCAMaxNeighbors;
  v2->agents_._Myfirst[this->mIndex]->neighborDist_ = v1;
  v2->agents_._Myfirst[this->mIndex]->timeHorizon_ = sORCATimeHorizon;
  v2->agents_._Myfirst[this->mIndex]->timeHorizonObst_ = sORCATimeHorizonObst;
  v4 = UFG::NavModuleLocal::IsAvoidanceEnabled((UFG::NavModuleLocal *)&this->vfptr);
  v5 = v3->mIndex;
  v6 = v4 == 0;
  v7 = v2->agents_._Myfirst;
  if ( v6 )
    v7[v5]->maxSpeed_ = 999.0;
  else
    v7[v5]->maxSpeed_ = sORCAMaxSpeed;
}

// File Line: 118
// RVA: 0xF6EB0
void __fastcall UFG::NavModuleLocalORCA::Update(UFG::NavModuleLocalORCA *this, float dt)
{
  UFG::NavModuleLocalORCA *v2; // rbx
  RVO::Agent *v3; // rcx
  float v4; // xmm8_4
  float v5; // xmm9_4
  __int128 v6; // xmm7
  float v7; // xmm6_4
  RVO::Vector2 v8; // rax
  float v9; // xmm14_4
  float v10; // xmm6_4
  __m128 v11; // xmm2
  float v12; // xmm1_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm11_4
  float v16; // xmm12_4
  float v17; // xmm14_4
  float v18; // xmm13_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  bool v23; // cf
  UFG::qVector3 source; // [rsp+20h] [rbp-B8h]
  UFG::qVector3 dest; // [rsp+30h] [rbp-A8h]
  float v26; // [rsp+E8h] [rbp+10h]

  v26 = dt;
  v2 = this;
  v3 = this->mpStrategy->mpSimulator->agents_._Myfirst[this->mIndex];
  v4 = v3->prefVelocity_.x_;
  v5 = v3->prefVelocity_.y_;
  if ( v3->resolved_ )
  {
    v6 = (unsigned int)(*(_QWORD *)&v3->velocity_ >> 32);
    LODWORD(v7) = v3->velocity_;
  }
  else
  {
    if ( sORCAEnableFallbackVelocity )
      v8 = v3->fallbackVelocity_;
    else
      v8 = v3->prefVelocity_;
    v6 = LODWORD(v8.y_);
    v7 = v8.x_ * sORCAFallbackVelocityRatio;
    *(float *)&v6 = v8.y_ * sORCAFallbackVelocityRatio;
  }
  source.x = v7;
  LODWORD(source.y) = v6;
  source.z = 0.0;
  v9 = sORCALocalLerpWeight * 0.0;
  *(float *)&v6 = (float)((float)(*(float *)&v6 - v3->inVelocity_.y_) * sORCALocalLerpWeight) + v3->inVelocity_.y_;
  v10 = (float)((float)(v7 - v3->inVelocity_.x_) * sORCALocalLerpWeight) + v3->inVelocity_.x_;
  dest.z = sORCALocalLerpWeight * 0.0;
  v11 = (__m128)v6;
  dest.x = v10;
  LODWORD(dest.y) = v6;
  v11.m128_f32[0] = (float)((float)(*(float *)&v6 * *(float *)&v6) + (float)(v10 * v10)) + (float)(v9 * v9);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  v13 = v10 * v12;
  v14 = *(float *)&v6 * v12;
  v15 = v13;
  v16 = v14;
  LODWORD(v2->m_fAdjustedSpeed) = (unsigned __int128)_mm_sqrt_ps(v11);
  v17 = v9 * v12;
  v18 = v17;
  v19 = (float)((float)(v14 * v5) + (float)(v13 * v4)) + (float)(v17 * 0.0);
  if ( v19 < 0.0 )
  {
    v18 = (float)(v19 * -0.0) + v17;
    v15 = (float)(COERCE_FLOAT(LODWORD(v4) ^ _xmm[0]) * v19) + v13;
    v16 = (float)(COERCE_FLOAT(LODWORD(v5) ^ _xmm[0]) * v19) + v14;
  }
  if ( v2->vfptr->IsStuck((UFG::NavModuleLocal *)&v2->vfptr) )
  {
    if ( sORCAFallbackWiggle )
      UFG::qRotateVectorZ(
        &dest,
        &source,
        (float)((float)((float)((float)((float)(sORCAResolveWiggleRange * v2->mWiggleRandomRange)
                                      + sORCAResolveWiggleAngle)
                              * 3.1415927)
                      * 0.0055555557)
              * (float)((float)(UFG::Metrics::msRealTimeSineWave * 2.0) - 1.0))
      + (float)((float)(sORCAResolveOffCenterAngle * 3.1415927) * 0.0055555557));
    v20 = v2->mStuckWaitTimer;
    if ( v20 > 0.0 )
    {
      v22 = v20 - v26;
      v2->mStuckWaitTimer = v22;
      if ( v22 <= 0.0 )
        LODWORD(v2->mStuckWaitTimer) = COERCE_UNSIGNED_INT(
                                         (float)(UFG::qRandom(s_StuckRandomRetryTime, &UFG::qDefaultSeed)
                                               + s_StuckBaseRetryTime)
                                       + s_StuckTransitionBufferTime) ^ _xmm[0];
      v2->m_fAdjustedSpeed = 0.0;
    }
    else
    {
      v21 = v20 + v26;
      v2->mStuckWaitTimer = v21;
      if ( v21 >= 0.0 )
        v2->mStuckWaitTimer = (float)(UFG::qRandom(s_StuckRandomWaitTime, &UFG::qDefaultSeed)
                                    + s_StuckTransitionBufferTime)
                            + s_StuckBaseWaitTime;
    }
  }
  else
  {
    v2->mStuckWaitTimer = 0.0;
  }
  v23 = v2->m_fAdjustedSpeed > 0.0;
  v2->m_steerData.m_vDesiredDirection.x = v4;
  v2->m_steerData.m_vDesiredDirection.y = v5;
  v2->m_steerData.m_vDesiredDirection.z = 0.0;
  if ( v23 )
  {
    v2->m_steerData.m_vClampedDirection.x = v15;
    v2->m_steerData.m_vClampedDirection.y = v16;
    v2->m_steerData.m_vClampedDirection.z = v18;
    v2->m_steerData.m_vLocalDirection.x = v13;
    v2->m_steerData.m_vLocalDirection.y = v14;
    v2->m_steerData.m_vLocalDirection.z = v17;
    v2->m_steerData.m_fLocalSpeed = v2->m_fAdjustedSpeed;
  }
  else
  {
    v2->m_steerData.m_vClampedDirection.x = v4;
    v2->m_steerData.m_vClampedDirection.y = v5;
    v2->m_steerData.m_vClampedDirection.z = 0.0;
    *(_QWORD *)&v2->m_steerData.m_vLocalDirection.z = 0i64;
    v2->m_steerData.m_vLocalDirection.x = v4;
    v2->m_steerData.m_vLocalDirection.y = v5;
  }
}

// File Line: 218
// RVA: 0xF66E0
void __fastcall UFG::NavModuleLocalORCA::GatherAgents(UFG::NavModuleLocalORCA *this)
{
  UFG::NavModuleLocalORCA *v1; // rbx
  RVO::RVOSimulator *v2; // rdi
  RVO::Agent *v3; // r14
  signed int v4; // esi
  __int64 v5; // rax
  __int64 v6; // rbx
  RVO::Agent *v7; // rdx
  float rangeSq; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = this->mpStrategy->mpSimulator;
  v3 = v2->agents_._Myfirst[this->mIndex];
  UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  v3->agentNeighbors_._Mylast = v3->agentNeighbors_._Myfirst;
  if ( UFG::NavModuleLocal::IsAvoidanceEnabled((UFG::NavModuleLocal *)&v1->vfptr) )
  {
    if ( v3->maxNeighbors_ )
    {
      v4 = 0;
      v5 = (_QWORD)((char *)v2->agents_._Mylast - (char *)v2->agents_._Myfirst) >> 3;
      rangeSq = v3->neighborDist_ * v3->neighborDist_;
      if ( (signed int)v5 > 0 )
      {
        v6 = 0i64;
        do
        {
          v7 = v2->agents_._Myfirst[v6];
          if ( v7->enabled )
            RVO::Agent::insertAgentNeighbor(v3, v7, &rangeSq);
          ++v4;
          ++v6;
        }
        while ( v4 < (signed int)((_QWORD)((char *)v2->agents_._Mylast - (char *)v2->agents_._Myfirst) >> 3) );
      }
    }
  }
}

// File Line: 248
// RVA: 0xF67B0
void __fastcall UFG::NavModuleLocalORCA::GatherObstacles(UFG::NavModuleLocalORCA *this, float deltaTime)
{
  UFG::NavModuleLocalORCA *v2; // r15
  RVO::Agent *v3; // r14
  UFG::qVector4 *v4; // rax
  float v5; // xmm1_4
  unsigned __int64 v6; // rdi
  __int64 v7; // rbx
  RVO::Obstacle *v8; // rcx
  RVO::Obstacle *v9; // rsi
  hkVector4f *v10; // rbx
  hkaiStreamingCollection::InstanceInfo *v11; // rsi
  hkVector4f *v12; // rax
  unsigned int v13; // er15
  hkVector4f *position; // rdi
  __m128 v15; // xmm1
  int v16; // er15
  __int64 v17; // rsi
  int v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  RVO::Vector2 *v21; // rbx
  RVO::Vector2 *v22; // rax
  float v23; // xmm6_4
  RVO::Vector2 *v24; // rax
  char *v25; // rax
  RVO::Obstacle *v26; // rbx
  char *v27; // rax
  char *v28; // rdi
  RVO::Vector2 *v29; // rax
  RVO::Vector2 *v30; // rax
  char *array; // [rsp+40h] [rbp-69h]
  int v32; // [rsp+48h] [rbp-61h]
  int v33; // [rsp+4Ch] [rbp-5Dh]
  RVO::Vector2 vector; // [rsp+50h] [rbp-59h]
  char *v35; // [rsp+58h] [rbp-51h]
  RVO::Vector2 v36; // [rsp+60h] [rbp-49h]
  RVO::Vector2 v37; // [rsp+68h] [rbp-41h]
  RVO::Vector2 v38; // [rsp+70h] [rbp-39h]
  __int64 v39; // [rsp+78h] [rbp-31h]
  RVO::Vector2 v40; // [rsp+80h] [rbp-29h]
  RVO::Vector2 v41; // [rsp+88h] [rbp-21h]
  RVO::Vector2 v42; // [rsp+90h] [rbp-19h]
  RVO::Vector2 v43; // [rsp+98h] [rbp-11h]
  hkAabb aabb; // [rsp+A0h] [rbp-9h]
  hkResult result; // [rsp+110h] [rbp+67h]
  int v46; // [rsp+114h] [rbp+6Bh]
  RVO::Vector2 v47; // [rsp+120h] [rbp+77h]
  hkaiAgentTraversalInfo traversalInfo; // [rsp+128h] [rbp+7Fh]

  v39 = -2i64;
  v2 = this;
  v3 = this->mpStrategy->mpSimulator->agents_._Myfirst[this->mIndex];
  v4 = UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  v5 = v4->y;
  vector.x_ = v4->x;
  vector.y_ = v5;
  v6 = 0i64;
  if ( (_QWORD)((char *)v3->obstacleNeighbors_._Mylast - (char *)v3->obstacleNeighbors_._Myfirst) >> 4 )
  {
    v7 = 0i64;
    do
    {
      v8 = v3->obstacleNeighbors_._Myfirst[v7].second;
      v9 = v8->nextObstacle;
      operator delete[](v8);
      if ( v9 )
        operator delete[](v9);
      ++v6;
      ++v7;
    }
    while ( v6 < (_QWORD)((char *)v3->obstacleNeighbors_._Mylast - (char *)v3->obstacleNeighbors_._Myfirst) >> 4 );
  }
  v3->obstacleNeighbors_._Mylast = v3->obstacleNeighbors_._Myfirst;
  if ( UFG::NavModuleLocal::IsAvoidanceEnabled((UFG::NavModuleLocal *)&v2->vfptr) && sORCAEnableStaticObstacle )
  {
    v10 = (hkVector4f *)UFG::NavManager::ms_pInstance[3].vfptr;
    if ( v10 )
    {
      v11 = *(hkaiStreamingCollection::InstanceInfo **)(v10[2].m_quad.m128_u64[0] + 32);
      v12 = (hkVector4f *)v2->m_navComponent;
      v13 = v12[8].m_quad.m128_u32[0];
      position = v12 + 7;
      aabb.m_min = (hkVector4f)v12[7].m_quad;
      v15 = _mm_shuffle_ps(
              (__m128)LODWORD(DEFAULT_DEBUGDRAW_SENSORRADIUS),
              (__m128)LODWORD(DEFAULT_DEBUGDRAW_SENSORRADIUS),
              0);
      aabb.m_max.m_quad = _mm_add_ps(v12[7].m_quad, v15);
      aabb.m_min.m_quad = _mm_sub_ps(aabb.m_min.m_quad, v15);
      traversalInfo.m_diameter = 0.0;
      traversalInfo.m_filterInfo = 0;
      array = 0i64;
      v32 = 0;
      v33 = 2147483648;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 100, 16);
      hkaiNavMeshUtils::_getNearbyBoundariesFlood(
        v11,
        v13,
        &aabb,
        &traversalInfo,
        0i64,
        position,
        v10 + 1,
        (hkArrayBase<hkVector4f> *)&array);
      v16 = 0;
      if ( v32 > 0 )
      {
        v17 = 0i64;
        do
        {
          v18 = *(_DWORD *)&array[v17 + 20];
          v19 = *(float *)&array[v17];
          v20 = *(float *)&array[v17 + 4];
          result.m_enum = *(_DWORD *)&array[v17 + 16];
          v46 = v18;
          v47.x_ = v19;
          v47.y_ = v20;
          if ( !(_S1_17 & 1) )
          {
            _S1_17 |= 1u;
            rangeSq = DEFAULT_DEBUGDRAW_SENSORRADIUS * DEFAULT_DEBUGDRAW_SENSORRADIUS;
          }
          v21 = RVO::Vector2::operator-(&v47, &v42, (RVO::Vector2 *)&result);
          v22 = RVO::Vector2::operator-((RVO::Vector2 *)&result, &v37, &vector);
          v23 = (float)(v21->y_ * v22->x_) - (float)(v21->x_ * v22->y_);
          v24 = RVO::Vector2::operator-(&v47, &v41, (RVO::Vector2 *)&result);
          if ( (float)((float)(v23 * v23) / (float)((float)(v24->y_ * v24->y_) + (float)(v24->x_ * v24->x_))) < rangeSq )
          {
            v25 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
            v26 = (RVO::Obstacle *)v25;
            v35 = v25;
            if ( v25 )
            {
              *v25 = 0;
              *((_QWORD *)v25 + 1) = 0i64;
              *((_QWORD *)v25 + 2) = 0i64;
              *((_QWORD *)v25 + 3) = 0i64;
              *((_QWORD *)v25 + 4) = 0i64;
              *((_QWORD *)v25 + 5) = 0i64;
            }
            else
            {
              v26 = 0i64;
            }
            v26->point_ = *(RVO::Vector2 *)&result.m_enum;
            v26->isConvex_ = 1;
            v27 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
            v28 = v27;
            v35 = v27;
            if ( v27 )
            {
              *v27 = 0;
              *((_QWORD *)v27 + 1) = 0i64;
              *((_QWORD *)v27 + 2) = 0i64;
              *((_QWORD *)v27 + 3) = 0i64;
              *((_QWORD *)v27 + 4) = 0i64;
              *((_QWORD *)v27 + 5) = 0i64;
            }
            else
            {
              v28 = 0i64;
            }
            *((RVO::Vector2 *)v28 + 2) = v47;
            *v28 = 1;
            *((_QWORD *)v28 + 3) = v26;
            v26->nextObstacle = (RVO::Obstacle *)v28;
            *((_QWORD *)v28 + 1) = v26;
            v26->prevObstacle = (RVO::Obstacle *)v28;
            v29 = RVO::Vector2::operator-(&v47, &v43, (RVO::Vector2 *)&result);
            v26->unitDir_ = *RVO::normalize(&v36, v29);
            v30 = RVO::Vector2::operator-((RVO::Vector2 *)&result, &v38, &v47);
            *((RVO::Vector2 *)v28 + 4) = *RVO::normalize(&v40, v30);
            v26->id_ = v16;
            *((_QWORD *)v28 + 5) = v16;
            if ( !RVO::Agent::insertObstacleNeighbor(v3, v26, DEFAULT_DEBUGDRAW_SENSORRADIUS) )
            {
              operator delete[](v26);
              operator delete[](v28);
            }
          }
          v16 += 2;
          v17 += 32i64;
        }
        while ( v16 < v32 );
      }
      v32 = 0;
      if ( v33 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          16 * v33);
    }
  }
}

// File Line: 334
// RVA: 0xF7370
void __fastcall UFG::NavModuleLocalORCA::UpdateSteering(UFG::NavModuleLocalORCA *this, float dt)
{
  UFG::NavModuleLocalORCA *v2; // rdi
  UFG::qVector4 *v3; // rsi
  float v4; // xmm7_4
  float v5; // xmm3_4
  __m128 v6; // xmm4
  float v7; // xmm6_4
  __m128 v8; // xmm1
  float v9; // xmm5_4
  float v10; // xmm0_4
  UFG::SimObject *v11; // rbx
  UFG::TransformNodeComponent *v12; // rbx
  RVO::RVOSimulator *v13; // rbx
  RVO::Vector2 v14; // [rsp+20h] [rbp-48h]
  RVO::Vector2 v15; // [rsp+70h] [rbp+8h]

  v2 = this;
  UFG::NavModuleLocalORCA::UpdateAvoidanceProperties(this);
  UFG::NavModuleLocal::UpdateAdjustedWaypointAndSpeed((UFG::NavModuleLocal *)&v2->vfptr, dt);
  v3 = UFG::NavComponent::GetCurrentPosition(v2->m_navComponent);
  v6 = (__m128)LODWORD(v2->m_adjustedWaypoint.m_navPosition.m_vPosition.y);
  v4 = v2->m_fAdjustedSpeed;
  v5 = v2->m_adjustedWaypoint.m_navPosition.m_vPosition.x - v3->x;
  v6.m128_f32[0] = v6.m128_f32[0] - v3->y;
  v7 = UFG::qVector3::msZero.y;
  v8 = v6;
  v9 = UFG::qVector3::msZero.x;
  v8.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5);
  LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v8);
  if ( v10 <= 0.0 )
  {
    v14 = *(RVO::Vector2 *)&UFG::qVector3::msZero.x;
  }
  else
  {
    v14.x_ = (float)((float)(1.0 / v10) * v5) * v4;
    v14.y_ = (float)((float)(1.0 / v10) * v6.m128_f32[0]) * v4;
  }
  v11 = v2->m_navComponent->m_pSimObject;
  if ( v11 )
  {
    v12 = v11->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v12);
    v9 = v12->mWorldVelocity.x;
    v7 = v12->mWorldVelocity.y;
  }
  v13 = v2->mpStrategy->mpSimulator;
  v15.x_ = v9;
  v13->agents_._Myfirst[v2->mIndex]->position_ = *(RVO::Vector2 *)&v3->x;
  v15.y_ = v7;
  v13->agents_._Myfirst[v2->mIndex]->velocity_ = v15;
  v13->agents_._Myfirst[v2->mIndex]->inVelocity_ = (RVO::Vector2)__PAIR__(LODWORD(v7), LODWORD(v9));
  v13->agents_._Myfirst[v2->mIndex]->prefVelocity_ = v14;
  v13->agents_._Myfirst[v2->mIndex]->radius_ = UFG::NavComponent::GetAvoidanceRadius(v2->m_navComponent);
}

// File Line: 378
// RVA: 0xF6BF0
float __fastcall UFG::NavModuleLocalORCA::GetTurningRadius(UFG::NavModuleLocalORCA *this, float fSpeed)
{
  float v2; // xmm0_4

  v2 = this->m_navComponent->m_fMaxAngularVelocity;
  if ( v2 <= 0.0099999998 )
    v2 = FLOAT_0_0099999998;
  return fSpeed / v2;
}

// File Line: 387
// RVA: 0xF6BC0
float __fastcall UFG::NavModuleLocalORCA::GetMaxSpeedForRadius(UFG::NavModuleLocalORCA *this, float fRadius)
{
  float v2; // xmm0_4

  v2 = this->m_navComponent->m_fMaxAngularVelocity;
  if ( v2 <= 0.0099999998 )
    v2 = FLOAT_0_0099999998;
  return v2 * fRadius;
}

// File Line: 401
// RVA: 0xF6D00
_BOOL8 __fastcall UFG::NavModuleLocalORCA::IsStuck(UFG::NavModuleLocalORCA *this)
{
  return this->mpStrategy->mpSimulator->agents_._Myfirst[this->mIndex]->resolved_ == 0;
}

