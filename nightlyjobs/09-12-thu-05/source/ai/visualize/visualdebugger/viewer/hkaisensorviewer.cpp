// File Line: 21
// RVA: 0xC418A0
void hkaiSensorViewer::registerViewer(void)
{
  hkaiSensorViewer::m_tag = hkProcessFactory::registerProcess(
                              hkSingleton<hkProcessFactory>::s_instance,
                              "AI - Sensor AABBs",
                              hkaiSensorViewer::create);
}

// File Line: 26
// RVA: 0xC418D0
hkProcess *__fastcall hkaiSensorViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiSensorViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiSensorViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 104i64);
  if ( v3 && (hkaiSensorViewer::hkaiSensorViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 32
// RVA: 0xC41F20
void __fastcall hkaiSensorViewer::hkaiSensorViewer(hkaiSensorViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiSensorViewer *v2; // rbx

  v2 = this;
  hkaiViewerBase::hkaiViewerBase((hkaiViewerBase *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiSensorViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiSensorViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiSensorViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiSensorViewer::`vftable';
  v2->m_displayAabbs.m_capacityAndFlags = 2147483648;
  v2->m_displayAabbs.m_data = 0i64;
  v2->m_displayAabbs.m_size = 0;
}

// File Line: 37
// RVA: 0xC41930
void __fastcall hkaiSensorViewer::init(hkaiSensorViewer *this)
{
  hkProcessHandler *v1; // rax
  int v2; // ebx
  hkaiSensorViewer *v3; // rsi
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

// File Line: 45
// RVA: 0xC41F80
void __fastcall hkaiSensorViewer::~hkaiSensorViewer(hkaiSensorViewer *this)
{
  int v1; // edi
  hkaiSensorViewer *v2; // rbx
  __int64 v3; // rsi
  hkaiViewerContext *v4; // rdx
  hkDisplayAABB *v5; // rcx
  int v6; // edi
  hkDisplayAABB *v7; // rsi
  signed __int64 v8; // rbp
  int v9; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkaiSensorViewer::`vftable'{for `hkReferencedObject'};
  v1 = 0;
  this->vfptr = (hkProcessVtbl *)&hkaiSensorViewer::`vftable'{for `hkProcess'};
  this->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiSensorViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2 = this;
  this->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiSensorViewer::`vftable';
  if ( this->m_context.m_pntr )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_context.m_pntr;
      if ( v1 >= v4->m_worlds.m_size )
        break;
      hkaiSensorViewer::worldRemovedCallback((hkaiSensorViewer *)((char *)v2 + 64), v4->m_worlds.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v2->m_context.m_pntr );
  }
  v5 = v2->m_displayAabbs.m_data;
  v6 = v2->m_displayAabbs.m_size - 1;
  if ( v6 >= 0 )
  {
    v7 = &v5[v6];
    v8 = (signed __int64)&v5[v6];
    do
    {
      v7->vfptr->__vecDelDtor((hkBaseObject *)v8, 0);
      v8 -= 144i64;
      --v6;
      --v7;
    }
    while ( v6 >= 0 );
  }
  v9 = v2->m_displayAabbs.m_capacityAndFlags;
  v2->m_displayAabbs.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_displayAabbs.m_data,
      144 * (v9 & 0x3FFFFFFF));
  v2->m_displayAabbs.m_data = 0i64;
  v2->m_displayAabbs.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable';
  hkaiViewerBase::~hkaiViewerBase((hkaiViewerBase *)&v2->vfptr);
}

// File Line: 53
// RVA: 0xC41EC0
void __fastcall hkaiSensorViewer::worldAddedCallback(hkaiSensorViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiSensorViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->vfptr);
}

// File Line: 58
// RVA: 0xC41EF0
void __fastcall hkaiSensorViewer::worldRemovedCallback(hkaiSensorViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiSensorViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->vfptr);
}

// File Line: 63
// RVA: 0xC419A0
void __fastcall hkaiSensorViewer::postStepCallback(hkaiSensorViewer *this, hkaiWorld *world, hkArrayBase<hkaiBehavior *> *behaviors)
{
  int v3; // ebx
  hkArrayBase<hkaiBehavior *> *v4; // rdi
  hkaiSensorViewer *v5; // r13
  int v6; // er14
  __int64 v7; // rsi
  int v8; // eax
  int v9; // ecx
  LPVOID v10; // rax
  char *v11; // rcx
  hkArrayBase<hkaiBehavior *> *v12; // rax
  int v13; // er15
  __int64 v14; // rsi
  signed int v15; // er12
  int v16; // ecx
  hkaiBehavior *v17; // r14
  __m128 *v18; // rbx
  __m128 *v19; // rax
  __m128 *v20; // rcx
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __int64 v23; // r15
  int v24; // eax
  int v25; // eax
  signed __int64 v26; // rdx
  int v27; // ebx
  void (__fastcall ***v28)(signed __int64, _QWORD, hkArrayBase<hkaiBehavior *> *); // rdi
  signed __int64 v29; // rsi
  __int64 v30; // rax
  hkDisplayAABB *v31; // rbx
  __int64 v32; // rdi
  int v33; // ebx
  hkLifoAllocator *v34; // rax
  hkLifoAllocator *v35; // rcx
  char *v36; // rax
  int v37; // edx
  char *v38; // r8
  unsigned int v39; // ebx
  int v40; // ebx
  int v41; // edi
  int v42; // edi
  __int64 v43; // rsi
  signed __int64 v44; // rbx
  hkaiViewerContext *v45; // rcx
  hkBaseObjectVtbl *v46; // r10
  int v47; // eax
  char *v48; // rdi
  signed int v49; // ebx
  hkLifoAllocator *v50; // rax
  int v51; // er8
  int v52; // eax
  char *v53; // rdi
  signed int v54; // ebx
  hkLifoAllocator *v55; // rax
  int v56; // er8
  __int64 sizeElem; // [rsp+20h] [rbp-11h]
  hkArrayBase<hkaiBehavior *> *array; // [rsp+28h] [rbp-9h]
  int v59; // [rsp+30h] [rbp-1h]
  int v60; // [rsp+34h] [rbp+3h]
  void *v61; // [rsp+38h] [rbp+7h]
  int v62; // [rsp+40h] [rbp+Fh]
  char *v63; // [rsp+48h] [rbp+17h]
  int v64; // [rsp+50h] [rbp+1Fh]
  int v65; // [rsp+54h] [rbp+23h]
  void *p; // [rsp+58h] [rbp+27h]
  int v67; // [rsp+60h] [rbp+2Fh]
  hkaiSensorViewer *retaddr; // [rsp+98h] [rbp+67h]

  v3 = 0;
  v4 = behaviors;
  v5 = this;
  v6 = 0;
  if ( behaviors->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = (__int64)v4->m_data[v7]->vfptr[6].__vecDelDtor((hkBaseObject *)&v4->m_data[v7]->vfptr, (unsigned int)world);
      ++v6;
      ++v7;
      v3 += v8;
    }
    while ( v6 < v4->m_size );
  }
  v9 = 0;
  array = 0i64;
  v60 = 2147483648;
  v62 = v3;
  v59 = 0;
  if ( v3 )
  {
    v10 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    behaviors = (hkArrayBase<hkaiBehavior *> *)*((_QWORD *)v10 + 3);
    world = (hkaiWorld *)((32 * v3 + 127) & 0xFFFFFF80);
    v11 = (char *)behaviors + (signed int)world;
    if ( (signed int)world > *((_DWORD *)v10 + 4) || (unsigned __int64)v11 > *((_QWORD *)v10 + 4) )
    {
      v12 = (hkArrayBase<hkaiBehavior *> *)hkLifoAllocator::allocateFromNewSlab((hkLifoAllocator *)v10, (int)world);
      v9 = v59;
      behaviors = v12;
      array = v12;
    }
    else
    {
      *((_QWORD *)v10 + 3) = v11;
      v9 = v59;
      array = behaviors;
    }
  }
  else
  {
    array = 0i64;
  }
  v13 = 0;
  v61 = array;
  v60 = v3 | 0x80000000;
  if ( v4->m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      v15 = 0;
      if ( ((signed int (__fastcall *)(hkaiBehavior *, hkaiWorld *, hkArrayBase<hkaiBehavior *> *))v4->m_data[v14]->vfptr[6].__vecDelDtor)(
             v4->m_data[v14],
             world,
             behaviors) > 0 )
      {
        do
        {
          v16 = v59;
          v17 = v4->m_data[v14];
          if ( v59 == (v60 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 32);
            v16 = v59;
          }
          v59 = v16 + 1;
          v18 = (__m128 *)&array[2 * v16];
          v19 = (__m128 *)((__int64 (__fastcall *)(hkaiBehavior *, _QWORD))v17->vfptr[6].__first_virtual_table_function__)(
                            v17,
                            (unsigned int)v15++);
          v20 = (__m128 *)v19[9].m128_u64[1];
          v21 = _mm_max_ps(_mm_shuffle_ps((__m128)v19[6].m128_u32[3], (__m128)v19[6].m128_u32[3], 0), v19[5]);
          v22 = _mm_mul_ps(v20[5], v21);
          *v18 = _mm_add_ps(_mm_mul_ps(v20[4], v21), v19[2]);
          v18[1] = _mm_add_ps(v22, v19[2]);
        }
        while ( v15 < ((signed int (*)(void))v4->m_data[v14]->vfptr[6].__vecDelDtor)() );
      }
      ++v13;
      ++v14;
    }
    while ( v13 < v4->m_size );
    v9 = v59;
    v5 = retaddr;
  }
  if ( v9 > SLODWORD(v5->vfptr) )
  {
    v23 = v9;
    v24 = HIDWORD(v5->vfptr) & 0x3FFFFFFF;
    if ( v24 < v9 )
    {
      v25 = 2 * v24;
      if ( v9 < v25 )
        v9 = v25;
      hkArrayUtil::_reserve(
        (hkResult *)&retaddr,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v5->m_memSizeAndFlags,
        v9,
        144);
      v9 = v59;
    }
    v26 = *(_QWORD *)&v5->m_memSizeAndFlags + 144 * v23;
    v27 = LODWORD(v5->vfptr) - v23 - 1;
    if ( v27 >= 0 )
    {
      v28 = (void (__fastcall ***)(signed __int64, _QWORD, hkArrayBase<hkaiBehavior *> *))(v26 + 144i64 * v27);
      v29 = v26 + 144i64 * v27;
      do
      {
        (**v28)(v29, 0i64, behaviors);
        v29 -= 144i64;
        --v27;
        v28 -= 18;
      }
      while ( v27 >= 0 );
      v9 = v59;
    }
    v30 = SLODWORD(v5->vfptr);
    v31 = (hkDisplayAABB *)(*(_QWORD *)&v5->m_memSizeAndFlags + 144 * v30);
    if ( (signed int)v23 - (signed int)v30 > 0 )
    {
      v32 = (unsigned int)(v23 - v30);
      do
      {
        if ( v31 )
          hkDisplayAABB::hkDisplayAABB(v31);
        ++v31;
        --v32;
      }
      while ( v32 );
      v9 = v59;
    }
    LODWORD(v5->vfptr) = v23;
  }
  v33 = v9;
  v63 = 0i64;
  v64 = 0;
  v65 = 2147483648;
  v67 = v9;
  if ( v9 )
  {
    v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v35 = v34;
    v36 = (char *)v34->m_cur;
    v37 = (8 * v33 + 127) & 0xFFFFFF80;
    v38 = &v36[v37];
    if ( v37 > v35->m_slabSize || v38 > v35->m_end )
    {
      v36 = (char *)hkLifoAllocator::allocateFromNewSlab(v35, v37);
      v9 = v59;
    }
    else
    {
      v35->m_cur = v38;
      v9 = v59;
    }
  }
  else
  {
    v36 = 0i64;
  }
  v39 = v33 | 0x80000000;
  v63 = v36;
  p = v36;
  v65 = v39;
  v40 = v39 & 0x3FFFFFFF;
  v41 = v9;
  if ( v40 < v9 )
  {
    if ( v9 < 2 * v40 )
      v9 = 2 * v40;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v63,
      v9,
      8);
    v9 = v59;
  }
  v64 = v41;
  v42 = 0;
  if ( v9 > 0 )
  {
    v43 = 0i64;
    do
    {
      v44 = 144i64 * v42;
      hkDisplayAABB::setExtents(
        (hkDisplayAABB *)(v44 + *(_QWORD *)&v5->m_memSizeAndFlags),
        (hkVector4f *)&array[2 * v42],
        (hkVector4f *)&array[2 * v42 + 1]);
      ++v42;
      v43 += 8i64;
      *(_QWORD *)&v63[v43 - 8] = v44 + *(_QWORD *)&v5->m_memSizeAndFlags;
    }
    while ( v42 < v59 );
  }
  v45 = v5[-1].m_context.m_pntr;
  v46 = v45->vfptr;
  LODWORD(array) = hkaiSensorViewer::m_tag;
  LODWORD(sizeElem) = 0;
  ((void (__fastcall *)(hkaiViewerContext *, hkaiSensorViewer **, char **, _QWORD, __int64))v46[13].__vecDelDtor)(
    v45,
    &retaddr,
    &v63,
    hkColor::ORANGE,
    sizeElem);
  v47 = v64;
  v48 = (char *)p;
  if ( p == v63 )
    v47 = 0;
  v64 = v47;
  v49 = (8 * v67 + 127) & 0xFFFFFF80;
  v50 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v51 = (v49 + 15) & 0xFFFFFFF0;
  if ( v49 > v50->m_slabSize || &v48[v51] != v50->m_cur || v50->m_firstNonLifoEnd == v48 )
    hkLifoAllocator::slowBlockFree(v50, v48, v51);
  else
    v50->m_cur = v48;
  v64 = 0;
  if ( v65 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v63,
      8 * v65);
  v52 = v59;
  v53 = (char *)v61;
  v63 = 0i64;
  if ( v61 == array )
    v52 = 0;
  v65 = 2147483648;
  v59 = v52;
  v54 = (32 * v62 + 127) & 0xFFFFFF80;
  v55 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v56 = (v54 + 15) & 0xFFFFFFF0;
  if ( v54 > v55->m_slabSize || &v53[v56] != v55->m_cur || v55->m_firstNonLifoEnd == v53 )
    hkLifoAllocator::slowBlockFree(v55, v53, v56);
  else
    v55->m_cur = v53;
  v59 = 0;
  if ( v60 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      32 * v60);
}

