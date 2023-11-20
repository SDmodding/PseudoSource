// File Line: 59
// RVA: 0x6C76B0
void __fastcall Scaleform::GFx::AS2::AvmSprite::AvmSprite(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::Sprite *psprite)
{
  Scaleform::GFx::Sprite *v2; // rbx
  Scaleform::GFx::AS2::AvmSprite *v3; // rdi
  Scaleform::GFx::AvmSpriteBase *v4; // rax
  __int64 v5; // rsi
  signed __int64 v6; // r14
  signed __int64 v7; // rcx
  unsigned int v8; // ebx
  Scaleform::GFx::AS2::Object *v9; // rax
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax

  v2 = psprite;
  v3 = this;
  Scaleform::GFx::AS2::AvmCharacter::AvmCharacter(
    (Scaleform::GFx::AS2::AvmCharacter *)&this->vfptr,
    (Scaleform::GFx::InteractiveObject *)&psprite->vfptr);
  v4 = (Scaleform::GFx::AvmSpriteBase *)&v3->vfptr;
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable';
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjContainerBase::`vftable';
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmSpriteBase::`vftable';
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable';
  Scaleform::GFx::AS2::Environment::Environment(&v3->ASEnvironment);
  v3->Level = -1;
  v5 = 0i64;
  v3->ASMovieClipObj.pObject = 0i64;
  v6 = (signed __int64)&v3->InitActionsExecuted;
  *(_QWORD *)v6 = 0i64;
  *(_QWORD *)(v6 + 8) = 0i64;
  *(_QWORD *)(v6 + 16) = 0i64;
  v3->TabChildren.Value = 0;
  v3->ASEnvironment.Target = (Scaleform::GFx::InteractiveObject *)&v2->vfptr;
  *((_BYTE *)&v3->ASEnvironment + 382) &= 0xFDu;
  v3->ASEnvironment.StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr);
  if ( v2 )
  {
    v7 = (signed __int64)v2 + 4 * (unsigned __int8)v2->AvmObjOffset;
    v5 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v7 + 8i64))(v7);
  }
  v3->ASEnvironment.StringContext.pContext = (Scaleform::GFx::AS2::GlobalContext *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 184i64))(v5);
  LOBYTE(v3->pDispObj[1].pIndXFormData) &= 0xDFu;
  v3->pDispObj->Flags |= 0x800u;
  v8 = ((__int64 (__cdecl *)(Scaleform::GFx::InteractiveObject *))v3->pDispObj[1].pParent->vfptr[10].__vecDelDtor)(v3->pDispObj[1].pParent);
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v3->InitActionsExecuted.Data,
    v8);
  memset(*(void **)v6, 0, v8);
  v9 = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
         (Scaleform::GFx::AS2::GlobalContext *)v3->pDispObj->pASRoot[2].vfptr,
         &v3->ASEnvironment,
         ASBuiltin_MovieClip);
  v10 = v9;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
  v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v3->pProto.pObject->vfptr;
  if ( v11 )
  {
    v12 = v11->RefCount;
    if ( v12 & 0x3FFFFFF )
    {
      v11->RefCount = v12 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
  v3->pProto.pObject = v10;
}

// File Line: 85
// RVA: 0x6D0F90
void __fastcall Scaleform::GFx::AS2::AvmSprite::~AvmSprite(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::AvmSprite *v1; // rbx
  Scaleform::GFx::AvmSpriteBase *v2; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v3; // rcx
  unsigned int v4; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v2 = (Scaleform::GFx::AvmSpriteBase *)&this->vfptr;
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable';
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->InitActionsExecuted.Data.Data);
  v3 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->ASMovieClipObj.pObject->vfptr;
  if ( v3 )
  {
    v4 = v3->RefCount;
    if ( v4 & 0x3FFFFFF )
    {
      v3->RefCount = v4 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
    }
  }
  Scaleform::GFx::AS2::Environment::~Environment(&v1->ASEnvironment);
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  Scaleform::GFx::AS2::AvmCharacter::~AvmCharacter((Scaleform::GFx::AS2::AvmCharacter *)&v1->vfptr);
}

// File Line: 89
// RVA: 0x700AD0
bool __fastcall Scaleform::GFx::AS2::AvmSprite::IsLevelMovie(Scaleform::GFx::AS2::AvmSprite *this)
{
  return *((_DWORD *)&this->ASEnvironment.ThrowingValue.NV + 6) >= 0;
}

// File Line: 108
// RVA: 0x6E8D00
void __fastcall Scaleform::GFx::AS2::AvmSprite::ExecuteInitActionFrameTags(Scaleform::GFx::AS2::AvmSprite *this, unsigned int frame)
{
  Scaleform::GFx::AS2::AvmSprite *v2; // rsi
  __int64 v3; // r14
  Scaleform::RefCountNTSImpl *v4; // rdi
  unsigned int v5; // ebx
  __int64 v6; // [rsp+28h] [rbp-20h]
  unsigned int v7; // [rsp+30h] [rbp-18h]

  v2 = this;
  v3 = frame;
  if ( !*((_BYTE *)&this->ASEnvironment.LocalFrames.Data.Data->pObject + frame) )
  {
    v4 = (Scaleform::RefCountNTSImpl *)this[-1].InitActionsExecuted.Data.Policy.Capacity;
    if ( v4 )
      ++v4->RefCount;
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
          v2[-1].InitActionsExecuted.Data.Policy.Capacity);
        ++v5;
      }
      while ( v5 < v7 );
      *((_BYTE *)&v2->ASEnvironment.LocalFrames.Data.Data->pObject + v3) = 1;
    }
    if ( v4 )
      Scaleform::RefCountNTSImpl::Release(v4);
  }
}

// File Line: 165
// RVA: 0x6DDE10
void __fastcall Scaleform::GFx::AS2::AvmSprite::CloneInternalData(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::InteractiveObject *src)
{
  Scaleform::GFx::InteractiveObject *v2; // rbx
  Scaleform::GFx::AS2::AvmSprite *v3; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *v4; // rax
  unsigned __int8 v5; // al
  __int64 v6; // rax
  Scaleform::GFx::AS2::MovieClipObject *v7; // rax

  v2 = src;
  v3 = this;
  if ( src )
    v4 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&src->vfptr + 4 * (unsigned __int8)src->AvmObjOffset))[1].__vecDelDtor)((char *)src + 4 * (unsigned __int8)src->AvmObjOffset);
  else
    v4 = 0i64;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::Assign(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)&v3->EventHandlers.mHash.pTable,
    &v3->EventHandlers,
    v4 + 4);
  if ( (v2->Flags >> 10) & 1 )
  {
    v5 = v2->AvmObjOffset;
    if ( v5 )
    {
      v6 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v2->vfptr + 4 * v5))[1].__vecDelDtor)((signed __int64)v2 + 4 * v5);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v6 + 96i64))(v6) )
      {
        v7 = Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject(v3);
        if ( v7 )
          v7->HasButtonHandlers = 1;
      }
    }
  }
}

// File Line: 177
// RVA: 0x6FB180
char __fastcall Scaleform::GFx::AS2::AvmSprite::HasEventHandler(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::EventId *v2; // rdi
  Scaleform::GFx::AS2::AvmSprite *v3; // rbx
  Scaleform::GFx::AS2::MovieClipObject *v5; // rcx
  char v6; // bl
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS2::Value v9; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h]

  v2 = id;
  v3 = this;
  if ( Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler((Scaleform::GFx::AS2::AvmCharacter *)&this->vfptr, id) )
    return 1;
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)&v3->pDispObj->pASRoot[7].AVMVersion,
    v2);
  if ( result.pNode->Size )
  {
    v9.T.Type = 0;
    v5 = v3->ASMovieClipObj.pObject;
    if ( v5 || (v5 = (Scaleform::GFx::AS2::MovieClipObject *)v3->pProto.pObject) != 0i64 )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v5->vfptr->GetMemberRaw)(
             &v5->vfptr,
             &v3->ASEnvironment.StringContext,
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
  v7 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  return v6;
}

// File Line: 206
// RVA: 0x6DC180
void __fastcall Scaleform::GFx::AS2::AvmSprite::CallFrameActions(Scaleform::GFx::AS2::AvmSprite *this, unsigned int frameNumber)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS2::AvmSprite *v3; // rsi
  Scaleform::GFx::ASMovieRootBase *v4; // rcx
  volatile int v5; // er14
  unsigned int v6; // ebp
  __int64 v7; // rbx
  __int64 v8; // rdi
  __int64 v9; // [rsp+20h] [rbp-18h]
  unsigned int v10; // [rsp+28h] [rbp-10h]

  v2 = frameNumber;
  v3 = this;
  if ( frameNumber == -1 || frameNumber >= ((unsigned int (*)(void))this->pDispObj->vfptr[111].__vecDelDtor)() )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v3->pDispObj->vfptr,
      "CallFrame('%d') - unknown frame",
      v2);
  }
  else
  {
    v4 = v3->pDispObj->pASRoot;
    v5 = v4[7].RefCount;
    v6 = LODWORD(v4[7].pMovieImpl) + 1;
    LODWORD(v4[7].pMovieImpl) = v6;
    v4[7].RefCount = v6;
    ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64 *, _QWORD))v3->pDispObj[1].pParent->vfptr[11].__vecDelDtor)(
      v3->pDispObj[1].pParent,
      &v9,
      v2);
    v7 = 0i64;
    if ( v10 )
    {
      do
      {
        v8 = *(_QWORD *)(v9 + 8 * v7);
        if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v8 + 32i64))(v8) )
          (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v8 + 8i64))(
            v8,
            v3->pDispObj);
        v7 = (unsigned int)(v7 + 1);
      }
      while ( (unsigned int)v7 < v10 );
    }
    v3->pDispObj->pASRoot[7].RefCount = v5;
    Scaleform::GFx::AS2::MovieRoot::DoActionsForSession((Scaleform::GFx::AS2::MovieRoot *)v3->pDispObj->pASRoot, v6);
  }
}

// File Line: 242
// RVA: 0x705C00
void __fastcall Scaleform::GFx::AS2::AvmSprite::OnEventLoad(Scaleform::GFx::AS2::AvmSprite *this)
{
  unsigned int v1; // edi
  Scaleform::GFx::AS2::AvmSprite *v2; // rsi
  signed __int64 v3; // rax
  signed __int64 v4; // rax
  Scaleform::GFx::ActionPriority::Priority v5; // edx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v6; // rax
  Scaleform::GFx::InteractiveObject *v7; // rbp
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v8; // rbx
  Scaleform::RefCountNTSImpl *v9; // rcx
  Scaleform::RefCountNTSImpl *v10; // rcx
  unsigned __int64 v11; // rbp
  signed __int64 v12; // rax
  Scaleform::GFx::InteractiveObject *v13; // rbx
  signed __int64 v14; // r14
  unsigned int v15; // [rsp+2Ch] [rbp-2Ch]
  Scaleform::GFx::EventId key; // [rsp+34h] [rbp-24h]

  *(_QWORD *)&key.Id = 1i64;
  v1 = 0;
  key.KeyCode = 0;
  LOBYTE(v15) = 0;
  key.TouchID = v15;
  v2 = this;
  *(_DWORD *)&key.RollOverCnt = 65280;
  v3 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::findIndexAlt<Scaleform::GFx::EventId>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)&this->EventHandlers.mHash.pTable,
         &key);
  if ( v3 < 0 || (v4 = (signed __int64)&v2->EventHandlers.mHash.pTable[4 * v3 + 2]) == 0 || (v5 = 4, v4 == -24) )
    v5 = 5;
  v6 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
         (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v2->pDispObj->pASRoot[3].RefCount,
         v5);
  v7 = v2->pDispObj;
  v6->Type = 2;
  v8 = v6;
  if ( v7 )
    ++v7->RefCount;
  v9 = (Scaleform::RefCountNTSImpl *)&v6->pCharacter.pObject->vfptr;
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release(v9);
  v8->pCharacter.pObject = v7;
  v10 = (Scaleform::RefCountNTSImpl *)&v8->pActionBuffer.pObject->vfptr;
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  v8->pActionBuffer.pObject = 0i64;
  *(_QWORD *)&v8->mEventId.Id = 1i64;
  v8->mEventId.KeyCode = 0;
  v8->mEventId.AsciiCode = 0;
  *(_DWORD *)&v8->mEventId.RollOverCnt = 65280;
  v2->pDispObj->Flags |= 0x20u;
  Scaleform::GFx::AS2::AvmSprite::ExecuteInitActionFrameTags((Scaleform::GFx::AS2::AvmSprite *)((char *)v2 + 40), 0);
  Scaleform::GFx::Sprite::DefaultOnEventLoad((Scaleform::GFx::Sprite *)v2->pDispObj);
  v11 = (unsigned __int64)v2->pDispObj->pASRoot[39].pASSupport.pObject;
  if ( v11 )
  {
    v12 = 0i64;
    do
    {
      v13 = v2->pDispObj;
      v14 = v12;
      if ( v13 == (Scaleform::GFx::InteractiveObject *)(*((__int64 (**)(void))(&v13->pASRoot[39].pMovieImpl->vfptr)[v12]->__vecDelDtor
                                                        + 120))() )
        Scaleform::GFx::Sprite::SetHitArea(
          (Scaleform::GFx::Sprite *)(&v2->pDispObj->pASRoot[39].pMovieImpl->vfptr)[v14],
          (Scaleform::GFx::Sprite *)v2->pDispObj);
      v12 = ++v1;
    }
    while ( v1 < v11 );
  }
}

// File Line: 280
// RVA: 0x714650
void __fastcall Scaleform::GFx::AS2::AvmSprite::SetHitAreaNotify(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::Sprite *phitArea)
{
  Scaleform::GFx::Sprite *v2; // r11
  Scaleform::GFx::AS2::AvmSprite *v3; // r10
  unsigned __int64 v4; // r9
  __int64 v5; // rdx
  unsigned __int64 v6; // r8
  signed int v7; // eax
  __int64 v8; // rcx
  __int64 v9; // rdx
  Scaleform::RefCountNTSImpl *v10; // rdi
  __int64 v11; // rbx
  Scaleform::RefCountNTSImpl **v12; // rdx

  v2 = phitArea;
  v3 = this;
  v4 = this[-1].InitActionsExecuted.Data.Policy.Capacity;
  v5 = *(_QWORD *)(v4 + 32);
  v6 = *(_QWORD *)(v5 + 1584);
  if ( *(_QWORD *)(v4 + 296) && (v7 = 0, v6) )
  {
    v8 = 0i64;
    v9 = *(_QWORD *)(v5 + 1576);
    while ( *(_QWORD *)(v9 + 8 * v8) != v4 )
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
  if ( v2 )
  {
    if ( v7 == -1 )
    {
      v10 = (Scaleform::RefCountNTSImpl *)v4;
      if ( v4 )
        ++*(_DWORD *)(v4 + 8);
      v11 = *(_QWORD *)(v3[-1].InitActionsExecuted.Data.Policy.Capacity + 32);
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
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> > *)(*(_QWORD *)(v4 + 32) + 1576i64),
      v7);
  }
}

// File Line: 298
// RVA: 0x6F6A60
signed __int64 __fastcall Scaleform::GFx::AS2::AvmSprite::GetTopMostEntity(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::Render::Point<float> *localPt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr, Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *hitTest)
{
  Scaleform::GFx::InteractiveObject *v4; // rdi
  Scaleform::GFx::AS2::AvmSprite *v5; // rsi
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v6; // rbx
  Scaleform::Render::Point<float> *v7; // r13
  __int64 v8; // r14
  __int64 v9; // rax
  float v10; // xmm6_4
  float v11; // xmm7_4
  Scaleform::GFx::InteractiveObject *v12; // rcx
  Scaleform::GFx::InteractiveObject *v13; // r8
  Scaleform::GFx::DisplayObject *v14; // r9
  unsigned int v15; // er10
  bool v16; // r11
  char v17; // dl
  signed __int64 v18; // r15
  Scaleform::GFx::DisplayObject *v19; // r12
  signed int v20; // ebp
  signed __int64 v21; // r13
  __int64 v22; // rcx
  signed int v23; // eax
  signed int v24; // esi
  unsigned __int8 v25; // al
  __int64 v26; // rax
  Scaleform::GFx::InteractiveObject *v27; // rcx
  signed __int64 result; // rax
  unsigned __int8 v29; // al
  __int64 v30; // rax
  Scaleform::GFx::InteractiveObject *v31; // rax
  Scaleform::GFx::InteractiveObject *v32; // rax
  float v33; // xmm0_4
  char v34; // [rsp+20h] [rbp-A8h]
  bool v35; // [rsp+21h] [rbp-A7h]
  unsigned int v36; // [rsp+24h] [rbp-A4h]
  Scaleform::GFx::InteractiveObject *v37; // [rsp+28h] [rbp-A0h]
  Scaleform::GFx::DisplayObject *v38; // [rsp+30h] [rbp-98h]
  Scaleform::GFx::InteractiveObject *v39; // [rsp+38h] [rbp-90h]
  Scaleform::GFx::InteractiveObject *v40; // [rsp+40h] [rbp-88h]
  float v41; // [rsp+48h] [rbp-80h]
  float v42; // [rsp+4Ch] [rbp-7Ch]
  Scaleform::GFx::AS2::AvmSprite *v43; // [rsp+D0h] [rbp+8h]
  Scaleform::Render::Point<float> *v44; // [rsp+D8h] [rbp+10h]
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v45; // [rsp+E8h] [rbp+20h]

  v45 = hitTest;
  v44 = localPt;
  v43 = this;
  v4 = (Scaleform::GFx::InteractiveObject *)this[-1].InitActionsExecuted.Data.Policy.Capacity;
  v5 = this;
  v6 = pdescr;
  v7 = localPt;
  v8 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v4->vfptr[121].__vecDelDtor)(v4);
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v4->vfptr[120].__vecDelDtor)(v4);
  v10 = v42;
  v11 = v41;
  v12 = v40;
  v13 = 0i64;
  v14 = 0i64;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = *(_QWORD *)(v5[-1].InitActionsExecuted.Data.Policy.Capacity + 224) - 1i64;
  v19 = (Scaleform::GFx::DisplayObject *)v9;
  v39 = 0i64;
  v38 = 0i64;
  v36 = 0;
  v35 = 0;
  v20 = 2;
  v34 = 0;
  if ( v18 < 0 )
  {
LABEL_45:
    if ( !v19 || (v32 = v6->pResult) != 0i64 && v32 != v4 && SLOBYTE(v32->Flags) < 0 )
    {
      if ( v20 == 1 )
      {
        v6->pResult = v12;
        v6->LocalPt.x = v11;
        v6->LocalPt.y = v10;
        v6->pIgnoreMC = v13;
        v6->pHitArea = v14;
        v6->ControllerIdx = v15;
        v6->TestAll = v16;
        return 1i64;
      }
      v33 = v7->y;
      v6->LocalPt.x = v7->x;
      v6->LocalPt.y = v33;
      if ( !v17 )
      {
        result = 3i64;
        goto LABEL_57;
      }
    }
    else if ( v19 != v6->pHitArea )
    {
      goto LABEL_28;
    }
LABEL_50:
    v6->pResult = v4;
    return 1i64;
  }
  v37 = v40;
  v21 = 16 * v18;
  while ( 1 )
  {
    v22 = *(_QWORD *)(v21 + *(_QWORD *)(v5[-1].InitActionsExecuted.Data.Policy.Capacity + 216));
    if ( v45->Data.Size && (!v45->Data.Data[v18] || *(_WORD *)(v22 + 104)) || (*(_BYTE *)(v22 + 106) >> 1) & 1 )
      goto LABEL_42;
    v23 = (*(__int64 (__fastcall **)(__int64, Scaleform::Render::Point<float> *, Scaleform::GFx::DisplayObjectBase::TopMostDescr *))(*(_QWORD *)v22 + 512i64))(
            v22,
            v44,
            v6);
    v24 = v23;
    if ( v23 != 1 )
      break;
    if ( (v4->Flags >> 13) & 1 )
      v6->pResult = v4;
    if ( !v6->pResult || !((v6->pResult->Flags >> 12) & 1) )
    {
      if ( v6->TestAll )
        v24 = 1;
      goto LABEL_18;
    }
    v5 = v43;
    v17 = 1;
    v6->pResult = v4;
    v34 = 1;
LABEL_43:
    v21 -= 16i64;
    if ( --v18 < 0 )
    {
      v12 = v37;
      v7 = v44;
      v13 = v39;
      v14 = v38;
      v15 = v36;
      v16 = v35;
      goto LABEL_45;
    }
  }
  if ( v23 == 3 && v6->pResult )
  {
    v11 = v6->LocalPt.x;
    v10 = v6->LocalPt.y;
    v37 = v6->pResult;
    v20 = 1;
    v39 = v6->pIgnoreMC;
    v38 = v6->pHitArea;
    v36 = v6->ControllerIdx;
    v35 = v6->TestAll;
  }
LABEL_18:
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::MovieClipObject> *))v43[-1].ASMovieClipObj.pObject->pSprite.pProxy.pObject)(&v43[-1].ASMovieClipObj) )
  {
    if ( !v8
      || !v6->TestAll
      && ((v25 = *(_BYTE *)(v8 + 109)) == 0
       || (v26 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v8 + 4i64 * v25) + 8i64))(v8 + 4i64 * v25),
           !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v26 + 96i64))(v26))) )
    {
      if ( v24 == 1 )
      {
        if ( v6->TestAll )
          return 1i64;
        if ( v6->pResult != v4 )
        {
          v27 = v6->pResult->pParent;
          if ( !v27 || !((unsigned __int8 (*)(void))v27->vfptr[59].__vecDelDtor)() )
            goto LABEL_28;
          return 1i64;
        }
      }
      goto LABEL_41;
    }
  }
  if ( v24 != 1 && v20 != 1 )
  {
LABEL_41:
    v5 = v43;
LABEL_42:
    v17 = v34;
    goto LABEL_43;
  }
  if ( v8 )
  {
    if ( v6->TestAll
      || (v29 = *(_BYTE *)(v8 + 109)) != 0
      && (v30 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v8 + 4i64 * v29) + 8i64))(v8 + 4i64 * v29),
          (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v30 + 96i64))(v30)) )
    {
      v6->pResult = (Scaleform::GFx::InteractiveObject *)v8;
      v6->pHitArea = (Scaleform::GFx::DisplayObject *)&v4->vfptr;
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
    if ( v31 == v4 )
    {
      if ( v19 == v6->pHitArea )
        goto LABEL_50;
      v6->pResult = 0i64;
      v20 = 2;
      goto LABEL_41;
    }
  }
LABEL_28:
  result = 2i64;
LABEL_57:
  v6->pResult = 0i64;
  return result;
}

// File Line: 482
// RVA: 0x705EC0
void __fastcall Scaleform::GFx::AS2::AvmSprite::OnEventUnload(Scaleform::GFx::AS2::AvmSprite *this)
{
  this->vfptr->Set__proto__(
    (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr,
    &this->ASEnvironment.StringContext,
    0i64);
}

// File Line: 499
// RVA: 0x707250
_BOOL8 __fastcall Scaleform::GFx::AS2::AvmSprite::OnUnloading(Scaleform::GFx::AS2::AvmSprite *this, bool mayRemove)
{
  Scaleform::GFx::InteractiveObject *v2; // r8
  Scaleform::GFx::AS2::AvmSprite *v3; // rsi
  Scaleform::GFx::ASMovieRootBase *v4; // rcx
  bool v5; // bp
  unsigned __int64 v6; // r9
  signed int v7; // eax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> > *v8; // r10
  __int64 v9; // rcx
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v10; // rax
  Scaleform::GFx::InteractiveObject *v11; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v12; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v13; // rbx
  Scaleform::GFx::InteractiveObject *v14; // rdi
  Scaleform::RefCountNTSImpl *v15; // rcx
  Scaleform::RefCountNTSImpl *v16; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v17; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v18; // rbx
  Scaleform::GFx::InteractiveObject *v19; // rdi
  Scaleform::RefCountNTSImpl *v20; // rcx
  Scaleform::RefCountNTSImpl *v21; // rcx
  __int64 v23; // [rsp+20h] [rbp-28h]
  int v24; // [rsp+28h] [rbp-20h]
  char v25; // [rsp+2Ch] [rbp-1Ch]
  int v26; // [rsp+30h] [rbp-18h]

  v2 = this->pDispObj;
  v3 = this;
  v4 = v2->pASRoot;
  v5 = mayRemove;
  v6 = (unsigned __int64)v4[39].pASSupport.pObject;
  if ( v2[1].pGeomData )
  {
    v7 = 0;
    if ( v6 )
    {
      v8 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> > *)&v4[39].pMovieImpl;
      v9 = 0i64;
      while ( (Scaleform::GFx::InteractiveObject *)v8->Data.Data[v9].pObject != v2 )
      {
        v9 = (unsigned int)++v7;
        if ( (unsigned int)v7 >= v6 )
          goto LABEL_9;
      }
      if ( v7 > -1 )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          v8,
          v7);
    }
  }
LABEL_9:
  if ( v5 )
  {
    v10 = v3->vfptr;
    v23 = 4i64;
    v24 = 0;
    v25 = 0;
    v26 = 65280;
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, __int64 *, Scaleform::GFx::InteractiveObject *, unsigned __int64, signed __int64, _QWORD, _QWORD))v10->HasEventHandler)(
            v3,
            &v23,
            v2,
            v6,
            4i64,
            *(_QWORD *)&v24,
            *(_QWORD *)&v26) )
      goto LABEL_30;
    v5 = 0;
  }
  v11 = v3->pDispObj;
  if ( (LOBYTE(v11->Flags) >> 5) & 1 )
  {
    if ( !((LOBYTE(v11->Flags) >> 3) & 1) )
    {
      v12 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
              (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v11->pASRoot[3].RefCount,
              AP_Frame);
      v13 = v12;
      if ( v12 )
      {
        v14 = v3->pDispObj;
        v12->Type = 2;
        if ( v14 )
          ++v14->RefCount;
        v15 = (Scaleform::RefCountNTSImpl *)&v12->pCharacter.pObject->vfptr;
        if ( v15 )
          Scaleform::RefCountNTSImpl::Release(v15);
        v13->pCharacter.pObject = v14;
        v16 = (Scaleform::RefCountNTSImpl *)&v13->pActionBuffer.pObject->vfptr;
        if ( v16 )
          Scaleform::RefCountNTSImpl::Release(v16);
        v13->pActionBuffer.pObject = 0i64;
        *(_QWORD *)&v13->mEventId.Id = 1i64;
        v13->mEventId.KeyCode = 0;
        v13->mEventId.AsciiCode = 0;
        *(_DWORD *)&v13->mEventId.RollOverCnt = 65280;
      }
    }
  }
  v17 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
          (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v3->pDispObj->pASRoot[3].RefCount,
          AP_Frame);
  v18 = v17;
  if ( v17 )
  {
    v19 = v3->pDispObj;
    v17->Type = 2;
    if ( v19 )
      ++v19->RefCount;
    v20 = (Scaleform::RefCountNTSImpl *)&v17->pCharacter.pObject->vfptr;
    if ( v20 )
      Scaleform::RefCountNTSImpl::Release(v20);
    v18->pCharacter.pObject = v19;
    v21 = (Scaleform::RefCountNTSImpl *)&v18->pActionBuffer.pObject->vfptr;
    if ( v21 )
      Scaleform::RefCountNTSImpl::Release(v21);
    v18->pActionBuffer.pObject = 0i64;
    *(_QWORD *)&v18->mEventId.Id = 4i64;
    v18->mEventId.KeyCode = 0;
    v18->mEventId.AsciiCode = 0;
    *(_DWORD *)&v18->mEventId.RollOverCnt = 65280;
  }
LABEL_30:
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(v3->pDispObj);
  return v5;
}

// File Line: 538
// RVA: 0x6FD4E0
void __fastcall Scaleform::GFx::AS2::AvmSprite::InitializeClassInstance(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rbx
  Scaleform::GFx::AS2::AvmCharacter *v3; // rbx
  unsigned int v4; // er10
  Scaleform::GFx::AS2::Environment *v5; // r8
  Scaleform::GFx::AS2::Value *v6; // r9
  Scaleform::GFx::AS2::ObjectInterface *v7; // rdx
  char v8; // al
  Scaleform::GFx::AS2::FunctionObject *v9; // rcx
  unsigned int v10; // edx
  Scaleform::GFx::AS2::LocalFrame *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-20h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(fn->ThisPtr) == 2 )
    v3 = (Scaleform::GFx::AS2::AvmCharacter *)&v2[-1].pProto;
  else
    v3 = 0i64;
  v4 = v1->FirstArgBottomIndex;
  v5 = v1->Env;
  v6 = 0i64;
  if ( v4 <= 32 * ((unsigned int)v5->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
    v6 = &v5->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
  Scaleform::GFx::AS2::Value::ToFunction(v6, &result, v5);
  if ( result.Function )
    v7 = (Scaleform::GFx::AS2::ObjectInterface *)&result.Function->vfptr;
  else
    v7 = 0i64;
  Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(v3, v7);
  v8 = result.Flags;
  if ( !(result.Flags & 2) )
  {
    v9 = result.Function;
    if ( result.Function )
    {
      v10 = result.Function->RefCount;
      if ( v10 & 0x3FFFFFF )
      {
        result.Function->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
        v8 = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( !(v8 & 1) )
  {
    v11 = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v12 = result.pLocalFrame->RefCount;
      if ( v12 & 0x3FFFFFF )
      {
        result.pLocalFrame->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
      }
    }
  }
}

// File Line: 553
// RVA: 0x6EA530
void __fastcall Scaleform::GFx::AS2::AvmSprite::FindClassAndInitializeClassInstance(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::GlobalContext *v2; // r15
  char v3; // r12
  Scaleform::GFx::AS2::FunctionObject *v4; // rsi
  Scaleform::GFx::AS2::LocalFrame *v5; // r14
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::AS2::ObjectInterface *v9; // rdi
  Scaleform::GFx::AS2::AvmCharacter *v10; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v11; // r10
  unsigned __int64 v12; // rbx
  __int64 v13; // r11
  signed __int64 v14; // r8
  unsigned __int64 *v15; // r9
  Scaleform::GFx::ASStringNode *v16; // rdx
  signed __int64 v17; // rdx
  Scaleform::GFx::ASStringNode *v18; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v19; // r8
  signed __int64 v20; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v21; // rdx
  Scaleform::GFx::AS2::ObjectInterface *v22; // rdx
  Scaleform::GFx::InteractiveObject *v23; // rbx
  Scaleform::GFx::InteractiveObject *v24; // rbx
  Scaleform::GFx::InteractiveObject *v25; // rbx
  Scaleform::GFx::ASStringNode *v26; // rcx
  bool v27; // zf
  unsigned int v28; // eax
  unsigned int v29; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry v30; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::AS2::FunctionRefBase orig; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS2::MovieRoot::ActionEntry v32; // [rsp+C0h] [rbp-40h]
  __int64 v33; // [rsp+140h] [rbp+40h]
  Scaleform::GFx::ASString result; // [rsp+190h] [rbp+90h]
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+198h] [rbp+98h]
  Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *v36; // [rsp+1A0h] [rbp+A0h]

  v33 = -2i64;
  v1 = fn;
  v2 = fn->Env->StringContext.pContext;
  v3 = 0;
  orig.Flags = 0;
  v4 = 0i64;
  orig.Function = 0i64;
  v5 = 0i64;
  orig.pLocalFrame = 0i64;
  v6 = fn->FirstArgBottomIndex;
  v7 = fn->Env;
  v8 = 0i64;
  if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
    v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
  Scaleform::GFx::AS2::Value::ToString(v8, &result, v7, -1);
  if ( result.pNode->Size )
  {
    v9 = v1->ThisPtr;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v9->vfptr->gap8[8])(v1->ThisPtr) == 2 )
      v10 = (Scaleform::GFx::AS2::AvmCharacter *)&v9[-1].pProto;
    else
      v10 = 0i64;
    if ( v1->Env->StringContext.SWFVersion <= 6u )
    {
      key.pStr = &result;
      v18 = result.pNode;
      if ( !result.pNode->pLower )
      {
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(result.pNode);
        v18 = result.pNode;
      }
      v19 = v2->RegisteredClasses.mHash.pTable;
      if ( !v19 )
        goto LABEL_39;
      v20 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
              (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v2->RegisteredClasses.mHash.pTable,
              &key,
              v18->HashFlags & v19->SizeMask);
      if ( v20 < 0 )
        goto LABEL_39;
      v17 = (signed __int64)v2->RegisteredClasses.mHash.pTable + 8 * (5 * v20 + 3);
    }
    else
    {
      v11 = v2->RegisteredClasses.mHash.pTable;
      if ( !v11 )
        goto LABEL_39;
      v12 = v11->SizeMask;
      v13 = (unsigned int)v12 & result.pNode->HashFlags;
      v14 = v13;
      v15 = &v11->EntryCount + v13 + 4 * v13 + 2;
      if ( *v15 == -2i64 || ((unsigned int)v12 & *(_DWORD *)(v15[1] + 28)) != v13 )
        goto LABEL_39;
      while ( 1 )
      {
        v16 = (Scaleform::GFx::ASStringNode *)v15[1];
        if ( ((unsigned int)v12 & v16->HashFlags) == v13 && v16 == result.pNode )
          break;
        v14 = *v15;
        if ( *v15 == -1i64 )
          goto LABEL_39;
        v15 = &v11->EntryCount + v14 + 4 * v14 + 2;
      }
      if ( v14 < 0 )
        goto LABEL_39;
      v17 = (signed __int64)v11 + 8 * (v14 + 4 * v14 + 3);
    }
    if ( v17 )
    {
      v21 = (Scaleform::GFx::AS2::FunctionRefBase *)(v17 + 8);
      if ( v21 )
      {
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&orig, v21);
        v4 = orig.Function;
        v22 = (Scaleform::GFx::AS2::ObjectInterface *)&orig.Function->vfptr;
        if ( !orig.Function )
          v22 = 0i64;
        Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(v10, v22);
        v23 = v10->pDispObj;
        v30.pCharacter.pObject = 0i64;
        v30.pActionBuffer.pObject = 0i64;
        *(_QWORD *)&v30.mEventId.Id = 0i64;
        v30.mEventId.KeyCode = 0;
        v30.mEventId.AsciiCode = 0;
        *(_DWORD *)&v30.mEventId.RollOverCnt = 65280;
        v30.Function.Flags = 0;
        v30.Function.Function = 0i64;
        v30.Function.pLocalFrame = 0i64;
        key.pStr = (Scaleform::GFx::ASString *)&v30.FunctionParams;
        v36 = &v30.FunctionParams;
        v30.FunctionParams.Data.Data = 0i64;
        v30.FunctionParams.Data.Size = 0i64;
        v30.FunctionParams.Data.Policy.Capacity = 0i64;
        v30.pNextEntry = 0i64;
        v30.Type = 2;
        if ( v23 )
          ++v23->RefCount;
        if ( v30.pCharacter.pObject )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v30.pCharacter.pObject->vfptr);
        v30.pCharacter.pObject = v23;
        if ( v30.pActionBuffer.pObject )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v30.pActionBuffer.pObject->vfptr);
        v30.pActionBuffer.pObject = 0i64;
        *(_QWORD *)&v30.mEventId.Id = 0x40000i64;
        v30.mEventId.KeyCode = 0;
        v30.mEventId.AsciiCode = 0;
        *(_DWORD *)&v30.mEventId.RollOverCnt = 65280;
        v30.SessionId = 0;
        Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(
          &v30,
          (Scaleform::GFx::AS2::MovieRoot *)v10->pDispObj->pASRoot);
        Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(&v30);
        v24 = v10->pDispObj;
        v32.pCharacter.pObject = 0i64;
        v32.pActionBuffer.pObject = 0i64;
        *(_QWORD *)&v32.mEventId.Id = 0i64;
        v32.mEventId.KeyCode = 0;
        v32.mEventId.AsciiCode = 0;
        *(_DWORD *)&v32.mEventId.RollOverCnt = 65280;
        v32.Function.Flags = 0;
        v32.Function.Function = 0i64;
        v32.Function.pLocalFrame = 0i64;
        key.pStr = (Scaleform::GFx::ASString *)&v32.FunctionParams;
        v36 = &v32.FunctionParams;
        v32.FunctionParams.Data.Data = 0i64;
        v32.FunctionParams.Data.Size = 0i64;
        v32.FunctionParams.Data.Policy.Capacity = 0i64;
        v32.pNextEntry = 0i64;
        v32.Type = 3;
        if ( v24 )
          ++v24->RefCount;
        if ( v32.pCharacter.pObject )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v32.pCharacter.pObject->vfptr);
        v32.pCharacter.pObject = v24;
        if ( v32.pActionBuffer.pObject )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v32.pActionBuffer.pObject->vfptr);
        v32.pActionBuffer.pObject = 0i64;
        Scaleform::GFx::AS2::FunctionRefBase::Assign(
          (Scaleform::GFx::AS2::FunctionRefBase *)&v32.Function.Function,
          &orig);
        v32.SessionId = 0;
        Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(
          &v32,
          (Scaleform::GFx::AS2::MovieRoot *)v10->pDispObj->pASRoot);
        Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(&v32);
        v3 = orig.Flags;
        v5 = orig.pLocalFrame;
        goto LABEL_46;
      }
    }
LABEL_39:
    v25 = v10->pDispObj;
    v30.pCharacter.pObject = 0i64;
    v30.pActionBuffer.pObject = 0i64;
    *(_QWORD *)&v30.mEventId.Id = 0i64;
    v30.mEventId.KeyCode = 0;
    v30.mEventId.AsciiCode = 0;
    *(_DWORD *)&v30.mEventId.RollOverCnt = 65280;
    v30.Function.Flags = 0;
    v30.Function.Function = 0i64;
    v30.Function.pLocalFrame = 0i64;
    key.pStr = (Scaleform::GFx::ASString *)&v30.FunctionParams;
    v36 = &v30.FunctionParams;
    v30.FunctionParams.Data.Data = 0i64;
    v30.FunctionParams.Data.Size = 0i64;
    v30.FunctionParams.Data.Policy.Capacity = 0i64;
    v30.pNextEntry = 0i64;
    v30.Type = 2;
    if ( v25 )
      ++v25->RefCount;
    if ( v30.pCharacter.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v30.pCharacter.pObject->vfptr);
    v30.pCharacter.pObject = v25;
    if ( v30.pActionBuffer.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v30.pActionBuffer.pObject->vfptr);
    v30.pActionBuffer.pObject = 0i64;
    *(_QWORD *)&v30.mEventId.Id = 0x40000i64;
    v30.mEventId.KeyCode = 0;
    v30.mEventId.AsciiCode = 0;
    *(_DWORD *)&v30.mEventId.RollOverCnt = 65280;
    v30.SessionId = 0;
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(&v30, (Scaleform::GFx::AS2::MovieRoot *)v10->pDispObj->pASRoot);
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(&v30);
  }
LABEL_46:
  v26 = result.pNode;
  v27 = result.pNode->RefCount == 1;
  --v26->RefCount;
  if ( v27 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  if ( !(v3 & 2) )
  {
    if ( v4 )
    {
      v28 = v4->RefCount;
      if ( v28 & 0x3FFFFFF )
      {
        v4->RefCount = v28 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->vfptr);
      }
    }
  }
  orig.Function = 0i64;
  if ( !(v3 & 1) && v5 )
  {
    v29 = v5->RefCount;
    if ( v29 & 0x3FFFFFF )
    {
      v5->RefCount = v29 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
}

// File Line: 601
// RVA: 0x6FD2D0
void __fastcall Scaleform::GFx::AS2::AvmSprite::InitObjectMembers(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rbx
  Scaleform::RefCountNTSImpl *v3; // rbx
  unsigned int v4; // er10
  Scaleform::GFx::AS2::Environment *v5; // rdx
  Scaleform::GFx::AS2::Value *v6; // r9
  Scaleform::GFx::AS2::ObjectInterface *v7; // rax
  __int64 v8; // rcx
  void **v9; // [rsp+38h] [rbp-20h]
  __int64 v10; // [rsp+40h] [rbp-18h]
  Scaleform::RefCountNTSImpl *v11; // [rsp+48h] [rbp-10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(fn->ThisPtr) == 2 )
  {
    v3 = (Scaleform::RefCountNTSImpl *)v2[1].vfptr;
    if ( v3 )
      ++v3->RefCount;
  }
  else
  {
    v3 = 0i64;
  }
  if ( v3 )
  {
    v4 = v1->FirstArgBottomIndex;
    v5 = v1->Env;
    v6 = 0i64;
    if ( v4 <= 32 * ((unsigned int)v5->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
      v6 = &v5->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
    v7 = Scaleform::GFx::AS2::Value::ToObjectInterface(v6, v5);
    v8 = (__int64)v1->Env;
    v9 = (void **)`Scaleform::GFx::AS2::AvmSprite::InitObjectMembers'::`4'::InitVisitor::`vftable';
    v10 = v8;
    v11 = v3;
    v7->vfptr->VisitMembers(
      v7,
      (Scaleform::GFx::AS2::ASStringContext *)(v8 + 232),
      (Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *)&v9,
      0,
      0i64);
    v9 = &Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable';
  }
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
}

// File Line: 621
// RVA: 0x723740
void __fastcall Scaleform::GFx::AS2::AvmSprite::InitObjectMembers_::_4_::InitVisitor::Visit(Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, __int64 flags)
{
  Scaleform::GFx::ASStringNode *v3; // r9
  __int64 v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rsi
  Scaleform::GFx::ASString *v6; // rbx
  __int64 v7; // rax
  char v8; // [rsp+40h] [rbp+8h]

  v3 = name[2].pNode;
  v4 = flags;
  v5 = val;
  v6 = name;
  if ( v3 )
    v7 = (*(__int64 (__fastcall ***)(signed __int64))((char *)&v3->pData + 4 * BYTE1(v3[2].HashFlags)))[1]((signed __int64)v3 + 4 * BYTE1(v3[2].HashFlags));
  else
    v7 = 0i64;
  v8 = 0;
  (*(void (__fastcall **)(__int64, Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::Value *, __int64, char *))(*(_QWORD *)(v7 + 8) + 24i64))(
    v7 + 8,
    v6[1].pNode,
    v5,
    v4,
    &v8);
}

// File Line: 640
// RVA: 0x6D7F90
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::AS2::AvmSprite::AddDisplayObject(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::CharPosInfo *pos, Scaleform::GFx::ASString *name, Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *peventHandlers)
{
  Scaleform::GFx::CharPosInfo *v4; // r15
  Scaleform::GFx::AS2::AvmSprite *v5; // r14
  Scaleform::GFx::MovieDefImpl *v6; // r10
  int v7; // er12
  char v8; // di
  Scaleform::GFx::CharacterCreateInfo *v9; // rax
  unsigned __int64 v10; // rcx
  Scaleform::GFx::DisplayObjectBase *v12; // rbx
  int v13; // er13
  __int64 v14; // rdx
  Scaleform::GFx::ASString *v15; // rax
  char v16; // si
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rdi
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::Render::Cxform *v20; // rax
  unsigned __int64 v21; // r9
  __int64 v22; // rcx
  __int64 v23; // rax
  Scaleform::GFx::DisplayObjectBase *v24; // rsi
  __int16 v25; // dx
  Scaleform::GFx::Sprite *v26; // rbx
  Scaleform::GFx::DisplayObjectBase *i; // rdi
  Scaleform::Render::Rect<float> *v28; // rax
  unsigned int v29; // er13
  unsigned int v30; // er12
  char v31; // r15
  Scaleform::GFx::Sprite *v32; // rdi
  bool v33; // zf
  Scaleform::GFx::Sprite *v34; // rcx
  bool placeObject; // [rsp+34h] [rbp-8Dh]
  Scaleform::GFx::CharacterCreateInfo result; // [rsp+40h] [rbp-81h]
  Scaleform::GFx::CharPosInfo posa; // [rsp+58h] [rbp-69h]
  Scaleform::GFx::ResourceId rid[2]; // [rsp+108h] [rbp+47h]
  Scaleform::GFx::ASString *namea; // [rsp+118h] [rbp+57h]
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *peventHandlersa; // [rsp+120h] [rbp+5Fh]
  void *v41; // [rsp+128h] [rbp+67h]
  int vars0; // [rsp+130h] [rbp+6Fh]
  void *retaddr; // [rsp+138h] [rbp+77h]
  __int64 pisMarkedForRemove; // [rsp+140h] [rbp+7Fh]
  __int64 v45; // [rsp+148h] [rbp+87h]
  Scaleform::GFx::ASString *v46; // [rsp+150h] [rbp+8Fh]
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v47; // [rsp+158h] [rbp+97h]

  v47 = peventHandlers;
  v46 = name;
  result.pBindDefImpl = (Scaleform::GFx::MovieDefImpl *)-2i64;
  v4 = pos;
  v5 = this;
  v6 = *(Scaleform::GFx::MovieDefImpl **)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 176);
  v7 = (signed int)retaddr;
  v8 = ((unsigned int)retaddr >> 2) & 1;
  placeObject = ((unsigned int)retaddr >> 2) & 1;
  LOBYTE(retaddr) = (unsigned __int8)retaddr & 1;
  if ( pisMarkedForRemove )
  {
    result.pCharDef = *(Scaleform::GFx::CharacterDef **)pisMarkedForRemove;
    result.pBindDefImpl = *(Scaleform::GFx::MovieDefImpl **)(pisMarkedForRemove + 8);
    result.pResource = *(Scaleform::GFx::Resource **)(pisMarkedForRemove + 16);
    v9 = &result;
  }
  else
  {
    rid[0] = pos->CharacterId;
    v9 = Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(v6, &result, (Scaleform::GFx::ResourceId)rid);
  }
  *(_OWORD *)&posa.ColorTransform.M[1][0] = *(_OWORD *)&v9->pCharDef;
  *(_QWORD *)&posa.Matrix_1.M[0][0] = v9->pResource;
  v10 = v5[-1].InitActionsExecuted.Data.Policy.Capacity;
  if ( !*(_QWORD *)&posa.ColorTransform.M[1][0] )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)(v10 + 24),
      "Sprite::AddDisplayObject() - unknown cid = %d",
      LOWORD(v4->CharacterId.Id));
    return 0i64;
  }
  LOBYTE(pisMarkedForRemove) = 0;
  v12 = Scaleform::GFx::DisplayList::GetDisplayObjectAtDepth(
          (Scaleform::GFx::DisplayList *)(v10 + 216),
          v4->Depth,
          (bool *)&pisMarkedForRemove);
  v13 = vars0;
  if ( vars0 == -1 )
    v13 = (*(__int64 (**)(void))(*(_QWORD *)v5[-1].InitActionsExecuted.Data.Policy.Capacity + 856i64))();
  if ( !v8 )
  {
    LOBYTE(retaddr) = 1;
    goto LABEL_50;
  }
  if ( v12
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v12->vfptr[51].__vecDelDtor)(v12)
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v12->vfptr[52].__vecDelDtor)(v12) )
  {
    LOBYTE(v14) = 1;
    v12->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v12->vfptr, v14);
  }
  if ( (_BYTE)pisMarkedForRemove )
    goto LABEL_17;
  if ( !v12 )
  {
LABEL_50:
    _((AMD_HD3D *)v5[-1].InitActionsExecuted.Data.Policy.Capacity);
    v21 = v5[-1].InitActionsExecuted.Data.Policy.Capacity;
    v22 = *(_QWORD *)(*(_QWORD *)(v21 + 32) + 24i64);
    rid[0] = v4->CharacterId;
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
    for ( i = *(Scaleform::GFx::DisplayObjectBase **)(v23 + 56); i; i = i->pParentChar )
    {
      v28 = Scaleform::GFx::DisplayObjectBase::GetScale9Grid(i, (Scaleform::Render::Rect<float> *)&result);
      if ( v28->x2 > v28->x1 && v28->y2 > v28->y1 )
      {
        v24->Flags |= 1u;
        ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v24->vfptr[20].__vecDelDtor)(v24);
        break;
      }
    }
    if ( v26 )
    {
      if ( namea->pNode->Size )
      {
        Scaleform::GFx::DisplayObject::SetOriginalName((Scaleform::GFx::DisplayObject *)&v26->vfptr, namea);
        LOBYTE(rid[0].Id) = 1;
      }
      if ( v45 )
        ((void (__fastcall *)(Scaleform::GFx::Sprite *))v26->vfptr[94].__vecDelDtor)(v26);
      if ( v7 & 4 )
        v26->Flags |= 1u;
      else
        v26->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v26->vfptr, 0);
    }
    v24->CreateFrame = v13;
    v29 = 0;
    if ( v26 )
      v29 = Scaleform::GFx::AS2::AvmSprite::OnAddingDisplayObject(
              (Scaleform::GFx::AS2::AvmSprite *)((char *)v5 - 40),
              (Scaleform::GFx::CharacterCreateInfo *)posa.ColorTransform.M[1],
              (Scaleform::GFx::InteractiveObject *)&v26->vfptr,
              peventHandlersa,
              v41,
              placeObject);
    v30 = v7 & 0xFFFFFFFE;
    if ( (_BYTE)retaddr )
      v30 |= 1u;
    if ( v26 )
    {
      Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)&v26->vfptr);
      Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList((Scaleform::GFx::InteractiveObject *)&v26->vfptr);
    }
    Scaleform::GFx::DisplayList::AddDisplayObject(
      (Scaleform::GFx::DisplayList *)(v5[-1].InitActionsExecuted.Data.Policy.Capacity + 216),
      (Scaleform::GFx::DisplayObjectBase *)v5[-1].InitActionsExecuted.Data.Policy.Capacity,
      v4,
      v24,
      v30);
    v31 = rid[0].Id;
    if ( LOBYTE(rid[0].Id) )
      (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Sprite *))(**(_QWORD **)(v5[-1].InitActionsExecuted.Data.Policy.Capacity
                                                                             + 32)
                                                               + 312i64))(
        *(_QWORD *)(v5[-1].InitActionsExecuted.Data.Policy.Capacity + 32),
        v26);
    if ( !v26 )
      goto LABEL_86;
    v32 = 0i64;
    if ( (v26->Flags >> 10) & 1 )
      v32 = v26;
    if ( placeObject )
    {
      v33 = v32 == 0i64;
    }
    else
    {
      Scaleform::GFx::AS2::MovieRoot::DoActionsForSession(
        *(Scaleform::GFx::AS2::MovieRoot **)(v5[-1].InitActionsExecuted.Data.Policy.Capacity + 32),
        v29);
      if ( !v32 )
      {
LABEL_83:
        if ( v31 )
        {
          v34 = (Scaleform::GFx::Sprite *)v5[-1].InitActionsExecuted.Data.Policy.Capacity;
          if ( namea->pNode == *(Scaleform::GFx::ASStringNode **)&v34->pASRoot[34].AVMVersion )
            Scaleform::GFx::Sprite::SetHitArea(v34, v26);
        }
LABEL_86:
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v24->vfptr);
        return v24;
      }
      result.pCharDef = (Scaleform::GFx::CharacterDef *)1;
      LODWORD(result.pBindDefImpl) = 0;
      BYTE4(result.pBindDefImpl) = 0;
      LODWORD(result.pResource) = 65280;
      v33 = Scaleform::GFx::DisplayObject::HasEventHandler(
              (Scaleform::GFx::DisplayObject *)&v32->vfptr,
              (Scaleform::GFx::EventId *)&result) == 0;
    }
    if ( !v33 )
      v32->Flags |= 0x80u;
    goto LABEL_83;
  }
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v12->vfptr[51].__vecDelDtor)(v12) )
    return 0i64;
LABEL_17:
  if ( !v12 || v12->Depth < -1 || v12->Id.Id != v4->CharacterId.Id )
    goto LABEL_50;
  if ( SLOBYTE(v12->Flags) >= 0 )
  {
    v17 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)(v5[-1].InitActionsExecuted.Data.Policy.Capacity + 32) + 312i64);
    *(_QWORD *)&rid[0].Id = v17;
    ++v17->RefCount;
    v15 = (Scaleform::GFx::ASString *)rid;
    v16 = 2;
  }
  else
  {
    v15 = Scaleform::GFx::DisplayObject::GetOriginalName(
            (Scaleform::GFx::DisplayObject *)v12,
            (Scaleform::GFx::ASString *)&posa.ColorTransform.M[0][2]);
    v16 = 1;
    v17 = *(Scaleform::GFx::ASStringNode **)&rid[0].Id;
  }
  v18 = v15->pNode;
  *(_QWORD *)&rid[0].Id = v18;
  ++v18->RefCount;
  if ( v16 & 2 )
  {
    v16 &= 0xFDu;
    v33 = v17->RefCount-- == 1;
    if ( v33 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  }
  if ( v16 & 1 )
  {
    v19 = *(Scaleform::GFx::ASStringNode **)&posa.ColorTransform.M[0][2];
    v33 = *(_DWORD *)(*(_QWORD *)&posa.ColorTransform.M[0][2] + 24i64) == 1;
    --v19->RefCount;
    if ( v33 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
  if ( SLOBYTE(v12->Flags) < 0 )
  {
    if ( namea->pNode->Size )
    {
      if ( v18 != namea->pNode )
        goto LABEL_47;
    }
    else if ( v18->Size && !((LOBYTE(v12[1].vfptr) >> 1) & 1) )
    {
LABEL_47:
      v33 = v18->RefCount-- == 1;
      if ( v33 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      goto LABEL_50;
    }
  }
  if ( v12->CreateFrame != v13 )
  {
    LOBYTE(retaddr) = 1;
    goto LABEL_47;
  }
  Scaleform::GFx::CharPosInfo::CharPosInfo(&posa, v4);
  if ( SLOBYTE(v4->Flags.Flags) >= 0
    && ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v12->vfptr[15].__vecDelDtor)(v12) )
  {
    posa.Flags.Flags |= 0x80u;
    posa.BlendMode = 0;
  }
  if ( !((LOBYTE(v4->Flags.Flags) >> 3) & 1) )
  {
    v20 = Scaleform::GFx::DisplayObjectBase::GetCxform(v12);
    if ( !Scaleform::Render::Cxform::IsIdentity(v20) )
    {
      posa.Flags.Flags |= 8u;
      Scaleform::Render::Cxform::SetIdentity(&posa.ColorTransform);
    }
  }
  Scaleform::GFx::DisplayObjContainer::MoveDisplayObject(
    (Scaleform::GFx::DisplayObjContainer *)v5[-1].InitActionsExecuted.Data.Policy.Capacity,
    &posa);
  if ( posa.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)posa.pFilters.pObject);
  v33 = v18->RefCount-- == 1;
  if ( !v33 )
    return 0i64;
  Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  return 0i64;
}

// File Line: 841
// RVA: 0x704E10
__int64 __usercall Scaleform::GFx::AS2::AvmSprite::OnAddingDisplayObject@<rax>(Scaleform::GFx::AS2::AvmSprite *this@<rcx>, Scaleform::GFx::CharacterCreateInfo *ccinfo@<rdx>, Scaleform::GFx::InteractiveObject *pscriptCh@<r8>, Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *peventHandlers@<r9>, unsigned __int64 a5@<r12>)
{
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v5; // r14
  Scaleform::GFx::InteractiveObject *v6; // rdi
  Scaleform::GFx::CharacterCreateInfo *v7; // r13
  Scaleform::GFx::InteractiveObject *v8; // r15
  Scaleform::GFx::ASMovieRootBase *v9; // rax
  unsigned __int64 v10; // rsi
  Scaleform::GFx::ASMovieRootBase *v11; // r13
  Scaleform::GFx::AS2::MovieClipObject *v12; // rax
  Scaleform::GFx::SwfEvent *v13; // rax
  Scaleform::GFx::AS2::ActionBufferData *v14; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v15; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v16; // rbx
  Scaleform::RefCountNTSImpl *v17; // rcx
  Scaleform::RefCountNTSImpl *v18; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v19; // rsi
  Scaleform::GFx::AS2::FunctionObject *v20; // r14
  Scaleform::GFx::AS2::LocalFrame *v21; // r15
  Scaleform::GFx::MovieDefImpl *v22; // rax
  Scaleform::String *v23; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *v24; // r13
  int v25; // eax
  Scaleform::GFx::AS2::Environment *v26; // rax
  signed __int64 v27; // rbx
  __int64 v28; // r11
  __int64 v29; // rbx
  __int64 v30; // r10
  __int64 v31; // r8
  __int64 *v32; // r9
  Scaleform::GFx::ASStringNode *v33; // rdx
  signed __int64 v34; // rdx
  Scaleform::GFx::ASStringNode *v35; // rax
  signed __int64 v36; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v37; // rdx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v38; // rbx
  char v39; // si
  Scaleform::RefCountNTSImpl *v40; // rcx
  Scaleform::RefCountNTSImpl *v41; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v42; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v43; // rbx
  Scaleform::RefCountNTSImpl *v44; // rcx
  Scaleform::RefCountNTSImpl *v45; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v46; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v47; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v48; // rbx
  Scaleform::RefCountNTSImpl *v49; // rcx
  Scaleform::RefCountNTSImpl *v50; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v51; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v52; // rbx
  Scaleform::RefCountNTSImpl *v53; // rcx
  Scaleform::RefCountNTSImpl *v54; // rcx
  char v55; // bl
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v56; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v57; // rbx
  Scaleform::RefCountNTSImpl *v58; // rcx
  Scaleform::RefCountNTSImpl *v59; // rcx
  Scaleform::GFx::ASStringNode *v60; // rcx
  bool v61; // zf
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v62; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v63; // rbx
  Scaleform::RefCountNTSImpl *v64; // rcx
  Scaleform::RefCountNTSImpl *v65; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v66; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v67; // rbx
  Scaleform::RefCountNTSImpl *v68; // rcx
  Scaleform::RefCountNTSImpl *v69; // rcx
  unsigned int v70; // eax
  unsigned int v71; // edx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+0h] [rbp-79h]
  unsigned int v74; // [rsp+18h] [rbp-61h]
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-59h]
  Scaleform::GFx::ResourceId rid[2]; // [rsp+28h] [rbp-51h]
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS2::FunctionRefBase orig; // [rsp+50h] [rbp-29h]
  Scaleform::GFx::ASMovieRootBase *v79; // [rsp+68h] [rbp-11h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *v80; // [rsp+70h] [rbp-9h]
  volatile int v81; // [rsp+78h] [rbp-1h]
  __int64 v82; // [rsp+80h] [rbp+7h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *v83; // [rsp+D0h] [rbp+57h]
  Scaleform::GFx::CharacterCreateInfo *v84; // [rsp+D8h] [rbp+5Fh]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *v85; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::AS2::ObjectInterface *pobj; // [rsp+F0h] [rbp+77h]
  char vars0; // [rsp+F8h] [rbp+7Fh]

  v82 = -2i64;
  v5 = peventHandlers;
  v6 = pscriptCh;
  v7 = ccinfo;
  v8 = 0i64;
  if ( (pscriptCh->Flags >> 10) & 1 )
    v8 = pscriptCh;
  LOBYTE(v85) = 1;
  v9 = this->pDispObj->pASRoot;
  v79 = this->pDispObj->pASRoot;
  if ( peventHandlers )
  {
    v10 = 0i64;
    a5 = peventHandlers->Data.Size;
    if ( a5 )
    {
      v11 = v9;
      do
      {
        Scaleform::GFx::AS2::AvmSwfEvent::AttachTo((Scaleform::GFx::AS2::AvmSwfEvent *)&v5->Data.Data[v10]->Event, v6);
        if ( v8 )
        {
          if ( v5->Data.Data[v10]->Event.Id & 0xFBFC00 )
          {
            v12 = Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject((Scaleform::GFx::AS2::AvmSprite *)((char *)v8 + 4 * (unsigned __int8)v8->AvmObjOffset));
            if ( v12 )
              v12->HasButtonHandlers = 1;
          }
        }
        if ( vars0 )
        {
          v13 = v5->Data.Data[v10];
          if ( v13->Event.Id == 512 )
          {
            v14 = v13->pActionOpData.pObject;
            if ( v14 )
            {
              if ( v14->BufferLen >= 1 )
              {
                if ( *v14->pBuffer )
                {
                  v15 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                          (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v11[3].RefCount,
                          AP_Initialize);
                  v16 = v15;
                  if ( v15 )
                  {
                    v15->Type = 2;
                    ++v6->RefCount;
                    v17 = (Scaleform::RefCountNTSImpl *)&v15->pCharacter.pObject->vfptr;
                    if ( v17 )
                      Scaleform::RefCountNTSImpl::Release(v17);
                    v16->pCharacter.pObject = v6;
                    v18 = (Scaleform::RefCountNTSImpl *)&v16->pActionBuffer.pObject->vfptr;
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
        ++v10;
      }
      while ( v10 < a5 );
      v7 = v84;
      this = (Scaleform::GFx::AS2::AvmSprite *)v83;
    }
  }
  v19 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)((__int64 (*)(void))this->vfptr[1].OnUnloading)();
  orig.Flags = 0;
  v20 = 0i64;
  orig.Function = 0i64;
  v21 = 0i64;
  orig.pLocalFrame = 0i64;
  rid[0] = v7->pCharDef->Id;
  v22 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v6->vfptr[66].__vecDelDtor)(v6);
  v23 = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(v22, (Scaleform::GFx::ResourceId)rid);
  v24 = (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v79[3].RefCount;
  v81 = v79[7].RefCount;
  v25 = LODWORD(v79[7].pMovieImpl) + 1;
  v74 = v25;
  v24->LastSessionId = v25;
  v24->CurrentSessionId = v25;
  LOBYTE(a5) = 0;
  if ( !v23 )
  {
    v39 = orig.Flags;
    goto LABEL_96;
  }
  v26 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))v83->Data[7].V.FunctionValue.pLocalFrame)();
  Scaleform::GFx::AS2::Environment::CreateString(v26, &result, v23);
  v27 = (signed __int64)&v19[3];
  if ( *(_BYTE *)(((__int64 (*)(void))v83->Data[7].V.FunctionValue.pLocalFrame)() + 240) <= 6u )
  {
    *(_QWORD *)&rid[0].Id = &result;
    v35 = result.pNode;
    if ( !result.pNode->pLower )
    {
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(result.pNode);
      v35 = result.pNode;
    }
    if ( !*(_QWORD *)v27 )
      goto LABEL_80;
    v36 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
            v19 + 3,
            (Scaleform::GFx::ASString::NoCaseKey *)rid,
            v35->HashFlags & *(_QWORD *)(*(_QWORD *)v27 + 8i64));
    if ( v36 < 0 )
      goto LABEL_80;
    v34 = *(_QWORD *)v27 + 8 * (5 * v36 + 3);
  }
  else
  {
    v28 = *(_QWORD *)v27;
    if ( !*(_QWORD *)v27 )
      goto LABEL_80;
    v29 = *(_QWORD *)(v28 + 8);
    v30 = (unsigned int)v29 & result.pNode->HashFlags;
    v31 = v30;
    v32 = (__int64 *)(v28 + 8 * (v30 + 4 * v30 + 2));
    if ( *v32 == -2 || ((unsigned int)v29 & *(_DWORD *)(v32[1] + 28)) != v30 )
      goto LABEL_80;
    while ( 1 )
    {
      v33 = (Scaleform::GFx::ASStringNode *)v32[1];
      if ( ((unsigned int)v29 & v33->HashFlags) == v30 && v33 == result.pNode )
        break;
      v31 = *v32;
      if ( *v32 == -1 )
        goto LABEL_80;
      v32 = (__int64 *)(v28 + 8 * (v31 + 4 * v31 + 2));
    }
    if ( v31 < 0 )
      goto LABEL_80;
    v34 = v28 + 8 * (v31 + 4 * v31 + 3);
  }
  if ( v34 )
  {
    v37 = (Scaleform::GFx::AS2::FunctionRefBase *)(v34 + 8);
    if ( v37 )
    {
      Scaleform::GFx::AS2::FunctionRefBase::Assign(&orig, v37);
      v38 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(v24, AP_Initialize);
      v85 = &pheapAddr;
      pheapAddr.Data = 0i64;
      pheapAddr.Size = 0i64;
      pheapAddr.Policy.Capacity = 0i64;
      v.T.Type = 8;
      v.V.FunctionValue.Flags = 0;
      v20 = orig.Function;
      v.V.pStringNode = (Scaleform::GFx::ASStringNode *)orig.Function;
      if ( orig.Function )
        orig.Function->RefCount = (orig.Function->RefCount + 1) & 0x8FFFFFFF;
      v.V.FunctionValue.pLocalFrame = 0i64;
      v21 = orig.pLocalFrame;
      v39 = orig.Flags;
      if ( orig.pLocalFrame )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
          (Scaleform::GFx::AS2::FunctionRefBase *)&v.NV.8,
          orig.pLocalFrame,
          orig.Flags & 1);
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
      v85 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
      *(_QWORD *)&rid[0].Id = &pheapAddr.Data[pheapAddr.Size - 1];
      if ( v85 )
        Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v, (__int64)v6);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      if ( v38 )
      {
        v38->Type = 4;
        ++v6->RefCount;
        v40 = (Scaleform::RefCountNTSImpl *)&v38->pCharacter.pObject->vfptr;
        if ( v40 )
          Scaleform::RefCountNTSImpl::Release(v40);
        v38->pCharacter.pObject = v6;
        v41 = (Scaleform::RefCountNTSImpl *)&v38->pActionBuffer.pObject->vfptr;
        if ( v41 )
          Scaleform::RefCountNTSImpl::Release(v41);
        v38->pActionBuffer.pObject = 0i64;
        v38->CFunction = Scaleform::GFx::AS2::AvmSprite::InitializeClassInstance;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&v38->FunctionParams.Data,
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr,
          (__int64)v6,
          0i64,
          (__int64)v24,
          (__int64)v20,
          (__int64)v21);
      }
      v42 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(v24, AP_Construct);
      v43 = v42;
      if ( v42 )
      {
        v42->Type = 2;
        ++v6->RefCount;
        v44 = (Scaleform::RefCountNTSImpl *)&v42->pCharacter.pObject->vfptr;
        if ( v44 )
          Scaleform::RefCountNTSImpl::Release(v44);
        v43->pCharacter.pObject = v6;
        v45 = (Scaleform::RefCountNTSImpl *)&v43->pActionBuffer.pObject->vfptr;
        if ( v45 )
          Scaleform::RefCountNTSImpl::Release(v45);
        v43->pActionBuffer.pObject = 0i64;
        *(_QWORD *)&v43->mEventId.Id = 0x40000i64;
        v43->mEventId.KeyCode = 0;
        v43->mEventId.AsciiCode = 0;
        *(_DWORD *)&v43->mEventId.RollOverCnt = 65280;
      }
      LOBYTE(v85) = 0;
      if ( Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)v83[1].Data) >= 6 )
      {
        v46 = pobj;
        if ( pobj )
        {
          Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            (Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
            0i64);
          Scaleform::GFx::AS2::Value::SetAsObjectInterface(&v, v46);
          Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &pheapAddr,
            &pheapAddr,
            pheapAddr.Size + 1);
          *(_QWORD *)&rid[0].Id = &pheapAddr.Data[pheapAddr.Size - 1];
          v80 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
          if ( *(_QWORD *)&rid[0].Id )
            Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v, (__int64)v6);
          v47 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(v24, AP_Construct);
          v48 = v47;
          if ( v47 )
          {
            v47->Type = 4;
            ++v6->RefCount;
            v49 = (Scaleform::RefCountNTSImpl *)&v47->pCharacter.pObject->vfptr;
            if ( v49 )
              Scaleform::RefCountNTSImpl::Release(v49);
            v48->pCharacter.pObject = v6;
            v50 = (Scaleform::RefCountNTSImpl *)&v48->pActionBuffer.pObject->vfptr;
            if ( v50 )
              Scaleform::RefCountNTSImpl::Release(v50);
            v48->pActionBuffer.pObject = 0i64;
            v48->CFunction = Scaleform::GFx::AS2::AvmSprite::InitObjectMembers;
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
              (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&v48->FunctionParams.Data,
              (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr,
              (__int64)v6,
              0i64,
              (__int64)v24,
              (__int64)v20,
              (__int64)v21);
          }
          if ( v.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
      }
      LOBYTE(a5) = 1;
      v51 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(v24, AP_Construct);
      v52 = v51;
      if ( v51 )
      {
        v51->Type = 3;
        ++v6->RefCount;
        v53 = (Scaleform::RefCountNTSImpl *)&v51->pCharacter.pObject->vfptr;
        if ( v53 )
          Scaleform::RefCountNTSImpl::Release(v53);
        v52->pCharacter.pObject = v6;
        v54 = (Scaleform::RefCountNTSImpl *)&v52->pActionBuffer.pObject->vfptr;
        if ( v54 )
          Scaleform::RefCountNTSImpl::Release(v54);
        v52->pActionBuffer.pObject = 0i64;
        Scaleform::GFx::AS2::FunctionRefBase::Assign(
          (Scaleform::GFx::AS2::FunctionRefBase *)&v52->Function.Function,
          &orig);
      }
      v80 = &pheapAddr;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
      goto LABEL_93;
    }
  }
LABEL_80:
  if ( vars0 )
  {
    v85 = &pheapAddr;
    pheapAddr.Data = 0i64;
    *(_OWORD *)&pheapAddr.Size = 0ui64;
    v55 = 5;
    v.T.Type = 5;
    v.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
    ++v.V.pStringNode->RefCount;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    v85 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
    v80 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
    if ( v85 )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v, (__int64)v6);
      v55 = v.T.Type;
    }
    if ( (unsigned __int8)v55 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v56 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(v24, AP_Construct);
    v57 = v56;
    if ( v56 )
    {
      v56->Type = 4;
      ++v6->RefCount;
      v58 = (Scaleform::RefCountNTSImpl *)&v56->pCharacter.pObject->vfptr;
      if ( v58 )
        Scaleform::RefCountNTSImpl::Release(v58);
      v57->pCharacter.pObject = v6;
      v59 = (Scaleform::RefCountNTSImpl *)&v57->pActionBuffer.pObject->vfptr;
      if ( v59 )
        Scaleform::RefCountNTSImpl::Release(v59);
      v57->pActionBuffer.pObject = 0i64;
      v57->CFunction = Scaleform::GFx::AS2::AvmSprite::FindClassAndInitializeClassInstance;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&v57->FunctionParams.Data,
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr,
        (__int64)v6,
        a5,
        (__int64)v24,
        0i64,
        0i64);
    }
    LOBYTE(v85) = 0;
    v80 = &pheapAddr;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
  }
  v39 = orig.Flags;
LABEL_93:
  v60 = result.pNode;
  v61 = result.pNode->RefCount == 1;
  --v60->RefCount;
  if ( v61 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v60);
LABEL_96:
  if ( vars0 )
  {
    if ( (_BYTE)v85 )
    {
      v62 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(v24, AP_Construct);
      v63 = v62;
      if ( v62 )
      {
        v62->Type = 2;
        ++v6->RefCount;
        v64 = (Scaleform::RefCountNTSImpl *)&v62->pCharacter.pObject->vfptr;
        if ( v64 )
          Scaleform::RefCountNTSImpl::Release(v64);
        v63->pCharacter.pObject = v6;
        v65 = (Scaleform::RefCountNTSImpl *)&v63->pActionBuffer.pObject->vfptr;
        if ( v65 )
          Scaleform::RefCountNTSImpl::Release(v65);
        v63->pActionBuffer.pObject = 0i64;
        *(_QWORD *)&v63->mEventId.Id = 0x40000i64;
        v63->mEventId.KeyCode = 0;
        v63->mEventId.AsciiCode = 0;
        *(_DWORD *)&v63->mEventId.RollOverCnt = 65280;
      }
    }
  }
  else if ( !(_BYTE)a5
         && Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)v83[1].Data) >= 6
         && pobj )
  {
    v83 = &pheapAddr;
    pheapAddr.Data = 0i64;
    *(_OWORD *)&pheapAddr.Size = 0ui64;
    Scaleform::GFx::AS2::Value::SetAsObjectInterface(&v, pobj);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    v83 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
    v85 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
    if ( v83 )
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v, (__int64)v6);
    v66 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(v24, AP_Construct);
    v67 = v66;
    if ( v66 )
    {
      v66->Type = 4;
      ++v6->RefCount;
      v68 = (Scaleform::RefCountNTSImpl *)&v66->pCharacter.pObject->vfptr;
      if ( v68 )
        Scaleform::RefCountNTSImpl::Release(v68);
      v67->pCharacter.pObject = v6;
      v69 = (Scaleform::RefCountNTSImpl *)&v67->pActionBuffer.pObject->vfptr;
      if ( v69 )
        Scaleform::RefCountNTSImpl::Release(v69);
      v67->pActionBuffer.pObject = 0i64;
      v67->CFunction = Scaleform::GFx::AS2::AvmSprite::InitObjectMembers;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&v67->FunctionParams.Data,
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr,
        (__int64)v6,
        0i64,
        (__int64)v24,
        (__int64)v20,
        (__int64)v21);
    }
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v83 = &pheapAddr;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
  }
  v79[7].RefCount = v81;
  if ( !(v39 & 2) )
  {
    if ( v20 )
    {
      v70 = v20->RefCount;
      if ( v70 & 0x3FFFFFF )
      {
        v20->RefCount = v70 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v20->vfptr);
      }
    }
  }
  orig.Function = 0i64;
  if ( !(v39 & 1) )
  {
    if ( v21 )
    {
      v71 = v21->RefCount;
      if ( v71 & 0x3FFFFFF )
      {
        v21->RefCount = v71 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v21->vfptr);
      }
    }
  }
  return v74;
}

// File Line: 1014
// RVA: 0x6DA3C0
void __fastcall Scaleform::GFx::AS2::AvmSprite::AdvanceFrame(Scaleform::GFx::AS2::AvmSprite *this, bool nextFrame, float framePos)
{
  Scaleform::GFx::AS2::AvmSprite *v3; // rsi
  Scaleform::GFx::Sprite *v4; // rdi
  unsigned int v5; // er14
  unsigned int v6; // ebx
  Scaleform::GFx::AS2::MovieClipObject *v7; // rax
  __int64 v8; // [rsp+28h] [rbp-18h]
  int v9; // [rsp+30h] [rbp-10h]
  char v10; // [rsp+34h] [rbp-Ch]
  int v11; // [rsp+38h] [rbp-8h]

  v3 = this;
  v4 = (Scaleform::GFx::Sprite *)this[-1].InitActionsExecuted.Data.Policy.Capacity;
  if ( v4 )
    ++v4->RefCount;
  if ( !(v4->Flags & 0xC) && !(v4->Flags & 0x1000) && v4->Depth >= -1 && nextFrame )
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))v4->vfptr[107].__vecDelDtor)(v4);
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::Sprite *))v4->vfptr[115].__vecDelDtor)(v4)
      || (v6 = v5,
          Scaleform::GFx::Sprite::IncrementFrameAndCheckForLoop(v4),
          v5 = ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))v4->vfptr[107].__vecDelDtor)(v4),
          v5 == v6) )
    {
      v9 = 0;
      v10 = 0;
      v7 = v3[-1].ASMovieClipObj.pObject;
      v8 = 2i64;
      v11 = 65280;
      ((void (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::MovieClipObject> *, __int64 *))v7->ResolveHandler.pLocalFrame)(
        &v3[-1].ASMovieClipObj,
        &v8);
    }
    else
    {
      ((void (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, _QWORD))v3->vfptr[2].ToAvmTextFieldBase)(v3, v5);
      v8 = 2i64;
      v9 = 0;
      v10 = 0;
      v11 = 65280;
      ((void (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::MovieClipObject> *, __int64 *))v3[-1].ASMovieClipObj.pObject->ResolveHandler.pLocalFrame)(
        &v3[-1].ASMovieClipObj,
        &v8);
      Scaleform::GFx::Sprite::ExecuteFrameTags(v4, v5);
    }
    if ( !v5 )
      Scaleform::GFx::DisplayList::UnloadMarkedObjects(
        (Scaleform::GFx::DisplayList *)(v3[-1].InitActionsExecuted.Data.Policy.Capacity + 216),
        (Scaleform::GFx::DisplayObjectBase *)v3[-1].InitActionsExecuted.Data.Policy.Capacity);
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
}

// File Line: 1123
// RVA: 0x6F5F50
bool __fastcall Scaleform::GFx::AS2::AvmSprite::GetStandardMember(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::AS2::AvmCharacter::StandardMember member, Scaleform::GFx::AS2::Value *pval, bool opcodeFlag)
{
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::AS2::AvmCharacter::StandardMember v5; // esi
  Scaleform::GFx::AS2::AvmSprite *v6; // rbx
  int v7; // eax
  bool v8; // al
  unsigned int v9; // eax
  unsigned int v10; // eax
  char v11; // cl
  bool v12; // bl
  Scaleform::GFx::AS2::Value *v13; // rcx
  char v14; // al
  bool v15; // bl
  Scaleform::GFx::CharacterHandle *v16; // rdx
  __int64 v17; // rax
  Scaleform::GFx::AS2::Environment *v18; // rsi
  __int64 v19; // rcx
  Scaleform::GFx::AS2::RectangleObject *v20; // rax
  Scaleform::GFx::AS2::RectangleObject *v21; // rax
  Scaleform::GFx::AS2::RectangleObject *v22; // rbx
  unsigned int v23; // eax
  Scaleform::GFx::InteractiveObject *v24; // rax
  double *v25; // rax
  double v26; // xmm6_8
  double v27; // xmm7_8
  double v28; // xmm8_8
  double v29; // xmm9_8
  __int64 v30; // rax
  Scaleform::GFx::AS2::Environment *v31; // rsi
  __int64 v32; // rcx
  Scaleform::GFx::AS2::RectangleObject *v33; // rax
  Scaleform::GFx::AS2::RectangleObject *v34; // rax
  Scaleform::Render::Rect<float> result; // [rsp+40h] [rbp-78h]
  Scaleform::Render::Rect<double> r; // [rsp+50h] [rbp-68h]

  v4 = pval;
  v5 = member;
  v6 = this;
  if ( Scaleform::GFx::AS2::AvmCharacter::GetStandardMember(
         (Scaleform::GFx::AS2::AvmCharacter *)&this->vfptr,
         member,
         pval,
         opcodeFlag) )
  {
    return 1;
  }
  switch ( v5 )
  {
    case 4u:
      v7 = (__int64)v6->pDispObj->vfptr[107].__vecDelDtor(
                      (Scaleform::RefCountNTSImplCore *)&v6->pDispObj->vfptr,
                      1073741824u);
      Scaleform::GFx::AS2::Value::SetInt(v4, v7 + 1);
      return 1;
    case 5u:
      v9 = (__int64)v6->pDispObj[1].pParent->vfptr[10].__vecDelDtor(
                      (Scaleform::RefCountNTSImplCore *)&v6->pDispObj[1].pParent->vfptr,
                      1073741824u);
      Scaleform::GFx::AS2::Value::SetInt(v4, v9);
      return 1;
    case 0xCu:
      v10 = (__int64)v6->pDispObj->vfptr[111].__vecDelDtor(
                       (Scaleform::RefCountNTSImplCore *)&v6->pDispObj->vfptr,
                       1073741824u);
      Scaleform::GFx::AS2::Value::SetInt(v4, v10);
      return 1;
    case 0x1Cu:
      LOBYTE(v6) = LOBYTE(v6->pDispObj[1].pIndXFormData) >> 5;
      goto LABEL_8;
    case 0x22u:
      v11 = BYTE1(v6->pDispObj[1].pIndXFormData);
      if ( !v11 )
        goto LABEL_11;
      v12 = v11 == 1;
      Scaleform::GFx::AS2::Value::DropRefs(v4);
      v4->T.Type = 2;
      v4->V.BooleanValue = v12;
      return 1;
    case 0x23u:
      v14 = v6->TabChildren.Value;
      v13 = v4;
      if ( !v14 )
        goto LABEL_12;
      v15 = v14 == 1;
      Scaleform::GFx::AS2::Value::DropRefs(v4);
      v4->T.Type = 2;
      v4->V.BooleanValue = v15;
      return 1;
    case 0x25u:
      if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, signed __int64))v6->vfptr[2].ToAvmDispContainerBase)(
                        v6,
                        5368709120i64)
                    + 240) < 8u )
        goto LABEL_36;
      if ( !Scaleform::GFx::DisplayObjectBase::HasScale9Grid((Scaleform::GFx::DisplayObjectBase *)&v6->pDispObj->vfptr) )
        goto LABEL_11;
      Scaleform::GFx::DisplayObjectBase::GetScale9Grid(
        (Scaleform::GFx::DisplayObjectBase *)&v6->pDispObj->vfptr,
        &result);
      v17 = (__int64)v6->vfptr[2].ToAvmDispContainerBase((Scaleform::GFx::AvmDisplayObjBase *)&v6->vfptr);
      v18 = (Scaleform::GFx::AS2::Environment *)v17;
      v20 = (Scaleform::GFx::AS2::RectangleObject *)(*(__int64 (__fastcall **)(__int64, signed __int64))(**(_QWORD **)(*(_QWORD *)(v17 + 232) + 48i64) + 80i64))(
                                                      v19,
                                                      96i64);
      if ( v20 )
      {
        Scaleform::GFx::AS2::RectangleObject::RectangleObject(v20, v18);
        v22 = v21;
      }
      else
      {
        v22 = 0i64;
      }
      r.x1 = (float)(result.x1 * 0.050000001);
      r.y1 = (float)(result.y1 * 0.050000001);
      r.x2 = (float)(result.x2 * 0.050000001);
      r.y2 = (float)(result.y2 * 0.050000001);
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v22, v18, &r);
      Scaleform::GFx::AS2::Value::SetAsObject(v4, (Scaleform::GFx::AS2::Object *)&v22->vfptr);
      goto LABEL_25;
    case 0x26u:
      v16 = (Scaleform::GFx::CharacterHandle *)v6->pDispObj[1].pGeomData;
      if ( v16 )
      {
        Scaleform::GFx::AS2::Value::SetAsCharacterHandle(v4, v16);
        v8 = 1;
      }
      else
      {
        Scaleform::GFx::AS2::Value::DropRefs(v4);
        v4->T.Type = 0;
LABEL_36:
        v8 = 0;
      }
      break;
    case 0x27u:
      if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, signed __int64))v6->vfptr[2].ToAvmDispContainerBase)(
                        v6,
                        5368709120i64)
                    + 240) < 8u )
        goto LABEL_36;
      v24 = v6->pDispObj;
      if ( v24->pScrollRect )
      {
        v25 = &v24->pScrollRect->Rectangle.x1;
        v26 = v25[3];
        v27 = v25[2];
        v28 = v25[1];
        v29 = *v25;
        v30 = (__int64)v6->vfptr[2].ToAvmDispContainerBase((Scaleform::GFx::AvmDisplayObjBase *)&v6->vfptr);
        v31 = (Scaleform::GFx::AS2::Environment *)v30;
        v33 = (Scaleform::GFx::AS2::RectangleObject *)(*(__int64 (__fastcall **)(__int64, signed __int64))(**(_QWORD **)(*(_QWORD *)(v30 + 232) + 48i64) + 80i64))(
                                                        v32,
                                                        96i64);
        if ( v33 )
        {
          Scaleform::GFx::AS2::RectangleObject::RectangleObject(v33, v31);
          v22 = v34;
        }
        else
        {
          v22 = 0i64;
        }
        r.x1 = v29 * 0.05;
        r.y1 = v28 * 0.05;
        r.x2 = v27 * 0.05;
        r.y2 = v26 * 0.05;
        Scaleform::GFx::AS2::RectangleObject::SetProperties(v22, v31, &r);
        Scaleform::GFx::AS2::Value::SetAsObject(v4, (Scaleform::GFx::AS2::Object *)&v22->vfptr);
LABEL_25:
        if ( v22 )
        {
          v23 = v22->RefCount;
          if ( v23 & 0x3FFFFFF )
          {
            v22->RefCount = v23 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v22->vfptr);
          }
        }
      }
      else
      {
LABEL_11:
        v13 = v4;
LABEL_12:
        Scaleform::GFx::AS2::Value::DropRefs(v13);
        v4->T.Type = 0;
      }
      return 1;
    case 0x47u:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, signed __int64))v6->vfptr[2].ToAvmDispContainerBase)(
                                    v6,
                                    5368709120i64)
                                + 232)
                    + 104i64) != 1 )
        goto LABEL_36;
      LODWORD(v6) = v6->pDispObj->Flags >> 11;
LABEL_8:
      Scaleform::GFx::AS2::Value::DropRefs(v4);
      v4->T.Type = 2;
      v4->V.BooleanValue = (unsigned __int8)v6 & 1;
      return 1;
    default:
      goto LABEL_36;
  }
  return v8;
}

// File Line: 1257
// RVA: 0x71BE60
__int64 __fastcall Scaleform::GFx::AS2::AvmSprite::SetStandardMember(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::AS2::AvmCharacter::StandardMember member, Scaleform::GFx::AS2::Value *origVal, bool opcodeFlag)
{
  bool v4; // r14
  __int64 v5; // rbx
  Scaleform::GFx::AS2::AvmSprite *v6; // rdi
  Scaleform::GFx::AS2::Environment *v7; // rax
  Scaleform::GFx::AS2::Environment *v8; // rsi
  Scaleform::GFx::AS2::MovieClipObject *v9; // rcx
  Scaleform::GFx::ASString *v10; // rax
  __int64 v11; // rsi
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::InteractiveObject *v14; // rbx
  Scaleform::GFx::AS2::Environment *v15; // rax
  char v16; // al
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
  Scaleform::GFx::AS2::Environment *v28; // rax
  Scaleform::GFx::AS2::Environment *v29; // rsi
  Scaleform::GFx::AS2::Object *v30; // rax
  Scaleform::GFx::AS2::RectangleObject *v31; // rbx
  float v32; // xmm1_4
  Scaleform::GFx::InteractiveObject *v33; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *v34; // rax
  double *v35; // rdx
  Scaleform::GFx::AS2::Environment *v36; // rax
  Scaleform::GFx::AS2::Environment *v37; // rsi
  Scaleform::GFx::AS2::Object *v38; // rax
  Scaleform::GFx::AS2::RectangleObject *v39; // rbx
  Scaleform::Render::Rect<double> *v40; // rdx
  unsigned __int8 v41; // bl
  double v43; // [rsp+28h] [rbp-29h]
  long double v44; // [rsp+30h] [rbp-21h]
  double v45; // [rsp+38h] [rbp-19h]
  double v46; // [rsp+40h] [rbp-11h]
  __int128 v47; // [rsp+48h] [rbp-9h]
  Scaleform::GFx::AS2::Value newVal; // [rsp+58h] [rbp+7h]
  Scaleform::GFx::AS2::Value v; // [rsp+78h] [rbp+27h]
  Scaleform::GFx::ASString result; // [rsp+B8h] [rbp+67h]

  v4 = opcodeFlag;
  v5 = (signed int)member;
  v6 = this;
  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)((char *)&newVal + 24), origVal, (__int64)this);
  v7 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v6->vfptr[2].GetAbsolutePath)(v6);
  v8 = v7;
  if ( (signed int)v5 > 21 )
  {
    if ( v7 )
    {
      v9 = v6->ASMovieClipObj.pObject;
      if ( v9 )
      {
        if ( v9->pWatchpoints )
        {
          v.T.Type = 0;
          v10 = Scaleform::GFx::AS2::Environment::CreateConstString(
                  v7,
                  &result,
                  Scaleform::GFx::AS2::AvmCharacter::MemberTable[v5].pName);
          v11 = (unsigned __int8)Scaleform::GFx::AS2::Object::InvokeWatchpoint(
                                   (Scaleform::GFx::AS2::Object *)&v6->ASMovieClipObj.pObject->vfptr,
                                   v8,
                                   v10,
                                   &newVal,
                                   &v);
          v12 = result.pNode;
          v13 = result.pNode->RefCount == 1;
          --v12->RefCount;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v12);
          if ( (_BYTE)v11 )
            Scaleform::GFx::AS2::Value::operator=(&newVal, &v, (__int64)v6);
          if ( v.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
      }
    }
  }
  if ( Scaleform::GFx::AS2::AvmCharacter::SetStandardMember(
         (Scaleform::GFx::AS2::AvmCharacter *)&v6->vfptr,
         (Scaleform::GFx::AS2::AvmCharacter::StandardMember)v5,
         &newVal,
         v4) )
  {
$LN238:
    v41 = 1;
  }
  else
  {
    switch ( (_DWORD)v5 )
    {
      case 4:
      case 5:
      case 0xC:
        goto $LN238;
      case 0x1C:
        v14 = v6->pDispObj;
        v15 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v6->vfptr[2].GetAbsolutePath)(v6);
        v13 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v15) == 0;
        v16 = (char)v14[1].pIndXFormData;
        if ( v13 )
          v17 = v16 & 0xDF;
        else
          v17 = v16 | 0x20;
        LOBYTE(v14[1].pIndXFormData) = v17;
        goto $LN238;
      case 0x22:
        if ( newVal.T.Type && newVal.T.Type != 10 )
        {
          v18 = v6->pDispObj;
          v19 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v6->vfptr[2].GetAbsolutePath)(v6);
          BYTE1(v18[1].pIndXFormData) = (Scaleform::GFx::AS2::Value::ToBool(&newVal, v19) == 0) + 1;
        }
        else
        {
          BYTE1(v6->pDispObj[1].pIndXFormData) = 0;
        }
        goto $LN238;
      case 0x23:
        if ( newVal.T.Type && newVal.T.Type != 10 )
        {
          v20 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v6->vfptr[2].GetAbsolutePath)(v6);
          v21 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v20);
          v6->TabChildren.Value = (v21 == 0) + 1;
          v22 = v6->pDispObj;
          if ( v21 )
            v22->Flags &= 0xFFFF7FFF;
          else
            v22->Flags |= 0x8000u;
        }
        else
        {
          v6->TabChildren.Value = 0;
        }
        goto $LN238;
      case 0x25:
        if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v6->vfptr[2].GetAbsolutePath)(v6)
                      + 240) < 8u )
          goto LABEL_52;
        v28 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v6->vfptr[2].GetAbsolutePath)(v6);
        v29 = v28;
        v30 = Scaleform::GFx::AS2::Value::ToObject(&newVal, v28);
        v31 = (Scaleform::GFx::AS2::RectangleObject *)v30;
        if ( v30 && (*(unsigned int (**)(void))&v30->vfptr->gap8[8])() == 17 )
        {
          *(_OWORD *)&v.T.Type = 0ui64;
          *((_OWORD *)&v.NV + 1) = 0ui64;
          Scaleform::GFx::AS2::RectangleObject::GetProperties(v31, v29, (Scaleform::Render::Rect<double> *)&v);
          *(float *)&v43 = (float)*(double *)&v.T.Type * 20.0;
          *((float *)&v43 + 1) = (float)v.NV.NumberValue * 20.0;
          v32 = *((double *)&v.NV + 2) - *(double *)&v.T.Type;
          *(float *)&v44 = (float)(v32 * 20.0) + *(float *)&v43;
          *((float *)&v44 + 1) = (float)((float)(*((double *)&v.NV + 3) - v.NV.NumberValue) * 20.0)
                               + *((float *)&v43 + 1);
          v33 = v6->pDispObj;
          v34 = v33->vfptr;
          v35 = &v43;
        }
        else
        {
          v33 = v6->pDispObj;
          v47 = 0i64;
          v34 = v33->vfptr;
          v35 = (double *)&v47;
        }
        v34[19].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v33->vfptr, (unsigned int)v35);
        goto $LN238;
      case 0x26:
        v25 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v6->vfptr[2].GetAbsolutePath)(v6);
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
                if ( SLOBYTE(v26->Flags) < 0 )
                  v27 = (Scaleform::GFx::Sprite *)v26;
                if ( v27 && (v27->Flags >> 10) & 1 )
                {
                  Scaleform::GFx::Sprite::SetHitArea((Scaleform::GFx::Sprite *)v6->pDispObj, v27);
                  goto $LN238;
                }
              }
            }
          }
        }
        Scaleform::GFx::Sprite::SetHitArea((Scaleform::GFx::Sprite *)v6->pDispObj, 0i64);
        goto LABEL_52;
      case 0x27:
        if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v6->vfptr[2].GetAbsolutePath)(v6)
                      + 240) < 8u )
          goto LABEL_52;
        v36 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v6->vfptr[2].GetAbsolutePath)(v6);
        v37 = v36;
        v38 = Scaleform::GFx::AS2::Value::ToObject(&newVal, v36);
        v39 = (Scaleform::GFx::AS2::RectangleObject *)v38;
        if ( v38 )
        {
          if ( (*(unsigned int (**)(void))&v38->vfptr->gap8[8])() != 17 )
            goto LABEL_52;
          *(_OWORD *)&v.T.Type = 0ui64;
          *((_OWORD *)&v.NV + 1) = 0ui64;
          Scaleform::GFx::AS2::RectangleObject::GetProperties(v39, v37, (Scaleform::Render::Rect<double> *)&v);
          v43 = *(double *)&v.T.Type * 20.0;
          v44 = v.NV.NumberValue * 20.0;
          v45 = (*((double *)&v.NV + 2) - *(double *)&v.T.Type) * 20.0 + *(double *)&v.T.Type * 20.0;
          v46 = (*((double *)&v.NV + 3) - v.NV.NumberValue) * 20.0 + v.NV.NumberValue * 20.0;
          v40 = (Scaleform::Render::Rect<double> *)&v43;
        }
        else
        {
          v40 = 0i64;
        }
        Scaleform::GFx::DisplayObject::SetScrollRect((Scaleform::GFx::DisplayObject *)&v6->pDispObj->vfptr, v40);
LABEL_52:
        v41 = 0;
        break;
      case 0x47:
        if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v6->vfptr[2].GetAbsolutePath)(v6)
                                  + 232)
                      + 104i64) != 1 )
          goto LABEL_52;
        v23 = v6->pDispObj;
        v24 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v6->vfptr[2].GetAbsolutePath)(v6);
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v24) )
          v23->Flags |= 0x800u;
        else
          v23->Flags &= 0xFFFFF7FF;
        goto $LN238;
      default:
        goto LABEL_52;
    }
  }
  if ( newVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&newVal);
  return v41;
}

// File Line: 1426
// RVA: 0x719AC0
bool __fastcall Scaleform::GFx::AS2::AvmSprite::SetMemberRaw(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v5; // rbp
  Scaleform::GFx::ASString *v6; // rdi
  Scaleform::GFx::AS2::ASStringContext *v7; // r14
  Scaleform::GFx::AS2::AvmSprite *v8; // rsi
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  unsigned int v11; // eax
  Scaleform::GFx::AS2::MovieClipObject *v12; // rax
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h]

  v5 = val;
  v6 = name;
  v7 = psc;
  v8 = this;
  if ( !((name->pNode->HashFlags >> 29) & 1) )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&name->pNode)
      || Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&v6->pNode, 0) != 95 )
    {
      goto LABEL_11;
    }
    Scaleform::GFx::ASString::ToLower(v6, &result);
    v9 = result.pNode;
    if ( !((result.pNode->HashFlags >> 28) & 1) )
    {
      v10 = result.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      goto LABEL_11;
    }
    v10 = result.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  v11 = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
          (Scaleform::GFx::AS2::AvmCharacter *)&v8[-1].TabChildren,
          v6);
  if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::Bool3W *, _QWORD, Scaleform::GFx::AS2::Value *, _QWORD))(*(_QWORD *)&v8[-1].TabChildren.Value + 272i64))(
         &v8[-1].TabChildren,
         v11,
         v5,
         0i64) )
  {
    LOBYTE(v12) = 1;
    return (char)v12;
  }
LABEL_11:
  if ( *(_QWORD *)&v8->Level
    || (v12 = Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject((Scaleform::GFx::AS2::AvmSprite *)((char *)v8 - 8))) != 0i64 )
  {
    LOBYTE(v12) = (*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)(*(_QWORD *)&v8->Level + 32i64) + 80i64))(
                    *(_QWORD *)&v8->Level + 32i64,
                    v7,
                    v6,
                    v5,
                    flags);
  }
  return (char)v12;
}

// File Line: 1447
// RVA: 0x6F01A0
bool __usercall Scaleform::GFx::AS2::AvmSprite::GetMember@<al>(Scaleform::GFx::AS2::AvmSprite *this@<rcx>, Scaleform::GFx::AS2::Environment *penv@<rdx>, Scaleform::GFx::AS2::ASStringContext *psc@<r8>, Scaleform::GFx::ASString *name@<r9>, long double a5@<xmm0>)
{
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::AS2::ASStringContext *v6; // r15
  Scaleform::GFx::AS2::Environment *v7; // r14
  Scaleform::GFx::AS2::AvmSprite *v8; // rdi
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  __int64 v11; // r13
  bool v12; // al
  Scaleform::GFx::AS2::Environment *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  float *v16; // rax
  __int128 v17; // xmm11
  __int128 v18; // xmm10
  __int128 v19; // xmm9
  __int128 v20; // xmm8
  __int128 v21; // xmm7
  __int128 v22; // xmm6
  float v23; // xmm4_4
  int v24; // xmm3_4
  int v25; // xmm2_4
  unsigned int v26; // xmm1_4
  unsigned int v27; // xmm0_4
  __int64 v28; // rcx
  Scaleform::GFx::AS2::ArrayObject *v29; // r14
  int v30; // ebx
  Scaleform::GFx::AS2::Environment *v31; // rax
  Scaleform::GFx::AS2::ArrayObject *v32; // rax
  Scaleform::GFx::AS2::ArrayObject *v33; // r14
  Scaleform::Render::Matrix4x4<float> *v34; // rdi
  unsigned int v35; // eax
  Scaleform::GFx::AS2::MovieClipObject *v36; // rcx
  char v37; // r12
  Scaleform::GFx::AS2::Object *v38; // rcx
  unsigned int v39; // eax
  Scaleform::GFx::ASStringNode *v40; // rcx
  unsigned int v41; // eax
  unsigned int v42; // eax
  Scaleform::GFx::DisplayObject *v43; // rax
  Scaleform::GFx::AS2::Object *v44; // r13
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> v45; // [rsp+20h] [rbp-B8h]
  Scaleform::GFx::AS2::ArrayObject *v46; // [rsp+28h] [rbp-B0h]
  Scaleform::GFx::AS2::Value val; // [rsp+30h] [rbp-A8h]
  __int64 v48; // [rsp+50h] [rbp-88h]
  int v49; // [rsp+58h] [rbp-80h]
  int v50; // [rsp+5Ch] [rbp-7Ch]
  Scaleform::Render::Matrix4x4<float> v51; // [rsp+60h] [rbp-78h]
  Scaleform::GFx::ASString result; // [rsp+130h] [rbp+58h]
  Scaleform::GFx::AS2::Value *retaddr; // [rsp+138h] [rbp+60h]

  *(_QWORD *)&v51.M[1][2] = -2i64;
  v5 = name;
  v6 = psc;
  v7 = penv;
  v8 = this;
  if ( !((name->pNode->HashFlags >> 29) & 1) )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&name->pNode)
      || Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&v5->pNode, 0) != 95 )
    {
      goto LABEL_31;
    }
    Scaleform::GFx::ASString::ToLower(v5, &result);
    v9 = result.pNode;
    if ( !((result.pNode->HashFlags >> 28) & 1) )
    {
      v10 = result.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      goto LABEL_31;
    }
    v10 = result.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  v11 = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
          (Scaleform::GFx::AS2::AvmCharacter *)&v8->vfptr,
          v5);
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, __int64, Scaleform::GFx::AS2::Value *, _QWORD))v8->vfptr[2].OnUnloading)(
         v8,
         v11,
         retaddr,
         0i64) )
  {
    return 1;
  }
  switch ( (_DWORD)v11 )
  {
    case 0x24:
      Scaleform::GFx::AS2::Value::DropRefs(retaddr);
      retaddr->T.Type = 0;
      return 1;
    case 0x6F:
      v8->pDispObj->vfptr[26].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->pDispObj->vfptr, 1073741824u);
      Scaleform::GFx::AS2::Value::SetNumber(retaddr, a5);
      return 1;
    case 0x70:
      v8->pDispObj->vfptr[32].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->pDispObj->vfptr, 1073741824u);
      Scaleform::GFx::AS2::Value::SetNumber(retaddr, a5);
      return 1;
    case 0x71:
      v8->pDispObj->vfptr[36].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->pDispObj->vfptr, 1073741824u);
      Scaleform::GFx::AS2::Value::SetNumber(retaddr, a5);
      return 1;
    case 0x72:
      v8->pDispObj->vfptr[38].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->pDispObj->vfptr, 1073741824u);
      Scaleform::GFx::AS2::Value::SetNumber(retaddr, a5);
      return 1;
    case 0x73:
      v16 = (float *)v8->pDispObj->vfptr[4].__vecDelDtor(
                       (Scaleform::RefCountNTSImplCore *)&v8->pDispObj->vfptr,
                       1073741824u);
      v17 = *(unsigned int *)v16;
      v18 = *((unsigned int *)v16 + 1);
      v19 = *((unsigned int *)v16 + 2);
      v20 = *((unsigned int *)v16 + 3);
      v21 = *((unsigned int *)v16 + 4);
      v22 = *((unsigned int *)v16 + 5);
      v23 = v16[7];
      v24 = *((_DWORD *)v16 + 8);
      v25 = *((_DWORD *)v16 + 9);
      v26 = *((_DWORD *)v16 + 10);
      v27 = *((_DWORD *)v16 + 11);
      v51.M[1][2] = v16[6];
      v51.M[1][3] = v23;
      v49 = v24;
      v50 = v25;
      *(_QWORD *)&v51.M[0][0] = __PAIR__(v27, v26);
      *(_OWORD *)&v51.M[0][2] = _xmm;
      Scaleform::Render::Matrix4x4<float>::Transpose(&v51);
      v45.pObject = (Scaleform::GFx::AS2::Object *)v7->StringContext.pContext->pHeap;
      v29 = (Scaleform::GFx::AS2::ArrayObject *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))v45.pObject->vfptr[3].Finalize_GC)(
                                                  v28,
                                                  144i64,
                                                  0i64);
      v46 = v29;
      v30 = 0;
      if ( v29 )
      {
        v31 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v8->vfptr[2].GetAbsolutePath)(v8);
        Scaleform::GFx::AS2::ArrayObject::ArrayObject(v29, v31);
        v33 = v32;
      }
      else
      {
        v33 = 0i64;
      }
      v46 = v33;
      Scaleform::GFx::AS2::ArrayObject::Resize(v33, 16);
      v34 = &v51;
      do
      {
        val.T.Type = 3;
        val.NV.NumberValue = v34->M[0][0];
        Scaleform::GFx::AS2::ArrayObject::SetElement(v33, v30, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        ++v30;
        v34 = (Scaleform::Render::Matrix4x4<float> *)((char *)v34 + 4);
      }
      while ( v30 < 16 );
      Scaleform::GFx::AS2::Value::SetAsObject(retaddr, (Scaleform::GFx::AS2::Object *)&v33->vfptr);
      if ( !v33 )
        return 1;
      v35 = v33->RefCount;
      if ( !(v35 & 0x3FFFFFF) )
        return 1;
      v33->RefCount = v35 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v33->vfptr);
      return 1;
    case 0x74:
      v8->pDispObj->vfptr[40].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->pDispObj->vfptr, 1073741824u);
      Scaleform::GFx::AS2::Value::SetNumber(retaddr, a5);
      return 1;
    case 0x75:
      if ( !v8->vfptr[2].HasEventHandler(
              (Scaleform::GFx::AvmDisplayObjBase *)&v8->vfptr,
              (Scaleform::GFx::EventId *)5368709120i64) )
        break;
      v13 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v8->vfptr[2].GetAbsolutePath)(v8);
      v14 = Scaleform::GFx::AS2::Environment::CreateConstString(v13, &result, "WIN 8,0,0,0");
      Scaleform::GFx::AS2::Value::SetString(retaddr, v14);
      v15 = result.pNode;
      v10 = result.pNode->RefCount == 1;
      --v15->RefCount;
      if ( !v10 )
        return 1;
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      return 1;
    default:
      break;
  }
LABEL_31:
  if ( v7
    && v5->pNode == (Scaleform::GFx::ASStringNode *)v7->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl
    || v6 && v5->pNode == (Scaleform::GFx::ASStringNode *)v6->pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl )
  {
    Scaleform::GFx::AS2::Value::SetAsObject(retaddr, v8->pProto.pObject);
    return 1;
  }
  v36 = v8->ASMovieClipObj.pObject;
  if ( v36 )
  {
    Scaleform::GFx::AS2::MovieClipObject::Exchange__proto__(
      v36,
      (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&result,
      0i64);
    v37 = 0;
    if ( v7
      && v8->ASMovieClipObj.pObject->vfptr->GetMember(
           (Scaleform::GFx::AS2::ObjectInterface *)&v8->ASMovieClipObj.pObject->vfptr,
           v7,
           v5,
           retaddr) )
    {
      v37 = 1;
    }
    else if ( v6 )
    {
      v37 = 0;
      if ( v8->ASMovieClipObj.pObject->vfptr->GetMemberRaw(
             (Scaleform::GFx::AS2::ObjectInterface *)&v8->ASMovieClipObj.pObject->vfptr,
             v6,
             v5,
             retaddr) )
      {
        v37 = 1;
      }
    }
    Scaleform::GFx::AS2::MovieClipObject::Exchange__proto__(
      v8->ASMovieClipObj.pObject,
      &v45,
      (Scaleform::GFx::AS2::Object *)result.pNode);
    v38 = v45.pObject;
    if ( v45.pObject )
    {
      v39 = v45.pObject->RefCount;
      if ( v39 & 0x3FFFFFF )
      {
        v45.pObject->RefCount = v39 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v38->vfptr);
      }
    }
    v40 = result.pNode;
    if ( v37 )
    {
      if ( result.pNode )
      {
        v41 = result.pNode->RefCount;
        if ( v41 & 0x3FFFFFF )
        {
          result.pNode->RefCount = v41 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v40);
          return 1;
        }
      }
      return 1;
    }
    if ( result.pNode )
    {
      v42 = result.pNode->RefCount;
      if ( v42 & 0x3FFFFFF )
      {
        result.pNode->RefCount = v42 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v40);
      }
    }
  }
  v43 = Scaleform::GFx::DisplayList::GetDisplayObjectByName(
          (Scaleform::GFx::DisplayList *)&v8->pDispObj[1],
          v5,
          v8->ASEnvironment.StringContext.SWFVersion > 6u);
  if ( v43 && SLOBYTE(v43->Flags) < 0 )
  {
    Scaleform::GFx::AS2::Value::SetAsCharacter(retaddr, (Scaleform::GFx::InteractiveObject *)v43);
    v12 = 1;
  }
  else
  {
    v44 = v8->pProto.pObject;
    if ( v44
      && (v7 && v44->vfptr->GetMember((Scaleform::GFx::AS2::ObjectInterface *)&v44->vfptr, v7, v5, retaddr)
       || v6 && v44->vfptr->GetMemberRaw((Scaleform::GFx::AS2::ObjectInterface *)&v44->vfptr, v6, v5, retaddr)) )
    {
      return 1;
    }
    if ( Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v5->pNode)
      && *v5->pNode->pData == 95
      && (*(_QWORD *)&val.T.Type = v5,
          *(_OWORD *)&val.NV.Int32Value = (unsigned __int64)retaddr,
          *((_QWORD *)&val.NV + 3) = 0i64,
          v48 = 0i64,
          v49 = 0,
          Scaleform::GFx::AS2::Environment::CheckGlobalAndLevels(
            &v8->ASEnvironment,
            (Scaleform::GFx::Bool3W *)&result,
            (Scaleform::GFx::AS2::Environment::GetVarParams *)&val),
          LOBYTE(result.pNode)) )
    {
      v12 = LOBYTE(result.pNode) == 1;
    }
    else
    {
      v12 = 0;
    }
  }
  return v12;
}

// File Line: 1622
// RVA: 0x6F51B0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::AvmSprite::GetRelativeTarget(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::ASString *name, bool first_call)
{
  Scaleform::GFx::ASStringNode *v3; // r9
  bool v4; // bp
  bool v5; // si
  Scaleform::GFx::ASString *v6; // rdi
  Scaleform::GFx::AS2::AvmSprite *v7; // rbx
  Scaleform::GFx::ASMovieRootBase *v8; // rax
  Scaleform::GFx::InteractiveObject *result; // rax
  Scaleform::GFx::ASMovieRootBase *v10; // rdx
  Scaleform::GFx::ASStringNode *v11; // rcx
  const char *v12; // rcx
  int v13; // eax
  char *ptail; // [rsp+30h] [rbp+8h]

  v3 = name->pNode;
  v4 = first_call;
  v5 = this->ASEnvironment.StringContext.SWFVersion > 6u;
  v6 = name;
  v7 = this;
  if ( (name->pNode->HashFlags & 0x80000000) != 0 )
  {
    if ( this->ASEnvironment.StringContext.SWFVersion > 6u )
    {
      v8 = this->ASEnvironment.StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( (Scaleform::GFx::ASStringNode *)v8[17].pASSupport.pObject != v3
        && (Scaleform::GFx::ASStringNode *)v8[20].vfptr != v3 )
      {
        if ( *(Scaleform::GFx::ASStringNode **)&v8[17].AVMVersion != v3
          && *(Scaleform::GFx::ASStringNode **)&v8[20].AVMVersion != v3 )
        {
          if ( (Scaleform::GFx::ASStringNode *)v8[20].pASSupport.pObject == v3 )
            return (Scaleform::GFx::InteractiveObject *)this->vfptr[2].HasEventHandler(
                                                          (Scaleform::GFx::AvmDisplayObjBase *)this,
                                                          0i64);
          goto LABEL_19;
        }
        return v7->pDispObj->pParent;
      }
      return v7->pDispObj;
    }
    if ( !v3->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v3 = v6->pNode;
    v10 = v7->ASEnvironment.StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    if ( v10[17].pASSupport.pObject == (Scaleform::GFx::ASSupport *)v6->pNode )
      return v7->pDispObj;
    v11 = v3->pLower;
    if ( (Scaleform::GFx::ASStringNode *)v10[20].vfptr[2].__vecDelDtor == v11 )
      return v7->pDispObj;
    if ( *(Scaleform::GFx::ASStringNode **)&v10[17].AVMVersion == v3
      || *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v10[20].AVMVersion + 16i64) == v11 )
    {
      return v7->pDispObj->pParent;
    }
    if ( *(Scaleform::GFx::ASStringNode **)&v10[20].pASSupport.pObject->SType == v11 )
      return (Scaleform::GFx::InteractiveObject *)v7->vfptr[2].HasEventHandler(
                                                    (Scaleform::GFx::AvmDisplayObjBase *)&v7->vfptr,
                                                    0i64);
  }
LABEL_19:
  v12 = v3->pData;
  if ( *v3->pData == 95 && v4 )
  {
    ptail = 0i64;
    v13 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(v12, (const char **)&ptail, v5);
    if ( v13 != -1 && !*ptail )
      return Scaleform::GFx::AS2::MovieRoot::GetLevelMovie((Scaleform::GFx::AS2::MovieRoot *)v7->pDispObj->pASRoot, v13);
  }
  result = (Scaleform::GFx::InteractiveObject *)Scaleform::GFx::DisplayList::GetDisplayObjectByName(
                                                  (Scaleform::GFx::DisplayList *)&v7->pDispObj[1],
                                                  v6,
                                                  v7->ASEnvironment.StringContext.SWFVersion > 6u);
  if ( !result || SLOBYTE(result->Flags) >= 0 )
    result = 0i64;
  return result;
}

// File Line: 1684
// RVA: 0x714D20
void __fastcall Scaleform::GFx::AS2::AvmSprite::SetLevel(Scaleform::GFx::AS2::AvmSprite *this, int level)
{
  int v2; // esi
  Scaleform::GFx::AS2::AvmSprite *v3; // r14
  unsigned __int64 v4; // rbx
  Scaleform::GFx::InteractiveObject *v5; // rcx
  Scaleform::GFx::ASMovieRootBase *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // rdx
  unsigned __int64 v8; // r8
  Scaleform::GFx::MovieImpl::LevelInfo *v9; // rdx
  __int64 v10; // rax
  Scaleform::Render::TreeContainer *v11; // rdi
  Scaleform::Render::TreeNode *v12; // rax
  Scaleform::GFx::InteractiveObject *v13; // rbx
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  char pstr; // [rsp+20h] [rbp-C8h]
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
  Scaleform::MsgFormat::Sink r; // [rsp+60h] [rbp-88h]
  __int64 v29; // [rsp+78h] [rbp-70h]
  Scaleform::GFx::ASString result; // [rsp+488h] [rbp+3A0h]
  int v; // [rsp+490h] [rbp+3A8h]

  v29 = -2i64;
  v2 = level;
  v3 = this;
  v4 = 0i64;
  v5 = this->pDispObj;
  v6 = v5->pASRoot;
  v7 = v6->pMovieImpl;
  v8 = v7->MovieLevels.Data.Size;
  if ( v8 )
  {
    v9 = v7->MovieLevels.Data.Data;
    v10 = 0i64;
    do
    {
      if ( v9[v10].Level > v2 )
        break;
      ++v4;
      ++v10;
    }
    while ( v4 < v8 );
  }
  v11 = (Scaleform::Render::TreeContainer *)v6[1].vfptr;
  v12 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr);
  Scaleform::Render::TreeContainer::Insert(v11, v4, v12);
  v3->Level = v2;
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
  r.Type = 2;
  r.SinkData.pStr = (Scaleform::String *)&pstr;
  r.SinkData.DataPtr.Size = 64i64;
  Scaleform::MsgFormat::MsgFormat((Scaleform::MsgFormat *)&r.SinkData, &r);
  Scaleform::MsgFormat::Parse((Scaleform::MsgFormat *)&r.SinkData, "_level{0}");
  Scaleform::MsgFormat::FormatD1<long>((Scaleform::MsgFormat *)&r.SinkData, &v);
  Scaleform::MsgFormat::FinishFormatD((Scaleform::MsgFormat *)&r.SinkData);
  Scaleform::MsgFormat::~MsgFormat((Scaleform::MsgFormat *)&r.SinkData);
  v13 = v3->pDispObj;
  v14 = Scaleform::GFx::AS2::Environment::CreateString(&v3->ASEnvironment, &result, &pstr);
  v13->vfptr[124].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v13->vfptr, (unsigned int)v14);
  v15 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
}

// File Line: 1708
// RVA: 0x7058C0
char __fastcall Scaleform::GFx::AS2::AvmSprite::OnEvent(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::EventId *v2; // rsi
  Scaleform::GFx::AS2::AvmSprite *v3; // rdi
  Scaleform::GFx::Sprite *v4; // rcx
  Scaleform::GFx::TimelineDef *v5; // rax
  char v6; // dl
  unsigned int v7; // eax
  const char *v8; // rdx
  __int64 v9; // rax
  char v10; // r14
  Scaleform::GFx::AS2::MovieClipObject *v11; // rcx
  Scaleform::GFx::Sprite *v12; // r15
  Scaleform::GFx::MovieImpl *v13; // r12
  __int64 v14; // r13
  Scaleform::GFx::Sprite *v15; // rbx
  bool v16; // r15
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v21; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v22; // rbx
  Scaleform::GFx::InteractiveObject *v23; // rdi
  Scaleform::RefCountNTSImpl *v24; // rcx
  Scaleform::RefCountNTSImpl *v25; // rcx
  Scaleform::GFx::AS2::Value v26; // [rsp+30h] [rbp-20h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+40h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> v28; // [rsp+A0h] [rbp+50h]
  Scaleform::GFx::Sprite *v29; // [rsp+A8h] [rbp+58h]

  v2 = id;
  v3 = this;
  v4 = (Scaleform::GFx::Sprite *)this->pDispObj;
  if ( v4->Flags & 0x40 )
    v5 = v4->pDef.pObject;
  else
    v5 = 0i64;
  if ( v5 )
  {
    v6 = v5[2].Id.Id;
    if ( v6 & 7 )
    {
      v7 = v2->Id;
      if ( v2->Id > 0x2000 )
      {
        if ( v7 == 0x4000 )
        {
LABEL_18:
          if ( !(v6 & 1) )
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
          if ( !(v6 & 2) )
            goto LABEL_21;
          v8 = "_down";
LABEL_20:
          Scaleform::GFx::Sprite::GotoLabeledFrame(v4, v8, 0);
          goto LABEL_21;
        }
        if ( v7 != 2048 )
        {
          if ( v7 != 4096 )
            goto LABEL_21;
          goto LABEL_18;
        }
      }
      if ( !(v6 & 4) )
        goto LABEL_21;
      v8 = "_over";
      goto LABEL_20;
    }
  }
LABEL_21:
  if ( Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler((Scaleform::GFx::AS2::AvmCharacter *)&v3->vfptr, v2) )
  {
LABEL_47:
    v21 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
            (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v3->pDispObj->pASRoot[3].RefCount,
            AP_Frame);
    v22 = v21;
    if ( v21 )
    {
      *(_OWORD *)&v26.T.Type = *(_OWORD *)&v2->Id;
      *((_DWORD *)&v26.NV + 4) = *(_DWORD *)&v2->RollOverCnt;
      v23 = v3->pDispObj;
      v21->Type = 2;
      if ( v23 )
        ++v23->RefCount;
      v24 = (Scaleform::RefCountNTSImpl *)&v21->pCharacter.pObject->vfptr;
      if ( v24 )
        Scaleform::RefCountNTSImpl::Release(v24);
      v22->pCharacter.pObject = v23;
      v25 = (Scaleform::RefCountNTSImpl *)&v22->pActionBuffer.pObject->vfptr;
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
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v3->vfptr[2].GetAbsolutePath)(v3);
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v9 + 232) + 40i64) + 24i64) + 312i64),
    v2);
  if ( result.pNode->Size )
  {
    v10 = 0;
    v26.T.Type = 0;
    v11 = v3->ASMovieClipObj.pObject;
    if ( v11 || (v11 = (Scaleform::GFx::AS2::MovieClipObject *)v3->pProto.pObject) != 0i64 )
    {
      v10 = 0;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v11->vfptr->GetMemberRaw)(
             &v11->vfptr,
             &v3->ASEnvironment.StringContext,
             &result,
             &v26,
             -2i64) )
      {
        v10 = 1;
      }
    }
    if ( (v2->Id - 64) & 0xFFFFFFBF )
      goto LABEL_58;
    if ( v3->ASEnvironment.StringContext.SWFVersion >= 6u )
    {
      v12 = (Scaleform::GFx::Sprite *)v3->pDispObj;
      v13 = v12->pASRoot->pMovieImpl;
      v14 = (unsigned int)v2->ControllerIndex;
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v13->FocusGroups[(unsigned __int8)v13->FocusGroupIndexes[v14]].LastFocused,
        &v28);
      v15 = v28.pObject;
      if ( v28.pObject )
      {
        ++v28.pObject->RefCount;
        v15 = v28.pObject;
      }
      v29 = v15;
      if ( v28.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v28.pObject->vfptr);
      v16 = v15 == v12;
      if ( v15 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v15->vfptr);
      if ( v16 && v13->FocusGroups[(unsigned __int8)v13->FocusGroupIndexes[v14]].FocusRectShown )
      {
LABEL_58:
        if ( v10 )
        {
          if ( v26.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v26);
          v17 = result.pNode;
          v18 = result.pNode->RefCount == 1;
          --v17->RefCount;
          if ( v18 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v17);
          goto LABEL_47;
        }
      }
    }
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
  }
  v19 = result.pNode;
  v18 = result.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  return 0;
}

// File Line: 1811
// RVA: 0x6E7D10
char __fastcall Scaleform::GFx::AS2::AvmSprite::ExecuteBuffer(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::AS2::ActionBuffer *pactionbuffer)
{
  Scaleform::GFx::AS2::ActionBuffer *v2; // rbx
  Scaleform::GFx::AS2::Environment *v3; // rax

  v2 = pactionbuffer;
  if ( (LOBYTE(this->pDispObj->Flags) >> 4) & 1 )
    return 0;
  v3 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))this->vfptr[2].GetAbsolutePath)();
  Scaleform::GFx::AS2::ActionBuffer::Execute(v2, v3, 0, v2->pBufferData.pObject->BufferLen, 0i64, 0i64, 0);
  return 1;
}

// File Line: 1827
// RVA: 0x6E87D0
bool __fastcall Scaleform::GFx::AS2::AvmSprite::ExecuteEvent(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::EventId *v2; // rsi
  Scaleform::GFx::AS2::AvmSprite *v3; // rdi
  Scaleform::GFx::InteractiveObject *v4; // rbx
  Scaleform::GFx::InteractiveObject *v6; // rcx
  bool v7; // bp

  v2 = id;
  v3 = this;
  v4 = this->pDispObj;
  if ( (LOBYTE(v4->Flags) >> 4) & 1 )
    return 0;
  if ( v4 )
    ++v4->RefCount;
  if ( id->Id != 1
    || (this->pDispObj->Flags &= 0xFFDFu, v6 = this->pDispObj, (LOBYTE(v6->Flags) >> 3) & 1)
    || SLOBYTE(v6[1].pIndXFormData) < 0 )
  {
    v7 = Scaleform::GFx::AS2::AvmCharacter::ExecuteEvent((Scaleform::GFx::AS2::AvmCharacter *)&v3->vfptr, id);
    if ( v2->Id == 4 )
    {
      v3->pDispObj->Flags |= 0x10u;
      Scaleform::GFx::InteractiveObject::SetNextUnloaded(
        v3->pDispObj,
        v3->pDispObj->pASRoot->pMovieImpl->pUnloadListHead);
      v3->pDispObj->pASRoot->pMovieImpl->pUnloadListHead = v3->pDispObj;
      ++v3->pDispObj->RefCount;
    }
  }
  else
  {
    v7 = 0;
  }
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
  return v7;
}

// File Line: 1886
// RVA: 0x6D7790
bool __fastcall Scaleform::GFx::AS2::AvmSprite::ActsAsButton(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::AvmSprite *v1; // rbx
  Scaleform::GFx::AS2::MovieClipObject *v2; // rdi
  Scaleform::GFx::AS2::MovieClipObject *v3; // rbx

  v1 = this;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AvmDisplayObjBaseVtbl **))this->vfptr[2].HasEventHandler)(&this->vfptr)
    || !((v1->pDispObj->Flags >> 4) & 1) )
  {
    return 0;
  }
  v2 = v1->ASMovieClipObj.pObject;
  if ( !v2 )
  {
    v2 = (Scaleform::GFx::AS2::MovieClipObject *)v1->pProto.pObject;
    if ( !v2 )
      return 0;
  }
  if ( v2->ButtonEventMask || v2->HasButtonHandlers )
    return 1;
  v3 = (Scaleform::GFx::AS2::MovieClipObject *)v2->pProto.pObject;
  if ( !v3 )
    return 0;
  while ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v2->pProto.pObject->vfptr->gap8[8])(&v2->pProto.pObject->vfptr) != 11 )
  {
    v3 = (Scaleform::GFx::AS2::MovieClipObject *)v3->pProto.pObject;
    if ( !v3 )
      return 0;
  }
  return Scaleform::GFx::AS2::MovieClipObject::ActsAsButton(v3);
}

// File Line: 1904
// RVA: 0x724080
void __fastcall Scaleform::GFx::AS2::AvmSprite::VisitMembers(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor, unsigned int visitFlags)
{
  unsigned int v4; // edi
  Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *v5; // rsi
  Scaleform::GFx::AS2::ASStringContext *v6; // rbp
  Scaleform::GFx::AS2::AvmSprite *v7; // rbx
  void **v8; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *v9; // [rsp+40h] [rbp-18h]
  unsigned int v10; // [rsp+48h] [rbp-10h]

  v4 = visitFlags;
  v5 = pvisitor;
  v6 = psc;
  v7 = this;
  if ( visitFlags & 2 )
  {
    v8 = (void **)&`Scaleform::GFx::AS2::AvmSprite::VisitMembers'::`5'::Visitor::`vftable';
    v9 = pvisitor;
    v10 = visitFlags;
    Scaleform::GFx::DisplayList::VisitMembers(
      (Scaleform::GFx::DisplayList *)&this->pProto.pObject[2].RefCount,
      (Scaleform::GFx::DisplayList::MemberVisitor *)&v8);
    v8 = &Scaleform::GFx::DisplayList::MemberVisitor::`vftable';
  }
  Scaleform::GFx::AS2::AvmCharacter::VisitMembers((Scaleform::GFx::AS2::AvmCharacter *)&v7->vfptr, v6, v5, v4);
}

// File Line: 1915
// RVA: 0x7239A0
void __fastcall Scaleform::GFx::AS2::AvmSprite::VisitMembers_::_5_::Visitor::Visit(Scaleform::GFx::ASString *name, Scaleform::GFx::InteractiveObject *pch, Scaleform::GFx::DisplayObject *a3)
{
  Scaleform::GFx::InteractiveObject *v3; // rdi
  Scaleform::GFx::ASString *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rax
  Scaleform::GFx::AS2::Value v6; // [rsp+28h] [rbp-30h]

  v3 = pch;
  v4 = name;
  v6.T.Type = 7;
  if ( a3 )
  {
    v5 = (Scaleform::GFx::ASStringNode *)a3->pNameHandle.pObject;
    if ( !v5 )
      v5 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(a3);
    v6.V.pStringNode = v5;
    if ( v5 )
      ++LODWORD(v5->pData);
  }
  else
  {
    v6.V.pStringNode = 0i64;
  }
  (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::AS2::Value *, _QWORD, signed __int64))v4[1].pNode->pData
   + 1))(
    v4[1].pNode,
    v3,
    &v6,
    LOBYTE(v4[2].pNode),
    -2i64);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
}

// File Line: 1928
// RVA: 0x6E20E0
bool __fastcall Scaleform::GFx::AS2::AvmSprite::DeleteMember(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name)
{
  return Scaleform::GFx::AS2::AvmCharacter::DeleteMember((Scaleform::GFx::AS2::AvmCharacter *)&this->vfptr, psc, name) != 0;
}

// File Line: 1935
// RVA: 0x6F43E0
Scaleform::GFx::AS2::MovieClipObject *__fastcall Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::AvmSprite *v1; // rdi
  Scaleform::GFx::AS2::MovieClipObject *v2; // rsi
  Scaleform::GFx::Sprite *v3; // rbx
  Scaleform::GFx::AS2::GlobalContext *v4; // rax
  Scaleform::GFx::AS2::MovieClipObject *v5; // rax
  Scaleform::GFx::AS2::MovieClipObject *v6; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rcx
  unsigned int v8; // eax

  v1 = this;
  if ( this->ASMovieClipObj.pObject )
    return this->ASMovieClipObj.pObject;
  v2 = (Scaleform::GFx::AS2::MovieClipObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, signed __int64))this->pDispObj->pASRoot->pMovieImpl->pHeap->vfptr->Alloc)(
                                                 this,
                                                 112i64);
  if ( v2 )
  {
    v3 = (Scaleform::GFx::Sprite *)v1->pDispObj;
    v4 = (Scaleform::GFx::AS2::GlobalContext *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v1->vfptr[1].OnUnloading)(v1);
    Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(v2, v4, v3);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->ASMovieClipObj.pObject->vfptr;
  if ( v7 )
  {
    v8 = v7->RefCount;
    if ( v8 & 0x3FFFFFF )
    {
      v7->RefCount = v8 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    }
  }
  v1->ASMovieClipObj.pObject = v6;
  return v6;
}

// File Line: 1942
// RVA: 0x6EE320
Scaleform::GFx::AS2::MovieClipObject *__fastcall Scaleform::GFx::AS2::AvmSprite::GetASObject(Scaleform::GFx::AS2::AvmSprite *this)
{
  return Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject(this);
}

// File Line: 1952
// RVA: 0x7008B0
bool __fastcall Scaleform::GFx::AS2::AvmSprite::IsFocusEnabled(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::AS2::AvmSprite *v2; // rbx
  Scaleform::GFx::AS2::Object *v4; // rdi
  Scaleform::GFx::ASString *v5; // rax
  __int64 v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  bool v9; // bl
  Scaleform::GFx::AS2::Value v10; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h]

  v2 = this;
  if ( fmt == 1 )
    return 0;
  v4 = this->pProto.pObject;
  if ( !v4 )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v2->vfptr[1].__vecDelDtor)(v2);
  v10.T.Type = 0;
  v5 = Scaleform::GFx::AS2::Environment::CreateConstString(&this->ASEnvironment, &result, "focusEnabled");
  v6 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v4->vfptr->GetMemberRaw)(
         &v4->vfptr,
         &v2->ASEnvironment.StringContext,
         v5,
         &v10,
         -2i64);
  v7 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( !(_BYTE)v6 || !v10.T.Type || v10.T.Type == 10 )
  {
    if ( v10.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v10);
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v2->vfptr[1].__vecDelDtor)(v2);
  }
  v9 = Scaleform::GFx::AS2::Value::ToBool(&v10, &v2->ASEnvironment);
  if ( v10.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v10);
  return v9;
}

// File Line: 1971
// RVA: 0x6E8AA0
void __fastcall Scaleform::GFx::AS2::AvmSprite::ExecuteFrame0Events(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::AvmSprite *v1; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v2; // rax
  unsigned __int64 v3; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v4; // rdi
  Scaleform::RefCountNTSImpl *v5; // rcx
  Scaleform::RefCountNTSImpl *v6; // rcx

  v1 = this;
  v2 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
         (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)(*(_QWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity
                                                                       + 32)
                                                           + 128i64),
         AP_Load);
  v3 = v1[-1].InitActionsExecuted.Data.Policy.Capacity;
  v4 = v2;
  v2->Type = 2;
  if ( v3 )
    ++*(_DWORD *)(v3 + 8);
  v5 = (Scaleform::RefCountNTSImpl *)&v2->pCharacter.pObject->vfptr;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  v4->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)v3;
  v6 = (Scaleform::RefCountNTSImpl *)&v4->pActionBuffer.pObject->vfptr;
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
__int64 __fastcall Scaleform::GFx::AS2::AvmSprite::GetCursorType(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::AvmSprite *v1; // rbx
  Scaleform::GFx::AS2::Environment *v2; // rdi
  BOOL v3; // ebx
  Scaleform::GFx::AS2::Value v5; // [rsp+28h] [rbp-30h]

  v1 = this;
  if ( !((unsigned __int8 (__cdecl *)(Scaleform::GFx::AS2::AvmSprite *))this->vfptr[1].__vecDelDtor)(this) )
    return 0i64;
  v2 = (Scaleform::GFx::AS2::Environment *)v1->vfptr[2].ToAvmDispContainerBase((Scaleform::GFx::AvmDisplayObjBase *)&v1->vfptr);
  v5.T.Type = 0;
  v3 = !v1->vfptr->GetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v1->vfptr,
          &v2->StringContext,
          (Scaleform::GFx::ASString *)&v2->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[33].pMovieImpl,
          &v5)
    || v5.T.Type && v5.T.Type != 10 && Scaleform::GFx::AS2::Value::ToBool(&v5, v2);
  if ( v5.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v5);
  return (unsigned int)v3;
}

// File Line: 2068
// RVA: 0x6ABB60
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpritePlay(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::InteractiveObject *v2; // rcx

  v1 = fn->ThisPtr;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v2 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v2 = 0i64;
  }
  else
  {
    v2 = fn->Env->Target;
  }
  if ( v2 )
    v2->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 0);
}

// File Line: 2075
// RVA: 0x6ABC50
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteStop(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::InteractiveObject *v2; // rcx

  v1 = fn->ThisPtr;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v2 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v2 = 0i64;
  }
  else
  {
    v2 = fn->Env->Target;
  }
  if ( v2 )
    v2->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 1u);
}

// File Line: 2082
// RVA: 0x6AC5E0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGotoAndPlay(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rbx
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::InteractiveObject *v4; // rbx
  unsigned int v5; // er9
  Scaleform::GFx::AS2::Environment *v6; // r8
  __int64 v7; // r9
  char v8; // al
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  unsigned int v11; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+48h] [rbp+10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = 0i64;
  if ( v2 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v2[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 )
  {
    if ( v1->NArgs < 1 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v4->vfptr,
        "AvmSprite::SpriteGotoAndPlay needs one arg");
      return;
    }
    v5 = v1->FirstArgBottomIndex;
    v6 = v1->Env;
    if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
      v3 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
    v11 = -1;
    if ( v3->T.Type == 5 )
    {
      Scaleform::GFx::AS2::Value::ToString(v3, &result, v6, -1);
      LOBYTE(v7) = 1;
      v8 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, const char *, unsigned int *, __int64, signed __int64))v4->vfptr[108].__vecDelDtor)(
             v4,
             result.pNode->pData,
             &v11,
             v7,
             -2i64);
      v9 = result.pNode;
      if ( !v8 )
      {
        v10 = result.pNode->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        return;
      }
      v10 = result.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    }
    else
    {
      v11 = Scaleform::GFx::AS2::Value::ToUInt32(v3, v6) - 1;
    }
    v4->vfptr[110].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, v11);
    v4->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 0);
  }
}

// File Line: 2110
// RVA: 0x6AC250
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGotoAndStop(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rbx
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::InteractiveObject *v4; // rbx
  unsigned int v5; // er9
  Scaleform::GFx::AS2::Environment *v6; // r8
  __int64 v7; // r9
  char v8; // al
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  unsigned int v11; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+48h] [rbp+10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = 0i64;
  if ( v2 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v2[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 )
  {
    if ( v1->NArgs < 1 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v4->vfptr,
        "AvmSprite::SpriteGotoAndStop needs one arg");
      return;
    }
    v5 = v1->FirstArgBottomIndex;
    v6 = v1->Env;
    if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
      v3 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
    v11 = -1;
    if ( v3->T.Type == 5 )
    {
      Scaleform::GFx::AS2::Value::ToString(v3, &result, v6, -1);
      LOBYTE(v7) = 1;
      v8 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, const char *, unsigned int *, __int64, signed __int64))v4->vfptr[108].__vecDelDtor)(
             v4,
             result.pNode->pData,
             &v11,
             v7,
             -2i64);
      v9 = result.pNode;
      if ( !v8 )
      {
        v10 = result.pNode->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        return;
      }
      v10 = result.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    }
    else
    {
      v11 = Scaleform::GFx::AS2::Value::ToUInt32(v3, v6) - 1;
    }
    v4->vfptr[110].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, v11);
    v4->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 1u);
  }
}

// File Line: 2138
// RVA: 0x6AC900
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteNextFrame(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rdi
  Scaleform::GFx::InteractiveObject *v2; // rdi
  int v3; // ebx
  int v4; // eax

  v1 = fn->ThisPtr;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v2 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v2 = 0i64;
  }
  else
  {
    v2 = fn->Env->Target;
  }
  if ( v2 )
  {
    v3 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v2->vfptr[111].__vecDelDtor)(v2);
    v4 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v2->vfptr[107].__vecDelDtor)(v2);
    if ( v4 < v3 )
      v2->vfptr[110].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, v4 + 1);
    v2->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 1u);
  }
}

// File Line: 2150
// RVA: 0x6ACB60
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpritePrevFrame(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::InteractiveObject *v2; // rbx
  int v3; // eax

  v1 = fn->ThisPtr;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v2 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v2 = 0i64;
  }
  else
  {
    v2 = fn->Env->Target;
  }
  if ( v2 )
  {
    v3 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v2->vfptr[107].__vecDelDtor)(v2);
    if ( v3 > 0 )
      v2->vfptr[110].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, v3 - 1);
    v2->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 1u);
  }
}

// File Line: 2162
// RVA: 0x6ACBE0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetBytesLoaded(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::Sprite *v3; // rcx
  unsigned int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // rbx
  unsigned int v6; // esi

  v1 = fn->ThisPtr;
  v2 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v3 = (Scaleform::GFx::Sprite *)v1[1].vfptr;
    else
      v3 = 0i64;
  }
  else
  {
    v3 = (Scaleform::GFx::Sprite *)fn->Env->Target;
  }
  if ( v3 )
  {
    v4 = Scaleform::GFx::Sprite::GetBytesLoaded(v3);
    v5 = v2->Result;
    v6 = v4;
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v2->Result);
    v5->NV.Int32Value = v6;
    v5->T.Type = 4;
  }
}

// File Line: 2176
// RVA: 0x6ACC60
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetBytesTotal(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::InteractiveObject *v3; // rcx
  __int64 v4; // rax
  Scaleform::GFx::AS2::Value *v5; // rbx
  int v6; // esi

  v1 = fn->ThisPtr;
  v2 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v3 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v3 = 0i64;
  }
  else
  {
    v3 = fn->Env->Target;
  }
  if ( v3 )
  {
    v4 = ((__int64 (*)(void))v3->vfptr[66].__vecDelDtor)();
    v5 = v2->Result;
    v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 104) + 24i64) + 64i64) + 80i64);
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v2->Result);
    v5->NV.Int32Value = v6;
    v5->T.Type = 4;
  }
}

// File Line: 2185
// RVA: 0x6AEBE0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteDuplicateMovieClip(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::AS2::Value *v4; // rsi
  Scaleform::GFx::DisplayObjectBase *v5; // r14
  signed int v6; // eax
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // rdx
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::AS2::ObjectInterface *v10; // rbp
  unsigned int v11; // er9
  Scaleform::GFx::AS2::Environment *v12; // r8
  Scaleform::GFx::AS2::Value *v13; // r10
  Scaleform::GFx::ASString *v14; // r15
  unsigned int v15; // er8
  Scaleform::GFx::AS2::Environment *v16; // r9
  signed __int64 v17; // rcx
  Scaleform::GFx::AS2::AvmCharacter *v18; // rbx
  long double v19; // xmm0_8
  Scaleform::GFx::InteractiveObject *v20; // rax
  Scaleform::GFx::InteractiveObject *v21; // rbx
  Scaleform::GFx::ASStringNode *v22; // rcx
  bool v23; // zf
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::InteractiveObject *v25; // [rsp+68h] [rbp+10h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  v3 = v1->ThisPtr;
  v4 = 0i64;
  if ( v3 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr) == 2 )
      v5 = (Scaleform::GFx::DisplayObjectBase *)v3[1].vfptr;
    else
      v5 = 0i64;
  }
  else
  {
    v5 = (Scaleform::GFx::DisplayObjectBase *)&v1->Env->Target->vfptr;
  }
  if ( v5 )
  {
    v6 = v1->NArgs;
    if ( v6 >= 2 )
    {
      if ( v6 == 3 )
      {
        v7 = v1->FirstArgBottomIndex - 2;
        v8 = v1->Env;
        v9 = 0i64;
        if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
                 + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
          v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
        v10 = Scaleform::GFx::AS2::Value::ToObjectInterface(v9, v8);
      }
      else
      {
        v10 = 0i64;
      }
      v11 = v1->FirstArgBottomIndex;
      v12 = v1->Env;
      v13 = 0i64;
      if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
        v13 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
      v14 = Scaleform::GFx::AS2::Value::ToString(v13, &result, v12, -1);
      v15 = v1->FirstArgBottomIndex - 1;
      v16 = v1->Env;
      if ( v15 <= 32 * ((unsigned int)v16->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v16->Stack.pCurrent - (char *)v16->Stack.pPageStart) >> 5) )
        v4 = &v16->Stack.Pages.Data.Data[v15 >> 5]->Values[v15 & 0x1F];
      v17 = (signed __int64)v5 + 4 * (unsigned __int8)v5->AvmObjOffset;
      v18 = (Scaleform::GFx::AS2::AvmCharacter *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v17 + 8i64))(v17);
      v19 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1->Env);
      v20 = Scaleform::GFx::AS2::AvmCharacter::CloneDisplayObject(v18, v14, (signed int)v19 + 0x4000, v10);
      v21 = v20;
      if ( v20 )
        ++v20->RefCount;
      v25 = v20;
      v22 = result.pNode;
      v23 = result.pNode->RefCount == 1;
      --v22->RefCount;
      if ( v23 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      if ( Scaleform::GFx::DisplayObjectBase::GetVersion(v5) >= 6 )
        Scaleform::GFx::AS2::Value::SetAsCharacter(v1->Result, v21);
      if ( v21 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v21->vfptr);
    }
  }
}

// File Line: 2202
// RVA: 0x6AE810
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteAttachMovie(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::InteractiveObject *v4; // r14
  Scaleform::GFx::DisplayObject *v5; // rsi
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::MovieImpl *v9; // rbx
  Scaleform::GFx::MovieDefImpl *v10; // rax
  bool v11; // bl
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  int v15; // eax
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  int v18; // ebx
  Scaleform::GFx::AS2::Value *v19; // rax
  unsigned int v20; // eax
  Scaleform::GFx::AS2::Value *v21; // rax
  Scaleform::GFx::AS2::ObjectInterface *v22; // rbx
  Scaleform::GFx::AS2::Value *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  __int64 v25; // rax
  Scaleform::RefCountNTSImpl *v26; // rbx
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASString *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASStringNode *v30; // rcx
  __int64 v31; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::ResourceBindData presBindData; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::ASString v33; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::ASString v34; // [rsp+68h] [rbp-98h]
  Scaleform::Render::Cxform v35; // [rsp+70h] [rbp-90h]
  Scaleform::Render::Matrix2x4<float> v36; // [rsp+90h] [rbp-70h]
  Scaleform::Render::RenderBuffer *v37; // [rsp+B0h] [rbp-50h]
  int v38; // [rsp+B8h] [rbp-48h]
  unsigned int v39; // [rsp+BCh] [rbp-44h]
  int v40; // [rsp+C0h] [rbp-40h]
  __int64 v41; // [rsp+C8h] [rbp-38h]
  char v42[6]; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::Resource *v43; // [rsp+E0h] [rbp-20h]
  Scaleform::GFx::Resource *v44; // [rsp+E8h] [rbp-18h]
  __int64 v45; // [rsp+F0h] [rbp-10h]
  __int64 v46; // [rsp+F8h] [rbp-8h]
  __int64 v47; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::ASString result; // [rsp+140h] [rbp+40h]
  Scaleform::String symbol; // [rsp+148h] [rbp+48h]
  Scaleform::GFx::ASString v50; // [rsp+150h] [rbp+50h]
  Scaleform::GFx::ASString v51; // [rsp+158h] [rbp+58h]

  v47 = -2i64;
  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  v3 = v1->ThisPtr;
  v4 = 0i64;
  if ( v3 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr) == 2 )
      v5 = (Scaleform::GFx::DisplayObject *)v3[1].vfptr;
    else
      v5 = 0i64;
  }
  else
  {
    v5 = (Scaleform::GFx::DisplayObject *)&v1->Env->Target->vfptr;
  }
  if ( v5 && v1->NArgs >= 3 )
  {
    v6 = v1->FirstArgBottomIndex;
    v7 = v1->Env;
    v8 = 0i64;
    if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
      v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v8, &result, v7, -1);
    presBindData.pResource.pObject = 0i64;
    presBindData.pBinding = 0i64;
    Scaleform::String::String(&symbol, result.pNode->pData);
    v9 = v5->pASRoot->pMovieImpl;
    v10 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v5->vfptr[66].__vecDelDtor)(v5);
    v11 = Scaleform::GFx::MovieImpl::FindExportedResource(v9, v10, &presBindData, &symbol) == 0;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    if ( v11 )
    {
      v12 = Scaleform::GFx::DisplayObject::GetName(v5, &v50);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v5->vfptr,
        "%s.attachMovie() failed - export name \"%s\" is not found.",
        v12->pNode->pData,
        result.pNode->pData);
      v13 = v50.pNode;
      v14 = v50.pNode->RefCount == 1;
      --v13->RefCount;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
    else
    {
      v15 = ((__int64 (*)(void))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)();
      if ( _bittest(&v15, 0xFu) )
      {
        v44 = 0i64;
        v45 = 0i64;
        v43 = presBindData.pResource.pObject;
        v44 = presBindData.pBinding->pOwnerDefRes;
        v18 = (int)presBindData.pResource.pObject[1].vfptr;
        v19 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
        v20 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v19, v1->Env) + 0x4000;
        v35 = Scaleform::Render::Cxform::Identity;
        v36 = Scaleform::Render::Matrix2x4<float>::Identity;
        v37 = 0i64;
        v38 = 0;
        *(_DWORD *)&v42[2] = 16777220;
        *(_DWORD *)v42 = 786432;
        v39 = v20;
        v40 = v18;
        v41 = 0i64;
        if ( v20 > 0x7EFFFFFD )
        {
          v28 = Scaleform::GFx::DisplayObject::GetName(v5, &v34);
          LODWORD(v31) = v39;
          Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
            (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v5->vfptr,
            "%s.attachMovie(\"%s\") failed - depth (%d) must be >= 0",
            v28->pNode->pData,
            result.pNode->pData,
            v31);
          v29 = v34.pNode;
          v14 = v34.pNode->RefCount == 1;
          --v29->RefCount;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v29);
        }
        else
        {
          if ( v1->NArgs == 4 )
          {
            v21 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
            v22 = Scaleform::GFx::AS2::Value::ToObjectInterface(v21, v1->Env);
          }
          else
          {
            v22 = 0i64;
          }
          v23 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
          v24 = Scaleform::GFx::AS2::Value::ToString(v23, &v33, v1->Env, -1);
          v25 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, Scaleform::GFx::AS2::ObjectInterface *, signed int, signed int, Scaleform::GFx::Resource **, _QWORD))v5->vfptr[118].__vecDelDtor)(
                  v5,
                  &v35,
                  v24,
                  0i64,
                  v22,
                  -1,
                  1,
                  &v43,
                  0i64);
          v26 = (Scaleform::RefCountNTSImpl *)v25;
          if ( v25 )
            ++*(_DWORD *)(v25 + 8);
          v46 = v25;
          v27 = v33.pNode;
          v14 = v33.pNode->RefCount == 1;
          --v27->RefCount;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v27);
          if ( v26 )
          {
            v26->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v26->vfptr, 0);
            if ( Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr) >= 6 )
            {
              if ( (v26[6].RefCount & 0x800000) != 0 )
                v4 = (Scaleform::GFx::InteractiveObject *)v26;
              Scaleform::GFx::AS2::Value::SetAsCharacter(v1->Result, v4);
            }
          }
          if ( v26 )
            Scaleform::RefCountNTSImpl::Release(v26);
        }
        if ( v37 )
          Scaleform::RefCountImpl::Release(v37);
      }
      else
      {
        v16 = Scaleform::GFx::DisplayObject::GetName(v5, &v51);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v5->vfptr,
          "%s.attachMovie() failed - \"%s\" is not a movieclip.",
          v16->pNode->pData,
          result.pNode->pData);
        v17 = v51.pNode;
        v14 = v51.pNode->RefCount == 1;
        --v17->RefCount;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      }
    }
    if ( presBindData.pResource.pObject )
      Scaleform::GFx::Resource::Release(presBindData.pResource.pObject);
    v30 = result.pNode;
    v14 = result.pNode->RefCount == 1;
    --v30->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  }
}

// File Line: 2289
// RVA: 0x6AE390
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteAttachBitmap(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::DisplayObjContainer *v4; // rsi
  unsigned int v5; // er10
  Scaleform::GFx::AS2::Environment *v6; // rdx
  Scaleform::GFx::AS2::Value *v7; // r9
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rbx
  Scaleform::GFx::ImageResource *v10; // r14
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rax
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value *v14; // rax
  bool v15; // r8
  Scaleform::GFx::MovieImpl *v16; // rcx
  Scaleform::GFx::AS2::MovieRoot *v17; // r15
  Scaleform::GFx::MovieDefImpl *v18; // rax
  Scaleform::GFx::MovieDefImpl *v19; // r14
  Scaleform::GFx::Sprite *v20; // r15
  __int128 *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  bool v23; // zf
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  unsigned int v28; // eax
  __int64 loadedSeparately; // [rsp+28h] [rbp-D8h]
  Scaleform::GFx::CharPosInfo pos; // [rsp+50h] [rbp-B0h]
  __int128 v31; // [rsp+C0h] [rbp-40h]
  __int128 v32; // [rsp+D0h] [rbp-30h]
  __int128 v33; // [rsp+E0h] [rbp-20h]
  __m128 v34; // [rsp+F0h] [rbp-10h]
  Scaleform::Render::RenderBuffer *v35; // [rsp+100h] [rbp+0h]
  int v36; // [rsp+108h] [rbp+8h]
  int v37; // [rsp+10Ch] [rbp+Ch]
  int v38; // [rsp+110h] [rbp+10h]
  __int64 v39; // [rsp+118h] [rbp+18h]
  char v40[6]; // [rsp+120h] [rbp+20h]
  __int64 v41; // [rsp+130h] [rbp+30h]
  Scaleform::Render::Cxform v42; // [rsp+140h] [rbp+40h]
  Scaleform::GFx::ASString result; // [rsp+1B0h] [rbp+B0h]
  Scaleform::GFx::AS2::Object *v44; // [rsp+1B8h] [rbp+B8h]
  Scaleform::GFx::MovieDefImpl *v45; // [rsp+1C0h] [rbp+C0h]
  Scaleform::GFx::Sprite *v46; // [rsp+1C8h] [rbp+C8h]

  v41 = -2i64;
  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  v3 = v1->ThisPtr;
  if ( v3 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::DisplayObjContainer *)v3[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = (Scaleform::GFx::DisplayObjContainer *)v1->Env->Target;
  }
  if ( !v4
    || v1->NArgs < 2
    || Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr) < 8 )
  {
    return;
  }
  v5 = v1->FirstArgBottomIndex;
  v6 = v1->Env;
  v7 = 0i64;
  if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
    v7 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
  v8 = Scaleform::GFx::AS2::Value::ToObject(v7, v6);
  v9 = v8;
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
  v44 = v8;
  if ( v8 && (*(unsigned int (**)(void))&v8->vfptr->gap8[8])() == 26 )
  {
    v10 = (Scaleform::GFx::ImageResource *)v9[1].vfptr;
    if ( v10 )
    {
      v12 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      v13 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v12, v1->Env) + 0x4000;
      pos.ColorTransform = Scaleform::Render::Cxform::Identity;
      pos.Matrix_1 = Scaleform::Render::Matrix2x4<float>::Identity;
      pos.pFilters.pObject = 0i64;
      pos.Ratio = 0.0;
      *(_DWORD *)&pos.Flags.Flags = 16777220;
      *(_DWORD *)&pos.ClipDepth = 786432;
      pos.Depth = v13;
      pos.CharacterId.Id = 1;
      pos.ClassName = 0i64;
      if ( v13 > 0x7EFFFFFD )
      {
        v24 = Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)&v4->vfptr, &result);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v4->vfptr,
          "%s.attachBitmap() failed - depth (%d) must be >= 0",
          v24->pNode->pData,
          (unsigned int)pos.Depth);
        v25 = result.pNode;
        v23 = result.pNode->RefCount == 1;
        --v25->RefCount;
        if ( v23 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      }
      else
      {
        if ( v1->NArgs < 4 )
        {
          v15 = 0;
        }
        else
        {
          v14 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
          v15 = Scaleform::GFx::AS2::Value::ToBool(v14, v1->Env);
        }
        v16 = v1->Env->Target->pASRoot->pMovieImpl;
        v17 = (Scaleform::GFx::AS2::MovieRoot *)v16->pASMovieRoot.pObject;
        v18 = Scaleform::GFx::MovieImpl::CreateImageMovieDef(v16, v10, v15, &customWorldMapCaption, 0i64);
        v19 = v18;
        v45 = v18;
        if ( v18 )
        {
          Scaleform::GFx::MovieDataDef::LoadTaskData::SetExtMovieDef(
            v18->pBindData.pObject->pDataDef.pObject->pData.pObject,
            (Scaleform::GFx::MovieDef *)v9[1].pRCC);
          LODWORD(result.pNode) = 65537;
          v20 = Scaleform::GFx::AS2::MovieRoot::CreateSprite(
                  v17,
                  (Scaleform::GFx::TimelineDef *)&v19->pBindData.pObject->pDataDef.pObject->vfptr,
                  v19,
                  (Scaleform::GFx::InteractiveObject *)&v4->vfptr,
                  (Scaleform::GFx::ResourceId)&result,
                  1);
          v46 = v20;
          if ( v20 )
          {
            Scaleform::Render::Cxform::Cxform(&v42);
            v31 = *v21;
            v32 = v21[1];
            v33 = _xmm;
            v34 = _xmm;
            v35 = 0i64;
            *(_DWORD *)&v40[2] = 0x1000000;
            v36 = 0;
            *(_DWORD *)v40 = 0x40000;
            v37 = 1;
            v38 = 1;
            v39 = 0i64;
            result.pNode = *(Scaleform::GFx::ASStringNode **)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
            ++result.pNode->RefCount;
            Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)&v20->vfptr);
            Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList((Scaleform::GFx::InteractiveObject *)&v20->vfptr);
            LODWORD(loadedSeparately) = 1;
            ((void (__fastcall *)(Scaleform::GFx::Sprite *, __int128 *, Scaleform::GFx::ASString *, _QWORD, _QWORD, __int64, _DWORD, _QWORD, _QWORD))v20->vfptr[118].__vecDelDtor)(
              v20,
              &v31,
              &result,
              0i64,
              0i64,
              loadedSeparately,
              0,
              0i64,
              0i64);
            Scaleform::GFx::DisplayObjContainer::ReplaceDisplayObject(
              v4,
              &pos,
              (Scaleform::GFx::DisplayObjectBase *)&v20->vfptr,
              &result);
            v4->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 0);
            v22 = result.pNode;
            v23 = result.pNode->RefCount == 1;
            --v22->RefCount;
            if ( v23 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v22);
            if ( v35 )
              Scaleform::RefCountImpl::Release(v35);
          }
          if ( v20 )
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v20->vfptr);
        }
        if ( v19 )
          Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v19->vfptr);
      }
      if ( pos.pFilters.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pos.pFilters.pObject);
      goto LABEL_38;
    }
    v11 = Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)&v4->vfptr, &result);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v4->vfptr,
      "%s.attachBitmap() failed - no image set in BitmapData.",
      v11->pNode->pData);
  }
  else
  {
    v26 = Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)&v4->vfptr, &result);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v4->vfptr,
      "%s.attachBitmap() failed - the argument is not a BitmapData.",
      v26->pNode->pData);
  }
  v27 = result.pNode;
  v23 = result.pNode->RefCount == 1;
  --v27->RefCount;
  if ( v23 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
LABEL_38:
  if ( v9 )
  {
    v28 = v9->RefCount;
    if ( v28 & 0x3FFFFFF )
    {
      v9->RefCount = v28 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
    }
  }
}

// File Line: 2374
// RVA: 0x6AEE60
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteCreateEmptyMovieClip(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rsi
  Scaleform::GFx::InteractiveObject *v5; // rbx
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r10
  unsigned int v9; // eax
  Scaleform::GFx::AS2::Value *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  __int64 v12; // rax
  Scaleform::RefCountNTSImpl *v13; // rbx
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::Render::Cxform v16; // [rsp+60h] [rbp-29h]
  Scaleform::Render::Matrix2x4<float> v17; // [rsp+80h] [rbp-9h]
  Scaleform::Render::RenderBuffer *v18; // [rsp+A0h] [rbp+17h]
  int v19; // [rsp+A8h] [rbp+1Fh]
  unsigned int v20; // [rsp+ACh] [rbp+23h]
  int v21; // [rsp+B0h] [rbp+27h]
  __int64 v22; // [rsp+B8h] [rbp+2Fh]
  char v23[6]; // [rsp+C0h] [rbp+37h]
  Scaleform::GFx::ASString result; // [rsp+F0h] [rbp+67h]
  __int64 v25; // [rsp+F8h] [rbp+6Fh]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  v3 = v1->ThisPtr;
  v4 = 0i64;
  if ( v3 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr) == 2 )
      v5 = (Scaleform::GFx::InteractiveObject *)v3[1].vfptr;
    else
      v5 = 0i64;
  }
  else
  {
    v5 = v1->Env->Target;
  }
  if ( v5 && v1->NArgs >= 2 )
  {
    v6 = v1->FirstArgBottomIndex - 1;
    v7 = v1->Env;
    v8 = 0i64;
    if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
      v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v9 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v8, v7) + 0x4000;
    v16 = Scaleform::Render::Cxform::Identity;
    v17 = Scaleform::Render::Matrix2x4<float>::Identity;
    v18 = 0i64;
    v19 = 0;
    *(_DWORD *)&v23[2] = 16777220;
    *(_DWORD *)v23 = 786432;
    v20 = v9;
    v21 = 65537;
    v22 = 0i64;
    if ( v9 <= 0x7EFFFFFD )
    {
      v10 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      v11 = Scaleform::GFx::AS2::Value::ToString(v10, &result, v1->Env, -1);
      v12 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, _QWORD, signed int, signed int, _QWORD, _QWORD))v5->vfptr[118].__vecDelDtor)(
              v5,
              &v16,
              v11,
              0i64,
              0i64,
              -1,
              1,
              0i64,
              0i64);
      v13 = (Scaleform::RefCountNTSImpl *)v12;
      if ( v12 )
        ++*(_DWORD *)(v12 + 8);
      v25 = v12;
      v14 = result.pNode;
      v15 = result.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( v13 )
      {
        v13->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v13->vfptr, 0);
        if ( (v13[6].RefCount & 0x800000) != 0 )
          v4 = (Scaleform::GFx::InteractiveObject *)v13;
        Scaleform::GFx::AS2::Value::SetAsCharacter(v1->Result, v4);
      }
      if ( v13 )
        Scaleform::RefCountNTSImpl::Release(v13);
    }
    if ( v18 )
      Scaleform::RefCountImpl::Release(v18);
  }
}

// File Line: 2402
// RVA: 0x6AF070
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteCreateTextField(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // r14
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  __int64 *v4; // rsi
  Scaleform::GFx::InteractiveObject *v5; // rbx
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r10
  unsigned int v9; // eax
  Scaleform::GFx::AS2::Value *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v12; // r10
  __int64 v13; // rax
  Scaleform::RefCountNTSImpl *v14; // rdi
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::InteractiveObject *v17; // r15
  __int64 v18; // rbx
  Scaleform::GFx::AS2::Value *v19; // rax
  __int64 v20; // rbx
  Scaleform::GFx::AS2::Value *v21; // rax
  __int64 v22; // rbx
  Scaleform::GFx::AS2::Value *v23; // rax
  __int64 v24; // rbx
  Scaleform::GFx::AS2::Value *v25; // rax
  __int64 v26; // [rsp+28h] [rbp-49h]
  Scaleform::Render::Cxform v27; // [rsp+38h] [rbp-39h]
  Scaleform::Render::Matrix2x4<float> v28; // [rsp+58h] [rbp-19h]
  Scaleform::Render::RenderBuffer *v29; // [rsp+78h] [rbp+7h]
  int v30; // [rsp+80h] [rbp+Fh]
  unsigned int v31; // [rsp+84h] [rbp+13h]
  int v32; // [rsp+88h] [rbp+17h]
  __int64 v33; // [rsp+90h] [rbp+1Fh]
  char v34[6]; // [rsp+98h] [rbp+27h]
  Scaleform::GFx::ASString result; // [rsp+D8h] [rbp+67h]
  __int64 v36; // [rsp+E0h] [rbp+6Fh]

  HIDWORD(v26) = -1;
  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  v3 = v1->ThisPtr;
  v4 = 0i64;
  if ( v3 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr) == 2 )
      v5 = (Scaleform::GFx::InteractiveObject *)v3[1].vfptr;
    else
      v5 = 0i64;
  }
  else
  {
    v5 = v1->Env->Target;
  }
  if ( v5 && v1->NArgs >= 6 )
  {
    v6 = v1->FirstArgBottomIndex - 1;
    v7 = v1->Env;
    v8 = 0i64;
    if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
      v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v9 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v8, v7) + 0x4000;
    v27 = Scaleform::Render::Cxform::Identity;
    v28 = Scaleform::Render::Matrix2x4<float>::Identity;
    v29 = 0i64;
    v30 = 0;
    *(_DWORD *)&v34[2] = 16777220;
    *(_DWORD *)v34 = 786432;
    v31 = v9;
    v32 = 65538;
    v33 = 0i64;
    if ( v9 <= 0x7EFFFFFD )
    {
      v10 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      v11 = Scaleform::GFx::AS2::Value::ToString(v10, &result, v1->Env, -1);
      v12 = v5->vfptr;
      *(_OWORD *)&v27.M[0][0] = 0ui64;
      LODWORD(v26) = -1;
      v13 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, _QWORD, __int64, signed int, _QWORD, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64))v12[118].__vecDelDtor)(
              v5,
              &v27,
              v11,
              0i64,
              0i64,
              v26,
              1,
              0i64,
              0i64,
              *(_QWORD *)&v27.M[1][0],
              *(_QWORD *)&v27.M[1][2],
              *(_QWORD *)&v28.M[0][0],
              *(_QWORD *)&v28.M[0][2],
              *(_QWORD *)&v28.M[1][0],
              *(_QWORD *)&v28.M[1][2]);
      v14 = (Scaleform::RefCountNTSImpl *)v13;
      if ( v13 )
        ++*(_DWORD *)(v13 + 8);
      v36 = v13;
      v15 = result.pNode;
      v16 = result.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      if ( v14 )
      {
        v14->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v14->vfptr, 0);
        v17 = 0i64;
        if ( (v14[6].RefCount & 0x800000) != 0 )
          v17 = (Scaleform::GFx::InteractiveObject *)v14;
        if ( v17 )
          v4 = (__int64 *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v17->vfptr
                                                                                      + 4
                                                                                      * (unsigned __int8)v17->AvmObjOffset))[1].__vecDelDtor)();
        v18 = *v4;
        v19 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
        (*(void (__fastcall **)(__int64 *, _QWORD, Scaleform::GFx::AS2::Value *, _QWORD))(v18 + 272))(
          v4,
          0i64,
          v19,
          0i64);
        v20 = *v4;
        v21 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
        (*(void (__fastcall **)(__int64 *, signed __int64, Scaleform::GFx::AS2::Value *))(v20 + 272))(v4, 1i64, v21);
        v22 = *v4;
        v23 = Scaleform::GFx::AS2::FnCall::Arg(v1, 4);
        (*(void (__fastcall **)(__int64 *, signed __int64, Scaleform::GFx::AS2::Value *))(v22 + 272))(v4, 8i64, v23);
        v24 = *v4;
        v25 = Scaleform::GFx::AS2::FnCall::Arg(v1, 5);
        (*(void (__fastcall **)(__int64 *, signed __int64, Scaleform::GFx::AS2::Value *))(v24 + 272))(v4, 9i64, v25);
        Scaleform::GFx::AS2::Value::SetAsCharacter(v1->Result, v17);
      }
      if ( v14 )
        Scaleform::RefCountNTSImpl::Release(v14);
    }
    if ( v29 )
      Scaleform::RefCountImpl::Release(v29);
  }
}

// File Line: 2436
// RVA: 0x6AEDD0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteRemoveMovieClip(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::InteractiveObject *v2; // rbx
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v1 = fn->ThisPtr;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v2 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v2 = 0i64;
  }
  else
  {
    v2 = fn->Env->Target;
  }
  if ( v2 )
  {
    if ( v2->Depth >= 0x4000 )
    {
      Scaleform::GFx::InteractiveObject::RemoveDisplayObject(v2);
    }
    else
    {
      v3 = Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)&v2->vfptr, &result);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v2->vfptr,
        "%s.removeMovieClip() failed - depth must be >= 0",
        v3->pNode->pData);
      v4 = result.pNode;
      v5 = result.pNode->RefCount == 1;
      --v4->RefCount;
      if ( v5 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    }
  }
}

// File Line: 2451
// RVA: 0x6AF920
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteSetMask(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rsi
  Scaleform::GFx::DisplayObject *v5; // rbx
  Scaleform::GFx::AS2::Environment *v6; // r10
  unsigned __int64 v7; // r11
  Scaleform::GFx::AS2::Value *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // r9
  Scaleform::GFx::InteractiveObject *v10; // rax
  Scaleform::GFx::DisplayObject *v11; // rdx

  v1 = fn->Result;
  v2 = fn;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v1->T.Type = 0;
  v3 = v2->ThisPtr;
  v4 = 0i64;
  if ( v3 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v2->ThisPtr) == 2 )
      v5 = (Scaleform::GFx::DisplayObject *)v3[1].vfptr;
    else
      v5 = 0i64;
  }
  else
  {
    v5 = (Scaleform::GFx::DisplayObject *)&v2->Env->Target->vfptr;
  }
  if ( v5 && v2->NArgs >= 1 )
  {
    v6 = v2->Env;
    v7 = (unsigned int)v2->FirstArgBottomIndex;
    v8 = 0i64;
    if ( (unsigned int)v7 <= 32 * (LODWORD(v6->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
      v8 = &v6->Stack.Pages.Data.Data[(unsigned __int64)(unsigned int)v7 >> 5]->Values[v7 & 0x1F];
    if ( v8->T.Type == 1 )
      goto LABEL_21;
    v9 = 0i64;
    if ( (unsigned int)v7 <= 32 * (LODWORD(v6->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
      v9 = &v6->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToCharacter(v9, v2->Env);
    if ( v10 )
    {
      if ( (v10->Flags >> 10) & 1 )
        v4 = v10;
      v11 = (Scaleform::GFx::DisplayObject *)&v4->vfptr;
    }
    else
    {
LABEL_21:
      v11 = 0i64;
    }
    Scaleform::GFx::DisplayObject::SetMask(v5, v11, 1);
  }
}

// File Line: 2479
// RVA: 0x6ACCF0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetBounds(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rsi
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rsi
  unsigned int v5; // er9
  Scaleform::GFx::AS2::Environment *v6; // r8
  signed __int64 v7; // rdx
  Scaleform::GFx::CharacterHandle *v8; // rcx
  Scaleform::GFx::DisplayObject *v9; // rax
  Scaleform::GFx::InteractiveObject *v10; // rcx
  Scaleform::GFx::DisplayObjectBase *v11; // rax
  __int64 v12; // kr00_8
  __int64 v13; // kr08_8
  Scaleform::Render::Rect<float> *v14; // rax
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Object *v16; // rax
  signed __int64 v17; // rsi
  unsigned int v18; // eax
  Scaleform::Render::Rect<float> pr; // [rsp+28h] [rbp-49h]
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+38h] [rbp-39h]
  Scaleform::Render::Matrix2x4<float> v21; // [rsp+58h] [rbp-19h]
  __int128 v22; // [rsp+78h] [rbp+7h]
  __m128 v23; // [rsp+88h] [rbp+17h]
  Scaleform::MemoryHeap *v24; // [rsp+D8h] [rbp+67h]
  Scaleform::GFx::AS2::Object *vars0; // [rsp+E0h] [rbp+6Fh]

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = 0i64;
  if ( v2 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v2[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 )
  {
    if ( v1->NArgs <= 0 )
    {
      v10 = v4;
    }
    else
    {
      v5 = v1->FirstArgBottomIndex;
      v6 = v1->Env;
      v7 = 0i64;
      if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
        v7 = (signed __int64)&v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
      if ( *(_BYTE *)v7 == 7
        && v6
        && (v8 = *(Scaleform::GFx::CharacterHandle **)(v7 + 8)) != 0i64
        && (v9 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v8, v6->Target->pASRoot->pMovieImpl)) != 0i64 )
      {
        v10 = 0i64;
        if ( SLOBYTE(v9->Flags) < 0 )
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
      if ( (v10->Flags >> 10) & 1 )
        v11 = (Scaleform::GFx::DisplayObjectBase *)&v10->vfptr;
    }
    else
    {
      v11 = 0i64;
    }
    pr = 0i64;
    *(_OWORD *)&v21.M[0][0] = _xmm;
    *(__m128 *)&v21.M[1][0] = _xmm;
    if ( v11 )
    {
      if ( v11 != (Scaleform::GFx::DisplayObjectBase *)v4 )
      {
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v11, &pmat);
        Scaleform::Render::Matrix2x4<float>::SetInverse(&v21, &pmat);
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &pmat);
        v12 = *(_QWORD *)&v21.M[0][0];
        v13 = *(_QWORD *)&v21.M[1][0];
        v21.M[0][0] = (float)(pmat.M[1][0] * v21.M[0][1]) + (float)(pmat.M[0][0] * v21.M[0][0]);
        v21.M[1][0] = (float)(pmat.M[1][0] * v21.M[1][1]) + (float)(pmat.M[0][0] * v21.M[1][0]);
        v21.M[0][1] = (float)(*(float *)&v12 * pmat.M[0][1]) + (float)(pmat.M[1][1] * v21.M[0][1]);
        v21.M[1][1] = (float)(*(float *)&v13 * pmat.M[0][1]) + (float)(pmat.M[1][1] * v21.M[1][1]);
        v21.M[1][2] = 0.0;
        v21.M[0][2] = 0.0;
        v21.M[0][3] = v21.M[0][3]
                    + (float)((float)(*((float *)&v12 + 1) * pmat.M[1][3]) + (float)(*(float *)&v12 * pmat.M[0][3]));
        v21.M[1][3] = v21.M[1][3]
                    + (float)((float)(*((float *)&v13 + 1) * pmat.M[1][3]) + (float)(*(float *)&v13 * pmat.M[0][3]));
      }
      v22 = _xmm;
      v23 = _xmm;
      v14 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Matrix2x4<float> *, __int128 *))v4->vfptr[61].__vecDelDtor)(
                                                v4,
                                                &pmat,
                                                &v22);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v21, &pr, v14);
    }
    v24 = v1->Env->StringContext.pContext->pHeap;
    v15 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, signed __int64))v24->vfptr->Alloc)(
                                           v10,
                                           96i64);
    vars0 = v15;
    if ( v15 )
    {
      Scaleform::GFx::AS2::Object::Object(v15, v1->Env);
      v3 = v16;
    }
    vars0 = v3;
    v17 = (signed __int64)&v1->Env->StringContext;
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.x1 * 0.05;
    LOBYTE(v24) = 0;
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v17,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v17 + 40i64) + 24i64) + 1360i64),
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&v24);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.x2 * 0.05;
    LOBYTE(v24) = 0;
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v17,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v17 + 40i64) + 24i64) + 1368i64),
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&v24);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.y1 * 0.05;
    LOBYTE(v24) = 0;
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v17,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v17 + 40i64) + 24i64) + 1376i64),
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&v24);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.y2 * 0.05;
    LOBYTE(v24) = 0;
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v17,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v17 + 40i64) + 24i64) + 1384i64),
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&v24);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v3);
    v18 = v3->RefCount;
    if ( v18 & 0x3FFFFFF )
    {
      v3->RefCount = v18 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v3->vfptr);
    }
  }
}

// File Line: 2526
// RVA: 0x6AD160
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetRect(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rsi
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rsi
  unsigned int v5; // er9
  Scaleform::GFx::AS2::Environment *v6; // r8
  signed __int64 v7; // rdx
  Scaleform::GFx::CharacterHandle *v8; // rcx
  Scaleform::GFx::DisplayObject *v9; // rax
  Scaleform::GFx::InteractiveObject *v10; // rcx
  Scaleform::GFx::DisplayObjectBase *v11; // rax
  __int64 v12; // kr00_8
  __int64 v13; // kr08_8
  Scaleform::Render::Rect<float> *v14; // rax
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Object *v16; // rax
  signed __int64 v17; // rsi
  unsigned int v18; // eax
  Scaleform::Render::Rect<float> pr; // [rsp+28h] [rbp-49h]
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+38h] [rbp-39h]
  Scaleform::Render::Matrix2x4<float> v21; // [rsp+58h] [rbp-19h]
  __int128 v22; // [rsp+78h] [rbp+7h]
  __m128 v23; // [rsp+88h] [rbp+17h]
  Scaleform::MemoryHeap *v24; // [rsp+D8h] [rbp+67h]
  Scaleform::GFx::AS2::Object *vars0; // [rsp+E0h] [rbp+6Fh]

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = 0i64;
  if ( v2 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v2[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 )
  {
    if ( v1->NArgs <= 0 )
    {
      v10 = v4;
    }
    else
    {
      v5 = v1->FirstArgBottomIndex;
      v6 = v1->Env;
      v7 = 0i64;
      if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
        v7 = (signed __int64)&v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
      if ( *(_BYTE *)v7 == 7
        && v6
        && (v8 = *(Scaleform::GFx::CharacterHandle **)(v7 + 8)) != 0i64
        && (v9 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v8, v6->Target->pASRoot->pMovieImpl)) != 0i64 )
      {
        v10 = 0i64;
        if ( SLOBYTE(v9->Flags) < 0 )
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
      if ( (v10->Flags >> 10) & 1 )
        v11 = (Scaleform::GFx::DisplayObjectBase *)&v10->vfptr;
    }
    else
    {
      v11 = 0i64;
    }
    pr = 0i64;
    *(_OWORD *)&v21.M[0][0] = _xmm;
    *(__m128 *)&v21.M[1][0] = _xmm;
    if ( v11 )
    {
      if ( v11 != (Scaleform::GFx::DisplayObjectBase *)v4 )
      {
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v11, &pmat);
        Scaleform::Render::Matrix2x4<float>::SetInverse(&v21, &pmat);
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &pmat);
        v12 = *(_QWORD *)&v21.M[0][0];
        v13 = *(_QWORD *)&v21.M[1][0];
        v21.M[0][0] = (float)(pmat.M[1][0] * v21.M[0][1]) + (float)(pmat.M[0][0] * v21.M[0][0]);
        v21.M[1][0] = (float)(pmat.M[1][0] * v21.M[1][1]) + (float)(pmat.M[0][0] * v21.M[1][0]);
        v21.M[0][1] = (float)(*(float *)&v12 * pmat.M[0][1]) + (float)(pmat.M[1][1] * v21.M[0][1]);
        v21.M[1][1] = (float)(*(float *)&v13 * pmat.M[0][1]) + (float)(pmat.M[1][1] * v21.M[1][1]);
        v21.M[1][2] = 0.0;
        v21.M[0][2] = 0.0;
        v21.M[0][3] = v21.M[0][3]
                    + (float)((float)(*((float *)&v12 + 1) * pmat.M[1][3]) + (float)(*(float *)&v12 * pmat.M[0][3]));
        v21.M[1][3] = v21.M[1][3]
                    + (float)((float)(*((float *)&v13 + 1) * pmat.M[1][3]) + (float)(*(float *)&v13 * pmat.M[0][3]));
      }
      v22 = _xmm;
      v23 = _xmm;
      v14 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Matrix2x4<float> *, __int128 *))v4->vfptr[62].__vecDelDtor)(
                                                v4,
                                                &pmat,
                                                &v22);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v21, &pr, v14);
    }
    v24 = v1->Env->StringContext.pContext->pHeap;
    v15 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, signed __int64))v24->vfptr->Alloc)(
                                           v10,
                                           96i64);
    vars0 = v15;
    if ( v15 )
    {
      Scaleform::GFx::AS2::Object::Object(v15, v1->Env);
      v3 = v16;
    }
    vars0 = v3;
    v17 = (signed __int64)&v1->Env->StringContext;
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.x1 * 0.05;
    LOBYTE(v24) = 0;
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v17,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v17 + 40i64) + 24i64) + 1360i64),
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&v24);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.x2 * 0.05;
    LOBYTE(v24) = 0;
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v17,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v17 + 40i64) + 24i64) + 1368i64),
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&v24);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.y1 * 0.05;
    LOBYTE(v24) = 0;
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v17,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v17 + 40i64) + 24i64) + 1376i64),
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&v24);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    LOBYTE(pmat.M[0][0]) = 3;
    *(double *)&pmat.M[0][2] = pr.y2 * 0.05;
    LOBYTE(v24) = 0;
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v17,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v17 + 40i64) + 24i64) + 1384i64),
      (Scaleform::GFx::AS2::Value *)&pmat,
      (Scaleform::GFx::AS2::PropFlags *)&v24);
    if ( LOBYTE(pmat.M[0][0]) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v3);
    v18 = v3->RefCount;
    if ( v18 & 0x3FFFFFF )
    {
      v3->RefCount = v18 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v3->vfptr);
    }
  }
}

// File Line: 2567
// RVA: 0x6AD5D0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLocalToGlobal(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::DisplayObjectBase *v5; // r14
  Scaleform::GFx::AS2::Environment *v6; // rdx
  signed __int64 v7; // rsi
  unsigned int v8; // er9
  Scaleform::GFx::AS2::ObjectInterface *v9; // rax
  Scaleform::GFx::AS2::ObjectInterface *v10; // rbx
  float v11; // xmm6_4
  float v12; // xmm2_4
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v13; // rax
  signed __int64 v14; // r8
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v15; // rax
  signed __int64 v16; // r8
  Scaleform::Render::Point3<float> ptIn; // [rsp+20h] [rbp-41h]
  Scaleform::GFx::AS2::Value v18; // [rsp+30h] [rbp-31h]
  Scaleform::GFx::AS2::Value v19; // [rsp+50h] [rbp-11h]
  Scaleform::GFx::AS2::Value v20; // [rsp+70h] [rbp+Fh]
  char v21; // [rsp+C8h] [rbp+67h]
  Scaleform::Render::Point<float> result; // [rsp+D0h] [rbp+6Fh]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  v3 = v1->ThisPtr;
  v4 = 0i64;
  if ( v3 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr) == 2 )
      v5 = (Scaleform::GFx::DisplayObjectBase *)v3[1].vfptr;
    else
      v5 = 0i64;
  }
  else
  {
    v5 = (Scaleform::GFx::DisplayObjectBase *)&v1->Env->Target->vfptr;
  }
  if ( v5 && v1->NArgs >= 1 )
  {
    v6 = v1->Env;
    v7 = (signed __int64)&v6->StringContext;
    v8 = v1->FirstArgBottomIndex;
    if ( v8 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
      v4 = &v6->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, v6);
    v10 = v9;
    if ( v9 )
    {
      v19.T.Type = 0;
      v18.T.Type = 0;
      v9->vfptr->GetMemberRaw(
        v9,
        (Scaleform::GFx::AS2::ASStringContext *)v7,
        (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v7 + 40i64) + 24i64) + 1344i64),
        &v19);
      v10->vfptr->GetMemberRaw(
        v10,
        (Scaleform::GFx::AS2::ASStringContext *)v7,
        (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v7 + 40i64) + 24i64) + 1352i64),
        &v18);
      if ( (unsigned __int8)(v19.T.Type - 3) <= 1u && (unsigned __int8)(v18.T.Type - 3) <= 1u )
      {
        v11 = Scaleform::GFx::AS2::Value::ToNumber(&v18, v1->Env);
        v12 = Scaleform::GFx::AS2::Value::ToNumber(&v19, v1->Env);
        ptIn.x = v12 * 20.0;
        ptIn.y = v11 * 20.0;
        ptIn.z = 0.0;
        Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(v5, &result, &ptIn);
        v20.T.Type = 3;
        v20.NV.NumberValue = result.x * 0.05;
        v21 = 0;
        v13 = v10->vfptr;
        v14 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v7 + 40i64) + 24i64) + 1344i64;
        *(_QWORD *)&ptIn.x = &v21;
        v13->SetMemberRaw(
          v10,
          (Scaleform::GFx::AS2::ASStringContext *)v7,
          (Scaleform::GFx::ASString *)v14,
          &v20,
          (Scaleform::GFx::AS2::PropFlags *)&v21);
        if ( v20.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v20);
        v20.T.Type = 3;
        v20.NV.NumberValue = result.y * 0.05;
        v21 = 0;
        v15 = v10->vfptr;
        v16 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v7 + 40i64) + 24i64) + 1352i64;
        *(_QWORD *)&ptIn.x = &v21;
        v15->SetMemberRaw(
          v10,
          (Scaleform::GFx::AS2::ASStringContext *)v7,
          (Scaleform::GFx::ASString *)v16,
          &v20,
          (Scaleform::GFx::AS2::PropFlags *)&v21);
        if ( v20.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v20);
      }
      if ( v18.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v18);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
  }
}ef

// File Line: 2593
// RVA: 0x6AD860
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGlobalToLocal(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::DisplayObjectBase *v5; // r14
  Scaleform::GFx::AS2::Environment *v6; // rdx
  signed __int64 v7; // rsi
  unsigned int v8; // er9
  Scaleform::GFx::AS2::ObjectInterface *v9; // rax
  Scaleform::GFx::AS2::ObjectInterface *v10; // rbx
  float v11; // xmm6_4
  float v12; // xmm1_4
  Scaleform::Render::Point<float> *v13; // rax
  float v14; // xmm0_4
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v15; // rax
  signed __int64 v16; // r8
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v17; // rax
  signed __int64 v18; // r8
  Scaleform::GFx::AS2::Value v19; // [rsp+20h] [rbp-31h]
  Scaleform::GFx::AS2::Value v20; // [rsp+40h] [rbp-11h]
  Scaleform::GFx::AS2::Value v21; // [rsp+60h] [rbp+Fh]
  Scaleform::Render::Point<float> result; // [rsp+B8h] [rbp+67h]
  Scaleform::Render::Point<float> ptIn; // [rsp+C0h] [rbp+6Fh]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  v3 = v1->ThisPtr;
  v4 = 0i64;
  if ( v3 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr) == 2 )
      v5 = (Scaleform::GFx::DisplayObjectBase *)v3[1].vfptr;
    else
      v5 = 0i64;
  }
  else
  {
    v5 = (Scaleform::GFx::DisplayObjectBase *)&v1->Env->Target->vfptr;
  }
  if ( v5 && v1->NArgs >= 1 )
  {
    v6 = v1->Env;
    v7 = (signed __int64)&v6->StringContext;
    v8 = v1->FirstArgBottomIndex;
    if ( v8 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
      v4 = &v6->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, v6);
    v10 = v9;
    if ( v9 )
    {
      v20.T.Type = 0;
      v19.T.Type = 0;
      v9->vfptr->GetMemberRaw(
        v9,
        (Scaleform::GFx::AS2::ASStringContext *)v7,
        (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v7 + 40i64) + 24i64) + 1344i64),
        &v20);
      v10->vfptr->GetMemberRaw(
        v10,
        (Scaleform::GFx::AS2::ASStringContext *)v7,
        (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v7 + 40i64) + 24i64) + 1352i64),
        &v19);
      if ( (unsigned __int8)(v20.T.Type - 3) <= 1u && (unsigned __int8)(v19.T.Type - 3) <= 1u )
      {
        v11 = Scaleform::GFx::AS2::Value::ToNumber(&v19, v1->Env);
        v12 = Scaleform::GFx::AS2::Value::ToNumber(&v20, v1->Env);
        ptIn.x = v12 * 20.0;
        ptIn.y = v11 * 20.0;
        v13 = Scaleform::GFx::DisplayObjectBase::GlobalToLocal(v5, &result, &ptIn);
        v14 = v13->y;
        ptIn.x = v13->x;
        ptIn.y = v14;
        v21.T.Type = 3;
        v21.NV.NumberValue = ptIn.x * 0.05;
        LOBYTE(result.x) = 0;
        v15 = v10->vfptr;
        v16 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v7 + 40i64) + 24i64) + 1344i64;
        *(_QWORD *)&v19.T.Type = &result;
        v15->SetMemberRaw(
          v10,
          (Scaleform::GFx::AS2::ASStringContext *)v7,
          (Scaleform::GFx::ASString *)v16,
          &v21,
          (Scaleform::GFx::AS2::PropFlags *)&result);
        if ( v21.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v21);
        v21.T.Type = 3;
        v21.NV.NumberValue = ptIn.y * 0.05;
        LOBYTE(result.x) = 0;
        v17 = v10->vfptr;
        v18 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v7 + 40i64) + 24i64) + 1352i64;
        *(_QWORD *)&v19.T.Type = &result;
        ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, signed __int64, signed __int64, Scaleform::GFx::AS2::Value *))v17->SetMemberRaw)(
          v10,
          v7,
          v18,
          &v21);
        if ( v21.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v21);
      }
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
      if ( v20.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v20);
    }
  }
}

// File Line: 2621
// RVA: 0x6ADAF0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteHitTest(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // r14
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::InteractiveObject *v4; // r14
  Scaleform::GFx::AS2::Value *v5; // rbx
  signed int v6; // eax
  unsigned __int8 v7; // r15
  unsigned __int64 v8; // r8
  Scaleform::GFx::AS2::Environment *v9; // rdx
  Scaleform::GFx::AS2::Value *v10; // r9
  float v11; // xmm9_4
  unsigned int v12; // er8
  Scaleform::GFx::AS2::Environment *v13; // rdx
  float v14; // xmm8_4
  float v15; // xmm8_4
  float v16; // xmm9_4
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::GFx::AS2::Value *v18; // rax
  Scaleform::GFx::MovieImpl *v19; // rdi
  float v20; // xmm9_4
  signed __int64 v21; // rbx
  char v22; // di
  float v23; // xmm2_4
  float v24; // xmm1_4
  Scaleform::GFx::AS2::Value *v25; // rbx
  Scaleform::GFx::AS2::Value *v26; // rcx
  Scaleform::GFx::AS2::Environment *v27; // rax
  Scaleform::GFx::DisplayObject *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // rcx
  bool v30; // zf
  Scaleform::Render::Matrix2x4<float> m; // [rsp+40h] [rbp-C0h]
  Scaleform::Render::Matrix2x4<float> v32; // [rsp+60h] [rbp-A0h]
  float v33; // [rsp+80h] [rbp-80h]
  float v34; // [rsp+84h] [rbp-7Ch]
  float v35; // [rsp+88h] [rbp-78h]
  float v36; // [rsp+8Ch] [rbp-74h]
  float v37; // [rsp+90h] [rbp-70h]
  float v38; // [rsp+94h] [rbp-6Ch]
  float v39; // [rsp+98h] [rbp-68h]
  float v40; // [rsp+9Ch] [rbp-64h]
  __int128 Dst; // [rsp+A0h] [rbp-60h]
  __m128 v42; // [rsp+B0h] [rbp-50h]
  float v43; // [rsp+C0h] [rbp-40h]
  float v44; // [rsp+C4h] [rbp-3Ch]
  float v45; // [rsp+C8h] [rbp-38h]
  float v46; // [rsp+CCh] [rbp-34h]
  Scaleform::Render::Rect<float> r; // [rsp+D0h] [rbp-30h]
  Scaleform::Render::Matrix3x4<float> pmat; // [rsp+E0h] [rbp-20h]
  Scaleform::Render::Rect<float> v49; // [rsp+110h] [rbp+10h]
  __int64 v50; // [rsp+120h] [rbp+20h]
  Scaleform::GFx::ASString result; // [rsp+1A0h] [rbp+A0h]
  Scaleform::Render::Point<float> ptOut; // [rsp+1A8h] [rbp+A8h]

  v50 = -2i64;
  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = 0i64;
  if ( v2 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v2[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 )
  {
    v5 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v5->T.Type = 2;
    v5->V.BooleanValue = 0;
    Dst = _xmm;
    v42 = _xmm;
    ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Rect<float> *, __int128 *))v4->vfptr[61].__vecDelDtor)(
      v4,
      &r,
      &Dst);
    if ( r.x2 != r.x1 || r.y2 != r.y1 )
    {
      v6 = v1->NArgs;
      if ( v6 >= 2 )
      {
        v7 = 0;
        v8 = (unsigned int)(v1->FirstArgBottomIndex - 1);
        v9 = v1->Env;
        v10 = 0i64;
        if ( (unsigned int)v8 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                               + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
          v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[(LOBYTE(v1->FirstArgBottomIndex) - 1) & 0x1F];
        v11 = Scaleform::GFx::AS2::Value::ToNumber(v10, v9);
        v12 = v1->FirstArgBottomIndex;
        v13 = v1->Env;
        if ( v12 <= 32 * (LODWORD(v13->Stack.Pages.Data.Size) - 1)
                  + (unsigned int)((_QWORD)((char *)v13->Stack.pCurrent - (char *)v13->Stack.pPageStart) >> 5) )
          v3 = &v13->Stack.Pages.Data.Data[(unsigned __int64)v12 >> 5]->Values[v12 & 0x1F];
        v14 = Scaleform::GFx::AS2::Value::ToNumber(v3, v13);
        v15 = v14 * 20.0;
        v16 = v11 * 20.0;
        if ( v1->NArgs >= 3 )
        {
          v17 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
          v7 = Scaleform::GFx::AS2::Value::ToBool(v17, v1->Env) != 0;
        }
        if ( v1->NArgs >= 4 )
        {
          v18 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
          v7 |= Scaleform::GFx::AS2::Value::ToBool(v18, v1->Env) != 0 ? 2 : 0;
        }
        v19 = v4->pASRoot->pMovieImpl;
        if ( v19 && Scaleform::GFx::DisplayObjectBase::Is3D((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, 1) )
        {
          v20 = (float)((float)((float)(v16 - (float)(v19->ViewOffsetY * 20.0))
                              / (float)(v19->VisibleFrameRect.y2 - v19->VisibleFrameRect.y1))
                      * 2.0)
              - 1.0;
          v21 = (signed __int64)&v19->ScreenToWorld;
          *(float *)v21 = (float)((float)((float)(v15 - (float)(v19->ViewOffsetX * 20.0))
                                        / (float)(v19->VisibleFrameRect.x2 - v19->VisibleFrameRect.x1))
                                * 2.0)
                        - 1.0;
          *(_DWORD *)(v21 + 4) = LODWORD(v20) ^ _xmm[0];
          memset(&Dst, 0, 0x30ui64);
          LODWORD(Dst) = 1065353216;
          v42.m128_i32[1] = 1065353216;
          v45 = 1.0;
          memset(&v32, 0, 0x40ui64);
          v32.M[0][0] = 1.0;
          v32.M[1][1] = 1.0;
          v35 = 1.0;
          v40 = 1.0;
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Matrix2x4<float> *, _QWORD))v4->vfptr[6].__vecDelDtor)(
                 v4,
                 &v32,
                 0i64) )
          {
            *(_OWORD *)&v19->ScreenToWorld.MatProj.M[0][0] = *(_OWORD *)&v32.M[0][0];
            *(_OWORD *)&v19->ScreenToWorld.MatProj.M[1][0] = *(_OWORD *)&v32.M[1][0];
            v19->ScreenToWorld.MatProj.M[2][0] = v33;
            v19->ScreenToWorld.MatProj.M[2][1] = v34;
            v19->ScreenToWorld.MatProj.M[2][2] = v35;
            v19->ScreenToWorld.MatProj.M[2][3] = v36;
            v19->ScreenToWorld.MatProj.M[3][0] = v37;
            v19->ScreenToWorld.MatProj.M[3][1] = v38;
            v19->ScreenToWorld.MatProj.M[3][2] = v39;
            v19->ScreenToWorld.MatProj.M[3][3] = v40;
          }
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int128 *, _QWORD))v4->vfptr[9].__vecDelDtor)(
                 v4,
                 &Dst,
                 0i64) )
          {
            *(_OWORD *)&v19->ScreenToWorld.MatView.M[0][0] = Dst;
            *(__m128 *)&v19->ScreenToWorld.MatView.M[1][0] = v42;
            v19->ScreenToWorld.MatView.M[2][0] = v43;
            v19->ScreenToWorld.MatView.M[2][1] = v44;
            v19->ScreenToWorld.MatView.M[2][2] = v45;
            v19->ScreenToWorld.MatView.M[2][3] = v46;
          }
          memset(&pmat, 0, 0x30ui64);
          pmat.M[0][0] = 1.0;
          pmat.M[1][1] = 1.0;
          pmat.M[2][2] = 1.0;
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &pmat);
          *(_OWORD *)&v19->ScreenToWorld.MatWorld.M[0][0] = *(_OWORD *)&pmat.M[0][0];
          *(_OWORD *)&v19->ScreenToWorld.MatWorld.M[1][0] = *(_OWORD *)&pmat.M[1][0];
          *(_OWORD *)&v19->ScreenToWorld.MatWorld.M[2][0] = *(_OWORD *)&pmat.M[2][0];
          Scaleform::Render::ScreenToWorld::GetWorldPoint(&v19->ScreenToWorld, &ptOut);
          v22 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Point<float> *, _QWORD))v4->vfptr[63].__vecDelDtor)(
                  v4,
                  &ptOut,
                  v7);
          goto LABEL_57;
        }
        *(_OWORD *)&m.M[0][0] = _xmm;
        *(__m128 *)&m.M[1][0] = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetLevelMatrix((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &m);
        v32 = m;
        Scaleform::Render::Matrix2x4<float>::SetInverse(&v32, &m);
        v23 = (float)((float)(v32.M[0][1] * v16) + (float)(v32.M[0][0] * v15)) + v32.M[0][3];
        *(float *)&result.pNode = (float)((float)(v32.M[0][1] * v16) + (float)(v32.M[0][0] * v15)) + v32.M[0][3];
        v24 = (float)((float)(v32.M[1][1] * v16) + (float)(v32.M[1][0] * v15)) + v32.M[1][3];
        *((float *)&result.pNode + 1) = (float)((float)(v32.M[1][1] * v16) + (float)(v32.M[1][0] * v15)) + v32.M[1][3];
        if ( v4->Flags & 1 )
          goto LABEL_26;
        if ( v23 > r.x2 || v23 < r.x1 || v24 > r.y2 || v24 < r.y1 )
        {
          v25 = v1->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
          v25->V.BooleanValue = 0;
        }
        else
        {
          if ( v7 & 1 )
          {
LABEL_26:
            v22 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::ASString *, _QWORD))v4->vfptr[63].__vecDelDtor)(
                    v4,
                    &result,
                    v7);
LABEL_57:
            v25 = v1->Result;
            Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
            v25->V.BooleanValue = v22;
            goto LABEL_58;
          }
          v25 = v1->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
          v25->V.BooleanValue = 1;
        }
LABEL_58:
        v25->T.Type = 2;
        return;
      }
      if ( v6 == 1 )
      {
        v26 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        if ( v26->T.Type == 7 )
        {
          v3 = (Scaleform::GFx::AS2::Value *)Scaleform::GFx::AS2::Value::ToCharacter(v26, v1->Env);
        }
        else
        {
          Scaleform::GFx::AS2::Value::ToString(v26, &result, v1->Env, -1);
          LOBYTE(pmat.M[0][0]) = 0;
          if ( Scaleform::GFx::AS2::Environment::GetVariable(
                 v1->Env,
                 &result,
                 (Scaleform::GFx::AS2::Value *)&pmat,
                 0i64,
                 0i64,
                 0i64,
                 0) )
          {
            v27 = v1->Env;
            if ( LOBYTE(pmat.M[0][0]) == 7 )
            {
              if ( v27 )
              {
                if ( *(_QWORD *)&pmat.M[0][2] )
                {
                  v28 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                          *(Scaleform::GFx::CharacterHandle **)&pmat.M[0][2],
                          v27->Target->pASRoot->pMovieImpl);
                  if ( v28 )
                  {
                    if ( SLOBYTE(v28->Flags) < 0 )
                      v3 = (Scaleform::GFx::AS2::Value *)v28;
                  }
                }
              }
            }
          }
          if ( LOBYTE(pmat.M[0][0]) >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pmat);
          v29 = result.pNode;
          v30 = result.pNode->RefCount == 1;
          --v29->RefCount;
          if ( v30 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v29);
        }
        if ( v3 )
        {
          Dst = _xmm;
          v42 = _xmm;
          (*(void (__fastcall **)(Scaleform::GFx::AS2::Value *, Scaleform::Render::Rect<float> *, __int128 *))(*(_QWORD *)&v3->T.Type + 488i64))(
            v3,
            &v49,
            &Dst);
          if ( v49.x2 != v49.x1 || v49.y2 != v49.y1 )
          {
            Dst = _xmm;
            v42 = _xmm;
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
              (Scaleform::GFx::DisplayObjectBase *)&v4->vfptr,
              (Scaleform::Render::Matrix2x4<float> *)&Dst);
            Scaleform::Render::Matrix2x4<float>::EncloseTransform(
              (Scaleform::Render::Matrix2x4<float> *)&Dst,
              (Scaleform::Render::Rect<float> *)&m,
              &r);
            Dst = _xmm;
            v42 = _xmm;
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
              (Scaleform::GFx::DisplayObjectBase *)v3,
              (Scaleform::Render::Matrix2x4<float> *)&Dst);
            Scaleform::Render::Matrix2x4<float>::EncloseTransform(
              (Scaleform::Render::Matrix2x4<float> *)&Dst,
              (Scaleform::Render::Rect<float> *)&v32,
              &v49);
            v22 = m.M[0][3] >= v32.M[0][1]
               && v32.M[0][3] >= m.M[0][1]
               && v32.M[0][2] >= m.M[0][0]
               && m.M[0][2] >= v32.M[0][0];
            goto LABEL_57;
          }
        }
      }
    }
  }
}:Render::Rect<float> *)&v32,
              &v49);
            v22 = m.M[0][3] >= v32.M[0][1]
              

// File Line: 2725
// RVA: 0x6AB8E0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteSwapDepths(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // r14
  Scaleform::GFx::InteractiveObject *v2; // rsi
  Scaleform::GFx::AS2::FnCall *v3; // rbp
  Scaleform::GFx::InteractiveObject *v4; // r14
  unsigned int v5; // edx
  Scaleform::GFx::InteractiveObject *v6; // r12
  Scaleform::GFx::AS2::Environment *v7; // r15
  Scaleform::GFx::AS2::Value *v8; // rbx
  Scaleform::GFx::DisplayObjectBase *v9; // rcx
  unsigned int v10; // edi
  Scaleform::GFx::DisplayObjectBase *v11; // rdi
  Scaleform::GFx::InteractiveObject *v12; // rax
  Scaleform::GFx::AS2::Environment *v13; // rbx
  int v14; // ebx
  unsigned int frame; // eax

  v1 = fn->ThisPtr;
  v2 = 0i64;
  v3 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) - 2 > 3 )
      v4 = 0i64;
    else
      v4 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( !v4 || v3->NArgs < 1 )
    return;
  v5 = v3->FirstArgBottomIndex;
  v6 = v4->pParent;
  v7 = v3->Env;
  v8 = 0i64;
  if ( v5 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
           + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
    v8 = &v7->Stack.Pages.Data.Data[(unsigned __int64)v5 >> 5]->Values[v5 & 0x1F];
  v9 = 0i64;
  if ( (v4->Flags >> 10) & 1 )
    v9 = (Scaleform::GFx::DisplayObjectBase *)&v4->vfptr;
  if ( (unsigned __int8)(v8->T.Type - 3) <= 1u )
  {
    v10 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v8, v7) + 0x4000;
    if ( v10 > 0x7EFFFFFD )
      return;
    goto LABEL_22;
  }
  if ( v9 )
  {
    v11 = (Scaleform::GFx::DisplayObjectBase *)&v7->Target->vfptr;
    *((_BYTE *)v7 + 382) &= 0xFDu;
    v7->Target = (Scaleform::GFx::InteractiveObject *)v9;
    v7->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(v9);
    v12 = Scaleform::GFx::AS2::Environment::FindTargetByValue(v3->Env, v8);
    v13 = v3->Env;
    *((_BYTE *)v13 + 382) &= 0xFDu;
    v13->Target = (Scaleform::GFx::InteractiveObject *)v11;
    v2 = v12;
    v13->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(v11);
  }
  else
  {
    v2 = Scaleform::GFx::AS2::Environment::FindTargetByValue(v7, v8);
  }
  if ( v2 && v2 != v4 && v6 == v2->pParent )
  {
    v10 = v2->Depth;
LABEL_22:
    if ( v4->Depth >= 0 )
    {
      v4->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 0);
      if ( v6 )
      {
        v14 = v4->Depth;
        frame = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v6->vfptr[107].__vecDelDtor)(v6);
        if ( Scaleform::GFx::DisplayList::SwapDepths(
               (Scaleform::GFx::DisplayList *)&v6[1],
               (Scaleform::GFx::DisplayObjectBase *)&v6->vfptr,
               v14,
               v10,
               frame) )
        {
          _((AMD_HD3D *)v6);
          if ( v2 )
            v2->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 0);
        }
      }
    }
  }
}

// File Line: 2787
// RVA: 0x6AF330
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetNextHighestDepth(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::InteractiveObject *v3; // rcx
  int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // rbx
  int v6; // esi

  v1 = fn->ThisPtr;
  v2 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v3 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v3 = 0i64;
  }
  else
  {
    v3 = fn->Env->Target;
  }
  if ( v3 )
  {
    v4 = Scaleform::GFx::DisplayList::GetLargestDepthInUse((Scaleform::GFx::DisplayList *)&v3[1]);
    v5 = v2->Result;
    v6 = v4 - 0x3FFF;
    if ( v4 - 0x3FFF < 0 )
      v6 = 0;
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v2->Result);
    v5->NV.Int32Value = v6;
    v5->T.Type = 4;
  }
}

// File Line: 2798
// RVA: 0x6AF3C0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetInstanceAtDepth(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rsi
  Scaleform::GFx::DisplayObjContainer *v5; // rbx
  Scaleform::GFx::AS2::Environment *v6; // rdx
  unsigned __int64 v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r9
  long double v9; // xmm0_8
  Scaleform::GFx::DisplayObjectBase *v10; // rax

  v1 = fn->Result;
  v2 = fn;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v1->T.Type = 0;
  v3 = v2->ThisPtr;
  v4 = 0i64;
  if ( v3 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v2->ThisPtr) == 2 )
      v5 = (Scaleform::GFx::DisplayObjContainer *)v3[1].vfptr;
    else
      v5 = 0i64;
  }
  else
  {
    v5 = (Scaleform::GFx::DisplayObjContainer *)v2->Env->Target;
  }
  if ( v5 && v2->NArgs >= 1 )
  {
    v6 = v2->Env;
    v7 = (unsigned int)v2->FirstArgBottomIndex;
    v8 = 0i64;
    if ( (unsigned int)v7 <= 32 * (LODWORD(v6->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
      v8 = &v6->Stack.Pages.Data.Data[v7 >> 5]->Values[v2->FirstArgBottomIndex & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToNumber(v8, v6);
    v10 = Scaleform::GFx::DisplayObjContainer::GetCharacterAtDepth(v5, (signed int)v9 + 0x4000);
    if ( v10 )
    {
      if ( SLOBYTE(v10->Flags) < 0 )
        v4 = (Scaleform::GFx::InteractiveObject *)v10;
      Scaleform::GFx::AS2::Value::SetAsCharacter(v2->Result, v4);
    }
  }
}

// File Line: 2820
// RVA: 0x6AF4B0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetTextSnapshot(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rcx

  v1 = fn->ThisPtr;
  if ( v1 )
    (*(void (**)(void))&v1->vfptr->gap8[8])();
}

// File Line: 2835
// RVA: 0x6AF4D0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteGetSWFVersion(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::InteractiveObject *v3; // rcx
  unsigned int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // rbx
  unsigned int v6; // esi

  v1 = fn->ThisPtr;
  v2 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v3 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v3 = 0i64;
  }
  else
  {
    v3 = fn->Env->Target;
  }
  if ( v3 )
  {
    v4 = Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
    v5 = v2->Result;
    v6 = v4;
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v2->Result);
    v5->NV.Int32Value = v6;
    v5->T.Type = 4;
  }
}

// File Line: 2843
// RVA: 0x6AF550
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteStartDrag(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::FnCall *v3; // rsi
  Scaleform::GFx::Sprite *v4; // rdi
  bool v5; // bp
  Scaleform::GFx::AS2::Environment *v6; // rdx
  unsigned __int64 v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::Environment *v9; // rdx
  int v10; // er8
  unsigned int v11; // er8
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
  bool v34; // dl
  int v35; // eax
  Scaleform::GFx::MovieImpl::DragState st; // [rsp+20h] [rbp-78h]

  v1 = fn->ThisPtr;
  v2 = 0i64;
  v3 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(v1) == 2 )
      v4 = (Scaleform::GFx::Sprite *)v1[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = (Scaleform::GFx::Sprite *)fn->Env->Target;
  }
  if ( v4 )
  {
    v5 = 0;
    st.pCharacter = 0i64;
    st.pTopmostEntity = 0i64;
    *(_WORD *)&st.LockCenter = 0;
    st.BoundLT = 0i64;
    st.BoundRB = 0i64;
    st.CenterDelta = 0i64;
    st.MouseIndex = -1;
    if ( v3->NArgs > 0 )
    {
      v6 = v3->Env;
      v7 = (unsigned int)v3->FirstArgBottomIndex;
      v8 = 0i64;
      if ( (unsigned int)v7 <= 32 * (LODWORD(v6->Stack.Pages.Data.Size) - 1)
                             + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
        v8 = &v6->Stack.Pages.Data.Data[v7 >> 5]->Values[v3->FirstArgBottomIndex & 0x1F];
      v5 = Scaleform::GFx::AS2::Value::ToBool(v8, v6);
      if ( v3->NArgs > 4 )
      {
        v9 = v3->Env;
        v10 = v3->FirstArgBottomIndex;
        st.Bound = 1;
        v11 = v10 - 1;
        v12 = 0i64;
        if ( v11 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                  + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
          v12 = &v9->Stack.Pages.Data.Data[(unsigned __int64)v11 >> 5]->Values[v11 & 0x1F];
        v13 = Scaleform::GFx::AS2::Value::ToNumber(v12, v9);
        v14 = v3->Env;
        v15 = v13;
        v16 = (unsigned int)(v3->FirstArgBottomIndex - 2);
        v17 = v15 * 20.0;
        v18 = 0i64;
        if ( (unsigned int)v16 <= 32 * (LODWORD(v14->Stack.Pages.Data.Size) - 1)
                                + (unsigned int)((_QWORD)((char *)v14->Stack.pCurrent - (char *)v14->Stack.pPageStart) >> 5) )
          v18 = &v14->Stack.Pages.Data.Data[v16 >> 5]->Values[(LOBYTE(v3->FirstArgBottomIndex) - 2) & 0x1F];
        v19 = Scaleform::GFx::AS2::Value::ToNumber(v18, v14);
        v20 = v3->Env;
        v21 = v19;
        v22 = (unsigned int)(v3->FirstArgBottomIndex - 3);
        v23 = v21 * 20.0;
        v24 = 0i64;
        if ( (unsigned int)v22 <= 32 * (LODWORD(v20->Stack.Pages.Data.Size) - 1)
                                + (unsigned int)((_QWORD)((char *)v20->Stack.pCurrent - (char *)v20->Stack.pPageStart) >> 5) )
          v24 = &v20->Stack.Pages.Data.Data[v22 >> 5]->Values[(LOBYTE(v3->FirstArgBottomIndex) - 3) & 0x1F];
        v25 = Scaleform::GFx::AS2::Value::ToNumber(v24, v20);
        v26 = v3->Env;
        v27 = v25;
        v28 = (unsigned int)(v3->FirstArgBottomIndex - 4);
        v29 = v27 * 20.0;
        if ( (unsigned int)v28 <= 32 * (LODWORD(v26->Stack.Pages.Data.Size) - 1)
                                + (unsigned int)((_QWORD)((char *)v26->Stack.pCurrent - (char *)v26->Stack.pPageStart) >> 5) )
          v2 = &v26->Stack.Pages.Data.Data[v28 >> 5]->Values[(LOBYTE(v3->FirstArgBottomIndex) - 4) & 0x1F];
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
    st.pCharacter = (Scaleform::GFx::InteractiveObject *)&v4->vfptr;
    Scaleform::GFx::MovieImpl::DragState::InitCenterDelta(&st, v5, 0);
    Scaleform::GFx::MovieImpl::SetDragState(v4->pASRoot->pMovieImpl, &st);
    v34 = (v4->Flags >> 21) & 1 && !((v4->Flags >> 22) & 1);
    v35 = Scaleform::GFx::Sprite::CheckAdvanceStatus(v4, v34);
    if ( v35 == -1 )
    {
      v4->Flags |= 0x400000u;
    }
    else if ( v35 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)&v4->vfptr);
    }
  }
}

// File Line: 2880
// RVA: 0x6AF880
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteStopDrag(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::Sprite *v2; // rbx
  bool v3; // dl
  int v4; // eax

  v1 = fn->ThisPtr;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v2 = (Scaleform::GFx::Sprite *)v1[1].vfptr;
    else
      v2 = 0i64;
  }
  else
  {
    v2 = (Scaleform::GFx::Sprite *)fn->Env->Target;
  }
  if ( v2 )
  {
    Scaleform::GFx::MovieImpl::StopDrag(v2->pASRoot->pMovieImpl, 0);
    v3 = (v2->Flags >> 21) & 1 && !((v2->Flags >> 22) & 1);
    v4 = Scaleform::GFx::Sprite::CheckAdvanceStatus(v2, v3);
    if ( v4 == -1 )
    {
      v2->Flags |= 0x400000u;
    }
    else if ( v4 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)&v2->vfptr);
    }
  }
}

// File Line: 2891
// RVA: 0x6AFA50
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLoadMovie(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rbx
  Scaleform::GFx::InteractiveObject *v3; // rsi
  signed int v4; // eax
  Scaleform::GFx::LoadQueueEntry::LoadMethod v5; // ebx
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  const char *v11; // rdx
  __int64 v12; // rcx
  char v13; // al
  __int64 v14; // rax
  char v15; // cl
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  unsigned int v18; // er9
  Scaleform::GFx::AS2::Environment *v19; // r8
  Scaleform::GFx::AS2::Value *v20; // r10
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASString v22; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString v23; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v3 = (Scaleform::GFx::InteractiveObject *)v2[1].vfptr;
    else
      v3 = 0i64;
  }
  else
  {
    v3 = fn->Env->Target;
  }
  if ( v3 )
  {
    v4 = v1->NArgs;
    if ( v4 > 0 )
    {
      v5 = 0;
      if ( v4 > 1 )
      {
        v6 = v1->FirstArgBottomIndex - 1;
        v7 = v1->Env;
        v8 = 0i64;
        if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
                 + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
          v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
        v9 = Scaleform::GFx::AS2::Value::ToString(v8, &result, v7, -1);
        Scaleform::GFx::ASString::ToLower(v9, &v22);
        v10 = result.pNode;
        v16 = result.pNode->RefCount == 1;
        --v10->RefCount;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
        v11 = v22.pNode->pData;
        v12 = 0i64;
        while ( 1 )
        {
          v13 = v11[v12++];
          if ( v13 != aGet[v12 - 1] )
            break;
          if ( v12 == 4 )
          {
            v5 = 1;
            goto LABEL_23;
          }
        }
        v14 = 0i64;
        while ( 1 )
        {
          v15 = v11[v14++];
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
          v5 = 2;
LABEL_23:
        v17 = v22.pNode;
        v16 = v22.pNode->RefCount == 1;
        --v17->RefCount;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      }
      v18 = v1->FirstArgBottomIndex;
      v19 = v1->Env;
      v20 = 0i64;
      if ( v18 <= 32 * ((unsigned int)v19->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v19->Stack.pCurrent - (char *)v19->Stack.pPageStart) >> 5) )
        v20 = &v19->Stack.Pages.Data.Data[v18 >> 5]->Values[v18 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v20, &v23, v19, -1);
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
        (Scaleform::GFx::AS2::MovieRoot *)v3->pASRoot,
        v3,
        v23.pNode->pData,
        v5,
        0i64);
      v21 = v23.pNode;
      v16 = v23.pNode->RefCount == 1;
      --v21->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    }
  }
}

// File Line: 2916
// RVA: 0x6AFC20
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteUnloadMovie(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::InteractiveObject *v2; // rcx

  v1 = fn->ThisPtr;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v2 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v2 = 0i64;
  }
  else
  {
    v2 = fn->Env->Target;
  }
  if ( v2 )
    Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
      (Scaleform::GFx::AS2::MovieRoot *)v2->pASRoot,
      v2,
      &customWorldMapCaption,
      0,
      0i64);
}

// File Line: 2925
// RVA: 0x6AFDF0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLoadVariables(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rbx
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::InteractiveObject *v4; // rbp
  signed int v5; // eax
  Scaleform::GFx::LoadQueueEntry::LoadMethod v6; // ebx
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  const char *v12; // rdx
  __int64 v13; // rcx
  char v14; // al
  __int64 v15; // rax
  char v16; // cl
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned int v19; // er9
  Scaleform::GFx::AS2::Environment *v20; // r8
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASString v22; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString v23; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h]

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = 0i64;
  if ( v2 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v2[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 )
  {
    v5 = v1->NArgs;
    if ( v5 > 0 )
    {
      v6 = 0;
      if ( v5 > 1 )
      {
        v7 = v1->FirstArgBottomIndex - 1;
        v8 = v1->Env;
        v9 = 0i64;
        if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
                 + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
          v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
        v10 = Scaleform::GFx::AS2::Value::ToString(v9, &result, v8, -1);
        Scaleform::GFx::ASString::ToLower(v10, &v22);
        v11 = result.pNode;
        v17 = result.pNode->RefCount == 1;
        --v11->RefCount;
        if ( v17 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        v12 = v22.pNode->pData;
        v13 = 0i64;
        while ( 1 )
        {
          v14 = v12[v13++];
          if ( v14 != aGet[v13 - 1] )
            break;
          if ( v13 == 4 )
          {
            v6 = 1;
            goto LABEL_23;
          }
        }
        v15 = 0i64;
        while ( 1 )
        {
          v16 = v12[v15++];
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
          v6 = 2;
LABEL_23:
        v18 = v22.pNode;
        v17 = v22.pNode->RefCount == 1;
        --v18->RefCount;
        if ( v17 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
      v19 = v1->FirstArgBottomIndex;
      v20 = v1->Env;
      if ( v19 <= 32 * ((unsigned int)v20->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v20->Stack.pCurrent - (char *)v20->Stack.pPageStart) >> 5) )
        v3 = &v20->Stack.Pages.Data.Data[v19 >> 5]->Values[v19 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v3, &v23, v20, -1);
      Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        (Scaleform::GFx::AS2::MovieRoot *)v4->pASRoot,
        v4,
        v23.pNode->pData,
        v6);
      v21 = v23.pNode;
      v17 = v23.pNode->RefCount == 1;
      --v21->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    }
  }
}

// File Line: 2952
// RVA: 0x71A210
void __fastcall Scaleform::GFx::AS2::AvmSprite::SetNoLine(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::AvmSprite *v1; // rdi
  Scaleform::GFx::DrawingContext *v2; // rsi
  Scaleform::GFx::DrawingContext *v3; // rbx

  v1 = this;
  v2 = (Scaleform::GFx::DrawingContext *)((__int64 (*)(void))this->pDispObj->vfptr[83].__vecDelDtor)();
  if ( !Scaleform::GFx::DrawingContext::NoLine(v2) )
  {
    v3 = (Scaleform::GFx::DrawingContext *)((__int64 (*)(void))v1->pDispObj->vfptr[83].__vecDelDtor)();
    _((AMD_HD3D *)v1->pDispObj);
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v1->pDispObj->vfptr);
    Scaleform::GFx::DrawingContext::AcquirePath(v3, 0);
    Scaleform::GFx::DrawingContext::SetNoLine(v2);
  }
}

// File Line: 2963
// RVA: 0x71A1A0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SetNoFill(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::AS2::AvmSprite *v1; // rsi
  Scaleform::GFx::DrawingContext *v2; // rdi
  Scaleform::GFx::DrawingContext *v3; // rbx

  v1 = this;
  v2 = (Scaleform::GFx::DrawingContext *)((__int64 (*)(void))this->pDispObj->vfptr[83].__vecDelDtor)();
  v3 = (Scaleform::GFx::DrawingContext *)((__int64 (*)(void))v1->pDispObj->vfptr[83].__vecDelDtor)();
  _((AMD_HD3D *)v1->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v1->pDispObj->vfptr);
  Scaleform::GFx::DrawingContext::AcquirePath(v3, 1);
  Scaleform::GFx::DrawingContext::SetNoFill(v2);
}

// File Line: 2999
// RVA: 0x6DB540
void __fastcall Scaleform::GFx::AS2::AvmSprite::BeginFill(Scaleform::GFx::AS2::AvmSprite *this, unsigned int rgba)
{
  Scaleform::GFx::AS2::AvmSprite *v2; // rdi
  unsigned int v3; // esi
  Scaleform::GFx::DrawingContext *v4; // rbx

  v2 = this;
  v3 = rgba;
  v4 = (Scaleform::GFx::DrawingContext *)((__int64 (*)(void))this->pDispObj->vfptr[83].__vecDelDtor)();
  _((AMD_HD3D *)v2->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v2->pDispObj->vfptr);
  Scaleform::GFx::DrawingContext::AcquirePath(v4, 1);
  Scaleform::GFx::DrawingContext::BeginSolidFill(v4, v3);
}

// File Line: 3008
// RVA: 0x6DB4C0
void __fastcall Scaleform::GFx::AS2::AvmSprite::BeginBitmapFill(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::FillType fillType, Scaleform::GFx::ImageResource *pimageRes, Scaleform::Render::Matrix2x4<float> *mtx)
{
  Scaleform::GFx::AS2::AvmSprite *v4; // rbx
  Scaleform::Render::Matrix2x4<float> *v5; // rsi
  Scaleform::GFx::ImageResource *v6; // rbp
  Scaleform::GFx::FillType v7; // er14
  Scaleform::GFx::DrawingContext *v8; // rdi

  v4 = this;
  v5 = mtx;
  v6 = pimageRes;
  v7 = fillType;
  v8 = (Scaleform::GFx::DrawingContext *)((__int64 (*)(void))this->pDispObj->vfptr[83].__vecDelDtor)();
  _((AMD_HD3D *)v4->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v4->pDispObj->vfptr);
  Scaleform::GFx::DrawingContext::AcquirePath(v8, 1);
  Scaleform::GFx::DrawingContext::BeginBitmapFill(v8, v7, v6, v5);
}

// File Line: 3020
// RVA: 0x7030D0
void __fastcall Scaleform::GFx::AS2::AvmSprite::MoveTo(Scaleform::GFx::AS2::AvmSprite *this, float x, float y)
{
  Scaleform::GFx::AS2::AvmSprite *v3; // rdi
  Scaleform::GFx::DrawingContext *v4; // rbx

  v3 = this;
  v4 = (Scaleform::GFx::DrawingContext *)((__int64 (*)(void))this->pDispObj->vfptr[83].__vecDelDtor)();
  _((AMD_HD3D *)v3->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v3->pDispObj->vfptr);
  Scaleform::GFx::DrawingContext::AcquirePath(v4, 0);
  Scaleform::GFx::DrawingContext::MoveTo(v4, x * 20.0, y * 20.0);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v3->pDispObj->vfptr);
}

// File Line: 3031
// RVA: 0x7011F0
void __fastcall Scaleform::GFx::AS2::AvmSprite::LineTo(Scaleform::GFx::AS2::AvmSprite *this, float x, float y)
{
  Scaleform::GFx::AS2::AvmSprite *v3; // rbx
  Scaleform::GFx::DrawingContext *v4; // rax

  v3 = this;
  v4 = (Scaleform::GFx::DrawingContext *)((__int64 (*)(void))this->pDispObj->vfptr[83].__vecDelDtor)();
  Scaleform::GFx::DrawingContext::LineTo(v4, x * 20.0, y * 20.0);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v3->pDispObj->vfptr);
}

// File Line: 3042
// RVA: 0x6E1940
void __fastcall Scaleform::GFx::AS2::AvmSprite::CurveTo(Scaleform::GFx::AS2::AvmSprite *this, float cx, float cy, float ax, float ay)
{
  Scaleform::GFx::AS2::AvmSprite *v5; // rbx
  Scaleform::GFx::DrawingContext *v6; // rax

  v5 = this;
  v6 = (Scaleform::GFx::DrawingContext *)((__int64 (*)(void))this->pDispObj->vfptr[83].__vecDelDtor)();
  Scaleform::GFx::DrawingContext::CurveTo(v6, cx * 20.0, cy * 20.0, ax * 20.0, ay * 20.0);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v5->pDispObj->vfptr);
}

// File Line: 3061
// RVA: 0x6B0100
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteClear(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::InteractiveObject *v2; // rbx
  Scaleform::GFx::DrawingContext *v3; // rax

  v1 = fn->ThisPtr;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v2 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v2 = 0i64;
  }
  else
  {
    v2 = fn->Env->Target;
  }
  if ( v2 )
  {
    if ( ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v2->vfptr[83].__vecDelDtor)(v2) )
    {
      v3 = (Scaleform::GFx::DrawingContext *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v2->vfptr[83].__vecDelDtor)(v2);
      Scaleform::GFx::DrawingContext::Clear(v3);
    }
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr);
    _((AMD_HD3D *)v2);
  }
}

// File Line: 3074
// RVA: 0x6B0310
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteBeginFill(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::AS2::Value *v2; // rdi
  Scaleform::GFx::AS2::FnCall *v3; // rsi
  Scaleform::GFx::InteractiveObject *v4; // rbx
  Scaleform::GFx::AS2::Environment *v5; // rdx
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS2::Value *v7; // r9
  unsigned int v8; // ebp
  Scaleform::GFx::AS2::Environment *v9; // rdx
  unsigned __int64 v10; // r8
  int v11; // ebp
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm0_4

  v1 = fn->ThisPtr;
  v2 = 0i64;
  v3 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 )
  {
    if ( v3->NArgs > 0 )
    {
      v5 = v3->Env;
      v6 = (unsigned int)v3->FirstArgBottomIndex;
      v7 = 0i64;
      if ( (unsigned int)v6 <= 32 * (LODWORD(v5->Stack.Pages.Data.Size) - 1)
                             + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
        v7 = &v5->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToUInt32(v7, v5) | 0xFF000000;
      if ( v3->NArgs <= 1 )
        goto LABEL_19;
      v9 = v3->Env;
      v10 = (unsigned int)(v3->FirstArgBottomIndex - 1);
      if ( (unsigned int)v10 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
        v2 = &v9->Stack.Pages.Data.Data[v10 >> 5]->Values[(LOBYTE(v3->FirstArgBottomIndex) - 1) & 0x1F];
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
      v8 = ((signed int)v14 << 24) | v11;
LABEL_19:
      Scaleform::GFx::AS2::AvmSprite::BeginFill(
        (Scaleform::GFx::AS2::AvmSprite *)((char *)v4 + 4 * (unsigned __int8)v4->AvmObjOffset),
        v8);
      return;
    }
    Scaleform::GFx::AS2::AvmSprite::SetNoFill((Scaleform::GFx::AS2::AvmSprite *)((char *)v4
                                                                               + 4 * (unsigned __int8)v4->AvmObjOffset));
  }
}

// File Line: 3097
// RVA: 0x71FD50
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteCreateGradient(Scaleform::GFx::AS2::FnCall *fn, Scaleform::Render::ComplexFill *complexFill)
{
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  signed int v3; // er14
  unsigned int v4; // er9
  Scaleform::GFx::AS2::Environment *v5; // r8
  Scaleform::GFx::AS2::Value *v6; // r10
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // rdx
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // r13
  unsigned int v12; // er9
  Scaleform::GFx::AS2::Environment *v13; // rdx
  Scaleform::GFx::AS2::Value *v14; // r10
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Object *v16; // rbx
  unsigned int v17; // er9
  Scaleform::GFx::AS2::Environment *v18; // rdx
  Scaleform::GFx::AS2::Value *v19; // r10
  Scaleform::GFx::AS2::Object *v20; // rax
  Scaleform::GFx::AS2::Object *v21; // r12
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // rax
  Scaleform::GFx::AS2::Environment *v23; // rbx
  Scaleform::GFx::AS2::ASStringContext *v24; // rsi
  Scaleform::GFx::AS2::Value *v25; // rax
  char *v26; // rbx
  Scaleform::GFx::ASString *v27; // rax
  __int64 v28; // r15
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASString *v30; // rax
  const char *v31; // rdx
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
  __int64 v42; // r14
  Scaleform::GFx::ASStringNode *v43; // rcx
  Scaleform::GFx::ASString *v44; // rax
  __int64 v45; // r14
  Scaleform::GFx::ASStringNode *v46; // rcx
  Scaleform::GFx::ASString *v47; // rax
  __int64 v48; // r14
  Scaleform::GFx::ASStringNode *v49; // rcx
  Scaleform::GFx::ASString *v50; // rax
  __int64 v51; // r14
  Scaleform::GFx::ASStringNode *v52; // rcx
  Scaleform::GFx::ASString *v53; // rax
  __int64 v54; // rbx
  Scaleform::GFx::ASStringNode *v55; // rcx
  float v56; // xmm9_4
  float v57; // xmm10_4
  float v58; // xmm6_4
  float v59; // xmm8_4
  float v60; // xmm1_4
  Scaleform::GFx::ASString *v61; // rax
  __int64 v62; // r14
  Scaleform::GFx::ASStringNode *v63; // rcx
  float v64; // xmm1_4
  Scaleform::GFx::ASString *v65; // rax
  __int64 v66; // r14
  Scaleform::GFx::ASStringNode *v67; // rcx
  float v68; // xmm1_4
  Scaleform::GFx::ASString *v69; // rax
  __int64 v70; // r14
  Scaleform::GFx::ASStringNode *v71; // rcx
  float v72; // xmm1_4
  Scaleform::GFx::ASString *v73; // rax
  __int64 v74; // r14
  Scaleform::GFx::ASStringNode *v75; // rcx
  float v76; // xmm1_4
  Scaleform::GFx::ASString *v77; // rax
  __int64 v78; // r14
  Scaleform::GFx::ASStringNode *v79; // rcx
  float v80; // xmm1_4
  Scaleform::GFx::ASString *v81; // rax
  __int64 v82; // rbx
  Scaleform::GFx::ASStringNode *v83; // rcx
  bool v84; // bl
  Scaleform::GFx::AS2::Value *v85; // rax
  Scaleform::GFx::AS2::Value *v86; // rax
  const char ***v87; // rax
  Scaleform::GFx::ASStringNode *v88; // rcx
  Scaleform::GFx::ASStringNode *v89; // rcx
  __int64 v90; // rax
  char v91; // cl
  bool v92; // zf
  Scaleform::Render::GradientType v93; // er15
  Scaleform::GFx::ASStringNode *v94; // rax
  __int64 v95; // rax
  __int64 v96; // rbx
  __int64 v97; // rsi
  Scaleform::Render::RenderBuffer *v98; // rcx
  signed int v99; // er14
  __int64 v100; // rsi
  __int64 v101; // r15
  unsigned int v102; // ebx
  float v103; // xmm1_4
  float v104; // xmm1_4
  int v105; // ebx
  int v106; // ebx
  float v107; // xmm1_4
  __int64 v108; // rdx
  __int64 v109; // rcx
  Scaleform::GFx::ASStringNode *v110; // rcx
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-A0h]
  Scaleform::GFx::AS2::Value v112; // [rsp+40h] [rbp-80h]
  unsigned int v113; // [rsp+60h] [rbp-60h]
  Scaleform::GFx::AS2::Object *v114; // [rsp+68h] [rbp-58h]
  __int64 v115; // [rsp+70h] [rbp-50h]
  Scaleform::GFx::ASString v116; // [rsp+110h] [rbp+50h]
  __int64 v117; // [rsp+118h] [rbp+58h]
  Scaleform::GFx::ASString result; // [rsp+120h] [rbp+60h]
  Scaleform::GFx::ASString v119; // [rsp+128h] [rbp+68h]

  v115 = -2i64;
  v2 = fn;
  v3 = 0;
  v113 = 0;
  if ( fn->NArgs > 0 )
  {
    v4 = fn->FirstArgBottomIndex;
    v5 = fn->Env;
    v6 = 0i64;
    if ( v4 <= 32 * ((unsigned int)v5->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
      v6 = &v5->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v6, &result, v5, -1);
    if ( v2->NArgs <= 1 )
      goto LABEL_117;
    v7 = v2->FirstArgBottomIndex - 1;
    v8 = v2->Env;
    v9 = 0i64;
    if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
      v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToObject(v9, v8);
    v11 = v10;
    if ( !v10 || (*(unsigned int (**)(void))&v10->vfptr->gap8[8])() != 7 || v2->NArgs <= 2 )
      goto LABEL_117;
    v12 = v2->FirstArgBottomIndex - 2;
    v13 = v2->Env;
    v14 = 0i64;
    if ( v12 <= 32 * ((unsigned int)v13->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v13->Stack.pCurrent - (char *)v13->Stack.pPageStart) >> 5) )
      v14 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
    v15 = Scaleform::GFx::AS2::Value::ToObject(v14, v13);
    v16 = v15;
    v114 = v15;
    if ( !v15 || (*(unsigned int (**)(void))&v15->vfptr->gap8[8])() != 7 || v2->NArgs <= 3 )
      goto LABEL_117;
    v17 = v2->FirstArgBottomIndex - 3;
    v18 = v2->Env;
    v19 = 0i64;
    if ( v17 <= 32 * ((unsigned int)v18->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v18->Stack.pCurrent - (char *)v18->Stack.pPageStart) >> 5) )
      v19 = &v18->Stack.Pages.Data.Data[v17 >> 5]->Values[v17 & 0x1F];
    v20 = Scaleform::GFx::AS2::Value::ToObject(v19, v18);
    v21 = v20;
    if ( !v20
      || (*(unsigned int (**)(void))&v20->vfptr->gap8[8])() != 7
      || v2->NArgs <= 4
      || (v22 = v11[1].pPrev, (signed int)v22 <= 0)
      || (_DWORD)v22 != v16[1].RootIndex
      || (_DWORD)v22 != v21[1].RootIndex )
    {
LABEL_117:
      v110 = result.pNode;
      v92 = result.pNode->RefCount == 1;
      --v110->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v110);
      return;
    }
    *(_OWORD *)&m.M[0][0] = _xmm;
    *(__m128 *)&m.M[1][0] = _xmm;
    v112.T.Type = 0;
    v23 = v2->Env;
    v24 = &v23->StringContext;
    v25 = Scaleform::GFx::AS2::FnCall::Arg(v2, 4);
    v26 = (char *)&Scaleform::GFx::AS2::Value::ToObject(v25, v23)->vfptr;
    v27 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "matrixType");
    v28 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
            v26,
            v24,
            v27,
            &v112);
    v29 = v116.pNode;
    v92 = v116.pNode->RefCount == 1;
    --v29->RefCount;
    if ( v92 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
    if ( (_BYTE)v28 )
    {
      v30 = Scaleform::GFx::AS2::Value::ToString(&v112, &v119, v2->Env, -1);
      v3 = 1;
      v113 = 1;
      v31 = v30->pNode->pData;
      v32 = 0i64;
      while ( 1 )
      {
        v33 = v31[v32++];
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
    if ( v3 & 1 )
    {
      v113 = v3 & 0xFFFFFFFE;
      v35 = v119.pNode;
      v92 = v119.pNode->RefCount == 1;
      --v35->RefCount;
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
      v41 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "x");
      v42 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
              v26,
              v24,
              v41,
              &v112);
      v43 = v116.pNode;
      v92 = v116.pNode->RefCount == 1;
      --v43->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v43);
      if ( (_BYTE)v42 )
        v36 = Scaleform::GFx::AS2::Value::ToNumber(&v112, v2->Env);
      v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "y");
      v45 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
              v26,
              v24,
              v44,
              &v112);
      v46 = v116.pNode;
      v92 = v116.pNode->RefCount == 1;
      --v46->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v46);
      if ( (_BYTE)v45 )
        v37 = Scaleform::GFx::AS2::Value::ToNumber(&v112, v2->Env);
      v47 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "w");
      v48 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
              v26,
              v24,
              v47,
              &v112);
      v49 = v116.pNode;
      v92 = v116.pNode->RefCount == 1;
      --v49->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v49);
      if ( (_BYTE)v48 )
        v38 = Scaleform::GFx::AS2::Value::ToNumber(&v112, v2->Env);
      v50 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "h");
      v51 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
              v26,
              v24,
              v50,
              &v112);
      v52 = v116.pNode;
      v92 = v116.pNode->RefCount == 1;
      --v52->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v52);
      if ( (_BYTE)v51 )
        v39 = Scaleform::GFx::AS2::Value::ToNumber(&v112, v2->Env);
      v53 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "r");
      v54 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
              v26,
              v24,
              v53,
              &v112);
      v55 = v116.pNode;
      v92 = v116.pNode->RefCount == 1;
      --v55->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v55);
      if ( (_BYTE)v54 )
        v40 = Scaleform::GFx::AS2::Value::ToNumber(&v112, v2->Env);
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
      v61 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "a");
      v62 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
              v26,
              v24,
              v61,
              &v112);
      v63 = v116.pNode;
      v92 = v116.pNode->RefCount == 1;
      --v63->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v63);
      if ( (_BYTE)v62 )
      {
        v64 = Scaleform::GFx::AS2::Value::ToNumber(&v112, v2->Env);
        m.M[0][0] = v64 * 0.00061035156;
      }
      v65 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "d");
      v66 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
              v26,
              v24,
              v65,
              &v112);
      v67 = v116.pNode;
      v92 = v116.pNode->RefCount == 1;
      --v67->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v67);
      if ( (_BYTE)v66 )
      {
        v68 = Scaleform::GFx::AS2::Value::ToNumber(&v112, v2->Env);
        m.M[0][1] = v68 * 0.00061035156;
      }
      v69 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "g");
      v70 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
              v26,
              v24,
              v69,
              &v112);
      v71 = v116.pNode;
      v92 = v116.pNode->RefCount == 1;
      --v71->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v71);
      if ( (_BYTE)v70 )
      {
        v72 = Scaleform::GFx::AS2::Value::ToNumber(&v112, v2->Env);
        m.M[0][3] = v72;
      }
      v73 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "b");
      v74 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
              v26,
              v24,
              v73,
              &v112);
      v75 = v116.pNode;
      v92 = v116.pNode->RefCount == 1;
      --v75->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v75);
      if ( (_BYTE)v74 )
      {
        v76 = Scaleform::GFx::AS2::Value::ToNumber(&v112, v2->Env);
        m.M[1][0] = v76 * 0.00061035156;
      }
      v77 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "e");
      v78 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
              v26,
              v24,
              v77,
              &v112);
      v79 = v116.pNode;
      v92 = v116.pNode->RefCount == 1;
      --v79->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v79);
      if ( (_BYTE)v78 )
      {
        v80 = Scaleform::GFx::AS2::Value::ToNumber(&v112, v2->Env);
        m.M[1][1] = v80 * 0.00061035156;
      }
      v81 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v24, &v116, "h");
      v82 = (*(unsigned __int8 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v26 + 88i64))(
              v26,
              v24,
              v81,
              &v112);
      v83 = v116.pNode;
      v92 = v116.pNode->RefCount == 1;
      --v83->RefCount;
      if ( v92 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v83);
      if ( !(_BYTE)v82 )
      {
LABEL_81:
        v84 = 0;
        if ( v2->NArgs > 5 )
        {
          v85 = Scaleform::GFx::AS2::FnCall::Arg(v2, 5);
          Scaleform::GFx::AS2::Value::ToString(v85, &v119, v2->Env, -1);
          if ( v2->NArgs > 6 )
          {
            v86 = Scaleform::GFx::AS2::FnCall::Arg(v2, 6);
            v87 = (const char ***)Scaleform::GFx::AS2::Value::ToString(v86, &v116, v2->Env, -1);
            v84 = strcmp(**v87, "linearRGB") == 0;
            v88 = v116.pNode;
            v92 = v116.pNode->RefCount == 1;
            --v88->RefCount;
            if ( v92 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v88);
          }
          v89 = v119.pNode;
          v92 = v119.pNode->RefCount == 1;
          --v89->RefCount;
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
        v93 = 0;
        if ( v92 )
          v93 = 1;
        LODWORD(v116.pNode) = v93;
        v94 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                Scaleform::Memory::pGlobalHeap,
                                                48i64);
        v119.pNode = v94;
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
        v97 = v117;
        v98 = *(Scaleform::Render::RenderBuffer **)(v117 + 24);
        if ( v98 )
          Scaleform::RefCountImpl::Release(v98);
        *(_QWORD *)(v97 + 24) = v96;
        if ( v96 )
        {
          *(_DWORD *)(v96 + 32) = 0;
          v99 = 0;
          if ( (signed int)v11[1].RootIndex > 0 )
          {
            v100 = 0i64;
            v101 = v117;
            do
            {
              v102 = Scaleform::GFx::AS2::Value::ToUInt32(
                       (Scaleform::GFx::AS2::Value *)(&v11[1].pRCC->vfptr)[v100],
                       v2->Env) | 0xFF000000;
              v103 = Scaleform::GFx::AS2::Value::ToNumber(
                       (Scaleform::GFx::AS2::Value *)(&v114[1].pRCC->vfptr)[v100],
                       v2->Env);
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
              v106 = ((signed int)v104 << 24) | v105;
              v107 = Scaleform::GFx::AS2::Value::ToNumber(
                       (Scaleform::GFx::AS2::Value *)(&v21[1].pRCC->vfptr)[v100],
                       v2->Env);
              if ( v107 >= 255.0 )
              {
                v107 = FLOAT_255_0;
              }
              else if ( v107 < 0.0 )
              {
                v107 = 0.0;
              }
              v108 = (unsigned int)v99;
              v109 = *(_QWORD *)(*(_QWORD *)(v101 + 24) + 24i64);
              *(_BYTE *)(v109 + 8 * v108) = (signed int)v107;
              *(_DWORD *)(v109 + 8 * v108 + 4) = v106;
              ++v99;
              ++v100;
            }
            while ( v99 < (signed int)v11[1].RootIndex );
            v93 = (Scaleform::Render::GradientType)v116.pNode;
            v97 = v117;
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
          *(_OWORD *)&v112.T.Type = _xmm;
          *((__m128 *)&v112.NV + 1) = _xmm;
          Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)&v112, &m);
          Scaleform::Render::Matrix2x4<float>::Prepend(
            (Scaleform::Render::Matrix2x4<float> *)(v97 + 32),
            (Scaleform::Render::Matrix2x4<float> *)&v112);
        }
        if ( v112.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v112);
        goto LABEL_117;
      }
      v60 = Scaleform::GFx::AS2::Value::ToNumber(&v112, v2->Env);
    }
    m.M[1][3] = v60;
    goto LABEL_81;
  }
};
          Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)&v112, &m)

// File Line: 3261
// RVA: 0x6B06C0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteBeginGradientFill(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rsi
  Scaleform::GFx::InteractiveObject *v3; // rdx
  signed __int64 v4; // rbx
  Scaleform::GFx::DrawingContext *v5; // rdi
  Scaleform::Render::ComplexFill *v6; // rbx

  v1 = fn->ThisPtr;
  v2 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v3 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v3 = 0i64;
  }
  else
  {
    v3 = fn->Env->Target;
  }
  if ( v3 )
  {
    v4 = (signed __int64)v3 + 4 * (unsigned __int8)v3->AvmObjOffset;
    v5 = (Scaleform::GFx::DrawingContext *)(*(__int64 (**)(void))(**(_QWORD **)(v4 + 24) + 664i64))();
    _(*(AMD_HD3D **)(v4 + 24));
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(*(Scaleform::GFx::DisplayObjectBase **)(v4 + 24));
    Scaleform::GFx::DrawingContext::AcquirePath(v5, 1);
    v6 = Scaleform::GFx::DrawingContext::CreateNewComplexFill(v5);
    Scaleform::GFx::DrawingContext::BeginFill(v5);
    if ( v6 )
      Scaleform::GFx::AS2::AvmSprite::SpriteCreateGradient(v2, v6);
  }
}

// File Line: 3271
// RVA: 0x6B0D10
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLineGradientStyle(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rsi
  Scaleform::GFx::InteractiveObject *v3; // rdx
  signed __int64 v4; // rdi
  Scaleform::GFx::DrawingContext *v5; // rbx
  Scaleform::Render::ComplexFill *v6; // rax

  v1 = fn->ThisPtr;
  v2 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v3 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v3 = 0i64;
  }
  else
  {
    v3 = fn->Env->Target;
  }
  if ( v3 )
  {
    v4 = (signed __int64)v3 + 4 * (unsigned __int8)v3->AvmObjOffset;
    v5 = (Scaleform::GFx::DrawingContext *)(*(__int64 (**)(void))(**(_QWORD **)(v4 + 24) + 664i64))();
    _(*(AMD_HD3D **)(v4 + 24));
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(*(Scaleform::GFx::DisplayObjectBase **)(v4 + 24));
    Scaleform::GFx::DrawingContext::AcquirePath(v5, 1);
    v6 = Scaleform::GFx::DrawingContext::CreateLineComplexFill(v5);
    if ( v6 )
      Scaleform::GFx::AS2::AvmSprite::SpriteCreateGradient(v2, v6);
  }
}

// File Line: 3281
// RVA: 0x6B09B0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteBeginBitmapFill(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rbx
  Scaleform::GFx::AS2::Value *v3; // rbp
  Scaleform::GFx::InteractiveObject *v4; // rsi
  unsigned int v5; // er9
  Scaleform::GFx::AS2::Environment *v6; // rdx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  Scaleform::GFx::ImageResource *v9; // r14
  Scaleform::GFx::AS2::Value *v10; // rax
  bool v11; // bp
  Scaleform::GFx::AS2::Value *v12; // rax
  int v13; // edx
  unsigned int v14; // eax
  Scaleform::Render::Matrix2x4<float> mtx; // [rsp+30h] [rbp-38h]

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = 0i64;
  if ( v2 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v2[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 && v1->NArgs > 0 )
  {
    v5 = v1->FirstArgBottomIndex;
    v6 = v1->Env;
    if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
      v3 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
    v7 = Scaleform::GFx::AS2::Value::ToObject(v3, v6);
    v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v7->vfptr;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    if ( !v7
      || (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v7->vfptr->gap8[8])(&v7->vfptr) != 26
      || (v9 = (Scaleform::GFx::ImageResource *)v8[3].vfptr) == 0i64 )
    {
      if ( !v8 )
        return;
      goto LABEL_23;
    }
    *(_OWORD *)&mtx.M[0][0] = _xmm;
    *(__m128 *)&mtx.M[1][0] = _xmm;
    if ( v1->NArgs >= 3 )
    {
      v10 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
      v11 = Scaleform::GFx::AS2::Value::ToBool(v10, v1->Env);
      if ( v1->NArgs > 3 )
      {
        v12 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
        if ( Scaleform::GFx::AS2::Value::ToBool(v12, v1->Env) )
        {
          v13 = 65 - (v11 != 0);
LABEL_21:
          Scaleform::GFx::AS2::AvmSprite::BeginBitmapFill(
            (Scaleform::GFx::AS2::AvmSprite *)((char *)v4 + 4 * (unsigned __int8)v4->AvmObjOffset),
            (Scaleform::GFx::FillType)v13,
            v9,
            &mtx);
LABEL_23:
          v14 = v8->RefCount;
          if ( v14 & 0x3FFFFFF )
          {
            v8->RefCount = v14 - 1;
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
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::InteractiveObject *v2; // rcx
  signed __int64 v3; // rdi
  Scaleform::GFx::DrawingContext *v4; // rbx

  v1 = fn->ThisPtr;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v2 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v2 = 0i64;
  }
  else
  {
    v2 = fn->Env->Target;
  }
  if ( v2 )
  {
    v3 = (signed __int64)v2 + 4 * (unsigned __int8)v2->AvmObjOffset;
    v4 = (Scaleform::GFx::DrawingContext *)(*(__int64 (**)(void))(**(_QWORD **)(v3 + 24) + 664i64))();
    _(*(AMD_HD3D **)(v3 + 24));
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(*(Scaleform::GFx::DisplayObjectBase **)(v3 + 24));
    Scaleform::GFx::DrawingContext::AcquirePath(v4, 1);
    Scaleform::GFx::DrawingContext::EndFill(v4);
  }
}

// File Line: 3356
// RVA: 0x6B11F0
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLineStyle(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rdi
  unsigned int joins; // esi
  Scaleform::GFx::InteractiveObject *v4; // r14
  unsigned int v5; // er10
  Scaleform::GFx::AS2::Environment *v6; // rdx
  Scaleform::GFx::AS2::Value *v7; // r9
  float v8; // xmm8_4
  signed int v9; // ebp
  bool v10; // r13
  unsigned int scaling; // er15
  unsigned int caps; // er12
  float miterLimit; // xmm6_4
  unsigned int v14; // er9
  Scaleform::GFx::AS2::Environment *v15; // rdx
  Scaleform::GFx::AS2::Value *v16; // r10
  unsigned int v17; // er9
  Scaleform::GFx::AS2::Environment *v18; // rdx
  Scaleform::GFx::AS2::Value *v19; // r10
  float v20; // xmm1_4
  float v21; // xmm1_4
  int v22; // ebp
  float v23; // xmm0_4
  Scaleform::GFx::AS2::Value *v24; // rax
  Scaleform::GFx::AS2::Value *v25; // rax
  const char *v26; // rdi
  __int64 v27; // rcx
  char v28; // al
  Scaleform::GFx::AS2::Value *v29; // rax
  Scaleform::GFx::ASStringNode *v30; // rdi
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::ASStringNode *v32; // rcx
  const char *v33; // rdx
  __int64 v34; // rcx
  char v35; // al
  __int64 v36; // rax
  char v37; // cl
  bool v38; // zf
  Scaleform::GFx::AS2::Value *v39; // rax
  Scaleform::GFx::ASStringNode *v40; // rdi
  Scaleform::GFx::ASStringNode *v41; // rcx
  Scaleform::GFx::ASStringNode *v42; // rcx
  const char *v43; // rdx
  __int64 v44; // rcx
  char v45; // al
  __int64 v46; // rax
  char v47; // cl
  bool v48; // zf
  Scaleform::GFx::AS2::Value *v49; // rax
  Scaleform::GFx::ASStringNode *v50; // rcx
  Scaleform::GFx::DrawingContext *v51; // rax
  Scaleform::GFx::ASString result; // [rsp+C0h] [rbp+8h]
  Scaleform::GFx::ASString v53; // [rsp+C8h] [rbp+10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  joins = 0;
  if ( v2 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v2[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 )
  {
    if ( v1->NArgs > 0 )
    {
      v5 = v1->FirstArgBottomIndex;
      v6 = v1->Env;
      v7 = 0i64;
      if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
        v7 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToNumber(v7, v6);
      v9 = -16777216;
      v10 = 0;
      scaling = 0;
      caps = 0;
      miterLimit = FLOAT_3_0;
      if ( v1->NArgs <= 1 )
        goto LABEL_68;
      v14 = v1->FirstArgBottomIndex - 1;
      v15 = v1->Env;
      v16 = 0i64;
      if ( v14 <= 32 * ((unsigned int)v15->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v15->Stack.pCurrent - (char *)v15->Stack.pPageStart) >> 5) )
        v16 = &v15->Stack.Pages.Data.Data[v14 >> 5]->Values[v14 & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToUInt32(v16, v15) | 0xFF000000;
      if ( v1->NArgs <= 2 )
      {
LABEL_68:
        v51 = (Scaleform::GFx::DrawingContext *)(*(__int64 (**)(void))(**(_QWORD **)((char *)&v4->vfptr
                                                                                   + 4
                                                                                   * (unsigned __int8)v4->AvmObjOffset)
                                                                     + 664i64))();
        Scaleform::GFx::DrawingContext::ChangeLineStyle(v51, v8 * 20.0, v9, v10, scaling, caps, joins, miterLimit);
        return;
      }
      v17 = v1->FirstArgBottomIndex - 2;
      v18 = v1->Env;
      v19 = 0i64;
      if ( v17 <= 32 * ((unsigned int)v18->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v18->Stack.pCurrent - (char *)v18->Stack.pPageStart) >> 5) )
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
      v9 = ((signed int)v23 << 24) | v22;
      if ( v1->NArgs > 3 )
      {
        v24 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
        v10 = Scaleform::GFx::AS2::Value::ToBool(v24, v1->Env);
        if ( v1->NArgs > 4 )
        {
          v25 = Scaleform::GFx::AS2::FnCall::Arg(v1, 4);
          Scaleform::GFx::AS2::Value::ToString(v25, &result, v1->Env, -1);
          v26 = result.pNode->pData;
          v27 = 0i64;
          while ( 1 )
          {
            v28 = v26[v27++];
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
          else if ( !strcmp(v26, "horizontal") )
          {
            scaling = 2;
          }
LABEL_31:
          if ( v1->NArgs > 5 )
          {
            v29 = Scaleform::GFx::AS2::FnCall::Arg(v1, 5);
            v30 = Scaleform::GFx::AS2::Value::ToString(v29, &v53, v1->Env, -1)->pNode;
            ++v30->RefCount;
            v31 = result.pNode;
            v38 = result.pNode->RefCount == 1;
            --v31->RefCount;
            if ( v38 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v31);
            result.pNode = v30;
            v32 = v53.pNode;
            v38 = v53.pNode->RefCount == 1;
            --v32->RefCount;
            if ( v38 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v32);
            v33 = result.pNode->pData;
            v34 = 0i64;
            while ( 1 )
            {
              v35 = v33[v34++];
              if ( v35 != aNone[v34 - 1] )
                break;
              if ( v34 == 5 )
              {
                caps = 320;
                goto LABEL_46;
              }
            }
            v36 = 0i64;
            while ( 1 )
            {
              v37 = v33[v36++];
              v38 = v37 == aSquare[v36 - 1];
              if ( v37 != aSquare[v36 - 1] )
                break;
              if ( v36 == 7 )
              {
                v38 = v37 == aSquare[6];
                break;
              }
            }
            if ( v38 )
              caps = 640;
LABEL_46:
            if ( v1->NArgs > 6 )
            {
              v39 = Scaleform::GFx::AS2::FnCall::Arg(v1, 6);
              v40 = Scaleform::GFx::AS2::Value::ToString(v39, &v53, v1->Env, -1)->pNode;
              ++v40->RefCount;
              v41 = result.pNode;
              v38 = result.pNode->RefCount == 1;
              --v41->RefCount;
              if ( v38 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v41);
              result.pNode = v40;
              v42 = v53.pNode;
              v38 = v53.pNode->RefCount == 1;
              --v42->RefCount;
              if ( v38 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v42);
              v43 = result.pNode->pData;
              v44 = 0i64;
              while ( 1 )
              {
                v45 = v43[v44++];
                if ( v45 != aMiter[v44 - 1] )
                  break;
                if ( v44 == 6 )
                {
                  joins = 32;
                  goto LABEL_61;
                }
              }
              v46 = 0i64;
              while ( 1 )
              {
                v47 = v43[v46++];
                v48 = v47 == aBevel[v46 - 1];
                if ( v47 != aBevel[v46 - 1] )
                  break;
                if ( v46 == 6 )
                {
                  v48 = v47 == aBevel[5];
                  break;
                }
              }
              if ( v48 )
                joins = 16;
LABEL_61:
              if ( v1->NArgs > 7 )
              {
                v49 = Scaleform::GFx::AS2::FnCall::Arg(v1, 7);
                miterLimit = Scaleform::GFx::AS2::Value::ToNumber(v49, v1->Env);
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
          v50 = result.pNode;
          v38 = result.pNode->RefCount == 1;
          --v50->RefCount;
          if ( v38 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v50);
        }
      }
      goto LABEL_68;
    }
    Scaleform::GFx::AS2::AvmSprite::SetNoLine((Scaleform::GFx::AS2::AvmSprite *)((char *)v4
                                                                               + 4 * (unsigned __int8)v4->AvmObjOffset));
  }
}

// File Line: 3425
// RVA: 0x6B1890
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteMoveTo(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::FnCall *v3; // rdi
  Scaleform::GFx::InteractiveObject *v4; // rsi
  Scaleform::GFx::AS2::Environment *v5; // rdx
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS2::Value *v7; // r9
  long double v8; // xmm0_8
  Scaleform::GFx::AS2::Environment *v9; // rdx
  float v10; // xmm6_4
  unsigned __int64 v11; // r8
  float v12; // xmm2_4

  v1 = fn->ThisPtr;
  v2 = 0i64;
  v3 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 && v3->NArgs >= 2 )
  {
    v5 = v3->Env;
    v6 = (unsigned int)v3->FirstArgBottomIndex;
    v7 = 0i64;
    if ( (unsigned int)v6 <= 32 * (LODWORD(v5->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
      v7 = &v5->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v8 = Scaleform::GFx::AS2::Value::ToNumber(v7, v5);
    v9 = v3->Env;
    v10 = v8;
    v11 = (unsigned int)(v3->FirstArgBottomIndex - 1);
    if ( (unsigned int)v11 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
      v2 = &v9->Stack.Pages.Data.Data[v11 >> 5]->Values[(LOBYTE(v3->FirstArgBottomIndex) - 1) & 0x1F];
    v12 = Scaleform::GFx::AS2::Value::ToNumber(v2, v9);
    Scaleform::GFx::AS2::AvmSprite::MoveTo(
      (Scaleform::GFx::AS2::AvmSprite *)((char *)v4 + 4 * (unsigned __int8)v4->AvmObjOffset),
      v10,
      v12);
  }
}

// File Line: 3438
// RVA: 0x6B1B70
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteLineTo(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::FnCall *v3; // rdi
  Scaleform::GFx::InteractiveObject *v4; // rsi
  Scaleform::GFx::AS2::Environment *v5; // rdx
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS2::Value *v7; // r9
  long double v8; // xmm0_8
  Scaleform::GFx::AS2::Environment *v9; // rdx
  float v10; // xmm6_4
  unsigned __int64 v11; // r8
  float v12; // xmm2_4

  v1 = fn->ThisPtr;
  v2 = 0i64;
  v3 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 && v3->NArgs >= 2 )
  {
    v5 = v3->Env;
    v6 = (unsigned int)v3->FirstArgBottomIndex;
    v7 = 0i64;
    if ( (unsigned int)v6 <= 32 * (LODWORD(v5->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
      v7 = &v5->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v8 = Scaleform::GFx::AS2::Value::ToNumber(v7, v5);
    v9 = v3->Env;
    v10 = v8;
    v11 = (unsigned int)(v3->FirstArgBottomIndex - 1);
    if ( (unsigned int)v11 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
      v2 = &v9->Stack.Pages.Data.Data[v11 >> 5]->Values[(LOBYTE(v3->FirstArgBottomIndex) - 1) & 0x1F];
    v12 = Scaleform::GFx::AS2::Value::ToNumber(v2, v9);
    Scaleform::GFx::AS2::AvmSprite::LineTo(
      (Scaleform::GFx::AS2::AvmSprite *)((char *)v4 + 4 * (unsigned __int8)v4->AvmObjOffset),
      v10,
      v12);
  }
}

// File Line: 3451
// RVA: 0x6B1D30
void __fastcall Scaleform::GFx::AS2::AvmSprite::SpriteCurveTo(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::FnCall *v3; // rdi
  Scaleform::GFx::InteractiveObject *v4; // rsi
  Scaleform::GFx::AS2::Environment *v5; // rdx
  unsigned __int64 v6; // r8
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

  v1 = fn->ThisPtr;
  v2 = 0i64;
  v3 = fn;
  if ( v1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) == 2 )
      v4 = (Scaleform::GFx::InteractiveObject *)v1[1].vfptr;
    else
      v4 = 0i64;
  }
  else
  {
    v4 = fn->Env->Target;
  }
  if ( v4 && v3->NArgs >= 4 )
  {
    v5 = v3->Env;
    v6 = (unsigned int)v3->FirstArgBottomIndex;
    v7 = 0i64;
    if ( (unsigned int)v6 <= 32 * (LODWORD(v5->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
      v7 = &v5->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v8 = Scaleform::GFx::AS2::Value::ToNumber(v7, v5);
    v9 = v3->Env;
    v10 = v8;
    v11 = (unsigned int)(v3->FirstArgBottomIndex - 1);
    v12 = 0i64;
    if ( (unsigned int)v11 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
      v12 = &v9->Stack.Pages.Data.Data[v11 >> 5]->Values[(LOBYTE(v3->FirstArgBottomIndex) - 1) & 0x1F];
    v13 = Scaleform::GFx::AS2::Value::ToNumber(v12, v9);
    v14 = v3->Env;
    v15 = v13;
    v16 = (unsigned int)(v3->FirstArgBottomIndex - 2);
    v17 = 0i64;
    if ( (unsigned int)v16 <= 32 * (LODWORD(v14->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)((_QWORD)((char *)v14->Stack.pCurrent - (char *)v14->Stack.pPageStart) >> 5) )
      v17 = &v14->Stack.Pages.Data.Data[v16 >> 5]->Values[(LOBYTE(v3->FirstArgBottomIndex) - 2) & 0x1F];
    v18 = Scaleform::GFx::AS2::Value::ToNumber(v17, v14);
    v19 = v3->Env;
    v20 = v18;
    v21 = (unsigned int)(v3->FirstArgBottomIndex - 3);
    if ( (unsigned int)v21 <= 32 * (LODWORD(v19->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)((_QWORD)((char *)v19->Stack.pCurrent - (char *)v19->Stack.pPageStart) >> 5) )
      v2 = &v19->Stack.Pages.Data.Data[v21 >> 5]->Values[(LOBYTE(v3->FirstArgBottomIndex) - 3) & 0x1F];
    ay = Scaleform::GFx::AS2::Value::ToNumber(v2, v19);
    Scaleform::GFx::AS2::AvmSprite::CurveTo(
      (Scaleform::GFx::AS2::AvmSprite *)((char *)v4 + 4 * (unsigned __int8)v4->AvmObjOffset),
      v10,
      v15,
      v20,
      ay);
  }
}

// File Line: 3466
// RVA: 0x6D7D40
void __fastcall Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::AS2::ActionBuffer *a, Scaleform::GFx::ActionPriority::Priority prio)
{
  Scaleform::GFx::AS2::AvmSprite *v3; // rdi
  Scaleform::GFx::AS2::ActionBuffer *v4; // rsi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v5; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v6; // rbx
  Scaleform::GFx::InteractiveObject *v7; // rdi
  Scaleform::RefCountNTSImpl *v8; // rcx
  Scaleform::RefCountNTSImpl *v9; // rcx

  v3 = this;
  v4 = a;
  v5 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
         (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].RefCount,
         prio);
  v6 = v5;
  if ( v5 )
  {
    v7 = v3->pDispObj;
    v5->Type = 1;
    if ( v7 )
      ++v7->RefCount;
    v8 = (Scaleform::RefCountNTSImpl *)&v5->pCharacter.pObject->vfptr;
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
    v6->pCharacter.pObject = v7;
    if ( v4 )
      ++v4->RefCount;
    v9 = (Scaleform::RefCountNTSImpl *)&v6->pActionBuffer.pObject->vfptr;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    v6->pActionBuffer.pObject = v4;
    v6->mEventId.Id = 0;
  }
}

// File Line: 3472
// RVA: 0x6E90D0
void __fastcall Scaleform::GFx::AS2::AvmSprite::FillTabableArray(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::InteractiveObject::FillTabableParams *params)
{
  Scaleform::GFx::InteractiveObject::FillTabableParams *v2; // rsi
  Scaleform::GFx::AS2::AvmSprite *v3; // r15
  __int64 v4; // rbp
  unsigned __int64 v5; // rbx
  Scaleform::GFx::ASString *v6; // rax
  char v7; // bl
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  __int64 v10; // r14
  __int64 v11; // rbx
  Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy> *v12; // rdi
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v13; // rdx
  Scaleform::GFx::AS2::Value v14; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::ASStringNode *v15; // [rsp+80h] [rbp+8h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v16; // [rsp+90h] [rbp+18h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v17; // [rsp+98h] [rbp+20h]

  v2 = params;
  v3 = this;
  v4 = *(_QWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 224);
  if ( v4 )
  {
    if ( !LOBYTE(this->Level) && !params->TabChildrenInProto.Value )
    {
      v5 = this[-1].InitActionsExecuted.Data.Size;
      if ( v5 )
      {
        v14.T.Type = 0;
        v6 = Scaleform::GFx::AS2::Environment::CreateConstString(
               (Scaleform::GFx::AS2::Environment *)&this->vfptr,
               (Scaleform::GFx::ASString *)&v15,
               "tabChildren");
        v7 = (*(__int64 (__fastcall **)(unsigned __int64, signed __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))(*(_QWORD *)(v5 + 32) + 88i64))(
               v5 + 32,
               (signed __int64)&v3->ASEnvironment.GlobalRegister[3].NV + 24,
               v6,
               &v14,
               -2i64);
        v8 = v15;
        v9 = v15->RefCount == 1;
        --v8->RefCount;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        if ( v7 && v14.T.Type && v14.T.Type != 10 )
          v2->TabChildrenInProto.Value = (Scaleform::GFx::AS2::Value::ToBool(
                                            &v14,
                                            (Scaleform::GFx::AS2::Environment *)&v3->vfptr) == 0)
                                       + 1;
        if ( v14.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v14);
      }
    }
    if ( LOBYTE(v3->Level) != 2 && v2->TabChildrenInProto.Value != 2 && v4 )
    {
      v10 = 0i64;
      do
      {
        v11 = *(_QWORD *)(v10 + *(_QWORD *)(v3[-1].InitActionsExecuted.Data.Policy.Capacity + 216));
        if ( v11
          && *(_BYTE *)(v11 + 106) < 0
          && (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v11 + 472i64))(v11) )
        {
          if ( *(_WORD *)(v11 + 188) > 0 && !v2->TabIndexed )
          {
            Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Resize(
              &v2->Array->Data,
              0i64);
            v2->TabIndexed = 1;
          }
          if ( ((*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v11 + 696i64))(v11)
             || v2->InclFocusEnabled
             && (*(unsigned __int8 (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v11 + 712i64))(v11, 2i64))
            && (!v2->TabIndexed || *(_WORD *)(v11 + 188) > 0) )
          {
            ++*(_DWORD *)(v11 + 8);
            v15 = (Scaleform::GFx::ASStringNode *)v11;
            v12 = &v2->Array->Data;
            Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy> *)&v2->Array->Data.Data,
              v2->Array->Data.pHeap,
              v2->Array->Data.Size + 1);
            v13 = &v12->Data[v12->Size - 1];
            v16 = v13;
            v17 = v13;
            if ( v13 )
            {
              ++*(_DWORD *)(v11 + 8);
              v13->pObject = (Scaleform::GFx::InteractiveObject *)v11;
            }
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v11);
          }
          if ( (*(_WORD *)(v11 + 106) >> 9) & 1 )
            Scaleform::GFx::DisplayObjContainer::FillTabableArray((Scaleform::GFx::DisplayObjContainer *)v11, v2);
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
char __fastcall Scaleform::GFx::AS2::AvmSprite::ReplaceChildCharacter(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::InteractiveObject *poldChar, Scaleform::GFx::InteractiveObject *pnewChar)
{
  Scaleform::GFx::InteractiveObject *v3; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rdi
  Scaleform::GFx::AS2::AvmSprite *v5; // rsi
  char v7; // al
  char v8; // al
  unsigned __int64 v9; // rax

  v3 = poldChar;
  v4 = pnewChar;
  v5 = this;
  Scaleform::GFx::DisplayObject::SetMask((Scaleform::GFx::DisplayObject *)&poldChar->vfptr, 0i64, 1);
  if ( (v3->Flags & 0x8000u) != 0 )
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(
      v5->pDispObj->pASRoot->pMovieImpl,
      (Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
  if ( Scaleform::GFx::DisplayList::GetDisplayIndex((Scaleform::GFx::DisplayList *)&v5->pDispObj[1], v3->Depth) == -1i64 )
    return 0;
  Scaleform::GFx::InteractiveObject::CopyPhysicalProperties(v4, v3);
  if ( (v4->Flags >> 10) & 1 && (v3->Flags >> 10) & 1 )
  {
    v7 = (char)v4[1].pIndXFormData;
    if ( (_QWORD)v3[1].pIndXFormData & 0x20 )
      v8 = v7 | 0x20;
    else
      v8 = v7 & 0xDF;
    LOBYTE(v4[1].pIndXFormData) = v8;
  }
  ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v3->vfptr[74].__vecDelDtor)(v3);
  ((void (*)(void))v5->pDispObj->pASRoot->vfptr[7].__vecDelDtor)();
  Scaleform::GFx::InteractiveObject::MoveNameHandle(v4, v3);
  v9 = Scaleform::GFx::DisplayList::GetDisplayIndex((Scaleform::GFx::DisplayList *)&v5->pDispObj[1], v3->Depth);
  if ( v9 == -1i64 )
    return 0;
  Scaleform::GFx::DisplayList::ReplaceDisplayObjectAtIndex(
    (Scaleform::GFx::DisplayList *)&v5->pDispObj[1],
    (Scaleform::GFx::DisplayObjectBase *)&v5->pDispObj->vfptr,
    v9,
    (Scaleform::GFx::DisplayObjectBase *)&v4->vfptr);
  return 1;
}

// File Line: 3569
// RVA: 0x710400
char __fastcall Scaleform::GFx::AS2::AvmSprite::ReplaceChildCharacterOnLoad(Scaleform::GFx::AS2::AvmSprite *this, Scaleform::GFx::InteractiveObject *poldChar, Scaleform::GFx::InteractiveObject *pnewChar)
{
  Scaleform::GFx::InteractiveObject *v3; // rbx
  Scaleform::GFx::AS2::AvmSprite *v4; // rdi
  char result; // al

  v3 = pnewChar;
  v4 = this;
  result = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *, Scaleform::GFx::InteractiveObject *))this->vfptr[2].ToAvmTextFieldBase)(
             this,
             poldChar);
  if ( result )
  {
    ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v3->vfptr[73].__vecDelDtor)(v3);
    ((void (*)(void))v4->pDispObj->pASRoot->vfptr[7].__vecDelDtor)();
    result = 1;
  }
  return result;
}

// File Line: 3580
// RVA: 0x7031D0
__int64 __fastcall Scaleform::GFx::AS2::AvmSprite::MustBeInPlaylist(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::Ptr<Scaleform::GFx::AS2::MovieClipObject> *v1; // rcx
  Scaleform::GFx::AS2::MovieClipObject *v2; // rax
  __int64 v4; // [rsp+20h] [rbp-28h]
  int v5; // [rsp+28h] [rbp-20h]
  char v6; // [rsp+2Ch] [rbp-1Ch]
  int v7; // [rsp+30h] [rbp-18h]

  v1 = &this[-1].ASMovieClipObj;
  v5 = 0;
  v6 = 0;
  v2 = v1->pObject;
  v4 = 2i64;
  v7 = 65280;
  return ((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::MovieClipObject> *, __int64 *))v2->ResolveHandler.Function)(
           v1,
           &v4);
}

// File Line: 3592
// RVA: 0x6EE890
signed __int64 __fastcall Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASMovieRootBase *v2; // rax
  Scaleform::GFx::ASStringNode *v3; // rcx

  v2 = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  v3 = name->pNode;
  if ( v2[26].vfptr == (Scaleform::RefCountImplCoreVtbl *)name->pNode )
    return 1i64;
  if ( *(Scaleform::GFx::ASStringNode **)&v2[26].RefCount == v3 )
    return 2i64;
  if ( (Scaleform::GFx::ASStringNode *)v2[26].pMovieImpl == v3 )
    return 4i64;
  if ( (Scaleform::GFx::ASStringNode *)v2[26].pASSupport.pObject == v3 )
    return 8i64;
  if ( *(Scaleform::GFx::ASStringNode **)&v2[26].AVMVersion == v3 )
    return 16i64;
  if ( (Scaleform::GFx::ASStringNode *)v2[27].vfptr == v3 )
    return 32i64;
  if ( *(Scaleform::GFx::ASStringNode **)&v2[27].RefCount == v3 )
    return 64i64;
  if ( (Scaleform::GFx::ASStringNode *)v2[32].vfptr == v3 )
    return 128i64;
  if ( *(Scaleform::GFx::ASStringNode **)&v2[32].RefCount == v3 )
    return 256i64;
  if ( (Scaleform::GFx::ASStringNode *)v2[32].pMovieImpl == v3 )
    return 512i64;
  if ( (Scaleform::GFx::ASStringNode *)v2[32].pASSupport.pObject == v3 )
    return 1024i64;
  if ( *(Scaleform::GFx::ASStringNode **)&v2[32].AVMVersion == v3 )
    return 2048i64;
  return 0i64;
}

// File Line: 3656
// RVA: 0x71E210
void __fastcall Scaleform::GFx::AS2::MovieClipObject::Set__proto__(Scaleform::GFx::AS2::MovieClipObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *protoObj)
{
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  Scaleform::GFx::AS2::MovieClipObject *v5; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int v7; // eax
  __int64 (__fastcall **v8)(void *); // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // [rsp+40h] [rbp-18h]
  Scaleform::GFx::AS2::ASStringContext *v10; // [rsp+48h] [rbp-10h]

  v3 = protoObj;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&this->vfptr, psc, protoObj);
  if ( v3 && (*(unsigned int (**)(void))&v3->vfptr->gap8[8])() != 11 )
  {
    v8 = &`Scaleform::GFx::AS2::MovieClipObject::Set__proto__'::`5'::MemberVisitor::`vftable';
    if ( v5 != (Scaleform::GFx::AS2::MovieClipObject *)32 )
      LODWORD((&v5[-1].pWatchpoints)[3]) = (LODWORD((&v5[-1].pWatchpoints)[3]) + 1) & 0x8FFFFFFF;
    v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5[-1].pWatchpoints;
    v10 = v4;
    (*(void (__fastcall **)(unsigned __int64 *, Scaleform::GFx::AS2::ASStringContext *, __int64 (__fastcall ***)(void *), signed __int64, _QWORD))(v5->pRCC->Roots.NumPages + 64))(
      &v5->pRCC->Roots.NumPages,
      v4,
      &v8,
      13i64,
      0i64);
    v6 = v9;
    if ( v9 )
    {
      v7 = v9->RefCount;
      if ( v7 & 0x3FFFFFF )
      {
        v9->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
  }
}

// File Line: 3676
// RVA: 0x7237D0
void __fastcall Scaleform::GFx::AS2::MovieClipObject::Set__proto___::_5_::MemberVisitor::Visit(Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, char flags)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = name;
  if ( (unsigned __int16)Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(
                           (Scaleform::GFx::AS2::ASStringContext *)name[2].pNode,
                           (Scaleform::GFx::ASString *)val) )
    BYTE2(v3[1].pNode[2].RefCount) = 1;
}

// File Line: 3692
// RVA: 0x6D7850
char __fastcall Scaleform::GFx::AS2::MovieClipObject::ActsAsButton(Scaleform::GFx::AS2::MovieClipObject *this)
{
  Scaleform::GFx::AS2::MovieClipObject *i; // rbx
  signed __int64 v2; // rdi

  i = this;
  if ( !this->ButtonEventMask )
  {
    while ( 2 )
    {
      if ( !i->HasButtonHandlers )
      {
        v2 = (signed __int64)&i->pProto;
        for ( i = (Scaleform::GFx::AS2::MovieClipObject *)i->pProto.pObject;
              ;
              i = (Scaleform::GFx::AS2::MovieClipObject *)i->pProto.pObject )
        {
          if ( !i )
            return 0;
          if ( (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)(*(_QWORD *)v2 + 32i64) + 16i64))(*(_QWORD *)v2 + 32i64) == 11 )
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
void __fastcall Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(Scaleform::GFx::AS2::MovieClipObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // rbp
  Scaleform::GFx::ASString *v5; // rsi
  Scaleform::GFx::AS2::ASStringContext *v6; // r14
  Scaleform::GFx::AS2::MovieClipObject *v7; // rdi
  Scaleform::GFx::DisplayObjectBase *v8; // rbx
  Scaleform::GFx::ASString v9; // rax
  __int16 v10; // ax
  Scaleform::GFx::ASString v11; // r8
  signed __int64 v12; // rcx
  Scaleform::GFx::ASMovieRootBase *v13; // rax
  Scaleform::GFx::AS2::Environment *v14; // rax
  const char ***v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::AS2::Environment *v18; // rax
  float v19; // xmm1_4
  Scaleform::GFx::AS2::Environment *v20; // rax
  bool v21; // al
  Scaleform::GFx::DisplayObjectBase *v22; // [rsp+20h] [rbp-48h]
  Scaleform::GFx::ASString result; // [rsp+28h] [rbp-40h]
  __int64 v24; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::AS2::Value v25; // [rsp+38h] [rbp-30h]

  v24 = -2i64;
  v4 = val;
  v5 = name;
  v6 = psc;
  v7 = this;
  Scaleform::GFx::AS2::MovieClipObject::GetSprite(this, (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&v22);
  v8 = v22;
  if ( v22 )
  {
    if ( v22->vfptr[68].__vecDelDtor((Scaleform::RefCountNTSImplCore *)v22, 0) == v8 )
    {
LABEL_12:
      v8 = v22;
      goto LABEL_13;
    }
    v8 = v22;
  }
  v9.pNode = v5->pNode;
  if ( v5->pNode->Size > 2 && *v9.pNode->pData == 111 && *((_BYTE *)v9.pNode->pData + 1) == 110 )
  {
    v25.T.Type = 0;
    if ( !v7->vfptr->GetMemberRaw((Scaleform::GFx::AS2::ObjectInterface *)&v7->vfptr, v6, v5, &v25) )
    {
      v10 = Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(v6, v5);
      if ( v10 )
        v7->ButtonEventMask |= v10;
    }
    if ( v25.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v25);
    goto LABEL_12;
  }
LABEL_13:
  if ( v8 )
  {
    v11.pNode = v5->pNode;
    if ( (v5->pNode->HashFlags & 0x80000000) != 0 )
    {
      v12 = (signed __int64)v8 + 4 * (unsigned __int8)v8->AvmObjOffset;
      v13 = v6->pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( v11.pNode == (Scaleform::GFx::ASStringNode *)v13[38].vfptr )
      {
        v14 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (**)(void))(*(_QWORD *)v12 + 240i64))();
        v15 = (const char ***)Scaleform::GFx::AS2::Value::ToString(v4, &result, v14, -1);
        Scaleform::GFx::DisplayObjectBase::SetRendererString(v22, **v15);
        v16 = result.pNode;
        v17 = result.pNode->RefCount == 1;
        --v16->RefCount;
        if ( v17 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      }
      else if ( v11.pNode == *(Scaleform::GFx::ASStringNode **)&v13[38].RefCount )
      {
        v18 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (**)(void))(*(_QWORD *)v12 + 240i64))();
        v19 = Scaleform::GFx::AS2::Value::ToNumber(v4, v18);
        Scaleform::GFx::DisplayObjectBase::SetRendererFloat(v8, v19);
      }
      else if ( v11.pNode == (Scaleform::GFx::ASStringNode *)v13[38].pMovieImpl )
      {
        v20 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (**)(void))(*(_QWORD *)v12 + 240i64))();
        v21 = Scaleform::GFx::AS2::Value::ToBool(v4, v20);
        Scaleform::GFx::DisplayObjectBase::DisableBatching(v8, v21);
      }
    }
  }
  if ( v22 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v22->vfptr);
}

// File Line: 3758
// RVA: 0x719BD0
bool __fastcall Scaleform::GFx::AS2::MovieClipObject::SetMemberRaw(Scaleform::GFx::AS2::MovieClipObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::MovieClipObject *v5; // rbp
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::ASString *v7; // rdi
  Scaleform::GFx::AS2::ASStringContext *v8; // rsi

  v5 = this;
  v6 = val;
  v7 = name;
  v8 = psc;
  Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(
    (Scaleform::GFx::AS2::MovieClipObject *)((char *)this - 32),
    psc,
    name,
    val);
  return Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v8, v7, v6, flags);
}

// File Line: 3767
// RVA: 0x717A90
bool __fastcall Scaleform::GFx::AS2::MovieClipObject::SetMember(Scaleform::GFx::AS2::MovieClipObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Environment *v5; // rsi
  Scaleform::GFx::AS2::MovieClipObject *v6; // rbp
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::ASString *v8; // rdi

  v5 = penv;
  v6 = this;
  v7 = val;
  v8 = name;
  Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(
    (Scaleform::GFx::AS2::MovieClipObject *)((char *)this - 32),
    &penv->StringContext,
    name,
    val);
  return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v6->vfptr, v5, v8, v7, flags);
}

// File Line: 3782
// RVA: 0x6E2100
bool __fastcall Scaleform::GFx::AS2::MovieClipObject::DeleteMember(Scaleform::GFx::AS2::MovieClipObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  Scaleform::GFx::AS2::MovieClipObject *v5; // rbx
  const char *v6; // rax
  unsigned __int16 v7; // ax
  Scaleform::GFx::AS2::Value v9; // [rsp+28h] [rbp-30h]

  v3 = name;
  v4 = psc;
  v5 = this;
  if ( name->pNode->Size > 2 )
  {
    v6 = name->pNode->pData;
    if ( *v6 == 111 && v6[1] == 110 )
    {
      v9.T.Type = 0;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::MovieClipObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))this->vfptr[3].~RefCountBaseGC<323>)(
             this,
             psc,
             name,
             &v9,
             -2i64) )
      {
        v7 = Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(v4, v3);
        if ( v7 )
          *(_WORD *)&v5->ResolveHandler.Flags &= ~v7;
      }
      if ( v9.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v9);
    }
  }
  return Scaleform::GFx::AS2::Object::DeleteMember((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v3);
}

// File Line: 3870
// RVA: 0x6CAB00
void __fastcall Scaleform::GFx::AS2::MovieClipProto::MovieClipProto(Scaleform::GFx::AS2::MovieClipProto *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *prototype, Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  Scaleform::GFx::AS2::MovieClipProto *v5; // r14
  Scaleform::GFx::ASString *v6; // rbx
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+88h] [rbp+10h]

  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>(
    (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment> *)&this->vfptr,
    psc,
    prototype,
    constructor);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v5->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::MovieClipProto::`vftable';
  flags.Flags = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&v5->vfptr,
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    MovieClipFunctionTable,
    &flags);
  flags.Flags = 3;
  val.T.Type = 2;
  val.V.BooleanValue = 1;
  v6 = (Scaleform::GFx::ASString *)v4->pContext->pMovieRoot->pASMovieRoot.pObject;
  Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(
    (Scaleform::GFx::AS2::MovieClipObject *)&v5->vfptr,
    v4,
    v6 + 167,
    &val);
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v6 + 167, &val, &flags);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 3877
// RVA: 0x6E0630
void __fastcall Scaleform::GFx::AS2::MovieClipCtorFunction::CreateNewObject(Scaleform::GFx::AS2::MovieClipCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::MovieClipObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::MovieClipObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieClipCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                 this,
                                                 112i64);
  if ( v3 )
    Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(v3, v2);
}

// File Line: 3882
// RVA: 0x6F96C0
void __fastcall Scaleform::GFx::AS2::MovieClipCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // rbx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 11 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v3[-2]);
    else
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, 0i64);
  }
  else
  {
    v4 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v4);
    v4->T.Type = 0;
  }
}

