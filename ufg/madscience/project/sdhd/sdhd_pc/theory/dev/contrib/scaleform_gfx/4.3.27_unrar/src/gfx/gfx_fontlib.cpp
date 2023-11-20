// File Line: 55
// RVA: 0x896930
void __fastcall Scaleform::GFx::FontLib::FontLib(Scaleform::GFx::FontLib *this)
{
  Scaleform::GFx::FontLib *v1; // rdi
  Scaleform::String *v2; // rax
  Scaleform::String *v3; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = 20;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontLib::`vftable;
  v2 = (Scaleform::String *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                              Scaleform::Memory::pGlobalHeap,
                              32i64);
  v3 = v2;
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
  v1->pImpl = (Scaleform::GFx::FontLibImpl *)v3;
  Scaleform::String::operator=(v3 + 3, "gfxfontlib.swf");
}

// File Line: 65
// RVA: 0x8B1070
void __fastcall Scaleform::GFx::FontLib::AddFontsFrom(Scaleform::GFx::FontLib *this, Scaleform::GFx::MovieDef *md, bool pin)
{
  bool v3; // bp
  Scaleform::GFx::MovieDef *v4; // rsi
  Scaleform::GFx::MovieDataDef *v5; // rdi
  Scaleform::GFx::FontLibImpl *v6; // rbx
  Scaleform::Ptr<Scaleform::GFx::MovieDataDef> *v7; // rdx
  Scaleform::GFx::ResourceLibBase *v8; // rcx
  Scaleform::GFx::ResourceLibBase *v9; // rcx

  v3 = pin;
  v4 = md;
  if ( this->pImpl && md )
  {
    v5 = *(Scaleform::GFx::MovieDataDef **)(*(_QWORD *)&md[3].RefCount.Value + 24i64);
    if ( v5 )
      _InterlockedExchangeAdd(&v5->RefCount.Value, 1u);
    v6 = this->pImpl;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy> *)this->pImpl,
      this->pImpl,
      v6->FontMovies.Data.Size + 1);
    v7 = &v6->FontMovies.Data.Data[v6->FontMovies.Data.Size - 1];
    if ( v7 )
    {
      if ( v5 )
        _InterlockedExchangeAdd(&v5->RefCount.Value, 1u);
      v7->pObject = v5;
    }
    if ( v5 && !_InterlockedDecrement(&v5->RefCount.Value) )
    {
      v8 = v5->pLib;
      if ( v8 )
      {
        v8->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, (unsigned int)v5);
        v5->pLib = 0i64;
      }
      v5->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v5->vfptr, 1u);
    }
    if ( v3 )
    {
      v9 = v4->pLib;
      if ( v9 )
        v9->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, (unsigned int)v4);
    }
  }
}

// File Line: 92
// RVA: 0x90AF90
void __fastcall Scaleform::GFx::FontLib::FontResult::SetResult(Scaleform::GFx::FontLib::FontResult *this, Scaleform::GFx::MovieDef *pmovieDef, Scaleform::GFx::FontResource *pfont)
{
  Scaleform::GFx::FontResource *v3; // rsi
  Scaleform::GFx::MovieDef *v4; // rbp
  Scaleform::GFx::FontLib::FontResult *v5; // rdi
  Scaleform::GFx::MovieDef *v6; // r14
  Scaleform::GFx::ResourceLibBase *v7; // rcx
  Scaleform::GFx::FontResource *v8; // r14
  Scaleform::GFx::ResourceLibBase *v9; // rcx

  v3 = pfont;
  v4 = pmovieDef;
  v5 = this;
  if ( pmovieDef )
    _InterlockedExchangeAdd(&pmovieDef->RefCount.Value, 1u);
  if ( pfont )
    _InterlockedExchangeAdd(&pfont->RefCount.Value, 1u);
  v6 = this->pMovieDef;
  if ( this->pMovieDef && !_InterlockedDecrement(&v6->RefCount.Value) )
  {
    v7 = v6->pLib;
    if ( v7 )
    {
      v7->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)v6);
      v6->pLib = 0i64;
    }
    v6->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v6->vfptr, 1u);
  }
  v8 = v5->pFontResource;
  if ( v8 && !_InterlockedDecrement(&v8->RefCount.Value) )
  {
    v9 = v8->pLib;
    if ( v9 )
    {
      v9->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, (unsigned int)v8);
      v8->pLib = 0i64;
    }
    v8->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v8->vfptr, 1u);
  }
  v5->pMovieDef = v4;
  v5->pFontResource = v3;
}

// File Line: 108
// RVA: 0x8A4BA0
void __fastcall Scaleform::GFx::FontLib::FontResult::~FontResult(Scaleform::GFx::FontLib::FontResult *this)
{
  Scaleform::GFx::MovieDef *v1; // rdi
  Scaleform::GFx::FontLib::FontResult *v2; // rsi
  Scaleform::GFx::ResourceLibBase *v3; // rcx
  Scaleform::GFx::FontResource *v4; // rdi
  Scaleform::GFx::ResourceLibBase *v5; // rcx

  v1 = this->pMovieDef;
  v2 = this;
  if ( this->pMovieDef && !_InterlockedDecrement(&v1->RefCount.Value) )
  {
    v3 = v1->pLib;
    if ( v3 )
    {
      v3->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)v1);
      v1->pLib = 0i64;
    }
    v1->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v1->vfptr, 1u);
  }
  v4 = v2->pFontResource;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount.Value) )
  {
    v5 = v4->pLib;
    if ( v5 )
    {
      v5->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)v4);
      v4->pLib = 0i64;
    }
    v4->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v4->vfptr, 1u);
  }
}

// File Line: 124
// RVA: 0x8CBC00
char __fastcall Scaleform::GFx::FontLib::FindFont(Scaleform::GFx::FontLib *this, Scaleform::GFx::FontLib::FontResult *presult, const char *pfontname, unsigned int fontFlags, Scaleform::GFx::MovieDef *puserDef, Scaleform::GFx::StateBag *pstates, Scaleform::GFx::ResourceWeakLib *pweakLib)
{
  const char *v7; // r12
  __int64 v8; // r9
  Scaleform::GFx::MovieDataDef *v10; // r13
  char v11; // r15
  Scaleform::GFx::MovieDefImpl *v12; // rbx
  __int64 v13; // r14
  Scaleform::GFx::FontLibImpl *v14; // rdx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v15; // rcx
  Scaleform::GFx::FontDataUseNode *volatile v16; // rbx
  int v17; // esi
  int v18; // ebp
  Scaleform::Render::Font *v19; // rcx
  const char *v20; // rax
  Scaleform::GFx::LoadStates *v21; // rax
  Scaleform::GFx::LoadStates *v22; // rax
  Scaleform::GFx::LoadStates *v23; // rsi
  Scaleform::Render::RenderBuffer *v24; // rcx
  Scaleform::GFx::LoaderImpl *v25; // rax
  Scaleform::GFx::LoaderImpl *v26; // rax
  Scaleform::GFx::LoaderImpl *v27; // rbp
  Scaleform::GFx::MovieDefBindStates *v28; // rax
  Scaleform::GFx::MovieDefBindStates *v29; // rax
  Scaleform::GFx::MovieDefBindStates *v30; // rsi
  Scaleform::GFx::LoadStates *v31; // rax
  Scaleform::GFx::LoadStates *v32; // rax
  Scaleform::GFx::LoadStates *v33; // r14
  unsigned int v34; // er8
  signed __int64 v35; // rdx
  Scaleform::GFx::FontResource *v36; // rsi
  char v37; // bp
  Scaleform::GFx::Resource *v38; // rbx
  Scaleform::GFx::ResourceLibBase *v39; // rcx
  Scaleform::GFx::ResourceLibBase *v40; // rcx
  unsigned int index; // [rsp+20h] [rbp-88h]
  Scaleform::GFx::MovieDef *pmovieDef; // [rsp+28h] [rbp-80h]
  Scaleform::GFx::ResourceBindData pdata; // [rsp+58h] [rbp-50h]
  Scaleform::GFx::FontLib *v44; // [rsp+B0h] [rbp+8h]
  Scaleform::GFx::FontLib::FontResult *v45; // [rsp+B8h] [rbp+10h]
  unsigned int v46; // [rsp+C8h] [rbp+20h]

  v45 = presult;
  v44 = this;
  v7 = pfontname;
  v8 = fontFlags & 0x313;
  v46 = v8;
  if ( !this->pImpl )
    return 0;
  index = 0;
  v10 = 0i64;
  v11 = 0;
  v12 = 0i64;
  pmovieDef = 0i64;
  v13 = 0i64;
  v14 = this->pImpl;
  if ( v14->FontMovies.Data.Size )
  {
    do
    {
      if ( v11 )
        goto LABEL_16;
      v10 = v14->FontMovies.Data.Data[v13].pObject;
      v15 = v10->pData.pObject;
      if ( v15->LoadState <= 1 )
      {
        Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(v15->pFrameUpdate.pObject);
        LOWORD(v8) = v46;
      }
      v16 = v10->pData.pObject->BindData.pFonts.Value;
      if ( v16 )
      {
        v17 = v8 & 0x10 | ((v8 & 0x300) != 0 ? 0x300 : 0) | 3;
        v18 = v8 & 0x313;
        while ( 1 )
        {
          v19 = v16->pFontData.pObject;
          if ( (v19->Flags & v17) == v18 )
          {
            v20 = (const char *)((__int64 (*)(void))v19->vfptr[1].__vecDelDtor)();
            if ( !Scaleform::String::CompareNoCase(v20, v7) )
              break;
          }
          v16 = v16->pNext.Value;
          if ( !v16 )
            goto LABEL_14;
        }
        index = v16->BindIndex;
        v11 = 1;
      }
LABEL_14:
      v13 = (unsigned int)(v13 + 1);
      v14 = v44->pImpl;
      v8 = v46;
    }
    while ( (unsigned int)v13 < v14->FontMovies.Data.Size );
    if ( v11 )
    {
LABEL_16:
      if ( puserDef )
      {
        v21 = (Scaleform::GFx::LoadStates *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, _QWORD, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              144i64,
                                              0i64,
                                              v8);
        if ( v21 )
        {
          Scaleform::GFx::LoadStates::LoadStates(
            v21,
            *(Scaleform::GFx::LoaderImpl **)&puserDef[1].RefCount.Value,
            pstates,
            (Scaleform::GFx::MovieDefBindStates *)puserDef[1].pLib);
          v23 = v22;
        }
        else
        {
          v23 = 0i64;
        }
        v12 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
                v23,
                v10,
                *(_DWORD *)(*(_QWORD *)&puserDef[3].RefCount.Value + 40i64) | 1u,
                0i64);
        pmovieDef = (Scaleform::GFx::MovieDef *)&v12->vfptr;
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
        v25 = (Scaleform::GFx::LoaderImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, _QWORD, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              120i64,
                                              0i64,
                                              v8);
        if ( v25 )
        {
          Scaleform::GFx::LoaderImpl::LoaderImpl(v25, pstates, pweakLib->pStrongLib, 0);
          v27 = v26;
        }
        else
        {
          v27 = 0i64;
        }
        v28 = (Scaleform::GFx::MovieDefBindStates *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      80i64);
        if ( v28 )
        {
          Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(v28, pstates);
          v30 = v29;
        }
        else
        {
          v30 = 0i64;
        }
        v31 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                              Scaleform::Memory::pGlobalHeap,
                                              144ui64,
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
        v12 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v33, v10, 1u, 0i64);
        pmovieDef = (Scaleform::GFx::MovieDef *)&v12->vfptr;
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
        if ( !v12 )
          goto LABEL_57;
        pdata.pResource.pObject = 0i64;
        pdata.pBinding = 0i64;
        if ( v12->pBindData.pObject->ResourceBinding.Frozen )
        {
          v34 = index;
          if ( index < v12->pBindData.pObject->ResourceBinding.ResourceCount )
          {
            v35 = (signed __int64)&v12->pBindData.pObject->ResourceBinding.pResources[index];
            if ( *(_QWORD *)v35 )
              _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v35 + 8i64), 1u);
            v36 = *(Scaleform::GFx::FontResource **)v35;
            pdata.pResource.pObject = *(Scaleform::GFx::Resource **)v35;
            pdata.pBinding = *(Scaleform::GFx::ResourceBinding **)(v35 + 8);
            goto LABEL_47;
          }
        }
        else
        {
          v34 = index;
        }
        Scaleform::GFx::ResourceBinding::GetResourceData_Locked(&v12->pBindData.pObject->ResourceBinding, &pdata, v34);
        v36 = (Scaleform::GFx::FontResource *)pdata.pResource.pObject;
LABEL_47:
        v12 = (Scaleform::GFx::MovieDefImpl *)pmovieDef;
        if ( v36 )
        {
          Scaleform::GFx::FontLib::FontResult::SetResult(v45, pmovieDef, v36);
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
            v39 = pdata.pResource.pObject->pLib;
            if ( v39 )
            {
              v39->vfptr[1].__vecDelDtor(
                (Scaleform::RefCountImplCore *)&v39->vfptr,
                (unsigned int)pdata.pResource.pObject);
              v38->pLib = 0i64;
            }
            v38->vfptr->__vecDelDtor(v38, 1u);
          }
          v12 = (Scaleform::GFx::MovieDefImpl *)pmovieDef;
        }
        goto LABEL_58;
      }
    }
    v12 = 0i64;
  }
LABEL_57:
  v37 = 0;
LABEL_58:
  if ( v12 && !_InterlockedDecrement(&v12->RefCount.Value) )
  {
    v40 = pmovieDef->pLib;
    if ( v40 )
    {
      v40->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v40->vfptr, (unsigned int)pmovieDef);
      pmovieDef->pLib = 0i64;
    }
    pmovieDef->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&pmovieDef->vfptr, 1u);
  }
  return v37;
}

// File Line: 216
// RVA: 0x8E86D0
void __fastcall Scaleform::GFx::FontLib::LoadFontNames(Scaleform::GFx::FontLib *this, Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *fontnames)
{
  Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *v2; // r14
  Scaleform::GFx::FontLib *v3; // r13
  Scaleform::GFx::FontLibImpl *v4; // rax
  unsigned int v5; // er15
  __int64 v6; // r8
  Scaleform::GFx::MovieDataDef *v7; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v8; // rcx
  Scaleform::GFx::FontDataUseNode *volatile v9; // rsi
  const char *v10; // rax
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rbp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > v13; // rdi
  unsigned __int64 v14; // r11
  signed __int64 v15; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v16; // r10
  unsigned __int8 *v17; // rax
  int v18; // ecx
  int v19; // er8
  Scaleform::String *v20; // rbx
  Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+28h] [rbp-40h]
  Scaleform::String src; // [rsp+70h] [rbp+8h]

  v2 = fontnames;
  v3 = this;
  v4 = this->pImpl;
  if ( v4 )
  {
    v5 = 0;
    if ( v4->FontMovies.Data.Size )
    {
      v6 = 0i64;
      do
      {
        v7 = v4->FontMovies.Data.Data[v6].pObject;
        v8 = v7->pData.pObject;
        if ( v8->LoadState <= 1 )
          Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(v8->pFrameUpdate.pObject);
        v9 = v7->pData.pObject->BindData.pFonts.Value;
        if ( v9 )
        {
          key.pFirst = &src;
          key.pSecond = &src;
          do
          {
            v10 = (const char *)((__int64 (__cdecl *)(Scaleform::Render::Font *, Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *, __int64))v9->pFontData.pObject->vfptr[1].__vecDelDtor)(
                                  v9->pFontData.pObject,
                                  fontnames,
                                  v6);
            Scaleform::String::String(&src, v10);
            v11 = Scaleform::String::BernsteinHashFunctionCIS(
                    (const void *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                    *(_QWORD *)(src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                    0x1505ui64);
            v12 = v11;
            v13.pTable = v2->mHash.pTable;
            if ( !v2->mHash.pTable )
              goto LABEL_20;
            v14 = v11 & v13.pTable->SizeMask;
            v15 = v11 & v13.pTable->SizeMask;
            v16 = &v13.pTable[2 * (v11 & v13.pTable->SizeMask) + 1];
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
                  if ( *v17 != v18 )
                    break;
                  ++v17;
                }
                while ( v18 );
                if ( !v19 )
                  break;
              }
              v15 = v16->EntryCount;
              if ( v16->EntryCount == -1i64 )
                goto LABEL_20;
              v16 = &v13.pTable[2 * v15 + 1];
            }
            if ( v15 >= 0 )
            {
              v20 = (Scaleform::String *)&v13.pTable[2 * (v15 + 1)];
              Scaleform::String::operator=(v20, &src);
              Scaleform::String::operator=(v20 + 1, &src);
            }
            else
            {
LABEL_20:
              Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
                (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v2->mHash.pTable,
                v2,
                &key,
                v12);
            }
            fontnames = (Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *)(src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
            if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                Scaleform::Memory::pGlobalHeap,
                fontnames,
                v6);
            v9 = v9->pNext.Value;
          }
          while ( v9 );
        }
        ++v5;
        v4 = v3->pImpl;
        v6 = v5;
      }
      while ( v5 < v4->FontMovies.Data.Size );
    }
  }
}

// File Line: 288
// RVA: 0x8D67D0
const char *__fastcall Scaleform::GFx::StateBag::GetDefaultFontLibName(Scaleform::GFx::StateBag *this)
{
  Scaleform::Render::RenderBuffer *v1; // rax
  unsigned __int64 v2; // rbx

  v1 = (Scaleform::Render::RenderBuffer *)this->vfptr->GetStateAddRef(this, State_ViewMatrix3D|0x10);
  if ( v1 )
    v2 = ((_QWORD)v1->pManager & 0xFFFFFFFFFFFFFFFCui64) + 12;
  else
    v2 = 0i64;
  if ( v1 )
    Scaleform::RefCountImpl::Release(v1);
  return (const char *)v2;
}

