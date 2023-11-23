// File Line: 22
// RVA: 0xBCF0D0
void __fastcall hkaiWorld::setupReferenceFrame(
        hkaiWorld *this,
        hkaiReferenceFrameAndExtrusion *referenceFrameAndExtrusion)
{
  referenceFrameAndExtrusion->m_up = this->m_up;
  referenceFrameAndExtrusion->m_cellExtrusion = this->m_silhouetteExtrusion;
  referenceFrameAndExtrusion->m_silhouetteRadiusExpasion = this->m_erosionRadius;
}

// File Line: 29
// RVA: 0xBCE830
void __fastcall hkaiWorld::addSilhouetteGenerator(hkaiWorld *this, hkaiSilhouetteGenerator *generator)
{
  hkRefPtr<hkaiSilhouetteGenerator> *v4; // r14
  hkaiOverlapManager *m_pntr; // rcx

  if ( generator )
    hkReferencedObject::addReference(generator);
  if ( this->m_silhouetteGenerators.m_size == (this->m_silhouetteGenerators.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_silhouetteGenerators, 8);
  v4 = &this->m_silhouetteGenerators.m_data[this->m_silhouetteGenerators.m_size];
  if ( v4 )
  {
    if ( generator )
      hkReferencedObject::addReference(generator);
    v4->m_pntr = generator;
  }
  ++this->m_silhouetteGenerators.m_size;
  if ( generator )
    hkReferencedObject::removeReference(generator);
  m_pntr = this->m_overlapManager.m_pntr;
  if ( m_pntr )
    hkaiOverlapManager::addSilhouetteGenerator(m_pntr, generator);
}

// File Line: 39
// RVA: 0xBCE8E0
void __fastcall hkaiWorld::removeSilhouetteGenerator(hkaiWorld *this, hkaiSilhouetteGenerator *generator)
{
  __int64 m_size; // rcx
  int v5; // edi
  __int64 v6; // rdx
  hkRefPtr<hkaiSilhouetteGenerator> *m_data; // rax
  hkaiOverlapManager *m_pntr; // rcx
  hkRefPtr<hkaiSilhouetteGenerator> *v9; // rbx
  hkReferencedObject *v10; // rcx
  __int64 v11; // rax

  if ( generator )
    hkReferencedObject::addReference(generator);
  m_size = this->m_silhouetteGenerators.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_7:
    v5 = -1;
  }
  else
  {
    m_data = this->m_silhouetteGenerators.m_data;
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
    m_pntr = this->m_overlapManager.m_pntr;
    if ( m_pntr )
      hkaiOverlapManager::removeSilhouetteGenerator(m_pntr, generator);
    v9 = this->m_silhouetteGenerators.m_data;
    v10 = v9[v5].m_pntr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
    v9[v5].m_pntr = 0i64;
    v11 = --this->m_silhouetteGenerators.m_size;
    if ( (_DWORD)v11 != v5 )
      this->m_silhouetteGenerators.m_data[v5].m_pntr = this->m_silhouetteGenerators.m_data[v11].m_pntr;
  }
}

// File Line: 53
// RVA: 0xBCE9C0
void __fastcall hkaiWorld::setSilhouetteExtrusion(hkaiWorld *this, float e)
{
  bool v2; // zf
  hkaiReferenceFrameAndExtrusion referenceFrameAndExtrusion; // [rsp+20h] [rbp-28h] BYREF

  v2 = this->m_overlapManager.m_pntr == 0i64;
  this->m_silhouetteExtrusion = e;
  if ( !v2 )
  {
    referenceFrameAndExtrusion.m_cellExtrusion = -1.0;
    referenceFrameAndExtrusion.m_silhouetteRadiusExpasion = -1.0;
    referenceFrameAndExtrusion.m_up = 0i64;
    hkaiWorld::setupReferenceFrame(this, &referenceFrameAndExtrusion);
    hkaiOverlapManager::setReferenceFrameAndExtrusion(this->m_overlapManager.m_pntr, &referenceFrameAndExtrusion);
    hkaiWorld::invalidateAllSilhouettes(this);
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
void __fastcall hkaiWorld::stepSilhouettesMT(
        hkaiWorld *this,
        hkBitField *sectionsToStep,
        hkJobQueue *jobQueue,
        hkJobThreadPool *threadPool)
{
  int v8; // edi
  BOOL v9; // r14d
  __int64 v10; // rsi
  hkaiOverlapManager *m_pntr; // rdx
  hkaiNavMeshSilhouetteSelector *v12; // rdx
  _QWORD *Value; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  int v17; // esi
  __int64 v18; // rdi
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  _QWORD *v22; // rcx
  hkArray<unsigned int,hkContainerTempAllocator> uncutFaceKeys; // [rsp+40h] [rbp-68h] BYREF
  hkArray<unsigned int,hkContainerTempAllocator> cutFaceKeys; // [rsp+50h] [rbp-58h] BYREF
  hkaiWorld::NavMeshModifiedCallbackContext v25; // [rsp+60h] [rbp-48h] BYREF

  if ( this->m_overlapManager.m_pntr )
  {
    v8 = 0;
    if ( this->m_listeners.m_size > 0 )
    {
      v9 = jobQueue != 0i64;
      v10 = 0i64;
      do
      {
        this->m_listeners.m_data[v10]->vfptr->preSilhouetteStepCallback(
          this->m_listeners.m_data[v10],
          this,
          (hkaiWorld::StepThreading)v9,
          sectionsToStep);
        ++v8;
        ++v10;
      }
      while ( v8 < this->m_listeners.m_size );
    }
    hkaiOverlapManager::updateOverlapsOfAllGenerators(
      this->m_overlapManager.m_pntr,
      &this->m_silhouetteGenerators,
      sectionsToStep,
      this->m_forceSilhouetteUpdates.m_bool != 0);
    m_pntr = this->m_overlapManager.m_pntr;
    cutFaceKeys.m_data = 0i64;
    cutFaceKeys.m_size = 0;
    cutFaceKeys.m_capacityAndFlags = 0x80000000;
    uncutFaceKeys.m_data = 0i64;
    uncutFaceKeys.m_size = 0;
    uncutFaceKeys.m_capacityAndFlags = 0x80000000;
    if ( m_pntr )
      v12 = &m_pntr->hkaiNavMeshSilhouetteSelector;
    else
      v12 = 0i64;
    if ( hkaiNavMeshCutter::cutSilhouettesIncremental(
           this->m_cutter.m_pntr,
           v12,
           &this->m_silhouetteGenerationParameters,
           &cutFaceKeys,
           &uncutFaceKeys,
           sectionsToStep,
           jobQueue,
           threadPool) )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v14 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v14 < Value[3] )
      {
        *v14 = "TtdynamicNavMeshModifiedCallback";
        v15 = __rdtsc();
        v16 = v14 + 2;
        *((_DWORD *)v16 - 2) = v15;
        Value[1] = v16;
      }
      hkaiWorld::NavMeshModifiedCallbackContext::NavMeshModifiedCallbackContext(
        &v25,
        this,
        &cutFaceKeys,
        &uncutFaceKeys);
      v17 = 0;
      if ( this->m_listeners.m_size > 0 )
      {
        v18 = 0i64;
        do
        {
          this->m_listeners.m_data[v18]->vfptr->dynamicNavMeshModifiedCallback(this->m_listeners.m_data[v18], &v25);
          ++v17;
          ++v18;
        }
        while ( v17 < this->m_listeners.m_size );
      }
      v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v20 = (_QWORD *)v19[1];
      if ( (unsigned __int64)v20 < v19[3] )
      {
        *v20 = "Et";
        v21 = __rdtsc();
        v22 = v20 + 2;
        *((_DWORD *)v22 - 2) = v21;
        v19[1] = v22;
      }
    }
    hkaiOverlapManager::markFrameDone(this->m_overlapManager.m_pntr);
    uncutFaceKeys.m_size = 0;
    if ( uncutFaceKeys.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        uncutFaceKeys.m_data,
        4 * uncutFaceKeys.m_capacityAndFlags);
    uncutFaceKeys.m_data = 0i64;
    cutFaceKeys.m_size = 0;
    uncutFaceKeys.m_capacityAndFlags = 0x80000000;
    if ( cutFaceKeys.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        cutFaceKeys.m_data,
        4 * cutFaceKeys.m_capacityAndFlags);
  }
}

// File Line: 118
// RVA: 0xBCEA20
void __fastcall hkaiWorld::invalidateAllSilhouettes(hkaiWorld *this)
{
  int v2; // ebx
  __int64 v3; // rdi
  hkErrStream v4; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  if ( this->m_overlapManager.m_pntr )
  {
    hkErrStream::hkErrStream(&v4, buf, 512);
    hkOstream::operator<<(
      &v4,
      "Changing silhouette generation settings is very slow and should not be done at runtime.");
    hkError::messageWarning(1862547905, buf, "World\\hkaiWorld_silhouette.cpp", 122);
    hkOstream::~hkOstream(&v4);
    hkaiOverlapManager::updateReferenceFrameAndExtrusion(this->m_overlapManager.m_pntr);
  }
  v2 = 0;
  if ( this->m_silhouetteGenerators.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      ((void (__fastcall *)(hkaiSilhouetteGenerator *))this->m_silhouetteGenerators.m_data[v3].m_pntr->vfptr[2].__vecDelDtor)(this->m_silhouetteGenerators.m_data[v3].m_pntr);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_silhouetteGenerators.m_size );
  }
}

// File Line: 133
// RVA: 0xBCEAE0
void __fastcall hkaiWorld::forceSilhouetteInformation(
        hkaiWorld *this,
        hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *silhouettes,
        hkArray<hkaiOverlapManagerSection,hkContainerHeapAllocator> *managerSections)
{
  hkArray<hkRefPtr<hkaiSilhouetteGenerator>,hkContainerHeapAllocator> *p_m_silhouetteGenerators; // r15
  hkRefPtr<hkaiSilhouetteGenerator> *m_data; // rdi
  int v6; // eax
  __int64 i; // rbx
  hkReferencedObject *m_pntr; // rcx
  __int64 m_size; // rbp
  int v10; // r12d
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  __int64 v14; // rdi
  __int64 j; // rbx
  hkReferencedObject *v16; // rcx
  hkReferencedObject **p_m_pntr; // rbx
  char *v18; // rsi
  __int64 v19; // rdi
  hkReferencedObject *v20; // rcx
  hkReferencedObject *v21; // rax
  hkRefPtr<hkaiSilhouetteGenerator> *v22; // rbx
  __int64 v23; // rsi
  signed __int64 v24; // r14
  __int64 v25; // r14
  hkResultEnum v26; // eax
  hkaiWorld *v27; // rsi
  __int64 v28; // rbx
  __int64 v29; // r14
  __int64 v30; // r12
  _DWORD *v31; // r13
  int v32; // ebx
  int v33; // r15d
  int v34; // eax
  int v35; // eax
  int v36; // r9d
  __int64 v37; // rdi
  __int64 v38; // rbx
  hkReferencedObject *v39; // rcx
  hkReferencedObject **v40; // rbx
  __int64 v41; // rsi
  __int64 v42; // rdi
  hkReferencedObject *v43; // rcx
  hkReferencedObject *v44; // rax
  hkReferencedObject **v45; // rbx
  __int64 v46; // rsi
  __int64 v47; // r14
  __int64 v48; // [rsp+30h] [rbp-58h]
  __int64 v49; // [rsp+38h] [rbp-50h]
  hkResult result; // [rsp+98h] [rbp+10h] BYREF
  hkArray<hkaiOverlapManagerSection,hkContainerHeapAllocator> *v52; // [rsp+A0h] [rbp+18h]
  hkResult v53; // [rsp+A8h] [rbp+20h] BYREF

  v52 = managerSections;
  p_m_silhouetteGenerators = &this->m_silhouetteGenerators;
  m_data = this->m_silhouetteGenerators.m_data;
  v6 = this->m_silhouetteGenerators.m_size - 1;
  for ( i = v6; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  p_m_silhouetteGenerators->m_size = 0;
  m_size = silhouettes->m_size;
  v10 = silhouettes->m_size;
  if ( (int)m_size > 0 )
    v10 = 0;
  v11 = p_m_silhouetteGenerators->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < (int)m_size )
  {
    v12 = 2 * v11;
    v13 = silhouettes->m_size;
    if ( (int)m_size < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_silhouetteGenerators, v13, 8);
  }
  v14 = (__int64)&p_m_silhouetteGenerators->m_data[m_size];
  for ( j = -1 - (int)m_size; j >= 0; *(_QWORD *)(v14 + 8 * j--) = 0i64 )
  {
    v16 = *(hkReferencedObject **)(v14 + 8 * j);
    if ( v16 )
      hkReferencedObject::removeReference(v16);
  }
  p_m_pntr = &p_m_silhouetteGenerators->m_data->m_pntr;
  if ( v10 > 0 )
  {
    v18 = (char *)((char *)silhouettes->m_data - (char *)p_m_pntr);
    v19 = v10;
    do
    {
      v20 = *(hkReferencedObject **)((char *)p_m_pntr + (_QWORD)v18);
      if ( v20 )
        hkReferencedObject::addReference(v20);
      if ( *p_m_pntr )
        hkReferencedObject::removeReference(*p_m_pntr);
      v21 = *(hkReferencedObject **)((char *)p_m_pntr++ + (_QWORD)v18);
      *(p_m_pntr - 1) = v21;
      --v19;
    }
    while ( v19 );
  }
  v22 = &silhouettes->m_data[v10];
  v23 = (int)m_size - v10;
  if ( (int)m_size - v10 > 0 )
  {
    v24 = (char *)&p_m_silhouetteGenerators->m_data[v10] - (char *)v22;
    do
    {
      if ( (hkRefPtr<hkaiSilhouetteGenerator> *)((char *)v22 + v24) )
      {
        if ( v22->m_pntr )
          hkReferencedObject::addReference(v22->m_pntr);
        *(hkRefPtr<hkaiSilhouetteGenerator> *)((char *)v22 + v24) = (hkRefPtr<hkaiSilhouetteGenerator>)v22->m_pntr;
      }
      ++v22;
      --v23;
    }
    while ( v23 );
  }
  v25 = (__int64)v52;
  p_m_silhouetteGenerators->m_size = m_size;
  v26 = HK_SUCCESS;
  result.m_enum = HK_SUCCESS;
  if ( *(int *)(v25 + 8) > 0 )
  {
    v27 = this;
    v28 = 0i64;
    v48 = 0i64;
    do
    {
      v49 = v26;
      hkaiOverlapManagerSection::clearGeneratorData(&v27->m_overlapManager.m_pntr->m_sections.m_data[v49]);
      v29 = v28 + *(_QWORD *)v25;
      v30 = *(int *)(v29 + 24);
      v31 = (_DWORD *)((char *)v27->m_overlapManager.m_pntr->m_sections.m_data + v28);
      v32 = v31[6];
      v33 = v30;
      if ( (int)v30 > v32 )
        v33 = v31[6];
      v34 = v31[7] & 0x3FFFFFFF;
      if ( v34 >= (int)v30 )
      {
        v53.m_enum = HK_SUCCESS;
      }
      else
      {
        v35 = 2 * v34;
        v36 = *(_DWORD *)(v29 + 24);
        if ( (int)v30 < v35 )
          v36 = v35;
        hkArrayUtil::_reserve(&v53, &hkContainerHeapAllocator::s_alloc, v31 + 4, v36, 8);
      }
      v37 = *((_QWORD *)v31 + 2) + 8 * v30;
      v38 = v32 - (int)v30 - 1;
      if ( (int)v38 >= 0 )
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
          v44 = *(hkReferencedObject **)((char *)v40++ + v41);
          *(v40 - 1) = v44;
          --v42;
        }
        while ( v42 );
      }
      v45 = (hkReferencedObject **)(*(_QWORD *)(v29 + 16) + 8i64 * v33);
      v46 = (int)v30 - v33;
      if ( (int)v30 - v33 > 0 )
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
      v27 = this;
      v25 = (__int64)v52;
      v31[6] = v30;
      this->m_overlapManager.m_pntr->m_sections.m_data[v48].m_numOriginalFaces = *(_DWORD *)(*(_QWORD *)v25
                                                                                           + v48 * 72
                                                                                           + 8);
      hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::operator=(
        &this->m_overlapManager.m_pntr->m_sections.m_data[v49].m_facePriorities,
        (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)(v49 * 72
                                                                                        + *(_QWORD *)v25
                                                                                        + 48i64));
      hkaiOverlapManagerSection::rebuildMap(&this->m_overlapManager.m_pntr->m_sections.m_data[v49], 1);
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
void __fastcall hkaiWorld::NavMeshModifiedCallbackContext::NavMeshModifiedCallbackContext(
        hkaiWorld::NavMeshModifiedCallbackContext *this,
        hkaiWorld *world,
        hkArrayBase<unsigned int> *cutFaceKeys,
        hkArrayBase<unsigned int> *uncutFaceKeys)
{
  this->m_world = world;
  this->m_cutFaceKeys = cutFaceKeys;
  this->m_uncutFaceKeys = uncutFaceKeys;
}

