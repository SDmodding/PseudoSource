// File Line: 20
// RVA: 0xC44C20
void __fastcall hkaiNavVolumeViewer::hkaiNavVolumeViewer(hkaiNavVolumeViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiNavVolumeViewer *v2; // rbx

  v2 = this;
  hkaiViewerBase::hkaiViewerBase((hkaiViewerBase *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiNavVolumeViewer::`vftable'{for `hkReferencedObject'};
  v2->vfptr = (hkProcessVtbl *)&hkaiNavVolumeViewer::`vftable'{for `hkProcess'};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavVolumeViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavVolumeViewer::`vftable';
  v2->m_navVolumeInfos.m_capacityAndFlags = 2147483648;
  v2->m_navVolumeInfos.m_data = 0i64;
  v2->m_navVolumeInfos.m_size = 0;
  v2->m_counter = 0;
}

// File Line: 25
// RVA: 0xC44950
void __fastcall hkaiNavVolumeViewer::init(hkaiNavVolumeViewer *this)
{
  hkProcessHandler *v1; // rax
  int v2; // ebx
  hkaiNavVolumeViewer *v3; // rsi
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

// File Line: 33
// RVA: 0xC44C80
void __fastcall hkaiNavVolumeViewer::~hkaiNavVolumeViewer(hkaiNavVolumeViewer *this)
{
  bool v1; // zf
  hkaiNavVolumeViewer *v2; // rbx
  int v3; // edi
  __int64 v4; // rsi
  hkaiViewerContext *v5; // rdx
  int v6; // eax

  v1 = this->m_navVolumeInfos.m_size == 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavVolumeViewer::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessVtbl *)&hkaiNavVolumeViewer::`vftable'{for `hkProcess'};
  v2 = this;
  this->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiNavVolumeViewer::`vftable'{for `hkaiViewerContextWorldListener'};
  this->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiNavVolumeViewer::`vftable';
  if ( !v1 )
  {
    do
      hkaiNavVolumeViewer::removeNavVolume(v2, v2->m_navVolumeInfos.m_data->m_navVolume);
    while ( v2->m_navVolumeInfos.m_size );
  }
  v3 = 0;
  if ( v2->m_context.m_pntr )
  {
    v4 = 0i64;
    do
    {
      v5 = v2->m_context.m_pntr;
      if ( v3 >= v5->m_worlds.m_size )
        break;
      hkaiNavVolumeViewer::worldRemovedCallback((hkaiNavVolumeViewer *)((char *)v2 + 64), v5->m_worlds.m_data[v4]);
      ++v3;
      ++v4;
    }
    while ( v2->m_context.m_pntr );
  }
  v6 = v2->m_navVolumeInfos.m_capacityAndFlags;
  v2->m_navVolumeInfos.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_navVolumeInfos.m_data,
      24 * (v6 & 0x3FFFFFFF));
  v2->m_navVolumeInfos.m_data = 0i64;
  v2->m_navVolumeInfos.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable';
  hkaiViewerBase::~hkaiViewerBase((hkaiViewerBase *)&v2->vfptr);
}

// File Line: 47
// RVA: 0xC44BC0
void __fastcall hkaiNavVolumeViewer::worldAddedCallback(hkaiNavVolumeViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiNavVolumeViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->vfptr);
}

// File Line: 52
// RVA: 0xC44BF0
void __fastcall hkaiNavVolumeViewer::worldRemovedCallback(hkaiNavVolumeViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiNavVolumeViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->vfptr);
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
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiNavVolumeViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiNavVolumeViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 112i64);
  if ( v3 && (hkaiNavVolumeViewer::hkaiNavVolumeViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 71
// RVA: 0xC449C0
void __fastcall hkaiNavVolumeViewer::postStepCallback(hkaiNavVolumeViewer *this, hkaiWorld *world, hkArrayBase<hkaiBehavior *> *behaviors)
{
  hkaiWorld *v3; // rsi
  hkaiNavVolumeViewer *v4; // rbp
  int v5; // er15
  int v6; // ebx
  __int64 v7; // rdi
  __int64 v8; // rax
  hkaiStreamingCollection *v9; // rax
  signed __int64 v10; // rcx
  hkaiWorld **v11; // rax
  hkaiStreamingCollection *v12; // rax
  int v13; // ebx
  __int64 v14; // rdi
  signed __int64 v15; // rcx
  hkaiWorld **v16; // rax
  __int64 v17; // rax
  __int64 v18; // r14
  hkaiWorld::ListenerVtbl *v19; // rdi
  __int64 v20; // rbx
  void *(__fastcall *v21)(hkaiWorld::Listener *, unsigned int); // rsi
  __int64 v22[2]; // [rsp+20h] [rbp-78h]
  __m128 v23; // [rsp+30h] [rbp-68h]
  __m128 v24; // [rsp+40h] [rbp-58h]
  __m128 v25; // [rsp+50h] [rbp-48h]
  __int128 v26; // [rsp+60h] [rbp-38h]
  char v27; // [rsp+A0h] [rbp+8h]

  v3 = world;
  v4 = this;
  if ( *(_QWORD *)&this[-1].m_counter )
  {
    v5 = 0;
    v6 = 0;
    if ( SLODWORD(this->vfptr) > 0 )
    {
      v7 = 0i64;
      do
      {
        v8 = *(_QWORD *)&v4->m_memSizeAndFlags;
        if ( *(hkaiWorld **)(v7 + v8 + 16) == v3 )
        {
          world = *(hkaiWorld **)(v7 + v8);
          v9 = v3->m_streamingCollection.m_pntr;
          v10 = 0i64;
          behaviors = (hkArrayBase<hkaiBehavior *> *)v9->m_instances.m_size;
          if ( (signed __int64)behaviors <= 0 )
          {
LABEL_9:
            hkaiNavVolumeViewer::removeNavVolume(
              (hkaiNavVolumeViewer *)((char *)v4 - 80),
              (hkaiNavVolumeInstance *)world);
            --v6;
            v7 -= 24i64;
          }
          else
          {
            v11 = (hkaiWorld **)&v9->m_instances.m_data->m_volumeInstancePtr;
            while ( world != *v11 )
            {
              ++v10;
              v11 += 6;
              if ( v10 >= (signed __int64)behaviors )
                goto LABEL_9;
            }
          }
        }
        ++v6;
        v7 += 24i64;
      }
      while ( v6 < SLODWORD(v4->vfptr) );
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
          behaviors = (hkArrayBase<hkaiBehavior *> *)SLODWORD(v4->vfptr);
          v15 = 0i64;
          if ( (signed __int64)behaviors <= 0 )
          {
LABEL_18:
            hkaiNavVolumeViewer::addNavVolume(
              (hkaiNavVolumeViewer *)((char *)v4 - 80),
              (hkaiNavVolumeInstance *)world,
              v3);
          }
          else
          {
            v16 = *(hkaiWorld ***)&v4->m_memSizeAndFlags;
            while ( *v16 != world )
            {
              ++v15;
              v16 += 3;
              if ( v15 >= (signed __int64)behaviors )
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
    v17 = *(_QWORD *)&v4[-1].m_counter;
    v23 = transform.m_quad;
    v24 = direction.m_quad;
    v26 = 0i64;
    v25 = stru_141A71280.m_quad;
    v26 = *(_OWORD *)(v17 + 224);
    if ( SLODWORD(v4->vfptr) > 0 )
    {
      v18 = 0i64;
      do
      {
        v19 = v4[-1].vfptr;
        v20 = *(_QWORD *)&v4->m_memSizeAndFlags;
        v21 = v19->__vecDelDtor;
        LODWORD(v22[0]) = ((__int64 (__fastcall *)(hkDebugDisplayHandler **, hkaiWorld *, hkArrayBase<hkaiBehavior *> *))v4[-1].m_displayHandler[1].vfptr)(
                            &v4[-1].m_displayHandler,
                            world,
                            behaviors);
        (*((void (__fastcall **)(hkaiWorld::ListenerVtbl *, char *, __m128 *, _QWORD, __int64))v21 + 9))(
          v19,
          &v27,
          &v23,
          *(_QWORD *)(v20 + v18 + 8),
          v22[0]);
        ++v5;
        v18 += 24i64;
      }
      while ( v5 < SLODWORD(v4->vfptr) );
    }
  }
}v20 + v18 + 8),
          v22[0]);
   

// File Line: 143
// RVA: 0xC44D90
void __fastcall hkaiNavVolumeViewer::addNavVolume(hkaiNavVolumeViewer *this, hkaiNavVolumeInstance *navVolume, hkaiWorld *world)
{
  hkaiNavVolumeViewer *v3; // r13
  hkaiWorld *v4; // r12
  hkaiNavVolumeInstance *v5; // r14
  _QWORD **v6; // rax
  __int64 v7; // rax
  hkGeometry *v8; // rbx
  hkaiNavVolume *v9; // rdx
  _QWORD **v10; // rax
  hkDisplayConvex *v11; // rax
  hkReferencedObject *v12; // rax
  hkReferencedObject *v13; // r15
  unsigned int v14; // ecx
  hkaiViewerContext *v15; // rax
  char *v16; // rdi
  __int128 v17; // xmm0
  hkDebugDisplayHandler *v18; // rax
  hkDebugDisplayHandlerVtbl *v19; // rbx
  hkDebugDisplayHandlerVtbl *v20; // rdi
  int v21; // eax
  __int64 v22; // rsi
  __int64 v23; // ST20_8
  __int64 v24; // rdx
  hkaiNavVolumeViewer::NavVolumeInfo *v25; // r8
  hkaiNavVolumeDebugUtils::GeomteryBuildSettings buildSettings; // [rsp+40h] [rbp-A8h]
  __int64 *v27; // [rsp+50h] [rbp-98h]
  int v28; // [rsp+58h] [rbp-90h]
  int v29; // [rsp+5Ch] [rbp-8Ch]
  hkReferencedObject *v30; // [rsp+60h] [rbp-88h]
  __m128 v31; // [rsp+70h] [rbp-78h]
  __m128 v32; // [rsp+80h] [rbp-68h]
  __m128 v33; // [rsp+90h] [rbp-58h]
  __int128 v34; // [rsp+A0h] [rbp-48h]
  char v35; // [rsp+F0h] [rbp+8h]
  hkaiNavVolumeInstance *v36; // [rsp+F8h] [rbp+10h]

  v3 = this;
  v4 = world;
  v5 = navVolume;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 48i64);
  v8 = (hkGeometry *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)v7 = &hkGeometry::`vftable';
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_DWORD *)(v7 + 24) = 0;
    *(_DWORD *)(v7 + 28) = 2147483648;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_DWORD *)(v7 + 40) = 0;
    *(_DWORD *)(v7 + 44) = 2147483648;
  }
  else
  {
    v8 = 0i64;
  }
  hkaiNavVolumeDebugUtils::GeomteryBuildSettings::GeomteryBuildSettings(&buildSettings);
  v9 = v5->m_originalVolume.m_pntr;
  buildSettings.m_skipBoundingFaces = 0;
  hkaiNavVolumeDebugUtils::buildNavVolumeGeometry(&buildSettings, v9, v8);
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 112i64);
  if ( v11 )
  {
    hkDisplayConvex::hkDisplayConvex(v11, v8);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  v14 = v3->m_counter;
  v28 = 1;
  v27 = (__int64 *)&v30;
  v29 = -2147483647;
  v3->m_counter = v14 + 1;
  v15 = v3->m_context.m_pntr;
  v30 = v13;
  v31 = transform.m_quad;
  v32 = direction.m_quad;
  v16 = (char *)v5 + 2 * v14;
  v36 = (hkaiNavVolumeInstance *)((char *)v5 + 2 * v14);
  v34 = 0i64;
  v33 = stru_141A71280.m_quad;
  v17 = (__int128)v15->m_displayOffset;
  v18 = v3->m_displayHandler;
  v34 = v17;
  v19 = v18->vfptr;
  v3->vfptr->getProcessTag((hkProcess *)&v3->vfptr);
  (*(void (__fastcall **)(hkDebugDisplayHandler *, char *, __int64 **, __m128 *, char *))v19->gap8)(
    v3->m_displayHandler,
    &v35,
    &v27,
    &v31,
    v16);
  v20 = v3->m_displayHandler->vfptr;
  v21 = v3->vfptr->getProcessTag((hkProcess *)&v3->vfptr);
  v22 = (__int64)v36;
  LODWORD(v23) = v21;
  v20->setGeometryColor(v3->m_displayHandler, (hkResult *)&v35, hkColor::GREEN, (unsigned __int64)v36, v23);
  hkReferencedObject::removeReference(v13);
  if ( v3->m_navVolumeInfos.m_size == (v3->m_navVolumeInfos.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_navVolumeInfos, 24);
  v24 = v3->m_navVolumeInfos.m_size;
  v25 = &v3->m_navVolumeInfos.m_data[v24];
  v3->m_navVolumeInfos.m_size = v24 + 1;
  v25->m_id = v22;
  v25->m_navVolume = v5;
  v25->m_world = v4;
  v28 = 0;
  if ( v29 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v27,
      8 * v29);
  v27 = 0i64;
  v29 = 2147483648;
  if ( buildSettings.m_filter.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&buildSettings.m_filter.m_pntr->vfptr);
}

// File Line: 171
// RVA: 0xC45010
void __fastcall hkaiNavVolumeViewer::removeNavVolume(hkaiNavVolumeViewer *this, hkaiNavVolumeInstance *navVolume)
{
  __int64 v2; // r9
  int v3; // esi
  __int64 v4; // r8
  hkaiNavVolumeViewer *v5; // rbp
  hkaiNavVolumeViewer::NavVolumeInfo *v6; // r14
  hkaiNavVolumeViewer::NavVolumeInfo *v7; // rax
  hkDebugDisplayHandler *v8; // rbx
  hkDebugDisplayHandlerVtbl *v9; // rdi
  signed __int64 v10; // r15
  int v11; // eax
  __int64 v12; // rax
  hkaiNavVolumeViewer::NavVolumeInfo *v13; // rdx
  signed __int64 v14; // r8
  signed __int64 v15; // rax
  signed __int64 v16; // rdx
  signed __int64 v17; // r8
  __int64 v18; // rcx
  char v19; // [rsp+50h] [rbp+8h]

  v2 = this->m_navVolumeInfos.m_size;
  v3 = 0;
  v4 = 0i64;
  v5 = this;
  if ( v2 > 0 )
  {
    v6 = this->m_navVolumeInfos.m_data;
    v7 = this->m_navVolumeInfos.m_data;
    while ( navVolume != v7->m_navVolume )
    {
      ++v4;
      ++v3;
      ++v7;
      if ( v4 >= v2 )
        return;
    }
    v8 = this->m_displayHandler;
    v9 = v8->vfptr;
    v10 = v3;
    v11 = ((__int64 (__fastcall *)(hkProcessVtbl **, hkaiNavVolumeInstance *, __int64))this->vfptr->getProcessTag)(
            &this->vfptr,
            navVolume,
            v4);
    v9->removeGeometry(v8, (hkResult *)&v19, v6[v10].m_id, v11, 0i64);
    v12 = --v5->m_navVolumeInfos.m_size;
    if ( (_DWORD)v12 != v3 )
    {
      v13 = v5->m_navVolumeInfos.m_data;
      v14 = (signed __int64)&v13[v12];
      v15 = (signed __int64)&v13[v10];
      v16 = 3i64;
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

// File Line: 192
// RVA: 0xC44B80
void __fastcall hkaiNavVolumeViewer::navVolumeAdded(hkaiNavVolumeViewer *this, hkaiWorld *world, hkaiNavVolumeInstance *volume, hkaiNavVolumeMediator *mediator)
{
  hkaiNavVolumeViewer::addNavVolume((hkaiNavVolumeViewer *)((char *)this - 80), volume, world);
}

// File Line: 197
// RVA: 0xC44BA0
void __fastcall hkaiNavVolumeViewer::navVolumeRemoved(hkaiNavVolumeViewer *this, hkaiWorld *world, hkaiNavVolumeInstance *volume)
{
  hkaiNavVolumeViewer::removeNavVolume((hkaiNavVolumeViewer *)((char *)this - 80), volume);
}

