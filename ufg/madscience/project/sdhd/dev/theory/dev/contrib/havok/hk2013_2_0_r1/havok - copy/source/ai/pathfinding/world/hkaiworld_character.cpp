// File Line: 30
// RVA: 0xBE30A0
void __fastcall hkaiWorld::updateMeshFaceForCharacter(hkaiWorld *this, hkaiCharacter *character)
{
  unsigned int m_currentNavMeshFace; // ebx
  hkaiStreamingCollection *m_pntr; // rbx
  hkaiDynamicNavMeshQueryMediator *DynamicQueryMediator; // rax
  hkVector4f pointOut; // [rsp+40h] [rbp-68h] BYREF
  hkaiCharacterUtil::GetFaceForPathfindingSettings settings; // [rsp+50h] [rbp-58h] BYREF
  hkaiNavMeshQueryMediator::QueryInputBase input; // [rsp+70h] [rbp-38h] BYREF

  m_currentNavMeshFace = character->m_currentNavMeshFace;
  if ( hkaiWorld::getDynamicQueryMediator(this) )
  {
    input.m_filterInfo = 0;
    memset(&input.m_userData, 0, 32);
    hkaiCharacterUtil::setupQueryInput(character, &input);
    hkaiCharacterUtil::GetFaceForPathfindingSettings::GetFaceForPathfindingSettings(&settings);
    settings.m_previousFaceKey = m_currentNavMeshFace;
    m_pntr = this->m_streamingCollection.m_pntr;
    settings.m_resolveEdgePenetrations.m_bool = 0;
    DynamicQueryMediator = hkaiWorld::getDynamicQueryMediator(this);
    character->m_currentNavMeshFace = hkaiCharacterUtil::getFaceForPathfinding(
                                        m_pntr,
                                        &character->m_position,
                                        &character->m_up,
                                        DynamicQueryMediator,
                                        &input,
                                        &settings,
                                        &pointOut);
  }
  else
  {
    character->m_currentNavMeshFace = -1;
  }
}

// File Line: 62
// RVA: 0xBE1D60
void __fastcall hkaiWorld::stepCharacters(
        hkaiWorld *this,
        float timestep,
        hkArrayBase<hkaiCharacter *> *characters,
        hkArrayBase<hkaiBehavior *> *behaviors)
{
  hkaiWorld::stepCharactersMT(this, timestep, characters, behaviors, 0i64, 0i64);
}

// File Line: 78
// RVA: 0xBE34A0
void __fastcall `anonymous namespace::AgentInfo::AgentInfo(AgentInfo *this)
{
  unsigned int v2; // ebx
  hkaiCharacter **v3; // rax
  hkaiCharacter **v4; // rcx
  int v5; // ecx
  int v6; // eax
  hkaiObstacleGenerator **v7; // rax
  __int64 m_enum; // kr08_8
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  v2 = 0x80000000;
  this->m_characters.m_data = 0i64;
  this->m_characters.m_size = 0;
  this->m_characters.m_capacityAndFlags = 0x80000000;
  result.m_enum = 64;
  v3 = (hkaiCharacter **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &result);
  this->m_characters.m_size = 8;
  v4 = v3;
  LODWORD(v3) = result;
  result.m_enum = 64;
  this->m_characters.m_data = v4;
  v5 = 0x80000000;
  v6 = (int)v3 / 8;
  if ( v6 )
    v5 = v6;
  this->m_characters.m_capacityAndFlags = v5;
  this->m_obstacles.m_data = 0i64;
  this->m_obstacles.m_size = 0;
  this->m_obstacles.m_capacityAndFlags = 0x80000000;
  v7 = (hkaiObstacleGenerator **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                   &hkContainerHeapAllocator::s_alloc,
                                   &result);
  this->m_obstacles.m_size = 8;
  m_enum = result.m_enum;
  this->m_obstacles.m_data = v7;
  if ( ((BYTE4(m_enum) & 7) + (int)m_enum) >> 3 )
    v2 = ((BYTE4(m_enum) & 7) + (int)m_enum) >> 3;
  this->m_obstacles.m_capacityAndFlags = v2;
  this->m_characters.m_size = 0;
  this->m_obstacles.m_size = 0;
}

// File Line: 93
// RVA: 0xBE3170
void __fastcall hkaiWorld::calcDesiredVelocities(
        hkaiWorld *this,
        float timestep,
        int numCharacters,
        hkArrayBase<hkaiBehavior *> *behaviors,
        hkJobQueue *jobQueue,
        hkJobThreadPool *threadPool,
        hkArray<hkaiLocalSteeringInput,hkContainerTempAllocator> *localSteeringInputs)
{
  hkArray<hkaiLocalSteeringInput,hkContainerTempAllocator> *v7; // r12
  int v8; // ebp
  int v10; // eax
  unsigned int v11; // r15d
  int v12; // eax
  int v13; // r9d
  hkJobQueue *v14; // rdi
  int m_numBehaviorUpdatesPerJob; // ecx
  hkaiBehavior **m_data; // r15
  int m_size; // eax
  int v18; // r13d
  int v19; // eax
  __int64 v20; // r12
  int v21; // edx
  __int32 v22; // eax
  int v23; // ebx
  int v24; // esi
  hkaiBehavior **v25; // rdi
  __int64 v26; // r14
  int v27; // eax
  hkJobThreadPool *v28; // rbx
  hkaiLocalSteeringInput *v29; // r13
  __int64 v30; // r14
  __int64 v31; // r12
  int v32; // ebx
  hkaiBehavior *v33; // rdi
  __int64 v34; // rdx
  int v35; // esi
  hkaiCharacter *v36; // rax
  int v37; // eax
  __int64 v38; // rbx
  hkaiReferenceFrame *m_referenceFrame; // rcx
  int v40; // [rsp+30h] [rbp-98h]
  int v41; // [rsp+34h] [rbp-94h]
  hkJob job; // [rsp+40h] [rbp-88h] BYREF
  __int128 v43; // [rsp+50h] [rbp-78h]
  hkaiBehavior **v44; // [rsp+60h] [rbp-68h]
  int v45; // [rsp+68h] [rbp-60h]
  __int64 v46; // [rsp+70h] [rbp-58h]
  int v47; // [rsp+78h] [rbp-50h]
  float v48; // [rsp+7Ch] [rbp-4Ch]
  hkResult v49; // [rsp+E0h] [rbp+18h] BYREF
  hkArrayBase<hkaiBehavior *> *v50; // [rsp+E8h] [rbp+20h]

  v50 = behaviors;
  v7 = localSteeringInputs;
  v8 = 0;
  v10 = localSteeringInputs->m_capacityAndFlags & 0x3FFFFFFF;
  v11 = numCharacters;
  localSteeringInputs->m_size = 0;
  if ( v10 < numCharacters )
  {
    v12 = 2 * v10;
    v13 = numCharacters;
    if ( numCharacters < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&v49, &hkContainerTempAllocator::s_alloc, v7, v13, 160);
    behaviors = v50;
  }
  v14 = jobQueue;
  v7->m_size = v11;
  if ( v14 && threadPool )
  {
    m_numBehaviorUpdatesPerJob = this->m_numBehaviorUpdatesPerJob;
    m_data = behaviors->m_data;
    v48 = timestep;
    job.m_size = 64;
    *(_WORD *)&job.m_jobSubType = 3073;
    v43 = 0i64;
    job.m_threadAffinity = -1;
    v45 = -1;
    v47 = -1;
    m_size = behaviors->m_size;
    v44 = 0i64;
    v46 = 0i64;
    job.m_jobSpuType.m_storage = 2;
    v40 = m_numBehaviorUpdatesPerJob;
    v18 = 0;
    v19 = (m_numBehaviorUpdatesPerJob + m_size - 1) / m_numBehaviorUpdatesPerJob;
    v41 = v19;
    if ( v19 > 0 )
    {
      v20 = (__int64)v7->m_data;
      v21 = v19 - 1;
      v22 = 0;
      v49.m_enum = HK_SUCCESS;
      do
      {
        if ( v18 == v21 )
          v23 = behaviors->m_size - v22;
        else
          v23 = m_numBehaviorUpdatesPerJob;
        v44 = m_data;
        v45 = v23;
        v24 = 0;
        if ( v23 > 0 )
        {
          v25 = m_data;
          v26 = (unsigned int)v23;
          do
          {
            v27 = ((__int64 (__fastcall *)(hkaiBehavior *))(*v25)->hkReferencedObject::hkBaseObject::vfptr[6].__vecDelDtor)(*v25);
            ++v25;
            v24 += v27;
            --v26;
          }
          while ( v26 );
          v14 = jobQueue;
        }
        v46 = v20;
        m_data += v23;
        v47 = v24;
        v20 += 160i64 * v24;
        hkJobQueue::addJob(v14, &job, JOB_HIGH_PRIORITY);
        m_numBehaviorUpdatesPerJob = v40;
        behaviors = v50;
        ++v18;
        v22 = v40 + v49.m_enum;
        v21 = v41 - 1;
        v49.m_enum += v40;
      }
      while ( v18 < v41 );
      v7 = localSteeringInputs;
      if ( v41 > 0 )
      {
        v28 = threadPool;
        ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64, hkArrayBase<hkaiBehavior *> *))threadPool->vfptr[5].__first_virtual_table_function__)(
          threadPool,
          v14,
          12i64,
          v50);
        hkJobQueue::processAllJobs(v14, 1);
        ((void (__fastcall *)(hkJobThreadPool *))v28->vfptr[2].__vecDelDtor)(v28);
      }
    }
  }
  else
  {
    v29 = v7->m_data;
    v30 = 0i64;
    if ( behaviors->m_size > 0i64 )
    {
      v31 = behaviors->m_size;
      do
      {
        v32 = 0;
        v33 = behaviors->m_data[v30];
        v35 = ((__int64 (__fastcall *)(hkaiBehavior *))v33->hkReferencedObject::hkBaseObject::vfptr[6].__vecDelDtor)(v33);
        if ( v35 > 0 )
        {
          do
          {
            v36 = (hkaiCharacter *)((__int64 (__fastcall *)(hkaiBehavior *, _QWORD))v33->hkReferencedObject::hkBaseObject::vfptr[6].__first_virtual_table_function__)(
                                     v33,
                                     (unsigned int)v32);
            if ( v36->m_state.m_storage != 7 )
              hkaiWorld::updateMeshFaceForCharacter(v33->m_world.m_pntr, v36);
            ++v32;
          }
          while ( v32 < v35 );
        }
        v37 = ((__int64 (__fastcall *)(hkaiBehavior *, __int64, hkaiLocalSteeringInput *, _QWORD))v33->hkReferencedObject::hkBaseObject::vfptr[1].__first_virtual_table_function__)(
                v33,
                v34,
                v29,
                v11);
        behaviors = v50;
        ++v30;
        v11 -= v37;
        v29 += v37;
      }
      while ( v30 < v31 );
      v7 = localSteeringInputs;
    }
  }
  if ( v7->m_size > 0 )
  {
    v38 = 0i64;
    do
    {
      if ( v7->m_data[v38].m_enableLocalSteering.m_bool )
      {
        m_referenceFrame = v7->m_data[v38].m_referenceFrame;
        if ( m_referenceFrame )
          hkaiReferenceFrame::validate(m_referenceFrame);
      }
      ++v8;
      ++v38;
    }
    while ( v8 < v7->m_size );
  }
}

// File Line: 175
// RVA: 0xBE1D80
void __fastcall hkaiWorld::stepCharactersMT(
        hkaiWorld *this,
        float timestep,
        hkJobQueue *characters,
        hkArrayBase<hkaiBehavior *> *behaviors,
        hkJobQueue *jobQueue,
        hkJobThreadPool *threadPool)
{
  __int64 v6; // rsi
  hkaiWorld *v7; // r12
  hkArrayBase<hkaiCharacter *> *v10; // rsi
  _QWORD *Value; // rax
  unsigned __int64 v12; // rcx
  _QWORD *v13; // r10
  const char *v14; // rdx
  unsigned __int64 v15; // rax
  hkaiWorld *m_size; // r14
  int v17; // ebx
  __int64 v18; // rdi
  hkaiWorld *v19; // rax
  int v20; // ecx
  hkaiWorld *m_world; // rdi
  AgentInfo *v22; // rbx
  __int64 v23; // rsi
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  _QWORD *v27; // rcx
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  int v32; // esi
  __int64 v33; // rbx
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  _QWORD *v37; // rcx
  _QWORD *v38; // r8
  unsigned __int64 v39; // rcx
  unsigned __int64 v40; // rax
  __int64 v41; // r13
  int v42; // r15d
  int v43; // eax
  hkResultEnum v44; // ecx
  int v45; // ebx
  hk1AxisSweep::AabbInt *v46; // rdi
  __int64 v47; // rsi
  __m128 *m_character; // rcx
  __m128 *v49; // rax
  __m128 v50; // xmm0
  __m128 v51; // xmm2
  __int64 v52; // rsi
  __int64 v53; // r14
  hk1AxisSweep::AabbInt *v54; // r13
  hkaiObstacleGenerator *m_pntr; // rcx
  hk1AxisSweep::AabbInt *v56; // rdx
  __int64 v57; // rax
  int v58; // ebx
  __int64 v59; // rax
  _QWORD *v60; // r8
  _QWORD *v61; // rcx
  unsigned __int64 v62; // rax
  _QWORD *v63; // rcx
  _QWORD *v64; // r8
  _QWORD *v65; // rcx
  unsigned __int64 v66; // rax
  _QWORD *v67; // rcx
  hk1AxisSweep::AabbInt *v68; // rcx
  int v69; // r8d
  unsigned __int64 v70; // rax
  unsigned int *v71; // r15
  hk1AxisSweep::AabbInt *v72; // rdx
  __int64 v73; // r8
  __int64 v74; // r9
  __int64 v75; // rbx
  __int64 v76; // rsi
  hkaiCharacter *v77; // r13
  hkaiCharacter *v78; // r14
  hkaiLocalSteeringFilter *v79; // rcx
  _DWORD *v80; // rbx
  hkaiLocalSteeringFilter *v81; // rcx
  _DWORD *v82; // rbx
  hkaiCharacter *v83; // rdx
  __int64 v84; // rcx
  hkaiObstacleGenerator *v85; // rsi
  hkaiLocalSteeringFilter *v86; // rcx
  _DWORD *v87; // rbx
  _QWORD *v88; // r8
  _QWORD *v89; // rcx
  unsigned __int64 v90; // rax
  _QWORD *v91; // rcx
  __int64 v92; // rsi
  hkaiWorld *v93; // r14
  __int64 v94; // rbx
  unsigned int *p_m_cutter; // rsi
  _QWORD *v96; // r8
  _QWORD *v97; // rcx
  unsigned __int64 v98; // rax
  _QWORD *v99; // rcx
  hkaiStreamingCollection *v100; // rax
  hkaiAvoidancePairProperties *v101; // rcx
  __int64 m_data_low; // r14
  int v103; // esi
  __int64 v104; // rax
  __int64 v105; // r14
  hkRefPtr<hkaiNavMeshCutter> *v106; // rbx
  __int64 v107; // r15
  hkaiLocalSteeringInput *v108; // r9
  hkaiCharacter *v109; // rdx
  __int64 v110; // rcx
  unsigned __int64 v111; // rcx
  _QWORD *v112; // r8
  _QWORD *v113; // rcx
  unsigned __int64 v114; // rax
  _QWORD *v115; // rcx
  __int64 m_numCharactersPerAvoidanceJob; // r15
  int v117; // r8d
  __int64 v118; // r14
  int v119; // ebx
  int v120; // eax
  int v121; // r13d
  int v122; // edi
  int v123; // esi
  _QWORD *v124; // r9
  unsigned __int64 v125; // r8
  unsigned __int64 v126; // rax
  _QWORD *v127; // r8
  _QWORD *v128; // rcx
  unsigned __int64 v129; // rax
  _QWORD *v130; // rcx
  int v131; // r13d
  __int64 v132; // r15
  hkVector4f *p_m_up; // rsi
  hkaiLocalSteeringInput *v134; // r14
  bool v135; // zf
  hkVector4f *v136; // r8
  unsigned int v137; // ebx
  hkResultEnum m_enum; // eax
  _QWORD *v139; // r8
  _QWORD *v140; // rcx
  unsigned __int64 v141; // rax
  _QWORD *v142; // rcx
  __int64 v143; // r15
  __m128 *v144; // rbx
  hkaiLocalSteeringInput *v145; // r14
  __m128 v146; // xmm6
  hkaiReferenceFrame *m_referenceFrame; // r13
  hkaiCharacter *v148; // rsi
  __m128 v149; // xmm6
  __m128 v150; // xmm1
  __m128 v151; // xmm1
  __m128 v152; // xmm2
  _QWORD *v153; // r8
  _QWORD *v154; // rcx
  unsigned __int64 v155; // rax
  _QWORD *v156; // rcx
  int v157; // esi
  __int64 v158; // rbx
  unsigned __int64 v159; // rdx
  _QWORD *v160; // r8
  _QWORD *v161; // rcx
  unsigned __int64 v162; // rax
  _QWORD *v163; // rcx
  int v164; // esi
  __int64 v165; // rbx
  _QWORD *v166; // r8
  _QWORD *v167; // rcx
  unsigned __int64 v168; // rax
  _QWORD *v169; // rcx
  int m_data; // ebx
  int i; // esi
  __int64 v172; // rbx
  int v173; // r8d
  int v174; // r8d
  __int64 v175; // rsi
  int *v176; // rbx
  int v177; // r8d
  int v178; // r8d
  _QWORD *v179; // rax
  _QWORD *v180; // rcx
  _QWORD *v181; // r8
  unsigned __int64 v182; // rax
  _QWORD *v183; // rcx
  hkaiWorld *v184; // [rsp+50h] [rbp-A0h]
  int v185; // [rsp+58h] [rbp-98h]
  int v186; // [rsp+58h] [rbp-98h]
  hkResult result; // [rsp+5Ch] [rbp-94h] BYREF
  hkVector4f array; // [rsp+60h] [rbp-90h] BYREF
  hkArray<hkaiLocalSteeringInput,hkContainerTempAllocator> localSteeringInputs; // [rsp+70h] [rbp-80h] BYREF
  hkaiWorld::CharacterStepCallbackContext v190; // [rsp+80h] [rbp-70h] BYREF
  hk1AxisSweep::AabbInt *aabbs[2]; // [rsp+A0h] [rbp-50h] BYREF
  int v192; // [rsp+B0h] [rbp-40h]
  int v193; // [rsp+B4h] [rbp-3Ch]
  hkaiObstacleCollector job; // [rsp+C0h] [rbp-30h] BYREF
  hkaiWorld::CharacterStepCallbackContext localVel; // [rsp+120h] [rbp+30h] BYREF
  hkaiAvoidanceSolver::SteeringAgent agentIn; // [rsp+140h] [rbp+50h] BYREF
  hkaiWorld *vars0; // [rsp+2C0h] [rbp+1D0h]
  __int64 v199; // [rsp+2D8h] [rbp+1E8h]

  v199 = v6;
  v7 = this;
  v10 = (hkArrayBase<hkaiCharacter *> *)characters;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = Value[1];
  v13 = Value;
  v14 = "Stsetup";
  if ( v12 < Value[3] )
  {
    *(_QWORD *)(v12 + 16) = "Stsetup";
    *(_QWORD *)v12 = "LtstepCharacters";
    v15 = __rdtsc();
    v14 = (const char *)((unsigned __int64)HIDWORD(v15) << 32);
    *(_DWORD *)(v12 + 8) = v15;
    v13[1] = v12 + 24;
  }
  m_size = (hkaiWorld *)v10->m_size;
  LODWORD(localSteeringInputs.m_data) = (_DWORD)m_size;
  if ( !(_DWORD)m_size )
    goto LABEL_167;
  v17 = 0;
  if ( v7->m_obstacleGenerators.m_size > 0 )
  {
    v18 = 0i64;
    do
    {
      ((void (__fastcall *)(hkaiObstacleGenerator *, const char *))v7->m_obstacleGenerators.m_data[v18].m_pntr->vfptr[1].__first_virtual_table_function__)(
        v7->m_obstacleGenerators.m_data[v18].m_pntr,
        v14);
      ++v17;
      ++v18;
    }
    while ( v17 < v7->m_obstacleGenerators.m_size );
  }
  localSteeringInputs.m_size = (_DWORD)m_size << 6;
  v19 = (hkaiWorld *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                       &hkContainerTempAllocator::s_alloc,
                       &localSteeringInputs.m_size);
  v20 = 0x80000000;
  m_world = v19;
  localVel.m_world = v19;
  if ( localSteeringInputs.m_size / 64 )
    v20 = localSteeringInputs.m_size / 64;
  v192 = v20;
  if ( (int)m_size > 0 )
  {
    v22 = (AgentInfo *)v19;
    v23 = (unsigned int)m_size;
    do
    {
      if ( v22 )
        `anonymous namespace::AgentInfo::AgentInfo(v22);
      ++v22;
      --v23;
    }
    while ( v23 );
    v10 = (hkArrayBase<hkaiCharacter *> *)this;
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "StcalcDesiredVel";
    v26 = __rdtsc();
    v27 = v25 + 2;
    *((_DWORD *)v27 - 2) = v26;
    v24[1] = v27;
  }
  localSteeringInputs.m_data = 0i64;
  localSteeringInputs.m_size = 0;
  localSteeringInputs.m_capacityAndFlags = 0x80000000;
  hkaiWorld::calcDesiredVelocities(
    v7,
    timestep,
    (int)m_size,
    behaviors,
    characters,
    (hkJobThreadPool *)behaviors,
    &localSteeringInputs);
  if ( v7->m_listeners.m_size )
  {
    v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v29 = (_QWORD *)v28[1];
    if ( (unsigned __int64)v29 < v28[3] )
    {
      *v29 = "StpreStepCallbacks";
      v30 = __rdtsc();
      v31 = v29 + 2;
      *((_DWORD *)v31 - 2) = v30;
      v28[1] = v31;
    }
    hkaiWorld::CharacterStepCallbackContext::CharacterStepCallbackContext(
      &v190,
      CALLBACK_PRECHARACTER_STEP,
      v7,
      timestep,
      v10,
      &localSteeringInputs);
    v32 = 0;
    if ( v7->m_listeners.m_size > 0 )
    {
      v33 = 0i64;
      do
      {
        (*(void (__fastcall **)(hkaiWorld::Listener *, hkaiWorld::CharacterStepCallbackContext *))v7->m_listeners.m_data[v33]->vfptr->gap8)(
          v7->m_listeners.m_data[v33],
          &v190);
        ++v32;
        ++v33;
      }
      while ( v32 < v7->m_listeners.m_size );
    }
  }
  v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v35 = (_QWORD *)v34[1];
  if ( (unsigned __int64)v35 < v34[3] )
  {
    *v35 = "Stbroadphase";
    v36 = __rdtsc();
    v37 = v35 + 2;
    *((_DWORD *)v37 - 2) = v36;
    v34[1] = v37;
  }
  v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v39 = v38[1];
  if ( v39 < v38[3] )
  {
    *(_QWORD *)v39 = "Ltbroadphase";
    *(_QWORD *)(v39 + 16) = "Stsetup";
    v40 = __rdtsc();
    *(_DWORD *)(v39 + 8) = v40;
    v38[1] = v39 + 24;
  }
  v41 = v7->m_obstacleGenerators.m_size;
  v42 = (_DWORD)m_size + v41;
  v43 = (_DWORD)m_size + v41 + 4;
  if ( (_DWORD)m_size + (_DWORD)v41 == -4 )
  {
    aabbs[0] = 0i64;
  }
  else
  {
    HIDWORD(localSteeringInputs.m_data) = 32 * v43;
    aabbs[0] = (hk1AxisSweep::AabbInt *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, char *, _QWORD *))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                                          &hkContainerTempAllocator::s_alloc,
                                          (char *)&localSteeringInputs.m_data + 4,
                                          v38);
    v43 = SHIDWORD(localSteeringInputs.m_data) / 32;
  }
  v44 = 0x80000000;
  v184 = m_size;
  if ( v43 )
    v44 = v43;
  v45 = 0;
  result.m_enum = v44;
  if ( (int)m_size > 0 )
  {
    v46 = aabbs[0];
    v47 = 0i64;
    do
    {
      m_character = (__m128 *)localSteeringInputs.m_data[v47].m_character;
      v49 = (__m128 *)m_character[9].m128_u64[1];
      v50 = _mm_max_ps(
              _mm_shuffle_ps((__m128)m_character[6].m128_u32[3], (__m128)m_character[6].m128_u32[3], 0),
              m_character[5]);
      v51 = _mm_mul_ps(v49[5], v50);
      *(__m128 *)&v190.m_world = _mm_add_ps(_mm_mul_ps(v49[4], v50), m_character[2]);
      *(__m128 *)&v190.m_characters = _mm_add_ps(v51, m_character[2]);
      hk1AxisSweep::AabbInt::set(&v46[v45], (hkAabb *)&v190, v45);
      ++v45;
      ++v47;
      m_size = (hkaiWorld *)((char *)m_size - 1);
    }
    while ( m_size );
    m_world = localVel.m_world;
  }
  v52 = 0i64;
  v53 = v41;
  if ( (int)v41 > 0 )
  {
    v54 = aabbs[0];
    do
    {
      m_pntr = v7->m_obstacleGenerators.m_data[v52].m_pntr;
      ((void (__fastcall *)(hkaiObstacleGenerator *, hkaiWorld::CharacterStepCallbackContext *))m_pntr->vfptr[2].__first_virtual_table_function__)(
        m_pntr,
        &v190);
      hk1AxisSweep::AabbInt::set(&v54[v45], (hkAabb *)&v190, v45);
      ++v52;
      ++v45;
    }
    while ( v52 < v53 );
  }
  v56 = aabbs[0];
  v57 = v45;
  v58 = v45 + 1;
  aabbs[0][v57].m_min[0] = -1;
  v59 = v58++;
  v56[v59].m_min[0] = -1;
  v56[v58].m_min[0] = -1;
  v56[v58 + 1].m_min[0] = -1;
  v60 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v61 = (_QWORD *)v60[1];
  if ( (unsigned __int64)v61 < v60[3] )
  {
    *v61 = "StsortAabbs";
    v62 = __rdtsc();
    v63 = v61 + 2;
    *((_DWORD *)v63 - 2) = v62;
    v60[1] = v63;
  }
  hk1AxisSweep::sortAabbs(aabbs[0], v42);
  v64 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v65 = (_QWORD *)v64[1];
  if ( (unsigned __int64)v65 < v64[3] )
  {
    *v65 = "Stscan";
    v66 = __rdtsc();
    v67 = v65 + 2;
    *((_DWORD *)v67 - 2) = v66;
    v64[1] = v67;
  }
  v68 = aabbs[0];
  v69 = 0;
  v193 = v42 - 1;
  v70 = 1i64;
  v185 = 0;
  v190.m_world = (hkaiWorld *)1;
  v71 = &aabbs[0]->m_min[1];
  do
  {
    array.m_quad.m128_u64[0] = v70;
    v72 = (hk1AxisSweep::AabbInt *)(v71 + 7);
    if ( v71[7] > v71[3] )
      goto LABEL_68;
    do
    {
      if ( (((v72->m_max[1] - *v71) | (v72->m_max[2] - v71[1]) | (v71[4] - v72->m_min[1]) | (v71[5] - v72->m_min[2])) & 0x80000000) != 0 )
        goto LABEL_66;
      v73 = (int)v71[2];
      v74 = *(int *)v72->m_expansionMin;
      if ( (int)v73 >= SLODWORD(localSteeringInputs.m_data) )
      {
        if ( (int)v74 >= SLODWORD(localSteeringInputs.m_data) )
          goto LABEL_66;
        v75 = *(int *)v72->m_expansionMin;
        v83 = localSteeringInputs.m_data[v74].m_character;
        v84 = (int)v71[2];
      }
      else
      {
        v75 = (int)v71[2];
        if ( (int)v74 < SLODWORD(localSteeringInputs.m_data) )
        {
          v76 = *(int *)v72->m_expansionMin;
          v77 = localSteeringInputs.m_data[v73].m_character;
          v78 = localSteeringInputs.m_data[v74].m_character;
          v79 = v77->m_steeringFilter.m_pntr;
          if ( !v79
            || ((unsigned int (__fastcall *)(hkaiLocalSteeringFilter *, hkaiCharacter *, hkaiCharacter *))v79->vfptr[1].__first_virtual_table_function__)(
                 v79,
                 v77,
                 localSteeringInputs.m_data[v74].m_character) )
          {
            v80 = (_DWORD *)((char *)m_world + 64 * v75);
            if ( v80[10] == (v80[11] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v80 + 8, 8);
            *(_QWORD *)(*((_QWORD *)v80 + 4) + 8i64 * (int)v80[10]++) = v78;
          }
          v81 = v78->m_steeringFilter.m_pntr;
          if ( !v81
            || ((unsigned int (__fastcall *)(hkaiLocalSteeringFilter *, hkaiCharacter *, hkaiCharacter *))v81->vfptr[1].__first_virtual_table_function__)(
                 v81,
                 v78,
                 v77) )
          {
            v82 = (_DWORD *)((char *)m_world + 64 * v76);
            if ( v82[10] == (v82[11] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v82 + 8, 8);
            *(_QWORD *)(*((_QWORD *)v82 + 4) + 8i64 * (int)v82[10]++) = v77;
          }
          goto LABEL_66;
        }
        v83 = localSteeringInputs.m_data[v73].m_character;
        v84 = v74;
      }
      v85 = v7->m_obstacleGenerators.m_data[v84 - (_QWORD)v184].m_pntr;
      v86 = v83->m_steeringFilter.m_pntr;
      if ( !v86
        || ((unsigned int (__fastcall *)(hkaiLocalSteeringFilter *, hkaiCharacter *, hkaiObstacleGenerator *))v86->vfptr[2].__vecDelDtor)(
             v86,
             v83,
             v85) )
      {
        v87 = (_DWORD *)((char *)m_world + 64 * v75);
        if ( v87[14] == (v87[15] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v87 + 12, 8);
        *(_QWORD *)(*((_QWORD *)v87 + 6) + 8i64 * (int)v87[14]++) = v85;
      }
LABEL_66:
      v68 = aabbs[0];
      v72 = &aabbs[0][++array.m_quad.m128_u64[0]];
    }
    while ( v72->m_min[0] <= v71[3] );
    v69 = v185;
LABEL_68:
    ++v69;
    v71 += 8;
    v70 = (unsigned __int64)&v190.m_world->vfptr + 1;
    v185 = v69;
    ++v190.m_world;
  }
  while ( v69 < v193 );
  if ( result.m_enum >= HK_SUCCESS )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v68, 32 * result.m_enum);
  v88 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v89 = (_QWORD *)v88[1];
  if ( (unsigned __int64)v89 < v88[3] )
  {
    *v89 = "lt";
    v90 = __rdtsc();
    v91 = v89 + 2;
    *((_DWORD *)v91 - 2) = v90;
    v88[1] = v91;
  }
  v92 = (__int64)v184;
  if ( (__int64)v184 > 0 )
  {
    v93 = v184;
    v94 = 0i64;
    p_m_cutter = (unsigned int *)&m_world->m_cutter;
    do
    {
      if ( localSteeringInputs.m_data[v94].m_enableLocalSteering.m_bool )
        hkaiAdaptiveRanger::updateRange(
          &localSteeringInputs.m_data[v94].m_character->m_adaptiveRanger,
          localSteeringInputs.m_data[v94].m_character->m_avoidanceProperties.m_pntr->m_maxNeighbors,
          *p_m_cutter);
      ++v94;
      p_m_cutter += 16;
      v93 = (hkaiWorld *)((char *)v93 - 1);
    }
    while ( v93 );
    v92 = (__int64)v184;
  }
  if ( characters && behaviors )
  {
    v96 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v97 = (_QWORD *)v96[1];
    if ( (unsigned __int64)v97 < v96[3] )
    {
      *v97 = "StsetupJobs";
      v98 = __rdtsc();
      v99 = v97 + 2;
      *((_DWORD *)v99 - 2) = v98;
      v96[1] = v99;
    }
    memset(&job.m_neighborAgents.m_size, 0, 20);
    HIDWORD(job.m_spheres.m_data) = -65456;
    *(float *)&job.m_neighborAgents.m_data = timestep;
    job.m_position.m_quad.m128_i32[2] = -1;
    v100 = v7->m_streamingCollection.m_pntr;
    job.m_boundaries = 0i64;
    HIDWORD(job.m_neighborAgents.m_data) = LODWORD(v7->m_erosionRadius);
    LOWORD(job.m_spheres.m_data) = 3072;
    BYTE2(job.m_spheres.m_data) = 1;
    job.m_position.m_quad.m128_u64[0] = 0i64;
    *(_QWORD *)&job.m_neighborAgents.m_size = v100->m_instances.m_data;
    v101 = v7->m_avoidancePairProps.m_pntr;
    v186 = 0;
    if ( v101 )
    {
      job.m_up.m_quad.m128_u64[0] = (unsigned __int64)v101->m_avoidancePairDataMap.m_data;
      job.m_up.m_quad.m128_i32[2] = v101->m_avoidancePairDataMap.m_size;
    }
    m_data_low = SLODWORD(localSteeringInputs.m_data);
    array.m_quad.m128_u64[0] = 0i64;
    array.m_quad.m128_u64[1] = 0x8000000000000000ui64;
    if ( SLODWORD(localSteeringInputs.m_data) > 0 )
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, (int)localSteeringInputs.m_data, 208);
    v103 = 0;
    v104 = m_data_low;
    if ( (int)m_data_low > 0 )
    {
      v105 = 0i64;
      v106 = &m_world->m_cutter;
      v107 = v104;
      do
      {
        v108 = &localSteeringInputs.m_data[v105];
        v109 = localSteeringInputs.m_data[v105].m_character;
        if ( localSteeringInputs.m_data[v105].m_enableLocalSteering.m_bool )
        {
          if ( v108->m_applyAvoidanceSteering.m_bool )
          {
            v110 = array.m_quad.m128_i32[2]++;
            v186 = 1;
            v111 = array.m_quad.m128_u64[0] + 208 * v110;
            *(hkVector4f *)v111 = v108->m_currentPosition;
            *(hkVector4f *)(v111 + 16) = v108->m_currentForward;
            *(hkVector4f *)(v111 + 32) = v108->m_currentUp;
            *(hkVector4f *)(v111 + 48) = v108->m_currentVelocity;
            *(hkVector4f *)(v111 + 64) = v108->m_desiredVelocity;
            *(hkVector4f *)(v111 + 80) = v108->m_desiredFutureDir;
            *(hkVector4f *)(v111 + 96) = v108->m_localGoalPlane;
            *(float *)(v111 + 112) = v108->m_distToLocalGoal;
            *(float *)(v111 + 116) = v108->m_timeToLocalGoal;
            *(_QWORD *)(v111 + 120) = v108->m_character;
            *(_QWORD *)(v111 + 128) = v108->m_referenceFrame;
            *(_QWORD *)(v111 + 136) = v108->m_avoidanceProperties;
            *(_BYTE *)(v111 + 144) = v108->m_isLocalGoalLast.m_bool;
            *(_BYTE *)(v111 + 145) = v108->m_applyKinematicConstraints.m_bool;
            *(_BYTE *)(v111 + 146) = v108->m_applyAvoidanceSteering.m_bool;
            *(_BYTE *)(v111 + 147) = v108->m_enableLocalSteering.m_bool;
            *(hkRefPtr<hkaiNavMeshCutter> *)(v111 + 160) = v106[-1];
            *(_DWORD *)(v111 + 176) = v106->m_pntr;
            *(hkRefPtr<hkaiNavMeshCutter> *)(v111 + 168) = v106[1];
            *(_DWORD *)(v111 + 180) = v106[2].m_pntr;
            *(_DWORD *)(v111 + 184) = v109->m_currentNavMeshFace;
            *(_QWORD *)(v111 + 192) = (char *)m_world + 64 * (__int64)v103;
          }
          else
          {
            hkaiAvoidanceSolverUtils::calcUnsteeredVelocity(
              timestep,
              &v109->m_up,
              &v109->m_avoidanceProperties.m_pntr->m_movementProperties,
              v108,
              &m_world->m_up + 4 * (__int64)v103,
              (hkVector4f *)&v190);
            *(_OWORD *)&v106[-5].m_pntr = *(_OWORD *)&v190.m_world;
            HIDWORD(v106[-4].m_pntr) = 1056964608;
          }
        }
        ++v103;
        ++v105;
        v106 += 8;
        --v107;
      }
      while ( v107 );
    }
    v112 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v113 = (_QWORD *)v112[1];
    if ( (unsigned __int64)v113 < v112[3] )
    {
      *v113 = "StqueueJobs";
      v114 = __rdtsc();
      v115 = v113 + 2;
      *((_DWORD *)v115 - 2) = v114;
      v112[1] = v115;
    }
    m_numCharactersPerAvoidanceJob = v7->m_numCharactersPerAvoidanceJob;
    v117 = array.m_quad.m128_i32[2];
    v118 = 0i64;
    v119 = 0;
    v120 = ((int)m_numCharactersPerAvoidanceJob + array.m_quad.m128_i32[2] - 1) / (int)m_numCharactersPerAvoidanceJob;
    v121 = v120;
    if ( v120 > 0 )
    {
      v122 = v120 - 1;
      v123 = 0;
      while ( 1 )
      {
        job.m_position.m_quad.m128_u64[0] = v118 + array.m_quad.m128_u64[0];
        job.m_position.m_quad.m128_i32[2] = v119 == v122 ? v117 - v123 : m_numCharactersPerAvoidanceJob;
        hkJobQueue::addJob(characters, (hkJob *)&job, JOB_HIGH_PRIORITY);
        ++v119;
        v123 += m_numCharactersPerAvoidanceJob;
        v118 += 208 * m_numCharactersPerAvoidanceJob;
        if ( v119 >= v121 )
          break;
        v117 = array.m_quad.m128_i32[2];
      }
      m_world = localVel.m_world;
      v7 = vars0;
    }
    v124 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v125 = v124[1];
    if ( v125 < v124[3] )
    {
      *(_QWORD *)v125 = "StprocessJobs";
      v126 = __rdtsc();
      *(_DWORD *)(v125 + 8) = v126;
      v124[1] = v125 + 16;
    }
    if ( v186 )
    {
      (*((void (__fastcall **)(hkArrayBase<hkaiBehavior *> *, hkJobQueue *, __int64, _QWORD *))behaviors->m_data + 11))(
        behaviors,
        characters,
        12i64,
        v124);
      hkJobQueue::processAllJobs(characters, 1);
      (*((void (__fastcall **)(hkArrayBase<hkaiBehavior *> *))behaviors->m_data + 4))(behaviors);
    }
    array.m_quad.m128_i32[2] = 0;
    if ( array.m_quad.m128_i32[3] >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, unsigned __int64, _QWORD, _QWORD *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        array.m_quad.m128_u64[0],
        208 * (array.m_quad.m128_i32[3] & 0x3FFFFFFFu),
        v124);
    goto LABEL_124;
  }
  v127 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v128 = (_QWORD *)v127[1];
  if ( (unsigned __int64)v128 < v127[3] )
  {
    *v128 = "Ststeering";
    v129 = __rdtsc();
    v130 = v128 + 2;
    *((_DWORD *)v130 - 2) = v129;
    v127[1] = v130;
  }
  v131 = 0;
  if ( v92 > 0 )
  {
    v132 = 0i64;
    p_m_up = &m_world->m_up;
    localVel.m_world = v184;
    do
    {
      v134 = &localSteeringInputs.m_data[v132];
      if ( localSteeringInputs.m_data[v132].m_enableLocalSteering.m_bool )
      {
        v135 = v134->m_applyAvoidanceSteering.m_bool == 0;
        v136 = (hkVector4f *)v134->m_character;
        *(hkVector4f *)&v190.m_world = v134->m_currentUp;
        if ( v135 )
        {
          hkaiAvoidanceSolverUtils::calcUnsteeredVelocity(
            timestep,
            (hkVector4f *)&v190,
            (hkaiMovementProperties *)(v136[9].m_quad.m128_u64[1] + 16),
            &localSteeringInputs.m_data[v132],
            p_m_up,
            (hkVector4f *)aabbs);
          p_m_up[-1] = *(hkVector4f *)aabbs;
          p_m_up[-1].m_quad.m128_i32[3] = 1056964608;
        }
        else
        {
          v137 = v136[6].m_quad.m128_u32[0];
          hkaiObstacleCollector::hkaiObstacleCollector(
            &job,
            p_m_up[1].m_quad.m128_i32[2],
            v136 + 2,
            (hkVector4f *)&v190);
          hkaiAvoidanceSolverUtils::setupAgent(
            v134,
            (hkaiObstacleCollector *)v7->m_streamingCollection.m_pntr->m_instances.m_data,
            v137,
            v7->m_erosionRadius);
          hkaiAvoidanceSolverUtils::calcSteeringVelocity(
            &result,
            timestep,
            (hkVector4f *)&v190,
            &agentIn,
            p_m_up,
            &array);
          m_enum = result.m_enum;
          p_m_up[-1] = (hkVector4f)array.m_quad;
          job.m_neighborAgents.m_size = 0;
          p_m_up[-1].m_quad.m128_i32[3] = m_enum | 0x3F000000;
          if ( job.m_neighborAgents.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              job.m_neighborAgents.m_data,
              80 * (job.m_neighborAgents.m_capacityAndFlags & 0x3FFFFFFF));
          job.m_neighborAgents.m_data = 0i64;
          job.m_neighborAgents.m_capacityAndFlags = 0x80000000;
          job.m_boundaries.m_size = 0;
          if ( job.m_boundaries.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              job.m_boundaries.m_data,
              32 * job.m_boundaries.m_capacityAndFlags);
          job.m_boundaries.m_data = 0i64;
          job.m_boundaries.m_capacityAndFlags = 0x80000000;
          job.m_spheres.m_size = 0;
          if ( job.m_spheres.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              job.m_spheres.m_data,
              32 * job.m_spheres.m_capacityAndFlags);
        }
      }
      ++v131;
      ++v132;
      p_m_up += 4;
      --localVel.m_world;
    }
    while ( localVel.m_world );
LABEL_124:
    v92 = (__int64)v184;
  }
  v139 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v140 = (_QWORD *)v139[1];
  if ( (unsigned __int64)v140 < v139[3] )
  {
    *v140 = "StsetVel";
    v141 = __rdtsc();
    v142 = v140 + 2;
    *((_DWORD *)v142 - 2) = v141;
    v139[1] = v142;
  }
  if ( v92 > 0 )
  {
    v143 = 0i64;
    v144 = (__m128 *)m_world;
    do
    {
      v145 = &localSteeringInputs.m_data[v143];
      if ( localSteeringInputs.m_data[v143].m_enableLocalSteering.m_bool )
      {
        v146 = *v144;
        m_referenceFrame = v145->m_referenceFrame;
        v148 = v145->m_character;
        *(__m128 *)&localVel.m_world = v144[1];
        v149 = _mm_shuffle_ps(v146, _mm_unpackhi_ps(v146, (__m128)0i64), 196);
        if ( m_referenceFrame )
        {
          hkaiReferenceFrame::transformLocalPosVelToWorldVel(
            m_referenceFrame,
            &localSteeringInputs.m_data[v143].m_currentPosition,
            (hkVector4f *)&localVel,
            (hkVector4f *)&v190);
          v150 = _mm_mul_ps(m_referenceFrame->m_angularVelocity.m_quad, v145->m_currentUp.m_quad);
          v151 = _mm_shuffle_ps(
                   *(__m128 *)&v190.m_world,
                   _mm_unpackhi_ps(
                     *(__m128 *)&v190.m_world,
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v150, v150, 85), _mm_shuffle_ps(v150, v150, 0)),
                         _mm_shuffle_ps(v150, v150, 170)),
                       _mm_shuffle_ps(*(__m128 *)&localVel.m_world, *(__m128 *)&localVel.m_world, 255))),
                   196);
          v152 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v149, v149, 85), m_referenceFrame->m_transform.m_rotation.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v149, v149, 0), m_referenceFrame->m_transform.m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v149, v149, 170), m_referenceFrame->m_transform.m_rotation.m_col2.m_quad));
        }
        else
        {
          v151 = v144[1];
          v152 = v149;
        }
        v148->m_velocity.m_quad = _mm_shuffle_ps(v151, _mm_unpackhi_ps(v151, v148->m_velocity.m_quad), 196);
        if ( v148->m_avoidanceProperties.m_pntr->m_movementProperties.m_kinematicConstraintType.m_storage == 1 )
          v148->m_forward.m_quad = v152;
        hkaiCharacter::setAvoidanceState(v148, (hkResult)(v144->m128_i32[3] & 0xC0FFFFFF));
        v92 = (__int64)v184;
      }
      ++v143;
      v144 += 4;
      v184 = (hkaiWorld *)--v92;
    }
    while ( v92 );
  }
  if ( v7->m_listeners.m_size )
  {
    v153 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v154 = (_QWORD *)v153[1];
    if ( (unsigned __int64)v154 < v153[3] )
    {
      *v154 = "StpostStepCallbacks";
      v155 = __rdtsc();
      v156 = v154 + 2;
      *((_DWORD *)v156 - 2) = v155;
      v153[1] = v156;
    }
    hkaiWorld::CharacterStepCallbackContext::CharacterStepCallbackContext(
      &localVel,
      CALLBACK_POSTCHARACTER_STEP,
      v7,
      timestep,
      (hkArrayBase<hkaiCharacter *> *)this,
      0i64);
    v157 = 0;
    if ( v7->m_listeners.m_size > 0 )
    {
      v158 = 0i64;
      do
      {
        v7->m_listeners.m_data[v158]->vfptr->postCharacterStepCallback(v7->m_listeners.m_data[v158], &localVel);
        ++v157;
        ++v158;
      }
      while ( v157 < v7->m_listeners.m_size );
    }
  }
  v160 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v161 = (_QWORD *)v160[1];
  if ( (unsigned __int64)v161 < v160[3] )
  {
    *v161 = "StbehaviorCallbacks";
    v162 = __rdtsc();
    v159 = (unsigned __int64)HIDWORD(v162) << 32;
    v163 = v161 + 2;
    *((_DWORD *)v163 - 2) = v162;
    v160[1] = v163;
  }
  v164 = 0;
  if ( *(int *)(v199 + 8) > 0 )
  {
    v165 = 0i64;
    do
    {
      (*(void (__fastcall **)(_QWORD, unsigned __int64, _QWORD *))(**(_QWORD **)(v165 + *(_QWORD *)v199) + 32i64))(
        *(_QWORD *)(v165 + *(_QWORD *)v199),
        v159,
        v160);
      ++v164;
      v165 += 8i64;
    }
    while ( v164 < *(_DWORD *)(v199 + 8) );
  }
  v166 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v167 = (_QWORD *)v166[1];
  if ( (unsigned __int64)v167 < v166[3] )
  {
    *v167 = "Stcleanup";
    v168 = __rdtsc();
    v169 = v167 + 2;
    *((_DWORD *)v169 - 2) = v168;
    v166[1] = v169;
  }
  m_data = (int)localSteeringInputs.m_data;
  for ( i = LODWORD(localSteeringInputs.m_data) - 1; i >= 0; --i )
  {
    v172 = (__int64)m_data << 6;
    v173 = *(_DWORD *)((char *)m_world + v172 - 4);
    *(_DWORD *)((char *)m_world + v172 - 8) = 0;
    if ( v173 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)((char *)m_world + v172 - 16),
        8 * v173);
    *(_QWORD *)((char *)m_world + v172 - 16) = 0i64;
    *(_DWORD *)((char *)m_world + v172 - 4) = 0x80000000;
    v174 = *(_DWORD *)((char *)m_world + v172 - 20);
    *(_DWORD *)((char *)m_world + v172 - 24) = 0;
    if ( v174 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)((char *)m_world + v172 - 32),
        8 * v174);
    *(_QWORD *)((char *)m_world + v172 - 32) = 0i64;
    *(_DWORD *)((char *)m_world + v172 - 20) = 0x80000000;
    m_data = i;
  }
  localSteeringInputs.m_size = 0;
  if ( localSteeringInputs.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      localSteeringInputs.m_data,
      160 * (localSteeringInputs.m_capacityAndFlags & 0x3FFFFFFF));
  localSteeringInputs.m_data = 0i64;
  localSteeringInputs.m_capacityAndFlags = 0x80000000;
  v175 = m_data - 1;
  if ( m_data - 1 >= 0 )
  {
    v176 = (int *)&m_world->m_dynamicNavMeshMediator.m_pntr + 16 * v175 + 1;
    do
    {
      v177 = *v176;
      *(v176 - 1) = 0;
      if ( v177 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v176 - 3),
          8 * v177);
      *(_QWORD *)(v176 - 3) = 0i64;
      *v176 = 0x80000000;
      v178 = *(v176 - 4);
      *(v176 - 5) = 0;
      if ( v178 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v176 - 7),
          8 * v178);
      *(_QWORD *)(v176 - 7) = 0i64;
      *(v176 - 4) = 0x80000000;
      v176 -= 16;
      --v175;
    }
    while ( v175 >= 0 );
  }
  if ( v192 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, m_world, v192 << 6);
LABEL_167:
  v179 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v180 = (_QWORD *)v179[1];
  v181 = v179;
  if ( (unsigned __int64)v180 < v179[3] )
  {
    *v180 = "lt";
    v182 = __rdtsc();
    v183 = v180 + 2;
    *((_DWORD *)v183 - 2) = v182;
    v181[1] = v183;
  }
}apAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v176 - 3),
          8 * v177);
      *(_QWORD *)(v176 - 3) = 0i64;
      *v176 = 0x80000000;
      v178 = *(v176 - 4);
      *(v176 - 5) = 0;


// File Line: 599
// RVA: 0xBE1BF0
void __fastcall hkaiWorld::addObstacleGenerator(hkaiWorld *this, hkaiObstacleGenerator *generator)
{
  hkArray<hkRefPtr<hkaiObstacleGenerator>,hkContainerHeapAllocator> *p_m_obstacleGenerators; // rdi
  hkRefPtr<hkaiObstacleGenerator> *v5; // rsi

  if ( generator )
    hkReferencedObject::addReference(generator);
  p_m_obstacleGenerators = &this->m_obstacleGenerators;
  if ( p_m_obstacleGenerators->m_size == (p_m_obstacleGenerators->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_obstacleGenerators, 8);
  v5 = &p_m_obstacleGenerators->m_data[p_m_obstacleGenerators->m_size];
  if ( v5 )
  {
    if ( generator )
      hkReferencedObject::addReference(generator);
    v5->m_pntr = generator;
  }
  ++p_m_obstacleGenerators->m_size;
  if ( generator )
    hkReferencedObject::removeReference(generator);
}

// File Line: 604
// RVA: 0xBE1C90
void __fastcall hkaiWorld::removeObstacleGenerator(hkaiWorld *this, hkaiObstacleGenerator *generator)
{
  __int64 m_size; // rcx
  int v5; // ebx
  __int64 v6; // rdx
  hkRefPtr<hkaiObstacleGenerator> *m_data; // rax
  hkRefPtr<hkaiObstacleGenerator> *v8; // rdi
  hkReferencedObject *m_pntr; // rcx
  __int64 v10; // rax

  if ( generator )
    hkReferencedObject::addReference(generator);
  m_size = this->m_obstacleGenerators.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_7:
    v5 = -1;
  }
  else
  {
    m_data = this->m_obstacleGenerators.m_data;
    while ( m_data->m_pntr != generator )
    {
      ++v6;
      ++v5;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_7;
    }
  }
  if ( generator )
    hkReferencedObject::removeReference(generator);
  if ( v5 >= 0 )
  {
    v8 = this->m_obstacleGenerators.m_data;
    m_pntr = v8[v5].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
    v8[v5].m_pntr = 0i64;
    v10 = --this->m_obstacleGenerators.m_size;
    if ( (_DWORD)v10 != v5 )
      this->m_obstacleGenerators.m_data[v5].m_pntr = this->m_obstacleGenerators.m_data[v10].m_pntr;
  }
}

// File Line: 619
// RVA: 0xBE17D0
void __fastcall hkaiWorld::CharacterStepCallbackContext::CharacterStepCallbackContext(
        hkaiWorld::CharacterStepCallbackContext *this,
        hkaiWorld::CharacterCallbackType cbType,
        hkaiWorld *world,
        float timestep,
        hkArrayBase<hkaiCharacter *> *characters,
        hkArrayBase<hkaiLocalSteeringInput> *localSteeringInputs)
{
  this->m_world = world;
  this->m_callbackType.m_storage = cbType;
  this->m_timestep = timestep;
  this->m_characters = characters;
  this->m_localSteeringInputs = localSteeringInputs;
}

// File Line: 629
// RVA: 0xBE1800
void __fastcall hkaiWorld::CharacterStepSerializableContext::CharacterStepSerializableContext(
        hkaiWorld::CharacterStepSerializableContext *this,
        hkaiWorld::CharacterStepCallbackContext *cbCtx)
{
  hkArrayBase<hkaiLocalSteeringInput> *m_localSteeringInputs; // rax
  int m_size; // ecx
  int v6; // r8d
  hkaiLocalSteeringInput *m_data; // rdx
  hkArray<hkRefPtr<hkaiObstacleGenerator>,hkContainerHeapAllocator> *p_m_obstacleGenerators; // r13
  hkArrayBase<hkaiCharacter *> *m_characters; // rax
  int v10; // r9d
  int v11; // eax
  int v12; // eax
  hkArrayBase<hkaiCharacter *> *v13; // rax
  int v14; // ebp
  __int64 v15; // r14
  hkaiCharacter **v16; // rax
  hkReferencedObject *v17; // rbx
  hkRefPtr<hkaiCharacter const > *v18; // rsi
  hkaiWorld *m_world; // r15
  int v20; // ebx
  int m_capacityAndFlags; // eax
  __int64 v22; // rbp
  int v23; // r12d
  int v24; // eax
  int v25; // eax
  int v26; // r9d
  __int64 v27; // rdi
  __int64 v28; // rbx
  hkReferencedObject *v29; // rcx
  hkReferencedObject **p_m_pntr; // rbx
  signed __int64 v31; // rdi
  __int64 v32; // rsi
  hkReferencedObject *v33; // rcx
  hkReferencedObject *v34; // rax
  hkReferencedObject **v35; // rbx
  __int64 v36; // rsi
  signed __int64 v37; // r14
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiWorld::CharacterStepSerializableContext::`vftable;
  this->m_world = cbCtx->m_world;
  this->m_callbackType.m_storage = cbCtx->m_callbackType.m_storage;
  this->m_timestep = cbCtx->m_timestep;
  this->m_characters.m_data = 0i64;
  this->m_characters.m_size = 0;
  this->m_characters.m_capacityAndFlags = 0x80000000;
  m_localSteeringInputs = cbCtx->m_localSteeringInputs;
  if ( m_localSteeringInputs )
    m_size = m_localSteeringInputs->m_size;
  else
    m_size = 0;
  if ( m_localSteeringInputs )
    v6 = m_localSteeringInputs->m_size;
  else
    v6 = 0;
  if ( m_localSteeringInputs )
    m_data = m_localSteeringInputs->m_data;
  else
    m_data = 0i64;
  this->m_localSteeringInputs.m_data = m_data;
  this->m_localSteeringInputs.m_size = v6;
  p_m_obstacleGenerators = &this->m_obstacleGenerators;
  this->m_localSteeringInputs.m_capacityAndFlags = m_size | 0x80000000;
  this->m_obstacleGenerators.m_data = 0i64;
  this->m_obstacleGenerators.m_size = 0;
  this->m_obstacleGenerators.m_capacityAndFlags = 0x80000000;
  m_characters = cbCtx->m_characters;
  if ( m_characters )
  {
    v10 = m_characters->m_size;
    v11 = this->m_characters.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v11 < v10 )
    {
      v12 = 2 * v11;
      if ( v10 < v12 )
        v10 = v12;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_characters, v10, 8);
    }
    v13 = cbCtx->m_characters;
    v14 = 0;
    if ( v13->m_size > 0 )
    {
      v15 = 0i64;
      do
      {
        v16 = v13->m_data;
        v17 = v16[v15];
        if ( v17 )
          hkReferencedObject::addReference(v16[v15]);
        v18 = &this->m_characters.m_data[this->m_characters.m_size];
        if ( v18 )
        {
          if ( v17 )
            hkReferencedObject::addReference(v17);
          v18->m_pntr = (hkaiCharacter *)v17;
        }
        ++this->m_characters.m_size;
        if ( v17 )
          hkReferencedObject::removeReference(v17);
        v13 = cbCtx->m_characters;
        ++v14;
        ++v15;
      }
      while ( v14 < v13->m_size );
    }
  }
  m_world = this->m_world;
  v20 = this->m_obstacleGenerators.m_size;
  m_capacityAndFlags = this->m_obstacleGenerators.m_capacityAndFlags;
  v22 = m_world->m_obstacleGenerators.m_size;
  v23 = m_world->m_obstacleGenerators.m_size;
  if ( (int)v22 > v20 )
    v23 = v20;
  v24 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v24 < (int)v22 )
  {
    v25 = 2 * v24;
    v26 = m_world->m_obstacleGenerators.m_size;
    if ( (int)v22 < v25 )
      v26 = v25;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_obstacleGenerators, v26, 8);
  }
  v27 = (__int64)&p_m_obstacleGenerators->m_data[v22];
  v28 = v20 - (int)v22 - 1;
  if ( (int)v28 >= 0 )
  {
    do
    {
      v29 = *(hkReferencedObject **)(v27 + 8 * v28);
      if ( v29 )
        hkReferencedObject::removeReference(v29);
      *(_QWORD *)(v27 + 8 * v28--) = 0i64;
    }
    while ( v28 >= 0 );
  }
  p_m_pntr = &p_m_obstacleGenerators->m_data->m_pntr;
  if ( v23 > 0 )
  {
    v31 = (char *)m_world->m_obstacleGenerators.m_data - (char *)p_m_pntr;
    v32 = v23;
    do
    {
      v33 = *(hkReferencedObject **)((char *)p_m_pntr + v31);
      if ( v33 )
        hkReferencedObject::addReference(v33);
      if ( *p_m_pntr )
        hkReferencedObject::removeReference(*p_m_pntr);
      v34 = *(hkReferencedObject **)((char *)p_m_pntr++ + v31);
      *(p_m_pntr - 1) = v34;
      --v32;
    }
    while ( v32 );
  }
  v35 = &m_world->m_obstacleGenerators.m_data[v23].m_pntr;
  v36 = (int)v22 - v23;
  if ( (int)v22 - v23 > 0 )
  {
    v37 = (char *)&p_m_obstacleGenerators->m_data[v23] - (char *)v35;
    do
    {
      if ( (hkReferencedObject **)((char *)v35 + v37) )
      {
        if ( *v35 )
          hkReferencedObject::addReference(*v35);
        *(hkReferencedObject **)((char *)v35 + v37) = *v35;
      }
      ++v35;
      --v36;
    }
    while ( v36 );
  }
  p_m_obstacleGenerators->m_size = v22;
}

// File Line: 644
// RVA: 0xBE1A90
void __fastcall hkaiWorld::CharacterStepSerializableContext::CharacterStepSerializableContext(
        hkaiWorld::CharacterStepSerializableContext *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiWorld::CharacterStepSerializableContext::`vftable;
}

// File Line: 648
// RVA: 0xBE1AB0
void __fastcall hkaiWorld::CharacterStepSerializableContext::~CharacterStepSerializableContext(
        hkaiWorld::CharacterStepSerializableContext *this)
{
  hkRefPtr<hkaiObstacleGenerator> *m_data; // rsi
  int v3; // eax
  __int64 i; // rbx
  hkReferencedObject *m_pntr; // rcx
  int m_capacityAndFlags; // r8d
  int v7; // eax
  hkRefPtr<hkaiCharacter const > *v8; // rsi
  int v9; // eax
  __int64 j; // rbx
  hkReferencedObject *v11; // rcx
  int v12; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkaiWorld::CharacterStepSerializableContext::`vftable;
  m_data = this->m_obstacleGenerators.m_data;
  v3 = this->m_obstacleGenerators.m_size - 1;
  for ( i = v3; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  m_capacityAndFlags = this->m_obstacleGenerators.m_capacityAndFlags;
  this->m_obstacleGenerators.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_obstacleGenerators.m_data,
      8 * m_capacityAndFlags);
  this->m_obstacleGenerators.m_data = 0i64;
  this->m_obstacleGenerators.m_capacityAndFlags = 0x80000000;
  v7 = this->m_localSteeringInputs.m_capacityAndFlags;
  this->m_localSteeringInputs.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_localSteeringInputs.m_data,
      160 * (v7 & 0x3FFFFFFF));
  this->m_localSteeringInputs.m_data = 0i64;
  this->m_localSteeringInputs.m_capacityAndFlags = 0x80000000;
  v8 = this->m_characters.m_data;
  v9 = this->m_characters.m_size - 1;
  for ( j = v9; j >= 0; v8[j--].m_pntr = 0i64 )
  {
    v11 = v8[j].m_pntr;
    if ( v11 )
      hkReferencedObject::removeReference(v11);
  }
  v12 = this->m_characters.m_capacityAndFlags;
  this->m_characters.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_characters.m_data,
      8 * v12);
  this->m_characters.m_data = 0i64;
  this->m_characters.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

