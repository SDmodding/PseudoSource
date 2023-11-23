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
  _QWORD **Value; // rax
  hkaiSensorViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiSensorViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 104i64);
  if ( v3 && (hkaiSensorViewer::hkaiSensorViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 32
// RVA: 0xC41F20
void __fastcall hkaiSensorViewer::hkaiSensorViewer(
        hkaiSensorViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiViewerBase::hkaiViewerBase(this, contexts);
  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiSensorViewer::`vftable{for `hkReferencedObject};
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiSensorViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiSensorViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiSensorViewer::`vftable;
  this->m_displayAabbs.m_capacityAndFlags = 0x80000000;
  this->m_displayAabbs.m_data = 0i64;
  this->m_displayAabbs.m_size = 0;
}

// File Line: 37
// RVA: 0xC41930
void __fastcall hkaiSensorViewer::init(hkaiSensorViewer *this)
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

// File Line: 45
// RVA: 0xC41F80
void __fastcall hkaiSensorViewer::~hkaiSensorViewer(hkaiSensorViewer *this)
{
  int v1; // edi
  __int64 v3; // rsi
  hkaiViewerContext *m_pntr; // rdx
  int v5; // edi
  hkDisplayAABB *v6; // rsi
  hkDisplayAABB *v7; // rbp
  int m_capacityAndFlags; // eax

  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiSensorViewer::`vftable{for `hkReferencedObject};
  v1 = 0;
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiSensorViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiSensorViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiSensorViewer::`vftable;
  if ( this->m_context.m_pntr )
  {
    v3 = 0i64;
    do
    {
      m_pntr = this->m_context.m_pntr;
      if ( v1 >= m_pntr->m_worlds.m_size )
        break;
      hkaiSensorViewer::worldRemovedCallback(
        (hkaiSensorViewer *)&this->hkaiViewerContextWorldListener,
        m_pntr->m_worlds.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( this->m_context.m_pntr );
  }
  v5 = this->m_displayAabbs.m_size - 1;
  if ( v5 >= 0 )
  {
    v6 = &this->m_displayAabbs.m_data[v5];
    v7 = v6;
    do
    {
      v6->vfptr->__vecDelDtor(v7--, 0i64);
      --v5;
      --v6;
    }
    while ( v5 >= 0 );
  }
  m_capacityAndFlags = this->m_displayAabbs.m_capacityAndFlags;
  this->m_displayAabbs.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_displayAabbs.m_data,
      144 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_displayAabbs.m_data = 0i64;
  this->m_displayAabbs.m_capacityAndFlags = 0x80000000;
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable;
  hkaiViewerBase::~hkaiViewerBase(this);
}

// File Line: 53
// RVA: 0xC41EC0
void __fastcall hkaiSensorViewer::worldAddedCallback(hkaiSensorViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiSensorViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 58
// RVA: 0xC41EF0
void __fastcall hkaiSensorViewer::worldRemovedCallback(hkaiSensorViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiSensorViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 63
// RVA: 0xC419A0
void __fastcall hkaiSensorViewer::postStepCallback(
        hkaiSensorViewer *this,
        hkaiWorld *world,
        hkArrayBase<hkaiBehavior *> *behaviors)
{
  int v3; // ebx
  int v6; // r14d
  __int64 v7; // rsi
  int v8; // eax
  int v9; // ecx
  hkLifoAllocator *Value; // rax
  hkVector4f *m_cur; // r8
  int v12; // edx
  char *v13; // rcx
  hkVector4f *v14; // rax
  int v15; // r15d
  __int64 v16; // rsi
  int i; // r12d
  int v18; // ecx
  hkaiBehavior *v19; // r14
  __m128 *p_m_quad; // rbx
  __m128 *v21; // rax
  __m128 *v22; // rcx
  __m128 v23; // xmm0
  __m128 v24; // xmm2
  __int64 v25; // r15
  int v26; // eax
  int v27; // eax
  int v28; // ebx
  void (__fastcall ***v29)(_QWORD, _QWORD); // rdi
  void (__fastcall ***v30)(_QWORD, _QWORD); // rsi
  __int64 vfptr_low; // rax
  hkDisplayAABB *v32; // rbx
  __int64 v33; // rdi
  int v34; // ebx
  hkLifoAllocator *v35; // rcx
  char *v36; // rax
  int v37; // edx
  char *v38; // r8
  int v39; // ebx
  int v40; // edi
  int v41; // edi
  __int64 v42; // rsi
  __int64 v43; // rbx
  hkaiViewerContext *m_pntr; // rcx
  hkBaseObjectVtbl *vfptr; // r10
  int v46; // eax
  char *v47; // rdi
  signed int v48; // ebx
  hkLifoAllocator *v49; // rax
  int v50; // r8d
  int v51; // eax
  char *v52; // rdi
  signed int v53; // ebx
  hkLifoAllocator *v54; // rax
  int v55; // r8d
  hkVector4f *array; // [rsp+28h] [rbp-9h] BYREF
  int v57; // [rsp+30h] [rbp-1h]
  int v58; // [rsp+34h] [rbp+3h]
  void *v59; // [rsp+38h] [rbp+7h]
  int v60; // [rsp+40h] [rbp+Fh]
  char *v61; // [rsp+48h] [rbp+17h] BYREF
  int v62; // [rsp+50h] [rbp+1Fh]
  int v63; // [rsp+54h] [rbp+23h]
  void *p; // [rsp+58h] [rbp+27h]
  int v65; // [rsp+60h] [rbp+2Fh]
  hkaiSensorViewer *retaddr; // [rsp+98h] [rbp+67h] BYREF

  v3 = 0;
  v6 = 0;
  if ( behaviors->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = (int)behaviors->m_data[v7]->hkReferencedObject::hkBaseObject::vfptr[6].__vecDelDtor(
                  behaviors->m_data[v7],
                  world);
      ++v6;
      ++v7;
      v3 += v8;
    }
    while ( v6 < behaviors->m_size );
  }
  v9 = 0;
  array = 0i64;
  v58 = 0x80000000;
  v60 = v3;
  v57 = 0;
  if ( v3 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkVector4f *)Value->m_cur;
    v12 = (32 * v3 + 127) & 0xFFFFFF80;
    v13 = (char *)m_cur + v12;
    if ( v12 > Value->m_slabSize || v13 > Value->m_end )
    {
      v14 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
      v9 = v57;
      array = v14;
    }
    else
    {
      Value->m_cur = v13;
      v9 = v57;
      array = m_cur;
    }
  }
  else
  {
    array = 0i64;
  }
  v15 = 0;
  v59 = array;
  v58 = v3 | 0x80000000;
  if ( behaviors->m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      for ( i = 0;
            i < ((int (__fastcall *)(hkaiBehavior *))behaviors->m_data[v16]->hkReferencedObject::hkBaseObject::vfptr[6].__vecDelDtor)(behaviors->m_data[v16]);
            p_m_quad[1] = _mm_add_ps(v24, v21[2]) )
      {
        v18 = v57;
        v19 = behaviors->m_data[v16];
        if ( v57 == (v58 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 32);
          v18 = v57;
        }
        v57 = v18 + 1;
        p_m_quad = &array[2 * v18].m_quad;
        v21 = (__m128 *)((__int64 (__fastcall *)(hkaiBehavior *, _QWORD))v19->hkReferencedObject::hkBaseObject::vfptr[6].__first_virtual_table_function__)(
                          v19,
                          (unsigned int)i++);
        v22 = (__m128 *)v21[9].m128_u64[1];
        v23 = _mm_max_ps(_mm_shuffle_ps((__m128)v21[6].m128_u32[3], (__m128)v21[6].m128_u32[3], 0), v21[5]);
        v24 = _mm_mul_ps(v22[5], v23);
        *p_m_quad = _mm_add_ps(_mm_mul_ps(v22[4], v23), v21[2]);
      }
      ++v15;
      ++v16;
    }
    while ( v15 < behaviors->m_size );
    v9 = v57;
    this = retaddr;
  }
  if ( v9 > SLODWORD(this->hkaiViewerBase::hkProcess::vfptr) )
  {
    v25 = v9;
    v26 = HIDWORD(this->hkaiViewerBase::hkProcess::vfptr) & 0x3FFFFFFF;
    if ( v26 < v9 )
    {
      v27 = 2 * v26;
      if ( v9 < v27 )
        v9 = v27;
      hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerHeapAllocator::s_alloc, &this->m_memSizeAndFlags, v9, 144);
      v9 = v57;
    }
    v28 = LODWORD(this->hkaiViewerBase::hkProcess::vfptr) - v25 - 1;
    if ( v28 >= 0 )
    {
      v29 = (void (__fastcall ***)(_QWORD, _QWORD))(*(_QWORD *)&this->m_memSizeAndFlags + 144 * v25 + 144i64 * v28);
      v30 = v29;
      do
      {
        (**v29)(v30, 0i64);
        v30 -= 18;
        --v28;
        v29 -= 18;
      }
      while ( v28 >= 0 );
      v9 = v57;
    }
    vfptr_low = SLODWORD(this->hkaiViewerBase::hkProcess::vfptr);
    v32 = (hkDisplayAABB *)(*(_QWORD *)&this->m_memSizeAndFlags + 144 * vfptr_low);
    if ( (int)v25 - (int)vfptr_low > 0 )
    {
      v33 = (unsigned int)(v25 - vfptr_low);
      do
      {
        if ( v32 )
          hkDisplayAABB::hkDisplayAABB(v32);
        ++v32;
        --v33;
      }
      while ( v33 );
      v9 = v57;
    }
    LODWORD(this->hkaiViewerBase::hkProcess::vfptr) = v25;
  }
  v34 = v9;
  v61 = 0i64;
  v62 = 0;
  v63 = 0x80000000;
  v65 = v9;
  if ( v9 )
  {
    v35 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v36 = (char *)v35->m_cur;
    v37 = (8 * v34 + 127) & 0xFFFFFF80;
    v38 = &v36[v37];
    if ( v37 > v35->m_slabSize || v38 > v35->m_end )
    {
      v36 = (char *)hkLifoAllocator::allocateFromNewSlab(v35, v37);
      v9 = v57;
    }
    else
    {
      v35->m_cur = v38;
      v9 = v57;
    }
  }
  else
  {
    v36 = 0i64;
  }
  v61 = v36;
  p = v36;
  v63 = v34 | 0x80000000;
  v39 = v34 & 0x3FFFFFFF;
  v40 = v9;
  if ( v39 < v9 )
  {
    if ( v9 < 2 * v39 )
      v9 = 2 * v39;
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerHeapAllocator::s_alloc, &v61, v9, 8);
    v9 = v57;
  }
  v62 = v40;
  v41 = 0;
  if ( v9 > 0 )
  {
    v42 = 0i64;
    do
    {
      v43 = 144i64 * v41;
      hkDisplayAABB::setExtents(
        (hkDisplayAABB *)(v43 + *(_QWORD *)&this->m_memSizeAndFlags),
        &array[2 * v41],
        &array[2 * v41 + 1]);
      ++v41;
      v42 += 8i64;
      *(_QWORD *)&v61[v42 - 8] = v43 + *(_QWORD *)&this->m_memSizeAndFlags;
    }
    while ( v41 < v57 );
  }
  m_pntr = this[-1].m_context.m_pntr;
  vfptr = m_pntr->hkReferencedObject::hkBaseObject::vfptr;
  LODWORD(array) = hkaiSensorViewer::m_tag;
  ((void (__fastcall *)(hkaiViewerContext *, hkaiSensorViewer **, char **, _QWORD, _DWORD))vfptr[13].__vecDelDtor)(
    m_pntr,
    &retaddr,
    &v61,
    hkColor::ORANGE,
    0);
  v46 = v62;
  v47 = (char *)p;
  if ( p == v61 )
    v46 = 0;
  v62 = v46;
  v48 = (8 * v65 + 127) & 0xFFFFFF80;
  v49 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v50 = (v48 + 15) & 0xFFFFFFF0;
  if ( v48 > v49->m_slabSize || &v47[v50] != v49->m_cur || v49->m_firstNonLifoEnd == v47 )
    hkLifoAllocator::slowBlockFree(v49, v47, v50);
  else
    v49->m_cur = v47;
  v62 = 0;
  if ( v63 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v61, 8 * v63);
  v51 = v57;
  v52 = (char *)v59;
  v61 = 0i64;
  if ( v59 == array )
    v51 = 0;
  v63 = 0x80000000;
  v57 = v51;
  v53 = (32 * v60 + 127) & 0xFFFFFF80;
  v54 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v55 = (v53 + 15) & 0xFFFFFFF0;
  if ( v53 > v54->m_slabSize || &v52[v55] != v54->m_cur || v54->m_firstNonLifoEnd == v52 )
    hkLifoAllocator::slowBlockFree(v54, v52, v55);
  else
    v54->m_cur = v52;
  v57 = 0;
  if ( v58 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v58);
}
  v57 = 0;
  if ( v58 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v58);
}

