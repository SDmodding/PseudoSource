// File Line: 25
// RVA: 0xC421F0
void __fastcall hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer(hkaiNavMeshBaseViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshBaseViewer *v2; // rbx

  v2 = this;
  hkaiViewerBase::hkaiViewerBase((hkaiViewerBase *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshBaseViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiNavMeshBaseViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshBaseViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshBaseViewer::`vftable';
  hkaiNavMeshDebugUtils::DebugInfo::DebugInfo(&v2->m_settings);
  *(_WORD *)&v2->m_settings.m_showFaces.m_bool = 0;
  v2->m_settings.m_showUserEdges.m_bool = 0;
}

// File Line: 32
// RVA: 0xC42370
void __fastcall hkaiNavMeshBaseViewer::init(hkaiNavMeshBaseViewer *this)
{
  hkProcessHandler *v1; // rax
  int v2; // ebx
  hkaiNavMeshBaseViewer *v3; // rsi
  __int64 v4; // rdi

  v1 = this->m_processHandler;
  v2 = 0;
  v3 = this;
  if ( v1 )
  {
    v4 = 0i64;
    do
    {
      if ( v2 >= SLODWORD(v1[22].vfptr) )
        break;
      ((void (__fastcall *)(hkDebugDisplayHandler **, _QWORD))v3->m_displayHandler[1].vfptr)(
        &v3->m_displayHandler,
        *(void *(__fastcall **)(hkProcessHandler *, unsigned int))((char *)&v1[21].vfptr->__vecDelDtor + v4));
      v1 = v3->m_processHandler;
      ++v2;
      v4 += 8i64;
    }
    while ( v1 );
  }
}

// File Line: 40
// RVA: 0xC42260
void __fastcall hkaiNavMeshBaseViewer::~hkaiNavMeshBaseViewer(hkaiNavMeshBaseViewer *this)
{
  int v1; // edi
  hkaiNavMeshBaseViewer *v2; // rbx
  __int64 v3; // rsi
  hkaiViewerContext *v4; // rdx
  int v5; // er8

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshBaseViewer::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessVtbl *)&hkaiNavMeshBaseViewer::`vftable'{for `hkProcess'};
  v2 = this;
  this->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshBaseViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  this->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshBaseViewer::`vftable';
  if ( this->m_context.m_pntr )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_context.m_pntr;
      if ( v1 >= v4->m_worlds.m_size )
        break;
      hkaiNavMeshBaseViewer::worldRemovedCallback((hkaiNavMeshBaseViewer *)((char *)v2 + 64), v4->m_worlds.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v2->m_context.m_pntr );
  }
  v5 = v2->m_settings.m_instanceEnabled.m_storage.m_words.m_capacityAndFlags;
  v2->m_settings.m_instanceEnabled.m_storage.m_words.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_settings.m_instanceEnabled.m_storage.m_words.m_data,
      4 * v5);
  v2->m_settings.m_instanceEnabled.m_storage.m_words.m_data = 0i64;
  v2->m_settings.m_instanceEnabled.m_storage.m_words.m_capacityAndFlags = 2147483648;
  hkaiGraphDebugUtils::DebugInfo::~DebugInfo(&v2->m_settings.m_clusterGraphSettings);
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable';
  hkaiViewerBase::~hkaiViewerBase((hkaiViewerBase *)&v2->vfptr);
}

// File Line: 48
// RVA: 0xC42440
void __fastcall hkaiNavMeshBaseViewer::worldAddedCallback(hkaiNavMeshBaseViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiNavMeshBaseViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->vfptr);
}

// File Line: 53
// RVA: 0xC42470
void __fastcall hkaiNavMeshBaseViewer::worldRemovedCallback(hkaiNavMeshBaseViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiNavMeshBaseViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->vfptr);
}

// File Line: 58
// RVA: 0xC423E0
void __fastcall hkaiNavMeshBaseViewer::postStepCallback(hkaiNavMeshBaseViewer *this, hkaiWorld *world, hkArrayBase<hkaiBehavior *> *behaviors)
{
  __int64 v3; // rax
  hkaiNavMeshBaseViewer *v4; // rsi
  hkBitField *v5; // rcx
  __int128 v6; // xmm0
  unsigned int *v7; // rax
  hkaiStreamingCollection *v8; // rbx
  int v9; // eax

  v3 = *((_QWORD *)&this[-1].m_settings.m_instanceEnabled + 3);
  v4 = this;
  v5 = &this[-1].m_settings.m_clusterGraphSettings.m_instanceEnabled;
  v6 = *(_OWORD *)(v3 + 224);
  v7 = v5->m_storage.m_words.m_data;
  *(_OWORD *)&v5[3].m_storage.m_words.m_size = v6;
  v8 = world->m_streamingCollection.m_pntr;
  v9 = (*((__int64 (__fastcall **)(hkBitField *, hkaiWorld *, hkArrayBase<hkaiBehavior *> *))v7 + 1))(
         v5,
         world,
         behaviors);
  hkaiNavMeshDebugUtils::showStreamingCollection(
    (hkDebugDisplayHandler *)v4[-1].m_settings.m_instanceEnabled.m_storage.m_words.m_data,
    v9,
    (hkaiNavMeshDebugUtils::DebugInfo *)&v4->vfptr,
    v8);
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
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiNavMeshGeometryViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshGeometryViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                      v2[11],
                                      672i64);
  if ( v3 && (hkaiNavMeshGeometryViewer::hkaiNavMeshGeometryViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 83
// RVA: 0xC42CE0
void __fastcall hkaiNavMeshGeometryViewer::hkaiNavMeshGeometryViewer(hkaiNavMeshGeometryViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshGeometryViewer *v2; // rbx

  v2 = this;
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer((hkaiNavMeshBaseViewer *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshGeometryViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiNavMeshGeometryViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshGeometryViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshGeometryViewer::`vftable';
  v2->m_navMeshInfos.m_capacityAndFlags = 2147483648;
  v2->m_navMeshInfos.m_data = 0i64;
  v2->m_navMeshInfos.m_size = 0;
  v2->m_settings.m_showEdges.m_bool = 0;
  v2->m_settings.m_showUserEdges.m_bool = 1;
}

// File Line: 90
// RVA: 0xC42D50
void __fastcall hkaiNavMeshGeometryViewer::~hkaiNavMeshGeometryViewer(hkaiNavMeshGeometryViewer *this)
{
  bool v1; // zf
  hkaiNavMeshGeometryViewer *v2; // rbx
  int v3; // eax
  __int64 v4; // rsi
  int *v5; // rdi
  int v6; // eax
  int v7; // eax

  v1 = this->m_navMeshInfos.m_size == 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshGeometryViewer::`vftable'{for `hkReferencedObject'};
  v2 = this;
  this->vfptr = (hkProcessVtbl *)&hkaiNavMeshGeometryViewer::`vftable'{for `hkProcess'};
  this->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshGeometryViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  this->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshGeometryViewer::`vftable';
  if ( !v1 )
  {
    do
      hkaiNavMeshGeometryViewer::removeNavMesh(v2, v2->m_navMeshInfos.m_data->m_navMeshInstance);
    while ( v2->m_navMeshInfos.m_size );
  }
  v3 = v2->m_navMeshInfos.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = &v2->m_navMeshInfos.m_data->m_originalFaceBlocks.m_capacityAndFlags + 10 * v3;
    do
    {
      v6 = *v5;
      *(v5 - 1) = 0;
      if ( v6 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v5 - 3),
          24 * (v6 & 0x3FFFFFFF));
      *(_QWORD *)(v5 - 3) = 0i64;
      *v5 = 2147483648;
      v5 -= 10;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v7 = v2->m_navMeshInfos.m_capacityAndFlags;
  v2->m_navMeshInfos.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_navMeshInfos.m_data,
      40 * (v7 & 0x3FFFFFFF));
  v2->m_navMeshInfos.m_data = 0i64;
  v2->m_navMeshInfos.m_capacityAndFlags = 2147483648;
  hkaiNavMeshBaseViewer::~hkaiNavMeshBaseViewer((hkaiNavMeshBaseViewer *)&v2->vfptr);
}

// File Line: 99
// RVA: 0xC42530
void __fastcall hkaiNavMeshGeometryViewer::worldRemovedCallback(hkaiNavMeshGeometryViewer *this, hkaiWorld *oldWorld)
{
  hkaiStreamingCollection *v2; // rsi
  hkaiNavMeshGeometryViewer *v3; // rbp
  signed int v4; // ebx
  __int64 v5; // rdi

  v2 = oldWorld->m_streamingCollection.m_pntr;
  v3 = this;
  v4 = 0;
  if ( (signed int)hkaiStreamingCollection::getNumInstances(oldWorld->m_streamingCollection.m_pntr) > 0 )
  {
    v5 = 0i64;
    do
    {
      hkaiNavMeshGeometryViewer::removeNavMesh(
        (hkaiNavMeshGeometryViewer *)((char *)v3 - 64),
        v2->m_instances.m_data[v5].m_instancePtr);
      ++v4;
      ++v5;
    }
    while ( v4 < (signed int)hkaiStreamingCollection::getNumInstances(v2) );
  }
}

// File Line: 111
// RVA: 0xC428D0
void __fastcall hkaiNavMeshGeometryViewer::dynamicNavMeshModifiedCallback(hkaiNavMeshGeometryViewer *this, hkaiWorld::NavMeshModifiedCallbackContext *context)
{
  hkaiWorld::NavMeshModifiedCallbackContext *v2; // rbx
  hkaiNavMeshGeometryViewer *v3; // r14
  _QWORD *v4; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // rdi
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkaiWorld *v9; // r15
  int v10; // esi
  int v11; // edi
  hkLifoAllocator *v12; // rax
  char *v13; // rcx
  int v14; // edx
  char *v15; // r8
  signed int v16; // eax
  int v17; // eax
  int v18; // er9
  int v19; // eax
  _DWORD *v20; // rdi
  __int64 i; // rcx
  hkArrayBase<unsigned int> *v22; // r9
  hkArrayBase<unsigned int> *v23; // r10
  int v24; // er8
  __int64 v25; // rdi
  unsigned int v26; // ecx
  int v27; // er8
  __int64 v28; // rdi
  unsigned int v29; // ecx
  hkaiStreamingCollection *v30; // rdi
  hkResultEnum v31; // ebx
  __int64 v32; // rsi
  hkaiStreamingCollection::InstanceInfo *v33; // rax
  hkaiNavMeshInstance *v34; // rbp
  hkaiNavMeshGeometryViewer *v35; // r13
  int v36; // eax
  int v37; // edi
  signed __int64 v38; // r14
  __int64 v39; // rbx
  __int64 v40; // rsi
  int v41; // er15
  int v42; // er12
  unsigned int v43; // eax
  unsigned __int64 v44; // rdx
  int v45; // er9
  unsigned __int64 v46; // rdx
  int v47; // er9
  unsigned __int64 baseId; // ST28_8
  _QWORD *v49; // rax
  _QWORD *v50; // rcx
  _QWORD *v51; // rdi
  unsigned __int64 v52; // rax
  signed __int64 v53; // rcx
  __int64 v54; // [rsp+30h] [rbp-68h]
  _DWORD *array; // [rsp+38h] [rbp-60h]
  int v56; // [rsp+40h] [rbp-58h]
  unsigned int v57; // [rsp+44h] [rbp-54h]
  char *v58; // [rsp+48h] [rbp-50h]
  int v59; // [rsp+50h] [rbp-48h]
  int v60; // [rsp+58h] [rbp-40h]
  hkaiNavMeshGeometryViewer *v61; // [rsp+A0h] [rbp+8h]
  hkResult result; // [rsp+B0h] [rbp+18h]
  hkaiWorld *world; // [rsp+B8h] [rbp+20h]

  v61 = this;
  v2 = context;
  v3 = this;
  if ( *(_QWORD *)&this[-1].m_navMeshInfos.m_size )
  {
    v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v5 = (_QWORD *)v4[1];
    v6 = v4;
    if ( (unsigned __int64)v5 < v4[3] )
    {
      *v5 = "TthkaiNavMeshGeometryViewer";
      v7 = __rdtsc();
      v8 = (signed __int64)(v5 + 2);
      *(_DWORD *)(v8 - 8) = v7;
      v6[1] = v8;
    }
    v9 = v2->m_world;
    world = v9;
    v10 = v9->m_streamingCollection.m_pntr->m_instances.m_size;
    array = 0i64;
    v56 = 0;
    v57 = 2147483648;
    v11 = (v10 + 31) >> 5;
    v59 = v11;
    if ( v11 )
    {
      v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (char *)v12->m_cur;
      v14 = (4 * v11 + 127) & 0xFFFFFF80;
      v15 = &v13[v14];
      if ( v14 > v12->m_slabSize || v15 > v12->m_end )
        v13 = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
      else
        v12->m_cur = v15;
    }
    else
    {
      v13 = 0i64;
    }
    array = v13;
    v58 = v13;
    v60 = v10;
    v57 = v11 | 0x80000000;
    v16 = (v11 | 0x80000000) & 0x3FFFFFFF;
    if ( v16 < v11 )
    {
      v17 = 2 * v16;
      v18 = (v10 + 31) >> 5;
      if ( v11 < v17 )
        v18 = v17;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v18, 4);
    }
    v19 = v11 - 1;
    v56 = (v10 + 31) >> 5;
    if ( v11 - 1 >= 0 )
    {
      v20 = array;
      for ( i = (unsigned int)(v19 + 1); i; --i )
      {
        *v20 = 0;
        ++v20;
      }
    }
    v22 = v2->m_cutFaceKeys;
    v23 = v2->m_uncutFaceKeys;
    v24 = 0;
    if ( v22->m_size > 0 )
    {
      v25 = 0i64;
      do
      {
        ++v24;
        ++v25;
        v26 = v22->m_data[v25 - 1] >> 22;
        array[(signed __int64)v26 >> 5] |= 1 << (v26 & 0x1F);
      }
      while ( v24 < v22->m_size );
    }
    v27 = 0;
    if ( v23->m_size > 0 )
    {
      v28 = 0i64;
      do
      {
        ++v27;
        ++v28;
        v29 = v23->m_data[v28 - 1] >> 22;
        array[(signed __int64)v29 >> 5] |= 1 << (v29 & 0x1F);
      }
      while ( v27 < v23->m_size );
    }
    v30 = v9->m_streamingCollection.m_pntr;
    v31 = 0;
    result.m_enum = 0;
    if ( v30->m_instances.m_size > 0 )
    {
      v32 = 0i64;
      v54 = 0i64;
      do
      {
        if ( (array[(signed __int64)(signed int)v31 >> 5] >> (v31 & 0x1F)) & 1 )
        {
          v33 = v30->m_instances.m_data;
          v34 = *(hkaiNavMeshInstance **)((char *)&v33->m_instancePtr + v32);
          if ( v34 )
          {
            v35 = (hkaiNavMeshGeometryViewer *)((char *)v3 - 80);
            v36 = hkaiNavMeshGeometryViewer::indexOfInstance(
                    (hkaiNavMeshGeometryViewer *)((char *)v3 - 80),
                    *(hkaiNavMeshInstance **)((char *)&v33->m_instancePtr + v32));
            if ( v36 >= 0 )
            {
              v37 = 0;
              v38 = v3->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_u64[0] + 40i64 * v36;
              if ( *(_DWORD *)(v38 + 24) > 0 )
              {
                v39 = 0i64;
                do
                {
                  v40 = v39 + *(_QWORD *)(v38 + 16);
                  v41 = *(_DWORD *)v40;
                  v42 = *(_DWORD *)(v40 + 4);
                  v43 = hkaiNavMeshGeometryViewer::getFlagBlockCrc(v34, *(_DWORD *)v40, *(_DWORD *)(v40 + 4));
                  if ( v43 == *(_DWORD *)(v40 + 16) )
                  {
                    v9 = world;
                  }
                  else
                  {
                    v44 = *(_QWORD *)(v40 + 8);
                    *(_DWORD *)(v40 + 16) = v43;
                    hkaiNavMeshGeometryViewer::removeGeometryForBlock(v35, v44);
                    v45 = v41;
                    v9 = world;
                    hkaiNavMeshGeometryViewer::addFaceGeometry(v35, v34, world, v45, v42, *(_QWORD *)(v40 + 8));
                  }
                  ++v37;
                  v39 += 24i64;
                }
                while ( v37 < *(_DWORD *)(v38 + 24) );
                v31 = result.m_enum;
                v32 = v54;
              }
              v46 = *(_QWORD *)(v38 + 32);
              if ( v46 )
                hkaiNavMeshGeometryViewer::removeGeometryForBlock(v35, v46);
              if ( v34->m_ownedFaces.m_size > 0 )
              {
                v47 = v34->m_numOriginalFaces;
                baseId = (unsigned __int64)v34->m_ownedFaces.m_data;
                *(_QWORD *)(v38 + 32) = v34->m_ownedFaces.m_data;
                hkaiNavMeshGeometryViewer::addFaceGeometry(v35, v34, v9, v47, v34->m_ownedFaces.m_size, baseId);
              }
              v3 = v61;
            }
          }
        }
        v30 = v9->m_streamingCollection.m_pntr;
        ++v31;
        v32 += 48i64;
        result.m_enum = v31;
        v54 = v32;
      }
      while ( v31 < v30->m_instances.m_size );
    }
    hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&array);
    v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v50 = (_QWORD *)v49[1];
    v51 = v49;
    if ( (unsigned __int64)v50 < v49[3] )
    {
      *v50 = "Et";
      v52 = __rdtsc();
      v53 = (signed __int64)(v50 + 2);
      *(_DWORD *)(v53 - 8) = v52;
      v51[1] = v53;
    }
  }
}

// File Line: 199
// RVA: 0xC425A0
void __fastcall hkaiNavMeshGeometryViewer::postStepCallback(hkaiNavMeshGeometryViewer *this, hkaiWorld *world, hkArrayBase<hkaiBehavior *> *behaviors)
{
  hkArrayBase<hkaiBehavior *> *v3; // r15
  hkaiWorld *v4; // r13
  hkaiNavMeshGeometryViewer *v5; // rdi
  _QWORD *v6; // rax
  unsigned __int64 v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  int v10; // ebx
  __int64 v11; // rsi
  unsigned __int64 v12; // rax
  hkaiNavMeshInstance *v13; // rdx
  hkaiStreamingCollection *v14; // rax
  __int64 v15; // rcx
  __int64 v16; // r8
  hkaiNavMeshInstance **v17; // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx
  hkaiStreamingCollection *v22; // rax
  int v23; // esi
  __int64 v24; // r14
  hkaiStreamingCollection::InstanceInfo *v25; // rax
  hkaiNavMeshInstance *v26; // rbx
  _QWORD *v27; // r8
  _QWORD *v28; // rcx
  unsigned __int64 v29; // rax
  signed __int64 v30; // rcx
  hkVector4f *v31; // rax
  int v32; // er14
  __int64 v33; // r12
  unsigned __int64 v34; // rbx
  int v35; // ebp
  __int64 v36; // rsi
  unsigned __int64 v37; // rdx
  _QWORD *v38; // rax
  _QWORD *v39; // rcx
  _QWORD *v40; // r8
  unsigned __int64 v41; // rax
  signed __int64 v42; // rcx
  _QWORD *v43; // r8
  _QWORD *v44; // rcx
  unsigned __int64 v45; // rax
  signed __int64 v46; // rcx
  hkTransformf aTb; // [rsp+20h] [rbp-A8h]
  hkTransformf transform; // [rsp+60h] [rbp-68h]
  hkArrayBase<hkaiBehavior *> *v49; // [rsp+E0h] [rbp+18h]

  v49 = behaviors;
  v3 = behaviors;
  v4 = world;
  v5 = this;
  if ( *(_QWORD *)&this[-1].m_navMeshInfos.m_size )
  {
    v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v7 = v6[1];
    v8 = v6;
    if ( v7 < v6[3] )
    {
      *(_QWORD *)v7 = "LthkaiNavMeshGeometryViewer::postStepCallback";
      *(_QWORD *)(v7 + 16) = "Stadd";
      v9 = __rdtsc();
      *(_DWORD *)(v7 + 8) = v9;
      v8[1] = v7 + 24;
    }
    v10 = 0;
    if ( v5->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_i32[2] > 0 )
    {
      v11 = 0i64;
      do
      {
        v12 = v5->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_u64[0];
        if ( *(hkaiWorld **)(v11 + v12 + 8) == v4 )
        {
          v13 = *(hkaiNavMeshInstance **)(v11 + v12);
          v14 = v4->m_streamingCollection.m_pntr;
          v15 = 0i64;
          v16 = v14->m_instances.m_size;
          if ( v16 <= 0 )
          {
LABEL_11:
            hkaiNavMeshGeometryViewer::removeNavMesh((hkaiNavMeshGeometryViewer *)((char *)v5 - 80), v13);
            --v10;
            v11 -= 40i64;
          }
          else
          {
            v17 = &v14->m_instances.m_data->m_instancePtr;
            while ( v13 != *v17 )
            {
              ++v15;
              v17 += 6;
              if ( v15 >= v16 )
                goto LABEL_11;
            }
          }
        }
        ++v10;
        v11 += 40i64;
      }
      while ( v10 < v5->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_i32[2] );
    }
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Stremove";
      v20 = __rdtsc();
      v21 = (signed __int64)(v19 + 2);
      *(_DWORD *)(v21 - 8) = v20;
      v18[1] = v21;
    }
    v22 = v4->m_streamingCollection.m_pntr;
    v23 = 0;
    if ( v22->m_instances.m_size > 0 )
    {
      v24 = 0i64;
      do
      {
        v25 = v22->m_instances.m_data;
        v26 = v25[v24].m_instancePtr;
        if ( v26
          && hkaiNavMeshGeometryViewer::indexOfInstance(
               (hkaiNavMeshGeometryViewer *)((char *)v5 - 80),
               v25[v24].m_instancePtr) < 0 )
        {
          hkaiNavMeshGeometryViewer::addNavMesh((hkaiNavMeshGeometryViewer *)((char *)v5 - 80), v26, v4);
        }
        v22 = v4->m_streamingCollection.m_pntr;
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
      v30 = (signed __int64)(v28 + 2);
      *(_DWORD *)(v30 - 8) = v29;
      v27[1] = v30;
    }
    v31 = *(hkVector4f **)&v5[-1].m_navMeshInfos.m_size;
    v32 = 0;
    aTb.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
    aTb.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    aTb.m_translation = 0i64;
    aTb.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    aTb.m_translation = (hkVector4f)v31[14].m_quad;
    if ( v5->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_i32[2] > 0 )
    {
      v33 = 0i64;
      do
      {
        v34 = v33 + v5->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_u64[0];
        hkTransformf::setMul(&transform, &aTb, (hkTransformf *)(*(_QWORD *)v34 + 112i64));
        v35 = 0;
        if ( *(_DWORD *)(v34 + 24) > 0 )
        {
          v36 = 0i64;
          do
          {
            hkaiNavMeshGeometryViewer::updateGeometryForBlock(
              (hkaiNavMeshGeometryViewer *)((char *)v5 - 80),
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
            (hkaiNavMeshGeometryViewer *)((char *)v5 - 80),
            v37,
            &transform);
        ++v32;
        v33 += 40i64;
      }
      while ( v32 < v5->m_settings.m_clusterGraphSettings.m_pruneLabelsAabb.m_max.m_quad.m128_i32[2] );
      v3 = v49;
    }
    v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v39 = (_QWORD *)v38[1];
    v40 = v38;
    if ( (unsigned __int64)v39 < v38[3] )
    {
      *v39 = "Stbase";
      v41 = __rdtsc();
      v42 = (signed __int64)(v39 + 2);
      *(_DWORD *)(v42 - 8) = v41;
      v40[1] = v42;
    }
    hkaiNavMeshBaseViewer::postStepCallback((hkaiNavMeshBaseViewer *)&v5->vfptr, v4, v3);
    v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v44 = (_QWORD *)v43[1];
    if ( (unsigned __int64)v44 < v43[3] )
    {
      *v44 = "lt";
      v45 = __rdtsc();
      v46 = (signed __int64)(v44 + 2);
      *(_DWORD *)(v46 - 8) = v45;
      v43[1] = v46;
    }
  }
}

// File Line: 283
// RVA: 0xC42E90
void __fastcall hkaiNavMeshGeometryViewer::addNavMesh(hkaiNavMeshGeometryViewer *this, hkaiNavMeshInstance *navMeshInstance, hkaiWorld *world)
{
  signed int *v3; // rbx
  hkaiNavMeshInstance *v4; // r14
  hkaiNavMeshGeometryViewer *v5; // r13
  signed __int64 v6; // rdx
  __int64 v7; // rdx
  int v8; // er12
  signed __int64 v9; // r15
  _QWORD *v10; // rbx
  __int64 v11; // rdx
  signed __int64 v12; // rsi
  int v13; // ebp
  int numFaces; // ebp
  unsigned __int64 baseId; // rdi
  int v16; // er9
  unsigned __int64 v17; // rcx
  hkaiWorld *worlda; // [rsp+80h] [rbp+18h]

  worlda = world;
  v3 = (signed int *)&this->m_navMeshInfos;
  v4 = navMeshInstance;
  v5 = this;
  if ( this->m_navMeshInfos.m_size == (this->m_navMeshInfos.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 40);
    world = worlda;
  }
  v6 = *(_QWORD *)v3 + 40i64 * v3[2];
  if ( v6 )
  {
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_DWORD *)(v6 + 24) = 0;
    *(_DWORD *)(v6 + 28) = 2147483648;
  }
  v7 = v3[2];
  v8 = 0;
  v9 = *(_QWORD *)v3 + 40 * v7;
  v3[2] = v7 + 1;
  *(_QWORD *)v9 = v4;
  *(_QWORD *)(v9 + 8) = world;
  if ( v4->m_numOriginalFaces > 0 )
  {
    v10 = (_QWORD *)(v9 + 16);
    do
    {
      if ( *(_DWORD *)(v9 + 24) == (*(_DWORD *)(v9 + 28) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 24);
      v11 = *(signed int *)(v9 + 24);
      v12 = *v10 + 24 * v11;
      *(_DWORD *)(v9 + 24) = v11 + 1;
      v13 = v4->m_numOriginalFaces;
      *(_DWORD *)v12 = v8;
      numFaces = v13 - v8;
      if ( numFaces > 1024 )
        numFaces = 1024;
      *(_DWORD *)(v12 + 4) = numFaces;
      baseId = (unsigned __int64)&v4->m_faceMap.m_data[v8];
      *(_QWORD *)(v12 + 8) = baseId;
      *(_DWORD *)(v12 + 16) = hkaiNavMeshGeometryViewer::getFlagBlockCrc(v4, v8, numFaces);
      hkaiNavMeshGeometryViewer::addFaceGeometry(v5, v4, worlda, v8, numFaces, baseId);
      v8 += 1024;
    }
    while ( v8 < v4->m_numOriginalFaces );
    world = worlda;
  }
  if ( v4->m_ownedFaces.m_size <= 0 )
  {
    *(_QWORD *)(v9 + 32) = 0i64;
  }
  else
  {
    v16 = v4->m_numOriginalFaces;
    v17 = (unsigned __int64)v4->m_ownedFaces.m_data;
    *(_QWORD *)(v9 + 32) = v17;
    hkaiNavMeshGeometryViewer::addFaceGeometry(v5, v4, world, v16, v4->m_ownedFaces.m_size, v17);
  }
}

// File Line: 315
// RVA: 0xC43090
void __fastcall hkaiNavMeshGeometryViewer::removeNavMesh(hkaiNavMeshGeometryViewer *this, hkaiNavMeshInstance *navMeshInstance)
{
  hkaiNavMeshGeometryViewer *v2; // rbx
  int v3; // eax
  int v4; // er14
  signed __int64 v5; // r15
  int v6; // esi
  signed __int64 v7; // rbp
  __int64 v8; // rdi
  unsigned __int64 v9; // rdx
  hkaiNavMeshGeometryViewer::NavMeshInfo *v10; // rdi
  int v11; // eax
  __int64 v12; // rax
  hkaiNavMeshGeometryViewer::NavMeshInfo *v13; // rdx
  signed __int64 v14; // r8
  signed __int64 v15; // rax
  signed __int64 v16; // rdx
  signed __int64 v17; // r8
  __int64 v18; // rcx

  v2 = this;
  v3 = hkaiNavMeshGeometryViewer::indexOfInstance(this, navMeshInstance);
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = v3;
    v6 = 0;
    v7 = (signed __int64)&v2->m_navMeshInfos.m_data[v3];
    if ( *(_DWORD *)(v7 + 24) > 0 )
    {
      v8 = 0i64;
      do
      {
        hkaiNavMeshGeometryViewer::removeGeometryForBlock(v2, *(_QWORD *)(v8 + *(_QWORD *)(v7 + 16) + 8));
        ++v6;
        v8 += 24i64;
      }
      while ( v6 < *(_DWORD *)(v7 + 24) );
    }
    v9 = *(_QWORD *)(v7 + 32);
    if ( v9 )
      hkaiNavMeshGeometryViewer::removeGeometryForBlock(v2, v9);
    v10 = &v2->m_navMeshInfos.m_data[v5];
    v11 = v10->m_originalFaceBlocks.m_capacityAndFlags;
    v10->m_originalFaceBlocks.m_size = 0;
    if ( v11 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v10->m_originalFaceBlocks.m_data,
        24 * (v11 & 0x3FFFFFFF));
    v10->m_originalFaceBlocks.m_data = 0i64;
    v10->m_originalFaceBlocks.m_capacityAndFlags = 2147483648;
    v12 = --v2->m_navMeshInfos.m_size;
    if ( (_DWORD)v12 != v4 )
    {
      v13 = v2->m_navMeshInfos.m_data;
      v14 = (signed __int64)&v13[v12];
      v15 = (signed __int64)&v13[v5];
      v16 = 5i64;
      v17 = v14 - v15;
      do
      {
        v18 = *(_QWORD *)(v17 + v15);
        v15 += 8i64;
        *(_QWORD *)(v15 - 8) = v18;
        --v16;
      }
      while ( v16 );
    }
  }
}

// File Line: 339
// RVA: 0xC42CA0
void __fastcall hkaiNavMeshGeometryViewer::navMeshInstanceAdded(hkaiNavMeshGeometryViewer *this, hkaiWorld *world, hkaiNavMeshInstance *navMeshInstance, hkaiNavMeshQueryMediator *mediator, hkaiDirectedGraphInstance *hierarchyGraph)
{
  hkaiNavMeshGeometryViewer::addNavMesh((hkaiNavMeshGeometryViewer *)((char *)this - 80), navMeshInstance, world);
}

// File Line: 344
// RVA: 0xC42CC0
void __fastcall hkaiNavMeshGeometryViewer::navMeshInstanceRemoved(hkaiNavMeshGeometryViewer *this, hkaiWorld *world, hkaiNavMeshInstance *navMeshInstance, hkaiDirectedGraphInstance *hierarchyGraph)
{
  hkaiNavMeshGeometryViewer::removeNavMesh((hkaiNavMeshGeometryViewer *)((char *)this - 80), navMeshInstance);
}

// File Line: 350
// RVA: 0xC441B0
unsigned __int64 __fastcall getRemappedIndex(int oldIndex, hkPointerMap<int,int,hkContainerHeapAllocator> *vertexRemap, hkaiNavMeshInstance *navMeshInstance, hkArray<hkVector4f,hkContainerHeapAllocator> *verts)
{
  unsigned __int64 v4; // rsi
  hkPointerMap<int,int,hkContainerHeapAllocator> *v5; // r15
  hkaiNavMeshInstance *v6; // rbp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rdi
  unsigned __int64 result; // rax
  unsigned int v9; // er14
  _OWORD *v10; // rcx
  signed int v11; // eax
  _OWORD *v12; // rbx

  v4 = oldIndex;
  v5 = vertexRemap;
  v6 = navMeshInstance;
  v7 = verts;
  result = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&vertexRemap->m_map.m_elem,
             oldIndex,
             0xFFFFFFFFFFFFFFFFui64);
  if ( (_DWORD)result == -1 )
  {
    v9 = v7->m_size;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v5->m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v4,
      v7->m_size);
    if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
    v10 = (_OWORD *)v7->m_data[v7->m_size++].m_quad.m128_f32;
    v11 = v6->m_numOriginalVertices;
    if ( (signed int)v4 >= v11 )
      v12 = (_OWORD *)v6->m_ownedVertices.m_data[(signed int)v4 - v11].m_quad.m128_f32;
    else
      v12 = (_OWORD *)v6->m_originalVertices[v4].m_quad.m128_f32;
    result = v9;
    *v10 = *v12;
  }
  return result;
}

// File Line: 362
// RVA: 0xC431D0
void __usercall hkaiNavMeshGeometryViewer::addFaceGeometry(hkaiNavMeshGeometryViewer *this@<rcx>, hkaiNavMeshInstance *navMeshInstance@<rdx>, hkaiWorld *world@<r8>, int startFaceIndex@<r9d>, __int64 a5@<rbx>, int numFaces, unsigned __int64 baseId)
{
  __int64 v7; // r13
  hkaiNavMeshInstance *v8; // rsi
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  _QWORD **v14; // rax
  __int64 v15; // rax
  signed int *v16; // rbx
  _QWORD **v17; // rax
  hkDisplayWireframe *v18; // rax
  __int64 v19; // rax
  _QWORD **v20; // rax
  hkDisplayWireframe *v21; // rax
  __int64 v22; // rax
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
  int v36; // er9
  int v37; // eax
  signed __int64 v38; // rdi
  hkaiNavMesh::Edge *v39; // rax
  int v40; // eax
  int v41; // ebx
  int v42; // er14
  int *v43; // r15
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v44; // r9
  hkaiNavMesh::Edge *v45; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v46; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v47; // r9
  hkaiNavMesh::Edge *v48; // rdi
  int v49; // ebx
  int v50; // eax
  int v51; // ecx
  signed int v52; // ebx
  hkaiNavMesh::Edge *v53; // rax
  char v54; // al
  __int64 v55; // rax
  signed int v56; // ecx
  __int128 *v57; // rax
  __int128 v58; // xmm7
  __int64 v59; // rax
  __int128 *v60; // rax
  __int128 v61; // xmm6
  _DWORD *v62; // rbx
  char v63; // al
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
  hkArray<int,hkContainerHeapAllocator> *ST20_8_68; // ST20_8
  unsigned int v75; // edx
  int v76; // ecx
  hkReferencedObject **v77; // r14
  __int64 v78; // rax
  __int64 *v79; // r15
  signed __int64 v80; // rsi
  signed __int64 v81; // r13
  hkReferencedObject *v82; // rdi
  __int64 *v83; // rax
  __int64 v84; // rbx
  __int64 v85; // rbx
  hkArray<int,hkContainerHeapAllocator> *ST20_8_69; // ST20_8
  _QWORD *v87; // rax
  _QWORD *v88; // rcx
  _QWORD *v89; // r8
  unsigned __int64 v90; // rax
  signed __int64 v91; // rcx
  __int64 index; // [rsp+28h] [rbp-D0h]
  __int64 indexa; // [rsp+28h] [rbp-D0h]
  __int64 v94; // [rsp+38h] [rbp-C0h]
  hkGeometry *geom; // [rsp+40h] [rbp-B8h]
  __int64 v96; // [rsp+48h] [rbp-B0h]
  _DWORD *v97; // [rsp+50h] [rbp-A8h]
  int v98; // [rsp+58h] [rbp-A0h]
  unsigned int v99; // [rsp+5Ch] [rbp-9Ch]
  _DWORD *v100; // [rsp+60h] [rbp-98h]
  hkPointerMap<int,int,hkContainerHeapAllocator> vertexRemap; // [rsp+68h] [rbp-90h]
  _DWORD *v102; // [rsp+78h] [rbp-80h]
  _DWORD *v103; // [rsp+80h] [rbp-78h]
  __int64 *v104; // [rsp+88h] [rbp-70h]
  int v105; // [rsp+90h] [rbp-68h]
  int v106; // [rsp+94h] [rbp-64h]
  hkReferencedObject *v107; // [rsp+98h] [rbp-60h]
  __int64 *v108; // [rsp+A0h] [rbp-58h]
  int v109; // [rsp+A8h] [rbp-50h]
  int v110; // [rsp+ACh] [rbp-4Ch]
  hkReferencedObject *v111; // [rsp+B0h] [rbp-48h]
  _DWORD *v112; // [rsp+B8h] [rbp-40h]
  _DWORD *v113; // [rsp+C0h] [rbp-38h]
  _DWORD *v114; // [rsp+C8h] [rbp-30h]
  __int64 v115; // [rsp+D0h] [rbp-28h]
  hkTransformf aTb; // [rsp+D8h] [rbp-20h]
  hkTransformf v117; // [rsp+118h] [rbp+20h]
  char *retaddr; // [rsp+1B8h] [rbp+C0h]
  hkaiNavMeshGeometryViewer *result; // [rsp+1C0h] [rbp+C8h]
  __int64 v120; // [rsp+1D0h] [rbp+D8h]
  int v121; // [rsp+1D8h] [rbp+E0h]

  result = this;
  v120 = a5;
  v7 = startFaceIndex;
  v8 = navMeshInstance;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtaddFaceGeometry";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 48i64);
  v16 = (signed int *)v15;
  geom = (hkGeometry *)v15;
  if ( v15 )
  {
    *(_DWORD *)(v15 + 8) = 0x1FFFF;
    *(_QWORD *)v15 = &hkGeometry::`vftable';
    *(_QWORD *)(v15 + 16) = 0i64;
    *(_DWORD *)(v15 + 24) = 0;
    *(_DWORD *)(v15 + 28) = 2147483648;
    *(_QWORD *)(v15 + 32) = 0i64;
    *(_DWORD *)(v15 + 40) = 0;
    *(_DWORD *)(v15 + 44) = 2147483648;
  }
  else
  {
    v16 = 0i64;
    geom = 0i64;
  }
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(v17[11], 128i64);
  if ( v18 )
  {
    hkDisplayWireframe::hkDisplayWireframe(v18);
    v103 = (_DWORD *)v19;
  }
  else
  {
    v103 = 0i64;
  }
  v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v20[11] + 8i64))(v20[11], 128i64);
  if ( v21 )
  {
    hkDisplayWireframe::hkDisplayWireframe(v21);
    v102 = (_DWORD *)v22;
  }
  else
  {
    v102 = 0i64;
  }
  v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v23[11] + 8i64))(v23[11], 128i64);
  if ( v24 )
  {
    hkDisplayWireframe::hkDisplayWireframe(v24);
    v100 = (_DWORD *)v25;
  }
  else
  {
    v100 = 0i64;
  }
  v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v26[11] + 8i64))(v26[11], 128i64);
  if ( v27 )
  {
    hkDisplayWireframe::hkDisplayWireframe(v27);
    v97 = (_DWORD *)v28;
  }
  else
  {
    v97 = 0i64;
  }
  v29 = v7;
  vertexRemap.m_map.m_elem = 0i64;
  vertexRemap.m_map.m_numElems = 0;
  vertexRemap.m_map.m_hashMod = -1;
  HIDWORD(v102) = v7 + v121;
  v96 = v7;
  if ( (signed int)v7 < (signed int)v7 + v121 )
  {
    while ( 1 )
    {
      if ( v8->m_faceFlags.m_size )
      {
        v30 = (__int64 *)&v121;
        LOBYTE(v121) = v8->m_faceFlags.m_data[v29].m_storage;
        v29 = v96;
      }
      else
      {
        LOBYTE(v120) = 0;
        v30 = &v120;
      }
      if ( !(*(_BYTE *)v30 & 1) )
      {
        v31 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__20(
                v8->m_originalFaces,
                v8->m_numOriginalFaces,
                &v8->m_instancedFaces,
                &v8->m_ownedFaces,
                &v8->m_faceMap,
                v7);
        v32 = v16[10];
        v33 = v31;
        v34 = v31->m_numEdges - 2;
        v35 = v16[11] & 0x3FFFFFFF;
        v36 = v34 + v32;
        if ( v35 >= v34 + (signed int)v32 )
        {
          LODWORD(result) = 0;
        }
        else
        {
          v37 = 2 * v35;
          if ( v36 < v37 )
            v36 = v37;
          hkArrayUtil::_reserve(
            (hkResult *)&result,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v16 + 8,
            v36,
            16);
        }
        v16[10] += v34;
        v38 = *((_QWORD *)v16 + 4) + 16 * v32;
        v39 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__22(
                v8->m_originalEdges,
                v8->m_numOriginalEdges,
                &v8->m_instancedEdges,
                &v8->m_ownedEdges,
                &v8->m_edgeMap,
                v33->m_startEdgeIndex);
        v40 = getRemappedIndex(v39->m_a, &vertexRemap, v8, &geom->m_vertices);
        v41 = v33->m_numEdges;
        v42 = 0;
        LODWORD(v102) = v40;
        if ( v41 > 0 )
        {
          v43 = (int *)(v38 + 8);
          v44 = &v8->m_ownedEdges;
          do
          {
            v45 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__22(
                    v8->m_originalEdges,
                    v8->m_numOriginalEdges,
                    &v8->m_instancedEdges,
                    v44,
                    &v8->m_edgeMap,
                    v42 + v33->m_startEdgeIndex);
            v48 = v45;
            if ( v42 > 0 && v42 < v41 - 1 )
            {
              v49 = getRemappedIndex(v45->m_a, &vertexRemap, v8, &geom->m_vertices);
              v50 = getRemappedIndex(v48->m_b, &vertexRemap, v8, &geom->m_vertices);
              v51 = (signed int)v102;
              *(v43 - 1) = v49;
              *(v43 - 2) = v51;
              *v43 = v50;
              v43 += 4;
              v47 = &v8->m_ownedEdges;
              v46 = &v8->m_instancedEdges;
            }
            v52 = v48->m_oppositeEdge;
            if ( v52 == -1
              || v48->m_flags.m_storage & 0x40
              || (signed int)v7 < (signed int)(v48->m_oppositeFace & 0x3FFFFF)
              || (((v53 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__22(
                            v8->m_originalEdges,
                            v8->m_numOriginalEdges,
                            v46,
                            v47,
                            &v8->m_edgeMap,
                            v52 & 0x3FFFFF),
                    v48->m_a != v53->m_a)
                || v48->m_b != v53->m_b)
               && (v48->m_a != v53->m_b || v48->m_b != v53->m_a) ? (v54 = 0) : (v54 = 1),
                  !v54) )
            {
              v55 = v48->m_a;
              v56 = v8->m_numOriginalVertices;
              if ( (signed int)v55 >= v56 )
                v57 = (__int128 *)&v8->m_ownedVertices.m_data[(signed int)v55 - v56];
              else
                v57 = (__int128 *)&v8->m_originalVertices[v55];
              v58 = *v57;
              v59 = v48->m_b;
              if ( (signed int)v59 >= v56 )
                v60 = (__int128 *)&v8->m_ownedVertices.m_data[(signed int)v59 - v56];
              else
                v60 = (__int128 *)&v8->m_originalVertices[v59];
              v61 = *v60;
              if ( v52 == -1 )
              {
                v62 = v102;
              }
              else
              {
                v63 = v48->m_flags.m_storage;
                if ( v63 & 0x40 )
                {
                  v62 = v100;
                }
                else
                {
                  v62 = v103;
                  if ( v63 & 2 )
                    v62 = v97;
                }
              }
              if ( v62[30] == (v62[31] & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v62 + 28, 16);
              *(_OWORD *)(*((_QWORD *)v62 + 14) + 16i64 * (signed int)v62[30]++) = v58;
              if ( v62[30] == (v62[31] & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v62 + 28, 16);
              v44 = &v8->m_ownedEdges;
              *(_OWORD *)(*((_QWORD *)v62 + 14) + 16i64 * (signed int)v62[30]++) = v61;
            }
            v41 = v33->m_numEdges;
            ++v42;
          }
          while ( v42 < v41 );
        }
        v29 = v96;
      }
      ++v29;
      LODWORD(v7) = v7 + 1;
      v96 = v29;
      if ( (signed int)v7 >= SHIDWORD(v102) )
        break;
      v16 = (signed int *)geom;
    }
  }
  v64 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v65 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v64[11] + 8i64))(v64[11], 112i64);
  if ( v65 )
  {
    hkDisplayConvex::hkDisplayConvex(v65, geom);
    v67 = v66;
  }
  else
  {
    v67 = 0i64;
  }
  v106 = -2147483647;
  v107 = v67;
  aTb.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  aTb.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v104 = (__int64 *)&v107;
  v68 = (hkVector4f *)*((_QWORD *)retaddr + 9);
  v105 = 1;
  aTb.m_translation = 0i64;
  aTb.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  aTb.m_translation = (hkVector4f)v68[14].m_quad;
  hkTransformf::setMul(&v117, &aTb, &v8->m_referenceFrame.m_transform);
  v69 = retaddr + 16;
  v70 = **((_QWORD **)retaddr + 6);
  v71 = (*(__int64 (__fastcall **)(char *))(*((_QWORD *)retaddr + 2) + 8i64))(retaddr + 16);
  v72 = *(_QWORD *)&numFaces;
  LODWORD(index) = v71;
  (*(void (__fastcall **)(_QWORD, int *, __int64 **, hkTransformf *, _QWORD, __int64, _QWORD, _DWORD))(v70 + 8))(
    *((_QWORD *)retaddr + 6),
    &v121,
    &v104,
    &v117,
    *(_QWORD *)&numFaces,
    index,
    0i64,
    0);
  v73 = **((_QWORD **)retaddr + 6);
  LODWORD(v70) = *((_DWORD *)retaddr + 44);
  LODWORD(ST20_8_68) = (*(__int64 (__fastcall **)(char *))(*((_QWORD *)retaddr + 2) + 8i64))(retaddr + 16);
  (*(void (__fastcall **)(_QWORD, int *, __int64, __int64, hkArray<int,hkContainerHeapAllocator> *))(v73 + 48))(
    *((_QWORD *)retaddr + 6),
    &v121,
    v70 & 0xFFFFFF | ((unsigned int)v70 >> 1) & 0x7F000000,
    v72,
    ST20_8_68);
  hkReferencedObject::removeReference(v67);
  v75 = *((_DWORD *)retaddr + 46);
  v76 = *((_DWORD *)retaddr + 44);
  v112 = v103;
  v113 = v102;
  v77 = (hkReferencedObject **)&v112;
  v114 = v100;
  v78 = (__int64)v97;
  LODWORD(v97) = v75;
  v115 = v78;
  v79 = (__int64 *)&v97;
  HIDWORD(v97) = *((_DWORD *)retaddr + 45);
  v98 = *((_DWORD *)retaddr + 47);
  v80 = v72 + 1;
  v99 = ((v76 & v75) + (((v76 ^ v75) >> 1) & 0x7F7F7F)) | 0xFF000000;
  v81 = 4i64;
  do
  {
    v82 = *v77;
    v108 = (__int64 *)&v111;
    v83 = (__int64 *)*((_QWORD *)retaddr + 6);
    v110 = -2147483647;
    v111 = v82;
    v109 = 1;
    v84 = *v83;
    LODWORD(v94) = 0;
    LODWORD(indexa) = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v69 + 8i64))(v69);
    (*(void (__fastcall **)(_QWORD, int *, __int64 **, hkTransformf *, signed __int64, __int64, _QWORD, __int64))(v84 + 8))(
      *((_QWORD *)retaddr + 6),
      &v121,
      &v108,
      &v117,
      v80,
      indexa,
      0i64,
      v94);
    v85 = **((_QWORD **)retaddr + 6);
    LODWORD(ST20_8_69) = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v69 + 8i64))(v69);
    (*(void (__fastcall **)(_QWORD, __int64 *, _QWORD, signed __int64, hkArray<int,hkContainerHeapAllocator> *))(v85 + 48))(
      *((_QWORD *)retaddr + 6),
      &v120,
      *(unsigned int *)v79,
      v80,
      ST20_8_69);
    hkReferencedObject::removeReference(v82);
    v109 = 0;
    if ( v110 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v108,
        8 * v110);
    ++v80;
    v79 = (__int64 *)((char *)v79 + 4);
    ++v77;
    --v81;
  }
  while ( v81 );
  v105 = 0;
  if ( v106 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v104,
      8 * v106);
  v104 = 0i64;
  v106 = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&vertexRemap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&vertexRemap);
  v87 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v88 = (_QWORD *)v87[1];
  v89 = v87;
  if ( (unsigned __int64)v88 < v87[3] )
  {
    *v88 = "Et";
    v90 = __rdtsc();
    v91 = (signed __int64)(v88 + 2);
    *(_DWORD *)(v91 - 8) = v90;
    v89[1] = v91;
  }
}

// File Line: 470
// RVA: 0xC43A80
void __fastcall hkaiNavMeshGeometryViewer::removeGeometryForBlock(hkaiNavMeshGeometryViewer *this, unsigned __int64 baseId)
{
  unsigned __int64 v2; // rdi
  hkaiNavMeshGeometryViewer *v3; // rsi
  signed __int64 v4; // rbp
  hkDebugDisplayHandlerVtbl *v5; // rbx
  unsigned int v6; // eax
  char v7; // [rsp+60h] [rbp+18h]

  v2 = baseId;
  v3 = this;
  v4 = 5i64;
  do
  {
    v5 = v3->m_displayHandler->vfptr;
    v6 = v3->vfptr->getProcessTag((hkProcess *)&v3->vfptr);
    v5->removeGeometry(v3->m_displayHandler, (hkResult *)&v7, v2++, v6, 0i64);
    --v4;
  }
  while ( v4 );
}

// File Line: 478
// RVA: 0xC43B00
void __fastcall hkaiNavMeshGeometryViewer::updateGeometryForBlock(hkaiNavMeshGeometryViewer *this, unsigned __int64 baseId, hkTransformf *transform)
{
  hkTransformf *v3; // r15
  unsigned __int64 v4; // rdi
  hkaiNavMeshGeometryViewer *v5; // rsi
  signed __int64 v6; // rbp
  hkDebugDisplayHandlerVtbl *v7; // rbx
  __int64 v8[5]; // [rsp+20h] [rbp-28h]
  char v9; // [rsp+68h] [rbp+20h]

  v3 = transform;
  v4 = baseId;
  v5 = this;
  v6 = 5i64;
  do
  {
    v7 = v5->m_displayHandler->vfptr;
    LODWORD(v8[0]) = v5->vfptr->getProcessTag((hkProcess *)&v5->vfptr);
    v7->updateGeometry(v5->m_displayHandler, (hkResult *)&v9, v3, v4++, v8[0]);
    --v6;
  }
  while ( v6 );
}

// File Line: 488
// RVA: 0xC43B80
__int64 __fastcall hkaiNavMeshGeometryViewer::getFlagBlockCrc(hkaiNavMeshInstance *instance, int startFaceIndex, int numFaces)
{
  signed __int64 v3; // rdi
  unsigned int v4; // ebx
  signed __int64 v5; // r14
  hkaiNavMeshInstance *v6; // rbp
  int v7; // esi
  char *v8; // rax
  char v10; // [rsp+48h] [rbp+10h]
  char v11; // [rsp+50h] [rbp+18h]

  v3 = startFaceIndex;
  v4 = -1;
  v5 = startFaceIndex + numFaces;
  v6 = instance;
  if ( startFaceIndex < v5 )
  {
    v7 = instance->m_faceFlags.m_size;
    do
    {
      if ( v7 )
      {
        v8 = &v10;
        v10 = v6->m_faceFlags.m_data[v3].m_storage;
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
signed __int64 __fastcall hkaiNavMeshGeometryViewer::indexOfInstance(hkaiNavMeshGeometryViewer *this, hkaiNavMeshInstance *instance)
{
  __int64 v2; // r10
  unsigned int v3; // er9
  __int64 v4; // r8
  hkaiNavMeshGeometryViewer::NavMeshInfo *v5; // rax

  v2 = this->m_navMeshInfos.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
    return 0xFFFFFFFFi64;
  v5 = this->m_navMeshInfos.m_data;
  while ( instance != v5->m_navMeshInstance )
  {
    ++v4;
    ++v3;
    ++v5;
    if ( v4 >= v2 )
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
hkProcess *__fastcall hkaiNavMeshVertexNormalsViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiNavMeshVertexNormalsViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshVertexNormalsViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                           v2[11],
                                           656i64);
  if ( v3 && (hkaiNavMeshVertexNormalsViewer::hkaiNavMeshVertexNormalsViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 536
// RVA: 0xC43CF0
void __fastcall hkaiNavMeshVertexNormalsViewer::hkaiNavMeshVertexNormalsViewer(hkaiNavMeshVertexNormalsViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshVertexNormalsViewer *v2; // rbx

  v2 = this;
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer((hkaiNavMeshBaseViewer *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshVertexNormalsViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiNavMeshVertexNormalsViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshVertexNormalsViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshVertexNormalsViewer::`vftable';
  v2->m_settings.m_showVertexNormals.m_bool = 1;
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
hkProcess *__fastcall hkaiNavMeshEdgeNormalsViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiNavMeshEdgeNormalsViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshEdgeNormalsViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                         v2[11],
                                         656i64);
  if ( v3 && (hkaiNavMeshEdgeNormalsViewer::hkaiNavMeshEdgeNormalsViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 558
// RVA: 0xC43DD0
void __fastcall hkaiNavMeshEdgeNormalsViewer::hkaiNavMeshEdgeNormalsViewer(hkaiNavMeshEdgeNormalsViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshEdgeNormalsViewer *v2; // rbx

  v2 = this;
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer((hkaiNavMeshBaseViewer *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshEdgeNormalsViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiNavMeshEdgeNormalsViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshEdgeNormalsViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshEdgeNormalsViewer::`vftable';
  v2->m_settings.m_showEdgeNormals.m_bool = 1;
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
hkProcess *__fastcall hkaiNavMeshFaceNormalsViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiNavMeshFaceNormalsViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshFaceNormalsViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                         v2[11],
                                         656i64);
  if ( v3 && (hkaiNavMeshFaceNormalsViewer::hkaiNavMeshFaceNormalsViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 580
// RVA: 0xC43EB0
void __fastcall hkaiNavMeshFaceNormalsViewer::hkaiNavMeshFaceNormalsViewer(hkaiNavMeshFaceNormalsViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshFaceNormalsViewer *v2; // rbx

  v2 = this;
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer((hkaiNavMeshBaseViewer *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshFaceNormalsViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiNavMeshFaceNormalsViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshFaceNormalsViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshFaceNormalsViewer::`vftable';
  v2->m_settings.m_showNormals.m_bool = 1;
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
hkProcess *__fastcall hkaiNavMeshVertexLabelsViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiNavMeshVertexLabelsViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshVertexLabelsViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                          v2[11],
                                          656i64);
  if ( v3 && (hkaiNavMeshVertexLabelsViewer::hkaiNavMeshVertexLabelsViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 602
// RVA: 0xC43F90
void __fastcall hkaiNavMeshVertexLabelsViewer::hkaiNavMeshVertexLabelsViewer(hkaiNavMeshVertexLabelsViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshVertexLabelsViewer *v2; // rbx

  v2 = this;
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer((hkaiNavMeshBaseViewer *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshVertexLabelsViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiNavMeshVertexLabelsViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshVertexLabelsViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshVertexLabelsViewer::`vftable';
  v2->m_settings.m_labelVertices.m_bool = 1;
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
hkProcess *__fastcall hkaiNavMeshEdgeLabelsViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiNavMeshEdgeLabelsViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshEdgeLabelsViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                        v2[11],
                                        656i64);
  if ( v3 && (hkaiNavMeshEdgeLabelsViewer::hkaiNavMeshEdgeLabelsViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 624
// RVA: 0xC44070
void __fastcall hkaiNavMeshEdgeLabelsViewer::hkaiNavMeshEdgeLabelsViewer(hkaiNavMeshEdgeLabelsViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshEdgeLabelsViewer *v2; // rbx

  v2 = this;
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer((hkaiNavMeshBaseViewer *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshEdgeLabelsViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiNavMeshEdgeLabelsViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshEdgeLabelsViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshEdgeLabelsViewer::`vftable';
  v2->m_settings.m_labelEdges.m_bool = 1;
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
hkProcess *__fastcall hkaiNavMeshFaceLabelsViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiNavMeshFaceLabelsViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavMeshFaceLabelsViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                        v2[11],
                                        656i64);
  if ( v3 && (hkaiNavMeshFaceLabelsViewer::hkaiNavMeshFaceLabelsViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 646
// RVA: 0xC44150
void __fastcall hkaiNavMeshFaceLabelsViewer::hkaiNavMeshFaceLabelsViewer(hkaiNavMeshFaceLabelsViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavMeshFaceLabelsViewer *v2; // rbx

  v2 = this;
  hkaiNavMeshBaseViewer::hkaiNavMeshBaseViewer((hkaiNavMeshBaseViewer *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshFaceLabelsViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiNavMeshFaceLabelsViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavMeshFaceLabelsViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavMeshFaceLabelsViewer::`vftable';
  v2->m_settings.m_labelFaces.m_bool = 1;
}

