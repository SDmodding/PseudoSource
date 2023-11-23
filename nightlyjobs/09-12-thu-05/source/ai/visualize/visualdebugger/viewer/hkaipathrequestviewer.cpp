// File Line: 18
// RVA: 0xC45400
void __fastcall hkaiPathRequestViewer::hkaiPathRequestViewer(
        hkaiPathRequestViewer *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiViewerBase::hkaiViewerBase(this, contexts);
  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiPathRequestViewer::`vftable{for `hkReferencedObject};
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiPathRequestViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiPathRequestViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiPathRequestViewer::`vftable;
}

// File Line: 22
// RVA: 0xC45450
void __fastcall hkaiPathRequestViewer::~hkaiPathRequestViewer(hkaiPathRequestViewer *this)
{
  int v1; // edi
  __int64 v3; // rsi
  hkaiViewerContext *m_pntr; // rdx

  v1 = 0;
  this->hkaiViewerBase::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiPathRequestViewer::`vftable{for `hkReferencedObject};
  this->hkaiViewerBase::hkProcess::vfptr = (hkProcessVtbl *)&hkaiPathRequestViewer::`vftable{for `hkProcess};
  this->hkaiViewerBase::hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiPathRequestViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiPathRequestViewer::`vftable;
  if ( this->m_context.m_pntr )
  {
    v3 = 0i64;
    do
    {
      m_pntr = this->m_context.m_pntr;
      if ( v1 >= m_pntr->m_worlds.m_size )
        break;
      hkaiPathRequestViewer::worldRemovedCallback(
        (hkaiPathRequestViewer *)&this->hkaiViewerContextWorldListener,
        m_pntr->m_worlds.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( this->m_context.m_pntr );
  }
  this->hkaiWorld::Listener::vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable;
  hkaiViewerBase::~hkaiViewerBase(this);
}

// File Line: 30
// RVA: 0xC45220
void __fastcall hkaiPathRequestViewer::init(hkaiPathRequestViewer *this)
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

// File Line: 38
// RVA: 0xC453A0
void __fastcall hkaiPathRequestViewer::worldAddedCallback(hkaiPathRequestViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiPathRequestViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 43
// RVA: 0xC453D0
void __fastcall hkaiPathRequestViewer::worldRemovedCallback(hkaiPathRequestViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiPathRequestViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->hkProcess);
}

// File Line: 51
// RVA: 0xC45190
void hkaiPathRequestViewer::registerViewer(void)
{
  hkaiPathRequestViewer::m_tag = hkProcessFactory::registerProcess(
                                   hkSingleton<hkProcessFactory>::s_instance,
                                   "AI - Path Requests",
                                   hkaiPathRequestViewer::create);
}

// File Line: 56
// RVA: 0xC451C0
hkProcess *__fastcall hkaiPathRequestViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkaiPathRequestViewer *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiPathRequestViewer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 88i64);
  if ( v3 && (hkaiPathRequestViewer::hkaiPathRequestViewer(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 61
// RVA: 0xC45290
void __fastcall hkaiPathRequestViewer::pathRequestProcessedCallback(
        hkaiPathRequestViewer *this,
        hkaiNavMeshPathRequestInfo *request)
{
  hkaiPathfindingUtil::FindPathInput *m_pntr; // rbx
  hkaiPathfindingUtil::FindPathOutput *v5; // rdx
  char m_storage; // al
  int i; // edi
  char v8; // [rsp+60h] [rbp+8h] BYREF

  hkRemoteObjectProcess::sendObject(
    (hkDisplaySerializeOStream *)this[-1].m_displayHandler,
    request,
    SEND_OBJECT_TAGFILE);
  m_pntr = request->m_input.m_pntr;
  if ( m_pntr )
  {
    v5 = request->m_output.m_pntr;
    if ( v5 )
    {
      m_storage = v5->m_outputParameters.m_status.m_storage;
      if ( m_storage == 2 )
      {
        for ( i = 0; i < m_pntr->m_goalPoints.m_size; ++i )
          ((void (__fastcall *)(hkProcessHandler *, char *, hkVector4f *, hkVector4f *, const unsigned int, _DWORD, int))this[-1].m_processHandler->hkaiViewerBase::hkProcess::vfptr[1].createProcess)(
            this[-1].m_processHandler,
            &v8,
            &m_pntr->m_startPoint,
            &m_pntr->m_goalPoints.m_data[i],
            hkColor::YELLOW,
            0,
            hkaiPathRequestViewer::m_tag);
      }
      else if ( m_storage != 5 )
      {
        hkaiNavMeshDebugUtils::_drawPathWithRadius(
          m_pntr,
          v5,
          hkColor::CYAN,
          hkColor::ORANGE,
          (hkDebugDisplayHandler *)this[-1].m_processHandler,
          hkaiPathRequestViewer::m_tag,
          0.001);
      }
    }
  }
}

// File Line: 84
// RVA: 0xC45380
void __fastcall hkaiPathRequestViewer::pathRequestProcessedCallback(
        hkaiPathRequestViewer *this,
        hkaiNavVolumePathRequestInfo *request)
{
  hkRemoteObjectProcess::sendObject(
    (hkDisplaySerializeOStream *)this[-1].m_displayHandler,
    request,
    SEND_OBJECT_TAGFILE);
}

