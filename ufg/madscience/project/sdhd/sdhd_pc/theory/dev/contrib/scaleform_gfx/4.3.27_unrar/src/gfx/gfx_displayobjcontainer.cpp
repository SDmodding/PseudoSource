// File Line: 33
// RVA: 0x8954C0
void __fastcall Scaleform::GFx::DisplayObjContainer::DisplayObjContainer(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        Scaleform::GFx::DisplayList *id)
{
  LODWORD(id) = id->DisplayObjectArray.Data.Data;
  Scaleform::GFx::InteractiveObject::InteractiveObject(
    this,
    pbindingDefImpl,
    pasRoot,
    pparent,
    (Scaleform::GFx::ResourceId)&id);
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  id = &this->mDisplayList;
  this->mDisplayList.DisplayObjectArray.Data.Data = 0i64;
  this->mDisplayList.DisplayObjectArray.Data.Size = 0i64;
  this->mDisplayList.DisplayObjectArray.Data.Policy.Capacity = 0i64;
  this->mDisplayList.DepthToIndexMap = 0i64;
  this->mDisplayList.pCachedChar = 0i64;
  this->mDisplayList.ModId = 0;
  this->mDisplayList.Flags = 0;
  this->pRootNode = 0i64;
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x200u;
}

// File Line: 38
// RVA: 0x8A3C20
void __fastcall Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::MovieDefRootNode *pRootNode; // rax
  Scaleform::GFx::MovieDefRootNode *v3; // rdx
  Scaleform::GFx::MovieDefRootNode *v4; // rcx

  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  pRootNode = this->pRootNode;
  if ( pRootNode )
  {
    --pRootNode->SpriteRefCount;
    v3 = this->pRootNode;
    if ( !v3->SpriteRefCount )
    {
      v3->pPrev->pNext = v3->pNext;
      v3->pNext->pPrev = v3->pPrev;
      v4 = this->pRootNode;
      if ( v4 )
        v4->vfptr->__vecDelDtor(v4, 1u);
    }
  }
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, this);
  Scaleform::GFx::DisplayList::~DisplayList(&this->mDisplayList);
  Scaleform::GFx::InteractiveObject::~InteractiveObject(this);
}

// File Line: 53
// RVA: 0x8B6980
void __fastcall Scaleform::GFx::DisplayObjContainer::AssignRootNode(
        Scaleform::GFx::DisplayObjContainer *this,
        bool importFlag)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  Scaleform::GFx::MovieDefRootNode *pNext; // rax
  Scaleform::List<Scaleform::GFx::MovieDefRootNode,Scaleform::GFx::MovieDefRootNode> *p_RootMovieDefNodes; // r8
  Scaleform::GFx::FontManager *v7; // rdi
  Scaleform::GFx::MovieDefRootNode *v8; // rcx
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rcx
  Scaleform::MemoryHeap *pHeap; // r14
  unsigned int v11; // eax
  Scaleform::GFx::FontManager *v12; // rax
  Scaleform::GFx::FontManager *v13; // rax
  Scaleform::GFx::MovieDefRootNode *pRootNode; // rsi
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::MovieDefRootNode *v16; // rdx
  Scaleform::GFx::MovieImpl *v17; // rcx

  if ( !this->pRootNode )
  {
    pMovieImpl = this->pASRoot->pMovieImpl;
    pNext = pMovieImpl->RootMovieDefNodes.Root.pNext;
    p_RootMovieDefNodes = &pMovieImpl->RootMovieDefNodes;
    v7 = 0i64;
    while ( 1 )
    {
      v8 = (Scaleform::GFx::MovieDefRootNode *)&p_RootMovieDefNodes[-1].Root.8;
      if ( !p_RootMovieDefNodes )
        v8 = 0i64;
      if ( pNext == v8 )
        break;
      if ( pNext->pDefImpl == this->pDefImpl.pObject && pNext->ImportFlag == importFlag )
      {
        ++pNext->SpriteRefCount;
        this->pRootNode = pNext;
        break;
      }
      pNext = pNext->pNext;
    }
    if ( !this->pRootNode )
    {
      pASRoot = this->pASRoot;
      pHeap = pASRoot->pMovieImpl->pHeap;
      this->pRootNode = (Scaleform::GFx::MovieDefRootNode *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::MemoryHeap *, Scaleform::GFx::MovieDefImpl *, bool, __int64))pASRoot->vfptr[6].__vecDelDtor)(
                                                              pASRoot,
                                                              pHeap,
                                                              this->pDefImpl.pObject,
                                                              importFlag,
                                                              -2i64);
      this->pRootNode->BytesLoaded = this->pDefImpl.pObject->pBindData.pObject->BytesLoaded;
      if ( importFlag )
        v11 = 0;
      else
        v11 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))this->pDefImpl.pObject->Scaleform::GFx::InteractiveObject::vfptr[1].GetKey)(this->pDefImpl.pObject);
      this->pRootNode->LoadingFrame = v11;
      v12 = (Scaleform::GFx::FontManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pHeap->vfptr->Alloc)(
                                             pHeap,
                                             104i64);
      if ( v12 )
      {
        Scaleform::GFx::FontManager::FontManager(
          v12,
          this->pASRoot->pMovieImpl,
          this->pDefImpl.pObject,
          this->pASRoot->pMovieImpl->pFontManagerStates.pObject);
        v7 = v13;
      }
      pRootNode = this->pRootNode;
      pObject = (Scaleform::Render::RenderBuffer *)pRootNode->pFontManager.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      pRootNode->pFontManager.pObject = v7;
      v16 = this->pRootNode;
      v17 = this->pASRoot->pMovieImpl;
      v16->pNext = v17->RootMovieDefNodes.Root.pNext;
      v16->pPrev = (Scaleform::GFx::MovieDefRootNode *)&v17->MovieLevels.Data.Policy;
      v17->RootMovieDefNodes.Root.pNext->pPrev = v16;
      v17->RootMovieDefNodes.Root.pNext = v16;
    }
  }
}

// File Line: 99
// RVA: 0x8CD4C0
Scaleform::GFx::MovieDefRootNode *__fastcall Scaleform::GFx::DisplayObjContainer::FindRootNode(
        Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::DisplayObjContainer *v1; // rax

  while ( this )
  {
    v1 = 0i64;
    if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x200) != 0 )
      v1 = this;
    if ( v1 && v1->pRootNode )
      return v1->pRootNode;
    this = (Scaleform::GFx::DisplayObjContainer *)this->pParent;
  }
  return 0i64;
}

// File Line: 117
// RVA: 0x8ED210
void __fastcall Scaleform::GFx::DisplayObjContainer::OnInsertionAsLevel(
        Scaleform::GFx::DisplayObjContainer *this,
        __int64 level)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // rcx
  unsigned __int16 Flags; // cx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  Scaleform::GFx::InteractiveObject *pPlayListHead; // rax
  unsigned int v7; // ecx
  int v8; // eax

  if ( (_DWORD)level )
  {
    if ( (int)level > 0 )
    {
      pMainMovie = this->pASRoot->pMovieImpl->pMainMovie;
      if ( pMainMovie )
      {
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[88].__vecDelDtor)(pMainMovie) )
        {
          this->Scaleform::GFx::InteractiveObject::Flags |= 0x180u;
        }
        else
        {
          this->Scaleform::GFx::InteractiveObject::Flags &= ~0x80u;
          this->Scaleform::GFx::InteractiveObject::Flags |= 0x100u;
        }
      }
    }
  }
  else
  {
    this->Scaleform::GFx::InteractiveObject::Flags |= 0x180u;
  }
  Flags = this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
  if ( (Flags & 0x10) == 0 && (Flags & 0x1000) == 0 && this->Depth >= -1 )
  {
    pMovieImpl = this->pASRoot->pMovieImpl;
    pPlayListHead = pMovieImpl->pPlayListHead;
    if ( pPlayListHead )
    {
      pPlayListHead->pPlayPrev = this;
      this->pPlayNext = pMovieImpl->pPlayListHead;
    }
    pMovieImpl->pPlayListHead = this;
  }
  v7 = this->Scaleform::GFx::InteractiveObject::Flags;
  if ( (v7 & 0x200000) == 0 || (v7 & 0x400000) != 0 )
    level = 0i64;
  else
    LOBYTE(level) = 1;
  v8 = (int)this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
              this,
              level);
  if ( v8 == -1 )
  {
    this->Scaleform::GFx::InteractiveObject::Flags |= 0x400000u;
  }
  else if ( v8 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
    this->FocusGroupMask = -1;
    return;
  }
  this->FocusGroupMask = -1;
}

// File Line: 137
// RVA: 0x8EBA90
void __fastcall Scaleform::GFx::DisplayObjContainer::MoveDisplayObject(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::CharPosInfo *pos)
{
  Scaleform::GFx::DisplayList::MoveDisplayObject(&this->mDisplayList, this, pos);
}

// File Line: 144
// RVA: 0x8BE640
void __fastcall Scaleform::GFx::DisplayObjContainer::CreateAndReplaceDisplayObject(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::CharPosInfo *pos,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::DisplayObjectBase **newChar)
{
  Scaleform::GFx::DisplayObjectBase *CharacterAtDepth; // rax
  Scaleform::RefCountNTSImpl *v9; // rbx
  int v10; // r15d
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rdx
  Scaleform::GFx::ASSupport *pObject; // rcx
  Scaleform::GFx::DisplayObjectBase *v13; // r14
  Scaleform::GFx::DisplayObjectBase *v14; // rdi
  __int64 v15; // rdx
  Scaleform::GFx::CharacterCreateInfo v16[3]; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::GFx::ResourceId id; // [rsp+A0h] [rbp+8h] BYREF
  Scaleform::GFx::DisplayObjectBase *v18; // [rsp+A8h] [rbp+10h]

  id.Id = pos->CharacterId.Id;
  Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(this->pDefImpl.pObject, v16, (Scaleform::GFx::ResourceId)&id);
  if ( v16[0].pCharDef )
  {
    id.Id = pos->CharacterId.Id;
    CharacterAtDepth = Scaleform::GFx::DisplayList::GetCharacterAtDepth(
                         &this->mDisplayList,
                         pos->Depth,
                         (Scaleform::GFx::ResourceId)&id,
                         0i64);
    v9 = CharacterAtDepth;
    if ( CharacterAtDepth )
      ++CharacterAtDepth->RefCount;
    v18 = CharacterAtDepth;
    v10 = -1;
    if ( CharacterAtDepth && CharacterAtDepth->Depth >= -1 )
      v10 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))CharacterAtDepth->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(CharacterAtDepth);
    pASRoot = this->pASRoot;
    pObject = pASRoot->pASSupport.pObject;
    id.Id = pos->CharacterId.Id;
    v13 = 0i64;
    v14 = (Scaleform::GFx::DisplayObjectBase *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::ResourceId *, _DWORD, __int64))pObject->vfptr[4].__vecDelDtor)(
                                                 pObject,
                                                 pASRoot->pMovieImpl,
                                                 v16,
                                                 this,
                                                 &id,
                                                 0,
                                                 -2i64);
    Scaleform::GFx::DisplayObjContainer::ReplaceDisplayObject(this, pos, v14, name);
    if ( v10 > -1 )
    {
      LOBYTE(v15) = v10 != 0;
      v14->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[58].__vecDelDtor(
        v14,
        v15);
    }
    if ( newChar )
    {
      if ( v14->RefCount > 1 )
        v13 = v14;
      *newChar = v13;
    }
    if ( v14 )
      Scaleform::RefCountNTSImpl::Release(v14);
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogError(
      &this->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "DisplayObjContainer::ReplaceDisplayObject() - unknown cid = %d",
      LOWORD(pos->CharacterId.Id));
  }
}

// File Line: 179
// RVA: 0x900090
void __fastcall Scaleform::GFx::DisplayObjContainer::ReplaceDisplayObject(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::CharPosInfo *pos,
        Scaleform::GFx::DisplayObject *ch,
        Scaleform::GFx::ASString *name)
{
  if ( name->pNode->Size
    && (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x100) != 0 )
  {
    Scaleform::GFx::DisplayObject::SetName(ch, name);
  }
  Scaleform::GFx::DisplayList::ReplaceDisplayObject(&this->mDisplayList, this, pos, ch);
  if ( name->pNode->Size )
  {
    if ( SLOBYTE(ch->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
      this->pASRoot->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::vfptr[39].__vecDelDtor(
        this->pASRoot,
        (unsigned int)ch);
  }
}

// File Line: 211
// RVA: 0x8FF280
void __fastcall Scaleform::GFx::DisplayObjContainer::RemoveDisplayObject(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::DisplayList *p_mDisplayList; // rdi
  signed __int64 v3; // rbx
  unsigned __int64 Size; // r8
  Scaleform::GFx::DisplayObjectBase **i; // rax
  char Flags; // al

  p_mDisplayList = &this->mDisplayList;
  v3 = 0i64;
  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  if ( Size )
  {
    for ( i = &p_mDisplayList->DisplayObjectArray.Data.Data->pCharacter; *i != ch; i += 2 )
    {
      if ( ++v3 >= Size )
        return;
    }
    if ( v3 >= 0 )
    {
      Scaleform::GFx::DisplayList::RemoveFromRenderTree(&this->mDisplayList, this, v3);
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        &p_mDisplayList->DisplayObjectArray,
        v3);
      Flags = p_mDisplayList->Flags;
      ++p_mDisplayList->ModId;
      p_mDisplayList->pCachedChar = 0i64;
      if ( (Flags & 2) != 0 )
        p_mDisplayList->Flags = Flags | 1;
    }
  }
}

// File Line: 221
// RVA: 0x8D62E0
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::DisplayObjContainer::GetChildAt(
        Scaleform::GFx::DisplayObjContainer *this,
        unsigned int index)
{
  if ( index < this->mDisplayList.DisplayObjectArray.Data.Size )
    return this->mDisplayList.DisplayObjectArray.Data.Data[index].pCharacter;
  else
    return 0i64;
}

// File Line: 236
// RVA: 0x8D5FF0
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::DisplayObjContainer::GetCharacterAtDepth(
        Scaleform::GFx::DisplayObjContainer *this,
        int depth)
{
  Scaleform::GFx::DisplayList *p_mDisplayList; // rbx
  unsigned __int64 DisplayIndex; // rax

  p_mDisplayList = &this->mDisplayList;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(&this->mDisplayList, depth);
  if ( DisplayIndex >= p_mDisplayList->DisplayObjectArray.Data.Size
    || p_mDisplayList->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter->Depth != depth
    || DisplayIndex == -1i64 )
  {
    return 0i64;
  }
  else
  {
    return p_mDisplayList->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter;
  }
}

// File Line: 255
// RVA: 0x8F3EA0
void __fastcall Scaleform::GFx::DisplayObjContainer::PropagateMouseEvent(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::EventId *id)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v5; // rax

  if ( this )
    ++this->RefCount;
  if ( id->Id == 8 && this->pASRoot->pMovieImpl->MouseCursorCount )
    Scaleform::GFx::InteractiveObject::DoMouseDrag(this, id->ControllerIndex);
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this) )
  {
    Scaleform::GFx::DisplayList::PropagateMouseEvent(&this->mDisplayList, id);
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v5 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                    + 4 * AvmObjOffset))[5].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
      (*(void (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v5 + 64i64))(v5, id);
    }
  }
  Scaleform::RefCountNTSImpl::Release(this);
}

// File Line: 278
// RVA: 0x8F3D50
void __fastcall Scaleform::GFx::DisplayObjContainer::PropagateKeyEvent(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  if ( this )
    ++this->RefCount;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this) )
  {
    Scaleform::GFx::DisplayList::PropagateKeyEvent(&this->mDisplayList, id, pkeyMask);
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::EventId *, int *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[96].__vecDelDtor)(
      this,
      id,
      pkeyMask);
  }
  Scaleform::RefCountNTSImpl::Release(this);
}

// File Line: 295
// RVA: 0x8B8D80
void __fastcall Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *phitTest,
        Scaleform::Render::Point<float> *pt,
        bool testShape)
{
  unsigned __int64 Size; // rdi
  unsigned __int64 i; // rsi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // r15
  __int64 v10; // rax
  unsigned int v11; // xmm1_4
  unsigned int v12; // xmm0_4
  char *Data; // rbx
  __int64 v14; // r8
  char v15; // al
  unsigned __int64 v16; // rdx
  unsigned __int64 v17; // r8
  Scaleform::GFx::DisplayObjectBase *v18; // rcx
  Scaleform::Render::Matrix2x4<float> v19; // [rsp+20h] [rbp-48h] BYREF
  Scaleform::Render::Point<float> result; // [rsp+70h] [rbp+8h] BYREF

  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[i].pCharacter;
    if ( pCharacter->ClipDepth )
    {
      if ( !phitTest->Size )
      {
        if ( Size > phitTest->Policy.Capacity )
          Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            phitTest,
            phitTest,
            Size + (Size >> 2));
        phitTest->Size = Size;
        memset(phitTest->Data, 1, Size);
      }
      v10 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pCharacter);
      v11 = *(_DWORD *)(v10 + 4);
      v19.M[0][0] = *(float *)v10;
      *(_QWORD *)&v19.M[0][1] = __PAIR64__(*(_DWORD *)(v10 + 8), v11);
      v12 = *(_DWORD *)(v10 + 16);
      v19.M[0][3] = *(float *)(v10 + 12);
      *(_QWORD *)&v19.M[1][0] = __PAIR64__(*(_DWORD *)(v10 + 20), v12);
      *(_QWORD *)&v19.M[1][2] = *(_QWORD *)(v10 + 24);
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v19, &result, pt);
      Data = phitTest->Data;
      LOBYTE(v14) = 1;
      v15 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, __int64))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
              pCharacter,
              &result,
              v14);
      v16 = i + 1;
      Data[i] = v15;
      if ( i + 1 < Size )
      {
        v17 = v16;
        do
        {
          v18 = this->mDisplayList.DisplayObjectArray.Data.Data[v17].pCharacter;
          if ( v18 && v18->Depth > pCharacter->ClipDepth )
            break;
          ++v16;
          ++v17;
          phitTest->Data[v16 - 1] = phitTest->Data[i];
        }
        while ( v16 < Size );
      }
      i = v16 - 1;
    }
  }
}

// File Line: 336
// RVA: 0x8DFA50
__int64 __fastcall Scaleform::GFx::DisplayObjContainer::GetTopMostMouseEntity(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  __int64 v6; // rbx
  Scaleform::GFx::DisplayObject *Mask; // rax
  Scaleform::GFx::DisplayObject *v8; // rsi
  Scaleform::GFx::DisplayObjectBase *v9; // rcx
  float *v10; // rax
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  _OWORD *v15; // rax
  Scaleform::GFx::InteractiveObject *v16; // rcx
  float *v17; // rax
  __int64 v18; // r8
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm7_4
  float v24; // xmm10_4
  float v25; // xmm11_4
  float v26; // xmm12_4
  float v27; // xmm13_4
  float v28; // xmm14_4
  float *v29; // rax
  Scaleform::GFx::DisplayObjectBase *pParent; // rcx
  Scaleform::Render::Matrix3x4<float> *v31; // rax
  __int64 v32; // rax
  Scaleform::Render::ScreenToWorld *p_ScreenToWorld; // rbx
  unsigned __int8 AvmObjOffset; // al
  __int64 v35; // rax
  unsigned int v36; // ebx
  _BYTE pmat[120]; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> phitTest; // [rsp+A8h] [rbp-30h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+C8h] [rbp-10h] BYREF
  __int64 v41; // [rsp+F8h] [rbp+20h]
  Scaleform::Render::Point<float> p; // [rsp+1C8h] [rbp+F0h] BYREF
  Scaleform::Render::Point<float> ptOut; // [rsp+1E0h] [rbp+108h] BYREF

  v41 = -2i64;
  v6 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[121].__vecDelDtor)(this);
  if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0x800) != 0
    || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this)
    && !v6
    || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this)
    || pdescr->pIgnoreMC == this
    || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::MovieImpl *, _QWORD))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[85].__vecDelDtor)(
          this,
          this->pASRoot->pMovieImpl,
          pdescr->ControllerIdx) )
  {
    goto LABEL_34;
  }
  if ( !Scaleform::GFx::DisplayObject::TransformPointToLocalAndCheckBounds(this, &p, pt, 1, 0i64) )
    return 2i64;
  Mask = Scaleform::GFx::DisplayObject::GetMask(this);
  v8 = Mask;
  if ( Mask )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))Mask->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(Mask)
      && (v8->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
    {
      if ( Scaleform::GFx::DisplayObjectBase::Has3D(v8) )
      {
        memset(pmat, 0, 0x30ui64);
        *(_DWORD *)pmat = 1065353216;
        *(_DWORD *)&pmat[20] = 1065353216;
        *(_DWORD *)&pmat[40] = 1065353216;
        memset(&pmat[56], 0, 0x40ui64);
        *(_DWORD *)&pmat[96] = 1065353216;
        *(_DWORD *)&pmat[116] = 1065353216;
        memset(&pmat[48], 0, 0x30ui64);
        *(_DWORD *)&pmat[68] = 1065353216;
        *(_DWORD *)&pmat[48] = 1065353216;
        pParent = v8->pParent;
        if ( pParent )
        {
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(pParent, (Scaleform::Render::Matrix3x4<float> *)&pmat[48]);
          v31 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(v8);
          *(_OWORD *)&m1.M[0][0] = *(_OWORD *)&pmat[48];
          *(_OWORD *)&m1.M[1][0] = *(_OWORD *)&pmat[64];
          *(_OWORD *)&m1.M[2][0] = *(_OWORD *)&pmat[40];
          Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
            (Scaleform::Render::Matrix3x4<float> *)&pmat[48],
            &m1,
            v31);
        }
        else
        {
          v32 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(v8);
          *(_QWORD *)&pmat[48] = *(_QWORD *)v32;
          *(_OWORD *)&pmat[56] = *(_OWORD *)(v32 + 8);
          *(_DWORD *)&pmat[72] = *(_DWORD *)(v32 + 24);
          *(_DWORD *)&pmat[76] = *(_DWORD *)(v32 + 28);
          *(_OWORD *)&pmat[40] = *(_OWORD *)(v32 + 32);
        }
        p_ScreenToWorld = &this->pASRoot->pMovieImpl->ScreenToWorld;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, _BYTE *, _QWORD))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[6].__vecDelDtor)(
               v8,
               &pmat[56],
               0i64) )
        {
          *(_OWORD *)&p_ScreenToWorld->MatProj.M[0][0] = *(_OWORD *)&pmat[56];
          p_ScreenToWorld->MatProj.M[1][0] = *(float *)&pmat[72];
          p_ScreenToWorld->MatProj.M[1][1] = *(float *)&pmat[76];
          p_ScreenToWorld->MatProj.M[1][2] = *(float *)&pmat[80];
          p_ScreenToWorld->MatProj.M[1][3] = *(float *)&pmat[84];
          p_ScreenToWorld->MatProj.M[2][0] = *(float *)&pmat[88];
          p_ScreenToWorld->MatProj.M[2][1] = *(float *)&pmat[92];
          p_ScreenToWorld->MatProj.M[2][2] = *(float *)&pmat[96];
          p_ScreenToWorld->MatProj.M[2][3] = *(float *)&pmat[100];
          p_ScreenToWorld->MatProj.M[3][0] = *(float *)&pmat[104];
          p_ScreenToWorld->MatProj.M[3][1] = *(float *)&pmat[108];
          p_ScreenToWorld->MatProj.M[3][2] = *(float *)&pmat[112];
          p_ScreenToWorld->MatProj.M[3][3] = *(float *)&pmat[116];
        }
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, _BYTE *, _QWORD))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[9].__vecDelDtor)(
               v8,
               pmat,
               0i64) )
        {
          *(_OWORD *)&p_ScreenToWorld->MatView.M[0][0] = *(_OWORD *)pmat;
          *(_OWORD *)&p_ScreenToWorld->MatView.M[1][0] = *(_OWORD *)&pmat[16];
          p_ScreenToWorld->MatView.M[2][0] = *(float *)&pmat[32];
          p_ScreenToWorld->MatView.M[2][1] = *(float *)&pmat[36];
          *(_QWORD *)&p_ScreenToWorld->MatView.M[2][2] = *(_QWORD *)&pmat[40];
        }
        *(_QWORD *)&p_ScreenToWorld->MatWorld.M[0][0] = *(_QWORD *)&pmat[48];
        *(_OWORD *)&p_ScreenToWorld->MatWorld.M[0][2] = *(_OWORD *)&pmat[56];
        p_ScreenToWorld->MatWorld.M[1][2] = *(float *)&pmat[72];
        p_ScreenToWorld->MatWorld.M[1][3] = *(float *)&pmat[76];
        *(_OWORD *)&p_ScreenToWorld->MatWorld.M[2][0] = *(_OWORD *)&pmat[40];
        Scaleform::Render::ScreenToWorld::GetWorldPoint(p_ScreenToWorld, &ptOut);
      }
      else
      {
        *(_OWORD *)&pmat[48] = _xmm;
        *(__m128 *)&pmat[64] = _xmm;
        *(_OWORD *)pmat = _xmm;
        *(__m128 *)&pmat[16] = _xmm;
        v9 = v8->pParent;
        if ( v9 )
        {
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v9, (Scaleform::Render::Matrix2x4<float> *)pmat);
          v10 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(v8);
          v11 = *(float *)pmat;
          v12 = *(float *)&pmat[4];
          v13 = *(float *)&pmat[16];
          v14 = *(float *)&pmat[20];
          *(float *)pmat = (float)(*(float *)pmat * *v10) + (float)(*(float *)&pmat[4] * v10[4]);
          *(float *)&pmat[16] = (float)(*(float *)&pmat[16] * *v10) + (float)(*(float *)&pmat[20] * v10[4]);
          *(float *)&pmat[4] = (float)(v11 * v10[1]) + (float)(*(float *)&pmat[4] * v10[5]);
          *(float *)&pmat[20] = (float)(v13 * v10[1]) + (float)(*(float *)&pmat[20] * v10[5]);
          *(_DWORD *)&pmat[24] = 0;
          *(_DWORD *)&pmat[8] = 0;
          *(float *)&pmat[12] = *(float *)&pmat[12] + (float)((float)(v12 * v10[7]) + (float)(v11 * v10[3]));
          *(float *)&pmat[28] = *(float *)&pmat[28] + (float)((float)(v14 * v10[7]) + (float)(v13 * v10[3]));
        }
        else
        {
          v15 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(v8);
          *(_OWORD *)pmat = *v15;
          *(_OWORD *)&pmat[16] = v15[1];
        }
        Scaleform::Render::Matrix2x4<float>::SetInverse(
          (Scaleform::Render::Matrix2x4<float> *)&pmat[48],
          (Scaleform::Render::Matrix2x4<float> *)pmat);
        *(_OWORD *)pmat = _xmm;
        *(__m128 *)&pmat[16] = _xmm;
        v16 = this->pParent;
        if ( v16 )
        {
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v16, (Scaleform::Render::Matrix2x4<float> *)pmat);
          v17 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
          v19 = *(float *)pmat;
          v20 = *(float *)&pmat[4];
          v21 = *(float *)&pmat[16];
          v22 = *(float *)&pmat[20];
          v23 = (float)(*(float *)&pmat[4] * v17[4]) + (float)(*(float *)pmat * *v17);
          *(float *)pmat = v23;
          v24 = (float)(*(float *)&pmat[20] * v17[4]) + (float)(*(float *)&pmat[16] * *v17);
          *(float *)&pmat[16] = v24;
          v25 = (float)(v19 * v17[1]) + (float)(*(float *)&pmat[4] * v17[5]);
          *(float *)&pmat[4] = v25;
          v26 = (float)(v21 * v17[1]) + (float)(*(float *)&pmat[20] * v17[5]);
          *(float *)&pmat[20] = v26;
          *(_DWORD *)&pmat[24] = 0;
          *(_DWORD *)&pmat[8] = 0;
          v27 = *(float *)&pmat[12] + (float)((float)(v20 * v17[7]) + (float)(v19 * v17[3]));
          *(float *)&pmat[12] = v27;
          v28 = *(float *)&pmat[28] + (float)((float)(v22 * v17[7]) + (float)(v21 * v17[3]));
        }
        else
        {
          v29 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
          v23 = *v29;
          *(float *)pmat = *v29;
          v25 = v29[1];
          *(_QWORD *)&pmat[4] = *(_QWORD *)(v29 + 1);
          v27 = v29[3];
          *(float *)&pmat[12] = v27;
          v24 = v29[4];
          *(float *)&pmat[16] = v24;
          v26 = v29[5];
          *(_QWORD *)&pmat[20] = *(_QWORD *)(v29 + 5);
          v28 = v29[7];
        }
        ptOut.x = (float)((float)((float)((float)(*(float *)&pmat[52] * v26) + (float)(*(float *)&pmat[48] * v25)) * p.y)
                        + (float)((float)((float)(*(float *)&pmat[52] * v24) + (float)(*(float *)&pmat[48] * v23)) * p.x))
                + (float)(*(float *)&pmat[60]
                        + (float)((float)(*(float *)&pmat[52] * v28) + (float)(*(float *)&pmat[48] * v27)));
        ptOut.y = (float)((float)((float)((float)(*(float *)&pmat[68] * v26) + (float)(*(float *)&pmat[64] * v25)) * p.y)
                        + (float)((float)((float)(*(float *)&pmat[68] * v24) + (float)(*(float *)&pmat[64] * v23)) * p.x))
                + (float)(*(float *)&pmat[76]
                        + (float)((float)(*(float *)&pmat[68] * v28) + (float)(*(float *)&pmat[64] * v27)));
      }
      LOBYTE(v18) = 1;
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Point<float> *, __int64))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
              v8,
              &ptOut,
              v18) )
      {
LABEL_34:
        pdescr->pResult = 0i64;
        return 2i64;
      }
    }
  }
  ptOut = (Scaleform::Render::Point<float>)&phitTest;
  memset(&phitTest, 0, sizeof(phitTest));
  Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(
    this,
    (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)&phitTest,
    &p,
    1);
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v35 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * AvmObjOffset))[5].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    v36 = (*(__int64 (__fastcall **)(__int64, Scaleform::Render::Point<float> *, Scaleform::GFx::DisplayObjectBase::TopMostDescr *, Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *))(*(_QWORD *)v35 + 176i64))(
            v35,
            &p,
            pdescr,
            &phitTest);
  }
  else
  {
    v36 = 2;
  }
  ptOut = (Scaleform::Render::Point<float>)&phitTest;
  if ( phitTest.Data.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v36;
}

// File Line: 406
// RVA: 0x8F0070
char __fastcall Scaleform::GFx::DisplayObjContainer::PointTestLocal(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::Render::Point<float> *pt,
        unsigned __int8 hitTestMask)
{
  float *v7; // rax
  float y; // xmm0_4
  unsigned __int64 Size; // rsi
  Scaleform::GFx::DisplayObject *pMaskCharacter; // rbx
  Scaleform::GFx::DisplayObjectBase *pParent; // rcx
  float *v12; // rax
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  __int128 *v17; // rax
  Scaleform::GFx::InteractiveObject *v18; // rcx
  float *v19; // rax
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm9_4
  float v26; // xmm11_4
  float v27; // xmm10_4
  float v28; // xmm12_4
  float v29; // xmm13_4
  float *v30; // rax
  float v31; // xmm2_4
  __int64 v32; // rsi
  __int64 v33; // r14
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rbx
  __int128 *v35; // rax
  char v36; // bl
  __int128 pmat; // [rsp+30h] [rbp-98h] BYREF
  _BYTE pmat_16[24]; // [rsp+40h] [rbp-88h] BYREF
  __int64 phitTest_8; // [rsp+58h] [rbp-70h]
  __int64 phitTest_16; // [rsp+60h] [rbp-68h]
  Scaleform::Render::Matrix2x4<float> v41; // [rsp+70h] [rbp-58h] BYREF
  Scaleform::Render::Point<float> v42; // [rsp+118h] [rbp+50h] BYREF
  Scaleform::Render::Point<float> result; // [rsp+130h] [rbp+68h] BYREF

  if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0x800) != 0 )
    return 0;
  if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 1) == 0 )
  {
    *(_OWORD *)&v41.M[0][0] = _xmm;
    *(__m128 *)&pmat_16[8] = _xmm;
    v7 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, __int128 *, Scaleform::Render::Matrix2x4<float> *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[61].__vecDelDtor)(
                    this,
                    &pmat,
                    &v41);
    if ( pt->x > v7[2] )
      return 0;
    if ( pt->x < *v7 )
      return 0;
    y = pt->y;
    if ( y > v7[3] || y < v7[1] )
      return 0;
  }
  if ( (hitTestMask & 2) != 0
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this) )
  {
    return 0;
  }
  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  if ( this->pMaskCharacter )
  {
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this) )
    {
      pMaskCharacter = this->pMaskCharacter;
      if ( pMaskCharacter )
      {
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))pMaskCharacter->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this->pMaskCharacter)
          && (pMaskCharacter->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
        {
          *(_OWORD *)&v41.M[0][0] = _xmm;
          *(_QWORD *)&pmat_16[16] = _xmm.m128_u64[1];
          pmat = _xmm;
          *(__m128 *)pmat_16 = _xmm;
          pParent = pMaskCharacter->pParent;
          if ( pParent )
          {
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, (Scaleform::Render::Matrix2x4<float> *)&pmat);
            v12 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))pMaskCharacter->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pMaskCharacter);
            v13 = *(float *)&pmat;
            v14 = *((float *)&pmat + 1);
            v15 = *(float *)pmat_16;
            v16 = *(float *)&pmat_16[4];
            *(float *)&pmat = (float)(*((float *)&pmat + 1) * v12[4]) + (float)(*(float *)&pmat * *v12);
            *(float *)pmat_16 = (float)(*(float *)&pmat_16[4] * v12[4]) + (float)(*(float *)pmat_16 * *v12);
            *((float *)&pmat + 1) = (float)(v13 * v12[1]) + (float)(*((float *)&pmat + 1) * v12[5]);
            *(float *)&pmat_16[4] = (float)(v15 * v12[1]) + (float)(*(float *)&pmat_16[4] * v12[5]);
            *(_DWORD *)&pmat_16[8] = 0;
            DWORD2(pmat) = 0;
            *((float *)&pmat + 3) = *((float *)&pmat + 3) + (float)((float)(v14 * v12[7]) + (float)(v13 * v12[3]));
            *(float *)&pmat_16[12] = *(float *)&pmat_16[12] + (float)((float)(v16 * v12[7]) + (float)(v15 * v12[3]));
          }
          else
          {
            v17 = (__int128 *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))pMaskCharacter->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pMaskCharacter);
            pmat = *v17;
            *(_OWORD *)pmat_16 = v17[1];
          }
          Scaleform::Render::Matrix2x4<float>::SetInverse(&v41, (Scaleform::Render::Matrix2x4<float> *)&pmat);
          pmat = _xmm;
          *(__m128 *)pmat_16 = _xmm;
          v18 = this->pParent;
          if ( v18 )
          {
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v18, (Scaleform::Render::Matrix2x4<float> *)&pmat);
            v19 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
            v20 = *(float *)&pmat;
            v21 = *((float *)&pmat + 1);
            v22 = *(float *)pmat_16;
            v23 = *(float *)&pmat_16[4];
            v24 = (float)(*((float *)&pmat + 1) * v19[4]) + (float)(*(float *)&pmat * *v19);
            *(float *)&pmat = v24;
            v25 = (float)(*(float *)&pmat_16[4] * v19[4]) + (float)(*(float *)pmat_16 * *v19);
            *(float *)pmat_16 = v25;
            v26 = (float)(v20 * v19[1]) + (float)(*((float *)&pmat + 1) * v19[5]);
            *((float *)&pmat + 1) = v26;
            v27 = (float)(v22 * v19[1]) + (float)(*(float *)&pmat_16[4] * v19[5]);
            *(float *)&pmat_16[4] = v27;
            *(_DWORD *)&pmat_16[8] = 0;
            DWORD2(pmat) = 0;
            v28 = *((float *)&pmat + 3) + (float)((float)(v21 * v19[7]) + (float)(v20 * v19[3]));
            *((float *)&pmat + 3) = v28;
            v29 = *(float *)&pmat_16[12] + (float)((float)(v23 * v19[7]) + (float)(v22 * v19[3]));
          }
          else
          {
            v30 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
            v24 = *v30;
            *(float *)&pmat = *v30;
            v26 = v30[1];
            *(_QWORD *)((char *)&pmat + 4) = *(_QWORD *)(v30 + 1);
            v28 = v30[3];
            *((float *)&pmat + 3) = v28;
            v25 = v30[4];
            *(float *)pmat_16 = v25;
            v27 = v30[5];
            *(_QWORD *)&pmat_16[4] = *(_QWORD *)(v30 + 5);
            v29 = v30[7];
          }
          result.x = (float)((float)((float)((float)(v25 * v41.M[0][1]) + (float)(v24 * v41.M[0][0])) * pt->x)
                           + (float)((float)((float)(v41.M[0][0] * v26) + (float)(v27 * v41.M[0][1])) * pt->y))
                   + (float)(v41.M[0][3] + (float)((float)(v41.M[0][1] * v29) + (float)(v41.M[0][0] * v28)));
          result.y = (float)((float)((float)((float)(v25 * *(float *)&pmat_16[12]) + (float)(v24 * *(float *)&pmat_16[8]))
                                   * pt->x)
                           + (float)((float)((float)(*(float *)&pmat_16[8] * v26) + (float)(v27 * *(float *)&pmat_16[12]))
                                   * pt->y))
                   + (float)(*(float *)&pmat_16[20]
                           + (float)((float)(*(float *)&pmat_16[12] * v29) + (float)(*(float *)&pmat_16[8] * v28)));
          if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Point<float> *, _QWORD))pMaskCharacter->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
                  pMaskCharacter,
                  &result,
                  hitTestMask) )
            return 0;
        }
      }
    }
  }
  result = (Scaleform::Render::Point<float>)&pmat_16[16];
  *(_QWORD *)&pmat_16[16] = 0i64;
  phitTest_8 = 0i64;
  phitTest_16 = 0i64;
  Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(
    this,
    (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)&pmat_16[16],
    pt,
    hitTestMask & 1);
  pmat = _xmm;
  *(__m128 *)pmat_16 = _xmm;
  v31 = pt->y;
  v42.x = pt->x;
  v42.y = v31;
  v32 = Size - 1;
  if ( v32 < 0 )
  {
LABEL_33:
    v36 = 0;
  }
  else
  {
    v33 = v32;
    while ( 1 )
    {
      pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[v33].pCharacter;
      if ( ((hitTestMask & 2) == 0
         || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(pCharacter))
        && (!phitTest_8 || *(_BYTE *)(*(_QWORD *)&pmat_16[16] + v32) && !pCharacter->ClipDepth) )
      {
        v35 = (__int128 *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pCharacter);
        pmat = *v35;
        *(_OWORD *)pmat_16 = v35[1];
        Scaleform::Render::Matrix2x4<float>::TransformByInverse(
          (Scaleform::Render::Matrix2x4<float> *)&pmat,
          &result,
          pt);
        v42 = result;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, _QWORD))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
               pCharacter,
               &v42,
               hitTestMask) )
        {
          break;
        }
      }
      --v33;
      if ( --v32 < 0 )
        goto LABEL_33;
    }
    v36 = 1;
  }
  result = (Scaleform::Render::Point<float>)&pmat_16[16];
  if ( *(_QWORD *)&pmat_16[16] )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v36;
}

// File Line: 461
// RVA: 0x8F3C10
void __fastcall Scaleform::GFx::DisplayObjContainer::PropagateFocusGroupMask(
        Scaleform::GFx::DisplayObjContainer *this,
        unsigned int mask)
{
  unsigned __int64 Size; // rdi
  __int64 v5; // rbx
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax

  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  this->FocusGroupMask = mask;
  if ( Size )
  {
    v5 = 0i64;
    do
    {
      pCharacter = 0i64;
      if ( SLOBYTE(this->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter->Flags) < 0 )
        pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter;
      if ( pCharacter )
      {
        vfptr = pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
        HIWORD(pCharacter[1].pRenNode.pObject) = mask;
        vfptr[106].__vecDelDtor(pCharacter, mask);
      }
      ++v5;
      --Size;
    }
    while ( Size );
  }
}

// File Line: 475
// RVA: 0x8D6300
void __fastcall Scaleform::GFx::DisplayObjContainer::GetChildDescTree(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::AmpMovieObjectDesc *parent,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v3; // r9
  Scaleform::GFx::DisplayObjContainer *v4; // rax
  unsigned __int64 v5; // rbp
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2,Scaleform::ArrayDefaultPolicy> *p_Children; // rdi
  __int64 v7; // rcx
  __int64 v8; // rsi
  __int64 v9; // rbx
  Scaleform::GFx::DisplayObject *v10; // rcx
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  _QWORD *p_pObject; // rdi
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-58h] BYREF
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2,Scaleform::ArrayDefaultPolicy> *v16; // [rsp+28h] [rbp-50h]
  __int64 v17; // [rsp+30h] [rbp-48h]
  __int64 v18; // [rsp+38h] [rbp-40h]
  _QWORD *v19; // [rsp+40h] [rbp-38h]
  _QWORD *v20; // [rsp+48h] [rbp-30h]
  __int64 v21; // [rsp+50h] [rbp-28h]
  __int64 v24; // [rsp+98h] [rbp+20h]

  v17 = -2i64;
  v3 = heap;
  v4 = this;
  v5 = 0i64;
  if ( this->mDisplayList.DisplayObjectArray.Data.Size )
  {
    p_Children = &parent->Children;
    v16 = &parent->Children;
    v7 = 0i64;
    v24 = 0i64;
    do
    {
      v8 = *(__int64 *)((char *)&v4->mDisplayList.DisplayObjectArray.Data.Data->pCharacter + v7);
      v9 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v3->vfptr->Alloc)(v3, 48i64);
      v18 = v9;
      if ( v9 )
      {
        *(_QWORD *)v9 = &Scaleform::RefCountImplCore::`vftable;
        *(_DWORD *)(v9 + 8) = 1;
        *(_QWORD *)v9 = &Scaleform::RefCountImpl::`vftable;
        *(_QWORD *)v9 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
        *(_QWORD *)v9 = &Scaleform::RefCountBase<Scaleform::AmpMovieObjectDesc,2>::`vftable;
        *(_QWORD *)v9 = &Scaleform::AmpMovieObjectDesc::`vftable;
        Scaleform::StringLH::StringLH((Scaleform::StringLH *)(v9 + 16));
        v19 = (_QWORD *)(v9 + 24);
        v20 = (_QWORD *)(v9 + 24);
        v10 = 0i64;
        *(_QWORD *)(v9 + 24) = 0i64;
        *(_QWORD *)(v9 + 32) = 0i64;
        *(_QWORD *)(v9 + 40) = 0i64;
      }
      else
      {
        v10 = 0i64;
        v9 = 0i64;
      }
      if ( (*(_BYTE *)(v8 + 107) & 1) != 0 )
        v10 = (Scaleform::GFx::DisplayObject *)v8;
      if ( v10 )
      {
        Name = Scaleform::GFx::DisplayObject::GetName(v10, &result);
        Scaleform::String::operator=((Scaleform::String *)(v9 + 16), Name->pNode->pData);
        pNode = result.pNode;
        if ( result.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
      else
      {
        Scaleform::String::operator=((Scaleform::String *)(v9 + 16), "Unnamed");
      }
      v21 = v9;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &p_Children->Data,
        p_Children,
        p_Children->Data.Size + 1);
      p_pObject = &p_Children->Data.Data[p_Children->Data.Size - 1].pObject;
      v20 = p_pObject;
      v19 = p_pObject;
      if ( p_pObject )
      {
        if ( v9 )
          Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v9);
        *p_pObject = v9;
      }
      if ( v9 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
      if ( (*(_WORD *)(v8 + 106) & 0x200) != 0 )
        Scaleform::GFx::DisplayObjContainer::GetChildDescTree(
          (Scaleform::GFx::DisplayObjContainer *)v8,
          (Scaleform::AmpMovieObjectDesc *)v9,
          heap);
      ++v5;
      v7 = v24 + 16;
      v24 += 16i64;
      v4 = this;
      v3 = heap;
      p_Children = v16;
    }
    while ( v5 < this->mDisplayList.DisplayObjectArray.Data.Size );
  }
}

// File Line: 500
// RVA: 0x8CB380
void __fastcall Scaleform::GFx::DisplayObjContainer::FillTabableArray(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::InteractiveObject::FillTabableParams *params)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v4; // rax

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v4 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[5].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject::FillTabableParams *))(*(_QWORD *)v4 + 184i64))(
      v4,
      params);
  }
}

// File Line: 506
// RVA: 0x8BDC20
char __fastcall Scaleform::GFx::DisplayObjContainer::Contains(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::DisplayObjContainer *ch)
{
  __int64 v5; // rbx
  __int64 i; // rdi
  Scaleform::GFx::DisplayObjContainer *pCharacter; // rcx

  if ( this == ch || ch && ch->pParent == this )
    return 1;
  v5 = 0i64;
  if ( !this->mDisplayList.DisplayObjectArray.Data.Size )
    return 0;
  for ( i = 0i64; ; ++i )
  {
    pCharacter = 0i64;
    if ( (this->mDisplayList.DisplayObjectArray.Data.Data[i].pCharacter->Flags & 0x200) != 0 )
      pCharacter = (Scaleform::GFx::DisplayObjContainer *)this->mDisplayList.DisplayObjectArray.Data.Data[i].pCharacter;
    if ( pCharacter && Scaleform::GFx::DisplayObjContainer::Contains(pCharacter, ch) )
      break;
    if ( ++v5 >= this->mDisplayList.DisplayObjectArray.Data.Size )
      return 0;
  }
  return 1;
}

// File Line: 523
// RVA: 0x8D8460
Scaleform::GFx::FontManager *__fastcall Scaleform::GFx::DisplayObjContainer::GetFontManager(
        Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::MovieDefRootNode *pRootNode; // rax
  Scaleform::GFx::InteractiveObject *pParent; // rdx

  pRootNode = this->pRootNode;
  if ( pRootNode )
    return pRootNode->pFontManager.pObject;
  pParent = this->pParent;
  if ( !pParent )
  {
    pRootNode = this->pASRoot->pMovieImpl->RootMovieDefNodes.Root.pNext;
    return pRootNode->pFontManager.pObject;
  }
  return (Scaleform::GFx::FontManager *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[67].__vecDelDtor)(this->pParent);
}

// File Line: 535
// RVA: 0x90C370
void __fastcall Scaleform::GFx::DisplayObjContainer::SetStateChangeFlags(
        Scaleform::GFx::DisplayObjContainer *this,
        unsigned __int8 flags)
{
  unsigned __int64 Size; // rsi
  __int64 v5; // rbx

  this->Scaleform::GFx::InteractiveObject::Flags &= 0xFFF0FFFF;
  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  this->Scaleform::GFx::InteractiveObject::Flags |= (flags & 0xF) << 16;
  if ( Size )
  {
    v5 = 0i64;
    do
    {
      this->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter->vfptr[79].__vecDelDtor(
        this->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter,
        flags);
      ++v5;
      --Size;
    }
    while ( Size );
  }
}

// File Line: 627
// RVA: 0x8CE420
void __fastcall Scaleform::GFx::DisplayObjContainer::ForceShutdown(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, this);
}

// File Line: 633
// RVA: 0x8E2D20
char __fastcall Scaleform::GFx::DisplayObjContainer::Has3D(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  unsigned __int64 Size; // rbp
  __int64 v5; // rbx
  __int64 i; // rdi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rcx

  pObject = this->pRenNode.pObject;
  if ( pObject
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64
                             * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x200) != 0 )
  {
    return 1;
  }
  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  v5 = 0i64;
  if ( !Size )
    return 0;
  for ( i = 0i64; ; ++i )
  {
    pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[i].pCharacter;
    if ( pCharacter )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[14].__vecDelDtor)(pCharacter) )
        break;
    }
    if ( ++v5 >= Size )
      return 0;
  }
  return 1;
}

// File Line: 648
// RVA: 0x918450
void __fastcall Scaleform::GFx::DisplayObjContainer::UpdateViewAndPerspective(
        Scaleform::GFx::DisplayObjContainer *this)
{
  unsigned __int64 Size; // rdi
  __int64 v3; // rbx
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rcx

  Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  if ( Size )
  {
    v3 = 0i64;
    do
    {
      pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[v3].pCharacter;
      if ( pCharacter )
        ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[12].__vecDelDtor)(pCharacter);
      ++v3;
      --Size;
    }
    while ( Size );
  }
}

// File Line: 671
// RVA: 0x8F4BB0
void __fastcall Scaleform::GFx::DisplayObjContainer::PropagateScale9GridExists(
        Scaleform::GFx::DisplayObjContainer *this)
{
  bool HasScale9Grid; // al
  bool v3; // bp
  unsigned __int64 Size; // rsi
  __int64 v5; // rdi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rcx

  HasScale9Grid = Scaleform::GFx::DisplayObjectBase::HasScale9Grid(this);
  v3 = HasScale9Grid;
  if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 1) != 0
    || !HasScale9Grid )
  {
    Size = this->mDisplayList.DisplayObjectArray.Data.Size;
    if ( Size )
    {
      v5 = 0i64;
      do
      {
        pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter;
        if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 1) != 0
          || v3 )
        {
          pCharacter->Flags |= 1u;
        }
        else
        {
          pCharacter->Flags &= ~1u;
        }
        ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[20].__vecDelDtor)(pCharacter);
        ++v5;
        --Size;
      }
      while ( Size );
    }
  }
}

