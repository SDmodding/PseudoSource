// File Line: 65
// RVA: 0x8A39D0
void __fastcall Scaleform::GFx::DataAllocator::~DataAllocator(Scaleform::GFx::DataAllocator *this)
{
  Scaleform::GFx::DataAllocator::Block *pNext; // rdi

  if ( this->pAllocations )
  {
    do
    {
      pNext = this->pAllocations->pNext;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pAllocations);
      this->pAllocations = pNext;
    }
    while ( pNext );
  }
}

// File Line: 75
// RVA: 0x8EF230
char *__fastcall Scaleform::GFx::DataAllocator::OverflowAlloc(
        Scaleform::GFx::DataAllocator *this,
        unsigned __int64 bytes)
{
  Scaleform::GFx::DataAllocator::Block *v4; // rax
  char *result; // rax
  char *v6; // rax

  if ( bytes > 0xFF8 )
  {
    v4 = (Scaleform::GFx::DataAllocator::Block *)this->pHeap->vfptr->Alloc(this->pHeap, bytes + 8, 0i64);
    if ( v4 )
    {
      v4->pNext = this->pAllocations;
      this->pAllocations = v4;
      return (char *)&v4[1];
    }
    return 0i64;
  }
  if ( bytes > this->BytesLeft )
  {
    v6 = (char *)this->pHeap->vfptr->Alloc(this->pHeap, 8184i64, 0i64);
    if ( !v6 )
      return 0i64;
    *(_QWORD *)v6 = this->pAllocations;
    this->pAllocations = (Scaleform::GFx::DataAllocator::Block *)v6;
    this->pCurrent = v6 + 8;
    this->BytesLeft = 8176i64;
  }
  result = this->pCurrent;
  this->BytesLeft -= bytes;
  this->pCurrent = &result[bytes];
  return result;
}

// File Line: 137
// RVA: 0x89AAF0
void __fastcall Scaleform::GFx::MovieDataDef::MovieDataDef(
        Scaleform::GFx::MovieDataDef *this,
        Scaleform::GFx::ResourceKey *creationKey,
        Scaleform::GFx::MovieDataDef::MovieDataType mtype,
        const char *purl,
        Scaleform::MemoryHeap *pargHeap,
        bool debugHeap,
        unsigned __int64 memoryArena)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v11; // rbp
  Scaleform::MemoryHeap *v12; // rsi
  const char *ShortFilename; // rax
  bool v14; // cf
  Scaleform::GFx::MovieDataDef::LoadTaskData *v15; // rax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v16; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx
  int v18; // [rsp+40h] [rbp-58h] BYREF
  __int64 v19; // [rsp+48h] [rbp-50h]
  __int64 v20; // [rsp+50h] [rbp-48h]
  __int64 v21; // [rsp+58h] [rbp-40h]
  __int64 v22; // [rsp+60h] [rbp-38h]
  __int64 v23; // [rsp+68h] [rbp-30h]
  __int64 v24; // [rsp+70h] [rbp-28h]
  unsigned __int64 v25; // [rsp+78h] [rbp-20h]
  Scaleform::String v26; // [rsp+A8h] [rbp+10h] BYREF

  this->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  this->RefCount.Value = 1;
  v11 = 0i64;
  this->pLib = 0i64;
  this->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->Id.Id = 0x40000;
  this->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::TimelineDef::`vftable;
  this->Scaleform::GFx::ResourceReport::vfptr = (Scaleform::GFx::ResourceReportVtbl *)&Scaleform::GFx::ResourceReport::`vftable;
  this->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::MovieDataDef::`vftable{for `Scaleform::GFx::TimelineDef};
  this->Scaleform::GFx::ResourceReport::vfptr = (Scaleform::GFx::ResourceReportVtbl *)&Scaleform::GFx::MovieDataDef::`vftable{for `Scaleform::GFx::ResourceReport};
  if ( creationKey->pKeyInterface )
    creationKey->pKeyInterface->vfptr->AddRef(creationKey->pKeyInterface, creationKey->hKeyData);
  this->mResourceKey.pKeyInterface = creationKey->pKeyInterface;
  this->mResourceKey.hKeyData = creationKey->hKeyData;
  this->MovieType = mtype;
  this->pData.pObject = 0i64;
  v12 = pargHeap;
  if ( !pargHeap )
  {
    ShortFilename = Scaleform::GetShortFilename(purl);
    Scaleform::String::String(&v26, "MovieData \"", ShortFilename, "\"");
    v14 = debugHeap;
    debugHeap = -debugHeap;
    v19 = 16i64;
    v22 = -1i64;
    v23 = 0i64;
    v18 = (v14 ? 0x1000 : 0) | 4;
    v20 = 0x2000i64;
    v21 = 0i64;
    v24 = 4i64;
    v25 = memoryArena;
    v12 = (Scaleform::MemoryHeap *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, unsigned __int64, int *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
                                     Scaleform::Memory::pGlobalHeap,
                                     (v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                                     &v18);
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  v15 = (Scaleform::GFx::MovieDataDef::LoadTaskData *)v12->vfptr->Alloc(v12, 528ui64, 0i64);
  if ( v15 )
  {
    Scaleform::GFx::MovieDataDef::LoadTaskData::LoadTaskData(v15, this, purl, v12);
    v11 = v16;
  }
  pObject = (Scaleform::Render::RenderBuffer *)this->pData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pData.pObject = v11;
  if ( !pargHeap )
    Scaleform::MemoryHeap::ReleaseOnFree((ANTLR3_COMMON_TOKEN_struct *)v12, (__int64)v11);
}

// File Line: 163
// RVA: 0x8A6260
void __fastcall Scaleform::GFx::MovieDataDef::~MovieDataDef(Scaleform::GFx::MovieDataDef *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rax
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // rcx

  this->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::MovieDataDef::`vftable{for `Scaleform::GFx::TimelineDef};
  this->Scaleform::GFx::ResourceReport::vfptr = (Scaleform::GFx::ResourceReportVtbl *)&Scaleform::GFx::MovieDataDef::`vftable{for `Scaleform::GFx::ResourceReport};
  pObject = this->pData.pObject;
  if ( pObject->LoadState <= LS_LoadingFrames )
    pObject->LoadingCanceled = 1;
  v3 = (Scaleform::Render::RenderBuffer *)this->pData.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  pKeyInterface = this->mResourceKey.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->vfptr->Release(pKeyInterface, this->mResourceKey.hKeyData);
  this->Scaleform::GFx::ResourceReport::vfptr = (Scaleform::GFx::ResourceReportVtbl *)&Scaleform::GFx::ResourceReport::`vftable;
  this->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 174
// RVA: 0x8A3A30
void __fastcall Scaleform::GFx::MovieDataDef::DefBindingData::~DefBindingData(
        Scaleform::GFx::MovieDataDef::DefBindingData *this)
{
  Scaleform::GFx::FrameBindData *volatile Value; // rax
  Scaleform::GFx::ImportData *volatile v3; // r14
  unsigned __int64 Size; // rsi
  unsigned __int64 *i; // rdi
  Scaleform::GFx::ResourceDataNode *volatile v6; // rdx
  Scaleform::GFx::FontDataUseNode *volatile v7; // rdx
  Scaleform::Render::RenderBuffer *pObject; // rcx

  Value = this->pFrameData.Value;
  for ( this->pFrameData.Value = 0i64; Value; Value = Value->pNextFrame.Value )
    ;
  while ( this->pImports.Value )
  {
    v3 = this->pImports.Value;
    this->pImports.Value = v3->pNext.Value;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v3->SourceUrl.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    Size = v3->Imports.Data.Size;
    for ( i = (unsigned __int64 *)&v3->Imports.Data.Data[Size - 1]; Size; --Size )
    {
      if ( !_InterlockedDecrement((volatile signed __int32 *)((*i & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      i -= 2;
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->Imports.Data.Data);
  }
  while ( this->pResourceNodes.Value )
  {
    v6 = this->pResourceNodes.Value;
    this->pResourceNodes.Value = v6->pNext.Value;
    if ( v6->Data.pInterface )
      v6->Data.pInterface->vfptr->Release(v6->Data.pInterface, v6->Data.hData);
  }
  while ( this->pFonts.Value )
  {
    v7 = this->pFonts.Value;
    this->pFonts.Value = v7->pNext.Value;
    pObject = (Scaleform::Render::RenderBuffer *)v7->pFontData.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
  }
}

// File Line: 214
// RVA: 0x913CA0
char __fastcall Scaleform::GFx::MovieDataDef::TranslateFrameString(
        Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *namedFrames,
        const char *label,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  const char *v5; // rbx
  char v7; // r10
  char v8; // r9
  int v9; // ecx
  Scaleform::String *v11; // rax
  char CaseInsensitive; // bl
  Scaleform::String v13; // [rsp+20h] [rbp-18h] BYREF
  __int64 v14; // [rsp+28h] [rbp-10h]
  char *tailptr; // [rsp+48h] [rbp+10h] BYREF

  v14 = -2i64;
  v5 = label;
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
        if ( (((v7 - 43) & 0xFD) != 0 || v8) && v7 != 32 && v7 != 9 )
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
    v9 = (int)Scaleform::SFstrtod(v5, &tailptr);
    if ( tailptr != v5 && !*tailptr )
    {
      *frameNumber = v9 - 1;
      return 1;
    }
    return 0;
  }
$translate_frame_label:
  Scaleform::String::String(&v13, v5);
  CaseInsensitive = Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetCaseInsensitive(
                      namedFrames,
                      v11,
                      frameNumber);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v13.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return CaseInsensitive;
}

// File Line: 274
// RVA: 0x914090
Scaleform::String *__fastcall Scaleform::GFx::MovieDataDef::TranslateNumberToFrameString(
        Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *namedFrames,
        unsigned int frameNumber,
        unsigned int *exactFrameNumberForLabel)
{
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  unsigned int v5; // r10d
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v9; // rcx
  unsigned __int64 v10; // rax
  Scaleform::String *v11; // rbx
  unsigned __int64 v12; // rcx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v13; // r8
  unsigned __int64 v14; // rdx
  unsigned int v15; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v16; // rax
  Scaleform::String *result; // rax
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v18; // [rsp+0h] [rbp-18h]
  unsigned __int64 v19; // [rsp+8h] [rbp-10h]

  pTable = namedFrames->mHash.pTable;
  v5 = 0;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v9 = pTable + 1;
    v10 = 0i64;
    do
    {
      if ( v9->EntryCount != -2i64 )
        break;
      ++v10;
      v9 += 2;
    }
    while ( v10 <= SizeMask );
    v18 = namedFrames;
    v19 = v10;
  }
  else
  {
    v18 = 0i64;
    v19 = 0i64;
  }
  v11 = 0i64;
  v12 = v19;
  while ( v18 )
  {
    v13 = v18->mHash.pTable;
    if ( !v18->mHash.pTable )
      break;
    v14 = v13->SizeMask;
    if ( (__int64)v12 > (__int64)v14 )
      break;
    v15 = v13[2 * v12 + 2].SizeMask;
    if ( frameNumber >= v15 && v15 >= v5 )
    {
      v5 = v13[2 * v12 + 2].SizeMask;
      v11 = (Scaleform::String *)&v13[2 * v12 + 2];
    }
    if ( ++v12 <= v14 )
    {
      v16 = &v13[2 * v12 + 1];
      do
      {
        if ( v16->EntryCount != -2i64 )
          break;
        ++v12;
        v16 += 2;
      }
      while ( v12 <= v14 );
    }
  }
  result = v11;
  if ( exactFrameNumberForLabel )
    *exactFrameNumberForLabel = v5;
  return result;
}

// File Line: 302
// RVA: 0x899670
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::LoadTaskData(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::MovieDataDef *pdataDef,
        const char *purl,
        Scaleform::MemoryHeap *pheap)
{
  __int64 v7; // r13
  Scaleform::GFx::PathAllocator *v8; // rax
  char v9; // r12
  char v10; // bl
  Scaleform::GFx::LoadUpdateSync *v11; // rax
  Scaleform::GFx::LoadUpdateSync *v12; // rax
  Scaleform::GFx::LoadUpdateSync *v13; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  __int64 v15; // rax
  __int64 v16; // rsi
  Scaleform::GFx::TextFieldDef *v17; // rax
  __int64 v18; // rax
  __int64 v19; // rax
  Scaleform::GFx::Resource *v20; // r15
  Scaleform::GFx::ShapeDataBase *v21; // rbx
  __int64 v22; // rax
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceLibBase *v24; // rcx
  __int64 v25; // rcx
  __int64 v26; // rcx
  char v27; // [rsp+20h] [rbp-49h]
  Scaleform::GFx::Resource *pres; // [rsp+28h] [rbp-41h]
  Scaleform::GFx::SwfShapeCharacterDef *v29; // [rsp+30h] [rbp-39h]
  Scaleform::GFx::ResourceId v30; // [rsp+38h] [rbp-31h] BYREF
  Scaleform::GFx::ResourceId v31[2]; // [rsp+40h] [rbp-29h] BYREF
  Scaleform::GFx::ResourceId v32; // [rsp+48h] [rbp-21h] BYREF
  Scaleform::String url; // [rsp+50h] [rbp-19h] BYREF
  Scaleform::GFx::ShapeDataBase *v34; // [rsp+58h] [rbp-11h]
  __int64 v35; // [rsp+60h] [rbp-9h]
  __int64 v36; // [rsp+68h] [rbp-1h]
  Scaleform::GFx::Resource *v37; // [rsp+70h] [rbp+7h]
  __int64 v38; // [rsp+78h] [rbp+Fh]
  __int64 v39; // [rsp+80h] [rbp+17h]
  __int64 rid; // [rsp+E8h] [rbp+7Fh] BYREF

  v36 = -2i64;
  v7 = 0i64;
  v27 = 0;
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
  Scaleform::GFx::MovieHeaderData::MovieHeaderData(&this->Header);
  this->pFrameUpdate.pObject = 0i64;
  this->BindData.pFrameData.Value = 0i64;
  this->BindData.pFrameDataLast = 0i64;
  this->BindData.pImports.Value = 0i64;
  this->BindData.pImportsLast = 0i64;
  this->BindData.pFonts.Value = 0i64;
  this->BindData.pFontsLast = 0i64;
  this->BindData.pResourceNodes.Value = 0i64;
  this->BindData.pResourceNodesLast = 0i64;
  Scaleform::Lock::Lock(&this->ResourceLock, 0);
  this->pExtMovieDef.pObject = 0i64;
  this->Resources.mHash.pTable = 0i64;
  this->Exports.mHash.pTable = 0i64;
  this->InvExports.mHash.pTable = 0i64;
  Scaleform::Lock::Lock(&this->PlaylistLock, 0);
  this->Playlist.Data.Data = 0i64;
  this->Playlist.Data.Size = 0i64;
  this->Playlist.Data.Policy.Capacity = 0i64;
  this->InitActionList.Data.Data = 0i64;
  this->InitActionList.Data.Size = 0i64;
  this->InitActionList.Data.Policy.Capacity = 0i64;
  this->NamedFrames.mHash.pTable = 0i64;
  this->GradientIdGenerator.Id = 327680;
  this->Scenes.pObject = 0i64;
  this->Scenes.Owner = 1;
  this->FileAttributes = 0;
  this->pMetadata = 0i64;
  this->MetadataSize = 0;
  v8 = (Scaleform::GFx::PathAllocator *)this->pHeap->vfptr->Alloc(this->pHeap, 24i64, 0i64);
  if ( v8 )
  {
    v8->pFirstPage = 0i64;
    v8->pLastPage = 0i64;
    *(_DWORD *)&v8->FreeBytes = 0x20000000;
  }
  else
  {
    v8 = 0i64;
  }
  this->pPathAllocator = v8;
  this->LoadingCanceled = 0;
  *(_QWORD *)&this->LoadState = 0i64;
  this->TagCount = 0;
  this->ResIndexCounter = 0;
  this->InitActionsCnt = 0;
  if ( pdataDef->MovieType == MT_Image )
  {
    Scaleform::String::String(&url, purl);
    v9 = 1;
    v27 = 1;
    if ( Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, 0i64, 0i64) )
    {
      v10 = 0;
      goto LABEL_9;
    }
  }
  else
  {
    v9 = 0;
  }
  v10 = 1;
LABEL_9:
  if ( (v9 & 1) != 0 )
  {
    v27 = v9 & 0xFE;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v9 &= ~1u;
  }
  if ( v10 )
  {
    v11 = (Scaleform::GFx::LoadUpdateSync *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              72i64);
    if ( v11 )
    {
      Scaleform::GFx::LoadUpdateSync::LoadUpdateSync(v11);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    pObject = (Scaleform::Render::RenderBuffer *)this->pFrameUpdate.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFrameUpdate.pObject = v13;
  }
  v15 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(this->pHeap, 96i64);
  v16 = v15;
  if ( v15 )
  {
    *(_QWORD *)v15 = &Scaleform::GFx::Resource::`vftable;
    *(_DWORD *)(v15 + 8) = 1;
    *(_QWORD *)(v15 + 16) = 0i64;
    *(_QWORD *)v15 = &Scaleform::GFx::CharacterDef::`vftable;
    *(_DWORD *)(v15 + 24) = 0x40000;
    *(_QWORD *)v15 = &Scaleform::GFx::TimelineDef::`vftable;
    *(_QWORD *)v15 = &Scaleform::GFx::TimelineIODef::`vftable;
    *(_QWORD *)v15 = &Scaleform::GFx::SpriteDef::`vftable;
    *(_QWORD *)(v15 + 32) = pdataDef;
    *(_QWORD *)(v15 + 40) = 0i64;
    *(_QWORD *)(v15 + 48) = 0i64;
    rid = v15 + 56;
    *(_QWORD *)(v15 + 56) = 0i64;
    *(_QWORD *)(v15 + 64) = 0i64;
    *(_QWORD *)(v15 + 72) = 0i64;
    *(_QWORD *)(v15 + 80) = 0i64;
    *(_BYTE *)(v15 + 88) = 0;
    v9 = v27;
  }
  else
  {
    v16 = 0i64;
  }
  v38 = v16;
  *(_DWORD *)(v16 + 48) = 1;
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,264>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,264>,Scaleform::ArrayDefaultPolicy> *)(v16 + 56),
    1ui64);
  LODWORD(rid) = 65537;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
    this,
    (Scaleform::GFx::ResourceId)&rid,
    (Scaleform::GFx::Resource *)v16);
  v17 = (Scaleform::GFx::TextFieldDef *)this->pHeap->vfptr->Alloc(this->pHeap, 144i64, 0i64);
  if ( v17 )
  {
    Scaleform::GFx::TextFieldDef::TextFieldDef(v17);
    v7 = v18;
  }
  v35 = v7;
  *(_WORD *)(v7 + 128) |= 0x800u;
  *(_DWORD *)(v7 + 84) = -16777216;
  *(_DWORD *)(v7 + 80) = 1131413504;
  *(_WORD *)(v7 + 128) |= 0x528u;
  v32.Id = 65538;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
    this,
    (Scaleform::GFx::ResourceId)&v32,
    (Scaleform::GFx::Resource *)v7);
  v19 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(this->pHeap, 96i64);
  v20 = (Scaleform::GFx::Resource *)v19;
  if ( v19 )
  {
    *(_QWORD *)v19 = &Scaleform::GFx::Resource::`vftable;
    *(_DWORD *)(v19 + 8) = 1;
    *(_QWORD *)(v19 + 16) = 0i64;
    *(_QWORD *)v19 = &Scaleform::GFx::CharacterDef::`vftable;
    *(_DWORD *)(v19 + 24) = 0x40000;
    *(_QWORD *)v19 = &Scaleform::GFx::ButtonDef::`vftable;
    *(_QWORD *)(v19 + 32) = 0i64;
    *(_QWORD *)(v19 + 40) = 0i64;
    *(_QWORD *)(v19 + 48) = 0i64;
    *(_QWORD *)&v31[0].Id = v19 + 56;
    *(_QWORD *)(v19 + 56) = 0i64;
    *(_QWORD *)(v19 + 64) = 0i64;
    *(_QWORD *)(v19 + 72) = 0i64;
    *(_QWORD *)(v19 + 80) = 0i64;
    *(_BYTE *)(v19 + 88) = 0;
    v9 = v27;
  }
  else
  {
    v20 = 0i64;
  }
  v37 = v20;
  v31[0].Id = 65539;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this, (Scaleform::GFx::ResourceId)v31, v20);
  v29 = (Scaleform::GFx::SwfShapeCharacterDef *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                                  this->pHeap,
                                                  48i64);
  if ( v29 )
  {
    v21 = (Scaleform::GFx::ShapeDataBase *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                             this->pHeap,
                                             32i64);
    if ( v21 )
    {
      v21->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
      v21->RefCount = 1;
      v21->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
      v21->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
      v21->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
      v21->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
      v21->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ShapeDataBase::`vftable;
      v21->Flags = 0;
      v21->Paths = (const char *)&unk_1418A79F4;
      v21->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ConstShapeNoStyles::`vftable;
    }
    else
    {
      v21 = 0i64;
    }
    v34 = v21;
    v9 |= 2u;
    Scaleform::GFx::SwfShapeCharacterDef::SwfShapeCharacterDef(v29, v21);
    pres = (Scaleform::GFx::Resource *)v22;
  }
  else
  {
    v22 = 0i64;
    pres = 0i64;
    v21 = v34;
  }
  v39 = v22;
  if ( (v9 & 2) != 0 && v21 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v21);
  v30.Id = 65540;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this, (Scaleform::GFx::ResourceId)&v30, pres);
  if ( pres && !_InterlockedDecrement(&pres->RefCount.Value) )
  {
    pLib = pres->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pres);
      pres->pLib = 0i64;
    }
    pres->vfptr->__vecDelDtor(pres, 1u);
  }
  if ( v20 && !_InterlockedDecrement(&v20->RefCount.Value) )
  {
    v24 = v20->pLib;
    if ( v24 )
    {
      v24->vfptr[1].__vecDelDtor(v24, (unsigned int)v20);
      v20->pLib = 0i64;
    }
    v20->vfptr->__vecDelDtor(v20, 1u);
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)(v7 + 8)) )
  {
    v25 = *(_QWORD *)(v7 + 16);
    if ( v25 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v25 + 8i64))(v25, v7);
      *(_QWORD *)(v7 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, __int64))v7)(v7, 1i64);
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)(v16 + 8)) )
  {
    v26 = *(_QWORD *)(v16 + 16);
    if ( v26 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v26 + 8i64))(v26, v16);
      *(_QWORD *)(v16 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, __int64))v16)(v16, 1i64);
  }
}

// File Line: 351
// RVA: 0x8A5560
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::~LoadTaskData(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v2; // rbx
  unsigned int v3; // r15d
  __int64 v4; // rdi
  Scaleform::GFx::TimelineDef::Frame *v5; // rdi
  unsigned int i; // esi
  Scaleform::GFx::ExecuteTag *v7; // rcx
  unsigned int v8; // r15d
  __int64 v9; // rdi
  Scaleform::GFx::TimelineDef::Frame *v10; // rdi
  unsigned int j; // esi
  Scaleform::GFx::ExecuteTag *v12; // rcx
  Scaleform::GFx::PathAllocator *pPathAllocator; // rsi
  Scaleform::GFx::PathAllocator::Page *pFirstPage; // rdx
  Scaleform::GFx::PathAllocator::Page *pNext; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *pObject; // rbx
  Scaleform::StringHashLH<Scaleform::GFx::ResourceHandle,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_Exports; // rdi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // rax
  __int64 v19; // r12
  __int64 v20; // r13
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v21; // r15
  char *v22; // rsi
  __int64 v23; // rdi
  __int64 v24; // rcx
  Scaleform::HashUncachedLH<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp,2> *p_Resources; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *v26; // rax
  __int64 v27; // r15
  __int64 v28; // r13
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *v29; // rsi
  unsigned __int64 *p_SizeMask; // rdi
  unsigned __int64 v31; // rdi
  __int64 v32; // rcx
  Scaleform::GFx::MovieDef *v33; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::Render::RenderBuffer *v35; // rcx
  Scaleform::MemoryHeap *v36; // rcx
  Scaleform::GFx::DataAllocator::Block *v37; // rbx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieDataDef::LoadTaskData::`vftable;
  v2 = 0i64;
  if ( this->LoadState < LS_LoadFinished )
  {
    v2 = this;
    EnterCriticalSection(&this->ResourceLock.cs);
  }
  v3 = 0;
  if ( this->Playlist.Data.Size )
  {
    v4 = 0i64;
    do
    {
      v5 = &this->Playlist.Data.Data[v4];
      for ( i = 0; i < v5->TagCount; ++i )
      {
        v7 = v5->pTagPtrList[i];
        v7->vfptr->__vecDelDtor(v7, 0i64);
      }
      v5->pTagPtrList = 0i64;
      v5->TagCount = 0;
      v4 = ++v3;
    }
    while ( v3 < this->Playlist.Data.Size );
  }
  v8 = 0;
  if ( this->InitActionList.Data.Size )
  {
    v9 = 0i64;
    do
    {
      v10 = &this->InitActionList.Data.Data[v9];
      for ( j = 0; j < v10->TagCount; ++j )
      {
        v12 = v10->pTagPtrList[j];
        v12->vfptr->__vecDelDtor(v12, 0i64);
      }
      v10->pTagPtrList = 0i64;
      v10->TagCount = 0;
      v9 = ++v8;
    }
    while ( v8 < this->InitActionList.Data.Size );
  }
  pPathAllocator = this->pPathAllocator;
  if ( pPathAllocator )
  {
    pFirstPage = pPathAllocator->pFirstPage;
    if ( pPathAllocator->pFirstPage )
    {
      do
      {
        pNext = pFirstPage->pNext;
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pFirstPage = pNext;
      }
      while ( pNext );
    }
    pPathAllocator->pFirstPage = 0i64;
    pPathAllocator->pLastPage = 0i64;
    pPathAllocator->FreeBytes = 0;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pPathAllocator);
  }
  if ( this->pMetadata )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    this->pMetadata = 0i64;
  }
  if ( v2 )
    LeaveCriticalSection(&v2->ResourceLock.cs);
  pObject = this->Scenes.pObject;
  if ( pObject )
  {
    if ( this->Scenes.Owner )
    {
      this->Scenes.Owner = 0;
      Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::SceneInfo>::DestructArray(
        pObject->Data.Data,
        pObject->Data.Size);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject->Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    this->Scenes.pObject = 0i64;
  }
  this->Scenes.Owner = 0;
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&this->NamedFrames);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->InitActionList.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Playlist.Data.Data);
  Scaleform::Lock::~Lock(&this->PlaylistLock.cs);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Clear(&this->InvExports.mHash);
  p_Exports = &this->Exports;
  pTable = this->Exports.mHash.pTable;
  if ( pTable )
  {
    v19 = 0i64;
    v20 = pTable->SizeMask + 1;
    do
    {
      v21 = p_Exports->mHash.pTable;
      if ( *(unsigned __int64 *)((char *)&p_Exports->mHash.pTable[1].EntryCount + v19) != -2i64 )
      {
        v22 = (char *)&v21[2] + v19;
        if ( !*((_DWORD *)v22 + 2) )
        {
          v23 = *((_QWORD *)v22 + 2);
          if ( v23 && !_InterlockedDecrement((volatile signed __int32 *)(v23 + 8)) )
          {
            v24 = *(_QWORD *)(v23 + 16);
            if ( v24 )
            {
              (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v24 + 8i64))(v24, v23);
              *(_QWORD *)(v23 + 16) = 0i64;
            }
            (**(void (__fastcall ***)(__int64, __int64))v23)(v23, 1i64);
          }
          p_Exports = &this->Exports;
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((*(_QWORD *)v22 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        *(unsigned __int64 *)((char *)&v21[1].EntryCount + v19) = -2i64;
      }
      v19 += 40i64;
      --v20;
    }
    while ( v20 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_Exports->mHash.pTable);
    p_Exports->mHash.pTable = 0i64;
  }
  p_Resources = &this->Resources;
  v26 = this->Resources.mHash.pTable;
  if ( v26 )
  {
    v27 = 0i64;
    v28 = v26->SizeMask + 1;
    do
    {
      v29 = p_Resources->mHash.pTable;
      if ( p_Resources->mHash.pTable[v27 + 1].EntryCount != -2i64 )
      {
        p_SizeMask = &v29[v27 + 1].SizeMask;
        if ( !*((_DWORD *)p_SizeMask + 2) )
        {
          v31 = p_SizeMask[2];
          if ( v31 )
          {
            if ( !_InterlockedDecrement((volatile signed __int32 *)(v31 + 8)) )
            {
              v32 = *(_QWORD *)(v31 + 16);
              if ( v32 )
              {
                (*(void (__fastcall **)(__int64, unsigned __int64))(*(_QWORD *)v32 + 8i64))(v32, v31);
                *(_QWORD *)(v31 + 16) = 0i64;
              }
              (**(void (__fastcall ***)(unsigned __int64, __int64))v31)(v31, 1i64);
            }
          }
        }
        v29[v27 + 1].EntryCount = -2i64;
      }
      v27 += 2i64;
      --v28;
    }
    while ( v28 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_Resources->mHash.pTable);
    p_Resources->mHash.pTable = 0i64;
  }
  v33 = this->pExtMovieDef.pObject;
  if ( v33 && !_InterlockedDecrement(&v33->RefCount.Value) )
  {
    pLib = v33->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v33);
      v33->pLib = 0i64;
    }
    v33->Scaleform::GFx::Resource::vfptr->__vecDelDtor(v33, 1u);
  }
  Scaleform::Lock::~Lock(&this->ResourceLock.cs);
  Scaleform::GFx::MovieDataDef::DefBindingData::~DefBindingData(&this->BindData);
  v35 = (Scaleform::Render::RenderBuffer *)this->pFrameUpdate.pObject;
  if ( v35 )
    Scaleform::RefCountImpl::Release(v35);
  if ( this->Header.mExporterInfo.CodeOffsets.Data.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->Header.mExporterInfo.SWFName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->Header.mExporterInfo.Prefix.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v36 = this->pImageHeap.pObject;
  if ( v36 )
    v36->vfptr->Release(v36);
  if ( this->TagMemAllocator.pAllocations )
  {
    do
    {
      v37 = this->TagMemAllocator.pAllocations->pNext;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->TagMemAllocator.pAllocations);
      this->TagMemAllocator.pAllocations = v37;
    }
    while ( v37 );
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 391
// RVA: 0x8E40A0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::InitEmptyMovieDef(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::Lock *p_PlaylistLock; // rbx

  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Playlist.Data,
    this->Header.FrameCount);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->InitActionList.Data,
    this->Header.FrameCount);
  this->InitActionsCnt = 0;
  LeaveCriticalSection(&p_PlaylistLock->cs);
  Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(this, this->Header.FrameCount, LS_LoadFinished);
}

// File Line: 412
// RVA: 0x8E4250
bool __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::InitImageFileMovieDef(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int fileLength,
        Scaleform::GFx::ImageResource *pimageResource,
        Scaleform::GFx::ImageCreator *imgCreator,
        Scaleform::Log *plog,
        bool bilinear)
{
  Scaleform::GFx::ImageResource *v7; // rsi
  Scaleform::MemoryHeap *v9; // rax
  Scaleform::Render::Image *v10; // rdi
  Scaleform::GFx::ImageResource *v11; // rax
  Scaleform::GFx::ImageResource *v12; // rax
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ImageShapeCharacterDef *v14; // rax
  __int64 v15; // rax
  __int64 v16; // r12
  Scaleform::GFx::DataAllocator::Block *v17; // rax
  Scaleform::GFx::DataAllocator::Block *v18; // rax
  Scaleform::GFx::DataAllocator::Block *v19; // r13
  _OWORD *v20; // rax
  __int64 v21; // rcx
  int v23; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::MemoryHeap *v24; // [rsp+28h] [rbp-D8h]
  int v25; // [rsp+30h] [rbp-D0h]
  int v26; // [rsp+34h] [rbp-CCh]
  __int64 v27; // [rsp+38h] [rbp-C8h]
  __int64 v28; // [rsp+40h] [rbp-C0h]
  __int64 v29; // [rsp+48h] [rbp-B8h]
  __int64 v30; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::CharPosInfo __that; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::Lock *p_PlaylistLock; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::DataAllocator::Block *v33; // [rsp+D8h] [rbp-28h]
  __int64 v34; // [rsp+E0h] [rbp-20h]
  __int64 v35; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::DataAllocator::Block *v36; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::ImageResource *v37; // [rsp+F8h] [rbp-8h]
  Scaleform::Render::Image *v38; // [rsp+100h] [rbp+0h]
  Scaleform::Render::Cxform v39; // [rsp+110h] [rbp+10h] BYREF
  Scaleform::GFx::DataAllocator::Block *v40; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::ResourceId rid; // [rsp+188h] [rbp+88h] BYREF
  Scaleform::GFx::ImageResource *v42; // [rsp+190h] [rbp+90h] BYREF
  Scaleform::GFx::ImageShapeCharacterDef *v43; // [rsp+198h] [rbp+98h] BYREF

  v35 = -2i64;
  v7 = pimageResource;
  this->Header.FileLength = fileLength;
  if ( !imgCreator
    || ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))pimageResource->pImage->vfptr[3].__vecDelDtor)(pimageResource->pImage) )
  {
    LODWORD(v42) = 0;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this, (Scaleform::GFx::ResourceId *)&v42, v7);
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
    v10 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::Render::ImageBase *))imgCreator->vfptr[4].__vecDelDtor)(
                                        imgCreator,
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
      Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this, &rid, v7);
      if ( v7 && !_InterlockedDecrement(&v7->RefCount.Value) )
      {
        pLib = v7->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v7);
          v7->pLib = 0i64;
        }
        v7->vfptr->__vecDelDtor(v7, 1u);
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
    v14 = (Scaleform::GFx::ImageShapeCharacterDef *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                                      this->pHeap,
                                                      48i64);
    v43 = v14;
    if ( v14 )
    {
      Scaleform::GFx::ImageShapeCharacterDef::ImageShapeCharacterDef(v14, v7, imgCreator, bilinear);
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    v34 = v16;
    *(_DWORD *)(v16 + 24) = 1;
    LODWORD(v43) = 1;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
      this,
      (Scaleform::GFx::ResourceId *)&v43,
      (Scaleform::GFx::Resource *)v16);
    p_PlaylistLock = &this->PlaylistLock;
    EnterCriticalSection(&this->PlaylistLock.cs);
    Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->Playlist.Data,
      this->Header.FrameCount);
    Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->InitActionList.Data,
      this->Header.FrameCount);
    this->InitActionsCnt = 0;
    v17 = (Scaleform::GFx::DataAllocator::Block *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))this->TagMemAllocator.pHeap->vfptr->Alloc)(
                                                    this->TagMemAllocator.pHeap,
                                                    160i64,
                                                    16i64);
    v40 = v17;
    if ( v17 )
    {
      v17->pNext = this->TagMemAllocator.pAllocations;
      this->TagMemAllocator.pAllocations = v17;
      v18 = v17 + 2;
      if ( v18 )
      {
        v19 = v18 + 2;
        v36 = v18 + 2;
        v33 = v18 + 2;
        if ( v18 != (Scaleform::GFx::DataAllocator::Block *)-16i64 )
          Scaleform::GFx::GFxPlaceObjectUnpacked::GFxPlaceObjectUnpacked((Scaleform::GFx::GFxPlaceObjectUnpacked *)&v18[2]);
        Scaleform::Render::Cxform::Cxform(&v39);
        *(_OWORD *)&__that.ColorTransform.M[0][0] = *v20;
        *(_OWORD *)&__that.ColorTransform.M[1][0] = v20[1];
        *(_OWORD *)&__that.Matrix_1.M[0][0] = _xmm;
        *(__m128 *)&__that.Matrix_1.M[1][0] = _xmm;
        __that.pFilters.pObject = 0i64;
        *(_WORD *)&__that.BlendMode = 256;
        __that.Ratio = 0.0;
        *(_DWORD *)&__that.ClipDepth = 0x40000;
        __that.Depth = 1;
        __that.CharacterId.Id = 1;
        __that.ClassName = 0i64;
        Scaleform::GFx::CharPosInfo::operator=((Scaleform::GFx::CharPosInfo *)&v19[2], &__that);
        v40[2].pNext = v19;
        this->Playlist.Data.Data->pTagPtrList = (Scaleform::GFx::ExecuteTag **)&v40[2];
        this->Playlist.Data.Data->TagCount = 1;
        if ( __that.pFilters.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)__that.pFilters.pObject);
      }
    }
    LeaveCriticalSection(&this->PlaylistLock.cs);
    if ( !_InterlockedDecrement((volatile signed __int32 *)(v16 + 8)) )
    {
      v21 = *(_QWORD *)(v16 + 16);
      if ( v21 )
      {
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v21 + 8i64))(v21, v16);
        *(_QWORD *)(v16 + 16) = 0i64;
      }
      (**(void (__fastcall ***)(__int64, __int64))v16)(v16, 1i64);
    }
  }
  Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(this, this->Header.FrameCount, LS_LoadFinished);
  return v7 != 0i64;
}

// File Line: 497
// RVA: 0x8D9CA0
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetImageHeap(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::MemoryHeap *pHeap; // rcx
  __int64 v3; // rax
  Scaleform::MemoryHeap *pObject; // rcx
  Scaleform::MemoryHeap *v5; // rdi
  int v7; // [rsp+20h] [rbp-48h] BYREF
  __int64 v8; // [rsp+28h] [rbp-40h]
  __int64 v9; // [rsp+30h] [rbp-38h]
  __int64 v10; // [rsp+38h] [rbp-30h]
  __int64 v11; // [rsp+40h] [rbp-28h]
  __int64 v12; // [rsp+48h] [rbp-20h]
  __int64 v13; // [rsp+50h] [rbp-18h]
  __int64 v14; // [rsp+58h] [rbp-10h]

  if ( this->pImageHeap.pObject )
    return this->pImageHeap.pObject;
  pHeap = this->pHeap;
  v14 = 0i64;
  v7 = 4;
  v8 = 32i64;
  v9 = 4096i64;
  v10 = 0i64;
  v11 = -1i64;
  v12 = 0i64;
  v13 = 5i64;
  v3 = (*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, const char *, int *))&pHeap->vfptr->gap8[24])(
         pHeap,
         "_Images",
         &v7);
  pObject = this->pImageHeap.pObject;
  v5 = (Scaleform::MemoryHeap *)v3;
  if ( pObject )
    pObject->vfptr->Release(pObject);
  this->pImageHeap.pObject = v5;
  return v5;
}

// File Line: 525
// RVA: 0x8F8200
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::Read(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::LoadProcess *plp,
        Scaleform::GFx::MovieBindProcess *pbp)
{
  Scaleform::GFx::MovieBindProcess *v3; // rdi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbp
  Scaleform::Lock *p_PlaylistLock; // rbx
  signed int v8; // ebx
  char v9; // si
  signed int v10; // r14d
  __int64 v11; // r13
  signed int v12; // ebx
  Scaleform::GFx::LoadStates *pObject; // r14
  Scaleform::GFx::ProgressHandler *v14; // r14
  int TagDataOffset; // esi
  int TagOffset; // edi
  Scaleform::GFx::TagType TagType; // ebx
  void (__fastcall *v18)(Scaleform::GFx::LoadProcess *, Scaleform::GFx::TagInfo *); // r8
  __int64 v19; // rax
  signed int v20; // ebx
  signed int FilePos; // edx
  unsigned int DataSize; // eax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v23; // rcx
  __int64 LoadState; // rdx
  signed int v25; // [rsp+20h] [rbp-88h]
  Scaleform::GFx::TagInfo pTagInfo; // [rsp+38h] [rbp-70h] BYREF
  Scaleform::String v27; // [rsp+48h] [rbp-60h] BYREF
  Scaleform::GFx::TagType v28; // [rsp+50h] [rbp-58h]
  int v29; // [rsp+54h] [rbp-54h]
  int v30; // [rsp+58h] [rbp-50h]
  int v31; // [rsp+5Ch] [rbp-4Ch]
  char v32; // [rsp+B0h] [rbp+8h]
  int TagLength; // [rsp+B8h] [rbp+10h]
  signed int v35; // [rsp+C8h] [rbp+20h]

  v3 = pbp;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)plp->pAltStream;
  if ( !pAltStream )
    pAltStream = &plp->ProcessInfo;
  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Playlist.Data,
    this->Header.FrameCount);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->InitActionList.Data,
    this->Header.FrameCount);
  LeaveCriticalSection(&p_PlaylistLock->cs);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    &pAltStream->Stream,
    "Note: SWF Frame Rate = %f, Frames = %d\n");
  this->TagCount = 0;
  v8 = 0;
  v9 = 0;
  v32 = 0;
  v10 = this->Header.FileLength / 0x1E;
  if ( v10 < 0x2000 )
    v10 = 0x2000;
  v25 = v10;
  if ( pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize >= plp->ProcessInfo.FileEndPos )
  {
LABEL_45:
    LoadState = plp->LoadState;
    if ( plp->FrameTags[LoadState].Data.Size || !(_DWORD)LoadState && plp->InitActionTags.Data.Size )
    {
      Scaleform::GFx::MovieDataDef::LoadTaskData::FinishLoadingFrame(this, plp, 1);
      if ( v3 )
        Scaleform::GFx::MovieBindProcess::BindNextFrame(v3);
    }
    else
    {
      Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(this, this->LoadingFrame, LS_LoadFinished);
    }
    return;
  }
  while ( !this->LoadingCanceled )
  {
    v11 = (unsigned int)Scaleform::GFx::Stream::OpenTag(&pAltStream->Stream, &pTagInfo);
    TagLength = pTagInfo.TagLength;
    v12 = pTagInfo.TagLength + v8;
    v35 = v12;
    if ( v9 && (this->LoadingFrame == 1 || v12 > v10 || pTagInfo.TagLength > 0x2000) )
    {
      Scaleform::WaitCondition::NotifyAll(&this->pFrameUpdate.pObject->WC);
      v32 = 0;
      v35 = 0;
      TagLength = pTagInfo.TagLength;
    }
    pObject = plp->pLoadStates.pObject;
    if ( pObject->pProgressHandler.pObject )
    {
      v14 = pObject->pProgressHandler.pObject;
      TagDataOffset = pTagInfo.TagDataOffset;
      TagOffset = pTagInfo.TagOffset;
      TagType = pTagInfo.TagType;
      Scaleform::String::String(&v27, &this->FileURL);
      v28 = TagType;
      v29 = TagOffset;
      v30 = TagLength;
      v31 = TagDataOffset;
      ((void (__fastcall *)(Scaleform::GFx::ProgressHandler *, Scaleform::String *, _QWORD))v14->vfptr[2].__vecDelDtor)(
        v14,
        &v27,
        0i64);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v27.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v3 = pbp;
    }
    if ( (_DWORD)v11 != 1 )
    {
      if ( (unsigned int)v11 >= 0x5C )
      {
        v19 = (unsigned int)(v11 - 1000);
        if ( (unsigned int)v19 > 9 )
          goto LABEL_23;
        v18 = Scaleform::GFx::GFx_GFX_TagLoaderTable[v19];
      }
      else
      {
        v18 = Scaleform::GFx::SWF_TagLoaderTable[v11];
      }
      if ( !v18 )
      {
LABEL_23:
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          &pAltStream->Stream,
          "*** no tag loader for type %d\n");
        goto LABEL_24;
      }
      v18(plp, &pTagInfo);
    }
LABEL_24:
    v20 = pAltStream->Stream.TagStack[--pAltStream->Stream.TagStackEntryCount];
    pAltStream->Stream.UnusedBits = 0;
    FilePos = pAltStream->Stream.FilePos;
    DataSize = pAltStream->Stream.DataSize;
    if ( v20 < (int)(FilePos - DataSize) || v20 >= FilePos )
    {
      if ( (pAltStream->Stream.ResyncFile || pAltStream->Stream.Pos + FilePos - DataSize != v20)
        && ((int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))pAltStream->Stream.pInput.pObject->vfptr[14].__vecDelDtor)(
             pAltStream->Stream.pInput.pObject,
             (unsigned int)v20,
             0i64) >= 0 )
      {
        pAltStream->Stream.ResyncFile = 0;
        *(_QWORD *)&pAltStream->Stream.Pos = 0i64;
        pAltStream->Stream.FilePos = v20;
      }
    }
    else
    {
      pAltStream->Stream.Pos = v20 + DataSize - FilePos;
    }
    pAltStream->Stream.UnusedBits = 0;
    ++this->TagCount;
    if ( (_DWORD)v11 == 1 )
    {
      if ( !(unsigned __int8)Scaleform::GFx::MovieDataDef::LoadTaskData::FinishLoadingFrame(this, plp, 0) )
        return;
      v9 = 1;
      v32 = 1;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  ShowFrame\n");
      if ( v3 )
        Scaleform::GFx::MovieBindProcess::BindNextFrame(v3);
    }
    else
    {
      if ( !(_DWORD)v11
        && pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize != plp->ProcessInfo.FileEndPos )
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
          &pAltStream->Stream,
          "Loader - Stream-end tag hit, but not at the end of the file yet; stopping for safety");
        goto LABEL_45;
      }
      v9 = v32;
    }
    if ( pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize >= plp->ProcessInfo.FileEndPos )
      goto LABEL_45;
    v8 = v35;
    v10 = v25;
  }
  Scaleform::GFx::LoadProcess::CleanupFrameTags(plp);
  if ( v3 )
  {
    v23 = v3->pBindData.pObject;
    if ( v23 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v23, 3u);
  }
  Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(this, this->LoadingFrame, LS_LoadCanceled);
}

// File Line: 696
// RVA: 0x8CD5D0
__int64 __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::FinishLoadingFrame(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::LoadProcess *plp,
        bool finished)
{
  unsigned __int8 v6; // bp
  Scaleform::GFx::FrameBindData *FrameBindData; // rsi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rcx
  Scaleform::Mutex *p_mMutex; // rbx

  Scaleform::GFx::LoadProcess::CommitFrameTags(plp);
  v6 = 1;
  FrameBindData = Scaleform::GFx::LoadProcess::CreateFrameBindData(plp);
  if ( FrameBindData )
  {
    FrameBindData->Frame = this->LoadingFrame;
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)plp->pAltStream;
    if ( !pAltStream )
      pAltStream = &plp->ProcessInfo;
    FrameBindData->BytesLoaded = pAltStream->Stream.Pos
                               + pAltStream->Stream.FilePos
                               - pAltStream->Stream.DataSize
                               - plp->ProcessInfo.FileStartPos;
  }
  p_mMutex = &this->pFrameUpdate.pObject->mMutex;
  Scaleform::Mutex::DoLock(p_mMutex);
  if ( !FrameBindData )
  {
    this->LoadState = LS_LoadError;
    v6 = 0;
    goto LABEL_12;
  }
  if ( this->BindData.pFrameData.Value )
    this->BindData.pFrameDataLast->pNextFrame.Value = FrameBindData;
  else
    this->BindData.pFrameData.Value = FrameBindData;
  this->BindData.pFrameDataLast = FrameBindData;
  ++this->LoadingFrame;
  if ( finished )
  {
    this->LoadState = LS_LoadFinished;
LABEL_12:
    if ( finished || !v6 )
      Scaleform::WaitCondition::NotifyAll(&this->pFrameUpdate.pObject->WC);
  }
  Scaleform::Mutex::Unlock(p_mMutex);
  return v6;
}

// File Line: 749
// RVA: 0x9174B0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int loadingFrame,
        Scaleform::GFx::MovieDataDef::MovieLoadState loadState)
{
  Scaleform::GFx::LoadUpdateSync *pObject; // rbx

  pObject = this->pFrameUpdate.pObject;
  if ( pObject )
  {
    Scaleform::Mutex::DoLock(&pObject->mMutex);
    this->LoadingFrame = loadingFrame;
    this->LoadState = loadState;
    Scaleform::WaitCondition::NotifyAll(&this->pFrameUpdate.pObject->WC);
    Scaleform::Mutex::Unlock(&pObject->mMutex);
  }
  else
  {
    this->LoadingFrame = loadingFrame;
    this->LoadState = loadState;
  }
}

// File Line: 795
// RVA: 0x91A0B0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::WaitForFrame(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int frame)
{
  Scaleform::Mutex *p_mMutex; // rbx

  if ( this->LoadState <= LS_LoadingFrames && this->LoadingFrame <= frame )
  {
    p_mMutex = &this->pFrameUpdate.pObject->mMutex;
    Scaleform::Mutex::DoLock(p_mMutex);
    while ( this->LoadState <= LS_LoadingFrames )
    {
      if ( this->LoadingFrame > frame )
        break;
      Scaleform::WaitCondition::Wait(&this->pFrameUpdate.pObject->WC, &this->pFrameUpdate.pObject->mMutex, 0xFFFFFFFF);
    }
    Scaleform::Mutex::Unlock(p_mMutex);
  }
}

// File Line: 834
// RVA: 0x8B1EF0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::ResourceId *rid,
        Scaleform::GFx::Resource *pres)
{
  __int64 v6; // rbx
  __int64 v7; // rcx
  int v8; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::Resource *v9; // [rsp+30h] [rbp-28h]
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef key; // [rsp+38h] [rbp-20h] BYREF
  Scaleform::GFx::MovieDataDef::LoadTaskData *v11; // [rsp+60h] [rbp+8h]

  v11 = 0i64;
  if ( this->LoadState < LS_LoadFinished )
  {
    v11 = this;
    EnterCriticalSection(&this->ResourceLock.cs);
  }
  v8 = 0;
  v9 = pres;
  if ( pres )
    _InterlockedExchangeAdd(&pres->RefCount.Value, 1u);
  key.pFirst = rid;
  key.pSecond = (Scaleform::GFx::ResourceHandle *)&v8;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef>(
    &this->Resources.mHash,
    &this->Resources,
    &key,
    rid->Id ^ ((unsigned __int64)rid->Id >> 8));
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
        (**(void (__fastcall ***)(__int64, __int64))v6)(v6, 1i64);
      }
    }
  }
  if ( v11 )
    LeaveCriticalSection(&v11->ResourceLock.cs);
}

// File Line: 842
// RVA: 0x8B1CC0
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::AddNewResourceHandle(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::ResourceHandle *result,
        Scaleform::GFx::ResourceId *rid)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // rbx
  unsigned int ResIndexCounter; // eax
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef key; // [rsp+30h] [rbp-28h] BYREF

  v6 = 0i64;
  ResIndexCounter = this->ResIndexCounter;
  result->HType = RH_Index;
  result->BindIndex = ResIndexCounter;
  ++this->ResIndexCounter;
  if ( this->LoadState < LS_LoadFinished )
  {
    v6 = this;
    EnterCriticalSection(&this->ResourceLock.cs);
  }
  key.pFirst = rid;
  key.pSecond = result;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef>(
    &this->Resources.mHash,
    &this->Resources,
    &key,
    rid->Id ^ ((unsigned __int64)rid->Id >> 8));
  if ( v6 )
    LeaveCriticalSection(&v6->ResourceLock.cs);
  return result;
}

// File Line: 852
// RVA: 0x8DDB80
__int64 __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::ResourceHandle *phandle,
        Scaleform::GFx::ResourceId *rid)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // rbx
  Scaleform::HashUncachedLH<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp,2> *p_Resources; // rdi
  signed __int64 v8; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> > v9; // rax
  unsigned __int8 v10; // di

  v6 = 0i64;
  if ( this->LoadState < LS_LoadFinished )
  {
    v6 = this;
    EnterCriticalSection(&this->ResourceLock.cs);
  }
  p_Resources = &this->Resources;
  if ( !p_Resources->mHash.pTable
    || (v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF>>::findIndexCore<Scaleform::GFx::ResourceId>(
               &p_Resources->mHash,
               rid,
               p_Resources->mHash.pTable->SizeMask & (rid->Id ^ ((unsigned __int64)rid->Id >> 8))),
        v8 < 0) )
  {
    p_Resources = 0i64;
    v8 = 0i64;
  }
  if ( p_Resources && (v9.pTable = p_Resources->mHash.pTable) != 0i64 && v8 <= (signed __int64)v9.pTable->SizeMask )
  {
    Scaleform::GFx::ResourceHandle::operator=(phandle, (Scaleform::GFx::ResourceHandle *)&v9.pTable[2 * v8 + 2]);
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
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::AddFrameName(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::String *name,
        Scaleform::GFx::LogState *plog)
{
  Scaleform::Lock *p_PlaylistLock; // rbx

  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::SetCaseInsensitive(
    &this->NamedFrames,
    name,
    &this->LoadingFrame);
  LeaveCriticalSection(&p_PlaylistLock->cs);
}

// File Line: 897
// RVA: 0x908A10
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::SetLoadingPlaylistFrame(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::TimelineDef::Frame *frame,
        Scaleform::GFx::LogState *plog)
{
  Scaleform::Lock *p_PlaylistLock; // rbx
  unsigned __int64 LoadingFrame; // r9
  unsigned __int64 Size; // rbp
  Scaleform::Log *pObject; // rax
  Scaleform::GFx::TimelineDef::Frame *v10; // r9

  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  LoadingFrame = this->LoadingFrame;
  if ( this->Playlist.Data.Size > LoadingFrame )
  {
    v10 = &this->Playlist.Data.Data[LoadingFrame];
    v10->pTagPtrList = frame->pTagPtrList;
    v10->TagCount = frame->TagCount;
  }
  else if ( plog && (plog->pLog.pObject || Scaleform::Log::GetGlobalLog()) )
  {
    Size = this->Playlist.Data.Size;
    pObject = plog->pLog.pObject;
    if ( !pObject )
      pObject = Scaleform::Log::GetGlobalLog();
    Scaleform::Log::LogError(
      pObject,
      "Invalid SWF file: failed to load frame #%d since total frames counter is %d",
      this->LoadingFrame + 1,
      (unsigned int)Size);
  }
  LeaveCriticalSection(&p_PlaylistLock->cs);
}

// File Line: 912
// RVA: 0x908940
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::SetLoadingInitActionFrame(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::TimelineDef::Frame *frame,
        Scaleform::GFx::LogState *plog)
{
  Scaleform::Lock *p_PlaylistLock; // rbx
  unsigned __int64 LoadingFrame; // rcx
  unsigned __int64 Size; // rbp
  Scaleform::Log *pObject; // rax
  Scaleform::GFx::TimelineDef::Frame *v10; // rcx

  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  LoadingFrame = this->LoadingFrame;
  if ( this->InitActionList.Data.Size > LoadingFrame )
  {
    v10 = &this->InitActionList.Data.Data[LoadingFrame];
    v10->pTagPtrList = frame->pTagPtrList;
    v10->TagCount = frame->TagCount;
    ++this->InitActionsCnt;
  }
  else if ( plog && (plog->pLog.pObject || Scaleform::Log::GetGlobalLog()) )
  {
    Size = this->InitActionList.Data.Size;
    pObject = plog->pLog.pObject;
    if ( !pObject )
      pObject = Scaleform::Log::GetGlobalLog();
    Scaleform::Log::LogError(
      pObject,
      "Invalid SWF file: failed to load init action frame #%d since total frames counter is %d",
      this->LoadingFrame + 1,
      (unsigned int)Size);
  }
  LeaveCriticalSection(&p_PlaylistLock->cs);
}

// File Line: 943
// RVA: 0x8DA9E0
bool __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetLabeledFrame(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        const char *label,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  Scaleform::Lock *p_PlaylistLock; // rbx
  bool v10; // di

  if ( this->LoadState >= LS_LoadFinished )
    return Scaleform::GFx::MovieDataDef::TranslateFrameString(&this->NamedFrames, label, frameNumber, translateNumbers);
  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  v10 = Scaleform::GFx::MovieDataDef::TranslateFrameString(&this->NamedFrames, label, frameNumber, translateNumbers);
  LeaveCriticalSection(&p_PlaylistLock->cs);
  return v10;
}

// File Line: 953
// RVA: 0x8D8D50
Scaleform::String *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabel(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int frameNumber,
        unsigned int *exactFrameNumberForLabel)
{
  Scaleform::Lock *p_PlaylistLock; // rbx
  Scaleform::String *v8; // rdi

  if ( this->LoadState >= LS_LoadFinished )
    return Scaleform::GFx::MovieDataDef::TranslateNumberToFrameString(
             &this->NamedFrames,
             frameNumber,
             exactFrameNumberForLabel);
  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  v8 = Scaleform::GFx::MovieDataDef::TranslateNumberToFrameString(
         &this->NamedFrames,
         frameNumber,
         exactFrameNumberForLabel);
  LeaveCriticalSection(&p_PlaylistLock->cs);
  return v8;
}

// File Line: 963
// RVA: 0x8D8E00
Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabels(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int frameNumber,
        Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *destArr)
{
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // r9
  __int64 v7; // r14
  unsigned __int64 v8; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v9; // rcx
  int v10; // ebp
  signed __int64 v11; // rbx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v12; // rcx
  Scaleform::String *v13; // rsi
  Scaleform::String *v14; // rcx
  unsigned __int64 SizeMask; // rcx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v16; // rax
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_NamedFrames; // [rsp+30h] [rbp-48h]
  unsigned __int64 v19; // [rsp+38h] [rbp-40h]
  char v20; // [rsp+80h] [rbp+8h]

  v20 = 0;
  if ( this->LoadState < LS_LoadFinished )
  {
    EnterCriticalSection(&this->PlaylistLock.cs);
    v20 = 1;
  }
  pTable = this->NamedFrames.mHash.pTable;
  v7 = 0i64;
  if ( pTable )
  {
    v8 = 0i64;
    v9 = pTable + 1;
    do
    {
      if ( v9->EntryCount != -2i64 )
        break;
      ++v8;
      v9 += 2;
    }
    while ( v8 <= pTable->SizeMask );
    p_NamedFrames = &this->NamedFrames;
    v19 = v8;
  }
  else
  {
    p_NamedFrames = 0i64;
    v19 = 0i64;
  }
  v10 = 0;
  v11 = v19;
  while ( p_NamedFrames )
  {
    v12 = p_NamedFrames->mHash.pTable;
    if ( !p_NamedFrames->mHash.pTable || v11 > (signed __int64)v12->SizeMask )
      break;
    if ( frameNumber == LODWORD(v12[2 * v11 + 2].SizeMask) )
    {
      v13 = (Scaleform::String *)&v12[2 * v11];
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &destArr->Data,
        destArr,
        destArr->Data.Size + 1);
      v14 = &destArr->Data.Data[destArr->Data.Size - 1];
      if ( v14 )
        Scaleform::String::String(v14, v13 + 4);
      ++v10;
    }
    SizeMask = p_NamedFrames->mHash.pTable->SizeMask;
    if ( v11 <= (__int64)SizeMask && ++v11 <= SizeMask )
    {
      v16 = &p_NamedFrames->mHash.pTable[2 * v11 + 1];
      do
      {
        if ( v16->EntryCount != -2i64 )
          break;
        ++v11;
        v16 += 2;
      }
      while ( v11 <= SizeMask );
    }
  }
  if ( v20 )
    LeaveCriticalSection(&this->PlaylistLock.cs);
  if ( v10 )
    return destArr;
  return (Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *)v7;
}

// File Line: 989
// RVA: 0x8B1FF0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::AddScene(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::String *name,
        unsigned int off)
{
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> > *p_Scenes; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *v7; // rax
  Scaleform::MemoryHeap *pHeap; // rbx
  Scaleform::GFx::MovieDataDef::SceneInfo v9; // [rsp+30h] [rbp-40h] BYREF

  p_Scenes = &this->Scenes;
  if ( !this->Scenes.pObject )
  {
    v7 = (Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *)this->pHeap->vfptr->Alloc(this->pHeap, 24i64, 0i64);
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
      p_Scenes,
      v7);
  }
  pHeap = this->pHeap;
  Scaleform::StringDH::CopyConstructHelper(&v9.Name, name, pHeap);
  v9.Offset = off;
  memset(&v9.NumFrames, 0, 28);
  v9.Labels.Data.pHeap = pHeap;
  Scaleform::ArrayData<Scaleform::GFx::MovieDataDef::SceneInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieDataDef::SceneInfo,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &p_Scenes->pObject->Data,
    &v9);
  Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::DestructArray(
    v9.Labels.Data.Data,
    v9.Labels.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9.Labels.Data.Data);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v9.Name.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 1020
// RVA: 0x8DDFE0
Scaleform::GFx::MovieDataDef::SceneInfo *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetScenes(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned __int64 *count)
{
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *pObject; // rax

  pObject = this->Scenes.pObject;
  if ( pObject )
  {
    *count = pObject->Data.Size;
    return this->Scenes.pObject->Data.Data;
  }
  else
  {
    *count = 0i64;
    return 0i64;
  }
}

// File Line: 1025
// RVA: 0x8DC150
Scaleform::GFx::TimelineDef::Frame *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetPlaylist(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::TimelineDef::Frame *result,
        int frameNumber)
{
  __int64 v3; // rbp
  Scaleform::Lock *p_PlaylistLock; // rbx
  Scaleform::GFx::TimelineDef::Frame *v7; // rcx

  v3 = frameNumber;
  if ( this->LoadState < LS_LoadFinished )
  {
    p_PlaylistLock = &this->PlaylistLock;
    EnterCriticalSection(&this->PlaylistLock.cs);
    v7 = &this->Playlist.Data.Data[v3];
    result->pTagPtrList = v7->pTagPtrList;
    result->TagCount = v7->TagCount;
    LeaveCriticalSection(&p_PlaylistLock->cs);
  }
  else
  {
    *result = this->Playlist.Data.Data[frameNumber];
  }
  return result;
}

// File Line: 1039
// RVA: 0x8DA130
__int64 __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::GetInitActions(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::TimelineDef::Frame *pframe,
        int frameNumber)
{
  __int64 v3; // rsi
  Scaleform::Lock *p_PlaylistLock; // rbx
  unsigned __int8 v7; // di
  Scaleform::GFx::TimelineDef::Frame *v8; // rcx

  v3 = frameNumber;
  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  if ( (unsigned int)v3 < this->InitActionList.Data.Size )
  {
    v8 = &this->InitActionList.Data.Data[v3];
    pframe->pTagPtrList = v8->pTagPtrList;
    pframe->TagCount = v8->TagCount;
    v7 = 1;
  }
  else
  {
    v7 = 0;
  }
  LeaveCriticalSection(&p_PlaylistLock->cs);
  return v7;
}

// File Line: 1091
// RVA: 0x896E60
void __fastcall Scaleform::GFx::GFxMovieDataDefFileKeyData::GFxMovieDataDefFileKeyData(
        Scaleform::GFx::GFxMovieDataDefFileKeyData *this,
        const char *pfilename,
        __int64 modifyTime,
        Scaleform::GFx::Resource *pfileOpener,
        Scaleform::GFx::ImageCreator *pimageCreator)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v10; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::GFxMovieDataDefFileKeyData,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::GFxMovieDataDefFileKeyData::`vftable;
  Scaleform::String::String(&this->FileName);
  this->pFileOpener.pObject = 0i64;
  this->pImageCreator.pObject = 0i64;
  Scaleform::String::operator=(&this->FileName, pfilename);
  this->ModifyTime = modifyTime;
  if ( pfileOpener )
    Scaleform::Render::RenderBuffer::AddRef(pfileOpener);
  pObject = (Scaleform::Render::RenderBuffer *)this->pFileOpener.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFileOpener.pObject = (Scaleform::GFx::FileOpener *)pfileOpener;
  if ( pimageCreator )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pimageCreator);
  v10 = (Scaleform::Render::RenderBuffer *)this->pImageCreator.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->pImageCreator.pObject = pimageCreator;
}

// File Line: 1146
// RVA: 0x8D97F0
unsigned __int64 __fastcall Scaleform::GFx::GFxMovieDataDefFileKeyInterface::GetHashCode(
        Scaleform::GFx::GFxMovieDataDefFileKeyInterface *this,
        _QWORD *hdata)
{
  return Scaleform::String::BernsteinHashFunction(
           (const void *)((hdata[2] & 0xFFFFFFFFFFFFFFFCui64) + 12),
           *(_QWORD *)(hdata[2] & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
           0x1505ui64) ^ hdata[5] ^ hdata[3] ^ hdata[4] ^ ((hdata[5] ^ hdata[3]) >> 7);
}

// File Line: 1152
// RVA: 0x8E7ED0
bool __fastcall Scaleform::GFx::GFxMovieDataDefFileKeyInterface::KeyEquals(
        Scaleform::GFx::GFxMovieDataDefFileKeyInterface *this,
        _QWORD *hdata,
        Scaleform::GFx::ResourceKey *other)
{
  _QWORD *hKeyData; // r8
  unsigned __int8 *v5; // rax
  unsigned __int64 v6; // r8
  int v7; // ecx
  int v8; // edx

  if ( this != other->pKeyInterface )
    return 0;
  hKeyData = other->hKeyData;
  if ( hdata[3] != hKeyData[3] || hdata[5] != hKeyData[5] || hdata[4] != hKeyData[4] )
    return 0;
  v5 = (unsigned __int8 *)((hdata[2] & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v6 = (hKeyData[2] & 0xFFFFFFFFFFFFFFFCui64) - (hdata[2] & 0xFFFFFFFFFFFFFFFCui64);
  do
  {
    v7 = v5[v6];
    v8 = *v5 - v7;
    if ( v8 )
      break;
    ++v5;
  }
  while ( v7 );
  return !v8;
}

// File Line: 1160
// RVA: 0x8D7B80
const char *__fastcall Scaleform::GFx::GFxMovieDataDefFileKeyInterface::GetFileURL(
        Scaleform::GFx::GFxMovieDataDefFileKeyInterface *this,
        _QWORD *hdata)
{
  return (const char *)((hdata[2] & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 1168
// RVA: 0x159C240
__int64 Scaleform::GFx::_dynamic_initializer_for__GFxMovieDataDefFileKeyInterface_Instance__()
{
  GFxMovieDataDefFileKeyInterface_Instance.vfptr = (Scaleform::GFx::ResourceKey::KeyInterfaceVtbl *)&Scaleform::GFx::GFxMovieDataDefFileKeyInterface::`vftable;
  return atexit((int (__fastcall *)())Scaleform::GFx::_dynamic_atexit_destructor_for__GFxMovieDataDefFileKeyInterface_Instance__);
}

// File Line: 1172
// RVA: 0x8C1450
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::MovieDataDef::CreateMovieFileKey(
        Scaleform::GFx::ResourceKey *result,
        const char *pfilename,
        __int64 modifyTime,
        Scaleform::GFx::Resource *pfileOpener,
        Scaleform::GFx::ImageCreator *pimageCreator)
{
  Scaleform::Render::RenderBuffer *v9; // rbx
  Scaleform::GFx::GFxMovieDataDefFileKeyData *v10; // rax
  Scaleform::Render::RenderBuffer *v11; // rax

  v9 = 0i64;
  v10 = (Scaleform::GFx::GFxMovieDataDefFileKeyData *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        48i64,
                                                        0i64);
  if ( v10 )
  {
    Scaleform::GFx::GFxMovieDataDefFileKeyData::GFxMovieDataDefFileKeyData(
      v10,
      pfilename,
      modifyTime,
      pfileOpener,
      pimageCreator);
    v9 = v11;
  }
  GFxMovieDataDefFileKeyInterface_Instance.vfptr->AddRef(&GFxMovieDataDefFileKeyInterface_Instance, v9);
  result->pKeyInterface = &GFxMovieDataDefFileKeyInterface_Instance;
  result->hKeyData = v9;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  return result;
}

// File Line: 1182
// RVA: 0x8DDC70
Scaleform::String *__fastcall Scaleform::GFx::MovieDataDef::GetResourceName(
        Scaleform::GFx::MovieDataDef *this,
        Scaleform::String *result)
{
  const char *ShortFilename; // rax

  ShortFilename = Scaleform::GetShortFilename((const char *)(((unsigned __int64)this->Scaleform::GFx::ResourceReport::vfptr[2].GetResourceName & 0xFFFFFFFFFFFFFFFCui64)
                                                           + 12));
  Scaleform::String::String(result, ShortFilename);
  return result;
}

// File Line: 1201
// RVA: 0x89AFE0
void __fastcall Scaleform::GFx::MovieDefImpl::MovieDefImpl(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MovieDataDef *pdataDef,
        Scaleform::GFx::Resource *pstates,
        Scaleform::GFx::Resource *ploaderImpl,
        unsigned int loadConstantFlags,
        Scaleform::GFx::StateBagImpl *pdelegateState,
        Scaleform::MemoryHeap *pargHeap,
        bool fullyLoaded,
        unsigned __int64 memoryArena)
{
  Scaleform::GFx::StateBagImpl *v13; // rsi
  Scaleform::MemoryHeap *v14; // r14
  const char *ShortFilename; // rax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v16; // rax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v17; // rax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v18; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v20; // rcx
  Scaleform::Render::RenderBuffer *v21; // rcx
  Scaleform::MemoryHeap *v22; // rax
  Scaleform::GFx::StateBagImpl *v23; // rax
  Scaleform::Render::RenderBuffer *v24; // rcx
  unsigned int v25; // [rsp+40h] [rbp-78h] BYREF
  __int64 v26; // [rsp+48h] [rbp-70h]
  __int64 v27; // [rsp+50h] [rbp-68h]
  __int64 v28; // [rsp+58h] [rbp-60h]
  __int64 v29; // [rsp+60h] [rbp-58h]
  __int64 v30; // [rsp+68h] [rbp-50h]
  __int64 v31; // [rsp+70h] [rbp-48h]
  unsigned __int64 v32; // [rsp+78h] [rbp-40h]
  Scaleform::String v33; // [rsp+D0h] [rbp+18h] BYREF
  Scaleform::HashSetLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > > *p_ReleaseNotifiers; // [rsp+D8h] [rbp+20h]

  this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  this->RefCount.Value = 1;
  v13 = 0i64;
  this->pLib = 0i64;
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::MovieDef::`vftable{for `Scaleform::GFx::Resource};
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::MovieDef::`vftable{for `Scaleform::GFx::StateBag};
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::MovieDefImpl::`vftable{for `Scaleform::GFx::Resource};
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::MovieDefImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->pStateBag.pObject = 0i64;
  this->pLoaderImpl.pObject = 0i64;
  this->pBindStates.pObject = 0i64;
  p_ReleaseNotifiers = &this->ReleaseNotifiers;
  this->ReleaseNotifiers.pTable = 0i64;
  Scaleform::Lock::Lock(&this->ReleaseNotifiersLock, 0);
  this->pBindData.pObject = 0i64;
  v14 = pargHeap;
  p_ReleaseNotifiers = (Scaleform::HashSetLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > > *)pargHeap;
  if ( !pargHeap )
  {
    ShortFilename = Scaleform::GetShortFilename((const char *)((pdataDef->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                             + 12));
    Scaleform::String::String(&v33, "MovieDef  \"", ShortFilename, "\"");
    v25 = HIWORD(loadConstantFlags) & 0x1000;
    v26 = 16i64;
    v27 = 4096i64;
    v28 = 4096i64;
    v29 = -1i64;
    v30 = 0i64;
    v31 = 2i64;
    v32 = memoryArena;
    v14 = (Scaleform::MemoryHeap *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, unsigned __int64, unsigned int *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
                                     Scaleform::Memory::pGlobalHeap,
                                     (v33.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                                     &v25);
    p_ReleaseNotifiers = (Scaleform::HashSetLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > > *)v14;
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((v33.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  v16 = (Scaleform::GFx::MovieDefImpl::BindTaskData *)v14->vfptr->Alloc(v14, 256ui64, 0i64);
  if ( v16 )
  {
    Scaleform::GFx::MovieDefImpl::BindTaskData::BindTaskData(v16, v14, pdataDef, this, loadConstantFlags, fullyLoaded);
    v18 = v17;
  }
  else
  {
    v18 = 0i64;
  }
  pObject = (Scaleform::Render::RenderBuffer *)this->pBindData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pBindData.pObject = v18;
  if ( !pargHeap )
    Scaleform::MemoryHeap::ReleaseOnFree((ANTLR3_COMMON_TOKEN_struct *)v14, (__int64)v18);
  if ( ploaderImpl )
    Scaleform::Render::RenderBuffer::AddRef(ploaderImpl);
  v20 = (Scaleform::Render::RenderBuffer *)this->pLoaderImpl.pObject;
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  this->pLoaderImpl.pObject = (Scaleform::GFx::LoaderImpl *)ploaderImpl;
  if ( pstates )
    Scaleform::Render::RenderBuffer::AddRef(pstates);
  v21 = (Scaleform::Render::RenderBuffer *)this->pBindStates.pObject;
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
  this->pBindStates.pObject = (Scaleform::GFx::MovieDefBindStates *)pstates;
  v22 = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                   Scaleform::Memory::pGlobalHeap,
                                   88i64);
  pargHeap = v22;
  if ( v22 )
  {
    Scaleform::GFx::StateBagImpl::StateBagImpl((Scaleform::GFx::StateBagImpl *)v22, pdelegateState);
    v13 = v23;
  }
  v24 = (Scaleform::Render::RenderBuffer *)this->pStateBag.pObject;
  if ( v24 )
    Scaleform::RefCountImpl::Release(v24);
  this->pStateBag.pObject = v13;
}

// File Line: 1234
// RVA: 0x8A63C0
void __fastcall Scaleform::GFx::MovieDefImpl::~MovieDefImpl(Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::Lock *p_ReleaseNotifiersLock; // rbx
  Scaleform::HashSetLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > > *p_ReleaseNotifiers; // r15
  Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > >::TableType *pTable; // rcx
  Scaleform::HashSetLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > > *v5; // rsi
  unsigned __int64 v6; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > >::TableType *v7; // rax
  Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > >::TableType *v8; // rcx
  __int64 v9; // rcx
  unsigned __int64 SizeMask; // rdx
  unsigned __int64 *v11; // rcx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  __int64 v13; // rcx
  __int64 v14; // rdx
  Scaleform::Render::RenderBuffer *v15; // rcx
  Scaleform::Render::RenderBuffer *v16; // rcx
  Scaleform::Render::RenderBuffer *v17; // rcx

  this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::MovieDefImpl::`vftable{for `Scaleform::GFx::Resource};
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::MovieDefImpl::`vftable{for `Scaleform::GFx::StateBag};
  p_ReleaseNotifiersLock = &this->ReleaseNotifiersLock;
  EnterCriticalSection(&this->ReleaseNotifiersLock.cs);
  p_ReleaseNotifiers = &this->ReleaseNotifiers;
  pTable = this->ReleaseNotifiers.pTable;
  if ( pTable )
  {
    v6 = 0i64;
    v7 = pTable + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++v6;
      v7 = (Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *> > >::TableType *)((char *)v7 + 24);
    }
    while ( v6 <= pTable->SizeMask );
    v5 = &this->ReleaseNotifiers;
  }
  else
  {
    v5 = 0i64;
    v6 = 0i64;
  }
  while ( v5 )
  {
    v8 = v5->pTable;
    if ( !v5->pTable || (signed __int64)v6 > (signed __int64)v8->SizeMask )
      break;
    v9 = *(&v8[2].EntryCount + 3 * v6);
    if ( v9 )
      (*(void (__fastcall **)(__int64, Scaleform::GFx::MovieDefImpl *))(*(_QWORD *)v9 + 8i64))(v9, this);
    SizeMask = v5->pTable->SizeMask;
    if ( (__int64)v6 <= (__int64)SizeMask && ++v6 <= SizeMask )
    {
      v11 = &v5->pTable[1].EntryCount + 3 * v6;
      do
      {
        if ( *v11 != -2i64 )
          break;
        ++v6;
        v11 += 3;
      }
      while ( v6 <= SizeMask );
    }
  }
  LeaveCriticalSection(&p_ReleaseNotifiersLock->cs);
  Scaleform::GFx::MovieDefImpl::BindTaskData::OnMovieDefRelease(this->pBindData.pObject);
  pObject = (Scaleform::Render::RenderBuffer *)this->pBindData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Lock::~Lock(&p_ReleaseNotifiersLock->cs);
  if ( p_ReleaseNotifiers->pTable )
  {
    v13 = 0i64;
    v14 = p_ReleaseNotifiers->pTable->SizeMask + 1;
    do
    {
      if ( *(unsigned __int64 *)((char *)&p_ReleaseNotifiers->pTable[1].EntryCount + v13) != -2i64 )
        *(unsigned __int64 *)((char *)&p_ReleaseNotifiers->pTable[1].EntryCount + v13) = -2i64;
      v13 += 24i64;
      --v14;
    }
    while ( v14 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_ReleaseNotifiers->pTable);
    p_ReleaseNotifiers->pTable = 0i64;
  }
  v15 = (Scaleform::Render::RenderBuffer *)this->pBindStates.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  v16 = (Scaleform::Render::RenderBuffer *)this->pLoaderImpl.pObject;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  v17 = (Scaleform::Render::RenderBuffer *)this->pStateBag.pObject;
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 1250
// RVA: 0x8B1E90
void __fastcall Scaleform::GFx::MovieDefImpl::AddReleaseNotifier(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MovieDefImpl::ReleaseNotifier *rn)
{
  Scaleform::Lock *p_ReleaseNotifiersLock; // rbx
  Scaleform::GFx::MovieDefImpl::ReleaseNotifier *key; // [rsp+48h] [rbp+10h] BYREF

  key = rn;
  p_ReleaseNotifiersLock = &this->ReleaseNotifiersLock;
  EnterCriticalSection(&this->ReleaseNotifiersLock.cs);
  Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>>>::Set<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>(
    &this->ReleaseNotifiers,
    &this->ReleaseNotifiers,
    &key);
  LeaveCriticalSection(&p_ReleaseNotifiersLock->cs);
}

// File Line: 1256
// RVA: 0x8FFC10
void __fastcall Scaleform::GFx::MovieDefImpl::RemoveReleaseNotifier(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MovieDefImpl::ReleaseNotifier *rn)
{
  Scaleform::Lock *p_ReleaseNotifiersLock; // rbx
  Scaleform::GFx::MovieDefImpl::ReleaseNotifier *key; // [rsp+48h] [rbp+10h] BYREF

  key = rn;
  p_ReleaseNotifiersLock = &this->ReleaseNotifiersLock;
  EnterCriticalSection(&this->ReleaseNotifiersLock.cs);
  Scaleform::HashSetBase<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *,Scaleform::FixedSizeHash<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>>>::RemoveAlt<Scaleform::GFx::MovieDefImpl::ReleaseNotifier *>(
    &this->ReleaseNotifiers,
    &key);
  LeaveCriticalSection(&p_ReleaseNotifiersLock->cs);
}

// File Line: 1270
// RVA: 0x89A900
void __fastcall Scaleform::GFx::MovieBindProcess::MovieBindProcess(
        Scaleform::GFx::MovieBindProcess *this,
        Scaleform::GFx::Resource *pls,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack)
{
  Scaleform::GFx::Resource *pObject; // rcx
  Scaleform::GFx::MovieDataDef *v9; // rcx
  bool v10; // al
  Scaleform::GFx::ImagePackParamsBase *v11; // r14
  Scaleform::GFx::ImageFileHandlerRegistry *v12; // rbp
  Scaleform::GFx::FileOpener *vfptr; // r15
  Scaleform::GFx::LogState *v14; // rax
  Scaleform::Log *GlobalLog; // rax
  Scaleform::GFx::ImagePacker *v16; // rdi
  Scaleform::GFx::ImagePacker *v17; // rcx
  Scaleform::GFx::TempBindData *v18; // rax
  int v19; // [rsp+30h] [rbp-98h] BYREF
  __int64 v20; // [rsp+38h] [rbp-90h]
  int v21; // [rsp+40h] [rbp-88h]
  int v22; // [rsp+44h] [rbp-84h]
  Scaleform::Log *v23; // [rsp+48h] [rbp-80h]
  __int128 v24; // [rsp+50h] [rbp-78h]
  __int64 v25; // [rsp+60h] [rbp-68h]
  Scaleform::String v26; // [rsp+78h] [rbp-50h] BYREF

  Scaleform::GFx::LoaderTask::LoaderTask(this, pls, Id_MovieBind);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieBindProcess::`vftable;
  this->pFrameBindData = 0i64;
  this->GlyphTextureIdGen.Id = 589824;
  this->pImagePacker.pObject = 0i64;
  pObject = (Scaleform::GFx::Resource *)pdefImpl->pBindData.pObject;
  if ( pObject )
    Scaleform::Render::RenderBuffer::AddRef(pObject);
  this->pBindData.pObject = pdefImpl->pBindData.pObject;
  this->pLoadStack = ploadStack;
  v9 = this->pBindData.pObject->pDataDef.pObject;
  this->pDataDef = v9;
  v10 = (((__int64 (__fastcall *)(Scaleform::GFx::MovieDataDef *))v9->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr[4].GetKey)(v9) & 0x10) != 0;
  this->Stripped = v10;
  v11 = *(Scaleform::GFx::ImagePackParamsBase **)&pls->pLib[4].RefCount;
  if ( !v11 || v10 )
  {
    this->pTempBindData = 0i64;
  }
  else
  {
    v19 = 2;
    v20 = 0i64;
    v21 = 1;
    v22 = 1;
    v23 = 0i64;
    v24 = 0i64;
    v25 = 0i64;
    Scaleform::String::String(&v26);
    v12 = *(Scaleform::GFx::ImageFileHandlerRegistry **)&pls[2].RefCount.Value;
    vfptr = (Scaleform::GFx::FileOpener *)pls->pLib[1].vfptr;
    v14 = (Scaleform::GFx::LogState *)pls[1].vfptr;
    if ( v14 )
    {
      GlobalLog = v14->pLog.pObject;
      if ( !GlobalLog )
        GlobalLog = Scaleform::Log::GetGlobalLog();
    }
    else
    {
      GlobalLog = 0i64;
    }
    *(_QWORD *)&v24 = vfptr;
    v23 = GlobalLog;
    *((_QWORD *)&v24 + 1) = v12;
    v20 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))pdefImpl->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[4].GetResourceTypeCode)(pdefImpl);
    v16 = (Scaleform::GFx::ImagePacker *)((__int64 (__fastcall *)(Scaleform::GFx::ImagePackParamsBase *, Scaleform::GFx::ResourceId *, Scaleform::RefCountImplCoreVtbl *, int *, __int64))v11->vfptr[2].__vecDelDtor)(
                                           v11,
                                           &this->GlyphTextureIdGen,
                                           pls->pLib[2].vfptr,
                                           &v19,
                                           -2i64);
    v17 = this->pImagePacker.pObject;
    if ( v17 )
      Scaleform::RefCountNTSImpl::Release(v17);
    this->pImagePacker.pObject = v16;
    v16->vfptr[1].__vecDelDtor(v16, (unsigned int)this->pBindData.pObject);
    v18 = (Scaleform::GFx::TempBindData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                            Scaleform::Memory::pGlobalHeap,
                                            8i64);
    if ( v18 )
      v18->FillStyleImageWrap.pTable = 0i64;
    else
      v18 = 0i64;
    this->pTempBindData = v18;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 1295
// RVA: 0x8A6100
void __fastcall Scaleform::GFx::MovieBindProcess::~MovieBindProcess(Scaleform::GFx::MovieBindProcess *this)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // rsi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v3; // rax
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *pTempBindData; // rbx
  Scaleform::GFx::ImagePacker *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::GFx::ImagePacker *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieBindProcess::`vftable;
  pObject = this->pBindData.pObject;
  if ( pObject )
  {
    pObject = (Scaleform::GFx::MovieDefImpl::BindTaskData *)pObject->pBindUpdate.pObject;
    if ( pObject )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pObject);
  }
  v3 = this->pBindData.pObject;
  if ( v3 )
  {
    if ( (v3->BindState & 0xF) == 1 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(this->pBindData.pObject, 3u);
    v4 = (Scaleform::Render::RenderBuffer *)this->pBindData.pObject;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
    this->pBindData.pObject = 0i64;
  }
  pTempBindData = (Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)this->pTempBindData;
  if ( pTempBindData )
  {
    Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>(pTempBindData);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pTempBindData);
  }
  v6 = this->pImagePacker.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  this->pImagePacker.pObject = 0i64;
  if ( pObject )
  {
    Scaleform::Mutex::DoLock((Scaleform::Mutex *)&pObject->pHeap);
    LOBYTE(pObject->ResourceBinding.pResources) = 1;
    Scaleform::WaitCondition::NotifyAll((Scaleform::WaitCondition *)&pObject->ResourceBinding.ResourceCount);
    Scaleform::Mutex::Unlock((Scaleform::Mutex *)&pObject->pHeap);
  }
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pObject);
  v7 = (Scaleform::Render::RenderBuffer *)this->pBindData.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = this->pImagePacker.pObject;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderTask::`vftable;
  Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(this->pLoadStates.pObject->pLoaderImpl.pObject, this);
  v9 = (Scaleform::Render::RenderBuffer *)this->pLoadStates.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 1323
// RVA: 0x8EB830
bool __fastcall Scaleform::GFx::MatchFileNames(Scaleform::String *path1, Scaleform::String *path2)
{
  _DWORD *v2; // rbx
  _DWORD *v3; // rdi
  int v4; // r10d
  int v5; // r11d
  __int64 v7; // r9
  __int64 v8; // rcx
  char v9; // al
  char v10; // dl
  int v11; // r8d
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
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // rax
  signed __int64 v3; // rax
  unsigned int v4; // edx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v5; // rcx
  Scaleform::GFx::FrameBindData *pFrameBindData; // r15
  Scaleform::GFx::FrameBindData *volatile Value; // r15
  Scaleform::GFx::MovieDataDef::LoadTaskData *v8; // rdi
  Scaleform::GFx::FrameBindData *v9; // r15
  Scaleform::GFx::FrameBindData *v10; // rax
  Scaleform::GFx::ImportData *pImportData; // rdi
  Scaleform::GFx::MovieDefImpl *MovieDefImplAddRef; // rax
  Scaleform::GFx::MovieDefImpl *v13; // r14
  Scaleform::GFx::Resource **FontLib; // rdi
  Scaleform::String *p_SourceUrl; // r12
  const char *DefaultFontLibName; // rax
  int v17; // edi
  Scaleform::String *v18; // rax
  char v19; // si
  Scaleform::Render::RenderBuffer *v20; // rsi
  int v21; // edi
  Scaleform::GFx::LoaderImpl::LoadStackItem *pLoadStack; // rcx
  Scaleform::GFx::LoaderImpl::LoadStackItem **j; // rax
  const char *v24; // rax
  Scaleform::GFx::MovieDefImpl *v25; // rsi
  __int64 *v26; // rdx
  __int64 *v27; // rax
  unsigned int FileAttributes; // edi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v29; // rax
  bool v30; // di
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v31; // rcx
  Scaleform::GFx::ImportVisitor *v32; // r12
  Scaleform::GFx::MovieDefImpl *v33; // rdi
  Scaleform::GFx::ResourceLibBase *v34; // rcx
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v35; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v36; // rcx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceLibBase *v38; // rcx
  Scaleform::GFx::ResourceDataNode *pResourceData; // rsi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v40; // rax
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // r14
  Scaleform::MemoryHeap *pHeap; // rdx
  unsigned int v43; // r12d
  Scaleform::GFx::Resource *v44; // rdi
  Scaleform::GFx::ResourceLibBase *v45; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v46; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v47; // rax
  __int64 v48; // rdi
  Scaleform::Render::RenderBuffer *v49; // rcx
  Scaleform::GFx::Resource *v50; // rbx
  Scaleform::GFx::ResourceLibBase *v51; // rcx
  Scaleform::GFx::FontDataUseNode *pFontData; // r12
  unsigned int v53; // esi
  unsigned int BindIndex; // r8d
  Scaleform::GFx::ResourceBindData *v55; // rdx
  Scaleform::GFx::FontResource *v56; // rdi
  unsigned __int64 v57; // rsi
  unsigned __int64 v58; // r8
  Scaleform::String *v59; // rcx
  Scaleform::GFx::Resource *v60; // rdi
  Scaleform::GFx::ResourceLibBase *v61; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v62; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v63; // rdi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v64; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v65; // rdi
  Scaleform::GFx::MovieDataDef *v66; // rcx
  int FileLength; // r12d
  Scaleform::String *v68; // rsi
  int v69; // r15d
  int BindingFrame; // r14d
  unsigned int v71; // esi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v72; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v73; // rax
  __int64 v74; // rdi
  Scaleform::Render::RenderBuffer *v75; // rcx
  unsigned int v76; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::ResourceBindData bd; // [rsp+38h] [rbp-C8h] BYREF
  Scaleform::Render::RenderBuffer *v78; // [rsp+48h] [rbp-B8h]
  Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::Render::RenderBuffer *v80; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::ResourceBindData pdata; // [rsp+70h] [rbp-90h] BYREF
  __int64 v82[2]; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::String path2; // [rsp+A8h] [rbp-58h] BYREF
  Scaleform::String v85; // [rsp+B0h] [rbp-50h] BYREF
  int v86; // [rsp+B8h] [rbp-48h]
  int v87; // [rsp+BCh] [rbp-44h]
  int v88; // [rsp+C0h] [rbp-40h]
  int v89; // [rsp+C4h] [rbp-3Ch]
  Scaleform::String v90; // [rsp+C8h] [rbp-38h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo v91; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontLib> result; // [rsp+E8h] [rbp-18h] BYREF
  Scaleform::Mutex *p_mMutex; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::MovieDefImpl *v94; // [rsp+F8h] [rbp-8h]
  __int64 v95; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::MovieDefImpl *v96; // [rsp+108h] [rbp+8h]
  __int64 v97; // [rsp+110h] [rbp+10h]
  __int64 v98; // [rsp+118h] [rbp+18h]
  __int64 v99; // [rsp+120h] [rbp+20h]
  Scaleform::Render::RenderBuffer *v100; // [rsp+128h] [rbp+28h]
  unsigned int i; // [rsp+190h] [rbp+90h]
  Scaleform::MemoryHeap *v102; // [rsp+190h] [rbp+90h]
  unsigned int v103; // [rsp+190h] [rbp+90h]
  Scaleform::GFx::ProgressHandler *v104; // [rsp+190h] [rbp+90h]
  unsigned int LoadFlags; // [rsp+198h] [rbp+98h]
  Scaleform::GFx::LoadStates *pls; // [rsp+1A0h] [rbp+A0h]
  Scaleform::GFx::ImportData *pimport; // [rsp+1A8h] [rbp+A8h]

  v98 = -2i64;
  v76 = 0;
  pObject = this->pBindData.pObject;
  if ( !pObject )
    return 3i64;
  v3 = pObject->BindState & 0xF;
  if ( (_DWORD)v3 != 1 )
  {
    if ( (_DWORD)v3 )
      return v3;
    v4 = this->pBindData.pObject->BindState & 0xFFFFFFF0 | 1;
    v5 = this->pBindData.pObject;
    if ( v5 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v5, v4);
  }
  pFrameBindData = this->pFrameBindData;
  if ( pFrameBindData )
    Value = pFrameBindData->pNextFrame.Value;
  else
    Value = this->pDataDef->pData.pObject->BindData.pFrameData.Value;
  if ( !Value )
  {
    v8 = this->pDataDef->pData.pObject;
    p_mMutex = &v8->pFrameUpdate.pObject->mMutex;
    Scaleform::Mutex::DoLock(p_mMutex);
    v9 = this->pFrameBindData;
    if ( v9 )
      Value = v9->pNextFrame.Value;
    else
      Value = this->pDataDef->pData.pObject->BindData.pFrameData.Value;
    for ( ; !Value; Value = v10 ? v10->pNextFrame.Value : this->pDataDef->pData.pObject->BindData.pFrameData.Value )
    {
      if ( v8->LoadState != LS_LoadingFrames || this->pBindData.pObject->BindingCanceled )
        break;
      Scaleform::WaitCondition::Wait(&v8->pFrameUpdate.pObject->WC, &v8->pFrameUpdate.pObject->mMutex, 0xFFFFFFFF);
      v10 = this->pFrameBindData;
    }
    if ( v8->LoadState == LS_LoadCanceled )
      this->pBindData.pObject->BindingCanceled = 1;
    Scaleform::Mutex::Unlock(p_mMutex);
    if ( !Value )
      goto LABEL_178;
  }
  if ( this->pBindData.pObject->BindingCanceled )
  {
LABEL_178:
    Scaleform::GFx::MovieBindProcess::FinishBinding(this);
    v71 = 4 - this->pBindData.pObject->BindingCanceled;
    v72 = this->pBindData.pObject;
    if ( v72 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(
        v72,
        v71 | this->pBindData.pObject->BindState & 0xFFFFFFF0);
    v73 = this->pBindData.pObject;
    v74 = (__int64)v73->pBindUpdate.pObject;
    if ( v74 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v73->pBindUpdate.pObject);
    v99 = v74;
    v75 = (Scaleform::Render::RenderBuffer *)this->pBindData.pObject;
    if ( v75 )
      Scaleform::RefCountImpl::Release(v75);
    this->pBindData.pObject = 0i64;
    Scaleform::Mutex::DoLock((Scaleform::Mutex *)(v74 + 16));
    *(_BYTE *)(v74 + 64) = 1;
    Scaleform::WaitCondition::NotifyAll((Scaleform::WaitCondition *)(v74 + 56));
    Scaleform::Mutex::Unlock((Scaleform::Mutex *)(v74 + 16));
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v74);
    return v71;
  }
  this->pFrameBindData = Value;
  pls = this->pLoadStates.pObject;
  LoadFlags = this->pBindData.pObject->LoadFlags;
  if ( (LoadFlags & 0x100000) == 0 )
  {
    pImportData = Value->pImportData;
    pimport = pImportData;
    v78 = 0i64;
    MovieDefImplAddRef = Scaleform::GFx::MovieDefImpl::BindTaskData::GetMovieDefImplAddRef(this->pBindData.pObject);
    v13 = MovieDefImplAddRef;
    v96 = MovieDefImplAddRef;
    if ( MovieDefImplAddRef )
    {
      FontLib = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetFontLib(
                                               &MovieDefImplAddRef->Scaleform::GFx::StateBag,
                                               &result);
      if ( *FontLib )
        Scaleform::Render::RenderBuffer::AddRef(*FontLib);
      v78 = (Scaleform::Render::RenderBuffer *)*FontLib;
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
      pImportData = pimport;
    }
    for ( i = 0; i < Value->ImportCount; ++i )
    {
      p_SourceUrl = &pImportData->SourceUrl;
      if ( v78 )
      {
        if ( v13 )
        {
          DefaultFontLibName = Scaleform::GFx::StateBag::GetDefaultFontLibName(&v13->Scaleform::GFx::StateBag);
          Scaleform::String::String(&path2, DefaultFontLibName);
          v17 = v76 | 1;
          v76 |= 1u;
          if ( Scaleform::GFx::MatchFileNames(p_SourceUrl, &path2) )
            goto LABEL_38;
        }
        else
        {
          v17 = v76;
        }
        Scaleform::String::String(&v90, "gfxfontlib.swf");
        v17 |= 2u;
        v76 = v17;
        if ( Scaleform::GFx::MatchFileNames(p_SourceUrl, v18) )
        {
LABEL_38:
          v19 = 1;
          goto LABEL_41;
        }
      }
      else
      {
        v17 = v76;
      }
      v19 = 0;
LABEL_41:
      if ( (v17 & 2) != 0 )
      {
        v76 = v17 & 0xFFFFFFFD;
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v90.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v17 &= ~2u;
      }
      if ( (v17 & 1) != 0 )
      {
        v76 = v17 & 0xFFFFFFFE;
        if ( !_InterlockedDecrement((volatile signed __int32 *)((path2.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      if ( v19 )
      {
        Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImportThroughFontLib(this->pBindData.pObject, pimport);
        goto LABEL_90;
      }
      v20 = (Scaleform::Render::RenderBuffer *)Scaleform::GFx::LoadStates::CloneForImport(pls);
      v80 = v20;
      v100 = v20;
      v21 = LoadFlags | 1;
      v82[0] = (__int64)this->pBindData.pObject->pDefImpl_Unsafe;
      v82[1] = 0i64;
      pLoadStack = this->pLoadStack;
      if ( pLoadStack )
      {
        for ( j = &pLoadStack->pNext; *j; j = &(*j)->pNext )
          pLoadStack = *j;
        pLoadStack->pNext = (Scaleform::GFx::LoaderImpl::LoadStackItem *)v82;
      }
      else
      {
        this->pLoadStack = (Scaleform::GFx::LoaderImpl::LoadStackItem *)v82;
      }
      if ( this->Stripped )
      {
        v24 = (const char *)(p_SourceUrl->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
        if ( (*(_QWORD *)v24 & 0x7FFFFFFFFFFFFFFFui64) > 4
          && !Scaleform::String::CompareNoCase(&v24[(*(_QWORD *)v24 & 0x7FFFFFFFFFFFFFFFi64) + 8], ".swf") )
        {
          loc.Use = File_Import;
          Scaleform::String::String(&loc.FileName, p_SourceUrl);
          Scaleform::String::String(&loc.ParentPath, &pls->RelativePath);
          Scaleform::String::Clear(&loc.FileName);
          Scaleform::String::AppendString(
            &loc.FileName,
            (const char *)((p_SourceUrl->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
            (*(_QWORD *)(p_SourceUrl->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) - 4);
          Scaleform::String::AppendString(&loc.FileName, ".gfx", -1i64);
          v25 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
                  (Scaleform::GFx::LoadStates *)v20,
                  &loc,
                  v21,
                  this->pLoadStack);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                                + 8)) )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                                + 8)) )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          if ( v25 )
            goto LABEL_68;
          v20 = v80;
        }
      }
      v91.Use = File_Import;
      Scaleform::String::String(&v91.FileName, p_SourceUrl);
      Scaleform::String::String(&v91.ParentPath, &pls->RelativePath);
      v25 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
              (Scaleform::GFx::LoadStates *)v20,
              &v91,
              v21,
              this->pLoadStack);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v91.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v91.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_68:
      v26 = (__int64 *)this->pLoadStack;
      if ( v26 == v82 )
      {
        this->pLoadStack = 0i64;
      }
      else if ( v26[1] )
      {
        while ( 1 )
        {
          v27 = (__int64 *)v26[1];
          if ( v27 == v82 )
            break;
          v26 = (__int64 *)v26[1];
          if ( !v27[1] )
            goto LABEL_75;
        }
        v26[1] = v27[1];
      }
LABEL_75:
      if ( !v25 )
        goto LABEL_94;
      FileAttributes = this->pDataDef->pData.pObject->FileAttributes;
      if ( (((unsigned __int8)FileAttributes ^ (__int64)v25->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[3].GetResourceReport(v25)) & 8) != 0 )
      {
        Scaleform::GFx::Resource::Release(v25);
        v35 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)pls->pLog.pObject;
        if ( v35 )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
            v35 + 3,
            "ActionScript version mismatched between main and import %s files",
            (const char *)((p_SourceUrl->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
LABEL_94:
        Scaleform::GFx::MovieBindProcess::FinishBinding(this);
        v36 = this->pBindData.pObject;
        if ( v36 )
          Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(
            v36,
            this->pBindData.pObject->BindState & 0xFFFFFFF0 | 4);
        if ( v80 )
          Scaleform::RefCountImpl::Release(v80);
        if ( v13 && _InterlockedExchangeAdd(&v13->RefCount.Value, 0xFFFFFFFF) == 1 )
        {
          pLib = v13->pLib;
          if ( pLib )
          {
            pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v13);
            v13->pLib = 0i64;
          }
          v13->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v13, 1u);
        }
        if ( v78 )
          Scaleform::RefCountImpl::Release(v78);
        return 4i64;
      }
      v29 = this->pBindData.pObject;
      v30 = v25->pBindData.pObject == v29;
      if ( v25->pBindData.pObject == v29 )
      {
        v31 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)pls->pLog.pObject;
        if ( v31 )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
            v31 + 3,
            "Self recursive import detected in %s",
            (const char *)((p_SourceUrl->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      }
      Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImport(this->pBindData.pObject, pimport, v25, pls, v30);
      v32 = pls->pBindStates.pObject->pImportVisitor.pObject;
      if ( v32 )
      {
        v33 = Scaleform::GFx::MovieDefImpl::BindTaskData::GetMovieDefImplAddRef(this->pBindData.pObject);
        v94 = v33;
        if ( v33 )
          v32->Scaleform::GFx::MovieDef::ImportVisitor::vfptr->Visit(
            &v32->Scaleform::GFx::MovieDef::ImportVisitor,
            v33,
            v25,
            (const char *)((pimport->SourceUrl.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        if ( v33 && !_InterlockedDecrement(&v33->RefCount.Value) )
        {
          v34 = v33->pLib;
          if ( v34 )
          {
            v34->vfptr[1].__vecDelDtor(v34, (unsigned int)v33);
            v33->pLib = 0i64;
          }
          v33->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v33, 1u);
        }
      }
      Scaleform::GFx::Resource::Release(v25);
      if ( v80 )
        Scaleform::RefCountImpl::Release(v80);
LABEL_90:
      pImportData = pimport->pNext.Value;
      pimport = pImportData;
    }
    if ( v13 && !_InterlockedDecrement(&v13->RefCount.Value) )
    {
      v38 = v13->pLib;
      if ( v38 )
      {
        v38->vfptr[1].__vecDelDtor(v38, (unsigned int)v13);
        v13->pLib = 0i64;
      }
      v13->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v13, 1u);
    }
    if ( v78 )
      Scaleform::RefCountImpl::Release(v78);
  }
  pResourceData = Value->pResourceData;
  v40 = this->pBindData.pObject;
  p_ResourceBinding = &v40->ResourceBinding;
  pHeap = v40->pHeap;
  v102 = pHeap;
  v43 = 0;
  if ( !Value->ResourceCount )
  {
LABEL_143:
    if ( Value->FontCount )
    {
      memset(&pheapAddr, 0, sizeof(pheapAddr));
      pFontData = Value->pFontData;
      v53 = 0;
      v103 = 0;
      while ( v53 < Value->FontCount )
      {
        pdata.pResource.pObject = 0i64;
        pdata.pBinding = 0i64;
        BindIndex = pFontData->BindIndex;
        if ( p_ResourceBinding->Frozen && BindIndex < p_ResourceBinding->ResourceCount )
        {
          v55 = &p_ResourceBinding->pResources[BindIndex];
          if ( v55->pResource.pObject )
            _InterlockedExchangeAdd(&v55->pResource.pObject->RefCount.Value, 1u);
          v56 = (Scaleform::GFx::FontResource *)v55->pResource.pObject;
          pdata = *v55;
        }
        else
        {
          Scaleform::GFx::ResourceBinding::GetResourceData_Locked(p_ResourceBinding, &pdata, BindIndex);
          v56 = (Scaleform::GFx::FontResource *)pdata.pResource.pObject;
        }
        if ( !v56 )
          goto LABEL_160;
        Scaleform::GFx::FontResource::ResolveTextureGlyphs(v56);
        v57 = pheapAddr.Size + 1;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v57 <= pheapAddr.Policy.Capacity )
            goto LABEL_158;
          v58 = v57 + (v57 >> 2);
        }
        else
        {
          if ( v57 >= pheapAddr.Policy.Capacity >> 1 )
            goto LABEL_158;
          v58 = pheapAddr.Size + 1;
        }
        Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v58);
LABEL_158:
        pheapAddr.Size = v57;
        v59 = &pheapAddr.Data[v57 - 1];
        v53 = v103;
        if ( v59 )
          v59->HeapTypeBits = (unsigned __int64)v56;
LABEL_160:
        if ( v56 && !_InterlockedDecrement(&v56->RefCount.Value) )
        {
          v60 = pdata.pResource.pObject;
          v61 = pdata.pResource.pObject->pLib;
          if ( v61 )
          {
            v61->vfptr[1].__vecDelDtor(v61, (unsigned int)pdata.pResource.pObject);
            v60->pLib = 0i64;
          }
          v60->vfptr->__vecDelDtor(v60, 1u);
        }
        v103 = ++v53;
        pFontData = pFontData->pNext.Value;
      }
      if ( pheapAddr.Data )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    this->pBindData.pObject->BytesLoaded = Value->BytesLoaded;
    if ( ++this->pBindData.pObject->BindingFrame == 1 )
    {
      v62 = this->pBindData.pObject;
      if ( v62 )
        Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v62, this->pBindData.pObject->BindState | 0x100);
    }
    v63 = this->pBindData.pObject;
    if ( v63->BindingFrame == this->pDataDef->vfptr[2].GetResourceTypeCode(this->pDataDef) )
    {
      this->pBindData.pObject->BytesLoaded = this->pDataDef->pData.pObject->Header.FileLength;
      Scaleform::GFx::MovieBindProcess::FinishBinding(this);
      v64 = this->pBindData.pObject;
      if ( v64 )
        Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(
          v64,
          this->pBindData.pObject->BindState & 0xFFFFFDF0 | 0x202);
    }
    v104 = pls->pProgressHandler.pObject;
    if ( v104 )
    {
      v65 = this->pBindData.pObject;
      v66 = v65->pDataDef.pObject;
      FileLength = v66->pData.pObject->Header.FileLength;
      v68 = (Scaleform::String *)v66->pData.pObject;
      v69 = v66->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr[2].GetResourceTypeCode(v66);
      BindingFrame = v65->BindingFrame;
      LODWORD(v65) = v65->BytesLoaded;
      Scaleform::String::String(&v85, v68 + 9);
      v86 = (int)v65;
      v87 = FileLength;
      v88 = BindingFrame;
      v89 = v69;
      v104->vfptr[1].__vecDelDtor(v104, (unsigned int)&v85);
      if ( _InterlockedExchangeAdd(
             (volatile signed __int32 *)((v85.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
             0xFFFFFFFF) == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    return this->pBindData.pObject->BindState & 0xF;
  }
  while ( !pResourceData->Data.pInterface )
  {
LABEL_129:
    ++v43;
    pResourceData = pResourceData->pNext.Value;
    if ( v43 >= Value->ResourceCount )
      goto LABEL_143;
  }
  bd.pBinding = p_ResourceBinding;
  bd.pResource.pObject = 0i64;
  if ( !this->pBindData.pObject->BindingCanceled
    && pResourceData->Data.pInterface
    && pResourceData->Data.pInterface->vfptr->CreateResource(
         pResourceData->Data.pInterface,
         pResourceData->Data.hData,
         &bd,
         pls,
         pHeap) )
  {
    if ( this->pImagePacker.pObject
      && (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))bd.pResource.pObject->vfptr->GetResourceTypeCode)(bd.pResource.pObject) & 0xFF00) == 256
      && (unsigned __int8)bd.pResource.pObject->vfptr->GetResourceTypeCode(bd.pResource.pObject) == 1 )
    {
      ((void (__fastcall *)(Scaleform::GFx::ImagePacker *, Scaleform::GFx::ResourceDataNode *, Scaleform::GFx::Resource *))this->pImagePacker.pObject->vfptr[3].__vecDelDtor)(
        this->pImagePacker.pObject,
        pResourceData,
        bd.pResource.pObject);
    }
    goto LABEL_123;
  }
  if ( !this->pBindData.pObject->BindingCanceled )
  {
LABEL_123:
    Scaleform::GFx::ResourceBinding::SetBindData(p_ResourceBinding, pResourceData->BindIndex, &bd);
    v44 = bd.pResource.pObject;
    if ( bd.pResource.pObject && !_InterlockedDecrement(&bd.pResource.pObject->RefCount.Value) )
    {
      v45 = v44->pLib;
      if ( v45 )
      {
        v45->vfptr[1].__vecDelDtor(v45, (unsigned int)v44);
        v44->pLib = 0i64;
      }
      v44->vfptr->__vecDelDtor(v44, 1u);
    }
    pHeap = v102;
    goto LABEL_129;
  }
  Scaleform::GFx::MovieBindProcess::FinishBinding(this);
  v46 = this->pBindData.pObject;
  if ( v46 )
    Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v46, this->pBindData.pObject->BindState & 0xFFFFFFF0 | 3);
  v47 = this->pBindData.pObject;
  v48 = (__int64)v47->pBindUpdate.pObject;
  if ( v48 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v47->pBindUpdate.pObject);
  v95 = v48;
  v49 = (Scaleform::Render::RenderBuffer *)this->pBindData.pObject;
  if ( v49 )
    Scaleform::RefCountImpl::Release(v49);
  this->pBindData.pObject = 0i64;
  v97 = v48 + 16;
  Scaleform::Mutex::DoLock((Scaleform::Mutex *)(v48 + 16));
  *(_BYTE *)(v48 + 64) = 1;
  Scaleform::WaitCondition::NotifyAll((Scaleform::WaitCondition *)(v48 + 56));
  Scaleform::Mutex::Unlock((Scaleform::Mutex *)(v48 + 16));
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v48);
  v50 = bd.pResource.pObject;
  if ( bd.pResource.pObject && _InterlockedExchangeAdd(&bd.pResource.pObject->RefCount.Value, 0xFFFFFFFF) == 1 )
  {
    v51 = v50->pLib;
    if ( v51 )
    {
      v51->vfptr[1].__vecDelDtor(v51, (unsigned int)v50);
      v50->pLib = 0i64;
    }
    v50->vfptr->__vecDelDtor(v50, 1u);
  }
  return 3i64;
}

// File Line: 1774
// RVA: 0x8CD500
void __fastcall Scaleform::GFx::MovieBindProcess::FinishBinding(Scaleform::GFx::MovieBindProcess *this)
{
  Scaleform::GFx::ImagePacker *pObject; // rcx
  Scaleform::GFx::TempBindData *pTempBindData; // rax
  Scaleform::GFx::MovieDefImpl *MovieDefImplAddRef; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  __int64 v6[4]; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pImagePacker.pObject;
  if ( pObject )
  {
    pTempBindData = this->pTempBindData;
    v6[0] = (__int64)&`Scaleform::GFx::MovieBindProcess::FinishBinding::`5::ImagePackVisitor::`vftable;
    v6[1] = (__int64)pObject;
    v6[2] = (__int64)pTempBindData;
    MovieDefImplAddRef = Scaleform::GFx::MovieDefImpl::BindTaskData::GetMovieDefImplAddRef(this->pBindData.pObject);
    ((void (__fastcall *)(Scaleform::GFx::MovieDefImpl *, __int64 *, __int64))MovieDefImplAddRef->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[6].GetResourceTypeCode)(
      MovieDefImplAddRef,
      v6,
      2i64);
    ((void (__fastcall *)(Scaleform::GFx::ImagePacker *))this->pImagePacker.pObject->vfptr[5].__vecDelDtor)(this->pImagePacker.pObject);
    if ( !_InterlockedDecrement(&MovieDefImplAddRef->RefCount.Value) )
    {
      pLib = MovieDefImplAddRef->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)MovieDefImplAddRef);
        MovieDefImplAddRef->pLib = 0i64;
      }
      MovieDefImplAddRef->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(
        MovieDefImplAddRef,
        1u);
    }
    v6[0] = (__int64)&Scaleform::GFx::MovieDef::ResourceVisitor::`vftable;
  }
  this->pBindData.pObject->ResourceBinding.Frozen = 1;
}

// File Line: 1786
// RVA: 0x9196A0
void __fastcall Scaleform::GFx::MovieBindProcess::FinishBinding_::_5_::ImagePackVisitor::Visit(
        Scaleform::GFx::MovieDef *pmovieDef,
        Scaleform::GFx::Resource *presource,
        __int64 rid,
        const char *pexportName,
        char *str1)
{
  __int64 v7; // rax
  Scaleform::GFx::ResourceLibBase *pLib; // rbx
  __int64 v9; // rax
  __int64 v10; // rdx
  bool v11; // di
  bool v12; // al

  v7 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, const char *))(**(_QWORD **)&pmovieDef->RefCount.Value
                                                                         + 32i64))(
         *(_QWORD *)&pmovieDef->RefCount.Value,
         rid,
         rid,
         pexportName);
  pLib = pmovieDef->pLib;
  v9 = Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::findIndex<unsigned int>(
         (Scaleform::HashSetBase<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int> > > *)pLib,
         (const unsigned int *)(v7 + 16));
  if ( v9 < 0 )
    v10 = 0i64;
  else
    v10 = (__int64)&pLib->vfptr[3 * v9 + 4];
  v11 = v10 == 0;
  v12 = str1 && (strstr(str1, "-forcepack") || strstr(str1, ".forcepack"));
  if ( v11 || v12 )
    (*(void (__fastcall **)(_QWORD, __int64, char *))(**(_QWORD **)&pmovieDef->RefCount.Value + 16i64))(
      *(_QWORD *)&pmovieDef->RefCount.Value,
      rid,
      str1);
}

// File Line: 1808
// RVA: 0x8C0E20
Scaleform::GFx::MemoryContext *__fastcall Scaleform::GFx::MovieDefImpl::CreateMemoryContext(
        Scaleform::GFx::MovieDefImpl *this,
        const char *heapName,
        Scaleform::GFx::MemoryParams *memParams,
        bool debugHeap)
{
  Scaleform::GFx::ASSupport *pObject; // rbx
  Scaleform::Ptr<Scaleform::GFx::ASSupport> result; // [rsp+20h] [rbp-18h] BYREF
  __int64 v10; // [rsp+28h] [rbp-10h]

  v10 = -2i64;
  pObject = Scaleform::GFx::MovieDefImpl::GetASSupport(this, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( pObject )
    return (Scaleform::GFx::MemoryContext *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, const char *, Scaleform::GFx::MemoryParams *, bool))pObject->vfptr[3].__vecDelDtor)(
                                              pObject,
                                              heapName,
                                              memParams,
                                              debugHeap);
  else
    return 0i64;
}

// File Line: 1821
// RVA: 0x8C0450
Scaleform::GFx::Movie *__fastcall Scaleform::GFx::MovieDefImpl::CreateInstance(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MemoryParams *memParams,
        bool initFirstFrame,
        Scaleform::GFx::ActionControl *actionControl,
        Scaleform::Render::ThreadCommandQueue *queue)
{
  const char *v9; // rax
  const char *ShortFilename; // rax
  __int64 v11; // rax
  Scaleform::Render::RenderBuffer *v12; // rsi
  __int64 v13; // rbx
  Scaleform::String v15; // [rsp+60h] [rbp+8h] BYREF

  v9 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[3].__vecDelDtor)(this);
  ShortFilename = Scaleform::GetShortFilename(v9);
  Scaleform::String::String(&v15, "MovieView \"", ShortFilename, "\"");
  v11 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, unsigned __int64, Scaleform::GFx::MemoryParams *, bool))this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[5].GetResourceTypeCode)(
          this,
          (v15.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
          memParams,
          (this->pBindData.pObject->LoadFlags & 0x10000000) != 0);
  v12 = (Scaleform::Render::RenderBuffer *)v11;
  if ( v11 )
  {
    v13 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, __int64, bool, Scaleform::GFx::ActionControl *, Scaleform::Render::ThreadCommandQueue *))this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[5].GetResourceReport)(
            this,
            v11,
            initFirstFrame,
            actionControl,
            queue);
    Scaleform::RefCountImpl::Release(v12);
  }
  else
  {
    v13 = 0i64;
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v15.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return (Scaleform::GFx::Movie *)v13;
}

// File Line: 1838
// RVA: 0x8C0540
Scaleform::GFx::Movie *__fastcall Scaleform::GFx::MovieDefImpl::CreateInstance(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MemoryContext *memContext,
        bool initFirstFrame,
        Scaleform::GFx::ActionControl *actionControl,
        Scaleform::Render::ThreadCommandQueue *queue)
{
  Scaleform::GFx::ASSupport *pObject; // rbx
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rdx
  __int64 v13; // r9
  Scaleform::GFx::Resource *v14; // rax
  Scaleform::Render::RenderBuffer *v15; // rbx
  __int64 *v17; // rsi
  __int64 v18; // rbx
  __int64 v19; // rax
  Scaleform::Ptr<Scaleform::GFx::ASSupport> result; // [rsp+20h] [rbp-28h] BYREF
  __int64 v21; // [rsp+28h] [rbp-20h]
  Scaleform::Render::RenderBuffer *v22; // [rsp+30h] [rbp-18h]

  v21 = -2i64;
  pObject = Scaleform::GFx::MovieDefImpl::GetASSupport(this, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( !pObject )
    return 0i64;
  v10 = (__int64)pObject->vfptr[1].__vecDelDtor(pObject, (unsigned int)memContext);
  v11 = v10;
  if ( !v10 )
    return 0i64;
  if ( actionControl )
    (*(void (__fastcall **)(__int64, __int64, Scaleform::GFx::ActionControl *))(*(_QWORD *)(v10 + 16) + 16i64))(
      v10 + 16,
      3i64,
      actionControl);
  if ( !(*(unsigned __int8 (__fastcall **)(_QWORD, Scaleform::GFx::MovieDefImpl *))(**(_QWORD **)(v11 + 24) + 136i64))(
          *(_QWORD *)(v11 + 24),
          this) )
  {
    if ( !_InterlockedDecrement((volatile signed __int32 *)(v11 + 8)) )
    {
      v14 = (Scaleform::GFx::Resource *)(*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(v11 + 24) + 464i64))(*(_QWORD *)(v11 + 24));
      v15 = (Scaleform::Render::RenderBuffer *)v14;
      if ( v14 )
        Scaleform::Render::RenderBuffer::AddRef(v14);
      v22 = v15;
      (**(void (__fastcall ***)(__int64, __int64))v11)(v11, 1i64);
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
  if ( initFirstFrame )
  {
    LOBYTE(v13) = 1;
    (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64))(*(_QWORD *)v11 + 192i64))(v11, v12, 0i64, v13);
  }
  return (Scaleform::GFx::Movie *)v11;
}

// File Line: 1889
// RVA: 0x8949D0
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::BindTaskData(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::MemoryHeap *pheap,
        Scaleform::GFx::MovieDataDef *pdataDef,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        unsigned int loadFlags,
        bool fullyLoaded)
{
  Scaleform::GFx::LoadUpdateSync *v9; // r14
  char v10; // bp
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // rdi
  bool v12; // bl
  Scaleform::GFx::LoadUpdateSync *v13; // rax
  Scaleform::GFx::LoadUpdateSync *v14; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::String url; // [rsp+88h] [rbp+10h] BYREF
  void *p_ImportSourceMovies; // [rsp+90h] [rbp+18h]
  void *p_BoundShapeMeshProviders; // [rsp+98h] [rbp+20h]

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
  p_ResourceBinding = &this->ResourceBinding;
  p_ImportSourceMovies = &this->ResourceBinding;
  this->ResourceBinding.pHeap = pheap;
  Scaleform::Lock::Lock(&this->ResourceBinding.ResourceLock, 0);
  p_ResourceBinding->pResources = 0i64;
  p_ResourceBinding->ResourceCount = 0;
  p_ResourceBinding->Frozen = 0;
  p_ResourceBinding->pOwnerDefRes = 0i64;
  p_ImportSourceMovies = &this->ImportSourceMovies;
  p_BoundShapeMeshProviders = &this->ImportSourceMovies;
  this->ImportSourceMovies.Data.Data = 0i64;
  this->ImportSourceMovies.Data.Size = 0i64;
  this->ImportSourceMovies.Data.Policy.Capacity = 0i64;
  Scaleform::Lock::Lock(&this->ImportSourceLock, 0);
  this->ResourceImports.Data.Data = 0i64;
  this->ResourceImports.Data.Size = 0i64;
  this->ResourceImports.Data.Policy.Capacity = 0i64;
  p_ImportSourceMovies = &this->BoundShapeMeshProviders;
  p_BoundShapeMeshProviders = &this->BoundShapeMeshProviders;
  this->BoundShapeMeshProviders.mHash.pTable = 0i64;
  this->pBindUpdate.pObject = 0i64;
  EnterCriticalSection(&p_ResourceBinding->ResourceLock.cs);
  p_ResourceBinding->pOwnerDefRes = pdefImpl;
  LeaveCriticalSection(&p_ResourceBinding->ResourceLock.cs);
  this->LoadFlags = loadFlags;
  this->BindingCanceled = 0;
  this->BindingFrame = 0;
  this->BytesLoaded = 0;
  this->BindState = 0;
  v12 = 1;
  if ( pdataDef->MovieType == MT_Image )
  {
    Scaleform::String::String(
      &url,
      (const char *)((pdataDef->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    v10 = 1;
    if ( Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, 0i64, 0i64) )
      v12 = 0;
  }
  if ( (v10 & 1) != 0
    && !_InterlockedDecrement((volatile signed __int32 *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  if ( v12 )
  {
    v13 = (Scaleform::GFx::LoadUpdateSync *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              72i64);
    p_ImportSourceMovies = v13;
    if ( v13 )
    {
      Scaleform::GFx::LoadUpdateSync::LoadUpdateSync(v13);
      v9 = v14;
    }
    pObject = (Scaleform::Render::RenderBuffer *)this->pBindUpdate.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pBindUpdate.pObject = v9;
  }
  if ( fullyLoaded )
  {
    this->BindingFrame = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDataDef *))this->pDataDef.pObject->vfptr[4].__vecDelDtor)(this->pDataDef.pObject);
    this->BytesLoaded = this->pDataDef.pObject->pData.pObject->Header.FileLength;
  }
}

// File Line: 1919
// RVA: 0x8A3340
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::~BindTaskData(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this)
{
  Scaleform::GFx::LoadUpdateSync *pObject; // rcx
  Scaleform::GFx::LoadUpdateSync *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::GFx::MovieDataDef *v5; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieDefImpl::BindTaskData::`vftable;
  pObject = this->pBindUpdate.pObject;
  if ( pObject )
    Scaleform::Mutex::DoLock(&pObject->mMutex);
  Scaleform::GFx::ResourceBinding::Destroy(&this->ResourceBinding);
  v3 = this->pBindUpdate.pObject;
  if ( v3 )
    Scaleform::Mutex::Unlock(&v3->mMutex);
  v4 = (Scaleform::Render::RenderBuffer *)this->pBindUpdate.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ShapeMeshProvider *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF>>::Clear(&this->BoundShapeMeshProviders.mHash);
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>>::DestructArray(
    this->ResourceImports.Data.Data,
    this->ResourceImports.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->ResourceImports.Data.Data);
  Scaleform::Lock::~Lock(&this->ImportSourceLock.cs);
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>>::DestructArray(
    this->ImportSourceMovies.Data.Data,
    this->ImportSourceMovies.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->ImportSourceMovies.Data.Data);
  Scaleform::GFx::ResourceBinding::Destroy(&this->ResourceBinding);
  Scaleform::Lock::~Lock(&this->ResourceBinding.ResourceLock.cs);
  v5 = this->pDataDef.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount.Value) )
  {
    pLib = v5->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v5);
      v5->pLib = 0i64;
    }
    v5->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v5, 1u);
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 1941
// RVA: 0x8EE9F0
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::OnMovieDefRelease(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this)
{
  Scaleform::Lock *p_ResourceLock; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rdi
  Scaleform::GFx::LoadUpdateSync *v4; // rbx

  p_ResourceLock = &this->ResourceBinding.ResourceLock;
  EnterCriticalSection(&this->ResourceBinding.ResourceLock.cs);
  this->ResourceBinding.pOwnerDefRes = 0i64;
  LeaveCriticalSection(&p_ResourceLock->cs);
  EnterCriticalSection(&this->ImportSourceLock.cs);
  this->pDefImpl_Unsafe = 0i64;
  LeaveCriticalSection(&this->ImportSourceLock.cs);
  if ( (this->BindState & 0xF) <= 1 )
    this->BindingCanceled = 1;
  pObject = this->pDataDef.pObject->pData.pObject;
  v4 = pObject->pFrameUpdate.pObject;
  if ( v4 )
  {
    Scaleform::Mutex::DoLock(&v4->mMutex);
    Scaleform::WaitCondition::NotifyAll(&pObject->pFrameUpdate.pObject->WC);
    Scaleform::Mutex::Unlock(&v4->mMutex);
  }
}

// File Line: 1959
// RVA: 0x8DB4E0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::GetMovieDefImplAddRef(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this)
{
  Scaleform::GFx::MovieDefImpl *pDefImpl_Unsafe; // rdx
  signed __int32 Value; // eax
  Scaleform::GFx::MovieDefImpl *v4; // rbx
  Scaleform::Lock *lpCriticalSection; // [rsp+40h] [rbp+8h]

  lpCriticalSection = &this->ImportSourceLock;
  EnterCriticalSection(&this->ImportSourceLock.cs);
  pDefImpl_Unsafe = this->pDefImpl_Unsafe;
  if ( pDefImpl_Unsafe && (Value = pDefImpl_Unsafe->RefCount.Value) != 0 )
  {
    while ( Value != _InterlockedCompareExchange(&pDefImpl_Unsafe->RefCount.Value, Value + 1, Value) )
    {
      Value = pDefImpl_Unsafe->RefCount.Value;
      if ( !Value )
        goto LABEL_7;
    }
    v4 = this->pDefImpl_Unsafe;
  }
  else
  {
LABEL_7:
    v4 = 0i64;
  }
  LeaveCriticalSection(&lpCriticalSection->cs);
  return v4;
}

// File Line: 1970
// RVA: 0x906690
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        volatile unsigned int newState)
{
  Scaleform::GFx::LoadUpdateSync *pObject; // rbx

  pObject = this->pBindUpdate.pObject;
  if ( pObject )
  {
    Scaleform::Mutex::DoLock(&pObject->mMutex);
    this->BindState = newState;
    Scaleform::WaitCondition::NotifyAll(&this->pBindUpdate.pObject->WC);
    Scaleform::Mutex::Unlock(&pObject->mMutex);
  }
  else
  {
    this->BindState = newState;
  }
}

// File Line: 1988
// RVA: 0x91A020
bool __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::WaitForBindStateFlags(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        unsigned int flags)
{
  Scaleform::GFx::LoadUpdateSync *pObject; // rcx
  Scaleform::Mutex *p_mMutex; // [rsp+40h] [rbp+8h]

  pObject = this->pBindUpdate.pObject;
  if ( pObject )
  {
    p_mMutex = &pObject->mMutex;
    Scaleform::Mutex::DoLock(&pObject->mMutex);
    while ( (this->BindState & 0xF) < 3 )
    {
      if ( (this->BindState & flags) != 0 )
        break;
      Scaleform::WaitCondition::Wait(&this->pBindUpdate.pObject->WC, &this->pBindUpdate.pObject->mMutex, 0xFFFFFFFF);
    }
    Scaleform::Mutex::Unlock(p_mMutex);
  }
  return (this->BindState & flags) != 0;
}

// File Line: 2037
// RVA: 0x903A10
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImport(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::GFx::ImportData *pimport,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::LoadStates *pls,
        bool recursive)
{
  unsigned int v9; // esi
  __int64 v10; // rdi
  Scaleform::GFx::ImportData::Symbol *v11; // rdi
  Scaleform::GFx::LogState *v12; // rcx
  Scaleform::GFx::MovieDataDef *pObject; // rcx
  Scaleform::GFx::Resource *pResource; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::Resource *v16; // rdi
  Scaleform::GFx::ResourceLibBase *v17; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v18; // rdx
  Scaleform::GFx::ResourceLibBase *v19; // rcx
  bool v20; // di
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v21; // rdx
  Scaleform::GFx::ResourceLibBase *v22; // rcx
  Scaleform::GFx::FontDataUseNode *volatile Value; // r13
  Scaleform::GFx::FontDataUseNode *volatile v24; // rsi
  Scaleform::Render::Font *v25; // r15
  Scaleform::GFx::FontDataUseNode *volatile v26; // rdi
  Scaleform::Render::Font *v27; // r14
  int v28; // esi
  const char *v29; // r14
  const char *v30; // rax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v31; // r9
  volatile unsigned int BindIndex; // r8d
  Scaleform::GFx::ResourceBindData *v33; // rdx
  Scaleform::GFx::Resource *v34; // rcx
  Scaleform::GFx::Resource *v35; // rdi
  Scaleform::GFx::ResourceLibBase *v36; // rcx
  Scaleform::GFx::FontDataUseNode *i; // [rsp+20h] [rbp-51h]
  Scaleform::GFx::ResourceHandle phandle; // [rsp+28h] [rbp-49h] BYREF
  Scaleform::GFx::ResourceBindData bd; // [rsp+38h] [rbp-39h] BYREF
  Scaleform::String result; // [rsp+48h] [rbp-29h] BYREF
  Scaleform::GFx::ResourceBindData pdata; // [rsp+50h] [rbp-21h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [rsp+60h] [rbp-11h]
  unsigned int CharacterId; // [rsp+68h] [rbp-9h]
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v44; // [rsp+70h] [rbp-1h]
  Scaleform::GFx::MovieDefImpl *v45; // [rsp+78h] [rbp+7h]
  Scaleform::GFx::MovieDefImpl *v46; // [rsp+80h] [rbp+Fh]
  __int64 v47; // [rsp+88h] [rbp+17h]
  Scaleform::GFx::ResourceId rid; // [rsp+D8h] [rbp+67h] BYREF

  v47 = -2i64;
  v9 = 0;
  if ( pimport->Imports.Data.Size )
  {
    v10 = 0i64;
    do
    {
      v11 = &pimport->Imports.Data.Data[v10];
      pdata.pResource.pObject = 0i64;
      pdata.pBinding = 0i64;
      if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(pdefImpl, &pdata, &v11->SymbolName, 0i64) )
      {
        CharacterId = v11->CharacterId;
        phandle.HType = RH_Pointer;
        phandle.pResource = 0i64;
        pObject = this->pDataDef.pObject;
        rid.Id = CharacterId;
        if ( (unsigned __int8)Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                                pObject->pData.pObject,
                                &phandle,
                                &rid) )
          Scaleform::GFx::ResourceBinding::SetBindData(&this->ResourceBinding, phandle.BindIndex, &pdata);
        if ( phandle.HType == RH_Pointer
          && phandle.pResource
          && !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
        {
          pResource = phandle.pResource;
          pLib = phandle.pResource->pLib;
          if ( pLib )
          {
            pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)phandle.pResource);
            pResource->pLib = 0i64;
          }
          pResource->vfptr->__vecDelDtor(pResource, 1u);
        }
      }
      else
      {
        v12 = pls->pLog.pObject;
        if ( v12 )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
            &v12->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "Import failed - resource %s is not exported from movie %s",
            (const char *)((v11->SymbolName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
            (const char *)((pimport->SourceUrl.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      }
      v16 = pdata.pResource.pObject;
      if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
      {
        v17 = v16->pLib;
        if ( v17 )
        {
          v17->vfptr[1].__vecDelDtor(v17, (unsigned int)v16);
          v16->pLib = 0i64;
        }
        v16->vfptr->__vecDelDtor(v16, 1u);
      }
      v10 = ++v9;
    }
    while ( v9 < pimport->Imports.Data.Size );
  }
  if ( !recursive )
  {
    lpCriticalSection = &this->ImportSourceLock.cs;
    EnterCriticalSection(&this->ImportSourceLock.cs);
    if ( pdefImpl )
      _InterlockedExchangeAdd(&pdefImpl->RefCount.Value, 1u);
    v45 = pdefImpl;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->ImportSourceMovies.Data,
      &this->ImportSourceMovies,
      this->ImportSourceMovies.Data.Size + 1);
    v44 = &this->ImportSourceMovies.Data.Data[this->ImportSourceMovies.Data.Size - 1];
    v18 = v44;
    if ( v44 )
    {
      if ( pdefImpl )
        _InterlockedExchangeAdd(&pdefImpl->RefCount.Value, 1u);
      v18->pObject = pdefImpl;
    }
    if ( pdefImpl && !_InterlockedDecrement(&pdefImpl->RefCount.Value) )
    {
      v19 = pdefImpl->pLib;
      if ( v19 )
      {
        v19->vfptr[1].__vecDelDtor(v19, (unsigned int)pdefImpl);
        pdefImpl->pLib = 0i64;
      }
      pdefImpl->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(pdefImpl, 1i64);
    }
    LeaveCriticalSection(lpCriticalSection);
    v20 = 0;
    recursive = 0;
    Scaleform::String::ToLower(&pimport->SourceUrl, &result);
    if ( strstr((const char *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), "_glyphs") )
    {
      recursive = 1;
      if ( pdefImpl )
        _InterlockedExchangeAdd(&pdefImpl->RefCount.Value, 1u);
      v46 = pdefImpl;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pls->SubstituteFontMovieDefs.Data,
        &pls->SubstituteFontMovieDefs,
        pls->SubstituteFontMovieDefs.Data.Size + 1);
      v21 = &pls->SubstituteFontMovieDefs.Data.Data[pls->SubstituteFontMovieDefs.Data.Size - 1];
      v44 = v21;
      if ( v21 )
      {
        if ( pdefImpl )
          _InterlockedExchangeAdd(&pdefImpl->RefCount.Value, 1u);
        v21->pObject = pdefImpl;
      }
      if ( pdefImpl && !_InterlockedDecrement(&pdefImpl->RefCount.Value) )
      {
        v22 = pdefImpl->pLib;
        if ( v22 )
        {
          v22->vfptr[1].__vecDelDtor(v22, (unsigned int)pdefImpl);
          pdefImpl->pLib = 0i64;
        }
        pdefImpl->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(pdefImpl, 1i64);
      }
      v20 = recursive;
    }
    Value = this->pDataDef.pObject->pData.pObject->BindData.pFonts.Value;
    v24 = pdefImpl->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pFonts.Value;
    for ( i = v24; Value; Value = Value->pNext.Value )
    {
      v25 = Value->pFontData.pObject;
      if ( !((unsigned int (__fastcall *)(Scaleform::Render::Font *))v25->vfptr[18].__vecDelDtor)(v25) || v20 )
      {
        v26 = v24;
        if ( v24 )
        {
          while ( 1 )
          {
            v27 = v26->pFontData.pObject;
            if ( ((unsigned int (__fastcall *)(Scaleform::Render::Font *))v27->vfptr[18].__vecDelDtor)(v27) )
            {
              v28 = v27->Flags & 0x303;
              v29 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v27->vfptr[1].__vecDelDtor)(v27);
              if ( (v25->Flags & (v28 & 0x10 | ((v28 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v28 & 0x313) )
              {
                v30 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v25->vfptr[1].__vecDelDtor)(v25);
                if ( !Scaleform::String::CompareNoCase(v30, v29) )
                  break;
              }
            }
            v26 = v26->pNext.Value;
            if ( !v26 )
              goto LABEL_67;
          }
          bd.pResource.pObject = 0i64;
          bd.pBinding = 0i64;
          v31 = pdefImpl->pBindData.pObject;
          BindIndex = v26->BindIndex;
          if ( v31->ResourceBinding.Frozen && BindIndex < v31->ResourceBinding.ResourceCount )
          {
            v33 = &v31->ResourceBinding.pResources[BindIndex];
            if ( v33->pResource.pObject )
              _InterlockedExchangeAdd(&v33->pResource.pObject->RefCount.Value, 1u);
            v34 = v33->pResource.pObject;
            bd = *v33;
          }
          else
          {
            Scaleform::GFx::ResourceBinding::GetResourceData_Locked(&v31->ResourceBinding, &bd, BindIndex);
            v34 = bd.pResource.pObject;
          }
          if ( v34 )
          {
            Scaleform::GFx::ResourceBinding::SetBindData(&this->ResourceBinding, Value->BindIndex, &bd);
            v34 = bd.pResource.pObject;
          }
          if ( v34 && !_InterlockedDecrement(&v34->RefCount.Value) )
          {
            v35 = bd.pResource.pObject;
            v36 = bd.pResource.pObject->pLib;
            if ( v36 )
            {
              v36->vfptr[1].__vecDelDtor(v36, (unsigned int)bd.pResource.pObject);
              v35->pLib = 0i64;
            }
            v35->vfptr->__vecDelDtor(v35, 1u);
          }
LABEL_67:
          v24 = i;
        }
        v20 = recursive;
      }
    }
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 2192
// RVA: 0x903EF0
char __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImportThroughFontLib(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::GFx::ImportData *pimport)
{
  unsigned int v4; // esi
  __int64 v5; // rbx
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // r14
  Scaleform::GFx::ImportData::Symbol *v7; // rbx
  Scaleform::GFx::FontData *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rdi
  Scaleform::GFx::FontResource *v11; // rax
  Scaleform::GFx::Resource *v12; // rax
  Scaleform::GFx::MovieDataDef *pObject; // rcx
  Scaleform::GFx::Resource *pResource; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::Resource *v16; // rbx
  Scaleform::GFx::ResourceLibBase *v17; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v18; // rdx
  Scaleform::GFx::ResourceHandle phandle; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::ResourceBindData bd; // [rsp+40h] [rbp-18h] BYREF
  void *rid; // [rsp+A0h] [rbp+48h] BYREF
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v23; // [rsp+A8h] [rbp+50h]
  __int64 v24; // [rsp+B0h] [rbp+58h]
  Scaleform::Lock *p_ImportSourceLock; // [rsp+B8h] [rbp+60h]

  v4 = 0;
  if ( pimport->Imports.Data.Size )
  {
    v5 = 0i64;
    p_ResourceBinding = &this->ResourceBinding;
    do
    {
      v7 = &pimport->Imports.Data.Data[v5];
      bd.pResource.pObject = 0i64;
      bd.pBinding = p_ResourceBinding;
      v8 = (Scaleform::GFx::FontData *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                         Scaleform::Memory::pGlobalHeap,
                                         136i64,
                                         0i64);
      rid = v8;
      if ( v8 )
      {
        Scaleform::GFx::FontData::FontData(
          v8,
          (const char *)((v7->SymbolName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          0);
        v10 = v9;
      }
      else
      {
        v10 = 0i64;
      }
      v24 = v10;
      *(_DWORD *)(v10 + 28) |= 0x40u;
      v11 = (Scaleform::GFx::FontResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              64i64);
      rid = v11;
      if ( v11 )
        Scaleform::GFx::FontResource::FontResource(v11, (Scaleform::GFx::Resource *)v10, p_ResourceBinding);
      else
        v12 = 0i64;
      bd.pResource.pObject = v12;
      LODWORD(v23) = v7->CharacterId;
      phandle.HType = RH_Pointer;
      phandle.pResource = 0i64;
      pObject = this->pDataDef.pObject;
      LODWORD(rid) = (_DWORD)v23;
      if ( (unsigned __int8)Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                              pObject->pData.pObject,
                              &phandle,
                              (Scaleform::GFx::ResourceId *)&rid) )
        Scaleform::GFx::ResourceBinding::SetBindData(p_ResourceBinding, phandle.BindIndex, &bd);
      if ( phandle.HType == RH_Pointer
        && phandle.pResource
        && !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
      {
        pResource = phandle.pResource;
        pLib = phandle.pResource->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)phandle.pResource);
          pResource->pLib = 0i64;
        }
        pResource->vfptr->__vecDelDtor(pResource, 1u);
      }
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
      if ( bd.pResource.pObject && !_InterlockedDecrement(&bd.pResource.pObject->RefCount.Value) )
      {
        v16 = bd.pResource.pObject;
        v17 = bd.pResource.pObject->pLib;
        if ( v17 )
        {
          v17->vfptr[1].__vecDelDtor(v17, (unsigned int)bd.pResource.pObject);
          v16->pLib = 0i64;
        }
        v16->vfptr->__vecDelDtor(v16, 1u);
      }
      v5 = ++v4;
    }
    while ( v4 < pimport->Imports.Data.Size );
  }
  p_ImportSourceLock = &this->ImportSourceLock;
  EnterCriticalSection(&this->ImportSourceLock.cs);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->ImportSourceMovies.Data,
    &this->ImportSourceMovies,
    this->ImportSourceMovies.Data.Size + 1);
  v18 = &this->ImportSourceMovies.Data.Data[this->ImportSourceMovies.Data.Size - 1];
  rid = v18;
  v23 = v18;
  if ( v18 )
    v18->pObject = 0i64;
  LeaveCriticalSection(&this->ImportSourceLock.cs);
  return 1;
}

// File Line: 2257
// RVA: 0x8DE0E0
Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *__fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::GetShapeMeshProvider(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *result,
        Scaleform::GFx::AS3::Class *defMeshProv)
{
  Scaleform::Render::ShapeMeshProvider *v5; // rdi
  Scaleform::Lock *p_ImportSourceLock; // rsi
  signed __int64 v7; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ShapeMeshProvider *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeHashF> >::TableType *v8; // rax
  unsigned __int64 *p_SizeMask; // rbx
  Scaleform::Render::ShapeMeshProvider *v10; // rbx
  char v11; // bp
  char v12; // bp
  Scaleform::Render::ShapeMeshProvider *v14; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::AS3::Class *key; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::Lock *v16; // [rsp+88h] [rbp+20h]

  key = defMeshProv;
  v5 = 0i64;
  p_ImportSourceLock = &this->ImportSourceLock;
  v16 = &this->ImportSourceLock;
  EnterCriticalSection(&this->ImportSourceLock.cs);
  v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF>>::findIndexAlt<Scaleform::GFx::ASString>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *)&this->BoundShapeMeshProviders,
         &key);
  if ( v7 < 0
    || (v8 = &this->BoundShapeMeshProviders.mHash.pTable[2 * v7 + 2]) == 0i64
    || (p_SizeMask = &v8->SizeMask,
        v8 == (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ShapeMeshProvider *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeHashF> >::TableType *)-8i64) )
  {
    v14 = 0i64;
    v11 = 2;
    v10 = 0i64;
  }
  else
  {
    if ( *p_SizeMask )
      (*(void (__fastcall **)(unsigned __int64))(*(_QWORD *)(*p_SizeMask + 16) + 8i64))(*p_SizeMask + 16);
    v10 = (Scaleform::Render::ShapeMeshProvider *)*p_SizeMask;
    v14 = v10;
    v11 = 1;
    if ( v10 )
      (*((void (__fastcall **)(Scaleform::Render::MeshProvider *))&v10->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->__vecDelDtor
       + 1))(&v10->Scaleform::Render::MeshProvider);
    v5 = v10;
  }
  result->pObject = v14;
  v12 = v11 | 4;
  if ( (v12 & 2) != 0 )
  {
    v12 &= ~2u;
    if ( v5 )
      v5->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->Release(&v5->Scaleform::Render::MeshProvider);
  }
  if ( (v12 & 1) != 0 && v10 )
    v10->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->Release(&v10->Scaleform::Render::MeshProvider);
  LeaveCriticalSection(&p_ImportSourceLock->cs);
  return result;
}

// File Line: 2265
// RVA: 0x8B2D40
void __fastcall Scaleform::GFx::MovieDefImpl::BindTaskData::AddShapeMeshProvider(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::Render::ShapeMeshProvider *defMeshProv,
        Scaleform::Render::ShapeMeshProvider *resolvedMeshProv)
{
  Scaleform::Lock *p_ImportSourceLock; // rbx
  Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeRef key; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::Render::ShapeMeshProvider *v7; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::Render::ShapeMeshProvider *v8; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::Lock *v9; // [rsp+70h] [rbp+18h]

  v8 = defMeshProv;
  p_ImportSourceLock = &this->ImportSourceLock;
  v9 = &this->ImportSourceLock;
  EnterCriticalSection(&this->ImportSourceLock.cs);
  if ( resolvedMeshProv )
    (*((void (__fastcall **)(Scaleform::Render::MeshProvider *))&resolvedMeshProv->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->__vecDelDtor
     + 1))(&resolvedMeshProv->Scaleform::Render::MeshProvider);
  v7 = resolvedMeshProv;
  key.pFirst = &v8;
  key.pSecond = (Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *)&v7;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ShapeMeshProvider *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeRef>(
    &this->BoundShapeMeshProviders.mHash,
    &this->BoundShapeMeshProviders,
    &key);
  if ( v7 )
    v7->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->Release(&v7->Scaleform::Render::MeshProvider);
  LeaveCriticalSection(&p_ImportSourceLock->cs);
}

// File Line: 2314
// RVA: 0x896F50
void __fastcall Scaleform::GFx::GFxMovieDefImplKey::GFxMovieDefImplKey(
        Scaleform::GFx::GFxMovieDefImplKey *this,
        Scaleform::GFx::MovieDataDef *pdataDef,
        Scaleform::GFx::Resource *pbindStates)
{
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
    Scaleform::Render::RenderBuffer::AddRef(pbindStates);
  this->pBindStates.pObject = (Scaleform::GFx::MovieDefBindStates *)pbindStates;
}

// File Line: 2351
// RVA: 0x8D9850
unsigned __int64 __fastcall Scaleform::GFx::GFxMovieDefImplKeyInterface::GetHashCode(
        Scaleform::GFx::GFxMovieDefImplKeyInterface *this,
        _QWORD *hdata)
{
  _QWORD *v2; // rax

  v2 = (_QWORD *)hdata[3];
  return v2[9] ^ v2[8] ^ v2[7] ^ v2[6] ^ v2[4] ^ v2[3] ^ v2[2] ^ ((v2[9] ^ v2[8] ^ v2[7] ^ v2[6] ^ v2[4] ^ v2[3] ^ v2[2] ^ hdata[2]) >> 7) ^ hdata[2];
}

// File Line: 2356
// RVA: 0x8E7F40
bool __fastcall Scaleform::GFx::GFxMovieDefImplKeyInterface::KeyEquals(
        Scaleform::GFx::GFxMovieDefImplKeyInterface *this,
        _QWORD *hdata,
        Scaleform::GFx::ResourceKey *other)
{
  bool result; // al
  _QWORD *hKeyData; // rcx
  _QWORD *v5; // rcx
  _QWORD *v6; // rdx

  if ( this != other->pKeyInterface )
    return 0;
  hKeyData = other->hKeyData;
  result = 0;
  if ( hdata[2] == hKeyData[2] )
  {
    v5 = (_QWORD *)hKeyData[3];
    v6 = (_QWORD *)hdata[3];
    if ( v6[2] == v5[2]
      && v6[3] == v5[3]
      && v6[4] == v5[4]
      && v6[6] == v5[6]
      && v6[7] == v5[7]
      && v6[8] == v5[8]
      && v6[9] == v5[9] )
    {
      return 1;
    }
  }
  return result;
}

// File Line: 2364
// RVA: 0x159C270
__int64 Scaleform::GFx::_dynamic_initializer_for__GFxMovieDefImplKeyInterface_Instance__()
{
  GFxMovieDefImplKeyInterface_Instance.vfptr = (Scaleform::GFx::ResourceKey::KeyInterfaceVtbl *)&Scaleform::GFx::GFxMovieDefImplKeyInterface::`vftable;
  return atexit((int (__fastcall *)())Scaleform::GFx::_dynamic_atexit_destructor_for__GFxMovieDefImplKeyInterface_Instance__);
}

// File Line: 2369
// RVA: 0x8C1510
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::MovieDefImpl::CreateMovieKey(
        Scaleform::GFx::ResourceKey *result,
        Scaleform::GFx::MovieDataDef *pdataDef,
        Scaleform::GFx::Resource *pbindStates)
{
  Scaleform::Render::RenderBuffer *v6; // rbx
  Scaleform::GFx::GFxMovieDefImplKey *v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rax

  v6 = 0i64;
  v7 = (Scaleform::GFx::GFxMovieDefImplKey *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               32i64,
                                               0i64);
  if ( v7 )
  {
    Scaleform::GFx::GFxMovieDefImplKey::GFxMovieDefImplKey(v7, pdataDef, pbindStates);
    v6 = v8;
  }
  GFxMovieDefImplKeyInterface_Instance.vfptr->AddRef(&GFxMovieDefImplKeyInterface_Instance, v6);
  result->pKeyInterface = &GFxMovieDefImplKeyInterface_Instance;
  result->hKeyData = v6;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  return result;
}

// File Line: 2381
// RVA: 0x8D7550
_BOOL8 __fastcall Scaleform::GFx::MovieDefImpl::GetExportedResource(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::ResourceBindData *pdata,
        Scaleform::String *symbol,
        Scaleform::GFx::MovieDefImpl *ignoreDef)
{
  Scaleform::GFx::ResourceBindData *v4; // rdi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v7; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v8; // rax
  unsigned __int64 v9; // rax
  signed __int64 v10; // rax
  char *v11; // rdx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v12; // rax
  unsigned int BindIndex; // r8d
  Scaleform::GFx::Resource *Resource; // rax
  Scaleform::GFx::Resource *v15; // rsi
  Scaleform::GFx::Resource *v16; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  bool v18; // di
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_ImportSourceLock; // rdi
  unsigned __int64 Size; // r8
  unsigned __int64 v21; // rsi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v22; // rax
  Scaleform::GFx::MovieDefImpl *v23; // rdi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v24; // rdx
  Scaleform::GFx::ResourceLibBase *v25; // rcx
  unsigned int v26; // edi
  unsigned __int64 v27; // rdx
  __int64 v28; // rcx
  Scaleform::GFx::MovieDefImpl *v29; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v30; // rdx
  unsigned __int64 v31; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v32; // rsi
  Scaleform::GFx::MovieDefImpl *v33; // rdi
  Scaleform::GFx::ResourceLibBase *v34; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *Data; // rdx
  unsigned __int64 v36; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v37; // rsi
  Scaleform::GFx::MovieDefImpl *v38; // rdi
  Scaleform::GFx::ResourceLibBase *v39; // rcx
  Scaleform::GFx::Resource *pResource; // rbx
  Scaleform::GFx::ResourceLibBase *v41; // rcx
  char v43; // [rsp+20h] [rbp-39h]
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+28h] [rbp-31h] BYREF
  Scaleform::GFx::ResourceHandle v45; // [rsp+40h] [rbp-19h] BYREF
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_mHash; // [rsp+50h] [rbp-9h]
  Scaleform::String::NoCaseKey key; // [rsp+58h] [rbp-1h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> *p_pheapAddr; // [rsp+60h] [rbp+7h]
  Scaleform::GFx::MovieDataDef::LoadTaskData *v49; // [rsp+68h] [rbp+Fh]
  __int64 v50; // [rsp+70h] [rbp+17h]
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v51; // [rsp+78h] [rbp+1Fh]
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v52; // [rsp+80h] [rbp+27h]
  unsigned __int64 v54; // [rsp+C0h] [rbp+67h]
  unsigned __int64 v55; // [rsp+C0h] [rbp+67h]
  Scaleform::String *symbola; // [rsp+D0h] [rbp+77h]

  symbola = symbol;
  v50 = -2i64;
  v4 = pdata;
  v45.HType = RH_Pointer;
  v45.pResource = 0i64;
  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v7 = 0i64;
  v49 = 0i64;
  if ( pObject->LoadState < LS_LoadFinished )
  {
    v7 = pObject;
    v49 = pObject;
    EnterCriticalSection(&pObject->ResourceLock.cs);
    symbol = symbola;
  }
  v8 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  key.pStr = symbol;
  p_mHash = &v8->Exports.mHash;
  if ( v8->Exports.mHash.pTable
    && (v9 = Scaleform::String::BernsteinHashFunctionCIS(
               (const void *)((symbol->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
               *(_QWORD *)(symbol->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
               0x1505ui64),
        v10 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
                p_mHash,
                &key,
                v9 & p_mHash->pTable->SizeMask),
        v10 >= 0)
    && (v11 = (char *)&p_mHash->pTable[2] + 40 * v10) != 0i64 )
  {
    Scaleform::GFx::ResourceHandle::operator=(&v45, (Scaleform::GFx::ResourceHandle *)(v11 + 8));
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
    v12 = this->pBindData.pObject;
    if ( v45.HType != RH_Index )
    {
      v4->pBinding = &v12->ResourceBinding;
      Resource = Scaleform::GFx::ResourceHandle::GetResource(&v45, &this->pBindData.pObject->ResourceBinding);
      v15 = Resource;
      if ( Resource )
        _InterlockedExchangeAdd(&Resource->RefCount.Value, 1u);
      v16 = v4->pResource.pObject;
      if ( v16 && !_InterlockedDecrement(&v16->RefCount.Value) )
      {
        pLib = v16->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v16);
          v16->pLib = 0i64;
        }
        v16->vfptr->__vecDelDtor(v16, 1u);
      }
      v4 = pdata;
      pdata->pResource.pObject = v15;
      goto LABEL_25;
    }
    if ( v12->ResourceBinding.Frozen )
    {
      BindIndex = v45.BindIndex;
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
      BindIndex = v45.BindIndex;
    }
    Scaleform::GFx::ResourceBinding::GetResourceData_Locked(&v12->ResourceBinding, v4, BindIndex);
    goto LABEL_25;
  }
  p_pheapAddr = &pheapAddr;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  p_ImportSourceLock = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&this->pBindData.pObject->ImportSourceLock;
  p_mHash = p_ImportSourceLock;
  EnterCriticalSection((LPCRITICAL_SECTION)p_ImportSourceLock);
  Size = this->pBindData.pObject->ImportSourceMovies.Data.Size;
  if ( Size > pheapAddr.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &pheapAddr,
      &pheapAddr,
      Size);
  v21 = 0i64;
  v22 = this->pBindData.pObject;
  if ( v22->ImportSourceMovies.Data.Size )
  {
    do
    {
      v23 = v22->ImportSourceMovies.Data.Data[v21].pObject;
      if ( v23 != ignoreDef )
      {
        if ( v23 )
          _InterlockedExchangeAdd(&v23->RefCount.Value, 1u);
        p_pheapAddr = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> *)v23;
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &pheapAddr,
          &pheapAddr,
          pheapAddr.Size + 1);
        v24 = &pheapAddr.Data[pheapAddr.Size - 1];
        v51 = v24;
        v52 = v24;
        if ( v24 )
        {
          if ( v23 )
            _InterlockedExchangeAdd(&v23->RefCount.Value, 1u);
          v24->pObject = v23;
        }
        if ( v23 && !_InterlockedDecrement(&v23->RefCount.Value) )
        {
          v25 = v23->pLib;
          if ( v25 )
          {
            v25->vfptr[1].__vecDelDtor(v25, (unsigned int)v23);
            v23->pLib = 0i64;
          }
          v23->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v23, 1u);
        }
      }
      ++v21;
      v22 = this->pBindData.pObject;
    }
    while ( v21 < v22->ImportSourceMovies.Data.Size );
    p_ImportSourceLock = p_mHash;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)p_ImportSourceLock);
  v26 = 0;
  v27 = pheapAddr.Size;
  if ( !pheapAddr.Size )
  {
LABEL_61:
    Data = pheapAddr.Data;
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
            v39->vfptr[1].__vecDelDtor(v39, (unsigned int)v38);
            v38->pLib = 0i64;
          }
          v38->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v38, 1u);
          v36 = v55;
        }
        --v37;
        v55 = --v36;
      }
      while ( v36 );
      Data = pheapAddr.Data;
    }
    if ( Data )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
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
  if ( !Scaleform::GFx::MovieDefImpl::GetExportedResource(v29, pdata, symbola, 0i64) )
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
          v34->vfptr[1].__vecDelDtor(v34, (unsigned int)v33);
          v33->pLib = 0i64;
        }
        v33->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v33, 1u);
        v31 = v54;
      }
      --v32;
      v54 = --v31;
    }
    while ( v31 );
    v30 = pheapAddr.Data;
  }
  if ( v30 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v18 = 1;
LABEL_72:
  if ( v45.HType == RH_Pointer && v45.pResource && !_InterlockedDecrement(&v45.pResource->RefCount.Value) )
  {
    pResource = v45.pResource;
    v41 = v45.pResource->pLib;
    if ( v41 )
    {
      v41->vfptr[1].__vecDelDtor(v41, (unsigned int)v45.pResource);
      pResource->pLib = 0i64;
    }
    pResource->vfptr->__vecDelDtor(pResource, 1u);
  }
  return v18;
}

// File Line: 2440
// RVA: 0x8C7D30
__int64 __fastcall Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MovieDefImpl *import)
{
  Scaleform::Lock *p_ImportSourceLock; // rbx
  __int64 v5; // rax
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // r8
  unsigned __int8 v7; // di

  p_ImportSourceLock = &this->pBindData.pObject->ImportSourceLock;
  EnterCriticalSection(&p_ImportSourceLock->cs);
  v5 = 0i64;
  pObject = this->pBindData.pObject;
  if ( pObject->ImportSourceMovies.Data.Size )
  {
    while ( pObject->ImportSourceMovies.Data.Data[v5].pObject != import )
    {
      if ( ++v5 >= pObject->ImportSourceMovies.Data.Size )
        goto LABEL_6;
    }
    v7 = 1;
  }
  else
  {
LABEL_6:
    v7 = 0;
  }
  LeaveCriticalSection(&p_ImportSourceLock->cs);
  return v7;
}

// File Line: 2453
// RVA: 0x8DB620
Scaleform::String *__fastcall Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::AS3::Abc::MbiInd *rid)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rcx
  __int64 v5; // rdi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v7; // rsi
  signed __int64 Index; // rax
  __int64 v9; // rax

  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v5 = 0i64;
  v6 = 0i64;
  if ( pObject->LoadState < LS_LoadFinished )
  {
    v6 = pObject;
    EnterCriticalSection(&pObject->ResourceLock.cs);
  }
  v7 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *)&v7->InvExports,
            rid);
  if ( Index >= 0 )
  {
    v9 = (__int64)&v7->InvExports.mHash.pTable[2 * Index + 2];
    if ( v9 )
      v5 = v9 + 8;
  }
  if ( v6 )
    LeaveCriticalSection(&v6->ResourceLock.cs);
  return (Scaleform::String *)v5;
}

// File Line: 2471
// RVA: 0x8D49B0
Scaleform::Ptr<Scaleform::GFx::ASSupport> *__fastcall Scaleform::GFx::MovieDefImpl::GetASSupport(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::Ptr<Scaleform::GFx::ASSupport> *result)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rax
  Scaleform::GFx::StateBag *v4; // rcx
  Scaleform::GFx::Resource *v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Ptr<Scaleform::GFx::ASSupport> resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ASSupport> *v9; // [rsp+48h] [rbp+10h]
  Scaleform::Ptr<Scaleform::GFx::ASSupport> v10; // [rsp+50h] [rbp+18h] BYREF

  v9 = result;
  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v4 = &this->Scaleform::GFx::StateBag;
  if ( (pObject->FileAttributes & 8 | 0x10) >> 3 > 2 )
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
    result->pObject = (Scaleform::GFx::ASSupport *)v5;
  }
  else
  {
    result->pObject = 0i64;
  }
  return result;
}

// File Line: 2496
// RVA: 0x8D6050
Scaleform::GFx::CharacterCreateInfo *__fastcall Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::CharacterCreateInfo *result,
        int *rid)
{
  Scaleform::GFx::MovieDataDef *pObject; // rdx
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // rbp
  Scaleform::GFx::Resource *pResource; // r14
  Scaleform::GFx::CharacterDef *v8; // rdi
  unsigned int BindIndex; // r8d
  __int64 v10; // rbp
  signed __int32 v11; // et0
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::Resource *v13; // rbx
  Scaleform::GFx::ResourceLibBase *v14; // rcx
  Scaleform::GFx::ResourceHandle v16; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::ResourceBindData pdata; // [rsp+38h] [rbp-40h] BYREF
  int v18; // [rsp+80h] [rbp+8h] BYREF
  int v19; // [rsp+88h] [rbp+10h]

  v16.HType = RH_Pointer;
  v16.pResource = 0i64;
  result->pCharDef = 0i64;
  result->pBindDefImpl = 0i64;
  result->pResource = 0i64;
  v19 = *rid;
  pObject = this->pBindData.pObject->pDataDef.pObject;
  v18 = v19;
  if ( !Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
          pObject->pData.pObject,
          &v16,
          (Scaleform::GFx::ResourceId)&v18) )
  {
    pResource = v16.pResource;
    goto LABEL_21;
  }
  p_ResourceBinding = &this->pBindData.pObject->ResourceBinding;
  if ( v16.HType )
  {
    pdata.pResource.pObject = 0i64;
    pdata.pBinding = 0i64;
    if ( p_ResourceBinding->Frozen )
    {
      BindIndex = v16.BindIndex;
      if ( v16.BindIndex < p_ResourceBinding->ResourceCount )
      {
        v10 = (__int64)&p_ResourceBinding->pResources[v16.BindIndex];
        if ( *(_QWORD *)v10 )
          _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v10 + 8i64), 1u);
        v8 = *(Scaleform::GFx::CharacterDef **)v10;
        pdata.pResource.pObject = *(Scaleform::GFx::Resource **)v10;
        p_ResourceBinding = *(Scaleform::GFx::ResourceBinding **)(v10 + 8);
        pdata.pBinding = p_ResourceBinding;
        goto LABEL_11;
      }
    }
    else
    {
      BindIndex = v16.BindIndex;
    }
    Scaleform::GFx::ResourceBinding::GetResourceData_Locked(p_ResourceBinding, &pdata, BindIndex);
    p_ResourceBinding = pdata.pBinding;
    v8 = (Scaleform::GFx::CharacterDef *)pdata.pResource.pObject;
LABEL_11:
    if ( v8 )
    {
      v11 = _InterlockedDecrement(&v8->RefCount.Value);
      v8 = (Scaleform::GFx::CharacterDef *)pdata.pResource.pObject;
      if ( !v11 )
      {
        pLib = pdata.pResource.pObject->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pdata.pResource.pObject);
          v8->pLib = 0i64;
        }
        v8->vfptr->__vecDelDtor(v8, 1u);
      }
    }
    pResource = v16.pResource;
    goto LABEL_17;
  }
  pResource = v16.pResource;
  v8 = (Scaleform::GFx::CharacterDef *)v16.pResource;
LABEL_17:
  if ( v8 )
  {
    result->pResource = v8;
    if ( (((__int64 (__fastcall *)(Scaleform::GFx::CharacterDef *))v8->vfptr->GetResourceTypeCode)(v8) & 0x8000) != 0 )
    {
      result->pBindDefImpl = p_ResourceBinding->pOwnerDefImpl;
      result->pCharDef = v8;
    }
  }
LABEL_21:
  if ( v16.HType == RH_Pointer && pResource && !_InterlockedDecrement(&pResource->RefCount.Value) )
  {
    v13 = v16.pResource;
    v14 = v16.pResource->pLib;
    if ( v14 )
    {
      v14->vfptr[1].__vecDelDtor(v14, (unsigned int)v16.pResource);
      v13->pLib = 0i64;
    }
    v13->vfptr->__vecDelDtor(v13, 1u);
  }
  return result;
}

// File Line: 2529
// RVA: 0x919890
void __fastcall Scaleform::GFx::MovieDefImpl::VisitImportedMovies(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MovieDef::ImportVisitor *visitor)
{
  Scaleform::GFx::MovieDef::ImportVisitor *v2; // rdi
  Scaleform::GFx::ImportData *volatile Value; // r15
  Scaleform::Lock *p_ImportSourceLock; // rbx
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // rax
  unsigned __int64 ImportIndex; // rcx
  Scaleform::GFx::MovieDefImpl *v8; // r12
  unsigned __int64 *p_SourceUrl; // rsi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // rax
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // r14
  __int64 EntryCount; // rdi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v14; // rbx
  bool v15; // zf
  unsigned __int64 v16; // rax
  signed __int64 v17; // rax
  unsigned __int64 v18; // rax
  __int64 v19; // [rsp+20h] [rbp-28h]
  Scaleform::Lock *v20; // [rsp+28h] [rbp-20h]
  Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeRef v21; // [rsp+30h] [rbp-18h] BYREF
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_pmemAddr; // [rsp+90h] [rbp+48h] BYREF
  Scaleform::GFx::MovieDef::ImportVisitor *v23; // [rsp+98h] [rbp+50h]
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > pmemAddr; // [rsp+A0h] [rbp+58h] BYREF
  Scaleform::String::NoCaseKey key; // [rsp+A8h] [rbp+60h] BYREF

  v23 = visitor;
  v19 = -2i64;
  v2 = visitor;
  Value = this->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pImports.Value;
  if ( !Value )
    return;
  p_pmemAddr = &pmemAddr;
  pmemAddr.pTable = 0i64;
  while ( 1 )
  {
    p_ImportSourceLock = &this->pBindData.pObject->ImportSourceLock;
    v20 = p_ImportSourceLock;
    EnterCriticalSection(&p_ImportSourceLock->cs);
    pObject = this->pBindData.pObject;
    ImportIndex = Value->ImportIndex;
    if ( ImportIndex >= pObject->ImportSourceMovies.Data.Size )
      break;
    v8 = pObject->ImportSourceMovies.Data.Data[ImportIndex].pObject;
    LeaveCriticalSection(&p_ImportSourceLock->cs);
    p_SourceUrl = (unsigned __int64 *)&Value->SourceUrl;
    pTable = pmemAddr.pTable;
    if ( pmemAddr.pTable )
    {
      v11 = Scaleform::String::BernsteinHashFunctionCIS(
              (const void *)((*p_SourceUrl & 0xFFFFFFFFFFFFFFFCui64) + 12),
              *(_QWORD *)(*p_SourceUrl & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
              0x1505ui64);
      pTable = pmemAddr.pTable;
      v12 = v11 & pmemAddr.pTable->SizeMask;
      EntryCount = v12;
      v14 = &pmemAddr.pTable[2 * v12 + 1];
      if ( v14->EntryCount != -2i64 && v14->SizeMask == v12 )
      {
        while ( 1 )
        {
          if ( v14->SizeMask == v12 )
          {
            v15 = Scaleform::String::CompareNoCase(
                    (const char *)((v14[1].EntryCount & 0xFFFFFFFFFFFFFFFCui64) + 12),
                    (const char *)((*p_SourceUrl & 0xFFFFFFFFFFFFFFFCui64) + 12)) == 0;
            pTable = pmemAddr.pTable;
            if ( v15 )
              break;
          }
          EntryCount = v14->EntryCount;
          if ( v14->EntryCount == -1i64 )
            goto LABEL_14;
          v14 = &pTable[2 * EntryCount + 1];
        }
        if ( EntryCount >= 0 && pmemAddr.pTable && EntryCount <= (signed __int64)pmemAddr.pTable->SizeMask )
          goto LABEL_23;
      }
LABEL_14:
      v2 = v23;
    }
    if ( v8 )
    {
      ((void (__fastcall *)(Scaleform::GFx::MovieDef::ImportVisitor *, Scaleform::GFx::MovieDefImpl *, Scaleform::GFx::MovieDefImpl *, unsigned __int64, __int64, Scaleform::Lock *))v2->vfptr->Visit)(
        v2,
        this,
        v8,
        (*p_SourceUrl & 0xFFFFFFFFFFFFFFFCui64) + 12,
        v19,
        v20);
      pTable = pmemAddr.pTable;
    }
    LOBYTE(p_pmemAddr) = 1;
    key.pStr = &Value->SourceUrl;
    if ( pTable
      && (v16 = Scaleform::String::BernsteinHashFunctionCIS(
                  (const void *)((*p_SourceUrl & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  *(_QWORD *)(*p_SourceUrl & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                  0x1505ui64),
          v17 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
                  &pmemAddr,
                  &key,
                  v16 & pmemAddr.pTable->SizeMask),
          v17 >= 0)
      && pmemAddr.pTable
      && v17 <= (signed __int64)pmemAddr.pTable->SizeMask )
    {
      LOBYTE(pmemAddr.pTable[2 * v17 + 2].SizeMask) = (_BYTE)p_pmemAddr;
    }
    else
    {
      v21.pFirst = &Value->SourceUrl;
      v21.pSecond = (const bool *)&p_pmemAddr;
      v18 = Scaleform::String::BernsteinHashFunctionCIS(
              (const void *)((*p_SourceUrl & 0xFFFFFFFFFFFFFFFCui64) + 12),
              *(_QWORD *)(*p_SourceUrl & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
              0x1505ui64);
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&pmemAddr,
        &pmemAddr,
        &v21,
        v18);
    }
LABEL_23:
    Value = Value->pNext.Value;
    v2 = v23;
    if ( !Value )
      goto LABEL_26;
  }
  LeaveCriticalSection(&p_ImportSourceLock->cs);
LABEL_26:
  p_pmemAddr = &pmemAddr;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<bool,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,bool,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&pmemAddr);
}

// File Line: 2576
// RVA: 0x919BB0
void __fastcall Scaleform::GFx::MovieDefImpl::VisitResources(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::MovieDef::ResourceVisitor *pvisitor,
        unsigned int visitMask)
{
  Scaleform::GFx::MovieDef::ResourceVisitor *v4; // r15
  Scaleform::GFx::MovieDefImpl *v5; // rsi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v7; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *pTable; // rdx
  unsigned __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *v10; // rcx
  signed __int64 v11; // rdi
  __int64 v12; // rax
  __int64 v13; // r15
  Scaleform::GFx::Resource *Resource; // rax
  Scaleform::GFx::Resource *v15; // r13
  int v16; // esi
  unsigned int v17; // eax
  bool v18; // zf
  unsigned __int64 v19; // rsi
  Scaleform::StringHashLH<Scaleform::GFx::ResourceHandle,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_Exports; // r11
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v21; // rdx
  unsigned __int64 v22; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v23; // rcx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v24; // rdx
  unsigned __int64 SizeMask; // r8
  unsigned __int64 *v26; // r10
  unsigned __int64 *v27; // rdx
  unsigned __int64 v28; // rdx
  _QWORD *v29; // rcx
  _RTL_CRITICAL_SECTION *p_cs; // rbx
  unsigned __int64 Size; // r8
  unsigned __int64 v32; // rdi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v33; // rax
  __int64 v34; // rbx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v35; // rdx
  unsigned __int64 v36; // rbx
  unsigned __int64 i; // rdi
  Scaleform::GFx::MovieDefImpl *v38; // rcx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *Data; // rdx
  unsigned __int64 v40; // rsi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v41; // rdi
  Scaleform::GFx::MovieDefImpl *v42; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  unsigned __int64 v44; // [rsp+20h] [rbp-49h]
  _RTL_CRITICAL_SECTION *v45; // [rsp+30h] [rbp-39h]
  __int64 p_Resources; // [rsp+50h] [rbp-19h]
  unsigned __int64 v47; // [rsp+58h] [rbp-11h]
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+60h] [rbp-9h] BYREF
  int v51; // [rsp+E0h] [rbp+77h] BYREF
  Scaleform::GFx::MovieDataDef::LoadTaskData *v52; // [rsp+E8h] [rbp+7Fh]

  v4 = pvisitor;
  v5 = this;
  if ( (visitMask & 0x803F) == 0 )
    goto LABEL_56;
  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v7 = 0i64;
  v52 = 0i64;
  if ( pObject->LoadState < LS_LoadFinished )
  {
    v7 = pObject;
    v52 = pObject;
    EnterCriticalSection(&pObject->ResourceLock.cs);
  }
  pTable = v5->pBindData.pObject->pDataDef.pObject->pData.pObject->Resources.mHash.pTable;
  if ( pTable )
  {
    v9 = 0i64;
    v10 = pTable + 1;
    do
    {
      if ( v10->EntryCount != -2i64 )
        break;
      ++v9;
      v10 += 2;
    }
    while ( v9 <= pTable->SizeMask );
    p_Resources = (__int64)&v5->pBindData.pObject->pDataDef.pObject->pData.pObject->Resources;
    v47 = v9;
  }
  else
  {
    p_Resources = 0i64;
    v47 = 0i64;
  }
  v11 = v47;
  while ( p_Resources )
  {
    v12 = *(_QWORD *)p_Resources;
    if ( !*(_QWORD *)p_Resources || v11 > *(_QWORD *)(v12 + 8) )
      break;
    v13 = 32 * v11;
    Resource = Scaleform::GFx::ResourceHandle::GetResource(
                 (Scaleform::GFx::ResourceHandle *)(32 * v11 + v12 + 32),
                 &v5->pBindData.pObject->ResourceBinding);
    v15 = Resource;
    if ( !Resource )
      goto LABEL_47;
    v16 = (unsigned __int8)Resource->vfptr->GetResourceTypeCode(Resource);
    v17 = v15->vfptr->GetResourceTypeCode(v15) >> 8;
    switch ( (unsigned __int8)v17 )
    {
      case 1u:
        if ( v16 == 1 )
        {
          v18 = (visitMask & 2) == 0;
        }
        else
        {
          if ( v16 != 2 )
            goto LABEL_46;
          v18 = (visitMask & 4) == 0;
        }
        break;
      case 2u:
        v18 = (visitMask & 1) == 0;
        break;
      case 4u:
        v18 = (visitMask & 0x10) == 0;
        break;
      case 0x83u:
        v18 = (visitMask & 8) == 0;
        break;
      case 0x84u:
        v18 = (visitMask & 0x20) == 0;
        break;
      default:
        goto LABEL_46;
    }
    if ( v18 )
    {
LABEL_46:
      v5 = this;
LABEL_47:
      v4 = pvisitor;
      goto LABEL_48;
    }
    v19 = 0i64;
    p_Exports = &this->pBindData.pObject->pDataDef.pObject->pData.pObject->Exports;
    v21 = p_Exports->mHash.pTable;
    if ( p_Exports->mHash.pTable )
    {
      v22 = 0i64;
      v23 = v21 + 1;
      do
      {
        if ( v23->EntryCount != -2i64 )
          break;
        ++v22;
        v23 = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *)((char *)v23 + 40);
      }
      while ( v22 <= v21->SizeMask );
    }
    else
    {
      p_Exports = 0i64;
      v22 = 0i64;
    }
    while ( p_Exports )
    {
      v24 = p_Exports->mHash.pTable;
      if ( !p_Exports->mHash.pTable )
        break;
      SizeMask = v24->SizeMask;
      if ( (__int64)v22 > (__int64)SizeMask )
        break;
      v26 = &v24[2].SizeMask + 5 * v22;
      if ( *(_DWORD *)v26 == *(_DWORD *)(*(_QWORD *)p_Resources + v13 + 32)
        && v26[1] == *(_QWORD *)(*(_QWORD *)p_Resources + v13 + 40) )
      {
        v19 = (*(&v24[2].EntryCount + 5 * v22) & 0xFFFFFFFFFFFFFFFCui64) + 12;
        break;
      }
      if ( ++v22 <= SizeMask )
      {
        v27 = &v24[1].EntryCount + 5 * v22;
        do
        {
          if ( *v27 != -2i64 )
            break;
          ++v22;
          v27 += 5;
        }
        while ( v22 <= SizeMask );
      }
    }
    v51 = *(_DWORD *)(v13 + *(_QWORD *)p_Resources + 24);
    v4 = pvisitor;
    v44 = v19;
    v5 = this;
    ((void (__fastcall *)(Scaleform::GFx::MovieDef::ResourceVisitor *, Scaleform::GFx::MovieDefImpl *, Scaleform::GFx::Resource *, int *, unsigned __int64))pvisitor->vfptr->Visit)(
      pvisitor,
      this,
      v15,
      &v51,
      v44);
LABEL_48:
    v28 = *(_QWORD *)(*(_QWORD *)p_Resources + 8i64);
    if ( v11 <= (__int64)v28 && ++v11 <= v28 )
    {
      v29 = (_QWORD *)(32 * v11 + *(_QWORD *)p_Resources + 16i64);
      do
      {
        if ( *v29 != -2i64 )
          break;
        ++v11;
        v29 += 4;
      }
      while ( v11 <= v28 );
    }
  }
  if ( v7 )
    LeaveCriticalSection(&v7->ResourceLock.cs);
LABEL_56:
  if ( (visitMask & 0x8000) != 0 )
  {
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    p_cs = &v5->pBindData.pObject->ImportSourceLock.cs;
    v45 = p_cs;
    EnterCriticalSection(p_cs);
    Size = v5->pBindData.pObject->ImportSourceMovies.Data.Size;
    if ( Size )
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        Size);
    v32 = 0i64;
    v33 = v5->pBindData.pObject;
    if ( v33->ImportSourceMovies.Data.Size )
    {
      do
      {
        v34 = (__int64)&v33->ImportSourceMovies.Data.Data[v32];
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,264>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &pheapAddr,
          &pheapAddr,
          pheapAddr.Size + 1);
        v35 = &pheapAddr.Data[pheapAddr.Size - 1];
        if ( v35 )
        {
          if ( *(_QWORD *)v34 )
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v34 + 8i64), 1u);
          v35->pObject = *(Scaleform::GFx::MovieDefImpl **)v34;
        }
        ++v32;
        v33 = v5->pBindData.pObject;
      }
      while ( v32 < v33->ImportSourceMovies.Data.Size );
      p_cs = v45;
    }
    LeaveCriticalSection(p_cs);
    v36 = 0i64;
    for ( i = pheapAddr.Size; v36 < i; ++v36 )
    {
      v38 = pheapAddr.Data[v36].pObject;
      if ( v38 )
        ((void (__fastcall *)(Scaleform::GFx::MovieDefImpl *, Scaleform::GFx::MovieDef::ResourceVisitor *, _QWORD))v38->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[6].GetResourceTypeCode)(
          v38,
          v4,
          visitMask);
    }
    Data = pheapAddr.Data;
    v40 = pheapAddr.Size;
    v41 = &pheapAddr.Data[pheapAddr.Size - 1];
    if ( pheapAddr.Size )
    {
      do
      {
        v42 = v41->pObject;
        if ( v41->pObject && !_InterlockedDecrement(&v42->RefCount.Value) )
        {
          pLib = v42->pLib;
          if ( pLib )
          {
            pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v42);
            v42->pLib = 0i64;
          }
          v42->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v42, 1u);
        }
        --v41;
        --v40;
      }
      while ( v40 );
      Data = pheapAddr.Data;
    }
    if ( Data )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 2688
// RVA: 0x8DD800
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::MovieDefImpl::GetResource(
        Scaleform::GFx::MovieDefImpl *this,
        const char *pexportName)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rcx
  Scaleform::GFx::Resource *Resource; // rsi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v7; // r14
  unsigned __int64 v8; // rax
  signed __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  Scaleform::String v11; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::MovieDataDef::LoadTaskData *v12; // [rsp+60h] [rbp+18h]
  Scaleform::String::NoCaseKey key; // [rsp+68h] [rbp+20h] BYREF

  if ( !pexportName )
    return 0i64;
  Scaleform::String::String(&v11, pexportName);
  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  Resource = 0i64;
  v6 = 0i64;
  v12 = 0i64;
  if ( pObject->LoadState < LS_LoadFinished )
  {
    v6 = pObject;
    v12 = pObject;
    EnterCriticalSection(&pObject->ResourceLock.cs);
  }
  v7 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  key.pStr = &v11;
  if ( v7->Exports.mHash.pTable )
  {
    v8 = Scaleform::String::BernsteinHashFunctionCIS(
           (const void *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
           *(_QWORD *)(v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
           0x1505ui64);
    v9 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
           &v7->Exports.mHash,
           &key,
           v8 & v7->Exports.mHash.pTable->SizeMask);
    if ( v9 >= 0 )
    {
      pTable = v7->Exports.mHash.pTable;
      if ( pTable )
      {
        if ( v9 <= (signed __int64)pTable->SizeMask )
          Resource = Scaleform::GFx::ResourceHandle::GetResource(
                       (Scaleform::GFx::ResourceHandle *)(&pTable[2].SizeMask + 5 * v9),
                       &this->pBindData.pObject->ResourceBinding);
      }
    }
  }
  if ( v6 )
    LeaveCriticalSection(&v6->ResourceLock.cs);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return Resource;
}

// File Line: 2717
// RVA: 0x8D85E0
Scaleform::GFx::FontResource *__fastcall Scaleform::GFx::MovieDefImpl::GetFontResource(
        Scaleform::GFx::MovieDefImpl *this,
        char *pfontName,
        unsigned int styleFlags,
        Scaleform::GFx::MovieDefImpl::SearchInfo *psearchInfo)
{
  Scaleform::GFx::MovieDefImpl *v6; // r12
  Scaleform::GFx::MovieDataDef *pObject; // rbx
  Scaleform::GFx::FontDataUseNode *volatile Value; // rdi
  unsigned int v9; // esi
  unsigned int v10; // r14d
  char *v11; // r13
  Scaleform::Render::Font *v12; // rcx
  const char *v13; // rax
  unsigned int BindIndex; // r8d
  Scaleform::GFx::ResourceBindData *v15; // rdx
  Scaleform::GFx::Resource *v16; // rbx
  Scaleform::GFx::ResourceVtbl *vfptr; // rcx
  signed __int32 v18; // et0
  Scaleform::GFx::Resource *v19; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::StringLH *v22; // rdi
  __int64 v23; // r13
  int v24; // r12d
  Scaleform::GFx::Resource *v25; // r15
  __int64 v26; // r13
  unsigned __int64 v27; // rdi
  __int64 v28; // r14
  __int64 v29; // rbx
  __int64 *v30; // r14
  __int64 v31; // r9
  __int64 v32; // r11
  __int64 v33; // r10
  __int64 v34; // rdx
  __int64 v35; // r8
  unsigned __int64 v36; // rcx
  int *v37; // rcx
  __int64 v38; // rdx
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // rcx
  unsigned int v40; // r8d
  Scaleform::GFx::ResourceBindData *v41; // rcx
  signed __int32 v42; // et0
  Scaleform::GFx::ResourceLibBase *v43; // rcx
  __int16 v44; // ax
  const char *v45; // rax
  Scaleform::GFx::Resource *v46; // rbx
  Scaleform::GFx::ResourceLibBase *v47; // rcx
  Scaleform::GFx::MovieDefImpl::SearchInfo *v48; // r14
  const char *v49; // rax
  Scaleform::GFx::Resource *v50; // rdi
  Scaleform::GFx::ResourceLibBase *v51; // rcx
  __int64 v52; // rax
  __int64 v53; // rbx
  __int64 v54; // rcx
  _RTL_CRITICAL_SECTION *p_cs; // rbx
  unsigned __int64 v56; // rdi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v57; // rax
  Scaleform::GFx::MovieDefImpl *v58; // rcx
  __int64 v59; // rsi
  Scaleform::String *v61; // [rsp+8h] [rbp-41h]
  unsigned int v62; // [rsp+10h] [rbp-39h]
  int v63; // [rsp+18h] [rbp-31h]
  Scaleform::GFx::Resource *index; // [rsp+20h] [rbp-29h]
  Scaleform::GFx::MovieDataDef *v65; // [rsp+28h] [rbp-21h]
  __int64 v66; // [rsp+28h] [rbp-21h]
  Scaleform::GFx::ResourceBindData v67; // [rsp+30h] [rbp-19h] BYREF
  Scaleform::GFx::ResourceBindData pdata; // [rsp+40h] [rbp-9h] BYREF
  __int64 v69; // [rsp+50h] [rbp+7h]
  int v70; // [rsp+58h] [rbp+Fh]
  __int64 v71; // [rsp+60h] [rbp+17h]
  _RTL_CRITICAL_SECTION *v72; // [rsp+68h] [rbp+1Fh]
  Scaleform::GFx::MovieDefImpl *v73; // [rsp+B0h] [rbp+67h]
  char *b; // [rsp+B8h] [rbp+6Fh]
  Scaleform::GFx::MovieDefImpl::SearchInfo *v75; // [rsp+C8h] [rbp+7Fh]

  v71 = -2i64;
  v6 = this;
  pObject = this->pBindData.pObject->pDataDef.pObject;
  v65 = pObject;
  Value = pObject->pData.pObject->BindData.pFonts.Value;
  if ( Value )
  {
    v9 = styleFlags & 0x10 | ((styleFlags & 0x300) != 0 ? 0x300 : 0) | 3;
    v10 = styleFlags & 0x313;
    v11 = b;
    do
    {
      v12 = Value->pFontData.pObject;
      if ( (v12->Flags & v9) == v10 )
      {
        v13 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v12->vfptr[1].__vecDelDtor)(v12);
        if ( !Scaleform::String::CompareNoCase(v13, v11) )
        {
          pdata.pResource.pObject = 0i64;
          pdata.pBinding = 0i64;
          BindIndex = Value->BindIndex;
          if ( v6->pBindData.pObject->ResourceBinding.Frozen
            && BindIndex < v6->pBindData.pObject->ResourceBinding.ResourceCount )
          {
            v15 = &v6->pBindData.pObject->ResourceBinding.pResources[BindIndex];
            if ( v15->pResource.pObject )
              _InterlockedExchangeAdd(&v15->pResource.pObject->RefCount.Value, 1u);
            v16 = v15->pResource.pObject;
            pdata = *v15;
          }
          else
          {
            Scaleform::GFx::ResourceBinding::GetResourceData_Locked(
              &v6->pBindData.pObject->ResourceBinding,
              &pdata,
              BindIndex);
            v16 = pdata.pResource.pObject;
          }
          if ( v16 )
          {
            if ( psearchInfo )
            {
              vfptr = v16[1].vfptr;
              if ( (HIDWORD(vfptr->GetResourceReport) & 0x40) != 0 )
              {
                psearchInfo->Status = FoundInResourcesNoGlyphs;
              }
              else if ( (styleFlags & 3) == 0
                     || (*((unsigned __int8 (__fastcall **)(Scaleform::GFx::ResourceVtbl *))vfptr->__vecDelDtor + 19))(vfptr) )
              {
                psearchInfo->Status = FoundInResources;
              }
              else
              {
                psearchInfo->Status = FoundInResourcesNeedFaux;
              }
            }
            v18 = _InterlockedDecrement(&v16->RefCount.Value);
            v19 = pdata.pResource.pObject;
            if ( !v18 )
            {
              pLib = pdata.pResource.pObject->pLib;
              if ( pLib )
              {
                pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pdata.pResource.pObject);
                v19->pLib = 0i64;
              }
              v19->vfptr->__vecDelDtor(v19, 1u);
            }
            return (Scaleform::GFx::FontResource *)v19;
          }
        }
      }
      Value = Value->pNext.Value;
    }
    while ( Value );
    pfontName = b;
    pObject = v65;
  }
  v22 = (Scaleform::StringLH *)pObject->pData.pObject->BindData.pImports.Value;
  v61 = v22;
  if ( v22 )
  {
    while ( 1 )
    {
      v62 = 0;
      if ( v22[1].HeapTypeBits )
        break;
LABEL_80:
      v22 = (Scaleform::StringLH *)v22[5].pData;
      v61 = v22;
      if ( !v22 )
      {
        v6 = v73;
        goto LABEL_95;
      }
    }
    v23 = 0i64;
    while ( 1 )
    {
      if ( psearchInfo )
        Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::Set<Scaleform::StringLH>(
          &psearchInfo->ImportSearchUrls,
          &psearchInfo->ImportSearchUrls,
          v22 + 3);
      v24 = 0;
      v25 = 0i64;
      index = 0i64;
      v26 = 2 * v23;
      v27 = *(unsigned int *)(v22->HeapTypeBits + 8 * v26 + 8);
      v70 = v27;
      v28 = (__int64)pObject->pData.pObject;
      v29 = 0i64;
      v69 = 0i64;
      if ( *(int *)(v28 + 228) < 2 )
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
      v34 = v33;
      v35 = v31 + 32 * v33 + 16;
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
        pfontName = b;
        v22 = (Scaleform::StringLH *)v61;
        goto LABEL_73;
      }
      v37 = (int *)(v31 + 32 * (v34 + 1));
      if ( !*v37 )
      {
        v38 = *((_QWORD *)v37 + 1);
        if ( v38 )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)(v38 + 8), 1u);
          v29 = v69;
        }
      }
      v24 = *v37;
      v63 = *v37;
      v25 = (Scaleform::GFx::Resource *)*((_QWORD *)v37 + 1);
      index = v25;
      if ( v29 )
        LeaveCriticalSection((LPCRITICAL_SECTION)(v29 + 328));
      p_ResourceBinding = &v73->pBindData.pObject->ResourceBinding;
      if ( !v24 )
      {
        v19 = v25;
        goto LABEL_64;
      }
      v67.pResource.pObject = 0i64;
      v67.pBinding = 0i64;
      if ( p_ResourceBinding->Frozen )
      {
        v40 = (unsigned int)index;
        if ( (unsigned int)index < p_ResourceBinding->ResourceCount )
        {
          v41 = &p_ResourceBinding->pResources[(unsigned int)index];
          if ( v41->pResource.pObject )
            _InterlockedExchangeAdd(&v41->pResource.pObject->RefCount.Value, 1u);
          v19 = v41->pResource.pObject;
          v67 = *v41;
          goto LABEL_58;
        }
      }
      else
      {
        v40 = (unsigned int)index;
      }
      Scaleform::GFx::ResourceBinding::GetResourceData_Locked(p_ResourceBinding, &v67, v40);
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
            v43->vfptr[1].__vecDelDtor(v43, (unsigned int)v67.pResource.pObject);
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
      pfontName = b;
      if ( (v44 & 0xFF00) == 512
        && (HIDWORD(v19[1].vfptr->GetResourceReport) & (styleFlags & 0x10 | ((styleFlags & 0x300) != 0 ? 0x300 : 0) | 3)) == (styleFlags & 0x313) )
      {
        if ( !Scaleform::String::CompareNoCase(
                (const char *)((*(_QWORD *)(v61->HeapTypeBits + 8 * v26) & 0xFFFFFFFFFFFFFFFCui64) + 12),
                b)
          || (v45 = (const char *)(*((__int64 (__fastcall **)(Scaleform::GFx::ResourceVtbl *))v19[1].vfptr->__vecDelDtor
                                   + 1))(v19[1].vfptr),
              !Scaleform::String::CompareNoCase(v45, pfontName)) )
        {
          v48 = v75;
          if ( v75 )
          {
            v49 = (const char *)(v61[3].HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
            if ( (*(_QWORD *)v49 & 0x7FFFFFFFFFFFFFFFui64) < 0xE
              || Scaleform::String::CompareNoCase(&v49[(*(_QWORD *)v49 & 0x7FFFFFFFFFFFFFFFi64) - 2], "gfxfontlib.swf") )
            {
              v48->Status = FoundInImports;
            }
            else
            {
              v48->Status = FoundInImportsFontLib;
            }
            Scaleform::String::operator=(&v48->ImportFoundUrl, v61 + 3);
          }
          if ( !v24 && v25 && !_InterlockedDecrement(&v25->RefCount.Value) )
          {
            v50 = index;
            v51 = index->pLib;
            if ( v51 )
            {
              v51->vfptr[1].__vecDelDtor(v51, (unsigned int)index);
              v50->pLib = 0i64;
            }
            v50->vfptr->__vecDelDtor(v50, 1u);
            return (Scaleform::GFx::FontResource *)v19;
          }
          return (Scaleform::GFx::FontResource *)v19;
        }
      }
LABEL_73:
      if ( !v24 && v25 && !_InterlockedDecrement(&v25->RefCount.Value) )
      {
        v46 = index;
        v47 = index->pLib;
        if ( v47 )
        {
          v47->vfptr[1].__vecDelDtor(v47, (unsigned int)index);
          v46->pLib = 0i64;
        }
        v46->vfptr->__vecDelDtor(v46, 1u);
      }
      v23 = ++v62;
      psearchInfo = v75;
      pObject = v65;
      if ( v62 >= v22[1].HeapTypeBits )
        goto LABEL_80;
    }
  }
LABEL_95:
  v52 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, char *))v6->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[6].GetResourceReport)(
          v6,
          pfontName);
  v53 = v52;
  if ( v52 )
  {
    if ( ((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v52 + 16i64))(v52) & 0xFF00) == 512
      && (*(_DWORD *)(*(_QWORD *)(v53 + 24) + 28i64) & (styleFlags & 0x10 | ((styleFlags & 0x300) != 0 ? 0x300 : 0) | 3)) == (styleFlags & 0x313) )
    {
      if ( psearchInfo )
        psearchInfo->Status = FoundInExports;
      return (Scaleform::GFx::FontResource *)v53;
    }
    goto LABEL_110;
  }
  v54 = *(_QWORD *)(v66 + 64);
  if ( (char)((*(_DWORD *)(v54 + 208) & 8 | 0x10u) >> 3) < 3 || !*(_QWORD *)(v54 + 272) )
  {
LABEL_110:
    if ( psearchInfo )
      psearchInfo->Status = NotFound;
    return 0i64;
  }
  p_cs = &v6->pBindData.pObject->ImportSourceLock.cs;
  v72 = p_cs;
  EnterCriticalSection(p_cs);
  v56 = 0i64;
  v57 = v6->pBindData.pObject;
  if ( !v57->ImportSourceMovies.Data.Size )
  {
LABEL_109:
    LeaveCriticalSection(p_cs);
    goto LABEL_110;
  }
  while ( 1 )
  {
    v58 = v57->ImportSourceMovies.Data.Data[v56].pObject;
    if ( v58 )
    {
      v59 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, char *, _QWORD, Scaleform::GFx::MovieDefImpl::SearchInfo *, Scaleform::GFx::ResourceBinding *))v58->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[7].__vecDelDtor)(
              v58,
              pfontName,
              styleFlags,
              psearchInfo,
              v67.pBinding);
      if ( v59 )
        break;
    }
    ++v56;
    v57 = v6->pBindData.pObject;
    if ( v56 >= v57->ImportSourceMovies.Data.Size )
      goto LABEL_109;
  }
  LeaveCriticalSection(p_cs);
  return (Scaleform::GFx::FontResource *)v59;
}

// File Line: 2882
// RVA: 0x8C9510
void __fastcall Scaleform::GFx::GFxInitImportActions::Execute(
        Scaleform::GFx::GFxInitImportActions *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  __int64 v4; // rbp
  unsigned __int64 ImportIndex; // rdi
  __int64 v6; // rdi

  v4 = *(_QWORD *)(((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(m)
                 + 104);
  ImportIndex = this->ImportIndex;
  EnterCriticalSection((LPCRITICAL_SECTION)(v4 + 152));
  if ( ImportIndex < *(_QWORD *)(v4 + 136) )
  {
    v6 = *(_QWORD *)(*(_QWORD *)(v4 + 128) + 8 * ImportIndex);
    LeaveCriticalSection((LPCRITICAL_SECTION)(v4 + 152));
    if ( v6 )
    {
      if ( *(int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 104) + 24i64) + 64i64) + 488i64) > 0 )
        m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[119].__vecDelDtor(
          m,
          v6);
    }
  }
  else
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)(v4 + 152));
  }
}

