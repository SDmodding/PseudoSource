// File Line: 69
// RVA: 0x7B0190
void __fastcall Scaleform::GFx::AS3::FrameCounter::AdvanceFrame(
        Scaleform::GFx::AS3::FrameCounter *this,
        bool nextFrame,
        float framePos)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // rbx
  unsigned int ASFramesToExecute; // edx
  Scaleform::GFx::AS3::ASVM *v6; // rax

  if ( nextFrame )
  {
    pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    ASFramesToExecute = pObject->ASFramesToExecute;
    if ( ASFramesToExecute )
    {
      Scaleform::GFx::AS3::VM::ExecuteCode(pObject->pAVM.pObject, ASFramesToExecute);
      v6 = pObject->pAVM.pObject;
      if ( v6->HandleException )
        v6->HandleException = 0;
      pObject->ASFramesToExecute = 0;
    }
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, AL_Highest);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, AL_High);
    Scaleform::GFx::AS3::FrameCounter::QueueFrameActions(this);
    Scaleform::GFx::AS3::MovieRoot::RequeueActionQueue(pObject, AL_Count_, AL_Frame);
  }
}

// File Line: 100
// RVA: 0x80B960
void __fastcall Scaleform::GFx::AS3::FrameCounter::QueueFrameActions(Scaleform::GFx::AS3::FrameCounter *this)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rsi
  Scaleform::GFx::InteractiveObject *i; // rbx
  Scaleform::GFx::AS3::AvmSprite *v4; // rdi
  unsigned int v5; // eax
  Scaleform::GFx::InteractiveObject *j; // rbx
  Scaleform::GFx::AS3::AvmSprite *v7; // rdi
  unsigned int v8; // eax

  pObject = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  Scaleform::GFx::AS3::EventChains::QueueEvents((Scaleform::GFx::AS3::EventChains *)&pObject[8].pASSupport, 16777237);
  if ( (this->pASRoot->pMovieImpl->Flags & 0x80000) != 0 )
  {
    for ( i = this->pPlayPrev; i; i = i->pPlayPrev )
    {
      *((_BYTE *)&i->CreateFrame + 4 * (unsigned __int8)i->AvmObjOffset) |= 2u;
      if ( (i->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
      {
        v4 = (Scaleform::GFx::AS3::AvmSprite *)((char *)i + 4 * (unsigned __int8)i->AvmObjOffset);
        if ( (v4->Flags & 2) != 0 )
        {
          v5 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->pDispObj->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::vfptr[107].__vecDelDtor)(v4->pDispObj);
          Scaleform::GFx::AS3::AvmSprite::QueueFrameScript(v4, v5);
          v4->Flags &= ~2u;
        }
      }
    }
  }
  else
  {
    for ( j = this->pPlayPrevOpt; j; j = j->pPlayPrevOpt )
    {
      *((_BYTE *)&j->CreateFrame + 4 * (unsigned __int8)j->AvmObjOffset) |= 2u;
      if ( (j->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
      {
        v7 = (Scaleform::GFx::AS3::AvmSprite *)((char *)j + 4 * (unsigned __int8)j->AvmObjOffset);
        if ( (v7->Flags & 2) != 0 )
        {
          v8 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v7->pDispObj->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::vfptr[107].__vecDelDtor)(v7->pDispObj);
          Scaleform::GFx::AS3::AvmSprite::QueueFrameScript(v7, v8);
          v7->Flags &= ~2u;
        }
      }
    }
  }
  Scaleform::GFx::AS3::EventChains::QueueEvents((Scaleform::GFx::AS3::EventChains *)&pObject[8].pASSupport, 16777238);
}

// File Line: 154
// RVA: 0x782140
void __fastcall Scaleform::GFx::AS3::Stage::Stage(
        Scaleform::GFx::AS3::Stage *this,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        _DWORD *id)
{
  Scaleform::GFx::ASStringManager *StringManager; // rax

  LODWORD(id) = *id;
  Scaleform::GFx::DisplayObjContainer::DisplayObjContainer(
    this,
    pbindingDefImpl,
    pasRoot,
    pparent,
    (Scaleform::GFx::ResourceId)&id);
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::Stage::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::Stage::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  this->pRoot.pObject = 0i64;
  this->FrameCounterObj.pObject = 0i64;
  StringManager = Scaleform::GFx::InteractiveObject::GetStringManager(this);
  Scaleform::GFx::ASStringManager::CreateEmptyString(StringManager, &this->CurrentStageOrientation);
  this->MouseCursorEventCnt = 0;
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x2000u;
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Flags |= 1u;
}

// File Line: 160
// RVA: 0x78E1A0
void __fastcall Scaleform::GFx::AS3::Stage::~Stage(Scaleform::GFx::AS3::Stage *this)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  Scaleform::GFx::DisplayObjContainer *v5; // rcx

  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::Stage::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::Stage::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  pNode = this->CurrentStageOrientation.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  pObject = this->FrameCounterObj.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v5 = this->pRoot.pObject;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer(this);
}

// File Line: 164
// RVA: 0x804960
void __fastcall Scaleform::GFx::AS3::Stage::OnInsertionAsLevel(Scaleform::GFx::AS3::Stage *this, int level)
{
  Scaleform::GFx::InteractiveObject *v4; // rdi
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  int v6; // [rsp+70h] [rbp+18h] BYREF
  Scaleform::GFx::ResourceId v7; // [rsp+78h] [rbp+20h] BYREF

  v6 = 322;
  v4 = (Scaleform::GFx::InteractiveObject *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              224i64,
                                              &v6);
  if ( v4 )
  {
    v7.Id = 0;
    Scaleform::GFx::InteractiveObject::InteractiveObject(
      v4,
      this->pDefImpl.pObject,
      this->pASRoot,
      0i64,
      (Scaleform::GFx::ResourceId)&v7);
    v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::FrameCounter::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
    v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::FrameCounter::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
    v4[1].Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = 0i64;
  }
  else
  {
    v4 = 0i64;
  }
  pObject = this->FrameCounterObj.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->FrameCounterObj.pObject = v4;
  Scaleform::GFx::InteractiveObject::AddToPlayList(v4);
  Scaleform::GFx::DisplayObjContainer::OnInsertionAsLevel(this, level);
}

// File Line: 172
// RVA: 0x7D7770
void __fastcall Scaleform::GFx::AS3::Stage::ForceShutdown(Scaleform::GFx::AS3::Stage *this)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // rcx
  Scaleform::GFx::DisplayObjContainer *v3; // rcx

  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this->FrameCounterObj.pObject);
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, this);
  _((AMD_HD3D *)this);
  pObject = this->pRoot.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))pObject->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[60].__vecDelDtor)(pObject);
  v3 = this->pRoot.pObject;
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  this->pRoot.pObject = 0i64;
  Scaleform::GFx::DisplayObjContainer::ForceShutdown(this);
}

// File Line: 182
// RVA: 0x7CE8A0
void __fastcall Scaleform::GFx::AS3::Stage::ExecuteFrame0Events(Scaleform::GFx::AS3::Stage *this)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // r10
  Scaleform::GFx::ASMovieRootBase *pObject; // rbp
  Scaleform::GFx::MovieDefImpl *v4; // r8
  Scaleform::GFx::ASSupport *v5; // rcx
  Scaleform::GFx::Sprite *v6; // rsi
  unsigned __int8 AvmObjOffset; // al
  __int64 v8; // rax
  Scaleform::GFx::ASMovieRootBase *v9; // rcx
  Scaleform::GFx::ASStringManager *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::DisplayObjContainer *v14; // rcx
  __int64 v15; // rax
  Scaleform::Render::TreeNode *v16; // r12
  char *v17; // rcx
  Scaleform::GFx::AS3::Class *Class; // rax
  Scaleform::GFx::AS3::Class *v19; // r15
  __int64 v20; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v21; // rdi
  bool v22; // al
  Scaleform::GFx::ASStringNode *v23; // rbx
  unsigned int Size; // eax
  __int64 v25; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v26; // rdi
  bool v27; // al
  Scaleform::GFx::ASStringNode *v28; // rbx
  unsigned int v29; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::VM *vfptr; // rcx
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // rbx
  char *v34; // rcx
  unsigned int v35; // eax
  Scaleform::StringDataPtr gname; // [rsp+38h] [rbp-60h] BYREF
  __int64 v37; // [rsp+48h] [rbp-50h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Class *v39; // [rsp+A8h] [rbp+10h]
  Scaleform::GFx::Sprite *v40; // [rsp+B0h] [rbp+18h]
  __int64 v41; // [rsp+B8h] [rbp+20h]

  pASRoot = this->pASRoot;
  pObject = pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v4 = this->pDefImpl.pObject;
  gname.pStr = (const char *)v4->pBindData.pObject->pDataDef.pObject;
  gname.Size = (unsigned __int64)v4;
  v37 = 0i64;
  v5 = pASRoot->pASSupport.pObject;
  LODWORD(result.pNode) = 0;
  v6 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::StringDataPtr *, Scaleform::GFx::AS3::Stage *, Scaleform::GFx::ASString *, int, __int64))v5->vfptr[4].__vecDelDtor)(
                                   v5,
                                   pASRoot->pMovieImpl,
                                   &gname,
                                   this,
                                   &result,
                                   3,
                                   -2i64);
  Scaleform::GFx::Sprite::SetLoadedSeparately(v6, 1);
  v6->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x800u;
  v40 = v6;
  v6->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x2000u;
  v6->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= 0x1000u;
  AvmObjOffset = v6->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v8 = ((__int64 (__fastcall *)(__int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * AvmObjOffset))[2].__vecDelDtor)((__int64)v6 + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v8 + 224i64))(v8, 0i64);
  }
  v9 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v10 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))v9->vfptr[59].__vecDelDtor)(v9);
  v11 = Scaleform::GFx::ASStringManager::CreateConstString(v10, &result, "root1");
  v6->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[124].__vecDelDtor(
    v6,
    (unsigned int)v11);
  pNode = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v6->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Flags |= 1u;
  ++v6->RefCount;
  v14 = this->pRoot.pObject;
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release(v14);
  this->pRoot.pObject = v6;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Stage *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[39].__vecDelDtor)(this);
  ((void (__fastcall *)(Scaleform::GFx::Sprite *))v6->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[39].__vecDelDtor)(v6);
  v15 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Stage *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[69].__vecDelDtor)(this);
  v16 = (Scaleform::Render::TreeNode *)v15;
  if ( v15 )
    ++*(_QWORD *)(v15 + 8);
  v41 = v15;
  Scaleform::GFx::DisplayList::AddEntryAtIndex(
    &this->mDisplayList,
    this,
    LODWORD(this->mDisplayList.DisplayObjectArray.Data.Size),
    v6);
  Scaleform::Render::TreeContainer::Insert(this->pASRoot->pMovieImpl->pRenderRoot.pObject, 0i64, v16);
  v6->pParent = this;
  Scaleform::GFx::InteractiveObject::AddToPlayList(v6);
  v17 = (char *)this + 4 * (unsigned __int8)this->AvmObjOffset;
  pObject[22].RefCount += (*(__int64 (__fastcall **)(char *, _QWORD))(*(_QWORD *)v17 + 112i64))(v17, 0i64);
  gname.pStr = "flash.display.LoaderInfo";
  gname.Size = 24i64;
  Class = Scaleform::GFx::AS3::VM::GetClass(
            (Scaleform::GFx::AS3::VM *)pObject[2].vfptr,
            &gname,
            (Scaleform::GFx::AS3::VMAppDomain *)pObject[2].vfptr[52].__vecDelDtor);
  v19 = Class;
  v39 = Class;
  if ( Class )
    Class->RefCount = (Class->RefCount + 1) & 0x8FBFFFFF;
  if ( Class )
  {
    v20 = (unsigned __int8)this->AvmObjOffset;
    v21 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)((char *)&this->pWeakProxy + 4 * v20);
    if ( !v21 )
      v21 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(&this->RefCount + v20);
    if ( ((unsigned __int8)v21 & 1) != 0 )
      v21 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v21 - 1);
    result.pNode = 0i64;
    v22 = Scaleform::GFx::AS3::ASVM::_constructInstance(
            (Scaleform::GFx::AS3::ASVM *)pObject[2].vfptr,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
            v19,
            0,
            0i64);
    v23 = result.pNode;
    if ( v22 && v21 )
    {
      Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(
        v21,
        (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)result.pNode);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v23[2].pManager,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)v21);
    }
    if ( v23 )
    {
      if ( ((unsigned __int8)v23 & 1) != 0 )
      {
        result.pNode = (Scaleform::GFx::ASStringNode *)((char *)v23 - 1);
      }
      else
      {
        Size = v23->Size;
        if ( (Size & 0x3FFFFF) != 0 )
        {
          v23->Size = Size - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v23);
        }
      }
    }
  }
  Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor((Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v6
                                                                                                  + 4 * (unsigned __int8)v6->AvmObjOffset));
  if ( v19 )
  {
    v25 = (unsigned __int8)v6->AvmObjOffset;
    v26 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)((char *)&v6->pWeakProxy + 4 * v25);
    if ( !v26 )
      v26 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(&v6->RefCount + v25);
    if ( ((unsigned __int8)v26 & 1) != 0 )
      v26 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v26 - 1);
    result.pNode = 0i64;
    v27 = Scaleform::GFx::AS3::ASVM::_constructInstance(
            (Scaleform::GFx::AS3::ASVM *)pObject[2].vfptr,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
            v19,
            0,
            0i64);
    v28 = result.pNode;
    if ( v27 && v26 )
    {
      Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(
        v26,
        (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)result.pNode);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v28[2].pManager,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)v26);
    }
    if ( v28 )
    {
      if ( ((unsigned __int8)v28 & 1) != 0 )
      {
        result.pNode = (Scaleform::GFx::ASStringNode *)((char *)v28 - 1);
      }
      else
      {
        v29 = v28->Size;
        if ( (v29 & 0x3FFFFF) != 0 )
        {
          v28->Size = v29 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v28);
        }
      }
    }
  }
  Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(
    (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v6 + 4 * (unsigned __int8)v6->AvmObjOffset),
    1);
  if ( (*(_BYTE *)(&v6->ClipDepth + 2 * (unsigned __int8)v6->AvmObjOffset) & 4) == 0 )
    ((void (__fastcall *)(Scaleform::GFx::Sprite *))v6->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[112].__vecDelDtor)(v6);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
    (Scaleform::GFx::AS3::MovieRoot *)this->pASRoot->pMovieImpl->pASMovieRoot.pObject,
    AL_Highest);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
    (Scaleform::GFx::AS3::MovieRoot *)this->pASRoot->pMovieImpl->pASMovieRoot.pObject,
    AL_High);
  *((_BYTE *)&v6->ClipDepth + 4 * (unsigned __int8)v6->AvmObjOffset) |= 4u;
  while ( pObject[22].RefCount )
  {
    RefCount = pObject[22].RefCount;
    pObject[22].RefCount = 0;
    Scaleform::GFx::AS3::VM::ExecuteCode((Scaleform::GFx::AS3::VM *)pObject[2].vfptr, RefCount);
    vfptr = (Scaleform::GFx::AS3::VM *)pObject[2].vfptr;
    if ( vfptr->HandleException )
    {
      vfptr->HandleException = 0;
      p_ExceptionObj = &vfptr->ExceptionObj;
      Scaleform::GFx::AS3::VM::OutputError(vfptr, &vfptr->ExceptionObj);
      if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
      {
        if ( (p_ExceptionObj->Flags & 0x200) != 0 )
        {
          pWeakProxy = p_ExceptionObj->Bonus.pWeakProxy;
          v13 = pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          p_ExceptionObj->Bonus.pWeakProxy = 0i64;
          p_ExceptionObj->value.VS._1.VStr = 0i64;
          p_ExceptionObj->value.VS._2.VObj = 0i64;
          p_ExceptionObj->Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(p_ExceptionObj);
        }
      }
      p_ExceptionObj->Flags &= 0xFFFFFFE0;
      this->FrameCounterObj.pObject->Flags |= 0x20u;
    }
  }
  if ( v6->pParent )
  {
    v34 = (char *)v6 + 4 * (unsigned __int8)v6->AvmObjOffset;
    LOBYTE(pWeakProxy) = 1;
    (*(void (__fastcall **)(char *, Scaleform::GFx::AS3::WeakProxy *))(*(_QWORD *)v34 + 152i64))(v34, pWeakProxy);
  }
  this->pASRoot->pMovieImpl->Flags |= 0x80000u;
  LOBYTE(pWeakProxy) = 1;
  this->FrameCounterObj.pObject->vfptr[71].__vecDelDtor(this->FrameCounterObj.pObject, (unsigned int)pWeakProxy);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
    (Scaleform::GFx::AS3::MovieRoot *)this->pASRoot->pMovieImpl->pASMovieRoot.pObject,
    AL_Frame);
  if ( v19 )
  {
    if ( ((unsigned __int8)v19 & 1) != 0 )
    {
      v39 = (Scaleform::GFx::AS3::Class *)((char *)v19 - 1);
    }
    else
    {
      v35 = v19->RefCount;
      if ( (v35 & 0x3FFFFF) != 0 )
      {
        v19->RefCount = v35 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
      }
    }
  }
  if ( v16 )
  {
    v13 = v16->RefCount-- == 1;
    if ( v13 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v16);
  }
  Scaleform::RefCountNTSImpl::Release(v6);
}

// File Line: 328
// RVA: 0x80A660
void __fastcall Scaleform::GFx::AS3::Stage::PropagateMouseEvent(
        Scaleform::GFx::AS3::Stage *this,
        Scaleform::GFx::EventId *id)
{
  if ( this )
    ++this->RefCount;
  if ( id->Id == 8 && this->pASRoot->pMovieImpl->MouseCursorCount )
    Scaleform::GFx::InteractiveObject::DoMouseDrag(this, id->ControllerIndex);
  if ( this )
    Scaleform::RefCountNTSImpl::Release(this);
}

// File Line: 351
// RVA: 0x7BE080
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Stage::CreateNewInstanceName(
        Scaleform::GFx::AS3::Stage *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringManager *v4; // rax
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v11; // [rsp+48h] [rbp+10h]

  v11 = result;
  pObject = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v4 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pObject->vfptr[59].__vecDelDtor)(pObject);
  v5 = Scaleform::GFx::ASStringManager::CreateEmptyString(v4, &resulta);
  pNode = v5->pNode;
  result->pNode = v5->pNode;
  ++pNode->RefCount;
  v7 = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  return result;
}

// File Line: 412
// RVA: 0x7E7480
__int64 __fastcall Scaleform::GFx::AS3::Stage::GetCurrentFrame(Scaleform::GFx::AS3::Stage *this)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // rcx

  pObject = this->pRoot.pObject;
  if ( pObject )
    return ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))pObject->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[107].__vecDelDtor)(pObject);
  else
    return 0i64;
}

// File Line: 419
// RVA: 0x7EB8C0
bool __fastcall Scaleform::GFx::AS3::Stage::GetLabeledFrame(
        Scaleform::GFx::AS3::Stage *this,
        const char *plabel,
        unsigned int *frameNumber,
        __int64 translateNumbers)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // rcx

  pObject = this->pRoot.pObject;
  if ( pObject )
    return ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, const char *, unsigned int *, __int64))pObject->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[108].__vecDelDtor)(
             pObject,
             plabel,
             frameNumber,
             translateNumbers);
  else
    return 0;
}

// File Line: 426
// RVA: 0x7E9990
Scaleform::String *__fastcall Scaleform::GFx::AS3::Stage::GetFrameLabel(
        Scaleform::GFx::AS3::Stage *this,
        __int64 fr,
        unsigned int *pdestfr)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // rcx

  pObject = this->pRoot.pObject;
  if ( pObject )
    return (Scaleform::String *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, __int64, unsigned int *))pObject->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[109].__vecDelDtor)(
                                  pObject,
                                  fr,
                                  pdestfr);
  else
    return 0i64;
}

// File Line: 433
// RVA: 0x7F1DE0
void __fastcall Scaleform::GFx::AS3::Stage::GotoFrame(Scaleform::GFx::AS3::Stage *this, __int64 targetFrameNumber)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // rcx

  pObject = this->pRoot.pObject;
  if ( pObject )
    pObject->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[110].__vecDelDtor(
      pObject,
      targetFrameNumber);
}

// File Line: 452
// RVA: 0x804180
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::AvmStage::OnEventUnload(Scaleform::GFx::AS3::AvmStage *this)
{
  Scaleform::GFx::AS3::AvmDisplayObjContainer::OnEventUnload(this);
}

