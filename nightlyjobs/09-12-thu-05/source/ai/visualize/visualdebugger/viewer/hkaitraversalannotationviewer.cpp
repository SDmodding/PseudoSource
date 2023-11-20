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
hkProcess *__fastcall hkaiTraversalAnnotationViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiTraversalAnnotationViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiTraversalAnnotationViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                          v2[11],
                                          88i64);
  if ( v3 && (hkaiTraversalAnnotationViewer::hkaiTraversalAnnotationViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 33
// RVA: 0xC45760
void __fastcall hkaiTraversalAnnotationViewer::hkaiTraversalAnnotationViewer(hkaiTraversalAnnotationViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiTraversalAnnotationViewer *v2; // rbx

  v2 = this;
  hkaiViewerBase::hkaiViewerBase((hkaiViewerBase *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiTraversalAnnotationViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiTraversalAnnotationViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiTraversalAnnotationViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiTraversalAnnotationViewer::`vftable';
}

// File Line: 38
// RVA: 0xC45620
void __fastcall hkaiTraversalAnnotationViewer::init(hkaiTraversalAnnotationViewer *this)
{
  hkProcessHandler *v1; // rdx
  int v2; // ebx
  hkaiTraversalAnnotationViewer *v3; // rdi
  int v4; // esi
  __int64 v5; // rbp
  hkProcessHandler *v6; // rdx
  __int64 v7; // rsi

  v1 = this->m_processHandler;
  v2 = 0;
  v3 = this;
  v4 = 0;
  if ( v1 )
  {
    v5 = 0i64;
    do
    {
      if ( v4 >= SLODWORD(v1[22].vfptr) )
        break;
      ((void (__fastcall *)(hkDebugDisplayHandler **, _QWORD))v3->m_displayHandler[1].vfptr)(
        &v3->m_displayHandler,
        *(void *(__fastcall **)(hkProcessHandler *, unsigned int))((char *)&v1[21].vfptr->__vecDelDtor + v5));
      v1 = v3->m_processHandler;
      ++v4;
      v5 += 8i64;
    }
    while ( v1 );
  }
  v6 = v3->m_processHandler;
  if ( v6 )
  {
    v7 = 0i64;
    do
    {
      if ( v2 >= SLODWORD(v6[24].vfptr) )
        break;
      ((void (__fastcall *)(hkDebugDisplayHandler **, _QWORD))v3->m_displayHandler[3].vfptr)(
        &v3->m_displayHandler,
        *(void *(__fastcall **)(hkProcessHandler *, unsigned int))((char *)&v6[23].vfptr->__vecDelDtor + v7));
      v6 = v3->m_processHandler;
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
  hkaiTraversalAnnotationViewer *v2; // rbx
  int v3; // esi
  __int64 v4; // rbp
  hkaiViewerContext *v5; // rdx
  __int64 v6; // rsi
  hkaiViewerContext *v7; // rdx

  v1 = 0;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiTraversalAnnotationViewer::`vftable'{for `hkReferencedObject'};
  v3 = 0;
  this->vfptr = (hkProcessVtbl *)&hkaiTraversalAnnotationViewer::`vftable'{for `hkProcess'};
  this->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiTraversalAnnotationViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  this->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiTraversalAnnotationViewer::`vftable';
  if ( this->m_context.m_pntr )
  {
    v4 = 0i64;
    do
    {
      v5 = v2->m_context.m_pntr;
      if ( v3 >= v5->m_worlds.m_size )
        break;
      hkaiTraversalAnnotationViewer::worldRemovedCallback(
        (hkaiTraversalAnnotationViewer *)((char *)v2 + 64),
        v5->m_worlds.m_data[v4]);
      ++v3;
      ++v4;
    }
    while ( v2->m_context.m_pntr );
  }
  if ( v2->m_context.m_pntr )
  {
    v6 = 0i64;
    do
    {
      v7 = v2->m_context.m_pntr;
      if ( v1 >= v7->m_traversalAnnotationLibraries.m_size )
        break;
      hkaiTraversalAnnotationViewer::traversalAnnotationLibraryRemovedCallback(
        (hkaiTraversalAnnotationViewer *)((char *)v2 + 64),
        v7->m_traversalAnnotationLibraries.m_data[v6].m_pntr);
      ++v1;
      ++v6;
    }
    while ( v2->m_context.m_pntr );
  }
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable';
  hkaiViewerBase::~hkaiViewerBase((hkaiViewerBase *)&v2->vfptr);
}

// File Line: 64
// RVA: 0xC456E0
void __fastcall hkaiTraversalAnnotationViewer::worldAddedCallback(hkaiTraversalAnnotationViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiTraversalAnnotationViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->vfptr);
}

// File Line: 69
// RVA: 0xC45710
void __fastcall hkaiTraversalAnnotationViewer::worldRemovedCallback(hkaiTraversalAnnotationViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiTraversalAnnotationViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->vfptr);
}

// File Line: 74
// RVA: 0xC456D0
void __fastcall hkaiTraversalAnnotationViewer::postStepCallback(hkaiTraversalAnnotationViewer *this, hkaiWorld *world, hkArrayBase<hkaiBehavior *> *behaviors)
{
  ;
}

// File Line: 79
// RVA: 0xC45740
void __fastcall hkaiTraversalAnnotationViewer::traversalAnnotationLibraryAddedCallback(hkaiTraversalAnnotationViewer *this, hkaiTraversalAnnotationLibrary *library)
{
  hkaiTraversalAnnotationViewer::addLibraryGeometry((hkaiTraversalAnnotationViewer *)((char *)this - 64), library);
}

// File Line: 84
// RVA: 0xC45750
void __fastcall hkaiTraversalAnnotationViewer::traversalAnnotationLibraryRemovedCallback(hkaiTraversalAnnotationViewer *this, hkaiTraversalAnnotationLibrary *library)
{
  hkaiTraversalAnnotationViewer::removeLibraryGeometry((hkaiTraversalAnnotationViewer *)((char *)this - 64), library);
}

// File Line: 89
// RVA: 0xC458A0
void __fastcall hkaiTraversalAnnotationViewer::addLibraryGeometry(hkaiTraversalAnnotationViewer *this, hkaiTraversalAnnotationLibrary *library)
{
  hkaiTraversalAnnotationViewer *v2; // rbp
  hkaiTraversalAnnotationLibrary *v3; // rdi
  signed int v4; // ebx
  signed int v5; // esi

  v2 = this;
  v3 = library;
  v4 = 0;
  v5 = hkaiTraversalAnnotationLibrary::getNumAnnotations(library);
  if ( v5 > 0 )
  {
    do
      hkaiTraversalAnnotationViewer::addAnnotationGeometry(v2, v3, v4++);
    while ( v4 < v5 );
  }
}

// File Line: 97
// RVA: 0xC45900
void __fastcall hkaiTraversalAnnotationViewer::removeLibraryGeometry(hkaiTraversalAnnotationViewer *this, hkaiTraversalAnnotationLibrary *library)
{
  hkaiTraversalAnnotationViewer *v2; // rsi
  unsigned int v3; // eax
  __int64 v4; // rdi
  unsigned __int64 v5; // rbx
  char v6; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = hkaiTraversalAnnotationLibrary::getNumAnnotations(library);
  if ( (signed int)v3 > 0 )
  {
    v4 = v3;
    v5 = 0i64;
    do
    {
      v2->m_displayHandler->vfptr->removeGeometry(
        v2->m_displayHandler,
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
void __fastcall hkaiTraversalAnnotationViewer::addAnnotationGeometry(hkaiTraversalAnnotationViewer *this, hkaiTraversalAnnotationLibrary *library, unsigned int index)
{
  hkaiTraversalAnnotationLibrary *v3; // rdi
  hkaiTraversalAnnotationViewer *v4; // rsi
  unsigned int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax

  v3 = library;
  v4 = this;
  v5 = index;
  v6 = hkaiTraversalAnnotationLibrary::getTraversalType(library, index);
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( v8 )
      {
        if ( v8 == 1 )
          hkaiTraversalAnnotationViewer::addDuckUnderGeometry(v4, v3, v5);
      }
      else
      {
        hkaiTraversalAnnotationViewer::addVaultGeometry(v4, v3, v5);
      }
    }
    else
    {
      hkaiTraversalAnnotationViewer::addClimbUpGeometry(v4, v3, v5);
    }
  }
}

// File Line: 118
// RVA: 0xC45A20
void __fastcall hkaiTraversalAnnotationViewer::addJumpGeometry(hkaiTraversalAnnotationViewer *this, hkaiTraversalAnnotationLibrary *library, unsigned int index)
{
  ;
}

// File Line: 123
// RVA: 0xC45A30
void __fastcall hkaiTraversalAnnotationViewer::addClimbUpGeometry(hkaiTraversalAnnotationViewer *this, hkaiTraversalAnnotationLibrary *library, unsigned int index)
{
  hkaiTraversalAnnotationLibrary *v3; // r15
  hkaiTraversalAnnotationViewer *v4; // r14
  int v5; // eax
  __int64 v6; // rsi
  int v7; // er9
  int i; // ebx
  __m128 *v9; // rax
  _QWORD **v10; // rax
  hkDisplayCapsule *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rdi
  int v14; // ecx
  hkDebugDisplayHandler *v15; // rcx
  hkDebugDisplayHandlerVtbl *v16; // r10
  __int64 ST20_8_12; // ST20_8
  __int64 j; // rbx
  __int64 numHeightSegments; // [rsp+28h] [rbp-19h]
  _QWORD *array; // [rsp+38h] [rbp-9h]
  int v21; // [rsp+40h] [rbp-1h]
  int v22; // [rsp+44h] [rbp+3h]
  hkVector4f rightPointOut; // [rsp+48h] [rbp+7h]
  hkVector4f leftPointOut; // [rsp+58h] [rbp+17h]
  void *retaddr; // [rsp+A8h] [rbp+67h]
  unsigned int annotationIndex; // [rsp+B8h] [rbp+77h]
  unsigned int v27; // [rsp+C0h] [rbp+7Fh]

  v27 = index;
  v3 = library;
  v4 = this;
  v5 = hkaiClimbUpUtils::getNumGrabSegments(library, &annotationIndex);
  v22 = 2147483648;
  array = 0i64;
  v21 = 0;
  v6 = v5;
  if ( v5 > 0 )
  {
    v7 = v5;
    if ( v5 < 0 )
      v7 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &array,
      v7,
      8);
  }
  for ( i = 0; i < (signed int)v6; ++v21 )
  {
    hkaiClimbUpUtils::getGrabSegment(v3, &annotationIndex, i, &leftPointOut, &rightPointOut);
    v9 = (__m128 *)v4->m_context.m_pntr;
    leftPointOut.m_quad = _mm_add_ps(leftPointOut.m_quad, v9[14]);
    rightPointOut.m_quad = _mm_add_ps(rightPointOut.m_quad, v9[14]);
    v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkDisplayCapsule *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 160i64);
    if ( v11 )
    {
      hkDisplayCapsule::hkDisplayCapsule(v11, &leftPointOut, &rightPointOut, 0.039999999, 12, 1);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    v14 = v21;
    if ( v21 == (v22 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8);
      v14 = v21;
    }
    ++i;
    array[v14] = v13;
  }
  v15 = v4->m_displayHandler;
  v16 = v15->vfptr;
  LODWORD(array) = 0;
  LODWORD(numHeightSegments) = hkaiTraversalAnnotationViewer::m_tag;
  (*(void (__fastcall **)(hkDebugDisplayHandler *, void **, _QWORD **, hkVector4f *, _QWORD, __int64, _QWORD))v16->gap8)(
    v15,
    &retaddr,
    &array,
    &transform,
    annotationIndex,
    numHeightSegments,
    0i64);
  LODWORD(ST20_8_12) = hkaiTraversalAnnotationViewer::m_tag;
  v4->m_displayHandler->vfptr->setGeometryColor(
    v4->m_displayHandler,
    (hkResult *)&retaddr,
    hkColor::DEEPPINK,
    annotationIndex,
    ST20_8_12);
  for ( j = 0i64; j < v6; ++j )
    hkReferencedObject::removeReference((hkReferencedObject *)array[j]);
  v21 = 0;
  if ( v22 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v22);
}

// File Line: 152
// RVA: 0xC45C80
void __fastcall hkaiTraversalAnnotationViewer::addVaultGeometry(hkaiTraversalAnnotationViewer *this, hkaiTraversalAnnotationLibrary *library, unsigned int index)
{
  hkaiTraversalAnnotationLibrary *v3; // r15
  hkaiTraversalAnnotationViewer *v4; // r14
  int v5; // eax
  __int64 v6; // rsi
  int v7; // er9
  int i; // ebx
  __m128 *v9; // rax
  _QWORD **v10; // rax
  hkDisplayCapsule *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rdi
  int v14; // ecx
  hkDebugDisplayHandler *v15; // rcx
  hkDebugDisplayHandlerVtbl *v16; // r10
  __int64 ST20_8_12; // ST20_8
  __int64 j; // rbx
  __int64 numHeightSegments; // [rsp+28h] [rbp-19h]
  _QWORD *array; // [rsp+38h] [rbp-9h]
  int v21; // [rsp+40h] [rbp-1h]
  int v22; // [rsp+44h] [rbp+3h]
  hkVector4f rightPointOut; // [rsp+48h] [rbp+7h]
  hkVector4f leftPointOut; // [rsp+58h] [rbp+17h]
  void *retaddr; // [rsp+A8h] [rbp+67h]
  unsigned int annotationIndex; // [rsp+B8h] [rbp+77h]
  unsigned int v27; // [rsp+C0h] [rbp+7Fh]

  v27 = index;
  v3 = library;
  v4 = this;
  v5 = hkaiVaultUtils::getNumHandPlantSegments(library, &annotationIndex);
  v22 = 2147483648;
  array = 0i64;
  v21 = 0;
  v6 = v5;
  if ( v5 > 0 )
  {
    v7 = v5;
    if ( v5 < 0 )
      v7 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &array,
      v7,
      8);
  }
  for ( i = 0; i < (signed int)v6; ++v21 )
  {
    hkaiVaultUtils::getHandPlantSegment(v3, &annotationIndex, i, &leftPointOut, &rightPointOut);
    v9 = (__m128 *)v4->m_context.m_pntr;
    leftPointOut.m_quad = _mm_add_ps(leftPointOut.m_quad, v9[14]);
    rightPointOut.m_quad = _mm_add_ps(rightPointOut.m_quad, v9[14]);
    v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkDisplayCapsule *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 160i64);
    if ( v11 )
    {
      hkDisplayCapsule::hkDisplayCapsule(v11, &leftPointOut, &rightPointOut, 0.039999999, 12, 1);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    v14 = v21;
    if ( v21 == (v22 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8);
      v14 = v21;
    }
    ++i;
    array[v14] = v13;
  }
  v15 = v4->m_displayHandler;
  v16 = v15->vfptr;
  LODWORD(array) = 0;
  LODWORD(numHeightSegments) = hkaiTraversalAnnotationViewer::m_tag;
  (*(void (__fastcall **)(hkDebugDisplayHandler *, void **, _QWORD **, hkVector4f *, _QWORD, __int64, _QWORD))v16->gap8)(
    v15,
    &retaddr,
    &array,
    &transform,
    annotationIndex,
    numHeightSegments,
    0i64);
  LODWORD(ST20_8_12) = hkaiTraversalAnnotationViewer::m_tag;
  v4->m_displayHandler->vfptr->setGeometryColor(
    v4->m_displayHandler,
    (hkResult *)&retaddr,
    hkColor::CORNFLOWERBLUE,
    annotationIndex,
    ST20_8_12);
  for ( j = 0i64; j < v6; ++j )
    hkReferencedObject::removeReference((hkReferencedObject *)array[j]);
  v21 = 0;
  if ( v22 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v22);
}

// File Line: 181
// RVA: 0xC45ED0
void __fastcall hkaiTraversalAnnotationViewer::addDuckUnderGeometry(hkaiTraversalAnnotationViewer *this, hkaiTraversalAnnotationLibrary *library, unsigned int index)
{
  hkaiTraversalAnnotationLibrary *v3; // r15
  hkaiTraversalAnnotationViewer *v4; // r13
  int v5; // esi
  _QWORD **v6; // rax
  hkDisplayWireframe *v7; // rax
  __int64 v8; // rax
  __int64 v9; // r14
  int v10; // ecx
  int v11; // er9
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
  __int64 ST20_8_28; // ST20_8
  hkVector4f *leftEndPointOut; // [rsp+28h] [rbp-41h]
  _QWORD *array; // [rsp+40h] [rbp-29h]
  int v25; // [rsp+48h] [rbp-21h]
  int v26; // [rsp+4Ch] [rbp-1Dh]
  hkVector4f rightStartPointOut; // [rsp+50h] [rbp-19h]
  hkVector4f v28; // [rsp+60h] [rbp-9h]
  hkVector4f v29; // [rsp+70h] [rbp+7h]
  hkVector4f leftStartPointOut; // [rsp+80h] [rbp+17h]
  hkResult result; // [rsp+D0h] [rbp+67h]
  unsigned int annotationIndex; // [rsp+E0h] [rbp+77h]

  annotationIndex = index;
  v3 = library;
  v4 = this;
  v5 = hkaiDuckUnderUtils::getNumClearanceIntervals(library, &annotationIndex);
  array = 0i64;
  v25 = 0;
  v26 = 2147483648;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 1, 8);
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 128i64);
  if ( v7 )
  {
    hkDisplayWireframe::hkDisplayWireframe(v7);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = v25;
  if ( v25 == (v26 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8);
    v10 = v25;
  }
  v11 = 8 * v5;
  array[v10] = v9;
  ++v25;
  v12 = *(_DWORD *)(v9 + 124) & 0x3FFFFFFF;
  if ( v12 < 8 * v5 )
  {
    v13 = 2 * v12;
    if ( v11 < v13 )
      v11 = v13;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(v9 + 112),
      v11,
      16);
  }
  for ( i = 0; i < v5; ++*(_DWORD *)(v9 + 120) )
  {
    hkaiDuckUnderUtils::getClearanceInterval(v3, &annotationIndex, i, &leftStartPointOut, &rightStartPointOut, &v29);
    if ( *(_DWORD *)(v9 + 120) == (*(_DWORD *)(v9 + 124) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(signed int *)(v9 + 120)) = (hkVector4f)leftStartPointOut.m_quad;
    v15 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v15 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(signed int *)(v9 + 120)) = (hkVector4f)rightStartPointOut.m_quad;
    v16 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v16 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(signed int *)(v9 + 120)) = (hkVector4f)rightStartPointOut.m_quad;
    v17 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v17 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(signed int *)(v9 + 120)) = (hkVector4f)v28.m_quad;
    v18 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v18 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(signed int *)(v9 + 120)) = (hkVector4f)v28.m_quad;
    v19 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v19 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(signed int *)(v9 + 120)) = (hkVector4f)v29.m_quad;
    v20 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v20 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, (void *)(v9 + 112), 16);
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(signed int *)(v9 + 120)) = (hkVector4f)v29.m_quad;
    v21 = *(_DWORD *)(v9 + 124);
    if ( ++*(_DWORD *)(v9 + 120) == (v21 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, (void *)(v9 + 112), 16);
    ++i;
    *(hkVector4f *)(*(_QWORD *)(v9 + 112) + 16i64 * *(signed int *)(v9 + 120)) = (hkVector4f)leftStartPointOut.m_quad;
  }
  LODWORD(leftEndPointOut) = hkaiTraversalAnnotationViewer::m_tag;
  (*(void (__fastcall **)(hkDebugDisplayHandler *, hkResult *, _QWORD **, hkVector4f *, _QWORD, hkVector4f *, _QWORD, _DWORD))v4->m_displayHandler->vfptr->gap8)(
    v4->m_displayHandler,
    &result,
    &array,
    &transform,
    annotationIndex,
    leftEndPointOut,
    0i64,
    0);
  LODWORD(ST20_8_28) = hkaiTraversalAnnotationViewer::m_tag;
  v4->m_displayHandler->vfptr->setGeometryColor(
    v4->m_displayHandler,
    &result,
    hkColor::GREENYELLOW,
    annotationIndex,
    ST20_8_28);
  hkReferencedObject::removeReference((hkReferencedObject *)v9);
  v25 = 0;
  if ( v26 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v26);
}

// File Line: 209
// RVA: 0xC462B0
void __fastcall hkaiTraversalAnnotationViewer::addDropDownGeometry(hkaiTraversalAnnotationViewer *this, hkaiTraversalAnnotationLibrary *library, unsigned int index)
{
  ;
}

