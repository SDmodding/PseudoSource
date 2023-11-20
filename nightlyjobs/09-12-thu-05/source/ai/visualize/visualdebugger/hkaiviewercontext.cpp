// File Line: 22
// RVA: 0xC3FD70
void hkaiViewerContext::registerDefaultAiProcesses(void)
{
  hkaiCharacterViewer::registerViewer();
  hkaiSensorViewer::registerViewer();
  hkaiNavVolumeViewer::registerViewer();
  hkaiNavMeshGeometryViewer::registerViewer();
  hkaiPathRequestViewer::registerViewer();
  hkaiSilhouetteReplayViewer::registerViewer();
  hkaiTraversalAnnotationViewer::registerViewer();
}

// File Line: 33
// RVA: 0xC3FDB0
void hkaiViewerContext::registerExtraAiProcesses(void)
{
  hkaiNavMeshVertexNormalsViewer::registerViewer();
  hkaiNavMeshEdgeNormalsViewer::registerViewer();
  hkaiNavMeshFaceNormalsViewer::registerViewer();
  hkaiNavMeshVertexLabelsViewer::registerViewer();
  hkaiNavMeshEdgeLabelsViewer::registerViewer();
  hkaiNavMeshFaceLabelsViewer::registerViewer();
}

// File Line: 44
// RVA: 0xC3FB00
void __fastcall hkaiViewerContext::hkaiViewerContext(hkaiViewerContext *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_owner = 0i64;
  this->m_monitorStreamBegins.m_data = this->m_monitorStreamBegins.m_storage;
  this->m_monitorStreamBegins.m_size = 0;
  this->m_monitorStreamBegins.m_capacityAndFlags = -2147483642;
  this->m_monitorStreamEnds.m_size = 0;
  this->m_monitorStreamEnds.m_capacityAndFlags = -2147483642;
  this->m_monitorStreamEnds.m_data = this->m_monitorStreamEnds.m_storage;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiViewerContext::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessContextVtbl *)&hkaiViewerContext::`vftable'{for `hkProcessContext'};
  this->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiViewerContext::`vftable'{for `hkaiWorld::Listener'};
  this->m_worlds.m_data = 0i64;
  this->m_worlds.m_size = 0;
  this->m_worlds.m_capacityAndFlags = 2147483648;
  this->m_traversalAnnotationLibraries.m_data = 0i64;
  this->m_traversalAnnotationLibraries.m_size = 0;
  this->m_traversalAnnotationLibraries.m_capacityAndFlags = 2147483648;
  this->m_listeners.m_data = 0i64;
  this->m_listeners.m_size = 0;
  this->m_listeners.m_capacityAndFlags = 2147483648;
  this->m_displayOffset = (hkVector4f)aabbOut.m_quad;
}

// File Line: 48
// RVA: 0xC3FBC0
void __fastcall hkaiViewerContext::~hkaiViewerContext(hkaiViewerContext *this)
{
  bool v1; // zf
  hkaiViewerContext *v2; // rbx
  int v3; // er8
  hkRefPtr<hkaiTraversalAnnotationLibrary const > *v4; // rsi
  int v5; // eax
  __int64 i; // rdi
  hkReferencedObject *v7; // rcx
  int v8; // er8
  int v9; // er8

  v1 = this->m_worlds.m_size == 0;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiViewerContext::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessContextVtbl *)&hkaiViewerContext::`vftable'{for `hkProcessContext'};
  this->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiViewerContext::`vftable'{for `hkaiWorld::Listener'};
  if ( !v1 )
  {
    do
      hkaiViewerContext::removeWorld(v2, *v2->m_worlds.m_data);
    while ( v2->m_worlds.m_size );
  }
  v3 = v2->m_listeners.m_capacityAndFlags;
  v2->m_listeners.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_listeners.m_data,
      8 * v3);
  v2->m_listeners.m_data = 0i64;
  v2->m_listeners.m_capacityAndFlags = 2147483648;
  v4 = v2->m_traversalAnnotationLibraries.m_data;
  v5 = v2->m_traversalAnnotationLibraries.m_size - 1;
  for ( i = v5; i >= 0; v4[i--].m_pntr = 0i64 )
  {
    v7 = (hkReferencedObject *)&v4[i].m_pntr->vfptr;
    if ( v7 )
      hkReferencedObject::removeReference(v7);
  }
  v8 = v2->m_traversalAnnotationLibraries.m_capacityAndFlags;
  v2->m_traversalAnnotationLibraries.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_traversalAnnotationLibraries.m_data,
      8 * v8);
  v2->m_traversalAnnotationLibraries.m_data = 0i64;
  v2->m_traversalAnnotationLibraries.m_capacityAndFlags = 2147483648;
  v9 = v2->m_worlds.m_capacityAndFlags;
  v2->m_worlds.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_worlds.m_data,
      8 * v9);
  v2->m_worlds.m_data = 0i64;
  v2->m_worlds.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable';
  hkProcessContext::~hkProcessContext((hkProcessContext *)&v2->vfptr);
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 56
// RVA: 0xC3FDE0
void __fastcall hkaiViewerContext::addWorld(hkaiViewerContext *this, hkaiWorld *newWorld)
{
  int v2; // edi
  hkArray<hkaiWorld *,hkContainerHeapAllocator> *v3; // rbx
  hkaiViewerContext *v4; // rbp
  __int64 v5; // rcx
  hkaiWorld *v6; // rsi
  int v7; // er9
  __int64 v8; // r8
  hkaiWorld **v9; // rax
  hkaiWorld::Listener *v10; // rdx
  __int64 v11; // r14

  v2 = 0;
  v3 = &this->m_worlds;
  v4 = this;
  v5 = this->m_worlds.m_size;
  v6 = newWorld;
  v7 = 0;
  v8 = 0i64;
  if ( v5 <= 0 )
    goto LABEL_7;
  v9 = v3->m_data;
  while ( *v9 != newWorld )
  {
    ++v8;
    ++v7;
    ++v9;
    if ( v8 >= v5 )
      goto LABEL_7;
  }
  if ( v7 < 0 )
  {
LABEL_7:
    v10 = (hkaiWorld::Listener *)&v4->vfptr;
    if ( !v4 )
      v10 = 0i64;
    hkaiWorld::addListener(v6, v10);
    if ( v4->m_listeners.m_size > 0 )
    {
      v11 = 0i64;
      do
      {
        v4->m_listeners.m_data[v11]->vfptr->worldAddedCallback(v4->m_listeners.m_data[v11], v6);
        ++v2;
        ++v11;
      }
      while ( v2 < v4->m_listeners.m_size );
    }
    hkReferencedObject::addReference((hkReferencedObject *)&v6->vfptr);
    if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 8);
    v3->m_data[v3->m_size++] = v6;
  }
}

// File Line: 75
// RVA: 0xC3FEE0
void __fastcall hkaiViewerContext::removeWorld(hkaiViewerContext *this, hkaiWorld *oldWorld)
{
  int v2; // esi
  hkaiViewerContext *v3; // rbx
  hkaiWorld *v4; // rbp
  __int64 v5; // rdx
  int v6; // edi
  __int64 v7; // rcx
  hkaiWorld **v8; // rax
  __int64 v9; // r14
  signed __int64 v10; // rsi
  __int64 v11; // rax

  v2 = 0;
  v3 = this;
  v4 = oldWorld;
  v5 = this->m_worlds.m_size;
  v6 = 0;
  v7 = 0i64;
  if ( v5 > 0 )
  {
    v8 = v3->m_worlds.m_data;
    while ( *v8 != v4 )
    {
      ++v7;
      ++v6;
      ++v8;
      if ( v7 >= v5 )
        return;
    }
    if ( v6 >= 0 )
    {
      hkaiWorld::removeListener(v4, (hkaiWorld::Listener *)&v3->vfptr);
      if ( v3->m_listeners.m_size > 0 )
      {
        v9 = 0i64;
        do
        {
          v3->m_listeners.m_data[v9]->vfptr->worldRemovedCallback(v3->m_listeners.m_data[v9], v4);
          ++v2;
          ++v9;
        }
        while ( v2 < v3->m_listeners.m_size );
      }
      v10 = v6;
      hkReferencedObject::removeReference((hkReferencedObject *)&v3->m_worlds.m_data[v10]->vfptr);
      v11 = --v3->m_worlds.m_size;
      if ( (_DWORD)v11 != v6 )
        v3->m_worlds.m_data[v10] = v3->m_worlds.m_data[v11];
    }
  }
}

// File Line: 95
// RVA: 0xC3FFE0
void __fastcall hkaiViewerContext::addTraversalAnnotationLibrary(hkaiViewerContext *this, hkaiTraversalAnnotationLibrary *library)
{
  hkaiTraversalAnnotationLibrary *v2; // rbx
  hkaiViewerContext *v3; // rbp
  int v4; // esi
  hkArray<hkRefPtr<hkaiTraversalAnnotationLibrary const >,hkContainerHeapAllocator> *v5; // rdi
  __int64 v6; // rcx
  signed int v7; // er8
  __int64 v8; // rdx
  hkaiTraversalAnnotationLibrary **v9; // rax
  bool v10; // r14
  __int64 v11; // r14
  hkaiTraversalAnnotationLibrary **v12; // rsi

  v2 = library;
  v3 = this;
  if ( library )
    hkReferencedObject::addReference((hkReferencedObject *)&library->vfptr);
  v4 = 0;
  v5 = &v3->m_traversalAnnotationLibraries;
  v6 = v3->m_traversalAnnotationLibraries.m_size;
  v7 = 0;
  v8 = 0i64;
  if ( v6 <= 0 )
  {
LABEL_7:
    v7 = -1;
  }
  else
  {
    v9 = &v5->m_data->m_pntr;
    while ( *v9 != v2 )
    {
      ++v8;
      ++v7;
      ++v9;
      if ( v8 >= v6 )
        goto LABEL_7;
    }
  }
  v10 = v7 < 0;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  if ( v10 )
  {
    if ( v3->m_listeners.m_size > 0 )
    {
      v11 = 0i64;
      do
      {
        v3->m_listeners.m_data[v11]->vfptr->traversalAnnotationLibraryAddedCallback(v3->m_listeners.m_data[v11], v2);
        ++v4;
        ++v11;
      }
      while ( v4 < v3->m_listeners.m_size );
    }
    if ( v2 )
      hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
    if ( v3->m_traversalAnnotationLibraries.m_size == (v3->m_traversalAnnotationLibraries.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_traversalAnnotationLibraries,
        8);
    v12 = &v5->m_data[v3->m_traversalAnnotationLibraries.m_size].m_pntr;
    if ( v12 )
    {
      if ( v2 )
        hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
      *v12 = v2;
    }
    ++v3->m_traversalAnnotationLibraries.m_size;
    if ( v2 )
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  }
}

// File Line: 111
// RVA: 0xC40120
void __fastcall hkaiViewerContext::removeTraversalAnnotationLibrary(hkaiViewerContext *this, hkaiTraversalAnnotationLibrary *library)
{
  hkaiTraversalAnnotationLibrary *v2; // rsi
  hkaiViewerContext *v3; // rbx
  __int64 v4; // rcx
  signed int v5; // edi
  __int64 v6; // rdx
  hkRefPtr<hkaiTraversalAnnotationLibrary const > *v7; // rax
  int v8; // ebp
  __int64 v9; // r14
  hkRefPtr<hkaiTraversalAnnotationLibrary const > *v10; // rsi
  hkReferencedObject *v11; // rcx
  signed __int64 v12; // r14
  __int64 v13; // rax

  v2 = library;
  v3 = this;
  if ( library )
    hkReferencedObject::addReference((hkReferencedObject *)&library->vfptr);
  v4 = v3->m_traversalAnnotationLibraries.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( v4 <= 0 )
  {
LABEL_7:
    v5 = -1;
  }
  else
  {
    v7 = v3->m_traversalAnnotationLibraries.m_data;
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
    v8 = 0;
    if ( v3->m_listeners.m_size > 0 )
    {
      v9 = 0i64;
      do
      {
        v3->m_listeners.m_data[v9]->vfptr->traversalAnnotationLibraryRemovedCallback(v3->m_listeners.m_data[v9], v2);
        ++v8;
        ++v9;
      }
      while ( v8 < v3->m_listeners.m_size );
    }
    v10 = v3->m_traversalAnnotationLibraries.m_data;
    v11 = (hkReferencedObject *)&v10[v5].m_pntr->vfptr;
    v12 = v5;
    if ( v11 )
      hkReferencedObject::removeReference(v11);
    v10[v12].m_pntr = 0i64;
    v13 = --v3->m_traversalAnnotationLibraries.m_size;
    if ( (_DWORD)v13 != v5 )
      v3->m_traversalAnnotationLibraries.m_data[v12].m_pntr = v3->m_traversalAnnotationLibraries.m_data[v13].m_pntr;
  }
}

// File Line: 128
// RVA: 0xC40230
void __fastcall hkaiViewerContext::addWorldAddedListener(hkaiViewerContext *this, hkaiViewerContextWorldListener *cb)
{
  hkArray<hkaiViewerContextWorldListener *,hkContainerHeapAllocator> *v2; // rbx
  int v3; // er8
  hkaiViewerContextWorldListener *v4; // rdi
  __int64 v5; // r9
  __int64 v6; // rcx
  hkaiViewerContextWorldListener **v7; // rax

  v2 = &this->m_listeners;
  v3 = 0;
  v4 = cb;
  v5 = this->m_listeners.m_size;
  v6 = 0i64;
  if ( (signed int)v5 <= 0 )
    goto LABEL_7;
  v7 = v2->m_data;
  while ( *v7 != cb )
  {
    ++v6;
    ++v3;
    ++v7;
    if ( v6 >= v5 )
      goto LABEL_7;
  }
  if ( v3 < 0 )
  {
LABEL_7:
    if ( (_DWORD)v5 == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
    v2->m_data[v2->m_size++] = v4;
  }
}

// File Line: 137
// RVA: 0xC402C0
void __fastcall hkaiViewerContext::removeWorldAddedListener(hkaiViewerContext *this, hkaiViewerContextWorldListener *cb)
{
  __int64 v2; // r11
  int v3; // er8
  __int64 v4; // r9
  hkaiViewerContextWorldListener **v5; // rax

  v2 = this->m_listeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (signed int)v2 > 0 )
  {
    v5 = this->m_listeners.m_data;
    while ( *v5 != cb )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        return;
    }
    if ( v3 >= 0 )
    {
      this->m_listeners.m_size = v2 - 1;
      if ( (_DWORD)v2 - 1 != v3 )
        this->m_listeners.m_data[v3] = this->m_listeners.m_data[(signed int)v2 - 1];
    }
  }
}

// File Line: 146
// RVA: 0xC40330
void __fastcall hkaiViewerContext::worldDeletedCallback(hkaiViewerContext *this, hkaiWorld *world)
{
  hkaiViewerContext::removeWorld((hkaiViewerContext *)((char *)this - 160), world);
}

