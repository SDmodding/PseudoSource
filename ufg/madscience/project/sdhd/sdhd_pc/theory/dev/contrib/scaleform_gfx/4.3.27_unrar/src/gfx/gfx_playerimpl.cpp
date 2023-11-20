// File Line: 207
// RVA: 0x8A60A0
void __fastcall Scaleform::GFx::Movie::~Movie(Scaleform::GFx::Movie *this)
{
  Scaleform::GFx::Movie *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::GFx::StateBag};
  v2 = (Scaleform::Render::RenderBuffer *)this->pASMovieRoot.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v1->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 212
// RVA: 0x8D4BE0
__int64 __fastcall Scaleform::GFx::Movie::GetAVMVersion(Scaleform::GFx::Movie *this)
{
  return (unsigned __int8)this->pASMovieRoot.pObject->AVMVersion;
}

// File Line: 217
// RVA: 0x8E1520
__int64 __fastcall Scaleform::GFx::Movie::GetVariable(Scaleform::GFx::Movie *this, Scaleform::GFx::Value *pval, const char *ppathToVar)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::Value *, const char *))this->pASMovieRoot.pObject->vfptr[49].__vecDelDtor)(
           this->pASMovieRoot.pObject,
           pval,
           ppathToVar);
}

// File Line: 223
// RVA: 0x90E8B0
__int64 __fastcall Scaleform::GFx::Movie::SetVariable(Scaleform::GFx::Movie *this, const char *ppathToVar, Scaleform::GFx::Value *value, __int64 setType)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, const char *, Scaleform::GFx::Value *, __int64))this->pASMovieRoot.pObject->vfptr[48].__vecDelDtor)(
           this->pASMovieRoot.pObject,
           ppathToVar,
           value,
           setType);
}

// File Line: 255
// RVA: 0x8E6DE0
__int64 __fastcall Scaleform::GFx::Movie::Invoke(Scaleform::GFx::Movie *this, const char *pmethodName, Scaleform::GFx::Value *presult, Scaleform::GFx::Value *pargs, unsigned int numArgs)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, const char *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))this->pASMovieRoot.pObject->vfptr[56].__vecDelDtor)(
           this->pASMovieRoot.pObject,
           pmethodName,
           presult,
           pargs);
}

// File Line: 261
// RVA: 0x8E6DB0
__int64 Scaleform::GFx::Movie::Invoke(Scaleform::GFx::Movie *this, const char *pmethodName, Scaleform::GFx::Value *presult, const char *pargFmt, ...)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, const char *, Scaleform::GFx::Value *))this->pASMovieRoot.pObject->vfptr[57].__vecDelDtor)(
           this->pASMovieRoot.pObject,
           pmethodName,
           presult);
}

// File Line: 272
// RVA: 0x8E6DF0
__int64 __fastcall Scaleform::GFx::Movie::InvokeArgs(Scaleform::GFx::Movie *this, const char *pmethodName, Scaleform::GFx::Value *presult, const char *pargFmt, char *args)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, const char *, Scaleform::GFx::Value *, const char *))this->pASMovieRoot.pObject->vfptr[57].__vecDelDtor)(
           this->pASMovieRoot.pObject,
           pmethodName,
           presult,
           pargFmt);
}

// File Line: 278
// RVA: 0x8C3AB0
void __fastcall Scaleform::GFx::Movie::CreateString(Scaleform::GFx::Movie *this, Scaleform::GFx::Value *pvalue, const char *pstring)
{
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::Value *, const char *))this->pASMovieRoot.pObject->vfptr[43].__vecDelDtor)(
    this->pASMovieRoot.pObject,
    pvalue,
    pstring);
}

// File Line: 305
// RVA: 0x907050
void __fastcall Scaleform::GFx::Movie::SetExternalInterfaceRetVal(Scaleform::GFx::Movie *this, Scaleform::GFx::Value *v)
{
  this->pASMovieRoot.pObject->vfptr[40].__vecDelDtor(
    (Scaleform::RefCountImplCore *)this->pASMovieRoot.pObject,
    (unsigned int)v);
}

// File Line: 310
// RVA: 0x8FE630
void __fastcall Scaleform::GFx::Movie::Release(Scaleform::GFx::Movie *this)
{
  Scaleform::GFx::Movie *v1; // rdi
  Scaleform::GFx::Resource *v2; // rax
  Scaleform::Render::RenderBuffer *v3; // rbx

  v1 = this;
  if ( !_InterlockedDecrement(&this->RefCount) )
  {
    v2 = (Scaleform::GFx::Resource *)((__int64 (__cdecl *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->vfptr[58].__vecDelDtor)(this->pASMovieRoot.pObject);
    v3 = (Scaleform::Render::RenderBuffer *)v2;
    if ( v2 )
      Scaleform::Render::RenderBuffer::AddRef(v2);
    v1->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 1u);
    if ( v3 )
      Scaleform::RefCountImpl::Release(v3);
  }
}

// File Line: 409
// RVA: 0x89B3D0
void __fastcall Scaleform::GFx::MovieImpl::MovieImpl(Scaleform::GFx::MovieImpl *this, Scaleform::MemoryHeap *pheap)
{
  Scaleform::GFx::MovieImpl *v2; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::LevelInfo,327,Scaleform::ArrayDefaultPolicy> *v3; // rax
  Scaleform::List<Scaleform::GFx::MovieDefRootNode,Scaleform::GFx::MovieDefRootNode> *v4; // rax
  bool v5; // zf
  Scaleform::ArrayDefaultPolicy *v6; // rcx
  Scaleform::Render::RenderBuffer **v7; // r14
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *v8; // rax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327,Scaleform::ArrayDefaultPolicy> *v9; // rax
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::FontDesc,2,Scaleform::ArrayDefaultPolicy> *v10; // rax
  signed __int64 v11; // rax
  Scaleform::Array<Scaleform::GFx::MovieImpl::MDKillListEntry,327,Scaleform::ArrayDefaultPolicy> *v12; // rax
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *v13; // rax
  Scaleform::Render::TreeRoot::NodeData *v14; // rax
  Scaleform::Render::ContextImpl::EntryData *v15; // rdi
  Scaleform::Render::ContextImpl::Entry *v16; // rdi
  Scaleform::Render::ContextImpl::Entry *v17; // rcx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v18; // rax
  Scaleform::Render::TreeNode *v19; // rdi
  Scaleform::Render::ContextImpl::Entry *v20; // rcx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v21; // rax
  Scaleform::GFx::StateBagImpl *v22; // rax
  Scaleform::GFx::StateBagImpl *v23; // rdi
  Scaleform::Render::RenderBuffer *v24; // rcx
  char v25; // al
  char *v26; // rcx
  __int64 v27; // rdi
  Scaleform::GFx::StateBagImpl *v28; // rax
  signed __int64 v29; // rax
  Scaleform::RefCountNTSImpl *v30; // rcx
  unsigned __int64 v31; // rax
  Scaleform::Render::ContextImpl::RTHandle v32; // [rsp+88h] [rbp+48h]
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *v33; // [rsp+90h] [rbp+50h]
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::LevelInfo,327,Scaleform::ArrayDefaultPolicy> *v34; // [rsp+98h] [rbp+58h]

  v2 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::`vftable;
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::GFx::StateBag};
  this->pASMovieRoot.pObject = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::MovieImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->AdvanceStats.pObject = 0i64;
  this->pHeap = pheap;
  this->pMainMovieDef.pObject = 0i64;
  v3 = &this->MovieLevels;
  v33 = (Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *)v3;
  v34 = &this->MovieLevels;
  v3->Data.Data = 0i64;
  v3->Data.Size = 0i64;
  v3->Data.Policy.Capacity = 0i64;
  v4 = &this->RootMovieDefNodes;
  v5 = &this->RootMovieDefNodes == 0i64;
  v6 = &this->MovieLevels.Data.Policy;
  if ( v5 )
    v6 = 0i64;
  v4->Root.pPrev = (Scaleform::GFx::MovieDefRootNode *)v6;
  v4->Root.pNext = (Scaleform::GFx::MovieDefRootNode *)v6;
  v2->pStateBag.pObject = 0i64;
  v2->pRenderRoot.pObject = 0i64;
  v7 = (Scaleform::Render::RenderBuffer **)&v2->hDisplayRoot;
  v33 = (Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *)v7;
  *v7 = 0i64;
  v2->pTopMostRoot.pObject = 0i64;
  *(_QWORD *)&v2->mViewport.BufferWidth = 0i64;
  *(_QWORD *)&v2->mViewport.Left = 0i64;
  v2->mViewport.Height = 1;
  v2->mViewport.Width = 1;
  *(_QWORD *)&v2->mViewport.ScissorWidth = 0i64;
  *(_QWORD *)&v2->mViewport.ScissorLeft = 0i64;
  v2->mViewport.Flags = 0;
  v2->mViewport.AspectRatio = 1.0;
  v2->mViewport.Scale = 1.0;
  v2->PixelScale = 1.0;
  *(_QWORD *)&v2->VisibleFrameRect.x1 = 0i64;
  *(_QWORD *)&v2->VisibleFrameRect.x2 = 0i64;
  *(_QWORD *)&v2->SafeRect.x1 = 0i64;
  *(_QWORD *)&v2->SafeRect.x2 = 0i64;
  *(_QWORD *)&v2->ViewportMatrix.M[0][0] = 1065353216i64;
  *(_QWORD *)&v2->ViewportMatrix.M[0][2] = 0i64;
  v2->ViewportMatrix.M[1][0] = 0.0;
  *(_QWORD *)&v2->ViewportMatrix.M[1][1] = 1065353216i64;
  v2->ViewportMatrix.M[1][3] = 0.0;
  Scaleform::Render::ScreenToWorld::ScreenToWorld(&v2->ScreenToWorld);
  v2->pCachedLog.pObject = 0i64;
  v2->pUserEventHandler.pObject = 0i64;
  v2->pFSCommandHandler.pObject = 0i64;
  v2->pExtIntfHandler.pObject = 0i64;
  v2->pFontManagerStates.pObject = 0i64;
  v2->pXMLObjectManager = 0i64;
  v2->InputEventsQueue.StartPos = 0i64;
  v2->InputEventsQueue.UsedEntries = 0i64;
  v2->InputEventsQueue.LastMousePosMask = 0;
  *(_WORD *)&v2->BackgroundColor.Channels.Green = 0;
  v2->BackgroundColor.Channels.Blue = 0;
  v2->BackgroundColor.Channels.Alpha = -1;
  `eh vector constructor iterator(
    v2->mMouseState,
    0x50ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::MouseState::MouseState);
  v2->MouseCursorCount = 1;
  v2->ControllerCount = 1;
  v2->UserData = 0i64;
  `eh vector constructor iterator(
    v2->KeyboardStates,
    0x688ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::KeyboardState::KeyboardState);
  v2->CurrentDragStates[0].pCharacter = 0i64;
  v2->CurrentDragStates[0].pTopmostEntity = 0i64;
  *(_WORD *)&v2->CurrentDragStates[0].LockCenter = 0;
  v2->CurrentDragStates[0].BoundLT = 0i64;
  v2->CurrentDragStates[0].BoundRB = 0i64;
  v2->CurrentDragStates[0].CenterDelta = 0i64;
  v2->CurrentDragStates[0].MouseIndex = -1;
  v2->CurrentDragStates[1].pCharacter = 0i64;
  v2->CurrentDragStates[1].pTopmostEntity = 0i64;
  *(_WORD *)&v2->CurrentDragStates[1].LockCenter = 0;
  v2->CurrentDragStates[1].BoundLT = 0i64;
  v2->CurrentDragStates[1].BoundRB = 0i64;
  v2->CurrentDragStates[1].CenterDelta = 0i64;
  v2->CurrentDragStates[1].MouseIndex = -1;
  v2->CurrentDragStates[2].pCharacter = 0i64;
  v2->CurrentDragStates[2].pTopmostEntity = 0i64;
  *(_WORD *)&v2->CurrentDragStates[2].LockCenter = 0;
  v2->CurrentDragStates[2].BoundLT = 0i64;
  v2->CurrentDragStates[2].BoundRB = 0i64;
  v2->CurrentDragStates[2].CenterDelta = 0i64;
  v2->CurrentDragStates[2].MouseIndex = -1;
  v2->CurrentDragStates[3].pCharacter = 0i64;
  v2->CurrentDragStates[3].pTopmostEntity = 0i64;
  *(_WORD *)&v2->CurrentDragStates[3].LockCenter = 0;
  v2->CurrentDragStates[3].BoundLT = 0i64;
  v2->CurrentDragStates[3].BoundRB = 0i64;
  v2->CurrentDragStates[3].CenterDelta = 0i64;
  v2->CurrentDragStates[3].MouseIndex = -1;
  v2->CurrentDragStates[4].pCharacter = 0i64;
  v2->CurrentDragStates[4].pTopmostEntity = 0i64;
  *(_WORD *)&v2->CurrentDragStates[4].LockCenter = 0;
  v2->CurrentDragStates[4].BoundLT = 0i64;
  v2->CurrentDragStates[4].BoundRB = 0i64;
  v2->CurrentDragStates[4].CenterDelta = 0i64;
  v2->CurrentDragStates[4].MouseIndex = -1;
  v2->CurrentDragStates[5].pCharacter = 0i64;
  v2->CurrentDragStates[5].pTopmostEntity = 0i64;
  *(_WORD *)&v2->CurrentDragStates[5].LockCenter = 0;
  v2->CurrentDragStates[5].BoundLT = 0i64;
  v2->CurrentDragStates[5].BoundRB = 0i64;
  v2->CurrentDragStates[5].CenterDelta = 0i64;
  v2->CurrentDragStates[5].MouseIndex = -1;
  v2->StickyVariables.mHash.pTable = 0i64;
  v8 = &v2->TopmostLevelCharacters;
  v8->Data.Data = 0i64;
  v8->Data.Size = 0i64;
  v8->Data.Policy.Capacity = 0i64;
  v9 = &v2->IntervalTimers;
  v33 = (Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *)v9;
  v34 = (Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::LevelInfo,327,Scaleform::ArrayDefaultPolicy> *)&v2->IntervalTimers;
  v9->Data.Data = 0i64;
  v9->Data.Size = 0i64;
  v9->Data.Policy.Capacity = 0i64;
  v2->FocusRectContainerNode.pObject = 0i64;
  `eh vector constructor iterator(
    v2->FocusGroups,
    0x60ui64,
    16,
    (void (__fastcall *)(void *))Scaleform::GFx::FocusGroupDescr::`default constructor closure);
  *(_QWORD *)&v2->Flags = 0i64;
  v10 = &v2->RegisteredFonts;
  v33 = (Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *)v10;
  v34 = (Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::LevelInfo,327,Scaleform::ArrayDefaultPolicy> *)&v2->RegisteredFonts;
  v10->Data.Data = 0i64;
  v10->Data.Size = 0i64;
  v10->Data.Policy.Capacity = 0i64;
  v11 = (signed __int64)&v2->RegisteredFonts.Data.Size;
  if ( v2 == (Scaleform::GFx::MovieImpl *)-21248i64 )
    v11 = 0i64;
  v2->DrawingContextList.Root.pPrev = (Scaleform::GFx::DrawingContext *)v11;
  v2->DrawingContextList.Root.pNext = (Scaleform::GFx::DrawingContext *)v11;
  v12 = &v2->MovieDefKillList;
  v33 = (Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *)v12;
  v34 = (Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::LevelInfo,327,Scaleform::ArrayDefaultPolicy> *)&v2->MovieDefKillList;
  v12->Data.Data = 0i64;
  v12->Data.Size = 0i64;
  v12->Data.Policy.Capacity = 0i64;
  v2->pSavedASMovieRoot.pObject = 0i64;
  Scaleform::Render::ContextImpl::Context::Context(&v2->RenderContext, Scaleform::Memory::pGlobalHeap);
  v2->DIContext.pObject = 0i64;
  v2->pRTCommandQueue = 0i64;
  v2->MultitouchHAL.pObject = 0i64;
  v2->GestureTopMostChar.pObject = 0i64;
  v13 = &v2->IndirectTransformPairs;
  v33 = v13;
  v34 = (Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::LevelInfo,327,Scaleform::ArrayDefaultPolicy> *)&v2->IndirectTransformPairs;
  v13->Data.Data = 0i64;
  v13->Data.Size = 0i64;
  v13->Data.Policy.Capacity = 0i64;
  v14 = (Scaleform::Render::TreeRoot::NodeData *)v2->RenderContext.pHeap->vfptr->Alloc(
                                                   v2->RenderContext.pHeap,
                                                   208ui64,
                                                   0i64);
  v15 = (Scaleform::Render::ContextImpl::EntryData *)&v14->vfptr;
  v33 = (Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *)v14;
  v34 = (Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::LevelInfo,327,Scaleform::ArrayDefaultPolicy> *)v14;
  if ( v14 )
    Scaleform::Render::TreeRoot::NodeData::NodeData(v14);
  v16 = Scaleform::Render::ContextImpl::Context::createEntryHelper(&v2->RenderContext, v15);
  v17 = (Scaleform::Render::ContextImpl::Entry *)&v2->pRenderRoot.pObject->0;
  if ( v17 )
  {
    v5 = v17->RefCount-- == 1;
    if ( v5 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v17);
  }
  v2->pRenderRoot.pObject = (Scaleform::Render::TreeRoot *)v16;
  Scaleform::Render::ContextImpl::RTHandle::RTHandle(&v32, v16);
  v18 = v32.pData.pObject;
  if ( v32.pData.pObject )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v32.pData.pObject);
    v18 = v32.pData.pObject;
  }
  if ( *v7 )
  {
    Scaleform::RefCountImpl::Release(*v7);
    v18 = v32.pData.pObject;
  }
  *v7 = (Scaleform::Render::RenderBuffer *)v18;
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v32);
  v19 = (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&v2->RenderContext);
  v20 = (Scaleform::Render::ContextImpl::Entry *)&v2->pTopMostRoot.pObject->0;
  if ( v20 )
  {
    v5 = v20->RefCount-- == 1;
    if ( v5 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v20);
  }
  v2->pTopMostRoot.pObject = (Scaleform::Render::TreeContainer *)v19;
  Scaleform::Render::TreeContainer::Add((Scaleform::Render::TreeContainer *)&v2->pRenderRoot.pObject->0, v19);
  Scaleform::Render::ContextImpl::Context::Capture(&v2->RenderContext);
  v2->pMainMovie = 0i64;
  v2->Flags |= 0x40180u;
  v2->pPlayListOptHead = 0i64;
  v2->pPlayListHead = 0i64;
  v2->TimeElapsed = 0i64;
  v2->TimeRemainder = 0.0;
  *(_QWORD *)&v2->FrameTime = 1034594987i64;
  v2->pLoadQueueHead = 0i64;
  v2->pLoadQueueMTHead = 0i64;
  v21 = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v2->pHeap->vfptr->Alloc)(
                                                                  v2->pHeap,
                                                                  88i64);
  v32.pData.pObject = v21;
  if ( v21 )
  {
    Scaleform::GFx::StateBagImpl::StateBagImpl((Scaleform::GFx::StateBagImpl *)v21, 0i64);
    v23 = v22;
  }
  else
  {
    v23 = 0i64;
  }
  v24 = (Scaleform::Render::RenderBuffer *)v2->pStateBag.pObject;
  if ( v24 )
    Scaleform::RefCountImpl::Release(v24);
  v2->pStateBag.pObject = v23;
  v25 = 0;
  v26 = &v2->KeyboardStates[0].KeyboardIndex;
  do
  {
    *v26 = v25++;
    v26 += 1672;
  }
  while ( (unsigned __int8)v25 < 6u );
  v2->pRetValHolder = 0i64;
  v27 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v2->pHeap->vfptr->Alloc)(v2->pHeap, 64i64);
  v32.pData.pObject = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v27;
  if ( v27 )
  {
    v28 = v2->pStateBag.pObject;
    if ( v28 )
      v29 = (signed __int64)&v28->vfptr;
    else
      v29 = 0i64;
    *(_QWORD *)v27 = &Scaleform::RefCountNTSImplCore::`vftable;
    *(_DWORD *)(v27 + 8) = 1;
    *(_QWORD *)v27 = &Scaleform::RefCountNTSImpl::`vftable;
    *(_QWORD *)v27 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,327>::`vftable;
    *(_QWORD *)v27 = &Scaleform::RefCountBaseNTS<Scaleform::GFx::FontManagerStates,327>::`vftable;
    *(_QWORD *)(v27 + 16) = &Scaleform::GFx::StateBag::`vftable;
    *(_QWORD *)v27 = &Scaleform::GFx::FontManagerStates::`vftable{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::FontManagerStates,327>};
    *(_QWORD *)(v27 + 16) = &Scaleform::GFx::FontManagerStates::`vftable{for `Scaleform::GFx::StateBag};
    *(_QWORD *)(v27 + 24) = 0i64;
    *(_QWORD *)(v27 + 32) = 0i64;
    *(_QWORD *)(v27 + 40) = 0i64;
    *(_QWORD *)(v27 + 48) = 0i64;
    *(_QWORD *)(v27 + 56) = v29;
  }
  else
  {
    v27 = 0i64;
  }
  v30 = (Scaleform::RefCountNTSImpl *)&v2->pFontManagerStates.pObject->vfptr;
  if ( v30 )
    Scaleform::RefCountNTSImpl::Release(v30);
  v2->pFontManagerStates.pObject = (Scaleform::GFx::FontManagerStates *)v27;
  v2->InstanceNameCount = 0;
  v2->ViewScaleX = 1.0;
  *(_QWORD *)&v2->ViewScaleY = 1065353216i64;
  v2->ViewOffsetY = 0.0;
  *(_QWORD *)&v2->ViewScaleMode = 1i64;
  v2->FocusGroupsCnt = 1;
  *(_QWORD *)v2->FocusGroupIndexes = 0i64;
  *(_QWORD *)&v2->FocusGroupIndexes[8] = 0i64;
  v2->LastIntervalTimerId = 0;
  v2->pIMECandidateListStyle = 0i64;
  v31 = Scaleform::Timer::GetTicks();
  v2->StartTickMs = (unsigned __int64)((v31 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)
                                     + ((unsigned __int64)(v31 - (v31 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)) >> 9;
  v2->PauseTickMs = 0i64;
  *(_QWORD *)&v2->SafeRect.x1 = 0i64;
  *(_QWORD *)&v2->SafeRect.x2 = 0i64;
  v2->pObjectInterface = 0i64;
  v2->LastLoadQueueEntryCnt = 0;
  v2->pUnloadListHead = 0i64;
  v2->MultitouchMode = 0;
  v2->FocusRectChanged = 1;
  v2->PreviouslyCaptured = 0;
}

// File Line: 544
// RVA: 0x8A66B0
void __fastcall Scaleform::GFx::MovieImpl::~MovieImpl(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl *v1; // rdi
  Scaleform::Render::TreeContainer *v2; // rbx
  signed __int64 v3; // rax
  unsigned int i; // ebx
  signed __int64 v5; // rsi
  Scaleform::Render::ContextImpl::Entry *v6; // rcx
  bool v7; // zf
  Scaleform::Render::ContextImpl::Entry *v8; // rcx
  Scaleform::GFx::DrawingContext *j; // rcx
  signed __int64 v10; // rax
  Scaleform::GFx::DrawingContext *v11; // rax
  signed __int64 v12; // rax
  Scaleform::Render::ContextImpl::Entry *v13; // rcx
  Scaleform::RefCountNTSImpl *v14; // rcx
  unsigned __int64 v15; // rbx
  unsigned __int64 v16; // rsi
  Scaleform::GFx::ASIntervalTimerIntf *v17; // rcx
  void **v18; // r13
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v19; // rbx
  Scaleform::GFx::LoadQueueEntryMT *v20; // rcx
  unsigned int v21; // ebp
  unsigned int v22; // esi
  Scaleform::GFx::LoadQueueEntryMT *k; // rbx
  Scaleform::GFx::LoadQueueEntry *v24; // rcx
  Scaleform::GFx::LoadQueueEntryMT *v25; // rcx
  Scaleform::GFx::Value::ObjectInterface *v26; // rbx
  signed __int64 v27; // rax
  Scaleform::GFx::Value *v28; // rbx
  void **v29; // r15
  Scaleform::GFx::Value::ObjectInterface *v30; // rcx
  Scaleform::Render::RenderBuffer *v31; // rcx
  Scaleform::Render::ContextImpl::Entry *v32; // rcx
  Scaleform::Render::RenderBuffer *v33; // rcx
  unsigned __int64 v34; // rsi
  signed __int64 l; // rbx
  Scaleform::RefCountNTSImpl *v36; // rcx
  Scaleform::RefCountNTSImpl *v37; // rcx
  Scaleform::Render::ContextImpl::Entry *v38; // rcx
  Scaleform::RefCountNTSImpl *v39; // rcx
  Scaleform::Render::RenderBuffer *v40; // rcx
  Scaleform::Render::RenderBuffer *v41; // rcx
  Scaleform::Render::RenderBuffer *v42; // rcx
  unsigned __int64 v43; // rsi
  Scaleform::GFx::MovieImpl::FontDesc *m; // rbx
  Scaleform::Render::ContextImpl::Entry *v45; // rcx
  unsigned __int64 v46; // rsi
  Scaleform::Render::RenderBuffer **n; // rbx
  unsigned __int64 v48; // rsi
  Scaleform::RefCountNTSImpl **ii; // rbx
  Scaleform::RefCountNTSImpl *v50; // rcx
  Scaleform::Render::RenderBuffer *v51; // rcx
  Scaleform::Render::RenderBuffer *v52; // rcx
  Scaleform::Render::RenderBuffer *v53; // rcx
  Scaleform::Render::RenderBuffer *v54; // rcx
  Scaleform::Render::ContextImpl::Entry *v55; // rcx
  Scaleform::Render::ContextImpl::Entry *v56; // rcx
  Scaleform::Render::RenderBuffer *v57; // rcx
  unsigned __int64 v58; // rsi
  signed __int64 jj; // rbx
  Scaleform::RefCountNTSImpl *v60; // rcx
  Scaleform::GFx::MovieDefImpl *v61; // rbx
  Scaleform::GFx::ResourceLibBase *v62; // rcx
  Scaleform::Render::RenderBuffer *v63; // rcx
  Scaleform::Render::RenderBuffer *v64; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::MovieImpl::`vftable{for `Scaleform::GFx::StateBag};
  v2 = this->FocusRectContainerNode.pObject;
  if ( v2 )
  {
    v3 = Scaleform::Render::TreeContainer::GetSize(this->FocusRectContainerNode.pObject);
    Scaleform::Render::TreeContainer::Remove(v2, 0i64, v3);
    for ( i = 0; i < v1->FocusGroupsCnt; ++i )
    {
      v5 = i;
      v6 = (Scaleform::Render::ContextImpl::Entry *)&v1->FocusGroups[v5].FocusRectNode.pObject->0;
      if ( v6 )
      {
        v7 = v6->RefCount-- == 1;
        if ( v7 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v6);
      }
      v1->FocusGroups[v5].FocusRectNode.pObject = 0i64;
    }
    v8 = (Scaleform::Render::ContextImpl::Entry *)&v1->FocusRectContainerNode.pObject->0;
    if ( v8 )
    {
      v7 = v8->RefCount-- == 1;
      if ( v7 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
    }
    v1->FocusRectContainerNode.pObject = 0i64;
  }
  for ( j = v1->DrawingContextList.Root.pNext; ; j = v11 )
  {
    v10 = (signed __int64)&v1->RegisteredFonts.Data.Size;
    if ( v1 == (Scaleform::GFx::MovieImpl *)-21248i64 )
      v10 = 0i64;
    if ( j == (Scaleform::GFx::DrawingContext *)v10 )
      break;
    v11 = j->pNext;
    j->pNext = 0i64;
    j->pPrev = 0i64;
  }
  v12 = (signed __int64)&v1->RegisteredFonts.Data.Size;
  if ( v1 == (Scaleform::GFx::MovieImpl *)-21248i64 )
    v12 = 0i64;
  v1->DrawingContextList.Root.pPrev = (Scaleform::GFx::DrawingContext *)v12;
  v1->DrawingContextList.Root.pNext = (Scaleform::GFx::DrawingContext *)v12;
  Scaleform::GFx::MovieImpl::ProcessUnloadQueue(v1);
  v13 = (Scaleform::Render::ContextImpl::Entry *)&v1->pRenderRoot.pObject->0;
  if ( v13 )
  {
    v7 = v13->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v13);
  }
  v1->pRenderRoot.pObject = 0i64;
  v14 = (Scaleform::RefCountNTSImpl *)&v1->pFontManagerStates.pObject->vfptr;
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release(v14);
  v1->pFontManagerStates.pObject = 0i64;
  v15 = 0i64;
  v16 = v1->IntervalTimers.Data.Size;
  if ( v16 )
  {
    do
    {
      v17 = v1->IntervalTimers.Data.Data[v15].pObject;
      ((void (__cdecl *)(Scaleform::GFx::ASIntervalTimerIntf *))v17->vfptr[4].__vecDelDtor)(v17);
      ++v15;
    }
    while ( v15 < v16 );
  }
  v18 = (void **)&v1->IntervalTimers.Data.Data;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy> *)&v1->IntervalTimers.Data.Data,
    &v1->IntervalTimers,
    0i64);
  v1->Flags |= 0x80000u;
  ((void (__cdecl *)(Scaleform::GFx::ASMovieRootBase *))v1->pASMovieRoot.pObject->vfptr[5].__vecDelDtor)(v1->pASMovieRoot.pObject);
  Scaleform::GFx::MovieImpl::ClearIndirectTransformPairs(v1);
  Scaleform::GFx::MovieImpl::ClearStickyVariables(v1);
  v19 = v1->pRetValHolder;
  if ( v19 )
  {
    if ( v19->CharBuffer )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(&v19->StringArray.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v19);
  }
  v20 = v1->pLoadQueueMTHead;
  v21 = 0;
  if ( v20 )
  {
    do
    {
      ++v21;
      v20->pQueueEntry->Canceled = 1;
      v20 = v20->pNext;
    }
    while ( v20 );
    if ( v21 )
    {
      do
      {
        v22 = 0;
        for ( k = v1->pLoadQueueMTHead; k; k = k->pNext )
        {
          if ( k->vfptr->LoadFinished(k) )
            ++v22;
        }
      }
      while ( v21 > v22 );
    }
  }
  while ( v1->pLoadQueueHead )
  {
    v24 = v1->pLoadQueueHead;
    v1->pLoadQueueHead = v24->pNext;
    v24->vfptr->__vecDelDtor(v24, 1u);
  }
  while ( v1->pLoadQueueMTHead )
  {
    v25 = v1->pLoadQueueMTHead;
    v1->pLoadQueueMTHead = v25->pNext;
    v25->vfptr->__vecDelDtor(v25, 1u);
  }
  v26 = v1->pObjectInterface;
  if ( v26 )
  {
    v27 = (signed __int64)&v26->ExternalObjRefs;
    if ( (Scaleform::List<Scaleform::GFx::Value,Scaleform::GFx::Value> *)v26->ExternalObjRefs.Root.pNext != &v26->ExternalObjRefs )
    {
      v28 = v26->ExternalObjRefs.Root.pNext;
      if ( v28 != (Scaleform::GFx::Value *)v27 )
      {
        do
        {
          if ( ((unsigned int)v28->Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v28->pObjectInterface->vfptr->gap8[8])(
              v28->pObjectInterface,
              v28,
              *(_QWORD *)&v28->mValue.NValue);
            v28->pObjectInterface = 0i64;
          }
          v28->Type = 32;
          v28 = v28->pNext;
        }
        while ( v28 != (Scaleform::GFx::Value *)&v1->pObjectInterface->ExternalObjRefs );
      }
    }
  }
  v29 = (void **)&v1->TopmostLevelCharacters.Data.Data;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&v1->TopmostLevelCharacters,
    &v1->TopmostLevelCharacters,
    0i64);
  v30 = v1->pObjectInterface;
  if ( v30 )
    v30->vfptr->__vecDelDtor(v30, 1u);
  ((void (__cdecl *)(Scaleform::GFx::ASMovieRootBase *))v1->pASMovieRoot.pObject->vfptr[42].__vecDelDtor)(v1->pASMovieRoot.pObject);
  v31 = (Scaleform::Render::RenderBuffer *)v1->pASMovieRoot.pObject;
  if ( v31 )
    Scaleform::RefCountImpl::Release(v31);
  v1->pASMovieRoot.pObject = 0i64;
  v32 = (Scaleform::Render::ContextImpl::Entry *)&v1->pTopMostRoot.pObject->0;
  if ( v32 )
  {
    v7 = v32->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v32);
  }
  v1->pTopMostRoot.pObject = 0i64;
  Scaleform::Render::ContextImpl::Context::Shutdown(&v1->RenderContext, 1);
  v33 = (Scaleform::Render::RenderBuffer *)v1->hDisplayRoot.pData.pObject;
  if ( v33 )
    Scaleform::RefCountImpl::Release(v33);
  v1->hDisplayRoot.pData.pObject = 0i64;
  v34 = v1->IndirectTransformPairs.Data.Size;
  for ( l = (signed __int64)&v1->IndirectTransformPairs.Data.Data[v1->IndirectTransformPairs.Data.Size - 1]; v34; --v34 )
  {
    v36 = *(Scaleform::RefCountNTSImpl **)(l + 16);
    if ( v36 )
      Scaleform::RefCountNTSImpl::Release(v36);
    v37 = *(Scaleform::RefCountNTSImpl **)(l + 8);
    if ( v37 )
      Scaleform::RefCountNTSImpl::Release(v37);
    v38 = *(Scaleform::Render::ContextImpl::Entry **)l;
    if ( *(_QWORD *)l )
    {
      v7 = v38->RefCount-- == 1;
      if ( v7 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v38);
    }
    l -= 32i64;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->IndirectTransformPairs.Data.Data);
  v39 = (Scaleform::RefCountNTSImpl *)&v1->GestureTopMostChar.pObject->vfptr;
  if ( v39 )
    Scaleform::RefCountNTSImpl::Release(v39);
  v40 = (Scaleform::Render::RenderBuffer *)v1->MultitouchHAL.pObject;
  if ( v40 )
    Scaleform::RefCountImpl::Release(v40);
  v41 = (Scaleform::Render::RenderBuffer *)v1->DIContext.pObject;
  if ( v41 )
    Scaleform::RefCountImpl::Release(v41);
  Scaleform::Render::ContextImpl::Context::~Context(&v1->RenderContext);
  v42 = (Scaleform::Render::RenderBuffer *)v1->pSavedASMovieRoot.pObject;
  if ( v42 )
    Scaleform::RefCountImpl::Release(v42);
  Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::MDKillListEntry>::DestructArray(
    v1->MovieDefKillList.Data.Data,
    v1->MovieDefKillList.Data.Size);
  if ( v1->MovieDefKillList.Data.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v43 = v1->RegisteredFonts.Data.Size;
  for ( m = &v1->RegisteredFonts.Data.Data[v1->RegisteredFonts.Data.Size - 1]; v43; --v43 )
  {
    Scaleform::GFx::MovieImpl::FontDesc::~FontDesc(m);
    --m;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->RegisteredFonts.Data.Data);
  `eh vector destructor iterator(
    v1->FocusGroups,
    0x60ui64,
    16,
    (void (__fastcall *)(void *))Scaleform::GFx::FocusGroupDescr::~FocusGroupDescr);
  v45 = (Scaleform::Render::ContextImpl::Entry *)&v1->FocusRectContainerNode.pObject->0;
  if ( v45 )
  {
    v7 = v45->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v45);
  }
  v46 = v1->IntervalTimers.Data.Size;
  for ( n = (Scaleform::Render::RenderBuffer **)((char *)*v18 + 8 * (v46 - 1)); v46; --v46 )
  {
    if ( *n )
      Scaleform::RefCountImpl::Release(*n);
    --n;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v18);
  v48 = v1->TopmostLevelCharacters.Data.Size;
  for ( ii = (Scaleform::RefCountNTSImpl **)((char *)*v29 + 8 * (v48 - 1)); v48; --v48 )
  {
    if ( *ii )
      Scaleform::RefCountNTSImpl::Release(*ii);
    --ii;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v29);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v1->StickyVariables.mHash.pTable);
  `eh vector destructor iterator(v1->KeyboardStates, 0x688ui64, 6, (void (__fastcall *)(void *))Scaleform::File::~File);
  `eh vector destructor iterator(
    v1->mMouseState,
    0x50ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::MouseState::~MouseState);
  v50 = (Scaleform::RefCountNTSImpl *)&v1->pFontManagerStates.pObject->vfptr;
  if ( v50 )
    Scaleform::RefCountNTSImpl::Release(v50);
  v51 = (Scaleform::Render::RenderBuffer *)v1->pExtIntfHandler.pObject;
  if ( v51 )
    Scaleform::RefCountImpl::Release(v51);
  v52 = (Scaleform::Render::RenderBuffer *)v1->pFSCommandHandler.pObject;
  if ( v52 )
    Scaleform::RefCountImpl::Release(v52);
  v53 = (Scaleform::Render::RenderBuffer *)v1->pUserEventHandler.pObject;
  if ( v53 )
    Scaleform::RefCountImpl::Release(v53);
  v54 = (Scaleform::Render::RenderBuffer *)v1->pCachedLog.pObject;
  if ( v54 )
    Scaleform::RefCountImpl::Release(v54);
  v55 = (Scaleform::Render::ContextImpl::Entry *)&v1->pTopMostRoot.pObject->0;
  if ( v55 )
  {
    v7 = v55->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v55);
  }
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle((Scaleform::Render::ContextImpl::RTHandle *)&v1->hDisplayRoot.pData);
  v56 = (Scaleform::Render::ContextImpl::Entry *)&v1->pRenderRoot.pObject->0;
  if ( v56 )
  {
    v7 = v56->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v56);
  }
  v57 = (Scaleform::Render::RenderBuffer *)v1->pStateBag.pObject;
  if ( v57 )
    Scaleform::RefCountImpl::Release(v57);
  v58 = v1->MovieLevels.Data.Size;
  for ( jj = (signed __int64)&v1->MovieLevels.Data.Data[v1->MovieLevels.Data.Size - 1]; v58; --v58 )
  {
    v60 = *(Scaleform::RefCountNTSImpl **)(jj + 8);
    if ( v60 )
      Scaleform::RefCountNTSImpl::Release(v60);
    jj -= 16i64;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->MovieLevels.Data.Data);
  v61 = v1->pMainMovieDef.pObject;
  if ( v61 && !_InterlockedDecrement(&v61->RefCount.Value) )
  {
    v62 = v61->pLib;
    if ( v62 )
    {
      v62->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v62->vfptr, (unsigned int)v61);
      v61->pLib = 0i64;
    }
    v61->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v61->vfptr, 1u);
  }
  v63 = (Scaleform::Render::RenderBuffer *)v1->AdvanceStats.pObject;
  if ( v63 )
    Scaleform::RefCountImpl::Release(v63);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>};
  v1->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::Movie::`vftable{for `Scaleform::GFx::StateBag};
  v64 = (Scaleform::Render::RenderBuffer *)v1->pASMovieRoot.pObject;
  if ( v64 )
    Scaleform::RefCountImpl::Release(v64);
  v1->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 723
// RVA: 0x8BC510
void __fastcall Scaleform::GFx::MovieImpl::ClearPlayList(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *v1; // r8
  Scaleform::GFx::InteractiveObject *v2; // rdx

  v1 = this->pPlayListHead;
  if ( v1 )
  {
    do
    {
      v2 = v1->pPlayNext;
      v1->pPlayPrevOpt = 0i64;
      v1->pPlayNextOpt = 0i64;
      v1->pPlayPrev = 0i64;
      v1->pPlayNext = 0i64;
      v1 = v2;
    }
    while ( v2 );
  }
  this->pPlayListHead = 0i64;
  this->pPlayListOptHead = 0i64;
}

// File Line: 734
// RVA: 0x906010
void __fastcall Scaleform::GFx::MovieImpl::SetASMovieRoot(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::ASMovieRootBase *pasmgr)
{
  Scaleform::GFx::Resource *v2; // rdi
  Scaleform::GFx::MovieImpl *v3; // rbx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx

  v2 = (Scaleform::GFx::Resource *)pasmgr;
  v3 = this;
  if ( pasmgr )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pasmgr);
  v4 = (Scaleform::Render::RenderBuffer *)v3->pSavedASMovieRoot.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v3->pSavedASMovieRoot.pObject = (Scaleform::GFx::ASMovieRootBase *)v2;
  if ( v2 )
    Scaleform::Render::RenderBuffer::AddRef(v2);
  v5 = (Scaleform::Render::RenderBuffer *)v3->pASMovieRoot.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v3->pASMovieRoot.pObject = v3->pSavedASMovieRoot.pObject;
}

// File Line: 773
// RVA: 0x8B1AD0
void __fastcall Scaleform::GFx::MovieImpl::AddLoadQueueEntry(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::LoadQueueEntry *pentry)
{
  Scaleform::GFx::LoadQueueEntry *v2; // r8
  signed __int64 v3; // rax
  bool v4; // zf

  pentry->EntryTime = ++this->LastLoadQueueEntryCnt;
  v2 = this->pLoadQueueHead;
  if ( v2 )
  {
    v3 = (signed __int64)&v2->pNext;
    if ( v2->pNext )
    {
      do
      {
        v2 = *(Scaleform::GFx::LoadQueueEntry **)v3;
        v4 = *(_QWORD *)(*(_QWORD *)v3 + 8i64) == 0i64;
        v3 = *(_QWORD *)v3 + 8i64;
      }
      while ( !v4 );
    }
    v2->pNext = pentry;
  }
  else
  {
    this->pLoadQueueHead = pentry;
  }
}

// File Line: 792
// RVA: 0x8B1B10
void __fastcall Scaleform::GFx::MovieImpl::AddLoadQueueEntryMT(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::LoadQueueEntryMT *pentryMT)
{
  Scaleform::GFx::LoadQueueEntryMT *v2; // r8
  signed __int64 v3; // rax
  bool v4; // zf

  pentryMT->pQueueEntry->EntryTime = ++this->LastLoadQueueEntryCnt;
  v2 = this->pLoadQueueMTHead;
  if ( v2 )
  {
    v3 = (signed __int64)&v2->pNext;
    if ( v2->pNext )
    {
      do
      {
        v2 = *(Scaleform::GFx::LoadQueueEntryMT **)v3;
        v4 = *(_QWORD *)(*(_QWORD *)v3 + 8i64) == 0i64;
        v3 = *(_QWORD *)v3 + 8i64;
      }
      while ( !v4 );
    }
    v2->pNext = pentryMT;
    pentryMT->pPrev = v2;
  }
  else
  {
    this->pLoadQueueMTHead = pentryMT;
  }
}

// File Line: 815
// RVA: 0x8C00B0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::MovieImpl::CreateImageMovieDef(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::ImageResource *pimageResource, bool bilinear, const char *purl, Scaleform::GFx::LoadStates *pls)
{
  const char *v5; // rbx
  bool v6; // r13
  Scaleform::GFx::ImageResource *v7; // r12
  Scaleform::GFx::MovieImpl *v8; // r15
  __int64 v9; // rdi
  __int64 v10; // rbp
  Scaleform::GFx::LoadStates *v11; // rsi
  Scaleform::GFx::LoadStates *v12; // r10
  Scaleform::GFx::StateBagImpl *v13; // rcx
  Scaleform::GFx::StateBag *v14; // r8
  Scaleform::GFx::LoadStates *v15; // rax
  Scaleform::MemoryHeap *v16; // r14
  Scaleform::GFx::LoadStates *v17; // rcx
  Scaleform::GFx::MovieDataDef *v18; // rax
  Scaleform::GFx::MovieDataDef *v19; // rax
  Scaleform::GFx::MovieDataDef *v20; // rbx
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *v21; // rbp
  Scaleform::GFx::LogState *v22; // rax
  Scaleform::Log *v23; // rax
  bool v24; // bp
  Scaleform::GFx::MovieDefImpl *v25; // r10
  __int64 v26; // rax
  Scaleform::GFx::ResourceLibBase *v27; // rcx
  Scaleform::GFx::ResourceLibBase *v28; // rcx
  Scaleform::GFx::ResourceKey result; // [rsp+70h] [rbp-38h]
  Scaleform::Render::RenderBuffer *v31; // [rsp+B8h] [rbp+10h]

  v5 = purl;
  v6 = bilinear;
  v7 = pimageResource;
  v8 = this;
  v9 = 0i64;
  v10 = 0i64;
  v31 = 0i64;
  v11 = pls;
  if ( !pls )
  {
    v12 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          144ui64,
                                          0i64);
    pls = v12;
    if ( v12 )
    {
      v13 = v8->pStateBag.pObject;
      v14 = (Scaleform::GFx::StateBag *)&v13->vfptr;
      if ( !v13 )
        v14 = 0i64;
      Scaleform::GFx::LoadStates::LoadStates(v12, v8->pMainMovieDef.pObject->pLoaderImpl.pObject, v14, 0i64);
      v11 = v15;
    }
    else
    {
      v11 = 0i64;
    }
    v31 = (Scaleform::Render::RenderBuffer *)v11;
  }
  if ( !v7 )
    goto LABEL_40;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(&result, v5, 0i64, 0i64, 0i64);
  v16 = v8->pHeap;
  v17 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap;
  if ( v16 )
    v17 = (Scaleform::GFx::LoadStates *)v8->pHeap;
  pls = v17;
  v18 = (Scaleform::GFx::MovieDataDef *)v17->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v17->vfptr, 72u);
  if ( v18 )
  {
    Scaleform::GFx::MovieDataDef::MovieDataDef(v18, &result, MT_Image, v5, v16, 0, 0i64);
    v20 = v19;
  }
  else
  {
    v20 = 0i64;
  }
  if ( v20 )
  {
    v21 = Scaleform::GFx::StateBag::GetImageCreator(
            (Scaleform::GFx::StateBag *)&v8->vfptr,
            (Scaleform::Ptr<Scaleform::GFx::ImageCreator> *)&pls);
    v22 = v11->pLog.pObject;
    if ( v22 )
    {
      v23 = v22->pLog.pObject;
      if ( !v23 )
        v23 = Scaleform::Log::GetGlobalLog();
    }
    else
    {
      v23 = 0i64;
    }
    v24 = Scaleform::GFx::MovieDataDef::LoadTaskData::InitImageFileMovieDef(
            v20->pData.pObject,
            0,
            v7,
            v21->pObject,
            v23,
            v6) == 0;
    if ( pls )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pls);
    if ( !v24 )
    {
      Scaleform::String::operator=(
        &v11->RelativePath,
        (const char *)((v20->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( !Scaleform::GFx::URLBuilder::ExtractFilePath(&v11->RelativePath) )
        Scaleform::String::Clear(&v11->RelativePath);
      v25 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v16->vfptr->Alloc)(
                                              v16,
                                              112i64);
      if ( v25 )
      {
        Scaleform::GFx::MovieDefImpl::MovieDefImpl(
          v25,
          v20,
          v11->pBindStates.pObject,
          v11->pLoaderImpl.pObject,
          0,
          v8->pStateBag.pObject->pDelegate.pObject,
          v16,
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
        v27 = v20->pLib;
        if ( v27 )
        {
          v27->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v27->vfptr, (unsigned int)v20);
          v20->pLib = 0i64;
        }
        v20->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v20->vfptr, 1u);
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
      v28->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v28->vfptr, (unsigned int)v20);
      v20->pLib = 0i64;
    }
    v20->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v20->vfptr, 1u);
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
  Scaleform::GFx::MovieImpl *v1; // rdi
  unsigned int v2; // ebp
  Scaleform::GFx::LoadQueueEntry *v3; // rsi
  Scaleform::GFx::LoadStates *v4; // r10
  Scaleform::GFx::StateBagImpl *v5; // rcx
  Scaleform::GFx::StateBag *v6; // r8
  Scaleform::Render::RenderBuffer *v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rbx
  Scaleform::GFx::LoadQueueEntryMT *v9; // rbx
  Scaleform::GFx::LoadQueueEntryMT *v10; // rbx
  Scaleform::GFx::LoadQueueEntryMT *v11; // rsi
  Scaleform::GFx::LoadQueueEntryMT *v12; // rax

  v1 = this;
  v2 = this->LastLoadQueueEntryCnt;
  while ( v1->pLoadQueueHead )
  {
    v3 = v1->pLoadQueueHead;
    if ( v3->EntryTime > v2 )
      break;
    v1->pLoadQueueHead = v3->pNext;
    v4 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                         Scaleform::Memory::pGlobalHeap,
                                         144ui64,
                                         0i64);
    if ( v4 )
    {
      v5 = v1->pStateBag.pObject;
      if ( v5 )
        v6 = (Scaleform::GFx::StateBag *)&v5->vfptr;
      else
        v6 = 0i64;
      Scaleform::GFx::LoadStates::LoadStates(v4, v1->pMainMovieDef.pObject->pLoaderImpl.pObject, v6, 0i64);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::LoadQueueEntry *, Scaleform::Render::RenderBuffer *))v1->pASMovieRoot.pObject->vfptr[35].__vecDelDtor)(
      v1->pASMovieRoot.pObject,
      v3,
      v8);
    v3->vfptr->__vecDelDtor(v3, 1u);
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
  }
  v9 = v1->pLoadQueueMTHead;
  if ( v9 )
  {
    while ( v9->vfptr->IsPreloadingFinished(v9) )
    {
      v9 = v9->pNext;
      if ( !v9 )
        goto LABEL_15;
    }
  }
  else
  {
LABEL_15:
    v10 = v1->pLoadQueueMTHead;
    while ( v10 )
    {
      if ( v10->vfptr->LoadFinished(v10) )
      {
        v11 = v10->pNext;
        if ( v11 )
          v11->pPrev = v10->pPrev;
        v12 = v10->pPrev;
        if ( v12 )
          v12->pNext = v11;
        if ( v1->pLoadQueueMTHead == v10 )
          v1->pLoadQueueMTHead = v11;
        v10->vfptr->__vecDelDtor(v10, 1u);
        v10 = v11;
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
void __fastcall Scaleform::GFx::MovieImpl::DragState::InitCenterDelta(Scaleform::GFx::MovieImpl::DragState *this, bool lockCenter, unsigned int mouseIndex)
{
  __int64 v3; // rsi
  Scaleform::GFx::MovieImpl::DragState *v4; // rdi
  Scaleform::GFx::InteractiveObject *v5; // r14
  Scaleform::GFx::InteractiveObject *v6; // rbx
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
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float *v24; // rax
  signed __int64 v25; // rax
  float v26; // xmm9_4
  float v27; // xmm8_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  __int64 v30; // rax
  float v31; // xmm1_4
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+18h] [rbp-59h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+38h] [rbp-39h]

  v3 = mouseIndex;
  v4 = this;
  this->LockCenter = lockCenter;
  this->MouseIndex = mouseIndex;
  if ( !lockCenter )
  {
    v5 = this->pCharacter;
    v6 = this->pCharacter->pParent;
    *(_OWORD *)&pmat.M[0][0] = _xmm;
    *(__m128 *)&pmat.M[1][0] = _xmm;
    if ( v6 )
    {
      *(_OWORD *)&pmat.M[0][0] = _xmm;
      *(__m128 *)&pmat.M[1][0] = _xmm;
      v7 = v6->pParentChar;
      if ( v7 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v7, &pmat);
        v8 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v6->vfptr[2].__vecDelDtor)(v6);
        v10 = pmat.M[0][1];
        v9 = pmat.M[0][0];
        v11 = pmat.M[1][0];
        v12 = 0.0;
        v13 = pmat.M[0][0];
        v14 = pmat.M[1][1];
        v15 = pmat.M[1][0];
        v16 = 0.0;
        v17 = (float)(pmat.M[0][0] * *v8) + (float)(pmat.M[0][1] * v8[4]);
        pmat.M[0][0] = (float)(pmat.M[0][0] * *v8) + (float)(pmat.M[0][1] * v8[4]);
        v18 = (float)(pmat.M[1][0] * *v8) + (float)(pmat.M[1][1] * v8[4]);
        pmat.M[1][0] = (float)(pmat.M[1][0] * *v8) + (float)(pmat.M[1][1] * v8[4]);
        v19 = (float)(v13 * v8[1]) + (float)(pmat.M[0][1] * v8[5]);
        *(_QWORD *)&pmat.M[0][1] = LODWORD(v19);
        v20 = (float)(v15 * v8[1]) + (float)(pmat.M[1][1] * v8[5]);
        *(_QWORD *)&pmat.M[1][1] = LODWORD(v20);
        v21 = (float)(v10 * v8[7]) + (float)(v9 * v8[3]);
        v22 = pmat.M[0][3] + v21;
        pmat.M[0][3] = pmat.M[0][3] + v21;
        v23 = pmat.M[1][3] + (float)((float)(v14 * v8[7]) + (float)(v11 * v8[3]));
      }
      else
      {
        v24 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v6->vfptr[2].__vecDelDtor)(v6);
        v17 = *v24;
        pmat.M[0][0] = *v24;
        v19 = v24[1];
        pmat.M[0][1] = v24[1];
        v16 = v24[2];
        pmat.M[0][2] = v24[2];
        v22 = v24[3];
        pmat.M[0][3] = v24[3];
        v18 = v24[4];
        pmat.M[1][0] = v24[4];
        v20 = v24[5];
        pmat.M[1][1] = v24[5];
        v12 = v24[6];
        pmat.M[1][2] = v24[6];
        v23 = v24[7];
      }
    }
    else
    {
      v23 = pmat.M[1][3];
      v12 = pmat.M[1][2];
      v20 = pmat.M[1][1];
      v18 = pmat.M[1][0];
      v22 = pmat.M[0][3];
      v16 = pmat.M[0][2];
      v19 = pmat.M[0][1];
      v17 = pmat.M[0][0];
    }
    if ( (unsigned int)v3 < 6 )
      v25 = (signed __int64)&v5->pASRoot->pMovieImpl->mMouseState[v3];
    else
      v25 = 0i64;
    v26 = *(float *)(v25 + 56);
    v27 = *(float *)(v25 + 60);
    *(_QWORD *)&pmat.M[0][2] = __PAIR__(LODWORD(v22), LODWORD(v16));
    *(_QWORD *)&pmat.M[1][0] = __PAIR__(LODWORD(v20), LODWORD(v18));
    *(_QWORD *)&pmat.M[1][2] = __PAIR__(LODWORD(v23), LODWORD(v12));
    *(_QWORD *)&m.M[0][0] = __PAIR__(LODWORD(v19), LODWORD(v17));
    *(_QWORD *)&m.M[0][2] = __PAIR__(LODWORD(v22), LODWORD(v16));
    *(_QWORD *)&m.M[1][0] = __PAIR__(LODWORD(v20), LODWORD(v18));
    *(_QWORD *)&m.M[1][2] = __PAIR__(LODWORD(v23), LODWORD(v12));
    Scaleform::Render::Matrix2x4<float>::SetInverse(&pmat, &m);
    v28 = (float)((float)(pmat.M[0][1] * v27) + (float)(pmat.M[0][0] * v26)) + pmat.M[0][3];
    v29 = (float)((float)(pmat.M[1][1] * v27) + (float)(pmat.M[1][0] * v26)) + pmat.M[1][3];
    v30 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v5->vfptr[2].__vecDelDtor)(v5);
    v31 = *(float *)(v30 + 28) - v29;
    v4->CenterDelta.x = *(float *)(v30 + 12) - v28;
    v4->CenterDelta.y = v31;
  }
}

// File Line: 966
// RVA: 0x90EE40
void __fastcall Scaleform::GFx::MovieImpl::SetViewport(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::Viewport *viewDesc)
{
  Scaleform::Render::Viewport *v2; // rdi
  Scaleform::GFx::Viewport *v3; // rsi
  Scaleform::GFx::MovieImpl *v4; // rbx
  int v5; // ebp
  int v6; // er12
  int v7; // er14
  int v8; // er15
  float v9; // xmm7_4
  float v10; // xmm11_4
  float v11; // xmm6_4
  float v12; // xmm9_4
  float v13; // xmm8_4
  float v14; // xmm10_4
  Scaleform::GFx::Movie::ScaleModeType v15; // eax

  v2 = (Scaleform::Render::Viewport *)&this->mViewport.BufferWidth;
  v3 = viewDesc;
  v4 = this;
  if ( memcmp(viewDesc, &this->mViewport, 0x34ui64) )
  {
    v5 = v4->mViewport.Height;
    v6 = v4->mViewport.Left;
    v7 = v4->mViewport.Width;
    v8 = v4->mViewport.Top;
    v9 = v4->mViewport.AspectRatio;
    v10 = v4->mViewport.Scale;
    v4->Flags |= 1u;
    v2->BufferWidth = v3->BufferWidth;
    v2->BufferHeight = v3->BufferHeight;
    v2->Left = v3->Left;
    v2->Top = v3->Top;
    v2->Width = v3->Width;
    v2->Height = v3->Height;
    v2->ScissorLeft = v3->ScissorLeft;
    v2->ScissorTop = v3->ScissorTop;
    v2->ScissorWidth = v3->ScissorWidth;
    v2->ScissorHeight = v3->ScissorHeight;
    v2->Flags = v3->Flags;
    v2[1].BufferWidth = LODWORD(v3->Scale);
    v2[1].BufferHeight = LODWORD(v3->AspectRatio);
    v11 = v4->VisibleFrameRect.x1;
    v12 = v4->VisibleFrameRect.y1;
    v13 = v4->VisibleFrameRect.x2;
    v14 = v4->VisibleFrameRect.y2;
    Scaleform::GFx::MovieImpl::UpdateViewport(v4);
    if ( v11 != v4->VisibleFrameRect.x1
      || v13 != v4->VisibleFrameRect.x2
      || v12 != v4->VisibleFrameRect.y1
      || v14 != v4->VisibleFrameRect.y2
      || (v15 = v4->ViewScaleMode) == 0
      && (v7 != v4->mViewport.Width
       || v5 != v4->mViewport.Height
       || v6 != v4->mViewport.Left
       || v8 != v4->mViewport.Top
       || v10 != v4->mViewport.Scale
       || v9 != v4->mViewport.AspectRatio)
      || v15 != 2 && (v7 != v4->mViewport.Width || v5 != v4->mViewport.Height || v9 != v4->mViewport.AspectRatio) )
    {
      ((void (*)(void))v4->pASMovieRoot.pObject->vfptr[19].__vecDelDtor)();
    }
    Scaleform::Render::TreeRoot::SetViewport(v4->pRenderRoot.pObject, v2);
    Scaleform::Render::TreeRoot::SetBackgroundColor(v4->pRenderRoot.pObject, &v4->BackgroundColor);
    Scaleform::Render::TreeNode::SetMatrix(
      (Scaleform::Render::TreeNode *)&v4->pRenderRoot.pObject->0,
      &v4->ViewportMatrix);
  }
}

// File Line: 1018
// RVA: 0x906360
void __fastcall Scaleform::GFx::MovieImpl::SetBackgroundColor(Scaleform::GFx::MovieImpl *this, __int64 color)
{
  this->BackgroundColor.Raw = *(_DWORD *)color;
  Scaleform::Render::TreeRoot::SetBackgroundColor(this->pRenderRoot.pObject, &this->BackgroundColor);
}

// File Line: 1024
// RVA: 0x906310
void __fastcall Scaleform::GFx::MovieImpl::SetBackgroundAlpha(Scaleform::GFx::MovieImpl *this, float alpha)
{
  char v2; // r8

  v2 = -1;
  if ( (unsigned __int8)(signed int)(float)(alpha * 255.0) < 0xFFu )
    v2 = (signed int)(float)(alpha * 255.0);
  this->BackgroundColor.Channels.Alpha = v2;
  Scaleform::Render::TreeRoot::SetBackgroundColor(this->pRenderRoot.pObject, &this->BackgroundColor);
}

// File Line: 1030
// RVA: 0x9189B0
void __fastcall Scaleform::GFx::MovieImpl::UpdateViewport(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieDefImpl *v1; // r8
  float v2; // xmm6_4
  float v3; // xmm7_4
  Scaleform::GFx::MovieImpl *v4; // rbx
  float v5; // xmm12_4
  float v6; // xmm11_4
  float v7; // xmm10_4
  float v8; // xmm15_4
  float v9; // xmm14_4
  float v10; // xmm13_4
  int v11; // edx
  float v12; // xmm1_4
  int v13; // eax
  Scaleform::GFx::Movie::ScaleModeType v14; // edx
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
  float v31; // xmm2_4
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
  float v42; // [rsp+C8h] [rbp+10h]
  float v43; // [rsp+D0h] [rbp+18h]

  v1 = this->pMainMovieDef.pObject;
  v2 = this->VisibleFrameRect.y2;
  v3 = this->VisibleFrameRect.y1;
  v4 = this;
  v5 = this->ViewScaleX;
  v6 = this->ViewScaleY;
  v7 = this->PixelScale;
  v8 = this->VisibleFrameRect.x2;
  v9 = this->ViewOffsetX;
  v10 = this->ViewOffsetY;
  v43 = this->VisibleFrameRect.x1;
  v42 = this->VisibleFrameRect.y1;
  v41 = this->VisibleFrameRect.y2;
  if ( !v1 )
  {
    this->ViewScaleY = 1.0;
    this->ViewScaleX = 1.0;
    *(_QWORD *)&this->ViewOffsetX = 0i64;
    this->PixelScale = 1.0;
    goto LABEL_47;
  }
  v11 = this->mViewport.Top;
  v12 = (float)v11 * 20.0;
  v13 = v11 + this->mViewport.Height;
  v14 = this->ViewScaleMode;
  v15 = (float)v13;
  v16 = (float)((float)(this->mViewport.Left + this->mViewport.Width) * 20.0)
      - (float)((float)this->mViewport.Left * 20.0);
  v17 = (float *)v1->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v18 = (float)(v15 * 20.0) - v12;
  v19 = v17[26] - v17[24];
  v20 = v17[27] - v17[25];
  switch ( v14 )
  {
    case 0:
      v31 = this->mViewport.Scale;
      v32 = (float)(v16 * this->mViewport.AspectRatio) * v31;
      v33 = v31 * v18;
      switch ( this->ViewAlignment )
      {
        case 0:
          this->VisibleFrameRect.x1 = (float)(20
                                            * (signed int)(float)((float)((float)(v19 * 0.5) - (float)(v32 * 0.5))
                                                                * 0.050000001));
          v34 = (float)(v20 * 0.5) - (float)(v33 * 0.5);
          goto LABEL_35;
        case 1:
          this->VisibleFrameRect.y1 = 0.0;
          this->VisibleFrameRect.x1 = (float)(20
                                            * (signed int)(float)((float)((float)(v19 * 0.5) - (float)(v32 * 0.5))
                                                                * 0.050000001));
          break;
        case 2:
          this->VisibleFrameRect.y1 = v20 - v33;
          this->VisibleFrameRect.x1 = (float)(20
                                            * (signed int)(float)((float)((float)(v19 * 0.5) - (float)(v32 * 0.5))
                                                                * 0.050000001));
          break;
        case 3:
          this->VisibleFrameRect.x1 = 0.0;
          goto LABEL_34;
        case 4:
          this->VisibleFrameRect.x1 = v19 - v32;
LABEL_34:
          v34 = (float)(v20 * 0.5) - (float)(v33 * 0.5);
LABEL_35:
          this->VisibleFrameRect.y1 = (float)(20 * (signed int)(float)(v34 * 0.050000001));
          break;
        case 5:
          *(_QWORD *)&this->VisibleFrameRect.x1 = 0i64;
          break;
        case 6:
          this->VisibleFrameRect.x1 = v19 - v32;
          this->VisibleFrameRect.y1 = 0.0;
          break;
        case 7:
          this->VisibleFrameRect.y1 = v20 - v33;
          this->VisibleFrameRect.x1 = 0.0;
          break;
        case 8:
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
    case 1:
      goto LABEL_59;
    case 2:
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
    case 3:
LABEL_59:
      v21 = v16 * this->mViewport.AspectRatio;
      if ( (v14 != 1 || (float)(v21 / v19) >= (float)(v18 / v20))
        && (v14 != 3 || (float)(v21 / v19) <= (float)(v18 / v20)) )
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
      else
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
LABEL_37:
      v2 = v41;
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
  v3 = v42;
  this->PixelScale = v38;
LABEL_47:
  Scaleform::GFx::MovieImpl::ResetViewportMatrix(this);
  if ( v43 != v4->VisibleFrameRect.x1
    || v8 != v4->VisibleFrameRect.x2
    || v3 != v4->VisibleFrameRect.y1
    || v2 != v4->VisibleFrameRect.y2
    || v9 != v4->ViewOffsetX
    || v10 != v4->ViewOffsetY
    || v5 != v4->ViewScaleX
    || v6 != v4->ViewScaleY
    || v7 != v4->PixelScale )
  {
    Scaleform::GFx::MovieImpl::UpdateViewAndPerspective(v4);
  }
}

// File Line: 1184
// RVA: 0x901770
void __fastcall Scaleform::GFx::MovieImpl::ResetViewportMatrix(Scaleform::GFx::MovieImpl *this)
{
  float v1; // xmm4_4
  float v2; // xmm5_4
  float v3; // xmm4_4
  float v4; // xmm5_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm2_4

  v1 = this->VisibleFrameRect.x1;
  v2 = this->VisibleFrameRect.y1;
  *(_QWORD *)&this->ViewportMatrix.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->ViewportMatrix.M[1][1] = 1065353216i64;
  LODWORD(v3) = LODWORD(v1) ^ _xmm[0];
  LODWORD(v4) = LODWORD(v2) ^ _xmm[0];
  this->ViewportMatrix.M[0][2] = 0.0;
  this->ViewportMatrix.M[1][0] = 0.0;
  this->ViewportMatrix.M[0][3] = v3;
  this->ViewportMatrix.M[1][3] = v4;
  v5 = (float)this->mViewport.Width;
  v6 = (float)this->mViewport.Height / (float)(this->VisibleFrameRect.y2 - this->VisibleFrameRect.y1);
  v7 = this->VisibleFrameRect.x2 - this->VisibleFrameRect.x1;
  this->ViewportMatrix.M[1][1] = v6;
  this->ViewportMatrix.M[1][3] = v4 * v6;
  v8 = v5 / v7;
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
  Scaleform::GFx::MovieImpl *v1; // rbx

  v1 = this;
  Scaleform::GFx::MovieImpl::ResetViewportMatrix(this);
  Scaleform::Render::TreeNode::SetMatrix(
    (Scaleform::Render::TreeNode *)&v1->pRenderRoot.pObject->0,
    &v1->ViewportMatrix);
}

// File Line: 1202
// RVA: 0x8EB2D0
void __fastcall Scaleform::GFx::MovieImpl::MakeViewAndPersp3D(Scaleform::Render::Matrix3x4<float> *matView, Scaleform::Render::Matrix4x4<float> *matPersp, Scaleform::Render::Rect<float> *frameRect, Scaleform::Render::Point<float> *projCenter, float fieldOfView, float focalLength, bool bInvertY)
{
  float v7; // xmm4_4
  Scaleform::Render::Matrix4x4<float> *v8; // rbx
  float v9; // xmm10_4
  float v10; // xmm7_4
  Scaleform::Render::Matrix3x4<float> *v11; // rsi
  float v12; // xmm8_4
  float fNearZ; // xmm9_4
  float fFarZ; // xmm6_4
  float v15; // xmm14_4
  __int128 v16; // xmm15
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
  Scaleform::Render::Point3<float> upVec; // [rsp+40h] [rbp-D8h]
  Scaleform::Render::Point3<float> eyePt; // [rsp+50h] [rbp-C8h]
  Scaleform::Render::Point3<float> zAxis; // [rsp+60h] [rbp-B8h]

  v7 = *(float *)&FLOAT_1_0;
  v8 = matPersp;
  v9 = frameRect->x2;
  v10 = focalLength;
  v11 = matView;
  LODWORD(v12) = COERCE_UNSIGNED_INT(v9 - frameRect->x1) & _xmm;
  if ( focalLength == 0.0 )
    fNearZ = *(float *)&FLOAT_1_0;
  else
    fNearZ = focalLength * 0.0099999998;
  if ( focalLength == 0.0 )
  {
    fFarZ = FLOAT_100000_0;
    if ( v12 > 100000.0 )
      LODWORD(fFarZ) = COERCE_UNSIGNED_INT(v9 - frameRect->x1) & _xmm;
  }
  else
  {
    fFarZ = focalLength * 100.0;
  }
  v15 = projCenter->x;
  v16 = LODWORD(projCenter->y);
  viewMaxY = projCenter->y - frameRect->y1;
  v18 = v12 * 0.5;
  v19 = _xmm[0];
  LODWORD(v20) = COERCE_UNSIGNED_INT(projCenter->x - frameRect->x1) ^ _xmm[0];
  LODWORD(v21) = COERCE_UNSIGNED_INT(frameRect->y2 - *(float *)&v16) ^ _xmm[0];
  v22 = v9 - projCenter->x;
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
  if ( v11 )
  {
    LODWORD(v24) = LODWORD(fFarZ) ^ v19;
    if ( COERCE_FLOAT(LODWORD(v10) ^ v19) >= COERCE_FLOAT(LODWORD(fFarZ) ^ v19) )
      LODWORD(v24) = LODWORD(v10) ^ v19;
    eyePt.x = v15;
    LODWORD(eyePt.y) = v16;
    eyePt.z = v24;
    if ( bInvertY )
      v25 = v7;
    else
      v25 = FLOAT_N1_0;
    v26 = v15 - v15;
    *(float *)&v16 = *(float *)&v16 - *(float *)&v16;
    upVec.y = v25;
    upVec.x = 0.0;
    upVec.z = 0.0;
    v27 = (__m128)v16;
    v27.m128_f32[0] = (float)(*(float *)&v16 * *(float *)&v16) + (float)(v26 * v26);
    if ( bInvertY )
      LODWORD(v24) ^= v19;
    v27.m128_f32[0] = v27.m128_f32[0] + (float)(v24 * v24);
    v28 = v7 / COERCE_FLOAT(_mm_sqrt_ps(v27));
    zAxis.x = v26 * v28;
    zAxis.y = *(float *)&v16 * v28;
    zAxis.z = v24 * v28;
    Scaleform::Render::Matrix3x4<float>::View(v11, &eyePt, &zAxis, &upVec);
  }
  if ( v8 )
  {
    if ( fieldOfView > 0.0 )
    {
      if ( bInvertY )
        Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterLH(v8, v10, v20, v22, v21, viewMaxY, fNearZ, fFarZ);
      else
        Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterRH(v8, v10, v20, v22, v21, viewMaxY, fNearZ, fFarZ);
    }
    else if ( bInvertY )
    {
      Scaleform::Render::Matrix4x4<float>::OrthoOffCenterLH(v8, v20, v22, v21, viewMaxY, fNearZ, fFarZ);
    }
    else
    {
      Scaleform::Render::Matrix4x4<float>::OrthoOffCenterRH(v8, v20, v22, v21, viewMaxY, fNearZ, fFarZ);
    }
  }
}

// File Line: 1259
// RVA: 0x918940
void __fastcall Scaleform::GFx::MovieImpl::UpdateViewAndPerspective(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl *v1; // rdi
  unsigned int v2; // ebx
  __int64 v3; // rcx
  Scaleform::GFx::InteractiveObject *v4; // rcx

  v1 = this;
  if ( this->VisibleFrameRect.x1 != this->VisibleFrameRect.x2 || this->VisibleFrameRect.y1 != this->VisibleFrameRect.y2 )
  {
    v2 = 0;
    if ( this->MovieLevels.Data.Size )
    {
      v3 = 0i64;
      do
      {
        v4 = v1->MovieLevels.Data.Data[v3].pSprite.pObject;
        if ( v4 )
          ((void (*)(void))v4->vfptr[12].__vecDelDtor)();
        v3 = ++v2;
      }
      while ( v2 < v1->MovieLevels.Data.Size );
    }
  }
}

// File Line: 1273
// RVA: 0x8E1680
void __fastcall Scaleform::GFx::MovieImpl::GetViewMatrix3D(Scaleform::GFx::MovieImpl *this, Scaleform::Render::Matrix3x4<float> *viewMat)
{
  Scaleform::Render::Matrix3x4<float> *v2; // rbx
  void *v3; // rax

  v2 = viewMat;
  v3 = this->pASMovieRoot.pObject->vfptr[16].__vecDelDtor((Scaleform::RefCountImplCore *)this->pASMovieRoot.pObject, 0);
  if ( v3 )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix3x4<float> *, _QWORD))(*(_QWORD *)v3 + 72i64))(
      v3,
      v2,
      0i64);
}

// File Line: 1281
// RVA: 0x90ECB0
void __fastcall Scaleform::GFx::MovieImpl::SetViewMatrix3D(Scaleform::GFx::MovieImpl *this, Scaleform::Render::Matrix3x4<float> *viewMat)
{
  Scaleform::Render::Matrix3x4<float> *v2; // rbx
  void *v3; // rax

  v2 = viewMat;
  v3 = this->pASMovieRoot.pObject->vfptr[16].__vecDelDtor((Scaleform::RefCountImplCore *)this->pASMovieRoot.pObject, 0);
  if ( v3 )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix3x4<float> *))(*(_QWORD *)v3 + 80i64))(v3, v2);
}

// File Line: 1289
// RVA: 0x8DC510
void __fastcall Scaleform::GFx::MovieImpl::GetProjectionMatrix3D(Scaleform::GFx::MovieImpl *this, Scaleform::Render::Matrix4x4<float> *projMat)
{
  Scaleform::Render::Matrix4x4<float> *v2; // rbx
  void *v3; // rax

  v2 = projMat;
  v3 = this->pASMovieRoot.pObject->vfptr[16].__vecDelDtor((Scaleform::RefCountImplCore *)this->pASMovieRoot.pObject, 0);
  if ( v3 )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix4x4<float> *, _QWORD))(*(_QWORD *)v3 + 48i64))(
      v3,
      v2,
      0i64);
}

// File Line: 1297
// RVA: 0x90A100
void __fastcall Scaleform::GFx::MovieImpl::SetProjectionMatrix3D(Scaleform::GFx::MovieImpl *this, Scaleform::Render::Matrix4x4<float> *projMat)
{
  Scaleform::Render::Matrix4x4<float> *v2; // rbx
  void *v3; // rax

  v2 = projMat;
  v3 = this->pASMovieRoot.pObject->vfptr[16].__vecDelDtor((Scaleform::RefCountImplCore *)this->pASMovieRoot.pObject, 0);
  if ( v3 )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix4x4<float> *))(*(_QWORD *)v3 + 56i64))(v3, v2);
}

// File Line: 1304
// RVA: 0x8E1790
void __fastcall Scaleform::GFx::MovieImpl::GetViewport(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::Viewport *pviewDesc)
{
  pviewDesc->BufferWidth = this->mViewport.BufferWidth;
  pviewDesc->BufferHeight = this->mViewport.BufferHeight;
  pviewDesc->Left = this->mViewport.Left;
  pviewDesc->Top = this->mViewport.Top;
  pviewDesc->Width = this->mViewport.Width;
  pviewDesc->Height = this->mViewport.Height;
  pviewDesc->ScissorLeft = this->mViewport.ScissorLeft;
  pviewDesc->ScissorTop = this->mViewport.ScissorTop;
  pviewDesc->ScissorWidth = this->mViewport.ScissorWidth;
  pviewDesc->ScissorHeight = this->mViewport.ScissorHeight;
  pviewDesc->Flags = this->mViewport.Flags;
  pviewDesc->Scale = this->mViewport.Scale;
  pviewDesc->AspectRatio = this->mViewport.AspectRatio;
}

// File Line: 1309
// RVA: 0x90ECF0
void __fastcall Scaleform::GFx::MovieImpl::SetViewScaleMode(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::Movie::ScaleModeType scaleMode)
{
  Scaleform::GFx::MovieImpl *v2; // rbx
  Scaleform::GFx::UserEventHandler *v3; // rcx
  Scaleform::GFx::Movie::ScaleModeType v4; // edi
  int v5; // xmm0_4
  int v6; // xmm1_4
  int v7; // eax
  int v8; // eax
  int v9; // [rsp+20h] [rbp-48h]
  int v10; // [rsp+24h] [rbp-44h]
  int v11; // [rsp+28h] [rbp-40h]
  int v12; // [rsp+2Ch] [rbp-3Ch]
  int v13; // [rsp+30h] [rbp-38h]
  int v14; // [rsp+34h] [rbp-34h]
  int v15; // [rsp+38h] [rbp-30h]
  int v16; // [rsp+3Ch] [rbp-2Ch]
  int v17; // [rsp+40h] [rbp-28h]
  int v18; // [rsp+44h] [rbp-24h]
  unsigned int v19; // [rsp+48h] [rbp-20h]
  int v20; // [rsp+4Ch] [rbp-1Ch]
  int v21; // [rsp+50h] [rbp-18h]
  int v22; // [rsp+70h] [rbp+8h]
  char v23; // [rsp+74h] [rbp+Ch]

  v2 = this;
  v3 = this->pUserEventHandler.pObject;
  v4 = scaleMode;
  if ( v3 )
  {
    v23 = 0;
    v22 = 25 - (scaleMode != 0);
    ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))v3->vfptr[1].__vecDelDtor)(
      v3,
      v2,
      &v22);
  }
  v2->ViewScaleMode = v4;
  v5 = LODWORD(v2->mViewport.Scale);
  v6 = LODWORD(v2->mViewport.AspectRatio);
  v9 = v2->mViewport.BufferWidth;
  v7 = v2->mViewport.BufferHeight;
  v20 = v5;
  v21 = v6;
  v10 = v7;
  v11 = v2->mViewport.Left;
  v12 = v2->mViewport.Top;
  v13 = v2->mViewport.Width;
  v14 = v2->mViewport.Height;
  v19 = v2->mViewport.Flags;
  v15 = v2->mViewport.ScissorLeft;
  v16 = v2->mViewport.ScissorTop;
  v17 = v2->mViewport.ScissorWidth;
  v8 = v2->mViewport.ScissorHeight;
  ++v2->mViewport.Flags;
  v18 = v8;
  v2->vfptr[12].__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, (unsigned int)&v9);
}

// File Line: 1321
// RVA: 0x90E8E0
void __fastcall Scaleform::GFx::MovieImpl::SetViewAlignment(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::Movie::AlignType align)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  int v4; // eax
  int v5; // eax
  int v6; // [rsp+20h] [rbp-48h]
  int v7; // [rsp+24h] [rbp-44h]
  int v8; // [rsp+28h] [rbp-40h]
  int v9; // [rsp+2Ch] [rbp-3Ch]
  int v10; // [rsp+30h] [rbp-38h]
  int v11; // [rsp+34h] [rbp-34h]
  int v12; // [rsp+38h] [rbp-30h]
  int v13; // [rsp+3Ch] [rbp-2Ch]
  int v14; // [rsp+40h] [rbp-28h]
  int v15; // [rsp+44h] [rbp-24h]
  unsigned int v16; // [rsp+48h] [rbp-20h]
  float v17; // [rsp+4Ch] [rbp-1Ch]
  float v18; // [rsp+50h] [rbp-18h]

  this->ViewAlignment = align;
  v2 = this->mViewport.Scale;
  v3 = this->mViewport.AspectRatio;
  v6 = this->mViewport.BufferWidth;
  v4 = this->mViewport.BufferHeight;
  v17 = v2;
  v18 = v3;
  v7 = v4;
  v8 = this->mViewport.Left;
  v9 = this->mViewport.Top;
  v10 = this->mViewport.Width;
  v11 = this->mViewport.Height;
  v16 = this->mViewport.Flags;
  v12 = this->mViewport.ScissorLeft;
  v13 = this->mViewport.ScissorTop;
  v14 = this->mViewport.ScissorWidth;
  v5 = this->mViewport.ScissorHeight;
  ++this->mViewport.Flags;
  v15 = v5;
  this->vfptr[12].__vecDelDtor((Scaleform::RefCountImplCore *)this, (unsigned int)&v6);
}

// File Line: 1332
// RVA: 0x8DF340
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::MovieImpl::GetTopMostEntity(Scaleform::GFx::MovieImpl *this, Scaleform::Render::Point<float> *mousePos, unsigned int controllerIdx, bool testAll, Scaleform::GFx::InteractiveObject *ignoreMC)
{
  Scaleform::Render::Point<float> *v5; // r15
  unsigned int v6; // er13
  Scaleform::GFx::MovieImpl *v7; // r14
  bool v8; // r12
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  Scaleform::RefCountImplCoreVtbl *v12; // rax
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
  Scaleform::GFx::InteractiveObject *v43; // rdi
  Scaleform::GFx::InteractiveObject *v44; // rbx
  Scaleform::GFx::DisplayObjectBase *v45; // rcx
  float *v46; // rax
  __int64 v47; // kr00_8
  __int64 v48; // kr08_8
  float v49; // xmm0_4
  float v50; // xmm2_4
  _OWORD *v51; // rax
  __int64 v52; // rdi
  signed __int64 v53; // rbx
  __int64 v54; // rcx
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+20h] [rbp-B1h]
  float v57; // [rsp+40h] [rbp-91h]
  int v58; // [rsp+44h] [rbp-8Dh]
  int v59; // [rsp+48h] [rbp-89h]
  int v60; // [rsp+4Ch] [rbp-85h]
  int v61; // [rsp+50h] [rbp-81h]
  int v62; // [rsp+54h] [rbp-7Dh]
  int v63; // [rsp+58h] [rbp-79h]
  int v64; // [rsp+5Ch] [rbp-75h]
  int v65; // [rsp+60h] [rbp-71h]
  int v66; // [rsp+64h] [rbp-6Dh]
  int v67; // [rsp+68h] [rbp-69h]
  int v68; // [rsp+6Ch] [rbp-65h]
  float Dst; // [rsp+70h] [rbp-61h]
  int v70; // [rsp+74h] [rbp-5Dh]
  int v71; // [rsp+78h] [rbp-59h]
  int v72; // [rsp+7Ch] [rbp-55h]
  int v73; // [rsp+80h] [rbp-51h]
  int v74; // [rsp+84h] [rbp-4Dh]
  int v75; // [rsp+88h] [rbp-49h]
  int v76; // [rsp+8Ch] [rbp-45h]
  int v77; // [rsp+90h] [rbp-41h]
  int v78; // [rsp+94h] [rbp-3Dh]
  int v79; // [rsp+98h] [rbp-39h]
  int v80; // [rsp+9Ch] [rbp-35h]
  int v81; // [rsp+A0h] [rbp-31h]
  int v82; // [rsp+A4h] [rbp-2Dh]
  int v83; // [rsp+A8h] [rbp-29h]
  int v84; // [rsp+ACh] [rbp-25h]
  __int64 v85; // [rsp+B0h] [rbp-21h]
  Scaleform::GFx::InteractiveObject *v86; // [rsp+C0h] [rbp-11h]
  __int64 v87; // [rsp+C8h] [rbp-9h]
  unsigned int v88; // [rsp+D0h] [rbp-1h]
  bool v89; // [rsp+D4h] [rbp+3h]
  __int64 v90; // [rsp+130h] [rbp+5Fh]
  Scaleform::Render::Point<float> result; // [rsp+138h] [rbp+67h]

  v5 = mousePos;
  v6 = controllerIdx;
  v7 = this;
  v8 = testAll;
  v9 = mousePos->x;
  v10 = this->VisibleFrameRect.x2 - this->VisibleFrameRect.x1;
  v11 = this->ViewOffsetX * 20.0;
  LODWORD(this->ScreenToWorld.Sy) = COERCE_UNSIGNED_INT(
                                      (float)((float)((float)(mousePos->y - (float)(this->ViewOffsetY * 20.0))
                                                    / (float)(this->VisibleFrameRect.y2 - this->VisibleFrameRect.y1))
                                            * 2.0)
                                    - 1.0) ^ _xmm[0];
  this->ScreenToWorld.Sx = (float)((float)((float)(v9 - v11) / v10) * 2.0) - 1.0;
  memset(&Dst, 0, 0x40ui64);
  v12 = v7->vfptr;
  Dst = 1.0;
  v74 = 1065353216;
  v79 = 1065353216;
  v84 = 1065353216;
  v12[62].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)&Dst);
  v13 = v70;
  v7->ScreenToWorld.MatProj.M[0][0] = Dst;
  v14 = v71;
  LODWORD(v7->ScreenToWorld.MatProj.M[0][1]) = v13;
  v15 = v72;
  LODWORD(v7->ScreenToWorld.MatProj.M[0][2]) = v14;
  v16 = v73;
  LODWORD(v7->ScreenToWorld.MatProj.M[0][3]) = v15;
  v17 = v74;
  LODWORD(v7->ScreenToWorld.MatProj.M[1][0]) = v16;
  v18 = v75;
  LODWORD(v7->ScreenToWorld.MatProj.M[1][1]) = v17;
  v19 = v76;
  LODWORD(v7->ScreenToWorld.MatProj.M[1][2]) = v18;
  v20 = v77;
  LODWORD(v7->ScreenToWorld.MatProj.M[1][3]) = v19;
  v21 = v78;
  LODWORD(v7->ScreenToWorld.MatProj.M[2][0]) = v20;
  v22 = v79;
  LODWORD(v7->ScreenToWorld.MatProj.M[2][1]) = v21;
  v23 = v80;
  LODWORD(v7->ScreenToWorld.MatProj.M[2][2]) = v22;
  v24 = v81;
  LODWORD(v7->ScreenToWorld.MatProj.M[2][3]) = v23;
  v25 = v82;
  LODWORD(v7->ScreenToWorld.MatProj.M[3][0]) = v24;
  v26 = v83;
  LODWORD(v7->ScreenToWorld.MatProj.M[3][1]) = v25;
  v27 = v84;
  LODWORD(v7->ScreenToWorld.MatProj.M[3][2]) = v26;
  LODWORD(v7->ScreenToWorld.MatProj.M[3][3]) = v27;
  memset(&v57, 0, 0x30ui64);
  v28 = v7->vfptr;
  v57 = 1.0;
  v62 = 1065353216;
  v67 = 1065353216;
  v28[60].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)&v57);
  v29 = v58;
  v30 = 0i64;
  v90 = 0i64;
  v7->ScreenToWorld.MatView.M[0][0] = v57;
  v31 = v59;
  LODWORD(v7->ScreenToWorld.MatView.M[0][1]) = v29;
  v32 = v60;
  LODWORD(v7->ScreenToWorld.MatView.M[0][2]) = v31;
  v33 = v61;
  LODWORD(v7->ScreenToWorld.MatView.M[0][3]) = v32;
  v34 = v62;
  LODWORD(v7->ScreenToWorld.MatView.M[1][0]) = v33;
  v35 = v63;
  LODWORD(v7->ScreenToWorld.MatView.M[1][1]) = v34;
  v36 = v64;
  LODWORD(v7->ScreenToWorld.MatView.M[1][2]) = v35;
  v37 = v65;
  LODWORD(v7->ScreenToWorld.MatView.M[1][3]) = v36;
  v38 = v66;
  LODWORD(v7->ScreenToWorld.MatView.M[2][0]) = v37;
  v39 = v67;
  LODWORD(v7->ScreenToWorld.MatView.M[2][1]) = v38;
  v40 = v68;
  LODWORD(v7->ScreenToWorld.MatView.M[2][2]) = v39;
  LODWORD(v7->ScreenToWorld.MatView.M[2][3]) = v40;
  v41 = LODWORD(v7->TopmostLevelCharacters.Data.Size) - 1;
  v42 = v41;
  if ( v41 >= 0 )
  {
    while ( 1 )
    {
      v43 = v7->TopmostLevelCharacters.Data.Data[v42].pObject;
      v44 = v43->pParent;
      if ( v44 )
      {
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        v45 = v44->pParentChar;
        if ( v45 )
        {
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v45, &pmat);
          v46 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v44->vfptr[2].__vecDelDtor)(v44);
          v47 = *(_QWORD *)&pmat.M[0][0];
          v48 = *(_QWORD *)&pmat.M[1][0];
          pmat.M[0][0] = (float)(pmat.M[0][1] * v46[4]) + (float)(pmat.M[0][0] * *v46);
          pmat.M[1][0] = (float)(pmat.M[1][1] * v46[4]) + (float)(pmat.M[1][0] * *v46);
          pmat.M[0][1] = (float)(*(float *)&v47 * v46[1]) + (float)(pmat.M[0][1] * v46[5]);
          v49 = pmat.M[1][1] * v46[5];
          v50 = *(float *)&v48 * v46[1];
          pmat.M[0][2] = 0.0;
          *(_QWORD *)&pmat.M[1][1] = COERCE_UNSIGNED_INT(v50 + v49);
          pmat.M[0][3] = pmat.M[0][3]
                       + (float)((float)(*((float *)&v47 + 1) * v46[7]) + (float)(*(float *)&v47 * v46[3]));
          pmat.M[1][3] = pmat.M[1][3]
                       + (float)((float)(*((float *)&v48 + 1) * v46[7]) + (float)(*(float *)&v48 * v46[3]));
        }
        else
        {
          v51 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v44->vfptr[2].__vecDelDtor)(v44);
          *(_OWORD *)&pmat.M[0][0] = *v51;
          *(_OWORD *)&pmat.M[1][0] = v51[1];
        }
        Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, &result, v5);
        v87 = 0i64;
        v86 = ignoreMC;
        v89 = v8;
        v88 = v6;
        if ( ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Point<float> *, __int64 *))v43->vfptr[64].__vecDelDtor)(
               v43,
               &result,
               &v85) == 1 )
          break;
      }
      if ( --v42 < 0 )
      {
        v30 = 0i64;
        goto LABEL_9;
      }
    }
    v30 = v85;
    v90 = v85;
    if ( v85 )
      return (Scaleform::GFx::InteractiveObject *)v30;
  }
LABEL_9:
  v52 = SLODWORD(v7->MovieLevels.Data.Size);
  if ( v52 <= 0 )
    return (Scaleform::GFx::InteractiveObject *)v30;
  v53 = 16 * v52 - 16;
  while ( 1 )
  {
    v54 = *(__int64 *)((char *)&v7->MovieLevels.Data.Data->pSprite.pObject + v53);
    v87 = 0i64;
    v86 = ignoreMC;
    v89 = v8;
    v88 = v6;
    if ( (*(unsigned int (__fastcall **)(__int64, Scaleform::Render::Point<float> *, __int64 *))(*(_QWORD *)v54 + 512i64))(
           v54,
           v5,
           &v85) == 1 )
      break;
    --v52;
    v53 -= 16i64;
    if ( v52 <= 0 )
      return (Scaleform::GFx::InteractiveObject *)v90;
  }
  return (Scaleform::GFx::InteractiveObject *)v85;
}

// File Line: 1398
// RVA: 0x8B4330
float __usercall Scaleform::GFx::MovieImpl::Advance@<xmm0>(Scaleform::GFx::MovieImpl *this@<rcx>, float deltaT@<xmm1>, unsigned int frameCatchUpCount@<r8d>, bool capture@<r9b>, float a5@<xmm0>)
{
  float v5; // xmm7_4
  Scaleform::GFx::MovieImpl *v6; // r13
  Scaleform::GFx::MovieDefImpl *v8; // rcx
  Scaleform::GFx::UserEventHandler *v10; // rbx
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::GFx::FSCommandHandler *v12; // rbx
  Scaleform::Render::RenderBuffer *v13; // rcx
  Scaleform::GFx::ExternalInterface *v14; // rbx
  Scaleform::Render::RenderBuffer *v15; // rcx
  __int64 v16; // rbx
  Scaleform::RefCountImplCoreVtbl *v17; // rdi
  Scaleform::Render::RenderBuffer *v18; // rcx
  Scaleform::Render::RenderBuffer *v19; // r14
  Scaleform::Render::RenderBuffer *v20; // rsi
  Scaleform::Render::RenderBuffer *v21; // rdi
  Scaleform::Render::RenderBuffer *v22; // r15
  unsigned __int8 v23; // r12
  unsigned int v24; // eax
  unsigned int v25; // eax
  Scaleform::GFx::MovieDefRootNode *i; // rbx
  signed __int64 v27; // rax
  unsigned int v28; // ebx
  __int64 v29; // rcx
  Scaleform::GFx::InteractiveObject *v30; // rcx
  unsigned __int64 v31; // rax
  int v32; // ebx
  float v33; // xmm0_4
  signed __int64 v34; // rcx
  unsigned __int64 v35; // r12
  float v36; // xmm13_4
  unsigned __int64 v37; // r15
  float v38; // xmm13_4
  signed __int64 v39; // rcx
  signed __int64 v40; // r14
  int v41; // esi
  unsigned __int64 v42; // rdi
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327,Scaleform::ArrayDefaultPolicy> *v43; // rbx
  Scaleform::GFx::ASIntervalTimerIntf *v44; // rcx
  __int128 v45; // xmm2
  unsigned __int64 v46; // rax
  unsigned __int64 v47; // r15
  __int64 j; // rsi
  Scaleform::GFx::ASIntervalTimerIntf *v49; // rcx
  Scaleform::Render::RenderBuffer *v50; // rcx
  float v51; // xmm13_4
  float v52; // xmm2_4
  float v53; // xmm0_4
  unsigned int v54; // edi
  bool v55; // si
  float v56; // xmm6_4
  float v57; // xmm0_4
  float v58; // xmm0_4
  float v59; // xmm2_4
  Scaleform::RefCountNTSImpl *v60; // rbx
  Scaleform::RefCountNTSImplCoreVtbl *v61; // rdi
  __int64 v62; // rcx
  __int64 v63; // rdx
  unsigned int v64; // eax
  unsigned int v65; // eax
  Scaleform::GFx::DrawingContext *k; // rbx
  signed __int64 v67; // rax
  signed __int64 v68; // rdi
  signed __int64 v69; // rbx
  signed __int64 v70; // rax
  float v71; // xmm0_4
  float v72; // xmm13_4
  Scaleform::Render::TreeRoot *v73; // rdx
  unsigned __int64 v74; // r15
  __int64 v75; // rsi
  Scaleform::GFx::MovieImpl::IndirectTransPair *v76; // rbx
  Scaleform::Render::TreeNode *v77; // r14
  Scaleform::Render::ContextImpl::Entry *v78; // rcx
  bool v79; // r9
  Scaleform::Render::TreeRoot *v80; // rcx
  Scaleform::Render::ContextImpl::Entry *v81; // rcx
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v82; // rcx
  float v83; // xmm7_4
  float v84; // xmm9_4
  float v85; // xmm0_4
  float v86; // xmm10_4
  float v87; // xmm8_4
  float v88; // xmm11_4
  float v89; // xmm1_4
  float v90; // xmm12_4
  int v91; // xmm2_4
  int v92; // xmm3_4
  int v93; // xmm4_4
  int v94; // xmm5_4
  char v95; // di
  Scaleform::Render::TreeRoot *v96; // rbx
  __int64 v97; // r9
  __int64 v98; // rdx
  float v99; // xmm0_4
  unsigned int v100; // xmm2_4
  unsigned int v101; // xmm3_4
  Scaleform::Render::TreeRoot *v102; // rbx
  __int64 v103; // r9
  __int64 v104; // rdx
  Scaleform::Render::Matrix3x4<float> *v105; // rax
  __int64 v106; // kr10_8
  float v107; // xmm6_4
  float v108; // xmm5_4
  bool v109; // al
  char Dst[48]; // [rsp+30h] [rbp-98h]
  Scaleform::Render::Matrix3x4<float> v111; // [rsp+60h] [rbp-68h]
  float v112; // [rsp+90h] [rbp-38h]
  float v113; // [rsp+94h] [rbp-34h]
  float v114; // [rsp+98h] [rbp-30h]
  float v115; // [rsp+9Ch] [rbp-2Ch]
  float v116; // [rsp+A0h] [rbp-28h]
  float v117; // [rsp+A4h] [rbp-24h]
  int v118; // [rsp+A8h] [rbp-20h]
  int v119; // [rsp+ACh] [rbp-1Ch]
  int v120; // [rsp+B0h] [rbp-18h]
  int v121; // [rsp+B4h] [rbp-14h]
  Scaleform::Render::Matrix3x4<float> v122; // [rsp+B8h] [rbp-10h]
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+E8h] [rbp+20h]
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+118h] [rbp+50h]
  Scaleform::Render::Matrix3x4<float> v125; // [rsp+148h] [rbp+80h]
  __int128 v126; // [rsp+178h] [rbp+B0h]
  __int128 v127; // [rsp+188h] [rbp+C0h]
  Scaleform::GFx::FontLib *pfontLib[2]; // [rsp+198h] [rbp+D0h]
  Scaleform::GFx::FontMap *pfontMap[2]; // [rsp+1A8h] [rbp+E0h]
  Scaleform::GFx::Translator *ptranslator[2]; // [rsp+1B8h] [rbp+F0h]
  __int64 v131; // [rsp+1C8h] [rbp+100h]
  Scaleform::GFx::Translator *v132; // [rsp+1D0h] [rbp+108h]
  Scaleform::GFx::FontMap *v133; // [rsp+1D8h] [rbp+110h]
  Scaleform::GFx::FontMap *v134; // [rsp+1E0h] [rbp+118h]
  Scaleform::GFx::FontLib *v135; // [rsp+1E8h] [rbp+120h]
  Scaleform::Render::Matrix3x4<float> result; // [rsp+1F8h] [rbp+130h]
  Scaleform::Render::RenderBuffer *v137; // [rsp+2F8h] [rbp+230h]
  unsigned int v138; // [rsp+308h] [rbp+240h]
  char v139; // [rsp+310h] [rbp+248h]

  v131 = -2i64;
  v5 = deltaT;
  v6 = this;
  if ( (this->Flags >> 20) & 1 )
  {
    if ( capture )
      Scaleform::GFx::MovieImpl::Capture(this, 1);
    return FLOAT_0_050000001;
  }
  if ( !this->pMainMovie )
  {
    if ( capture )
      Scaleform::GFx::MovieImpl::Capture(this, 1);
    v8 = v6->pMainMovieDef.pObject;
    if ( !v8 )
      return 0.0;
    ((void (*)(void))v8->vfptr[2].GetKey)();
    return 1.0 / a5;
  }
  Scaleform::GFx::MovieImpl::ProcessMovieDefToKillList(this);
  if ( deltaT < 0.0 )
    v5 = 0.0;
  v6->Flags |= 0x200u;
  *(_QWORD *)&Dst[40] = 0i64;
  _mm_store_si128((__m128i *)&v126, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v127, (__m128i)0i64);
  _mm_store_si128((__m128i *)pfontLib, (__m128i)0i64);
  _mm_store_si128((__m128i *)pfontMap, (__m128i)0i64);
  _mm_store_si128((__m128i *)ptranslator, (__m128i)0i64);
  v6->pStateBag.pObject->vfptr->GetStatesAddRef(
    (Scaleform::GFx::StateBag *)&v6->pStateBag.pObject->vfptr,
    (Scaleform::GFx::State **)&v126,
    stateQuery,
    9u);
  v137 = 0i64;
  v10 = (Scaleform::GFx::UserEventHandler *)v126;
  v11 = (Scaleform::Render::RenderBuffer *)v6->pUserEventHandler.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v6->pUserEventHandler.pObject = v10;
  v12 = (Scaleform::GFx::FSCommandHandler *)*((_QWORD *)&v126 + 1);
  v13 = (Scaleform::Render::RenderBuffer *)v6->pFSCommandHandler.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  v6->pFSCommandHandler.pObject = v12;
  v14 = (Scaleform::GFx::ExternalInterface *)v127;
  v15 = (Scaleform::Render::RenderBuffer *)v6->pExtIntfHandler.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  v6->pExtIntfHandler.pObject = v14;
  v16 = *((_QWORD *)&v127 + 1);
  *(_QWORD *)&Dst[40] = *((_QWORD *)&v127 + 1);
  v137 = (Scaleform::Render::RenderBuffer *)pfontLib[0];
  if ( !pfontLib[0] )
  {
    v17 = 0i64;
LABEL_24:
    if ( !v17 )
      goto LABEL_26;
    goto LABEL_25;
  }
  v17 = pfontLib[0][1].vfptr;
  if ( !v17 )
  {
    v17 = (Scaleform::RefCountImplCoreVtbl *)Scaleform::Log::GetGlobalLog();
    goto LABEL_24;
  }
LABEL_25:
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v17);
LABEL_26:
  v18 = (Scaleform::Render::RenderBuffer *)v6->pCachedLog.pObject;
  if ( v18 )
    Scaleform::RefCountImpl::Release(v18);
  v6->pCachedLog.pObject = (Scaleform::Log *)v17;
  v19 = (Scaleform::Render::RenderBuffer *)pfontLib[1];
  v135 = pfontLib[1];
  v20 = (Scaleform::Render::RenderBuffer *)pfontMap[0];
  v134 = pfontMap[0];
  v21 = (Scaleform::Render::RenderBuffer *)pfontMap[1];
  v133 = pfontMap[1];
  v22 = (Scaleform::Render::RenderBuffer *)ptranslator[0];
  v132 = ptranslator[0];
  v23 = Scaleform::GFx::FontManagerStates::CheckStateChange(
          v6->pFontManagerStates.pObject,
          pfontLib[1],
          pfontMap[0],
          (Scaleform::GFx::FontProvider *)pfontMap[1],
          ptranslator[0]);
  if ( v22 )
    Scaleform::RefCountImpl::Release(v22);
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  if ( v19 )
    Scaleform::RefCountImpl::Release(v19);
  v6->Flags |= 2u;
  v24 = v6->Flags;
  if ( v16 )
  {
    if ( *(_BYTE *)(v16 + 24) & 1 )
      v25 = v24 | 4;
    else
      v25 = v24 & 0xFFFFFFFB;
    v6->Flags = v25;
    if ( (*(_DWORD *)(v16 + 24) >> 1) & 1 )
      v6->Flags |= 0x40u;
    else
      v6->Flags &= 0xFFFFFFBF;
    if ( (*(_DWORD *)(v16 + 24) >> 2) & 1 )
      v6->Flags |= 8u;
    else
      v6->Flags &= 0xFFFFFFF7;
    if ( (*(_DWORD *)(v16 + 24) >> 4) & 1 )
      v6->Flags |= 0x20u;
    else
      v6->Flags &= 0xFFFFFFDF;
    if ( (*(_DWORD *)(v16 + 24) >> 3) & 1 )
      v6->Flags |= 0x10u;
    else
      v6->Flags &= 0xFFFFFFEF;
  }
  else
  {
    v6->Flags = v24 & 0xFFFFFF83;
  }
  for ( i = v6->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
  {
    v27 = (signed __int64)(v6 == (Scaleform::GFx::MovieImpl *)-112i64 ? 0i64 : &v6->MovieLevels.Data.Policy);
    if ( i == (Scaleform::GFx::MovieDefRootNode *)v27 )
      break;
    if ( !i->ImportFlag )
    {
      i->BytesLoaded = i->pDefImpl->pBindData.pObject->BytesLoaded;
      i->LoadingFrame = ((__int64 (*)(void))i->pDefImpl->vfptr[1].GetKey)();
    }
    if ( v23 )
      ((void (*)(void))i->pFontManager.pObject->vfptr[3].__vecDelDtor)();
  }
  if ( v23 || (v6->Flags2 >> 1) & 1 )
  {
    v28 = 0;
    if ( v6->MovieLevels.Data.Size )
    {
      v29 = 0i64;
      do
      {
        v30 = v6->MovieLevels.Data.Data[v29].pSprite.pObject;
        v30->vfptr[79].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v30->vfptr, v23);
        v29 = ++v28;
      }
      while ( v28 < v6->MovieLevels.Data.Size );
    }
  }
  if ( !((unsigned int (*)(void))v6->pMainMovie->vfptr[111].__vecDelDtor)() )
  {
    if ( v139 )
      Scaleform::GFx::MovieImpl::Capture(v6, 1);
    v6->Flags &= 0xFFFFFFFD;
    if ( v137 )
      Scaleform::RefCountImpl::Release(v137);
    if ( *(_QWORD *)&Dst[40] )
      Scaleform::RefCountImpl::Release(*(Scaleform::Render::RenderBuffer **)&Dst[40]);
    return 0.0;
  }
  if ( (LOWORD(v6->Flags) >> 8) & 1 && ((unsigned int (*)(void))v6->pMainMovie->vfptr[111].__vecDelDtor)() )
  {
    v6->Flags &= 0xFFFFFEFF;
    v31 = v6->MovieLevels.Data.Size;
    if ( (_DWORD)v31 )
    {
      do
      {
        v32 = v31 - 1;
        ((void (*)(void))v6->MovieLevels.Data.Data[(unsigned int)(v31 - 1)].pSprite.pObject->vfptr[112].__vecDelDtor)();
        LODWORD(v31) = v32;
      }
      while ( v32 );
    }
    ((void (*)(void))v6->pASMovieRoot.pObject->vfptr[7].__vecDelDtor)();
    Scaleform::GFx::MovieImpl::ProcessUnloadQueue(v6);
    Scaleform::GFx::MovieImpl::ProcessLoadQueue(v6);
  }
  v33 = v5 * 1000000.0;
  v34 = 0i64;
  if ( (float)(v5 * 1000000.0) >= 9.223372e18 )
  {
    v33 = v33 - 9.223372e18;
    if ( v33 < 9.223372e18 )
      v34 = 0x8000000000000000i64;
  }
  v6->TimeElapsed += v34 + (unsigned int)(signed int)v33;
  v6->TimeRemainder = v5 + v6->TimeRemainder;
  v35 = Scaleform::Timer::GetProfileTicks();
  v36 = v6->FrameTime;
  v37 = v6->IntervalTimers.Data.Size;
  if ( v37 )
  {
    v38 = v36 * 1000000.0;
    v39 = 0i64;
    if ( v38 >= 9.223372e18 )
    {
      v38 = v38 - 9.223372e18;
      if ( v38 < 9.223372e18 )
        v39 = 0x8000000000000000i64;
    }
    v40 = v39 + (unsigned int)(signed int)v38;
    v41 = 0;
    v42 = 0i64;
    if ( v37 )
    {
      v43 = &v6->IntervalTimers;
      do
      {
        v44 = v43->Data.Data[v42].pObject;
        if ( v44 && ((unsigned __int8 (*)(void))v44->vfptr[3].__vecDelDtor)() )
        {
          v45 = LODWORD(v6->FrameTime);
          v43->Data.Data[v42].pObject->vfptr[2].__vecDelDtor(
            (Scaleform::RefCountImplCore *)&v43->Data.Data[v42].pObject->vfptr,
            (unsigned int)v6);
          v46 = ((__int64 (*)(void))v43->Data.Data[v42].pObject->vfptr[6].__vecDelDtor)() - v6->TimeElapsed;
          if ( v46 < v40 )
            v40 = v46;
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
        v47 = v6->IntervalTimers.Data.Size;
        for ( j = 0i64; v47; --v47 )
        {
          v49 = v43->Data.Data[j].pObject;
          if ( v49 && ((unsigned __int8 (*)(void))v49->vfptr[3].__vecDelDtor)() )
          {
            j = (unsigned int)(j + 1);
          }
          else
          {
            ((void (*)(void))v43->Data.Data[j].pObject->vfptr[4].__vecDelDtor)();
            if ( v6->IntervalTimers.Data.Size == 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy> *)&v6->IntervalTimers.Data.Data,
                &v6->IntervalTimers,
                0i64);
            }
            else
            {
              v50 = (Scaleform::Render::RenderBuffer *)v43->Data.Data[j].pObject;
              if ( v50 )
                Scaleform::RefCountImpl::Release(v50);
              memmove(
                &v43->Data.Data[j],
                &v43->Data.Data[j + 1],
                8 * (v6->IntervalTimers.Data.Size - (unsigned int)j) - 8);
              --v6->IntervalTimers.Data.Size;
            }
          }
        }
      }
    }
    v51 = (float)(signed int)v40;
    if ( v40 < 0 )
      v51 = v51 + 1.8446744e19;
    v36 = v51 * 1000000.0;
  }
  Scaleform::GFx::MovieImpl::ProcessInput(v6);
  v52 = v6->TimeRemainder;
  v53 = v6->FrameTime;
  if ( v52 < v53 )
  {
    Scaleform::GFx::MovieImpl::AdvanceFrame(v6, 0, v52 / v53);
    v6->TimeRemainder = fmodf(v6->TimeRemainder, v6->FrameTime);
    ((void (*)(void))v6->pASMovieRoot.pObject->vfptr[7].__vecDelDtor)();
    Scaleform::GFx::MovieImpl::ProcessUnloadQueue(v6);
    Scaleform::GFx::MovieImpl::ProcessLoadQueue(v6);
    v63 = 0i64;
  }
  else
  {
    ((void (*)(void))v6->pASMovieRoot.pObject->vfptr[7].__vecDelDtor)();
    v54 = v138;
    v55 = v138 || v6->ForceFrameCatchUp > v138;
    do
    {
      v56 = v6->FrameTime;
      v57 = v6->TimeRemainder;
      if ( v55 )
        v58 = v57 - v56;
      else
        v58 = fmodf(v57, v6->FrameTime);
      v6->TimeRemainder = v58;
      if ( v58 < v56 )
        v59 = v58 / v56;
      else
        v59 = 0.0;
      Scaleform::GFx::MovieImpl::AdvanceFrame(v6, 1, v59);
      ((void (*)(void))v6->pASMovieRoot.pObject->vfptr[7].__vecDelDtor)();
      v60 = (Scaleform::RefCountNTSImpl *)&v6->pUnloadListHead->vfptr;
      if ( v60 )
      {
        do
        {
          v61 = v60[10].vfptr;
          v60[10].vfptr = 0i64;
          ((void (__fastcall *)(Scaleform::RefCountNTSImpl *))v60->vfptr[75].__vecDelDtor)(v60);
          v62 = *(_QWORD *)&v60[3].RefCount;
          if ( v62 )
            (*(void (__fastcall **)(__int64, Scaleform::RefCountNTSImpl *))(*(_QWORD *)v62 + 936i64))(v62, v60);
          Scaleform::RefCountNTSImpl::Release(v60);
          v60 = (Scaleform::RefCountNTSImpl *)v61;
        }
        while ( v61 );
        v6->pUnloadListHead = 0i64;
        v54 = v138;
      }
      Scaleform::GFx::MovieImpl::ProcessLoadQueue(v6);
      v64 = v6->ForceFrameCatchUp;
      if ( v64 )
        v6->ForceFrameCatchUp = v64 - 1;
      v65 = v54--;
      v138 = v54;
    }
    while ( v65 && v6->FrameTime <= v6->TimeRemainder || v6->ForceFrameCatchUp );
    v6->Flags |= 0x80u;
    LOBYTE(v63) = 1;
  }
  v6->pASMovieRoot.pObject->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)v6->pASMovieRoot.pObject, v63);
  for ( k = v6->DrawingContextList.Root.pNext; ; k = k->pNext )
  {
    v67 = (signed __int64)(v6 == (Scaleform::GFx::MovieImpl *)-21248i64 ? 0i64 : &v6->RegisteredFonts.Data.Size);
    if ( k == (Scaleform::GFx::DrawingContext *)v67 )
      break;
    if ( k->States < 0 )
      Scaleform::GFx::DrawingContext::UpdateRenderNode(k);
  }
  if ( v6->FocusRectChanged )
    Scaleform::GFx::MovieImpl::UpdateFocusRectRenderNodes(v6);
  v68 = 0i64;
  if ( v6->FocusGroupsCnt )
  {
    do
    {
      v69 = v68;
      if ( v6->FocusGroups[v68].TabableArrayStatus & 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy> *)&v6->FocusGroups[v69].TabableArray.Data.Data,
          v6->FocusGroups[v69].TabableArray.Data.pHeap,
          0i64);
        v6->FocusGroups[v69].TabableArrayStatus = 0;
      }
      v68 = (unsigned int)(v68 + 1);
    }
    while ( (unsigned int)v68 < v6->FocusGroupsCnt );
  }
  v6->Flags &= 0xFFFFFFFD;
  v70 = Scaleform::Timer::GetProfileTicks() - v35;
  v71 = (float)(signed int)v70;
  if ( v70 < 0 )
    v71 = v71 + 1.8446744e19;
  v72 = v36 + (float)(v71 * -0.000001);
  if ( v72 < 0.0 )
    v72 = 0.0;
  if ( v139 )
  {
    if ( !Scaleform::Render::ContextImpl::Context::HasChanges(&v6->RenderContext) && !v6->MovieDefKillList.Data.Size )
    {
      if ( v6->PreviouslyCaptured > 0 )
      {
        LOBYTE(v73) = 1;
        v6->pASMovieRoot.pObject->vfptr[11].__vecDelDtor(
          (Scaleform::RefCountImplCore *)v6->pASMovieRoot.pObject,
          (unsigned int)v73);
        Scaleform::Render::ContextImpl::Context::Capture(&v6->RenderContext);
        v6->pASMovieRoot.pObject->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)v6->pASMovieRoot.pObject, 0);
        --v6->PreviouslyCaptured;
      }
      goto LABEL_205;
    }
    v74 = v6->IndirectTransformPairs.Data.Size;
    if ( !v74 )
    {
LABEL_198:
      if ( (v6->Flags >> 10) & 1
        || (v109 = Scaleform::Render::ContextImpl::Context::HasChanges(&v6->RenderContext)) != 0 )
      {
        v109 = 1;
      }
      if ( v109 )
        v6->Flags |= 0x400u;
      else
        v6->Flags &= 0xFFFFFBFF;
      LOBYTE(v73) = 1;
      v6->pASMovieRoot.pObject->vfptr[11].__vecDelDtor(
        (Scaleform::RefCountImplCore *)v6->pASMovieRoot.pObject,
        (unsigned int)v73);
      Scaleform::Render::ContextImpl::Context::Capture(&v6->RenderContext);
      v6->pASMovieRoot.pObject->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)v6->pASMovieRoot.pObject, 0);
      v6->PreviouslyCaptured = 1;
      goto LABEL_205;
    }
    v75 = 0i64;
    while ( 1 )
    {
      v76 = v6->IndirectTransformPairs.Data.Data;
      v77 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v76[v75].Obj.pObject);
      v78 = v77->pPrev;
      if ( v77->pPrev )
      {
        v79 = ((_QWORD)v78->pNext & 0x80040181) != 0;
        if ( (_QWORD)v78->pNext & 0x80040181 )
          goto LABEL_179;
      }
      else
      {
        v79 = 0;
      }
      v73 = 0i64;
      v80 = (Scaleform::Render::TreeRoot *)v76[v75].TransformParent.pObject;
      if ( v80 )
      {
        while ( v80 != v6->pRenderRoot.pObject )
        {
          if ( v80->pPrev && ((_QWORD)v80->pPrev->pNext & 0x80040181) != 0 )
          {
            v79 = 1;
            break;
          }
          v80 = (Scaleform::Render::TreeRoot *)v80->pParent;
          v73 = (Scaleform::Render::TreeRoot *)(unsigned int)((_DWORD)v73 + 1);
          if ( !v80 )
            break;
        }
      }
      if ( (_DWORD)v73 == v76[v75].OrigParentDepth )
      {
        if ( !v79 )
        {
          v81 = v77->pParent;
          if ( v81 )
          {
            v73 = v6->pRenderRoot.pObject;
            while ( v81 != (Scaleform::Render::ContextImpl::Entry *)v73 )
            {
              if ( v81->pPrev && ((_QWORD)v81->pPrev->pNext & 0x80040181) != 0 )
                goto LABEL_179;
              v81 = v81->pParent;
              if ( !v81 )
                goto LABEL_197;
            }
          }
          goto LABEL_197;
        }
      }
      else
      {
        v76[v75].OrigParentDepth = (signed int)v73;
      }
LABEL_179:
      v82 = v76[v75].Obj.pObject->pIndXFormData;
      v83 = v82->OrigTransformMatrix.M[0][0];
      v111.M[0][0] = v82->OrigTransformMatrix.M[0][0];
      v84 = v82->OrigTransformMatrix.M[0][1];
      v111.M[0][1] = v82->OrigTransformMatrix.M[0][1];
      v85 = v82->OrigTransformMatrix.M[0][2];
      v111.M[0][2] = v82->OrigTransformMatrix.M[0][2];
      v86 = v82->OrigTransformMatrix.M[0][3];
      v111.M[0][3] = v82->OrigTransformMatrix.M[0][3];
      v87 = v82->OrigTransformMatrix.M[1][0];
      v111.M[1][0] = v82->OrigTransformMatrix.M[1][0];
      v88 = v82->OrigTransformMatrix.M[1][1];
      v111.M[1][1] = v82->OrigTransformMatrix.M[1][1];
      v89 = v82->OrigTransformMatrix.M[1][2];
      v111.M[1][2] = v82->OrigTransformMatrix.M[1][2];
      v90 = v82->OrigTransformMatrix.M[1][3];
      v111.M[1][3] = v82->OrigTransformMatrix.M[1][3];
      v91 = LODWORD(v82->OrigTransformMatrix.M[2][0]);
      *(float *)&Dst[24] = v82->OrigTransformMatrix.M[2][0];
      v92 = LODWORD(v82->OrigTransformMatrix.M[2][1]);
      *(float *)&Dst[28] = v82->OrigTransformMatrix.M[2][1];
      v93 = LODWORD(v82->OrigTransformMatrix.M[2][2]);
      *(float *)&Dst[32] = v82->OrigTransformMatrix.M[2][2];
      v94 = LODWORD(v82->OrigTransformMatrix.M[2][3]);
      *(float *)&Dst[36] = v82->OrigTransformMatrix.M[2][3];
      v95 = v82->IsOrig3D;
      v96 = (Scaleform::Render::TreeRoot *)v76[v75].TransformParent.pObject;
      if ( v96 )
      {
        while ( v96 != v6->pRenderRoot.pObject )
        {
          v97 = *(_QWORD *)(((unsigned __int64)v96 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
          v98 = *(_QWORD *)(v97
                          + 8
                          * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v96[-1]
                                                                                    - ((unsigned __int64)v96 & 0xFFFFFFFFFFFFF000ui64))
                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                           + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v96[-1]
                                                                                                - ((unsigned __int64)v96 & 0xFFFFFFFFFFFFF000ui64))
                                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                          + 40);
          if ( (*(_WORD *)(*(_QWORD *)(v97
                                     + 8
                                     * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v96[-1]
                                                                                               - ((unsigned __int64)v96 & 0xFFFFFFFFFFFFF000ui64))
                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                      + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v96[-1] - ((unsigned __int64)v96 & 0xFFFFFFFFFFFFF000ui64))
                                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                     + 40)
                         + 10i64) >> 9) & 1 )
          {
            *(_QWORD *)&v111.M[2][2] = __PAIR__(LODWORD(v84), LODWORD(v83));
            v112 = v85;
            v113 = v86;
            v114 = v87;
            v115 = v88;
            v116 = v89;
            v117 = v90;
            v118 = v91;
            v119 = v92;
            v120 = v93;
            v121 = v94;
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &v111,
              (Scaleform::Render::Matrix3x4<float> *)(v98 + 16),
              (Scaleform::Render::Matrix3x4<float> *)((char *)&v111 + 40));
            v95 = 1;
          }
          else
          {
            *(_QWORD *)&m2.M[0][0] = __PAIR__(LODWORD(v84), LODWORD(v83));
            *(_QWORD *)&m2.M[0][2] = __PAIR__(LODWORD(v86), LODWORD(v85));
            *(_QWORD *)&m2.M[1][0] = __PAIR__(LODWORD(v88), LODWORD(v87));
            *(_QWORD *)&m2.M[1][2] = __PAIR__(LODWORD(v90), LODWORD(v89));
            *(_QWORD *)&m2.M[2][0] = __PAIR__(v92, v91);
            *(_QWORD *)&m2.M[2][2] = __PAIR__(v94, v93);
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &v111,
              (Scaleform::Render::Matrix2x4<float> *)(v98 + 16),
              &m2);
          }
          v96 = (Scaleform::Render::TreeRoot *)v96->pParent;
          v90 = v111.M[1][3];
          v88 = v111.M[1][1];
          v87 = v111.M[1][0];
          v86 = v111.M[0][3];
          v84 = v111.M[0][1];
          v83 = v111.M[0][0];
          if ( !v96 )
            break;
          v94 = *(_DWORD *)&Dst[36];
          v93 = *(_DWORD *)&Dst[32];
          v92 = *(_DWORD *)&Dst[28];
          v91 = *(_DWORD *)&Dst[24];
          v89 = v111.M[1][2];
          v85 = v111.M[0][2];
        }
      }
      memset(Dst, 0, 0x30ui64);
      LODWORD(v99) = (_DWORD)FLOAT_1_0;
      *(_DWORD *)Dst = (_DWORD)FLOAT_1_0;
      v100 = (unsigned int)FLOAT_1_0;
      *(_DWORD *)&Dst[20] = (_DWORD)FLOAT_1_0;
      v101 = (unsigned int)FLOAT_1_0;
      *(_DWORD *)&Dst[40] = (_DWORD)FLOAT_1_0;
      v102 = (Scaleform::Render::TreeRoot *)v77->pParent;
      if ( v102 )
      {
        while ( v102 != v6->pRenderRoot.pObject )
        {
          v103 = *(_QWORD *)(((unsigned __int64)v102 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
          v104 = *(_QWORD *)(v103
                           + 8
                           * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v102[-1]
                                                                                     - ((unsigned __int64)v102 & 0xFFFFFFFFFFFFF000ui64))
                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                            + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v102[-1]
                                                                                                 - ((unsigned __int64)v102 & 0xFFFFFFFFFFFFF000ui64))
                                                                                * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                           + 40);
          if ( (*(_WORD *)(*(_QWORD *)(v103
                                     + 8
                                     * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v102[-1]
                                                                                               - ((unsigned __int64)v102 & 0xFFFFFFFFFFFFF000ui64))
                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                      + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v102[-1] - ((unsigned __int64)v102 & 0xFFFFFFFFFFFFF000ui64))
                                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                     + 40)
                         + 10i64) >> 9) & 1 )
          {
            v122.M[0][0] = v99;
            *(_QWORD *)&v122.M[0][1] = *(_QWORD *)&Dst[4];
            v122.M[0][3] = *(float *)&Dst[12];
            *(_QWORD *)&v122.M[1][0] = __PAIR__(v100, *(unsigned int *)&Dst[16]);
            *(_QWORD *)&v122.M[1][2] = *(_QWORD *)&Dst[24];
            *(_QWORD *)&v122.M[2][0] = *(_QWORD *)&Dst[32];
            *(_QWORD *)&v122.M[2][2] = __PAIR__(*(unsigned int *)&Dst[44], v101);
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              (Scaleform::Render::Matrix3x4<float> *)Dst,
              (Scaleform::Render::Matrix3x4<float> *)(v104 + 16),
              &v122);
            v95 = 1;
          }
          else
          {
            v125.M[0][0] = v99;
            *(_QWORD *)&v125.M[0][1] = *(_QWORD *)&Dst[4];
            v125.M[0][3] = *(float *)&Dst[12];
            *(_QWORD *)&v125.M[1][0] = __PAIR__(v100, *(unsigned int *)&Dst[16]);
            *(_QWORD *)&v125.M[1][2] = *(_QWORD *)&Dst[24];
            *(_QWORD *)&v125.M[2][0] = *(_QWORD *)&Dst[32];
            *(_QWORD *)&v125.M[2][2] = __PAIR__(*(unsigned int *)&Dst[44], v101);
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              (Scaleform::Render::Matrix3x4<float> *)Dst,
              (Scaleform::Render::Matrix2x4<float> *)(v104 + 16),
              &v125);
          }
          v102 = (Scaleform::Render::TreeRoot *)v102->pParent;
          v100 = *(_DWORD *)&Dst[20];
          v99 = *(float *)Dst;
          if ( !v102 )
            break;
          v101 = *(_DWORD *)&Dst[40];
        }
        v84 = v111.M[0][1];
        v83 = v111.M[0][0];
        v86 = v111.M[0][3];
        v88 = v111.M[1][1];
        v87 = v111.M[1][0];
        v90 = v111.M[1][3];
      }
      if ( v95 )
      {
        v105 = Scaleform::Render::Matrix3x4<float>::GetInverse((Scaleform::Render::Matrix3x4<float> *)Dst, &result);
        *(_OWORD *)Dst = *(_OWORD *)&v105->M[0][0];
        *(float *)&Dst[16] = v105->M[1][0];
        *(float *)&Dst[20] = v105->M[1][1];
        *(_QWORD *)&Dst[24] = *(_QWORD *)&v105->M[1][2];
        *(_OWORD *)&Dst[32] = *(_OWORD *)&v105->M[2][0];
        m1 = *(Scaleform::Render::Matrix3x4<float> *)Dst;
        Scaleform::Render::Matrix3x4<float>::MultiplyMatrix((Scaleform::Render::Matrix3x4<float> *)Dst, &m1, &v111);
        Scaleform::Render::TreeNode::SetMatrix3D(v77, (Scaleform::Render::Matrix3x4<float> *)Dst);
      }
      else
      {
        *(_QWORD *)&v111.M[0][2] = __PAIR__(*(unsigned int *)&Dst[4], LODWORD(v99));
        *(_QWORD *)&v111.M[1][0] = *(_QWORD *)&Dst[8];
        *(_QWORD *)&v111.M[1][2] = __PAIR__(v100, *(unsigned int *)&Dst[16]);
        *(_QWORD *)&v111.M[2][0] = *(_QWORD *)&Dst[24];
        Scaleform::Render::Matrix2x4<float>::SetInverse(
          (Scaleform::Render::Matrix2x4<float> *)Dst,
          (Scaleform::Render::Matrix2x4<float> *)&v111.M[0][2]);
        v106 = *(_QWORD *)Dst;
        v107 = *(float *)&Dst[16];
        v108 = *(float *)&Dst[20];
        *(float *)Dst = (float)(v87 * *(float *)&Dst[4]) + (float)(v83 * *(float *)Dst);
        *(float *)&Dst[16] = (float)(v83 * *(float *)&Dst[16]) + (float)(v87 * *(float *)&Dst[20]);
        *(float *)&Dst[4] = (float)(*(float *)&Dst[4] * v88) + (float)(*(float *)&v106 * v84);
        *(float *)&Dst[20] = (float)(v107 * v84) + (float)(*(float *)&Dst[20] * v88);
        *(_DWORD *)&Dst[24] = 0;
        *(_DWORD *)&Dst[8] = 0;
        *(float *)&Dst[12] = *(float *)&Dst[12]
                           + (float)((float)(*(float *)&v106 * v86) + (float)(*((float *)&v106 + 1) * v90));
        *(float *)&Dst[28] = *(float *)&Dst[28] + (float)((float)(v107 * v86) + (float)(v108 * v90));
        Scaleform::Render::TreeNode::SetMatrix(v77, (Scaleform::Render::Matrix2x4<float> *)Dst);
      }
LABEL_197:
      ++v75;
      if ( !--v74 )
        goto LABEL_198;
    }
  }
LABEL_205:
  if ( v72 >= (float)(v6->FrameTime - v6->TimeRemainder) )
    v72 = v6->FrameTime - v6->TimeRemainder;
  if ( v137 )
    Scaleform::RefCountImpl::Release(v137);
  if ( *(_QWORD *)&Dst[40] )
    Scaleform::RefCountImpl::Release(*(Scaleform::Render::RenderBuffer **)&Dst[40]);
  return v72;
}RefCountImpl::Release(*(Scaleform::Render::RenderBuffer **)&Dst[40]);
  return v72;
}

// File Line: 1758
// RVA: 0x8B98E0
void __fastcall Scaleform::GFx::MovieImpl::Capture(Scaleform::GFx::MovieImpl *this, __int64 onChangeOnly)
{
  Scaleform::GFx::MovieImpl *v2; // rdi
  unsigned __int64 v3; // r12
  __int64 v4; // r14
  Scaleform::GFx::MovieImpl::IndirectTransPair *v5; // rbx
  Scaleform::Render::TreeNode *v6; // r15
  Scaleform::Render::ContextImpl::Entry *v7; // rcx
  bool v8; // r9
  Scaleform::GFx::DisplayObjectBase *v9; // rax
  Scaleform::Render::TreeRoot *v10; // rbx
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v11; // rcx
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
  char v24; // si
  __int64 v25; // r9
  __int64 v26; // rdx
  Scaleform::Render::TreeRoot *v27; // rcx
  Scaleform::Render::ContextImpl::Entry *v28; // rcx
  Scaleform::Render::TreeRoot *v29; // rbx
  float v30; // xmm0_4
  float v31; // xmm2_4
  unsigned int v32; // xmm3_4
  __int64 v33; // r9
  __int64 v34; // rdx
  Scaleform::Render::Matrix3x4<float> *v35; // rax
  float v36; // xmm10_4
  float v37; // xmm8_4
  float v38; // xmm6_4
  float v39; // xmm4_4
  float v40; // xmm2_4
  unsigned int v41; // xmm0_4
  float v42; // xmm4_4
  float v43; // xmm6_4
  unsigned int v44; // xmm1_4
  float v45; // xmm4_4
  float v46; // xmm2_4
  float v47; // xmm6_4
  bool v48; // al
  float Dst; // [rsp+20h] [rbp-E0h]
  __int64 v50; // [rsp+24h] [rbp-DCh]
  float v51; // [rsp+2Ch] [rbp-D4h]
  float v52; // [rsp+30h] [rbp-D0h]
  float v53; // [rsp+34h] [rbp-CCh]
  __int64 v54; // [rsp+38h] [rbp-C8h]
  __int64 v55; // [rsp+40h] [rbp-C0h]
  unsigned int v56; // [rsp+48h] [rbp-B8h]
  unsigned int v57; // [rsp+4Ch] [rbp-B4h]
  Scaleform::Render::Matrix3x4<float> v58; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+80h] [rbp-80h]
  Scaleform::Render::Matrix3x4<float> v60; // [rsp+B0h] [rbp-50h]
  Scaleform::Render::Matrix3x4<float> v61; // [rsp+E0h] [rbp-20h]
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+110h] [rbp+10h]
  Scaleform::Render::Matrix3x4<float> v63; // [rsp+140h] [rbp+40h]
  Scaleform::Render::Matrix3x4<float> result; // [rsp+170h] [rbp+70h]

  v2 = this;
  if ( (_BYTE)onChangeOnly
    && !Scaleform::Render::ContextImpl::Context::HasChanges(&this->RenderContext)
    && !v2->MovieDefKillList.Data.Size )
  {
    if ( v2->PreviouslyCaptured > 0 )
    {
      LOBYTE(onChangeOnly) = 1;
      v2->pASMovieRoot.pObject->vfptr[11].__vecDelDtor(
        (Scaleform::RefCountImplCore *)v2->pASMovieRoot.pObject,
        onChangeOnly);
      Scaleform::Render::ContextImpl::Context::Capture(&v2->RenderContext);
      v2->pASMovieRoot.pObject->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)v2->pASMovieRoot.pObject, 0);
      --v2->PreviouslyCaptured;
    }
    return;
  }
  v3 = v2->IndirectTransformPairs.Data.Size;
  if ( v3 )
  {
    v4 = 0i64;
    do
    {
      v5 = v2->IndirectTransformPairs.Data.Data;
      v6 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5[v4].Obj.pObject);
      v7 = v6->pPrev;
      if ( v6->pPrev )
      {
        v8 = ((_QWORD)v7->pNext & 0x80040181) != 0;
        if ( (_QWORD)v7->pNext & 0x80040181 )
          goto LABEL_10;
      }
      else
      {
        v8 = 0;
      }
      v27 = (Scaleform::Render::TreeRoot *)v5[v4].TransformParent.pObject;
      onChangeOnly = 0i64;
      if ( v27 )
      {
        while ( v27 != v2->pRenderRoot.pObject )
        {
          if ( v27->pPrev && ((_QWORD)v27->pPrev->pNext & 0x80040181) != 0 )
          {
            v8 = 1;
            break;
          }
          v27 = (Scaleform::Render::TreeRoot *)v27->pParent;
          onChangeOnly = (unsigned int)(onChangeOnly + 1);
          if ( !v27 )
            break;
        }
      }
      if ( (_DWORD)onChangeOnly == v5[v4].OrigParentDepth )
      {
        if ( !v8 )
        {
          v28 = v6->pParent;
          if ( v28 )
          {
            onChangeOnly = (__int64)v2->pRenderRoot.pObject;
            while ( v28 != (Scaleform::Render::ContextImpl::Entry *)onChangeOnly )
            {
              if ( v28->pPrev && ((_QWORD)v28->pPrev->pNext & 0x80040181) != 0 )
                goto LABEL_10;
              v28 = v28->pParent;
              if ( !v28 )
                goto LABEL_46;
            }
          }
          goto LABEL_46;
        }
      }
      else
      {
        v5[v4].OrigParentDepth = onChangeOnly;
      }
LABEL_10:
      v9 = v5[v4].Obj.pObject;
      v10 = (Scaleform::Render::TreeRoot *)v5[v4].TransformParent.pObject;
      v11 = v9->pIndXFormData;
      v12 = v11->OrigTransformMatrix.M[0][0];
      v58.M[0][0] = v11->OrigTransformMatrix.M[0][0];
      v13 = v11->OrigTransformMatrix.M[0][1];
      v58.M[0][1] = v11->OrigTransformMatrix.M[0][1];
      v14 = v11->OrigTransformMatrix.M[0][2];
      v58.M[0][2] = v11->OrigTransformMatrix.M[0][2];
      v15 = v11->OrigTransformMatrix.M[0][3];
      v58.M[0][3] = v11->OrigTransformMatrix.M[0][3];
      v16 = v11->OrigTransformMatrix.M[1][0];
      v58.M[1][0] = v11->OrigTransformMatrix.M[1][0];
      v17 = v11->OrigTransformMatrix.M[1][1];
      v58.M[1][1] = v11->OrigTransformMatrix.M[1][1];
      v18 = v11->OrigTransformMatrix.M[1][2];
      v58.M[1][2] = v11->OrigTransformMatrix.M[1][2];
      v19 = v11->OrigTransformMatrix.M[1][3];
      v58.M[1][3] = v11->OrigTransformMatrix.M[1][3];
      v20 = v11->OrigTransformMatrix.M[2][0];
      v58.M[2][0] = v11->OrigTransformMatrix.M[2][0];
      v21 = v11->OrigTransformMatrix.M[2][1];
      v58.M[2][1] = v11->OrigTransformMatrix.M[2][1];
      v22 = v11->OrigTransformMatrix.M[2][2];
      v58.M[2][2] = v11->OrigTransformMatrix.M[2][2];
      v23 = v11->OrigTransformMatrix.M[2][3];
      v58.M[2][3] = v11->OrigTransformMatrix.M[2][3];
      v24 = v11->IsOrig3D;
      if ( v10 )
      {
        while ( v10 != v2->pRenderRoot.pObject )
        {
          v25 = *(_QWORD *)(((unsigned __int64)v10 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
          v26 = *(_QWORD *)(v25
                          + 8
                          * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v10[-1]
                                                                                    - ((unsigned __int64)v10 & 0xFFFFFFFFFFFFF000ui64))
                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                           + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v10[-1]
                                                                                                - ((unsigned __int64)v10 & 0xFFFFFFFFFFFFF000ui64))
                                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                          + 40);
          if ( (*(_WORD *)(*(_QWORD *)(v25
                                     + 8
                                     * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v10[-1]
                                                                                               - ((unsigned __int64)v10 & 0xFFFFFFFFFFFFF000ui64))
                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                      + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v10[-1] - ((unsigned __int64)v10 & 0xFFFFFFFFFFFFF000ui64))
                                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                     + 40)
                         + 10i64) >> 9) & 1 )
          {
            *(_QWORD *)&m2.M[0][0] = __PAIR__(LODWORD(v13), LODWORD(v12));
            *(_QWORD *)&m2.M[0][2] = __PAIR__(LODWORD(v15), LODWORD(v14));
            *(_QWORD *)&m2.M[1][0] = __PAIR__(LODWORD(v17), LODWORD(v16));
            *(_QWORD *)&m2.M[1][2] = __PAIR__(LODWORD(v19), LODWORD(v18));
            *(_QWORD *)&m2.M[2][0] = __PAIR__(LODWORD(v21), LODWORD(v20));
            *(_QWORD *)&m2.M[2][2] = __PAIR__(LODWORD(v23), LODWORD(v22));
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &v58,
              (Scaleform::Render::Matrix3x4<float> *)(v26 + 16),
              &m2);
            v24 = 1;
          }
          else
          {
            *(_QWORD *)&v61.M[0][0] = __PAIR__(LODWORD(v13), LODWORD(v12));
            *(_QWORD *)&v61.M[0][2] = __PAIR__(LODWORD(v15), LODWORD(v14));
            *(_QWORD *)&v61.M[1][0] = __PAIR__(LODWORD(v17), LODWORD(v16));
            *(_QWORD *)&v61.M[1][2] = __PAIR__(LODWORD(v19), LODWORD(v18));
            *(_QWORD *)&v61.M[2][0] = __PAIR__(LODWORD(v21), LODWORD(v20));
            *(_QWORD *)&v61.M[2][2] = __PAIR__(LODWORD(v23), LODWORD(v22));
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              &v58,
              (Scaleform::Render::Matrix2x4<float> *)(v26 + 16),
              &v61);
          }
          v10 = (Scaleform::Render::TreeRoot *)v10->pParent;
          v19 = v58.M[1][3];
          v17 = v58.M[1][1];
          v16 = v58.M[1][0];
          v15 = v58.M[0][3];
          v13 = v58.M[0][1];
          v12 = v58.M[0][0];
          if ( !v10 )
            break;
          v23 = v58.M[2][3];
          v22 = v58.M[2][2];
          v21 = v58.M[2][1];
          v20 = v58.M[2][0];
          v18 = v58.M[1][2];
          v14 = v58.M[0][2];
        }
      }
      memset(&Dst, 0, 0x30ui64);
      v29 = (Scaleform::Render::TreeRoot *)v6->pParent;
      v30 = *(float *)&FLOAT_1_0;
      LODWORD(v31) = (_DWORD)FLOAT_1_0;
      v32 = (unsigned int)FLOAT_1_0;
      LODWORD(Dst) = (_DWORD)FLOAT_1_0;
      v53 = *(float *)&FLOAT_1_0;
      v56 = (unsigned int)FLOAT_1_0;
      if ( v29 )
      {
        while ( v29 != v2->pRenderRoot.pObject )
        {
          v33 = *(_QWORD *)(((unsigned __int64)v29 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
          v34 = *(_QWORD *)(v33
                          + 8
                          * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v29[-1]
                                                                                    - ((unsigned __int64)v29 & 0xFFFFFFFFFFFFF000ui64))
                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                           + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v29[-1]
                                                                                                - ((unsigned __int64)v29 & 0xFFFFFFFFFFFFF000ui64))
                                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                          + 40);
          if ( (*(_WORD *)(*(_QWORD *)(v33
                                     + 8
                                     * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v29[-1]
                                                                                               - ((unsigned __int64)v29 & 0xFFFFFFFFFFFFF000ui64))
                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                      + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v29[-1] - ((unsigned __int64)v29 & 0xFFFFFFFFFFFFF000ui64))
                                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                     + 40)
                         + 10i64) >> 9) & 1 )
          {
            v60.M[0][0] = v30;
            *(_QWORD *)&v60.M[0][1] = v50;
            v60.M[0][3] = v51;
            *(_QWORD *)&v60.M[1][0] = __PAIR__(LODWORD(v31), LODWORD(v52));
            *(_QWORD *)&v60.M[1][2] = v54;
            *(_QWORD *)&v60.M[2][0] = v55;
            *(_QWORD *)&v60.M[2][2] = __PAIR__(v57, v32);
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              (Scaleform::Render::Matrix3x4<float> *)&Dst,
              (Scaleform::Render::Matrix3x4<float> *)(v34 + 16),
              &v60);
            v24 = 1;
          }
          else
          {
            v63.M[0][0] = v30;
            *(_QWORD *)&v63.M[0][1] = v50;
            v63.M[0][3] = v51;
            *(_QWORD *)&v63.M[1][0] = __PAIR__(LODWORD(v31), LODWORD(v52));
            *(_QWORD *)&v63.M[1][2] = v54;
            *(_QWORD *)&v63.M[2][0] = v55;
            *(_QWORD *)&v63.M[2][2] = __PAIR__(v57, v32);
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
              (Scaleform::Render::Matrix3x4<float> *)&Dst,
              (Scaleform::Render::Matrix2x4<float> *)(v34 + 16),
              &v63);
          }
          v29 = (Scaleform::Render::TreeRoot *)v29->pParent;
          v31 = v53;
          v30 = Dst;
          if ( !v29 )
            break;
          v32 = v56;
        }
        v13 = v58.M[0][1];
        v12 = v58.M[0][0];
        v15 = v58.M[0][3];
        v17 = v58.M[1][1];
        v16 = v58.M[1][0];
        v19 = v58.M[1][3];
      }
      if ( v24 )
      {
        v35 = Scaleform::Render::Matrix3x4<float>::GetInverse((Scaleform::Render::Matrix3x4<float> *)&Dst, &result);
        Dst = v35->M[0][0];
        v36 = v35->M[0][1];
        *(_QWORD *)&m1.M[0][0] = __PAIR__(LODWORD(v36), LODWORD(Dst));
        *(float *)&v50 = v36;
        HIDWORD(v50) = LODWORD(v35->M[0][2]);
        v37 = v35->M[0][3];
        *(_QWORD *)&m1.M[0][2] = __PAIR__(LODWORD(v37), HIDWORD(v50));
        v51 = v37;
        v52 = v35->M[1][0];
        v38 = v35->M[1][1];
        *(_QWORD *)&m1.M[1][0] = __PAIR__(LODWORD(v38), LODWORD(v52));
        v53 = v38;
        *(float *)&v54 = v35->M[1][2];
        v39 = v35->M[1][3];
        *(_QWORD *)&m1.M[1][2] = __PAIR__(LODWORD(v39), (unsigned int)v54);
        *((float *)&v54 + 1) = v39;
        *(float *)&v55 = v35->M[2][0];
        v40 = v35->M[2][1];
        *(_QWORD *)&m1.M[2][0] = __PAIR__(LODWORD(v40), (unsigned int)v55);
        *((float *)&v55 + 1) = v40;
        v56 = LODWORD(v35->M[2][2]);
        v41 = LODWORD(v35->M[2][3]);
        *(_QWORD *)&m1.M[2][2] = __PAIR__(v41, v56);
        v57 = v41;
        Scaleform::Render::Matrix3x4<float>::MultiplyMatrix((Scaleform::Render::Matrix3x4<float> *)&Dst, &m1, &v58);
        Scaleform::Render::TreeNode::SetMatrix3D(v6, (Scaleform::Render::Matrix3x4<float> *)&Dst);
      }
      else
      {
        result.M[0][0] = v30;
        *(_QWORD *)&result.M[0][1] = v50;
        result.M[0][3] = v51;
        *(_QWORD *)&result.M[1][0] = __PAIR__(LODWORD(v31), LODWORD(v52));
        *(_QWORD *)&result.M[1][2] = v54;
        Scaleform::Render::Matrix2x4<float>::SetInverse(
          (Scaleform::Render::Matrix2x4<float> *)&Dst,
          (Scaleform::Render::Matrix2x4<float> *)&result);
        v42 = Dst;
        v43 = v52;
        LODWORD(v54) = 0;
        Dst = (float)(*(float *)&v50 * v16) + (float)(Dst * v12);
        v52 = (float)(v52 * v12) + (float)(v53 * v16);
        *(float *)&v44 = (float)(*(float *)&v50 * v17) + (float)(v42 * v13);
        v45 = (float)(v42 * v15) + (float)(*(float *)&v50 * v19);
        v50 = v44;
        v46 = (float)(v43 * v13) + (float)(v53 * v17);
        v47 = (float)(v43 * v15) + (float)(v53 * v19);
        v53 = v46;
        v51 = v51 + v45;
        *((float *)&v54 + 1) = *((float *)&v54 + 1) + v47;
        Scaleform::Render::TreeNode::SetMatrix(v6, (Scaleform::Render::Matrix2x4<float> *)&Dst);
      }
LABEL_46:
      ++v4;
      --v3;
    }
    while ( v3 );
  }
  if ( (v2->Flags >> 10) & 1 || (v48 = Scaleform::Render::ContextImpl::Context::HasChanges(&v2->RenderContext)) != 0 )
    v48 = 1;
  if ( v48 )
    v2->Flags |= 0x400u;
  else
    v2->Flags &= 0xFFFFFBFF;
  LOBYTE(onChangeOnly) = 1;
  v2->pASMovieRoot.pObject->vfptr[11].__vecDelDtor(
    (Scaleform::RefCountImplCore *)v2->pASMovieRoot.pObject,
    onChangeOnly);
  Scaleform::Render::ContextImpl::Context::Capture(&v2->RenderContext);
  v2->pASMovieRoot.pObject->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)v2->pASMovieRoot.pObject, 0);
  v2->PreviouslyCaptured = 1;
}

// File Line: 1901
// RVA: 0x8F30A0
void __fastcall Scaleform::GFx::MovieImpl::ProcessInput(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl *v1; // rbx
  bool v2; // r13
  signed int v3; // er14
  int v4; // esi
  Scaleform::GFx::InputEventsQueueEntry *v5; // rax
  Scaleform::GFx::InputEventsQueueEntry *v6; // rdx
  Scaleform::GFx::InputEventsQueueEntry::QueueEntryType v7; // eax
  unsigned int v8; // er12
  unsigned int i; // edi
  signed __int64 v10; // r15
  int v11; // xmm1_4
  Scaleform::GFx::InteractiveObject *v12; // rax
  Scaleform::GFx::InteractiveObject *v13; // rsi
  __int64 v14; // [rsp+30h] [rbp-69h]
  int v15; // [rsp+38h] [rbp-61h]
  char v16; // [rsp+3Ch] [rbp-5Dh]
  int v17; // [rsp+40h] [rbp-59h]
  Scaleform::String *v18; // [rsp+48h] [rbp-51h]
  Scaleform::String *v19; // [rsp+50h] [rbp-49h]
  Scaleform::String *v20; // [rsp+58h] [rbp-41h]
  Scaleform::String *v21; // [rsp+60h] [rbp-39h]
  Scaleform::GFx::ProcessFocusKeyInfo focusKeyInfo; // [rsp+70h] [rbp-29h]
  __int64 v23; // [rsp+B0h] [rbp+17h]
  unsigned int miceProceededMask; // [rsp+100h] [rbp+67h]
  int v25; // [rsp+104h] [rbp+6Bh]
  Scaleform::GFx::InteractiveObject *v26; // [rsp+108h] [rbp+6Fh]

  v23 = -2i64;
  v1 = this;
  if ( this->pMainMovie )
  {
    v2 = this->pASMovieRoot.pObject->AVMVersion == 2;
    _mm_store_si128((__m128i *)&focusKeyInfo, (__m128i)0i64);
    focusKeyInfo.CurFocusIdx = -1;
    focusKeyInfo.Prev_aRect = 0i64;
    *(_QWORD *)&focusKeyInfo.PrevKeyCode = 0i64;
    *(_DWORD *)&focusKeyInfo.KeyboardIndex = 0;
    focusKeyInfo.Initialized = 0;
    miceProceededMask = 0;
    v3 = 1;
    v4 = (1 << this->MouseCursorCount) - 1;
    while ( v1->InputEventsQueue.UsedEntries || v1->InputEventsQueue.LastMousePosMask )
    {
      v5 = Scaleform::GFx::InputEventsQueue::GetEntry(&v1->InputEventsQueue);
      v6 = v5;
      v7 = v5->t;
      if ( v7 == 1 )
      {
        Scaleform::GFx::MovieImpl::ProcessKeyboard(v1, v6, &focusKeyInfo);
      }
      else if ( v7 )
      {
        switch ( v7 )
        {
          case 7:
            v14 = 16777254i64;
            v15 = 0;
            v16 = 0;
            v17 = 65280;
            v18 = v6->u.statusEntry.Code;
            v19 = v6->u.statusEntry.Level;
            v20 = v6->u.statusEntry.ExtensionId;
            v21 = v6->u.statusEntry.ContextId;
            v1->pASMovieRoot.pObject->vfptr[23].__vecDelDtor(
              (Scaleform::RefCountImplCore *)&v1->pASMovieRoot.pObject->vfptr,
              (unsigned int)&v14);
            break;
          case 5:
            Scaleform::GFx::MovieImpl::ProcessAccelerometer(v1, v6);
            break;
          case 6:
            Scaleform::GFx::MovieImpl::ProcessGeolocation(v1, v6);
            break;
        }
      }
      else
      {
        Scaleform::GFx::MovieImpl::ProcessMouse(v1, v6, &miceProceededMask, v2);
      }
    }
    if ( (v1->Flags >> 7) & 1 )
    {
      v8 = miceProceededMask;
      if ( (miceProceededMask & v4) != v4 )
      {
        for ( i = 0; i < v1->MouseCursorCount; v3 *= 2 )
        {
          if ( !(v3 & v8) && *((_BYTE *)&v1->mMouseState[i] + 76) & 0x10 )
          {
            v10 = (signed __int64)v1 + 80 * i;
            *(_DWORD *)(v10 + 8748) = *(_DWORD *)(v10 + 8744);
            v11 = LODWORD(v1->mMouseState[i].LastPosition.y);
            miceProceededMask = LODWORD(v1->mMouseState[i].LastPosition.x);
            v25 = v11;
            v12 = Scaleform::GFx::MovieImpl::GetTopMostEntity(
                    v1,
                    (Scaleform::Render::Point<float> *)&miceProceededMask,
                    i,
                    v2,
                    0i64);
            v13 = v12;
            if ( v12 )
              ++v12->RefCount;
            v26 = v12;
            Scaleform::GFx::MouseState::SetTopmostEntity((Scaleform::GFx::MouseState *)(v10 + 8696), v12);
            Scaleform::GFx::MovieImpl::CheckMouseCursorType(v1, i, v13);
            v1->pASMovieRoot.pObject->vfptr[13].__vecDelDtor((Scaleform::RefCountImplCore *)v1->pASMovieRoot.pObject, i);
            if ( v13 )
              Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v13->vfptr);
          }
          ++i;
        }
      }
    }
    Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(v1, &focusKeyInfo);
    v1->Flags &= 0xFFFFFF7F;
    if ( focusKeyInfo.CurFocused.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&focusKeyInfo.CurFocused.pObject->vfptr);
  }
}

// File Line: 2012
// RVA: 0x8F0D30
void __fastcall Scaleform::GFx::MovieImpl::ProcessAccelerometer(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InputEventsQueueEntry *qe)
{
  long double v2; // xmm0_8
  long double v3; // xmm1_8
  float v4; // er8
  Scaleform::GFx::ASMovieRootBase *v5; // rcx
  long double v6; // xmm0_8
  long double v7; // xmm1_8
  __int64 v8; // [rsp+20h] [rbp-48h]
  int v9; // [rsp+28h] [rbp-40h]
  char v10; // [rsp+2Ch] [rbp-3Ch]
  int v11; // [rsp+30h] [rbp-38h]
  float v12; // [rsp+34h] [rbp-34h]
  long double v13; // [rsp+38h] [rbp-30h]
  long double v14; // [rsp+40h] [rbp-28h]
  long double v15; // [rsp+48h] [rbp-20h]
  long double v16; // [rsp+50h] [rbp-18h]

  v2 = qe->u.accelerometerEntry.Timestamp;
  v3 = qe->u.accelerometerEntry.AccelerationX;
  v4 = qe->u.mouseEntry.PosX;
  v5 = this->pASMovieRoot.pObject;
  v8 = 16777252i64;
  v13 = v2;
  v6 = qe->u.accelerometerEntry.AccelerationY;
  v14 = v3;
  v9 = 0;
  v10 = 0;
  v11 = 65280;
  v7 = qe->u.accelerometerEntry.AccelerationZ;
  v15 = v6;
  v12 = v4;
  v16 = v7;
  v5->vfptr[24].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v8);
}

// File Line: 2024
// RVA: 0x8F2040
void __fastcall Scaleform::GFx::MovieImpl::ProcessGeolocation(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InputEventsQueueEntry *qe)
{
  long double v2; // xmm0_8
  long double v3; // xmm1_8
  float v4; // er8
  Scaleform::GFx::ASMovieRootBase *v5; // rcx
  long double v6; // xmm0_8
  long double v7; // xmm1_8
  long double v8; // xmm0_8
  long double v9; // xmm1_8
  long double v10; // xmm0_8
  long double v11; // xmm1_8
  __int64 v12; // [rsp+20h] [rbp-68h]
  int v13; // [rsp+28h] [rbp-60h]
  char v14; // [rsp+2Ch] [rbp-5Ch]
  int v15; // [rsp+30h] [rbp-58h]
  float v16; // [rsp+34h] [rbp-54h]
  long double v17; // [rsp+38h] [rbp-50h]
  long double v18; // [rsp+40h] [rbp-48h]
  long double v19; // [rsp+48h] [rbp-40h]
  long double v20; // [rsp+50h] [rbp-38h]
  long double v21; // [rsp+58h] [rbp-30h]
  long double v22; // [rsp+60h] [rbp-28h]
  long double v23; // [rsp+68h] [rbp-20h]
  long double v24; // [rsp+70h] [rbp-18h]

  v2 = qe->u.accelerometerEntry.Timestamp;
  v3 = qe->u.accelerometerEntry.AccelerationX;
  v4 = qe->u.mouseEntry.PosX;
  v5 = this->pASMovieRoot.pObject;
  v12 = 16777253i64;
  v17 = v2;
  v6 = qe->u.accelerometerEntry.AccelerationY;
  v18 = v3;
  v13 = 0;
  v14 = 0;
  v15 = 65280;
  v7 = qe->u.accelerometerEntry.AccelerationZ;
  v19 = v6;
  v8 = qe->u.geolocationEntry.VAccuracy;
  v16 = v4;
  v20 = v7;
  v9 = qe->u.geolocationEntry.Speed;
  v21 = v8;
  v10 = qe->u.geolocationEntry.Heading;
  v22 = v9;
  v11 = qe->u.geolocationEntry.Timestamp;
  v23 = v10;
  v24 = v11;
  v5->vfptr[25].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v12);
}

// File Line: 2040
// RVA: 0x8F3320
void __fastcall Scaleform::GFx::MovieImpl::ProcessKeyboard(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InputEventsQueueEntry *qe, Scaleform::GFx::ProcessFocusKeyInfo *focusKeyInfo)
{
  Scaleform::GFx::ProcessFocusKeyInfo *v3; // r15
  Scaleform::GFx::MovieImpl *v4; // rsi
  signed __int64 v5; // rbp
  unsigned int v6; // er10
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry *v7; // rdi
  float v8; // er9
  unsigned __int8 v9; // al
  Scaleform::GFx::Event::EventType v10; // er14
  int v11; // er8
  char v12; // al
  char v13; // dl
  char v14; // cl
  __int64 v15; // r9
  int v16; // ebx
  Scaleform::GFx::InteractiveObject *v17; // rcx
  __int64 v18; // rax
  Scaleform::GFx::InteractiveObject *v19; // rdx
  __int64 v20; // rcx
  signed int v21; // eax
  Scaleform::GFx::Sprite *v22; // rbx
  int v23; // [rsp+30h] [rbp-48h]
  unsigned int v24; // [rsp+34h] [rbp-44h]
  float v25; // [rsp+38h] [rbp-40h]
  char v26; // [rsp+3Ch] [rbp-3Ch]
  char v27; // [rsp+40h] [rbp-38h]
  char v28; // [rsp+41h] [rbp-37h]
  char v29; // [rsp+42h] [rbp-36h]
  char v30; // [rsp+43h] [rbp-35h]
  unsigned int v31; // [rsp+88h] [rbp+10h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+98h] [rbp+20h]

  v3 = focusKeyInfo;
  v4 = this;
  v5 = 0i64;
  v6 = 0;
  v31 = 0;
  v7 = (Scaleform::GFx::InputEventsQueueEntry::KeyEntry *)&qe->u;
  v8 = qe->u.mouseEntry.PosY;
  if ( v8 == 0.0 )
  {
    if ( v7->WcharCode )
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[(unsigned __int8)qe->u.mouseEntry.WheelScrollDelta]].LastFocused,
        &result);
      v22 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        v22 = result.pObject;
      }
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
      if ( v22 )
        ((void (__fastcall *)(Scaleform::GFx::Sprite *, _QWORD, _QWORD))v22->vfptr[97].__vecDelDtor)(
          v22,
          v7->WcharCode,
          (unsigned __int8)v7->KeyboardIndex);
      if ( v22 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v22->vfptr);
    }
  }
  else
  {
    if ( qe->u.mouseEntry.Flags )
    {
      v9 = 64;
      v10 = 5;
    }
    else
    {
      v9 = -128;
      v10 = 6;
    }
    v11 = v9;
    v23 = v9;
    v24 = v7->WcharCode;
    v25 = v8;
    v26 = qe->u.keyEntry.AsciiCode;
    v27 = 0;
    v30 = 0;
    v28 = qe->u.mouseEntry.WheelScrollDelta;
    v12 = qe->u.keyEntry.KeysState | 0x80;
    v29 = qe->u.keyEntry.KeysState | 0x80;
    if ( !v26 )
    {
      v13 = 0;
      v14 = v12 & 1;
      if ( v12 & 8 )
        v14 = v14 == 0;
      if ( (unsigned int)(LODWORD(v8) - 32) > 0x50 )
      {
        v15 = (unsigned int)(LODWORD(v8) - 186);
        if ( (unsigned int)v15 <= 0x50 )
        {
          if ( v14 )
            v13 = *(_BYTE *)(v15 + 5394558744i64);
          else
            v13 = *(_BYTE *)(v15 + 5394558704i64);
        }
      }
      else if ( v14 )
      {
        v13 = asciiShift1[LODWORD(v8) - 32];
      }
      else
      {
        v13 = ascii1[LODWORD(v8) - 32];
      }
      v26 = v13;
    }
    v16 = v4->MovieLevels.Data.Size;
    if ( v16 )
    {
      do
      {
        v17 = v4->MovieLevels.Data.Data[--v16].pSprite.pObject;
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, int *, unsigned int *))v17->vfptr[101].__vecDelDtor)(
          v17,
          &v23,
          &v31);
      }
      while ( v16 );
      v6 = v31;
      v11 = v23;
    }
    v18 = (unsigned __int8)v7->KeyboardIndex;
    if ( (unsigned int)v18 < 6 )
      v5 = (signed __int64)&v4->KeyboardStates[v18];
    v19 = v4->pMainMovie;
    v20 = *(_QWORD *)(v5 + 16);
    if ( v20 )
    {
      if ( v11 == 64 )
      {
        (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *, int *, _QWORD, signed __int64))(*(_QWORD *)v20 + 8i64))(
          v20,
          v19,
          &v23,
          v6,
          -2i64);
      }
      else if ( v11 == 128 )
      {
        (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *, int *, _QWORD, signed __int64))(*(_QWORD *)v20 + 16i64))(
          v20,
          v19,
          &v23,
          v6,
          -2i64);
      }
    }
    v21 = v4->Flags >> 30;
    if ( v21 == 3 )
      v21 = -1;
    if ( v21 != 1 )
      Scaleform::GFx::MovieImpl::ProcessFocusKey(v4, v10, v7, v3);
  }
}

// File Line: 2102
// RVA: 0x8F36F0
void __fastcall Scaleform::GFx::MovieImpl::ProcessMouse(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InputEventsQueueEntry *qe, unsigned int *miceProceededMask, bool avm2)
{
  Scaleform::GFx::InputEventsQueueEntry *v4; // rbx
  Scaleform::GFx::MovieImpl *v5; // rdi
  __int64 v6; // rsi
  signed __int64 v7; // r12
  Scaleform::GFx::MouseState *v8; // r13
  char v9; // dl
  unsigned int v10; // er8
  unsigned __int16 v11; // cx
  char v12; // al
  char v13; // dl
  float v14; // xmm0_4
  float v15; // xmm1_4
  Scaleform::GFx::InteractiveObject *v16; // rax
  Scaleform::GFx::InteractiveObject *v17; // r14
  Scaleform::GFx::InteractiveObject *v18; // rcx
  signed int v19; // er15
  char v20; // al
  unsigned __int64 v21; // rax
  char v22; // r13
  __int64 v23; // r14
  int v24; // er12
  Scaleform::GFx::InteractiveObject *v25; // rsi
  int v26; // ecx
  Scaleform::GFx::Sprite *v27; // rbx
  Scaleform::GFx::InteractiveObject *v28; // [rsp+30h] [rbp-40h]
  Scaleform::GFx::MouseState *v29; // [rsp+38h] [rbp-38h]
  __int64 v30; // [rsp+50h] [rbp-20h]
  int v31; // [rsp+58h] [rbp-18h]
  char v32; // [rsp+5Ch] [rbp-14h]
  char v33; // [rsp+60h] [rbp-10h]
  char v34; // [rsp+61h] [rbp-Fh]
  __int16 v35; // [rsp+62h] [rbp-Eh]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+B0h] [rbp+40h]
  Scaleform::Render::Point<float> mousePos; // [rsp+B8h] [rbp+48h]
  __int64 v38; // [rsp+C0h] [rbp+50h]

  v4 = qe;
  v5 = this;
  *miceProceededMask |= 1 << qe->u.mouseEntry.MouseIndex;
  v6 = (unsigned __int8)qe->u.mouseEntry.MouseIndex;
  LODWORD(result.pObject) = (unsigned __int8)qe->u.mouseEntry.MouseIndex;
  v7 = 80 * v6;
  v38 = 80 * v6;
  v8 = &this->mMouseState[v6];
  v29 = v8;
  *((_BYTE *)v8 + 76) |= 0x10u;
  v9 = *((_BYTE *)v8 + 76);
  v10 = v8->CurButtonsState;
  v8->PrevButtonsState = v10;
  v11 = v4->u.mouseEntry.ButtonsState;
  if ( v11 )
  {
    v12 = v4->u.mouseEntry.Flags;
    if ( v12 & 0x40 || v12 >= 0 || !v11 )
      v8->CurButtonsState = v10 | v11;
    else
      v8->CurButtonsState = v10 & ~v11;
  }
  if ( v4->u.mouseEntry.Flags & 0x20 )
    v8->WheelDelta = v4->u.mouseEntry.WheelScrollDelta;
  else
    v8->WheelDelta = 0;
  if ( v4->u.accelerometerEntry.IdAcc != SLODWORD(v8->LastPosition.x)
    || v4->u.keyEntry.Code != SLODWORD(v8->LastPosition.y) )
  {
    v13 = v9 | 8;
  }
  else
  {
    v13 = v9 & 0xF7;
  }
  *((_BYTE *)v8 + 76) = v13;
  v14 = v4->u.mouseEntry.PosY;
  v8->LastPosition.x = v4->u.mouseEntry.PosX;
  v8->LastPosition.y = v14;
  v15 = v4->u.mouseEntry.PosY;
  mousePos.x = v4->u.mouseEntry.PosX;
  mousePos.y = v15;
  v16 = Scaleform::GFx::MovieImpl::GetTopMostEntity(v5, &mousePos, v6, avm2, 0i64);
  v17 = v16;
  v28 = v16;
  if ( v16 )
    ++v16->RefCount;
  Scaleform::GFx::MouseState::SetTopmostEntity(v8, v16);
  v18 = v5->CurrentDragStates[v6].pCharacter;
  if ( v18 )
    Scaleform::GFx::InteractiveObject::DoMouseDrag(v18, v6);
  v19 = 0;
  if ( v4->u.mouseEntry.ButtonsState && v4->u.keyEntry.AsciiCode & 1 )
  {
    if ( v4->u.mouseEntry.Flags & 0xC0 || (v20 = 1, !v4->u.mouseEntry.ButtonsState) )
      v20 = 0;
    v19 = 32;
    if ( v20 )
      v19 = 16;
  }
  v21 = v5->MovieLevels.Data.Size;
  if ( (_DWORD)v21 )
  {
    v22 = (char)result.pObject;
    v23 = v38;
    do
    {
      v24 = v21 - 1;
      v25 = v5->MovieLevels.Data.Data[(unsigned int)(v21 - 1)].pSprite.pObject;
      if ( v19 )
      {
        LODWORD(v30) = v19;
        *(__int64 *)((char *)&v30 + 4) = 0i64;
        v35 = 0;
        v32 = 0;
        v34 = v22;
        v33 = 0;
        v25->vfptr[99].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v25->vfptr, (unsigned int)&v30);
      }
      if ( *((_BYTE *)v5->mMouseState + v23 + 76) & 8 )
      {
        v30 = 8i64;
        v31 = 0;
        v35 = 0;
        v32 = 0;
        v34 = v22;
        v33 = 0;
        v25->vfptr[99].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v25->vfptr, (unsigned int)&v30);
      }
      LODWORD(v21) = v24;
    }
    while ( v24 );
    v17 = v28;
    v8 = v29;
    LODWORD(v6) = result.pObject;
    v7 = v38;
  }
  if ( !((v5->Flags >> 16) & 1) && v4->u.mouseEntry.ButtonsState )
    goto LABEL_58;
  v26 = (v5->Flags >> 22) & 3;
  if ( v26 == 3 )
    v26 = -1;
  if ( v26 != 1 && *((_BYTE *)v5->mMouseState + v7 + 76) & 8 )
LABEL_58:
    Scaleform::GFx::MovieImpl::HideFocusRect(v5, v6);
  if ( v4->u.mouseEntry.Flags & 0x20 && v17 )
    v17->vfptr[98].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v17->vfptr, v4->u.mouseEntry.WheelScrollDelta);
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::InputEventsQueueEntry *, Scaleform::GFx::MouseState *, _QWORD))v5->pASMovieRoot.pObject->vfptr[18].__vecDelDtor)(
    v5->pASMovieRoot.pObject,
    v4,
    v8,
    (unsigned int)v6);
  Scaleform::GFx::MovieImpl::CheckMouseCursorType(v5, v6, v17);
  if ( !(v4->u.mouseEntry.Flags & 0xC0) && v4->u.mouseEntry.ButtonsState && v4->u.keyEntry.AsciiCode & 1 )
  {
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v5->FocusGroups[(unsigned __int8)v5->FocusGroupIndexes[(unsigned int)v6]].LastFocused,
      &result);
    v27 = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      v27 = result.pObject;
    }
    mousePos = (Scaleform::Render::Point<float>)v27;
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
    if ( v17 != (Scaleform::GFx::InteractiveObject *)v27 )
      Scaleform::GFx::MovieImpl::QueueSetFocusTo(v5, v17, v17, v6, GFx_FocusMovedByMouse, 0i64);
    if ( v27 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v27->vfptr);
  }
  v5->pASMovieRoot.pObject->vfptr[13].__vecDelDtor((Scaleform::RefCountImplCore *)v5->pASMovieRoot.pObject, v6);
  if ( v17 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v17->vfptr);
}

// File Line: 2211
// RVA: 0x906EF0
void __fastcall Scaleform::GFx::MovieImpl::SetDragState(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::MovieImpl::DragState *st)
{
  __int64 v2; // r8
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4

  v2 = st->MouseIndex;
  this->CurrentDragStates[v2].pCharacter = st->pCharacter;
  this->CurrentDragStates[v2].pTopmostEntity = st->pTopmostEntity;
  this->CurrentDragStates[v2].LockCenter = st->LockCenter;
  this->CurrentDragStates[v2].Bound = st->Bound;
  v3 = st->BoundLT.y;
  this->CurrentDragStates[v2].BoundLT.x = st->BoundLT.x;
  this->CurrentDragStates[v2].BoundLT.y = v3;
  v4 = st->BoundRB.y;
  this->CurrentDragStates[v2].BoundRB.x = st->BoundRB.x;
  this->CurrentDragStates[v2].BoundRB.y = v4;
  v5 = st->CenterDelta.y;
  this->CurrentDragStates[v2].CenterDelta.x = st->CenterDelta.x;
  this->CurrentDragStates[v2].CenterDelta.y = v5;
  this->CurrentDragStates[v2].MouseIndex = st->MouseIndex;
}

// File Line: 2217
// RVA: 0x8D7010
void __fastcall Scaleform::GFx::MovieImpl::GetDragState(Scaleform::GFx::MovieImpl *this, unsigned int mouseIndex, Scaleform::GFx::MovieImpl::DragState *st)
{
  __int64 v3; // rdx
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4

  v3 = mouseIndex;
  st->pCharacter = this->CurrentDragStates[v3].pCharacter;
  st->pTopmostEntity = this->CurrentDragStates[v3].pTopmostEntity;
  st->LockCenter = this->CurrentDragStates[v3].LockCenter;
  st->Bound = this->CurrentDragStates[v3].Bound;
  v4 = this->CurrentDragStates[v3].BoundLT.y;
  st->BoundLT.x = this->CurrentDragStates[v3].BoundLT.x;
  st->BoundLT.y = v4;
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
void __fastcall Scaleform::GFx::MovieImpl::SetDragStateTopmostEntity(Scaleform::GFx::MovieImpl *this, unsigned int mouseIndex, Scaleform::GFx::InteractiveObject *topmostEntity)
{
  (&this->vfptr)[6 * (mouseIndex + 401i64)] = (Scaleform::RefCountImplCoreVtbl *)topmostEntity;
}

// File Line: 2229
// RVA: 0x9118B0
void __fastcall Scaleform::GFx::MovieImpl::StopDrag(Scaleform::GFx::MovieImpl *this, unsigned int mouseIndex)
{
  signed __int64 v2; // rax
  __int64 v3; // rdx

  v2 = mouseIndex + 401i64;
  v3 = mouseIndex;
  this->CurrentDragStates[v3].pCharacter = 0i64;
  this->CurrentDragStates[v3].MouseIndex = -1;
  (&this->vfptr)[6 * v2] = 0i64;
}

// File Line: 2237
// RVA: 0x9118F0
void __fastcall Scaleform::GFx::MovieImpl::StopDragCharacter(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InteractiveObject *ch)
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
void __fastcall Scaleform::GFx::MovieImpl::AdvanceFrame(Scaleform::GFx::MovieImpl *this, bool nextFrame, float framePos)
{
  bool v3; // r15
  Scaleform::GFx::MovieImpl *v4; // rsi
  unsigned int v5; // ecx
  unsigned __int64 v6; // rdi
  unsigned int v8; // eax
  char v9; // r12
  unsigned int v10; // eax
  Scaleform::RefCountNTSImpl *i; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v12; // rdx
  unsigned __int64 j; // r14
  Scaleform::GFx::InteractiveObject *v14; // rbx
  unsigned int v16; // edx
  unsigned int v17; // edx
  unsigned int v18; // edx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v19; // rdx
  unsigned __int64 v20; // rdi
  Scaleform::RefCountNTSImpl **v21; // rbx
  Scaleform::RefCountNTSImpl *k; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v24; // rdx
  Scaleform::GFx::InteractiveObject *v25; // rcx
  unsigned __int64 v27; // rdi
  Scaleform::RefCountNTSImpl **v28; // rbx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+30h] [rbp-30h]

  v3 = nextFrame;
  v4 = this;
  if ( nextFrame )
    ((void (__cdecl *)(Scaleform::GFx::ASMovieRootBase *))this->pASMovieRoot.pObject->vfptr[27].__vecDelDtor)(this->pASMovieRoot.pObject);
  v5 = v4->Flags;
  v6 = 0i64;
  if ( (v4->Flags >> 19) & 1 )
  {
    _RAX = v4->pPlayListHead;
    __asm
    {
      prefetcht1 byte ptr [rax+0C0h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+0A0h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+80h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+60h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+40h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+20h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax]; Prefetch to all cache levels
    }
    v4->pPlayListOptHead = 0i64;
    v4->Flags = v5 & 0xFFF7FFFF;
    v8 = v4->Flags2;
    v9 = ~(unsigned __int8)(v4->Flags2 >> 3) & 1;
    if ( v9 )
      v10 = v8 | 8;
    else
      v10 = v8 & 0xFFFFFFF7;
    v4->Flags2 = v10;
    pheapAddr.Data = 0i64;
    pheapAddr.Size = 0i64;
    pheapAddr.Policy.Capacity = 0i64;
    for ( i = (Scaleform::RefCountNTSImpl *)&v4->pPlayListHead->vfptr; i; i = (Scaleform::RefCountNTSImpl *)i[9].vfptr )
    {
      ++i->RefCount;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
      v12 = &pheapAddr.Data[pheapAddr.Size - 1];
      if ( v12 )
      {
        if ( i )
          ++i->RefCount;
        v12->pObject = (Scaleform::GFx::InteractiveObject *)i;
      }
      if ( i )
        Scaleform::RefCountNTSImpl::Release(i);
    }
    for ( j = 0i64; j < pheapAddr.Size; ++j )
    {
      v14 = pheapAddr.Data[j].pObject;
      _RAX = v14->pPlayNext;
      __asm
      {
        prefetcht1 byte ptr [rax+0C0h]; Prefetch to all cache levels
        prefetcht1 byte ptr [rax+0A0h]; Prefetch to all cache levels
        prefetcht1 byte ptr [rax+80h]; Prefetch to all cache levels
        prefetcht1 byte ptr [rax+60h]; Prefetch to all cache levels
        prefetcht1 byte ptr [rax+40h]; Prefetch to all cache levels
        prefetcht1 byte ptr [rax+20h]; Prefetch to all cache levels
        prefetcht1 byte ptr [rax]; Prefetch to all cache levels
      }
      v16 = v14->Flags;
      if ( !((v14->Flags >> 21) & 1) || ((unsigned __int8)(v4->Flags2 >> 3) ^ (unsigned __int8)(v16 >> 23)) & 1 )
      {
        v17 = v16 & 0xFFDFFFFF;
        v14->Flags = v17;
        if ( v9 )
          v18 = v17 | 0x800000;
        else
          v18 = v17 & 0xFF7FFFFF;
        v14->Flags = v18;
        v14->pPlayPrevOpt = 0i64;
        v14->pPlayNextOpt = 0i64;
      }
      if ( ~(LOBYTE(v14->Flags) >> 6) & 1 && !((LOBYTE(v14->Flags) >> 5) & 1) )
      {
        if ( (!((v14->Flags >> 21) & 1) || ((unsigned __int8)(v4->Flags2 >> 3) ^ (unsigned __int8)(v14->Flags >> 23)) & 1)
          && (unsigned int)v14->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v14->vfptr, 0) == 1 )
        {
          Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v14);
        }
        if ( v3 || (v14->Flags >> 20) & 1 )
          v14->vfptr[71].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v14->vfptr, v3);
      }
    }
    v19 = pheapAddr.Data;
    v20 = pheapAddr.Size;
    v21 = (Scaleform::RefCountNTSImpl **)&pheapAddr.Data[pheapAddr.Size - 1];
    if ( pheapAddr.Size )
    {
      do
      {
        if ( *v21 )
          Scaleform::RefCountNTSImpl::Release(*v21);
        --v21;
        --v20;
      }
      while ( v20 );
LABEL_58:
      v19 = pheapAddr.Data;
      goto LABEL_59;
    }
  }
  else
  {
    _RAX = v4->pPlayListOptHead;
    __asm
    {
      prefetcht1 byte ptr [rax+0C0h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+0A0h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+80h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+60h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+40h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+20h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax]; Prefetch to all cache levels
    }
    pheapAddr.Data = 0i64;
    pheapAddr.Size = 0i64;
    pheapAddr.Policy.Capacity = 0i64;
    for ( k = (Scaleform::RefCountNTSImpl *)&v4->pPlayListOptHead->vfptr; k; k = (Scaleform::RefCountNTSImpl *)k[10].vfptr )
    {
      ++k->RefCount;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
      v24 = &pheapAddr.Data[pheapAddr.Size - 1];
      if ( v24 )
      {
        if ( k )
          ++k->RefCount;
        v24->pObject = (Scaleform::GFx::InteractiveObject *)k;
      }
      if ( k )
        Scaleform::RefCountNTSImpl::Release(k);
    }
    if ( pheapAddr.Size )
    {
      do
      {
        v25 = pheapAddr.Data[v6].pObject;
        _RAX = v25->pPlayNextOpt;
        __asm
        {
          prefetcht1 byte ptr [rax+0C0h]; Prefetch to all cache levels
          prefetcht1 byte ptr [rax+0A0h]; Prefetch to all cache levels
          prefetcht1 byte ptr [rax+80h]; Prefetch to all cache levels
          prefetcht1 byte ptr [rax+60h]; Prefetch to all cache levels
          prefetcht1 byte ptr [rax+40h]; Prefetch to all cache levels
          prefetcht1 byte ptr [rax+20h]; Prefetch to all cache levels
          prefetcht1 byte ptr [rax]; Prefetch to all cache levels
        }
        if ( (v25->Flags >> 22) & 1 )
        {
          Scaleform::GFx::InteractiveObject::RemoveFromOptimizedPlayList(v25);
        }
        else if ( ~(LOBYTE(v25->Flags) >> 6) & 1 && (v3 || (v25->Flags >> 20) & 1) && !((LOBYTE(v25->Flags) >> 5) & 1) )
        {
          v25->vfptr[71].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v25->vfptr, v3);
        }
        ++v6;
      }
      while ( v6 < pheapAddr.Size );
    }
    v19 = pheapAddr.Data;
    v27 = pheapAddr.Size;
    v28 = (Scaleform::RefCountNTSImpl **)&pheapAddr.Data[pheapAddr.Size - 1];
    if ( pheapAddr.Size )
    {
      do
      {
        if ( *v28 )
          Scaleform::RefCountNTSImpl::Release(*v28);
        --v28;
        --v27;
      }
      while ( v27 );
      goto LABEL_58;
    }
  }
LABEL_59:
  if ( v19 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v19);
  v4->Flags2 &= 0xFFFFFFFD;
}

// File Line: 2728
// RVA: 0x8BAFB0
void __fastcall Scaleform::GFx::MovieImpl::CheckMouseCursorType(Scaleform::GFx::MovieImpl *this, unsigned int mouseIdx, Scaleform::GFx::InteractiveObject *ptopMouseCharacter)
{
  unsigned int v3; // er14
  Scaleform::GFx::MovieImpl *v4; // r15
  Scaleform::GFx::InteractiveObject *v5; // rdi
  char *v6; // rbp
  unsigned int v7; // ebx
  unsigned int v8; // ecx

  v3 = mouseIdx;
  v4 = this;
  v5 = ptopMouseCharacter;
  v6 = (char *)this + 80 * mouseIdx;
  if ( Scaleform::GFx::MouseState::IsTopmostEntityChanged((Scaleform::GFx::MouseState *)(v6 + 8696)) )
  {
    v7 = 0;
    if ( v5 )
      v7 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v5->vfptr[116].__vecDelDtor)(v5);
    if ( *((_DWORD *)v6 + 2191) != v7 )
      ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, _QWORD, _QWORD))v4->pASMovieRoot.pObject->vfptr[3].__vecDelDtor)(
        v4->pASMovieRoot.pObject,
        v3,
        v7);
    v8 = *((_DWORD *)v6 + 2190);
    if ( v8 == -1 )
      v8 = v7;
    *((_DWORD *)v6 + 2191) = v8;
  }
}

// File Line: 2739
// RVA: 0x8BA3B0
void __fastcall Scaleform::GFx::MovieImpl::ChangeMouseCursorType(Scaleform::GFx::MovieImpl *this, unsigned int mouseIdx, unsigned int newCursorType)
{
  unsigned int v3; // edi
  char *v4; // rbx
  unsigned int v5; // eax

  v3 = newCursorType;
  v4 = (char *)this + 80 * mouseIdx;
  if ( *((_DWORD *)v4 + 2191) != newCursorType )
    ((void (*)(void))this->pASMovieRoot.pObject->vfptr[3].__vecDelDtor)();
  v5 = *((_DWORD *)v4 + 2190);
  if ( v5 == -1 )
    v5 = v3;
  *((_DWORD *)v4 + 2191) = v5;
}

// File Line: 2747
// RVA: 0x8E2610
signed __int64 __fastcall Scaleform::GFx::MovieImpl::HandleEvent(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::Event *event)
{
  Scaleform::GFx::Event *v2; // rbx
  Scaleform::GFx::MovieImpl *v3; // rdi
  signed __int64 v4; // rax
  signed __int64 v5; // r8
  Scaleform::GFx::Event *v6; // rbx
  __int64 v7; // rdx
  _BYTE *v8; // rcx
  __int64 v9; // rax
  Scaleform::GFx::KeyboardState *v10; // rcx
  unsigned __int8 v11; // al
  __int64 v12; // rsi
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  unsigned int v16; // esi
  float v17; // xmm1_4
  float v18; // xmm6_4
  signed int v19; // ebx
  Scaleform::GFx::InputEventsQueueEntry *v20; // rax
  float v21; // xmm0_4
  unsigned int v22; // esi
  float v23; // xmm1_4
  float v24; // xmm6_4
  signed int v25; // ebx
  Scaleform::GFx::InputEventsQueueEntry *v26; // rax
  float v27; // xmm0_4
  unsigned int v28; // esi
  float v29; // xmm1_4
  float v30; // xmm6_4
  signed int v31; // ebx
  Scaleform::GFx::InputEventsQueueEntry *v32; // rax
  float v33; // xmm0_4
  __int64 v34; // rax
  signed __int64 v35; // rsi
  signed int v36; // er11
  char v37; // r8
  Scaleform::KeyModifiers specialKeysState; // ST28_1
  unsigned int v39; // edx
  __int64 v40; // rax
  signed __int64 v41; // rsi
  signed int v42; // er11
  char v43; // r8
  Scaleform::KeyModifiers v44; // ST28_1
  Scaleform::Render::Point<float> p; // [rsp+80h] [rbp+20h]
  Scaleform::Render::Point<float> result; // [rsp+90h] [rbp+30h]

  v2 = event;
  v3 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[41].__vecDelDtor)() )
  {
    if ( v2->Type != 8 )
      return 0i64;
    goto LABEL_5;
  }
  if ( v2->Type == 8 )
  {
LABEL_5:
    v5 = (signed __int64)v3->KeyboardStates;
    v6 = v2 + 1;
    LODWORD(v7) = 0;
    do
    {
      if ( LOBYTE(v6->Type) )
      {
        v8 = 0i64;
        if ( (unsigned int)v7 < 6 )
          v8 = (_BYTE *)v5;
        v8[1666] = (LOBYTE(v6->Type) >> 4) & 1;
        v8[1667] = (LOBYTE(v6->Type) >> 3) & 1;
        v8[1668] = (LOBYTE(v6->Type) >> 5) & 1;
      }
      v7 = (unsigned int)(v7 + 1);
      v5 += 1672i64;
      v6 = (Scaleform::GFx::Event *)((char *)v6 + 1);
    }
    while ( (unsigned int)v7 < 6 );
    v3->Flags |= 0x40000u;
    LOBYTE(v7) = 1;
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, __int64, signed __int64))v3->pASMovieRoot.pObject->vfptr[26].__vecDelDtor)(
      v3->pASMovieRoot.pObject,
      v7,
      v5);
    return 1i64;
  }
  if ( (unsigned int)(v2->Type - 5) <= 1 )
  {
    v9 = (unsigned __int8)v2[2].Modifiers.States;
    if ( (unsigned int)v9 < 6 )
    {
      v10 = &v3->KeyboardStates[v9];
      if ( v10 )
      {
        v11 = v2->Modifiers.States;
        if ( v11 )
        {
          v10->Toggled[0] = (v11 >> 4) & 1;
          v10->Toggled[1] = ((unsigned __int8)v2->Modifiers.States >> 3) & 1;
          v10->Toggled[2] = ((unsigned __int8)v2->Modifiers.States >> 5) & 1;
        }
      }
    }
  }
  switch ( v2->Type )
  {
    case 1:
      v12 = (unsigned int)v2[3].Type;
      if ( (unsigned int)v12 >= v3->MouseCursorCount )
        goto LABEL_74;
      v13 = *(float *)&v2[1].Modifiers.States;
      LODWORD(p.x) = v2[1].Type;
      p.y = v13;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v3->ViewportMatrix, &result, &p);
      if ( (unsigned int)v12 < 6 )
      {
        v14 = result.x;
        v15 = result.y;
        v3->InputEventsQueue.LastMousePosMask |= 1 << v12;
        v3->InputEventsQueue.LastMousePos[v12].x = v14;
        v3->InputEventsQueue.LastMousePos[v12].y = v15;
      }
      v4 = 3i64;
      break;
    case 2:
      v22 = v2[3].Type;
      if ( v22 >= v3->MouseCursorCount )
        goto LABEL_74;
      v23 = *(float *)&v2[1].Modifiers.States;
      LODWORD(p.x) = v2[1].Type;
      p.y = v23;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v3->ViewportMatrix, &result, &p);
      v24 = result.x;
      v25 = 1 << *(_DWORD *)&v2[2].Modifiers.States;
      if ( result.x != 1.1754944e-38 )
        v3->InputEventsQueue.LastMousePosMask &= ~(1 << v22);
      v26 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(&v3->InputEventsQueue);
      v26->t = 0;
      v26->u.mouseEntry.MouseIndex = v22;
      v26->u.mouseEntry.ButtonsState = v25;
      v27 = result.y;
      v26->u.mouseEntry.PosX = v24;
      v26->u.mouseEntry.PosY = v27;
      v26->u.mouseEntry.Flags = 0;
      v4 = 3i64;
      break;
    case 3:
      v16 = v2[3].Type;
      if ( v16 >= v3->MouseCursorCount )
        goto LABEL_74;
      v17 = *(float *)&v2[1].Modifiers.States;
      LODWORD(p.x) = v2[1].Type;
      p.y = v17;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v3->ViewportMatrix, &result, &p);
      v18 = result.x;
      v19 = 1 << *(_DWORD *)&v2[2].Modifiers.States;
      if ( result.x != 1.1754944e-38 )
        v3->InputEventsQueue.LastMousePosMask &= ~(1 << v16);
      v20 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(&v3->InputEventsQueue);
      v20->t = 0;
      v20->u.mouseEntry.MouseIndex = v16;
      v20->u.mouseEntry.ButtonsState = v19;
      v21 = result.y;
      v20->u.mouseEntry.PosX = v18;
      v20->u.mouseEntry.PosY = v21;
      v20->u.mouseEntry.Flags = -128;
      v4 = 3i64;
      break;
    case 4:
      v28 = v2[3].Type;
      if ( v28 >= v3->MouseCursorCount )
        goto LABEL_74;
      v29 = *(float *)&v2[1].Modifiers.States;
      LODWORD(p.x) = v2[1].Type;
      p.y = v29;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v3->ViewportMatrix, &result, &p);
      v30 = result.x;
      v31 = (signed int)*(float *)&v2[2].Type;
      if ( result.x != 1.1754944e-38 )
        v3->InputEventsQueue.LastMousePosMask &= ~(1 << v28);
      v32 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(&v3->InputEventsQueue);
      v32->t = 0;
      v32->u.mouseEntry.MouseIndex = v28;
      v32->u.mouseEntry.WheelScrollDelta = v31;
      v33 = result.y;
      v32->u.mouseEntry.PosX = v30;
      v32->u.mouseEntry.PosY = v33;
      v32->u.mouseEntry.ButtonsState = 0;
      v32->u.mouseEntry.Flags = 32;
      v4 = 3i64;
      break;
    case 5:
      v34 = (unsigned __int8)v2[2].Modifiers.States;
      if ( (unsigned int)v34 < 6 )
      {
        v35 = (signed __int64)&v3->KeyboardStates[v34];
        if ( v35 )
        {
          v36 = v2[1].Type;
          v37 = v2[1].Modifiers.States;
          if ( (unsigned int)v36 <= 0xE4 )
          {
            specialKeysState.States = v2->Modifiers.States;
            *(_BYTE *)((v36 >> 3) + v35 + 1637) |= 1 << (v36 - 8 * (v36 >> 3));
            Scaleform::GFx::KeyboardState::KeyQueue::Put(
              (Scaleform::GFx::KeyboardState::KeyQueue *)(v35 + 24),
              v36,
              v37,
              0,
              F3_720_512,
              specialKeysState);
          }
          switch ( v2[1].Type )
          {
            case 0x10:
              if ( v2->Modifiers.States & 0x40 )
                *(_BYTE *)(v35 + 1657) |= 2u;
              else
                *(_BYTE *)(v35 + 1657) |= 1u;
              break;
            case 0x11:
              if ( v2->Modifiers.States & 0x40 )
                *(_BYTE *)(v35 + 1657) |= 8u;
              else
                *(_BYTE *)(v35 + 1657) |= 4u;
              break;
            case 0x12:
              if ( v2->Modifiers.States & 0x40 )
                *(_BYTE *)(v35 + 1657) |= 0x20u;
              else
                *(_BYTE *)(v35 + 1657) |= 0x10u;
              break;
          }
        }
      }
      Scaleform::GFx::InputEventsQueue::AddKeyDown(
        &v3->InputEventsQueue,
        v2[1].Type,
        v2[1].Modifiers.States,
        v2->Modifiers,
        v2[2].Modifiers.States);
      v39 = v2[2].Type;
      if ( v39 == 13 || v39 >= 0x20 && v39 != 127 )
        Scaleform::GFx::InputEventsQueue::AddCharTyped(&v3->InputEventsQueue, v39, v2[2].Modifiers.States);
      v4 = 3i64;
      break;
    case 6:
      v40 = (unsigned __int8)v2[2].Modifiers.States;
      if ( (unsigned int)v40 < 6 )
      {
        v41 = (signed __int64)&v3->KeyboardStates[v40];
        if ( v41 )
        {
          v42 = v2[1].Type;
          v43 = v2[1].Modifiers.States;
          if ( (unsigned int)v42 <= 0xE4 )
          {
            v44.States = v2->Modifiers.States;
            *(_BYTE *)((v42 >> 3) + v41 + 1637) &= ~(1 << (v42 - 8 * (v42 >> 3)));
            Scaleform::GFx::KeyboardState::KeyQueue::Put(
              (Scaleform::GFx::KeyboardState::KeyQueue *)(v41 + 24),
              v42,
              v43,
              0,
              F5_360_512,
              v44);
          }
          switch ( v2[1].Type )
          {
            case 0x10:
              if ( v2->Modifiers.States & 0x40 )
                *(_BYTE *)(v41 + 1657) &= 0xFDu;
              else
                *(_BYTE *)(v41 + 1657) &= 0xFEu;
              break;
            case 0x11:
              if ( v2->Modifiers.States & 0x40 )
                *(_BYTE *)(v41 + 1657) &= 0xF7u;
              else
                *(_BYTE *)(v41 + 1657) &= 0xFBu;
              break;
            case 0x12:
              if ( v2->Modifiers.States & 0x40 )
                *(_BYTE *)(v41 + 1657) &= 0xDFu;
              else
                *(_BYTE *)(v41 + 1657) &= 0xEFu;
              break;
          }
        }
      }
      Scaleform::GFx::InputEventsQueue::AddKeyUp(
        &v3->InputEventsQueue,
        v2[1].Type,
        v2[1].Modifiers.States,
        v2->Modifiers,
        v2[2].Modifiers.States);
      v4 = 3i64;
      break;
    case 9:
      Scaleform::GFx::MovieImpl::ResetKeyboardState(v3);
      Scaleform::GFx::MovieImpl::ResetMouseState(v3);
      v3->Flags &= 0xFFFBFFFF;
      v3->pASMovieRoot.pObject->vfptr[26].__vecDelDtor((Scaleform::RefCountImplCore *)v3->pASMovieRoot.pObject, 0);
      goto LABEL_74;
    case 0x1A:
      Scaleform::GFx::InputEventsQueue::AddAccelerometerEvent(
        &v3->InputEventsQueue,
        v2[1].Type,
        *(long double *)&v2[2],
        *(long double *)&v2[3],
        *(long double *)&v2[4],
        *(long double *)&v2[5]);
      v4 = 3i64;
      break;
    case 0x1B:
      Scaleform::GFx::InputEventsQueue::AddGeolocationEvent(
        &v3->InputEventsQueue,
        v2[1].Type,
        *(long double *)&v2[2],
        *(long double *)&v2[3],
        *(long double *)&v2[4],
        *(long double *)&v2[5],
        *(long double *)&v2[6],
        *(long double *)&v2[7],
        *(long double *)&v2[8],
        *(long double *)&v2[9]);
      v4 = 3i64;
      break;
    case 0x1C:
      Scaleform::GFx::InputEventsQueue::AddStatusEvent(
        &v3->InputEventsQueue,
        *(Scaleform::String **)&v2[1],
        *(Scaleform::String **)&v2[2],
        *(Scaleform::String **)&v2[3],
        *(Scaleform::String **)&v2[4]);
      v4 = 3i64;
      break;
    case 0x1D:
      Scaleform::GFx::InputEventsQueue::AddCharTyped(&v3->InputEventsQueue, v2[1].Type, v2[1].Modifiers.States);
      v4 = 3i64;
      break;
    default:
LABEL_74:
      v4 = 0i64;
      break;
  }
  return v4;
}

// File Line: 3171
// RVA: 0x8EBE50
void __fastcall Scaleform::GFx::MovieImpl::NotifyMouseState(Scaleform::GFx::MovieImpl *this, float x, float y, unsigned int buttons, unsigned int mouseIndex)
{
  Scaleform::GFx::MovieImpl *v5; // rbx
  unsigned int v6; // er15
  __int64 v7; // rsi
  Scaleform::GFx::InputEventsQueue *v8; // rdi
  float v9; // xmm6_4
  int v10; // xmm8_4
  unsigned int v11; // ebp
  signed int v12; // ebx
  signed __int64 v13; // r14
  Scaleform::GFx::InputEventsQueueEntry *v14; // rax
  unsigned __int16 v15; // cx
  float v16; // [rsp+20h] [rbp-68h]
  int v17; // [rsp+24h] [rbp-64h]
  float v18; // [rsp+90h] [rbp+8h]
  float v19; // [rsp+94h] [rbp+Ch]

  v5 = this;
  v18 = x;
  v19 = y;
  v6 = buttons;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(
    &this->ViewportMatrix,
    (Scaleform::Render::Point<float> *)&v16,
    (Scaleform::Render::Point<float> *)&v18);
  v7 = mouseIndex;
  if ( mouseIndex < v5->MouseCursorCount )
  {
    v8 = &v5->InputEventsQueue;
    v9 = v16;
    v10 = v17;
    if ( (unsigned int)v7 < 6 )
    {
      v5->InputEventsQueue.LastMousePosMask |= 1 << mouseIndex;
      v8->LastMousePos[v7].x = v9;
      LODWORD(v8->LastMousePos[v7].y) = v10;
    }
    v11 = v5->mMouseState[v7].CurButtonsState;
    v12 = 1;
    v13 = 16i64;
    do
    {
      if ( v6 & v12 )
      {
        if ( !(v12 & v11) )
        {
          if ( v9 != 1.1754944e-38 )
            v8->LastMousePosMask &= ~(1 << v7);
          v14 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(v8);
          v14->t = 0;
          v14->u.mouseEntry.Flags = 0;
          v15 = v12 & v6;
LABEL_15:
          v14->u.mouseEntry.ButtonsState = v15;
          v14->u.keyEntry.Code = v10;
          v14->u.mouseEntry.PosX = v9;
          v14->u.mouseEntry.MouseIndex = v7;
          goto LABEL_16;
        }
      }
      else if ( !(v12 & v11) )
      {
        goto LABEL_16;
      }
      if ( !(v6 & v12) )
      {
        if ( v9 != 1.1754944e-38 )
          v8->LastMousePosMask &= ~(1 << v7);
        v14 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(v8);
        v14->t = 0;
        v14->u.mouseEntry.Flags = -128;
        v15 = v11 & v12;
        goto LABEL_15;
      }
LABEL_16:
      v12 *= 2;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 3196
// RVA: 0x8DB1F0
void __fastcall Scaleform::GFx::MovieImpl::GetMouseState(Scaleform::GFx::MovieImpl *this, unsigned int mouseIndex, float *x, float *y, unsigned int *buttons)
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
char __fastcall Scaleform::GFx::MovieImpl::HitTest(Scaleform::GFx::MovieImpl *this, float x, float y, Scaleform::GFx::Movie::HitTestType testCond, unsigned int controllerIdx)
{
  Scaleform::GFx::MovieImpl *v5; // r14
  Scaleform::GFx::Movie::HitTestType v6; // esi
  float v7; // xmm2_4
  int v8; // edi
  unsigned int v9; // er15
  Scaleform::GFx::MovieImpl::LevelInfo *v10; // rax
  Scaleform::GFx::DisplayObjectBase *v11; // rbx
  __int64 v12; // r8
  Scaleform::GFx::ASMovieRootBase *v13; // rax
  bool v14; // zf
  Scaleform::RefCountNTSImplCoreVtbl *v15; // rax
  __int64 v17; // rbx
  unsigned __int8 v18; // al
  __int64 v19; // rax
  Scaleform::Render::Point<float> result; // [rsp+30h] [rbp-50h]
  float v21; // [rsp+40h] [rbp-40h]
  float v22; // [rsp+44h] [rbp-3Ch]
  float v23; // [rsp+48h] [rbp-38h]
  float v24; // [rsp+4Ch] [rbp-34h]
  __int128 v25; // [rsp+50h] [rbp-30h]
  __m128 v26; // [rsp+60h] [rbp-20h]
  unsigned int v27; // [rsp+70h] [rbp-10h]
  char v28; // [rsp+74h] [rbp-Ch]
  Scaleform::Render::Point<float> p; // [rsp+B0h] [rbp+30h]

  v5 = this;
  p.x = x;
  p.y = y;
  v6 = testCond;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
  v7 = (float)(result.x - (float)(v5->ViewOffsetX * 20.0)) / (float)(v5->VisibleFrameRect.x2 - v5->VisibleFrameRect.x1);
  LODWORD(v5->ScreenToWorld.Sy) = COERCE_UNSIGNED_INT(
                                    (float)((float)((float)(result.y - (float)(v5->ViewOffsetY * 20.0))
                                                  / (float)(v5->VisibleFrameRect.y2 - v5->VisibleFrameRect.y1))
                                          * 2.0)
                                  - 1.0) ^ _xmm[0];
  v5->ScreenToWorld.Sx = (float)(v7 * 2.0) - 1.0;
  v8 = v5->MovieLevels.Data.Size;
  if ( !v8 )
    return 0;
  v9 = controllerIdx;
  while ( 1 )
  {
    v10 = v5->MovieLevels.Data.Data;
    --v8;
    v25 = _xmm;
    v26 = _xmm;
    v11 = (Scaleform::GFx::DisplayObjectBase *)&v10[v8].pSprite.pObject->vfptr;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, float *, __int128 *))v11->vfptr[61].__vecDelDtor)(
      v11,
      &v21,
      &v25);
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(v11, &p, &result, 0, 0i64);
    if ( (p.x > v23 || p.x < v21 || p.y > v24 || p.y < v22)
      && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v11->vfptr[14].__vecDelDtor)(v11) )
    {
      goto LABEL_25;
    }
    if ( v6 )
      break;
    v12 = 0i64;
LABEL_24:
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, __int64))v11->vfptr[63].__vecDelDtor)(
           v11,
           &p,
           v12) )
    {
      return 1;
    }
LABEL_25:
    if ( !v8 )
      return 0;
  }
  if ( v6 == 1 )
  {
    LOBYTE(v12) = 1;
    goto LABEL_24;
  }
  if ( v6 != 2 )
  {
    if ( v6 != 3 )
      goto LABEL_25;
    LOBYTE(v12) = 3;
    goto LABEL_24;
  }
  v13 = v5->pASMovieRoot.pObject;
  v26 = 0ui64;
  v28 = 0;
  v27 = v9;
  v14 = v13->AVMVersion == 1;
  v15 = v11->vfptr;
  if ( v14 )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, __int128 *))v15[64].__vecDelDtor)(
           v11,
           &p,
           &v25) == 1 )
      return 1;
    goto LABEL_25;
  }
  v28 = 1;
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, __int128 *))v15[64].__vecDelDtor)(
         v11,
         &p,
         &v25) != 1 )
    goto LABEL_25;
  v17 = v25;
  if ( !(_QWORD)v25 )
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
} + 96i64))(v19) )
        return 1;
    }
    v17 = *(_QWORD *)(v17 + 56);
    if ( !v17 )
      goto LABEL_2

// File Line: 3287
// RVA: 0x8B1990
__int64 __fastcall Scaleform::GFx::MovieImpl::AddIntervalTimer(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::ASIntervalTimerIntf *timer)
{
  Scaleform::GFx::Resource *v2; // rdi
  Scaleform::GFx::MovieImpl *v3; // rsi
  _QWORD *v4; // rbx

  v2 = (Scaleform::GFx::Resource *)timer;
  v3 = this;
  timer->vfptr[7].__vecDelDtor((Scaleform::RefCountImplCore *)timer, ++this->LastIntervalTimerId);
  Scaleform::Render::RenderBuffer::AddRef(v2);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy> *)&v3->IntervalTimers.Data.Data,
    &v3->IntervalTimers,
    v3->IntervalTimers.Data.Size + 1);
  v4 = &v3->IntervalTimers.Data.Data[v3->IntervalTimers.Data.Size - 1].pObject;
  if ( v4 )
  {
    Scaleform::Render::RenderBuffer::AddRef(v2);
    *v4 = v2;
  }
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v2);
  return (unsigned int)v3->LastIntervalTimerId;
}

// File Line: 3294
// RVA: 0x8BC490
void __fastcall Scaleform::GFx::MovieImpl::ClearIntervalTimer(Scaleform::GFx::MovieImpl *this, int timerId)
{
  unsigned __int64 v2; // rsi
  __int64 v3; // rbx
  int v4; // ebp
  Scaleform::GFx::MovieImpl *v5; // rdi
  Scaleform::GFx::ASIntervalTimerIntf *v6; // rcx

  v2 = this->IntervalTimers.Data.Size;
  v3 = 0i64;
  v4 = timerId;
  v5 = this;
  if ( v2 )
  {
    while ( 1 )
    {
      v6 = v5->IntervalTimers.Data.Data[v3].pObject;
      if ( v6 )
      {
        if ( ((unsigned int (*)(void))v6->vfptr[8].__vecDelDtor)() == v4 )
          break;
      }
      if ( ++v3 >= v2 )
        return;
    }
    ((void (*)(void))v5->IntervalTimers.Data.Data[v3].pObject->vfptr[4].__vecDelDtor)();
  }
}

// File Line: 3308
// RVA: 0x910870
void __fastcall Scaleform::GFx::MovieImpl::ShutdownTimers(Scaleform::GFx::MovieImpl *this)
{
  unsigned __int64 v1; // rsi
  unsigned __int64 v2; // rbx
  Scaleform::GFx::MovieImpl *v3; // rdi

  v1 = this->IntervalTimers.Data.Size;
  v2 = 0i64;
  v3 = this;
  if ( v1 )
  {
    do
      ((void (*)(void))v3->IntervalTimers.Data.Data[v2++].pObject->vfptr[4].__vecDelDtor)();
    while ( v2 < v1 );
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy> *)&v3->IntervalTimers.Data.Data,
    &v3->IntervalTimers,
    0i64);
}

// File Line: 3317
// RVA: 0x9108D0
void __fastcall Scaleform::GFx::MovieImpl::ShutdownTimersForMovieDef(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::MovieDefImpl *defimpl)
{
  unsigned __int64 v2; // rbp
  Scaleform::GFx::MovieDefImpl *v3; // r14
  Scaleform::GFx::MovieImpl *v4; // rsi
  unsigned __int64 v5; // rbx
  Scaleform::GFx::ASIntervalTimerIntf *v6; // rcx
  Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf> *v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf> *v9; // rdi

  v2 = this->IntervalTimers.Data.Size;
  v3 = defimpl;
  v4 = this;
  v5 = 0i64;
  if ( v2 )
  {
    do
    {
      v6 = v4->IntervalTimers.Data.Data[v5].pObject;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::ASIntervalTimerIntf *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::MovieDefImpl *))v6->vfptr[5].__vecDelDtor)(
             v6,
             v4,
             v3) )
      {
        v7 = v4->IntervalTimers.Data.Data;
        v8 = (Scaleform::Render::RenderBuffer *)v7[v5].pObject;
        v9 = &v7[v5];
        if ( v8 )
          Scaleform::RefCountImpl::Release(v8);
        v9->pObject = 0i64;
      }
      ++v5;
    }
    while ( v5 < v2 );
  }
}

// File Line: 3346
// RVA: 0x8D6630
__int64 __fastcall Scaleform::GFx::MovieImpl::GetCurrentFrame(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rcx
  __int64 result; // rax

  v1 = this->pMainMovie;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr[107].__vecDelDtor)();
  else
    result = 0i64;
  return result;
}

// File Line: 3350
// RVA: 0x8E2EE0
bool __fastcall Scaleform::GFx::MovieImpl::HasLooped(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rcx
  __int64 v2; // rax

  v1 = this->pMainMovie;
  if ( v1 )
    v2 = ((unsigned __int8 (*)(void))v1->vfptr[113].__vecDelDtor)();
  else
    LOBYTE(v2) = 0;
  return v2;
}

// File Line: 3356
// RVA: 0x8FE740
char __fastcall Scaleform::GFx::MovieImpl::ReleaseLevelMovie(Scaleform::GFx::MovieImpl *this, int level)
{
  Scaleform::GFx::MovieImpl *v2; // rdi
  unsigned __int64 v3; // rsi
  Scaleform::GFx::DisplayObjectBase *v4; // rbp
  unsigned __int64 v5; // rcx
  __int64 v6; // rbx
  signed __int64 v7; // r15
  Scaleform::RefCountNTSImpl *v8; // rcx
  Scaleform::Render::TreeNode *v9; // rax
  Scaleform::Render::TreeContainer *v10; // rbx
  signed __int64 v11; // rax
  char result; // al
  unsigned __int64 v13; // rcx
  __int64 v14; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v15; // r8
  Scaleform::GFx::InteractiveObject *v16; // rcx
  Scaleform::GFx::DisplayObjectBase *v17; // rbx
  Scaleform::Render::TreeNode *v18; // rax
  Scaleform::Render::TreeContainer *v19; // rcx

  v2 = this;
  LODWORD(v3) = 0;
  if ( level )
  {
    v13 = this->MovieLevels.Data.Size;
    if ( v13 )
    {
      v14 = 0i64;
      v15 = v2->MovieLevels.Data.Data;
      while ( v15[v14].Level != level )
      {
        LODWORD(v3) = v3 + 1;
        v14 = (unsigned int)v3;
        if ( (unsigned int)v3 >= v13 )
          goto LABEL_30;
      }
      v3 = (unsigned int)v3;
      v16 = v15[(unsigned int)v3].pSprite.pObject;
      if ( v16 )
        ++v16->RefCount;
      v17 = (Scaleform::GFx::DisplayObjectBase *)&v15[(unsigned int)v3].pSprite.pObject->vfptr;
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v17->vfptr[75].__vecDelDtor)(v17);
      ((void (__cdecl *)(Scaleform::GFx::ASMovieRootBase *))v2->pASMovieRoot.pObject->vfptr[7].__vecDelDtor)(v2->pASMovieRoot.pObject);
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v17->vfptr[60].__vecDelDtor)(v17);
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy> > *)&v2->MovieLevels.Data,
        v3);
      v2->Flags |= 0x100u;
      v18 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v17);
      if ( v18 )
      {
        v19 = (Scaleform::Render::TreeContainer *)v18->pParent;
        if ( v19 )
          Scaleform::Render::TreeContainer::Remove(v19, v3, 1ui64);
      }
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v17->vfptr);
      result = 1;
    }
    else
    {
LABEL_30:
      result = 0;
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
    if ( v2->MovieLevels.Data.Size )
    {
      v4 = (Scaleform::GFx::DisplayObjectBase *)&v2->MovieLevels.Data.Data->pSprite.pObject->vfptr;
      if ( v4 )
        ++v4->RefCount;
    }
    else
    {
      v4 = 0i64;
    }
    while ( v2->MovieLevels.Data.Size )
    {
      v5 = v2->MovieLevels.Data.Size;
      v6 = *((_QWORD *)&v2->MovieLevels.Data.Data[v5] - 1);
      (*(void (__fastcall **)(_QWORD))(*(_QWORD *)v6 + 600i64))(*((_QWORD *)&v2->MovieLevels.Data.Data[v5] - 1));
      ((void (__cdecl *)(Scaleform::GFx::ASMovieRootBase *))v2->pASMovieRoot.pObject->vfptr[7].__vecDelDtor)(v2->pASMovieRoot.pObject);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 480i64))(v6);
      v7 = v2->MovieLevels.Data.Size - 1;
      if ( v2->MovieLevels.Data.Size == 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy> *)&v2->MovieLevels.Data.Data,
          &v2->MovieLevels,
          0i64);
      }
      else
      {
        v8 = (Scaleform::RefCountNTSImpl *)&v2->MovieLevels.Data.Data[v7].pSprite.pObject->vfptr;
        if ( v8 )
          Scaleform::RefCountNTSImpl::Release(v8);
        memmove(
          &v2->MovieLevels.Data.Data[v7],
          &v2->MovieLevels.Data.Data[v7 + 1],
          16 * (v2->MovieLevels.Data.Size - v7 - 1));
        --v2->MovieLevels.Data.Size;
      }
    }
    v9 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4);
    if ( v9 )
    {
      v10 = (Scaleform::Render::TreeContainer *)v9->pParent;
      if ( v10 )
      {
        v11 = Scaleform::Render::TreeContainer::GetSize((Scaleform::Render::TreeContainer *)v9->pParent);
        Scaleform::Render::TreeContainer::Remove(v10, 0i64, v11);
      }
    }
    if ( v4 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
    v2->pMainMovie = 0i64;
    v2->FrameTime = 0.083333336;
    v2->Flags |= 0x100u;
    result = 1;
  }
  return result;
}

// File Line: 3438
// RVA: 0x9042E0
void __fastcall Scaleform::GFx::MovieImpl::Restart(Scaleform::GFx::MovieImpl *this, bool advance0)
{
  bool v2; // r15
  Scaleform::GFx::MovieImpl *v3; // rdi
  __int64 v4; // rax
  __int64 v5; // r14
  int i; // ebx
  Scaleform::GFx::LoadQueueEntryMT *v7; // rcx
  unsigned int v8; // ebp
  unsigned int v9; // esi
  Scaleform::GFx::LoadQueueEntryMT *j; // rbx
  Scaleform::GFx::LoadQueueEntry *v11; // rcx
  Scaleform::GFx::LoadQueueEntryMT *v12; // rcx
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v13; // rbx
  unsigned int k; // ebx
  Scaleform::GFx::UserEventHandler *v15; // rcx
  Scaleform::GFx::UserEventHandler *v16; // rcx
  __int64 v17; // rdx
  __int64 v18; // r9
  __int64 v19; // rcx
  int v20; // [rsp+28h] [rbp-50h]
  char v21; // [rsp+2Ch] [rbp-4Ch]
  int v22; // [rsp+30h] [rbp-48h]
  unsigned int v23; // [rsp+34h] [rbp-44h]
  int v24; // [rsp+38h] [rbp-40h]
  char v25; // [rsp+3Ch] [rbp-3Ch]
  int v26; // [rsp+40h] [rbp-38h]
  unsigned int v27; // [rsp+44h] [rbp-34h]

  v2 = advance0;
  v3 = this;
  if ( this->pMainMovie )
  {
    this->Flags2 |= 4u;
    Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
    v4 = ((__int64 (__cdecl *)(Scaleform::GFx::InteractiveObject *))v3->pMainMovie->vfptr[66].__vecDelDtor)(v3->pMainMovie);
    v5 = v4;
    if ( v4 )
      _InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 8), 1u);
    for ( i = v3->MovieLevels.Data.Size - 1; i >= 0; --i )
      Scaleform::GFx::MovieImpl::ReleaseLevelMovie(v3, i);
    Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy> *)&v3->MovieLevels.Data.Data,
      &v3->MovieLevels,
      0i64);
    v7 = v3->pLoadQueueMTHead;
    v8 = 0;
    if ( v7 )
    {
      do
      {
        ++v8;
        v7->pQueueEntry->Canceled = 1;
        v7 = v7->pNext;
      }
      while ( v7 );
      if ( v8 )
      {
        do
        {
          v9 = 0;
          for ( j = v3->pLoadQueueMTHead; j; j = j->pNext )
          {
            if ( j->vfptr->LoadFinished(j) )
              ++v9;
          }
        }
        while ( v8 > v9 );
      }
    }
    while ( v3->pLoadQueueHead )
    {
      v11 = v3->pLoadQueueHead;
      v3->pLoadQueueHead = v11->pNext;
      v11->vfptr->__vecDelDtor(v11, 1u);
    }
    while ( v3->pLoadQueueMTHead )
    {
      v12 = v3->pLoadQueueMTHead;
      v3->pLoadQueueMTHead = v12->pNext;
      v12->vfptr->__vecDelDtor(v12, 1u);
    }
    v3->pLoadQueueHead = 0i64;
    v3->pLoadQueueMTHead = 0i64;
    v3->Flags |= 0x80000u;
    v3->pPlayListOptHead = 0i64;
    v3->pPlayListHead = 0i64;
    ((void (__cdecl *)(Scaleform::GFx::ASMovieRootBase *))v3->pASMovieRoot.pObject->vfptr[42].__vecDelDtor)(v3->pASMovieRoot.pObject);
    Scaleform::GFx::MovieImpl::ClearIndirectTransformPairs(v3);
    v13 = v3->pRetValHolder;
    if ( v13 )
    {
      if ( v13->CharBuffer )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(&v13->StringArray.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13);
    }
    v3->pRetValHolder = 0i64;
    Scaleform::GFx::MovieImpl::ResetFocusStates(v3);
    v3->Flags &= 0x3FFFFFu;
    Scaleform::GFx::MovieImpl::ResetMouseState(v3);
    v3->pASMovieRoot.pObject->vfptr[9].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->pASMovieRoot.pObject->vfptr, 2u);
    v3->Flags2 &= 0xFFFFFFFB;
    v3->pASMovieRoot.pObject->vfptr[17].__vecDelDtor((Scaleform::RefCountImplCore *)v3->pASMovieRoot.pObject, v5);
    if ( v3->pMainMovie )
    {
      if ( v3->pUserEventHandler.pObject )
      {
        for ( k = 0; k < v3->MouseCursorCount; ++k )
        {
          v15 = v3->pUserEventHandler.pObject;
          v21 = 0;
          v20 = 21;
          v22 = 0;
          v23 = k;
          ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))v15->vfptr[1].__vecDelDtor)(
            v15,
            v3,
            &v20);
          v16 = v3->pUserEventHandler.pObject;
          v25 = 0;
          v24 = 23;
          v26 = 0;
          v27 = k;
          ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))v16->vfptr[1].__vecDelDtor)(
            v16,
            v3,
            &v24);
        }
      }
      v3->FocusRectChanged = 1;
      Scaleform::GFx::MovieImpl::ResetKeyboardState(v3);
      if ( v2 )
      {
        LOBYTE(v18) = 1;
        ((void (__fastcall *)(Scaleform::GFx::MovieImpl *, __int64, _QWORD, __int64, signed __int64))v3->vfptr[24].__vecDelDtor)(
          v3,
          v17,
          0i64,
          v18,
          -2i64);
      }
      v3->pASMovieRoot.pObject->vfptr[9].__vecDelDtor(
        (Scaleform::RefCountImplCore *)&v3->pASMovieRoot.pObject->vfptr,
        2u);
    }
    if ( v5 && !_InterlockedDecrement((volatile signed __int32 *)(v5 + 8)) )
    {
      v19 = *(_QWORD *)(v5 + 16);
      if ( v19 )
      {
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v19 + 8i64))(v19, v5);
        *(_QWORD *)(v5 + 16) = 0i64;
      }
      (**(void (__fastcall ***)(__int64, signed __int64))v5)(v5, 1i64);
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
  unsigned int *v1; // rbx
  signed __int64 v2; // rdi

  v1 = &this->KeyboardStates[0].KeyQueue.GetIdx;
  v2 = 6i64;
  do
  {
    *(_QWORD *)(v1 - 1) = 0i64;
    v1[1] = 0;
    memset(v1 - 401, 0, 0x640ui64);
    v1 += 418;
    *(_QWORD *)((char *)v1 - 1663) = 0i64;
    *(_QWORD *)((char *)v1 - 1655) = 0i64;
    *(_QWORD *)((char *)v1 - 1647) = 0i64;
    *(unsigned int *)((char *)v1 - 1639) = 0;
    *((_BYTE *)v1 - 1635) = 0;
    *((_WORD *)v1 - 817) = 0;
    *((_BYTE *)v1 - 1632) = 0;
    --v2;
  }
  while ( v2 );
}

// File Line: 3610
// RVA: 0x9085F0
void __fastcall Scaleform::GFx::MovieImpl::SetKeyboardListener(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::KeyboardState::IListener *l)
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
  Scaleform::GFx::InteractiveObject *v2; // rcx

  v2 = this->pMainMovie;
  if ( v2 )
    v2->vfptr[110].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, targetFrameNumber);
}

// File Line: 3624
// RVA: 0x8E24C0
char __fastcall Scaleform::GFx::MovieImpl::GotoLabeledFrame(Scaleform::GFx::MovieImpl *this, const char *label, int offset)
{
  int v3; // esi
  const char *v4; // rdi
  Scaleform::GFx::MovieImpl *v5; // rbx
  Scaleform::GFx::MovieDataDef *v6; // rcx
  int v8; // [rsp+40h] [rbp+8h]
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+58h] [rbp+20h]

  v3 = offset;
  v4 = label;
  v5 = this;
  if ( this->pMainMovie )
  {
    v8 = -1;
    v6 = this->pMainMovieDef.pObject->pBindData.pObject->pDataDef.pObject;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::MovieDataDef *, const char *, int *, _QWORD, signed __int64))v6->vfptr[3].GetKey)(
           v6,
           label,
           &v8,
           0i64,
           -2i64) )
    {
      v5->vfptr[4].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, v8 + v3);
      return 1;
    }
    Scaleform::GFx::StateBag::GetLogState((Scaleform::GFx::StateBag *)&v5->vfptr, &result);
    if ( result.pObject )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&result.pObject->vfptr,
        "MovieImpl::GotoLabeledFrame(%s) unknown label",
        v4);
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  }
  return 0;
}

// File Line: 3644
// RVA: 0x909BF0
void __fastcall Scaleform::GFx::MovieImpl::SetPause(Scaleform::GFx::MovieImpl *this, bool pause)
{
  Scaleform::GFx::MovieImpl *v2; // rbx
  unsigned int v3; // ecx
  bool v4; // di
  char v5; // al
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rax
  Scaleform::GFx::InteractiveObject *v8; // rcx
  Scaleform::GFx::InteractiveObject *v9; // rbx

  v2 = this;
  v3 = this->Flags;
  v4 = pause;
  v5 = (v3 >> 20) & 1;
  if ( (!v5 || !pause) && (v5 || pause) )
  {
    if ( pause )
    {
      v2->Flags = v3 | 0x100000;
      v6 = Scaleform::Timer::GetTicks();
      v2->PauseTickMs = (unsigned __int64)((v6 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)
                                         + ((unsigned __int64)(v6 - (v6 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)) >> 9;
    }
    else
    {
      v2->Flags = v3 & 0xFFEFFFFF;
      v7 = Scaleform::Timer::GetTicks();
      v2->StartTickMs += ((unsigned __int64)((v7 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)
                                           + ((unsigned __int64)(v7
                                                               - (v7 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)) >> 9)
                       - v2->PauseTickMs;
    }
    v8 = v2->pPlayListHead;
    if ( v8 )
    {
      do
      {
        v9 = v8->pPlayNext;
        v8->vfptr[95].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, v4);
        v8 = v9;
      }
      while ( v9 );
    }
  }
}

// File Line: 3673
// RVA: 0x909CE0
void __fastcall Scaleform::GFx::MovieImpl::SetPlayState(Scaleform::GFx::MovieImpl *this, __int64 s)
{
  Scaleform::GFx::InteractiveObject *v2; // rcx

  v2 = this->pMainMovie;
  if ( v2 )
    v2->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, s);
}

// File Line: 3678
// RVA: 0x8DC110
__int64 __fastcall Scaleform::GFx::MovieImpl::GetPlayState(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rcx
  __int64 result; // rax

  v1 = this->pMainMovie;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr[115].__vecDelDtor)();
  else
    result = 1i64;
  return result;
}

// File Line: 3684
// RVA: 0x90F150
void __fastcall Scaleform::GFx::MovieImpl::SetVisible(Scaleform::GFx::MovieImpl *this, __int64 visible)
{
  Scaleform::GFx::InteractiveObject *v2; // rcx

  v2 = this->pMainMovie;
  if ( v2 )
    v2->vfptr[58].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, visible);
}

// File Line: 3688
// RVA: 0x8E1850
bool __fastcall Scaleform::GFx::MovieImpl::GetVisible(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rcx
  __int64 v2; // rax

  v1 = this->pMainMovie;
  if ( v1 )
    v2 = ((unsigned __int8 (*)(void))v1->vfptr[59].__vecDelDtor)();
  else
    LOBYTE(v2) = 0;
  return v2;
}

// File Line: 3693
// RVA: 0x8B2E30
void __fastcall Scaleform::GFx::MovieImpl::AddStickyVariableNode(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::ASString *path, Scaleform::GFx::MovieImpl::StickyVarNode *p)
{
  Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > > *v3; // rdi
  Scaleform::GFx::MovieImpl::StickyVarNode *v4; // rbx
  Scaleform::GFx::ASString *v5; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v6; // rsi
  signed __int64 v7; // rax
  signed __int64 v8; // rdx
  __int64 v9; // rdx
  _QWORD *v10; // rcx
  Scaleform::GFx::MovieImpl::StickyVarNode *value; // [rsp+40h] [rbp+18h]

  value = p;
  v3 = (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::All)&this->StickyVariables.mHash;
  v4 = p;
  v5 = path;
  v6 = this->StickyVariables.mHash.pTable;
  if ( v6
    && (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->StickyVariables.mHash.pTable,
               path,
               v6->SizeMask & path->pNode->HashFlags),
        v7 >= 0)
    && (v8 = (signed __int64)v6 + 8 * (3 * v7 + 3)) != 0
    && (v9 = *(_QWORD *)(v8 + 8)) != 0 )
  {
    v10 = (_QWORD *)v9;
    while ( (Scaleform::GFx::ASStringNode *)v10[1] != v4->Name.pNode )
    {
      v10 = (_QWORD *)v10[2];
      if ( !v10 )
      {
        v4->pNext = *(Scaleform::GFx::MovieImpl::StickyVarNode **)(v9 + 16);
        *(_QWORD *)(v9 + 16) = value;
        return;
      }
    }
    (*(void (__fastcall **)(_QWORD *, Scaleform::GFx::MovieImpl::StickyVarNode *))(*v10 + 8i64))(v10, v4);
    if ( value )
      value->vfptr->__vecDelDtor(value, 1u);
  }
  else
  {
    Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
      v3,
      v5,
      &value);
  }
}

// File Line: 3734
// RVA: 0x8BC9D0
void __fastcall Scaleform::GFx::MovieImpl::ClearStickyVariables(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v1; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v2; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v3; // rax
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // rdi
  __int64 v8; // rdi
  void (__fastcall ***v9)(_QWORD, signed __int64); // rcx
  unsigned __int64 v10; // rdx
  unsigned __int64 *v11; // rcx

  v1 = 0i64;
  v2 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->StickyVariables.mHash.pTable;
  v3 = this->StickyVariables.mHash.pTable;
  v4 = 0i64;
  if ( v3 )
  {
    v5 = v3->SizeMask;
    v6 = v3 + 1;
    do
    {
      if ( v6->EntryCount != -2i64 )
        break;
      ++v4;
      v6 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v6 + 24);
    }
    while ( v4 <= v5 );
    v1 = v2;
  }
  while ( v1 )
  {
    v7 = v1->pTable;
    if ( !v1->pTable || (signed __int64)v4 > (signed __int64)v7->SizeMask )
      break;
    v8 = *(&v7[2].EntryCount + 3 * v4);
    while ( v8 )
    {
      v9 = (void (__fastcall ***)(_QWORD, signed __int64))v8;
      v8 = *(_QWORD *)(v8 + 16);
      (**v9)(v9, 1i64);
    }
    v10 = v1->pTable->SizeMask;
    if ( (signed __int64)v4 <= (signed __int64)v10 && ++v4 <= v10 )
    {
      v11 = &v1->pTable[1].EntryCount + 3 * v4;
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
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(v2);
}

// File Line: 3783
// RVA: 0x9014F0
void __fastcall Scaleform::GFx::MovieImpl::ResetFocusStates(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl *v1; // rbp
  unsigned int v2; // esi
  signed __int64 v3; // rdi
  _QWORD *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASStringNode *v8; // rcx

  v1 = this;
  v2 = 0;
  if ( this->FocusGroupsCnt )
  {
    do
    {
      v3 = (signed __int64)v1 + 96 * v2;
      v4 = *(_QWORD **)(v3 + 19664);
      if ( v4 )
      {
        if ( --*(_DWORD *)v4 <= 0 )
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
      *(_QWORD *)(v3 + 19664) = 0i64;
      if ( *(_BYTE *)(v3 + 19697) & 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy> *)(v3 + 19624),
          *(const void **)(v3 + 19648),
          0i64);
        *(_BYTE *)(v3 + 19697) = 0;
      }
      *(_DWORD *)(v3 + 19672) = 0;
      ++v2;
    }
    while ( v2 < v1->FocusGroupsCnt );
  }
}

// File Line: 3793
// RVA: 0x906A80
char __fastcall Scaleform::GFx::MovieImpl::SetControllerFocusGroup(Scaleform::GFx::MovieImpl *this, unsigned int controllerIdx, unsigned int focusGroupIndex)
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
__int64 __fastcall Scaleform::GFx::MovieImpl::GetControllerFocusGroup(Scaleform::GFx::MovieImpl *this, unsigned int controllerIdx)
{
  __int64 result; // rax

  if ( controllerIdx < 0x10 )
    result = (unsigned __int8)this->FocusGroupIndexes[controllerIdx];
  else
    result = 0i64;
  return result;
}

// File Line: 3811
// RVA: 0x8CB3C0
void __fastcall Scaleform::GFx::MovieImpl::FillTabableArray(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo)
{
  Scaleform::GFx::ProcessFocusKeyInfo *v2; // r15
  Scaleform::GFx::MovieImpl *v3; // rbp
  Scaleform::GFx::FocusGroupDescr *v4; // rsi
  char v5; // al
  Scaleform::GFx::CharacterHandle *v6; // rdx
  __int64 v7; // rbx
  __int64 v8; // rdx
  unsigned __int8 v9; // al
  __int64 v10; // rax
  __int64 v11; // rdi
  signed __int64 v12; // rbx
  __int64 v13; // rcx
  unsigned __int8 v14; // al
  __int64 v15; // rax
  unsigned __int64 v16; // r8
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *v17; // rcx
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *v18; // [rsp+28h] [rbp-30h]
  char v19; // [rsp+30h] [rbp-28h]
  bool v20; // [rsp+31h] [rbp-27h]
  char v21; // [rsp+32h] [rbp-26h]

  v2 = pfocusInfo;
  v3 = this;
  v4 = pfocusInfo->pFocusGroup;
  if ( pfocusInfo->InclFocusEnabled )
  {
    v5 = v4->TabableArrayStatus;
    if ( v5 & 1 )
    {
      if ( !(v5 & 2) )
      {
        Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Resize(
          &v4->TabableArray.Data,
          0i64);
        v4->TabableArrayStatus = 0;
      }
    }
  }
  if ( !(v4->TabableArrayStatus & 1) )
  {
    v19 = 0;
    v21 = 0;
    v18 = &v4->TabableArray;
    v20 = v2->InclFocusEnabled;
    v6 = v4->ModalClip.pObject;
    if ( !v6 )
      goto LABEL_26;
    v7 = (__int64)v6->pCharacter;
    if ( v7
      || (v7 = (__int64)v3->pASMovieRoot.pObject->vfptr[8].__vecDelDtor(
                          (Scaleform::RefCountImplCore *)&v3->pASMovieRoot.pObject->vfptr,
                          (unsigned int)&v6->NamePath)) != 0 )
    {
      ++*(_DWORD *)(v7 + 8);
    }
    if ( v7 )
    {
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v7);
      v9 = *(_BYTE *)(v7 + 109);
      if ( v9 )
      {
        v10 = (*(__int64 (__cdecl **)(__int64, __int64))(*(_QWORD *)(v7 + 4i64 * v9) + 40i64))(v7 + 4i64 * v9, v8);
        (*(void (__fastcall **)(__int64, Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> **))(*(_QWORD *)v10 + 184i64))(
          v10,
          &v18);
      }
    }
    else
    {
LABEL_26:
      v11 = SLODWORD(v3->MovieLevels.Data.Size);
      if ( v11 > 0 )
      {
        v12 = 16 * v11 - 16;
        do
        {
          v13 = *(__int64 *)((char *)&v3->MovieLevels.Data.Data->pSprite.pObject + v12);
          if ( (*(_WORD *)(v13 + 106) >> 9) & 1 )
          {
            v14 = *(_BYTE *)(v13 + 109);
            if ( v14 )
            {
              v15 = (*(__int64 (__cdecl **)(__int64, Scaleform::GFx::CharacterHandle *))(*(_QWORD *)(v13 + 4i64 * v14)
                                                                                       + 40i64))(
                      v13 + 4i64 * v14,
                      v6);
              (*(void (__fastcall **)(__int64, Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> **))(*(_QWORD *)v15 + 184i64))(
                v15,
                &v18);
            }
          }
          --v11;
          v12 -= 16i64;
        }
        while ( v11 > 0 );
      }
    }
    v16 = v4->TabableArray.Data.Size;
    v17 = &v4->TabableArray;
    if ( v19 )
      Scaleform::Alg::QuickSortSliced<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TabIndexSortFunctor>(
        v17,
        0i64,
        v16,
        byte_142440EF4);
    else
      Scaleform::Alg::QuickSortSliced<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AutoTabSortFunctor>(
        v17,
        0i64,
        v16,
        byte_142440EF5);
    v4->TabableArrayStatus = 1;
    if ( v2->InclFocusEnabled )
      v4->TabableArrayStatus = 3;
  }
}

// File Line: 3864
// RVA: 0x8E4120
void __fastcall Scaleform::GFx::MovieImpl::InitFocusKeyInfo(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo, Scaleform::GFx::InputEventsQueueEntry::KeyEntry *keyEntry, bool inclFocusEnabled, Scaleform::GFx::FocusGroupDescr *pfocusGroup)
{
  Scaleform::GFx::ProcessFocusKeyInfo *v5; // rbx
  Scaleform::GFx::FocusGroupDescr *v6; // rdi
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  Scaleform::GFx::Sprite *v10; // rax
  Scaleform::RefCountNTSImpl *v11; // rcx
  Scaleform::GFx::InteractiveObject *v12; // rdx
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // r8
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v15; // rcx
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+48h] [rbp+10h]

  v5 = pfocusInfo;
  if ( !pfocusInfo->Initialized )
  {
    v6 = pfocusGroup;
    if ( !pfocusGroup )
      v6 = &this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[(unsigned __int8)keyEntry->KeyboardIndex]];
    pfocusInfo->pFocusGroup = v6;
    pfocusInfo->PrevKeyCode = v6->LastFocusKeyCode;
    v7 = v6->LastFocusedRect.y2;
    v8 = v6->LastFocusedRect.x2;
    v9 = v6->LastFocusedRect.y1;
    pfocusInfo->Prev_aRect.x1 = v6->LastFocusedRect.x1;
    pfocusInfo->Prev_aRect.y1 = v9;
    pfocusInfo->Prev_aRect.x2 = v8;
    pfocusInfo->Prev_aRect.y2 = v7;
    pfocusInfo->InclFocusEnabled = inclFocusEnabled;
    pfocusInfo->ManualFocus = 0;
    pfocusInfo->KeyboardIndex = keyEntry->KeyboardIndex;
    pfocusInfo->KeyCode = keyEntry->Code;
    pfocusInfo->KeysState = keyEntry->KeysState;
    Scaleform::GFx::MovieImpl::FillTabableArray(this, pfocusInfo);
    v5->CurFocusIdx = -1;
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v6->LastFocused,
      &result);
    v10 = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      v10 = result.pObject;
    }
    v11 = (Scaleform::RefCountNTSImpl *)&v5->CurFocused.pObject->vfptr;
    if ( v11 )
    {
      Scaleform::RefCountNTSImpl::Release(v11);
      v10 = result.pObject;
    }
    v5->CurFocused.pObject = (Scaleform::GFx::InteractiveObject *)&v10->vfptr;
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
    v12 = v5->CurFocused.pObject;
    if ( v12 )
    {
      v13 = 0i64;
      v14 = v6->TabableArray.Data.Size;
      if ( v14 )
      {
        v15 = v6->TabableArray.Data.Data;
        while ( v15->pObject != v12 )
        {
          ++v13;
          ++v15;
          if ( v13 >= v14 )
            goto LABEL_17;
        }
        v5->CurFocusIdx = v13;
      }
    }
LABEL_17:
    v5->Initialized = 1;
  }
}

// File Line: 3906
// RVA: 0x8F1140
void __fastcall Scaleform::GFx::MovieImpl::ProcessFocusKey(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::Event::EventType event, Scaleform::GFx::InputEventsQueueEntry::KeyEntry *keyEntry, Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo)
{
  Scaleform::GFx::ProcessFocusKeyInfo *v4; // r14
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry *v5; // rbx
  Scaleform::GFx::MovieImpl *v6; // r12
  unsigned int v7; // er9
  Scaleform::GFx::FocusGroupDescr *v8; // r15
  __int64 v9; // r13
  signed __int64 v10; // rdx
  signed __int64 v11; // rdi
  int v12; // esi
  signed __int64 v13; // rbx
  Scaleform::GFx::InteractiveObject *v14; // rcx
  Scaleform::GFx::InteractiveObject *v15; // rcx
  Scaleform::GFx::InteractiveObject *v16; // rcx
  int v17; // eax
  Scaleform::Render::Rect<float> *v18; // rax
  unsigned int v19; // ecx
  unsigned int v20; // ecx
  signed __int64 v21; // rdi
  float v22; // xmm14_4
  float v23; // xmm10_4
  char v24; // r15
  unsigned int v25; // er13
  signed __int64 v26; // rsi
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
  float v37; // xmm2_4
  float v38; // xmm1_4
  __m128 v39; // xmm3
  __m128 v40; // xmm5
  float v41; // xmm0_4
  float v42; // xmm0_4
  __m128 v43; // xmm2
  __m128 v44; // xmm4
  signed int v45; // ecx
  signed int v46; // ecx
  signed int v47; // ecx
  signed int v48; // ecx
  float v49; // xmm0_4
  float v50; // xmm0_4
  signed int v51; // ecx
  signed int v52; // ecx
  signed int v53; // ecx
  signed int v54; // ecx
  signed __int64 v55; // rdi
  __m128 v56; // xmm14
  float v57; // xmm15_4
  char v58; // r15
  unsigned int v59; // er13
  signed __int64 v60; // rsi
  __int64 v61; // r12
  float v62; // xmm8_4
  __int64 v63; // rbx
  __int64 v64; // rax
  __int64 v65; // rbx
  Scaleform::GFx::DisplayObjectBase *v66; // rcx
  float *v67; // rax
  float v68; // xmm3_4
  float v69; // xmm4_4
  unsigned __int64 v70; // kr00_8
  Scaleform::Render::Rect<float> *v71; // rax
  unsigned int v72; // eax
  float v73; // xmm3_4
  float v74; // xmm2_4
  float v75; // xmm3_4
  float v76; // xmm2_4
  float v77; // xmm1_4
  __m128 v78; // xmm4
  __m128 v79; // xmm5
  float v80; // xmm0_4
  float v81; // xmm0_4
  __m128 v82; // xmm3
  __m128 v83; // xmm2
  signed int v84; // ecx
  signed int v85; // ecx
  signed int v86; // ecx
  signed int v87; // ecx
  float v88; // xmm0_4
  float v89; // xmm0_4
  signed int v90; // ecx
  signed int v91; // ecx
  signed int v92; // ecx
  signed int v93; // ecx
  __int64 v94; // rax
  __int64 v95; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v96; // rdi
  Scaleform::GFx::InteractiveObject *v97; // rax
  Scaleform::RefCountNTSImpl *v98; // rcx
  Scaleform::RefCountNTSImpl *v99; // rcx
  float v100; // [rsp+30h] [rbp-98h]
  float v101; // [rsp+30h] [rbp-98h]
  float v102; // [rsp+40h] [rbp-88h]
  Scaleform::Render::Rect<float> pr; // [rsp+48h] [rbp-80h]
  __m128 v104; // [rsp+58h] [rbp-70h]
  __int64 v105; // [rsp+68h] [rbp-60h]
  Scaleform::Render::Rect<float> v106; // [rsp+70h] [rbp-58h]
  __int64 v107; // [rsp+80h] [rbp-48h]
  char v108; // [rsp+88h] [rbp-40h]
  Scaleform::Render::Matrix2x4<float> result; // [rsp+98h] [rbp-30h]
  __int64 v110; // [rsp+198h] [rbp+D0h]
  float v111; // [rsp+1A0h] [rbp+D8h]
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry *v112; // [rsp+1A8h] [rbp+E0h]

  if ( event != 5 )
    return;
  v107 = -2i64;
  v4 = pfocusInfo;
  v5 = keyEntry;
  v6 = this;
  v7 = keyEntry->Code;
  if ( v7 != 9
    && (!this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[(unsigned __int8)keyEntry->KeyboardIndex]].FocusRectShown
     && !v4->ManualFocus
     || v7 - 37 > 3) )
  {
    return;
  }
  Scaleform::GFx::MovieImpl::InitFocusKeyInfo(this, v4, keyEntry, 0, 0i64);
  v8 = v4->pFocusGroup;
  v104.m128_u64[1] = (unsigned __int64)v8;
  v9 = v8->TabableArray.Data.Size;
  v105 = v9;
  v10 = (signed int)v9;
  *(_QWORD *)&v106.x1 = (signed int)v9;
  if ( v5->Code == 9 )
  {
    v11 = v4->CurFocusIdx;
    v4->CurFocusIdx = -1;
    v12 = 0;
    v13 = v11;
    if ( (signed int)v9 <= 0 )
      goto LABEL_222;
    while ( 1 )
    {
      if ( v112->KeysState & 1 )
      {
        LODWORD(v11) = v11 - 1;
        if ( --v13 < 0 )
        {
          LODWORD(v11) = v9 - 1;
          v13 = v10 - 1;
        }
      }
      else
      {
        LODWORD(v11) = v11 + 1;
        if ( ++v13 >= v10 )
        {
          LODWORD(v11) = 0;
          v13 = 0i64;
        }
      }
      v14 = v8->TabableArray.Data.Data[v13].pObject;
      if ( v14 )
      {
        if ( v4->InclFocusEnabled || ((unsigned __int8 (*)(void))v14->vfptr[87].__vecDelDtor)() )
        {
          v15 = v8->TabableArray.Data.Data[v13].pObject;
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::MovieImpl *, _QWORD))v15->vfptr[85].__vecDelDtor)(
                 v15,
                 v6,
                 (unsigned __int8)v4->KeyboardIndex) )
          {
            v4->CurFocusIdx = v11;
            goto LABEL_222;
          }
        }
        v10 = *(_QWORD *)&v106.x1;
      }
      if ( ++v12 >= (signed int)v9 )
        goto LABEL_222;
    }
  }
  v16 = v4->CurFocused.pObject;
  if ( !v16 )
    goto LABEL_222;
  if ( !((unsigned __int8 (*)(void))v16->vfptr[88].__vecDelDtor)() )
  {
    v17 = HIBYTE(v6->Flags) & 3;
    if ( v17 == 3 )
      v17 = -1;
    if ( v17 != 1 && !v4->ManualFocus )
      goto LABEL_222;
  }
  Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(
    (Scaleform::GFx::DisplayObjectBase *)&v4->CurFocused.pObject->vfptr,
    &result);
  v18 = (Scaleform::Render::Rect<float> *)v4->CurFocused.pObject->vfptr[93].__vecDelDtor(
                                            (Scaleform::RefCountNTSImplCore *)&v4->CurFocused.pObject->vfptr,
                                            (unsigned int)&v106);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(
    &result,
    (Scaleform::Render::Rect<float> *)((char *)&pr + 8),
    v18);
  v19 = v5->Code;
  if ( v4->PrevKeyCode == v19 )
  {
    if ( (v19 - 38) & 0xFFFFFFFD )
    {
      if ( !((v19 - 37) & 0xFFFFFFFD) )
      {
        pr.y2 = v4->Prev_aRect.y1;
        v104.m128_i32[1] = LODWORD(v4->Prev_aRect.y2);
      }
    }
    else
    {
      pr.x2 = v4->Prev_aRect.x1;
      v104.m128_i32[0] = LODWORD(v4->Prev_aRect.x2);
    }
  }
  else
  {
    v4->Prev_aRect.x1 = pr.x2;
    v4->Prev_aRect.y1 = pr.y2;
    *(_QWORD *)&v4->Prev_aRect.x2 = v104.m128_u64[0];
    v4->PrevKeyCode = v5->Code;
  }
  v20 = v5->Code;
  if ( !((v20 - 37) & 0xFFFFFFFD) )
  {
    v55 = v4->CurFocusIdx;
    v111 = FLOAT_2_1474836e9;
    if ( v20 == 39 )
      v56 = (__m128)LODWORD(FLOAT_2_1474836e9);
    else
      v56 = (__m128)LODWORD(FLOAT_N2_1474836e9);
    v101 = v56.m128_f32[0];
    v57 = FLOAT_2_1474836e9;
    v58 = 0;
    v59 = v9 - 1;
    v60 = v55;
    if ( (signed int)v59 <= 0 )
    {
LABEL_221:
      LODWORD(v9) = v105;
      v8 = (Scaleform::GFx::FocusGroupDescr *)v104.m128_u64[1];
      goto LABEL_222;
    }
    v61 = v59;
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
      if ( v60 < *(_QWORD *)&v106.x1 )
      {
        if ( (signed int)v55 < 0 )
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
      v63 = *(_QWORD *)(v104.m128_u64[1] + 8);
      v64 = *(_QWORD *)(v63 + 8 * v60);
      if ( v64 )
        ++*(_DWORD *)(v64 + 8);
      v65 = *(_QWORD *)(v63 + 8 * v60);
      *(_QWORD *)&v106.x2 = v65;
      if ( v4->InclFocusEnabled || (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v65 + 696i64))(v65) )
      {
        if ( (*(unsigned __int8 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)v65 + 680i64))(
               v65,
               v110,
               (unsigned __int8)v4->KeyboardIndex) )
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
    pr = (Scaleform::Render::Rect<float>)_xmm;
    v104 = _xmm;
    v66 = *(Scaleform::GFx::DisplayObjectBase **)(v65 + 56);
    if ( v66 )
    {
      Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(v66, (Scaleform::Render::Matrix2x4<float> *)&pr);
      v67 = (float *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v65 + 16i64))(v65);
      v68 = pr.x1;
      v69 = pr.y1;
      v70 = v104.m128_u64[0];
      pr.x1 = (float)(pr.x1 * *v67) + (float)(pr.y1 * v67[4]);
      v104.m128_f32[0] = (float)(v104.m128_f32[0] * *v67) + (float)(v104.m128_f32[1] * v67[4]);
      pr.y1 = (float)(v68 * v67[1]) + (float)(pr.y1 * v67[5]);
      v104.m128_f32[1] = (float)(*(float *)&v70 * v67[1]) + (float)(v104.m128_f32[1] * v67[5]);
      v104.m128_i32[2] = 0;
      pr.x2 = 0.0;
      pr.y2 = pr.y2 + (float)((float)(v69 * v67[7]) + (float)(v68 * v67[3]));
      v104.m128_f32[3] = v104.m128_f32[3]
                       + (float)((float)(*((float *)&v70 + 1) * v67[7]) + (float)(*(float *)&v70 * v67[3]));
    }
    else
    {
      pr = (Scaleform::Render::Rect<float>)_xmm;
      v104 = _xmm;
    }
    v71 = (Scaleform::Render::Rect<float> *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v65 + 744i64))(
                                              v65,
                                              &v108);
    Scaleform::Render::Matrix2x4<float>::EncloseTransform((Scaleform::Render::Matrix2x4<float> *)&pr, &v106, v71);
    v72 = v112->Code;
    if ( v72 == 39 )
    {
      v73 = v104.m128_f32[0] + v62;
      v74 = FLOAT_3_4028235e38;
    }
    else
    {
      v74 = pr.x2 - v62;
      v73 = FLOAT_1_1754944eN38;
    }
    if ( v106.y2 < pr.y2 || v104.m128_f32[1] < v106.y1 || v74 < v106.x1 || v106.x2 < v73 )
      goto LABEL_234;
    v75 = v106.y1;
    v76 = v106.y2;
    if ( v106.y1 <= pr.y2 )
      v75 = pr.y2;
    if ( v106.y2 > v104.m128_f32[1] )
      v76 = v104.m128_f32[1];
    if ( (float)(v76 - v75) < 40.0 )
    {
LABEL_234:
      if ( v58 )
        goto LABEL_219;
    }
    else if ( !v58 )
    {
      v101 = v106.x1;
      v111 = v106.y2;
      v58 = 1;
LABEL_218:
      v56 = (__m128)LODWORD(v106.x2);
      v57 = v106.y1;
      v4->CurFocusIdx = v55;
      goto LABEL_219;
    }
    v77 = (float)((float)(v104.m128_f32[1] - pr.y2) * 0.5) + pr.y2;
    if ( v72 == 39 )
    {
      v78 = (__m128)LODWORD(v106.x1);
      v79 = (__m128)LODWORD(v101);
      if ( v104.m128_f32[0] > v106.x1 )
        v78 = (__m128)v104.m128_u32[0];
      if ( v104.m128_f32[0] > v101 )
        v79 = (__m128)v104.m128_u32[0];
      if ( v106.x2 < v78.m128_f32[0] || v106.y2 < v106.y1 )
        goto LABEL_219;
      v80 = (float)(v106.x2 - v78.m128_f32[0]) * 0.050000001;
      v81 = v80 <= 0.0 ? v80 - 0.5 : v80 + 0.5;
      if ( (signed int)v81 <= 3 )
        goto LABEL_219;
      v82 = (__m128)LODWORD(v106.y2);
      v83 = (__m128)LODWORD(v111);
      v78.m128_f32[0] = (float)(v78.m128_f32[0] - v104.m128_f32[0]) * 0.050000001;
      v84 = (signed int)v78.m128_f32[0];
      if ( (signed int)v78.m128_f32[0] != 0x80000000 && (float)v84 != v78.m128_f32[0] )
        v78.m128_f32[0] = (float)(v84 - (_mm_movemask_ps(_mm_unpacklo_ps(v78, v78)) & 1));
      v82.m128_f32[0] = (float)((float)((float)((float)(v106.y2 - v106.y1) * 0.5) + v106.y1) - v77) * 0.050000001;
      v85 = (signed int)v82.m128_f32[0];
      if ( (signed int)v82.m128_f32[0] != 0x80000000 && (float)v85 != v82.m128_f32[0] )
        v82.m128_f32[0] = (float)(v85 - (_mm_movemask_ps(_mm_unpacklo_ps(v82, v82)) & 1));
      v79.m128_f32[0] = (float)(v79.m128_f32[0] - v104.m128_f32[0]) * 0.050000001;
      v86 = (signed int)v79.m128_f32[0];
      if ( (signed int)v79.m128_f32[0] != 0x80000000 && (float)v86 != v79.m128_f32[0] )
        v79.m128_f32[0] = (float)(v86 - (_mm_movemask_ps(_mm_unpacklo_ps(v79, v79)) & 1));
      v83.m128_f32[0] = (float)((float)((float)((float)(v111 - v57) * 0.5) + v57) - v77) * 0.050000001;
      v87 = (signed int)v83.m128_f32[0];
      if ( (signed int)v83.m128_f32[0] != 0x80000000 && (float)v87 != v83.m128_f32[0] )
        v83.m128_f32[0] = (float)(v87 - (_mm_movemask_ps(_mm_unpacklo_ps(v83, v83)) & 1));
      if ( v78.m128_f32[0] < 0.0 )
        goto LABEL_219;
    }
    else
    {
      v78 = (__m128)LODWORD(v106.x2);
      v79 = v56;
      if ( pr.x2 < v106.x2 )
        v78 = (__m128)LODWORD(pr.x2);
      if ( pr.x2 < v56.m128_f32[0] )
        v79 = (__m128)LODWORD(pr.x2);
      if ( v78.m128_f32[0] < v106.x1 || v106.y2 < v106.y1 )
        goto LABEL_219;
      v88 = (float)(v78.m128_f32[0] - v106.x1) * 0.050000001;
      v89 = v88 <= 0.0 ? v88 - 0.5 : v88 + 0.5;
      if ( (signed int)v89 <= 3 )
        goto LABEL_219;
      v82 = (__m128)LODWORD(v106.y2);
      v83 = (__m128)LODWORD(v111);
      v78.m128_f32[0] = (float)(v78.m128_f32[0] - pr.x2) * 0.050000001;
      v90 = (signed int)v78.m128_f32[0];
      if ( (signed int)v78.m128_f32[0] != 0x80000000 && (float)v90 != v78.m128_f32[0] )
        v78.m128_f32[0] = (float)(v90 - (_mm_movemask_ps(_mm_unpacklo_ps(v78, v78)) & 1));
      v82.m128_f32[0] = (float)((float)((float)((float)(v106.y2 - v106.y1) * 0.5) + v106.y1) - v77) * 0.050000001;
      v91 = (signed int)v82.m128_f32[0];
      if ( (signed int)v82.m128_f32[0] != 0x80000000 && (float)v91 != v82.m128_f32[0] )
        v82.m128_f32[0] = (float)(v91 - (_mm_movemask_ps(_mm_unpacklo_ps(v82, v82)) & 1));
      v79.m128_f32[0] = (float)(v79.m128_f32[0] - pr.x2) * 0.050000001;
      v92 = (signed int)v79.m128_f32[0];
      if ( (signed int)v79.m128_f32[0] != 0x80000000 && (float)v92 != v79.m128_f32[0] )
        v79.m128_f32[0] = (float)(v92 - (_mm_movemask_ps(_mm_unpacklo_ps(v79, v79)) & 1));
      v83.m128_f32[0] = (float)((float)((float)((float)(v111 - v57) * 0.5) + v57) - v77) * 0.050000001;
      v93 = (signed int)v83.m128_f32[0];
      if ( (signed int)v83.m128_f32[0] != 0x80000000 && (float)v93 != v83.m128_f32[0] )
        v83.m128_f32[0] = (float)(v93 - (_mm_movemask_ps(_mm_unpacklo_ps(v83, v83)) & 1));
      if ( v78.m128_f32[0] > 0.0 )
        goto LABEL_219;
    }
    if ( v58 )
    {
      if ( COERCE_FLOAT(v78.m128_i32[0] & _xmm) >= COERCE_FLOAT(v79.m128_i32[0] & _xmm)
        && (v78.m128_f32[0] != v79.m128_f32[0]
         || COERCE_FLOAT(v82.m128_i32[0] & _xmm) >= COERCE_FLOAT(v83.m128_i32[0] & _xmm)) )
      {
        goto LABEL_219;
      }
      goto LABEL_217;
    }
    if ( (float)((float)(v82.m128_f32[0] * v82.m128_f32[0]) + (float)(v78.m128_f32[0] * v78.m128_f32[0])) < (float)((float)(v83.m128_f32[0] * v83.m128_f32[0]) + (float)(v79.m128_f32[0] * v79.m128_f32[0])) )
    {
LABEL_217:
      v101 = v106.x1;
      v111 = v106.y2;
      goto LABEL_218;
    }
LABEL_219:
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v65);
    v62 = *(float *)&FLOAT_1_0;
    goto LABEL_220;
  }
  if ( !((v20 - 38) & 0xFFFFFFFD) )
  {
    v21 = v4->CurFocusIdx;
    v102 = 0.0;
    v100 = 0.0;
    v22 = FLOAT_2_1474836e9;
    if ( v20 == 40 )
      v23 = FLOAT_2_1474836e9;
    else
      v23 = FLOAT_N2_1474836e9;
    v111 = v23;
    v24 = 0;
    v25 = v9 - 1;
    v26 = v21;
    if ( (signed int)v25 > 0 )
    {
      v27 = v25;
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
        if ( v26 < *(_QWORD *)&v106.x1 )
        {
          if ( (signed int)v21 < 0 )
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
        v29 = *(_QWORD *)(v104.m128_u64[1] + 8);
        v30 = *(_QWORD *)(v29 + 8 * v26);
        if ( v30 )
          ++*(_DWORD *)(v30 + 8);
        v31 = *(Scaleform::GFx::DisplayObjectBase **)(v29 + 8 * v26);
        *(_QWORD *)&v106.x2 = v31;
        if ( v4->InclFocusEnabled
          || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v31->vfptr[87].__vecDelDtor)(v31) )
        {
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, __int64, _QWORD))v31->vfptr[85].__vecDelDtor)(
                 v31,
                 v110,
                 (unsigned __int8)v4->KeyboardIndex) )
          {
            break;
          }
        }
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v31->vfptr);
LABEL_125:
        --v27;
        v5 = v112;
        if ( !v27 )
          goto LABEL_221;
      }
      Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(v31, (Scaleform::Render::Matrix2x4<float> *)&pr);
      v32 = (Scaleform::Render::Rect<float> *)v31->vfptr[93].__vecDelDtor(
                                                (Scaleform::RefCountNTSImplCore *)&v31->vfptr,
                                                (unsigned int)&v108);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform((Scaleform::Render::Matrix2x4<float> *)&pr, &v106, v32);
      v33 = v112->Code;
      if ( v33 == 40 )
      {
        v34 = v104.m128_f32[1] + v28;
        v35 = FLOAT_3_4028235e38;
      }
      else
      {
        v35 = pr.y2 - v28;
        v34 = FLOAT_1_1754944eN38;
      }
      if ( v106.y2 < v34 || v35 < v106.y1 || v104.m128_f32[0] < v106.x1 || v106.x2 < pr.x2 )
        goto LABEL_235;
      v36 = v106.x1;
      v37 = v106.x2;
      if ( v106.x1 <= pr.x2 )
        v36 = pr.x2;
      if ( v106.x2 > v104.m128_f32[0] )
        v37 = v104.m128_f32[0];
      if ( (float)(v37 - v36) < 40.0 )
      {
LABEL_235:
        if ( v24 )
          goto LABEL_124;
      }
      else if ( !v24 )
      {
        v111 = v106.y1;
        v100 = v106.y2;
        v24 = 1;
LABEL_123:
        v102 = v106.x2;
        v22 = v106.x1;
        v4->CurFocusIdx = v21;
        goto LABEL_124;
      }
      v38 = (float)((float)(v104.m128_f32[0] - pr.x2) * 0.5) + pr.x2;
      if ( v33 == 38 )
      {
        v39 = (__m128)LODWORD(v106.y2);
        v40 = (__m128)LODWORD(v100);
        if ( pr.y2 < v106.y2 )
          v39 = (__m128)LODWORD(pr.y2);
        if ( pr.y2 < v100 )
          v40 = (__m128)LODWORD(pr.y2);
        if ( v106.x2 < v106.x1 || v39.m128_f32[0] < v106.y1 )
          goto LABEL_124;
        v41 = (float)(v39.m128_f32[0] - v106.y1) * 0.050000001;
        v42 = v41 <= 0.0 ? v41 - 0.5 : v41 + 0.5;
        if ( (signed int)v42 <= 3 )
          goto LABEL_124;
        v44 = (__m128)LODWORD(v106.x2);
        v43 = (__m128)LODWORD(v102);
        v44.m128_f32[0] = (float)((float)((float)((float)(v106.x2 - v106.x1) * 0.5) + v106.x1) - v38) * 0.050000001;
        v45 = (signed int)v44.m128_f32[0];
        if ( (signed int)v44.m128_f32[0] != 0x80000000 && (float)v45 != v44.m128_f32[0] )
          v44.m128_f32[0] = (float)(v45 - (_mm_movemask_ps(_mm_unpacklo_ps(v44, v44)) & 1));
        v39.m128_f32[0] = (float)(v39.m128_f32[0] - pr.y2) * 0.050000001;
        v46 = (signed int)v39.m128_f32[0];
        if ( (signed int)v39.m128_f32[0] != 0x80000000 && (float)v46 != v39.m128_f32[0] )
          v39.m128_f32[0] = (float)(v46 - (_mm_movemask_ps(_mm_unpacklo_ps(v39, v39)) & 1));
        v43.m128_f32[0] = (float)((float)((float)((float)(v102 - v22) * 0.5) + v22) - v38) * 0.050000001;
        v47 = (signed int)v43.m128_f32[0];
        if ( (signed int)v43.m128_f32[0] != 0x80000000 && (float)v47 != v43.m128_f32[0] )
          v43.m128_f32[0] = (float)(v47 - (_mm_movemask_ps(_mm_unpacklo_ps(v43, v43)) & 1));
        v40.m128_f32[0] = (float)(v40.m128_f32[0] - pr.y2) * 0.050000001;
        v48 = (signed int)v40.m128_f32[0];
        if ( (signed int)v40.m128_f32[0] != 0x80000000 && (float)v48 != v40.m128_f32[0] )
          v40.m128_f32[0] = (float)(v48 - (_mm_movemask_ps(_mm_unpacklo_ps(v40, v40)) & 1));
        if ( v39.m128_f32[0] > 0.0 )
          goto LABEL_124;
      }
      else
      {
        v39 = (__m128)LODWORD(v106.y1);
        v40 = (__m128)LODWORD(v111);
        if ( v104.m128_f32[1] > v106.y1 )
          v39 = (__m128)v104.m128_u32[1];
        if ( v104.m128_f32[1] > v111 )
          v40 = (__m128)v104.m128_u32[1];
        if ( v106.x2 < v106.x1 || v106.y2 < v39.m128_f32[0] )
          goto LABEL_124;
        v49 = (float)(v106.y2 - v39.m128_f32[0]) * 0.050000001;
        v50 = v49 <= 0.0 ? v49 - 0.5 : v49 + 0.5;
        if ( (signed int)v50 <= 3 )
          goto LABEL_124;
        v44 = (__m128)LODWORD(v106.x2);
        v43 = (__m128)LODWORD(v102);
        v44.m128_f32[0] = (float)((float)((float)((float)(v106.x2 - v106.x1) * 0.5) + v106.x1) - v38) * 0.050000001;
        v51 = (signed int)v44.m128_f32[0];
        if ( (signed int)v44.m128_f32[0] != 0x80000000 && (float)v51 != v44.m128_f32[0] )
          v44.m128_f32[0] = (float)(v51 - (_mm_movemask_ps(_mm_unpacklo_ps(v44, v44)) & 1));
        v39.m128_f32[0] = (float)(v39.m128_f32[0] - v104.m128_f32[1]) * 0.050000001;
        v52 = (signed int)v39.m128_f32[0];
        if ( (signed int)v39.m128_f32[0] != 0x80000000 && (float)v52 != v39.m128_f32[0] )
          v39.m128_f32[0] = (float)(v52 - (_mm_movemask_ps(_mm_unpacklo_ps(v39, v39)) & 1));
        v43.m128_f32[0] = (float)((float)((float)((float)(v102 - v22) * 0.5) + v22) - v38) * 0.050000001;
        v53 = (signed int)v43.m128_f32[0];
        if ( (signed int)v43.m128_f32[0] != 0x80000000 && (float)v53 != v43.m128_f32[0] )
          v43.m128_f32[0] = (float)(v53 - (_mm_movemask_ps(_mm_unpacklo_ps(v43, v43)) & 1));
        v40.m128_f32[0] = (float)(v40.m128_f32[0] - v104.m128_f32[1]) * 0.050000001;
        v54 = (signed int)v40.m128_f32[0];
        if ( (signed int)v40.m128_f32[0] != 0x80000000 && (float)v54 != v40.m128_f32[0] )
          v40.m128_f32[0] = (float)(v54 - (_mm_movemask_ps(_mm_unpacklo_ps(v40, v40)) & 1));
        if ( v39.m128_f32[0] < 0.0 )
          goto LABEL_124;
      }
      if ( v24 )
      {
        if ( COERCE_FLOAT(v39.m128_i32[0] & _xmm) >= COERCE_FLOAT(v40.m128_i32[0] & _xmm)
          && (v39.m128_f32[0] != v40.m128_f32[0]
           || COERCE_FLOAT(v44.m128_i32[0] & _xmm) >= COERCE_FLOAT(v43.m128_i32[0] & _xmm)) )
        {
          goto LABEL_124;
        }
        goto LABEL_122;
      }
      if ( (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v44.m128_f32[0] * v44.m128_f32[0])) < (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v43.m128_f32[0] * v43.m128_f32[0])) )
      {
LABEL_122:
        v111 = v106.y1;
        v100 = v106.y2;
        goto LABEL_123;
      }
LABEL_124:
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v31->vfptr);
      v28 = *(float *)&FLOAT_1_0;
      goto LABEL_125;
    }
    goto LABEL_221;
  }
LABEL_222:
  v94 = v4->CurFocusIdx;
  if ( (signed int)v94 < 0 || (signed int)v94 >= (signed int)v9 )
  {
    v99 = (Scaleform::RefCountNTSImpl *)&v4->CurFocused.pObject->vfptr;
    if ( v99 )
      Scaleform::RefCountNTSImpl::Release(v99);
    v4->CurFocused.pObject = 0i64;
  }
  else
  {
    v95 = v4->CurFocusIdx;
    v96 = v8->TabableArray.Data.Data;
    v97 = v96[v94].pObject;
    if ( v97 )
      ++v97->RefCount;
    v98 = (Scaleform::RefCountNTSImpl *)&v4->CurFocused.pObject->vfptr;
    if ( v98 )
      Scaleform::RefCountNTSImpl::Release(v98);
    v4->CurFocused = v96[v95];
  }
}
      Scaleform::RefCountNTSImpl::Release(v98);
    v4->CurFocused = v96[v95];
  }
}

// File Line: 4261
// RVA: 0x8CB550
void __fastcall Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo)
{
  Scaleform::GFx::ProcessFocusKeyInfo *pfocusKeyInfo; // rbp
  Scaleform::GFx::MovieImpl *v3; // rdi
  unsigned __int64 v4; // rsi
  int v5; // eax
  Scaleform::GFx::InteractiveObject *v6; // r14
  Scaleform::GFx::Sprite *v7; // rbx
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::Sprite *v12; // [rsp+68h] [rbp+10h]

  pfocusKeyInfo = pfocusInfo;
  v3 = this;
  v4 = (unsigned __int8)this->FocusGroupIndexes[(unsigned __int8)pfocusInfo->KeyboardIndex];
  if ( pfocusInfo->Initialized )
  {
    if ( this->FocusGroups[v4].TabableArrayStatus & 1 )
    {
      v5 = pfocusInfo->CurFocusIdx;
      if ( v5 >= 0 && v5 < SLODWORD(this->FocusGroups[v4].TabableArray.Data.Size) )
      {
        v6 = this->FocusGroups[v4].TabableArray.Data.Data[pfocusInfo->CurFocusIdx].pObject;
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
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
        if ( v7 != (Scaleform::GFx::Sprite *)v6 )
        {
          v3->FocusGroups[v4].LastFocusKeyCode = pfocusKeyInfo->PrevKeyCode;
          v8 = pfocusKeyInfo->Prev_aRect.y2;
          v9 = pfocusKeyInfo->Prev_aRect.x2;
          v10 = pfocusKeyInfo->Prev_aRect.y1;
          v3->FocusGroups[v4].LastFocusedRect.x1 = pfocusKeyInfo->Prev_aRect.x1;
          v3->FocusGroups[v4].LastFocusedRect.y1 = v10;
          v3->FocusGroups[v4].LastFocusedRect.x2 = v9;
          v3->FocusGroups[v4].LastFocusedRect.y2 = v8;
          Scaleform::GFx::MovieImpl::QueueSetFocusTo(
            v3,
            v6,
            0i64,
            (unsigned __int8)pfocusKeyInfo->KeyboardIndex,
            GFx_FocusMovedByKeyboard,
            pfocusKeyInfo);
        }
        if ( v6
          && ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject *))v6->vfptr[81].__vecDelDtor)(v6) == 4 )
        {
          if ( v3->FocusGroups[v4].FocusRectShown )
            v3->FocusRectChanged = 1;
          v3->FocusGroups[v4].FocusRectShown = 0;
        }
        else
        {
          if ( !v3->FocusGroups[v4].FocusRectShown )
            v3->FocusRectChanged = 1;
          v3->FocusGroups[v4].FocusRectShown = 1;
        }
        if ( v7 )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v7->vfptr);
      }
    }
  }
}

// File Line: 4316
// RVA: 0x909820
void __fastcall Scaleform::GFx::MovieImpl::SetModalClip(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::Sprite *pmovie, unsigned int controllerIdx)
{
  char *v3; // rsi
  _QWORD *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::CharacterHandle *v9; // rdi
  _QWORD *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx

  v3 = (char *)this + 96 * (unsigned __int8)this->FocusGroupIndexes[controllerIdx];
  if ( pmovie )
  {
    v9 = pmovie->pNameHandle.pObject;
    if ( v9
      || (v9 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&pmovie->vfptr)) != 0i64 )
    {
      ++v9->RefCount;
    }
    v10 = (_QWORD *)*((_QWORD *)v3 + 2458);
    if ( v10 )
    {
      if ( --*(_DWORD *)v10 <= 0 )
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
    *((_QWORD *)v3 + 2458) = v9;
  }
  else
  {
    v4 = (_QWORD *)*((_QWORD *)v3 + 2458);
    if ( v4 )
    {
      if ( --*(_DWORD *)v4 <= 0 )
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
Scaleform::RefCountNTSImpl *__fastcall Scaleform::GFx::MovieImpl::GetModalClip(Scaleform::GFx::MovieImpl *this, unsigned int controllerIdx)
{
  Scaleform::GFx::CharacterHandle *v2; // rdx
  Scaleform::RefCountNTSImpl *v3; // rbx

  v2 = this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]].ModalClip.pObject;
  if ( !v2 )
    return 0i64;
  v3 = (Scaleform::RefCountNTSImpl *)&v2->pCharacter->vfptr;
  if ( v3
    || (v3 = (Scaleform::RefCountNTSImpl *)this->pASMovieRoot.pObject->vfptr[8].__vecDelDtor(
                                             (Scaleform::RefCountImplCore *)this->pASMovieRoot.pObject,
                                             (unsigned int)&v2->NamePath)) != 0i64 )
  {
    ++v3->RefCount;
  }
  if ( !v3 )
    return 0i64;
  Scaleform::RefCountNTSImpl::Release(v3);
  return v3;
}

// File Line: 4332
// RVA: 0x8D6510
__int64 __fastcall Scaleform::GFx::MovieImpl::GetControllerMaskByFocusGroup(Scaleform::GFx::MovieImpl *this, unsigned int focusGroupIndex)
{
  unsigned int v2; // er9
  char *v3; // r10
  int v4; // er8
  signed __int64 v5; // r11
  int v6; // er8
  int v7; // er8
  int v8; // er8

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
  Scaleform::GFx::MovieImpl *v1; // r14
  Scaleform::Render::TreeContainer *v2; // rbx
  Scaleform::Render::TreeNode *v3; // rbx
  Scaleform::Render::ContextImpl::Entry *v4; // rcx
  bool v5; // zf
  signed __int64 v6; // rax
  signed __int64 v7; // r13
  int v8; // edi
  signed __int64 v9; // r12
  Scaleform::GFx::Sprite *v10; // rbx
  Scaleform::GFx::DisplayObjectBase *v11; // rcx
  Scaleform::Render::Matrix3x4<float> *v12; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  unsigned int v17; // xmm4_4
  unsigned int v18; // xmm5_4
  unsigned int v19; // xmm6_4
  unsigned int v20; // xmm7_4
  unsigned int v21; // xmm8_4
  unsigned int v22; // xmm9_4
  unsigned int v23; // xmm10_4
  float v24; // xmm11_4
  float *v25; // rax
  float v26; // xmm0_4
  float v27; // xmm7_4
  float v28; // xmm8_4
  float v29; // xmm9_4
  float v30; // xmm10_4
  __int64 v31; // rcx
  Scaleform::Render::ShapeDataFloat *v32; // rax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v33; // rax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v34; // rsi
  signed __int64 v35; // rcx
  signed __int64 v36; // rdx
  __int64 v37; // rdx
  float v38; // xmm1_4
  float v39; // xmm1_4
  float v40; // xmm1_4
  float v41; // xmm7_4
  float v42; // xmm1_4
  __int64 v43; // rcx
  Scaleform::Render::ShapeMeshProvider *v44; // rax
  Scaleform::Render::ShapeMeshProvider *v45; // rax
  Scaleform::Render::ShapeMeshProvider *v46; // r15
  Scaleform::Render::TreeShape *v47; // rdi
  Scaleform::Render::ContextImpl::Entry *v48; // rcx
  __int128 Dst; // [rsp+20h] [rbp-A0h]
  __int128 v50; // [rsp+30h] [rbp-90h]
  Scaleform::Render::Matrix3x4<float> v51; // [rsp+40h] [rbp-80h]
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+70h] [rbp-50h]
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v53; // [rsp+A0h] [rbp-20h]
  Scaleform::Render::TreeShape *v54; // [rsp+A8h] [rbp-18h]
  __int64 v55; // [rsp+B0h] [rbp-10h]
  unsigned int v56; // [rsp+B8h] [rbp-8h]
  __int64 v57; // [rsp+C0h] [rbp+0h]
  Scaleform::Render::ShapeMeshProvider *v58; // [rsp+C8h] [rbp+8h]
  int v59; // [rsp+190h] [rbp+D0h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+198h] [rbp+D8h]
  Scaleform::GFx::Sprite *v61; // [rsp+1A0h] [rbp+E0h]
  __int64 v62; // [rsp+1A8h] [rbp+E8h]

  v55 = -2i64;
  v1 = this;
  if ( this->pMainMovie )
  {
    v2 = this->FocusRectContainerNode.pObject;
    if ( v2 )
    {
      v6 = Scaleform::Render::TreeContainer::GetSize(this->FocusRectContainerNode.pObject);
      Scaleform::Render::TreeContainer::Remove(v2, 0i64, v6);
    }
    else
    {
      v3 = (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&this->RenderContext);
      v4 = (Scaleform::Render::ContextImpl::Entry *)&v1->FocusRectContainerNode.pObject->0;
      if ( v4 )
      {
        v5 = v4->RefCount-- == 1;
        if ( v5 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
      }
      v1->FocusRectContainerNode.pObject = (Scaleform::Render::TreeContainer *)v3;
      Scaleform::Render::TreeContainer::Add((Scaleform::Render::TreeContainer *)&v1->pRenderRoot.pObject->0, v3);
    }
    v7 = 0i64;
    if ( v1->FocusGroupsCnt )
    {
      v8 = 0;
      v59 = 0;
      do
      {
        v9 = v7;
        Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
          (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v1->FocusGroups[v7].LastFocused,
          &result);
        v10 = result.pObject;
        if ( result.pObject )
        {
          ++result.pObject->RefCount;
          v10 = result.pObject;
        }
        v61 = v10;
        if ( result.pObject )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
        if ( v10
          && v1->FocusGroups[v9].FocusRectShown
          && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *))v10->vfptr[88].__vecDelDtor)(v10) )
        {
          v10->vfptr[93].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v10->vfptr, (unsigned int)v51.M[2]);
          if ( v51.M[2][2] == v51.M[2][0] && v51.M[2][3] == v51.M[2][1] )
          {
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v10->vfptr);
            return;
          }
          memset(&Dst, 0, 0x30ui64);
          LODWORD(Dst) = 1065353216;
          DWORD1(v50) = 1065353216;
          v51.M[0][2] = 1.0;
          v11 = v10->pParentChar;
          if ( v11 )
          {
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(v11, (Scaleform::Render::Matrix3x4<float> *)&Dst);
            v12 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))v10->vfptr[4].__vecDelDtor)(v10);
            *(_OWORD *)&m1.M[0][0] = Dst;
            *(_OWORD *)&m1.M[1][0] = v50;
            *(_OWORD *)&m1.M[2][0] = *(_OWORD *)&v51.M[0][0];
            Scaleform::Render::Matrix3x4<float>::MultiplyMatrix((Scaleform::Render::Matrix3x4<float> *)&Dst, &m1, v12);
            v13 = v51.M[0][3];
            v14 = v51.M[0][2];
            v15 = v51.M[0][1];
            v16 = v51.M[0][0];
            v17 = HIDWORD(v50);
            v18 = DWORD2(v50);
            v19 = DWORD1(v50);
            v20 = v50;
            v21 = HIDWORD(Dst);
            v22 = DWORD2(Dst);
            v23 = DWORD1(Dst);
            LODWORD(v24) = Dst;
          }
          else
          {
            v25 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))v10->vfptr[4].__vecDelDtor)(v10);
            v24 = *v25;
            *(float *)&Dst = *v25;
            v23 = *((_DWORD *)v25 + 1);
            *((float *)&Dst + 1) = v25[1];
            v22 = *((_DWORD *)v25 + 2);
            *((float *)&Dst + 2) = v25[2];
            v21 = *((_DWORD *)v25 + 3);
            *((float *)&Dst + 3) = v25[3];
            v20 = *((_DWORD *)v25 + 4);
            *(float *)&v50 = v25[4];
            v19 = *((_DWORD *)v25 + 5);
            *((float *)&v50 + 1) = v25[5];
            v18 = *((_DWORD *)v25 + 6);
            *((float *)&v50 + 2) = v25[6];
            v17 = *((_DWORD *)v25 + 7);
            *((float *)&v50 + 3) = v25[7];
            v16 = v25[8];
            v51.M[0][0] = v25[8];
            v15 = v25[9];
            v51.M[0][1] = v25[9];
            v14 = v25[10];
            v51.M[0][2] = v25[10];
            v13 = v25[11];
            v51.M[0][3] = v25[11];
          }
          *(_QWORD *)&v51.M[0][0] = __PAIR__(v23, LODWORD(v24));
          *(_QWORD *)&v51.M[0][2] = __PAIR__(v21, v22);
          *(_QWORD *)&v51.M[1][0] = __PAIR__(v19, v20);
          *(_QWORD *)&v51.M[1][2] = __PAIR__(v17, v18);
          *(_QWORD *)&v51.M[2][0] = __PAIR__(LODWORD(v15), LODWORD(v16));
          *(_QWORD *)&v51.M[2][2] = __PAIR__(LODWORD(v13), LODWORD(v14));
          Scaleform::Render::Matrix3x4<float>::EncloseTransform(
            &v51,
            (Scaleform::Render::Rect<float> *)v51.M[1],
            (Scaleform::Render::Rect<float> *)v51.M[2]);
          v26 = (float)(signed int)v7 * 20.0;
          v27 = v51.M[1][0] - v26;
          v51.M[1][0] = v51.M[1][0] - v26;
          v28 = v51.M[1][2] + v26;
          v51.M[1][2] = v51.M[1][2] + v26;
          v29 = v51.M[1][1] - v26;
          v51.M[1][1] = v51.M[1][1] - v26;
          v30 = v51.M[1][3] + v26;
          v51.M[1][3] = v51.M[1][3] + v26;
          v62 = (__int64)v1->RenderContext.pHeap;
          v32 = (Scaleform::Render::ShapeDataFloat *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v62 + 80i64))(
                                                       v31,
                                                       128i64,
                                                       0i64);
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
            (Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> *)&v34->Fills.Data.Data,
            &v34->Fills,
            v34->Fills.Data.Size + 1);
          v35 = 16 * v34->Fills.Data.Size;
          v36 = (signed __int64)&v34->Fills.Data.Data[-1];
          v5 = v35 + v36 == 0;
          v37 = v35 + v36;
          v62 = v37;
          *(_QWORD *)&m1.M[0][0] = v37;
          if ( !v5 )
          {
            *(_DWORD *)v37 = v8 ^ 0xFFFFFF00 | 0xFF000000;
            *(_QWORD *)(v37 + 8) = 0i64;
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
          v38 = v34->StartX;
          if ( v38 != v34->LastX || v34->StartY != v34->LastY )
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
              v34,
              v38,
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
          v62 = (__int64)v1->RenderContext.pHeap;
          v44 = (Scaleform::Render::ShapeMeshProvider *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v62 + 80i64))(
                                                          v43,
                                                          144i64,
                                                          0i64);
          *(_QWORD *)&m1.M[0][0] = v44;
          if ( v44 )
          {
            Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(
              v44,
              (Scaleform::Render::ShapeDataInterface *)&v34->vfptr,
              0i64);
            v46 = v45;
          }
          else
          {
            v46 = 0i64;
          }
          v58 = v46;
          v47 = (Scaleform::Render::TreeShape *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(&v1->RenderContext);
          v54 = v47;
          Scaleform::Render::TreeShape::SetShape(v47, v46);
          Scaleform::Render::TreeContainer::Add(
            v1->FocusRectContainerNode.pObject,
            (Scaleform::Render::TreeNode *)&v47->0);
          if ( v47 )
            ++v47->RefCount;
          v48 = (Scaleform::Render::ContextImpl::Entry *)&v1->FocusGroups[v9].FocusRectNode.pObject->0;
          if ( v48 )
          {
            v5 = v48->RefCount-- == 1;
            if ( v5 )
              Scaleform::Render::ContextImpl::Entry::destroyHelper(v48);
          }
          v1->FocusGroups[v9].FocusRectNode.pObject = v47;
          if ( v47 )
          {
            v5 = v47->RefCount-- == 1;
            if ( v5 )
              Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v47->0);
          }
          if ( v46 )
            ((void (*)(void))v46->vfptr->Release)();
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v34);
          v8 = v59;
        }
        if ( v10 )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v10->vfptr);
        v7 = (unsigned int)(v7 + 1);
        v8 += 1081552;
        v59 = v8;
      }
      while ( (unsigned int)v7 < v1->FocusGroupsCnt );
    }
    v1->FocusRectChanged = 0;
  }
}

// File Line: 4434
// RVA: 0x8E32E0
void __fastcall Scaleform::GFx::MovieImpl::HideFocusRect(Scaleform::GFx::MovieImpl *this, unsigned int controllerIdx)
{
  unsigned int v2; // ebp
  Scaleform::GFx::MovieImpl *v3; // rsi
  __int64 v4; // rdi
  Scaleform::GFx::Sprite *v5; // rbx
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::Sprite *v7; // [rsp+60h] [rbp+18h]

  v2 = controllerIdx;
  v3 = this;
  v4 = (unsigned __int8)this->FocusGroupIndexes[controllerIdx];
  if ( this->FocusGroups[v4].FocusRectShown )
  {
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[v4].LastFocused,
      &result);
    v5 = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      v5 = result.pObject;
    }
    v7 = v5;
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
    if ( v5
      && v5->pParent
      && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *, _QWORD, _QWORD, signed __int64, signed __int64))v5->vfptr[92].__vecDelDtor)(
            v5,
            0i64,
            v2,
            2i64,
            -2i64) )
    {
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v5->vfptr);
      return;
    }
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v5->vfptr);
  }
  v3->FocusGroups[v4].FocusRectShown = 0;
  v3->FocusRectChanged = 1;
}

// File Line: 4448
// RVA: 0x907520
__int64 __fastcall Scaleform::GFx::MovieImpl::SetFocusTo(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InteractiveObject *ch, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::FocusMovedType v4; // er14
  unsigned int v5; // esi
  Scaleform::GFx::InteractiveObject *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // rbp
  Scaleform::GFx::Sprite *v8; // rbx
  unsigned __int8 v9; // di
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::Sprite *v12; // [rsp+58h] [rbp+10h]

  v4 = fmt;
  v5 = controllerIdx;
  v6 = ch;
  v7 = this;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]].LastFocused,
    &result);
  v8 = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    v8 = result.pObject;
  }
  v12 = v8;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
  if ( v8 == (Scaleform::GFx::Sprite *)v6
    || (v7->FocusRectChanged = 1, v8)
    && v8->pParent
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *, Scaleform::GFx::InteractiveObject *, _QWORD, _QWORD, signed __int64))v8->vfptr[92].__vecDelDtor)(
          v8,
          v6,
          v5,
          (unsigned int)v4,
          -2i64) )
  {
    v9 = 0;
  }
  else
  {
    Scaleform::GFx::MovieImpl::TransferFocus(v7, v6, v5, v4);
    if ( v6 )
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, _QWORD, _QWORD))v6->vfptr[91].__vecDelDtor)(
        v6,
        v5,
        (unsigned int)v4);
    v9 = 1;
  }
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v8->vfptr);
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
__int64 __fastcall Scaleform::GFx::MovieImpl::QueueSetFocusTo(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InteractiveObject *ch, Scaleform::GFx::InteractiveObject *ptopMostCh, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt, Scaleform::GFx::ProcessFocusKeyInfo *pfocusKeyInfo)
{
  unsigned int v6; // ebp
  Scaleform::GFx::InteractiveObject *v7; // rdi
  Scaleform::GFx::MovieImpl *v8; // r14
  Scaleform::GFx::Sprite *v9; // rbx
  Scaleform::GFx::FocusMovedType v10; // esi
  unsigned __int8 v11; // di
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::Sprite *v14; // [rsp+68h] [rbp+10h]

  v6 = controllerIdx;
  v7 = ch;
  v8 = this;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]].LastFocused,
    &result);
  v9 = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    v9 = result.pObject;
  }
  v14 = v9;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
  if ( v9 == (Scaleform::GFx::Sprite *)v7 )
    goto LABEL_22;
  v8->FocusRectChanged = 1;
  v10 = fmt;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::Sprite *, Scaleform::GFx::InteractiveObject *, _QWORD, Scaleform::GFx::FocusMovedType, Scaleform::GFx::ProcessFocusKeyInfo *, signed __int64))v8->pASMovieRoot.pObject->vfptr[22].__vecDelDtor)(
          v8->pASMovieRoot.pObject,
          v9,
          v7,
          v6,
          fmt,
          pfocusKeyInfo,
          -2i64) )
    goto LABEL_22;
  if ( v7 && !(unsigned __int8)v7->vfptr[89].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v7->vfptr, v10) )
    v7 = 0i64;
  if ( v9
    && v9->pParent
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *, Scaleform::GFx::InteractiveObject *, _QWORD, _QWORD))v9->vfptr[92].__vecDelDtor)(
          v9,
          v7,
          v6,
          (unsigned int)v10) )
  {
LABEL_22:
    v11 = 0;
  }
  else
  {
    if ( v7 )
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, _QWORD, _QWORD))v7->vfptr[91].__vecDelDtor)(
        v7,
        v6,
        (unsigned int)v10);
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::InteractiveObject *, _QWORD, _QWORD))v8->pASMovieRoot.pObject->vfptr[20].__vecDelDtor)(
      v8->pASMovieRoot.pObject,
      v7,
      v6,
      (unsigned int)v10);
    v11 = 1;
  }
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v9->vfptr);
  return v11;
}

// File Line: 4552
// RVA: 0x913190
void __fastcall Scaleform::GFx::MovieImpl::TransferFocus(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InteractiveObject *pNewFocus, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::FocusMovedType v4; // er13
  unsigned int v5; // er12
  Scaleform::GFx::InteractiveObject *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // r15
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *v8; // rsi
  Scaleform::RefCountNTSImpl *v9; // rbx
  int v10; // er14
  Scaleform::WeakPtrProxy *v11; // rdx
  bool v12; // zf
  Scaleform::WeakPtrProxy *v13; // rbp
  Scaleform::WeakPtrProxy *v14; // rdx
  Scaleform::WeakPtrProxy *v15; // rdx
  Scaleform::WeakPtrProxy *v16; // rbp
  Scaleform::WeakPtrProxy *v17; // rdx
  Scaleform::WeakPtrProxy *v18; // rdx
  _QWORD v19[11]; // [rsp+20h] [rbp-58h]
  Scaleform::RefCountNTSImpl *v20; // [rsp+80h] [rbp+8h]
  Scaleform::RefCountNTSImpl *v21; // [rsp+88h] [rbp+10h]

  v4 = fmt;
  v5 = controllerIdx;
  v6 = pNewFocus;
  v7 = this;
  v8 = (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]].LastFocused;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    v8,
    (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&v20);
  v9 = v20;
  if ( v20 )
  {
    ++v20->RefCount;
    v9 = v20;
  }
  v21 = v9;
  if ( v20 )
    Scaleform::RefCountNTSImpl::Release(v20);
  if ( v9 != (Scaleform::RefCountNTSImpl *)v6 )
  {
    v7->FocusRectChanged = 1;
    v10 = (unsigned __int8)v7->pASMovieRoot.pObject->AVMVersion;
    if ( v10 == 2 )
    {
      if ( !v6 )
        goto LABEL_42;
      if ( !(unsigned __int8)v6->vfptr[89].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, v4) )
      {
        v11 = v8->pProxy.pObject;
        if ( v8->pProxy.pObject )
        {
          v12 = v11->RefCount-- == 1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        }
        v6 = 0i64;
LABEL_21:
        v8->pProxy.pObject = 0i64;
        goto LABEL_22;
      }
      if ( !v6 )
      {
LABEL_42:
        v15 = v8->pProxy.pObject;
        if ( v8->pProxy.pObject )
        {
          v12 = v15->RefCount-- == 1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        }
        goto LABEL_21;
      }
      v13 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v6->vfptr);
      v14 = v8->pProxy.pObject;
      if ( v8->pProxy.pObject )
      {
        v12 = v14->RefCount-- == 1;
        if ( v12 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      }
      v8->pProxy.pObject = v13;
    }
LABEL_22:
    if ( v9 && *(_QWORD *)&v9[3].RefCount )
      ((void (__fastcall *)(Scaleform::RefCountNTSImpl *, _QWORD, Scaleform::GFx::InteractiveObject *, _QWORD, Scaleform::GFx::FocusMovedType))v9->vfptr[90].__vecDelDtor)(
        v9,
        0i64,
        v6,
        v5,
        v4);
    if ( v10 == 1 )
    {
      if ( !v6 )
      {
        v18 = v8->pProxy.pObject;
        if ( v8->pProxy.pObject )
        {
          v12 = v18->RefCount-- == 1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        }
        v8->pProxy.pObject = 0i64;
        goto LABEL_37;
      }
      v16 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v6->vfptr);
      v17 = v8->pProxy.pObject;
      if ( v8->pProxy.pObject )
      {
        v12 = v17->RefCount-- == 1;
        if ( v12 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      }
      v8->pProxy.pObject = v16;
    }
    if ( v6 )
    {
      LODWORD(v19[0]) = v4;
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, signed __int64, Scaleform::RefCountNTSImpl *, _QWORD, _QWORD))v6->vfptr[90].__vecDelDtor)(
        v6,
        1i64,
        v9,
        v5,
        v19[0]);
    }
LABEL_37:
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::RefCountNTSImpl *, Scaleform::GFx::InteractiveObject *, _QWORD))v7->pASMovieRoot.pObject->vfptr[21].__vecDelDtor)(
      v7->pASMovieRoot.pObject,
      v9,
      v6,
      v5);
  }
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release(v9);
}

// File Line: 4599
// RVA: 0x9084F0
void __fastcall Scaleform::GFx::MovieImpl::SetKeyboardFocusTo(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InteractiveObject *ch, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::InteractiveObject *v4; // rbx
  unsigned int v5; // er14
  Scaleform::GFx::FocusMovedType v6; // er15
  Scaleform::GFx::MovieImpl *v7; // rsi
  Scaleform::GFx::FocusGroupDescr *v8; // rdi
  int v9; // ebp
  bool v10; // zf

  v4 = ch;
  v5 = controllerIdx;
  v6 = fmt;
  v7 = this;
  v8 = &this->FocusGroups[(unsigned __int8)this->FocusGroupIndexes[controllerIdx]];
  if ( ch && ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject *))ch->vfptr[81].__vecDelDtor)(ch) == 4 )
  {
    if ( v8->FocusRectShown )
      v7->FocusRectChanged = 1;
    v8->FocusRectShown = 0;
  }
  else
  {
    if ( !v8->FocusRectShown )
      v7->FocusRectChanged = 1;
    v8->FocusRectShown = 1;
  }
  v9 = 0;
  v8->LastFocusKeyCode = 0;
  if ( (unsigned __int8)Scaleform::GFx::MovieImpl::SetFocusTo(v7, v4, v5, v6) && v8->FocusRectShown )
  {
    v10 = v4 == 0i64;
    if ( v4 )
    {
      do
      {
        if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v4->vfptr[59].__vecDelDtor)(v4) )
          break;
        v4 = v4->pParent;
      }
      while ( v4 );
      v10 = v4 == 0i64;
    }
    LOBYTE(v9) = v10;
    if ( v8->FocusRectShown != v9 )
      v7->FocusRectChanged = 1;
    v8->FocusRectShown = v4 == 0i64;
  }
}

// File Line: 4647
// RVA: 0x901310
void __fastcall Scaleform::GFx::MovieImpl::ResetFocusForChar(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::InteractiveObject *v2; // r13
  Scaleform::GFx::MovieImpl *v3; // r15
  __int64 v4; // rbp
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *v5; // r12
  Scaleform::GFx::Sprite *v6; // rbx
  Scaleform::GFx::Sprite *v7; // rbx
  unsigned int v8; // edi
  int v9; // eax
  char *v10; // rdx
  signed __int64 v11; // r8
  int v12; // eax
  int v13; // eax
  int v14; // eax
  unsigned int v15; // er14
  unsigned int i; // esi
  Scaleform::WeakPtrProxy *v17; // rdx
  bool v18; // zf
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+70h] [rbp+8h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> v20; // [rsp+80h] [rbp+18h]
  Scaleform::GFx::Sprite *v21; // [rsp+88h] [rbp+20h]

  v2 = ch;
  v3 = this;
  v4 = 0i64;
  if ( this->FocusGroupsCnt )
  {
    do
    {
      v5 = (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)((char *)v3 + 96 * v4);
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        v5 + 2457,
        &result);
      v6 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        v6 = result.pObject;
      }
      v21 = v6;
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
      if ( v6 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v6->vfptr);
      if ( v6 == (Scaleform::GFx::Sprite *)v2 )
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
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v20.pObject->vfptr);
        if ( v7 && !Scaleform::GFx::MovieImpl::IsShutdowning(v3) )
        {
          v8 = 0;
          v9 = 1;
          v10 = &v3->FocusGroupIndexes[1];
          v11 = 4i64;
          do
          {
            if ( (unsigned __int8)*(v10 - 1) == (_DWORD)v4 )
              v8 |= v9;
            v12 = 2 * v9;
            if ( (unsigned __int8)*v10 == (_DWORD)v4 )
              v8 |= v12;
            v13 = 2 * v12;
            if ( (unsigned __int8)v10[1] == (_DWORD)v4 )
              v8 |= v13;
            v14 = 2 * v13;
            if ( (unsigned __int8)v10[2] == (_DWORD)v4 )
              v8 |= v14;
            v9 = 2 * v14;
            v10 += 4;
            --v11;
          }
          while ( v11 );
          v15 = (__int64)v3->vfptr[46].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)v10);
          for ( i = 0; v8; v8 >>= 1 )
          {
            if ( i >= v15 )
              break;
            Scaleform::GFx::MovieImpl::SetFocusTo(v3, 0i64, i++, GFx_FocusMovedByKeyboard);
          }
        }
        v17 = v5[2457].pProxy.pObject;
        if ( v17 )
        {
          v18 = v17->RefCount-- == 1;
          if ( v18 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::WeakPtrProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
              Scaleform::Memory::pGlobalHeap,
              v17);
        }
        v5[2457].pProxy.pObject = 0i64;
        if ( v7 )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v7->vfptr);
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v3->FocusGroupsCnt );
  }
}

// File Line: 4667
// RVA: 0x8E7280
char __fastcall Scaleform::GFx::MovieImpl::IsFocused(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::InteractiveObject *v2; // r14
  Scaleform::GFx::MovieImpl *v3; // rbp
  __int64 v4; // rdi
  Scaleform::GFx::Sprite *v5; // rbx
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::Sprite *v8; // [rsp+60h] [rbp+18h]

  v2 = ch;
  v3 = this;
  v4 = 0i64;
  if ( !this->FocusGroupsCnt )
    return 0;
  while ( 1 )
  {
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v3->FocusGroups[v4].LastFocused,
      &result);
    v5 = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      v5 = result.pObject;
    }
    v8 = v5;
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v5->vfptr);
    if ( v5 == (Scaleform::GFx::Sprite *)v2 )
      break;
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= v3->FocusGroupsCnt )
      return 0;
  }
  return 1;
}

// File Line: 4678
// RVA: 0x8B3D90
void __fastcall Scaleform::GFx::MovieImpl::AddTopmostLevelCharacter(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::GFx::InteractiveObject *v2; // r15
  Scaleform::GFx::MovieImpl *v3; // r12
  unsigned __int8 v4; // al
  __int64 v5; // rax
  unsigned __int64 v6; // rsi
  void *v7; // rax
  void *v8; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // rdi
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v12; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *v13; // r14
  unsigned __int64 v14; // r13
  unsigned __int64 v15; // r8
  Scaleform::GFx::AS3::Instances::fl::XML *v16; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML *i; // rdi
  unsigned __int64 v18; // rbx
  unsigned __int64 v19; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v20; // rcx
  signed __int64 v21; // r9
  unsigned __int64 v22; // rdx
  signed __int64 v23; // rcx
  __int64 v24; // rax
  signed int v25; // ebx
  signed __int64 v26; // rcx
  __int64 v27; // rax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *v28; // rdi
  unsigned __int64 v29; // r14
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v30; // rcx
  signed __int64 v31; // rbx
  unsigned __int64 v32; // r8
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v33; // rcx
  Scaleform::Render::TreeNode *v34; // rcx
  bool v35; // zf
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v36; // [rsp+30h] [rbp-40h]
  void *v37; // [rsp+48h] [rbp-28h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v38; // [rsp+50h] [rbp-20h]
  void *pheapAddr; // [rsp+68h] [rbp-8h]
  Scaleform::Ptr<Scaleform::Render::TreeNode> result; // [rsp+B8h] [rbp+48h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v41; // [rsp+C0h] [rbp+50h]
  Scaleform::GFx::InteractiveObject *v42; // [rsp+C8h] [rbp+58h]

  v2 = pch;
  v3 = this;
  if ( (pch->Flags >> 10) & 1 )
  {
    v4 = pch->AvmObjOffset;
    if ( v4 )
    {
      v5 = ((__int64 (__cdecl *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&pch->vfptr + 4 * v4))[2].__vecDelDtor)((char *)pch + 4 * v4);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 248i64))(v5) )
        return;
    }
  }
  v6 = 0i64;
  if ( !v3->TopmostLevelCharacters.Data.Size )
    goto LABEL_47;
  v7 = (void *)((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))v3->vfptr[48].__vecDelDtor)(v3);
  v41 = &v38;
  v38.Data = 0i64;
  v38.Size = 0i64;
  v38.Policy.Capacity = 0i64;
  pheapAddr = v7;
  v8 = (void *)((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))v3->vfptr[48].__vecDelDtor)(v3);
  v41 = &v36;
  v36.Data = 0i64;
  v36.Size = 0i64;
  v36.Policy.Capacity = 0i64;
  v37 = v8;
  v9 = (Scaleform::GFx::AS3::Instances::fl::XML *)v2;
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
      v12->pObject = v9;
    v13 = v9;
    v9 = (Scaleform::GFx::AS3::Instances::fl::XML *)v9->Text.pNode;
  }
  while ( v9 );
  v14 = v3->TopmostLevelCharacters.Data.Size;
  if ( !v14 )
  {
LABEL_46:
    v41 = &v36;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v36.Data);
    v41 = &v38;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v38.Data);
LABEL_47:
    ++v2->RefCount;
    v42 = v2;
    v28 = &v3->TopmostLevelCharacters;
    v29 = v3->TopmostLevelCharacters.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&v3->TopmostLevelCharacters,
      &v3->TopmostLevelCharacters,
      v29 + 1);
    if ( v29 + 1 > v29 )
    {
      v30 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&v28->Data.Data[v29];
      v41 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&v28->Data.Data[v29];
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
    v32 = v3->TopmostLevelCharacters.Data.Size;
    if ( v6 < v32 - 1 )
      memmove(&v28->Data.Data[v6 + 1], &v28->Data.Data[v6], 8 * (v32 - v6) - 8);
    v33 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&v28->Data.Data[v6];
    v41 = v33;
    if ( v33 )
    {
      ++v2->RefCount;
      v33->Data = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)v2;
    }
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v2->vfptr);
    Scaleform::GFx::DisplayObjectBase::SetIndirectTransform(
      (Scaleform::GFx::DisplayObjectBase *)&v2->vfptr,
      &result,
      (Scaleform::Render::TreeNode *)&v3->pTopMostRoot.pObject->0);
    if ( result.pObject )
      Scaleform::Render::TreeContainer::Insert(v3->pTopMostRoot.pObject, v6, result.pObject);
    v34 = result.pObject;
    if ( result.pObject )
    {
      v35 = result.pObject->RefCount-- == 1;
      if ( v35 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v34->0);
    }
    return;
  }
  v15 = v36.Size;
  while ( v3->TopmostLevelCharacters.Data.Data[v6].pObject != v2 )
  {
    if ( v15 && v36.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v36.Data )
      {
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v36.Data = 0i64;
      }
      v36.Policy.Capacity = 0i64;
    }
    v15 = 0i64;
    v36.Size = 0i64;
    v16 = 0i64;
    for ( i = (Scaleform::GFx::AS3::Instances::fl::XML *)v3->TopmostLevelCharacters.Data.Data[v6].pObject;
          i;
          i = (Scaleform::GFx::AS3::Instances::fl::XML *)i->Text.pNode )
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
        goto LABEL_30;
      }
LABEL_30:
      v15 = v18;
      v36.Size = v18;
      v20 = &v36.Data[v18 - 1];
      if ( v20 )
      {
        v20->pObject = i;
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
      v23 = (signed __int64)v16 + 4 * *((unsigned __int8 *)&v16[1].RefCount + 5);
      v24 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v23 + 16i64))(v23);
      v25 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v24 + 240i64))(v24);
      v26 = (signed __int64)v13 + 4 * *((unsigned __int8 *)&v13[1].RefCount + 5);
      v27 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v26 + 16i64))(v26);
      if ( v25 > (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v27 + 240i64))(v27) )
        goto LABEL_46;
      v15 = v36.Size;
    }
    if ( ++v6 >= v14 )
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
void __fastcall Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::DisplayObjectBase *pch)
{
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rbx
  Scaleform::GFx::DisplayObjectBase *v4; // rsi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *v5; // rdi
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v6; // rax
  Scaleform::RefCountNTSImpl *v7; // rcx

  v2 = this->TopmostLevelCharacters.Data.Size;
  v3 = 0i64;
  v4 = pch;
  if ( v2 )
  {
    v5 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&this->TopmostLevelCharacters;
    v6 = this->TopmostLevelCharacters.Data.Data;
    while ( (Scaleform::GFx::DisplayObjectBase *)v6->pObject != pch )
    {
      ++v3;
      ++v6;
      if ( v3 >= v2 )
        return;
    }
    Scaleform::Render::TreeContainer::Remove(this->pTopMostRoot.pObject, v3, 1ui64);
    Scaleform::GFx::DisplayObjectBase::RemoveIndirectTransform(v4, 1);
    if ( v5->Size == 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        v5,
        v5,
        0i64);
    }
    else
    {
      v7 = (Scaleform::RefCountNTSImpl *)&v5->Data[v3].pObject->vfptr;
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
      memmove(&v5->Data[v3], &v5->Data[v3 + 1], 8 * (v5->Size - v3) - 8);
      --v5->Size;
    }
  }
}

// File Line: 4805
// RVA: 0x8D6C70
bool __fastcall Scaleform::GFx::MovieImpl::GetDirtyFlag(Scaleform::GFx::MovieImpl *this, bool doReset)
{
  bool v2; // di
  Scaleform::GFx::MovieImpl *v3; // rbx
  bool result; // al

  v2 = doReset;
  v3 = this;
  if ( (this->Flags >> 10) & 1
    || (result = Scaleform::Render::ContextImpl::Context::HasChanges(&this->RenderContext)) != 0 )
  {
    result = 1;
  }
  if ( v2 )
    v3->Flags &= 0xFFFFFBFF;
  return result;
}

// File Line: 4813
// RVA: 0x8DE9B0
Scaleform::Render::Text::Allocator *__fastcall Scaleform::GFx::MovieImpl::GetTextAllocator(Scaleform::GFx::MovieImpl *this)
{
  return (Scaleform::Render::Text::Allocator *)((__int64 (*)(void))this->pASMovieRoot.pObject->vfptr[60].__vecDelDtor)();
}

// File Line: 4818
// RVA: 0x8D4A60
unsigned __int64 __fastcall Scaleform::GFx::MovieImpl::GetASTimerMs(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl *v1; // rsi
  Scaleform::GFx::TestStream *v2; // rdi
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rbx
  unsigned __int64 result; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rax
  Scaleform::LongFormatter v8; // [rsp+30h] [rbp-68h]
  Scaleform::String v9; // [rsp+A0h] [rbp+8h]
  Scaleform::Render::RenderBuffer *v10; // [rsp+A8h] [rbp+10h]

  v1 = this;
  v2 = Scaleform::GFx::StateBag::GetTestStream(
         (Scaleform::GFx::StateBag *)&this->vfptr,
         (Scaleform::Ptr<Scaleform::GFx::TestStream> *)&v10)->pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  if ( v2 )
  {
    if ( v2->TestStatus )
    {
      Scaleform::String::String(&v9);
      ((void (__fastcall *)(Scaleform::GFx::TestStream *, const char *, Scaleform::String *))v2->vfptr[1].__vecDelDtor)(
        v2,
        "timer",
        &v9);
      result = strtoui64((const char *)((v9.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), 0i64, 10);
      v6 = result;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v9.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      {
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        result = v6;
      }
    }
    else
    {
      v3 = Scaleform::Timer::GetTicks();
      v4 = ((unsigned __int64)((v3 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)
                             + ((unsigned __int64)(v3 - (v3 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)) >> 9)
         - v1->StartTickMs;
      Scaleform::LongFormatter::LongFormatter(&v8, v4);
      Scaleform::LongFormatter::Convert(&v8);
      ((void (__fastcall *)(Scaleform::GFx::TestStream *, const char *, char *))v2->vfptr[2].__vecDelDtor)(
        v2,
        "timer",
        v8.ValueStr);
      v8.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
      Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v8.vfptr);
      result = v4;
    }
  }
  else
  {
    v7 = Scaleform::Timer::GetTicks();
    result = ((unsigned __int64)((v7 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)
                               + ((unsigned __int64)(v7 - (v7 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)) >> 9)
           - v1->StartTickMs;
  }
  return result;
}

// File Line: 4844
// RVA: 0x914180
Scaleform::Render::Point<float> *__fastcall Scaleform::GFx::MovieImpl::TranslateToScreen(Scaleform::GFx::MovieImpl *this, Scaleform::Render::Point<float> *result, Scaleform::Render::Point<float> *p, Scaleform::Render::Matrix2x4<float> *puserMatrix)
{
  Scaleform::GFx::InteractiveObject *v4; // rdi
  float *v5; // rbx
  float *v6; // rsi
  Scaleform::Render::Point<float> *v7; // r14
  Scaleform::Render::Point<float> *v8; // rbp
  Scaleform::GFx::DisplayObjectBase *v9; // rcx
  float *v10; // rax
  __int64 v11; // kr00_8
  float v12; // xmm3_4
  float v13; // xmm10_4
  float v14; // xmm4_4
  float v15; // xmm11_4
  float v16; // xmm9_4
  float v17; // xmm10_4
  float v18; // xmm12_4
  float v19; // xmm2_4
  float v20; // xmm13_4
  float *v21; // rax
  float v22; // xmm2_4
  float v23; // xmm14_4
  float v24; // xmm7_4
  float v25; // xmm3_4
  float v26; // xmm15_4
  float v27; // xmm8_4
  float v28; // xmm5_4
  float v29; // xmm7_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm3_4
  float v36; // xmm4_4
  float v37; // ST20_4
  float v38; // xmm0_4
  float v39; // xmm4_4
  float v40; // xmm15_4
  float v41; // xmm2_4
  float v42; // xmm0_4
  float v43; // xmm14_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm3_4
  float v47; // xmm5_4
  Scaleform::Render::Point<float> *v48; // rax
  float v49; // xmm9_4
  float v50; // xmm5_4
  float v51; // xmm4_4
  float v52; // xmm10_4
  float v53; // xmm0_4
  float v54; // xmm13_4
  float v55; // xmm0_4
  float v56; // xmm3_4
  float v57; // xmm2_4
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-E8h]
  float v59; // [rsp+120h] [rbp+8h]
  float v60; // [rsp+130h] [rbp+18h]

  v4 = this->pMainMovie;
  v5 = (float *)this;
  v6 = (float *)puserMatrix;
  v7 = p;
  v8 = result;
  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  v9 = v4->pParentChar;
  if ( v9 )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v9, &pmat);
    v10 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v4->vfptr[2].__vecDelDtor)(v4);
    v11 = *(_QWORD *)&pmat.M[0][0];
    v12 = pmat.M[1][0];
    v13 = pmat.M[0][0];
    v14 = pmat.M[1][1];
    v15 = (float)(pmat.M[0][1] * v10[4]) + (float)(pmat.M[0][0] * *v10);
    pmat.M[0][0] = (float)(pmat.M[0][1] * v10[4]) + (float)(pmat.M[0][0] * *v10);
    v16 = (float)(pmat.M[1][1] * v10[4]) + (float)(pmat.M[1][0] * *v10);
    pmat.M[1][0] = (float)(pmat.M[1][1] * v10[4]) + (float)(pmat.M[1][0] * *v10);
    v17 = (float)(v13 * v10[1]) + (float)(pmat.M[0][1] * v10[5]);
    *(_QWORD *)&pmat.M[0][1] = LODWORD(v17);
    v18 = (float)(v12 * v10[1]) + (float)(pmat.M[1][1] * v10[5]);
    *(_QWORD *)&pmat.M[1][1] = LODWORD(v18);
    v19 = (float)(*((float *)&v11 + 1) * v10[7]) + (float)(*(float *)&v11 * v10[3]);
    v20 = pmat.M[0][3] + v19;
    pmat.M[0][3] = pmat.M[0][3] + v19;
    v59 = pmat.M[1][3] + (float)((float)(v14 * v10[7]) + (float)(v12 * v10[3]));
  }
  else
  {
    v21 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v4->vfptr[2].__vecDelDtor)(v4);
    v15 = *v21;
    pmat.M[0][0] = *v21;
    v17 = v21[1];
    *(_QWORD *)&pmat.M[0][1] = *(_QWORD *)(v21 + 1);
    v20 = v21[3];
    pmat.M[0][3] = v21[3];
    v16 = v21[4];
    pmat.M[1][0] = v21[4];
    v18 = v21[5];
    *(_QWORD *)&pmat.M[1][1] = *(_QWORD *)(v21 + 5);
    v59 = v21[7];
  }
  v22 = v5[68];
  v23 = v5[69];
  v24 = v5[71];
  v25 = v5[72];
  v26 = v5[73];
  v27 = v5[75];
  if ( v6 )
  {
    v28 = v5[68];
    v29 = v5[72];
    v30 = v6[4];
    v31 = (float)(*v6 * v22) + (float)(v30 * v23);
    v32 = v6[1];
    v33 = v32;
    v34 = (float)(*v6 * v29) + (float)(v30 * v26);
    v35 = v6[3];
    v60 = v31;
    v36 = v6[5];
    v37 = v34;
    v38 = v36;
    v39 = v36 * v26;
    v40 = v32 * v29;
    v41 = v6[7];
    v42 = v38 * v23;
    v43 = v33 * v28;
    v44 = v35;
    v26 = v40 + v39;
    v23 = v43 + v42;
    v45 = v41;
    v46 = (float)(v35 * v29) + (float)(v41 * v5[73]);
    v22 = v60;
    v27 = v5[75] + v46;
    v25 = v37;
    v24 = v5[71] + (float)((float)(v44 * v28) + (float)(v45 * v5[69]));
  }
  v47 = v16;
  v48 = v8;
  v49 = (float)(v16 * v26) + (float)(v15 * v25);
  v50 = (float)(v47 * v23) + (float)(v15 * v22);
  v51 = (float)(v17 * v22) + (float)(v18 * v23);
  v52 = (float)(v17 * v25) + (float)(v18 * v26);
  v53 = v20;
  v54 = v20 * v25;
  v55 = v53 * v22;
  v56 = v7->x * 20.0;
  v57 = v7->y * 20.0;
  v8->y = (float)((float)(v56 * v49) + (float)(v57 * v52)) + (float)(v27 + (float)(v54 + (float)(v59 * v26)));
  v8->x = (float)((float)(v56 * v50) + (float)(v57 * v51)) + (float)(v24 + (float)((float)(v59 * v23) + v55));
  return v48;
}

// File Line: 4855
// RVA: 0x914590
Scaleform::Render::Rect<float> *__usercall Scaleform::GFx::MovieImpl::TranslateToScreen@<rax>(Scaleform::GFx::MovieImpl *this@<rcx>, Scaleform::Render::Rect<float> *result@<rdx>, Scaleform::Render::Rect<float> *r@<r8>, Scaleform::Render::Matrix2x4<float> *puserMatrix@<r9>, __int128 a5@<xmm6>)
{
  float *v5; // rbx
  float *v6; // rsi
  Scaleform::Render::Rect<float> *v7; // r14
  Scaleform::Render::Rect<float> *v8; // r15
  Scaleform::GFx::InteractiveObject *v9; // rdi
  Scaleform::GFx::DisplayObjectBase *v10; // rcx
  float *v11; // rax
  __int64 v12; // kr00_8
  __int64 v13; // kr08_8
  float v14; // xmm12_4
  float v15; // xmm13_4
  float v16; // xmm14_4
  float v17; // xmm0_4
  float v18; // xmm15_4
  float v19; // xmm15_4
  float v20; // xmm0_4
  float *v21; // rax
  float v22; // xmm10_4
  float v23; // xmm8_4
  float v24; // xmm3_4
  float v25; // xmm11_4
  float v26; // xmm9_4
  float v27; // xmm4_4
  float v28; // xmm7_4
  float v29; // xmm5_4
  float v30; // xmm1_4
  float v31; // xmm5_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  Scaleform::Render::Rect<float> ra; // [rsp+20h] [rbp-C8h]
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-B8h]
  Scaleform::Render::Matrix2x4<float> v39; // [rsp+50h] [rbp-98h]
  __int128 v40; // [rsp+100h] [rbp+18h]

  v5 = (float *)this;
  v6 = (float *)puserMatrix;
  v7 = r;
  v8 = result;
  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  v9 = this->pMainMovie;
  v10 = v9->pParentChar;
  if ( v10 )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v10, &pmat);
    v11 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v9->vfptr[2].__vecDelDtor)(v9);
    v12 = *(_QWORD *)&pmat.M[0][0];
    v13 = *(_QWORD *)&pmat.M[1][0];
    v14 = (float)(pmat.M[0][0] * *v11) + (float)(pmat.M[0][1] * v11[4]);
    pmat.M[0][0] = (float)(pmat.M[0][0] * *v11) + (float)(pmat.M[0][1] * v11[4]);
    v15 = (float)(pmat.M[1][1] * v11[4]) + (float)(pmat.M[1][0] * *v11);
    pmat.M[1][0] = (float)(pmat.M[1][1] * v11[4]) + (float)(pmat.M[1][0] * *v11);
    v16 = (float)(pmat.M[0][1] * v11[5]) + (float)(*(float *)&v12 * v11[1]);
    pmat.M[0][1] = (float)(pmat.M[0][1] * v11[5]) + (float)(*(float *)&v12 * v11[1]);
    v17 = pmat.M[1][1] * v11[5];
    v18 = *(float *)&v13 * v11[1];
    pmat.M[0][2] = 0.0;
    v19 = v18 + v17;
    *(_QWORD *)&pmat.M[1][1] = LODWORD(v19);
    pmat.M[0][3] = pmat.M[0][3] + (float)((float)(*((float *)&v12 + 1) * v11[7]) + (float)(*(float *)&v12 * v11[3]));
    v20 = pmat.M[1][3] + (float)((float)(*((float *)&v13 + 1) * v11[7]) + (float)(*(float *)&v13 * v11[3]));
  }
  else
  {
    v21 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v9->vfptr[2].__vecDelDtor)(v9);
    v14 = *v21;
    pmat.M[0][0] = *v21;
    v16 = v21[1];
    *(_QWORD *)&pmat.M[0][1] = *(_QWORD *)(v21 + 1);
    pmat.M[0][3] = v21[3];
    v15 = v21[4];
    pmat.M[1][0] = v21[4];
    v19 = v21[5];
    *(_QWORD *)&pmat.M[1][1] = *(_QWORD *)(v21 + 5);
    v20 = v21[7];
  }
  v22 = v5[68];
  v23 = v5[69];
  v24 = v5[71];
  v25 = v5[72];
  v26 = v5[73];
  v27 = v5[75];
  pmat.M[1][3] = v20;
  if ( v6 )
  {
    v40 = a5;
    v28 = v25;
    v29 = v22;
    v30 = v22;
    v22 = (float)(v22 * *v6) + (float)(v23 * v6[4]);
    v25 = (float)(v25 * *v6) + (float)(v26 * v6[4]);
    v31 = (float)(v29 * v6[3]) + (float)(v23 * v6[7]);
    v23 = (float)(v30 * v6[1]) + (float)(v23 * v6[5]);
    v27 = v5[75] + (float)((float)(v28 * v6[3]) + (float)(v26 * v6[7]));
    v24 = v24 + v31;
    v26 = (float)(v28 * v6[1]) + (float)(v26 * v6[5]);
  }
  v39.M[0][0] = (float)(v23 * v15) + (float)(v22 * v14);
  v39.M[1][0] = (float)(v26 * v15) + (float)(v25 * v14);
  *(_QWORD *)&v39.M[0][1] = COERCE_UNSIGNED_INT((float)(v23 * v19) + (float)(v22 * v16));
  v32 = v7->x2;
  v33 = v7->x1;
  *(_QWORD *)&v39.M[1][1] = COERCE_UNSIGNED_INT((float)(v26 * v19) + (float)(v25 * v16));
  ra.x1 = v33 * 20.0;
  v34 = v7->y1;
  v39.M[0][3] = v24 + (float)((float)(v23 * pmat.M[1][3]) + (float)(v22 * pmat.M[0][3]));
  ra.y1 = v34 * 20.0;
  v35 = v7->y2;
  v39.M[1][3] = v27 + (float)((float)(v26 * pmat.M[1][3]) + (float)(v25 * pmat.M[0][3]));
  ra.y2 = v35 * 20.0;
  ra.x2 = v32 * 20.0;
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v39, v8, &ra);
  return v8;
}

// File Line: 4872
// RVA: 0x913DA0
__int64 __fastcall Scaleform::GFx::MovieImpl::TranslateLocalToScreen(Scaleform::GFx::MovieImpl *this, const char *pathToMovieClip, Scaleform::Render::Point<float> *pt, Scaleform::Render::Point<float> *presPt, Scaleform::Render::Matrix2x4<float> *userMatrix)
{
  Scaleform::Render::Point<float> *v5; // rdi
  Scaleform::Render::Point<float> *v6; // rsi
  float *v7; // rbx
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
  __int128 v19; // [rsp+30h] [rbp-D8h]
  __m128 v20; // [rsp+40h] [rbp-C8h]
  char v21; // [rsp+50h] [rbp-B8h]
  __int64 v22; // [rsp+60h] [rbp-A8h]
  unsigned int v23; // [rsp+68h] [rbp-A0h]
  __int64 v24; // [rsp+70h] [rbp-98h]

  v5 = presPt;
  v6 = pt;
  v7 = (float *)this;
  v22 = 0i64;
  v23 = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, char *, const char *))this->pASMovieRoot.pObject->vfptr[49].__vecDelDtor)(
         this->pASMovieRoot.pObject,
         &v21,
         pathToMovieClip)
    && (v19 = _xmm,
        v20 = _xmm,
        (*(unsigned __int8 (__fastcall **)(__int64, __int64, __int128 *))(*(_QWORD *)v22 + 232i64))(v22, v24, &v19)) )
  {
    v8 = v7[68] * 20.0;
    v9 = v7[69] * 20.0;
    v10 = v7[71] * 20.0;
    v11 = v7[72] * 20.0;
    v12 = v7[73] * 20.0;
    v13 = v7[75] * 20.0;
    if ( userMatrix )
    {
      v14 = v7[68] * 20.0;
      v15 = v7[72] * 20.0;
      v8 = (float)(v8 * userMatrix->M[0][0]) + (float)(v9 * userMatrix->M[1][0]);
      v11 = (float)(v11 * userMatrix->M[0][0]) + (float)(v12 * userMatrix->M[1][0]);
      v9 = (float)(v14 * userMatrix->M[0][1]) + (float)(v9 * userMatrix->M[1][1]);
      v12 = (float)(v15 * userMatrix->M[0][1]) + (float)(v12 * userMatrix->M[1][1]);
      v10 = v10 + (float)((float)(v14 * userMatrix->M[0][3]) + (float)((float)(v7[69] * 20.0) * userMatrix->M[1][3]));
      v13 = v13 + (float)((float)(v15 * userMatrix->M[0][3]) + (float)((float)(v7[73] * 20.0) * userMatrix->M[1][3]));
    }
    v16 = (float)((float)((float)((float)(v11 * *(float *)&v19) + (float)(v12 * v20.m128_f32[0])) * v6->x)
                + (float)((float)((float)(v11 * *((float *)&v19 + 1)) + (float)(v12 * v20.m128_f32[1])) * v6->y))
        + (float)(v13 + (float)((float)(v11 * *((float *)&v19 + 3)) + (float)(v12 * v20.m128_f32[3])));
    v5->x = (float)((float)((float)((float)(v8 * *(float *)&v19) + (float)(v9 * v20.m128_f32[0])) * v6->x)
                  + (float)((float)((float)(v8 * *((float *)&v19 + 1)) + (float)(v9 * v20.m128_f32[1])) * v6->y))
          + (float)(v10 + (float)((float)(v8 * *((float *)&v19 + 3)) + (float)(v9 * v20.m128_f32[3])));
    v5->y = v16;
    v17 = 1;
  }
  else
  {
    v17 = 0;
  }
  if ( (v23 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v22 + 16i64))(v22, &v21, v24);
    v22 = 0i64;
  }
  return v17;
}

// File Line: 4899
// RVA: 0x8DE5D0
void __fastcall Scaleform::GFx::MovieImpl::GetStats(Scaleform::GFx::MovieImpl *this, Scaleform::StatBag *pbag, __int64 reset)
{
  Scaleform::AmpStats *v3; // rcx

  v3 = this->AdvanceStats.pObject;
  if ( v3 )
    ((void (__fastcall *)(Scaleform::AmpStats *, Scaleform::StatBag *, __int64))v3->vfptr[5].__vecDelDtor)(
      v3,
      pbag,
      reset);
}

// File Line: 4926
// RVA: 0x8F0CD0
void __fastcall Scaleform::GFx::MovieImpl::PrintObjectsReport(Scaleform::GFx::MovieImpl *this, __int64 flags, Scaleform::Log *log, const char *swfName, Scaleform::Ptr<Scaleform::AmpMovieObjectDesc> *root, Scaleform::MemoryHeap *heap)
{
  Scaleform::GFx::MovieImpl *v6; // rdi
  Scaleform::AmpMovieObjectDesc *v7; // rdi

  v6 = this;
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, __int64, Scaleform::Log *, const char *))this->pASMovieRoot.pObject->vfptr[32].__vecDelDtor)(
    this->pASMovieRoot.pObject,
    flags,
    log,
    swfName);
  if ( root )
  {
    v7 = (Scaleform::AmpMovieObjectDesc *)v6->pASMovieRoot.pObject->vfptr[34].__vecDelDtor(
                                            (Scaleform::RefCountImplCore *)&v6->pASMovieRoot.pObject->vfptr,
                                            (unsigned int)heap);
    if ( root->pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)root->pObject);
    root->pObject = v7;
  }
}

// File Line: 4936
// RVA: 0x908630
char __usercall Scaleform::GFx::MovieImpl::SetLevelMovie@<al>(Scaleform::GFx::MovieImpl *this@<rcx>, int level@<edx>, Scaleform::GFx::DisplayObjContainer *psprite@<r8>, float a4@<xmm0>)
{
  Scaleform::GFx::DisplayObjContainer *v4; // r15
  int v5; // esi
  Scaleform::GFx::MovieImpl *v6; // r14
  unsigned int v7; // ecx
  unsigned __int64 v8; // rdx
  __int64 v9; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v10; // r8
  unsigned __int64 v12; // rdi
  unsigned __int64 v13; // r13
  signed __int64 v14; // rax
  signed __int64 v15; // rbx
  unsigned __int64 v16; // r8
  signed __int64 v17; // rdi
  __int64 v18; // rax
  Scaleform::GFx::MovieDefImpl *v19; // rdi
  Scaleform::GFx::MovieDefImpl *v20; // rbx
  Scaleform::GFx::ResourceLibBase *v21; // rcx
  Scaleform::AmpStats *v22; // rsi
  Scaleform::RefCountImplCoreVtbl *v23; // rbx
  __int64 v24; // rax
  Scaleform::GFx::MovieDefImpl *v25; // rax
  Scaleform::GFx::StateBagImpl *v26; // rbx
  Scaleform::GFx::StateBagImpl *v27; // rdi
  Scaleform::Render::RenderBuffer *v28; // rcx
  __int64 v29; // rax
  __int64 v30; // rsi
  int v31; // [rsp+38h] [rbp-70h]
  int v32; // [rsp+3Ch] [rbp-6Ch]
  __int64 v33; // [rsp+40h] [rbp-68h]
  int v34; // [rsp+48h] [rbp-60h]
  int v35; // [rsp+4Ch] [rbp-5Ch]
  int v36; // [rsp+50h] [rbp-58h]
  __int64 v37; // [rsp+54h] [rbp-54h]
  __int64 v38; // [rsp+5Ch] [rbp-4Ch]
  int v39; // [rsp+64h] [rbp-44h]
  int v40; // [rsp+68h] [rbp-40h]

  v4 = psprite;
  v5 = level;
  v6 = this;
  v7 = 0;
  v8 = v6->MovieLevels.Data.Size;
  if ( v8 )
  {
    v9 = 0i64;
    v10 = v6->MovieLevels.Data.Data;
    while ( v10[v9].Level < v5 )
    {
      v9 = ++v7;
      if ( v7 >= v8 )
        goto LABEL_8;
    }
    if ( v10[v7].Level == v5 )
      return 0;
  }
LABEL_8:
  v6->Flags |= 0x100u;
  if ( v4 )
    ++v4->RefCount;
  v12 = v7;
  v13 = v6->MovieLevels.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy> *)&v6->MovieLevels.Data.Data,
    &v6->MovieLevels,
    v13 + 1);
  if ( v13 + 1 > v13 )
  {
    v14 = (signed __int64)&v6->MovieLevels.Data.Data[v13];
    v15 = 1i64;
    do
    {
      if ( v14 )
        *(_QWORD *)(v14 + 8) = 0i64;
      v14 += 16i64;
      --v15;
    }
    while ( v15 );
  }
  v16 = v6->MovieLevels.Data.Size;
  if ( v12 < v16 - 1 )
    memmove(&v6->MovieLevels.Data.Data[v12 + 1], &v6->MovieLevels.Data.Data[v12], 16 * (v16 - v12 - 1));
  v17 = (signed __int64)&v6->MovieLevels.Data.Data[v12];
  if ( v17 )
  {
    *(_DWORD *)v17 = v5;
    if ( v4 )
      ++v4->RefCount;
    *(_QWORD *)(v17 + 8) = v4;
  }
  v4->vfptr[122].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, v5);
  if ( !v5 )
  {
    v6->pMainMovie = (Scaleform::GFx::InteractiveObject *)&v4->vfptr;
    v18 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v4->vfptr[66].__vecDelDtor)(v4);
    v19 = (Scaleform::GFx::MovieDefImpl *)v18;
    if ( v18 )
      _InterlockedExchangeAdd((volatile signed __int32 *)(v18 + 8), 1u);
    v20 = v6->pMainMovieDef.pObject;
    if ( v20 && !_InterlockedDecrement(&v20->RefCount.Value) )
    {
      v21 = v20->pLib;
      if ( v21 )
      {
        v21->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, (unsigned int)v20);
        v20->pLib = 0i64;
      }
      v20->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v20->vfptr, 1u);
    }
    v6->pMainMovieDef.pObject = v19;
    if ( v19 )
    {
      v22 = v6->AdvanceStats.pObject;
      if ( v22 )
      {
        v23 = v22->vfptr;
        v24 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v19->vfptr[3].__vecDelDtor)(v19);
        v23[7].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, v24);
      }
    }
    v25 = v6->pMainMovieDef.pObject;
    v26 = v25->pStateBag.pObject;
    v27 = v6->pStateBag.pObject;
    if ( v26 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v25->pStateBag.pObject);
    v28 = (Scaleform::Render::RenderBuffer *)v27->pDelegate.pObject;
    if ( v28 )
      Scaleform::RefCountImpl::Release(v28);
    v27->pDelegate.pObject = v26;
    v29 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))v6->vfptr[1].__vecDelDtor)(v6);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v29 + 72i64))(v29);
    v6->FrameTime = 1.0 / a4;
    if ( !(v6->Flags & 1) )
    {
      v30 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v4->vfptr[66].__vecDelDtor)(v4);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v30 + 56i64))(v30);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v30 + 48i64))(v30);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v30 + 56i64))(v30);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v30 + 48i64))(v30);
      v31 = (signed int)a4;
      v32 = (signed int)a4;
      v33 = 0i64;
      v34 = (signed int)a4;
      v35 = (signed int)a4;
      v38 = 0i64;
      v37 = 0i64;
      v36 = 0;
      v40 = 1065353216;
      v39 = 1065353216;
      v6->vfptr[12].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)&v31);
    }
  }
  v6->Flags |= 0x80u;
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
  return 1;
}

// File Line: 4990
// RVA: 0x8C2750
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::MovieImpl::CreateNewInstanceName(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::MovieImpl *v3; // rdi
  Scaleform::GFx::ASStringManager *v4; // rax
  char pstr; // [rsp+28h] [rbp-460h]
  __int64 v7; // [rsp+29h] [rbp-45Fh]
  __int64 v8; // [rsp+31h] [rbp-457h]
  __int64 v9; // [rsp+39h] [rbp-44Fh]
  __int64 v10; // [rsp+41h] [rbp-447h]
  __int64 v11; // [rsp+49h] [rbp-43Fh]
  int v12; // [rsp+51h] [rbp-437h]
  __int16 v13; // [rsp+55h] [rbp-433h]
  char v14; // [rsp+57h] [rbp-431h]
  Scaleform::MsgFormat::Sink r; // [rsp+58h] [rbp-430h]
  __int64 v16; // [rsp+70h] [rbp-418h]
  Scaleform::MsgFormat v17; // [rsp+80h] [rbp-408h]

  v16 = -2i64;
  v2 = result;
  v3 = this;
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
  r.Type = 2;
  r.SinkData.pStr = (Scaleform::String *)&pstr;
  r.SinkData.DataPtr.Size = 48i64;
  Scaleform::MsgFormat::MsgFormat(&v17, &r);
  Scaleform::MsgFormat::Parse(&v17, "instance{0}");
  Scaleform::MsgFormat::FormatD1<unsigned long>(&v17, &v3->InstanceNameCount);
  Scaleform::MsgFormat::FinishFormatD(&v17);
  Scaleform::MsgFormat::~MsgFormat(&v17);
  v4 = (Scaleform::GFx::ASStringManager *)((__int64 (__cdecl *)(Scaleform::GFx::ASMovieRootBase *))v3->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)(v3->pASMovieRoot.pObject);
  Scaleform::GFx::ASStringManager::CreateString(v4, v2, &pstr);
  return v2;
}

// File Line: 5000
// RVA: 0x8D9D50
Scaleform::Ptr<Scaleform::GFx::ImageResource> *__fastcall Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(Scaleform::GFx::MovieImpl *this, Scaleform::Ptr<Scaleform::GFx::ImageResource> *result, Scaleform::GFx::MovieDefImpl *md, const char *linkageId)
{
  const char *v4; // rdi
  Scaleform::GFx::MovieDefImpl *v5; // r15
  Scaleform::Ptr<Scaleform::GFx::ImageResource> *v6; // rsi
  Scaleform::GFx::MovieImpl *v7; // r13
  Scaleform::String *v8; // rax
  bool v9; // r14
  Scaleform::GFx::StateBagImpl *v10; // r14
  Scaleform::GFx::StateBag *v11; // r14
  __int64 v12; // r15
  Scaleform::GFx::ImageCreator *v13; // r12
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *v14; // rsi
  __int64 *v15; // rdi
  Scaleform::Ptr<Scaleform::Log> *v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rax
  Scaleform::Render::Image *v19; // rdi
  Scaleform::GFx::ImageResource *v20; // rax
  char v21; // al
  Scaleform::GFx::MovieDefImpl *v22; // r14
  Scaleform::GFx::MovieDefRootNode *i; // rdi
  signed __int64 v24; // rax
  Scaleform::GFx::MovieDefImpl *v25; // rcx
  bool v26; // di
  Scaleform::GFx::Resource *v27; // rdi
  Scaleform::GFx::ResourceLibBase *v28; // rcx
  Scaleform::GFx::Resource *v29; // rcx
  Scaleform::GFx::Resource *v30; // rdi
  Scaleform::GFx::ResourceLibBase *v31; // rcx
  __int64 v32; // rax
  __int64 v33; // rbx
  Scaleform::GFx::ResourceLibBase *v34; // rcx
  Scaleform::GFx::ResourceBindData v36; // [rsp+0h] [rbp-79h]
  Scaleform::String v37; // [rsp+10h] [rbp-69h]
  Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> v38; // [rsp+18h] [rbp-61h]
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> v39; // [rsp+20h] [rbp-59h]
  Scaleform::String v40; // [rsp+28h] [rbp-51h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> resulta; // [rsp+30h] [rbp-49h]
  Scaleform::Ptr<Scaleform::Log> v42; // [rsp+38h] [rbp-41h]
  int v43; // [rsp+40h] [rbp-39h]
  __int64 v44; // [rsp+48h] [rbp-31h]
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
  v4 = linkageId;
  v5 = md;
  v6 = result;
  v7 = this;
  LODWORD(v40.pData) = 0;
  v56 = 0i64;
  if ( !md )
  {
LABEL_59:
    v32 = (__int64)v56;
    v6->pObject = v56;
    LODWORD(v40.pData) = 1;
    if ( v32 && !_InterlockedDecrement((volatile signed __int32 *)(v32 + 8)) )
    {
      v33 = (__int64)v56;
      v34 = v56->pLib;
      if ( v34 )
      {
        v34->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v34->vfptr, (unsigned int)v56);
        *(_QWORD *)(v33 + 16) = 0i64;
      }
      (**(void (__fastcall ***)(__int64, signed __int64))v33)(v33, 1i64);
    }
    return v6;
  }
  Scaleform::String::String(&v40, linkageId);
  v9 = Scaleform::GFx::LoaderImpl::IsProtocolImage(v8, 0i64, 0i64);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v40.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( v9 )
  {
    v10 = v7->pStateBag.pObject;
    if ( v10 )
      v11 = (Scaleform::GFx::StateBag *)&v10->vfptr;
    else
      v11 = 0i64;
    v12 = (__int64)v7->pHeap;
    v51 = v7->pHeap;
    v13 = Scaleform::GFx::StateBag::GetImageCreator(v11, &resulta)->pObject;
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    if ( !v13 )
      goto LABEL_59;
    v43 = 0;
    v44 = v12;
    v45 = 1;
    v46 = 1;
    v47 = 0i64;
    v48 = 0i64;
    v49 = 0i64;
    v50 = 0i64;
    v14 = Scaleform::GFx::StateBag::GetImageFileHandlerRegistry(v11, &v39);
    v15 = (__int64 *)Scaleform::GFx::StateBag::GetFileOpener(v11, &v38);
    v16 = Scaleform::GFx::StateBag::GetLog(v11, &v42);
    v17 = (__int64)v14->pObject;
    v18 = (__int64)v16->pObject;
    v48 = *v15;
    v47 = v18;
    v49 = v17;
    if ( v42.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v42.pObject);
    if ( v38.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v38.pObject);
    if ( v39.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v39.pObject);
    v50 = v7;
    Scaleform::String::String(&v37, pdata);
    v19 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::String *))v13->vfptr[1].__vecDelDtor)(
                                        v13,
                                        &v43,
                                        &v37);
    v54 = v19;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v37.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    if ( v19 )
    {
      v20 = (Scaleform::GFx::ImageResource *)(*(__int64 (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v12 + 80i64))(
                                               v12,
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
  Scaleform::String::String((Scaleform::String *)&resulta, v4);
  if ( (unsigned __int8)Scaleform::GFx::MovieDefImpl::GetExportedResource(v5, &v36, (Scaleform::String *)&resulta, 0i64) )
  {
    v21 = 1;
  }
  else
  {
    v22 = v5;
    for ( i = v7->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
    {
      v24 = (signed __int64)&v7->MovieLevels.Data.Policy;
      if ( v7 == (Scaleform::GFx::MovieImpl *)-112i64 )
        v24 = 0i64;
      if ( i == (Scaleform::GFx::MovieDefRootNode *)v24 )
        break;
      v25 = i->pDefImpl;
      if ( v25 != v5 && (unsigned __int8)Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(v25, v22) )
      {
        if ( (unsigned __int8)Scaleform::GFx::MovieDefImpl::GetExportedResource(
                                i->pDefImpl,
                                &v36,
                                (Scaleform::String *)&resulta,
                                0i64) )
        {
          v21 = 1;
          goto LABEL_38;
        }
        v22 = i->pDefImpl;
      }
    }
    v21 = 0;
LABEL_38:
    v6 = v55;
  }
  v26 = v21 == 0;
  if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)resulta.pObject & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( !v26 )
  {
    if ( (((__int64 (*)(void))v36.pResource.pObject->vfptr->GetResourceTypeCode)() & 0xFF00) == 256 )
    {
      v29 = v36.pResource.pObject;
      if ( v36.pResource.pObject )
        _InterlockedExchangeAdd(&v36.pResource.pObject->RefCount.Value, 1u);
      v56 = (Scaleform::GFx::ImageResource *)v29;
    }
    v30 = v36.pResource.pObject;
    if ( v36.pResource.pObject && !_InterlockedDecrement(&v36.pResource.pObject->RefCount.Value) )
    {
      v31 = v30->pLib;
      if ( v31 )
      {
        v31->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v31->vfptr, (unsigned int)v30);
        v30->pLib = 0i64;
      }
      v30->vfptr->__vecDelDtor(v30, 1u);
    }
LABEL_57:
    v6 = v55;
    if ( v56 )
      _InterlockedExchangeAdd(&v56->RefCount.Value, 1u);
    goto LABEL_59;
  }
  v6->pObject = 0i64;
  LODWORD(v40.pData) = 1;
  v27 = v36.pResource.pObject;
  if ( v36.pResource.pObject && !_InterlockedDecrement(&v36.pResource.pObject->RefCount.Value) )
  {
    v28 = v27->pLib;
    if ( v28 )
    {
      v28->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v28->vfptr, (unsigned int)v27);
      v27->pLib = 0i64;
    }
    v27->vfptr->__vecDelDtor(v27, 1u);
  }
  return v6;
}

// File Line: 5050
// RVA: 0x8FD890
bool __fastcall Scaleform::GFx::MovieImpl::ReadTextData(Scaleform::String *pdata, Scaleform::File *pfile, int *pfileLen, bool urlEncoded)
{
  bool v4; // r14
  int *v5; // rsi
  Scaleform::File *v6; // rdi
  Scaleform::String *v7; // rbp
  int v8; // eax
  char *v9; // rbx
  signed int v10; // eax
  int v11; // eax
  signed __int64 v12; // rcx
  int v13; // eax
  signed __int64 v14; // rcx
  const char *v15; // rdx
  __int64 v16; // r8
  Scaleform::String src; // [rsp+58h] [rbp+10h]

  v4 = urlEncoded;
  v5 = pfileLen;
  v6 = pfile;
  v7 = pdata;
  v8 = ((__int64 (__fastcall *)(Scaleform::File *))pfile->vfptr[6].__vecDelDtor)(pfile);
  *v5 = v8;
  if ( v8 )
  {
    Scaleform::String::String(&src);
    v9 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, *v5, 0i64);
    ((void (__fastcall *)(Scaleform::File *, char *, _QWORD))v6->vfptr[10].__vecDelDtor)(v6, v9, (unsigned int)*v5);
    v10 = *v5;
    if ( *(_WORD *)v9 == -257 )
    {
      v11 = v10 / 2 - 1;
      v12 = 0i64;
      if ( v11 > 0 )
      {
        do
          ++v12;
        while ( v12 < v11 );
      }
      Scaleform::String::AppendString(&src, (const wchar_t *)v9 + 1, v11);
    }
    else if ( *(_WORD *)v9 == -2 )
    {
      v13 = v10 / 2 - 1;
      v14 = 0i64;
      if ( v13 > 0 )
      {
        do
        {
          *(_WORD *)&v9[2 * v14 + 2] = __ROL2__(*(_WORD *)&v9[2 * v14 + 2], 8);
          ++v14;
        }
        while ( v14 < v13 );
      }
      Scaleform::String::AppendString(&src, (const wchar_t *)v9 + 1, v13);
    }
    else
    {
      if ( v10 <= 2 || *v9 != -17 || v9[1] != -69 || v9[2] != -65 )
      {
        v16 = *v5;
        v15 = v9;
      }
      else
      {
        v15 = v9 + 3;
        v16 = v10 - 3;
      }
      Scaleform::String::AppendString(&src, v15, v16);
    }
    if ( v4 )
      Scaleform::GFx::ASUtils::Unescape(
        (const char *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        *(_QWORD *)(src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
        v7);
    else
      Scaleform::String::operator=(v7, &src);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    LOBYTE(v8) = 1;
  }
  return v8;
}

// File Line: 5135
// RVA: 0x8FA880
bool __fastcall Scaleform::GFx::MovieImpl::ReadBinaryData(Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pdata, Scaleform::File *pfile, int *pfileLen)
{
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v3; // rsi
  int *v4; // rdi
  Scaleform::File *v5; // rbx
  int v6; // eax

  v3 = pdata;
  v4 = pfileLen;
  v5 = pfile;
  v6 = ((__int64 (__fastcall *)(Scaleform::File *))pfile->vfptr[6].__vecDelDtor)(pfile);
  *v4 = v6;
  if ( v6 )
  {
    Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      (Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)v3,
      v6);
    LOBYTE(v6) = ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v5->vfptr[10].__vecDelDtor)(
                   v5,
                   v3->Data.Data,
                   (unsigned int)*v4) == *v4;
  }
  return v6;
}

// File Line: 5181
// RVA: 0x8F3B80
void __fastcall Scaleform::GFx::MovieImpl::ProcessUnloadQueue(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rbx
  Scaleform::GFx::MovieImpl *v2; // rsi
  Scaleform::GFx::InteractiveObject *v3; // rdi
  Scaleform::RefCountNTSImplCoreVtbl *v4; // rax
  Scaleform::GFx::InteractiveObject *v5; // rcx

  v1 = this->pUnloadListHead;
  v2 = this;
  if ( v1 )
  {
    do
    {
      v3 = v1->pPlayNextOpt;
      v4 = v1->vfptr;
      v1->pPlayNextOpt = 0i64;
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v4[75].__vecDelDtor)(v1);
      v5 = v1->pParent;
      if ( v5 )
        v5->vfptr[117].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)v1);
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v1->vfptr);
      v1 = v3;
    }
    while ( v3 );
    v2->pUnloadListHead = 0i64;
  }
}

// File Line: 5354
// RVA: 0x8CBAC0
char __fastcall Scaleform::GFx::MovieImpl::FindExportedResource(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::MovieDefImpl *localDef, Scaleform::GFx::ResourceBindData *presBindData, Scaleform::String *symbol)
{
  Scaleform::String *v4; // r14
  Scaleform::GFx::ResourceBindData *v5; // r15
  Scaleform::GFx::MovieDefImpl *v6; // rbp
  Scaleform::GFx::MovieImpl *v7; // rdi
  Scaleform::GFx::MovieDefRootNode *v9; // rbx
  Scaleform::GFx::MovieDefImpl *v10; // rsi
  signed __int64 v11; // rdi
  signed __int64 v12; // rax
  Scaleform::GFx::MovieDefImpl *v13; // rcx

  v4 = symbol;
  v5 = presBindData;
  v6 = localDef;
  v7 = this;
  if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(localDef, presBindData, symbol, 0i64) )
    return 1;
  v9 = v7->RootMovieDefNodes.Root.pNext;
  v10 = v6;
  v11 = (signed __int64)&v7->RootMovieDefNodes;
  while ( 1 )
  {
    v12 = v11 ? v11 - 8 : 0i64;
    if ( v9 == (Scaleform::GFx::MovieDefRootNode *)v12 )
      break;
    v13 = v9->pDefImpl;
    if ( v13 != v6 && (unsigned __int8)Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(v13, v10) )
    {
      if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(v9->pDefImpl, v5, v4, 0i64) )
        return 1;
      v10 = v9->pDefImpl;
    }
    v9 = v9->pNext;
  }
  return 0;
}

// File Line: 5378
// RVA: 0x8D70B0
Scaleform::Render::DrawableImageContext *__fastcall Scaleform::GFx::MovieImpl::GetDrawableImageContext(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl *v1; // rdi
  Scaleform::Render::DrawableImageContext *result; // rax
  Scaleform::Render::DrawableImageContext *v3; // rax
  Scaleform::Render::DrawableImageContext *v4; // rbx
  Scaleform::Render::DrawableImageContext *v5; // rax
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::Interfaces i; // [rsp+28h] [rbp-30h]

  v1 = this;
  result = this->DIContext.pObject;
  if ( !result )
  {
    v3 = (Scaleform::Render::DrawableImageContext *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      448ui64,
                                                      0i64);
    v4 = 0i64;
    if ( v3 )
    {
      i.pTextureManager = 0i64;
      i.pHAL = 0i64;
      i.pRenderer2D = 0i64;
      i.RenderThreadID = 0i64;
      Scaleform::Render::DrawableImageContext::DrawableImageContext(v3, &v1->RenderContext, v1->pRTCommandQueue, &i);
      v4 = v5;
    }
    v6 = (Scaleform::Render::RenderBuffer *)v1->DIContext.pObject;
    if ( v6 )
      Scaleform::RefCountImpl::Release(v6);
    v1->DIContext.pObject = v4;
    result = v4;
  }
  return result;
}

// File Line: 5389
// RVA: 0x8BF3A0
Scaleform::GFx::DrawingContext *__fastcall Scaleform::GFx::MovieImpl::CreateDrawingContext(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl *v1; // rsi
  char v2; // bl
  Scaleform::GFx::DrawingContext *v3; // rdi
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *v4; // rax
  Scaleform::GFx::DrawingContext *v5; // rax
  Scaleform::GFx::DrawingContext *v6; // rdi
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> result; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::DrawingContext *v9; // [rsp+60h] [rbp+18h]

  v1 = this;
  v2 = 0;
  v3 = (Scaleform::GFx::DrawingContext *)this->pHeap->vfptr->Alloc(this->pHeap, 208ui64, 0i64);
  v9 = v3;
  if ( v3 )
  {
    v4 = Scaleform::GFx::StateBag::GetImageCreator((Scaleform::GFx::StateBag *)&v1->vfptr, &result);
    v2 = 1;
    Scaleform::GFx::DrawingContext::DrawingContext(v3, &v1->RenderContext, v4->pObject);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v2 & 1 && result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  v6->pPrev = v1->DrawingContextList.Root.pPrev;
  v6->pNext = (Scaleform::GFx::DrawingContext *)&v1->RegisteredFonts.Data.Size;
  v1->DrawingContextList.Root.pPrev->pNext = v6;
  v1->DrawingContextList.Root.pPrev = v6;
  return v6;
}

// File Line: 5399
// RVA: 0x916AE0
void __fastcall Scaleform::GFx::MovieImpl::UpdateAllRenderNodes(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::DrawingContext *v1; // rbx
  Scaleform::GFx::MovieImpl *v2; // rsi
  Scaleform::List<Scaleform::GFx::DrawingContext,Scaleform::GFx::DrawingContext> *v3; // rdi
  signed __int64 v4; // rax

  v1 = this->DrawingContextList.Root.pNext;
  v2 = this;
  v3 = &this->DrawingContextList;
  while ( 1 )
  {
    v4 = (signed __int64)(v3 ? &v3[-1] : 0i64);
    if ( v1 == (Scaleform::GFx::DrawingContext *)v4 )
      break;
    if ( v1->States < 0 )
      Scaleform::GFx::DrawingContext::UpdateRenderNode(v1);
    v1 = v1->pNext;
  }
  if ( v2->FocusRectChanged )
    Scaleform::GFx::MovieImpl::UpdateFocusRectRenderNodes(v2);
}

// File Line: 5431
// RVA: 0x8B1B60
void __fastcall Scaleform::GFx::MovieImpl::AddMovieDefToKillList(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::MovieDefImpl *md)
{
  Scaleform::GFx::MovieDefImpl *v2; // rdi
  unsigned __int64 v3; // rdx
  unsigned __int64 v4; // r8
  Scaleform::GFx::MovieImpl::MDKillListEntry *v5; // r9
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v6; // rax
  unsigned __int64 v7; // rsi
  Scaleform::Array<Scaleform::GFx::MovieImpl::MDKillListEntry,327,Scaleform::ArrayDefaultPolicy> *v8; // rbx
  unsigned __int64 *v9; // rdx
  Scaleform::GFx::ResourceLibBase *v10; // rcx

  if ( md )
  {
    v2 = md;
    v3 = 0i64;
    v4 = this->MovieDefKillList.Data.Size;
    if ( v4 )
    {
      v5 = this->MovieDefKillList.Data.Data;
      v6 = &v5->pMovieDef;
      while ( v6->pObject != v2 )
      {
        ++v3;
        v6 += 2;
        if ( v3 >= v4 )
          goto LABEL_8;
      }
      v5[v3].KillFrameId = this->RenderContext.SnapshotFrameIds[0];
    }
    else
    {
LABEL_8:
      v7 = this->RenderContext.SnapshotFrameIds[0];
      _InterlockedExchangeAdd(&v2->RefCount.Value, 1u);
      v8 = &this->MovieDefKillList;
      Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::MDKillListEntry,Scaleform::AllocatorGH<Scaleform::GFx::MovieImpl::MDKillListEntry,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::MDKillListEntry,Scaleform::AllocatorGH<Scaleform::GFx::MovieImpl::MDKillListEntry,327>,Scaleform::ArrayDefaultPolicy> *)&this->MovieDefKillList.Data.Data,
        &this->MovieDefKillList,
        this->MovieDefKillList.Data.Size + 1);
      v9 = &v8->Data.Data[v8->Data.Size - 1].KillFrameId;
      if ( v9 )
      {
        *v9 = v7;
        _InterlockedExchangeAdd(&v2->RefCount.Value, 1u);
        v9[1] = (unsigned __int64)v2;
      }
      if ( !_InterlockedDecrement(&v2->RefCount.Value) )
      {
        v10 = v2->pLib;
        if ( v10 )
        {
          v10->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, (unsigned int)v2);
          v2->pLib = 0i64;
        }
        v2->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v2->vfptr, 1u);
      }
    }
  }
}

// File Line: 5451
// RVA: 0x8F3A80
void __fastcall Scaleform::GFx::MovieImpl::ProcessMovieDefToKillList(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl *v1; // rbp
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // r15
  unsigned __int64 v4; // rsi
  Scaleform::ArrayData<Scaleform::GFx::MovieImpl::MDKillListEntry,Scaleform::AllocatorGH<Scaleform::GFx::MovieImpl::MDKillListEntry,327>,Scaleform::ArrayDefaultPolicy> *v5; // rdi
  __int64 v6; // r14
  Scaleform::GFx::MovieImpl::MDKillListEntry *v7; // rbx
  Scaleform::GFx::MovieDefImpl *v8; // rbx
  Scaleform::GFx::ResourceLibBase *v9; // rcx

  v1 = this;
  v2 = this->MovieDefKillList.Data.Size;
  if ( v2 )
  {
    v3 = this->RenderContext.FinalizedFrameId;
    v4 = 0i64;
    if ( v2 )
    {
      v5 = &this->MovieDefKillList.Data;
      v6 = 0i64;
      do
      {
        v7 = &v5->Data[v6];
        if ( v3 <= v7->KillFrameId )
        {
          ++v4;
          ++v6;
        }
        else if ( v5->Size == 1 )
        {
          Scaleform::ArrayData<Scaleform::GFx::MovieImpl::MDKillListEntry,Scaleform::AllocatorGH<Scaleform::GFx::MovieImpl::MDKillListEntry,327>,Scaleform::ArrayDefaultPolicy>::Resize(
            v5,
            0i64);
        }
        else
        {
          v8 = v7->pMovieDef.pObject;
          if ( v8 && !_InterlockedDecrement(&v8->RefCount.Value) )
          {
            v9 = v8->pLib;
            if ( v9 )
            {
              v9->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, (unsigned int)v8);
              v8->pLib = 0i64;
            }
            v8->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v8->vfptr, 1u);
          }
          memmove(&v5->Data[v6], &v5->Data[v6 + 1], 16 * (v5->Size - v4 - 1));
          --v5->Size;
        }
      }
      while ( v4 < v1->MovieDefKillList.Data.Size );
    }
  }
}

// File Line: 5666
// RVA: 0x8DDD40
void __fastcall Scaleform::GFx::MovieImpl::GetRetValHolder(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl *v1; // rbx
  __int64 v2; // rax
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v3; // rdi
  Scaleform::GFx::ASStringManager *v4; // rax
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v5; // rax

  v1 = this;
  if ( this->pRetValHolder )
  {
    v5 = this->pRetValHolder;
  }
  else
  {
    v2 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pHeap->vfptr->Alloc)(
           this->pHeap,
           56i64);
    v3 = (Scaleform::GFx::MovieImpl::ReturnValueHolder *)v2;
    if ( v2 )
    {
      v4 = (Scaleform::GFx::ASStringManager *)((__int64 (__cdecl *)(Scaleform::GFx::ASMovieRootBase *))v1->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)(v1->pASMovieRoot.pObject);
      Scaleform::GFx::MovieImpl::ReturnValueHolder::ReturnValueHolder(v3, v4);
    }
    v1->pRetValHolder = (Scaleform::GFx::MovieImpl::ReturnValueHolder *)v2;
  }
}

// File Line: 5675
// RVA: 0x8CE480
void __fastcall Scaleform::GFx::MovieImpl::ForceUpdateImages(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl *v1; // rbx

  v1 = this;
  Scaleform::Render::ContextImpl::Context::ForceUpdateImages(&this->RenderContext);
  ++v1->PreviouslyCaptured;
}

// File Line: 5687
// RVA: 0x8B1810
void __fastcall Scaleform::GFx::MovieImpl::AddIndirectTransformPair(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::DisplayObjContainer *origParent, Scaleform::Render::TreeNode *transformParent, Scaleform::GFx::DisplayObjectBase *obj)
{
  Scaleform::GFx::DisplayObjectBase *v4; // rsi
  Scaleform::Render::TreeNode *v5; // rdi
  Scaleform::GFx::DisplayObjContainer *v6; // rbp
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *v7; // rbx
  signed __int64 v8; // rdx
  bool v9; // zf

  v4 = obj;
  v5 = transformParent;
  v6 = origParent;
  if ( transformParent )
    ++transformParent->RefCount;
  if ( obj )
    ++obj->RefCount;
  if ( origParent )
    ++origParent->RefCount;
  v7 = &this->IndirectTransformPairs;
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy> *)&this->IndirectTransformPairs.Data.Data,
    &this->IndirectTransformPairs,
    this->IndirectTransformPairs.Data.Size + 1);
  v8 = (signed __int64)&v7->Data.Data[v7->Data.Size - 1];
  if ( v8 )
  {
    if ( v5 )
      ++v5->RefCount;
    *(_QWORD *)v8 = v5;
    if ( v4 )
      ++v4->RefCount;
    *(_QWORD *)(v8 + 8) = v4;
    if ( v6 )
      ++v6->RefCount;
    *(_QWORD *)(v8 + 16) = v6;
    *(_DWORD *)(v8 + 24) = -1;
  }
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v6->vfptr);
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
  if ( v5 )
  {
    v9 = v5->RefCount-- == 1;
    if ( v9 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v5->0);
  }
}

// File Line: 5696
// RVA: 0x8FFA00
Scaleform::GFx::MovieImpl::IndirectTransPair *__fastcall Scaleform::GFx::MovieImpl::RemoveIndirectTransformPair(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::MovieImpl::IndirectTransPair *result, Scaleform::GFx::DisplayObjectBase *obj)
{
  Scaleform::GFx::MovieImpl::IndirectTransPair *v3; // rdi
  unsigned __int64 v4; // rdx
  unsigned __int64 v5; // r9
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy> > *v6; // r10
  Scaleform::GFx::MovieImpl::IndirectTransPair *v7; // rcx
  Scaleform::GFx::DisplayObjectBase **v8; // rax
  signed __int64 v9; // rax
  Scaleform::Render::ContextImpl::Entry *v10; // rbx
  __int64 v11; // rcx
  Scaleform::RefCountNTSImpl *v12; // rsi
  __int64 v13; // r8
  Scaleform::RefCountNTSImpl *v14; // rbp
  int v15; // er14
  bool v16; // zf

  v3 = result;
  v4 = 0i64;
  v5 = this->IndirectTransformPairs.Data.Size;
  if ( v5 )
  {
    v6 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy> > *)&this->IndirectTransformPairs.Data;
    v7 = this->IndirectTransformPairs.Data.Data;
    v8 = &v7->Obj.pObject;
    while ( *v8 != obj )
    {
      ++v4;
      v8 += 4;
      if ( v4 >= v5 )
        goto LABEL_25;
    }
    v9 = (signed __int64)&v7[v4];
    if ( *(_QWORD *)v9 )
      ++*(_QWORD *)(*(_QWORD *)v9 + 8i64);
    v10 = *(Scaleform::Render::ContextImpl::Entry **)v9;
    v11 = *(_QWORD *)(v9 + 8);
    if ( v11 )
      ++*(_DWORD *)(v11 + 8);
    v12 = *(Scaleform::RefCountNTSImpl **)(v9 + 8);
    v13 = *(_QWORD *)(v9 + 16);
    if ( v13 )
      ++*(_DWORD *)(v13 + 8);
    v14 = *(Scaleform::RefCountNTSImpl **)(v9 + 16);
    v15 = *(_DWORD *)(v9 + 24);
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      v6,
      v4);
    if ( v10 )
      ++v10->RefCount;
    v3->TransformParent.pObject = (Scaleform::Render::TreeNode *)v10;
    if ( v12 )
      ++v12->RefCount;
    v3->Obj.pObject = (Scaleform::GFx::DisplayObjectBase *)v12;
    if ( v14 )
      ++v14->RefCount;
    v3->OriginalParent.pObject = (Scaleform::GFx::DisplayObjContainer *)v14;
    v3->OrigParentDepth = v15;
    if ( v14 )
      Scaleform::RefCountNTSImpl::Release(v14);
    if ( v12 )
      Scaleform::RefCountNTSImpl::Release(v12);
    if ( v10 )
    {
      v16 = v10->RefCount-- == 1;
      if ( v16 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v10);
    }
  }
  else
  {
LABEL_25:
    v3->TransformParent.pObject = 0i64;
    v3->Obj.pObject = 0i64;
    v3->OriginalParent.pObject = 0i64;
    v3->OrigParentDepth = -1;
  }
  return v3;
}

// File Line: 5710
// RVA: 0x8BC3E0
void __fastcall Scaleform::GFx::MovieImpl::ClearIndirectTransformPairs(Scaleform::GFx::MovieImpl *this)
{
  unsigned __int64 v1; // rsi
  Scaleform::GFx::MovieImpl *v2; // rbp
  __int64 v3; // rdi
  Scaleform::GFx::MovieImpl::IndirectTransPair *v4; // rbx
  Scaleform::Render::ContextImpl::Entry *v5; // rcx
  bool v6; // zf
  Scaleform::RefCountNTSImpl *v7; // rcx
  Scaleform::RefCountNTSImpl *v8; // rcx

  v1 = this->IndirectTransformPairs.Data.Size;
  v2 = this;
  if ( v1 )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->IndirectTransformPairs.Data.Data;
      v5 = (Scaleform::Render::ContextImpl::Entry *)&v4[v3].TransformParent.pObject->0;
      if ( v5 )
      {
        v6 = v5->RefCount-- == 1;
        if ( v6 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
      }
      v4[v3].TransformParent.pObject = 0i64;
      v7 = (Scaleform::RefCountNTSImpl *)&v4[v3].Obj.pObject->vfptr;
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
      v4[v3].Obj.pObject = 0i64;
      v8 = (Scaleform::RefCountNTSImpl *)&v4[v3].OriginalParent.pObject->vfptr;
      if ( v8 )
        Scaleform::RefCountNTSImpl::Release(v8);
      v4[v3].OriginalParent.pObject = 0i64;
      v4[v3].OrigParentDepth = 0;
      ++v3;
      --v1;
    }
    while ( v1 );
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy> *)&v2->IndirectTransformPairs.Data.Data,
    &v2->IndirectTransformPairs,
    0i64);
}

// File Line: 5720
// RVA: 0x9183C0
void __fastcall Scaleform::GFx::MovieImpl::UpdateTransformParent(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::DisplayObjectBase *obj, Scaleform::GFx::DisplayObjectBase *transfParent)
{
  unsigned __int64 v3; // r9
  Scaleform::Render::TreeNode *v4; // rdi
  unsigned __int64 v5; // rbx
  Scaleform::GFx::MovieImpl::IndirectTransPair *v6; // r10
  Scaleform::GFx::DisplayObjectBase **v7; // rax
  signed __int64 v8; // rbx
  Scaleform::Render::TreeNode *v9; // rax
  Scaleform::Render::ContextImpl::Entry *v10; // rcx
  bool v11; // zf

  v3 = this->IndirectTransformPairs.Data.Size;
  v4 = 0i64;
  v5 = 0i64;
  if ( v3 )
  {
    v6 = this->IndirectTransformPairs.Data.Data;
    v7 = &v6->Obj.pObject;
    while ( *v7 != obj )
    {
      ++v5;
      v7 += 4;
      if ( v5 >= v3 )
        return;
    }
    v8 = (signed __int64)&v6[v5];
    if ( transfParent )
    {
      v9 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(transfParent);
      v4 = v9;
      if ( v9 )
        ++v9->RefCount;
    }
    v10 = *(Scaleform::Render::ContextImpl::Entry **)v8;
    if ( *(_QWORD *)v8 )
    {
      v11 = v10->RefCount-- == 1;
      if ( v11 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v10);
    }
    *(_QWORD *)v8 = v4;
    *(_DWORD *)(v8 + 24) = -1;
  }
}

// File Line: 5735
// RVA: 0x8FE410
char __fastcall Scaleform::GFx::MovieImpl::RegisterFont(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::MovieDef *md, Scaleform::GFx::FontResource *fontRes)
{
  Scaleform::GFx::FontResource *v3; // rsi
  Scaleform::GFx::MovieDef *v4; // rdi
  Scaleform::GFx::MovieImpl *v5; // rbp
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // r8
  Scaleform::GFx::MovieImpl::FontDesc *v8; // rax
  char result; // al
  Scaleform::GFx::MovieImpl::FontDesc *v10; // rdx
  Scaleform::GFx::ResourceLibBase *v11; // rcx
  Scaleform::GFx::ResourceLibBase *v12; // rcx

  v3 = fontRes;
  v4 = md;
  v5 = this;
  v6 = 0i64;
  v7 = this->RegisteredFonts.Data.Size;
  if ( v7 )
  {
    v8 = this->RegisteredFonts.Data.Data;
    while ( v8->pFont.pObject != v3 || v8->pMovieDef.pObject != v4 )
    {
      ++v6;
      ++v8;
      if ( v6 >= v7 )
        goto LABEL_8;
    }
    result = 0;
  }
  else
  {
LABEL_8:
    if ( v3 )
      _InterlockedExchangeAdd(&v3->RefCount.Value, 1u);
    if ( v4 )
      _InterlockedExchangeAdd(&v4->RefCount.Value, 1u);
    Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::FontDesc,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::FontDesc,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::FontDesc,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::FontDesc,2>,Scaleform::ArrayDefaultPolicy> *)&this->RegisteredFonts.Data.Data,
      &this->RegisteredFonts,
      this->RegisteredFonts.Data.Size + 1);
    v10 = &v5->RegisteredFonts.Data.Data[v5->RegisteredFonts.Data.Size - 1];
    if ( v10 )
    {
      if ( v4 )
        _InterlockedExchangeAdd(&v4->RefCount.Value, 1u);
      v10->pMovieDef.pObject = v4;
      if ( v3 )
        _InterlockedExchangeAdd(&v3->RefCount.Value, 1u);
      v10->pFont.pObject = v3;
    }
    v5->Flags2 |= 2u;
    if ( v3 && !_InterlockedDecrement(&v3->RefCount.Value) )
    {
      v11 = v3->pLib;
      if ( v11 )
      {
        v11->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, (unsigned int)v3);
        v3->pLib = 0i64;
      }
      v3->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v3->vfptr, 1u);
    }
    if ( v4 && !_InterlockedDecrement(&v4->RefCount.Value) )
    {
      v12 = v4->pLib;
      if ( v12 )
      {
        v12->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, (unsigned int)v4);
        v4->pLib = 0i64;
      }
      v4->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v4->vfptr, 1u);
    }
    result = 1;
  }
  return result;
}

// File Line: 5756
// RVA: 0x916540
void __fastcall Scaleform::GFx::MovieImpl::UnregisterFonts(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::MovieDefImpl *pdefImpl)
{
  unsigned __int64 v2; // rdi
  Scaleform::GFx::MovieDefImpl *v3; // r14
  Scaleform::GFx::MovieImpl *v4; // rbp
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::FontDesc,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::FontDesc,2>,Scaleform::ArrayDefaultPolicy> *v5; // rbx
  __int64 v6; // rsi
  Scaleform::GFx::MovieImpl::FontDesc *v7; // rcx
  Scaleform::GFx::MovieDefRootNode *i; // rbx
  signed __int64 v9; // rax

  v2 = 0i64;
  v3 = pdefImpl;
  v4 = this;
  if ( this->RegisteredFonts.Data.Size )
  {
    v5 = (Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::FontDesc,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::FontDesc,2>,Scaleform::ArrayDefaultPolicy> *)&this->RegisteredFonts.Data.Data;
    v6 = 0i64;
    do
    {
      v7 = &v5->Data[v6];
      if ( (Scaleform::GFx::MovieDefImpl *)v7->pMovieDef.pObject == v3 )
      {
        if ( v5->Size == 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::FontDesc,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::FontDesc,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            v5,
            v5,
            0i64);
        }
        else
        {
          Scaleform::GFx::MovieImpl::FontDesc::~FontDesc(v7);
          memmove(&v5->Data[v6], &v5->Data[v6 + 1], 16 * (v5->Size - v2 - 1));
          --v5->Size;
        }
      }
      else
      {
        ++v2;
        ++v6;
      }
    }
    while ( v2 < v4->RegisteredFonts.Data.Size );
  }
  for ( i = v4->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
  {
    v9 = (signed __int64)(v4 == (Scaleform::GFx::MovieImpl *)-112i64 ? 0i64 : &v4->MovieLevels.Data.Policy);
    if ( i == (Scaleform::GFx::MovieDefRootNode *)v9 )
      break;
    Scaleform::GFx::FontManager::CleanCacheFor(i->pFontManager.pObject, v3);
  }
  v4->Flags2 |= 2u;
}

// File Line: 5780
// RVA: 0x8CD3E0
Scaleform::GFx::FontResource *__fastcall Scaleform::GFx::MovieImpl::FindRegisteredFont(Scaleform::GFx::MovieImpl *this, const char *pfontName, unsigned int matchFontFlags, Scaleform::GFx::MovieDef **ppsrcMovieDef)
{
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // rbx
  Scaleform::GFx::MovieDef **v6; // r13
  const char *v7; // r12
  Scaleform::GFx::MovieImpl *v8; // rsi
  __int64 v9; // rdi
  unsigned int v10; // er14
  unsigned int v11; // er15
  Scaleform::Render::Font *v12; // rcx
  const char *v13; // rax
  signed __int64 v15; // rbx

  v4 = this->RegisteredFonts.Data.Size;
  v5 = 0i64;
  v6 = ppsrcMovieDef;
  v7 = pfontName;
  v8 = this;
  if ( !v4 )
    return 0i64;
  v9 = 0i64;
  v10 = matchFontFlags & 0x10 | ((matchFontFlags & 0x300) != 0 ? 0x300 : 0) | 3;
  v11 = matchFontFlags & 0x313;
  while ( 1 )
  {
    v12 = v8->RegisteredFonts.Data.Data[v9].pFont.pObject->pFont.pObject;
    if ( (v10 & v12->Flags) == v11 )
    {
      v13 = (const char *)((__int64 (*)(void))v12->vfptr[1].__vecDelDtor)();
      if ( !Scaleform::String::CompareNoCase(v13, v7) )
        break;
    }
    ++v5;
    ++v9;
    if ( v5 >= v4 )
      return 0i64;
  }
  v15 = v5;
  *v6 = v8->RegisteredFonts.Data.Data[v15].pMovieDef.pObject;
  return v8->RegisteredFonts.Data.Data[v15].pFont.pObject;
}

// File Line: 5807
// RVA: 0x8E9620
void __fastcall Scaleform::GFx::MovieImpl::MakeAreaVisible(Scaleform::GFx::MovieImpl *this, Scaleform::Render::Rect<float> *screenRect, Scaleform::Render::Rect<float> *box, unsigned int flags)
{
  char v4; // si
  Scaleform::Render::Rect<float> *v5; // rbx
  Scaleform::Render::Rect<float> *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // r15
  float *v8; // r14
  float v9; // xmm9_4
  float v10; // xmm10_4
  __m128 v11; // xmm6
  float v12; // xmm7_4
  double v13; // xmm4_8
  double v14; // xmm3_8
  float v15; // xmm8_4
  float v16; // xmm11_4
  float v17; // xmm7_4
  double v18; // xmm1_8
  double v19; // xmm3_8
  __m128d v20; // xmm1
  double v21; // xmm3_8
  double v22; // xmm12_8
  double v23; // xmm5_8
  double v24; // xmm2_8
  float v25; // xmm6_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm8_4
  float v30; // xmm10_4
  float v31; // xmm7_4
  float v32; // xmm10_4
  float v33; // xmm6_4
  float v34; // xmm9_4
  float v35; // xmm3_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm6_4
  float v39; // xmm3_4
  float v40; // xmm0_4
  float v41; // xmm8_4
  Scaleform::Render::Rect<float> pr; // [rsp+20h] [rbp-99h]
  Scaleform::Render::Rect<float> v43; // [rsp+30h] [rbp-89h]
  Scaleform::Render::Rect<float> r; // [rsp+40h] [rbp-79h]
  Scaleform::Render::Matrix2x4<float> v45; // [rsp+50h] [rbp-69h]
  Scaleform::Render::Matrix2x4<float> v46; // [rsp+70h] [rbp-49h]

  v4 = flags;
  v5 = box;
  v6 = screenRect;
  v7 = this;
  if ( box->x2 > screenRect->x2 || box->y2 > screenRect->y2 || box->x1 < screenRect->x1 || box->y1 < screenRect->y1 )
  {
    *(_OWORD *)&v46.M[0][0] = _xmm;
    *(__m128 *)&v46.M[1][0] = _xmm;
    Scaleform::GFx::MovieImpl::ResetViewportMatrix(this);
    v8 = (float *)&v7->ViewportMatrix;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v46, &v7->ViewportMatrix);
    pr = 0i64;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v46, &pr, v6);
    v9 = v5->x1 * 20.0;
    v11 = (__m128)LODWORD(v5->x2);
    v10 = v5->y1 * 20.0;
    v11.m128_f32[0] = v11.m128_f32[0] * 20.0;
    v12 = v5->y2 * 20.0;
    r.x1 = v5->x1 * 20.0;
    r.y1 = v10;
    LODWORD(r.x2) = v11.m128_i32[0];
    r.y2 = v12;
    v13 = DOUBLE_1_0;
    v14 = DOUBLE_1_0;
    if ( !(v4 & 1) )
    {
      if ( (float)(v11.m128_f32[0] - v9) > (float)(pr.x2 - pr.x1) )
        v13 = pr.x2 / v11.m128_f32[0];
      if ( (float)(v12 - v10) > (float)(pr.y2 - pr.y1) )
        v14 = pr.y2 / v12;
    }
    if ( v4 & 2 )
    {
      if ( v13 == 1.0 && v14 == 1.0 )
      {
        v15 = pr.y2 - pr.y1;
        v16 = pr.x2 - pr.x1;
        v17 = v12 - v10;
        v18 = (float)((float)(pr.y2 - pr.y1) * (float)(pr.x2 - pr.x1));
        v11.m128_f32[0] = v11.m128_f32[0] - v9;
        if ( (float)((float)(v17 * v11.m128_f32[0]) * 2.0) < v18 )
        {
          v19 = v18;
          v20 = _mm_cvtps_pd(v11);
          v21 = v19 * 0.5;
          v22 = 1.0 / v17;
          v23 = 1.0 / v11.m128_f32[0];
          v20.m128d_f64[0] = v20.m128d_f64[0] * v22 * v21;
          *(_QWORD *)&v24 = (unsigned __int128)_mm_sqrt_pd(v20);
          v13 = v23 * v24;
          v14 = v21 / v24 * v22;
          if ( v11.m128_f32[0] * (v23 * v24) > v16 )
            v13 = v16 * v23;
          if ( v17 * v14 > v15 )
            v14 = v15 * v22;
        }
      }
    }
    if ( v13 >= v14 )
      v13 = v14;
    v25 = 0.0;
    v26 = v13;
    v45.M[0][0] = v26;
    v45.M[1][1] = v26;
    v45.M[0][1] = v26 * 0.0;
    v45.M[0][2] = v26 * 0.0;
    v45.M[1][0] = v26 * 0.0;
    v45.M[1][2] = v26 * 0.0;
    v45.M[0][3] = (float)(COERCE_FLOAT(LODWORD(v9) ^ _xmm[0]) * v26) + v9;
    v45.M[1][3] = (float)(COERCE_FLOAT(LODWORD(v10) ^ _xmm[0]) * v26) + v10;
    v43 = 0i64;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v45, &v43, &r);
    v27 = 0.0;
    if ( v43.x1 > pr.x2 || v43.x2 < pr.x1 || v43.x2 > pr.x2 || v43.x1 < pr.x1 )
    {
      if ( v4 & 4 )
        v25 = v43.x1 - pr.x1;
      else
        v25 = (float)((float)((float)(v43.x2 - v43.x1) * 0.5) + v43.x1)
            - (float)(pr.x2 - (float)((float)(pr.x2 - pr.x1) * 0.5));
    }
    if ( v43.y1 > pr.y2 || v43.y2 < pr.y1 || v43.y2 > pr.y2 || v43.y1 < pr.y1 )
    {
      if ( v4 & 4 )
        v27 = v43.y1 - pr.y1;
      else
        v27 = (float)((float)((float)(v43.y2 - v43.y1) * 0.5) + v43.y1)
            - (float)(pr.y2 - (float)((float)(pr.y2 - pr.y1) * 0.5));
    }
    v28 = *v8;
    v29 = v7->ViewportMatrix.M[1][1];
    v30 = v45.M[0][3];
    v7->ViewportMatrix.M[1][2] = 0.0;
    v7->ViewportMatrix.M[0][2] = 0.0;
    v31 = v7->ViewportMatrix.M[1][0];
    v32 = v30 + COERCE_FLOAT(LODWORD(v25) ^ _xmm[0]);
    v33 = v7->ViewportMatrix.M[0][1];
    v45.M[0][3] = v32;
    v35 = v33 * v45.M[1][1];
    v45.M[1][3] = v45.M[1][3] + COERCE_FLOAT(LODWORD(v27) ^ _xmm[0]);
    v34 = v45.M[1][3];
    *v8 = (float)(v33 * v45.M[1][0]) + (float)(v28 * v45.M[0][0]);
    v36 = v28 * v45.M[0][1];
    v7->ViewportMatrix.M[1][0] = (float)(v29 * v45.M[1][0]) + (float)(v31 * v45.M[0][0]);
    v37 = v29 * v45.M[1][1];
    v38 = (float)((float)(v33 * v34) + (float)(v28 * v32)) + v7->ViewportMatrix.M[0][3];
    v39 = v35 + v36;
    v40 = v31 * v45.M[0][1];
    v7->ViewportMatrix.M[0][1] = v39;
    v7->ViewportMatrix.M[0][3] = v38;
    v41 = (float)((float)(v29 * v34) + (float)(v31 * v32)) + v7->ViewportMatrix.M[1][3];
    v7->ViewportMatrix.M[1][1] = v37 + v40;
    v7->ViewportMatrix.M[1][3] = v41;
    Scaleform::Render::TreeNode::SetMatrix(
      (Scaleform::Render::TreeNode *)&v7->pRenderRoot.pObject->0,
      &v7->ViewportMatrix);
  }
}

