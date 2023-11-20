// File Line: 39
// RVA: 0xBF5450
void __fastcall hkaiOverlapManager::hkaiOverlapManager(hkaiOverlapManager *this, hkaiStreamingCollection *navMeshCollection, hkaiReferenceFrameAndExtrusion *referenceFrameAndExtrusion)
{
  hkaiReferenceFrameAndExtrusion *v3; // rsi
  hkaiStreamingCollection *v4; // rdi
  hkaiOverlapManager *v5; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v3 = referenceFrameAndExtrusion;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiOverlapManager::`vftable{for `hkReferencedObject};
  v4 = navMeshCollection;
  this->vfptr = (hkaiNavMeshSilhouetteSelectorVtbl *)&hkaiOverlapManager::`vftable{for `hkaiNavMeshSilhouetteSelector};
  v5 = this;
  this->m_referenceFrameAndExtrusion.m_up = referenceFrameAndExtrusion->m_up;
  *(_OWORD *)&this->m_referenceFrameAndExtrusion.m_cellExtrusion = *(_OWORD *)&referenceFrameAndExtrusion->m_cellExtrusion;
  if ( navMeshCollection )
    hkReferencedObject::addReference((hkReferencedObject *)&navMeshCollection->vfptr);
  v5->m_navMeshCollection.m_pntr = v4;
  v5->m_sections.m_capacityAndFlags = 2147483648;
  v5->m_sections.m_data = 0i64;
  v5->m_sections.m_size = 0;
  v5->m_silhouetteFilter.m_pntr = 0i64;
  v5->m_priorityController.m_pntr = 0i64;
  hkaiOverlapManager::setReferenceFrameAndExtrusion(v5, v3);
  v5->m_stepCount = 0;
  v5->m_maxCutFacesPerStep = -1;
  v5->m_hasMovedTolerance = 0.001;
}

// File Line: 47
// RVA: 0xBF7040
void __fastcall hkaiOverlapManager::setReferenceFrameAndExtrusion(hkaiOverlapManager *this, hkaiReferenceFrameAndExtrusion *refFrame)
{
  this->m_referenceFrameAndExtrusion.m_up = refFrame->m_up;
  this->m_referenceFrameAndExtrusion.m_cellExtrusion = refFrame->m_cellExtrusion;
  this->m_referenceFrameAndExtrusion.m_silhouetteRadiusExpasion = refFrame->m_silhouetteRadiusExpasion;
  this->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage = refFrame->m_upTransformMethod.m_storage;
}

// File Line: 53
// RVA: 0xBF5FE0
void __fastcall hkaiOverlapManager::setSilhouetteFilter(hkaiOverlapManager *this, hkaiSpatialQueryHitFilter *filter)
{
  hkaiSpatialQueryHitFilter *v2; // rbx
  hkaiOverlapManager *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = filter;
  v3 = this;
  if ( filter )
    hkReferencedObject::addReference((hkReferencedObject *)&filter->vfptr);
  v4 = (hkReferencedObject *)&v3->m_silhouetteFilter.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_silhouetteFilter.m_pntr = v2;
}

// File Line: 62
// RVA: 0xBF5500
void __fastcall hkaiOverlapManager::hkaiOverlapManager(hkaiOverlapManager *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiOverlapManager::`vftable{for `hkReferencedObject};
  this->vfptr = (hkaiNavMeshSilhouetteSelectorVtbl *)&hkaiOverlapManager::`vftable{for `hkaiNavMeshSilhouetteSelector};
  this->m_silhouetteFilter.m_pntr = 0i64;
  this->m_priorityController.m_pntr = 0i64;
  if ( f.m_finishing )
    hkaiOverlapManager::rebuildMaps(this, 0);
}

// File Line: 72
// RVA: 0xBF5550
void __fastcall hkaiOverlapManager::~hkaiOverlapManager(hkaiOverlapManager *this)
{
  hkaiOverlapManager *v1; // rbx
  int v2; // edi
  hkReferencedObject *v3; // rcx
  hkReferencedObject *v4; // rcx
  int v5; // edi
  hkaiOverlapManagerSection *v6; // rsi
  int v7; // eax
  hkReferencedObject *v8; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiOverlapManager::`vftable{for `hkReferencedObject};
  v1 = this;
  v2 = 0;
  for ( this->vfptr = (hkaiNavMeshSilhouetteSelectorVtbl *)&hkaiOverlapManager::`vftable{for `hkaiNavMeshSilhouetteSelector};
        v2 < v1->m_sections.m_size;
        ++v2 )
  {
    hkaiOverlapManager::unloadSection(v1, v2);
  }
  v3 = (hkReferencedObject *)&v1->m_priorityController.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_priorityController.m_pntr = 0i64;
  v4 = (hkReferencedObject *)&v1->m_silhouetteFilter.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v1->m_silhouetteFilter.m_pntr = 0i64;
  v5 = v1->m_sections.m_size - 1;
  if ( v5 >= 0 )
  {
    v6 = &v1->m_sections.m_data[v5];
    do
    {
      hkaiOverlapManagerSection::~hkaiOverlapManagerSection(v6);
      --v6;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v7 = v1->m_sections.m_capacityAndFlags;
  v1->m_sections.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_sections.m_data,
      72 * (v7 & 0x3FFFFFFF));
  v1->m_sections.m_data = 0i64;
  v1->m_sections.m_capacityAndFlags = 2147483648;
  v8 = (hkReferencedObject *)&v1->m_navMeshCollection.m_pntr->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v1->m_navMeshCollection.m_pntr = 0i64;
  v1->vfptr = (hkaiNavMeshSilhouetteSelectorVtbl *)&hkaiNavMeshSilhouetteSelector::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 81
// RVA: 0xBF77D0
void __fastcall hkaiOverlapManager::queryAndUpdateFacesForGenerator(hkaiOverlapManager *this, int sectionIdx, hkaiOverlapManagerSection::GeneratorData *generatorData, hkaiSilhouetteGenerator *gen, hkQTransformf *silhouetteRelativeTransform)
{
  hkaiSilhouetteGenerator *v5; // r14
  hkaiOverlapManagerSection::GeneratorData *v6; // r13
  __int64 v7; // r15
  hkaiOverlapManager *v8; // rsi
  hkaiNavMeshInstance *v9; // rbx
  hkQTransformf *v10; // r12
  hkaiSpatialQueryHitFilter *v11; // rax
  hkaiStreamingCollection *v12; // rax
  hkaiNavMeshQueryMediator *v13; // rbx
  _QWORD *v14; // rax
  unsigned __int64 v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx
  unsigned int *array; // [rsp+40h] [rbp-31h]
  int v23; // [rsp+48h] [rbp-29h]
  int v24; // [rsp+4Ch] [rbp-25h]
  int v25; // [rsp+50h] [rbp-21h]
  hkaiSilhouetteGenerator *v26; // [rsp+58h] [rbp-19h]
  __int128 v27; // [rsp+60h] [rbp-11h]
  __int64 v28; // [rsp+70h] [rbp-1h]
  hkAabb genAabb; // [rsp+80h] [rbp+Fh]
  hkResult result; // [rsp+D8h] [rbp+67h]

  v5 = gen;
  v6 = generatorData;
  v7 = sectionIdx;
  v8 = this;
  array = 0i64;
  v23 = 0;
  v24 = 2147483648;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 32, 4);
  v9 = v8->m_navMeshCollection.m_pntr->m_instances.m_data[v7].m_instancePtr;
  v25 = 0;
  v26 = 0i64;
  _mm_store_si128((__m128i *)&v27, (__m128i)0i64);
  genAabb.m_min = (hkVector4f)xmmword_141A712A0;
  v28 = 0i64;
  v10 = silhouetteRelativeTransform;
  genAabb.m_max.m_quad = _mm_xor_ps(
                           (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                           (__m128)xmmword_141A712A0);
  hkaiOverlapManager::getExtrudedAabbForGenerator(
    v8,
    v5,
    &v8->m_referenceFrameAndExtrusion,
    silhouetteRelativeTransform,
    v9,
    &genAabb);
  v11 = v8->m_silhouetteFilter.m_pntr;
  v26 = v5;
  *(_QWORD *)&v27 = v11;
  v12 = v8->m_navMeshCollection.m_pntr;
  *((_QWORD *)&v27 + 1) = v9;
  v13 = v12->m_instances.m_data[v7].m_mediator;
  v23 = 0;
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = v14[1];
  v16 = v14;
  if ( v15 < v14[3] )
  {
    *(_QWORD *)v15 = "TtqueryAabb";
    v17 = __rdtsc();
    *(_DWORD *)(v15 + 8) = v17;
    v16[1] = v15 + 16;
  }
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, unsigned int **))v13->vfptr[3].__first_virtual_table_function__)(
    v13,
    &v25,
    &array);
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = (signed __int64)(v19 + 2);
    *(_DWORD *)(v21 - 8) = v20;
    v18[1] = v21;
  }
  if ( v23 > 1 )
    hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(array, 0, v23 - 1, 0);
  hkaiOverlapManager::updateSectionFacesForGenerator(v8, v7, v6, v5, v10, &genAabb, (hkArrayBase<unsigned int> *)&array);
  v23 = 0;
  if ( v24 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v24);
}

// File Line: 114
// RVA: 0xBF7070
void __fastcall hkaiOverlapManager::updateSectionFacesForGenerator(hkaiOverlapManager *this, int sectionIdx, hkaiOverlapManagerSection::GeneratorData *generatorData, hkaiSilhouetteGenerator *gen, hkQTransformf *silhouetteRelativeTransform, hkAabb *genAabb, hkArrayBase<unsigned int> *faceKeys)
{
  hkArrayBase<unsigned int> *v7; // r14
  int v8; // ebx
  hkArray<int,hkContainerHeapAllocator> *v9; // r15
  hkaiOverlapManagerSection *v10; // rax
  int v11; // er12
  hkLifoAllocator *v12; // rax
  unsigned int *v13; // r13
  int v14; // edx
  char *v15; // rcx
  __int64 v16; // rdi
  hkLifoAllocator *v17; // rax
  _DWORD *v18; // rbp
  int v19; // edx
  char *v20; // rcx
  hkLifoAllocator *v21; // rax
  int v22; // edx
  char *v23; // rcx
  hkReferencedObject *v24; // rcx
  char v25; // si
  hkReferencedObject *v26; // rbx
  hkReferencedObject *v27; // rcx
  hkaiOverlapManager *v28; // rsi
  signed int v29; // er8
  __m128i v30; // xmm0
  int v31; // edx
  int v32; // er8
  __int64 v33; // r10
  __int64 v34; // r11
  int v35; // eax
  int v36; // er9
  int v37; // ecx
  __int64 v38; // r9
  signed __int64 v39; // r8
  __int64 v40; // rcx
  int v41; // eax
  signed __int64 v42; // rdx
  __int64 v43; // rax
  hkAabb *v44; // r14
  float v45; // xmm7_4
  float v46; // xmm6_4
  int *v47; // rbx
  int v48; // er11
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v49; // r10
  signed int v50; // ecx
  signed __int64 v51; // rdx
  signed __int64 v52; // r9
  signed __int64 v53; // r8
  char **v54; // rax
  __int64 v55; // rax
  float v56; // xmm6_4
  int *v57; // rsi
  __int64 v58; // rbp
  int v59; // edi
  signed __int64 v60; // rbx
  __int64 v61; // rsi
  unsigned int *v62; // r14
  int *v63; // rbx
  __int64 v64; // rdi
  int v65; // er9
  int v66; // eax
  int v67; // eax
  signed int v68; // edi
  hkLifoAllocator *v69; // rax
  int v70; // ebx
  int v71; // esi
  hkLifoAllocator *v72; // rax
  hkLifoAllocator *v73; // rax
  unsigned int *a; // [rsp+30h] [rbp-B8h]
  _DWORD *v75; // [rsp+38h] [rbp-B0h]
  hkReferencedObject *v76; // [rsp+40h] [rbp-A8h]
  hkaiSilhouetteGeneratorSectionContext *v77; // [rsp+48h] [rbp-A0h]
  hkaiOverlapManagerSection *v78; // [rsp+50h] [rbp-98h]
  hkArray<int,hkContainerHeapAllocator> *v79; // [rsp+58h] [rbp-90h]
  hkReferencedObject v80; // [rsp+60h] [rbp-88h]
  __int128 v81; // [rsp+70h] [rbp-78h]
  hkaiOverlapManager *v82; // [rsp+F0h] [rbp+8h]
  hkResult result; // [rsp+F8h] [rbp+10h]
  int v84; // [rsp+100h] [rbp+18h]
  hkaiSilhouetteGenerator *v85; // [rsp+108h] [rbp+20h]

  v85 = gen;
  v82 = this;
  v7 = faceKeys;
  result.m_enum = 0;
  v8 = generatorData->m_overlappedFaces.m_size;
  v9 = &generatorData->m_overlappedFaces;
  v79 = &generatorData->m_overlappedFaces;
  if ( faceKeys->m_size > v8 )
    v8 = faceKeys->m_size;
  v10 = &this->m_sections.m_data[sectionIdx];
  v11 = 0;
  LODWORD(faceKeys) = v8;
  v78 = v10;
  v77 = &generatorData->m_context;
  if ( v8 )
  {
    v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (unsigned int *)v12->m_cur;
    v14 = (4 * v8 + 127) & 0xFFFFFF80;
    v15 = (char *)v13 + v14;
    if ( v14 > v12->m_slabSize || v15 > v12->m_end )
      v13 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
    else
      v12->m_cur = v15;
  }
  else
  {
    v13 = 0i64;
  }
  v16 = 0i64;
  v84 = v8 | 0x80000000;
  if ( v8 )
  {
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = v17->m_cur;
    v19 = (4 * v8 + 127) & 0xFFFFFF80;
    v75 = v18;
    v20 = (char *)v18 + v19;
    if ( v19 > v17->m_slabSize || v20 > v17->m_end )
    {
      v18 = hkLifoAllocator::allocateFromNewSlab(v17, v19);
      v75 = v18;
    }
    else
    {
      v17->m_cur = v20;
    }
  }
  else
  {
    v18 = 0i64;
    v75 = 0i64;
  }
  result.m_enum = 0;
  if ( v8 )
  {
    v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (4 * v8 + 127) & 0xFFFFFF80;
    a = (unsigned int *)v21->m_cur;
    v23 = (char *)a + v22;
    if ( v22 > v21->m_slabSize || v23 > v21->m_end )
      a = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v21, v22);
    else
      v21->m_cur = v23;
  }
  else
  {
    a = 0i64;
  }
  *(_DWORD *)&v80.m_memSizeAndFlags = 0x1FFFF;
  v24 = (hkReferencedObject *)&v82->m_priorityController.m_pntr->vfptr;
  v25 = 1;
  v80.vfptr = (hkBaseObjectVtbl *)&hkaiDefaultSilhouettePriorityController::`vftable;
  if ( v24 )
  {
    hkReferencedObject::addReference(v24);
    v26 = (hkReferencedObject *)&v82->m_priorityController.m_pntr->vfptr;
    v76 = (hkReferencedObject *)&v82->m_priorityController.m_pntr->vfptr;
    v27 = (hkReferencedObject *)&v82->m_priorityController.m_pntr->vfptr;
  }
  else
  {
    v25 = 2;
    hkReferencedObject::addReference(&v80);
    v27 = &v80;
    v76 = &v80;
    v26 = &v80;
  }
  if ( v25 & 2 )
  {
    v25 &= 0xFDu;
    if ( v27 )
      hkReferencedObject::removeReference(v27);
  }
  if ( v25 & 1 && v26 )
    hkReferencedObject::removeReference(v26);
  v28 = v82;
  v29 = v9->m_size;
  v30 = (__m128i)v82->m_referenceFrameAndExtrusion.m_up;
  _mm_store_si128((__m128i *)&v81, v30);
  if ( v29 > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(v9->m_data, 0, v29 - 1, 0);
  v31 = 0;
  v32 = 0;
  v33 = 0i64;
  v34 = 0i64;
  while ( 1 )
  {
    v35 = v9->m_size;
    if ( v31 == v35 )
    {
      if ( v32 == v7->m_size )
        goto LABEL_49;
      if ( v31 == v35 )
        break;
    }
    if ( v32 == v7->m_size )
    {
      if ( v31 < v35 )
      {
        v39 = v31;
        do
        {
          v40 = (signed int)v16;
          ++v31;
          v41 = v9->m_data[v39];
          v16 = (unsigned int)(v16 + 1);
          ++v39;
          v18[v40] = v41;
        }
        while ( v31 < v9->m_size );
      }
      goto LABEL_49;
    }
    v36 = v9->m_data[v34];
    v37 = v7->m_data[v33] & 0x3FFFFF;
    if ( v36 == v37 )
    {
      v38 = result.m_enum;
      ++v31;
      ++v34;
      ++v32;
      ++v33;
      a[v38] = v37;
      result.m_enum = v38 + 1;
    }
    else if ( v36 >= v37 )
    {
      ++v32;
      ++v33;
      v13[v11++] = v37;
    }
    else
    {
      ++v31;
      ++v34;
      v18[(signed int)v16] = v36;
      v16 = (unsigned int)(v16 + 1);
    }
  }
  if ( v32 < v7->m_size )
  {
    v42 = v32;
    do
    {
      ++v32;
      ++v42;
      v43 = v11++;
      v13[v43] = v7->m_data[v42 - 1] & 0x3FFFFF;
    }
    while ( v32 < v7->m_size );
  }
LABEL_49:
  v44 = genAabb;
  v45 = *(float *)&FLOAT_1_0;
  if ( (signed int)v16 > 0 )
  {
    if ( v82->m_maxCutFacesPerStep <= 0 )
    {
      v46 = *(float *)&FLOAT_1_0;
    }
    else
    {
      ((void (__fastcall *)(hkReferencedObject *, hkaiSilhouetteGenerator *, hkAabb *, __int128 *))v76->vfptr[2].__vecDelDtor)(
        v76,
        v85,
        genAabb,
        &v81);
      v46 = *(float *)v30.m128i_i32;
    }
    if ( (signed int)v16 > 0 )
    {
      v47 = v18;
      do
      {
        v48 = *v47;
        v49 = v78->m_faceToGeneratorsMap.m_data;
        v50 = 0;
        v51 = 0i64;
        v52 = *v47;
        v53 = v49[*v47].m_size;
        if ( v53 <= 0 )
        {
LABEL_59:
          v50 = -1;
          v51 = -1i64;
        }
        else
        {
          v54 = (char **)v49[*v47].m_data;
          while ( *v54 != (char *)v77 )
          {
            ++v51;
            ++v50;
            ++v54;
            if ( v51 >= v53 )
              goto LABEL_59;
          }
        }
        --v49[*v47].m_size;
        v55 = v49[v52].m_size;
        if ( (_DWORD)v55 != v50 )
          v49[v52].m_data[v51] = v49[v52].m_data[v55];
        hkaiOverlapManagerSection::setFaceDirty(v78, v48, v46);
        ++v47;
        --v16;
      }
      while ( v16 );
      v9 = v79;
      v28 = v82;
    }
  }
  if ( v11 > 0 )
  {
    if ( v28->m_maxCutFacesPerStep <= 0 )
    {
      v56 = *(float *)&FLOAT_1_0;
    }
    else
    {
      ((void (__fastcall *)(hkReferencedObject *, hkaiSilhouetteGenerator *, hkAabb *, __int128 *))v76->vfptr[1].__first_virtual_table_function__)(
        v76,
        v85,
        v44,
        &v81);
      v56 = *(float *)v30.m128i_i32;
    }
    if ( v11 > 0 )
    {
      v57 = (int *)v13;
      v58 = (unsigned int)v11;
      do
      {
        v59 = *v57;
        v60 = (signed __int64)&v78->m_faceToGeneratorsMap.m_data[*v57];
        if ( *(_DWORD *)(v60 + 8) == (*(_DWORD *)(v60 + 12) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v78->m_faceToGeneratorsMap.m_data[*v57],
            8);
        *(_QWORD *)(*(_QWORD *)v60 + 8i64 * (signed int)(*(_DWORD *)(v60 + 8))++) = v77;
        hkaiOverlapManagerSection::setFaceDirty(v78, v59, v56);
        ++v57;
        --v58;
      }
      while ( v58 );
      v9 = v79;
      v44 = genAabb;
      v18 = v75;
    }
  }
  v61 = (unsigned int)result.m_enum;
  if ( (signed int)result.m_enum <= 0 )
  {
    v62 = a;
  }
  else
  {
    if ( v82->m_maxCutFacesPerStep > 0 )
    {
      ((void (__fastcall *)(hkReferencedObject *, hkaiSilhouetteGenerator *, hkAabb *, __int128 *, hkaiSilhouetteGeneratorSectionContext *, hkQTransformf *))v76->vfptr[2].__first_virtual_table_function__)(
        v76,
        v85,
        v44,
        &v81,
        v77,
        silhouetteRelativeTransform);
      v45 = *(float *)v30.m128i_i32;
    }
    v62 = a;
    if ( (signed int)v61 > 0 )
    {
      v63 = (int *)a;
      v64 = v61;
      do
      {
        hkaiOverlapManagerSection::setFaceDirty(v78, *v63, v45);
        ++v63;
        --v64;
      }
      while ( v64 );
      v18 = v75;
    }
  }
  v65 = v61 + v11;
  v66 = v9->m_capacityAndFlags & 0x3FFFFFFF;
  v9->m_size = 0;
  if ( v66 < (signed int)v61 + v11 )
  {
    v67 = 2 * v66;
    if ( v65 < v67 )
      v65 = v67;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9, v65, 4);
  }
  hkArrayBase<unsigned int>::_append(
    (hkArrayBase<unsigned int> *)v9,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v13,
    v11);
  hkArrayBase<unsigned int>::_append(
    (hkArrayBase<unsigned int> *)v9,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v62,
    v61);
  v68 = (4 * (_DWORD)faceKeys + 127) & 0xFFFFFF80;
  v80.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  v69 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v70 = (v68 + 15) & 0xFFFFFFF0;
  if ( v68 > v69->m_slabSize || (char *)v62 + v70 != v69->m_cur || v69->m_firstNonLifoEnd == v62 )
    hkLifoAllocator::slowBlockFree(v69, v62, v70);
  else
    v69->m_cur = v62;
  v71 = v84;
  if ( v84 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v62,
      4 * v84);
  v72 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v68 > v72->m_slabSize || (char *)v18 + v70 != v72->m_cur || v72->m_firstNonLifoEnd == v18 )
    hkLifoAllocator::slowBlockFree(v72, v18, v70);
  else
    v72->m_cur = v18;
  if ( v71 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v18,
      4 * v71);
  v73 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v68 > v73->m_slabSize || (char *)v13 + v70 != v73->m_cur || v73->m_firstNonLifoEnd == v13 )
    hkLifoAllocator::slowBlockFree(v73, v13, v70);
  else
    v73->m_cur = v13;
  if ( v71 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v13,
      4 * v71);
}tor::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v13,
      4 * v71);
}

// File Line: 309
// RVA: 0xBF5660
void __fastcall hkaiOverlapManager::loadSection(hkaiOverlapManager *this, int sectionIndex, hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *generators)
{
  __int64 v3; // r13
  int v4; // edi
  hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *v5; // r12
  int v6; // ebp
  hkaiOverlapManager *v7; // r15
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // ebx
  hkaiOverlapManagerSection *v12; // rsi
  __int64 v13; // rax
  __int64 v14; // r8
  signed __int64 v15; // rax
  hkaiOverlapManagerSection *v16; // rbp
  hkaiStreamingCollection::InstanceInfo *v17; // rax
  hkaiNavMeshInstance *v18; // rbx
  __int64 v19; // rsi
  hkaiSilhouetteGenerator *v20; // rbx
  hkaiOverlapManagerSection::GeneratorData *v21; // rax
  hkQuaternionf v22; // [rsp+30h] [rbp-68h]
  hkVector4f v23; // [rsp+40h] [rbp-58h]
  hkQTransformf initialRelativeTransform; // [rsp+50h] [rbp-48h]
  __int64 v25; // [rsp+A8h] [rbp+10h]

  v3 = sectionIndex;
  v4 = 0;
  v5 = generators;
  v6 = sectionIndex + 1;
  v7 = this;
  if ( this->m_sections.m_size < sectionIndex + 1 )
  {
    v8 = this->m_sections.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < v6 )
    {
      v9 = 2 * v8;
      v10 = sectionIndex + 1;
      if ( v6 < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(
        (hkResult *)&v25,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_sections,
        v10,
        72);
    }
    v11 = v7->m_sections.m_size - v6 - 1;
    if ( v11 >= 0 )
    {
      v12 = &v7->m_sections.m_data[v6 + v11];
      do
      {
        hkaiOverlapManagerSection::~hkaiOverlapManagerSection(v12);
        --v12;
        --v11;
      }
      while ( v11 >= 0 );
    }
    v13 = v7->m_sections.m_size;
    v14 = v6 - (signed int)v13;
    if ( v6 - (signed int)v13 > 0 )
    {
      v15 = (signed __int64)&v7->m_sections.m_data[v13].m_generatorData.m_capacityAndFlags;
      do
      {
        if ( v15 != 28 )
        {
          *(_QWORD *)(v15 - 28) = 0i64;
          *(_DWORD *)(v15 - 20) = 0;
          *(_QWORD *)(v15 - 12) = 0i64;
          *(_DWORD *)(v15 - 4) = 0;
          *(_DWORD *)v15 = 2147483648;
          *(_QWORD *)(v15 + 4) = 0i64;
          *(_DWORD *)(v15 + 12) = 0;
          *(_DWORD *)(v15 + 16) = 2147483648;
          *(_QWORD *)(v15 + 20) = 0i64;
          *(_DWORD *)(v15 + 28) = 0;
          *(_DWORD *)(v15 + 32) = 2147483648;
          *(_DWORD *)(v15 + 36) = 0;
        }
        v15 += 72i64;
        --v14;
      }
      while ( v14 );
    }
    v7->m_sections.m_size = v6;
  }
  v16 = &v7->m_sections.m_data[v3];
  v17 = v7->m_navMeshCollection.m_pntr->m_instances.m_data;
  v18 = v17[v3].m_instancePtr;
  hkaiOverlapManagerSection::init(v16, v17[v3].m_instancePtr);
  hkQuaternionf::set(&v22, &v18->m_referenceFrame.m_transform.m_rotation);
  v23.m_quad = (__m128)v18->m_referenceFrame.m_transform.m_translation;
  if ( v5 && v5->m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = v5->m_data[v19].m_pntr;
      hkQTransformf::setMulInverseMul(&initialRelativeTransform, (hkQTransformf *)&v22, &v20->m_transform);
      v21 = (hkaiOverlapManagerSection::GeneratorData *)hkaiOverlapManagerSection::addDataForGenerator(
                                                          v16,
                                                          v20,
                                                          &initialRelativeTransform);
      hkaiOverlapManager::queryAndUpdateFacesForGenerator(v7, v3, v21, v20, &initialRelativeTransform);
      ++v4;
      ++v19;
    }
    while ( v4 < v5->m_size );
  }
}

// File Line: 340
// RVA: 0xBF5850
void __fastcall hkaiOverlapManager::unloadSection(hkaiOverlapManager *this, int sectionIndex)
{
  hkaiOverlapManagerSection::clearGeneratorData(&this->m_sections.m_data[sectionIndex]);
}

// File Line: 347
// RVA: 0xBF5870
void __fastcall hkaiOverlapManager::addSilhouetteGenerator(hkaiOverlapManager *this, hkaiSilhouetteGenerator *gen)
{
  int v2; // ebx
  hkaiSilhouetteGenerator *v3; // r15
  hkaiOverlapManager *v4; // rsi
  __int64 v5; // r14
  hkaiOverlapManagerSection *v6; // rbp
  hkaiNavMeshInstance *v7; // rdi
  hkaiOverlapManagerSection::GeneratorData *v8; // rax
  hkQuaternionf v9; // [rsp+30h] [rbp-58h]
  hkVector4f v10; // [rsp+40h] [rbp-48h]
  hkQTransformf initialRelativeTransform; // [rsp+50h] [rbp-38h]

  v2 = 0;
  v3 = gen;
  v4 = this;
  if ( this->m_sections.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = &v4->m_sections.m_data[v2];
      v7 = v4->m_navMeshCollection.m_pntr->m_instances.m_data[v5].m_instancePtr;
      if ( v7 )
      {
        hkQuaternionf::set(&v9, &v7->m_referenceFrame.m_transform.m_rotation);
        v10.m_quad = (__m128)v7->m_referenceFrame.m_transform.m_translation;
        hkQTransformf::setMulInverseMul(&initialRelativeTransform, (hkQTransformf *)&v9, &v3->m_transform);
        v8 = (hkaiOverlapManagerSection::GeneratorData *)hkaiOverlapManagerSection::addDataForGenerator(
                                                           v6,
                                                           v3,
                                                           &initialRelativeTransform);
        hkaiOverlapManager::queryAndUpdateFacesForGenerator(v4, v2, v8, v3, &initialRelativeTransform);
      }
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_sections.m_size );
  }
}

// File Line: 374
// RVA: 0xBF5AB0
void __fastcall hkaiOverlapManager::recomputeOverlapsForGenerator(hkaiOverlapManager *this, hkaiSilhouetteGenerator *gen)
{
  int v2; // ebx
  hkaiSilhouetteGenerator *v3; // rbp
  hkaiOverlapManager *v4; // rdi
  __int64 v5; // rsi
  hkaiOverlapManagerSection::GeneratorData *v6; // rax

  v2 = 0;
  v3 = gen;
  v4 = this;
  if ( this->m_sections.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      if ( v4->m_navMeshCollection.m_pntr->m_instances.m_data[v5].m_instancePtr )
      {
        v6 = hkaiOverlapManagerSection::getGeneratorData(&v4->m_sections.m_data[v2], v3);
        hkaiOverlapManager::queryAndUpdateFacesForGenerator(v4, v2, v6, v3, &v6->m_context.m_lastRelativeTransform);
      }
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_sections.m_size );
  }
}

// File Line: 390
// RVA: 0xBF5950
void __usercall hkaiOverlapManager::removeSilhouetteGenerator(hkaiOverlapManager *this@<rcx>, hkaiSilhouetteGenerator *gen@<rdx>, float a3@<xmm0>)
{
  int v3; // edi
  hkaiSilhouetteGenerator *v4; // r14
  hkaiOverlapManager *v5; // rsi
  hkReferencedObject *v6; // rcx
  char v7; // bp
  hkReferencedObject *v8; // rbx
  hkReferencedObject *v9; // rcx
  hkReferencedObject *v10; // r15
  float v11; // xmm6_4
  __int64 v12; // rbx
  hkaiOverlapManagerSection *v13; // rcx
  hkReferencedObject v14; // [rsp+30h] [rbp-68h]
  hkAabb v15; // [rsp+40h] [rbp-58h]
  hkReferencedObject *v16; // [rsp+A0h] [rbp+8h]

  v3 = 0;
  v4 = gen;
  v5 = this;
  LODWORD(v16) = 0;
  hkaiOverlapManager::getExtrudedAabbForGenerator(
    this,
    gen,
    &this->m_referenceFrameAndExtrusion,
    &hkQTransformfIdentity_storage,
    0i64,
    &v15);
  v6 = (hkReferencedObject *)&v5->m_priorityController.m_pntr->vfptr;
  *(_DWORD *)&v14.m_memSizeAndFlags = 0x1FFFF;
  v7 = 1;
  v14.vfptr = (hkBaseObjectVtbl *)&hkaiDefaultSilhouettePriorityController::`vftable;
  if ( v6 )
  {
    hkReferencedObject::addReference(v6);
    v8 = (hkReferencedObject *)&v5->m_priorityController.m_pntr->vfptr;
    v16 = (hkReferencedObject *)&v5->m_priorityController.m_pntr->vfptr;
    v9 = v16;
  }
  else
  {
    v7 = 2;
    hkReferencedObject::addReference(&v14);
    v9 = &v14;
    v16 = &v14;
    v8 = &v14;
  }
  v10 = v16;
  if ( v7 & 2 )
  {
    v7 &= 0xFDu;
    if ( v9 )
      hkReferencedObject::removeReference(v9);
  }
  if ( v7 & 1 && v8 )
    hkReferencedObject::removeReference(v8);
  if ( v5->m_maxCutFacesPerStep <= 0 )
  {
    v11 = *(float *)&FLOAT_1_0;
  }
  else
  {
    ((void (__fastcall *)(hkReferencedObject *, hkaiSilhouetteGenerator *, hkAabb *, hkaiReferenceFrameAndExtrusion *))v10->vfptr[2].__vecDelDtor)(
      v10,
      v4,
      &v15,
      &v5->m_referenceFrameAndExtrusion);
    v11 = a3;
  }
  if ( v5->m_sections.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = &v5->m_sections.m_data[v12];
      if ( v13->m_numOriginalFaces )
        hkaiOverlapManagerSection::removeDataForGenerator(v13, v4, v11);
      ++v3;
      ++v12;
    }
    while ( v3 < v5->m_sections.m_size );
  }
}

// File Line: 414
// RVA: 0xBF5B50
void __fastcall hkaiOverlapManager::updateOverlapsOfAllGenerators(hkaiOverlapManager *this, hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *generators, hkBitField *sectionsToUpdate, unsigned int updateFlags)
{
  hkaiOverlapManager *v4; // r13
  char v5; // si
  hkBitField *v6; // r14
  hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *v7; // r15
  _QWORD *v8; // rdi
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __int64 v12; // rbx
  bool v13; // zf
  _DWORD *v14; // rdx
  int v15; // edi
  hkLifoAllocator *v16; // rax
  int v17; // ecx
  char *v18; // r8
  signed int v19; // eax
  int v20; // eax
  int v21; // er9
  __int64 v22; // rcx
  _DWORD *v23; // rdi
  __m128 v24; // xmm0
  __m128 v25; // xmm6
  __int64 v26; // rsi
  __int64 v27; // r12
  int v28; // er14
  signed int v29; // ebx
  hkaiSilhouetteGenerator *v30; // rdi
  int v31; // er15
  unsigned __int64 v32; // rbx
  __int64 v33; // rax
  signed __int64 v34; // rdi
  int v35; // esi
  __int64 v36; // r14
  hkaiSilhouetteGenerator *v37; // rbx
  hkaiOverlapManagerSection::GeneratorData *v38; // rdi
  hkaiOverlapManagerSection *v39; // rdx
  char v40; // al
  __m128 v41; // xmm3
  __m128 v42; // xmm0
  __m128 v43; // xmm1
  _QWORD *v44; // rdi
  _QWORD *v45; // rcx
  unsigned __int64 v46; // rax
  signed __int64 v47; // rcx
  hkaiOverlapManagerSection *v48[2]; // [rsp+30h] [rbp-59h]
  __m128 array; // [rsp+40h] [rbp-49h]
  __m128 v50; // [rsp+50h] [rbp-39h]
  __int128 v51; // [rsp+60h] [rbp-29h]
  hkQuaternionf v52; // [rsp+70h] [rbp-19h]
  __int128 v53; // [rsp+80h] [rbp-9h]
  char v54; // [rsp+F0h] [rbp+67h]
  _QWORD *v55; // [rsp+F8h] [rbp+6Fh]
  _QWORD *v56; // [rsp+100h] [rbp+77h]
  hkResult result; // [rsp+108h] [rbp+7Fh]

  v4 = this;
  v5 = updateFlags;
  v6 = sectionsToUpdate;
  v7 = generators;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtupdateOverlaps";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = v7->m_size;
  if ( !v6 || (v13 = v6->m_storage.m_numBits == 0, v54 = 1, v13) )
    v54 = 0;
  v14 = 0i64;
  v15 = ((signed int)v12 + 31) >> 5;
  array.m128_u64[1] = 0i64;
  if ( v15 )
  {
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = v16->m_cur;
    v17 = (4 * v15 + 127) & 0xFFFFFF80;
    v18 = (char *)v14 + v17;
    if ( v17 > v16->m_slabSize || v18 > v16->m_end )
      v14 = hkLifoAllocator::allocateFromNewSlab(v16, v17);
    else
      v16->m_cur = v18;
  }
  array.m128_u64[1] = (unsigned __int64)v14;
  v19 = (v15 | 0x80000000) & 0x3FFFFFFF;
  if ( v19 < v15 )
  {
    v20 = 2 * v19;
    v21 = ((signed int)v12 + 31) >> 5;
    if ( v15 < v20 )
      v21 = v20;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m128_u16[4],
      v21,
      4);
    v14 = (_DWORD *)array.m128_u64[1];
  }
  if ( v15 - 1 >= 0 )
  {
    v22 = (unsigned int)v15;
    v23 = v14;
    while ( v22 )
    {
      *v23 = 0;
      ++v23;
      --v22;
    }
  }
  result.m_enum = v5 & 1;
  if ( v5 & 1 )
    v24 = _mm_sub_ps((__m128)0i64, query.m_quad);
  else
    v24 = _mm_shuffle_ps((__m128)LODWORD(v4->m_hasMovedTolerance), (__m128)LODWORD(v4->m_hasMovedTolerance), 0);
  *(__m128 *)v48 = v24;
  v25 = v24;
  v26 = 0i64;
  v27 = v12;
  v28 = 0;
  v29 = 1;
  _mm_store_si128((__m128i *)v48, (__m128i)v4->m_referenceFrameAndExtrusion.m_up.m_quad);
  if ( v27 > 0 )
  {
    do
    {
      v30 = v7->m_data[v26].m_pntr;
      v30->vfptr[3].__vecDelDtor((hkBaseObject *)&v30->vfptr, (unsigned int)v48);
      if ( ((unsigned __int8 (__fastcall *)(hkaiSilhouetteGenerator *))v30->vfptr[4].__first_virtual_table_function__)(v30) )
        *(_DWORD *)(array.m128_u64[1] + 4 * ((signed __int64)v28 >> 5)) |= v29;
      v29 = __ROL4__(v29, 1);
      ++v26;
      ++v28;
    }
    while ( v26 < v27 );
  }
  v31 = 0;
  if ( v4->m_sections.m_size > 0 )
  {
    v32 = 0i64;
    array.m128_u64[0] = 0i64;
    do
    {
      if ( !v54 || (*(_DWORD *)(*v56 + 4 * ((signed __int64)v31 >> 5)) >> (v31 & 0x1F)) & 1 )
      {
        v48[0] = &v4->m_sections.m_data[v31];
        v33 = *(__int64 *)((char *)&v4->m_navMeshCollection.m_pntr->m_instances.m_data->m_instancePtr + v32);
        v48[0] = (hkaiOverlapManagerSection *)v33;
        if ( v33 )
        {
          v34 = v33 + 112;
          hkQuaternionf::set(&v52, (hkRotationf *)(v33 + 112));
          v35 = 0;
          v36 = 0i64;
          v53 = *(_OWORD *)(v34 + 48);
          if ( v27 > 0 )
          {
            do
            {
              v37 = *(hkaiSilhouetteGenerator **)(*v55 + 8 * v36);
              v38 = hkaiOverlapManagerSection::getGeneratorData(v48[0], *(hkaiSilhouetteGenerator **)(*v55 + 8 * v36));
              hkQTransformf::setMulInverseMul((hkQTransformf *)&array, (hkQTransformf *)&v52, &v37->m_transform);
              v39 = v48[0];
              v38->m_context.m_generatedLastFrame.m_bool = v38->m_context.m_generatingThisFrame.m_bool;
              _mm_store_si128((__m128i *)&v51, (__m128i)v4->m_referenceFrameAndExtrusion.m_up.m_quad);
              v40 = ((__int64 (__fastcall *)(hkaiSilhouetteGenerator *, hkaiOverlapManagerSection *, __int128 *))v37->vfptr[5].__vecDelDtor)(
                      v37,
                      v39,
                      &v51);
              v13 = result.m_enum == 0;
              v38->m_context.m_generatingThisFrame.m_bool = v40;
              if ( !v13
                || (v38->m_context.m_generatedLastFrame.m_bool != 0) != (v40 != 0)
                || v40
                && ((*(_DWORD *)(array.m128_u64[1] + 4 * ((signed __int64)v35 >> 5)) >> (v35 & 0x1F)) & 1
                 || ((v41 = v38->m_context.m_lastRelativeTransform.m_rotation.m_vec.m_quad,
                      v42 = _mm_mul_ps(array, v41),
                      v43 = _mm_add_ps(_mm_shuffle_ps(v42, v42, 78), v42),
                      _mm_movemask_ps(
                        _mm_cmpltps(
                          (__m128)_mm_srli_epi32(
                                    _mm_slli_epi32(
                                      (__m128i)_mm_sub_ps(
                                                 v41,
                                                 _mm_xor_ps(
                                                   (__m128)_mm_slli_epi32(
                                                             _mm_srli_epi32(
                                                               (__m128i)_mm_add_ps(_mm_shuffle_ps(v43, v43, 177), v43),
                                                               0x1Fu),
                                                             0x1Fu),
                                                   array)),
                                      1u),
                                    1u),
                          v25)) != 15)
                  || (_mm_movemask_ps(
                        _mm_cmpltps(
                          (__m128)_mm_srli_epi32(
                                    _mm_slli_epi32(
                                      (__m128i)_mm_sub_ps(
                                                 v38->m_context.m_lastRelativeTransform.m_translation.m_quad,
                                                 v50),
                                      1u),
                                    1u),
                          v25)) & 7) != 7)
                 && hkaiSilhouetteGenerator::hasMovedAgainstSection(
                      v37,
                      &v38->m_context.m_lastRelativeTransform,
                      (hkQTransformf *)&array)) )
              {
                v38->m_context.m_lastRelativeTransform.m_rotation.m_vec.m_quad = array;
                v38->m_context.m_lastRelativeTransform.m_translation.m_quad = v50;
                hkaiOverlapManager::queryAndUpdateFacesForGenerator(v4, v31, v38, v37, (hkQTransformf *)&array);
              }
              ++v36;
              ++v35;
            }
            while ( v36 < v27 );
            v32 = array.m128_u64[0];
          }
        }
      }
      v32 += 48i64;
      ++v31;
      array.m128_u64[0] = v32;
    }
    while ( v31 < v4->m_sections.m_size );
  }
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&array.m128_u16[4]);
  v44 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v45 = (_QWORD *)v44[1];
  if ( (unsigned __int64)v45 < v44[3] )
  {
    *v45 = "Et";
    v46 = __rdtsc();
    v47 = (signed __int64)(v45 + 2);
    *(_DWORD *)(v47 - 8) = v46;
    v44[1] = v47;
  }
}

// File Line: 619
// RVA: 0xBF7AB0
signed __int64 __fastcall hkaiOverlapManager::testLocalAabbAgainstFace(hkAabb *aabbLocal, hkaiNavMeshInstance *meshInstance, int faceIndex)
{
  hkaiNavMesh *v3; // rdx
  signed __int64 result; // rax

  v3 = meshInstance->m_originalMesh.m_pntr;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(v3->m_aabb.m_min.m_quad, aabbLocal->m_max.m_quad),
            _mm_cmpleps(aabbLocal->m_min.m_quad, v3->m_aabb.m_max.m_quad))) & 7) == 7 )
    result = hkaiNavMeshUtils::faceAabbCheck(aabbLocal, v3, faceIndex);
  else
    result = 0i64;
  return result;
}

// File Line: 694
// RVA: 0xBF6110
void __fastcall hkaiOverlapManager::getUpdatedFaces(hkaiOverlapManager *this, hkaiNavMeshCutter *cutter, hkArray<unsigned int,hkContainerTempAllocator> *cutFaceKeysOut, hkArray<unsigned int,hkContainerTempAllocator> *uncutFaceKeysOut, hkBitField *sectionsToUpdate)
{
  hkaiOverlapManager *v5; // r15
  _QWORD *v6; // r10
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  _QWORD *v10; // rax
  char v11; // bl
  int v12; // er9
  int v13; // er12
  __int64 v14; // rdi
  __int64 v15; // r13
  __int64 v16; // r14
  __int64 v17; // rsi
  int v18; // edx
  signed __int64 v19; // rcx
  int v20; // er9
  _DWORD *v21; // rax
  int v22; // ebx
  __int64 v23; // r8
  bool v24; // r9
  char *v25; // rax
  bool v26; // al
  unsigned int v27; // xmm6_4
  unsigned int *v28; // rdx
  unsigned int v29; // xmm0_4
  int v30; // er8
  int v31; // er10
  signed __int64 v32; // rcx
  _DWORD *v33; // rdx
  bool v34; // sf
  hkResultEnum v35; // er9
  bool v36; // zf
  int v37; // esi
  __int64 v38; // r10
  __int64 v39; // r11
  __int64 v40; // r14
  __int64 v41; // rbx
  int v42; // er8
  int v43; // eax
  int v44; // ecx
  int index; // er15
  __int64 v46; // r12
  signed __int64 v47; // r13
  unsigned int v48; // ecx
  int v49; // er8
  __int64 v50; // r9
  int v51; // ecx
  int v52; // edx
  int v53; // eax
  hkIntRealPair *v54; // rax
  hkaiNavMesh::Face *v55; // rdi
  int v56; // er11
  char *v57; // rax
  unsigned int *v58; // rdx
  unsigned int v59; // xmm0_4
  __int16 v60; // si
  int v61; // ebx
  int v62; // er12
  hkaiNavMesh::Edge *v63; // r13
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v64; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v65; // r8
  hkaiNavMesh::Edge *v66; // rax
  unsigned int v67; // edx
  unsigned int v68; // eax
  int v69; // ecx
  __int64 v70; // rdx
  unsigned int v71; // eax
  int v72; // ecx
  signed __int64 v73; // rax
  int v74; // edx
  unsigned int *v75; // rdx
  unsigned int v76; // xmm0_4
  __int64 v77; // rbx
  int v78; // eax
  int v79; // eax
  int v80; // er9
  hkArray<unsigned int,hkContainerTempAllocator> *v81; // r10
  int v82; // eax
  int v83; // eax
  int v84; // er9
  __int64 v85; // rdi
  __int64 v86; // rbx
  float v87; // edx
  int v88; // er9
  __int64 v89; // rax
  _QWORD *v90; // rax
  _QWORD *v91; // rcx
  _QWORD *v92; // r8
  unsigned __int64 v93; // rax
  signed __int64 v94; // rcx
  char v95; // [rsp+30h] [rbp-C8h]
  char v96; // [rsp+31h] [rbp-C7h]
  char v97; // [rsp+32h] [rbp-C6h]
  float *array; // [rsp+38h] [rbp-C0h]
  int v99; // [rsp+40h] [rbp-B8h]
  int v100; // [rsp+44h] [rbp-B4h]
  int v101; // [rsp+48h] [rbp-B0h]
  __int64 v102; // [rsp+50h] [rbp-A8h]
  int v103; // [rsp+58h] [rbp-A0h]
  __int64 v104; // [rsp+60h] [rbp-98h]
  hkResult result; // [rsp+68h] [rbp-90h]
  int v106; // [rsp+6Ch] [rbp-8Ch]
  __int64 v107; // [rsp+70h] [rbp-88h]
  FacePriorityPair entry; // [rsp+78h] [rbp-80h]
  __int64 v109; // [rsp+88h] [rbp-70h]
  __int64 v110; // [rsp+90h] [rbp-68h]
  FacePriorityPair v111; // [rsp+98h] [rbp-60h]
  FacePriorityPair v112; // [rsp+A8h] [rbp-50h]
  hkaiOverlapManager *retaddr; // [rsp+118h] [rbp+20h]
  hkaiNavMeshCutter *v114; // [rsp+120h] [rbp+28h]
  hkaiNavMeshCutter *v115; // [rsp+128h] [rbp+30h]
  hkArray<unsigned int,hkContainerTempAllocator> *v116; // [rsp+130h] [rbp+38h]
  hkIntRealPair key; // [rsp+138h] [rbp+40h]

  key = (hkIntRealPair)uncutFaceKeysOut;
  v116 = cutFaceKeysOut;
  v115 = cutter;
  v114 = (hkaiNavMeshCutter *)this;
  v5 = this;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TthkaiOverlapManager::getUpdatedFaces";
    v8 = __rdtsc();
    v9 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v9 - 8) = v8;
    v6[1] = v9;
  }
  v10 = (_QWORD *)key;
  v11 = *(_QWORD *)&key && *(_DWORD *)(*(_QWORD *)&key + 16i64);
  v12 = v5->m_sections.m_size;
  v95 = v11;
  array = 0i64;
  v99 = 0;
  v100 = 2147483648;
  v101 = v12;
  if ( v12 > 0 )
  {
    if ( v12 < 0 )
      v12 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v12, 12);
    v10 = (_QWORD *)key;
  }
  v13 = 0;
  if ( SLODWORD(v5->m_navMeshCollection.m_pntr) > 0 )
  {
    v14 = 0i64;
    v15 = 0i64;
    do
    {
      if ( !v11 || (*(_DWORD *)(*v10 + 4 * ((signed __int64)v13 >> 5)) >> (v13 & 0x1F)) & 1 )
      {
        v16 = *(_QWORD *)(v15 + *(_QWORD *)(*(_QWORD *)&v5->m_referenceFrameAndExtrusion.m_cellExtrusion + 32i64));
        if ( v16 )
        {
          v17 = *(_QWORD *)&v5->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage;
          v18 = 0;
          v19 = 0i64;
          v20 = *(_DWORD *)(v14 + v17 + 56) - 1;
          if ( v20 >= 0 )
          {
            v21 = *(_DWORD **)(v14 + v17 + 48);
            do
            {
              if ( *v21 != -1 )
                break;
              ++v19;
              ++v18;
              v21 += 2;
            }
            while ( v19 <= v20 );
          }
          v22 = v18;
          if ( v18 <= v20 )
          {
            while ( 1 )
            {
              v23 = (signed int)*(_QWORD *)(*(_QWORD *)(v14 + v17 + 48) + 8i64 * v22);
              v110 = *(_QWORD *)(*(_QWORD *)(v14 + v17 + 48) + 8i64 * v22);
              v24 = *(_DWORD *)(*(_QWORD *)(v14 + v17 + 32) + 16 * v23 + 8) != 0;
              if ( *(_DWORD *)(v16 + 328) )
              {
                v25 = &v96;
                v96 = *(_BYTE *)(v23 + *(_QWORD *)(v16 + 320));
              }
              else
              {
                v97 = 0;
                v25 = &v97;
              }
              v26 = v24 || *v25 & 4;
              v27 = HIDWORD(v110);
              entry.m_priority = *((float *)&v110 + 1);
              entry.m_faceKey = v26;
              if ( v101 <= 0 )
              {
                if ( v99 == (v100 & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 12);
                v28 = (unsigned int *)&array[3 * v99];
                if ( v28 )
                {
                  *v28 = entry.m_faceKey;
                  v29 = entry.m_faceKey;
                  v28[1] = v27;
                  v28[2] = v29;
                }
                ++v99;
                goto LABEL_38;
              }
              if ( v99 < v101 )
                goto LABEL_37;
              if ( *((float *)&v110 + 1) > array[1] )
                break;
LABEL_38:
              v30 = v22 + 1;
              v31 = *(_DWORD *)(v14 + v17 + 56) - 1;
              v32 = v22 + 1;
              if ( v32 <= v31 )
              {
                v33 = (_DWORD *)(*(_QWORD *)(v14 + v17 + 48) + 8i64 * v30);
                do
                {
                  if ( *v33 != -1 )
                    break;
                  ++v32;
                  ++v30;
                  v33 += 2;
                }
                while ( v32 <= v31 );
              }
              v22 = v30;
              if ( v30 > v31 )
              {
                v5 = retaddr;
                goto LABEL_44;
              }
            }
            hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::removeEntry(
              (hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *)&array,
              0);
LABEL_37:
            hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(
              (hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *)&array,
              &entry);
            goto LABEL_38;
          }
LABEL_44:
          v11 = v95;
        }
      }
      v10 = (_QWORD *)key;
      ++v13;
      v15 += 48i64;
      v14 += 72i64;
    }
    while ( v13 < SLODWORD(v5->m_navMeshCollection.m_pntr) );
  }
  if ( v101 > 0 && v99 >= v101 )
  {
    v34 = (signed int)((_QWORD)v5->m_sections.m_data & 0x8000000F) < 0;
    v35 = (_QWORD)v5->m_sections.m_data & 0x8000000F;
    result.m_enum = (_QWORD)v5->m_sections.m_data & 0x8000000F;
    if ( v34 )
    {
      v35 = (((_BYTE)v35 - 1) | 0xFFFFFFF0) + 1;
      result.m_enum = v35;
    }
    v36 = LODWORD(v5->m_navMeshCollection.m_pntr) == 0;
    v34 = SLODWORD(v5->m_navMeshCollection.m_pntr) < 0;
    v37 = 0;
    v106 = 0;
    if ( !v34 && !v36 )
    {
      v38 = 0i64;
      v102 = 0i64;
      v39 = 0i64;
      v110 = 0i64;
      while ( 1 )
      {
        v40 = *(_QWORD *)(v39 + *(_QWORD *)(*(_QWORD *)&v5->m_referenceFrameAndExtrusion.m_cellExtrusion + 32i64));
        if ( v40 )
          break;
LABEL_121:
        ++v37;
        v39 += 48i64;
        v38 += 72i64;
        v106 = v37;
        v110 = v39;
        v102 = v38;
        if ( v37 >= SLODWORD(v5->m_navMeshCollection.m_pntr) )
          goto LABEL_122;
      }
      v41 = *(_QWORD *)&v5->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage;
      v42 = *(_DWORD *)(v38 + v41 + 8);
      v104 = *(_QWORD *)&v5->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage;
      v43 = (v42 + 15) / 16;
      v44 = v43 * (v35 + 1);
      index = v35 * v43;
      if ( v42 < v44 )
        v44 = v42;
      v46 = index;
      v103 = v35 * v43;
      v109 = index;
      *(_QWORD *)&entry.m_faceKey = v44;
      if ( index >= (signed __int64)v44 )
      {
LABEL_120:
        v5 = retaddr;
        goto LABEL_121;
      }
      v47 = 16i64 * index;
      v107 = 16i64 * index;
      v48 = -1640531535 * index;
      entry.m_shouldCut = -1640531535 * index;
      while ( 1 )
      {
        v49 = *(_DWORD *)(v38 + v41 + 56) - 1;
        if ( v49 <= 0
          || (v50 = *(_QWORD *)(v38 + v41 + 48), v51 = v49 & v48, v52 = *(_DWORD *)(v50 + 8i64 * v51), v52 == -1) )
        {
LABEL_61:
          v53 = *(_DWORD *)(v38 + v41 + 56);
        }
        else
        {
          while ( v52 != index )
          {
            v51 = v49 & (v51 + 1);
            v52 = *(_DWORD *)(v50 + 8i64 * v51);
            if ( v52 == -1 )
              goto LABEL_61;
          }
          v53 = v51;
        }
        if ( v53 <= v49 )
          goto LABEL_118;
        if ( *(_DWORD *)(v40 + 328) )
        {
          v54 = &key;
          LOBYTE(key.m_key) = *(_BYTE *)(v46 + *(_QWORD *)(v40 + 320));
        }
        else
        {
          v97 = 0;
          v54 = (hkIntRealPair *)&v97;
        }
        if ( !(v54->m_key & 1) || *(_DWORD *)(*(_QWORD *)(v38 + v41 + 32) + v47 + 8) )
          goto LABEL_118;
        v55 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__9(
                *(hkaiNavMesh::Face **)(v40 + 16),
                *(_DWORD *)(v40 + 24),
                (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v40 + 240),
                (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v40 + 272),
                (hkArray<int,hkContainerHeapAllocator> *)(v40 + 224),
                index);
        if ( v56 )
        {
          v57 = &v96;
          v96 = *(_BYTE *)(v46 + *(_QWORD *)(v40 + 320));
        }
        else
        {
          v95 = 0;
          v57 = &v95;
        }
        if ( !(*v57 & 4) )
          break;
        if ( (unsigned int)hkaiNavMeshCutter::getNumCutKeysFromOriginal(v114, index | (unsigned int)(v37 << 22)) != 1 )
        {
          v111.m_priority = 0.0;
          v111.m_faceKey = index | (v37 << 22);
          v111.m_shouldCut = 1;
          if ( v101 > 0 )
          {
            if ( v99 >= v101 )
            {
              if ( array[1] < 0.0 )
              {
                hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::removeEntry(
                  (hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *)&array,
                  0);
                hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(
                  (hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *)&array,
                  &v111);
              }
            }
            else
            {
              hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(
                (hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *)&array,
                &v111);
            }
          }
          else
          {
            if ( v99 == (v100 & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 12);
            v58 = (unsigned int *)&array[3 * v99];
            if ( v58 )
            {
              *v58 = v111.m_faceKey;
              v59 = v111.m_shouldCut;
              v58[1] = 0;
              v58[2] = v59;
            }
            ++v99;
          }
        }
LABEL_117:
        v41 = v104;
        v38 = v102;
LABEL_118:
        ++v46;
        ++index;
        v48 = entry.m_shouldCut - 1640531535;
        v47 += 16i64;
        v103 = index;
        entry.m_shouldCut -= 1640531535;
        v109 = v46;
        v107 = v47;
        if ( v46 >= *(_QWORD *)&entry.m_faceKey )
        {
          v35 = result.m_enum;
          v39 = v110;
          goto LABEL_120;
        }
      }
      v60 = v55->m_numUserEdges;
      if ( v60 <= 0 )
        v61 = v55->m_startEdgeIndex;
      else
        v61 = v55->m_startUserEdgeIndex;
      if ( v61 == -1 )
      {
LABEL_106:
        v37 = v106;
        v112.m_priority = 0.0;
        v112.m_shouldCut = 0;
        v112.m_faceKey = index | (v106 << 22);
        if ( v101 > 0 )
        {
          if ( v99 >= v101 )
          {
            if ( array[1] < 0.0 )
            {
              hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::removeEntry(
                (hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *)&array,
                0);
              hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(
                (hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *)&array,
                &v112);
            }
          }
          else
          {
            hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(
              (hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *)&array,
              &v112);
          }
        }
        else
        {
          if ( v99 == (v100 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 12);
          v75 = (unsigned int *)&array[3 * v99];
          if ( v75 )
          {
            *v75 = v112.m_faceKey;
            v76 = v112.m_shouldCut;
            v75[1] = 0;
            v75[2] = v76;
          }
          ++v99;
        }
        goto LABEL_117;
      }
      v62 = *(_DWORD *)(v40 + 40);
      v63 = *(hkaiNavMesh::Edge **)(v40 + 32);
      v64 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v40 + 288);
      v65 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v40 + 256);
      while ( 1 )
      {
        v66 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__9(
                v63,
                v62,
                v65,
                v64,
                (hkArray<int,hkContainerHeapAllocator> *)(v40 + 208),
                v61);
        if ( v66->m_oppositeEdge != -1 )
        {
          v67 = v66->m_oppositeFace;
          if ( v66->m_flags.m_storage & 0x40 )
            v68 = v67 & 0xFFC00000;
          else
            v68 = *(_DWORD *)(v40 + 472) << 22;
          v69 = v68 | v67 & 0x3FFFFF;
          v36 = v67 == -1;
          v70 = *(_QWORD *)&retaddr->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage;
          if ( v36 )
            v69 = -1;
          v71 = v69;
          v72 = v69 & 0x3FFFFF;
          v73 = 9i64 * (v71 >> 22);
          if ( v72 < *(_DWORD *)(v70 + 8 * v73 + 40) )
          {
            if ( *(_DWORD *)(*(_QWORD *)(v70 + 8 * v73 + 32) + 16i64 * v72 + 8) )
            {
              index = v103;
              v46 = v109;
              v47 = v107;
              v37 = v106;
              goto LABEL_117;
            }
          }
        }
        v74 = v55->m_startUserEdgeIndex;
        if ( v61 >= v74 && v61 < v60 + v74 - 1 )
          goto LABEL_103;
        if ( v61 != v60 + v74 - 1 )
          break;
        v61 = v55->m_startEdgeIndex;
LABEL_104:
        if ( v61 == -1 )
          goto LABEL_105;
      }
      if ( v61 < v55->m_startEdgeIndex || v61 >= v55->m_numEdges + v55->m_startEdgeIndex - 1 )
      {
LABEL_105:
        index = v103;
        v46 = v109;
        v47 = v107;
        goto LABEL_106;
      }
LABEL_103:
      ++v61;
      goto LABEL_104;
    }
  }
LABEL_122:
  v77 = v99;
  v78 = *(_DWORD *)(&v115->m_referenceCount + 1) & 0x3FFFFFFF;
  if ( v78 < v99 )
  {
    v79 = 2 * v78;
    v80 = v99;
    if ( v99 < v79 )
      v80 = v79;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      v115,
      v80,
      4);
  }
  v81 = v116;
  v82 = v116->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v82 < (signed int)v77 )
  {
    v83 = 2 * v82;
    v84 = v77;
    if ( (signed int)v77 < v83 )
      v84 = v83;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      v116,
      v84,
      4);
    v81 = v116;
  }
  v85 = v77;
  if ( (signed int)v77 > 0 )
  {
    key.m_value = 0.0;
    v86 = 0i64;
    do
    {
      v87 = array[v86];
      v88 = LODWORD(array[v86]) & 0x3FFFFF;
      if ( LODWORD(array[v86 + 2]) )
        *((float *)&v115->vfptr->__vecDelDtor + (signed int)(*(_DWORD *)&v115->m_memSizeAndFlags)++) = v87;
      else
        *(float *)&v81->m_data[v81->m_size++] = v87;
      v89 = *(_QWORD *)&v5->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage;
      key.m_key = v88;
      hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::remove(
        (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)(v89
                                                                                        + 8
                                                                                        * ((unsigned int)(LODWORD(v87) >> 22)
                                                                                         + 8i64
                                                                                         * (unsigned int)(LODWORD(v87) >> 22)
                                                                                         + 6)),
        (hkResult *)&retaddr,
        key);
      v81 = v116;
      v86 += 3i64;
      --v85;
    }
    while ( v85 );
  }
  v99 = 0;
  if ( v100 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      12 * (v100 & 0x3FFFFFFF));
  array = 0i64;
  v100 = 2147483648;
  v90 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v91 = (_QWORD *)v90[1];
  v92 = v90;
  if ( (unsigned __int64)v91 < v90[3] )
  {
    *v91 = "Et";
    v93 = __rdtsc();
    v94 = (signed __int64)(v91 + 2);
    *(_DWORD *)(v94 - 8) = v93;
    v92[1] = v94;
  }
}

// File Line: 887
// RVA: 0xBF6AB0
void __fastcall hkaiOverlapManager::gatherSilhouettesForFace(hkaiOverlapManager *this, unsigned int faceKey, hkaiSilhouetteGenerationParameters *genParamsIn, hkArray<hkArray<hkVector4f,hkContainerTempAllocator>,hkContainerTempAllocator> *silsOut, hkArray<int,hkContainerTempAllocator> *silsMaterials)
{
  int v5; // er12
  hkaiOverlapManager *v6; // rdi
  __int64 v7; // rax
  hkReferencedObject *v8; // rcx
  hkaiOverlapManagerSection *v9; // r13
  int v10; // er14
  hkArray<hkArray<hkVector4f,hkContainerTempAllocator>,hkContainerTempAllocator> *v11; // rsi
  char v12; // r15
  hkReferencedObject *v13; // rbx
  hkReferencedObject *v14; // rcx
  int v15; // eax
  signed __int64 v16; // r13
  __int64 v17; // rcx
  hkSimdFloat32 *instance; // r10
  char v19; // bl
  char v20; // bl
  char v21; // al
  int v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  __int128 v25; // xmm1
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm6
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  __m128 v31; // xmm2
  __m128 v32; // xmm6
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm2
  hkaiSilhouettePriorityController *v36; // r8
  hkaiSilhouetteGeneratorSectionContext *v37; // rax
  signed __int64 v38; // r15
  _DWORD *v39; // rbx
  hkaiSilhouetteGeneratorSectionContext *v40; // rdx
  int v41; // edi
  int v42; // er14
  hkaiNavMeshInstance *meshInstance; // [rsp+30h] [rbp-98h]
  hkaiNavMeshInstance *meshInstancea; // [rsp+30h] [rbp-98h]
  int v45; // [rsp+38h] [rbp-90h]
  int faceIndex[4]; // [rsp+40h] [rbp-88h]
  hkaiSilhouettePriorityController *controller; // [rsp+50h] [rbp-78h]
  int v48; // [rsp+58h] [rbp-70h]
  float v49; // [rsp+5Ch] [rbp-6Ch]
  hkReferencedObject v50; // [rsp+60h] [rbp-68h]
  __int128 v51; // [rsp+70h] [rbp-58h]
  hkQuaternionf v52; // [rsp+88h] [rbp-40h]
  hkVector4f referenceAxis; // [rsp+98h] [rbp-30h]
  hkaiOverlapManager *v54; // [rsp+118h] [rbp+50h]
  unsigned int v55; // [rsp+120h] [rbp+58h]
  hkaiSilhouetteGeneratorSectionContext *generatorContexts; // [rsp+128h] [rbp+60h]
  void *array; // [rsp+138h] [rbp+70h]

  v5 = 0;
  v6 = this;
  *(_QWORD *)faceIndex = faceKey >> 22;
  v7 = *(_QWORD *)&this->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage;
  v8 = *(hkReferencedObject **)&this->m_maxCutFacesPerStep;
  v9 = (hkaiOverlapManagerSection *)(v7 + 72i64 * *(_QWORD *)faceIndex);
  v10 = faceKey & 0x3FFFFF;
  v11 = silsOut;
  referenceAxis.m_quad.m128_u64[0] = v7 + 72i64 * *(_QWORD *)faceIndex;
  v55 = faceKey & 0x3FFFFF;
  *(_DWORD *)&v50.m_memSizeAndFlags = 0x1FFFF;
  v50.vfptr = (hkBaseObjectVtbl *)&hkaiDefaultSilhouettePriorityController::`vftable;
  if ( v8 )
  {
    v12 = 1;
    hkReferencedObject::addReference(v8);
    v13 = *(hkReferencedObject **)&v6->m_maxCutFacesPerStep;
    meshInstance = *(hkaiNavMeshInstance **)&v6->m_maxCutFacesPerStep;
    v14 = *(hkReferencedObject **)&v6->m_maxCutFacesPerStep;
  }
  else
  {
    v12 = 2;
    hkReferencedObject::addReference(&v50);
    v14 = &v50;
    meshInstance = (hkaiNavMeshInstance *)&v50;
    v13 = &v50;
  }
  controller = (hkaiSilhouettePriorityController *)meshInstance;
  if ( v12 & 2 )
  {
    v12 &= 0xFDu;
    if ( v14 )
      hkReferencedObject::removeReference(v14);
  }
  if ( v12 & 1 && v13 )
    hkReferencedObject::removeReference(v13);
  v15 = hkaiOverlapManagerSection::sortGeneratorsForFace(v9, controller, v10);
  v51 = 0i64;
  v45 = v15;
  faceIndex[2] = -1082130432;
  v16 = *(_QWORD *)(referenceAxis.m_quad.m128_u64[0] + 32) + 16i64 * v10;
  v17 = *(_QWORD *)&v6->m_referenceFrameAndExtrusion.m_cellExtrusion;
  faceIndex[3] = -1082130432;
  instance = *(hkSimdFloat32 **)(*(_QWORD *)(v17 + 32) + 48i64 * *(_QWORD *)faceIndex);
  meshInstancea = (hkaiNavMeshInstance *)instance;
  v19 = *(_BYTE *)(instance[6].m_real.m128_u64[0] + 120);
  v48 = 0;
  *(hkReferencedObject *)((char *)&v50 + 8) = 0i64;
  *(__int128 *)((char *)&v51 + 8) = 0i64;
  v49 = FLOAT_0_40000001;
  v50.vfptr = (hkBaseObjectVtbl *)__PAIR__(LODWORD(FLOAT_0_0049999999), LODWORD(FLOAT_50_0));
  v20 = v19 & 1;
  if ( v20 )
  {
    v21 = v6->m_referenceFrameAndExtrusion.m_up.m_quad.m128_i8[8];
    v22 = v6->m_referenceFrameAndExtrusion.m_up.m_quad.m128_i32[1];
    faceIndex[2] = v6->m_referenceFrameAndExtrusion.m_up.m_quad.m128_i32[0];
    faceIndex[3] = v22;
    LOBYTE(controller) = v21;
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&controller,
      instance,
      (hkaiNavMeshInstance *)(unsigned int)v10,
      (__int64)faceIndex);
    v51 = *(_OWORD *)faceIndex;
    v23 = generatorContexts->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_f32[1];
    v48 = generatorContexts->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_i32[0];
    v24 = generatorContexts->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_f32[2];
    v49 = v23;
    v50.vfptr = (hkBaseObjectVtbl *)__PAIR__(
                                      generatorContexts->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_i32[3],
                                      LODWORD(v24));
    *(hkReferencedObject *)((char *)&v50 + 8) = (hkReferencedObject)generatorContexts->m_lastRelativeTransform.m_translation;
    v25 = *(_OWORD *)&generatorContexts->m_generator;
    v52.m_vec.m_quad = (__m128)generatorContexts[1].m_lastRelativeTransform.m_rotation;
    *(__int128 *)((char *)&v51 + 8) = v25;
    v26 = _mm_shuffle_ps(*(__m128 *)faceIndex, _mm_unpackhi_ps(*(__m128 *)faceIndex, (__m128)0i64), 196);
    v27 = _mm_shuffle_ps(v26, v26, 241);
    v28 = _mm_shuffle_ps(v26, v26, 206);
    v29 = _mm_mul_ps(v28, v28);
    v30 = _mm_mul_ps(v27, v27);
    v31 = _mm_cmpltps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
              _mm_shuffle_ps(v30, v30, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
              _mm_shuffle_ps(v29, v29, 170)));
    v32 = _mm_xor_ps(
            _mm_or_ps(_mm_and_ps(v28, v31), _mm_andnot_ps(v31, v27)),
            (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    v33 = _mm_mul_ps(v32, v32);
    v34 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
            _mm_shuffle_ps(v33, v33, 170));
    v35 = _mm_rsqrt_ps(v34);
    referenceAxis.m_quad = _mm_mul_ps(
                             v32,
                             _mm_andnot_ps(
                               _mm_cmpleps(v34, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v35))));
    hkaiSilhouetteReferenceFrame::set(
      (hkaiSilhouetteReferenceFrame *)&v50.m_memSizeAndFlags,
      (hkVector4f *)faceIndex,
      &referenceAxis);
    instance = (hkSimdFloat32 *)meshInstancea;
    v36 = (hkaiSilhouettePriorityController *)&v51;
  }
  else
  {
    v36 = (hkaiSilhouettePriorityController *)&v6->vfptr;
  }
  v37 = (hkaiSilhouetteGeneratorSectionContext *)&v48;
  if ( !v20 )
    v37 = generatorContexts;
  controller = v36;
  v38 = 0i64;
  *(_QWORD *)faceIndex = v37;
  if ( *(_DWORD *)(v16 + 8) > 0 )
  {
    v39 = array;
    do
    {
      v40 = *(hkaiSilhouetteGeneratorSectionContext **)(*(_QWORD *)v16 + 8 * v38);
      generatorContexts = v40;
      if ( v40->m_generatingThisFrame.m_bool )
      {
        hkaiOverlapManager::getExtrudedAabbForGenerator(
          (hkaiOverlapManager *)((char *)v6 - 16),
          v40->m_generator,
          (hkaiReferenceFrameAndExtrusion *)v36,
          &v40->m_lastRelativeTransform,
          (hkaiNavMeshInstance *)instance,
          (hkAabb *)&referenceAxis);
        if ( hkaiOverlapManager::testLocalAabbAgainstFace((hkAabb *)&referenceAxis, meshInstancea, v10) )
        {
          v41 = v11->m_size;
          hkaiSilhouetteMergerUtils::createNonmergedCompoundSilhouettes(
            &generatorContexts,
            1,
            *(hkaiSilhouetteGenerationParameters **)faceIndex,
            v11);
          if ( v38 < v45 )
            v42 = -1;
          else
            v42 = generatorContexts->m_generator->m_materialId;
          for ( ; v41 < v11->m_size; ++v39[2] )
          {
            if ( v39[2] == (v39[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v39, 4);
            ++v41;
            *(_DWORD *)(*(_QWORD *)v39 + 4i64 * (signed int)v39[2]) = v42;
          }
          v10 = v55;
          v6 = v54;
        }
      }
      instance = (hkSimdFloat32 *)meshInstancea;
      v36 = controller;
      ++v5;
      ++v38;
    }
    while ( v5 < *(_DWORD *)(v16 + 8) );
  }
}

// File Line: 984
// RVA: 0xBF6EE0
void __fastcall hkaiOverlapManager::setupJobForFace(hkaiOverlapManager *this, unsigned int faceKey, hkaiNavMeshCutFaceJob *job)
{
  hkaiOverlapManager *v3; // rsi
  hkReferencedObject *v4; // rcx
  __int64 v5; // r15
  int v6; // ebp
  hkaiNavMeshCutFaceJob *v7; // r13
  unsigned int v8; // er14
  char v9; // di
  hkReferencedObject *v10; // rbx
  hkReferencedObject *v11; // rcx
  int v12; // er10
  signed __int64 v13; // r8
  hkaiNavMeshInstance *v14; // r9
  int v15; // eax
  hkReferencedObject v16; // [rsp+20h] [rbp-48h]
  hkaiSilhouettePriorityController *v17; // [rsp+70h] [rbp+8h]

  v3 = this;
  v4 = *(hkReferencedObject **)&this->m_maxCutFacesPerStep;
  v5 = faceKey >> 22;
  v6 = faceKey & 0x3FFFFF;
  v7 = job;
  v8 = faceKey;
  *(_DWORD *)&v16.m_memSizeAndFlags = 0x1FFFF;
  v9 = 1;
  v16.vfptr = (hkBaseObjectVtbl *)&hkaiDefaultSilhouettePriorityController::`vftable;
  if ( v4 )
  {
    hkReferencedObject::addReference(v4);
    v10 = *(hkReferencedObject **)&v3->m_maxCutFacesPerStep;
    v17 = *(hkaiSilhouettePriorityController **)&v3->m_maxCutFacesPerStep;
    v11 = *(hkReferencedObject **)&v3->m_maxCutFacesPerStep;
  }
  else
  {
    v9 = 2;
    hkReferencedObject::addReference(&v16);
    v11 = &v16;
    v17 = (hkaiSilhouettePriorityController *)&v16;
    v10 = &v16;
  }
  if ( v9 & 2 )
  {
    v9 &= 0xFDu;
    if ( v11 )
      hkReferencedObject::removeReference(v11);
  }
  if ( v9 & 1 && v10 )
    hkReferencedObject::removeReference(v10);
  v12 = hkaiOverlapManagerSection::sortGeneratorsForFace(
          (hkaiOverlapManagerSection *)(*(_QWORD *)&v3->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage
                                      + 72 * v5),
          v17,
          v6);
  v13 = *(_QWORD *)(*(_QWORD *)&v3->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage + 72 * v5 + 32)
      + 16i64 * v6;
  v14 = *(hkaiNavMeshInstance **)(*(_QWORD *)(*(_QWORD *)&v3->m_referenceFrameAndExtrusion.m_cellExtrusion + 32i64)
                                + 48 * v5);
  v7->m_faceKey = v8;
  v7->m_meshInstance = v14;
  v7->m_generatorContexts = *(hkaiSilhouetteGeneratorSectionContext *const **)v13;
  v15 = *(_DWORD *)(v13 + 8);
  v7->m_firstNonCuttingGeneratorIndex = v12;
  v7->m_numGenerators = v15;
  v7->m_worldUp = *(hkVector4f *)&v3->vfptr;
  v7->m_extrusionAmount = v3->m_referenceFrameAndExtrusion.m_up.m_quad.m128_f32[0];
  v7->m_radiusExpansionAmount = v3->m_referenceFrameAndExtrusion.m_up.m_quad.m128_f32[1];
  v7->m_isWallClimbing.m_bool = v14->m_originalMesh.m_pntr->m_flags.m_storage & 1;
}

// File Line: 1058
// RVA: 0xBF5F80
void __fastcall hkaiOverlapManager::markFrameDone(hkaiOverlapManager *this)
{
  ++this->m_stepCount;
}

// File Line: 1063
// RVA: 0xBF5F90
void __fastcall hkaiOverlapManager::updateReferenceFrameAndExtrusion(hkaiOverlapManager *this)
{
  int v1; // ebx
  hkaiOverlapManager *i; // rdi

  v1 = 0;
  for ( i = this; v1 < i->m_sections.m_size; ++v1 )
    hkaiOverlapManagerSection::dirtyAllFaces(&i->m_sections.m_data[v1]);
}

// File Line: 1074
// RVA: 0xBF79E0
void __fastcall hkaiOverlapManager::setAabbExpansion(hkaiOverlapManager *this, hkVector4f *up, float extrusion)
{
  ;
}

// File Line: 1079
// RVA: 0xBF79F0
void __fastcall hkaiOverlapManager::getExtrudedAabbForGenerator(hkaiOverlapManager *this, hkaiSilhouetteGenerator *gen, hkaiReferenceFrameAndExtrusion *refFrame, hkQTransformf *localTransform, hkaiNavMeshInstance *instance, hkAabb *aabbOut)
{
  hkaiSilhouetteGenerator *v6; // rdi
  hkaiReferenceFrameAndExtrusion *v7; // rbx
  unsigned int expansionFlags; // ecx
  __m128 v9; // xmm0
  float v10; // xmm1_4
  __m128 v11; // xmm1
  hkVector4f v12; // xmm1
  hkSimdFloat32 planarExpansion; // [rsp+30h] [rbp-58h]
  hkSimdFloat32 extrusion; // [rsp+40h] [rbp-48h]
  hkVector4f up; // [rsp+50h] [rbp-38h]
  hkAabb aabbInOut; // [rsp+60h] [rbp-28h]

  v6 = gen;
  v7 = refFrame;
  ((void (__fastcall *)(hkaiSilhouetteGenerator *, hkQTransformf *, hkAabb *))gen->vfptr[3].__first_virtual_table_function__)(
    gen,
    localTransform,
    &aabbInOut);
  expansionFlags = 0;
  if ( instance )
  {
    LOBYTE(expansionFlags) = (instance->m_originalMesh.m_pntr->m_flags.m_storage & 1) != 0;
    expansionFlags += 3;
  }
  v9 = v7->m_up.m_quad;
  v10 = v6->m_lazyRecomputeDisplacementThreshold + v7->m_silhouetteRadiusExpasion;
  _mm_store_si128((__m128i *)&up, (__m128i)v7->m_up.m_quad);
  v9.m128_f32[0] = v10;
  v11 = _mm_shuffle_ps((__m128)LODWORD(v7->m_cellExtrusion), (__m128)LODWORD(v7->m_cellExtrusion), 0);
  planarExpansion.m_real = _mm_shuffle_ps(v9, v9, 0);
  extrusion.m_real = v11;
  hkaiSilhouetteGenerator::expandAabb(&aabbInOut, &up, &extrusion, &planarExpansion, expansionFlags);
  v12.m_quad = (__m128)aabbInOut.m_max;
  aabbOut->m_min = aabbInOut.m_min;
  aabbOut->m_max = (hkVector4f)v12.m_quad;
}

// File Line: 1101
// RVA: 0xBF4910
signed __int64 __fastcall hkaiOverlapManagerSection::sortGeneratorsForFace(hkaiOverlapManagerSection *this, hkaiSilhouettePriorityController *controller, int f)
{
  hkArrayBase<char *> *v3; // rbx
  int v5; // er9
  int v6; // er9
  char v7; // si
  int v8; // er10
  __int64 v9; // rdi
  char **v10; // r11
  int v11; // edx
  int v12; // ecx
  signed __int64 v13; // rax
  char **v14; // rdx
  char *v15; // rax
  unsigned int v16; // ebx
  char **a; // [rsp+30h] [rbp-38h]
  int numtoinsert; // [rsp+38h] [rbp-30h]
  int v19; // [rsp+3Ch] [rbp-2Ch]
  char **v20; // [rsp+40h] [rbp-28h]
  int v21; // [rsp+48h] [rbp-20h]
  int v22; // [rsp+4Ch] [rbp-1Ch]
  _DWORD *array; // [rsp+50h] [rbp-18h]
  int v24; // [rsp+58h] [rbp-10h]
  int v25; // [rsp+5Ch] [rbp-Ch]
  hkResult result; // [rsp+90h] [rbp+28h]

  v3 = (hkArrayBase<char *> *)&this->m_faceToGeneratorsMap.m_data[f];
  controller->vfptr[3].__vecDelDtor((hkBaseObject *)controller, (unsigned int)v3);
  if ( v3->m_size < 14 )
    return 0xFFFFFFFFi64;
  array = 0i64;
  v24 = 0;
  v25 = 2147483648;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 14, 4);
  a = 0i64;
  numtoinsert = 0;
  v19 = 2147483648;
  v5 = v3->m_size;
  if ( v5 > 0 )
  {
    if ( v5 < 0 )
      v5 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &a, v5, 8);
  }
  v20 = 0i64;
  v21 = 0;
  v22 = 2147483648;
  v6 = v3->m_size;
  if ( v6 > 0 )
  {
    if ( v6 < 0 )
      v6 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v20, v6, 8);
  }
  v7 = 0;
  v8 = 0;
  if ( v3->m_size <= 0 )
  {
LABEL_23:
    v16 = -1;
    goto LABEL_24;
  }
  v9 = 0i64;
  do
  {
    v10 = &v3->m_data[v9];
    v11 = *(_DWORD *)(*((_QWORD *)*v10 + 4) + 32i64);
    if ( v11 == -1 )
    {
      a[numtoinsert++] = *v10;
    }
    else
    {
      v12 = 0;
      v13 = 0i64;
      if ( v24 <= 0i64 )
        goto LABEL_18;
      while ( array[v13] != v11 )
      {
        ++v13;
        ++v12;
        if ( v13 >= v24 )
          goto LABEL_18;
      }
      if ( v12 == -1 )
      {
LABEL_18:
        if ( v24 >= 14 )
        {
          v7 = 1;
          a[numtoinsert++] = *v10;
          goto LABEL_34;
        }
        array[v24++] = v11;
        v14 = &v20[v21];
        v15 = v3->m_data[v9];
      }
      else
      {
        v14 = &v20[v21];
        v15 = *v10;
      }
      *v14 = v15;
      ++v21;
    }
    if ( !v7 && v3->m_size - v8 - 1 <= 14 - v24 )
      goto LABEL_23;
LABEL_34:
    ++v8;
    ++v9;
  }
  while ( v8 < v3->m_size );
  if ( !v7 )
    goto LABEL_23;
  v3->m_size = 0;
  hkArrayBase<unsigned __int64>::_append(
    v3,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    a,
    numtoinsert);
  hkArrayBase<unsigned __int64>::_append(v3, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v20, v21);
  v16 = numtoinsert;
LABEL_24:
  v21 = 0;
  if ( v22 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v20,
      8 * v22);
  v20 = 0i64;
  v22 = 2147483648;
  numtoinsert = 0;
  if ( v19 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      a,
      8 * v19);
  a = 0i64;
  v24 = 0;
  v19 = 2147483648;
  if ( v25 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v25);
  return v16;
}

// File Line: 1182
// RVA: 0xBF4D50
hkReferencedObject *__fastcall hkaiOverlapManagerSection::addDataForGenerator(hkaiOverlapManagerSection *this, hkaiSilhouetteGenerator *gen, hkQTransformf *initialRelativeTransform)
{
  hkaiOverlapManagerSection *v3; // rdi
  hkQTransformf *v4; // rbx
  hkaiSilhouetteGenerator *v5; // rsi
  _QWORD **v6; // rax
  hkaiOverlapManagerSection::GeneratorData *v7; // rax
  hkReferencedObject *v8; // rax
  hkReferencedObject *v9; // rbx
  _QWORD *v10; // rsi

  v3 = this;
  v4 = initialRelativeTransform;
  v5 = gen;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkaiOverlapManagerSection::GeneratorData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(
                                                     v6[11],
                                                     80i64);
  if ( v7 )
  {
    hkaiOverlapManagerSection::GeneratorData::GeneratorData(v7, v5, v4);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_generatorDataMap->m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)v5,
    v3->m_generatorData.m_size);
  if ( v9 )
    hkReferencedObject::addReference(v9);
  if ( v3->m_generatorData.m_size == (v3->m_generatorData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_generatorData, 8);
  v10 = &v3->m_generatorData.m_data[v3->m_generatorData.m_size].m_pntr;
  if ( v10 )
  {
    if ( v9 )
      hkReferencedObject::addReference(v9);
    *v10 = v9;
  }
  ++v3->m_generatorData.m_size;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  hkReferencedObject::removeReference(v9);
  return v9;
}

// File Line: 1195
// RVA: 0xBF44C0
void __fastcall hkaiOverlapManagerSection::init(hkaiOverlapManagerSection *this, hkaiNavMeshInstance *instance)
{
  __int64 v2; // rsi
  int v3; // eax
  hkaiOverlapManagerSection *v4; // r14
  hkaiNavMeshInstance *v5; // r15
  int v6; // eax
  int v7; // er9
  int v8; // eax
  __int64 v9; // rdi
  int *v10; // rbx
  int v11; // er8
  __int64 v12; // rax
  int v13; // ecx
  signed __int64 v14; // rax
  __int64 v15; // r8
  _QWORD **v16; // rax
  __int64 v17; // rax
  hkResult result; // [rsp+60h] [rbp+8h]

  v2 = instance->m_numOriginalFaces;
  v3 = this->m_faceToGeneratorsMap.m_capacityAndFlags & 0x3FFFFFFF;
  v4 = this;
  v5 = instance;
  if ( v3 < (signed int)v2 )
  {
    v6 = 2 * v3;
    v7 = instance->m_numOriginalFaces;
    if ( (signed int)v2 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_faceToGeneratorsMap,
      v7,
      16);
  }
  v8 = v4->m_faceToGeneratorsMap.m_size - v2 - 1;
  v9 = v8;
  if ( v8 >= 0 )
  {
    v10 = &v4->m_faceToGeneratorsMap.m_data[v2].m_capacityAndFlags + 4 * v8;
    do
    {
      v11 = *v10;
      *(v10 - 1) = 0;
      if ( v11 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v10 - 3),
          8 * v11);
      *(_QWORD *)(v10 - 3) = 0i64;
      *v10 = 2147483648;
      v10 -= 4;
      --v9;
    }
    while ( v9 >= 0 );
  }
  v12 = v4->m_faceToGeneratorsMap.m_size;
  v13 = v2 - v12;
  v14 = (signed __int64)&v4->m_faceToGeneratorsMap.m_data[v12];
  v15 = v13;
  if ( v13 > 0 )
  {
    do
    {
      if ( v14 )
      {
        *(_QWORD *)v14 = 0i64;
        *(_DWORD *)(v14 + 8) = 0;
        *(_DWORD *)(v14 + 12) = 2147483648;
      }
      v14 += 16i64;
      --v15;
    }
    while ( v15 );
  }
  v4->m_faceToGeneratorsMap.m_size = v2;
  v4->m_numOriginalFaces = v5->m_numOriginalFaces;
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(v16[11], 16i64);
  if ( v17 )
  {
    *(_QWORD *)v17 = 0i64;
    *(_DWORD *)(v17 + 8) = 0;
    *(_DWORD *)(v17 + 12) = -1;
    v4->m_generatorDataMap = (hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> *)v17;
  }
  else
  {
    v4->m_generatorDataMap = 0i64;
  }
}

// File Line: 1204
// RVA: 0xBF4640
void __fastcall hkaiOverlapManagerSection::clearGeneratorData(hkaiOverlapManagerSection *this)
{
  hkaiOverlapManagerSection *v1; // rsi
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v2; // rcx
  int v3; // eax
  __int64 v4; // rdi
  int *v5; // rbx
  int v6; // er8
  int v7; // er8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v8; // rbx
  _QWORD **v9; // rax
  hkRefPtr<hkaiOverlapManagerSection::GeneratorData> *v10; // rdi
  int v11; // eax
  __int64 i; // rbx
  hkReferencedObject *v13; // rcx

  v1 = this;
  v2 = this->m_faceToGeneratorsMap.m_data;
  v3 = v1->m_faceToGeneratorsMap.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = &v2->m_capacityAndFlags + 4 * v3;
    do
    {
      v6 = *v5;
      *(v5 - 1) = 0;
      if ( v6 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v5 - 3),
          8 * v6);
      *(_QWORD *)(v5 - 3) = 0i64;
      *v5 = 2147483648;
      v5 -= 4;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v7 = v1->m_faceToGeneratorsMap.m_capacityAndFlags;
  v1->m_faceToGeneratorsMap.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_faceToGeneratorsMap.m_data,
      16 * v7);
  v1->m_faceToGeneratorsMap.m_data = 0i64;
  v1->m_faceToGeneratorsMap.m_capacityAndFlags = 2147483648;
  v8 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_generatorDataMap->m_map.m_elem;
  v1->m_numOriginalFaces = 0;
  if ( v8 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      v8,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)v8);
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *, signed __int64))(*v9[11] + 16i64))(
      v9[11],
      v8,
      16i64);
  }
  v1->m_generatorDataMap = 0i64;
  v10 = v1->m_generatorData.m_data;
  v11 = v1->m_generatorData.m_size - 1;
  for ( i = v11; i >= 0; v10[i--].m_pntr = 0i64 )
  {
    v13 = (hkReferencedObject *)&v10[i].m_pntr->vfptr;
    if ( v13 )
      hkReferencedObject::removeReference(v13);
  }
  v1->m_generatorData.m_size = 0;
  hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::clear((hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)&v1->m_facePriorities.m_elem);
}

// File Line: 1216
// RVA: 0xBF4E40
void __fastcall hkaiOverlapManagerSection::removeDataForGenerator(hkaiOverlapManagerSection *this, hkaiSilhouetteGenerator *gen, float generatorPriority)
{
  hkaiOverlapManagerSection *v3; // rbx
  Dummy *v4; // rax
  unsigned __int64 v5; // r15
  __int64 v6; // rsi
  hkaiOverlapManagerSection::GeneratorData *v7; // r13
  __int64 v8; // r14
  int *v9; // rax
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v10; // r10
  signed int v11; // ecx
  int v12; // er11
  signed __int64 v13; // rdx
  signed __int64 v14; // r8
  signed __int64 v15; // r9
  hkaiSilhouetteGeneratorSectionContext **v16; // rax
  __int64 v17; // rax
  hkRefPtr<hkaiOverlapManagerSection::GeneratorData> *v18; // rdi
  hkReferencedObject *v19; // rcx
  __int64 v20; // rax
  hkRefPtr<hkaiOverlapManagerSection::GeneratorData> *v21; // rsi
  hkReferencedObject *v22; // rcx
  hkaiOverlapManagerSection::GeneratorData *v23; // rdi
  __int64 v24; // rax

  v3 = this;
  v4 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_generatorDataMap->m_map.m_elem,
         (unsigned __int64)gen);
  v5 = SLODWORD(v3->m_generatorDataMap->m_map.m_elem[(signed int)v4].val);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_generatorDataMap->m_map.m_elem,
    v4);
  v6 = 0i64;
  v7 = v3->m_generatorData.m_data[v5].m_pntr;
  v8 = v7->m_overlappedFaces.m_size;
  if ( v8 > 0 )
  {
    do
    {
      v9 = v7->m_overlappedFaces.m_data;
      v10 = v3->m_faceToGeneratorsMap.m_data;
      v11 = 0;
      v12 = v9[v6];
      v13 = 0i64;
      v14 = v9[v6];
      v15 = v10[v9[v6]].m_size;
      if ( v15 <= 0 )
      {
LABEL_6:
        v11 = -1;
        v13 = -1i64;
      }
      else
      {
        v16 = v10[v9[v6]].m_data;
        while ( *v16 != &v7->m_context )
        {
          ++v13;
          ++v11;
          ++v16;
          if ( v13 >= v15 )
            goto LABEL_6;
        }
      }
      v17 = --v10[v14].m_size;
      if ( (_DWORD)v17 != v11 )
        v10[v14].m_data[v13] = v10[v14].m_data[v17];
      hkaiOverlapManagerSection::setFaceDirty(v3, v12, generatorPriority);
      ++v6;
    }
    while ( v6 < v8 );
  }
  if ( (_DWORD)v5 == v3->m_generatorData.m_size - 1 )
  {
    v18 = v3->m_generatorData.m_data;
    v19 = (hkReferencedObject *)&v18[v5].m_pntr->vfptr;
    if ( v19 )
      hkReferencedObject::removeReference(v19);
    v18[v5].m_pntr = 0i64;
    v20 = --v3->m_generatorData.m_size;
    if ( (_DWORD)v20 != (_DWORD)v5 )
      v3->m_generatorData.m_data[v5].m_pntr = v3->m_generatorData.m_data[v20].m_pntr;
  }
  else
  {
    v21 = v3->m_generatorData.m_data;
    v22 = (hkReferencedObject *)&v21[v5].m_pntr->vfptr;
    v23 = v21[v3->m_generatorData.m_size - 1].m_pntr;
    if ( v22 )
      hkReferencedObject::removeReference(v22);
    v21[v5].m_pntr = 0i64;
    v24 = --v3->m_generatorData.m_size;
    if ( (_DWORD)v24 != (_DWORD)v5 )
      v3->m_generatorData.m_data[v5].m_pntr = v3->m_generatorData.m_data[v24].m_pntr;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_generatorDataMap->m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (unsigned __int64)v23->m_context.m_generator,
      v5);
  }
}

// File Line: 1263
// RVA: 0xBF4FE0
bool __fastcall hkaiOverlapManagerSection::isOk(hkaiOverlapManagerSection *this)
{
  hkaiOverlapManagerSection *v1; // r13
  bool result; // al
  int v3; // ebx
  __int64 v4; // r15
  int v5; // edi
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v6; // r14
  __int64 v7; // rsi
  hkaiOverlapManagerSection::GeneratorData *v8; // rax
  int v9; // edx
  signed __int64 v10; // r10
  hkaiOverlapManagerSection::GeneratorData *v11; // rcx
  signed __int64 v12; // rax
  int *v13; // r9
  int *v14; // rcx
  int v15; // edx
  signed __int64 v16; // rax
  int *v17; // rcx
  hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> *v18; // r14
  int v19; // edx
  __int64 v20; // rcx
  __int64 v21; // r8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v22; // rax
  int v23; // ebp
  int v24; // edi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v25; // r15
  __int64 v26; // r10
  hkaiOverlapManagerSection::GeneratorData *v27; // rcx
  __int64 v28; // rbx
  int *v29; // r11
  signed __int64 v30; // r9
  int v31; // edx
  __int64 v32; // rcx
  signed __int64 v33; // rax
  __int64 v34; // r8
  _QWORD *v35; // rax
  __int64 v36; // r8
  int v37; // edx
  __int64 v38; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v39; // rax

  v1 = this;
  if ( !this->m_numOriginalFaces )
    return 1;
  v3 = 0;
  if ( this->m_faceToGeneratorsMap.m_size <= 0 )
  {
LABEL_21:
    v18 = v1->m_generatorDataMap;
    v19 = 0;
    v20 = 0i64;
    v21 = v1->m_generatorDataMap->m_map.m_hashMod;
    if ( v21 >= 0 )
    {
      v22 = v18->m_map.m_elem;
      do
      {
        if ( v22->key != -1i64 )
          break;
        ++v20;
        ++v19;
        ++v22;
      }
      while ( v20 <= v21 );
    }
    v23 = v18->m_map.m_hashMod;
    v24 = v19;
    if ( v19 > v23 )
    {
LABEL_41:
      result = 1;
    }
    else
    {
      v25 = v18->m_map.m_elem;
      while ( 1 )
      {
        v26 = 0i64;
        v27 = v1->m_generatorData.m_data[SLODWORD(v25[v24].val)].m_pntr;
        v28 = v27->m_overlappedFaces.m_size;
        if ( v28 > 0 )
          break;
LABEL_36:
        v36 = v18->m_map.m_hashMod;
        v37 = v24 + 1;
        v38 = v24 + 1;
        if ( v38 <= v36 )
        {
          v39 = &v25[v37];
          do
          {
            if ( v39->key != -1i64 )
              break;
            ++v38;
            ++v37;
            ++v39;
          }
          while ( v38 <= v36 );
        }
        v24 = v37;
        if ( v37 > v23 )
          goto LABEL_41;
      }
      v29 = v27->m_overlappedFaces.m_data;
      v30 = (signed __int64)&v27->m_context;
      while ( 1 )
      {
        v31 = 0;
        v32 = 0i64;
        v33 = (signed __int64)&v1->m_faceToGeneratorsMap.m_data[*v29];
        v34 = *(signed int *)(v33 + 8);
        if ( v34 <= 0 )
          break;
        v35 = *(_QWORD **)v33;
        while ( *v35 != v30 )
        {
          ++v32;
          ++v31;
          ++v35;
          if ( v32 >= v34 )
            goto LABEL_33;
        }
        if ( v31 < 0 )
          break;
        ++v26;
        ++v29;
        if ( v26 >= v28 )
          goto LABEL_36;
      }
LABEL_33:
      result = 0;
    }
  }
  else
  {
    v4 = 0i64;
    while ( 1 )
    {
      v5 = 0;
      v6 = &v1->m_faceToGeneratorsMap.m_data[v4];
      if ( v6->m_size > 0 )
        break;
LABEL_20:
      ++v3;
      ++v4;
      if ( v3 >= v1->m_faceToGeneratorsMap.m_size )
        goto LABEL_21;
    }
    v7 = 0i64;
    while ( 1 )
    {
      v8 = hkaiOverlapManagerSection::getGeneratorData(v1, v6->m_data[v7]->m_generator);
      v9 = 0;
      v10 = v8->m_overlappedFaces.m_size;
      v11 = v8;
      v12 = 0i64;
      if ( (signed int)v10 <= 0 )
        break;
      v13 = v11->m_overlappedFaces.m_data;
      v14 = v11->m_overlappedFaces.m_data;
      while ( *v14 != v3 )
      {
        ++v12;
        ++v9;
        ++v14;
        if ( v12 >= v10 )
          goto LABEL_11;
      }
      if ( v12 < 0 )
        break;
      v15 = v9 + 1;
      v16 = v12 + 1;
      if ( v16 < v10 )
      {
        v17 = &v13[v16];
        while ( *v17 != v3 )
        {
          ++v16;
          ++v15;
          ++v17;
          if ( v16 >= v10 )
            goto LABEL_19;
        }
        if ( v15 >= 0 )
          break;
      }
LABEL_19:
      ++v5;
      ++v7;
      if ( v5 >= v6->m_size )
        goto LABEL_20;
    }
LABEL_11:
    result = 0;
  }
  return result;
}

// File Line: 1314
// RVA: 0xBF7AF0
void __fastcall hkaiOverlapManager::rebuildMaps(hkaiOverlapManager *this, bool updateContexts)
{
  int v2; // ebx
  bool v3; // si
  hkaiOverlapManager *i; // rdi

  v2 = 0;
  v3 = updateContexts;
  for ( i = this; v2 < i->m_sections.m_size; ++v2 )
    hkaiOverlapManagerSection::rebuildMap(&i->m_sections.m_data[v2], v3);
}

// File Line: 1323
// RVA: 0xBF5210
void __fastcall hkaiOverlapManagerSection::rebuildMap(hkaiOverlapManagerSection *this, bool updateContexts)
{
  __int64 v2; // rsi
  char v3; // bl
  int v4; // eax
  hkaiOverlapManagerSection *v5; // r12
  int v6; // eax
  int v7; // er9
  int v8; // eax
  __int64 v9; // rdi
  int *v10; // rbx
  int v11; // er8
  signed __int64 v12; // rax
  int v13; // ecx
  signed __int64 v14; // r8
  __int64 v15; // rax
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v16; // r8
  _QWORD **v17; // rax
  __int64 v18; // rax
  int v19; // er15
  __int64 v20; // r13
  hkaiOverlapManagerSection::GeneratorData *v21; // rdi
  hkaiSilhouetteGenerator *v22; // rcx
  int v23; // eax
  int v24; // ebp
  __int64 v25; // rsi
  signed __int64 v26; // rbx
  hkResult result; // [rsp+70h] [rbp+8h]
  bool v28; // [rsp+78h] [rbp+10h]

  v28 = updateContexts;
  v2 = this->m_numOriginalFaces;
  v3 = updateContexts;
  v4 = this->m_faceToGeneratorsMap.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = this;
  if ( v4 < (signed int)v2 )
  {
    v6 = 2 * v4;
    v7 = this->m_numOriginalFaces;
    if ( (signed int)v2 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_faceToGeneratorsMap,
      v7,
      16);
  }
  v8 = v5->m_faceToGeneratorsMap.m_size - v2 - 1;
  v9 = v8;
  if ( v8 >= 0 )
  {
    v10 = &v5->m_faceToGeneratorsMap.m_data[v2].m_capacityAndFlags + 4 * v8;
    do
    {
      v11 = *v10;
      *(v10 - 1) = 0;
      if ( v11 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v10 - 3),
          8 * v11);
      *(_QWORD *)(v10 - 3) = 0i64;
      *v10 = 2147483648;
      v10 -= 4;
      --v9;
    }
    while ( v9 >= 0 );
    v3 = v28;
  }
  v12 = v5->m_faceToGeneratorsMap.m_size;
  v13 = v2 - v12;
  v14 = v12;
  v15 = (signed int)v2 - (signed int)v12;
  v16 = &v5->m_faceToGeneratorsMap.m_data[v14];
  if ( v13 > 0 )
  {
    do
    {
      if ( v16 )
      {
        v16->m_data = 0i64;
        v16->m_size = 0;
        v16->m_capacityAndFlags = 2147483648;
      }
      ++v16;
      --v15;
    }
    while ( v15 );
  }
  v5->m_faceToGeneratorsMap.m_size = v2;
  if ( (_DWORD)v2 )
  {
    v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(v17[11], 16i64);
    if ( v18 )
    {
      *(_QWORD *)v18 = 0i64;
      *(_DWORD *)(v18 + 8) = 0;
      *(_DWORD *)(v18 + 12) = -1;
    }
    else
    {
      v18 = 0i64;
    }
    v5->m_generatorDataMap = (hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> *)v18;
    v19 = 0;
    if ( v5->m_generatorData.m_size > 0 )
    {
      v20 = 0i64;
      do
      {
        v21 = v5->m_generatorData.m_data[v20].m_pntr;
        if ( v3 )
        {
          v22 = v21->m_context.m_generator;
          if ( v22 )
            v23 = ((__int64 (*)(void))v22->vfptr[6].__vecDelDtor)();
          else
            v23 = 0;
          v21->m_context.m_generatorSize = v23;
        }
        v24 = 0;
        if ( v21->m_overlappedFaces.m_size > 0 )
        {
          v25 = 0i64;
          do
          {
            v26 = (signed __int64)&v5->m_faceToGeneratorsMap.m_data[v21->m_overlappedFaces.m_data[v25]];
            if ( *(_DWORD *)(v26 + 8) == (*(_DWORD *)(v26 + 12) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v5->m_faceToGeneratorsMap.m_data[v21->m_overlappedFaces.m_data[v25]],
                8);
            ++v24;
            *(_QWORD *)(*(_QWORD *)v26 + 8i64 * (signed int)(*(_DWORD *)(v26 + 8))++) = (char *)v21 + 16;
            ++v25;
          }
          while ( v24 < v21->m_overlappedFaces.m_size );
          v3 = v28;
        }
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v5->m_generatorDataMap->m_map.m_elem,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          (unsigned __int64)v21->m_context.m_generator,
          v19++);
        ++v20;
      }
      while ( v19 < v5->m_generatorData.m_size );
    }
  }
}

// File Line: 1359
// RVA: 0xBF42F0
void __fastcall hkaiOverlapManagerSection::~hkaiOverlapManagerSection(hkaiOverlapManagerSection *this)
{
  hkaiOverlapManagerSection *v1; // rdi
  int v2; // er8
  int v3; // eax
  __int64 v4; // rsi
  int *v5; // rbx
  int v6; // er8
  int v7; // er8
  hkRefPtr<hkaiOverlapManagerSection::GeneratorData> *v8; // rsi
  int v9; // eax
  __int64 i; // rbx
  hkReferencedObject *v11; // rcx
  int v12; // er8

  v1 = this;
  hkaiOverlapManagerSection::clearGeneratorData(this);
  v2 = v1->m_facePriorities.m_elem.m_capacityAndFlags;
  v1->m_facePriorities.m_elem.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_facePriorities.m_elem.m_data,
      8 * v2);
  v1->m_facePriorities.m_elem.m_data = 0i64;
  v1->m_facePriorities.m_elem.m_capacityAndFlags = 2147483648;
  v3 = v1->m_faceToGeneratorsMap.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = &v1->m_faceToGeneratorsMap.m_data->m_capacityAndFlags + 4 * v3;
    do
    {
      v6 = *v5;
      *(v5 - 1) = 0;
      if ( v6 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v5 - 3),
          8 * v6);
      *(_QWORD *)(v5 - 3) = 0i64;
      *v5 = 2147483648;
      v5 -= 4;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v7 = v1->m_faceToGeneratorsMap.m_capacityAndFlags;
  v1->m_faceToGeneratorsMap.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_faceToGeneratorsMap.m_data,
      16 * v7);
  v1->m_faceToGeneratorsMap.m_data = 0i64;
  v1->m_faceToGeneratorsMap.m_capacityAndFlags = 2147483648;
  v8 = v1->m_generatorData.m_data;
  v9 = v1->m_generatorData.m_size - 1;
  for ( i = v9; i >= 0; v8[i--].m_pntr = 0i64 )
  {
    v11 = (hkReferencedObject *)&v8[i].m_pntr->vfptr;
    if ( v11 )
      hkReferencedObject::removeReference(v11);
  }
  v12 = v1->m_generatorData.m_capacityAndFlags;
  v1->m_generatorData.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_generatorData.m_data,
      8 * v12);
  v1->m_generatorData.m_data = 0i64;
  v1->m_generatorData.m_capacityAndFlags = 2147483648;
}

// File Line: 1364
// RVA: 0xBF4780
void __fastcall hkaiOverlapManagerSection::optimizeCapacity(hkaiOverlapManagerSection *this)
{
  hkaiOverlapManagerSection *v1; // rbp
  unsigned int v2; // edx
  unsigned int v3; // edx
  int v4; // eax
  int requestedCapacity; // ecx
  int v6; // ebx
  int v7; // esi
  __int64 v8; // rdi
  unsigned int v9; // ecx
  int v10; // edx
  __int64 v11; // rdi
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v12; // rdx
  unsigned int v13; // ecx
  int v14; // er8

  v1 = this;
  v2 = ((((unsigned int)(this->m_generatorData.m_size - 1) >> 16) | (this->m_generatorData.m_size - 1)) >> 8) | ((unsigned int)(this->m_generatorData.m_size - 1) >> 16) | (this->m_generatorData.m_size - 1);
  v3 = (((v2 >> 4) | v2) >> 2) | (v2 >> 4) | v2;
  v4 = this->m_generatorData.m_capacityAndFlags & 0x3FFFFFFF;
  requestedCapacity = (v3 | (v3 >> 1)) + 1;
  if ( requestedCapacity < v4 )
    hkArrayUtil::_reduce(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_generatorData,
      8,
      0i64,
      requestedCapacity);
  v6 = 0;
  v7 = 0;
  if ( v1->m_generatorData.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      hkaiOverlapManagerSection::GeneratorData::optimizeCapacity(v1->m_generatorData.m_data[v8].m_pntr);
      ++v7;
      ++v8;
    }
    while ( v7 < v1->m_generatorData.m_size );
  }
  v9 = ((((((((unsigned int)(v1->m_faceToGeneratorsMap.m_size - 1) >> 16) | (v1->m_faceToGeneratorsMap.m_size - 1)) >> 8) | ((unsigned int)(v1->m_faceToGeneratorsMap.m_size - 1) >> 16) | (v1->m_faceToGeneratorsMap.m_size - 1)) >> 4) | ((((unsigned int)(v1->m_faceToGeneratorsMap.m_size - 1) >> 16) | (v1->m_faceToGeneratorsMap.m_size - 1)) >> 8) | ((unsigned int)(v1->m_faceToGeneratorsMap.m_size - 1) >> 16) | (v1->m_faceToGeneratorsMap.m_size - 1)) >> 2) | ((((((unsigned int)(v1->m_faceToGeneratorsMap.m_size - 1) >> 16) | (v1->m_faceToGeneratorsMap.m_size - 1)) >> 8) | ((unsigned int)(v1->m_faceToGeneratorsMap.m_size - 1) >> 16) | (v1->m_faceToGeneratorsMap.m_size - 1)) >> 4) | ((((unsigned int)(v1->m_faceToGeneratorsMap.m_size - 1) >> 16) | (v1->m_faceToGeneratorsMap.m_size - 1)) >> 8) | ((unsigned int)(v1->m_faceToGeneratorsMap.m_size - 1) >> 16) | (v1->m_faceToGeneratorsMap.m_size - 1);
  v10 = (v9 | (v9 >> 1)) + 1;
  if ( v10 < (v1->m_faceToGeneratorsMap.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_faceToGeneratorsMap,
      16,
      0i64,
      v10);
  if ( v1->m_faceToGeneratorsMap.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = &v1->m_faceToGeneratorsMap.m_data[v11];
      v13 = ((((((((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 8) | ((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 4) | ((((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 8) | ((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 2) | ((((((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 8) | ((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 4) | ((((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 8) | ((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1);
      v14 = (v13 | (v13 >> 1)) + 1;
      if ( v14 < (v12->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12, 8, 0i64, v14);
      ++v6;
      ++v11;
    }
    while ( v6 < v1->m_faceToGeneratorsMap.m_size );
  }
  hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::optimizeCapacity(
    (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)&v1->m_facePriorities.m_elem,
    0);
}

// File Line: 1386
// RVA: 0xBF6060
void __fastcall hkaiOverlapManager::optimizeCapacity(hkaiOverlapManager *this)
{
  hkaiOverlapManager *v1; // rsi
  unsigned int v2; // edx
  int v3; // eax
  int requestedCapacity; // ecx
  int i; // ebx

  v1 = this;
  v2 = ((((((((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 8) | ((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 4) | ((((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 8) | ((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 2) | ((((((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 8) | ((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 4) | ((((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 8) | ((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1);
  v3 = this->m_sections.m_capacityAndFlags & 0x3FFFFFFF;
  requestedCapacity = (v2 | (v2 >> 1)) + 1;
  if ( requestedCapacity < v3 )
    hkArrayUtil::_reduce(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_sections,
      72,
      0i64,
      requestedCapacity);
  for ( i = 0; i < v1->m_sections.m_size; ++i )
    hkaiOverlapManagerSection::optimizeCapacity(&v1->m_sections.m_data[i]);
}

// File Line: 1395
// RVA: 0xBF6020
void __fastcall hkaiOverlapManager::setSilhouettePriorityController(hkaiOverlapManager *this, hkaiSilhouettePriorityController *controller)
{
  hkaiSilhouettePriorityController *v2; // rbx
  hkaiOverlapManager *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = controller;
  v3 = this;
  if ( controller )
    hkReferencedObject::addReference((hkReferencedObject *)&controller->vfptr);
  v4 = (hkReferencedObject *)&v3->m_priorityController.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_priorityController.m_pntr = v2;
}

// File Line: 1400
// RVA: 0xBF4450
void __fastcall hkaiOverlapManagerSection::GeneratorData::optimizeCapacity(hkaiOverlapManagerSection::GeneratorData *this)
{
  hkArray<int,hkContainerHeapAllocator> *v1; // rdx
  unsigned int v2; // ecx
  unsigned int v3; // ecx
  signed int requestedCapacity; // er8

  v1 = &this->m_overlappedFaces;
  v2 = ((unsigned int)(this->m_overlappedFaces.m_size - 1) >> 16) | (this->m_overlappedFaces.m_size - 1);
  v3 = (((v2 >> 8) | v2) >> 4) | (v2 >> 8) | v2;
  requestedCapacity = ((v3 >> 2) | v3 | (((v3 >> 2) | v3) >> 1)) + 1;
  if ( requestedCapacity < (v1->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v1, 4, 0i64, requestedCapacity);
}

// File Line: 1405
// RVA: 0xBF4C00
void __fastcall hkaiOverlapManagerSection::dirtyAllFaces(hkaiOverlapManagerSection *this)
{
  hkaiOverlapManagerSection *v1; // rbp
  int v2; // ebx
  int v3; // esi
  int v4; // er8
  int v5; // er8
  hkIntRealPair *v6; // r9
  int v7; // ecx
  int v8; // edx
  __int64 v9; // rdx
  hkIntRealPair *v10; // rcx
  hkIntRealPair *v11; // r9
  int v12; // er8
  signed int v13; // er10
  int v14; // ecx
  int v15; // edx
  __int64 v16; // rax
  hkResult result; // [rsp+40h] [rbp+8h]
  __int64 v18; // [rsp+48h] [rbp+10h]
  hkIntRealPair v19; // [rsp+50h] [rbp+18h]

  v1 = this;
  hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::reserve(
    (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)&this->m_facePriorities.m_elem,
    this->m_numOriginalFaces);
  v2 = 0;
  if ( v1->m_numOriginalFaces > 0 )
  {
    v3 = 0;
    do
    {
      v4 = v1->m_facePriorities.m_elem.m_size;
      v18 = (unsigned int)v2;
      v5 = v4 - 1;
      if ( v5 <= 0 || (v6 = v1->m_facePriorities.m_elem.m_data, v7 = v5 & v3, v8 = v6[v5 & v3].m_key, v8 == -1) )
      {
LABEL_7:
        LODWORD(v9) = v5 + 1;
      }
      else
      {
        while ( v8 != v2 )
        {
          v7 = v5 & (v7 + 1);
          v8 = v6[v7].m_key;
          if ( v8 == -1 )
            goto LABEL_7;
        }
        LODWORD(v9) = v7;
      }
      if ( (signed int)v9 > v1->m_facePriorities.m_elem.m_size - 1 )
      {
        if ( 2 * v1->m_facePriorities.m_numElems > v5 )
          hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::resizeTable(
            (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)&v1->m_facePriorities.m_elem,
            &result,
            2 * v5 + 2);
        v11 = v1->m_facePriorities.m_elem.m_data;
        v12 = v1->m_facePriorities.m_elem.m_size - 1;
        v13 = 1;
        v14 = v12 & v3;
        v15 = v11[v12 & v3].m_key;
        if ( v15 != -1 )
        {
          while ( v15 != v2 )
          {
            v14 = v12 & (v14 + 1);
            v15 = v11[v14].m_key;
            if ( v15 == -1 )
              goto LABEL_18;
          }
          v13 = 0;
        }
LABEL_18:
        v16 = v18;
        v1->m_facePriorities.m_numElems += v13;
        v11[v14] = (hkIntRealPair)v16;
      }
      else
      {
        v10 = v1->m_facePriorities.m_elem.m_data;
        v9 = (signed int)v9;
        v19 = v10[(signed int)v9];
        HIDWORD(v18) = LODWORD(v19.m_value);
        v10[v9] = (hkIntRealPair)v18;
      }
      ++v2;
      v3 -= 1640531535;
    }
    while ( v2 < v1->m_numOriginalFaces );
  }
}

