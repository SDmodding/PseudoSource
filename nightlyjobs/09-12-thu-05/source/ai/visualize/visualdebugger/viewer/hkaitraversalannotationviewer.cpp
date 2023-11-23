// File Line: 22
// RVA: 0xC45590
void hkaiTraversalAnnotationViewer::registerViewer(void)
{
  hkaiTraversalAnnotationViewer::m_tag = hkProcessFactory::registerProcess(
                                           hkSingleton<hkProcessFactory>::s_instance,
                                           "AI - Traversal Annotations",
                                           hkaiTraversalAnnotationViewer::create);
}

// File Line: 27
// RVA: 0xC455C0
hkProcess *__fastcall hkaiTraversalAnnotationViewer::create(
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkaiTraversalAnnotationViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiTraversalAnnotationViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                          Value[11],
                                          88i64);
  if ( v3 && (hkaiTraversalAnnotationViewer::hkaiTraversalAnnotationViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 33
// RVA: 0xC45760
void __fastcall hkaiTraversalAnnotationViewer::hkaiTraversalAnnotationViewer(
        hkaiTraversalAnnotationViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiViewerBase::hkaiViewerBase(this, contexts);
  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiTraversalAnnotationViewer::`vftable{for `hkReferencedObject};
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiTraversalAnnotationViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiTraversalAnnotationViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiTraversalAnnotationViewer::`vftable;
}

// File Line: 38
// RVA: 0xC45620
void __fastcall hkaiTraversalAnnotationViewer::init(hkaiTraversalAnnotationViewer *this)
{
  hkProcessHandler *m_processHandler; // rdx
  int v2; // ebx
  int v4; // esi
  __int64 v5; // rbp
  hkProcessHandler *v6; // rdx
  __int64 v7; // rsi

  m_processHandler = this->m_processHandler;
  v2 = 0;
  v4 = 0;
  if ( m_processHandler )
  {
    v5 = 0i64;
    do
    {
      if ( v4 >= SLODWORD(m_processHandler[22].vfptr) )
        break;
      ((void (__fastcall *)(hkDebugDisplayHandler **, _QWORD))this->m_displayHandler[1].vfptr)(
        &this->m_displayHandler,
        *(void *(__fastcall **)(hkProcessHandler *, unsigned int))((char *)&m_processHandler[21].vfptr->__vecDelDtor + v5));
      m_processHandler = this->m_processHandler;
      ++v4;
      v5 += 8i64;
    }
    while ( m_processHandler );
  }
  v6 = this->m_processHandler;
  if ( v6 )
  {
    v7 = 0i64;
    do
    {
      if ( v2 >= SLODWORD(v6[24].vfptr) )
        break;
      ((void (__fastcall *)(hkDebugDisplayHandler **, _QWORD))this->m_displayHandler[3].vfptr)(
        &this->m_displayHandler,
        *(void *(__fastcall **)(hkProcessHandler *, unsigned int))((char *)&v6[23].vfptr->__vecDelDtor + v7));
      v6 = this->m_processHandler;
      ++v2;
      v7 += 8i64;
    }
    while ( v6 );
  }
}

// File Line: 51
// RVA: 0xC457B0
void __fastcall hkaiTraversalAnnotationViewer::~hkaiTraversalAnnotationViewer(hkaiTraversalAnnotationViewer *this)
{
  int v1; // edi
  int v3; // esi
  __int64 v4; // rbp
  hkaiViewerContext *m_pntr; // rdx
  __int64 v6; // rsi
  hkaiViewerContext *v7; // rdx

  v1 = 0;
  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiTraversalAnnotationViewer::`vftable{for `hkReferencedObject};
  v3 = 0;
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiTraversalAnnotationViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiTraversalAnnotationViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiTraversalAnnotationViewer::`vftable;
  if ( this->m_context.m_pntr )
  {
    v4 = 0i64;
    do
    {
      m_pntr = this->m_context.m_pntr;
      if ( v3 >= m_pntr->m_worlds.m_size )
        break;
      hkaiTraversalAnnotationViewer::worldRemovedCallback(
        (hkaiTraversalAnnotationViewer *)&this->hkaiViewerContextWorldListener,
        m_pntr->m_worlds.m_data[v4]);
      ++v3;
      ++v4;
    }
    while ( this->m_context.m_pntr );
  }
  if ( this->m_context.m_pntr )
  {
    v6 = 0i64;
    do
    {
      v7 = this->m_context.m_pntr;
      if ( v1 >= v7->m_traversalAnnotationLibraries.m_size )
        break;
      hkaiTraversalAnnotationViewer::traversalAnnotationLibraryRemovedCallback(
        (hkaiTraversalAnnotationViewer *)&this->hkaiViewerContextWorldListener,
        v7->m_traversalAnnotationLibraries.m_data[v6].m_pntr);
      ++v1;
      ++v6;
    }
    while ( this->m_context.m_pntr );
  }
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable;
  hkaiViewerBase::~hkaiViewerBase(this);
}

// File Line: 64
// RVA: 0xC456E0
void __fastcall hkaiTraversalAnnotationViewer::worldAddedCallback(hkaiTraversalAnnotationViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiTraversalAnnotationViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 69
// RVA: 0xC45710
void __fastcall hkaiTraversalAnnotationViewer::worldRemovedCallback(hkaiTraversalAnnotationViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiTraversalAnnotationViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 74
// RVA: 0xC456D0
void __fastcall hkaiTraversalAnnotationViewer::postStepCallback(
        hkaiTraversalAnnotationViewer *this,
        hkaiWorld *world,
        hkArrayBase<hkaiBehavior *> *behaviors)
{
  ;
}

// File Line: 79
// RVA: 0xC45740
void __fastcall hkaiTraversalAnnotationViewer::traversalAnnotationLibraryAddedCallback(
        hkaiTraversalAnnotationViewer *this,
        hkaiTraversalAnnotationLibrary *library)
{
  hkaiTraversalAnnotationViewer::addLibraryGeometry((hkaiTraversalAnnotationViewer *)((char *)this - 64), library);
}

// File Line: 84
// RVA: 0xC45750
void __fastcall hkaiTraversalAnnotationViewer::traversalAnnotationLibraryRemovedCallback(
        hkaiTraversalAnnotationViewer *this,
        hkaiTraversalAnnotationLibrary *library)
{
  hkaiTraversalAnnotationViewer::removeLibraryGeometry((hkaiTraversalAnnotationViewer *)((char *)this - 64), library);
}

// File Line: 89
// RVA: 0xC458A0
void __fastcall hkaiTraversalAnnotationViewer::addLibraryGeometry(
        hkaiTraversalAnnotationViewer *this,
        hkaiTraversalAnnotationLibrary *library)
{
  signed int v4; // ebx
  int NumAnnotations; // esi

  v4 = 0;
  NumAnnotations = hkaiTraversalAnnotationLibrary::getNumAnnotations(library);
  if ( NumAnnotations > 0 )
  {
    do
      hkaiTraversalAnnotationViewer::addAnnotationGeometry(this, library, v4++);
    while ( v4 < NumAnnotations );
  }
}

// File Line: 97
// RVA: 0xC45900
void __fastcall hkaiTraversalAnnotationViewer::removeLibraryGeometry(
        hkaiTraversalAnnotationViewer *this,
        hkaiTraversalAnnotationLibrary *library)
{
  int NumAnnotations; // eax
  __int64 v4; // rdi
  unsigned __int64 v5; // rbx
  char v6; // [rsp+50h] [rbp+18h] BYREF

  NumAnnotations = hkaiTraversalAnnotationLibrary::getNumAnnotations(library);
  if ( NumAnnotations > 0 )
  {
    v4 = (unsigned int)NumAnnotations;
    v5 = 0i64;
    do
    {
      this->m_displayHandler->hkaiViewerBase::hkProcess::vfptr->removeGeometry(
        this->m_displayHandler,
        (hkResult *)&v6,
        v5++,
        hkaiTraversalAnnotationViewer::m_tag,
        0i64);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 105
// RVA: 0xC45980
void __fastcall hkaiTraversalAnnotationViewer::addAnnotationGeometry(
        hkaiTraversalAnnotationViewer *this,
        hkaiTraversalAnnotationLibrary *library,
        unsigned int index)
{
  int TraversalType; // eax
  int v7; // eax
  int v8; // eax

  TraversalType = hkaiTraversalAnnotationLibrary::getTraversalType(library, index);
  if ( TraversalType )
  {
    v7 = TraversalType - 1;
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( v8 )
      {
        if ( v8 == 1 )
          hkaiTraversalAnnotationViewer::addDuckUnderGeometry(this, library, index);
      }
      else
      {
        hkaiTraversalAnnotationViewer::addVaultGeometry(this, library, index);
      }
    }
    else
    {
      hkaiTraversalAnnotationViewer::addClimbUpGeometry(this, library, index);
    }
  }
}

// File Line: 118
// RVA: 0xC45A20
void __fastcall hkaiTraversalAnnotationViewer::addJumpGeometry(
        hkaiTraversalAnnotationViewer *this,
        hkaiTraversalAnnotationLibrary *library,
        unsigned int index)
{
  ;
}

// File Line: 123
// RVA: 0xC45A30
void __fastcall hkaiTraversalAnnotationViewer::addClimbUpGeometry(
        hkaiTraversalAnnotationViewer *this,
        hkaiTraversalAnnotationLibrary *library,
        unsigned int index)
{
  int NumGrabSegments; // eax
  __int64 v6; // rsi
  int i; // ebx
  hkaiViewerContext *m_pntr; // rax
  _QWORD **Value; // rax
  hkDisplayCapsule *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rdi
  int v13; // ecx
  hkDebugDisplayHandler *m_displayHandler; // rcx
  hkDebugDisplayHandlerVtbl *vfptr; // r10
  __int64 j; // rbx
  _QWORD *array; // [rsp+38h] [rbp-9h] BYREF
  int v18; // [rsp+40h] [rbp-1h]
  int v19; // [rsp+44h] [rbp+3h]
  hkVector4f rightPointOut; // [rsp+48h] [rbp+7h] BYREF
  hkVector4f leftPointOut; // [rsp+58h] [rbp+17h] BYREF
  void *retaddr; // [rsp+A8h] [rbp+67h] BYREF
  unsigned int annotationIndex; // [rsp+B8h] [rbp+77h] BYREF
  unsigned int v24; // [rsp+C0h] [rbp+7Fh]

  v24 = index;
  NumGrabSegments = hkaiClimbUpUtils::getNumGrabSegments(library, &annotationIndex);
  v19 = 0x80000000;
  array = 0i64;
  v18 = 0;
  v6 = NumGrabSegments;
  if ( NumGrabSegments > 0 )
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerTempAllocator::s_alloc, &array, NumGrabSegments, 8);
  for ( i = 0; i < (int)v6; ++v18 )
  {
    hkaiClimbUpUtils::getGrabSegment(library, &annotationIndex, i, &leftPointOut, &rightPointOut);
    m_pntr = this->m_context.m_pntr;
    leftPointOut.m_quad = _mm_add_ps(leftPointOut.m_quad, m_pntr->m_displayOffset.m_quad);
    rightPointOut.m_quad = _mm_add_ps(rightPointOut.m_quad, m_pntr->m_displayOffset.m_quad);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkDisplayCapsule *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 160i64);
    if ( v10 )
    {
      hkDisplayCapsule::hkDisplayCapsule(v10, &leftPointOut, &rightPointOut, 0.039999999, 12, 1);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    v13 = v18;
    if ( v18 == (v19 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 8);
      v13 = v18;
    }
    ++i;
    array[v13] = v12;
  }
  m_displayHandler = this->m_displayHandler;
  vfptr = m_displayHandler->vfptr;
  LODWORD(array) = 0;
  (*(void (__fastcall **)(hkDebugDisplayHandler *, void **, _QWORD **, hkVector4f *, _QWORD, int, _QWORD))vfptr->gap8)(
    m_displayHandler,
    &retaddr,
    &array,
    &transform,
    annotationIndex,
    hkaiTraversalAnnotationViewer::m_tag,
    0i64);
  this->m_displayHandler->hkaiViewerBase::hkProcess::vfptr->setGeometryColor(
    this->m_displayHandler,
    (hkResult *)&retaddr,
    hkColor::DEEPPINK,
    annotationIndex,
    hkaiTraversalAnnotationViewer::m_tag);
  for ( j = 0i64; j < v6; ++j )
    hkReferencedObject::removeReference((hkReferencedObject *)array[j]);
  v18 = 0;
  if ( v19 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v19);
}

// File Line: 152
// RVA: 0xC45C80
void __fastcall hkaiTraversalAnnotationViewer::addVaultGeometry(
        hkaiTraversalAnnotationViewer *this,
        hkaiTraversalAnnotationLibrary *library,
        unsigned int index)
{
  int NumHandPlantSegments; // eax
  __int64 v6; // rsi
  int i; // ebx
  hkaiViewerContext *m_pntr; // rax
  _QWORD **Value; // rax
  hkDisplayCapsule *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rdi
  int v13; // ecx
  hkDebugDisplayHandler *m_displayHandler; // rcx
  hkDebugDisplayHandlerVtbl *vfptr; // r10
  __int64 j; // rbx
  _QWORD *array; // [rsp+38h] [rbp-9h] BYREF
  int v18; // [rsp+40h] [rbp-1h]
  int v19; // [rsp+44h] [rbp+3h]
  hkVector4f rightPointOut; // [rsp+48h] [rbp+7h] BYREF
  hkVector4f leftPointOut; // [rsp+58h] [rbp+17h] BYREF
  void *retaddr; // [rsp+A8h] [rbp+67h] BYREF
  unsigned int annotationIndex; // [rsp+B8h] [rbp+77h] BYREF
  unsigned int v24; // [rsp+C0h] [rbp+7Fh]

  v24 = index;
  NumHandPlantSegments = hkaiVaultUtils::getNumHandPlantSegments(library, &annotationIndex);
  v19 = 0x80000000;
  array = 0i64;
  v18 = 0;
  v6 = NumHandPlantSegments;
  if ( NumHandPlantSegments > 0 )
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerTempAllocator::s_alloc, &array, NumHandPlantSegments, 8);
  for ( i = 0; i < (int)v6; ++v18 )
  {
    hkaiVaultUtils::getHandPlantSegment(library, &annotationIndex, i, &leftPointOut, &rightPointOut);
    m_pntr = this->m_context.m_pntr;
    leftPointOut.m_quad = _mm_add_ps(leftPointOut.m_quad, m_pntr->m_displayOffset.m_quad);
    rightPointOut.m_quad = _mm_add_ps(rightPointOut.m_quad, m_pntr->m_displayOffset.m_quad);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkDisplayCapsule *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 160i64);
    if ( v10 )
    {
      hkDisplayCapsule::hkDisplayCapsule(v10, &leftPointOut, &rightPointOut, 0.039999999, 12, 1);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    v13 = v18;
    if ( v18 == (v19 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 8);
      v13 = v18;
    }
    ++i;
    array[v13] = v12;
  }
  m_displayHandler = this->m_displayHandler;
  vfptr = m_displayHandler->vfptr;
  LODWORD(array) = 0;
  (*(void (__fastcall **)(hkDebugDisplayHandler *, void **, _QWORD **, hkVector4f *, _QWORD, int, _QWORD))vfptr->gap8)(
    m_displayHandler,
    &retaddr,
    &array,
    &transform,
    annotationIndex,
    hkaiTraversalAnnotationViewer::m_tag,
    0i64);
  this->m_displayHandler->hkaiViewerBase::hkProcess::vfptr->setGeometryColor(
    this->m_displayHandler,
    (hkResult *)&retaddr,
    hkColor::CORNFLOWERBLUE,
    annotationIndex,
    hkaiTraversalAnnotationViewer::m_tag);
  for ( j = 0i64; j < v6; ++j )
    hkReferencedObject::removeReference((hkReferencedObject *)array[j]);
  v18 = 0;
  if ( v19 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v19);
}

// File Line: 181
// RVA: 0xC45ED0
void __fastcall hkaiTraversalAnnotationViewer::addDuckUnderGeometry(
        hkaiTraversalAnnotationViewer *this,
        hkaiTraversalAnnotationLibrary *library,
        unsigned int index)
{
  int NumClearanceIntervals; // esi
  _QWORD **Value; // rax
  hkDisplayWireframe *v7; // rax
  __int64 v8; // rax
  __int64 v9; // r14
  int v10; // ecx
  int v11; // r9d
  int v12; // eax
  int v13; // eax
  int i; // edi
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  _QWORD *array; // [rsp+40h] [rbp-29h] BYREF
  int v23; // [rsp+48h] [rbp-21h]
  int v24; // [rsp+4Ch] [rbp-1Dh]
  hkVector4f rightStartPointOut; // [rsp+50h] [rbp-19h] BYREF
  hkVector4f v26; // [rsp+60h] [rbp-9h]
  hkVector4f leftEndPointOut; // [rsp+70h] [rbp+7h] BYREF
  hkVector4f leftStartPointOut; // [rsp+80h] [rbp+17h] BYREF
  hkResult result; // [rsp+D0h] [rbp+67h] BYREF
  unsigned int annotationIndex; // [rsp+E0h] [rbp+77h] BYREF

  annotationIndex = index;
  NumClearanceIntervals = hkaiDuckUnderUtils::getNumClearanceIntervals(library, &annotationIndex);
  array = 0i64;
  v23 = 0;
  v24 = 0x80000000;
  hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, 1, 8);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 128i64);
  if ( v7 )
  {
    hkDisplayWireframe::hkDisplayWireframe(v7);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = v23;
  if ( v23 == (v24 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 8);
    v10 = v23;
  }
  v11 = 8 * NumClearanceIntervals;
  array[v10] = v9;
  ++v23;
  v12 = *(_DWORD *)(v9 + 124) & 0x3FFFFFFF;
  if ( v12 < 8 * NumClearanceIntervals )
  {
    v13 = 2 * v12;
    if ( v11 < v13 )
      v11 = v13;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (void *)(v9 + 112), v11, 16);
  }
  for ( i = 0; i < NumClearanceIntervals; ++*(_DWORD *)(v9 + 120) )
  {
    hkaiDuckUnderUtils::getClearanceInterval(
      library,
      &annotationIndex,
      i,
      &leftStartPointOut,
      &rightStartPointOut,
      &leftEndPointOut);
    if ( *(_DWORD *)(v9 + 120) == (*(_DWORD *)(v9 + 124) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(int *)(v9 + 120)) = (hkVector4f)leftStartPointOut.m_quad;
    v15 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v15 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(int *)(v9 + 120)) = (hkVector4f)rightStartPointOut.m_quad;
    v16 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v16 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(int *)(v9 + 120)) = (hkVector4f)rightStartPointOut.m_quad;
    v17 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v17 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(int *)(v9 + 120)) = (hkVector4f)v26.m_quad;
    v18 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v18 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(int *)(v9 + 120)) = (hkVector4f)v26.m_quad;
    v19 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v19 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(int *)(v9 + 120)) = (hkVector4f)leftEndPointOut.m_quad;
    v20 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v20 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(int *)(v9 + 120)) = (hkVector4f)leftEndPointOut.m_quad;
    v21 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v21 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (void *)(v9 + 112), 16);
    ++i;
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(int *)(v9 + 120)) = (hkVector4f)leftStartPointOut.m_quad;
  }
  (*(void (__fastcall **)(hkDebugDisplayHandler *, hkResult *, _QWORD **, hkVector4f *, _QWORD, int, _QWORD, _DWORD))this->m_displayHandler->hkaiViewerBase::hkProcess::vfptr->gap8)(
    this->m_displayHandler,
    &result,
    &array,
    &transform,
    annotationIndex,
    hkaiTraversalAnnotationViewer::m_tag,
    0i64,
    0);
  this->m_displayHandler->hkaiViewerBase::hkProcess::vfptr->setGeometryColor(
    this->m_displayHandler,
    &result,
    hkColor::GREENYELLOW,
    annotationIndex,
    hkaiTraversalAnnotationViewer::m_tag);
  hkReferencedObject::removeReference((hkReferencedObject *)v9);
  v23 = 0;
  if ( v24 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v24);
}

// File Line: 209
// RVA: 0xC462B0
void __fastcall hkaiTraversalAnnotationViewer::addDropDownGeometry(
        hkaiTraversalAnnotationViewer *this,
        hkaiTraversalAnnotationLibrary *library,
        unsigned int index)
{
  ;
}

