// File Line: 56
// RVA: 0x8C92A0
void __fastcall Scaleform::GFx::AS3::DoAbc::Execute(Scaleform::GFx::AS3::DoAbc *this, Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::DisplayObjContainer *v2; // rdi
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // rsi
  Scaleform::GFx::AS3::AbcDataBuffer *v4; // rbx
  Scaleform::GFx::AS3::MovieRoot *v5; // rax
  Scaleform::Log *v6; // rbx
  __int64 v7; // rdi
  Scaleform::Log *v8; // rbx
  __int64 v9; // rax
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+40h] [rbp+8h]

  v2 = m;
  v3 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset);
  v4 = this->pAbc.pObject;
  v5 = (Scaleform::GFx::AS3::MovieRoot *)Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Root(v3);
  if ( !(unsigned __int8)Scaleform::GFx::AS3::MovieRoot::ExecuteAbc(v5, v4, v2) )
  {
    v6 = Scaleform::GFx::StateBag::GetLog(
           (Scaleform::GFx::StateBag *)&v3->pDispObj->pASRoot->pMovieImpl->vfptr,
           &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v6 )
    {
      v7 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v2->vfptr[66].__vecDelDtor)(v2);
      v8 = Scaleform::GFx::StateBag::GetLog(
             (Scaleform::GFx::StateBag *)&v3->pDispObj->pASRoot->pMovieImpl->vfptr,
             &result)->pObject;
      v9 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 96i64))(v7);
      Scaleform::Log::LogError(v8, "Can't execute ABC from %s", v9);
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    }
  }
}

// File Line: 71
// RVA: 0x8CB180
const char *__fastcall UFG::SimComponent::GetDebugTypeName(UFG::SimComponent *this)
{
  return (const char *)((__int64 (*)(void))this->vfptr[1].__vecDelDtor)();
}

// File Line: 93
// RVA: 0x912820
void __fastcall Scaleform::GFx::AS3::SymbolClassLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // r12
  Scaleform::GFx::Stream *v3; // r15
  __int64 v4; // r9
  unsigned __int16 v5; // r8
  __int64 v6; // rbx
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *v7; // r14
  __int64 v8; // rsi
  __int64 v9; // r8
  unsigned __int16 v10; // di
  Scaleform::GFx::MovieDataDef::LoadTaskData *v11; // r13
  signed __int64 v12; // rsi
  unsigned __int64 v13; // r14
  signed __int64 v14; // rbx
  signed __int64 *v15; // rdi
  __int64 v16; // rcx
  signed __int64 v17; // rdi
  __int64 v18; // rbx
  __int64 v19; // rcx
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // r14
  signed __int64 v22; // rbx
  signed __int64 *v23; // rdi
  Scaleform::StringLH *v24; // rdx
  Scaleform::GFx::Resource *v25; // rbx
  Scaleform::GFx::ResourceLibBase *v26; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v27; // [rsp+20h] [rbp-50h]
  signed __int64 v28; // [rsp+28h] [rbp-48h]
  Scaleform::StringDH v29; // [rsp+30h] [rbp-40h]
  Scaleform::GFx::ResourceHandle phandle; // [rsp+40h] [rbp-30h]
  Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+50h] [rbp-20h]
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef v32; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::ResourceId rid; // [rsp+B0h] [rbp+40h]
  int v34; // [rsp+C0h] [rbp+50h]
  __int64 v35; // [rsp+C8h] [rbp+58h]

  v28 = -2i64;
  v2 = p;
  v3 = p->pAltStream;
  if ( !v3 )
    v3 = &p->ProcessInfo.Stream;
  v3->UnusedBits = 0;
  if ( (signed int)(v3->DataSize - v3->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 2);
  v4 = v3->Pos;
  v5 = (unsigned __int8)v3->pBuffer[v4] | (unsigned __int16)((unsigned __int8)v3->pBuffer[(unsigned int)(v4 + 1)] << 8);
  v3->Pos = v4 + 2;
  v6 = v5;
  v7 = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
    "  SymbolClassLoader: num = %d\n");
  if ( (_DWORD)v6 )
  {
    v8 = (unsigned int)v6;
    v35 = v6;
    do
    {
      v3->UnusedBits = 0;
      if ( (signed int)(v3->DataSize - v3->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v3, 2);
      v9 = v3->Pos;
      v10 = (unsigned __int8)v3->pBuffer[v9] | (unsigned __int16)((unsigned __int8)v3->pBuffer[(unsigned int)(v9 + 1)] << 8);
      v3->Pos = v9 + 2;
      Scaleform::StringDH::StringDH(&v29, v2->pLoadData.pObject->pHeap);
      Scaleform::GFx::Stream::ReadString(v3, (Scaleform::String *)&v29.0);
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(v7, "       id = %d, symbol = '%s'\n");
      phandle.HType = 0;
      phandle.pResource = 0i64;
      if ( !v10
        || (rid.Id = v10,
            (unsigned __int8)Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                               v2->pLoadData.pObject,
                               &phandle,
                               (__int64)&rid)) )
      {
        v34 = v10;
        v11 = v2->pLoadData.pObject;
        v27 = 0i64;
        if ( v11->LoadState < 2 )
        {
          v27 = v2->pLoadData.pObject;
          EnterCriticalSection(&v11->ResourceLock.cs);
        }
        v12 = (signed __int64)&v11->Exports;
        if ( !v11->Exports.mHash.pTable )
          goto LABEL_35;
        v13 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64) & *(_QWORD *)(*(_QWORD *)v12 + 8i64);
        v14 = v13;
        v15 = (signed __int64 *)(*(_QWORD *)v12 + 8 * (v13 + 4 * v13 + 2));
        if ( *v15 == -2 || v15[1] != v13 )
          goto LABEL_35;
        while ( v15[1] != v13
             || Scaleform::String::CompareNoCase(
                  (const char *)((v15[2] & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  (const char *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
        {
          v14 = *v15;
          if ( *v15 == -1 )
            goto LABEL_35;
          v15 = (signed __int64 *)(*(_QWORD *)v12 + 8 * (v14 + 4 * v14 + 2));
        }
        if ( v14 >= 0
          && v11 != (Scaleform::GFx::MovieDataDef::LoadTaskData *)-384i64
          && (v16 = *(_QWORD *)v12) != 0
          && v14 <= *(_QWORD *)(v16 + 8) )
        {
          v17 = v16 + 40 * (v14 + 1);
          if ( phandle.HType == RH_Pointer && phandle.pResource )
            _InterlockedExchangeAdd(&phandle.pResource->RefCount.Value, 1u);
          if ( !*(_DWORD *)v17 )
          {
            v18 = *(_QWORD *)(v17 + 8);
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
                (**(void (__fastcall ***)(__int64, signed __int64))v18)(v18, 1i64);
              }
            }
          }
          *(Scaleform::GFx::ResourceHandle *)v17 = phandle;
        }
        else
        {
LABEL_35:
          key.pFirst = (Scaleform::String *)&v29;
          key.pSecond = &phandle;
          v20 = Scaleform::String::BernsteinHashFunctionCIS(
                  (const void *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  *(_QWORD *)(v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                  0x1505ui64);
          Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
            (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v11->Exports.mHash.pTable,
            &v11->Exports,
            &key,
            v20);
        }
        if ( !*(_QWORD *)v12 )
          goto LABEL_44;
        v21 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64) & *(_QWORD *)(*(_QWORD *)v12 + 8i64);
        v22 = v21;
        v23 = (signed __int64 *)(*(_QWORD *)v12 + 8 * (v21 + 4 * v21 + 2));
        if ( *v23 == -2 || v23[1] != v21 )
          goto LABEL_44;
        while ( v23[1] != v21
             || Scaleform::String::CompareNoCase(
                  (const char *)((v23[2] & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  (const char *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
        {
          v22 = *v23;
          if ( *v23 == -1 )
            goto LABEL_44;
          v23 = (signed __int64 *)(*(_QWORD *)v12 + 8 * (v22 + 4 * v22 + 2));
        }
        if ( v22 < 0 )
        {
LABEL_44:
          v12 = 0i64;
          v22 = 0i64;
        }
        v24 = (Scaleform::StringLH *)(*(_QWORD *)v12 + 8 * (v22 + 4 * (v22 + 1)));
        v32.pFirst = (Scaleform::GFx::ResourceId *)&v34;
        v32.pSecond = v24;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF> > *)&v11->InvExports.mHash.pTable,
          &v11->InvExports,
          &v32);
        if ( v27 )
          LeaveCriticalSection(&v27->ResourceLock.cs);
        v7 = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr;
        v8 = v35;
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
          (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)v7,
          "SymbolClassLoader can't find Resource with id = %d, name = '%s'",
          v10,
          (v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
          v27,
          v28);
      }
      if ( phandle.HType == RH_Pointer )
      {
        v25 = phandle.pResource;
        if ( phandle.pResource )
        {
          if ( !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
          {
            v26 = v25->pLib;
            if ( v26 )
            {
              v26->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v26->vfptr, (unsigned int)v25);
              v25->pLib = 0i64;
            }
            v25->vfptr->__vecDelDtor(v25, 1u);
          }
        }
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v35 = --v8;
    }
    while ( v8 );
  }
}

// File Line: 136
// RVA: 0x8C7570
void __fastcall Scaleform::GFx::AS3::DoAbcLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // r15
  Scaleform::GFx::LoadProcess *v3; // rsi
  Scaleform::GFx::Stream *v4; // rdi
  __int64 v5; // r8
  int v6; // er14
  unsigned int v7; // ebp
  _QWORD *v8; // rbx
  Scaleform::GFx::AS3::DoAbc *v9; // rdi
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::StringDH v11; // [rsp+28h] [rbp-60h]
  char dest; // [rsp+38h] [rbp-50h]
  Scaleform::GFx::ResourceId spriteId; // [rsp+90h] [rbp+8h]
  void *v14; // [rsp+98h] [rbp+10h]
  void *v15; // [rsp+A0h] [rbp+18h]
  void *v16; // [rsp+A8h] [rbp+20h]

  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 4);
  v5 = v4->Pos;
  v6 = (unsigned __int8)v4->pBuffer[v5] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 1)] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 2)] | ((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 3)] << 8)) << 8)) << 8);
  v4->Pos = v5 + 4;
  Scaleform::StringDH::StringDH(&v11, v3->pLoadData.pObject->pHeap);
  Scaleform::GFx::Stream::ReadString(v4, (Scaleform::String *)&v11.0);
  v7 = v2->TagLength + v2->TagDataOffset - (v4->Pos + v4->FilePos - v4->DataSize);
  if ( !(*(_QWORD *)(v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) && v3->ASInitActionTagsNum )
  {
    Scaleform::SFsprintf(&dest, 0x14ui64, "%d");
    Scaleform::String::operator=((Scaleform::String *)&v11.0, &dest);
  }
  v8 = (_QWORD *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v7 + 47i64, 0i64);
  v14 = v8;
  v15 = v8;
  if ( v8 )
  {
    *v8 = &Scaleform::RefCountImplCore::`vftable';
    *((_DWORD *)v8 + 2) = 1;
    *v8 = &Scaleform::RefCountImpl::`vftable';
    *v8 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,263>::`vftable';
    *v8 = &Scaleform::RefCountBase<Scaleform::GFx::AS3::AbcDataBuffer,263>::`vftable';
    *v8 = &Scaleform::GFx::AS3::AbcDataBuffer::`vftable';
    Scaleform::String::String((Scaleform::String *)v8 + 2, (Scaleform::String *)&v11.0);
    *((_DWORD *)v8 + 6) = v7;
    *((_BYTE *)v8 + 28) = v6;
    Scaleform::StringLH::StringLH((Scaleform::StringLH *)v8 + 4);
  }
  else
  {
    v8 = 0i64;
  }
  v16 = v8;
  Scaleform::String::operator=(
    (Scaleform::String *)v8 + 4,
    (const char *)((v3->pDataDef_Unsafe->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  if ( Scaleform::GFx::Stream::ReadToBuffer(v4, (char *)v8 + 40, *((_DWORD *)v8 + 6)) == *((_DWORD *)v8 + 6) )
  {
    v9 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS3::DoAbc>(v3);
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v8);
    v10 = (Scaleform::Render::RenderBuffer *)v9->pAbc.pObject;
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    v9->pAbc.pObject = (Scaleform::GFx::AS3::AbcDataBuffer *)v8;
    Scaleform::GFx::LoadProcess::AddInitAction(
      v3,
      (Scaleform::GFx::ResourceId)&spriteId,
      (Scaleform::GFx::ExecuteTag *)&v9->vfptr);
    ++v3->ASInitActionTagsNum;
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
      "Can't read completely ABCData at offset %d",
      (unsigned int)v2->TagOffset);
  }
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 200
// RVA: 0x8945C0
void __fastcall Scaleform::GFx::AS3Support::AS3Support(Scaleform::GFx::AS3Support *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable';
  this->SType = 39;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASSupport::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3Support::`vftable';
  qword_1420AFDC0 = (__int64)Scaleform::GFx::AS3::SymbolClassLoader;
  qword_1420AFDF0 = (__int64)Scaleform::GFx::AS3::DoAbcLoader;
}

// File Line: 206
// RVA: 0x8C0F60
Scaleform::GFx::MovieImpl *__fastcall Scaleform::GFx::AS3Support::CreateMovie(Scaleform::GFx::AS3Support *this, Scaleform::GFx::MemoryContext *memContext)
{
  Scaleform::GFx::AS3::MemoryContextImpl *v2; // rbp
  Scaleform::GFx::AS3Support *v3; // r14
  Scaleform::RefCountImplCoreVtbl *v4; // rsi
  Scaleform::GFx::MovieImpl *v5; // rax
  Scaleform::Render::RenderBuffer *v6; // rbx
  Scaleform::GFx::MovieImpl *v7; // rax
  Scaleform::GFx::MovieImpl *v8; // rdi
  Scaleform::GFx::AS3::MovieRoot *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rax

  v2 = (Scaleform::GFx::AS3::MemoryContextImpl *)memContext;
  v3 = this;
  v4 = memContext[1].vfptr;
  v5 = (Scaleform::GFx::MovieImpl *)(*((__int64 (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, signed __int64, _QWORD))v4->__vecDelDtor
                                     + 10))(
                                      v4,
                                      21648i64,
                                      0i64);
  v6 = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::MovieImpl::MovieImpl(v5, (Scaleform::MemoryHeap *)v4);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = (Scaleform::GFx::AS3::MovieRoot *)(*((__int64 (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, signed __int64, _QWORD))v4->__vecDelDtor
                                          + 10))(
                                           v4,
                                           2312i64,
                                           0i64);
  if ( v9 )
  {
    Scaleform::GFx::AS3::MovieRoot::MovieRoot(v9, v2, v8, (Scaleform::GFx::ASSupport *)&v3->vfptr);
    v6 = v10;
  }
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  return v8;
}

// File Line: 229
// RVA: 0x8C0C70
Scaleform::GFx::MemoryContext *__fastcall Scaleform::GFx::AS3Support::CreateMemoryContext(Scaleform::GFx::AS3Support *this, const char *heapName, Scaleform::GFx::MemoryParams *memParams, bool debugHeap)
{
  Scaleform::GFx::MemoryParams *v4; // rsi
  signed __int64 v5; // rax
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
  __m128i v19; // [rsp+40h] [rbp-58h]
  __int128 v20; // [rsp+50h] [rbp-48h]
  __int128 v21; // [rsp+60h] [rbp-38h]
  __int128 v22; // [rsp+70h] [rbp-28h]

  v4 = memParams;
  v19 = *(__m128i *)&memParams->Desc.Flags;
  v20 = *(_OWORD *)&memParams->Desc.Granularity;
  v21 = *(_OWORD *)&memParams->Desc.Threshold;
  v22 = *(_OWORD *)&memParams->Desc.HeapId;
  v19.m128i_i32[0] = (debugHeap != 0 ? 0x1000 : 0) | 3 | _mm_cvtsi128_si32(v19);
  *(_QWORD *)&v22 = 3i64;
  v5 = memParams->InitialDynamicLimit;
  if ( (_DWORD)v5 == -1 )
    v5 = 0x20000i64;
  *((_QWORD *)&v21 + 1) = v5;
  v6 = (Scaleform::MemoryHeap *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, const char *, __m128i *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
                                  Scaleform::Memory::pGlobalHeap,
                                  heapName,
                                  &v19);
  Scaleform::MemoryHeap::AssignToCurrentThread(v6);
  v7 = (Scaleform::GFx::AS3::MemoryContextImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v6->vfptr->Alloc)(
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
    v4->FramesBetweenCollections,
    v4->MaxCollectionRoots,
    v4->RunsToUpgradeGen,
    v4->RunsToCollectYoung,
    v4->RunsToCollectOld);
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
  *(_QWORD *)(v10 + 72) = v4->Desc.Limit;
  *(float *)(v10 + 96) = v4->HeapLimitMultiplier;
  v6->vfptr->SetLimitHandler(v6, (Scaleform::MemoryHeap::LimitHandler *)(v10 + 48));
  Scaleform::MemoryHeap::ReleaseOnFree((ANTLR3_COMMON_TOKEN_struct *)v6, v10);
  return (Scaleform::GFx::MemoryContext *)v10;
}

// File Line: 273
// RVA: 0x8BED30
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::AS3Support::CreateCharacterInstance(Scaleform::GFx::AS3Support *this, Scaleform::GFx::MovieImpl *proot, Scaleform::GFx::CharacterCreateInfo *ccinfo, Scaleform::GFx::InteractiveObject *pparent, __int64 rid, Scaleform::GFx::CharacterDef::CharacterDefType type)
{
  Scaleform::GFx::InteractiveObject *v6; // r14
  Scaleform::GFx::CharacterCreateInfo *v7; // rdi
  Scaleform::GFx::MovieImpl *v8; // rbx
  Scaleform::GFx::CharacterDef::CharacterDefType v9; // eax
  Scaleform::GFx::AS3::ShapeObject *v10; // rax
  Scaleform::GFx::DisplayObjectBase *v11; // rax
  Scaleform::GFx::DisplayObjectBase *v12; // rbx
  Scaleform::GFx::DisplayObjectBase *result; // rax
  __int64 v14; // rsi
  Scaleform::GFx::Sprite *v15; // rax
  Scaleform::GFx::Sprite *v16; // rbx
  __int64 v17; // rsi
  Scaleform::GFx::Sprite *v18; // rax
  Scaleform::GFx::Sprite *v19; // rbx
  __int64 v20; // rsi
  Scaleform::GFx::Button *v21; // rax
  Scaleform::GFx::Button *v22; // rbx
  __int64 v23; // rsi
  Scaleform::GFx::TextField *v24; // rax
  Scaleform::GFx::TextField *v25; // rbx
  __int64 v26; // rsi
  Scaleform::GFx::StaticTextCharacter *v27; // rax
  Scaleform::GFx::StaticTextCharacter *v28; // rbx
  Scaleform::GFx::AS3::AvmBitmap *v29; // rax
  Scaleform::GFx::DisplayObjectBase *v30; // rax
  Scaleform::GFx::DisplayObjectBase *v31; // rbx
  Scaleform::GFx::ResourceId v32[2]; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::ResourceId v33; // [rsp+48h] [rbp-28h]
  __int64 v34; // [rsp+50h] [rbp-20h]
  __int64 v35; // [rsp+58h] [rbp-18h]
  __int64 v36; // [rsp+60h] [rbp-10h]

  v34 = -2i64;
  v6 = pparent;
  v7 = ccinfo;
  v8 = proot;
  v9 = type;
  if ( type == Unknown )
    v9 = ((unsigned int (*)(void))ccinfo->pCharDef->vfptr[1].__vecDelDtor)();
  switch ( v9 )
  {
    case 1:
      *(_QWORD *)&v32[0].Id = v8->pHeap;
      v10 = (Scaleform::GFx::AS3::ShapeObject *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS3Support *, signed __int64, _QWORD))(**(_QWORD **)&v32[0].Id + 80i64))(
                                                  this,
                                                  216i64,
                                                  0i64);
      v35 = (__int64)v10;
      if ( v10 )
      {
        type = *(_DWORD *)rid;
        Scaleform::GFx::AS3::ShapeObject::ShapeObject(
          v10,
          v7->pCharDef,
          v8->pASMovieRoot.pObject,
          v6,
          (Scaleform::GFx::ResourceId)&type);
        v12 = v11;
      }
      else
      {
        v12 = 0i64;
      }
      result = v12;
      break;
    case 3:
      v14 = (__int64)v8->pHeap->vfptr->Alloc(v8->pHeap, 432ui64, 0i64);
      v35 = v14;
      v36 = v14;
      if ( v14 )
      {
        v32[0] = *(Scaleform::GFx::ResourceId *)rid;
        Scaleform::GFx::Sprite::Sprite(
          (Scaleform::GFx::Sprite *)v14,
          (Scaleform::GFx::TimelineDef *)v7->pCharDef,
          v7->pBindDefImpl,
          v8->pASMovieRoot.pObject,
          v6,
          (Scaleform::GFx::ResourceId)v32,
          0);
        v16 = v15;
      }
      else
      {
        v16 = 0i64;
      }
      v36 = v14 + 320;
      if ( v14 != -320 )
        Scaleform::GFx::AS3::AvmMovieClip::AvmMovieClip((Scaleform::GFx::AS3::AvmMovieClip *)(v14 + 320), v16);
      result = (Scaleform::GFx::DisplayObjectBase *)&v16->vfptr;
      break;
    case 4:
      v23 = (__int64)v8->pHeap->vfptr->Alloc(v8->pHeap, 392ui64, 0i64);
      v36 = v23;
      v35 = v23;
      if ( v23 )
      {
        v32[0] = *(Scaleform::GFx::ResourceId *)rid;
        Scaleform::GFx::TextField::TextField(
          (Scaleform::GFx::TextField *)v23,
          (Scaleform::GFx::TextFieldDef *)v7->pCharDef,
          v7->pBindDefImpl,
          v8->pASMovieRoot.pObject,
          v6,
          (Scaleform::GFx::ResourceId)v32);
        v25 = v24;
      }
      else
      {
        v25 = 0i64;
      }
      v35 = v23 + 312;
      if ( v23 != -312 )
        Scaleform::GFx::AS3::AvmTextField::AvmTextField((Scaleform::GFx::AS3::AvmTextField *)(v23 + 312), v25);
      result = (Scaleform::GFx::DisplayObjectBase *)&v25->vfptr;
      break;
    case 5:
      v26 = (__int64)v8->pHeap->vfptr->Alloc(v8->pHeap, 456ui64, 0i64);
      v36 = v26;
      v35 = v26;
      if ( v26 )
      {
        v32[0] = *(Scaleform::GFx::ResourceId *)rid;
        Scaleform::GFx::StaticTextCharacter::StaticTextCharacter(
          (Scaleform::GFx::StaticTextCharacter *)v26,
          (Scaleform::GFx::StaticTextDef *)v7->pCharDef,
          v7->pBindDefImpl,
          v8->pASMovieRoot.pObject);
        v28 = v27;
      }
      else
      {
        v28 = 0i64;
      }
      v35 = v26 + 400;
      if ( v26 != -400 )
        Scaleform::GFx::AS3::AvmStaticText::AvmStaticText((Scaleform::GFx::AS3::AvmStaticText *)(v26 + 400), v28);
      result = (Scaleform::GFx::DisplayObjectBase *)&v28->vfptr;
      break;
    case 6:
      v20 = (__int64)v8->pHeap->vfptr->Alloc(v8->pHeap, 448ui64, 0i64);
      v36 = v20;
      v35 = v20;
      if ( v20 )
      {
        v32[0] = *(Scaleform::GFx::ResourceId *)rid;
        Scaleform::GFx::Button::Button(
          (Scaleform::GFx::Button *)v20,
          (Scaleform::GFx::ButtonDef *)v7->pCharDef,
          v7->pBindDefImpl,
          v8->pASMovieRoot.pObject,
          v6,
          (Scaleform::GFx::ResourceId)v32);
        v22 = v21;
      }
      else
      {
        v22 = 0i64;
      }
      v35 = v20 + 368;
      if ( v20 != -368 )
        Scaleform::GFx::AS3::AvmButton::AvmButton((Scaleform::GFx::AS3::AvmButton *)(v20 + 368), v22);
      result = (Scaleform::GFx::DisplayObjectBase *)&v22->vfptr;
      break;
    case 8:
      v36 = (__int64)v8->pHeap;
      v29 = (Scaleform::GFx::AS3::AvmBitmap *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS3Support *, signed __int64, _QWORD))(*(_QWORD *)v36 + 80i64))(
                                                this,
                                                216i64,
                                                0i64);
      v35 = (__int64)v29;
      if ( v29 )
      {
        v33.Id = *(_DWORD *)rid;
        Scaleform::GFx::AS3::AvmBitmap::AvmBitmap(
          v29,
          v8->pASMovieRoot.pObject,
          v7,
          v6,
          (Scaleform::GFx::ResourceId)&v33);
        v31 = v30;
      }
      else
      {
        v31 = 0i64;
      }
      result = v31;
      break;
    case 9:
      v17 = (__int64)v8->pHeap->vfptr->Alloc(v8->pHeap, 432ui64, 0i64);
      v36 = v17;
      v35 = v17;
      if ( v17 )
      {
        v32[0] = *(Scaleform::GFx::ResourceId *)rid;
        Scaleform::GFx::Sprite::Sprite(
          (Scaleform::GFx::Sprite *)v17,
          (Scaleform::GFx::TimelineDef *)v7->pCharDef,
          v7->pBindDefImpl,
          v8->pASMovieRoot.pObject,
          v6,
          (Scaleform::GFx::ResourceId)v32,
          0);
        v19 = v18;
      }
      else
      {
        v19 = 0i64;
      }
      v35 = v17 + 320;
      if ( v17 != -320 )
        Scaleform::GFx::AS3::AvmSprite::AvmSprite((Scaleform::GFx::AS3::AvmSprite *)(v17 + 320), v19);
      result = (Scaleform::GFx::DisplayObjectBase *)&v19->vfptr;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 374
// RVA: 0x8B5CB0
Scaleform::GFx::PlaceObject2Tag *__fastcall Scaleform::GFx::AS3Support::AllocPlaceObject2Tag(Scaleform::GFx::AS3Support *this, Scaleform::GFx::LoadProcess *p, unsigned __int64 dataSz, char __formal)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject2Tag>(p, dataSz);
}

// File Line: 379
// RVA: 0x8B5CD0
Scaleform::GFx::PlaceObject3Tag *__fastcall Scaleform::GFx::AS3Support::AllocPlaceObject3Tag(Scaleform::GFx::AS3Support *this, Scaleform::GFx::LoadProcess *p, unsigned __int64 dataSz)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject3Tag>(p, dataSz);
}

// File Line: 384
// RVA: 0x8B5D10
Scaleform::GFx::RemoveObjectTag *__fastcall Scaleform::GFx::AS3Support::AllocRemoveObjectTag(Scaleform::GFx::AS3Support *this, Scaleform::GFx::LoadProcess *p)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::RemoveObjectTag>(p);
}

// File Line: 389
// RVA: 0x8B5CF0
Scaleform::GFx::RemoveObject2Tag *__fastcall Scaleform::GFx::AS3Support::AllocRemoveObject2Tag(Scaleform::GFx::AS3Support *this, Scaleform::GFx::LoadProcess *p)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::RemoveObject2Tag>(p);
}

