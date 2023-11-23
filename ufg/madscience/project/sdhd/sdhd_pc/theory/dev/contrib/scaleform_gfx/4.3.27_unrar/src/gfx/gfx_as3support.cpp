// File Line: 56
// RVA: 0x8C92A0
void __fastcall Scaleform::GFx::AS3::DoAbc::Execute(
        Scaleform::GFx::AS3::DoAbc *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // rsi
  Scaleform::GFx::Resource *pObject; // rbx
  Scaleform::GFx::AS3::MovieRoot *AS3Root; // rax
  Scaleform::Log *v6; // rbx
  __int64 v7; // rdi
  Scaleform::Log *v8; // rbx
  const char *v9; // rax
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+40h] [rbp+8h] BYREF

  v3 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset);
  pObject = (Scaleform::GFx::Resource *)this->pAbc.pObject;
  AS3Root = Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Root(v3);
  if ( !Scaleform::GFx::AS3::MovieRoot::ExecuteAbc(AS3Root, pObject, m) )
  {
    v6 = Scaleform::GFx::StateBag::GetLog(&v3->pDispObj->pASRoot->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v6 )
    {
      v7 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(m);
      v8 = Scaleform::GFx::StateBag::GetLog(&v3->pDispObj->pASRoot->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
      v9 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 96i64))(v7);
      Scaleform::Log::LogError(v8, "Cant execute ABC from %s", v9);
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    }
  }
}

// File Line: 71
// RVA: 0x8CB180
const char *__fastcall UFG::SimComponent::GetDebugTypeName(UFG::SimComponent *this)
{
  return (const char *)((__int64 (__fastcall *)(UFG::SimComponent *))this->vfptr[1].__vecDelDtor)(this);
}

// File Line: 93
// RVA: 0x912820
void __fastcall Scaleform::GFx::AS3::SymbolClassLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // r15
  __int64 Pos; // r9
  unsigned __int16 v5; // r8
  __int64 v6; // rbx
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v7; // r14
  __int64 v8; // rsi
  __int64 v9; // r8
  unsigned __int16 v10; // di
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // r13
  Scaleform::StringHashLH<Scaleform::GFx::ResourceHandle,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_Exports; // rsi
  unsigned __int64 v13; // r14
  __int64 v14; // rbx
  __int64 *v15; // rdi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 *v17; // rdi
  __int64 v18; // rbx
  __int64 v19; // rcx
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // r14
  __int64 v22; // rbx
  __int64 *v23; // rdi
  Scaleform::StringLH *v24; // rdx
  Scaleform::GFx::Resource *pResource; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v27; // [rsp+20h] [rbp-50h]
  Scaleform::StringDH v28; // [rsp+30h] [rbp-40h] BYREF
  Scaleform::GFx::ResourceHandle phandle; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef v31; // [rsp+60h] [rbp-10h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+B0h] [rbp+40h] BYREF
  int v33; // [rsp+C0h] [rbp+50h] BYREF
  __int64 v34; // [rsp+C8h] [rbp+58h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v6 = v5;
  v7 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  SymbolClassLoader: num = %d\n");
  if ( (_DWORD)v6 )
  {
    v8 = (unsigned int)v6;
    v34 = v6;
    do
    {
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v9 = pAltStream->Stream.Pos;
      v10 = (unsigned __int8)pAltStream->Stream.pBuffer[v9] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v9 + 1)] << 8);
      pAltStream->Stream.Pos = v9 + 2;
      Scaleform::StringDH::StringDH(&v28, p->pLoadData.pObject->pHeap);
      Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &v28);
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)v7,
        "       id = %d, symbol = %s\n");
      phandle.HType = RH_Pointer;
      phandle.pResource = 0i64;
      if ( !v10
        || (rid.Id = v10,
            (unsigned __int8)Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                               p->pLoadData.pObject,
                               &phandle,
                               &rid)) )
      {
        v33 = v10;
        pObject = p->pLoadData.pObject;
        v27 = 0i64;
        if ( pObject->LoadState < LS_LoadFinished )
        {
          v27 = p->pLoadData.pObject;
          EnterCriticalSection(&pObject->ResourceLock.cs);
        }
        p_Exports = &pObject->Exports;
        if ( !pObject->Exports.mHash.pTable )
          goto LABEL_35;
        v13 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64) & p_Exports->mHash.pTable->SizeMask;
        v14 = v13;
        v15 = (__int64 *)(&p_Exports->mHash.pTable[2 * v13 + 1].EntryCount + v13);
        if ( *v15 == -2 || v15[1] != v13 )
          goto LABEL_35;
        while ( v15[1] != v13
             || Scaleform::String::CompareNoCase(
                  (const char *)((v15[2] & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  (const char *)((v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
        {
          v14 = *v15;
          if ( *v15 == -1 )
            goto LABEL_35;
          v15 = (__int64 *)(&p_Exports->mHash.pTable[2 * v14 + 1].EntryCount + v14);
        }
        if ( v14 >= 0
          && pObject != (Scaleform::GFx::MovieDataDef::LoadTaskData *)-384i64
          && (pTable = p_Exports->mHash.pTable) != 0i64
          && v14 <= (signed __int64)pTable->SizeMask )
        {
          v17 = &pTable[2].SizeMask + 5 * v14;
          if ( phandle.HType == RH_Pointer && phandle.pResource )
            _InterlockedExchangeAdd(&phandle.pResource->RefCount.Value, 1u);
          if ( !*(_DWORD *)v17 )
          {
            v18 = v17[1];
            if ( v18 )
            {
              if ( !_InterlockedDecrement((volatile signed __int32 *)(v18 + 8)) )
              {
                v19 = *(_QWORD *)(v18 + 16);
                if ( v19 )
                {
                  (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v19 + 8i64))(v19, v18);
                  *(_QWORD *)(v18 + 16) = 0i64;
                }
                (**(void (__fastcall ***)(__int64, __int64))v18)(v18, 1i64);
              }
            }
          }
          *(_DWORD *)v17 = phandle.HType;
          v17[1] = (unsigned __int64)phandle.pResource;
        }
        else
        {
LABEL_35:
          key.pFirst = &v28;
          key.pSecond = &phandle;
          v20 = Scaleform::String::BernsteinHashFunctionCIS(
                  (const void *)((v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  *(_QWORD *)(v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                  0x1505ui64);
          Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
            &pObject->Exports.mHash,
            &pObject->Exports,
            &key,
            v20);
        }
        if ( !p_Exports->mHash.pTable )
          goto LABEL_44;
        v21 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64) & p_Exports->mHash.pTable->SizeMask;
        v22 = v21;
        v23 = (__int64 *)(&p_Exports->mHash.pTable[2 * v21 + 1].EntryCount + v21);
        if ( *v23 == -2 || v23[1] != v21 )
          goto LABEL_44;
        while ( v23[1] != v21
             || Scaleform::String::CompareNoCase(
                  (const char *)((v23[2] & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  (const char *)((v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
        {
          v22 = *v23;
          if ( *v23 == -1 )
            goto LABEL_44;
          v23 = (__int64 *)(&p_Exports->mHash.pTable[2 * v22 + 1].EntryCount + v22);
        }
        if ( v22 < 0 )
        {
LABEL_44:
          p_Exports = 0i64;
          v22 = 0i64;
        }
        v24 = (Scaleform::StringLH *)(&p_Exports->mHash.pTable[2 * v22 + 2].EntryCount + v22);
        v31.pFirst = (Scaleform::GFx::ResourceId *)&v33;
        v31.pSecond = v24;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
          &pObject->InvExports.mHash,
          &pObject->InvExports,
          &v31);
        if ( v27 )
          LeaveCriticalSection(&v27->ResourceLock.cs);
        v7 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
        v8 = v34;
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
          v7,
          "SymbolClassLoader cant find Resource with id = %d, name = %s",
          v10,
          (const char *)((v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      }
      if ( phandle.HType == RH_Pointer )
      {
        pResource = phandle.pResource;
        if ( phandle.pResource )
        {
          if ( !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
          {
            pLib = pResource->pLib;
            if ( pLib )
            {
              pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
              pResource->pLib = 0i64;
            }
            pResource->vfptr->__vecDelDtor(pResource, 1u);
          }
        }
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v34 = --v8;
    }
    while ( v8 );
  }
}

// File Line: 136
// RVA: 0x8C7570
void __fastcall Scaleform::GFx::AS3::DoAbcLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdi
  __int64 Pos; // r8
  char v6; // r14
  unsigned int v7; // ebp
  __int64 ASInitActionTagsNum; // r9
  Scaleform::GFx::AS3::AbcDataBuffer *v9; // rbx
  Scaleform::GFx::AS3::DoAbc *v10; // rdi
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::StringDH v12; // [rsp+28h] [rbp-60h] BYREF
  char dest[80]; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::GFx::ResourceId spriteId; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::AbcDataBuffer *v15; // [rsp+98h] [rbp+10h]
  Scaleform::GFx::AS3::AbcDataBuffer *v16; // [rsp+A0h] [rbp+18h]
  Scaleform::GFx::AS3::AbcDataBuffer *v17; // [rsp+A8h] [rbp+20h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
  Pos = pAltStream->Stream.Pos;
  v6 = pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 4;
  Scaleform::StringDH::StringDH(&v12, p->pLoadData.pObject->pHeap);
  Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &v12);
  v7 = tagInfo->TagLength
     + tagInfo->TagDataOffset
     - (pAltStream->Stream.Pos
      + pAltStream->Stream.FilePos
      - pAltStream->Stream.DataSize);
  if ( (*(_QWORD *)(v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) == 0 )
  {
    ASInitActionTagsNum = p->ASInitActionTagsNum;
    if ( (_DWORD)ASInitActionTagsNum )
    {
      Scaleform::SFsprintf(dest, 0x14ui64, "%d", ASInitActionTagsNum);
      Scaleform::String::operator=(&v12, dest);
    }
  }
  v9 = (Scaleform::GFx::AS3::AbcDataBuffer *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               v7 + 47i64,
                                               0i64);
  v15 = v9;
  v16 = v9;
  if ( v9 )
  {
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
    v9->RefCount = 1;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,263>::`vftable;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS3::AbcDataBuffer,263>::`vftable;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::AbcDataBuffer::`vftable;
    Scaleform::String::String(&v9->Name, &v12);
    v9->DataSize = v7;
    v9->Flags = v6;
    Scaleform::StringLH::StringLH(&v9->FileName);
  }
  else
  {
    v9 = 0i64;
  }
  v17 = v9;
  Scaleform::String::operator=(
    &v9->FileName,
    (const char *)((p->pDataDef_Unsafe->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  if ( Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, v9->Data, v9->DataSize) == v9->DataSize )
  {
    v10 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS3::DoAbc>(p);
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v9);
    pObject = (Scaleform::Render::RenderBuffer *)v10->pAbc.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    v10->pAbc.pObject = v9;
    Scaleform::GFx::LoadProcess::AddInitAction(p, (Scaleform::GFx::ResourceId)&spriteId, v10);
    ++p->ASInitActionTagsNum;
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      &pAltStream->Stream,
      "Cant read completely ABCData at offset %d",
      (unsigned int)tagInfo->TagOffset);
  }
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 200
// RVA: 0x8945C0
void __fastcall Scaleform::GFx::AS3Support::AS3Support(Scaleform::GFx::AS3Support *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = State_UserData|0x20;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASSupport::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3Support::`vftable;
  qword_1420AFDC0 = (__int64)Scaleform::GFx::AS3::SymbolClassLoader;
  qword_1420AFDF0 = (__int64)Scaleform::GFx::AS3::DoAbcLoader;
}

// File Line: 206
// RVA: 0x8C0F60
Scaleform::GFx::MovieImpl *__fastcall Scaleform::GFx::AS3Support::CreateMovie(
        Scaleform::GFx::AS3Support *this,
        Scaleform::GFx::Resource *memContext)
{
  Scaleform::RefCountImplCoreVtbl *pLib; // rsi
  Scaleform::GFx::MovieImpl *v5; // rax
  Scaleform::Render::RenderBuffer *v6; // rbx
  Scaleform::GFx::MovieImpl *v7; // rax
  Scaleform::GFx::MovieImpl *v8; // rdi
  Scaleform::GFx::AS3::MovieRoot *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rax

  pLib = (Scaleform::RefCountImplCoreVtbl *)memContext->pLib;
  v5 = (Scaleform::GFx::MovieImpl *)(*((__int64 (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, __int64, _QWORD))pLib->__vecDelDtor
                                     + 10))(
                                      pLib,
                                      21648i64,
                                      0i64);
  v6 = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::MovieImpl::MovieImpl(v5, (Scaleform::MemoryHeap *)pLib);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = (Scaleform::GFx::AS3::MovieRoot *)(*((__int64 (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, __int64, _QWORD))pLib->__vecDelDtor
                                          + 10))(
                                           pLib,
                                           2312i64,
                                           0i64);
  if ( v9 )
  {
    Scaleform::GFx::AS3::MovieRoot::MovieRoot(v9, memContext, v8, (Scaleform::GFx::Resource *)this);
    v6 = v10;
  }
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  return v8;
}

// File Line: 229
// RVA: 0x8C0C70
Scaleform::GFx::MemoryContext *__fastcall Scaleform::GFx::AS3Support::CreateMemoryContext(
        Scaleform::GFx::AS3Support *this,
        const char *heapName,
        Scaleform::GFx::MemoryParams *memParams,
        bool debugHeap)
{
  __int64 InitialDynamicLimit; // rax
  Scaleform::MemoryHeap *v6; // rdi
  Scaleform::GFx::AS3::MemoryContextImpl *v7; // rax
  __int64 v8; // rbp
  __int64 v9; // rax
  __int64 v10; // rbx
  Scaleform::GFx::AS3::ASRefCountCollector *v11; // rax
  Scaleform::GFx::AS3::ASRefCountCollector *v12; // rax
  Scaleform::GFx::AS3::ASRefCountCollector *v13; // r14
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::GFx::ASStringManager *v15; // rax
  __int64 v16; // rax
  Scaleform::Render::RenderBuffer *v17; // rcx
  __m128i v19[2]; // [rsp+40h] [rbp-58h] BYREF
  __int128 v20; // [rsp+60h] [rbp-38h]
  __int128 v21; // [rsp+70h] [rbp-28h]

  v19[0] = *(__m128i *)&memParams->Desc.Flags;
  v19[1] = *(__m128i *)&memParams->Desc.Granularity;
  v20 = *(_OWORD *)&memParams->Desc.Threshold;
  v21 = *(_OWORD *)&memParams->Desc.HeapId;
  v19[0].m128i_i32[0] = (debugHeap ? 0x1000 : 0) | 3 | _mm_cvtsi128_si32(v19[0]);
  *(_QWORD *)&v21 = 3i64;
  InitialDynamicLimit = memParams->InitialDynamicLimit;
  if ( (_DWORD)InitialDynamicLimit == -1 )
    InitialDynamicLimit = 0x20000i64;
  *((_QWORD *)&v20 + 1) = InitialDynamicLimit;
  v6 = (Scaleform::MemoryHeap *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, const char *, __m128i *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
                                  Scaleform::Memory::pGlobalHeap,
                                  heapName,
                                  v19);
  Scaleform::MemoryHeap::AssignToCurrentThread(v6);
  v7 = (Scaleform::GFx::AS3::MemoryContextImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v6->vfptr->Alloc)(
                                                   v6,
                                                   104i64);
  v8 = 0i64;
  if ( v7 )
  {
    Scaleform::GFx::AS3::MemoryContextImpl::MemoryContextImpl(v7);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  *(_QWORD *)(v10 + 16) = v6;
  v11 = (Scaleform::GFx::AS3::ASRefCountCollector *)v6->vfptr->Alloc(v6, 232ui64, 0i64);
  if ( v11 )
  {
    Scaleform::GFx::AS3::ASRefCountCollector::ASRefCountCollector(v11);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  v14 = *(Scaleform::Render::RenderBuffer **)(v10 + 32);
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  *(_QWORD *)(v10 + 32) = v13;
  Scaleform::GFx::AS3::ASRefCountCollector::SetParams(
    v13,
    memParams->FramesBetweenCollections,
    memParams->MaxCollectionRoots,
    memParams->RunsToUpgradeGen,
    memParams->RunsToCollectYoung,
    memParams->RunsToCollectOld);
  v15 = (Scaleform::GFx::ASStringManager *)v6->vfptr->Alloc(v6, 160ui64, 0i64);
  if ( v15 )
  {
    Scaleform::GFx::ASStringManager::ASStringManager(v15, v6);
    v8 = v16;
  }
  v17 = *(Scaleform::Render::RenderBuffer **)(v10 + 24);
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  *(_QWORD *)(v10 + 24) = v8;
  *(_QWORD *)(v10 + 72) = memParams->Desc.Limit;
  *(float *)(v10 + 96) = memParams->HeapLimitMultiplier;
  v6->vfptr->SetLimitHandler(v6, (Scaleform::MemoryHeap::LimitHandler *)(v10 + 48));
  Scaleform::MemoryHeap::ReleaseOnFree((ANTLR3_COMMON_TOKEN_struct *)v6, v10);
  return (Scaleform::GFx::MemoryContext *)v10;
}

// File Line: 273
// RVA: 0x8BED30
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::AS3Support::CreateCharacterInstance(
        Scaleform::GFx::AS3Support *this,
        Scaleform::GFx::MovieImpl *proot,
        Scaleform::GFx::CharacterCreateInfo *ccinfo,
        Scaleform::GFx::InteractiveObject *pparent,
        unsigned int *rid,
        unsigned int type)
{
  Scaleform::GFx::CharacterDef::CharacterDefType v9; // eax
  Scaleform::GFx::AS3::ShapeObject *v10; // rax
  Scaleform::GFx::DisplayObjectBase *v11; // rax
  Scaleform::GFx::DisplayObjectBase *v12; // rbx
  Scaleform::GFx::DisplayObjectBase *result; // rax
  char *v14; // rsi
  Scaleform::GFx::Sprite *v15; // rax
  Scaleform::GFx::Sprite *v16; // rbx
  char *v17; // rsi
  Scaleform::GFx::Sprite *v18; // rax
  Scaleform::GFx::Sprite *v19; // rbx
  char *v20; // rsi
  Scaleform::GFx::Button *v21; // rax
  Scaleform::GFx::Button *v22; // rbx
  char *v23; // rsi
  Scaleform::GFx::TextField *v24; // rax
  Scaleform::GFx::TextField *v25; // rbx
  char *v26; // rsi
  Scaleform::GFx::StaticTextCharacter *v27; // rax
  Scaleform::GFx::StaticTextCharacter *v28; // rbx
  Scaleform::GFx::AS3::AvmBitmap *v29; // rax
  Scaleform::GFx::DisplayObjectBase *v30; // rax
  Scaleform::GFx::DisplayObjectBase *v31; // rbx
  Scaleform::GFx::ResourceId v32[2]; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::ResourceId id; // [rsp+48h] [rbp-28h] BYREF
  __int64 v34; // [rsp+50h] [rbp-20h]
  char *v35; // [rsp+58h] [rbp-18h]
  Scaleform::MemoryHeap *pHeap; // [rsp+60h] [rbp-10h]

  v34 = -2i64;
  v9 = type;
  if ( !type )
    v9 = ((unsigned int (__fastcall *)(Scaleform::GFx::CharacterDef *))ccinfo->pCharDef->vfptr[1].__vecDelDtor)(ccinfo->pCharDef);
  switch ( v9 )
  {
    case F5_1Pt2_512:
      *(_QWORD *)&v32[0].Id = proot->pHeap;
      v10 = (Scaleform::GFx::AS3::ShapeObject *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS3Support *, __int64, _QWORD))(**(_QWORD **)&v32[0].Id + 80i64))(
                                                  this,
                                                  216i64,
                                                  0i64);
      v35 = (char *)v10;
      if ( v10 )
      {
        type = *rid;
        Scaleform::GFx::AS3::ShapeObject::ShapeObject(
          v10,
          (Scaleform::GFx::ShapeBaseCharacterDef *)ccinfo->pCharDef,
          proot->pASMovieRoot.pObject,
          pparent,
          &type);
        v12 = v11;
      }
      else
      {
        v12 = 0i64;
      }
      result = v12;
      break;
    case F3_2Pt88_512:
      v14 = (char *)proot->pHeap->vfptr->Alloc(proot->pHeap, 432i64, 0i64);
      v35 = v14;
      pHeap = (Scaleform::MemoryHeap *)v14;
      if ( v14 )
      {
        v32[0].Id = *rid;
        Scaleform::GFx::Sprite::Sprite(
          (Scaleform::GFx::Sprite *)v14,
          (Scaleform::GFx::TimelineDef *)ccinfo->pCharDef,
          ccinfo->pBindDefImpl,
          proot->pASMovieRoot.pObject,
          pparent,
          v32,
          0);
        v16 = v15;
      }
      else
      {
        v16 = 0i64;
      }
      pHeap = (Scaleform::MemoryHeap *)(v14 + 320);
      if ( v14 != (char *)-320i64 )
        Scaleform::GFx::AS3::AvmMovieClip::AvmMovieClip((Scaleform::GFx::AS3::AvmMovieClip *)(v14 + 320), v16);
      result = v16;
      break;
    case F3_20Pt8_512:
      v23 = (char *)proot->pHeap->vfptr->Alloc(proot->pHeap, 392i64, 0i64);
      pHeap = (Scaleform::MemoryHeap *)v23;
      v35 = v23;
      if ( v23 )
      {
        v32[0].Id = *rid;
        Scaleform::GFx::TextField::TextField(
          (Scaleform::GFx::TextField *)v23,
          (Scaleform::GFx::TextFieldDef *)ccinfo->pCharDef,
          ccinfo->pBindDefImpl,
          proot->pASMovieRoot.pObject,
          pparent,
          (Scaleform::MemoryHeap *)v32);
        v25 = v24;
      }
      else
      {
        v25 = 0i64;
      }
      v35 = v23 + 312;
      if ( v23 != (char *)-312i64 )
        Scaleform::GFx::AS3::AvmTextField::AvmTextField((Scaleform::GFx::AS3::AvmTextField *)(v23 + 312), v25);
      result = v25;
      break;
    case F3_720_512:
      v26 = (char *)proot->pHeap->vfptr->Alloc(proot->pHeap, 456i64, 0i64);
      pHeap = (Scaleform::MemoryHeap *)v26;
      v35 = v26;
      if ( v26 )
      {
        v32[0].Id = *rid;
        Scaleform::GFx::StaticTextCharacter::StaticTextCharacter(
          (Scaleform::GFx::StaticTextCharacter *)v26,
          (Scaleform::GFx::StaticTextDef *)ccinfo->pCharDef,
          ccinfo->pBindDefImpl,
          proot->pASMovieRoot.pObject);
        v28 = v27;
      }
      else
      {
        v28 = 0i64;
      }
      v35 = v26 + 400;
      if ( v26 != (char *)-400i64 )
        Scaleform::GFx::AS3::AvmStaticText::AvmStaticText((Scaleform::GFx::AS3::AvmStaticText *)(v26 + 400), v28);
      result = v28;
      break;
    case F5_360_512:
      v20 = (char *)proot->pHeap->vfptr->Alloc(proot->pHeap, 448i64, 0i64);
      pHeap = (Scaleform::MemoryHeap *)v20;
      v35 = v20;
      if ( v20 )
      {
        v32[0].Id = *rid;
        Scaleform::GFx::Button::Button(
          (Scaleform::GFx::Button *)v20,
          (Scaleform::GFx::ButtonDef *)ccinfo->pCharDef,
          ccinfo->pBindDefImpl,
          proot->pASMovieRoot.pObject,
          pparent,
          v32);
        v22 = v21;
      }
      else
      {
        v22 = 0i64;
      }
      v35 = v20 + 368;
      if ( v20 != (char *)-368i64 )
        Scaleform::GFx::AS3::AvmButton::AvmButton((Scaleform::GFx::AS3::AvmButton *)(v20 + 368), v22);
      result = v22;
      break;
    case F5_320_1024:
      pHeap = proot->pHeap;
      v29 = (Scaleform::GFx::AS3::AvmBitmap *)pHeap->vfptr->Alloc((Scaleform::MemoryHeap *)this, 216ui64, 0i64);
      v35 = (char *)v29;
      if ( v29 )
      {
        id.Id = *rid;
        Scaleform::GFx::AS3::AvmBitmap::AvmBitmap(v29, proot->pASMovieRoot.pObject, ccinfo, pparent, &id);
        v31 = v30;
      }
      else
      {
        v31 = 0i64;
      }
      result = v31;
      break;
    case F5_180_512:
      v17 = (char *)proot->pHeap->vfptr->Alloc(proot->pHeap, 432i64, 0i64);
      pHeap = (Scaleform::MemoryHeap *)v17;
      v35 = v17;
      if ( v17 )
      {
        v32[0].Id = *rid;
        Scaleform::GFx::Sprite::Sprite(
          (Scaleform::GFx::Sprite *)v17,
          (Scaleform::GFx::TimelineDef *)ccinfo->pCharDef,
          ccinfo->pBindDefImpl,
          proot->pASMovieRoot.pObject,
          pparent,
          v32,
          0);
        v19 = v18;
      }
      else
      {
        v19 = 0i64;
      }
      v35 = v17 + 320;
      if ( v17 != (char *)-320i64 )
        Scaleform::GFx::AS3::AvmSprite::AvmSprite((Scaleform::GFx::AS3::AvmSprite *)(v17 + 320), v19);
      result = v19;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 374
// RVA: 0x8B5CB0
Scaleform::GFx::PlaceObject2Tag *__fastcall Scaleform::GFx::AS3Support::AllocPlaceObject2Tag(
        Scaleform::GFx::AS3Support *this,
        Scaleform::GFx::LoadProcess *p,
        unsigned __int64 dataSz,
        char __formal)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject2Tag>(p, dataSz);
}

// File Line: 379
// RVA: 0x8B5CD0
Scaleform::GFx::PlaceObject3Tag *__fastcall Scaleform::GFx::AS3Support::AllocPlaceObject3Tag(
        Scaleform::GFx::AS3Support *this,
        Scaleform::GFx::LoadProcess *p,
        unsigned __int64 dataSz)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject3Tag>(p, dataSz);
}

// File Line: 384
// RVA: 0x8B5D10
Scaleform::GFx::RemoveObjectTag *__fastcall Scaleform::GFx::AS3Support::AllocRemoveObjectTag(
        Scaleform::GFx::AS3Support *this,
        Scaleform::GFx::LoadProcess *p)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::RemoveObjectTag>(p);
}

// File Line: 389
// RVA: 0x8B5CF0
Scaleform::GFx::RemoveObject2Tag *__fastcall Scaleform::GFx::AS3Support::AllocRemoveObject2Tag(
        Scaleform::GFx::AS3Support *this,
        Scaleform::GFx::LoadProcess *p)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::RemoveObject2Tag>(p);
}

