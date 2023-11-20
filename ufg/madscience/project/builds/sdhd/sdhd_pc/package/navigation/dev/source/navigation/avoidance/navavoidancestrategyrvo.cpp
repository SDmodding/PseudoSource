// File Line: 141
// RVA: 0xE8A10
void __usercall UFG::NavAvoidanceStrategyRVO::CalcDesiredVelocities(UFG::NavAvoidanceStrategyRVO *this@<rcx>, float deltaTime@<xmm1>, signed __int64 a3@<rdx>)
{
  UFG::NavAvoidanceStrategyRVO *v3; // r14
  hkaiWorld *v4; // rax
  hkArrayBase<hkaiBehavior *> *v5; // rcx
  int v6; // er8
  __int64 v7; // r12
  int v8; // er13
  int v9; // eax
  __int64 v10; // rdx
  int v11; // ecx
  __int64 v12; // r9
  int v13; // edi
  int v14; // esi
  __int64 v15; // rbx
  __int64 v16; // rbp
  int v17; // eax
  hkArrayBase<hkaiBehavior *> *v18; // rax
  hkaiLocalSteeringInput *v19; // rdi
  unsigned int v20; // esi
  int v21; // er15
  __int64 v22; // rbx
  int v23; // eax
  __int64 v24; // rcx
  signed __int64 v25; // [rsp+20h] [rbp-98h]
  hkJob job; // [rsp+30h] [rbp-88h]
  __int128 v27; // [rsp+40h] [rbp-78h]
  __int64 v28; // [rsp+50h] [rbp-68h]
  int v29; // [rsp+58h] [rbp-60h]
  __int64 v30; // [rsp+60h] [rbp-58h]
  int v31; // [rsp+68h] [rbp-50h]
  float v32; // [rsp+6Ch] [rbp-4Ch]
  int v33; // [rsp+C0h] [rbp+8h]
  int v34; // [rsp+D0h] [rbp+18h]
  int v35; // [rsp+D8h] [rbp+20h]

  v3 = this;
  if ( this->mpJobQueue && this->mpThreadPool )
  {
    v32 = deltaTime;
    job.m_size = 64;
    *(_WORD *)&job.m_jobSubType = 3073;
    job.m_threadAffinity = -1;
    v29 = -1;
    v31 = -1;
    _mm_store_si128((__m128i *)&v27, (__m128i)0i64);
    v4 = this->mpWorld;
    v5 = this->mpBehaviors;
    v28 = 0i64;
    v30 = 0i64;
    job.m_jobSpuType.m_storage = 2;
    v6 = v4->m_numBehaviorUpdatesPerJob;
    v7 = (__int64)v5->m_data;
    v8 = 0;
    v34 = v6;
    v9 = (v6 + v5->m_size - 1) / v6;
    v10 = (__int64)v3->mLocalSteeringInputs.m_data;
    v25 = (signed __int64)v3->mLocalSteeringInputs.m_data;
    v35 = v9;
    if ( v9 > 0 )
    {
      v11 = 0;
      LODWORD(v12) = v9 - 1;
      v33 = 0;
      do
      {
        if ( v8 == (_DWORD)v12 )
          v13 = v3->mpBehaviors->m_size - v11;
        else
          v13 = v6;
        v28 = v7;
        v29 = v13;
        v14 = 0;
        if ( v13 > 0 )
        {
          v15 = v7;
          v16 = (unsigned int)v13;
          do
          {
            v17 = (*(__int64 (**)(void))(**(_QWORD **)v15 + 96i64))();
            v15 += 8i64;
            v14 += v17;
            --v16;
          }
          while ( v16 );
          v10 = v25;
        }
        v30 = v10;
        v7 += 8i64 * v13;
        v31 = v14;
        v25 = 160i64 * v14 + v10;
        hkJobQueue::addJob(v3->mpJobQueue, &job, 0);
        v6 = v34;
        v10 = v25;
        ++v8;
        v11 = v34 + v33;
        v12 = (unsigned int)(v35 - 1);
        v33 += v34;
      }
      while ( v8 < v35 );
      if ( v35 > 0 )
      {
        ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64, __int64))v3->mpThreadPool->vfptr[5].__first_virtual_table_function__)(
          v3->mpThreadPool,
          v3->mpJobQueue,
          12i64,
          v12);
        ((void (*)(void))v3->mpThreadPool->vfptr[2].__vecDelDtor)();
        hkJobQueue::processAllJobs(v3->mpJobQueue, 1);
      }
    }
  }
  else
  {
    v18 = this->mpBehaviors;
    v19 = this->mLocalSteeringInputs.m_data;
    v20 = this->mLocalSteeringInputs.m_size;
    v21 = 0;
    if ( v18->m_size > 0 )
    {
      v22 = 0i64;
      do
      {
        v23 = ((__int64 (__fastcall *)(hkaiBehavior *, signed __int64, hkaiLocalSteeringInput *, _QWORD))v18->m_data[v22]->vfptr[1].__first_virtual_table_function__)(
                v18->m_data[v22],
                a3,
                v19,
                v20);
        ++v21;
        ++v22;
        v24 = v23;
        v20 -= v23;
        v18 = v3->mpBehaviors;
        a3 = 160 * v24;
        v19 += v24;
      }
      while ( v21 < v18->m_size );
    }
  }
}

// File Line: 200
// RVA: 0xF3B60
void __fastcall UFG::NavAvoidanceStrategyRVO::UpdateGenerators(UFG::NavAvoidanceStrategyRVO *this)
{
  hkaiWorld *v1; // rsi
  int v2; // ebx
  __int64 v3; // rdi

  v1 = this->mpWorld;
  v2 = 0;
  if ( v1->m_obstacleGenerators.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      ((void (*)(void))v1->m_obstacleGenerators.m_data[v3].m_pntr->vfptr[1].__first_virtual_table_function__)();
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_obstacleGenerators.m_size );
  }
}

// File Line: 209
// RVA: 0xE9C30
void __fastcall UFG::NavAvoidanceStrategyRVO::DetectOverlaps(UFG::NavAvoidanceStrategyRVO *this)
{
  UFG::NavAvoidanceStrategyRVO *v1; // rbp
  __int64 v2; // r12
  hkaiWorld *v3; // r13
  __int64 v4; // r14
  int v5; // er15
  int v6; // eax
  hk1AxisSweep::AabbInt *v7; // rcx
  unsigned int v8; // edx
  int v9; // ebx
  __int64 v10; // rdi
  __int64 v11; // rsi
  hk1AxisSweep::AabbInt *v12; // r12
  __m128 *v13; // rcx
  __m128 *v14; // rax
  __m128 v15; // xmm1
  __int64 v16; // rdi
  __int64 v17; // rsi
  bool v18; // zf
  bool v19; // sf
  hk1AxisSweep::AabbInt *v20; // r14
  hkaiObstacleGenerator *v21; // rcx
  signed __int64 v22; // rax
  int v23; // ebx
  signed __int64 v24; // rax
  int v25; // ecx
  signed __int64 v26; // rax
  unsigned int *v27; // rsi
  int v28; // edx
  signed __int64 v29; // r15
  hk1AxisSweep::AabbInt *v30; // r9
  __int64 v31; // rdx
  __int64 v32; // r8
  bool v33; // cl
  __m128 *v34; // rbx
  __int64 v35; // rdi
  signed __int64 v36; // r12
  __int64 v37; // r14
  signed __int64 v38; // r14
  __m128 *v39; // rbx
  __int64 v40; // rcx
  hkaiObstacleGenerator *v41; // rdi
  hk1AxisSweep::AabbInt *aabbs; // [rsp+20h] [rbp-98h]
  signed __int64 v43; // [rsp+28h] [rbp-90h]
  hkAabb aabbIn; // [rsp+50h] [rbp-68h]
  int v45; // [rsp+C0h] [rbp+8h]
  int v46; // [rsp+C8h] [rbp+10h]
  int v47; // [rsp+D0h] [rbp+18h]
  int v48; // [rsp+D8h] [rbp+20h]

  v1 = this;
  v2 = this->mpCharacters->m_size;
  v46 = v2;
  v3 = this->mpWorld;
  v4 = v3->m_obstacleGenerators.m_size;
  v5 = v4 + v2;
  v6 = v4 + v2 + 4;
  if ( (_DWORD)v4 + (_DWORD)v2 == -4 )
  {
    v7 = 0i64;
  }
  else
  {
    v45 = 32 * v6;
    v7 = (hk1AxisSweep::AabbInt *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                    &v45);
    v6 = v45 / 32;
  }
  aabbs = v7;
  v8 = 2147483648;
  if ( v6 )
    v8 = v6;
  v48 = v8;
  v9 = 0;
  if ( (signed int)v2 > 0 )
  {
    v10 = 0i64;
    v11 = v2;
    v12 = v7;
    do
    {
      v13 = (__m128 *)v1->mLocalSteeringInputs.m_data[v10].m_character;
      v14 = (__m128 *)v13[9].m128_u64[1];
      v15 = v14[5];
      aabbIn.m_min.m_quad = _mm_add_ps(v14[4], v13[2]);
      aabbIn.m_max.m_quad = _mm_add_ps(v15, v13[2]);
      hk1AxisSweep::AabbInt::set(&v12[v9], &aabbIn, v9);
      ++v9;
      ++v10;
      --v11;
    }
    while ( v11 );
    LODWORD(v2) = v46;
  }
  v16 = 0i64;
  v17 = v4;
  v18 = (_DWORD)v4 == 0;
  v19 = (signed int)v4 < 0;
  v20 = aabbs;
  if ( !v19 && !v18 )
  {
    do
    {
      v21 = v3->m_obstacleGenerators.m_data[v16].m_pntr;
      ((void (__fastcall *)(hkaiObstacleGenerator *, hkAabb *))v21->vfptr[2].__first_virtual_table_function__)(
        v21,
        &aabbIn);
      hk1AxisSweep::AabbInt::set(&aabbs[v9], &aabbIn, v9);
      ++v16;
      ++v9;
    }
    while ( v16 < v17 );
  }
  v22 = v9;
  v23 = v9 + 1;
  aabbs[v22].m_min[0] = -1;
  v24 = v23++;
  aabbs[v24].m_min[0] = -1;
  aabbs[v23].m_min[0] = -1;
  aabbs[v23 + 1].m_min[0] = -1;
  hk1AxisSweep::sortAabbs(aabbs, v5);
  v25 = 0;
  v47 = 0;
  v45 = v5 - 1;
  v26 = 1i64;
  v43 = 1i64;
  v27 = &aabbs->m_min[1];
  v28 = v5 - 1;
  do
  {
    v29 = v26;
    v30 = (hk1AxisSweep::AabbInt *)(v27 + 7);
    if ( v27[7] > v27[3] )
      goto LABEL_30;
    do
    {
      if ( (((v30->m_max[1] - *v27) | (v27[4] - v30->m_min[1]) | (v30->m_max[2] - v27[1]) | (v27[5] - v30->m_min[2])) & 0x80000000) != 0 )
        goto LABEL_28;
      v31 = (signed int)v27[2];
      v32 = *(signed int *)v30->m_expansionMin;
      v33 = (signed int)v32 < (signed int)v2;
      if ( (signed int)v31 >= (signed int)v2 )
      {
        if ( !v33 )
          goto LABEL_28;
        v40 = (signed int)v27[2];
        v34 = &v1->mAgentInfos.m_data[v32].m_steerOut.m_forwardAndResult.m_quad;
      }
      else
      {
        v34 = &v1->mAgentInfos.m_data[v31].m_steerOut.m_forwardAndResult.m_quad;
        if ( v33 )
        {
          v35 = *(signed int *)v30->m_expansionMin;
          v36 = (signed __int64)&v1->mLocalSteeringInputs.m_data[v32];
          v37 = (signed int)v27[2];
          if ( v34[2].m128_i32[2] == (v34[2].m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v34[2], 8);
          *(_QWORD *)(v34[2].m128_u64[0] + 8i64 * v34[2].m128_i32[2]++) = *(_QWORD *)(v36 + 120);
          v38 = (signed __int64)&v1->mLocalSteeringInputs.m_data[v37];
          v39 = &v1->mAgentInfos.m_data[v35].m_steerOut.m_forwardAndResult.m_quad;
          if ( v39[2].m128_i32[2] == (v39[2].m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v39[2], 8);
          *(_QWORD *)(v39[2].m128_u64[0] + 8i64 * v39[2].m128_i32[2]++) = *(_QWORD *)(v38 + 120);
          LODWORD(v2) = v46;
          v20 = aabbs;
          goto LABEL_28;
        }
        v40 = *(signed int *)v30->m_expansionMin;
      }
      v41 = v3->m_obstacleGenerators.m_data[v40 - (signed int)v2].m_pntr;
      if ( v34[3].m128_i32[2] == (v34[3].m128_i32[3] & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v34[3], 8);
      *(_QWORD *)(v34[3].m128_u64[0] + 8i64 * v34[3].m128_i32[2]++) = v41;
LABEL_28:
      v30 = &v20[++v29];
    }
    while ( v30->m_min[0] <= v27[3] );
    v25 = v47;
    v28 = v45;
LABEL_30:
    v47 = ++v25;
    v26 = v43++ + 1;
    v27 += 8;
  }
  while ( v25 < v28 );
  if ( v48 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v20,
      32 * v48);
}

// File Line: 280
// RVA: 0xF1580
void __fastcall UFG::NavAvoidanceStrategyRVO::StartAvoidanceTasks(UFG::NavAvoidanceStrategyRVO *this, float deltaTime)
{
  UFG::NavAvoidanceStrategyRVO *v2; // rsi
  hkArrayBase<hkaiCharacter *> *v3; // rax
  __int64 v4; // rdi
  __int64 v5; // r14
  hkaiWorld *v6; // rdx
  hkaiAvoidancePairProperties *v7; // rax
  int v8; // er15
  __int64 v9; // r12
  __int64 v10; // r13
  __int64 v11; // rcx
  hkaiLocalSteeringInput *v12; // r9
  hkaiCharacter *v13; // r8
  UFG::AgentInfo *v14; // rbx
  hkaiAvoidanceSolverCommand *v15; // rcx
  __int64 v16; // r14
  int v17; // eax
  signed int v18; // er13
  int v19; // edx
  __int64 v20; // rbx
  int v21; // eax
  hkVector4f *v22; // rcx
  __int64 v23; // r12
  hkaiLocalSteeringInput *v24; // r13
  hkVector4f *v25; // r8
  UFG::AgentInfo *v26; // r15
  unsigned int v27; // ebx
  hkVector4f steerVelocityOut; // [rsp+48h] [rbp-80h]
  float v29; // [rsp+58h] [rbp-70h]
  char steerForwardOut[12]; // [rsp+5Ch] [rbp-6Ch]
  hkaiAvoidancePairProperties::PairData *v31; // [rsp+68h] [rbp-60h]
  hkJob job; // [rsp+70h] [rbp-58h]
  int v33; // [rsp+80h] [rbp-48h]
  hkVector4f v34; // [rsp+98h] [rbp-30h]
  __int64 v35; // [rsp+A8h] [rbp-20h]
  hkVector4f v36; // [rsp+B8h] [rbp-10h]
  hkaiAvoidanceSolver::SteeringAgent agentIn; // [rsp+C8h] [rbp+0h]
  hkResult result; // [rsp+238h] [rbp+170h]
  __int64 v39; // [rsp+248h] [rbp+180h]

  v35 = -2i64;
  v2 = this;
  v3 = this->mpCharacters;
  v4 = 0i64;
  result.m_enum = 0;
  v5 = v3->m_size;
  if ( UFG::HavokNavManager::ms_bEnableSteeringMT )
  {
    *(_WORD *)&job.m_jobSubType = 3072;
    job.m_jobSpuType.m_storage = 1;
    job.m_size = 80;
    job.m_threadAffinity = -1;
    _mm_store_si128((__m128i *)&steerVelocityOut, (__m128i)0i64);
    *(_QWORD *)&steerForwardOut[4] = 0i64;
    v31 = 0i64;
    *(_DWORD *)&job.m_jobSubType = 0;
    *(_QWORD *)(&job.m_threadAffinity + 1) = 0i64;
    v33 = -1;
    v6 = this->mpWorld;
    *(_QWORD *)steerForwardOut = LODWORD(v6->m_erosionRadius);
    v29 = deltaTime;
    *(_QWORD *)&steerForwardOut[4] = v6->m_streamingCollection.m_pntr->m_instances.m_data;
    v7 = v6->m_avoidancePairProps.m_pntr;
    if ( v7 )
    {
      v31 = v7->m_avoidancePairDataMap.m_data;
      *(_DWORD *)&job.m_jobSubType = v6->m_avoidancePairProps.m_pntr->m_avoidancePairDataMap.m_size;
    }
    v8 = 0;
    if ( v5 > 0 )
    {
      v9 = 0i64;
      v10 = 0i64;
      v11 = 0i64;
      v39 = 0i64;
      do
      {
        v12 = (hkaiLocalSteeringInput *)((char *)v2->mLocalSteeringInputs.m_data + v11);
        v13 = v12->m_character;
        v14 = &v2->mAgentInfos.m_data[v10];
        if ( v12->m_applyAvoidanceSteering.m_bool )
        {
          v15 = v2->mCommands.m_data;
          v15[v9].m_localSteeringInput.m_currentPosition = v12->m_currentPosition;
          v15[v9].m_localSteeringInput.m_currentForward = v12->m_currentForward;
          v15[v9].m_localSteeringInput.m_currentUp = v12->m_currentUp;
          v15[v9].m_localSteeringInput.m_currentVelocity = v12->m_currentVelocity;
          v15[v9].m_localSteeringInput.m_desiredVelocity = v12->m_desiredVelocity;
          v15[v9].m_localSteeringInput.m_desiredFutureDir = v12->m_desiredFutureDir;
          v15[v9].m_localSteeringInput.m_localGoalPlane = v12->m_localGoalPlane;
          v15[v9].m_localSteeringInput.m_distToLocalGoal = v12->m_distToLocalGoal;
          v15[v9].m_localSteeringInput.m_timeToLocalGoal = v12->m_timeToLocalGoal;
          v15[v9].m_localSteeringInput.m_character = v12->m_character;
          v15[v9].m_localSteeringInput.m_referenceFrame = v12->m_referenceFrame;
          v15[v9].m_localSteeringInput.m_avoidanceProperties = v12->m_avoidanceProperties;
          v15[v9].m_localSteeringInput.m_isLocalGoalLast.m_bool = v12->m_isLocalGoalLast.m_bool;
          v15[v9].m_localSteeringInput.m_applyKinematicConstraints.m_bool = v12->m_applyKinematicConstraints.m_bool;
          v15[v9].m_localSteeringInput.m_applyAvoidanceSteering.m_bool = v12->m_applyAvoidanceSteering.m_bool;
          v15[v9].m_localSteeringInput.m_enableLocalSteering.m_bool = v12->m_enableLocalSteering.m_bool;
          v15[v9].m_nearbyCharacters = v14->m_characters.m_data;
          v15[v9].m_numNearbyCharacters = v14->m_characters.m_size;
          v15[v9].m_obstacleGenerators = v14->m_obstacles.m_data;
          v15[v9].m_numObstacleGenerators = v14->m_obstacles.m_size;
          v15[v9].m_currentNavMeshFaceKey = v13->m_currentNavMeshFace;
          v15[v9].m_output = &v14->m_steerOut;
          result.m_enum = 1;
          ++v8;
          ++v9;
        }
        else
        {
          hkaiAvoidanceSolverUtils::calcUnsteeredVelocity(
            deltaTime,
            &v2->mUp,
            &v13->m_avoidanceProperties.m_pntr->m_movementProperties,
            v12,
            (hkVector4f *)((char *)&steerVelocityOut + 8),
            (hkVector4f *)&steerForwardOut[4]);
          v14->m_steerOut.m_velocity = *(hkVector4f *)((char *)&steerVelocityOut + 8);
          v14->m_steerOut.m_forwardAndResult = *(hkVector4f *)&steerForwardOut[4];
          v14->m_steerOut.m_forwardAndResult.m_quad.m128_i32[3] = 1056964608;
        }
        v11 = v39 + 160;
        v39 += 160i64;
        ++v10;
        --v5;
      }
      while ( v5 );
    }
    v16 = v2->mpWorld->m_numCharactersPerAvoidanceJob;
    v17 = (v8 + (signed int)v16 - 1) / (signed int)v16;
    v18 = v17;
    if ( v17 > 0 )
    {
      v19 = v17 - 1;
      v20 = 0i64;
      v39 = 208 * v16;
      do
      {
        *(_QWORD *)(&job.m_threadAffinity + 1) = (char *)v2->mCommands.m_data + v20;
        v21 = v16;
        if ( (_DWORD)v4 == v19 )
          v21 = v8;
        v33 = v21;
        hkJobQueue::addJob(v2->mpJobQueue, &job, 0);
        LODWORD(v4) = v4 + 1;
        v20 += v39;
        v8 -= v16;
        v19 = v18 - 1;
      }
      while ( (signed int)v4 < v18 );
    }
    if ( result.m_enum )
      ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64))v2->mpThreadPool->vfptr[5].__first_virtual_table_function__)(
        v2->mpThreadPool,
        v2->mpJobQueue,
        12i64);
  }
  else if ( v5 > 0 )
  {
    v22 = &this->mUp;
    v23 = 0i64;
    do
    {
      v24 = &v2->mLocalSteeringInputs.m_data[v23];
      v25 = (hkVector4f *)v24->m_character;
      v26 = v2->mAgentInfos.m_data;
      if ( v24->m_applyAvoidanceSteering.m_bool )
      {
        v27 = v25[6].m_quad.m128_u32[0];
        hkaiObstacleCollector::hkaiObstacleCollector(
          (hkaiObstacleCollector *)&job,
          *(int *)((char *)&v26->m_characters.m_size + v4),
          v25 + 2,
          v22);
        hkaiAvoidanceSolverUtils::setupAgent(
          v24,
          v2->mpWorld->m_streamingCollection.m_pntr->m_instances.m_data,
          v27,
          v2->mpWorld->m_erosionRadius,
          (hkArrayBase<hkaiCharacter const *> *)((char *)&v26->m_characters.m_data + v4),
          (hkArrayBase<hkaiObstacleGenerator const *> *)((char *)&v26->m_obstacles.m_data + v4),
          v2->mpWorld->m_avoidancePairProps.m_pntr,
          &agentIn,
          (hkaiObstacleCollector *)&job);
        hkaiAvoidanceSolverUtils::calcSteeringVelocity(
          &result,
          deltaTime,
          &v2->mUp,
          &agentIn,
          (hkVector4f *)&steerForwardOut[4],
          (hkVector4f *)((char *)&steerVelocityOut + 8));
        *(hkVector4f *)((char *)&v26->m_steerOut.m_velocity + v4) = *(hkVector4f *)&steerForwardOut[4];
        *(hkVector4f *)((char *)&v26->m_steerOut.m_forwardAndResult + v4) = *(hkVector4f *)((char *)&steerVelocityOut + 8);
        *(int *)((char *)&v26->m_steerOut.m_forwardAndResult.m_quad.m128_i32[3] + v4) = result.m_enum | 0x3F000000;
        hkaiObstacleCollector::~hkaiObstacleCollector((hkaiObstacleCollector *)&job);
      }
      else
      {
        hkaiAvoidanceSolverUtils::calcUnsteeredVelocity(
          deltaTime,
          v22,
          (hkaiMovementProperties *)(v25[9].m_quad.m128_u64[1] + 16),
          v24,
          &v36,
          &v34);
        *(hkVector4f *)((char *)&v26->m_steerOut.m_forwardAndResult + v4) = (hkVector4f)v34.m_quad;
        *(int *)((char *)&v26->m_steerOut.m_forwardAndResult.m_quad.m128_i32[3] + v4) = 1056964608;
        *(hkVector4f *)((char *)&v26->m_steerOut.m_velocity + v4) = (hkVector4f)v36.m_quad;
      }
      ++v23;
      v4 += 64i64;
      --v5;
      v22 = &v2->mUp;
    }
    while ( v5 );
  }
}

// File Line: 400
// RVA: 0xECD20
void __usercall UFG::NavAvoidanceStrategyRVO::GatherResult(UFG::NavAvoidanceStrategyRVO *this@<rcx>, float deltaTime@<xmm1>, __int64 a3@<rdx>)
{
  __int64 v3; // r12
  int v4; // edi
  UFG::NavAvoidanceStrategyRVO *v5; // rbp
  __int64 v6; // r14
  __int64 v7; // rsi
  UFG::AgentInfo *v8; // rax
  float v9; // ebx
  hkaiLocalSteeringInput *v10; // rdx
  __m128 v11; // xmm1
  __m128 *v12; // r13
  hkaiCharacter *v13; // r15
  unsigned int v14; // ebx
  __m128 v15; // xmm1
  hkArrayBase<hkaiBehavior *> *v16; // rax
  __int64 v17; // rbx
  hkVector4f localVel; // [rsp+20h] [rbp-58h]
  hkVector4f worldVel; // [rsp+30h] [rbp-48h]

  v3 = this->mpCharacters->m_size;
  v4 = 0;
  v5 = this;
  if ( v3 > 0 )
  {
    v6 = 0i64;
    v7 = 0i64;
    do
    {
      v8 = v5->mAgentInfos.m_data;
      v9 = v8[v7].m_steerOut.m_forwardAndResult.m_quad.m128_f32[3];
      v10 = &v5->mLocalSteeringInputs.m_data[v6];
      v11 = v8[v7].m_steerOut.m_velocity.m_quad;
      localVel.m_quad = (__m128)v8[v7].m_steerOut.m_velocity;
      v12 = &v10->m_referenceFrame->m_transform.m_rotation.m_col0.m_quad;
      v13 = v10->m_character;
      v14 = LODWORD(v9) & 0xC0FFFFFF;
      if ( v12 )
      {
        hkaiReferenceFrame::transformLocalPosVelToWorldVel(
          v10->m_referenceFrame,
          &v10->m_currentPosition,
          &localVel,
          &worldVel);
        v15 = _mm_mul_ps(v12[5], v5->mUp.m_quad);
        v11 = _mm_shuffle_ps(
                worldVel.m_quad,
                _mm_unpackhi_ps(
                  worldVel.m_quad,
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                      _mm_shuffle_ps(v15, v15, 170)),
                    _mm_shuffle_ps(localVel.m_quad, localVel.m_quad, 255))),
                196);
      }
      v13->m_velocity.m_quad = v11;
      hkaiCharacter::setAvoidanceState(v13, (hkResult)v14);
      ++v6;
      ++v7;
      --v3;
    }
    while ( v3 );
  }
  v16 = v5->mpBehaviors;
  if ( v16->m_size > 0 )
  {
    v17 = 0i64;
    do
    {
      ((void (__cdecl *)(hkaiBehavior *, __int64))v16->m_data[v17]->vfptr[2].__vecDelDtor)(v16->m_data[v17], a3);
      v16 = v5->mpBehaviors;
      ++v4;
      ++v17;
    }
    while ( v4 < v16->m_size );
  }
}

// File Line: 456
// RVA: 0xE4C00
void __fastcall UFG::NavAvoidanceStrategyRVO::NavAvoidanceStrategyRVO(UFG::NavAvoidanceStrategyRVO *this, hkaiWorld *pWorld, hkJobQueue *pJobQueue, hkJobThreadPool *pThreadPool, hkaiAvoidanceProperties::AvoidanceSolverType solverType)
{
  hkJobThreadPool *v5; // rsi
  hkJobQueue *v6; // rdi
  hkaiWorld *v7; // rbx
  UFG::NavAvoidanceStrategyRVO *v8; // r15
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // er9
  int v13; // ecx
  signed __int64 v14; // rdx

  v5 = pThreadPool;
  v6 = pJobQueue;
  v7 = pWorld;
  v8 = this;
  UFG::NavAvoidanceStrategy::NavAvoidanceStrategy((UFG::NavAvoidanceStrategy *)&this->vfptr);
  v8->vfptr = (UFG::NavAvoidanceStrategyVtbl *)&UFG::NavAvoidanceStrategyRVO::`vftable';
  v8->mpWorld = v7;
  v9 = 0;
  v8->mAgentInfos.m_data = 0i64;
  v8->mAgentInfos.m_size = 0;
  v8->mAgentInfos.m_capacityAndFlags = 2147483648;
  v8->mLocalSteeringInputs.m_data = 0i64;
  v8->mLocalSteeringInputs.m_size = 0;
  v8->mLocalSteeringInputs.m_capacityAndFlags = 2147483648;
  v8->mCommands.m_data = 0i64;
  v8->mCommands.m_size = 0;
  v8->mCommands.m_capacityAndFlags = 2147483648;
  v8->mpJobQueue = v6;
  v8->mpThreadPool = v5;
  v8->mNumCharacters = 0;
  UFG::NavAvoidanceStrategyRVO::msAvoidanceSolverType = solverType;
  v8->mUp.m_quad = _xmm;
  v10 = v8->mCommands.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < 500 )
  {
    v11 = 2 * v10;
    v12 = 500;
    if ( v11 > 500 )
      v12 = v11;
    hkArrayUtil::_reserve(
      (hkResult *)&solverType,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v8->mCommands,
      v12,
      208);
  }
  v13 = v8->mCommands.m_size;
  v14 = (signed __int64)&v8->mCommands.m_data[v8->mCommands.m_size];
  solverType = 0;
  if ( 500 - v13 > 0 )
  {
    do
      solverType = ++v9;
    while ( v9 < 500 - v8->mCommands.m_size );
  }
  v8->mCommands.m_size = 500;
  v8->mpCharacters = (hkArrayBase<hkaiCharacter *> *)&UFG::NavModuleLocalRVO::ms_aCharacters;
  v8->mpBehaviors = (hkArrayBase<hkaiBehavior *> *)&UFG::NavModuleLocalRVO::ms_aBehaviors;
}

// File Line: 480
// RVA: 0xE6190
void __fastcall UFG::NavAvoidanceStrategyRVO::~NavAvoidanceStrategyRVO(UFG::NavAvoidanceStrategyRVO *this)
{
  UFG::NavAvoidanceStrategyRVO *v1; // rbx
  int v2; // er8
  int v3; // eax
  int v4; // edi
  UFG::AgentInfo *v5; // rsi
  int v6; // er8

  v1 = this;
  this->vfptr = (UFG::NavAvoidanceStrategyVtbl *)&UFG::NavAvoidanceStrategyRVO::`vftable';
  this->mCommands.m_size = 0;
  v2 = this->mCommands.m_capacityAndFlags;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->mCommands.m_data,
      208 * (v2 & 0x3FFFFFFF));
  v1->mCommands.m_data = 0i64;
  v1->mCommands.m_capacityAndFlags = 2147483648;
  v1->mLocalSteeringInputs.m_size = 0;
  v3 = v1->mLocalSteeringInputs.m_capacityAndFlags;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mLocalSteeringInputs.m_data,
      160 * (v3 & 0x3FFFFFFF));
  v1->mLocalSteeringInputs.m_data = 0i64;
  v1->mLocalSteeringInputs.m_capacityAndFlags = 2147483648;
  v4 = v1->mAgentInfos.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &v1->mAgentInfos.m_data[(signed __int64)v4];
    do
    {
      UFG::AgentInfo::~AgentInfo(v5);
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v1->mAgentInfos.m_size = 0;
  v6 = v1->mAgentInfos.m_capacityAndFlags;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mAgentInfos.m_data,
      v6 << 6);
  v1->mAgentInfos.m_data = 0i64;
  v1->mAgentInfos.m_capacityAndFlags = 2147483648;
  UFG::NavAvoidanceStrategy::~NavAvoidanceStrategy((UFG::NavAvoidanceStrategy *)&v1->vfptr);
}

// File Line: 484
// RVA: 0xF2720
void __fastcall UFG::NavAvoidanceStrategyRVO::Update(UFG::NavAvoidanceStrategyRVO *this, UFG::UpdatePhase phase, float deltaTime)
{
  UFG::NavAvoidanceStrategyRVO *v3; // rsi
  hkArrayBase<hkaiCharacter *> *v4; // r8
  __int64 v5; // r14
  bool v6; // cl
  __int32 v7; // edx
  __int64 v8; // rdx
  int v9; // ecx
  int v10; // edx
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // er9
  int v15; // edi
  UFG::AgentInfo *v16; // rbp
  int v17; // eax
  int v18; // eax
  int v19; // er9
  int v20; // edi
  UFG::AgentInfo *v21; // rbp
  int v22; // ebp
  signed __int64 v23; // rdi
  signed __int64 v24; // rcx
  bool v25; // zf
  UFG::AgentInfo *v26; // rcx
  signed __int64 v27; // rdx
  hkResult result; // [rsp+88h] [rbp+10h]
  UFG::AgentInfo *v29; // [rsp+98h] [rbp+20h]

  v3 = this;
  v4 = this->mpCharacters;
  v5 = v4->m_size;
  if ( phase == UPDATE_PHASE_PART1 )
    this->mNumCharacters = v5;
  if ( (_DWORD)v5 && !UFG::NavComponent::ms_bDisableNavigation )
  {
    v6 = UFG::HavokNavManager::ms_bEnableSteeringMT && this->mpJobQueue && this->mpThreadPool;
    if ( phase )
    {
      v7 = phase - 1;
      if ( v7 )
      {
        v8 = (unsigned int)(v7 - 1);
        if ( !(_DWORD)v8 )
        {
          if ( v6 )
            ((void (*)(void))v3->mpThreadPool->vfptr[2].__vecDelDtor)();
          UFG::NavAvoidanceStrategyRVO::GatherResult(v3, deltaTime, v8);
        }
      }
      else
      {
        if ( v6 )
          ((void (*)(void))v3->mpThreadPool->vfptr[2].__vecDelDtor)();
        UFG::NavAvoidanceStrategyRVO::DetectOverlaps(v3);
        UFG::NavAvoidanceStrategyRVO::StartAvoidanceTasks(v3, deltaTime);
      }
    }
    else
    {
      v9 = UFG::NavAvoidanceStrategyRVO::msStepCharactersMTMin;
      if ( v4->m_size / UFG::NavAvoidanceStrategyRVO::msStepCharactersMTRatio > UFG::NavAvoidanceStrategyRVO::msStepCharactersMTMin )
        v9 = v4->m_size / UFG::NavAvoidanceStrategyRVO::msStepCharactersMTRatio;
      v10 = UFG::NavAvoidanceStrategyRVO::msStepCharactersMTMax;
      if ( v9 < UFG::NavAvoidanceStrategyRVO::msStepCharactersMTMax )
        v10 = v9;
      v3->mpWorld->m_numCharactersPerAvoidanceJob = v10;
      v3->mpWorld->m_numBehaviorUpdatesPerJob = v10;
      v11 = 0;
      v3->mLocalSteeringInputs.m_size = 0;
      v12 = v3->mLocalSteeringInputs.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v12 < (signed int)v5 )
      {
        v13 = 2 * v12;
        v14 = v5;
        if ( (signed int)v5 < v13 )
          v14 = v13;
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v3->mLocalSteeringInputs,
          v14,
          160);
      }
      v3->mLocalSteeringInputs.m_size = v5;
      v15 = v3->mAgentInfos.m_size - 1;
      if ( v15 >= 0 )
      {
        v16 = &v3->mAgentInfos.m_data[(signed __int64)v15];
        do
        {
          UFG::AgentInfo::~AgentInfo(v16);
          --v16;
          --v15;
        }
        while ( v15 >= 0 );
      }
      v3->mAgentInfos.m_size = 0;
      v17 = v3->mAgentInfos.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v17 < (signed int)v5 )
      {
        v18 = 2 * v17;
        v19 = v5;
        if ( (signed int)v5 < v18 )
          v19 = v18;
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v3->mAgentInfos,
          v19,
          64);
      }
      v20 = v3->mAgentInfos.m_size - v5 - 1;
      if ( v20 >= 0 )
      {
        v21 = &v3->mAgentInfos.m_data[v5 + v20];
        do
        {
          UFG::AgentInfo::~AgentInfo(v21);
          --v21;
          --v20;
        }
        while ( v20 >= 0 );
      }
      v22 = v5 - v3->mAgentInfos.m_size;
      v23 = (signed __int64)&v3->mAgentInfos.m_data[(signed __int64)v3->mAgentInfos.m_size];
      result.m_enum = 0;
      if ( v22 > 0 )
      {
        do
        {
          v24 = (signed __int64)v11 << 6;
          v25 = v23 + v24 == 0;
          v26 = (UFG::AgentInfo *)(v23 + v24);
          v29 = v26;
          if ( !v25 )
            UFG::AgentInfo::AgentInfo(v26);
          result.m_enum = ++v11;
        }
        while ( v11 < v22 );
      }
      v3->mAgentInfos.m_size = v5;
      UFG::NavAvoidanceStrategyRVO::UpdateGenerators(v3);
      UFG::NavAvoidanceStrategyRVO::CalcDesiredVelocities(v3, deltaTime, v27);
    }
  }
}

// File Line: 561
// RVA: 0xF0E80
void __fastcall UFG::NavAvoidanceStrategyRVO::SetLocalModuleFor(UFG::NavAvoidanceStrategyRVO *this, UFG::NavComponent *pNavComponent)
{
  UFG::NavComponent::SetLocalModule<UFG::NavModuleLocalRVO>(pNavComponent);
}

