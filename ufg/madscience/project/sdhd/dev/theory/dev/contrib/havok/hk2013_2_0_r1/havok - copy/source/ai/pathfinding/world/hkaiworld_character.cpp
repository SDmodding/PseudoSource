// File Line: 30
// RVA: 0xBE30A0
void __fastcall hkaiWorld::updateMeshFaceForCharacter(hkaiWorld *this, hkaiCharacter *character)
{
  unsigned int v2; // ebx
  hkaiCharacter *v3; // rdi
  hkaiWorld *v4; // rsi
  hkaiStreamingCollection *v5; // rbx
  hkaiDynamicNavMeshQueryMediator *v6; // rax
  hkVector4f pointOut; // [rsp+40h] [rbp-68h]
  hkaiCharacterUtil::GetFaceForPathfindingSettings settings; // [rsp+50h] [rbp-58h]
  hkaiNavMeshQueryMediator::QueryInputBase input; // [rsp+70h] [rbp-38h]

  v2 = character->m_currentNavMeshFace;
  v3 = character;
  v4 = this;
  if ( hkaiWorld::getDynamicQueryMediator(this) )
  {
    input.m_filterInfo = 0;
    input.m_userData = 0i64;
    input.m_hitFilter = 0i64;
    input.m_instance = 0i64;
    input.m_localToWorldTransform = 0i64;
    hkaiCharacterUtil::setupQueryInput(v3, &input);
    hkaiCharacterUtil::GetFaceForPathfindingSettings::GetFaceForPathfindingSettings(&settings);
    settings.m_previousFaceKey = v2;
    v5 = v4->m_streamingCollection.m_pntr;
    settings.m_resolveEdgePenetrations.m_bool = 0;
    v6 = hkaiWorld::getDynamicQueryMediator(v4);
    v3->m_currentNavMeshFace = hkaiCharacterUtil::getFaceForPathfinding(
                                 v5,
                                 &v3->m_position,
                                 &v3->m_up,
                                 (hkaiNavMeshQueryMediator *)&v6->vfptr,
                                 &input,
                                 &settings,
                                 &pointOut);
  }
  else
  {
    v3->m_currentNavMeshFace = -1;
  }
}

// File Line: 62
// RVA: 0xBE1D60
void __fastcall hkaiWorld::stepCharacters(hkaiWorld *this, float timestep, hkArrayBase<hkaiCharacter *> *characters, hkArrayBase<hkaiBehavior *> *behaviors)
{
  hkaiWorld::stepCharactersMT(this, timestep, characters, behaviors, 0i64, 0i64);
}

// File Line: 78
// RVA: 0xBE34A0
void __fastcall `anonymous namespace'::AgentInfo::AgentInfo(AgentInfo *this)
{
  AgentInfo *v1; // rbp
  unsigned int v2; // ebx
  hkaiCharacter **v3; // rax
  hkaiCharacter **v4; // rcx
  unsigned int v5; // ecx
  int v6; // eax
  hkaiObstacleGenerator **v7; // rax
  hkaiObstacleGenerator **v8; // rcx
  int v9; // eax
  int v10; // er9
  int v11; // er9
  hkResult result; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = 2147483648;
  this->m_characters.m_data = 0i64;
  this->m_characters.m_size = 0;
  this->m_characters.m_capacityAndFlags = 2147483648;
  result.m_enum = 64;
  v3 = (hkaiCharacter **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                           (int *)&result);
  v1->m_characters.m_size = 8;
  v4 = v3;
  LODWORD(v3) = result;
  result.m_enum = 64;
  v1->m_characters.m_data = v4;
  v5 = 2147483648;
  v6 = (signed int)v3 / 8;
  if ( v6 )
    v5 = v6;
  v1->m_characters.m_capacityAndFlags = v5;
  v1->m_obstacles.m_data = 0i64;
  v1->m_obstacles.m_size = 0;
  v1->m_obstacles.m_capacityAndFlags = 2147483648;
  v7 = (hkaiObstacleGenerator **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                   (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                   (int *)&result);
  v1->m_obstacles.m_size = 8;
  v8 = v7;
  LODWORD(v7) = result;
  v1->m_obstacles.m_data = v8;
  v9 = (signed int)v7 / 8;
  if ( v9 )
    v2 = v9;
  v1->m_obstacles.m_capacityAndFlags = v2;
  if ( (v1->m_characters.m_capacityAndFlags & 0x3FFFFFFF) < 0 )
  {
    v10 = 0;
    if ( 2 * (v1->m_characters.m_capacityAndFlags & 0x3FFFFFFF) > 0 )
      v10 = 2 * (v1->m_characters.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_characters,
      v10,
      8);
  }
  v1->m_characters.m_size = 0;
  if ( (v1->m_obstacles.m_capacityAndFlags & 0x3FFFFFFF) < 0 )
  {
    v11 = 0;
    if ( 2 * (v1->m_obstacles.m_capacityAndFlags & 0x3FFFFFFF) > 0 )
      v11 = 2 * (v1->m_obstacles.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_obstacles,
      v11,
      8);
  }
  v1->m_obstacles.m_size = 0;
}

// File Line: 93
// RVA: 0xBE3170
void __fastcall hkaiWorld::calcDesiredVelocities(hkaiWorld *this, float timestep, int numCharacters, hkArrayBase<hkaiBehavior *> *behaviors, hkJobQueue *jobQueue, hkJobThreadPool *threadPool, hkArray<hkaiLocalSteeringInput,hkContainerTempAllocator> *localSteeringInputs)
{
  hkArray<hkaiLocalSteeringInput,hkContainerTempAllocator> *v7; // r12
  int v8; // ebp
  hkaiWorld *v9; // rbx
  int v10; // eax
  unsigned int v11; // er15
  int v12; // eax
  int v13; // er9
  hkJobQueue *v14; // rdi
  int v15; // ecx
  hkaiBehavior **v16; // r15
  int v17; // eax
  int v18; // er13
  int v19; // eax
  __int64 v20; // r12
  int v21; // edx
  int v22; // eax
  int v23; // ebx
  int v24; // esi
  hkaiBehavior **v25; // rdi
  __int64 v26; // r14
  int v27; // eax
  hkJobThreadPool *v28; // rbx
  hkaiLocalSteeringInput *v29; // r13
  __int64 v30; // r14
  __int64 v31; // r12
  unsigned int v32; // ebx
  hkaiBehavior *v33; // rdi
  __int64 v34; // rdx
  int v35; // esi
  hkaiCharacter *v36; // rax
  int v37; // eax
  __int64 v38; // rbx
  hkaiReferenceFrame *v39; // rcx
  int v40; // [rsp+30h] [rbp-98h]
  int v41; // [rsp+34h] [rbp-94h]
  hkJob job; // [rsp+40h] [rbp-88h]
  __int128 v43; // [rsp+50h] [rbp-78h]
  hkaiBehavior **v44; // [rsp+60h] [rbp-68h]
  int v45; // [rsp+68h] [rbp-60h]
  __int64 v46; // [rsp+70h] [rbp-58h]
  int v47; // [rsp+78h] [rbp-50h]
  float v48; // [rsp+7Ch] [rbp-4Ch]
  int v49; // [rsp+E0h] [rbp+18h]
  hkArrayBase<hkaiBehavior *> *v50; // [rsp+E8h] [rbp+20h]

  v50 = behaviors;
  v7 = localSteeringInputs;
  v8 = 0;
  v9 = this;
  v10 = localSteeringInputs->m_capacityAndFlags & 0x3FFFFFFF;
  v11 = numCharacters;
  localSteeringInputs->m_size = 0;
  if ( v10 < numCharacters )
  {
    v12 = 2 * v10;
    v13 = numCharacters;
    if ( numCharacters < v12 )
      v13 = v12;
    hkArrayUtil::_reserve((hkResult *)&v49, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v7, v13, 160);
    behaviors = v50;
  }
  v14 = jobQueue;
  v7->m_size = v11;
  if ( v14 && threadPool )
  {
    v15 = v9->m_numBehaviorUpdatesPerJob;
    v16 = behaviors->m_data;
    v48 = timestep;
    job.m_size = 64;
    *(_WORD *)&job.m_jobSubType = 3073;
    _mm_store_si128((__m128i *)&v43, (__m128i)0i64);
    job.m_threadAffinity = -1;
    v45 = -1;
    v47 = -1;
    v17 = behaviors->m_size;
    v44 = 0i64;
    v46 = 0i64;
    job.m_jobSpuType.m_storage = 2;
    v40 = v15;
    v18 = 0;
    v19 = (v15 + v17 - 1) / v15;
    v41 = v19;
    if ( v19 > 0 )
    {
      v20 = (__int64)v7->m_data;
      v21 = v19 - 1;
      v22 = 0;
      v49 = 0;
      do
      {
        if ( v18 == v21 )
          v23 = behaviors->m_size - v22;
        else
          v23 = v15;
        v44 = v16;
        v45 = v23;
        v24 = 0;
        if ( v23 > 0 )
        {
          v25 = v16;
          v26 = (unsigned int)v23;
          do
          {
            v27 = ((__int64 (*)(void))(*v25)->vfptr[6].__vecDelDtor)();
            ++v25;
            v24 += v27;
            --v26;
          }
          while ( v26 );
          v14 = jobQueue;
        }
        v46 = v20;
        v16 += v23;
        v47 = v24;
        v20 += 160i64 * v24;
        hkJobQueue::addJob(v14, &job, 0);
        v15 = v40;
        behaviors = v50;
        ++v18;
        v22 = v40 + v49;
        v21 = v41 - 1;
        v49 += v40;
      }
      while ( v18 < v41 );
      v7 = localSteeringInputs;
      if ( v41 > 0 )
      {
        v28 = threadPool;
        ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64, hkArrayBase<hkaiBehavior *> *))threadPool->vfptr[5].__first_virtual_table_function__)(
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
        v35 = ((__int64 (__fastcall *)(hkaiBehavior *))v33->vfptr[6].__vecDelDtor)(v33);
        if ( v35 > 0 )
        {
          do
          {
            v36 = (hkaiCharacter *)((__int64 (__fastcall *)(hkaiBehavior *, _QWORD))v33->vfptr[6].__first_virtual_table_function__)(
                                     v33,
                                     v32);
            if ( v36->m_state.m_storage != 7 )
              hkaiWorld::updateMeshFaceForCharacter(v33->m_world.m_pntr, v36);
            ++v32;
          }
          while ( (signed int)v32 < v35 );
        }
        v37 = ((__int64 (__fastcall *)(hkaiBehavior *, __int64, hkaiLocalSteeringInput *, _QWORD))v33->vfptr[1].__first_virtual_table_function__)(
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
        v39 = v7->m_data[v38].m_referenceFrame;
        if ( v39 )
          hkaiReferenceFrame::validate(v39);
      }
      ++v8;
      ++v38;
    }
    while ( v8 < v7->m_size );
  }
}

// File Line: 175
// RVA: 0xBE1D80
void __usercall hkaiWorld::stepCharactersMT(hkaiWorld *this@<rcx>, float timestep@<xmm1>, hkArrayBase<hkaiCharacter *> *characters@<r8>, hkArrayBase<hkaiBehavior *> *behaviors@<r9>, __m128 *a5@<xmm14>, hkJobQueue *jobQueue, hkJobThreadPool *threadPool)
{
  hkaiWorld *v7; // r12
  float v8; // xmm7_4
  hkArrayBase<hkaiBehavior *> *v9; // r15
  hkArrayBase<hkaiCharacter *> *v10; // rsi
  _QWORD *v11; // rax
  unsigned __int64 v12; // rcx
  _QWORD *v13; // r10
  const char *v14; // rdx
  unsigned __int64 v15; // rax
  signed __int64 v16; // r14
  int v17; // ebx
  __int64 v18; // rdi
  AgentInfo *v19; // rax
  int v20; // ecx
  hkVector4f *v21; // rdi
  AgentInfo *v22; // rbx
  __int64 v23; // rsi
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  signed __int64 v27; // rcx
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  signed __int64 v31; // rcx
  int v32; // esi
  __int64 v33; // rbx
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  signed __int64 v37; // rcx
  _QWORD *v38; // r8
  unsigned __int64 v39; // rcx
  unsigned __int64 v40; // rax
  __int64 v41; // r13
  int v42; // er15
  int v43; // eax
  hkResultEnum v44; // ecx
  int v45; // ebx
  hk1AxisSweep::AabbInt *v46; // rdi
  __int64 v47; // rsi
  __m128 *v48; // rcx
  __m128 *v49; // rax
  __m128 v50; // xmm0
  __m128 v51; // xmm2
  __int64 v52; // rsi
  __int64 v53; // r14
  hk1AxisSweep::AabbInt *v54; // r13
  hkaiObstacleGenerator *v55; // rcx
  hk1AxisSweep::AabbInt *v56; // rdx
  __int64 v57; // rax
  int v58; // ebx
  __int64 v59; // rax
  _QWORD *v60; // r8
  _QWORD *v61; // rcx
  unsigned __int64 v62; // rax
  signed __int64 v63; // rcx
  _QWORD *v64; // r8
  _QWORD *v65; // rcx
  unsigned __int64 v66; // rax
  signed __int64 v67; // rcx
  hk1AxisSweep::AabbInt *v68; // rcx
  int v69; // er8
  char *v70; // rax
  unsigned int *v71; // r15
  hk1AxisSweep::AabbInt *v72; // rdx
  __int64 v73; // r8
  __int64 v74; // r9
  bool v75; // cl
  __int64 v76; // rbx
  __int64 v77; // rsi
  hkaiCharacter *v78; // r13
  hkaiCharacter *v79; // r14
  hkaiLocalSteeringFilter *v80; // rcx
  __m128 *v81; // rbx
  hkaiLocalSteeringFilter *v82; // rcx
  __m128 *v83; // rbx
  hkaiCharacter *v84; // rdx
  __int64 v85; // rcx
  hkaiObstacleGenerator *v86; // rsi
  hkaiLocalSteeringFilter *v87; // rcx
  __m128 *v88; // rbx
  _QWORD *v89; // r8
  _QWORD *v90; // rcx
  unsigned __int64 v91; // rax
  signed __int64 v92; // rcx
  signed __int64 v93; // rsi
  signed __int64 v94; // r14
  __int64 v95; // rbx
  unsigned int *v96; // rsi
  _QWORD *v97; // r8
  _QWORD *v98; // rcx
  unsigned __int64 v99; // rax
  signed __int64 v100; // rcx
  hkaiStreamingCollection *v101; // rax
  hkaiAvoidancePairProperties *v102; // rcx
  __int64 v103; // r14
  int v104; // er9
  int v105; // esi
  __int64 v106; // rax
  __int64 v107; // r14
  signed __int64 v108; // rbx
  __int64 v109; // r15
  hkaiLocalSteeringInput *v110; // r9
  hkaiCharacter *v111; // rdx
  __int64 v112; // rcx
  hkVector4f *v113; // rcx
  _QWORD *v114; // r8
  _QWORD *v115; // rcx
  unsigned __int64 v116; // rax
  signed __int64 v117; // rcx
  __int64 v118; // r15
  float v119; // er8
  __int64 v120; // r14
  int v121; // ebx
  int v122; // eax
  int v123; // er13
  int v124; // edi
  int v125; // esi
  _QWORD *v126; // r9
  unsigned __int64 v127; // r8
  unsigned __int64 v128; // rax
  _QWORD *v129; // r8
  _QWORD *v130; // rcx
  unsigned __int64 v131; // rax
  signed __int64 v132; // rcx
  int v133; // er13
  __int64 v134; // r15
  hkVector4f *v135; // rsi
  hkaiLocalSteeringInput *v136; // r14
  bool v137; // zf
  hkVector4f *v138; // r8
  unsigned int v139; // ebx
  hkArray<hkaiLocalSteeringInput,hkContainerTempAllocator> *localSteeringInputs; // ST30_8
  hkResultEnum v141; // eax
  _QWORD *v142; // r8
  _QWORD *v143; // rcx
  unsigned __int64 v144; // rax
  signed __int64 v145; // rcx
  __int64 v146; // r15
  hkVector4f *v147; // rbx
  hkaiLocalSteeringInput *v148; // r14
  __m128 v149; // xmm6
  hkaiReferenceFrame *v150; // r13
  hkaiCharacter *v151; // rsi
  __m128 v152; // xmm6
  __m128 v153; // xmm1
  __m128 v154; // xmm1
  __m128 v155; // xmm2
  _QWORD *v156; // r8
  _QWORD *v157; // rcx
  unsigned __int64 v158; // rax
  signed __int64 v159; // rcx
  int v160; // esi
  __int64 v161; // rbx
  unsigned __int64 v162; // rdx
  _QWORD *v163; // r8
  _QWORD *v164; // rcx
  unsigned __int64 v165; // rax
  signed __int64 v166; // rcx
  int v167; // esi
  __int64 v168; // rbx
  _QWORD *v169; // r8
  _QWORD *v170; // rcx
  unsigned __int64 v171; // rax
  signed __int64 v172; // rcx
  int v173; // ebx
  int i; // esi
  signed __int64 v175; // rbx
  int v176; // er8
  int v177; // er8
  __int64 v178; // rsi
  int *v179; // rbx
  int v180; // er8
  int v181; // er8
  _QWORD *v182; // rax
  _QWORD *v183; // rcx
  _QWORD *v184; // r8
  unsigned __int64 v185; // rax
  signed __int64 v186; // rcx
  signed __int64 v187; // [rsp+50h] [rbp-A0h]
  int v188; // [rsp+58h] [rbp-98h]
  signed int v189; // [rsp+58h] [rbp-98h]
  hkResult result; // [rsp+5Ch] [rbp-94h]
  hkVector4f array; // [rsp+60h] [rbp-90h]
  hkArray<hkaiLocalSteeringInput,hkContainerTempAllocator> v192; // [rsp+70h] [rbp-80h]
  hkaiWorld::CharacterStepCallbackContext v193; // [rsp+80h] [rbp-70h]
  hk1AxisSweep::AabbInt *aabbs[2]; // [rsp+A0h] [rbp-50h]
  int v195; // [rsp+B0h] [rbp-40h]
  int v196; // [rsp+B4h] [rbp-3Ch]
  hkJob job; // [rsp+C0h] [rbp-30h]
  __int128 v198; // [rsp+D0h] [rbp-20h]
  void *v199; // [rsp+E0h] [rbp-10h]
  hkaiStreamingCollection::InstanceInfo *v200; // [rsp+E8h] [rbp-8h]
  hkaiAvoidancePairProperties::PairData *v201; // [rsp+F0h] [rbp+0h]
  int v202; // [rsp+F8h] [rbp+8h]
  unsigned __int64 v203; // [rsp+100h] [rbp+10h]
  int v204; // [rsp+108h] [rbp+18h]
  hkVector4f localVel; // [rsp+120h] [rbp+30h]
  hkaiAvoidanceSolver::SteeringAgent agentIn; // [rsp+140h] [rbp+50h]
  hkaiWorld *vars0; // [rsp+2C0h] [rbp+1D0h]
  hkArrayBase<hkaiCharacter *> *charactersa; // [rsp+2D0h] [rbp+1E0h]
  __int64 v209; // [rsp+2D8h] [rbp+1E8h]
  hkJobQueue *v210; // [rsp+2E0h] [rbp+1F0h]
  hkJobThreadPool *v211; // [rsp+2E8h] [rbp+1F8h]

  v211 = (hkJobThreadPool *)behaviors;
  v210 = (hkJobQueue *)characters;
  charactersa = (hkArrayBase<hkaiCharacter *> *)this;
  v7 = this;
  v8 = timestep;
  v9 = behaviors;
  v10 = characters;
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = v11[1];
  v13 = v11;
  v14 = "Stsetup";
  if ( v12 < v11[3] )
  {
    *(_QWORD *)(v12 + 16) = "Stsetup";
    *(_QWORD *)v12 = "LtstepCharacters";
    v15 = __rdtsc();
    v14 = (const char *)((unsigned __int64)HIDWORD(v15) << 32);
    *(_DWORD *)(v12 + 8) = v15;
    v13[1] = v12 + 24;
  }
  v16 = v10->m_size;
  LODWORD(v192.m_data) = v16;
  if ( !(_DWORD)v16 )
    goto LABEL_169;
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
  v192.m_size = (_DWORD)v16 << 6;
  v19 = (AgentInfo *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                       (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                       &v192.m_size);
  v20 = 2147483648;
  v21 = &v19->m_steerOut.m_forwardAndResult;
  localVel.m_quad.m128_u64[0] = (unsigned __int64)v19;
  if ( v192.m_size / 64 )
    v20 = v192.m_size / 64;
  v195 = v20;
  if ( (signed int)v16 > 0 )
  {
    v22 = v19;
    v23 = (unsigned int)v16;
    do
    {
      if ( v22 )
        `anonymous namespace'::AgentInfo::AgentInfo(v22);
      ++v22;
      --v23;
    }
    while ( v23 );
    v10 = charactersa;
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "StcalcDesiredVel";
    v26 = __rdtsc();
    v27 = (signed __int64)(v25 + 2);
    *(_DWORD *)(v27 - 8) = v26;
    v24[1] = v27;
  }
  v192.m_data = 0i64;
  v192.m_size = 0;
  v192.m_capacityAndFlags = 2147483648;
  hkaiWorld::calcDesiredVelocities(v7, timestep, v16, v9, v210, v211, &v192);
  if ( v7->m_listeners.m_size )
  {
    v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v29 = (_QWORD *)v28[1];
    if ( (unsigned __int64)v29 < v28[3] )
    {
      *v29 = "StpreStepCallbacks";
      v30 = __rdtsc();
      v31 = (signed __int64)(v29 + 2);
      *(_DWORD *)(v31 - 8) = v30;
      v28[1] = v31;
    }
    hkaiWorld::CharacterStepCallbackContext::CharacterStepCallbackContext(
      &v193,
      0,
      v7,
      timestep,
      v10,
      (hkArrayBase<hkaiLocalSteeringInput> *)&v192.m_data);
    v32 = 0;
    if ( v7->m_listeners.m_size > 0 )
    {
      v33 = 0i64;
      do
      {
        (*(void (__fastcall **)(hkaiWorld::Listener *, hkaiWorld::CharacterStepCallbackContext *))v7->m_listeners.m_data[v33]->vfptr->gap8)(
          v7->m_listeners.m_data[v33],
          &v193);
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
    v37 = (signed __int64)(v35 + 2);
    *(_DWORD *)(v37 - 8) = v36;
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
  v42 = v16 + v41;
  v43 = v16 + v41 + 4;
  if ( (_DWORD)v16 + (_DWORD)v41 == -4 )
  {
    aabbs[0] = 0i64;
  }
  else
  {
    HIDWORD(v192.m_data) = 32 * v43;
    aabbs[0] = (hk1AxisSweep::AabbInt *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, char *, _QWORD *))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                                          &hkContainerTempAllocator::s_alloc,
                                          (char *)&v192.m_data + 4,
                                          v38);
    v43 = SHIDWORD(v192.m_data) / 32;
  }
  v44 = 2147483648;
  v187 = v16;
  if ( v43 )
    v44 = v43;
  v45 = 0;
  result.m_enum = v44;
  if ( (signed int)v16 > 0 )
  {
    v46 = aabbs[0];
    v47 = 0i64;
    do
    {
      v48 = (__m128 *)v192.m_data[v47].m_character;
      v49 = (__m128 *)v48[9].m128_u64[1];
      v50 = _mm_max_ps(_mm_shuffle_ps((__m128)v48[6].m128_u32[3], (__m128)v48[6].m128_u32[3], 0), v48[5]);
      v51 = _mm_mul_ps(v49[5], v50);
      *(__m128 *)&v193.m_world = _mm_add_ps(_mm_mul_ps(v49[4], v50), v48[2]);
      *(__m128 *)&v193.m_characters = _mm_add_ps(v51, v48[2]);
      hk1AxisSweep::AabbInt::set(&v46[v45], (hkAabb *)&v193, v45);
      ++v45;
      ++v47;
      --v16;
    }
    while ( v16 );
    v21 = (hkVector4f *)localVel.m_quad.m128_u64[0];
  }
  v52 = 0i64;
  v53 = v41;
  if ( (signed int)v41 > 0 )
  {
    v54 = aabbs[0];
    do
    {
      v55 = v7->m_obstacleGenerators.m_data[v52].m_pntr;
      ((void (__fastcall *)(hkaiObstacleGenerator *, hkaiWorld::CharacterStepCallbackContext *))v55->vfptr[2].__first_virtual_table_function__)(
        v55,
        &v193);
      hk1AxisSweep::AabbInt::set(&v54[v45], (hkAabb *)&v193, v45);
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
  v56[v58 + 1i64].m_min[0] = -1;
  v60 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v61 = (_QWORD *)v60[1];
  if ( (unsigned __int64)v61 < v60[3] )
  {
    *v61 = "StsortAabbs";
    v62 = __rdtsc();
    v63 = (signed __int64)(v61 + 2);
    *(_DWORD *)(v63 - 8) = v62;
    v60[1] = v63;
  }
  hk1AxisSweep::sortAabbs(aabbs[0], v42);
  v64 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v65 = (_QWORD *)v64[1];
  if ( (unsigned __int64)v65 < v64[3] )
  {
    *v65 = "Stscan";
    v66 = __rdtsc();
    v67 = (signed __int64)(v65 + 2);
    *(_DWORD *)(v67 - 8) = v66;
    v64[1] = v67;
  }
  v68 = aabbs[0];
  v69 = 0;
  v196 = v42 - 1;
  v70 = (char *)1;
  v188 = 0;
  v193.m_world = (hkaiWorld *)1;
  v71 = &aabbs[0]->m_min[1];
  do
  {
    array.m_quad.m128_u64[0] = (unsigned __int64)v70;
    v72 = (hk1AxisSweep::AabbInt *)(v71 + 7);
    if ( v71[7] > v71[3] )
      goto LABEL_68;
    do
    {
      if ( (((v72->m_max[1] - *v71) | (v72->m_max[2] - v71[1]) | (v71[4] - v72->m_min[1]) | (v71[5] - v72->m_min[2])) & 0x80000000) != 0 )
        goto LABEL_66;
      v73 = (signed int)v71[2];
      v74 = *(signed int *)v72->m_expansionMin;
      v75 = (signed int)v74 < SLODWORD(v192.m_data);
      if ( (signed int)v73 >= SLODWORD(v192.m_data) )
      {
        if ( !v75 )
          goto LABEL_66;
        v76 = *(signed int *)v72->m_expansionMin;
        v84 = v192.m_data[v74].m_character;
        v85 = (signed int)v71[2];
      }
      else
      {
        v76 = (signed int)v71[2];
        if ( v75 )
        {
          v77 = *(signed int *)v72->m_expansionMin;
          v78 = v192.m_data[v73].m_character;
          v79 = v192.m_data[v74].m_character;
          v80 = v78->m_steeringFilter.m_pntr;
          if ( !v80
            || ((unsigned int (__fastcall *)(hkaiLocalSteeringFilter *, hkaiCharacter *, hkaiCharacter *))v80->vfptr[1].__first_virtual_table_function__)(
                 v80,
                 v78,
                 v192.m_data[v74].m_character) )
          {
            v81 = &v21[4 * v76].m_quad;
            if ( v81[2].m128_i32[2] == (v81[2].m128_i32[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v81[2], 8);
            *(_QWORD *)(v81[2].m128_u64[0] + 8i64 * v81[2].m128_i32[2]++) = v79;
          }
          v82 = v79->m_steeringFilter.m_pntr;
          if ( !v82
            || ((unsigned int (__fastcall *)(hkaiLocalSteeringFilter *, hkaiCharacter *, hkaiCharacter *))v82->vfptr[1].__first_virtual_table_function__)(
                 v82,
                 v79,
                 v78) )
          {
            v83 = &v21[4 * v77].m_quad;
            if ( v83[2].m128_i32[2] == (v83[2].m128_i32[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v83[2], 8);
            *(_QWORD *)(v83[2].m128_u64[0] + 8i64 * v83[2].m128_i32[2]++) = v78;
          }
          goto LABEL_66;
        }
        v84 = v192.m_data[v73].m_character;
        v85 = v74;
      }
      v86 = v7->m_obstacleGenerators.m_data[v85 - v187].m_pntr;
      v87 = v84->m_steeringFilter.m_pntr;
      if ( !v87
        || ((unsigned int (__fastcall *)(hkaiLocalSteeringFilter *, hkaiCharacter *, hkaiObstacleGenerator *))v87->vfptr[2].__vecDelDtor)(
             v87,
             v84,
             v86) )
      {
        v88 = &v21[4 * v76].m_quad;
        if ( v88[3].m128_i32[2] == (v88[3].m128_i32[3] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v88[3], 8);
        *(_QWORD *)(v88[3].m128_u64[0] + 8i64 * v88[3].m128_i32[2]++) = v86;
      }
LABEL_66:
      v68 = aabbs[0];
      v72 = &aabbs[0][++array.m_quad.m128_u64[0]];
    }
    while ( v72->m_min[0] <= v71[3] );
    v69 = v188;
LABEL_68:
    ++v69;
    v71 += 8;
    v70 = (char *)&v193.m_world->vfptr + 1;
    v188 = v69;
    ++v193.m_world;
  }
  while ( v69 < v196 );
  if ( (signed int)result.m_enum >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v68,
      32 * result.m_enum);
  v89 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v90 = (_QWORD *)v89[1];
  if ( (unsigned __int64)v90 < v89[3] )
  {
    *v90 = "lt";
    v91 = __rdtsc();
    v92 = (signed __int64)(v90 + 2);
    *(_DWORD *)(v92 - 8) = v91;
    v89[1] = v92;
  }
  v93 = v187;
  if ( v187 > 0 )
  {
    v94 = v187;
    v95 = 0i64;
    v96 = &v21[2].m_quad.m128_u32[2];
    do
    {
      if ( v192.m_data[v95].m_enableLocalSteering.m_bool )
        hkaiAdaptiveRanger::updateRange(
          &v192.m_data[v95].m_character->m_adaptiveRanger,
          v192.m_data[v95].m_character->m_avoidanceProperties.m_pntr->m_maxNeighbors,
          *v96);
      ++v95;
      v96 += 16;
      --v94;
    }
    while ( v94 );
    v93 = v187;
  }
  if ( v210 && v211 )
  {
    v97 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v98 = (_QWORD *)v97[1];
    if ( (unsigned __int64)v98 < v97[3] )
    {
      *v98 = "StsetupJobs";
      v99 = __rdtsc();
      v100 = (signed __int64)(v98 + 2);
      *(_DWORD *)(v100 - 8) = v99;
      v97[1] = v100;
    }
    v200 = 0i64;
    job.m_size = 80;
    *(float *)&v199 = timestep;
    job.m_threadAffinity = -1;
    v204 = -1;
    v101 = v7->m_streamingCollection.m_pntr;
    _mm_store_si128((__m128i *)&v198, (__m128i)0i64);
    HIDWORD(v199) = LODWORD(v7->m_erosionRadius);
    *(_WORD *)&job.m_jobSubType = 3072;
    job.m_jobSpuType.m_storage = 1;
    v201 = 0i64;
    v202 = 0;
    v203 = 0i64;
    v200 = v101->m_instances.m_data;
    v102 = v7->m_avoidancePairProps.m_pntr;
    v189 = 0;
    if ( v102 )
    {
      v201 = v102->m_avoidancePairDataMap.m_data;
      v202 = v102->m_avoidancePairDataMap.m_size;
    }
    v103 = SLODWORD(v192.m_data);
    array.m_quad.m128_u64[0] = 0i64;
    array.m_quad.m128_u64[1] = 0x8000000000000000i64;
    if ( SLODWORD(v192.m_data) > 0 )
    {
      v104 = v103;
      if ( SLODWORD(v192.m_data) < 0 )
        v104 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v104, 208);
    }
    v105 = 0;
    v106 = v103;
    if ( (signed int)v103 > 0 )
    {
      v107 = 0i64;
      v108 = (signed __int64)&v21[2].m_quad.m128_i64[1];
      v109 = v106;
      do
      {
        v110 = &v192.m_data[v107];
        v111 = v192.m_data[v107].m_character;
        if ( v192.m_data[v107].m_enableLocalSteering.m_bool )
        {
          if ( v110->m_applyAvoidanceSteering.m_bool )
          {
            v112 = array.m_quad.m128_i32[2];
            ++array.m_quad.m128_i32[2];
            v189 = 1;
            v113 = (hkVector4f *)(array.m_quad.m128_u64[0] + 208 * v112);
            *v113 = v110->m_currentPosition;
            v113[1] = v110->m_currentForward;
            v113[2] = v110->m_currentUp;
            v113[3] = v110->m_currentVelocity;
            v113[4] = v110->m_desiredVelocity;
            v113[5] = v110->m_desiredFutureDir;
            v113[6] = v110->m_localGoalPlane;
            v113[7].m_quad.m128_i32[0] = LODWORD(v110->m_distToLocalGoal);
            v113[7].m_quad.m128_i32[1] = LODWORD(v110->m_timeToLocalGoal);
            v113[7].m_quad.m128_u64[1] = (unsigned __int64)v110->m_character;
            v113[8].m_quad.m128_u64[0] = (unsigned __int64)v110->m_referenceFrame;
            v113[8].m_quad.m128_u64[1] = (unsigned __int64)v110->m_avoidanceProperties;
            v113[9].m_quad.m128_i8[0] = v110->m_isLocalGoalLast.m_bool;
            v113[9].m_quad.m128_i8[1] = v110->m_applyKinematicConstraints.m_bool;
            v113[9].m_quad.m128_i8[2] = v110->m_applyAvoidanceSteering.m_bool;
            v113[9].m_quad.m128_i8[3] = v110->m_enableLocalSteering.m_bool;
            v113[10].m_quad.m128_u64[0] = *(_QWORD *)(v108 - 8);
            v113[11].m_quad.m128_i32[0] = *(_DWORD *)v108;
            v113[10].m_quad.m128_u64[1] = *(_QWORD *)(v108 + 8);
            v113[11].m_quad.m128_i32[1] = *(_DWORD *)(v108 + 16);
            v113[11].m_quad.m128_i32[2] = v111->m_currentNavMeshFace;
            v113[12].m_quad.m128_u64[0] = (unsigned __int64)&v21[4 * (signed __int64)v105];
          }
          else
          {
            hkaiAvoidanceSolverUtils::calcUnsteeredVelocity(
              timestep,
              &v111->m_up,
              &v111->m_avoidanceProperties.m_pntr->m_movementProperties,
              v110,
              a5,
              &v21[4 * (signed __int64)v105 + 1],
              (hkVector4f *)&v193);
            *(_OWORD *)(v108 - 40) = *(_OWORD *)&v193.m_world;
            *(_DWORD *)(v108 - 28) = 1056964608;
          }
        }
        ++v105;
        ++v107;
        v108 += 64i64;
        --v109;
      }
      while ( v109 );
    }
    v114 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v115 = (_QWORD *)v114[1];
    if ( (unsigned __int64)v115 < v114[3] )
    {
      *v115 = "StqueueJobs";
      v116 = __rdtsc();
      v117 = (signed __int64)(v115 + 2);
      *(_DWORD *)(v117 - 8) = v116;
      v114[1] = v117;
    }
    v118 = v7->m_numCharactersPerAvoidanceJob;
    v119 = array.m_quad.m128_f32[2];
    v120 = 0i64;
    v121 = 0;
    v122 = ((signed int)v118 + array.m_quad.m128_i32[2] - 1) / (signed int)v118;
    v123 = v122;
    if ( v122 > 0 )
    {
      v124 = v122 - 1;
      v125 = 0;
      while ( 1 )
      {
        v203 = v120 + array.m_quad.m128_u64[0];
        v204 = v121 == v124 ? LODWORD(v119) - v125 : (_DWORD)v118;
        hkJobQueue::addJob(v210, &job, 0);
        ++v121;
        v125 += v118;
        v120 += 208 * v118;
        if ( v121 >= v123 )
          break;
        v119 = array.m_quad.m128_f32[2];
      }
      v21 = (hkVector4f *)localVel.m_quad.m128_u64[0];
      v7 = vars0;
      LODWORD(v120) = 0;
    }
    v126 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v127 = v126[1];
    if ( v127 < v126[3] )
    {
      *(_QWORD *)v127 = "StprocessJobs";
      v128 = __rdtsc();
      *(_DWORD *)(v127 + 8) = v128;
      v126[1] = v127 + 16;
    }
    if ( v189 )
    {
      ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64, LPVOID))v211->vfptr[5].__first_virtual_table_function__)(
        v211,
        v210,
        12i64,
        v126);
      hkJobQueue::processAllJobs(v210, 1);
      ((void (__fastcall *)(hkJobThreadPool *))v211->vfptr[2].__vecDelDtor)(v211);
    }
    array.m_quad.m128_i32[2] = v120;
    if ( array.m_quad.m128_i32[3] >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, unsigned __int64, _QWORD, _QWORD *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        array.m_quad.m128_u64[0],
        208 * (array.m_quad.m128_i32[3] & 0x3FFFFFFFu),
        v126);
    goto LABEL_126;
  }
  v129 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v130 = (_QWORD *)v129[1];
  if ( (unsigned __int64)v130 < v129[3] )
  {
    *v130 = "Ststeering";
    v131 = __rdtsc();
    v132 = (signed __int64)(v130 + 2);
    *(_DWORD *)(v132 - 8) = v131;
    v129[1] = v132;
  }
  v133 = 0;
  if ( v93 > 0 )
  {
    v134 = 0i64;
    v135 = v21 + 1;
    localVel.m_quad.m128_u64[0] = v187;
    do
    {
      v136 = &v192.m_data[v134];
      if ( v192.m_data[v134].m_enableLocalSteering.m_bool )
      {
        v137 = v136->m_applyAvoidanceSteering.m_bool == 0;
        v138 = (hkVector4f *)v136->m_character;
        _mm_store_si128((__m128i *)&v193, (__m128i)v136->m_currentUp.m_quad);
        if ( v137 )
        {
          hkaiAvoidanceSolverUtils::calcUnsteeredVelocity(
            timestep,
            (hkVector4f *)&v193,
            (hkaiMovementProperties *)(v138[9].m_quad.m128_u64[1] + 16),
            v136,
            a5,
            v135,
            (hkVector4f *)aabbs);
          v135[-1] = *(hkVector4f *)aabbs;
          v135[-1].m_quad.m128_i32[3] = 1056964608;
        }
        else
        {
          v139 = v138[6].m_quad.m128_u32[0];
          hkaiObstacleCollector::hkaiObstacleCollector(
            (hkaiObstacleCollector *)&job,
            v135[1].m_quad.m128_i32[2],
            v138 + 2,
            (hkVector4f *)&v193);
          localSteeringInputs = (hkArray<hkaiLocalSteeringInput,hkContainerTempAllocator> *)v7->m_avoidancePairProps.m_pntr;
          hkaiAvoidanceSolverUtils::setupAgent(
            v136,
            v7->m_streamingCollection.m_pntr->m_instances.m_data,
            v139,
            v7->m_erosionRadius);
          hkaiAvoidanceSolverUtils::calcSteeringVelocity(
            &result,
            timestep,
            (hkVector4f *)&v193,
            &agentIn,
            a5,
            v135,
            &array);
          v141 = result.m_enum;
          v135[-1] = (hkVector4f)array.m_quad;
          LODWORD(v200) = 0;
          v135[-1].m_quad.m128_i32[3] = v141 | 0x3F000000;
          if ( SHIDWORD(v200) >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              v199,
              80 * (HIDWORD(v200) & 0x3FFFFFFF));
          v199 = 0i64;
          HIDWORD(v200) = 2147483648;
          DWORD2(v198) = 0;
          if ( v198 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              (void *)v198,
              32 * HIDWORD(v198));
          *(_QWORD *)&v198 = 0i64;
          HIDWORD(v198) = 2147483648;
          *(_DWORD *)(&job.m_threadAffinity + 1) = 0;
          if ( *(_DWORD *)(&job.m_threadAffinity + 3) >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              *(void **)&job.m_jobSubType,
              32 * *(_DWORD *)(&job.m_threadAffinity + 3));
        }
      }
      ++v133;
      ++v134;
      v135 += 4;
      --localVel.m_quad.m128_u64[0];
    }
    while ( localVel.m_quad.m128_u64[0] );
LABEL_126:
    v93 = v187;
  }
  v142 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v143 = (_QWORD *)v142[1];
  if ( (unsigned __int64)v143 < v142[3] )
  {
    *v143 = "StsetVel";
    v144 = __rdtsc();
    v145 = (signed __int64)(v143 + 2);
    *(_DWORD *)(v145 - 8) = v144;
    v142[1] = v145;
  }
  if ( v93 > 0 )
  {
    v146 = 0i64;
    v147 = v21;
    do
    {
      v148 = &v192.m_data[v146];
      if ( v192.m_data[v146].m_enableLocalSteering.m_bool )
      {
        v149 = v147->m_quad;
        v150 = v148->m_referenceFrame;
        v151 = v148->m_character;
        _mm_store_si128((__m128i *)&localVel, (__m128i)v147[1].m_quad);
        v152 = _mm_shuffle_ps(v149, _mm_unpackhi_ps(v149, (__m128)0i64), 196);
        if ( v150 )
        {
          hkaiReferenceFrame::transformLocalPosVelToWorldVel(
            v150,
            &v148->m_currentPosition,
            &localVel,
            (hkVector4f *)&v193);
          v153 = _mm_mul_ps(v150->m_angularVelocity.m_quad, v148->m_currentUp.m_quad);
          v154 = _mm_shuffle_ps(
                   *(__m128 *)&v193.m_world,
                   _mm_unpackhi_ps(
                     *(__m128 *)&v193.m_world,
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v153, v153, 85), _mm_shuffle_ps(v153, v153, 0)),
                         _mm_shuffle_ps(v153, v153, 170)),
                       _mm_shuffle_ps(localVel.m_quad, localVel.m_quad, 255))),
                   196);
          v155 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v152, v152, 85), v150->m_transform.m_rotation.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v152, v152, 0), v150->m_transform.m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v152, v152, 170), v150->m_transform.m_rotation.m_col2.m_quad));
        }
        else
        {
          v154 = v147[1].m_quad;
          v155 = v152;
        }
        v151->m_velocity.m_quad = _mm_shuffle_ps(v154, _mm_unpackhi_ps(v154, v151->m_velocity.m_quad), 196);
        if ( v151->m_avoidanceProperties.m_pntr->m_movementProperties.m_kinematicConstraintType.m_storage == 1 )
          v151->m_forward.m_quad = v155;
        hkaiCharacter::setAvoidanceState(v151, (hkResult)(v147->m_quad.m128_i32[3] & 0xC0FFFFFF));
        v93 = v187;
      }
      ++v146;
      v147 += 4;
      v187 = --v93;
    }
    while ( v93 );
  }
  if ( v7->m_listeners.m_size )
  {
    v156 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v157 = (_QWORD *)v156[1];
    if ( (unsigned __int64)v157 < v156[3] )
    {
      *v157 = "StpostStepCallbacks";
      v158 = __rdtsc();
      v159 = (signed __int64)(v157 + 2);
      *(_DWORD *)(v159 - 8) = v158;
      v156[1] = v159;
    }
    hkaiWorld::CharacterStepCallbackContext::CharacterStepCallbackContext(
      (hkaiWorld::CharacterStepCallbackContext *)&localVel,
      CALLBACK_POSTCHARACTER_STEP,
      v7,
      v8,
      charactersa,
      0i64);
    v160 = 0;
    if ( v7->m_listeners.m_size > 0 )
    {
      v161 = 0i64;
      do
      {
        v7->m_listeners.m_data[v161]->vfptr->postCharacterStepCallback(
          v7->m_listeners.m_data[v161],
          (hkaiWorld::CharacterStepCallbackContext *)&localVel);
        ++v160;
        ++v161;
      }
      while ( v160 < v7->m_listeners.m_size );
    }
  }
  v163 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v164 = (_QWORD *)v163[1];
  if ( (unsigned __int64)v164 < v163[3] )
  {
    *v164 = "StbehaviorCallbacks";
    v165 = __rdtsc();
    v162 = (unsigned __int64)HIDWORD(v165) << 32;
    v166 = (signed __int64)(v164 + 2);
    *(_DWORD *)(v166 - 8) = v165;
    v163[1] = v166;
  }
  v167 = 0;
  if ( *(_DWORD *)(v209 + 8) > 0 )
  {
    v168 = 0i64;
    do
    {
      (*(void (__fastcall **)(_QWORD, unsigned __int64, _QWORD *))(**(_QWORD **)(v168 + *(_QWORD *)v209) + 32i64))(
        *(_QWORD *)(v168 + *(_QWORD *)v209),
        v162,
        v163);
      ++v167;
      v168 += 8i64;
    }
    while ( v167 < *(_DWORD *)(v209 + 8) );
  }
  v169 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v170 = (_QWORD *)v169[1];
  if ( (unsigned __int64)v170 < v169[3] )
  {
    *v170 = "Stcleanup";
    v171 = __rdtsc();
    v172 = (signed __int64)(v170 + 2);
    *(_DWORD *)(v172 - 8) = v171;
    v169[1] = v172;
  }
  v173 = (int)v192.m_data;
  for ( i = LODWORD(v192.m_data) - 1; i >= 0; --i )
  {
    v175 = (signed __int64)v173 << 6;
    v176 = *(int *)((char *)&v21->m_quad.m128_i32[-1] + v175);
    *(int *)((char *)&v21->m_quad.m128_i32[-2] + v175) = 0;
    if ( v176 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)((char *)v21[-1].m_quad.m128_u64 + v175),
        8 * v176);
    *(unsigned __int64 *)((char *)v21[-1].m_quad.m128_u64 + v175) = 0i64;
    *(int *)((char *)&v21->m_quad.m128_i32[-1] + v175) = 2147483648;
    v177 = *(_DWORD *)((char *)&v21[-1] + v175 - 4);
    *(_DWORD *)((char *)&v21[-1] + v175 - 8) = 0;
    if ( v177 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)((char *)v21[-2].m_quad.m128_u64 + v175),
        8 * v177);
    *(unsigned __int64 *)((char *)v21[-2].m_quad.m128_u64 + v175) = 0i64;
    *(_DWORD *)((char *)&v21[-1] + v175 - 4) = 2147483648;
    v173 = i;
  }
  v192.m_size = 0;
  if ( v192.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v192.m_data,
      160 * (v192.m_capacityAndFlags & 0x3FFFFFFF));
  v192.m_data = 0i64;
  v192.m_capacityAndFlags = 2147483648;
  v178 = v173 - 1;
  if ( v173 - 1 >= 0 )
  {
    v179 = &v21[4 * v178 + 3].m_quad.m128_i32[3];
    do
    {
      v180 = *v179;
      *(v179 - 1) = 0;
      if ( v180 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v179 - 3),
          8 * v180);
      *(_QWORD *)(v179 - 3) = 0i64;
      *v179 = 2147483648;
      v181 = *(v179 - 4);
      *(v179 - 5) = 0;
      if ( v181 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v179 - 7),
          8 * v181);
      *(_QWORD *)(v179 - 7) = 0i64;
      *(v179 - 4) = 2147483648;
      v179 -= 16;
      --v178;
    }
    while ( v178 >= 0 );
  }
  if ( v195 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v21,
      v195 << 6);
LABEL_169:
  v182 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v183 = (_QWORD *)v182[1];
  v184 = v182;
  if ( (unsigned __int64)v183 < v182[3] )
  {
    *v183 = "lt";
    v185 = __rdtsc();
    v186 = (signed __int64)(v183 + 2);
    *(_DWORD *)(v186 - 8) = v185;
    v184[1] = v186;
  }
}ontainerHeapAllocator::

// File Line: 599
// RVA: 0xBE1BF0
void __fastcall hkaiWorld::addObstacleGenerator(hkaiWorld *this, hkaiObstacleGenerator *generator)
{
  hkaiObstacleGenerator *v2; // rbx
  hkaiWorld *v3; // rdi
  hkArray<hkRefPtr<hkaiObstacleGenerator>,hkContainerHeapAllocator> *v4; // rdi
  hkaiObstacleGenerator **v5; // rsi

  v2 = generator;
  v3 = this;
  if ( generator )
    hkReferencedObject::addReference((hkReferencedObject *)&generator->vfptr);
  v4 = &v3->m_obstacleGenerators;
  if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
  v5 = &v4->m_data[v4->m_size].m_pntr;
  if ( v5 )
  {
    if ( v2 )
      hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
    *v5 = v2;
  }
  ++v4->m_size;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
}

// File Line: 604
// RVA: 0xBE1C90
void __fastcall hkaiWorld::removeObstacleGenerator(hkaiWorld *this, hkaiObstacleGenerator *generator)
{
  hkaiObstacleGenerator *v2; // rdi
  hkaiWorld *v3; // rsi
  __int64 v4; // rcx
  signed int v5; // ebx
  __int64 v6; // rdx
  hkRefPtr<hkaiObstacleGenerator> *v7; // rax
  hkRefPtr<hkaiObstacleGenerator> *v8; // rdi
  hkReferencedObject *v9; // rcx
  signed __int64 v10; // r14
  __int64 v11; // rax

  v2 = generator;
  v3 = this;
  if ( generator )
    hkReferencedObject::addReference((hkReferencedObject *)&generator->vfptr);
  v4 = v3->m_obstacleGenerators.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( v4 <= 0 )
  {
LABEL_7:
    v5 = -1;
  }
  else
  {
    v7 = v3->m_obstacleGenerators.m_data;
    while ( v7->m_pntr != v2 )
    {
      ++v6;
      ++v5;
      ++v7;
      if ( v6 >= v4 )
        goto LABEL_7;
    }
  }
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  if ( v5 >= 0 )
  {
    v8 = v3->m_obstacleGenerators.m_data;
    v9 = (hkReferencedObject *)&v8[v5].m_pntr->vfptr;
    v10 = v5;
    if ( v9 )
      hkReferencedObject::removeReference(v9);
    v8[v10].m_pntr = 0i64;
    v11 = --v3->m_obstacleGenerators.m_size;
    if ( (_DWORD)v11 != v5 )
      v3->m_obstacleGenerators.m_data[v10].m_pntr = v3->m_obstacleGenerators.m_data[v11].m_pntr;
  }
}

// File Line: 619
// RVA: 0xBE17D0
void __fastcall hkaiWorld::CharacterStepCallbackContext::CharacterStepCallbackContext(hkaiWorld::CharacterStepCallbackContext *this, hkaiWorld::CharacterCallbackType cbType, hkaiWorld *world, float timestep, hkArrayBase<hkaiCharacter *> *characters, hkArrayBase<hkaiLocalSteeringInput> *localSteeringInputs)
{
  this->m_world = world;
  this->m_callbackType.m_storage = cbType;
  this->m_timestep = timestep;
  this->m_characters = characters;
  this->m_localSteeringInputs = localSteeringInputs;
}

// File Line: 629
// RVA: 0xBE1800
void __fastcall hkaiWorld::CharacterStepSerializableContext::CharacterStepSerializableContext(hkaiWorld::CharacterStepSerializableContext *this, hkaiWorld::CharacterStepCallbackContext *cbCtx)
{
  hkaiWorld::CharacterStepCallbackContext *v2; // r15
  hkaiWorld::CharacterStepSerializableContext *v3; // r12
  hkArrayBase<hkaiLocalSteeringInput> *v4; // rax
  int v5; // ecx
  int v6; // er8
  hkaiLocalSteeringInput *v7; // rdx
  hkArray<hkRefPtr<hkaiObstacleGenerator>,hkContainerHeapAllocator> *v8; // r13
  hkArrayBase<hkaiCharacter *> *v9; // rax
  int v10; // er9
  int v11; // eax
  int v12; // eax
  hkArrayBase<hkaiCharacter *> *v13; // rax
  int v14; // ebp
  __int64 v15; // r14
  hkaiCharacter **v16; // rax
  hkReferencedObject *v17; // rbx
  _QWORD *v18; // rsi
  hkaiWorld *v19; // r15
  signed int v20; // ebx
  int v21; // eax
  __int64 v22; // rbp
  signed int v23; // er12
  int v24; // eax
  int v25; // eax
  int v26; // er9
  signed __int64 v27; // rdi
  __int64 v28; // rbx
  hkReferencedObject *v29; // rcx
  hkReferencedObject **v30; // rbx
  signed __int64 v31; // rdi
  __int64 v32; // rsi
  hkReferencedObject *v33; // rcx
  hkReferencedObject *v34; // rax
  hkReferencedObject **v35; // rbx
  __int64 v36; // rsi
  signed __int64 v37; // r14
  hkResult result; // [rsp+78h] [rbp+10h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiWorld::CharacterStepSerializableContext::`vftable';
  v2 = cbCtx;
  this->m_world = cbCtx->m_world;
  v3 = this;
  this->m_callbackType.m_storage = cbCtx->m_callbackType.m_storage;
  this->m_timestep = cbCtx->m_timestep;
  this->m_characters.m_data = 0i64;
  this->m_characters.m_size = 0;
  this->m_characters.m_capacityAndFlags = 2147483648;
  v4 = cbCtx->m_localSteeringInputs;
  if ( v4 )
    v5 = v4->m_size;
  else
    v5 = 0;
  if ( v4 )
    v6 = v4->m_size;
  else
    v6 = 0;
  if ( v4 )
    v7 = v4->m_data;
  else
    v7 = 0i64;
  v3->m_localSteeringInputs.m_data = v7;
  v3->m_localSteeringInputs.m_size = v6;
  v8 = &v3->m_obstacleGenerators;
  v3->m_localSteeringInputs.m_capacityAndFlags = v5 | 0x80000000;
  v8->m_data = 0i64;
  v8->m_size = 0;
  v8->m_capacityAndFlags = 2147483648;
  v9 = v2->m_characters;
  if ( v9 )
  {
    v10 = v9->m_size;
    v11 = v3->m_characters.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v11 < v10 )
    {
      v12 = 2 * v11;
      if ( v10 < v12 )
        v10 = v12;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_characters,
        v10,
        8);
    }
    v13 = v2->m_characters;
    v14 = 0;
    if ( v13->m_size > 0 )
    {
      v15 = 0i64;
      do
      {
        v16 = v13->m_data;
        v17 = (hkReferencedObject *)&v16[v15]->vfptr;
        if ( v17 )
          hkReferencedObject::addReference((hkReferencedObject *)&v16[v15]->vfptr);
        v18 = &v3->m_characters.m_data[v3->m_characters.m_size].m_pntr;
        if ( v18 )
        {
          if ( v17 )
            hkReferencedObject::addReference(v17);
          *v18 = v17;
        }
        ++v3->m_characters.m_size;
        if ( v17 )
          hkReferencedObject::removeReference(v17);
        v13 = v2->m_characters;
        ++v14;
        ++v15;
      }
      while ( v14 < v13->m_size );
    }
  }
  v19 = v3->m_world;
  v20 = v3->m_obstacleGenerators.m_size;
  v21 = v3->m_obstacleGenerators.m_capacityAndFlags;
  v22 = v19->m_obstacleGenerators.m_size;
  v23 = v19->m_obstacleGenerators.m_size;
  if ( (signed int)v22 > v20 )
    v23 = v20;
  v24 = v21 & 0x3FFFFFFF;
  if ( v24 < (signed int)v22 )
  {
    v25 = 2 * v24;
    v26 = v19->m_obstacleGenerators.m_size;
    if ( (signed int)v22 < v25 )
      v26 = v25;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, v26, 8);
  }
  v27 = (signed __int64)&v8->m_data[v22];
  v28 = v20 - (signed int)v22 - 1;
  if ( (signed int)v28 >= 0 )
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
  v30 = (hkReferencedObject **)v8->m_data;
  if ( v23 > 0 )
  {
    v31 = (char *)v19->m_obstacleGenerators.m_data - (char *)v30;
    v32 = v23;
    do
    {
      v33 = *(hkReferencedObject **)((char *)v30 + v31);
      if ( v33 )
        hkReferencedObject::addReference(v33);
      if ( *v30 )
        hkReferencedObject::removeReference(*v30);
      v34 = *(hkReferencedObject **)((char *)v30 + v31);
      ++v30;
      *(v30 - 1) = v34;
      --v32;
    }
    while ( v32 );
  }
  v35 = (hkReferencedObject **)&v19->m_obstacleGenerators.m_data[v23];
  v36 = (signed int)v22 - v23;
  if ( (signed int)v22 - v23 > 0 )
  {
    v37 = (char *)&v8->m_data[v23] - (char *)v35;
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
  v8->m_size = v22;
}

// File Line: 644
// RVA: 0xBE1A90
void __fastcall hkaiWorld::CharacterStepSerializableContext::CharacterStepSerializableContext(hkaiWorld::CharacterStepSerializableContext *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiWorld::CharacterStepSerializableContext::`vftable';
}

// File Line: 648
// RVA: 0xBE1AB0
void __fastcall hkaiWorld::CharacterStepSerializableContext::~CharacterStepSerializableContext(hkaiWorld::CharacterStepSerializableContext *this)
{
  hkaiWorld::CharacterStepSerializableContext *v1; // rdi
  hkRefPtr<hkaiObstacleGenerator> *v2; // rsi
  int v3; // eax
  __int64 i; // rbx
  hkReferencedObject *v5; // rcx
  int v6; // er8
  int v7; // eax
  hkRefPtr<hkaiCharacter const > *v8; // rsi
  int v9; // eax
  __int64 j; // rbx
  hkReferencedObject *v11; // rcx
  int v12; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiWorld::CharacterStepSerializableContext::`vftable';
  v2 = this->m_obstacleGenerators.m_data;
  v3 = this->m_obstacleGenerators.m_size - 1;
  for ( i = v3; i >= 0; v2[i--].m_pntr = 0i64 )
  {
    v5 = (hkReferencedObject *)&v2[i].m_pntr->vfptr;
    if ( v5 )
      hkReferencedObject::removeReference(v5);
  }
  v6 = v1->m_obstacleGenerators.m_capacityAndFlags;
  v1->m_obstacleGenerators.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_obstacleGenerators.m_data,
      8 * v6);
  v1->m_obstacleGenerators.m_data = 0i64;
  v1->m_obstacleGenerators.m_capacityAndFlags = 2147483648;
  v7 = v1->m_localSteeringInputs.m_capacityAndFlags;
  v1->m_localSteeringInputs.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_localSteeringInputs.m_data,
      160 * (v7 & 0x3FFFFFFF));
  v1->m_localSteeringInputs.m_data = 0i64;
  v1->m_localSteeringInputs.m_capacityAndFlags = 2147483648;
  v8 = v1->m_characters.m_data;
  v9 = v1->m_characters.m_size - 1;
  for ( j = v9; j >= 0; v8[j--].m_pntr = 0i64 )
  {
    v11 = (hkReferencedObject *)&v8[j].m_pntr->vfptr;
    if ( v11 )
      hkReferencedObject::removeReference(v11);
  }
  v12 = v1->m_characters.m_capacityAndFlags;
  v1->m_characters.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_characters.m_data,
      8 * v12);
  v1->m_characters.m_data = 0i64;
  v1->m_characters.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

