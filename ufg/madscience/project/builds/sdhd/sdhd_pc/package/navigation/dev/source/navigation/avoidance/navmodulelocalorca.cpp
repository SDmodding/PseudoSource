// File Line: 25
// RVA: 0xF62B0
void __fastcall UFG::NavModuleLocalORCA::NavModuleLocalORCA(UFG::NavModuleLocalORCA *this, UFG::NavComponent *parent)
{
  UFG::NavModuleLocal::NavModuleLocal(this, parent);
  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocalORCA::`vftable;
  this->mpStrategy = 0i64;
  *(_QWORD *)&this->mIndex = 0i64;
  this->mStuckWaitTimer = 0.0;
  this->mGatherObstaclesTicket.mPrev = &this->mGatherObstaclesTicket;
  this->mGatherObstaclesTicket.mNext = &this->mGatherObstaclesTicket;
  this->mGatherObstaclesTicket.mTimestamp = 0i64;
  this->mGatherObstaclesTicket.mActiveCallback.m_Closure.m_pthis = 0i64;
  this->mGatherObstaclesTicket.mActiveCallback.m_Closure.m_pFunction = 0i64;
  this->mGatherObstaclesTicket.mInactiveCallback.m_Closure.m_pthis = 0i64;
  this->mGatherObstaclesTicket.mInactiveCallback.m_Closure.m_pFunction = 0i64;
}

// File Line: 47
// RVA: 0xF6C20
void __fastcall UFG::NavModuleLocalORCA::Init(UFG::NavModuleLocalORCA *this, UFG::NavAvoidanceStrategyORCA *pStrategy)
{
  RVO::RVOSimulator *mpSimulator; // rbx
  UFG::qVector4 *CurrentPosition; // rax
  UFG::NavAvoidanceStrategyORCA *mpStrategy; // rcx
  __int64 mNumActiveIndexes; // rdx
  __int64 v7; // r9
  float v8; // xmm0_4
  fastdelegate::FastDelegate1<float,void> v9; // [rsp+20h] [rbp-18h] BYREF

  this->mpStrategy = pStrategy;
  mpSimulator = pStrategy->mpSimulator;
  CurrentPosition = UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  mpStrategy = this->mpStrategy;
  mNumActiveIndexes = mpStrategy->mNumActiveIndexes;
  v7 = (int)mpStrategy->mIndexes[mNumActiveIndexes];
  mpStrategy->mNumActiveIndexes = mNumActiveIndexes + 1;
  mpStrategy->mpSimulator->agents_._Myfirst[(unsigned int)v7]->enabled = 1;
  this->mIndex = v7;
  mpSimulator->agents_._Myfirst[v7]->position_ = *(RVO::Vector2 *)&CurrentPosition->x;
  v8 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
  this->mStuckWaitTimer = 0.0;
  this->mWiggleRandomRange = v8;
  v9.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *)) UFG::NavModuleLocalORCA::`vcall{96,{flat}};
  v9.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::TicketBoothManager::Register(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_NAVLOCAL_GATHEROBSTACLE,
    &this->mGatherObstaclesTicket,
    &v9);
}

// File Line: 63
// RVA: 0xF63A0
void __fastcall UFG::NavModuleLocalORCA::~NavModuleLocalORCA(UFG::NavModuleLocalORCA *this)
{
  UFG::qNode<UFG::Ticket,UFG::Ticket> *mPrev; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *mNext; // rax

  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocalORCA::`vftable;
  UFG::NavAvoidanceStrategyORCA::ReturnAgentIndex(this->mpStrategy, this->mIndex);
  UFG::TicketBoothManager::Unregister(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_NAVLOCAL_GATHEROBSTACLE,
    &this->mGatherObstaclesTicket);
  mPrev = this->mGatherObstaclesTicket.mPrev;
  mNext = this->mGatherObstaclesTicket.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mGatherObstaclesTicket.mPrev = &this->mGatherObstaclesTicket;
  this->mGatherObstaclesTicket.mNext = &this->mGatherObstaclesTicket;
  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocal::`vftable;
  _((AMD_HD3D *)&this->m_adjustedWaypoint);
}

// File Line: 70
// RVA: 0xF6D30
void __fastcall UFG::NavModuleLocalORCA::Reset(UFG::NavModuleLocalORCA *this)
{
  UFG::NavModuleLocal::Reset(this);
  this->mStuckWaitTimer = 0.0;
}

// File Line: 76
// RVA: 0xF7290
void __fastcall UFG::NavModuleLocalORCA::UpdateAvoidanceProperties(UFG::NavModuleLocalORCA *this)
{
  float v1; // xmm0_4
  RVO::RVOSimulator *mpSimulator; // rdi
  bool IsAvoidanceEnabled; // al
  __int64 mIndex; // rcx
  bool v6; // zf
  RVO::Agent **Myfirst; // rax

  v1 = sORCANeighborDist;
  mpSimulator = this->mpStrategy->mpSimulator;
  mpSimulator->agents_._Myfirst[this->mIndex]->maxNeighbors_ = sORCAMaxNeighbors;
  mpSimulator->agents_._Myfirst[this->mIndex]->neighborDist_ = v1;
  mpSimulator->agents_._Myfirst[this->mIndex]->timeHorizon_ = sORCATimeHorizon;
  mpSimulator->agents_._Myfirst[this->mIndex]->timeHorizonObst_ = sORCATimeHorizonObst;
  IsAvoidanceEnabled = UFG::NavModuleLocal::IsAvoidanceEnabled(this);
  mIndex = this->mIndex;
  v6 = !IsAvoidanceEnabled;
  Myfirst = mpSimulator->agents_._Myfirst;
  if ( v6 )
    Myfirst[mIndex]->maxSpeed_ = 999.0;
  else
    Myfirst[mIndex]->maxSpeed_ = sORCAMaxSpeed;
}

// File Line: 118
// RVA: 0xF6EB0
void __fastcall UFG::NavModuleLocalORCA::Update(UFG::NavModuleLocalORCA *this, float dt)
{
  RVO::Agent *v3; // rcx
  float x; // xmm8_4
  float y; // xmm9_4
  __int128 y_low; // xmm7
  float v7; // xmm6_4
  RVO::Vector2 fallbackVelocity; // rax
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
  float mStuckWaitTimer; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  bool v23; // cf
  UFG::qVector3 source; // [rsp+20h] [rbp-B8h] BYREF
  UFG::qVector3 dest; // [rsp+30h] [rbp-A8h] BYREF

  v3 = this->mpStrategy->mpSimulator->agents_._Myfirst[this->mIndex];
  x = v3->prefVelocity_.x_;
  y = v3->prefVelocity_.y_;
  if ( v3->resolved_ )
  {
    y_low = (unsigned int)HIDWORD(*(_QWORD *)&v3->velocity_);
    LODWORD(v7) = v3->velocity_;
  }
  else
  {
    if ( sORCAEnableFallbackVelocity )
      fallbackVelocity = v3->fallbackVelocity_;
    else
      fallbackVelocity = v3->prefVelocity_;
    y_low = LODWORD(fallbackVelocity.y_);
    v7 = fallbackVelocity.x_ * sORCAFallbackVelocityRatio;
    *(float *)&y_low = fallbackVelocity.y_ * sORCAFallbackVelocityRatio;
  }
  source.x = v7;
  LODWORD(source.y) = y_low;
  source.z = 0.0;
  v9 = sORCALocalLerpWeight * 0.0;
  *(float *)&y_low = (float)((float)(*(float *)&y_low - v3->inVelocity_.y_) * sORCALocalLerpWeight) + v3->inVelocity_.y_;
  v10 = (float)((float)(v7 - v3->inVelocity_.x_) * sORCALocalLerpWeight) + v3->inVelocity_.x_;
  dest.z = sORCALocalLerpWeight * 0.0;
  v11 = (__m128)y_low;
  dest.x = v10;
  LODWORD(dest.y) = y_low;
  v11.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v10 * v10)) + (float)(v9 * v9);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
  v13 = v10 * v12;
  v14 = *(float *)&y_low * v12;
  v15 = v13;
  v16 = v14;
  LODWORD(this->m_fAdjustedSpeed) = _mm_sqrt_ps(v11).m128_u32[0];
  v17 = v9 * v12;
  v18 = v17;
  v19 = (float)((float)(v14 * y) + (float)(v13 * x)) + (float)(v17 * 0.0);
  if ( v19 < 0.0 )
  {
    v18 = (float)(v19 * -0.0) + v17;
    v15 = (float)(COERCE_FLOAT(LODWORD(x) ^ _xmm[0]) * v19) + v13;
    v16 = (float)(COERCE_FLOAT(LODWORD(y) ^ _xmm[0]) * v19) + v14;
  }
  if ( this->vfptr->IsStuck(this) )
  {
    if ( sORCAFallbackWiggle )
      UFG::qRotateVectorZ(
        &dest,
        &source,
        (float)((float)((float)((float)((float)(sORCAResolveWiggleRange * this->mWiggleRandomRange)
                                      + sORCAResolveWiggleAngle)
                              * 3.1415927)
                      * 0.0055555557)
              * (float)((float)(UFG::Metrics::msRealTimeSineWave * 2.0) - 1.0))
      + (float)((float)(sORCAResolveOffCenterAngle * 3.1415927) * 0.0055555557));
    mStuckWaitTimer = this->mStuckWaitTimer;
    if ( mStuckWaitTimer > 0.0 )
    {
      v22 = mStuckWaitTimer - dt;
      this->mStuckWaitTimer = v22;
      if ( v22 <= 0.0 )
        LODWORD(this->mStuckWaitTimer) = COERCE_UNSIGNED_INT(
                                           (float)(UFG::qRandom(s_StuckRandomRetryTime, &UFG::qDefaultSeed)
                                                 + s_StuckBaseRetryTime)
                                         + s_StuckTransitionBufferTime) ^ _xmm[0];
      this->m_fAdjustedSpeed = 0.0;
    }
    else
    {
      v21 = mStuckWaitTimer + dt;
      this->mStuckWaitTimer = v21;
      if ( v21 >= 0.0 )
        this->mStuckWaitTimer = (float)(UFG::qRandom(s_StuckRandomWaitTime, &UFG::qDefaultSeed)
                                      + s_StuckTransitionBufferTime)
                              + s_StuckBaseWaitTime;
    }
  }
  else
  {
    this->mStuckWaitTimer = 0.0;
  }
  v23 = this->m_fAdjustedSpeed > 0.0;
  this->m_steerData.m_vDesiredDirection.x = x;
  this->m_steerData.m_vDesiredDirection.y = y;
  this->m_steerData.m_vDesiredDirection.z = 0.0;
  if ( v23 )
  {
    this->m_steerData.m_vClampedDirection.x = v15;
    this->m_steerData.m_vClampedDirection.y = v16;
    this->m_steerData.m_vClampedDirection.z = v18;
    this->m_steerData.m_vLocalDirection.x = v13;
    this->m_steerData.m_vLocalDirection.y = v14;
    this->m_steerData.m_vLocalDirection.z = v17;
    this->m_steerData.m_fLocalSpeed = this->m_fAdjustedSpeed;
  }
  else
  {
    this->m_steerData.m_vClampedDirection.x = x;
    this->m_steerData.m_vClampedDirection.y = y;
    this->m_steerData.m_vClampedDirection.z = 0.0;
    *(_QWORD *)&this->m_steerData.m_vLocalDirection.z = 0i64;
    this->m_steerData.m_vLocalDirection.x = x;
    this->m_steerData.m_vLocalDirection.y = y;
  }
}

// File Line: 218
// RVA: 0xF66E0
void __fastcall UFG::NavModuleLocalORCA::GatherAgents(UFG::NavModuleLocalORCA *this)
{
  RVO::RVOSimulator *mpSimulator; // rdi
  RVO::Agent *v3; // r14
  int v4; // esi
  __int64 v5; // rax
  __int64 v6; // rbx
  RVO::Agent *v7; // rdx
  float rangeSq; // [rsp+30h] [rbp+8h] BYREF

  mpSimulator = this->mpStrategy->mpSimulator;
  v3 = mpSimulator->agents_._Myfirst[this->mIndex];
  UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  v3->agentNeighbors_._Mylast = v3->agentNeighbors_._Myfirst;
  if ( UFG::NavModuleLocal::IsAvoidanceEnabled(this) )
  {
    if ( v3->maxNeighbors_ )
    {
      v4 = 0;
      v5 = mpSimulator->agents_._Mylast - mpSimulator->agents_._Myfirst;
      rangeSq = v3->neighborDist_ * v3->neighborDist_;
      if ( (int)v5 > 0 )
      {
        v6 = 0i64;
        do
        {
          v7 = mpSimulator->agents_._Myfirst[v6];
          if ( v7->enabled )
            RVO::Agent::insertAgentNeighbor(v3, v7, &rangeSq);
          ++v4;
          ++v6;
        }
        while ( v4 < (int)(mpSimulator->agents_._Mylast - mpSimulator->agents_._Myfirst) );
      }
    }
  }
}

// File Line: 248
// RVA: 0xF67B0
void __fastcall UFG::NavModuleLocalORCA::GatherObstacles(UFG::NavModuleLocalORCA *this, float deltaTime)
{
  RVO::Agent *v3; // r14
  UFG::qVector4 *CurrentPosition; // rax
  float y; // xmm1_4
  unsigned __int64 v6; // rdi
  __int64 v7; // rbx
  RVO::Obstacle *second; // rcx
  RVO::Obstacle *nextObstacle; // rsi
  hkVector4f *vfptr; // rbx
  hkaiStreamingCollection::InstanceInfo *v11; // rsi
  UFG::NavComponent *m_navComponent; // rax
  unsigned int m_packedKey; // r15d
  hkVector4f *position; // rdi
  __m128 v15; // xmm1
  int v16; // r15d
  __int64 v17; // rsi
  float v18; // xmm1_4
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
  hkArrayBase<hkVector4f> array; // [rsp+40h] [rbp-69h] BYREF
  RVO::Vector2 vector; // [rsp+50h] [rbp-59h] BYREF
  char *v33; // [rsp+58h] [rbp-51h]
  RVO::Vector2 v34; // [rsp+60h] [rbp-49h] BYREF
  RVO::Vector2 v35; // [rsp+68h] [rbp-41h] BYREF
  RVO::Vector2 v36; // [rsp+70h] [rbp-39h] BYREF
  __int64 v37; // [rsp+78h] [rbp-31h]
  RVO::Vector2 v38; // [rsp+80h] [rbp-29h] BYREF
  RVO::Vector2 v39; // [rsp+88h] [rbp-21h] BYREF
  RVO::Vector2 v40; // [rsp+90h] [rbp-19h] BYREF
  RVO::Vector2 v41; // [rsp+98h] [rbp-11h] BYREF
  hkAabb aabb; // [rsp+A0h] [rbp-9h] BYREF
  RVO::Vector2 result; // [rsp+110h] [rbp+67h] BYREF
  RVO::Vector2 v44; // [rsp+120h] [rbp+77h] BYREF
  hkaiAgentTraversalInfo traversalInfo; // [rsp+128h] [rbp+7Fh] BYREF

  v37 = -2i64;
  v3 = this->mpStrategy->mpSimulator->agents_._Myfirst[this->mIndex];
  CurrentPosition = UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  y = CurrentPosition->y;
  vector.x_ = CurrentPosition->x;
  vector.y_ = y;
  v6 = 0i64;
  if ( v3->obstacleNeighbors_._Mylast - v3->obstacleNeighbors_._Myfirst )
  {
    v7 = 0i64;
    do
    {
      second = v3->obstacleNeighbors_._Myfirst[v7].second;
      nextObstacle = second->nextObstacle;
      operator delete[](second);
      if ( nextObstacle )
        operator delete[](nextObstacle);
      ++v6;
      ++v7;
    }
    while ( v6 < v3->obstacleNeighbors_._Mylast - v3->obstacleNeighbors_._Myfirst );
  }
  v3->obstacleNeighbors_._Mylast = v3->obstacleNeighbors_._Myfirst;
  if ( UFG::NavModuleLocal::IsAvoidanceEnabled(this) && sORCAEnableStaticObstacle )
  {
    vfptr = (hkVector4f *)UFG::NavManager::ms_pInstance[3].vfptr;
    if ( vfptr )
    {
      v11 = *(hkaiStreamingCollection::InstanceInfo **)(vfptr[2].m_quad.m128_u64[0] + 32);
      m_navComponent = this->m_navComponent;
      m_packedKey = m_navComponent->m_navPosition.m_packedKey;
      position = &m_navComponent->m_navPosition.m_hkvMeshPosition;
      aabb.m_min = m_navComponent->m_navPosition.m_hkvMeshPosition;
      v15 = _mm_shuffle_ps(
              (__m128)LODWORD(DEFAULT_DEBUGDRAW_SENSORRADIUS),
              (__m128)LODWORD(DEFAULT_DEBUGDRAW_SENSORRADIUS),
              0);
      aabb.m_max.m_quad = _mm_add_ps(m_navComponent->m_navPosition.m_hkvMeshPosition.m_quad, v15);
      aabb.m_min.m_quad = _mm_sub_ps(aabb.m_min.m_quad, v15);
      traversalInfo.m_diameter = 0.0;
      traversalInfo.m_filterInfo = 0;
      array.m_data = 0i64;
      array.m_size = 0;
      array.m_capacityAndFlags = 0x80000000;
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &array, 100, 16);
      hkaiNavMeshUtils::_getNearbyBoundariesFlood(
        v11,
        m_packedKey,
        &aabb,
        &traversalInfo,
        0i64,
        position,
        vfptr + 1,
        &array);
      v16 = 0;
      if ( array.m_size > 0 )
      {
        v17 = 0i64;
        do
        {
          v18 = array.m_data[v17 + 1].m_quad.m128_f32[1];
          v19 = array.m_data[v17].m_quad.m128_f32[0];
          v20 = array.m_data[v17].m_quad.m128_f32[1];
          LODWORD(result.x_) = array.m_data[v17 + 1].m_quad.m128_i32[0];
          result.y_ = v18;
          v44.x_ = v19;
          v44.y_ = v20;
          if ( (_S1_17 & 1) == 0 )
          {
            _S1_17 |= 1u;
            rangeSq = DEFAULT_DEBUGDRAW_SENSORRADIUS * DEFAULT_DEBUGDRAW_SENSORRADIUS;
          }
          v21 = RVO::Vector2::operator-(&v44, &v40, &result);
          v22 = RVO::Vector2::operator-(&result, &v35, &vector);
          v23 = (float)(v21->y_ * v22->x_) - (float)(v21->x_ * v22->y_);
          v24 = RVO::Vector2::operator-(&v44, &v39, &result);
          if ( (float)((float)(v23 * v23) / (float)((float)(v24->y_ * v24->y_) + (float)(v24->x_ * v24->x_))) < rangeSq )
          {
            v25 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
            v26 = (RVO::Obstacle *)v25;
            v33 = v25;
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
            v26->point_ = result;
            v26->isConvex_ = 1;
            v27 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
            v28 = v27;
            v33 = v27;
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
            *((RVO::Vector2 *)v28 + 2) = v44;
            *v28 = 1;
            *((_QWORD *)v28 + 3) = v26;
            v26->nextObstacle = (RVO::Obstacle *)v28;
            *((_QWORD *)v28 + 1) = v26;
            v26->prevObstacle = (RVO::Obstacle *)v28;
            v29 = RVO::Vector2::operator-(&v44, &v41, &result);
            v26->unitDir_ = *RVO::normalize(&v34, v29);
            v30 = RVO::Vector2::operator-(&result, &v36, &v44);
            *((RVO::Vector2 *)v28 + 4) = *RVO::normalize(&v38, v30);
            v26->id_ = v16;
            *((_QWORD *)v28 + 5) = v16;
            if ( !RVO::Agent::insertObstacleNeighbor(v3, v26, DEFAULT_DEBUGDRAW_SENSORRADIUS) )
            {
              operator delete[](v26);
              operator delete[](v28);
            }
          }
          v16 += 2;
          v17 += 2i64;
        }
        while ( v16 < array.m_size );
      }
      array.m_size = 0;
      if ( array.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          array.m_data,
          16 * array.m_capacityAndFlags);
    }
  }
}

// File Line: 334
// RVA: 0xF7370
void __fastcall UFG::NavModuleLocalORCA::UpdateSteering(UFG::NavModuleLocalORCA *this, float dt)
{
  UFG::qVector4 *CurrentPosition; // rsi
  float m_fAdjustedSpeed; // xmm7_4
  float v5; // xmm3_4
  __m128 y_low; // xmm4
  float y; // xmm6_4
  __m128 v8; // xmm1
  float x; // xmm5_4
  float v10; // xmm0_4
  UFG::SimObject *m_pSimObject; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  RVO::RVOSimulator *mpSimulator; // rbx
  RVO::Vector2 v14; // [rsp+20h] [rbp-48h]

  UFG::NavModuleLocalORCA::UpdateAvoidanceProperties(this);
  UFG::NavModuleLocal::UpdateAdjustedWaypointAndSpeed(this, dt);
  CurrentPosition = UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  y_low = (__m128)LODWORD(this->m_adjustedWaypoint.m_navPosition.m_vPosition.y);
  m_fAdjustedSpeed = this->m_fAdjustedSpeed;
  v5 = this->m_adjustedWaypoint.m_navPosition.m_vPosition.x - CurrentPosition->x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - CurrentPosition->y;
  y = UFG::qVector3::msZero.y;
  v8 = y_low;
  x = UFG::qVector3::msZero.x;
  v8.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v5 * v5);
  v10 = _mm_sqrt_ps(v8).m128_f32[0];
  if ( v10 <= 0.0 )
  {
    v14 = *(RVO::Vector2 *)&UFG::qVector3::msZero.x;
  }
  else
  {
    v14.x_ = (float)((float)(1.0 / v10) * v5) * m_fAdjustedSpeed;
    v14.y_ = (float)((float)(1.0 / v10) * y_low.m128_f32[0]) * m_fAdjustedSpeed;
  }
  m_pSimObject = this->m_navComponent->m_pSimObject;
  if ( m_pSimObject )
  {
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    x = m_pTransformNodeComponent->mWorldVelocity.x;
    y = m_pTransformNodeComponent->mWorldVelocity.y;
  }
  mpSimulator = this->mpStrategy->mpSimulator;
  mpSimulator->agents_._Myfirst[this->mIndex]->position_ = *(RVO::Vector2 *)&CurrentPosition->x;
  mpSimulator->agents_._Myfirst[this->mIndex]->velocity_ = (RVO::Vector2)__PAIR64__(LODWORD(y), LODWORD(x));
  mpSimulator->agents_._Myfirst[this->mIndex]->inVelocity_ = (RVO::Vector2)__PAIR64__(LODWORD(y), LODWORD(x));
  mpSimulator->agents_._Myfirst[this->mIndex]->prefVelocity_ = v14;
  mpSimulator->agents_._Myfirst[this->mIndex]->radius_ = UFG::NavComponent::GetAvoidanceRadius(this->m_navComponent);
}

// File Line: 378
// RVA: 0xF6BF0
float __fastcall UFG::NavModuleLocalORCA::GetTurningRadius(UFG::NavModuleLocalORCA *this, float fSpeed)
{
  float m_fMaxAngularVelocity; // xmm0_4

  m_fMaxAngularVelocity = this->m_navComponent->m_fMaxAngularVelocity;
  if ( m_fMaxAngularVelocity <= 0.0099999998 )
    m_fMaxAngularVelocity = FLOAT_0_0099999998;
  return fSpeed / m_fMaxAngularVelocity;
}

// File Line: 387
// RVA: 0xF6BC0
float __fastcall UFG::NavModuleLocalORCA::GetMaxSpeedForRadius(UFG::NavModuleLocalORCA *this, float fRadius)
{
  float m_fMaxAngularVelocity; // xmm0_4

  m_fMaxAngularVelocity = this->m_navComponent->m_fMaxAngularVelocity;
  if ( m_fMaxAngularVelocity <= 0.0099999998 )
    m_fMaxAngularVelocity = FLOAT_0_0099999998;
  return m_fMaxAngularVelocity * fRadius;
}

// File Line: 401
// RVA: 0xF6D00
_BOOL8 __fastcall UFG::NavModuleLocalORCA::IsStuck(UFG::NavModuleLocalORCA *this)
{
  return !this->mpStrategy->mpSimulator->agents_._Myfirst[this->mIndex]->resolved_;
}

