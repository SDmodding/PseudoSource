// File Line: 18
// RVA: 0xC45400
void __fastcall hkaiPathRequestViewer::hkaiPathRequestViewer(hkaiPathRequestViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiPathRequestViewer *v2; // rbx

  v2 = this;
  hkaiViewerBase::hkaiViewerBase((hkaiViewerBase *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiPathRequestViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiPathRequestViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiPathRequestViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiPathRequestViewer::`vftable';
}

// File Line: 22
// RVA: 0xC45450
void __fastcall hkaiPathRequestViewer::~hkaiPathRequestViewer(hkaiPathRequestViewer *this)
{
  int v1; // edi
  hkaiPathRequestViewer *v2; // rbx
  __int64 v3; // rsi
  hkaiViewerContext *v4; // rdx

  v1 = 0;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPathRequestViewer::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessVtbl *)&hkaiPathRequestViewer::`vftable'{for `hkProcess'};
  this->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiPathRequestViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  this->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiPathRequestViewer::`vftable';
  if ( this->m_context.m_pntr )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_context.m_pntr;
      if ( v1 >= v4->m_worlds.m_size )
        break;
      hkaiPathRequestViewer::worldRemovedCallback((hkaiPathRequestViewer *)((char *)v2 + 64), v4->m_worlds.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v2->m_context.m_pntr );
  }
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable';
  hkaiViewerBase::~hkaiViewerBase((hkaiViewerBase *)&v2->vfptr);
}

// File Line: 30
// RVA: 0xC45220
void __fastcall hkaiPathRequestViewer::init(hkaiPathRequestViewer *this)
{
  hkProcessHandler *v1; // rax
  int v2; // ebx
  hkaiPathRequestViewer *v3; // rsi
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

// File Line: 38
// RVA: 0xC453A0
void __fastcall hkaiPathRequestViewer::worldAddedCallback(hkaiPathRequestViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiPathRequestViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->vfptr);
}

// File Line: 43
// RVA: 0xC453D0
void __fastcall hkaiPathRequestViewer::worldRemovedCallback(hkaiPathRequestViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiPathRequestViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->vfptr);
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
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiPathRequestViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiPathRequestViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 88i64);
  if ( v3 && (hkaiPathRequestViewer::hkaiPathRequestViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 61
// RVA: 0xC45290
void __fastcall hkaiPathRequestViewer::pathRequestProcessedCallback(hkaiPathRequestViewer *this, hkaiNavMeshPathRequestInfo *request)
{
  hkaiPathRequestViewer *v2; // rsi
  hkaiNavMeshPathRequestInfo *v3; // rdi
  hkaiPathfindingUtil::FindPathInput *v4; // rbx
  hkaiPathfindingUtil::FindPathOutput *v5; // rdx
  char v6; // al
  int i; // edi
  hkDebugDisplayHandler *displayHandler; // [rsp+20h] [rbp-38h]
  __int64 tag; // [rsp+28h] [rbp-30h]
  _QWORD displayOffset[5]; // [rsp+30h] [rbp-28h]
  char v11; // [rsp+60h] [rbp+8h]

  v2 = this;
  v3 = request;
  hkRemoteObjectProcess::sendObject(
    (hkDisplaySerializeOStream *)this[-1].m_displayHandler,
    (hkReferencedObject *)&request->vfptr,
    SEND_OBJECT_TAGFILE);
  v4 = v3->m_input.m_pntr;
  if ( v4 )
  {
    v5 = v3->m_output.m_pntr;
    if ( v5 )
    {
      v6 = v5->m_outputParameters.m_status.m_storage;
      if ( v6 == 2 )
      {
        for ( i = 0; i < v4->m_goalPoints.m_size; ++i )
        {
          LODWORD(displayOffset[0]) = hkaiPathRequestViewer::m_tag;
          LODWORD(tag) = 0;
          LODWORD(displayHandler) = hkColor::YELLOW;
          ((void (__fastcall *)(hkProcessHandler *, char *, hkVector4f *, hkVector4f *, hkDebugDisplayHandler *, __int64, _QWORD))v2[-1].m_processHandler->vfptr[1].createProcess)(
            v2[-1].m_processHandler,
            &v11,
            &v4->m_startPoint,
            &v4->m_goalPoints.m_data[i],
            displayHandler,
            tag,
            displayOffset[0]);
        }
      }
      else if ( v6 != 5 )
      {
        hkaiNavMeshDebugUtils::_drawPathWithRadius(
          v4,
          v5,
          hkColor::CYAN,
          hkColor::ORANGE,
          (hkDebugDisplayHandler *)v2[-1].m_processHandler,
          hkaiPathRequestViewer::m_tag,
          0.001);
      }
    }
  }
}

// File Line: 84
// RVA: 0xC45380
void __fastcall hkaiPathRequestViewer::pathRequestProcessedCallback(hkaiPathRequestViewer *this, hkaiNavVolumePathRequestInfo *request)
{
  hkRemoteObjectProcess::sendObject(
    (hkDisplaySerializeOStream *)this[-1].m_displayHandler,
    (hkReferencedObject *)&request->vfptr,
    SEND_OBJECT_TAGFILE);
}

