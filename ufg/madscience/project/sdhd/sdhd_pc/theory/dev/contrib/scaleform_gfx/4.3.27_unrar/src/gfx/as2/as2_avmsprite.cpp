// File Line: 59
// RVA: 0x6C76B0
void __fastcall Scaleform::GFx::AS2::AvmSprite::AvmSprite(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::Sprite *psprite)
{
  __int64 v4; // rsi
  char *v5; // rcx
  unsigned int v6; // ebx
  Scaleform::GFx::AS2::Object *ActualPrototype; // rax
  Scaleform::GFx::AS2::Object *v8; // rbx
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS2::AvmCharacter::AvmCharacter(this, psprite);
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjContainerBase::`vftable;
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmSpriteBase::`vftable;
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable;
  Scaleform::GFx::AS2::Environment::Environment(&this->ASEnvironment);
  this->Level = -1;
  v4 = 0i64;
  this->ASMovieClipObj.pObject = 0i64;
  this->InitActionsExecuted.Data.Data = 0i64;
  this->InitActionsExecuted.Data.Size = 0i64;
  this->InitActionsExecuted.Data.Policy.Capacity = 0i64;
  this->TabChildren.Value = 0;
  this->ASEnvironment.Target = psprite;
  *((_BYTE *)&this->ASEnvironment + 382) &= ~2u;
  this->ASEnvironment.StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(psprite);
  if ( psprite )
  {
    v5 = (char *)psprite + 4 * (unsigned __int8)psprite->AvmObjOffset;
    v4 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 8i64))(v5);
  }
  this->ASEnvironment.StringContext.pContext = (Scaleform::GFx::AS2::GlobalContext *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 184i64))(v4);
  LOBYTE(this->pDispObj[1].pIndXFormData) &= ~0x20u;
  this->pDispObj->Flags |= 0x800u;
  v6 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj[1].pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::$CFA0FEAB6C317A8124CFA738756F89CC::vfptr[10].__vecDelDtor)(this->pDispObj[1].pParent);
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->InitActionsExecuted.Data,
    v6);
  memset(this->InitActionsExecuted.Data.Data, 0, v6);
  ActualPrototype = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
                      (Scaleform::GFx::AS2::GlobalContext *)this->pDispObj->pASRoot[2].vfptr,
                      &this->ASEnvironment,
                      ASBuiltin_MovieClip);
  v8 = ActualPrototype;
  if ( ActualPrototype )
    ActualPrototype->RefCount = (ActualPrototype->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->pProto.pObject = v8;
}

// File Line: 85
// RVA: 0x6D0F90
void __fastcall Scaleform::GFx::AS2::AvmSprite::~AvmSprite(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AvmSpriteBase *v2; // rdi
  Scaleform::GFx::AS2::MovieClipObject *pObject; // rcx
  unsigned int RefCount; // eax

  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v2 = &this->Scaleform::GFx::AvmSpriteBase;
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->InitActionsExecuted.Data.Data);
  pObject = this->ASMovieClipObj.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  Scaleform::GFx::AS2::Environment::~Environment(&this->ASEnvironment);
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  Scaleform::GFx::AS2::AvmCharacter::~AvmCharacter(this);
}

// File Line: 89
// RVA: 0x700AD0
_BOOL8 __fastcall Scaleform::GFx::AS2::AvmSprite::IsLevelMovie(Scaleform::GFx::AS2::AvmSprite *this)
{
  return *((_DWORD *)&this->ASEnvironment.ThrowingValue.NV + 6) >= 0;
}

// File Line: 108
// RVA: 0x6E8D00
void __fastcall Scaleform::GFx::AS2::AvmSprite::ExecuteInitActionFrameTags(
        Scaleform::GFx::AS2::AvmSprite *this,
        unsigned int frame)
{
  __int64 v3; // r14
  Scaleform::RefCountNTSImpl *Capacity; // rdi
  unsigned int v5; // ebx
  __int64 v6; // [rsp+28h] [rbp-20h] BYREF
  unsigned int v7; // [rsp+30h] [rbp-18h]

  v3 = frame;
  if ( !*((_BYTE *)&this->ASEnvironment.LocalFrames.Data.Data->pObject + frame) )
  {
    Capacity = (Scaleform::RefCountNTSImpl *)this[-1].InitActionsExecuted.Data.Policy.Capacity;
    if ( Capacity )
      ++Capacity->RefCount;
    v5 = 0;
    v6 = 0i64;
    v7 = 0;
    if ( (*(unsigned __int8 (__fastcall **)(_QWORD, __int64 *, _QWORD))(**(_QWORD **)(this[-1].InitActionsExecuted.Data.Policy.Capacity
                                                                                    + 272)
                                                                      + 96i64))(
           *(_QWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 272),
           &v6,
           frame)
      && v7 )
    {
      do
      {
        (*(void (__fastcall **)(_QWORD, unsigned __int64))(**(_QWORD **)(v6 + 8i64 * v5) + 8i64))(
          *(_QWORD *)(v6 + 8i64 * v5),
          this[-1].InitActionsExecuted.Data.Policy.Capacity);
        ++v5;
      }
      while ( v5 < v7 );
      *((_BYTE *)&this->ASEnvironment.LocalFrames.Data.Data->pObject + v3) = 1;
    }
    if ( Capacity )
      Scaleform::RefCountNTSImpl::Release(Capacity);
  }
}

// File Line: 165
// RVA: 0x6DDE10
void __fastcall Scaleform::GFx::AS2::AvmSprite::CloneInternalData(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::InteractiveObject *src)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *v4; // rax
  char *v5; // rcx
  unsigned __int8 AvmObjOffset; // al
  __int64 v7; // rax
  Scaleform::GFx::AS2::MovieClipObject *MovieClipObject; // rax

  if ( src )
  {
    v5 = (char *)src + 4 * (unsigned __int8)src->AvmObjOffset;
    v4 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 8i64))(v5);
  }
  else
  {
    v4 = 0i64;
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::Assign(
    &this->EventHandlers.mHash,
    &this->EventHandlers,
    v4 + 4);
  if ( (src->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
  {
    AvmObjOffset = src->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v7 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&src->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                    + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)src + 4 * AvmObjOffset);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v7 + 96i64))(v7) )
      {
        MovieClipObject = Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject(this);
        if ( MovieClipObject )
          MovieClipObject->HasButtonHandlers = 1;
      }
    }
  }
}

// File Line: 177
// RVA: 0x6FB180
char __fastcall Scaleform::GFx::AS2::AvmSprite::HasEventHandler(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::AS2::MovieClipObject *pObject; // rcx
  char v6; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value v9; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h] BYREF

  if ( Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(this, id) )
    return 1;
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)&this->pDispObj->pASRoot[7].AVMVersion,
    id);
  if ( result.pNode->Size )
  {
    v9.T.Type = 0;
    pObject = this->ASMovieClipObj.pObject;
    if ( pObject || (pObject = (Scaleform::GFx::AS2::MovieClipObject *)this->pProto.pObject) != 0i64 )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))pObject->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw)(
             &pObject->Scaleform::GFx::AS2::ObjectInterface,
             &this->ASEnvironment.StringContext,
             &result,
             &v9,
             -2i64) )
      {
        if ( v9.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v9);
        v6 = 1;
        goto LABEL_13;
      }
    }
    if ( v9.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v9);
  }
  v6 = 0;
LABEL_13:
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return v6;
}

// File Line: 206
// RVA: 0x6DC180
void __fastcall Scaleform::GFx::AS2::AvmSprite::CallFrameActions(
        Scaleform::GFx::AS2::AvmSprite *this,
        unsigned int frameNumber)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rcx
  volatile int RefCount; // r14d
  unsigned int v6; // ebp
  __int64 i; // rbx
  __int64 v8; // rdi
  __int64 v9; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v10; // [rsp+28h] [rbp-10h]

  if ( frameNumber == -1
    || frameNumber >= ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[111].__vecDelDtor)(this->pDispObj) )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogError(
      &this->pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "CallFrame(%d) - unknown frame",
      frameNumber);
  }
  else
  {
    pASRoot = this->pDispObj->pASRoot;
    RefCount = pASRoot[7].RefCount;
    v6 = LODWORD(pASRoot[7].pMovieImpl) + 1;
    LODWORD(pASRoot[7].pMovieImpl) = v6;
    pASRoot[7].RefCount = v6;
    ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64 *, _QWORD))this->pDispObj[1].pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::$CFA0FEAB6C317A8124CFA738756F89CC::vfptr[11].__vecDelDtor)(
      this->pDispObj[1].pParent,
      &v9,
      frameNumber);
    for ( i = 0i64; (unsigned int)i < v10; i = (unsigned int)(i + 1) )
    {
      v8 = *(_QWORD *)(v9 + 8 * i);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v8 + 32i64))(v8) )
        (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v8 + 8i64))(
          v8,
          this->pDispObj);
    }
    this->pDispObj->pASRoot[7].RefCount = RefCount;
    Scaleform::GFx::AS2::MovieRoot::DoActionsForSession((Scaleform::GFx::AS2::MovieRoot *)this->pDispObj->pASRoot, v6);
  }
}

// File Line: 242
// RVA: 0x705C00
void __fastcall Scaleform::GFx::AS2::AvmSprite::OnEventLoad(Scaleform::GFx::AS2::AvmSprite *this)
{
  unsigned int v1; // edi
  signed __int64 v3; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> >::TableType *v4; // rax
  Scaleform::GFx::ActionPriority::Priority v5; // edx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::InteractiveObject *pDispObj; // rbp
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v8; // rbx
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::RefCountNTSImpl *v10; // rcx
  Scaleform::GFx::ASSupport *v11; // rbp
  __int64 v12; // rax
  Scaleform::GFx::InteractiveObject *v13; // rbx
  __int64 v14; // r14
  Scaleform::RefCountImplCoreVtbl *v15; // rcx
  unsigned int v16; // [rsp+2Ch] [rbp-2Ch]
  Scaleform::GFx::EventId key; // [rsp+34h] [rbp-24h] BYREF

  *(_QWORD *)&key.Id = 1i64;
  v1 = 0;
  key.KeyCode = 0;
  LOBYTE(v16) = 0;
  key.TouchID = v16;
  *(_DWORD *)&key.RollOverCnt = 65280;
  v3 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::findIndexAlt<Scaleform::GFx::EventId>(
         &this->EventHandlers.mHash,
         &key);
  if ( v3 < 0
    || (v4 = &this->EventHandlers.mHash.pTable[4 * v3 + 2]) == 0i64
    || (v5 = AP_Frame,
        v4 == (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> >::TableType *)-24i64) )
  {
    v5 = AP_Load;
  }
  inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
               (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].RefCount,
               v5);
  pDispObj = this->pDispObj;
  inserted->Type = Entry_Event;
  v8 = inserted;
  if ( pDispObj )
    ++pDispObj->RefCount;
  pObject = inserted->pCharacter.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v8->pCharacter.pObject = pDispObj;
  v10 = v8->pActionBuffer.pObject;
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  v8->pActionBuffer.pObject = 0i64;
  *(_QWORD *)&v8->mEventId.Id = 1i64;
  v8->mEventId.KeyCode = 0;
  v8->mEventId.AsciiCode = 0;
  *(_DWORD *)&v8->mEventId.RollOverCnt = 65280;
  this->pDispObj->Flags |= 0x20u;
  Scaleform::GFx::AS2::AvmSprite::ExecuteInitActionFrameTags(
    (Scaleform::GFx::AS2::AvmSprite *)&this->Scaleform::GFx::AvmSpriteBase,
    0);
  Scaleform::GFx::Sprite::DefaultOnEventLoad((Scaleform::GFx::Sprite *)this->pDispObj);
  v11 = this->pDispObj->pASRoot[39].pASSupport.pObject;
  if ( v11 )
  {
    v12 = 0i64;
    do
    {
      v13 = this->pDispObj;
      v14 = v12;
      v15 = (&v13->pASRoot[39].pMovieImpl->vfptr)[v12];
      if ( v13 == (Scaleform::GFx::InteractiveObject *)(*((__int64 (__fastcall **)(Scaleform::RefCountImplCoreVtbl *))v15->__vecDelDtor
                                                        + 120))(v15) )
        Scaleform::GFx::Sprite::SetHitArea(
          (Scaleform::GFx::Sprite *)(&this->pDispObj->pASRoot[39].pMovieImpl->vfptr)[v14],
          (Scaleform::GFx::Sprite *)this->pDispObj);
      v12 = ++v1;
    }
    while ( v1 < (unsigned __int64)v11 );
  }
}

// File Line: 280
// RVA: 0x714650
void __fastcall Scaleform::GFx::AS2::AvmSprite::SetHitAreaNotify(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::Sprite *phitArea)
{
  unsigned __int64 Capacity; // r9
  __int64 v5; // rdx
  unsigned __int64 v6; // r8
  int v7; // eax
  __int64 v8; // rcx
  __int64 v9; // rdx
  Scaleform::RefCountNTSImpl *v10; // rdi
  __int64 v11; // rbx
  Scaleform::RefCountNTSImpl **v12; // rdx

  Capacity = this[-1].InitActionsExecuted.Data.Policy.Capacity;
  v5 = *(_QWORD *)(Capacity + 32);
  v6 = *(_QWORD *)(v5 + 1584);
  if ( *(_QWORD *)(Capacity + 296) && (v7 = 0, v6) )
  {
    v8 = 0i64;
    v9 = *(_QWORD *)(v5 + 1576);
    while ( *(_QWORD *)(v9 + 8 * v8) != Capacity )
    {
      v8 = (unsigned int)++v7;
      if ( (unsigned int)v7 >= v6 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v7 = -1;
  }
  if ( phitArea )
  {
    if ( v7 == -1 )
    {
      v10 = (Scaleform::RefCountNTSImpl *)Capacity;
      if ( Capacity )
        ++*(_DWORD *)(Capacity + 8);
      v11 = *(_QWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 32);
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)(v11 + 1576),
        (const void *)(v11 + 1576),
        *(_QWORD *)(v11 + 1584) + 1i64);
      v12 = (Scaleform::RefCountNTSImpl **)(*(_QWORD *)(v11 + 1576) + 8 * (*(_QWORD *)(v11 + 1584) - 1i64));
      if ( v12 )
      {
        if ( v10 )
          ++v10->RefCount;
        *v12 = v10;
      }
      if ( v10 )
        Scaleform::RefCountNTSImpl::Release(v10);
    }
  }
  else if ( v7 > -1 )
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> > *)(*(_QWORD *)(Capacity + 32) + 1576i64),
      v7);
  }
}

// File Line: 298
// RVA: 0x6F6A60
__int64 __fastcall Scaleform::GFx::AS2::AvmSprite::GetTopMostEntity(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::Render::Point<float> *localPt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr,
        Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *hitTest)
{
  Scaleform::GFx::InteractiveObject *Capacity; // rdi
  Scaleform::GFx::AS2::AvmSprite *v5; // rsi
  Scaleform::Render::Point<float> *v7; // r13
  Scaleform::GFx::InteractiveObject *v8; // r14
  __int64 v9; // rax
  float v10; // xmm6_4
  float x; // xmm7_4
  Scaleform::GFx::InteractiveObject *v12; // rcx
  Scaleform::GFx::InteractiveObject *v13; // r8
  Scaleform::GFx::DisplayObject *v14; // r9
  unsigned int v15; // r10d
  bool v16; // r11
  char v17; // dl
  __int64 v18; // r15
  Scaleform::GFx::DisplayObject *v19; // r12
  int v20; // ebp
  __int64 v21; // r13
  __int64 v22; // rcx
  int v23; // eax
  int v24; // esi
  unsigned __int8 AvmObjOffset; // al
  __int64 v26; // rax
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  __int64 result; // rax
  unsigned __int8 v29; // al
  __int64 v30; // rax
  Scaleform::GFx::InteractiveObject *v31; // rax
  Scaleform::GFx::InteractiveObject *pResult; // rax
  float y; // xmm0_4
  char v34; // [rsp+20h] [rbp-A8h]
  bool TestAll; // [rsp+21h] [rbp-A7h]
  unsigned int ControllerIdx; // [rsp+24h] [rbp-A4h]
  Scaleform::GFx::InteractiveObject *v37; // [rsp+28h] [rbp-A0h]
  Scaleform::GFx::DisplayObject *pHitArea; // [rsp+30h] [rbp-98h]
  Scaleform::GFx::InteractiveObject *pIgnoreMC; // [rsp+38h] [rbp-90h]
  Scaleform::GFx::InteractiveObject *v40; // [rsp+40h] [rbp-88h]
  float v41; // [rsp+48h] [rbp-80h]
  float v42; // [rsp+4Ch] [rbp-7Ch]

  Capacity = (Scaleform::GFx::InteractiveObject *)this[-1].InitActionsExecuted.Data.Policy.Capacity;
  v5 = this;
  v7 = localPt;
  v8 = (Scaleform::GFx::InteractiveObject *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))Capacity->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[121].__vecDelDtor)(Capacity);
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))Capacity->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[120].__vecDelDtor)(Capacity);
  v10 = v42;
  x = v41;
  v12 = v40;
  v13 = 0i64;
  v14 = 0i64;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = *(_QWORD *)(v5[-1].InitActionsExecuted.Data.Policy.Capacity + 224) - 1i64;
  v19 = (Scaleform::GFx::DisplayObject *)v9;
  pIgnoreMC = 0i64;
  pHitArea = 0i64;
  ControllerIdx = 0;
  TestAll = 0;
  v20 = 2;
  v34 = 0;
  if ( v18 < 0 )
  {
LABEL_45:
    if ( v19
      && ((pResult = pdescr->pResult) == 0i64
       || pResult == Capacity
       || SLOBYTE(pResult->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >= 0) )
    {
      if ( v19 != pdescr->pHitArea )
        goto LABEL_28;
    }
    else
    {
      if ( v20 == 1 )
      {
        pdescr->pResult = v12;
        pdescr->LocalPt.x = x;
        pdescr->LocalPt.y = v10;
        pdescr->pIgnoreMC = v13;
        pdescr->pHitArea = v14;
        pdescr->ControllerIdx = v15;
        pdescr->TestAll = v16;
        return 1i64;
      }
      y = v7->y;
      pdescr->LocalPt.x = v7->x;
      pdescr->LocalPt.y = y;
      if ( !v17 )
      {
        result = 3i64;
        goto LABEL_57;
      }
    }
LABEL_50:
    pdescr->pResult = Capacity;
    return 1i64;
  }
  v37 = v40;
  v21 = 16 * v18;
  while ( 1 )
  {
    v22 = *(_QWORD *)(v21 + *(_QWORD *)(v5[-1].InitActionsExecuted.Data.Policy.Capacity + 216));
    if ( hitTest->Data.Size && (!hitTest->Data.Data[v18] || *(_WORD *)(v22 + 104)) || (*(_BYTE *)(v22 + 106) & 2) != 0 )
      goto LABEL_42;
    v23 = (*(__int64 (__fastcall **)(__int64, Scaleform::Render::Point<float> *, Scaleform::GFx::DisplayObjectBase::TopMostDescr *))(*(_QWORD *)v22 + 512i64))(
            v22,
            localPt,
            pdescr);
    v24 = v23;
    if ( v23 != 1 )
      break;
    if ( (Capacity->Flags & 0x2000) != 0 )
      pdescr->pResult = Capacity;
    if ( !pdescr->pResult || (pdescr->pResult->Flags & 0x1000) == 0 )
    {
      if ( pdescr->TestAll )
        v24 = 1;
      goto LABEL_18;
    }
    v5 = this;
    v17 = 1;
    pdescr->pResult = Capacity;
    v34 = 1;
LABEL_43:
    v21 -= 16i64;
    if ( --v18 < 0 )
    {
      v12 = v37;
      v7 = localPt;
      v13 = pIgnoreMC;
      v14 = pHitArea;
      v15 = ControllerIdx;
      v16 = TestAll;
      goto LABEL_45;
    }
  }
  if ( v23 == 3 && pdescr->pResult )
  {
    x = pdescr->LocalPt.x;
    v10 = pdescr->LocalPt.y;
    v37 = pdescr->pResult;
    v20 = 1;
    pIgnoreMC = pdescr->pIgnoreMC;
    pHitArea = pdescr->pHitArea;
    ControllerIdx = pdescr->ControllerIdx;
    TestAll = pdescr->TestAll;
  }
LABEL_18:
  if ( !((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::MovieClipObject> *))this[-1].ASMovieClipObj.pObject->pSprite.pProxy.pObject)(&this[-1].ASMovieClipObj) )
  {
    if ( !v8
      || !pdescr->TestAll
      && ((AvmObjOffset = v8->AvmObjOffset) == 0
       || (v26 = ((__int64 (__fastcall *)(__int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                           + 4 * AvmObjOffset))[1].__vecDelDtor)((__int64)v8 + 4 * AvmObjOffset),
           !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v26 + 96i64))(v26))) )
    {
      if ( v24 == 1 )
      {
        if ( pdescr->TestAll )
          return 1i64;
        if ( pdescr->pResult != Capacity )
        {
          pParent = pdescr->pResult->pParent;
          if ( !pParent
            || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(pParent) )
          {
            goto LABEL_28;
          }
          return 1i64;
        }
      }
      goto LABEL_41;
    }
  }
  if ( v24 != 1 && v20 != 1 )
  {
LABEL_41:
    v5 = this;
LABEL_42:
    v17 = v34;
    goto LABEL_43;
  }
  if ( v8 )
  {
    if ( pdescr->TestAll
      || (v29 = v8->AvmObjOffset) != 0
      && (v30 = ((__int64 (__fastcall *)(__int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                          + 4 * v29))[1].__vecDelDtor)((__int64)v8 + 4 * v29),
          (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v30 + 96i64))(v30)) )
    {
      pdescr->pResult = v8;
      pdescr->pHitArea = Capacity;
      return 1i64;
    }
  }
  if ( !v19 )
    goto LABEL_50;
  v31 = (Scaleform::GFx::InteractiveObject *)v19;
  while ( 1 )
  {
    v31 = v31->pParent;
    if ( !v31 )
      break;
    if ( v31 == Capacity )
    {
      if ( v19 == pdescr->pHitArea )
        goto LABEL_50;
      pdescr->pResult = 0i64;
      v20 = 2;
      goto LABEL_41;
    }
  }
LABEL_28:
  result = 2i64;
LABEL_57:
  pdescr->pResult = 0i64;
  return result;
}

// File Line: 482
// RVA: 0x705EC0
void __fastcall Scaleform::GFx::AS2::AvmSprite::OnEventUnload(Scaleform::GFx::AS2::AvmSprite *this)
{
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr->Set__proto__(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &this->ASEnvironment.StringContext,
    0i64);
}

// File Line: 499
// RVA: 0x707250
_BOOL8 __fastcall Scaleform::GFx::AS2::AvmSprite::OnUnloading(Scaleform::GFx::AS2::AvmSprite *this, bool mayRemove)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // r8
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rcx
  unsigned __int64 pObject; // r9
  int v7; // eax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> > *p_pMovieImpl; // r10
  __int64 v9; // rcx
  Scaleform::GFx::AvmDisplayObjBaseVtbl *vfptr; // rax
  Scaleform::GFx::InteractiveObject *v11; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v13; // rbx
  Scaleform::GFx::InteractiveObject *v14; // rdi
  Scaleform::RefCountNTSImpl *v15; // rcx
  Scaleform::RefCountNTSImpl *v16; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v17; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v18; // rbx
  Scaleform::GFx::InteractiveObject *v19; // rdi
  Scaleform::RefCountNTSImpl *v20; // rcx
  Scaleform::RefCountNTSImpl *v21; // rcx
  __int64 v23; // [rsp+20h] [rbp-28h] BYREF
  int v24; // [rsp+28h] [rbp-20h]
  char v25; // [rsp+2Ch] [rbp-1Ch]
  int v26; // [rsp+30h] [rbp-18h]

  pDispObj = this->pDispObj;
  pASRoot = pDispObj->pASRoot;
  pObject = (unsigned __int64)pASRoot[39].pASSupport.pObject;
  if ( pDispObj[1].pGeomData )
  {
    v7 = 0;
    if ( pObject )
    {
      p_pMovieImpl = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> > *)&pASRoot[39].pMovieImpl;
      v9 = 0i64;
      while ( p_pMovieImpl->Data.Data[v9].pObject != pDispObj )
      {
        v9 = (unsigned int)++v7;
        if ( (unsigned int)v7 >= pObject )
          goto LABEL_9;
      }
      if ( v7 > -1 )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          p_pMovieImpl,
          v7);
    }
  }
LABEL_9:
  if ( mayRemove )
  {
    vfptr = this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr;
    v23 = 4i64;
    v24 = 0;
    v25 = 0;
    v26 = 65280;
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, __int64 *, Scaleform::GFx::InteractiveObject *, unsigned __int64))vfptr->HasEventHandler)(
            this,
            &v23,
            pDispObj,
            pObject) )
      goto LABEL_30;
    mayRemove = 0;
  }
  v11 = this->pDispObj;
  if ( (v11->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x20) != 0
    && (v11->Scaleform::GFx::DisplayObject::Flags & 8) == 0 )
  {
    inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v11->pASRoot[3].RefCount,
                 AP_Frame);
    v13 = inserted;
    if ( inserted )
    {
      v14 = this->pDispObj;
      inserted->Type = Entry_Event;
      if ( v14 )
        ++v14->RefCount;
      v15 = inserted->pCharacter.pObject;
      if ( v15 )
        Scaleform::RefCountNTSImpl::Release(v15);
      v13->pCharacter.pObject = v14;
      v16 = v13->pActionBuffer.pObject;
      if ( v16 )
        Scaleform::RefCountNTSImpl::Release(v16);
      v13->pActionBuffer.pObject = 0i64;
      *(_QWORD *)&v13->mEventId.Id = 1i64;
      v13->mEventId.KeyCode = 0;
      v13->mEventId.AsciiCode = 0;
      *(_DWORD *)&v13->mEventId.RollOverCnt = 65280;
    }
  }
  v17 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
          (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].RefCount,
          AP_Frame);
  v18 = v17;
  if ( v17 )
  {
    v19 = this->pDispObj;
    v17->Type = Entry_Event;
    if ( v19 )
      ++v19->RefCount;
    v20 = v17->pCharacter.pObject;
    if ( v20 )
      Scaleform::RefCountNTSImpl::Release(v20);
    v18->pCharacter.pObject = v19;
    v21 = v18->pActionBuffer.pObject;
    if ( v21 )
      Scaleform::RefCountNTSImpl::Release(v21);
    v18->pActionBuffer.pObject = 0i64;
    *(_QWORD *)&v18->mEventId.Id = 4i64;
    v18->mEventId.KeyCode = 0;
    v18->mEventId.AsciiCode = 0;
    *(_DWORD *)&v18->mEventId.RollOverCnt = 65280;
  }
LABEL_30:
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this->pDispObj);
  return mayRemove;
}

// File Line: 538
// RVA: 0x6FD4E0
void __fastcall Scaleform::GFx::AS2::AvmSprite::InitializeClassInstance(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::AS2::AvmCharacter *p_pProto; // rbx
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v6; // r9
  Scaleform::GFx::AS2::ObjectInterface *v7; // rdx
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-20h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 2 )
    p_pProto = (Scaleform::GFx::AS2::AvmCharacter *)&ThisPtr[-1].pProto;
  else
    p_pProto = 0i64;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v6 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToFunction(v6, &result, Env);
  if ( result.Function )
    v7 = &result.Function->Scaleform::GFx::AS2::ObjectInterface;
  else
    v7 = 0i64;
  Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(p_pProto, v7);
  Flags = result.Flags;
  if ( (result.Flags & 2) == 0 )
  {
    Function = result.Function;
    if ( result.Function )
    {
      RefCount = result.Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        result.Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        Flags = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v12 = result.pLocalFrame->RefCount;
      if ( (v12 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
}

// File Line: 553
// RVA: 0x6EA530
void __fastcall Scaleform::GFx::AS2::AvmSprite::FindClassAndInitializeClassInstance(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // r15
  char Flags; // r12
  Scaleform::GFx::AS2::FunctionObject *Function; // rsi
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // r14
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rdi
  Scaleform::GFx::AS2::AvmCharacter *p_pProto; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v11; // r10
  unsigned __int64 SizeMask; // rbx
  __int64 v13; // r11
  __int64 v14; // r8
  __int64 *v15; // r9
  Scaleform::GFx::ASStringNode *v16; // rdx
  __int64 v17; // rdx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r8
  signed __int64 v20; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v21; // rdx
  Scaleform::GFx::AS2::ObjectInterface *v22; // rdx
  Scaleform::GFx::InteractiveObject *pDispObj; // rbx
  Scaleform::GFx::InteractiveObject *v24; // rbx
  Scaleform::GFx::InteractiveObject *v25; // rbx
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned int RefCount; // eax
  unsigned int v29; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry v30; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::GFx::AS2::FunctionRefBase orig; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::MovieRoot::ActionEntry v32; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v33; // [rsp+140h] [rbp+40h]
  Scaleform::GFx::ASString result; // [rsp+190h] [rbp+90h] BYREF
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+198h] [rbp+98h] BYREF
  Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *p_FunctionParams; // [rsp+1A0h] [rbp+A0h]

  v33 = -2i64;
  pContext = fn->Env->StringContext.pContext;
  Flags = 0;
  Function = 0i64;
  memset(&orig, 0, 17);
  pLocalFrame = 0i64;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v8 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToString(v8, &result, Env, -1);
  if ( result.pNode->Size )
  {
    ThisPtr = fn->ThisPtr;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 2 )
      p_pProto = (Scaleform::GFx::AS2::AvmCharacter *)&ThisPtr[-1].pProto;
    else
      p_pProto = 0i64;
    if ( fn->Env->StringContext.SWFVersion <= 6u )
    {
      key.pStr = &result;
      pNode = result.pNode;
      if ( !result.pNode->pLower )
      {
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(result.pNode);
        pNode = result.pNode;
      }
      pTable = pContext->RegisteredClasses.mHash.pTable;
      if ( !pTable )
        goto LABEL_39;
      v20 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
              &pContext->RegisteredClasses.mHash,
              &key,
              pNode->HashFlags & pTable->SizeMask);
      if ( v20 < 0 )
        goto LABEL_39;
      v17 = (__int64)(&pContext->RegisteredClasses.mHash.pTable[1].SizeMask + 5 * v20);
    }
    else
    {
      v11 = pContext->RegisteredClasses.mHash.pTable;
      if ( !v11 )
        goto LABEL_39;
      SizeMask = v11->SizeMask;
      v13 = (unsigned int)SizeMask & result.pNode->HashFlags;
      v14 = v13;
      v15 = (__int64 *)(&v11[2 * v13 + 1].EntryCount + v13);
      if ( *v15 == -2 || ((unsigned int)SizeMask & *(_DWORD *)(v15[1] + 28)) != v13 )
        goto LABEL_39;
      while ( 1 )
      {
        v16 = (Scaleform::GFx::ASStringNode *)v15[1];
        if ( ((unsigned int)SizeMask & v16->HashFlags) == v13 && v16 == result.pNode )
          break;
        v14 = *v15;
        if ( *v15 == -1 )
          goto LABEL_39;
        v15 = (__int64 *)(&v11[2 * v14 + 1].EntryCount + v14);
      }
      if ( v14 < 0 )
        goto LABEL_39;
      v17 = (__int64)(&v11[2 * v14 + 1].SizeMask + v14);
    }
    if ( v17 )
    {
      v21 = (Scaleform::GFx::AS2::FunctionRefBase *)(v17 + 8);
      if ( v21 )
      {
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&orig, v21);
        Function = orig.Function;
        v22 = &orig.Function->Scaleform::GFx::AS2::ObjectInterface;
        if ( !orig.Function )
          v22 = 0i64;
        Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(p_pProto, v22);
        pDispObj = p_pProto->pDispObj;
        memset(&v30.pCharacter, 0, 29);
        *(_DWORD *)&v30.mEventId.RollOverCnt = 65280;
        memset(&v30.Function, 0, 17);
        key.pStr = (Scaleform::GFx::ASString *)&v30.FunctionParams;
        p_FunctionParams = &v30.FunctionParams;
        memset(&v30.FunctionParams, 0, sizeof(v30.FunctionParams));
        v30.pNextEntry = 0i64;
        v30.Type = Entry_Event;
        if ( pDispObj )
          ++pDispObj->RefCount;
        if ( v30.pCharacter.pObject )
          Scaleform::RefCountNTSImpl::Release(v30.pCharacter.pObject);
        v30.pCharacter.pObject = pDispObj;
        if ( v30.pActionBuffer.pObject )
          Scaleform::RefCountNTSImpl::Release(v30.pActionBuffer.pObject);
        v30.pActionBuffer.pObject = 0i64;
        *(_QWORD *)&v30.mEventId.Id = 0x40000i64;
        v30.mEventId.KeyCode = 0;
        v30.mEventId.AsciiCode = 0;
        *(_DWORD *)&v30.mEventId.RollOverCnt = 65280;
        v30.SessionId = 0;
        Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(
          &v30,
          (Scaleform::GFx::AS2::MovieRoot *)p_pProto->pDispObj->pASRoot);
        Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(&v30);
        v24 = p_pProto->pDispObj;
        memset(&v32.pCharacter, 0, 29);
        *(_DWORD *)&v32.mEventId.RollOverCnt = 65280;
        memset(&v32.Function, 0, 17);
        key.pStr = (Scaleform::GFx::ASString *)&v32.FunctionParams;
        p_FunctionParams = &v32.FunctionParams;
        memset(&v32.FunctionParams, 0, sizeof(v32.FunctionParams));
        v32.pNextEntry = 0i64;
        v32.Type = Entry_Function;
        if ( v24 )
          ++v24->RefCount;
        if ( v32.pCharacter.pObject )
          Scaleform::RefCountNTSImpl::Release(v32.pCharacter.pObject);
        v32.pCharacter.pObject = v24;
        if ( v32.pActionBuffer.pObject )
          Scaleform::RefCountNTSImpl::Release(v32.pActionBuffer.pObject);
        v32.pActionBuffer.pObject = 0i64;
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&v32.Function, &orig);
        v32.SessionId = 0;
        Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(
          &v32,
          (Scaleform::GFx::AS2::MovieRoot *)p_pProto->pDispObj->pASRoot);
        Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(&v32);
        Flags = orig.Flags;
        pLocalFrame = orig.pLocalFrame;
        goto LABEL_46;
      }
    }
LABEL_39:
    v25 = p_pProto->pDispObj;
    memset(&v30.pCharacter, 0, 29);
    *(_DWORD *)&v30.mEventId.RollOverCnt = 65280;
    memset(&v30.Function, 0, 17);
    key.pStr = (Scaleform::GFx::ASString *)&v30.FunctionParams;
    p_FunctionParams = &v30.FunctionParams;
    memset(&v30.FunctionParams, 0, sizeof(v30.FunctionParams));
    v30.pNextEntry = 0i64;
    v30.Type = Entry_Event;
    if ( v25 )
      ++v25->RefCount;
    if ( v30.pCharacter.pObject )
      Scaleform::RefCountNTSImpl::Release(v30.pCharacter.pObject);
    v30.pCharacter.pObject = v25;
    if ( v30.pActionBuffer.pObject )
      Scaleform::RefCountNTSImpl::Release(v30.pActionBuffer.pObject);
    v30.pActionBuffer.pObject = 0i64;
    *(_QWORD *)&v30.mEventId.Id = 0x40000i64;
    v30.mEventId.KeyCode = 0;
    v30.mEventId.AsciiCode = 0;
    *(_DWORD *)&v30.mEventId.RollOverCnt = 65280;
    v30.SessionId = 0;
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(
      &v30,
      (Scaleform::GFx::AS2::MovieRoot *)p_pProto->pDispObj->pASRoot);
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(&v30);
  }
LABEL_46:
  v26 = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  if ( (Flags & 2) == 0 )
  {
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  orig.Function = 0i64;
  if ( (Flags & 1) == 0 && pLocalFrame )
  {
    v29 = pLocalFrame->RefCount;
    if ( (v29 & 0x3FFFFFF) != 0 )
    {
      pLocalFrame->RefCount = v29 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
    }
  }
}

// File Line: 601
// RVA: 0x6FD2D0
void __fastcall Scaleform::GFx::AS2::AvmSprite::InitObjectMembers(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::RefCountNTSImpl *vfptr; // rbx
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v6; // r9
  Scaleform::GFx::AS2::ObjectInterface *v7; // rax
  Scaleform::GFx::AS2::Environment *v8; // rcx
  __int64 v9[4]; // [rsp+38h] [rbp-20h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 2 )
  {
    vfptr = (Scaleform::RefCountNTSImpl *)ThisPtr[1].vfptr;
    if ( vfptr )
      ++vfptr->RefCount;
  }
  else
  {
    vfptr = 0i64;
  }
  if ( vfptr )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v6 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v7 = Scaleform::GFx::AS2::Value::ToObjectInterface(v6, Env);
    v8 = fn->Env;
    v9[0] = (__int64)`Scaleform::GFx::AS2::AvmSprite::InitObjectMembers::`4::InitVisitor::`vftable;
    v9[1] = (__int64)v8;
    v9[2] = (__int64)vfptr;
    v7->vfptr->VisitMembers(v7, &v8->StringContext, (Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *)v9, 0, 0i64);
    v9[0] = (__int64)&Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable;
  }
  if ( vfptr )
    Scaleform::RefCountNTSImpl::Release(vfptr);
}

// File Line: 621
// RVA: 0x723740
void __fastcall Scaleform::GFx::AS2::AvmSprite::InitObjectMembers_::_4_::InitVisitor::Visit(
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        __int64 flags)
{
  Scaleform::GFx::ASStringNode *pNode; // r9
  __int64 v7; // rax
  char *v8; // rcx
  char v9; // [rsp+40h] [rbp+8h] BYREF

  pNode = name[2].pNode;
  if ( pNode )
  {
    v8 = (char *)pNode + 4 * BYTE1(pNode[2].HashFlags);
    v7 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 8i64))(v8);
  }
  else
  {
    v7 = 0i64;
  }
  v9 = 0;
  (*(void (__fastcall **)(__int64, Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::Value *, __int64, char *))(*(_QWORD *)(v7 + 8) + 24i64))(
    v7 + 8,
    name[1].pNode,
    val,
    flags,
    &v9);
}

// File Line: 640
// RVA: 0x6D7F90
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::AS2::AvmSprite::AddDisplayObject(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::CharPosInfo *pos,
        Scaleform::GFx::ASString *name,
        Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *peventHandlers)
{
  Scaleform::GFx::MovieDefImpl *v6; // r10
  int v7; // r12d
  bool v8; // di
  Scaleform::GFx::CharacterCreateInfo *p_result; // rax
  unsigned __int64 Capacity; // rcx
  Scaleform::GFx::DisplayObjectBase *DisplayObjectAtDepth; // rbx
  int v13; // r13d
  __int64 v14; // rdx
  Scaleform::GFx::ASString *OriginalName; // rax
  char v16; // si
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::Render::Cxform *Cxform; // rax
  unsigned __int64 v21; // r9
  __int64 v22; // rcx
  __int64 v23; // rax
  Scaleform::GFx::DisplayObjectBase *v24; // rsi
  __int16 v25; // dx
  Scaleform::GFx::Sprite *v26; // rbx
  Scaleform::GFx::DisplayObjectBase *i; // rdi
  Scaleform::Render::Rect<float> *Scale9Grid; // rax
  unsigned int v29; // r13d
  unsigned int v30; // r12d
  char Id; // r15
  Scaleform::GFx::Sprite *v32; // rdi
  bool v33; // zf
  Scaleform::GFx::Sprite *v34; // rcx
  bool placeObject; // [rsp+34h] [rbp-8Dh]
  Scaleform::GFx::CharacterCreateInfo result; // [rsp+40h] [rbp-81h] BYREF
  Scaleform::GFx::CharPosInfo posa; // [rsp+58h] [rbp-69h] BYREF
  Scaleform::GFx::ResourceId rid[2]; // [rsp+108h] [rbp+47h] BYREF
  Scaleform::GFx::ASString *namea; // [rsp+118h] [rbp+57h]
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *peventHandlersa; // [rsp+120h] [rbp+5Fh]
  void *v41; // [rsp+128h] [rbp+67h]
  int vars0; // [rsp+130h] [rbp+6Fh]
  void *retaddr; // [rsp+138h] [rbp+77h]
  Scaleform::GFx::CharacterCreateInfo *pisMarkedForRemove; // [rsp+140h] [rbp+7Fh] BYREF
  __int64 v45; // [rsp+148h] [rbp+87h]
  Scaleform::GFx::ASString *v46; // [rsp+150h] [rbp+8Fh]
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v47; // [rsp+158h] [rbp+97h]

  v47 = peventHandlers;
  v46 = name;
  result.pBindDefImpl = (Scaleform::GFx::MovieDefImpl *)-2i64;
  v6 = *(Scaleform::GFx::MovieDefImpl **)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 176);
  v7 = (int)retaddr;
  v8 = ((unsigned __int8)retaddr & 4) != 0;
  placeObject = v8;
  LOBYTE(retaddr) = (unsigned __int8)retaddr & 1;
  if ( pisMarkedForRemove )
  {
    result = *pisMarkedForRemove;
    p_result = &result;
  }
  else
  {
    rid[0] = pos->CharacterId;
    p_result = Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(v6, &result, (Scaleform::GFx::ResourceId)rid);
  }
  *(_OWORD *)&posa.ColorTransform.M[1][0] = *(_OWORD *)&p_result->pCharDef;
  *(_QWORD *)&posa.Matrix_1.M[0][0] = p_result->pResource;
  Capacity = this[-1].InitActionsExecuted.Data.Policy.Capacity;
  if ( !*(_QWORD *)&posa.ColorTransform.M[1][0] )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)(Capacity + 24),
      "Sprite::AddDisplayObject() - unknown cid = %d",
      LOWORD(pos->CharacterId.Id));
    return 0i64;
  }
  LOBYTE(pisMarkedForRemove) = 0;
  DisplayObjectAtDepth = Scaleform::GFx::DisplayList::GetDisplayObjectAtDepth(
                           (Scaleform::GFx::DisplayList *)(Capacity + 216),
                           pos->Depth,
                           (bool *)&pisMarkedForRemove);
  v13 = vars0;
  if ( vars0 == -1 )
    v13 = (*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)this[-1].InitActionsExecuted.Data.Policy.Capacity
                                                      + 856i64))(this[-1].InitActionsExecuted.Data.Policy.Capacity);
  if ( !v8 )
  {
    LOBYTE(retaddr) = 1;
    goto LABEL_50;
  }
  if ( DisplayObjectAtDepth
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))DisplayObjectAtDepth->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[51].__vecDelDtor)(DisplayObjectAtDepth)
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))DisplayObjectAtDepth->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[52].__vecDelDtor)(DisplayObjectAtDepth) )
  {
    LOBYTE(v14) = 1;
    DisplayObjectAtDepth->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      DisplayObjectAtDepth,
      v14);
  }
  if ( (_BYTE)pisMarkedForRemove )
    goto LABEL_17;
  if ( !DisplayObjectAtDepth )
  {
LABEL_50:
    _((AMD_HD3D *)this[-1].InitActionsExecuted.Data.Policy.Capacity);
    v21 = this[-1].InitActionsExecuted.Data.Policy.Capacity;
    v22 = *(_QWORD *)(*(_QWORD *)(v21 + 32) + 24i64);
    rid[0] = pos->CharacterId;
    v23 = (*(__int64 (__fastcall **)(__int64, _QWORD, float *))(*(_QWORD *)v22 + 32i64))(
            v22,
            *(_QWORD *)(*(_QWORD *)(v21 + 32) + 16i64),
            posa.ColorTransform.M[1]);
    v24 = (Scaleform::GFx::DisplayObjectBase *)v23;
    *(_QWORD *)&posa.ColorTransform.M[0][2] = v23;
    v25 = *(_WORD *)(v23 + 106);
    v26 = 0i64;
    if ( (v25 & 0x80u) != 0 )
      v26 = (Scaleform::GFx::Sprite *)v23;
    LOBYTE(rid[0].Id) = 0;
    *(_WORD *)(v23 + 106) = v25 & 0xFFFE;
    for ( i = *(Scaleform::GFx::DisplayObjectBase **)(v23 + 56); i; i = i->pParent )
    {
      Scale9Grid = Scaleform::GFx::DisplayObjectBase::GetScale9Grid(i, (Scaleform::Render::Rect<float> *)&result);
      if ( Scale9Grid->x2 > Scale9Grid->x1 && Scale9Grid->y2 > Scale9Grid->y1 )
      {
        v24->Flags |= 1u;
        ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v24->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[20].__vecDelDtor)(v24);
        break;
      }
    }
    if ( v26 )
    {
      if ( namea->pNode->Size )
      {
        Scaleform::GFx::DisplayObject::SetOriginalName(v26, namea);
        LOBYTE(rid[0].Id) = 1;
      }
      if ( v45 )
        ((void (__fastcall *)(Scaleform::GFx::Sprite *))v26->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[94].__vecDelDtor)(v26);
      if ( (v7 & 4) != 0 )
        v26->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Flags |= 1u;
      else
        v26->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
          v26,
          0);
    }
    v24->CreateFrame = v13;
    v29 = 0;
    if ( v26 )
      v29 = Scaleform::GFx::AS2::AvmSprite::OnAddingDisplayObject(
              (Scaleform::GFx::AS2::AvmSprite *)((char *)this - 40),
              (Scaleform::GFx::CharacterCreateInfo *)posa.ColorTransform.M[1],
              v26,
              peventHandlersa,
              v41,
              placeObject);
    v30 = v7 & 0xFFFFFFFE;
    if ( (_BYTE)retaddr )
      v30 |= 1u;
    if ( v26 )
    {
      Scaleform::GFx::InteractiveObject::AddToPlayList(v26);
      Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList(v26);
    }
    Scaleform::GFx::DisplayList::AddDisplayObject(
      (Scaleform::GFx::DisplayList *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 216),
      (Scaleform::GFx::DisplayObjectBase *)this[-1].InitActionsExecuted.Data.Policy.Capacity,
      pos,
      v24,
      v30);
    Id = rid[0].Id;
    if ( LOBYTE(rid[0].Id) )
      (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Sprite *))(**(_QWORD **)(this[-1].InitActionsExecuted.Data.Policy.Capacity
                                                                             + 32)
                                                               + 312i64))(
        *(_QWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 32),
        v26);
    if ( !v26 )
      goto LABEL_86;
    v32 = 0i64;
    if ( (v26->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
      v32 = v26;
    if ( placeObject )
    {
      v33 = v32 == 0i64;
    }
    else
    {
      Scaleform::GFx::AS2::MovieRoot::DoActionsForSession(
        *(Scaleform::GFx::AS2::MovieRoot **)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 32),
        v29);
      if ( !v32 )
      {
LABEL_83:
        if ( Id )
        {
          v34 = (Scaleform::GFx::Sprite *)this[-1].InitActionsExecuted.Data.Policy.Capacity;
          if ( namea->pNode == *(Scaleform::GFx::ASStringNode **)&v34->pASRoot[34].AVMVersion )
            Scaleform::GFx::Sprite::SetHitArea(v34, v26);
        }
LABEL_86:
        Scaleform::RefCountNTSImpl::Release(v24);
        return v24;
      }
      result.pCharDef = (Scaleform::GFx::CharacterDef *)1;
      LODWORD(result.pBindDefImpl) = 0;
      BYTE4(result.pBindDefImpl) = 0;
      LODWORD(result.pResource) = 65280;
      v33 = !Scaleform::GFx::DisplayObject::HasEventHandler(v32, (Scaleform::GFx::EventId *)&result);
    }
    if ( !v33 )
      v32->Flags |= 0x80u;
    goto LABEL_83;
  }
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))DisplayObjectAtDepth->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[51].__vecDelDtor)(DisplayObjectAtDepth) )
    return 0i64;
LABEL_17:
  if ( !DisplayObjectAtDepth || DisplayObjectAtDepth->Depth < -1 || DisplayObjectAtDepth->Id.Id != pos->CharacterId.Id )
    goto LABEL_50;
  if ( SLOBYTE(DisplayObjectAtDepth->Flags) >= 0 )
  {
    v17 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 32) + 312i64);
    *(_QWORD *)&rid[0].Id = v17;
    ++v17->RefCount;
    OriginalName = (Scaleform::GFx::ASString *)rid;
    v16 = 2;
  }
  else
  {
    OriginalName = Scaleform::GFx::DisplayObject::GetOriginalName(
                     (Scaleform::GFx::DisplayObject *)DisplayObjectAtDepth,
                     (Scaleform::GFx::ASString *)&posa.ColorTransform.M[0][2]);
    v16 = 1;
    v17 = *(Scaleform::GFx::ASStringNode **)&rid[0].Id;
  }
  pNode = OriginalName->pNode;
  *(_QWORD *)&rid[0].Id = pNode;
  ++pNode->RefCount;
  if ( (v16 & 2) != 0 )
  {
    v16 &= ~2u;
    v33 = v17->RefCount-- == 1;
    if ( v33 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  }
  if ( (v16 & 1) != 0 )
  {
    v19 = *(Scaleform::GFx::ASStringNode **)&posa.ColorTransform.M[0][2];
    v33 = (*(_DWORD *)(*(_QWORD *)&posa.ColorTransform.M[0][2] + 24i64))-- == 1;
    if ( v33 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
  if ( SLOBYTE(DisplayObjectAtDepth->Flags) < 0 )
  {
    if ( namea->pNode->Size )
    {
      if ( pNode != namea->pNode )
        goto LABEL_47;
    }
    else if ( pNode->Size
           && ((__int64)DisplayObjectAtDepth[1].Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr & 2) == 0 )
    {
LABEL_47:
      v33 = pNode->RefCount-- == 1;
      if ( v33 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      goto LABEL_50;
    }
  }
  if ( DisplayObjectAtDepth->CreateFrame != v13 )
  {
    LOBYTE(retaddr) = 1;
    goto LABEL_47;
  }
  Scaleform::GFx::CharPosInfo::CharPosInfo(&posa, pos);
  if ( SLOBYTE(pos->Flags.Flags) >= 0
    && ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))DisplayObjectAtDepth->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[15].__vecDelDtor)(DisplayObjectAtDepth) )
  {
    posa.Flags.Flags |= 0x80u;
    posa.BlendMode = 0;
  }
  if ( (pos->Flags.Flags & 8) == 0 )
  {
    Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(DisplayObjectAtDepth);
    if ( !Scaleform::Render::Cxform::IsIdentity(Cxform) )
    {
      posa.Flags.Flags |= 8u;
      Scaleform::Render::Cxform::SetIdentity(&posa.ColorTransform);
    }
  }
  Scaleform::GFx::DisplayObjContainer::MoveDisplayObject(
    (Scaleform::GFx::DisplayObjContainer *)this[-1].InitActionsExecuted.Data.Policy.Capacity,
    &posa);
  if ( posa.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)posa.pFilters.pObject);
  v33 = pNode->RefCount-- == 1;
  if ( !v33 )
    return 0i64;
  Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return 0i64;
}

// File Line: 841
// RVA: 0x704E10
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall Scaleform::GFx::AS2::AvmSprite::OnAddingDisplayObject(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::CharacterCreateInfo *ccinfo,
        Scaleform::GFx::InteractiveObject *pscriptCh,
        Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *peventHandlers)
{
  Scaleform::GFx::InteractiveObject *v7; // r15
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rax
  unsigned __int64 v9; // rsi
  unsigned __int64 Size; // r12
  Scaleform::GFx::ASMovieRootBase *v11; // r13
  Scaleform::GFx::AS2::MovieClipObject *MovieClipObject; // rax
  Scaleform::GFx::SwfEvent *v13; // rax
  Scaleform::GFx::AS2::ActionBufferData *pObject; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v16; // rbx
  Scaleform::RefCountNTSImpl *v17; // rcx
  Scaleform::RefCountNTSImpl *v18; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v19; // rsi
  Scaleform::GFx::AS2::FunctionObject *Function; // r14
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // r15
  Scaleform::GFx::MovieDefImpl *v22; // rax
  Scaleform::String *NameOfExportedResource; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *p_RefCount; // r13
  int v25; // eax
  char v26; // r12
  Scaleform::GFx::AS2::Environment *v27; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v28; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r11
  unsigned __int64 SizeMask; // rbx
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 *v33; // r9
  Scaleform::GFx::ASStringNode *v34; // rdx
  __int64 v35; // rdx
  Scaleform::GFx::ASStringNode *pNode; // rax
  signed __int64 v37; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v38; // rdx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v39; // rbx
  char Flags; // si
  Scaleform::RefCountNTSImpl *v41; // rcx
  Scaleform::RefCountNTSImpl *v42; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v43; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v44; // rbx
  Scaleform::RefCountNTSImpl *v45; // rcx
  Scaleform::RefCountNTSImpl *v46; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v47; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v48; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v49; // rbx
  Scaleform::RefCountNTSImpl *v50; // rcx
  Scaleform::RefCountNTSImpl *v51; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v52; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v53; // rbx
  Scaleform::RefCountNTSImpl *v54; // rcx
  Scaleform::RefCountNTSImpl *v55; // rcx
  char Type; // bl
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v57; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v58; // rbx
  Scaleform::RefCountNTSImpl *v59; // rcx
  Scaleform::RefCountNTSImpl *v60; // rcx
  Scaleform::GFx::ASStringNode *v61; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v63; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v64; // rbx
  Scaleform::RefCountNTSImpl *v65; // rcx
  Scaleform::RefCountNTSImpl *v66; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v67; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v68; // rbx
  Scaleform::RefCountNTSImpl *v69; // rcx
  Scaleform::RefCountNTSImpl *v70; // rcx
  unsigned int v71; // eax
  unsigned int v72; // edx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+0h] [rbp-79h] BYREF
  unsigned int v75; // [rsp+18h] [rbp-61h]
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-59h] BYREF
  Scaleform::GFx::ResourceId rid[2]; // [rsp+28h] [rbp-51h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::FunctionRefBase orig; // [rsp+50h] [rbp-29h] BYREF
  Scaleform::GFx::ASMovieRootBase *v80; // [rsp+68h] [rbp-11h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *v81; // [rsp+70h] [rbp-9h]
  volatile int RefCount; // [rsp+78h] [rbp-1h]
  __int64 v83; // [rsp+80h] [rbp+7h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *v84; // [rsp+D0h] [rbp+57h]
  Scaleform::GFx::CharacterCreateInfo *v85; // [rsp+D8h] [rbp+5Fh]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *p_pheapAddr; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::AS2::ObjectInterface *pobj; // [rsp+F0h] [rbp+77h]
  char vars0; // [rsp+F8h] [rbp+7Fh]

  v83 = -2i64;
  v7 = 0i64;
  if ( (pscriptCh->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
    v7 = pscriptCh;
  LOBYTE(p_pheapAddr) = 1;
  pASRoot = this->pDispObj->pASRoot;
  v80 = pASRoot;
  if ( peventHandlers )
  {
    v9 = 0i64;
    Size = peventHandlers->Data.Size;
    if ( Size )
    {
      v11 = pASRoot;
      do
      {
        Scaleform::GFx::AS2::AvmSwfEvent::AttachTo(peventHandlers->Data.Data[v9], pscriptCh);
        if ( v7 )
        {
          if ( (peventHandlers->Data.Data[v9]->Event.Id & 0xFBFC00) != 0 )
          {
            MovieClipObject = Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject((Scaleform::GFx::AS2::AvmSprite *)((char *)v7 + 4 * (unsigned __int8)v7->AvmObjOffset));
            if ( MovieClipObject )
              MovieClipObject->HasButtonHandlers = 1;
          }
        }
        if ( vars0 )
        {
          v13 = peventHandlers->Data.Data[v9];
          if ( v13->Event.Id == 512 )
          {
            pObject = v13->pActionOpData.pObject;
            if ( pObject )
            {
              if ( pObject->BufferLen )
              {
                if ( *pObject->pBuffer )
                {
                  inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                               (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v11[3].RefCount,
                               AP_Initialize);
                  v16 = inserted;
                  if ( inserted )
                  {
                    inserted->Type = Entry_Event;
                    ++pscriptCh->RefCount;
                    v17 = inserted->pCharacter.pObject;
                    if ( v17 )
                      Scaleform::RefCountNTSImpl::Release(v17);
                    v16->pCharacter.pObject = pscriptCh;
                    v18 = v16->pActionBuffer.pObject;
                    if ( v18 )
                      Scaleform::RefCountNTSImpl::Release(v18);
                    v16->pActionBuffer.pObject = 0i64;
                    *(_QWORD *)&v16->mEventId.Id = 512i64;
                    v16->mEventId.KeyCode = 0;
                    v16->mEventId.AsciiCode = 0;
                    *(_DWORD *)&v16->mEventId.RollOverCnt = 65280;
                  }
                }
              }
            }
          }
        }
        ++v9;
      }
      while ( v9 < Size );
      ccinfo = v85;
      this = (Scaleform::GFx::AS2::AvmSprite *)v84;
    }
  }
  v19 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[1].OnUnloading)(this);
  Function = 0i64;
  memset(&orig, 0, 17);
  pLocalFrame = 0i64;
  rid[0] = ccinfo->pCharDef->Id;
  v22 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pscriptCh->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pscriptCh);
  NameOfExportedResource = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(v22, (Scaleform::GFx::ResourceId)rid);
  p_RefCount = (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v80[3].RefCount;
  RefCount = v80[7].RefCount;
  v25 = LODWORD(v80[7].pMovieImpl) + 1;
  v75 = v25;
  LODWORD(v80[7].pMovieImpl) = v25;
  p_RefCount->CurrentSessionId = v25;
  v26 = 0;
  if ( !NameOfExportedResource )
  {
    Flags = orig.Flags;
    goto LABEL_96;
  }
  v27 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *))v84->Data[7].V.FunctionValue.pLocalFrame)(v84);
  Scaleform::GFx::AS2::Environment::CreateString(v27, &result, NameOfExportedResource);
  v28 = v19 + 3;
  if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *))v84->Data[7].V.FunctionValue.pLocalFrame)(v84)
                + 240) <= 6u )
  {
    *(_QWORD *)&rid[0].Id = &result;
    pNode = result.pNode;
    if ( !result.pNode->pLower )
    {
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(result.pNode);
      pNode = result.pNode;
    }
    if ( !v28->pTable )
      goto LABEL_80;
    v37 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
            v19 + 3,
            (Scaleform::GFx::ASString::NoCaseKey *)rid,
            pNode->HashFlags & v28->pTable->SizeMask);
    if ( v37 < 0 )
      goto LABEL_80;
    v35 = (__int64)(&v28->pTable[1].SizeMask + 5 * v37);
  }
  else
  {
    pTable = v28->pTable;
    if ( !v28->pTable )
      goto LABEL_80;
    SizeMask = pTable->SizeMask;
    v31 = (unsigned int)SizeMask & result.pNode->HashFlags;
    v32 = v31;
    v33 = (__int64 *)(&pTable[2 * v31 + 1].EntryCount + v31);
    if ( *v33 == -2 || ((unsigned int)SizeMask & *(_DWORD *)(v33[1] + 28)) != v31 )
      goto LABEL_80;
    while ( 1 )
    {
      v34 = (Scaleform::GFx::ASStringNode *)v33[1];
      if ( ((unsigned int)SizeMask & v34->HashFlags) == v31 && v34 == result.pNode )
        break;
      v32 = *v33;
      if ( *v33 == -1 )
        goto LABEL_80;
      v33 = (__int64 *)(&pTable[2 * v32 + 1].EntryCount + v32);
    }
    if ( v32 < 0 )
      goto LABEL_80;
    v35 = (__int64)(&pTable[2 * v32 + 1].SizeMask + v32);
  }
  if ( v35 )
  {
    v38 = (Scaleform::GFx::AS2::FunctionRefBase *)(v35 + 8);
    if ( v38 )
    {
      Scaleform::GFx::AS2::FunctionRefBase::Assign(&orig, v38);
      v39 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_RefCount, AP_Initialize);
      p_pheapAddr = &pheapAddr;
      memset(&pheapAddr, 0, sizeof(pheapAddr));
      v.T.Type = 8;
      v.V.FunctionValue.Flags = 0;
      Function = orig.Function;
      v.V.pStringNode = (Scaleform::GFx::ASStringNode *)orig.Function;
      if ( orig.Function )
        orig.Function->RefCount = (orig.Function->RefCount + 1) & 0x8FFFFFFF;
      v.V.FunctionValue.pLocalFrame = 0i64;
      pLocalFrame = orig.pLocalFrame;
      Flags = orig.Flags;
      if ( orig.pLocalFrame )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v.V.FunctionValue, orig.pLocalFrame, orig.Flags & 1);
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
      p_pheapAddr = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
      *(_QWORD *)&rid[0].Id = p_pheapAddr;
      if ( p_pheapAddr )
        Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      if ( v39 )
      {
        v39->Type = Entry_CFunction;
        ++pscriptCh->RefCount;
        v41 = v39->pCharacter.pObject;
        if ( v41 )
          Scaleform::RefCountNTSImpl::Release(v41);
        v39->pCharacter.pObject = pscriptCh;
        v42 = v39->pActionBuffer.pObject;
        if ( v42 )
          Scaleform::RefCountNTSImpl::Release(v42);
        v39->pActionBuffer.pObject = 0i64;
        v39->CFunction = Scaleform::GFx::AS2::AvmSprite::InitializeClassInstance;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
          &v39->FunctionParams,
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr);
      }
      v43 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_RefCount, AP_Construct);
      v44 = v43;
      if ( v43 )
      {
        v43->Type = Entry_Event;
        ++pscriptCh->RefCount;
        v45 = v43->pCharacter.pObject;
        if ( v45 )
          Scaleform::RefCountNTSImpl::Release(v45);
        v44->pCharacter.pObject = pscriptCh;
        v46 = v44->pActionBuffer.pObject;
        if ( v46 )
          Scaleform::RefCountNTSImpl::Release(v46);
        v44->pActionBuffer.pObject = 0i64;
        *(_QWORD *)&v44->mEventId.Id = 0x40000i64;
        v44->mEventId.KeyCode = 0;
        v44->mEventId.AsciiCode = 0;
        *(_DWORD *)&v44->mEventId.RollOverCnt = 65280;
      }
      LOBYTE(p_pheapAddr) = 0;
      if ( Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)v84[1].Data) >= 6 )
      {
        v47 = pobj;
        if ( pobj )
        {
          Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            (Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
            0i64);
          Scaleform::GFx::AS2::Value::SetAsObjectInterface(&v, v47);
          Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &pheapAddr,
            &pheapAddr,
            pheapAddr.Size + 1);
          *(_QWORD *)&rid[0].Id = &pheapAddr.Data[pheapAddr.Size - 1];
          v81 = *(Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> **)&rid[0].Id;
          if ( *(_QWORD *)&rid[0].Id )
            Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v);
          v48 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_RefCount, AP_Construct);
          v49 = v48;
          if ( v48 )
          {
            v48->Type = Entry_CFunction;
            ++pscriptCh->RefCount;
            v50 = v48->pCharacter.pObject;
            if ( v50 )
              Scaleform::RefCountNTSImpl::Release(v50);
            v49->pCharacter.pObject = pscriptCh;
            v51 = v49->pActionBuffer.pObject;
            if ( v51 )
              Scaleform::RefCountNTSImpl::Release(v51);
            v49->pActionBuffer.pObject = 0i64;
            v49->CFunction = Scaleform::GFx::AS2::AvmSprite::InitObjectMembers;
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
              &v49->FunctionParams,
              (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr);
          }
          if ( v.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
      }
      v26 = 1;
      v52 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_RefCount, AP_Construct);
      v53 = v52;
      if ( v52 )
      {
        v52->Type = Entry_Function;
        ++pscriptCh->RefCount;
        v54 = v52->pCharacter.pObject;
        if ( v54 )
          Scaleform::RefCountNTSImpl::Release(v54);
        v53->pCharacter.pObject = pscriptCh;
        v55 = v53->pActionBuffer.pObject;
        if ( v55 )
          Scaleform::RefCountNTSImpl::Release(v55);
        v53->pActionBuffer.pObject = 0i64;
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&v53->Function, &orig);
      }
      v81 = &pheapAddr;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
      goto LABEL_93;
    }
  }
LABEL_80:
  if ( vars0 )
  {
    p_pheapAddr = &pheapAddr;
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    Type = 5;
    v.T.Type = 5;
    v.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
    ++result.pNode->RefCount;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    p_pheapAddr = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
    v81 = p_pheapAddr;
    if ( p_pheapAddr )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v);
      Type = v.T.Type;
    }
    if ( (unsigned __int8)Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v57 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_RefCount, AP_Construct);
    v58 = v57;
    if ( v57 )
    {
      v57->Type = Entry_CFunction;
      ++pscriptCh->RefCount;
      v59 = v57->pCharacter.pObject;
      if ( v59 )
        Scaleform::RefCountNTSImpl::Release(v59);
      v58->pCharacter.pObject = pscriptCh;
      v60 = v58->pActionBuffer.pObject;
      if ( v60 )
        Scaleform::RefCountNTSImpl::Release(v60);
      v58->pActionBuffer.pObject = 0i64;
      v58->CFunction = Scaleform::GFx::AS2::AvmSprite::FindClassAndInitializeClassInstance;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        &v58->FunctionParams,
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr);
    }
    LOBYTE(p_pheapAddr) = 0;
    v81 = &pheapAddr;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
  }
  Flags = orig.Flags;
LABEL_93:
  v61 = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v61);
LABEL_96:
  if ( vars0 )
  {
    if ( (_BYTE)p_pheapAddr )
    {
      v63 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_RefCount, AP_Construct);
      v64 = v63;
      if ( v63 )
      {
        v63->Type = Entry_Event;
        ++pscriptCh->RefCount;
        v65 = v63->pCharacter.pObject;
        if ( v65 )
          Scaleform::RefCountNTSImpl::Release(v65);
        v64->pCharacter.pObject = pscriptCh;
        v66 = v64->pActionBuffer.pObject;
        if ( v66 )
          Scaleform::RefCountNTSImpl::Release(v66);
        v64->pActionBuffer.pObject = 0i64;
        *(_QWORD *)&v64->mEventId.Id = 0x40000i64;
        v64->mEventId.KeyCode = 0;
        v64->mEventId.AsciiCode = 0;
        *(_DWORD *)&v64->mEventId.RollOverCnt = 65280;
      }
    }
  }
  else if ( !v26
         && Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)v84[1].Data) >= 6
         && pobj )
  {
    v84 = &pheapAddr;
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    Scaleform::GFx::AS2::Value::SetAsObjectInterface(&v, pobj);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    v84 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
    p_pheapAddr = v84;
    if ( v84 )
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v);
    v67 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(p_RefCount, AP_Construct);
    v68 = v67;
    if ( v67 )
    {
      v67->Type = Entry_CFunction;
      ++pscriptCh->RefCount;
      v69 = v67->pCharacter.pObject;
      if ( v69 )
        Scaleform::RefCountNTSImpl::Release(v69);
      v68->pCharacter.pObject = pscriptCh;
      v70 = v68->pActionBuffer.pObject;
      if ( v70 )
        Scaleform::RefCountNTSImpl::Release(v70);
      v68->pActionBuffer.pObject = 0i64;
      v68->CFunction = Scaleform::GFx::AS2::AvmSprite::InitObjectMembers;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        &v68->FunctionParams,
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr);
    }
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v84 = &pheapAddr;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
  }
  v80[7].RefCount = RefCount;
  if ( (Flags & 2) == 0 )
  {
    if ( Function )
    {
      v71 = Function->RefCount;
      if ( (v71 & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = v71 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  orig.Function = 0i64;
  if ( (Flags & 1) == 0 )
  {
    if ( pLocalFrame )
    {
      v72 = pLocalFrame->RefCount;
      if ( (v72 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v72 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  return v75;
}

// File Line: 1014
// RVA: 0x6DA3C0
void __fastcall Scaleform::GFx::AS2::AvmSprite::AdvanceFrame(
        Scaleform::GFx::AS2::AvmSprite *this,
        bool nextFrame,
        float framePos)
{
  Scaleform::GFx::Sprite *Capacity; // rdi
  unsigned int v5; // r14d
  unsigned int v6; // ebx
  Scaleform::GFx::AS2::MovieClipObject *pObject; // rax
  __int64 v8; // [rsp+28h] [rbp-18h] BYREF
  int v9; // [rsp+30h] [rbp-10h]
  char v10; // [rsp+34h] [rbp-Ch]
  int v11; // [rsp+38h] [rbp-8h]

  Capacity = (Scaleform::GFx::Sprite *)this[-1].InitActionsExecuted.Data.Policy.Capacity;
  if ( Capacity )
    ++Capacity->RefCount;
  if ( (Capacity->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0xC) == 0
    && (Capacity->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) == 0
    && Capacity->Depth >= -1
    && nextFrame )
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))Capacity->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[107].__vecDelDtor)(Capacity);
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::Sprite *))Capacity->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[115].__vecDelDtor)(Capacity)
      || (v6 = v5,
          Scaleform::GFx::Sprite::IncrementFrameAndCheckForLoop(Capacity),
          v5 = ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))Capacity->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[107].__vecDelDtor)(Capacity),
          v5 == v6) )
    {
      v9 = 0;
      v10 = 0;
      pObject = this[-1].ASMovieClipObj.pObject;
      v8 = 2i64;
      v11 = 65280;
      ((void (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::MovieClipObject> *, __int64 *))pObject->ResolveHandler.pLocalFrame)(
        &this[-1].ASMovieClipObj,
        &v8);
    }
    else
    {
      ((void (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, _QWORD))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmTextFieldBase)(
        this,
        v5);
      v8 = 2i64;
      v9 = 0;
      v10 = 0;
      v11 = 65280;
      ((void (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::MovieClipObject> *, __int64 *))this[-1].ASMovieClipObj.pObject->ResolveHandler.pLocalFrame)(
        &this[-1].ASMovieClipObj,
        &v8);
      Scaleform::GFx::Sprite::ExecuteFrameTags(Capacity, v5);
    }
    if ( !v5 )
      Scaleform::GFx::DisplayList::UnloadMarkedObjects(
        (Scaleform::GFx::DisplayList *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 216),
        (Scaleform::GFx::DisplayObjectBase *)this[-1].InitActionsExecuted.Data.Policy.Capacity);
  }
  Scaleform::RefCountNTSImpl::Release(Capacity);
}

// File Line: 1123
// RVA: 0x6F5F50
bool __fastcall Scaleform::GFx::AS2::AvmSprite::GetStandardMember(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::AvmCharacter::StandardMember member,
        Scaleform::GFx::AS2::Value *pval,
        bool opcodeFlag)
{
  Scaleform::GFx::AS2::AvmSprite *v6; // rbx
  int v7; // eax
  bool v8; // al
  unsigned int v9; // eax
  unsigned int v10; // eax
  char v11; // cl
  bool v12; // bl
  Scaleform::GFx::AS2::Value *v13; // rcx
  char Value; // al
  bool v15; // bl
  Scaleform::GFx::CharacterHandle *pGeomData; // rdx
  Scaleform::GFx::AS2::Environment *v17; // rsi
  __int64 v18; // rcx
  Scaleform::GFx::AS2::RectangleObject *v19; // rax
  Scaleform::GFx::AS2::RectangleObject *v20; // rax
  Scaleform::GFx::AS2::RectangleObject *v21; // rbx
  unsigned int RefCount; // eax
  Scaleform::GFx::InteractiveObject *pDispObj; // rax
  double *p_x1; // rax
  double v25; // xmm6_8
  double v26; // xmm7_8
  double v27; // xmm8_8
  double v28; // xmm9_8
  Scaleform::GFx::AS2::Environment *v29; // rsi
  __int64 v30; // rcx
  Scaleform::GFx::AS2::RectangleObject *v31; // rax
  Scaleform::GFx::AS2::RectangleObject *v32; // rax
  Scaleform::Render::Rect<float> result; // [rsp+40h] [rbp-78h] BYREF
  Scaleform::Render::Rect<double> r; // [rsp+50h] [rbp-68h] BYREF

  v6 = this;
  if ( Scaleform::GFx::AS2::AvmCharacter::GetStandardMember(this, member, pval, opcodeFlag) )
    return 1;
  switch ( member )
  {
    case M_currentframe:
      v7 = (int)v6->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[107].__vecDelDtor(v6->pDispObj, 0x40000000u);
      Scaleform::GFx::AS2::Value::SetInt(pval, v7 + 1);
      return 1;
    case M_totalframes:
      v9 = (unsigned int)v6->pDispObj[1].pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::$CFA0FEAB6C317A8124CFA738756F89CC::vfptr[10].__vecDelDtor(
                           v6->pDispObj[1].pParent,
                           0x40000000u);
      Scaleform::GFx::AS2::Value::SetInt(pval, v9);
      return 1;
    case M_framesloaded:
      v10 = (unsigned int)v6->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[111].__vecDelDtor(
                            v6->pDispObj,
                            0x40000000u);
      Scaleform::GFx::AS2::Value::SetInt(pval, v10);
      return 1;
    case M_lockroot:
      LOBYTE(v6) = LOBYTE(v6->pDispObj[1].pIndXFormData) >> 5;
      goto LABEL_8;
    case M_focusEnabled:
      v11 = BYTE1(v6->pDispObj[1].pIndXFormData);
      if ( !v11 )
        goto LABEL_11;
      v12 = v11 == 1;
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->T.Type = 2;
      pval->V.BooleanValue = v12;
      goto LABEL_13;
    case M_tabChildren:
      Value = v6->TabChildren.Value;
      v13 = pval;
      if ( !Value )
        goto LABEL_12;
      v15 = Value == 1;
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->T.Type = 2;
      pval->V.BooleanValue = v15;
      goto LABEL_13;
    case M_scale9Grid:
      if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, unsigned __int64))v6->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase)(
                        v6,
                        0x140000000ui64)
                    + 240) < 8u )
        return 0;
      if ( !Scaleform::GFx::DisplayObjectBase::HasScale9Grid(v6->pDispObj) )
        goto LABEL_11;
      Scaleform::GFx::DisplayObjectBase::GetScale9Grid(v6->pDispObj, &result);
      v17 = (Scaleform::GFx::AS2::Environment *)v6->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase(v6);
      v19 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, __int64))v17->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                      v18,
                                                      96i64);
      if ( v19 )
      {
        Scaleform::GFx::AS2::RectangleObject::RectangleObject(v19, v17);
        v21 = v20;
      }
      else
      {
        v21 = 0i64;
      }
      r.x1 = (float)(result.x1 * 0.050000001);
      r.y1 = (float)(result.y1 * 0.050000001);
      r.x2 = (float)(result.x2 * 0.050000001);
      r.y2 = (float)(result.y2 * 0.050000001);
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v21, v17, &r);
      Scaleform::GFx::AS2::Value::SetAsObject(pval, v21);
      goto LABEL_25;
    case M_hitArea:
      pGeomData = (Scaleform::GFx::CharacterHandle *)v6->pDispObj[1].pGeomData;
      if ( pGeomData )
      {
        Scaleform::GFx::AS2::Value::SetAsCharacterHandle(pval, pGeomData);
        return 1;
      }
      else
      {
        Scaleform::GFx::AS2::Value::DropRefs(pval);
        pval->T.Type = 0;
        return 0;
      }
    case M_scrollRect:
      if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, unsigned __int64))v6->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase)(
                        v6,
                        0x140000000ui64)
                    + 240) < 8u )
        return 0;
      pDispObj = v6->pDispObj;
      if ( pDispObj->pScrollRect )
      {
        p_x1 = &pDispObj->pScrollRect->Rectangle.x1;
        v25 = p_x1[3];
        v26 = p_x1[2];
        v27 = p_x1[1];
        v28 = *p_x1;
        v29 = (Scaleform::GFx::AS2::Environment *)v6->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase(v6);
        v31 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, __int64))v29->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                        v30,
                                                        96i64);
        if ( v31 )
        {
          Scaleform::GFx::AS2::RectangleObject::RectangleObject(v31, v29);
          v21 = v32;
        }
        else
        {
          v21 = 0i64;
        }
        r.x1 = v28 * 0.05;
        r.y1 = v27 * 0.05;
        r.x2 = v26 * 0.05;
        r.y2 = v25 * 0.05;
        Scaleform::GFx::AS2::RectangleObject::SetProperties(v21, v29, &r);
        Scaleform::GFx::AS2::Value::SetAsObject(pval, v21);
LABEL_25:
        if ( v21 )
        {
          RefCount = v21->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v21->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v21);
          }
        }
      }
      else
      {
LABEL_11:
        v13 = pval;
LABEL_12:
        Scaleform::GFx::AS2::Value::DropRefs(v13);
        pval->T.Type = 0;
      }
LABEL_13:
      v8 = 1;
      break;
    case M_hitTestDisable:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, unsigned __int64))v6->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase)(
                                    v6,
                                    0x140000000ui64)
                                + 232)
                    + 104i64) != 1 )
        return 0;
      LODWORD(v6) = v6->pDispObj->Flags >> 11;
LABEL_8:
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->T.Type = 2;
      pval->V.BooleanValue = (unsigned __int8)v6 & 1;
      return 1;
    default:
      return 0;
  }
  return v8;
}

// File Line: 1257
// RVA: 0x71BE60
__int64 __fastcall Scaleform::GFx::AS2::AvmSprite::SetStandardMember(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::AvmCharacter::StandardMember member,
        Scaleform::GFx::AS2::Value *origVal,
        bool opcodeFlag)
{
  __int64 v5; // rbx
  Scaleform::GFx::AS2::Environment *v7; // rax
  Scaleform::GFx::AS2::Environment *v8; // rsi
  Scaleform::GFx::AS2::MovieClipObject *pObject; // rcx
  Scaleform::GFx::ASString *v10; // rax
  char v11; // si
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::InteractiveObject *pDispObj; // rbx
  Scaleform::GFx::AS2::Environment *v15; // rax
  char pIndXFormData; // al
  char v17; // al
  Scaleform::GFx::InteractiveObject *v18; // rbx
  Scaleform::GFx::AS2::Environment *v19; // rax
  Scaleform::GFx::AS2::Environment *v20; // rax
  bool v21; // al
  Scaleform::GFx::InteractiveObject *v22; // rcx
  Scaleform::GFx::InteractiveObject *v23; // rbx
  Scaleform::GFx::AS2::Environment *v24; // rax
  __int64 v25; // rax
  Scaleform::GFx::DisplayObject *v26; // rax
  Scaleform::GFx::Sprite *v27; // rdx
  Scaleform::GFx::AS2::Environment *v28; // rsi
  Scaleform::GFx::AS2::Object *v29; // rax
  Scaleform::GFx::AS2::RectangleObject *v30; // rbx
  float v31; // xmm1_4
  Scaleform::GFx::InteractiveObject *v32; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  double *v34; // rdx
  Scaleform::GFx::AS2::Environment *v35; // rsi
  Scaleform::GFx::AS2::Object *v36; // rax
  Scaleform::GFx::AS2::RectangleObject *v37; // rbx
  Scaleform::Render::Rect<double> *v38; // rdx
  unsigned __int8 v39; // bl
  double v41; // [rsp+28h] [rbp-29h] BYREF
  long double v42; // [rsp+30h] [rbp-21h]
  double v43; // [rsp+38h] [rbp-19h]
  double v44; // [rsp+40h] [rbp-11h]
  __int128 v45; // [rsp+48h] [rbp-9h] BYREF
  Scaleform::GFx::AS2::Value newVal; // [rsp+58h] [rbp+7h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+78h] [rbp+27h] BYREF
  Scaleform::GFx::ASString result; // [rsp+B8h] [rbp+67h] BYREF

  v5 = member;
  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)((char *)&newVal.NV + 24), origVal);
  v7 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
  v8 = v7;
  if ( (int)v5 > 21 )
  {
    if ( v7 )
    {
      pObject = this->ASMovieClipObj.pObject;
      if ( pObject )
      {
        if ( pObject->pWatchpoints )
        {
          v.T.Type = 0;
          v10 = Scaleform::GFx::AS2::Environment::CreateConstString(
                  v7,
                  &result,
                  Scaleform::GFx::AS2::AvmCharacter::MemberTable[v5].pName);
          v11 = Scaleform::GFx::AS2::Object::InvokeWatchpoint(this->ASMovieClipObj.pObject, v8, v10, &newVal, &v);
          pNode = result.pNode;
          v13 = result.pNode->RefCount-- == 1;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          if ( v11 )
            Scaleform::GFx::AS2::Value::operator=(&newVal, &v);
          if ( v.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
      }
    }
  }
  if ( Scaleform::GFx::AS2::AvmCharacter::SetStandardMember(this, v5, &newVal, opcodeFlag) )
  {
$LN238:
    v39 = 1;
  }
  else
  {
    switch ( (int)v5 )
    {
      case 4:
      case 5:
      case 12:
        goto $LN238;
      case 28:
        pDispObj = this->pDispObj;
        v15 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
        v13 = !Scaleform::GFx::AS2::Value::ToBool(&newVal, v15);
        pIndXFormData = (char)pDispObj[1].pIndXFormData;
        if ( v13 )
          v17 = pIndXFormData & 0xDF;
        else
          v17 = pIndXFormData | 0x20;
        LOBYTE(pDispObj[1].pIndXFormData) = v17;
        goto $LN238;
      case 34:
        if ( !newVal.T.Type || newVal.T.Type == 10 )
        {
          BYTE1(this->pDispObj[1].pIndXFormData) = 0;
        }
        else
        {
          v18 = this->pDispObj;
          v19 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
          BYTE1(v18[1].pIndXFormData) = !Scaleform::GFx::AS2::Value::ToBool(&newVal, v19) + 1;
        }
        goto $LN238;
      case 35:
        if ( !newVal.T.Type || newVal.T.Type == 10 )
        {
          this->TabChildren.Value = 0;
        }
        else
        {
          v20 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
          v21 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v20);
          this->TabChildren.Value = !v21 + 1;
          v22 = this->pDispObj;
          if ( v21 )
            v22->Flags &= ~0x8000u;
          else
            v22->Flags |= 0x8000u;
        }
        goto $LN238;
      case 37:
        if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this)
                      + 240) < 8u )
          goto LABEL_52;
        v28 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
        v29 = Scaleform::GFx::AS2::Value::ToObject(&newVal, v28);
        v30 = (Scaleform::GFx::AS2::RectangleObject *)v29;
        if ( v29
          && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v29->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v29->Scaleform::GFx::AS2::ObjectInterface) == 17 )
        {
          memset(&v, 0, sizeof(v));
          Scaleform::GFx::AS2::RectangleObject::GetProperties(v30, v28, (Scaleform::Render::Rect<double> *)&v);
          *(float *)&v41 = (float)*(double *)&v.T.Type * 20.0;
          *((float *)&v41 + 1) = (float)v.NV.NumberValue * 20.0;
          v31 = *(double *)&v.V.FunctionValue.pLocalFrame - *(double *)&v.T.Type;
          *(float *)&v42 = (float)(v31 * 20.0) + *(float *)&v41;
          *((float *)&v42 + 1) = (float)((float)(*((double *)&v.NV + 3) - v.NV.NumberValue) * 20.0)
                               + *((float *)&v41 + 1);
          v32 = this->pDispObj;
          vfptr = v32->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
          v34 = &v41;
        }
        else
        {
          v32 = this->pDispObj;
          v45 = 0i64;
          vfptr = v32->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
          v34 = (double *)&v45;
        }
        vfptr[19].__vecDelDtor(v32, (unsigned int)v34);
        goto $LN238;
      case 38:
        v25 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
        if ( newVal.T.Type == 7 )
        {
          if ( v25 )
          {
            if ( newVal.V.pStringNode )
            {
              v26 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                      newVal.V.pCharHandle,
                      *(Scaleform::GFx::MovieImpl **)(*(_QWORD *)(*(_QWORD *)(v25 + 224) + 32i64) + 16i64));
              if ( v26 )
              {
                v27 = 0i64;
                if ( SLOBYTE(v26->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
                  v27 = (Scaleform::GFx::Sprite *)v26;
                if ( v27
                  && (v27->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
                {
                  Scaleform::GFx::Sprite::SetHitArea((Scaleform::GFx::Sprite *)this->pDispObj, v27);
                  goto $LN238;
                }
              }
            }
          }
        }
        Scaleform::GFx::Sprite::SetHitArea((Scaleform::GFx::Sprite *)this->pDispObj, 0i64);
        goto LABEL_52;
      case 39:
        if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this)
                      + 240) < 8u )
          goto LABEL_52;
        v35 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
        v36 = Scaleform::GFx::AS2::Value::ToObject(&newVal, v35);
        v37 = (Scaleform::GFx::AS2::RectangleObject *)v36;
        if ( v36 )
        {
          if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v36->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v36->Scaleform::GFx::AS2::ObjectInterface) != 17 )
            goto LABEL_52;
          memset(&v, 0, sizeof(v));
          Scaleform::GFx::AS2::RectangleObject::GetProperties(v37, v35, (Scaleform::Render::Rect<double> *)&v);
          v41 = *(double *)&v.T.Type * 20.0;
          v42 = v.NV.NumberValue * 20.0;
          v43 = (*(double *)&v.V.FunctionValue.pLocalFrame - *(double *)&v.T.Type) * 20.0 + *(double *)&v.T.Type * 20.0;
          v44 = (*((double *)&v.NV + 3) - v.NV.NumberValue) * 20.0 + v.NV.NumberValue * 20.0;
          v38 = (Scaleform::Render::Rect<double> *)&v41;
        }
        else
        {
          v38 = 0i64;
        }
        Scaleform::GFx::DisplayObject::SetScrollRect(this->pDispObj, v38);
LABEL_52:
        v39 = 0;
        break;
      case 71:
        if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this)
                                  + 232)
                      + 104i64) != 1 )
          goto LABEL_52;
        v23 = this->pDispObj;
        v24 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v24) )
          v23->Flags |= 0x800u;
        else
          v23->Flags &= ~0x800u;
        goto $LN238;
      default:
        goto LABEL_52;
    }
  }
  if ( newVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&newVal);
  return v39;
}

// File Line: 1426
// RVA: 0x719AC0
bool __fastcall Scaleform::GFx::AS2::AvmSprite::SetMemberRaw(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  unsigned int StandardMemberConstant; // eax
  Scaleform::GFx::AS2::MovieClipObject *MovieClipObject; // rax
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h] BYREF

  if ( (name->pNode->HashFlags & 0x20000000) == 0 )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength(name) || Scaleform::GFx::ASConstString::GetCharAt(name, 0) != 95 )
      goto LABEL_11;
    Scaleform::GFx::ASString::ToLower(name, &result);
    pNode = result.pNode;
    if ( (result.pNode->HashFlags & 0x10000000) == 0 )
    {
      v10 = result.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      goto LABEL_11;
    }
    v10 = result.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                             (Scaleform::GFx::AS2::AvmSprite *)((char *)this - 8),
                             (Scaleform::GFx::ASStringNode *)name);
  if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Bool3W *, _QWORD, Scaleform::GFx::AS2::Value *, _QWORD))(*(_QWORD *)&this[-1].TabChildren.Value + 272i64))(
         &this[-1].TabChildren,
         StandardMemberConstant,
         val,
         0i64) )
  {
    LOBYTE(MovieClipObject) = 1;
    return (char)MovieClipObject;
  }
LABEL_11:
  if ( *(_QWORD *)&this->Level
    || (MovieClipObject = Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject((Scaleform::GFx::AS2::AvmSprite *)((char *)this - 8))) != 0i64 )
  {
    LOBYTE(MovieClipObject) = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)(*(_QWORD *)&this->Level + 32i64) + 80i64))(
                                *(_QWORD *)&this->Level + 32i64,
                                psc,
                                name,
                                val,
                                flags);
  }
  return (char)MovieClipObject;
}

// File Line: 1447
// RVA: 0x6F01A0
bool __fastcall Scaleform::GFx::AS2::AvmSprite::GetMember(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  __int64 StandardMemberConstant; // r13
  bool v11; // al
  Scaleform::GFx::AS2::Environment *v12; // rax
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  long double v15; // xmm0_8
  long double v16; // xmm0_8
  long double v17; // xmm0_8
  long double v18; // xmm0_8
  void *v19; // rax
  float v20; // xmm4_4
  unsigned int v21; // xmm3_4
  unsigned int v22; // xmm2_4
  unsigned int v23; // xmm1_4
  unsigned int v24; // xmm0_4
  __int64 v25; // rcx
  Scaleform::GFx::AS2::ArrayObject *v26; // r14
  int v27; // ebx
  Scaleform::GFx::AS2::Environment *v28; // rax
  Scaleform::GFx::AS2::ArrayObject *v29; // rax
  Scaleform::GFx::AS2::ArrayObject *v30; // r14
  Scaleform::Render::Matrix4x4<float> *v31; // rdi
  unsigned int v32; // eax
  long double v33; // xmm0_8
  Scaleform::GFx::AS2::MovieClipObject *pObject; // rcx
  bool v35; // r12
  Scaleform::GFx::AS2::Object *v36; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int v39; // eax
  unsigned int v40; // eax
  Scaleform::GFx::DisplayObject *DisplayObjectByName; // rax
  Scaleform::GFx::AS2::Object *v42; // r13
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> v43; // [rsp+20h] [rbp-B8h] BYREF
  Scaleform::GFx::AS2::ArrayObject *v44; // [rsp+28h] [rbp-B0h]
  Scaleform::GFx::AS2::Environment::GetVarParams val; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::Render::Matrix4x4<float> v46; // [rsp+60h] [rbp-78h] BYREF
  Scaleform::GFx::ASString result; // [rsp+130h] [rbp+58h] BYREF
  Scaleform::GFx::AS2::Value *retaddr; // [rsp+138h] [rbp+60h]

  *(_QWORD *)&v46.M[1][2] = -2i64;
  if ( (name->pNode->HashFlags & 0x20000000) != 0 )
    goto LABEL_9;
  if ( !Scaleform::GFx::ASConstString::GetLength(name) || Scaleform::GFx::ASConstString::GetCharAt(name, 0) != 95 )
  {
LABEL_31:
    if ( penv
      && name->pNode == (Scaleform::GFx::ASStringNode *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl
      || psc
      && name->pNode == (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl )
    {
      Scaleform::GFx::AS2::Value::SetAsObject(retaddr, this->pProto.pObject);
      return 1;
    }
    pObject = this->ASMovieClipObj.pObject;
    if ( pObject )
    {
      Scaleform::GFx::AS2::MovieClipObject::Exchange__proto__(
        pObject,
        (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&result,
        0i64);
      v35 = 0;
      if ( penv
        && this->ASMovieClipObj.pObject->vfptr->GetMember(
             &this->ASMovieClipObj.pObject->Scaleform::GFx::AS2::ObjectInterface,
             penv,
             name,
             retaddr) )
      {
        v35 = 1;
      }
      else if ( psc )
      {
        v35 = this->ASMovieClipObj.pObject->vfptr->GetMemberRaw(
                &this->ASMovieClipObj.pObject->Scaleform::GFx::AS2::ObjectInterface,
                psc,
                name,
                retaddr);
      }
      Scaleform::GFx::AS2::MovieClipObject::Exchange__proto__(
        this->ASMovieClipObj.pObject,
        &v43,
        (Scaleform::GFx::AS2::Object *)result.pNode);
      v36 = v43.pObject;
      if ( v43.pObject )
      {
        RefCount = v43.pObject->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v43.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v36);
        }
      }
      pNode = result.pNode;
      if ( v35 )
      {
        if ( result.pNode )
        {
          v39 = result.pNode->RefCount;
          if ( (v39 & 0x3FFFFFF) != 0 )
          {
            result.pNode->RefCount = v39 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pNode);
            return 1;
          }
        }
        return 1;
      }
      if ( result.pNode )
      {
        v40 = result.pNode->RefCount;
        if ( (v40 & 0x3FFFFFF) != 0 )
        {
          result.pNode->RefCount = v40 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pNode);
        }
      }
    }
    DisplayObjectByName = Scaleform::GFx::DisplayList::GetDisplayObjectByName(
                            (Scaleform::GFx::DisplayList *)&this->pDispObj[1],
                            name,
                            this->ASEnvironment.StringContext.SWFVersion > 6u);
    if ( DisplayObjectByName && SLOBYTE(DisplayObjectByName->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
    {
      Scaleform::GFx::AS2::Value::SetAsCharacter(retaddr, (Scaleform::GFx::InteractiveObject *)DisplayObjectByName);
      return 1;
    }
    v42 = this->pProto.pObject;
    if ( !v42
      || (!penv
       || !v42->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMember(
             &v42->Scaleform::GFx::AS2::ObjectInterface,
             penv,
             name,
             retaddr))
      && (!psc
       || !v42->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
             &v42->Scaleform::GFx::AS2::ObjectInterface,
             psc,
             name,
             retaddr)) )
    {
      v11 = Scaleform::GFx::ASConstString::GetLength(name)
         && *name->pNode->pData == 95
         && (val.VarName = name,
             *(_OWORD *)&val.pResult = (unsigned __int64)retaddr,
             memset(&val.ppNewTarget, 0, 20),
             Scaleform::GFx::AS2::Environment::CheckGlobalAndLevels(
               &this->ASEnvironment,
               (Scaleform::GFx::Bool3W *)&result,
               &val),
             LOBYTE(result.pNode))
         && LOBYTE(result.pNode) == 1;
      return v11;
    }
    return 1;
  }
  Scaleform::GFx::ASString::ToLower(name, &result);
  v8 = result.pNode;
  if ( (result.pNode->HashFlags & 0x10000000) == 0 )
  {
    v9 = result.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    goto LABEL_31;
  }
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
LABEL_9:
  StandardMemberConstant = (unsigned int)Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(this, name);
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, __int64, Scaleform::GFx::AS2::Value *, _QWORD))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].OnUnloading)(
         this,
         StandardMemberConstant,
         retaddr,
         0i64) )
  {
    return 1;
  }
  switch ( (int)StandardMemberConstant )
  {
    case $:
      Scaleform::GFx::AS2::Value::DropRefs(retaddr);
      retaddr->T.Type = 0;
      return 1;
    case o:
      v17 = ((double (__fastcall *)(Scaleform::GFx::InteractiveObject *, unsigned __int64))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[26].__vecDelDtor)(
              this->pDispObj,
              0x140000000ui64);
      Scaleform::GFx::AS2::Value::SetNumber(retaddr, v17);
      return 1;
    case p:
      v18 = ((double (__fastcall *)(Scaleform::GFx::InteractiveObject *, unsigned __int64))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[32].__vecDelDtor)(
              this->pDispObj,
              0x140000000ui64);
      Scaleform::GFx::AS2::Value::SetNumber(retaddr, v18);
      return 1;
    case q:
      v15 = ((double (__fastcall *)(Scaleform::GFx::InteractiveObject *, unsigned __int64))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[36].__vecDelDtor)(
              this->pDispObj,
              0x140000000ui64);
      Scaleform::GFx::AS2::Value::SetNumber(retaddr, v15);
      return 1;
    case r:
      v16 = ((double (__fastcall *)(Scaleform::GFx::InteractiveObject *, unsigned __int64))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[38].__vecDelDtor)(
              this->pDispObj,
              0x140000000ui64);
      Scaleform::GFx::AS2::Value::SetNumber(retaddr, v16);
      return 1;
    case s:
      v19 = this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[4].__vecDelDtor(this->pDispObj, 0x140000000ui64);
      v20 = *((float *)v19 + 7);
      v21 = *((_DWORD *)v19 + 8);
      v22 = *((_DWORD *)v19 + 9);
      v23 = *((_DWORD *)v19 + 10);
      v24 = *((_DWORD *)v19 + 11);
      v46.M[1][2] = *((float *)v19 + 6);
      v46.M[1][3] = v20;
      val.ExcludeFlags = v21;
      *(&val.ExcludeFlags + 1) = v22;
      *(_QWORD *)&v46.M[0][0] = __PAIR64__(v24, v23);
      *(_OWORD *)&v46.M[0][2] = _xmm;
      Scaleform::Render::Matrix4x4<float>::Transpose(&v46);
      v43.pObject = (Scaleform::GFx::AS2::Object *)penv->StringContext.pContext->pHeap;
      v26 = (Scaleform::GFx::AS2::ArrayObject *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))v43.pObject->vfptr[3].Finalize_GC)(
                                                  v25,
                                                  144i64,
                                                  0i64);
      v44 = v26;
      v27 = 0;
      if ( v26 )
      {
        v28 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
        Scaleform::GFx::AS2::ArrayObject::ArrayObject(v26, v28);
        v30 = v29;
      }
      else
      {
        v30 = 0i64;
      }
      v44 = v30;
      Scaleform::GFx::AS2::ArrayObject::Resize(v30, 16);
      v31 = &v46;
      do
      {
        LOBYTE(val.VarName) = 3;
        *(double *)&val.pResult = v31->M[0][0];
        Scaleform::GFx::AS2::ArrayObject::SetElement(v30, v27, (Scaleform::GFx::AS2::Value *)&val);
        if ( LOBYTE(val.VarName) >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&val);
        ++v27;
        v31 = (Scaleform::Render::Matrix4x4<float> *)((char *)v31 + 4);
      }
      while ( v27 < 16 );
      Scaleform::GFx::AS2::Value::SetAsObject(retaddr, v30);
      if ( !v30 )
        return 1;
      v32 = v30->RefCount;
      if ( (v32 & 0x3FFFFFF) == 0 )
        return 1;
      v30->RefCount = v32 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
      return 1;
    case t:
      v33 = ((double (__fastcall *)(Scaleform::GFx::InteractiveObject *, unsigned __int64))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[40].__vecDelDtor)(
              this->pDispObj,
              0x140000000ui64);
      Scaleform::GFx::AS2::Value::SetNumber(retaddr, v33);
      return 1;
    case u:
      if ( !this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].HasEventHandler(
              &this->Scaleform::GFx::AvmSpriteBase,
              (Scaleform::GFx::EventId *)0x140000000i64) )
        goto LABEL_31;
      v12 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
      v13 = Scaleform::GFx::AS2::Environment::CreateConstString(v12, &result, "WIN 8,0,0,0");
      Scaleform::GFx::AS2::Value::SetString(retaddr, v13);
      v14 = result.pNode;
      v9 = result.pNode->RefCount-- == 1;
      if ( !v9 )
        return 1;
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v11 = 1;
      break;
    default:
      goto LABEL_31;
  }
  return v11;
}   v11 = 1;
      break;
    default:
      goto LABEL_31;
  }
  return v11;
}

// File Line: 1622
// RVA: 0x6F51B0
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::AS2::AvmSprite::GetRelativeTarget(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::ASString *name,
        bool first_call)
{
  Scaleform::GFx::ASStringNode *pNode; // r9
  bool v5; // si
  Scaleform::GFx::ASMovieRootBase *pObject; // rax
  Scaleform::GFx::Sprite *result; // rax
  Scaleform::GFx::ASMovieRootBase *v10; // rdx
  void *(__fastcall *pLower)(Scaleform::RefCountImplCore *, unsigned int); // rcx
  const char *pData; // rcx
  int v13; // eax
  char *ptail; // [rsp+30h] [rbp+8h] BYREF

  pNode = name->pNode;
  v5 = this->ASEnvironment.StringContext.SWFVersion > 6u;
  if ( (name->pNode->HashFlags & 0x80000000) != 0 )
  {
    if ( this->ASEnvironment.StringContext.SWFVersion > 6u )
    {
      pObject = this->ASEnvironment.StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( (Scaleform::GFx::ASStringNode *)pObject[17].pASSupport.pObject != pNode
        && (Scaleform::GFx::ASStringNode *)pObject[20].vfptr != pNode )
      {
        if ( *(Scaleform::GFx::ASStringNode **)&pObject[17].AVMVersion != pNode
          && *(Scaleform::GFx::ASStringNode **)&pObject[20].AVMVersion != pNode )
        {
          if ( (Scaleform::GFx::ASStringNode *)pObject[20].pASSupport.pObject == pNode )
            return (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, _QWORD))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].HasEventHandler)(
                                               this,
                                               0i64);
          goto LABEL_18;
        }
        return (Scaleform::GFx::Sprite *)this->pDispObj->pParent;
      }
      return (Scaleform::GFx::Sprite *)this->pDispObj;
    }
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    pNode = name->pNode;
    v10 = this->ASEnvironment.StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    if ( v10[17].pASSupport.pObject == (Scaleform::GFx::ASSupport *)name->pNode )
      return (Scaleform::GFx::Sprite *)this->pDispObj;
    pLower = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))pNode->pLower;
    if ( v10[20].vfptr[2].__vecDelDtor == pLower )
      return (Scaleform::GFx::Sprite *)this->pDispObj;
    if ( *(Scaleform::GFx::ASStringNode **)&v10[17].AVMVersion == pNode
      || *(void *(__fastcall **)(Scaleform::RefCountImplCore *, unsigned int))(*(_QWORD *)&v10[20].AVMVersion + 16i64) == pLower )
    {
      return (Scaleform::GFx::Sprite *)this->pDispObj->pParent;
    }
    if ( *(void *(__fastcall **)(Scaleform::RefCountImplCore *, unsigned int))&v10[20].pASSupport.pObject->SType == pLower )
      return (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, _QWORD))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].HasEventHandler)(
                                         this,
                                         0i64);
  }
LABEL_18:
  pData = pNode->pData;
  if ( *pNode->pData == 95 && first_call )
  {
    ptail = 0i64;
    v13 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(pData, (const char **)&ptail, v5);
    if ( v13 != -1 && !*ptail )
      return Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
               (Scaleform::GFx::AS2::MovieRoot *)this->pDispObj->pASRoot,
               v13);
  }
  result = (Scaleform::GFx::Sprite *)Scaleform::GFx::DisplayList::GetDisplayObjectByName(
                                       (Scaleform::GFx::DisplayList *)&this->pDispObj[1],
                                       name,
                                       this->ASEnvironment.StringContext.SWFVersion > 6u);
  if ( !result
    || SLOBYTE(result->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >= 0 )
  {
    return 0i64;
  }
  return result;
}playObjectBase::Flags) >= 0 )
  {
    

// File Line: 1684
// RVA: 0x714D20
void __fastcall Scaleform::GFx::AS2::AvmSprite::SetLevel(Scaleform::GFx::AS2::AvmSprite *this, int level)
{
  unsigned __int64 v4; // rbx
  Scaleform::GFx::InteractiveObject *pDispObj; // rcx
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rdi
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  unsigned __int64 Size; // r8
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // rdx
  __int64 v10; // rax
  Scaleform::Render::TreeContainer *vfptr; // rdi
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::GFx::InteractiveObject *v13; // rbx
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  char pstr; // [rsp+20h] [rbp-C8h] BYREF
  __int64 v18; // [rsp+21h] [rbp-C7h]
  __int64 v19; // [rsp+29h] [rbp-BFh]
  __int64 v20; // [rsp+31h] [rbp-B7h]
  __int64 v21; // [rsp+39h] [rbp-AFh]
  __int64 v22; // [rsp+41h] [rbp-A7h]
  __int64 v23; // [rsp+49h] [rbp-9Fh]
  __int64 v24; // [rsp+51h] [rbp-97h]
  int v25; // [rsp+59h] [rbp-8Fh]
  __int16 v26; // [rsp+5Dh] [rbp-8Bh]
  char v27; // [rsp+5Fh] [rbp-89h]
  Scaleform::MsgFormat::Sink r; // [rsp+60h] [rbp-88h] BYREF
  __int64 v29; // [rsp+78h] [rbp-70h]
  Scaleform::GFx::ASString result; // [rsp+488h] [rbp+3A0h] BYREF
  int v; // [rsp+490h] [rbp+3A8h] BYREF

  v29 = -2i64;
  v4 = 0i64;
  pDispObj = this->pDispObj;
  pASRoot = pDispObj->pASRoot;
  pMovieImpl = pASRoot->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v10 = 0i64;
    do
    {
      if ( Data[v10].Level > level )
        break;
      ++v4;
      ++v10;
    }
    while ( v4 < Size );
  }
  vfptr = (Scaleform::Render::TreeContainer *)pASRoot[1].vfptr;
  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(pDispObj);
  Scaleform::Render::TreeContainer::Insert(vfptr, v4, RenderNode);
  this->Level = level;
  pstr = 0;
  v18 = 0i64;
  v19 = 0i64;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 0i64;
  v23 = 0i64;
  v24 = 0i64;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  r.Type = tDataPtr;
  r.SinkData.pStr = (Scaleform::String *)&pstr;
  r.SinkData.DataPtr.Size = 64i64;
  Scaleform::MsgFormat::MsgFormat((Scaleform::MsgFormat *)&r.SinkData, &r);
  Scaleform::MsgFormat::Parse((Scaleform::MsgFormat *)&r.SinkData, "_level{0}");
  Scaleform::MsgFormat::FormatD1<long>((Scaleform::MsgFormat *)&r.SinkData, &v);
  Scaleform::MsgFormat::FinishFormatD((Scaleform::MsgFormat *)&r.SinkData);
  Scaleform::MsgFormat::~MsgFormat((Scaleform::MsgFormat *)&r.SinkData);
  v13 = this->pDispObj;
  v14 = Scaleform::GFx::AS2::Environment::CreateString(&this->ASEnvironment, &result, &pstr);
  v13->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[124].__vecDelDtor(
    v13,
    (unsigned int)v14);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 1708
// RVA: 0x7058C0
char __fastcall Scaleform::GFx::AS2::AvmSprite::OnEvent(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::Sprite *pDispObj; // rcx
  Scaleform::GFx::TimelineDef *pObject; // rax
  char v6; // dl
  unsigned int v7; // eax
  const char *v8; // rdx
  __int64 v9; // rax
  bool v10; // r14
  Scaleform::GFx::AS2::MovieClipObject *v11; // rcx
  Scaleform::GFx::InteractiveObject *v12; // r15
  Scaleform::GFx::MovieImpl *pMovieImpl; // r12
  __int64 ControllerIndex; // r13
  Scaleform::GFx::Sprite *v15; // rbx
  bool v16; // r15
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v18; // zf
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v22; // rbx
  Scaleform::GFx::InteractiveObject *v23; // rdi
  Scaleform::RefCountNTSImpl *v24; // rcx
  Scaleform::RefCountNTSImpl *v25; // rcx
  Scaleform::GFx::AS2::Value v26; // [rsp+30h] [rbp-20h] BYREF
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+40h] BYREF
  Scaleform::Ptr<Scaleform::GFx::Sprite> v28; // [rsp+A0h] [rbp+50h] BYREF
  Scaleform::GFx::Sprite *v29; // [rsp+A8h] [rbp+58h]

  pDispObj = (Scaleform::GFx::Sprite *)this->pDispObj;
  if ( (pDispObj->Flags & 0x40) != 0 )
    pObject = pDispObj->pDef.pObject;
  else
    pObject = 0i64;
  if ( pObject )
  {
    v6 = pObject[2].Id.Id;
    if ( (v6 & 7) != 0 )
    {
      v7 = id->Id;
      if ( id->Id > 0x2000 )
      {
        if ( v7 == 0x4000 )
        {
LABEL_18:
          if ( (v6 & 1) == 0 )
            goto LABEL_21;
          v8 = "_up";
          goto LABEL_20;
        }
        if ( v7 != 0x10000 )
          goto LABEL_21;
      }
      else if ( v7 != 0x2000 )
      {
        if ( v7 == 1024 )
        {
          if ( (v6 & 2) == 0 )
            goto LABEL_21;
          v8 = "_down";
LABEL_20:
          Scaleform::GFx::Sprite::GotoLabeledFrame(pDispObj, v8, 0);
          goto LABEL_21;
        }
        if ( v7 != 2048 )
        {
          if ( v7 != 4096 )
            goto LABEL_21;
          goto LABEL_18;
        }
      }
      if ( (v6 & 4) == 0 )
        goto LABEL_21;
      v8 = "_over";
      goto LABEL_20;
    }
  }
LABEL_21:
  if ( Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(this, id) )
  {
LABEL_46:
    inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].RefCount,
                 AP_Frame);
    v22 = inserted;
    if ( inserted )
    {
      *(_OWORD *)&v26.T.Type = *(_OWORD *)&id->Id;
      *((_DWORD *)&v26.NV + 4) = *(_DWORD *)&id->RollOverCnt;
      v23 = this->pDispObj;
      inserted->Type = Entry_Event;
      if ( v23 )
        ++v23->RefCount;
      v24 = inserted->pCharacter.pObject;
      if ( v24 )
        Scaleform::RefCountNTSImpl::Release(v24);
      v22->pCharacter.pObject = v23;
      v25 = v22->pActionBuffer.pObject;
      if ( v25 )
        Scaleform::RefCountNTSImpl::Release(v25);
      v22->pActionBuffer.pObject = 0i64;
      *(_QWORD *)&v22->mEventId.Id = *(_QWORD *)&v26.T.Type;
      v22->mEventId.KeyCode = v26.NV.UInt32Value;
      v22->mEventId.AsciiCode = BYTE4(v26.NV.NumberValue);
      *(_DWORD *)&v22->mEventId.RollOverCnt = *((_DWORD *)&v26.NV + 4);
    }
    return 1;
  }
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v9 + 232) + 40i64) + 24i64) + 312i64),
    id);
  if ( result.pNode->Size )
  {
    v10 = 0;
    v26.T.Type = 0;
    v11 = this->ASMovieClipObj.pObject;
    if ( v11 || (v11 = (Scaleform::GFx::AS2::MovieClipObject *)this->pProto.pObject) != 0i64 )
      v10 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))v11->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw)(
              &v11->Scaleform::GFx::AS2::ObjectInterface,
              &this->ASEnvironment.StringContext,
              &result,
              &v26,
              -2i64) != 0;
    if ( ((id->Id - 64) & 0xFFFFFFBF) != 0 )
      goto LABEL_36;
    if ( this->ASEnvironment.StringContext.SWFVersion >= 6u )
    {
      v12 = this->pDispObj;
      pMovieImpl = v12->pASRoot->pMovieImpl;
      ControllerIndex = (unsigned int)id->ControllerIndex;
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->FocusGroups[(unsigned __int8)pMovieImpl->FocusGroupIndexes[ControllerIndex]].LastFocused,
        &v28);
      v15 = v28.pObject;
      if ( v28.pObject )
      {
        ++v28.pObject->RefCount;
        v15 = v28.pObject;
      }
      v29 = v15;
      if ( v28.pObject )
        Scaleform::RefCountNTSImpl::Release(v28.pObject);
      v16 = v15 == v12;
      if ( v15 )
        Scaleform::RefCountNTSImpl::Release(v15);
      if ( v16
        && pMovieImpl->FocusGroups[(unsigned __int8)pMovieImpl->FocusGroupIndexes[ControllerIndex]].FocusRectShown )
      {
LABEL_36:
        if ( v10 )
        {
          if ( v26.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v26);
          pNode = result.pNode;
          v18 = result.pNode->RefCount-- == 1;
          if ( v18 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          goto LABEL_46;
        }
      }
    }
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  v19 = result.pNode;
  v18 = result.pNode->RefCount-- == 1;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  return 0;
}

// File Line: 1811
// RVA: 0x6E7D10
char __fastcall Scaleform::GFx::AS2::AvmSprite::ExecuteBuffer(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ActionBuffer *pactionbuffer)
{
  Scaleform::GFx::AS2::Environment *v3; // rax

  if ( (this->pDispObj->Flags & 0x10) != 0 )
    return 0;
  v3 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
  Scaleform::GFx::AS2::ActionBuffer::Execute(
    pactionbuffer,
    v3,
    0,
    pactionbuffer->pBufferData.pObject->BufferLen,
    0i64,
    0i64,
    Exec_Unknown);
  return 1;
}

// File Line: 1827
// RVA: 0x6E87D0
bool __fastcall Scaleform::GFx::AS2::AvmSprite::ExecuteEvent(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // rbx
  Scaleform::GFx::InteractiveObject *v6; // rcx
  bool v7; // bp

  pDispObj = this->pDispObj;
  if ( (pDispObj->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0 )
    return 0;
  if ( pDispObj )
    ++pDispObj->RefCount;
  if ( id->Id != 1
    || (this->pDispObj->Flags &= ~0x20u, v6 = this->pDispObj, (v6->Scaleform::GFx::DisplayObject::Flags & 8) != 0)
    || SLOBYTE(v6[1].pIndXFormData) < 0 )
  {
    v7 = Scaleform::GFx::AS2::AvmCharacter::ExecuteEvent(this, id);
    if ( id->Id == 4 )
    {
      this->pDispObj->Flags |= 0x10u;
      Scaleform::GFx::InteractiveObject::SetNextUnloaded(
        this->pDispObj,
        this->pDispObj->pASRoot->pMovieImpl->pUnloadListHead);
      this->pDispObj->pASRoot->pMovieImpl->pUnloadListHead = this->pDispObj;
      ++this->pDispObj->RefCount;
    }
  }
  else
  {
    v7 = 0;
  }
  if ( pDispObj )
    Scaleform::RefCountNTSImpl::Release(pDispObj);
  return v7;
}

// File Line: 1886
// RVA: 0x6D7790
bool __fastcall Scaleform::GFx::AS2::AvmSprite::ActsAsButton(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::MovieClipObject *pObject; // rdi
  Scaleform::GFx::AS2::MovieClipObject *v3; // rbx

  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AvmSpriteBase *))this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].HasEventHandler)(&this->Scaleform::GFx::AvmSpriteBase)
    || (this->pDispObj->Flags & 0x10) == 0 )
  {
    return 0;
  }
  pObject = this->ASMovieClipObj.pObject;
  if ( !pObject )
  {
    pObject = (Scaleform::GFx::AS2::MovieClipObject *)this->pProto.pObject;
    if ( !pObject )
      return 0;
  }
  if ( pObject->ButtonEventMask || pObject->HasButtonHandlers )
    return 1;
  v3 = (Scaleform::GFx::AS2::MovieClipObject *)pObject->pProto.pObject;
  if ( !v3 )
    return 0;
  while ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&pObject->pProto.pObject->vfptr->gap8[8])(&pObject->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface) != 11 )
  {
    v3 = (Scaleform::GFx::AS2::MovieClipObject *)v3->pProto.pObject;
    if ( !v3 )
      return 0;
  }
  return Scaleform::GFx::AS2::MovieClipObject::ActsAsButton(v3);
}

// File Line: 1904
// RVA: 0x724080
void __fastcall Scaleform::GFx::AS2::AvmSprite::VisitMembers(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::DisplayList::MemberVisitorVtbl *pvisitor,
        unsigned int visitFlags)
{
  Scaleform::GFx::DisplayList::MemberVisitor v8[2]; // [rsp+38h] [rbp-20h] BYREF
  unsigned int v9; // [rsp+48h] [rbp-10h]

  if ( (visitFlags & 2) != 0 )
  {
    v8[0].vfptr = (Scaleform::GFx::DisplayList::MemberVisitorVtbl *)&`Scaleform::GFx::AS2::AvmSprite::VisitMembers::`5::Visitor::`vftable;
    v8[1].vfptr = pvisitor;
    v9 = visitFlags;
    Scaleform::GFx::DisplayList::VisitMembers((Scaleform::GFx::DisplayList *)&this->pProto.pObject[2].RefCount, v8);
    v8[0].vfptr = (Scaleform::GFx::DisplayList::MemberVisitorVtbl *)&Scaleform::GFx::DisplayList::MemberVisitor::`vftable;
  }
  Scaleform::GFx::AS2::AvmCharacter::VisitMembers(
    this,
    psc,
    (Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *)pvisitor,
    visitFlags);
}

// File Line: 1915
// RVA: 0x7239A0
void __fastcall Scaleform::GFx::AS2::AvmSprite::VisitMembers_::_5_::Visitor::Visit(
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::InteractiveObject *pch,
        Scaleform::GFx::DisplayObject *a3)
{
  Scaleform::GFx::ASStringNode *pObject; // rax
  Scaleform::GFx::AS2::Value v6; // [rsp+28h] [rbp-30h] BYREF

  v6.T.Type = 7;
  if ( a3 )
  {
    pObject = (Scaleform::GFx::ASStringNode *)a3->pNameHandle.pObject;
    if ( !pObject )
      pObject = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(a3);
    v6.V.pStringNode = pObject;
    if ( pObject )
      ++LODWORD(pObject->pData);
  }
  else
  {
    v6.V.pStringNode = 0i64;
  }
  (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::AS2::Value *, _QWORD, __int64))name[1].pNode->pData
   + 1))(
    name[1].pNode,
    pch,
    &v6,
    LOBYTE(name[2].pNode),
    -2i64);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
}

// File Line: 1928
// RVA: 0x6E20E0
bool __fastcall Scaleform::GFx::AS2::AvmSprite::DeleteMember(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  return Scaleform::GFx::AS2::AvmCharacter::DeleteMember(this, psc, name) != 0;
}

// File Line: 1935
// RVA: 0x6F43E0
Scaleform::GFx::AS2::MovieClipObject *__fastcall Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject(
        Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::MovieClipObject *v2; // rsi
  Scaleform::GFx::Sprite *pDispObj; // rbx
  Scaleform::GFx::AS2::GlobalContext *v4; // rax
  Scaleform::GFx::AS2::MovieClipObject *v5; // rax
  Scaleform::GFx::AS2::MovieClipObject *v6; // rbx
  Scaleform::GFx::AS2::MovieClipObject *pObject; // rcx
  unsigned int RefCount; // eax

  if ( this->ASMovieClipObj.pObject )
    return this->ASMovieClipObj.pObject;
  v2 = (Scaleform::GFx::AS2::MovieClipObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, __int64))this->pDispObj->pASRoot->pMovieImpl->pHeap->vfptr->Alloc)(
                                                 this,
                                                 112i64);
  if ( v2 )
  {
    pDispObj = (Scaleform::GFx::Sprite *)this->pDispObj;
    v4 = (Scaleform::GFx::AS2::GlobalContext *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[1].OnUnloading)(this);
    Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(v2, v4, pDispObj);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  pObject = this->ASMovieClipObj.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->ASMovieClipObj.pObject = v6;
  return v6;
}

// File Line: 1942
// RVA: 0x6EE320
// attributes: thunk
Scaleform::GFx::AS2::MovieClipObject *__fastcall Scaleform::GFx::AS2::AvmSprite::GetASObject(
        Scaleform::GFx::AS2::AvmSprite *this)
{
  return Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject(this);
}

// File Line: 1952
// RVA: 0x7008B0
bool __fastcall Scaleform::GFx::AS2::AvmSprite::IsFocusEnabled(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::AS2::Object *pObject; // rdi
  Scaleform::GFx::ASString *v5; // rax
  char v6; // di
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // bl
  Scaleform::GFx::AS2::Value v10; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h] BYREF

  if ( fmt == GFx_FocusMovedByMouse )
    return 0;
  pObject = this->pProto.pObject;
  if ( !pObject )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[1].__vecDelDtor)(this);
  v10.T.Type = 0;
  v5 = Scaleform::GFx::AS2::Environment::CreateConstString(&this->ASEnvironment, &result, "focusEnabled");
  v6 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw)(
         &pObject->Scaleform::GFx::AS2::ObjectInterface,
         &this->ASEnvironment.StringContext,
         v5,
         &v10,
         -2i64);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( !v6 || !v10.T.Type || v10.T.Type == 10 )
  {
    if ( v10.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v10);
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[1].__vecDelDtor)(this);
  }
  v9 = Scaleform::GFx::AS2::Value::ToBool(&v10, &this->ASEnvironment);
  if ( v10.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v10);
  return v9;
}

// File Line: 1971
// RVA: 0x6E8AA0
void __fastcall Scaleform::GFx::AS2::AvmSprite::ExecuteFrame0Events(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rax
  unsigned __int64 Capacity; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v4; // rdi
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::RefCountNTSImpl *v6; // rcx

  inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
               (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)(*(_QWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity
                                                                             + 32)
                                                                 + 128i64),
               AP_Load);
  Capacity = this[-1].InitActionsExecuted.Data.Policy.Capacity;
  v4 = inserted;
  inserted->Type = Entry_Event;
  if ( Capacity )
    ++*(_DWORD *)(Capacity + 8);
  pObject = inserted->pCharacter.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v4->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)Capacity;
  v6 = v4->pActionBuffer.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  v4->pActionBuffer.pObject = 0i64;
  *(_QWORD *)&v4->mEventId.Id = 1i64;
  v4->mEventId.KeyCode = 0;
  v4->mEventId.AsciiCode = 0;
  *(_DWORD *)&v4->mEventId.RollOverCnt = 65280;
}

// File Line: 1976
// RVA: 0x6EF040
_BOOL8 __fastcall Scaleform::GFx::AS2::AvmSprite::GetCursorType(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::Environment *v2; // rdi
  BOOL v3; // ebx
  Scaleform::GFx::AS2::Value v5; // [rsp+28h] [rbp-30h] BYREF

  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[1].__vecDelDtor)(this) )
    return 0i64;
  v2 = (Scaleform::GFx::AS2::Environment *)this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase(this);
  v5.T.Type = 0;
  v3 = !this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
          &this->Scaleform::GFx::AS2::ObjectInterface,
          &v2->StringContext,
          (Scaleform::GFx::ASString *)&v2->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pMovieImpl,
          &v5)
    || v5.T.Type && v5.T.Type != 10 && Scaleform::GFx::AS2::Value::ToBool(&v5, v2);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  return v3;
}

// File Line: 2068
// RVA: 0x6ABB60
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpritePlay(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rcx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
    vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
      vfptr,
      0);
}

// File Line: 2075
// RVA: 0x6ABC50
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteStop(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rcx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
    vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
      vfptr,
      1u);
}

// File Line: 2082
// RVA: 0x6AC5E0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGotoAndPlay(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::InteractiveObject *vfptr; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  __int64 v7; // r9
  char v8; // al
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  unsigned int v11; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+48h] [rbp+10h] BYREF

  ThisPtr = fn->ThisPtr;
  v3 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    if ( fn->NArgs < 1 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(
        &vfptr->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "AvmSprite::SpriteGotoAndPlay needs one arg");
      return;
    }
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v3 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v11 = -1;
    if ( v3->T.Type == 5 )
    {
      Scaleform::GFx::AS2::Value::ToString(v3, &result, Env, -1);
      LOBYTE(v7) = 1;
      v8 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, const char *, unsigned int *, __int64, __int64))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[108].__vecDelDtor)(
             vfptr,
             result.pNode->pData,
             &v11,
             v7,
             -2i64);
      pNode = result.pNode;
      if ( !v8 )
      {
        v10 = result.pNode->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        return;
      }
      v10 = result.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      v11 = Scaleform::GFx::AS2::Value::ToUInt32(v3, Env) - 1;
    }
    vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[110].__vecDelDtor(
      vfptr,
      v11);
    vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
      vfptr,
      0);
  }
}

// File Line: 2110
// RVA: 0x6AC250
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGotoAndStop(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::InteractiveObject *vfptr; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  __int64 v7; // r9
  char v8; // al
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  unsigned int v11; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+48h] [rbp+10h] BYREF

  ThisPtr = fn->ThisPtr;
  v3 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    if ( fn->NArgs < 1 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(
        &vfptr->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "AvmSprite::SpriteGotoAndStop needs one arg");
      return;
    }
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v3 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v11 = -1;
    if ( v3->T.Type == 5 )
    {
      Scaleform::GFx::AS2::Value::ToString(v3, &result, Env, -1);
      LOBYTE(v7) = 1;
      v8 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, const char *, unsigned int *, __int64, __int64))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[108].__vecDelDtor)(
             vfptr,
             result.pNode->pData,
             &v11,
             v7,
             -2i64);
      pNode = result.pNode;
      if ( !v8 )
      {
        v10 = result.pNode->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        return;
      }
      v10 = result.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      v11 = Scaleform::GFx::AS2::Value::ToUInt32(v3, Env) - 1;
    }
    vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[110].__vecDelDtor(
      vfptr,
      v11);
    vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
      vfptr,
      1u);
  }
}

// File Line: 2138
// RVA: 0x6AC900
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteNextFrame(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rdi
  Scaleform::GFx::InteractiveObject *vfptr; // rdi
  int v3; // ebx
  int v4; // eax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    v3 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[111].__vecDelDtor)(vfptr);
    v4 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[107].__vecDelDtor)(vfptr);
    if ( v4 < v3 )
      vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[110].__vecDelDtor(
        vfptr,
        v4 + 1);
    vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
      vfptr,
      1u);
  }
}

// File Line: 2150
// RVA: 0x6ACB60
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpritePrevFrame(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rbx
  int v3; // eax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    v3 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[107].__vecDelDtor)(vfptr);
    if ( v3 > 0 )
      vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[110].__vecDelDtor(
        vfptr,
        v3 - 1);
    vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
      vfptr,
      1u);
  }
}

// File Line: 2162
// RVA: 0x6ACBE0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetBytesLoaded(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::Sprite *vfptr; // rcx
  unsigned int BytesLoaded; // eax
  Scaleform::GFx::AS2::Value *Result; // rbx
  int v6; // esi

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::Sprite *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = (Scaleform::GFx::Sprite *)fn->Env->Target;
  }
  if ( vfptr )
  {
    BytesLoaded = Scaleform::GFx::Sprite::GetBytesLoaded(vfptr);
    Result = fn->Result;
    v6 = BytesLoaded;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    Result->NV.Int32Value = v6;
    Result->T.Type = 4;
  }
}

// File Line: 2176
// RVA: 0x6ACC60
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetBytesTotal(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rcx
  __int64 v4; // rax
  Scaleform::GFx::AS2::Value *Result; // rbx
  int v6; // esi

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    v4 = ((__int64 (*)(void))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)();
    Result = fn->Result;
    v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 104) + 24i64) + 64i64) + 80i64);
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    Result->NV.Int32Value = v6;
    Result->T.Type = 4;
  }
}

// File Line: 2185
// RVA: 0x6AEBE0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteDuplicateMovieClip(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // r14
  Scaleform::GFx::AS2::Value *v4; // rsi
  Scaleform::GFx::InteractiveObject *vfptr; // r14
  int NArgs; // eax
  unsigned int v7; // r9d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::AS2::ObjectInterface *v10; // rbp
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *v12; // r8
  Scaleform::GFx::AS2::Value *v13; // r10
  Scaleform::GFx::ASString *v14; // r15
  unsigned int v15; // r8d
  Scaleform::GFx::AS2::Environment *v16; // r9
  char *v17; // rcx
  Scaleform::GFx::AS2::AvmCharacter *v18; // rbx
  long double v19; // xmm0_8
  Scaleform::GFx::InteractiveObject *v20; // rax
  Scaleform::GFx::InteractiveObject *v21; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::InteractiveObject *v25; // [rsp+68h] [rbp+10h]

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  v4 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    NArgs = fn->NArgs;
    if ( NArgs >= 2 )
    {
      if ( NArgs == 3 )
      {
        v7 = fn->FirstArgBottomIndex - 2;
        Env = fn->Env;
        v9 = 0i64;
        if ( v7 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                 + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
          v9 = &Env->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
        v10 = Scaleform::GFx::AS2::Value::ToObjectInterface(v9, Env);
      }
      else
      {
        v10 = 0i64;
      }
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      v12 = fn->Env;
      v13 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(v12->Stack.pCurrent - v12->Stack.pPageStart) )
        v13 = &v12->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v14 = Scaleform::GFx::AS2::Value::ToString(v13, &result, v12, -1);
      v15 = fn->FirstArgBottomIndex - 1;
      v16 = fn->Env;
      if ( v15 <= 32 * ((unsigned int)v16->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v16->Stack.pCurrent - v16->Stack.pPageStart) )
        v4 = &v16->Stack.Pages.Data.Data[v15 >> 5]->Values[v15 & 0x1F];
      v17 = (char *)vfptr + 4 * (unsigned __int8)vfptr->AvmObjOffset;
      v18 = (Scaleform::GFx::AS2::AvmCharacter *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v17 + 8i64))(v17);
      v19 = Scaleform::GFx::AS2::Value::ToNumber(v4, fn->Env);
      v20 = Scaleform::GFx::AS2::AvmCharacter::CloneDisplayObject(v18, v14, (int)v19 + 0x4000, v10);
      v21 = v20;
      if ( v20 )
        ++v20->RefCount;
      v25 = v20;
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( Scaleform::GFx::DisplayObjectBase::GetVersion(vfptr) >= 6 )
        Scaleform::GFx::AS2::Value::SetAsCharacter(fn->Result, v21);
      if ( v21 )
        Scaleform::RefCountNTSImpl::Release(v21);
    }
  }
}

// File Line: 2202
// RVA: 0x6AE810
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteAttachMovie(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rsi
  Scaleform::GFx::InteractiveObject *v4; // r14
  Scaleform::GFx::InteractiveObject *vfptr; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  Scaleform::GFx::MovieDefImpl *v10; // rax
  bool v11; // bl
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v14; // zf
  Scaleform::GFx::ASString *v15; // rax
  int v16; // ebx
  Scaleform::GFx::AS2::Value *v17; // rax
  unsigned int v18; // eax
  Scaleform::GFx::AS2::Value *v19; // rax
  Scaleform::GFx::AS2::ObjectInterface *v20; // rbx
  Scaleform::GFx::AS2::Value *v21; // rax
  Scaleform::GFx::ASString *v22; // rax
  __int64 v23; // rax
  char *v24; // rbx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::ResourceBindData presBindData; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::ASString v30; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::ASString v31; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::Render::Cxform v32[2]; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Render::RenderBuffer *v33; // [rsp+B0h] [rbp-50h]
  int v34; // [rsp+B8h] [rbp-48h]
  unsigned int v35; // [rsp+BCh] [rbp-44h]
  int v36; // [rsp+C0h] [rbp-40h]
  __int64 v37; // [rsp+C8h] [rbp-38h]
  int v38; // [rsp+D0h] [rbp-30h]
  __int16 v39; // [rsp+D4h] [rbp-2Ch]
  Scaleform::GFx::Resource *pObject; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::GFx::Resource *pOwnerDefRes; // [rsp+E8h] [rbp-18h]
  __int64 v42; // [rsp+F0h] [rbp-10h]
  __int64 v43; // [rsp+F8h] [rbp-8h]
  __int64 v44; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::ASString result; // [rsp+140h] [rbp+40h] BYREF
  Scaleform::String symbol; // [rsp+148h] [rbp+48h] BYREF
  Scaleform::GFx::ASString v47; // [rsp+150h] [rbp+50h] BYREF
  Scaleform::GFx::ASString v48; // [rsp+158h] [rbp+58h] BYREF

  v44 = -2i64;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  v4 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( !vfptr || fn->NArgs < 3 )
    return;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v8 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToString(v8, &result, Env, -1);
  presBindData.pResource.pObject = 0i64;
  presBindData.pBinding = 0i64;
  Scaleform::String::String(&symbol, result.pNode->pData);
  pMovieImpl = vfptr->pASRoot->pMovieImpl;
  v10 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(vfptr);
  v11 = !Scaleform::GFx::MovieImpl::FindExportedResource(pMovieImpl, v10, &presBindData, &symbol);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v11 )
  {
    Name = Scaleform::GFx::DisplayObject::GetName(vfptr, &v47);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &vfptr->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie() failed - export name \"%s\" is not found.",
      Name->pNode->pData,
      result.pNode->pData);
    pNode = v47.pNode;
    v14 = v47.pNode->RefCount-- == 1;
    if ( v14 )
LABEL_14:
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)(presBindData.pResource.pObject) & 0x8000) != 0 )
    {
      pOwnerDefRes = 0i64;
      v42 = 0i64;
      pObject = presBindData.pResource.pObject;
      pOwnerDefRes = presBindData.pBinding->pOwnerDefRes;
      v16 = (int)presBindData.pResource.pObject[1].vfptr;
      v17 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
      v18 = (int)Scaleform::GFx::AS2::Value::ToNumber(v17, fn->Env) + 0x4000;
      v32[0] = Scaleform::Render::Cxform::Identity;
      v32[1] = (Scaleform::Render::Cxform)Scaleform::Render::Matrix2x4<float>::Identity;
      v33 = 0i64;
      v34 = 0;
      v39 = 256;
      v38 = 786432;
      v35 = v18;
      v36 = v16;
      v37 = 0i64;
      if ( v18 > 0x7EFFFFFD )
      {
        v26 = Scaleform::GFx::DisplayObject::GetName(vfptr, &v31);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          &vfptr->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
          "%s.attachMovie(\"%s\") failed - depth (%d) must be >= 0",
          v26->pNode->pData,
          result.pNode->pData,
          v35);
        v27 = v31.pNode;
        v14 = v31.pNode->RefCount-- == 1;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      }
      else
      {
        if ( fn->NArgs == 4 )
        {
          v19 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
          v20 = Scaleform::GFx::AS2::Value::ToObjectInterface(v19, fn->Env);
        }
        else
        {
          v20 = 0i64;
        }
        v21 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v22 = Scaleform::GFx::AS2::Value::ToString(v21, &v30, fn->Env, -1);
        v23 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, Scaleform::GFx::AS2::ObjectInterface *, int, int, Scaleform::GFx::Resource **, _QWORD))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[118].__vecDelDtor)(
                vfptr,
                v32,
                v22,
                0i64,
                v20,
                -1,
                1,
                &pObject,
                0i64);
        v24 = (char *)v23;
        if ( v23 )
          ++*(_DWORD *)(v23 + 8);
        v43 = v23;
        v25 = v30.pNode;
        v14 = v30.pNode->RefCount-- == 1;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        if ( v24 )
        {
          (*(void (__fastcall **)(char *, _QWORD))(*(_QWORD *)v24 + 424i64))(v24, 0i64);
          if ( Scaleform::GFx::DisplayObjectBase::GetVersion(vfptr) >= 6 )
          {
            if ( v24[106] < 0 )
              v4 = (Scaleform::GFx::InteractiveObject *)v24;
            Scaleform::GFx::AS2::Value::SetAsCharacter(fn->Result, v4);
          }
        }
        if ( v24 )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v24);
      }
      if ( v33 )
        Scaleform::RefCountImpl::Release(v33);
      goto LABEL_37;
    }
    v15 = Scaleform::GFx::DisplayObject::GetName(vfptr, &v48);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &vfptr->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie() failed - \"%s\" is not a movieclip.",
      v15->pNode->pData,
      result.pNode->pData);
    pNode = v48.pNode;
    v14 = v48.pNode->RefCount-- == 1;
    if ( v14 )
      goto LABEL_14;
  }
LABEL_37:
  if ( presBindData.pResource.pObject )
    Scaleform::GFx::Resource::Release(presBindData.pResource.pObject);
  v28 = result.pNode;
  v14 = result.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
}

// File Line: 2289
// RVA: 0x6AE390
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteAttachBitmap(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rsi
  Scaleform::GFx::DisplayObjContainer *vfptr; // rsi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v7; // r9
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rbx
  Scaleform::GFx::ImageResource *v10; // r14
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rax
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value *v14; // rax
  bool v15; // r8
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  Scaleform::GFx::AS2::MovieRoot *pObject; // r15
  Scaleform::GFx::MovieDefImpl *ImageMovieDef; // rax
  Scaleform::GFx::MovieDefImpl *v19; // r14
  Scaleform::GFx::Sprite *Sprite; // r15
  __int128 *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  bool v23; // zf
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::CharPosInfo pos; // [rsp+50h] [rbp-B0h] BYREF
  __int128 v30[4]; // [rsp+C0h] [rbp-40h] BYREF
  Scaleform::Render::RenderBuffer *v31; // [rsp+100h] [rbp+0h]
  int v32; // [rsp+108h] [rbp+8h]
  int v33; // [rsp+10Ch] [rbp+Ch]
  int v34; // [rsp+110h] [rbp+10h]
  __int64 v35; // [rsp+118h] [rbp+18h]
  int v36; // [rsp+120h] [rbp+20h]
  __int16 v37; // [rsp+124h] [rbp+24h]
  __int64 v38; // [rsp+130h] [rbp+30h]
  Scaleform::Render::Cxform v39; // [rsp+140h] [rbp+40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+1B0h] [rbp+B0h] BYREF
  Scaleform::GFx::AS2::Object *v41; // [rsp+1B8h] [rbp+B8h]
  Scaleform::GFx::MovieDefImpl *v42; // [rsp+1C0h] [rbp+C0h]
  Scaleform::GFx::Sprite *v43; // [rsp+1C8h] [rbp+C8h]

  v38 = -2i64;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::DisplayObjContainer *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = (Scaleform::GFx::DisplayObjContainer *)fn->Env->Target;
  }
  if ( !vfptr || fn->NArgs < 2 || Scaleform::GFx::DisplayObjectBase::GetVersion(vfptr) < 8 )
    return;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v7 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v7 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v8 = Scaleform::GFx::AS2::Value::ToObject(v7, Env);
  v9 = v8;
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
  v41 = v8;
  if ( v8
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v8->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v8->Scaleform::GFx::AS2::ObjectInterface) == 26 )
  {
    v10 = (Scaleform::GFx::ImageResource *)v9[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr;
    if ( v10 )
    {
      v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      v13 = (int)Scaleform::GFx::AS2::Value::ToNumber(v12, fn->Env) + 0x4000;
      pos.ColorTransform = Scaleform::Render::Cxform::Identity;
      pos.Matrix_1 = Scaleform::Render::Matrix2x4<float>::Identity;
      pos.pFilters.pObject = 0i64;
      pos.Ratio = 0.0;
      *(_WORD *)&pos.BlendMode = 256;
      *(_DWORD *)&pos.ClipDepth = 786432;
      pos.Depth = v13;
      pos.CharacterId.Id = 1;
      pos.ClassName = 0i64;
      if ( v13 > 0x7EFFFFFD )
      {
        Name = Scaleform::GFx::DisplayObject::GetName(vfptr, &result);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          &vfptr->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
          "%s.attachBitmap() failed - depth (%d) must be >= 0",
          Name->pNode->pData,
          (unsigned int)pos.Depth);
        pNode = result.pNode;
        v23 = result.pNode->RefCount-- == 1;
        if ( v23 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
      else
      {
        if ( fn->NArgs < 4 )
        {
          v15 = 0;
        }
        else
        {
          v14 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
          v15 = Scaleform::GFx::AS2::Value::ToBool(v14, fn->Env);
        }
        pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
        pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovieImpl->pASMovieRoot.pObject;
        ImageMovieDef = Scaleform::GFx::MovieImpl::CreateImageMovieDef(pMovieImpl, v10, v15, &customCaption, 0i64);
        v19 = ImageMovieDef;
        v42 = ImageMovieDef;
        if ( ImageMovieDef )
        {
          Scaleform::GFx::MovieDataDef::LoadTaskData::SetExtMovieDef(
            ImageMovieDef->pBindData.pObject->pDataDef.pObject->pData.pObject,
            (Scaleform::GFx::MovieDef *)v9[1].pRCC);
          LODWORD(result.pNode) = 65537;
          Sprite = Scaleform::GFx::AS2::MovieRoot::CreateSprite(
                     pObject,
                     v19->pBindData.pObject->pDataDef.pObject,
                     v19,
                     vfptr,
                     (Scaleform::GFx::ResourceId)&result,
                     1);
          v43 = Sprite;
          if ( Sprite )
          {
            Scaleform::Render::Cxform::Cxform(&v39);
            v30[0] = *v21;
            v30[1] = v21[1];
            v30[2] = _xmm;
            v30[3] = (__int128)_xmm;
            v31 = 0i64;
            v37 = 256;
            v32 = 0;
            v36 = 0x40000;
            v33 = 1;
            v34 = 1;
            v35 = 0i64;
            result.pNode = *(Scaleform::GFx::ASStringNode **)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
            ++result.pNode->RefCount;
            Scaleform::GFx::InteractiveObject::AddToPlayList(Sprite);
            Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList(Sprite);
            ((void (__fastcall *)(Scaleform::GFx::Sprite *, __int128 *, Scaleform::GFx::ASString *, _QWORD, _QWORD, int, _DWORD, _QWORD, _QWORD))Sprite->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[118].__vecDelDtor)(
              Sprite,
              v30,
              &result,
              0i64,
              0i64,
              1,
              0,
              0i64,
              0i64);
            Scaleform::GFx::DisplayObjContainer::ReplaceDisplayObject(vfptr, &pos, Sprite, &result);
            vfptr->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
              vfptr,
              0);
            v22 = result.pNode;
            v23 = result.pNode->RefCount-- == 1;
            if ( v23 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v22);
            if ( v31 )
              Scaleform::RefCountImpl::Release(v31);
          }
          if ( Sprite )
            Scaleform::RefCountNTSImpl::Release(Sprite);
        }
        if ( v19 )
          Scaleform::GFx::Resource::Release(v19);
      }
      if ( pos.pFilters.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pos.pFilters.pObject);
      goto LABEL_38;
    }
    v11 = Scaleform::GFx::DisplayObject::GetName(vfptr, &result);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &vfptr->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachBitmap() failed - no image set in BitmapData.",
      v11->pNode->pData);
  }
  else
  {
    v26 = Scaleform::GFx::DisplayObject::GetName(vfptr, &result);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &vfptr->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachBitmap() failed - the argument is not a BitmapData.",
      v26->pNode->pData);
  }
  v27 = result.pNode;
  v23 = result.pNode->RefCount-- == 1;
  if ( v23 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
LABEL_38:
  if ( v9 )
  {
    RefCount = v9->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v9->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
    }
  }
}

// File Line: 2374
// RVA: 0x6AEE60
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteCreateEmptyMovieClip(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rsi
  Scaleform::GFx::InteractiveObject *vfptr; // rbx
  unsigned int v6; // r9d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v8; // r10
  unsigned int v9; // eax
  Scaleform::GFx::AS2::Value *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  __int64 v12; // rax
  char *v13; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Cxform v16[2]; // [rsp+60h] [rbp-29h] BYREF
  Scaleform::Render::RenderBuffer *v17; // [rsp+A0h] [rbp+17h]
  int v18; // [rsp+A8h] [rbp+1Fh]
  unsigned int v19; // [rsp+ACh] [rbp+23h]
  int v20; // [rsp+B0h] [rbp+27h]
  __int64 v21; // [rsp+B8h] [rbp+2Fh]
  int v22; // [rsp+C0h] [rbp+37h]
  __int16 v23; // [rsp+C4h] [rbp+3Bh]
  Scaleform::GFx::ASString result; // [rsp+F0h] [rbp+67h] BYREF
  __int64 v25; // [rsp+F8h] [rbp+6Fh]

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  v4 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr && fn->NArgs >= 2 )
  {
    v6 = fn->FirstArgBottomIndex - 1;
    Env = fn->Env;
    v8 = 0i64;
    if ( v6 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
             + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v8 = &Env->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v9 = (int)Scaleform::GFx::AS2::Value::ToNumber(v8, Env) + 0x4000;
    v16[0] = Scaleform::Render::Cxform::Identity;
    v16[1] = (Scaleform::Render::Cxform)Scaleform::Render::Matrix2x4<float>::Identity;
    v17 = 0i64;
    v18 = 0;
    v23 = 256;
    v22 = 786432;
    v19 = v9;
    v20 = 65537;
    v21 = 0i64;
    if ( v9 <= 0x7EFFFFFD )
    {
      v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v11 = Scaleform::GFx::AS2::Value::ToString(v10, &result, fn->Env, -1);
      v12 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, _QWORD, int, int, _QWORD, _QWORD))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[118].__vecDelDtor)(
              vfptr,
              v16,
              v11,
              0i64,
              0i64,
              -1,
              1,
              0i64,
              0i64);
      v13 = (char *)v12;
      if ( v12 )
        ++*(_DWORD *)(v12 + 8);
      v25 = v12;
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v13 )
      {
        (*(void (__fastcall **)(char *, _QWORD))(*(_QWORD *)v13 + 424i64))(v13, 0i64);
        if ( v13[106] < 0 )
          v4 = (Scaleform::GFx::InteractiveObject *)v13;
        Scaleform::GFx::AS2::Value::SetAsCharacter(fn->Result, v4);
      }
      if ( v13 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v13);
    }
    if ( v17 )
      Scaleform::RefCountImpl::Release(v17);
  }
}

// File Line: 2402
// RVA: 0x6AF070
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteCreateTextField(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  __int64 *v4; // rsi
  Scaleform::GFx::InteractiveObject *vfptr; // rbx
  unsigned int v6; // r9d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v8; // r10
  unsigned int v9; // eax
  Scaleform::GFx::AS2::Value *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v12; // r10
  __int64 v13; // rax
  char *v14; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::InteractiveObject *v17; // r15
  char *v18; // rcx
  __int64 v19; // rbx
  Scaleform::GFx::AS2::Value *v20; // rax
  __int64 v21; // rbx
  Scaleform::GFx::AS2::Value *v22; // rax
  __int64 v23; // rbx
  Scaleform::GFx::AS2::Value *v24; // rax
  __int64 v25; // rbx
  Scaleform::GFx::AS2::Value *v26; // rax
  __int64 v27; // [rsp+28h] [rbp-49h]
  Scaleform::Render::Cxform v28[2]; // [rsp+38h] [rbp-39h] BYREF
  Scaleform::Render::RenderBuffer *v29; // [rsp+78h] [rbp+7h]
  int v30; // [rsp+80h] [rbp+Fh]
  unsigned int v31; // [rsp+84h] [rbp+13h]
  int v32; // [rsp+88h] [rbp+17h]
  __int64 v33; // [rsp+90h] [rbp+1Fh]
  int v34; // [rsp+98h] [rbp+27h]
  __int16 v35; // [rsp+9Ch] [rbp+2Bh]
  Scaleform::GFx::ASString result; // [rsp+D8h] [rbp+67h] BYREF
  __int64 v37; // [rsp+E0h] [rbp+6Fh]

  HIDWORD(v27) = -1;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  v4 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr && fn->NArgs >= 6 )
  {
    v6 = fn->FirstArgBottomIndex - 1;
    Env = fn->Env;
    v8 = 0i64;
    if ( v6 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
             + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v8 = &Env->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v9 = (int)Scaleform::GFx::AS2::Value::ToNumber(v8, Env) + 0x4000;
    v28[0] = Scaleform::Render::Cxform::Identity;
    v28[1] = (Scaleform::Render::Cxform)Scaleform::Render::Matrix2x4<float>::Identity;
    v29 = 0i64;
    v30 = 0;
    v35 = 256;
    v34 = 786432;
    v31 = v9;
    v32 = 65538;
    v33 = 0i64;
    if ( v9 <= 0x7EFFFFFD )
    {
      v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v11 = Scaleform::GFx::AS2::Value::ToString(v10, &result, fn->Env, -1);
      v12 = vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
      *(_OWORD *)&v28[0].M[0][0] = 0ui64;
      LODWORD(v27) = -1;
      v13 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, _QWORD, __int64, int))v12[118].__vecDelDtor)(
              vfptr,
              v28,
              v11,
              0i64,
              0i64,
              v27,
              1);
      v14 = (char *)v13;
      if ( v13 )
        ++*(_DWORD *)(v13 + 8);
      v37 = v13;
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v14 )
      {
        (*(void (__fastcall **)(char *, _QWORD))(*(_QWORD *)v14 + 424i64))(v14, 0i64);
        v17 = 0i64;
        if ( v14[106] < 0 )
          v17 = (Scaleform::GFx::InteractiveObject *)v14;
        if ( v17 )
        {
          v18 = (char *)v17 + 4 * (unsigned __int8)v17->AvmObjOffset;
          v4 = (__int64 *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v18 + 8i64))(v18);
        }
        v19 = *v4;
        v20 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        (*(void (__fastcall **)(__int64 *, _QWORD, Scaleform::GFx::AS2::Value *, _QWORD))(v19 + 272))(
          v4,
          0i64,
          v20,
          0i64);
        v21 = *v4;
        v22 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
        (*(void (__fastcall **)(__int64 *, __int64, Scaleform::GFx::AS2::Value *))(v21 + 272))(v4, 1i64, v22);
        v23 = *v4;
        v24 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
        (*(void (__fastcall **)(__int64 *, __int64, Scaleform::GFx::AS2::Value *))(v23 + 272))(v4, 8i64, v24);
        v25 = *v4;
        v26 = Scaleform::GFx::AS2::FnCall::Arg(fn, 5);
        (*(void (__fastcall **)(__int64 *, __int64, Scaleform::GFx::AS2::Value *))(v25 + 272))(v4, 9i64, v26);
        Scaleform::GFx::AS2::Value::SetAsCharacter(fn->Result, v17);
      }
      if ( v14 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v14);
    }
    if ( v29 )
      Scaleform::RefCountImpl::Release(v29);
  }
}

// File Line: 2436
// RVA: 0x6AEDD0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteRemoveMovieClip(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rbx
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    if ( vfptr->Depth >= 0x4000 )
    {
      Scaleform::GFx::InteractiveObject::RemoveDisplayObject(vfptr);
    }
    else
    {
      Name = Scaleform::GFx::DisplayObject::GetName(vfptr, &result);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &vfptr->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.removeMovieClip() failed - depth must be >= 0",
        Name->pNode->pData);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 2451
// RVA: 0x6AF920
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteSetMask(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rsi
  Scaleform::GFx::InteractiveObject *vfptr; // rbx
  Scaleform::GFx::AS2::Environment *Env; // r10
  unsigned __int64 FirstArgBottomIndex; // r11
  Scaleform::GFx::AS2::Value *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // r9
  Scaleform::GFx::InteractiveObject *v10; // rax
  Scaleform::GFx::DisplayObject *v11; // rdx

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  v4 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr && fn->NArgs >= 1 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v8 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v8 = &Env->Stack.Pages.Data.Data[(unsigned __int64)(unsigned int)FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    if ( v8->T.Type == 1 )
      goto LABEL_17;
    v9 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToCharacter(v9, fn->Env);
    if ( !v10 )
    {
LABEL_17:
      v11 = 0i64;
    }
    else
    {
      if ( (v10->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
        v4 = v10;
      v11 = v4;
    }
    Scaleform::GFx::DisplayObject::SetMask(vfptr, v11, 1);
  }
}

// File Line: 2479
// RVA: 0x6ACCF0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetBounds(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rsi
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  __int64 v7; // rdx
  Scaleform::GFx::CharacterHandle *v8; // rcx
  Scaleform::GFx::DisplayObject *v9; // rax
  Scaleform::GFx::InteractiveObject *v10; // rcx
  Scaleform::GFx::DisplayObjectBase *v11; // rax
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  Scaleform::Render::Rect<float> *v16; // rax
  Scaleform::GFx::AS2::Object *v17; // rax
  Scaleform::GFx::AS2::Object *v18; // rax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rsi
  unsigned int RefCount; // eax
  Scaleform::Render::Rect<float> pr; // [rsp+28h] [rbp-49h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+38h] [rbp-39h] BYREF
  Scaleform::Render::Matrix2x4<float> v23; // [rsp+58h] [rbp-19h] BYREF
  __int128 v24[5]; // [rsp+78h] [rbp+7h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+D8h] [rbp+67h] BYREF
  Scaleform::GFx::AS2::Object *vars0; // [rsp+E0h] [rbp+6Fh]

  ThisPtr = fn->ThisPtr;
  v3 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    if ( fn->NArgs <= 0 )
    {
      v10 = vfptr;
    }
    else
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v7 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v7 = (__int64)&Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      if ( *(_BYTE *)v7 == 7
        && Env
        && (v8 = *(Scaleform::GFx::CharacterHandle **)(v7 + 8)) != 0i64
        && (v9 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v8, Env->Target->pASRoot->pMovieImpl)) != 0i64 )
      {
        v10 = 0i64;
        if ( SLOBYTE(v9->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
          v10 = (Scaleform::GFx::InteractiveObject *)v9;
      }
      else
      {
        v10 = 0i64;
      }
    }
    if ( v10 )
    {
      v11 = 0i64;
      if ( (v10->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
        v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    pr = 0i64;
    *(_OWORD *)&v23.M[0][0] = _xmm;
    *(__m128 *)&v23.M[1][0] = _xmm;
    if ( v11 )
    {
      if ( v11 != vfptr )
      {
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v11, &pmat);
        Scaleform::Render::Matrix2x4<float>::SetInverse(&v23, &pmat);
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(vfptr, &pmat);
        v12 = v23.M[0][0];
        v13 = v23.M[0][1];
        v14 = v23.M[1][0];
        v15 = v23.M[1][1];
        v23.M[0][0] = (float)(pmat.M[1][0] * v23.M[0][1]) + (float)(pmat.M[0][0] * v23.M[0][0]);
        v23.M[1][0] = (float)(pmat.M[1][0] * v23.M[1][1]) + (float)(pmat.M[0][0] * v23.M[1][0]);
        v23.M[0][1] = (float)(v12 * pmat.M[0][1]) + (float)(pmat.M[1][1] * v23.M[0][1]);
        v23.M[1][1] = (float)(v14 * pmat.M[0][1]) + (float)(pmat.M[1][1] * v23.M[1][1]);
        v23.M[1][2] = 0.0;
        v23.M[0][2] = 0.0;
        v23.M[0][3] = v23.M[0][3] + (float)((float)(v13 * pmat.M[1][3]) + (float)(v12 * pmat.M[0][3]));
        v23.M[1][3] = v23.M[1][3] + (float)((float)(v15 * pmat.M[1][3]) + (float)(v14 * pmat.M[0][3]));
      }
      v24[0] = _xmm;
      v24[1] = (__int128)_xmm;
      v16 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Matrix2x4<float> *, __int128 *))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[61].__vecDelDtor)(
                                                vfptr,
                                                &pmat,
                                                v24);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v23, &pr, v16);
    }
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v17 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64))pHeap->vfptr->Alloc)(
                                           v10,
                                           96i64);
    vars0 = v17;
    if ( v17 )
    {
      Scaleform::GFx::AS2::Object::Object(v17, fn->Env);
      v3 = v18;
    }
    vars0 = v3;
    p_StringContext = &fn->Env->StringContext;
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.x1 * 0.05;
    LOBYTE(pHeap) = 0;
    v3->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v3->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34],
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.x2 * 0.05;
    LOBYTE(pHeap) = 0;
    v3->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v3->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.y1 * 0.05;
    LOBYTE(pHeap) = 0;
    v3->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v3->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34].pMovieImpl,
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.y2 * 0.05;
    LOBYTE(pHeap) = 0;
    v3->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v3->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34].pASSupport,
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v3);
    RefCount = v3->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v3->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
    }
  }
}

// File Line: 2526
// RVA: 0x6AD160
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetRect(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rsi
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  __int64 v7; // rdx
  Scaleform::GFx::CharacterHandle *v8; // rcx
  Scaleform::GFx::DisplayObject *v9; // rax
  Scaleform::GFx::InteractiveObject *v10; // rcx
  Scaleform::GFx::DisplayObjectBase *v11; // rax
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  Scaleform::Render::Rect<float> *v16; // rax
  Scaleform::GFx::AS2::Object *v17; // rax
  Scaleform::GFx::AS2::Object *v18; // rax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rsi
  unsigned int RefCount; // eax
  Scaleform::Render::Rect<float> pmat_8; // [rsp+40h] [rbp-49h] BYREF
  __int128 pmat_24; // [rsp+50h] [rbp-39h] BYREF
  __m128 v23; // [rsp+60h] [rbp-29h]
  Scaleform::Render::Matrix2x4<float> v24; // [rsp+70h] [rbp-19h] BYREF
  _OWORD v25[4]; // [rsp+90h] [rbp+7h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+F0h] [rbp+67h] BYREF
  Scaleform::GFx::AS2::Object *v27; // [rsp+F8h] [rbp+6Fh]

  ThisPtr = fn->ThisPtr;
  v3 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    if ( fn->NArgs <= 0 )
    {
      v10 = vfptr;
    }
    else
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v7 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v7 = (__int64)&Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      if ( *(_BYTE *)v7 == 7
        && Env
        && (v8 = *(Scaleform::GFx::CharacterHandle **)(v7 + 8)) != 0i64
        && (v9 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v8, Env->Target->pASRoot->pMovieImpl)) != 0i64 )
      {
        v10 = 0i64;
        if ( SLOBYTE(v9->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
          v10 = (Scaleform::GFx::InteractiveObject *)v9;
      }
      else
      {
        v10 = 0i64;
      }
    }
    if ( v10 )
    {
      v11 = 0i64;
      if ( (v10->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
        v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    pmat_8 = 0i64;
    *(_OWORD *)&v24.M[0][0] = _xmm;
    *(__m128 *)&v24.M[1][0] = _xmm;
    if ( v11 )
    {
      if ( v11 != vfptr )
      {
        pmat_24 = _xmm;
        v23 = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v11, (Scaleform::Render::Matrix2x4<float> *)&pmat_24);
        Scaleform::Render::Matrix2x4<float>::SetInverse(&v24, (Scaleform::Render::Matrix2x4<float> *)&pmat_24);
        pmat_24 = _xmm;
        v23 = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(vfptr, (Scaleform::Render::Matrix2x4<float> *)&pmat_24);
        v12 = v24.M[0][0];
        v13 = v24.M[0][1];
        v14 = v24.M[1][0];
        v15 = v24.M[1][1];
        v24.M[0][0] = (float)(v23.m128_f32[0] * v24.M[0][1]) + (float)(*(float *)&pmat_24 * v24.M[0][0]);
        v24.M[1][0] = (float)(v23.m128_f32[0] * v24.M[1][1]) + (float)(*(float *)&pmat_24 * v24.M[1][0]);
        v24.M[0][1] = (float)(v12 * *((float *)&pmat_24 + 1)) + (float)(v23.m128_f32[1] * v24.M[0][1]);
        v24.M[1][1] = (float)(v14 * *((float *)&pmat_24 + 1)) + (float)(v23.m128_f32[1] * v24.M[1][1]);
        v24.M[1][2] = 0.0;
        v24.M[0][2] = 0.0;
        v24.M[0][3] = v24.M[0][3] + (float)((float)(v13 * v23.m128_f32[3]) + (float)(v12 * *((float *)&pmat_24 + 3)));
        v24.M[1][3] = v24.M[1][3] + (float)((float)(v15 * v23.m128_f32[3]) + (float)(v14 * *((float *)&pmat_24 + 3)));
      }
      v25[0] = _xmm;
      v25[1] = _xmm;
      v16 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int128 *, _OWORD *))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[62].__vecDelDtor)(
                                                vfptr,
                                                &pmat_24,
                                                v25);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v24, &pmat_8, v16);
    }
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v17 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64))pHeap->vfptr->Alloc)(
                                           v10,
                                           96i64);
    v27 = v17;
    if ( v17 )
    {
      Scaleform::GFx::AS2::Object::Object(v17, fn->Env);
      v3 = v18;
    }
    v27 = v3;
    p_StringContext = &fn->Env->StringContext;
    LOBYTE(pmat_24) = 3;
    *((double *)&pmat_24 + 1) = pmat_8.x1 * 0.05;
    LOBYTE(pHeap) = 0;
    v3->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v3->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34],
      (Scaleform::GFx::AS2::Value *)&pmat_24,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    if ( (unsigned __int8)pmat_24 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat_24);
    LOBYTE(pmat_24) = 3;
    *((double *)&pmat_24 + 1) = pmat_8.x2 * 0.05;
    LOBYTE(pHeap) = 0;
    v3->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v3->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
      (Scaleform::GFx::AS2::Value *)&pmat_24,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    if ( (unsigned __int8)pmat_24 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat_24);
    LOBYTE(pmat_24) = 3;
    *((double *)&pmat_24 + 1) = pmat_8.y1 * 0.05;
    LOBYTE(pHeap) = 0;
    v3->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v3->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34].pMovieImpl,
      (Scaleform::GFx::AS2::Value *)&pmat_24,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    if ( (unsigned __int8)pmat_24 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat_24);
    LOBYTE(pmat_24) = 3;
    *((double *)&pmat_24 + 1) = pmat_8.y2 * 0.05;
    LOBYTE(pHeap) = 0;
    v3->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v3->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[34].pASSupport,
      (Scaleform::GFx::AS2::Value *)&pmat_24,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    if ( (unsigned __int8)pmat_24 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat_24);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v3);
    RefCount = v3->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v3->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
    }
  }
}

// File Line: 2567
// RVA: 0x6AD5D0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLocalToGlobal(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rsi
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // r14
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::ObjectInterface *v9; // rax
  Scaleform::GFx::AS2::ObjectInterface *v10; // rbx
  float v11; // xmm6_4
  float v12; // xmm2_4
  Scaleform::Render::Point3<float> ptIn; // [rsp+20h] [rbp-41h] BYREF
  Scaleform::GFx::AS2::Value v14; // [rsp+30h] [rbp-31h] BYREF
  Scaleform::GFx::AS2::Value v15; // [rsp+50h] [rbp-11h] BYREF
  Scaleform::GFx::AS2::Value v16; // [rsp+70h] [rbp+Fh] BYREF
  char v17; // [rsp+C8h] [rbp+67h] BYREF
  Scaleform::Render::Point<float> result; // [rsp+D0h] [rbp+6Fh] BYREF

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  v4 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr && fn->NArgs >= 1 )
  {
    Env = fn->Env;
    p_StringContext = &Env->StringContext;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, Env);
    v10 = v9;
    if ( v9 )
    {
      v15.T.Type = 0;
      v14.T.Type = 0;
      v9->vfptr->GetMemberRaw(
        v9,
        p_StringContext,
        (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
        &v15);
      v10->vfptr->GetMemberRaw(
        v10,
        p_StringContext,
        (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
        &v14);
      if ( (unsigned __int8)(v15.T.Type - 3) <= 1u && (unsigned __int8)(v14.T.Type - 3) <= 1u )
      {
        v11 = Scaleform::GFx::AS2::Value::ToNumber(&v14, fn->Env);
        v12 = Scaleform::GFx::AS2::Value::ToNumber(&v15, fn->Env);
        ptIn.x = v12 * 20.0;
        ptIn.y = v11 * 20.0;
        ptIn.z = 0.0;
        Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(vfptr, &result, &ptIn);
        v16.T.Type = 3;
        v16.NV.NumberValue = result.x * 0.05;
        v17 = 0;
        v10->vfptr->SetMemberRaw(
          v10,
          p_StringContext,
          (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
          &v16,
          (Scaleform::GFx::AS2::PropFlags *)&v17);
        if ( v16.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v16);
        v16.T.Type = 3;
        v16.NV.NumberValue = result.y * 0.05;
        v17 = 0;
        v10->vfptr->SetMemberRaw(
          v10,
          p_StringContext,
          (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
          &v16,
          (Scaleform::GFx::AS2::PropFlags *)&v17);
        if ( v16.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v16);
      }
      if ( v14.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v14);
      if ( v15.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v15);
    }
  }
}

// File Line: 2593
// RVA: 0x6AD860
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGlobalToLocal(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rsi
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // r14
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::ObjectInterface *v9; // rax
  Scaleform::GFx::AS2::ObjectInterface *v10; // rbx
  float v11; // xmm6_4
  float v12; // xmm1_4
  Scaleform::Render::Point<float> *v13; // rax
  float y; // xmm0_4
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v15; // rax
  __int64 p_AVMVersion; // r8
  Scaleform::GFx::AS2::Value v17; // [rsp+20h] [rbp-31h] BYREF
  Scaleform::GFx::AS2::Value v18; // [rsp+40h] [rbp-11h] BYREF
  Scaleform::GFx::AS2::Value v19; // [rsp+60h] [rbp+Fh] BYREF
  Scaleform::Render::Point<float> result; // [rsp+B8h] [rbp+67h] BYREF
  Scaleform::Render::Point<float> ptIn; // [rsp+C0h] [rbp+6Fh] BYREF

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  v4 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr && fn->NArgs >= 1 )
  {
    Env = fn->Env;
    p_StringContext = &Env->StringContext;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, Env);
    v10 = v9;
    if ( v9 )
    {
      v18.T.Type = 0;
      v17.T.Type = 0;
      v9->vfptr->GetMemberRaw(
        v9,
        p_StringContext,
        (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
        &v18);
      v10->vfptr->GetMemberRaw(
        v10,
        p_StringContext,
        (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion,
        &v17);
      if ( (unsigned __int8)(v18.T.Type - 3) <= 1u && (unsigned __int8)(v17.T.Type - 3) <= 1u )
      {
        v11 = Scaleform::GFx::AS2::Value::ToNumber(&v17, fn->Env);
        v12 = Scaleform::GFx::AS2::Value::ToNumber(&v18, fn->Env);
        ptIn.x = v12 * 20.0;
        ptIn.y = v11 * 20.0;
        v13 = Scaleform::GFx::DisplayObjectBase::GlobalToLocal(vfptr, &result, &ptIn);
        y = v13->y;
        ptIn.x = v13->x;
        ptIn.y = y;
        v19.T.Type = 3;
        v19.NV.NumberValue = ptIn.x * 0.05;
        LOBYTE(result.x) = 0;
        v10->vfptr->SetMemberRaw(
          v10,
          p_StringContext,
          (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport,
          &v19,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        if ( v19.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v19);
        v19.T.Type = 3;
        v19.NV.NumberValue = ptIn.y * 0.05;
        LOBYTE(result.x) = 0;
        v15 = v10->vfptr;
        p_AVMVersion = (__int64)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion;
        *(_QWORD *)&v17.T.Type = &result;
        ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, __int64, Scaleform::GFx::AS2::Value *))v15->SetMemberRaw)(
          v10,
          p_StringContext,
          p_AVMVersion,
          &v19);
        if ( v19.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v19);
      }
      if ( v17.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v17);
      if ( v18.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v18);
    }
  }
}

// File Line: 2621
// RVA: 0x6ADAF0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteHitTest(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // r14
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::InteractiveObject *vfptr; // r14
  Scaleform::GFx::AS2::Value *v5; // rbx
  int NArgs; // eax
  unsigned __int8 v7; // r15
  unsigned __int64 v8; // r8
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v10; // r9
  float v11; // xmm9_4
  unsigned int FirstArgBottomIndex; // r8d
  Scaleform::GFx::AS2::Environment *v13; // rdx
  float v14; // xmm8_4
  float v15; // xmm8_4
  float v16; // xmm9_4
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::GFx::AS2::Value *v18; // rax
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdi
  float v20; // xmm9_4
  char v21; // di
  float v22; // xmm2_4
  float v23; // xmm1_4
  Scaleform::GFx::AS2::Value *v24; // rbx
  Scaleform::GFx::AS2::Value *v25; // rcx
  Scaleform::GFx::AS2::Environment *v26; // rax
  Scaleform::GFx::DisplayObject *v27; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Matrix2x4<float> m; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::Render::Matrix2x4<float> v31[2]; // [rsp+60h] [rbp-A0h] BYREF
  _BYTE Dst[48]; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::Render::Rect<float> r; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::Render::Matrix3x4<float> pmat; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::Render::Rect<float> v35; // [rsp+110h] [rbp+10h] BYREF
  __int64 v36; // [rsp+120h] [rbp+20h]
  Scaleform::GFx::ASString result; // [rsp+1A0h] [rbp+A0h] BYREF
  Scaleform::Render::Point<float> ptOut; // [rsp+1A8h] [rbp+A8h] BYREF

  v36 = -2i64;
  ThisPtr = fn->ThisPtr;
  v3 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    v5 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v5);
    v5->T.Type = 2;
    v5->V.BooleanValue = 0;
    *(_OWORD *)Dst = _xmm;
    *(__m128 *)&Dst[16] = _xmm;
    ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Rect<float> *, _BYTE *))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[61].__vecDelDtor)(
      vfptr,
      &r,
      Dst);
    if ( r.x2 != r.x1 || r.y2 != r.y1 )
    {
      NArgs = fn->NArgs;
      if ( NArgs >= 2 )
      {
        v7 = 0;
        v8 = (unsigned int)(fn->FirstArgBottomIndex - 1);
        Env = fn->Env;
        v10 = 0i64;
        if ( (unsigned int)v8 <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                               + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
          v10 = &Env->Stack.Pages.Data.Data[v8 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
        v11 = Scaleform::GFx::AS2::Value::ToNumber(v10, Env);
        FirstArgBottomIndex = fn->FirstArgBottomIndex;
        v13 = fn->Env;
        if ( FirstArgBottomIndex <= 32 * (LODWORD(v13->Stack.Pages.Data.Size) - 1)
                                  + (unsigned int)(v13->Stack.pCurrent - v13->Stack.pPageStart) )
          v3 = &v13->Stack.Pages.Data.Data[(unsigned __int64)FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
        v14 = Scaleform::GFx::AS2::Value::ToNumber(v3, v13);
        v15 = v14 * 20.0;
        v16 = v11 * 20.0;
        if ( fn->NArgs >= 3 )
        {
          v17 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
          v7 = Scaleform::GFx::AS2::Value::ToBool(v17, fn->Env);
        }
        if ( fn->NArgs >= 4 )
        {
          v18 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
          v7 |= Scaleform::GFx::AS2::Value::ToBool(v18, fn->Env) ? 2 : 0;
        }
        pMovieImpl = vfptr->pASRoot->pMovieImpl;
        if ( pMovieImpl && Scaleform::GFx::DisplayObjectBase::Is3D(vfptr, 1) )
        {
          v20 = (float)((float)((float)(v16 - (float)(pMovieImpl->ViewOffsetY * 20.0))
                              / (float)(pMovieImpl->VisibleFrameRect.y2 - pMovieImpl->VisibleFrameRect.y1))
                      * 2.0)
              - 1.0;
          pMovieImpl->ScreenToWorld.Sx = (float)((float)((float)(v15 - (float)(pMovieImpl->ViewOffsetX * 20.0))
                                                       / (float)(pMovieImpl->VisibleFrameRect.x2
                                                               - pMovieImpl->VisibleFrameRect.x1))
                                               * 2.0)
                                       - 1.0;
          LODWORD(pMovieImpl->ScreenToWorld.Sy) = LODWORD(v20) ^ _xmm[0];
          memset(Dst, 0, sizeof(Dst));
          *(_DWORD *)Dst = 1065353216;
          *(_DWORD *)&Dst[20] = 1065353216;
          *(_DWORD *)&Dst[40] = 1065353216;
          memset(v31, 0, sizeof(v31));
          v31[0].M[0][0] = 1.0;
          v31[0].M[1][1] = 1.0;
          v31[1].M[0][2] = 1.0;
          v31[1].M[1][3] = 1.0;
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Matrix2x4<float> *, _QWORD))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[6].__vecDelDtor)(
                 vfptr,
                 v31,
                 0i64) )
          {
            *(Scaleform::Render::Matrix2x4<float> *)&pMovieImpl->ScreenToWorld.MatProj.M[0][0] = v31[0];
            *(Scaleform::Render::Matrix2x4<float> *)&pMovieImpl->ScreenToWorld.MatProj.M[2][0] = v31[1];
          }
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, _BYTE *, _QWORD))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[9].__vecDelDtor)(
                 vfptr,
                 Dst,
                 0i64) )
          {
            *(_OWORD *)&pMovieImpl->ScreenToWorld.MatView.M[0][0] = *(_OWORD *)Dst;
            *(_OWORD *)&pMovieImpl->ScreenToWorld.MatView.M[1][0] = *(_OWORD *)&Dst[16];
            pMovieImpl->ScreenToWorld.MatView.M[2][0] = *(float *)&Dst[32];
            pMovieImpl->ScreenToWorld.MatView.M[2][1] = *(float *)&Dst[36];
            pMovieImpl->ScreenToWorld.MatView.M[2][2] = *(float *)&Dst[40];
            pMovieImpl->ScreenToWorld.MatView.M[2][3] = *(float *)&Dst[44];
          }
          memset(&pmat, 0, sizeof(pmat));
          pmat.M[0][0] = 1.0;
          pmat.M[1][1] = 1.0;
          pmat.M[2][2] = 1.0;
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(vfptr, &pmat);
          pMovieImpl->ScreenToWorld.MatWorld = pmat;
          Scaleform::Render::ScreenToWorld::GetWorldPoint(&pMovieImpl->ScreenToWorld, &ptOut);
          v21 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Point<float> *, _QWORD))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
                  vfptr,
                  &ptOut,
                  v7);
          goto LABEL_57;
        }
        *(_OWORD *)&m.M[0][0] = _xmm;
        *(__m128 *)&m.M[1][0] = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(vfptr, &m);
        v31[0] = m;
        Scaleform::Render::Matrix2x4<float>::SetInverse(v31, &m);
        v22 = (float)((float)(v31[0].M[0][1] * v16) + (float)(v31[0].M[0][0] * v15)) + v31[0].M[0][3];
        *(float *)&result.pNode = v22;
        v23 = (float)((float)(v31[0].M[1][1] * v16) + (float)(v31[0].M[1][0] * v15)) + v31[0].M[1][3];
        *((float *)&result.pNode + 1) = v23;
        if ( (vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 1) != 0 )
          goto LABEL_26;
        if ( v22 > r.x2 || v22 < r.x1 || v23 > r.y2 || v23 < r.y1 )
        {
          v24 = fn->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v24);
          v24->V.BooleanValue = 0;
        }
        else
        {
          if ( (v7 & 1) != 0 )
          {
LABEL_26:
            v21 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::ASString *, _QWORD))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
                    vfptr,
                    &result,
                    v7);
LABEL_57:
            v24 = fn->Result;
            Scaleform::GFx::AS2::Value::DropRefs(v24);
            v24->V.BooleanValue = v21;
            goto LABEL_58;
          }
          v24 = fn->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v24);
          v24->V.BooleanValue = 1;
        }
LABEL_58:
        v24->T.Type = 2;
        return;
      }
      if ( NArgs == 1 )
      {
        v25 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        if ( v25->T.Type == 7 )
        {
          v3 = (Scaleform::GFx::AS2::Value *)Scaleform::GFx::AS2::Value::ToCharacter(v25, fn->Env);
        }
        else
        {
          Scaleform::GFx::AS2::Value::ToString(v25, &result, fn->Env, -1);
          LOBYTE(pmat.M[0][0]) = 0;
          if ( Scaleform::GFx::AS2::Environment::GetVariable(
                 fn->Env,
                 &result,
                 (Scaleform::GFx::AS2::Value *)&pmat,
                 0i64,
                 0i64,
                 0i64,
                 0) )
          {
            v26 = fn->Env;
            if ( LOBYTE(pmat.M[0][0]) == 7 )
            {
              if ( v26 )
              {
                if ( *(_QWORD *)&pmat.M[0][2] )
                {
                  v27 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                          *(Scaleform::GFx::CharacterHandle **)&pmat.M[0][2],
                          v26->Target->pASRoot->pMovieImpl);
                  if ( v27 )
                  {
                    if ( SLOBYTE(v27->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
                      v3 = (Scaleform::GFx::AS2::Value *)v27;
                  }
                }
              }
            }
          }
          if ( LOBYTE(pmat.M[0][0]) >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
          pNode = result.pNode;
          if ( result.pNode->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
        if ( v3 )
        {
          *(_OWORD *)Dst = _xmm;
          *(__m128 *)&Dst[16] = _xmm;
          (*(void (__fastcall **)(Scaleform::GFx::AS2::Value *, Scaleform::Render::Rect<float> *, _BYTE *))(*(_QWORD *)&v3->T.Type + 488i64))(
            v3,
            &v35,
            Dst);
          if ( v35.x2 != v35.x1 || v35.y2 != v35.y1 )
          {
            *(_OWORD *)Dst = _xmm;
            *(__m128 *)&Dst[16] = _xmm;
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(vfptr, (Scaleform::Render::Matrix2x4<float> *)Dst);
            Scaleform::Render::Matrix2x4<float>::EncloseTransform(
              (Scaleform::Render::Matrix2x4<float> *)Dst,
              (Scaleform::Render::Rect<float> *)&m,
              &r);
            *(_OWORD *)Dst = _xmm;
            *(__m128 *)&Dst[16] = _xmm;
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
              (Scaleform::GFx::DisplayObjectBase *)v3,
              (Scaleform::Render::Matrix2x4<float> *)Dst);
            Scaleform::Render::Matrix2x4<float>::EncloseTransform(
              (Scaleform::Render::Matrix2x4<float> *)Dst,
              (Scaleform::Render::Rect<float> *)v31,
              &v35);
            v21 = m.M[0][3] >= v31[0].M[0][1]
               && v31[0].M[0][3] >= m.M[0][1]
               && v31[0].M[0][2] >= m.M[0][0]
               && m.M[0][2] >= v31[0].M[0][0];
            goto LABEL_57;
          }
        }
      }
    }
  }
}

// File Line: 2725
// RVA: 0x6AB8E0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteSwapDepths(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // r14
  Scaleform::GFx::InteractiveObject *v2; // rsi
  Scaleform::GFx::InteractiveObject *vfptr; // r14
  unsigned int FirstArgBottomIndex; // edx
  Scaleform::GFx::InteractiveObject *pParent; // r12
  Scaleform::GFx::AS2::Environment *Env; // r15
  Scaleform::GFx::AS2::Value *v8; // rbx
  Scaleform::GFx::DisplayObjectBase *v9; // rcx
  unsigned int Depth; // edi
  Scaleform::GFx::DisplayObjectBase *Target; // rdi
  Scaleform::GFx::InteractiveObject *TargetByValue; // rax
  Scaleform::GFx::AS2::Environment *v13; // rbx
  int v14; // ebx
  unsigned int frame; // eax

  ThisPtr = fn->ThisPtr;
  v2 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr)
       - 2 > 3 )
      vfptr = 0i64;
    else
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( !vfptr || fn->NArgs < 1 )
    return;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  pParent = vfptr->pParent;
  Env = fn->Env;
  v8 = 0i64;
  if ( FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v8 = &Env->Stack.Pages.Data.Data[(unsigned __int64)FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v9 = 0i64;
  if ( (vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
    v9 = vfptr;
  if ( (unsigned __int8)(v8->T.Type - 3) <= 1u )
  {
    Depth = (int)Scaleform::GFx::AS2::Value::ToNumber(v8, Env) + 0x4000;
    if ( Depth > 0x7EFFFFFD )
      return;
    goto LABEL_22;
  }
  if ( v9 )
  {
    Target = Env->Target;
    *((_BYTE *)Env + 382) &= ~2u;
    Env->Target = (Scaleform::GFx::InteractiveObject *)v9;
    Env->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(v9);
    TargetByValue = Scaleform::GFx::AS2::Environment::FindTargetByValue(fn->Env, v8);
    v13 = fn->Env;
    *((_BYTE *)v13 + 382) &= ~2u;
    v13->Target = (Scaleform::GFx::InteractiveObject *)Target;
    v2 = TargetByValue;
    v13->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(Target);
  }
  else
  {
    v2 = Scaleform::GFx::AS2::Environment::FindTargetByValue(Env, v8);
  }
  if ( v2 && v2 != vfptr && pParent == v2->pParent )
  {
    Depth = v2->Depth;
LABEL_22:
    if ( vfptr->Depth >= 0 )
    {
      vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
        vfptr,
        0);
      if ( pParent )
      {
        v14 = vfptr->Depth;
        frame = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[107].__vecDelDtor)(pParent);
        if ( Scaleform::GFx::DisplayList::SwapDepths(
               (Scaleform::GFx::DisplayList *)&pParent[1],
               pParent,
               v14,
               Depth,
               frame) )
        {
          _((AMD_HD3D *)pParent);
          if ( v2 )
            v2->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
              v2,
              0);
        }
      }
    }
  }
}

// File Line: 2787
// RVA: 0x6AF330
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetNextHighestDepth(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rcx
  int LargestDepthInUse; // eax
  Scaleform::GFx::AS2::Value *Result; // rbx
  int v6; // esi

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    LargestDepthInUse = Scaleform::GFx::DisplayList::GetLargestDepthInUse((Scaleform::GFx::DisplayList *)&vfptr[1]);
    Result = fn->Result;
    v6 = LargestDepthInUse - 0x3FFF;
    if ( LargestDepthInUse - 0x3FFF < 0 )
      v6 = 0;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    Result->NV.Int32Value = v6;
    Result->T.Type = 4;
  }
}

// File Line: 2798
// RVA: 0x6AF3C0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetInstanceAtDepth(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rsi
  Scaleform::GFx::DisplayObjContainer *vfptr; // rbx
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v8; // r9
  long double v9; // xmm0_8
  Scaleform::GFx::DisplayObjectBase *CharacterAtDepth; // rax

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  v4 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::DisplayObjContainer *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = (Scaleform::GFx::DisplayObjContainer *)fn->Env->Target;
  }
  if ( vfptr && fn->NArgs >= 1 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v8 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToNumber(v8, Env);
    CharacterAtDepth = Scaleform::GFx::DisplayObjContainer::GetCharacterAtDepth(vfptr, (int)v9 + 0x4000);
    if ( CharacterAtDepth )
    {
      if ( SLOBYTE(CharacterAtDepth->Flags) < 0 )
        v4 = (Scaleform::GFx::InteractiveObject *)CharacterAtDepth;
      Scaleform::GFx::AS2::Value::SetAsCharacter(fn->Result, v4);
    }
  }
}

// File Line: 2820
// RVA: 0x6AF4B0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetTextSnapshot(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
    (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr);
}

// File Line: 2835
// RVA: 0x6AF4D0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetSWFVersion(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rcx
  unsigned int Version; // eax
  Scaleform::GFx::AS2::Value *Result; // rbx
  int v6; // esi

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    Version = Scaleform::GFx::DisplayObjectBase::GetVersion(vfptr);
    Result = fn->Result;
    v6 = Version;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    Result->NV.Int32Value = v6;
    Result->T.Type = 4;
  }
}

// File Line: 2843
// RVA: 0x6AF550
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteStartDrag(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::Sprite *vfptr; // rdi
  bool v5; // bp
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::Environment *v9; // rdx
  int v10; // r8d
  unsigned int v11; // r8d
  Scaleform::GFx::AS2::Value *v12; // r9
  long double v13; // xmm0_8
  Scaleform::GFx::AS2::Environment *v14; // rdx
  float v15; // xmm8_4
  unsigned __int64 v16; // r8
  float v17; // xmm8_4
  Scaleform::GFx::AS2::Value *v18; // r9
  long double v19; // xmm0_8
  Scaleform::GFx::AS2::Environment *v20; // rdx
  float v21; // xmm6_4
  unsigned __int64 v22; // r8
  float v23; // xmm6_4
  Scaleform::GFx::AS2::Value *v24; // r9
  long double v25; // xmm0_8
  Scaleform::GFx::AS2::Environment *v26; // rdx
  float v27; // xmm7_4
  unsigned __int64 v28; // r8
  float v29; // xmm7_4
  float v30; // xmm1_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  unsigned int Flags; // ecx
  bool v35; // dl
  int v36; // eax
  Scaleform::GFx::MovieImpl::DragState st; // [rsp+20h] [rbp-78h] BYREF

  ThisPtr = fn->ThisPtr;
  v2 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::Sprite *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = (Scaleform::GFx::Sprite *)fn->Env->Target;
  }
  if ( vfptr )
  {
    v5 = 0;
    memset(&st, 0, 18);
    memset(&st.BoundLT, 0, 24);
    st.MouseIndex = -1;
    if ( fn->NArgs > 0 )
    {
      Env = fn->Env;
      FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
      v8 = 0i64;
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
      v5 = Scaleform::GFx::AS2::Value::ToBool(v8, Env);
      if ( fn->NArgs > 4 )
      {
        v9 = fn->Env;
        v10 = fn->FirstArgBottomIndex;
        st.Bound = 1;
        v11 = v10 - 1;
        v12 = 0i64;
        if ( v11 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                  + (unsigned int)(v9->Stack.pCurrent - v9->Stack.pPageStart) )
          v12 = &v9->Stack.Pages.Data.Data[(unsigned __int64)v11 >> 5]->Values[v11 & 0x1F];
        v13 = Scaleform::GFx::AS2::Value::ToNumber(v12, v9);
        v14 = fn->Env;
        v15 = v13;
        v16 = (unsigned int)(fn->FirstArgBottomIndex - 2);
        v17 = v15 * 20.0;
        v18 = 0i64;
        if ( (unsigned int)v16 <= 32 * (LODWORD(v14->Stack.Pages.Data.Size) - 1)
                                + (unsigned int)(v14->Stack.pCurrent - v14->Stack.pPageStart) )
          v18 = &v14->Stack.Pages.Data.Data[v16 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 2) & 0x1F];
        v19 = Scaleform::GFx::AS2::Value::ToNumber(v18, v14);
        v20 = fn->Env;
        v21 = v19;
        v22 = (unsigned int)(fn->FirstArgBottomIndex - 3);
        v23 = v21 * 20.0;
        v24 = 0i64;
        if ( (unsigned int)v22 <= 32 * (LODWORD(v20->Stack.Pages.Data.Size) - 1)
                                + (unsigned int)(v20->Stack.pCurrent - v20->Stack.pPageStart) )
          v24 = &v20->Stack.Pages.Data.Data[v22 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 3) & 0x1F];
        v25 = Scaleform::GFx::AS2::Value::ToNumber(v24, v20);
        v26 = fn->Env;
        v27 = v25;
        v28 = (unsigned int)(fn->FirstArgBottomIndex - 4);
        v29 = v27 * 20.0;
        if ( (unsigned int)v28 <= 32 * (LODWORD(v26->Stack.Pages.Data.Size) - 1)
                                + (unsigned int)(v26->Stack.pCurrent - v26->Stack.pPageStart) )
          v2 = &v26->Stack.Pages.Data.Data[v28 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 4) & 0x1F];
        v30 = Scaleform::GFx::AS2::Value::ToNumber(v2, v26);
        v31 = v30 * 20.0;
        if ( v17 > v29 )
        {
          v32 = v17;
          v17 = v29;
          v29 = v32;
        }
        if ( v23 > v31 )
        {
          v33 = v23;
          v23 = v31;
          v31 = v33;
        }
        st.BoundLT.x = v17;
        st.BoundLT.y = v23;
        st.BoundRB.x = v29;
        st.BoundRB.y = v31;
      }
    }
    st.pCharacter = vfptr;
    Scaleform::GFx::MovieImpl::DragState::InitCenterDelta(&st, v5, 0);
    Scaleform::GFx::MovieImpl::SetDragState(vfptr->pASRoot->pMovieImpl, &st);
    Flags = vfptr->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags;
    v35 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
    v36 = Scaleform::GFx::Sprite::CheckAdvanceStatus(vfptr, v35);
    if ( v36 == -1 )
    {
      vfptr->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= 0x400000u;
    }
    else if ( v36 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(vfptr);
    }
  }
}

// File Line: 2880
// RVA: 0x6AF880
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteStopDrag(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::Sprite *vfptr; // rbx
  unsigned int Flags; // ecx
  bool v4; // dl
  int v5; // eax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::Sprite *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = (Scaleform::GFx::Sprite *)fn->Env->Target;
  }
  if ( vfptr )
  {
    Scaleform::GFx::MovieImpl::StopDrag(vfptr->pASRoot->pMovieImpl, 0);
    Flags = vfptr->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags;
    v4 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
    v5 = Scaleform::GFx::Sprite::CheckAdvanceStatus(vfptr, v4);
    if ( v5 == -1 )
    {
      vfptr->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= 0x400000u;
    }
    else if ( v5 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(vfptr);
    }
  }
}

// File Line: 2891
// RVA: 0x6AFA50
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLoadMovie(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rsi
  int NArgs; // eax
  Scaleform::GFx::LoadQueueEntry::LoadMethod v5; // ebx
  unsigned int v6; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  const char *pData; // rdx
  __int64 v12; // rcx
  char v13; // al
  __int64 v14; // rax
  char v15; // cl
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *v19; // r8
  Scaleform::GFx::AS2::Value *v20; // r10
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASString v22; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v23; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    NArgs = fn->NArgs;
    if ( NArgs > 0 )
    {
      v5 = LM_None;
      if ( NArgs > 1 )
      {
        v6 = fn->FirstArgBottomIndex - 1;
        Env = fn->Env;
        v8 = 0i64;
        if ( v6 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                 + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
          v8 = &Env->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
        v9 = Scaleform::GFx::AS2::Value::ToString(v8, &result, Env, -1);
        Scaleform::GFx::ASString::ToLower(v9, &v22);
        pNode = result.pNode;
        v16 = result.pNode->RefCount-- == 1;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        pData = v22.pNode->pData;
        v12 = 0i64;
        while ( 1 )
        {
          v13 = pData[v12++];
          if ( v13 != aGet[v12 - 1] )
            break;
          if ( v12 == 4 )
          {
            v5 = LM_Get;
            goto LABEL_23;
          }
        }
        v14 = 0i64;
        while ( 1 )
        {
          v15 = pData[v14++];
          v16 = v15 == aPost[v14 - 1];
          if ( v15 != aPost[v14 - 1] )
            break;
          if ( v14 == 5 )
          {
            v16 = v15 == aPost[4];
            break;
          }
        }
        if ( v16 )
          v5 = LM_Post;
LABEL_23:
        v17 = v22.pNode;
        v16 = v22.pNode->RefCount-- == 1;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      }
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      v19 = fn->Env;
      v20 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)v19->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(v19->Stack.pCurrent - v19->Stack.pPageStart) )
        v20 = &v19->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v20, &v23, v19, -1);
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
        (Scaleform::GFx::AS2::MovieRoot *)vfptr->pASRoot,
        vfptr,
        v23.pNode->pData,
        v5,
        0i64);
      v21 = v23.pNode;
      v16 = v23.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    }
  }
}

// File Line: 2916
// RVA: 0x6AFC20
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteUnloadMovie(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rcx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
    Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
      (Scaleform::GFx::AS2::MovieRoot *)vfptr->pASRoot,
      vfptr,
      &customCaption,
      LM_None,
      0i64);
}

// File Line: 2925
// RVA: 0x6AFDF0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLoadVariables(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::InteractiveObject *vfptr; // rbp
  int NArgs; // eax
  Scaleform::GFx::LoadQueueEntry::LoadMethod v6; // ebx
  unsigned int v7; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  const char *pData; // rdx
  __int64 v13; // rcx
  char v14; // al
  __int64 v15; // rax
  char v16; // cl
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *v20; // r8
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASString v22; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v23; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h] BYREF

  ThisPtr = fn->ThisPtr;
  v3 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    NArgs = fn->NArgs;
    if ( NArgs > 0 )
    {
      v6 = LM_None;
      if ( NArgs > 1 )
      {
        v7 = fn->FirstArgBottomIndex - 1;
        Env = fn->Env;
        v9 = 0i64;
        if ( v7 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                 + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
          v9 = &Env->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
        v10 = Scaleform::GFx::AS2::Value::ToString(v9, &result, Env, -1);
        Scaleform::GFx::ASString::ToLower(v10, &v22);
        pNode = result.pNode;
        v17 = result.pNode->RefCount-- == 1;
        if ( v17 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        pData = v22.pNode->pData;
        v13 = 0i64;
        while ( 1 )
        {
          v14 = pData[v13++];
          if ( v14 != aGet[v13 - 1] )
            break;
          if ( v13 == 4 )
          {
            v6 = LM_Get;
            goto LABEL_23;
          }
        }
        v15 = 0i64;
        while ( 1 )
        {
          v16 = pData[v15++];
          v17 = v16 == aPost[v15 - 1];
          if ( v16 != aPost[v15 - 1] )
            break;
          if ( v15 == 5 )
          {
            v17 = v16 == aPost[4];
            break;
          }
        }
        if ( v17 )
          v6 = LM_Post;
LABEL_23:
        v18 = v22.pNode;
        v17 = v22.pNode->RefCount-- == 1;
        if ( v17 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      v20 = fn->Env;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)v20->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(v20->Stack.pCurrent - v20->Stack.pPageStart) )
        v3 = &v20->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v3, &v23, v20, -1);
      Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        (Scaleform::GFx::AS2::MovieRoot *)vfptr->pASRoot,
        vfptr,
        v23.pNode->pData,
        v6);
      v21 = v23.pNode;
      v17 = v23.pNode->RefCount-- == 1;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    }
  }
}

// File Line: 2952
// RVA: 0x71A210
void __fastcall Scaleform::GFx::AS2::AvmSprite::SetNoLine(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::DrawingContext *v2; // rsi
  Scaleform::GFx::DrawingContext *v3; // rbx

  v2 = (Scaleform::GFx::DrawingContext *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[83].__vecDelDtor)(this->pDispObj);
  if ( !Scaleform::GFx::DrawingContext::NoLine(v2) )
  {
    v3 = (Scaleform::GFx::DrawingContext *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[83].__vecDelDtor)(this->pDispObj);
    _((AMD_HD3D *)this->pDispObj);
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
    Scaleform::GFx::DrawingContext::AcquirePath(v3, 0);
    Scaleform::GFx::DrawingContext::SetNoLine(v2);
  }
}

// File Line: 2963
// RVA: 0x71A1A0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SetNoFill(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::DrawingContext *v2; // rdi
  Scaleform::GFx::DrawingContext *v3; // rbx

  v2 = (Scaleform::GFx::DrawingContext *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[83].__vecDelDtor)(this->pDispObj);
  v3 = (Scaleform::GFx::DrawingContext *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[83].__vecDelDtor)(this->pDispObj);
  _((AMD_HD3D *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(v3, 1);
  Scaleform::GFx::DrawingContext::SetNoFill(v2);
}

// File Line: 2999
// RVA: 0x6DB540
void __fastcall Scaleform::GFx::AS2::AvmSprite::BeginFill(Scaleform::GFx::AS2::AvmSprite *this, unsigned int rgba)
{
  Scaleform::GFx::DrawingContext *v4; // rbx

  v4 = (Scaleform::GFx::DrawingContext *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[83].__vecDelDtor)(this->pDispObj);
  _((AMD_HD3D *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(v4, 1);
  Scaleform::GFx::DrawingContext::BeginSolidFill(v4, rgba);
}

// File Line: 3008
// RVA: 0x6DB4C0
void __fastcall Scaleform::GFx::AS2::AvmSprite::BeginBitmapFill(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::FillType fillType,
        Scaleform::GFx::ImageResource *pimageRes,
        Scaleform::Render::Matrix2x4<float> *mtx)
{
  Scaleform::GFx::DrawingContext *v8; // rdi

  v8 = (Scaleform::GFx::DrawingContext *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[83].__vecDelDtor)(this->pDispObj);
  _((AMD_HD3D *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(v8, 1);
  Scaleform::GFx::DrawingContext::BeginBitmapFill(v8, fillType, pimageRes, mtx);
}

// File Line: 3020
// RVA: 0x7030D0
void __fastcall Scaleform::GFx::AS2::AvmSprite::MoveTo(Scaleform::GFx::AS2::AvmSprite *this, float x, float y)
{
  Scaleform::GFx::DrawingContext *v4; // rbx

  v4 = (Scaleform::GFx::DrawingContext *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[83].__vecDelDtor)(this->pDispObj);
  _((AMD_HD3D *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(v4, 0);
  Scaleform::GFx::DrawingContext::MoveTo(v4, x * 20.0, y * 20.0);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}

// File Line: 3031
// RVA: 0x7011F0
void __fastcall Scaleform::GFx::AS2::AvmSprite::LineTo(Scaleform::GFx::AS2::AvmSprite *this, float x, float y)
{
  Scaleform::GFx::DrawingContext *v4; // rax

  v4 = (Scaleform::GFx::DrawingContext *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[83].__vecDelDtor)(this->pDispObj);
  Scaleform::GFx::DrawingContext::LineTo(v4, x * 20.0, y * 20.0);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}

// File Line: 3042
// RVA: 0x6E1940
void __fastcall Scaleform::GFx::AS2::AvmSprite::CurveTo(
        Scaleform::GFx::AS2::AvmSprite *this,
        float cx,
        float cy,
        float ax,
        float ay)
{
  Scaleform::GFx::DrawingContext *v6; // rax

  v6 = (Scaleform::GFx::DrawingContext *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[83].__vecDelDtor)(this->pDispObj);
  Scaleform::GFx::DrawingContext::CurveTo(v6, cx * 20.0, cy * 20.0, ax * 20.0, ay * 20.0);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}

// File Line: 3061
// RVA: 0x6B0100
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteClear(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rbx
  Scaleform::GFx::DrawingContext *v3; // rax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    if ( ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[83].__vecDelDtor)(vfptr) )
    {
      v3 = (Scaleform::GFx::DrawingContext *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[83].__vecDelDtor)(vfptr);
      Scaleform::GFx::DrawingContext::Clear(v3);
    }
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(vfptr);
    _((AMD_HD3D *)vfptr);
  }
}

// File Line: 3074
// RVA: 0x6B0310
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteBeginFill(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::AS2::Value *v2; // rdi
  Scaleform::GFx::InteractiveObject *vfptr; // rbx
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v7; // r9
  unsigned int v8; // ebp
  Scaleform::GFx::AS2::Environment *v9; // rdx
  unsigned __int64 v10; // r8
  int v11; // ebp
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm0_4

  ThisPtr = fn->ThisPtr;
  v2 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    if ( fn->NArgs > 0 )
    {
      Env = fn->Env;
      FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
      v7 = 0i64;
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v7 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToUInt32(v7, Env) | 0xFF000000;
      if ( fn->NArgs <= 1 )
        goto LABEL_19;
      v9 = fn->Env;
      v10 = (unsigned int)(fn->FirstArgBottomIndex - 1);
      if ( (unsigned int)v10 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)(v9->Stack.pCurrent - v9->Stack.pPageStart) )
        v2 = &v9->Stack.Pages.Data.Data[v10 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
      v11 = v8 & 0xFFFFFF;
      v12 = Scaleform::GFx::AS2::Value::ToNumber(v2, v9);
      v13 = (float)(v12 * 255.0) * 0.0099999998;
      if ( v13 >= 255.0 )
      {
        v13 = FLOAT_255_0;
      }
      else
      {
        v14 = 0.0;
        if ( v13 < 0.0 )
          goto LABEL_18;
      }
      v14 = v13;
LABEL_18:
      v8 = ((int)v14 << 24) | v11;
LABEL_19:
      Scaleform::GFx::AS2::AvmSprite::BeginFill(
        (Scaleform::GFx::AS2::AvmSprite *)((char *)vfptr + 4 * (unsigned __int8)vfptr->AvmObjOffset),
        v8);
      return;
    }
    Scaleform::GFx::AS2::AvmSprite::SetNoFill((Scaleform::GFx::AS2::AvmSprite *)((char *)vfptr
                                                                               + 4
                                                                               * (unsigned __int8)vfptr->AvmObjOffset));
  }
}

// File Line: 3097
// RVA: 0x71FD50
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteCreateGradient(
        Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::Render::ComplexFill *complexFill)
{
  int v3; // r14d
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v6; // r10
  unsigned int v7; // r9d
  Scaleform::GFx::AS2::Environment *v8; // rdx
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // r13
  unsigned int v12; // r9d
  Scaleform::GFx::AS2::Environment *v13; // rdx
  Scaleform::GFx::AS2::Value *v14; // r10
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Object *v16; // rbx
  unsigned int v17; // r9d
  Scaleform::GFx::AS2::Environment *v18; // rdx
  Scaleform::GFx::AS2::Value *v19; // r10
  Scaleform::GFx::AS2::Object *v20; // rax
  Scaleform::GFx::AS2::Object *v21; // r12
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pPrev; // rax
  Scaleform::GFx::AS2::Environment *v23; // rbx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rsi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v25; // rax
  Scaleform::GFx::AS2::ObjectInterface *v26; // rbx
  Scaleform::GFx::ASString *v27; // rax
  bool v28; // r15
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASString *v30; // rax
  const char *pData; // rdx
  __int64 v32; // rcx
  char v33; // al
  char v34; // r15
  Scaleform::GFx::ASStringNode *v35; // rcx
  float v36; // xmm9_4
  float v37; // xmm10_4
  float v38; // xmm6_4
  float v39; // xmm8_4
  float v40; // xmm11_4
  Scaleform::GFx::ASString *v41; // rax
  bool v42; // r14
  Scaleform::GFx::ASStringNode *v43; // rcx
  Scaleform::GFx::ASString *v44; // rax
  bool v45; // r14
  Scaleform::GFx::ASStringNode *v46; // rcx
  Scaleform::GFx::ASString *v47; // rax
  bool v48; // r14
  Scaleform::GFx::ASStringNode *v49; // rcx
  Scaleform::GFx::ASString *v50; // rax
  bool v51; // r14
  Scaleform::GFx::ASStringNode *v52; // rcx
  Scaleform::GFx::ASString *v53; // rax
  bool v54; // bl
  Scaleform::GFx::ASStringNode *v55; // rcx
  float v56; // xmm9_4
  float v57; // xmm10_4
  float v58; // xmm6_4
  float v59; // xmm8_4
  float v60; // xmm1_4
  Scaleform::GFx::ASString *v61; // rax
  bool v62; // r14
  Scaleform::GFx::ASStringNode *v63; // rcx
  float v64; // xmm1_4
  Scaleform::GFx::ASString *v65; // rax
  bool v66; // r14
  Scaleform::GFx::ASStringNode *v67; // rcx
  float v68; // xmm1_4
  Scaleform::GFx::ASString *v69; // rax
  bool v70; // r14
  Scaleform::GFx::ASStringNode *v71; // rcx
  float v72; // xmm1_4
  Scaleform::GFx::ASString *v73; // rax
  bool v74; // r14
  Scaleform::GFx::ASStringNode *v75; // rcx
  float v76; // xmm1_4
  Scaleform::GFx::ASString *v77; // rax
  bool v78; // r14
  Scaleform::GFx::ASStringNode *v79; // rcx
  float v80; // xmm1_4
  Scaleform::GFx::ASString *v81; // rax
  bool v82; // bl
  Scaleform::GFx::ASStringNode *v83; // rcx
  bool v84; // bl
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v85; // rax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v86; // rax
  Scaleform::GFx::ASString *v87; // rax
  Scaleform::GFx::ASStringNode *v88; // rcx
  Scaleform::GFx::ASStringNode *v89; // rcx
  __int64 v90; // rax
  char v91; // cl
  bool v92; // zf
  Scaleform::Render::GradientType v93; // r15d
  Scaleform::GFx::ASStringNode *v94; // rax
  __int64 v95; // rax
  __int64 v96; // rbx
  __int64 v97; // rsi
  Scaleform::Render::RenderBuffer *v98; // rcx
  unsigned int v99; // r14d
  __int64 v100; // rsi
  __int64 v101; // r15
  unsigned int v102; // ebx
  float v103; // xmm1_4
  float v104; // xmm1_4
  int v105; // ebx
  int v106; // ebx
  float v107; // xmm1_4
  __int64 v108; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-A0h] BYREF
  Scaleform::GFx::AS2::Value v111; // [rsp+40h] [rbp-80h] BYREF
  unsigned int v112; // [rsp+60h] [rbp-60h]
  Scaleform::GFx::AS2::Object *v113; // [rsp+68h] [rbp-58h]
  __int64 v114; // [rsp+70h] [rbp-50h]
  Scaleform::GFx::ASString v115; // [rsp+110h] [rbp+50h] BYREF
  __int64 v116; // [rsp+118h] [rbp+58h]
  Scaleform::GFx::ASString result; // [rsp+120h] [rbp+60h] BYREF
  Scaleform::GFx::ASString v118; // [rsp+128h] [rbp+68h] BYREF

  v114 = -2i64;
  v3 = 0;
  v112 = 0;
  if ( fn->NArgs > 0 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v6 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v6, &result, Env, -1);
    if ( fn->NArgs <= 1 )
      goto LABEL_115;
    v7 = fn->FirstArgBottomIndex - 1;
    v8 = fn->Env;
    v9 = 0i64;
    if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
             + (unsigned int)(v8->Stack.pCurrent - v8->Stack.pPageStart) )
      v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToObject(v9, v8);
    v11 = v10;
    if ( !v10
      || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v10->Scaleform::GFx::AS2::ObjectInterface) != 7
      || fn->NArgs <= 2 )
    {
      goto LABEL_115;
    }
    v12 = fn->FirstArgBottomIndex - 2;
    v13 = fn->Env;
    v14 = 0i64;
    if ( v12 <= 32 * ((unsigned int)v13->Stack.Pages.Data.Size - 1)
              + (unsigned int)(v13->Stack.pCurrent - v13->Stack.pPageStart) )
      v14 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
    v15 = Scaleform::GFx::AS2::Value::ToObject(v14, v13);
    v16 = v15;
    v113 = v15;
    if ( !v15
      || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v15->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v15->Scaleform::GFx::AS2::ObjectInterface) != 7
      || fn->NArgs <= 3 )
    {
      goto LABEL_115;
    }
    v17 = fn->FirstArgBottomIndex - 3;
    v18 = fn->Env;
    v19 = 0i64;
    if ( v17 <= 32 * ((unsigned int)v18->Stack.Pages.Data.Size - 1)
              + (unsigned int)(v18->Stack.pCurrent - v18->Stack.pPageStart) )
      v19 = &v18->Stack.Pages.Data.Data[v17 >> 5]->Values[v17 & 0x1F];
    v20 = Scaleform::GFx::AS2::Value::ToObject(v19, v18);
    v21 = v20;
    if ( !v20
      || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v20->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v20->Scaleform::GFx::AS2::ObjectInterface) != 7
      || fn->NArgs <= 4
      || (pPrev = v11[1].pPrev, (int)pPrev <= 0)
      || (_DWORD)pPrev != v16[1].RootIndex
      || (_DWORD)pPrev != v21[1].RootIndex )
    {
LABEL_115:
      pNode = result.pNode;
      v92 = result.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return;
    }
    *(_OWORD *)&m.M[0][0] = _xmm;
    *(__m128 *)&m.M[1][0] = _xmm;
    v111.T.Type = 0;
    v23 = fn->Env;
    p_StringContext = &v23->StringContext;
    v25 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
    v26 = &Scaleform::GFx::AS2::Value::ToObject(v25->Values, v23)->Scaleform::GFx::AS2::ObjectInterface;
    v27 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "matrixType");
    v28 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v27, &v111);
    v29 = v115.pNode;
    v92 = v115.pNode->RefCount-- == 1;
    if ( v92 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
    if ( v28 )
    {
      v30 = Scaleform::GFx::AS2::Value::ToString(&v111, &v118, fn->Env, -1);
      v3 = 1;
      v112 = 1;
      pData = v30->pNode->pData;
      v32 = 0i64;
      while ( 1 )
      {
        v33 = pData[v32++];
        if ( v33 != aBox_3[v32 - 1] )
          break;
        if ( v32 == 4 )
        {
          v34 = 1;
          goto LABEL_31;
        }
      }
    }
    v34 = 0;
LABEL_31:
    if ( (v3 & 1) != 0 )
    {
      v112 = v3 & 0xFFFFFFFE;
      v35 = v118.pNode;
      v92 = v118.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v35);
    }
    if ( v34 )
    {
      v36 = 0.0;
      v37 = 0.0;
      v38 = FLOAT_100_0;
      v39 = FLOAT_100_0;
      v40 = 0.0;
      v41 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "x");
      v42 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v41, &v111);
      v43 = v115.pNode;
      v92 = v115.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v43);
      if ( v42 )
        v36 = Scaleform::GFx::AS2::Value::ToNumber(&v111, fn->Env);
      v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "y");
      v45 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v44, &v111);
      v46 = v115.pNode;
      v92 = v115.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v46);
      if ( v45 )
        v37 = Scaleform::GFx::AS2::Value::ToNumber(&v111, fn->Env);
      v47 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "w");
      v48 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v47, &v111);
      v49 = v115.pNode;
      v92 = v115.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v49);
      if ( v48 )
        v38 = Scaleform::GFx::AS2::Value::ToNumber(&v111, fn->Env);
      v50 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "h");
      v51 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v50, &v111);
      v52 = v115.pNode;
      v92 = v115.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v52);
      if ( v51 )
        v39 = Scaleform::GFx::AS2::Value::ToNumber(&v111, fn->Env);
      v53 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "r");
      v54 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v53, &v111);
      v55 = v115.pNode;
      v92 = v115.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v55);
      if ( v54 )
        v40 = Scaleform::GFx::AS2::Value::ToNumber(&v111, fn->Env);
      v56 = v36 + (float)(v38 * 0.5);
      v57 = v37 + (float)(v39 * 0.5);
      v58 = v38 * 0.00061035156;
      v59 = v39 * 0.00061035156;
      Scaleform::Render::Matrix2x4<float>::AppendRotation(&m, v40);
      m.M[0][0] = m.M[0][0] * v58;
      m.M[0][1] = m.M[0][1] * v58;
      m.M[0][2] = m.M[0][2] * v58;
      m.M[1][0] = m.M[1][0] * v59;
      m.M[1][1] = m.M[1][1] * v59;
      m.M[1][2] = m.M[1][2] * v59;
      m.M[0][3] = (float)(m.M[0][3] * v58) + v56;
      v60 = (float)(m.M[1][3] * v59) + v57;
    }
    else
    {
      v61 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "a");
      v62 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v61, &v111);
      v63 = v115.pNode;
      v92 = v115.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v63);
      if ( v62 )
      {
        v64 = Scaleform::GFx::AS2::Value::ToNumber(&v111, fn->Env);
        m.M[0][0] = v64 * 0.00061035156;
      }
      v65 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "d");
      v66 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v65, &v111);
      v67 = v115.pNode;
      v92 = v115.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v67);
      if ( v66 )
      {
        v68 = Scaleform::GFx::AS2::Value::ToNumber(&v111, fn->Env);
        m.M[0][1] = v68 * 0.00061035156;
      }
      v69 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "g");
      v70 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v69, &v111);
      v71 = v115.pNode;
      v92 = v115.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v71);
      if ( v70 )
      {
        v72 = Scaleform::GFx::AS2::Value::ToNumber(&v111, fn->Env);
        m.M[0][3] = v72;
      }
      v73 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "b");
      v74 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v73, &v111);
      v75 = v115.pNode;
      v92 = v115.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v75);
      if ( v74 )
      {
        v76 = Scaleform::GFx::AS2::Value::ToNumber(&v111, fn->Env);
        m.M[1][0] = v76 * 0.00061035156;
      }
      v77 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "e");
      v78 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v77, &v111);
      v79 = v115.pNode;
      v92 = v115.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v79);
      if ( v78 )
      {
        v80 = Scaleform::GFx::AS2::Value::ToNumber(&v111, fn->Env);
        m.M[1][1] = v80 * 0.00061035156;
      }
      v81 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &v115, "h");
      v82 = v26->vfptr->GetMemberRaw(v26, p_StringContext, v81, &v111);
      v83 = v115.pNode;
      v92 = v115.pNode->RefCount-- == 1;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v83);
      if ( !v82 )
      {
LABEL_81:
        v84 = 0;
        if ( fn->NArgs > 5 )
        {
          v85 = Scaleform::GFx::AS2::FnCall::Arg(fn, 5);
          Scaleform::GFx::AS2::Value::ToString(v85->Values, &v118, fn->Env, -1);
          if ( fn->NArgs > 6 )
          {
            v86 = Scaleform::GFx::AS2::FnCall::Arg(fn, 6);
            v87 = Scaleform::GFx::AS2::Value::ToString(v86->Values, &v115, fn->Env, -1);
            v84 = strcmp(v87->pNode->pData, "linearRGB") == 0;
            v88 = v115.pNode;
            v92 = v115.pNode->RefCount-- == 1;
            if ( v92 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v88);
          }
          v89 = v118.pNode;
          v92 = v118.pNode->RefCount-- == 1;
          if ( v92 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v89);
        }
        v90 = 0i64;
        while ( 1 )
        {
          v91 = result.pNode->pData[v90++];
          v92 = v91 == aRadial[v90 - 1];
          if ( v91 != aRadial[v90 - 1] )
            break;
          if ( v90 == 7 )
          {
            v92 = v91 == aRadial[6];
            break;
          }
        }
        v93 = v92;
        LODWORD(v115.pNode) = v92;
        v94 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                Scaleform::Memory::pGlobalHeap,
                                                48i64);
        v118.pNode = v94;
        if ( v94 )
        {
          Scaleform::Render::GradientData::GradientData(
            (Scaleform::Render::GradientData *)v94,
            v93,
            v11[1].RootIndex,
            v84);
          v96 = v95;
        }
        else
        {
          v96 = 0i64;
        }
        v97 = v116;
        v98 = *(Scaleform::Render::RenderBuffer **)(v116 + 24);
        if ( v98 )
          Scaleform::RefCountImpl::Release(v98);
        *(_QWORD *)(v97 + 24) = v96;
        if ( v96 )
        {
          *(_DWORD *)(v96 + 32) = 0;
          v99 = 0;
          if ( (int)v11[1].RootIndex > 0 )
          {
            v100 = 0i64;
            v101 = v116;
            do
            {
              v102 = Scaleform::GFx::AS2::Value::ToUInt32(
                       (Scaleform::GFx::AS2::Value *)(&v11[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v100],
                       fn->Env) | 0xFF000000;
              v103 = Scaleform::GFx::AS2::Value::ToNumber(
                       (Scaleform::GFx::AS2::Value *)(&v113[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v100],
                       fn->Env);
              v104 = (float)(v103 * 255.0) * 0.0099999998;
              v105 = v102 & 0xFFFFFF;
              if ( v104 >= 255.0 )
              {
                v104 = FLOAT_255_0;
              }
              else if ( v104 < 0.0 )
              {
                v104 = 0.0;
              }
              v106 = ((int)v104 << 24) | v105;
              v107 = Scaleform::GFx::AS2::Value::ToNumber(
                       (Scaleform::GFx::AS2::Value *)(&v21[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v100],
                       fn->Env);
              if ( v107 >= 255.0 )
              {
                v107 = FLOAT_255_0;
              }
              else if ( v107 < 0.0 )
              {
                v107 = 0.0;
              }
              v108 = *(_QWORD *)(*(_QWORD *)(v101 + 24) + 24i64);
              *(_BYTE *)(v108 + 8i64 * v99) = (int)v107;
              *(_DWORD *)(v108 + 8i64 * v99++ + 4) = v106;
              ++v100;
            }
            while ( (signed int)v99 < (signed int)v11[1].RootIndex );
            v93 = (Scaleform::Render::GradientType)v115.pNode;
            v97 = v116;
          }
          m.M[0][3] = m.M[0][3] * 20.0;
          m.M[1][3] = m.M[1][3] * 20.0;
          *(_QWORD *)(v97 + 32) = 1065353216i64;
          *(_QWORD *)(v97 + 40) = 0i64;
          *(_DWORD *)(v97 + 48) = 0;
          *(_QWORD *)(v97 + 52) = 1065353216i64;
          *(_DWORD *)(v97 + 60) = 0;
          *(_QWORD *)(v97 + 32) = 939524096i64;
          *(_DWORD *)(v97 + 40) = 0;
          *(_QWORD *)(v97 + 44) = 1056964608i64;
          *(_QWORD *)(v97 + 52) = 939524096i64;
          if ( v93 )
            *(_DWORD *)(v97 + 60) = 1056964608;
          else
            *(_DWORD *)(v97 + 60) = 0;
          *(_OWORD *)&v111.T.Type = _xmm;
          *((__m128 *)&v111.NV + 1) = _xmm;
          Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)&v111, &m);
          Scaleform::Render::Matrix2x4<float>::Prepend(
            (Scaleform::Render::Matrix2x4<float> *)(v97 + 32),
            (Scaleform::Render::Matrix2x4<float> *)&v111);
        }
        if ( v111.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v111);
        goto LABEL_115;
      }
      v60 = Scaleform::GFx::AS2::Value::ToNumber(&v111, fn->Env);
    }
    m.M[1][3] = v60;
    goto LABEL_81;
  }
}

// File Line: 3261
// RVA: 0x6B06C0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteBeginGradientFill(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rdx
  char *v4; // rbx
  Scaleform::GFx::DrawingContext *v5; // rdi
  Scaleform::Render::ComplexFill *NewComplexFill; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    v4 = (char *)vfptr + 4 * (unsigned __int8)vfptr->AvmObjOffset;
    v5 = (Scaleform::GFx::DrawingContext *)(*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)v4 + 3) + 664i64))(*((_QWORD *)v4 + 3));
    _(*((AMD_HD3D **)v4 + 3));
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(*((Scaleform::GFx::DisplayObjectBase **)v4 + 3));
    Scaleform::GFx::DrawingContext::AcquirePath(v5, 1);
    NewComplexFill = Scaleform::GFx::DrawingContext::CreateNewComplexFill(v5);
    Scaleform::GFx::DrawingContext::BeginFill(v5);
    if ( NewComplexFill )
      Scaleform::GFx::AS2::AvmSprite::SpriteCreateGradient(fn, NewComplexFill);
  }
}

// File Line: 3271
// RVA: 0x6B0D10
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLineGradientStyle(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rdx
  char *v4; // rdi
  Scaleform::GFx::DrawingContext *v5; // rbx
  Scaleform::Render::ComplexFill *LineComplexFill; // rax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    v4 = (char *)vfptr + 4 * (unsigned __int8)vfptr->AvmObjOffset;
    v5 = (Scaleform::GFx::DrawingContext *)(*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)v4 + 3) + 664i64))(*((_QWORD *)v4 + 3));
    _(*((AMD_HD3D **)v4 + 3));
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(*((Scaleform::GFx::DisplayObjectBase **)v4 + 3));
    Scaleform::GFx::DrawingContext::AcquirePath(v5, 1);
    LineComplexFill = Scaleform::GFx::DrawingContext::CreateLineComplexFill(v5);
    if ( LineComplexFill )
      Scaleform::GFx::AS2::AvmSprite::SpriteCreateGradient(fn, LineComplexFill);
  }
}

// File Line: 3281
// RVA: 0x6B09B0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteBeginBitmapFill(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::AS2::Value *v3; // rbp
  Scaleform::GFx::InteractiveObject *vfptr; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  Scaleform::GFx::ImageResource *v9; // r14
  Scaleform::GFx::AS2::Value *v10; // rax
  bool v11; // bp
  Scaleform::GFx::AS2::Value *v12; // rax
  int v13; // edx
  unsigned int RefCount; // eax
  Scaleform::Render::Matrix2x4<float> mtx; // [rsp+30h] [rbp-38h] BYREF

  ThisPtr = fn->ThisPtr;
  v3 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr && fn->NArgs > 0 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v3 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v7 = Scaleform::GFx::AS2::Value::ToObject(v3, Env);
    v8 = v7;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    if ( !v7
      || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v7->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v7->Scaleform::GFx::AS2::ObjectInterface) != 26
      || (v9 = (Scaleform::GFx::ImageResource *)v8[3].vfptr) == 0i64 )
    {
      if ( !v8 )
        return;
      goto LABEL_23;
    }
    *(_OWORD *)&mtx.M[0][0] = _xmm;
    *(__m128 *)&mtx.M[1][0] = _xmm;
    if ( fn->NArgs >= 3 )
    {
      v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
      v11 = Scaleform::GFx::AS2::Value::ToBool(v10, fn->Env);
      if ( fn->NArgs > 3 )
      {
        v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
        if ( Scaleform::GFx::AS2::Value::ToBool(v12, fn->Env) )
        {
          v13 = 65 - v11;
LABEL_21:
          Scaleform::GFx::AS2::AvmSprite::BeginBitmapFill(
            (Scaleform::GFx::AS2::AvmSprite *)((char *)vfptr + 4 * (unsigned __int8)vfptr->AvmObjOffset),
            (Scaleform::GFx::FillType)v13,
            v9,
            &mtx);
LABEL_23:
          RefCount = v8->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v8->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
          }
          return;
        }
      }
      v13 = 67;
      if ( !v11 )
        goto LABEL_21;
    }
    v13 = 66;
    goto LABEL_21;
  }
}

// File Line: 3348
// RVA: 0x6B0F80
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteEndFill(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rcx
  char *v3; // rdi
  Scaleform::GFx::DrawingContext *v4; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    v3 = (char *)vfptr + 4 * (unsigned __int8)vfptr->AvmObjOffset;
    v4 = (Scaleform::GFx::DrawingContext *)(*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)v3 + 3) + 664i64))(*((_QWORD *)v3 + 3));
    _(*((AMD_HD3D **)v3 + 3));
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(*((Scaleform::GFx::DisplayObjectBase **)v3 + 3));
    Scaleform::GFx::DrawingContext::AcquirePath(v4, 1);
    Scaleform::GFx::DrawingContext::EndFill(v4);
  }
}

// File Line: 3356
// RVA: 0x6B11F0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLineStyle(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rdi
  unsigned int joins; // esi
  Scaleform::GFx::InteractiveObject *vfptr; // r14
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v7; // r9
  float v8; // xmm8_4
  unsigned int v9; // ebp
  bool v10; // r13
  unsigned int scaling; // r15d
  unsigned int caps; // r12d
  float miterLimit; // xmm6_4
  unsigned int v14; // r9d
  Scaleform::GFx::AS2::Environment *v15; // rdx
  Scaleform::GFx::AS2::Value *v16; // r10
  unsigned int v17; // r9d
  Scaleform::GFx::AS2::Environment *v18; // rdx
  Scaleform::GFx::AS2::Value *v19; // r10
  float v20; // xmm1_4
  float v21; // xmm1_4
  int v22; // ebp
  float v23; // xmm0_4
  Scaleform::GFx::AS2::Value *v24; // rax
  Scaleform::GFx::AS2::Value *v25; // rax
  const char *pData; // rdi
  __int64 v27; // rcx
  char v28; // al
  Scaleform::GFx::AS2::Value *v29; // rax
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::ASStringNode *v33; // rcx
  const char *v34; // rdx
  __int64 v35; // rcx
  char v36; // al
  __int64 v37; // rax
  char v38; // cl
  bool v39; // zf
  Scaleform::GFx::AS2::Value *v40; // rax
  Scaleform::GFx::ASString *v41; // rax
  Scaleform::GFx::ASStringNode *v42; // rdi
  Scaleform::GFx::ASStringNode *v43; // rcx
  Scaleform::GFx::ASStringNode *v44; // rcx
  const char *v45; // rdx
  __int64 v46; // rcx
  char v47; // al
  __int64 v48; // rax
  char v49; // cl
  bool v50; // zf
  Scaleform::GFx::AS2::Value *v51; // rax
  Scaleform::GFx::ASStringNode *v52; // rcx
  __int64 v53; // rcx
  Scaleform::GFx::DrawingContext *v54; // rax
  Scaleform::GFx::ASString result; // [rsp+C0h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v56; // [rsp+C8h] [rbp+10h] BYREF

  ThisPtr = fn->ThisPtr;
  joins = 0;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr )
  {
    if ( fn->NArgs > 0 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v7 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v7 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToNumber(v7, Env);
      v9 = -16777216;
      v10 = 0;
      scaling = 0;
      caps = 0;
      miterLimit = FLOAT_3_0;
      if ( fn->NArgs <= 1 )
        goto LABEL_68;
      v14 = fn->FirstArgBottomIndex - 1;
      v15 = fn->Env;
      v16 = 0i64;
      if ( v14 <= 32 * ((unsigned int)v15->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v15->Stack.pCurrent - v15->Stack.pPageStart) )
        v16 = &v15->Stack.Pages.Data.Data[v14 >> 5]->Values[v14 & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToUInt32(v16, v15) | 0xFF000000;
      if ( fn->NArgs <= 2 )
      {
LABEL_68:
        v53 = *(__int64 *)((char *)&vfptr->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr
                         + 4 * (unsigned __int8)vfptr->AvmObjOffset);
        v54 = (Scaleform::GFx::DrawingContext *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v53 + 664i64))(v53);
        Scaleform::GFx::DrawingContext::ChangeLineStyle(v54, v8 * 20.0, v9, v10, scaling, caps, joins, miterLimit);
        return;
      }
      v17 = fn->FirstArgBottomIndex - 2;
      v18 = fn->Env;
      v19 = 0i64;
      if ( v17 <= 32 * ((unsigned int)v18->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v18->Stack.pCurrent - v18->Stack.pPageStart) )
        v19 = &v18->Stack.Pages.Data.Data[v17 >> 5]->Values[v17 & 0x1F];
      v20 = Scaleform::GFx::AS2::Value::ToNumber(v19, v18);
      v21 = (float)(v20 * 255.0) * 0.0099999998;
      v22 = v9 & 0xFFFFFF;
      if ( v21 >= 255.0 )
      {
        v21 = FLOAT_255_0;
      }
      else
      {
        v23 = 0.0;
        if ( v21 < 0.0 )
          goto LABEL_21;
      }
      v23 = v21;
LABEL_21:
      v9 = ((int)v23 << 24) | v22;
      if ( fn->NArgs > 3 )
      {
        v24 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
        v10 = Scaleform::GFx::AS2::Value::ToBool(v24, fn->Env);
        if ( fn->NArgs > 4 )
        {
          v25 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
          Scaleform::GFx::AS2::Value::ToString(v25, &result, fn->Env, -1);
          pData = result.pNode->pData;
          v27 = 0i64;
          while ( 1 )
          {
            v28 = pData[v27++];
            if ( v28 != aNone[v27 - 1] )
              break;
            if ( v27 == 5 )
            {
              scaling = 6;
              goto LABEL_31;
            }
          }
          if ( !strcmp(result.pNode->pData, "vertical") )
          {
            scaling = 4;
          }
          else if ( !strcmp(pData, "horizontal") )
          {
            scaling = 2;
          }
LABEL_31:
          if ( fn->NArgs > 5 )
          {
            v29 = Scaleform::GFx::AS2::FnCall::Arg(fn, 5);
            v30 = Scaleform::GFx::AS2::Value::ToString(v29, &v56, fn->Env, -1);
            pNode = v30->pNode;
            ++v30->pNode->RefCount;
            v32 = result.pNode;
            v39 = result.pNode->RefCount-- == 1;
            if ( v39 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v32);
            result.pNode = pNode;
            v33 = v56.pNode;
            v39 = v56.pNode->RefCount-- == 1;
            if ( v39 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v33);
            v34 = result.pNode->pData;
            v35 = 0i64;
            while ( 1 )
            {
              v36 = v34[v35++];
              if ( v36 != aNone[v35 - 1] )
                break;
              if ( v35 == 5 )
              {
                caps = 320;
                goto LABEL_46;
              }
            }
            v37 = 0i64;
            while ( 1 )
            {
              v38 = v34[v37++];
              v39 = v38 == aSquare[v37 - 1];
              if ( v38 != aSquare[v37 - 1] )
                break;
              if ( v37 == 7 )
              {
                v39 = v38 == aSquare[6];
                break;
              }
            }
            if ( v39 )
              caps = 640;
LABEL_46:
            if ( fn->NArgs > 6 )
            {
              v40 = Scaleform::GFx::AS2::FnCall::Arg(fn, 6);
              v41 = Scaleform::GFx::AS2::Value::ToString(v40, &v56, fn->Env, -1);
              v42 = v41->pNode;
              ++v41->pNode->RefCount;
              v43 = result.pNode;
              v39 = result.pNode->RefCount-- == 1;
              if ( v39 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v43);
              result.pNode = v42;
              v44 = v56.pNode;
              v39 = v56.pNode->RefCount-- == 1;
              if ( v39 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v44);
              v45 = result.pNode->pData;
              v46 = 0i64;
              while ( 1 )
              {
                v47 = v45[v46++];
                if ( v47 != aMiter[v46 - 1] )
                  break;
                if ( v46 == 6 )
                {
                  joins = 32;
                  goto LABEL_61;
                }
              }
              v48 = 0i64;
              while ( 1 )
              {
                v49 = v45[v48++];
                v50 = v49 == aBevel[v48 - 1];
                if ( v49 != aBevel[v48 - 1] )
                  break;
                if ( v48 == 6 )
                {
                  v50 = v49 == aBevel[5];
                  break;
                }
              }
              if ( v50 )
                joins = 16;
LABEL_61:
              if ( fn->NArgs > 7 )
              {
                v51 = Scaleform::GFx::AS2::FnCall::Arg(fn, 7);
                miterLimit = Scaleform::GFx::AS2::Value::ToNumber(v51, fn->Env);
                if ( miterLimit >= 1.0 )
                {
                  if ( miterLimit > 255.0 )
                    miterLimit = FLOAT_255_0;
                }
                else
                {
                  miterLimit = *(float *)&FLOAT_1_0;
                }
              }
            }
          }
          v52 = result.pNode;
          v39 = result.pNode->RefCount-- == 1;
          if ( v39 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v52);
        }
      }
      goto LABEL_68;
    }
    Scaleform::GFx::AS2::AvmSprite::SetNoLine((Scaleform::GFx::AS2::AvmSprite *)((char *)vfptr
                                                                               + 4
                                                                               * (unsigned __int8)vfptr->AvmObjOffset));
  }
}

// File Line: 3425
// RVA: 0x6B1890
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteMoveTo(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rsi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v7; // r9
  long double v8; // xmm0_8
  Scaleform::GFx::AS2::Environment *v9; // rdx
  float v10; // xmm6_4
  unsigned __int64 v11; // r8
  float v12; // xmm2_4

  ThisPtr = fn->ThisPtr;
  v2 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr && fn->NArgs >= 2 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v7 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v7 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v8 = Scaleform::GFx::AS2::Value::ToNumber(v7, Env);
    v9 = fn->Env;
    v10 = v8;
    v11 = (unsigned int)(fn->FirstArgBottomIndex - 1);
    if ( (unsigned int)v11 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)(v9->Stack.pCurrent - v9->Stack.pPageStart) )
      v2 = &v9->Stack.Pages.Data.Data[v11 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
    v12 = Scaleform::GFx::AS2::Value::ToNumber(v2, v9);
    Scaleform::GFx::AS2::AvmSprite::MoveTo(
      (Scaleform::GFx::AS2::AvmSprite *)((char *)vfptr + 4 * (unsigned __int8)vfptr->AvmObjOffset),
      v10,
      v12);
  }
}

// File Line: 3438
// RVA: 0x6B1B70
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLineTo(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rsi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v7; // r9
  long double v8; // xmm0_8
  Scaleform::GFx::AS2::Environment *v9; // rdx
  float v10; // xmm6_4
  unsigned __int64 v11; // r8
  float v12; // xmm2_4

  ThisPtr = fn->ThisPtr;
  v2 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr && fn->NArgs >= 2 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v7 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v7 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v8 = Scaleform::GFx::AS2::Value::ToNumber(v7, Env);
    v9 = fn->Env;
    v10 = v8;
    v11 = (unsigned int)(fn->FirstArgBottomIndex - 1);
    if ( (unsigned int)v11 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)(v9->Stack.pCurrent - v9->Stack.pPageStart) )
      v2 = &v9->Stack.Pages.Data.Data[v11 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
    v12 = Scaleform::GFx::AS2::Value::ToNumber(v2, v9);
    Scaleform::GFx::AS2::AvmSprite::LineTo(
      (Scaleform::GFx::AS2::AvmSprite *)((char *)vfptr + 4 * (unsigned __int8)vfptr->AvmObjOffset),
      v10,
      v12);
  }
}

// File Line: 3451
// RVA: 0x6B1D30
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteCurveTo(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rsi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v7; // r9
  long double v8; // xmm0_8
  Scaleform::GFx::AS2::Environment *v9; // rdx
  float v10; // xmm8_4
  unsigned __int64 v11; // r8
  Scaleform::GFx::AS2::Value *v12; // r9
  long double v13; // xmm0_8
  Scaleform::GFx::AS2::Environment *v14; // rdx
  float v15; // xmm7_4
  unsigned __int64 v16; // r8
  Scaleform::GFx::AS2::Value *v17; // r9
  long double v18; // xmm0_8
  Scaleform::GFx::AS2::Environment *v19; // rdx
  float v20; // xmm6_4
  unsigned __int64 v21; // r8
  float ay; // xmm4_4

  ThisPtr = fn->ThisPtr;
  v2 = 0i64;
  if ( ThisPtr )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
    else
      vfptr = 0i64;
  }
  else
  {
    vfptr = fn->Env->Target;
  }
  if ( vfptr && fn->NArgs >= 4 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v7 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v7 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v8 = Scaleform::GFx::AS2::Value::ToNumber(v7, Env);
    v9 = fn->Env;
    v10 = v8;
    v11 = (unsigned int)(fn->FirstArgBottomIndex - 1);
    v12 = 0i64;
    if ( (unsigned int)v11 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)(v9->Stack.pCurrent - v9->Stack.pPageStart) )
      v12 = &v9->Stack.Pages.Data.Data[v11 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
    v13 = Scaleform::GFx::AS2::Value::ToNumber(v12, v9);
    v14 = fn->Env;
    v15 = v13;
    v16 = (unsigned int)(fn->FirstArgBottomIndex - 2);
    v17 = 0i64;
    if ( (unsigned int)v16 <= 32 * (LODWORD(v14->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)(v14->Stack.pCurrent - v14->Stack.pPageStart) )
      v17 = &v14->Stack.Pages.Data.Data[v16 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 2) & 0x1F];
    v18 = Scaleform::GFx::AS2::Value::ToNumber(v17, v14);
    v19 = fn->Env;
    v20 = v18;
    v21 = (unsigned int)(fn->FirstArgBottomIndex - 3);
    if ( (unsigned int)v21 <= 32 * (LODWORD(v19->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)(v19->Stack.pCurrent - v19->Stack.pPageStart) )
      v2 = &v19->Stack.Pages.Data.Data[v21 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 3) & 0x1F];
    ay = Scaleform::GFx::AS2::Value::ToNumber(v2, v19);
    Scaleform::GFx::AS2::AvmSprite::CurveTo(
      (Scaleform::GFx::AS2::AvmSprite *)((char *)vfptr + 4 * (unsigned __int8)vfptr->AvmObjOffset),
      v10,
      v15,
      v20,
      ay);
  }
}

// File Line: 3466
// RVA: 0x6D7D40
void __fastcall Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ActionBuffer *a,
        Scaleform::GFx::ActionPriority::Priority prio)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v6; // rbx
  Scaleform::GFx::InteractiveObject *pDispObj; // rdi
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::RefCountNTSImpl *v9; // rcx

  inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
               (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].RefCount,
               prio);
  v6 = inserted;
  if ( inserted )
  {
    pDispObj = this->pDispObj;
    inserted->Type = Entry_Buffer;
    if ( pDispObj )
      ++pDispObj->RefCount;
    pObject = inserted->pCharacter.pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    v6->pCharacter.pObject = pDispObj;
    if ( a )
      ++a->RefCount;
    v9 = v6->pActionBuffer.pObject;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    v6->pActionBuffer.pObject = a;
    v6->mEventId.Id = 0;
  }
}

// File Line: 3472
// RVA: 0x6E90D0
void __fastcall Scaleform::GFx::AS2::AvmSprite::FillTabableArray(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::InteractiveObject::FillTabableParams *params)
{
  __int64 v4; // rbp
  unsigned __int64 Size; // rbx
  Scaleform::GFx::ASString *ConstString; // rax
  char v7; // bl
  Scaleform::GFx::ASStringNode *v8; // rcx
  __int64 v10; // r14
  __int64 v11; // rbx
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *Array; // rdi
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v13; // rdx
  Scaleform::GFx::AS2::Value v14; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::ASStringNode *v15; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v16; // [rsp+90h] [rbp+18h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v17; // [rsp+98h] [rbp+20h]

  v4 = *(_QWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 224);
  if ( v4 )
  {
    if ( !LOBYTE(this->Level) && !params->TabChildrenInProto.Value )
    {
      Size = this[-1].InitActionsExecuted.Data.Size;
      if ( Size )
      {
        v14.T.Type = 0;
        ConstString = Scaleform::GFx::AS2::Environment::CreateConstString(
                        (Scaleform::GFx::AS2::Environment *)&this->Scaleform::GFx::AS2::ObjectInterface,
                        (Scaleform::GFx::ASString *)&v15,
                        "tabChildren");
        v7 = (*(__int64 (__fastcall **)(unsigned __int64, char *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))(*(_QWORD *)(Size + 32) + 88i64))(
               Size + 32,
               &this->ASEnvironment.GlobalRegister[3].V.FunctionValue.Flags,
               ConstString,
               &v14,
               -2i64);
        v8 = v15;
        if ( v15->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        if ( v7 && v14.T.Type && v14.T.Type != 10 )
          params->TabChildrenInProto.Value = !Scaleform::GFx::AS2::Value::ToBool(
                                                &v14,
                                                (Scaleform::GFx::AS2::Environment *)&this->Scaleform::GFx::AS2::ObjectInterface)
                                           + 1;
        if ( v14.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v14);
      }
    }
    if ( LOBYTE(this->Level) != 2 && params->TabChildrenInProto.Value != 2 )
    {
      v10 = 0i64;
      do
      {
        v11 = *(_QWORD *)(v10 + *(_QWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 216));
        if ( v11
          && *(char *)(v11 + 106) < 0
          && (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v11 + 472i64))(v11) )
        {
          if ( *(__int16 *)(v11 + 188) > 0 && !params->TabIndexed )
          {
            Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Resize(
              &params->Array->Data,
              0i64);
            params->TabIndexed = 1;
          }
          if ( ((*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v11 + 696i64))(v11)
             || params->InclFocusEnabled
             && (*(unsigned __int8 (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 712i64))(v11, 2i64))
            && (!params->TabIndexed || *(__int16 *)(v11 + 188) > 0) )
          {
            ++*(_DWORD *)(v11 + 8);
            v15 = (Scaleform::GFx::ASStringNode *)v11;
            Array = params->Array;
            Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              &params->Array->Data,
              params->Array->Data.pHeap,
              params->Array->Data.Size + 1);
            v13 = &Array->Data.Data[Array->Data.Size - 1];
            v16 = v13;
            v17 = v13;
            if ( v13 )
            {
              ++*(_DWORD *)(v11 + 8);
              v13->pObject = (Scaleform::GFx::InteractiveObject *)v11;
            }
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v11);
          }
          if ( (*(_WORD *)(v11 + 106) & 0x200) != 0 )
            Scaleform::GFx::DisplayObjContainer::FillTabableArray((Scaleform::GFx::DisplayObjContainer *)v11, params);
        }
        v10 += 16i64;
        --v4;
      }
      while ( v4 );
    }
  }
}

// File Line: 3529
// RVA: 0x7102E0
char __fastcall Scaleform::GFx::AS2::AvmSprite::ReplaceChildCharacter(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::InteractiveObject *poldChar,
        Scaleform::GFx::InteractiveObject *pnewChar)
{
  char pIndXFormData; // al
  char v8; // al
  unsigned __int64 DisplayIndex; // rax

  Scaleform::GFx::DisplayObject::SetMask(poldChar, 0i64, 1);
  if ( (poldChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x8000u) != 0 )
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(this->pDispObj->pASRoot->pMovieImpl, poldChar);
  if ( Scaleform::GFx::DisplayList::GetDisplayIndex((Scaleform::GFx::DisplayList *)&this->pDispObj[1], poldChar->Depth) == -1i64 )
    return 0;
  Scaleform::GFx::InteractiveObject::CopyPhysicalProperties(pnewChar, poldChar);
  if ( (pnewChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
    && (poldChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
  {
    pIndXFormData = (char)pnewChar[1].pIndXFormData;
    if ( ((__int64)poldChar[1].pIndXFormData & 0x20) != 0 )
      v8 = pIndXFormData | 0x20;
    else
      v8 = pIndXFormData & 0xDF;
    LOBYTE(pnewChar[1].pIndXFormData) = v8;
  }
  ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))poldChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[74].__vecDelDtor)(poldChar);
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pDispObj->pASRoot->vfptr[7].__vecDelDtor)(this->pDispObj->pASRoot);
  Scaleform::GFx::InteractiveObject::MoveNameHandle(pnewChar, poldChar);
  DisplayIndex = Scaleform::GFx::DisplayList::GetDisplayIndex(
                   (Scaleform::GFx::DisplayList *)&this->pDispObj[1],
                   poldChar->Depth);
  if ( DisplayIndex == -1i64 )
    return 0;
  Scaleform::GFx::DisplayList::ReplaceDisplayObjectAtIndex(
    (Scaleform::GFx::DisplayList *)&this->pDispObj[1],
    this->pDispObj,
    DisplayIndex,
    pnewChar);
  return 1;
}

// File Line: 3569
// RVA: 0x710400
char __fastcall Scaleform::GFx::AS2::AvmSprite::ReplaceChildCharacterOnLoad(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::InteractiveObject *poldChar,
        Scaleform::GFx::InteractiveObject *pnewChar)
{
  char result; // al

  result = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, Scaleform::GFx::InteractiveObject *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmTextFieldBase)(
             this,
             poldChar);
  if ( result )
  {
    ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))pnewChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[73].__vecDelDtor)(pnewChar);
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pDispObj->pASRoot->vfptr[7].__vecDelDtor)(this->pDispObj->pASRoot);
    return 1;
  }
  return result;
}

// File Line: 3580
// RVA: 0x7031D0
__int64 __fastcall Scaleform::GFx::AS2::AvmSprite::MustBeInPlaylist(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::Ptr<Scaleform::GFx::AS2::MovieClipObject> *p_ASMovieClipObj; // rcx
  Scaleform::GFx::AS2::MovieClipObject *pObject; // rax
  __int64 v4; // [rsp+20h] [rbp-28h] BYREF
  int v5; // [rsp+28h] [rbp-20h]
  char v6; // [rsp+2Ch] [rbp-1Ch]
  int v7; // [rsp+30h] [rbp-18h]

  p_ASMovieClipObj = &this[-1].ASMovieClipObj;
  v5 = 0;
  v6 = 0;
  pObject = p_ASMovieClipObj->pObject;
  v4 = 2i64;
  v7 = 65280;
  return ((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::MovieClipObject> *, __int64 *))pObject->ResolveHandler.Function)(
           p_ASMovieClipObj,
           &v4);
}

// File Line: 3592
// RVA: 0x6EE890
__int64 __fastcall Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx

  pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  pNode = name->pNode;
  if ( pObject[26].vfptr == (Scaleform::RefCountImplCoreVtbl *)name->pNode )
    return 1i64;
  if ( *(Scaleform::GFx::ASStringNode **)&pObject[26].RefCount == pNode )
    return 2i64;
  if ( (Scaleform::GFx::ASStringNode *)pObject[26].pMovieImpl == pNode )
    return 4i64;
  if ( (Scaleform::GFx::ASStringNode *)pObject[26].pASSupport.pObject == pNode )
    return 8i64;
  if ( *(Scaleform::GFx::ASStringNode **)&pObject[26].AVMVersion == pNode )
    return 16i64;
  if ( (Scaleform::GFx::ASStringNode *)pObject[27].vfptr == pNode )
    return 32i64;
  if ( *(Scaleform::GFx::ASStringNode **)&pObject[27].RefCount == pNode )
    return 64i64;
  if ( (Scaleform::GFx::ASStringNode *)pObject[32].vfptr == pNode )
    return 128i64;
  if ( *(Scaleform::GFx::ASStringNode **)&pObject[32].RefCount == pNode )
    return 256i64;
  if ( (Scaleform::GFx::ASStringNode *)pObject[32].pMovieImpl == pNode )
    return 512i64;
  if ( (Scaleform::GFx::ASStringNode *)pObject[32].pASSupport.pObject == pNode )
    return 1024i64;
  if ( *(Scaleform::GFx::ASStringNode **)&pObject[32].AVMVersion == pNode )
    return 2048i64;
  return 0i64;
}

// File Line: 3656
// RVA: 0x71E210
void __fastcall Scaleform::GFx::AS2::MovieClipObject::Set__proto__(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *protoObj)
{
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int RefCount; // eax
  __int64 (__fastcall **v8)(void *); // [rsp+38h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // [rsp+40h] [rbp-18h]
  Scaleform::GFx::AS2::ASStringContext *v10; // [rsp+48h] [rbp-10h]

  Scaleform::GFx::AS2::Object::Set__proto__(this, psc, protoObj);
  if ( protoObj
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&protoObj->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&protoObj->Scaleform::GFx::AS2::ObjectInterface) != 11 )
  {
    v8 = &`Scaleform::GFx::AS2::MovieClipObject::Set__proto__::`5::MemberVisitor::`vftable;
    if ( this != (Scaleform::GFx::AS2::MovieClipObject *)32 )
      LODWORD((&this[-1].pWatchpoints)[3]) = (LODWORD((&this[-1].pWatchpoints)[3]) + 1) & 0x8FFFFFFF;
    v9 = (Scaleform::GFx::AS2::MovieClipObject *)((char *)this - 32);
    v10 = psc;
    (*(void (__fastcall **)(unsigned __int64 *, Scaleform::GFx::AS2::ASStringContext *, __int64 (__fastcall ***)(void *), __int64, _QWORD))(this->pRCC->Roots.NumPages + 64))(
      &this->pRCC->Roots.NumPages,
      psc,
      &v8,
      13i64,
      0i64);
    v6 = v9;
    if ( v9 )
    {
      RefCount = v9->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
  }
}

// File Line: 3676
// RVA: 0x7237D0
void __fastcall Scaleform::GFx::AS2::MovieClipObject::Set__proto___::_5_::MemberVisitor::Visit(
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::ASString *val,
        char flags)
{
  if ( (unsigned __int16)Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(
                           (Scaleform::GFx::AS2::ASStringContext *)name[2].pNode,
                           val) )
    BYTE2(name[1].pNode[2].RefCount) = 1;
}

// File Line: 3692
// RVA: 0x6D7850
char __fastcall Scaleform::GFx::AS2::MovieClipObject::ActsAsButton(Scaleform::GFx::AS2::MovieClipObject *this)
{
  Scaleform::GFx::AS2::MovieClipObject *i; // rbx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // rdi

  i = this;
  if ( !this->ButtonEventMask )
  {
    while ( 2 )
    {
      if ( !i->HasButtonHandlers )
      {
        p_pProto = &i->pProto;
        for ( i = (Scaleform::GFx::AS2::MovieClipObject *)i->pProto.pObject;
              ;
              i = (Scaleform::GFx::AS2::MovieClipObject *)i->pProto.pObject )
        {
          if ( !i )
            return 0;
          if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&p_pProto->pObject->vfptr->gap8[8])(&p_pProto->pObject->Scaleform::GFx::AS2::ObjectInterface) == 11 )
            break;
        }
        if ( !i->ButtonEventMask )
          continue;
      }
      break;
    }
  }
  return 1;
}

// File Line: 3710
// RVA: 0x719770
void __fastcall Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::DisplayObjectBase *v8; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  __int16 ButtonEventNameMask; // ax
  Scaleform::GFx::ASStringNode *v11; // r8
  char *v12; // rcx
  Scaleform::GFx::ASMovieRootBase *pObject; // rax
  Scaleform::GFx::AS2::Environment *v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS2::Environment *v18; // rax
  float v19; // xmm1_4
  Scaleform::GFx::AS2::Environment *v20; // rax
  bool v21; // al
  Scaleform::GFx::DisplayObjectBase *v22; // [rsp+20h] [rbp-48h] BYREF
  Scaleform::GFx::ASString result; // [rsp+28h] [rbp-40h] BYREF
  __int64 v24; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::AS2::Value v25; // [rsp+38h] [rbp-30h] BYREF

  v24 = -2i64;
  Scaleform::GFx::AS2::MovieClipObject::GetSprite(this, (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&v22);
  v8 = v22;
  if ( v22 )
  {
    if ( v22->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor(
           v22,
           0i64) == v8 )
    {
LABEL_12:
      v8 = v22;
      goto LABEL_13;
    }
    v8 = v22;
  }
  pNode = name->pNode;
  if ( name->pNode->Size > 2 && *pNode->pData == 111 && *((_BYTE *)pNode->pData + 1) == 110 )
  {
    v25.T.Type = 0;
    if ( !this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
            &this->Scaleform::GFx::AS2::ObjectInterface,
            psc,
            name,
            &v25) )
    {
      ButtonEventNameMask = Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(psc, name);
      if ( ButtonEventNameMask )
        this->ButtonEventMask |= ButtonEventNameMask;
    }
    if ( v25.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v25);
    goto LABEL_12;
  }
LABEL_13:
  if ( v8 )
  {
    v11 = name->pNode;
    if ( (name->pNode->HashFlags & 0x80000000) != 0 )
    {
      v12 = (char *)v8 + 4 * (unsigned __int8)v8->AvmObjOffset;
      pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( v11 == (Scaleform::GFx::ASStringNode *)pObject[38].vfptr )
      {
        v14 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 240i64))(v12);
        v15 = Scaleform::GFx::AS2::Value::ToString(val, &result, v14, -1);
        Scaleform::GFx::DisplayObjectBase::SetRendererString(v22, v15->pNode->pData);
        v16 = result.pNode;
        if ( result.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      }
      else if ( v11 == *(Scaleform::GFx::ASStringNode **)&pObject[38].RefCount )
      {
        v18 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 240i64))(v12);
        v19 = Scaleform::GFx::AS2::Value::ToNumber(val, v18);
        Scaleform::GFx::DisplayObjectBase::SetRendererFloat(v8, v19);
      }
      else if ( v11 == (Scaleform::GFx::ASStringNode *)pObject[38].pMovieImpl )
      {
        v20 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 240i64))(v12);
        v21 = Scaleform::GFx::AS2::Value::ToBool(val, v20);
        Scaleform::GFx::DisplayObjectBase::DisableBatching(v8, v21);
      }
    }
  }
  if ( v22 )
    Scaleform::RefCountNTSImpl::Release(v22);
}

// File Line: 3758
// RVA: 0x719BD0
bool __fastcall Scaleform::GFx::AS2::MovieClipObject::SetMemberRaw(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(
    (Scaleform::GFx::AS2::MovieClipObject *)((char *)this - 32),
    psc,
    name,
    val);
  return Scaleform::GFx::AS2::Object::SetMemberRaw(this, psc, name, val, flags);
}

// File Line: 3767
// RVA: 0x717A90
bool __fastcall Scaleform::GFx::AS2::MovieClipObject::SetMember(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(
    (Scaleform::GFx::AS2::MovieClipObject *)((char *)this - 32),
    &penv->StringContext,
    name,
    val);
  return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
}

// File Line: 3782
// RVA: 0x6E2100
bool __fastcall Scaleform::GFx::AS2::MovieClipObject::DeleteMember(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  unsigned __int16 ButtonEventNameMask; // ax
  Scaleform::GFx::AS2::Value v8; // [rsp+28h] [rbp-30h] BYREF

  if ( name->pNode->Size > 2 && *(_WORD *)name->pNode->pData == 28271 )
  {
    v8.T.Type = 0;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::MovieClipObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
           this,
           psc,
           name,
           &v8,
           -2i64) )
    {
      ButtonEventNameMask = Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(psc, name);
      if ( ButtonEventNameMask )
        *(_WORD *)&this->ResolveHandler.Flags &= ~ButtonEventNameMask;
    }
    if ( v8.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v8);
  }
  return Scaleform::GFx::AS2::Object::DeleteMember(this, psc, name);
}

// File Line: 3870
// RVA: 0x6CAB00
void __fastcall Scaleform::GFx::AS2::MovieClipProto::MovieClipProto(
        Scaleform::GFx::AS2::MovieClipProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *prototype,
        Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rbx
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+88h] [rbp+10h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    prototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::MovieClipObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::MovieClipObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::MovieClipProto::`vftable;
  flags.Flags = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    this,
    psc,
    MovieClipFunctionTable,
    &flags);
  flags.Flags = 3;
  val.T.Type = 2;
  val.V.BooleanValue = 1;
  pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(
    this,
    psc,
    (Scaleform::GFx::ASString *)&pObject[33].pMovieImpl,
    &val);
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (Scaleform::GFx::ASString *)&pObject[33].pMovieImpl,
    &val,
    &flags);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 3877
// RVA: 0x6E0630
void __fastcall Scaleform::GFx::AS2::MovieClipCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::MovieClipCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::MovieClipObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::MovieClipObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieClipCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                 this,
                                                 112i64);
  if ( v3 )
    Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(v3, penv);
}

// File Line: 3882
// RVA: 0x6F96C0
void __fastcall Scaleform::GFx::AS2::MovieClipCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *Result; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 11 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, (Scaleform::GFx::AS2::Object *)&v3[-2]);
    else
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, 0i64);
  }
  else
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 0;
  }
}

