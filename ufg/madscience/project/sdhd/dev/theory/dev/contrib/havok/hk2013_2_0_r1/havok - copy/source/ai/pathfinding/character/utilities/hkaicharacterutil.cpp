// File Line: 36
// RVA: 0xC0C610
void __fastcall hkaiCharacterUtil::GetFaceForPathfindingSettings::GetFaceForPathfindingSettings(hkaiCharacterUtil::GetFaceForPathfindingSettings *this)
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
void __fastcall hkaiCharacterUtil::ProjectToMeshSettings::ProjectToMeshSettings(hkaiCharacterUtil::ProjectToMeshSettings *this)
{
  this->m_meshQueryRadius = 1.0;
  this->m_meshRaycastLength = 0.25;
  this->m_meshProjectDamping = 0.75;
  this->m_useCoherentQueries.m_bool = 1;
  this->m_coherencyTolerance = 0.001;
}

// File Line: 49
// RVA: 0xC0BC80
hkaiPathfindingUtil::FindPathInput *__fastcall hkaiCharacterUtil::generatePathRequest(hkaiWorld *world, hkaiCharacter *character, hkVector4f *goal)
{
  return hkaiCharacterUtil::generatePathRequest(world, character, goal, 1);
}

// File Line: 54
// RVA: 0xC0BDE0
hkaiVolumePathfindingUtil::FindPathInput *__fastcall hkaiCharacterUtil::generateVolumePathRequest(hkaiWorld *world, hkaiCharacter *character, hkVector4f *goal)
{
  return hkaiCharacterUtil::generateVolumePathRequest(world, character, goal, 1);
}

// File Line: 59
// RVA: 0xC0BCA0
hkaiPathfindingUtil::FindPathInput *__fastcall hkaiCharacterUtil::generatePathRequest(hkaiWorld *world, hkaiCharacter *character, hkVector4f *goals, int numGoals)
{
  hkaiWorld *v4; // rsi
  int v5; // ebp
  hkVector4f *v6; // r14
  hkaiCharacter *v7; // rdi
  _QWORD **v8; // rax
  hkaiPathfindingUtil::FindPathInput *v9; // rax
  hkaiPathfindingUtil::FindPathInput *v10; // rax
  hkaiPathfindingUtil::FindPathInput *v11; // rbx
  __m128 v12; // xmm0
  __m128i v13; // xmm1
  hkVector4f v14; // xmm0

  v4 = world;
  v5 = numGoals;
  v6 = goals;
  v7 = character;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkaiPathfindingUtil::FindPathInput *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(
                                               v8[11],
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
  hkaiPathfindingUtil::FindPathInput::operator=(v11, &v4->m_defaultPathfindingInput);
  v11->m_agentInfo.m_diameter = fmaxf(0.0, v7->m_radius - v4->m_erosionRadius) * 2.0;
  v12 = _mm_mul_ps(v4->m_up.m_quad, (__m128)xmmword_141A71390);
  v13 = _mm_add_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v12),
            _mm_cvttps_epi32(v12)),
          _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
  v11->m_searchParameters.m_up.m_vec[0] = _mm_extract_epi16(v13, 1);
  v11->m_searchParameters.m_up.m_vec[1] = _mm_extract_epi16(v13, 3);
  v11->m_searchParameters.m_up.m_vec[2] = _mm_extract_epi16(v13, 5);
  v11->m_agentInfo.m_filterInfo = v7->m_agentFilterInfo;
  v11->m_searchParameters.m_costModifier = v7->m_costModifier.m_pntr;
  v11->m_searchParameters.m_edgeFilter = v7->m_edgeFilter.m_pntr;
  v14.m_quad = (__m128)v7->m_position;
  v11->m_startFaceKey = -1;
  v11->m_startPoint = (hkVector4f)v14.m_quad;
  hkArrayBase<hkVector4f>::_append(
    (hkArrayBase<hkVector4f> *)&v11->m_goalPoints.m_data,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v6,
    v5);
  v11->m_goalFaceKeys.m_size = 0;
  return v11;
}

// File Line: 84
// RVA: 0xC0BE00
hkaiVolumePathfindingUtil::FindPathInput *__fastcall hkaiCharacterUtil::generateVolumePathRequest(hkaiWorld *world, hkaiCharacter *character, hkVector4f *goals, int numGoals)
{
  hkaiWorld *v4; // rsi
  int v5; // ebp
  hkVector4f *v6; // r14
  hkaiCharacter *v7; // rdi
  _QWORD **v8; // rax
  hkaiVolumePathfindingUtil::FindPathInput *v9; // rax
  hkaiVolumePathfindingUtil::FindPathInput *v10; // rax
  hkaiVolumePathfindingUtil::FindPathInput *v11; // rbx
  __m128 v12; // xmm0
  __m128i v13; // xmm1
  hkVector4f v14; // xmm0

  v4 = world;
  v5 = numGoals;
  v6 = goals;
  v7 = character;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkaiVolumePathfindingUtil::FindPathInput *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(
                                                     v8[11],
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
  hkaiVolumePathfindingUtil::FindPathInput::operator=(v11, &v4->m_defaultVolumePathfindingInput);
  v12 = _mm_mul_ps(v4->m_up.m_quad, (__m128)xmmword_141A71390);
  v13 = _mm_add_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v12),
            _mm_cvttps_epi32(v12)),
          _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
  v11->m_searchParameters.m_up.m_vec[0] = _mm_extract_epi16(v13, 1);
  v11->m_searchParameters.m_up.m_vec[1] = _mm_extract_epi16(v13, 3);
  v11->m_searchParameters.m_up.m_vec[2] = _mm_extract_epi16(v13, 5);
  v11->m_agentInfo.m_diameter = v7->m_radius * 2.0;
  v11->m_agentInfo.m_filterInfo = v7->m_agentFilterInfo;
  v11->m_searchParameters.m_costModifier = v7->m_costModifier.m_pntr;
  v11->m_searchParameters.m_edgeFilter = v7->m_edgeFilter.m_pntr;
  v14.m_quad = (__m128)v7->m_position;
  v11->m_startCellKey = -1;
  v11->m_startPoint = (hkVector4f)v14.m_quad;
  hkArrayBase<hkVector4f>::_append(
    (hkArrayBase<hkVector4f> *)&v11->m_goalPoints.m_data,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v6,
    v5);
  v11->m_goalCellKeys.m_size = 0;
  return v11;
}

// File Line: 112
// RVA: 0xC0C970
hkaiCharacterUtil::ProcessedPath *__fastcall hkaiCharacterUtil::processPathOutput(hkaiCharacterUtil::ProcessedPath *result, hkaiNavMeshPathRequestInfo *pathRequest, hkaiWorld *world, hkaiCharacter *character, hkSimdFloat32 *characterToPathStartThreshold)
{
  hkaiPathfindingUtil::FindPathOutput *v5; // rbp
  hkaiCharacter *v6; // r15
  hkaiCharacterUtil::ProcessedPath *v7; // rbx
  hkaiCharacterUtil::ProcessedPath *v8; // rax
  hkaiPathfindingUtil::FindPathInput *v9; // r14
  char v10; // al
  _QWORD **v11; // rax
  __int64 v12; // rax
  hkaiPath *v13; // rsi
  __m128i *v14; // rcx
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm5
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  unsigned int v21; // er9
  int v22; // er9
  bool v23; // al
  hkVector4f n; // [rsp+30h] [rbp-28h]

  v5 = pathRequest->m_output.m_pntr;
  v6 = character;
  v7 = result;
  if ( v5 )
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
      v10 = v5->m_outputParameters.m_status.m_storage;
      if ( v10 == 5 )
      {
        *(_QWORD *)&result->m_result = 2i64;
        v8 = result;
        result->m_path = 0i64;
      }
      else if ( v10 == 2 )
      {
        *(_QWORD *)&result->m_result = 3i64;
        v8 = result;
        result->m_path = 0i64;
      }
      else
      {
        v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v12 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(v11[11], 40i64);
        v13 = (hkaiPath *)v12;
        if ( v12 )
        {
          *(_DWORD *)(v12 + 8) = 0x1FFFF;
          *(_QWORD *)v12 = &hkaiPath::`vftable;
          *(_QWORD *)(v12 + 16) = 0i64;
          *(_DWORD *)(v12 + 24) = 0;
          *(_DWORD *)(v12 + 28) = 2147483648;
          *(_BYTE *)(v12 + 32) = 0;
        }
        else
        {
          v13 = 0i64;
        }
        v14 = (__m128i *)&v6->m_up;
        v15 = _mm_sub_ps(v6->m_position.m_quad, v9->m_startPoint.m_quad);
        v16 = _mm_mul_ps(v6->m_up.m_quad, v15);
        v17 = _mm_sub_ps(
                v15,
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                    _mm_shuffle_ps(v16, v16, 170)),
                  v6->m_up.m_quad));
        v18 = _mm_mul_ps(v17, v17);
        v19 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                _mm_shuffle_ps(v18, v18, 170));
        v20 = _mm_rsqrt_ps(v19);
        if ( COERCE_FLOAT(
               _mm_andnot_ps(
                 _mm_cmpleps(v19, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                     _mm_mul_ps(*(__m128 *)_xmm, v20)),
                   v19))) > characterToPathStartThreshold->m_real.m128_f32[0] )
        {
          v21 = v6->m_currentNavMeshFace;
          if ( v21 == -1 )
            v22 = -1;
          else
            v22 = v21 >> 22;
          if ( v5->m_pathOut.m_size )
            v14 = (__m128i *)&v5->m_pathOut.m_data->m_normal;
          _mm_store_si128((__m128i *)&n, *v14);
          hkaiPath::addPoint(v13, &v6->m_position, &n, v22, 0, 0);
        }
        hkaiPathProjectionUtil::getSimplifiedPathPoints(&v5->m_pathOut, v13, 0.1, 0.99800003, 0.99800003);
        v23 = v5->m_outputParameters.m_status.m_storage != 4 && v5->m_outputParameters.m_goalIndex >= 0;
        v7->m_path = v13;
        v7->m_lastPointIsGoal = v23;
        v7->m_result = 0;
        v8 = v7;
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
}

// File Line: 182
// RVA: 0xC0CB90
hkaiCharacterUtil::ProcessedPath *__fastcall hkaiCharacterUtil::processPathOutput(hkaiCharacterUtil::ProcessedPath *result, hkaiNavVolumePathRequestInfo *pathRequest, hkaiWorld *world, hkaiCharacter *character)
{
  hkaiVolumePathfindingUtil::FindPathOutput *v4; // rbp
  hkaiCharacterUtil::ProcessedPath *v5; // rbx
  hkaiCharacterUtil::ProcessedPath *v6; // rax
  char v7; // al
  _QWORD **v8; // rax
  __int64 v9; // rax
  unsigned int v10; // edi
  hkaiPath *v11; // rsi
  bool v12; // sf

  v4 = pathRequest->m_output.m_pntr;
  v5 = result;
  if ( v4 )
  {
    if ( pathRequest->m_input.m_pntr->m_startCellKey == -1 )
    {
      *(_QWORD *)&result->m_result = 1i64;
      v6 = result;
      result->m_path = 0i64;
    }
    else
    {
      v7 = v4->m_outputParameters.m_status.m_storage;
      if ( v7 == 5 )
      {
        *(_QWORD *)&result->m_result = 2i64;
        v6 = result;
        result->m_path = 0i64;
      }
      else if ( v7 == 2 )
      {
        *(_QWORD *)&result->m_result = 3i64;
        v6 = result;
        result->m_path = 0i64;
      }
      else
      {
        v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v9 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 40i64);
        v10 = 0;
        v11 = (hkaiPath *)v9;
        if ( v9 )
        {
          *(_DWORD *)(v9 + 8) = 0x1FFFF;
          *(_QWORD *)v9 = &hkaiPath::`vftable;
          *(_QWORD *)(v9 + 16) = 0i64;
          *(_DWORD *)(v9 + 24) = 0;
          *(_DWORD *)(v9 + 28) = 2147483648;
          *(_BYTE *)(v9 + 32) = 0;
        }
        else
        {
          v11 = 0i64;
        }
        hkaiPathProjectionUtil::getSimplifiedPathPoints(&v4->m_pathOut, v11, 0.1, 0.99800003, 0.99800003);
        v12 = v4->m_outputParameters.m_goalIndex < 0;
        v5->m_result = 0;
        v5->m_path = v11;
        LOBYTE(v10) = !v12;
        v6 = v5;
        v5->m_lastPointIsGoal = v10;
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
void __usercall hkaiCharacterUtil::updatePathRequest(hkaiWorld *world@<rcx>, hkaiCharacter *character@<rdx>, hkaiPathfindingUtil::FindPathInput *input@<r8>, float querySize@<xmm3>, float a5@<ebx>, float effectiveRadiusMultiplier)
{
  hkaiWorld *v6; // rdi
  hkaiPathfindingUtil::FindPathInput *v7; // rsi
  hkaiCharacter *v8; // r14
  _QWORD *v9; // r9
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkaiDynamicNavMeshQueryMediator *v13; // rax
  hkaiStreamingCollection *v14; // r12
  hkaiNavMeshQueryMediator *v15; // r13
  float v16; // xmm6_4
  unsigned int v17; // eax
  int v18; // ecx
  hkArrayBase<hkVector4f> *v19; // r14
  const unsigned int *v20; // r8
  int v21; // er9
  hkVector4f *v22; // rsi
  __int64 v23; // rdi
  __int64 v24; // r14
  unsigned int v25; // er15
  int v26; // edx
  int v27; // ecx
  __m128 v28; // xmm0
  int v29; // er9
  hkVector4f *v30; // r8
  _QWORD *v31; // rax
  _QWORD *v32; // rcx
  _QWORD *v33; // r8
  unsigned __int64 v34; // rax
  signed __int64 v35; // rcx
  hkVector4f *a; // [rsp+40h] [rbp-B8h]
  int v37; // [rsp+48h] [rbp-B0h]
  int v38; // [rsp+4Ch] [rbp-ACh]
  unsigned int *array; // [rsp+50h] [rbp-A8h]
  int numtoinsert; // [rsp+58h] [rbp-A0h]
  int v41; // [rsp+5Ch] [rbp-9Ch]
  hkVector4f up; // [rsp+60h] [rbp-98h]
  hkaiCharacterUtil::GetFaceForPathfindingSettings inputBase; // [rsp+70h] [rbp-88h]
  __int64 v44; // [rsp+90h] [rbp-68h]
  __int64 v45; // [rsp+98h] [rbp-60h]
  __int64 v46; // [rsp+A0h] [rbp-58h]
  __int64 v47; // [rsp+A8h] [rbp-50h]
  hkVector4f pointOut; // [rsp+B8h] [rbp-40h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *retaddr; // [rsp+128h] [rbp+30h]
  hkaiPathfindingUtil::FindPathInput *v50; // [rsp+138h] [rbp+40h]
  unsigned int v51; // [rsp+148h] [rbp+50h]

  v6 = world;
  v7 = input;
  v8 = character;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtutilPathReq";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = hkaiWorld::getDynamicQueryMediator(v6);
  v14 = v6->m_streamingCollection.m_pntr;
  v15 = (hkaiNavMeshQueryMediator *)&v13->vfptr;
  LODWORD(retaddr) = 0;
  v16 = fmaxf(0.0, v8->m_radius - v6->m_erosionRadius) * a5;
  v7->m_agentInfo.m_diameter = v16 * 2.0;
  if ( v13 && v14 )
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
    hkaiCharacterUtil::setupQueryInput(v8, (hkaiNavMeshQueryMediator::QueryInputBase *)&inputBase.m_previousFaceKey);
    _mm_store_si128((__m128i *)&up, (__m128i)v8->m_up.m_quad);
    v17 = hkaiCharacterUtil::getFaceForPathfinding(
            v14,
            &v8->m_position,
            &up,
            v15,
            (hkaiNavMeshQueryMediator::QueryInputBase *)&inputBase.m_previousFaceKey,
            &inputBase,
            &pointOut);
    v18 = v7->m_goalPoints.m_size;
    v19 = (hkArrayBase<hkVector4f> *)&v7->m_goalPoints.m_data;
    v51 = v17;
    v20 = 0i64;
    array = 0i64;
    v21 = 0;
    numtoinsert = 0;
    v41 = 2147483648;
    a = 0i64;
    v37 = 0;
    v38 = 2147483648;
    retaddr = &v7->m_goalPoints;
    if ( v18 > 0 )
    {
      v22 = &v6->m_up;
      v23 = 0i64;
      v24 = (unsigned int)v18;
      do
      {
        v25 = hkaiCharacterUtil::getFaceForPathfinding(
                v14,
                &retaddr->m_data[v23],
                v22,
                v15,
                (hkaiNavMeshQueryMediator::QueryInputBase *)&inputBase.m_previousFaceKey,
                &inputBase,
                &up);
        if ( v25 != -1 )
        {
          v26 = numtoinsert;
          if ( numtoinsert == (v41 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 4);
            v26 = numtoinsert;
          }
          array[v26] = v25;
          v27 = v37;
          ++numtoinsert;
          if ( v37 == (v38 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &a, 16);
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
      v7 = v50;
      v19 = (hkArrayBase<hkVector4f> *)&retaddr->m_data;
      v17 = v51;
    }
    v28 = pointOut.m_quad;
    v7->m_startFaceKey = v17;
    v7->m_goalFaceKeys.m_size = 0;
    v7->m_startPoint.m_quad = v28;
    hkArrayBase<unsigned int>::_append(
      (hkArrayBase<unsigned int> *)&v7->m_goalFaceKeys.m_data,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v20,
      v21);
    v29 = v37;
    v30 = a;
    v7->m_goalPoints.m_size = 0;
    hkArrayBase<hkVector4f>::_append(v19, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v30, v29);
    v37 = 0;
    if ( v38 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        a,
        16 * v38);
    a = 0i64;
    v38 = 2147483648;
    numtoinsert = 0;
    if ( v41 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        4 * v41);
    array = 0i64;
    v41 = 2147483648;
  }
  else
  {
    v7->m_goalFaceKeys.m_size = 0;
    v7->m_goalPoints.m_size = 0;
  }
  v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v32 = (_QWORD *)v31[1];
  v33 = v31;
  if ( (unsigned __int64)v32 < v31[3] )
  {
    *v32 = "Et";
    v34 = __rdtsc();
    v35 = (signed __int64)(v32 + 2);
    *(_DWORD *)(v35 - 8) = v34;
    v33[1] = v35;
  }
}

// File Line: 306
// RVA: 0xC0C650
hkaiReferenceFrame *__fastcall hkaiCharacterUtil::getCharacterReferenceFrame(hkaiCharacter *character, hkaiWorld *world)
{
  unsigned int v2; // eax
  hkaiNavMeshInstance *v3; // rax
  hkaiReferenceFrame *result; // rax

  v2 = character->m_currentNavMeshFace;
  if ( v2 != -1 && (v3 = world->m_streamingCollection.m_pntr->m_instances.m_data[v2 >> 22].m_instancePtr) != 0i64 )
    result = &v3->m_referenceFrame;
  else
    result = 0i64;
  return result;
}

// File Line: 325
// RVA: 0xC0C690
__int64 __fastcall hkaiCharacterUtil::getFaceForPathfinding(hkaiStreamingCollection *collection, hkVector4f *point, hkVector4f *up, hkaiNavMeshQueryMediator *mediator, hkaiNavMeshQueryMediator::QueryInputBase *inputBase, hkaiCharacterUtil::GetFaceForPathfindingSettings *settings, hkVector4f *pointOut)
{
  hkaiStreamingCollection *v7; // r12
  hkaiNavMeshQueryMediator *v8; // rsi
  hkVector4f *v9; // rdi
  hkVector4f *v10; // r15
  _QWORD *v11; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r9
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  __m128i v16; // xmm0
  char v17; // cl
  __m128 v18; // xmm0
  hkSimdFloat32 v19; // xmm2
  __int128 v20; // xmm1
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  char v23; // al
  unsigned int v24; // edi
  __m128i v25; // xmm1
  bool v26; // zf
  __int128 v27; // xmm0
  __int128 v28; // xmm1
  hkVector4f v29; // xmm1
  __m128 v30; // xmm0
  unsigned int v31; // eax
  __m128 v32; // xmm0
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  signed __int64 v36; // rcx
  hkVector4f closestPointOut; // [rsp+30h] [rbp-D0h]
  hkaiNavMeshQueryMediator::HitDetails hitOut; // [rsp+40h] [rbp-C0h]
  hkVector4f v40; // [rsp+60h] [rbp-A0h]
  hkaiNavMeshQueryMediator::CoherentInput cinput; // [rsp+70h] [rbp-90h]
  hkaiNavMeshQueryMediator::BidirectionalRaycastInput input; // [rsp+C0h] [rbp-40h]
  hkaiNavMeshQueryMediator::GetClosestPointInput v43; // [rsp+110h] [rbp+10h]

  v7 = collection;
  v8 = mediator;
  v9 = up;
  v10 = point;
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  v13 = v11;
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "TtgetFaceForPath";
    v14 = __rdtsc();
    v15 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v13[1] = v15;
  }
  v16 = (__m128i)v10->m_quad;
  cinput.m_previousFaceKey = -1;
  v17 = settings->m_useCoherentQueries.m_bool;
  _mm_store_si128((__m128i *)&cinput, (__m128i)xmmword_141A712A0);
  _mm_store_si128((__m128i *)&cinput.m_up, (__m128i)xmmword_141A712A0);
  _mm_store_si128((__m128i *)&closestPointOut, v16);
  cinput.m_isOnFaceTolerance.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  cinput.m_coherencyTolerance.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0);
  if ( v17 )
  {
    v18 = (__m128)LODWORD(settings->m_coherencyTolerance);
    cinput.m_previousFaceKey = settings->m_previousFaceKey;
    cinput.m_isOnFaceTolerance.m_real = _mm_shuffle_ps(v18, v18, 0);
    cinput.m_up = (hkVector4f)v9->m_quad;
    cinput.m_previousPoint = (hkVector4f)v10->m_quad;
  }
  v19.m_real = _mm_shuffle_ps((__m128)LODWORD(settings->m_raycastLength), (__m128)LODWORD(settings->m_raycastLength), 0);
  v20 = *(_OWORD *)&inputBase->m_hitFilter;
  *(_OWORD *)&input.m_filterInfo = *(_OWORD *)&inputBase->m_filterInfo;
  *(_OWORD *)&input.m_hitFilter = v20;
  v21 = v10->m_quad;
  input.m_localToWorldTransform = inputBase->m_localToWorldTransform;
  v22 = v9->m_quad;
  input.m_center.m_quad = v21;
  input.m_forwardTo.m_quad = _mm_add_ps(_mm_mul_ps(v22, v19.m_real), v21);
  if ( v17 )
  {
    cinput.m_coherencyTolerance = (hkSimdFloat32)v19.m_real;
    v23 = hkaiNavMeshQueryMediator::coherentCastBidirectionalRay(v8, v7, &input, &cinput, &hitOut);
  }
  else
  {
    v23 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, hkaiNavMeshQueryMediator::BidirectionalRaycastInput *, hkaiNavMeshQueryMediator::HitDetails *, _QWORD *))v8->vfptr[3].__vecDelDtor)(
            v8,
            &input,
            &hitOut,
            v13);
  }
  if ( !v23
    || (v24 = hitOut.m_hitFaceKey,
        v25 = (__m128i)_mm_add_ps(
                         _mm_mul_ps(
                           _mm_sub_ps(input.m_forwardTo.m_quad, input.m_center.m_quad),
                           hitOut.m_hitFraction.m_real),
                         input.m_center.m_quad),
        closestPointOut.m_quad = (__m128)v25,
        hitOut.m_hitFaceKey == -1) )
  {
    v26 = settings->m_useCoherentQueries.m_bool == 0;
    v27 = *(_OWORD *)&inputBase->m_filterInfo;
    v28 = *(_OWORD *)&inputBase->m_hitFilter;
    v43.m_navMeshCutter = 0i64;
    *(_OWORD *)&v43.m_filterInfo = v27;
    *(_OWORD *)&v43.m_hitFilter = v28;
    v29.m_quad = v10->m_quad;
    v43.m_localToWorldTransform = inputBase->m_localToWorldTransform;
    v30 = (__m128)LODWORD(settings->m_aabbQuerySize);
    v43.m_position = (hkVector4f)v29.m_quad;
    v43.m_queryRadius.m_real = _mm_shuffle_ps(v30, v30, 0);
    if ( v26 )
    {
      v31 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, hkaiNavMeshQueryMediator::GetClosestPointInput *, hkVector4f *))v8->vfptr[1].__first_virtual_table_function__)(
              v8,
              &v43,
              &closestPointOut);
    }
    else
    {
      cinput.m_coherencyTolerance.m_real = _mm_shuffle_ps(
                                             (__m128)LODWORD(settings->m_coherencyTolerance),
                                             (__m128)LODWORD(settings->m_coherencyTolerance),
                                             0);
      v31 = hkaiNavMeshQueryMediator::coherentGetClosestPoint(v8, v7, &v43, &cinput, &closestPointOut);
    }
    v25 = (__m128i)closestPointOut.m_quad;
    v24 = v31;
  }
  if ( settings->m_resolveEdgePenetrations.m_bool
    && v24 != -1
    && (v32 = (__m128)LODWORD(settings->m_characterRadius), v32.m128_f32[0] > 0.00000011920929) )
  {
    _mm_store_si128((__m128i *)&v40, v25);
    hitOut.m_hitFraction.m_real = _mm_shuffle_ps(v32, v32, 0);
    hkaiNavMeshUtils::resolveEdgePenetrations(v7, v8, &closestPointOut, &hitOut.m_hitFraction, &v40);
    *pointOut = (hkVector4f)v40.m_quad;
  }
  else
  {
    *pointOut = (hkVector4f)v25;
  }
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "Et";
    v35 = __rdtsc();
    v36 = (signed __int64)(v34 + 2);
    *(_DWORD *)(v36 - 8) = v35;
    v33[1] = v36;
  }
  return v24;
}

// File Line: 400
// RVA: 0xC0C310
void __fastcall hkaiCharacterUtil::updatePathRequest(hkaiWorld *world, hkaiCharacter *character, hkaiVolumePathfindingUtil::FindPathInput *input, float querySize)
{
  hkaiWorld *v4; // rbx
  hkaiVolumePathfindingUtil::FindPathInput *v5; // r13
  hkaiCharacter *v6; // rdi
  _QWORD *v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r9
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  hkaiDynamicNavVolumeMediator *v12; // r15
  __m128 v13; // xmm0
  int v14; // eax
  __int64 v15; // r14
  const unsigned int *v16; // r8
  __int64 v17; // r9
  __int64 v18; // rdi
  unsigned int v19; // esi
  int v20; // edx
  int v21; // ecx
  __int128 v22; // xmm0
  int v23; // er9
  hkVector4f *v24; // r8
  _QWORD *v25; // rax
  _QWORD *v26; // rcx
  _QWORD *v27; // r8
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  unsigned int *array; // [rsp+18h] [rbp-79h]
  int numtoinsert; // [rsp+20h] [rbp-71h]
  int v32; // [rsp+24h] [rbp-6Dh]
  hkVector4f *a; // [rsp+28h] [rbp-69h]
  int v34; // [rsp+30h] [rbp-61h]
  int v35; // [rsp+34h] [rbp-5Dh]
  int v36; // [rsp+38h] [rbp-59h]
  hkVector4f v37; // [rsp+48h] [rbp-49h]
  __int128 v38; // [rsp+58h] [rbp-39h]
  hkaiNavVolumeMediator::GetClosestPointInput gcpInput; // [rsp+68h] [rbp-29h]

  v4 = world;
  v5 = input;
  v6 = character;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  v9 = v7;
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TtutilPathReq";
    v10 = __rdtsc();
    v11 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v9[1] = v11;
  }
  v12 = hkaiWorld::getDynamicNavVolumeMediator(v4);
  if ( v12 )
  {
    v13 = 0i64;
    gcpInput.m_filterInfo = 0;
    gcpInput.m_position = (hkVector4f)xmmword_141A712A0;
    _mm_store_si128((__m128i *)&gcpInput.m_hitFilter, (__m128i)0i64);
    gcpInput.m_userData = 0i64;
    gcpInput.m_translation = 0i64;
    hkaiCharacterUtil::setupGetClosestPointInput(v6, &gcpInput);
    v13.m128_f32[0] = querySize;
    gcpInput.m_queryRadius.m_real = _mm_shuffle_ps(v13, v13, 0);
    v14 = ((__int64 (__fastcall *)(hkaiDynamicNavVolumeMediator *, hkaiNavVolumeMediator::GetClosestPointInput *, __int128 *))v12->vfptr[1].__first_virtual_table_function__)(
            v12,
            &gcpInput,
            &v38);
    v15 = v5->m_goalPoints.m_size;
    v16 = 0i64;
    array = 0i64;
    v17 = 0i64;
    numtoinsert = 0;
    v36 = v14;
    v32 = 2147483648;
    a = 0i64;
    v34 = 0;
    v35 = 2147483648;
    if ( v15 > 0 )
    {
      v18 = 0i64;
      do
      {
        gcpInput.m_position = v5->m_goalPoints.m_data[v18];
        v19 = ((__int64 (__fastcall *)(hkaiDynamicNavVolumeMediator *, hkaiNavVolumeMediator::GetClosestPointInput *, hkVector4f *, __int64))v12->vfptr[1].__first_virtual_table_function__)(
                v12,
                &gcpInput,
                &v37,
                v17);
        if ( v19 != -1 )
        {
          v20 = numtoinsert;
          if ( numtoinsert == (v32 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 4);
            v20 = numtoinsert;
          }
          array[v20] = v19;
          v21 = v34;
          ++numtoinsert;
          if ( v34 == (v35 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &a, 16);
            v21 = v34;
          }
          a[v21] = (hkVector4f)v37.m_quad;
          ++v34;
        }
        ++v18;
        --v15;
      }
      while ( v15 );
      LODWORD(v17) = numtoinsert;
      v16 = array;
      v14 = v36;
    }
    v22 = v38;
    v5->m_startCellKey = v14;
    v5->m_goalCellKeys.m_size = 0;
    v5->m_startPoint = (hkVector4f)v22;
    hkArrayBase<unsigned int>::_append(
      (hkArrayBase<unsigned int> *)&v5->m_goalCellKeys.m_data,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v16,
      v17);
    v23 = v34;
    v24 = a;
    v5->m_goalPoints.m_size = 0;
    hkArrayBase<hkVector4f>::_append(
      (hkArrayBase<hkVector4f> *)&v5->m_goalPoints.m_data,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v24,
      v23);
    v34 = 0;
    if ( v35 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        a,
        16 * v35);
    a = 0i64;
    v35 = 2147483648;
    numtoinsert = 0;
    if ( v32 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        4 * v32);
    array = 0i64;
    v32 = 2147483648;
  }
  else
  {
    v5->m_goalCellKeys.m_size = 0;
    v5->m_goalPoints.m_size = 0;
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  v27 = v25;
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v28 = __rdtsc();
    v29 = (signed __int64)(v26 + 2);
    *(_DWORD *)(v29 - 8) = v28;
    v27[1] = v29;
  }
}

// File Line: 451
// RVA: 0xC0CCF0
void __usercall hkaiCharacterUtil::integrateMotion(float timestep@<xmm0>, hkaiCharacter *const *characters@<rdx>, int numCharacters@<r8d>, __m128 a4@<xmm1>)
{
  signed __int64 v4; // rcx
  __m128 v5; // xmm1
  hkaiCharacter *v6; // rax

  v4 = 0i64;
  if ( numCharacters > 0 )
  {
    a4.m128_f32[0] = timestep;
    v5 = _mm_shuffle_ps(a4, a4, 0);
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
void __usercall hkaiCharacterUtil::integrateMotionAndProjectToMesh(float timestep@<xmm0>, hkaiWorld *world@<rdx>, hkaiCharacter *const *characters@<r8>, int numCharacters@<r9d>, __m128 a5@<xmm7>, hkaiCharacterUtil::ProjectToMeshSettings *settings)
{
  hkaiWorld *v6; // rbx
  __int64 v7; // r14
  hkaiCharacter *const *v8; // r15
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  hkaiStreamingCollection *v14; // r12
  hkaiDynamicNavMeshQueryMediator *v15; // r13
  char v16; // cl
  float v17; // xmm1_4
  __int64 v18; // rsi
  __m128 v19; // xmm7
  hkaiCharacter *v20; // rbx
  __m128 v21; // xmm6
  __m128 v22; // xmm6
  unsigned int v23; // eax
  _QWORD *v24; // rax
  _QWORD *v25; // rcx
  _QWORD *v26; // r8
  unsigned __int64 v27; // rax
  signed __int64 v28; // rcx
  hkVector4f pointOut; // [rsp+38h] [rbp-71h]
  hkVector4f up; // [rsp+48h] [rbp-61h]
  hkVector4f point; // [rsp+58h] [rbp-51h]
  hkaiCharacterUtil::GetFaceForPathfindingSettings v32; // [rsp+68h] [rbp-41h]
  hkaiNavMeshQueryMediator::QueryInputBase input; // [rsp+88h] [rbp-21h]
  __int64 v34; // [rsp+128h] [rbp+7Fh]

  v6 = world;
  v7 = numCharacters;
  v8 = characters;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtintegrateMotionAndProjectToMesh";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = v6->m_streamingCollection.m_pntr;
  v15 = hkaiWorld::getDynamicQueryMediator(v6);
  hkaiCharacterUtil::GetFaceForPathfindingSettings::GetFaceForPathfindingSettings(&v32);
  v16 = *(_BYTE *)(v34 + 12);
  v32.m_resolveEdgePenetrations.m_bool = 0;
  v17 = *(float *)(v34 + 4);
  v32.m_aabbQuerySize = *(float *)v34;
  v32.m_raycastLength = v17;
  v18 = 0i64;
  v32.m_useCoherentQueries.m_bool = v16;
  v32.m_characterRadius = 0.0;
  v32.m_coherencyTolerance = *(float *)(v34 + 16);
  if ( v7 > 0 )
  {
    a5.m128_f32[0] = timestep;
    v19 = _mm_shuffle_ps(a5, a5, 0);
    do
    {
      v20 = v8[v18];
      input.m_filterInfo = 0;
      input.m_userData = 0i64;
      input.m_hitFilter = 0i64;
      v21 = _mm_mul_ps(v20->m_velocity.m_quad, v19);
      _mm_store_si128((__m128i *)&up, (__m128i)v20->m_up.m_quad);
      input.m_instance = 0i64;
      input.m_localToWorldTransform = 0i64;
      v22 = _mm_add_ps(v21, v20->m_position.m_quad);
      point.m_quad = v22;
      hkaiCharacterUtil::setupQueryInput(v20, &input);
      v23 = v20->m_currentNavMeshFace;
      _mm_store_si128((__m128i *)&pointOut, (__m128i)v22);
      v32.m_previousFaceKey = v23;
      hkaiCharacterUtil::getFaceForPathfinding(
        v14,
        &point,
        &up,
        (hkaiNavMeshQueryMediator *)&v15->vfptr,
        &input,
        &v32,
        &pointOut);
      ++v18;
      v20->m_position.m_quad = _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps(pointOut.m_quad, v22),
                                   _mm_shuffle_ps(
                                     (__m128)*(unsigned int *)(v34 + 8),
                                     (__m128)*(unsigned int *)(v34 + 8),
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
    v28 = (signed __int64)(v25 + 2);
    *(_DWORD *)(v28 - 8) = v27;
    v26[1] = v28;
  }
}

// File Line: 518
// RVA: 0xC0BBF0
void __fastcall hkaiCharacterUtil::setupQueryInput(hkaiCharacter *character, hkaiNavMeshQueryMediator::QueryInputBase *input)
{
  input->m_filterInfo = character->m_agentFilterInfo;
  input->m_userData = character->m_userData;
  input->m_hitFilter = character->m_hitFilter.m_pntr;
}

// File Line: 525
// RVA: 0xC0BC20
void __fastcall hkaiCharacterUtil::setupGetClosestPointInput(hkaiCharacter *character, hkaiNavMeshQueryMediator::GetClosestPointInput *gcpInput)
{
  hkaiNavMeshQueryMediator::GetClosestPointInput *v2; // rdi
  hkaiCharacter *v3; // rbx

  v2 = gcpInput;
  v3 = character;
  hkaiCharacterUtil::setupQueryInput(character, (hkaiNavMeshQueryMediator::QueryInputBase *)&gcpInput->m_filterInfo);
  v2->m_position = v3->m_position;
}

// File Line: 531
// RVA: 0xC0BC50
void __fastcall hkaiCharacterUtil::setupGetClosestPointInput(hkaiCharacter *character, hkaiNavVolumeMediator::GetClosestPointInput *gcpInput)
{
  gcpInput->m_filterInfo = character->m_agentFilterInfo;
  gcpInput->m_userData = character->m_userData;
  gcpInput->m_hitFilter = character->m_hitFilter.m_pntr;
  gcpInput->m_position = character->m_position;
}

