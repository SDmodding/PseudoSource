// File Line: 33
// RVA: 0x8954C0
void __fastcall Scaleform::GFx::DisplayObjContainer::DisplayObjContainer(Scaleform::GFx::DisplayObjContainer *this, Scaleform::GFx::MovieDefImpl *pbindingDefImpl, Scaleform::GFx::ASMovieRootBase *pasRoot, Scaleform::GFx::InteractiveObject *pparent, Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::DisplayObjContainer *v5; // rbx
  Scaleform::GFx::DisplayList *v6; // rax

  v5 = this;
  id.Id = **(_DWORD **)&id.Id;
  Scaleform::GFx::InteractiveObject::InteractiveObject(
    (Scaleform::GFx::InteractiveObject *)&this->vfptr,
    pbindingDefImpl,
    pasRoot,
    pparent,
    (Scaleform::GFx::ResourceId)&id);
  v5->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  v5->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  v6 = &v5->mDisplayList;
  *(_QWORD *)&id.Id = v6;
  v6->DisplayObjectArray.Data.Data = 0i64;
  v6->DisplayObjectArray.Data.Size = 0i64;
  v6->DisplayObjectArray.Data.Policy.Capacity = 0i64;
  v5->mDisplayList.DepthToIndexMap = 0i64;
  v5->mDisplayList.pCachedChar = 0i64;
  v5->mDisplayList.ModId = 0;
  v5->mDisplayList.Flags = 0;
  v5->pRootNode = 0i64;
  v5->Flags |= 0x200u;
}

// File Line: 38
// RVA: 0x8A3C20
void __fastcall Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::DisplayObjContainer *v1; // rdi
  Scaleform::GFx::MovieDefRootNode *v2; // rax
  Scaleform::GFx::MovieDefRootNode *v3; // rdx
  Scaleform::GFx::MovieDefRootNode *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObjContainer::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  v2 = this->pRootNode;
  if ( v2 )
  {
    --v2->SpriteRefCount;
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
  Scaleform::GFx::DisplayList::Clear(&v1->mDisplayList, (Scaleform::GFx::DisplayObjectBase *)&v1->vfptr);
  Scaleform::GFx::DisplayList::~DisplayList(&v1->mDisplayList);
  Scaleform::GFx::InteractiveObject::~InteractiveObject((Scaleform::GFx::InteractiveObject *)&v1->vfptr);
}

// File Line: 53
// RVA: 0x8B6980
void __fastcall Scaleform::GFx::DisplayObjContainer::AssignRootNode(Scaleform::GFx::DisplayObjContainer *this, bool importFlag)
{
  bool v2; // si
  Scaleform::GFx::DisplayObjContainer *v3; // rbx
  Scaleform::GFx::MovieImpl *v4; // r8
  Scaleform::GFx::MovieDefRootNode *v5; // rax
  signed __int64 v6; // r8
  Scaleform::GFx::FontManager *v7; // rdi
  signed __int64 v8; // rcx
  Scaleform::GFx::ASMovieRootBase *v9; // rcx
  Scaleform::MemoryHeap *v10; // r14
  unsigned int v11; // eax
  Scaleform::GFx::FontManager *v12; // rax
  Scaleform::GFx::FontManager *v13; // rax
  Scaleform::GFx::MovieDefRootNode *v14; // rsi
  Scaleform::Render::RenderBuffer *v15; // rcx
  Scaleform::GFx::MovieDefRootNode *v16; // rdx
  Scaleform::GFx::MovieImpl *v17; // rcx

  v2 = importFlag;
  v3 = this;
  if ( !this->pRootNode )
  {
    v4 = this->pASRoot->pMovieImpl;
    v5 = v4->RootMovieDefNodes.Root.pNext;
    v6 = (signed __int64)&v4->RootMovieDefNodes;
    v7 = 0i64;
    while ( 1 )
    {
      v8 = v6 - 8;
      if ( !v6 )
        v8 = 0i64;
      if ( v5 == (Scaleform::GFx::MovieDefRootNode *)v8 )
        break;
      if ( v5->pDefImpl == v3->pDefImpl.pObject && v5->ImportFlag == importFlag )
      {
        ++v5->SpriteRefCount;
        v3->pRootNode = v5;
        break;
      }
      v5 = v5->pNext;
    }
    if ( !v3->pRootNode )
    {
      v9 = v3->pASRoot;
      v10 = v9->pMovieImpl->pHeap;
      v3->pRootNode = (Scaleform::GFx::MovieDefRootNode *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::MemoryHeap *, Scaleform::GFx::MovieDefImpl *, bool, signed __int64))v9->vfptr[6].__vecDelDtor)(
                                                            v9,
                                                            v9->pMovieImpl->pHeap,
                                                            v3->pDefImpl.pObject,
                                                            importFlag,
                                                            -2i64);
      v3->pRootNode->BytesLoaded = v3->pDefImpl.pObject->pBindData.pObject->BytesLoaded;
      if ( v2 )
        v11 = 0;
      else
        v11 = ((__int64 (*)(void))v3->pDefImpl.pObject->vfptr[1].GetKey)();
      v3->pRootNode->LoadingFrame = v11;
      v12 = (Scaleform::GFx::FontManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v10->vfptr->Alloc)(
                                             v10,
                                             104i64);
      if ( v12 )
      {
        Scaleform::GFx::FontManager::FontManager(
          v12,
          v3->pASRoot->pMovieImpl,
          v3->pDefImpl.pObject,
          v3->pASRoot->pMovieImpl->pFontManagerStates.pObject);
        v7 = v13;
      }
      v14 = v3->pRootNode;
      v15 = (Scaleform::Render::RenderBuffer *)v14->pFontManager.pObject;
      if ( v15 )
        Scaleform::RefCountImpl::Release(v15);
      v14->pFontManager.pObject = v7;
      v16 = v3->pRootNode;
      v17 = v3->pASRoot->pMovieImpl;
      v16->pNext = v17->RootMovieDefNodes.Root.pNext;
      v16->pPrev = (Scaleform::GFx::MovieDefRootNode *)&v17->MovieLevels.Data.Policy;
      v17->RootMovieDefNodes.Root.pNext->pPrev = v16;
      v17->RootMovieDefNodes.Root.pNext = v16;
    }
  }
}

// File Line: 99
// RVA: 0x8CD4C0
Scaleform::GFx::MovieDefRootNode *__fastcall Scaleform::GFx::DisplayObjContainer::FindRootNode(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::DisplayObjContainer *v1; // rax

  while ( this )
  {
    v1 = 0i64;
    if ( (this->Flags >> 9) & 1 )
      v1 = this;
    if ( v1 && v1->pRootNode )
      return v1->pRootNode;
    this = (Scaleform::GFx::DisplayObjContainer *)this->pParent;
  }
  return 0i64;
}

// File Line: 117
// RVA: 0x8ED210
void __fastcall Scaleform::GFx::DisplayObjContainer::OnInsertionAsLevel(Scaleform::GFx::DisplayObjContainer *this, __int64 level)
{
  Scaleform::GFx::DisplayObjContainer *v2; // rbx
  Scaleform::GFx::InteractiveObject *v3; // rcx
  unsigned __int16 v4; // cx
  Scaleform::GFx::MovieImpl *v5; // rcx
  Scaleform::GFx::InteractiveObject *v6; // rax
  int v7; // eax

  v2 = this;
  if ( (_DWORD)level )
  {
    if ( (signed int)level > 0 )
    {
      v3 = this->pASRoot->pMovieImpl->pMainMovie;
      if ( v3 )
      {
        if ( ((unsigned __int8 (*)(void))v3->vfptr[88].__vecDelDtor)() )
        {
          v2->Flags |= 0x180u;
        }
        else
        {
          v2->Flags &= 0xFFFFFF7F;
          v2->Flags |= 0x100u;
        }
      }
    }
  }
  else
  {
    this->Flags |= 0x180u;
  }
  v4 = v2->Flags;
  if ( !(((unsigned __int8)v4 >> 4) & 1) && !(v4 & 0x1000) && v2->Depth >= -1 )
  {
    v5 = v2->pASRoot->pMovieImpl;
    v6 = v5->pPlayListHead;
    if ( v6 )
    {
      v6->pPlayPrev = (Scaleform::GFx::InteractiveObject *)&v2->vfptr;
      v2->pPlayNext = v5->pPlayListHead;
    }
    v5->pPlayListHead = (Scaleform::GFx::InteractiveObject *)&v2->vfptr;
  }
  if ( !((v2->Flags >> 21) & 1) || (v2->Flags >> 22) & 1 )
    level = 0i64;
  else
    LOBYTE(level) = 1;
  v7 = (__int64)v2->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, level);
  if ( v7 == -1 )
  {
    v2->Flags |= 0x400000u;
  }
  else if ( v7 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)&v2->vfptr);
    v2->FocusGroupMask = -1;
    return;
  }
  v2->FocusGroupMask = -1;
}

// File Line: 137
// RVA: 0x8EBA90
void __fastcall Scaleform::GFx::DisplayObjContainer::MoveDisplayObject(Scaleform::GFx::DisplayObjContainer *this, Scaleform::GFx::CharPosInfo *pos)
{
  Scaleform::GFx::DisplayList::MoveDisplayObject(
    &this->mDisplayList,
    (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
    pos);
}

// File Line: 144
// RVA: 0x8BE640
void __fastcall Scaleform::GFx::DisplayObjContainer::CreateAndReplaceDisplayObject(Scaleform::GFx::DisplayObjContainer *this, Scaleform::GFx::CharPosInfo *pos, Scaleform::GFx::ASString *name, Scaleform::GFx::DisplayObjectBase **newChar)
{
  Scaleform::GFx::DisplayObjectBase **v4; // r12
  Scaleform::GFx::ASString *v5; // r13
  Scaleform::GFx::CharPosInfo *v6; // rsi
  Scaleform::GFx::DisplayObjContainer *v7; // rbp
  Scaleform::GFx::DisplayObjectBase *v8; // rax
  Scaleform::RefCountNTSImpl *v9; // rbx
  __int64 v10; // r15
  Scaleform::GFx::ASMovieRootBase *v11; // rdx
  Scaleform::GFx::ASSupport *v12; // rcx
  Scaleform::GFx::DisplayObjectBase *v13; // r14
  Scaleform::GFx::DisplayObjectBase *v14; // rdi
  __int64 v15; // rdx
  __int64 v16; // [rsp+40h] [rbp-58h]
  Scaleform::GFx::ResourceId id; // [rsp+A0h] [rbp+8h]
  Scaleform::GFx::DisplayObjectBase *v18; // [rsp+A8h] [rbp+10h]

  v4 = newChar;
  v5 = name;
  v6 = pos;
  v7 = this;
  id.Id = pos->CharacterId.Id;
  Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
    this->pDefImpl.pObject,
    (Scaleform::GFx::CharacterCreateInfo *)&v16,
    (Scaleform::GFx::ResourceId)&id);
  if ( v16 )
  {
    id.Id = v6->CharacterId.Id;
    v8 = Scaleform::GFx::DisplayList::GetCharacterAtDepth(
           &v7->mDisplayList,
           v6->Depth,
           (Scaleform::GFx::ResourceId)&id,
           0i64);
    v9 = (Scaleform::RefCountNTSImpl *)&v8->vfptr;
    if ( v8 )
      ++v8->RefCount;
    v18 = v8;
    LODWORD(v10) = -1;
    if ( v8 && v8->Depth >= -1 )
      v10 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v8->vfptr[59].__vecDelDtor)(v8);
    v11 = v7->pASRoot;
    v12 = v11->pASSupport.pObject;
    id.Id = v6->CharacterId.Id;
    v13 = 0i64;
    v14 = (Scaleform::GFx::DisplayObjectBase *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, __int64 *, Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::ResourceId *, _DWORD, signed __int64))v12->vfptr[4].__vecDelDtor)(
                                                 v12,
                                                 v11->pMovieImpl,
                                                 &v16,
                                                 v7,
                                                 &id,
                                                 0,
                                                 -2i64);
    Scaleform::GFx::DisplayObjContainer::ReplaceDisplayObject(v7, v6, v14, v5);
    if ( (signed int)v10 > -1 )
    {
      LOBYTE(v15) = (_DWORD)v10 != 0;
      v14->vfptr[58].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v14->vfptr, v15);
    }
    if ( v4 )
    {
      if ( v14->RefCount > 1 )
        v13 = v14;
      *v4 = v13;
    }
    if ( v14 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v14->vfptr);
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v7->vfptr,
      "DisplayObjContainer::ReplaceDisplayObject() - unknown cid = %d",
      LOWORD(v6->CharacterId.Id));
  }
}

// File Line: 179
// RVA: 0x900090
void __fastcall Scaleform::GFx::DisplayObjContainer::ReplaceDisplayObject(Scaleform::GFx::DisplayObjContainer *this, Scaleform::GFx::CharPosInfo *pos, Scaleform::GFx::DisplayObjectBase *ch, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASString *v4; // rsi
  Scaleform::GFx::DisplayObjectBase *v5; // rbx
  Scaleform::GFx::CharPosInfo *v6; // rbp
  Scaleform::GFx::DisplayObjContainer *v7; // rdi

  v4 = name;
  v5 = ch;
  v6 = pos;
  v7 = this;
  if ( name->pNode->Size && this->Flags & 0x100 )
    Scaleform::GFx::DisplayObject::SetName((Scaleform::GFx::DisplayObject *)ch, name);
  Scaleform::GFx::DisplayList::ReplaceDisplayObject(
    &v7->mDisplayList,
    (Scaleform::GFx::DisplayObjectBase *)&v7->vfptr,
    v6,
    v5);
  if ( v4->pNode->Size )
  {
    if ( SLOBYTE(v5->Flags) < 0 )
      v7->pASRoot->vfptr[39].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->pASRoot->vfptr, (unsigned int)v5);
  }
}

// File Line: 211
// RVA: 0x8FF280
void __fastcall Scaleform::GFx::DisplayObjContainer::RemoveDisplayObject(Scaleform::GFx::DisplayObjContainer *this, Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::DisplayList *v2; // rdi
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // r8
  Scaleform::GFx::DisplayObjectBase **v5; // rax
  char v6; // al

  v2 = &this->mDisplayList;
  v3 = 0i64;
  v4 = this->mDisplayList.DisplayObjectArray.Data.Size;
  if ( v4 )
  {
    v5 = &v2->DisplayObjectArray.Data.Data->pCharacter;
    while ( *v5 != ch )
    {
      ++v3;
      v5 += 2;
      if ( v3 >= v4 )
        return;
    }
    if ( (v3 & 0x8000000000000000ui64) == 0i64 )
    {
      Scaleform::GFx::DisplayList::RemoveFromRenderTree(
        &this->mDisplayList,
        (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
        v3);
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v2->DisplayObjectArray.Data,
        v3);
      v6 = v2->Flags;
      ++v2->ModId;
      v2->pCachedChar = 0i64;
      if ( v6 & 2 )
        v2->Flags = v6 | 1;
    }
  }
}

// File Line: 221
// RVA: 0x8D62E0
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::DisplayObjContainer::GetChildAt(Scaleform::GFx::DisplayObjContainer *this, unsigned int index)
{
  Scaleform::GFx::DisplayObjectBase *result; // rax

  if ( index < this->mDisplayList.DisplayObjectArray.Data.Size )
    result = this->mDisplayList.DisplayObjectArray.Data.Data[index].pCharacter;
  else
    result = 0i64;
  return result;
}

// File Line: 236
// RVA: 0x8D5FF0
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::DisplayObjContainer::GetCharacterAtDepth(Scaleform::GFx::DisplayObjContainer *this, int depth)
{
  Scaleform::GFx::DisplayList *v2; // rbx
  int v3; // edi
  unsigned __int64 v4; // rax
  Scaleform::GFx::DisplayObjectBase *result; // rax

  v2 = &this->mDisplayList;
  v3 = depth;
  v4 = Scaleform::GFx::DisplayList::FindDisplayIndex(&this->mDisplayList, depth);
  if ( v4 >= v2->DisplayObjectArray.Data.Size
    || v2->DisplayObjectArray.Data.Data[v4].pCharacter->Depth != v3
    || v4 == -1i64 )
  {
    result = 0i64;
  }
  else
  {
    result = v2->DisplayObjectArray.Data.Data[v4].pCharacter;
  }
  return result;
}

// File Line: 255
// RVA: 0x8F3EA0
void __fastcall Scaleform::GFx::DisplayObjContainer::PropagateMouseEvent(Scaleform::GFx::DisplayObjContainer *this, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::EventId *v2; // rdi
  Scaleform::GFx::DisplayObjContainer *v3; // rbx
  unsigned __int8 v4; // al
  __int64 v5; // rax

  v2 = id;
  v3 = this;
  if ( this )
    ++this->RefCount;
  if ( id->Id == 8 && this->pASRoot->pMovieImpl->MouseCursorCount )
    Scaleform::GFx::InteractiveObject::DoMouseDrag(
      (Scaleform::GFx::InteractiveObject *)&this->vfptr,
      id->ControllerIndex);
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v3->vfptr[59].__vecDelDtor)(v3) )
  {
    Scaleform::GFx::DisplayList::PropagateMouseEvent(&v3->mDisplayList, v2);
    v4 = v3->AvmObjOffset;
    if ( v4 )
    {
      v5 = ((__int64 (__cdecl *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr + 4 * v4))[5].__vecDelDtor)((signed __int64)v3 + 4 * v4);
      (*(void (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v5 + 64i64))(v5, v2);
    }
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v3->vfptr);
}

// File Line: 278
// RVA: 0x8F3D50
void __fastcall Scaleform::GFx::DisplayObjContainer::PropagateKeyEvent(Scaleform::GFx::DisplayObjContainer *this, Scaleform::GFx::EventId *id, int *pkeyMask)
{
  int *v3; // rdi
  Scaleform::GFx::EventId *v4; // rsi
  Scaleform::GFx::DisplayObjContainer *v5; // rbx

  v3 = pkeyMask;
  v4 = id;
  v5 = this;
  if ( this )
    ++this->RefCount;
  if ( ((unsigned __int8 (__cdecl *)(Scaleform::GFx::DisplayObjContainer *))this->vfptr[59].__vecDelDtor)(this) )
  {
    Scaleform::GFx::DisplayList::PropagateKeyEvent(&v5->mDisplayList, v4, v3);
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::EventId *, int *))v5->vfptr[96].__vecDelDtor)(
      v5,
      v4,
      v3);
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v5->vfptr);
}

// File Line: 295
// RVA: 0x8B8D80
void __fastcall Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(Scaleform::GFx::DisplayObjContainer *this, Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *phitTest, Scaleform::Render::Point<float> *pt, bool testShape)
{
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // rsi
  Scaleform::Render::Point<float> *v6; // r12
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *v7; // r14
  Scaleform::GFx::DisplayObjContainer *v8; // rbp
  unsigned __int16 *v9; // r15
  __int64 v10; // rax
  unsigned int v11; // xmm1_4
  unsigned int v12; // xmm0_4
  char *v13; // rbx
  __int64 v14; // r8
  char v15; // al
  unsigned __int64 v16; // rdx
  signed __int64 v17; // r8
  Scaleform::GFx::DisplayObjectBase *v18; // rcx
  Scaleform::Render::Matrix2x4<float> v19; // [rsp+20h] [rbp-48h]
  Scaleform::Render::Point<float> result; // [rsp+70h] [rbp+8h]

  v4 = this->mDisplayList.DisplayObjectArray.Data.Size;
  v5 = 0i64;
  v6 = pt;
  v7 = (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)phitTest;
  v8 = this;
  if ( v4 )
  {
    do
    {
      v9 = (unsigned __int16 *)v8->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter;
      if ( v9[52] )
      {
        if ( !v7->Size )
        {
          if ( v4 > v7->Policy.Capacity )
            Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v7,
              v7,
              v4 + (v4 >> 2));
          v7->Size = v4;
          memset(v7->Data, 1, v4);
        }
        v10 = (*(__int64 (__fastcall **)(unsigned __int16 *))(*(_QWORD *)v9 + 16i64))(v9);
        v11 = *(_DWORD *)(v10 + 4);
        v19.M[0][0] = *(float *)v10;
        *(_QWORD *)&v19.M[0][1] = __PAIR__(*(_DWORD *)(v10 + 8), v11);
        v12 = *(_DWORD *)(v10 + 16);
        v19.M[0][3] = *(float *)(v10 + 12);
        *(_QWORD *)&v19.M[1][0] = __PAIR__(*(_DWORD *)(v10 + 20), v12);
        *(_QWORD *)&v19.M[1][2] = *(_QWORD *)(v10 + 24);
        Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v19, &result, v6);
        v13 = v7->Data;
        LOBYTE(v14) = 1;
        v15 = (*(__int64 (__fastcall **)(unsigned __int16 *, Scaleform::Render::Point<float> *, __int64))(*(_QWORD *)v9 + 504i64))(
                v9,
                &result,
                v14);
        v16 = v5 + 1;
        v13[v5] = v15;
        if ( v5 + 1 < v4 )
        {
          v17 = v16;
          do
          {
            v18 = v8->mDisplayList.DisplayObjectArray.Data.Data[v17].pCharacter;
            if ( v18 && v18->Depth > v9[52] )
              break;
            ++v16;
            ++v17;
            v7->Data[v16 - 1] = v7->Data[v5];
          }
          while ( v16 < v4 );
        }
        v5 = v16 - 1;
      }
      ++v5;
    }
    while ( v5 < v4 );
  }
}

// File Line: 336
// RVA: 0x8DFA50
signed __int64 __fastcall Scaleform::GFx::DisplayObjContainer::GetTopMostMouseEntity(Scaleform::GFx::DisplayObjContainer *this, Scaleform::Render::Point<float> *pt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v3; // r15
  Scaleform::Render::Point<float> *v4; // rsi
  Scaleform::GFx::DisplayObjContainer *v5; // rdi
  __int64 v6; // rbx
  Scaleform::GFx::DisplayObject *v7; // rax
  Scaleform::GFx::DisplayObject *v8; // rsi
  Scaleform::GFx::DisplayObjectBase *v9; // rcx
  float *v10; // rax
  __int64 v11; // kr00_8
  __int64 v12; // kr08_8
  _OWORD *v13; // rax
  Scaleform::GFx::DisplayObjectBase *v14; // rcx
  float *v15; // rax
  __int64 v16; // r8
  __int64 v17; // kr10_8
  __int64 v18; // kr18_8
  float v19; // xmm7_4
  float v20; // xmm10_4
  float v21; // xmm11_4
  float v22; // xmm0_4
  float v23; // xmm12_4
  float v24; // xmm2_4
  float v25; // xmm13_4
  float v26; // xmm14_4
  float *v27; // rax
  Scaleform::GFx::DisplayObjectBase *v28; // rcx
  Scaleform::Render::Matrix3x4<float> *v29; // rax
  __int64 v30; // rax
  signed __int64 v31; // rbx
  unsigned __int8 v32; // al
  __int64 v33; // rax
  unsigned int v34; // ebx
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-A8h]
  int v37; // [rsp+50h] [rbp-88h]
  int v38; // [rsp+54h] [rbp-84h]
  Scaleform::Render::Matrix2x4<float> Dst; // [rsp+58h] [rbp-80h]
  int v40; // [rsp+78h] [rbp-60h]
  float v41; // [rsp+7Ch] [rbp-5Ch]
  int v42; // [rsp+80h] [rbp-58h]
  int v43; // [rsp+84h] [rbp-54h]
  int v44; // [rsp+88h] [rbp-50h]
  int v45; // [rsp+8Ch] [rbp-4Ch]
  int v46; // [rsp+90h] [rbp-48h]
  int v47; // [rsp+94h] [rbp-44h]
  int v48; // [rsp+98h] [rbp-40h]
  int v49; // [rsp+9Ch] [rbp-3Ch]
  int v50; // [rsp+A0h] [rbp-38h]
  int v51; // [rsp+A4h] [rbp-34h]
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> phitTest; // [rsp+A8h] [rbp-30h]
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+C8h] [rbp-10h]
  __int64 v54; // [rsp+F8h] [rbp+20h]
  Scaleform::Render::Point<float> p; // [rsp+1C8h] [rbp+F0h]
  Scaleform::Render::Point<float> ptOut; // [rsp+1E0h] [rbp+108h]

  v54 = -2i64;
  v3 = pdescr;
  v4 = pt;
  v5 = this;
  v6 = ((__int64 (*)(void))this->vfptr[121].__vecDelDtor)();
  if ( (v5->Flags >> 11) & 1
    || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v5->vfptr[59].__vecDelDtor)(v5) && !v6
    || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v5->vfptr[78].__vecDelDtor)(v5)
    || (Scaleform::GFx::DisplayObjContainer *)v3->pIgnoreMC == v5
    || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::MovieImpl *, _QWORD))v5->vfptr[85].__vecDelDtor)(
          v5,
          v5->pASRoot->pMovieImpl,
          v3->ControllerIdx) )
  {
    goto LABEL_38;
  }
  if ( !Scaleform::GFx::DisplayObject::TransformPointToLocalAndCheckBounds(
          (Scaleform::GFx::DisplayObject *)&v5->vfptr,
          &p,
          v4,
          1,
          0i64) )
    return 2i64;
  v7 = Scaleform::GFx::DisplayObject::GetMask((Scaleform::GFx::DisplayObject *)&v5->vfptr);
  v8 = v7;
  if ( v7 )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v7->vfptr[78].__vecDelDtor)(v7)
      && !((LOBYTE(v8->Flags) >> 4) & 1) )
    {
      if ( Scaleform::GFx::DisplayObjectBase::Has3D((Scaleform::GFx::DisplayObjectBase *)&v8->vfptr) )
      {
        memset(&pmat, 0, 0x30ui64);
        pmat.M[0][0] = 1.0;
        pmat.M[1][1] = 1.0;
        Dst.M[0][0] = 1.0;
        memset(Dst.M[1], 0, 0x40ui64);
        v46 = 1065353216;
        v51 = 1065353216;
        memset(&Dst.M[0][2], 0, 0x30ui64);
        Dst.M[1][3] = 1.0;
        Dst.M[0][2] = 1.0;
        v28 = v8->pParentChar;
        if ( v28 )
        {
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(v28, (Scaleform::Render::Matrix3x4<float> *)&Dst.M[0][2]);
          v29 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->vfptr[4].__vecDelDtor)(v8);
          *(_OWORD *)&m1.M[0][0] = *(_OWORD *)&Dst.M[0][2];
          *(_OWORD *)&m1.M[1][0] = *(_OWORD *)&Dst.M[1][2];
          *(_OWORD *)&m1.M[2][0] = *(_OWORD *)&Dst.M[0][0];
          Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
            (Scaleform::Render::Matrix3x4<float> *)&Dst.M[0][2],
            &m1,
            v29);
        }
        else
        {
          v30 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->vfptr[4].__vecDelDtor)(v8);
          *(_QWORD *)&Dst.M[0][2] = *(_QWORD *)v30;
          *(_OWORD *)&Dst.M[1][0] = *(_OWORD *)(v30 + 8);
          v40 = *(_DWORD *)(v30 + 24);
          v41 = *(float *)(v30 + 28);
          *(_OWORD *)&Dst.M[0][0] = *(_OWORD *)(v30 + 32);
        }
        v31 = (signed __int64)&v5->pASRoot->pMovieImpl->ScreenToWorld;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, float *, _QWORD))v8->vfptr[6].__vecDelDtor)(
               v8,
               Dst.M[1],
               0i64) )
        {
          *(_OWORD *)(v31 + 16) = *(_OWORD *)&Dst.M[1][0];
          *(_DWORD *)(v31 + 32) = v40;
          *(float *)(v31 + 36) = v41;
          *(_DWORD *)(v31 + 40) = v42;
          *(_DWORD *)(v31 + 44) = v43;
          *(_DWORD *)(v31 + 48) = v44;
          *(_DWORD *)(v31 + 52) = v45;
          *(_DWORD *)(v31 + 56) = v46;
          *(_DWORD *)(v31 + 60) = v47;
          *(_DWORD *)(v31 + 64) = v48;
          *(_DWORD *)(v31 + 68) = v49;
          *(_DWORD *)(v31 + 72) = v50;
          *(_DWORD *)(v31 + 76) = v51;
        }
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Matrix2x4<float> *, _QWORD))v8->vfptr[9].__vecDelDtor)(
               v8,
               &pmat,
               0i64) )
        {
          *(_OWORD *)(v31 + 80) = *(_OWORD *)&pmat.M[0][0];
          *(_OWORD *)(v31 + 96) = *(_OWORD *)&pmat.M[1][0];
          *(_DWORD *)(v31 + 112) = v37;
          *(_DWORD *)(v31 + 116) = v38;
          *(_QWORD *)(v31 + 120) = *(_QWORD *)&Dst.M[0][0];
        }
        *(_QWORD *)(v31 + 128) = *(_QWORD *)&Dst.M[0][2];
        *(_OWORD *)(v31 + 136) = *(_OWORD *)&Dst.M[1][0];
        *(_DWORD *)(v31 + 152) = v40;
        *(float *)(v31 + 156) = v41;
        *(_OWORD *)(v31 + 160) = *(_OWORD *)&Dst.M[0][0];
        Scaleform::Render::ScreenToWorld::GetWorldPoint((Scaleform::Render::ScreenToWorld *)v31, &ptOut);
      }
      else
      {
        *(_OWORD *)&Dst.M[0][2] = _xmm;
        *(__m128 *)&Dst.M[1][2] = _xmm;
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        v9 = v8->pParentChar;
        if ( v9 )
        {
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v9, &pmat);
          v10 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->vfptr[2].__vecDelDtor)(v8);
          v11 = *(_QWORD *)&pmat.M[0][0];
          v12 = *(_QWORD *)&pmat.M[1][0];
          pmat.M[0][0] = (float)(pmat.M[0][0] * *v10) + (float)(pmat.M[0][1] * v10[4]);
          pmat.M[1][0] = (float)(pmat.M[1][0] * *v10) + (float)(pmat.M[1][1] * v10[4]);
          pmat.M[0][1] = (float)(*(float *)&v11 * v10[1]) + (float)(pmat.M[0][1] * v10[5]);
          pmat.M[1][1] = (float)(*(float *)&v12 * v10[1]) + (float)(pmat.M[1][1] * v10[5]);
          pmat.M[1][2] = 0.0;
          pmat.M[0][2] = 0.0;
          pmat.M[0][3] = pmat.M[0][3]
                       + (float)((float)(*((float *)&v11 + 1) * v10[7]) + (float)(*(float *)&v11 * v10[3]));
          pmat.M[1][3] = pmat.M[1][3]
                       + (float)((float)(*((float *)&v12 + 1) * v10[7]) + (float)(*(float *)&v12 * v10[3]));
        }
        else
        {
          v13 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->vfptr[2].__vecDelDtor)(v8);
          *(_OWORD *)&pmat.M[0][0] = *v13;
          *(_OWORD *)&pmat.M[1][0] = v13[1];
        }
        Scaleform::Render::Matrix2x4<float>::SetInverse(
          (Scaleform::Render::Matrix2x4<float> *)((char *)&Dst + 8),
          &pmat);
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        v14 = v5->pParentChar;
        if ( v14 )
        {
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v14, &pmat);
          v15 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v5->vfptr[2].__vecDelDtor)(v5);
          v17 = *(_QWORD *)&pmat.M[0][0];
          v18 = *(_QWORD *)&pmat.M[1][0];
          v19 = (float)(pmat.M[0][1] * v15[4]) + (float)(pmat.M[0][0] * *v15);
          pmat.M[0][0] = (float)(pmat.M[0][1] * v15[4]) + (float)(pmat.M[0][0] * *v15);
          v20 = (float)(pmat.M[1][1] * v15[4]) + (float)(pmat.M[1][0] * *v15);
          pmat.M[1][0] = (float)(pmat.M[1][1] * v15[4]) + (float)(pmat.M[1][0] * *v15);
          v21 = (float)(*(float *)&v17 * v15[1]) + (float)(pmat.M[0][1] * v15[5]);
          pmat.M[0][1] = (float)(*(float *)&v17 * v15[1]) + (float)(pmat.M[0][1] * v15[5]);
          v22 = pmat.M[1][1] * v15[5];
          v23 = (float)(*(float *)&v18 * v15[1]) + v22;
          pmat.M[1][1] = (float)(*(float *)&v18 * v15[1]) + v22;
          pmat.M[1][2] = 0.0;
          pmat.M[0][2] = 0.0;
          v24 = (float)(*((float *)&v17 + 1) * v15[7]) + (float)(*(float *)&v17 * v15[3]);
          v25 = pmat.M[0][3] + v24;
          pmat.M[0][3] = pmat.M[0][3] + v24;
          v26 = pmat.M[1][3] + (float)((float)(*((float *)&v18 + 1) * v15[7]) + (float)(*(float *)&v18 * v15[3]));
        }
        else
        {
          v27 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v5->vfptr[2].__vecDelDtor)(v5);
          v19 = *v27;
          pmat.M[0][0] = *v27;
          v21 = v27[1];
          *(_QWORD *)&pmat.M[0][1] = *(_QWORD *)(v27 + 1);
          v25 = v27[3];
          pmat.M[0][3] = v27[3];
          v20 = v27[4];
          pmat.M[1][0] = v27[4];
          v23 = v27[5];
          *(_QWORD *)&pmat.M[1][1] = *(_QWORD *)(v27 + 5);
          v26 = v27[7];
        }
        ptOut.x = (float)((float)((float)((float)(Dst.M[0][3] * v23) + (float)(Dst.M[0][2] * v21)) * p.y)
                        + (float)((float)((float)(Dst.M[0][3] * v20) + (float)(Dst.M[0][2] * v19)) * p.x))
                + (float)(Dst.M[1][1] + (float)((float)(Dst.M[0][3] * v26) + (float)(Dst.M[0][2] * v25)));
        ptOut.y = (float)((float)((float)((float)(Dst.M[1][3] * v23) + (float)(Dst.M[1][2] * v21)) * p.y)
                        + (float)((float)((float)(Dst.M[1][3] * v20) + (float)(Dst.M[1][2] * v19)) * p.x))
                + (float)(v41 + (float)((float)(Dst.M[1][3] * v26) + (float)(Dst.M[1][2] * v25)));
      }
      LOBYTE(v16) = 1;
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Point<float> *, __int64))v8->vfptr[63].__vecDelDtor)(
              v8,
              &ptOut,
              v16) )
      {
LABEL_38:
        v3->pResult = 0i64;
        return 2i64;
      }
    }
  }
  ptOut = (Scaleform::Render::Point<float>)&phitTest;
  phitTest.Data.Data = 0i64;
  phitTest.Data.Size = 0i64;
  phitTest.Data.Policy.Capacity = 0i64;
  Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(v5, &phitTest, &p, 1);
  v32 = v5->AvmObjOffset;
  if ( v32 )
  {
    v33 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v5->vfptr + 4 * v32))[5].__vecDelDtor)();
    v34 = (*(__int64 (__fastcall **)(__int64, Scaleform::Render::Point<float> *, Scaleform::GFx::DisplayObjectBase::TopMostDescr *, Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *))(*(_QWORD *)v33 + 176i64))(
            v33,
            &p,
            v3,
            &phitTest);
  }
  else
  {
    v34 = 2;
  }
  ptOut = (Scaleform::Render::Point<float>)&phitTest;
  if ( phitTest.Data.Data )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return v34;
}   ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return v34;
}

// File Line: 406
// RVA: 0x8F0070
char __fastcall Scaleform::GFx::DisplayObjContainer::PointTestLocal(Scaleform::GFx::DisplayObjContainer *this, Scaleform::Render::Point<float> *pt, char hitTestMask)
{
  unsigned __int8 v3; // r13
  Scaleform::Render::Point<float> *v4; // r15
  Scaleform::GFx::DisplayObjContainer *v5; // rdi
  float *v7; // rax
  float v8; // xmm0_4
  unsigned __int64 v9; // rsi
  Scaleform::GFx::DisplayObject *v10; // rbx
  Scaleform::GFx::DisplayObjectBase *v11; // rcx
  float *v12; // rax
  __int64 v13; // kr00_8
  __int64 v14; // kr08_8
  _OWORD *v15; // rax
  Scaleform::GFx::DisplayObjectBase *v16; // rcx
  float *v17; // rax
  __int64 v18; // kr10_8
  __int64 v19; // kr18_8
  float v20; // xmm5_4
  float v21; // xmm9_4
  float v22; // xmm11_4
  float v23; // xmm0_4
  float v24; // xmm10_4
  float v25; // xmm2_4
  float v26; // xmm12_4
  float v27; // xmm13_4
  float *v28; // rax
  float v29; // xmm2_4
  signed __int64 v30; // rsi
  signed __int64 v31; // r14
  Scaleform::GFx::DisplayObjectBase *v32; // rbx
  _OWORD *v33; // rax
  char v34; // bl
  char pmat[40]; // [rsp+30h] [rbp-98h]
  __int64 v36; // [rsp+58h] [rbp-70h]
  __int64 v37; // [rsp+60h] [rbp-68h]
  Scaleform::Render::Matrix2x4<float> v38; // [rsp+70h] [rbp-58h]
  Scaleform::Render::Point<float> v39; // [rsp+118h] [rbp+50h]
  Scaleform::Render::Point<float> result; // [rsp+130h] [rbp+68h]

  v3 = hitTestMask;
  v4 = pt;
  v5 = this;
  if ( (this->Flags >> 11) & 1 )
    return 0;
  if ( !(this->Flags & 1) )
  {
    *(_OWORD *)&v38.M[0][0] = _xmm;
    *(__m128 *)&pmat[24] = _xmm;
    v7 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, char *, Scaleform::Render::Matrix2x4<float> *))this->vfptr[61].__vecDelDtor)(
                    this,
                    pmat,
                    &v38);
    if ( v4->x > v7[2] )
      return 0;
    if ( v4->x < *v7 )
      return 0;
    v8 = v4->y;
    if ( v8 > v7[3] || v8 < v7[1] )
      return 0;
  }
  if ( v3 & 2
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v5->vfptr[59].__vecDelDtor)(v5) )
  {
    return 0;
  }
  v9 = v5->mDisplayList.DisplayObjectArray.Data.Size;
  if ( v5->pMaskCharacter )
  {
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v5->vfptr[78].__vecDelDtor)(v5) )
    {
      v10 = v5->pMaskCharacter;
      if ( v10 )
      {
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v10->vfptr[78].__vecDelDtor)(v5->pMaskCharacter)
          && !((LOBYTE(v10->Flags) >> 4) & 1) )
        {
          *(_OWORD *)&v38.M[0][0] = _xmm;
          *(__m128 *)&pmat[24] = _xmm;
          *(_OWORD *)pmat = _xmm;
          *(__m128 *)&pmat[16] = _xmm;
          v11 = v10->pParentChar;
          if ( v11 )
          {
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v11, (Scaleform::Render::Matrix2x4<float> *)pmat);
            v12 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v10->vfptr[2].__vecDelDtor)(v10);
            v13 = *(_QWORD *)pmat;
            v14 = *(_QWORD *)&pmat[16];
            *(float *)pmat = (float)(*(float *)&pmat[4] * v12[4]) + (float)(*(float *)pmat * *v12);
            *(float *)&pmat[16] = (float)(*(float *)&pmat[20] * v12[4]) + (float)(*(float *)&pmat[16] * *v12);
            *(float *)&pmat[4] = (float)(*(float *)&v13 * v12[1]) + (float)(*(float *)&pmat[4] * v12[5]);
            *(float *)&pmat[20] = (float)(*(float *)&v14 * v12[1]) + (float)(*(float *)&pmat[20] * v12[5]);
            *(_DWORD *)&pmat[24] = 0;
            *(_DWORD *)&pmat[8] = 0;
            *(float *)&pmat[12] = *(float *)&pmat[12]
                                + (float)((float)(*((float *)&v13 + 1) * v12[7]) + (float)(*(float *)&v13 * v12[3]));
            *(float *)&pmat[28] = *(float *)&pmat[28]
                                + (float)((float)(*((float *)&v14 + 1) * v12[7]) + (float)(*(float *)&v14 * v12[3]));
          }
          else
          {
            v15 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v10->vfptr[2].__vecDelDtor)(v10);
            *(_OWORD *)pmat = *v15;
            *(_OWORD *)&pmat[16] = v15[1];
          }
          Scaleform::Render::Matrix2x4<float>::SetInverse(&v38, (Scaleform::Render::Matrix2x4<float> *)pmat);
          *(_OWORD *)pmat = _xmm;
          *(__m128 *)&pmat[16] = _xmm;
          v16 = v5->pParentChar;
          if ( v16 )
          {
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v16, (Scaleform::Render::Matrix2x4<float> *)pmat);
            v17 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v5->vfptr[2].__vecDelDtor)(v5);
            v18 = *(_QWORD *)pmat;
            v19 = *(_QWORD *)&pmat[16];
            v20 = (float)(*(float *)&pmat[4] * v17[4]) + (float)(*(float *)pmat * *v17);
            *(float *)pmat = (float)(*(float *)&pmat[4] * v17[4]) + (float)(*(float *)pmat * *v17);
            v21 = (float)(*(float *)&pmat[20] * v17[4]) + (float)(*(float *)&pmat[16] * *v17);
            *(float *)&pmat[16] = (float)(*(float *)&pmat[20] * v17[4]) + (float)(*(float *)&pmat[16] * *v17);
            v22 = (float)(*(float *)&v18 * v17[1]) + (float)(*(float *)&pmat[4] * v17[5]);
            *(float *)&pmat[4] = (float)(*(float *)&v18 * v17[1]) + (float)(*(float *)&pmat[4] * v17[5]);
            v23 = *(float *)&pmat[20] * v17[5];
            v24 = (float)(*(float *)&v19 * v17[1]) + v23;
            *(float *)&pmat[20] = (float)(*(float *)&v19 * v17[1]) + v23;
            *(_DWORD *)&pmat[24] = 0;
            *(_DWORD *)&pmat[8] = 0;
            v25 = (float)(*((float *)&v18 + 1) * v17[7]) + (float)(*(float *)&v18 * v17[3]);
            v26 = *(float *)&pmat[12] + v25;
            *(float *)&pmat[12] = *(float *)&pmat[12] + v25;
            v27 = *(float *)&pmat[28]
                + (float)((float)(*((float *)&v19 + 1) * v17[7]) + (float)(*(float *)&v19 * v17[3]));
          }
          else
          {
            v28 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v5->vfptr[2].__vecDelDtor)(v5);
            v20 = *v28;
            *(float *)pmat = *v28;
            v22 = v28[1];
            *(_QWORD *)&pmat[4] = *(_QWORD *)(v28 + 1);
            v26 = v28[3];
            *(float *)&pmat[12] = v28[3];
            v21 = v28[4];
            *(float *)&pmat[16] = v28[4];
            v24 = v28[5];
            *(_QWORD *)&pmat[20] = *(_QWORD *)(v28 + 5);
            v27 = v28[7];
          }
          result.x = (float)((float)((float)((float)(v21 * v38.M[0][1]) + (float)(v20 * v38.M[0][0])) * v4->x)
                           + (float)((float)((float)(v38.M[0][0] * v22) + (float)(v24 * v38.M[0][1])) * v4->y))
                   + (float)(v38.M[0][3] + (float)((float)(v38.M[0][1] * v27) + (float)(v38.M[0][0] * v26)));
          result.y = (float)((float)((float)((float)(v21 * *(float *)&pmat[28]) + (float)(v20 * *(float *)&pmat[24]))
                                   * v4->x)
                           + (float)((float)((float)(*(float *)&pmat[24] * v22) + (float)(v24 * *(float *)&pmat[28]))
                                   * v4->y))
                   + (float)(*(float *)&pmat[36]
                           + (float)((float)(*(float *)&pmat[28] * v27) + (float)(*(float *)&pmat[24] * v26)));
          if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Point<float> *, _QWORD))v10->vfptr[63].__vecDelDtor)(
                  v10,
                  &result,
                  v3) )
            return 0;
        }
      }
    }
  }
  result = (Scaleform::Render::Point<float>)&pmat[32];
  *(_QWORD *)&pmat[32] = 0i64;
  v36 = 0i64;
  v37 = 0i64;
  Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(
    v5,
    (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&pmat[32],
    v4,
    v3 & 1);
  *(_OWORD *)pmat = _xmm;
  *(__m128 *)&pmat[16] = _xmm;
  v29 = v4->y;
  v39.x = v4->x;
  v39.y = v29;
  v30 = v9 - 1;
  if ( v30 < 0 )
  {
LABEL_33:
    v34 = 0;
  }
  else
  {
    v31 = v30;
    while ( 1 )
    {
      v32 = v5->mDisplayList.DisplayObjectArray.Data.Data[v31].pCharacter;
      if ( (!(v3 & 2)
         || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v32->vfptr[59].__vecDelDtor)(v32))
        && (!v36 || *(_BYTE *)(*(_QWORD *)&pmat[32] + v30) && !v32->ClipDepth) )
      {
        v33 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v32->vfptr[2].__vecDelDtor)(v32);
        *(_OWORD *)pmat = *v33;
        *(_OWORD *)&pmat[16] = v33[1];
        Scaleform::Render::Matrix2x4<float>::TransformByInverse(
          (Scaleform::Render::Matrix2x4<float> *)pmat,
          &result,
          v4);
        v39 = result;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, _QWORD))v32->vfptr[63].__vecDelDtor)(
               v32,
               &v39,
               v3) )
        {
          break;
        }
      }
      --v31;
      if ( --v30 < 0 )
        goto LABEL_33;
    }
    v34 = 1;
  }
  result = (Scaleform::Render::Point<float>)&pmat[32];
  if ( *(_QWORD *)&pmat[32] )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v34;
}

// File Line: 461
// RVA: 0x8F3C10
void __fastcall Scaleform::GFx::DisplayObjContainer::PropagateFocusGroupMask(Scaleform::GFx::DisplayObjContainer *this, unsigned int mask)
{
  unsigned __int64 v2; // rdi
  unsigned int v3; // esi
  Scaleform::GFx::DisplayObjContainer *v4; // rbp
  __int64 v5; // rbx
  Scaleform::GFx::DisplayObjectBase *v6; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *v7; // rax

  v2 = this->mDisplayList.DisplayObjectArray.Data.Size;
  v3 = mask;
  v4 = this;
  this->FocusGroupMask = mask;
  if ( v2 )
  {
    v5 = 0i64;
    do
    {
      v6 = 0i64;
      if ( SLOBYTE(v4->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter->Flags) < 0 )
        v6 = v4->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter;
      if ( v6 )
      {
        v7 = v6->vfptr;
        HIWORD(v6[1].pRenNode.pObject) = v3;
        v7[106].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, v3);
      }
      ++v5;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 475
// RVA: 0x8D6300
void __fastcall Scaleform::GFx::DisplayObjContainer::GetChildDescTree(Scaleform::GFx::DisplayObjContainer *this, Scaleform::AmpMovieObjectDesc *parent, Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v3; // r9
  Scaleform::GFx::DisplayObjContainer *v4; // rax
  unsigned __int64 v5; // rbp
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2,Scaleform::ArrayDefaultPolicy> *v6; // rdi
  signed __int64 v7; // rcx
  __int64 v8; // rsi
  __int64 v9; // rbx
  _QWORD *v10; // rax
  Scaleform::GFx::DisplayObject *v11; // rcx
  const char ***v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  _QWORD *v15; // rdi
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-58h]
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2,Scaleform::ArrayDefaultPolicy> *v17; // [rsp+28h] [rbp-50h]
  __int64 v18; // [rsp+30h] [rbp-48h]
  __int64 v19; // [rsp+38h] [rbp-40h]
  _QWORD *v20; // [rsp+40h] [rbp-38h]
  _QWORD *v21; // [rsp+48h] [rbp-30h]
  __int64 v22; // [rsp+50h] [rbp-28h]
  Scaleform::GFx::DisplayObjContainer *v23; // [rsp+80h] [rbp+8h]
  Scaleform::MemoryHeap *heapa; // [rsp+90h] [rbp+18h]
  __int64 v25; // [rsp+98h] [rbp+20h]

  heapa = heap;
  v23 = this;
  v18 = -2i64;
  v3 = heap;
  v4 = this;
  v5 = 0i64;
  if ( this->mDisplayList.DisplayObjectArray.Data.Size )
  {
    v6 = &parent->Children;
    v17 = &parent->Children;
    v7 = 0i64;
    v25 = 0i64;
    do
    {
      v8 = *(__int64 *)((char *)&v4->mDisplayList.DisplayObjectArray.Data.Data->pCharacter + v7);
      v9 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->vfptr->Alloc)(v3, 48i64);
      v19 = v9;
      if ( v9 )
      {
        *(_QWORD *)v9 = &Scaleform::RefCountImplCore::`vftable;
        *(_DWORD *)(v9 + 8) = 1;
        *(_QWORD *)v9 = &Scaleform::RefCountImpl::`vftable;
        *(_QWORD *)v9 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
        *(_QWORD *)v9 = &Scaleform::RefCountBase<Scaleform::AmpMovieObjectDesc,2>::`vftable;
        *(_QWORD *)v9 = &Scaleform::AmpMovieObjectDesc::`vftable;
        Scaleform::StringLH::StringLH((Scaleform::StringLH *)(v9 + 16));
        v10 = (_QWORD *)(v9 + 24);
        v20 = v10;
        v21 = (_QWORD *)(v9 + 24);
        v11 = 0i64;
        *v10 = 0i64;
        v10[1] = 0i64;
        v10[2] = 0i64;
      }
      else
      {
        v11 = 0i64;
        v9 = 0i64;
      }
      if ( *(_BYTE *)(v8 + 107) & 1 )
        v11 = (Scaleform::GFx::DisplayObject *)v8;
      if ( v11 )
      {
        v12 = (const char ***)Scaleform::GFx::DisplayObject::GetName(v11, &result);
        Scaleform::String::operator=((Scaleform::String *)(v9 + 16), **v12);
        v13 = result.pNode;
        v14 = result.pNode->RefCount == 1;
        --v13->RefCount;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      }
      else
      {
        Scaleform::String::operator=((Scaleform::String *)(v9 + 16), "Unnamed");
      }
      v22 = v9;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2>,Scaleform::ArrayDefaultPolicy> *)&v6->Data.Data,
        v6,
        v6->Data.Size + 1);
      v15 = &v6->Data.Data[v6->Data.Size - 1].pObject;
      v21 = v15;
      v20 = v15;
      if ( v15 )
      {
        if ( v9 )
          Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v9);
        *v15 = v9;
      }
      if ( v9 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
      if ( (*(_WORD *)(v8 + 106) >> 9) & 1 )
        Scaleform::GFx::DisplayObjContainer::GetChildDescTree(
          (Scaleform::GFx::DisplayObjContainer *)v8,
          (Scaleform::AmpMovieObjectDesc *)v9,
          heapa);
      ++v5;
      v7 = v25 + 16;
      v25 += 16i64;
      v4 = v23;
      v3 = heapa;
      v6 = v17;
    }
    while ( v5 < v23->mDisplayList.DisplayObjectArray.Data.Size );
  }
}

// File Line: 500
// RVA: 0x8CB380
void __fastcall Scaleform::GFx::DisplayObjContainer::FillTabableArray(Scaleform::GFx::DisplayObjContainer *this, Scaleform::GFx::InteractiveObject::FillTabableParams *params)
{
  unsigned __int8 v2; // al
  Scaleform::GFx::InteractiveObject::FillTabableParams *v3; // rbx
  __int64 v4; // rax

  v2 = this->AvmObjOffset;
  v3 = params;
  if ( v2 )
  {
    v4 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v2))[5].__vecDelDtor)();
    (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject::FillTabableParams *))(*(_QWORD *)v4 + 184i64))(
      v4,
      v3);
  }
}

// File Line: 506
// RVA: 0x8BDC20
char __fastcall Scaleform::GFx::DisplayObjContainer::Contains(Scaleform::GFx::DisplayObjContainer *this, Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rsi
  Scaleform::GFx::DisplayObjContainer *v3; // rbp
  unsigned __int64 v5; // rbx
  __int64 v6; // rdi
  Scaleform::GFx::DisplayObjContainer *v7; // rcx

  v2 = ch;
  v3 = this;
  if ( this == (Scaleform::GFx::DisplayObjContainer *)ch
    || ch && (Scaleform::GFx::DisplayObjContainer *)ch->pParent == this )
  {
    return 1;
  }
  v5 = 0i64;
  if ( !this->mDisplayList.DisplayObjectArray.Data.Size )
    return 0;
  v6 = 0i64;
  while ( 1 )
  {
    v7 = 0i64;
    if ( (v3->mDisplayList.DisplayObjectArray.Data.Data[v6].pCharacter->Flags >> 9) & 1 )
      v7 = (Scaleform::GFx::DisplayObjContainer *)v3->mDisplayList.DisplayObjectArray.Data.Data[v6].pCharacter;
    if ( v7 && Scaleform::GFx::DisplayObjContainer::Contains(v7, v2) )
      break;
    ++v5;
    ++v6;
    if ( v5 >= v3->mDisplayList.DisplayObjectArray.Data.Size )
      return 0;
  }
  return 1;
}

// File Line: 523
// RVA: 0x8D8460
Scaleform::GFx::FontManager *__fastcall Scaleform::GFx::DisplayObjContainer::GetFontManager(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::MovieDefRootNode *v1; // rax
  Scaleform::GFx::InteractiveObject *v2; // rdx

  v1 = this->pRootNode;
  if ( v1 )
    return v1->pFontManager.pObject;
  v2 = this->pParent;
  if ( !v2 )
  {
    v1 = this->pASRoot->pMovieImpl->RootMovieDefNodes.Root.pNext;
    return v1->pFontManager.pObject;
  }
  return (Scaleform::GFx::FontManager *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v2->vfptr[67].__vecDelDtor)(this->pParent);
}

// File Line: 535
// RVA: 0x90C370
void __fastcall Scaleform::GFx::DisplayObjContainer::SetStateChangeFlags(Scaleform::GFx::DisplayObjContainer *this, char flags)
{
  unsigned __int64 v2; // rsi
  unsigned __int8 v3; // bp
  Scaleform::GFx::DisplayObjContainer *v4; // rdi
  __int64 v5; // rbx

  this->Flags &= 0xFFF0FFFF;
  v2 = this->mDisplayList.DisplayObjectArray.Data.Size;
  v3 = flags;
  v4 = this;
  this->Flags |= (flags & 0xF) << 16;
  if ( v2 )
  {
    v5 = 0i64;
    do
    {
      v4->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter->vfptr[79].__vecDelDtor(
        (Scaleform::RefCountNTSImplCore *)v4->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter,
        v3);
      ++v5;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 627
// RVA: 0x8CE420
void __fastcall Scaleform::GFx::DisplayObjContainer::ForceShutdown(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, (Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
}

// File Line: 633
// RVA: 0x8E2D20
char __fastcall Scaleform::GFx::DisplayObjContainer::Has3D(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::DisplayObjContainer *v1; // rsi
  Scaleform::Render::TreeNode *v2; // rcx
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // rbx
  __int64 v6; // rdi
  Scaleform::GFx::DisplayObjectBase *v7; // rcx

  v1 = this;
  v2 = this->pRenNode.pObject;
  if ( v2
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1]
                                                                                       - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 10i64) >> 9) & 1 )
  {
    return 1;
  }
  v4 = v1->mDisplayList.DisplayObjectArray.Data.Size;
  v5 = 0i64;
  if ( !v4 )
    return 0;
  v6 = 0i64;
  while ( 1 )
  {
    v7 = v1->mDisplayList.DisplayObjectArray.Data.Data[v6].pCharacter;
    if ( v7 )
    {
      if ( ((unsigned __int8 (*)(void))v7->vfptr[14].__vecDelDtor)() )
        break;
    }
    ++v5;
    ++v6;
    if ( v5 >= v4 )
      return 0;
  }
  return 1;
}

// File Line: 648
// RVA: 0x918450
void __fastcall Scaleform::GFx::DisplayObjContainer::UpdateViewAndPerspective(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::DisplayObjContainer *v1; // rsi
  unsigned __int64 v2; // rdi
  __int64 v3; // rbx
  Scaleform::GFx::DisplayObjectBase *v4; // rcx

  v1 = this;
  Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  v2 = v1->mDisplayList.DisplayObjectArray.Data.Size;
  if ( v2 )
  {
    v3 = 0i64;
    do
    {
      v4 = v1->mDisplayList.DisplayObjectArray.Data.Data[v3].pCharacter;
      if ( v4 )
        ((void (*)(void))v4->vfptr[12].__vecDelDtor)();
      ++v3;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 671
// RVA: 0x8F4BB0
void __fastcall Scaleform::GFx::DisplayObjContainer::PropagateScale9GridExists(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::DisplayObjContainer *v1; // rbx
  bool v2; // al
  bool v3; // bp
  unsigned __int64 v4; // rsi
  __int64 v5; // rdi
  Scaleform::GFx::DisplayObjectBase *v6; // rcx

  v1 = this;
  v2 = Scaleform::GFx::DisplayObjectBase::HasScale9Grid((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  v3 = v2;
  if ( v1->Flags & 1 || !v2 )
  {
    v4 = v1->mDisplayList.DisplayObjectArray.Data.Size;
    if ( v4 )
    {
      v5 = 0i64;
      do
      {
        v6 = v1->mDisplayList.DisplayObjectArray.Data.Data[v5].pCharacter;
        if ( v1->Flags & 1 || v3 )
          v6->Flags |= 1u;
        else
          v6->Flags &= 0xFFFEu;
        ((void (*)(void))v6->vfptr[20].__vecDelDtor)();
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}

