// File Line: 39
// RVA: 0xBF5450
void __fastcall hkaiOverlapManager::hkaiOverlapManager(
        hkaiOverlapManager *this,
        hkaiStreamingCollection *navMeshCollection,
        hkaiReferenceFrameAndExtrusion *referenceFrameAndExtrusion)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiOverlapManager::`vftable{for `hkReferencedObject};
  this->hkaiNavMeshSilhouetteSelector::vfptr = (hkaiNavMeshSilhouetteSelectorVtbl *)&hkaiOverlapManager::`vftable{for `hkaiNavMeshSilhouetteSelector};
  this->m_referenceFrameAndExtrusion = *referenceFrameAndExtrusion;
  if ( navMeshCollection )
    hkReferencedObject::addReference(navMeshCollection);
  this->m_navMeshCollection.m_pntr = navMeshCollection;
  this->m_sections.m_capacityAndFlags = 0x80000000;
  this->m_sections.m_data = 0i64;
  this->m_sections.m_size = 0;
  this->m_silhouetteFilter.m_pntr = 0i64;
  this->m_priorityController.m_pntr = 0i64;
  hkaiOverlapManager::setReferenceFrameAndExtrusion(this, referenceFrameAndExtrusion);
  this->m_stepCount = 0;
  this->m_maxCutFacesPerStep = -1;
  this->m_hasMovedTolerance = 0.001;
}

// File Line: 47
// RVA: 0xBF7040
void __fastcall hkaiOverlapManager::setReferenceFrameAndExtrusion(
        hkaiOverlapManager *this,
        hkaiReferenceFrameAndExtrusion *refFrame)
{
  this->m_referenceFrameAndExtrusion = *refFrame;
}

// File Line: 53
// RVA: 0xBF5FE0
void __fastcall hkaiOverlapManager::setSilhouetteFilter(hkaiOverlapManager *this, hkaiSpatialQueryHitFilter *filter)
{
  hkaiSpatialQueryHitFilter *m_pntr; // rcx

  if ( filter )
    hkReferencedObject::addReference(filter);
  m_pntr = this->m_silhouetteFilter.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_silhouetteFilter.m_pntr = filter;
}

// File Line: 62
// RVA: 0xBF5500
void __fastcall hkaiOverlapManager::hkaiOverlapManager(hkaiOverlapManager *this, hkFinishLoadedObjectFlag f)
{
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiOverlapManager::`vftable{for `hkReferencedObject};
  this->hkaiNavMeshSilhouetteSelector::vfptr = (hkaiNavMeshSilhouetteSelectorVtbl *)&hkaiOverlapManager::`vftable{for `hkaiNavMeshSilhouetteSelector};
  this->m_silhouetteFilter.m_pntr = 0i64;
  this->m_priorityController.m_pntr = 0i64;
  if ( f.m_finishing )
    hkaiOverlapManager::rebuildMaps(this, 0);
}

// File Line: 72
// RVA: 0xBF5550
void __fastcall hkaiOverlapManager::~hkaiOverlapManager(hkaiOverlapManager *this)
{
  int v2; // edi
  hkaiSilhouettePriorityController *m_pntr; // rcx
  hkaiSpatialQueryHitFilter *v4; // rcx
  int v5; // edi
  hkaiOverlapManagerSection *v6; // rsi
  int m_capacityAndFlags; // eax
  hkaiStreamingCollection *v8; // rcx

  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiOverlapManager::`vftable{for `hkReferencedObject};
  v2 = 0;
  for ( this->hkaiNavMeshSilhouetteSelector::vfptr = (hkaiNavMeshSilhouetteSelectorVtbl *)&hkaiOverlapManager::`vftable{for `hkaiNavMeshSilhouetteSelector};
        v2 < this->m_sections.m_size;
        ++v2 )
  {
    hkaiOverlapManager::unloadSection(this, v2);
  }
  m_pntr = this->m_priorityController.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_priorityController.m_pntr = 0i64;
  v4 = this->m_silhouetteFilter.m_pntr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  this->m_silhouetteFilter.m_pntr = 0i64;
  v5 = this->m_sections.m_size - 1;
  if ( v5 >= 0 )
  {
    v6 = &this->m_sections.m_data[v5];
    do
    {
      hkaiOverlapManagerSection::~hkaiOverlapManagerSection(v6--);
      --v5;
    }
    while ( v5 >= 0 );
  }
  m_capacityAndFlags = this->m_sections.m_capacityAndFlags;
  this->m_sections.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_sections.m_data,
      72 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_sections.m_data = 0i64;
  this->m_sections.m_capacityAndFlags = 0x80000000;
  v8 = this->m_navMeshCollection.m_pntr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  this->m_navMeshCollection.m_pntr = 0i64;
  this->hkaiNavMeshSilhouetteSelector::vfptr = (hkaiNavMeshSilhouetteSelectorVtbl *)&hkaiNavMeshSilhouetteSelector::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 81
// RVA: 0xBF77D0
void __fastcall hkaiOverlapManager::queryAndUpdateFacesForGenerator(
        hkaiOverlapManager *this,
        int sectionIdx,
        hkaiOverlapManagerSection::GeneratorData *generatorData,
        hkaiSilhouetteGenerator *gen,
        hkQTransformf *silhouetteRelativeTransform)
{
  __int64 v7; // r15
  hkaiNavMeshInstance *m_instancePtr; // rbx
  hkQTransformf *v10; // r12
  hkaiSpatialQueryHitFilter *m_pntr; // rax
  hkaiStreamingCollection *v12; // rax
  hkaiNavMeshQueryMediator *m_mediator; // rbx
  _QWORD *Value; // rax
  unsigned __int64 v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  hkArrayBase<unsigned int> array; // [rsp+40h] [rbp-31h] BYREF
  int v23; // [rsp+50h] [rbp-21h] BYREF
  hkaiSilhouetteGenerator *v24; // [rsp+58h] [rbp-19h]
  __int128 v25; // [rsp+60h] [rbp-11h]
  __int64 v26; // [rsp+70h] [rbp-1h]
  hkAabb genAabb; // [rsp+80h] [rbp+Fh] BYREF
  hkResult result; // [rsp+D8h] [rbp+67h] BYREF

  v7 = sectionIdx;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, 32, 4);
  m_instancePtr = this->m_navMeshCollection.m_pntr->m_instances.m_data[v7].m_instancePtr;
  v23 = 0;
  v24 = 0i64;
  v25 = 0i64;
  genAabb.m_min = (hkVector4f)xmmword_141A712A0;
  v26 = 0i64;
  v10 = silhouetteRelativeTransform;
  genAabb.m_max.m_quad = _mm_xor_ps(
                           (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                           (__m128)xmmword_141A712A0);
  hkaiOverlapManager::getExtrudedAabbForGenerator(
    this,
    gen,
    &this->m_referenceFrameAndExtrusion,
    silhouetteRelativeTransform,
    m_instancePtr,
    &genAabb);
  m_pntr = this->m_silhouetteFilter.m_pntr;
  v24 = gen;
  *(_QWORD *)&v25 = m_pntr;
  v12 = this->m_navMeshCollection.m_pntr;
  *((_QWORD *)&v25 + 1) = m_instancePtr;
  m_mediator = v12->m_instances.m_data[v7].m_mediator;
  array.m_size = 0;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = Value[1];
  v16 = Value;
  if ( v15 < Value[3] )
  {
    *(_QWORD *)v15 = "TtqueryAabb";
    v17 = __rdtsc();
    *(_DWORD *)(v15 + 8) = v17;
    v16[1] = v15 + 16;
  }
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, hkArrayBase<unsigned int> *))m_mediator->vfptr[3].__first_virtual_table_function__)(
    m_mediator,
    &v23,
    &array);
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = v19 + 2;
    *((_DWORD *)v21 - 2) = v20;
    v18[1] = v21;
  }
  if ( array.m_size > 1 )
    hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(array.m_data, 0, array.m_size - 1, 0);
  hkaiOverlapManager::updateSectionFacesForGenerator(this, v7, generatorData, gen, v10, &genAabb, &array);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      4 * array.m_capacityAndFlags);
}

// File Line: 114
// RVA: 0xBF7070
void __fastcall hkaiOverlapManager::updateSectionFacesForGenerator(
        hkaiOverlapManager *this,
        int sectionIdx,
        hkaiOverlapManagerSection::GeneratorData *generatorData,
        hkaiSilhouetteGenerator *gen,
        hkQTransformf *silhouetteRelativeTransform,
        hkAabb *genAabb,
        hkArrayBase<unsigned int> *faceKeys)
{
  hkArrayBase<unsigned int> *v7; // r14
  int m_size; // ebx
  hkArrayBase<unsigned int> *p_m_overlappedFaces; // r15
  hkaiOverlapManagerSection *v10; // rax
  int v11; // r12d
  hkLifoAllocator *Value; // rax
  char *m_cur; // r13
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
  hkaiSilhouettePriorityController *m_pntr; // rcx
  char v25; // si
  hkaiSilhouettePriorityController *v26; // rbx
  hkReferencedObject *v27; // rcx
  hkaiOverlapManager *v28; // rsi
  int v29; // r8d
  int v30; // edx
  int v31; // r8d
  __int64 v32; // r10
  __int64 v33; // r11
  int v34; // eax
  int v35; // r9d
  int v36; // ecx
  hkResultEnum m_enum; // r9d
  __int64 v38; // r8
  __int64 v39; // rcx
  unsigned int v40; // eax
  __int64 v41; // rdx
  __int64 v42; // rax
  hkAabb *v43; // r14
  float v44; // xmm7_4
  double v45; // xmm0_8
  float v46; // xmm6_4
  int *v47; // rbx
  int v48; // r11d
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *m_data; // r10
  int v50; // ecx
  __int64 v51; // rdx
  __int64 v52; // r9
  __int64 v53; // r8
  hkaiSilhouetteGeneratorSectionContext **v54; // rax
  __int64 v55; // rax
  double v56; // xmm0_8
  float v57; // xmm6_4
  int *v58; // rsi
  __int64 v59; // rbp
  int v60; // edi
  __int64 v61; // rbx
  __int64 v62; // rsi
  double v63; // xmm0_8
  char *v64; // r14
  int *v65; // rbx
  __int64 v66; // rdi
  int v67; // r9d
  int v68; // eax
  int v69; // eax
  signed int v70; // edi
  hkLifoAllocator *v71; // rax
  int v72; // ebx
  int v73; // esi
  hkLifoAllocator *v74; // rax
  hkLifoAllocator *v75; // rax
  unsigned int *a; // [rsp+30h] [rbp-B8h]
  _DWORD *v77; // [rsp+38h] [rbp-B0h]
  hkReferencedObject *v78; // [rsp+40h] [rbp-A8h]
  hkaiSilhouetteGeneratorSectionContext *p_m_context; // [rsp+48h] [rbp-A0h]
  hkaiOverlapManagerSection *v80; // [rsp+50h] [rbp-98h]
  hkArray<int,hkContainerHeapAllocator> *v81; // [rsp+58h] [rbp-90h]
  hkReferencedObject v82; // [rsp+60h] [rbp-88h] BYREF
  hkVector4f v83; // [rsp+70h] [rbp-78h] BYREF
  hkResult result; // [rsp+F8h] [rbp+10h] BYREF
  int v86; // [rsp+100h] [rbp+18h]
  hkaiSilhouetteGenerator *v87; // [rsp+108h] [rbp+20h]

  v87 = gen;
  v7 = faceKeys;
  result.m_enum = HK_SUCCESS;
  m_size = generatorData->m_overlappedFaces.m_size;
  p_m_overlappedFaces = (hkArrayBase<unsigned int> *)&generatorData->m_overlappedFaces;
  v81 = &generatorData->m_overlappedFaces;
  if ( faceKeys->m_size > m_size )
    m_size = faceKeys->m_size;
  v10 = &this->m_sections.m_data[sectionIdx];
  v11 = 0;
  LODWORD(faceKeys) = m_size;
  v80 = v10;
  p_m_context = &generatorData->m_context;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v14 = (4 * m_size + 127) & 0xFFFFFF80;
    v15 = &m_cur[v14];
    if ( v14 > Value->m_slabSize || v15 > Value->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v14);
    else
      Value->m_cur = v15;
  }
  else
  {
    m_cur = 0i64;
  }
  v16 = 0i64;
  v86 = m_size | 0x80000000;
  if ( m_size )
  {
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = v17->m_cur;
    v19 = (4 * m_size + 127) & 0xFFFFFF80;
    v77 = v18;
    v20 = (char *)v18 + v19;
    if ( v19 > v17->m_slabSize || v20 > v17->m_end )
    {
      v18 = hkLifoAllocator::allocateFromNewSlab(v17, v19);
      v77 = v18;
    }
    else
    {
      v17->m_cur = v20;
    }
  }
  else
  {
    v18 = 0i64;
    v77 = 0i64;
  }
  result.m_enum = HK_SUCCESS;
  if ( m_size )
  {
    v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (4 * m_size + 127) & 0xFFFFFF80;
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
  *(_DWORD *)&v82.m_memSizeAndFlags = 0x1FFFF;
  m_pntr = this->m_priorityController.m_pntr;
  v25 = 1;
  v82.vfptr = (hkBaseObjectVtbl *)&hkaiDefaultSilhouettePriorityController::`vftable;
  if ( m_pntr )
  {
    hkReferencedObject::addReference(m_pntr);
    v26 = this->m_priorityController.m_pntr;
    v78 = v26;
    v27 = v26;
  }
  else
  {
    v25 = 2;
    hkReferencedObject::addReference(&v82);
    v27 = &v82;
    v78 = &v82;
    v26 = (hkaiSilhouettePriorityController *)&v82;
  }
  if ( (v25 & 2) != 0 )
  {
    v25 &= ~2u;
    if ( v27 )
      hkReferencedObject::removeReference(v27);
  }
  if ( (v25 & 1) != 0 && v26 )
    hkReferencedObject::removeReference(v26);
  v28 = this;
  v29 = p_m_overlappedFaces->m_size;
  v83.m_quad = (__m128)this->m_referenceFrameAndExtrusion.m_up;
  if ( v29 > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>((int *)p_m_overlappedFaces->m_data, 0, v29 - 1, 0);
  v30 = 0;
  v31 = 0;
  v32 = 0i64;
  v33 = 0i64;
  while ( 1 )
  {
    v34 = p_m_overlappedFaces->m_size;
    if ( v30 == v34 )
    {
      if ( v31 == v7->m_size )
        goto LABEL_49;
      if ( v30 == v34 )
        break;
    }
    if ( v31 == v7->m_size )
    {
      if ( v30 < v34 )
      {
        v38 = v30;
        do
        {
          v39 = (int)v16;
          ++v30;
          v40 = p_m_overlappedFaces->m_data[v38];
          v16 = (unsigned int)(v16 + 1);
          ++v38;
          v18[v39] = v40;
        }
        while ( v30 < p_m_overlappedFaces->m_size );
      }
      goto LABEL_49;
    }
    v35 = p_m_overlappedFaces->m_data[v33];
    v36 = v7->m_data[v32] & 0x3FFFFF;
    if ( v35 == v36 )
    {
      m_enum = result.m_enum;
      ++v30;
      ++v33;
      ++v31;
      ++v32;
      a[result.m_enum] = v36;
      result.m_enum = m_enum + 1;
    }
    else if ( v35 >= v36 )
    {
      ++v31;
      ++v32;
      *(_DWORD *)&m_cur[4 * v11++] = v36;
    }
    else
    {
      ++v30;
      ++v33;
      v18[(int)v16] = v35;
      v16 = (unsigned int)(v16 + 1);
    }
  }
  if ( v31 < v7->m_size )
  {
    v41 = v31;
    do
    {
      ++v31;
      ++v41;
      v42 = v11++;
      *(_DWORD *)&m_cur[4 * v42] = v7->m_data[v41 - 1] & 0x3FFFFF;
    }
    while ( v31 < v7->m_size );
  }
LABEL_49:
  v43 = genAabb;
  v44 = *(float *)&FLOAT_1_0;
  if ( (int)v16 > 0 )
  {
    if ( this->m_maxCutFacesPerStep <= 0 )
    {
      v46 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v45 = ((double (__fastcall *)(hkReferencedObject *, hkaiSilhouetteGenerator *, hkAabb *, hkVector4f *))v78->vfptr[2].__vecDelDtor)(
              v78,
              v87,
              genAabb,
              &v83);
      v46 = *(float *)&v45;
    }
    v47 = v18;
    do
    {
      v48 = *v47;
      m_data = v80->m_faceToGeneratorsMap.m_data;
      v50 = 0;
      v51 = 0i64;
      v52 = *v47;
      v53 = m_data[*v47].m_size;
      if ( v53 <= 0 )
      {
LABEL_58:
        v50 = -1;
        v51 = -1i64;
      }
      else
      {
        v54 = m_data[*v47].m_data;
        while ( *v54 != p_m_context )
        {
          ++v51;
          ++v50;
          ++v54;
          if ( v51 >= v53 )
            goto LABEL_58;
        }
      }
      --m_data[*v47].m_size;
      v55 = m_data[v52].m_size;
      if ( (_DWORD)v55 != v50 )
        m_data[v52].m_data[v51] = m_data[v52].m_data[v55];
      hkaiOverlapManagerSection::setFaceDirty(v80, v48, v46);
      ++v47;
      --v16;
    }
    while ( v16 );
    p_m_overlappedFaces = (hkArrayBase<unsigned int> *)v81;
    v28 = this;
  }
  if ( v11 > 0 )
  {
    if ( v28->m_maxCutFacesPerStep <= 0 )
    {
      v57 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v56 = ((double (__fastcall *)(hkReferencedObject *, hkaiSilhouetteGenerator *, hkAabb *, hkVector4f *))v78->vfptr[1].__first_virtual_table_function__)(
              v78,
              v87,
              v43,
              &v83);
      v57 = *(float *)&v56;
    }
    v58 = (int *)m_cur;
    v59 = (unsigned int)v11;
    do
    {
      v60 = *v58;
      v61 = (__int64)&v80->m_faceToGeneratorsMap.m_data[*v58];
      if ( *(_DWORD *)(v61 + 8) == (*(_DWORD *)(v61 + 12) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v80->m_faceToGeneratorsMap.m_data[*v58], 8);
      *(_QWORD *)(*(_QWORD *)v61 + 8i64 * (int)(*(_DWORD *)(v61 + 8))++) = p_m_context;
      hkaiOverlapManagerSection::setFaceDirty(v80, v60, v57);
      ++v58;
      --v59;
    }
    while ( v59 );
    p_m_overlappedFaces = (hkArrayBase<unsigned int> *)v81;
    v43 = genAabb;
    v18 = v77;
  }
  v62 = (unsigned int)result.m_enum;
  if ( result.m_enum <= HK_SUCCESS )
  {
    v64 = (char *)a;
  }
  else
  {
    if ( this->m_maxCutFacesPerStep > 0 )
    {
      v63 = ((double (__fastcall *)(hkReferencedObject *, hkaiSilhouetteGenerator *, hkAabb *, hkVector4f *, hkaiSilhouetteGeneratorSectionContext *, hkQTransformf *))v78->vfptr[2].__first_virtual_table_function__)(
              v78,
              v87,
              v43,
              &v83,
              p_m_context,
              silhouetteRelativeTransform);
      v44 = *(float *)&v63;
    }
    v64 = (char *)a;
    if ( (int)v62 > 0 )
    {
      v65 = (int *)a;
      v66 = v62;
      do
      {
        hkaiOverlapManagerSection::setFaceDirty(v80, *v65++, v44);
        --v66;
      }
      while ( v66 );
      v18 = v77;
    }
  }
  v67 = v62 + v11;
  v68 = p_m_overlappedFaces->m_capacityAndFlags & 0x3FFFFFFF;
  p_m_overlappedFaces->m_size = 0;
  if ( v68 < (int)v62 + v11 )
  {
    v69 = 2 * v68;
    if ( v67 < v69 )
      v67 = v69;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_overlappedFaces, v67, 4);
  }
  hkArrayBase<unsigned int>::_append(p_m_overlappedFaces, &hkContainerHeapAllocator::s_alloc, m_cur, v11);
  hkArrayBase<unsigned int>::_append(p_m_overlappedFaces, &hkContainerHeapAllocator::s_alloc, v64, v62);
  v70 = (4 * (_DWORD)faceKeys + 127) & 0xFFFFFF80;
  v82.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  v71 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v72 = (v70 + 15) & 0xFFFFFFF0;
  if ( v70 > v71->m_slabSize || &v64[v72] != v71->m_cur || v71->m_firstNonLifoEnd == v64 )
    hkLifoAllocator::slowBlockFree(v71, v64, v72);
  else
    v71->m_cur = v64;
  v73 = v86;
  if ( v86 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v64, 4 * v86);
  v74 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v70 > v74->m_slabSize || (char *)v18 + v72 != v74->m_cur || v74->m_firstNonLifoEnd == v18 )
    hkLifoAllocator::slowBlockFree(v74, v18, v72);
  else
    v74->m_cur = v18;
  if ( v73 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v18, 4 * v73);
  v75 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v70 > v75->m_slabSize || &m_cur[v72] != v75->m_cur || v75->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v75, m_cur, v72);
  else
    v75->m_cur = m_cur;
  if ( v73 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_cur, 4 * v73);
}    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_cur, 4 * v73);
}

// File Line: 309
// RVA: 0xBF5660
void __fastcall hkaiOverlapManager::loadSection(
        hkaiOverlapManager *this,
        int sectionIndex,
        hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *generators)
{
  __int64 v3; // r13
  int v4; // edi
  int v6; // ebp
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  int v11; // ebx
  hkaiOverlapManagerSection *v12; // rsi
  __int64 m_size; // rax
  __int64 v14; // r8
  int *p_m_capacityAndFlags; // rax
  hkaiOverlapManagerSection *v16; // rbp
  hkaiNavMeshInstance *m_instancePtr; // rbx
  __int64 v18; // rsi
  hkaiSilhouetteGenerator *m_pntr; // rbx
  hkaiOverlapManagerSection::GeneratorData *v20; // rax
  hkQTransformf v21; // [rsp+30h] [rbp-68h] BYREF
  hkQTransformf initialRelativeTransform; // [rsp+50h] [rbp-48h] BYREF
  hkResult v23; // [rsp+A8h] [rbp+10h] BYREF

  v3 = sectionIndex;
  v4 = 0;
  v6 = sectionIndex + 1;
  if ( this->m_sections.m_size < sectionIndex + 1 )
  {
    v8 = this->m_sections.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < v6 )
    {
      v9 = 2 * v8;
      v10 = sectionIndex + 1;
      if ( v6 < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(&v23, &hkContainerHeapAllocator::s_alloc, &this->m_sections, v10, 72);
    }
    v11 = this->m_sections.m_size - v6 - 1;
    if ( v11 >= 0 )
    {
      v12 = &this->m_sections.m_data[v6 + v11];
      do
      {
        hkaiOverlapManagerSection::~hkaiOverlapManagerSection(v12--);
        --v11;
      }
      while ( v11 >= 0 );
    }
    m_size = this->m_sections.m_size;
    v14 = v6 - (int)m_size;
    if ( v6 - (int)m_size > 0 )
    {
      p_m_capacityAndFlags = &this->m_sections.m_data[m_size].m_generatorData.m_capacityAndFlags;
      do
      {
        if ( p_m_capacityAndFlags != (int *)28 )
        {
          *(_QWORD *)(p_m_capacityAndFlags - 7) = 0i64;
          *(p_m_capacityAndFlags - 5) = 0;
          *(_QWORD *)(p_m_capacityAndFlags - 3) = 0i64;
          *(p_m_capacityAndFlags - 1) = 0;
          *p_m_capacityAndFlags = 0x80000000;
          *(_QWORD *)(p_m_capacityAndFlags + 1) = 0i64;
          p_m_capacityAndFlags[3] = 0;
          p_m_capacityAndFlags[4] = 0x80000000;
          *(_QWORD *)(p_m_capacityAndFlags + 5) = 0i64;
          p_m_capacityAndFlags[7] = 0;
          p_m_capacityAndFlags[8] = 0x80000000;
          p_m_capacityAndFlags[9] = 0;
        }
        p_m_capacityAndFlags += 18;
        --v14;
      }
      while ( v14 );
    }
    this->m_sections.m_size = v6;
  }
  v16 = &this->m_sections.m_data[v3];
  m_instancePtr = this->m_navMeshCollection.m_pntr->m_instances.m_data[v3].m_instancePtr;
  hkaiOverlapManagerSection::init(v16, m_instancePtr);
  hkQuaternionf::set(&v21.m_rotation, &m_instancePtr->m_referenceFrame.m_transform.m_rotation);
  v21.m_translation = m_instancePtr->m_referenceFrame.m_transform.m_translation;
  if ( generators && generators->m_size > 0 )
  {
    v18 = 0i64;
    do
    {
      m_pntr = generators->m_data[v18].m_pntr;
      hkQTransformf::setMulInverseMul(&initialRelativeTransform, &v21, &m_pntr->m_transform);
      v20 = hkaiOverlapManagerSection::addDataForGenerator(v16, m_pntr, &initialRelativeTransform);
      hkaiOverlapManager::queryAndUpdateFacesForGenerator(this, v3, v20, m_pntr, &initialRelativeTransform);
      ++v4;
      ++v18;
    }
    while ( v4 < generators->m_size );
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
  __int64 v5; // r14
  hkaiOverlapManagerSection *v6; // rbp
  hkaiNavMeshInstance *m_instancePtr; // rdi
  hkaiOverlapManagerSection::GeneratorData *v8; // rax
  hkQTransformf v9; // [rsp+30h] [rbp-58h] BYREF
  hkQTransformf initialRelativeTransform; // [rsp+50h] [rbp-38h] BYREF

  v2 = 0;
  if ( this->m_sections.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = &this->m_sections.m_data[v2];
      m_instancePtr = this->m_navMeshCollection.m_pntr->m_instances.m_data[v5].m_instancePtr;
      if ( m_instancePtr )
      {
        hkQuaternionf::set(&v9.m_rotation, &m_instancePtr->m_referenceFrame.m_transform.m_rotation);
        v9.m_translation = m_instancePtr->m_referenceFrame.m_transform.m_translation;
        hkQTransformf::setMulInverseMul(&initialRelativeTransform, &v9, &gen->m_transform);
        v8 = hkaiOverlapManagerSection::addDataForGenerator(v6, gen, &initialRelativeTransform);
        hkaiOverlapManager::queryAndUpdateFacesForGenerator(this, v2, v8, gen, &initialRelativeTransform);
      }
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_sections.m_size );
  }
}

// File Line: 374
// RVA: 0xBF5AB0
void __fastcall hkaiOverlapManager::recomputeOverlapsForGenerator(
        hkaiOverlapManager *this,
        hkaiSilhouetteGenerator *gen)
{
  int v2; // ebx
  __int64 v5; // rsi
  hkaiOverlapManagerSection::GeneratorData *GeneratorData; // rax

  v2 = 0;
  if ( this->m_sections.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      if ( this->m_navMeshCollection.m_pntr->m_instances.m_data[v5].m_instancePtr )
      {
        GeneratorData = hkaiOverlapManagerSection::getGeneratorData(&this->m_sections.m_data[v2], gen);
        hkaiOverlapManager::queryAndUpdateFacesForGenerator(
          this,
          v2,
          GeneratorData,
          gen,
          &GeneratorData->m_context.m_lastRelativeTransform);
      }
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_sections.m_size );
  }
}

// File Line: 390
// RVA: 0xBF5950
void __fastcall hkaiOverlapManager::removeSilhouetteGenerator(hkaiOverlapManager *this, hkaiSilhouetteGenerator *gen)
{
  int v2; // edi
  hkaiSilhouettePriorityController *m_pntr; // rcx
  char v6; // bp
  hkaiSilhouettePriorityController *v7; // rbx
  hkReferencedObject *v8; // rcx
  double v9; // xmm0_8
  float v10; // xmm6_4
  __int64 v11; // rbx
  hkaiOverlapManagerSection *v12; // rcx
  hkReferencedObject v13; // [rsp+30h] [rbp-68h] BYREF
  hkAabb v14; // [rsp+40h] [rbp-58h] BYREF
  hkReferencedObject *v15; // [rsp+A0h] [rbp+8h]

  v2 = 0;
  hkaiOverlapManager::getExtrudedAabbForGenerator(
    this,
    gen,
    &this->m_referenceFrameAndExtrusion,
    &hkQTransformfIdentity_storage,
    0i64,
    &v14);
  m_pntr = this->m_priorityController.m_pntr;
  *(_DWORD *)&v13.m_memSizeAndFlags = 0x1FFFF;
  v6 = 1;
  v13.vfptr = (hkBaseObjectVtbl *)&hkaiDefaultSilhouettePriorityController::`vftable;
  if ( m_pntr )
  {
    hkReferencedObject::addReference(m_pntr);
    v7 = this->m_priorityController.m_pntr;
    v15 = v7;
    v8 = v7;
  }
  else
  {
    v6 = 2;
    hkReferencedObject::addReference(&v13);
    v8 = &v13;
    v15 = &v13;
    v7 = (hkaiSilhouettePriorityController *)&v13;
  }
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    if ( v8 )
      hkReferencedObject::removeReference(v8);
  }
  if ( (v6 & 1) != 0 && v7 )
    hkReferencedObject::removeReference(v7);
  if ( this->m_maxCutFacesPerStep <= 0 )
  {
    v10 = *(float *)&FLOAT_1_0;
  }
  else
  {
    v9 = ((double (__fastcall *)(hkReferencedObject *, hkaiSilhouetteGenerator *, hkAabb *, hkaiReferenceFrameAndExtrusion *))v15->vfptr[2].__vecDelDtor)(
           v15,
           gen,
           &v14,
           &this->m_referenceFrameAndExtrusion);
    v10 = *(float *)&v9;
  }
  if ( this->m_sections.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = &this->m_sections.m_data[v11];
      if ( v12->m_numOriginalFaces )
        hkaiOverlapManagerSection::removeDataForGenerator(v12, gen, v10);
      ++v2;
      ++v11;
    }
    while ( v2 < this->m_sections.m_size );
  }
}

// File Line: 414
// RVA: 0xBF5B50
void __fastcall hkaiOverlapManager::updateOverlapsOfAllGenerators(
        hkaiOverlapManager *this,
        hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *generators,
        hkBitField *sectionsToUpdate,
        char updateFlags)
{
  _QWORD *Value; // rdi
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __int64 m_size; // rbx
  bool v13; // zf
  _DWORD *m_cur; // rdx
  int v15; // edi
  hkLifoAllocator *v16; // rax
  int v17; // ecx
  char *v18; // r8
  int v19; // r9d
  __int64 v20; // rcx
  _DWORD *v21; // rdi
  __m128 v22; // xmm0
  __m128 v23; // xmm6
  __int64 v24; // rsi
  __int64 v25; // r12
  int v26; // r14d
  int v27; // ebx
  hkaiSilhouetteGenerator *m_pntr; // rdi
  int v29; // r15d
  unsigned __int64 v30; // rbx
  __int64 v31; // rax
  hkVector4f *v32; // rdi
  int v33; // esi
  __int64 v34; // r14
  hkaiSilhouetteGenerator *v35; // rbx
  hkaiOverlapManagerSection::GeneratorData *GeneratorData; // rdi
  hkaiOverlapManagerSection *v37; // rdx
  char v38; // al
  __m128 m_quad; // xmm3
  __m128 v40; // xmm0
  __m128 v41; // xmm1
  _QWORD *v42; // rdi
  _QWORD *v43; // rcx
  unsigned __int64 v44; // rax
  _QWORD *v45; // rcx
  hkaiOverlapManagerSection *v46[2]; // [rsp+30h] [rbp-59h] BYREF
  hkQTransformf array; // [rsp+40h] [rbp-49h] BYREF
  hkVector4f v48; // [rsp+60h] [rbp-29h] BYREF
  hkQTransformf v49[3]; // [rsp+70h] [rbp-19h] BYREF
  char v50; // [rsp+F0h] [rbp+67h]
  _QWORD *v51; // [rsp+F8h] [rbp+6Fh]
  _QWORD *v52; // [rsp+100h] [rbp+77h]
  hkResult result; // [rsp+108h] [rbp+7Fh] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtupdateOverlaps";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_size = generators->m_size;
  if ( !sectionsToUpdate || (v13 = sectionsToUpdate->m_storage.m_numBits == 0, v50 = 1, v13) )
    v50 = 0;
  m_cur = 0i64;
  v15 = ((int)m_size + 31) >> 5;
  array.m_rotation.m_vec.m_quad.m128_u64[1] = 0i64;
  if ( v15 )
  {
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = v16->m_cur;
    v17 = (4 * v15 + 127) & 0xFFFFFF80;
    v18 = (char *)m_cur + v17;
    if ( v17 > v16->m_slabSize || v18 > v16->m_end )
      m_cur = hkLifoAllocator::allocateFromNewSlab(v16, v17);
    else
      v16->m_cur = v18;
  }
  array.m_rotation.m_vec.m_quad.m128_u64[1] = (unsigned __int64)m_cur;
  if ( (v15 & 0x3FFFFFFF) < v15 )
  {
    v19 = ((int)m_size + 31) >> 5;
    if ( v15 < 2 * (v15 & 0x3FFFFFFF) )
      v19 = 2 * (v15 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      &array.m_rotation.m_vec.m_quad.m128_u16[4],
      v19,
      4);
    m_cur = (_DWORD *)array.m_rotation.m_vec.m_quad.m128_u64[1];
  }
  if ( v15 - 1 >= 0 )
  {
    v20 = (unsigned int)v15;
    v21 = m_cur;
    while ( v20 )
    {
      *v21++ = 0;
      --v20;
    }
  }
  result.m_enum = updateFlags & 1;
  if ( (updateFlags & 1) != 0 )
    v22 = _mm_sub_ps((__m128)0i64, query.m_quad);
  else
    v22 = _mm_shuffle_ps((__m128)LODWORD(this->m_hasMovedTolerance), (__m128)LODWORD(this->m_hasMovedTolerance), 0);
  *(__m128 *)v46 = v22;
  v23 = v22;
  v24 = 0i64;
  v25 = m_size;
  v26 = 0;
  v27 = 1;
  *(hkVector4f *)v46 = this->m_referenceFrameAndExtrusion.m_up;
  if ( v25 > 0 )
  {
    do
    {
      m_pntr = generators->m_data[v24].m_pntr;
      m_pntr->vfptr[3].__vecDelDtor(m_pntr, (unsigned int)v46);
      if ( ((unsigned __int8 (__fastcall *)(hkaiSilhouetteGenerator *))m_pntr->vfptr[4].__first_virtual_table_function__)(m_pntr) )
        *(_DWORD *)(array.m_rotation.m_vec.m_quad.m128_u64[1] + 4 * ((__int64)v26 >> 5)) |= v27;
      v27 = __ROL4__(v27, 1);
      ++v24;
      ++v26;
    }
    while ( v24 < v25 );
  }
  v29 = 0;
  if ( this->m_sections.m_size > 0 )
  {
    v30 = 0i64;
    array.m_rotation.m_vec.m_quad.m128_u64[0] = 0i64;
    do
    {
      if ( !v50 || ((*(_DWORD *)(*v52 + 4 * ((__int64)v29 >> 5)) >> (v29 & 0x1F)) & 1) != 0 )
      {
        v46[0] = &this->m_sections.m_data[v29];
        v31 = *(__int64 *)((char *)&this->m_navMeshCollection.m_pntr->m_instances.m_data->m_instancePtr + v30);
        v46[0] = (hkaiOverlapManagerSection *)v31;
        if ( v31 )
        {
          v32 = (hkVector4f *)(v31 + 112);
          hkQuaternionf::set(&v49[0].m_rotation, (hkRotationf *)(v31 + 112));
          v33 = 0;
          v34 = 0i64;
          v49[0].m_translation = (hkVector4f)v32[3].m_quad;
          if ( v25 > 0 )
          {
            do
            {
              v35 = *(hkaiSilhouetteGenerator **)(*v51 + 8 * v34);
              GeneratorData = hkaiOverlapManagerSection::getGeneratorData(v46[0], v35);
              hkQTransformf::setMulInverseMul(&array, v49, &v35->m_transform);
              v37 = v46[0];
              GeneratorData->m_context.m_generatedLastFrame.m_bool = GeneratorData->m_context.m_generatingThisFrame.m_bool;
              v48.m_quad = (__m128)this->m_referenceFrameAndExtrusion.m_up;
              v38 = ((__int64 (__fastcall *)(hkaiSilhouetteGenerator *, hkaiOverlapManagerSection *, hkVector4f *))v35->vfptr[5].__vecDelDtor)(
                      v35,
                      v37,
                      &v48);
              v13 = result.m_enum == HK_SUCCESS;
              GeneratorData->m_context.m_generatingThisFrame.m_bool = v38;
              if ( !v13
                || (GeneratorData->m_context.m_generatedLastFrame.m_bool != 0) != (v38 != 0)
                || v38
                && (((*(_DWORD *)(array.m_rotation.m_vec.m_quad.m128_u64[1] + 4 * ((__int64)v33 >> 5)) >> (v33 & 0x1F)) & 1) != 0
                 || ((m_quad = GeneratorData->m_context.m_lastRelativeTransform.m_rotation.m_vec.m_quad,
                      v40 = _mm_mul_ps(array.m_rotation.m_vec.m_quad, m_quad),
                      v41 = _mm_add_ps(_mm_shuffle_ps(v40, v40, 78), v40),
                      _mm_movemask_ps(
                        _mm_cmplt_ps(
                          (__m128)_mm_srli_epi32(
                                    _mm_slli_epi32(
                                      (__m128i)_mm_sub_ps(
                                                 m_quad,
                                                 _mm_xor_ps(
                                                   (__m128)_mm_slli_epi32(
                                                             _mm_srli_epi32(
                                                               (__m128i)_mm_add_ps(_mm_shuffle_ps(v41, v41, 177), v41),
                                                               0x1Fu),
                                                             0x1Fu),
                                                   array.m_rotation.m_vec.m_quad)),
                                      1u),
                                    1u),
                          v23)) != 15)
                  || (_mm_movemask_ps(
                        _mm_cmplt_ps(
                          (__m128)_mm_srli_epi32(
                                    _mm_slli_epi32(
                                      (__m128i)_mm_sub_ps(
                                                 GeneratorData->m_context.m_lastRelativeTransform.m_translation.m_quad,
                                                 array.m_translation.m_quad),
                                      1u),
                                    1u),
                          v23)) & 7) != 7)
                 && hkaiSilhouetteGenerator::hasMovedAgainstSection(
                      v35,
                      &GeneratorData->m_context.m_lastRelativeTransform,
                      &array)) )
              {
                GeneratorData->m_context.m_lastRelativeTransform = array;
                hkaiOverlapManager::queryAndUpdateFacesForGenerator(this, v29, GeneratorData, v35, &array);
              }
              ++v34;
              ++v33;
            }
            while ( v34 < v25 );
            v30 = array.m_rotation.m_vec.m_quad.m128_u64[0];
          }
        }
      }
      v30 += 48i64;
      ++v29;
      array.m_rotation.m_vec.m_quad.m128_u64[0] = v30;
    }
    while ( v29 < this->m_sections.m_size );
  }
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&array.m_rotation.m_vec.m_quad.m128_u16[4]);
  v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v43 = (_QWORD *)v42[1];
  if ( (unsigned __int64)v43 < v42[3] )
  {
    *v43 = "Et";
    v44 = __rdtsc();
    v45 = v43 + 2;
    *((_DWORD *)v45 - 2) = v44;
    v42[1] = v45;
  }
}

// File Line: 619
// RVA: 0xBF7AB0
__int64 __fastcall hkaiOverlapManager::testLocalAabbAgainstFace(
        hkAabb *aabbLocal,
        hkaiNavMeshInstance *meshInstance,
        int faceIndex)
{
  hkaiNavMesh *m_pntr; // rdx

  m_pntr = meshInstance->m_originalMesh.m_pntr;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(m_pntr->m_aabb.m_min.m_quad, aabbLocal->m_max.m_quad),
            _mm_cmple_ps(aabbLocal->m_min.m_quad, m_pntr->m_aabb.m_max.m_quad))) & 7) == 7 )
    return hkaiNavMeshUtils::faceAabbCheck(aabbLocal, m_pntr, faceIndex);
  else
    return 0i64;
}

// File Line: 694
// RVA: 0xBF6110
void __fastcall hkaiOverlapManager::getUpdatedFaces(
        hkaiOverlapManager *this,
        hkaiNavMeshCutter *cutter,
        hkArray<unsigned int,hkContainerTempAllocator> *cutFaceKeysOut,
        hkArray<unsigned int,hkContainerTempAllocator> *uncutFaceKeysOut,
        hkBitField *sectionsToUpdate)
{
  hkaiOverlapManager *v5; // r15
  _QWORD *Value; // r10
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // rax
  char v11; // bl
  int m_size; // r9d
  int v13; // r12d
  __int64 v14; // rdi
  __int64 v15; // r13
  __int64 v16; // r14
  __int64 v17; // rsi
  int v18; // edx
  __int64 v19; // rcx
  int v20; // r9d
  _DWORD *v21; // rax
  int v22; // ebx
  __int64 v23; // r8
  bool v24; // r9
  char *v25; // rax
  bool v26; // al
  float v27; // xmm6_4
  FacePriorityPair *v28; // rdx
  unsigned int m_faceKey; // xmm0_4
  int v30; // r8d
  int v31; // r10d
  __int64 v32; // rcx
  _DWORD *v33; // rdx
  bool v34; // sf
  hkResultEnum m_enum; // r9d
  bool v36; // cc
  int v37; // esi
  __int64 v38; // r10
  __int64 v39; // r11
  __int64 v40; // r14
  __int64 v41; // rbx
  int v42; // r8d
  int v43; // eax
  int v44; // ecx
  int index; // r15d
  __int64 v46; // r12
  __int64 v47; // r13
  unsigned int v48; // ecx
  int v49; // r8d
  __int64 v50; // r9
  int v51; // ecx
  int v52; // edx
  int v53; // eax
  hkIntRealPair *p_key; // rax
  hkaiNavMesh::Face *v55; // rdi
  int v56; // r11d
  char *v57; // rax
  FacePriorityPair *v58; // rdx
  unsigned int m_shouldCut; // xmm0_4
  __int16 m_numUserEdges; // si
  int m_startEdgeIndex; // ebx
  int v62; // r12d
  hkaiNavMesh::Edge *v63; // r13
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v64; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v65; // r8
  hkaiNavMesh::Edge *v66; // rax
  unsigned int m_oppositeFace; // edx
  unsigned int v68; // eax
  int v69; // ecx
  bool v70; // zf
  __int64 v71; // rdx
  unsigned int v72; // eax
  int v73; // ecx
  __int64 v74; // rax
  int m_startUserEdgeIndex; // edx
  FacePriorityPair *v76; // rdx
  unsigned int v77; // xmm0_4
  __int64 v78; // rbx
  int v79; // eax
  int v80; // eax
  int v81; // r9d
  hkArray<unsigned int,hkContainerTempAllocator> *v82; // r10
  int v83; // eax
  int v84; // eax
  int v85; // r9d
  __int64 v86; // rdi
  __int64 v87; // rbx
  unsigned int v88; // edx
  __int64 v89; // rax
  _QWORD *v90; // rax
  _QWORD *v91; // rcx
  _QWORD *v92; // r8
  unsigned __int64 v93; // rax
  _QWORD *v94; // rcx
  char v95; // [rsp+30h] [rbp-C8h] BYREF
  char v96; // [rsp+31h] [rbp-C7h] BYREF
  char v97[6]; // [rsp+32h] [rbp-C6h] BYREF
  hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > array; // [rsp+38h] [rbp-C0h] BYREF
  int v99; // [rsp+48h] [rbp-B0h]
  __int64 v100; // [rsp+50h] [rbp-A8h]
  int v101; // [rsp+58h] [rbp-A0h]
  __int64 v102; // [rsp+60h] [rbp-98h]
  hkResult result; // [rsp+68h] [rbp-90h] BYREF
  int v104; // [rsp+6Ch] [rbp-8Ch]
  __int64 v105; // [rsp+70h] [rbp-88h]
  FacePriorityPair entry; // [rsp+78h] [rbp-80h] BYREF
  __int64 v107; // [rsp+88h] [rbp-70h]
  __int64 v108; // [rsp+90h] [rbp-68h]
  FacePriorityPair v109; // [rsp+98h] [rbp-60h] BYREF
  FacePriorityPair v110; // [rsp+A8h] [rbp-50h] BYREF
  hkaiOverlapManager *retaddr; // [rsp+118h] [rbp+20h] BYREF
  hkIntRealPair key; // [rsp+138h] [rbp+40h] BYREF

  key = (hkIntRealPair)uncutFaceKeysOut;
  v5 = this;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TthkaiOverlapManager::getUpdatedFaces";
    v8 = __rdtsc();
    v9 = v7 + 2;
    *((_DWORD *)v9 - 2) = v8;
    Value[1] = v9;
  }
  v10 = (_QWORD *)key;
  v11 = *(_QWORD *)&key && *(_DWORD *)(*(_QWORD *)&key + 16i64);
  m_size = v5->m_sections.m_size;
  v95 = v11;
  array.m_contents.m_data = 0i64;
  array.m_contents.m_size = 0;
  array.m_contents.m_capacityAndFlags = 0x80000000;
  v99 = m_size;
  if ( m_size > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, m_size, 12);
    v10 = (_QWORD *)key;
  }
  v13 = 0;
  if ( SLODWORD(v5->m_navMeshCollection.m_pntr) > 0 )
  {
    v14 = 0i64;
    v15 = 0i64;
    do
    {
      if ( !v11 || ((*(_DWORD *)(*v10 + 4 * ((__int64)v13 >> 5)) >> (v13 & 0x1F)) & 1) != 0 )
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
              v23 = (int)*(_QWORD *)(*(_QWORD *)(v14 + v17 + 48) + 8i64 * v22);
              v108 = *(_QWORD *)(*(_QWORD *)(v14 + v17 + 48) + 8i64 * v22);
              v24 = *(_DWORD *)(*(_QWORD *)(v14 + v17 + 32) + 16 * v23 + 8) != 0;
              if ( *(_DWORD *)(v16 + 328) )
              {
                v25 = &v96;
                v96 = *(_BYTE *)(v23 + *(_QWORD *)(v16 + 320));
              }
              else
              {
                v97[0] = 0;
                v25 = v97;
              }
              v26 = v24 || (*v25 & 4) != 0;
              v27 = *((float *)&v108 + 1);
              entry.m_priority = *((float *)&v108 + 1);
              entry.m_faceKey = v26;
              if ( v99 <= 0 )
              {
                if ( array.m_contents.m_size == (array.m_contents.m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 12);
                v28 = &array.m_contents.m_data[array.m_contents.m_size];
                if ( v28 )
                {
                  v28->m_faceKey = entry.m_faceKey;
                  m_faceKey = entry.m_faceKey;
                  v28->m_priority = v27;
                  v28->m_shouldCut = m_faceKey;
                }
                ++array.m_contents.m_size;
                goto LABEL_36;
              }
              if ( array.m_contents.m_size < v99 )
                goto LABEL_35;
              if ( *((float *)&v108 + 1) > array.m_contents.m_data->m_priority )
                break;
LABEL_36:
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
                goto LABEL_42;
              }
            }
            hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::removeEntry(&array, 0);
LABEL_35:
            hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(&array, &entry);
            goto LABEL_36;
          }
LABEL_42:
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
  if ( v99 > 0 && array.m_contents.m_size >= v99 )
  {
    v34 = SLODWORD(v5->m_sections.m_data) < 0;
    m_enum = (__int64)v5->m_sections.m_data & 0x8000000F;
    result.m_enum = m_enum;
    if ( v34 )
    {
      m_enum = (((_BYTE)m_enum - 1) | 0xFFFFFFF0) + 1;
      result.m_enum = m_enum;
    }
    v36 = SLODWORD(v5->m_navMeshCollection.m_pntr) <= 0;
    v37 = 0;
    v104 = 0;
    if ( !v36 )
    {
      v38 = 0i64;
      v100 = 0i64;
      v39 = 0i64;
      v108 = 0i64;
      while ( 1 )
      {
        v40 = *(_QWORD *)(v39 + *(_QWORD *)(*(_QWORD *)&v5->m_referenceFrameAndExtrusion.m_cellExtrusion + 32i64));
        if ( v40 )
          break;
LABEL_119:
        ++v37;
        v39 += 48i64;
        v38 += 72i64;
        v104 = v37;
        v108 = v39;
        v100 = v38;
        if ( v37 >= SLODWORD(v5->m_navMeshCollection.m_pntr) )
          goto LABEL_120;
      }
      v41 = *(_QWORD *)&v5->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage;
      v42 = *(_DWORD *)(v38 + v41 + 8);
      v102 = v41;
      v43 = (v42 + 15) / 16;
      v44 = v43 * (m_enum + 1);
      index = m_enum * v43;
      if ( v42 < v44 )
        v44 = v42;
      v46 = index;
      v101 = m_enum * v43;
      v107 = index;
      *(_QWORD *)&entry.m_faceKey = v44;
      if ( index >= (__int64)v44 )
      {
LABEL_118:
        v5 = retaddr;
        goto LABEL_119;
      }
      v47 = 16i64 * index;
      v105 = v47;
      v48 = -1640531535 * index;
      entry.m_shouldCut = -1640531535 * index;
      while ( 1 )
      {
        v49 = *(_DWORD *)(v38 + v41 + 56) - 1;
        if ( v49 <= 0
          || (v50 = *(_QWORD *)(v38 + v41 + 48), v51 = v49 & v48, v52 = *(_DWORD *)(v50 + 8i64 * v51), v52 == -1) )
        {
LABEL_59:
          v53 = *(_DWORD *)(v38 + v41 + 56);
        }
        else
        {
          while ( v52 != index )
          {
            v51 = v49 & (v51 + 1);
            v52 = *(_DWORD *)(v50 + 8i64 * v51);
            if ( v52 == -1 )
              goto LABEL_59;
          }
          v53 = v51;
        }
        if ( v53 <= v49 )
          goto LABEL_116;
        if ( *(_DWORD *)(v40 + 328) )
        {
          p_key = &key;
          LOBYTE(key.m_key) = *(_BYTE *)(v46 + *(_QWORD *)(v40 + 320));
        }
        else
        {
          v97[0] = 0;
          p_key = (hkIntRealPair *)v97;
        }
        if ( (p_key->m_key & 1) == 0 || *(_DWORD *)(*(_QWORD *)(v38 + v41 + 32) + v47 + 8) )
          goto LABEL_116;
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
        if ( (*v57 & 4) == 0 )
          break;
        if ( (unsigned int)hkaiNavMeshCutter::getNumCutKeysFromOriginal(
                             (hkaiNavMeshCutter *)this,
                             index | (unsigned int)(v37 << 22)) != 1 )
        {
          v109.m_priority = 0.0;
          v109.m_faceKey = index | (v37 << 22);
          v109.m_shouldCut = 1;
          if ( v99 > 0 )
          {
            if ( array.m_contents.m_size >= v99 )
            {
              if ( array.m_contents.m_data->m_priority < 0.0 )
              {
                hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::removeEntry(&array, 0);
                hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(&array, &v109);
              }
            }
            else
            {
              hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(&array, &v109);
            }
          }
          else
          {
            if ( array.m_contents.m_size == (array.m_contents.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 12);
            v58 = &array.m_contents.m_data[array.m_contents.m_size];
            if ( v58 )
            {
              v58->m_faceKey = v109.m_faceKey;
              m_shouldCut = v109.m_shouldCut;
              v58->m_priority = 0.0;
              v58->m_shouldCut = m_shouldCut;
            }
            ++array.m_contents.m_size;
          }
        }
LABEL_115:
        v41 = v102;
        v38 = v100;
LABEL_116:
        ++v46;
        ++index;
        v48 = entry.m_shouldCut - 1640531535;
        v47 += 16i64;
        v101 = index;
        entry.m_shouldCut -= 1640531535;
        v107 = v46;
        v105 = v47;
        if ( v46 >= *(__int64 *)&entry.m_faceKey )
        {
          m_enum = result.m_enum;
          v39 = v108;
          goto LABEL_118;
        }
      }
      m_numUserEdges = v55->m_numUserEdges;
      if ( m_numUserEdges <= 0 )
        m_startEdgeIndex = v55->m_startEdgeIndex;
      else
        m_startEdgeIndex = v55->m_startUserEdgeIndex;
      if ( m_startEdgeIndex == -1 )
      {
LABEL_104:
        v37 = v104;
        v110.m_priority = 0.0;
        v110.m_shouldCut = 0;
        v110.m_faceKey = index | (v104 << 22);
        if ( v99 > 0 )
        {
          if ( array.m_contents.m_size >= v99 )
          {
            if ( array.m_contents.m_data->m_priority < 0.0 )
            {
              hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::removeEntry(&array, 0);
              hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(&array, &v110);
            }
          }
          else
          {
            hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(&array, &v110);
          }
        }
        else
        {
          if ( array.m_contents.m_size == (array.m_contents.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 12);
          v76 = &array.m_contents.m_data[array.m_contents.m_size];
          if ( v76 )
          {
            v76->m_faceKey = v110.m_faceKey;
            v77 = v110.m_shouldCut;
            v76->m_priority = 0.0;
            v76->m_shouldCut = v77;
          }
          ++array.m_contents.m_size;
        }
        goto LABEL_115;
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
                m_startEdgeIndex);
        if ( v66->m_oppositeEdge != -1 )
        {
          m_oppositeFace = v66->m_oppositeFace;
          if ( (v66->m_flags.m_storage & 0x40) != 0 )
            v68 = m_oppositeFace & 0xFFC00000;
          else
            v68 = *(_DWORD *)(v40 + 472) << 22;
          v69 = v68 | m_oppositeFace & 0x3FFFFF;
          v70 = m_oppositeFace == -1;
          v71 = *(_QWORD *)&retaddr->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage;
          if ( v70 )
            v69 = -1;
          v72 = v69;
          v73 = v69 & 0x3FFFFF;
          v74 = 9i64 * (v72 >> 22);
          if ( v73 < *(_DWORD *)(v71 + 8 * v74 + 40) )
          {
            if ( *(_DWORD *)(*(_QWORD *)(v71 + 8 * v74 + 32) + 16i64 * v73 + 8) )
            {
              index = v101;
              v46 = v107;
              v47 = v105;
              v37 = v104;
              goto LABEL_115;
            }
          }
        }
        m_startUserEdgeIndex = v55->m_startUserEdgeIndex;
        if ( m_startEdgeIndex >= m_startUserEdgeIndex && m_startEdgeIndex < m_numUserEdges + m_startUserEdgeIndex - 1 )
          goto LABEL_101;
        if ( m_startEdgeIndex != m_numUserEdges + m_startUserEdgeIndex - 1 )
          break;
        m_startEdgeIndex = v55->m_startEdgeIndex;
LABEL_102:
        if ( m_startEdgeIndex == -1 )
          goto LABEL_103;
      }
      if ( m_startEdgeIndex < v55->m_startEdgeIndex || m_startEdgeIndex >= v55->m_numEdges + v55->m_startEdgeIndex - 1 )
      {
LABEL_103:
        index = v101;
        v46 = v107;
        v47 = v105;
        goto LABEL_104;
      }
LABEL_101:
      ++m_startEdgeIndex;
      goto LABEL_102;
    }
  }
LABEL_120:
  v78 = array.m_contents.m_size;
  v79 = *(_DWORD *)(&cutter->m_referenceCount + 1) & 0x3FFFFFFF;
  if ( v79 < array.m_contents.m_size )
  {
    v80 = 2 * v79;
    v81 = array.m_contents.m_size;
    if ( array.m_contents.m_size < v80 )
      v81 = v80;
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerTempAllocator::s_alloc, cutter, v81, 4);
  }
  v82 = cutFaceKeysOut;
  v83 = cutFaceKeysOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v83 < (int)v78 )
  {
    v84 = 2 * v83;
    v85 = v78;
    if ( (int)v78 < v84 )
      v85 = v84;
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerTempAllocator::s_alloc, cutFaceKeysOut, v85, 4);
    v82 = cutFaceKeysOut;
  }
  v86 = v78;
  if ( (int)v78 > 0 )
  {
    key.m_value = 0.0;
    v87 = 0i64;
    do
    {
      v88 = array.m_contents.m_data[v87].m_faceKey;
      if ( array.m_contents.m_data[v87].m_shouldCut )
        *((_DWORD *)&cutter->vfptr->__vecDelDtor + (int)(*(_DWORD *)&cutter->m_memSizeAndFlags)++) = v88;
      else
        v82->m_data[v82->m_size++] = v88;
      v89 = *(_QWORD *)&v5->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage;
      key.m_key = v88 & 0x3FFFFF;
      hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::remove(
        (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)(v89
                                                                                        + 8
                                                                                        * ((v88 >> 22)
                                                                                         + 8i64 * (v88 >> 22)
                                                                                         + 6)),
        (hkResult *)&retaddr,
        key);
      v82 = cutFaceKeysOut;
      ++v87;
      --v86;
    }
    while ( v86 );
  }
  array.m_contents.m_size = 0;
  if ( array.m_contents.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_contents.m_data,
      12 * (array.m_contents.m_capacityAndFlags & 0x3FFFFFFF));
  array.m_contents.m_data = 0i64;
  array.m_contents.m_capacityAndFlags = 0x80000000;
  v90 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v91 = (_QWORD *)v90[1];
  v92 = v90;
  if ( (unsigned __int64)v91 < v90[3] )
  {
    *v91 = "Et";
    v93 = __rdtsc();
    v94 = v91 + 2;
    *((_DWORD *)v94 - 2) = v93;
    v92[1] = v94;
  }
}

// File Line: 887
// RVA: 0xBF6AB0
void __fastcall hkaiOverlapManager::gatherSilhouettesForFace(
        hkaiOverlapManager *this,
        unsigned int faceKey,
        hkaiSilhouetteGenerationParameters *genParamsIn,
        hkArray<hkArray<hkVector4f,hkContainerTempAllocator>,hkContainerTempAllocator> *silsOut,
        hkArray<int,hkContainerTempAllocator> *silsMaterials)
{
  int v5; // r12d
  hkaiOverlapManager *v6; // rdi
  __int64 v7; // rax
  hkReferencedObject *v8; // rcx
  hkaiOverlapManagerSection *v9; // r13
  int v10; // r14d
  char v12; // r15
  hkReferencedObject *v13; // rbx
  hkReferencedObject *v14; // rcx
  __int64 v15; // r13
  __int64 v16; // rcx
  hkSimdFloat32 *instance; // r10
  char v18; // bl
  char v19; // bl
  char v20; // al
  int v21; // xmm1_4
  int v22; // xmm1_4
  int v23; // xmm0_4
  hkVector4f v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __m128 v31; // xmm6
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  hkaiSilhouettePriorityController *v35; // r8
  hkaiSilhouetteGeneratorSectionContext *v36; // rax
  __int64 v37; // r15
  hkaiSilhouetteGeneratorSectionContext *v38; // rbx
  hkaiSilhouetteGeneratorSectionContext *v39; // rdx
  int m_size; // edi
  int m_materialId; // r14d
  hkaiNavMeshInstance *meshInstance; // [rsp+30h] [rbp-98h]
  hkaiNavMeshInstance *meshInstancea; // [rsp+30h] [rbp-98h]
  int v44; // [rsp+38h] [rbp-90h]
  int faceIndex[4]; // [rsp+40h] [rbp-88h] BYREF
  hkaiSilhouettePriorityController *controller; // [rsp+50h] [rbp-78h] BYREF
  int v47; // [rsp+58h] [rbp-70h] BYREF
  float v48; // [rsp+5Ch] [rbp-6Ch]
  void **v49; // [rsp+60h] [rbp-68h] BYREF
  hkaiSilhouetteReferenceFrame v50; // [rsp+68h] [rbp-60h] BYREF
  hkAabb referenceAxis[2]; // [rsp+98h] [rbp-30h] BYREF
  hkaiOverlapManager *v52; // [rsp+118h] [rbp+50h]
  unsigned int v53; // [rsp+120h] [rbp+58h]
  hkaiSilhouetteGeneratorSectionContext *generatorContexts[3]; // [rsp+128h] [rbp+60h] BYREF

  v5 = 0;
  v6 = this;
  *(_QWORD *)faceIndex = faceKey >> 22;
  v7 = *(_QWORD *)&this->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage;
  v8 = *(hkReferencedObject **)&this->m_maxCutFacesPerStep;
  v9 = (hkaiOverlapManagerSection *)(v7 + 72i64 * *(_QWORD *)faceIndex);
  v10 = faceKey & 0x3FFFFF;
  referenceAxis[0].m_min.m_quad.m128_u64[0] = (unsigned __int64)v9;
  v53 = faceKey & 0x3FFFFF;
  v50.m_up.m_quad.m128_i32[0] = 0x1FFFF;
  v49 = &hkaiDefaultSilhouettePriorityController::`vftable;
  if ( v8 )
  {
    v12 = 1;
    hkReferencedObject::addReference(v8);
    v13 = *(hkReferencedObject **)&v6->m_maxCutFacesPerStep;
    meshInstance = (hkaiNavMeshInstance *)v13;
    v14 = v13;
  }
  else
  {
    v12 = 2;
    hkReferencedObject::addReference((hkReferencedObject *)&v49);
    v14 = (hkReferencedObject *)&v49;
    meshInstance = (hkaiNavMeshInstance *)&v49;
    v13 = (hkReferencedObject *)&v49;
  }
  controller = (hkaiSilhouettePriorityController *)meshInstance;
  if ( (v12 & 2) != 0 )
  {
    v12 &= ~2u;
    if ( v14 )
      hkReferencedObject::removeReference(v14);
  }
  if ( (v12 & 1) != 0 && v13 )
    hkReferencedObject::removeReference(v13);
  v44 = hkaiOverlapManagerSection::sortGeneratorsForFace(v9, controller, v10);
  faceIndex[2] = -1082130432;
  v15 = *(_QWORD *)(referenceAxis[0].m_min.m_quad.m128_u64[0] + 32) + 16i64 * v10;
  v16 = *(_QWORD *)&v6->m_referenceFrameAndExtrusion.m_cellExtrusion;
  faceIndex[3] = -1082130432;
  instance = *(hkSimdFloat32 **)(*(_QWORD *)(v16 + 32) + 48i64 * *(_QWORD *)faceIndex);
  meshInstancea = (hkaiNavMeshInstance *)instance;
  v18 = *(_BYTE *)(instance[6].m_real.m128_u64[0] + 120);
  v47 = 0;
  memset(&v50, 0, 32);
  v48 = FLOAT_0_40000001;
  v49 = (void **)__PAIR64__(LODWORD(FLOAT_0_0049999999), LODWORD(FLOAT_50_0));
  v19 = v18 & 1;
  if ( v19 )
  {
    v20 = v6->m_referenceFrameAndExtrusion.m_up.m_quad.m128_i8[8];
    v21 = v6->m_referenceFrameAndExtrusion.m_up.m_quad.m128_i32[1];
    faceIndex[2] = v6->m_referenceFrameAndExtrusion.m_up.m_quad.m128_i32[0];
    faceIndex[3] = v21;
    LOBYTE(controller) = v20;
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&controller,
      instance,
      (hkaiNavMeshInstance *)(unsigned int)v10,
      (__m128 *)faceIndex);
    *(hkVector4f *)((char *)&v50.m_up + 8) = *(hkVector4f *)faceIndex;
    v22 = generatorContexts[0]->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_i32[1];
    v47 = generatorContexts[0]->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_i32[0];
    v23 = generatorContexts[0]->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_i32[2];
    v48 = *(float *)&v22;
    v49 = (void **)__PAIR64__(generatorContexts[0]->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_i32[3], v23);
    v50.m_up = generatorContexts[0]->m_lastRelativeTransform.m_translation;
    v24.m_quad = *(__m128 *)&generatorContexts[0]->m_generator;
    v50.m_orthogonalAxis = (hkVector4f)generatorContexts[0][1].m_lastRelativeTransform.m_rotation;
    v50.m_referenceAxis = (hkVector4f)v24.m_quad;
    v25 = _mm_shuffle_ps(*(__m128 *)faceIndex, _mm_unpackhi_ps(*(__m128 *)faceIndex, (__m128)0i64), 196);
    v26 = _mm_shuffle_ps(v25, v25, 241);
    v27 = _mm_shuffle_ps(v25, v25, 206);
    v28 = _mm_mul_ps(v27, v27);
    v29 = _mm_mul_ps(v26, v26);
    v30 = _mm_cmplt_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
              _mm_shuffle_ps(v29, v29, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
              _mm_shuffle_ps(v28, v28, 170)));
    v31 = _mm_xor_ps(
            _mm_or_ps(_mm_and_ps(v27, v30), _mm_andnot_ps(v30, v26)),
            (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    v32 = _mm_mul_ps(v31, v31);
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
            _mm_shuffle_ps(v32, v32, 170));
    v34 = _mm_rsqrt_ps(v33);
    referenceAxis[0].m_min.m_quad = _mm_mul_ps(
                                      v31,
                                      _mm_andnot_ps(
                                        _mm_cmple_ps(v33, (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v34))));
    hkaiSilhouetteReferenceFrame::set(&v50, (hkVector4f *)faceIndex, &referenceAxis[0].m_min);
    instance = (hkSimdFloat32 *)meshInstancea;
    v35 = (hkaiSilhouettePriorityController *)&v50.m_up.m_quad.m128_u16[4];
  }
  else
  {
    v35 = (hkaiSilhouettePriorityController *)&v6->hkaiNavMeshSilhouetteSelector;
  }
  v36 = (hkaiSilhouetteGeneratorSectionContext *)&v47;
  if ( !v19 )
    v36 = generatorContexts[0];
  controller = v35;
  v37 = 0i64;
  *(_QWORD *)faceIndex = v36;
  if ( *(int *)(v15 + 8) > 0 )
  {
    v38 = generatorContexts[2];
    do
    {
      v39 = *(hkaiSilhouetteGeneratorSectionContext **)(*(_QWORD *)v15 + 8 * v37);
      generatorContexts[0] = v39;
      if ( v39->m_generatingThisFrame.m_bool )
      {
        hkaiOverlapManager::getExtrudedAabbForGenerator(
          (hkaiOverlapManager *)((char *)v6 - 16),
          v39->m_generator,
          (hkaiReferenceFrameAndExtrusion *)v35,
          &v39->m_lastRelativeTransform,
          (hkaiNavMeshInstance *)instance,
          referenceAxis);
        if ( hkaiOverlapManager::testLocalAabbAgainstFace(referenceAxis, meshInstancea, v10) )
        {
          m_size = silsOut->m_size;
          hkaiSilhouetteMergerUtils::createNonmergedCompoundSilhouettes(
            generatorContexts,
            1,
            *(hkaiSilhouetteGenerationParameters **)faceIndex,
            silsOut);
          if ( v37 < v44 )
            m_materialId = -1;
          else
            m_materialId = generatorContexts[0]->m_generator->m_materialId;
          for ( ; m_size < silsOut->m_size; ++v38->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_i32[2] )
          {
            if ( v38->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_i32[2] == (v38->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_i32[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v38, 4);
            ++m_size;
            *(_DWORD *)(v38->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_u64[0]
                      + 4i64 * v38->m_lastRelativeTransform.m_rotation.m_vec.m_quad.m128_i32[2]) = m_materialId;
          }
          v10 = v53;
          v6 = v52;
        }
      }
      instance = (hkSimdFloat32 *)meshInstancea;
      v35 = controller;
      ++v5;
      ++v37;
    }
    while ( v5 < *(_DWORD *)(v15 + 8) );
  }
}

// File Line: 984
// RVA: 0xBF6EE0
void __fastcall hkaiOverlapManager::setupJobForFace(
        hkaiOverlapManager *this,
        unsigned int faceKey,
        hkaiNavMeshCutFaceJob *job)
{
  hkReferencedObject *v4; // rcx
  __int64 v5; // r15
  int v6; // ebp
  char v9; // di
  hkReferencedObject *v10; // rbx
  hkReferencedObject *v11; // rcx
  int v12; // r10d
  __int64 v13; // r8
  hkaiNavMeshInstance *v14; // r9
  int v15; // eax
  hkReferencedObject v16; // [rsp+20h] [rbp-48h] BYREF
  hkaiSilhouettePriorityController *v17; // [rsp+70h] [rbp+8h]

  v4 = *(hkReferencedObject **)&this->m_maxCutFacesPerStep;
  v5 = faceKey >> 22;
  v6 = faceKey & 0x3FFFFF;
  *(_DWORD *)&v16.m_memSizeAndFlags = 0x1FFFF;
  v9 = 1;
  v16.vfptr = (hkBaseObjectVtbl *)&hkaiDefaultSilhouettePriorityController::`vftable;
  if ( v4 )
  {
    hkReferencedObject::addReference(v4);
    v10 = *(hkReferencedObject **)&this->m_maxCutFacesPerStep;
    v17 = (hkaiSilhouettePriorityController *)v10;
    v11 = v10;
  }
  else
  {
    v9 = 2;
    hkReferencedObject::addReference(&v16);
    v11 = &v16;
    v17 = (hkaiSilhouettePriorityController *)&v16;
    v10 = &v16;
  }
  if ( (v9 & 2) != 0 )
  {
    v9 &= ~2u;
    if ( v11 )
      hkReferencedObject::removeReference(v11);
  }
  if ( (v9 & 1) != 0 && v10 )
    hkReferencedObject::removeReference(v10);
  v12 = hkaiOverlapManagerSection::sortGeneratorsForFace(
          (hkaiOverlapManagerSection *)(*(_QWORD *)&this->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage
                                      + 72 * v5),
          v17,
          v6);
  v13 = *(_QWORD *)(*(_QWORD *)&this->m_referenceFrameAndExtrusion.m_upTransformMethod.m_storage + 72 * v5 + 32)
      + 16i64 * v6;
  v14 = *(hkaiNavMeshInstance **)(*(_QWORD *)(*(_QWORD *)&this->m_referenceFrameAndExtrusion.m_cellExtrusion + 32i64)
                                + 48 * v5);
  job->m_faceKey = faceKey;
  job->m_meshInstance = v14;
  job->m_generatorContexts = *(hkaiSilhouetteGeneratorSectionContext *const **)v13;
  v15 = *(_DWORD *)(v13 + 8);
  job->m_firstNonCuttingGeneratorIndex = v12;
  job->m_numGenerators = v15;
  job->m_worldUp = *(hkVector4f *)&this->hkaiNavMeshSilhouetteSelector::vfptr;
  LODWORD(job->m_extrusionAmount) = this->m_referenceFrameAndExtrusion.m_up.m_quad.m128_i32[0];
  LODWORD(job->m_radiusExpansionAmount) = this->m_referenceFrameAndExtrusion.m_up.m_quad.m128_i32[1];
  job->m_isWallClimbing.m_bool = v14->m_originalMesh.m_pntr->m_flags.m_storage & 1;
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
  int i; // ebx

  for ( i = 0; i < this->m_sections.m_size; ++i )
    hkaiOverlapManagerSection::dirtyAllFaces(&this->m_sections.m_data[i]);
}

// File Line: 1074
// RVA: 0xBF79E0
void __fastcall hkaiOverlapManager::setAabbExpansion(hkaiOverlapManager *this, hkVector4f *up, float extrusion)
{
  ;
}

// File Line: 1079
// RVA: 0xBF79F0
void __fastcall hkaiOverlapManager::getExtrudedAabbForGenerator(
        hkaiOverlapManager *this,
        hkaiSilhouetteGenerator *gen,
        hkaiReferenceFrameAndExtrusion *refFrame,
        hkQTransformf *localTransform,
        hkaiNavMeshInstance *instance,
        hkAabb *aabbOut)
{
  unsigned int expansionFlags; // ecx
  __m128 m_quad; // xmm0
  float v10; // xmm1_4
  __m128 v11; // xmm1
  hkVector4f v12; // xmm1
  hkSimdFloat32 planarExpansion; // [rsp+30h] [rbp-58h] BYREF
  hkSimdFloat32 extrusion; // [rsp+40h] [rbp-48h] BYREF
  hkVector4f up; // [rsp+50h] [rbp-38h] BYREF
  hkAabb aabbInOut; // [rsp+60h] [rbp-28h] BYREF

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
  v10 = gen->m_lazyRecomputeDisplacementThreshold + refFrame->m_silhouetteRadiusExpasion;
  up.m_quad = (__m128)refFrame->m_up;
  m_quad = up.m_quad;
  m_quad.m128_f32[0] = v10;
  v11 = _mm_shuffle_ps((__m128)LODWORD(refFrame->m_cellExtrusion), (__m128)LODWORD(refFrame->m_cellExtrusion), 0);
  planarExpansion.m_real = _mm_shuffle_ps(m_quad, m_quad, 0);
  extrusion.m_real = v11;
  hkaiSilhouetteGenerator::expandAabb(&aabbInOut, &up, &extrusion, &planarExpansion, expansionFlags);
  v12.m_quad = (__m128)aabbInOut.m_max;
  aabbOut->m_min = aabbInOut.m_min;
  aabbOut->m_max = (hkVector4f)v12.m_quad;
}

// File Line: 1101
// RVA: 0xBF4910
__int64 __fastcall hkaiOverlapManagerSection::sortGeneratorsForFace(
        hkaiOverlapManagerSection *this,
        hkaiSilhouettePriorityController *controller,
        int f)
{
  hkArrayBase<char *> *v3; // rbx
  int m_size; // r9d
  int v6; // r9d
  char v7; // si
  int v8; // r10d
  __int64 v9; // rdi
  char **v10; // r11
  int v11; // edx
  int v12; // ecx
  __int64 v13; // rax
  char **v14; // rdx
  char *v15; // rax
  unsigned int v16; // ebx
  char **a; // [rsp+30h] [rbp-38h] BYREF
  int numtoinsert; // [rsp+38h] [rbp-30h]
  int v19; // [rsp+3Ch] [rbp-2Ch]
  char **v20; // [rsp+40h] [rbp-28h] BYREF
  int v21; // [rsp+48h] [rbp-20h]
  int v22; // [rsp+4Ch] [rbp-1Ch]
  _DWORD *array; // [rsp+50h] [rbp-18h] BYREF
  int v24; // [rsp+58h] [rbp-10h]
  int v25; // [rsp+5Ch] [rbp-Ch]
  hkResult result; // [rsp+90h] [rbp+28h] BYREF

  v3 = (hkArrayBase<char *> *)&this->m_faceToGeneratorsMap.m_data[f];
  controller->vfptr[3].__vecDelDtor(controller, (unsigned int)v3);
  if ( v3->m_size < 14 )
    return 0xFFFFFFFFi64;
  array = 0i64;
  v24 = 0;
  v25 = 0x80000000;
  hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, 14, 4);
  a = 0i64;
  numtoinsert = 0;
  v19 = 0x80000000;
  m_size = v3->m_size;
  if ( m_size > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &a, m_size, 8);
  v20 = 0i64;
  v21 = 0;
  v22 = 0x80000000;
  v6 = v3->m_size;
  if ( v6 > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &v20, v6, 8);
  v7 = 0;
  v8 = 0;
  if ( v3->m_size <= 0 )
  {
LABEL_19:
    v16 = -1;
    goto LABEL_20;
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
      if ( v24 <= 0 )
        goto LABEL_14;
      while ( array[v13] != v11 )
      {
        ++v13;
        ++v12;
        if ( v13 >= v24 )
          goto LABEL_14;
      }
      if ( v12 == -1 )
      {
LABEL_14:
        if ( v24 >= 14 )
        {
          v7 = 1;
          a[numtoinsert++] = *v10;
          goto LABEL_30;
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
      goto LABEL_19;
LABEL_30:
    ++v8;
    ++v9;
  }
  while ( v8 < v3->m_size );
  if ( !v7 )
    goto LABEL_19;
  v3->m_size = 0;
  hkArrayBase<unsigned __int64>::_append(v3, &hkContainerHeapAllocator::s_alloc, a, numtoinsert);
  hkArrayBase<unsigned __int64>::_append(v3, &hkContainerHeapAllocator::s_alloc, v20, v21);
  v16 = numtoinsert;
LABEL_20:
  v21 = 0;
  if ( v22 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v20, 8 * v22);
  v20 = 0i64;
  v22 = 0x80000000;
  numtoinsert = 0;
  if ( v19 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, a, 8 * v19);
  a = 0i64;
  v24 = 0;
  v19 = 0x80000000;
  if ( v25 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v25);
  return v16;
}

// File Line: 1182
// RVA: 0xBF4D50
hkaiOverlapManagerSection::GeneratorData *__fastcall hkaiOverlapManagerSection::addDataForGenerator(
        hkaiOverlapManagerSection *this,
        hkaiSilhouetteGenerator *gen,
        hkQTransformf *initialRelativeTransform)
{
  _QWORD **Value; // rax
  hkaiOverlapManagerSection::GeneratorData *v7; // rax
  hkReferencedObject *v8; // rax
  hkReferencedObject *v9; // rbx
  hkRefPtr<hkaiOverlapManagerSection::GeneratorData> *v10; // rsi

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkaiOverlapManagerSection::GeneratorData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                     Value[11],
                                                     80i64);
  if ( v7 )
  {
    hkaiOverlapManagerSection::GeneratorData::GeneratorData(v7, gen, initialRelativeTransform);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_generatorDataMap->m_map,
    &hkContainerHeapAllocator::s_alloc,
    (unsigned __int64)gen,
    this->m_generatorData.m_size);
  if ( v9 )
    hkReferencedObject::addReference(v9);
  if ( this->m_generatorData.m_size == (this->m_generatorData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_generatorData, 8);
  v10 = &this->m_generatorData.m_data[this->m_generatorData.m_size];
  if ( v10 )
  {
    if ( v9 )
      hkReferencedObject::addReference(v9);
    v10->m_pntr = (hkaiOverlapManagerSection::GeneratorData *)v9;
  }
  ++this->m_generatorData.m_size;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  hkReferencedObject::removeReference(v9);
  return (hkaiOverlapManagerSection::GeneratorData *)v9;
}

// File Line: 1195
// RVA: 0xBF44C0
void __fastcall hkaiOverlapManagerSection::init(hkaiOverlapManagerSection *this, hkaiNavMeshInstance *instance)
{
  __int64 m_numOriginalFaces; // rsi
  int v3; // eax
  int v6; // eax
  int v7; // r9d
  int v8; // eax
  __int64 v9; // rdi
  int *v10; // rbx
  int v11; // r8d
  __int64 m_size; // rax
  int v13; // ecx
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v14; // rax
  __int64 v15; // r8
  _QWORD **Value; // rax
  hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> *v17; // rax
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  m_numOriginalFaces = instance->m_numOriginalFaces;
  v3 = this->m_faceToGeneratorsMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 < (int)m_numOriginalFaces )
  {
    v6 = 2 * v3;
    v7 = instance->m_numOriginalFaces;
    if ( (int)m_numOriginalFaces < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_faceToGeneratorsMap, v7, 16);
  }
  v8 = this->m_faceToGeneratorsMap.m_size - m_numOriginalFaces - 1;
  v9 = v8;
  if ( v8 >= 0 )
  {
    v10 = &this->m_faceToGeneratorsMap.m_data[m_numOriginalFaces].m_capacityAndFlags + 4 * v8;
    do
    {
      v11 = *v10;
      *(v10 - 1) = 0;
      if ( v11 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v10 - 3),
          8 * v11);
      *(_QWORD *)(v10 - 3) = 0i64;
      *v10 = 0x80000000;
      v10 -= 4;
      --v9;
    }
    while ( v9 >= 0 );
  }
  m_size = this->m_faceToGeneratorsMap.m_size;
  v13 = m_numOriginalFaces - m_size;
  v14 = &this->m_faceToGeneratorsMap.m_data[m_size];
  v15 = v13;
  if ( v13 > 0 )
  {
    do
    {
      if ( v14 )
      {
        v14->m_data = 0i64;
        v14->m_size = 0;
        v14->m_capacityAndFlags = 0x80000000;
      }
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  this->m_faceToGeneratorsMap.m_size = m_numOriginalFaces;
  this->m_numOriginalFaces = instance->m_numOriginalFaces;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                                                        Value[11],
                                                                                        16i64);
  if ( v17 )
  {
    v17->m_map.m_elem = 0i64;
    v17->m_map.m_numElems = 0;
    v17->m_map.m_hashMod = -1;
    this->m_generatorDataMap = v17;
  }
  else
  {
    this->m_generatorDataMap = 0i64;
  }
}

// File Line: 1204
// RVA: 0xBF4640
void __fastcall hkaiOverlapManagerSection::clearGeneratorData(hkaiOverlapManagerSection *this)
{
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *m_data; // rcx
  int v3; // eax
  __int64 v4; // rdi
  int *v5; // rbx
  int v6; // r8d
  int m_capacityAndFlags; // r8d
  hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> *m_generatorDataMap; // rbx
  _QWORD **Value; // rax
  hkRefPtr<hkaiOverlapManagerSection::GeneratorData> *v10; // rdi
  int v11; // eax
  __int64 i; // rbx
  hkReferencedObject *m_pntr; // rcx

  m_data = this->m_faceToGeneratorsMap.m_data;
  v3 = this->m_faceToGeneratorsMap.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = &m_data->m_capacityAndFlags + 4 * v3;
    do
    {
      v6 = *v5;
      *(v5 - 1) = 0;
      if ( v6 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)(v5 - 3), 8 * v6);
      *(_QWORD *)(v5 - 3) = 0i64;
      *v5 = 0x80000000;
      v5 -= 4;
      --v4;
    }
    while ( v4 >= 0 );
  }
  m_capacityAndFlags = this->m_faceToGeneratorsMap.m_capacityAndFlags;
  this->m_faceToGeneratorsMap.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_faceToGeneratorsMap.m_data,
      16 * m_capacityAndFlags);
  this->m_faceToGeneratorsMap.m_data = 0i64;
  this->m_faceToGeneratorsMap.m_capacityAndFlags = 0x80000000;
  m_generatorDataMap = this->m_generatorDataMap;
  this->m_numOriginalFaces = 0;
  if ( m_generatorDataMap )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &m_generatorDataMap->m_map,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)m_generatorDataMap);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_generatorDataMap,
      16i64);
  }
  this->m_generatorDataMap = 0i64;
  v10 = this->m_generatorData.m_data;
  v11 = this->m_generatorData.m_size - 1;
  for ( i = v11; i >= 0; v10[i--].m_pntr = 0i64 )
  {
    m_pntr = v10[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  this->m_generatorData.m_size = 0;
  hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::clear(&this->m_facePriorities);
}

// File Line: 1216
// RVA: 0xBF4E40
void __fastcall hkaiOverlapManagerSection::removeDataForGenerator(
        hkaiOverlapManagerSection *this,
        hkaiSilhouetteGenerator *gen,
        float generatorPriority)
{
  Dummy *Key; // rax
  unsigned __int64 val_low; // r15
  __int64 v6; // rsi
  hkaiOverlapManagerSection::GeneratorData *m_pntr; // r13
  __int64 m_size; // r14
  int *m_data; // rax
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v10; // r10
  int v11; // ecx
  int v12; // r11d
  __int64 v13; // rdx
  __int64 v14; // r9
  hkaiSilhouetteGeneratorSectionContext **v15; // rax
  __int64 v16; // rax
  hkRefPtr<hkaiOverlapManagerSection::GeneratorData> *v17; // rdi
  hkReferencedObject *v18; // rcx
  __int64 v19; // rax
  hkRefPtr<hkaiOverlapManagerSection::GeneratorData> *v20; // rsi
  hkReferencedObject *v21; // rcx
  hkaiOverlapManagerSection::GeneratorData *v22; // rdi
  __int64 v23; // rax

  Key = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
          &this->m_generatorDataMap->m_map,
          (unsigned __int64)gen);
  val_low = SLODWORD(this->m_generatorDataMap->m_map.m_elem[(int)Key].val);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
    &this->m_generatorDataMap->m_map,
    Key);
  v6 = 0i64;
  m_pntr = this->m_generatorData.m_data[val_low].m_pntr;
  m_size = m_pntr->m_overlappedFaces.m_size;
  if ( m_size > 0 )
  {
    do
    {
      m_data = m_pntr->m_overlappedFaces.m_data;
      v10 = this->m_faceToGeneratorsMap.m_data;
      v11 = 0;
      v12 = m_data[v6];
      v13 = 0i64;
      v14 = v10[v12].m_size;
      if ( v14 <= 0 )
      {
LABEL_6:
        v11 = -1;
        v13 = -1i64;
      }
      else
      {
        v15 = v10[m_data[v6]].m_data;
        while ( *v15 != &m_pntr->m_context )
        {
          ++v13;
          ++v11;
          ++v15;
          if ( v13 >= v14 )
            goto LABEL_6;
        }
      }
      v16 = --v10[v12].m_size;
      if ( (_DWORD)v16 != v11 )
        v10[v12].m_data[v13] = v10[v12].m_data[v16];
      hkaiOverlapManagerSection::setFaceDirty(this, v12, generatorPriority);
      ++v6;
    }
    while ( v6 < m_size );
  }
  if ( (_DWORD)val_low == this->m_generatorData.m_size - 1 )
  {
    v17 = this->m_generatorData.m_data;
    v18 = v17[val_low].m_pntr;
    if ( v18 )
      hkReferencedObject::removeReference(v18);
    v17[val_low].m_pntr = 0i64;
    v19 = --this->m_generatorData.m_size;
    if ( (_DWORD)v19 != (_DWORD)val_low )
      this->m_generatorData.m_data[val_low].m_pntr = this->m_generatorData.m_data[v19].m_pntr;
  }
  else
  {
    v20 = this->m_generatorData.m_data;
    v21 = v20[val_low].m_pntr;
    v22 = v20[this->m_generatorData.m_size - 1].m_pntr;
    if ( v21 )
      hkReferencedObject::removeReference(v21);
    v20[val_low].m_pntr = 0i64;
    v23 = --this->m_generatorData.m_size;
    if ( (_DWORD)v23 != (_DWORD)val_low )
      this->m_generatorData.m_data[val_low].m_pntr = this->m_generatorData.m_data[v23].m_pntr;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &this->m_generatorDataMap->m_map,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned __int64)v22->m_context.m_generator,
      val_low);
  }
}

// File Line: 1263
// RVA: 0xBF4FE0
char __fastcall hkaiOverlapManagerSection::isOk(hkaiOverlapManagerSection *this)
{
  int v3; // ebx
  __int64 v4; // r15
  int v5; // edi
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v6; // r14
  __int64 v7; // rsi
  hkaiOverlapManagerSection::GeneratorData *GeneratorData; // rax
  int v9; // edx
  __int64 v10; // r10
  hkaiOverlapManagerSection::GeneratorData *v11; // rcx
  __int64 v12; // rax
  int *v13; // r9
  int *j; // rcx
  int v15; // edx
  __int64 v16; // rax
  int *v17; // rcx
  hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> *m_generatorDataMap; // r14
  int v19; // edx
  __int64 v20; // rcx
  __int64 m_hashMod; // r8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v23; // ebp
  int v24; // edi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v25; // r15
  __int64 v26; // r10
  hkaiOverlapManagerSection::GeneratorData *m_pntr; // rcx
  __int64 m_size; // rbx
  int *m_data; // r11
  hkaiSilhouetteGeneratorSectionContext *p_m_context; // r9
  int v31; // edx
  __int64 v32; // rcx
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v33; // rax
  __int64 v34; // r8
  hkaiSilhouetteGeneratorSectionContext **i; // rax
  __int64 v36; // r8
  int v37; // edx
  __int64 v38; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v39; // rax

  if ( !this->m_numOriginalFaces )
    return 1;
  v3 = 0;
  if ( this->m_faceToGeneratorsMap.m_size <= 0 )
  {
LABEL_21:
    m_generatorDataMap = this->m_generatorDataMap;
    v19 = 0;
    v20 = 0i64;
    m_hashMod = this->m_generatorDataMap->m_map.m_hashMod;
    if ( m_hashMod >= 0 )
    {
      m_elem = m_generatorDataMap->m_map.m_elem;
      do
      {
        if ( m_elem->key != -1i64 )
          break;
        ++v20;
        ++v19;
        ++m_elem;
      }
      while ( v20 <= m_hashMod );
    }
    v23 = m_generatorDataMap->m_map.m_hashMod;
    v24 = v19;
    if ( v19 > v23 )
    {
      return 1;
    }
    else
    {
      v25 = m_generatorDataMap->m_map.m_elem;
      while ( 1 )
      {
        v26 = 0i64;
        m_pntr = this->m_generatorData.m_data[SLODWORD(v25[v24].val)].m_pntr;
        m_size = m_pntr->m_overlappedFaces.m_size;
        if ( m_size > 0 )
          break;
LABEL_36:
        v36 = m_generatorDataMap->m_map.m_hashMod;
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
          return 1;
      }
      m_data = m_pntr->m_overlappedFaces.m_data;
      p_m_context = &m_pntr->m_context;
      while ( 1 )
      {
        v31 = 0;
        v32 = 0i64;
        v33 = &this->m_faceToGeneratorsMap.m_data[*m_data];
        v34 = v33->m_size;
        if ( v34 <= 0 )
          return 0;
        for ( i = v33->m_data; *i != p_m_context; ++i )
        {
          ++v32;
          ++v31;
          if ( v32 >= v34 )
            return 0;
        }
        if ( v31 < 0 )
          return 0;
        ++v26;
        ++m_data;
        if ( v26 >= m_size )
          goto LABEL_36;
      }
    }
  }
  else
  {
    v4 = 0i64;
    while ( 1 )
    {
      v5 = 0;
      v6 = &this->m_faceToGeneratorsMap.m_data[v4];
      if ( v6->m_size > 0 )
        break;
LABEL_20:
      ++v3;
      ++v4;
      if ( v3 >= this->m_faceToGeneratorsMap.m_size )
        goto LABEL_21;
    }
    v7 = 0i64;
    while ( 1 )
    {
      GeneratorData = hkaiOverlapManagerSection::getGeneratorData(this, v6->m_data[v7]->m_generator);
      v9 = 0;
      v10 = GeneratorData->m_overlappedFaces.m_size;
      v11 = GeneratorData;
      v12 = 0i64;
      if ( (int)v10 <= 0 )
        return 0;
      v13 = v11->m_overlappedFaces.m_data;
      for ( j = v13; *j != v3; ++j )
      {
        ++v12;
        ++v9;
        if ( v12 >= v10 )
          return 0;
      }
      if ( v12 < 0 )
        return 0;
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
          return 0;
      }
LABEL_19:
      ++v5;
      ++v7;
      if ( v5 >= v6->m_size )
        goto LABEL_20;
    }
  }
}

// File Line: 1314
// RVA: 0xBF7AF0
void __fastcall hkaiOverlapManager::rebuildMaps(hkaiOverlapManager *this, bool updateContexts)
{
  int i; // ebx

  for ( i = 0; i < this->m_sections.m_size; ++i )
    hkaiOverlapManagerSection::rebuildMap(&this->m_sections.m_data[i], updateContexts);
}

// File Line: 1323
// RVA: 0xBF5210
void __fastcall hkaiOverlapManagerSection::rebuildMap(hkaiOverlapManagerSection *this, bool updateContexts)
{
  __int64 m_numOriginalFaces; // rsi
  char v3; // bl
  int v4; // eax
  int v6; // eax
  int v7; // r9d
  int v8; // eax
  __int64 v9; // rdi
  int *v10; // rbx
  int v11; // r8d
  __int64 m_size; // r8
  int v13; // ecx
  __int64 v14; // rax
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v15; // r8
  _QWORD **Value; // rax
  hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> *v17; // rax
  int v18; // r15d
  __int64 v19; // r13
  hkaiOverlapManagerSection::GeneratorData *m_pntr; // rdi
  hkaiSilhouetteGenerator *m_generator; // rcx
  int v22; // eax
  int v23; // ebp
  __int64 v24; // rsi
  hkArray<hkaiSilhouetteGeneratorSectionContext const *,hkContainerHeapAllocator> *v25; // rbx
  hkResult result; // [rsp+70h] [rbp+8h] BYREF
  bool v27; // [rsp+78h] [rbp+10h]

  v27 = updateContexts;
  m_numOriginalFaces = this->m_numOriginalFaces;
  v3 = updateContexts;
  v4 = this->m_faceToGeneratorsMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < (int)m_numOriginalFaces )
  {
    v6 = 2 * v4;
    v7 = this->m_numOriginalFaces;
    if ( (int)m_numOriginalFaces < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_faceToGeneratorsMap, v7, 16);
  }
  v8 = this->m_faceToGeneratorsMap.m_size - m_numOriginalFaces - 1;
  v9 = v8;
  if ( v8 >= 0 )
  {
    v10 = &this->m_faceToGeneratorsMap.m_data[m_numOriginalFaces].m_capacityAndFlags + 4 * v8;
    do
    {
      v11 = *v10;
      *(v10 - 1) = 0;
      if ( v11 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v10 - 3),
          8 * v11);
      *(_QWORD *)(v10 - 3) = 0i64;
      *v10 = 0x80000000;
      v10 -= 4;
      --v9;
    }
    while ( v9 >= 0 );
    v3 = v27;
  }
  m_size = this->m_faceToGeneratorsMap.m_size;
  v13 = m_numOriginalFaces - m_size;
  v14 = (int)m_numOriginalFaces - (int)m_size;
  v15 = &this->m_faceToGeneratorsMap.m_data[m_size];
  if ( v13 > 0 )
  {
    do
    {
      if ( v15 )
      {
        v15->m_data = 0i64;
        v15->m_size = 0;
        v15->m_capacityAndFlags = 0x80000000;
      }
      ++v15;
      --v14;
    }
    while ( v14 );
  }
  this->m_faceToGeneratorsMap.m_size = m_numOriginalFaces;
  if ( (_DWORD)m_numOriginalFaces )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkPointerMap<hkaiSilhouetteGenerator const *,int,hkContainerHeapAllocator> *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                                                          Value[11],
                                                                                          16i64);
    if ( v17 )
    {
      v17->m_map.m_elem = 0i64;
      v17->m_map.m_numElems = 0;
      v17->m_map.m_hashMod = -1;
    }
    else
    {
      v17 = 0i64;
    }
    this->m_generatorDataMap = v17;
    v18 = 0;
    if ( this->m_generatorData.m_size > 0 )
    {
      v19 = 0i64;
      do
      {
        m_pntr = this->m_generatorData.m_data[v19].m_pntr;
        if ( v3 )
        {
          m_generator = m_pntr->m_context.m_generator;
          if ( m_generator )
            v22 = ((__int64 (__fastcall *)(hkaiSilhouetteGenerator *))m_generator->vfptr[6].__vecDelDtor)(m_generator);
          else
            v22 = 0;
          m_pntr->m_context.m_generatorSize = v22;
        }
        v23 = 0;
        if ( m_pntr->m_overlappedFaces.m_size > 0 )
        {
          v24 = 0i64;
          do
          {
            v25 = &this->m_faceToGeneratorsMap.m_data[m_pntr->m_overlappedFaces.m_data[v24]];
            if ( v25->m_size == (v25->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                &hkContainerHeapAllocator::s_alloc,
                &this->m_faceToGeneratorsMap.m_data[m_pntr->m_overlappedFaces.m_data[v24]],
                8);
            ++v23;
            v25->m_data[v25->m_size++] = &m_pntr->m_context;
            ++v24;
          }
          while ( v23 < m_pntr->m_overlappedFaces.m_size );
          v3 = v27;
        }
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &this->m_generatorDataMap->m_map,
          &hkContainerHeapAllocator::s_alloc,
          (unsigned __int64)m_pntr->m_context.m_generator,
          v18++);
        ++v19;
      }
      while ( v18 < this->m_generatorData.m_size );
    }
  }
}

// File Line: 1359
// RVA: 0xBF42F0
void __fastcall hkaiOverlapManagerSection::~hkaiOverlapManagerSection(hkaiOverlapManagerSection *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // eax
  __int64 v4; // rsi
  int *v5; // rbx
  int v6; // r8d
  int v7; // r8d
  hkRefPtr<hkaiOverlapManagerSection::GeneratorData> *m_data; // rsi
  int v9; // eax
  __int64 i; // rbx
  hkReferencedObject *m_pntr; // rcx
  int v12; // r8d

  hkaiOverlapManagerSection::clearGeneratorData(this);
  m_capacityAndFlags = this->m_facePriorities.m_elem.m_capacityAndFlags;
  this->m_facePriorities.m_elem.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_facePriorities.m_elem.m_data,
      8 * m_capacityAndFlags);
  this->m_facePriorities.m_elem.m_data = 0i64;
  this->m_facePriorities.m_elem.m_capacityAndFlags = 0x80000000;
  v3 = this->m_faceToGeneratorsMap.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = &this->m_faceToGeneratorsMap.m_data->m_capacityAndFlags + 4 * v3;
    do
    {
      v6 = *v5;
      *(v5 - 1) = 0;
      if ( v6 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)(v5 - 3), 8 * v6);
      *(_QWORD *)(v5 - 3) = 0i64;
      *v5 = 0x80000000;
      v5 -= 4;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v7 = this->m_faceToGeneratorsMap.m_capacityAndFlags;
  this->m_faceToGeneratorsMap.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_faceToGeneratorsMap.m_data,
      16 * v7);
  this->m_faceToGeneratorsMap.m_data = 0i64;
  this->m_faceToGeneratorsMap.m_capacityAndFlags = 0x80000000;
  m_data = this->m_generatorData.m_data;
  v9 = this->m_generatorData.m_size - 1;
  for ( i = v9; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  v12 = this->m_generatorData.m_capacityAndFlags;
  this->m_generatorData.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_generatorData.m_data,
      8 * v12);
  this->m_generatorData.m_data = 0i64;
  this->m_generatorData.m_capacityAndFlags = 0x80000000;
}

// File Line: 1364
// RVA: 0xBF4780
void __fastcall hkaiOverlapManagerSection::optimizeCapacity(hkaiOverlapManagerSection *this)
{
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
  int v14; // r8d

  v2 = ((((unsigned int)(this->m_generatorData.m_size - 1) >> 16) | (this->m_generatorData.m_size - 1)) >> 8) | ((unsigned int)(this->m_generatorData.m_size - 1) >> 16) | (this->m_generatorData.m_size - 1);
  v3 = (((v2 >> 4) | v2) >> 2) | (v2 >> 4) | v2;
  v4 = this->m_generatorData.m_capacityAndFlags & 0x3FFFFFFF;
  requestedCapacity = (v3 | (v3 >> 1)) + 1;
  if ( requestedCapacity < v4 )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, &this->m_generatorData, 8, 0i64, requestedCapacity);
  v6 = 0;
  v7 = 0;
  if ( this->m_generatorData.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      hkaiOverlapManagerSection::GeneratorData::optimizeCapacity(this->m_generatorData.m_data[v8].m_pntr);
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_generatorData.m_size );
  }
  v9 = ((((((((unsigned int)(this->m_faceToGeneratorsMap.m_size - 1) >> 16) | (this->m_faceToGeneratorsMap.m_size - 1)) >> 8) | ((unsigned int)(this->m_faceToGeneratorsMap.m_size - 1) >> 16) | (this->m_faceToGeneratorsMap.m_size - 1)) >> 4) | ((((unsigned int)(this->m_faceToGeneratorsMap.m_size - 1) >> 16) | (this->m_faceToGeneratorsMap.m_size - 1)) >> 8) | ((unsigned int)(this->m_faceToGeneratorsMap.m_size - 1) >> 16) | (this->m_faceToGeneratorsMap.m_size - 1)) >> 2) | ((((((unsigned int)(this->m_faceToGeneratorsMap.m_size - 1) >> 16) | (this->m_faceToGeneratorsMap.m_size - 1)) >> 8) | ((unsigned int)(this->m_faceToGeneratorsMap.m_size - 1) >> 16) | (this->m_faceToGeneratorsMap.m_size - 1)) >> 4) | ((((unsigned int)(this->m_faceToGeneratorsMap.m_size - 1) >> 16) | (this->m_faceToGeneratorsMap.m_size - 1)) >> 8) | ((unsigned int)(this->m_faceToGeneratorsMap.m_size - 1) >> 16) | (this->m_faceToGeneratorsMap.m_size - 1);
  v10 = (v9 | (v9 >> 1)) + 1;
  if ( v10 < (this->m_faceToGeneratorsMap.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, &this->m_faceToGeneratorsMap, 16, 0i64, v10);
  if ( this->m_faceToGeneratorsMap.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = &this->m_faceToGeneratorsMap.m_data[v11];
      v13 = ((((((((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 8) | ((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 4) | ((((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 8) | ((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 2) | ((((((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 8) | ((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 4) | ((((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1)) >> 8) | ((unsigned int)(v12->m_size - 1) >> 16) | (v12->m_size - 1);
      v14 = (v13 | (v13 >> 1)) + 1;
      if ( v14 < (v12->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, v12, 8, 0i64, v14);
      ++v6;
      ++v11;
    }
    while ( v6 < this->m_faceToGeneratorsMap.m_size );
  }
  hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::optimizeCapacity(
    &this->m_facePriorities,
    0);
}

// File Line: 1386
// RVA: 0xBF6060
void __fastcall hkaiOverlapManager::optimizeCapacity(hkaiOverlapManager *this)
{
  unsigned int v2; // edx
  int v3; // eax
  int requestedCapacity; // ecx
  int i; // ebx

  v2 = ((((((((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 8) | ((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 4) | ((((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 8) | ((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 2) | ((((((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 8) | ((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 4) | ((((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1)) >> 8) | ((unsigned int)(this->m_sections.m_size - 1) >> 16) | (this->m_sections.m_size - 1);
  v3 = this->m_sections.m_capacityAndFlags & 0x3FFFFFFF;
  requestedCapacity = (v2 | (v2 >> 1)) + 1;
  if ( requestedCapacity < v3 )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, &this->m_sections, 72, 0i64, requestedCapacity);
  for ( i = 0; i < this->m_sections.m_size; ++i )
    hkaiOverlapManagerSection::optimizeCapacity(&this->m_sections.m_data[i]);
}

// File Line: 1395
// RVA: 0xBF6020
void __fastcall hkaiOverlapManager::setSilhouettePriorityController(
        hkaiOverlapManager *this,
        hkaiSilhouettePriorityController *controller)
{
  hkaiSilhouettePriorityController *m_pntr; // rcx

  if ( controller )
    hkReferencedObject::addReference(controller);
  m_pntr = this->m_priorityController.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_priorityController.m_pntr = controller;
}

// File Line: 1400
// RVA: 0xBF4450
void __fastcall hkaiOverlapManagerSection::GeneratorData::optimizeCapacity(
        hkaiOverlapManagerSection::GeneratorData *this)
{
  hkArray<int,hkContainerHeapAllocator> *p_m_overlappedFaces; // rdx
  unsigned int v2; // ecx
  unsigned int v3; // ecx
  signed int requestedCapacity; // r8d

  p_m_overlappedFaces = &this->m_overlappedFaces;
  v2 = ((unsigned int)(this->m_overlappedFaces.m_size - 1) >> 16) | (this->m_overlappedFaces.m_size - 1);
  v3 = (((v2 >> 8) | v2) >> 4) | (v2 >> 8) | v2;
  requestedCapacity = ((v3 >> 2) | v3 | (((v3 >> 2) | v3) >> 1)) + 1;
  if ( requestedCapacity < (p_m_overlappedFaces->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, p_m_overlappedFaces, 4, 0i64, requestedCapacity);
}

// File Line: 1405
// RVA: 0xBF4C00
void __fastcall hkaiOverlapManagerSection::dirtyAllFaces(hkaiOverlapManagerSection *this)
{
  int v2; // ebx
  int v3; // esi
  int m_size; // r8d
  int v5; // r8d
  hkIntRealPair *m_data; // r9
  int v7; // ecx
  int m_key; // edx
  int v9; // edx
  hkIntRealPair *v10; // rcx
  hkIntRealPair *v11; // r9
  int v12; // r8d
  int v13; // r10d
  int v14; // ecx
  int v15; // edx
  __int64 v16; // rax
  hkResult result; // [rsp+40h] [rbp+8h] BYREF
  __int64 v18; // [rsp+48h] [rbp+10h]
  hkIntRealPair v19; // [rsp+50h] [rbp+18h]

  hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::reserve(
    &this->m_facePriorities,
    this->m_numOriginalFaces);
  v2 = 0;
  if ( this->m_numOriginalFaces > 0 )
  {
    v3 = 0;
    do
    {
      m_size = this->m_facePriorities.m_elem.m_size;
      v18 = (unsigned int)v2;
      v5 = m_size - 1;
      if ( v5 <= 0
        || (m_data = this->m_facePriorities.m_elem.m_data, v7 = v5 & v3, m_key = m_data[v5 & v3].m_key, m_key == -1) )
      {
LABEL_7:
        v9 = v5 + 1;
      }
      else
      {
        while ( m_key != v2 )
        {
          v7 = v5 & (v7 + 1);
          m_key = m_data[v7].m_key;
          if ( m_key == -1 )
            goto LABEL_7;
        }
        v9 = v7;
      }
      if ( v9 > this->m_facePriorities.m_elem.m_size - 1 )
      {
        if ( 2 * this->m_facePriorities.m_numElems > v5 )
          hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::resizeTable(
            &this->m_facePriorities,
            &result,
            2 * v5 + 2);
        v11 = this->m_facePriorities.m_elem.m_data;
        v12 = this->m_facePriorities.m_elem.m_size - 1;
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
        this->m_facePriorities.m_numElems += v13;
        v11[v14] = (hkIntRealPair)v16;
      }
      else
      {
        v10 = this->m_facePriorities.m_elem.m_data;
        v19 = v10[v9];
        HIDWORD(v18) = LODWORD(v19.m_value);
        v10[v9] = (hkIntRealPair)v18;
      }
      ++v2;
      v3 -= 1640531535;
    }
    while ( v2 < this->m_numOriginalFaces );
  }
}

