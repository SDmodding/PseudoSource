// File Line: 207
// RVA: 0x8A60A0
void __fastcall Scaleform::GFx::Movie::~Movie(Scaleform::GFx::Movie *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>};
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::GFx::StateBag};
  pObject = (Scaleform::Render::RenderBuffer *)this->pASMovieRoot.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 212
// RVA: 0x8D4BE0
__int64 __fastcall Scaleform::GFx::Movie::GetAVMVersion(Scaleform::GFx::Movie *this)
{
  return (unsigned __int8)this->pASMovieRoot.pObject->AVMVersion;
}

// File Line: 217
// RVA: 0x8E1520
__int64 __fastcall Scaleform::GFx::Movie::GetVariable(
        Scaleform::GFx::Movie *this,
        Scaleform::GFx::Value *pval,
        const char *ppathToVar)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::Value *, const char *))this->pASMovieRoot.pObject->vfptr[49].__vecDelDtor)(
           this->pASMovieRoot.pObject,
           pval,
           ppathToVar);
}

// File Line: 223
// RVA: 0x90E8B0
__int64 __fastcall Scaleform::GFx::Movie::SetVariable(
        Scaleform::GFx::Movie *this,
        const char *ppathToVar,
        Scaleform::GFx::Value *value,
        __int64 setType)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, const char *, Scaleform::GFx::Value *, __int64))this->pASMovieRoot.pObject->vfptr[48].__vecDelDtor)(
           this->pASMovieRoot.pObject,
           ppathToVar,
           value,
           setType);
}

// File Line: 255
// RVA: 0x8E6DE0
__int64 __fastcall Scaleform::GFx::Movie::Invoke(
        Scaleform::GFx::Movie *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        Scaleform::GFx::Value *pargs,
        unsigned int numArgs)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, const char *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))this->pASMovieRoot.pObject->vfptr[56].__vecDelDtor)(
           this->pASMovieRoot.pObject,
           pmethodName,
           presult,
           pargs);
}

// File Line: 261
// RVA: 0x8E6DB0
__int64 Scaleform::GFx::Movie::Invoke(
        Scaleform::GFx::Movie *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt,
        ...)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, const char *, Scaleform::GFx::Value *))this->pASMovieRoot.pObject->vfptr[57].__vecDelDtor)(
           this->pASMovieRoot.pObject,
           pmethodName,
           presult);
}

// File Line: 272
// RVA: 0x8E6DF0
__int64 __fastcall Scaleform::GFx::Movie::InvokeArgs(
        Scaleform::GFx::Movie *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt,
        char *args)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, const char *, Scaleform::GFx::Value *, const char *))this->pASMovieRoot.pObject->vfptr[57].__vecDelDtor)(
           this->pASMovieRoot.pObject,
           pmethodName,
           presult,
           pargFmt);
}

// File Line: 278
// RVA: 0x8C3AB0
void __fastcall Scaleform::GFx::Movie::CreateString(
        Scaleform::GFx::Movie *this,
        Scaleform::GFx::Value *pvalue,
        const char *pstring)
{
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::Value *, const char *))this->pASMovieRoot.pObject->vfptr[43].__vecDelDtor)(
    this->pASMovieRoot.pObject,
    pvalue,
    pstring);
}

// File Line: 305
// RVA: 0x907050
void __fastcall Scaleform::GFx::Movie::SetExternalInterfaceRetVal(
        Scaleform::GFx::Movie *this,
        Scaleform::GFx::Value *v)
{
  this->pASMovieRoot.pObject->vfptr[40].__vecDelDtor(this->pASMovieRoot.pObject, (unsigned int)v);
}

// File Line: 310
// RVA: 0x8FE630
void __fastcall Scaleform::GFx::Movie::Release(Scaleform::GFx::Movie *this)
{
  Scaleform::GFx::Resource *v2; // rax
  Scaleform::Render::RenderBuffer *v3; // rbx

  if ( !_InterlockedDecrement(&this->RefCount) )
  {
    v2 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->vfptr[58].__vecDelDtor)(this->pASMovieRoot.pObject);
    v3 = (Scaleform::Render::RenderBuffer *)v2;
    if ( v2 )
      Scaleform::Render::RenderBuffer::AddRef(v2);
    this->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      this,
      1i64);
    if ( v3 )
      Scaleform::RefCountImpl::Release(v3);
  }
}

// File Line: 409
// RVA: 0x89B3D0
void __fastcall Scaleform::GFx::MovieImpl::MovieImpl(Scaleform::GFx::MovieImpl *this, Scaleform::MemoryHeap *pheap)
{
  Scaleform::List<Scaleform::GFx::MovieDefRootNode,Scaleform::GFx::MovieDefRootNode> *p_RootMovieDefNodes; // rax
  bool v4; // zf
  Scaleform::ArrayDefaultPolicy *p_Policy; // rcx
  Scaleform::Render::RenderBuffer **p_hDisplayRoot; // r14
  unsigned __int64 *p_Size; // rax
  Scaleform::Render::TreeRoot::NodeData *v8; // rax
  Scaleform::Render::ContextImpl::EntryData *v9; // rdi
  Scaleform::Render::TreeRoot *EntryHelper; // rdi
  Scaleform::Render::TreeRoot *pObject; // rcx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v12; // rax
  Scaleform::Render::TreeContainer *v13; // rdi
  Scaleform::Render::TreeContainer *v14; // rcx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v15; // rax
  Scaleform::GFx::StateBagImpl *v16; // rax
  Scaleform::GFx::StateBagImpl *v17; // rdi
  Scaleform::Render::RenderBuffer *v18; // rcx
  char v19; // al
  char *p_KeyboardIndex; // rcx
  __int64 v21; // rdi
  Scaleform::GFx::StateBagImpl *v22; // rax
  Scaleform::GFx::StateBag *v23; // rax
  Scaleform::GFx::FontManagerStates *v24; // rcx
  Scaleform::Render::ContextImpl::RTHandle v25; // [rsp+88h] [rbp+48h] BYREF
  void *p_MovieLevels; // [rsp+90h] [rbp+50h]
  void *p_IntervalTimers; // [rsp+98h] [rbp+58h]

  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::`vftable;
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::`vftable;
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>};
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::GFx::StateBag};
  this->pASMovieRoot.pObject = 0i64;
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>};
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::MovieImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->AdvanceStats.pObject = 0i64;
  this->pHeap = pheap;
  this->pMainMovieDef.pObject = 0i64;
  p_MovieLevels = &this->MovieLevels;
  p_IntervalTimers = &this->MovieLevels;
  this->MovieLevels.Data.Data = 0i64;
  this->MovieLevels.Data.Size = 0i64;
  this->MovieLevels.Data.Policy.Capacity = 0i64;
  p_RootMovieDefNodes = &this->RootMovieDefNodes;
  v4 = &this->RootMovieDefNodes == 0i64;
  p_Policy = &this->MovieLevels.Data.Policy;
  if ( v4 )
    p_Policy = 0i64;
  p_RootMovieDefNodes->Root.pPrev = (Scaleform::GFx::MovieDefRootNode *)p_Policy;
  p_RootMovieDefNodes->Root.pNext = (Scaleform::GFx::MovieDefRootNode *)p_Policy;
  this->pStateBag.pObject = 0i64;
  this->pRenderRoot.pObject = 0i64;
  p_hDisplayRoot = (Scaleform::Render::RenderBuffer **)&this->hDisplayRoot;
  p_MovieLevels = &this->hDisplayRoot;
  this->hDisplayRoot.pData.pObject = 0i64;
  this->pTopMostRoot.pObject = 0i64;
  *(_QWORD *)&this->mViewport.BufferWidth = 0i64;
  *(_QWORD *)&this->mViewport.Left = 0i64;
  this->mViewport.Height = 1;
  this->mViewport.Width = 1;
  *(_QWORD *)&this->mViewport.ScissorWidth = 0i64;
  *(_QWORD *)&this->mViewport.ScissorLeft = 0i64;
  this->mViewport.Flags = 0;
  this->mViewport.AspectRatio = 1.0;
  this->mViewport.Scale = 1.0;
  this->PixelScale = 1.0;
  *(_QWORD *)&this->VisibleFrameRect.x1 = 0i64;
  *(_QWORD *)&this->VisibleFrameRect.x2 = 0i64;
  *(_QWORD *)&this->SafeRect.x1 = 0i64;
  *(_QWORD *)&this->SafeRect.x2 = 0i64;
  *(_QWORD *)&this->ViewportMatrix.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->ViewportMatrix.M[0][2] = 0i64;
  this->ViewportMatrix.M[1][0] = 0.0;
  *(_QWORD *)&this->ViewportMatrix.M[1][1] = 1065353216i64;
  this->ViewportMatrix.M[1][3] = 0.0;
  Scaleform::Render::ScreenToWorld::ScreenToWorld(&this->ScreenToWorld);
  this->pCachedLog.pObject = 0i64;
  this->pUserEventHandler.pObject = 0i64;
  this->pFSCommandHandler.pObject = 0i64;
  this->pExtIntfHandler.pObject = 0i64;
  this->pFontManagerStates.pObject = 0i64;
  this->pXMLObjectManager = 0i64;
  this->InputEventsQueue.StartPos = 0i64;
  this->InputEventsQueue.UsedEntries = 0i64;
  this->InputEventsQueue.LastMousePosMask = 0;
  *(_WORD *)&this->BackgroundColor.Channels.Green = 0;
  this->BackgroundColor.Channels.Blue = 0;
  this->BackgroundColor.Channels.Alpha = -1;
  `eh vector constructor iterator(
    this->mMouseState,
    0x50ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::MouseState::MouseState);
  this->MouseCursorCount = 1;
  this->ControllerCount = 1;
  this->UserData = 0i64;
  `eh vector constructor iterator(
    this->KeyboardStates,
    0x688ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::KeyboardState::KeyboardState);
  this->CurrentDragStates[0].pCharacter = 0i64;
  this->CurrentDragStates[0].pTopmostEntity = 0i64;
  *(_WORD *)&this->CurrentDragStates[0].LockCenter = 0;
  this->CurrentDragStates[0].BoundLT = 0i64;
  this->CurrentDragStates[0].BoundRB = 0i64;
  this->CurrentDragStates[0].CenterDelta = 0i64;
  this->CurrentDragStates[0].MouseIndex = -1;
  this->CurrentDragStates[1].pCharacter = 0i64;
  this->CurrentDragStates[1].pTopmostEntity = 0i64;
  *(_WORD *)&this->CurrentDragStates[1].LockCenter = 0;
  this->CurrentDragStates[1].BoundLT = 0i64;
  this->CurrentDragStates[1].BoundRB = 0i64;
  this->CurrentDragStates[1].CenterDelta = 0i64;
  this->CurrentDragStates[1].MouseIndex = -1;
  this->CurrentDragStates[2].pCharacter = 0i64;
  this->CurrentDragStates[2].pTopmostEntity = 0i64;
  *(_WORD *)&this->CurrentDragStates[2].LockCenter = 0;
  this->CurrentDragStates[2].BoundLT = 0i64;
  this->CurrentDragStates[2].BoundRB = 0i64;
  this->CurrentDragStates[2].CenterDelta = 0i64;
  this->CurrentDragStates[2].MouseIndex = -1;
  this->CurrentDragStates[3].pCharacter = 0i64;
  this->CurrentDragStates[3].pTopmostEntity = 0i64;
  *(_WORD *)&this->CurrentDragStates[3].LockCenter = 0;
  this->CurrentDragStates[3].BoundLT = 0i64;
  this->CurrentDragStates[3].BoundRB = 0i64;
  this->CurrentDragStates[3].CenterDelta = 0i64;
  this->CurrentDragStates[3].MouseIndex = -1;
  this->CurrentDragStates[4].pCharacter = 0i64;
  this->CurrentDragStates[4].pTopmostEntity = 0i64;
  *(_WORD *)&this->CurrentDragStates[4].LockCenter = 0;
  this->CurrentDragStates[4].BoundLT = 0i64;
  this->CurrentDragStates[4].BoundRB = 0i64;
  this->CurrentDragStates[4].CenterDelta = 0i64;
  this->CurrentDragStates[4].MouseIndex = -1;
  this->CurrentDragStates[5].pCharacter = 0i64;
  this->CurrentDragStates[5].pTopmostEntity = 0i64;
  *(_WORD *)&this->CurrentDragStates[5].LockCenter = 0;
  this->CurrentDragStates[5].BoundLT = 0i64;
  this->CurrentDragStates[5].BoundRB = 0i64;
  this->CurrentDragStates[5].CenterDelta = 0i64;
  this->CurrentDragStates[5].MouseIndex = -1;
  this->StickyVariables.mHash.pTable = 0i64;
  this->TopmostLevelCharacters.Data.Data = 0i64;
  this->TopmostLevelCharacters.Data.Size = 0i64;
  this->TopmostLevelCharacters.Data.Policy.Capacity = 0i64;
  p_MovieLevels = &this->IntervalTimers;
  p_IntervalTimers = &this->IntervalTimers;
  this->IntervalTimers.Data.Data = 0i64;
  this->IntervalTimers.Data.Size = 0i64;
  this->IntervalTimers.Data.Policy.Capacity = 0i64;
  this->FocusRectContainerNode.pObject = 0i64;
  `eh vector constructor iterator(
    this->FocusGroups,
    0x60ui64,
    16,
    (void (__fastcall *)(void *))Scaleform::GFx::FocusGroupDescr::`default constructor closure);
  *(_QWORD *)&this->Flags = 0i64;
  p_MovieLevels = &this->RegisteredFonts;
  p_IntervalTimers = &this->RegisteredFonts;
  this->RegisteredFonts.Data.Data = 0i64;
  this->RegisteredFonts.Data.Size = 0i64;
  this->RegisteredFonts.Data.Policy.Capacity = 0i64;
  p_Size = &this->RegisteredFonts.Data.Size;
  if ( this == (Scaleform::GFx::MovieImpl *)-21248i64 )
    p_Size = 0i64;
  this->DrawingContextList.Root.pPrev = (Scaleform::GFx::DrawingContext *)p_Size;
  this->DrawingContextList.Root.pNext = (Scaleform::GFx::DrawingContext *)p_Size;
  p_MovieLevels = &this->MovieDefKillList;
  p_IntervalTimers = &this->MovieDefKillList;
  this->MovieDefKillList.Data.Data = 0i64;
  this->MovieDefKillList.Data.Size = 0i64;
  this->MovieDefKillList.Data.Policy.Capacity = 0i64;
  this->pSavedASMovieRoot.pObject = 0i64;
  Scaleform::Render::ContextImpl::Context::Context(&this->RenderContext, Scaleform::Memory::pGlobalHeap);
  this->DIContext.pObject = 0i64;
  this->pRTCommandQueue = 0i64;
  this->MultitouchHAL.pObject = 0i64;
  this->GestureTopMostChar.pObject = 0i64;
  p_MovieLevels = &this->IndirectTransformPairs;
  p_IntervalTimers = &this->IndirectTransformPairs;
  this->IndirectTransformPairs.Data.Data = 0i64;
  this->IndirectTransformPairs.Data.Size = 0i64;
  this->IndirectTransformPairs.Data.Policy.Capacity = 0i64;
  v8 = (Scaleform::Render::TreeRoot::NodeData *)this->RenderContext.pHeap->vfptr->Alloc(
                                                  this->RenderContext.pHeap,
                                                  208i64,
                                                  0i64);
  v9 = v8;
  p_MovieLevels = v8;
  p_IntervalTimers = v8;
  if ( v8 )
    Scaleform::Render::TreeRoot::NodeData::NodeData(v8);
  EntryHelper = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::Context::createEntryHelper(
                                                 &this->RenderContext,
                                                 v9);
  pObject = this->pRenderRoot.pObject;
  if ( pObject )
  {
    v4 = pObject->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->pRenderRoot.pObject = EntryHelper;
  Scaleform::Render::ContextImpl::RTHandle::RTHandle(&v25, EntryHelper);
  v12 = v25.pData.pObject;
  if ( v25.pData.pObject )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v25.pData.pObject);
    v12 = v25.pData.pObject;
  }
  if ( *p_hDisplayRoot )
  {
    Scaleform::RefCountImpl::Release(*p_hDisplayRoot);
    v12 = v25.pData.pObject;
  }
  *p_hDisplayRoot = (Scaleform::Render::RenderBuffer *)v12;
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v25);
  v13 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&this->RenderContext);
  v14 = this->pTopMostRoot.pObject;
  if ( v14 )
  {
    v4 = v14->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v14);
  }
  this->pTopMostRoot.pObject = v13;
  Scaleform::Render::TreeContainer::Add(this->pRenderRoot.pObject, v13);
  Scaleform::Render::ContextImpl::Context::Capture(&this->RenderContext);
  this->pMainMovie = 0i64;
  this->Flags |= 0x40180u;
  this->pPlayListOptHead = 0i64;
  this->pPlayListHead = 0i64;
  this->TimeElapsed = 0i64;
  this->TimeRemainder = 0.0;
  *(_QWORD *)&this->FrameTime = 1034594987i64;
  this->pLoadQueueHead = 0i64;
  this->pLoadQueueMTHead = 0i64;
  v15 = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                                                  this->pHeap,
                                                                  88i64);
  v25.pData.pObject = v15;
  if ( v15 )
  {
    Scaleform::GFx::StateBagImpl::StateBagImpl((Scaleform::GFx::StateBagImpl *)v15, 0i64);
    v17 = v16;
  }
  else
  {
    v17 = 0i64;
  }
  v18 = (Scaleform::Render::RenderBuffer *)this->pStateBag.pObject;
  if ( v18 )
    Scaleform::RefCountImpl::Release(v18);
  this->pStateBag.pObject = v17;
  v19 = 0;
  p_KeyboardIndex = &this->KeyboardStates[0].KeyboardIndex;
  do
  {
    *p_KeyboardIndex = v19++;
    p_KeyboardIndex += 1672;
  }
  while ( (unsigned __int8)v19 < 6u );
  this->pRetValHolder = 0i64;
  v21 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(this->pHeap, 64i64);
  v25.pData.pObject = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v21;
  if ( v21 )
  {
    v22 = this->pStateBag.pObject;
    if ( v22 )
      v23 = &v22->Scaleform::GFx::StateBag;
    else
      v23 = 0i64;
    *(_QWORD *)v21 = &Scaleform::RefCountNTSImplCore::`vftable;
    *(_DWORD *)(v21 + 8) = 1;
    *(_QWORD *)v21 = &Scaleform::RefCountNTSImpl::`vftable;
    *(_QWORD *)v21 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,327>::`vftable;
    *(_QWORD *)v21 = &Scaleform::RefCountBaseNTS<Scaleform::GFx::FontManagerStates,327>::`vftable;
    *(_QWORD *)(v21 + 16) = &Scaleform::GFx::StateBag::`vftable;
    *(_QWORD *)v21 = &Scaleform::GFx::FontManagerStates::`vftable{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::FontManagerStates,327>};
    *(_QWORD *)(v21 + 16) = &Scaleform::GFx::FontManagerStates::`vftable{for `Scaleform::GFx::StateBag};
    *(_QWORD *)(v21 + 24) = 0i64;
    *(_QWORD *)(v21 + 32) = 0i64;
    *(_QWORD *)(v21 + 40) = 0i64;
    *(_QWORD *)(v21 + 48) = 0i64;
    *(_QWORD *)(v21 + 56) = v23;
  }
  else
  {
    v21 = 0i64;
  }
  v24 = this->pFontManagerStates.pObject;
  if ( v24 )
    Scaleform::RefCountNTSImpl::Release(v24);
  this->pFontManagerStates.pObject = (Scaleform::GFx::FontManagerStates *)v21;
  this->InstanceNameCount = 0;
  this->ViewScaleX = 1.0;
  *(_QWORD *)&this->ViewScaleY = 1065353216i64;
  this->ViewOffsetY = 0.0;
  *(_QWORD *)&this->ViewScaleMode = 1i64;
  this->FocusGroupsCnt = 1;
  *(_QWORD *)this->FocusGroupIndexes = 0i64;
  *(_QWORD *)&this->FocusGroupIndexes[8] = 0i64;
  this->LastIntervalTimerId = 0;
  this->pIMECandidateListStyle = 0i64;
  this->StartTickMs = Scaleform::Timer::GetTicks() / 0x3E8;
  this->PauseTickMs = 0i64;
  *(_QWORD *)&this->SafeRect.x1 = 0i64;
  *(_QWORD *)&this->SafeRect.x2 = 0i64;
  this->pObjectInterface = 0i64;
  this->LastLoadQueueEntryCnt = 0;
  this->pUnloadListHead = 0i64;
  this->MultitouchMode = MTI_None;
  this->FocusRectChanged = 1;
  this->PreviouslyCaptured = 0;
}

// File Line: 544
// RVA: 0x8A66B0
void __fastcall Scaleform::GFx::MovieImpl::~MovieImpl(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::Render::TreeContainer *pObject; // rbx
  __int64 Size; // rax
  unsigned int i; // ebx
  __int64 v5; // rsi
  Scaleform::Render::TreeShape *v6; // rcx
  bool v7; // zf
  Scaleform::Render::TreeContainer *v8; // rcx
  Scaleform::GFx::DrawingContext *j; // rcx
  unsigned __int64 *p_Size; // rax
  Scaleform::GFx::DrawingContext *pNext; // rax
  unsigned __int64 *v12; // rax
  Scaleform::Render::TreeRoot *v13; // rcx
  Scaleform::GFx::FontManagerStates *v14; // rcx
  unsigned __int64 v15; // rbx
  unsigned __int64 v16; // rsi
  Scaleform::GFx::ASIntervalTimerIntf *v17; // rcx
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327,Scaleform::ArrayDefaultPolicy> *p_IntervalTimers; // r13
  Scaleform::GFx::MovieImpl::ReturnValueHolder *pRetValHolder; // rbx
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // rcx
  unsigned int v21; // ebp
  unsigned int v22; // esi
  Scaleform::GFx::LoadQueueEntryMT *k; // rbx
  Scaleform::GFx::LoadQueueEntry *pLoadQueueHead; // rcx
  Scaleform::GFx::LoadQueueEntryMT *v25; // rcx
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // rbx
  Scaleform::List<Scaleform::GFx::Value,Scaleform::GFx::Value> *p_ExternalObjRefs; // rax
  Scaleform::GFx::Value *v28; // rbx
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *p_TopmostLevelCharacters; // r15
  Scaleform::GFx::Value::ObjectInterface *v30; // rcx
  Scaleform::Render::RenderBuffer *v31; // rcx
  Scaleform::Render::TreeContainer *v32; // rcx
  Scaleform::Render::RenderBuffer *v33; // rcx
  unsigned __int64 v34; // rsi
  Scaleform::GFx::MovieImpl::IndirectTransPair *m; // rbx
  Scaleform::RefCountNTSImpl *v36; // rcx
  Scaleform::RefCountNTSImpl *v37; // rcx
  Scaleform::Render::ContextImpl::Entry *v38; // rcx
  Scaleform::GFx::InteractiveObject *v39; // rcx
  Scaleform::Render::RenderBuffer *v40; // rcx
  Scaleform::Render::RenderBuffer *v41; // rcx
  Scaleform::Render::RenderBuffer *v42; // rcx
  unsigned __int64 v43; // rsi
  Scaleform::GFx::MovieImpl::FontDesc *n; // rbx
  Scaleform::Render::TreeContainer *v45; // rcx
  unsigned __int64 v46; // rsi
  Scaleform::Render::RenderBuffer **ii; // rbx
  unsigned __int64 v48; // rsi
  Scaleform::RefCountNTSImpl **jj; // rbx
  Scaleform::GFx::FontManagerStates *v50; // rcx
  Scaleform::Render::RenderBuffer *v51; // rcx
  Scaleform::Render::RenderBuffer *v52; // rcx
  Scaleform::Render::RenderBuffer *v53; // rcx
  Scaleform::Render::RenderBuffer *v54; // rcx
  Scaleform::Render::TreeContainer *v55; // rcx
  Scaleform::Render::TreeRoot *v56; // rcx
  Scaleform::Render::RenderBuffer *v57; // rcx
  unsigned __int64 v58; // rsi
  Scaleform::GFx::MovieImpl::LevelInfo *kk; // rbx
  Scaleform::RefCountNTSImpl *v60; // rcx
  Scaleform::GFx::MovieDefImpl *v61; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::Render::RenderBuffer *v63; // rcx
  Scaleform::Render::RenderBuffer *v64; // rcx

  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>};
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::MovieImpl::`vftable{for `Scaleform::GFx::StateBag};
  pObject = this->FocusRectContainerNode.pObject;
  if ( pObject )
  {
    Size = Scaleform::Render::TreeContainer::GetSize(this->FocusRectContainerNode.pObject);
    Scaleform::Render::TreeContainer::Remove(pObject, 0i64, Size);
    for ( i = 0; i < this->FocusGroupsCnt; ++i )
    {
      v5 = i;
      v6 = this->FocusGroups[v5].FocusRectNode.pObject;
      if ( v6 )
      {
        v7 = v6->RefCount-- == 1;
        if ( v7 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v6);
      }
      this->FocusGroups[v5].FocusRectNode.pObject = 0i64;
    }
    v8 = this->FocusRectContainerNode.pObject;
    if ( v8 )
    {
      v7 = v8->RefCount-- == 1;
      if ( v7 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
    }
    this->FocusRectContainerNode.pObject = 0i64;
  }
  for ( j = this->DrawingContextList.Root.pNext; ; j = pNext )
  {
    p_Size = &this->RegisteredFonts.Data.Size;
    if ( this == (Scaleform::GFx::MovieImpl *)-21248i64 )
      p_Size = 0i64;
    if ( j == (Scaleform::GFx::DrawingContext *)p_Size )
      break;
    pNext = j->pNext;
    j->pNext = 0i64;
    j->pPrev = 0i64;
  }
  v12 = &this->RegisteredFonts.Data.Size;
  if ( this == (Scaleform::GFx::MovieImpl *)-21248i64 )
    v12 = 0i64;
  this->DrawingContextList.Root.pPrev = (Scaleform::GFx::DrawingContext *)v12;
  this->DrawingContextList.Root.pNext = (Scaleform::GFx::DrawingContext *)v12;
  Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
  v13 = this->pRenderRoot.pObject;
  if ( v13 )
  {
    v7 = v13->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v13);
  }
  this->pRenderRoot.pObject = 0i64;
  v14 = this->pFontManagerStates.pObject;
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release(v14);
  this->pFontManagerStates.pObject = 0i64;
  v15 = 0i64;
  v16 = this->IntervalTimers.Data.Size;
  if ( v16 )
  {
    do
    {
      v17 = this->IntervalTimers.Data.Data[v15].pObject;
      ((void (__fastcall *)(Scaleform::GFx::ASIntervalTimerIntf *))v17->vfptr[4].__vecDelDtor)(v17);
      ++v15;
    }
    while ( v15 < v16 );
  }
  p_IntervalTimers = &this->IntervalTimers;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->IntervalTimers.Data,
    &this->IntervalTimers,
    0i64);
  this->Flags |= 0x80000u;
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[5].__vecDelDtor)(this->pASMovieRoot.pObject);
  Scaleform::GFx::MovieImpl::ClearIndirectTransformPairs(this);
  Scaleform::GFx::MovieImpl::ClearStickyVariables(this);
  pRetValHolder = this->pRetValHolder;
  if ( pRetValHolder )
  {
    if ( pRetValHolder->CharBuffer )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(&pRetValHolder->StringArray.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pRetValHolder);
  }
  pLoadQueueMTHead = this->pLoadQueueMTHead;
  v21 = 0;
  if ( pLoadQueueMTHead )
  {
    do
    {
      ++v21;
      pLoadQueueMTHead->pQueueEntry->Canceled = 1;
      pLoadQueueMTHead = pLoadQueueMTHead->pNext;
    }
    while ( pLoadQueueMTHead );
    if ( v21 )
    {
      do
      {
        v22 = 0;
        for ( k = this->pLoadQueueMTHead; k; k = k->pNext )
        {
          if ( k->vfptr->LoadFinished(k) )
            ++v22;
        }
      }
      while ( v21 > v22 );
    }
  }
  while ( this->pLoadQueueHead )
  {
    pLoadQueueHead = this->pLoadQueueHead;
    this->pLoadQueueHead = pLoadQueueHead->pNext;
    pLoadQueueHead->vfptr->__vecDelDtor(pLoadQueueHead, 1u);
  }
  while ( this->pLoadQueueMTHead )
  {
    v25 = this->pLoadQueueMTHead;
    this->pLoadQueueMTHead = v25->pNext;
    v25->vfptr->__vecDelDtor(v25, 1u);
  }
  pObjectInterface = this->pObjectInterface;
  if ( pObjectInterface )
  {
    p_ExternalObjRefs = &pObjectInterface->ExternalObjRefs;
    if ( (Scaleform::List<Scaleform::GFx::Value,Scaleform::GFx::Value> *)pObjectInterface->ExternalObjRefs.Root.pNext != &pObjectInterface->ExternalObjRefs )
    {
      v28 = pObjectInterface->ExternalObjRefs.Root.pNext;
      if ( v28 != (Scaleform::GFx::Value *)p_ExternalObjRefs )
      {
        do
        {
          if ( (v28->Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v28->pObjectInterface->vfptr->gap8[8])(
              v28->pObjectInterface,
              v28,
              v28->mValue);
            v28->pObjectInterface = 0i64;
          }
          v28->Type = 32;
          v28 = v28->pNext;
        }
        while ( v28 != (Scaleform::GFx::Value *)&this->pObjectInterface->ExternalObjRefs );
      }
    }
  }
  p_TopmostLevelCharacters = &this->TopmostLevelCharacters;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&this->TopmostLevelCharacters,
    &this->TopmostLevelCharacters,
    0i64);
  v30 = this->pObjectInterface;
  if ( v30 )
    v30->vfptr->__vecDelDtor(v30, 1u);
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[42].__vecDelDtor)(this->pASMovieRoot.pObject);
  v31 = (Scaleform::Render::RenderBuffer *)this->pASMovieRoot.pObject;
  if ( v31 )
    Scaleform::RefCountImpl::Release(v31);
  this->pASMovieRoot.pObject = 0i64;
  v32 = this->pTopMostRoot.pObject;
  if ( v32 )
  {
    v7 = v32->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v32);
  }
  this->pTopMostRoot.pObject = 0i64;
  Scaleform::Render::ContextImpl::Context::Shutdown(&this->RenderContext, 1);
  v33 = (Scaleform::Render::RenderBuffer *)this->hDisplayRoot.pData.pObject;
  if ( v33 )
    Scaleform::RefCountImpl::Release(v33);
  this->hDisplayRoot.pData.pObject = 0i64;
  v34 = this->IndirectTransformPairs.Data.Size;
  for ( m = &this->IndirectTransformPairs.Data.Data[v34 - 1]; v34; --v34 )
  {
    v36 = m->OriginalParent.pObject;
    if ( v36 )
      Scaleform::RefCountNTSImpl::Release(v36);
    v37 = m->Obj.pObject;
    if ( v37 )
      Scaleform::RefCountNTSImpl::Release(v37);
    v38 = m->TransformParent.pObject;
    if ( m->TransformParent.pObject )
    {
      v7 = v38->RefCount-- == 1;
      if ( v7 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v38);
    }
    --m;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->IndirectTransformPairs.Data.Data);
  v39 = this->GestureTopMostChar.pObject;
  if ( v39 )
    Scaleform::RefCountNTSImpl::Release(v39);
  v40 = (Scaleform::Render::RenderBuffer *)this->MultitouchHAL.pObject;
  if ( v40 )
    Scaleform::RefCountImpl::Release(v40);
  v41 = (Scaleform::Render::RenderBuffer *)this->DIContext.pObject;
  if ( v41 )
    Scaleform::RefCountImpl::Release(v41);
  Scaleform::Render::ContextImpl::Context::~Context(&this->RenderContext);
  v42 = (Scaleform::Render::RenderBuffer *)this->pSavedASMovieRoot.pObject;
  if ( v42 )
    Scaleform::RefCountImpl::Release(v42);
  Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::MDKillListEntry>::DestructArray(
    this->MovieDefKillList.Data.Data,
    this->MovieDefKillList.Data.Size);
  if ( this->MovieDefKillList.Data.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v43 = this->RegisteredFonts.Data.Size;
  for ( n = &this->RegisteredFonts.Data.Data[v43 - 1]; v43; --v43 )
    Scaleform::GFx::MovieImpl::FontDesc::~FontDesc(n--);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->RegisteredFonts.Data.Data);
  `eh vector destructor iterator(
    this->FocusGroups,
    0x60ui64,
    16,
    (void (__fastcall *)(void *))Scaleform::GFx::FocusGroupDescr::~FocusGroupDescr);
  v45 = this->FocusRectContainerNode.pObject;
  if ( v45 )
  {
    v7 = v45->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v45);
  }
  v46 = this->IntervalTimers.Data.Size;
  for ( ii = (Scaleform::Render::RenderBuffer **)&p_IntervalTimers->Data.Data[v46 - 1]; v46; --v46 )
  {
    if ( *ii )
      Scaleform::RefCountImpl::Release(*ii);
    --ii;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_IntervalTimers->Data.Data);
  v48 = this->TopmostLevelCharacters.Data.Size;
  for ( jj = &p_TopmostLevelCharacters->Data.Data[v48 - 1].pObject; v48; --v48 )
  {
    if ( *jj )
      Scaleform::RefCountNTSImpl::Release(*jj);
    --jj;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_TopmostLevelCharacters->Data.Data);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&this->StickyVariables.mHash);
  `eh vector destructor iterator(
    this->KeyboardStates,
    0x688ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::File::~File);
  `eh vector destructor iterator(
    this->mMouseState,
    0x50ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::MouseState::~MouseState);
  v50 = this->pFontManagerStates.pObject;
  if ( v50 )
    Scaleform::RefCountNTSImpl::Release(v50);
  v51 = (Scaleform::Render::RenderBuffer *)this->pExtIntfHandler.pObject;
  if ( v51 )
    Scaleform::RefCountImpl::Release(v51);
  v52 = (Scaleform::Render::RenderBuffer *)this->pFSCommandHandler.pObject;
  if ( v52 )
    Scaleform::RefCountImpl::Release(v52);
  v53 = (Scaleform::Render::RenderBuffer *)this->pUserEventHandler.pObject;
  if ( v53 )
    Scaleform::RefCountImpl::Release(v53);
  v54 = (Scaleform::Render::RenderBuffer *)this->pCachedLog.pObject;
  if ( v54 )
    Scaleform::RefCountImpl::Release(v54);
  v55 = this->pTopMostRoot.pObject;
  if ( v55 )
  {
    v7 = v55->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v55);
  }
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&this->hDisplayRoot);
  v56 = this->pRenderRoot.pObject;
  if ( v56 )
  {
    v7 = v56->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v56);
  }
  v57 = (Scaleform::Render::RenderBuffer *)this->pStateBag.pObject;
  if ( v57 )
    Scaleform::RefCountImpl::Release(v57);
  v58 = this->MovieLevels.Data.Size;
  for ( kk = &this->MovieLevels.Data.Data[v58 - 1]; v58; --v58 )
  {
    v60 = kk->pSprite.pObject;
    if ( v60 )
      Scaleform::RefCountNTSImpl::Release(v60);
    --kk;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->MovieLevels.Data.Data);
  v61 = this->pMainMovieDef.pObject;
  if ( v61 && !_InterlockedDecrement(&v61->RefCount.Value) )
  {
    pLib = v61->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v61);
      v61->pLib = 0i64;
    }
    v61->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v61, 1u);
  }
  v63 = (Scaleform::Render::RenderBuffer *)this->AdvanceStats.pObject;
  if ( v63 )
    Scaleform::RefCountImpl::Release(v63);
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>};
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::GFx::StateBag};
  v64 = (Scaleform::Render::RenderBuffer *)this->pASMovieRoot.pObject;
  if ( v64 )
    Scaleform::RefCountImpl::Release(v64);
  this->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 723
// RVA: 0x8BC510
void __fastcall Scaleform::GFx::MovieImpl::ClearPlayList(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *pPlayListHead; // r8
  Scaleform::GFx::InteractiveObject *pPlayNext; // rdx

  pPlayListHead = this->pPlayListHead;
  if ( pPlayListHead )
  {
    do
    {
      pPlayNext = pPlayListHead->pPlayNext;
      pPlayListHead->pPlayPrevOpt = 0i64;
      pPlayListHead->pPlayNextOpt = 0i64;
      pPlayListHead->pPlayPrev = 0i64;
      pPlayListHead->pPlayNext = 0i64;
      pPlayListHead = pPlayNext;
    }
    while ( pPlayNext );
  }
  this->pPlayListHead = 0i64;
  this->pPlayListOptHead = 0i64;
}

// File Line: 734
// RVA: 0x906010
void __fastcall Scaleform::GFx::MovieImpl::SetASMovieRoot(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Resource *pasmgr)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx

  if ( pasmgr )
    Scaleform::Render::RenderBuffer::AddRef(pasmgr);
  pObject = (Scaleform::Render::RenderBuffer *)this->pSavedASMovieRoot.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pSavedASMovieRoot.pObject = (Scaleform::GFx::ASMovieRootBase *)pasmgr;
  if ( pasmgr )
    Scaleform::Render::RenderBuffer::AddRef(pasmgr);
  v5 = (Scaleform::Render::RenderBuffer *)this->pASMovieRoot.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  this->pASMovieRoot.pObject = this->pSavedASMovieRoot.pObject;
}

// File Line: 773
// RVA: 0x8B1AD0
void __fastcall Scaleform::GFx::MovieImpl::AddLoadQueueEntry(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::LoadQueueEntry *pentry)
{
  Scaleform::GFx::LoadQueueEntry *pLoadQueueHead; // r8
  __int64 p_pNext; // rax
  bool v4; // zf

  pentry->EntryTime = ++this->LastLoadQueueEntryCnt;
  pLoadQueueHead = this->pLoadQueueHead;
  if ( pLoadQueueHead )
  {
    p_pNext = (__int64)&pLoadQueueHead->pNext;
    if ( pLoadQueueHead->pNext )
    {
      do
      {
        pLoadQueueHead = *(Scaleform::GFx::LoadQueueEntry **)p_pNext;
        v4 = *(_QWORD *)(*(_QWORD *)p_pNext + 8i64) == 0i64;
        p_pNext = *(_QWORD *)p_pNext + 8i64;
      }
      while ( !v4 );
    }
    pLoadQueueHead->pNext = pentry;
  }
  else
  {
    this->pLoadQueueHead = pentry;
  }
}

// File Line: 792
// RVA: 0x8B1B10
void __fastcall Scaleform::GFx::MovieImpl::AddLoadQueueEntryMT(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::LoadQueueEntryMT *pentryMT)
{
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // r8
  __int64 p_pNext; // rax
  bool v4; // zf

  pentryMT->pQueueEntry->EntryTime = ++this->LastLoadQueueEntryCnt;
  pLoadQueueMTHead = this->pLoadQueueMTHead;
  if ( pLoadQueueMTHead )
  {
    p_pNext = (__int64)&pLoadQueueMTHead->pNext;
    if ( pLoadQueueMTHead->pNext )
    {
      do
      {
        pLoadQueueMTHead = *(Scaleform::GFx::LoadQueueEntryMT **)p_pNext;
        v4 = *(_QWORD *)(*(_QWORD *)p_pNext + 8i64) == 0i64;
        p_pNext = *(_QWORD *)p_pNext + 8i64;
      }
      while ( !v4 );
    }
    pLoadQueueMTHead->pNext = pentryMT;
    pentryMT->pPrev = pLoadQueueMTHead;
  }
  else
  {
    this->pLoadQueueMTHead = pentryMT;
  }
}

// File Line: 815
// RVA: 0x8C00B0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::MovieImpl::CreateImageMovieDef(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ImageResource *pimageResource,
        bool bilinear,
        const char *purl,
        Scaleform::Render::RenderBuffer *pls)
{
  __int64 v9; // rdi
  __int64 v10; // rbp
  Scaleform::Render::RenderBuffer *v11; // rsi
  Scaleform::GFx::LoadStates *v12; // r10
  Scaleform::GFx::StateBagImpl *pObject; // rcx
  Scaleform::GFx::ResourceLibBase **v14; // r8
  Scaleform::Render::RenderBuffer *v15; // rax
  Scaleform::MemoryHeap *pHeap; // r14
  Scaleform::MemoryHeap *v17; // rcx
  Scaleform::GFx::MovieDataDef *v18; // rax
  Scaleform::GFx::MovieDataDef *v19; // rax
  Scaleform::GFx::MovieDataDef *v20; // rbx
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *ImageCreator; // rbp
  Scaleform::Render::RenderBufferManager *pManager; // rax
  Scaleform::Log *vfptr; // rax
  bool v24; // bp
  Scaleform::GFx::MovieDefImpl *v25; // r10
  __int64 v26; // rax
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceLibBase *v28; // rcx
  Scaleform::GFx::ResourceKey result; // [rsp+70h] [rbp-38h] BYREF
  Scaleform::Render::RenderBuffer *v31; // [rsp+B8h] [rbp+10h]

  v9 = 0i64;
  v10 = 0i64;
  v31 = 0i64;
  v11 = pls;
  if ( !pls )
  {
    v12 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          144i64,
                                          0i64);
    pls = (Scaleform::Render::RenderBuffer *)v12;
    if ( v12 )
    {
      pObject = this->pStateBag.pObject;
      v14 = (Scaleform::GFx::ResourceLibBase **)&pObject->Scaleform::GFx::StateBag;
      if ( !pObject )
        v14 = 0i64;
      Scaleform::GFx::LoadStates::LoadStates(
        v12,
        (Scaleform::GFx::Resource *)this->pMainMovieDef.pObject->pLoaderImpl.pObject,
        v14,
        0i64);
      v11 = v15;
    }
    else
    {
      v11 = 0i64;
    }
    v31 = v11;
  }
  if ( !pimageResource )
    goto LABEL_40;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(&result, purl, 0i64, 0i64, 0i64);
  pHeap = this->pHeap;
  v17 = Scaleform::Memory::pGlobalHeap;
  if ( pHeap )
    v17 = this->pHeap;
  pls = (Scaleform::Render::RenderBuffer *)v17;
  v18 = (Scaleform::GFx::MovieDataDef *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v17->vfptr->Alloc)(
                                          v17,
                                          72i64);
  if ( v18 )
  {
    Scaleform::GFx::MovieDataDef::MovieDataDef(v18, &result, MT_Image, purl, pHeap, 0, 0i64);
    v20 = v19;
  }
  else
  {
    v20 = 0i64;
  }
  if ( v20 )
  {
    ImageCreator = Scaleform::GFx::StateBag::GetImageCreator(
                     &this->Scaleform::GFx::StateBag,
                     (Scaleform::Ptr<Scaleform::GFx::ImageCreator> *)&pls);
    pManager = v11->pManager;
    if ( pManager )
    {
      vfptr = (Scaleform::Log *)pManager[2].vfptr;
      if ( !vfptr )
        vfptr = Scaleform::Log::GetGlobalLog();
    }
    else
    {
      vfptr = 0i64;
    }
    v24 = !Scaleform::GFx::MovieDataDef::LoadTaskData::InitImageFileMovieDef(
             v20->pData.pObject,
             0,
             pimageResource,
             ImageCreator->pObject,
             vfptr,
             bilinear);
    if ( pls )
      Scaleform::RefCountImpl::Release(pls);
    if ( !v24 )
    {
      Scaleform::String::operator=(
        (Scaleform::String *)&v11[2].RefCount,
        (const char *)((v20->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( !Scaleform::GFx::URLBuilder::ExtractFilePath((Scaleform::String *)&v11[2].RefCount) )
        Scaleform::String::Clear((Scaleform::String *)&v11[2].RefCount);
      v25 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pHeap->vfptr->Alloc)(
                                              pHeap,
                                              112i64);
      if ( v25 )
      {
        Scaleform::GFx::MovieDefImpl::MovieDefImpl(
          v25,
          v20,
          *(Scaleform::GFx::Resource **)&v11->Type,
          (Scaleform::GFx::Resource *)v11[2].vfptr,
          0,
          this->pStateBag.pObject->pDelegate.pObject,
          pHeap,
          1,
          0i64);
        v10 = v26;
      }
      else
      {
        v10 = 0i64;
      }
      if ( !_InterlockedDecrement(&v20->RefCount.Value) )
      {
        pLib = v20->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v20);
          v20->pLib = 0i64;
        }
        v20->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(
          v20,
          1u);
      }
      if ( result.pKeyInterface )
        result.pKeyInterface->vfptr->Release(result.pKeyInterface, result.hKeyData);
LABEL_40:
      v9 = v10;
      goto LABEL_41;
    }
  }
  if ( v20 && !_InterlockedDecrement(&v20->RefCount.Value) )
  {
    v28 = v20->pLib;
    if ( v28 )
    {
      v28->vfptr[1].__vecDelDtor(v28, (unsigned int)v20);
      v20->pLib = 0i64;
    }
    v20->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(
      v20,
      1u);
  }
  if ( result.pKeyInterface )
    result.pKeyInterface->vfptr->Release(result.pKeyInterface, result.hKeyData);
LABEL_41:
  if ( v31 )
    Scaleform::RefCountImpl::Release(v31);
  return (Scaleform::GFx::MovieDefImpl *)v9;
}

// File Line: 863
// RVA: 0x8F3580
void __fastcall Scaleform::GFx::MovieImpl::ProcessLoadQueue(Scaleform::GFx::MovieImpl *this)
{
  unsigned int LastLoadQueueEntryCnt; // ebp
  Scaleform::GFx::LoadQueueEntry *pLoadQueueHead; // rsi
  Scaleform::GFx::LoadStates *v4; // r10
  Scaleform::GFx::StateBagImpl *pObject; // rcx
  Scaleform::GFx::ResourceLibBase **v6; // r8
  Scaleform::Render::RenderBuffer *v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rbx
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // rbx
  Scaleform::GFx::LoadQueueEntryMT *v10; // rbx
  Scaleform::GFx::LoadQueueEntryMT *pNext; // rsi
  Scaleform::GFx::LoadQueueEntryMT *pPrev; // rax

  LastLoadQueueEntryCnt = this->LastLoadQueueEntryCnt;
  while ( this->pLoadQueueHead )
  {
    pLoadQueueHead = this->pLoadQueueHead;
    if ( pLoadQueueHead->EntryTime > LastLoadQueueEntryCnt )
      break;
    this->pLoadQueueHead = pLoadQueueHead->pNext;
    v4 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                         Scaleform::Memory::pGlobalHeap,
                                         144i64,
                                         0i64);
    if ( v4 )
    {
      pObject = this->pStateBag.pObject;
      if ( pObject )
        v6 = (Scaleform::GFx::ResourceLibBase **)&pObject->Scaleform::GFx::StateBag;
      else
        v6 = 0i64;
      Scaleform::GFx::LoadStates::LoadStates(
        v4,
        (Scaleform::GFx::Resource *)this->pMainMovieDef.pObject->pLoaderImpl.pObject,
        v6,
        0i64);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::LoadQueueEntry *, Scaleform::Render::RenderBuffer *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[35].__vecDelDtor)(
      this->pASMovieRoot.pObject,
      pLoadQueueHead,
      v8);
    pLoadQueueHead->vfptr->__vecDelDtor(pLoadQueueHead, 1u);
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
  }
  pLoadQueueMTHead = this->pLoadQueueMTHead;
  if ( pLoadQueueMTHead )
  {
    while ( pLoadQueueMTHead->vfptr->IsPreloadingFinished(pLoadQueueMTHead) )
    {
      pLoadQueueMTHead = pLoadQueueMTHead->pNext;
      if ( !pLoadQueueMTHead )
        goto LABEL_15;
    }
  }
  else
  {
LABEL_15:
    v10 = this->pLoadQueueMTHead;
    while ( v10 )
    {
      if ( v10->vfptr->LoadFinished(v10) )
      {
        pNext = v10->pNext;
        if ( pNext )
          pNext->pPrev = v10->pPrev;
        pPrev = v10->pPrev;
        if ( pPrev )
          pPrev->pNext = pNext;
        if ( this->pLoadQueueMTHead == v10 )
          this->pLoadQueueMTHead = pNext;
        v10->vfptr->__vecDelDtor(v10, 1u);
        v10 = pNext;
      }
      else
      {
        v10 = v10->pNext;
      }
    }
  }
}

// File Line: 930
// RVA: 0x8E3D60
void __fastcall Scaleform::GFx::MovieImpl::DragState::InitCenterDelta(
        Scaleform::GFx::MovieImpl::DragState *this,
        bool lockCenter,
        unsigned int mouseIndex)
{
  __int64 v3; // rsi
  Scaleform::GFx::InteractiveObject *pCharacter; // r14
  Scaleform::GFx::InteractiveObject *pParent; // rbx
  Scaleform::GFx::DisplayObjectBase *v7; // rcx
  float *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm11_4
  float v13; // xmm6_4
  float v14; // xmm4_4
  float v15; // xmm10_4
  float v16; // xmm12_4
  float v17; // xmm5_4
  float v18; // xmm7_4
  float v19; // xmm6_4
  float v20; // xmm10_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float *v23; // rax
  __int64 v24; // rax
  float v25; // xmm9_4
  float v26; // xmm8_4
  float v27; // xmm7_4
  float v28; // xmm6_4
  __int64 v29; // rax
  float v30; // xmm1_4
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+18h] [rbp-59h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [rsp+38h] [rbp-39h] BYREF

  v3 = mouseIndex;
  this->LockCenter = lockCenter;
  this->MouseIndex = mouseIndex;
  if ( !lockCenter )
  {
    pCharacter = this->pCharacter;
    pParent = this->pCharacter->pParent;
    *(_OWORD *)&pmat.M[0][0] = _xmm;
    *(__m128 *)&pmat.M[1][0] = _xmm;
    if ( pParent )
    {
      *(_OWORD *)&pmat.M[0][0] = _xmm;
      *(__m128 *)&pmat.M[1][0] = _xmm;
      v7 = pParent->pParent;
      if ( v7 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v7, &pmat);
        v8 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pParent);
        v9 = pmat.M[0][0];
        v10 = pmat.M[0][1];
        v11 = pmat.M[1][0];
        v12 = 0.0;
        v13 = pmat.M[0][0];
        v14 = pmat.M[1][1];
        v15 = pmat.M[1][0];
        v16 = 0.0;
        v17 = (float)(pmat.M[0][0] * *v8) + (float)(pmat.M[0][1] * v8[4]);
        pmat.M[0][0] = v17;
        v18 = (float)(pmat.M[1][0] * *v8) + (float)(pmat.M[1][1] * v8[4]);
        pmat.M[1][0] = v18;
        v19 = (float)(v13 * v8[1]) + (float)(pmat.M[0][1] * v8[5]);
        *(_QWORD *)&pmat.M[0][1] = LODWORD(v19);
        v20 = (float)(v15 * v8[1]) + (float)(pmat.M[1][1] * v8[5]);
        *(_QWORD *)&pmat.M[1][1] = LODWORD(v20);
        v21 = pmat.M[0][3] + (float)((float)(v10 * v8[7]) + (float)(v9 * v8[3]));
        pmat.M[0][3] = v21;
        v22 = pmat.M[1][3] + (float)((float)(v14 * v8[7]) + (float)(v11 * v8[3]));
      }
      else
      {
        v23 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pParent);
        v17 = *v23;
        pmat.M[0][0] = *v23;
        v19 = v23[1];
        pmat.M[0][1] = v19;
        v16 = v23[2];
        pmat.M[0][2] = v16;
        v21 = v23[3];
        pmat.M[0][3] = v21;
        v18 = v23[4];
        pmat.M[1][0] = v18;
        v20 = v23[5];
        pmat.M[1][1] = v20;
        v12 = v23[6];
        pmat.M[1][2] = v12;
        v22 = v23[7];
      }
    }
    else
    {
      v22 = pmat.M[1][3];
      v12 = pmat.M[1][2];
      v20 = pmat.M[1][1];
      v18 = pmat.M[1][0];
      v21 = pmat.M[0][3];
      v16 = pmat.M[0][2];
      v19 = pmat.M[0][1];
      v17 = pmat.M[0][0];
    }
    if ( (unsigned int)v3 < 6 )
      v24 = (__int64)&pCharacter->pASRoot->pMovieImpl->mMouseState[v3];
    else
      v24 = 0i64;
    v25 = *(float *)(v24 + 56);
    v26 = *(float *)(v24 + 60);
    *(_QWORD *)&pmat.M[0][2] = __PAIR64__(LODWORD(v21), LODWORD(v16));
    *(_QWORD *)&pmat.M[1][0] = __PAIR64__(LODWORD(v20), LODWORD(v18));
    *(_QWORD *)&pmat.M[1][2] = __PAIR64__(LODWORD(v22), LODWORD(v12));
    *(_QWORD *)&m.M[0][0] = __PAIR64__(LODWORD(v19), LODWORD(v17));
    *(_QWORD *)&m.M[0][2] = __PAIR64__(LODWORD(v21), LODWORD(v16));
    *(_QWORD *)&m.M[1][0] = __PAIR64__(LODWORD(v20), LODWORD(v18));
    *(_QWORD *)&m.M[1][2] = __PAIR64__(LODWORD(v22), LODWORD(v12));
    Scaleform::Render::Matrix2x4<float>::SetInverse(&pmat, &m);
    v27 = (float)((float)(pmat.M[0][1] * v26) + (float)(pmat.M[0][0] * v25)) + pmat.M[0][3];
    v28 = (float)((float)(pmat.M[1][1] * v26) + (float)(pmat.M[1][0] * v25)) + pmat.M[1][3];
    v29 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pCharacter->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pCharacter);
    v30 = *(float *)(v29 + 28) - v28;
    this->CenterDelta.x = *(float *)(v29 + 12) - v27;
    this->CenterDelta.y = v30;
  }
}

// File Line: 966
// RVA: 0x90EE40
void __fastcall Scaleform::GFx::MovieImpl::SetViewport(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Viewport *viewDesc)
{
  Scaleform::GFx::Viewport *p_mViewport; // rdi
  int Height; // ebp
  int Left; // r12d
  int Width; // r14d
  int Top; // r15d
  float AspectRatio; // xmm7_4
  float Scale; // xmm11_4
  float x1; // xmm6_4
  float y1; // xmm9_4
  float x2; // xmm8_4
  float y2; // xmm10_4
  Scaleform::GFx::Movie::ScaleModeType ViewScaleMode; // eax

  p_mViewport = &this->mViewport;
  if ( memcmp(viewDesc, &this->mViewport, 0x34ui64) )
  {
    Height = this->mViewport.Height;
    Left = this->mViewport.Left;
    Width = this->mViewport.Width;
    Top = this->mViewport.Top;
    AspectRatio = this->mViewport.AspectRatio;
    Scale = this->mViewport.Scale;
    this->Flags |= 1u;
    p_mViewport->BufferWidth = viewDesc->BufferWidth;
    p_mViewport->BufferHeight = viewDesc->BufferHeight;
    p_mViewport->Left = viewDesc->Left;
    p_mViewport->Top = viewDesc->Top;
    p_mViewport->Width = viewDesc->Width;
    p_mViewport->Height = viewDesc->Height;
    p_mViewport->ScissorLeft = viewDesc->ScissorLeft;
    p_mViewport->ScissorTop = viewDesc->ScissorTop;
    p_mViewport->ScissorWidth = viewDesc->ScissorWidth;
    p_mViewport->ScissorHeight = viewDesc->ScissorHeight;
    p_mViewport->Flags = viewDesc->Flags;
    p_mViewport->Scale = viewDesc->Scale;
    p_mViewport->AspectRatio = viewDesc->AspectRatio;
    x1 = this->VisibleFrameRect.x1;
    y1 = this->VisibleFrameRect.y1;
    x2 = this->VisibleFrameRect.x2;
    y2 = this->VisibleFrameRect.y2;
    Scaleform::GFx::MovieImpl::UpdateViewport(this);
    if ( x1 != this->VisibleFrameRect.x1
      || x2 != this->VisibleFrameRect.x2
      || y1 != this->VisibleFrameRect.y1
      || y2 != this->VisibleFrameRect.y2
      || (ViewScaleMode = this->ViewScaleMode) == SM_NoScale
      && (Width != this->mViewport.Width
       || Height != this->mViewport.Height
       || Left != this->mViewport.Left
       || Top != this->mViewport.Top
       || Scale != this->mViewport.Scale
       || AspectRatio != this->mViewport.AspectRatio)
      || ViewScaleMode != SM_ExactFit
      && (Width != this->mViewport.Width
       || Height != this->mViewport.Height
       || AspectRatio != this->mViewport.AspectRatio) )
    {
      ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[19].__vecDelDtor)(this->pASMovieRoot.pObject);
    }
    Scaleform::Render::TreeRoot::SetViewport(this->pRenderRoot.pObject, p_mViewport);
    Scaleform::Render::TreeRoot::SetBackgroundColor(this->pRenderRoot.pObject, &this->BackgroundColor);
    Scaleform::Render::TreeNode::SetMatrix(this->pRenderRoot.pObject, &this->ViewportMatrix);
  }
}

// File Line: 1018
// RVA: 0x906360
void __fastcall Scaleform::GFx::MovieImpl::SetBackgroundColor(Scaleform::GFx::MovieImpl *this, unsigned int *color)
{
  this->BackgroundColor.Raw = *color;
  Scaleform::Render::TreeRoot::SetBackgroundColor(this->pRenderRoot.pObject, &this->BackgroundColor);
}

// File Line: 1024
// RVA: 0x906310
void __fastcall Scaleform::GFx::MovieImpl::SetBackgroundAlpha(Scaleform::GFx::MovieImpl *this, float alpha)
{
  char v2; // r8

  v2 = -1;
  if ( (unsigned __int8)(int)(float)(alpha * 255.0) != 0xFF )
    v2 = (int)(float)(alpha * 255.0);
  this->BackgroundColor.Channels.Alpha = v2;
  Scaleform::Render::TreeRoot::SetBackgroundColor(this->pRenderRoot.pObject, &this->BackgroundColor);
}

// File Line: 1030
// RVA: 0x9189B0
void __fastcall Scaleform::GFx::MovieImpl::UpdateViewport(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieDefImpl *pObject; // r8
  float y2; // xmm6_4
  float y1; // xmm7_4
  float ViewScaleX; // xmm12_4
  float ViewScaleY; // xmm11_4
  float PixelScale; // xmm10_4
  float x2; // xmm15_4
  float ViewOffsetX; // xmm14_4
  float ViewOffsetY; // xmm13_4
  int Top; // edx
  float v12; // xmm1_4
  int v13; // eax
  Scaleform::GFx::Movie::ScaleModeType ViewScaleMode; // edx
  float v15; // xmm8_4
  float v16; // xmm5_4
  float *v17; // rax
  float v18; // xmm8_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm6_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm0_4
  float v27; // xmm6_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float Scale; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm2_4
  float v34; // xmm4_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // [rsp+C0h] [rbp+8h]
  float x1; // [rsp+D0h] [rbp+18h]

  pObject = this->pMainMovieDef.pObject;
  y2 = this->VisibleFrameRect.y2;
  y1 = this->VisibleFrameRect.y1;
  ViewScaleX = this->ViewScaleX;
  ViewScaleY = this->ViewScaleY;
  PixelScale = this->PixelScale;
  x2 = this->VisibleFrameRect.x2;
  ViewOffsetX = this->ViewOffsetX;
  ViewOffsetY = this->ViewOffsetY;
  x1 = this->VisibleFrameRect.x1;
  v41 = y2;
  if ( !pObject )
  {
    this->ViewScaleY = 1.0;
    this->ViewScaleX = 1.0;
    *(_QWORD *)&this->ViewOffsetX = 0i64;
    this->PixelScale = 1.0;
    goto LABEL_47;
  }
  Top = this->mViewport.Top;
  v12 = (float)Top * 20.0;
  v13 = Top + this->mViewport.Height;
  ViewScaleMode = this->ViewScaleMode;
  v15 = (float)v13;
  v16 = (float)((float)(this->mViewport.Left + this->mViewport.Width) * 20.0)
      - (float)((float)this->mViewport.Left * 20.0);
  v17 = (float *)pObject->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v18 = (float)(v15 * 20.0) - v12;
  v19 = v17[26] - v17[24];
  v20 = v17[27] - v17[25];
  switch ( ViewScaleMode )
  {
    case SM_NoScale:
      Scale = this->mViewport.Scale;
      v32 = (float)(v16 * this->mViewport.AspectRatio) * Scale;
      v33 = Scale * v18;
      switch ( this->ViewAlignment )
      {
        case Align_Center:
          this->VisibleFrameRect.x1 = (float)(20
                                            * (int)(float)((float)((float)(v19 * 0.5) - (float)(v32 * 0.5)) * 0.050000001));
          v34 = (float)(v20 * 0.5) - (float)(v33 * 0.5);
          goto LABEL_35;
        case Align_TopCenter:
          this->VisibleFrameRect.y1 = 0.0;
          this->VisibleFrameRect.x1 = (float)(20
                                            * (int)(float)((float)((float)(v19 * 0.5) - (float)(v32 * 0.5)) * 0.050000001));
          break;
        case Align_BottomCenter:
          this->VisibleFrameRect.y1 = v20 - v33;
          this->VisibleFrameRect.x1 = (float)(20
                                            * (int)(float)((float)((float)(v19 * 0.5) - (float)(v32 * 0.5)) * 0.050000001));
          break;
        case Align_CenterLeft:
          this->VisibleFrameRect.x1 = 0.0;
          goto LABEL_34;
        case Align_CenterRight:
          this->VisibleFrameRect.x1 = v19 - v32;
LABEL_34:
          v34 = (float)(v20 * 0.5) - (float)(v33 * 0.5);
LABEL_35:
          this->VisibleFrameRect.y1 = (float)(20 * (int)(float)(v34 * 0.050000001));
          break;
        case Align_TopLeft:
          *(_QWORD *)&this->VisibleFrameRect.x1 = 0i64;
          break;
        case Align_TopRight:
          this->VisibleFrameRect.x1 = v19 - v32;
          this->VisibleFrameRect.y1 = 0.0;
          break;
        case Align_BottomLeft:
          this->VisibleFrameRect.y1 = v20 - v33;
          this->VisibleFrameRect.x1 = 0.0;
          break;
        case Align_BottomRight:
          this->VisibleFrameRect.x1 = v19 - v32;
          this->VisibleFrameRect.y1 = v20 - v33;
          break;
        default:
          break;
      }
      this->VisibleFrameRect.x2 = v32 + this->VisibleFrameRect.x1;
      this->VisibleFrameRect.y2 = v33 + this->VisibleFrameRect.y1;
      v35 = this->mViewport.Scale;
      v36 = this->VisibleFrameRect.y1;
      this->ViewOffsetX = this->VisibleFrameRect.x1 * 0.050000001;
      this->ViewScaleY = v35;
      this->ViewScaleX = v35 * this->mViewport.AspectRatio;
      this->ViewOffsetY = v36 * 0.050000001;
      goto LABEL_37;
    case SM_ShowAll:
      goto LABEL_6;
    case SM_ExactFit:
      *(_QWORD *)&this->VisibleFrameRect.x1 = 0i64;
      this->VisibleFrameRect.x2 = v19;
      v25 = v20 + this->VisibleFrameRect.y1;
      this->VisibleFrameRect.y2 = v25;
      *(_QWORD *)&this->ViewOffsetX = 0i64;
      if ( v16 == 0.0 )
        v26 = 0.0;
      else
        v26 = (float)(v19 - this->VisibleFrameRect.x1) / v16;
      this->ViewScaleX = v26;
      if ( v18 == 0.0 )
        this->ViewScaleY = 0.0;
      else
        this->ViewScaleY = (float)(v25 - this->VisibleFrameRect.y1) / v18;
      break;
    case SM_NoBorder:
LABEL_6:
      v21 = v16 * this->mViewport.AspectRatio;
      if ( ViewScaleMode == SM_ShowAll && (float)(v21 / v19) < (float)(v18 / v20)
        || ViewScaleMode == SM_NoBorder && (float)(v21 / v19) > (float)(v18 / v20) )
      {
        this->VisibleFrameRect.x1 = 0.0;
        v22 = (float)(v19 * v18) / v21;
        this->VisibleFrameRect.y1 = (float)(v20 * 0.5) - (float)(v22 * 0.5);
        this->VisibleFrameRect.x2 = v19;
        this->VisibleFrameRect.y2 = v22 + this->VisibleFrameRect.y1;
        v23 = this->VisibleFrameRect.y1;
        this->ViewOffsetX = 0.0;
        this->ViewOffsetY = v23 * 0.050000001;
        if ( v16 == 0.0 )
          v24 = 0.0;
        else
          v24 = v19 / v16;
        this->ViewScaleX = v24;
        this->ViewScaleY = v24 / this->mViewport.AspectRatio;
      }
      else
      {
        this->VisibleFrameRect.y1 = 0.0;
        v27 = (float)(v21 * v20) * (float)(1.0 / v18);
        v28 = (float)(v19 * 0.5) - (float)(v27 * 0.5);
        this->VisibleFrameRect.x1 = v28;
        this->VisibleFrameRect.x2 = v28 + v27;
        this->VisibleFrameRect.y2 = v20 + this->VisibleFrameRect.y1;
        v29 = this->VisibleFrameRect.x1;
        this->ViewOffsetY = 0.0;
        this->ViewOffsetX = v29 * 0.050000001;
        if ( v18 == 0.0 )
          v30 = 0.0;
        else
          v30 = (float)(1.0 / v18) * v20;
        this->ViewScaleY = v30;
        this->ViewScaleX = v30 * this->mViewport.AspectRatio;
      }
LABEL_37:
      y2 = v41;
      break;
  }
  v37 = this->ViewScaleY;
  v38 = FLOAT_0_0049999999;
  if ( v37 == 0.0 )
    v39 = FLOAT_0_0049999999;
  else
    v39 = 1.0 / v37;
  v40 = this->ViewScaleX;
  if ( v40 != 0.0 )
    v38 = 1.0 / v40;
  if ( v39 >= v38 )
    v38 = v39;
  this->PixelScale = v38;
LABEL_47:
  Scaleform::GFx::MovieImpl::ResetViewportMatrix(this);
  if ( x1 != this->VisibleFrameRect.x1
    || x2 != this->VisibleFrameRect.x2
    || y1 != this->VisibleFrameRect.y1
    || y2 != this->VisibleFrameRect.y2
    || ViewOffsetX != this->ViewOffsetX
    || ViewOffsetY != this->ViewOffsetY
    || ViewScaleX != this->ViewScaleX
    || ViewScaleY != this->ViewScaleY
    || PixelScale != this->PixelScale )
  {
    Scaleform::GFx::MovieImpl::UpdateViewAndPerspective(this);
  }
}

// File Line: 1184
// RVA: 0x901770
void __fastcall Scaleform::GFx::MovieImpl::ResetViewportMatrix(Scaleform::GFx::MovieImpl *this)
{
  float x1; // xmm4_4
  float y1; // xmm5_4
  float v3; // xmm4_4
  float v4; // xmm5_4
  float Width; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm2_4

  x1 = this->VisibleFrameRect.x1;
  y1 = this->VisibleFrameRect.y1;
  *(_QWORD *)&this->ViewportMatrix.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->ViewportMatrix.M[1][1] = 1065353216i64;
  LODWORD(v3) = LODWORD(x1) ^ _xmm[0];
  LODWORD(v4) = LODWORD(y1) ^ _xmm[0];
  this->ViewportMatrix.M[0][2] = 0.0;
  this->ViewportMatrix.M[1][0] = 0.0;
  this->ViewportMatrix.M[0][3] = v3;
  this->ViewportMatrix.M[1][3] = v4;
  Width = (float)this->mViewport.Width;
  v6 = (float)this->mViewport.Height / (float)(this->VisibleFrameRect.y2 - this->VisibleFrameRect.y1);
  v7 = this->VisibleFrameRect.x2 - this->VisibleFrameRect.x1;
  this->ViewportMatrix.M[1][1] = v6;
  this->ViewportMatrix.M[1][3] = v4 * v6;
  v8 = Width / v7;
  this->ViewportMatrix.M[0][0] = v8;
  this->ViewportMatrix.M[0][3] = v3 * v8;
  this->ViewportMatrix.M[0][1] = v8 * 0.0;
  this->ViewportMatrix.M[0][2] = v8 * 0.0;
  this->ViewportMatrix.M[1][0] = v6 * 0.0;
  this->ViewportMatrix.M[1][2] = v6 * 0.0;
}

// File Line: 1191
// RVA: 0x9046A0
void __fastcall Scaleform::GFx::MovieImpl::RestoreViewport(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl::ResetViewportMatrix(this);
  Scaleform::Render::TreeNode::SetMatrix(this->pRenderRoot.pObject, &this->ViewportMatrix);
}

// File Line: 1202
// RVA: 0x8EB2D0
void __fastcall Scaleform::GFx::MovieImpl::MakeViewAndPersp3D(
        Scaleform::Render::Matrix3x4<float> *matView,
        Scaleform::Render::Matrix4x4<float> *matPersp,
        Scaleform::Render::Rect<float> *frameRect,
        Scaleform::Render::Point<float> *projCenter,
        float fieldOfView,
        float focalLength,
        bool bInvertY)
{
  float v7; // xmm4_4
  float x2; // xmm10_4
  float v10; // xmm7_4
  float v12; // xmm8_4
  float fNearZ; // xmm9_4
  float fFarZ; // xmm6_4
  float x; // xmm14_4
  __int128 y_low; // xmm15
  float viewMaxY; // xmm13_4
  float v18; // xmm8_4
  int v19; // xmm1_4
  float v20; // xmm11_4
  float v21; // xmm12_4
  float v22; // xmm10_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm14_4
  __m128 v27; // xmm2
  float v28; // xmm4_4
  Scaleform::Render::Point3<float> upVec; // [rsp+40h] [rbp-D8h] BYREF
  Scaleform::Render::Point3<float> eyePt; // [rsp+50h] [rbp-C8h] BYREF
  Scaleform::Render::Point3<float> zAxis; // [rsp+60h] [rbp-B8h] BYREF

  v7 = *(float *)&FLOAT_1_0;
  x2 = frameRect->x2;
  v10 = focalLength;
  LODWORD(v12) = COERCE_UNSIGNED_INT(x2 - frameRect->x1) & _xmm;
  if ( focalLength == 0.0 )
    fNearZ = *(float *)&FLOAT_1_0;
  else
    fNearZ = focalLength * 0.0099999998;
  if ( focalLength == 0.0 )
  {
    fFarZ = FLOAT_100000_0;
    if ( v12 > 100000.0 )
      LODWORD(fFarZ) = COERCE_UNSIGNED_INT(x2 - frameRect->x1) & _xmm;
  }
  else
  {
    fFarZ = focalLength * 100.0;
  }
  x = projCenter->x;
  y_low = LODWORD(projCenter->y);
  viewMaxY = projCenter->y - frameRect->y1;
  v18 = v12 * 0.5;
  v19 = _xmm[0];
  LODWORD(v20) = COERCE_UNSIGNED_INT(projCenter->x - frameRect->x1) ^ _xmm[0];
  LODWORD(v21) = COERCE_UNSIGNED_INT(frameRect->y2 - *(float *)&y_low) ^ _xmm[0];
  v22 = x2 - projCenter->x;
  if ( focalLength == 0.0 )
  {
    if ( fieldOfView > 0.0 )
    {
      v23 = tanf((float)(fieldOfView * 3.141592653589793 * 0.005555555555555556) * 0.5);
      v7 = *(float *)&FLOAT_1_0;
      v19 = _xmm[0];
      v10 = v18 / v23;
    }
    else
    {
      v10 = v18;
    }
  }
  if ( matView )
  {
    LODWORD(v24) = LODWORD(fFarZ) ^ v19;
    if ( COERCE_FLOAT(LODWORD(v10) ^ v19) >= COERCE_FLOAT(LODWORD(fFarZ) ^ v19) )
      LODWORD(v24) = LODWORD(v10) ^ v19;
    eyePt.x = x;
    LODWORD(eyePt.y) = y_low;
    eyePt.z = v24;
    if ( bInvertY )
      v25 = v7;
    else
      v25 = FLOAT_N1_0;
    v26 = x - x;
    *(float *)&y_low = *(float *)&y_low - *(float *)&y_low;
    upVec.y = v25;
    upVec.x = 0.0;
    upVec.z = 0.0;
    v27 = (__m128)y_low;
    v27.m128_f32[0] = (float)(*(float *)&y_low * *(float *)&y_low) + (float)(v26 * v26);
    if ( bInvertY )
      LODWORD(v24) ^= v19;
    v27.m128_f32[0] = v27.m128_f32[0] + (float)(v24 * v24);
    v28 = v7 / _mm_sqrt_ps(v27).m128_f32[0];
    zAxis.x = v26 * v28;
    zAxis.y = *(float *)&y_low * v28;
    zAxis.z = v24 * v28;
    Scaleform::Render::Matrix3x4<float>::View(matView, &eyePt, &zAxis, &upVec);
  }
  if ( matPersp )
  {
    if ( fieldOfView > 0.0 )
    {
      if ( bInvertY )
        Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterLH(
          matPersp,
          v10,
          v20,
          v22,
          v21,
          viewMaxY,
          fNearZ,
          fFarZ);
      else
        Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterRH(
          matPersp,
          v10,
          v20,
          v22,
          v21,
          viewMaxY,
          fNearZ,
          fFarZ);
    }
    else if ( bInvertY )
    {
      Scaleform::Render::Matrix4x4<float>::OrthoOffCenterLH(matPersp, v20, v22, v21, viewMaxY, fNearZ, fFarZ);
    }
    else
    {
      Scaleform::Render::Matrix4x4<float>::OrthoOffCenterRH(matPersp, v20, v22, v21, viewMaxY, fNearZ, fFarZ);
    }
  }
}

// File Line: 1259
// RVA: 0x918940
void __fastcall Scaleform::GFx::MovieImpl::UpdateViewAndPerspective(Scaleform::GFx::MovieImpl *this)
{
  unsigned int v2; // ebx
  __int64 v3; // rcx
  Scaleform::GFx::InteractiveObject *pObject; // rcx

  if ( this->VisibleFrameRect.x1 != this->VisibleFrameRect.x2 || this->VisibleFrameRect.y1 != this->VisibleFrameRect.y2 )
  {
    v2 = 0;
    if ( this->MovieLevels.Data.Size )
    {
      v3 = 0i64;
      do
      {
        pObject = this->MovieLevels.Data.Data[v3].pSprite.pObject;
        if ( pObject )
          ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[12].__vecDelDtor)(pObject);
        v3 = ++v2;
      }
      while ( v2 < this->MovieLevels.Data.Size );
    }
  }
}

// File Line: 1273
// RVA: 0x8E1680
void __fastcall Scaleform::GFx::MovieImpl::GetViewMatrix3D(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Matrix3x4<float> *viewMat)
{
  void *v3; // rax

  v3 = this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[16].__vecDelDtor(this->pASMovieRoot.pObject, 0i64);
  if ( v3 )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix3x4<float> *, _QWORD))(*(_QWORD *)v3 + 72i64))(
      v3,
      viewMat,
      0i64);
}

// File Line: 1281
// RVA: 0x90ECB0
void __fastcall Scaleform::GFx::MovieImpl::SetViewMatrix3D(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Matrix3x4<float> *viewMat)
{
  void *v3; // rax

  v3 = this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[16].__vecDelDtor(this->pASMovieRoot.pObject, 0i64);
  if ( v3 )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix3x4<float> *))(*(_QWORD *)v3 + 80i64))(v3, viewMat);
}

// File Line: 1289
// RVA: 0x8DC510
void __fastcall Scaleform::GFx::MovieImpl::GetProjectionMatrix3D(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Matrix4x4<float> *projMat)
{
  void *v3; // rax

  v3 = this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[16].__vecDelDtor(this->pASMovieRoot.pObject, 0i64);
  if ( v3 )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix4x4<float> *, _QWORD))(*(_QWORD *)v3 + 48i64))(
      v3,
      projMat,
      0i64);
}

// File Line: 1297
// RVA: 0x90A100
void __fastcall Scaleform::GFx::MovieImpl::SetProjectionMatrix3D(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Matrix4x4<float> *projMat)
{
  void *v3; // rax

  v3 = this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[16].__vecDelDtor(this->pASMovieRoot.pObject, 0i64);
  if ( v3 )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix4x4<float> *))(*(_QWORD *)v3 + 56i64))(v3, projMat);
}

// File Line: 1304
// RVA: 0x8E1790
void __fastcall Scaleform::GFx::MovieImpl::GetViewport(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Viewport *pviewDesc)
{
  *pviewDesc = this->mViewport;
}

// File Line: 1309
// RVA: 0x90ECF0
void __fastcall Scaleform::GFx::MovieImpl::SetViewScaleMode(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Movie::ScaleModeType scaleMode)
{
  Scaleform::GFx::UserEventHandler *pObject; // rcx
  float Scale; // xmm0_4
  float AspectRatio; // xmm1_4
  int BufferHeight; // eax
  int ScissorHeight; // eax
  int v9[18]; // [rsp+20h] [rbp-48h] BYREF
  int v10; // [rsp+70h] [rbp+8h] BYREF
  char v11; // [rsp+74h] [rbp+Ch]

  pObject = this->pUserEventHandler.pObject;
  if ( pObject )
  {
    v11 = 0;
    v10 = 25 - (scaleMode != SM_NoScale);
    ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
      this,
      &v10);
  }
  this->ViewScaleMode = scaleMode;
  Scale = this->mViewport.Scale;
  AspectRatio = this->mViewport.AspectRatio;
  v9[0] = this->mViewport.BufferWidth;
  BufferHeight = this->mViewport.BufferHeight;
  *(float *)&v9[11] = Scale;
  *(float *)&v9[12] = AspectRatio;
  v9[1] = BufferHeight;
  v9[2] = this->mViewport.Left;
  v9[3] = this->mViewport.Top;
  v9[4] = this->mViewport.Width;
  v9[5] = this->mViewport.Height;
  v9[10] = this->mViewport.Flags;
  v9[6] = this->mViewport.ScissorLeft;
  v9[7] = this->mViewport.ScissorTop;
  v9[8] = this->mViewport.ScissorWidth;
  ScissorHeight = this->mViewport.ScissorHeight;
  ++this->mViewport.Flags;
  v9[9] = ScissorHeight;
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[12].__vecDelDtor(
    this,
    (unsigned int)v9);
}

// File Line: 1321
// RVA: 0x90E8E0
void __fastcall Scaleform::GFx::MovieImpl::SetViewAlignment(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Movie::AlignType align)
{
  float Scale; // xmm0_4
  float AspectRatio; // xmm1_4
  int BufferHeight; // eax
  int ScissorHeight; // eax
  int v6[18]; // [rsp+20h] [rbp-48h] BYREF

  this->ViewAlignment = align;
  Scale = this->mViewport.Scale;
  AspectRatio = this->mViewport.AspectRatio;
  v6[0] = this->mViewport.BufferWidth;
  BufferHeight = this->mViewport.BufferHeight;
  *(float *)&v6[11] = Scale;
  *(float *)&v6[12] = AspectRatio;
  v6[1] = BufferHeight;
  v6[2] = this->mViewport.Left;
  v6[3] = this->mViewport.Top;
  v6[4] = this->mViewport.Width;
  v6[5] = this->mViewport.Height;
  v6[10] = this->mViewport.Flags;
  v6[6] = this->mViewport.ScissorLeft;
  v6[7] = this->mViewport.ScissorTop;
  v6[8] = this->mViewport.ScissorWidth;
  ScissorHeight = this->mViewport.ScissorHeight;
  ++this->mViewport.Flags;
  v6[9] = ScissorHeight;
  this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[12].__vecDelDtor(
    this,
    (unsigned int)v6);
}

// File Line: 1332
// RVA: 0x8DF340
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::MovieImpl::GetTopMostEntity(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Point<float> *mousePos,
        unsigned int controllerIdx,
        bool testAll,
        Scaleform::GFx::InteractiveObject *ignoreMC)
{
  float x; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  int v13; // xmm1_4
  int v14; // xmm0_4
  int v15; // xmm1_4
  int v16; // xmm0_4
  int v17; // xmm1_4
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm0_4
  int v21; // xmm1_4
  int v22; // xmm0_4
  int v23; // xmm1_4
  int v24; // xmm0_4
  int v25; // xmm1_4
  int v26; // xmm0_4
  int v27; // xmm1_4
  Scaleform::RefCountImplCoreVtbl *v28; // rax
  int v29; // xmm1_4
  __int64 v30; // rcx
  int v31; // xmm0_4
  int v32; // xmm1_4
  int v33; // xmm0_4
  int v34; // xmm1_4
  int v35; // xmm0_4
  int v36; // xmm1_4
  int v37; // xmm0_4
  int v38; // xmm1_4
  int v39; // xmm0_4
  int v40; // xmm1_4
  int v41; // eax
  __int64 v42; // rsi
  Scaleform::GFx::InteractiveObject *pObject; // rdi
  Scaleform::GFx::InteractiveObject *pParent; // rbx
  Scaleform::GFx::DisplayObjectBase *v45; // rcx
  float *v46; // rax
  float v47; // xmm3_4
  float v48; // xmm4_4
  float v49; // xmm5_4
  float v50; // xmm6_4
  float v51; // xmm0_4
  float v52; // xmm2_4
  __int64 Size_low; // rdi
  __int64 i; // rbx
  __int64 v55; // rcx
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+20h] [rbp-B1h] BYREF
  int v58[12]; // [rsp+40h] [rbp-91h] BYREF
  int Dst[16]; // [rsp+70h] [rbp-61h] BYREF
  __int64 v60[2]; // [rsp+B0h] [rbp-21h] BYREF
  Scaleform::GFx::InteractiveObject *v61; // [rsp+C0h] [rbp-11h]
  __int64 v62; // [rsp+C8h] [rbp-9h]
  unsigned int v63; // [rsp+D0h] [rbp-1h]
  bool v64; // [rsp+D4h] [rbp+3h]
  __int64 v65; // [rsp+130h] [rbp+5Fh]
  Scaleform::Render::Point<float> result; // [rsp+138h] [rbp+67h] BYREF

  x = mousePos->x;
  v10 = this->VisibleFrameRect.x2 - this->VisibleFrameRect.x1;
  v11 = this->ViewOffsetX * 20.0;
  LODWORD(this->ScreenToWorld.Sy) = COERCE_UNSIGNED_INT(
                                      (float)((float)((float)(mousePos->y - (float)(this->ViewOffsetY * 20.0))
                                                    / (float)(this->VisibleFrameRect.y2 - this->VisibleFrameRect.y1))
                                            * 2.0)
                                    - 1.0) ^ _xmm[0];
  this->ScreenToWorld.Sx = (float)((float)((float)(x - v11) / v10) * 2.0) - 1.0;
  memset(Dst, 0, sizeof(Dst));
  vfptr = this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
  Dst[0] = 1065353216;
  Dst[5] = 1065353216;
  Dst[10] = 1065353216;
  Dst[15] = 1065353216;
  vfptr[62].__vecDelDtor(this, (unsigned int)Dst);
  v13 = Dst[1];
  LODWORD(this->ScreenToWorld.MatProj.M[0][0]) = Dst[0];
  v14 = Dst[2];
  LODWORD(this->ScreenToWorld.MatProj.M[0][1]) = v13;
  v15 = Dst[3];
  LODWORD(this->ScreenToWorld.MatProj.M[0][2]) = v14;
  v16 = Dst[4];
  LODWORD(this->ScreenToWorld.MatProj.M[0][3]) = v15;
  v17 = Dst[5];
  LODWORD(this->ScreenToWorld.MatProj.M[1][0]) = v16;
  v18 = Dst[6];
  LODWORD(this->ScreenToWorld.MatProj.M[1][1]) = v17;
  v19 = Dst[7];
  LODWORD(this->ScreenToWorld.MatProj.M[1][2]) = v18;
  v20 = Dst[8];
  LODWORD(this->ScreenToWorld.MatProj.M[1][3]) = v19;
  v21 = Dst[9];
  LODWORD(this->ScreenToWorld.MatProj.M[2][0]) = v20;
  v22 = Dst[10];
  LODWORD(this->ScreenToWorld.MatProj.M[2][1]) = v21;
  v23 = Dst[11];
  LODWORD(this->ScreenToWorld.MatProj.M[2][2]) = v22;
  v24 = Dst[12];
  LODWORD(this->ScreenToWorld.MatProj.M[2][3]) = v23;
  v25 = Dst[13];
  LODWORD(this->ScreenToWorld.MatProj.M[3][0]) = v24;
  v26 = Dst[14];
  LODWORD(this->ScreenToWorld.MatProj.M[3][1]) = v25;
  v27 = Dst[15];
  LODWORD(this->ScreenToWorld.MatProj.M[3][2]) = v26;
  LODWORD(this->ScreenToWorld.MatProj.M[3][3]) = v27;
  memset(v58, 0, sizeof(v58));
  v28 = this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
  v58[0] = 1065353216;
  v58[5] = 1065353216;
  v58[10] = 1065353216;
  v28[60].__vecDelDtor(this, (unsigned int)v58);
  v29 = v58[1];
  v30 = 0i64;
  v65 = 0i64;
  LODWORD(this->ScreenToWorld.MatView.M[0][0]) = v58[0];
  v31 = v58[2];
  LODWORD(this->ScreenToWorld.MatView.M[0][1]) = v29;
  v32 = v58[3];
  LODWORD(this->ScreenToWorld.MatView.M[0][2]) = v31;
  v33 = v58[4];
  LODWORD(this->ScreenToWorld.MatView.M[0][3]) = v32;
  v34 = v58[5];
  LODWORD(this->ScreenToWorld.MatView.M[1][0]) = v33;
  v35 = v58[6];
  LODWORD(this->ScreenToWorld.MatView.M[1][1]) = v34;
  v36 = v58[7];
  LODWORD(this->ScreenToWorld.MatView.M[1][2]) = v35;
  v37 = v58[8];
  LODWORD(this->ScreenToWorld.MatView.M[1][3]) = v36;
  v38 = v58[9];
  LODWORD(this->ScreenToWorld.MatView.M[2][0]) = v37;
  v39 = v58[10];
  LODWORD(this->ScreenToWorld.MatView.M[2][1]) = v38;
  v40 = v58[11];
  LODWORD(this->ScreenToWorld.MatView.M[2][2]) = v39;
  LODWORD(this->ScreenToWorld.MatView.M[2][3]) = v40;
  v41 = LODWORD(this->TopmostLevelCharacters.Data.Size) - 1;
  v42 = v41;
  if ( v41 >= 0 )
  {
    while ( 1 )
    {
      pObject = this->TopmostLevelCharacters.Data.Data[v42].pObject;
      pParent = pObject->pParent;
      if ( pParent )
      {
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        v45 = pParent->pParent;
        if ( v45 )
        {
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v45, &pmat);
          v46 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pParent);
          v47 = pmat.M[0][0];
          v48 = pmat.M[0][1];
          v49 = pmat.M[1][0];
          v50 = pmat.M[1][1];
          pmat.M[0][0] = (float)(pmat.M[0][1] * v46[4]) + (float)(pmat.M[0][0] * *v46);
          pmat.M[1][0] = (float)(pmat.M[1][1] * v46[4]) + (float)(pmat.M[1][0] * *v46);
          pmat.M[0][1] = (float)(v47 * v46[1]) + (float)(pmat.M[0][1] * v46[5]);
          v51 = pmat.M[1][1] * v46[5];
          v52 = v49 * v46[1];
          pmat.M[0][2] = 0.0;
          *(_QWORD *)&pmat.M[1][1] = COERCE_UNSIGNED_INT(v52 + v51);
          pmat.M[0][3] = pmat.M[0][3] + (float)((float)(v48 * v46[7]) + (float)(v47 * v46[3]));
          pmat.M[1][3] = pmat.M[1][3] + (float)((float)(v50 * v46[7]) + (float)(v49 * v46[3]));
        }
        else
        {
          pmat = *(Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pParent);
        }
        Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, &result, mousePos);
        v62 = 0i64;
        v61 = ignoreMC;
        v64 = testAll;
        v63 = controllerIdx;
        if ( ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Point<float> *, __int64 *))pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[64].__vecDelDtor)(
               pObject,
               &result,
               v60) == 1 )
          break;
      }
      if ( --v42 < 0 )
      {
        v30 = 0i64;
        goto LABEL_9;
      }
    }
    v30 = v60[0];
    v65 = v60[0];
    if ( v60[0] )
      return (Scaleform::GFx::InteractiveObject *)v30;
  }
LABEL_9:
  Size_low = SLODWORD(this->MovieLevels.Data.Size);
  if ( Size_low <= 0 )
    return (Scaleform::GFx::InteractiveObject *)v30;
  for ( i = 16 * Size_low - 16; ; i -= 16i64 )
  {
    v55 = *(__int64 *)((char *)&this->MovieLevels.Data.Data->pSprite.pObject + i);
    v62 = 0i64;
    v61 = ignoreMC;
    v64 = testAll;
    v63 = controllerIdx;
    if ( (*(unsigned int (__fastcall **)(__int64, Scaleform::Render::Point<float> *, __int64 *))(*(_QWORD *)v55 + 512i64))(
           v55,
           mousePos,
           v60) == 1 )
      break;
    if ( --Size_low <= 0 )
      return (Scaleform::GFx::InteractiveObject *)v65;
  }
  return (Scaleform::GFx::InteractiveObject *)v60[0];
}

// File Line: 1398
// RVA: 0x8B4330
float __fastcall Scaleform::GFx::MovieImpl::Advance(
        Scaleform::GFx::MovieImpl *this,
        float deltaT,
        unsigned int frameCatchUpCount,
        bool capture)
{
  float v4; // xmm7_4
  Scaleform::GFx::MovieDefImpl *pObject; // rcx
  Scaleform::GFx::UserEventHandler *v9; // rbx
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::GFx::FSCommandHandler *v11; // rbx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::ExternalInterface *v13; // rbx
  Scaleform::Render::RenderBuffer *v14; // rcx
  __int64 v15; // rbx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rdi
  Scaleform::Render::RenderBuffer *v17; // rcx
  Scaleform::Render::RenderBuffer *v18; // r14
  Scaleform::Render::RenderBuffer *v19; // rsi
  Scaleform::Render::RenderBuffer *v20; // rdi
  Scaleform::Render::RenderBuffer *v21; // r15
  unsigned __int8 v22; // r12
  unsigned int Flags; // eax
  unsigned int v24; // eax
  Scaleform::GFx::MovieDefRootNode *i; // rbx
  Scaleform::ArrayDefaultPolicy *v26; // rax
  unsigned int v27; // ebx
  __int64 v28; // rcx
  Scaleform::GFx::InteractiveObject *v29; // rcx
  unsigned __int64 Size; // rax
  int v31; // ebx
  Scaleform::GFx::InteractiveObject *v32; // rcx
  float v33; // xmm0_4
  unsigned __int64 v34; // rcx
  unsigned __int64 ProfileTicks; // r12
  float FrameTime; // xmm13_4
  unsigned __int64 v37; // r15
  float v38; // xmm13_4
  unsigned __int64 v39; // rcx
  __int64 v40; // r14
  int v41; // esi
  unsigned __int64 v42; // rdi
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327,Scaleform::ArrayDefaultPolicy> *p_IntervalTimers; // rbx
  Scaleform::GFx::ASIntervalTimerIntf *v44; // rcx
  unsigned __int64 v45; // rax
  unsigned __int64 v46; // r15
  __int64 j; // rsi
  Scaleform::GFx::ASIntervalTimerIntf *v48; // rcx
  Scaleform::Render::RenderBuffer *v49; // rcx
  float v50; // xmm13_4
  float TimeRemainder; // xmm2_4
  float v52; // xmm0_4
  int v53; // edi
  bool v54; // si
  float v55; // xmm6_4
  float v56; // xmm0_4
  float v57; // xmm0_4
  float v58; // xmm2_4
  Scaleform::GFx::InteractiveObject *pUnloadListHead; // rbx
  Scaleform::GFx::InteractiveObject *pPlayNextOpt; // rdi
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  __int64 v62; // rdx
  unsigned int ForceFrameCatchUp; // eax
  int v64; // eax
  Scaleform::GFx::DrawingContext *k; // rbx
  unsigned __int64 *v66; // rax
  __int64 m; // rdi
  __int64 v68; // rbx
  __int64 v69; // rax
  float v70; // xmm0_4
  float v71; // xmm13_4
  Scaleform::Render::TreeRoot *v72; // rdx
  unsigned __int64 v73; // r15
  __int64 v74; // rsi
  Scaleform::GFx::MovieImpl::IndirectTransPair *Data; // rbx
  Scaleform::Render::TreeNode *RenderNode; // r14
  Scaleform::Render::ContextImpl::Entry *pPrev; // rcx
  bool v78; // r9
  Scaleform::Render::TreeRoot *v79; // rcx
  Scaleform::Render::TreeRoot *v80; // rcx
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *pIndXFormData; // rcx
  float v82; // xmm7_4
  float v83; // xmm9_4
  float v84; // xmm0_4
  float v85; // xmm10_4
  float v86; // xmm8_4
  float v87; // xmm11_4
  float v88; // xmm1_4
  float v89; // xmm12_4
  float v90; // xmm2_4
  float v91; // xmm3_4
  float v92; // xmm4_4
  float v93; // xmm5_4
  char IsOrig3D; // di
  Scaleform::Render::TreeRoot *v95; // rbx
  __int64 v96; // rdx
  float v97; // xmm0_4
  float v98; // xmm2_4
  float v99; // xmm3_4
  Scaleform::Render::TreeRoot *v100; // rbx
  __int64 v101; // rdx
  float v102; // xmm4_4
  float v103; // xmm3_4
  float v104; // xmm6_4
  float v105; // xmm5_4
  bool HasChanges; // al
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+30h] [rbp-98h] BYREF
  Scaleform::Render::Matrix3x4<float> v108; // [rsp+60h] [rbp-68h] BYREF
  float v109; // [rsp+90h] [rbp-38h]
  float v110; // [rsp+94h] [rbp-34h]
  float v111; // [rsp+98h] [rbp-30h]
  float v112; // [rsp+9Ch] [rbp-2Ch]
  float v113; // [rsp+A0h] [rbp-28h]
  float v114; // [rsp+A4h] [rbp-24h]
  float v115; // [rsp+A8h] [rbp-20h]
  float v116; // [rsp+ACh] [rbp-1Ch]
  float v117; // [rsp+B0h] [rbp-18h]
  float v118; // [rsp+B4h] [rbp-14h]
  Scaleform::Render::Matrix3x4<float> v119; // [rsp+B8h] [rbp-10h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+E8h] [rbp+20h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+118h] [rbp+50h] BYREF
  Scaleform::Render::Matrix3x4<float> v122; // [rsp+148h] [rbp+80h] BYREF
  __int128 v123; // [rsp+178h] [rbp+B0h] BYREF
  __int128 v124; // [rsp+188h] [rbp+C0h]
  Scaleform::GFx::FontLib *pfontLib[2]; // [rsp+198h] [rbp+D0h]
  Scaleform::GFx::FontMap *pfontMap[2]; // [rsp+1A8h] [rbp+E0h]
  Scaleform::GFx::Translator *ptranslator[2]; // [rsp+1B8h] [rbp+F0h]
  __int64 v128; // [rsp+1C8h] [rbp+100h]
  Scaleform::GFx::Translator *v129; // [rsp+1D0h] [rbp+108h]
  Scaleform::GFx::FontMap *v130; // [rsp+1D8h] [rbp+110h]
  Scaleform::GFx::FontMap *v131; // [rsp+1E0h] [rbp+118h]
  Scaleform::GFx::FontLib *v132; // [rsp+1E8h] [rbp+120h]
  Scaleform::Render::Matrix3x4<float> result; // [rsp+1F8h] [rbp+130h] BYREF
  Scaleform::Render::RenderBuffer *v134; // [rsp+2F8h] [rbp+230h]
  int v135; // [rsp+308h] [rbp+240h]
  char v136; // [rsp+310h] [rbp+248h]

  v128 = -2i64;
  v4 = deltaT;
  if ( (this->Flags & 0x100000) != 0 )
  {
    if ( capture )
      Scaleform::GFx::MovieImpl::Capture(this, 1);
    return FLOAT_0_050000001;
  }
  if ( !this->pMainMovie )
  {
    if ( capture )
      Scaleform::GFx::MovieImpl::Capture(this, 1);
    pObject = this->pMainMovieDef.pObject;
    if ( pObject )
      return 1.0
           / ((float (__fastcall *)(Scaleform::GFx::MovieDefImpl *))pObject->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[2].GetKey)(pObject);
    else
      return 0.0;
  }
  Scaleform::GFx::MovieImpl::ProcessMovieDefToKillList(this);
  if ( deltaT < 0.0 )
    v4 = 0.0;
  this->Flags |= 0x200u;
  *(_QWORD *)&Dst.M[2][2] = 0i64;
  v123 = 0i64;
  v124 = 0i64;
  *(_OWORD *)pfontLib = 0i64;
  *(_OWORD *)pfontMap = 0i64;
  *(_OWORD *)ptranslator = 0i64;
  this->pStateBag.pObject->vfptr->GetStatesAddRef(
    &this->pStateBag.pObject->Scaleform::GFx::StateBag,
    (Scaleform::GFx::State **)&v123,
    stateQuery,
    9u);
  v134 = 0i64;
  v9 = (Scaleform::GFx::UserEventHandler *)v123;
  v10 = (Scaleform::Render::RenderBuffer *)this->pUserEventHandler.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->pUserEventHandler.pObject = v9;
  v11 = (Scaleform::GFx::FSCommandHandler *)*((_QWORD *)&v123 + 1);
  v12 = (Scaleform::Render::RenderBuffer *)this->pFSCommandHandler.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  this->pFSCommandHandler.pObject = v11;
  v13 = (Scaleform::GFx::ExternalInterface *)v124;
  v14 = (Scaleform::Render::RenderBuffer *)this->pExtIntfHandler.pObject;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  this->pExtIntfHandler.pObject = v13;
  v15 = *((_QWORD *)&v124 + 1);
  *(_QWORD *)&Dst.M[2][2] = *((_QWORD *)&v124 + 1);
  v134 = (Scaleform::Render::RenderBuffer *)pfontLib[0];
  if ( !pfontLib[0] )
  {
    vfptr = 0i64;
LABEL_24:
    if ( !vfptr )
      goto LABEL_26;
    goto LABEL_25;
  }
  vfptr = pfontLib[0][1].vfptr;
  if ( !vfptr )
  {
    vfptr = (Scaleform::RefCountImplCoreVtbl *)Scaleform::Log::GetGlobalLog();
    goto LABEL_24;
  }
LABEL_25:
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)vfptr);
LABEL_26:
  v17 = (Scaleform::Render::RenderBuffer *)this->pCachedLog.pObject;
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  this->pCachedLog.pObject = (Scaleform::Log *)vfptr;
  v18 = (Scaleform::Render::RenderBuffer *)pfontLib[1];
  v132 = pfontLib[1];
  v19 = (Scaleform::Render::RenderBuffer *)pfontMap[0];
  v131 = pfontMap[0];
  v20 = (Scaleform::Render::RenderBuffer *)pfontMap[1];
  v130 = pfontMap[1];
  v21 = (Scaleform::Render::RenderBuffer *)ptranslator[0];
  v129 = ptranslator[0];
  v22 = Scaleform::GFx::FontManagerStates::CheckStateChange(
          this->pFontManagerStates.pObject,
          pfontLib[1],
          pfontMap[0],
          (Scaleform::GFx::FontProvider *)pfontMap[1],
          ptranslator[0]);
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  if ( v19 )
    Scaleform::RefCountImpl::Release(v19);
  if ( v18 )
    Scaleform::RefCountImpl::Release(v18);
  this->Flags |= 2u;
  Flags = this->Flags;
  if ( v15 )
  {
    if ( (*(_BYTE *)(v15 + 24) & 1) != 0 )
      v24 = Flags | 4;
    else
      v24 = Flags & 0xFFFFFFFB;
    this->Flags = v24;
    if ( (*(_DWORD *)(v15 + 24) & 2) != 0 )
      this->Flags |= 0x40u;
    else
      this->Flags &= ~0x40u;
    if ( (*(_DWORD *)(v15 + 24) & 4) != 0 )
      this->Flags |= 8u;
    else
      this->Flags &= ~8u;
    if ( (*(_DWORD *)(v15 + 24) & 0x10) != 0 )
      this->Flags |= 0x20u;
    else
      this->Flags &= ~0x20u;
    if ( (*(_DWORD *)(v15 + 24) & 8) != 0 )
      this->Flags |= 0x10u;
    else
      this->Flags &= ~0x10u;
  }
  else
  {
    this->Flags = Flags & 0xFFFFFF83;
  }
  for ( i = this->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
  {
    v26 = this == (Scaleform::GFx::MovieImpl *)-112i64 ? 0i64 : &this->MovieLevels.Data.Policy;
    if ( i == (Scaleform::GFx::MovieDefRootNode *)v26 )
      break;
    if ( !i->ImportFlag )
    {
      i->BytesLoaded = i->pDefImpl->pBindData.pObject->BytesLoaded;
      i->LoadingFrame = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))i->pDefImpl->vfptr[1].GetKey)(i->pDefImpl);
    }
    if ( v22 )
      ((void (__fastcall *)(Scaleform::GFx::FontManager *))i->pFontManager.pObject->vfptr[3].__vecDelDtor)(i->pFontManager.pObject);
  }
  if ( v22 || (this->Flags2 & 2) != 0 )
  {
    v27 = 0;
    if ( this->MovieLevels.Data.Size )
    {
      v28 = 0i64;
      do
      {
        v29 = this->MovieLevels.Data.Data[v28].pSprite.pObject;
        v29->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[79].__vecDelDtor(
          v29,
          v22);
        v28 = ++v27;
      }
      while ( v27 < this->MovieLevels.Data.Size );
    }
  }
  if ( !((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pMainMovie->vfptr[111].__vecDelDtor)(this->pMainMovie) )
  {
    if ( v136 )
      Scaleform::GFx::MovieImpl::Capture(this, 1);
    this->Flags &= ~2u;
    if ( v134 )
      Scaleform::RefCountImpl::Release(v134);
    if ( *(_QWORD *)&Dst.M[2][2] )
      Scaleform::RefCountImpl::Release(*(Scaleform::Render::RenderBuffer **)&Dst.M[2][2]);
    return 0.0;
  }
  if ( (this->Flags & 0x100) != 0
    && ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pMainMovie->vfptr[111].__vecDelDtor)(this->pMainMovie) )
  {
    this->Flags &= ~0x100u;
    Size = this->MovieLevels.Data.Size;
    if ( (_DWORD)Size )
    {
      do
      {
        v31 = Size - 1;
        v32 = this->MovieLevels.Data.Data[(unsigned int)(Size - 1)].pSprite.pObject;
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v32->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[112].__vecDelDtor)(v32);
        LODWORD(Size) = v31;
      }
      while ( v31 );
    }
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[7].__vecDelDtor)(this->pASMovieRoot.pObject);
    Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
    Scaleform::GFx::MovieImpl::ProcessLoadQueue(this);
  }
  v33 = v4 * 1000000.0;
  v34 = 0i64;
  if ( (float)(v4 * 1000000.0) >= 9.223372e18 )
  {
    v33 = v33 - 9.223372e18;
    if ( v33 < 9.223372e18 )
      v34 = 0x8000000000000000ui64;
  }
  this->TimeElapsed += v34 + (unsigned int)(int)v33;
  this->TimeRemainder = v4 + this->TimeRemainder;
  ProfileTicks = Scaleform::Timer::GetProfileTicks();
  FrameTime = this->FrameTime;
  v37 = this->IntervalTimers.Data.Size;
  if ( v37 )
  {
    v38 = FrameTime * 1000000.0;
    v39 = 0i64;
    if ( v38 >= 9.223372e18 )
    {
      v38 = v38 - 9.223372e18;
      if ( v38 < 9.223372e18 )
        v39 = 0x8000000000000000ui64;
    }
    v40 = v39 + (unsigned int)(int)v38;
    v41 = 0;
    v42 = 0i64;
    p_IntervalTimers = &this->IntervalTimers;
    do
    {
      v44 = p_IntervalTimers->Data.Data[v42].pObject;
      if ( v44
        && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::ASIntervalTimerIntf *))v44->vfptr[3].__vecDelDtor)(v44) )
      {
        p_IntervalTimers->Data.Data[v42].pObject->vfptr[2].__vecDelDtor(
          p_IntervalTimers->Data.Data[v42].pObject,
          (unsigned int)this);
        v45 = ((__int64 (__fastcall *)(Scaleform::GFx::ASIntervalTimerIntf *))p_IntervalTimers->Data.Data[v42].pObject->vfptr[6].__vecDelDtor)(p_IntervalTimers->Data.Data[v42].pObject)
            - this->TimeElapsed;
        if ( v45 < v40 )
          v40 = v45;
      }
      else
      {
        ++v41;
      }
      ++v42;
    }
    while ( v42 < v37 );
    if ( v41 )
    {
      v46 = this->IntervalTimers.Data.Size;
      for ( j = 0i64; v46; --v46 )
      {
        v48 = p_IntervalTimers->Data.Data[j].pObject;
        if ( v48
          && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::ASIntervalTimerIntf *))v48->vfptr[3].__vecDelDtor)(v48) )
        {
          j = (unsigned int)(j + 1);
        }
        else
        {
          ((void (__fastcall *)(Scaleform::GFx::ASIntervalTimerIntf *))p_IntervalTimers->Data.Data[j].pObject->vfptr[4].__vecDelDtor)(p_IntervalTimers->Data.Data[j].pObject);
          if ( this->IntervalTimers.Data.Size == 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              &this->IntervalTimers.Data,
              &this->IntervalTimers,
              0i64);
          }
          else
          {
            v49 = (Scaleform::Render::RenderBuffer *)p_IntervalTimers->Data.Data[j].pObject;
            if ( v49 )
              Scaleform::RefCountImpl::Release(v49);
            memmove(
              &p_IntervalTimers->Data.Data[j],
              &p_IntervalTimers->Data.Data[j + 1],
              8 * (this->IntervalTimers.Data.Size - (unsigned int)j) - 8);
            --this->IntervalTimers.Data.Size;
          }
        }
      }
    }
    v50 = (float)(int)v40;
    if ( v40 < 0 )
      v50 = v50 + 1.8446744e19;
    FrameTime = v50 * 1000000.0;
  }
  Scaleform::GFx::MovieImpl::ProcessInput(this);
  TimeRemainder = this->TimeRemainder;
  v52 = this->FrameTime;
  if ( TimeRemainder < v52 )
  {
    Scaleform::GFx::MovieImpl::AdvanceFrame(this, 0, TimeRemainder / v52);
    this->TimeRemainder = fmodf(this->TimeRemainder, this->FrameTime);
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[7].__vecDelDtor)(this->pASMovieRoot.pObject);
    Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
    Scaleform::GFx::MovieImpl::ProcessLoadQueue(this);
    v62 = 0i64;
  }
  else
  {
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[7].__vecDelDtor)(this->pASMovieRoot.pObject);
    v53 = v135;
    v54 = v135 || this->ForceFrameCatchUp;
    do
    {
      v55 = this->FrameTime;
      v56 = this->TimeRemainder;
      if ( v54 )
        v57 = v56 - v55;
      else
        v57 = fmodf(v56, this->FrameTime);
      this->TimeRemainder = v57;
      if ( v57 < v55 )
        v58 = v57 / v55;
      else
        v58 = 0.0;
      Scaleform::GFx::MovieImpl::AdvanceFrame(this, 1, v58);
      ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[7].__vecDelDtor)(this->pASMovieRoot.pObject);
      pUnloadListHead = this->pUnloadListHead;
      if ( pUnloadListHead )
      {
        do
        {
          pPlayNextOpt = pUnloadListHead->pPlayNextOpt;
          pUnloadListHead->pPlayNextOpt = 0i64;
          ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))pUnloadListHead->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[75].__vecDelDtor)(pUnloadListHead);
          pParent = pUnloadListHead->pParent;
          if ( pParent )
            pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[117].__vecDelDtor(
              pParent,
              (unsigned int)pUnloadListHead);
          Scaleform::RefCountNTSImpl::Release(pUnloadListHead);
          pUnloadListHead = pPlayNextOpt;
        }
        while ( pPlayNextOpt );
        this->pUnloadListHead = 0i64;
        v53 = v135;
      }
      Scaleform::GFx::MovieImpl::ProcessLoadQueue(this);
      ForceFrameCatchUp = this->ForceFrameCatchUp;
      if ( ForceFrameCatchUp )
        this->ForceFrameCatchUp = ForceFrameCatchUp - 1;
      v64 = v53--;
      v135 = v53;
    }
    while ( v64 && this->FrameTime <= this->TimeRemainder || this->ForceFrameCatchUp );
    this->Flags |= 0x80u;
    LOBYTE(v62) = 1;
  }
  this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[2].__vecDelDtor(this->pASMovieRoot.pObject, v62);
  for ( k = this->DrawingContextList.Root.pNext; ; k = k->pNext )
  {
    v66 = this == (Scaleform::GFx::MovieImpl *)-21248i64 ? 0i64 : &this->RegisteredFonts.Data.Size;
    if ( k == (Scaleform::GFx::DrawingContext *)v66 )
      break;
    if ( k->States < 0 )
      Scaleform::GFx::DrawingContext::UpdateRenderNode(k);
  }
  if ( this->FocusRectChanged )
    Scaleform::GFx::MovieImpl::UpdateFocusRectRenderNodes(this);
  for ( m = 0i64; (unsigned int)m < this->FocusGroupsCnt; m = (unsigned int)(m + 1) )
  {
    v68 = m;
    if ( (this->FocusGroups[m].TabableArrayStatus & 1) != 0 )
    {
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &this->FocusGroups[v68].TabableArray.Data,
        (__int64 *)this->FocusGroups[v68].TabableArray.Data.pHeap,
        0i64);
      this->FocusGroups[v68].TabableArrayStatus = 0;
    }
  }
  this->Flags &= ~2u;
  v69 = Scaleform::Timer::GetProfileTicks() - ProfileTicks;
  v70 = (float)(int)v69;
  if ( v69 < 0 )
    v70 = v70 + 1.8446744e19;
  v71 = FrameTime + (float)(v70 * -0.000001);
  if ( v71 < 0.0 )
    v71 = 0.0;
  if ( v136 )
  {
    if ( !Scaleform::Render::ContextImpl::Context::HasChanges(&this->RenderContext) && !this->MovieDefKillList.Data.Size )
    {
      if ( this->PreviouslyCaptured > 0 )
      {
        LOBYTE(v72) = 1;
        this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[11].__vecDelDtor(
          this->pASMovieRoot.pObject,
          (unsigned int)v72);
        Scaleform::Render::ContextImpl::Context::Capture(&this->RenderContext);
        this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[11].__vecDelDtor(this->pASMovieRoot.pObject, 0);
        --this->PreviouslyCaptured;
      }
      goto LABEL_204;
    }
    v73 = this->IndirectTransformPairs.Data.Size;
    if ( !v73 )
    {
LABEL_197:
      if ( (this->Flags & 0x400) != 0
        || (HasChanges = Scaleform::Render::ContextImpl::Context::HasChanges(&this->RenderContext)) )
      {
        HasChanges = 1;
      }
      if ( HasChanges )
        this->Flags |= 0x400u;
      else
        this->Flags &= ~0x400u;
      LOBYTE(v72) = 1;
      this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[11].__vecDelDtor(
        this->pASMovieRoot.pObject,
        (unsigned int)v72);
      Scaleform::Render::ContextImpl::Context::Capture(&this->RenderContext);
      this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[11].__vecDelDtor(this->pASMovieRoot.pObject, 0);
      this->PreviouslyCaptured = 1;
      goto LABEL_204;
    }
    v74 = 0i64;
    while ( 1 )
    {
      Data = this->IndirectTransformPairs.Data.Data;
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(Data[v74].Obj.pObject);
      pPrev = RenderNode->pPrev;
      if ( RenderNode->pPrev )
      {
        v78 = ((__int64)pPrev->pNext & 0x80040181) != 0;
        if ( ((__int64)pPrev->pNext & 0x80040181) != 0 )
          goto LABEL_178;
      }
      else
      {
        v78 = 0;
      }
      v72 = 0i64;
      v79 = (Scaleform::Render::TreeRoot *)Data[v74].TransformParent.pObject;
      if ( v79 )
      {
        while ( v79 != this->pRenderRoot.pObject )
        {
          if ( v79->pPrev && ((__int64)v79->pPrev->pNext & 0x80040181) != 0 )
          {
            v78 = 1;
            break;
          }
          v79 = (Scaleform::Render::TreeRoot *)v79->pParent;
          v72 = (Scaleform::Render::TreeRoot *)(unsigned int)((_DWORD)v72 + 1);
          if ( !v79 )
            break;
        }
      }
      if ( (_DWORD)v72 == Data[v74].OrigParentDepth )
      {
        if ( !v78 )
        {
          v80 = (Scaleform::Render::TreeRoot *)RenderNode->pParent;
          if ( v80 )
          {
            v72 = this->pRenderRoot.pObject;
            while ( v80 != v72 )
            {
              if ( v80->pPrev && ((__int64)v80->pPrev->pNext & 0x80040181) != 0 )
                goto LABEL_178;
              v80 = (Scaleform::Render::TreeRoot *)v80->pParent;
              if ( !v80 )
                goto LABEL_196;
            }
          }
          goto LABEL_196;
        }
      }
      else
      {
        Data[v74].OrigParentDepth = (int)v72;
      }
LABEL_178:
      pIndXFormData = Data[v74].Obj.pObject->pIndXFormData;
      v82 = pIndXFormData->OrigTransformMatrix.M[0][0];
      v108.M[0][0] = pIndXFormData->OrigTransformMatrix.M[0][0];
      v83 = pIndXFormData->OrigTransformMatrix.M[0][1];
      v108.M[0][1] = v83;
      v84 = pIndXFormData->OrigTransformMatrix.M[0][2];
      v108.M[0][2] = v84;
      v85 = pIndXFormData->OrigTransformMatrix.M[0][3];
      v108.M[0][3] = v85;
      v86 = pIndXFormData->OrigTransformMatrix.M[1][0];
      v108.M[1][0] = v86;
      v87 = pIndXFormData->OrigTransformMatrix.M[1][1];
      v108.M[1][1] = v87;
      v88 = pIndXFormData->OrigTransformMatrix.M[1][2];
      v108.M[1][2] = v88;
      v89 = pIndXFormData->OrigTransformMatrix.M[1][3];
      v108.M[1][3] = v89;
      v90 = pIndXFormData->OrigTransformMatrix.M[2][0];
      Dst.M[1][2] = v90;
      v91 = pIndXFormData->OrigTransformMatrix.M[2][1];
      Dst.M[1][3] = v91;
      v92 = pIndXFormData->OrigTransformMatrix.M[2][2];
      Dst.M[2][0] = v92;
      v93 = pIndXFormData->OrigTransformMatrix.M[2][3];
      Dst.M[2][1] = v93;
      IsOrig3D = pIndXFormData->IsOrig3D;
      v95 = (Scaleform::Render::TreeRoot *)Data[v74].TransformParent.pObject;
      if ( v95 )
      {
        while ( v95 != this->pRenderRoot.pObject )
        {
          v96 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v95 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                          + 8i64 * (unsigned int)((int)((_DWORD)v95 - ((unsigned int)v95 & 0xFFFFF000) - 56) / 56)
                          + 40);
          if ( (*(_WORD *)(v96 + 10) & 0x200) != 0 )
          {
            *(_QWORD *)&v108.M[2][2] = __PAIR64__(LODWORD(v83), LODWORD(v82));
            v109 = v84;
            v110 = v85;
            v111 = v86;
            v112 = v87;
            v113 = v88;
            v114 = v89;
            v115 = v90;
            v116 = v91;
            v117 = v92;
            v118 = v93;
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &v108,
              (Scaleform::Render::Matrix3x4<float> *)(v96 + 16),
              (Scaleform::Render::Matrix3x4<float> *)&v108.M[2][2]);
            IsOrig3D = 1;
          }
          else
          {
            *(_QWORD *)&m2.M[0][0] = __PAIR64__(LODWORD(v83), LODWORD(v82));
            *(_QWORD *)&m2.M[0][2] = __PAIR64__(LODWORD(v85), LODWORD(v84));
            *(_QWORD *)&m2.M[1][0] = __PAIR64__(LODWORD(v87), LODWORD(v86));
            *(_QWORD *)&m2.M[1][2] = __PAIR64__(LODWORD(v89), LODWORD(v88));
            *(_QWORD *)&m2.M[2][0] = __PAIR64__(LODWORD(v91), LODWORD(v90));
            *(_QWORD *)&m2.M[2][2] = __PAIR64__(LODWORD(v93), LODWORD(v92));
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &v108,
              (Scaleform::Render::Matrix2x4<float> *)(v96 + 16),
              &m2);
          }
          v95 = (Scaleform::Render::TreeRoot *)v95->pParent;
          v89 = v108.M[1][3];
          v87 = v108.M[1][1];
          v86 = v108.M[1][0];
          v85 = v108.M[0][3];
          v83 = v108.M[0][1];
          v82 = v108.M[0][0];
          if ( !v95 )
            break;
          v93 = Dst.M[2][1];
          v92 = Dst.M[2][0];
          v91 = Dst.M[1][3];
          v90 = Dst.M[1][2];
          v88 = v108.M[1][2];
          v84 = v108.M[0][2];
        }
      }
      memset(&Dst, 0, sizeof(Dst));
      LODWORD(v97) = (_DWORD)FLOAT_1_0;
      LODWORD(Dst.M[0][0]) = (_DWORD)FLOAT_1_0;
      LODWORD(v98) = (_DWORD)FLOAT_1_0;
      LODWORD(Dst.M[1][1]) = (_DWORD)FLOAT_1_0;
      LODWORD(v99) = (_DWORD)FLOAT_1_0;
      LODWORD(Dst.M[2][2]) = (_DWORD)FLOAT_1_0;
      v100 = (Scaleform::Render::TreeRoot *)RenderNode->pParent;
      if ( v100 )
      {
        while ( v100 != this->pRenderRoot.pObject )
        {
          v101 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v100 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                           + 8i64 * (unsigned int)((int)((_DWORD)v100 - ((unsigned int)v100 & 0xFFFFF000) - 56) / 56)
                           + 40);
          if ( (*(_WORD *)(v101 + 10) & 0x200) != 0 )
          {
            v119.M[0][0] = v97;
            *(_QWORD *)&v119.M[0][1] = *(_QWORD *)&Dst.M[0][1];
            v119.M[0][3] = Dst.M[0][3];
            *(_QWORD *)&v119.M[1][0] = __PAIR64__(LODWORD(v98), LODWORD(Dst.M[1][0]));
            *(_QWORD *)&v119.M[1][2] = *(_QWORD *)&Dst.M[1][2];
            *(_QWORD *)&v119.M[2][0] = *(_QWORD *)&Dst.M[2][0];
            *(_QWORD *)&v119.M[2][2] = __PAIR64__(LODWORD(Dst.M[2][3]), LODWORD(v99));
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &Dst,
              (Scaleform::Render::Matrix3x4<float> *)(v101 + 16),
              &v119);
            IsOrig3D = 1;
          }
          else
          {
            v122.M[0][0] = v97;
            *(_QWORD *)&v122.M[0][1] = *(_QWORD *)&Dst.M[0][1];
            v122.M[0][3] = Dst.M[0][3];
            *(_QWORD *)&v122.M[1][0] = __PAIR64__(LODWORD(v98), LODWORD(Dst.M[1][0]));
            *(_QWORD *)&v122.M[1][2] = *(_QWORD *)&Dst.M[1][2];
            *(_QWORD *)&v122.M[2][0] = *(_QWORD *)&Dst.M[2][0];
            *(_QWORD *)&v122.M[2][2] = __PAIR64__(LODWORD(Dst.M[2][3]), LODWORD(v99));
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &Dst,
              (Scaleform::Render::Matrix2x4<float> *)(v101 + 16),
              &v122);
          }
          v100 = (Scaleform::Render::TreeRoot *)v100->pParent;
          v98 = Dst.M[1][1];
          v97 = Dst.M[0][0];
          if ( !v100 )
            break;
          v99 = Dst.M[2][2];
        }
        v82 = v108.M[0][0];
        v83 = v108.M[0][1];
        v85 = v108.M[0][3];
        v86 = v108.M[1][0];
        v87 = v108.M[1][1];
        v89 = v108.M[1][3];
      }
      if ( IsOrig3D )
      {
        Dst = *Scaleform::Render::Matrix3x4<float>::GetInverse(&Dst, &result);
        m1 = Dst;
        Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&Dst, &m1, &v108);
        Scaleform::Render::TreeNode::SetMatrix3D(RenderNode, &Dst);
      }
      else
      {
        *(_QWORD *)&v108.M[0][2] = __PAIR64__(LODWORD(Dst.M[0][1]), LODWORD(v97));
        *(_QWORD *)&v108.M[1][0] = *(_QWORD *)&Dst.M[0][2];
        *(_QWORD *)&v108.M[1][2] = __PAIR64__(LODWORD(v98), LODWORD(Dst.M[1][0]));
        *(_QWORD *)&v108.M[2][0] = *(_QWORD *)&Dst.M[1][2];
        Scaleform::Render::Matrix2x4<float>::SetInverse(
          (Scaleform::Render::Matrix2x4<float> *)&Dst,
          (Scaleform::Render::Matrix2x4<float> *)&v108.M[0][2]);
        v102 = Dst.M[0][0];
        v103 = Dst.M[0][1];
        v104 = Dst.M[1][0];
        v105 = Dst.M[1][1];
        Dst.M[0][0] = (float)(v86 * Dst.M[0][1]) + (float)(v82 * Dst.M[0][0]);
        Dst.M[1][0] = (float)(v82 * Dst.M[1][0]) + (float)(v86 * Dst.M[1][1]);
        Dst.M[0][1] = (float)(Dst.M[0][1] * v87) + (float)(v102 * v83);
        Dst.M[1][1] = (float)(v104 * v83) + (float)(Dst.M[1][1] * v87);
        Dst.M[1][2] = 0.0;
        Dst.M[0][2] = 0.0;
        Dst.M[0][3] = Dst.M[0][3] + (float)((float)(v102 * v85) + (float)(v103 * v89));
        Dst.M[1][3] = Dst.M[1][3] + (float)((float)(v104 * v85) + (float)(v105 * v89));
        Scaleform::Render::TreeNode::SetMatrix(RenderNode, (Scaleform::Render::Matrix2x4<float> *)&Dst);
      }
LABEL_196:
      ++v74;
      if ( !--v73 )
        goto LABEL_197;
    }
  }
LABEL_204:
  if ( v71 >= (float)(this->FrameTime - this->TimeRemainder) )
    v71 = this->FrameTime - this->TimeRemainder;
  if ( v134 )
    Scaleform::RefCountImpl::Release(v134);
  if ( *(_QWORD *)&Dst.M[2][2] )
    Scaleform::RefCountImpl::Release(*(Scaleform::Render::RenderBuffer **)&Dst.M[2][2]);
  return v71;
}

// File Line: 1758
// RVA: 0x8B98E0
void __fastcall Scaleform::GFx::MovieImpl::Capture(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::TreeRoot *onChangeOnly)
{
  unsigned __int64 Size; // r12
  __int64 v4; // r14
  Scaleform::GFx::MovieImpl::IndirectTransPair *Data; // rbx
  Scaleform::Render::TreeNode *RenderNode; // r15
  Scaleform::Render::ContextImpl::Entry *pPrev; // rcx
  bool v8; // r9
  Scaleform::GFx::DisplayObjectBase *v9; // rax
  Scaleform::Render::TreeRoot *v10; // rbx
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *pIndXFormData; // rcx
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm0_4
  float v15; // xmm9_4
  float v16; // xmm10_4
  float v17; // xmm11_4
  float v18; // xmm1_4
  float v19; // xmm12_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  char IsOrig3D; // si
  __int64 v25; // rdx
  Scaleform::Render::TreeRoot *pObject; // rcx
  Scaleform::Render::TreeRoot *pParent; // rcx
  Scaleform::Render::TreeRoot *v28; // rbx
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  __int64 v32; // rdx
  Scaleform::Render::Matrix3x4<float> *Inverse; // rax
  float v34; // xmm10_4
  float v35; // xmm8_4
  float v36; // xmm6_4
  float v37; // xmm4_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  float v40; // xmm4_4
  float v41; // xmm6_4
  unsigned int v42; // xmm1_4
  float v43; // xmm4_4
  unsigned int v44; // xmm2_4
  float v45; // xmm6_4
  bool HasChanges; // al
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::Render::Matrix3x4<float> v48; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::Render::Matrix3x4<float> v50; // [rsp+B0h] [rbp-50h] BYREF
  Scaleform::Render::Matrix3x4<float> v51; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+110h] [rbp+10h] BYREF
  Scaleform::Render::Matrix3x4<float> v53; // [rsp+140h] [rbp+40h] BYREF
  Scaleform::Render::Matrix3x4<float> result; // [rsp+170h] [rbp+70h] BYREF

  if ( (_BYTE)onChangeOnly
    && !Scaleform::Render::ContextImpl::Context::HasChanges(&this->RenderContext)
    && !this->MovieDefKillList.Data.Size )
  {
    if ( this->PreviouslyCaptured > 0 )
    {
      LOBYTE(onChangeOnly) = 1;
      this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[11].__vecDelDtor(
        this->pASMovieRoot.pObject,
        (unsigned int)onChangeOnly);
      Scaleform::Render::ContextImpl::Context::Capture(&this->RenderContext);
      this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[11].__vecDelDtor(this->pASMovieRoot.pObject, 0);
      --this->PreviouslyCaptured;
    }
    return;
  }
  Size = this->IndirectTransformPairs.Data.Size;
  if ( Size )
  {
    v4 = 0i64;
    do
    {
      Data = this->IndirectTransformPairs.Data.Data;
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(Data[v4].Obj.pObject);
      pPrev = RenderNode->pPrev;
      if ( RenderNode->pPrev )
      {
        v8 = ((__int64)pPrev->pNext & 0x80040181) != 0;
        if ( ((__int64)pPrev->pNext & 0x80040181) != 0 )
          goto LABEL_10;
      }
      else
      {
        v8 = 0;
      }
      pObject = (Scaleform::Render::TreeRoot *)Data[v4].TransformParent.pObject;
      onChangeOnly = 0i64;
      if ( pObject )
      {
        while ( pObject != this->pRenderRoot.pObject )
        {
          if ( pObject->pPrev && ((__int64)pObject->pPrev->pNext & 0x80040181) != 0 )
          {
            v8 = 1;
            break;
          }
          pObject = (Scaleform::Render::TreeRoot *)pObject->pParent;
          onChangeOnly = (Scaleform::Render::TreeRoot *)(unsigned int)((_DWORD)onChangeOnly + 1);
          if ( !pObject )
            break;
        }
      }
      if ( (_DWORD)onChangeOnly == Data[v4].OrigParentDepth )
      {
        if ( !v8 )
        {
          pParent = (Scaleform::Render::TreeRoot *)RenderNode->pParent;
          if ( pParent )
          {
            onChangeOnly = this->pRenderRoot.pObject;
            while ( pParent != onChangeOnly )
            {
              if ( pParent->pPrev && ((__int64)pParent->pPrev->pNext & 0x80040181) != 0 )
                goto LABEL_10;
              pParent = (Scaleform::Render::TreeRoot *)pParent->pParent;
              if ( !pParent )
                goto LABEL_46;
            }
          }
          goto LABEL_46;
        }
      }
      else
      {
        Data[v4].OrigParentDepth = (int)onChangeOnly;
      }
LABEL_10:
      v9 = Data[v4].Obj.pObject;
      v10 = (Scaleform::Render::TreeRoot *)Data[v4].TransformParent.pObject;
      pIndXFormData = v9->pIndXFormData;
      v12 = pIndXFormData->OrigTransformMatrix.M[0][0];
      v48.M[0][0] = pIndXFormData->OrigTransformMatrix.M[0][0];
      v13 = pIndXFormData->OrigTransformMatrix.M[0][1];
      v48.M[0][1] = v13;
      v14 = pIndXFormData->OrigTransformMatrix.M[0][2];
      v48.M[0][2] = v14;
      v15 = pIndXFormData->OrigTransformMatrix.M[0][3];
      v48.M[0][3] = v15;
      v16 = pIndXFormData->OrigTransformMatrix.M[1][0];
      v48.M[1][0] = v16;
      v17 = pIndXFormData->OrigTransformMatrix.M[1][1];
      v48.M[1][1] = v17;
      v18 = pIndXFormData->OrigTransformMatrix.M[1][2];
      v48.M[1][2] = v18;
      v19 = pIndXFormData->OrigTransformMatrix.M[1][3];
      v48.M[1][3] = v19;
      v20 = pIndXFormData->OrigTransformMatrix.M[2][0];
      v48.M[2][0] = v20;
      v21 = pIndXFormData->OrigTransformMatrix.M[2][1];
      v48.M[2][1] = v21;
      v22 = pIndXFormData->OrigTransformMatrix.M[2][2];
      v48.M[2][2] = v22;
      v23 = pIndXFormData->OrigTransformMatrix.M[2][3];
      v48.M[2][3] = v23;
      IsOrig3D = pIndXFormData->IsOrig3D;
      if ( v10 )
      {
        while ( v10 != this->pRenderRoot.pObject )
        {
          v25 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v10 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                          + 8i64 * (unsigned int)((int)((_DWORD)v10 - ((unsigned int)v10 & 0xFFFFF000) - 56) / 56)
                          + 40);
          if ( (*(_WORD *)(v25 + 10) & 0x200) != 0 )
          {
            *(_QWORD *)&m2.M[0][0] = __PAIR64__(LODWORD(v13), LODWORD(v12));
            *(_QWORD *)&m2.M[0][2] = __PAIR64__(LODWORD(v15), LODWORD(v14));
            *(_QWORD *)&m2.M[1][0] = __PAIR64__(LODWORD(v17), LODWORD(v16));
            *(_QWORD *)&m2.M[1][2] = __PAIR64__(LODWORD(v19), LODWORD(v18));
            *(_QWORD *)&m2.M[2][0] = __PAIR64__(LODWORD(v21), LODWORD(v20));
            *(_QWORD *)&m2.M[2][2] = __PAIR64__(LODWORD(v23), LODWORD(v22));
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &v48,
              (Scaleform::Render::Matrix3x4<float> *)(v25 + 16),
              &m2);
            IsOrig3D = 1;
          }
          else
          {
            *(_QWORD *)&v51.M[0][0] = __PAIR64__(LODWORD(v13), LODWORD(v12));
            *(_QWORD *)&v51.M[0][2] = __PAIR64__(LODWORD(v15), LODWORD(v14));
            *(_QWORD *)&v51.M[1][0] = __PAIR64__(LODWORD(v17), LODWORD(v16));
            *(_QWORD *)&v51.M[1][2] = __PAIR64__(LODWORD(v19), LODWORD(v18));
            *(_QWORD *)&v51.M[2][0] = __PAIR64__(LODWORD(v21), LODWORD(v20));
            *(_QWORD *)&v51.M[2][2] = __PAIR64__(LODWORD(v23), LODWORD(v22));
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &v48,
              (Scaleform::Render::Matrix2x4<float> *)(v25 + 16),
              &v51);
          }
          v10 = (Scaleform::Render::TreeRoot *)v10->pParent;
          v19 = v48.M[1][3];
          v17 = v48.M[1][1];
          v16 = v48.M[1][0];
          v15 = v48.M[0][3];
          v13 = v48.M[0][1];
          v12 = v48.M[0][0];
          if ( !v10 )
            break;
          v23 = v48.M[2][3];
          v22 = v48.M[2][2];
          v21 = v48.M[2][1];
          v20 = v48.M[2][0];
          v18 = v48.M[1][2];
          v14 = v48.M[0][2];
        }
      }
      memset(&Dst, 0, sizeof(Dst));
      v28 = (Scaleform::Render::TreeRoot *)RenderNode->pParent;
      v29 = *(float *)&FLOAT_1_0;
      LODWORD(v30) = (_DWORD)FLOAT_1_0;
      LODWORD(v31) = (_DWORD)FLOAT_1_0;
      LODWORD(Dst.M[0][0]) = (_DWORD)FLOAT_1_0;
      LODWORD(Dst.M[1][1]) = (_DWORD)FLOAT_1_0;
      LODWORD(Dst.M[2][2]) = (_DWORD)FLOAT_1_0;
      if ( v28 )
      {
        while ( v28 != this->pRenderRoot.pObject )
        {
          v32 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v28 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                          + 8i64 * (unsigned int)((int)((_DWORD)v28 - ((unsigned int)v28 & 0xFFFFF000) - 56) / 56)
                          + 40);
          if ( (*(_WORD *)(v32 + 10) & 0x200) != 0 )
          {
            v50.M[0][0] = v29;
            *(_QWORD *)&v50.M[0][1] = *(_QWORD *)&Dst.M[0][1];
            v50.M[0][3] = Dst.M[0][3];
            *(_QWORD *)&v50.M[1][0] = __PAIR64__(LODWORD(v30), LODWORD(Dst.M[1][0]));
            *(_QWORD *)&v50.M[1][2] = *(_QWORD *)&Dst.M[1][2];
            *(_QWORD *)&v50.M[2][0] = *(_QWORD *)&Dst.M[2][0];
            *(_QWORD *)&v50.M[2][2] = __PAIR64__(LODWORD(Dst.M[2][3]), LODWORD(v31));
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &Dst,
              (Scaleform::Render::Matrix3x4<float> *)(v32 + 16),
              &v50);
            IsOrig3D = 1;
          }
          else
          {
            v53.M[0][0] = v29;
            *(_QWORD *)&v53.M[0][1] = *(_QWORD *)&Dst.M[0][1];
            v53.M[0][3] = Dst.M[0][3];
            *(_QWORD *)&v53.M[1][0] = __PAIR64__(LODWORD(v30), LODWORD(Dst.M[1][0]));
            *(_QWORD *)&v53.M[1][2] = *(_QWORD *)&Dst.M[1][2];
            *(_QWORD *)&v53.M[2][0] = *(_QWORD *)&Dst.M[2][0];
            *(_QWORD *)&v53.M[2][2] = __PAIR64__(LODWORD(Dst.M[2][3]), LODWORD(v31));
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &Dst,
              (Scaleform::Render::Matrix2x4<float> *)(v32 + 16),
              &v53);
          }
          v28 = (Scaleform::Render::TreeRoot *)v28->pParent;
          v30 = Dst.M[1][1];
          v29 = Dst.M[0][0];
          if ( !v28 )
            break;
          v31 = Dst.M[2][2];
        }
        v12 = v48.M[0][0];
        v13 = v48.M[0][1];
        v15 = v48.M[0][3];
        v16 = v48.M[1][0];
        v17 = v48.M[1][1];
        v19 = v48.M[1][3];
      }
      if ( IsOrig3D )
      {
        Inverse = Scaleform::Render::Matrix3x4<float>::GetInverse(&Dst, &result);
        Dst.M[0][0] = Inverse->M[0][0];
        v34 = Inverse->M[0][1];
        *(_QWORD *)&m1.M[0][0] = __PAIR64__(LODWORD(v34), LODWORD(Dst.M[0][0]));
        Dst.M[0][1] = v34;
        Dst.M[0][2] = Inverse->M[0][2];
        v35 = Inverse->M[0][3];
        *(_QWORD *)&m1.M[0][2] = __PAIR64__(LODWORD(v35), LODWORD(Dst.M[0][2]));
        Dst.M[0][3] = v35;
        Dst.M[1][0] = Inverse->M[1][0];
        v36 = Inverse->M[1][1];
        *(_QWORD *)&m1.M[1][0] = __PAIR64__(LODWORD(v36), LODWORD(Dst.M[1][0]));
        Dst.M[1][1] = v36;
        Dst.M[1][2] = Inverse->M[1][2];
        v37 = Inverse->M[1][3];
        *(_QWORD *)&m1.M[1][2] = __PAIR64__(LODWORD(v37), LODWORD(Dst.M[1][2]));
        Dst.M[1][3] = v37;
        Dst.M[2][0] = Inverse->M[2][0];
        v38 = Inverse->M[2][1];
        *(_QWORD *)&m1.M[2][0] = __PAIR64__(LODWORD(v38), LODWORD(Dst.M[2][0]));
        Dst.M[2][1] = v38;
        Dst.M[2][2] = Inverse->M[2][2];
        v39 = Inverse->M[2][3];
        *(_QWORD *)&m1.M[2][2] = __PAIR64__(LODWORD(v39), LODWORD(Dst.M[2][2]));
        Dst.M[2][3] = v39;
        Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&Dst, &m1, &v48);
        Scaleform::Render::TreeNode::SetMatrix3D(RenderNode, &Dst);
      }
      else
      {
        result.M[0][0] = v29;
        *(_QWORD *)&result.M[0][1] = *(_QWORD *)&Dst.M[0][1];
        result.M[0][3] = Dst.M[0][3];
        *(_QWORD *)&result.M[1][0] = __PAIR64__(LODWORD(v30), LODWORD(Dst.M[1][0]));
        *(_QWORD *)&result.M[1][2] = *(_QWORD *)&Dst.M[1][2];
        Scaleform::Render::Matrix2x4<float>::SetInverse(
          (Scaleform::Render::Matrix2x4<float> *)&Dst,
          (Scaleform::Render::Matrix2x4<float> *)&result);
        v40 = Dst.M[0][0];
        v41 = Dst.M[1][0];
        Dst.M[0][0] = (float)(Dst.M[0][1] * v16) + (float)(Dst.M[0][0] * v12);
        Dst.M[1][0] = (float)(Dst.M[1][0] * v12) + (float)(Dst.M[1][1] * v16);
        *(float *)&v42 = (float)(Dst.M[0][1] * v17) + (float)(v40 * v13);
        v43 = (float)(v40 * v15) + (float)(Dst.M[0][1] * v19);
        *(_QWORD *)&Dst.M[0][1] = v42;
        *(float *)&v44 = (float)(v41 * v13) + (float)(Dst.M[1][1] * v17);
        v45 = (float)(v41 * v15) + (float)(Dst.M[1][1] * v19);
        *(_QWORD *)&Dst.M[1][1] = v44;
        Dst.M[0][3] = Dst.M[0][3] + v43;
        Dst.M[1][3] = Dst.M[1][3] + v45;
        Scaleform::Render::TreeNode::SetMatrix(RenderNode, (Scaleform::Render::Matrix2x4<float> *)&Dst);
      }
LABEL_46:
      ++v4;
      --Size;
    }
    while ( Size );
  }
  if ( (this->Flags & 0x400) != 0
    || (HasChanges = Scaleform::Render::ContextImpl::Context::HasChanges(&this->RenderContext)) )
  {
    HasChanges = 1;
  }
  if ( HasChanges )
    this->Flags |= 0x400u;
  else
    this->Flags &= ~0x400u;
  LOBYTE(onChangeOnly) = 1;
  this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[11].__vecDelDtor(
    this->pASMovieRoot.pObject,
    (unsigned int)onChangeOnly);
  Scaleform::Render::ContextImpl::Context::Capture(&this->RenderContext);
  this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[11].__vecDelDtor(this->pASMovieRoot.pObject, 0);
  this->PreviouslyCaptured = 1;
}

// File Line: 1901
// RVA: 0x8F30A0
void __fastcall Scaleform::GFx::MovieImpl::ProcessInput(Scaleform::GFx::MovieImpl *this)
{
  bool v2; // r13
  int v3; // r14d
  int v4; // esi
  Scaleform::GFx::InputEventsQueueEntry *Entry; // rdx
  Scaleform::GFx::InputEventsQueueEntry::QueueEntryType t; // eax
  float x; // r12d
  unsigned int i; // edi
  char *v9; // r15
  float v10; // xmm1_4
  Scaleform::GFx::InteractiveObject *TopMostEntity; // rax
  Scaleform::GFx::InteractiveObject *v12; // rsi
  __int64 v13; // [rsp+30h] [rbp-69h] BYREF
  int v14; // [rsp+38h] [rbp-61h]
  char v15; // [rsp+3Ch] [rbp-5Dh]
  int v16; // [rsp+40h] [rbp-59h]
  Scaleform::String *Code; // [rsp+48h] [rbp-51h]
  Scaleform::String *Level; // [rsp+50h] [rbp-49h]
  Scaleform::String *ExtensionId; // [rsp+58h] [rbp-41h]
  Scaleform::String *ContextId; // [rsp+60h] [rbp-39h]
  Scaleform::GFx::ProcessFocusKeyInfo focusKeyInfo; // [rsp+70h] [rbp-29h] BYREF
  __int64 v22; // [rsp+B0h] [rbp+17h]
  Scaleform::Render::Point<float> miceProceededMask; // [rsp+100h] [rbp+67h] BYREF
  Scaleform::GFx::InteractiveObject *v24; // [rsp+108h] [rbp+6Fh]

  v22 = -2i64;
  if ( this->pMainMovie )
  {
    v2 = this->pASMovieRoot.pObject->AVMVersion == 2;
    *(_OWORD *)&focusKeyInfo.pFocusGroup = 0i64;
    focusKeyInfo.CurFocusIdx = -1;
    memset(&focusKeyInfo.Prev_aRect, 0, 29);
    miceProceededMask.x = 0.0;
    v3 = 1;
    v4 = (1 << this->MouseCursorCount) - 1;
    while ( this->InputEventsQueue.UsedEntries || this->InputEventsQueue.LastMousePosMask )
    {
      Entry = Scaleform::GFx::InputEventsQueue::GetEntry(&this->InputEventsQueue);
      t = Entry->t;
      if ( Entry->t == QE_Key )
      {
        Scaleform::GFx::MovieImpl::ProcessKeyboard(this, Entry, &focusKeyInfo);
      }
      else if ( t )
      {
        switch ( t )
        {
          case QE_Status:
            v13 = 16777254i64;
            v14 = 0;
            v15 = 0;
            v16 = 65280;
            Code = Entry->u.statusEntry.Code;
            Level = Entry->u.statusEntry.Level;
            ExtensionId = Entry->u.statusEntry.ExtensionId;
            ContextId = Entry->u.statusEntry.ContextId;
            this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[23].__vecDelDtor(
              this->pASMovieRoot.pObject,
              (unsigned int)&v13);
            break;
          case QE_Accelerometer:
            Scaleform::GFx::MovieImpl::ProcessAccelerometer(this, Entry);
            break;
          case QE_Geolocation:
            Scaleform::GFx::MovieImpl::ProcessGeolocation(this, Entry);
            break;
        }
      }
      else
      {
        Scaleform::GFx::MovieImpl::ProcessMouse(this, Entry, (unsigned int *)&miceProceededMask, v2);
      }
    }
    if ( (this->Flags & 0x80) != 0 )
    {
      x = miceProceededMask.x;
      if ( (LODWORD(miceProceededMask.x) & v4) != v4 )
      {
        for ( i = 0; i < this->MouseCursorCount; v3 *= 2 )
        {
          if ( (v3 & LODWORD(x)) == 0 && (*((_BYTE *)&this->mMouseState[i] + 76) & 0x10) != 0 )
          {
            v9 = (char *)this + 80 * i;
            *((_DWORD *)v9 + 2187) = *((_DWORD *)v9 + 2186);
            v10 = *((float *)v9 + 2189);
            miceProceededMask.x = *((float *)v9 + 2188);
            miceProceededMask.y = v10;
            TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(this, &miceProceededMask, i, v2, 0i64);
            v12 = TopMostEntity;
            if ( TopMostEntity )
              ++TopMostEntity->RefCount;
            v24 = TopMostEntity;
            Scaleform::GFx::MouseState::SetTopmostEntity((Scaleform::GFx::MouseState *)(v9 + 8696), TopMostEntity);
            Scaleform::GFx::MovieImpl::CheckMouseCursorType(this, i, v12);
            this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[13].__vecDelDtor(this->pASMovieRoot.pObject, i);
            if ( v12 )
              Scaleform::RefCountNTSImpl::Release(v12);
          }
          ++i;
        }
      }
    }
    Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(this, &focusKeyInfo);
    this->Flags &= ~0x80u;
    if ( focusKeyInfo.CurFocused.pObject )
      Scaleform::RefCountNTSImpl::Release(focusKeyInfo.CurFocused.pObject);
  }
}

// File Line: 2012
// RVA: 0x8F0D30
void __fastcall Scaleform::GFx::MovieImpl::ProcessAccelerometer(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::InputEventsQueueEntry *qe)
{
  Scaleform::String *Level; // xmm0_8
  Scaleform::String *ExtensionId; // xmm1_8
  unsigned int WcharCode; // r8d
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::String *ContextId; // xmm0_8
  long double AccelerationZ; // xmm1_8
  __int64 v8; // [rsp+20h] [rbp-48h] BYREF
  int v9; // [rsp+28h] [rbp-40h]
  char v10; // [rsp+2Ch] [rbp-3Ch]
  int v11; // [rsp+30h] [rbp-38h]
  unsigned int v12; // [rsp+34h] [rbp-34h]
  Scaleform::String *v13; // [rsp+38h] [rbp-30h]
  Scaleform::String *v14; // [rsp+40h] [rbp-28h]
  Scaleform::String *v15; // [rsp+48h] [rbp-20h]
  long double v16; // [rsp+50h] [rbp-18h]

  Level = qe->u.statusEntry.Level;
  ExtensionId = qe->u.statusEntry.ExtensionId;
  WcharCode = qe->u.keyEntry.WcharCode;
  pObject = this->pASMovieRoot.pObject;
  v8 = 16777252i64;
  v13 = Level;
  ContextId = qe->u.statusEntry.ContextId;
  v14 = ExtensionId;
  v9 = 0;
  v10 = 0;
  v11 = 65280;
  AccelerationZ = qe->u.accelerometerEntry.AccelerationZ;
  v15 = ContextId;
  v12 = WcharCode;
  v16 = AccelerationZ;
  pObject->vfptr[24].__vecDelDtor(pObject, (unsigned int)&v8);
}

// File Line: 2024
// RVA: 0x8F2040
void __fastcall Scaleform::GFx::MovieImpl::ProcessGeolocation(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::InputEventsQueueEntry *qe)
{
  Scaleform::String *Level; // xmm0_8
  Scaleform::String *ExtensionId; // xmm1_8
  unsigned int WcharCode; // r8d
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::String *ContextId; // xmm0_8
  long double AccelerationZ; // xmm1_8
  long double VAccuracy; // xmm0_8
  long double Speed; // xmm1_8
  long double Heading; // xmm0_8
  long double Timestamp; // xmm1_8
  __int64 v12; // [rsp+20h] [rbp-68h] BYREF
  int v13; // [rsp+28h] [rbp-60h]
  char v14; // [rsp+2Ch] [rbp-5Ch]
  int v15; // [rsp+30h] [rbp-58h]
  unsigned int v16; // [rsp+34h] [rbp-54h]
  Scaleform::String *v17; // [rsp+38h] [rbp-50h]
  Scaleform::String *v18; // [rsp+40h] [rbp-48h]
  Scaleform::String *v19; // [rsp+48h] [rbp-40h]
  long double v20; // [rsp+50h] [rbp-38h]
  long double v21; // [rsp+58h] [rbp-30h]
  long double v22; // [rsp+60h] [rbp-28h]
  long double v23; // [rsp+68h] [rbp-20h]
  long double v24; // [rsp+70h] [rbp-18h]

  Level = qe->u.statusEntry.Level;
  ExtensionId = qe->u.statusEntry.ExtensionId;
  WcharCode = qe->u.keyEntry.WcharCode;
  pObject = this->pASMovieRoot.pObject;
  v12 = 16777253i64;
  v17 = Level;
  ContextId = qe->u.statusEntry.ContextId;
  v18 = ExtensionId;
  v13 = 0;
  v14 = 0;
  v15 = 65280;
  AccelerationZ = qe->u.accelerometerEntry.AccelerationZ;
  v19 = ContextId;
  VAccuracy = qe->u.geolocationEntry.VAccuracy;
  v16 = WcharCode;
  v20 = AccelerationZ;
  Speed = qe->u.geolocationEntry.Speed;
  v21 = VAccuracy;
  Heading = qe->u.geolocationEntry.Heading;
  v22 = Speed;
  Timestamp = qe->u.geolocationEntry.Timestamp;
  v23 = Heading;
  v24 = Timestamp;
  pObject->vfptr[25].__vecDelDtor(pObject, (unsigned int)&v12);
}

// File Line: 2040
// RVA: 0x8F3320
void __fastcall Scaleform::GFx::MovieImpl::ProcessKeyboard(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::InputEventsQueueEntry *qe,
        Scaleform::GFx::ProcessFocusKeyInfo *focusKeyInfo)
{
  Scaleform::GFx::KeyboardState *v5; // rbp
  unsigned int v6; // r10d
  Scaleform::GFx::InputEventsQueueEntry::Entry *p_u; // rdi
  unsigned int Code; // r9d
  unsigned __int8 v9; // al
  Scaleform::GFx::Event::EventType v10; // r14d
  int v11; // r8d
  char v12; // al
  char v13; // dl
  char v14; // cl
  __int64 v15; // rax
  __int64 v16; // r9
  int Size; // ebx
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v19; // rax
  Scaleform::GFx::InteractiveObject *pMainMovie; // rdx
  Scaleform::GFx::KeyboardState::IListener *pListener; // rcx
  unsigned int v22; // eax
  Scaleform::GFx::Sprite *v23; // rbx
  int v24[3]; // [rsp+30h] [rbp-48h] BYREF
  char AsciiCode; // [rsp+3Ch] [rbp-3Ch]
  char v26; // [rsp+40h] [rbp-38h]
  char WheelScrollDelta; // [rsp+41h] [rbp-37h]
  char v28; // [rsp+42h] [rbp-36h]
  char v29; // [rsp+43h] [rbp-35h]
  unsigned int v30; // [rsp+88h] [rbp+10h] BYREF
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+98h] [rbp+20h] BYREF

  v5 = 0i64;
  v6 = 0;
  v30 = 0;
  p_u = &qe->u;
  Code = qe->u.keyEntry.Code;
  if ( Code )
  {
    if ( qe->u.mouseEntry.Flags )
    {
      v9 = 64;
      v10 = F3_720_512;
    }
    else
    {
      v9 = 0x80;
      v10 = F5_360_512;
    }
    v11 = v9;
    v24[0] = v9;
    v24[1] = p_u->keyEntry.WcharCode;
    v24[2] = Code;
    AsciiCode = qe->u.keyEntry.AsciiCode;
    v26 = 0;
    v29 = 0;
    WheelScrollDelta = qe->u.mouseEntry.WheelScrollDelta;
    v12 = qe->u.keyEntry.KeysState | 0x80;
    v28 = v12;
    if ( !AsciiCode )
    {
      v13 = 0;
      v14 = v12 & 1;
      if ( (v12 & 8) != 0 )
        v14 = v14 == 0;
      v15 = Code - 32;
      if ( (unsigned int)v15 > 0x50 )
      {
        v16 = Code - 186;
        if ( (unsigned int)v16 <= 0x50 )
        {
          if ( v14 )
            v13 = asciiShift2[v16];
          else
            v13 = ascii2[v16];
        }
      }
      else if ( v14 )
      {
        v13 = asciiShift1[v15];
      }
      else
      {
        v13 = ascii1[v15];
      }
      AsciiCode = v13;
    }
    Size = this->MovieLevels.Data.Size;
    if ( Size )
    {
      do
      {
        pObject = this->MovieLevels.Data.Data[--Size].pSprite.pObject;
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, int *, unsigned int *))pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[101].__vecDelDtor)(
          pObject,
          v24,
          &v30);
      }
      while ( Size );
      v6 = v30;
      v11 = v24[0];
    }
    v19 = (unsigned __int8)p_u->mouseEntry.WheelScrollDelta;
    if ( (unsigned int)v19 < 6 )
      v5 = &this->KeyboardStates[v19];
    pMainMovie = this->pMainMovie;
    pListener = v5->pListener;
    if ( pListener )
    {
      if ( v11 == 64 )
      {
        ((void (__fastcall *)(Scaleform::GFx::KeyboardState::IListener *, Scaleform::GFx::InteractiveObject *, int *, _QWORD, __int64))pListener->vfptr->OnKeyDown)(
          pListener,
          pMainMovie,
          v24,
          v6,
          -2i64);
      }
      else if ( v11 == 128 )
      {
        ((void (__fastcall *)(Scaleform::GFx::KeyboardState::IListener *, Scaleform::GFx::InteractiveObject *, int *, _QWORD, __int64))pListener->vfptr->OnKeyUp)(
          pListener,
          pMainMovie,
          v24,
          v6,
          -2i64);
      }
    }
    v22 = this->Flags >> 30;
    if ( v22 == 3 )
      v22 = -1;
    if ( v22 != 1 )
      Scaleform::GFx::MovieImpl::ProcessFocusKey(
        this,
        v10,
        (Scaleform::GFx::InputEventsQueueEntry::KeyEntry *)p_u,
        focusKeyInfo);
  }
  else if ( p_u->keyEntry.WcharCode )
  {
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[(unsigned __int8)qe->u.mouseEntry.WheelScrollDelta]].LastFocused,
      &result);
    v23 = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      v23 = result.pObject;
    }
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release(result.pObject);
    if ( v23 )
      ((void (__fastcall *)(Scaleform::GFx::Sprite *, _QWORD, _QWORD))v23->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[97].__vecDelDtor)(
        v23,
        p_u->keyEntry.WcharCode,
        (unsigned __int8)p_u->mouseEntry.WheelScrollDelta);
    if ( v23 )
      Scaleform::RefCountNTSImpl::Release(v23);
  }
}

// File Line: 2102
// RVA: 0x8F36F0
void __fastcall Scaleform::GFx::MovieImpl::ProcessMouse(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::InputEventsQueueEntry *qe,
        unsigned int *miceProceededMask,
        bool avm2)
{
  __int64 MouseIndex; // rsi
  __int64 v7; // r12
  Scaleform::GFx::MouseState *v8; // r13
  char v9; // dl
  unsigned int CurButtonsState; // r8d
  unsigned __int16 ButtonsState; // cx
  char Flags; // al
  char v13; // dl
  unsigned int Code; // xmm0_4
  float PosY; // xmm1_4
  Scaleform::GFx::InteractiveObject *TopMostEntity; // rax
  Scaleform::GFx::InteractiveObject *v17; // r14
  Scaleform::GFx::InteractiveObject *pCharacter; // rcx
  int v19; // r15d
  char v20; // al
  unsigned __int64 Size; // rax
  char pObject; // r13
  __int64 v23; // r14
  int v24; // r12d
  Scaleform::GFx::InteractiveObject *v25; // rsi
  unsigned int v26; // ecx
  Scaleform::GFx::Sprite *v27; // rbx
  Scaleform::GFx::InteractiveObject *v28; // [rsp+30h] [rbp-40h]
  Scaleform::GFx::MouseState *v29; // [rsp+38h] [rbp-38h]
  _BYTE v30[12]; // [rsp+50h] [rbp-20h] BYREF
  char v31; // [rsp+5Ch] [rbp-14h]
  char v32; // [rsp+60h] [rbp-10h]
  char v33; // [rsp+61h] [rbp-Fh]
  __int16 v34; // [rsp+62h] [rbp-Eh]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+B0h] [rbp+40h] BYREF
  Scaleform::Render::Point<float> mousePos; // [rsp+B8h] [rbp+48h] BYREF
  __int64 v37; // [rsp+C0h] [rbp+50h]

  *miceProceededMask |= 1 << qe->u.mouseEntry.MouseIndex;
  MouseIndex = (unsigned __int8)qe->u.mouseEntry.MouseIndex;
  LODWORD(result.pObject) = (unsigned __int8)qe->u.mouseEntry.MouseIndex;
  v7 = 80 * MouseIndex;
  v37 = 80 * MouseIndex;
  v8 = &this->mMouseState[MouseIndex];
  v29 = v8;
  *((_BYTE *)v8 + 76) |= 0x10u;
  v9 = *((_BYTE *)v8 + 76);
  CurButtonsState = v8->CurButtonsState;
  v8->PrevButtonsState = CurButtonsState;
  ButtonsState = qe->u.mouseEntry.ButtonsState;
  if ( ButtonsState )
  {
    Flags = qe->u.mouseEntry.Flags;
    if ( (Flags & 0x40) != 0 || Flags >= 0 )
      v8->CurButtonsState = CurButtonsState | ButtonsState;
    else
      v8->CurButtonsState = CurButtonsState & ~ButtonsState;
  }
  if ( (qe->u.mouseEntry.Flags & 0x20) != 0 )
    v8->WheelDelta = qe->u.mouseEntry.WheelScrollDelta;
  else
    v8->WheelDelta = 0;
  if ( qe->u.accelerometerEntry.IdAcc == SLODWORD(v8->LastPosition.x)
    && qe->u.keyEntry.Code == SLODWORD(v8->LastPosition.y) )
  {
    v13 = v9 & 0xF7;
  }
  else
  {
    v13 = v9 | 8;
  }
  *((_BYTE *)v8 + 76) = v13;
  Code = qe->u.keyEntry.Code;
  LODWORD(v8->LastPosition.x) = qe->u.keyEntry.WcharCode;
  LODWORD(v8->LastPosition.y) = Code;
  PosY = qe->u.mouseEntry.PosY;
  LODWORD(mousePos.x) = qe->u.keyEntry.WcharCode;
  mousePos.y = PosY;
  TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(this, &mousePos, MouseIndex, avm2, 0i64);
  v17 = TopMostEntity;
  v28 = TopMostEntity;
  if ( TopMostEntity )
    ++TopMostEntity->RefCount;
  Scaleform::GFx::MouseState::SetTopmostEntity(v8, TopMostEntity);
  pCharacter = this->CurrentDragStates[MouseIndex].pCharacter;
  if ( pCharacter )
    Scaleform::GFx::InteractiveObject::DoMouseDrag(pCharacter, MouseIndex);
  v19 = 0;
  if ( qe->u.mouseEntry.ButtonsState && (qe->u.keyEntry.AsciiCode & 1) != 0 )
  {
    if ( (qe->u.mouseEntry.Flags & 0xC0) != 0 || (v20 = 1, !qe->u.mouseEntry.ButtonsState) )
      v20 = 0;
    v19 = 32;
    if ( v20 )
      v19 = 16;
  }
  Size = this->MovieLevels.Data.Size;
  if ( (_DWORD)Size )
  {
    pObject = (char)result.pObject;
    v23 = v37;
    do
    {
      v24 = Size - 1;
      v25 = this->MovieLevels.Data.Data[(unsigned int)(Size - 1)].pSprite.pObject;
      if ( v19 )
      {
        *(_DWORD *)v30 = v19;
        *(_QWORD *)&v30[4] = 0i64;
        v34 = 0;
        v31 = 0;
        v33 = pObject;
        v32 = 0;
        v25->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[99].__vecDelDtor(
          v25,
          (unsigned int)v30);
      }
      if ( (*((_BYTE *)this->mMouseState + v23 + 76) & 8) != 0 )
      {
        *(_QWORD *)v30 = 8i64;
        *(_DWORD *)&v30[8] = 0;
        v34 = 0;
        v31 = 0;
        v33 = pObject;
        v32 = 0;
        v25->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[99].__vecDelDtor(
          v25,
          (unsigned int)v30);
      }
      LODWORD(Size) = v24;
    }
    while ( v24 );
    v17 = v28;
    v8 = v29;
    LODWORD(MouseIndex) = result.pObject;
    v7 = v37;
  }
  if ( (this->Flags & 0x10000) == 0 && qe->u.mouseEntry.ButtonsState )
    goto LABEL_38;
  v26 = (this->Flags >> 22) & 3;
  if ( v26 == 3 )
    v26 = -1;
  if ( v26 != 1 && (*((_BYTE *)this->mMouseState + v7 + 76) & 8) != 0 )
LABEL_38:
    Scaleform::GFx::MovieImpl::HideFocusRect(this, MouseIndex);
  if ( (qe->u.mouseEntry.Flags & 0x20) != 0 && v17 )
    v17->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[98].__vecDelDtor(
      v17,
      qe->u.mouseEntry.WheelScrollDelta);
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::InputEventsQueueEntry *, Scaleform::GFx::MouseState *, _QWORD))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[18].__vecDelDtor)(
    this->pASMovieRoot.pObject,
    qe,
    v8,
    (unsigned int)MouseIndex);
  Scaleform::GFx::MovieImpl::CheckMouseCursorType(this, MouseIndex, v17);
  if ( (qe->u.mouseEntry.Flags & 0xC0) == 0 && qe->u.mouseEntry.ButtonsState && (qe->u.keyEntry.AsciiCode & 1) != 0 )
  {
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[(unsigned int)MouseIndex]].LastFocused,
      &result);
    v27 = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      v27 = result.pObject;
    }
    mousePos = (Scaleform::Render::Point<float>)v27;
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release(result.pObject);
    if ( v17 != v27 )
      Scaleform::GFx::MovieImpl::QueueSetFocusTo(this, v17, v17, MouseIndex, GFx_FocusMovedByMouse, 0i64);
    if ( v27 )
      Scaleform::RefCountNTSImpl::Release(v27);
  }
  this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[13].__vecDelDtor(this->pASMovieRoot.pObject, MouseIndex);
  if ( v17 )
    Scaleform::RefCountNTSImpl::Release(v17);
}

// File Line: 2211
// RVA: 0x906EF0
void __fastcall Scaleform::GFx::MovieImpl::SetDragState(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieImpl::DragState *st)
{
  __int64 MouseIndex; // r8
  float y; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4

  MouseIndex = st->MouseIndex;
  this->CurrentDragStates[MouseIndex].pCharacter = st->pCharacter;
  this->CurrentDragStates[MouseIndex].pTopmostEntity = st->pTopmostEntity;
  this->CurrentDragStates[MouseIndex].LockCenter = st->LockCenter;
  this->CurrentDragStates[MouseIndex].Bound = st->Bound;
  y = st->BoundLT.y;
  this->CurrentDragStates[MouseIndex].BoundLT.x = st->BoundLT.x;
  this->CurrentDragStates[MouseIndex].BoundLT.y = y;
  v4 = st->BoundRB.y;
  this->CurrentDragStates[MouseIndex].BoundRB.x = st->BoundRB.x;
  this->CurrentDragStates[MouseIndex].BoundRB.y = v4;
  v5 = st->CenterDelta.y;
  this->CurrentDragStates[MouseIndex].CenterDelta.x = st->CenterDelta.x;
  this->CurrentDragStates[MouseIndex].CenterDelta.y = v5;
  this->CurrentDragStates[MouseIndex].MouseIndex = st->MouseIndex;
}

// File Line: 2217
// RVA: 0x8D7010
void __fastcall Scaleform::GFx::MovieImpl::GetDragState(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIndex,
        Scaleform::GFx::MovieImpl::DragState *st)
{
  __int64 v3; // rdx
  float y; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4

  v3 = mouseIndex;
  st->pCharacter = this->CurrentDragStates[v3].pCharacter;
  st->pTopmostEntity = this->CurrentDragStates[v3].pTopmostEntity;
  st->LockCenter = this->CurrentDragStates[v3].LockCenter;
  st->Bound = this->CurrentDragStates[v3].Bound;
  y = this->CurrentDragStates[v3].BoundLT.y;
  st->BoundLT.x = this->CurrentDragStates[v3].BoundLT.x;
  st->BoundLT.y = y;
  v5 = this->CurrentDragStates[v3].BoundRB.y;
  st->BoundRB.x = this->CurrentDragStates[v3].BoundRB.x;
  st->BoundRB.y = v5;
  v6 = this->CurrentDragStates[v3].CenterDelta.y;
  st->CenterDelta.x = this->CurrentDragStates[v3].CenterDelta.x;
  st->CenterDelta.y = v6;
  st->MouseIndex = this->CurrentDragStates[v3].MouseIndex;
}

// File Line: 2223
// RVA: 0x906F90
void __fastcall Scaleform::GFx::MovieImpl::SetDragStateTopmostEntity(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIndex,
        Scaleform::GFx::InteractiveObject *topmostEntity)
{
  this->CurrentDragStates[mouseIndex].pTopmostEntity = topmostEntity;
}

// File Line: 2229
// RVA: 0x9118B0
void __fastcall Scaleform::GFx::MovieImpl::StopDrag(Scaleform::GFx::MovieImpl *this, unsigned int mouseIndex)
{
  __int64 v2; // rax
  __int64 v3; // rdx

  v2 = mouseIndex + 401i64;
  v3 = mouseIndex;
  this->CurrentDragStates[v3].pCharacter = 0i64;
  this->CurrentDragStates[v3].MouseIndex = -1;
  (&this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr)[6 * v2] = 0i64;
}

// File Line: 2237
// RVA: 0x9118F0
void __fastcall Scaleform::GFx::MovieImpl::StopDragCharacter(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  if ( this->CurrentDragStates[0].pCharacter == ch )
  {
    this->CurrentDragStates[0].pCharacter = 0i64;
    this->CurrentDragStates[0].pTopmostEntity = 0i64;
    this->CurrentDragStates[0].MouseIndex = -1;
  }
  if ( this->CurrentDragStates[1].pCharacter == ch )
  {
    this->CurrentDragStates[1].pCharacter = 0i64;
    this->CurrentDragStates[1].pTopmostEntity = 0i64;
    this->CurrentDragStates[1].MouseIndex = -1;
  }
  if ( this->CurrentDragStates[2].pCharacter == ch )
  {
    this->CurrentDragStates[2].pCharacter = 0i64;
    this->CurrentDragStates[2].pTopmostEntity = 0i64;
    this->CurrentDragStates[2].MouseIndex = -1;
  }
  if ( this->CurrentDragStates[3].pCharacter == ch )
  {
    this->CurrentDragStates[3].pCharacter = 0i64;
    this->CurrentDragStates[3].pTopmostEntity = 0i64;
    this->CurrentDragStates[3].MouseIndex = -1;
  }
  if ( this->CurrentDragStates[4].pCharacter == ch )
  {
    this->CurrentDragStates[4].pCharacter = 0i64;
    this->CurrentDragStates[4].pTopmostEntity = 0i64;
    this->CurrentDragStates[4].MouseIndex = -1;
  }
  if ( this->CurrentDragStates[5].pCharacter == ch )
  {
    this->CurrentDragStates[5].pCharacter = 0i64;
    this->CurrentDragStates[5].pTopmostEntity = 0i64;
    this->CurrentDragStates[5].MouseIndex = -1;
  }
}

// File Line: 2260
// RVA: 0x8E6F20
_BOOL8 __fastcall Scaleform::GFx::MovieImpl::IsDragging(Scaleform::GFx::MovieImpl *this, unsigned int mouseIndex)
{
  return this->CurrentDragStates[mouseIndex].pCharacter != 0i64;
}

// File Line: 2400
// RVA: 0x8B54F0
void __fastcall Scaleform::GFx::MovieImpl::AdvanceFrame(
        Scaleform::GFx::MovieImpl *this,
        bool nextFrame,
        float framePos)
{
  unsigned int Flags; // ecx
  unsigned __int64 v6; // rdi
  const char *pPlayListHead; // rax
  unsigned int Flags2; // eax
  bool v9; // r12
  unsigned int v10; // eax
  Scaleform::GFx::InteractiveObject *i; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v12; // rdx
  unsigned __int64 j; // r14
  Scaleform::GFx::InteractiveObject *pObject; // rbx
  const char *pPlayNext; // rax
  unsigned int v16; // edx
  unsigned int v17; // edx
  unsigned int v18; // edx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *Data; // rdx
  unsigned __int64 Size; // rdi
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v21; // rbx
  const char *pPlayListOptHead; // rax
  Scaleform::GFx::InteractiveObject *k; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v24; // rdx
  Scaleform::GFx::InteractiveObject *v25; // rcx
  const char *pPlayNextOpt; // rax
  unsigned int v27; // edx
  unsigned __int64 v28; // rdi
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v29; // rbx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+30h] [rbp-30h] BYREF

  if ( nextFrame )
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[27].__vecDelDtor)(this->pASMovieRoot.pObject);
  Flags = this->Flags;
  v6 = 0i64;
  if ( (Flags & 0x80000) != 0 )
  {
    pPlayListHead = (const char *)this->pPlayListHead;
    _mm_prefetch(pPlayListHead + 192, 2);
    _mm_prefetch(pPlayListHead + 160, 2);
    _mm_prefetch(pPlayListHead + 128, 2);
    _mm_prefetch(pPlayListHead + 96, 2);
    _mm_prefetch(pPlayListHead + 64, 2);
    _mm_prefetch(pPlayListHead + 32, 2);
    _mm_prefetch(pPlayListHead, 2);
    this->pPlayListOptHead = 0i64;
    this->Flags = Flags & 0xFFF7FFFF;
    Flags2 = this->Flags2;
    v9 = (Flags2 & 8) == 0;
    if ( (Flags2 & 8) != 0 )
      v10 = Flags2 & 0xFFFFFFF7;
    else
      v10 = Flags2 | 8;
    this->Flags2 = v10;
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    for ( i = this->pPlayListHead; i; i = i->pPlayNext )
    {
      ++i->RefCount;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
      v12 = &pheapAddr.Data[pheapAddr.Size - 1];
      if ( v12 )
      {
        ++i->RefCount;
        v12->pObject = i;
      }
      Scaleform::RefCountNTSImpl::Release(i);
    }
    for ( j = 0i64; j < pheapAddr.Size; ++j )
    {
      pObject = pheapAddr.Data[j].pObject;
      pPlayNext = (const char *)pObject->pPlayNext;
      _mm_prefetch(pPlayNext + 192, 2);
      _mm_prefetch(pPlayNext + 160, 2);
      _mm_prefetch(pPlayNext + 128, 2);
      _mm_prefetch(pPlayNext + 96, 2);
      _mm_prefetch(pPlayNext + 64, 2);
      _mm_prefetch(pPlayNext + 32, 2);
      _mm_prefetch(pPlayNext, 2);
      v16 = pObject->Flags;
      if ( (v16 & 0x200000) == 0 || (((unsigned __int8)(this->Flags2 >> 3) ^ (unsigned __int8)(v16 >> 23)) & 1) != 0 )
      {
        v17 = v16 & 0xFFDFFFFF;
        pObject->Flags = v17;
        if ( v9 )
          v18 = v17 | 0x800000;
        else
          v18 = v17 & 0xFF7FFFFF;
        pObject->Flags = v18;
        pObject->pPlayPrevOpt = 0i64;
        pObject->pPlayNextOpt = 0i64;
      }
      if ( (pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x40) == 0
        && (pObject->Scaleform::GFx::DisplayObject::Flags & 0x20) == 0 )
      {
        if ( ((pObject->Flags & 0x200000) == 0
           || (((unsigned __int8)(this->Flags2 >> 3) ^ (unsigned __int8)(pObject->Flags >> 23)) & 1) != 0)
          && pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
               pObject,
               0) == (void *)1 )
        {
          Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(pObject);
        }
        if ( nextFrame || (pObject->Flags & 0x100000) != 0 )
          pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[71].__vecDelDtor(
            pObject,
            nextFrame);
      }
    }
    Data = pheapAddr.Data;
    Size = pheapAddr.Size;
    v21 = &pheapAddr.Data[pheapAddr.Size - 1];
    if ( pheapAddr.Size )
    {
      do
      {
        if ( v21->pObject )
          Scaleform::RefCountNTSImpl::Release(v21->pObject);
        --v21;
        --Size;
      }
      while ( Size );
LABEL_50:
      Data = pheapAddr.Data;
    }
  }
  else
  {
    pPlayListOptHead = (const char *)this->pPlayListOptHead;
    _mm_prefetch(pPlayListOptHead + 192, 2);
    _mm_prefetch(pPlayListOptHead + 160, 2);
    _mm_prefetch(pPlayListOptHead + 128, 2);
    _mm_prefetch(pPlayListOptHead + 96, 2);
    _mm_prefetch(pPlayListOptHead + 64, 2);
    _mm_prefetch(pPlayListOptHead + 32, 2);
    _mm_prefetch(pPlayListOptHead, 2);
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    for ( k = this->pPlayListOptHead; k; k = k->pPlayNextOpt )
    {
      ++k->RefCount;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
      v24 = &pheapAddr.Data[pheapAddr.Size - 1];
      if ( v24 )
      {
        ++k->RefCount;
        v24->pObject = k;
      }
      Scaleform::RefCountNTSImpl::Release(k);
    }
    if ( pheapAddr.Size )
    {
      do
      {
        v25 = pheapAddr.Data[v6].pObject;
        pPlayNextOpt = (const char *)v25->pPlayNextOpt;
        _mm_prefetch(pPlayNextOpt + 192, 2);
        _mm_prefetch(pPlayNextOpt + 160, 2);
        _mm_prefetch(pPlayNextOpt + 128, 2);
        _mm_prefetch(pPlayNextOpt + 96, 2);
        _mm_prefetch(pPlayNextOpt + 64, 2);
        _mm_prefetch(pPlayNextOpt + 32, 2);
        _mm_prefetch(pPlayNextOpt, 2);
        v27 = v25->Flags;
        if ( (v27 & 0x400000) != 0 )
        {
          Scaleform::GFx::InteractiveObject::RemoveFromOptimizedPlayList(v25);
        }
        else if ( (v25->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x40) == 0
               && (nextFrame || (v27 & 0x100000) != 0)
               && (v25->Scaleform::GFx::DisplayObject::Flags & 0x20) == 0 )
        {
          v25->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[71].__vecDelDtor(
            v25,
            nextFrame);
        }
        ++v6;
      }
      while ( v6 < pheapAddr.Size );
    }
    Data = pheapAddr.Data;
    v28 = pheapAddr.Size;
    v29 = &pheapAddr.Data[pheapAddr.Size - 1];
    if ( pheapAddr.Size )
    {
      do
      {
        if ( v29->pObject )
          Scaleform::RefCountNTSImpl::Release(v29->pObject);
        --v29;
        --v28;
      }
      while ( v28 );
      goto LABEL_50;
    }
  }
  if ( Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->Flags2 &= ~2u;
}      goto LABEL_50;
    }
  }
  if ( Data )
    ((void (__fastc

// File Line: 2728
// RVA: 0x8BAFB0
void __fastcall Scaleform::GFx::MovieImpl::CheckMouseCursorType(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIdx,
        Scaleform::GFx::InteractiveObject *ptopMouseCharacter)
{
  char *v6; // rbp
  unsigned int v7; // ebx
  unsigned int v8; // ecx

  v6 = (char *)this + 80 * mouseIdx;
  if ( Scaleform::GFx::MouseState::IsTopmostEntityChanged((Scaleform::GFx::MouseState *)(v6 + 8696)) )
  {
    v7 = 0;
    if ( ptopMouseCharacter )
      v7 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))ptopMouseCharacter->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[116].__vecDelDtor)(ptopMouseCharacter);
    if ( *((_DWORD *)v6 + 2191) != v7 )
      ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, _QWORD, _QWORD))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[3].__vecDelDtor)(
        this->pASMovieRoot.pObject,
        mouseIdx,
        v7);
    v8 = *((_DWORD *)v6 + 2190);
    if ( v8 == -1 )
      v8 = v7;
    *((_DWORD *)v6 + 2191) = v8;
  }
}

// File Line: 2739
// RVA: 0x8BA3B0
void __fastcall Scaleform::GFx::MovieImpl::ChangeMouseCursorType(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIdx,
        unsigned int newCursorType)
{
  char *v4; // rbx
  unsigned int v5; // eax

  v4 = (char *)this + 80 * mouseIdx;
  if ( *((_DWORD *)v4 + 2191) != newCursorType )
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[3].__vecDelDtor)(this->pASMovieRoot.pObject);
  v5 = *((_DWORD *)v4 + 2190);
  if ( v5 == -1 )
    v5 = newCursorType;
  *((_DWORD *)v4 + 2191) = v5;
}

// File Line: 2747
// RVA: 0x8E2610
__int64 __fastcall Scaleform::GFx::MovieImpl::HandleEvent(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Event *event)
{
  __int64 v4; // rax
  Scaleform::GFx::KeyboardState *KeyboardStates; // r8
  Scaleform::GFx::Event *v6; // rbx
  __int64 v7; // rdx
  __int64 States; // rax
  Scaleform::GFx::KeyboardState *v9; // rcx
  char v10; // al
  __int64 Type; // rsi
  float v12; // xmm1_4
  float x; // xmm0_4
  float y; // xmm1_4
  unsigned int v15; // esi
  float v16; // xmm1_4
  float v17; // xmm6_4
  int v18; // ebx
  Scaleform::GFx::InputEventsQueue *v19; // rax
  float v20; // xmm0_4
  unsigned int v21; // esi
  float v22; // xmm1_4
  float v23; // xmm6_4
  int v24; // ebx
  Scaleform::GFx::InputEventsQueue *v25; // rax
  float v26; // xmm0_4
  unsigned int v27; // esi
  float v28; // xmm1_4
  float v29; // xmm6_4
  int v30; // ebx
  Scaleform::GFx::InputEventsQueue *v31; // rax
  float v32; // xmm0_4
  __int64 v33; // rax
  Scaleform::GFx::KeyboardState *v34; // rsi
  Scaleform::GFx::Event::EventType v35; // r11d
  char v36; // r8
  unsigned int v37; // edx
  __int64 v38; // rax
  Scaleform::GFx::KeyboardState *v39; // rsi
  Scaleform::GFx::Event::EventType v40; // r11d
  char v41; // r8
  char specialKeysState; // [rsp+28h] [rbp-38h]
  char specialKeysStatea; // [rsp+28h] [rbp-38h]
  Scaleform::Render::Point<float> p; // [rsp+80h] [rbp+20h] BYREF
  Scaleform::Render::Point<float> result; // [rsp+90h] [rbp+30h] BYREF

  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::MovieImpl *))this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[41].__vecDelDtor)(this) )
  {
    if ( event->Type != F5_320_1024 )
      return 0i64;
    goto LABEL_5;
  }
  if ( event->Type == F5_320_1024 )
  {
LABEL_5:
    KeyboardStates = this->KeyboardStates;
    v6 = event + 1;
    LODWORD(v7) = 0;
    do
    {
      if ( LOBYTE(v6->Type) )
      {
        KeyboardStates->Toggled[0] = (v6->Type & 0x10) != 0;
        KeyboardStates->Toggled[1] = (v6->Type & 8) != 0;
        KeyboardStates->Toggled[2] = (v6->Type & 0x20) != 0;
      }
      v7 = (unsigned int)(v7 + 1);
      ++KeyboardStates;
      v6 = (Scaleform::GFx::Event *)((char *)v6 + 1);
    }
    while ( (unsigned int)v7 < 6 );
    this->Flags |= 0x40000u;
    LOBYTE(v7) = 1;
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, __int64, Scaleform::GFx::KeyboardState *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[26].__vecDelDtor)(
      this->pASMovieRoot.pObject,
      v7,
      KeyboardStates);
    return 1i64;
  }
  if ( (unsigned int)(event->Type - 5) <= 1 )
  {
    States = (unsigned __int8)event[2].Modifiers.States;
    if ( (unsigned int)States < 6 )
    {
      v9 = &this->KeyboardStates[States];
      if ( v9 )
      {
        v10 = event->Modifiers.States;
        if ( v10 )
        {
          v9->Toggled[0] = (v10 & 0x10) != 0;
          v9->Toggled[1] = (event->Modifiers.States & 8) != 0;
          v9->Toggled[2] = (event->Modifiers.States & 0x20) != 0;
        }
      }
    }
  }
  switch ( event->Type )
  {
    case F5_1Pt2_512:
      Type = (unsigned int)event[3].Type;
      if ( (unsigned int)Type >= this->MouseCursorCount )
        goto LABEL_72;
      v12 = *(float *)&event[1].Modifiers.States;
      LODWORD(p.x) = event[1].Type;
      p.y = v12;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
      if ( (unsigned int)Type < 6 )
      {
        x = result.x;
        y = result.y;
        this->InputEventsQueue.LastMousePosMask |= 1 << Type;
        this->InputEventsQueue.LastMousePos[Type].x = x;
        this->InputEventsQueue.LastMousePos[Type].y = y;
      }
      v4 = 3i64;
      break;
    case F3_1Pt44_512:
      v21 = event[3].Type;
      if ( v21 >= this->MouseCursorCount )
        goto LABEL_72;
      v22 = *(float *)&event[1].Modifiers.States;
      LODWORD(p.x) = event[1].Type;
      p.y = v22;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
      v23 = result.x;
      v24 = 1 << *(_DWORD *)&event[2].Modifiers.States;
      if ( result.x != 1.1754944e-38 )
        this->InputEventsQueue.LastMousePosMask &= ~(1 << v21);
      v25 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(&this->InputEventsQueue);
      v25->Queue[0].t = QE_Mouse;
      v25->Queue[0].u.mouseEntry.MouseIndex = v21;
      v25->Queue[0].u.mouseEntry.ButtonsState = v24;
      v26 = result.y;
      v25->Queue[0].u.mouseEntry.PosX = v23;
      v25->Queue[0].u.mouseEntry.PosY = v26;
      v25->Queue[0].u.mouseEntry.Flags = 0;
      v4 = 3i64;
      break;
    case F3_2Pt88_512:
      v15 = event[3].Type;
      if ( v15 >= this->MouseCursorCount )
        goto LABEL_72;
      v16 = *(float *)&event[1].Modifiers.States;
      LODWORD(p.x) = event[1].Type;
      p.y = v16;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
      v17 = result.x;
      v18 = 1 << *(_DWORD *)&event[2].Modifiers.States;
      if ( result.x != 1.1754944e-38 )
        this->InputEventsQueue.LastMousePosMask &= ~(1 << v15);
      v19 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(&this->InputEventsQueue);
      v19->Queue[0].t = QE_Mouse;
      v19->Queue[0].u.mouseEntry.MouseIndex = v15;
      v19->Queue[0].u.mouseEntry.ButtonsState = v18;
      v20 = result.y;
      v19->Queue[0].u.mouseEntry.PosX = v17;
      v19->Queue[0].u.mouseEntry.PosY = v20;
      v19->Queue[0].u.mouseEntry.Flags = 0x80;
      v4 = 3i64;
      break;
    case F3_20Pt8_512:
      v27 = event[3].Type;
      if ( v27 >= this->MouseCursorCount )
        goto LABEL_72;
      v28 = *(float *)&event[1].Modifiers.States;
      LODWORD(p.x) = event[1].Type;
      p.y = v28;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
      v29 = result.x;
      v30 = (int)*(float *)&event[2].Type;
      if ( result.x != 1.1754944e-38 )
        this->InputEventsQueue.LastMousePosMask &= ~(1 << v27);
      v31 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(&this->InputEventsQueue);
      v31->Queue[0].t = QE_Mouse;
      v31->Queue[0].u.mouseEntry.MouseIndex = v27;
      v31->Queue[0].u.mouseEntry.WheelScrollDelta = v30;
      v32 = result.y;
      v31->Queue[0].u.mouseEntry.PosX = v29;
      v31->Queue[0].u.mouseEntry.PosY = v32;
      v31->Queue[0].u.mouseEntry.ButtonsState = 0;
      v31->Queue[0].u.mouseEntry.Flags = 32;
      v4 = 3i64;
      break;
    case F3_720_512:
      v33 = (unsigned __int8)event[2].Modifiers.States;
      if ( (unsigned int)v33 < 6 )
      {
        v34 = &this->KeyboardStates[v33];
        if ( v34 )
        {
          v35 = event[1].Type;
          v36 = event[1].Modifiers.States;
          if ( (unsigned int)v35 <= 0xE4 )
          {
            specialKeysState = event->Modifiers.States;
            v34->Keymap[v35 >> 3] |= 1 << (v35 - 8 * (v35 >> 3));
            Scaleform::GFx::KeyboardState::KeyQueue::Put(
              &v34->KeyQueue,
              v35,
              v36,
              0,
              F3_720_512,
              (Scaleform::KeyModifiers)specialKeysState);
          }
          switch ( event[1].Type )
          {
            case F5_720_512:
              if ( (event->Modifiers.States & 0x40) != 0 )
                v34->Keymap[20] |= 2u;
              else
                v34->Keymap[20] |= 1u;
              break;
            case F3_1Pt2_512:
              if ( (event->Modifiers.States & 0x40) != 0 )
                v34->Keymap[20] |= 8u;
              else
                v34->Keymap[20] |= 4u;
              break;
            case F3_1Pt23_1024:
              if ( (event->Modifiers.States & 0x40) != 0 )
                v34->Keymap[20] |= 0x20u;
              else
                v34->Keymap[20] |= 0x10u;
              break;
          }
        }
      }
      Scaleform::GFx::InputEventsQueue::AddKeyDown(
        &this->InputEventsQueue,
        event[1].Type,
        event[1].Modifiers.States,
        event->Modifiers,
        event[2].Modifiers.States);
      v37 = event[2].Type;
      if ( v37 == 13 || v37 >= 0x20 && v37 != 127 )
        Scaleform::GFx::InputEventsQueue::AddCharTyped(&this->InputEventsQueue, v37, event[2].Modifiers.States);
      v4 = 3i64;
      break;
    case F5_360_512:
      v38 = (unsigned __int8)event[2].Modifiers.States;
      if ( (unsigned int)v38 < 6 )
      {
        v39 = &this->KeyboardStates[v38];
        if ( v39 )
        {
          v40 = event[1].Type;
          v41 = event[1].Modifiers.States;
          if ( (unsigned int)v40 <= 0xE4 )
          {
            specialKeysStatea = event->Modifiers.States;
            v39->Keymap[v40 >> 3] &= ~(1 << (v40 - 8 * (v40 >> 3)));
            Scaleform::GFx::KeyboardState::KeyQueue::Put(
              &v39->KeyQueue,
              v40,
              v41,
              0,
              F5_360_512,
              (Scaleform::KeyModifiers)specialKeysStatea);
          }
          switch ( event[1].Type )
          {
            case F5_720_512:
              if ( (event->Modifiers.States & 0x40) != 0 )
                v39->Keymap[20] &= ~2u;
              else
                v39->Keymap[20] &= ~1u;
              break;
            case F3_1Pt2_512:
              if ( (event->Modifiers.States & 0x40) != 0 )
                v39->Keymap[20] &= ~8u;
              else
                v39->Keymap[20] &= ~4u;
              break;
            case F3_1Pt23_1024:
              if ( (event->Modifiers.States & 0x40) != 0 )
                v39->Keymap[20] &= ~0x20u;
              else
                v39->Keymap[20] &= ~0x10u;
              break;
          }
        }
      }
      Scaleform::GFx::InputEventsQueue::AddKeyUp(
        &this->InputEventsQueue,
        event[1].Type,
        event[1].Modifiers.States,
        event->Modifiers,
        event[2].Modifiers.States);
      v4 = 3i64;
      break;
    case F5_180_512:
      Scaleform::GFx::MovieImpl::ResetKeyboardState(this);
      Scaleform::GFx::MovieImpl::ResetMouseState(this);
      this->Flags &= ~0x40000u;
      this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[26].__vecDelDtor(this->pASMovieRoot.pObject, 0);
      goto LABEL_72;
    case F3_240M_512|F3_1Pt44_512:
      Scaleform::GFx::InputEventsQueue::AddAccelerometerEvent(
        &this->InputEventsQueue,
        event[1].Type,
        *(long double *)&event[2],
        *(long double *)&event[3],
        *(long double *)&event[4],
        *(long double *)&event[5]);
      v4 = 3i64;
      break;
    case F3_32M_512|F3_1Pt44_512:
      Scaleform::GFx::InputEventsQueue::AddGeolocationEvent(
        &this->InputEventsQueue,
        event[1].Type,
        *(long double *)&event[2],
        *(long double *)&event[3],
        *(long double *)&event[4],
        *(long double *)&event[5],
        *(long double *)&event[6],
        *(long double *)&event[7],
        *(long double *)&event[8],
        *(long double *)&event[9]);
      v4 = 3i64;
      break;
    case F3_240M_512|F3_20Pt8_512:
      Scaleform::GFx::InputEventsQueue::AddStatusEvent(
        &this->InputEventsQueue,
        *(Scaleform::String **)&event[1],
        *(Scaleform::String **)&event[2],
        *(Scaleform::String **)&event[3],
        *(Scaleform::String **)&event[4]);
      v4 = 3i64;
      break;
    case F3_32M_512|F3_20Pt8_512:
      Scaleform::GFx::InputEventsQueue::AddCharTyped(&this->InputEventsQueue, event[1].Type, event[1].Modifiers.States);
      v4 = 3i64;
      break;
    default:
LABEL_72:
      v4 = 0i64;
      break;
  }
  return v4;
}ates);
      v4 = 3i64;
      break;
    default:
LABEL_72:
      v4 = 0i64;
      break;
  }
  return v4;
}

// File Line: 3171
// RVA: 0x8EBE50
void __fastcall Scaleform::GFx::MovieImpl::NotifyMouseState(
        Scaleform::GFx::MovieImpl *this,
        float x,
        float y,
        unsigned int buttons,
        unsigned int mouseIndex)
{
  __int64 v7; // rsi
  Scaleform::GFx::InputEventsQueue *p_InputEventsQueue; // rdi
  float v9; // xmm6_4
  float v10; // xmm8_4
  unsigned int CurButtonsState; // ebp
  int v12; // ebx
  __int64 i; // r14
  Scaleform::GFx::InputEventsQueue *v14; // rax
  unsigned __int16 v15; // cx
  Scaleform::Render::Point<float> v16; // [rsp+20h] [rbp-68h] BYREF
  Scaleform::Render::Point<float> v17; // [rsp+90h] [rbp+8h] BYREF

  v17.x = x;
  v17.y = y;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &v16, &v17);
  v7 = mouseIndex;
  if ( mouseIndex < this->MouseCursorCount )
  {
    p_InputEventsQueue = &this->InputEventsQueue;
    v9 = v16.x;
    v10 = v16.y;
    if ( mouseIndex < 6 )
    {
      this->InputEventsQueue.LastMousePosMask |= 1 << mouseIndex;
      p_InputEventsQueue->LastMousePos[v7].x = v9;
      p_InputEventsQueue->LastMousePos[v7].y = v10;
    }
    CurButtonsState = this->mMouseState[v7].CurButtonsState;
    v12 = 1;
    for ( i = 16i64; i; --i )
    {
      if ( (buttons & v12) != 0 )
      {
        if ( (v12 & CurButtonsState) == 0 )
        {
          if ( v9 != 1.1754944e-38 )
            p_InputEventsQueue->LastMousePosMask &= ~(1 << v7);
          v14 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(p_InputEventsQueue);
          v14->Queue[0].t = QE_Mouse;
          v14->Queue[0].u.mouseEntry.Flags = 0;
          v15 = v12 & buttons;
LABEL_15:
          v14->Queue[0].u.mouseEntry.ButtonsState = v15;
          v14->Queue[0].u.mouseEntry.PosY = v10;
          v14->Queue[0].u.mouseEntry.PosX = v9;
          v14->Queue[0].u.mouseEntry.MouseIndex = v7;
          goto LABEL_16;
        }
      }
      else if ( (v12 & CurButtonsState) == 0 )
      {
        goto LABEL_16;
      }
      if ( (buttons & v12) == 0 )
      {
        if ( v9 != 1.1754944e-38 )
          p_InputEventsQueue->LastMousePosMask &= ~(1 << v7);
        v14 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(p_InputEventsQueue);
        v14->Queue[0].t = QE_Mouse;
        v14->Queue[0].u.mouseEntry.Flags = 0x80;
        v15 = CurButtonsState & v12;
        goto LABEL_15;
      }
LABEL_16:
      v12 *= 2;
    }
  }
}

// File Line: 3196
// RVA: 0x8DB1F0
void __fastcall Scaleform::GFx::MovieImpl::GetMouseState(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIndex,
        float *x,
        float *y,
        unsigned int *buttons)
{
  float v5; // xmm1_4

  if ( mouseIndex < this->MouseCursorCount )
  {
    v5 = (float)((float)(this->mMouseState[mouseIndex].LastPosition.y * 0.050000001) - this->ViewOffsetY)
       / this->ViewScaleY;
    if ( x )
      *x = (float)((float)(this->mMouseState[mouseIndex].LastPosition.x * 0.050000001) - this->ViewOffsetX)
         / this->ViewScaleX;
    if ( y )
      *y = v5;
    if ( buttons )
      *buttons = this->mMouseState[mouseIndex].CurButtonsState;
  }
}

// File Line: 3215
// RVA: 0x8E33B0
char __fastcall Scaleform::GFx::MovieImpl::HitTest(
        Scaleform::GFx::MovieImpl *this,
        float x,
        float y,
        Scaleform::GFx::Movie::HitTestType testCond,
        int controllerIdx)
{
  float v7; // xmm2_4
  int Size; // edi
  int v9; // r15d
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // rax
  Scaleform::GFx::DisplayObjectBase *pObject; // rbx
  __int64 v12; // r8
  Scaleform::GFx::ASMovieRootBase *v13; // rax
  bool v14; // zf
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int64 v17; // rbx
  unsigned __int8 v18; // al
  __int64 v19; // rax
  Scaleform::Render::Point<float> result; // [rsp+30h] [rbp-50h] BYREF
  int v21[4]; // [rsp+40h] [rbp-40h] BYREF
  __int128 v22; // [rsp+50h] [rbp-30h] BYREF
  __m128 v23; // [rsp+60h] [rbp-20h]
  int v24; // [rsp+70h] [rbp-10h]
  char v25; // [rsp+74h] [rbp-Ch]
  Scaleform::Render::Point<float> p; // [rsp+B0h] [rbp+30h] BYREF

  p.x = x;
  p.y = y;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
  v7 = (float)(result.x - (float)(this->ViewOffsetX * 20.0))
     / (float)(this->VisibleFrameRect.x2 - this->VisibleFrameRect.x1);
  LODWORD(this->ScreenToWorld.Sy) = COERCE_UNSIGNED_INT(
                                      (float)((float)((float)(result.y - (float)(this->ViewOffsetY * 20.0))
                                                    / (float)(this->VisibleFrameRect.y2 - this->VisibleFrameRect.y1))
                                            * 2.0)
                                    - 1.0) ^ _xmm[0];
  this->ScreenToWorld.Sx = (float)(v7 * 2.0) - 1.0;
  Size = this->MovieLevels.Data.Size;
  if ( !Size )
    return 0;
  v9 = controllerIdx;
  while ( 1 )
  {
    Data = this->MovieLevels.Data.Data;
    --Size;
    v22 = _xmm;
    v23 = _xmm;
    pObject = Data[Size].pSprite.pObject;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, int *, __int128 *))pObject->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[61].__vecDelDtor)(
      pObject,
      v21,
      &v22);
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(pObject, &p, &result, 0, 0i64);
    if ( (p.x > *(float *)&v21[2] || p.x < *(float *)v21 || p.y > *(float *)&v21[3] || p.y < *(float *)&v21[1])
      && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pObject->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[14].__vecDelDtor)(pObject) )
    {
      goto LABEL_25;
    }
    if ( testCond )
      break;
    v12 = 0i64;
LABEL_24:
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, __int64))pObject->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
           pObject,
           &p,
           v12) )
    {
      return 1;
    }
LABEL_25:
    if ( !Size )
      return 0;
  }
  if ( testCond == HitTest_Shapes )
  {
    LOBYTE(v12) = 1;
    goto LABEL_24;
  }
  if ( testCond != HitTest_ButtonEvents )
  {
    if ( testCond != HitTest_ShapesNoInvisible )
      goto LABEL_25;
    LOBYTE(v12) = 3;
    goto LABEL_24;
  }
  v13 = this->pASMovieRoot.pObject;
  v23 = 0ui64;
  v25 = 0;
  v24 = v9;
  v14 = v13->AVMVersion == 1;
  vfptr = pObject->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
  if ( v14 )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, __int128 *))vfptr[64].__vecDelDtor)(
           pObject,
           &p,
           &v22) == 1 )
      return 1;
    goto LABEL_25;
  }
  v25 = 1;
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, __int128 *))vfptr[64].__vecDelDtor)(
         pObject,
         &p,
         &v22) != 1 )
    goto LABEL_25;
  v17 = v22;
  if ( !(_QWORD)v22 )
    goto LABEL_25;
  while ( 1 )
  {
    v18 = *(_BYTE *)(v17 + 109);
    if ( v18 )
    {
      v19 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v17 + 4i64 * v18) + 8i64))(v17 + 4i64 * v18);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v19 + 96i64))(v19) )
        return 1;
    }
    v17 = *(_QWORD *)(v17 + 56);
    if ( !v17 )
      goto LABEL_25;
  }
}

// File Line: 3287
// RVA: 0x8B1990
__int64 __fastcall Scaleform::GFx::MovieImpl::AddIntervalTimer(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::RenderBuffer *timer)
{
  Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf> *v4; // rbx

  timer->vfptr[7].__vecDelDtor(timer, ++this->LastIntervalTimerId);
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)timer);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->IntervalTimers.Data,
    &this->IntervalTimers,
    this->IntervalTimers.Data.Size + 1);
  v4 = &this->IntervalTimers.Data.Data[this->IntervalTimers.Data.Size - 1];
  if ( v4 )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)timer);
    v4->pObject = (Scaleform::GFx::ASIntervalTimerIntf *)timer;
  }
  Scaleform::RefCountImpl::Release(timer);
  return (unsigned int)this->LastIntervalTimerId;
}

// File Line: 3294
// RVA: 0x8BC490
void __fastcall Scaleform::GFx::MovieImpl::ClearIntervalTimer(Scaleform::GFx::MovieImpl *this, int timerId)
{
  unsigned __int64 Size; // rsi
  __int64 v3; // rbx
  Scaleform::GFx::ASIntervalTimerIntf *pObject; // rcx
  Scaleform::GFx::ASIntervalTimerIntf *v7; // rcx

  Size = this->IntervalTimers.Data.Size;
  v3 = 0i64;
  if ( Size )
  {
    while ( 1 )
    {
      pObject = this->IntervalTimers.Data.Data[v3].pObject;
      if ( pObject )
      {
        if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ASIntervalTimerIntf *))pObject->vfptr[8].__vecDelDtor)(pObject) == timerId )
          break;
      }
      if ( ++v3 >= Size )
        return;
    }
    v7 = this->IntervalTimers.Data.Data[v3].pObject;
    ((void (__fastcall *)(Scaleform::GFx::ASIntervalTimerIntf *))v7->vfptr[4].__vecDelDtor)(v7);
  }
}

// File Line: 3308
// RVA: 0x910870
void __fastcall Scaleform::GFx::MovieImpl::ShutdownTimers(Scaleform::GFx::MovieImpl *this)
{
  unsigned __int64 Size; // rsi
  unsigned __int64 i; // rbx
  Scaleform::GFx::ASIntervalTimerIntf *pObject; // rcx

  Size = this->IntervalTimers.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    pObject = this->IntervalTimers.Data.Data[i].pObject;
    ((void (__fastcall *)(Scaleform::GFx::ASIntervalTimerIntf *))pObject->vfptr[4].__vecDelDtor)(pObject);
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->IntervalTimers.Data,
    &this->IntervalTimers,
    0i64);
}

// File Line: 3317
// RVA: 0x9108D0
void __fastcall Scaleform::GFx::MovieImpl::ShutdownTimersForMovieDef(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieDefImpl *defimpl)
{
  unsigned __int64 Size; // rbp
  unsigned __int64 i; // rbx
  Scaleform::GFx::ASIntervalTimerIntf *pObject; // rcx
  Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf> *Data; // rax
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf> *v9; // rdi

  Size = this->IntervalTimers.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    pObject = this->IntervalTimers.Data.Data[i].pObject;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::ASIntervalTimerIntf *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::MovieDefImpl *))pObject->vfptr[5].__vecDelDtor)(
           pObject,
           this,
           defimpl) )
    {
      Data = this->IntervalTimers.Data.Data;
      v8 = (Scaleform::Render::RenderBuffer *)Data[i].pObject;
      v9 = &Data[i];
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
      v9->pObject = 0i64;
    }
  }
}

// File Line: 3346
// RVA: 0x8D6630
__int64 __fastcall Scaleform::GFx::MovieImpl::GetCurrentFrame(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // rcx

  pMainMovie = this->pMainMovie;
  if ( pMainMovie )
    return ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[107].__vecDelDtor)(pMainMovie);
  else
    return 0i64;
}

// File Line: 3350
// RVA: 0x8E2EE0
bool __fastcall Scaleform::GFx::MovieImpl::HasLooped(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // rcx

  pMainMovie = this->pMainMovie;
  if ( pMainMovie )
    return ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[113].__vecDelDtor)(pMainMovie);
  else
    return 0;
}

// File Line: 3356
// RVA: 0x8FE740
char __fastcall Scaleform::GFx::MovieImpl::ReleaseLevelMovie(Scaleform::GFx::MovieImpl *this, int level)
{
  unsigned int v3; // esi
  Scaleform::GFx::InteractiveObject *v4; // rbp
  Scaleform::GFx::InteractiveObject *v5; // rbx
  unsigned __int64 v6; // r15
  Scaleform::GFx::InteractiveObject *v7; // rcx
  Scaleform::Render::TreeNode *v8; // rax
  Scaleform::Render::TreeContainer *v9; // rbx
  __int64 v10; // rax
  unsigned __int64 Size; // rcx
  __int64 v13; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  Scaleform::GFx::DisplayObjectBase *v16; // rbx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::TreeContainer *pParent; // rcx

  v3 = 0;
  if ( level )
  {
    Size = this->MovieLevels.Data.Size;
    if ( Size )
    {
      v13 = 0i64;
      Data = this->MovieLevels.Data.Data;
      while ( Data[v13].Level != level )
      {
        v13 = ++v3;
        if ( v3 >= Size )
          return 0;
      }
      pObject = Data[v3].pSprite.pObject;
      if ( pObject )
        ++pObject->RefCount;
      v16 = Data[v3].pSprite.pObject;
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v16->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[75].__vecDelDtor)(v16);
      ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[7].__vecDelDtor)(this->pASMovieRoot.pObject);
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v16->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[60].__vecDelDtor)(v16);
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        &this->MovieLevels,
        v3);
      this->Flags |= 0x100u;
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v16);
      if ( RenderNode )
      {
        pParent = (Scaleform::Render::TreeContainer *)RenderNode->pParent;
        if ( pParent )
          Scaleform::Render::TreeContainer::Remove(pParent, v3, 1ui64);
      }
      Scaleform::RefCountNTSImpl::Release(v16);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    this->CurrentDragStates[0].pCharacter = 0i64;
    this->CurrentDragStates[0].pTopmostEntity = 0i64;
    this->CurrentDragStates[0].MouseIndex = -1;
    this->CurrentDragStates[1].pCharacter = 0i64;
    this->CurrentDragStates[1].pTopmostEntity = 0i64;
    this->CurrentDragStates[1].MouseIndex = -1;
    this->CurrentDragStates[2].pCharacter = 0i64;
    this->CurrentDragStates[2].pTopmostEntity = 0i64;
    this->CurrentDragStates[2].MouseIndex = -1;
    this->CurrentDragStates[3].pCharacter = 0i64;
    this->CurrentDragStates[3].pTopmostEntity = 0i64;
    this->CurrentDragStates[3].MouseIndex = -1;
    this->CurrentDragStates[4].pCharacter = 0i64;
    this->CurrentDragStates[4].pTopmostEntity = 0i64;
    this->CurrentDragStates[4].MouseIndex = -1;
    this->CurrentDragStates[5].pCharacter = 0i64;
    this->CurrentDragStates[5].pTopmostEntity = 0i64;
    this->CurrentDragStates[5].MouseIndex = -1;
    Scaleform::GFx::MovieImpl::ShutdownTimers(this);
    if ( this->MovieLevels.Data.Size )
    {
      v4 = this->MovieLevels.Data.Data->pSprite.pObject;
      if ( v4 )
        ++v4->RefCount;
    }
    else
    {
      v4 = 0i64;
    }
    while ( this->MovieLevels.Data.Size )
    {
      v5 = this->MovieLevels.Data.Data[this->MovieLevels.Data.Size - 1].pSprite.pObject;
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v5->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[75].__vecDelDtor)(v5);
      ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[7].__vecDelDtor)(this->pASMovieRoot.pObject);
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v5->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[60].__vecDelDtor)(v5);
      v6 = this->MovieLevels.Data.Size - 1;
      if ( this->MovieLevels.Data.Size == 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->MovieLevels.Data,
          &this->MovieLevels,
          0i64);
      }
      else
      {
        v7 = this->MovieLevels.Data.Data[v6].pSprite.pObject;
        if ( v7 )
          Scaleform::RefCountNTSImpl::Release(v7);
        memmove(
          &this->MovieLevels.Data.Data[v6],
          &this->MovieLevels.Data.Data[v6 + 1],
          16 * (this->MovieLevels.Data.Size - v6 - 1));
        --this->MovieLevels.Data.Size;
      }
    }
    v8 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4);
    if ( v8 )
    {
      v9 = (Scaleform::Render::TreeContainer *)v8->pParent;
      if ( v9 )
      {
        v10 = Scaleform::Render::TreeContainer::GetSize((Scaleform::Render::TreeContainer *)v8->pParent);
        Scaleform::Render::TreeContainer::Remove(v9, 0i64, v10);
      }
    }
    if ( v4 )
      Scaleform::RefCountNTSImpl::Release(v4);
    this->pMainMovie = 0i64;
    this->FrameTime = 0.083333336;
    this->Flags |= 0x100u;
    return 1;
  }
}

// File Line: 3438
// RVA: 0x9042E0
void __fastcall Scaleform::GFx::MovieImpl::Restart(Scaleform::GFx::MovieImpl *this, bool advance0)
{
  __int64 v4; // rax
  __int64 v5; // r14
  int i; // ebx
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // rcx
  unsigned int v8; // ebp
  unsigned int v9; // esi
  Scaleform::GFx::LoadQueueEntryMT *j; // rbx
  Scaleform::GFx::LoadQueueEntry *pLoadQueueHead; // rcx
  Scaleform::GFx::LoadQueueEntryMT *v12; // rcx
  Scaleform::GFx::MovieImpl::ReturnValueHolder *pRetValHolder; // rbx
  unsigned int k; // ebx
  Scaleform::GFx::UserEventHandler *pObject; // rcx
  Scaleform::GFx::UserEventHandler *v16; // rcx
  __int64 v17; // rdx
  __int64 v18; // r9
  __int64 v19; // rcx
  int v20; // [rsp+28h] [rbp-50h] BYREF
  char v21; // [rsp+2Ch] [rbp-4Ch]
  int v22; // [rsp+30h] [rbp-48h]
  unsigned int v23; // [rsp+34h] [rbp-44h]
  int v24; // [rsp+38h] [rbp-40h] BYREF
  char v25; // [rsp+3Ch] [rbp-3Ch]
  int v26; // [rsp+40h] [rbp-38h]
  unsigned int v27; // [rsp+44h] [rbp-34h]

  if ( this->pMainMovie )
  {
    this->Flags2 |= 4u;
    Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
    v4 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pMainMovie->vfptr[66].__vecDelDtor)(this->pMainMovie);
    v5 = v4;
    if ( v4 )
      _InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 8), 1u);
    for ( i = this->MovieLevels.Data.Size - 1; i >= 0; --i )
      Scaleform::GFx::MovieImpl::ReleaseLevelMovie(this, i);
    Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->MovieLevels.Data,
      &this->MovieLevels,
      0i64);
    pLoadQueueMTHead = this->pLoadQueueMTHead;
    v8 = 0;
    if ( pLoadQueueMTHead )
    {
      do
      {
        ++v8;
        pLoadQueueMTHead->pQueueEntry->Canceled = 1;
        pLoadQueueMTHead = pLoadQueueMTHead->pNext;
      }
      while ( pLoadQueueMTHead );
      if ( v8 )
      {
        do
        {
          v9 = 0;
          for ( j = this->pLoadQueueMTHead; j; j = j->pNext )
          {
            if ( j->vfptr->LoadFinished(j) )
              ++v9;
          }
        }
        while ( v8 > v9 );
      }
    }
    while ( this->pLoadQueueHead )
    {
      pLoadQueueHead = this->pLoadQueueHead;
      this->pLoadQueueHead = pLoadQueueHead->pNext;
      pLoadQueueHead->vfptr->__vecDelDtor(pLoadQueueHead, 1u);
    }
    while ( this->pLoadQueueMTHead )
    {
      v12 = this->pLoadQueueMTHead;
      this->pLoadQueueMTHead = v12->pNext;
      v12->vfptr->__vecDelDtor(v12, 1u);
    }
    this->pLoadQueueHead = 0i64;
    this->pLoadQueueMTHead = 0i64;
    this->Flags |= 0x80000u;
    this->pPlayListOptHead = 0i64;
    this->pPlayListHead = 0i64;
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[42].__vecDelDtor)(this->pASMovieRoot.pObject);
    Scaleform::GFx::MovieImpl::ClearIndirectTransformPairs(this);
    pRetValHolder = this->pRetValHolder;
    if ( pRetValHolder )
    {
      if ( pRetValHolder->CharBuffer )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(&pRetValHolder->StringArray.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pRetValHolder);
    }
    this->pRetValHolder = 0i64;
    Scaleform::GFx::MovieImpl::ResetFocusStates(this);
    this->Flags &= 0x3FFFFFu;
    Scaleform::GFx::MovieImpl::ResetMouseState(this);
    this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[9].__vecDelDtor(this->pASMovieRoot.pObject, 2u);
    this->Flags2 &= ~4u;
    this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[17].__vecDelDtor(this->pASMovieRoot.pObject, v5);
    if ( this->pMainMovie )
    {
      if ( this->pUserEventHandler.pObject )
      {
        for ( k = 0; k < this->MouseCursorCount; ++k )
        {
          pObject = this->pUserEventHandler.pObject;
          v21 = 0;
          v20 = 21;
          v22 = 0;
          v23 = k;
          ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))pObject->vfptr[1].__vecDelDtor)(
            pObject,
            this,
            &v20);
          v16 = this->pUserEventHandler.pObject;
          v25 = 0;
          v24 = 23;
          v26 = 0;
          v27 = k;
          ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))v16->vfptr[1].__vecDelDtor)(
            v16,
            this,
            &v24);
        }
      }
      this->FocusRectChanged = 1;
      Scaleform::GFx::MovieImpl::ResetKeyboardState(this);
      if ( advance0 )
      {
        LOBYTE(v18) = 1;
        ((void (__fastcall *)(Scaleform::GFx::MovieImpl *, __int64, _QWORD, __int64, __int64))this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[24].__vecDelDtor)(
          this,
          v17,
          0i64,
          v18,
          -2i64);
      }
      this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[9].__vecDelDtor(this->pASMovieRoot.pObject, 2u);
    }
    if ( v5 && !_InterlockedDecrement((volatile signed __int32 *)(v5 + 8)) )
    {
      v19 = *(_QWORD *)(v5 + 16);
      if ( v19 )
      {
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v19 + 8i64))(v19, v5);
        *(_QWORD *)(v5 + 16) = 0i64;
      }
      (**(void (__fastcall ***)(__int64, __int64))v5)(v5, 1i64);
    }
  }
}

// File Line: 3591
// RVA: 0x901680
void __fastcall Scaleform::GFx::MovieImpl::ResetMouseState(Scaleform::GFx::MovieImpl *this)
{
  *((_BYTE *)this->mMouseState + 76) &= 0xE0u;
  this->mMouseState[0].mPresetCursorType = -1;
  *(_QWORD *)&this->mMouseState[0].CursorType = 0i64;
  *(_QWORD *)&this->mMouseState[0].CurButtonsState = 0i64;
  this->mMouseState[0].LastPosition = 0i64;
  this->mMouseState[1].mPresetCursorType = -1;
  *(_QWORD *)&this->mMouseState[1].CursorType = 0i64;
  *(_QWORD *)&this->mMouseState[1].CurButtonsState = 0i64;
  this->mMouseState[1].LastPosition = 0i64;
  *((_BYTE *)&this->mMouseState[1] + 76) &= 0xE0u;
  this->mMouseState[2].mPresetCursorType = -1;
  *(_QWORD *)&this->mMouseState[2].CursorType = 0i64;
  *(_QWORD *)&this->mMouseState[2].CurButtonsState = 0i64;
  this->mMouseState[2].LastPosition = 0i64;
  *((_BYTE *)&this->mMouseState[2] + 76) &= 0xE0u;
  this->mMouseState[3].mPresetCursorType = -1;
  *(_QWORD *)&this->mMouseState[3].CursorType = 0i64;
  *(_QWORD *)&this->mMouseState[3].CurButtonsState = 0i64;
  this->mMouseState[3].LastPosition = 0i64;
  *((_BYTE *)&this->mMouseState[3] + 76) &= 0xE0u;
  this->mMouseState[4].mPresetCursorType = -1;
  *(_QWORD *)&this->mMouseState[4].CursorType = 0i64;
  *(_QWORD *)&this->mMouseState[4].CurButtonsState = 0i64;
  this->mMouseState[4].LastPosition = 0i64;
  *((_BYTE *)&this->mMouseState[4] + 76) &= 0xE0u;
  this->mMouseState[5].mPresetCursorType = -1;
  *(_QWORD *)&this->mMouseState[5].CursorType = 0i64;
  *(_QWORD *)&this->mMouseState[5].CurButtonsState = 0i64;
  this->mMouseState[5].LastPosition = 0i64;
  *((_BYTE *)&this->mMouseState[5] + 76) &= 0xE0u;
}

// File Line: 3599
// RVA: 0x9015F0
void __fastcall Scaleform::GFx::MovieImpl::ResetKeyboardState(Scaleform::GFx::MovieImpl *this)
{
  unsigned int *p_GetIdx; // rbx
  __int64 v2; // rdi

  p_GetIdx = &this->KeyboardStates[0].KeyQueue.GetIdx;
  v2 = 6i64;
  do
  {
    *(_QWORD *)(p_GetIdx - 1) = 0i64;
    p_GetIdx[1] = 0;
    memset(p_GetIdx - 401, 0, 0x640ui64);
    p_GetIdx += 418;
    *(_QWORD *)((char *)p_GetIdx - 1663) = 0i64;
    *(_QWORD *)((char *)p_GetIdx - 1655) = 0i64;
    *(_QWORD *)((char *)p_GetIdx - 1647) = 0i64;
    *(unsigned int *)((char *)p_GetIdx - 1639) = 0;
    *((_BYTE *)p_GetIdx - 1635) = 0;
    *((_WORD *)p_GetIdx - 817) = 0;
    *((_BYTE *)p_GetIdx - 1632) = 0;
    --v2;
  }
  while ( v2 );
}

// File Line: 3610
// RVA: 0x9085F0
void __fastcall Scaleform::GFx::MovieImpl::SetKeyboardListener(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::KeyboardState::IListener *l)
{
  this->KeyboardStates[0].pListener = l;
  this->KeyboardStates[1].pListener = l;
  this->KeyboardStates[2].pListener = l;
  this->KeyboardStates[3].pListener = l;
  this->KeyboardStates[4].pListener = l;
  this->KeyboardStates[5].pListener = l;
}

// File Line: 3619
// RVA: 0x8E21C0
void __fastcall Scaleform::GFx::MovieImpl::GotoFrame(Scaleform::GFx::MovieImpl *this, __int64 targetFrameNumber)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // rcx

  pMainMovie = this->pMainMovie;
  if ( pMainMovie )
    pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[110].__vecDelDtor(
      pMainMovie,
      targetFrameNumber);
}

// File Line: 3624
// RVA: 0x8E24C0
char __fastcall Scaleform::GFx::MovieImpl::GotoLabeledFrame(
        Scaleform::GFx::MovieImpl *this,
        const char *label,
        int offset)
{
  Scaleform::GFx::MovieDataDef *pObject; // rcx
  int v8; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+58h] [rbp+20h] BYREF

  if ( this->pMainMovie )
  {
    v8 = -1;
    pObject = this->pMainMovieDef.pObject->pBindData.pObject->pDataDef.pObject;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::MovieDataDef *, const char *, int *, _QWORD, __int64))pObject->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr[3].GetKey)(
           pObject,
           label,
           &v8,
           0i64,
           -2i64) )
    {
      this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[4].__vecDelDtor(
        this,
        v8 + offset);
      return 1;
    }
    Scaleform::GFx::StateBag::GetLogState(&this->Scaleform::GFx::StateBag, &result);
    if ( result.pObject )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        &result.pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "MovieImpl::GotoLabeledFrame(%s) unknown label",
        label);
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  }
  return 0;
}

// File Line: 3644
// RVA: 0x909BF0
void __fastcall Scaleform::GFx::MovieImpl::SetPause(Scaleform::GFx::MovieImpl *this, bool pause)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::InteractiveObject *pPlayListHead; // rcx
  Scaleform::GFx::InteractiveObject *pPlayNext; // rbx

  Flags = this->Flags;
  if ( ((Flags & 0x100000) == 0 || !pause) && ((Flags & 0x100000) != 0 || pause) )
  {
    if ( pause )
    {
      this->Flags = Flags | 0x100000;
      this->PauseTickMs = Scaleform::Timer::GetTicks() / 0x3E8;
    }
    else
    {
      this->Flags = Flags & 0xFFEFFFFF;
      this->StartTickMs += Scaleform::Timer::GetTicks() / 0x3E8 - this->PauseTickMs;
    }
    pPlayListHead = this->pPlayListHead;
    if ( pPlayListHead )
    {
      do
      {
        pPlayNext = pPlayListHead->pPlayNext;
        pPlayListHead->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[95].__vecDelDtor(
          pPlayListHead,
          pause);
        pPlayListHead = pPlayNext;
      }
      while ( pPlayNext );
    }
  }
}

// File Line: 3673
// RVA: 0x909CE0
void __fastcall Scaleform::GFx::MovieImpl::SetPlayState(Scaleform::GFx::MovieImpl *this, __int64 s)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // rcx

  pMainMovie = this->pMainMovie;
  if ( pMainMovie )
    pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
      pMainMovie,
      s);
}

// File Line: 3678
// RVA: 0x8DC110
__int64 __fastcall Scaleform::GFx::MovieImpl::GetPlayState(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // rcx

  pMainMovie = this->pMainMovie;
  if ( pMainMovie )
    return ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[115].__vecDelDtor)(pMainMovie);
  else
    return 1i64;
}

// File Line: 3684
// RVA: 0x90F150
void __fastcall Scaleform::GFx::MovieImpl::SetVisible(Scaleform::GFx::MovieImpl *this, __int64 visible)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // rcx

  pMainMovie = this->pMainMovie;
  if ( pMainMovie )
    pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[58].__vecDelDtor(
      pMainMovie,
      visible);
}

// File Line: 3688
// RVA: 0x8E1850
bool __fastcall Scaleform::GFx::MovieImpl::GetVisible(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // rcx

  pMainMovie = this->pMainMovie;
  if ( pMainMovie )
    return ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(pMainMovie);
  else
    return 0;
}

// File Line: 3693
// RVA: 0x8B2E30
void __fastcall Scaleform::GFx::MovieImpl::AddStickyVariableNode(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ASString *path,
        Scaleform::GFx::MovieImpl::StickyVarNode *p)
{
  Scaleform::GFx::ASStringHash<Scaleform::GFx::MovieImpl::StickyVarNode *> *p_StickyVariables; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rsi
  __int64 v7; // rax
  unsigned __int64 *v8; // rdx
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // rcx
  Scaleform::GFx::MovieImpl::StickyVarNode *value; // [rsp+40h] [rbp+18h] BYREF

  value = p;
  p_StickyVariables = &this->StickyVariables;
  pTable = this->StickyVariables.mHash.pTable;
  if ( pTable
    && (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->StickyVariables.mHash,
               path,
               pTable->SizeMask & path->pNode->HashFlags),
        v7 >= 0)
    && (v8 = &pTable[1].SizeMask + 3 * v7) != 0i64
    && (v9 = v8[1]) != 0 )
  {
    v10 = v9;
    while ( *(Scaleform::GFx::ASStringNode **)(v10 + 8) != p->Name.pNode )
    {
      v10 = *(_QWORD *)(v10 + 16);
      if ( !v10 )
      {
        p->pNext = *(Scaleform::GFx::MovieImpl::StickyVarNode **)(v9 + 16);
        *(_QWORD *)(v9 + 16) = value;
        return;
      }
    }
    (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::MovieImpl::StickyVarNode *))(*(_QWORD *)v10 + 8i64))(
      v10,
      p);
    if ( value )
      value->vfptr->__vecDelDtor(value, 1i64);
  }
  else
  {
    Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
      p_StickyVariables,
      path,
      &value);
  }
}

// File Line: 3734
// RVA: 0x8BC9D0
void __fastcall Scaleform::GFx::MovieImpl::ClearStickyVariables(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::ASStringHash<Scaleform::GFx::MovieImpl::StickyVarNode *> *v1; // rsi
  Scaleform::GFx::ASStringHash<Scaleform::GFx::MovieImpl::StickyVarNode *> *p_StickyVariables; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rax
  unsigned __int64 v4; // rbx
  unsigned __int64 SizeMask; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // rdi
  __int64 v8; // rdi
  void (__fastcall ***v9)(_QWORD, __int64); // rcx
  unsigned __int64 v10; // rdx
  unsigned __int64 *v11; // rcx

  v1 = 0i64;
  p_StickyVariables = &this->StickyVariables;
  pTable = this->StickyVariables.mHash.pTable;
  v4 = 0i64;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v6 = pTable + 1;
    do
    {
      if ( v6->EntryCount != -2i64 )
        break;
      ++v4;
      v6 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v6 + 24);
    }
    while ( v4 <= SizeMask );
    v1 = p_StickyVariables;
  }
  while ( v1 )
  {
    v7 = v1->mHash.pTable;
    if ( !v1->mHash.pTable || (signed __int64)v4 > (signed __int64)v7->SizeMask )
      break;
    v8 = *(&v7[2].EntryCount + 3 * v4);
    while ( v8 )
    {
      v9 = (void (__fastcall ***)(_QWORD, __int64))v8;
      v8 = *(_QWORD *)(v8 + 16);
      (**v9)(v9, 1i64);
    }
    v10 = v1->mHash.pTable->SizeMask;
    if ( (__int64)v4 <= (__int64)v10 && ++v4 <= v10 )
    {
      v11 = &v1->mHash.pTable[1].EntryCount + 3 * v4;
      do
      {
        if ( *v11 != -2i64 )
          break;
        ++v4;
        v11 += 3;
      }
      while ( v4 <= v10 );
    }
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&p_StickyVariables->mHash);
}

// File Line: 3783
// RVA: 0x9014F0
void __fastcall Scaleform::GFx::MovieImpl::ResetFocusStates(Scaleform::GFx::MovieImpl *this)
{
  unsigned int i; // esi
  char *v3; // rdi
  _QWORD *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASStringNode *v8; // rcx

  for ( i = 0; i < this->FocusGroupsCnt; ++i )
  {
    v3 = (char *)this + 96 * i;
    v4 = (_QWORD *)*((_QWORD *)v3 + 2458);
    if ( v4 )
    {
      if ( (int)--*(_DWORD *)v4 <= 0 )
      {
        v5 = (Scaleform::GFx::ASStringNode *)v4[4];
        v6 = v5->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v5);
        v7 = (Scaleform::GFx::ASStringNode *)v4[3];
        v6 = v7->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
        v8 = (Scaleform::GFx::ASStringNode *)v4[2];
        v6 = v8->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
      }
    }
    *((_QWORD *)v3 + 2458) = 0i64;
    if ( (v3[19697] & 1) != 0 )
    {
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy> *)(v3 + 19624),
        *((__int64 **)v3 + 2456),
        0i64);
      v3[19697] = 0;
    }
    *((_DWORD *)v3 + 4918) = 0;
  }
}

// File Line: 3793
// RVA: 0x906A80
char __fastcall Scaleform::GFx::MovieImpl::SetControllerFocusGroup(
        Scaleform::GFx::MovieImpl *this,
        unsigned int controllerIdx,
        unsigned int focusGroupIndex)
{
  if ( controllerIdx >= 0x10 || focusGroupIndex >= 0x10 )
    return 0;
  this->FocusGroupIndexes[controllerIdx] = focusGroupIndex;
  if ( focusGroupIndex >= this->FocusGroupsCnt )
    this->FocusGroupsCnt = focusGroupIndex + 1;
  return 1;
}

// File Line: 3804
// RVA: 0x8D64F0
__int64 __fastcall Scaleform::GFx::MovieImpl::GetControllerFocusGroup(
        Scaleform::GFx::MovieImpl *this,
        unsigned int controllerIdx)
{
  if ( controllerIdx < 0x10 )
    return (unsigned __int8)this->FocusGroupIndexes[controllerIdx];
  else
    return 0i64;
}

// File Line: 3811
// RVA: 0x8CB3C0
void __fastcall Scaleform::GFx::MovieImpl::FillTabableArray(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo)
{
  Scaleform::GFx::FocusGroupDescr *pFocusGroup; // rsi
  char TabableArrayStatus; // al
  Scaleform::GFx::CharacterHandle *pObject; // rdx
  Scaleform::GFx::DisplayObject *pCharacter; // rbx
  unsigned __int8 AvmObjOffset; // al
  __int64 v9; // rax
  __int64 Size_low; // rdi
  __int64 v11; // rbx
  __int64 v12; // rcx
  unsigned __int8 v13; // al
  __int64 v14; // rax
  unsigned __int64 Size; // r8
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *v16; // rcx
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *p_TabableArray; // [rsp+28h] [rbp-30h] BYREF
  char v18; // [rsp+30h] [rbp-28h]
  bool InclFocusEnabled; // [rsp+31h] [rbp-27h]
  char v20; // [rsp+32h] [rbp-26h]

  pFocusGroup = pfocusInfo->pFocusGroup;
  if ( pfocusInfo->InclFocusEnabled )
  {
    TabableArrayStatus = pFocusGroup->TabableArrayStatus;
    if ( (TabableArrayStatus & 1) != 0 && (TabableArrayStatus & 2) == 0 )
    {
      Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Resize(
        &pFocusGroup->TabableArray.Data,
        0i64);
      pFocusGroup->TabableArrayStatus = 0;
    }
  }
  if ( (pFocusGroup->TabableArrayStatus & 1) == 0 )
  {
    v18 = 0;
    v20 = 0;
    p_TabableArray = &pFocusGroup->TabableArray;
    InclFocusEnabled = pfocusInfo->InclFocusEnabled;
    pObject = pFocusGroup->ModalClip.pObject;
    if ( !pObject )
      goto LABEL_13;
    pCharacter = pObject->pCharacter;
    if ( pCharacter
      || (pCharacter = (Scaleform::GFx::DisplayObject *)this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[8].__vecDelDtor(
                                                          this->pASMovieRoot.pObject,
                                                          &pObject->NamePath)) != 0i64 )
    {
      ++pCharacter->RefCount;
    }
    if ( pCharacter )
    {
      Scaleform::RefCountNTSImpl::Release(pCharacter);
      AvmObjOffset = pCharacter->AvmObjOffset;
      if ( AvmObjOffset )
      {
        v9 = ((__int64 (__fastcall *)(_DWORD *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&pCharacter->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                        + 4 * AvmObjOffset))[5].__vecDelDtor)((_DWORD *)pCharacter + AvmObjOffset);
        (*(void (__fastcall **)(__int64, Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> **))(*(_QWORD *)v9 + 184i64))(
          v9,
          &p_TabableArray);
      }
    }
    else
    {
LABEL_13:
      Size_low = SLODWORD(this->MovieLevels.Data.Size);
      if ( Size_low > 0 )
      {
        v11 = 16 * Size_low - 16;
        do
        {
          v12 = *(__int64 *)((char *)&this->MovieLevels.Data.Data->pSprite.pObject + v11);
          if ( (*(_WORD *)(v12 + 106) & 0x200) != 0 )
          {
            v13 = *(_BYTE *)(v12 + 109);
            if ( v13 )
            {
              v14 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v12 + 4i64 * v13) + 40i64))(v12 + 4i64 * v13);
              (*(void (__fastcall **)(__int64, Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> **))(*(_QWORD *)v14 + 184i64))(
                v14,
                &p_TabableArray);
            }
          }
          --Size_low;
          v11 -= 16i64;
        }
        while ( Size_low > 0 );
      }
    }
    Size = pFocusGroup->TabableArray.Data.Size;
    v16 = &pFocusGroup->TabableArray;
    if ( v18 )
      Scaleform::Alg::QuickSortSliced<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TabIndexSortFunctor>(
        v16,
        0i64,
        Size,
        byte_142440EF4);
    else
      Scaleform::Alg::QuickSortSliced<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AutoTabSortFunctor>(
        v16,
        0i64,
        Size,
        byte_142440EF5);
    pFocusGroup->TabableArrayStatus = 1;
    if ( pfocusInfo->InclFocusEnabled )
      pFocusGroup->TabableArrayStatus = 3;
  }
}

// File Line: 3864
// RVA: 0x8E4120
void __fastcall Scaleform::GFx::MovieImpl::InitFocusKeyInfo(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo,
        Scaleform::GFx::InputEventsQueueEntry::KeyEntry *keyEntry,
        bool inclFocusEnabled,
        Scaleform::GFx::FocusGroupDescr *pfocusGroup)
{
  Scaleform::GFx::FocusGroupDescr *v6; // rdi
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  Scaleform::GFx::Sprite *pObject; // rax
  Scaleform::GFx::InteractiveObject *v11; // rcx
  Scaleform::GFx::InteractiveObject *v12; // rdx
  unsigned __int64 v13; // rax
  unsigned __int64 Size; // r8
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *Data; // rcx
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+48h] [rbp+10h] BYREF

  if ( !pfocusInfo->Initialized )
  {
    v6 = pfocusGroup;
    if ( !pfocusGroup )
      v6 = &this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[(unsigned __int8)keyEntry->KeyboardIndex]];
    pfocusInfo->pFocusGroup = v6;
    pfocusInfo->PrevKeyCode = v6->LastFocusKeyCode;
    y2 = v6->LastFocusedRect.y2;
    x2 = v6->LastFocusedRect.x2;
    y1 = v6->LastFocusedRect.y1;
    pfocusInfo->Prev_aRect.x1 = v6->LastFocusedRect.x1;
    pfocusInfo->Prev_aRect.y1 = y1;
    pfocusInfo->Prev_aRect.x2 = x2;
    pfocusInfo->Prev_aRect.y2 = y2;
    pfocusInfo->InclFocusEnabled = inclFocusEnabled;
    pfocusInfo->ManualFocus = 0;
    pfocusInfo->KeyboardIndex = keyEntry->KeyboardIndex;
    pfocusInfo->KeyCode = keyEntry->Code;
    pfocusInfo->KeysState = keyEntry->KeysState;
    Scaleform::GFx::MovieImpl::FillTabableArray(this, pfocusInfo);
    pfocusInfo->CurFocusIdx = -1;
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v6->LastFocused,
      &result);
    pObject = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      pObject = result.pObject;
    }
    v11 = pfocusInfo->CurFocused.pObject;
    if ( v11 )
    {
      Scaleform::RefCountNTSImpl::Release(v11);
      pObject = result.pObject;
    }
    pfocusInfo->CurFocused.pObject = pObject;
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release(result.pObject);
    v12 = pfocusInfo->CurFocused.pObject;
    if ( v12 )
    {
      v13 = 0i64;
      Size = v6->TabableArray.Data.Size;
      if ( Size )
      {
        Data = v6->TabableArray.Data.Data;
        while ( Data->pObject != v12 )
        {
          ++v13;
          ++Data;
          if ( v13 >= Size )
            goto LABEL_17;
        }
        pfocusInfo->CurFocusIdx = v13;
      }
    }
LABEL_17:
    pfocusInfo->Initialized = 1;
  }
}

// File Line: 3906
// RVA: 0x8F1140
void __fastcall Scaleform::GFx::MovieImpl::ProcessFocusKey(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Event::EventType event,
        Scaleform::GFx::InputEventsQueueEntry::KeyEntry *keyEntry,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo)
{
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry *v5; // rbx
  unsigned int Code; // r9d
  Scaleform::GFx::FocusGroupDescr *pFocusGroup; // r15
  __int64 Size; // r13
  __int64 v10; // rdx
  __int64 CurFocusIdx; // rdi
  int v12; // esi
  __int64 v13; // rbx
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  Scaleform::GFx::InteractiveObject *v15; // rcx
  Scaleform::GFx::InteractiveObject *v16; // rcx
  int v17; // eax
  Scaleform::Render::Rect<float> *v18; // rax
  unsigned int v19; // ecx
  unsigned int v20; // ecx
  __int64 v21; // rdi
  float v22; // xmm14_4
  float v23; // xmm10_4
  char v24; // r15
  int v25; // r13d
  __int64 v26; // rsi
  __int64 v27; // r12
  float v28; // xmm8_4
  __int64 v29; // rbx
  __int64 v30; // rax
  Scaleform::GFx::DisplayObjectBase *v31; // rbx
  Scaleform::Render::Rect<float> *v32; // rax
  unsigned int v33; // eax
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm3_4
  float x2; // xmm2_4
  float v38; // xmm1_4
  __m128 y1_low; // xmm3
  __m128 v40; // xmm5
  float v41; // xmm0_4
  float v42; // xmm0_4
  __m128 v43; // xmm2
  __m128 v44; // xmm4
  int v45; // ecx
  int v46; // ecx
  int v47; // ecx
  int v48; // ecx
  float v49; // xmm0_4
  float v50; // xmm0_4
  int v51; // ecx
  int v52; // ecx
  int v53; // ecx
  int v54; // ecx
  __int64 v55; // rdi
  __m128 x2_low; // xmm14
  float v57; // xmm15_4
  char v58; // r15
  int v59; // r13d
  __int64 v60; // rsi
  __int64 v61; // r12
  float v62; // xmm8_4
  __int64 v63; // rbx
  __int64 v64; // rax
  __int64 v65; // rbx
  Scaleform::GFx::DisplayObjectBase *v66; // rcx
  float *v67; // rax
  float v68; // xmm3_4
  float v69; // xmm4_4
  float v70; // xmm5_4
  float v71; // xmm6_4
  Scaleform::Render::Rect<float> *v72; // rax
  unsigned int v73; // eax
  float v74; // xmm3_4
  float v75; // xmm2_4
  float y1; // xmm3_4
  float y2; // xmm2_4
  float v78; // xmm1_4
  __m128 x1_low; // xmm4
  __m128 v80; // xmm5
  float v81; // xmm0_4
  float v82; // xmm0_4
  __m128 y2_low; // xmm3
  __m128 v84; // xmm2
  int v85; // ecx
  int v86; // ecx
  int v87; // ecx
  int v88; // ecx
  float v89; // xmm0_4
  float v90; // xmm0_4
  int v91; // ecx
  int v92; // ecx
  int v93; // ecx
  int v94; // ecx
  __int64 v95; // rax
  __int64 v96; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *Data; // rdi
  Scaleform::GFx::InteractiveObject *v98; // rax
  Scaleform::GFx::InteractiveObject *v99; // rcx
  Scaleform::GFx::InteractiveObject *v100; // rcx
  float v101; // [rsp+30h] [rbp-98h]
  float x1; // [rsp+30h] [rbp-98h]
  float v103; // [rsp+40h] [rbp-88h]
  Scaleform::Render::Matrix2x4<float> pr; // [rsp+48h] [rbp-80h] BYREF
  __int64 v105; // [rsp+68h] [rbp-60h]
  Scaleform::Render::Rect<float> v106; // [rsp+70h] [rbp-58h] BYREF
  __int64 v107; // [rsp+80h] [rbp-48h]
  char v108[16]; // [rsp+88h] [rbp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [rsp+98h] [rbp-30h] BYREF
  __int64 v110; // [rsp+198h] [rbp+D0h]
  float v111; // [rsp+1A0h] [rbp+D8h]
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry *v112; // [rsp+1A8h] [rbp+E0h]

  if ( event != F3_720_512 )
    return;
  v107 = -2i64;
  v5 = keyEntry;
  Code = keyEntry->Code;
  if ( Code != 9
    && (!this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[(unsigned __int8)keyEntry->KeyboardIndex]].FocusRectShown
     && !pfocusInfo->ManualFocus
     || Code - 37 > 3) )
  {
    return;
  }
  Scaleform::GFx::MovieImpl::InitFocusKeyInfo(this, pfocusInfo, keyEntry, 0, 0i64);
  pFocusGroup = pfocusInfo->pFocusGroup;
  *(_QWORD *)&pr.M[1][2] = pFocusGroup;
  Size = pFocusGroup->TabableArray.Data.Size;
  v105 = Size;
  v10 = (int)Size;
  *(_QWORD *)&v106.x1 = (int)Size;
  if ( v5->Code == 9 )
  {
    CurFocusIdx = pfocusInfo->CurFocusIdx;
    pfocusInfo->CurFocusIdx = -1;
    v12 = 0;
    v13 = CurFocusIdx;
    if ( (int)Size <= 0 )
      goto LABEL_222;
    while ( 1 )
    {
      if ( (v112->KeysState & 1) != 0 )
      {
        LODWORD(CurFocusIdx) = CurFocusIdx - 1;
        if ( --v13 < 0 )
        {
          LODWORD(CurFocusIdx) = Size - 1;
          v13 = v10 - 1;
        }
      }
      else
      {
        LODWORD(CurFocusIdx) = CurFocusIdx + 1;
        if ( ++v13 >= v10 )
        {
          LODWORD(CurFocusIdx) = 0;
          v13 = 0i64;
        }
      }
      pObject = pFocusGroup->TabableArray.Data.Data[v13].pObject;
      if ( pObject )
      {
        if ( pfocusInfo->InclFocusEnabled
          || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[87].__vecDelDtor)(pObject) )
        {
          v15 = pFocusGroup->TabableArray.Data.Data[v13].pObject;
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::MovieImpl *, _QWORD))v15->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[85].__vecDelDtor)(
                 v15,
                 this,
                 (unsigned __int8)pfocusInfo->KeyboardIndex) )
          {
            pfocusInfo->CurFocusIdx = CurFocusIdx;
            goto LABEL_222;
          }
        }
        v10 = *(_QWORD *)&v106.x1;
      }
      if ( ++v12 >= (int)Size )
        goto LABEL_222;
    }
  }
  v16 = pfocusInfo->CurFocused.pObject;
  if ( !v16 )
    goto LABEL_222;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v16->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[88].__vecDelDtor)(v16) )
  {
    v17 = HIBYTE(this->Flags) & 3;
    if ( v17 == 3 )
      v17 = -1;
    if ( v17 != 1 && !pfocusInfo->ManualFocus )
      goto LABEL_222;
  }
  Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(pfocusInfo->CurFocused.pObject, &result);
  v18 = (Scaleform::Render::Rect<float> *)pfocusInfo->CurFocused.pObject->vfptr[93].__vecDelDtor(
                                            pfocusInfo->CurFocused.pObject,
                                            &v106);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&result, (Scaleform::Render::Rect<float> *)&pr.M[0][2], v18);
  v19 = v5->Code;
  if ( pfocusInfo->PrevKeyCode == v19 )
  {
    if ( ((v19 - 38) & 0xFFFFFFFD) != 0 )
    {
      if ( ((v19 - 37) & 0xFFFFFFFD) == 0 )
      {
        pr.M[0][3] = pfocusInfo->Prev_aRect.y1;
        pr.M[1][1] = pfocusInfo->Prev_aRect.y2;
      }
    }
    else
    {
      pr.M[0][2] = pfocusInfo->Prev_aRect.x1;
      pr.M[1][0] = pfocusInfo->Prev_aRect.x2;
    }
  }
  else
  {
    *(_QWORD *)&pfocusInfo->Prev_aRect.x1 = *(_QWORD *)&pr.M[0][2];
    *(_QWORD *)&pfocusInfo->Prev_aRect.x2 = *(_QWORD *)&pr.M[1][0];
    pfocusInfo->PrevKeyCode = v5->Code;
  }
  v20 = v5->Code;
  if ( ((v20 - 37) & 0xFFFFFFFD) == 0 )
  {
    v55 = pfocusInfo->CurFocusIdx;
    v111 = FLOAT_2_1474836e9;
    if ( v20 == 39 )
      x2_low = (__m128)LODWORD(FLOAT_2_1474836e9);
    else
      x2_low = (__m128)LODWORD(FLOAT_N2_1474836e9);
    x1 = x2_low.m128_f32[0];
    v57 = FLOAT_2_1474836e9;
    v58 = 0;
    v59 = Size - 1;
    v60 = v55;
    if ( v59 <= 0 )
    {
LABEL_221:
      LODWORD(Size) = v105;
      pFocusGroup = *(Scaleform::GFx::FocusGroupDescr **)&pr.M[1][2];
      goto LABEL_222;
    }
    v61 = (unsigned int)v59;
    v62 = *(float *)&FLOAT_1_0;
    while ( 1 )
    {
      if ( v5->Code == 39 )
      {
        LODWORD(v55) = v55 + 1;
        ++v60;
      }
      else
      {
        LODWORD(v55) = v55 - 1;
        --v60;
      }
      if ( v60 < *(__int64 *)&v106.x1 )
      {
        if ( (int)v55 < 0 )
        {
          LODWORD(v55) = v59;
          v60 = *(_QWORD *)&v106.x1 - 1i64;
        }
      }
      else
      {
        LODWORD(v55) = 0;
        v60 = 0i64;
      }
      v63 = *(_QWORD *)(*(_QWORD *)&pr.M[1][2] + 8i64);
      v64 = *(_QWORD *)(v63 + 8 * v60);
      if ( v64 )
        ++*(_DWORD *)(v64 + 8);
      v65 = *(_QWORD *)(v63 + 8 * v60);
      *(_QWORD *)&v106.x2 = v65;
      if ( pfocusInfo->InclFocusEnabled || (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v65 + 696i64))(v65) )
      {
        if ( (*(unsigned __int8 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)v65 + 680i64))(
               v65,
               v110,
               (unsigned __int8)pfocusInfo->KeyboardIndex) )
        {
          break;
        }
      }
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v65);
LABEL_220:
      --v61;
      v5 = v112;
      if ( !v61 )
        goto LABEL_221;
    }
    *(_OWORD *)&pr.M[0][0] = _xmm;
    *(__m128 *)&pr.M[1][0] = _xmm;
    v66 = *(Scaleform::GFx::DisplayObjectBase **)(v65 + 56);
    if ( v66 )
    {
      Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(v66, &pr);
      v67 = (float *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v65 + 16i64))(v65);
      v68 = pr.M[0][0];
      v69 = pr.M[0][1];
      v70 = pr.M[1][0];
      v71 = pr.M[1][1];
      pr.M[0][0] = (float)(pr.M[0][0] * *v67) + (float)(pr.M[0][1] * v67[4]);
      pr.M[1][0] = (float)(pr.M[1][0] * *v67) + (float)(pr.M[1][1] * v67[4]);
      pr.M[0][1] = (float)(v68 * v67[1]) + (float)(pr.M[0][1] * v67[5]);
      pr.M[1][1] = (float)(v70 * v67[1]) + (float)(pr.M[1][1] * v67[5]);
      pr.M[1][2] = 0.0;
      pr.M[0][2] = 0.0;
      pr.M[0][3] = pr.M[0][3] + (float)((float)(v69 * v67[7]) + (float)(v68 * v67[3]));
      pr.M[1][3] = pr.M[1][3] + (float)((float)(v71 * v67[7]) + (float)(v70 * v67[3]));
    }
    else
    {
      *(_OWORD *)&pr.M[0][0] = _xmm;
      *(__m128 *)&pr.M[1][0] = _xmm;
    }
    v72 = (Scaleform::Render::Rect<float> *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v65 + 744i64))(
                                              v65,
                                              v108);
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&pr, &v106, v72);
    v73 = v112->Code;
    if ( v73 == 39 )
    {
      v74 = pr.M[1][0] + v62;
      v75 = FLOAT_3_4028235e38;
    }
    else
    {
      v75 = pr.M[0][2] - v62;
      v74 = FLOAT_1_1754944eN38;
    }
    if ( v106.y2 < pr.M[0][3] || pr.M[1][1] < v106.y1 || v75 < v106.x1 || v106.x2 < v74 )
      goto LABEL_162;
    y1 = v106.y1;
    y2 = v106.y2;
    if ( v106.y1 <= pr.M[0][3] )
      y1 = pr.M[0][3];
    if ( v106.y2 > pr.M[1][1] )
      y2 = pr.M[1][1];
    if ( (float)(y2 - y1) < 40.0 )
    {
LABEL_162:
      if ( v58 )
        goto LABEL_219;
    }
    else if ( !v58 )
    {
      x1 = v106.x1;
      v111 = v106.y2;
      v58 = 1;
LABEL_218:
      x2_low = (__m128)LODWORD(v106.x2);
      v57 = v106.y1;
      pfocusInfo->CurFocusIdx = v55;
      goto LABEL_219;
    }
    v78 = (float)((float)(pr.M[1][1] - pr.M[0][3]) * 0.5) + pr.M[0][3];
    if ( v73 == 39 )
    {
      x1_low = (__m128)LODWORD(v106.x1);
      v80 = (__m128)LODWORD(x1);
      if ( pr.M[1][0] > v106.x1 )
        x1_low = (__m128)LODWORD(pr.M[1][0]);
      if ( pr.M[1][0] > x1 )
        v80 = (__m128)LODWORD(pr.M[1][0]);
      if ( v106.x2 < x1_low.m128_f32[0] || v106.y2 < v106.y1 )
        goto LABEL_219;
      v81 = (float)(v106.x2 - x1_low.m128_f32[0]) * 0.050000001;
      v82 = v81 <= 0.0 ? v81 - 0.5 : v81 + 0.5;
      if ( (int)v82 <= 3 )
        goto LABEL_219;
      y2_low = (__m128)LODWORD(v106.y2);
      v84 = (__m128)LODWORD(v111);
      x1_low.m128_f32[0] = (float)(x1_low.m128_f32[0] - pr.M[1][0]) * 0.050000001;
      v85 = (int)x1_low.m128_f32[0];
      if ( (int)x1_low.m128_f32[0] != 0x80000000 && (float)v85 != x1_low.m128_f32[0] )
        x1_low.m128_f32[0] = (float)(v85 - (_mm_movemask_ps(_mm_unpacklo_ps(x1_low, x1_low)) & 1));
      y2_low.m128_f32[0] = (float)((float)((float)((float)(v106.y2 - v106.y1) * 0.5) + v106.y1) - v78) * 0.050000001;
      v86 = (int)y2_low.m128_f32[0];
      if ( (int)y2_low.m128_f32[0] != 0x80000000 && (float)v86 != y2_low.m128_f32[0] )
        y2_low.m128_f32[0] = (float)(v86 - (_mm_movemask_ps(_mm_unpacklo_ps(y2_low, y2_low)) & 1));
      v80.m128_f32[0] = (float)(v80.m128_f32[0] - pr.M[1][0]) * 0.050000001;
      v87 = (int)v80.m128_f32[0];
      if ( (int)v80.m128_f32[0] != 0x80000000 && (float)v87 != v80.m128_f32[0] )
        v80.m128_f32[0] = (float)(v87 - (_mm_movemask_ps(_mm_unpacklo_ps(v80, v80)) & 1));
      v84.m128_f32[0] = (float)((float)((float)((float)(v111 - v57) * 0.5) + v57) - v78) * 0.050000001;
      v88 = (int)v84.m128_f32[0];
      if ( (int)v84.m128_f32[0] != 0x80000000 && (float)v88 != v84.m128_f32[0] )
        v84.m128_f32[0] = (float)(v88 - (_mm_movemask_ps(_mm_unpacklo_ps(v84, v84)) & 1));
      if ( x1_low.m128_f32[0] < 0.0 )
        goto LABEL_219;
    }
    else
    {
      x1_low = (__m128)LODWORD(v106.x2);
      v80 = x2_low;
      if ( pr.M[0][2] < v106.x2 )
        x1_low = (__m128)LODWORD(pr.M[0][2]);
      if ( pr.M[0][2] < x2_low.m128_f32[0] )
        v80 = (__m128)LODWORD(pr.M[0][2]);
      if ( x1_low.m128_f32[0] < v106.x1 || v106.y2 < v106.y1 )
        goto LABEL_219;
      v89 = (float)(x1_low.m128_f32[0] - v106.x1) * 0.050000001;
      v90 = v89 <= 0.0 ? v89 - 0.5 : v89 + 0.5;
      if ( (int)v90 <= 3 )
        goto LABEL_219;
      y2_low = (__m128)LODWORD(v106.y2);
      v84 = (__m128)LODWORD(v111);
      x1_low.m128_f32[0] = (float)(x1_low.m128_f32[0] - pr.M[0][2]) * 0.050000001;
      v91 = (int)x1_low.m128_f32[0];
      if ( (int)x1_low.m128_f32[0] != 0x80000000 && (float)v91 != x1_low.m128_f32[0] )
        x1_low.m128_f32[0] = (float)(v91 - (_mm_movemask_ps(_mm_unpacklo_ps(x1_low, x1_low)) & 1));
      y2_low.m128_f32[0] = (float)((float)((float)((float)(v106.y2 - v106.y1) * 0.5) + v106.y1) - v78) * 0.050000001;
      v92 = (int)y2_low.m128_f32[0];
      if ( (int)y2_low.m128_f32[0] != 0x80000000 && (float)v92 != y2_low.m128_f32[0] )
        y2_low.m128_f32[0] = (float)(v92 - (_mm_movemask_ps(_mm_unpacklo_ps(y2_low, y2_low)) & 1));
      v80.m128_f32[0] = (float)(v80.m128_f32[0] - pr.M[0][2]) * 0.050000001;
      v93 = (int)v80.m128_f32[0];
      if ( (int)v80.m128_f32[0] != 0x80000000 && (float)v93 != v80.m128_f32[0] )
        v80.m128_f32[0] = (float)(v93 - (_mm_movemask_ps(_mm_unpacklo_ps(v80, v80)) & 1));
      v84.m128_f32[0] = (float)((float)((float)((float)(v111 - v57) * 0.5) + v57) - v78) * 0.050000001;
      v94 = (int)v84.m128_f32[0];
      if ( (int)v84.m128_f32[0] != 0x80000000 && (float)v94 != v84.m128_f32[0] )
        v84.m128_f32[0] = (float)(v94 - (_mm_movemask_ps(_mm_unpacklo_ps(v84, v84)) & 1));
      if ( x1_low.m128_f32[0] > 0.0 )
        goto LABEL_219;
    }
    if ( v58 )
    {
      if ( COERCE_FLOAT(x1_low.m128_i32[0] & _xmm) >= COERCE_FLOAT(v80.m128_i32[0] & _xmm)
        && (x1_low.m128_f32[0] != v80.m128_f32[0]
         || COERCE_FLOAT(y2_low.m128_i32[0] & _xmm) >= COERCE_FLOAT(v84.m128_i32[0] & _xmm)) )
      {
        goto LABEL_219;
      }
      goto LABEL_217;
    }
    if ( (float)((float)(y2_low.m128_f32[0] * y2_low.m128_f32[0]) + (float)(x1_low.m128_f32[0] * x1_low.m128_f32[0])) < (float)((float)(v84.m128_f32[0] * v84.m128_f32[0]) + (float)(v80.m128_f32[0] * v80.m128_f32[0])) )
    {
LABEL_217:
      x1 = v106.x1;
      v111 = v106.y2;
      goto LABEL_218;
    }
LABEL_219:
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v65);
    v62 = *(float *)&FLOAT_1_0;
    goto LABEL_220;
  }
  if ( ((v20 - 38) & 0xFFFFFFFD) == 0 )
  {
    v21 = pfocusInfo->CurFocusIdx;
    v103 = 0.0;
    v101 = 0.0;
    v22 = FLOAT_2_1474836e9;
    if ( v20 == 40 )
      v23 = FLOAT_2_1474836e9;
    else
      v23 = FLOAT_N2_1474836e9;
    v111 = v23;
    v24 = 0;
    v25 = Size - 1;
    v26 = v21;
    if ( v25 > 0 )
    {
      v27 = (unsigned int)v25;
      v28 = *(float *)&FLOAT_1_0;
      while ( 1 )
      {
        if ( v5->Code == 40 )
        {
          LODWORD(v21) = v21 + 1;
          ++v26;
        }
        else
        {
          LODWORD(v21) = v21 - 1;
          --v26;
        }
        if ( v26 < *(__int64 *)&v106.x1 )
        {
          if ( (int)v21 < 0 )
          {
            LODWORD(v21) = v25;
            v26 = *(_QWORD *)&v106.x1 - 1i64;
          }
        }
        else
        {
          LODWORD(v21) = 0;
          v26 = 0i64;
        }
        v29 = *(_QWORD *)(*(_QWORD *)&pr.M[1][2] + 8i64);
        v30 = *(_QWORD *)(v29 + 8 * v26);
        if ( v30 )
          ++*(_DWORD *)(v30 + 8);
        v31 = *(Scaleform::GFx::DisplayObjectBase **)(v29 + 8 * v26);
        *(_QWORD *)&v106.x2 = v31;
        if ( pfocusInfo->InclFocusEnabled
          || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v31->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[87].__vecDelDtor)(v31) )
        {
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, __int64, _QWORD))v31->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[85].__vecDelDtor)(
                 v31,
                 v110,
                 (unsigned __int8)pfocusInfo->KeyboardIndex) )
          {
            break;
          }
        }
        Scaleform::RefCountNTSImpl::Release(v31);
LABEL_125:
        --v27;
        v5 = v112;
        if ( !v27 )
          goto LABEL_221;
      }
      Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(v31, &pr);
      v32 = (Scaleform::Render::Rect<float> *)v31->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[93].__vecDelDtor(
                                                v31,
                                                (unsigned int)v108);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&pr, &v106, v32);
      v33 = v112->Code;
      if ( v33 == 40 )
      {
        v34 = pr.M[1][1] + v28;
        v35 = FLOAT_3_4028235e38;
      }
      else
      {
        v35 = pr.M[0][3] - v28;
        v34 = FLOAT_1_1754944eN38;
      }
      if ( v106.y2 < v34 || v35 < v106.y1 || pr.M[1][0] < v106.x1 || v106.x2 < pr.M[0][2] )
        goto LABEL_67;
      v36 = v106.x1;
      x2 = v106.x2;
      if ( v106.x1 <= pr.M[0][2] )
        v36 = pr.M[0][2];
      if ( v106.x2 > pr.M[1][0] )
        x2 = pr.M[1][0];
      if ( (float)(x2 - v36) < 40.0 )
      {
LABEL_67:
        if ( v24 )
          goto LABEL_124;
      }
      else if ( !v24 )
      {
        v111 = v106.y1;
        v101 = v106.y2;
        v24 = 1;
LABEL_123:
        v103 = v106.x2;
        v22 = v106.x1;
        pfocusInfo->CurFocusIdx = v21;
        goto LABEL_124;
      }
      v38 = (float)((float)(pr.M[1][0] - pr.M[0][2]) * 0.5) + pr.M[0][2];
      if ( v33 == 38 )
      {
        y1_low = (__m128)LODWORD(v106.y2);
        v40 = (__m128)LODWORD(v101);
        if ( pr.M[0][3] < v106.y2 )
          y1_low = (__m128)LODWORD(pr.M[0][3]);
        if ( pr.M[0][3] < v101 )
          v40 = (__m128)LODWORD(pr.M[0][3]);
        if ( v106.x2 < v106.x1 || y1_low.m128_f32[0] < v106.y1 )
          goto LABEL_124;
        v41 = (float)(y1_low.m128_f32[0] - v106.y1) * 0.050000001;
        v42 = v41 <= 0.0 ? v41 - 0.5 : v41 + 0.5;
        if ( (int)v42 <= 3 )
          goto LABEL_124;
        v44 = (__m128)LODWORD(v106.x2);
        v43 = (__m128)LODWORD(v103);
        v44.m128_f32[0] = (float)((float)((float)((float)(v106.x2 - v106.x1) * 0.5) + v106.x1) - v38) * 0.050000001;
        v45 = (int)v44.m128_f32[0];
        if ( (int)v44.m128_f32[0] != 0x80000000 && (float)v45 != v44.m128_f32[0] )
          v44.m128_f32[0] = (float)(v45 - (_mm_movemask_ps(_mm_unpacklo_ps(v44, v44)) & 1));
        y1_low.m128_f32[0] = (float)(y1_low.m128_f32[0] - pr.M[0][3]) * 0.050000001;
        v46 = (int)y1_low.m128_f32[0];
        if ( (int)y1_low.m128_f32[0] != 0x80000000 && (float)v46 != y1_low.m128_f32[0] )
          y1_low.m128_f32[0] = (float)(v46 - (_mm_movemask_ps(_mm_unpacklo_ps(y1_low, y1_low)) & 1));
        v43.m128_f32[0] = (float)((float)((float)((float)(v103 - v22) * 0.5) + v22) - v38) * 0.050000001;
        v47 = (int)v43.m128_f32[0];
        if ( (int)v43.m128_f32[0] != 0x80000000 && (float)v47 != v43.m128_f32[0] )
          v43.m128_f32[0] = (float)(v47 - (_mm_movemask_ps(_mm_unpacklo_ps(v43, v43)) & 1));
        v40.m128_f32[0] = (float)(v40.m128_f32[0] - pr.M[0][3]) * 0.050000001;
        v48 = (int)v40.m128_f32[0];
        if ( (int)v40.m128_f32[0] != 0x80000000 && (float)v48 != v40.m128_f32[0] )
          v40.m128_f32[0] = (float)(v48 - (_mm_movemask_ps(_mm_unpacklo_ps(v40, v40)) & 1));
        if ( y1_low.m128_f32[0] > 0.0 )
          goto LABEL_124;
      }
      else
      {
        y1_low = (__m128)LODWORD(v106.y1);
        v40 = (__m128)LODWORD(v111);
        if ( pr.M[1][1] > v106.y1 )
          y1_low = (__m128)LODWORD(pr.M[1][1]);
        if ( pr.M[1][1] > v111 )
          v40 = (__m128)LODWORD(pr.M[1][1]);
        if ( v106.x2 < v106.x1 || v106.y2 < y1_low.m128_f32[0] )
          goto LABEL_124;
        v49 = (float)(v106.y2 - y1_low.m128_f32[0]) * 0.050000001;
        v50 = v49 <= 0.0 ? v49 - 0.5 : v49 + 0.5;
        if ( (int)v50 <= 3 )
          goto LABEL_124;
        v44 = (__m128)LODWORD(v106.x2);
        v43 = (__m128)LODWORD(v103);
        v44.m128_f32[0] = (float)((float)((float)((float)(v106.x2 - v106.x1) * 0.5) + v106.x1) - v38) * 0.050000001;
        v51 = (int)v44.m128_f32[0];
        if ( (int)v44.m128_f32[0] != 0x80000000 && (float)v51 != v44.m128_f32[0] )
          v44.m128_f32[0] = (float)(v51 - (_mm_movemask_ps(_mm_unpacklo_ps(v44, v44)) & 1));
        y1_low.m128_f32[0] = (float)(y1_low.m128_f32[0] - pr.M[1][1]) * 0.050000001;
        v52 = (int)y1_low.m128_f32[0];
        if ( (int)y1_low.m128_f32[0] != 0x80000000 && (float)v52 != y1_low.m128_f32[0] )
          y1_low.m128_f32[0] = (float)(v52 - (_mm_movemask_ps(_mm_unpacklo_ps(y1_low, y1_low)) & 1));
        v43.m128_f32[0] = (float)((float)((float)((float)(v103 - v22) * 0.5) + v22) - v38) * 0.050000001;
        v53 = (int)v43.m128_f32[0];
        if ( (int)v43.m128_f32[0] != 0x80000000 && (float)v53 != v43.m128_f32[0] )
          v43.m128_f32[0] = (float)(v53 - (_mm_movemask_ps(_mm_unpacklo_ps(v43, v43)) & 1));
        v40.m128_f32[0] = (float)(v40.m128_f32[0] - pr.M[1][1]) * 0.050000001;
        v54 = (int)v40.m128_f32[0];
        if ( (int)v40.m128_f32[0] != 0x80000000 && (float)v54 != v40.m128_f32[0] )
          v40.m128_f32[0] = (float)(v54 - (_mm_movemask_ps(_mm_unpacklo_ps(v40, v40)) & 1));
        if ( y1_low.m128_f32[0] < 0.0 )
          goto LABEL_124;
      }
      if ( v24 )
      {
        if ( COERCE_FLOAT(y1_low.m128_i32[0] & _xmm) >= COERCE_FLOAT(v40.m128_i32[0] & _xmm)
          && (y1_low.m128_f32[0] != v40.m128_f32[0]
           || COERCE_FLOAT(v44.m128_i32[0] & _xmm) >= COERCE_FLOAT(v43.m128_i32[0] & _xmm)) )
        {
          goto LABEL_124;
        }
        goto LABEL_122;
      }
      if ( (float)((float)(y1_low.m128_f32[0] * y1_low.m128_f32[0]) + (float)(v44.m128_f32[0] * v44.m128_f32[0])) < (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v43.m128_f32[0] * v43.m128_f32[0])) )
      {
LABEL_122:
        v111 = v106.y1;
        v101 = v106.y2;
        goto LABEL_123;
      }
LABEL_124:
      Scaleform::RefCountNTSImpl::Release(v31);
      v28 = *(float *)&FLOAT_1_0;
      goto LABEL_125;
    }
    goto LABEL_221;
  }
LABEL_222:
  v95 = pfocusInfo->CurFocusIdx;
  if ( (int)v95 < 0 || (int)v95 >= (int)Size )
  {
    v100 = pfocusInfo->CurFocused.pObject;
    if ( v100 )
      Scaleform::RefCountNTSImpl::Release(v100);
    pfocusInfo->CurFocused.pObject = 0i64;
  }
  else
  {
    v96 = pfocusInfo->CurFocusIdx;
    Data = pFocusGroup->TabableArray.Data.Data;
    v98 = Data[v95].pObject;
    if ( v98 )
      ++v98->RefCount;
    v99 = pfocusInfo->CurFocused.pObject;
    if ( v99 )
      Scaleform::RefCountNTSImpl::Release(v99);
    pfocusInfo->CurFocused = Data[v96];
  }
}

// File Line: 4261
// RVA: 0x8CB550
void __fastcall Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo)
{
  __int64 v4; // rsi
  int CurFocusIdx; // eax
  Scaleform::GFx::InteractiveObject *pObject; // r14
  Scaleform::GFx::Sprite *v7; // rbx
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v12; // [rsp+68h] [rbp+10h]

  v4 = (unsigned __int8)this->FocusGroupIndexes[(unsigned __int8)pfocusInfo->KeyboardIndex];
  if ( pfocusInfo->Initialized && (this->FocusGroups[v4].TabableArrayStatus & 1) != 0 )
  {
    CurFocusIdx = pfocusInfo->CurFocusIdx;
    if ( CurFocusIdx >= 0 && CurFocusIdx < SLODWORD(this->FocusGroups[v4].TabableArray.Data.Size) )
    {
      pObject = this->FocusGroups[v4].TabableArray.Data.Data[pfocusInfo->CurFocusIdx].pObject;
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[v4].LastFocused,
        &result);
      v7 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        v7 = result.pObject;
      }
      v12 = v7;
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release(result.pObject);
      if ( v7 != pObject )
      {
        this->FocusGroups[v4].LastFocusKeyCode = pfocusInfo->PrevKeyCode;
        y2 = pfocusInfo->Prev_aRect.y2;
        x2 = pfocusInfo->Prev_aRect.x2;
        y1 = pfocusInfo->Prev_aRect.y1;
        this->FocusGroups[v4].LastFocusedRect.x1 = pfocusInfo->Prev_aRect.x1;
        this->FocusGroups[v4].LastFocusedRect.y1 = y1;
        this->FocusGroups[v4].LastFocusedRect.x2 = x2;
        this->FocusGroups[v4].LastFocusedRect.y2 = y2;
        Scaleform::GFx::MovieImpl::QueueSetFocusTo(
          this,
          pObject,
          0i64,
          (unsigned __int8)pfocusInfo->KeyboardIndex,
          GFx_FocusMovedByKeyboard,
          pfocusInfo);
      }
      if ( pObject
        && ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject *))pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(pObject) == 4 )
      {
        if ( this->FocusGroups[v4].FocusRectShown )
          this->FocusRectChanged = 1;
        this->FocusGroups[v4].FocusRectShown = 0;
      }
      else
      {
        if ( !this->FocusGroups[v4].FocusRectShown )
          this->FocusRectChanged = 1;
        this->FocusGroups[v4].FocusRectShown = 1;
      }
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
    }
  }
}

// File Line: 4316
// RVA: 0x909820
void __fastcall Scaleform::GFx::MovieImpl::SetModalClip(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *pmovie,
        unsigned int controllerIdx)
{
  char *v3; // rsi
  _QWORD *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::CharacterHandle *pObject; // rdi
  _QWORD *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx

  v3 = (char *)this + 96 * (unsigned __int8)this->FocusGroupIndexes[controllerIdx];
  if ( pmovie )
  {
    pObject = pmovie->pNameHandle.pObject;
    if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pmovie)) != 0i64 )
      ++pObject->RefCount;
    v10 = (_QWORD *)*((_QWORD *)v3 + 2458);
    if ( v10 )
    {
      if ( (int)--*(_DWORD *)v10 <= 0 )
      {
        v11 = (Scaleform::GFx::ASStringNode *)v10[4];
        v6 = v11->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        v12 = (Scaleform::GFx::ASStringNode *)v10[3];
        v6 = v12->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        v13 = (Scaleform::GFx::ASStringNode *)v10[2];
        v6 = v13->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
      }
    }
    *((_QWORD *)v3 + 2458) = pObject;
  }
  else
  {
    v4 = (_QWORD *)*((_QWORD *)v3 + 2458);
    if ( v4 )
    {
      if ( (int)--*(_DWORD *)v4 <= 0 )
      {
        v5 = (Scaleform::GFx::ASStringNode *)v4[4];
        v6 = v5->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v5);
        v7 = (Scaleform::GFx::ASStringNode *)v4[3];
        v6 = v7->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
        v8 = (Scaleform::GFx::ASStringNode *)v4[2];
        v6 = v8->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
      }
    }
    *((_QWORD *)v3 + 2458) = 0i64;
  }
}

// File Line: 4326
// RVA: 0x8DB0F0
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::MovieImpl::GetModalClip(
        Scaleform::GFx::MovieImpl *this,
        unsigned int controllerIdx)
{
  Scaleform::GFx::CharacterHandle *pObject; // rdx
  Scaleform::RefCountNTSImpl *pCharacter; // rbx

  pObject = this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]].ModalClip.pObject;
  if ( !pObject )
    return 0i64;
  pCharacter = pObject->pCharacter;
  if ( pCharacter
    || (pCharacter = (Scaleform::RefCountNTSImpl *)this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[8].__vecDelDtor(
                                                     this->pASMovieRoot.pObject,
                                                     &pObject->NamePath)) != 0i64 )
  {
    ++pCharacter->RefCount;
  }
  if ( !pCharacter )
    return 0i64;
  Scaleform::RefCountNTSImpl::Release(pCharacter);
  return (Scaleform::GFx::Sprite *)pCharacter;
}

// File Line: 4332
// RVA: 0x8D6510
__int64 __fastcall Scaleform::GFx::MovieImpl::GetControllerMaskByFocusGroup(
        Scaleform::GFx::MovieImpl *this,
        unsigned int focusGroupIndex)
{
  unsigned int v2; // r9d
  char *v3; // r10
  int v4; // r8d
  __int64 v5; // r11
  int v6; // r8d
  int v7; // r8d
  int v8; // r8d

  v2 = 0;
  v3 = &this->FocusGroupIndexes[1];
  v4 = 1;
  v5 = 4i64;
  do
  {
    if ( (unsigned __int8)*(v3 - 1) == focusGroupIndex )
      v2 |= v4;
    v6 = 2 * v4;
    if ( (unsigned __int8)*v3 == focusGroupIndex )
      v2 |= v6;
    v7 = 2 * v6;
    if ( (unsigned __int8)v3[1] == focusGroupIndex )
      v2 |= v7;
    v8 = 2 * v7;
    if ( (unsigned __int8)v3[2] == focusGroupIndex )
      v2 |= v8;
    v4 = 2 * v8;
    v3 += 4;
    --v5;
  }
  while ( v5 );
  return v2;
}

// File Line: 4343
// RVA: 0x916D10
void __fastcall Scaleform::GFx::MovieImpl::UpdateFocusRectRenderNodes(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::Render::TreeContainer *pObject; // rbx
  Scaleform::Render::TreeContainer *v3; // rbx
  Scaleform::Render::TreeContainer *v4; // rcx
  bool v5; // zf
  __int64 Size; // rax
  __int64 v7; // r13
  int v8; // edi
  __int64 v9; // r12
  Scaleform::GFx::Sprite *v10; // rbx
  Scaleform::GFx::DisplayObjectBase *pParent; // rcx
  Scaleform::Render::Matrix3x4<float> *v12; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm9_4
  float v23; // xmm10_4
  float v24; // xmm11_4
  float *v25; // rax
  float v26; // xmm0_4
  float v27; // xmm7_4
  float v28; // xmm8_4
  float v29; // xmm9_4
  float v30; // xmm10_4
  Scaleform::MemoryHeap *v31; // rcx
  Scaleform::Render::ShapeDataFloat *v32; // rax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v33; // rax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v34; // rsi
  __int64 v35; // rcx
  __int64 v36; // rdx
  Scaleform::MemoryHeap *v37; // rdx
  float StartX; // xmm1_4
  float v39; // xmm1_4
  float v40; // xmm1_4
  float v41; // xmm7_4
  float v42; // xmm1_4
  Scaleform::MemoryHeap *v43; // rcx
  Scaleform::Render::ShapeMeshProvider *v44; // rax
  Scaleform::Render::ContextImpl::EntryDataVtbl *v45; // rax
  Scaleform::Render::ContextImpl::EntryDataVtbl *v46; // r15
  Scaleform::Render::TreeShape *v47; // rdi
  Scaleform::Render::TreeShape *v48; // rcx
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+20h] [rbp-A0h] BYREF
  Scaleform::Render::Rect<float> v50; // [rsp+50h] [rbp-70h] BYREF
  Scaleform::Render::Rect<float> v51; // [rsp+60h] [rbp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+70h] [rbp-50h] BYREF
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v53; // [rsp+A0h] [rbp-20h]
  Scaleform::Render::TreeShape *v54; // [rsp+A8h] [rbp-18h]
  __int64 v55; // [rsp+B0h] [rbp-10h]
  unsigned int v56; // [rsp+B8h] [rbp-8h]
  __int64 v57; // [rsp+C0h] [rbp+0h]
  Scaleform::Render::ContextImpl::EntryDataVtbl *v58; // [rsp+C8h] [rbp+8h]
  int v59; // [rsp+190h] [rbp+D0h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+198h] [rbp+D8h] BYREF
  Scaleform::GFx::Sprite *v61; // [rsp+1A0h] [rbp+E0h]
  Scaleform::MemoryHeap *pHeap; // [rsp+1A8h] [rbp+E8h]

  v55 = -2i64;
  if ( this->pMainMovie )
  {
    pObject = this->FocusRectContainerNode.pObject;
    if ( pObject )
    {
      Size = Scaleform::Render::TreeContainer::GetSize(this->FocusRectContainerNode.pObject);
      Scaleform::Render::TreeContainer::Remove(pObject, 0i64, Size);
    }
    else
    {
      v3 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&this->RenderContext);
      v4 = this->FocusRectContainerNode.pObject;
      if ( v4 )
      {
        v5 = v4->RefCount-- == 1;
        if ( v5 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
      }
      this->FocusRectContainerNode.pObject = v3;
      Scaleform::Render::TreeContainer::Add(this->pRenderRoot.pObject, v3);
    }
    v7 = 0i64;
    if ( this->FocusGroupsCnt )
    {
      v8 = 0;
      v59 = 0;
      do
      {
        v9 = v7;
        Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
          (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[v7].LastFocused,
          &result);
        v10 = result.pObject;
        if ( result.pObject )
        {
          ++result.pObject->RefCount;
          v10 = result.pObject;
        }
        v61 = v10;
        if ( result.pObject )
          Scaleform::RefCountNTSImpl::Release(result.pObject);
        if ( v10
          && this->FocusGroups[v9].FocusRectShown
          && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *))v10->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[88].__vecDelDtor)(v10) )
        {
          v10->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[93].__vecDelDtor(
            v10,
            (unsigned int)&v51);
          if ( v51.x2 == v51.x1 && v51.y2 == v51.y1 )
          {
            Scaleform::RefCountNTSImpl::Release(v10);
            return;
          }
          memset(&Dst, 0, sizeof(Dst));
          Dst.M[0][0] = 1.0;
          Dst.M[1][1] = 1.0;
          Dst.M[2][2] = 1.0;
          pParent = v10->pParent;
          if ( pParent )
          {
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(pParent, &Dst);
            v12 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))v10->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(v10);
            m1 = Dst;
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&Dst, &m1, v12);
            v13 = Dst.M[2][3];
            v14 = Dst.M[2][2];
            v15 = Dst.M[2][1];
            v16 = Dst.M[2][0];
            v17 = Dst.M[1][3];
            v18 = Dst.M[1][2];
            v19 = Dst.M[1][1];
            v20 = Dst.M[1][0];
            v21 = Dst.M[0][3];
            v22 = Dst.M[0][2];
            v23 = Dst.M[0][1];
            v24 = Dst.M[0][0];
          }
          else
          {
            v25 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))v10->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(v10);
            v24 = *v25;
            Dst.M[0][0] = *v25;
            v23 = v25[1];
            Dst.M[0][1] = v23;
            v22 = v25[2];
            Dst.M[0][2] = v22;
            v21 = v25[3];
            Dst.M[0][3] = v21;
            v20 = v25[4];
            Dst.M[1][0] = v20;
            v19 = v25[5];
            Dst.M[1][1] = v19;
            v18 = v25[6];
            Dst.M[1][2] = v18;
            v17 = v25[7];
            Dst.M[1][3] = v17;
            v16 = v25[8];
            Dst.M[2][0] = v16;
            v15 = v25[9];
            Dst.M[2][1] = v15;
            v14 = v25[10];
            Dst.M[2][2] = v14;
            v13 = v25[11];
            Dst.M[2][3] = v13;
          }
          *(_QWORD *)&Dst.M[2][0] = __PAIR64__(LODWORD(v23), LODWORD(v24));
          *(_QWORD *)&Dst.M[2][2] = __PAIR64__(LODWORD(v21), LODWORD(v22));
          v50.x1 = v20;
          v50.y1 = v19;
          v50.x2 = v18;
          v50.y2 = v17;
          v51.x1 = v16;
          v51.y1 = v15;
          v51.x2 = v14;
          v51.y2 = v13;
          Scaleform::Render::Matrix3x4<float>::EncloseTransform(
            (Scaleform::Render::Matrix3x4<float> *)Dst.M[2],
            &v50,
            &v51);
          v26 = (float)(int)v7 * 20.0;
          v27 = v50.x1 - v26;
          v50.x1 = v50.x1 - v26;
          v28 = v50.x2 + v26;
          v50.x2 = v50.x2 + v26;
          v29 = v50.y1 - v26;
          v50.y1 = v50.y1 - v26;
          v30 = v50.y2 + v26;
          v50.y2 = v50.y2 + v26;
          pHeap = this->RenderContext.pHeap;
          v32 = (Scaleform::Render::ShapeDataFloat *)pHeap->vfptr->Alloc(v31, 128ui64, 0i64);
          *(_QWORD *)&m1.M[0][0] = v32;
          if ( v32 )
          {
            Scaleform::Render::ShapeDataFloat::ShapeDataFloat(v32);
            v34 = v33;
          }
          else
          {
            v34 = 0i64;
          }
          v53 = v34;
          v57 = 0i64;
          v56 = v8 ^ 0xFFFFFF00 | 0xFF000000;
          Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &v34->Fills.Data,
            &v34->Fills,
            v34->Fills.Data.Size + 1);
          v35 = 16 * v34->Fills.Data.Size;
          v36 = (__int64)&v34->Fills.Data.Data[-1];
          v5 = v35 + v36 == 0;
          v37 = (Scaleform::MemoryHeap *)(v35 + v36);
          pHeap = v37;
          *(_QWORD *)&m1.M[0][0] = v37;
          if ( !v5 )
          {
            LODWORD(v37->vfptr) = v8 ^ 0xFFFFFF00 | 0xFF000000;
            v37->pPrev = 0i64;
          }
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
            v34,
            1u,
            0,
            0);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
            v34,
            v27,
            v29);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v28,
            v29);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v28,
            v29 + 20.0);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v27,
            v29 + 20.0);
          StartX = v34->StartX;
          if ( StartX != v34->LastX || v34->StartY != v34->LastY )
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
              v34,
              StartX,
              v34->StartY);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v34);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
            v34,
            1u,
            0,
            0);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
            v34,
            v28,
            v29);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v28,
            v30);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v28 - 20.0,
            v30);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v28 - 20.0,
            v29);
          v39 = v34->StartX;
          if ( v39 != v34->LastX || v34->StartY != v34->LastY )
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
              v34,
              v39,
              v34->StartY);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v34);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
            v34,
            1u,
            0,
            0);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
            v34,
            v28,
            v30);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v27,
            v30);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v27,
            v30 - 20.0);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v28,
            v30 - 20.0);
          v40 = v34->StartX;
          if ( v40 != v34->LastX || v34->StartY != v34->LastY )
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
              v34,
              v40,
              v34->StartY);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v34);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
            v34,
            1u,
            0,
            0);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
            v34,
            v27,
            v30);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v27,
            v29);
          v41 = v27 + 20.0;
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v41,
            v29);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
            v34,
            v41,
            v30);
          v42 = v34->StartX;
          if ( v42 != v34->LastX || v34->StartY != v34->LastY )
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
              v34,
              v42,
              v34->StartY);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v34);
          Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v34);
          pHeap = this->RenderContext.pHeap;
          v44 = (Scaleform::Render::ShapeMeshProvider *)pHeap->vfptr->Alloc(v43, 144ui64, 0i64);
          *(_QWORD *)&m1.M[0][0] = v44;
          if ( v44 )
          {
            Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v44, v34, 0i64);
            v46 = v45;
          }
          else
          {
            v46 = 0i64;
          }
          v58 = v46;
          v47 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(&this->RenderContext);
          v54 = v47;
          Scaleform::Render::TreeShape::SetShape(v47, v46);
          Scaleform::Render::TreeContainer::Add(this->FocusRectContainerNode.pObject, v47);
          if ( v47 )
            ++v47->RefCount;
          v48 = this->FocusGroups[v9].FocusRectNode.pObject;
          if ( v48 )
          {
            v5 = v48->RefCount-- == 1;
            if ( v5 )
              Scaleform::Render::ContextImpl::Entry::destroyHelper(v48);
          }
          this->FocusGroups[v9].FocusRectNode.pObject = v47;
          if ( v47 )
          {
            v5 = v47->RefCount-- == 1;
            if ( v5 )
              Scaleform::Render::ContextImpl::Entry::destroyHelper(v47);
          }
          if ( v46 )
            (*((void (__fastcall **)(void (__fastcall **)(Scaleform::Render::ContextImpl::EntryData *, void *)))v46->CopyTo
             + 2))(&v46->CopyTo);
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v34);
          v8 = v59;
        }
        if ( v10 )
          Scaleform::RefCountNTSImpl::Release(v10);
        v7 = (unsigned int)(v7 + 1);
        v8 += 1081552;
        v59 = v8;
      }
      while ( (unsigned int)v7 < this->FocusGroupsCnt );
    }
    this->FocusRectChanged = 0;
  }
}

// File Line: 4434
// RVA: 0x8E32E0
void __fastcall Scaleform::GFx::MovieImpl::HideFocusRect(Scaleform::GFx::MovieImpl *this, unsigned int controllerIdx)
{
  __int64 v4; // rdi
  Scaleform::GFx::Sprite *pObject; // rbx
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v7; // [rsp+60h] [rbp+18h]

  v4 = (unsigned __int8)this->FocusGroupIndexes[controllerIdx];
  if ( this->FocusGroups[v4].FocusRectShown )
  {
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[v4].LastFocused,
      &result);
    pObject = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      pObject = result.pObject;
    }
    v7 = pObject;
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release(result.pObject);
    if ( pObject
      && pObject->pParent
      && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *, _QWORD, _QWORD, __int64, __int64))pObject->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[92].__vecDelDtor)(
            pObject,
            0i64,
            controllerIdx,
            2i64,
            -2i64) )
    {
      Scaleform::RefCountNTSImpl::Release(pObject);
      return;
    }
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
  }
  this->FocusGroups[v4].FocusRectShown = 0;
  this->FocusRectChanged = 1;
}

// File Line: 4448
// RVA: 0x907520
__int64 __fastcall Scaleform::GFx::MovieImpl::SetFocusTo(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *ch,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::Sprite *pObject; // rbx
  unsigned __int8 v9; // di
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v12; // [rsp+58h] [rbp+10h]

  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]].LastFocused,
    &result);
  pObject = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    pObject = result.pObject;
  }
  v12 = pObject;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pObject);
  if ( pObject == ch
    || (this->FocusRectChanged = 1, pObject)
    && pObject->pParent
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *, Scaleform::GFx::InteractiveObject *, _QWORD, _QWORD, __int64))pObject->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[92].__vecDelDtor)(
          pObject,
          ch,
          controllerIdx,
          (unsigned int)fmt,
          -2i64) )
  {
    v9 = 0;
  }
  else
  {
    Scaleform::GFx::MovieImpl::TransferFocus(this, ch, controllerIdx, fmt);
    if ( ch )
      ((void (__fastcall *)(Scaleform::GFx::Sprite *, _QWORD, _QWORD))ch->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[91].__vecDelDtor)(
        ch,
        controllerIdx,
        (unsigned int)fmt);
    v9 = 1;
  }
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  return v9;
}

// File Line: 4488
// RVA: 0x9015E0
void __fastcall Scaleform::GFx::MovieImpl::ResetInputFocus(Scaleform::GFx::MovieImpl *this, unsigned int controllerIdx)
{
  Scaleform::GFx::MovieImpl::SetFocusTo(this, 0i64, controllerIdx, GFx_FocusMovedByAS);
}

// File Line: 4495
// RVA: 0x8F5780
__int64 __fastcall Scaleform::GFx::MovieImpl::QueueSetFocusTo(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *ch,
        Scaleform::GFx::InteractiveObject *ptopMostCh,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusKeyInfo)
{
  Scaleform::GFx::Sprite *pObject; // rbx
  Scaleform::GFx::FocusMovedType v10; // esi
  unsigned __int8 v11; // di
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v14; // [rsp+68h] [rbp+10h]

  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]].LastFocused,
    &result);
  pObject = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    pObject = result.pObject;
  }
  v14 = pObject;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pObject);
  if ( pObject == ch )
    goto LABEL_16;
  this->FocusRectChanged = 1;
  v10 = fmt;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::Sprite *, Scaleform::GFx::Sprite *, _QWORD, Scaleform::GFx::FocusMovedType, Scaleform::GFx::ProcessFocusKeyInfo *, __int64))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[22].__vecDelDtor)(
          this->pASMovieRoot.pObject,
          pObject,
          ch,
          controllerIdx,
          fmt,
          pfocusKeyInfo,
          -2i64) )
    goto LABEL_16;
  if ( ch
    && !ch->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[89].__vecDelDtor(
          ch,
          (unsigned int)v10) )
  {
    ch = 0i64;
  }
  if ( pObject
    && pObject->pParent
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *, Scaleform::GFx::InteractiveObject *, _QWORD, _QWORD))pObject->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[92].__vecDelDtor)(
          pObject,
          ch,
          controllerIdx,
          (unsigned int)v10) )
  {
LABEL_16:
    v11 = 0;
  }
  else
  {
    if ( ch )
      ((void (__fastcall *)(Scaleform::GFx::Sprite *, _QWORD, _QWORD))ch->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[91].__vecDelDtor)(
        ch,
        controllerIdx,
        (unsigned int)v10);
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::Sprite *, _QWORD, _QWORD))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[20].__vecDelDtor)(
      this->pASMovieRoot.pObject,
      ch,
      controllerIdx,
      (unsigned int)v10);
    v11 = 1;
  }
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  return v11;
}

// File Line: 4552
// RVA: 0x913190
void __fastcall Scaleform::GFx::MovieImpl::TransferFocus(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::InteractiveObject *pNewFocus,
        unsigned int controllerIdx,
        unsigned int fmt)
{
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p_LastFocused; // rsi
  Scaleform::GFx::InteractiveObject *v9; // rbx
  int AVMVersion; // r14d
  Scaleform::WeakPtrProxy *v11; // rdx
  bool v12; // zf
  Scaleform::WeakPtrProxy *WeakProxy; // rbp
  Scaleform::WeakPtrProxy *v14; // rdx
  Scaleform::WeakPtrProxy *pObject; // rdx
  Scaleform::WeakPtrProxy *v16; // rbp
  Scaleform::WeakPtrProxy *v17; // rdx
  Scaleform::WeakPtrProxy *v18; // rdx
  Scaleform::RefCountNTSImpl *v19; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::InteractiveObject *v20; // [rsp+88h] [rbp+10h]

  p_LastFocused = &this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]].LastFocused;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)p_LastFocused,
    (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&v19);
  v9 = (Scaleform::GFx::InteractiveObject *)v19;
  if ( v19 )
  {
    ++v19->RefCount;
    v9 = (Scaleform::GFx::InteractiveObject *)v19;
  }
  v20 = v9;
  if ( v19 )
    Scaleform::RefCountNTSImpl::Release(v19);
  if ( v9 != pNewFocus )
  {
    this->FocusRectChanged = 1;
    AVMVersion = (unsigned __int8)this->pASMovieRoot.pObject->AVMVersion;
    if ( AVMVersion == 2 )
    {
      if ( !pNewFocus )
      {
        pObject = p_LastFocused->pProxy.pObject;
        if ( p_LastFocused->pProxy.pObject )
        {
          v12 = pObject->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        goto LABEL_20;
      }
      if ( !pNewFocus->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[89].__vecDelDtor(
              pNewFocus,
              fmt) )
      {
        v11 = p_LastFocused->pProxy.pObject;
        if ( p_LastFocused->pProxy.pObject )
        {
          v12 = v11->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        pNewFocus = 0i64;
LABEL_20:
        p_LastFocused->pProxy.pObject = 0i64;
        goto LABEL_21;
      }
      WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pNewFocus);
      v14 = p_LastFocused->pProxy.pObject;
      if ( p_LastFocused->pProxy.pObject )
      {
        v12 = v14->RefCount-- == 1;
        if ( v12 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      p_LastFocused->pProxy.pObject = WeakProxy;
    }
LABEL_21:
    if ( v9 && v9->pParent )
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, _QWORD, Scaleform::GFx::InteractiveObject *, _QWORD, unsigned int))v9->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[90].__vecDelDtor)(
        v9,
        0i64,
        pNewFocus,
        controllerIdx,
        fmt);
    if ( AVMVersion == 1 )
    {
      if ( !pNewFocus )
      {
        v18 = p_LastFocused->pProxy.pObject;
        if ( p_LastFocused->pProxy.pObject )
        {
          v12 = v18->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        p_LastFocused->pProxy.pObject = 0i64;
        goto LABEL_36;
      }
      v16 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pNewFocus);
      v17 = p_LastFocused->pProxy.pObject;
      if ( p_LastFocused->pProxy.pObject )
      {
        v12 = v17->RefCount-- == 1;
        if ( v12 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      p_LastFocused->pProxy.pObject = v16;
    }
    if ( pNewFocus )
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64, Scaleform::GFx::InteractiveObject *, _QWORD, unsigned int))pNewFocus->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[90].__vecDelDtor)(
        pNewFocus,
        1i64,
        v9,
        controllerIdx,
        fmt);
LABEL_36:
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::InteractiveObject *, _QWORD))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[21].__vecDelDtor)(
      this->pASMovieRoot.pObject,
      v9,
      pNewFocus,
      controllerIdx);
  }
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release(v9);
}

// File Line: 4599
// RVA: 0x9084F0
void __fastcall Scaleform::GFx::MovieImpl::SetKeyboardFocusTo(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *ch,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::Sprite *pParent; // rbx
  Scaleform::GFx::FocusGroupDescr *v8; // rdi
  int v9; // ebp
  bool v10; // zf

  pParent = ch;
  v8 = &this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]];
  if ( ch
    && ((unsigned int (__fastcall *)(Scaleform::GFx::Sprite *))ch->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(ch) == 4 )
  {
    if ( v8->FocusRectShown )
      this->FocusRectChanged = 1;
    v8->FocusRectShown = 0;
  }
  else
  {
    if ( !v8->FocusRectShown )
      this->FocusRectChanged = 1;
    v8->FocusRectShown = 1;
  }
  v9 = 0;
  v8->LastFocusKeyCode = 0;
  if ( (unsigned __int8)Scaleform::GFx::MovieImpl::SetFocusTo(this, pParent, controllerIdx, fmt) && v8->FocusRectShown )
  {
    v10 = pParent == 0i64;
    if ( pParent )
    {
      do
      {
        if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *))pParent->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(pParent) )
          break;
        pParent = (Scaleform::GFx::Sprite *)pParent->pParent;
      }
      while ( pParent );
      v10 = pParent == 0i64;
    }
    LOBYTE(v9) = v10;
    if ( v8->FocusRectShown != v9 )
      this->FocusRectChanged = 1;
    v8->FocusRectShown = pParent == 0i64;
  }
}

// File Line: 4647
// RVA: 0x901310
void __fastcall Scaleform::GFx::MovieImpl::ResetFocusForChar(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *ch)
{
  __int64 i; // rbp
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *v5; // r12
  Scaleform::GFx::Sprite *pObject; // rbx
  Scaleform::GFx::Sprite *v7; // rbx
  unsigned int v8; // edi
  int v9; // eax
  char *v10; // rdx
  __int64 v11; // r8
  int v12; // eax
  int v13; // eax
  int v14; // eax
  unsigned int v15; // r14d
  unsigned int j; // esi
  Scaleform::WeakPtrProxy *v17; // rdx
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::Ptr<Scaleform::GFx::Sprite> v20; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::GFx::Sprite *v21; // [rsp+88h] [rbp+20h]

  for ( i = 0i64; (unsigned int)i < this->FocusGroupsCnt; i = (unsigned int)(i + 1) )
  {
    v5 = (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)((char *)this + 96 * i);
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      v5 + 2457,
      &result);
    pObject = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      pObject = result.pObject;
    }
    v21 = pObject;
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release(result.pObject);
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    if ( pObject == ch )
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        v5 + 2457,
        &v20);
      v7 = v20.pObject;
      if ( v20.pObject )
      {
        ++v20.pObject->RefCount;
        v7 = v20.pObject;
      }
      if ( v20.pObject )
        Scaleform::RefCountNTSImpl::Release(v20.pObject);
      if ( v7 && !Scaleform::GFx::MovieImpl::IsShutdowning(this) )
      {
        v8 = 0;
        v9 = 1;
        v10 = &this->FocusGroupIndexes[1];
        v11 = 4i64;
        do
        {
          if ( (unsigned __int8)*(v10 - 1) == (_DWORD)i )
            v8 |= v9;
          v12 = 2 * v9;
          if ( (unsigned __int8)*v10 == (_DWORD)i )
            v8 |= v12;
          v13 = 2 * v12;
          if ( (unsigned __int8)v10[1] == (_DWORD)i )
            v8 |= v13;
          v14 = 2 * v13;
          if ( (unsigned __int8)v10[2] == (_DWORD)i )
            v8 |= v14;
          v9 = 2 * v14;
          v10 += 4;
          --v11;
        }
        while ( v11 );
        v15 = (unsigned int)this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[46].__vecDelDtor(
                              this,
                              v10);
        for ( j = 0; v8; v8 >>= 1 )
        {
          if ( j >= v15 )
            break;
          Scaleform::GFx::MovieImpl::SetFocusTo(this, 0i64, j++, GFx_FocusMovedByKeyboard);
        }
      }
      v17 = v5[2457].pProxy.pObject;
      if ( v17 )
      {
        if ( v17->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      v5[2457].pProxy.pObject = 0i64;
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
    }
  }
}

// File Line: 4667
// RVA: 0x8E7280
char __fastcall Scaleform::GFx::MovieImpl::IsFocused(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::Sprite *ch)
{
  __int64 v4; // rdi
  Scaleform::GFx::Sprite *pObject; // rbx
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v8; // [rsp+60h] [rbp+18h]

  v4 = 0i64;
  if ( !this->FocusGroupsCnt )
    return 0;
  while ( 1 )
  {
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[v4].LastFocused,
      &result);
    pObject = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      pObject = result.pObject;
    }
    v8 = pObject;
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release(result.pObject);
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    if ( pObject == ch )
      break;
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= this->FocusGroupsCnt )
      return 0;
  }
  return 1;
}

// File Line: 4678
// RVA: 0x8B3D90
void __fastcall Scaleform::GFx::MovieImpl::AddTopmostLevelCharacter(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::InteractiveObject *pch)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v5; // rax
  unsigned __int64 v6; // rsi
  void *v7; // rax
  void *v8; // rax
  Scaleform::GFx::InteractiveObject *pParent; // rdi
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v12; // rcx
  Scaleform::GFx::InteractiveObject *v13; // r14
  unsigned __int64 Size; // r13
  unsigned __int64 v15; // r8
  Scaleform::GFx::InteractiveObject *v16; // rcx
  Scaleform::GFx::InteractiveObject *i; // rdi
  unsigned __int64 v18; // rbx
  unsigned __int64 v19; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v20; // rcx
  __int64 v21; // r9
  unsigned __int64 v22; // rdx
  char *v23; // rcx
  __int64 v24; // rax
  int v25; // ebx
  char *v26; // rcx
  __int64 v27; // rax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *p_TopmostLevelCharacters; // rdi
  unsigned __int64 v29; // r14
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v30; // rcx
  __int64 v31; // rbx
  unsigned __int64 v32; // r8
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v33; // rcx
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v36; // [rsp+30h] [rbp-40h] BYREF
  void *v37; // [rsp+48h] [rbp-28h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v38; // [rsp+50h] [rbp-20h] BYREF
  void *pheapAddr; // [rsp+68h] [rbp-8h]
  Scaleform::Ptr<Scaleform::Render::TreeNode> result; // [rsp+B8h] [rbp+48h] BYREF
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v41; // [rsp+C0h] [rbp+50h]
  Scaleform::GFx::InteractiveObject *v42; // [rsp+C8h] [rbp+58h]

  if ( (pch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
  {
    AvmObjOffset = pch->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v5 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&pch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                    + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)pch + 4 * AvmObjOffset);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 248i64))(v5) )
        return;
    }
  }
  v6 = 0i64;
  if ( !this->TopmostLevelCharacters.Data.Size )
    goto LABEL_47;
  v7 = (void *)((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[48].__vecDelDtor)(this);
  v41 = &v38;
  memset(&v38, 0, sizeof(v38));
  pheapAddr = v7;
  v8 = (void *)((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[48].__vecDelDtor)(this);
  v41 = &v36;
  memset(&v36, 0, sizeof(v36));
  v37 = v8;
  pParent = pch;
  do
  {
    v10 = v38.Size + 1;
    if ( v38.Size + 1 >= v38.Size )
    {
      if ( v10 <= v38.Policy.Capacity )
        goto LABEL_12;
      v11 = v10 + (v10 >> 2);
    }
    else
    {
      if ( v10 >= v38.Policy.Capacity >> 1 )
        goto LABEL_12;
      v11 = v38.Size + 1;
    }
    Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v38,
      pheapAddr,
      v11);
LABEL_12:
    v38.Size = v10;
    v12 = &v38.Data[v10 - 1];
    if ( v12 )
      v12->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)pParent;
    v13 = pParent;
    pParent = pParent->pParent;
  }
  while ( pParent );
  Size = this->TopmostLevelCharacters.Data.Size;
  if ( !Size )
  {
LABEL_46:
    v41 = &v36;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v36.Data);
    v41 = &v38;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v38.Data);
LABEL_47:
    ++pch->RefCount;
    v42 = pch;
    p_TopmostLevelCharacters = &this->TopmostLevelCharacters;
    v29 = this->TopmostLevelCharacters.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&this->TopmostLevelCharacters,
      &this->TopmostLevelCharacters,
      v29 + 1);
    if ( v29 + 1 > v29 )
    {
      v30 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&p_TopmostLevelCharacters->Data.Data[v29];
      v41 = v30;
      v31 = 1i64;
      do
      {
        if ( v30 )
          v30->Data = 0i64;
        v30 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)((char *)v30 + 8);
        v41 = v30;
        --v31;
      }
      while ( v31 );
    }
    v32 = this->TopmostLevelCharacters.Data.Size;
    if ( v6 < v32 - 1 )
      memmove(
        &p_TopmostLevelCharacters->Data.Data[v6 + 1],
        &p_TopmostLevelCharacters->Data.Data[v6],
        8 * (v32 - v6) - 8);
    v33 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&p_TopmostLevelCharacters->Data.Data[v6];
    v41 = v33;
    if ( v33 )
    {
      ++pch->RefCount;
      v33->Data = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)pch;
    }
    Scaleform::RefCountNTSImpl::Release(pch);
    Scaleform::GFx::DisplayObjectBase::SetIndirectTransform(pch, &result, this->pTopMostRoot.pObject);
    if ( result.pObject )
      Scaleform::Render::TreeContainer::Insert(this->pTopMostRoot.pObject, v6, result.pObject);
    pObject = result.pObject;
    if ( result.pObject )
    {
      if ( result.pObject->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
    }
    return;
  }
  v15 = v36.Size;
  while ( this->TopmostLevelCharacters.Data.Data[v6].pObject != pch )
  {
    if ( v15 && (v36.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( v36.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v36.Data = 0i64;
      }
      v36.Policy.Capacity = 0i64;
    }
    v15 = 0i64;
    v36.Size = 0i64;
    v16 = 0i64;
    for ( i = this->TopmostLevelCharacters.Data.Data[v6].pObject; i; i = i->pParent )
    {
      v18 = v15 + 1;
      if ( v15 + 1 >= v15 )
      {
        if ( v18 > v36.Policy.Capacity )
        {
          v19 = v18 + (v18 >> 2);
          goto LABEL_29;
        }
      }
      else if ( v18 < v36.Policy.Capacity >> 1 )
      {
        v19 = v15 + 1;
LABEL_29:
        Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v36,
          v37,
          v19);
      }
      v15 = v18;
      v36.Size = v18;
      v20 = &v36.Data[v18 - 1];
      if ( v20 )
      {
        v20->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)i;
        v15 = v36.Size;
      }
      v16 = i;
    }
    if ( v16 == v13 )
    {
      v21 = v15 - 1;
      v22 = v38.Size - 1;
      if ( (signed __int64)(v38.Size - 1) >= 0 )
      {
        while ( v21 >= 0 )
        {
          if ( v38.Data[v22].pObject != v36.Data[v21].pObject )
          {
            if ( SHIDWORD(v38.Data[v22].pObject->pTraits.pObject) < SHIDWORD(v36.Data[v21].pObject->pTraits.pObject) )
              goto LABEL_46;
            break;
          }
          --v21;
          if ( (--v22 & 0x8000000000000000ui64) != 0i64 )
            break;
        }
      }
    }
    else
    {
      v23 = (char *)v16 + 4 * (unsigned __int8)v16->AvmObjOffset;
      v24 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v23 + 16i64))(v23);
      v25 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v24 + 240i64))(v24);
      v26 = (char *)v13 + 4 * (unsigned __int8)v13->AvmObjOffset;
      v27 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v26 + 16i64))(v26);
      if ( v25 > (*(int (__fastcall **)(__int64))(*(_QWORD *)v27 + 240i64))(v27) )
        goto LABEL_46;
      v15 = v36.Size;
    }
    if ( ++v6 >= Size )
      goto LABEL_46;
  }
  v41 = &v36;
  ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
    Scaleform::Memory::pGlobalHeap,
    v36.Data,
    v15);
  v41 = &v38;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v38.Data);
}

// File Line: 4765
// RVA: 0x8FFD80
void __fastcall Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::InteractiveObject *pch)
{
  unsigned __int64 Size; // r8
  unsigned __int64 v3; // rbx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *p_TopmostLevelCharacters; // rdi
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *i; // rax
  Scaleform::RefCountNTSImpl *pObject; // rcx

  Size = this->TopmostLevelCharacters.Data.Size;
  v3 = 0i64;
  if ( Size )
  {
    p_TopmostLevelCharacters = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&this->TopmostLevelCharacters;
    for ( i = this->TopmostLevelCharacters.Data.Data; i->pObject != pch; ++i )
    {
      if ( ++v3 >= Size )
        return;
    }
    Scaleform::Render::TreeContainer::Remove(this->pTopMostRoot.pObject, v3, 1ui64);
    Scaleform::GFx::DisplayObjectBase::RemoveIndirectTransform(pch, 1);
    if ( p_TopmostLevelCharacters->Size == 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        p_TopmostLevelCharacters,
        p_TopmostLevelCharacters,
        0i64);
    }
    else
    {
      pObject = p_TopmostLevelCharacters->Data[v3].pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      memmove(
        &p_TopmostLevelCharacters->Data[v3],
        &p_TopmostLevelCharacters->Data[v3 + 1],
        8 * (p_TopmostLevelCharacters->Size - v3) - 8);
      --p_TopmostLevelCharacters->Size;
    }
  }
}

// File Line: 4805
// RVA: 0x8D6C70
bool __fastcall Scaleform::GFx::MovieImpl::GetDirtyFlag(Scaleform::GFx::MovieImpl *this, bool doReset)
{
  bool result; // al

  if ( (this->Flags & 0x400) != 0
    || (result = Scaleform::Render::ContextImpl::Context::HasChanges(&this->RenderContext)) )
  {
    result = 1;
  }
  if ( doReset )
    this->Flags &= ~0x400u;
  return result;
}

// File Line: 4813
// RVA: 0x8DE9B0
Scaleform::Render::Text::Allocator *__fastcall Scaleform::GFx::MovieImpl::GetTextAllocator(
        Scaleform::GFx::MovieImpl *this)
{
  return (Scaleform::Render::Text::Allocator *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[60].__vecDelDtor)(this->pASMovieRoot.pObject);
}

// File Line: 4818
// RVA: 0x8D4A60
unsigned __int64 __fastcall Scaleform::GFx::MovieImpl::GetASTimerMs(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::TestStream *pObject; // rdi
  unsigned __int64 v3; // rbx
  unsigned __int64 result; // rax
  unsigned __int64 v5; // rbx
  Scaleform::LongFormatter v6; // [rsp+30h] [rbp-68h] BYREF
  Scaleform::String v7; // [rsp+A0h] [rbp+8h] BYREF
  Scaleform::Render::RenderBuffer *v8; // [rsp+A8h] [rbp+10h] BYREF

  pObject = Scaleform::GFx::StateBag::GetTestStream(
              &this->Scaleform::GFx::StateBag,
              (Scaleform::Ptr<Scaleform::GFx::TestStream> *)&v8)->pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  if ( !pObject )
    return Scaleform::Timer::GetTicks() / 0x3E8 - this->StartTickMs;
  if ( pObject->TestStatus )
  {
    Scaleform::String::String(&v7);
    ((void (__fastcall *)(Scaleform::GFx::TestStream *, const char *, Scaleform::String *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
      "timer",
      &v7);
    result = strtoui64((const char *)((v7.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), 0i64, 10);
    v5 = result;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v7.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      return v5;
    }
  }
  else
  {
    v3 = Scaleform::Timer::GetTicks() / 0x3E8 - this->StartTickMs;
    Scaleform::LongFormatter::LongFormatter(&v6, v3);
    Scaleform::LongFormatter::Convert(&v6);
    ((void (__fastcall *)(Scaleform::GFx::TestStream *, const char *, char *))pObject->vfptr[2].__vecDelDtor)(
      pObject,
      "timer",
      v6.ValueStr);
    v6.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
    Scaleform::Formatter::~Formatter(&v6);
    return v3;
  }
  return result;
}

// File Line: 4844
// RVA: 0x914180
Scaleform::Render::Point<float> *__fastcall Scaleform::GFx::MovieImpl::TranslateToScreen(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Point<float> *result,
        Scaleform::Render::Point<float> *p,
        Scaleform::Render::Matrix2x4<float> *puserMatrix)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // rdi
  Scaleform::GFx::DisplayObjectBase *pParent; // rcx
  float *v10; // rax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm10_4
  float v15; // xmm4_4
  float v16; // xmm11_4
  float v17; // xmm9_4
  float v18; // xmm10_4
  float v19; // xmm12_4
  float v20; // xmm13_4
  float *v21; // rax
  float v22; // xmm2_4
  float v23; // xmm14_4
  float v24; // xmm7_4
  float v25; // xmm3_4
  float v26; // xmm15_4
  float v27; // xmm8_4
  float v28; // xmm5_4
  float v29; // xmm0_4
  float v30; // xmm4_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm4_4
  float v35; // xmm0_4
  float v36; // xmm14_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  Scaleform::Render::Point<float> *v39; // rax
  float v40; // xmm5_4
  float v41; // xmm4_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // [rsp+20h] [rbp-F8h]
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-E8h] BYREF
  float v47; // [rsp+120h] [rbp+8h]
  float v48; // [rsp+130h] [rbp+18h]

  pMainMovie = this->pMainMovie;
  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  pParent = pMainMovie->pParent;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, &pmat);
    v10 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pMainMovie);
    v11 = pmat.M[0][0];
    v12 = pmat.M[0][1];
    v13 = pmat.M[1][0];
    v14 = pmat.M[0][0];
    v15 = pmat.M[1][1];
    v16 = (float)(pmat.M[0][1] * v10[4]) + (float)(pmat.M[0][0] * *v10);
    pmat.M[0][0] = v16;
    v17 = (float)(pmat.M[1][1] * v10[4]) + (float)(pmat.M[1][0] * *v10);
    pmat.M[1][0] = v17;
    v18 = (float)(v14 * v10[1]) + (float)(pmat.M[0][1] * v10[5]);
    *(_QWORD *)&pmat.M[0][1] = LODWORD(v18);
    v19 = (float)(v13 * v10[1]) + (float)(pmat.M[1][1] * v10[5]);
    *(_QWORD *)&pmat.M[1][1] = LODWORD(v19);
    v20 = pmat.M[0][3] + (float)((float)(v12 * v10[7]) + (float)(v11 * v10[3]));
    pmat.M[0][3] = v20;
    v47 = pmat.M[1][3] + (float)((float)(v15 * v10[7]) + (float)(v13 * v10[3]));
  }
  else
  {
    v21 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pMainMovie);
    v16 = *v21;
    pmat.M[0][0] = *v21;
    v18 = v21[1];
    *(_QWORD *)&pmat.M[0][1] = *(_QWORD *)(v21 + 1);
    v20 = v21[3];
    pmat.M[0][3] = v20;
    v17 = v21[4];
    pmat.M[1][0] = v17;
    v19 = v21[5];
    *(_QWORD *)&pmat.M[1][1] = *(_QWORD *)(v21 + 5);
    v47 = v21[7];
  }
  v22 = this->ViewportMatrix.M[0][0];
  v23 = this->ViewportMatrix.M[0][1];
  v24 = this->ViewportMatrix.M[0][3];
  v25 = this->ViewportMatrix.M[1][0];
  v26 = this->ViewportMatrix.M[1][1];
  v27 = this->ViewportMatrix.M[1][3];
  if ( puserMatrix )
  {
    v28 = this->ViewportMatrix.M[0][0];
    v29 = puserMatrix->M[1][0];
    v30 = (float)(puserMatrix->M[0][0] * v22) + (float)(v29 * v23);
    v31 = puserMatrix->M[0][1];
    v32 = v31 * v25;
    v48 = v30;
    v45 = (float)(puserMatrix->M[0][0] * v25) + (float)(v29 * v26);
    v33 = puserMatrix->M[1][1];
    v34 = v33 * v26;
    v35 = v33 * v23;
    v36 = v31 * v28;
    v37 = puserMatrix->M[0][3];
    v26 = v32 + v34;
    v23 = v36 + v35;
    v38 = puserMatrix->M[1][3];
    v22 = v48;
    v27 = this->ViewportMatrix.M[1][3]
        + (float)((float)(v37 * this->ViewportMatrix.M[1][0]) + (float)(v38 * this->ViewportMatrix.M[1][1]));
    v25 = v45;
    v24 = this->ViewportMatrix.M[0][3] + (float)((float)(v37 * v28) + (float)(v38 * this->ViewportMatrix.M[0][1]));
  }
  v39 = result;
  v40 = (float)(v17 * v23) + (float)(v16 * v22);
  v41 = (float)(v18 * v22) + (float)(v19 * v23);
  v42 = v20 * v22;
  v43 = p->y * 20.0;
  v44 = p->x * 20.0;
  result->y = (float)((float)(v44 * (float)((float)(v17 * v26) + (float)(v16 * v25)))
                    + (float)(v43 * (float)((float)(v18 * v25) + (float)(v19 * v26))))
            + (float)(v27 + (float)((float)(v20 * v25) + (float)(v47 * v26)));
  result->x = (float)((float)(v44 * v40) + (float)(v43 * v41)) + (float)(v24 + (float)((float)(v47 * v23) + v42));
  return v39;
}

// File Line: 4855
// RVA: 0x914590
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::MovieImpl::TranslateToScreen(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Rect<float> *r,
        Scaleform::Render::Matrix2x4<float> *puserMatrix)
{
  __int128 v4; // xmm6
  Scaleform::GFx::InteractiveObject *pMainMovie; // rdi
  Scaleform::GFx::DisplayObjectBase *pParent; // rcx
  float *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm12_4
  float v17; // xmm13_4
  float v18; // xmm14_4
  float v19; // xmm0_4
  float v20; // xmm15_4
  float v21; // xmm15_4
  float v22; // xmm0_4
  float *v23; // rax
  float v24; // xmm10_4
  float v25; // xmm8_4
  float v26; // xmm3_4
  float v27; // xmm11_4
  float v28; // xmm9_4
  float v29; // xmm4_4
  float v30; // xmm7_4
  float v31; // xmm5_4
  float v32; // xmm1_4
  float v33; // xmm5_4
  float x2; // xmm1_4
  float x1; // xmm0_4
  float y1; // xmm0_4
  float y2; // xmm0_4
  Scaleform::Render::Rect<float> ra; // [rsp+20h] [rbp-C8h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::Render::Matrix2x4<float> v41; // [rsp+50h] [rbp-98h] BYREF
  __int128 v42; // [rsp+100h] [rbp+18h]

  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  pMainMovie = this->pMainMovie;
  pParent = pMainMovie->pParent;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, &pmat);
    v11 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pMainMovie);
    v12 = pmat.M[0][0];
    v13 = pmat.M[0][1];
    v14 = pmat.M[1][0];
    v15 = pmat.M[1][1];
    v16 = (float)(pmat.M[0][0] * *v11) + (float)(pmat.M[0][1] * v11[4]);
    pmat.M[0][0] = v16;
    v17 = (float)(pmat.M[1][1] * v11[4]) + (float)(pmat.M[1][0] * *v11);
    pmat.M[1][0] = v17;
    v18 = (float)(pmat.M[0][1] * v11[5]) + (float)(v12 * v11[1]);
    pmat.M[0][1] = v18;
    v19 = pmat.M[1][1] * v11[5];
    v20 = v14 * v11[1];
    pmat.M[0][2] = 0.0;
    v21 = v20 + v19;
    *(_QWORD *)&pmat.M[1][1] = LODWORD(v21);
    pmat.M[0][3] = pmat.M[0][3] + (float)((float)(v13 * v11[7]) + (float)(v12 * v11[3]));
    v22 = pmat.M[1][3] + (float)((float)(v15 * v11[7]) + (float)(v14 * v11[3]));
  }
  else
  {
    v23 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pMainMovie);
    v16 = *v23;
    pmat.M[0][0] = *v23;
    v18 = v23[1];
    *(_QWORD *)&pmat.M[0][1] = *(_QWORD *)(v23 + 1);
    pmat.M[0][3] = v23[3];
    v17 = v23[4];
    pmat.M[1][0] = v17;
    v21 = v23[5];
    *(_QWORD *)&pmat.M[1][1] = *(_QWORD *)(v23 + 5);
    v22 = v23[7];
  }
  v24 = this->ViewportMatrix.M[0][0];
  v25 = this->ViewportMatrix.M[0][1];
  v26 = this->ViewportMatrix.M[0][3];
  v27 = this->ViewportMatrix.M[1][0];
  v28 = this->ViewportMatrix.M[1][1];
  v29 = this->ViewportMatrix.M[1][3];
  pmat.M[1][3] = v22;
  if ( puserMatrix )
  {
    v42 = v4;
    v30 = v27;
    v31 = v24;
    v32 = v24;
    v24 = (float)(v24 * puserMatrix->M[0][0]) + (float)(v25 * puserMatrix->M[1][0]);
    v27 = (float)(v27 * puserMatrix->M[0][0]) + (float)(v28 * puserMatrix->M[1][0]);
    v33 = (float)(v31 * puserMatrix->M[0][3]) + (float)(v25 * puserMatrix->M[1][3]);
    v25 = (float)(v32 * puserMatrix->M[0][1]) + (float)(v25 * puserMatrix->M[1][1]);
    v29 = this->ViewportMatrix.M[1][3]
        + (float)((float)(v30 * puserMatrix->M[0][3]) + (float)(v28 * puserMatrix->M[1][3]));
    v26 = v26 + v33;
    v28 = (float)(v30 * puserMatrix->M[0][1]) + (float)(v28 * puserMatrix->M[1][1]);
  }
  v41.M[0][0] = (float)(v25 * v17) + (float)(v24 * v16);
  v41.M[1][0] = (float)(v28 * v17) + (float)(v27 * v16);
  *(_QWORD *)&v41.M[0][1] = COERCE_UNSIGNED_INT((float)(v25 * v21) + (float)(v24 * v18));
  x2 = r->x2;
  x1 = r->x1;
  *(_QWORD *)&v41.M[1][1] = COERCE_UNSIGNED_INT((float)(v28 * v21) + (float)(v27 * v18));
  ra.x1 = x1 * 20.0;
  y1 = r->y1;
  v41.M[0][3] = v26 + (float)((float)(v25 * pmat.M[1][3]) + (float)(v24 * pmat.M[0][3]));
  ra.y1 = y1 * 20.0;
  y2 = r->y2;
  v41.M[1][3] = v29 + (float)((float)(v28 * pmat.M[1][3]) + (float)(v27 * pmat.M[0][3]));
  ra.y2 = y2 * 20.0;
  ra.x2 = x2 * 20.0;
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v41, result, &ra);
  return result;
}

// File Line: 4872
// RVA: 0x913DA0
__int64 __fastcall Scaleform::GFx::MovieImpl::TranslateLocalToScreen(
        Scaleform::GFx::MovieImpl *this,
        const char *pathToMovieClip,
        Scaleform::Render::Point<float> *pt,
        Scaleform::Render::Point<float> *presPt,
        Scaleform::Render::Matrix2x4<float> *userMatrix)
{
  float v8; // xmm8_4
  float v9; // xmm10_4
  float v10; // xmm12_4
  float v11; // xmm9_4
  float v12; // xmm11_4
  float v13; // xmm13_4
  float v14; // xmm5_4
  float v15; // xmm7_4
  float v16; // xmm5_4
  unsigned __int8 v17; // bl
  __int128 v19; // [rsp+30h] [rbp-D8h] BYREF
  __m128 v20; // [rsp+40h] [rbp-C8h]
  char v21[16]; // [rsp+50h] [rbp-B8h] BYREF
  __int64 v22; // [rsp+60h] [rbp-A8h]
  int v23; // [rsp+68h] [rbp-A0h]
  __int64 v24; // [rsp+70h] [rbp-98h]

  v22 = 0i64;
  v23 = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, char *, const char *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[49].__vecDelDtor)(
         this->pASMovieRoot.pObject,
         v21,
         pathToMovieClip)
    && (v19 = _xmm,
        v20 = _xmm,
        (*(unsigned __int8 (__fastcall **)(__int64, __int64, __int128 *))(*(_QWORD *)v22 + 232i64))(v22, v24, &v19)) )
  {
    v8 = this->ViewportMatrix.M[0][0] * 20.0;
    v9 = this->ViewportMatrix.M[0][1] * 20.0;
    v10 = this->ViewportMatrix.M[0][3] * 20.0;
    v11 = this->ViewportMatrix.M[1][0] * 20.0;
    v12 = this->ViewportMatrix.M[1][1] * 20.0;
    v13 = this->ViewportMatrix.M[1][3] * 20.0;
    if ( userMatrix )
    {
      v14 = this->ViewportMatrix.M[0][0] * 20.0;
      v15 = this->ViewportMatrix.M[1][0] * 20.0;
      v8 = (float)(v8 * userMatrix->M[0][0]) + (float)(v9 * userMatrix->M[1][0]);
      v11 = (float)(v11 * userMatrix->M[0][0]) + (float)(v12 * userMatrix->M[1][0]);
      v9 = (float)(v14 * userMatrix->M[0][1]) + (float)(v9 * userMatrix->M[1][1]);
      v12 = (float)(v15 * userMatrix->M[0][1]) + (float)(v12 * userMatrix->M[1][1]);
      v10 = v10
          + (float)((float)(v14 * userMatrix->M[0][3])
                  + (float)((float)(this->ViewportMatrix.M[0][1] * 20.0) * userMatrix->M[1][3]));
      v13 = v13
          + (float)((float)(v15 * userMatrix->M[0][3])
                  + (float)((float)(this->ViewportMatrix.M[1][1] * 20.0) * userMatrix->M[1][3]));
    }
    v16 = (float)((float)((float)((float)(v11 * *(float *)&v19) + (float)(v12 * v20.m128_f32[0])) * pt->x)
                + (float)((float)((float)(v11 * *((float *)&v19 + 1)) + (float)(v12 * v20.m128_f32[1])) * pt->y))
        + (float)(v13 + (float)((float)(v11 * *((float *)&v19 + 3)) + (float)(v12 * v20.m128_f32[3])));
    presPt->x = (float)((float)((float)((float)(v8 * *(float *)&v19) + (float)(v9 * v20.m128_f32[0])) * pt->x)
                      + (float)((float)((float)(v8 * *((float *)&v19 + 1)) + (float)(v9 * v20.m128_f32[1])) * pt->y))
              + (float)(v10 + (float)((float)(v8 * *((float *)&v19 + 3)) + (float)(v9 * v20.m128_f32[3])));
    presPt->y = v16;
    v17 = 1;
  }
  else
  {
    v17 = 0;
  }
  if ( (v23 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v22 + 16i64))(v22, v21, v24);
    v22 = 0i64;
  }
  return v17;
}

// File Line: 4899
// RVA: 0x8DE5D0
void __fastcall Scaleform::GFx::MovieImpl::GetStats(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::StatBag *pbag,
        __int64 reset)
{
  Scaleform::AmpStats *pObject; // rcx

  pObject = this->AdvanceStats.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::AmpStats *, Scaleform::StatBag *, __int64))pObject->vfptr[5].__vecDelDtor)(
      pObject,
      pbag,
      reset);
}

// File Line: 4926
// RVA: 0x8F0CD0
void __fastcall Scaleform::GFx::MovieImpl::PrintObjectsReport(
        Scaleform::GFx::MovieImpl *this,
        __int64 flags,
        Scaleform::Log *log,
        const char *swfName,
        Scaleform::Ptr<Scaleform::AmpMovieObjectDesc> *root,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::AmpMovieObjectDesc *v7; // rdi

  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, __int64, Scaleform::Log *, const char *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[32].__vecDelDtor)(
    this->pASMovieRoot.pObject,
    flags,
    log,
    swfName);
  if ( root )
  {
    v7 = (Scaleform::AmpMovieObjectDesc *)this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[34].__vecDelDtor(
                                            this->pASMovieRoot.pObject,
                                            heap);
    if ( root->pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)root->pObject);
    root->pObject = v7;
  }
}

// File Line: 4936
// RVA: 0x908630
char __fastcall Scaleform::GFx::MovieImpl::SetLevelMovie(
        Scaleform::GFx::MovieImpl *this,
        int level,
        Scaleform::GFx::DisplayObjContainer *psprite)
{
  unsigned int v6; // ecx
  unsigned __int64 Size; // rdx
  __int64 v8; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // r13
  Scaleform::GFx::MovieImpl::LevelInfo *v13; // rax
  __int64 v14; // rbx
  unsigned __int64 v15; // r8
  Scaleform::GFx::MovieImpl::LevelInfo *v16; // rdi
  __int64 v17; // rax
  Scaleform::GFx::MovieDefImpl *v18; // rdi
  Scaleform::GFx::MovieDefImpl *pObject; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::AmpStats *v21; // rsi
  Scaleform::RefCountImplCoreVtbl *vfptr; // rbx
  __int64 v23; // rax
  Scaleform::GFx::MovieDefImpl *v24; // rax
  Scaleform::GFx::StateBagImpl *v25; // rbx
  Scaleform::GFx::StateBagImpl *v26; // rdi
  Scaleform::Render::RenderBuffer *v27; // rcx
  __int64 v28; // rax
  __int64 v29; // rsi
  int v30; // ebp
  int v31; // edi
  int v32; // ebx
  int v33[2]; // [rsp+38h] [rbp-70h] BYREF
  __int64 v34; // [rsp+40h] [rbp-68h]
  int v35; // [rsp+48h] [rbp-60h]
  int v36; // [rsp+4Ch] [rbp-5Ch]
  int v37; // [rsp+50h] [rbp-58h]
  __int64 v38; // [rsp+54h] [rbp-54h]
  __int64 v39; // [rsp+5Ch] [rbp-4Ch]
  int v40; // [rsp+64h] [rbp-44h]
  int v41; // [rsp+68h] [rbp-40h]

  v6 = 0;
  Size = this->MovieLevels.Data.Size;
  if ( Size )
  {
    v8 = 0i64;
    Data = this->MovieLevels.Data.Data;
    while ( Data[v8].Level < level )
    {
      v8 = ++v6;
      if ( v6 >= Size )
        goto LABEL_8;
    }
    if ( Data[v6].Level == level )
      return 0;
  }
LABEL_8:
  this->Flags |= 0x100u;
  if ( psprite )
    ++psprite->RefCount;
  v11 = v6;
  v12 = this->MovieLevels.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->MovieLevels.Data,
    &this->MovieLevels,
    v12 + 1);
  if ( v12 + 1 > v12 )
  {
    v13 = &this->MovieLevels.Data.Data[v12];
    v14 = 1i64;
    do
    {
      if ( v13 )
        v13->pSprite.pObject = 0i64;
      ++v13;
      --v14;
    }
    while ( v14 );
  }
  v15 = this->MovieLevels.Data.Size;
  if ( v11 < v15 - 1 )
    memmove(&this->MovieLevels.Data.Data[v11 + 1], &this->MovieLevels.Data.Data[v11], 16 * (v15 - v11 - 1));
  v16 = &this->MovieLevels.Data.Data[v11];
  if ( v16 )
  {
    v16->Level = level;
    if ( psprite )
      ++psprite->RefCount;
    v16->pSprite.pObject = psprite;
  }
  psprite->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[122].__vecDelDtor(
    psprite,
    level);
  if ( !level )
  {
    this->pMainMovie = psprite;
    v17 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))psprite->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(psprite);
    v18 = (Scaleform::GFx::MovieDefImpl *)v17;
    if ( v17 )
      _InterlockedExchangeAdd((volatile signed __int32 *)(v17 + 8), 1u);
    pObject = this->pMainMovieDef.pObject;
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount.Value) )
    {
      pLib = pObject->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pObject);
        pObject->pLib = 0i64;
      }
      pObject->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(pObject, 1u);
    }
    this->pMainMovieDef.pObject = v18;
    if ( v18 )
    {
      v21 = this->AdvanceStats.pObject;
      if ( v21 )
      {
        vfptr = v21->vfptr;
        v23 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v18->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[3].__vecDelDtor)(v18);
        vfptr[7].__vecDelDtor(v21, v23);
      }
    }
    v24 = this->pMainMovieDef.pObject;
    v25 = v24->pStateBag.pObject;
    v26 = this->pStateBag.pObject;
    if ( v25 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v24->pStateBag.pObject);
    v27 = (Scaleform::Render::RenderBuffer *)v26->pDelegate.pObject;
    if ( v27 )
      Scaleform::RefCountImpl::Release(v27);
    v26->pDelegate.pObject = v25;
    v28 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(this);
    this->FrameTime = 1.0 / (*(float (__fastcall **)(__int64))(*(_QWORD *)v28 + 72i64))(v28);
    if ( (this->Flags & 1) == 0 )
    {
      v29 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))psprite->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(psprite);
      v30 = (int)(*(float (__fastcall **)(__int64))(*(_QWORD *)v29 + 56i64))(v29);
      v31 = (int)(*(float (__fastcall **)(__int64))(*(_QWORD *)v29 + 48i64))(v29);
      v32 = (int)(*(float (__fastcall **)(__int64))(*(_QWORD *)v29 + 56i64))(v29);
      v33[0] = (int)(*(float (__fastcall **)(__int64))(*(_QWORD *)v29 + 48i64))(v29);
      v33[1] = v32;
      v34 = 0i64;
      v35 = v31;
      v36 = v30;
      v39 = 0i64;
      v38 = 0i64;
      v37 = 0;
      v41 = 1065353216;
      v40 = 1065353216;
      this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[12].__vecDelDtor(
        this,
        (unsigned int)v33);
    }
  }
  this->Flags |= 0x80u;
  Scaleform::RefCountNTSImpl::Release(psprite);
  return 1;
}

// File Line: 4990
// RVA: 0x8C2750
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::MovieImpl::CreateNewInstanceName(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringManager *v4; // rax
  char pstr; // [rsp+28h] [rbp-460h] BYREF
  __int64 v7; // [rsp+29h] [rbp-45Fh]
  __int64 v8; // [rsp+31h] [rbp-457h]
  __int64 v9; // [rsp+39h] [rbp-44Fh]
  __int64 v10; // [rsp+41h] [rbp-447h]
  __int64 v11; // [rsp+49h] [rbp-43Fh]
  int v12; // [rsp+51h] [rbp-437h]
  __int16 v13; // [rsp+55h] [rbp-433h]
  char v14; // [rsp+57h] [rbp-431h]
  Scaleform::MsgFormat::Sink r; // [rsp+58h] [rbp-430h] BYREF
  __int64 v16; // [rsp+70h] [rbp-418h]
  Scaleform::MsgFormat v17; // [rsp+80h] [rbp-408h] BYREF

  v16 = -2i64;
  ++this->InstanceNameCount;
  pstr = 0;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  r.Type = tDataPtr;
  r.SinkData.pStr = (Scaleform::String *)&pstr;
  r.SinkData.DataPtr.Size = 48i64;
  Scaleform::MsgFormat::MsgFormat(&v17, &r);
  Scaleform::MsgFormat::Parse(&v17, "instance{0}");
  Scaleform::MsgFormat::FormatD1<unsigned long>(&v17, &this->InstanceNameCount);
  Scaleform::MsgFormat::FinishFormatD(&v17);
  Scaleform::MsgFormat::~MsgFormat(&v17);
  v4 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[59].__vecDelDtor)(this->pASMovieRoot.pObject);
  Scaleform::GFx::ASStringManager::CreateString(v4, result, &pstr);
  return result;
}

// File Line: 5000
// RVA: 0x8D9D50
// bad sp value at call has been detected, the output may be wrong!
Scaleform::Ptr<Scaleform::GFx::ImageResource> *__fastcall Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Ptr<Scaleform::GFx::ImageResource> *result,
        Scaleform::GFx::MovieDefImpl *md,
        const char *linkageId)
{
  Scaleform::String *v8; // rax
  bool IsProtocolImage; // r14
  Scaleform::GFx::StateBagImpl *pObject; // r14
  Scaleform::GFx::StateBag *v11; // r14
  Scaleform::MemoryHeap *pHeap; // r15
  Scaleform::GFx::ImageCreator *v13; // r12
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *ImageFileHandlerRegistry; // rsi
  __int64 *FileOpener; // rdi
  Scaleform::Ptr<Scaleform::Log> *Log; // rax
  __int64 v17; // rdx
  __int64 v18; // rax
  Scaleform::Render::Image *v19; // rdi
  Scaleform::GFx::ImageResource *v20; // rax
  char v21; // al
  Scaleform::GFx::MovieDefImpl *v22; // r14
  Scaleform::GFx::MovieDefRootNode *i; // rdi
  Scaleform::ArrayDefaultPolicy *p_Policy; // rax
  Scaleform::GFx::MovieDefImpl *pDefImpl; // rcx
  bool v26; // di
  Scaleform::GFx::Resource *v27; // rdi
  Scaleform::GFx::ResourceLibBase *v28; // rcx
  Scaleform::GFx::ImageResource *v29; // rcx
  Scaleform::GFx::Resource *v30; // rdi
  Scaleform::GFx::ResourceLibBase *v31; // rcx
  Scaleform::GFx::ImageResource *v32; // rax
  Scaleform::GFx::ImageResource *v33; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceBindData v36; // [rsp+0h] [rbp-79h] BYREF
  Scaleform::String v37; // [rsp+10h] [rbp-69h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> v38; // [rsp+18h] [rbp-61h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> v39; // [rsp+20h] [rbp-59h] BYREF
  Scaleform::String v40; // [rsp+28h] [rbp-51h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> resulta; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::Ptr<Scaleform::Log> v42; // [rsp+38h] [rbp-41h] BYREF
  int v43; // [rsp+40h] [rbp-39h] BYREF
  Scaleform::MemoryHeap *v44; // [rsp+48h] [rbp-31h]
  int v45; // [rsp+50h] [rbp-29h]
  int v46; // [rsp+54h] [rbp-25h]
  __int64 v47; // [rsp+58h] [rbp-21h]
  __int64 v48; // [rsp+60h] [rbp-19h]
  __int64 v49; // [rsp+68h] [rbp-11h]
  Scaleform::GFx::MovieImpl *v50; // [rsp+70h] [rbp-9h]
  Scaleform::MemoryHeap *v51; // [rsp+78h] [rbp-1h]
  __int64 v52; // [rsp+80h] [rbp+7h]
  Scaleform::GFx::ImageResource *v53; // [rsp+88h] [rbp+Fh]
  Scaleform::Render::Image *v54; // [rsp+90h] [rbp+17h]
  Scaleform::Ptr<Scaleform::GFx::ImageResource> *v55; // [rsp+E8h] [rbp+6Fh]
  Scaleform::GFx::ImageResource *v56; // [rsp+F0h] [rbp+77h]
  char *pdata; // [rsp+F8h] [rbp+7Fh]

  v52 = -2i64;
  LODWORD(v40.pData) = 0;
  v56 = 0i64;
  if ( !md )
  {
LABEL_59:
    v32 = v56;
    result->pObject = v56;
    LODWORD(v40.pData) = 1;
    if ( v32 && !_InterlockedDecrement(&v32->RefCount.Value) )
    {
      v33 = v56;
      pLib = v56->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v56);
        v33->pLib = 0i64;
      }
      v33->vfptr->__vecDelDtor(v33, 1u);
    }
    return result;
  }
  Scaleform::String::String(&v40, linkageId);
  IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(v8, 0i64, 0i64);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v40.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( IsProtocolImage )
  {
    pObject = this->pStateBag.pObject;
    if ( pObject )
      v11 = &pObject->Scaleform::GFx::StateBag;
    else
      v11 = 0i64;
    pHeap = this->pHeap;
    v51 = pHeap;
    v13 = Scaleform::GFx::StateBag::GetImageCreator(v11, &resulta)->pObject;
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    if ( !v13 )
      goto LABEL_59;
    v43 = 0;
    v44 = pHeap;
    v45 = 1;
    v46 = 1;
    v47 = 0i64;
    v48 = 0i64;
    v49 = 0i64;
    v50 = 0i64;
    ImageFileHandlerRegistry = Scaleform::GFx::StateBag::GetImageFileHandlerRegistry(v11, &v39);
    FileOpener = (__int64 *)Scaleform::GFx::StateBag::GetFileOpener(v11, &v38);
    Log = Scaleform::GFx::StateBag::GetLog(v11, &v42);
    v17 = (__int64)ImageFileHandlerRegistry->pObject;
    v18 = (__int64)Log->pObject;
    v48 = *FileOpener;
    v47 = v18;
    v49 = v17;
    if ( v42.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v42.pObject);
    if ( v38.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v38.pObject);
    if ( v39.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v39.pObject);
    v50 = this;
    Scaleform::String::String(&v37, pdata);
    v19 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::String *))v13->vfptr[1].__vecDelDtor)(
                                        v13,
                                        &v43,
                                        &v37);
    v54 = v19;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v37.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( v19 )
    {
      v20 = (Scaleform::GFx::ImageResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pHeap->vfptr->Alloc)(
                                               pHeap,
                                               104i64);
      v53 = v20;
      if ( v20 )
        Scaleform::GFx::ImageResource::ImageResource(v20, v19, Use_Bitmap);
      v56 = v20;
    }
    if ( v19 )
      ((void (__fastcall *)(Scaleform::Render::Image *))v19->vfptr[2].__vecDelDtor)(v19);
    goto LABEL_57;
  }
  v36.pResource.pObject = 0i64;
  Scaleform::String::String((Scaleform::String *)&resulta, linkageId);
  if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(md, &v36, (Scaleform::String *)&resulta, 0i64) )
  {
    v21 = 1;
  }
  else
  {
    v22 = md;
    for ( i = this->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
    {
      p_Policy = &this->MovieLevels.Data.Policy;
      if ( this == (Scaleform::GFx::MovieImpl *)-112i64 )
        p_Policy = 0i64;
      if ( i == (Scaleform::GFx::MovieDefRootNode *)p_Policy )
        break;
      pDefImpl = i->pDefImpl;
      if ( pDefImpl != md && (unsigned __int8)Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(pDefImpl, v22) )
      {
        if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(i->pDefImpl, &v36, (Scaleform::String *)&resulta, 0i64) )
        {
          v21 = 1;
          goto LABEL_38;
        }
        v22 = i->pDefImpl;
      }
    }
    v21 = 0;
LABEL_38:
    result = v55;
  }
  v26 = v21 == 0;
  if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)resulta.pObject & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !v26 )
  {
    if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))v36.pResource.pObject->vfptr->GetResourceTypeCode)(v36.pResource.pObject) & 0xFF00) == 256 )
    {
      v29 = (Scaleform::GFx::ImageResource *)v36.pResource.pObject;
      if ( v36.pResource.pObject )
        _InterlockedExchangeAdd(&v36.pResource.pObject->RefCount.Value, 1u);
      v56 = v29;
    }
    v30 = v36.pResource.pObject;
    if ( v36.pResource.pObject && !_InterlockedDecrement(&v36.pResource.pObject->RefCount.Value) )
    {
      v31 = v30->pLib;
      if ( v31 )
      {
        v31->vfptr[1].__vecDelDtor(v31, (unsigned int)v30);
        v30->pLib = 0i64;
      }
      v30->vfptr->__vecDelDtor(v30, 1u);
    }
LABEL_57:
    result = v55;
    if ( v56 )
      _InterlockedExchangeAdd(&v56->RefCount.Value, 1u);
    goto LABEL_59;
  }
  result->pObject = 0i64;
  LODWORD(v40.pData) = 1;
  v27 = v36.pResource.pObject;
  if ( v36.pResource.pObject && !_InterlockedDecrement(&v36.pResource.pObject->RefCount.Value) )
  {
    v28 = v27->pLib;
    if ( v28 )
    {
      v28->vfptr[1].__vecDelDtor(v28, (unsigned int)v27);
      v27->pLib = 0i64;
    }
    v27->vfptr->__vecDelDtor(v27, 1u);
  }
  return result;
}

// File Line: 5050
// RVA: 0x8FD890
bool __fastcall Scaleform::GFx::MovieImpl::ReadTextData(
        Scaleform::String *pdata,
        Scaleform::File *pfile,
        unsigned int *pfileLen,
        bool urlEncoded)
{
  int v8; // eax
  char *v9; // rbx
  int v10; // eax
  int v11; // eax
  __int64 v12; // rcx
  __int64 i; // r8
  int v14; // eax
  __int64 v15; // rcx
  const char *v16; // rdx
  __int64 v17; // r8
  Scaleform::String src; // [rsp+58h] [rbp+10h] BYREF

  v8 = ((__int64 (__fastcall *)(Scaleform::File *))pfile->vfptr[6].__vecDelDtor)(pfile);
  *pfileLen = v8;
  if ( !v8 )
    return v8;
  Scaleform::String::String(&src);
  v9 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, (int)*pfileLen, 0i64);
  ((void (__fastcall *)(Scaleform::File *, char *, _QWORD))pfile->vfptr[10].__vecDelDtor)(pfile, v9, *pfileLen);
  v10 = *pfileLen;
  if ( *(_WORD *)v9 == 0xFEFF )
  {
    v11 = v10 / 2 - 1;
    v12 = 0i64;
    for ( i = v11; v12 < v11; ++v12 )
      ;
  }
  else
  {
    if ( *(_WORD *)v9 != 0xFFFE )
    {
      if ( v10 > 2 && *v9 == -17 && v9[1] == -69 && v9[2] == -65 )
      {
        v16 = v9 + 3;
        v17 = v10 - 3;
      }
      else
      {
        v17 = (int)*pfileLen;
        v16 = v9;
      }
      Scaleform::String::AppendString(&src, v16, v17);
      goto LABEL_17;
    }
    v14 = v10 / 2 - 1;
    v15 = 0i64;
    for ( i = v14; v15 < v14; ++v15 )
      *(_WORD *)&v9[2 * v15 + 2] = __ROL2__(*(_WORD *)&v9[2 * v15 + 2], 8);
  }
  Scaleform::String::AppendString(&src, (const wchar_t *)v9 + 1, i);
LABEL_17:
  if ( urlEncoded )
    Scaleform::GFx::ASUtils::Unescape(
      (const char *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
      *(_QWORD *)(src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
      pdata);
  else
    Scaleform::String::operator=(pdata, &src);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  LOBYTE(v8) = 1;
  return v8;
}

// File Line: 5135
// RVA: 0x8FA880
bool __fastcall Scaleform::GFx::MovieImpl::ReadBinaryData(
        Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *pdata,
        Scaleform::File *pfile,
        unsigned int *pfileLen)
{
  int v6; // eax

  v6 = ((__int64 (__fastcall *)(Scaleform::File *))pfile->vfptr[6].__vecDelDtor)(pfile);
  *pfileLen = v6;
  if ( v6 )
  {
    Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      pdata,
      v6);
    LOBYTE(v6) = ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))pfile->vfptr[10].__vecDelDtor)(
                   pfile,
                   pdata->Data,
                   *pfileLen) == *pfileLen;
  }
  return v6;
}

// File Line: 5181
// RVA: 0x8F3B80
void __fastcall Scaleform::GFx::MovieImpl::ProcessUnloadQueue(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *pUnloadListHead; // rbx
  Scaleform::GFx::InteractiveObject *pPlayNextOpt; // rdi
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  Scaleform::GFx::InteractiveObject *pParent; // rcx

  pUnloadListHead = this->pUnloadListHead;
  if ( pUnloadListHead )
  {
    do
    {
      pPlayNextOpt = pUnloadListHead->pPlayNextOpt;
      vfptr = pUnloadListHead->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
      pUnloadListHead->pPlayNextOpt = 0i64;
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))vfptr[75].__vecDelDtor)(pUnloadListHead);
      pParent = pUnloadListHead->pParent;
      if ( pParent )
        pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[117].__vecDelDtor(
          pParent,
          (unsigned int)pUnloadListHead);
      Scaleform::RefCountNTSImpl::Release(pUnloadListHead);
      pUnloadListHead = pPlayNextOpt;
    }
    while ( pPlayNextOpt );
    this->pUnloadListHead = 0i64;
  }
}

// File Line: 5354
// RVA: 0x8CBAC0
char __fastcall Scaleform::GFx::MovieImpl::FindExportedResource(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieDefImpl *localDef,
        Scaleform::GFx::ResourceBindData *presBindData,
        Scaleform::String *symbol)
{
  Scaleform::GFx::MovieDefRootNode *pNext; // rbx
  Scaleform::GFx::MovieDefImpl *v10; // rsi
  Scaleform::List<Scaleform::GFx::MovieDefRootNode,Scaleform::GFx::MovieDefRootNode> *p_RootMovieDefNodes; // rdi
  __int64 v12; // rax
  Scaleform::GFx::MovieDefImpl *pDefImpl; // rcx

  if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(localDef, presBindData, symbol, 0i64) )
    return 1;
  pNext = this->RootMovieDefNodes.Root.pNext;
  v10 = localDef;
  p_RootMovieDefNodes = &this->RootMovieDefNodes;
  while ( 1 )
  {
    v12 = p_RootMovieDefNodes ? (__int64)&p_RootMovieDefNodes[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::GFx::MovieDefRootNode *)v12 )
      break;
    pDefImpl = pNext->pDefImpl;
    if ( pDefImpl != localDef && (unsigned __int8)Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(pDefImpl, v10) )
    {
      if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(pNext->pDefImpl, presBindData, symbol, 0i64) )
        return 1;
      v10 = pNext->pDefImpl;
    }
    pNext = pNext->pNext;
  }
  return 0;
}

// File Line: 5378
// RVA: 0x8D70B0
Scaleform::Render::DrawableImageContext *__fastcall Scaleform::GFx::MovieImpl::GetDrawableImageContext(
        Scaleform::GFx::MovieImpl *this)
{
  Scaleform::Render::DrawableImageContext *result; // rax
  Scaleform::Render::DrawableImageContext *v3; // rax
  Scaleform::Render::DrawableImageContext *v4; // rbx
  Scaleform::Render::DrawableImageContext *v5; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::Interfaces i; // [rsp+28h] [rbp-30h] BYREF

  result = this->DIContext.pObject;
  if ( !result )
  {
    v3 = (Scaleform::Render::DrawableImageContext *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      448i64,
                                                      0i64);
    v4 = 0i64;
    if ( v3 )
    {
      memset(&i, 0, sizeof(i));
      Scaleform::Render::DrawableImageContext::DrawableImageContext(v3, &this->RenderContext, this->pRTCommandQueue, &i);
      v4 = v5;
    }
    pObject = (Scaleform::Render::RenderBuffer *)this->DIContext.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->DIContext.pObject = v4;
    return v4;
  }
  return result;
}

// File Line: 5389
// RVA: 0x8BF3A0
Scaleform::GFx::DrawingContext *__fastcall Scaleform::GFx::MovieImpl::CreateDrawingContext(
        Scaleform::GFx::MovieImpl *this)
{
  char v2; // bl
  Scaleform::GFx::DrawingContext *v3; // rdi
  Scaleform::GFx::Resource **ImageCreator; // rax
  Scaleform::GFx::DrawingContext *v5; // rax
  Scaleform::GFx::DrawingContext *v6; // rdi
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> result; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::DrawingContext *v9; // [rsp+60h] [rbp+18h]

  v2 = 0;
  v3 = (Scaleform::GFx::DrawingContext *)this->pHeap->vfptr->Alloc(this->pHeap, 208i64, 0i64);
  v9 = v3;
  if ( v3 )
  {
    ImageCreator = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetImageCreator(
                                                  &this->Scaleform::GFx::StateBag,
                                                  &result);
    v2 = 1;
    Scaleform::GFx::DrawingContext::DrawingContext(v3, &this->RenderContext, *ImageCreator);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( (v2 & 1) != 0 && result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  v6->pPrev = this->DrawingContextList.Root.pPrev;
  v6->pNext = (Scaleform::GFx::DrawingContext *)&this->RegisteredFonts.Data.Size;
  this->DrawingContextList.Root.pPrev->pNext = v6;
  this->DrawingContextList.Root.pPrev = v6;
  return v6;
}

// File Line: 5399
// RVA: 0x916AE0
void __fastcall Scaleform::GFx::MovieImpl::UpdateAllRenderNodes(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::DrawingContext *pNext; // rbx
  Scaleform::List<Scaleform::GFx::DrawingContext,Scaleform::GFx::DrawingContext> *p_DrawingContextList; // rdi
  __int64 v4; // rax

  pNext = this->DrawingContextList.Root.pNext;
  p_DrawingContextList = &this->DrawingContextList;
  while ( 1 )
  {
    v4 = p_DrawingContextList ? (__int64)&p_DrawingContextList[-1] : 0i64;
    if ( pNext == (Scaleform::GFx::DrawingContext *)v4 )
      break;
    if ( pNext->States < 0 )
      Scaleform::GFx::DrawingContext::UpdateRenderNode(pNext);
    pNext = pNext->pNext;
  }
  if ( this->FocusRectChanged )
    Scaleform::GFx::MovieImpl::UpdateFocusRectRenderNodes(this);
}

// File Line: 5431
// RVA: 0x8B1B60
void __fastcall Scaleform::GFx::MovieImpl::AddMovieDefToKillList(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieDefImpl *md)
{
  unsigned __int64 v3; // rdx
  unsigned __int64 Size; // r8
  Scaleform::GFx::MovieImpl::MDKillListEntry *Data; // r9
  Scaleform::GFx::MovieDefImpl **p_pObject; // rax
  unsigned __int64 v7; // rsi
  Scaleform::Array<Scaleform::GFx::MovieImpl::MDKillListEntry,327,Scaleform::ArrayDefaultPolicy> *p_MovieDefKillList; // rbx
  Scaleform::GFx::MovieImpl::MDKillListEntry *v9; // rdx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  if ( md )
  {
    v3 = 0i64;
    Size = this->MovieDefKillList.Data.Size;
    if ( Size )
    {
      Data = this->MovieDefKillList.Data.Data;
      p_pObject = &Data->pMovieDef.pObject;
      while ( *p_pObject != md )
      {
        ++v3;
        p_pObject += 2;
        if ( v3 >= Size )
          goto LABEL_8;
      }
      Data[v3].KillFrameId = this->RenderContext.SnapshotFrameIds[0];
    }
    else
    {
LABEL_8:
      v7 = this->RenderContext.SnapshotFrameIds[0];
      _InterlockedExchangeAdd(&md->RefCount.Value, 1u);
      p_MovieDefKillList = &this->MovieDefKillList;
      Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::MDKillListEntry,Scaleform::AllocatorGH<Scaleform::GFx::MovieImpl::MDKillListEntry,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &this->MovieDefKillList.Data,
        &this->MovieDefKillList,
        this->MovieDefKillList.Data.Size + 1);
      v9 = &p_MovieDefKillList->Data.Data[p_MovieDefKillList->Data.Size - 1];
      if ( v9 )
      {
        v9->KillFrameId = v7;
        _InterlockedExchangeAdd(&md->RefCount.Value, 1u);
        v9->pMovieDef.pObject = md;
      }
      if ( !_InterlockedDecrement(&md->RefCount.Value) )
      {
        pLib = md->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)md);
          md->pLib = 0i64;
        }
        md->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(md, 1i64);
      }
    }
  }
}

// File Line: 5451
// RVA: 0x8F3A80
void __fastcall Scaleform::GFx::MovieImpl::ProcessMovieDefToKillList(Scaleform::GFx::MovieImpl *this)
{
  unsigned __int64 FinalizedFrameId; // r15
  unsigned __int64 v3; // rsi
  Scaleform::Array<Scaleform::GFx::MovieImpl::MDKillListEntry,327,Scaleform::ArrayDefaultPolicy> *p_MovieDefKillList; // rdi
  __int64 v5; // r14
  Scaleform::GFx::MovieImpl::MDKillListEntry *v6; // rbx
  Scaleform::GFx::MovieDefImpl *pObject; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  if ( this->MovieDefKillList.Data.Size )
  {
    FinalizedFrameId = this->RenderContext.FinalizedFrameId;
    v3 = 0i64;
    p_MovieDefKillList = &this->MovieDefKillList;
    v5 = 0i64;
    do
    {
      v6 = &p_MovieDefKillList->Data.Data[v5];
      if ( FinalizedFrameId <= v6->KillFrameId )
      {
        ++v3;
        ++v5;
      }
      else if ( p_MovieDefKillList->Data.Size == 1 )
      {
        Scaleform::ArrayData<Scaleform::GFx::MovieImpl::MDKillListEntry,Scaleform::AllocatorGH<Scaleform::GFx::MovieImpl::MDKillListEntry,327>,Scaleform::ArrayDefaultPolicy>::Resize(
          &p_MovieDefKillList->Data,
          0i64);
      }
      else
      {
        pObject = v6->pMovieDef.pObject;
        if ( pObject && !_InterlockedDecrement(&pObject->RefCount.Value) )
        {
          pLib = pObject->pLib;
          if ( pLib )
          {
            pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pObject);
            pObject->pLib = 0i64;
          }
          pObject->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(pObject, 1u);
        }
        memmove(
          &p_MovieDefKillList->Data.Data[v5],
          &p_MovieDefKillList->Data.Data[v5 + 1],
          16 * (p_MovieDefKillList->Data.Size - v3 - 1));
        --p_MovieDefKillList->Data.Size;
      }
    }
    while ( v3 < this->MovieDefKillList.Data.Size );
  }
}

// File Line: 5666
// RVA: 0x8DDD40
void __fastcall Scaleform::GFx::MovieImpl::GetRetValHolder(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v2; // rax
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v3; // rdi
  Scaleform::GFx::ASStringManager *v4; // rax

  if ( !this->pRetValHolder )
  {
    v2 = (Scaleform::GFx::MovieImpl::ReturnValueHolder *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                                           this->pHeap,
                                                           56i64);
    v3 = v2;
    if ( v2 )
    {
      v4 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[59].__vecDelDtor)(this->pASMovieRoot.pObject);
      Scaleform::GFx::MovieImpl::ReturnValueHolder::ReturnValueHolder(v3, v4);
    }
    this->pRetValHolder = v2;
  }
}

// File Line: 5675
// RVA: 0x8CE480
void __fastcall Scaleform::GFx::MovieImpl::ForceUpdateImages(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::Render::ContextImpl::Context::ForceUpdateImages(&this->RenderContext);
  ++this->PreviouslyCaptured;
}

// File Line: 5687
// RVA: 0x8B1810
void __fastcall Scaleform::GFx::MovieImpl::AddIndirectTransformPair(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::DisplayObjContainer *origParent,
        Scaleform::Render::TreeNode *transformParent,
        Scaleform::GFx::DisplayObjectBase *obj)
{
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *p_IndirectTransformPairs; // rbx
  __int64 v8; // rdx

  if ( transformParent )
    ++transformParent->RefCount;
  if ( obj )
    ++obj->RefCount;
  if ( origParent )
    ++origParent->RefCount;
  p_IndirectTransformPairs = &this->IndirectTransformPairs;
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->IndirectTransformPairs.Data,
    &this->IndirectTransformPairs,
    this->IndirectTransformPairs.Data.Size + 1);
  v8 = (__int64)&p_IndirectTransformPairs->Data.Data[p_IndirectTransformPairs->Data.Size - 1];
  if ( v8 )
  {
    if ( transformParent )
      ++transformParent->RefCount;
    *(_QWORD *)v8 = transformParent;
    if ( obj )
      ++obj->RefCount;
    *(_QWORD *)(v8 + 8) = obj;
    if ( origParent )
      ++origParent->RefCount;
    *(_QWORD *)(v8 + 16) = origParent;
    *(_DWORD *)(v8 + 24) = -1;
  }
  if ( origParent )
    Scaleform::RefCountNTSImpl::Release(origParent);
  if ( obj )
    Scaleform::RefCountNTSImpl::Release(obj);
  if ( transformParent )
  {
    if ( transformParent->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(transformParent);
  }
}

// File Line: 5696
// RVA: 0x8FFA00
Scaleform::GFx::MovieImpl::IndirectTransPair *__fastcall Scaleform::GFx::MovieImpl::RemoveIndirectTransformPair(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieImpl::IndirectTransPair *result,
        Scaleform::GFx::DisplayObjectBase *obj)
{
  unsigned __int64 v4; // rdx
  unsigned __int64 Size; // r9
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *p_IndirectTransformPairs; // r10
  Scaleform::GFx::MovieImpl::IndirectTransPair *Data; // rcx
  Scaleform::GFx::DisplayObjectBase **p_pObject; // rax
  Scaleform::GFx::MovieImpl::IndirectTransPair *v9; // rax
  Scaleform::Render::TreeNode *pObject; // rbx
  Scaleform::GFx::DisplayObjectBase *v11; // rcx
  Scaleform::GFx::DisplayObjectBase *v12; // rsi
  Scaleform::GFx::DisplayObjContainer *v13; // r8
  Scaleform::GFx::DisplayObjContainer *v14; // rbp
  int OrigParentDepth; // r14d

  v4 = 0i64;
  Size = this->IndirectTransformPairs.Data.Size;
  if ( Size )
  {
    p_IndirectTransformPairs = &this->IndirectTransformPairs;
    Data = this->IndirectTransformPairs.Data.Data;
    p_pObject = &Data->Obj.pObject;
    while ( *p_pObject != obj )
    {
      ++v4;
      p_pObject += 4;
      if ( v4 >= Size )
        goto LABEL_25;
    }
    v9 = &Data[v4];
    if ( v9->TransformParent.pObject )
      ++v9->TransformParent.pObject->RefCount;
    pObject = v9->TransformParent.pObject;
    v11 = v9->Obj.pObject;
    if ( v11 )
      ++v11->RefCount;
    v12 = v9->Obj.pObject;
    v13 = v9->OriginalParent.pObject;
    if ( v13 )
      ++v13->RefCount;
    v14 = v9->OriginalParent.pObject;
    OrigParentDepth = v9->OrigParentDepth;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      p_IndirectTransformPairs,
      v4);
    if ( pObject )
      ++pObject->RefCount;
    result->TransformParent.pObject = pObject;
    if ( v12 )
      ++v12->RefCount;
    result->Obj.pObject = v12;
    if ( v14 )
      ++v14->RefCount;
    result->OriginalParent.pObject = v14;
    result->OrigParentDepth = OrigParentDepth;
    if ( v14 )
      Scaleform::RefCountNTSImpl::Release(v14);
    if ( v12 )
      Scaleform::RefCountNTSImpl::Release(v12);
    if ( pObject )
    {
      if ( pObject->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
    }
  }
  else
  {
LABEL_25:
    result->TransformParent.pObject = 0i64;
    result->Obj.pObject = 0i64;
    result->OriginalParent.pObject = 0i64;
    result->OrigParentDepth = -1;
  }
  return result;
}

// File Line: 5710
// RVA: 0x8BC3E0
void __fastcall Scaleform::GFx::MovieImpl::ClearIndirectTransformPairs(Scaleform::GFx::MovieImpl *this)
{
  unsigned __int64 Size; // rsi
  __int64 v3; // rdi
  Scaleform::GFx::MovieImpl::IndirectTransPair *Data; // rbx
  Scaleform::Render::ContextImpl::Entry *pObject; // rcx
  Scaleform::RefCountNTSImpl *v7; // rcx
  Scaleform::RefCountNTSImpl *v8; // rcx

  Size = this->IndirectTransformPairs.Data.Size;
  if ( Size )
  {
    v3 = 0i64;
    do
    {
      Data = this->IndirectTransformPairs.Data.Data;
      pObject = Data[v3].TransformParent.pObject;
      if ( pObject )
      {
        if ( pObject->RefCount-- == 1 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
      }
      Data[v3].TransformParent.pObject = 0i64;
      v7 = Data[v3].Obj.pObject;
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
      Data[v3].Obj.pObject = 0i64;
      v8 = Data[v3].OriginalParent.pObject;
      if ( v8 )
        Scaleform::RefCountNTSImpl::Release(v8);
      Data[v3].OriginalParent.pObject = 0i64;
      Data[v3++].OrigParentDepth = 0;
      --Size;
    }
    while ( Size );
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->IndirectTransformPairs.Data,
    &this->IndirectTransformPairs,
    0i64);
}

// File Line: 5720
// RVA: 0x9183C0
void __fastcall Scaleform::GFx::MovieImpl::UpdateTransformParent(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::DisplayObjectBase *obj,
        Scaleform::GFx::DisplayObjectBase *transfParent)
{
  unsigned __int64 Size; // r9
  Scaleform::Render::TreeNode *v4; // rdi
  __int64 v5; // rbx
  Scaleform::GFx::MovieImpl::IndirectTransPair *Data; // r10
  Scaleform::GFx::DisplayObjectBase **i; // rax
  Scaleform::GFx::MovieImpl::IndirectTransPair *v8; // rbx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::Entry *pObject; // rcx

  Size = this->IndirectTransformPairs.Data.Size;
  v4 = 0i64;
  v5 = 0i64;
  if ( Size )
  {
    Data = this->IndirectTransformPairs.Data.Data;
    for ( i = &Data->Obj.pObject; *i != obj; i += 4 )
    {
      if ( ++v5 >= Size )
        return;
    }
    v8 = &Data[v5];
    if ( transfParent )
    {
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(transfParent);
      v4 = RenderNode;
      if ( RenderNode )
        ++RenderNode->RefCount;
    }
    pObject = v8->TransformParent.pObject;
    if ( v8->TransformParent.pObject )
    {
      if ( pObject->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
    }
    v8->TransformParent.pObject = v4;
    v8->OrigParentDepth = -1;
  }
}

// File Line: 5735
// RVA: 0x8FE410
char __fastcall Scaleform::GFx::MovieImpl::RegisterFont(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieDef *md,
        Scaleform::GFx::FontResource *fontRes)
{
  unsigned __int64 v6; // rdx
  unsigned __int64 Size; // r8
  Scaleform::GFx::MovieImpl::FontDesc *Data; // rax
  Scaleform::GFx::MovieImpl::FontDesc *v10; // rdx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceLibBase *v12; // rcx

  v6 = 0i64;
  Size = this->RegisteredFonts.Data.Size;
  if ( Size )
  {
    Data = this->RegisteredFonts.Data.Data;
    while ( Data->pFont.pObject != fontRes || Data->pMovieDef.pObject != md )
    {
      ++v6;
      ++Data;
      if ( v6 >= Size )
        goto LABEL_8;
    }
    return 0;
  }
  else
  {
LABEL_8:
    if ( fontRes )
      _InterlockedExchangeAdd(&fontRes->RefCount.Value, 1u);
    if ( md )
      _InterlockedExchangeAdd(&md->RefCount.Value, 1u);
    Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::FontDesc,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::FontDesc,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->RegisteredFonts.Data,
      &this->RegisteredFonts,
      this->RegisteredFonts.Data.Size + 1);
    v10 = &this->RegisteredFonts.Data.Data[this->RegisteredFonts.Data.Size - 1];
    if ( v10 )
    {
      if ( md )
        _InterlockedExchangeAdd(&md->RefCount.Value, 1u);
      v10->pMovieDef.pObject = md;
      if ( fontRes )
        _InterlockedExchangeAdd(&fontRes->RefCount.Value, 1u);
      v10->pFont.pObject = fontRes;
    }
    this->Flags2 |= 2u;
    if ( fontRes && !_InterlockedDecrement(&fontRes->RefCount.Value) )
    {
      pLib = fontRes->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)fontRes);
        fontRes->pLib = 0i64;
      }
      fontRes->vfptr->__vecDelDtor(fontRes, 1i64);
    }
    if ( md && !_InterlockedDecrement(&md->RefCount.Value) )
    {
      v12 = md->pLib;
      if ( v12 )
      {
        v12->vfptr[1].__vecDelDtor(v12, (unsigned int)md);
        md->pLib = 0i64;
      }
      md->Scaleform::GFx::Resource::vfptr->__vecDelDtor(md, 1i64);
    }
    return 1;
  }
}

// File Line: 5756
// RVA: 0x916540
void __fastcall Scaleform::GFx::MovieImpl::UnregisterFonts(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieDefImpl *pdefImpl)
{
  unsigned __int64 v2; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::FontDesc,2,Scaleform::ArrayDefaultPolicy> *p_RegisteredFonts; // rbx
  __int64 v6; // rsi
  Scaleform::GFx::MovieImpl::FontDesc *v7; // rcx
  Scaleform::GFx::MovieDefRootNode *i; // rbx
  Scaleform::ArrayDefaultPolicy *v9; // rax

  v2 = 0i64;
  if ( this->RegisteredFonts.Data.Size )
  {
    p_RegisteredFonts = &this->RegisteredFonts;
    v6 = 0i64;
    do
    {
      v7 = &p_RegisteredFonts->Data.Data[v6];
      if ( v7->pMovieDef.pObject == pdefImpl )
      {
        if ( p_RegisteredFonts->Data.Size == 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::FontDesc,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::FontDesc,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &p_RegisteredFonts->Data,
            p_RegisteredFonts,
            0i64);
        }
        else
        {
          Scaleform::GFx::MovieImpl::FontDesc::~FontDesc(v7);
          memmove(
            &p_RegisteredFonts->Data.Data[v6],
            &p_RegisteredFonts->Data.Data[v6 + 1],
            16 * (p_RegisteredFonts->Data.Size - v2 - 1));
          --p_RegisteredFonts->Data.Size;
        }
      }
      else
      {
        ++v2;
        ++v6;
      }
    }
    while ( v2 < this->RegisteredFonts.Data.Size );
  }
  for ( i = this->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
  {
    v9 = this == (Scaleform::GFx::MovieImpl *)-112i64 ? 0i64 : &this->MovieLevels.Data.Policy;
    if ( i == (Scaleform::GFx::MovieDefRootNode *)v9 )
      break;
    Scaleform::GFx::FontManager::CleanCacheFor(i->pFontManager.pObject, pdefImpl);
  }
  this->Flags2 |= 2u;
}

// File Line: 5780
// RVA: 0x8CD3E0
Scaleform::GFx::FontResource *__fastcall Scaleform::GFx::MovieImpl::FindRegisteredFont(
        Scaleform::GFx::MovieImpl *this,
        const char *pfontName,
        __int16 matchFontFlags,
        Scaleform::GFx::MovieDef **ppsrcMovieDef)
{
  unsigned __int64 Size; // rbp
  unsigned __int64 v5; // rbx
  __int64 v9; // rdi
  int v10; // r14d
  int v11; // r15d
  Scaleform::Render::Font *pObject; // rcx
  const char *v13; // rax
  unsigned __int64 v15; // rbx

  Size = this->RegisteredFonts.Data.Size;
  v5 = 0i64;
  if ( !Size )
    return 0i64;
  v9 = 0i64;
  v10 = matchFontFlags & 0x10 | ((matchFontFlags & 0x300) != 0 ? 0x300 : 0) | 3;
  v11 = matchFontFlags & 0x313;
  while ( 1 )
  {
    pObject = this->RegisteredFonts.Data.Data[v9].pFont.pObject->pFont.pObject;
    if ( (v10 & pObject->Flags) == v11 )
    {
      v13 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))pObject->vfptr[1].__vecDelDtor)(pObject);
      if ( !Scaleform::String::CompareNoCase(v13, pfontName) )
        break;
    }
    ++v5;
    ++v9;
    if ( v5 >= Size )
      return 0i64;
  }
  v15 = v5;
  *ppsrcMovieDef = this->RegisteredFonts.Data.Data[v15].pMovieDef.pObject;
  return this->RegisteredFonts.Data.Data[v15].pFont.pObject;
}

// File Line: 5807
// RVA: 0x8E9620
void __fastcall Scaleform::GFx::MovieImpl::MakeAreaVisible(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Rect<float> *screenRect,
        Scaleform::Render::Rect<float> *box,
        char flags)
{
  Scaleform::Render::Matrix2x4<float> *p_ViewportMatrix; // r14
  float v9; // xmm9_4
  float v10; // xmm10_4
  __m128 x2_low; // xmm6
  float v12; // xmm7_4
  double v13; // xmm4_8
  double v14; // xmm3_8
  float v15; // xmm8_4
  float v16; // xmm11_4
  float v17; // xmm7_4
  __m128d v18; // xmm1
  double v19; // xmm3_8
  double v20; // xmm12_8
  double v21; // xmm5_8
  double v22; // xmm2_8
  float v23; // xmm6_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // xmm5_4
  float v27; // xmm8_4
  float v28; // xmm10_4
  float v29; // xmm7_4
  float v30; // xmm10_4
  float v31; // xmm6_4
  float v32; // xmm9_4
  float v33; // xmm3_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm6_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  float v39; // xmm8_4
  Scaleform::Render::Rect<float> pr; // [rsp+20h] [rbp-99h] BYREF
  Scaleform::Render::Rect<float> v41; // [rsp+30h] [rbp-89h] BYREF
  Scaleform::Render::Rect<float> r; // [rsp+40h] [rbp-79h] BYREF
  Scaleform::Render::Matrix2x4<float> v43; // [rsp+50h] [rbp-69h] BYREF
  Scaleform::Render::Matrix2x4<float> v44; // [rsp+70h] [rbp-49h] BYREF

  if ( box->x2 > screenRect->x2 || box->y2 > screenRect->y2 || box->x1 < screenRect->x1 || box->y1 < screenRect->y1 )
  {
    *(_OWORD *)&v44.M[0][0] = _xmm;
    *(__m128 *)&v44.M[1][0] = _xmm;
    Scaleform::GFx::MovieImpl::ResetViewportMatrix(this);
    p_ViewportMatrix = &this->ViewportMatrix;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v44, &this->ViewportMatrix);
    pr = 0i64;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v44, &pr, screenRect);
    v9 = box->x1 * 20.0;
    x2_low = (__m128)LODWORD(box->x2);
    v10 = box->y1 * 20.0;
    x2_low.m128_f32[0] = x2_low.m128_f32[0] * 20.0;
    v12 = box->y2 * 20.0;
    r.x1 = v9;
    r.y1 = v10;
    LODWORD(r.x2) = x2_low.m128_i32[0];
    r.y2 = v12;
    v13 = DOUBLE_1_0;
    v14 = DOUBLE_1_0;
    if ( (flags & 1) == 0 )
    {
      if ( (float)(x2_low.m128_f32[0] - v9) > (float)(pr.x2 - pr.x1) )
        v13 = pr.x2 / x2_low.m128_f32[0];
      if ( (float)(v12 - v10) > (float)(pr.y2 - pr.y1) )
        v14 = pr.y2 / v12;
    }
    if ( (flags & 2) != 0 && v13 == 1.0 && v14 == 1.0 )
    {
      v15 = pr.y2 - pr.y1;
      v16 = pr.x2 - pr.x1;
      v17 = v12 - v10;
      x2_low.m128_f32[0] = x2_low.m128_f32[0] - v9;
      if ( (float)((float)(v17 * x2_low.m128_f32[0]) * 2.0) < (double)(float)((float)(pr.y2 - pr.y1)
                                                                            * (float)(pr.x2 - pr.x1)) )
      {
        v18 = _mm_cvtps_pd(x2_low);
        v19 = (float)((float)(pr.y2 - pr.y1) * (float)(pr.x2 - pr.x1)) * 0.5;
        v20 = 1.0 / v17;
        v21 = 1.0 / x2_low.m128_f32[0];
        v18.m128d_f64[0] = v18.m128d_f64[0] * v20 * v19;
        v22 = _mm_sqrt_pd(v18).m128d_f64[0];
        v13 = v21 * v22;
        v14 = v19 / v22 * v20;
        if ( x2_low.m128_f32[0] * (v21 * v22) > v16 )
          v13 = v16 * v21;
        if ( v17 * v14 > v15 )
          v14 = v15 * v20;
      }
    }
    if ( v13 >= v14 )
      v13 = v14;
    v23 = 0.0;
    v24 = v13;
    v43.M[0][0] = v24;
    v43.M[1][1] = v24;
    v43.M[0][1] = v24 * 0.0;
    v43.M[0][2] = v24 * 0.0;
    v43.M[1][0] = v24 * 0.0;
    v43.M[1][2] = v24 * 0.0;
    v43.M[0][3] = (float)(COERCE_FLOAT(LODWORD(v9) ^ _xmm[0]) * v24) + v9;
    v43.M[1][3] = (float)(COERCE_FLOAT(LODWORD(v10) ^ _xmm[0]) * v24) + v10;
    v41 = 0i64;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v43, &v41, &r);
    v25 = 0.0;
    if ( v41.x1 > pr.x2 || v41.x2 < pr.x1 || v41.x2 > pr.x2 || v41.x1 < pr.x1 )
    {
      if ( (flags & 4) != 0 )
        v23 = v41.x1 - pr.x1;
      else
        v23 = (float)((float)((float)(v41.x2 - v41.x1) * 0.5) + v41.x1)
            - (float)(pr.x2 - (float)((float)(pr.x2 - pr.x1) * 0.5));
    }
    if ( v41.y1 > pr.y2 || v41.y2 < pr.y1 || v41.y2 > pr.y2 || v41.y1 < pr.y1 )
    {
      if ( (flags & 4) != 0 )
        v25 = v41.y1 - pr.y1;
      else
        v25 = (float)((float)((float)(v41.y2 - v41.y1) * 0.5) + v41.y1)
            - (float)(pr.y2 - (float)((float)(pr.y2 - pr.y1) * 0.5));
    }
    v26 = p_ViewportMatrix->M[0][0];
    v27 = this->ViewportMatrix.M[1][1];
    v28 = v43.M[0][3];
    this->ViewportMatrix.M[1][2] = 0.0;
    this->ViewportMatrix.M[0][2] = 0.0;
    v29 = this->ViewportMatrix.M[1][0];
    v30 = v28 + COERCE_FLOAT(LODWORD(v23) ^ _xmm[0]);
    v31 = this->ViewportMatrix.M[0][1];
    v43.M[0][3] = v30;
    v33 = v31 * v43.M[1][1];
    v43.M[1][3] = v43.M[1][3] + COERCE_FLOAT(LODWORD(v25) ^ _xmm[0]);
    v32 = v43.M[1][3];
    p_ViewportMatrix->M[0][0] = (float)(v31 * v43.M[1][0]) + (float)(v26 * v43.M[0][0]);
    v34 = v26 * v43.M[0][1];
    this->ViewportMatrix.M[1][0] = (float)(v27 * v43.M[1][0]) + (float)(v29 * v43.M[0][0]);
    v35 = v27 * v43.M[1][1];
    v36 = (float)((float)(v31 * v32) + (float)(v26 * v30)) + this->ViewportMatrix.M[0][3];
    v37 = v33 + v34;
    v38 = v29 * v43.M[0][1];
    this->ViewportMatrix.M[0][1] = v37;
    this->ViewportMatrix.M[0][3] = v36;
    v39 = (float)((float)(v27 * v32) + (float)(v29 * v30)) + this->ViewportMatrix.M[1][3];
    this->ViewportMatrix.M[1][1] = v35 + v38;
    this->ViewportMatrix.M[1][3] = v39;
    Scaleform::Render::TreeNode::SetMatrix(this->pRenderRoot.pObject, &this->ViewportMatrix);
  }
}

