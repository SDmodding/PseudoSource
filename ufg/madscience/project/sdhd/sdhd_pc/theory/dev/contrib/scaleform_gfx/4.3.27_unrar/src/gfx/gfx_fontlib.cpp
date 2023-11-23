// File Line: 55
// RVA: 0x896930
void __fastcall Scaleform::GFx::FontLib::FontLib(Scaleform::GFx::FontLib *this)
{
  Scaleform::String *v2; // rax
  Scaleform::GFx::FontLibImpl *v3; // rbx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = 20;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontLib::`vftable;
  v2 = (Scaleform::String *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                              Scaleform::Memory::pGlobalHeap,
                              32i64);
  v3 = (Scaleform::GFx::FontLibImpl *)v2;
  if ( v2 )
  {
    v2->HeapTypeBits = 0i64;
    v2[1].HeapTypeBits = 0i64;
    v2[2].HeapTypeBits = 0i64;
    Scaleform::String::String(v2 + 3);
  }
  else
  {
    v3 = 0i64;
  }
  this->pImpl = v3;
  Scaleform::String::operator=(&v3->FileToSubstitute, "gfxfontlib.swf");
}

// File Line: 65
// RVA: 0x8B1070
void __fastcall Scaleform::GFx::FontLib::AddFontsFrom(
        Scaleform::GFx::FontLib *this,
        Scaleform::GFx::MovieDef *md,
        bool pin)
{
  Scaleform::GFx::MovieDefImpl *v5; // rdi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy> *pImpl; // rbx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v7; // rdx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceLibBase *v9; // rcx

  if ( this->pImpl && md )
  {
    v5 = *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)&md[3].RefCount.Value + 24i64);
    if ( v5 )
      _InterlockedExchangeAdd(&v5->RefCount.Value, 1u);
    pImpl = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy> *)this->pImpl;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      pImpl,
      pImpl,
      pImpl->Size + 1);
    v7 = &pImpl->Data[pImpl->Size - 1];
    if ( v7 )
    {
      if ( v5 )
        _InterlockedExchangeAdd(&v5->RefCount.Value, 1u);
      v7->pObject = v5;
    }
    if ( v5 && !_InterlockedDecrement(&v5->RefCount.Value) )
    {
      pLib = v5->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v5);
        v5->pLib = 0i64;
      }
      v5->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v5, 1u);
    }
    if ( pin )
    {
      v9 = md->pLib;
      if ( v9 )
        v9->vfptr[2].__vecDelDtor(v9, (unsigned int)md);
    }
  }
}

// File Line: 92
// RVA: 0x90AF90
void __fastcall Scaleform::GFx::FontLib::FontResult::SetResult(
        Scaleform::GFx::FontLib::FontResult *this,
        Scaleform::GFx::MovieDef *pmovieDef,
        Scaleform::GFx::FontResource *pfont)
{
  Scaleform::GFx::MovieDef *v6; // r14
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::FontResource *pFontResource; // r14
  Scaleform::GFx::ResourceLibBase *v9; // rcx

  if ( pmovieDef )
    _InterlockedExchangeAdd(&pmovieDef->RefCount.Value, 1u);
  if ( pfont )
    _InterlockedExchangeAdd(&pfont->RefCount.Value, 1u);
  v6 = this->pMovieDef;
  if ( this->pMovieDef && !_InterlockedDecrement(&v6->RefCount.Value) )
  {
    pLib = v6->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v6);
      v6->pLib = 0i64;
    }
    v6->Scaleform::GFx::Resource::vfptr->__vecDelDtor(v6, 1u);
  }
  pFontResource = this->pFontResource;
  if ( pFontResource && !_InterlockedDecrement(&pFontResource->RefCount.Value) )
  {
    v9 = pFontResource->pLib;
    if ( v9 )
    {
      v9->vfptr[1].__vecDelDtor(v9, (unsigned int)pFontResource);
      pFontResource->pLib = 0i64;
    }
    pFontResource->vfptr->__vecDelDtor(pFontResource, 1u);
  }
  this->pMovieDef = pmovieDef;
  this->pFontResource = pfont;
}

// File Line: 108
// RVA: 0x8A4BA0
void __fastcall Scaleform::GFx::FontLib::FontResult::~FontResult(Scaleform::GFx::FontLib::FontResult *this)
{
  Scaleform::GFx::MovieDef *pMovieDef; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::FontResource *pFontResource; // rdi
  Scaleform::GFx::ResourceLibBase *v5; // rcx

  pMovieDef = this->pMovieDef;
  if ( this->pMovieDef && !_InterlockedDecrement(&pMovieDef->RefCount.Value) )
  {
    pLib = pMovieDef->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pMovieDef);
      pMovieDef->pLib = 0i64;
    }
    pMovieDef->Scaleform::GFx::Resource::vfptr->__vecDelDtor(pMovieDef, 1u);
  }
  pFontResource = this->pFontResource;
  if ( pFontResource && !_InterlockedDecrement(&pFontResource->RefCount.Value) )
  {
    v5 = pFontResource->pLib;
    if ( v5 )
    {
      v5->vfptr[1].__vecDelDtor(v5, (unsigned int)pFontResource);
      pFontResource->pLib = 0i64;
    }
    pFontResource->vfptr->__vecDelDtor(pFontResource, 1u);
  }
}

// File Line: 124
// RVA: 0x8CBC00
char __fastcall Scaleform::GFx::FontLib::FindFont(
        Scaleform::GFx::FontLib *this,
        Scaleform::GFx::FontLib::FontResult *presult,
        const char *pfontname,
        __int16 fontFlags,
        Scaleform::GFx::MovieDef *puserDef,
        Scaleform::GFx::ResourceLibBase **pstates,
        Scaleform::GFx::ResourceWeakLib *pweakLib)
{
  __int64 v8; // r9
  Scaleform::GFx::MovieDataDef *pObject; // r13
  char v11; // r15
  Scaleform::GFx::MovieDefImpl *Movie_LoadState; // rbx
  __int64 v13; // r14
  Scaleform::GFx::FontLibImpl *pImpl; // rdx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v15; // rcx
  Scaleform::GFx::FontDataUseNode *volatile Value; // rbx
  int v17; // esi
  int v18; // ebp
  Scaleform::Render::Font *v19; // rcx
  const char *v20; // rax
  Scaleform::GFx::LoadStates *v21; // rax
  Scaleform::GFx::Resource *v22; // rax
  Scaleform::GFx::Resource *v23; // rsi
  Scaleform::Render::RenderBuffer *v24; // rcx
  Scaleform::GFx::LoaderImpl *v25; // rax
  Scaleform::GFx::Resource *v26; // rax
  Scaleform::GFx::Resource *v27; // rbp
  Scaleform::GFx::MovieDefBindStates *v28; // rax
  Scaleform::GFx::MovieDefBindStates *v29; // rax
  Scaleform::GFx::MovieDefBindStates *v30; // rsi
  Scaleform::GFx::LoadStates *v31; // rax
  Scaleform::GFx::Resource *v32; // rax
  Scaleform::GFx::Resource *v33; // r14
  unsigned int v34; // r8d
  Scaleform::GFx::ResourceBindData *v35; // rdx
  Scaleform::GFx::FontResource *v36; // rsi
  char v37; // bp
  Scaleform::GFx::Resource *v38; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceLibBase *v40; // rcx
  unsigned int index; // [rsp+20h] [rbp-88h]
  Scaleform::GFx::MovieDef *pmovieDef; // [rsp+28h] [rbp-80h]
  Scaleform::GFx::ResourceBindData pdata; // [rsp+58h] [rbp-50h] BYREF
  unsigned int v46; // [rsp+C8h] [rbp+20h]

  v8 = fontFlags & 0x313;
  v46 = v8;
  if ( !this->pImpl )
    return 0;
  index = 0;
  pObject = 0i64;
  v11 = 0;
  Movie_LoadState = 0i64;
  pmovieDef = 0i64;
  v13 = 0i64;
  pImpl = this->pImpl;
  if ( pImpl->FontMovies.Data.Size )
  {
    do
    {
      if ( v11 )
        goto LABEL_16;
      pObject = pImpl->FontMovies.Data.Data[v13].pObject;
      v15 = pObject->pData.pObject;
      if ( v15->LoadState <= LS_LoadingFrames )
      {
        Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(v15->pFrameUpdate.pObject);
        LOWORD(v8) = v46;
      }
      Value = pObject->pData.pObject->BindData.pFonts.Value;
      if ( Value )
      {
        v17 = v8 & 0x10 | ((v8 & 0x300) != 0 ? 0x300 : 0) | 3;
        v18 = v8 & 0x313;
        while ( 1 )
        {
          v19 = Value->pFontData.pObject;
          if ( (v19->Flags & v17) == v18 )
          {
            v20 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v19->vfptr[1].__vecDelDtor)(v19);
            if ( !Scaleform::String::CompareNoCase(v20, pfontname) )
              break;
          }
          Value = Value->pNext.Value;
          if ( !Value )
            goto LABEL_14;
        }
        index = Value->BindIndex;
        v11 = 1;
      }
LABEL_14:
      v13 = (unsigned int)(v13 + 1);
      pImpl = this->pImpl;
      v8 = v46;
    }
    while ( (unsigned int)v13 < pImpl->FontMovies.Data.Size );
    if ( v11 )
    {
LABEL_16:
      if ( puserDef )
      {
        v21 = (Scaleform::GFx::LoadStates *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, _QWORD, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              144i64,
                                              0i64,
                                              v8);
        if ( v21 )
        {
          Scaleform::GFx::LoadStates::LoadStates(
            v21,
            *(Scaleform::GFx::Resource **)&puserDef[1].RefCount.Value,
            pstates,
            (Scaleform::GFx::MovieDefBindStates *)puserDef[1].pLib);
          v23 = v22;
        }
        else
        {
          v23 = 0i64;
        }
        Movie_LoadState = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
                            v23,
                            pObject,
                            *(_DWORD *)(*(_QWORD *)&puserDef[3].RefCount.Value + 40i64) | 1u,
                            0i64);
        pmovieDef = Movie_LoadState;
        if ( v23 )
        {
          v24 = (Scaleform::Render::RenderBuffer *)v23;
LABEL_38:
          Scaleform::RefCountImpl::Release(v24);
          goto LABEL_39;
        }
        goto LABEL_39;
      }
      if ( pweakLib )
      {
        v25 = (Scaleform::GFx::LoaderImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              120i64);
        if ( v25 )
        {
          Scaleform::GFx::LoaderImpl::LoaderImpl(v25, (Scaleform::GFx::StateBag *)pstates, pweakLib->pStrongLib, 0);
          v27 = v26;
        }
        else
        {
          v27 = 0i64;
        }
        v28 = (Scaleform::GFx::MovieDefBindStates *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      80i64);
        if ( v28 )
        {
          Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(v28, (Scaleform::GFx::StateBag *)pstates);
          v30 = v29;
        }
        else
        {
          v30 = 0i64;
        }
        v31 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                              Scaleform::Memory::pGlobalHeap,
                                              144i64,
                                              0i64);
        if ( v31 )
        {
          Scaleform::GFx::LoadStates::LoadStates(v31, v27, pstates, v30);
          v33 = v32;
        }
        else
        {
          v33 = 0i64;
        }
        Movie_LoadState = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v33, pObject, 1u, 0i64);
        pmovieDef = Movie_LoadState;
        if ( v33 )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v33);
        if ( v30 )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v30);
        if ( v27 )
        {
          v24 = (Scaleform::Render::RenderBuffer *)v27;
          goto LABEL_38;
        }
LABEL_39:
        if ( !Movie_LoadState )
          goto LABEL_57;
        pdata.pResource.pObject = 0i64;
        pdata.pBinding = 0i64;
        if ( Movie_LoadState->pBindData.pObject->ResourceBinding.Frozen )
        {
          v34 = index;
          if ( index < Movie_LoadState->pBindData.pObject->ResourceBinding.ResourceCount )
          {
            v35 = &Movie_LoadState->pBindData.pObject->ResourceBinding.pResources[index];
            if ( v35->pResource.pObject )
              _InterlockedExchangeAdd(&v35->pResource.pObject->RefCount.Value, 1u);
            v36 = (Scaleform::GFx::FontResource *)v35->pResource.pObject;
            pdata = *v35;
            goto LABEL_47;
          }
        }
        else
        {
          v34 = index;
        }
        Scaleform::GFx::ResourceBinding::GetResourceData_Locked(
          &Movie_LoadState->pBindData.pObject->ResourceBinding,
          &pdata,
          v34);
        v36 = (Scaleform::GFx::FontResource *)pdata.pResource.pObject;
LABEL_47:
        Movie_LoadState = (Scaleform::GFx::MovieDefImpl *)pmovieDef;
        if ( v36 )
        {
          Scaleform::GFx::FontLib::FontResult::SetResult(presult, pmovieDef, v36);
          v37 = 1;
        }
        else
        {
          v37 = 0;
        }
        if ( v36 )
        {
          if ( !_InterlockedDecrement(&v36->RefCount.Value) )
          {
            v38 = pdata.pResource.pObject;
            pLib = pdata.pResource.pObject->pLib;
            if ( pLib )
            {
              pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pdata.pResource.pObject);
              v38->pLib = 0i64;
            }
            v38->vfptr->__vecDelDtor(v38, 1u);
          }
          Movie_LoadState = (Scaleform::GFx::MovieDefImpl *)pmovieDef;
        }
        goto LABEL_58;
      }
    }
    Movie_LoadState = 0i64;
  }
LABEL_57:
  v37 = 0;
LABEL_58:
  if ( Movie_LoadState && !_InterlockedDecrement(&Movie_LoadState->RefCount.Value) )
  {
    v40 = pmovieDef->pLib;
    if ( v40 )
    {
      v40->vfptr[1].__vecDelDtor(v40, (unsigned int)pmovieDef);
      pmovieDef->pLib = 0i64;
    }
    pmovieDef->Scaleform::GFx::Resource::vfptr->__vecDelDtor(pmovieDef, 1u);
  }
  return v37;
}

// File Line: 216
// RVA: 0x8E86D0
void __fastcall Scaleform::GFx::FontLib::LoadFontNames(
        Scaleform::GFx::FontLib *this,
        Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *fontnames)
{
  Scaleform::GFx::FontLibImpl *pImpl; // rax
  unsigned int v5; // r15d
  __int64 v6; // r8
  Scaleform::GFx::MovieDataDef *pObject; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v8; // rcx
  Scaleform::GFx::FontDataUseNode *volatile Value; // rsi
  const char *v10; // rax
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rbp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // rdi
  __int64 v14; // r11
  __int64 EntryCount; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v16; // r10
  unsigned __int8 *v17; // rax
  int v18; // ecx
  int v19; // r8d
  Scaleform::String *v20; // rbx
  Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::String src; // [rsp+70h] [rbp+8h] BYREF

  pImpl = this->pImpl;
  if ( pImpl )
  {
    v5 = 0;
    if ( pImpl->FontMovies.Data.Size )
    {
      v6 = 0i64;
      do
      {
        pObject = pImpl->FontMovies.Data.Data[v6].pObject;
        v8 = pObject->pData.pObject;
        if ( v8->LoadState <= LS_LoadingFrames )
          Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(v8->pFrameUpdate.pObject);
        Value = pObject->pData.pObject->BindData.pFonts.Value;
        if ( Value )
        {
          key.pFirst = &src;
          key.pSecond = &src;
          do
          {
            v10 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))Value->pFontData.pObject->vfptr[1].__vecDelDtor)(Value->pFontData.pObject);
            Scaleform::String::String(&src, v10);
            v11 = Scaleform::String::BernsteinHashFunctionCIS(
                    (const void *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                    *(_QWORD *)(src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                    0x1505ui64);
            v12 = v11;
            pTable = fontnames->mHash.pTable;
            if ( !fontnames->mHash.pTable )
              goto LABEL_20;
            v14 = v11 & pTable->SizeMask;
            EntryCount = v14;
            v16 = &pTable[2 * v14 + 1];
            if ( v16->EntryCount == -2i64 || v16->SizeMask != v14 )
              goto LABEL_20;
            while ( 1 )
            {
              if ( v16->SizeMask == v14 )
              {
                v17 = (unsigned __int8 *)((v16[1].EntryCount & 0xFFFFFFFFFFFFFFFCui64) + 12);
                do
                {
                  v18 = v17[(src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (v16[1].EntryCount & 0xFFFFFFFFFFFFFFFCui64)];
                  v19 = *v17 - v18;
                  if ( v19 )
                    break;
                  ++v17;
                }
                while ( v18 );
                if ( !v19 )
                  break;
              }
              EntryCount = v16->EntryCount;
              if ( v16->EntryCount == -1i64 )
                goto LABEL_20;
              v16 = &pTable[2 * EntryCount + 1];
            }
            if ( EntryCount >= 0 )
            {
              v20 = (Scaleform::String *)&pTable[2 * EntryCount + 2];
              Scaleform::String::operator=(v20, &src);
              Scaleform::String::operator=(v20 + 1, &src);
            }
            else
            {
LABEL_20:
              Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
                &fontnames->mHash,
                fontnames,
                &key,
                v12);
            }
            if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            Value = Value->pNext.Value;
          }
          while ( Value );
        }
        ++v5;
        pImpl = this->pImpl;
        v6 = v5;
      }
      while ( v5 < pImpl->FontMovies.Data.Size );
    }
  }
}

// File Line: 288
// RVA: 0x8D67D0
const char *__fastcall Scaleform::GFx::StateBag::GetDefaultFontLibName(Scaleform::GFx::StateBag *this)
{
  Scaleform::Render::RenderBuffer *v1; // rax
  unsigned __int64 v2; // rbx

  v1 = (Scaleform::Render::RenderBuffer *)this->vfptr->GetStateAddRef(this, 21i64);
  if ( v1 )
    v2 = ((unsigned __int64)v1->pManager & 0xFFFFFFFFFFFFFFFCui64) + 12;
  else
    v2 = 0i64;
  if ( v1 )
    Scaleform::RefCountImpl::Release(v1);
  return (const char *)v2;
}

