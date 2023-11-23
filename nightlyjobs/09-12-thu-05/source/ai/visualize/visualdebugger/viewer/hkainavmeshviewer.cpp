// File Line: 25
// RVA: 0xC421F0
void __fastcall hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer(
        hkaiNavMeshBaseViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiViewerBase::hkaiViewerBase(this, contexts);
  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshBaseViewer::`vftable{for `hkReferencedObject};
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavMeshBaseViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshBaseViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshBaseViewer::`vftable;
  hkaiNavMeshDebugUtils::DebugInfo::DebugInfo(&this->m_settings);
  *(_WORD *)&this->m_settings.m_showFaces.m_bool = 0;
  this->m_settings.m_showUserEdges.m_bool = 0;
}

// File Line: 32
// RVA: 0xC42370
void __fastcall hkaiNavMeshBaseViewer::init(hkaiNavMeshBaseViewer *this)
{
  hkProcessHandler *m_processHandler; // rax
  int v2; // ebx
  __int64 v4; // rdi

  m_processHandler = this->m_processHandler;
  v2 = 0;
  if ( m_processHandler )
  {
    v4 = 0i64;
    do
    {
      if ( v2 >= SLODWORD(m_processHandler[22].vfptr) )
        break;
      ((void (__fastcall *)(hkDebugDisplayHandler **, _QWORD))this->m_displayHandler[1].vfptr)(
        &this->m_displayHandler,
        *(void *(__fastcall **)(hkProcessHandler *, unsigned int))((char *)&m_processHandler[21].vfptr->__vecDelDtor + v4));
      m_processHandler = this->m_processHandler;
      ++v2;
      v4 += 8i64;
    }
    while ( m_processHandler );
  }
}

// File Line: 40
// RVA: 0xC42260
void __fastcall hkaiNavMeshBaseViewer::~hkaiNavMeshBaseViewer(hkaiNavMeshBaseViewer *this)
{
  int v1; // edi
  __int64 v3; // rsi
  hkaiViewerContext *m_pntr; // rdx
  int m_capacityAndFlags; // r8d

  v1 = 0;
  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshBaseViewer::`vftable{for `hkReferencedObject};
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavMeshBaseViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshBaseViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshBaseViewer::`vftable;
  if ( this->m_context.m_pntr )
  {
    v3 = 0i64;
    do
    {
      m_pntr = this->m_context.m_pntr;
      if ( v1 >= m_pntr->m_worlds.m_size )
        break;
      hkaiNavMeshBaseViewer::worldRemovedCallback(
        (hkaiNavMeshBaseViewer *)&this->hkaiViewerContextWorldListener,
        m_pntr->m_worlds.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( this->m_context.m_pntr );
  }
  m_capacityAndFlags = this->m_settings.m_instanceEnabled.m_storage.m_words.m_capacityAndFlags;
  this->m_settings.m_instanceEnabled.m_storage.m_words.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_settings.m_instanceEnabled.m_storage.m_words.m_data,
      4 * m_capacityAndFlags);
  this->m_settings.m_instanceEnabled.m_storage.m_words.m_data = 0i64;
  this->m_settings.m_instanceEnabled.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  hkaiGraphDebugUtils::DebugInfo::~DebugInfo(&this->m_settings.m_clusterGraphSettings);
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable;
  hkaiViewerBase::~hkaiViewerBase(this);
}

// File Line: 48
// RVA: 0xC42440
void __fastcall hkaiNavMeshBaseViewer::worldAddedCallback(hkaiNavMeshBaseViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiNavMeshBaseViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 53
// RVA: 0xC42470
void __fastcall hkaiNavMeshBaseViewer::worldRemovedCallback(hkaiNavMeshBaseViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiNavMeshBaseViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 58
// RVA: 0xC423E0
void __fastcall hkaiNavMeshBaseViewer::postStepCallback(
        hkaiNavMeshBaseViewer *this,
        hkaiWorld *world,
        hkArrayBase<hkaiBehavior *> *behaviors)
{
  __int64 v3; // rax
  hkBitField *p_m_instanceEnabled; // rcx
  __int128 v6; // xmm0
  unsigned int *m_data; // rax
  hkaiStreamingCollection *m_pntr; // rbx
  int v9; // eax

  v3 = *((_QWORD *)&this[-1].m_settings.m_instanceEnabled + 3);
  p_m_instanceEnabled = &this[-1].m_settings.m_clusterGraphSettings.m_instanceEnabled;
  v6 = *(_OWORD *)(v3 + 224);
  m_data = p_m_instanceEnabled->m_storage.m_words.m_data;
  *(_OWORD *)&p_m_instanceEnabled[3].m_storage.m_words.m_size = v6;
  m_pntr = world->m_streamingCollection.m_pntr;
  v9 = (*((__int64 (__fastcall **)(hkBitField *, hkaiWorld *, hkArrayBase<hkaiBehavior *> *))m_data + 1))(
         p_m_instanceEnabled,
         world,
         behaviors);
  hkaiNavMeshDebugUtils::showStreamingCollection(
    (hkDebugDisplayHandler *)this[-1].m_settings.m_instanceEnabled.m_storage.m_words.m_data,
    v9,
    (hkaiNavMeshDebugUtils::DebugInfo *)&this->hkProcess,
    m_pntr);
}

// File Line: 72
// RVA: 0xC424A0
void hkaiNavMeshGeometryViewer::registerViewer(void)
{
  hkaiNavMeshGeometryViewer::m_tag = hkProcessFactory::registerProcess(
                                       hkSingleton<hkProcessFactory>::s_instance,
                                       "AI - Nav Mesh Geometry",
                                       hkaiNavMeshGeometryViewer::create);
}

// File Line: 77
// RVA: 0xC424D0
hkProcess *__fastcall hkaiNavMeshGeometryViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkaiNavMeshGeometryViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshGeometryViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                      Value[11],
                                      672i64);
  if ( v3 && (hkaiNavMeshGeometryViewer::hkaiNavMeshGeometryViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 83
// RVA: 0xC42CE0
void __fastcall hkaiNavMeshGeometryViewer::hkaiNavMeshGeometryViewer(
        hkaiNavMeshGeometryViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer(this, contexts);
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshGeometryViewer::`vftable{for `hkReferencedObject};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavMeshGeometryViewer::`vftable{for `hkProcess};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshGeometryViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiNavMeshBaseViewer::hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshGeometryViewer::`vftable;
  this->m_navMeshInfos.m_capacityAndFlags = 0x80000000;
  this->m_navMeshInfos.m_data = 0i64;
  this->m_navMeshInfos.m_size = 0;
  this->m_settings.m_showEdges.m_bool = 0;
  this->m_settings.m_showUserEdges.m_bool = 1;
}

// File Line: 90
// RVA: 0xC42D50
void __fastcall hkaiNavMeshGeometryViewer::~hkaiNavMeshGeometryViewer(hkaiNavMeshGeometryViewer *this)
{
  bool v1; // zf
  int v3; // eax
  __int64 v4; // rsi
  int *v5; // rdi
  int v6; // eax
  int m_capacityAndFlags; // eax

  v1 = this->m_navMeshInfos.m_size == 0;
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshGeometryViewer::`vftable{for `hkReferencedObject};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavMeshGeometryViewer::`vftable{for `hkProcess};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshGeometryViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiNavMeshBaseViewer::hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshGeometryViewer::`vftable;
  if ( !v1 )
  {
    do
      hkaiNavMeshGeometryViewer::removeNavMesh(this, this->m_navMeshInfos.m_data->m_navMeshInstance);
    while ( this->m_navMeshInfos.m_size );
  }
  v3 = this->m_navMeshInfos.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = &this->m_navMeshInfos.m_data->m_originalFaceBlocks.m_capacityAndFlags + 10 * v3;
    do
    {
      v6 = *v5;
      *(v5 - 1) = 0;
      if ( v6 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v5 - 3),
          24 * (v6 & 0x3FFFFFFF));
      *(_QWORD *)(v5 - 3) = 0i64;
      *v5 = 0x80000000;
      v5 -= 10;
      --v4;
    }
    while ( v4 >= 0 );
  }
  m_capacityAndFlags = this->m_navMeshInfos.m_capacityAndFlags;
  this->m_navMeshInfos.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_navMeshInfos.m_data,
      40 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_navMeshInfos.m_data = 0i64;
  this->m_navMeshInfos.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshBaseViewer::~hkaiNavMeshBaseViewer(this);
}

// File Line: 99
// RVA: 0xC42530
void __fastcall hkaiNavMeshGeometryViewer::worldRemovedCallback(hkaiNavMeshGeometryViewer *this, hkaiWorld *oldWorld)
{
  hkaiStreamingCollection *m_pntr; // rsi
  int v4; // ebx
  __int64 v5; // rdi

  m_pntr = oldWorld->m_streamingCollection.m_pntr;
  v4 = 0;
  if ( (int)hkaiStreamingCollection::getNumInstances(m_pntr) > 0 )
  {
    v5 = 0i64;
    do
    {
      hkaiNavMeshGeometryViewer::removeNavMesh(
        (hkaiNavMeshGeometryViewer *)((char *)this - 64),
        m_pntr->m_instances.m_data[v5].m_instancePtr);
      ++v4;
      ++v5;
    }
    while ( v4 < (int)hkaiStreamingCollection::getNumInstances(m_pntr) );
  }
}

// File Line: 111
// RVA: 0xC428D0
void __fastcall hkaiNavMeshGeometryViewer::dynamicNavMeshModifiedCallback(
        hkaiNavMeshGeometryViewer *this,
        hkaiWorld::NavMeshModifiedCallbackContext *context)
{
  hkaiNavMeshGeometryViewer *v3; // r14
  _QWORD *Value; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // rdi
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkaiWorld *m_world; // r15
  int m_size; // esi
  int v11; // edi
  hkLifoAllocator *v12; // rax
  unsigned int *m_cur; // rcx
  int v14; // edx
  char *v15; // r8
  int v16; // r9d
  int v17; // eax
  unsigned int *m_data; // rdi
  __int64 i; // rcx
  hkArrayBase<unsigned int> *m_cutFaceKeys; // r9
  hkArrayBase<unsigned int> *m_uncutFaceKeys; // r10
  int v22; // r8d
  __int64 v23; // rdi
  __int64 v24; // rdx
  int v25; // r8d
  __int64 v26; // rdi
  __int64 v27; // rdx
  hkaiStreamingCollection *m_pntr; // rdi
  hkResultEnum m_enum; // ebx
  __int64 v30; // rsi
  hkaiStreamingCollection::InstanceInfo *v31; // rax
  hkaiNavMeshInstance *v32; // rbp
  hkaiNavMeshGeometryViewer *v33; // r13
  int v34; // eax
  int v35; // edi
  __int64 v36; // r14
  __int64 v37; // rbx
  __int64 v38; // rsi
  int v39; // r15d
  int v40; // r12d
  unsigned int FlagBlockCrc; // eax
  unsigned __int64 v42; // rdx
  int v43; // r9d
  unsigned __int64 v44; // rdx
  int m_numOriginalFaces; // r9d
  _QWORD *v46; // rax
  _QWORD *v47; // rcx
  _QWORD *v48; // rdi
  unsigned __int64 v49; // rax
  _QWORD *v50; // rcx
  unsigned __int64 baseId; // [rsp+28h] [rbp-70h]
  __int64 v52; // [rsp+30h] [rbp-68h]
  hkBitFieldStorage<hkLocalArray<unsigned int> > array; // [rsp+38h] [rbp-60h] BYREF
  hkResult result; // [rsp+B0h] [rbp+18h] BYREF
  hkaiWorld *world; // [rsp+B8h] [rbp+20h]

  v3 = this;
  if ( *(_QWORD *)&this[-1].m_navMeshInfos.m_size )
  {
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v5 = (_QWORD *)Value[1];
    v6 = Value;
    if ( (unsigned __int64)v5 < Value[3] )
    {
      *v5 = "TthkaiNavMeshGeometryViewer";
      v7 = __rdtsc();
      v8 = v5 + 2;
      *((_DWORD *)v8 - 2) = v7;
      v6[1] = v8;
    }
    m_world = context->m_world;
    world = m_world;
    m_size = m_world->m_streamingCollection.m_pntr->m_instances.m_size;
    array.m_words.m_data = 0i64;
    array.m_words.m_size = 0;
    array.m_words.m_capacityAndFlags = 0x80000000;
    v11 = (m_size + 31) >> 5;
    array.m_words.m_initialCapacity = v11;
    if ( v11 )
    {
      v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (unsigned int *)v12->m_cur;
      v14 = (4 * v11 + 127) & 0xFFFFFF80;
      v15 = (char *)m_cur + v14;
      if ( v14 > v12->m_slabSize || v15 > v12->m_end )
        m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
      else
        v12->m_cur = v15;
    }
    else
    {
      m_cur = 0i64;
    }
    array.m_words.m_data = m_cur;
    array.m_words.m_localMemory = m_cur;
    array.m_numBits = m_size;
    array.m_words.m_capacityAndFlags = v11 | 0x80000000;
    if ( (v11 & 0x3FFFFFFF) < v11 )
    {
      v16 = (m_size + 31) >> 5;
      if ( v11 < 2 * (v11 & 0x3FFFFFFF) )
        v16 = 2 * (v11 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v16, 4);
    }
    v17 = v11 - 1;
    array.m_words.m_size = (m_size + 31) >> 5;
    if ( v11 - 1 >= 0 )
    {
      m_data = array.m_words.m_data;
      for ( i = (unsigned int)(v17 + 1); i; --i )
        *m_data++ = 0;
    }
    m_cutFaceKeys = context->m_cutFaceKeys;
    m_uncutFaceKeys = context->m_uncutFaceKeys;
    v22 = 0;
    if ( m_cutFaceKeys->m_size > 0 )
    {
      v23 = 0i64;
      do
      {
        ++v22;
        v24 = m_cutFaceKeys->m_data[v23++] >> 22;
        array.m_words.m_data[v24 >> 5] |= 1 << (v24 & 0x1F);
      }
      while ( v22 < m_cutFaceKeys->m_size );
    }
    v25 = 0;
    if ( m_uncutFaceKeys->m_size > 0 )
    {
      v26 = 0i64;
      do
      {
        ++v25;
        v27 = m_uncutFaceKeys->m_data[v26++] >> 22;
        array.m_words.m_data[v27 >> 5] |= 1 << (v27 & 0x1F);
      }
      while ( v25 < m_uncutFaceKeys->m_size );
    }
    m_pntr = m_world->m_streamingCollection.m_pntr;
    m_enum = HK_SUCCESS;
    result.m_enum = HK_SUCCESS;
    if ( m_pntr->m_instances.m_size > 0 )
    {
      v30 = 0i64;
      v52 = 0i64;
      do
      {
        if ( ((array.m_words.m_data[(__int64)(int)m_enum >> 5] >> (m_enum & 0x1F)) & 1) != 0 )
        {
          v31 = m_pntr->m_instances.m_data;
          v32 = *(hkaiNavMeshInstance **)((char *)&v31->m_instancePtr + v30);
          if ( v32 )
          {
            v33 = (hkaiNavMeshGeometryViewer *)((char *)v3 - 80);
            v34 = hkaiNavMeshGeometryViewer::indexOfInstance(
                    (hkaiNavMeshGeometryViewer *)((char *)v3 - 80),
                    *(hkaiNavMeshInstance **)((char *)&v31->m_instancePtr + v30));
            if ( v34 >= 0 )
            {
              v35 = 0;
              v36 = v3->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_u64[0] + 40i64 * v34;
              if ( *(int *)(v36 + 24) > 0 )
              {
                v37 = 0i64;
                do
                {
                  v38 = v37 + *(_QWORD *)(v36 + 16);
                  v39 = *(_DWORD *)v38;
                  v40 = *(_DWORD *)(v38 + 4);
                  FlagBlockCrc = hkaiNavMeshGeometryViewer::getFlagBlockCrc(v32, *(_DWORD *)v38, v40);
                  if ( FlagBlockCrc == *(_DWORD *)(v38 + 16) )
                  {
                    m_world = world;
                  }
                  else
                  {
                    v42 = *(_QWORD *)(v38 + 8);
                    *(_DWORD *)(v38 + 16) = FlagBlockCrc;
                    hkaiNavMeshGeometryViewer::removeGeometryForBlock(v33, v42);
                    v43 = v39;
                    m_world = world;
                    hkaiNavMeshGeometryViewer::addFaceGeometry(v33, v32, world, v43, v40, *(_QWORD *)(v38 + 8));
                  }
                  ++v35;
                  v37 += 24i64;
                }
                while ( v35 < *(_DWORD *)(v36 + 24) );
                m_enum = result.m_enum;
                v30 = v52;
              }
              v44 = *(_QWORD *)(v36 + 32);
              if ( v44 )
                hkaiNavMeshGeometryViewer::removeGeometryForBlock(v33, v44);
              if ( v32->m_ownedFaces.m_size > 0 )
              {
                m_numOriginalFaces = v32->m_numOriginalFaces;
                baseId = (unsigned __int64)v32->m_ownedFaces.m_data;
                *(_QWORD *)(v36 + 32) = baseId;
                hkaiNavMeshGeometryViewer::addFaceGeometry(
                  v33,
                  v32,
                  m_world,
                  m_numOriginalFaces,
                  v32->m_ownedFaces.m_size,
                  baseId);
              }
              v3 = this;
            }
          }
        }
        m_pntr = m_world->m_streamingCollection.m_pntr;
        ++m_enum;
        v30 += 48i64;
        result.m_enum = m_enum;
        v52 = v30;
      }
      while ( m_enum < m_pntr->m_instances.m_size );
    }
    hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&array);
    v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v47 = (_QWORD *)v46[1];
    v48 = v46;
    if ( (unsigned __int64)v47 < v46[3] )
    {
      *v47 = "Et";
      v49 = __rdtsc();
      v50 = v47 + 2;
      *((_DWORD *)v50 - 2) = v49;
      v48[1] = v50;
    }
  }
}

// File Line: 199
// RVA: 0xC425A0
void __fastcall hkaiNavMeshGeometryViewer::postStepCallback(
        hkaiNavMeshGeometryViewer *this,
        hkaiWorld *world,
        hkArrayBase<hkaiBehavior *> *behaviors)
{
  hkArrayBase<hkaiBehavior *> *v3; // r15
  _QWORD *Value; // rax
  unsigned __int64 v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  int v10; // ebx
  __int64 v11; // rsi
  unsigned __int64 v12; // rax
  hkaiNavMeshInstance *v13; // rdx
  hkaiStreamingCollection *m_pntr; // rax
  __int64 v15; // rcx
  __int64 m_size; // r8
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  hkaiStreamingCollection *v22; // rax
  int v23; // esi
  __int64 v24; // r14
  hkaiStreamingCollection::InstanceInfo *v25; // rax
  hkaiNavMeshInstance *m_instancePtr; // rbx
  _QWORD *v27; // r8
  _QWORD *v28; // rcx
  unsigned __int64 v29; // rax
  _QWORD *v30; // rcx
  hkVector4f *v31; // rax
  int v32; // r14d
  __int64 v33; // r12
  __int64 v34; // rbx
  int v35; // ebp
  __int64 v36; // rsi
  unsigned __int64 v37; // rdx
  _QWORD *v38; // rax
  _QWORD *v39; // rcx
  _QWORD *v40; // r8
  unsigned __int64 v41; // rax
  _QWORD *v42; // rcx
  _QWORD *v43; // r8
  _QWORD *v44; // rcx
  unsigned __int64 v45; // rax
  _QWORD *v46; // rcx
  hkTransformf aTb; // [rsp+20h] [rbp-A8h] BYREF
  hkTransformf transform; // [rsp+60h] [rbp-68h] BYREF

  v3 = behaviors;
  if ( *(_QWORD *)&this[-1].m_navMeshInfos.m_size )
  {
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v7 = Value[1];
    v8 = Value;
    if ( v7 < Value[3] )
    {
      *(_QWORD *)v7 = "LthkaiNavMeshGeometryViewer::postStepCallback";
      *(_QWORD *)(v7 + 16) = "Stadd";
      v9 = __rdtsc();
      *(_DWORD *)(v7 + 8) = v9;
      v8[1] = v7 + 24;
    }
    v10 = 0;
    if ( this->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_i32[2] > 0 )
    {
      v11 = 0i64;
      do
      {
        v12 = this->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_u64[0];
        if ( *(hkaiWorld **)(v11 + v12 + 8) == world )
        {
          v13 = *(hkaiNavMeshInstance **)(v11 + v12);
          m_pntr = world->m_streamingCollection.m_pntr;
          v15 = 0i64;
          m_size = m_pntr->m_instances.m_size;
          if ( m_size <= 0 )
          {
LABEL_11:
            hkaiNavMeshGeometryViewer::removeNavMesh((hkaiNavMeshGeometryViewer *)((char *)this - 80), v13);
            --v10;
            v11 -= 40i64;
          }
          else
          {
            m_data = m_pntr->m_instances.m_data;
            while ( v13 != m_data->m_instancePtr )
            {
              ++v15;
              ++m_data;
              if ( v15 >= m_size )
                goto LABEL_11;
            }
          }
        }
        ++v10;
        v11 += 40i64;
      }
      while ( v10 < this->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_i32[2] );
    }
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Stremove";
      v20 = __rdtsc();
      v21 = v19 + 2;
      *((_DWORD *)v21 - 2) = v20;
      v18[1] = v21;
    }
    v22 = world->m_streamingCollection.m_pntr;
    v23 = 0;
    if ( v22->m_instances.m_size > 0 )
    {
      v24 = 0i64;
      do
      {
        v25 = v22->m_instances.m_data;
        m_instancePtr = v25[v24].m_instancePtr;
        if ( m_instancePtr
          && hkaiNavMeshGeometryViewer::indexOfInstance(
               (hkaiNavMeshGeometryViewer *)((char *)this - 80),
               v25[v24].m_instancePtr) < 0 )
        {
          hkaiNavMeshGeometryViewer::addNavMesh((hkaiNavMeshGeometryViewer *)((char *)this - 80), m_instancePtr, world);
        }
        v22 = world->m_streamingCollection.m_pntr;
        ++v23;
        ++v24;
      }
      while ( v23 < v22->m_instances.m_size );
    }
    v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v28 = (_QWORD *)v27[1];
    if ( (unsigned __int64)v28 < v27[3] )
    {
      *v28 = "StupdateTransforms";
      v29 = __rdtsc();
      v30 = v28 + 2;
      *((_DWORD *)v30 - 2) = v29;
      v27[1] = v30;
    }
    v31 = *(hkVector4f **)&this[-1].m_navMeshInfos.m_size;
    v32 = 0;
    aTb.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
    aTb.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    aTb.m_translation = 0i64;
    aTb.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    aTb.m_translation = (hkVector4f)v31[14].m_quad;
    if ( this->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_i32[2] > 0 )
    {
      v33 = 0i64;
      do
      {
        v34 = v33 + this->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_u64[0];
        hkTransformf::setMul(&transform, &aTb, (hkTransformf *)(*(_QWORD *)v34 + 112i64));
        v35 = 0;
        if ( *(int *)(v34 + 24) > 0 )
        {
          v36 = 0i64;
          do
          {
            hkaiNavMeshGeometryViewer::updateGeometryForBlock(
              (hkaiNavMeshGeometryViewer *)((char *)this - 80),
              *(_QWORD *)(v36 + *(_QWORD *)(v34 + 16) + 8),
              &transform);
            ++v35;
            v36 += 24i64;
          }
          while ( v35 < *(_DWORD *)(v34 + 24) );
        }
        v37 = *(_QWORD *)(v34 + 32);
        if ( v37 )
          hkaiNavMeshGeometryViewer::updateGeometryForBlock(
            (hkaiNavMeshGeometryViewer *)((char *)this - 80),
            v37,
            &transform);
        ++v32;
        v33 += 40i64;
      }
      while ( v32 < this->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_i32[2] );
      v3 = behaviors;
    }
    v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v39 = (_QWORD *)v38[1];
    v40 = v38;
    if ( (unsigned __int64)v39 < v38[3] )
    {
      *v39 = "Stbase";
      v41 = __rdtsc();
      v42 = v39 + 2;
      *((_DWORD *)v42 - 2) = v41;
      v40[1] = v42;
    }
    hkaiNavMeshBaseViewer::postStepCallback(this, world, v3);
    v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v44 = (_QWORD *)v43[1];
    if ( (unsigned __int64)v44 < v43[3] )
    {
      *v44 = "lt";
      v45 = __rdtsc();
      v46 = v44 + 2;
      *((_DWORD *)v46 - 2) = v45;
      v43[1] = v46;
    }
  }
}

// File Line: 283
// RVA: 0xC42E90
void __fastcall hkaiNavMeshGeometryViewer::addNavMesh(
        hkaiNavMeshGeometryViewer *this,
        hkaiNavMeshInstance *navMeshInstance,
        hkaiWorld *world)
{
  hkArray<hkaiNavMeshGeometryViewer::NavMeshInfo,hkContainerHeapAllocator> *p_m_navMeshInfos; // rbx
  __int64 v6; // rdx
  __int64 m_size; // rdx
  int v8; // r12d
  __int64 v9; // r15
  _QWORD *v10; // rbx
  __int64 v11; // rdx
  __int64 v12; // rsi
  int m_numOriginalFaces; // ebp
  int numFaces; // ebp
  int *baseId; // rdi
  int v16; // r9d
  hkaiNavMesh::Face *m_data; // rcx
  hkaiWorld *worlda; // [rsp+80h] [rbp+18h]

  worlda = world;
  p_m_navMeshInfos = &this->m_navMeshInfos;
  if ( this->m_navMeshInfos.m_size == (this->m_navMeshInfos.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_navMeshInfos, 40);
    world = worlda;
  }
  v6 = (__int64)&p_m_navMeshInfos->m_data[p_m_navMeshInfos->m_size];
  if ( v6 )
  {
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_DWORD *)(v6 + 24) = 0;
    *(_DWORD *)(v6 + 28) = 0x80000000;
  }
  m_size = p_m_navMeshInfos->m_size;
  v8 = 0;
  v9 = (__int64)&p_m_navMeshInfos->m_data[m_size];
  p_m_navMeshInfos->m_size = m_size + 1;
  *(_QWORD *)v9 = navMeshInstance;
  *(_QWORD *)(v9 + 8) = world;
  if ( navMeshInstance->m_numOriginalFaces > 0 )
  {
    v10 = (_QWORD *)(v9 + 16);
    do
    {
      if ( *(_DWORD *)(v9 + 24) == (*(_DWORD *)(v9 + 28) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v10, 24);
      v11 = *(int *)(v9 + 24);
      v12 = *v10 + 24 * v11;
      *(_DWORD *)(v9 + 24) = v11 + 1;
      m_numOriginalFaces = navMeshInstance->m_numOriginalFaces;
      *(_DWORD *)v12 = v8;
      numFaces = m_numOriginalFaces - v8;
      if ( numFaces > 1024 )
        numFaces = 1024;
      *(_DWORD *)(v12 + 4) = numFaces;
      baseId = &navMeshInstance->m_faceMap.m_data[v8];
      *(_QWORD *)(v12 + 8) = baseId;
      *(_DWORD *)(v12 + 16) = hkaiNavMeshGeometryViewer::getFlagBlockCrc(navMeshInstance, v8, numFaces);
      hkaiNavMeshGeometryViewer::addFaceGeometry(this, navMeshInstance, worlda, v8, numFaces, (unsigned __int64)baseId);
      v8 += 1024;
    }
    while ( v8 < navMeshInstance->m_numOriginalFaces );
    world = worlda;
  }
  if ( navMeshInstance->m_ownedFaces.m_size <= 0 )
  {
    *(_QWORD *)(v9 + 32) = 0i64;
  }
  else
  {
    v16 = navMeshInstance->m_numOriginalFaces;
    m_data = navMeshInstance->m_ownedFaces.m_data;
    *(_QWORD *)(v9 + 32) = m_data;
    hkaiNavMeshGeometryViewer::addFaceGeometry(
      this,
      navMeshInstance,
      world,
      v16,
      navMeshInstance->m_ownedFaces.m_size,
      (unsigned __int64)m_data);
  }
}

// File Line: 315
// RVA: 0xC43090
void __fastcall hkaiNavMeshGeometryViewer::removeNavMesh(
        hkaiNavMeshGeometryViewer *this,
        hkaiNavMeshInstance *navMeshInstance)
{
  int v3; // eax
  int v4; // r14d
  __int64 v5; // r15
  int v6; // esi
  hkaiNavMeshGeometryViewer::NavMeshInfo *v7; // rbp
  __int64 v8; // rdi
  unsigned __int64 m_ownedFaceIdBase; // rdx
  hkaiNavMeshGeometryViewer::NavMeshInfo *v10; // rdi
  int m_capacityAndFlags; // eax
  __int64 v12; // rax
  hkaiNavMeshGeometryViewer::NavMeshInfo *m_data; // rdx
  hkaiNavMeshGeometryViewer::NavMeshInfo *v14; // r8
  hkaiNavMeshGeometryViewer::NavMeshInfo *v15; // rax
  __int64 v16; // rdx
  signed __int64 v17; // r8
  unsigned __int64 v18; // rcx

  v3 = hkaiNavMeshGeometryViewer::indexOfInstance(this, navMeshInstance);
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = v3;
    v6 = 0;
    v7 = &this->m_navMeshInfos.m_data[v5];
    if ( v7->m_originalFaceBlocks.m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        hkaiNavMeshGeometryViewer::removeGeometryForBlock(this, v7->m_originalFaceBlocks.m_data[v8].m_idBase);
        ++v6;
        ++v8;
      }
      while ( v6 < v7->m_originalFaceBlocks.m_size );
    }
    m_ownedFaceIdBase = v7->m_ownedFaceIdBase;
    if ( m_ownedFaceIdBase )
      hkaiNavMeshGeometryViewer::removeGeometryForBlock(this, m_ownedFaceIdBase);
    v10 = &this->m_navMeshInfos.m_data[v5];
    m_capacityAndFlags = v10->m_originalFaceBlocks.m_capacityAndFlags;
    v10->m_originalFaceBlocks.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v10->m_originalFaceBlocks.m_data,
        24 * (m_capacityAndFlags & 0x3FFFFFFF));
    v10->m_originalFaceBlocks.m_data = 0i64;
    v10->m_originalFaceBlocks.m_capacityAndFlags = 0x80000000;
    v12 = --this->m_navMeshInfos.m_size;
    if ( (_DWORD)v12 != v4 )
    {
      m_data = this->m_navMeshInfos.m_data;
      v14 = &m_data[v12];
      v15 = &m_data[v5];
      v16 = 5i64;
      v17 = (char *)v14 - (char *)v15;
      do
      {
        v18 = *(unsigned __int64 *)((char *)&v15->m_navMeshInstance + v17);
        v15 = (hkaiNavMeshGeometryViewer::NavMeshInfo *)((char *)v15 + 8);
        v15[-1].m_ownedFaceIdBase = v18;
        --v16;
      }
      while ( v16 );
    }
  }
}

// File Line: 339
// RVA: 0xC42CA0
void __fastcall hkaiNavMeshGeometryViewer::navMeshInstanceAdded(
        hkaiNavMeshGeometryViewer *this,
        hkaiWorld *world,
        hkaiNavMeshInstance *navMeshInstance,
        hkaiNavMeshQueryMediator *mediator,
        hkaiDirectedGraphInstance *hierarchyGraph)
{
  hkaiNavMeshGeometryViewer::addNavMesh((hkaiNavMeshGeometryViewer *)((char *)this - 80), navMeshInstance, world);
}

// File Line: 344
// RVA: 0xC42CC0
void __fastcall hkaiNavMeshGeometryViewer::navMeshInstanceRemoved(
        hkaiNavMeshGeometryViewer *this,
        hkaiWorld *world,
        hkaiNavMeshInstance *navMeshInstance,
        hkaiDirectedGraphInstance *hierarchyGraph)
{
  hkaiNavMeshGeometryViewer::removeNavMesh((hkaiNavMeshGeometryViewer *)((char *)this - 80), navMeshInstance);
}

// File Line: 350
// RVA: 0xC441B0
unsigned __int64 __fastcall getRemappedIndex(
        int oldIndex,
        hkPointerMap<int,int,hkContainerHeapAllocator> *vertexRemap,
        hkaiNavMeshInstance *navMeshInstance,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verts)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 result; // rax
  int m_size; // r14d
  hkVector4f *v10; // rcx
  int m_numOriginalVertices; // eax
  hkVector4f *v12; // rbx

  v4 = oldIndex;
  result = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
             &vertexRemap->m_map,
             oldIndex,
             0xFFFFFFFFFFFFFFFFui64);
  if ( (_DWORD)result == -1 )
  {
    m_size = verts->m_size;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &vertexRemap->m_map,
      &hkContainerHeapAllocator::s_alloc,
      v4,
      m_size);
    if ( verts->m_size == (verts->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, verts, 16);
    v10 = &verts->m_data[verts->m_size++];
    m_numOriginalVertices = navMeshInstance->m_numOriginalVertices;
    if ( (int)v4 >= m_numOriginalVertices )
      v12 = &navMeshInstance->m_ownedVertices.m_data[(int)v4 - m_numOriginalVertices];
    else
      v12 = &navMeshInstance->m_originalVertices[v4];
    result = (unsigned int)m_size;
    *v10 = (hkVector4f)v12->m_quad;
  }
  return result;
}

// File Line: 362
// RVA: 0xC431D0
void __fastcall hkaiNavMeshGeometryViewer::addFaceGeometry(
        hkaiNavMeshGeometryViewer *this,
        hkaiNavMeshInstance *navMeshInstance,
        hkaiWorld *world,
        int startFaceIndex,
        __int64 numFaces,
        unsigned __int64 baseId)
{
  __int64 v6; // rbx
  __int64 index; // r13
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  _QWORD **v14; // rax
  __int64 v15; // rax
  int *v16; // rbx
  _QWORD **v17; // rax
  hkDisplayWireframe *v18; // rax
  IAmdDxExt *v19; // rax
  _QWORD **v20; // rax
  hkDisplayWireframe *v21; // rax
  IAmdDxExtQuadBufferStereo *v22; // rax
  _QWORD **v23; // rax
  hkDisplayWireframe *v24; // rax
  __int64 v25; // rax
  _QWORD **v26; // rax
  hkDisplayWireframe *v27; // rax
  __int64 v28; // rax
  __int64 v29; // rcx
  __int64 *v30; // rax
  hkaiNavMesh::Face *v31; // rax
  __int64 v32; // r14
  hkaiNavMesh::Face *v33; // r12
  int v34; // edi
  int v35; // eax
  int v36; // r9d
  int v37; // eax
  __int64 v38; // rdi
  hkaiNavMesh::Edge *v39; // rax
  int RemappedIndex; // eax
  int m_numEdges; // ebx
  int v42; // r14d
  int *v43; // r15
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // r9
  hkaiNavMesh::Edge *v45; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v47; // r9
  hkaiNavMesh::Edge *v48; // rdi
  int v49; // ebx
  int v50; // eax
  int mStereo; // ecx
  int m_oppositeEdge; // ebx
  hkaiNavMesh::Edge *v53; // rax
  char v54; // al
  __int64 m_a; // rax
  int m_numOriginalVertices; // ecx
  hkVector4f *v57; // rax
  __m128 m_quad; // xmm7
  __int64 m_b; // rax
  hkVector4f *v60; // rax
  __m128 v61; // xmm6
  _DWORD *mExtension; // rbx
  char m_storage; // al
  _QWORD **v64; // rax
  hkDisplayConvex *v65; // rax
  hkReferencedObject *v66; // rax
  hkReferencedObject *v67; // r14
  hkVector4f *v68; // rax
  char *v69; // r12
  __int64 v70; // rbx
  int v71; // eax
  __int64 v72; // rsi
  __int64 v73; // rdi
  int v74; // eax
  unsigned int v75; // edx
  int v76; // ecx
  hkReferencedObject **v77; // r14
  __int64 v78; // rax
  __int64 *v79; // r15
  __int64 v80; // rsi
  __int64 v81; // r13
  hkReferencedObject *v82; // rdi
  __int64 *v83; // rax
  __int64 v84; // rbx
  int v85; // eax
  __int64 v86; // rbx
  int v87; // eax
  _QWORD *v88; // rax
  _QWORD *v89; // rcx
  _QWORD *v90; // r8
  unsigned __int64 v91; // rax
  _QWORD *v92; // rcx
  hkGeometry *geom; // [rsp+40h] [rbp-B8h]
  __int64 v94; // [rsp+48h] [rbp-B0h]
  _DWORD *v95; // [rsp+50h] [rbp-A8h] BYREF
  int v96; // [rsp+58h] [rbp-A0h]
  unsigned int v97; // [rsp+5Ch] [rbp-9Ch]
  _DWORD *v98; // [rsp+60h] [rbp-98h]
  AMD_HD3D vertexRemap; // [rsp+68h] [rbp-90h] BYREF
  __int64 *v100; // [rsp+88h] [rbp-70h] BYREF
  int v101; // [rsp+90h] [rbp-68h]
  int v102; // [rsp+94h] [rbp-64h]
  hkReferencedObject *v103; // [rsp+98h] [rbp-60h] BYREF
  __int64 *v104; // [rsp+A0h] [rbp-58h] BYREF
  int v105; // [rsp+A8h] [rbp-50h]
  int v106; // [rsp+ACh] [rbp-4Ch]
  hkReferencedObject *v107; // [rsp+B0h] [rbp-48h] BYREF
  __int64 v108[4]; // [rsp+B8h] [rbp-40h] BYREF
  hkTransformf aTb; // [rsp+D8h] [rbp-20h] BYREF
  hkTransformf v110; // [rsp+118h] [rbp+20h] BYREF
  char *retaddr; // [rsp+1B8h] [rbp+C0h]
  hkaiNavMeshGeometryViewer *result; // [rsp+1C0h] [rbp+C8h] BYREF
  __int64 v113; // [rsp+1D0h] [rbp+D8h] BYREF
  int v114; // [rsp+1D8h] [rbp+E0h] BYREF

  result = this;
  v113 = v6;
  index = startFaceIndex;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtaddFaceGeometry";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(v14[11], 48i64);
  v16 = (int *)v15;
  geom = (hkGeometry *)v15;
  if ( v15 )
  {
    *(_DWORD *)(v15 + 8) = 0x1FFFF;
    *(_QWORD *)v15 = &hkGeometry::`vftable;
    *(_QWORD *)(v15 + 16) = 0i64;
    *(_DWORD *)(v15 + 24) = 0;
    *(_DWORD *)(v15 + 28) = 0x80000000;
    *(_QWORD *)(v15 + 32) = 0i64;
    *(_DWORD *)(v15 + 40) = 0;
    *(_DWORD *)(v15 + 44) = 0x80000000;
  }
  else
  {
    v16 = 0i64;
    geom = 0i64;
  }
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v17[11] + 8i64))(v17[11], 128i64);
  if ( v18 )
  {
    hkDisplayWireframe::hkDisplayWireframe(v18);
    vertexRemap.mExtension = v19;
  }
  else
  {
    vertexRemap.mExtension = 0i64;
  }
  v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v20[11] + 8i64))(v20[11], 128i64);
  if ( v21 )
  {
    hkDisplayWireframe::hkDisplayWireframe(v21);
    vertexRemap.mStereo = v22;
  }
  else
  {
    vertexRemap.mStereo = 0i64;
  }
  v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v23[11] + 8i64))(v23[11], 128i64);
  if ( v24 )
  {
    hkDisplayWireframe::hkDisplayWireframe(v24);
    v98 = (_DWORD *)v25;
  }
  else
  {
    v98 = 0i64;
  }
  v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v26[11] + 8i64))(v26[11], 128i64);
  if ( v27 )
  {
    hkDisplayWireframe::hkDisplayWireframe(v27);
    v95 = (_DWORD *)v28;
  }
  else
  {
    v95 = 0i64;
  }
  v29 = index;
  *(_QWORD *)&vertexRemap.mEnableStereo = 0i64;
  vertexRemap.mWidth = 0;
  vertexRemap.mHeight = -1;
  HIDWORD(vertexRemap.mStereo) = index + v114;
  v94 = index;
  if ( (int)index < (int)index + v114 )
  {
    while ( 1 )
    {
      if ( navMeshInstance->m_faceFlags.m_size )
      {
        v30 = (__int64 *)&v114;
        LOBYTE(v114) = navMeshInstance->m_faceFlags.m_data[v29].m_storage;
        v29 = v94;
      }
      else
      {
        LOBYTE(v113) = 0;
        v30 = &v113;
      }
      if ( (*(_BYTE *)v30 & 1) == 0 )
      {
        v31 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__20(
                navMeshInstance->m_originalFaces,
                navMeshInstance->m_numOriginalFaces,
                &navMeshInstance->m_instancedFaces,
                &navMeshInstance->m_ownedFaces,
                &navMeshInstance->m_faceMap,
                index);
        v32 = v16[10];
        v33 = v31;
        v34 = v31->m_numEdges - 2;
        v35 = v16[11] & 0x3FFFFFFF;
        v36 = v34 + v32;
        if ( v35 >= v34 + (int)v32 )
        {
          LODWORD(result) = 0;
        }
        else
        {
          v37 = 2 * v35;
          if ( v36 < v37 )
            v36 = v37;
          hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, v16 + 8, v36, 16);
        }
        v16[10] += v34;
        v38 = *((_QWORD *)v16 + 4) + 16 * v32;
        v39 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__22(
                navMeshInstance->m_originalEdges,
                navMeshInstance->m_numOriginalEdges,
                &navMeshInstance->m_instancedEdges,
                &navMeshInstance->m_ownedEdges,
                &navMeshInstance->m_edgeMap,
                v33->m_startEdgeIndex);
        RemappedIndex = getRemappedIndex(
                          v39->m_a,
                          (hkPointerMap<int,int,hkContainerHeapAllocator> *)&vertexRemap,
                          navMeshInstance,
                          &geom->m_vertices);
        m_numEdges = v33->m_numEdges;
        v42 = 0;
        LODWORD(vertexRemap.mStereo) = RemappedIndex;
        if ( m_numEdges > 0 )
        {
          v43 = (int *)(v38 + 8);
          p_m_ownedEdges = &navMeshInstance->m_ownedEdges;
          do
          {
            v45 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__22(
                    navMeshInstance->m_originalEdges,
                    navMeshInstance->m_numOriginalEdges,
                    &navMeshInstance->m_instancedEdges,
                    p_m_ownedEdges,
                    &navMeshInstance->m_edgeMap,
                    v42 + v33->m_startEdgeIndex);
            v48 = v45;
            if ( v42 > 0 && v42 < m_numEdges - 1 )
            {
              v49 = getRemappedIndex(
                      v45->m_a,
                      (hkPointerMap<int,int,hkContainerHeapAllocator> *)&vertexRemap,
                      navMeshInstance,
                      &geom->m_vertices);
              v50 = getRemappedIndex(
                      v48->m_b,
                      (hkPointerMap<int,int,hkContainerHeapAllocator> *)&vertexRemap,
                      navMeshInstance,
                      &geom->m_vertices);
              mStereo = (int)vertexRemap.mStereo;
              *(v43 - 1) = v49;
              *(v43 - 2) = mStereo;
              *v43 = v50;
              v43 += 4;
              v47 = &navMeshInstance->m_ownedEdges;
              p_m_instancedEdges = &navMeshInstance->m_instancedEdges;
            }
            m_oppositeEdge = v48->m_oppositeEdge;
            if ( m_oppositeEdge == -1
              || (v48->m_flags.m_storage & 0x40) != 0
              || (int)index < (signed int)(v48->m_oppositeFace & 0x3FFFFF)
              || (((v53 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__22(
                            navMeshInstance->m_originalEdges,
                            navMeshInstance->m_numOriginalEdges,
                            p_m_instancedEdges,
                            v47,
                            &navMeshInstance->m_edgeMap,
                            m_oppositeEdge & 0x3FFFFF),
                    v48->m_a != v53->m_a)
                || v48->m_b != v53->m_b)
               && (v48->m_a != v53->m_b || v48->m_b != v53->m_a)
                ? (v54 = 0)
                : (v54 = 1),
                  !v54) )
            {
              m_a = v48->m_a;
              m_numOriginalVertices = navMeshInstance->m_numOriginalVertices;
              if ( (int)m_a >= m_numOriginalVertices )
                v57 = &navMeshInstance->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
              else
                v57 = &navMeshInstance->m_originalVertices[m_a];
              m_quad = v57->m_quad;
              m_b = v48->m_b;
              if ( (int)m_b >= m_numOriginalVertices )
                v60 = &navMeshInstance->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices];
              else
                v60 = &navMeshInstance->m_originalVertices[m_b];
              v61 = v60->m_quad;
              if ( m_oppositeEdge == -1 )
              {
                mExtension = vertexRemap.mStereo;
              }
              else
              {
                m_storage = v48->m_flags.m_storage;
                if ( (m_storage & 0x40) != 0 )
                {
                  mExtension = v98;
                }
                else
                {
                  mExtension = vertexRemap.mExtension;
                  if ( (m_storage & 2) != 0 )
                    mExtension = v95;
                }
              }
              if ( mExtension[30] == (mExtension[31] & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, mExtension + 28, 16);
              *(__m128 *)(*((_QWORD *)mExtension + 14) + 16i64 * (int)mExtension[30]++) = m_quad;
              if ( mExtension[30] == (mExtension[31] & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, mExtension + 28, 16);
              p_m_ownedEdges = &navMeshInstance->m_ownedEdges;
              *(__m128 *)(*((_QWORD *)mExtension + 14) + 16i64 * (int)mExtension[30]++) = v61;
            }
            m_numEdges = v33->m_numEdges;
            ++v42;
          }
          while ( v42 < m_numEdges );
        }
        v29 = v94;
      }
      ++v29;
      LODWORD(index) = index + 1;
      v94 = v29;
      if ( (int)index >= SHIDWORD(vertexRemap.mStereo) )
        break;
      v16 = (int *)geom;
    }
  }
  v64 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v65 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v64[11] + 8i64))(v64[11], 112i64);
  if ( v65 )
  {
    hkDisplayConvex::hkDisplayConvex(v65, geom);
    v67 = v66;
  }
  else
  {
    v67 = 0i64;
  }
  v102 = -2147483647;
  v103 = v67;
  aTb.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  aTb.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v100 = (__int64 *)&v103;
  v68 = (hkVector4f *)*((_QWORD *)retaddr + 9);
  v101 = 1;
  aTb.m_translation = 0i64;
  aTb.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  aTb.m_translation = (hkVector4f)v68[14].m_quad;
  hkTransformf::setMul(&v110, &aTb, &navMeshInstance->m_referenceFrame.m_transform);
  v69 = retaddr + 16;
  v70 = **((_QWORD **)retaddr + 6);
  v71 = (*(__int64 (__fastcall **)(char *))(*((_QWORD *)retaddr + 2) + 8i64))(retaddr + 16);
  v72 = numFaces;
  (*(void (__fastcall **)(_QWORD, int *, __int64 **, hkTransformf *, __int64, int, _QWORD, _DWORD))(v70 + 8))(
    *((_QWORD *)retaddr + 6),
    &v114,
    &v100,
    &v110,
    numFaces,
    v71,
    0i64,
    0);
  v73 = **((_QWORD **)retaddr + 6);
  LODWORD(v70) = *((_DWORD *)retaddr + 44);
  v74 = (*(__int64 (__fastcall **)(char *))(*((_QWORD *)retaddr + 2) + 8i64))(retaddr + 16);
  (*(void (__fastcall **)(_QWORD, int *, __int64, __int64, int))(v73 + 48))(
    *((_QWORD *)retaddr + 6),
    &v114,
    v70 & 0xFFFFFF | ((unsigned int)v70 >> 1) & 0x7F000000,
    v72,
    v74);
  hkReferencedObject::removeReference(v67);
  v75 = *((_DWORD *)retaddr + 46);
  v76 = *((_DWORD *)retaddr + 44);
  v108[0] = (__int64)vertexRemap.mExtension;
  v108[1] = (__int64)vertexRemap.mStereo;
  v77 = (hkReferencedObject **)v108;
  v108[2] = (__int64)v98;
  v78 = (__int64)v95;
  LODWORD(v95) = v75;
  v108[3] = v78;
  v79 = (__int64 *)&v95;
  HIDWORD(v95) = *((_DWORD *)retaddr + 45);
  v96 = *((_DWORD *)retaddr + 47);
  v80 = v72 + 1;
  v97 = ((v76 & v75) + (((v76 ^ v75) >> 1) & 0x7F7F7F)) | 0xFF000000;
  v81 = 4i64;
  do
  {
    v82 = *v77;
    v104 = (__int64 *)&v107;
    v83 = (__int64 *)*((_QWORD *)retaddr + 6);
    v106 = -2147483647;
    v107 = v82;
    v105 = 1;
    v84 = *v83;
    v85 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v69 + 8i64))(v69);
    (*(void (__fastcall **)(_QWORD, int *, __int64 **, hkTransformf *, __int64, int, _QWORD, _DWORD))(v84 + 8))(
      *((_QWORD *)retaddr + 6),
      &v114,
      &v104,
      &v110,
      v80,
      v85,
      0i64,
      0);
    v86 = **((_QWORD **)retaddr + 6);
    v87 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v69 + 8i64))(v69);
    (*(void (__fastcall **)(_QWORD, __int64 *, _QWORD, __int64, int))(v86 + 48))(
      *((_QWORD *)retaddr + 6),
      &v113,
      *(unsigned int *)v79,
      v80,
      v87);
    hkReferencedObject::removeReference(v82);
    v105 = 0;
    if ( v106 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v104, 8 * v106);
    ++v80;
    v79 = (__int64 *)((char *)v79 + 4);
    ++v77;
    --v81;
  }
  while ( v81 );
  v101 = 0;
  if ( v102 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v100, 8 * v102);
  v100 = 0i64;
  v102 = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&vertexRemap,
    &hkContainerHeapAllocator::s_alloc);
  _(&vertexRemap);
  v88 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v89 = (_QWORD *)v88[1];
  v90 = v88;
  if ( (unsigned __int64)v89 < v88[3] )
  {
    *v89 = "Et";
    v91 = __rdtsc();
    v92 = v89 + 2;
    *((_DWORD *)v92 - 2) = v91;
    v90[1] = v92;
  }
}Operations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&vertexRemap,
    &hkContainerHeapAllocator::s_alloc);
  _(&vertexRemap);
  v88 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v89 = (_QWORD *)v88[1];
  v90 = v88;
  if ( (unsigned __int64)v89 < v88[3] )
  {
    *

// File Line: 470
// RVA: 0xC43A80
void __fastcall hkaiNavMeshGeometryViewer::removeGeometryForBlock(
        hkaiNavMeshGeometryViewer *this,
        unsigned __int64 baseId)
{
  __int64 v4; // rbp
  hkDebugDisplayHandlerVtbl *vfptr; // rbx
  unsigned int v6; // eax
  char v7; // [rsp+60h] [rbp+18h] BYREF

  v4 = 5i64;
  do
  {
    vfptr = this->m_displayHandler->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr;
    v6 = this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr->getProcessTag(&this->hkProcess);
    vfptr->removeGeometry(this->m_displayHandler, (hkResult *)&v7, baseId++, v6, 0i64);
    --v4;
  }
  while ( v4 );
}

// File Line: 478
// RVA: 0xC43B00
void __fastcall hkaiNavMeshGeometryViewer::updateGeometryForBlock(
        hkaiNavMeshGeometryViewer *this,
        unsigned __int64 baseId,
        hkTransformf *transform)
{
  __int64 v6; // rbp
  hkDebugDisplayHandlerVtbl *vfptr; // rbx
  int v8; // eax
  char v9; // [rsp+68h] [rbp+20h] BYREF

  v6 = 5i64;
  do
  {
    vfptr = this->m_displayHandler->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr;
    v8 = this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr->getProcessTag(&this->hkProcess);
    vfptr->updateGeometry(this->m_displayHandler, (hkResult *)&v9, transform, baseId++, v8);
    --v6;
  }
  while ( v6 );
}

// File Line: 488
// RVA: 0xC43B80
__int64 __fastcall hkaiNavMeshGeometryViewer::getFlagBlockCrc(
        hkaiNavMeshInstance *instance,
        int startFaceIndex,
        int numFaces)
{
  __int64 v3; // rdi
  unsigned int v4; // ebx
  __int64 v5; // r14
  int m_size; // esi
  char *v8; // rax
  char m_storage; // [rsp+48h] [rbp+10h] BYREF
  char v11; // [rsp+50h] [rbp+18h] BYREF

  v3 = startFaceIndex;
  v4 = -1;
  v5 = startFaceIndex + numFaces;
  if ( startFaceIndex < v5 )
  {
    m_size = instance->m_faceFlags.m_size;
    do
    {
      if ( m_size )
      {
        v8 = &m_storage;
        m_storage = instance->m_faceFlags.m_data[v3].m_storage;
      }
      else
      {
        v11 = 0;
        v8 = &v11;
      }
      ++v3;
      v4 = hkCrcStreamWriter<unsigned int,3988292384>::calcPermute((unsigned __int8)(v4 ^ *v8)) ^ (v4 >> 8);
    }
    while ( v3 < v5 );
  }
  return ~v4;
}

// File Line: 506
// RVA: 0xC43C10
__int64 __fastcall hkaiNavMeshGeometryViewer::indexOfInstance(
        hkaiNavMeshGeometryViewer *this,
        hkaiNavMeshInstance *instance)
{
  __int64 m_size; // r10
  unsigned int v3; // r9d
  __int64 v4; // r8
  hkaiNavMeshGeometryViewer::NavMeshInfo *i; // rax

  m_size = this->m_navMeshInfos.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = this->m_navMeshInfos.m_data; instance != i->m_navMeshInstance; ++i )
  {
    ++v4;
    ++v3;
    if ( v4 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 525
// RVA: 0xC43C60
void hkaiNavMeshVertexNormalsViewer::registerViewer(void)
{
  hkaiNavMeshVertexNormalsViewer::m_tag = hkProcessFactory::registerProcess(
                                            hkSingleton<hkProcessFactory>::s_instance,
                                            "AI - Nav Mesh Vertex Normals",
                                            hkaiNavMeshVertexNormalsViewer::create);
}

// File Line: 530
// RVA: 0xC43C90
hkProcess *__fastcall hkaiNavMeshVertexNormalsViewer::create(
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkaiNavMeshVertexNormalsViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshVertexNormalsViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                           Value[11],
                                           656i64);
  if ( v3 && (hkaiNavMeshVertexNormalsViewer::hkaiNavMeshVertexNormalsViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 536
// RVA: 0xC43CF0
void __fastcall hkaiNavMeshVertexNormalsViewer::hkaiNavMeshVertexNormalsViewer(
        hkaiNavMeshVertexNormalsViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer(this, contexts);
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshVertexNormalsViewer::`vftable{for `hkReferencedObject};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavMeshVertexNormalsViewer::`vftable{for `hkProcess};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshVertexNormalsViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiNavMeshBaseViewer::hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshVertexNormalsViewer::`vftable;
  this->m_settings.m_showVertexNormals.m_bool = 1;
}

// File Line: 547
// RVA: 0xC43D40
void hkaiNavMeshEdgeNormalsViewer::registerViewer(void)
{
  hkaiNavMeshEdgeNormalsViewer::m_tag = hkProcessFactory::registerProcess(
                                          hkSingleton<hkProcessFactory>::s_instance,
                                          "AI - Nav Mesh Edge Normals",
                                          hkaiNavMeshEdgeNormalsViewer::create);
}

// File Line: 552
// RVA: 0xC43D70
hkProcess *__fastcall hkaiNavMeshEdgeNormalsViewer::create(
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkaiNavMeshEdgeNormalsViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshEdgeNormalsViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                         Value[11],
                                         656i64);
  if ( v3 && (hkaiNavMeshEdgeNormalsViewer::hkaiNavMeshEdgeNormalsViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 558
// RVA: 0xC43DD0
void __fastcall hkaiNavMeshEdgeNormalsViewer::hkaiNavMeshEdgeNormalsViewer(
        hkaiNavMeshEdgeNormalsViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer(this, contexts);
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshEdgeNormalsViewer::`vftable{for `hkReferencedObject};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavMeshEdgeNormalsViewer::`vftable{for `hkProcess};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshEdgeNormalsViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiNavMeshBaseViewer::hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshEdgeNormalsViewer::`vftable;
  this->m_settings.m_showEdgeNormals.m_bool = 1;
}

// File Line: 569
// RVA: 0xC43E20
void hkaiNavMeshFaceNormalsViewer::registerViewer(void)
{
  hkaiNavMeshFaceNormalsViewer::m_tag = hkProcessFactory::registerProcess(
                                          hkSingleton<hkProcessFactory>::s_instance,
                                          "AI - Nav Mesh Face Normals",
                                          hkaiNavMeshFaceNormalsViewer::create);
}

// File Line: 574
// RVA: 0xC43E50
hkProcess *__fastcall hkaiNavMeshFaceNormalsViewer::create(
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkaiNavMeshFaceNormalsViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshFaceNormalsViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                         Value[11],
                                         656i64);
  if ( v3 && (hkaiNavMeshFaceNormalsViewer::hkaiNavMeshFaceNormalsViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 580
// RVA: 0xC43EB0
void __fastcall hkaiNavMeshFaceNormalsViewer::hkaiNavMeshFaceNormalsViewer(
        hkaiNavMeshFaceNormalsViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer(this, contexts);
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshFaceNormalsViewer::`vftable{for `hkReferencedObject};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavMeshFaceNormalsViewer::`vftable{for `hkProcess};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshFaceNormalsViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiNavMeshBaseViewer::hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshFaceNormalsViewer::`vftable;
  this->m_settings.m_showNormals.m_bool = 1;
}

// File Line: 591
// RVA: 0xC43F00
void hkaiNavMeshVertexLabelsViewer::registerViewer(void)
{
  hkaiNavMeshVertexLabelsViewer::m_tag = hkProcessFactory::registerProcess(
                                           hkSingleton<hkProcessFactory>::s_instance,
                                           "AI - Nav Mesh Vertex Labels",
                                           hkaiNavMeshVertexLabelsViewer::create);
}

// File Line: 596
// RVA: 0xC43F30
hkProcess *__fastcall hkaiNavMeshVertexLabelsViewer::create(
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkaiNavMeshVertexLabelsViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshVertexLabelsViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                          Value[11],
                                          656i64);
  if ( v3 && (hkaiNavMeshVertexLabelsViewer::hkaiNavMeshVertexLabelsViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 602
// RVA: 0xC43F90
void __fastcall hkaiNavMeshVertexLabelsViewer::hkaiNavMeshVertexLabelsViewer(
        hkaiNavMeshVertexLabelsViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer(this, contexts);
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshVertexLabelsViewer::`vftable{for `hkReferencedObject};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavMeshVertexLabelsViewer::`vftable{for `hkProcess};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshVertexLabelsViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiNavMeshBaseViewer::hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshVertexLabelsViewer::`vftable;
  this->m_settings.m_labelVertices.m_bool = 1;
}

// File Line: 613
// RVA: 0xC43FE0
void hkaiNavMeshEdgeLabelsViewer::registerViewer(void)
{
  hkaiNavMeshEdgeLabelsViewer::m_tag = hkProcessFactory::registerProcess(
                                         hkSingleton<hkProcessFactory>::s_instance,
                                         "AI - Nav Mesh Edge Labels",
                                         hkaiNavMeshEdgeLabelsViewer::create);
}

// File Line: 618
// RVA: 0xC44010
hkProcess *__fastcall hkaiNavMeshEdgeLabelsViewer::create(
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkaiNavMeshEdgeLabelsViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshEdgeLabelsViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                        Value[11],
                                        656i64);
  if ( v3 && (hkaiNavMeshEdgeLabelsViewer::hkaiNavMeshEdgeLabelsViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 624
// RVA: 0xC44070
void __fastcall hkaiNavMeshEdgeLabelsViewer::hkaiNavMeshEdgeLabelsViewer(
        hkaiNavMeshEdgeLabelsViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer(this, contexts);
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshEdgeLabelsViewer::`vftable{for `hkReferencedObject};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavMeshEdgeLabelsViewer::`vftable{for `hkProcess};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshEdgeLabelsViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiNavMeshBaseViewer::hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshEdgeLabelsViewer::`vftable;
  this->m_settings.m_labelEdges.m_bool = 1;
}

// File Line: 635
// RVA: 0xC440C0
void hkaiNavMeshFaceLabelsViewer::registerViewer(void)
{
  hkaiNavMeshFaceLabelsViewer::m_tag = hkProcessFactory::registerProcess(
                                         hkSingleton<hkProcessFactory>::s_instance,
                                         "AI - Nav Mesh Face Labels",
                                         hkaiNavMeshFaceLabelsViewer::create);
}

// File Line: 640
// RVA: 0xC440F0
hkProcess *__fastcall hkaiNavMeshFaceLabelsViewer::create(
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkaiNavMeshFaceLabelsViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshFaceLabelsViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                        Value[11],
                                        656i64);
  if ( v3 && (hkaiNavMeshFaceLabelsViewer::hkaiNavMeshFaceLabelsViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 646
// RVA: 0xC44150
void __fastcall hkaiNavMeshFaceLabelsViewer::hkaiNavMeshFaceLabelsViewer(
        hkaiNavMeshFaceLabelsViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer(this, contexts);
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshFaceLabelsViewer::`vftable{for `hkReferencedObject};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavMeshFaceLabelsViewer::`vftable{for `hkProcess};
  this->hkaiNavMeshBaseViewer::hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshFaceLabelsViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiNavMeshBaseViewer::hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshFaceLabelsViewer::`vftable;
  this->m_settings.m_labelFaces.m_bool = 1;
}

