// File Line: 112
// RVA: 0x89B290
void __fastcall Scaleform::GFx::MovieHeaderData::MovieHeaderData(Scaleform::GFx::MovieHeaderData *this)
{
  Scaleform::GFx::MovieHeaderData *v1; // rdi
  Scaleform::String *v2; // rbx
  signed __int64 v3; // [rsp+60h] [rbp+18h]

  v1 = this;
  this->FileLength = 0;
  this->Version = -1;
  *(_QWORD *)&this->FrameRect.x1 = 0i64;
  *(_QWORD *)&this->FrameRect.x2 = 0i64;
  this->FPS = 1.0;
  this->SWFFlags = 0;
  v2 = (Scaleform::String *)&this->mExporterInfo;
  Scaleform::String::String(&this->mExporterInfo.Prefix);
  Scaleform::String::String(v2 + 5);
  v3 = (signed __int64)&v2[6];
  *(_OWORD *)v3 = 0ui64;
  *(_QWORD *)(v3 + 16) = 0i64;
  LODWORD(v2->pData) = 0;
  v2[2].HeapTypeBits = 0i64;
  v2[1].HeapTypeBits = 0i64;
  HIDWORD(v2[3].HeapTypeBits) = 0;
  LOWORD(v2[3].pData) = 0;
  v1->FrameCount = 1;
}

// File Line: 156
// RVA: 0x89C930
void __fastcall Scaleform::GFx::SWFProcessInfo::SWFProcessInfo(Scaleform::GFx::SWFProcessInfo *this, Scaleform::MemoryHeap *pheap)
{
  Scaleform::GFx::SWFProcessInfo *v2; // rbx
  Scaleform::Render::RenderBuffer *v3; // rcx

  v2 = this;
  this->Stream.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::`vftable;
  this->Stream.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::Stream::`vftable;
  this->Stream.pInput.pObject = 0i64;
  Scaleform::StringDH::StringDH(&this->Stream.FileName, pheap);
  v2->Stream.BufferSize = 512;
  v2->Stream.pBuffer = v2->Stream.BuiltinBuffer;
  v3 = (Scaleform::Render::RenderBuffer *)v2->Stream.pInput.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v2->Stream.pInput.pObject = 0i64;
  v2->Stream.pLog = 0i64;
  v2->Stream.pParseControl = 0i64;
  v2->Stream.ParseFlags = 0;
  *(_WORD *)&v2->Stream.CurrentByte = 0;
  Scaleform::String::Clear((Scaleform::String *)&v2->Stream.FileName.0);
  *(_QWORD *)&v2->Stream.TagStack[1] = 0i64;
  v2->Stream.TagStack[0] = 0;
  *(_QWORD *)&v2->Stream.Pos = 0i64;
  v2->Stream.ResyncFile = 0;
  v2->Stream.FilePos = 0;
  Scaleform::GFx::MovieHeaderData::MovieHeaderData(&v2->Header);
  v2->FileAttributes = 0;
}

// File Line: 244
// RVA: 0x89CED0
void __fastcall Scaleform::GFx::StateBagImpl::StateBagImpl(Scaleform::GFx::StateBagImpl *this, Scaleform::GFx::StateBagImpl *pdelegate)
{
  Scaleform::GFx::StateBagImpl *v2; // rdi
  Scaleform::GFx::StateBagImpl *v3; // rbx
  Scaleform::Render::RenderBuffer *v4; // rcx

  v2 = pdelegate;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>::`vftable;
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>};
  this->pDelegate.pObject = 0i64;
  this->States.pTable = 0i64;
  Scaleform::Lock::Lock(&this->StateLock, 0);
  if ( v2 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v2);
  v4 = (Scaleform::Render::RenderBuffer *)v3->pDelegate.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v3->pDelegate.pObject = v2;
}

// File Line: 249
// RVA: 0x8A7C00
void __fastcall Scaleform::GFx::StateBagImpl::~StateBagImpl(Scaleform::GFx::StateBagImpl *this)
{
  Scaleform::GFx::StateBagImpl *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>};
  Scaleform::Lock::~Lock(&this->StateLock.cs);
  Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::~HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>((Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp> > *)&v1->States.pTable);
  v2 = (Scaleform::Render::RenderBuffer *)v1->pDelegate.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v1->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::`vftable;
  v1->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 274
// RVA: 0x90C240
void __fastcall Scaleform::GFx::StateBagImpl::SetState(Scaleform::GFx::StateBagImpl *this, Scaleform::GFx::State::StateType state, Scaleform::GFx::State *pstate)
{
  Scaleform::GFx::State *v3; // rsi
  Scaleform::GFx::StateBagImpl *v4; // rdi
  _RTL_CRITICAL_SECTION *v5; // rbx
  Scaleform::GFx::StateBagImpl::StatePtr key; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::State::StateType v7; // [rsp+58h] [rbp+10h]
  Scaleform::Ptr<Scaleform::GFx::StateBagImpl> *v8; // [rsp+60h] [rbp+18h]

  v7 = state;
  v3 = pstate;
  v4 = this;
  v5 = (_RTL_CRITICAL_SECTION *)&this->pDelegate;
  v8 = &this->pDelegate;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->pDelegate);
  if ( v3 )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v3);
    key.pState.pObject = v3;
    Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::Set<Scaleform::GFx::StateBagImpl::StatePtr>(
      (Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp> > *)&v4->vfptr,
      &v4->vfptr,
      &key);
    if ( key.pState.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)key.pState.pObject);
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::RemoveAlt<enum  Scaleform::GFx::State::StateType>(
      (Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp> > *)&v4->vfptr,
      &v7);
  }
  LeaveCriticalSection(v5);
}

// File Line: 283
// RVA: 0x8DE300
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::StateBagImpl::GetStateAddRef(Scaleform::GFx::StateBagImpl *this, Scaleform::GFx::State::StateType state)
{
  __int64 v2; // rsi
  Scaleform::GFx::StateBagImpl *v3; // rbp
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *v5; // r9
  void *(__fastcall *v6)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int); // r8
  void *(__fastcall *v7)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int); // rcx
  void *(__fastcall **v8)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int); // rdx
  Scaleform::GFx::Resource **v9; // rdi
  Scaleform::GFx::Resource *v10; // rdi
  Scaleform::GFx::Resource *result; // rax
  Scaleform::GFx::StateBagVtbl *v12; // rcx

  v2 = state;
  v3 = this;
  v4 = (_RTL_CRITICAL_SECTION *)&this->pDelegate;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->pDelegate);
  v5 = v3->vfptr;
  if ( !v5 )
    goto LABEL_11;
  v6 = (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))(v2 & (_QWORD)v5->IsVerboseActionErrors);
  v7 = v6;
  v8 = &v5->__vecDelDtor + (_QWORD)v6 + 2 * ((_QWORD)v6 + 1);
  if ( *v8 == (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))-2i64
    || v8[1] != v6 )
  {
    goto LABEL_11;
  }
  while ( v8[1] != v6 || *((_DWORD *)v8[2] + 4) != (_DWORD)v2 )
  {
    v7 = *v8;
    if ( *v8 == (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))-1i64 )
      goto LABEL_11;
    v8 = &v5->__vecDelDtor + (_QWORD)v7 + 2 * ((_QWORD)v7 + 1);
  }
  if ( (signed __int64)v7 >= 0
    && (v9 = (Scaleform::GFx::Resource **)(&v5->__vecDelDtor + (_QWORD)v7 + 2 * ((_QWORD)v7 + 2))) != 0i64 )
  {
    Scaleform::Render::RenderBuffer::AddRef(*v9);
    v10 = *v9;
    LeaveCriticalSection(v4);
    result = v10;
  }
  else
  {
LABEL_11:
    LeaveCriticalSection(v4);
    v12 = v3->vfptr;
    if ( v12 )
      result = (Scaleform::GFx::Resource *)(*((__int64 (__fastcall **)(void (__fastcall **)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType, Scaleform::GFx::State *), _QWORD))v12->SetState
                                            + 3))(
                                             &v12->SetState,
                                             (unsigned int)v2);
    else
      result = 0i64;
  }
  return result;
}

// File Line: 304
// RVA: 0x8DE490
void __fastcall Scaleform::GFx::StateBagImpl::GetStatesAddRef(Scaleform::GFx::StateBagImpl *this, Scaleform::GFx::State **pstateList, Scaleform::GFx::State::StateType *pstates, unsigned int count)
{
  unsigned int v4; // er13
  Scaleform::GFx::State::StateType *v5; // rdi
  Scaleform::GFx::State **v6; // rsi
  Scaleform::GFx::StateBagImpl *v7; // r15
  char v8; // r12
  _RTL_CRITICAL_SECTION *v9; // rbx
  Scaleform::GFx::State::StateType *v10; // r14
  __int64 v11; // rbp
  Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *v12; // r8
  __int64 v13; // r10
  void *(__fastcall *v14)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int); // r9
  void *(__fastcall *v15)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int); // rax
  void *(__fastcall **v16)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int); // rdx
  Scaleform::GFx::Resource **v17; // rdi
  Scaleform::GFx::StateBagVtbl *v18; // rcx
  Scaleform::GFx::State **v19; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::State::StateType *v20; // [rsp+80h] [rbp+18h]

  v20 = pstates;
  v19 = pstateList;
  v4 = count;
  v5 = pstates;
  v6 = pstateList;
  v7 = this;
  v8 = 0;
  v9 = (_RTL_CRITICAL_SECTION *)&this->pDelegate;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->pDelegate);
  if ( v4 )
  {
    v10 = v5;
    v11 = v4;
    do
    {
      if ( !*v6 )
      {
        v12 = v7->vfptr;
        if ( !v12 )
          goto LABEL_14;
        v13 = *(signed int *)v10;
        v14 = (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))(v13 & (_QWORD)v12->IsVerboseActionErrors);
        v15 = v14;
        v16 = &v12->__vecDelDtor + (_QWORD)v14 + 2 * ((_QWORD)v14 + 1);
        if ( *v16 == (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))-2i64
          || v16[1] != v14 )
        {
          goto LABEL_14;
        }
        while ( v16[1] != v14 || *((_DWORD *)v16[2] + 4) != (_DWORD)v13 )
        {
          v15 = *v16;
          if ( *v16 == (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))-1i64 )
            goto LABEL_14;
          v16 = &v12->__vecDelDtor + (_QWORD)v15 + 2 * ((_QWORD)v15 + 1);
        }
        if ( (signed __int64)v15 >= 0
          && (v17 = (Scaleform::GFx::Resource **)(&v12->__vecDelDtor + (_QWORD)v15 + 2 * ((_QWORD)v15 + 2))) != 0i64 )
        {
          Scaleform::Render::RenderBuffer::AddRef(*v17);
          *v6 = (Scaleform::GFx::State *)*v17;
        }
        else
        {
LABEL_14:
          v8 = 1;
        }
      }
      ++v10;
      ++v6;
      --v11;
    }
    while ( v11 );
    v5 = v20;
    v6 = v19;
  }
  LeaveCriticalSection(v9);
  if ( v8 )
  {
    v18 = v7->vfptr;
    if ( v18 )
      (*((void (__fastcall **)(void (__fastcall **)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType, Scaleform::GFx::State *), Scaleform::GFx::State **, Scaleform::GFx::State::StateType *, _QWORD, signed __int64))v18->SetState
       + 4))(
        &v18->SetState,
        v6,
        v5,
        v4,
        -2i64);
  }
}

// File Line: 406
// RVA: 0x8DE420
Scaleform::GFx::StateBagVtbl *__fastcall Scaleform::GFx::LoaderImpl::GetStateBagImpl(Scaleform::GFx::LoaderImpl *this)
{
  Scaleform::GFx::StateBagVtbl *result; // rax

  result = this->vfptr;
  if ( result )
    result = (Scaleform::GFx::StateBagVtbl *)((char *)result + 16);
  return result;
}

