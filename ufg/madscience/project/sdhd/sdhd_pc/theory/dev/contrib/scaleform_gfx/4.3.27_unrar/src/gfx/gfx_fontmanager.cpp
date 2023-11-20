// File Line: 25
// RVA: 0x8DE240
Scaleform::GFx::State *__fastcall Scaleform::GFx::FontManagerStates::GetStateAddRef(Scaleform::GFx::FontManagerStates *this, Scaleform::GFx::State::StateType state)
{
  Scaleform::GFx::FontManagerStates *v2; // rbx
  Scaleform::GFx::Resource *v3; // rcx
  Scaleform::GFx::State *result; // rax
  Scaleform::GFx::StateBagVtbl *v5; // rcx
  Scaleform::GFx::Resource *v6; // rcx
  Scaleform::GFx::Resource *v7; // rcx

  v2 = this;
  switch ( state )
  {
    case 20:
      v3 = *(Scaleform::GFx::Resource **)&this->RefCount;
      if ( v3 )
        Scaleform::Render::RenderBuffer::AddRef(v3);
      result = *(Scaleform::GFx::State **)&v2->RefCount;
      break;
    case 23:
      v5 = this->vfptr;
      if ( v5 )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v5);
      result = (Scaleform::GFx::State *)v2->vfptr;
      break;
    case 22:
      v6 = (Scaleform::GFx::Resource *)this->pFontLib.pObject;
      if ( v6 )
        Scaleform::Render::RenderBuffer::AddRef(v6);
      result = (Scaleform::GFx::State *)&v2->pFontLib.pObject->vfptr;
      break;
    case 1:
      v7 = (Scaleform::GFx::Resource *)this->pFontMap.pObject;
      if ( v7 )
        Scaleform::Render::RenderBuffer::AddRef(v7);
      result = (Scaleform::GFx::State *)&v2->pFontMap.pObject->vfptr;
      break;
    default:
      result = (Scaleform::GFx::State *)((__int64 (*)(void))this->pFontProvider.pObject->vfptr[3].__vecDelDtor)();
      break;
  }
  return result;
}

// File Line: 56
// RVA: 0x8BB050
__int64 __fastcall Scaleform::GFx::FontManagerStates::CheckStateChange(Scaleform::GFx::FontManagerStates *this, Scaleform::GFx::FontLib *pfontLib, Scaleform::GFx::FontMap *pfontMap, Scaleform::GFx::FontProvider *pfontProvider, Scaleform::GFx::Translator *ptranslator)
{
  unsigned __int8 v5; // di
  Scaleform::GFx::Resource *v6; // rsi
  Scaleform::GFx::Resource *v7; // rbp
  Scaleform::GFx::FontLib *v8; // r14
  Scaleform::GFx::FontManagerStates *v9; // rbx
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::Render::RenderBuffer *v13; // rcx

  v5 = 0;
  v6 = (Scaleform::GFx::Resource *)pfontProvider;
  v7 = (Scaleform::GFx::Resource *)pfontMap;
  v8 = pfontLib;
  v9 = this;
  if ( this->pFontLib.pObject != pfontLib )
  {
    v5 = 1;
    if ( pfontLib )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pfontLib);
    v10 = (Scaleform::Render::RenderBuffer *)v9->pFontLib.pObject;
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    v9->pFontLib.pObject = v8;
  }
  if ( (Scaleform::GFx::Resource *)v9->pFontMap.pObject != v7 )
  {
    v5 |= 2u;
    if ( v7 )
      Scaleform::Render::RenderBuffer::AddRef(v7);
    v11 = (Scaleform::Render::RenderBuffer *)v9->pFontMap.pObject;
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    v9->pFontMap.pObject = (Scaleform::GFx::FontMap *)v7;
  }
  if ( (Scaleform::GFx::Resource *)v9->pFontProvider.pObject != v6 )
  {
    v5 |= 4u;
    if ( v6 )
      Scaleform::Render::RenderBuffer::AddRef(v6);
    v12 = (Scaleform::Render::RenderBuffer *)v9->pFontProvider.pObject;
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    v9->pFontProvider.pObject = (Scaleform::GFx::FontProvider *)v6;
  }
  if ( v9->pTranslator.pObject != ptranslator )
  {
    v5 |= 8u;
    if ( ptranslator )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)ptranslator);
    v13 = (Scaleform::Render::RenderBuffer *)v9->pTranslator.pObject;
    if ( v13 )
      Scaleform::RefCountImpl::Release(v13);
    v9->pTranslator.pObject = ptranslator;
  }
  return v5;
}

// File Line: 88
// RVA: 0x896A00
void __fastcall Scaleform::GFx::FontManager::FontManager(Scaleform::GFx::FontManager *this, Scaleform::GFx::MovieImpl *movie, Scaleform::GFx::MovieDefImpl *pdefImpl, Scaleform::GFx::FontManagerStates *pstate)
{
  Scaleform::GFx::FontManagerStates *v4; // rbp
  Scaleform::GFx::MovieDefImpl *v5; // rsi
  Scaleform::GFx::MovieImpl *v6; // rdi
  Scaleform::GFx::FontManager *v7; // r14
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::MovieDataDef>,2,Scaleform::ArrayDefaultPolicy> *v8; // rax
  Scaleform::GFx::FontMap::MapEntry *v9; // rbx

  v4 = pstate;
  v5 = pdefImpl;
  v6 = movie;
  v7 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::FontManagerBase,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontManagerBase::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontManager::`vftable';
  this->CreatedFonts.pTable = 0i64;
  v8 = &this->FontMovies;
  v8->Data.Data = 0i64;
  v8->Data.Size = 0i64;
  v8->Data.Policy.Capacity = 0i64;
  this->pEmptyFont.pObject = 0i64;
  v9 = &this->FontMapEntry;
  Scaleform::String::String(&this->FontMapEntry.Name);
  v9->ScaleFactor = 1.0;
  v9->Flags = 16;
  v7->pMovie = v6;
  v7->pDefImpl = v5;
  v7->pWeakLib = 0i64;
  v7->pState = v4;
  Scaleform::GFx::FontManager::commonInit(v7);
}

// File Line: 98
// RVA: 0x896AF0
void __fastcall Scaleform::GFx::FontManager::FontManager(Scaleform::GFx::FontManager *this, Scaleform::GFx::ResourceWeakLib *pweakLib, Scaleform::GFx::FontManagerStates *pstate)
{
  Scaleform::GFx::FontManagerStates *v3; // rsi
  Scaleform::GFx::ResourceWeakLib *v4; // rdi
  Scaleform::GFx::FontManager *v5; // r14
  Scaleform::GFx::FontMap::MapEntry *v6; // rbx
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::MovieDataDef>,2,Scaleform::ArrayDefaultPolicy> *v7; // [rsp+68h] [rbp+10h]

  v3 = pstate;
  v4 = pweakLib;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::FontManagerBase,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontManagerBase::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontManager::`vftable';
  this->CreatedFonts.pTable = 0i64;
  v7 = &this->FontMovies;
  *(_OWORD *)&v7->Data.Data = 0ui64;
  v7->Data.Policy.Capacity = 0i64;
  this->pEmptyFont.pObject = 0i64;
  v6 = &this->FontMapEntry;
  Scaleform::String::String(&this->FontMapEntry.Name);
  v6->ScaleFactor = 1.0;
  v6->Flags = 16;
  v5->pMovie = 0i64;
  v5->pDefImpl = 0i64;
  v5->pWeakLib = v4;
  v5->pState = v3;
  Scaleform::GFx::FontManager::commonInit(v5);
}

// File Line: 107
// RVA: 0x91E2B0
void __fastcall Scaleform::GFx::FontManager::commonInit(Scaleform::GFx::FontManager *this)
{
  Scaleform::GFx::FontManager *v1; // rbp
  Scaleform::GFx::FontData *v2; // rax
  Scaleform::Render::Font *v3; // rax
  Scaleform::Render::Font *v4; // rsi
  Scaleform::GFx::FontResource *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx
  __int64 v8; // rdi
  Scaleform::GFx::Resource *v9; // r14
  Scaleform::Render::RenderBuffer *v10; // rcx
  __int64 v11; // rcx
  int v12; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::FontData *v13; // [rsp+80h] [rbp+18h]
  Scaleform::Render::Font *v14; // [rsp+88h] [rbp+20h]

  v1 = this;
  v12 = 75;
  v2 = (Scaleform::GFx::FontData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::FontManager *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
                                         v1,
                                         64ui64,
                                         (Scaleform::AllocInfo *)&v13);
  if ( v5 )
  {
    Scaleform::GFx::FontResource::FontResource(v5, v4, 0i64);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
         Scaleform::Memory::pGlobalHeap,
         64i64);
  if ( v8 )
  {
    v9 = *(Scaleform::GFx::Resource **)(v7 + 24);
    *(_QWORD *)v8 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v8 + 8) = 1;
    *(_QWORD *)v8 = &Scaleform::RefCountImpl::`vftable';
    *(_QWORD *)v8 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable';
    *(_QWORD *)v8 = &Scaleform::RefCountBase<Scaleform::Render::Text::FontHandle,74>::`vftable';
    *(_QWORD *)v8 = &Scaleform::Render::Text::FontHandle::`vftable';
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_DWORD *)(v8 + 24) = 0;
    Scaleform::StringLH::StringLH((Scaleform::StringLH *)(v8 + 32));
    *(_DWORD *)(v8 + 40) = 1065353216;
    if ( v9 )
      Scaleform::Render::RenderBuffer::AddRef(v9);
    *(_QWORD *)(v8 + 48) = v9;
    *(_QWORD *)v8 = &Scaleform::GFx::FontHandle::`vftable';
    *(_QWORD *)(v8 + 56) = 0i64;
  }
  else
  {
    v8 = 0i64;
  }
  v10 = (Scaleform::Render::RenderBuffer *)v1->pEmptyFont.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v1->pEmptyFont.pObject = (Scaleform::GFx::FontHandle *)v8;
  if ( v7 && !_InterlockedDecrement((volatile signed __int32 *)(v7 + 8)) )
  {
    v11 = *(_QWORD *)(v7 + 16);
    if ( v11 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 8i64))(v11, v7);
      *(_QWORD *)(v7 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, signed __int64))v7)(v7, 1i64);
  }
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v4);
}

// File Line: 114
// RVA: 0x8A4970
void __fastcall Scaleform::GFx::FontManager::~FontManager(Scaleform::GFx::FontManager *this)
{
  Scaleform::GFx::FontManager *v1; // rdi
  Scaleform::Render::RenderBuffer *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontManager::`vftable';
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->FontMapEntry.Name.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v2 = (Scaleform::Render::RenderBuffer *)v1->pEmptyFont.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>>::DestructArray(
    (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)v1->FontMovies.Data.Data,
    v1->FontMovies.Data.Size);
  if ( v1->FontMovies.Data.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::HashSet<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::~HashSet<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>((Scaleform::HashSet<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&v1->CreatedFonts.pTable);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontManagerBase::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
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
  if ( matchFontFlags & 0x10 )
  {
    if ( v2 == 3 )
    {
      result = off_1420B1208;
    }
    else if ( matchFontFlags & 2 )
    {
      result = off_1420B11F8[0];
    }
    else
    {
      result = off_1420B11F0[0];
      if ( matchFontFlags & 1 )
        result = off_1420B1200[0];
    }
  }
  else if ( v2 == 3 )
  {
    result = off_1420B11E8[0];
  }
  else if ( matchFontFlags & 2 )
  {
    result = off_1420B11D8[0];
  }
  else
  {
    result = (char *)StrFlags[0];
    if ( matchFontFlags & 1 )
      result = off_1420B11E0[0];
  }
  return result;
}

// File Line: 167
// RVA: 0x8B2440
void __fastcall Scaleform::GFx::AddSearchInfo_2(Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo, const char *line)
{
  const char *v2; // rbp
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v3; // rbx
  int i; // edi
  Scaleform::String v5; // [rsp+50h] [rbp+8h]

  if ( psearchInfo )
  {
    v2 = line;
    v3 = psearchInfo;
    Scaleform::String::String(&v5, "   ");
    for ( i = 0; i < v3->Indent; ++i )
      Scaleform::StringBuffer::AppendString(
        &v3->Info,
        (const char *)((v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        *(_QWORD *)(v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
    Scaleform::StringBuffer::AppendString(&v3->Info, v2, -1i64);
    Scaleform::StringBuffer::AppendString(&v3->Info, "\n", -1i64);
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 179
// RVA: 0x8B2510
void __fastcall Scaleform::GFx::AddSearchInfo_3(Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo, const char *pfontname, unsigned int flags, bool fontlib_installed, Scaleform::GFx::MovieDefImpl::SearchInfo *resSearchInfo)
{
  bool v5; // bl
  unsigned int v6; // er12
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v7; // r15
  Scaleform::GFx::MovieDefImpl::SearchInfo *v8; // r13
  Scaleform::GFx::MovieDefImpl::SearchInfo::SearchStatus v9; // eax
  Scaleform::MsgFormat *v10; // rcx
  Scaleform::HashSet<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> > *v11; // r14
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *v12; // rax
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *v13; // rdx
  unsigned __int64 v14; // rax
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *v15; // rcx
  signed __int64 v16; // rbx
  __int64 v17; // rdi
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *v18; // rdx
  signed __int64 v19; // rcx
  unsigned __int64 v20; // rax
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *v21; // rcx
  Scaleform::String *v22; // rax
  Scaleform::String *v23; // rax
  Scaleform::String *v24; // rax
  unsigned __int64 v25; // rdx
  unsigned __int64 v26; // rdx
  unsigned __int64 v27; // rdx
  unsigned __int64 v28; // rcx
  _QWORD *v29; // rax
  unsigned __int64 v30; // rdx
  char *v31; // rax
  __int128 v32; // [rsp+20h] [rbp-E0h]
  __m128i v33; // [rsp+30h] [rbp-D0h]
  Scaleform::String v34; // [rsp+40h] [rbp-C0h]
  Scaleform::String v35; // [rsp+48h] [rbp-B8h]
  char *v36; // [rsp+50h] [rbp-B0h]
  char *v37; // [rsp+58h] [rbp-A8h]
  char *v38; // [rsp+60h] [rbp-A0h]
  char *v39; // [rsp+68h] [rbp-98h]
  Scaleform::String result; // [rsp+70h] [rbp-90h]
  char *v41; // [rsp+78h] [rbp-88h]
  char *v42; // [rsp+80h] [rbp-80h]
  char *v43; // [rsp+88h] [rbp-78h]
  char *v44; // [rsp+90h] [rbp-70h]
  char *v45; // [rsp+98h] [rbp-68h]
  Scaleform::MsgFormat::Sink v46; // [rsp+A0h] [rbp-60h]
  Scaleform::MsgFormat::Sink v47; // [rsp+B8h] [rbp-48h]
  Scaleform::MsgFormat::Sink v48; // [rsp+D0h] [rbp-30h]
  Scaleform::MsgFormat::Sink r; // [rsp+E8h] [rbp-18h]
  Scaleform::MsgFormat::Sink v50; // [rsp+100h] [rbp+0h]
  Scaleform::MsgFormat::Sink v51; // [rsp+118h] [rbp+18h]
  Scaleform::MsgFormat::Sink v52; // [rsp+130h] [rbp+30h]
  Scaleform::MsgFormat::Sink v53; // [rsp+148h] [rbp+48h]
  Scaleform::MsgFormat::Sink v54; // [rsp+160h] [rbp+60h]
  Scaleform::MsgFormat::Sink v55; // [rsp+178h] [rbp+78h]
  __int64 v56; // [rsp+190h] [rbp+90h]
  char line; // [rsp+1A0h] [rbp+A0h]
  Scaleform::MsgFormat v58; // [rsp+5A0h] [rbp+4A0h]
  Scaleform::MsgFormat v59; // [rsp+9A0h] [rbp+8A0h]
  Scaleform::MsgFormat v60; // [rsp+DA0h] [rbp+CA0h]
  Scaleform::MsgFormat v61; // [rsp+11A0h] [rbp+10A0h]
  Scaleform::MsgFormat v62; // [rsp+15A0h] [rbp+14A0h]
  Scaleform::MsgFormat v63; // [rsp+19A0h] [rbp+18A0h]
  Scaleform::MsgFormat v64; // [rsp+1DA0h] [rbp+1CA0h]
  Scaleform::MsgFormat v65; // [rsp+21A0h] [rbp+20A0h]
  Scaleform::MsgFormat v66; // [rsp+25A0h] [rbp+24A0h]
  Scaleform::MsgFormat v67; // [rsp+29A0h] [rbp+28A0h]
  Scaleform::String v68; // [rsp+2DE0h] [rbp+2CE0h]
  char *v; // [rsp+2DE8h] [rbp+2CE8h]

  if ( psearchInfo )
  {
    v = (char *)pfontname;
    v56 = -2i64;
    v5 = fontlib_installed;
    v6 = flags;
    v7 = psearchInfo;
    v8 = resSearchInfo;
    v9 = resSearchInfo->Status;
    if ( resSearchInfo->Status == 1 )
    {
      v42 = (char *)Scaleform::GFx::FontFlagsToString(flags);
      r.Type = 2;
      r.SinkData.pStr = (Scaleform::String *)&line;
      r.SinkData.DataPtr.Size = 1024i64;
      Scaleform::MsgFormat::MsgFormat(&v65, &r);
      Scaleform::MsgFormat::Parse(&v65, "Movie resource: \"{0}\" {1} found.");
      Scaleform::MsgFormat::FormatD1<char const *>(&v65, (const char *const *)&v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v65, (const char *const *)&v42);
      Scaleform::MsgFormat::FinishFormatD(&v65);
      v10 = &v65;
    }
    else if ( v9 == 3 )
    {
      v43 = (char *)Scaleform::GFx::FontFlagsToString(flags);
      v48.Type = 2;
      v48.SinkData.pStr = (Scaleform::String *)&line;
      v48.SinkData.DataPtr.Size = 1024i64;
      Scaleform::MsgFormat::MsgFormat(&v60, &v48);
      Scaleform::MsgFormat::Parse(&v60, "Movie resource: \"{0}\" {1} found, requires faux");
      Scaleform::MsgFormat::FormatD1<char const *>(&v60, (const char *const *)&v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v60, (const char *const *)&v43);
      Scaleform::MsgFormat::FinishFormatD(&v60);
      v10 = &v60;
    }
    else if ( v9 == 2 )
    {
      v45 = (char *)Scaleform::GFx::FontFlagsToString(flags);
      v46.Type = 2;
      v46.SinkData.pStr = (Scaleform::String *)&line;
      v46.SinkData.DataPtr.Size = 1024i64;
      Scaleform::MsgFormat::MsgFormat(&v64, &v46);
      Scaleform::MsgFormat::Parse(&v64, "Movie resource: \"{0}\" {1} ref found, requires FontLib/Map/Provider.");
      Scaleform::MsgFormat::FormatD1<char const *>(&v64, (const char *const *)&v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v64, (const char *const *)&v45);
      Scaleform::MsgFormat::FinishFormatD(&v64);
      v10 = &v64;
    }
    else
    {
      v36 = (char *)Scaleform::GFx::FontFlagsToString(flags);
      v51.Type = 2;
      v51.SinkData.pStr = (Scaleform::String *)&line;
      v51.SinkData.DataPtr.Size = 1024i64;
      Scaleform::MsgFormat::MsgFormat(&v62, &v51);
      Scaleform::MsgFormat::Parse(&v62, "Movie resource: \"{0}\" {1} not found.");
      Scaleform::MsgFormat::FormatD1<char const *>(&v62, (const char *const *)&v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v62, (const char *const *)&v36);
      Scaleform::MsgFormat::FinishFormatD(&v62);
      Scaleform::MsgFormat::~MsgFormat(&v62);
      Scaleform::GFx::AddSearchInfo_2(v7, &line);
      if ( v8->Status == 4 )
        goto LABEL_54;
      if ( v8->Status != 5 )
      {
        v38 = (char *)Scaleform::GFx::FontFlagsToString(v6);
        v47.Type = 2;
        v47.SinkData.pStr = (Scaleform::String *)&line;
        v47.SinkData.DataPtr.Size = 1024i64;
        Scaleform::MsgFormat::MsgFormat(&v59, &v47);
        Scaleform::MsgFormat::Parse(&v59, "Imports       : \"{0}\" {1} not found.");
        Scaleform::MsgFormat::FormatD1<char const *>(&v59, (const char *const *)&v);
        Scaleform::MsgFormat::FormatD1<char const *>(&v59, (const char *const *)&v38);
        Scaleform::MsgFormat::FinishFormatD(&v59);
        Scaleform::MsgFormat::~MsgFormat(&v59);
        Scaleform::GFx::AddSearchInfo_2(v7, &line);
        v11 = &v8->ImportSearchUrls;
        v12 = v8->ImportSearchUrls.pTable;
        if ( v12 && v12->EntryCount )
        {
          Scaleform::String::String(&v68);
          v13 = v11->pTable;
          if ( v11->pTable )
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
            v33.m128i_i64[0] = (__int64)&v8->ImportSearchUrls;
            v33.m128i_i64[1] = v14;
          }
          else
          {
            v33 = 0ui64;
          }
          _mm_store_si128((__m128i *)&v32, v33);
          v16 = *((_QWORD *)&v32 + 1);
          v17 = v32;
          while ( v17 && *(_QWORD *)v17 && v16 <= *(_QWORD *)(*(_QWORD *)v17 + 8i64) )
          {
            v18 = v11->pTable;
            if ( v11->pTable )
            {
              v20 = 0i64;
              v21 = v18 + 1;
              do
              {
                if ( v21->EntryCount != -2i64 )
                  break;
                ++v20;
                v21 = (Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *)((char *)v21 + 24);
              }
              while ( v20 <= v18->SizeMask );
              v19 = (signed __int64)&v8->ImportSearchUrls;
            }
            else
            {
              v19 = 0i64;
              v20 = 0i64;
            }
            *((_QWORD *)&v32 + 1) = v20;
            *(_QWORD *)&v32 = v19;
            if ( v17 != v19 || v16 != v20 )
              Scaleform::String::AppendString(&v68, ", ", -1i64);
            Scaleform::String::String(&v35, "\"");
            v23 = Scaleform::String::operator+(
                    v22,
                    &result,
                    (Scaleform::String *)(*(_QWORD *)v17 + 8 * (v16 + 2 * (v16 + 2))));
            v24 = Scaleform::String::operator+(v23, &v34, "\"");
            Scaleform::String::operator+=(&v68, v24);
            v25 = v34.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v34.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                Scaleform::Memory::pGlobalHeap,
                v25);
            v26 = result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
            if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                Scaleform::Memory::pGlobalHeap,
                v26);
            v27 = v35.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v35.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                Scaleform::Memory::pGlobalHeap,
                v27);
            v28 = *(_QWORD *)(*(_QWORD *)v17 + 8i64);
            if ( v16 <= (signed __int64)v28 && ++v16 <= v28 )
            {
              v29 = (_QWORD *)(*(_QWORD *)v17 + 8 * (v16 + 2 * (v16 + 1)));
              do
              {
                if ( *v29 != -2i64 )
                  break;
                ++v16;
                v29 += 3;
              }
              while ( v16 <= v28 );
            }
          }
          v50.Type = 2;
          v50.SinkData.pStr = (Scaleform::String *)&line;
          v50.SinkData.DataPtr.Size = 1024i64;
          Scaleform::MsgFormat::MsgFormat(&v67, &v50);
          Scaleform::MsgFormat::Parse(&v67, "              : {0}.");
          Scaleform::MsgFormat::FormatD1<Scaleform::String>(&v67, &v68);
          Scaleform::MsgFormat::FinishFormatD(&v67);
          Scaleform::MsgFormat::~MsgFormat(&v67);
          Scaleform::GFx::AddSearchInfo_2(v7, &line);
          v30 = v68.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
          if ( _InterlockedExchangeAdd(
                 (volatile signed __int32 *)((v68.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
                 0xFFFFFFFF) == 1 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
              Scaleform::Memory::pGlobalHeap,
              v30);
        }
        v31 = (char *)Scaleform::GFx::FontFlagsToString(v6);
        if ( v8->Status == 6 )
        {
          v37 = v31;
          v52.Type = 2;
          v52.SinkData.pStr = (Scaleform::String *)&line;
          v52.SinkData.DataPtr.Size = 1024i64;
          Scaleform::MsgFormat::MsgFormat(&v61, &v52);
          Scaleform::MsgFormat::Parse(&v61, "Exported      : \"{0}\" {1} found.");
          Scaleform::MsgFormat::FormatD1<char const *>(&v61, (const char *const *)&v);
          Scaleform::MsgFormat::FormatD1<char const *>(&v61, (const char *const *)&v37);
          Scaleform::MsgFormat::FinishFormatD(&v61);
          v10 = &v61;
        }
        else
        {
          v39 = v31;
          v55.Type = 2;
          v55.SinkData.pStr = (Scaleform::String *)&line;
          v55.SinkData.DataPtr.Size = 1024i64;
          Scaleform::MsgFormat::MsgFormat(&v63, &v55);
          Scaleform::MsgFormat::Parse(&v63, "Exported      : \"{0}\" {1} not found.");
          Scaleform::MsgFormat::FormatD1<char const *>(&v63, (const char *const *)&v);
          Scaleform::MsgFormat::FormatD1<char const *>(&v63, (const char *const *)&v39);
          Scaleform::MsgFormat::FinishFormatD(&v63);
          v10 = &v63;
        }
        goto LABEL_51;
      }
      if ( v5 )
      {
        v44 = (char *)Scaleform::GFx::FontFlagsToString(v6);
        v53.Type = 2;
        v53.SinkData.pStr = (Scaleform::String *)&line;
        v53.SinkData.DataPtr.Size = 1024i64;
        Scaleform::MsgFormat::MsgFormat(&v66, &v53);
        Scaleform::MsgFormat::Parse(&v66, "Imports       : \"{0}\" {1} import delegates to font library.");
        Scaleform::MsgFormat::FormatD1<char const *>(&v66, (const char *const *)&v);
        Scaleform::MsgFormat::FormatD1<char const *>(&v66, (const char *const *)&v44);
        Scaleform::MsgFormat::FinishFormatD(&v66);
        v10 = &v66;
      }
      else
      {
LABEL_54:
        v41 = (char *)Scaleform::GFx::FontFlagsToString(v6);
        v54.Type = 2;
        v54.SinkData.pStr = (Scaleform::String *)&line;
        v54.SinkData.DataPtr.Size = 1024i64;
        Scaleform::MsgFormat::MsgFormat(&v58, &v54);
        Scaleform::MsgFormat::Parse(&v58, "Imports       : \"{0}\" {1} found in \"{2}\".");
        Scaleform::MsgFormat::FormatD1<char const *>(&v58, (const char *const *)&v);
        Scaleform::MsgFormat::FormatD1<char const *>(&v58, (const char *const *)&v41);
        Scaleform::MsgFormat::FormatD1<Scaleform::String>(&v58, &v8->ImportFoundUrl);
        Scaleform::MsgFormat::FinishFormatD(&v58);
        v10 = &v58;
      }
    }
LABEL_51:
    Scaleform::MsgFormat::~MsgFormat(v10);
    Scaleform::GFx::AddSearchInfo_2(v7, &line);
  }
}

// File Line: 260
// RVA: 0x8B2350
void __fastcall Scaleform::GFx::AddSearchInfo_1(Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo, const char *str1, const char *str2, const char *str3, unsigned int flags, const char *str4)
{
  const char *v6; // rdi
  const char *v7; // rsi
  const char *v8; // rbp
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v9; // rbx
  const char *v10; // rax
  char *v11; // rdx
  Scaleform::StringBuffer v12; // [rsp+28h] [rbp-40h]

  if ( psearchInfo )
  {
    v6 = str3;
    v7 = str2;
    v8 = str1;
    v9 = psearchInfo;
    Scaleform::StringBuffer::StringBuffer(&v12, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v12, v8, -1i64);
    Scaleform::StringBuffer::AppendString(&v12, v7, -1i64);
    Scaleform::StringBuffer::AppendString(&v12, v6, -1i64);
    v10 = Scaleform::GFx::FontFlagsToString(flags);
    Scaleform::StringBuffer::AppendString(&v12, v10, -1i64);
    Scaleform::StringBuffer::AppendString(&v12, str4, -1i64);
    v11 = &customWorldMapCaption;
    if ( v12.pData )
      v11 = v12.pData;
    Scaleform::GFx::AddSearchInfo_2(v9, v11);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v12);
  }
}

// File Line: 273
// RVA: 0x8B2220
void __fastcall Scaleform::GFx::AddSearchInfo_0(Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo, const char *str1, const char *str2, const char *str3, unsigned int flags1, const char *str4, const char *str5, const char *str6, unsigned int flags2)
{
  const char *v9; // rdi
  const char *v10; // rsi
  const char *v11; // rbp
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v12; // rbx
  const char *v13; // rax
  const char *v14; // rax
  char *v15; // rdx
  Scaleform::StringBuffer v16; // [rsp+28h] [rbp-40h]

  if ( psearchInfo )
  {
    v9 = str3;
    v10 = str2;
    v11 = str1;
    v12 = psearchInfo;
    Scaleform::StringBuffer::StringBuffer(&v16, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v16, v11, -1i64);
    Scaleform::StringBuffer::AppendString(&v16, v10, -1i64);
    Scaleform::StringBuffer::AppendString(&v16, v9, -1i64);
    v13 = Scaleform::GFx::FontFlagsToString(flags1);
    Scaleform::StringBuffer::AppendString(&v16, v13, -1i64);
    Scaleform::StringBuffer::AppendString(&v16, str4, -1i64);
    Scaleform::StringBuffer::AppendString(&v16, str5, -1i64);
    Scaleform::StringBuffer::AppendString(&v16, str6, -1i64);
    v14 = Scaleform::GFx::FontFlagsToString(flags2);
    Scaleform::StringBuffer::AppendString(&v16, v14, -1i64);
    v15 = &customWorldMapCaption;
    if ( v16.pData )
      v15 = v16.pData;
    Scaleform::GFx::AddSearchInfo_2(v12, v15);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v16);
  }
}

// File Line: 290
// RVA: 0x8B2120
void __fastcall Scaleform::GFx::AddSearchInfo(Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo, const char *str1, const char *str2, const char *str3, const char *str4, const char *str5, unsigned int flags)
{
  const char *v7; // rdi
  const char *v8; // rsi
  const char *v9; // rbp
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v10; // rbx
  const char *v11; // rax
  char *v12; // rdx
  Scaleform::StringBuffer v13; // [rsp+28h] [rbp-40h]

  if ( psearchInfo )
  {
    v7 = str3;
    v8 = str2;
    v9 = str1;
    v10 = psearchInfo;
    Scaleform::StringBuffer::StringBuffer(&v13, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v13, v9, -1i64);
    Scaleform::StringBuffer::AppendString(&v13, v8, -1i64);
    Scaleform::StringBuffer::AppendString(&v13, v7, -1i64);
    Scaleform::StringBuffer::AppendString(&v13, str4, -1i64);
    Scaleform::StringBuffer::AppendString(&v13, str5, -1i64);
    v11 = Scaleform::GFx::FontFlagsToString(flags);
    Scaleform::StringBuffer::AppendString(&v13, v11, -1i64);
    v12 = &customWorldMapCaption;
    if ( v13.pData )
      v12 = v13.pData;
    Scaleform::GFx::AddSearchInfo_2(v10, v12);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v13);
  }
}

// File Line: 307
// RVA: 0x8CC5A0
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::FontManager::FindOrCreateHandle(Scaleform::GFx::FontManager *this, const char *pfontName, unsigned int matchFontFlags, Scaleform::GFx::FontResource **ppfoundFont, Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  unsigned int v5; // edi
  const char *v6; // r12
  Scaleform::GFx::FontManager *v7; // r13
  Scaleform::GFx::Resource *v8; // r14
  Scaleform::GFx::FontHandle *v9; // rbx
  Scaleform::GFx::FontManagerStates *v10; // rax
  int v11; // esi
  Scaleform::GFx::MovieDefImpl::SearchInfo *v12; // rdx
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v13; // r15
  unsigned __int64 v14; // rdx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rax
  Scaleform::GFx::Resource **v17; // rdi
  Scaleform::GFx::Resource *v18; // rcx
  Scaleform::GFx::MovieDefImpl *v19; // rcx
  Scaleform::GFx::FontResource *v20; // rsi
  Scaleform::GFx::MovieDef *v21; // rdi
  Scaleform::GFx::MovieImpl *v22; // rcx
  Scaleform::Render::Font *v23; // rcx
  Scaleform::Render::Text::FontHandle *v24; // rax
  Scaleform::Render::Text::FontManagerBase *v25; // rdx
  _QWORD *v26; // rax
  _BYTE *v27; // rcx
  unsigned int v28; // er15
  unsigned __int8 v29; // di
  unsigned __int64 v30; // rdx
  unsigned __int64 v31; // rax
  signed __int64 v32; // rax
  signed __int64 v33; // rdi
  bool v34; // zf
  Scaleform::GFx::FontHandle **v35; // rdi
  const char *v36; // r13
  unsigned int flags; // er12
  float v38; // xmm6_4
  int v39; // er15
  const char *v40; // rsi
  Scaleform::GFx::FontMap::MapFontFlags v41; // er12
  Scaleform::GFx::FontMap::MapFontFlags v42; // eax
  signed int v43; // er15
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v44; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v45; // rsi
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
  signed __int64 v59; // rcx
  unsigned __int64 v60; // rdx
  unsigned __int64 v61; // rax
  signed __int64 v62; // rax
  Scaleform::GFx::Resource **v63; // rbx
  Scaleform::GFx::MovieDef *v64; // rdi
  Scaleform::Render::Text::FontManagerBase *v65; // rdx
  Scaleform::GFx::MovieDef *v66; // rdi
  Scaleform::Render::Text::FontManagerBase *v67; // rdx
  const char *str4; // rax
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v69; // rcx
  Scaleform::GFx::MovieDef *v70; // rdi
  Scaleform::GFx::ResourceLibBase *v71; // rcx
  Scaleform::GFx::FontResource *v72; // rdi
  Scaleform::GFx::ResourceLibBase *v73; // rcx
  Scaleform::GFx::MovieDefImpl *v74; // rax
  Scaleform::GFx::ResourceWeakLib *v75; // r9
  Scaleform::GFx::Resource *v76; // rdi
  Scaleform::Render::Text::FontHandle *v77; // rax
  Scaleform::Render::Text::FontManagerBase *v78; // rdx
  Scaleform::GFx::ResourceLibBase *v79; // rcx
  unsigned int v80; // er12
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v81; // rsi
  Scaleform::GFx::FontManagerStates *v82; // rax
  signed __int64 v83; // rax
  __int64 v84; // rdi
  Scaleform::Render::Text::FontManagerBase *v85; // rdx
  const char *v86; // rax
  __int64 v87; // rdi
  __int64 v88; // rcx
  __int64 v89; // rdi
  __int64 v90; // rcx
  Scaleform::GFx::FontHandle **v91; // rdx
  char v93; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::FontHandle *v94; // [rsp+48h] [rbp-B8h]
  int v95; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::FontLib *v96; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::FontHandle *v97; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::FontHandle **v98; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::MovieDefImpl::SearchInfo *v99; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::MovieDef *ppsrcMovieDef; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::FontLib::FontResult v101; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::FontProvider *pprovider; // [rsp+90h] [rbp-70h]
  __int64 v103; // [rsp+98h] [rbp-68h]
  __int64 v104; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::MovieDefImpl::SearchInfo resSearchInfo; // [rsp+A8h] [rbp-58h]
  Scaleform::GFx::FontMap *v106; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::FontManager::FontKey key; // [rsp+C8h] [rbp-38h]
  Scaleform::GFx::FontManager::FontKey v108; // [rsp+D8h] [rbp-28h]
  Scaleform::GFx::FontManager::FontKey v109; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::FontManager::FontKey v110; // [rsp+F8h] [rbp-8h]
  __int64 v111; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::Resource *v112; // [rsp+110h] [rbp+10h]
  Scaleform::GFx::FontManager *pmanager; // [rsp+190h] [rbp+90h]
  char *pfontNamea; // [rsp+198h] [rbp+98h]
  unsigned int matchFontFlagsa; // [rsp+1A0h] [rbp+A0h]
  Scaleform::GFx::FontResource **v116; // [rsp+1A8h] [rbp+A8h]

  v116 = ppfoundFont;
  matchFontFlagsa = matchFontFlags;
  pfontNamea = (char *)pfontName;
  pmanager = this;
  v111 = -2i64;
  v5 = matchFontFlags;
  v6 = pfontName;
  v7 = this;
  key.pFontName = pfontName;
  key.FontStyle = matchFontFlags;
  v8 = 0i64;
  v9 = 0i64;
  v94 = 0i64;
  v10 = this->pState;
  v96 = v10->pFontLib.pObject;
  pprovider = v10->pFontProvider.pObject;
  v106 = v10->pFontMap.pObject;
  v11 = 0;
  v95 = 0;
  v98 = 0i64;
  ppsrcMovieDef = (Scaleform::GFx::MovieDef *)&resSearchInfo.ImportSearchUrls;
  resSearchInfo.ImportSearchUrls.pTable = 0i64;
  Scaleform::String::String(&resSearchInfo.ImportFoundUrl);
  v12 = 0i64;
  v99 = 0i64;
  v93 = 0;
  v13 = searchInfo;
  while ( 1 )
  {
    if ( v13 )
    {
      v95 = v11 + 1;
      ++v13->Indent;
      v12 = &resSearchInfo;
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
              (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&v7->CreatedFonts.pTable,
              &key,
              v7->CreatedFonts.pTable->SizeMask & (v15 ^ v5 & 3));
      if ( v16 >= 0 )
      {
        v17 = (Scaleform::GFx::Resource **)&v7->CreatedFonts.pTable[2 * (v16 + 1)];
        if ( v17 )
        {
          if ( matchFontFlagsa & 0x10 )
            goto LABEL_189;
          v18 = *v17;
          if ( !((BYTE4((*v17)[2].vfptr->GetResourceReport) | LOBYTE((*v17)[1].vfptr)) & 0x10) )
            goto LABEL_189;
          if ( *((_BYTE *)v17 + 8) )
            goto LABEL_191;
          v98 = (Scaleform::GFx::FontHandle **)&v7->CreatedFonts.pTable[2 * (v16 + 1)];
        }
        v5 = matchFontFlagsa;
      }
      v12 = v99;
    }
    v19 = v7->pDefImpl;
    if ( v19 )
      v20 = (Scaleform::GFx::FontResource *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, const char *, _QWORD, Scaleform::GFx::MovieDefImpl::SearchInfo *))v19->vfptr[7].__vecDelDtor)(
                                              v19,
                                              v6,
                                              v5,
                                              v12);
    else
      v20 = 0i64;
    Scaleform::GFx::AddSearchInfo_3(v13, v6, v5, v7->pState->pFontLib.pObject != 0i64, &resSearchInfo);
    v21 = 0i64;
    ppsrcMovieDef = 0i64;
    if ( !v20 )
    {
      v22 = v7->pMovie;
      if ( !v22 )
        goto LABEL_34;
      v20 = Scaleform::GFx::MovieImpl::FindRegisteredFont(v22, v6, matchFontFlagsa, &ppsrcMovieDef);
      if ( !v20 )
      {
        Scaleform::GFx::AddSearchInfo_1(v13, "Registered fonts: \"", v6, "\"", matchFontFlagsa, " not found.");
        goto LABEL_34;
      }
      v21 = ppsrcMovieDef;
    }
    v23 = v20->pFont.pObject;
    if ( ~(unsigned __int8)(v23->Flags >> 6) & 1 )
    {
      if ( matchFontFlagsa & 3 && !((unsigned __int8 (*)(void))v23->vfptr[19].__vecDelDtor)() )
      {
        if ( v116 )
          *v116 = v20;
        v91 = v98;
        if ( v98 )
        {
          (*v98)->pFontManager = 0i64;
          Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::RemoveAlt<Scaleform::GFx::FontHandle *>(
            (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&v7->CreatedFonts.pTable,
            v91);
        }
        goto LABEL_200;
      }
      v24 = (Scaleform::Render::Text::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     64i64);
      v9 = (Scaleform::GFx::FontHandle *)v24;
      v97 = (Scaleform::GFx::FontHandle *)v24;
      if ( v24 )
      {
        v25 = (Scaleform::Render::Text::FontManagerBase *)&v7->vfptr;
        if ( v13 )
          v25 = 0i64;
        Scaleform::Render::Text::FontHandle::FontHandle(v24, v25, v20->pFont.pObject, v6, 0);
        v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable';
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
        (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&v7->CreatedFonts.pTable,
        (Scaleform::GFx::FontHandle *const *)v17);
      if ( !v7->CreatedFonts.pTable )
        goto LABEL_205;
      v26 = (_QWORD *)(v9->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
      v27 = *v26 & 0x7FFFFFFFFFFFFFFFi64 ? (_QWORD *)((char *)v26 + 12) : ((__int64 (*)(void))v9->pFont.pObject->vfptr[1].__vecDelDtor)();
      v28 = v9->pFont.pObject->Flags;
      v29 = (v28 | v9->OverridenFontFlags) & 3;
      v30 = -1i64;
      do
        ++v30;
      while ( v27[v30] );
      v31 = Scaleform::String::BernsteinHashFunctionCIS(v27, v30, 0x1505ui64);
      v32 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontHandle *>(
              (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&v7->CreatedFonts.pTable,
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
LABEL_205:
        v98 = 0i64;
      }
    }
    v36 = v6;
    flags = matchFontFlagsa;
    v38 = *(float *)&FLOAT_1_0;
    v39 = 0;
    if ( v9 )
      goto LABEL_120;
    v40 = pfontNamea;
    if ( !v106 || !Scaleform::GFx::FontMap::GetFontMapping(v106, &pmanager->FontMapEntry, pfontNamea) )
      goto LABEL_79;
    v36 = (const char *)((pmanager->FontMapEntry.Name.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
    v41 = pmanager->FontMapEntry.Flags;
    if ( v41 == 16 )
      flags = matchFontFlagsa;
    else
      flags = matchFontFlagsa & 0xFFFFFFFC | v41 & 0xFFFFFFF3;
    v38 = pmanager->FontMapEntry.ScaleFactor;
    v42 = pmanager->FontMapEntry.Flags;
    if ( v42 & 0xC )
      v43 = (signed int)v42 >> 2;
    else
      LOBYTE(v43) = 0;
    v39 = pmanager->FontMapEntry.Flags & 0x20 | v43 & 3;
    v44 = searchInfo;
    if ( searchInfo )
    {
      Scaleform::GFx::AddSearchInfo(
        searchInfo,
        "Applying FontMap: \"",
        pfontNamea,
        "\"  mapped to \"",
        v36,
        "\"",
        flags);
      goto LABEL_80;
    }
    v108.pFontName = (const char *)((pmanager->FontMapEntry.Name.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
    v108.FontStyle = flags;
    v45 = (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&pmanager->CreatedFonts.pTable;
    if ( pmanager->CreatedFonts.pTable )
    {
      v46 = -1i64;
      do
        ++v46;
      while ( v36[v46] );
      v47 = Scaleform::String::BernsteinHashFunctionCIS(v36, v46, 0x1505ui64);
      v48 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontManager::FontKey>(
              v45,
              &v108,
              v45->pTable->SizeMask & (v47 ^ flags & 3));
      if ( v48 >= 0 )
      {
        v17 = (Scaleform::GFx::Resource **)&v45->pTable[2 * (v48 + 1)];
        if ( v17 )
        {
          v49 = *v17;
          if ( v38 == *(float *)&(*v17)[1].pLib )
            goto LABEL_190;
          v50 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                Scaleform::Memory::pGlobalHeap,
                                                64i64);
          v97 = v50;
          if ( v50 )
          {
            Scaleform::GFx::FontHandle::FontHandle(
              v50,
              (Scaleform::Render::Text::FontManagerBase *)&pmanager->vfptr,
              (Scaleform::Render::Font *)(*v17)[2].vfptr,
              pfontNamea,
              matchFontFlagsa,
              *(Scaleform::GFx::MovieDef **)&(*v17)[2].RefCount.Value);
            v9 = v51;
          }
          else
          {
            v9 = 0i64;
          }
          v94 = v9;
          v9->FontScaleFactor = v38;
        }
      }
    }
    v109.pFontName = pfontNamea;
    v109.FontStyle = flags;
    if ( v45->pTable )
    {
      v52 = -1i64;
      do
        ++v52;
      while ( pfontNamea[v52] );
      v53 = Scaleform::String::BernsteinHashFunctionCIS(pfontNamea, v52, 0x1505ui64);
      v54 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontManager::FontKey>(
              v45,
              &v109,
              v45->pTable->SizeMask & (v53 ^ flags & 3));
      if ( v54 >= 0 )
      {
        v17 = (Scaleform::GFx::Resource **)&v45->pTable[2 * (v54 + 1)];
        if ( v17 )
          break;
      }
    }
LABEL_77:
    if ( v9 )
      goto LABEL_120;
    v40 = pfontNamea;
LABEL_79:
    v44 = searchInfo;
LABEL_80:
    v57 = (__int64)v96;
    if ( v96 )
    {
      v101.pMovieDef = 0i64;
      v101.pFontResource = 0i64;
      v58 = pmanager->pState;
      v59 = (signed __int64)&v58->vfptr;
      if ( !v58 )
        v59 = 0i64;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::FontLib *, Scaleform::GFx::FontLib::FontResult *, const char *, _QWORD, Scaleform::GFx::MovieDefImpl *, signed __int64, Scaleform::GFx::ResourceWeakLib *))v96->vfptr[1].__vecDelDtor)(
             v96,
             &v101,
             v36,
             flags,
             pmanager->pDefImpl,
             v59,
             pmanager->pWeakLib) )
      {
        if ( v39 )
        {
          v110.pFontName = v40;
          v110.FontStyle = v39;
          if ( pmanager->CreatedFonts.pTable )
          {
            v60 = -1i64;
            do
              ++v60;
            while ( v40[v60] );
            v61 = Scaleform::String::BernsteinHashFunctionCIS(v40, v60, 0x1505ui64);
            v62 = Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::findIndexCore<Scaleform::GFx::FontManager::FontKey>(
                    (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&pmanager->CreatedFonts.pTable,
                    &v110,
                    pmanager->CreatedFonts.pTable->SizeMask & (v61 ^ v39 & 3));
            if ( v62 >= 0 )
            {
              v63 = (Scaleform::GFx::Resource **)&pmanager->CreatedFonts.pTable[2 * (v62 + 1)];
              if ( v63 )
              {
                Scaleform::Render::RenderBuffer::AddRef(*v63);
                v8 = *v63;
                Scaleform::GFx::FontLib::FontResult::~FontResult(&v101);
                goto LABEL_200;
              }
            }
          }
          v9 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                               Scaleform::Memory::pGlobalHeap,
                                               64i64);
          v97 = v9;
          if ( v9 )
          {
            v64 = v101.pMovieDef;
            v65 = (Scaleform::Render::Text::FontManagerBase *)&pmanager->vfptr;
            if ( searchInfo )
              v65 = 0i64;
            Scaleform::Render::Text::FontHandle::FontHandle(
              (Scaleform::Render::Text::FontHandle *)&v9->vfptr,
              v65,
              v101.pFontResource->pFont.pObject,
              v40,
              v39);
            v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable';
            if ( v64 )
              _InterlockedExchangeAdd(&v64->RefCount.Value, 1u);
            v9->pSourceMovieDef.pObject = v64;
          }
          else
          {
            v9 = 0i64;
          }
          v94 = v9;
          v9->FontScaleFactor = v38;
          Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontLib: \"", v40, "\" ", v39, " found.");
          goto LABEL_108;
        }
        v9 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             64i64);
        v97 = v9;
        if ( v9 )
        {
          v66 = v101.pMovieDef;
          v67 = (Scaleform::Render::Text::FontManagerBase *)&pmanager->vfptr;
          if ( searchInfo )
            v67 = 0i64;
          Scaleform::Render::Text::FontHandle::FontHandle(
            (Scaleform::Render::Text::FontHandle *)&v9->vfptr,
            v67,
            v101.pFontResource->pFont.pObject,
            v40,
            0);
          v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable';
          if ( v66 )
            _InterlockedExchangeAdd(&v66->RefCount.Value, 1u);
          v9->pSourceMovieDef.pObject = v66;
        }
        else
        {
          v9 = 0i64;
        }
        v94 = v9;
        v9->FontScaleFactor = v38;
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
          v71 = v70->pLib;
          if ( v71 )
          {
            v71->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v71->vfptr, (unsigned int)v70);
            v70->pLib = 0i64;
          }
          v70->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v70->vfptr, 1u);
        }
        v9 = v94;
      }
      v72 = v101.pFontResource;
      if ( v101.pFontResource )
      {
        if ( !_InterlockedDecrement(&v101.pFontResource->RefCount.Value) )
        {
          v73 = v72->pLib;
          if ( v73 )
          {
            v73->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v73->vfptr, (unsigned int)v72);
            v72->pLib = 0i64;
          }
          v72->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v72->vfptr, 1u);
        }
        v9 = v94;
      }
LABEL_120:
      v57 = (__int64)v96;
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
      if ( !v57 && resSearchInfo.Status == 2 )
        Scaleform::GFx::AddSearchInfo_2(searchInfo, "FontLib not installed.");
LABEL_128:
      if ( pprovider )
      {
        v74 = pmanager->pDefImpl;
        if ( v74 )
          v75 = v74->pLoaderImpl.pObject->pWeakResourceLib.pObject;
        else
          v75 = pmanager->pWeakLib;
        v76 = Scaleform::GFx::FontResource::CreateFontResource(v36, flags, pprovider, v75);
        v112 = v76;
        if ( v76 )
        {
          Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontProvider: \"", v36, "\" ", flags, " found.");
          v77 = (Scaleform::Render::Text::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         64i64);
          v9 = (Scaleform::GFx::FontHandle *)v77;
          v97 = (Scaleform::GFx::FontHandle *)v77;
          if ( v77 )
          {
            v78 = (Scaleform::Render::Text::FontManagerBase *)&pmanager->vfptr;
            if ( searchInfo )
              v78 = 0i64;
            Scaleform::Render::Text::FontHandle::FontHandle(
              v77,
              v78,
              (Scaleform::Render::Font *)v76[1].vfptr,
              pfontNamea,
              0);
            v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable';
            v9->pSourceMovieDef.pObject = 0i64;
          }
          else
          {
            v9 = 0i64;
          }
          v94 = v9;
          v9->FontScaleFactor = v38;
        }
        else
        {
          Scaleform::GFx::AddSearchInfo_1(searchInfo, "Searching FontProvider: \"", v36, "\" ", flags, " not found.");
        }
        if ( v76 )
        {
          if ( !_InterlockedDecrement(&v76->RefCount.Value) )
          {
            v79 = v76->pLib;
            if ( v79 )
            {
              v79->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v79->vfptr, (unsigned int)v76);
              v76->pLib = 0i64;
            }
            v76->vfptr->__vecDelDtor(v76, 1u);
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
      if ( !pprovider && resSearchInfo.Status == 2 )
        Scaleform::GFx::AddSearchInfo_2(searchInfo, "FontProvider not installed.");
      goto LABEL_153;
    }
LABEL_152:
    if ( v9 )
    {
LABEL_195:
      v81 = (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)pmanager;
LABEL_196:
      if ( searchInfo )
        searchInfo->Indent -= v95;
      else
        Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Add<Scaleform::GFx::FontHandle *>(
          v81 + 2,
          &v81[2],
          &v94);
      v8 = (Scaleform::GFx::Resource *)v9;
      goto LABEL_200;
    }
LABEL_153:
    if ( v96 && flags & 0x10 )
    {
      v80 = flags & 0xFFFFFFEF;
      v103 = 0i64;
      v104 = 0i64;
      v81 = (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)pmanager;
      v82 = pmanager->pState;
      v83 = (signed __int64)(v82 ? &v82->vfptr : 0i64);
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::FontLib *, __int64 *, const char *, _QWORD, Scaleform::GFx::MovieDefImpl *, signed __int64, _QWORD))v96->vfptr[1].__vecDelDtor)(
             v96,
             &v103,
             v36,
             v80,
             pmanager->pDefImpl,
             v83,
             0i64) )
      {
        v9 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             64i64);
        v97 = v9;
        if ( v9 )
        {
          v84 = v103;
          v85 = (Scaleform::Render::Text::FontManagerBase *)&pmanager->vfptr;
          if ( searchInfo )
            v85 = 0i64;
          Scaleform::Render::Text::FontHandle::FontHandle(
            (Scaleform::Render::Text::FontHandle *)&v9->vfptr,
            v85,
            *(Scaleform::Render::Font **)(v104 + 24),
            pfontNamea,
            0x10u);
          v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable';
          if ( v84 )
            _InterlockedExchangeAdd((volatile signed __int32 *)(v84 + 8), 1u);
          v9->pSourceMovieDef.pObject = (Scaleform::GFx::MovieDef *)v84;
        }
        else
        {
          v9 = 0i64;
        }
        v94 = v9;
        v9->FontScaleFactor = v38;
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
          (**(void (__fastcall ***)(__int64, signed __int64))v87)(v87, 1i64);
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
          (**(void (__fastcall ***)(__int64, signed __int64))v89)(v89, 1i64);
        }
        v9 = v94;
      }
      if ( v9 )
        goto LABEL_196;
    }
    if ( !(matchFontFlagsa & 0x10) )
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
    v96 = 0i64;
    v93 = 1;
    v6 = pfontNamea;
    v7 = pmanager;
    v11 = v95;
    v12 = v99;
  }
  v49 = *v17;
  if ( v38 != *(float *)&(*v17)[1].pLib )
  {
    v55 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                          Scaleform::Memory::pGlobalHeap,
                                          64i64);
    v97 = v55;
    if ( v55 )
    {
      Scaleform::GFx::FontHandle::FontHandle(
        v55,
        (Scaleform::Render::Text::FontManagerBase *)&pmanager->vfptr,
        (Scaleform::Render::Font *)(*v17)[2].vfptr,
        pfontNamea,
        matchFontFlagsa,
        *(Scaleform::GFx::MovieDef **)&(*v17)[2].RefCount.Value);
      v9 = v56;
    }
    else
    {
      v9 = 0i64;
    }
    v94 = v9;
    v9->FontScaleFactor = v38;
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
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::~HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>((Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> > *)&resSearchInfo.ImportSearchUrls.pTable);
  return v8;
}

// File Line: 645
// RVA: 0x8BF6C0
Scaleform::GFx::FontHandle *__fastcall Scaleform::GFx::FontManager::CreateFontHandle(Scaleform::GFx::FontManager *this, const char *pfontName, unsigned int matchFontFlags, bool allowListOfFonts, Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  unsigned int v5; // er14
  const char *v6; // rdi
  Scaleform::GFx::FontManager *v7; // r15
  Scaleform::GFx::FontHandle *v9; // rbp
  char *v10; // rax
  char *v11; // rsi
  signed __int64 v12; // rbx
  char *v13; // rdx
  char _Dst[152]; // [rsp+20h] [rbp-98h]

  v5 = matchFontFlags;
  v6 = pfontName;
  v7 = this;
  if ( !allowListOfFonts )
    return Scaleform::GFx::FontManager::CreateFontHandleFromName(this, pfontName, matchFontFlags, searchInfo);
  v9 = 0i64;
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
    v9 = Scaleform::GFx::FontManager::CreateFontHandleFromName(v7, v13, v5, searchInfo);
    if ( v9 )
      return v9;
  }
  while ( v11 );
  return v9;
}

// File Line: 683
// RVA: 0x8BF7C0
Scaleform::GFx::FontHandle *__fastcall Scaleform::GFx::FontManager::CreateFontHandleFromName(Scaleform::GFx::FontManager *this, const char *pfontName, unsigned int matchFontFlags, Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *v4; // rdi
  unsigned int v5; // er14
  const char *str5; // rsi
  Scaleform::GFx::FontManager *v7; // r13
  char *v8; // r15
  Scaleform::GFx::FontHandle *v9; // rbx
  Scaleform::GFx::Resource *v10; // rbp
  Scaleform::GFx::FontHandle *v11; // rax
  Scaleform::GFx::FontHandle *v12; // rax
  Scaleform::GFx::FontResource *v13; // rbp
  Scaleform::Render::Text::FontHandle *v14; // rax
  Scaleform::Render::Text::FontManagerBase *v15; // rdx
  Scaleform::GFx::FontHandle *key; // [rsp+50h] [rbp-78h]
  Scaleform::GFx::FontResource *ppfoundFont; // [rsp+58h] [rbp-70h]
  __int64 v19; // [rsp+60h] [rbp-68h]
  Scaleform::GFx::Resource *v20; // [rsp+68h] [rbp-60h]
  Scaleform::StringBuffer v21; // [rsp+70h] [rbp-58h]
  int v22; // [rsp+E8h] [rbp+20h]

  v19 = -2i64;
  v4 = searchInfo;
  v5 = matchFontFlags;
  str5 = pfontName;
  v7 = this;
  v22 = 0;
  v8 = &customWorldMapCaption;
  if ( searchInfo )
  {
    v22 = searchInfo->Indent;
    Scaleform::GFx::AddSearchInfo_1(
      searchInfo,
      "Searching for font: \"",
      pfontName,
      "\" ",
      matchFontFlags,
      &customWorldMapCaption);
  }
  ppfoundFont = 0i64;
  v9 = (Scaleform::GFx::FontHandle *)Scaleform::GFx::FontManager::FindOrCreateHandle(v7, str5, v5, &ppfoundFont, v4);
  if ( !v9 && v5 & 3 )
  {
    if ( v4 )
    {
      ++v4->Indent;
      Scaleform::GFx::AddSearchInfo_1(
        v4,
        "Searching for font: \"",
        str5,
        "\" ",
        v5 & 0xFFFFFFFC,
        &customWorldMapCaption);
    }
    v10 = Scaleform::GFx::FontManager::FindOrCreateHandle(v7, str5, v5 & 0xFFFFFFFC, 0i64, v4);
    v20 = v10;
    if ( v10 )
    {
      v11 = (Scaleform::GFx::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                            Scaleform::Memory::pGlobalHeap,
                                            64i64);
      key = v11;
      if ( v11 )
      {
        Scaleform::GFx::FontHandle::FontHandle(v11, (Scaleform::GFx::FontHandle *)v10);
        v9 = v12;
      }
      else
      {
        v9 = 0i64;
      }
      key = v9;
      v9->OverridenFontFlags |= v5 & 3;
      if ( v4 )
        Scaleform::GFx::AddSearchInfo_0(
          v4,
          "Font \"",
          str5,
          "\" ",
          v5,
          " will be generated from \"",
          str5,
          "\"",
          v5 & 0xFFFFFFFC);
      else
        Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Add<Scaleform::GFx::FontHandle *>(
          (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&v7->CreatedFonts.pTable,
          &v7->CreatedFonts,
          &key);
    }
    if ( v10 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
    v8 = &customWorldMapCaption;
  }
  if ( v4 )
    v4->Indent = v22;
  if ( !v9 )
  {
    v13 = ppfoundFont;
    if ( !ppfoundFont )
      goto LABEL_37;
    if ( v4 )
    {
      Scaleform::StringBuffer::StringBuffer(&v21, Scaleform::Memory::pGlobalHeap);
      Scaleform::StringBuffer::AppendString(&v21, "Empty font: \"", -1i64);
      Scaleform::StringBuffer::AppendString(&v21, str5, -1i64);
      Scaleform::StringBuffer::AppendString(&v21, "\" is created", -1i64);
      if ( v21.pData )
        v8 = v21.pData;
      Scaleform::GFx::AddSearchInfo_2(v4, v8);
      Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v21);
    }
    v14 = (Scaleform::Render::Text::FontHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   64i64);
    v9 = (Scaleform::GFx::FontHandle *)v14;
    if ( v14 )
    {
      v15 = (Scaleform::Render::Text::FontManagerBase *)&v7->vfptr;
      if ( v4 )
        v15 = 0i64;
      Scaleform::Render::Text::FontHandle::FontHandle(v14, v15, v13->pFont.pObject, str5, 0);
      v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable';
      v9->pSourceMovieDef.pObject = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    key = v9;
    if ( !v4 )
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Add<Scaleform::GFx::FontHandle *>(
        (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&v7->CreatedFonts.pTable,
        &v7->CreatedFonts,
        &key);
    if ( !v9 )
LABEL_37:
      Scaleform::GFx::AddSearchInfo_2(v4, "Font not found.");
  }
  return v9;
}

// File Line: 767
// RVA: 0x8D73D0
Scaleform::GFx::FontHandle *__fastcall Scaleform::GFx::FontManager::GetEmptyFont(Scaleform::GFx::FontManager *this)
{
  Scaleform::GFx::FontManager *v1; // rbx

  v1 = this;
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)this->pEmptyFont.pObject);
  return v1->pEmptyFont.pObject;
}

// File Line: 773
// RVA: 0x8BB220
void __fastcall Scaleform::GFx::FontManager::CleanCache(Scaleform::GFx::FontManager *this)
{
  void **v1; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v2; // rcx
  unsigned __int64 v3; // rax
  void **v4; // r9
  unsigned __int64 v5; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v6; // rcx
  _QWORD *v7; // rdx
  unsigned __int64 v8; // r8
  _QWORD *v9; // rdx
  __int64 v10; // rcx
  signed __int64 v11; // rdx

  v1 = (void **)&this->CreatedFonts.pTable;
  v2 = this->CreatedFonts.pTable;
  v3 = 0i64;
  if ( v2 )
  {
    v5 = v2->SizeMask;
    v6 = v2 + 1;
    do
    {
      if ( v6->EntryCount != -2i64 )
        break;
      ++v3;
      v6 += 2;
    }
    while ( v3 <= v5 );
    v4 = v1;
  }
  else
  {
    v4 = 0i64;
  }
  while ( v4 )
  {
    v7 = *v4;
    if ( !*v4 || (signed __int64)v3 > v7[1] )
      break;
    *(_QWORD *)(v7[4 * (v3 + 1)] + 16i64) = 0i64;
    v8 = *((_QWORD *)*v4 + 1);
    if ( (signed __int64)v3 <= (signed __int64)v8 && ++v3 <= v8 )
    {
      v9 = (char *)*v4 + 32 * v3 + 16;
      do
      {
        if ( *v9 != -2i64 )
          break;
        ++v3;
        v9 += 4;
      }
      while ( v3 <= v8 );
    }
  }
  if ( *v1 )
  {
    v10 = 0i64;
    v11 = *((_QWORD *)*v1 + 1) + 1i64;
    do
    {
      if ( *(_QWORD *)((char *)*v1 + v10 + 16) != -2i64 )
        *(_QWORD *)((char *)*v1 + v10 + 16) = -2i64;
      v10 += 32i64;
      --v11;
    }
    while ( v11 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v1);
    *v1 = 0i64;
  }
}

// File Line: 783
// RVA: 0x8BB310
void __fastcall Scaleform::GFx::FontManager::CleanCacheFor(Scaleform::GFx::FontManager *this, Scaleform::GFx::MovieDefImpl *pdefImpl)
{
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v2; // rax
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v3; // r8
  Scaleform::GFx::MovieDefImpl *v4; // rdi
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v7; // rax
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > v8; // rax
  unsigned __int64 v9; // r9
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > v10; // r9
  unsigned __int64 v11; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v12; // rax
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::Iterator v13; // [rsp+20h] [rbp-18h]

  v2 = this->CreatedFonts.pTable;
  v3 = (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&this->CreatedFonts.pTable;
  v4 = pdefImpl;
  if ( v2 )
  {
    v6 = v2->SizeMask;
    v5 = 0i64;
    v7 = v2 + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++v5;
      v7 += 2;
    }
    while ( v5 <= v6 );
  }
  else
  {
    v3 = 0i64;
    v5 = 0i64;
  }
  v13.Index = v5;
  v13.pHash = v3;
  while ( v3 )
  {
    v8.pTable = v3->pTable;
    if ( !v3->pTable || (signed __int64)v5 > (signed __int64)v8.pTable->SizeMask )
      break;
    v9 = v8.pTable[2 * v5 + 2].EntryCount;
    if ( *(Scaleform::GFx::MovieDefImpl **)(v9 + 56) == v4 )
    {
      *(_QWORD *)(v9 + 16) = 0i64;
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Iterator::RemoveAlt<Scaleform::GFx::FontManager::NodePtr>(
        &v13,
        (Scaleform::GFx::FontManager::NodePtr *)&v3->pTable[2 * v5 + 2]);
      v5 = v13.Index;
      v3 = v13.pHash;
    }
    v10.pTable = v3->pTable;
    v11 = v3->pTable->SizeMask;
    if ( (signed __int64)v5 <= (signed __int64)v11 )
    {
      v13.Index = ++v5;
      if ( v5 <= v11 )
      {
        v12 = &v10.pTable[2 * v5 + 1];
        do
        {
          if ( v12->EntryCount != -2i64 )
            break;
          ++v5;
          v12 += 2;
          v13.Index = v5;
        }
        while ( v5 <= v11 );
      }
    }
  }
}

