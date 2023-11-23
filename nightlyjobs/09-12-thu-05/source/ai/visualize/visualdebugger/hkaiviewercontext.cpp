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
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiViewerContext::`vftable{for `hkReferencedObject};
  this->hkProcessContext::vfptr = (hkProcessContextVtbl *)&hkaiViewerContext::`vftable{for `hkProcessContext};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiViewerContext::`vftable{for `hkaiWorld::Listener};
  this->m_worlds.m_data = 0i64;
  this->m_worlds.m_size = 0;
  this->m_worlds.m_capacityAndFlags = 0x80000000;
  this->m_traversalAnnotationLibraries.m_data = 0i64;
  this->m_traversalAnnotationLibraries.m_size = 0;
  this->m_traversalAnnotationLibraries.m_capacityAndFlags = 0x80000000;
  this->m_listeners.m_data = 0i64;
  this->m_listeners.m_size = 0;
  this->m_listeners.m_capacityAndFlags = 0x80000000;
  this->m_displayOffset = (hkVector4f)aabbOut.m_quad;
}

// File Line: 48
// RVA: 0xC3FBC0
void __fastcall hkaiViewerContext::~hkaiViewerContext(hkaiViewerContext *this)
{
  bool v1; // zf
  int m_capacityAndFlags; // r8d
  hkRefPtr<hkaiTraversalAnnotationLibrary const > *m_data; // rsi
  int v5; // eax
  __int64 i; // rdi
  hkReferencedObject *m_pntr; // rcx
  int v8; // r8d
  int v9; // r8d

  v1 = this->m_worlds.m_size == 0;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiViewerContext::`vftable{for `hkReferencedObject};
  this->hkProcessContext::vfptr = (hkProcessContextVtbl *)&hkaiViewerContext::`vftable{for `hkProcessContext};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiViewerContext::`vftable{for `hkaiWorld::Listener};
  if ( !v1 )
  {
    do
      hkaiViewerContext::removeWorld(this, *this->m_worlds.m_data);
    while ( this->m_worlds.m_size );
  }
  m_capacityAndFlags = this->m_listeners.m_capacityAndFlags;
  this->m_listeners.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_listeners.m_data,
      8 * m_capacityAndFlags);
  this->m_listeners.m_data = 0i64;
  this->m_listeners.m_capacityAndFlags = 0x80000000;
  m_data = this->m_traversalAnnotationLibraries.m_data;
  v5 = this->m_traversalAnnotationLibraries.m_size - 1;
  for ( i = v5; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  v8 = this->m_traversalAnnotationLibraries.m_capacityAndFlags;
  this->m_traversalAnnotationLibraries.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_traversalAnnotationLibraries.m_data,
      8 * v8);
  this->m_traversalAnnotationLibraries.m_data = 0i64;
  this->m_traversalAnnotationLibraries.m_capacityAndFlags = 0x80000000;
  v9 = this->m_worlds.m_capacityAndFlags;
  this->m_worlds.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_worlds.m_data, 8 * v9);
  this->m_worlds.m_data = 0i64;
  this->m_worlds.m_capacityAndFlags = 0x80000000;
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable;
  hkProcessContext::~hkProcessContext(&this->hkProcessContext);
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 56
// RVA: 0xC3FDE0
void __fastcall hkaiViewerContext::addWorld(hkaiViewerContext *this, hkaiWorld *newWorld)
{
  int v2; // edi
  hkArray<hkaiWorld *,hkContainerHeapAllocator> *p_m_worlds; // rbx
  __int64 m_size; // rcx
  int v7; // r9d
  __int64 v8; // r8
  hkaiWorld **m_data; // rax
  hkaiWorld::Listener *v10; // rdx
  __int64 v11; // r14

  v2 = 0;
  p_m_worlds = &this->m_worlds;
  m_size = this->m_worlds.m_size;
  v7 = 0;
  v8 = 0i64;
  if ( m_size <= 0 )
    goto LABEL_7;
  m_data = p_m_worlds->m_data;
  while ( *m_data != newWorld )
  {
    ++v8;
    ++v7;
    ++m_data;
    if ( v8 >= m_size )
      goto LABEL_7;
  }
  if ( v7 < 0 )
  {
LABEL_7:
    v10 = &this->hkaiWorld::Listener;
    if ( !this )
      v10 = 0i64;
    hkaiWorld::addListener(newWorld, v10);
    if ( this->m_listeners.m_size > 0 )
    {
      v11 = 0i64;
      do
      {
        this->m_listeners.m_data[v11]->vfptr->worldAddedCallback(this->m_listeners.m_data[v11], newWorld);
        ++v2;
        ++v11;
      }
      while ( v2 < this->m_listeners.m_size );
    }
    hkReferencedObject::addReference(newWorld);
    if ( p_m_worlds->m_size == (p_m_worlds->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_worlds, 8);
    p_m_worlds->m_data[p_m_worlds->m_size++] = newWorld;
  }
}

// File Line: 75
// RVA: 0xC3FEE0
void __fastcall hkaiViewerContext::removeWorld(hkaiViewerContext *this, hkaiWorld *oldWorld)
{
  int v2; // esi
  __int64 m_size; // rdx
  int v6; // edi
  __int64 v7; // rcx
  hkaiWorld **i; // rax
  __int64 v9; // r14
  __int64 v10; // rax

  v2 = 0;
  m_size = this->m_worlds.m_size;
  v6 = 0;
  v7 = 0i64;
  if ( m_size > 0 )
  {
    for ( i = this->m_worlds.m_data; *i != oldWorld; ++i )
    {
      ++v7;
      ++v6;
      if ( v7 >= m_size )
        return;
    }
    if ( v6 >= 0 )
    {
      hkaiWorld::removeListener(oldWorld, &this->hkaiWorld::Listener);
      if ( this->m_listeners.m_size > 0 )
      {
        v9 = 0i64;
        do
        {
          this->m_listeners.m_data[v9]->vfptr->worldRemovedCallback(this->m_listeners.m_data[v9], oldWorld);
          ++v2;
          ++v9;
        }
        while ( v2 < this->m_listeners.m_size );
      }
      hkReferencedObject::removeReference(this->m_worlds.m_data[v6]);
      v10 = --this->m_worlds.m_size;
      if ( (_DWORD)v10 != v6 )
        this->m_worlds.m_data[v6] = this->m_worlds.m_data[v10];
    }
  }
}

// File Line: 95
// RVA: 0xC3FFE0
void __fastcall hkaiViewerContext::addTraversalAnnotationLibrary(
        hkaiViewerContext *this,
        hkaiTraversalAnnotationLibrary *library)
{
  int v4; // esi
  hkArray<hkRefPtr<hkaiTraversalAnnotationLibrary const >,hkContainerHeapAllocator> *p_m_traversalAnnotationLibraries; // rdi
  __int64 m_size; // rcx
  int v7; // r8d
  __int64 v8; // rdx
  hkaiTraversalAnnotationLibrary **p_m_pntr; // rax
  bool v10; // r14
  __int64 v11; // r14
  hkRefPtr<hkaiTraversalAnnotationLibrary const > *v12; // rsi

  if ( library )
    hkReferencedObject::addReference(library);
  v4 = 0;
  p_m_traversalAnnotationLibraries = &this->m_traversalAnnotationLibraries;
  m_size = this->m_traversalAnnotationLibraries.m_size;
  v7 = 0;
  v8 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_7:
    v7 = -1;
  }
  else
  {
    p_m_pntr = &p_m_traversalAnnotationLibraries->m_data->m_pntr;
    while ( *p_m_pntr != library )
    {
      ++v8;
      ++v7;
      ++p_m_pntr;
      if ( v8 >= m_size )
        goto LABEL_7;
    }
  }
  v10 = v7 < 0;
  if ( library )
    hkReferencedObject::removeReference(library);
  if ( v10 )
  {
    if ( this->m_listeners.m_size > 0 )
    {
      v11 = 0i64;
      do
      {
        this->m_listeners.m_data[v11]->vfptr->traversalAnnotationLibraryAddedCallback(
          this->m_listeners.m_data[v11],
          library);
        ++v4;
        ++v11;
      }
      while ( v4 < this->m_listeners.m_size );
    }
    if ( library )
      hkReferencedObject::addReference(library);
    if ( this->m_traversalAnnotationLibraries.m_size == (this->m_traversalAnnotationLibraries.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_traversalAnnotationLibraries, 8);
    v12 = &p_m_traversalAnnotationLibraries->m_data[this->m_traversalAnnotationLibraries.m_size];
    if ( v12 )
    {
      if ( library )
        hkReferencedObject::addReference(library);
      v12->m_pntr = library;
    }
    ++this->m_traversalAnnotationLibraries.m_size;
    if ( library )
      hkReferencedObject::removeReference(library);
  }
}

// File Line: 111
// RVA: 0xC40120
void __fastcall hkaiViewerContext::removeTraversalAnnotationLibrary(
        hkaiViewerContext *this,
        hkaiTraversalAnnotationLibrary *library)
{
  __int64 m_size; // rcx
  int v5; // edi
  __int64 v6; // rdx
  hkRefPtr<hkaiTraversalAnnotationLibrary const > *m_data; // rax
  int v8; // ebp
  __int64 v9; // r14
  hkRefPtr<hkaiTraversalAnnotationLibrary const > *v10; // rsi
  hkReferencedObject *m_pntr; // rcx
  __int64 v12; // rax

  if ( library )
    hkReferencedObject::addReference(library);
  m_size = this->m_traversalAnnotationLibraries.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_7:
    v5 = -1;
  }
  else
  {
    m_data = this->m_traversalAnnotationLibraries.m_data;
    while ( m_data->m_pntr != library )
    {
      ++v6;
      ++v5;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_7;
    }
  }
  if ( library )
    hkReferencedObject::removeReference(library);
  if ( v5 >= 0 )
  {
    v8 = 0;
    if ( this->m_listeners.m_size > 0 )
    {
      v9 = 0i64;
      do
      {
        this->m_listeners.m_data[v9]->vfptr->traversalAnnotationLibraryRemovedCallback(
          this->m_listeners.m_data[v9],
          library);
        ++v8;
        ++v9;
      }
      while ( v8 < this->m_listeners.m_size );
    }
    v10 = this->m_traversalAnnotationLibraries.m_data;
    m_pntr = v10[v5].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
    v10[v5].m_pntr = 0i64;
    v12 = --this->m_traversalAnnotationLibraries.m_size;
    if ( (_DWORD)v12 != v5 )
      this->m_traversalAnnotationLibraries.m_data[v5].m_pntr = this->m_traversalAnnotationLibraries.m_data[v12].m_pntr;
  }
}

// File Line: 128
// RVA: 0xC40230
void __fastcall hkaiViewerContext::addWorldAddedListener(hkaiViewerContext *this, hkaiViewerContextWorldListener *cb)
{
  hkArray<hkaiViewerContextWorldListener *,hkContainerHeapAllocator> *p_m_listeners; // rbx
  int v3; // r8d
  __int64 m_size; // r9
  __int64 v6; // rcx
  hkaiViewerContextWorldListener **m_data; // rax

  p_m_listeners = &this->m_listeners;
  v3 = 0;
  m_size = this->m_listeners.m_size;
  v6 = 0i64;
  if ( (int)m_size <= 0 )
    goto LABEL_7;
  m_data = p_m_listeners->m_data;
  while ( *m_data != cb )
  {
    ++v6;
    ++v3;
    ++m_data;
    if ( v6 >= m_size )
      goto LABEL_7;
  }
  if ( v3 < 0 )
  {
LABEL_7:
    if ( (_DWORD)m_size == (p_m_listeners->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_listeners, 8);
    p_m_listeners->m_data[p_m_listeners->m_size++] = cb;
  }
}

// File Line: 137
// RVA: 0xC402C0
void __fastcall hkaiViewerContext::removeWorldAddedListener(
        hkaiViewerContext *this,
        hkaiViewerContextWorldListener *cb)
{
  __int64 m_size; // r11
  int v3; // r8d
  __int64 v4; // r9
  hkaiViewerContextWorldListener **i; // rax

  m_size = this->m_listeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (int)m_size > 0 )
  {
    for ( i = this->m_listeners.m_data; *i != cb; ++i )
    {
      ++v4;
      ++v3;
      if ( v4 >= m_size )
        return;
    }
    if ( v3 >= 0 )
    {
      this->m_listeners.m_size = m_size - 1;
      if ( (_DWORD)m_size - 1 != v3 )
        this->m_listeners.m_data[v3] = this->m_listeners.m_data[(int)m_size - 1];
    }
  }
}

// File Line: 146
// RVA: 0xC40330
void __fastcall hkaiViewerContext::worldDeletedCallback(hkaiViewerContext *this, hkaiWorld *world)
{
  hkaiViewerContext::removeWorld((hkaiViewerContext *)((char *)this - 160), world);
}

