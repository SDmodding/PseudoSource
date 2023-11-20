// File Line: 69
// RVA: 0x7B0190
void __fastcall Scaleform::GFx::AS3::FrameCounter::AdvanceFrame(Scaleform::GFx::AS3::FrameCounter *this, bool nextFrame, float framePos)
{
  Scaleform::GFx::AS3::FrameCounter *v3; // rdi
  Scaleform::GFx::ASMovieRootBase *v4; // rbx
  unsigned int v5; // edx
  Scaleform::RefCountImplCoreVtbl *v6; // rax

  if ( nextFrame )
  {
    v3 = this;
    v4 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v5 = v4[22].RefCount;
    if ( v5 )
    {
      Scaleform::GFx::AS3::VM::ExecuteCode((Scaleform::GFx::AS3::VM *)v4[2].vfptr, v5);
      v6 = v4[2].vfptr;
      if ( LOBYTE(v6[21].__vecDelDtor) )
        LOBYTE(v6[21].__vecDelDtor) = 0;
      v4[22].RefCount = 0;
    }
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue((Scaleform::GFx::AS3::MovieRoot *)v4, 0);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue((Scaleform::GFx::AS3::MovieRoot *)v4, AL_High);
    Scaleform::GFx::AS3::FrameCounter::QueueFrameActions(v3);
    Scaleform::GFx::AS3::MovieRoot::RequeueActionQueue((Scaleform::GFx::AS3::MovieRoot *)v4, AL_Count_, AL_Frame);
  }
}

// File Line: 100
// RVA: 0x80B960
void __fastcall Scaleform::GFx::AS3::FrameCounter::QueueFrameActions(Scaleform::GFx::AS3::FrameCounter *this)
{
  Scaleform::GFx::AS3::FrameCounter *v1; // rbx
  Scaleform::GFx::ASMovieRootBase *v2; // rsi
  Scaleform::GFx::InteractiveObject *i; // rbx
  signed __int64 v4; // rdi
  unsigned int v5; // eax
  Scaleform::GFx::InteractiveObject *j; // rbx
  signed __int64 v7; // rdi
  unsigned int v8; // eax

  v1 = this;
  v2 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  Scaleform::GFx::AS3::EventChains::QueueEvents(
    (Scaleform::GFx::AS3::EventChains *)&v2[8].pASSupport,
    Event_FrameConstructed);
  if ( (v1->pASRoot->pMovieImpl->Flags >> 19) & 1 )
  {
    for ( i = v1->pPlayPrev; i; i = i->pPlayPrev )
    {
      *((_BYTE *)&i->CreateFrame + 4 * (unsigned __int8)i->AvmObjOffset) |= 2u;
      if ( (i->Flags >> 10) & 1 )
      {
        v4 = (signed __int64)i + 4 * (unsigned __int8)i->AvmObjOffset;
        if ( *(_BYTE *)(v4 + 104) & 2 )
        {
          v5 = (*(__int64 (**)(void))(**(_QWORD **)(v4 + 24) + 856i64))();
          Scaleform::GFx::AS3::AvmSprite::QueueFrameScript((Scaleform::GFx::AS3::AvmSprite *)v4, v5);
          *(_BYTE *)(v4 + 104) &= 0xFDu;
        }
      }
    }
  }
  else
  {
    for ( j = v1->pPlayPrevOpt; j; j = j->pPlayPrevOpt )
    {
      *((_BYTE *)&j->CreateFrame + 4 * (unsigned __int8)j->AvmObjOffset) |= 2u;
      if ( (j->Flags >> 10) & 1 )
      {
        v7 = (signed __int64)j + 4 * (unsigned __int8)j->AvmObjOffset;
        if ( *(_BYTE *)(v7 + 104) & 2 )
        {
          v8 = (*(__int64 (**)(void))(**(_QWORD **)(v7 + 24) + 856i64))();
          Scaleform::GFx::AS3::AvmSprite::QueueFrameScript((Scaleform::GFx::AS3::AvmSprite *)v7, v8);
          *(_BYTE *)(v7 + 104) &= 0xFDu;
        }
      }
    }
  }
  Scaleform::GFx::AS3::EventChains::QueueEvents((Scaleform::GFx::AS3::EventChains *)&v2[8].pASSupport, Event_ExitFrame);
}

// File Line: 154
// RVA: 0x782140
void __fastcall Scaleform::GFx::AS3::Stage::Stage(Scaleform::GFx::AS3::Stage *this, Scaleform::GFx::MovieDefImpl *pbindingDefImpl, Scaleform::GFx::ASMovieRootBase *pasRoot, Scaleform::GFx::InteractiveObject *pparent, Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::AS3::Stage *v5; // rdi
  Scaleform::GFx::ASStringManager *v6; // rax

  v5 = this;
  id.Id = **(_DWORD **)&id.Id;
  Scaleform::GFx::DisplayObjContainer::DisplayObjContainer(
    (Scaleform::GFx::DisplayObjContainer *)&this->vfptr,
    pbindingDefImpl,
    pasRoot,
    pparent,
    (Scaleform::GFx::ResourceId)&id);
  v5->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::Stage::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  v5->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::Stage::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  v5->pRoot.pObject = 0i64;
  v5->FrameCounterObj.pObject = 0i64;
  v6 = Scaleform::GFx::InteractiveObject::GetStringManager((Scaleform::GFx::InteractiveObject *)&v5->vfptr);
  Scaleform::GFx::ASStringManager::CreateEmptyString(v6, &v5->CurrentStageOrientation);
  v5->MouseCursorEventCnt = 0;
  v5->Flags |= 0x2000u;
  v5->Flags |= 1u;
}

// File Line: 160
// RVA: 0x78E1A0
void __fastcall Scaleform::GFx::AS3::Stage::~Stage(Scaleform::GFx::AS3::Stage *this)
{
  Scaleform::GFx::AS3::Stage *v1; // rbx
  Scaleform::GFx::ASStringNode *v2; // rcx
  bool v3; // zf
  Scaleform::RefCountNTSImpl *v4; // rcx
  Scaleform::RefCountNTSImpl *v5; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::Stage::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::Stage::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  v2 = this->CurrentStageOrientation.pNode;
  v3 = v2->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v2);
  v4 = (Scaleform::RefCountNTSImpl *)&v1->FrameCounterObj.pObject->vfptr;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  v5 = (Scaleform::RefCountNTSImpl *)&v1->pRoot.pObject->vfptr;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer((Scaleform::GFx::DisplayObjContainer *)&v1->vfptr);
}

// File Line: 164
// RVA: 0x804960
void __fastcall Scaleform::GFx::AS3::Stage::OnInsertionAsLevel(Scaleform::GFx::AS3::Stage *this, int level)
{
  int v2; // esi
  Scaleform::GFx::AS3::Stage *v3; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rdi
  Scaleform::RefCountNTSImpl *v5; // rcx
  int v6; // [rsp+70h] [rbp+18h]
  Scaleform::GFx::ResourceId v7; // [rsp+78h] [rbp+20h]

  v2 = level;
  v3 = this;
  v6 = 322;
  v4 = (Scaleform::GFx::InteractiveObject *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              224ui64,
                                              (Scaleform::AllocInfo *)&v6);
  if ( v4 )
  {
    v7.Id = 0;
    Scaleform::GFx::InteractiveObject::InteractiveObject(
      v4,
      v3->pDefImpl.pObject,
      v3->pASRoot,
      0i64,
      (Scaleform::GFx::ResourceId)&v7);
    v4->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::FrameCounter::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
    v4->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::FrameCounter::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
    v4[1].vfptr = 0i64;
  }
  else
  {
    v4 = 0i64;
  }
  v5 = (Scaleform::RefCountNTSImpl *)&v3->FrameCounterObj.pObject->vfptr;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  v3->FrameCounterObj.pObject = v4;
  Scaleform::GFx::InteractiveObject::AddToPlayList(v4);
  Scaleform::GFx::DisplayObjContainer::OnInsertionAsLevel((Scaleform::GFx::DisplayObjContainer *)&v3->vfptr, v2);
}

// File Line: 172
// RVA: 0x7D7770
void __fastcall Scaleform::GFx::AS3::Stage::ForceShutdown(Scaleform::GFx::AS3::Stage *this)
{
  Scaleform::GFx::AS3::Stage *v1; // rbx
  Scaleform::GFx::DisplayObjContainer *v2; // rcx
  Scaleform::RefCountNTSImpl *v3; // rcx

  v1 = this;
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this->FrameCounterObj.pObject);
  Scaleform::GFx::DisplayList::Clear(&v1->mDisplayList, (Scaleform::GFx::DisplayObjectBase *)&v1->vfptr);
  _((AMD_HD3D *)v1);
  v2 = v1->pRoot.pObject;
  if ( v2 )
    ((void (*)(void))v2->vfptr[60].__vecDelDtor)();
  v3 = (Scaleform::RefCountNTSImpl *)&v1->pRoot.pObject->vfptr;
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  v1->pRoot.pObject = 0i64;
  Scaleform::GFx::DisplayObjContainer::ForceShutdown((Scaleform::GFx::DisplayObjContainer *)&v1->vfptr);
}

// File Line: 182
// RVA: 0x7CE8A0
void __fastcall Scaleform::GFx::AS3::Stage::ExecuteFrame0Events(Scaleform::GFx::AS3::Stage *this)
{
  Scaleform::GFx::AS3::Stage *v1; // r14
  Scaleform::GFx::ASMovieRootBase *v2; // r10
  Scaleform::GFx::ASMovieRootBase *v3; // rbp
  Scaleform::GFx::MovieDefImpl *v4; // r8
  Scaleform::GFx::ASSupport *v5; // rcx
  signed int v6; // ST28_4
  Scaleform::GFx::Sprite *v7; // rsi
  unsigned __int8 v8; // al
  __int64 v9; // rax
  Scaleform::GFx::ASStringManager *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::RefCountNTSImpl *v14; // rcx
  __int64 v15; // rax
  Scaleform::Render::TreeNode *v16; // r12
  signed __int64 v17; // rcx
  Scaleform::GFx::AS3::Class *v18; // rax
  Scaleform::GFx::AS3::Class *v19; // r15
  __int64 v20; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v21; // rdi
  bool v22; // al
  Scaleform::GFx::ASStringNode *v23; // rbx
  unsigned int v24; // eax
  __int64 v25; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v26; // rdi
  bool v27; // al
  Scaleform::GFx::ASStringNode *v28; // rbx
  unsigned int v29; // eax
  Scaleform::GFx::AS3::WeakProxy *v30; // rdx
  unsigned int v31; // edx
  Scaleform::GFx::AS3::VM *v32; // rcx
  Scaleform::GFx::AS3::Value *v33; // rbx
  signed __int64 v34; // rcx
  unsigned int v35; // eax
  Scaleform::StringDataPtr gname; // [rsp+38h] [rbp-60h]
  __int64 v37; // [rsp+48h] [rbp-50h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+8h]
  Scaleform::GFx::AS3::Class *v39; // [rsp+A8h] [rbp+10h]
  Scaleform::GFx::Sprite *v40; // [rsp+B0h] [rbp+18h]
  __int64 v41; // [rsp+B8h] [rbp+20h]

  v1 = this;
  v2 = this->pASRoot;
  v3 = v2->pMovieImpl->pASMovieRoot.pObject;
  v4 = this->pDefImpl.pObject;
  gname.pStr = (const char *)v4->pBindData.pObject->pDataDef.pObject;
  gname.Size = (unsigned __int64)v4;
  v37 = 0i64;
  v5 = v2->pASSupport.pObject;
  LODWORD(result.pNode) = 0;
  v6 = 3;
  v7 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::StringDataPtr *, Scaleform::GFx::AS3::Stage *, Scaleform::GFx::ASString *, signed int, signed __int64, const char *, Scaleform::GFx::MovieDefImpl *, _QWORD))v5->vfptr[4].__vecDelDtor)(
                                   v5,
                                   v2->pMovieImpl,
                                   &gname,
                                   v1,
                                   &result,
                                   v6,
                                   -2i64,
                                   gname.pStr,
                                   v4,
                                   0i64);
  Scaleform::GFx::Sprite::SetLoadedSeparately(v7, 1);
  v7->Flags |= 0x800u;
  v40 = v7;
  v7->Flags |= 0x2000u;
  v7->Flags |= 0x1000u;
  v8 = v7->AvmObjOffset;
  if ( v8 )
  {
    v9 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v7->vfptr + 4 * v8))[2].__vecDelDtor)();
    (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v9 + 224i64))(v9, 0i64);
  }
  v10 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v1->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
  v11 = Scaleform::GFx::ASStringManager::CreateConstString(v10, &result, "root1");
  v7->vfptr[124].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v7->vfptr, (unsigned int)v11);
  v12 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v7->Flags |= 1u;
  ++v7->RefCount;
  v14 = (Scaleform::RefCountNTSImpl *)&v1->pRoot.pObject->vfptr;
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release(v14);
  v1->pRoot.pObject = (Scaleform::GFx::DisplayObjContainer *)&v7->vfptr;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Stage *))v1->vfptr[39].__vecDelDtor)(v1);
  ((void (__fastcall *)(Scaleform::GFx::Sprite *))v7->vfptr[39].__vecDelDtor)(v7);
  v15 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Stage *))v1->vfptr[69].__vecDelDtor)(v1);
  v16 = (Scaleform::Render::TreeNode *)v15;
  if ( v15 )
    ++*(_QWORD *)(v15 + 8);
  v41 = v15;
  Scaleform::GFx::DisplayList::AddEntryAtIndex(
    &v1->mDisplayList,
    (Scaleform::GFx::DisplayObjectBase *)&v1->vfptr,
    LODWORD(v1->mDisplayList.DisplayObjectArray.Data.Size),
    (Scaleform::GFx::DisplayObjectBase *)&v7->vfptr);
  Scaleform::Render::TreeContainer::Insert(
    (Scaleform::Render::TreeContainer *)&v1->pASRoot->pMovieImpl->pRenderRoot.pObject->0,
    0i64,
    v16);
  v7->pParent = (Scaleform::GFx::InteractiveObject *)&v1->vfptr;
  Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)&v7->vfptr);
  v17 = (signed __int64)v1 + 4 * (unsigned __int8)v1->AvmObjOffset;
  v3[22].RefCount += (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v17 + 112i64))(v17, 0i64);
  gname.pStr = "flash.display.LoaderInfo";
  gname.Size = 24i64;
  v18 = Scaleform::GFx::AS3::VM::GetClass(
          (Scaleform::GFx::AS3::VM *)v3[2].vfptr,
          &gname,
          (Scaleform::GFx::AS3::VMAppDomain *)v3[2].vfptr[52].__vecDelDtor);
  v19 = v18;
  v39 = v18;
  if ( v18 )
    v18->RefCount = (v18->RefCount + 1) & 0x8FBFFFFF;
  if ( v18 )
  {
    v20 = (unsigned __int8)v1->AvmObjOffset;
    v21 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)((char *)&v1->pWeakProxy + 4 * v20);
    if ( !v21 )
      v21 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(&v1->RefCount + v20);
    if ( (unsigned __int8)v21 & 1 )
      v21 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v21 - 1);
    result.pNode = 0i64;
    v22 = Scaleform::GFx::AS3::ASVM::_constructInstance(
            (Scaleform::GFx::AS3::ASVM *)v3[2].vfptr,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
            (Scaleform::GFx::AS3::Object *)&v19->vfptr,
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
      if ( (unsigned __int8)v23 & 1 )
      {
        result.pNode = (Scaleform::GFx::ASStringNode *)((char *)v23 - 1);
      }
      else
      {
        v24 = v23->Size;
        if ( v24 & 0x3FFFFF )
        {
          v23->Size = v24 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v23);
        }
      }
    }
  }
  Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor((Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v7
                                                                                                  + 4 * (unsigned __int8)v7->AvmObjOffset));
  if ( v19 )
  {
    v25 = (unsigned __int8)v7->AvmObjOffset;
    v26 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)((char *)&v7->pWeakProxy + 4 * v25);
    if ( !v26 )
      v26 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(&v7->RefCount + v25);
    if ( (unsigned __int8)v26 & 1 )
      v26 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v26 - 1);
    result.pNode = 0i64;
    v27 = Scaleform::GFx::AS3::ASVM::_constructInstance(
            (Scaleform::GFx::AS3::ASVM *)v3[2].vfptr,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
            (Scaleform::GFx::AS3::Object *)&v19->vfptr,
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
      if ( (unsigned __int8)v28 & 1 )
      {
        result.pNode = (Scaleform::GFx::ASStringNode *)((char *)v28 - 1);
      }
      else
      {
        v29 = v28->Size;
        if ( v29 & 0x3FFFFF )
        {
          v28->Size = v29 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v28);
        }
      }
    }
  }
  Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(
    (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v7 + 4 * (unsigned __int8)v7->AvmObjOffset),
    1);
  if ( !(*(_BYTE *)(&v7->ClipDepth + 2 * (unsigned __int8)v7->AvmObjOffset) & 4) )
    ((void (__fastcall *)(Scaleform::GFx::Sprite *))v7->vfptr[112].__vecDelDtor)(v7);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
    (Scaleform::GFx::AS3::MovieRoot *)v1->pASRoot->pMovieImpl->pASMovieRoot.pObject,
    0);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
    (Scaleform::GFx::AS3::MovieRoot *)v1->pASRoot->pMovieImpl->pASMovieRoot.pObject,
    AL_High);
  *((_BYTE *)&v7->ClipDepth + 4 * (unsigned __int8)v7->AvmObjOffset) |= 4u;
  while ( v3[22].RefCount )
  {
    v31 = v3[22].RefCount;
    v3[22].RefCount = 0;
    Scaleform::GFx::AS3::VM::ExecuteCode((Scaleform::GFx::AS3::VM *)v3[2].vfptr, v31);
    v32 = (Scaleform::GFx::AS3::VM *)v3[2].vfptr;
    if ( v32->HandleException )
    {
      v32->HandleException = 0;
      v33 = &v32->ExceptionObj;
      Scaleform::GFx::AS3::VM::OutputError(v32, &v32->ExceptionObj);
      if ( (v33->Flags & 0x1F) > 9 )
      {
        if ( (v33->Flags >> 9) & 1 )
        {
          v30 = v33->Bonus.pWeakProxy;
          v13 = v30->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v33->Bonus.pWeakProxy = 0i64;
          v33->value.VNumber = 0.0;
          v33->value.VS._2.VObj = 0i64;
          v33->Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v33);
        }
      }
      v33->Flags &= 0xFFFFFFE0;
      v1->FrameCounterObj.pObject->Flags |= 0x20u;
    }
  }
  if ( v7->pParent )
  {
    v34 = (signed __int64)v7 + 4 * (unsigned __int8)v7->AvmObjOffset;
    LOBYTE(v30) = 1;
    (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS3::WeakProxy *))(*(_QWORD *)v34 + 152i64))(v34, v30);
  }
  v1->pASRoot->pMovieImpl->Flags |= 0x80000u;
  LOBYTE(v30) = 1;
  v1->FrameCounterObj.pObject->vfptr[71].__vecDelDtor(
    (Scaleform::RefCountNTSImplCore *)&v1->FrameCounterObj.pObject->vfptr,
    (unsigned int)v30);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
    (Scaleform::GFx::AS3::MovieRoot *)v1->pASRoot->pMovieImpl->pASMovieRoot.pObject,
    AL_Frame);
  if ( v19 )
  {
    if ( (unsigned __int8)v19 & 1 )
    {
      v39 = (Scaleform::GFx::AS3::Class *)((char *)v19 - 1);
    }
    else
    {
      v35 = v19->RefCount;
      if ( v35 & 0x3FFFFF )
      {
        v19->RefCount = v35 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v19->vfptr);
      }
    }
  }
  if ( v16 )
  {
    v13 = v16->RefCount-- == 1;
    if ( v13 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v16->0);
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v7->vfptr);
}

// File Line: 328
// RVA: 0x80A660
void __fastcall Scaleform::GFx::AS3::Stage::PropagateMouseEvent(Scaleform::GFx::AS3::Stage *this, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::AS3::Stage *v2; // rbx

  v2 = this;
  if ( this )
    ++this->RefCount;
  if ( id->Id == 8 && this->pASRoot->pMovieImpl->MouseCursorCount )
    Scaleform::GFx::InteractiveObject::DoMouseDrag(
      (Scaleform::GFx::InteractiveObject *)&this->vfptr,
      id->ControllerIndex);
  if ( v2 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v2->vfptr);
}

// File Line: 351
// RVA: 0x7BE080
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Stage::CreateNewInstanceName(Scaleform::GFx::AS3::Stage *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::ASMovieRootBase *v3; // rcx
  Scaleform::GFx::ASStringManager *v4; // rax
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString *v11; // [rsp+48h] [rbp+10h]

  v11 = result;
  v2 = result;
  v3 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v4 = (Scaleform::GFx::ASStringManager *)((__int64 (__cdecl *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::ASString *))v3->vfptr[59].__vecDelDtor)(
                                            v3,
                                            result);
  v5 = Scaleform::GFx::ASStringManager::CreateEmptyString(v4, &resulta);
  v6 = v5->pNode;
  v2->pNode = v5->pNode;
  ++v6->RefCount;
  v7 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  return v2;
}

// File Line: 412
// RVA: 0x7E7480
__int64 __fastcall Scaleform::GFx::AS3::Stage::GetCurrentFrame(Scaleform::GFx::AS3::Stage *this)
{
  Scaleform::GFx::DisplayObjContainer *v1; // rcx
  __int64 result; // rax

  v1 = this->pRoot.pObject;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr[107].__vecDelDtor)();
  else
    result = 0i64;
  return result;
}

// File Line: 419
// RVA: 0x7EB8C0
bool __fastcall Scaleform::GFx::AS3::Stage::GetLabeledFrame(Scaleform::GFx::AS3::Stage *this, const char *plabel, unsigned int *frameNumber, __int64 translateNumbers)
{
  Scaleform::GFx::DisplayObjContainer *v4; // rcx
  bool result; // al

  v4 = this->pRoot.pObject;
  if ( v4 )
    result = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, const char *, unsigned int *, __int64))v4->vfptr[108].__vecDelDtor)(
               v4,
               plabel,
               frameNumber,
               translateNumbers);
  else
    result = 0;
  return result;
}

// File Line: 426
// RVA: 0x7E9990
Scaleform::String *__fastcall Scaleform::GFx::AS3::Stage::GetFrameLabel(Scaleform::GFx::AS3::Stage *this, __int64 fr, unsigned int *pdestfr)
{
  Scaleform::GFx::DisplayObjContainer *v3; // rcx
  Scaleform::String *result; // rax

  v3 = this->pRoot.pObject;
  if ( v3 )
    result = (Scaleform::String *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, __int64, unsigned int *))v3->vfptr[109].__vecDelDtor)(
                                    v3,
                                    fr,
                                    pdestfr);
  else
    result = 0i64;
  return result;
}

// File Line: 433
// RVA: 0x7F1DE0
void __fastcall Scaleform::GFx::AS3::Stage::GotoFrame(Scaleform::GFx::AS3::Stage *this, __int64 targetFrameNumber)
{
  Scaleform::GFx::DisplayObjContainer *v2; // rcx

  v2 = this->pRoot.pObject;
  if ( v2 )
    v2->vfptr[110].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, targetFrameNumber);
}

// File Line: 452
// RVA: 0x804180
void __fastcall Scaleform::GFx::AS3::AvmStage::OnEventUnload(Scaleform::GFx::AS3::AvmStage *this)
{
  Scaleform::GFx::AS3::AvmDisplayObjContainer::OnEventUnload((Scaleform::GFx::AS3::AvmDisplayObjContainer *)&this->vfptr);
}

