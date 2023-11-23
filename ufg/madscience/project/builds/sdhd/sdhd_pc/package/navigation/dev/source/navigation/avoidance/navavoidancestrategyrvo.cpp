// File Line: 141
// RVA: 0xE8A10
void __fastcall UFG::NavAvoidanceStrategyRVO::CalcDesiredVelocities(
        UFG::NavAvoidanceStrategyRVO *this,
        float deltaTime)
{
  __int64 v2; // rdx
  hkaiWorld *mpWorld; // rax
  hkArrayBase<hkaiBehavior *> *mpBehaviors; // rcx
  int m_numBehaviorUpdatesPerJob; // r8d
  __int64 m_data; // r12
  int v8; // r13d
  int v9; // eax
  hkaiLocalSteeringInput *v10; // rdx
  int v11; // ecx
  __int64 v12; // r9
  int v13; // edi
  int v14; // esi
  _QWORD *v15; // rbx
  __int64 v16; // rbp
  int v17; // eax
  hkArrayBase<hkaiBehavior *> *v18; // rax
  hkaiLocalSteeringInput *v19; // rdi
  unsigned int m_size; // esi
  int v21; // r15d
  __int64 v22; // rbx
  int v23; // eax
  __int64 v24; // rcx
  hkaiLocalSteeringInput *v25; // [rsp+20h] [rbp-98h]
  hkJob job; // [rsp+30h] [rbp-88h] BYREF
  __int128 v27; // [rsp+40h] [rbp-78h]
  __int64 v28; // [rsp+50h] [rbp-68h]
  int v29; // [rsp+58h] [rbp-60h]
  hkaiLocalSteeringInput *v30; // [rsp+60h] [rbp-58h]
  int v31; // [rsp+68h] [rbp-50h]
  float v32; // [rsp+6Ch] [rbp-4Ch]
  int v33; // [rsp+C0h] [rbp+8h]
  int v34; // [rsp+D0h] [rbp+18h]
  int v35; // [rsp+D8h] [rbp+20h]

  if ( this->mpJobQueue && this->mpThreadPool )
  {
    v32 = deltaTime;
    job.m_size = 64;
    *(_WORD *)&job.m_jobSubType = 3073;
    job.m_threadAffinity = -1;
    v29 = -1;
    v31 = -1;
    v27 = 0i64;
    mpWorld = this->mpWorld;
    mpBehaviors = this->mpBehaviors;
    v28 = 0i64;
    v30 = 0i64;
    job.m_jobSpuType.m_storage = 2;
    m_numBehaviorUpdatesPerJob = mpWorld->m_numBehaviorUpdatesPerJob;
    m_data = (__int64)mpBehaviors->m_data;
    v8 = 0;
    v34 = m_numBehaviorUpdatesPerJob;
    v9 = (m_numBehaviorUpdatesPerJob + mpBehaviors->m_size - 1) / m_numBehaviorUpdatesPerJob;
    v10 = this->mLocalSteeringInputs.m_data;
    v25 = v10;
    v35 = v9;
    if ( v9 > 0 )
    {
      v11 = 0;
      LODWORD(v12) = v9 - 1;
      v33 = 0;
      do
      {
        if ( v8 == (_DWORD)v12 )
          v13 = this->mpBehaviors->m_size - v11;
        else
          v13 = m_numBehaviorUpdatesPerJob;
        v28 = m_data;
        v29 = v13;
        v14 = 0;
        if ( v13 > 0 )
        {
          v15 = (_QWORD *)m_data;
          v16 = (unsigned int)v13;
          do
          {
            v17 = (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)*v15 + 96i64))(*v15);
            ++v15;
            v14 += v17;
            --v16;
          }
          while ( v16 );
          v10 = v25;
        }
        v30 = v10;
        m_data += 8i64 * v13;
        v31 = v14;
        v25 = &v10[v14];
        hkJobQueue::addJob(this->mpJobQueue, &job, JOB_HIGH_PRIORITY);
        m_numBehaviorUpdatesPerJob = v34;
        v10 = v25;
        ++v8;
        v11 = v34 + v33;
        v12 = (unsigned int)(v35 - 1);
        v33 += v34;
      }
      while ( v8 < v35 );
      if ( v35 > 0 )
      {
        ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64, __int64))this->mpThreadPool->vfptr[5].__first_virtual_table_function__)(
          this->mpThreadPool,
          this->mpJobQueue,
          12i64,
          v12);
        ((void (__fastcall *)(hkJobThreadPool *))this->mpThreadPool->vfptr[2].__vecDelDtor)(this->mpThreadPool);
        hkJobQueue::processAllJobs(this->mpJobQueue, 1);
      }
    }
  }
  else
  {
    v18 = this->mpBehaviors;
    v19 = this->mLocalSteeringInputs.m_data;
    m_size = this->mLocalSteeringInputs.m_size;
    v21 = 0;
    if ( v18->m_size > 0 )
    {
      v22 = 0i64;
      do
      {
        v23 = ((__int64 (__fastcall *)(hkaiBehavior *, __int64, hkaiLocalSteeringInput *, _QWORD))v18->m_data[v22]->hkReferencedObject::hkBaseObject::vfptr[1].__first_virtual_table_function__)(
                v18->m_data[v22],
                v2,
                v19,
                m_size);
        ++v21;
        ++v22;
        v24 = v23;
        m_size -= v23;
        v18 = this->mpBehaviors;
        v2 = 160 * v24;
        v19 += v24;
      }
      while ( v21 < v18->m_size );
    }
  }
}
        v18 = this->mpBehaviors;
        v2 = 160 * v24;
        v19 += v24;
      }
      while ( v21 < v18->m_

// File Line: 200
// RVA: 0xF3B60
void __fastcall UFG::NavAvoidanceStrategyRVO::UpdateGenerators(UFG::NavAvoidanceStrategyRVO *this)
{
  hkaiWorld *mpWorld; // rsi
  int v2; // ebx
  __int64 v3; // rdi

  mpWorld = this->mpWorld;
  v2 = 0;
  if ( mpWorld->m_obstacleGenerators.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      mpWorld->m_obstacleGenerators.m_data[v3].m_pntr->vfptr[1].__first_virtual_table_function__(mpWorld->m_obstacleGenerators.m_data[v3].m_pntr);
      ++v2;
      ++v3;
    }
    while ( v2 < mpWorld->m_obstacleGenerators.m_size );
  }
}

// File Line: 209
// RVA: 0xE9C30
void __fastcall UFG::NavAvoidanceStrategyRVO::DetectOverlaps(UFG::NavAvoidanceStrategyRVO *this)
{
  __int64 m_size; // r12
  hkaiWorld *mpWorld; // r13
  __int64 v4; // r14
  int v5; // r15d
  int v6; // eax
  hk1AxisSweep::AabbInt *v7; // rcx
  unsigned int v8; // edx
  int v9; // ebx
  __int64 v10; // rdi
  __int64 v11; // rsi
  hk1AxisSweep::AabbInt *v12; // r12
  hkaiCharacter *m_character; // rcx
  hkaiAvoidanceProperties *m_pntr; // rax
  __m128 m_quad; // xmm1
  __int64 v16; // rdi
  __int64 v17; // rsi
  bool v18; // cc
  hk1AxisSweep::AabbInt *v19; // r14
  hkaiObstacleGenerator *v20; // rcx
  __int64 v21; // rax
  int v22; // ebx
  __int64 v23; // rax
  int v24; // ecx
  __int64 v25; // rax
  unsigned int *v26; // rsi
  int v27; // edx
  __int64 v28; // r15
  hk1AxisSweep::AabbInt *v29; // r9
  __int64 v30; // rdx
  __int64 v31; // r8
  UFG::AgentInfo *v32; // rbx
  __int64 v33; // rdi
  hkaiLocalSteeringInput *v34; // r12
  __int64 v35; // r14
  hkaiLocalSteeringInput *v36; // r14
  UFG::AgentInfo *v37; // rbx
  __int64 v38; // rcx
  hkaiObstacleGenerator *v39; // rdi
  hk1AxisSweep::AabbInt *aabbs; // [rsp+20h] [rbp-98h]
  __int64 v41; // [rsp+28h] [rbp-90h]
  hkAabb aabbIn; // [rsp+50h] [rbp-68h] BYREF
  int v43; // [rsp+C0h] [rbp+8h] BYREF
  int v44; // [rsp+C8h] [rbp+10h]
  int v45; // [rsp+D0h] [rbp+18h]
  int v46; // [rsp+D8h] [rbp+20h]

  m_size = this->mpCharacters->m_size;
  v44 = m_size;
  mpWorld = this->mpWorld;
  v4 = mpWorld->m_obstacleGenerators.m_size;
  v5 = v4 + m_size;
  v6 = v4 + m_size + 4;
  if ( (_DWORD)v4 + (_DWORD)m_size == -4 )
  {
    v7 = 0i64;
  }
  else
  {
    v43 = 32 * v6;
    v7 = (hk1AxisSweep::AabbInt *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                    &hkContainerTempAllocator::s_alloc,
                                    &v43);
    v6 = v43 / 32;
  }
  aabbs = v7;
  v8 = 0x80000000;
  if ( v6 )
    v8 = v6;
  v46 = v8;
  v9 = 0;
  if ( (int)m_size > 0 )
  {
    v10 = 0i64;
    v11 = m_size;
    v12 = v7;
    do
    {
      m_character = this->mLocalSteeringInputs.m_data[v10].m_character;
      m_pntr = m_character->m_avoidanceProperties.m_pntr;
      m_quad = m_pntr->m_localSensorAabb.m_max.m_quad;
      aabbIn.m_min.m_quad = _mm_add_ps(m_pntr->m_localSensorAabb.m_min.m_quad, m_character->m_position.m_quad);
      aabbIn.m_max.m_quad = _mm_add_ps(m_quad, m_character->m_position.m_quad);
      hk1AxisSweep::AabbInt::set(&v12[v9], &aabbIn, v9);
      ++v9;
      ++v10;
      --v11;
    }
    while ( v11 );
    LODWORD(m_size) = v44;
  }
  v16 = 0i64;
  v17 = v4;
  v18 = (int)v4 <= 0;
  v19 = aabbs;
  if ( !v18 )
  {
    do
    {
      v20 = mpWorld->m_obstacleGenerators.m_data[v16].m_pntr;
      ((void (__fastcall *)(hkaiObstacleGenerator *, hkAabb *))v20->vfptr[2].__first_virtual_table_function__)(
        v20,
        &aabbIn);
      hk1AxisSweep::AabbInt::set(&aabbs[v9], &aabbIn, v9);
      ++v16;
      ++v9;
    }
    while ( v16 < v17 );
  }
  v21 = v9;
  v22 = v9 + 1;
  aabbs[v21].m_min[0] = -1;
  v23 = v22++;
  aabbs[v23].m_min[0] = -1;
  aabbs[v22].m_min[0] = -1;
  aabbs[v22 + 1].m_min[0] = -1;
  hk1AxisSweep::sortAabbs(aabbs, v5);
  v24 = 0;
  v45 = 0;
  v43 = v5 - 1;
  v25 = 1i64;
  v41 = 1i64;
  v26 = &aabbs->m_min[1];
  v27 = v5 - 1;
  do
  {
    v28 = v25;
    v29 = (hk1AxisSweep::AabbInt *)(v26 + 7);
    if ( v26[7] > v26[3] )
      goto LABEL_30;
    do
    {
      if ( (((v29->m_max[1] - *v26) | (v26[4] - v29->m_min[1]) | (v29->m_max[2] - v26[1]) | (v26[5] - v29->m_min[2])) & 0x80000000) != 0 )
        goto LABEL_28;
      v30 = (int)v26[2];
      v31 = *(int *)v29->m_expansionMin;
      if ( (int)v30 >= (int)m_size )
      {
        if ( (int)v31 >= (int)m_size )
          goto LABEL_28;
        v38 = (int)v26[2];
        v32 = &this->mAgentInfos.m_data[v31];
      }
      else
      {
        v32 = &this->mAgentInfos.m_data[v30];
        if ( (int)v31 < (int)m_size )
        {
          v33 = *(int *)v29->m_expansionMin;
          v34 = &this->mLocalSteeringInputs.m_data[v31];
          v35 = (int)v26[2];
          if ( v32->m_characters.m_size == (v32->m_characters.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v32->m_characters, 8);
          v32->m_characters.m_data[v32->m_characters.m_size++] = v34->m_character;
          v36 = &this->mLocalSteeringInputs.m_data[v35];
          v37 = &this->mAgentInfos.m_data[v33];
          if ( v37->m_characters.m_size == (v37->m_characters.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v37->m_characters, 8);
          v37->m_characters.m_data[v37->m_characters.m_size++] = v36->m_character;
          LODWORD(m_size) = v44;
          v19 = aabbs;
          goto LABEL_28;
        }
        v38 = *(int *)v29->m_expansionMin;
      }
      v39 = mpWorld->m_obstacleGenerators.m_data[v38 - (int)m_size].m_pntr;
      if ( v32->m_obstacles.m_size == (v32->m_obstacles.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v32->m_obstacles, 8);
      v32->m_obstacles.m_data[v32->m_obstacles.m_size++] = v39;
LABEL_28:
      v29 = &v19[++v28];
    }
    while ( v29->m_min[0] <= v26[3] );
    v24 = v45;
    v27 = v43;
LABEL_30:
    v45 = ++v24;
    v25 = ++v41;
    v26 += 8;
  }
  while ( v24 < v27 );
  if ( v46 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v19, 32 * v46);
}

// File Line: 280
// RVA: 0xF1580
void __fastcall UFG::NavAvoidanceStrategyRVO::StartAvoidanceTasks(UFG::NavAvoidanceStrategyRVO *this, float deltaTime)
{
  hkArrayBase<hkaiCharacter *> *mpCharacters; // rax
  __int64 v4; // rdi
  __int64 m_size; // r14
  hkaiWorld *mpWorld; // rdx
  hkaiAvoidancePairProperties *m_pntr; // rax
  int v8; // r15d
  __int64 v9; // r12
  __int64 v10; // r13
  __int64 v11; // rcx
  hkaiLocalSteeringInput *v12; // r9
  hkaiCharacter *m_character; // r8
  UFG::AgentInfo *v14; // rbx
  hkaiAvoidanceSolverCommand *m_data; // rcx
  __int64 m_numCharactersPerAvoidanceJob; // r14
  int v17; // eax
  int v18; // r13d
  int v19; // edx
  __int64 v20; // rbx
  int v21; // eax
  hkVector4f *p_mUp; // rcx
  __int64 v23; // r12
  hkaiLocalSteeringInput *v24; // r13
  hkVector4f *v25; // r8
  UFG::AgentInfo *v26; // r15
  unsigned int v27; // ebx
  _BYTE steerVelocityOut[24]; // [rsp+48h] [rbp-80h] BYREF
  hkVector4f steerForwardOut; // [rsp+60h] [rbp-68h] BYREF
  hkJob job; // [rsp+70h] [rbp-58h] BYREF
  int v31; // [rsp+80h] [rbp-48h]
  hkVector4f v32; // [rsp+98h] [rbp-30h] BYREF
  __int64 v33; // [rsp+A8h] [rbp-20h]
  hkVector4f v34; // [rsp+B8h] [rbp-10h] BYREF
  hkaiAvoidanceSolver::SteeringAgent agentIn; // [rsp+C8h] [rbp+0h] BYREF
  hkResult result; // [rsp+238h] [rbp+170h] BYREF
  __int64 v37; // [rsp+248h] [rbp+180h]

  v33 = -2i64;
  mpCharacters = this->mpCharacters;
  v4 = 0i64;
  result.m_enum = HK_SUCCESS;
  m_size = mpCharacters->m_size;
  if ( UFG::HavokNavManager::ms_bEnableSteeringMT )
  {
    job.m_size = 80;
    job.m_threadAffinity = -1;
    *(_OWORD *)steerVelocityOut = 0i64;
    steerForwardOut.m_quad = (__m128)0i64;
    *(_DWORD *)&job.m_jobSubType = 0;
    *(_QWORD *)(&job.m_threadAffinity + 1) = 0i64;
    v31 = -1;
    mpWorld = this->mpWorld;
    *(float *)&steerVelocityOut[20] = mpWorld->m_erosionRadius;
    *(float *)&steerVelocityOut[16] = deltaTime;
    steerForwardOut.m_quad.m128_u64[0] = (unsigned __int64)mpWorld->m_streamingCollection.m_pntr->m_instances.m_data;
    m_pntr = mpWorld->m_avoidancePairProps.m_pntr;
    if ( m_pntr )
    {
      steerForwardOut.m_quad.m128_u64[1] = (unsigned __int64)m_pntr->m_avoidancePairDataMap.m_data;
      *(_DWORD *)&job.m_jobSubType = mpWorld->m_avoidancePairProps.m_pntr->m_avoidancePairDataMap.m_size;
    }
    v8 = 0;
    if ( m_size > 0 )
    {
      v9 = 0i64;
      v10 = 0i64;
      v11 = 0i64;
      v37 = 0i64;
      do
      {
        v12 = (hkaiLocalSteeringInput *)((char *)this->mLocalSteeringInputs.m_data + v11);
        m_character = v12->m_character;
        v14 = &this->mAgentInfos.m_data[v10];
        if ( v12->m_applyAvoidanceSteering.m_bool )
        {
          m_data = this->mCommands.m_data;
          m_data[v9].m_localSteeringInput.m_currentPosition = v12->m_currentPosition;
          m_data[v9].m_localSteeringInput.m_currentForward = v12->m_currentForward;
          m_data[v9].m_localSteeringInput.m_currentUp = v12->m_currentUp;
          m_data[v9].m_localSteeringInput.m_currentVelocity = v12->m_currentVelocity;
          m_data[v9].m_localSteeringInput.m_desiredVelocity = v12->m_desiredVelocity;
          m_data[v9].m_localSteeringInput.m_desiredFutureDir = v12->m_desiredFutureDir;
          m_data[v9].m_localSteeringInput.m_localGoalPlane = v12->m_localGoalPlane;
          m_data[v9].m_localSteeringInput.m_distToLocalGoal = v12->m_distToLocalGoal;
          m_data[v9].m_localSteeringInput.m_timeToLocalGoal = v12->m_timeToLocalGoal;
          m_data[v9].m_localSteeringInput.m_character = v12->m_character;
          m_data[v9].m_localSteeringInput.m_referenceFrame = v12->m_referenceFrame;
          m_data[v9].m_localSteeringInput.m_avoidanceProperties = v12->m_avoidanceProperties;
          m_data[v9].m_localSteeringInput.m_isLocalGoalLast.m_bool = v12->m_isLocalGoalLast.m_bool;
          m_data[v9].m_localSteeringInput.m_applyKinematicConstraints.m_bool = v12->m_applyKinematicConstraints.m_bool;
          m_data[v9].m_localSteeringInput.m_applyAvoidanceSteering.m_bool = v12->m_applyAvoidanceSteering.m_bool;
          m_data[v9].m_localSteeringInput.m_enableLocalSteering.m_bool = v12->m_enableLocalSteering.m_bool;
          m_data[v9].m_nearbyCharacters = v14->m_characters.m_data;
          m_data[v9].m_numNearbyCharacters = v14->m_characters.m_size;
          m_data[v9].m_obstacleGenerators = v14->m_obstacles.m_data;
          m_data[v9].m_numObstacleGenerators = v14->m_obstacles.m_size;
          m_data[v9].m_currentNavMeshFaceKey = m_character->m_currentNavMeshFace;
          m_data[v9].m_output = &v14->m_steerOut;
          result.m_enum = HK_FAILURE;
          ++v8;
          ++v9;
        }
        else
        {
          hkaiAvoidanceSolverUtils::calcUnsteeredVelocity(
            deltaTime,
            &this->mUp,
            &m_character->m_avoidanceProperties.m_pntr->m_movementProperties,
            v12,
            (hkVector4f *)&steerVelocityOut[8],
            &steerForwardOut);
          v14->m_steerOut.m_velocity = *(hkVector4f *)&steerVelocityOut[8];
          v14->m_steerOut.m_forwardAndResult = (hkVector4f)steerForwardOut.m_quad;
          v14->m_steerOut.m_forwardAndResult.m_quad.m128_i32[3] = 1056964608;
        }
        v11 = v37 + 160;
        v37 += 160i64;
        ++v10;
        --m_size;
      }
      while ( m_size );
    }
    m_numCharactersPerAvoidanceJob = this->mpWorld->m_numCharactersPerAvoidanceJob;
    v17 = (v8 + (int)m_numCharactersPerAvoidanceJob - 1) / (int)m_numCharactersPerAvoidanceJob;
    v18 = v17;
    if ( v17 > 0 )
    {
      v19 = v17 - 1;
      v20 = 0i64;
      v37 = 208 * m_numCharactersPerAvoidanceJob;
      do
      {
        *(_QWORD *)(&job.m_threadAffinity + 1) = (char *)this->mCommands.m_data + v20;
        v21 = m_numCharactersPerAvoidanceJob;
        if ( (_DWORD)v4 == v19 )
          v21 = v8;
        v31 = v21;
        hkJobQueue::addJob(this->mpJobQueue, &job, JOB_HIGH_PRIORITY);
        LODWORD(v4) = v4 + 1;
        v20 += v37;
        v8 -= m_numCharactersPerAvoidanceJob;
        v19 = v18 - 1;
      }
      while ( (int)v4 < v18 );
    }
    if ( result.m_enum )
      ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64))this->mpThreadPool->vfptr[5].__first_virtual_table_function__)(
        this->mpThreadPool,
        this->mpJobQueue,
        12i64);
  }
  else if ( m_size > 0 )
  {
    p_mUp = &this->mUp;
    v23 = 0i64;
    do
    {
      v24 = &this->mLocalSteeringInputs.m_data[v23];
      v25 = (hkVector4f *)v24->m_character;
      v26 = this->mAgentInfos.m_data;
      if ( v24->m_applyAvoidanceSteering.m_bool )
      {
        v27 = v25[6].m_quad.m128_u32[0];
        hkaiObstacleCollector::hkaiObstacleCollector(
          (hkaiObstacleCollector *)&job,
          *(int *)((char *)&v26->m_characters.m_size + v4),
          v25 + 2,
          p_mUp);
        hkaiAvoidanceSolverUtils::setupAgent(
          v24,
          this->mpWorld->m_streamingCollection.m_pntr->m_instances.m_data,
          v27,
          this->mpWorld->m_erosionRadius,
          (hkArrayBase<hkaiCharacter const *> *)((char *)&v26->m_characters + v4),
          (hkArrayBase<hkaiObstacleGenerator const *> *)((char *)&v26->m_obstacles + v4),
          this->mpWorld->m_avoidancePairProps.m_pntr,
          &agentIn,
          (hkaiObstacleCollector *)&job);
        hkaiAvoidanceSolverUtils::calcSteeringVelocity(
          &result,
          deltaTime,
          &this->mUp,
          &agentIn,
          &steerForwardOut,
          (hkVector4f *)&steerVelocityOut[8]);
        *(hkVector4f *)((char *)&v26->m_steerOut.m_velocity + v4) = (hkVector4f)steerForwardOut.m_quad;
        *(hkVector4f *)((char *)&v26->m_steerOut.m_forwardAndResult + v4) = *(hkVector4f *)&steerVelocityOut[8];
        *(int *)((char *)&v26->m_steerOut.m_forwardAndResult.m_quad.m128_i32[3] + v4) = result.m_enum | 0x3F000000;
        hkaiObstacleCollector::~hkaiObstacleCollector((hkaiObstacleCollector *)&job);
      }
      else
      {
        hkaiAvoidanceSolverUtils::calcUnsteeredVelocity(
          deltaTime,
          p_mUp,
          (hkaiMovementProperties *)(v25[9].m_quad.m128_u64[1] + 16),
          v24,
          &v34,
          &v32);
        *(hkVector4f *)((char *)&v26->m_steerOut.m_forwardAndResult + v4) = (hkVector4f)v32.m_quad;
        *(int *)((char *)&v26->m_steerOut.m_forwardAndResult.m_quad.m128_i32[3] + v4) = 1056964608;
        *(hkVector4f *)((char *)&v26->m_steerOut.m_velocity + v4) = (hkVector4f)v34.m_quad;
      }
      ++v23;
      v4 += 64i64;
      --m_size;
      p_mUp = &this->mUp;
    }
    while ( m_size );
  }
}

// File Line: 400
// RVA: 0xECD20
void __fastcall UFG::NavAvoidanceStrategyRVO::GatherResult(UFG::NavAvoidanceStrategyRVO *this, float deltaTime)
{
  __int64 m_size; // r12
  int v3; // edi
  __int64 v5; // r14
  __int64 v6; // rsi
  UFG::AgentInfo *m_data; // rax
  int v8; // ebx
  hkaiLocalSteeringInput *v9; // rdx
  __m128 m_quad; // xmm1
  __m128 *p_m_quad; // r13
  hkaiCharacter *m_character; // r15
  unsigned int v13; // ebx
  __m128 v14; // xmm1
  hkArrayBase<hkaiBehavior *> *mpBehaviors; // rax
  __int64 v16; // rbx
  hkVector4f localVel; // [rsp+20h] [rbp-58h] BYREF
  hkVector4f worldVel; // [rsp+30h] [rbp-48h] BYREF

  m_size = this->mpCharacters->m_size;
  v3 = 0;
  if ( m_size > 0 )
  {
    v5 = 0i64;
    v6 = 0i64;
    do
    {
      m_data = this->mAgentInfos.m_data;
      v8 = m_data[v6].m_steerOut.m_forwardAndResult.m_quad.m128_i32[3];
      v9 = &this->mLocalSteeringInputs.m_data[v5];
      m_quad = m_data[v6].m_steerOut.m_velocity.m_quad;
      localVel.m_quad = m_quad;
      p_m_quad = &v9->m_referenceFrame->m_transform.m_rotation.m_col0.m_quad;
      m_character = v9->m_character;
      v13 = v8 & 0xC0FFFFFF;
      if ( p_m_quad )
      {
        hkaiReferenceFrame::transformLocalPosVelToWorldVel(
          v9->m_referenceFrame,
          &v9->m_currentPosition,
          &localVel,
          &worldVel);
        v14 = _mm_mul_ps(p_m_quad[5], this->mUp.m_quad);
        m_quad = _mm_shuffle_ps(
                   worldVel.m_quad,
                   _mm_unpackhi_ps(
                     worldVel.m_quad,
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                         _mm_shuffle_ps(v14, v14, 170)),
                       _mm_shuffle_ps(localVel.m_quad, localVel.m_quad, 255))),
                   196);
      }
      m_character->m_velocity.m_quad = m_quad;
      hkaiCharacter::setAvoidanceState(m_character, (hkResult)v13);
      ++v5;
      ++v6;
      --m_size;
    }
    while ( m_size );
  }
  mpBehaviors = this->mpBehaviors;
  if ( mpBehaviors->m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      ((void (__fastcall *)(hkaiBehavior *))mpBehaviors->m_data[v16]->hkReferencedObject::hkBaseObject::vfptr[2].__vecDelDtor)(mpBehaviors->m_data[v16]);
      mpBehaviors = this->mpBehaviors;
      ++v3;
      ++v16;
    }
    while ( v3 < mpBehaviors->m_size );
  }
}

// File Line: 456
// RVA: 0xE4C00
void __fastcall UFG::NavAvoidanceStrategyRVO::NavAvoidanceStrategyRVO(
        UFG::NavAvoidanceStrategyRVO *this,
        hkaiWorld *pWorld,
        hkJobQueue *pJobQueue,
        hkJobThreadPool *pThreadPool,
        hkaiAvoidanceProperties::AvoidanceSolverType solverType)
{
  int v9; // ebx
  int v10; // r9d
  int m_size; // ecx

  UFG::NavAvoidanceStrategy::NavAvoidanceStrategy(this);
  this->vfptr = (UFG::NavAvoidanceStrategyVtbl *)&UFG::NavAvoidanceStrategyRVO::`vftable;
  this->mpWorld = pWorld;
  v9 = 0;
  this->mAgentInfos.m_data = 0i64;
  this->mAgentInfos.m_size = 0;
  this->mAgentInfos.m_capacityAndFlags = 0x80000000;
  this->mLocalSteeringInputs.m_data = 0i64;
  this->mLocalSteeringInputs.m_size = 0;
  this->mLocalSteeringInputs.m_capacityAndFlags = 0x80000000;
  this->mCommands.m_data = 0i64;
  this->mCommands.m_size = 0;
  this->mCommands.m_capacityAndFlags = 0x80000000;
  this->mpJobQueue = pJobQueue;
  this->mpThreadPool = pThreadPool;
  this->mNumCharacters = 0;
  UFG::NavAvoidanceStrategyRVO::msAvoidanceSolverType = solverType;
  this->mUp.m_quad = _xmm;
  if ( (this->mCommands.m_capacityAndFlags & 0x3FFFFFFFu) < 0x1F4 )
  {
    v10 = 500;
    if ( 2 * (this->mCommands.m_capacityAndFlags & 0x3FFFFFFF) > 500 )
      v10 = 2 * (this->mCommands.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&solverType, &hkContainerHeapAllocator::s_alloc, &this->mCommands, v10, 208);
  }
  m_size = this->mCommands.m_size;
  solverType = AVOIDANCE_SOLVER_SAMPLING;
  if ( 500 - m_size > 0 )
  {
    do
      solverType = ++v9;
    while ( v9 < 500 - this->mCommands.m_size );
  }
  this->mCommands.m_size = 500;
  this->mpCharacters = &UFG::NavModuleLocalRVO::ms_aCharacters;
  this->mpBehaviors = &UFG::NavModuleLocalRVO::ms_aBehaviors;
}

// File Line: 480
// RVA: 0xE6190
void __fastcall UFG::NavAvoidanceStrategyRVO::~NavAvoidanceStrategyRVO(UFG::NavAvoidanceStrategyRVO *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // eax
  int v4; // edi
  UFG::AgentInfo *v5; // rsi
  int v6; // r8d

  this->vfptr = (UFG::NavAvoidanceStrategyVtbl *)&UFG::NavAvoidanceStrategyRVO::`vftable;
  this->mCommands.m_size = 0;
  m_capacityAndFlags = this->mCommands.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mCommands.m_data,
      208 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->mCommands.m_data = 0i64;
  this->mCommands.m_capacityAndFlags = 0x80000000;
  this->mLocalSteeringInputs.m_size = 0;
  v3 = this->mLocalSteeringInputs.m_capacityAndFlags;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mLocalSteeringInputs.m_data,
      160 * (v3 & 0x3FFFFFFF));
  this->mLocalSteeringInputs.m_data = 0i64;
  this->mLocalSteeringInputs.m_capacityAndFlags = 0x80000000;
  v4 = this->mAgentInfos.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &this->mAgentInfos.m_data[(__int64)v4];
    do
    {
      UFG::AgentInfo::~AgentInfo(v5--);
      --v4;
    }
    while ( v4 >= 0 );
  }
  this->mAgentInfos.m_size = 0;
  v6 = this->mAgentInfos.m_capacityAndFlags;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mAgentInfos.m_data,
      v6 << 6);
  this->mAgentInfos.m_data = 0i64;
  this->mAgentInfos.m_capacityAndFlags = 0x80000000;
  UFG::NavAvoidanceStrategy::~NavAvoidanceStrategy(this);
}

// File Line: 484
// RVA: 0xF2720
void __fastcall UFG::NavAvoidanceStrategyRVO::Update(
        UFG::NavAvoidanceStrategyRVO *this,
        UFG::UpdatePhase phase,
        float deltaTime)
{
  hkArrayBase<hkaiCharacter *> *mpCharacters; // r8
  __int64 m_size; // r14
  bool v6; // cl
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  int v14; // edi
  UFG::AgentInfo *v15; // rbp
  int v16; // eax
  int v17; // eax
  int v18; // r9d
  int v19; // edi
  UFG::AgentInfo *v20; // rbp
  int v21; // ebp
  UFG::AgentInfo *v22; // rdi
  __int64 v23; // rcx
  bool v24; // zf
  UFG::AgentInfo *v25; // rcx
  hkResult result; // [rsp+88h] [rbp+10h] BYREF
  UFG::AgentInfo *v27; // [rsp+98h] [rbp+20h]

  mpCharacters = this->mpCharacters;
  m_size = mpCharacters->m_size;
  if ( phase == UPDATE_PHASE_PART1 )
    this->mNumCharacters = m_size;
  if ( (_DWORD)m_size && !UFG::NavComponent::ms_bDisableNavigation )
  {
    v6 = UFG::HavokNavManager::ms_bEnableSteeringMT && this->mpJobQueue && this->mpThreadPool;
    if ( phase )
    {
      v7 = phase - 1;
      if ( v7 )
      {
        if ( v7 == 1 )
        {
          if ( v6 )
            ((void (__fastcall *)(hkJobThreadPool *))this->mpThreadPool->vfptr[2].__vecDelDtor)(this->mpThreadPool);
          UFG::NavAvoidanceStrategyRVO::GatherResult(this, deltaTime);
        }
      }
      else
      {
        if ( v6 )
          ((void (__fastcall *)(hkJobThreadPool *))this->mpThreadPool->vfptr[2].__vecDelDtor)(this->mpThreadPool);
        UFG::NavAvoidanceStrategyRVO::DetectOverlaps(this);
        UFG::NavAvoidanceStrategyRVO::StartAvoidanceTasks(this, deltaTime);
      }
    }
    else
    {
      v8 = UFG::NavAvoidanceStrategyRVO::msStepCharactersMTMin;
      if ( mpCharacters->m_size / UFG::NavAvoidanceStrategyRVO::msStepCharactersMTRatio > UFG::NavAvoidanceStrategyRVO::msStepCharactersMTMin )
        v8 = mpCharacters->m_size / UFG::NavAvoidanceStrategyRVO::msStepCharactersMTRatio;
      v9 = UFG::NavAvoidanceStrategyRVO::msStepCharactersMTMax;
      if ( v8 < UFG::NavAvoidanceStrategyRVO::msStepCharactersMTMax )
        v9 = v8;
      this->mpWorld->m_numCharactersPerAvoidanceJob = v9;
      this->mpWorld->m_numBehaviorUpdatesPerJob = v9;
      v10 = 0;
      this->mLocalSteeringInputs.m_size = 0;
      v11 = this->mLocalSteeringInputs.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v11 < (int)m_size )
      {
        v12 = 2 * v11;
        v13 = m_size;
        if ( (int)m_size < v12 )
          v13 = v12;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->mLocalSteeringInputs, v13, 160);
      }
      this->mLocalSteeringInputs.m_size = m_size;
      v14 = this->mAgentInfos.m_size - 1;
      if ( v14 >= 0 )
      {
        v15 = &this->mAgentInfos.m_data[(__int64)v14];
        do
        {
          UFG::AgentInfo::~AgentInfo(v15--);
          --v14;
        }
        while ( v14 >= 0 );
      }
      this->mAgentInfos.m_size = 0;
      v16 = this->mAgentInfos.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v16 < (int)m_size )
      {
        v17 = 2 * v16;
        v18 = m_size;
        if ( (int)m_size < v17 )
          v18 = v17;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->mAgentInfos, v18, 64);
      }
      v19 = this->mAgentInfos.m_size - m_size - 1;
      if ( v19 >= 0 )
      {
        v20 = &this->mAgentInfos.m_data[m_size + v19];
        do
        {
          UFG::AgentInfo::~AgentInfo(v20--);
          --v19;
        }
        while ( v19 >= 0 );
      }
      v21 = m_size - this->mAgentInfos.m_size;
      v22 = &this->mAgentInfos.m_data[(__int64)this->mAgentInfos.m_size];
      result.m_enum = HK_SUCCESS;
      if ( v21 > 0 )
      {
        do
        {
          v23 = (__int64)v10 << 6;
          v24 = (UFG::AgentInfo *)((char *)v22 + v23) == 0i64;
          v25 = (UFG::AgentInfo *)((char *)v22 + v23);
          v27 = v25;
          if ( !v24 )
            UFG::AgentInfo::AgentInfo(v25);
          result.m_enum = ++v10;
        }
        while ( v10 < v21 );
      }
      this->mAgentInfos.m_size = m_size;
      UFG::NavAvoidanceStrategyRVO::UpdateGenerators(this);
      UFG::NavAvoidanceStrategyRVO::CalcDesiredVelocities(this, deltaTime);
    }
  }
}

// File Line: 561
// RVA: 0xF0E80
void __fastcall UFG::NavAvoidanceStrategyRVO::SetLocalModuleFor(
        UFG::NavAvoidanceStrategyRVO *this,
        UFG::NavComponent *pNavComponent)
{
  UFG::NavComponent::SetLocalModule<UFG::NavModuleLocalRVO>(pNavComponent);
}

