// File Line: 65
// RVA: 0x8A39D0
void __fastcall Scaleform::GFx::DataAllocator::~DataAllocator(Scaleform::GFx::DataAllocator *this)
{
  Scaleform::GFx::DataAllocator *v1; // rbx
  Scaleform::GFx::DataAllocator::Block *v2; // rdi

  v1 = this;
  if ( this->pAllocations )
  {
    do
    {
      v2 = v1->pAllocations->pNext;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->pAllocations);
      v1->pAllocations = v2;
    }
    while ( v2 );
  }
}

// File Line: 75
// RVA: 0x8EF230
char *__fastcall Scaleform::GFx::DataAllocator::OverflowAlloc(Scaleform::GFx::DataAllocator *this, unsigned __int64 bytes)
{
  unsigned __int64 v2; // rdi
  Scaleform::GFx::DataAllocator *v3; // rbx
  Scaleform::GFx::DataAllocator::Block *v4; // rax
  char *result; // rax
  Scaleform::GFx::DataAllocator::Block **v6; // rax

  v2 = bytes;
  v3 = this;
  if ( bytes > 0xFF8 )
  {
    v4 = (Scaleform::GFx::DataAllocator::Block *)this->pHeap->vfptr->Alloc(this->pHeap, bytes + 8, 0i64);
    if ( v4 )
    {
      v4->pNext = v3->pAllocations;
      v3->pAllocations = v4;
      return (char *)&v4[1];
    }
    return 0i64;
  }
  if ( bytes > this->BytesLeft )
  {
    v6 = (Scaleform::GFx::DataAllocator::Block **)this->pHeap->vfptr->Alloc(this->pHeap, 8184ui64, 0i64);
    if ( !v6 )
      return 0i64;
    *v6 = v3->pAllocations;
    v3->pAllocations = (Scaleform::GFx::DataAllocator::Block *)v6;
    v3->pCurrent = (char *)(v6 + 1);
    v3->BytesLeft = 8176i64;
  }
  result = v3->pCurrent;
  v3->BytesLeft -= v2;
  v3->pCurrent = &result[v2];
  return result;
}

// File Line: 137
// RVA: 0x89AAF0
void __fastcall Scaleform::GFx::MovieDataDef::MovieDataDef(Scaleform::GFx::MovieDataDef *this, Scaleform::GFx::ResourceKey *creationKey, Scaleform::GFx::MovieDataDef::MovieDataType mtype, const char *purl, Scaleform::MemoryHeap *pargHeap, bool debugHeap, unsigned __int64 memoryArena)
{
  const char *v7; // r15
  Scaleform::GFx::MovieDataDef::MovieDataType v8; // esi
  Scaleform::GFx::ResourceKey *v9; // rbx
  Scaleform::GFx::MovieDataDef *v10; // rdi
  volatile int v11; // et1
  __int64 v12; // rax
  __int64 v13; // rbp
  Scaleform::MemoryHeap *v14; // rsi
  const char *v15; // rax
  bool v16; // cf
  unsigned __int64 v17; // rdx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v18; // rax
  __int64 v19; // rax
  Scaleform::Render::RenderBuffer *v20; // rcx
  int v21; // [rsp+40h] [rbp-58h]
  __int64 v22; // [rsp+48h] [rbp-50h]
  __int64 v23; // [rsp+50h] [rbp-48h]
  __int64 v24; // [rsp+58h] [rbp-40h]
  __int64 v25; // [rsp+60h] [rbp-38h]
  __int64 v26; // [rsp+68h] [rbp-30h]
  __int64 v27; // [rsp+70h] [rbp-28h]
  unsigned __int64 v28; // [rsp+78h] [rbp-20h]
  Scaleform::String v29; // [rsp+A8h] [rbp+10h]

  v7 = purl;
  v8 = mtype;
  v9 = creationKey;
  v10 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  v11 = this->RefCount.Value;
  v12 = (unsigned int)this->RefCount.Value;
  this->RefCount.Value = 1;
  v13 = 0i64;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->Id.Id = 0x40000;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::TimelineDef::`vftable;
  this->vfptr = (Scaleform::GFx::ResourceReportVtbl *)&Scaleform::GFx::ResourceReport::`vftable;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::MovieDataDef::`vftable{for `Scaleform::GFx::TimelineDef};
  this->vfptr = (Scaleform::GFx::ResourceReportVtbl *)&Scaleform::GFx::MovieDataDef::`vftable{for `Scaleform::GFx::ResourceReport};
  if ( creationKey->pKeyInterface )
    creationKey->pKeyInterface->vfptr->AddRef(creationKey->pKeyInterface, creationKey->hKeyData);
  v10->mResourceKey.pKeyInterface = v9->pKeyInterface;
  v10->mResourceKey.hKeyData = v9->hKeyData;
  v10->MovieType = v8;
  v10->pData.pObject = 0i64;
  v14 = pargHeap;
  if ( !pargHeap )
  {
    v15 = Scaleform::GetShortFilename(v7);
    Scaleform::String::String(&v29, "MovieData \"", v15, "\"");
    v16 = debugHeap != 0;
    debugHeap = -debugHeap;
    v22 = 16i64;
    v25 = -1i64;
    v26 = 0i64;
    v21 = (v16 ? 0x1000 : 0) | 4;
    v23 = 0x2000i64;
    v24 = 0i64;
    v27 = 4i64;
    v28 = memoryArena;
    v14 = (Scaleform::MemoryHeap *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, unsigned __int64, int *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
                                     Scaleform::Memory::pGlobalHeap,
                                     (v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                                     &v21);
    v17 = v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v17);
  }
  v18 = (Scaleform::GFx::MovieDataDef::LoadTaskData *)v14->vfptr->Alloc(v14, 528ui64, 0i64);
  if ( v18 )
  {
    Scaleform::GFx::MovieDataDef::LoadTaskData::LoadTaskData(v18, v10, v7, v14);
    v13 = v19;
  }
  v20 = (Scaleform::Render::RenderBuffer *)v10->pData.pObject;
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  v10->pData.pObject = (Scaleform::GFx::MovieDataDef::LoadTaskData *)v13;
  if ( !pargHeap )
    Scaleform::MemoryHeap::ReleaseOnFree((ANTLR3_COMMON_TOKEN_struct *)v14, v13);
}

// File Line: 163
// RVA: 0x8A6260
void __fastcall Scaleform::GFx::MovieDataDef::~MovieDataDef(Scaleform::GFx::MovieDataDef *this)
{
  Scaleform::GFx::MovieDataDef *v1; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v2; // rax
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::MovieDataDef::`vftable{for `Scaleform::GFx::TimelineDef};
  this->vfptr = (Scaleform::GFx::ResourceReportVtbl *)&Scaleform::GFx::MovieDataDef::`vftable{for `Scaleform::GFx::ResourceReport};
  v2 = this->pData.pObject;
  if ( v2->LoadState <= 1 )
    v2->LoadingCanceled = 1;
  v3 = (Scaleform::Render::RenderBuffer *)this->pData.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = v1->mResourceKey.pKeyInterface;
  if ( v4 )
    v4->vfptr->Release(v4, v1->mResourceKey.hKeyData);
  v1->vfptr = (Scaleform::GFx::ResourceReportVtbl *)&Scaleform::GFx::ResourceReport::`vftable;
  v1->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  v1->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 174
// RVA: 0x8A3A30
void __fastcall Scaleform::GFx::MovieDataDef::DefBindingData::~DefBindingData(Scaleform::GFx::MovieDataDef::DefBindingData *this)
{
  Scaleform::GFx::MovieDataDef::DefBindingData *v1; // rbx
  Scaleform::GFx::FrameBindData *volatile v2; // rax
  Scaleform::GFx::ImportData *volatile v3; // r14
  unsigned __int64 v4; // rsi
  unsigned __int64 *i; // rdi
  Scaleform::GFx::ResourceDataNode *volatile v6; // rdx
  Scaleform::GFx::FontDataUseNode *volatile v7; // rdx
  Scaleform::Render::RenderBuffer *v8; // rcx

  v1 = this;
  v2 = this->pFrameData.Value;
  for ( this->pFrameData.Value = 0i64; v2; v2 = v2->pNextFrame.Value )
    ;
  if ( this->pImports.Value )
  {
    do
    {
      v3 = v1->pImports.Value;
      v1->pImports.Value = v1->pImports.Value->pNext.Value;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v3->SourceUrl.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v4 = v3->Imports.Data.Size;
      for ( i = (unsigned __int64 *)&v3->Imports.Data.Data[v3->Imports.Data.Size - 1]; v4; --v4 )
      {
        if ( !_InterlockedDecrement((volatile signed __int32 *)((*i & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        i -= 2;
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->Imports.Data.Data);
    }
    while ( v1->pImports.Value );
  }
  while ( v1->pResourceNodes.Value )
  {
    v6 = v1->pResourceNodes.Value;
    v1->pResourceNodes.Value = v1->pResourceNodes.Value->pNext.Value;
    if ( v6->Data.pInterface )
      v6->Data.pInterface->vfptr->Release(v6->Data.pInterface, v6->Data.hData);
  }
  while ( v1->pFonts.Value )
  {
    v7 = v1->pFonts.Value;
    v1->pFonts.Value = v1->pFonts.Value->pNext.Value;
    v8 = (Scaleform::Render::RenderBuffer *)v7->pFontData.pObject;
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
  }
}

// File Line: 214
// RVA: 0x913CA0
char __fastcall Scaleform::GFx::MovieDataDef::TranslateFrameString(Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *namedFrames, const char *label, unsigned int *frameNumber, bool translateNumbers)
{
  unsigned int *v4; // rdi
  const char *v5; // rbx
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v6; // rsi
  char v7; // r10
  char v8; // r9
  signed int v9; // ecx
  Scaleform::String *v11; // rax
  char v12; // bl
  Scaleform::String v13; // [rsp+20h] [rbp-18h]
  __int64 v14; // [rsp+28h] [rbp-10h]
  char *tailptr; // [rsp+48h] [rbp+10h]

  v14 = -2i64;
  v4 = frameNumber;
  v5 = label;
  v6 = namedFrames;
  if ( !label )
    return 0;
  v7 = *label;
  if ( !*label )
    return 0;
  if ( translateNumbers )
  {
    v8 = 0;
    do
    {
      if ( (unsigned __int8)(v7 - 48) > 9u )
      {
        if ( ((v7 - 43) & 0xFD || v8) && v7 != 32 && v7 != 9 )
          goto $translate_frame_label;
      }
      else
      {
        v8 = 1;
      }
      v7 = *++label;
    }
    while ( *label );
    tailptr = 0i64;
    v9 = (signed int)Scaleform::SFstrtod(v5, &tailptr);
    if ( tailptr != v5 && !*tailptr )
    {
      *v4 = v9 - 1;
      return 1;
    }
    return 0;
  }
$translate_frame_label:
  Scaleform::String::String(&v13, v5);
  v12 = Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetCaseInsensitive(
          v6,
          v11,
          v4);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v13.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return v12;
}

// File Line: 274
// RVA: 0x914090
Scaleform::String *__fastcall Scaleform::GFx::MovieDataDef::TranslateNumberToFrameString(Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *namedFrames, unsigned int frameNumber, unsigned int *exactFrameNumberForLabel)
{
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v3; // r9
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v4; // rcx
  unsigned int v5; // er10
  unsigned int *v6; // rdi
  unsigned int v7; // esi
  unsigned __int64 v8; // rdx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v9; // rcx
  unsigned __int64 v10; // rax
  Scaleform::String *v11; // rbx
  __int64 v12; // rcx
  __int64 v13; // r8
  unsigned __int64 v14; // rdx
  unsigned int v15; // eax
  _QWORD *v16; // rax
  Scaleform::String *result; // rax
  __m128i v18; // [rsp+0h] [rbp-18h]

  v3 = namedFrames;
  v4 = namedFrames->mHash.pTable;
  v5 = 0;
  v6 = exactFrameNumberForLabel;
  v7 = frameNumber;
  if ( v4 )
  {
    v8 = v4->SizeMask;
    v9 = v4 + 1;
    v10 = 0i64;
    do
    {
      if ( v9->EntryCount != -2i64 )
        break;
      ++v10;
      v9 += 2;
    }
    while ( v10 <= v8 );
    v18.m128i_i64[0] = (__int64)v3;
    v18.m128i_i64[1] = v10;
  }
  else
  {
    v18 = 0ui64;
  }
  v11 = 0i64;
  _mm_store_si128(&v18, v18);
  v12 = v18.m128i_i64[1];
  while ( v18.m128i_i64[0] )
  {
    v13 = *(_QWORD *)v18.m128i_i64[0];
    if ( !*(_QWORD *)v18.m128i_i64[0] )
      break;
    v14 = *(_QWORD *)(v13 + 8);
    if ( v12 > (signed __int64)v14 )
      break;
    v15 = *(_DWORD *)(32 * v12 + v13 + 40);
    if ( v7 >= v15 && v15 >= v5 )
    {
      v5 = *(_DWORD *)(32 * v12 + v13 + 40);
      v11 = (Scaleform::String *)(32 * v12 + v13 + 32);
    }
    if ( ++v12 <= v14 )
    {
      v16 = (_QWORD *)(v13 + 32 * v12 + 16);
      do
      {
        if ( *v16 != -2i64 )
          break;
        ++v12;
        v16 += 4;
      }
      while ( v12 <= v14 );
    }
  }
  result = v11;
  if ( v6 )
    *v6 = v5;
  return result;
}

// File Line: 302
// RVA: 0x899670
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::LoadTaskData(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::GFx::MovieDataDef *pdataDef, const char *purl, Scaleform::MemoryHeap *pheap)
{
  const char *v4; // rbx
  Scaleform::GFx::MovieDataDef *v5; // r15
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // r14
  __int64 v7; // r13
  Scaleform::GFx::FrameBindData *volatile v8; // rt1
  Scaleform::GFx::FrameBindData *volatile v9; // rt1
  Scaleform::GFx::ImportData *volatile v10; // rt1
  Scaleform::GFx::ImportData *volatile v11; // rt1
  Scaleform::GFx::FontDataUseNode *volatile v12; // rt1
  Scaleform::GFx::FontDataUseNode *volatile v13; // rt1
  Scaleform::GFx::ResourceDataNode *volatile v14; // rt1
  Scaleform::GFx::ResourceDataNode *volatile v15; // rax
  Scaleform::GFx::SwfShapeCharacterDef *v16; // ST30_8
  Scaleform::GFx::SwfShapeCharacterDef *v17; // ST30_8
  __int64 v18; // rax
  char v19; // r12
  char v20; // bl
  Scaleform::GFx::LoadUpdateSync *v21; // rax
  Scaleform::GFx::LoadUpdateSync *v22; // rax
  Scaleform::GFx::LoadUpdateSync *v23; // rbx
  Scaleform::Render::RenderBuffer *v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rsi
  int v27; // et1
  __int64 v28; // rax
  _QWORD *v29; // rax
  Scaleform::GFx::TextFieldDef *v30; // rax
  __int64 v31; // rax
  __int64 v32; // rax
  __int64 v33; // r15
  int v34; // et1
  __int64 v35; // rax
  Scaleform::GFx::Resource *v36; // ST28_8
  Scaleform::GFx::Resource *v37; // ST28_8
  Scaleform::GFx::ShapeDataBase *v38; // rbx
  __int64 v39; // rax
  Scaleform::GFx::ResourceLibBase *v40; // rcx
  __int64 v41; // rcx
  __int64 v42; // rcx
  __int64 v43; // rcx
  char v44; // [rsp+20h] [rbp-49h]
  Scaleform::GFx::Resource *pres; // [rsp+28h] [rbp-41h]
  Scaleform::GFx::SwfShapeCharacterDef *v46; // [rsp+30h] [rbp-39h]
  Scaleform::GFx::ResourceId v47; // [rsp+38h] [rbp-31h]
  Scaleform::GFx::ResourceId v48[2]; // [rsp+40h] [rbp-29h]
  Scaleform::GFx::ResourceId v49; // [rsp+48h] [rbp-21h]
  Scaleform::String url; // [rsp+50h] [rbp-19h]
  Scaleform::GFx::ShapeDataBase *v51; // [rsp+58h] [rbp-11h]
  __int64 v52; // [rsp+60h] [rbp-9h]
  __int64 v53; // [rsp+68h] [rbp-1h]
  __int64 v54; // [rsp+70h] [rbp+7h]
  __int64 v55; // [rsp+78h] [rbp+Fh]
  __int64 v56; // [rsp+80h] [rbp+17h]
  int v57; // [rsp+D8h] [rbp+6Fh]
  _QWORD *rid; // [rsp+E8h] [rbp+7Fh]

  v53 = -2i64;
  v4 = purl;
  v5 = pdataDef;
  v6 = this;
  v7 = 0i64;
  v44 = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,264>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::MovieDataDef::LoadTaskDataBase,264>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieDataDef::LoadTaskDataBase::`vftable;
  this->TagMemAllocator.pHeap = pheap;
  this->TagMemAllocator.pAllocations = 0i64;
  this->TagMemAllocator.pCurrent = 0i64;
  this->TagMemAllocator.BytesLeft = 0i64;
  this->pPathAllocator = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieDataDef::LoadTaskData::`vftable;
  this->pHeap = pheap;
  this->pImageHeap.pObject = 0i64;
  Scaleform::StringLH::StringLH(&this->FileURL, purl);
  Scaleform::GFx::MovieHeaderData::MovieHeaderData(&v6->Header);
  v6->pFrameUpdate.pObject = 0i64;
  v8 = v6->BindData.pFrameData.Value;
  v6->BindData.pFrameData.Value = 0i64;
  v9 = v6->BindData.pFrameData.Value;
  v6->BindData.pFrameDataLast = 0i64;
  v10 = v6->BindData.pImports.Value;
  v6->BindData.pImports.Value = 0i64;
  v11 = v6->BindData.pImports.Value;
  v6->BindData.pImportsLast = 0i64;
  v12 = v6->BindData.pFonts.Value;
  v6->BindData.pFonts.Value = 0i64;
  v13 = v6->BindData.pFonts.Value;
  v6->BindData.pFontsLast = 0i64;
  v14 = v6->BindData.pResourceNodes.Value;
  v6->BindData.pResourceNodes.Value = 0i64;
  v15 = v6->BindData.pResourceNodes.Value;
  v6->BindData.pResourceNodesLast = 0i64;
  Scaleform::Lock::Lock(&v6->ResourceLock, 0);
  v6->pExtMovieDef.pObject = 0i64;
  v6->Resources.mHash.pTable = 0i64;
  v6->Exports.mHash.pTable = 0i64;
  v6->InvExports.mHash.pTable = 0i64;
  Scaleform::Lock::Lock(&v6->PlaylistLock, 0);
  v16 = (Scaleform::GFx::SwfShapeCharacterDef *)&v6->Playlist;
  v16->vfptr = 0i64;
  *(_QWORD *)&v16->RefCount.Value = 0i64;
  v16->pLib = 0i64;
  v17 = (Scaleform::GFx::SwfShapeCharacterDef *)&v6->InitActionList;
  v17->vfptr = 0i64;
  *(_QWORD *)&v17->RefCount.Value = 0i64;
  v17->pLib = 0i64;
  v6->NamedFrames.mHash.pTable = 0i64;
  v6->GradientIdGenerator.Id = 327680;
  v6->Scenes.pObject = 0i64;
  v6->Scenes.Owner = 1;
  v6->FileAttributes = 0;
  v6->pMetadata = 0i64;
  v6->MetadataSize = 0;
  v18 = (__int64)v6->pHeap->vfptr->Alloc(v6->pHeap, 24ui64, 0i64);
  if ( v18 )
  {
    *(_QWORD *)v18 = 0i64;
    *(_QWORD *)(v18 + 8) = 0i64;
    *(_DWORD *)(v18 + 16) = 0x20000000;
  }
  else
  {
    v18 = 0i64;
  }
  v6->pPathAllocator = (Scaleform::GFx::PathAllocator *)v18;
  v6->LoadingCanceled = 0;
  *(_QWORD *)&v6->LoadState = 0i64;
  v6->TagCount = 0;
  v6->ResIndexCounter = 0;
  v6->InitActionsCnt = 0;
  if ( v5->MovieType == 2 )
  {
    Scaleform::String::String(&url, v4);
    v19 = 1;
    v44 = 1;
    if ( Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, 0i64, 0i64) )
    {
      v20 = 0;
      goto LABEL_9;
    }
  }
  else
  {
    v19 = 0;
  }
  v20 = 1;
LABEL_9:
  if ( v19 & 1 )
  {
    v44 = v19 & 0xFE;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v19 &= 0xFEu;
  }
  if ( v20 )
  {
    v21 = (Scaleform::GFx::LoadUpdateSync *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              72i64);
    if ( v21 )
    {
      Scaleform::GFx::LoadUpdateSync::LoadUpdateSync(v21);
      v23 = v22;
    }
    else
    {
      v23 = 0i64;
    }
    v24 = (Scaleform::Render::RenderBuffer *)v6->pFrameUpdate.pObject;
    if ( v24 )
      Scaleform::RefCountImpl::Release(v24);
    v6->pFrameUpdate.pObject = v23;
  }
  v25 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v6->pHeap->vfptr->Alloc)(v6->pHeap, 96i64);
  v26 = v25;
  if ( v25 )
  {
    *(_QWORD *)v25 = &Scaleform::GFx::Resource::`vftable;
    v27 = *(_DWORD *)(v25 + 8);
    v28 = *(unsigned int *)(v25 + 8);
    *(_DWORD *)(v26 + 8) = 1;
    *(_QWORD *)(v26 + 16) = 0i64;
    *(_QWORD *)v26 = &Scaleform::GFx::CharacterDef::`vftable;
    *(_DWORD *)(v26 + 24) = 0x40000;
    *(_QWORD *)v26 = &Scaleform::GFx::TimelineDef::`vftable;
    *(_QWORD *)v26 = &Scaleform::GFx::TimelineIODef::`vftable;
    *(_QWORD *)v26 = &Scaleform::GFx::SpriteDef::`vftable;
    *(_QWORD *)(v26 + 32) = v5;
    *(_QWORD *)(v26 + 40) = 0i64;
    *(_QWORD *)(v26 + 48) = 0i64;
    v29 = (_QWORD *)(v26 + 56);
    rid = v29;
    *v29 = 0i64;
    v29[1] = 0i64;
    v29[2] = 0i64;
    *(_QWORD *)(v26 + 80) = 0i64;
    *(_BYTE *)(v26 + 88) = 0;
    v19 = v44;
  }
  else
  {
    v26 = 0i64;
  }
  v55 = v26;
  *(_DWORD *)(v26 + 48) = 1;
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,264>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,264>,Scaleform::ArrayDefaultPolicy> *)(v26 + 56),
    1ui64);
  LODWORD(rid) = 65537;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
    v6,
    (Scaleform::GFx::ResourceId)&rid,
    (Scaleform::GFx::Resource *)v26);
  v30 = (Scaleform::GFx::TextFieldDef *)v6->pHeap->vfptr->Alloc(v6->pHeap, 144ui64, 0i64);
  if ( v30 )
  {
    Scaleform::GFx::TextFieldDef::TextFieldDef(v30);
    v7 = v31;
  }
  v52 = v7;
  *(_WORD *)(v7 + 128) |= 0x800u;
  *(_WORD *)((char *)&v57 + 1) = 0;
  LOBYTE(v57) = 0;
  HIBYTE(v57) = -1;
  *(_DWORD *)(v7 + 84) = v57;
  *(_DWORD *)(v7 + 80) = 1131413504;
  *(_WORD *)(v7 + 128) |= 0x528u;
  v49.Id = 65538;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
    v6,
    (Scaleform::GFx::ResourceId)&v49,
    (Scaleform::GFx::Resource *)v7);
  v32 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v6->pHeap->vfptr->Alloc)(v6->pHeap, 96i64);
  v33 = v32;
  if ( v32 )
  {
    *(_QWORD *)v32 = &Scaleform::GFx::Resource::`vftable;
    v34 = *(_DWORD *)(v32 + 8);
    v35 = *(unsigned int *)(v32 + 8);
    *(_DWORD *)(v33 + 8) = 1;
    *(_QWORD *)(v33 + 16) = 0i64;
    *(_QWORD *)v33 = &Scaleform::GFx::CharacterDef::`vftable;
    *(_DWORD *)(v33 + 24) = 0x40000;
    *(_QWORD *)v33 = &Scaleform::GFx::ButtonDef::`vftable;
    v36 = (Scaleform::GFx::Resource *)(v33 + 32);
    v36->vfptr = 0i64;
    *(_QWORD *)&v36->RefCount.Value = 0i64;
    v36->pLib = 0i64;
    v37 = (Scaleform::GFx::Resource *)(v33 + 56);
    *(_QWORD *)&v48[0].Id = v33 + 56;
    v37->vfptr = 0i64;
    *(_QWORD *)&v37->RefCount.Value = 0i64;
    v37->pLib = 0i64;
    *(_QWORD *)(v33 + 80) = 0i64;
    *(_BYTE *)(v33 + 88) = 0;
    v19 = v44;
  }
  else
  {
    v33 = 0i64;
  }
  v54 = v33;
  v48[0].Id = 65539;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
    v6,
    (Scaleform::GFx::ResourceId)v48,
    (Scaleform::GFx::Resource *)v33);
  v46 = (Scaleform::GFx::SwfShapeCharacterDef *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v6->pHeap->vfptr->Alloc)(
                                                  v6->pHeap,
                                                  48i64);
  if ( v46 )
  {
    v38 = (Scaleform::GFx::ShapeDataBase *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v6->pHeap->vfptr->Alloc)(
                                             v6->pHeap,
                                             32i64);
    if ( v38 )
    {
      v38->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
      v38->RefCount = 1;
      v38->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
      v38->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
      v38->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
      v38->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
      v38->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ShapeDataBase::`vftable;
      v38->Flags = 0;
      v38->Paths = (const char *)&unk_1418A79F4;
      v38->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ConstShapeNoStyles::`vftable;
    }
    else
    {
      v38 = 0i64;
    }
    v51 = v38;
    v19 |= 2u;
    Scaleform::GFx::SwfShapeCharacterDef::SwfShapeCharacterDef(v46, v38);
    pres = (Scaleform::GFx::Resource *)v39;
  }
  else
  {
    v39 = 0i64;
    pres = 0i64;
    v38 = v51;
  }
  v56 = v39;
  if ( v19 & 2 && v38 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v38);
  v47.Id = 65540;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(v6, (Scaleform::GFx::ResourceId)&v47, pres);
  if ( pres && !_InterlockedDecrement(&pres->RefCount.Value) )
  {
    v40 = pres->pLib;
    if ( v40 )
    {
      v40->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v40->vfptr, (unsigned int)pres);
      pres->pLib = 0i64;
    }
    pres->vfptr->__vecDelDtor(pres, 1u);
  }
  if ( v33 && !_InterlockedDecrement((volatile signed __int32 *)(v33 + 8)) )
  {
    v41 = *(_QWORD *)(v33 + 16);
    if ( v41 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v41 + 8i64))(v41, v33);
      *(_QWORD *)(v33 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, signed __int64))v33)(v33, 1i64);
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)(v7 + 8)) )
  {
    v42 = *(_QWORD *)(v7 + 16);
    if ( v42 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v42 + 8i64))(v42, v7);
      *(_QWORD *)(v7 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, signed __int64))v7)(v7, 1i64);
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)(v26 + 8)) )
  {
    v43 = *(_QWORD *)(v26 + 16);
    if ( v43 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v43 + 8i64))(v43, v26);
      *(_QWORD *)(v26 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, signed __int64))v26)(v26, 1i64);
  }
}

// File Line: 351
// RVA: 0x8A5560
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::~LoadTaskData(Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v1; // r14
  Scaleform::GFx::MovieDataDef::LoadTaskData *v2; // rbx
  unsigned int v3; // er15
  __int64 v4; // rdi
  signed __int64 v5; // rdi
  unsigned int i; // esi
  void (__fastcall ***v7)(_QWORD, _QWORD); // rcx
  unsigned int v8; // er15
  __int64 v9; // rdi
  signed __int64 v10; // rdi
  unsigned int j; // esi
  void (__fastcall ***v12)(_QWORD, _QWORD); // rcx
  Scaleform::GFx::PathAllocator *v13; // rsi
  Scaleform::GFx::PathAllocator::Page *v14; // rdx
  Scaleform::GFx::PathAllocator::Page *v15; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *v16; // rbx
  void **v17; // rdi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v18; // rax
  __int64 v19; // r12
  signed __int64 v20; // r13
  char *v21; // r15
  signed __int64 v22; // rsi
  __int64 v23; // rdi
  __int64 v24; // rcx
  void **v25; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *v26; // rax
  __int64 v27; // r15
  signed __int64 v28; // r13
  char *v29; // rsi
  signed __int64 v30; // rdi
  __int64 v31; // rdi
  __int64 v32; // rcx
  Scaleform::GFx::MovieDef *v33; // rdi
  Scaleform::GFx::ResourceLibBase *v34; // rcx
  Scaleform::Render::RenderBuffer *v35; // rcx
  Scaleform::MemoryHeap *v36; // rcx
  Scaleform::GFx::DataAllocator::Block *v37; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieDataDef::LoadTaskData::`vftable;
  v2 = 0i64;
  if ( this->LoadState < 2 )
  {
    v2 = this;
    EnterCriticalSection(&this->ResourceLock.cs);
  }
  v3 = 0;
  if ( v1->Playlist.Data.Size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = (signed __int64)&v1->Playlist.Data.Data[v4];
      for ( i = 0; i < *(_DWORD *)(v5 + 8); ++i )
      {
        v7 = *(void (__fastcall ****)(_QWORD, _QWORD))(*(_QWORD *)v5 + 8i64 * i);
        (**v7)(v7, 0i64);
      }
      *(_QWORD *)v5 = 0i64;
      *(_DWORD *)(v5 + 8) = 0;
      v4 = ++v3;
    }
    while ( v3 < v1->Playlist.Data.Size );
  }
  v8 = 0;
  if ( v1->InitActionList.Data.Size > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = (signed __int64)&v1->InitActionList.Data.Data[v9];
      for ( j = 0; j < *(_DWORD *)(v10 + 8); ++j )
      {
        v12 = *(void (__fastcall ****)(_QWORD, _QWORD))(*(_QWORD *)v10 + 8i64 * j);
        (**v12)(v12, 0i64);
      }
      *(_QWORD *)v10 = 0i64;
      *(_DWORD *)(v10 + 8) = 0;
      v9 = ++v8;
    }
    while ( v8 < v1->InitActionList.Data.Size );
  }
  v13 = v1->pPathAllocator;
  if ( v13 )
  {
    v14 = v13->pFirstPage;
    if ( v13->pFirstPage )
    {
      do
      {
        v15 = v14->pNext;
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v14 = v15;
      }
      while ( v15 );
    }
    v13->pFirstPage = 0i64;
    v13->pLastPage = 0i64;
    v13->FreeBytes = 0;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13);
  }
  if ( v1->pMetadata )
  {
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v1->pMetadata = 0i64;
  }
  if ( v2 )
    LeaveCriticalSection(&v2->ResourceLock.cs);
  v16 = v1->Scenes.pObject;
  if ( v16 )
  {
    if ( v1->Scenes.Owner )
    {
      v1->Scenes.Owner = 0;
      Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::SceneInfo>::DestructArray(v16->Data.Data, v16->Data.Size);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16->Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
    }
    v1->Scenes.pObject = 0i64;
  }
  v1->Scenes.Owner = 0;
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v1->NamedFrames);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->InitActionList.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Playlist.Data.Data);
  Scaleform::Lock::~Lock(&v1->PlaylistLock.cs);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF> > *)&v1->InvExports.mHash.pTable);
  v17 = (void **)&v1->Exports.mHash.pTable;
  v18 = v1->Exports.mHash.pTable;
  if ( v18 )
  {
    v19 = 0i64;
    v20 = v18->SizeMask + 1;
    do
    {
      v21 = (char *)*v17;
      if ( *(_QWORD *)((char *)*v17 + v19 + 16) != -2i64 )
      {
        v22 = (signed __int64)&v21[v19 + 32];
        if ( !*(_DWORD *)(v22 + 8) )
        {
          v23 = *(_QWORD *)(v22 + 16);
          if ( v23 && !_InterlockedDecrement((volatile signed __int32 *)(v23 + 8)) )
          {
            v24 = *(_QWORD *)(v23 + 16);
            if ( v24 )
            {
              (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v24 + 8i64))(v24, v23);
              *(_QWORD *)(v23 + 16) = 0i64;
            }
            (**(void (__fastcall ***)(__int64, signed __int64))v23)(v23, 1i64);
          }
          v17 = (void **)&v1->Exports.mHash.pTable;
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((*(_QWORD *)v22 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        *(_QWORD *)&v21[v19 + 16] = -2i64;
      }
      v19 += 40i64;
      --v20;
    }
    while ( v20 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v17);
    *v17 = 0i64;
  }
  v25 = (void **)&v1->Resources.mHash.pTable;
  v26 = v1->Resources.mHash.pTable;
  if ( v26 )
  {
    v27 = 0i64;
    v28 = v26->SizeMask + 1;
    do
    {
      v29 = (char *)*v25;
      if ( *(_QWORD *)((char *)*v25 + v27 + 16) != -2i64 )
      {
        v30 = (signed __int64)&v29[v27 + 24];
        if ( !*(_DWORD *)(v30 + 8) )
        {
          v31 = *(_QWORD *)(v30 + 16);
          if ( v31 )
          {
            if ( !_InterlockedDecrement((volatile signed __int32 *)(v31 + 8)) )
            {
              v32 = *(_QWORD *)(v31 + 16);
              if ( v32 )
              {
                (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v32 + 8i64))(v32, v31);
                *(_QWORD *)(v31 + 16) = 0i64;
              }
              (**(void (__fastcall ***)(__int64, signed __int64))v31)(v31, 1i64);
            }
          }
        }
        *(_QWORD *)&v29[v27 + 16] = -2i64;
      }
      v27 += 32i64;
      --v28;
    }
    while ( v28 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v25);
    *v25 = 0i64;
  }
  v33 = v1->pExtMovieDef.pObject;
  if ( v33 && !_InterlockedDecrement(&v33->RefCount.Value) )
  {
    v34 = v33->pLib;
    if ( v34 )
    {
      v34->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v34->vfptr, (unsigned int)v33);
      v33->pLib = 0i64;
    }
    v33->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v33->vfptr, 1u);
  }
  Scaleform::Lock::~Lock(&v1->ResourceLock.cs);
  Scaleform::GFx::MovieDataDef::DefBindingData::~DefBindingData(&v1->BindData);
  v35 = (Scaleform::Render::RenderBuffer *)v1->pFrameUpdate.pObject;
  if ( v35 )
    Scaleform::RefCountImpl::Release(v35);
  if ( v1->Header.mExporterInfo.CodeOffsets.Data.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->Header.mExporterInfo.SWFName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->Header.mExporterInfo.Prefix.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v36 = v1->pImageHeap.pObject;
  if ( v36 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))v36->vfptr->Release)(v36);
  if ( v1->TagMemAllocator.pAllocations )
  {
    do
    {
      v37 = v1->TagMemAllocator.pAllocations->pNext;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->TagMemAllocator.pAllocations);
      v1->TagMemAllocator.pAllocations = v37;
    }
    while ( v37 );
  }
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 391
// RVA: 0x8E40A0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::InitEmptyMovieDef(Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx

  v1 = this;
  v2 = &this->PlaylistLock.cs;
  EnterCriticalSection(&this->PlaylistLock.cs);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->Playlist.Data,
    v1->Header.FrameCount);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->InitActionList.Data,
    v1->Header.FrameCount);
  v1->InitActionsCnt = 0;
  LeaveCriticalSection(v2);
  Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(v1, v1->Header.FrameCount, LS_LoadFinished);
}

// File Line: 412
// RVA: 0x8E4250
bool __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::InitImageFileMovieDef(Scaleform::GFx::MovieDataDef::LoadTaskData *this, unsigned int fileLength, Scaleform::GFx::ImageResource *pimageResource, Scaleform::GFx::ImageCreator *imgCreator, Scaleform::Log *plog, bool bilinear)
{
  Scaleform::GFx::ImageCreator *v6; // r12
  Scaleform::GFx::ImageResource *v7; // rsi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v8; // r15
  Scaleform::MemoryHeap *v9; // rax
  Scaleform::Render::Image *v10; // rdi
  Scaleform::GFx::ImageResource *v11; // rax
  Scaleform::GFx::ImageResource *v12; // rax
  Scaleform::GFx::ResourceLibBase *v13; // rcx
  Scaleform::GFx::ImageShapeCharacterDef *v14; // rax
  __int64 v15; // rax
  __int64 v16; // r12
  Scaleform::GFx::DataAllocator::Block *v17; // rax
  signed __int64 v18; // rax
  signed __int64 v19; // r13
  _OWORD *v20; // rax
  __int64 v21; // rcx
  int v23; // [rsp+20h] [rbp-E0h]
  Scaleform::MemoryHeap *v24; // [rsp+28h] [rbp-D8h]
  int v25; // [rsp+30h] [rbp-D0h]
  int v26; // [rsp+34h] [rbp-CCh]
  __int64 v27; // [rsp+38h] [rbp-C8h]
  __int64 v28; // [rsp+40h] [rbp-C0h]
  __int64 v29; // [rsp+48h] [rbp-B8h]
  __int64 v30; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::CharPosInfo __that; // [rsp+60h] [rbp-A0h]
  Scaleform::Lock *v32; // [rsp+D0h] [rbp-30h]
  __int64 v33; // [rsp+D8h] [rbp-28h]
  __int64 v34; // [rsp+E0h] [rbp-20h]
  __int64 v35; // [rsp+E8h] [rbp-18h]
  __int64 v36; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::ImageResource *v37; // [rsp+F8h] [rbp-8h]
  Scaleform::Render::Image *v38; // [rsp+100h] [rbp+0h]
  Scaleform::Render::Cxform v39; // [rsp+110h] [rbp+10h]
  Scaleform::GFx::DataAllocator::Block *v40; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::ResourceId rid; // [rsp+188h] [rbp+88h]
  Scaleform::GFx::ImageResource *v42; // [rsp+190h] [rbp+90h]
  Scaleform::GFx::ImageShapeCharacterDef *v43; // [rsp+198h] [rbp+98h]

  v35 = -2i64;
  v6 = imgCreator;
  v7 = pimageResource;
  v8 = this;
  this->Header.FileLength = fileLength;
  if ( !imgCreator || ((unsigned int (*)(void))pimageResource->pImage->vfptr[3].__vecDelDtor)() )
  {
    LODWORD(v42) = 0;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(v8, (__int64)&v42, (Scaleform::GFx::Resource *)&v7->vfptr);
  }
  else
  {
    v9 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v7);
    v23 = 1;
    v24 = v9;
    v25 = 1;
    v26 = 1;
    v27 = 0i64;
    v28 = 0i64;
    v29 = 0i64;
    v30 = 0i64;
    v10 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::Render::ImageBase *))v6->vfptr[4].__vecDelDtor)(
                                        v6,
                                        &v23,
                                        v7->pImage);
    v38 = v10;
    if ( v10 )
    {
      v11 = (Scaleform::GFx::ImageResource *)v24->vfptr->Alloc(v24, 104ui64, 0i64);
      v42 = v11;
      if ( v11 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v11, v10, Use_Bitmap);
        v7 = v12;
      }
      else
      {
        v7 = 0i64;
      }
      v37 = v7;
      rid.Id = 0;
      Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(v8, (__int64)&rid, (Scaleform::GFx::Resource *)&v7->vfptr);
      if ( v7 && !_InterlockedDecrement(&v7->RefCount.Value) )
      {
        v13 = v7->pLib;
        if ( v13 )
        {
          v13->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, (unsigned int)v7);
          v7->pLib = 0i64;
        }
        v7->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v7->vfptr, 1u);
      }
    }
    else
    {
      v7 = 0i64;
      if ( plog )
        Scaleform::Log::LogError(plog, "Cant create or decode image.");
    }
    if ( v10 )
      ((void (__fastcall *)(Scaleform::Render::Image *))v10->vfptr[2].__vecDelDtor)(v10);
  }
  if ( v7 )
  {
    v14 = (Scaleform::GFx::ImageShapeCharacterDef *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v8->pHeap->vfptr->Alloc)(
                                                      v8->pHeap,
                                                      48i64);
    v43 = v14;
    if ( v14 )
    {
      Scaleform::GFx::ImageShapeCharacterDef::ImageShapeCharacterDef(v14, v7, v6, bilinear);
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    v34 = v16;
    *(_DWORD *)(v16 + 24) = 1;
    LODWORD(v43) = 1;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(v8, (__int64)&v43, (Scaleform::GFx::Resource *)v16);
    v32 = &v8->PlaylistLock;
    EnterCriticalSection(&v8->PlaylistLock.cs);
    Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v8->Playlist.Data,
      v8->Header.FrameCount);
    Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v8->InitActionList.Data,
      v8->Header.FrameCount);
    v8->InitActionsCnt = 0;
    v17 = (Scaleform::GFx::DataAllocator::Block *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, signed __int64))v8->TagMemAllocator.pHeap->vfptr->Alloc)(
                                                    v8->TagMemAllocator.pHeap,
                                                    160i64,
                                                    16i64);
    v40 = v17;
    if ( v17 )
    {
      v17->pNext = v8->TagMemAllocator.pAllocations;
      v8->TagMemAllocator.pAllocations = v17;
      v18 = (signed __int64)&v17[2];
      if ( v18 )
      {
        v19 = v18 + 16;
        v36 = v18 + 16;
        v33 = v18 + 16;
        if ( v18 != -16 )
          Scaleform::GFx::GFxPlaceObjectUnpacked::GFxPlaceObjectUnpacked((Scaleform::GFx::GFxPlaceObjectUnpacked *)(v18 + 16));
        Scaleform::Render::Cxform::Cxform(&v39);
        *(_OWORD *)&__that.ColorTransform.M[0][0] = *v20;
        *(_OWORD *)&__that.ColorTransform.M[1][0] = v20[1];
        *(_OWORD *)&__that.Matrix_1.M[0][0] = _xmm;
        *(__m128 *)&__that.Matrix_1.M[1][0] = _xmm;
        __that.pFilters.pObject = 0i64;
        *(_DWORD *)&__that.Flags.Flags = 0x1000000;
        __that.Ratio = 0.0;
        *(_DWORD *)&__that.ClipDepth = 0x40000;
        __that.Depth = 1;
        __that.CharacterId.Id = 1;
        __that.ClassName = 0i64;
        Scaleform::GFx::CharPosInfo::operator=((Scaleform::GFx::CharPosInfo *)(v19 + 16), &__that);
        v40[2].pNext = (Scaleform::GFx::DataAllocator::Block *)v19;
        v8->Playlist.Data.Data->pTagPtrList = (Scaleform::GFx::ExecuteTag **)&v40[2];
        v8->Playlist.Data.Data->TagCount = 1;
        if ( __that.pFilters.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)__that.pFilters.pObject);
      }
    }
    LeaveCriticalSection(&v8->PlaylistLock.cs);
    if ( !_InterlockedDecrement((volatile signed __int32 *)(v16 + 8)) )
    {
      v21 = *(_QWORD *)(v16 + 16);
      if ( v21 )
      {
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v21 + 8i64))(v21, v16);
        *(_QWORD *)(v16 + 16) = 0i64;
      }
      (**(void (__fastcall ***)(__int64, signed __int64))v16)(v16, 1i64);
    }
  }
  Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(v8, v8->Header.FrameCount, LS_LoadFinished);
  return v7 != 0i64;
}

// File Line: 497
// RVA: 0x8D9CA0
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetImageHeap(Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v1; // rbx
  Scaleform::MemoryHeap *v2; // rcx
  __int64 v3; // rax
  __int64 v4; // r8
  __int64 v5; // r9
  Scaleform::MemoryHeap *v6; // rcx
  Scaleform::MemoryHeap *v7; // rdi
  int v9; // [rsp+20h] [rbp-48h]
  __int64 v10; // [rsp+28h] [rbp-40h]
  __int64 v11; // [rsp+30h] [rbp-38h]
  __int64 v12; // [rsp+38h] [rbp-30h]
  __int64 v13; // [rsp+40h] [rbp-28h]
  __int64 v14; // [rsp+48h] [rbp-20h]
  __int64 v15; // [rsp+50h] [rbp-18h]
  __int64 v16; // [rsp+58h] [rbp-10h]

  v1 = this;
  if ( this->pImageHeap.pObject )
    return this->pImageHeap.pObject;
  v2 = this->pHeap;
  v16 = 0i64;
  v9 = 4;
  v10 = 32i64;
  v11 = 4096i64;
  v12 = 0i64;
  v13 = -1i64;
  v14 = 0i64;
  v15 = 5i64;
  v3 = (*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, const char *, int *))&v2->vfptr->gap8[24])(
         v2,
         "_Images",
         &v9);
  v6 = v1->pImageHeap.pObject;
  v7 = (Scaleform::MemoryHeap *)v3;
  if ( v6 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::MemoryHeapVtbl *, __int64, __int64, _QWORD, __int64, __int64, __int64))v6->vfptr->Release)(
      v6,
      v6->vfptr,
      v4,
      v5,
      *(_QWORD *)&v9,
      v10,
      v11,
      v12);
  v1->pImageHeap.pObject = v7;
  return v7;
}

// File Line: 525
// RVA: 0x8F8200
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::Read(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::GFx::LoadProcess *plp, Scaleform::GFx::MovieBindProcess *pbp)
{
  Scaleform::GFx::MovieBindProcess *v3; // rdi
  Scaleform::GFx::LoadProcess *v4; // r12
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // r15
  Scaleform::GFx::Stream *v6; // rbp
  _RTL_CRITICAL_SECTION *v7; // rbx
  __m128d v8; // xmm2
  __int64 v9; // r9
  int v10; // ebx
  char v11; // si
  signed int v12; // er14
  __int64 v13; // r13
  int v14; // ebx
  Scaleform::GFx::LoadStates *v15; // r14
  Scaleform::GFx::ProgressHandler *v16; // r14
  int v17; // esi
  int v18; // edi
  Scaleform::GFx::TagType v19; // ebx
  void (__fastcall *v20)(Scaleform::GFx::LoadProcess *, Scaleform::GFx::TagInfo *); // r8
  __int64 v21; // rax
  int v22; // ebx
  signed int v23; // edx
  unsigned int v24; // eax
  int v25; // ecx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v26; // rcx
  __int64 v27; // rdx
  signed int v28; // [rsp+20h] [rbp-88h]
  Scaleform::GFx::TagInfo pTagInfo; // [rsp+38h] [rbp-70h]
  Scaleform::String v30; // [rsp+48h] [rbp-60h]
  Scaleform::GFx::TagType v31; // [rsp+50h] [rbp-58h]
  int v32; // [rsp+54h] [rbp-54h]
  int v33; // [rsp+58h] [rbp-50h]
  int v34; // [rsp+5Ch] [rbp-4Ch]
  char v35; // [rsp+B0h] [rbp+8h]
  int v36; // [rsp+B8h] [rbp+10h]
  Scaleform::GFx::MovieBindProcess *v37; // [rsp+C0h] [rbp+18h]
  int v38; // [rsp+C8h] [rbp+20h]

  v37 = pbp;
  v3 = pbp;
  v4 = plp;
  v5 = this;
  v6 = plp->pAltStream;
  if ( !v6 )
    v6 = &plp->ProcessInfo.Stream;
  v7 = &this->PlaylistLock.cs;
  EnterCriticalSection(&this->PlaylistLock.cs);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v5->Playlist.Data,
    v5->Header.FrameCount);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v5->InitActionList.Data,
    v5->Header.FrameCount);
  LeaveCriticalSection(v7);
  v8 = _mm_cvtps_pd((__m128)LODWORD(v5->Header.FPS));
  v9 = v5->Header.FrameCount;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v6->vfptr,
    "Note: SWF Frame Rate = %f, Frames = %d\n");
  v5->TagCount = 0;
  v10 = 0;
  v11 = 0;
  v35 = 0;
  v12 = v5->Header.FileLength / 0x1E;
  if ( v12 < 0x2000 )
    v12 = 0x2000;
  v28 = v12;
  if ( v6->Pos + v6->FilePos - v6->DataSize >= v4->ProcessInfo.FileEndPos )
  {
LABEL_45:
    v27 = v4->LoadState;
    if ( v4->FrameTags[v27].Data.Size || !(_DWORD)v27 && v4->InitActionTags.Data.Size )
    {
      Scaleform::GFx::MovieDataDef::LoadTaskData::FinishLoadingFrame(v5, v4, 1);
      if ( v3 )
        Scaleform::GFx::MovieBindProcess::BindNextFrame(v3);
    }
    else
    {
      Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(v5, v5->LoadingFrame, LS_LoadFinished);
    }
    return;
  }
  while ( !v5->LoadingCanceled )
  {
    v13 = (unsigned int)Scaleform::GFx::Stream::OpenTag(v6, &pTagInfo);
    v36 = pTagInfo.TagLength;
    v14 = pTagInfo.TagLength + v10;
    v38 = v14;
    if ( v11 && (v5->LoadingFrame == 1 || v14 > v12 || pTagInfo.TagLength > 0x2000) )
    {
      Scaleform::WaitCondition::NotifyAll(&v5->pFrameUpdate.pObject->WC);
      v35 = 0;
      v38 = 0;
      v36 = pTagInfo.TagLength;
    }
    v15 = v4->pLoadStates.pObject;
    if ( v15->pProgressHandler.pObject )
    {
      v16 = v15->pProgressHandler.pObject;
      v17 = pTagInfo.TagDataOffset;
      v18 = pTagInfo.TagOffset;
      v19 = pTagInfo.TagType;
      Scaleform::String::String(&v30, (Scaleform::String *)&v5->FileURL.0);
      v31 = v19;
      v32 = v18;
      v33 = v36;
      v34 = v17;
      ((void (__fastcall *)(Scaleform::GFx::ProgressHandler *, Scaleform::String *, _QWORD))v16->vfptr[2].__vecDelDtor)(
        v16,
        &v30,
        0i64);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v3 = v37;
    }
    if ( (_DWORD)v13 != 1 )
    {
      if ( (unsigned int)v13 >= 0x5C )
      {
        v21 = (unsigned int)(v13 - 1000);
        if ( (unsigned int)v21 > 9 )
          goto LABEL_23;
        v20 = Scaleform::GFx::GFx_GFX_TagLoaderTable[v21];
      }
      else
      {
        v20 = Scaleform::GFx::SWF_TagLoaderTable[v13];
      }
      if ( !v20 )
      {
LABEL_23:
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v6->vfptr,
          "*** no tag loader for type %d\n");
        goto LABEL_24;
      }
      v20(v4, &pTagInfo);
    }
LABEL_24:
    v22 = v6->TagStack[--v6->TagStackEntryCount];
    v6->UnusedBits = 0;
    v23 = v6->FilePos;
    v24 = v6->DataSize;
    v25 = v6->FilePos - v24;
    if ( v22 < v25 || v22 >= v23 )
    {
      if ( (v6->ResyncFile || v6->Pos + v25 != v22)
        && ((signed int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v6->pInput.pObject->vfptr[14].__vecDelDtor)(
             v6->pInput.pObject,
             (unsigned int)v22,
             0i64) >= 0 )
      {
        v6->ResyncFile = 0;
        *(_QWORD *)&v6->Pos = 0i64;
        v6->FilePos = v22;
      }
    }
    else
    {
      v6->Pos = v22 + v24 - v23;
    }
    v6->UnusedBits = 0;
    ++v5->TagCount;
    if ( (_DWORD)v13 == 1 )
    {
      if ( !(unsigned __int8)Scaleform::GFx::MovieDataDef::LoadTaskData::FinishLoadingFrame(v5, v4, 0) )
        return;
      v11 = 1;
      v35 = 1;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v6->vfptr,
        "  ShowFrame\n");
      if ( v3 )
        Scaleform::GFx::MovieBindProcess::BindNextFrame(v3);
    }
    else
    {
      if ( !(_DWORD)v13 && v6->Pos + v6->FilePos - v6->DataSize != v4->ProcessInfo.FileEndPos )
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v6->vfptr,
          "Loader - Stream-end tag hit, but not at the end of the file yet; stopping for safety");
        goto LABEL_45;
      }
      v11 = v35;
    }
    if ( v6->Pos + v6->FilePos - v6->DataSize >= v4->ProcessInfo.FileEndPos )
      goto LABEL_45;
    v10 = v38;
    v12 = v28;
  }
  Scaleform::GFx::LoadProcess::CleanupFrameTags(v4);
  if ( v3 )
  {
    v26 = v3->pBindData.pObject;
    if ( v26 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v26, 3u);
  }
  Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(v5, v5->LoadingFrame, LS_LoadCanceled);
}

// File Line: 696
// RVA: 0x8CD5D0
__int64 __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::FinishLoadingFrame(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::GFx::LoadProcess *plp, bool finished)
{
  bool v3; // r14
  Scaleform::GFx::LoadProcess *v4; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rdi
  unsigned __int8 v6; // bp
  Scaleform::GFx::FrameBindData *v7; // rsi
  Scaleform::GFx::SWFProcessInfo *v8; // rcx
  Scaleform::Mutex *v9; // rbx
  Scaleform::Mutex *v11; // [rsp+50h] [rbp+8h]

  v3 = finished;
  v4 = plp;
  v5 = this;
  Scaleform::GFx::LoadProcess::CommitFrameTags(plp);
  v6 = 1;
  v7 = Scaleform::GFx::LoadProcess::CreateFrameBindData(v4);
  if ( v7 )
  {
    v7->Frame = v5->LoadingFrame;
    v8 = (Scaleform::GFx::SWFProcessInfo *)v4->pAltStream;
    if ( !v8 )
      v8 = &v4->ProcessInfo;
    v7->BytesLoaded = v8->Stream.Pos + v8->Stream.FilePos - v8->Stream.DataSize - v4->ProcessInfo.FileStartPos;
  }
  v9 = &v5->pFrameUpdate.pObject->mMutex;
  v11 = &v5->pFrameUpdate.pObject->mMutex;
  Scaleform::Mutex::DoLock(v9);
  if ( !v7 )
  {
    v5->LoadState = 4;
    v6 = 0;
    goto LABEL_12;
  }
  if ( v5->BindData.pFrameData.Value )
    v5->BindData.pFrameDataLast->pNextFrame.Value = v7;
  else
    v5->BindData.pFrameData.Value = v7;
  v5->BindData.pFrameDataLast = v7;
  ++v5->LoadingFrame;
  v9 = v11;
  if ( v3 )
  {
    v5->LoadState = 2;
LABEL_12:
    if ( v3 || !v6 )
      Scaleform::WaitCondition::NotifyAll(&v5->pFrameUpdate.pObject->WC);
  }
  Scaleform::Mutex::Unlock(v9);
  return v6;
}

// File Line: 749
// RVA: 0x9174B0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(Scaleform::GFx::MovieDataDef::LoadTaskData *this, unsigned int loadingFrame, Scaleform::GFx::MovieDataDef::MovieLoadState loadState)
{
  Scaleform::GFx::MovieDataDef::MovieLoadState v3; // esi
  unsigned int v4; // ebp
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rdi
  Scaleform::GFx::LoadUpdateSync *v6; // rbx

  v3 = loadState;
  v4 = loadingFrame;
  v5 = this;
  v6 = this->pFrameUpdate.pObject;
  if ( v6 )
  {
    Scaleform::Mutex::DoLock(&v6->mMutex);
    v5->LoadingFrame = v4;
    v5->LoadState = v3;
    Scaleform::WaitCondition::NotifyAll(&v5->pFrameUpdate.pObject->WC);
    Scaleform::Mutex::Unlock(&v6->mMutex);
  }
  else
  {
    this->LoadingFrame = loadingFrame;
    this->LoadState = loadState;
  }
}

// File Line: 795
// RVA: 0x91A0B0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::WaitForFrame(Scaleform::GFx::MovieDataDef::LoadTaskData *this, unsigned int frame)
{
  unsigned int v2; // esi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v3; // rdi
  Scaleform::Mutex *v4; // rbx

  v2 = frame;
  v3 = this;
  if ( this->LoadState <= 1 && this->LoadingFrame <= frame )
  {
    v4 = &this->pFrameUpdate.pObject->mMutex;
    Scaleform::Mutex::DoLock(v4);
    while ( v3->LoadState <= 1 )
    {
      if ( v3->LoadingFrame > v2 )
        break;
      Scaleform::WaitCondition::Wait(&v3->pFrameUpdate.pObject->WC, &v3->pFrameUpdate.pObject->mMutex, 0xFFFFFFFF);
    }
    Scaleform::Mutex::Unlock(v4);
  }
}

// File Line: 834
// RVA: 0x8B1EF0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(Scaleform::GFx::MovieDataDef::LoadTaskData *this, __int64 rid, Scaleform::GFx::Resource *pres)
{
  Scaleform::GFx::Resource *v3; // rbx
  Scaleform::GFx::ResourceId *v4; // rsi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rdi
  __int64 v6; // rbx
  __int64 v7; // rcx
  int v8; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::Resource *v9; // [rsp+30h] [rbp-28h]
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef key; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::MovieDataDef::LoadTaskData *v11; // [rsp+60h] [rbp+8h]

  v3 = pres;
  v4 = (Scaleform::GFx::ResourceId *)rid;
  v5 = this;
  v11 = 0i64;
  if ( this->LoadState < 2 )
  {
    v11 = this;
    EnterCriticalSection(&this->ResourceLock.cs);
  }
  v8 = 0;
  v9 = v3;
  if ( v3 )
    _InterlockedExchangeAdd(&v3->RefCount.Value, 1u);
  key.pFirst = v4;
  key.pSecond = (Scaleform::GFx::ResourceHandle *)&v8;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> > *)&v5->Resources.mHash.pTable,
    &v5->Resources,
    &key,
    v4->Id ^ ((unsigned __int64)v4->Id >> 8));
  if ( !v8 )
  {
    v6 = (__int64)v9;
    if ( v9 )
    {
      if ( !_InterlockedDecrement(&v9->RefCount.Value) )
      {
        v7 = *(_QWORD *)(v6 + 16);
        if ( v7 )
        {
          (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v7 + 8i64))(v7, v6);
          *(_QWORD *)(v6 + 16) = 0i64;
        }
        (**(void (__fastcall ***)(__int64, signed __int64))v6)(v6, 1i64);
      }
    }
  }
  if ( v11 )
    LeaveCriticalSection(&v11->ResourceLock.cs);
}

// File Line: 842
// RVA: 0x8B1CC0
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::AddNewResourceHandle(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::GFx::ResourceHandle *result, __int64 rid)
{
  Scaleform::GFx::ResourceId *v3; // rbp
  Scaleform::GFx::ResourceHandle *v4; // rdi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rsi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // rbx
  unsigned int v7; // eax
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef key; // [rsp+30h] [rbp-28h]

  v3 = (Scaleform::GFx::ResourceId *)rid;
  v4 = result;
  v5 = this;
  v6 = 0i64;
  v7 = this->ResIndexCounter;
  result->HType = 1;
  result->BindIndex = v7;
  ++this->ResIndexCounter;
  if ( this->LoadState < 2 )
  {
    v6 = this;
    EnterCriticalSection(&this->ResourceLock.cs);
  }
  key.pFirst = v3;
  key.pSecond = v4;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> > *)&v5->Resources.mHash.pTable,
    &v5->Resources,
    &key,
    v3->Id ^ ((unsigned __int64)v3->Id >> 8));
  if ( v6 )
    LeaveCriticalSection(&v6->ResourceLock.cs);
  return v4;
}

// File Line: 852
// RVA: 0x8DDB80
__int64 __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::GFx::ResourceHandle *phandle, __int64 rid)
{
  Scaleform::GFx::ResourceId *v3; // rsi
  Scaleform::GFx::ResourceHandle *v4; // rbp
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rdi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> > *v7; // rdi
  signed __int64 v8; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> > v9; // rax
  unsigned __int8 v10; // di

  v3 = (Scaleform::GFx::ResourceId *)rid;
  v4 = phandle;
  v5 = this;
  v6 = 0i64;
  if ( this->LoadState < 2 )
  {
    v6 = this;
    EnterCriticalSection(&this->ResourceLock.cs);
  }
  v7 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> > *)&v5->Resources.mHash.pTable;
  if ( !v7->pTable
    || (v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF>>::findIndexCore<Scaleform::GFx::ResourceId>(
               v7,
               v3,
               v7->pTable->SizeMask & (v3->Id ^ ((unsigned __int64)v3->Id >> 8))),
        v8 < 0) )
  {
    v7 = 0i64;
    v8 = 0i64;
  }
  if ( v7 && (v9.pTable = v7->pTable) != 0i64 && v8 <= (signed __int64)v9.pTable->SizeMask )
  {
    Scaleform::GFx::ResourceHandle::operator=(v4, (Scaleform::GFx::ResourceHandle *)&v9.pTable[2 * (v8 + 1)]);
    v10 = 1;
  }
  else
  {
    v10 = 0;
  }
  if ( v6 )
    LeaveCriticalSection(&v6->ResourceLock.cs);
  return v10;
}

// File Line: 887
// RVA: 0x8B1160
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::AddFrameName(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::String *name, Scaleform::GFx::LogState *plog)
{
  Scaleform::String *v3; // rsi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v4; // rdi
  _RTL_CRITICAL_SECTION *v5; // rbx

  v3 = name;
  v4 = this;
  v5 = &this->PlaylistLock.cs;
  EnterCriticalSection(&this->PlaylistLock.cs);
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::SetCaseInsensitive(
    &v4->NamedFrames,
    v3,
    &v4->LoadingFrame);
  LeaveCriticalSection(v5);
}

// File Line: 897
// RVA: 0x908A10
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::SetLoadingPlaylistFrame(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::GFx::TimelineDef::Frame *frame, Scaleform::GFx::LogState *plog)
{
  Scaleform::GFx::LogState *v3; // rsi
  Scaleform::GFx::TimelineDef::Frame *v4; // r14
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rdi
  _RTL_CRITICAL_SECTION *v6; // rbx
  unsigned __int64 v7; // r9
  unsigned __int64 v8; // rbp
  Scaleform::Log *v9; // rax
  signed __int64 v10; // r9

  v3 = plog;
  v4 = frame;
  v5 = this;
  v6 = &this->PlaylistLock.cs;
  EnterCriticalSection(&this->PlaylistLock.cs);
  v7 = v5->LoadingFrame;
  if ( v5->Playlist.Data.Size > v7 )
  {
    v10 = (signed __int64)&v5->Playlist.Data.Data[v7];
    *(_QWORD *)v10 = v4->pTagPtrList;
    *(_DWORD *)(v10 + 8) = v4->TagCount;
  }
  else if ( v3 && (v3->pLog.pObject || Scaleform::Log::GetGlobalLog()) )
  {
    v8 = v5->Playlist.Data.Size;
    v9 = v3->pLog.pObject;
    if ( !v9 )
      v9 = Scaleform::Log::GetGlobalLog();
    Scaleform::Log::LogError(
      v9,
      "Invalid SWF file: failed to load frame #%d since total frames counter is %d",
      v5->LoadingFrame + 1,
      (unsigned int)v8,
      -2i64);
  }
  LeaveCriticalSection(v6);
}

// File Line: 912
// RVA: 0x908940
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::SetLoadingInitActionFrame(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::GFx::TimelineDef::Frame *frame, Scaleform::GFx::LogState *plog)
{
  Scaleform::GFx::LogState *v3; // rsi
  Scaleform::GFx::TimelineDef::Frame *v4; // r14
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rdi
  _RTL_CRITICAL_SECTION *v6; // rbx
  unsigned __int64 v7; // rcx
  unsigned __int64 v8; // rbp
  Scaleform::Log *v9; // rax
  signed __int64 v10; // rcx

  v3 = plog;
  v4 = frame;
  v5 = this;
  v6 = &this->PlaylistLock.cs;
  EnterCriticalSection(&this->PlaylistLock.cs);
  v7 = v5->LoadingFrame;
  if ( v5->InitActionList.Data.Size > v7 )
  {
    v10 = (signed __int64)&v5->InitActionList.Data.Data[v7];
    *(_QWORD *)v10 = v4->pTagPtrList;
    *(_DWORD *)(v10 + 8) = v4->TagCount;
    ++v5->InitActionsCnt;
  }
  else if ( v3 && (v3->pLog.pObject || Scaleform::Log::GetGlobalLog()) )
  {
    v8 = v5->InitActionList.Data.Size;
    v9 = v3->pLog.pObject;
    if ( !v9 )
      v9 = Scaleform::Log::GetGlobalLog();
    Scaleform::Log::LogError(
      v9,
      "Invalid SWF file: failed to load init action frame #%d since total frames counter is %d",
      v5->LoadingFrame + 1,
      (unsigned int)v8,
      -2i64);
  }
  LeaveCriticalSection(v6);
}

// File Line: 943
// RVA: 0x8DA9E0
bool __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetLabeledFrame(Scaleform::GFx::MovieDataDef::LoadTaskData *this, const char *label, unsigned int *frameNumber, bool translateNumbers)
{
  bool v4; // si
  unsigned int *v5; // rbp
  const char *v6; // r14
  Scaleform::GFx::MovieDataDef::LoadTaskData *v7; // rdi
  _RTL_CRITICAL_SECTION *v9; // rbx
  bool v10; // di

  v4 = translateNumbers;
  v5 = frameNumber;
  v6 = label;
  v7 = this;
  if ( this->LoadState >= 2 )
    return Scaleform::GFx::MovieDataDef::TranslateFrameString(&this->NamedFrames, label, frameNumber, translateNumbers);
  v9 = &this->PlaylistLock.cs;
  EnterCriticalSection(&this->PlaylistLock.cs);
  v10 = Scaleform::GFx::MovieDataDef::TranslateFrameString(&v7->NamedFrames, v6, v5, v4);
  LeaveCriticalSection(v9);
  return v10;
}

// File Line: 953
// RVA: 0x8D8D50
Scaleform::String *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabel(Scaleform::GFx::MovieDataDef::LoadTaskData *this, unsigned int frameNumber, unsigned int *exactFrameNumberForLabel)
{
  unsigned int *v3; // rsi
  unsigned int v4; // ebp
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rdi
  _RTL_CRITICAL_SECTION *v7; // rbx
  Scaleform::String *v8; // rdi

  v3 = exactFrameNumberForLabel;
  v4 = frameNumber;
  v5 = this;
  if ( this->LoadState >= 2 )
    return Scaleform::GFx::MovieDataDef::TranslateNumberToFrameString(
             &this->NamedFrames,
             frameNumber,
             exactFrameNumberForLabel);
  v7 = &this->PlaylistLock.cs;
  EnterCriticalSection(&this->PlaylistLock.cs);
  v8 = Scaleform::GFx::MovieDataDef::TranslateNumberToFrameString(&v5->NamedFrames, v4, v3);
  LeaveCriticalSection(v7);
  return v8;
}

// File Line: 963
// RVA: 0x8D8E00
Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabels(Scaleform::GFx::MovieDataDef::LoadTaskData *this, unsigned int frameNumber, Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *destArr)
{
  Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *v3; // r15
  unsigned int v4; // er12
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // r13
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v6; // r9
  Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *v7; // r14
  unsigned __int64 v8; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v9; // rcx
  int v10; // ebp
  __int64 v11; // rbx
  __int64 v12; // rdi
  __int64 v13; // rcx
  Scaleform::String *v14; // rsi
  Scaleform::String *v15; // rcx
  unsigned __int64 v16; // rcx
  _QWORD *v17; // rax
  __m128i v19; // [rsp+30h] [rbp-48h]
  char v20; // [rsp+80h] [rbp+8h]

  v3 = destArr;
  v4 = frameNumber;
  v5 = this;
  v20 = 0;
  if ( this->LoadState < 2 )
  {
    EnterCriticalSection(&this->PlaylistLock.cs);
    v20 = 1;
  }
  v6 = v5->NamedFrames.mHash.pTable;
  v7 = 0i64;
  if ( v6 )
  {
    v8 = 0i64;
    v9 = v6 + 1;
    do
    {
      if ( v9->EntryCount != -2i64 )
        break;
      ++v8;
      v9 += 2;
    }
    while ( v8 <= v6->SizeMask );
    v19.m128i_i64[0] = (__int64)&v5->NamedFrames;
    v19.m128i_i64[1] = v8;
  }
  else
  {
    v19 = 0ui64;
  }
  _mm_store_si128(&v19, v19);
  v10 = 0;
  v11 = v19.m128i_i64[1];
  v12 = v19.m128i_i64[0];
  while ( v12 )
  {
    v13 = *(_QWORD *)v12;
    if ( !*(_QWORD *)v12 || v11 > *(_QWORD *)(v13 + 8) )
      break;
    if ( v4 == *(_DWORD *)(32 * v11 + v13 + 40) )
    {
      v14 = (Scaleform::String *)(32 * v11 + v13);
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Data.Data,
        v3,
        v3->Data.Size + 1);
      v15 = &v3->Data.Data[v3->Data.Size - 1];
      if ( v15 )
        Scaleform::String::String(v15, v14 + 4);
      ++v10;
    }
    v16 = *(_QWORD *)(*(_QWORD *)v12 + 8i64);
    if ( v11 <= (signed __int64)v16 && ++v11 <= v16 )
    {
      v17 = (_QWORD *)(*(_QWORD *)v12 + 32 * v11 + 16);
      do
      {
        if ( *v17 != -2i64 )
          break;
        ++v11;
        v17 += 4;
      }
      while ( v11 <= v16 );
    }
  }
  if ( v20 )
    LeaveCriticalSection(&v5->PlaylistLock.cs);
  if ( v10 )
    v7 = v3;
  return v7;
}

// File Line: 989
// RVA: 0x8B1FF0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::AddScene(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::String *name, unsigned int off)
{
  unsigned int v3; // esi
  Scaleform::String *v4; // r14
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rbx
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> > *v6; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *v7; // rax
  Scaleform::MemoryHeap *v8; // rbx
  unsigned __int64 v9; // rdx
  Scaleform::StringDH v10; // [rsp+30h] [rbp-40h]
  unsigned int v11; // [rsp+40h] [rbp-30h]
  int v12; // [rsp+44h] [rbp-2Ch]
  __int128 p; // [rsp+48h] [rbp-28h]
  __int64 v14; // [rsp+58h] [rbp-18h]
  Scaleform::MemoryHeap *v15; // [rsp+60h] [rbp-10h]

  v3 = off;
  v4 = name;
  v5 = this;
  v6 = &this->Scenes;
  if ( !this->Scenes.pObject )
  {
    v7 = (Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *)this->pHeap->vfptr->Alloc(this->pHeap, 24ui64, 0i64);
    if ( v7 )
    {
      v7->Data.Data = 0i64;
      v7->Data.Size = 0i64;
      v7->Data.Policy.Capacity = 0i64;
    }
    else
    {
      v7 = 0i64;
    }
    Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy>>::operator=(
      v6,
      v7);
  }
  v8 = v5->pHeap;
  Scaleform::StringDH::CopyConstructHelper(&v10, v4, v8);
  v11 = v3;
  v12 = 0;
  p = 0ui64;
  v14 = 0i64;
  v15 = v8;
  Scaleform::ArrayData<Scaleform::GFx::MovieDataDef::SceneInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieDataDef::SceneInfo,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &v6->pObject->Data,
    (Scaleform::GFx::MovieDataDef::SceneInfo *)&v10);
  Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::DestructArray(
    (Scaleform::GFx::MovieDataDef::FrameLabelInfo *)p,
    *((unsigned __int64 *)&p + 1));
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)p);
  v9 = v10.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v10.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v9);
}

// File Line: 1020
// RVA: 0x8DDFE0
Scaleform::GFx::MovieDataDef::SceneInfo *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetScenes(Scaleform::GFx::MovieDataDef::LoadTaskData *this, unsigned __int64 *count)
{
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *v2; // rax
  Scaleform::GFx::MovieDataDef::SceneInfo *result; // rax

  v2 = this->Scenes.pObject;
  if ( v2 )
  {
    *count = v2->Data.Size;
    result = this->Scenes.pObject->Data.Data;
  }
  else
  {
    *count = 0i64;
    result = 0i64;
  }
  return result;
}

// File Line: 1025
// RVA: 0x8DC150
Scaleform::GFx::TimelineDef::Frame *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetPlaylist(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::GFx::TimelineDef::Frame *result, int frameNumber)
{
  __int64 v3; // rbp
  Scaleform::GFx::TimelineDef::Frame *v4; // rdi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rsi
  Scaleform::GFx::TimelineDef::Frame *v6; // r8
  _RTL_CRITICAL_SECTION *v7; // rbx
  signed __int64 v8; // rcx

  v3 = frameNumber;
  v4 = result;
  v5 = this;
  if ( this->LoadState < 2 )
  {
    v7 = &this->PlaylistLock.cs;
    EnterCriticalSection(&this->PlaylistLock.cs);
    v8 = (signed __int64)&v5->Playlist.Data.Data[v3];
    v4->pTagPtrList = *(Scaleform::GFx::ExecuteTag ***)v8;
    v4->TagCount = *(_DWORD *)(v8 + 8);
    LeaveCriticalSection(v7);
  }
  else
  {
    v6 = &this->Playlist.Data.Data[frameNumber];
    result->pTagPtrList = v6->pTagPtrList;
    result->TagCount = v6->TagCount;
  }
  return v4;
}

// File Line: 1039
// RVA: 0x8DA130
__int64 __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetInitActions(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::GFx::TimelineDef::Frame *pframe, int frameNumber)
{
  __int64 v3; // rsi
  Scaleform::GFx::TimelineDef::Frame *v4; // r14
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rdi
  _RTL_CRITICAL_SECTION *v6; // rbx
  unsigned __int8 v7; // di
  signed __int64 v8; // rcx

  v3 = frameNumber;
  v4 = pframe;
  v5 = this;
  v6 = &this->PlaylistLock.cs;
  EnterCriticalSection(&this->PlaylistLock.cs);
  if ( (unsigned int)v3 < v5->InitActionList.Data.Size )
  {
    v8 = (signed __int64)&v5->InitActionList.Data.Data[v3];
    v4->pTagPtrList = *(Scaleform::GFx::ExecuteTag ***)v8;
    v4->TagCount = *(_DWORD *)(v8 + 8);
    v7 = 1;
  }
  else
  {
    v7 = 0;
  }
  LeaveCriticalSection(v6);
  return v7;
}

// File Line: 1091
// RVA: 0x896E60
void __fastcall Scaleform::GFx::GFxMovieDataDefFileKeyData::GFxMovieDataDefFileKeyData(Scaleform::GFx::GFxMovieDataDefFileKeyData *this, const char *pfilename, __int64 modifyTime, Scaleform::GFx::FileOpener *pfileOpener, Scaleform::GFx::ImageCreator *pimageCreator)
{
  Scaleform::GFx::FileOpener *v5; // rbp
  __int64 v6; // rsi
  const char *v7; // rdi
  Scaleform::GFx::GFxMovieDataDefFileKeyData *v8; // r14
  Scaleform::Render::RenderBuffer *v9; // rcx
  Scaleform::Render::RenderBuffer *v10; // rcx

  v5 = pfileOpener;
  v6 = modifyTime;
  v7 = pfilename;
  v8 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::GFxMovieDataDefFileKeyData,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::GFxMovieDataDefFileKeyData::`vftable;
  Scaleform::String::String(&this->FileName);
  v8->pFileOpener.pObject = 0i64;
  v8->pImageCreator.pObject = 0i64;
  Scaleform::String::operator=(&v8->FileName, v7);
  v8->ModifyTime = v6;
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v5);
  v9 = (Scaleform::Render::RenderBuffer *)v8->pFileOpener.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v8->pFileOpener.pObject = v5;
  if ( pimageCreator )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pimageCreator);
  v10 = (Scaleform::Render::RenderBuffer *)v8->pImageCreator.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v8->pImageCreator.pObject = pimageCreator;
}

// File Line: 1146
// RVA: 0x8D97F0
unsigned __int64 __fastcall Scaleform::GFx::GFxMovieDataDefFileKeyInterface::GetHashCode(Scaleform::GFx::GFxMovieDataDefFileKeyInterface *this, void *hdata)
{
  return Scaleform::String::BernsteinHashFunction(
           (const void *)((*((_QWORD *)hdata + 2) & 0xFFFFFFFFFFFFFFFCui64) + 12),
           *(_QWORD *)(*((_QWORD *)hdata + 2) & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
           0x1505ui64) ^ *((_QWORD *)hdata + 5) ^ *((_QWORD *)hdata + 3) ^ *((_QWORD *)hdata + 4) ^ ((*((_QWORD *)hdata + 5) ^ *((_QWORD *)hdata + 3)) >> 7);
}

// File Line: 1152
// RVA: 0x8E7ED0
char __fastcall Scaleform::GFx::GFxMovieDataDefFileKeyInterface::KeyEquals(Scaleform::GFx::GFxMovieDataDefFileKeyInterface *this, void *hdata, Scaleform::GFx::ResourceKey *other)
{
  char result; // al
  _QWORD *v4; // r8
  unsigned __int8 *v5; // rax
  unsigned __int64 v6; // r8
  int v7; // ecx
  int v8; // edx

  if ( this != (Scaleform::GFx::GFxMovieDataDefFileKeyInterface *)other->pKeyInterface )
    return 0;
  v4 = other->hKeyData;
  if ( *((_QWORD *)hdata + 3) != v4[3] || *((_OWORD *)hdata + 2) != *((_OWORD *)v4 + 2) )
    goto LABEL_13;
  v5 = (unsigned __int8 *)((*((_QWORD *)hdata + 2) & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v6 = (v4[2] & 0xFFFFFFFFFFFFFFFCui64) - (*((_QWORD *)hdata + 2) & 0xFFFFFFFFFFFFFFFCui64);
  do
  {
    v7 = v5[v6];
    v8 = *v5 - v7;
    if ( *v5 != v7 )
      break;
    ++v5;
  }
  while ( v7 );
  if ( v8 )
LABEL_13:
    result = 0;
  else
    result = 1;
  return result;
}

// File Line: 1160
// RVA: 0x8D7B80
const char *__fastcall Scaleform::GFx::GFxMovieDataDefFileKeyInterface::GetFileURL(Scaleform::GFx::GFxMovieDataDefFileKeyInterface *this, void *hdata)
{
  return (const char *)((*((_QWORD *)hdata + 2) & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 1168
// RVA: 0x159C240
__int64 Scaleform::GFx::_dynamic_initializer_for__GFxMovieDataDefFileKeyInterface_Instance__()
{
  GFxMovieDataDefFileKeyInterface_Instance.vfptr = (Scaleform::GFx::ResourceKey::KeyInterfaceVtbl *)&Scaleform::GFx::GFxMovieDataDefFileKeyInterface::`vftable;
  return atexit(Scaleform::GFx::_dynamic_atexit_destructor_for__GFxMovieDataDefFileKeyInterface_Instance__);
}

// File Line: 1172
// RVA: 0x8C1450
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::MovieDataDef::CreateMovieFileKey(Scaleform::GFx::ResourceKey *result, const char *pfilename, __int64 modifyTime, Scaleform::GFx::FileOpener *pfileOpener, Scaleform::GFx::ImageCreator *pimageCreator)
{
  Scaleform::GFx::FileOpener *v5; // rsi
  __int64 v6; // rbp
  const char *v7; // r14
  Scaleform::GFx::ResourceKey *v8; // rdi
  Scaleform::Render::RenderBuffer *v9; // rbx
  Scaleform::GFx::GFxMovieDataDefFileKeyData *v10; // rax
  Scaleform::Render::RenderBuffer *v11; // rax

  v5 = pfileOpener;
  v6 = modifyTime;
  v7 = pfilename;
  v8 = result;
  v9 = 0i64;
  v10 = (Scaleform::GFx::GFxMovieDataDefFileKeyData *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        48ui64,
                                                        0i64);
  if ( v10 )
  {
    Scaleform::GFx::GFxMovieDataDefFileKeyData::GFxMovieDataDefFileKeyData(v10, v7, v6, v5, pimageCreator);
    v9 = v11;
  }
  GFxMovieDataDefFileKeyInterface_Instance.vfptr->AddRef(
    (Scaleform::GFx::ResourceKey::KeyInterface *)&GFxMovieDataDefFileKeyInterface_Instance,
    v9);
  v8->pKeyInterface = (Scaleform::GFx::ResourceKey::KeyInterface *)&GFxMovieDataDefFileKeyInterface_Instance;
  v8->hKeyData = v9;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  return v8;
}

// File Line: 1182
// RVA: 0x8DDC70
Scaleform::String *__fastcall Scaleform::GFx::MovieDataDef::GetResourceName(Scaleform::GFx::MovieDataDef *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rbx
  const char *v3; // rax

  v2 = result;
  v3 = Scaleform::GetShortFilename((const char *)(((_QWORD)this->vfptr[2].GetResourceName & 0xFFFFFFFFFFFFFFFCui64) + 12));
  Scaleform::String::String(v2, v3);
  return v2;
}

// File Line: 1201
// RVA: 0x89AFE0
void __fastcall Scaleform::GFx::MovieDefImpl::MovieDefImpl(Scaleform::GFx::MovieDefImpl *this, Scaleform::GFx::MovieDataDef *pdataDef, Scaleform::GFx::MovieDefBindStates *pstates, Scaleform::GFx::LoaderImpl *ploaderImpl, unsigned int loadConstantFlags, Scaleform::GFx::StateBagImpl *pdelegateState, Scaleform::MemoryHeap *pargHeap, bool fullyLoaded, unsigned __int64 memoryArena)
{
  Scaleform::GFx::Resource *v9; // rbp
  Scaleform::GFx::Resource *v10; // r15
  Scaleform::GFx::MovieDataDef *v11; // r13
  Scaleform::GFx::MovieDefImpl *v12; // rdi
  volatile int v13; // et1
  __int64 v14; // rax
  Scaleform::GFx::StateBagImpl *v15; // rsi
  Scaleform::MemoryHeap *v16; // r14
  const char *v17; // rax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v18; // rax
  __int64 v19; // rax
  __int64 v20; // rbx
  Scaleform::Render::RenderBuffer *v21; // rcx
  Scaleform::Render::RenderBuffer *v22; // rcx
  Scaleform::Render::RenderBuffer *v23; // rcx
  Scaleform::MemoryHeap *v24; // rax
  Scaleform::GFx::StateBagImpl *v25; // rax
  Scaleform::Render::RenderBuffer *v26; // rcx
  unsigned int v27; // [rsp+40h] [rbp-78h]
  __int64 v28; // [rsp+48h] [rbp-70h]
  __int64 v29; // [rsp+50h] [rbp-68h]
  __int64 v30; // [rsp+58h] [rbp-60h]
  __int64 v31; // [rsp+60h] [rbp-58h]
  __int64 v32; // [rsp+68h] [rbp-50h]
  __int64 v33; // [rsp+70h] [rbp-48h]
  unsigned __int64 v34; // [rsp+78h] [rbp-40h]
  Scaleform::String v35; // [rsp+D0h] [rbp+18h]
  void *v36; // [rsp+D8h] [rbp+20h]

  v9 = (Scaleform::GFx::Resource *)ploaderImpl;
  v10 = (Scaleform::GFx::Resource *)pstates;
  v11 = pdataDef;
  v12 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  v13 = this->RefCount.Value;
  v14 = (unsigned int)this->RefCount.Value;
  this->RefCount.Value = 1;
  v15 = 0i64;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::MovieDef::`vftable{for `Scaleform::GFx::Resource};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::MovieDef::`vftable{for `Scaleform::GFx::StateBag};
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::MovieDefImpl::`vftable{for `Scaleform::GFx::Resource};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::MovieDefImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->pStateBag.pObject = 0i64;
  this->pLoaderImpl.pObject = 0i64;
  this->pBindStates.pObject = 0i64;
  v36 = &this->ReleaseNotifiers;
  this->ReleaseNotifiers.pTable = 0i64;
  Scaleform::Lock::Lock(&this->ReleaseNotifiersLock, 0);
  v12->pBindData.pObject = 0i64;
  v16 = pargHeap;
  v36 = pargHeap;
  if ( !pargHeap )
  {
    v17 = Scaleform::GetShortFilename((const char *)((v11->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                   + 12));
    Scaleform::String::String(&v35, "MovieDef  \"", v17, "\"");
    v27 = (loadConstantFlags >> 16) & 0x1000;
    v28 = 16i64;
    v29 = 4096i64;
    v30 = 4096i64;
    v31 = -1i64;
    v32 = 0i64;
    v33 = 2i64;
    v34 = memoryArena;
    v16 = (Scaleform::MemoryHeap *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, unsigned __int64, unsigned int *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
                                     Scaleform::Memory::pGlobalHeap,
                                     (v35.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                                     &v27);
    v36 = v16;
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((v35.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
  v18 = (Scaleform::GFx::MovieDefImpl::BindTaskData *)v16->vfptr->Alloc(v16, 256ui64, 0i64);
  if ( v18 )
  {
    Scaleform::GFx::MovieDefImpl::BindTaskData::BindTaskData(v18, v16, v11, v12, loadConstantFlags, fullyLoaded);
    v20 = v19;
  }
  else
  {
    v20 = 0i64;
  }
  v21 = (Scaleform::Render::RenderBuffer *)v12->pBindData.pObject;
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
  v12->pBindData.pObject = (Scaleform::GFx::MovieDefImpl::BindTaskData *)v20;
  if ( !pargHeap )
    Scaleform::MemoryHeap::ReleaseOnFree((ANTLR3_COMMON_TOKEN_struct *)v16, v20);
  if ( v9 )
    Scaleform::Render::RenderBuffer::AddRef(v9);
  v22 = (Scaleform::Render::RenderBuffer *)v12->pLoaderImpl.pObject;
  if ( v22 )
    Scaleform::RefCountImpl::Release(v22);
  v12->pLoaderImpl.pObject = (Scaleform::GFx::LoaderImpl *)v9;
  if ( v10 )
    Scaleform::Render::RenderBuffer::AddRef(v10);
  v23 = (Scaleform::Render::RenderBuffer *)v12->pBindStates.pObject;
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  v12->pBindStates.pObject = (Scaleform::GFx::MovieDefBindStates *)v10;
  v24 = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                   Scaleform::Memory::pGlobalHeap,
                                   88i64);
  pargHeap = v24;
  if ( v24 )
  {
    Scaleform::GFx::StateBagImpl::StateBagImpl((Scaleform::GFx::StateBagImpl *)v24, pdelegateState);
    v15 = v25;
  }
  v26 = (Scaleform::Render::RenderBuffer *)v12->pStateBag.pObject;
  if ( v26 )
    Scaleform::RefCountImpl::Release(v26);
  v12->pStateBag.pObject = v15;
}

// File Line: 1234
// RVA: 0x8A63C0
void __fastcall Scaleform::GFx::MovieDefImpl::~MovieDefImpl(Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::GFx::MovieDefImpl *v1; // r14
  _RTL_CRITICAL_SECTION *v2; // rbx
  void **v3; // r15
  Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > >::TableType *v4; // rcx
  signed __int64 v5; // rsi
  unsigned __int64 v6; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > >::TableType *v7; // rax
  __int64 v8; // rcx
  __int64 v9; // rcx
  unsigned __int64 v10; // rdx
  _QWORD *v11; // rcx
  Scaleform::Render::RenderBuffer *v12; // rcx
  __int64 v13; // rcx
  signed __int64 v14; // rdx
  Scaleform::Render::RenderBuffer *v15; // rcx
  Scaleform::Render::RenderBuffer *v16; // rcx
  Scaleform::Render::RenderBuffer *v17; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::MovieDefImpl::`vftable{for `Scaleform::GFx::Resource};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::MovieDefImpl::`vftable{for `Scaleform::GFx::StateBag};
  v2 = &this->ReleaseNotifiersLock.cs;
  EnterCriticalSection(&this->ReleaseNotifiersLock.cs);
  v3 = (void **)&v1->ReleaseNotifiers.pTable;
  v4 = v1->ReleaseNotifiers.pTable;
  if ( v4 )
  {
    v6 = 0i64;
    v7 = v4 + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++v6;
      v7 = (Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > >::TableType *)((char *)v7 + 24);
    }
    while ( v6 <= v4->SizeMask );
    v5 = (signed __int64)&v1->ReleaseNotifiers;
  }
  else
  {
    v5 = 0i64;
    v6 = 0i64;
  }
  while ( v5 )
  {
    v8 = *(_QWORD *)v5;
    if ( !*(_QWORD *)v5 || (signed __int64)v6 > *(_QWORD *)(v8 + 8) )
      break;
    v9 = *(_QWORD *)(v8 + 24 * v6 + 32);
    if ( v9 )
      (*(void (__fastcall **)(__int64, Scaleform::GFx::MovieDefImpl *))(*(_QWORD *)v9 + 8i64))(v9, v1);
    v10 = *(_QWORD *)(*(_QWORD *)v5 + 8i64);
    if ( (signed __int64)v6 <= (signed __int64)v10 && ++v6 <= v10 )
    {
      v11 = (_QWORD *)(*(_QWORD *)v5 + 24 * v6 + 16);
      do
      {
        if ( *v11 != -2i64 )
          break;
        ++v6;
        v11 += 3;
      }
      while ( v6 <= v10 );
    }
  }
  LeaveCriticalSection(v2);
  Scaleform::GFx::MovieDefImpl::BindTaskData::OnMovieDefRelease(v1->pBindData.pObject);
  v12 = (Scaleform::Render::RenderBuffer *)v1->pBindData.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  Scaleform::Lock::~Lock(v2);
  if ( *v3 )
  {
    v13 = 0i64;
    v14 = *((_QWORD *)*v3 + 1) + 1i64;
    do
    {
      if ( *(_QWORD *)((char *)*v3 + v13 + 16) != -2i64 )
        *(_QWORD *)((char *)*v3 + v13 + 16) = -2i64;
      v13 += 24i64;
      --v14;
    }
    while ( v14 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v3);
    *v3 = 0i64;
  }
  v15 = (Scaleform::Render::RenderBuffer *)v1->pBindStates.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  v16 = (Scaleform::Render::RenderBuffer *)v1->pLoaderImpl.pObject;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  v17 = (Scaleform::Render::RenderBuffer *)v1->pStateBag.pObject;
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  v1->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  v1->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 1250
// RVA: 0x8B1E90
void __fastcall Scaleform::GFx::MovieDefImpl::AddReleaseNotifier(Scaleform::GFx::MovieDefImpl *this, Scaleform::GFx::MovieDefImpl::ReleaseNotifier *rn)
{
  Scaleform::GFx::MovieDefImpl *v2; // rdi
  _RTL_CRITICAL_SECTION *v3; // rbx
  Scaleform::GFx::MovieDefImpl::ReleaseNotifier *key; // [rsp+48h] [rbp+10h]

  key = rn;
  v2 = this;
  v3 = &this->ReleaseNotifiersLock.cs;
  EnterCriticalSection(&this->ReleaseNotifiersLock.cs);
  Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>>>::Set<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>(
    (Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > > *)&v2->ReleaseNotifiers.pTable,
    &v2->ReleaseNotifiers,
    &key);
  LeaveCriticalSection(v3);
}

// File Line: 1256
// RVA: 0x8FFC10
void __fastcall Scaleform::GFx::MovieDefImpl::RemoveReleaseNotifier(Scaleform::GFx::MovieDefImpl *this, Scaleform::GFx::MovieDefImpl::ReleaseNotifier *rn)
{
  Scaleform::GFx::MovieDefImpl *v2; // rdi
  _RTL_CRITICAL_SECTION *v3; // rbx
  Scaleform::GFx::MovieDefImpl::ReleaseNotifier *key; // [rsp+48h] [rbp+10h]

  key = rn;
  v2 = this;
  v3 = &this->ReleaseNotifiersLock.cs;
  EnterCriticalSection(&this->ReleaseNotifiersLock.cs);
  Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>>>::RemoveAlt<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>(
    (Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > > *)&v2->ReleaseNotifiers.pTable,
    &key);
  LeaveCriticalSection(v3);
}

// File Line: 1270
// RVA: 0x89A900
void __fastcall Scaleform::GFx::MovieBindProcess::MovieBindProcess(Scaleform::GFx::MovieBindProcess *this, Scaleform::GFx::LoadStates *pls, Scaleform::GFx::MovieDefImpl *pdefImpl, Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack)
{
  Scaleform::GFx::LoaderImpl::LoadStackItem *v4; // rbp
  Scaleform::GFx::MovieDefImpl *v5; // rsi
  Scaleform::GFx::LoadStates *v6; // rdi
  Scaleform::GFx::MovieBindProcess *v7; // rbx
  Scaleform::GFx::Resource *v8; // rcx
  Scaleform::GFx::MovieDataDef *v9; // rcx
  bool v10; // al
  Scaleform::GFx::ImagePackParamsBase *v11; // r14
  Scaleform::GFx::ImageFileHandlerRegistry *v12; // rbp
  Scaleform::GFx::FileOpener *v13; // r15
  Scaleform::GFx::LogState *v14; // rax
  Scaleform::Log *v15; // rax
  __int64 v16; // rdi
  Scaleform::RefCountNTSImpl *v17; // rcx
  Scaleform::GFx::TempBindData *v18; // rax
  int v19; // [rsp+30h] [rbp-98h]
  __int64 v20; // [rsp+38h] [rbp-90h]
  int v21; // [rsp+40h] [rbp-88h]
  int v22; // [rsp+44h] [rbp-84h]
  Scaleform::Log *v23; // [rsp+48h] [rbp-80h]
  __int128 v24; // [rsp+50h] [rbp-78h]
  __int64 v25; // [rsp+60h] [rbp-68h]
  Scaleform::String v26; // [rsp+78h] [rbp-50h]

  v4 = ploadStack;
  v5 = pdefImpl;
  v6 = pls;
  v7 = this;
  Scaleform::GFx::LoaderTask::LoaderTask((Scaleform::GFx::LoaderTask *)&this->vfptr, pls, Id_MovieBind);
  v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieBindProcess::`vftable;
  v7->pFrameBindData = 0i64;
  v7->GlyphTextureIdGen.Id = 589824;
  v7->pImagePacker.pObject = 0i64;
  v8 = (Scaleform::GFx::Resource *)v5->pBindData.pObject;
  if ( v8 )
    Scaleform::Render::RenderBuffer::AddRef(v8);
  v7->pBindData.pObject = v5->pBindData.pObject;
  v7->pLoadStack = v4;
  v9 = v7->pBindData.pObject->pDataDef.pObject;
  v7->pDataDef = v9;
  v10 = (((unsigned int (__cdecl *)(Scaleform::GFx::MovieDataDef *))v9->vfptr[4].GetKey)(v9) >> 4) & 1;
  v7->Stripped = v10;
  v11 = v6->pBindStates.pObject->pImagePackParams.pObject;
  if ( !v11 || v10 )
  {
    v7->pTempBindData = 0i64;
  }
  else
  {
    v19 = 2;
    v20 = 0i64;
    v21 = 1;
    v22 = 1;
    v23 = 0i64;
    _mm_store_si128((__m128i *)&v24, (__m128i)0i64);
    v25 = 0i64;
    Scaleform::String::String(&v26);
    v12 = v6->pImageFileHandlerRegistry.pObject;
    v13 = v6->pBindStates.pObject->pFileOpener.pObject;
    v14 = v6->pLog.pObject;
    if ( v14 )
    {
      v15 = v14->pLog.pObject;
      if ( !v15 )
        v15 = Scaleform::Log::GetGlobalLog();
    }
    else
    {
      v15 = 0i64;
    }
    *(_QWORD *)&v24 = v13;
    v23 = v15;
    *((_QWORD *)&v24 + 1) = v12;
    v20 = v5->vfptr[4].GetResourceTypeCode((Scaleform::GFx::Resource *)&v5->vfptr);
    v16 = ((__int64 (__fastcall *)(Scaleform::GFx::ImagePackParamsBase *, Scaleform::GFx::ResourceId *, Scaleform::GFx::ImageCreator *, int *, signed __int64))v11->vfptr[2].__vecDelDtor)(
            v11,
            &v7->GlyphTextureIdGen,
            v6->pBindStates.pObject->pImageCreator.pObject,
            &v19,
            -2i64);
    v17 = (Scaleform::RefCountNTSImpl *)&v7->pImagePacker.pObject->vfptr;
    if ( v17 )
      Scaleform::RefCountNTSImpl::Release(v17);
    v7->pImagePacker.pObject = (Scaleform::GFx::ImagePacker *)v16;
    (*(void (__fastcall **)(__int64, Scaleform::GFx::MovieDefImpl::BindTaskData *))(*(_QWORD *)v16 + 8i64))(
      v16,
      v7->pBindData.pObject);
    v18 = (Scaleform::GFx::TempBindData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                            Scaleform::Memory::pGlobalHeap,
                                            8i64);
    if ( v18 )
      v18->FillStyleImageWrap.pTable = 0i64;
    else
      v18 = 0i64;
    v7->pTempBindData = v18;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 1295
// RVA: 0x8A6100
void __fastcall Scaleform::GFx::MovieBindProcess::~MovieBindProcess(Scaleform::GFx::MovieBindProcess *this)
{
  Scaleform::GFx::MovieBindProcess *v1; // rdi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v2; // rsi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v3; // rax
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *v5; // rbx
  Scaleform::RefCountNTSImpl *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::RefCountNTSImpl *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieBindProcess::`vftable;
  v2 = this->pBindData.pObject;
  if ( v2 )
  {
    v2 = (Scaleform::GFx::MovieDefImpl::BindTaskData *)v2->pBindUpdate.pObject;
    if ( v2 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v2);
  }
  v3 = v1->pBindData.pObject;
  if ( v3 )
  {
    if ( (v3->BindState & 0xF) == 1 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v1->pBindData.pObject, 3u);
    v4 = (Scaleform::Render::RenderBuffer *)v1->pBindData.pObject;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
    v1->pBindData.pObject = 0i64;
  }
  v5 = (Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)v1->pTempBindData;
  if ( v5 )
  {
    Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>(v5);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
  }
  v6 = (Scaleform::RefCountNTSImpl *)&v1->pImagePacker.pObject->vfptr;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  v1->pImagePacker.pObject = 0i64;
  if ( v2 )
  {
    Scaleform::Mutex::DoLock((Scaleform::Mutex *)&v2->pHeap);
    LOBYTE(v2->ResourceBinding.pResources) = 1;
    Scaleform::WaitCondition::NotifyAll((Scaleform::WaitCondition *)&v2->ResourceBinding.ResourceCount);
    Scaleform::Mutex::Unlock((Scaleform::Mutex *)&v2->pHeap);
  }
  if ( v2 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v2);
  v7 = (Scaleform::Render::RenderBuffer *)v1->pBindData.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = (Scaleform::RefCountNTSImpl *)&v1->pImagePacker.pObject->vfptr;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderTask::`vftable;
  Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(
    v1->pLoadStates.pObject->pLoaderImpl.pObject,
    (Scaleform::GFx::LoaderTask *)&v1->vfptr);
  v9 = (Scaleform::Render::RenderBuffer *)v1->pLoadStates.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 1323
// RVA: 0x8EB830
bool __fastcall Scaleform::GFx::MatchFileNames(Scaleform::String *path1, Scaleform::String *path2)
{
  _DWORD *v2; // rbx
  _DWORD *v3; // rdi
  int v4; // er10
  int v5; // er11
  __int64 v7; // r9
  __int64 v8; // rcx
  char v9; // al
  char v10; // dl
  int v11; // er8
  int v12; // edx
  char v13; // cl

  v2 = (_DWORD *)(path2->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v3 = (_DWORD *)(path1->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v4 = *v2 - 1;
  v5 = *v3 - 1;
  if ( (v5 < 0 || v4 < 0) && v5 != v4 )
    return 0;
  v7 = v5;
  v8 = v4;
  if ( v5 >= 0 )
  {
    while ( v8 >= 0 )
    {
      v9 = *((_BYTE *)v3 + v7 + 12);
      if ( v9 == 92 || v9 == 47 )
      {
        v10 = *((_BYTE *)v2 + v8 + 12);
        if ( v10 == 92 || v10 == 47 )
          return 1;
      }
      v11 = v9;
      if ( (unsigned int)(v9 - 65) <= 0x19 )
        v11 = v9 + 32;
      v12 = *((char *)v2 + v8 + 12);
      if ( (unsigned int)(v12 - 65) <= 0x19 )
        v12 += 32;
      if ( v11 != v12 )
        return 0;
      --v5;
      --v4;
      --v8;
      if ( --v7 < 0 )
        break;
    }
  }
  if ( v4 == v5 )
    return 1;
  if ( v4 >= v5 )
    v13 = *((_BYTE *)v2 + v4 + 12);
  else
    v13 = *((_BYTE *)v3 + v5 + 12);
  return v13 == 92 || v13 == 47;
}

// File Line: 1346
// RVA: 0x8B7270
signed __int64 __fastcall Scaleform::GFx::MovieBindProcess::BindNextFrame(Scaleform::GFx::MovieBindProcess *this)
{
  Scaleform::GFx::MovieBindProcess *v1; // rbx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v2; // rax
  signed __int64 v3; // rax
  unsigned int v4; // edx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v5; // rcx
  Scaleform::GFx::FrameBindData *v6; // r15
  Scaleform::GFx::FrameBindData *volatile v7; // r15
  Scaleform::GFx::MovieDataDef::LoadTaskData *v8; // rdi
  Scaleform::GFx::FrameBindData *v9; // r15
  Scaleform::GFx::FrameBindData *v10; // rax
  unsigned int v11; // eax
  Scaleform::GFx::ImportData *v12; // rdi
  Scaleform::GFx::MovieDefImpl *v13; // rax
  Scaleform::GFx::MovieDefImpl *v14; // r14
  Scaleform::GFx::Resource **v15; // rdi
  Scaleform::String *v16; // r12
  const char *v17; // rax
  int v18; // edi
  Scaleform::String *v19; // rax
  char v20; // si
  Scaleform::Render::RenderBuffer *v21; // rsi
  int v22; // edi
  Scaleform::GFx::LoaderImpl::LoadStackItem *v23; // rcx
  Scaleform::GFx::LoaderImpl::LoadStackItem **v24; // rax
  const char *v25; // rax
  Scaleform::GFx::MovieDefImpl *v26; // rsi
  __int64 *v27; // rdx
  __int64 *v28; // rax
  unsigned int v29; // edi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v30; // rax
  bool v31; // di
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v32; // rcx
  Scaleform::GFx::ImportVisitor *v33; // r12
  Scaleform::GFx::MovieDefImpl *v34; // rdi
  Scaleform::GFx::ResourceLibBase *v35; // rcx
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v36; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v37; // rcx
  Scaleform::GFx::ResourceLibBase *v38; // rcx
  Scaleform::GFx::ResourceLibBase *v39; // rcx
  unsigned int *v40; // rsi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v41; // rax
  Scaleform::GFx::ResourceBinding *v42; // r14
  Scaleform::MemoryHeap *v43; // rdx
  unsigned int v44; // er12
  Scaleform::GFx::Resource *v49; // rdi
  Scaleform::GFx::ResourceLibBase *v50; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v51; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v52; // rax
  __int64 v53; // rdi
  Scaleform::Render::RenderBuffer *v54; // rcx
  Scaleform::GFx::Resource *v55; // rbx
  Scaleform::GFx::ResourceLibBase *v56; // rcx
  Scaleform::GFx::FontDataUseNode *v57; // r12
  unsigned int v58; // esi
  unsigned int v59; // er8
  signed __int64 v60; // rdx
  Scaleform::GFx::FontResource *v61; // rdi
  unsigned __int64 v62; // rsi
  unsigned __int64 v63; // r8
  Scaleform::String *v64; // rcx
  Scaleform::GFx::Resource *v65; // rdi
  Scaleform::GFx::ResourceLibBase *v66; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v67; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v68; // rdi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v69; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v70; // rdi
  Scaleform::GFx::MovieDataDef *v71; // rcx
  int v72; // er12
  Scaleform::String *v73; // rsi
  int v74; // er15
  int v75; // er14
  unsigned int v76; // esi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v77; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v78; // rax
  __int64 v79; // rdi
  Scaleform::Render::RenderBuffer *v80; // rcx
  unsigned int v81; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::ResourceBindData bd; // [rsp+38h] [rbp-C8h]
  Scaleform::Render::RenderBuffer *v83; // [rsp+48h] [rbp-B8h]
  Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::RenderBuffer *v85; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::ResourceBindData pdata; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::MovieDefImpl *v87; // [rsp+80h] [rbp-80h]
  __int64 v88; // [rsp+88h] [rbp-78h]
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+90h] [rbp-70h]
  Scaleform::String path2; // [rsp+A8h] [rbp-58h]
  Scaleform::String v91; // [rsp+B0h] [rbp-50h]
  int v92; // [rsp+B8h] [rbp-48h]
  int v93; // [rsp+BCh] [rbp-44h]
  int v94; // [rsp+C0h] [rbp-40h]
  int v95; // [rsp+C4h] [rbp-3Ch]
  Scaleform::String v96; // [rsp+C8h] [rbp-38h]
  Scaleform::GFx::URLBuilder::LocationInfo v97; // [rsp+D0h] [rbp-30h]
  Scaleform::Ptr<Scaleform::GFx::FontLib> result; // [rsp+E8h] [rbp-18h]
  Scaleform::Mutex *v99; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::MovieDefImpl *v100; // [rsp+F8h] [rbp-8h]
  __int64 v101; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::MovieDefImpl *v102; // [rsp+108h] [rbp+8h]
  __int64 v103; // [rsp+110h] [rbp+10h]
  __int64 v104; // [rsp+118h] [rbp+18h]
  __int64 v105; // [rsp+120h] [rbp+20h]
  Scaleform::Render::RenderBuffer *v106; // [rsp+128h] [rbp+28h]
  __int64 v107; // [rsp+130h] [rbp+30h]
  unsigned int v108; // [rsp+190h] [rbp+90h]
  Scaleform::MemoryHeap *v109; // [rsp+190h] [rbp+90h]
  unsigned int v111; // [rsp+190h] [rbp+90h]
  Scaleform::GFx::ProgressHandler *v112; // [rsp+190h] [rbp+90h]
  unsigned int v113; // [rsp+198h] [rbp+98h]
  Scaleform::GFx::LoadStates *pls; // [rsp+1A0h] [rbp+A0h]
  Scaleform::GFx::ImportData *pimport; // [rsp+1A8h] [rbp+A8h]

  v104 = -2i64;
  v1 = this;
  v81 = 0;
  v2 = this->pBindData.pObject;
  if ( !v2 )
    return 3i64;
  v3 = v2->BindState & 0xF;
  if ( (_DWORD)v3 != 1 )
  {
    if ( (_DWORD)v3 )
      return v3;
    v4 = this->pBindData.pObject->BindState & 0xFFFFFFF1 | 1;
    v5 = this->pBindData.pObject;
    if ( v5 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v5, v4);
  }
  v6 = v1->pFrameBindData;
  if ( v6 )
    v7 = v6->pNextFrame.Value;
  else
    v7 = v1->pDataDef->pData.pObject->BindData.pFrameData.Value;
  if ( !v7 )
  {
    v8 = v1->pDataDef->pData.pObject;
    v99 = &v8->pFrameUpdate.pObject->mMutex;
    Scaleform::Mutex::DoLock(v99);
    v9 = v1->pFrameBindData;
    if ( v9 )
      v7 = v9->pNextFrame.Value;
    else
      v7 = v1->pDataDef->pData.pObject->BindData.pFrameData.Value;
    while ( !v7 )
    {
      if ( v8->LoadState != 1 || v1->pBindData.pObject->BindingCanceled )
        break;
      Scaleform::WaitCondition::Wait(&v8->pFrameUpdate.pObject->WC, &v8->pFrameUpdate.pObject->mMutex, 0xFFFFFFFF);
      v10 = v1->pFrameBindData;
      v7 = v10 ? v10->pNextFrame.Value : v1->pDataDef->pData.pObject->BindData.pFrameData.Value;
    }
    if ( v8->LoadState == 3 )
      v1->pBindData.pObject->BindingCanceled = 1;
    Scaleform::Mutex::Unlock(v99);
    if ( !v7 )
      goto LABEL_192;
  }
  if ( v1->pBindData.pObject->BindingCanceled )
  {
LABEL_192:
    Scaleform::GFx::MovieBindProcess::FinishBinding(v1);
    v76 = 4 - (v1->pBindData.pObject->BindingCanceled != 0);
    v77 = v1->pBindData.pObject;
    if ( v77 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v77, v76 | v1->pBindData.pObject->BindState & 0xFFFFFFF0);
    v78 = v1->pBindData.pObject;
    v79 = (__int64)v78->pBindUpdate.pObject;
    if ( v79 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v78->pBindUpdate.pObject);
    v105 = v79;
    v80 = (Scaleform::Render::RenderBuffer *)v1->pBindData.pObject;
    if ( v80 )
      Scaleform::RefCountImpl::Release(v80);
    v1->pBindData.pObject = 0i64;
    v107 = v79 + 16;
    Scaleform::Mutex::DoLock((Scaleform::Mutex *)(v79 + 16));
    *(_BYTE *)(v79 + 64) = 1;
    Scaleform::WaitCondition::NotifyAll((Scaleform::WaitCondition *)(v79 + 56));
    Scaleform::Mutex::Unlock((Scaleform::Mutex *)(v79 + 16));
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v79);
    return v76;
  }
  v1->pFrameBindData = v7;
  pls = v1->pLoadStates.pObject;
  v113 = v1->pBindData.pObject->LoadFlags;
  v11 = v1->pBindData.pObject->LoadFlags;
  if ( !_bittest((const signed int *)&v11, 0x14u) )
  {
    v12 = v7->pImportData;
    pimport = v7->pImportData;
    v83 = 0i64;
    v13 = Scaleform::GFx::MovieDefImpl::BindTaskData::GetMovieDefImplAddRef(v1->pBindData.pObject);
    v14 = v13;
    v102 = v13;
    if ( v13 )
    {
      v15 = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetFontLib(
                                           (Scaleform::GFx::StateBag *)&v13->vfptr,
                                           &result);
      if ( *v15 )
        Scaleform::Render::RenderBuffer::AddRef(*v15);
      v83 = (Scaleform::Render::RenderBuffer *)*v15;
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
      v12 = pimport;
    }
    v108 = 0;
    if ( v7->ImportCount )
    {
      do
      {
        v16 = (Scaleform::String *)&v12->SourceUrl.0;
        if ( v83 )
        {
          if ( v14 )
          {
            v17 = Scaleform::GFx::StateBag::GetDefaultFontLibName((Scaleform::GFx::StateBag *)&v14->vfptr);
            Scaleform::String::String(&path2, v17);
            v18 = v81 | 1;
            v81 |= 1u;
            if ( Scaleform::GFx::MatchFileNames(v16, &path2) )
              goto LABEL_38;
          }
          else
          {
            v18 = v81;
          }
          Scaleform::String::String(&v96, "gfxfontlib.swf");
          v18 |= 2u;
          v81 = v18;
          if ( Scaleform::GFx::MatchFileNames(v16, v19) )
          {
LABEL_38:
            v20 = 1;
            goto LABEL_41;
          }
        }
        else
        {
          v18 = v81;
        }
        v20 = 0;
LABEL_41:
        if ( v18 & 2 )
        {
          v81 = v18 & 0xFFFFFFFD;
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v96.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v18 &= 0xFFFFFFFD;
        }
        if ( v18 & 1 )
        {
          v81 = v18 & 0xFFFFFFFE;
          if ( !_InterlockedDecrement((volatile signed __int32 *)((path2.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        }
        if ( v20 )
        {
          Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImportThroughFontLib(v1->pBindData.pObject, pimport);
          goto LABEL_90;
        }
        v21 = (Scaleform::Render::RenderBuffer *)Scaleform::GFx::LoadStates::CloneForImport(pls);
        v85 = v21;
        v106 = v21;
        v22 = v113 | 1;
        v87 = v1->pBindData.pObject->pDefImpl_Unsafe;
        v88 = 0i64;
        v23 = v1->pLoadStack;
        if ( v23 )
        {
          v24 = &v23->pNext;
          if ( v23->pNext )
          {
            do
            {
              v23 = *v24;
              v24 = &(*v24)->pNext;
            }
            while ( *v24 );
          }
          v23->pNext = (Scaleform::GFx::LoaderImpl::LoadStackItem *)&v87;
        }
        else
        {
          v1->pLoadStack = (Scaleform::GFx::LoaderImpl::LoadStackItem *)&v87;
        }
        if ( v1->Stripped )
        {
          v25 = (const char *)(v16->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
          if ( (*(_QWORD *)v25 & 0x7FFFFFFFFFFFFFFFui64) > 4
            && !Scaleform::String::CompareNoCase(&v25[(*(_QWORD *)v25 & 0x7FFFFFFFFFFFFFFFi64) + 8], ".swf") )
          {
            loc.Use = 1;
            Scaleform::String::String(&loc.FileName, v16);
            Scaleform::String::String(&loc.ParentPath, &pls->RelativePath);
            Scaleform::String::Clear(&loc.FileName);
            Scaleform::String::AppendString(
              &loc.FileName,
              (const char *)((v16->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
              (*(_QWORD *)(v16->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) - 4);
            Scaleform::String::AppendString(&loc.FileName, ".gfx", -1i64);
            v26 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
                    (Scaleform::GFx::LoadStates *)v21,
                    &loc,
                    v22,
                    v1->pLoadStack);
            if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                                  + 8)) )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                                  + 8)) )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            if ( v26 )
              goto LABEL_68;
            v21 = v85;
          }
        }
        v97.Use = 1;
        Scaleform::String::String(&v97.FileName, v16);
        Scaleform::String::String(&v97.ParentPath, &pls->RelativePath);
        v26 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
                (Scaleform::GFx::LoadStates *)v21,
                &v97,
                v22,
                v1->pLoadStack);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v97.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                              + 8)) )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v97.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_68:
        v27 = (__int64 *)v1->pLoadStack;
        if ( v27 == (__int64 *)&v87 )
        {
          v1->pLoadStack = 0i64;
        }
        else if ( v27[1] )
        {
          while ( 1 )
          {
            v28 = (__int64 *)v27[1];
            if ( v28 == (__int64 *)&v87 )
              break;
            v27 = (__int64 *)v27[1];
            if ( !v28[1] )
              goto LABEL_75;
          }
          v27[1] = v28[1];
        }
LABEL_75:
        if ( !v26 )
          goto LABEL_94;
        v29 = v1->pDataDef->pData.pObject->FileAttributes;
        if ( ((unsigned __int8)v29 ^ (unsigned __int8)v26->vfptr[3].GetResourceReport((Scaleform::GFx::Resource *)&v26->vfptr)) & 8 )
        {
          Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v26->vfptr);
          v36 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)pls->pLog.pObject;
          if ( v36 )
            Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
              v36 + 3,
              "ActionScript version mismatched between main and import %s files",
              (v16->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
LABEL_94:
          Scaleform::GFx::MovieBindProcess::FinishBinding(v1);
          v37 = v1->pBindData.pObject;
          if ( v37 )
            Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(
              v37,
              v1->pBindData.pObject->BindState & 0xFFFFFFF4 | 4);
          if ( v85 )
            Scaleform::RefCountImpl::Release(v85);
          if ( v14 && _InterlockedExchangeAdd(&v14->RefCount.Value, 0xFFFFFFFF) == 1 )
          {
            v38 = v14->pLib;
            if ( v38 )
            {
              v38->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v38->vfptr, (unsigned int)v14);
              v14->pLib = 0i64;
            }
            v14->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v14->vfptr, 1u);
          }
          if ( v83 )
            Scaleform::RefCountImpl::Release(v83);
          return 4i64;
        }
        v30 = v1->pBindData.pObject;
        v31 = v26->pBindData.pObject == v30;
        if ( v26->pBindData.pObject == v30 )
        {
          v32 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)pls->pLog.pObject;
          if ( v32 )
            Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
              v32 + 3,
              "Self recursive import detected in %s",
              (v16->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        }
        Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImport(v1->pBindData.pObject, pimport, v26, pls, v31);
        v33 = pls->pBindStates.pObject->pImportVisitor.pObject;
        if ( v33 )
        {
          v34 = Scaleform::GFx::MovieDefImpl::BindTaskData::GetMovieDefImplAddRef(v1->pBindData.pObject);
          v100 = v34;
          if ( v34 )
            v33->vfptr->Visit(
              (Scaleform::GFx::MovieDef::ImportVisitor *)&v33->vfptr,
              (Scaleform::GFx::MovieDef *)&v34->vfptr,
              (Scaleform::GFx::MovieDef *)&v26->vfptr,
              (const char *)((pimport->SourceUrl.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
          if ( v34 && !_InterlockedDecrement(&v34->RefCount.Value) )
          {
            v35 = v34->pLib;
            if ( v35 )
            {
              v35->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v35->vfptr, (unsigned int)v34);
              v34->pLib = 0i64;
            }
            v34->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v34->vfptr, 1u);
          }
        }
        Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v26->vfptr);
        if ( v85 )
          Scaleform::RefCountImpl::Release(v85);
LABEL_90:
        ++v108;
        v12 = pimport->pNext.Value;
        pimport = pimport->pNext.Value;
      }
      while ( v108 < v7->ImportCount );
    }
    if ( v14 && !_InterlockedDecrement(&v14->RefCount.Value) )
    {
      v39 = v14->pLib;
      if ( v39 )
      {
        v39->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v39->vfptr, (unsigned int)v14);
        v14->pLib = 0i64;
      }
      v14->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v14->vfptr, 1u);
    }
    if ( v83 )
      Scaleform::RefCountImpl::Release(v83);
  }
  v40 = (unsigned int *)v7->pResourceData;
  v41 = v1->pBindData.pObject;
  v42 = &v41->ResourceBinding;
  v43 = v41->pHeap;
  v109 = v41->pHeap;
  v44 = 0;
  if ( !v7->ResourceCount )
  {
LABEL_148:
    if ( v7->FontCount )
    {
      pheapAddr.Data = 0i64;
      pheapAddr.Size = 0i64;
      pheapAddr.Policy.Capacity = 0i64;
      v57 = v7->pFontData;
      v58 = 0;
      v111 = 0;
      if ( v7->FontCount )
      {
        do
        {
          pdata.pResource.pObject = 0i64;
          pdata.pBinding = 0i64;
          v59 = v57->BindIndex;
          if ( v42->Frozen && v59 < v42->ResourceCount )
          {
            v60 = (signed __int64)&v42->pResources[v59];
            if ( *(_QWORD *)v60 )
              _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v60 + 8i64), 1u);
            v61 = *(Scaleform::GFx::FontResource **)v60;
            pdata.pResource.pObject = *(Scaleform::GFx::Resource **)v60;
            pdata.pBinding = *(Scaleform::GFx::ResourceBinding **)(v60 + 8);
          }
          else
          {
            Scaleform::GFx::ResourceBinding::GetResourceData_Locked(v42, &pdata, v59);
            v61 = (Scaleform::GFx::FontResource *)pdata.pResource.pObject;
          }
          if ( !v61 )
            goto LABEL_165;
          Scaleform::GFx::FontResource::ResolveTextureGlyphs(v61);
          v62 = pheapAddr.Size + 1;
          if ( pheapAddr.Size + 1 >= pheapAddr.Size )
          {
            if ( v62 <= pheapAddr.Policy.Capacity )
              goto LABEL_163;
            v63 = v62 + (v62 >> 2);
          }
          else
          {
            if ( v62 >= pheapAddr.Policy.Capacity >> 1 )
              goto LABEL_163;
            v63 = pheapAddr.Size + 1;
          }
          Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v63);
LABEL_163:
          pheapAddr.Size = v62;
          v64 = &pheapAddr.Data[v62 - 1];
          v58 = v111;
          if ( v64 )
            v64->HeapTypeBits = (unsigned __int64)v61;
LABEL_165:
          if ( v61 && !_InterlockedDecrement(&v61->RefCount.Value) )
          {
            v65 = pdata.pResource.pObject;
            v66 = pdata.pResource.pObject->pLib;
            if ( v66 )
            {
              v66->vfptr[1].__vecDelDtor(
                (Scaleform::RefCountImplCore *)&v66->vfptr,
                (unsigned int)pdata.pResource.pObject);
              v65->pLib = 0i64;
            }
            v65->vfptr->__vecDelDtor(v65, 1u);
          }
          v111 = ++v58;
          v57 = v57->pNext.Value;
        }
        while ( v58 < v7->FontCount );
      }
      if ( pheapAddr.Data )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v1->pBindData.pObject->BytesLoaded = v7->BytesLoaded;
    if ( ++v1->pBindData.pObject->BindingFrame == 1 )
    {
      v67 = v1->pBindData.pObject;
      if ( v67 )
        Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v67, v1->pBindData.pObject->BindState | 0x100);
    }
    v68 = v1->pBindData.pObject;
    if ( v68->BindingFrame == ((unsigned int (*)(void))v1->pDataDef->vfptr[2].GetResourceTypeCode)() )
    {
      v1->pBindData.pObject->BytesLoaded = v1->pDataDef->pData.pObject->Header.FileLength;
      Scaleform::GFx::MovieBindProcess::FinishBinding(v1);
      v69 = v1->pBindData.pObject;
      if ( v69 )
        Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(
          v69,
          v1->pBindData.pObject->BindState & 0xFFFFFFF2 | 0x202);
    }
    v112 = pls->pProgressHandler.pObject;
    if ( v112 )
    {
      v70 = v1->pBindData.pObject;
      v71 = v70->pDataDef.pObject;
      v72 = v71->pData.pObject->Header.FileLength;
      v73 = (Scaleform::String *)v71->pData.pObject;
      v74 = ((__int64 (*)(void))v71->vfptr[2].GetResourceTypeCode)();
      v75 = v70->BindingFrame;
      LODWORD(v70) = v70->BytesLoaded;
      Scaleform::String::String(&v91, v73 + 9);
      v92 = (signed int)v70;
      v93 = v72;
      v94 = v75;
      v95 = v74;
      v112->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v112->vfptr, (unsigned int)&v91);
      if ( _InterlockedExchangeAdd(
             (volatile signed __int32 *)((v91.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
             0xFFFFFFFF) == 1 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    return v1->pBindData.pObject->BindState & 0xF;
  }
  while ( !*(_QWORD *)v40 )
  {
LABEL_134:
    ++v44;
    v40 = (unsigned int *)*((_QWORD *)v40 + 3);
    if ( v44 >= v7->ResourceCount )
      goto LABEL_148;
  }
  bd.pResource.pObject = 0i64;
  bd.pBinding = v42;
  bd.pResource.pObject = 0i64;
  if ( !v1->pBindData.pObject->BindingCanceled
    && *(_QWORD *)v40
    && (*(unsigned __int8 (__fastcall **)(_QWORD, _QWORD, Scaleform::GFx::ResourceBindData *, Scaleform::GFx::LoadStates *, Scaleform::MemoryHeap *))(**(_QWORD **)v40 + 24i64))(
         *(_QWORD *)v40,
         *((_QWORD *)v40 + 1),
         &bd,
         pls,
         v43) )
  {
    if ( v1->pImagePacker.pObject
      && (((__int64 (*)(void))bd.pResource.pObject->vfptr->GetResourceTypeCode)() & 0xFF00) == 256
      && ((unsigned __int8 (*)(void))bd.pResource.pObject->vfptr->GetResourceTypeCode)() == 1 )
    {
      ((void (__fastcall *)(Scaleform::GFx::ImagePacker *, unsigned int *, Scaleform::GFx::Resource *))v1->pImagePacker.pObject->vfptr[3].__vecDelDtor)(
        v1->pImagePacker.pObject,
        v40,
        bd.pResource.pObject);
    }
    goto LABEL_128;
  }
  if ( !v1->pBindData.pObject->BindingCanceled )
  {
LABEL_128:
    Scaleform::GFx::ResourceBinding::SetBindData(v42, v40[4], &bd);
    v49 = bd.pResource.pObject;
    if ( bd.pResource.pObject && !_InterlockedDecrement(&bd.pResource.pObject->RefCount.Value) )
    {
      v50 = v49->pLib;
      if ( v50 )
      {
        v50->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v50->vfptr, (unsigned int)v49);
        v49->pLib = 0i64;
      }
      v49->vfptr->__vecDelDtor(v49, 1u);
    }
    v43 = v109;
    goto LABEL_134;
  }
  Scaleform::GFx::MovieBindProcess::FinishBinding(v1);
  v51 = v1->pBindData.pObject;
  if ( v51 )
    Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v51, v1->pBindData.pObject->BindState & 0xFFFFFFF3 | 3);
  v52 = v1->pBindData.pObject;
  v53 = (__int64)v52->pBindUpdate.pObject;
  if ( v53 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v52->pBindUpdate.pObject);
  v101 = v53;
  v54 = (Scaleform::Render::RenderBuffer *)v1->pBindData.pObject;
  if ( v54 )
    Scaleform::RefCountImpl::Release(v54);
  v1->pBindData.pObject = 0i64;
  v103 = v53 + 16;
  Scaleform::Mutex::DoLock((Scaleform::Mutex *)(v53 + 16));
  *(_BYTE *)(v53 + 64) = 1;
  Scaleform::WaitCondition::NotifyAll((Scaleform::WaitCondition *)(v53 + 56));
  Scaleform::Mutex::Unlock((Scaleform::Mutex *)(v53 + 16));
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v53);
  v55 = bd.pResource.pObject;
  if ( bd.pResource.pObject && _InterlockedExchangeAdd(&bd.pResource.pObject->RefCount.Value, 0xFFFFFFFF) == 1 )
  {
    v56 = v55->pLib;
    if ( v56 )
    {
      v56->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v56->vfptr, (unsigned int)v55);
      v55->pLib = 0i64;
    }
    v55->vfptr->__vecDelDtor(v55, 1u);
  }
  return 3i64;
}

// File Line: 1774
// RVA: 0x8CD500
void __fastcall Scaleform::GFx::MovieBindProcess::FinishBinding(Scaleform::GFx::MovieBindProcess *this)
{
  Scaleform::GFx::MovieBindProcess *v1; // rdi
  Scaleform::GFx::ImagePacker *v2; // rcx
  __int64 v3; // rax
  Scaleform::GFx::MovieDefImpl *v4; // rbx
  __int64 v5; // r8
  __int64 v6; // r9
  Scaleform::GFx::ResourceLibBase *v7; // rcx
  void **v8; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::ImagePacker *v9; // [rsp+30h] [rbp-18h]
  __int64 v10; // [rsp+38h] [rbp-10h]

  v1 = this;
  v2 = this->pImagePacker.pObject;
  if ( v2 )
  {
    v3 = (__int64)v1->pTempBindData;
    v8 = (void **)&`Scaleform::GFx::MovieBindProcess::FinishBinding::`5::ImagePackVisitor::`vftable;
    v9 = v2;
    v10 = v3;
    v4 = Scaleform::GFx::MovieDefImpl::BindTaskData::GetMovieDefImplAddRef(v1->pBindData.pObject);
    ((void (__fastcall *)(Scaleform::GFx::MovieDefImpl *, void ***, signed __int64))v4->vfptr[6].GetResourceTypeCode)(
      v4,
      &v8,
      2i64);
    ((void (__cdecl *)(Scaleform::GFx::ImagePacker *, Scaleform::RefCountNTSImplCoreVtbl *, __int64, __int64))v1->pImagePacker.pObject->vfptr[5].__vecDelDtor)(
      v1->pImagePacker.pObject,
      v1->pImagePacker.pObject->vfptr,
      v5,
      v6);
    if ( !_InterlockedDecrement(&v4->RefCount.Value) )
    {
      v7 = v4->pLib;
      if ( v7 )
      {
        v7->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)v4);
        v4->pLib = 0i64;
      }
      v4->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v4->vfptr, 1u);
    }
    v8 = &Scaleform::GFx::MovieDef::ResourceVisitor::`vftable;
  }
  v1->pBindData.pObject->ResourceBinding.Frozen = 1;
}

// File Line: 1786
// RVA: 0x9196A0
void __fastcall Scaleform::GFx::MovieBindProcess::FinishBinding_::_5_::ImagePackVisitor::Visit(Scaleform::GFx::MovieDef *pmovieDef, Scaleform::GFx::Resource *presource, __int64 rid, const char *pexportName, char *str1)
{
  Scaleform::GFx::MovieDef *v5; // rsi
  __int64 v6; // rbp
  __int64 v7; // rax
  Scaleform::GFx::ResourceLibBase *v8; // rbx
  __int64 v9; // rax
  signed __int64 v10; // rdx
  bool v11; // di
  bool v12; // al

  v5 = pmovieDef;
  v6 = rid;
  v7 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, const char *))(**(_QWORD **)&pmovieDef->RefCount.Value
                                                                         + 32i64))(
         *(_QWORD *)&pmovieDef->RefCount.Value,
         rid,
         rid,
         pexportName);
  v8 = v5->pLib;
  v9 = Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::findIndex<unsigned int>(
         (Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > > *)v5->pLib,
         (const unsigned int *)(v7 + 16));
  if ( v9 < 0 )
    v10 = 0i64;
  else
    v10 = (signed __int64)&v8->vfptr[3 * v9 + 4];
  v11 = v10 == 0;
  v12 = str1 && (strstr(str1, "-forcepack") || strstr(str1, ".forcepack"));
  if ( v11 || v12 )
    (*(void (__fastcall **)(_QWORD, __int64, char *))(**(_QWORD **)&v5->RefCount.Value + 16i64))(
      *(_QWORD *)&v5->RefCount.Value,
      v6,
      str1);
}

// File Line: 1808
// RVA: 0x8C0E20
Scaleform::GFx::MemoryContext *__fastcall Scaleform::GFx::MovieDefImpl::CreateMemoryContext(Scaleform::GFx::MovieDefImpl *this, const char *heapName, Scaleform::GFx::MemoryParams *memParams, bool debugHeap)
{
  bool v4; // di
  Scaleform::GFx::MemoryParams *v5; // rsi
  const char *v6; // rbp
  Scaleform::GFx::ASSupport *v7; // rbx
  Scaleform::GFx::MemoryContext *v8; // rax
  Scaleform::Ptr<Scaleform::GFx::ASSupport> result; // [rsp+20h] [rbp-18h]
  __int64 v10; // [rsp+28h] [rbp-10h]

  v10 = -2i64;
  v4 = debugHeap;
  v5 = memParams;
  v6 = heapName;
  v7 = Scaleform::GFx::MovieDefImpl::GetASSupport(this, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( v7 )
    v8 = (Scaleform::GFx::MemoryContext *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, const char *, Scaleform::GFx::MemoryParams *, bool))v7->vfptr[3].__vecDelDtor)(
                                            v7,
                                            v6,
                                            v5,
                                            v4);
  else
    v8 = 0i64;
  return v8;
}

// File Line: 1821
// RVA: 0x8C0450
Scaleform::GFx::Movie *__fastcall Scaleform::GFx::MovieDefImpl::CreateInstance(Scaleform::GFx::MovieDefImpl *this, Scaleform::GFx::MemoryParams *memParams, bool initFirstFrame, Scaleform::GFx::ActionControl *actionControl, Scaleform::Render::ThreadCommandQueue *queue)
{
  Scaleform::GFx::ActionControl *v5; // rbp
  bool v6; // r14
  Scaleform::GFx::MemoryParams *v7; // rbx
  Scaleform::GFx::MovieDefImpl *v8; // rdi
  const char *v9; // rax
  const char *v10; // rax
  __int64 v11; // rax
  Scaleform::Render::RenderBuffer *v12; // rsi
  __int64 v13; // rbx
  Scaleform::String v15; // [rsp+60h] [rbp+8h]

  v5 = actionControl;
  v6 = initFirstFrame;
  v7 = memParams;
  v8 = this;
  v9 = (const char *)((__int64 (*)(void))this->vfptr[3].__vecDelDtor)();
  v10 = Scaleform::GetShortFilename(v9);
  Scaleform::String::String(&v15, "MovieView \"", v10, "\"");
  v11 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, unsigned __int64, Scaleform::GFx::MemoryParams *, _QWORD))v8->vfptr[5].GetResourceTypeCode)(
          v8,
          (v15.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
          v7,
          (v8->pBindData.pObject->LoadFlags >> 28) & 1);
  v12 = (Scaleform::Render::RenderBuffer *)v11;
  if ( v11 )
  {
    v13 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, __int64, bool, Scaleform::GFx::ActionControl *, Scaleform::Render::ThreadCommandQueue *))v8->vfptr[5].GetResourceReport)(
            v8,
            v11,
            v6,
            v5,
            queue);
    Scaleform::RefCountImpl::Release(v12);
  }
  else
  {
    v13 = 0i64;
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v15.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return (Scaleform::GFx::Movie *)v13;
}

// File Line: 1838
// RVA: 0x8C0540
Scaleform::GFx::Movie *__fastcall Scaleform::GFx::MovieDefImpl::CreateInstance(Scaleform::GFx::MovieDefImpl *this, Scaleform::GFx::MemoryContext *memContext, bool initFirstFrame, Scaleform::GFx::ActionControl *actionControl, Scaleform::Render::ThreadCommandQueue *queue)
{
  Scaleform::GFx::ActionControl *v5; // rsi
  bool v6; // bp
  Scaleform::GFx::MemoryContext *v7; // rdi
  Scaleform::GFx::MovieDefImpl *v8; // r14
  Scaleform::GFx::ASSupport *v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rdx
  __int64 v13; // r9
  Scaleform::GFx::Resource *v14; // rax
  Scaleform::Render::RenderBuffer *v15; // rbx
  __int64 *v17; // rsi
  __int64 v18; // rbx
  __int64 v19; // rax
  Scaleform::Ptr<Scaleform::GFx::ASSupport> result; // [rsp+20h] [rbp-28h]
  __int64 v21; // [rsp+28h] [rbp-20h]
  Scaleform::Render::RenderBuffer *v22; // [rsp+30h] [rbp-18h]

  v21 = -2i64;
  v5 = actionControl;
  v6 = initFirstFrame;
  v7 = memContext;
  v8 = this;
  v9 = Scaleform::GFx::MovieDefImpl::GetASSupport(this, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( !v9 )
    return 0i64;
  v10 = (__int64)v9->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, (unsigned int)v7);
  v11 = v10;
  if ( !v10 )
    return 0i64;
  if ( v5 )
    (*(void (__fastcall **)(__int64, signed __int64, Scaleform::GFx::ActionControl *))(*(_QWORD *)(v10 + 16) + 16i64))(
      v10 + 16,
      3i64,
      v5);
  if ( !(*(unsigned __int8 (__fastcall **)(_QWORD, Scaleform::GFx::MovieDefImpl *))(**(_QWORD **)(v11 + 24) + 136i64))(
          *(_QWORD *)(v11 + 24),
          v8) )
  {
    if ( !_InterlockedDecrement((volatile signed __int32 *)(v11 + 8)) )
    {
      v14 = (Scaleform::GFx::Resource *)(*(__int64 (**)(void))(**(_QWORD **)(v11 + 24) + 464i64))();
      v15 = (Scaleform::Render::RenderBuffer *)v14;
      if ( v14 )
        Scaleform::Render::RenderBuffer::AddRef(v14);
      v22 = v15;
      (**(void (__fastcall ***)(__int64, signed __int64))v11)(v11, 1i64);
      if ( v15 )
        Scaleform::RefCountImpl::Release(v15);
    }
    return 0i64;
  }
  v17 = *(__int64 **)(v11 + 0x30);
  if ( v17 )
  {
    v18 = *v17;
    v19 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 8i64))(v11);
    (*(void (__fastcall **)(__int64 *, __int64))(v18 + 48))(v17, v19);
  }
  *(_QWORD *)(v11 + 21584) = queue;
  if ( v6 )
  {
    LOBYTE(v13) = 1;
    (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64))(*(_QWORD *)v11 + 192i64))(v11, v12, 0i64, v13);
  }
  return (Scaleform::GFx::Movie *)v11;
}

// File Line: 1889
// RVA: 0x8949D0
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::BindTaskData(Scaleform::GFx::MovieDefImpl::BindTaskData *this, Scaleform::MemoryHeap *pheap, Scaleform::GFx::MovieDataDef *pdataDef, Scaleform::GFx::MovieDefImpl *pdefImpl, unsigned int loadFlags, bool fullyLoaded)
{
  Scaleform::GFx::MovieDefImpl *v6; // r12
  Scaleform::GFx::MovieDataDef *v7; // r15
  Scaleform::GFx::MovieDefImpl::BindTaskData *v8; // rsi
  Scaleform::GFx::LoadUpdateSync *v9; // r14
  char v10; // bp
  Scaleform::GFx::ResourceBinding *v11; // rdi
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264,Scaleform::ArrayDefaultPolicy> *v12; // rax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264,Scaleform::ArrayDefaultPolicy> *v13; // rax
  __int64 v14; // r8
  bool v15; // bl
  unsigned __int64 v16; // rdx
  Scaleform::GFx::LoadUpdateSync *v17; // rax
  Scaleform::GFx::LoadUpdateSync *v18; // rax
  Scaleform::Render::RenderBuffer *v19; // rcx
  Scaleform::String url; // [rsp+88h] [rbp+10h]
  _QWORD *v21; // [rsp+90h] [rbp+18h]
  void *v22; // [rsp+98h] [rbp+20h]

  v6 = pdefImpl;
  v7 = pdataDef;
  v8 = this;
  v9 = 0i64;
  v10 = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::MovieDefImpl::BindTaskData,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieDefImpl::BindTaskData::`vftable;
  this->pHeap = pheap;
  if ( pdataDef )
  {
    _InterlockedExchangeAdd(&pdataDef->RefCount.Value, 1u);
    v10 = 0;
  }
  this->pDataDef.pObject = pdataDef;
  this->pDefImpl_Unsafe = pdefImpl;
  v11 = &this->ResourceBinding;
  v21 = &v11->pHeap;
  v11->pHeap = pheap;
  Scaleform::Lock::Lock(&this->ResourceBinding.ResourceLock, 0);
  v11->pResources = 0i64;
  v11->ResourceCount = 0;
  v11->Frozen = 0;
  v11->pOwnerDefRes = 0i64;
  v12 = &v8->ImportSourceMovies;
  v21 = &v12->Data.Data;
  v22 = &v8->ImportSourceMovies;
  v12->Data.Data = 0i64;
  v12->Data.Size = 0i64;
  v12->Data.Policy.Capacity = 0i64;
  Scaleform::Lock::Lock(&v8->ImportSourceLock, 0);
  v13 = &v8->ResourceImports;
  v13->Data.Data = 0i64;
  v13->Data.Size = 0i64;
  v13->Data.Policy.Capacity = 0i64;
  v21 = &v8->BoundShapeMeshProviders.mHash.pTable;
  v22 = &v8->BoundShapeMeshProviders;
  v8->BoundShapeMeshProviders.mHash.pTable = 0i64;
  v8->pBindUpdate.pObject = 0i64;
  EnterCriticalSection(&v11->ResourceLock.cs);
  v11->pOwnerDefRes = (Scaleform::GFx::Resource *)&v6->vfptr;
  LeaveCriticalSection(&v11->ResourceLock.cs);
  v8->LoadFlags = loadFlags;
  v8->BindingCanceled = 0;
  v8->BindingFrame = 0;
  v8->BytesLoaded = 0;
  v8->BindState = 0;
  v15 = 1;
  if ( v7->MovieType == 2 )
  {
    Scaleform::String::String(
      &url,
      (const char *)((v7->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    v10 = 1;
    if ( Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, 0i64, 0i64) )
      v15 = 0;
  }
  if ( v10 & 1 )
  {
    v16 = url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v16,
        v14);
  }
  if ( v15 )
  {
    v17 = (Scaleform::GFx::LoadUpdateSync *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              72i64);
    v21 = &v17->vfptr;
    if ( v17 )
    {
      Scaleform::GFx::LoadUpdateSync::LoadUpdateSync(v17);
      v9 = v18;
    }
    v19 = (Scaleform::Render::RenderBuffer *)v8->pBindUpdate.pObject;
    if ( v19 )
      Scaleform::RefCountImpl::Release(v19);
    v8->pBindUpdate.pObject = v9;
  }
  if ( fullyLoaded )
  {
    v8->BindingFrame = ((__int64 (*)(void))v8->pDataDef.pObject->vfptr[4].__vecDelDtor)();
    v8->BytesLoaded = v8->pDataDef.pObject->pData.pObject->Header.FileLength;
  }
}

// File Line: 1919
// RVA: 0x8A3340
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::~BindTaskData(Scaleform::GFx::MovieDefImpl::BindTaskData *this)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *v1; // rdi
  Scaleform::GFx::LoadUpdateSync *v2; // rcx
  Scaleform::GFx::LoadUpdateSync *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::GFx::MovieDataDef *v5; // rbx
  Scaleform::GFx::ResourceLibBase *v6; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieDefImpl::BindTaskData::`vftable;
  v2 = this->pBindUpdate.pObject;
  if ( v2 )
    Scaleform::Mutex::DoLock(&v2->mMutex);
  Scaleform::GFx::ResourceBinding::Destroy(&v1->ResourceBinding);
  v3 = v1->pBindUpdate.pObject;
  if ( v3 )
    Scaleform::Mutex::Unlock(&v3->mMutex);
  v4 = (Scaleform::Render::RenderBuffer *)v1->pBindUpdate.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ShapeMeshProvider *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ShapeMeshProvider *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::Sh)&v1->BoundShapeMeshProviders.mHash.pTable);
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>>::DestructArray(
    v1->ResourceImports.Data.Data,
    v1->ResourceImports.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->ResourceImports.Data.Data);
  Scaleform::Lock::~Lock(&v1->ImportSourceLock.cs);
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>>::DestructArray(
    v1->ImportSourceMovies.Data.Data,
    v1->ImportSourceMovies.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->ImportSourceMovies.Data.Data);
  Scaleform::GFx::ResourceBinding::Destroy(&v1->ResourceBinding);
  Scaleform::Lock::~Lock(&v1->ResourceBinding.ResourceLock.cs);
  v5 = v1->pDataDef.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount.Value) )
  {
    v6 = v5->pLib;
    if ( v6 )
    {
      v6->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)v5);
      v5->pLib = 0i64;
    }
    v5->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v5->vfptr, 1u);
  }
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 1941
// RVA: 0x8EE9F0
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::OnMovieDefRelease(Scaleform::GFx::MovieDefImpl::BindTaskData *this)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v3; // rdi
  Scaleform::GFx::LoadUpdateSync *v4; // rbx

  v1 = this;
  v2 = &this->ResourceBinding.ResourceLock.cs;
  EnterCriticalSection(&this->ResourceBinding.ResourceLock.cs);
  v1->ResourceBinding.pOwnerDefRes = 0i64;
  LeaveCriticalSection(v2);
  EnterCriticalSection(&v1->ImportSourceLock.cs);
  v1->pDefImpl_Unsafe = 0i64;
  LeaveCriticalSection(&v1->ImportSourceLock.cs);
  if ( (signed int)(v1->BindState & 0xF) <= 1 )
    v1->BindingCanceled = 1;
  v3 = v1->pDataDef.pObject->pData.pObject;
  v4 = v3->pFrameUpdate.pObject;
  if ( v4 )
  {
    Scaleform::Mutex::DoLock(&v4->mMutex);
    Scaleform::WaitCondition::NotifyAll(&v3->pFrameUpdate.pObject->WC);
    Scaleform::Mutex::Unlock(&v4->mMutex);
  }
}

// File Line: 1959
// RVA: 0x8DB4E0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::GetMovieDefImplAddRef(Scaleform::GFx::MovieDefImpl::BindTaskData *this)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *v1; // rbx
  Scaleform::GFx::MovieDefImpl *v2; // rdx
  signed __int32 v3; // eax
  Scaleform::GFx::MovieDefImpl *v4; // rbx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+40h] [rbp+8h]

  v1 = this;
  lpCriticalSection = &this->ImportSourceLock.cs;
  EnterCriticalSection(&this->ImportSourceLock.cs);
  v2 = v1->pDefImpl_Unsafe;
  if ( v2 && (v3 = v2->RefCount.Value) != 0 )
  {
    while ( v3 != _InterlockedCompareExchange(&v2->RefCount.Value, v3 + 1, v3) )
    {
      v3 = v2->RefCount.Value;
      if ( !v3 )
        goto LABEL_7;
    }
    v4 = v1->pDefImpl_Unsafe;
  }
  else
  {
LABEL_7:
    v4 = 0i64;
  }
  LeaveCriticalSection(lpCriticalSection);
  return v4;
}

// File Line: 1970
// RVA: 0x906690
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(Scaleform::GFx::MovieDefImpl::BindTaskData *this, unsigned int newState)
{
  unsigned int v2; // esi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v3; // rdi
  Scaleform::GFx::LoadUpdateSync *v4; // rbx

  v2 = newState;
  v3 = this;
  v4 = this->pBindUpdate.pObject;
  if ( v4 )
  {
    Scaleform::Mutex::DoLock(&v4->mMutex);
    v3->BindState = v2;
    Scaleform::WaitCondition::NotifyAll(&v3->pBindUpdate.pObject->WC);
    Scaleform::Mutex::Unlock(&v4->mMutex);
  }
  else
  {
    this->BindState = newState;
  }
}

// File Line: 1988
// RVA: 0x91A020
bool __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::WaitForBindStateFlags(Scaleform::GFx::MovieDefImpl::BindTaskData *this, unsigned int flags)
{
  unsigned int v2; // edi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v3; // rbx
  Scaleform::GFx::LoadUpdateSync *v4; // rcx
  Scaleform::Mutex *v6; // [rsp+40h] [rbp+8h]

  v2 = flags;
  v3 = this;
  v4 = this->pBindUpdate.pObject;
  if ( v4 )
  {
    v6 = &v4->mMutex;
    Scaleform::Mutex::DoLock(&v4->mMutex);
    while ( (v3->BindState & 0xF) < 3 )
    {
      if ( v3->BindState & v2 )
        break;
      Scaleform::WaitCondition::Wait(&v3->pBindUpdate.pObject->WC, &v3->pBindUpdate.pObject->mMutex, 0xFFFFFFFF);
    }
    Scaleform::Mutex::Unlock(v6);
  }
  return (v3->BindState & v2) != 0;
}

// File Line: 2037
// RVA: 0x903A10
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImport(Scaleform::GFx::MovieDefImpl::BindTaskData *this, Scaleform::GFx::ImportData *pimport, Scaleform::GFx::MovieDefImpl *pdefImpl, Scaleform::GFx::LoadStates *pls, bool recursive)
{
  Scaleform::GFx::LoadStates *v5; // r15
  Scaleform::GFx::MovieDefImpl *v6; // r12
  Scaleform::GFx::ImportData *v7; // r14
  Scaleform::GFx::MovieDefImpl::BindTaskData *v8; // r13
  unsigned int v9; // esi
  __int64 v10; // rdi
  signed __int64 v11; // rdi
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v12; // rcx
  Scaleform::GFx::MovieDataDef *v13; // rcx
  Scaleform::GFx::Resource *v14; // rdi
  Scaleform::GFx::ResourceLibBase *v15; // rcx
  Scaleform::GFx::Resource *v16; // rdi
  Scaleform::GFx::ResourceLibBase *v17; // rcx
  Scaleform::GFx::MovieDefImpl **v18; // rdx
  Scaleform::GFx::ResourceLibBase *v19; // rcx
  bool v20; // di
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v21; // rdx
  Scaleform::GFx::ResourceLibBase *v22; // rcx
  Scaleform::GFx::FontDataUseNode *volatile v23; // r13
  Scaleform::GFx::MovieDataDef::LoadTaskData *v24; // rax
  Scaleform::GFx::FontDataUseNode *volatile v25; // rsi
  Scaleform::Render::Font *v26; // r15
  Scaleform::GFx::FontDataUseNode *volatile v27; // rdi
  Scaleform::Render::Font *v28; // r14
  int v29; // esi
  const char *v30; // r14
  const char *v31; // rax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v32; // r9
  unsigned int v33; // er8
  signed __int64 v34; // rdx
  Scaleform::GFx::Resource *v35; // rcx
  Scaleform::GFx::Resource *v36; // rdi
  Scaleform::GFx::ResourceLibBase *v37; // rcx
  Scaleform::GFx::FontDataUseNode *volatile i; // [rsp+20h] [rbp-51h]
  Scaleform::GFx::ResourceHandle phandle; // [rsp+28h] [rbp-49h]
  Scaleform::GFx::ResourceBindData bd; // [rsp+38h] [rbp-39h]
  Scaleform::String result; // [rsp+48h] [rbp-29h]
  Scaleform::GFx::ResourceBindData pdata; // [rsp+50h] [rbp-21h]
  LPCRITICAL_SECTION lpCriticalSection; // [rsp+60h] [rbp-11h]
  unsigned int v44; // [rsp+68h] [rbp-9h]
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v45; // [rsp+70h] [rbp-1h]
  Scaleform::GFx::MovieDefImpl *v46; // [rsp+78h] [rbp+7h]
  Scaleform::GFx::MovieDefImpl *v47; // [rsp+80h] [rbp+Fh]
  __int64 v48; // [rsp+88h] [rbp+17h]
  Scaleform::GFx::MovieDefImpl::BindTaskData *v49; // [rsp+D0h] [rbp+5Fh]
  Scaleform::GFx::ResourceId rid; // [rsp+D8h] [rbp+67h]

  v49 = this;
  v48 = -2i64;
  v5 = pls;
  v6 = pdefImpl;
  v7 = pimport;
  v8 = this;
  v9 = 0;
  if ( pimport->Imports.Data.Size )
  {
    v10 = 0i64;
    do
    {
      v11 = (signed __int64)&v7->Imports.Data.Data[v10];
      pdata.pResource.pObject = 0i64;
      pdata.pBinding = 0i64;
      if ( (unsigned __int8)Scaleform::GFx::MovieDefImpl::GetExportedResource(
                              v6,
                              &pdata,
                              (Scaleform::String *)v11,
                              0i64) )
      {
        v44 = *(_DWORD *)(v11 + 8);
        phandle.HType = 0;
        phandle.pResource = 0i64;
        v13 = v8->pDataDef.pObject;
        rid.Id = v44;
        if ( (unsigned __int8)Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                                v13->pData.pObject,
                                &phandle,
                                (__int64)&rid) )
          Scaleform::GFx::ResourceBinding::SetBindData(&v8->ResourceBinding, phandle.BindIndex, &pdata);
        if ( phandle.HType == RH_Pointer
          && phandle.pResource
          && !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
        {
          v14 = phandle.pResource;
          v15 = phandle.pResource->pLib;
          if ( v15 )
          {
            v15->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, (unsigned int)phandle.pResource);
            v14->pLib = 0i64;
          }
          v14->vfptr->__vecDelDtor(v14, 1u);
        }
      }
      else
      {
        v12 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v5->pLog.pObject;
        if ( v12 )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
            v12 + 3,
            "Import failed - resource %s is not exported from movie %s",
            (*(_QWORD *)v11 & 0xFFFFFFFFFFFFFFFCui64) + 12,
            (v7->SourceUrl.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
      }
      v16 = pdata.pResource.pObject;
      if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
      {
        v17 = v16->pLib;
        if ( v17 )
        {
          v17->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v17->vfptr, (unsigned int)v16);
          v16->pLib = 0i64;
        }
        v16->vfptr->__vecDelDtor(v16, 1u);
      }
      v10 = ++v9;
    }
    while ( v9 < v7->Imports.Data.Size );
  }
  if ( !recursive )
  {
    lpCriticalSection = &v8->ImportSourceLock.cs;
    EnterCriticalSection(&v8->ImportSourceLock.cs);
    if ( v6 )
      _InterlockedExchangeAdd(&v6->RefCount.Value, 1u);
    v46 = v6;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> *)&v8->ImportSourceMovies.Data.Data,
      &v8->ImportSourceMovies,
      v8->ImportSourceMovies.Data.Size + 1);
    v45 = &v8->ImportSourceMovies.Data.Data[v8->ImportSourceMovies.Data.Size - 1];
    v18 = &v45->pObject;
    if ( v45 )
    {
      if ( v6 )
        _InterlockedExchangeAdd(&v6->RefCount.Value, 1u);
      *v18 = v6;
    }
    if ( v6 && !_InterlockedDecrement(&v6->RefCount.Value) )
    {
      v19 = v6->pLib;
      if ( v19 )
      {
        v19->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v19->vfptr, (unsigned int)v6);
        v6->pLib = 0i64;
      }
      v6->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v6->vfptr, 1u);
    }
    LeaveCriticalSection(lpCriticalSection);
    v20 = 0;
    recursive = 0;
    Scaleform::String::ToLower((Scaleform::String *)&v7->SourceUrl.0, &result);
    if ( strstr((const char *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), "_glyphs") )
    {
      recursive = 1;
      if ( v6 )
        _InterlockedExchangeAdd(&v6->RefCount.Value, 1u);
      v47 = v6;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy> *)&v5->SubstituteFontMovieDefs.Data.Data,
        &v5->SubstituteFontMovieDefs,
        v5->SubstituteFontMovieDefs.Data.Size + 1);
      v21 = &v5->SubstituteFontMovieDefs.Data.Data[v5->SubstituteFontMovieDefs.Data.Size - 1];
      v45 = v21;
      if ( v21 )
      {
        if ( v6 )
          _InterlockedExchangeAdd(&v6->RefCount.Value, 1u);
        v21->pObject = v6;
      }
      if ( v6 && !_InterlockedDecrement(&v6->RefCount.Value) )
      {
        v22 = v6->pLib;
        if ( v22 )
        {
          v22->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, (unsigned int)v6);
          v6->pLib = 0i64;
        }
        v6->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v6->vfptr, 1u);
      }
      v20 = recursive;
    }
    v23 = v8->pDataDef.pObject->pData.pObject->BindData.pFonts.Value;
    v24 = v6->pBindData.pObject->pDataDef.pObject->pData.pObject;
    v25 = v24->BindData.pFonts.Value;
    for ( i = v24->BindData.pFonts.Value; v23; v23 = v23->pNext.Value )
    {
      v26 = v23->pFontData.pObject;
      if ( !((unsigned int (__fastcall *)(Scaleform::Render::Font *))v26->vfptr[18].__vecDelDtor)(v23->pFontData.pObject)
        || v20 )
      {
        v27 = v25;
        if ( v25 )
        {
          while ( 1 )
          {
            v28 = v27->pFontData.pObject;
            if ( ((unsigned int (__fastcall *)(Scaleform::Render::Font *))v28->vfptr[18].__vecDelDtor)(v27->pFontData.pObject) )
            {
              v29 = v28->Flags & 0x303;
              v30 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v28->vfptr[1].__vecDelDtor)(v28);
              if ( (v26->Flags & (v29 & 0x10 | ((v29 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v29 & 0x313) )
              {
                v31 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v26->vfptr[1].__vecDelDtor)(v26);
                if ( !Scaleform::String::CompareNoCase(v31, v30) )
                  break;
              }
            }
            v27 = v27->pNext.Value;
            if ( !v27 )
              goto LABEL_67;
          }
          bd.pResource.pObject = 0i64;
          bd.pBinding = 0i64;
          v32 = v6->pBindData.pObject;
          v33 = v27->BindIndex;
          if ( v32->ResourceBinding.Frozen && v33 < v32->ResourceBinding.ResourceCount )
          {
            v34 = (signed __int64)&v32->ResourceBinding.pResources[v33];
            if ( *(_QWORD *)v34 )
              _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v34 + 8i64), 1u);
            v35 = *(Scaleform::GFx::Resource **)v34;
            bd.pResource.pObject = *(Scaleform::GFx::Resource **)v34;
            bd.pBinding = *(Scaleform::GFx::ResourceBinding **)(v34 + 8);
          }
          else
          {
            Scaleform::GFx::ResourceBinding::GetResourceData_Locked(&v32->ResourceBinding, &bd, v33);
            v35 = bd.pResource.pObject;
          }
          if ( v35 )
          {
            Scaleform::GFx::ResourceBinding::SetBindData(&v49->ResourceBinding, v23->BindIndex, &bd);
            v35 = bd.pResource.pObject;
          }
          if ( v35 && !_InterlockedDecrement(&v35->RefCount.Value) )
          {
            v36 = bd.pResource.pObject;
            v37 = bd.pResource.pObject->pLib;
            if ( v37 )
            {
              v37->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v37->vfptr, (unsigned int)bd.pResource.pObject);
              v36->pLib = 0i64;
            }
            v36->vfptr->__vecDelDtor(v36, 1u);
          }
LABEL_67:
          v25 = i;
        }
        v20 = recursive;
      }
    }
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 2192
// RVA: 0x903EF0
char __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImportThroughFontLib(Scaleform::GFx::MovieDefImpl::BindTaskData *this, Scaleform::GFx::ImportData *pimport)
{
  Scaleform::GFx::ImportData *v2; // r15
  Scaleform::GFx::MovieDefImpl::BindTaskData *v3; // r13
  unsigned int v4; // esi
  __int64 v5; // rbx
  Scaleform::GFx::ResourceBinding *v6; // r14
  signed __int64 v7; // rbx
  Scaleform::GFx::FontData *v8; // rax
  Scaleform::Render::Font *v9; // rax
  Scaleform::Render::Font *v10; // rdi
  Scaleform::GFx::FontResource *v11; // rax
  Scaleform::GFx::Resource *v12; // rax
  Scaleform::GFx::MovieDataDef *v13; // rcx
  Scaleform::GFx::Resource *v14; // rbx
  Scaleform::GFx::ResourceLibBase *v15; // rcx
  Scaleform::GFx::Resource *v16; // rbx
  Scaleform::GFx::ResourceLibBase *v17; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v18; // rdx
  Scaleform::GFx::ResourceHandle phandle; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::ResourceBindData bd; // [rsp+40h] [rbp-18h]
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *rid; // [rsp+A0h] [rbp+48h]
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v23; // [rsp+A8h] [rbp+50h]
  Scaleform::Render::Font *v24; // [rsp+B0h] [rbp+58h]
  Scaleform::Lock *v25; // [rsp+B8h] [rbp+60h]

  v2 = pimport;
  v3 = this;
  v4 = 0;
  if ( pimport->Imports.Data.Size )
  {
    v5 = 0i64;
    v6 = &this->ResourceBinding;
    do
    {
      v7 = (signed __int64)&v2->Imports.Data.Data[v5];
      bd.pResource.pObject = 0i64;
      bd.pBinding = v6;
      v8 = (Scaleform::GFx::FontData *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                         Scaleform::Memory::pGlobalHeap,
                                         136ui64,
                                         0i64);
      rid = (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)v8;
      if ( v8 )
      {
        Scaleform::GFx::FontData::FontData(v8, (const char *)((*(_QWORD *)v7 & 0xFFFFFFFFFFFFFFFCui64) + 12), 0);
        v10 = v9;
      }
      else
      {
        v10 = 0i64;
      }
      v24 = v10;
      v10->Flags |= 0x40u;
      v11 = (Scaleform::GFx::FontResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              64i64);
      rid = (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)v11;
      if ( v11 )
        Scaleform::GFx::FontResource::FontResource(v11, v10, v6);
      else
        v12 = 0i64;
      bd.pResource.pObject = v12;
      LODWORD(v23) = *(_DWORD *)(v7 + 8);
      phandle.HType = 0;
      phandle.pResource = 0i64;
      v13 = v3->pDataDef.pObject;
      LODWORD(rid) = (_DWORD)v23;
      if ( (unsigned __int8)Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                              v13->pData.pObject,
                              &phandle,
                              (__int64)&rid) )
        Scaleform::GFx::ResourceBinding::SetBindData(v6, phandle.BindIndex, &bd);
      if ( phandle.HType == RH_Pointer
        && phandle.pResource
        && !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
      {
        v14 = phandle.pResource;
        v15 = phandle.pResource->pLib;
        if ( v15 )
        {
          v15->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, (unsigned int)phandle.pResource);
          v14->pLib = 0i64;
        }
        v14->vfptr->__vecDelDtor(v14, 1u);
      }
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
      if ( bd.pResource.pObject && !_InterlockedDecrement(&bd.pResource.pObject->RefCount.Value) )
      {
        v16 = bd.pResource.pObject;
        v17 = bd.pResource.pObject->pLib;
        if ( v17 )
        {
          v17->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v17->vfptr, (unsigned int)bd.pResource.pObject);
          v16->pLib = 0i64;
        }
        v16->vfptr->__vecDelDtor(v16, 1u);
      }
      v5 = ++v4;
    }
    while ( v4 < v2->Imports.Data.Size );
  }
  v25 = &v3->ImportSourceLock;
  EnterCriticalSection(&v3->ImportSourceLock.cs);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> *)&v3->ImportSourceMovies.Data.Data,
    &v3->ImportSourceMovies,
    v3->ImportSourceMovies.Data.Size + 1);
  v18 = &v3->ImportSourceMovies.Data.Data[v3->ImportSourceMovies.Data.Size - 1];
  rid = v18;
  v23 = v18;
  if ( v18 )
    v18->pObject = 0i64;
  LeaveCriticalSection(&v3->ImportSourceLock.cs);
  return 1;
}

// File Line: 2257
// RVA: 0x8DE0E0
Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *__fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::GetShapeMeshProvider(Scaleform::GFx::MovieDefImpl::BindTaskData *this, Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *result, Scaleform::Render::ShapeMeshProvider *defMeshProv)
{
  Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *v3; // r15
  Scaleform::GFx::MovieDefImpl::BindTaskData *v4; // rbx
  __int64 v5; // rdi
  _RTL_CRITICAL_SECTION *v6; // rsi
  signed __int64 v7; // rax
  __int64 v8; // rdx
  signed __int64 v9; // rax
  signed __int64 v10; // rbx
  __int64 v11; // rbx
  char v12; // bp
  char v13; // bp
  Scaleform::Render::ShapeMeshProvider *v15; // [rsp+70h] [rbp+8h]
  Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *v16; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::AS3::Class *key; // [rsp+80h] [rbp+18h]
  Scaleform::Lock *v18; // [rsp+88h] [rbp+20h]

  key = (Scaleform::GFx::AS3::Class *)defMeshProv;
  v16 = result;
  v3 = result;
  v4 = this;
  v5 = 0i64;
  v6 = &this->ImportSourceLock.cs;
  v18 = &this->ImportSourceLock;
  EnterCriticalSection(&this->ImportSourceLock.cs);
  v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF>>::findIndexAlt<Scaleform::GFx::ASString>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *)&v4->BoundShapeMeshProviders,
         &key);
  if ( v7 >= 0
    && (v9 = (signed __int64)&v4->BoundShapeMeshProviders.mHash.pTable[2 * (v7 + 1)]) != 0
    && (v10 = v9 + 8, v9 != -8) )
  {
    if ( *(_QWORD *)v10 )
      (*(void (__cdecl **)(signed __int64, __int64))(*(_QWORD *)(*(_QWORD *)v10 + 16i64) + 8i64))(
        *(_QWORD *)v10 + 16i64,
        v8);
    v11 = *(_QWORD *)v10;
    v15 = (Scaleform::Render::ShapeMeshProvider *)v11;
    v12 = 1;
    if ( v11 )
      (*(void (__cdecl **)(__int64, __int64))(*(_QWORD *)(v11 + 16) + 8i64))(v11 + 16, v8);
    v5 = (__int64)v15;
  }
  else
  {
    v15 = 0i64;
    v12 = 2;
    v11 = 0i64;
  }
  v3->pObject = v15;
  v13 = v12 | 4;
  if ( v13 & 2 )
  {
    v13 &= 0xFDu;
    if ( v5 )
      (*(void (__cdecl **)(__int64, __int64))(*(_QWORD *)(v5 + 16) + 16i64))(v5 + 16, v8);
  }
  if ( v13 & 1 && v11 )
    (*(void (__cdecl **)(__int64, __int64))(*(_QWORD *)(v11 + 16) + 16i64))(v11 + 16, v8);
  LeaveCriticalSection(v6);
  return v3;
}

// File Line: 2265
// RVA: 0x8B2D40
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::AddShapeMeshProvider(Scaleform::GFx::MovieDefImpl::BindTaskData *this, Scaleform::Render::ShapeMeshProvider *defMeshProv, Scaleform::Render::ShapeMeshProvider *resolvedMeshProv)
{
  Scaleform::Render::ShapeMeshProvider *v3; // rdi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v4; // rsi
  _RTL_CRITICAL_SECTION *v5; // rbx
  Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeRef key; // [rsp+28h] [rbp-30h]
  Scaleform::Render::ShapeMeshProvider *v7; // [rsp+60h] [rbp+8h]
  Scaleform::Render::ShapeMeshProvider *v8; // [rsp+68h] [rbp+10h]
  Scaleform::Lock *v9; // [rsp+70h] [rbp+18h]

  v8 = defMeshProv;
  v3 = resolvedMeshProv;
  v4 = this;
  v5 = &this->ImportSourceLock.cs;
  v9 = &this->ImportSourceLock;
  EnterCriticalSection(&this->ImportSourceLock.cs);
  if ( v3 )
    (*((void (__cdecl **)(Scaleform::Render::MeshProviderVtbl **))&v3->vfptr->__vecDelDtor + 1))(&v3->vfptr);
  v7 = v3;
  key.pFirst = &v8;
  key.pSecond = (Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *)&v7;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ShapeMeshProvider *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ShapeMeshProvider *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::Sh)&v4->BoundShapeMeshProviders.mHash.pTable,
    &v4->BoundShapeMeshProviders,
    &key);
  if ( v7 )
    ((void (__cdecl *)(Scaleform::Render::MeshProviderVtbl **))v7->vfptr->Release)(&v7->vfptr);
  LeaveCriticalSection(v5);
}

// File Line: 2314
// RVA: 0x896F50
void __fastcall Scaleform::GFx::GFxMovieDefImplKey::GFxMovieDefImplKey(Scaleform::GFx::GFxMovieDefImplKey *this, Scaleform::GFx::MovieDataDef *pdataDef, Scaleform::GFx::MovieDefBindStates *pbindStates)
{
  Scaleform::GFx::MovieDefBindStates *v3; // rdi
  Scaleform::GFx::GFxMovieDefImplKey *v4; // rbx

  v3 = pbindStates;
  v4 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::GFxMovieDefImplKey,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::GFxMovieDefImplKey::`vftable;
  if ( pdataDef )
    _InterlockedExchangeAdd(&pdataDef->RefCount.Value, 1u);
  this->pDataDef.pObject = pdataDef;
  if ( pbindStates )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pbindStates);
  v4->pBindStates.pObject = v3;
}

// File Line: 2351
// RVA: 0x8D9850
unsigned __int64 __fastcall Scaleform::GFx::GFxMovieDefImplKeyInterface::GetHashCode(Scaleform::GFx::GFxMovieDefImplKeyInterface *this, void *hdata)
{
  _QWORD *v2; // rax

  v2 = (_QWORD *)*((_QWORD *)hdata + 3);
  return v2[9] ^ v2[8] ^ v2[7] ^ v2[6] ^ v2[4] ^ v2[3] ^ v2[2] ^ ((v2[9] ^ v2[8] ^ v2[7] ^ v2[6] ^ v2[4] ^ v2[3] ^ v2[2] ^ *((_QWORD *)hdata + 2)) >> 7) ^ *((_QWORD *)hdata + 2);
}

// File Line: 2356
// RVA: 0x8E7F40
bool __fastcall Scaleform::GFx::GFxMovieDefImplKeyInterface::KeyEquals(Scaleform::GFx::GFxMovieDefImplKeyInterface *this, void *hdata, Scaleform::GFx::ResourceKey *other)
{
  bool result; // al
  _QWORD *v4; // rcx
  _QWORD *v5; // rcx
  _QWORD *v6; // rdx

  if ( this != (Scaleform::GFx::GFxMovieDefImplKeyInterface *)other->pKeyInterface )
    return 0;
  v4 = other->hKeyData;
  result = 0;
  if ( *((_QWORD *)hdata + 2) == v4[2] )
  {
    v5 = (_QWORD *)v4[3];
    v6 = (_QWORD *)*((_QWORD *)hdata + 3);
    if ( v6[2] == v5[2]
      && v6[3] == v5[3]
      && v6[4] == v5[4]
      && v6[6] == v5[6]
      && v6[7] == v5[7]
      && v6[8] == v5[8]
      && v6[9] == v5[9] )
    {
      result = 1;
    }
  }
  return result;
}

// File Line: 2364
// RVA: 0x159C270
__int64 Scaleform::GFx::_dynamic_initializer_for__GFxMovieDefImplKeyInterface_Instance__()
{
  GFxMovieDefImplKeyInterface_Instance.vfptr = (Scaleform::GFx::ResourceKey::KeyInterfaceVtbl *)&Scaleform::GFx::GFxMovieDefImplKeyInterface::`vftable;
  return atexit(Scaleform::GFx::_dynamic_atexit_destructor_for__GFxMovieDefImplKeyInterface_Instance__);
}

// File Line: 2369
// RVA: 0x8C1510
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::MovieDefImpl::CreateMovieKey(Scaleform::GFx::ResourceKey *result, Scaleform::GFx::MovieDataDef *pdataDef, Scaleform::GFx::MovieDefBindStates *pbindStates)
{
  Scaleform::GFx::MovieDefBindStates *v3; // rsi
  Scaleform::GFx::MovieDataDef *v4; // rbp
  Scaleform::GFx::ResourceKey *v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rbx
  Scaleform::GFx::GFxMovieDefImplKey *v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rax

  v3 = pbindStates;
  v4 = pdataDef;
  v5 = result;
  v6 = 0i64;
  v7 = (Scaleform::GFx::GFxMovieDefImplKey *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               32ui64,
                                               0i64);
  if ( v7 )
  {
    Scaleform::GFx::GFxMovieDefImplKey::GFxMovieDefImplKey(v7, v4, v3);
    v6 = v8;
  }
  GFxMovieDefImplKeyInterface_Instance.vfptr->AddRef(
    (Scaleform::GFx::ResourceKey::KeyInterface *)&GFxMovieDefImplKeyInterface_Instance,
    v6);
  v5->pKeyInterface = (Scaleform::GFx::ResourceKey::KeyInterface *)&GFxMovieDefImplKeyInterface_Instance;
  v5->hKeyData = v6;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  return v5;
}

// File Line: 2381
// RVA: 0x8D7550
_BOOL8 __fastcall Scaleform::GFx::MovieDefImpl::GetExportedResource(Scaleform::GFx::MovieDefImpl *this, Scaleform::GFx::ResourceBindData *pdata, Scaleform::String *symbol, Scaleform::GFx::MovieDefImpl *ignoreDef)
{
  Scaleform::GFx::ResourceBindData *v4; // rdi
  Scaleform::GFx::MovieDefImpl *v5; // rsi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v7; // rbx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v8; // rax
  unsigned __int64 v9; // rax
  signed __int64 v10; // rax
  unsigned __int64 *v11; // rdx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v12; // rax
  unsigned int v13; // er8
  Scaleform::GFx::Resource *v14; // rax
  Scaleform::GFx::Resource *v15; // rsi
  Scaleform::GFx::Resource *v16; // rdi
  Scaleform::GFx::ResourceLibBase *v17; // rcx
  bool v18; // di
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v19; // rdi
  unsigned __int64 v20; // r8
  unsigned __int64 v21; // rsi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v22; // rax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> *v23; // rdi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v24; // rdx
  unsigned __int64 v25; // rcx
  unsigned int v26; // edi
  unsigned __int64 v27; // rdx
  __int64 v28; // rcx
  Scaleform::GFx::MovieDefImpl *v29; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v30; // rdx
  unsigned __int64 v31; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v32; // rsi
  Scaleform::GFx::MovieDefImpl *v33; // rdi
  Scaleform::GFx::ResourceLibBase *v34; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v35; // rdx
  unsigned __int64 v36; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v37; // rsi
  Scaleform::GFx::MovieDefImpl *v38; // rdi
  Scaleform::GFx::ResourceLibBase *v39; // rcx
  Scaleform::GFx::Resource *v40; // rbx
  Scaleform::GFx::ResourceLibBase *v41; // rcx
  char v43; // [rsp+20h] [rbp-39h]
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+28h] [rbp-31h]
  Scaleform::GFx::ResourceHandle v45; // [rsp+40h] [rbp-19h]
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v46; // [rsp+50h] [rbp-9h]
  Scaleform::String::NoCaseKey key; // [rsp+58h] [rbp-1h]
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> *v48; // [rsp+60h] [rbp+7h]
  Scaleform::GFx::MovieDataDef::LoadTaskData *v49; // [rsp+68h] [rbp+Fh]
  __int64 v50; // [rsp+70h] [rbp+17h]
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v51; // [rsp+78h] [rbp+1Fh]
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v52; // [rsp+80h] [rbp+27h]
  Scaleform::GFx::MovieDefImpl *v53; // [rsp+C0h] [rbp+67h]
  unsigned __int64 v54; // [rsp+C0h] [rbp+67h]
  unsigned __int64 v55; // [rsp+C0h] [rbp+67h]
  Scaleform::GFx::ResourceBindData *pdataa; // [rsp+C8h] [rbp+6Fh]
  Scaleform::String *symbola; // [rsp+D0h] [rbp+77h]
  Scaleform::GFx::MovieDefImpl *v58; // [rsp+D8h] [rbp+7Fh]

  v58 = ignoreDef;
  symbola = symbol;
  pdataa = pdata;
  v53 = this;
  v50 = -2i64;
  v4 = pdata;
  v5 = this;
  v45.HType = 0;
  v45.pResource = 0i64;
  v6 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v7 = 0i64;
  v49 = 0i64;
  if ( v6->LoadState < 2 )
  {
    v7 = v6;
    v49 = v6;
    EnterCriticalSection(&v6->ResourceLock.cs);
    symbol = symbola;
  }
  v8 = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)v5->pBindData.pObject->pDataDef.pObject->pData.pObject;
  key.pStr = symbol;
  v46 = v8 + 48;
  if ( v8[48].pTable
    && (v9 = Scaleform::String::BernsteinHashFunctionCIS(
               (const void *)((symbol->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
               *(_QWORD *)(symbol->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
               0x1505ui64),
        v10 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
                v46,
                &key,
                v9 & v46->pTable->SizeMask),
        v10 >= 0)
    && (v11 = &v46->pTable->EntryCount + 5 * v10 + 4) != 0i64 )
  {
    Scaleform::GFx::ResourceHandle::operator=(&v45, (Scaleform::GFx::ResourceHandle *)(v11 + 1));
    v43 = 1;
  }
  else
  {
    v43 = 0;
  }
  if ( v7 )
    LeaveCriticalSection(&v7->ResourceLock.cs);
  if ( v43 )
  {
    v12 = v5->pBindData.pObject;
    if ( v45.HType != 1 )
    {
      v4->pBinding = &v12->ResourceBinding;
      v14 = Scaleform::GFx::ResourceHandle::GetResource(&v45, &v5->pBindData.pObject->ResourceBinding);
      v15 = v14;
      if ( v14 )
        _InterlockedExchangeAdd(&v14->RefCount.Value, 1u);
      v16 = v4->pResource.pObject;
      if ( v16 && !_InterlockedDecrement(&v16->RefCount.Value) )
      {
        v17 = v16->pLib;
        if ( v17 )
        {
          v17->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v17->vfptr, (unsigned int)v16);
          v16->pLib = 0i64;
        }
        v16->vfptr->__vecDelDtor(v16, 1u);
      }
      v4 = pdataa;
      pdataa->pResource.pObject = v15;
      goto LABEL_25;
    }
    if ( v12->ResourceBinding.Frozen )
    {
      v13 = v45.BindIndex;
      if ( v45.BindIndex < v12->ResourceBinding.ResourceCount )
      {
        Scaleform::GFx::ResourceBindData::operator=(v4, &v12->ResourceBinding.pResources[v45.BindIndex]);
LABEL_25:
        v18 = v4->pResource.pObject != 0i64;
        goto LABEL_72;
      }
    }
    else
    {
      v13 = v45.BindIndex;
    }
    Scaleform::GFx::ResourceBinding::GetResourceData_Locked(&v12->ResourceBinding, v4, v13);
    goto LABEL_25;
  }
  v48 = &pheapAddr;
  pheapAddr.Data = 0i64;
  pheapAddr.Size = 0i64;
  pheapAddr.Policy.Capacity = 0i64;
  v19 = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v5->pBindData.pObject->ImportSourceLock;
  v46 = v19;
  EnterCriticalSection((LPCRITICAL_SECTION)v19);
  v20 = v5->pBindData.pObject->ImportSourceMovies.Data.Size;
  if ( v20 > pheapAddr.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &pheapAddr,
      &pheapAddr,
      v20);
  v21 = 0i64;
  v22 = v53->pBindData.pObject;
  if ( v22->ImportSourceMovies.Data.Size > 0 )
  {
    do
    {
      v23 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> *)v22->ImportSourceMovies.Data.Data[v21].pObject;
      if ( v23 != (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> *)v58 )
      {
        if ( v23 )
          _InterlockedExchangeAdd((volatile signed __int32 *)&v23->Size, 1u);
        v48 = v23;
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &pheapAddr,
          &pheapAddr,
          pheapAddr.Size + 1);
        v24 = &pheapAddr.Data[pheapAddr.Size - 1];
        v51 = &pheapAddr.Data[pheapAddr.Size - 1];
        v52 = &pheapAddr.Data[pheapAddr.Size - 1];
        if ( v24 )
        {
          if ( v23 )
            _InterlockedExchangeAdd((volatile signed __int32 *)&v23->Size, 1u);
          v24->pObject = (Scaleform::GFx::MovieDefImpl *)v23;
        }
        if ( v23 && !_InterlockedDecrement((volatile signed __int32 *)&v23->Size) )
        {
          v25 = v23->Policy.Capacity;
          if ( v25 )
          {
            (*(void (__fastcall **)(unsigned __int64, Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> *))(*(_QWORD *)v25 + 8i64))(
              v25,
              v23);
            v23->Policy.Capacity = 0i64;
          }
          ((void (__fastcall *)(Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> *, signed __int64))v23->Data->pObject)(
            v23,
            1i64);
        }
      }
      ++v21;
      v22 = v53->pBindData.pObject;
    }
    while ( v21 < v22->ImportSourceMovies.Data.Size );
    v19 = v46;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)v19);
  v26 = 0;
  v27 = pheapAddr.Size;
  if ( !pheapAddr.Size )
  {
LABEL_61:
    v35 = pheapAddr.Data;
    v36 = pheapAddr.Size;
    v55 = pheapAddr.Size;
    v37 = &pheapAddr.Data[pheapAddr.Size - 1];
    if ( pheapAddr.Size )
    {
      do
      {
        v38 = v37->pObject;
        if ( v37->pObject && !_InterlockedDecrement(&v38->RefCount.Value) )
        {
          v39 = v38->pLib;
          if ( v39 )
          {
            v39->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v39->vfptr, (unsigned int)v38);
            v38->pLib = 0i64;
          }
          v38->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v38->vfptr, 1u);
          v36 = v55;
        }
        --v37;
        v55 = --v36;
      }
      while ( v36 );
      v35 = pheapAddr.Data;
    }
    if ( v35 )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v18 = 0;
    goto LABEL_72;
  }
  v28 = 0i64;
  while ( 1 )
  {
    v29 = pheapAddr.Data[v28].pObject;
    if ( v29 )
      break;
LABEL_48:
    v28 = ++v26;
    if ( v26 >= v27 )
      goto LABEL_61;
  }
  if ( !Scaleform::GFx::MovieDefImpl::GetExportedResource(v29, pdataa, symbola, 0i64) )
  {
    v27 = pheapAddr.Size;
    goto LABEL_48;
  }
  v30 = pheapAddr.Data;
  v31 = pheapAddr.Size;
  v54 = pheapAddr.Size;
  v32 = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( pheapAddr.Size )
  {
    do
    {
      v33 = v32->pObject;
      if ( v32->pObject && !_InterlockedDecrement(&v33->RefCount.Value) )
      {
        v34 = v33->pLib;
        if ( v34 )
        {
          v34->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v34->vfptr, (unsigned int)v33);
          v33->pLib = 0i64;
        }
        v33->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v33->vfptr, 1u);
        v31 = v54;
      }
      --v32;
      v54 = --v31;
    }
    while ( v31 );
    v30 = pheapAddr.Data;
  }
  if ( v30 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v18 = 1;
LABEL_72:
  if ( v45.HType == RH_Pointer
    && v45.pResource
    && _InterlockedExchangeAdd(&v45.pResource->RefCount.Value, 0xFFFFFFFF) == 1 )
  {
    v40 = v45.pResource;
    v41 = v45.pResource->pLib;
    if ( v41 )
    {
      v41->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v41->vfptr, (unsigned int)v45.pResource);
      v40->pLib = 0i64;
    }
    v40->vfptr->__vecDelDtor(v40, 1u);
  }
  return v18;
}

// File Line: 2440
// RVA: 0x8C7D30
__int64 __fastcall Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(Scaleform::GFx::MovieDefImpl *this, Scaleform::GFx::MovieDefImpl *import)
{
  Scaleform::GFx::MovieDefImpl *v2; // rsi
  Scaleform::GFx::MovieDefImpl *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx
  __int64 v5; // rax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v6; // r8
  unsigned __int8 v7; // di

  v2 = import;
  v3 = this;
  v4 = &this->pBindData.pObject->ImportSourceLock.cs;
  EnterCriticalSection(v4);
  v5 = 0i64;
  v6 = v3->pBindData.pObject;
  if ( v6->ImportSourceMovies.Data.Size )
  {
    while ( v6->ImportSourceMovies.Data.Data[v5].pObject != v2 )
    {
      if ( ++v5 >= v6->ImportSourceMovies.Data.Size )
        goto LABEL_6;
    }
    v7 = 1;
  }
  else
  {
LABEL_6:
    v7 = 0;
  }
  LeaveCriticalSection(v4);
  return v7;
}

// File Line: 2453
// RVA: 0x8DB620
Scaleform::String *__fastcall Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(Scaleform::GFx::MovieDefImpl *this, __int64 rid)
{
  Scaleform::GFx::AS3::Abc::MbiInd *v2; // rbp
  Scaleform::GFx::MovieDefImpl *v3; // rsi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v4; // rcx
  signed __int64 v5; // rdi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *v7; // rsi
  signed __int64 v8; // rax
  signed __int64 v9; // rax

  v2 = (Scaleform::GFx::AS3::Abc::MbiInd *)rid;
  v3 = this;
  v4 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v5 = 0i64;
  v6 = 0i64;
  if ( v4->LoadState < 2 )
  {
    v6 = v4;
    EnterCriticalSection(&v4->ResourceLock.cs);
  }
  v7 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::Fix)v3->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v8 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
         v7 + 49,
         v2);
  if ( v8 >= 0 )
  {
    v9 = (signed __int64)&v7[49].pTable[2 * (v8 + 1)];
    if ( v9 )
      v5 = v9 + 8;
  }
  if ( v6 )
    LeaveCriticalSection(&v6->ResourceLock.cs);
  return (Scaleform::String *)v5;
}

// File Line: 2471
// RVA: 0x8D49B0
Scaleform::Ptr<Scaleform::GFx::ASSupport> *__fastcall Scaleform::GFx::MovieDefImpl::GetASSupport(Scaleform::GFx::MovieDefImpl *this, Scaleform::Ptr<Scaleform::GFx::ASSupport> *result)
{
  Scaleform::Ptr<Scaleform::GFx::ASSupport> *v2; // rbx
  signed int v3; // er8
  Scaleform::GFx::StateBag *v4; // rcx
  Scaleform::GFx::Resource *v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Ptr<Scaleform::GFx::ASSupport> resulta; // [rsp+40h] [rbp+8h]
  Scaleform::Ptr<Scaleform::GFx::ASSupport> *v9; // [rsp+48h] [rbp+10h]
  Scaleform::Ptr<Scaleform::GFx::ASSupport> v10; // [rsp+50h] [rbp+18h]

  v9 = result;
  v2 = result;
  v3 = (this->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes & 8 | 0x10) >> 3;
  v4 = (Scaleform::GFx::StateBag *)&this->vfptr;
  if ( v3 > 2 )
  {
    v5 = (Scaleform::GFx::Resource *)Scaleform::GFx::StateBag::GetAS3Support(v4, &v10)->pObject;
    v6 = (Scaleform::Render::RenderBuffer *)v10.pObject;
  }
  else
  {
    v5 = (Scaleform::GFx::Resource *)Scaleform::GFx::StateBag::GetAS2Support(v4, &resulta)->pObject;
    v6 = (Scaleform::Render::RenderBuffer *)resulta.pObject;
  }
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  if ( v5 )
  {
    Scaleform::Render::RenderBuffer::AddRef(v5);
    v2->pObject = (Scaleform::GFx::ASSupport *)v5;
  }
  else
  {
    v2->pObject = 0i64;
  }
  return v2;
}

// File Line: 2496
// RVA: 0x8D6050
Scaleform::GFx::CharacterCreateInfo *__fastcall Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(Scaleform::GFx::MovieDefImpl *this, Scaleform::GFx::CharacterCreateInfo *result, __int64 rid)
{
  Scaleform::GFx::CharacterCreateInfo *v3; // rsi
  Scaleform::GFx::MovieDefImpl *v4; // rdi
  Scaleform::GFx::MovieDataDef *v5; // rdx
  Scaleform::GFx::ResourceBinding *v6; // rbp
  Scaleform::GFx::Resource *v7; // r14
  Scaleform::GFx::Resource *v8; // rdi
  unsigned int v9; // er8
  signed __int64 v10; // rbp
  signed __int32 v11; // et0
  Scaleform::GFx::ResourceLibBase *v12; // rcx
  unsigned int v13; // eax
  Scaleform::GFx::Resource *v14; // rbx
  __int64 v15; // rcx
  int v17; // [rsp+28h] [rbp-50h]
  unsigned int index[2]; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::ResourceBindData pdata; // [rsp+38h] [rbp-40h]
  int v20; // [rsp+80h] [rbp+8h]
  int v21; // [rsp+88h] [rbp+10h]

  v3 = result;
  v4 = this;
  v17 = 0;
  *(_QWORD *)index = 0i64;
  result->pCharDef = 0i64;
  result->pBindDefImpl = 0i64;
  result->pResource = 0i64;
  v21 = *(_DWORD *)rid;
  v5 = this->pBindData.pObject->pDataDef.pObject;
  v20 = v21;
  if ( !Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
          v5->pData.pObject,
          (Scaleform::GFx::ResourceHandle *)&v17,
          (Scaleform::GFx::ResourceId)&v20) )
  {
    v7 = *(Scaleform::GFx::Resource **)index;
    goto LABEL_21;
  }
  v6 = &v4->pBindData.pObject->ResourceBinding;
  if ( v17 )
  {
    pdata.pResource.pObject = 0i64;
    pdata.pBinding = 0i64;
    if ( v6->Frozen )
    {
      v9 = index[0];
      if ( index[0] < v6->ResourceCount )
      {
        v10 = (signed __int64)&v6->pResources[index[0]];
        if ( *(_QWORD *)v10 )
          _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v10 + 8i64), 1u);
        v8 = *(Scaleform::GFx::Resource **)v10;
        pdata.pResource.pObject = *(Scaleform::GFx::Resource **)v10;
        v6 = *(Scaleform::GFx::ResourceBinding **)(v10 + 8);
        pdata.pBinding = v6;
        goto LABEL_11;
      }
    }
    else
    {
      v9 = index[0];
    }
    Scaleform::GFx::ResourceBinding::GetResourceData_Locked(v6, &pdata, v9);
    v6 = pdata.pBinding;
    v8 = pdata.pResource.pObject;
LABEL_11:
    if ( v8 )
    {
      v11 = _InterlockedDecrement(&v8->RefCount.Value);
      v8 = pdata.pResource.pObject;
      if ( !v11 )
      {
        v12 = pdata.pResource.pObject->pLib;
        if ( v12 )
        {
          v12->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, (unsigned int)pdata.pResource.pObject);
          v8->pLib = 0i64;
        }
        v8->vfptr->__vecDelDtor(v8, 1u);
      }
    }
    v7 = *(Scaleform::GFx::Resource **)index;
    goto LABEL_17;
  }
  v7 = *(Scaleform::GFx::Resource **)index;
  v8 = *(Scaleform::GFx::Resource **)index;
LABEL_17:
  if ( v8 )
  {
    v3->pResource = v8;
    v13 = v8->vfptr->GetResourceTypeCode(v8);
    if ( _bittest((const signed int *)&v13, 0xFu) )
    {
      v3->pBindDefImpl = v6->pOwnerDefImpl;
      v3->pCharDef = (Scaleform::GFx::CharacterDef *)v8;
    }
  }
LABEL_21:
  if ( !v17 && v7 && !_InterlockedDecrement(&v7->RefCount.Value) )
  {
    v14 = *(Scaleform::GFx::Resource **)index;
    v15 = *(_QWORD *)(*(_QWORD *)index + 16i64);
    if ( v15 )
    {
      (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v15 + 8i64))(v15, *(_QWORD *)index);
      v14->pLib = 0i64;
    }
    v14->vfptr->__vecDelDtor(v14, 1u);
  }
  return v3;
}

// File Line: 2529
// RVA: 0x919890
void __fastcall Scaleform::GFx::MovieDefImpl::VisitImportedMovies(Scaleform::GFx::MovieDefImpl *this, Scaleform::GFx::MovieDef::ImportVisitor *visitor)
{
  Scaleform::GFx::MovieDef::ImportVisitor *v2; // rdi
  Scaleform::GFx::MovieDefImpl *v3; // r13
  Scaleform::GFx::ImportData *volatile v4; // r15
  _RTL_CRITICAL_SECTION *v5; // rbx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v6; // rax
  unsigned __int64 v7; // rcx
  Scaleform::GFx::MovieDefImpl *v8; // r12
  unsigned __int64 *v9; // rsi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v10; // rax
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // r14
  signed __int64 v13; // rdi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v14; // rbx
  bool v15; // zf
  unsigned __int64 v16; // rax
  signed __int64 v17; // rax
  unsigned __int64 v18; // rax
  signed __int64 v19; // [rsp+20h] [rbp-28h]
  signed __int64 v20; // [rsp+28h] [rbp-20h]
  Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeRef v21; // [rsp+30h] [rbp-18h]
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v22; // [rsp+90h] [rbp+48h]
  Scaleform::GFx::MovieDef::ImportVisitor *v23; // [rsp+98h] [rbp+50h]
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > pmemAddr; // [rsp+A0h] [rbp+58h]
  Scaleform::String::NoCaseKey key; // [rsp+A8h] [rbp+60h]

  v23 = visitor;
  v19 = -2i64;
  v2 = visitor;
  v3 = this;
  v4 = this->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pImports.Value;
  if ( !v4 )
    return;
  v22 = &pmemAddr;
  pmemAddr.pTable = 0i64;
  while ( 1 )
  {
    v5 = &v3->pBindData.pObject->ImportSourceLock.cs;
    v20 = (signed __int64)&v3->pBindData.pObject->ImportSourceLock;
    EnterCriticalSection(v5);
    v6 = v3->pBindData.pObject;
    v7 = v4->ImportIndex;
    if ( v7 >= v6->ImportSourceMovies.Data.Size )
      break;
    v8 = v6->ImportSourceMovies.Data.Data[v7].pObject;
    LeaveCriticalSection(v5);
    v9 = (unsigned __int64 *)&v4->SourceUrl;
    v10 = pmemAddr.pTable;
    if ( pmemAddr.pTable )
    {
      v11 = Scaleform::String::BernsteinHashFunctionCIS(
              (const void *)((*v9 & 0xFFFFFFFFFFFFFFFCui64) + 12),
              *(_QWORD *)(*v9 & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
              0x1505ui64);
      v10 = pmemAddr.pTable;
      v12 = v11 & pmemAddr.pTable->SizeMask;
      v13 = v11 & pmemAddr.pTable->SizeMask;
      v14 = &pmemAddr.pTable[2 * (v11 & pmemAddr.pTable->SizeMask) + 1];
      if ( v14->EntryCount != -2i64 && v14->SizeMask == v12 )
      {
        while ( 1 )
        {
          if ( v14->SizeMask == v12 )
          {
            v15 = Scaleform::String::CompareNoCase(
                    (const char *)((v14[1].EntryCount & 0xFFFFFFFFFFFFFFFCui64) + 12),
                    (const char *)((*v9 & 0xFFFFFFFFFFFFFFFCui64) + 12)) == 0;
            v10 = pmemAddr.pTable;
            if ( v15 )
              break;
          }
          v13 = v14->EntryCount;
          if ( v14->EntryCount == -1i64 )
            goto LABEL_14;
          v14 = &v10[2 * v13 + 1];
        }
        if ( v13 >= 0 && pmemAddr.pTable && v13 <= (signed __int64)pmemAddr.pTable->SizeMask )
          goto LABEL_23;
      }
LABEL_14:
      v2 = v23;
    }
    if ( v8 )
    {
      ((void (__fastcall *)(Scaleform::GFx::MovieDef::ImportVisitor *, Scaleform::GFx::MovieDefImpl *, Scaleform::GFx::MovieDefImpl *, unsigned __int64, signed __int64, signed __int64))v2->vfptr->Visit)(
        v2,
        v3,
        v8,
        (*v9 & 0xFFFFFFFFFFFFFFFCui64) + 12,
        v19,
        v20);
      v10 = pmemAddr.pTable;
    }
    LOBYTE(v22) = 1;
    key.pStr = (Scaleform::String *)&v4->SourceUrl.0;
    if ( v10
      && (v16 = Scaleform::String::BernsteinHashFunctionCIS(
                  (const void *)((*v9 & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  *(_QWORD *)(*v9 & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                  0x1505ui64),
          v17 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
                  &pmemAddr,
                  &key,
                  v16 & pmemAddr.pTable->SizeMask),
          v17 >= 0)
      && pmemAddr.pTable
      && v17 <= (signed __int64)pmemAddr.pTable->SizeMask )
    {
      LOBYTE(pmemAddr.pTable[2 * v17 + 2].SizeMask) = (_BYTE)v22;
    }
    else
    {
      v21.pFirst = (Scaleform::String *)&v4->SourceUrl.0;
      v21.pSecond = (const bool *)&v22;
      v18 = Scaleform::String::BernsteinHashFunctionCIS(
              (const void *)((*v9 & 0xFFFFFFFFFFFFFFFCui64) + 12),
              *(_QWORD *)(*v9 & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
              0x1505ui64);
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&pmemAddr,
        &pmemAddr,
        &v21,
        v18);
    }
LABEL_23:
    v4 = v4->pNext.Value;
    v2 = v23;
    if ( !v4 )
      goto LABEL_26;
  }
  LeaveCriticalSection(v5);
LABEL_26:
  v22 = &pmemAddr;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&pmemAddr);
}

// File Line: 2576
// RVA: 0x919BB0
void __fastcall Scaleform::GFx::MovieDefImpl::VisitResources(Scaleform::GFx::MovieDefImpl *this, Scaleform::GFx::MovieDef::ResourceVisitor *pvisitor, unsigned int visitMask)
{
  unsigned int v3; // er14
  Scaleform::GFx::MovieDef::ResourceVisitor *v4; // r15
  Scaleform::GFx::MovieDefImpl *v5; // rsi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v7; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *v8; // rdx
  unsigned __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *v10; // rcx
  __int64 v11; // rdi
  __int64 v12; // r12
  __int64 v13; // rax
  signed __int64 v14; // r15
  Scaleform::GFx::Resource *v15; // rax
  Scaleform::GFx::Resource *v16; // r13
  __int64 v17; // rsi
  unsigned int v18; // eax
  bool v19; // zf
  unsigned __int64 v20; // rsi
  Scaleform::StringHashLH<Scaleform::GFx::ResourceHandle,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v21; // r11
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v22; // rdx
  unsigned __int64 v23; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v24; // rcx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v25; // rdx
  unsigned __int64 v26; // r8
  signed __int64 v27; // r10
  unsigned __int64 *v28; // rdx
  unsigned __int64 v29; // ST20_8
  unsigned __int64 v30; // rdx
  _QWORD *v31; // rcx
  _RTL_CRITICAL_SECTION *v32; // rbx
  unsigned __int64 v33; // r8
  unsigned __int64 v34; // rdi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v35; // rax
  signed __int64 v36; // rbx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v37; // rdx
  unsigned __int64 v38; // rbx
  unsigned __int64 v39; // rdi
  Scaleform::GFx::MovieDefImpl *v40; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v41; // rdx
  unsigned __int64 v42; // rsi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v43; // rdi
  Scaleform::GFx::MovieDefImpl *v44; // rbx
  Scaleform::GFx::ResourceLibBase *v45; // rcx
  signed __int64 v46; // [rsp+30h] [rbp-39h]
  __m128i v47; // [rsp+50h] [rbp-19h]
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+60h] [rbp-9h]
  Scaleform::GFx::MovieDefImpl *v49; // [rsp+D0h] [rbp+67h]
  Scaleform::GFx::MovieDef::ResourceVisitor *v50; // [rsp+D8h] [rbp+6Fh]
  int v51; // [rsp+E0h] [rbp+77h]
  Scaleform::GFx::MovieDataDef::LoadTaskData *v52; // [rsp+E8h] [rbp+7Fh]

  v50 = pvisitor;
  v49 = this;
  v3 = visitMask;
  v4 = pvisitor;
  v5 = this;
  if ( !(visitMask & 0x803F) )
    goto LABEL_56;
  v6 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v7 = 0i64;
  v52 = 0i64;
  if ( v6->LoadState < 2 )
  {
    v7 = v6;
    v52 = v6;
    EnterCriticalSection(&v6->ResourceLock.cs);
  }
  v8 = v5->pBindData.pObject->pDataDef.pObject->pData.pObject->Resources.mHash.pTable;
  if ( v8 )
  {
    v9 = 0i64;
    v10 = v8 + 1;
    do
    {
      if ( v10->EntryCount != -2i64 )
        break;
      ++v9;
      v10 += 2;
    }
    while ( v9 <= v8->SizeMask );
    v47.m128i_i64[0] = (__int64)&v5->pBindData.pObject->pDataDef.pObject->pData.pObject->Resources;
    v47.m128i_i64[1] = v9;
  }
  else
  {
    v47 = 0ui64;
  }
  _mm_store_si128(&v47, v47);
  v11 = v47.m128i_i64[1];
  v12 = v47.m128i_i64[0];
  while ( v12 )
  {
    v13 = *(_QWORD *)v12;
    if ( !*(_QWORD *)v12 || v11 > *(_QWORD *)(v13 + 8) )
      break;
    v14 = 32 * v11;
    v15 = Scaleform::GFx::ResourceHandle::GetResource(
            (Scaleform::GFx::ResourceHandle *)(32 * v11 + v13 + 32),
            &v5->pBindData.pObject->ResourceBinding);
    v16 = v15;
    if ( !v15 )
      goto LABEL_47;
    v17 = (unsigned __int8)v15->vfptr->GetResourceTypeCode(v15);
    v18 = v16->vfptr->GetResourceTypeCode(v16) >> 8;
    switch ( (unsigned __int8)v18 )
    {
      case 1u:
        if ( (_DWORD)v17 == 1 )
        {
          v19 = (v3 & 2) == 0;
        }
        else
        {
          if ( (_DWORD)v17 != 2 )
            goto LABEL_46;
          v19 = (v3 & 4) == 0;
        }
        break;
      case 2u:
        v19 = (v3 & 1) == 0;
        break;
      case 4u:
        v19 = (v3 & 0x10) == 0;
        break;
      case 0x83u:
        v19 = (v3 & 8) == 0;
        break;
      case 0x84u:
        v19 = (v3 & 0x20) == 0;
        break;
      default:
        goto LABEL_46;
    }
    if ( v19 )
    {
LABEL_46:
      v5 = v49;
LABEL_47:
      v4 = v50;
      goto LABEL_48;
    }
    v20 = 0i64;
    v21 = &v49->pBindData.pObject->pDataDef.pObject->pData.pObject->Exports;
    v22 = v21->mHash.pTable;
    if ( v21->mHash.pTable )
    {
      v23 = 0i64;
      v24 = v22 + 1;
      do
      {
        if ( v24->EntryCount != -2i64 )
          break;
        ++v23;
        v24 = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *)((char *)v24 + 40);
      }
      while ( v23 <= v22->SizeMask );
    }
    else
    {
      v21 = 0i64;
      v23 = 0i64;
    }
    while ( v21 )
    {
      v25 = v21->mHash.pTable;
      if ( !v21->mHash.pTable )
        break;
      v26 = v25->SizeMask;
      if ( (signed __int64)v23 > (signed __int64)v26 )
        break;
      v27 = (signed __int64)v25 + 40 * (v23 + 1);
      if ( *(_DWORD *)v27 == *(_DWORD *)(*(_QWORD *)v12 + v14 + 32)
        && *(_QWORD *)(v27 + 8) == *(_QWORD *)(*(_QWORD *)v12 + v14 + 40) )
      {
        v20 = (*(&v25[2].EntryCount + 5 * v23) & 0xFFFFFFFFFFFFFFFCui64) + 12;
        break;
      }
      if ( ++v23 <= v26 )
      {
        v28 = &v25[1].EntryCount + 5 * v23;
        do
        {
          if ( *v28 != -2i64 )
            break;
          ++v23;
          v28 += 5;
        }
        while ( v23 <= v26 );
      }
    }
    v51 = *(_DWORD *)(v14 + *(_QWORD *)v12 + 24);
    v4 = v50;
    v29 = v20;
    v5 = v49;
    ((void (__fastcall *)(Scaleform::GFx::MovieDef::ResourceVisitor *, Scaleform::GFx::MovieDefImpl *, Scaleform::GFx::Resource *, int *, unsigned __int64))v50->vfptr->Visit)(
      v50,
      v49,
      v16,
      &v51,
      v29);
LABEL_48:
    v30 = *(_QWORD *)(*(_QWORD *)v12 + 8i64);
    if ( v11 <= (signed __int64)v30 && ++v11 <= v30 )
    {
      v31 = (_QWORD *)(32 * v11 + *(_QWORD *)v12 + 16i64);
      do
      {
        if ( *v31 != -2i64 )
          break;
        ++v11;
        v31 += 4;
      }
      while ( v11 <= v30 );
    }
  }
  if ( v7 )
    LeaveCriticalSection(&v7->ResourceLock.cs);
LABEL_56:
  if ( _bittest((const signed int *)&v3, 0xFu) )
  {
    pheapAddr.Data = 0i64;
    pheapAddr.Size = 0i64;
    pheapAddr.Policy.Capacity = 0i64;
    v32 = &v5->pBindData.pObject->ImportSourceLock.cs;
    v46 = (signed __int64)&v5->pBindData.pObject->ImportSourceLock;
    EnterCriticalSection(v32);
    v33 = v5->pBindData.pObject->ImportSourceMovies.Data.Size;
    if ( v33 > pheapAddr.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v33);
    v34 = 0i64;
    v35 = v5->pBindData.pObject;
    if ( v35->ImportSourceMovies.Data.Size )
    {
      do
      {
        v36 = (signed __int64)&v35->ImportSourceMovies.Data.Data[v34];
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &pheapAddr,
          &pheapAddr,
          pheapAddr.Size + 1);
        v37 = &pheapAddr.Data[pheapAddr.Size - 1];
        v47.m128i_i64[0] = (__int64)&pheapAddr.Data[pheapAddr.Size - 1];
        if ( v37 )
        {
          if ( *(_QWORD *)v36 )
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v36 + 8i64), 1u);
          v37->pObject = *(Scaleform::GFx::MovieDefImpl **)v36;
        }
        ++v34;
        v35 = v5->pBindData.pObject;
      }
      while ( v34 < v35->ImportSourceMovies.Data.Size );
      v32 = (_RTL_CRITICAL_SECTION *)v46;
    }
    LeaveCriticalSection(v32);
    v38 = 0i64;
    v39 = pheapAddr.Size;
    if ( pheapAddr.Size )
    {
      do
      {
        v40 = pheapAddr.Data[v38].pObject;
        if ( v40 )
          ((void (__fastcall *)(Scaleform::GFx::MovieDefImpl *, Scaleform::GFx::MovieDef::ResourceVisitor *, _QWORD))v40->vfptr[6].GetResourceTypeCode)(
            v40,
            v4,
            v3);
        ++v38;
      }
      while ( v38 < v39 );
    }
    v47.m128i_i64[0] = (__int64)&pheapAddr;
    v41 = pheapAddr.Data;
    v42 = pheapAddr.Size;
    v43 = &pheapAddr.Data[pheapAddr.Size - 1];
    if ( pheapAddr.Size )
    {
      do
      {
        v44 = v43->pObject;
        if ( v43->pObject && !_InterlockedDecrement(&v44->RefCount.Value) )
        {
          v45 = v44->pLib;
          if ( v45 )
          {
            v45->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v45->vfptr, (unsigned int)v44);
            v44->pLib = 0i64;
          }
          v44->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v44->vfptr, 1u);
        }
        --v43;
        --v42;
      }
      while ( v42 );
      v41 = pheapAddr.Data;
    }
    if ( v41 )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 2688
// RVA: 0x8DD800
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::MovieDefImpl::GetResource(Scaleform::GFx::MovieDefImpl *this, const char *pexportName)
{
  Scaleform::GFx::MovieDefImpl *v2; // rdi
  __int64 v4; // rcx
  Scaleform::GFx::Resource *v5; // rsi
  __int64 v6; // rbx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v7; // r14
  unsigned __int64 v8; // rax
  signed __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v10; // rcx
  Scaleform::String v11; // [rsp+58h] [rbp+10h]
  __int64 v12; // [rsp+60h] [rbp+18h]
  Scaleform::String::NoCaseKey key; // [rsp+68h] [rbp+20h]

  v2 = this;
  if ( !pexportName )
    return 0i64;
  Scaleform::String::String(&v11, pexportName);
  v4 = (__int64)v2->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v5 = 0i64;
  v6 = 0i64;
  v12 = 0i64;
  if ( *(_DWORD *)(v4 + 228) < 2 )
  {
    v6 = v4;
    v12 = v4;
    EnterCriticalSection((LPCRITICAL_SECTION)(v4 + 328));
  }
  v7 = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)v2->pBindData.pObject->pDataDef.pObject->pData.pObject;
  key.pStr = &v11;
  if ( v7[48].pTable )
  {
    v8 = Scaleform::String::BernsteinHashFunctionCIS(
           (const void *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
           *(_QWORD *)(v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
           0x1505ui64);
    v9 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
           v7 + 48,
           &key,
           v8 & v7[48].pTable->SizeMask);
    if ( v9 >= 0 )
    {
      v10 = v7[48].pTable;
      if ( v10 )
      {
        if ( v9 <= (signed __int64)v10->SizeMask )
          v5 = Scaleform::GFx::ResourceHandle::GetResource(
                 (Scaleform::GFx::ResourceHandle *)(&v10[2].SizeMask + 5 * v9),
                 &v2->pBindData.pObject->ResourceBinding);
      }
    }
  }
  if ( v6 )
    LeaveCriticalSection((LPCRITICAL_SECTION)(v6 + 328));
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v5;
}

// File Line: 2717
// RVA: 0x8D85E0
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::MovieDefImpl::GetFontResource(Scaleform::GFx::MovieDefImpl *this, const char *pfontName, unsigned int styleFlags, Scaleform::GFx::MovieDefImpl::SearchInfo *psearchInfo)
{
  Scaleform::GFx::MovieDefImpl::SearchInfo *v4; // r15
  const char *v5; // r14
  Scaleform::GFx::MovieDefImpl *v6; // r12
  Scaleform::GFx::MovieDataDef *v7; // rbx
  Scaleform::GFx::FontDataUseNode *volatile v8; // rdi
  unsigned int v9; // esi
  unsigned int v10; // er14
  char *v11; // r13
  Scaleform::Render::Font *v12; // rcx
  const char *v13; // rax
  unsigned int v14; // er8
  signed __int64 v15; // rdx
  Scaleform::GFx::Resource *v16; // rbx
  Scaleform::GFx::ResourceVtbl *v17; // rcx
  signed __int32 v18; // et0
  Scaleform::GFx::Resource *v19; // rbx
  Scaleform::GFx::ResourceLibBase *v20; // rcx
  Scaleform::StringLH *v22; // rdi
  __int64 v23; // r13
  int v24; // er12
  Scaleform::GFx::Resource *v25; // r15
  signed __int64 v26; // r13
  unsigned __int64 v27; // rdi
  __int64 v28; // r14
  __int64 v29; // rbx
  __int64 *v30; // r14
  __int64 v31; // r9
  __int64 v32; // r11
  unsigned __int64 v33; // r10
  signed __int64 v34; // rdx
  signed __int64 v35; // r8
  unsigned __int64 v36; // rcx
  signed __int64 v37; // rcx
  __int64 v38; // rdx
  Scaleform::GFx::ResourceBinding *v39; // rcx
  unsigned int v40; // er8
  signed __int64 v41; // rcx
  signed __int32 v42; // et0
  Scaleform::GFx::ResourceLibBase *v43; // rcx
  __int16 v44; // ax
  const char *v45; // rax
  Scaleform::GFx::Resource *v46; // rbx
  Scaleform::GFx::ResourceLibBase *v47; // rcx
  __int64 v48; // r14
  const char *v49; // rax
  Scaleform::GFx::Resource *v50; // rdi
  Scaleform::GFx::ResourceLibBase *v51; // rcx
  __int64 v52; // rax
  __int64 v53; // rbx
  __int64 v54; // rcx
  _RTL_CRITICAL_SECTION *v55; // rbx
  unsigned __int64 v56; // rdi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v57; // rax
  Scaleform::GFx::MovieDefImpl *v58; // rcx
  __int64 v59; // rsi
  unsigned int v60; // [rsp+0h] [rbp-49h]
  Scaleform::String *v61; // [rsp+8h] [rbp-41h]
  unsigned int v62; // [rsp+10h] [rbp-39h]
  int v63; // [rsp+18h] [rbp-31h]
  Scaleform::GFx::Resource *index; // [rsp+20h] [rbp-29h]
  Scaleform::GFx::MovieDataDef *v65; // [rsp+28h] [rbp-21h]
  __int64 v66; // [rsp+28h] [rbp-21h]
  Scaleform::GFx::ResourceBindData v67; // [rsp+30h] [rbp-19h]
  Scaleform::GFx::ResourceBindData pdata; // [rsp+40h] [rbp-9h]
  __int64 v69; // [rsp+50h] [rbp+7h]
  int v70; // [rsp+58h] [rbp+Fh]
  __int64 v71; // [rsp+60h] [rbp+17h]
  _RTL_CRITICAL_SECTION *v72; // [rsp+68h] [rbp+1Fh]
  Scaleform::GFx::MovieDefImpl *v73; // [rsp+B0h] [rbp+67h]
  char *b; // [rsp+B8h] [rbp+6Fh]
  Scaleform::GFx::MovieDefImpl::SearchInfo *v75; // [rsp+C8h] [rbp+7Fh]

  v71 = -2i64;
  v4 = psearchInfo;
  v60 = styleFlags;
  v5 = pfontName;
  v6 = this;
  v7 = this->pBindData.pObject->pDataDef.pObject;
  v65 = v7;
  v8 = v7->pData.pObject->BindData.pFonts.Value;
  if ( v8 )
  {
    v9 = styleFlags & 0x10 | ((styleFlags & 0x300) != 0 ? 0x300 : 0) | 3;
    v10 = styleFlags & 0x313;
    v11 = b;
    do
    {
      v12 = v8->pFontData.pObject;
      if ( (v12->Flags & v9) == v10 )
      {
        v13 = (const char *)((__int64 (*)(void))v12->vfptr[1].__vecDelDtor)();
        if ( !Scaleform::String::CompareNoCase(v13, v11) )
        {
          pdata.pResource.pObject = 0i64;
          pdata.pBinding = 0i64;
          v14 = v8->BindIndex;
          if ( v6->pBindData.pObject->ResourceBinding.Frozen
            && v14 < v6->pBindData.pObject->ResourceBinding.ResourceCount )
          {
            v15 = (signed __int64)&v6->pBindData.pObject->ResourceBinding.pResources[v14];
            if ( *(_QWORD *)v15 )
              _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v15 + 8i64), 1u);
            v16 = *(Scaleform::GFx::Resource **)v15;
            pdata.pResource.pObject = *(Scaleform::GFx::Resource **)v15;
            pdata.pBinding = *(Scaleform::GFx::ResourceBinding **)(v15 + 8);
          }
          else
          {
            Scaleform::GFx::ResourceBinding::GetResourceData_Locked(
              &v6->pBindData.pObject->ResourceBinding,
              &pdata,
              v14);
            v16 = pdata.pResource.pObject;
          }
          if ( v16 )
          {
            if ( v4 )
            {
              v17 = v16[1].vfptr;
              if ( ~(unsigned __int8)(HIDWORD(v17->GetResourceReport) >> 6) & 1 )
              {
                if ( !(v60 & 3) || (*((unsigned __int8 (**)(void))v17->__vecDelDtor + 19))() )
                  v4->Status = 1;
                else
                  v4->Status = 3;
              }
              else
              {
                v4->Status = 2;
              }
            }
            v18 = _InterlockedDecrement(&v16->RefCount.Value);
            v19 = pdata.pResource.pObject;
            if ( !v18 )
            {
              v20 = pdata.pResource.pObject->pLib;
              if ( v20 )
              {
                v20->vfptr[1].__vecDelDtor(
                  (Scaleform::RefCountImplCore *)&v20->vfptr,
                  (unsigned int)pdata.pResource.pObject);
                v19->pLib = 0i64;
              }
              v19->vfptr->__vecDelDtor(v19, 1u);
            }
            return v19;
          }
        }
      }
      v8 = v8->pNext.Value;
    }
    while ( v8 );
    v5 = b;
    v7 = v65;
  }
  v22 = (Scaleform::StringLH *)v7->pData.pObject->BindData.pImports.Value;
  v61 = (Scaleform::String *)&v22->0;
  if ( v22 )
  {
    while ( 1 )
    {
      v62 = 0;
      if ( v22[1].HeapTypeBits )
        break;
LABEL_80:
      v22 = (Scaleform::StringLH *)v22[5].pData;
      v61 = (Scaleform::String *)&v22->0;
      if ( !v22 )
      {
        v6 = v73;
        goto LABEL_95;
      }
    }
    v23 = 0i64;
    while ( 1 )
    {
      if ( v4 )
        Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::Set<Scaleform::StringLH>(
          (Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> > *)&v4->ImportSearchUrls.pTable,
          &v4->ImportSearchUrls,
          v22 + 3);
      v24 = 0;
      v25 = 0i64;
      index = 0i64;
      v26 = 2 * v23;
      v27 = *(unsigned int *)(v22->HeapTypeBits + 8 * v26 + 8);
      v70 = v27;
      v28 = (__int64)v7->pData.pObject;
      v29 = 0i64;
      v69 = 0i64;
      if ( *(_DWORD *)(v28 + 228) < 2 )
      {
        v29 = v28;
        v69 = v28;
        EnterCriticalSection((LPCRITICAL_SECTION)(v28 + 328));
      }
      v30 = (__int64 *)(v28 + 376);
      v31 = *v30;
      if ( !*v30 )
        goto LABEL_70;
      v32 = *(_QWORD *)(v31 + 8);
      v33 = v32 & (v27 ^ (v27 >> 8));
      v34 = v32 & (v27 ^ (v27 >> 8));
      v35 = v31 + 32 * (v32 & (v27 ^ (v27 >> 8))) + 16;
      if ( *(_QWORD *)v35 == -2i64
        || (v32 & (*(unsigned int *)(v35 + 8) ^ ((unsigned __int64)*(unsigned int *)(v35 + 8) >> 8))) != v33 )
      {
        goto LABEL_70;
      }
      while ( 1 )
      {
        v36 = *(unsigned int *)(v35 + 8);
        if ( (v32 & (v36 ^ (v36 >> 8))) == v33 && (_DWORD)v36 == (_DWORD)v27 )
          break;
        v34 = *(_QWORD *)v35;
        if ( *(_QWORD *)v35 == -1i64 )
          goto LABEL_70;
        v35 = 32 * v34 + v31 + 16;
      }
      if ( v34 < 0 || !v30 || v34 > v32 )
      {
LABEL_70:
        if ( v29 )
          LeaveCriticalSection((LPCRITICAL_SECTION)(v29 + 328));
LABEL_72:
        v5 = b;
        v22 = (Scaleform::StringLH *)v61;
        goto LABEL_73;
      }
      v37 = v31 + 32 * (v34 + 1);
      if ( !*(_DWORD *)v37 )
      {
        v38 = *(_QWORD *)(v37 + 8);
        if ( v38 )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)(v38 + 8), 1u);
          v29 = v69;
        }
      }
      v24 = *(_DWORD *)v37;
      v63 = *(_DWORD *)v37;
      v25 = *(Scaleform::GFx::Resource **)(v37 + 8);
      index = *(Scaleform::GFx::Resource **)(v37 + 8);
      if ( v29 )
        LeaveCriticalSection((LPCRITICAL_SECTION)(v29 + 328));
      v39 = &v73->pBindData.pObject->ResourceBinding;
      if ( !v24 )
      {
        v19 = v25;
        goto LABEL_64;
      }
      v67.pResource.pObject = 0i64;
      v67.pBinding = 0i64;
      if ( v39->Frozen )
      {
        v40 = (unsigned int)index;
        if ( (unsigned int)index < v39->ResourceCount )
        {
          v41 = (signed __int64)&v39->pResources[(unsigned int)index];
          if ( *(_QWORD *)v41 )
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v41 + 8i64), 1u);
          v19 = *(Scaleform::GFx::Resource **)v41;
          v67.pResource.pObject = *(Scaleform::GFx::Resource **)v41;
          v67.pBinding = *(Scaleform::GFx::ResourceBinding **)(v41 + 8);
          goto LABEL_58;
        }
      }
      else
      {
        v40 = (unsigned int)index;
      }
      Scaleform::GFx::ResourceBinding::GetResourceData_Locked(v39, &v67, v40);
      v19 = v67.pResource.pObject;
LABEL_58:
      if ( v19 )
      {
        v42 = _InterlockedDecrement(&v19->RefCount.Value);
        v19 = v67.pResource.pObject;
        if ( !v42 )
        {
          v43 = v67.pResource.pObject->pLib;
          if ( v43 )
          {
            v43->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v43->vfptr, (unsigned int)v67.pResource.pObject);
            v19->pLib = 0i64;
          }
          v19->vfptr->__vecDelDtor(v19, 1u);
        }
      }
      v25 = index;
      v24 = v63;
LABEL_64:
      if ( !v19 )
        goto LABEL_72;
      v44 = v19->vfptr->GetResourceTypeCode(v19);
      v22 = (Scaleform::StringLH *)v61;
      v5 = b;
      if ( (v44 & 0xFF00) == 512
        && (HIDWORD(v19[1].vfptr->GetResourceReport) & (v60 & 0x10 | ((v60 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v60 & 0x313) )
      {
        if ( !Scaleform::String::CompareNoCase(
                (const char *)((*(_QWORD *)(v61->HeapTypeBits + 8 * v26) & 0xFFFFFFFFFFFFFFFCui64) + 12),
                b)
          || (v45 = (const char *)(*((__int64 (**)(void))v19[1].vfptr->__vecDelDtor + 1))(),
              !Scaleform::String::CompareNoCase(v45, v5)) )
        {
          v48 = (__int64)v75;
          if ( v75 )
          {
            v49 = (const char *)(v61[3].HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
            if ( (*(_QWORD *)v49 & 0x7FFFFFFFFFFFFFFFui64) < 0xE
              || Scaleform::String::CompareNoCase(&v49[(*(_QWORD *)v49 & 0x7FFFFFFFFFFFFFFFi64) - 2], "gfxfontlib.swf") )
            {
              *(_DWORD *)v48 = 4;
            }
            else
            {
              *(_DWORD *)v48 = 5;
            }
            Scaleform::String::operator=((Scaleform::String *)(v48 + 16), v61 + 3);
          }
          if ( !v24 && v25 && !_InterlockedDecrement(&v25->RefCount.Value) )
          {
            v50 = index;
            v51 = index->pLib;
            if ( v51 )
            {
              v51->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v51->vfptr, (unsigned int)index);
              v50->pLib = 0i64;
            }
            v50->vfptr->__vecDelDtor(v50, 1u);
            return v19;
          }
          return v19;
        }
      }
LABEL_73:
      if ( !v24 && v25 && !_InterlockedDecrement(&v25->RefCount.Value) )
      {
        v46 = index;
        v47 = index->pLib;
        if ( v47 )
        {
          v47->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v47->vfptr, (unsigned int)index);
          v46->pLib = 0i64;
        }
        v46->vfptr->__vecDelDtor(v46, 1u);
      }
      v23 = ++v62;
      v4 = v75;
      v7 = v65;
      if ( v62 >= v22[1].HeapTypeBits )
        goto LABEL_80;
    }
  }
LABEL_95:
  v52 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, const char *))v6->vfptr[6].GetResourceReport)(v6, v5);
  v53 = v52;
  if ( v52 )
  {
    if ( ((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v52 + 16i64))(v52) & 0xFF00) == 512
      && (*(_DWORD *)(*(_QWORD *)(v53 + 24) + 28i64) & (v60 & 0x10 | ((v60 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v60 & 0x313) )
    {
      if ( v4 )
        v4->Status = 6;
      return (Scaleform::GFx::Resource *)v53;
    }
    goto LABEL_110;
  }
  v54 = *(_QWORD *)(v66 + 64);
  if ( (char)((*(_DWORD *)(v54 + 208) & 8 | 0x10u) >> 3) < 3 || !*(_QWORD *)(v54 + 272) )
  {
LABEL_110:
    if ( v4 )
      v4->Status = 0;
    return 0i64;
  }
  v55 = &v6->pBindData.pObject->ImportSourceLock.cs;
  v72 = v55;
  EnterCriticalSection(v55);
  v56 = 0i64;
  v57 = v6->pBindData.pObject;
  if ( !v57->ImportSourceMovies.Data.Size )
  {
LABEL_109:
    LeaveCriticalSection(v55);
    goto LABEL_110;
  }
  while ( 1 )
  {
    v58 = v57->ImportSourceMovies.Data.Data[v56].pObject;
    if ( v58 )
    {
      v59 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, const char *, _QWORD, Scaleform::GFx::MovieDefImpl::SearchInfo *))v58->vfptr[7].__vecDelDtor)(
              v58,
              v5,
              v60,
              v4);
      if ( v59 )
        break;
    }
    ++v56;
    v57 = v6->pBindData.pObject;
    if ( v56 >= v57->ImportSourceMovies.Data.Size )
      goto LABEL_109;
  }
  LeaveCriticalSection(v55);
  return (Scaleform::GFx::Resource *)v59;
}

// File Line: 2882
// RVA: 0x8C9510
void __fastcall Scaleform::GFx::GFxInitImportActions::Execute(Scaleform::GFx::GFxInitImportActions *this, Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::DisplayObjContainer *v2; // rsi
  Scaleform::GFx::GFxInitImportActions *v3; // rbx
  __int64 v4; // rbp
  unsigned __int64 v5; // rdi
  __int64 v6; // rdi

  v2 = m;
  v3 = this;
  v4 = *(_QWORD *)(((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))m->vfptr[66].__vecDelDtor)(m) + 104);
  v5 = v3->ImportIndex;
  EnterCriticalSection((LPCRITICAL_SECTION)(v4 + 152));
  if ( v5 < *(_QWORD *)(v4 + 136) )
  {
    v6 = *(_QWORD *)(*(_QWORD *)(v4 + 128) + 8 * v5);
    LeaveCriticalSection((LPCRITICAL_SECTION)(v4 + 152));
    if ( v6 )
    {
      if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 104) + 24i64) + 64i64) + 488i64) > 0 )
        v2->vfptr[119].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, v6);
    }
  }
  else
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)(v4 + 152));
  }
}

