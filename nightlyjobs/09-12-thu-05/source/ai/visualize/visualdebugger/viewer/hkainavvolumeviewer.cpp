// File Line: 20
// RVA: 0xC44C20
void __fastcall hkaiNavVolumeViewer::hkaiNavVolumeViewer(
        hkaiNavVolumeViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiViewerBase::hkaiViewerBase(this, contexts);
  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavVolumeViewer::`vftable{for `hkReferencedObject};
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavVolumeViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavVolumeViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavVolumeViewer::`vftable;
  this->m_navVolumeInfos.m_capacityAndFlags = 0x80000000;
  this->m_navVolumeInfos.m_data = 0i64;
  this->m_navVolumeInfos.m_size = 0;
  this->m_counter = 0;
}

// File Line: 25
// RVA: 0xC44950
void __fastcall hkaiNavVolumeViewer::init(hkaiNavVolumeViewer *this)
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

// File Line: 33
// RVA: 0xC44C80
void __fastcall hkaiNavVolumeViewer::~hkaiNavVolumeViewer(hkaiNavVolumeViewer *this)
{
  bool v1; // zf
  int v3; // edi
  __int64 v4; // rsi
  hkaiViewerContext *m_pntr; // rdx
  int m_capacityAndFlags; // eax

  v1 = this->m_navVolumeInfos.m_size == 0;
  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavVolumeViewer::`vftable{for `hkReferencedObject};
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiNavVolumeViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavVolumeViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavVolumeViewer::`vftable;
  if ( !v1 )
  {
    do
      hkaiNavVolumeViewer::removeNavVolume(this, this->m_navVolumeInfos.m_data->m_navVolume);
    while ( this->m_navVolumeInfos.m_size );
  }
  v3 = 0;
  if ( this->m_context.m_pntr )
  {
    v4 = 0i64;
    do
    {
      m_pntr = this->m_context.m_pntr;
      if ( v3 >= m_pntr->m_worlds.m_size )
        break;
      hkaiNavVolumeViewer::worldRemovedCallback(
        (hkaiNavVolumeViewer *)&this->hkaiViewerContextWorldListener,
        m_pntr->m_worlds.m_data[v4]);
      ++v3;
      ++v4;
    }
    while ( this->m_context.m_pntr );
  }
  m_capacityAndFlags = this->m_navVolumeInfos.m_capacityAndFlags;
  this->m_navVolumeInfos.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_navVolumeInfos.m_data,
      24 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_navVolumeInfos.m_data = 0i64;
  this->m_navVolumeInfos.m_capacityAndFlags = 0x80000000;
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable;
  hkaiViewerBase::~hkaiViewerBase(this);
}

// File Line: 47
// RVA: 0xC44BC0
void __fastcall hkaiNavVolumeViewer::worldAddedCallback(hkaiNavVolumeViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiNavVolumeViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 52
// RVA: 0xC44BF0
void __fastcall hkaiNavVolumeViewer::worldRemovedCallback(hkaiNavVolumeViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiNavVolumeViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 61
// RVA: 0xC448C0
void hkaiNavVolumeViewer::registerViewer(void)
{
  hkaiNavVolumeViewer::m_tag = hkProcessFactory::registerProcess(
                                 hkSingleton<hkProcessFactory>::s_instance,
                                 "AI - Nav Volume Geometry",
                                 hkaiNavVolumeViewer::create);
}

// File Line: 66
// RVA: 0xC448F0
hkProcess *__fastcall hkaiNavVolumeViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkaiNavVolumeViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavVolumeViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
  if ( v3 && (hkaiNavVolumeViewer::hkaiNavVolumeViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 71
// RVA: 0xC449C0
void __fastcall hkaiNavVolumeViewer::postStepCallback(hkaiNavVolumeViewer *this, hkaiWorld *world, __int64 behaviors)
{
  hkaiWorld *v3; // rsi
  int v5; // r15d
  int v6; // ebx
  __int64 v7; // rdi
  __int64 v8; // rax
  hkaiStreamingCollection *m_pntr; // rax
  __int64 v10; // rcx
  hkaiWorld **p_m_volumeInstancePtr; // rax
  hkaiStreamingCollection *v12; // rax
  int v13; // ebx
  __int64 v14; // rdi
  __int64 v15; // rcx
  hkaiWorld **v16; // rax
  __int64 v17; // rax
  __int64 v18; // r14
  hkaiWorld::ListenerVtbl *vfptr; // rdi
  __int64 v20; // rbx
  void *(__fastcall *vecDelDtor)(hkaiWorld::Listener *, unsigned int); // rsi
  int v22; // eax
  __int128 v23[3]; // [rsp+30h] [rbp-68h] BYREF
  __int128 v24; // [rsp+60h] [rbp-38h]
  char v25; // [rsp+A0h] [rbp+8h] BYREF

  v3 = world;
  if ( *(_QWORD *)&this[-1].m_counter )
  {
    v5 = 0;
    v6 = 0;
    if ( SLODWORD(this->hkaiViewerBase::hkProcess::vfptr) > 0 )
    {
      v7 = 0i64;
      do
      {
        v8 = *(_QWORD *)&this->m_memSizeAndFlags;
        if ( *(hkaiWorld **)(v7 + v8 + 16) == v3 )
        {
          world = *(hkaiWorld **)(v7 + v8);
          m_pntr = v3->m_streamingCollection.m_pntr;
          v10 = 0i64;
          behaviors = m_pntr->m_instances.m_size;
          if ( behaviors <= 0 )
          {
LABEL_9:
            hkaiNavVolumeViewer::removeNavVolume(
              (hkaiNavVolumeViewer *)((char *)this - 80),
              (hkaiNavVolumeInstance *)world);
            --v6;
            v7 -= 24i64;
          }
          else
          {
            p_m_volumeInstancePtr = (hkaiWorld **)&m_pntr->m_instances.m_data->m_volumeInstancePtr;
            while ( world != *p_m_volumeInstancePtr )
            {
              ++v10;
              p_m_volumeInstancePtr += 6;
              if ( v10 >= behaviors )
                goto LABEL_9;
            }
          }
        }
        ++v6;
        v7 += 24i64;
      }
      while ( v6 < SLODWORD(this->hkaiViewerBase::hkProcess::vfptr) );
    }
    v12 = v3->m_streamingCollection.m_pntr;
    v13 = 0;
    if ( v12->m_instances.m_size > 0 )
    {
      v14 = 0i64;
      do
      {
        world = (hkaiWorld *)v12->m_instances.m_data[v14].m_volumeInstancePtr;
        if ( world )
        {
          behaviors = SLODWORD(this->hkaiViewerBase::hkProcess::vfptr);
          v15 = 0i64;
          if ( behaviors <= 0 )
          {
LABEL_18:
            hkaiNavVolumeViewer::addNavVolume(
              (hkaiNavVolumeViewer *)((char *)this - 80),
              (hkaiNavVolumeInstance *)world,
              v3);
          }
          else
          {
            v16 = *(hkaiWorld ***)&this->m_memSizeAndFlags;
            while ( *v16 != world )
            {
              ++v15;
              v16 += 3;
              if ( v15 >= behaviors )
                goto LABEL_18;
            }
          }
        }
        v12 = v3->m_streamingCollection.m_pntr;
        ++v13;
        ++v14;
      }
      while ( v13 < v12->m_instances.m_size );
    }
    v17 = *(_QWORD *)&this[-1].m_counter;
    v23[0] = (__int128)transform.m_quad;
    v23[1] = (__int128)direction.m_quad;
    v24 = 0i64;
    v23[2] = (__int128)stru_141A71280.m_quad;
    v24 = *(_OWORD *)(v17 + 224);
    if ( SLODWORD(this->hkaiViewerBase::hkProcess::vfptr) > 0 )
    {
      v18 = 0i64;
      do
      {
        vfptr = this[-1].hkaiWorld::Listener::vfptr;
        v20 = *(_QWORD *)&this->m_memSizeAndFlags;
        vecDelDtor = vfptr->__vecDelDtor;
        v22 = ((__int64 (__fastcall *)(hkDebugDisplayHandler **, hkaiWorld *, __int64))this[-1].m_displayHandler[1].vfptr)(
                &this[-1].m_displayHandler,
                world,
                behaviors);
        (*((void (__fastcall **)(hkaiWorld::ListenerVtbl *, char *, __int128 *, _QWORD, int))vecDelDtor + 9))(
          vfptr,
          &v25,
          v23,
          *(_QWORD *)(v20 + v18 + 8),
          v22);
        ++v5;
        v18 += 24i64;
      }
      while ( v5 < SLODWORD(this->hkaiViewerBase::hkProcess::vfptr) );
    }
  }
});
        ++v5;
        v18 += 24i64;
      }
      while ( v

// File Line: 143
// RVA: 0xC44D90
void __fastcall hkaiNavVolumeViewer::addNavVolume(
        hkaiNavVolumeViewer *this,
        hkaiNavVolumeInstance *navVolume,
        hkaiWorld *world)
{
  _QWORD **Value; // rax
  __int64 v7; // rax
  hkGeometry *v8; // rbx
  hkaiNavVolume *m_pntr; // rdx
  _QWORD **v10; // rax
  hkDisplayConvex *v11; // rax
  hkReferencedObject *v12; // rax
  hkReferencedObject *v13; // r15
  unsigned int m_counter; // ecx
  hkaiViewerContext *v15; // rax
  char *v16; // rdi
  __int128 m_displayOffset; // xmm0
  hkDebugDisplayHandler *m_displayHandler; // rax
  hkDebugDisplayHandlerVtbl *vfptr; // rbx
  int v20; // eax
  hkDebugDisplayHandlerVtbl *v21; // rdi
  int v22; // eax
  __int64 v23; // rsi
  __int64 m_size; // rdx
  hkaiNavVolumeViewer::NavVolumeInfo *v25; // r8
  hkaiNavVolumeDebugUtils::GeomteryBuildSettings buildSettings; // [rsp+40h] [rbp-A8h] BYREF
  __int64 *v27; // [rsp+50h] [rbp-98h] BYREF
  int v28; // [rsp+58h] [rbp-90h]
  int v29; // [rsp+5Ch] [rbp-8Ch]
  hkReferencedObject *v30; // [rsp+60h] [rbp-88h] BYREF
  __int128 v31[3]; // [rsp+70h] [rbp-78h] BYREF
  __int128 v32; // [rsp+A0h] [rbp-48h]
  char v33; // [rsp+F0h] [rbp+8h] BYREF
  char *v34; // [rsp+F8h] [rbp+10h]

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v8 = (hkGeometry *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)v7 = &hkGeometry::`vftable;
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_DWORD *)(v7 + 24) = 0;
    *(_DWORD *)(v7 + 28) = 0x80000000;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_DWORD *)(v7 + 40) = 0;
    *(_DWORD *)(v7 + 44) = 0x80000000;
  }
  else
  {
    v8 = 0i64;
  }
  hkaiNavVolumeDebugUtils::GeomteryBuildSettings::GeomteryBuildSettings(&buildSettings);
  m_pntr = navVolume->m_originalVolume.m_pntr;
  buildSettings.m_skipBoundingFaces = 0;
  hkaiNavVolumeDebugUtils::buildNavVolumeGeometry(&buildSettings, m_pntr, v8);
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v10[11] + 8i64))(v10[11], 112i64);
  if ( v11 )
  {
    hkDisplayConvex::hkDisplayConvex(v11, v8);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  m_counter = this->m_counter;
  v28 = 1;
  v27 = (__int64 *)&v30;
  v29 = -2147483647;
  this->m_counter = m_counter + 1;
  v15 = this->m_context.m_pntr;
  v30 = v13;
  v31[0] = (__int128)transform.m_quad;
  v31[1] = (__int128)direction.m_quad;
  v16 = (char *)navVolume + 2 * m_counter;
  v34 = v16;
  v32 = 0i64;
  v31[2] = (__int128)stru_141A71280.m_quad;
  m_displayOffset = (__int128)v15->m_displayOffset;
  m_displayHandler = this->m_displayHandler;
  v32 = m_displayOffset;
  vfptr = m_displayHandler->vfptr;
  v20 = this->hkaiViewerBase::hkProcess::vfptr->getProcessTag(&this->hkProcess);
  (*(void (__fastcall **)(hkDebugDisplayHandler *, char *, __int64 **, __int128 *, char *, int, _QWORD, _DWORD))vfptr->gap8)(
    this->m_displayHandler,
    &v33,
    &v27,
    v31,
    v16,
    v20,
    0i64,
    0);
  v21 = this->m_displayHandler->hkaiViewerBase::hkProcess::vfptr;
  v22 = this->hkaiViewerBase::hkProcess::vfptr->getProcessTag(&this->hkProcess);
  v23 = (__int64)v34;
  v21->setGeometryColor(this->m_displayHandler, (hkResult *)&v33, hkColor::GREEN, (unsigned __int64)v34, v22);
  hkReferencedObject::removeReference(v13);
  if ( this->m_navVolumeInfos.m_size == (this->m_navVolumeInfos.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_navVolumeInfos, 24);
  m_size = this->m_navVolumeInfos.m_size;
  v25 = &this->m_navVolumeInfos.m_data[m_size];
  this->m_navVolumeInfos.m_size = m_size + 1;
  v25->m_id = v23;
  v25->m_navVolume = navVolume;
  v25->m_world = world;
  v28 = 0;
  if ( v29 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v27, 8 * v29);
  v27 = 0i64;
  v29 = 0x80000000;
  if ( buildSettings.m_filter.m_pntr )
    hkReferencedObject::removeReference(buildSettings.m_filter.m_pntr);
}

// File Line: 171
// RVA: 0xC45010
void __fastcall hkaiNavVolumeViewer::removeNavVolume(hkaiNavVolumeViewer *this, hkaiNavVolumeInstance *navVolume)
{
  __int64 m_size; // r9
  int v3; // esi
  __int64 v4; // r8
  hkaiNavVolumeViewer::NavVolumeInfo *m_data; // r14
  hkaiNavVolumeInstance **i; // rax
  hkDebugDisplayHandler *m_displayHandler; // rbx
  hkDebugDisplayHandlerVtbl *vfptr; // rdi
  __int64 v10; // r15
  int v11; // eax
  __int64 v12; // rax
  hkaiNavVolumeViewer::NavVolumeInfo *v13; // rdx
  hkaiNavVolumeViewer::NavVolumeInfo *v14; // r8
  hkaiNavVolumeViewer::NavVolumeInfo *v15; // rax
  __int64 v16; // rdx
  signed __int64 v17; // r8
  hkaiWorld *v18; // rcx
  char v19; // [rsp+50h] [rbp+8h] BYREF

  m_size = this->m_navVolumeInfos.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size > 0 )
  {
    m_data = this->m_navVolumeInfos.m_data;
    for ( i = &m_data->m_navVolume; navVolume != *i; i += 3 )
    {
      ++v4;
      ++v3;
      if ( v4 >= m_size )
        return;
    }
    m_displayHandler = this->m_displayHandler;
    vfptr = m_displayHandler->vfptr;
    v10 = v3;
    v11 = ((__int64 (__fastcall *)(hkProcess *, hkaiNavVolumeInstance *, __int64))this->hkaiViewerBase::hkProcess::vfptr->getProcessTag)(
            &this->hkProcess,
            navVolume,
            v4);
    vfptr->removeGeometry(m_displayHandler, (hkResult *)&v19, m_data[v10].m_id, v11, 0i64);
    v12 = --this->m_navVolumeInfos.m_size;
    if ( (_DWORD)v12 != v3 )
    {
      v13 = this->m_navVolumeInfos.m_data;
      v14 = &v13[v12];
      v15 = &v13[v10];
      v16 = 3i64;
      v17 = (char *)v14 - (char *)v15;
      do
      {
        v18 = *(hkaiWorld **)((char *)&v15->m_navVolume + v17);
        v15 = (hkaiNavVolumeViewer::NavVolumeInfo *)((char *)v15 + 8);
        v15[-1].m_world = v18;
        --v16;
      }
      while ( v16 );
    }
  }
}

// File Line: 192
// RVA: 0xC44B80
void __fastcall hkaiNavVolumeViewer::navVolumeAdded(
        hkaiNavVolumeViewer *this,
        hkaiWorld *world,
        hkaiNavVolumeInstance *volume,
        hkaiNavVolumeMediator *mediator)
{
  hkaiNavVolumeViewer::addNavVolume((hkaiNavVolumeViewer *)((char *)this - 80), volume, world);
}

// File Line: 197
// RVA: 0xC44BA0
void __fastcall hkaiNavVolumeViewer::navVolumeRemoved(
        hkaiNavVolumeViewer *this,
        hkaiWorld *world,
        hkaiNavVolumeInstance *volume)
{
  hkaiNavVolumeViewer::removeNavVolume((hkaiNavVolumeViewer *)((char *)this - 80), volume);
}

