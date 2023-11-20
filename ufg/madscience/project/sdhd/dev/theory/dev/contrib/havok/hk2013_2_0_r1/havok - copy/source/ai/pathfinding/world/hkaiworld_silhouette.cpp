// File Line: 22
// RVA: 0xBCF0D0
void __fastcall hkaiWorld::setupReferenceFrame(hkaiWorld *this, hkaiReferenceFrameAndExtrusion *referenceFrameAndExtrusion)
{
  referenceFrameAndExtrusion->m_up = this->m_up;
  referenceFrameAndExtrusion->m_cellExtrusion = this->m_silhouetteExtrusion;
  referenceFrameAndExtrusion->m_silhouetteRadiusExpasion = this->m_erosionRadius;
}

// File Line: 29
// RVA: 0xBCE830
void __fastcall hkaiWorld::addSilhouetteGenerator(hkaiWorld *this, hkaiSilhouetteGenerator *generator)
{
  hkaiSilhouetteGenerator *v2; // rbx
  hkaiWorld *v3; // rsi
  hkRefPtr<hkaiSilhouetteGenerator> *v4; // r14
  hkaiOverlapManager *v5; // rcx

  v2 = generator;
  v3 = this;
  if ( generator )
    hkReferencedObject::addReference((hkReferencedObject *)&generator->vfptr);
  if ( v3->m_silhouetteGenerators.m_size == (v3->m_silhouetteGenerators.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_silhouetteGenerators,
      8);
  v4 = &v3->m_silhouetteGenerators.m_data[v3->m_silhouetteGenerators.m_size];
  if ( v4 )
  {
    if ( v2 )
      hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
    v4->m_pntr = v2;
  }
  ++v3->m_silhouetteGenerators.m_size;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v5 = v3->m_overlapManager.m_pntr;
  if ( v5 )
    hkaiOverlapManager::addSilhouetteGenerator(v5, v2);
}

// File Line: 39
// RVA: 0xBCE8E0
void __fastcall hkaiWorld::removeSilhouetteGenerator(hkaiWorld *this, hkaiSilhouetteGenerator *generator)
{
  hkaiSilhouetteGenerator *v2; // rbx
  hkaiWorld *v3; // rsi
  __int64 v4; // rcx
  signed int v5; // edi
  __int64 v6; // rdx
  hkRefPtr<hkaiSilhouetteGenerator> *v7; // rax
  hkaiOverlapManager *v8; // rcx
  hkRefPtr<hkaiSilhouetteGenerator> *v9; // rbx
  hkReferencedObject *v10; // rcx
  signed __int64 v11; // r14
  __int64 v12; // rax

  v2 = generator;
  v3 = this;
  if ( generator )
    hkReferencedObject::addReference((hkReferencedObject *)&generator->vfptr);
  v4 = v3->m_silhouetteGenerators.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( v4 <= 0 )
  {
LABEL_7:
    v5 = -1;
  }
  else
  {
    v7 = v3->m_silhouetteGenerators.m_data;
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
    v8 = v3->m_overlapManager.m_pntr;
    if ( v8 )
      hkaiOverlapManager::removeSilhouetteGenerator(v8, v2);
    v9 = v3->m_silhouetteGenerators.m_data;
    v10 = (hkReferencedObject *)&v9[v5].m_pntr->vfptr;
    v11 = v5;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
    v9[v11].m_pntr = 0i64;
    v12 = --v3->m_silhouetteGenerators.m_size;
    if ( (_DWORD)v12 != v5 )
      v3->m_silhouetteGenerators.m_data[v11].m_pntr = v3->m_silhouetteGenerators.m_data[v12].m_pntr;
  }
}

// File Line: 53
// RVA: 0xBCE9C0
void __fastcall hkaiWorld::setSilhouetteExtrusion(hkaiWorld *this, float e)
{
  bool v2; // zf
  hkaiWorld *v3; // rbx
  hkaiReferenceFrameAndExtrusion referenceFrameAndExtrusion; // [rsp+20h] [rbp-28h]

  v2 = this->m_overlapManager.m_pntr == 0i64;
  this->m_silhouetteExtrusion = e;
  v3 = this;
  if ( !v2 )
  {
    referenceFrameAndExtrusion.m_cellExtrusion = -1.0;
    referenceFrameAndExtrusion.m_silhouetteRadiusExpasion = -1.0;
    referenceFrameAndExtrusion.m_up = 0i64;
    hkaiWorld::setupReferenceFrame(this, &referenceFrameAndExtrusion);
    hkaiOverlapManager::setReferenceFrameAndExtrusion(v3->m_overlapManager.m_pntr, &referenceFrameAndExtrusion);
    hkaiWorld::invalidateAllSilhouettes(v3);
  }
}

// File Line: 67
// RVA: 0xBCEE40
void __fastcall hkaiWorld::stepSilhouettes(hkaiWorld *this, hkBitField *sectionsToStep)
{
  hkaiWorld::stepSilhouettesMT(this, sectionsToStep, 0i64, 0i64);
}

// File Line: 73
// RVA: 0xBCEE60
void __fastcall hkaiWorld::stepSilhouettesMT(hkaiWorld *this, hkBitField *sectionsToStep, hkJobQueue *jobQueue, hkJobThreadPool *threadPool)
{
  hkJobThreadPool *v4; // r12
  hkJobQueue *v5; // r15
  hkBitField *v6; // rbp
  hkaiWorld *v7; // rbx
  int v8; // edi
  BOOL v9; // er14
  __int64 v10; // rsi
  hkaiOverlapManager *v11; // rdx
  hkaiNavMeshSilhouetteSelector *v12; // rdx
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  int v17; // esi
  __int64 v18; // rdi
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx
  hkArray<unsigned int,hkContainerTempAllocator> uncutFaceKeys; // [rsp+40h] [rbp-68h]
  hkArray<unsigned int,hkContainerTempAllocator> cutFaceKeys; // [rsp+50h] [rbp-58h]
  hkaiWorld::NavMeshModifiedCallbackContext v25; // [rsp+60h] [rbp-48h]

  v4 = threadPool;
  v5 = jobQueue;
  v6 = sectionsToStep;
  v7 = this;
  if ( this->m_overlapManager.m_pntr )
  {
    v8 = 0;
    if ( this->m_listeners.m_size > 0 )
    {
      v9 = jobQueue != 0i64;
      v10 = 0i64;
      do
      {
        v7->m_listeners.m_data[v10]->vfptr->preSilhouetteStepCallback(
          v7->m_listeners.m_data[v10],
          v7,
          (hkaiWorld::StepThreading)v9,
          v6);
        ++v8;
        ++v10;
      }
      while ( v8 < v7->m_listeners.m_size );
    }
    hkaiOverlapManager::updateOverlapsOfAllGenerators(
      v7->m_overlapManager.m_pntr,
      &v7->m_silhouetteGenerators,
      v6,
      v7->m_forceSilhouetteUpdates.m_bool != 0);
    v11 = v7->m_overlapManager.m_pntr;
    cutFaceKeys.m_data = 0i64;
    cutFaceKeys.m_size = 0;
    cutFaceKeys.m_capacityAndFlags = 2147483648;
    uncutFaceKeys.m_data = 0i64;
    uncutFaceKeys.m_size = 0;
    uncutFaceKeys.m_capacityAndFlags = 2147483648;
    if ( v11 )
      v12 = (hkaiNavMeshSilhouetteSelector *)&v11->vfptr;
    else
      v12 = 0i64;
    if ( hkaiNavMeshCutter::cutSilhouettesIncremental(
           v7->m_cutter.m_pntr,
           v12,
           &v7->m_silhouetteGenerationParameters,
           &cutFaceKeys,
           &uncutFaceKeys,
           v6,
           v5,
           v4) )
    {
      v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v14 = (_QWORD *)v13[1];
      if ( (unsigned __int64)v14 < v13[3] )
      {
        *v14 = "TtdynamicNavMeshModifiedCallback";
        v15 = __rdtsc();
        v16 = (signed __int64)(v14 + 2);
        *(_DWORD *)(v16 - 8) = v15;
        v13[1] = v16;
      }
      hkaiWorld::NavMeshModifiedCallbackContext::NavMeshModifiedCallbackContext(
        &v25,
        v7,
        (hkArrayBase<unsigned int> *)&cutFaceKeys.m_data,
        (hkArrayBase<unsigned int> *)&uncutFaceKeys.m_data);
      v17 = 0;
      if ( v7->m_listeners.m_size > 0 )
      {
        v18 = 0i64;
        do
        {
          v7->m_listeners.m_data[v18]->vfptr->dynamicNavMeshModifiedCallback(v7->m_listeners.m_data[v18], &v25);
          ++v17;
          ++v18;
        }
        while ( v17 < v7->m_listeners.m_size );
      }
      v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v20 = (_QWORD *)v19[1];
      if ( (unsigned __int64)v20 < v19[3] )
      {
        *v20 = "Et";
        v21 = __rdtsc();
        v22 = (signed __int64)(v20 + 2);
        *(_DWORD *)(v22 - 8) = v21;
        v19[1] = v22;
      }
    }
    hkaiOverlapManager::markFrameDone(v7->m_overlapManager.m_pntr);
    uncutFaceKeys.m_size = 0;
    if ( uncutFaceKeys.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        uncutFaceKeys.m_data,
        4 * uncutFaceKeys.m_capacityAndFlags);
    uncutFaceKeys.m_data = 0i64;
    cutFaceKeys.m_size = 0;
    uncutFaceKeys.m_capacityAndFlags = 2147483648;
    if ( cutFaceKeys.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        cutFaceKeys.m_data,
        4 * cutFaceKeys.m_capacityAndFlags);
  }
}locator *)&hkContainerTempAllocator:

// File Line: 118
// RVA: 0xBCEA20
void __fastcall hkaiWorld::invalidateAllSilhouettes(hkaiWorld *this)
{
  hkaiWorld *v1; // rsi
  int v2; // ebx
  __int64 v3; // rdi
  hkErrStream v4; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v1 = this;
  if ( this->m_overlapManager.m_pntr )
  {
    hkErrStream::hkErrStream(&v4, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v4.vfptr,
      "Changing silhouette generation settings is very slow and should not be done at runtime.");
    hkError::messageWarning(1862547905, &buf, "World\\hkaiWorld_silhouette.cpp", 122);
    hkOstream::~hkOstream((hkOstream *)&v4.vfptr);
    hkaiOverlapManager::updateReferenceFrameAndExtrusion(v1->m_overlapManager.m_pntr);
  }
  v2 = 0;
  if ( v1->m_silhouetteGenerators.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      ((void (*)(void))v1->m_silhouetteGenerators.m_data[v3].m_pntr->vfptr[2].__vecDelDtor)();
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_silhouetteGenerators.m_size );
  }
}

// File Line: 133
// RVA: 0xBCEAE0
void __fastcall hkaiWorld::forceSilhouetteInformation(hkaiWorld *this, hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *silhouettes, hkArray<hkaiOverlapManagerSection,hkContainerHeapAllocator> *managerSections)
{
  hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *v3; // r15
  hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *v4; // r13
  hkRefPtr<hkaiSilhouetteGenerator> *v5; // rdi
  int v6; // eax
  __int64 i; // rbx
  hkReferencedObject *v8; // rcx
  __int64 v9; // rbp
  int v10; // er12
  int v11; // eax
  int v12; // eax
  int v13; // er9
  signed __int64 v14; // rdi
  __int64 j; // rbx
  hkReferencedObject *v16; // rcx
  hkReferencedObject **v17; // rbx
  signed __int64 v18; // rsi
  __int64 v19; // rdi
  hkReferencedObject *v20; // rcx
  hkReferencedObject *v21; // rax
  hkReferencedObject **v22; // rbx
  __int64 v23; // rsi
  signed __int64 v24; // r14
  __int64 v25; // r14
  hkResultEnum v26; // eax
  hkaiWorld *v27; // rsi
  signed __int64 v28; // rbx
  signed __int64 v29; // r14
  __int64 v30; // r12
  _DWORD *v31; // r13
  signed int v32; // ebx
  int v33; // er15
  int v34; // eax
  int v35; // eax
  int v36; // er9
  signed __int64 v37; // rdi
  __int64 v38; // rbx
  hkReferencedObject *v39; // rcx
  hkReferencedObject **v40; // rbx
  __int64 v41; // rsi
  __int64 v42; // rdi
  hkReferencedObject *v43; // rcx
  hkReferencedObject *v44; // rax
  hkReferencedObject **v45; // rbx
  __int64 v46; // rsi
  signed __int64 v47; // r14
  __int64 v48; // [rsp+30h] [rbp-58h]
  signed __int64 v49; // [rsp+38h] [rbp-50h]
  hkaiWorld *v50; // [rsp+90h] [rbp+8h]
  hkResult result; // [rsp+98h] [rbp+10h]
  hkArray<hkaiOverlapManagerSection,hkContainerHeapAllocator> *v52; // [rsp+A0h] [rbp+18h]
  hkResult v53; // [rsp+A8h] [rbp+20h]

  v52 = managerSections;
  v50 = this;
  v3 = &this->m_silhouetteGenerators;
  v4 = silhouettes;
  v5 = this->m_silhouetteGenerators.m_data;
  v6 = this->m_silhouetteGenerators.m_size - 1;
  for ( i = v6; i >= 0; v5[i--].m_pntr = 0i64 )
  {
    v8 = (hkReferencedObject *)&v5[i].m_pntr->vfptr;
    if ( v8 )
      hkReferencedObject::removeReference(v8);
  }
  v3->m_size = 0;
  v9 = v4->m_size;
  v10 = v4->m_size;
  if ( (signed int)v9 > 0 )
    v10 = 0;
  v11 = v3->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < (signed int)v9 )
  {
    v12 = 2 * v11;
    v13 = v9;
    if ( (signed int)v9 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v13, 8);
  }
  v14 = (signed __int64)&v3->m_data[v9];
  for ( j = -1 - (signed int)v9; j >= 0; *(_QWORD *)(v14 + 8 * j--) = 0i64 )
  {
    v16 = *(hkReferencedObject **)(v14 + 8 * j);
    if ( v16 )
      hkReferencedObject::removeReference(v16);
  }
  v17 = (hkReferencedObject **)v3->m_data;
  if ( v10 > 0 )
  {
    v18 = (char *)v4->m_data - (char *)v17;
    v19 = v10;
    do
    {
      v20 = *(hkReferencedObject **)((char *)v17 + v18);
      if ( v20 )
        hkReferencedObject::addReference(v20);
      if ( *v17 )
        hkReferencedObject::removeReference(*v17);
      v21 = *(hkReferencedObject **)((char *)v17 + v18);
      ++v17;
      *(v17 - 1) = v21;
      --v19;
    }
    while ( v19 );
  }
  v22 = (hkReferencedObject **)&v4->m_data[v10];
  v23 = (signed int)v9 - v10;
  if ( (signed int)v9 - v10 > 0 )
  {
    v24 = (char *)&v3->m_data[v10] - (char *)v22;
    do
    {
      if ( (hkReferencedObject **)((char *)v22 + v24) )
      {
        if ( *v22 )
          hkReferencedObject::addReference(*v22);
        *(hkReferencedObject **)((char *)v22 + v24) = *v22;
      }
      ++v22;
      --v23;
    }
    while ( v23 );
  }
  v25 = (__int64)v52;
  v3->m_size = v9;
  v26 = 0;
  result.m_enum = 0;
  if ( *(_DWORD *)(v25 + 8) > 0 )
  {
    v27 = v50;
    v28 = 0i64;
    v48 = 0i64;
    do
    {
      v49 = v26;
      hkaiOverlapManagerSection::clearGeneratorData(&v27->m_overlapManager.m_pntr->m_sections.m_data[v26]);
      v29 = v28 + *(_QWORD *)v25;
      v30 = *(signed int *)(v29 + 24);
      v31 = (_DWORD *)((char *)v27->m_overlapManager.m_pntr->m_sections.m_data + v28);
      v32 = v31[6];
      v33 = v30;
      if ( (signed int)v30 > v32 )
        v33 = v31[6];
      v34 = v31[7] & 0x3FFFFFFF;
      if ( v34 >= (signed int)v30 )
      {
        v53.m_enum = 0;
      }
      else
      {
        v35 = 2 * v34;
        v36 = v30;
        if ( (signed int)v30 < v35 )
          v36 = v35;
        hkArrayUtil::_reserve(&v53, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v31 + 4, v36, 8);
      }
      v37 = *((_QWORD *)v31 + 2) + 8 * v30;
      v38 = v32 - (signed int)v30 - 1;
      if ( (signed int)v38 >= 0 )
      {
        do
        {
          v39 = *(hkReferencedObject **)(v37 + 8 * v38);
          if ( v39 )
            hkReferencedObject::removeReference(v39);
          *(_QWORD *)(v37 + 8 * v38--) = 0i64;
        }
        while ( v38 >= 0 );
      }
      v40 = (hkReferencedObject **)*((_QWORD *)v31 + 2);
      if ( v33 > 0 )
      {
        v41 = *(_QWORD *)(v29 + 16) - (_QWORD)v40;
        v42 = v33;
        do
        {
          v43 = *(hkReferencedObject **)((char *)v40 + v41);
          if ( v43 )
            hkReferencedObject::addReference(v43);
          if ( *v40 )
            hkReferencedObject::removeReference(*v40);
          v44 = *(hkReferencedObject **)((char *)v40 + v41);
          ++v40;
          *(v40 - 1) = v44;
          --v42;
        }
        while ( v42 );
      }
      v45 = (hkReferencedObject **)(*(_QWORD *)(v29 + 16) + 8i64 * v33);
      v46 = (signed int)v30 - v33;
      if ( (signed int)v30 - v33 > 0 )
      {
        v47 = *((_QWORD *)v31 + 2) + 8i64 * v33 - (_QWORD)v45;
        do
        {
          if ( (hkReferencedObject **)((char *)v45 + v47) )
          {
            if ( *v45 )
              hkReferencedObject::addReference(*v45);
            *(hkReferencedObject **)((char *)v45 + v47) = *v45;
          }
          ++v45;
          --v46;
        }
        while ( v46 );
      }
      v27 = v50;
      v25 = (__int64)v52;
      v31[6] = v30;
      v50->m_overlapManager.m_pntr->m_sections.m_data[v48].m_numOriginalFaces = *(_DWORD *)(*(_QWORD *)v25 + v48 * 72 + 8);
      hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::operator=(
        (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)&v50->m_overlapManager.m_pntr->m_sections.m_data[v49].m_facePriorities.m_elem,
        (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)(v49 * 72
                                                                                        + *(_QWORD *)v25
                                                                                        + 48i64));
      hkaiOverlapManagerSection::rebuildMap(&v50->m_overlapManager.m_pntr->m_sections.m_data[v49], 1);
      v28 = v48 * 72 + 72;
      v26 = result.m_enum + 1;
      ++v48;
      result.m_enum = v26;
    }
    while ( v26 < *(_DWORD *)(v25 + 8) );
  }
}

// File Line: 155
// RVA: 0xBCE810
void __fastcall hkaiWorld::NavMeshModifiedCallbackContext::NavMeshModifiedCallbackContext(hkaiWorld::NavMeshModifiedCallbackContext *this, hkaiWorld *world, hkArrayBase<unsigned int> *cutFaceKeys, hkArrayBase<unsigned int> *uncutFaceKeys)
{
  this->m_world = world;
  this->m_cutFaceKeys = cutFaceKeys;
  this->m_uncutFaceKeys = uncutFaceKeys;
}

