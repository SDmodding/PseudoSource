// File Line: 112
// RVA: 0x89B290
void __fastcall Scaleform::GFx::MovieHeaderData::MovieHeaderData(Scaleform::GFx::MovieHeaderData *this)
{
  Scaleform::GFx::ExporterInfoImpl *p_mExporterInfo; // rbx

  this->FileLength = 0;
  this->Version = -1;
  *(_QWORD *)&this->FrameRect.x1 = 0i64;
  *(_QWORD *)&this->FrameRect.x2 = 0i64;
  this->FPS = 1.0;
  this->SWFFlags = 0;
  p_mExporterInfo = &this->mExporterInfo;
  Scaleform::String::String(&this->mExporterInfo.Prefix);
  Scaleform::String::String(&p_mExporterInfo->SWFName);
  p_mExporterInfo->CodeOffsets.Data.Data = 0i64;
  p_mExporterInfo->CodeOffsets.Data.Size = 0i64;
  p_mExporterInfo->CodeOffsets.Data.Policy.Capacity = 0i64;
  p_mExporterInfo->SI.Format = File_Unopened;
  p_mExporterInfo->SI.pSWFName = 0i64;
  p_mExporterInfo->SI.pPrefix = 0i64;
  p_mExporterInfo->SI.ExportFlags = 0;
  p_mExporterInfo->SI.Version = 0;
  this->FrameCount = 1;
}

// File Line: 156
// RVA: 0x89C930
void __fastcall Scaleform::GFx::SWFProcessInfo::SWFProcessInfo(
        Scaleform::GFx::SWFProcessInfo *this,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->Stream.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::`vftable;
  this->Stream.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *)&Scaleform::GFx::Stream::`vftable;
  this->Stream.pInput.pObject = 0i64;
  Scaleform::StringDH::StringDH(&this->Stream.FileName, pheap);
  this->Stream.BufferSize = 512;
  this->Stream.pBuffer = this->Stream.BuiltinBuffer;
  pObject = (Scaleform::Render::RenderBuffer *)this->Stream.pInput.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Stream.pInput.pObject = 0i64;
  this->Stream.pLog = 0i64;
  this->Stream.pParseControl = 0i64;
  this->Stream.ParseFlags = 0;
  *(_WORD *)&this->Stream.CurrentByte = 0;
  Scaleform::String::Clear(&this->Stream.FileName);
  *(_QWORD *)&this->Stream.TagStack[1] = 0i64;
  this->Stream.TagStack[0] = 0;
  *(_QWORD *)&this->Stream.Pos = 0i64;
  this->Stream.ResyncFile = 0;
  this->Stream.FilePos = 0;
  Scaleform::GFx::MovieHeaderData::MovieHeaderData(&this->Header);
  this->FileAttributes = 0;
}

// File Line: 244
// RVA: 0x89CED0
void __fastcall Scaleform::GFx::StateBagImpl::StateBagImpl(
        Scaleform::GFx::StateBagImpl *this,
        Scaleform::GFx::Resource *pdelegate)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>::`vftable;
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>};
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>};
  this->pDelegate.pObject = 0i64;
  this->States.pTable = 0i64;
  Scaleform::Lock::Lock(&this->StateLock, 0);
  if ( pdelegate )
    Scaleform::Render::RenderBuffer::AddRef(pdelegate);
  pObject = (Scaleform::Render::RenderBuffer *)this->pDelegate.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pDelegate.pObject = (Scaleform::GFx::StateBagImpl *)pdelegate;
}

// File Line: 249
// RVA: 0x8A7C00
void __fastcall Scaleform::GFx::StateBagImpl::~StateBagImpl(Scaleform::GFx::StateBagImpl *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>};
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *)&Scaleform::GFx::StateBagImpl::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>};
  Scaleform::Lock::~Lock(&this->StateLock.cs);
  Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::~HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>(&this->States);
  pObject = (Scaleform::Render::RenderBuffer *)this->pDelegate.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::`vftable;
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 274
// RVA: 0x90C240
void __fastcall Scaleform::GFx::StateBagImpl::SetState(
        Scaleform::GFx::StateBagImpl *this,
        Scaleform::GFx::State::StateType state,
        Scaleform::GFx::Resource *pstate)
{
  _RTL_CRITICAL_SECTION *p_pDelegate; // rbx
  Scaleform::GFx::StateBagImpl::StatePtr key; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::State::StateType v7; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::Ptr<Scaleform::GFx::StateBagImpl> *v8; // [rsp+60h] [rbp+18h]

  v7 = state;
  p_pDelegate = (_RTL_CRITICAL_SECTION *)&this->pDelegate;
  v8 = &this->pDelegate;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->pDelegate);
  if ( pstate )
  {
    Scaleform::Render::RenderBuffer::AddRef(pstate);
    key.pState.pObject = (Scaleform::GFx::State *)pstate;
    Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::Set<Scaleform::GFx::StateBagImpl::StatePtr>(
      (Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp> > *)&this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>,
      &this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>,
      &key);
    if ( key.pState.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)key.pState.pObject);
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::RemoveAlt<enum Scaleform::GFx::State::StateType>(
      (Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp> > *)&this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>,
      &v7);
  }
  LeaveCriticalSection(p_pDelegate);
}

// File Line: 283
// RVA: 0x8DE300
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::StateBagImpl::GetStateAddRef(
        Scaleform::GFx::StateBagImpl *this,
        Scaleform::GFx::State::StateType state)
{
  __int64 v2; // rsi
  _RTL_CRITICAL_SECTION *p_pDelegate; // rbx
  Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *vfptr; // r9
  __int64 v6; // r8
  __int64 v7; // rcx
  void *(__fastcall **v8)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int); // rdx
  Scaleform::GFx::Resource **v9; // rdi
  Scaleform::GFx::Resource *v10; // rdi
  Scaleform::GFx::StateBagVtbl *v12; // rcx

  v2 = state;
  p_pDelegate = (_RTL_CRITICAL_SECTION *)&this->pDelegate;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->pDelegate);
  vfptr = this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::vfptr;
  if ( !vfptr )
    goto LABEL_11;
  v6 = v2 & (__int64)vfptr->IsVerboseActionErrors;
  v7 = v6;
  v8 = &vfptr[v6 + 1].__vecDelDtor + v6;
  if ( *v8 == (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))-2i64
    || v8[1] != (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))v6 )
  {
    goto LABEL_11;
  }
  while ( v8[1] != (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))v6
       || *((_DWORD *)v8[2] + 4) != (_DWORD)v2 )
  {
    v7 = (__int64)*v8;
    if ( *v8 == (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))-1i64 )
      goto LABEL_11;
    v8 = &vfptr[v7 + 1].__vecDelDtor + v7;
  }
  if ( v7 >= 0 && (v9 = (Scaleform::GFx::Resource **)(&vfptr[v7 + 2].__vecDelDtor + v7)) != 0i64 )
  {
    Scaleform::Render::RenderBuffer::AddRef(*v9);
    v10 = *v9;
    LeaveCriticalSection(p_pDelegate);
    return v10;
  }
  else
  {
LABEL_11:
    LeaveCriticalSection(p_pDelegate);
    v12 = this->Scaleform::GFx::StateBag::vfptr;
    if ( v12 )
      return (Scaleform::GFx::Resource *)(*((__int64 (__fastcall **)(void (__fastcall **)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType, Scaleform::GFx::State *), _QWORD))v12->SetState
                                          + 3))(
                                           &v12->SetState,
                                           (unsigned int)v2);
    else
      return 0i64;
  }
}

// File Line: 304
// RVA: 0x8DE490
void __fastcall Scaleform::GFx::StateBagImpl::GetStatesAddRef(
        Scaleform::GFx::StateBagImpl *this,
        Scaleform::GFx::State **pstateList,
        Scaleform::GFx::State::StateType *pstates,
        unsigned int count)
{
  Scaleform::GFx::State::StateType *v5; // rdi
  Scaleform::GFx::State **v6; // rsi
  char v8; // r12
  _RTL_CRITICAL_SECTION *p_pDelegate; // rbx
  Scaleform::GFx::State::StateType *v10; // r14
  __int64 v11; // rbp
  Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>Vtbl *vfptr; // r8
  __int64 v13; // r10
  __int64 v14; // r9
  __int64 v15; // rax
  void *(__fastcall **v16)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int); // rdx
  Scaleform::GFx::Resource **v17; // rdi
  Scaleform::GFx::StateBagVtbl *v18; // rcx

  v5 = pstates;
  v6 = pstateList;
  v8 = 0;
  p_pDelegate = (_RTL_CRITICAL_SECTION *)&this->pDelegate;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->pDelegate);
  if ( count )
  {
    v10 = v5;
    v11 = count;
    do
    {
      if ( !*v6 )
      {
        vfptr = this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::vfptr;
        if ( !vfptr )
          goto LABEL_14;
        v13 = *(int *)v10;
        v14 = v13 & (__int64)vfptr->IsVerboseActionErrors;
        v15 = v14;
        v16 = &vfptr[v14 + 1].__vecDelDtor + v14;
        if ( *v16 == (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))-2i64
          || v16[1] != (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))v14 )
        {
          goto LABEL_14;
        }
        while ( v16[1] != (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))v14
             || *((_DWORD *)v16[2] + 4) != (_DWORD)v13 )
        {
          v15 = (__int64)*v16;
          if ( *v16 == (void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl> *, unsigned int))-1i64 )
            goto LABEL_14;
          v16 = &vfptr[v15 + 1].__vecDelDtor + v15;
        }
        if ( v15 >= 0 && (v17 = (Scaleform::GFx::Resource **)(&vfptr[v15 + 2].__vecDelDtor + v15)) != 0i64 )
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
    v5 = pstates;
    v6 = pstateList;
  }
  LeaveCriticalSection(p_pDelegate);
  if ( v8 )
  {
    v18 = this->Scaleform::GFx::StateBag::vfptr;
    if ( v18 )
      (*((void (__fastcall **)(void (__fastcall **)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType, Scaleform::GFx::State *), Scaleform::GFx::State **, Scaleform::GFx::State::StateType *, _QWORD, __int64))v18->SetState
       + 4))(
        &v18->SetState,
        v6,
        v5,
        count,
        -2i64);
  }
}

// File Line: 406
// RVA: 0x8DE420
Scaleform::GFx::StateBagVtbl *__fastcall Scaleform::GFx::LoaderImpl::GetStateBagImpl(Scaleform::GFx::LoaderImpl *this)
{
  Scaleform::GFx::StateBagVtbl *result; // rax

  result = this->Scaleform::GFx::StateBag::vfptr;
  if ( result )
    return (Scaleform::GFx::StateBagVtbl *)((char *)result + 16);
  return result;
}

