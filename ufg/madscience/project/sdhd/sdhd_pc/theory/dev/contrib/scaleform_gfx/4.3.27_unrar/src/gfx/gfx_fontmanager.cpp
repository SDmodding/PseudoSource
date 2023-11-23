// File Line: 25
// RVA: 0x8DE240
Scaleform::GFx::StateBagVtbl *__fastcall Scaleform::GFx::FontManagerStates::GetStateAddRef(
        Scaleform::GFx::FontManagerStates *this,
        Scaleform::GFx::State::StateType state)
{
  Scaleform::GFx::Resource *v3; // rcx
  Scaleform::GFx::StateBagVtbl *vfptr; // rcx
  Scaleform::GFx::Resource *pObject; // rcx
  Scaleform::GFx::Resource *v7; // rcx

  switch ( state )
  {
    case 20:
      v3 = *(Scaleform::GFx::Resource **)&this->RefCount;
      if ( v3 )
        Scaleform::Render::RenderBuffer::AddRef(v3);
      return *(Scaleform::GFx::StateBagVtbl **)&this->RefCount;
    case 23:
      vfptr = this->Scaleform::GFx::StateBag::vfptr;
      if ( vfptr )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)vfptr);
      return this->Scaleform::GFx::StateBag::vfptr;
    case 22:
      pObject = (Scaleform::GFx::Resource *)this->pFontLib.pObject;
      if ( pObject )
        Scaleform::Render::RenderBuffer::AddRef(pObject);
      return (Scaleform::GFx::StateBagVtbl *)this->pFontLib.pObject;
    case 1:
      v7 = (Scaleform::GFx::Resource *)this->pFontMap.pObject;
      if ( v7 )
        Scaleform::Render::RenderBuffer::AddRef(v7);
      return (Scaleform::GFx::StateBagVtbl *)this->pFontMap.pObject;
    default:
      return (Scaleform::GFx::StateBagVtbl *)((__int64 (__fastcall *)(Scaleform::GFx::FontProvider *))this->pFontProvider.pObject->vfptr[3].__vecDelDtor)(this->pFontProvider.pObject);
  }
}

// File Line: 56
// RVA: 0x8BB050
__int64 __fastcall Scaleform::GFx::FontManagerStates::CheckStateChange(
        Scaleform::GFx::FontManagerStates *this,
        Scaleform::GFx::Resource *pfontLib,
        Scaleform::GFx::Resource *pfontMap,
        Scaleform::GFx::Resource *pfontProvider,
        Scaleform::GFx::Translator *ptranslator)
{
  unsigned __int8 v5; // di
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::Render::RenderBuffer *v13; // rcx

  v5 = 0;
  if ( (Scaleform::GFx::Resource *)this->pFontLib.pObject != pfontLib )
  {
    v5 = 1;
    if ( pfontLib )
      Scaleform::Render::RenderBuffer::AddRef(pfontLib);
    pObject = (Scaleform::Render::RenderBuffer *)this->pFontLib.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFontLib.pObject = (Scaleform::GFx::FontLib *)pfontLib;
  }
  if ( (Scaleform::GFx::Resource *)this->pFontMap.pObject != pfontMap )
  {
    v5 |= 2u;
    if ( pfontMap )
      Scaleform::Render::RenderBuffer::AddRef(pfontMap);
    v11 = (Scaleform::Render::RenderBuffer *)this->pFontMap.pObject;
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    this->pFontMap.pObject = (Scaleform::GFx::FontMap *)pfontMap;
  }
  if ( (Scaleform::GFx::Resource *)this->pFontProvider.pObject != pfontProvider )
  {
    v5 |= 4u;
    if ( pfontProvider )
      Scaleform::Render::RenderBuffer::AddRef(pfontProvider);
    v12 = (Scaleform::Render::RenderBuffer *)this->pFontProvider.pObject;
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    this->pFontProvider.pObject = (Scaleform::GFx::FontProvider *)pfontProvider;
  }
  if ( this->pTranslator.pObject != ptranslator )
  {
    v5 |= 8u;
    if ( ptranslator )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)ptranslator);
    v13 = (Scaleform::Render::RenderBuffer *)this->pTranslator.pObject;
    if ( v13 )
      Scaleform::RefCountImpl::Release(v13);
    this->pTranslator.pObject = ptranslator;
  }
  return v5;
}

// File Line: 88
// RVA: 0x896A00
void __fastcall Scaleform::GFx::FontManager::FontManager(
        Scaleform::GFx::FontManager *this,
        Scaleform::GFx::MovieImpl *movie,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::FontManagerStates *pstate)
{
  Scaleform::GFx::FontMap::MapEntry *p_FontMapEntry; // rbx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::FontManagerBase,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontManagerBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontManager::`vftable;
  this->CreatedFonts.pTable = 0i64;
  this->FontMovies.Data.Data = 0i64;
  this->FontMovies.Data.Size = 0i64;
  this->FontMovies.Data.Policy.Capacity = 0i64;
  this->pEmptyFont.pObject = 0i64;
  p_FontMapEntry = &this->FontMapEntry;
  Scaleform::String::String(&this->FontMapEntry.Name);
  p_FontMapEntry->ScaleFactor = 1.0;
  p_FontMapEntry->Flags = MFF_Original;
  this->pMovie = movie;
  this->pDefImpl = pdefImpl;
  this->pWeakLib = 0i64;
  this->pState = pstate;
  Scaleform::GFx::FontManager::commonInit(this);
}

// File Line: 98
// RVA: 0x896AF0
void __fastcall Scaleform::GFx::FontManager::FontManager(
        Scaleform::GFx::FontManager *this,
        Scaleform::GFx::ResourceWeakLib *pweakLib,
        Scaleform::GFx::FontManagerStates *pstate)
{
  Scaleform::GFx::FontMap::MapEntry *p_FontMapEntry; // rbx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::FontManagerBase,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontManagerBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontManager::`vftable;
  this->CreatedFonts.pTable = 0i64;
  this->FontMovies.Data.Data = 0i64;
  this->FontMovies.Data.Size = 0i64;
  this->FontMovies.Data.Policy.Capacity = 0i64;
  this->pEmptyFont.pObject = 0i64;
  p_FontMapEntry = &this->FontMapEntry;
  Scaleform::String::String(&this->FontMapEntry.Name);
  p_FontMapEntry->ScaleFactor = 1.0;
  p_FontMapEntry->Flags = MFF_Original;
  this->pMovie = 0i64;
  this->pDefImpl = 0i64;
  this->pWeakLib = pweakLib;
  this->pState = pstate;
  Scaleform::GFx::FontManager::commonInit(this);
}

// File Line: 107
// RVA: 0x91E2B0
void __fastcall Scaleform::GFx::FontManager::commonInit(Scaleform::GFx::FontManager *this)
{
  Scaleform::GFx::FontData *v2; // rax
  Scaleform::GFx::Resource *v3; // rax
  Scaleform::GFx::Resource *v4; // rsi
  Scaleform::GFx::FontResource *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx
  __int64 v8; // rdi
  Scaleform::GFx::Resource *v9; // r14
  Scaleform::Render::RenderBuffer *pObject; // rcx
  __int64 v11; // rcx
  int v12; // [rsp+78h] [rbp+10h] BYREF
  Scaleform::GFx::FontData *v13; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::GFx::Resource *v14; // [rsp+88h] [rbp+20h]

  v12 = 75;
  v2 = (Scaleform::GFx::FontData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::FontManager *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                     Scaleform::Memory::pGlobalHeap,
                                     this,
                                     136i64,
                                     &v12,
                                     -2i64);
  v13 = v2;
  if ( v2 )
  {
    Scaleform::GFx::FontData::FontData(v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  v14 = v4;
  LODWORD(v13) = 2;
  v5 = (Scaleform::GFx::FontResource *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         64i64,
                                         &v13);
  if ( v5 )
  {
    Scaleform::GFx::FontResource::FontResource(v5, v4, 0i64);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
         Scaleform::Memory::pGlobalHeap,
         64i64);
  if ( v8 )
  {
    v9 = *(Scaleform::GFx::Resource **)(v7 + 24);
    *(_QWORD *)v8 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v8 + 8) = 1;
    *(_QWORD *)v8 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v8 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable;
    *(_QWORD *)v8 = &Scaleform::RefCountBase<Scaleform::Render::Text::FontHandle,74>::`vftable;
    *(_QWORD *)v8 = &Scaleform::Render::Text::FontHandle::`vftable;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_DWORD *)(v8 + 24) = 0;
    Scaleform::StringLH::StringLH((Scaleform::StringLH *)(v8 + 32));
    *(_DWORD *)(v8 + 40) = 1065353216;
    if ( v9 )
      Scaleform::Render::RenderBuffer::AddRef(v9);
    *(_QWORD *)(v8 + 48) = v9;
    *(_QWORD *)v8 = &Scaleform::GFx::FontHandle::`vftable;
    *(_QWORD *)(v8 + 56) = 0i64;
  }
  else
  {
    v8 = 0i64;
  }
  pObject = (Scaleform::Render::RenderBuffer *)this->pEmptyFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pEmptyFont.pObject = (Scaleform::GFx::FontHandle *)v8;
  if ( v7 && !_InterlockedDecrement((volatile signed __int32 *)(v7 + 8)) )
  {
    v11 = *(_QWORD *)(v7 + 16);
    if ( v11 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 8i64))(v11, v7);
      *(_QWORD *)(v7 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, __int64))v7)(v7, 1i64);
  }
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v4);
}

// File Line: 114
// RVA: 0x8A4970
void __fastcall Scaleform::GFx::FontManager::~FontManager(Scaleform::GFx::FontManager *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontManager::`vftable;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->FontMapEntry.Name.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  pObject = (Scaleform::Render::RenderBuffer *)this->pEmptyFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>>::DestructArray(
    (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)this->FontMovies.Data.Data,
    this->FontMovies.Data.Size);
  if ( this->FontMovies.Data.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::HashSet<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::~HashSet<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>(&this->CreatedFonts);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontManagerBase::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 141
// RVA: 0x8CD740
char *__fastcall Scaleform::GFx::FontFlagsToString(unsigned int matchFontFlags)
{
  char *result; // rax
  char v2; // al

  if ( !matchFontFlags )
    return (char *)StrFlags[0];
  v2 = matchFontFlags & 3;
  if ( (matchFontFlags & 0x10) != 0 )
  {
    if ( v2 == 3 )
    {
      return off_1420B1208;
    }
    else if ( (matchFontFlags & 2) != 0 )
    {
      return off_1420B11F8[0];
    }
    else
    {
      result = off_1420B11F0[0];
      if ( (matchFontFlags & 1) != 0 )
        return off_1420B1200[0];
    }
  }
  else if ( v2 == 3 )
  {
    return off_1420B11E8[0];
  }
  else if ( (matchFontFlags & 2) != 0 )
  {
    return off_1420B11D8[0];
  }
  else
  {
    result = (char *)StrFlags[0];
    if ( (matchFontFlags & 1) != 0 )
      return off_1420B11E0[0];
  }
  return result;
}

// File Line: 167
// RVA: 0x8B2440
void __fastcall Scaleform::GFx::AddSearchInfo_2(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo,
        const char *line)
{
  int i; // edi
  Scaleform::String v5; // [rsp+50h] [rbp+8h] BYREF

  if ( psearchInfo )
  {
    Scaleform::String::String(&v5, "   ");
    for ( i = 0; i < psearchInfo->Indent; ++i )
      Scaleform::StringBuffer::AppendString(
        &psearchInfo->Info,
        (const char *)((v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        *(_QWORD *)(v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
    Scaleform::StringBuffer::AppendString(&psearchInfo->Info, line, -1i64);
    Scaleform::StringBuffer::AppendString(&psearchInfo->Info, "\n", -1i64);
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 179
// RVA: 0x8B2510
void __fastcall Scaleform::GFx::AddSearchInfo_3(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo,
        char *pfontname,
        unsigned int flags,
        bool fontlib_installed,
        Scaleform::GFx::MovieDefImpl::SearchInfo *resSearchInfo)
{
  Scaleform::GFx::MovieDefImpl::SearchInfo *v8; // r13
  Scaleform::GFx::MovieDefImpl::SearchInfo::SearchStatus Status; // eax
  Scaleform::MsgFormat *v10; // rcx
  Scaleform::HashSet<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> > *p_ImportSearchUrls; // r14
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *pTable; // rax
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *v13; // rdx
  unsigned __int64 v14; // rax
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *v15; // rcx
  __int128 v16; // rcx
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *v17; // rdx
  unsigned __int64 v18; // rax
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *v19; // rcx
  Scaleform::String *v20; // rax
  Scaleform::String *v21; // rax
  Scaleform::String *v22; // rax
  _QWORD *v23; // rax
  char *v24; // rax
  __int128 v25; // [rsp+30h] [rbp-D0h]
  Scaleform::String v26; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::String v27; // [rsp+48h] [rbp-B8h] BYREF
  char *v28; // [rsp+50h] [rbp-B0h] BYREF
  char *v29; // [rsp+58h] [rbp-A8h] BYREF
  char *v30; // [rsp+60h] [rbp-A0h] BYREF
  char *v31; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::String result; // [rsp+70h] [rbp-90h] BYREF
  char *v33; // [rsp+78h] [rbp-88h] BYREF
  char *v34; // [rsp+80h] [rbp-80h] BYREF
  char *v35; // [rsp+88h] [rbp-78h] BYREF
  char *v36; // [rsp+90h] [rbp-70h] BYREF
  char *v37; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::MsgFormat::Sink v38; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::MsgFormat::Sink v39; // [rsp+B8h] [rbp-48h] BYREF
  Scaleform::MsgFormat::Sink v40; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::MsgFormat::Sink r; // [rsp+E8h] [rbp-18h] BYREF
  Scaleform::MsgFormat::Sink v42; // [rsp+100h] [rbp+0h] BYREF
  Scaleform::MsgFormat::Sink v43; // [rsp+118h] [rbp+18h] BYREF
  Scaleform::MsgFormat::Sink v44; // [rsp+130h] [rbp+30h] BYREF
  Scaleform::MsgFormat::Sink v45; // [rsp+148h] [rbp+48h] BYREF
  Scaleform::MsgFormat::Sink v46; // [rsp+160h] [rbp+60h] BYREF
  Scaleform::MsgFormat::Sink v47; // [rsp+178h] [rbp+78h] BYREF
  __int64 v48; // [rsp+190h] [rbp+90h]
  char line[1024]; // [rsp+1A0h] [rbp+A0h] BYREF
  Scaleform::MsgFormat v50; // [rsp+5A0h] [rbp+4A0h] BYREF
  Scaleform::MsgFormat v51; // [rsp+9A0h] [rbp+8A0h] BYREF
  Scaleform::MsgFormat v52; // [rsp+DA0h] [rbp+CA0h] BYREF
  Scaleform::MsgFormat v53; // [rsp+11A0h] [rbp+10A0h] BYREF
  Scaleform::MsgFormat v54; // [rsp+15A0h] [rbp+14A0h] BYREF
  Scaleform::MsgFormat v55; // [rsp+19A0h] [rbp+18A0h] BYREF
  Scaleform::MsgFormat v56; // [rsp+1DA0h] [rbp+1CA0h] BYREF
  Scaleform::MsgFormat v57; // [rsp+21A0h] [rbp+20A0h] BYREF
  Scaleform::MsgFormat v58; // [rsp+25A0h] [rbp+24A0h] BYREF
  Scaleform::MsgFormat v59; // [rsp+29A0h] [rbp+28A0h] BYREF
  Scaleform::String v60; // [rsp+2DE0h] [rbp+2CE0h] BYREF
  char *v; // [rsp+2DE8h] [rbp+2CE8h] BYREF

  if ( psearchInfo )
  {
    v = pfontname;
    v48 = -2i64;
    v8 = resSearchInfo;
    Status = resSearchInfo->Status;
    if ( resSearchInfo->Status == FoundInResources )
    {
      v34 = (char *)Scaleform::GFx::FontFlagsToString(flags);
      r.Type = tDataPtr;
      r.SinkData.pStr = (Scaleform::String *)line;
      r.SinkData.DataPtr.Size = 1024i64;
      Scaleform::MsgFormat::MsgFormat(&v57, &r);
      Scaleform::MsgFormat::Parse(&v57, "Movie resource: \"{0}\" {1} found.");
      Scaleform::MsgFormat::FormatD1<char const *>(&v57, (const char **)&v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v57, (const char **)&v34);
      Scaleform::MsgFormat::FinishFormatD(&v57);
      v10 = &v57;
    }
    else if ( Status == FoundInResourcesNeedFaux )
    {
      v35 = (char *)Scaleform::GFx::FontFlagsToString(flags);
      v40.Type = tDataPtr;
      v40.SinkData.pStr = (Scaleform::String *)line;
      v40.SinkData.DataPtr.Size = 1024i64;
      Scaleform::MsgFormat::MsgFormat(&v52, &v40);
      Scaleform::MsgFormat::Parse(&v52, "Movie resource: \"{0}\" {1} found, requires faux");
      Scaleform::MsgFormat::FormatD1<char const *>(&v52, (const char **)&v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v52, (const char **)&v35);
      Scaleform::MsgFormat::FinishFormatD(&v52);
      v10 = &v52;
    }
    else if ( Status == FoundInResourcesNoGlyphs )
    {
      v37 = (char *)Scaleform::GFx::FontFlagsToString(flags);
      v38.Type = tDataPtr;
      v38.SinkData.pStr = (Scaleform::String *)line;
      v38.SinkData.DataPtr.Size = 1024i64;
      Scaleform::MsgFormat::MsgFormat(&v56, &v38);
      Scaleform::MsgFormat::Parse(&v56, "Movie resource: \"{0}\" {1} ref found, requires FontLib/Map/Provider.");
      Scaleform::MsgFormat::FormatD1<char const *>(&v56, (const char **)&v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v56, (const char **)&v37);
      Scaleform::MsgFormat::FinishFormatD(&v56);
      v10 = &v56;
    }
    else
    {
      v28 = (char *)Scaleform::GFx::FontFlagsToString(flags);
      v43.Type = tDataPtr;
      v43.SinkData.pStr = (Scaleform::String *)line;
      v43.SinkData.DataPtr.Size = 1024i64;
      Scaleform::MsgFormat::MsgFormat(&v54, &v43);
      Scaleform::MsgFormat::Parse(&v54, "Movie resource: \"{0}\" {1} not found.");
      Scaleform::MsgFormat::FormatD1<char const *>(&v54, (const char **)&v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v54, (const char **)&v28);
      Scaleform::MsgFormat::FinishFormatD(&v54);
      Scaleform::MsgFormat::~MsgFormat(&v54);
      Scaleform::GFx::AddSearchInfo_2(psearchInfo, line);
      if ( v8->Status == FoundInImports )
        goto LABEL_49;
      if ( v8->Status != FoundInImportsFontLib )
      {
        v30 = (char *)Scaleform::GFx::FontFlagsToString(flags);
        v39.Type = tDataPtr;
        v39.SinkData.pStr = (Scaleform::String *)line;
        v39.SinkData.DataPtr.Size = 1024i64;
        Scaleform::MsgFormat::MsgFormat(&v51, &v39);
        Scaleform::MsgFormat::Parse(&v51, "Imports       : \"{0}\" {1} not found.");
        Scaleform::MsgFormat::FormatD1<char const *>(&v51, (const char **)&v);
        Scaleform::MsgFormat::FormatD1<char const *>(&v51, (const char **)&v30);
        Scaleform::MsgFormat::FinishFormatD(&v51);
        Scaleform::MsgFormat::~MsgFormat(&v51);
        Scaleform::GFx::AddSearchInfo_2(psearchInfo, line);
        p_ImportSearchUrls = &v8->ImportSearchUrls;
        pTable = v8->ImportSearchUrls.pTable;
        if ( pTable && pTable->EntryCount )
        {
          Scaleform::String::String(&v60);
          v13 = p_ImportSearchUrls->pTable;
          if ( p_ImportSearchUrls->pTable )
          {
            v14 = 0i64;
            v15 = v13 + 1;
            do
            {
              if ( v15->EntryCount != -2i64 )
                break;
              ++v14;
              v15 = (Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *)((char *)v15 + 24);
            }
            while ( v14 <= v13->SizeMask );
            *(_QWORD *)&v25 = &v8->ImportSearchUrls;
            *((_QWORD *)&v25 + 1) = v14;
          }
          else
          {
            v25 = 0ui64;
          }
          *((_QWORD *)&v16 + 1) = *((_QWORD *)&v25 + 1);
          while ( (_QWORD)v25 && *(_QWORD *)v25 && *((__int64 *)&v16 + 1) <= *(_QWORD *)(*(_QWORD *)v25 + 8i64) )
          {
            v17 = p_ImportSearchUrls->pTable;
            if ( p_ImportSearchUrls->pTable )
            {
              v18 = 0i64;
              v19 = v17 + 1;
              do
              {
                if ( v19->EntryCount != -2i64 )
                  break;
                ++v18;
                v19 = (Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *)((char *)v19 + 24);
              }
              while ( v18 <= v17->SizeMask );
              *(_QWORD *)&v16 = &v8->ImportSearchUrls;
            }
            else
            {
              *(_QWORD *)&v16 = 0i64;
              v18 = 0i64;
            }
            if ( v16 != __PAIR128__(v18, v25) )
              Scaleform::String::AppendString(&v60, ", ", -1i64);
            Scaleform::String::String(&v27, "\"");
            v21 = Scaleform::String::operator+(
                    v20,
                    &result,
                    (Scaleform::String *)(*(_QWORD *)v25
                                        + 8 * (*((_QWORD *)&v16 + 1) + 2 * (*((_QWORD *)&v16 + 1) + 2i64))));
            v22 = Scaleform::String::operator+(v21, &v26, "\"");
            Scaleform::String::operator+=(&v60, v22);
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v27.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            *(_QWORD *)&v16 = *(_QWORD *)(*(_QWORD *)v25 + 8i64);
            if ( *((__int64 *)&v16 + 1) <= (__int64)v16 && ++*((_QWORD *)&v16 + 1) <= (unsigned __int64)v16 )
            {
              v23 = (_QWORD *)(*(_QWORD *)v25 + 8 * (*((_QWORD *)&v16 + 1) + 2 * (*((_QWORD *)&v16 + 1) + 1i64)));
              do
              {
                if ( *v23 != -2i64 )
                  break;
                ++*((_QWORD *)&v16 + 1);
                v23 += 3;
              }
              while ( *((_QWORD *)&v16 + 1) <= (unsigned __int64)v16 );
            }
          }
          v42.Type = tDataPtr;
          v42.SinkData.pStr = (Scaleform::String *)line;
          v42.SinkData.DataPtr.Size = 1024i64;
          Scaleform::MsgFormat::MsgFormat(&v59, &v42);
          Scaleform::MsgFormat::Parse(&v59, "              : {0}.");
          Scaleform::MsgFormat::FormatD1<Scaleform::String>(&v59, &v60);
          Scaleform::MsgFormat::FinishFormatD(&v59);
          Scaleform::MsgFormat::~MsgFormat(&v59);
          Scaleform::GFx::AddSearchInfo_2(psearchInfo, line);
          if ( _InterlockedExchangeAdd(
                 (volatile signed __int32 *)((v60.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
                 0xFFFFFFFF) == 1 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        v24 = (char *)Scaleform::GFx::FontFlagsToString(flags);
        if ( v8->Status == FoundInExports )
        {
          v29 = v24;
          v44.Type = tDataPtr;
          v44.SinkData.pStr = (Scaleform::String *)line;
          v44.SinkData.DataPtr.Size = 1024i64;
          Scaleform::MsgFormat::MsgFormat(&v53, &v44);
          Scaleform::MsgFormat::Parse(&v53, "Exported      : \"{0}\" {1} found.");
          Scaleform::MsgFormat::FormatD1<char const *>(&v53, (const char **)&v);
          Scaleform::MsgFormat::FormatD1<char const *>(&v53, (const char **)&v29);
          Scaleform::MsgFormat::FinishFormatD(&v53);
          v10 = &v53;
        }
        else
        {
          v31 = v24;
          v47.Type = tDataPtr;
          v47.SinkData.pStr = (Scaleform::String *)line;
          v47.SinkData.DataPtr.Size = 1024i64;
          Scaleform::MsgFormat::MsgFormat(&v55, &v47);
          Scaleform::MsgFormat::Parse(&v55, "Exported      : \"{0}\" {1} not found.");
          Scaleform::MsgFormat::FormatD1<char const *>(&v55, (const char **)&v);
          Scaleform::MsgFormat::FormatD1<char const *>(&v55, (const char **)&v31);
          Scaleform::MsgFormat::FinishFormatD(&v55);
          v10 = &v55;
        }
        goto LABEL_50;
      }
      if ( !fontlib_installed )
      {
LABEL_49:
        v33 = (char *)Scaleform::GFx::FontFlagsToString(flags);
        v46.Type = tDataPtr;
        v46.SinkData.pStr = (Scaleform::String *)line;
        v46.SinkData.DataPtr.Size = 1024i64;
        Scaleform::MsgFormat::MsgFormat(&v50, &v46);
        Scaleform::MsgFormat::Parse(&v50, "Imports       : \"{0}\" {1} found in \"{2}\".");
        Scaleform::MsgFormat::FormatD1<char const *>(&v50, (const char **)&v);
        Scaleform::MsgFormat::FormatD1<char const *>(&v50, (const char **)&v33);
        Scaleform::MsgFormat::FormatD1<Scaleform::String>(&v50, &v8->ImportFoundUrl);
        Scaleform::MsgFormat::FinishFormatD(&v50);
        v10 = &v50;
      }
      else
      {
        v36 = (char *)Scaleform::GFx::FontFlagsToString(flags);
        v45.Type = tDataPtr;
        v45.SinkData.pStr = (Scaleform::String *)line;
        v45.SinkData.DataPtr.Size = 1024i64;
        Scaleform::MsgFormat::MsgFormat(&v58, &v45);
        Scaleform::MsgFormat::Parse(&v58, "Imports       : \"{0}\" {1} import delegates to font library.");
        Scaleform::MsgFormat::FormatD1<char const *>(&v58, (const char **)&v);
        Scaleform::MsgFormat::FormatD1<char const *>(&v58, (const char **)&v36);
        Scaleform::MsgFormat::FinishFormatD(&v58);
        v10 = &v58;
      }
    }
LABEL_50:
    Scaleform::MsgFormat::~MsgFormat(v10);
    Scaleform::GFx::AddSearchInfo_2(psearchInfo, line);
  }
}

// File Line: 260
// RVA: 0x8B2350
void __fastcall Scaleform::GFx::AddSearchInfo_1(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo,
        const char *str1,
        const char *str2,
        const char *str3,
        unsigned int flags,
        const char *str4)
{
  const char *v10; // rax
  char *pData; // rdx
  Scaleform::StringBuffer v12; // [rsp+28h] [rbp-40h] BYREF

  if ( psearchInfo )
  {
    Scaleform::StringBuffer::StringBuffer(&v12, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v12, str1, -1i64);
    Scaleform::StringBuffer::AppendString(&v12, str2, -1i64);
    Scaleform::StringBuffer::AppendString(&v12, str3, -1i64);
    v10 = Scaleform::GFx::FontFlagsToString(flags);
    Scaleform::StringBuffer::AppendString(&v12, v10, -1i64);
    Scaleform::StringBuffer::AppendString(&v12, str4, -1i64);
    pData = &customCaption;
    if ( v12.pData )
      pData = v12.pData;
    Scaleform::GFx::AddSearchInfo_2(psearchInfo, pData);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v12);
  }
}

// File Line: 273
// RVA: 0x8B2220
void __fastcall Scaleform::GFx::AddSearchInfo_0(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo,
        const char *str1,
        const char *str2,
        const char *str3,
        unsigned int flags1,
        const char *str4,
        const char *str5,
        const char *str6,
        unsigned int flags2)
{
  const char *v13; // rax
  const char *v14; // rax
  char *pData; // rdx
  Scaleform::StringBuffer v16; // [rsp+28h] [rbp-40h] BYREF

  if ( psearchInfo )
  {
    Scaleform::StringBuffer::StringBuffer(&v16, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v16, str1, -1i64);
    Scaleform::StringBuffer::AppendString(&v16, str2, -1i64);
    Scaleform::StringBuffer::AppendString(&v16, str3, -1i64);
    v13 = Scaleform::GFx::FontFlagsToString(flags1);
    Scaleform::StringBuffer::AppendString(&v16, v13, -1i64);
    Scaleform::StringBuffer::AppendString(&v16, str4, -1i64);
    Scaleform::StringBuffer::AppendString(&v16, str5, -1i64);
    Scaleform::StringBuffer::AppendString(&v16, str6, -1i64);
    v14 = Scaleform::GFx::FontFlagsToString(flags2);
    Scaleform::StringBuffer::AppendString(&v16, v14, -1i64);
    pData = &customCaption;
    if ( v16.pData )
      pData = v16.pData;
    Scaleform::GFx::AddSearchInfo_2(psearchInfo, pData);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v16);
  }
}

// File Line: 290
// RVA: 0x8B2120
void __fastcall Scaleform::GFx::AddSearchInfo(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo,
        const char *str1,
        const char *str2,
        const char *str3,
        const char *str4,
        const char *str5,
        unsigned int flags)
{
  const char *v11; // rax
  char *pData; // rdx
  Scaleform::StringBuffer v13; // [rsp+28h] [rbp-40h] BYREF

  if ( psearchInfo )
  {
    Scaleform::StringBuffer::StringBuffer(&v13, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v13, str1, -1i64);
    Scaleform::StringBuffer::AppendString(&v13, str2, -1i64);
    Scaleform::StringBuffer::AppendString(&v13, str3, -1i64);
    Scaleform::StringBuffer::AppendString(&v13, str4, -1i64);
    Scaleform::StringBuffer::AppendString(&v13, str5, -1i64);
    v11 = Scaleform::GFx::FontFlagsToString(flags);
    Scaleform::StringBuffer::AppendString(&v13, v11, -1i64);
    pData = &customCaption;
    if ( v13.pData )
      pData = v13.pData;
    Scaleform::GFx::AddSearchInfo_2(psearchInfo, pData);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v13);
  }
}

// File Line: 307
// RVA: 0x8CC5A0
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::FontManager::FindOrCreateHandle(
        Scaleform::GFx::FontManager *this,
        char *pfontName,
        unsigned int matchFontFlags,
        Scaleform::GFx::FontResource **ppfoundFont,
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  unsigned int v5; // edi
  char *v6; // r12
  Scaleform::GFx::FontManager *v7; // r13
  Scaleform::GFx::Resource *v8; // r14
  Scaleform::GFx::FontHandle *v9; // rbx
  Scaleform::GFx::FontManagerStates *pState; // rax
  int v11; // esi
  Scaleform::GFx::MovieDefImpl::SearchInfo *p_resSearchInfo; // rdx
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v13; // r15
  unsigned __int64 v14; // rdx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rax
  Scaleform::GFx::Resource **v17; // rdi
  Scaleform::GFx::Resource *v18; // rcx
  Scaleform::GFx::MovieDefImpl *pDefImpl; // rcx
  Scaleform::GFx::FontResource *RegisteredFont; // rsi
  Scaleform::GFx::MovieDef *v21; // rdi
  Scaleform::GFx::MovieImpl *pMovie; // rcx
  Scaleform::Render::Font *v23; // rcx
  Scaleform::Render::Text::FontHandle *v24; // rax
  Scaleform::Render::Text::FontManagerBase *v25; // rdx
  _QWORD *v26; // rax
  char *v27; // rcx
  unsigned int v28; // r15d
  unsigned __int8 v29; // di
  unsigned __int64 v30; // rdx
  unsigned __int64 v31; // rax
  signed __int64 v32; // rax
  __int64 v33; // rdi
  bool v34; // zf
  Scaleform::GFx::FontHandle **v35; // rdi
  const char *v36; // r13
  unsigned int flags; // r12d
  float ScaleFactor; // xmm6_4
  __int32 v39; // r15d
  const char *v40; // rsi
  Scaleform::GFx::FontMap::MapFontFlags v41; // r12d
  Scaleform::GFx::FontMap::MapFontFlags v42; // eax
  int v43; // r15d
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v44; // rdi
  Scaleform::HashSetLH<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *p_CreatedFonts; // rsi
  unsigned __int64 v46; // rdx
  unsigned __int64 v47; // rax
  signed __int64 v48; // rax
  Scaleform::GFx::Resource *v49; // rax
  Scaleform::GFx::FontHandle *v50; // rax
  Scaleform::GFx::FontHandle *v51; // rax
  unsigned __int64 v52; // rdx
  unsigned __int64 v53; // rax
  signed __int64 v54; // rax
  Scaleform::GFx::FontHandle *v55; // rax
  Scaleform::GFx::FontHandle *v56; // rax
  __int64 v57; // r11
  Scaleform::GFx::FontManagerStates *v58; // rax
  Scaleform::GFx::StateBag *v59; // rcx
  unsigned __int64 v60; // rdx
  unsigned __int64 v61; // rax
  signed __int64 v62; // rax
  Scaleform::GFx::Resource **v63; // rbx
  Scaleform::GFx::MovieDef *pMovieDef; // rdi
  Scaleform::GFx::FontManager *v65; // rdx
  Scaleform::GFx::MovieDef *v66; // rdi
  Scaleform::GFx::FontManager *v67; // rdx
  const char *str4; // rax
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v69; // rcx
  Scaleform::GFx::MovieDef *v70; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::FontResource *pFontResource; // rdi
  Scaleform::GFx::ResourceLibBase *v73; // rcx
  Scaleform::GFx::MovieDefImpl *v74; // rax
  Scaleform::GFx::ResourceWeakLib *pWeakLib; // r9
  Scaleform::GFx::FontResource *FontResource; // rdi
  Scaleform::Render::Text::FontHandle *v77; // rax
  Scaleform::GFx::FontManager *v78; // rdx
  Scaleform::GFx::ResourceLibBase *v79; // rcx
  unsigned int v80; // r12d
  Scaleform::GFx::FontManager *v81; // rsi
  Scaleform::GFx::FontManagerStates *v82; // rax
  __int64 v83; // rax
  __int64 v84; // rdi
  Scaleform::GFx::FontManager *v85; // rdx
  const char *v86; // rax
  __int64 v87; // rdi
  __int64 v88; // rcx
  __int64 v89; // rdi
  __int64 v90; // rcx
  Scaleform::GFx::FontHandle **v91; // rdx
  char v93; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::FontHandle *v94; // [rsp+48h] [rbp-B8h] BYREF
  int v95; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::FontLib *pObject; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::FontHandle *v97; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::FontHandle **v98; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::MovieDefImpl::SearchInfo *v99; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::MovieDef *ppsrcMovieDef; // [rsp+78h] [rbp-88h] BYREF
  Scaleform::GFx::FontLib::FontResult v101; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::FontProvider *pprovider; // [rsp+90h] [rbp-70h]
  __int64 v103; // [rsp+98h] [rbp-68h] BYREF
  __int64 v104; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::MovieDefImpl::SearchInfo resSearchInfo; // [rsp+A8h] [rbp-58h] BYREF
  Scaleform::GFx::FontMap *v106; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::FontManager::FontKey key; // [rsp+C8h] [rbp-38h] BYREF
  Scaleform::GFx::FontManager::FontKey v108; // [rsp+D8h] [rbp-28h] BYREF
  Scaleform::GFx::FontManager::FontKey v109; // [rsp+E8h] [rbp-18h] BYREF
  Scaleform::GFx::FontManager::FontKey v110; // [rsp+F8h] [rbp-8h] BYREF
  __int64 v111; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::FontResource *v112; // [rsp+110h] [rbp+10h]
  unsigned int matchFontFlagsa; // [rsp+1A0h] [rbp+A0h]

  matchFontFlagsa = matchFontFlags;
  v111 = -2i64;
  v5 = matchFontFlags;
  v6 = pfontName;
  v7 = this;
  key.pFontName = pfontName;
  key.FontStyle = matchFontFlags;
  v8 = 0i64;
  v9 = 0i64;
  v94 = 0i64;
  pState = this->pState;
  pObject = pState->pFontLib.pObject;
  pprovider = pState->pFontProvider.pObject;
  v106 = pState->pFontMap.pObject;
  v11 = 0;
  v95 = 0;
  v98 = 0i64;
  ppsrcMovieDef = (Scaleform::GFx::MovieDef *)&resSearchInfo.ImportSearchUrls;
  resSearchInfo.ImportSearchUrls.pTable = 0i64;
  Scaleform::String::String(&resSearchInfo.ImportFoundUrl);
  p_resSearchInfo = 0i64;
  v99 = 0i64;
  v93 = 0;
  v13 = searchInfo;
  while ( 1 )
  {
    if ( v13 )
    {
      v95 = v11 + 1;
      ++v13->Indent;
      p_resSearchInfo = &resSearchInfo;
      v99 = &resSearchInfo;
    }
    else if ( v7->CreatedFonts.pTable )
    {
      v14 = -1i64;
      do
        ++v14;
      while ( v6[v14] );
      v15 = Scaleform::String::BernsteinHashFunctionCIS(v6, v14, 0x1505ui64);
      v16 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontManager::FontKey>(
              &v7->CreatedFonts,
              &key,
              v7->CreatedFonts.pTable->SizeMask & (v15 ^ v5 & 3));
      if ( v16 >= 0 )
      {
        v17 = (Scaleform::GFx::Resource **)&v7->CreatedFonts.pTable[2 * v16 + 2];
        if ( v17 )
        {
          if ( (matchFontFlagsa & 0x10) != 0 )
            goto LABEL_189;
          v18 = *v17;
          if ( ((BYTE4((*v17)[2].vfptr->GetResourceReport) | LOBYTE((*v17)[1].vfptr)) & 0x10) == 0 )
            goto LABEL_189;
          if ( *((_BYTE *)v17 + 8) )
            goto LABEL_191;
          v98 = (Scaleform::GFx::FontHandle **)&v7->CreatedFonts.pTable[2 * v16 + 2];
        }
        v5 = matchFontFlagsa;
      }
      p_resSearchInfo = v99;
    }
    pDefImpl = v7->pDefImpl;
    if ( pDefImpl )
      RegisteredFont = (Scaleform::GFx::FontResource *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, char *, _QWORD, Scaleform::GFx::MovieDefImpl::SearchInfo *))pDefImpl->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[7].__vecDelDtor)(
                                                         pDefImpl,
                                                         v6,
                                                         v5,
                                                         p_resSearchInfo);
    else
      RegisteredFont = 0i64;
    Scaleform::GFx::AddSearchInfo_3(v13, v6, v5, v7->pState->pFontLib.pObject != 0i64, &resSearchInfo);
    v21 = 0i64;
    ppsrcMovieDef = 0i64;
    if ( !RegisteredFont )
    {
      pMovie = v7->pMovie;
      if ( !pMovie )
        goto LABEL_34;
      RegisteredFont = Scaleform::GFx::MovieImpl::FindRegisteredFont(pMovie, v6, matchFontFlagsa, &ppsrcMovieDef);
      if ( !RegisteredFont )
      {
        Scaleform::GFx::AddSearchInfo_1(v13, "Registered fonts: \"", v6, "\"", matchFontFlagsa, " not found.");
        goto LABEL_34;
      }
      v21 = ppsrcMovieDef;
    }
    v23 = RegisteredFont->pFont.pObject;
    if ( (v23->Flags & 0x40) == 0 )
    {
      if ( (matchFontFlagsa & 3) != 0
        && !((unsigned __int8 (__fastcall *)(Scaleform::Render::Font *))v23->vfptr[19].__vecDelDtor)(v23) )
      {
        if ( ppfoundFont )
          *ppfoundFont = RegisteredFont;
        v91 = v98;
        if ( v98 )
        {
          (*v98)->pFontManager = 0i64;
          Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::RemoveAlt<Scaleform::GFx::FontHandle *>(
            &v7->CreatedFonts,
            v91);
        }
        goto LABEL_200;
      }
      v24 = (Scaleform::Render::Text::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     64i64);
      v9 = (Scaleform::GFx::FontHandle *)v24;
      v97 = (Scaleform::GFx::FontHandle *)v24;
      if ( v24 )
      {
        v25 = v7;
        if ( v13 )
          v25 = 0i64;
        Scaleform::Render::Text::FontHandle::FontHandle(
          v24,
          v25,
          (Scaleform::GFx::Resource *)RegisteredFont->pFont.pObject,
          v6,
          0);
        v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable;
        if ( v21 )
        {
          _InterlockedExchangeAdd(&v21->RefCount.Value, 1u);
          v21 = ppsrcMovieDef;
        }
        v9->pSourceMovieDef.pObject = v21;
      }
      else
      {
        v9 = 0i64;
      }
      v94 = v9;
    }
LABEL_34:
    v17 = (Scaleform::GFx::Resource **)v98;
    if ( v98 )
    {
      if ( !v9 )
      {
        *((_BYTE *)v98 + 8) = 1;
LABEL_189:
        Scaleform::Render::RenderBuffer::AddRef(*v17);
        v8 = *v17;
        goto LABEL_200;
      }
      (*v98)->pFontManager = 0i64;
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::RemoveAlt<Scaleform::GFx::FontHandle *>(
        &v7->CreatedFonts,
        (Scaleform::GFx::FontHandle **)v17);
      if ( !v7->CreatedFonts.pTable )
        goto LABEL_45;
      v26 = (_QWORD *)(v9->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
      v27 = (*v26 & 0x7FFFFFFFFFFFFFFFi64) != 0
          ? (char *)v26 + 12
          : (char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v9->pFont.pObject->Scaleform::Render::Text::FontHandle::vfptr[1].__vecDelDtor)(v9->pFont.pObject);
      v28 = v9->pFont.pObject->Flags;
      v29 = (v28 | v9->OverridenFontFlags) & 3;
      v30 = -1i64;
      do
        ++v30;
      while ( v27[v30] );
      v31 = Scaleform::String::BernsteinHashFunctionCIS(v27, v30, 0x1505ui64);
      v32 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontHandle *>(
              &v7->CreatedFonts,
              &v94,
              v7->CreatedFonts.pTable->SizeMask & (v31 ^ ((unsigned __int8)v28 | v29) & 3));
      if ( v32 >= 0 )
      {
        v33 = 2 * (v32 + 1);
        v34 = &v7->CreatedFonts.pTable[v33] == 0;
        v35 = (Scaleform::GFx::FontHandle **)&v7->CreatedFonts.pTable[v33];
        v98 = v35;
        if ( !v34 )
        {
          v9->pFontManager = 0i64;
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
          Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)*v35);
          v8 = (Scaleform::GFx::Resource *)*v35;
          goto LABEL_200;
        }
      }
      else
      {
LABEL_45:
        v98 = 0i64;
      }
    }
    v36 = v6;
    flags = matchFontFlagsa;
    ScaleFactor = *(float *)&FLOAT_1_0;
    v39 = 0;
    if ( v9 )
      goto LABEL_120;
    v40 = pfontName;
    if ( !v106 || !Scaleform::GFx::FontMap::GetFontMapping(v106, &this->FontMapEntry, pfontName) )
      goto LABEL_79;
    v36 = (const char *)((this->FontMapEntry.Name.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
    v41 = this->FontMapEntry.Flags;
    if ( v41 == MFF_Original )
      flags = matchFontFlagsa;
    else
      flags = matchFontFlagsa & 0xFFFFFFFC | v41 & 0xFFFFFFF3;
    ScaleFactor = this->FontMapEntry.ScaleFactor;
    v42 = this->FontMapEntry.Flags;
    if ( (v42 & 0xC) != 0 )
      v43 = v42 >> 2;
    else
      LOBYTE(v43) = 0;
    v39 = this->FontMapEntry.Flags & 0x20 | v43 & 3;
    v44 = searchInfo;
    if ( searchInfo )
    {
      Scaleform::GFx::AddSearchInfo(searchInfo, "Applying FontMap: \"", pfontName, "\"  mapped to \"", v36, "\"", flags);
      goto LABEL_80;
    }
    v108.pFontName = (const char *)((this->FontMapEntry.Name.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
    v108.FontStyle = flags;
    p_CreatedFonts = &this->CreatedFonts;
    if ( this->CreatedFonts.pTable )
    {
      v46 = -1i64;
      do
        ++v46;
      while ( v36[v46] );
      v47 = Scaleform::String::BernsteinHashFunctionCIS(v36, v46, 0x1505ui64);
      v48 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontManager::FontKey>(
              p_CreatedFonts,
              &v108,
              p_CreatedFonts->pTable->SizeMask & (v47 ^ flags & 3));
      if ( v48 >= 0 )
      {
        v17 = (Scaleform::GFx::Resource **)&p_CreatedFonts->pTable[2 * v48 + 2];
        if ( v17 )
        {
          v49 = *v17;
          if ( ScaleFactor == *(float *)&(*v17)[1].pLib )
            goto LABEL_190;
          v50 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                Scaleform::Memory::pGlobalHeap,
                                                64i64);
          v97 = v50;
          if ( v50 )
          {
            Scaleform::GFx::FontHandle::FontHandle(
              v50,
              this,
              (Scaleform::Render::Font *)(*v17)[2].vfptr,
              pfontName,
              matchFontFlagsa,
              *(Scaleform::GFx::MovieDef **)&(*v17)[2].RefCount.Value);
            v9 = v51;
          }
          else
          {
            v9 = 0i64;
          }
          v94 = v9;
          v9->FontScaleFactor = ScaleFactor;
        }
      }
    }
    v109.pFontName = pfontName;
    v109.FontStyle = flags;
    if ( p_CreatedFonts->pTable )
    {
      v52 = -1i64;
      do
        ++v52;
      while ( pfontName[v52] );
      v53 = Scaleform::String::BernsteinHashFunctionCIS(pfontName, v52, 0x1505ui64);
      v54 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontManager::FontKey>(
              p_CreatedFonts,
              &v109,
              p_CreatedFonts->pTable->SizeMask & (v53 ^ flags & 3));
      if ( v54 >= 0 )
      {
        v17 = (Scaleform::GFx::Resource **)&p_CreatedFonts->pTable[2 * v54 + 2];
        if ( v17 )
          break;
      }
    }
LABEL_77:
    if ( v9 )
      goto LABEL_120;
    v40 = pfontName;
LABEL_79:
    v44 = searchInfo;
LABEL_80:
    v57 = (__int64)pObject;
    if ( pObject )
    {
      v101.pMovieDef = 0i64;
      v101.pFontResource = 0i64;
      v58 = this->pState;
      v59 = &v58->Scaleform::GFx::StateBag;
      if ( !v58 )
        v59 = 0i64;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::FontLib *, Scaleform::GFx::FontLib::FontResult *, const char *, _QWORD, Scaleform::GFx::MovieDefImpl *, Scaleform::GFx::StateBag *, Scaleform::GFx::ResourceWeakLib *))pObject->vfptr[1].__vecDelDtor)(
             pObject,
             &v101,
             v36,
             flags,
             this->pDefImpl,
             v59,
             this->pWeakLib) )
      {
        if ( v39 )
        {
          v110.pFontName = v40;
          v110.FontStyle = v39;
          if ( this->CreatedFonts.pTable )
          {
            v60 = -1i64;
            do
              ++v60;
            while ( v40[v60] );
            v61 = Scaleform::String::BernsteinHashFunctionCIS(v40, v60, 0x1505ui64);
            v62 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontManager::FontKey>(
                    &this->CreatedFonts,
                    &v110,
                    this->CreatedFonts.pTable->SizeMask & (v61 ^ v39 & 3));
            if ( v62 >= 0 )
            {
              v63 = (Scaleform::GFx::Resource **)&this->CreatedFonts.pTable[2 * v62 + 2];
              if ( v63 )
              {
                Scaleform::Render::RenderBuffer::AddRef(*v63);
                v8 = *v63;
                Scaleform::GFx::FontLib::FontResult::~FontResult(&v101);
                goto LABEL_200;
              }
            }
          }
          v9 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                               Scaleform::Memory::pGlobalHeap,
                                               64i64);
          v97 = v9;
          if ( v9 )
          {
            pMovieDef = v101.pMovieDef;
            v65 = this;
            if ( searchInfo )
              v65 = 0i64;
            Scaleform::Render::Text::FontHandle::FontHandle(
              v9,
              v65,
              (Scaleform::GFx::Resource *)v101.pFontResource->pFont.pObject,
              v40,
              v39);
            v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable;
            if ( pMovieDef )
              _InterlockedExchangeAdd(&pMovieDef->RefCount.Value, 1u);
            v9->pSourceMovieDef.pObject = pMovieDef;
          }
          else
          {
            v9 = 0i64;
          }
          v94 = v9;
          v9->FontScaleFactor = ScaleFactor;
          Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontLib: \"", v40, "\" ", v39, " found.");
          goto LABEL_108;
        }
        v9 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             64i64);
        v97 = v9;
        if ( v9 )
        {
          v66 = v101.pMovieDef;
          v67 = this;
          if ( searchInfo )
            v67 = 0i64;
          Scaleform::Render::Text::FontHandle::FontHandle(
            v9,
            v67,
            (Scaleform::GFx::Resource *)v101.pFontResource->pFont.pObject,
            v40,
            0);
          v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable;
          if ( v66 )
            _InterlockedExchangeAdd(&v66->RefCount.Value, 1u);
          v9->pSourceMovieDef.pObject = v66;
        }
        else
        {
          v9 = 0i64;
        }
        v94 = v9;
        v9->FontScaleFactor = ScaleFactor;
        str4 = " found.";
        v69 = searchInfo;
      }
      else
      {
        str4 = " not found.";
        v69 = v44;
      }
      Scaleform::GFx::AddSearchInfo_1(v69, "Searching FontLib: \"", v36, "\" ", flags, str4);
LABEL_108:
      v70 = v101.pMovieDef;
      if ( v101.pMovieDef )
      {
        if ( !_InterlockedDecrement(&v101.pMovieDef->RefCount.Value) )
        {
          pLib = v70->pLib;
          if ( pLib )
          {
            pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v70);
            v70->pLib = 0i64;
          }
          v70->Scaleform::GFx::Resource::vfptr->__vecDelDtor(v70, 1u);
        }
        v9 = v94;
      }
      pFontResource = v101.pFontResource;
      if ( v101.pFontResource )
      {
        if ( !_InterlockedDecrement(&v101.pFontResource->RefCount.Value) )
        {
          v73 = pFontResource->pLib;
          if ( v73 )
          {
            v73->vfptr[1].__vecDelDtor(v73, (unsigned int)pFontResource);
            pFontResource->pLib = 0i64;
          }
          pFontResource->vfptr->__vecDelDtor(pFontResource, 1u);
        }
        v9 = v94;
      }
LABEL_120:
      v57 = (__int64)pObject;
    }
    v13 = searchInfo;
    if ( v93 || !searchInfo )
    {
      if ( !v9 )
        goto LABEL_128;
      goto LABEL_146;
    }
    if ( !v9 )
    {
      if ( !v57 && resSearchInfo.Status == FoundInResourcesNoGlyphs )
        Scaleform::GFx::AddSearchInfo_2(searchInfo, "FontLib not installed.");
LABEL_128:
      if ( pprovider )
      {
        v74 = this->pDefImpl;
        if ( v74 )
          pWeakLib = v74->pLoaderImpl.pObject->pWeakResourceLib.pObject;
        else
          pWeakLib = this->pWeakLib;
        FontResource = Scaleform::GFx::FontResource::CreateFontResource(v36, flags, pprovider, pWeakLib);
        v112 = FontResource;
        if ( FontResource )
        {
          Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontProvider: \"", v36, "\" ", flags, " found.");
          v77 = (Scaleform::Render::Text::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         64i64);
          v9 = (Scaleform::GFx::FontHandle *)v77;
          v97 = (Scaleform::GFx::FontHandle *)v77;
          if ( v77 )
          {
            v78 = this;
            if ( searchInfo )
              v78 = 0i64;
            Scaleform::Render::Text::FontHandle::FontHandle(
              v77,
              v78,
              (Scaleform::GFx::Resource *)FontResource->pFont.pObject,
              pfontName,
              0);
            v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable;
            v9->pSourceMovieDef.pObject = 0i64;
          }
          else
          {
            v9 = 0i64;
          }
          v94 = v9;
          v9->FontScaleFactor = ScaleFactor;
        }
        else
        {
          Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontProvider: \"", v36, "\" ", flags, " not found.");
        }
        if ( FontResource )
        {
          if ( !_InterlockedDecrement(&FontResource->RefCount.Value) )
          {
            v79 = FontResource->pLib;
            if ( v79 )
            {
              v79->vfptr[1].__vecDelDtor(v79, (unsigned int)FontResource);
              FontResource->pLib = 0i64;
            }
            FontResource->vfptr->__vecDelDtor(FontResource, 1u);
          }
          v9 = v94;
        }
      }
LABEL_146:
      if ( v93 )
        goto LABEL_152;
    }
    if ( searchInfo )
    {
      if ( v9 )
        goto LABEL_195;
      if ( !pprovider && resSearchInfo.Status == FoundInResourcesNoGlyphs )
        Scaleform::GFx::AddSearchInfo_2(searchInfo, "FontProvider not installed.");
      goto LABEL_153;
    }
LABEL_152:
    if ( v9 )
    {
LABEL_195:
      v81 = this;
LABEL_196:
      if ( searchInfo )
        searchInfo->Indent -= v95;
      else
        Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Add<Scaleform::GFx::FontHandle *>(
          &v81->CreatedFonts,
          &v81->CreatedFonts,
          &v94);
      v8 = (Scaleform::GFx::Resource *)v9;
      goto LABEL_200;
    }
LABEL_153:
    if ( pObject && (flags & 0x10) != 0 )
    {
      v80 = flags & 0xFFFFFFEF;
      v103 = 0i64;
      v104 = 0i64;
      v81 = this;
      v82 = this->pState;
      v83 = v82 ? (__int64)&v82->Scaleform::GFx::StateBag : 0i64;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::FontLib *, __int64 *, const char *, _QWORD, Scaleform::GFx::MovieDefImpl *, __int64, _QWORD))pObject->vfptr[1].__vecDelDtor)(
             pObject,
             &v103,
             v36,
             v80,
             this->pDefImpl,
             v83,
             0i64) )
      {
        v9 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             64i64);
        v97 = v9;
        if ( v9 )
        {
          v84 = v103;
          v85 = this;
          if ( searchInfo )
            v85 = 0i64;
          Scaleform::Render::Text::FontHandle::FontHandle(
            v9,
            v85,
            *(Scaleform::GFx::Resource **)(v104 + 24),
            pfontName,
            0x10u);
          v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable;
          if ( v84 )
            _InterlockedExchangeAdd((volatile signed __int32 *)(v84 + 8), 1u);
          v9->pSourceMovieDef.pObject = (Scaleform::GFx::MovieDef *)v84;
        }
        else
        {
          v9 = 0i64;
        }
        v94 = v9;
        v9->FontScaleFactor = ScaleFactor;
        v86 = " found.";
      }
      else
      {
        v86 = " not found.";
      }
      Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontLib without [Device] flag: \"", v36, "\" ", v80, v86);
      v87 = v103;
      if ( v103 )
      {
        if ( !_InterlockedDecrement((volatile signed __int32 *)(v103 + 8)) )
        {
          v88 = *(_QWORD *)(v87 + 16);
          if ( v88 )
          {
            (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v88 + 8i64))(v88, v87);
            *(_QWORD *)(v87 + 16) = 0i64;
          }
          (**(void (__fastcall ***)(__int64, __int64))v87)(v87, 1i64);
        }
        v9 = v94;
      }
      v89 = v104;
      if ( v104 )
      {
        if ( !_InterlockedDecrement((volatile signed __int32 *)(v104 + 8)) )
        {
          v90 = *(_QWORD *)(v89 + 16);
          if ( v90 )
          {
            (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v90 + 8i64))(v90, v89);
            *(_QWORD *)(v89 + 16) = 0i64;
          }
          (**(void (__fastcall ***)(__int64, __int64))v89)(v89, 1i64);
        }
        v9 = v94;
      }
      if ( v9 )
        goto LABEL_196;
    }
    if ( (matchFontFlagsa & 0x10) == 0 )
    {
      if ( searchInfo )
        searchInfo->Indent -= v95;
      goto LABEL_200;
    }
    Scaleform::GFx::AddSearchInfo_2(searchInfo, "Searching again without [Device] flag:");
    v5 = matchFontFlagsa & 0xFFFFFFEF;
    matchFontFlagsa = v5;
    key.FontStyle = v5;
    pprovider = 0i64;
    pObject = 0i64;
    v93 = 1;
    v6 = pfontName;
    v7 = this;
    v11 = v95;
    p_resSearchInfo = v99;
  }
  v49 = *v17;
  if ( ScaleFactor != *(float *)&(*v17)[1].pLib )
  {
    v55 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                          Scaleform::Memory::pGlobalHeap,
                                          64i64);
    v97 = v55;
    if ( v55 )
    {
      Scaleform::GFx::FontHandle::FontHandle(
        v55,
        this,
        (Scaleform::Render::Font *)(*v17)[2].vfptr,
        pfontName,
        matchFontFlagsa,
        *(Scaleform::GFx::MovieDef **)&(*v17)[2].RefCount.Value);
      v9 = v56;
    }
    else
    {
      v9 = 0i64;
    }
    v94 = v9;
    v9->FontScaleFactor = ScaleFactor;
    goto LABEL_77;
  }
LABEL_190:
  v18 = v49;
LABEL_191:
  Scaleform::Render::RenderBuffer::AddRef(v18);
  v8 = *v17;
LABEL_200:
  if ( !_InterlockedDecrement((volatile signed __int32 *)((resSearchInfo.ImportFoundUrl.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::~HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>(&resSearchInfo.ImportSearchUrls);
  return v8;
}

// File Line: 645
// RVA: 0x8BF6C0
Scaleform::GFx::FontHandle *__fastcall Scaleform::GFx::FontManager::CreateFontHandle(
        Scaleform::GFx::FontManager *this,
        const char *pfontName,
        unsigned int matchFontFlags,
        bool allowListOfFonts,
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  const char *v6; // rdi
  Scaleform::GFx::FontHandle *FontHandleFromName; // rbp
  char *v10; // rax
  char *v11; // rsi
  signed __int64 v12; // rbx
  char *v13; // rdx
  char _Dst[152]; // [rsp+20h] [rbp-98h] BYREF

  v6 = pfontName;
  if ( !allowListOfFonts )
    return Scaleform::GFx::FontManager::CreateFontHandleFromName(this, pfontName, matchFontFlags, searchInfo);
  FontHandleFromName = 0i64;
  do
  {
    v10 = strchr(v6, 44);
    v11 = v10;
    if ( v10 )
    {
      v12 = v10 - v6;
      if ( (unsigned __int64)(v10 - v6) > 0x7F )
        continue;
      strncpy_s(_Dst, 0x7Fui64, v6, v10 - v6);
      _Dst[v12] = 0;
      v6 += v12 + 1;
      v13 = _Dst;
    }
    else
    {
      v13 = (char *)v6;
    }
    FontHandleFromName = Scaleform::GFx::FontManager::CreateFontHandleFromName(this, v13, matchFontFlags, searchInfo);
    if ( FontHandleFromName )
      return FontHandleFromName;
  }
  while ( v11 );
  return FontHandleFromName;
}

// File Line: 683
// RVA: 0x8BF7C0
Scaleform::GFx::FontHandle *__fastcall Scaleform::GFx::FontManager::CreateFontHandleFromName(
        Scaleform::GFx::FontManager *this,
        const char *pfontName,
        unsigned int matchFontFlags,
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  char *pData; // r15
  Scaleform::GFx::FontHandle *Handle; // rbx
  Scaleform::GFx::FontResource *v10; // rbp
  Scaleform::GFx::FontHandle *v11; // rax
  Scaleform::GFx::FontHandle *v12; // rax
  Scaleform::GFx::FontResource *v13; // rbp
  Scaleform::Render::Text::FontHandle *v14; // rax
  Scaleform::GFx::FontManager *v15; // rdx
  Scaleform::GFx::FontHandle *key; // [rsp+50h] [rbp-78h] BYREF
  Scaleform::GFx::FontResource *ppfoundFont[3]; // [rsp+58h] [rbp-70h] BYREF
  Scaleform::StringBuffer v19; // [rsp+70h] [rbp-58h] BYREF
  int Indent; // [rsp+E8h] [rbp+20h]

  ppfoundFont[1] = (Scaleform::GFx::FontResource *)-2i64;
  Indent = 0;
  pData = &customCaption;
  if ( searchInfo )
  {
    Indent = searchInfo->Indent;
    Scaleform::GFx::AddSearchInfo_1(
      searchInfo,
      "Searching for font: \"",
      pfontName,
      "\" ",
      matchFontFlags,
      &customCaption);
  }
  ppfoundFont[0] = 0i64;
  Handle = (Scaleform::GFx::FontHandle *)Scaleform::GFx::FontManager::FindOrCreateHandle(
                                           this,
                                           pfontName,
                                           matchFontFlags,
                                           ppfoundFont,
                                           searchInfo);
  if ( !Handle && (matchFontFlags & 3) != 0 )
  {
    if ( searchInfo )
    {
      ++searchInfo->Indent;
      Scaleform::GFx::AddSearchInfo_1(
        searchInfo,
        "Searching for font: \"",
        pfontName,
        "\" ",
        matchFontFlags & 0xFFFFFFFC,
        &customCaption);
    }
    v10 = (Scaleform::GFx::FontResource *)Scaleform::GFx::FontManager::FindOrCreateHandle(
                                            this,
                                            pfontName,
                                            matchFontFlags & 0xFFFFFFFC,
                                            0i64,
                                            searchInfo);
    ppfoundFont[2] = v10;
    if ( v10 )
    {
      v11 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                            Scaleform::Memory::pGlobalHeap,
                                            64i64);
      key = v11;
      if ( v11 )
      {
        Scaleform::GFx::FontHandle::FontHandle(v11, (Scaleform::GFx::FontHandle *)v10);
        Handle = v12;
      }
      else
      {
        Handle = 0i64;
      }
      key = Handle;
      Handle->OverridenFontFlags |= matchFontFlags & 3;
      if ( searchInfo )
        Scaleform::GFx::AddSearchInfo_0(
          searchInfo,
          "Font \"",
          pfontName,
          "\" ",
          matchFontFlags,
          " will be generated from \"",
          pfontName,
          "\"",
          matchFontFlags & 0xFFFFFFFC);
      else
        Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Add<Scaleform::GFx::FontHandle *>(
          &this->CreatedFonts,
          &this->CreatedFonts,
          &key);
    }
    if ( v10 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
    pData = &customCaption;
  }
  if ( searchInfo )
    searchInfo->Indent = Indent;
  if ( !Handle )
  {
    v13 = ppfoundFont[0];
    if ( !ppfoundFont[0] )
      goto LABEL_33;
    if ( searchInfo )
    {
      Scaleform::StringBuffer::StringBuffer(&v19, Scaleform::Memory::pGlobalHeap);
      Scaleform::StringBuffer::AppendString(&v19, "Empty font: \"", -1i64);
      Scaleform::StringBuffer::AppendString(&v19, pfontName, -1i64);
      Scaleform::StringBuffer::AppendString(&v19, "\" is created", -1i64);
      if ( v19.pData )
        pData = v19.pData;
      Scaleform::GFx::AddSearchInfo_2(searchInfo, pData);
      Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v19);
    }
    v14 = (Scaleform::Render::Text::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   64i64);
    Handle = (Scaleform::GFx::FontHandle *)v14;
    if ( v14 )
    {
      v15 = this;
      if ( searchInfo )
        v15 = 0i64;
      Scaleform::Render::Text::FontHandle::FontHandle(
        v14,
        v15,
        (Scaleform::GFx::Resource *)v13->pFont.pObject,
        pfontName,
        0);
      Handle->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable;
      Handle->pSourceMovieDef.pObject = 0i64;
    }
    else
    {
      Handle = 0i64;
    }
    key = Handle;
    if ( !searchInfo )
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Add<Scaleform::GFx::FontHandle *>(
        &this->CreatedFonts,
        &this->CreatedFonts,
        &key);
    if ( !Handle )
LABEL_33:
      Scaleform::GFx::AddSearchInfo_2(searchInfo, "Font not found.");
  }
  return Handle;
}

// File Line: 767
// RVA: 0x8D73D0
Scaleform::GFx::FontHandle *__fastcall Scaleform::GFx::FontManager::GetEmptyFont(Scaleform::GFx::FontManager *this)
{
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)this->pEmptyFont.pObject);
  return this->pEmptyFont.pObject;
}

// File Line: 773
// RVA: 0x8BB220
void __fastcall Scaleform::GFx::FontManager::CleanCache(Scaleform::GFx::FontManager *this)
{
  Scaleform::HashSetLH<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *p_CreatedFonts; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *pTable; // rcx
  unsigned __int64 v3; // rax
  Scaleform::HashSetLH<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v4; // r9
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v6; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v7; // rdx
  unsigned __int64 v8; // r8
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // rdx

  p_CreatedFonts = &this->CreatedFonts;
  pTable = this->CreatedFonts.pTable;
  v3 = 0i64;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v6 = pTable + 1;
    do
    {
      if ( v6->EntryCount != -2i64 )
        break;
      ++v3;
      v6 += 2;
    }
    while ( v3 <= SizeMask );
    v4 = p_CreatedFonts;
  }
  else
  {
    v4 = 0i64;
  }
  while ( v4 )
  {
    v7 = v4->pTable;
    if ( !v4->pTable || (signed __int64)v3 > (signed __int64)v7->SizeMask )
      break;
    *(_QWORD *)(v7[2 * v3 + 2].EntryCount + 16) = 0i64;
    v8 = v4->pTable->SizeMask;
    if ( (__int64)v3 <= (__int64)v8 && ++v3 <= v8 )
    {
      v9 = &v4->pTable[2 * v3 + 1];
      do
      {
        if ( v9->EntryCount != -2i64 )
          break;
        ++v3;
        v9 += 2;
      }
      while ( v3 <= v8 );
    }
  }
  if ( p_CreatedFonts->pTable )
  {
    v10 = 0i64;
    v11 = p_CreatedFonts->pTable->SizeMask + 1;
    do
    {
      if ( p_CreatedFonts->pTable[v10 + 1].EntryCount != -2i64 )
        p_CreatedFonts->pTable[v10 + 1].EntryCount = -2i64;
      v10 += 2i64;
      --v11;
    }
    while ( v11 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_CreatedFonts->pTable);
    p_CreatedFonts->pTable = 0i64;
  }
}

// File Line: 783
// RVA: 0x8BB310
void __fastcall Scaleform::GFx::FontManager::CleanCacheFor(
        Scaleform::GFx::FontManager *this,
        Scaleform::GFx::MovieDefImpl *pdefImpl)
{
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *pTable; // rax
  Scaleform::HashSetLH<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *p_CreatedFonts; // r8
  unsigned __int64 Index; // rcx
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v7; // rax
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > v8; // rax
  unsigned __int64 EntryCount; // r9
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > v10; // r9
  unsigned __int64 v11; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v12; // rax
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::Iterator v13; // [rsp+20h] [rbp-18h] BYREF

  pTable = this->CreatedFonts.pTable;
  p_CreatedFonts = &this->CreatedFonts;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    Index = 0i64;
    v7 = pTable + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++Index;
      v7 += 2;
    }
    while ( Index <= SizeMask );
  }
  else
  {
    p_CreatedFonts = 0i64;
    Index = 0i64;
  }
  v13.Index = Index;
  v13.pHash = p_CreatedFonts;
  while ( p_CreatedFonts )
  {
    v8.pTable = p_CreatedFonts->pTable;
    if ( !p_CreatedFonts->pTable || (signed __int64)Index > (signed __int64)v8.pTable->SizeMask )
      break;
    EntryCount = v8.pTable[2 * Index + 2].EntryCount;
    if ( *(Scaleform::GFx::MovieDefImpl **)(EntryCount + 56) == pdefImpl )
    {
      *(_QWORD *)(EntryCount + 16) = 0i64;
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Iterator::RemoveAlt<Scaleform::GFx::FontManager::NodePtr>(
        &v13,
        (Scaleform::GFx::FontManager::NodePtr *)&p_CreatedFonts->pTable[2 * Index + 2]);
      Index = v13.Index;
      p_CreatedFonts = (Scaleform::HashSetLH<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)v13.pHash;
    }
    v10.pTable = p_CreatedFonts->pTable;
    v11 = p_CreatedFonts->pTable->SizeMask;
    if ( (__int64)Index <= (__int64)v11 )
    {
      v13.Index = ++Index;
      if ( Index <= v11 )
      {
        v12 = &v10.pTable[2 * Index + 1];
        do
        {
          if ( v12->EntryCount != -2i64 )
            break;
          ++Index;
          v12 += 2;
          v13.Index = Index;
        }
        while ( Index <= v11 );
      }
    }
  }
}

