// File Line: 36
// RVA: 0xC0C610
void __fastcall hkaiCharacterUtil::GetFaceForPathfindingSettings::GetFaceForPathfindingSettings(
        hkaiCharacterUtil::GetFaceForPathfindingSettings *this)
{
  this->m_raycastLength = 2.0;
  this->m_aabbQuerySize = 2.0;
  this->m_resolveEdgePenetrations.m_bool = 1;
  this->m_characterRadius = 0.5;
  this->m_useCoherentQueries.m_bool = 1;
  this->m_coherencyTolerance = 0.001;
  this->m_previousFaceKey = -1;
}

// File Line: 45
// RVA: 0xC0CD30
void __fastcall hkaiCharacterUtil::ProjectToMeshSettings::ProjectToMeshSettings(
        hkaiCharacterUtil::ProjectToMeshSettings *this)
{
  this->m_meshQueryRadius = 1.0;
  this->m_meshRaycastLength = 0.25;
  this->m_meshProjectDamping = 0.75;
  this->m_useCoherentQueries.m_bool = 1;
  this->m_coherencyTolerance = 0.001;
}

// File Line: 49
// RVA: 0xC0BC80
hkaiPathfindingUtil::FindPathInput *__fastcall hkaiCharacterUtil::generatePathRequest(
        hkaiWorld *world,
        hkaiCharacter *character,
        hkVector4f *goal)
{
  return hkaiCharacterUtil::generatePathRequest(world, character, goal, 1);
}

// File Line: 54
// RVA: 0xC0BDE0
hkaiVolumePathfindingUtil::FindPathInput *__fastcall hkaiCharacterUtil::generateVolumePathRequest(
        hkaiWorld *world,
        hkaiCharacter *character,
        hkVector4f *goal)
{
  return hkaiCharacterUtil::generateVolumePathRequest(world, character, goal, 1);
}

// File Line: 59
// RVA: 0xC0BCA0
hkaiPathfindingUtil::FindPathInput *__fastcall hkaiCharacterUtil::generatePathRequest(
        hkaiWorld *world,
        hkaiCharacter *character,
        hkVector4f *goals,
        int numGoals)
{
  _QWORD **Value; // rax
  hkaiPathfindingUtil::FindPathInput *v9; // rax
  hkaiPathfindingUtil::FindPathInput *v10; // rax
  hkaiPathfindingUtil::FindPathInput *v11; // rbx
  __m128 v12; // xmm0
  __m128i v13; // xmm1
  hkVector4f v14; // xmm0

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkaiPathfindingUtil::FindPathInput *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                               Value[11],
                                               192i64);
  if ( v9 )
  {
    hkaiPathfindingUtil::FindPathInput::FindPathInput(v9, 0);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  hkaiPathfindingUtil::FindPathInput::operator=(v11, &world->m_defaultPathfindingInput);
  v11->m_agentInfo.m_diameter = fmaxf(0.0, character->m_radius - world->m_erosionRadius) * 2.0;
  v12 = _mm_mul_ps(world->m_up.m_quad, (__m128)xmmword_141A71390);
  v13 = _mm_add_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v12),
            _mm_cvttps_epi32(v12)),
          _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
  v11->m_searchParameters.m_up.m_vec[0] = _mm_extract_epi16(v13, 1);
  v11->m_searchParameters.m_up.m_vec[1] = _mm_extract_epi16(v13, 3);
  v11->m_searchParameters.m_up.m_vec[2] = _mm_extract_epi16(v13, 5);
  v11->m_agentInfo.m_filterInfo = character->m_agentFilterInfo;
  v11->m_searchParameters.m_costModifier = character->m_costModifier.m_pntr;
  v11->m_searchParameters.m_edgeFilter = character->m_edgeFilter.m_pntr;
  v14.m_quad = (__m128)character->m_position;
  v11->m_startFaceKey = -1;
  v11->m_startPoint = (hkVector4f)v14.m_quad;
  hkArrayBase<hkVector4f>::_append(&v11->m_goalPoints, &hkContainerHeapAllocator::s_alloc, goals, numGoals);
  v11->m_goalFaceKeys.m_size = 0;
  return v11;
}

// File Line: 84
// RVA: 0xC0BE00
hkaiVolumePathfindingUtil::FindPathInput *__fastcall hkaiCharacterUtil::generateVolumePathRequest(
        hkaiWorld *world,
        hkaiCharacter *character,
        hkVector4f *goals,
        int numGoals)
{
  _QWORD **Value; // rax
  hkaiVolumePathfindingUtil::FindPathInput *v9; // rax
  hkaiVolumePathfindingUtil::FindPathInput *v10; // rax
  hkaiVolumePathfindingUtil::FindPathInput *v11; // rbx
  __m128 v12; // xmm0
  __m128i v13; // xmm1
  hkVector4f v14; // xmm0

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkaiVolumePathfindingUtil::FindPathInput *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                     Value[11],
                                                     144i64);
  if ( v9 )
  {
    hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(v9, 0);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  hkaiVolumePathfindingUtil::FindPathInput::operator=(v11, &world->m_defaultVolumePathfindingInput);
  v12 = _mm_mul_ps(world->m_up.m_quad, (__m128)xmmword_141A71390);
  v13 = _mm_add_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v12),
            _mm_cvttps_epi32(v12)),
          _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
  v11->m_searchParameters.m_up.m_vec[0] = _mm_extract_epi16(v13, 1);
  v11->m_searchParameters.m_up.m_vec[1] = _mm_extract_epi16(v13, 3);
  v11->m_searchParameters.m_up.m_vec[2] = _mm_extract_epi16(v13, 5);
  v11->m_agentInfo.m_diameter = character->m_radius * 2.0;
  v11->m_agentInfo.m_filterInfo = character->m_agentFilterInfo;
  v11->m_searchParameters.m_costModifier = character->m_costModifier.m_pntr;
  v11->m_searchParameters.m_edgeFilter = character->m_edgeFilter.m_pntr;
  v14.m_quad = (__m128)character->m_position;
  v11->m_startCellKey = -1;
  v11->m_startPoint = (hkVector4f)v14.m_quad;
  hkArrayBase<hkVector4f>::_append(&v11->m_goalPoints, &hkContainerHeapAllocator::s_alloc, goals, numGoals);
  v11->m_goalCellKeys.m_size = 0;
  return v11;
}

// File Line: 112
// RVA: 0xC0C970
hkaiCharacterUtil::ProcessedPath *__fastcall hkaiCharacterUtil::processPathOutput(
        hkaiCharacterUtil::ProcessedPath *result,
        hkaiNavMeshPathRequestInfo *pathRequest,
        hkaiWorld *world,
        hkaiCharacter *character,
        hkSimdFloat32 *characterToPathStartThreshold)
{
  hkaiPathfindingUtil::FindPathOutput *m_pntr; // rbp
  hkaiCharacterUtil::ProcessedPath *v8; // rax
  hkaiPathfindingUtil::FindPathInput *v9; // r14
  char m_storage; // al
  _QWORD **Value; // rax
  __int64 v12; // rax
  hkaiPath *v13; // rsi
  hkVector4f *p_m_up; // rcx
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm5
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  unsigned int m_currentNavMeshFace; // r9d
  int v22; // r9d
  bool v23; // al
  hkVector4f n; // [rsp+30h] [rbp-28h] BYREF

  m_pntr = pathRequest->m_output.m_pntr;
  if ( m_pntr )
  {
    v9 = pathRequest->m_input.m_pntr;
    if ( v9->m_startFaceKey == -1 )
    {
      *(_QWORD *)&result->m_result = 1i64;
      v8 = result;
      result->m_path = 0i64;
    }
    else
    {
      m_storage = m_pntr->m_outputParameters.m_status.m_storage;
      if ( m_storage == 5 )
      {
        *(_QWORD *)&result->m_result = 2i64;
        v8 = result;
        result->m_path = 0i64;
      }
      else if ( m_storage == 2 )
      {
        *(_QWORD *)&result->m_result = 3i64;
        v8 = result;
        result->m_path = 0i64;
      }
      else
      {
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v12 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
        v13 = (hkaiPath *)v12;
        if ( v12 )
        {
          *(_DWORD *)(v12 + 8) = 0x1FFFF;
          *(_QWORD *)v12 = &hkaiPath::`vftable;
          *(_QWORD *)(v12 + 16) = 0i64;
          *(_DWORD *)(v12 + 24) = 0;
          *(_DWORD *)(v12 + 28) = 0x80000000;
          *(_BYTE *)(v12 + 32) = 0;
        }
        else
        {
          v13 = 0i64;
        }
        p_m_up = &character->m_up;
        v15 = _mm_sub_ps(character->m_position.m_quad, v9->m_startPoint.m_quad);
        v16 = _mm_mul_ps(character->m_up.m_quad, v15);
        v17 = _mm_sub_ps(
                v15,
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                    _mm_shuffle_ps(v16, v16, 170)),
                  character->m_up.m_quad));
        v18 = _mm_mul_ps(v17, v17);
        v19 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                _mm_shuffle_ps(v18, v18, 170));
        v20 = _mm_rsqrt_ps(v19);
        if ( _mm_andnot_ps(
               _mm_cmple_ps(v19, (__m128)0i64),
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                   _mm_mul_ps(*(__m128 *)_xmm, v20)),
                 v19)).m128_f32[0] > characterToPathStartThreshold->m_real.m128_f32[0] )
        {
          m_currentNavMeshFace = character->m_currentNavMeshFace;
          if ( m_currentNavMeshFace == -1 )
            v22 = -1;
          else
            v22 = m_currentNavMeshFace >> 22;
          if ( m_pntr->m_pathOut.m_size )
            p_m_up = &m_pntr->m_pathOut.m_data->m_normal;
          n.m_quad = p_m_up->m_quad;
          hkaiPath::addPoint(v13, &character->m_position, &n, v22, 0, 0);
        }
        hkaiPathProjectionUtil::getSimplifiedPathPoints(&m_pntr->m_pathOut, v13, 0.1, 0.99800003, 0.99800003);
        v23 = m_pntr->m_outputParameters.m_status.m_storage != 4 && m_pntr->m_outputParameters.m_goalIndex >= 0;
        result->m_path = v13;
        result->m_lastPointIsGoal = v23;
        result->m_result = CALLBACK_PATH_SUCCEEDED;
        return result;
      }
    }
  }
  else
  {
    *(_QWORD *)&result->m_result = 4i64;
    v8 = result;
    result->m_path = 0i64;
  }
  return v8;
}lse
  {
    *(_QWORD *)&result->m_result = 4i64;
    v8 = result;
    result->m_path = 0i64;
  }
  ret

// File Line: 182
// RVA: 0xC0CB90
hkaiCharacterUtil::ProcessedPath *__fastcall hkaiCharacterUtil::processPathOutput(
        hkaiCharacterUtil::ProcessedPath *result,
        hkaiNavVolumePathRequestInfo *pathRequest,
        hkaiWorld *world,
        hkaiCharacter *character)
{
  hkaiVolumePathfindingUtil::FindPathOutput *m_pntr; // rbp
  hkaiCharacterUtil::ProcessedPath *v6; // rax
  char m_storage; // al
  _QWORD **Value; // rax
  __int64 v9; // rax
  unsigned int v10; // edi
  hkaiPath *v11; // rsi
  bool v12; // sf

  m_pntr = pathRequest->m_output.m_pntr;
  if ( m_pntr )
  {
    if ( pathRequest->m_input.m_pntr->m_startCellKey == -1 )
    {
      *(_QWORD *)&result->m_result = 1i64;
      v6 = result;
      result->m_path = 0i64;
    }
    else
    {
      m_storage = m_pntr->m_outputParameters.m_status.m_storage;
      if ( m_storage == 5 )
      {
        *(_QWORD *)&result->m_result = 2i64;
        v6 = result;
        result->m_path = 0i64;
      }
      else if ( m_storage == 2 )
      {
        *(_QWORD *)&result->m_result = 3i64;
        v6 = result;
        result->m_path = 0i64;
      }
      else
      {
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v9 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
        v10 = 0;
        v11 = (hkaiPath *)v9;
        if ( v9 )
        {
          *(_DWORD *)(v9 + 8) = 0x1FFFF;
          *(_QWORD *)v9 = &hkaiPath::`vftable;
          *(_QWORD *)(v9 + 16) = 0i64;
          *(_DWORD *)(v9 + 24) = 0;
          *(_DWORD *)(v9 + 28) = 0x80000000;
          *(_BYTE *)(v9 + 32) = 0;
        }
        else
        {
          v11 = 0i64;
        }
        hkaiPathProjectionUtil::getSimplifiedPathPoints(&m_pntr->m_pathOut, v11, 0.1, 0.99800003, 0.99800003);
        v12 = m_pntr->m_outputParameters.m_goalIndex < 0;
        result->m_result = CALLBACK_PATH_SUCCEEDED;
        result->m_path = v11;
        LOBYTE(v10) = !v12;
        v6 = result;
        result->m_lastPointIsGoal = v10;
      }
    }
  }
  else
  {
    *(_QWORD *)&result->m_result = 4i64;
    v6 = result;
    result->m_path = 0i64;
  }
  return v6;
}

// File Line: 243
// RVA: 0xC0BF30
void __fastcall hkaiCharacterUtil::updatePathRequest(
        hkaiWorld *world,
        hkaiCharacter *character,
        hkaiPathfindingUtil::FindPathInput *input,
        float querySize,
        float effectiveRadiusMultiplier)
{
  float v5; // ebx
  _QWORD *Value; // r9
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkaiDynamicNavMeshQueryMediator *DynamicQueryMediator; // rax
  hkaiStreamingCollection *m_pntr; // r12
  hkaiNavMeshQueryMediator *v15; // r13
  float v16; // xmm6_4
  unsigned int FaceForPathfinding; // eax
  int m_size; // ecx
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_goalPoints; // r14
  char *v20; // r8
  int v21; // r9d
  hkVector4f *p_m_up; // rsi
  __int64 v23; // rdi
  __int64 v24; // r14
  unsigned int v25; // r15d
  int v26; // edx
  int v27; // ecx
  __m128 m_quad; // xmm0
  int v29; // r9d
  hkVector4f *v30; // r8
  _QWORD *v31; // rax
  _QWORD *v32; // rcx
  _QWORD *v33; // r8
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  hkVector4f *a; // [rsp+40h] [rbp-B8h] BYREF
  int v37; // [rsp+48h] [rbp-B0h]
  int v38; // [rsp+4Ch] [rbp-ACh]
  char *array; // [rsp+50h] [rbp-A8h] BYREF
  int numtoinsert; // [rsp+58h] [rbp-A0h]
  int v41; // [rsp+5Ch] [rbp-9Ch]
  hkVector4f up; // [rsp+60h] [rbp-98h] BYREF
  hkaiCharacterUtil::GetFaceForPathfindingSettings inputBase; // [rsp+70h] [rbp-88h] BYREF
  __int64 v44; // [rsp+90h] [rbp-68h]
  __int64 v45; // [rsp+98h] [rbp-60h]
  __int64 v46; // [rsp+A0h] [rbp-58h]
  __int64 v47; // [rsp+A8h] [rbp-50h]
  hkVector4f pointOut; // [rsp+B8h] [rbp-40h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> *retaddr; // [rsp+128h] [rbp+30h]
  hkaiPathfindingUtil::FindPathInput *v50; // [rsp+138h] [rbp+40h]
  unsigned int v51; // [rsp+148h] [rbp+50h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtutilPathReq";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  DynamicQueryMediator = hkaiWorld::getDynamicQueryMediator(world);
  m_pntr = world->m_streamingCollection.m_pntr;
  v15 = DynamicQueryMediator;
  LODWORD(retaddr) = 0;
  v16 = fmaxf(0.0, character->m_radius - world->m_erosionRadius) * v5;
  input->m_agentInfo.m_diameter = v16 * 2.0;
  if ( DynamicQueryMediator && m_pntr )
  {
    hkaiCharacterUtil::GetFaceForPathfindingSettings::GetFaceForPathfindingSettings(&inputBase);
    inputBase.m_aabbQuerySize = querySize;
    inputBase.m_raycastLength = querySize;
    inputBase.m_characterRadius = v16;
    inputBase.m_resolveEdgePenetrations.m_bool = 1;
    inputBase.m_previousFaceKey = 0;
    v44 = 0i64;
    v45 = 0i64;
    v46 = 0i64;
    v47 = 0i64;
    hkaiCharacterUtil::setupQueryInput(
      character,
      (hkaiNavMeshQueryMediator::QueryInputBase *)&inputBase.m_previousFaceKey);
    up.m_quad = (__m128)character->m_up;
    FaceForPathfinding = hkaiCharacterUtil::getFaceForPathfinding(
                           m_pntr,
                           &character->m_position,
                           &up,
                           v15,
                           (hkaiNavMeshQueryMediator::QueryInputBase *)&inputBase.m_previousFaceKey,
                           &inputBase,
                           &pointOut);
    m_size = input->m_goalPoints.m_size;
    p_m_goalPoints = &input->m_goalPoints;
    v51 = FaceForPathfinding;
    v20 = 0i64;
    array = 0i64;
    v21 = 0;
    numtoinsert = 0;
    v41 = 0x80000000;
    a = 0i64;
    v37 = 0;
    v38 = 0x80000000;
    retaddr = &input->m_goalPoints;
    if ( m_size > 0 )
    {
      p_m_up = &world->m_up;
      v23 = 0i64;
      v24 = (unsigned int)m_size;
      do
      {
        v25 = hkaiCharacterUtil::getFaceForPathfinding(
                m_pntr,
                &retaddr->m_data[v23],
                p_m_up,
                v15,
                (hkaiNavMeshQueryMediator::QueryInputBase *)&inputBase.m_previousFaceKey,
                &inputBase,
                &up);
        if ( v25 != -1 )
        {
          v26 = numtoinsert;
          if ( numtoinsert == (v41 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 4);
            v26 = numtoinsert;
          }
          *(_DWORD *)&array[4 * v26] = v25;
          v27 = v37;
          ++numtoinsert;
          if ( v37 == (v38 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &a, 16);
            v27 = v37;
          }
          a[v27] = (hkVector4f)up.m_quad;
          ++v37;
        }
        ++v23;
        --v24;
      }
      while ( v24 );
      v21 = numtoinsert;
      v20 = array;
      input = v50;
      p_m_goalPoints = retaddr;
      FaceForPathfinding = v51;
    }
    m_quad = pointOut.m_quad;
    input->m_startFaceKey = FaceForPathfinding;
    input->m_goalFaceKeys.m_size = 0;
    input->m_startPoint.m_quad = m_quad;
    hkArrayBase<unsigned int>::_append(&input->m_goalFaceKeys, &hkContainerHeapAllocator::s_alloc, v20, v21);
    v29 = v37;
    v30 = a;
    input->m_goalPoints.m_size = 0;
    hkArrayBase<hkVector4f>::_append(p_m_goalPoints, &hkContainerHeapAllocator::s_alloc, v30, v29);
    v37 = 0;
    if ( v38 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, a, 16 * v38);
    a = 0i64;
    v38 = 0x80000000;
    numtoinsert = 0;
    if ( v41 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v41);
    array = 0i64;
    v41 = 0x80000000;
  }
  else
  {
    input->m_goalFaceKeys.m_size = 0;
    input->m_goalPoints.m_size = 0;
  }
  v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v32 = (_QWORD *)v31[1];
  v33 = v31;
  if ( (unsigned __int64)v32 < v31[3] )
  {
    *v32 = "Et";
    v34 = __rdtsc();
    v35 = v32 + 2;
    *((_DWORD *)v35 - 2) = v34;
    v33[1] = v35;
  }
}

// File Line: 306
// RVA: 0xC0C650
hkaiReferenceFrame *__fastcall hkaiCharacterUtil::getCharacterReferenceFrame(
        hkaiCharacter *character,
        hkaiWorld *world)
{
  unsigned int m_currentNavMeshFace; // eax
  hkaiNavMeshInstance *m_instancePtr; // rax

  m_currentNavMeshFace = character->m_currentNavMeshFace;
  if ( m_currentNavMeshFace == -1 )
    return 0i64;
  m_instancePtr = world->m_streamingCollection.m_pntr->m_instances.m_data[m_currentNavMeshFace >> 22].m_instancePtr;
  if ( !m_instancePtr )
    return 0i64;
  else
    return &m_instancePtr->m_referenceFrame;
}

// File Line: 325
// RVA: 0xC0C690
__int64 __fastcall hkaiCharacterUtil::getFaceForPathfinding(
        hkaiStreamingCollection *collection,
        hkVector4f *point,
        hkVector4f *up,
        hkaiNavMeshQueryMediator *mediator,
        hkaiNavMeshQueryMediator::QueryInputBase *inputBase,
        hkaiCharacterUtil::GetFaceForPathfindingSettings *settings,
        hkVector4f *pointOut)
{
  _QWORD *Value; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r9
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  __m128 m_quad; // xmm0
  char m_bool; // cl
  __m128 m_coherencyTolerance_low; // xmm0
  hkSimdFloat32 v19; // xmm2
  __int128 v20; // xmm1
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  char v23; // al
  unsigned int m_hitFaceKey; // edi
  hkVector4f v25; // xmm1
  bool v26; // zf
  __int128 v27; // xmm0
  __int128 v28; // xmm1
  __m128 v29; // xmm1
  __m128 m_aabbQuerySize_low; // xmm0
  unsigned int ClosestPoint; // eax
  __m128 m_characterRadius_low; // xmm0
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  _QWORD *v36; // rcx
  hkVector4f closestPointOut; // [rsp+30h] [rbp-D0h] BYREF
  hkaiNavMeshQueryMediator::HitDetails hitOut; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f v40; // [rsp+60h] [rbp-A0h] BYREF
  hkaiNavMeshQueryMediator::CoherentInput cinput; // [rsp+70h] [rbp-90h] BYREF
  hkaiNavMeshQueryMediator::BidirectionalRaycastInput input; // [rsp+C0h] [rbp-40h] BYREF
  hkaiNavMeshQueryMediator::GetClosestPointInput v43; // [rsp+110h] [rbp+10h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)Value[1];
  v13 = Value;
  if ( (unsigned __int64)v12 < Value[3] )
  {
    *v12 = "TtgetFaceForPath";
    v14 = __rdtsc();
    v15 = v12 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v13[1] = v15;
  }
  m_quad = point->m_quad;
  cinput.m_previousFaceKey = -1;
  m_bool = settings->m_useCoherentQueries.m_bool;
  cinput.m_previousPoint = (hkVector4f)xmmword_141A712A0;
  cinput.m_up = (hkVector4f)xmmword_141A712A0;
  closestPointOut.m_quad = m_quad;
  cinput.m_isOnFaceTolerance.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  cinput.m_coherencyTolerance.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0);
  if ( m_bool )
  {
    m_coherencyTolerance_low = (__m128)LODWORD(settings->m_coherencyTolerance);
    cinput.m_previousFaceKey = settings->m_previousFaceKey;
    cinput.m_isOnFaceTolerance.m_real = _mm_shuffle_ps(m_coherencyTolerance_low, m_coherencyTolerance_low, 0);
    cinput.m_up = (hkVector4f)up->m_quad;
    cinput.m_previousPoint = (hkVector4f)point->m_quad;
  }
  v19.m_real = _mm_shuffle_ps((__m128)LODWORD(settings->m_raycastLength), (__m128)LODWORD(settings->m_raycastLength), 0);
  v20 = *(_OWORD *)&inputBase->m_hitFilter;
  *(_OWORD *)&input.m_filterInfo = *(_OWORD *)&inputBase->m_filterInfo;
  *(_OWORD *)&input.m_hitFilter = v20;
  v21 = point->m_quad;
  input.m_localToWorldTransform = inputBase->m_localToWorldTransform;
  v22 = up->m_quad;
  input.m_center.m_quad = v21;
  input.m_forwardTo.m_quad = _mm_add_ps(_mm_mul_ps(v22, v19.m_real), v21);
  if ( m_bool )
  {
    cinput.m_coherencyTolerance = (hkSimdFloat32)v19.m_real;
    v23 = hkaiNavMeshQueryMediator::coherentCastBidirectionalRay(mediator, collection, &input, &cinput, &hitOut);
  }
  else
  {
    v23 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, hkaiNavMeshQueryMediator::BidirectionalRaycastInput *, hkaiNavMeshQueryMediator::HitDetails *, _QWORD *))mediator->vfptr[3].__vecDelDtor)(
            mediator,
            &input,
            &hitOut,
            v13);
  }
  if ( !v23
    || (m_hitFaceKey = hitOut.m_hitFaceKey,
        v25.m_quad = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_sub_ps(input.m_forwardTo.m_quad, input.m_center.m_quad),
                         hitOut.m_hitFraction.m_real),
                       input.m_center.m_quad),
        closestPointOut.m_quad = v25.m_quad,
        hitOut.m_hitFaceKey == -1) )
  {
    v26 = settings->m_useCoherentQueries.m_bool == 0;
    v27 = *(_OWORD *)&inputBase->m_filterInfo;
    v28 = *(_OWORD *)&inputBase->m_hitFilter;
    v43.m_navMeshCutter = 0i64;
    *(_OWORD *)&v43.m_filterInfo = v27;
    *(_OWORD *)&v43.m_hitFilter = v28;
    v29 = point->m_quad;
    v43.m_localToWorldTransform = inputBase->m_localToWorldTransform;
    m_aabbQuerySize_low = (__m128)LODWORD(settings->m_aabbQuerySize);
    v43.m_position.m_quad = v29;
    v43.m_queryRadius.m_real = _mm_shuffle_ps(m_aabbQuerySize_low, m_aabbQuerySize_low, 0);
    if ( v26 )
    {
      ClosestPoint = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, hkaiNavMeshQueryMediator::GetClosestPointInput *, hkVector4f *))mediator->vfptr[1].__first_virtual_table_function__)(
                       mediator,
                       &v43,
                       &closestPointOut);
    }
    else
    {
      cinput.m_coherencyTolerance.m_real = _mm_shuffle_ps(
                                             (__m128)LODWORD(settings->m_coherencyTolerance),
                                             (__m128)LODWORD(settings->m_coherencyTolerance),
                                             0);
      ClosestPoint = hkaiNavMeshQueryMediator::coherentGetClosestPoint(
                       mediator,
                       collection,
                       &v43,
                       &cinput,
                       &closestPointOut);
    }
    v25.m_quad = closestPointOut.m_quad;
    m_hitFaceKey = ClosestPoint;
  }
  if ( !settings->m_resolveEdgePenetrations.m_bool
    || m_hitFaceKey == -1
    || (m_characterRadius_low = (__m128)LODWORD(settings->m_characterRadius),
        m_characterRadius_low.m128_f32[0] <= 0.00000011920929) )
  {
    *pointOut = (hkVector4f)v25.m_quad;
  }
  else
  {
    v40.m_quad = v25.m_quad;
    hitOut.m_hitFraction.m_real = _mm_shuffle_ps(m_characterRadius_low, m_characterRadius_low, 0);
    hkaiNavMeshUtils::resolveEdgePenetrations(collection, mediator, &closestPointOut, &hitOut.m_hitFraction, &v40);
    *pointOut = (hkVector4f)v40.m_quad;
  }
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "Et";
    v35 = __rdtsc();
    v36 = v34 + 2;
    *((_DWORD *)v36 - 2) = v35;
    v33[1] = v36;
  }
  return m_hitFaceKey;
}

// File Line: 400
// RVA: 0xC0C310
void __fastcall hkaiCharacterUtil::updatePathRequest(
        hkaiWorld *world,
        hkaiCharacter *character,
        hkaiVolumePathfindingUtil::FindPathInput *input,
        float querySize)
{
  _QWORD *Value; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r9
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkaiDynamicNavVolumeMediator *DynamicNavVolumeMediator; // r15
  __m128 v13; // xmm0
  unsigned int v14; // eax
  __int64 m_size; // r14
  char *v16; // r8
  __int64 v17; // r9
  __int64 v18; // rdi
  int v19; // esi
  int v20; // edx
  int v21; // ecx
  hkVector4f v22; // xmm0
  int v23; // r9d
  hkVector4f *v24; // r8
  _QWORD *v25; // rax
  _QWORD *v26; // rcx
  _QWORD *v27; // r8
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  char *array; // [rsp+18h] [rbp-79h] BYREF
  int numtoinsert; // [rsp+20h] [rbp-71h]
  int v32; // [rsp+24h] [rbp-6Dh]
  hkVector4f *a; // [rsp+28h] [rbp-69h] BYREF
  int v34; // [rsp+30h] [rbp-61h]
  int v35; // [rsp+34h] [rbp-5Dh]
  unsigned int v36; // [rsp+38h] [rbp-59h]
  hkVector4f v37; // [rsp+48h] [rbp-49h] BYREF
  __m128 v38; // [rsp+58h] [rbp-39h] BYREF
  hkaiNavVolumeMediator::GetClosestPointInput gcpInput; // [rsp+68h] [rbp-29h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  v9 = Value;
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "TtutilPathReq";
    v10 = __rdtsc();
    v11 = v8 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v9[1] = v11;
  }
  DynamicNavVolumeMediator = hkaiWorld::getDynamicNavVolumeMediator(world);
  if ( DynamicNavVolumeMediator )
  {
    v13 = 0i64;
    gcpInput.m_filterInfo = 0;
    gcpInput.m_position = (hkVector4f)xmmword_141A712A0;
    memset(&gcpInput.m_userData, 0, 32);
    hkaiCharacterUtil::setupGetClosestPointInput(character, &gcpInput);
    v13.m128_f32[0] = querySize;
    gcpInput.m_queryRadius.m_real = _mm_shuffle_ps(v13, v13, 0);
    v14 = ((__int64 (__fastcall *)(hkaiDynamicNavVolumeMediator *, hkaiNavVolumeMediator::GetClosestPointInput *, __m128 *))DynamicNavVolumeMediator->vfptr[1].__first_virtual_table_function__)(
            DynamicNavVolumeMediator,
            &gcpInput,
            &v38);
    m_size = input->m_goalPoints.m_size;
    v16 = 0i64;
    array = 0i64;
    v17 = 0i64;
    numtoinsert = 0;
    v36 = v14;
    v32 = 0x80000000;
    a = 0i64;
    v34 = 0;
    v35 = 0x80000000;
    if ( m_size > 0 )
    {
      v18 = 0i64;
      do
      {
        gcpInput.m_position = input->m_goalPoints.m_data[v18];
        v19 = ((__int64 (__fastcall *)(hkaiDynamicNavVolumeMediator *, hkaiNavVolumeMediator::GetClosestPointInput *, hkVector4f *, __int64))DynamicNavVolumeMediator->vfptr[1].__first_virtual_table_function__)(
                DynamicNavVolumeMediator,
                &gcpInput,
                &v37,
                v17);
        if ( v19 != -1 )
        {
          v20 = numtoinsert;
          if ( numtoinsert == (v32 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 4);
            v20 = numtoinsert;
          }
          *(_DWORD *)&array[4 * v20] = v19;
          v21 = v34;
          ++numtoinsert;
          if ( v34 == (v35 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &a, 16);
            v21 = v34;
          }
          a[v21] = (hkVector4f)v37.m_quad;
          ++v34;
        }
        ++v18;
        --m_size;
      }
      while ( m_size );
      LODWORD(v17) = numtoinsert;
      v16 = array;
      v14 = v36;
    }
    v22.m_quad = v38;
    input->m_startCellKey = v14;
    input->m_goalCellKeys.m_size = 0;
    input->m_startPoint = (hkVector4f)v22.m_quad;
    hkArrayBase<unsigned int>::_append(&input->m_goalCellKeys, &hkContainerHeapAllocator::s_alloc, v16, v17);
    v23 = v34;
    v24 = a;
    input->m_goalPoints.m_size = 0;
    hkArrayBase<hkVector4f>::_append(&input->m_goalPoints, &hkContainerHeapAllocator::s_alloc, v24, v23);
    v34 = 0;
    if ( v35 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, a, 16 * v35);
    a = 0i64;
    v35 = 0x80000000;
    numtoinsert = 0;
    if ( v32 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v32);
    array = 0i64;
    v32 = 0x80000000;
  }
  else
  {
    input->m_goalCellKeys.m_size = 0;
    input->m_goalPoints.m_size = 0;
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  v27 = v25;
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v28 = __rdtsc();
    v29 = v26 + 2;
    *((_DWORD *)v29 - 2) = v28;
    v27[1] = v29;
  }
}

// File Line: 451
// RVA: 0xC0CCF0
void __fastcall hkaiCharacterUtil::integrateMotion(float timestep, hkaiCharacter *const *characters, int numCharacters)
{
  __m128 v3; // xmm1
  __int64 v4; // rcx
  __m128 v5; // xmm1
  hkaiCharacter *v6; // rax

  v4 = 0i64;
  if ( numCharacters > 0 )
  {
    v3.m128_f32[0] = timestep;
    v5 = _mm_shuffle_ps(v3, v3, 0);
    do
    {
      v6 = characters[v4++];
      v6->m_position.m_quad = _mm_add_ps(_mm_mul_ps(v6->m_velocity.m_quad, v5), v6->m_position.m_quad);
    }
    while ( v4 < numCharacters );
  }
}

// File Line: 478
// RVA: 0xC0CD60
void __fastcall hkaiCharacterUtil::integrateMotionAndProjectToMesh(
        float timestep,
        hkaiWorld *world,
        hkaiCharacter *const *characters,
        int numCharacters,
        hkaiCharacterUtil::ProjectToMeshSettings *settings)
{
  __m128 v5; // xmm7
  __int64 v7; // r14
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  hkaiStreamingCollection *m_pntr; // r12
  hkaiDynamicNavMeshQueryMediator *DynamicQueryMediator; // r13
  char v16; // cl
  float v17; // xmm1_4
  __int64 v18; // rsi
  __m128 v19; // xmm7
  hkaiCharacter *v20; // rbx
  __m128 v21; // xmm6
  __m128 v22; // xmm6
  unsigned int m_currentNavMeshFace; // eax
  _QWORD *v24; // rax
  _QWORD *v25; // rcx
  _QWORD *v26; // r8
  unsigned __int64 v27; // rax
  _QWORD *v28; // rcx
  hkVector4f pointOut; // [rsp+38h] [rbp-71h] BYREF
  hkVector4f up; // [rsp+48h] [rbp-61h] BYREF
  hkVector4f point; // [rsp+58h] [rbp-51h] BYREF
  hkaiCharacterUtil::GetFaceForPathfindingSettings v32; // [rsp+68h] [rbp-41h] BYREF
  hkaiNavMeshQueryMediator::QueryInputBase input; // [rsp+88h] [rbp-21h] BYREF
  __m128 v34; // [rsp+C0h] [rbp+17h]
  __int64 v35; // [rsp+128h] [rbp+7Fh]

  v7 = numCharacters;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtintegrateMotionAndProjectToMesh";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  m_pntr = world->m_streamingCollection.m_pntr;
  DynamicQueryMediator = hkaiWorld::getDynamicQueryMediator(world);
  hkaiCharacterUtil::GetFaceForPathfindingSettings::GetFaceForPathfindingSettings(&v32);
  v16 = *(_BYTE *)(v35 + 12);
  v32.m_resolveEdgePenetrations.m_bool = 0;
  v17 = *(float *)(v35 + 4);
  v32.m_aabbQuerySize = *(float *)v35;
  v32.m_raycastLength = v17;
  v18 = 0i64;
  v32.m_useCoherentQueries.m_bool = v16;
  v32.m_characterRadius = 0.0;
  v32.m_coherencyTolerance = *(float *)(v35 + 16);
  if ( v7 > 0 )
  {
    v34 = v5;
    v5.m128_f32[0] = timestep;
    v19 = _mm_shuffle_ps(v5, v5, 0);
    do
    {
      v20 = characters[v18];
      input.m_filterInfo = 0;
      memset(&input.m_userData, 0, 32);
      v21 = _mm_mul_ps(v20->m_velocity.m_quad, v19);
      up.m_quad = (__m128)v20->m_up;
      v22 = _mm_add_ps(v21, v20->m_position.m_quad);
      point.m_quad = v22;
      hkaiCharacterUtil::setupQueryInput(v20, &input);
      m_currentNavMeshFace = v20->m_currentNavMeshFace;
      pointOut.m_quad = v22;
      v32.m_previousFaceKey = m_currentNavMeshFace;
      hkaiCharacterUtil::getFaceForPathfinding(m_pntr, &point, &up, DynamicQueryMediator, &input, &v32, &pointOut);
      ++v18;
      v20->m_position.m_quad = _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps(pointOut.m_quad, v22),
                                   _mm_shuffle_ps(
                                     (__m128)*(unsigned int *)(v35 + 8),
                                     (__m128)*(unsigned int *)(v35 + 8),
                                     0)),
                                 v22);
    }
    while ( v18 < v7 );
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  v26 = v24;
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "Et";
    v27 = __rdtsc();
    v28 = v25 + 2;
    *((_DWORD *)v28 - 2) = v27;
    v26[1] = v28;
  }
}

// File Line: 518
// RVA: 0xC0BBF0
void __fastcall hkaiCharacterUtil::setupQueryInput(
        hkaiCharacter *character,
        hkaiNavMeshQueryMediator::QueryInputBase *input)
{
  input->m_filterInfo = character->m_agentFilterInfo;
  input->m_userData = character->m_userData;
  input->m_hitFilter = character->m_hitFilter.m_pntr;
}

// File Line: 525
// RVA: 0xC0BC20
void __fastcall hkaiCharacterUtil::setupGetClosestPointInput(
        hkaiCharacter *character,
        hkaiNavMeshQueryMediator::GetClosestPointInput *gcpInput)
{
  hkaiCharacterUtil::setupQueryInput(character, gcpInput);
  gcpInput->m_position = character->m_position;
}

// File Line: 531
// RVA: 0xC0BC50
void __fastcall hkaiCharacterUtil::setupGetClosestPointInput(
        hkaiCharacter *character,
        hkaiNavVolumeMediator::GetClosestPointInput *gcpInput)
{
  gcpInput->m_filterInfo = character->m_agentFilterInfo;
  gcpInput->m_userData = character->m_userData;
  gcpInput->m_hitFilter = character->m_hitFilter.m_pntr;
  gcpInput->m_position = character->m_position;
}

