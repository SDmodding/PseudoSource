// File Line: 44
// RVA: 0x8A7B00
void __fastcall Scaleform::GFx::SpriteDef::~SpriteDef(Scaleform::GFx::SpriteDef *this)
{
  unsigned int v2; // ebp
  __int64 v3; // rbx
  Scaleform::GFx::TimelineDef::Frame *v4; // rbx
  unsigned int i; // edi
  Scaleform::GFx::ExecuteTag *v6; // rcx

  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::SpriteDef::`vftable;
  v2 = 0;
  if ( this->Playlist.Data.Size )
  {
    v3 = 0i64;
    do
    {
      v4 = &this->Playlist.Data.Data[v3];
      for ( i = 0; i < v4->TagCount; ++i )
      {
        v6 = v4->pTagPtrList[i];
        v6->vfptr->__vecDelDtor(v6, 0i64);
      }
      v4->pTagPtrList = 0i64;
      v4->TagCount = 0;
      v3 = ++v2;
    }
    while ( v2 < this->Playlist.Data.Size );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pScale9Grid);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Playlist.Data.Data);
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&this->NamedFrames);
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 62
// RVA: 0x8B11D0
void __fastcall Scaleform::GFx::SpriteDef::AddFrameName(
        Scaleform::GFx::SpriteDef *this,
        Scaleform::String *name,
        Scaleform::GFx::LogState *plog)
{
  __int64 LoadingFrame; // r8
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v7; // rax
  unsigned __int64 v8; // r8
  __int64 v9; // rcx
  __int64 v10; // rdx
  char v11; // al
  __int64 v12; // rdx
  char v13; // al
  char v14; // al
  Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+30h] [rbp-18h] BYREF
  int v16; // [rsp+50h] [rbp+8h] BYREF

  LoadingFrame = (unsigned int)this->LoadingFrame;
  if ( (int)LoadingFrame < 0 || (int)LoadingFrame >= this->FrameCount )
  {
    if ( plog )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "AddFrameName(%d, %s) -- frame is out of range (frameCount = %d; skipping",
        LoadingFrame,
        (const char *)((name->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        this->FrameCount);
  }
  else
  {
    v7 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetAlt<Scaleform::String>(
           &this->NamedFrames.mHash,
           name);
    if ( v7 && plog )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "AddFrameName(%d, %s) -- frame name already assigned to frame %d; overriding",
        (unsigned int)this->LoadingFrame,
        (const char *)((name->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        LODWORD(v7->SizeMask));
    if ( Scaleform::String::GetLength(name) )
    {
      v8 = name->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      if ( *(_BYTE *)(v8 + 12) == 95 )
      {
        v9 = 0i64;
        v10 = 0i64;
        while ( 1 )
        {
          v11 = *(_BYTE *)(v8 + v10++ + 12);
          if ( v11 != aUp_1[v10 - 1] )
            break;
          if ( v10 == 4 )
          {
            this->Flags |= 1u;
            goto LABEL_19;
          }
        }
        v12 = 0i64;
        while ( 1 )
        {
          v13 = *(_BYTE *)(v8 + v12++ + 12);
          if ( v13 != aDown_1[v12 - 1] )
            break;
          if ( v12 == 6 )
          {
            this->Flags |= 2u;
            goto LABEL_19;
          }
        }
        while ( 1 )
        {
          v14 = *(_BYTE *)(v8 + v9++ + 12);
          if ( v14 != aOver[v9 - 1] )
            break;
          if ( v9 == 6 )
          {
            this->Flags |= 4u;
            break;
          }
        }
      }
    }
LABEL_19:
    v16 = this->LoadingFrame;
    key.pSecond = (const unsigned int *)&v16;
    key.pFirst = name;
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
      &this->NamedFrames.mHash,
      &this->NamedFrames,
      &key);
  }
}

// File Line: 94
// RVA: 0x8F92B0
void __fastcall Scaleform::GFx::SpriteDef::Read(
        Scaleform::GFx::SpriteDef *this,
        Scaleform::GFx::LoadProcess *p,
        unsigned __int16 *charId)
{
  unsigned __int16 *v3; // rdi
  Scaleform::GFx::LoadProcess *v4; // rsi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 v7; // rcx
  unsigned int v8; // ebp
  __int64 Pos; // r9
  unsigned __int16 v10; // r8
  int v11; // eax
  Scaleform::ArrayLH<Scaleform::GFx::TimelineDef::Frame,264,Scaleform::ArrayDefaultPolicy> *p_Playlist; // r14
  __int64 v13; // r12
  Scaleform::GFx::LoadStates *pObject; // r15
  Scaleform::GFx::ProgressHandler *v15; // r15
  int TagDataOffset; // r14d
  int TagLength; // ebp
  int TagOffset; // esi
  Scaleform::GFx::TagType TagType; // edi
  __int64 v20; // r8
  void (__fastcall *v21)(Scaleform::GFx::LoadProcess *, Scaleform::GFx::TagInfo *); // r8
  __int64 v22; // rax
  signed int v23; // edi
  signed int FilePos; // edx
  unsigned int DataSize; // eax
  __int64 LoadState; // rdx
  __int64 v27; // [rsp+20h] [rbp-88h]
  Scaleform::GFx::TagInfo pTagInfo; // [rsp+38h] [rbp-70h] BYREF
  Scaleform::String v29; // [rsp+48h] [rbp-60h] BYREF
  Scaleform::GFx::TagType v30; // [rsp+50h] [rbp-58h]
  int v31; // [rsp+54h] [rbp-54h]
  int v32; // [rsp+58h] [rbp-50h]
  int v33; // [rsp+5Ch] [rbp-4Ch]
  unsigned int v34; // [rsp+B0h] [rbp+8h]
  Scaleform::String src; // [rsp+C8h] [rbp+20h] BYREF

  v3 = charId;
  v4 = p;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v7 = pAltStream->Stream.TagStackEntryCount - 1;
  if ( (unsigned int)v7 >= 2 )
    v8 = 0;
  else
    v8 = pAltStream->Stream.TagStack[v7];
  v34 = v8;
  p->LoadState = LS_LoadingSprite;
  p->pTimelineDef = this;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v10 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v11 = v10;
  if ( !v10 )
    v11 = 1;
  this->FrameCount = v11;
  p_Playlist = &this->Playlist;
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,264>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Playlist.Data,
    v11);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  frames = %d\n");
  for ( this->LoadingFrame = 0;
        pAltStream->Stream.FilePos + pAltStream->Stream.Pos - pAltStream->Stream.DataSize < v8;
        v3 = charId )
  {
    v13 = (unsigned int)Scaleform::GFx::Stream::OpenTag(&pAltStream->Stream, &pTagInfo);
    Scaleform::String::String(
      &src,
      (const char *)((v4->pLoadData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    pObject = v4->pLoadStates.pObject;
    if ( pObject->pProgressHandler.pObject )
    {
      v15 = pObject->pProgressHandler.pObject;
      TagDataOffset = pTagInfo.TagDataOffset;
      TagLength = pTagInfo.TagLength;
      TagOffset = pTagInfo.TagOffset;
      TagType = pTagInfo.TagType;
      Scaleform::String::String(&v29, &src);
      v30 = TagType;
      v31 = TagOffset;
      v32 = TagLength;
      v33 = TagDataOffset;
      LOBYTE(v20) = 1;
      ((void (__fastcall *)(Scaleform::GFx::ProgressHandler *, Scaleform::String *, __int64))v15->vfptr[2].__vecDelDtor)(
        v15,
        &v29,
        v20);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      p_Playlist = &this->Playlist;
      v8 = v34;
      v3 = charId;
      v4 = p;
    }
    if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( (_DWORD)v13 == 1 )
    {
      if ( this->LoadingFrame == LODWORD(this->Playlist.Data.Size) )
      {
        Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,264>,Scaleform::ArrayDefaultPolicy>::Resize(
          &p_Playlist->Data,
          this->Playlist.Data.Size + 1);
        LODWORD(v27) = this->LoadingFrame + 1;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
          &pAltStream->Stream,
          "An extra frame is found for sprite id = %d, framecnt = %d, actual frames = %d",
          *v3,
          (unsigned int)this->FrameCount,
          v27);
      }
      Scaleform::GFx::LoadProcess::CommitFrameTags(v4);
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        &pAltStream->Stream,
        "  ShowFrame (sprite, char id = %d)\n");
      ++this->LoadingFrame;
      goto LABEL_28;
    }
    if ( (unsigned int)v13 >= 0x5C )
    {
      v22 = (unsigned int)(v13 - 1000);
      if ( (unsigned int)v22 > 9 )
        goto LABEL_27;
      v21 = Scaleform::GFx::GFx_GFX_TagLoaderTable[v22];
    }
    else
    {
      v21 = Scaleform::GFx::SWF_TagLoaderTable[v13];
    }
    if ( v21 )
    {
      v21(v4, &pTagInfo);
      goto LABEL_28;
    }
LABEL_27:
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      &pAltStream->Stream,
      "*** no tag loader for type %d\n");
LABEL_28:
    v23 = pAltStream->Stream.TagStack[--pAltStream->Stream.TagStackEntryCount];
    pAltStream->Stream.UnusedBits = 0;
    FilePos = pAltStream->Stream.FilePos;
    DataSize = pAltStream->Stream.DataSize;
    if ( v23 < (int)(FilePos - DataSize) || v23 >= FilePos )
    {
      if ( (pAltStream->Stream.ResyncFile || pAltStream->Stream.Pos + FilePos - DataSize != v23)
        && ((int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))pAltStream->Stream.pInput.pObject->vfptr[14].__vecDelDtor)(
             pAltStream->Stream.pInput.pObject,
             (unsigned int)v23,
             0i64) >= 0 )
      {
        pAltStream->Stream.ResyncFile = 0;
        *(_QWORD *)&pAltStream->Stream.Pos = 0i64;
        pAltStream->Stream.FilePos = v23;
      }
    }
    else
    {
      pAltStream->Stream.Pos = v23 + DataSize - FilePos;
    }
    pAltStream->Stream.UnusedBits = 0;
  }
  LoadState = v4->LoadState;
  if ( v4->FrameTags[LoadState].Data.Size || !(_DWORD)LoadState && v4->InitActionTags.Data.Size )
  {
    if ( this->LoadingFrame == LODWORD(this->Playlist.Data.Size) )
    {
      Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,264>,Scaleform::ArrayDefaultPolicy>::Resize(
        &p_Playlist->Data,
        this->Playlist.Data.Size + 1);
      LODWORD(v27) = this->LoadingFrame + 1;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
        &pAltStream->Stream,
        "An extra frame is found for sprite id = %d, framecnt = %d, actual frames = %d",
        *v3,
        (unsigned int)this->FrameCount,
        v27);
    }
    Scaleform::GFx::LoadProcess::CommitFrameTags(v4);
  }
  v4->LoadState = LS_LoadingRoot;
  v4->pTimelineDef = 0i64;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    &pAltStream->Stream,
    "  -- sprite END, char id = %d --\n");
}

// File Line: 196
// RVA: 0x8D8FC0
Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::SpriteDef::GetFrameLabels(
        Scaleform::GFx::SpriteDef *this,
        unsigned int frameNumber,
        Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *destArr)
{
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_NamedFrames; // r10
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // r9
  __int64 v7; // r14
  unsigned __int64 v8; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v9; // rcx
  int v10; // esi
  signed __int64 v11; // rbx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v12; // rcx
  Scaleform::String *v13; // rbp
  Scaleform::String *v14; // rcx
  unsigned __int64 SizeMask; // rcx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v16; // rax
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v18; // [rsp+30h] [rbp-38h]
  unsigned __int64 v19; // [rsp+38h] [rbp-30h]

  p_NamedFrames = &this->NamedFrames;
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
    v18 = p_NamedFrames;
    v19 = v8;
  }
  else
  {
    v18 = 0i64;
    v19 = 0i64;
  }
  v10 = 0;
  v11 = v19;
  while ( v18 )
  {
    v12 = v18->mHash.pTable;
    if ( !v18->mHash.pTable || v11 > (signed __int64)v12->SizeMask )
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
    SizeMask = v18->mHash.pTable->SizeMask;
    if ( v11 <= (__int64)SizeMask && ++v11 <= SizeMask )
    {
      v16 = &v18->mHash.pTable[2 * v11 + 1];
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
  if ( v10 )
    return destArr;
  return (Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *)v7;
}

// File Line: 233
// RVA: 0x8B0270
Scaleform::GFx::TimelineSnapshot::SnapshotElement *__fastcall Scaleform::GFx::TimelineSnapshot::Add(
        Scaleform::GFx::TimelineSnapshot *this,
        int depth)
{
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *result; // rax
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v5; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 Size; // r10
  __int64 v8; // rcx
  unsigned __int64 v9; // r8
  unsigned __int64 v10; // r8

  result = Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2>>::allocate(&this->SnapshotHeap);
  v5 = result;
  v6 = 0i64;
  if ( result )
  {
    result->CreateFrame = -1;
    result->Tags.pMainTag = 0i64;
    result->Tags.pMatrixTag = 0i64;
    result->Tags.pCxFormTag = 0i64;
    result->Tags.pFiltersTag = 0i64;
    result->Tags.pBlendModeTag = 0i64;
    result->Tags.pDepthTag = 0i64;
    result->Tags.pClipDepthTag = 0i64;
    result->Tags.pRatioTag = 0i64;
    result->Tags.pCharIdTag = 0i64;
    result->Tags.pClassNameTag = 0i64;
    *(_WORD *)&result->PlaceType = 255;
  }
  if ( result )
  {
    result->pPrev = this->SnapshotList.Root.pPrev;
    result->pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)&this->SnapshotList;
    this->SnapshotList.Root.pPrev->pNext = result;
    this->SnapshotList.Root.pPrev = result;
    result->Depth = depth;
    Size = this->SnapshotSortedArray.Data.Size;
    v8 = Size;
    while ( v8 > 0 )
    {
      v9 = (v8 >> 1) + v6;
      if ( depth >= this->SnapshotSortedArray.Data.Data[v9]->Depth )
      {
        v6 = v9 + 1;
        v8 += -1 - (v8 >> 1);
      }
      else
      {
        v8 >>= 1;
      }
    }
    Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      (Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy> *)&this->SnapshotSortedArray,
      Size + 1);
    v10 = this->SnapshotSortedArray.Data.Size;
    if ( v6 < v10 - 1 )
      memmove(
        &this->SnapshotSortedArray.Data.Data[v6 + 1],
        &this->SnapshotSortedArray.Data.Data[v6],
        8 * (v10 - v6) - 8);
    this->SnapshotSortedArray.Data.Data[v6] = v5;
    return v5;
  }
  return result;
}

// File Line: 263
// RVA: 0x8EB240
void __fastcall Scaleform::GFx::TimelineSnapshot::MakeSnapshot(
        Scaleform::GFx::TimelineSnapshot *this,
        Scaleform::GFx::TimelineDef *pdef,
        unsigned int startFrame,
        unsigned int endFrame)
{
  unsigned int v5; // edi
  __int64 i; // rbx
  __int64 v9; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v10; // [rsp+28h] [rbp-10h]

  if ( startFrame <= endFrame )
  {
    v5 = startFrame;
    do
    {
      ((void (__fastcall *)(Scaleform::GFx::TimelineDef *, __int64 *, _QWORD))pdef->vfptr[2].GetResourceReport)(
        pdef,
        &v9,
        v5);
      for ( i = 0i64; (unsigned int)i < v10; i = (unsigned int)(i + 1) )
        (*(void (__fastcall **)(_QWORD, Scaleform::GFx::TimelineSnapshot *, _QWORD))(**(_QWORD **)(v9 + 8 * i) + 48i64))(
          *(_QWORD *)(v9 + 8 * i),
          this,
          v5);
      ++v5;
    }
    while ( v5 <= endFrame );
  }
}

// File Line: 282
// RVA: 0x8CADA0
void __fastcall Scaleform::GFx::TimelineSnapshot::ExecuteSnapshot(
        Scaleform::GFx::TimelineSnapshot *this,
        Scaleform::GFx::DisplayObjContainer *pdispObj)
{
  int v3; // ebx
  Scaleform::List<Scaleform::GFx::TimelineSnapshot::SnapshotElement,Scaleform::GFx::TimelineSnapshot::SnapshotElement> *p_SnapshotList; // r14
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *i; // rdi
  Scaleform::GFx::ASMovieRootBase *v6; // rcx
  Scaleform::GFx::ASStringManager *v7; // rax
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::ASMovieRootBase *v14; // rcx
  Scaleform::GFx::ASStringManager *v15; // rax
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  int v19; // eax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASString v21; // [rsp+58h] [rbp-A8h] BYREF
  Scaleform::GFx::ASString v22; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::ASString v23; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData v25; // [rsp+80h] [rbp-80h] BYREF
  __int64 v26; // [rsp+110h] [rbp+10h]
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData v27; // [rsp+120h] [rbp+20h] BYREF
  char v28[16]; // [rsp+1B0h] [rbp+B0h] BYREF
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData v29; // [rsp+1C0h] [rbp+C0h] BYREF
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *id; // [rsp+290h] [rbp+190h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+2A0h] [rbp+1A0h] BYREF
  Scaleform::GFx::ASStringNode *v32; // [rsp+2A8h] [rbp+1A8h] BYREF

  v26 = -2i64;
  v3 = 0;
  p_SnapshotList = &this->SnapshotList;
  if ( (Scaleform::List<Scaleform::GFx::TimelineSnapshot::SnapshotElement,Scaleform::GFx::TimelineSnapshot::SnapshotElement> *)this->SnapshotList.Root.pNext != &this->SnapshotList )
  {
    for ( i = this->SnapshotList.Root.pNext; ; i = i->pNext )
    {
      if ( i->PlaceType )
      {
        if ( i->PlaceType == 1 )
        {
          id = &v29;
          Scaleform::Render::Cxform::Cxform(&v29.Pos.ColorTransform);
          *(_OWORD *)&v29.Pos.Matrix_1.M[0][0] = _xmm;
          *(__m128 *)&v29.Pos.Matrix_1.M[1][0] = _xmm;
          v29.Pos.pFilters.pObject = 0i64;
          v29.Pos.CharacterId.Id = 0x40000;
          *(_DWORD *)&v29.Pos.ClipDepth = 0;
          *(_QWORD *)&v29.Pos.Ratio = 0i64;
          *(_WORD *)&v29.Pos.BlendMode = 256;
          v29.Pos.ClassName = 0i64;
          Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(&i->Tags, &v29);
          Scaleform::GFx::DisplayList::MoveDisplayObject(&pdispObj->mDisplayList, pdispObj, &v29.Pos);
          id = &v29;
          pObject = (Scaleform::Render::RenderBuffer *)v29.Pos.pFilters.pObject;
        }
        else
        {
          if ( i->PlaceType != 2 )
          {
            if ( i->PlaceType == 3 )
            {
              LODWORD(id) = 0x40000;
              Scaleform::GFx::DisplayList::RemoveDisplayObject(
                &pdispObj->mDisplayList,
                pdispObj,
                i->Depth,
                (Scaleform::GFx::ResourceId)&id);
            }
            goto LABEL_37;
          }
          id = &v27;
          Scaleform::Render::Cxform::Cxform(&v27.Pos.ColorTransform);
          *(_OWORD *)&v27.Pos.Matrix_1.M[0][0] = _xmm;
          *(__m128 *)&v27.Pos.Matrix_1.M[1][0] = _xmm;
          v27.Pos.pFilters.pObject = 0i64;
          v27.Pos.CharacterId.Id = 0x40000;
          *(_DWORD *)&v27.Pos.ClipDepth = 0;
          *(_QWORD *)&v27.Pos.Ratio = 0i64;
          *(_WORD *)&v27.Pos.BlendMode = 256;
          v27.Pos.ClassName = 0i64;
          Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(&i->Tags, &v27);
          v6 = pdispObj->pASRoot->pMovieImpl->pASMovieRoot.pObject;
          v7 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))v6->vfptr[59].__vecDelDtor)(v6);
          if ( v27.Name )
          {
            v8 = Scaleform::GFx::ASStringManager::CreateString(v7, &v23, v27.Name);
            v3 |= 8u;
          }
          else
          {
            v8 = Scaleform::GFx::ASStringManager::CreateEmptyString(v7, &result);
            v3 |= 4u;
          }
          pNode = v8->pNode;
          ++pNode->RefCount;
          if ( (v3 & 8) != 0 )
          {
            v3 &= ~8u;
            v9 = v23.pNode;
            v10 = v23.pNode->RefCount-- == 1;
            if ( v10 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v9);
          }
          if ( (v3 & 4) != 0 )
          {
            v3 &= ~4u;
            v11 = result.pNode;
            v10 = result.pNode->RefCount-- == 1;
            if ( v10 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v11);
          }
          ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *, Scaleform::GFx::ASStringNode **, char *))pdispObj->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[123].__vecDelDtor)(
            pdispObj,
            &v27,
            &pNode,
            v28);
          v12 = pNode;
          v10 = pNode->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v12);
          id = &v27;
          pObject = (Scaleform::Render::RenderBuffer *)v27.Pos.pFilters.pObject;
        }
      }
      else
      {
        id = &v25;
        Scaleform::Render::Cxform::Cxform(&v25.Pos.ColorTransform);
        *(_OWORD *)&v25.Pos.Matrix_1.M[0][0] = _xmm;
        *(__m128 *)&v25.Pos.Matrix_1.M[1][0] = _xmm;
        v25.Pos.pFilters.pObject = 0i64;
        v25.Pos.CharacterId.Id = 0x40000;
        *(_DWORD *)&v25.Pos.ClipDepth = 0;
        *(_QWORD *)&v25.Pos.Ratio = 0i64;
        *(_WORD *)&v25.Pos.BlendMode = 256;
        v25.Pos.ClassName = 0i64;
        Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(&i->Tags, &v25);
        v14 = pdispObj->pASRoot->pMovieImpl->pASMovieRoot.pObject;
        v15 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))v14->vfptr[59].__vecDelDtor)(v14);
        if ( v25.Name )
        {
          v16 = Scaleform::GFx::ASStringManager::CreateString(v15, &v22, v25.Name);
          v3 |= 2u;
        }
        else
        {
          v16 = Scaleform::GFx::ASStringManager::CreateEmptyString(v15, &v21);
          v3 |= 1u;
        }
        v32 = v16->pNode;
        ++v32->RefCount;
        if ( (v3 & 2) != 0 )
        {
          v3 &= ~2u;
          v17 = v22.pNode;
          v10 = v22.pNode->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v17);
        }
        if ( (v3 & 1) != 0 )
        {
          v3 &= ~1u;
          v18 = v21.pNode;
          v10 = v21.pNode->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v18);
        }
        v19 = 4;
        if ( (i->Flags & 2) != 0 )
          v19 = 6;
        ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *, Scaleform::GFx::ASStringNode **, Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *, _QWORD, unsigned int, int, _QWORD, _QWORD))pdispObj->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[118].__vecDelDtor)(
          pdispObj,
          &v25,
          &v32,
          v25.pEventHandlers,
          0i64,
          i->CreateFrame,
          v19,
          0i64,
          0i64);
        v20 = v32;
        v10 = v32->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
        id = &v25;
        pObject = (Scaleform::Render::RenderBuffer *)v25.Pos.pFilters.pObject;
      }
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
LABEL_37:
      if ( i == p_SnapshotList->Root.pPrev )
        return;
    }
  }
}

// File Line: 345
// RVA: 0x915BA0
void __fastcall Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(
        Scaleform::GFx::TimelineSnapshot::SourceTags *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  Scaleform::GFx::GFxPlaceObjectBase *pDepthTag; // rcx
  Scaleform::GFx::GFxPlaceObjectBase *pCharIdTag; // rcx
  __int64 v6; // rsi
  __int64 v7; // rax
  Scaleform::GFx::GFxPlaceObjectBase *pMatrixTag; // rcx
  __int64 v9; // rax
  Scaleform::GFx::GFxPlaceObjectBase *pClassNameTag; // rcx
  __int64 v11; // rax
  Scaleform::GFx::GFxPlaceObjectBase *pCxFormTag; // rcx
  __int64 v13; // rax
  __int64 v14; // rax
  Scaleform::GFx::GFxPlaceObjectBase *pBlendModeTag; // rcx
  __int64 v16; // rax
  Scaleform::GFx::GFxPlaceObjectBase *pClipDepthTag; // rcx
  __int64 v18; // rax
  Scaleform::GFx::GFxPlaceObjectBase *pRatioTag; // rcx
  __int64 v20; // rax
  Scaleform::GFx::GFxPlaceObjectBase *pFiltersTag; // rcx
  Scaleform::GFx::Resource *v22; // rcx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  __int128 ptr[4]; // [rsp+40h] [rbp-518h] BYREF
  _DWORD v25[20]; // [rsp+80h] [rbp-4D8h]
  char v26[144]; // [rsp+D0h] [rbp-488h] BYREF
  char v27[144]; // [rsp+160h] [rbp-3F8h] BYREF
  char v28[144]; // [rsp+1F0h] [rbp-368h] BYREF
  char v29[144]; // [rsp+280h] [rbp-2D8h] BYREF
  char v30[144]; // [rsp+310h] [rbp-248h] BYREF
  char v31[144]; // [rsp+3A0h] [rbp-1B8h] BYREF
  char v32[144]; // [rsp+430h] [rbp-128h] BYREF
  char v33[144]; // [rsp+4C0h] [rbp-98h] BYREF

  ((void (__fastcall *)(Scaleform::GFx::GFxPlaceObjectBase *))this->pMainTag->vfptr[1].__vecDelDtor)(this->pMainTag);
  `eh vector constructor iterator(
    ptr,
    0x90ui64,
    9,
    (void (__fastcall *)(void *))Scaleform::GFx::GFxPlaceObjectBase::UnpackedData::UnpackedData);
  pDepthTag = this->pDepthTag;
  if ( pDepthTag != this->pMainTag )
  {
    pDepthTag->vfptr[1].__vecDelDtor(pDepthTag, (unsigned int)ptr);
    data->Pos.Depth = v25[3];
    data->Pos.Flags.Flags |= 1u;
  }
  pCharIdTag = this->pCharIdTag;
  v6 = 0i64;
  if ( pCharIdTag != this->pMainTag )
  {
    if ( this->pDepthTag == pCharIdTag )
    {
      v7 = 0i64;
    }
    else
    {
      pCharIdTag->vfptr[1].__vecDelDtor(pCharIdTag, (unsigned int)v26);
      v7 = 1i64;
    }
    data->Pos.CharacterId.Id = v25[36 * v7 + 4];
    data->Pos.Flags.Flags |= 2u;
  }
  pMatrixTag = this->pMatrixTag;
  if ( pMatrixTag != this->pMainTag )
  {
    if ( this->pDepthTag == pMatrixTag )
    {
      v9 = 0i64;
    }
    else if ( this->pCharIdTag == pMatrixTag )
    {
      v9 = 1i64;
    }
    else
    {
      pMatrixTag->vfptr[1].__vecDelDtor(pMatrixTag, (unsigned int)v27);
      v9 = 2i64;
    }
    data->Pos.Matrix_1.M[0][0] = *(float *)&ptr[9 * v9 + 2];
    data->Pos.Matrix_1.M[0][1] = *((float *)&ptr[9 * v9 + 2] + 1);
    data->Pos.Matrix_1.M[0][2] = *((float *)&ptr[9 * v9 + 2] + 2);
    data->Pos.Matrix_1.M[0][3] = *((float *)&ptr[9 * v9 + 2] + 3);
    data->Pos.Matrix_1.M[1][0] = *(float *)&ptr[9 * v9 + 3];
    data->Pos.Matrix_1.M[1][1] = *((float *)&ptr[9 * v9 + 3] + 1);
    data->Pos.Matrix_1.M[1][2] = *((float *)&ptr[9 * v9 + 3] + 2);
    data->Pos.Matrix_1.M[1][3] = *((float *)&ptr[9 * v9 + 3] + 3);
    data->Pos.Flags.Flags |= 4u;
  }
  pClassNameTag = this->pClassNameTag;
  if ( pClassNameTag != this->pMainTag )
  {
    if ( this->pDepthTag == pClassNameTag )
    {
      v11 = 0i64;
    }
    else if ( this->pCharIdTag == pClassNameTag )
    {
      v11 = 1i64;
    }
    else if ( this->pMatrixTag == pClassNameTag )
    {
      v11 = 2i64;
    }
    else
    {
      pClassNameTag->vfptr[1].__vecDelDtor(pClassNameTag, (unsigned int)v28);
      v11 = 3i64;
    }
    data->Pos.ClassName = *(const char **)&v25[36 * v11 + 6];
    data->Pos.Flags.Flags |= 0x100u;
  }
  pCxFormTag = this->pCxFormTag;
  if ( pCxFormTag != this->pMainTag )
  {
    if ( this->pDepthTag == pCxFormTag )
    {
      v13 = 0i64;
    }
    else if ( this->pCharIdTag == pCxFormTag )
    {
      v13 = 1i64;
    }
    else if ( this->pMatrixTag == pCxFormTag )
    {
      v13 = 2i64;
    }
    else if ( this->pClassNameTag == pCxFormTag )
    {
      v13 = 3i64;
    }
    else
    {
      pCxFormTag->vfptr[1].__vecDelDtor(pCxFormTag, (unsigned int)v29);
      v13 = 4i64;
    }
    v14 = 9 * v13;
    *(_OWORD *)&data->Pos.ColorTransform.M[0][0] = ptr[v14];
    *(_OWORD *)&data->Pos.ColorTransform.M[1][0] = ptr[v14 + 1];
    data->Pos.Flags.Flags |= 8u;
  }
  pBlendModeTag = this->pBlendModeTag;
  if ( pBlendModeTag != this->pMainTag )
  {
    if ( this->pDepthTag == pBlendModeTag )
    {
      v16 = 0i64;
    }
    else if ( this->pCharIdTag == pBlendModeTag )
    {
      v16 = 1i64;
    }
    else if ( this->pMatrixTag == pBlendModeTag )
    {
      v16 = 2i64;
    }
    else if ( this->pClassNameTag == pBlendModeTag )
    {
      v16 = 3i64;
    }
    else if ( this->pCxFormTag == pBlendModeTag )
    {
      v16 = 4i64;
    }
    else
    {
      pBlendModeTag->vfptr[1].__vecDelDtor(pBlendModeTag, (unsigned int)v30);
      v16 = 5i64;
    }
    data->Pos.BlendMode = v25[36 * v16 + 9];
    data->Pos.Flags.Flags |= 0x80u;
  }
  pClipDepthTag = this->pClipDepthTag;
  if ( pClipDepthTag != this->pMainTag )
  {
    if ( this->pDepthTag == pClipDepthTag )
    {
      v18 = 0i64;
    }
    else if ( this->pCharIdTag == pClipDepthTag )
    {
      v18 = 1i64;
    }
    else if ( this->pMatrixTag == pClipDepthTag )
    {
      v18 = 2i64;
    }
    else if ( this->pClassNameTag == pClipDepthTag )
    {
      v18 = 3i64;
    }
    else if ( this->pCxFormTag == pClipDepthTag )
    {
      v18 = 4i64;
    }
    else if ( this->pBlendModeTag == pClipDepthTag )
    {
      v18 = 5i64;
    }
    else
    {
      pClipDepthTag->vfptr[1].__vecDelDtor(pClipDepthTag, (unsigned int)v31);
      v18 = 6i64;
    }
    data->Pos.ClipDepth = v25[36 * v18 + 8];
    data->Pos.Flags.Flags |= 0x40u;
  }
  pRatioTag = this->pRatioTag;
  if ( pRatioTag != this->pMainTag )
  {
    if ( this->pDepthTag == pRatioTag )
    {
      v20 = 0i64;
    }
    else if ( this->pCharIdTag == pRatioTag )
    {
      v20 = 1i64;
    }
    else if ( this->pMatrixTag == pRatioTag )
    {
      v20 = 2i64;
    }
    else if ( this->pClassNameTag == pRatioTag )
    {
      v20 = 3i64;
    }
    else if ( this->pCxFormTag == pRatioTag )
    {
      v20 = 4i64;
    }
    else if ( this->pBlendModeTag == pRatioTag )
    {
      v20 = 5i64;
    }
    else if ( this->pClipDepthTag == pRatioTag )
    {
      v20 = 6i64;
    }
    else
    {
      pRatioTag->vfptr[1].__vecDelDtor(pRatioTag, (unsigned int)v32);
      v20 = 7i64;
    }
    LODWORD(data->Pos.Ratio) = v25[36 * v20 + 2];
    data->Pos.Flags.Flags |= 0x10u;
  }
  pFiltersTag = this->pFiltersTag;
  if ( pFiltersTag != this->pMainTag )
  {
    if ( this->pDepthTag != pFiltersTag )
    {
      if ( this->pCharIdTag == pFiltersTag )
      {
        v6 = 1i64;
      }
      else if ( this->pMatrixTag == pFiltersTag )
      {
        v6 = 2i64;
      }
      else if ( this->pClassNameTag == pFiltersTag )
      {
        v6 = 3i64;
      }
      else if ( this->pCxFormTag == pFiltersTag )
      {
        v6 = 4i64;
      }
      else if ( this->pBlendModeTag == pFiltersTag )
      {
        v6 = 5i64;
      }
      else if ( this->pClipDepthTag == pFiltersTag )
      {
        v6 = 6i64;
      }
      else if ( this->pRatioTag == pFiltersTag )
      {
        v6 = 7i64;
      }
      else
      {
        pFiltersTag->vfptr[1].__vecDelDtor(pFiltersTag, (unsigned int)v33);
        v6 = 8i64;
      }
    }
    v22 = *(Scaleform::GFx::Resource **)&v25[36 * v6];
    if ( v22 )
      Scaleform::Render::RenderBuffer::AddRef(v22);
    pObject = (Scaleform::Render::RenderBuffer *)data->Pos.pFilters.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    data->Pos.pFilters.pObject = *(Scaleform::Render::FilterSet **)&v25[36 * v6];
    data->Pos.Flags.Flags |= 0x20u;
  }
  `eh vector destructor iterator(
    ptr,
    0x90ui64,
    9,
    (void (__fastcall *)(void *))Scaleform::GFx::GFxPlaceObjectBase::UnpackedData::~UnpackedData);
}t);
    data->Pos.pFilters.pObject = *(Scaleform::Render::FilterSet **)&v25[36 * v6];
    data->Pos.Flags.

// File Line: 447
// RVA: 0x8B3440
void __fastcall Scaleform::GFx::GFxPlaceObjectUnpacked::AddToTimelineSnapshot(
        Scaleform::GFx::GFxPlaceObjectUnpacked *this,
        Scaleform::GFx::TimelineSnapshot *psnapshot,
        unsigned int frame)
{
  __int64 Size; // rcx
  int Depth; // r10d
  __int64 v8; // r9
  Scaleform::GFx::TimelineSnapshot::SnapshotElement **Data; // r11
  __int64 v10; // r8
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v11; // rcx
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v12; // rax

  this->vfptr->Trace(this, "\n");
  Size = psnapshot->SnapshotSortedArray.Data.Size;
  Depth = this->Pos.Depth;
  v8 = 0i64;
  if ( Size <= 0 )
    goto LABEL_12;
  Data = psnapshot->SnapshotSortedArray.Data.Data;
  do
  {
    v10 = (Size >> 1) + v8;
    if ( Depth >= Data[v10]->Depth )
    {
      v8 = v10 + 1;
      Size += -1 - (Size >> 1);
    }
    else
    {
      Size >>= 1;
    }
  }
  while ( Size > 0 );
  if ( v8 && (v11 = Data[v8 - 1], v11->Depth == Depth) && v11 && (v11->Flags & 2) == 0 )
  {
    v11->Tags.pClassNameTag = this;
    v11->Tags.pCharIdTag = this;
    v11->Tags.pRatioTag = this;
    v11->Tags.pClipDepthTag = this;
    v11->Tags.pDepthTag = this;
    v11->Tags.pBlendModeTag = this;
    v11->Tags.pFiltersTag = this;
    v11->Tags.pCxFormTag = this;
    v11->Tags.pMatrixTag = this;
    v11->Tags.pMainTag = this;
    v11->CreateFrame = frame;
    v11->Flags |= 1u;
  }
  else
  {
LABEL_12:
    v12 = Scaleform::GFx::TimelineSnapshot::Add(psnapshot, Depth);
    v12->Tags.pClassNameTag = this;
    v12->Tags.pCharIdTag = this;
    v12->Tags.pRatioTag = this;
    v12->Tags.pClipDepthTag = this;
    v12->Tags.pDepthTag = this;
    v12->Tags.pBlendModeTag = this;
    v12->Tags.pFiltersTag = this;
    v12->Tags.pCxFormTag = this;
    v12->Tags.pMatrixTag = this;
    v12->Tags.pMainTag = this;
    v12->CreateFrame = frame;
    v12->PlaceType = 0;
    v12->Flags |= 1u;
  }
}

// File Line: 482
// RVA: 0x8B3AC0
void __fastcall Scaleform::GFx::PlaceObjectTag::AddToTimelineSnapshot(
        Scaleform::GFx::PlaceObjectTag *this,
        Scaleform::GFx::TimelineSnapshot *psnapshot,
        unsigned int frame)
{
  __int64 Size; // rdx
  __int64 v7; // r9
  int v8; // r10d
  Scaleform::GFx::TimelineSnapshot::SnapshotElement **Data; // r11
  __int64 v10; // r8
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v11; // rcx
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v12; // rax

  this->vfptr->Trace(this, "\n");
  Size = psnapshot->SnapshotSortedArray.Data.Size;
  v7 = 0i64;
  v8 = *(unsigned __int16 *)&this->pData[2];
  if ( Size <= 0 )
    goto LABEL_12;
  Data = psnapshot->SnapshotSortedArray.Data.Data;
  do
  {
    v10 = (Size >> 1) + v7;
    if ( v8 >= Data[v10]->Depth )
    {
      v7 = v10 + 1;
      Size += -1 - (Size >> 1);
    }
    else
    {
      Size >>= 1;
    }
  }
  while ( Size > 0 );
  if ( v7 && (v11 = Data[v7 - 1], v11->Depth == v8) && v11 && (v11->Flags & 2) == 0 )
  {
    v11->Tags.pClassNameTag = this;
    v11->Tags.pCharIdTag = this;
    v11->Tags.pRatioTag = this;
    v11->Tags.pClipDepthTag = this;
    v11->Tags.pDepthTag = this;
    v11->Tags.pBlendModeTag = this;
    v11->Tags.pFiltersTag = this;
    v11->Tags.pCxFormTag = this;
    v11->Tags.pMatrixTag = this;
    v11->Tags.pMainTag = this;
    v11->CreateFrame = frame;
    v11->Flags |= 1u;
  }
  else
  {
LABEL_12:
    v12 = Scaleform::GFx::TimelineSnapshot::Add(psnapshot, v8);
    v12->PlaceType = 0;
    v12->Tags.pClassNameTag = this;
    v12->Tags.pCharIdTag = this;
    v12->Tags.pRatioTag = this;
    v12->Tags.pClipDepthTag = this;
    v12->Tags.pDepthTag = this;
    v12->Tags.pBlendModeTag = this;
    v12->Tags.pFiltersTag = this;
    v12->Tags.pCxFormTag = this;
    v12->Tags.pMatrixTag = this;
    v12->Tags.pMainTag = this;
    v12->CreateFrame = frame;
    v12->Flags |= 1u;
  }
}

// File Line: 527
// RVA: 0x8C95D0
void __fastcall Scaleform::GFx::GFxPlaceObjectUnpacked::Execute(
        Scaleform::GFx::GFxPlaceObjectUnpacked *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringManager *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF

  pObject = m->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v5 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pObject->vfptr[59].__vecDelDtor)(pObject);
  Scaleform::GFx::ASStringManager::CreateEmptyString(v5, &result);
  ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASString *, _QWORD, _QWORD, int, int, _QWORD, _QWORD))m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[118].__vecDelDtor)(
    m,
    &this->Pos,
    &result,
    0i64,
    0i64,
    -1,
    4,
    0i64,
    0i64);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 578
// RVA: 0x8D8160
Scaleform::GFx::CharPosInfoFlags *__fastcall Scaleform::GFx::PlaceObjectTag::GetFlags(
        Scaleform::GFx::PlaceObjectTag *this,
        Scaleform::GFx::CharPosInfoFlags *result)
{
  result->Flags = (this->HasCxForm ? 8 : 0) | 7;
  return result;
}

// File Line: 594
// RVA: 0x8CA200
void __fastcall Scaleform::GFx::PlaceObjectTag::Execute(
        Scaleform::GFx::PlaceObjectTag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringManager *v5; // rax
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Cxform v9; // [rsp+60h] [rbp-98h] BYREF
  __int128 v10; // [rsp+80h] [rbp-78h]
  __m128 v11; // [rsp+90h] [rbp-68h]
  Scaleform::Render::RenderBuffer *v12; // [rsp+A0h] [rbp-58h]
  int v13; // [rsp+A8h] [rbp-50h]
  int v14; // [rsp+ACh] [rbp-4Ch]
  int v15; // [rsp+B0h] [rbp-48h]
  __int64 v16; // [rsp+B8h] [rbp-40h]
  int v17; // [rsp+C0h] [rbp-38h]
  __int16 v18; // [rsp+C4h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+100h] [rbp+8h] BYREF

  result.pNode = (Scaleform::GFx::ASStringNode *)&v9;
  Scaleform::Render::Cxform::Cxform(&v9);
  v10 = _xmm;
  v11 = _xmm;
  v12 = 0i64;
  v15 = 0x40000;
  v17 = 0;
  v13 = 0;
  v14 = 0;
  v18 = 256;
  v16 = 0i64;
  this->vfptr[1].__vecDelDtor(this, (unsigned int)&v9);
  pObject = m->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v5 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pObject->vfptr[59].__vecDelDtor)(pObject);
  v6 = Scaleform::GFx::ASStringManager::CreateEmptyString(v5, &result);
  ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, _QWORD, int, int, _QWORD, _QWORD))m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[118].__vecDelDtor)(
    m,
    &v9,
    v6,
    0i64,
    0i64,
    -1,
    4,
    0i64,
    0i64);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result.pNode = (Scaleform::GFx::ASStringNode *)&v9;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
}

// File Line: 606
// RVA: 0x915AF0
void __fastcall Scaleform::GFx::PlaceObjectTag::Unpack(
        Scaleform::GFx::PlaceObjectTag *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  __int16 v3; // ax
  __int16 v4; // r8
  Scaleform::Render::Matrix2x4<float> *p_Matrix_1; // rdx
  Scaleform::GFx::StreamContext v7; // [rsp+20h] [rbp-28h] BYREF

  data->Name = 0i64;
  data->pEventHandlers = 0i64;
  data->PlaceType = Place_Add;
  data->Pos.Flags.Flags |= 2u;
  v3 = (unsigned __int8)this->pData[0];
  v4 = (unsigned __int8)this->pData[1];
  v7.CurBitIndex = 0;
  p_Matrix_1 = &data->Pos.Matrix_1;
  v7.pData = this->pData;
  v7.DataSize = -1i64;
  v7.CurByteIndex = 4i64;
  LODWORD(p_Matrix_1[1].M[1][0]) = (unsigned __int16)(v3 | (v4 << 8));
  HIWORD(p_Matrix_1[2].M[0][0]) |= 1u;
  LODWORD(p_Matrix_1[1].M[0][3]) = *(unsigned __int16 *)&this->pData[2];
  HIWORD(p_Matrix_1[2].M[0][0]) |= 4u;
  Scaleform::GFx::StreamContext::ReadMatrix(&v7, p_Matrix_1);
  if ( this->HasCxForm )
  {
    data->Pos.Flags.Flags |= 8u;
    Scaleform::GFx::StreamContext::ReadCxformRgb(&v7, &data->Pos.ColorTransform);
  }
}

// File Line: 639
// RVA: 0x8A7210
void __fastcall Scaleform::GFx::PlaceObject2Tag::~PlaceObject2Tag(Scaleform::GFx::PlaceObject2Tag *this)
{
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::PlaceObject2Tag::`vftable;
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::ExecuteTag::`vftable;
}

// File Line: 747
// RVA: 0x8D8110
Scaleform::GFx::CharPosInfoFlags *__fastcall Scaleform::GFx::PlaceObject2Tag::GetFlags(
        Scaleform::GFx::PlaceObject2Tag *this,
        Scaleform::GFx::CharPosInfoFlags *result)
{
  result->Flags = this->pData[0] & 0x5F;
  return result;
}

// File Line: 777
// RVA: 0x8CA440
void __fastcall Scaleform::GFx::PlaceObject2Tag::ExecuteBase(
        Scaleform::GFx::PlaceObject2Tag *this,
        Scaleform::GFx::DisplayObjContainer *m,
        char version)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringManager *v7; // rax
  Scaleform::GFx::ASString *String; // rax
  char v9; // bl
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASMovieRootBase *v13; // rcx
  Scaleform::GFx::ASStringManager *v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  char v16; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASString v20; // [rsp+58h] [rbp-90h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp-88h] BYREF
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData v22; // [rsp+68h] [rbp-80h] BYREF
  __int64 v23; // [rsp+F8h] [rbp+10h]
  char v24[32]; // [rsp+100h] [rbp+18h] BYREF
  Scaleform::GFx::ASString v25; // [rsp+140h] [rbp+58h] BYREF

  v23 = -2i64;
  v25.pNode = (Scaleform::GFx::ASStringNode *)&v22;
  Scaleform::Render::Cxform::Cxform(&v22.Pos.ColorTransform);
  *(_OWORD *)&v22.Pos.Matrix_1.M[0][0] = _xmm;
  *(__m128 *)&v22.Pos.Matrix_1.M[1][0] = _xmm;
  v22.Pos.pFilters.pObject = 0i64;
  v22.Pos.CharacterId.Id = 0x40000;
  *(_DWORD *)&v22.Pos.ClipDepth = 0;
  v22.Pos.Ratio = 0.0;
  v22.Pos.Depth = 0;
  *(_WORD *)&v22.Pos.BlendMode = 256;
  v22.Pos.ClassName = 0i64;
  Scaleform::GFx::PlaceObject2Tag::UnpackBase(this, &v22, version);
  if ( v22.PlaceType )
  {
    if ( v22.PlaceType == Place_Move )
    {
      Scaleform::GFx::DisplayList::MoveDisplayObject(&m->mDisplayList, m, &v22.Pos);
      goto LABEL_27;
    }
    if ( v22.PlaceType != Place_Replace )
      goto LABEL_27;
    pObject = m->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v7 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pObject->vfptr[59].__vecDelDtor)(pObject);
    if ( v22.Name )
    {
      String = Scaleform::GFx::ASStringManager::CreateString(
                 v7,
                 (Scaleform::GFx::ASString *)&v22.Pos.ColorTransform.M[0][2],
                 v22.Name);
      v9 = 8;
    }
    else
    {
      String = Scaleform::GFx::ASStringManager::CreateEmptyString(v7, (Scaleform::GFx::ASString *)&v22);
      v9 = 4;
    }
    v25.pNode = String->pNode;
    ++v25.pNode->RefCount;
    if ( (v9 & 8) != 0 )
    {
      v9 &= ~8u;
      v10 = *(Scaleform::GFx::ASStringNode **)&v22.Pos.ColorTransform.M[0][2];
      v11 = (*(_DWORD *)(*(_QWORD *)&v22.Pos.ColorTransform.M[0][2] + 24i64))-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    }
    if ( (v9 & 4) != 0 )
    {
      v12 = *(Scaleform::GFx::ASStringNode **)&v22.Pos.ColorTransform.M[0][0];
      v11 = (*(_DWORD *)(*(_QWORD *)&v22.Pos.ColorTransform.M[0][0] + 24i64))-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *, Scaleform::GFx::ASString *, char *))m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[123].__vecDelDtor)(
      m,
      &v22,
      &v25,
      v24);
  }
  else
  {
    v13 = m->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v14 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))v13->vfptr[59].__vecDelDtor)(v13);
    if ( v22.Name )
    {
      v15 = Scaleform::GFx::ASStringManager::CreateString(v14, &v20, v22.Name);
      v16 = 2;
    }
    else
    {
      v15 = Scaleform::GFx::ASStringManager::CreateEmptyString(v14, &result);
      v16 = 1;
    }
    v25.pNode = v15->pNode;
    ++v25.pNode->RefCount;
    if ( (v16 & 2) != 0 )
    {
      v16 &= ~2u;
      pNode = v20.pNode;
      v11 = v20.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    if ( (v16 & 1) != 0 )
    {
      v18 = result.pNode;
      v11 = result.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *, Scaleform::GFx::ASString *, Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *, _QWORD, int, int, _QWORD, _QWORD))m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[118].__vecDelDtor)(
      m,
      &v22,
      &v25,
      v22.pEventHandlers,
      0i64,
      -1,
      4,
      0i64,
      0i64);
  }
  v19 = v25.pNode;
  v11 = v25.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
LABEL_27:
  v25.pNode = (Scaleform::GFx::ASStringNode *)&v22;
  if ( v22.Pos.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v22.Pos.pFilters.pObject);
}

// File Line: 831
// RVA: 0x8E2E30
__int64 __fastcall Scaleform::GFx::PlaceObject2Tag::HasEventHandlers(Scaleform::GFx::Stream *pin)
{
  unsigned int DataSize; // eax
  __int64 Pos; // rcx
  signed int FilePos; // r8d
  unsigned __int8 v5; // si
  unsigned int v6; // edx
  unsigned int v7; // ecx
  signed int v8; // edi

  DataSize = pin->DataSize;
  pin->UnusedBits = 0;
  if ( (int)(DataSize - pin->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(pin, 1);
  Pos = pin->Pos;
  FilePos = pin->FilePos;
  v5 = pin->pBuffer[Pos];
  v6 = Pos + 1;
  v7 = pin->DataSize;
  pin->Pos = v6;
  pin->UnusedBits = 0;
  v8 = FilePos - v7 + v6 - 1;
  if ( v8 < (int)(FilePos - v7) || v8 >= FilePos )
  {
    if ( (pin->ResyncFile || FilePos - v7 + v6 != v8)
      && ((int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))pin->pInput.pObject->vfptr[14].__vecDelDtor)(
           pin->pInput.pObject,
           (unsigned int)v8,
           0i64) >= 0 )
    {
      pin->ResyncFile = 0;
      pin->FilePos = v8;
      *(_QWORD *)&pin->Pos = 0i64;
    }
  }
  else
  {
    pin->Pos = v6 - 1;
  }
  return v5 >> 7;
}

// File Line: 850
// RVA: 0x916260
Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::PlaceObject3Tag::UnpackEventHandlers(
        Scaleform::GFx::PlaceObject3Tag *this)
{
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *result; // rax
  __int64 v3; // rbx
  Scaleform::Render::Cxform v4; // [rsp+30h] [rbp-98h] BYREF
  __int128 v5; // [rsp+50h] [rbp-78h]
  __m128 v6; // [rsp+60h] [rbp-68h]
  Scaleform::Render::RenderBuffer *v7; // [rsp+70h] [rbp-58h]
  int v8; // [rsp+78h] [rbp-50h]
  int v9; // [rsp+7Ch] [rbp-4Ch]
  int v10; // [rsp+80h] [rbp-48h]
  __int64 v11; // [rsp+88h] [rbp-40h]
  int v12; // [rsp+90h] [rbp-38h]
  __int16 v13; // [rsp+94h] [rbp-34h]
  __int64 v14; // [rsp+A0h] [rbp-28h]

  if ( this->pData[0] >= 0 )
    return 0i64;
  result = *(Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> **)&this->pData[1];
  if ( !result )
  {
    Scaleform::Render::Cxform::Cxform(&v4);
    v5 = _xmm;
    v6 = _xmm;
    v7 = 0i64;
    v10 = 0x40000;
    v12 = 0;
    v8 = 0;
    v9 = 0;
    v13 = 256;
    v11 = 0i64;
    this->vfptr[1].__vecDelDtor(this, (unsigned int)&v4);
    v3 = v14;
    if ( v7 )
      Scaleform::RefCountImpl::Release(v7);
    return (Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *)v3;
  }
  return result;
}

// File Line: 868
// RVA: 0x916010
void __fastcall Scaleform::GFx::PlaceObject2Tag::UnpackBase(
        Scaleform::GFx::PlaceObject2Tag *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data,
        char version)
{
  char *pData; // r15
  char v5; // di
  unsigned __int64 v7; // rdx
  _BYTE *v9; // r9
  unsigned int CurBitIndex; // r8d
  __int16 v11; // ax
  __int16 v12; // cx
  unsigned __int64 CurByteIndex; // rdx
  unsigned __int16 v14; // cx
  unsigned __int16 v15; // cx
  char v16; // al
  unsigned __int16 v17; // cx
  char v18; // al
  char v19; // di
  Scaleform::GFx::StreamContext v20; // [rsp+30h] [rbp-20h] BYREF

  pData = this->pData;
  v20.CurByteIndex = 0i64;
  v20.CurBitIndex = 0;
  v20.DataSize = -1i64;
  v20.pData = this->pData;
  v5 = this->pData[0];
  v20.CurBitIndex = 0;
  v7 = 1i64;
  if ( v5 < 0 )
    v7 = 9i64;
  v9 = this->pData;
  CurBitIndex = 0;
  v20.CurByteIndex = v7;
  v11 = (unsigned __int8)pData[v7];
  v12 = (unsigned __int8)pData[v7 + 1];
  CurByteIndex = v7 + 2;
  v20.CurByteIndex = CurByteIndex;
  data->Pos.Depth = (unsigned __int16)(v11 | (v12 << 8));
  if ( (v5 & 2) != 0 )
  {
    data->Pos.Flags.Flags |= 2u;
    v20.CurBitIndex = 0;
    v14 = *(_WORD *)&pData[CurByteIndex];
    CurByteIndex += 2i64;
    v20.CurByteIndex = CurByteIndex;
    data->Pos.CharacterId.Id = v14;
  }
  if ( (v5 & 4) != 0 )
  {
    data->Pos.Flags.Flags |= 4u;
    Scaleform::GFx::StreamContext::ReadMatrix(&v20, &data->Pos.Matrix_1);
    CurBitIndex = v20.CurBitIndex;
    CurByteIndex = v20.CurByteIndex;
    v9 = v20.pData;
  }
  if ( (v5 & 8) != 0 )
  {
    data->Pos.Flags.Flags |= 8u;
    Scaleform::GFx::StreamContext::ReadCxformRgba(&v20, &data->Pos.ColorTransform);
    CurBitIndex = v20.CurBitIndex;
    CurByteIndex = v20.CurByteIndex;
    v9 = v20.pData;
  }
  if ( (v5 & 0x10) != 0 )
  {
    data->Pos.Flags.Flags |= 0x10u;
    if ( CurBitIndex )
      v20.CurByteIndex = ++CurByteIndex;
    v20.CurBitIndex = 0;
    CurBitIndex = 0;
    v15 = *(_WORD *)&v9[CurByteIndex];
    CurByteIndex += 2i64;
    v20.CurByteIndex = CurByteIndex;
    data->Pos.Ratio = (float)v15 * 0.000015259022;
  }
  if ( (v5 & 0x20) != 0 )
  {
    if ( CurBitIndex )
      v20.CurByteIndex = ++CurByteIndex;
    CurBitIndex = 0;
    v20.CurBitIndex = 0;
    data->Name = &this->pData[CurByteIndex];
    do
    {
      v16 = v9[CurByteIndex++];
      v20.CurByteIndex = CurByteIndex;
    }
    while ( v16 );
  }
  else
  {
    data->Name = 0i64;
  }
  if ( (v5 & 0x40) != 0 )
  {
    data->Pos.Flags.Flags |= 0x40u;
    if ( CurBitIndex )
      v20.CurByteIndex = ++CurByteIndex;
    v20.CurBitIndex = 0;
    v17 = *(_WORD *)&v9[CurByteIndex];
    v20.CurByteIndex = CurByteIndex + 2;
    data->Pos.ClipDepth = v17;
  }
  if ( (v5 & 0x80) != 0 )
    ((void (__fastcall *)(Scaleform::GFx::PlaceObject2Tag *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *, Scaleform::GFx::StreamContext *, char *, char))this->vfptr[1].IsRemoveTag)(
      this,
      data,
      &v20,
      pData,
      version);
  else
    data->pEventHandlers = 0i64;
  v18 = v5;
  v19 = v5 & 1;
  data->PlaceType = Place_Add;
  if ( (v18 & 2) != 0 )
  {
    if ( v19 )
      data->PlaceType = Place_Replace;
  }
  else
  {
    data->PlaceType = v19 != 0;
  }
}

// File Line: 936
// RVA: 0x8A7320
void __fastcall Scaleform::GFx::PlaceObject3Tag::~PlaceObject3Tag(Scaleform::GFx::PlaceObject3Tag *this)
{
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::PlaceObject3Tag::`vftable;
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::ExecuteTag::`vftable;
}

// File Line: 1075
// RVA: 0x8D8120
Scaleform::GFx::CharPosInfoFlags *__fastcall Scaleform::GFx::PlaceObject3Tag::GetFlags(
        Scaleform::GFx::PlaceObject3Tag *this,
        Scaleform::GFx::CharPosInfoFlags *result)
{
  char v2; // r8
  __int64 v3; // rax

  v2 = this->pData[0];
  v3 = 1i64;
  if ( v2 < 0 )
    v3 = 9i64;
  result->Flags = v2 & 0x5F | (unsigned __int8)(32 * (this->pData[v3] & 1 | (2 * (this->pData[v3] & 0xFE))));
  return result;
}

// File Line: 1108
// RVA: 0x8C9FA0
void __fastcall Scaleform::GFx::PlaceObject3Tag::Execute(
        Scaleform::GFx::PlaceObject3Tag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringManager *v5; // rax
  Scaleform::GFx::ASString *v6; // rax
  char v7; // bl
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASMovieRootBase *v11; // rcx
  Scaleform::GFx::ASStringManager *v12; // rax
  Scaleform::GFx::ASString *v13; // rax
  char v14; // bl
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString v18; // [rsp+58h] [rbp-A8h] BYREF
  Scaleform::GFx::ASString v19; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::CharPosInfo v20; // [rsp+70h] [rbp-90h] BYREF
  __int64 v21; // [rsp+E0h] [rbp-20h]
  char *pstr; // [rsp+E8h] [rbp-18h]
  int v23; // [rsp+F0h] [rbp-10h]
  __int64 v24; // [rsp+100h] [rbp+0h]
  char v25[24]; // [rsp+108h] [rbp+8h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+130h] [rbp+30h] BYREF
  Scaleform::GFx::ASString v27; // [rsp+140h] [rbp+40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+148h] [rbp+48h] BYREF

  v24 = -2i64;
  pNode = (Scaleform::GFx::ASStringNode *)&v20;
  Scaleform::Render::Cxform::Cxform(&v20.ColorTransform);
  *(_OWORD *)&v20.Matrix_1.M[0][0] = _xmm;
  *(__m128 *)&v20.Matrix_1.M[1][0] = _xmm;
  v20.pFilters.pObject = 0i64;
  v20.CharacterId.Id = 0x40000;
  *(_DWORD *)&v20.ClipDepth = 0;
  v20.Ratio = 0.0;
  v20.Depth = 0;
  *(_WORD *)&v20.BlendMode = 256;
  v20.ClassName = 0i64;
  this->vfptr[1].__vecDelDtor(this, (unsigned int)&v20);
  if ( v23 )
  {
    if ( v23 == 1 )
    {
      Scaleform::GFx::DisplayList::MoveDisplayObject(&m->mDisplayList, m, &v20);
      goto LABEL_27;
    }
    if ( v23 != 2 )
      goto LABEL_27;
    pObject = m->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v5 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pObject->vfptr[59].__vecDelDtor)(pObject);
    if ( pstr )
    {
      v6 = Scaleform::GFx::ASStringManager::CreateString(v5, &v27, pstr);
      v7 = 8;
    }
    else
    {
      v6 = Scaleform::GFx::ASStringManager::CreateEmptyString(v5, &result);
      v7 = 4;
    }
    pNode = v6->pNode;
    ++pNode->RefCount;
    if ( (v7 & 8) != 0 )
    {
      v7 &= ~8u;
      v8 = v27.pNode;
      v9 = v27.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
    if ( (v7 & 4) != 0 )
    {
      v10 = result.pNode;
      v9 = result.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASStringNode **, char *))m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[123].__vecDelDtor)(
      m,
      &v20,
      &pNode,
      v25);
  }
  else
  {
    v11 = m->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v12 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))v11->vfptr[59].__vecDelDtor)(v11);
    if ( pstr )
    {
      v13 = Scaleform::GFx::ASStringManager::CreateString(v12, &v19, pstr);
      v14 = 2;
    }
    else
    {
      v13 = Scaleform::GFx::ASStringManager::CreateEmptyString(v12, &v18);
      v14 = 1;
    }
    pNode = v13->pNode;
    ++pNode->RefCount;
    if ( (v14 & 2) != 0 )
    {
      v14 &= ~2u;
      v15 = v19.pNode;
      v9 = v19.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    if ( (v14 & 1) != 0 )
    {
      v16 = v18.pNode;
      v9 = v18.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASStringNode **, __int64, _QWORD, int, int, _QWORD, _QWORD))m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[118].__vecDelDtor)(
      m,
      &v20,
      &pNode,
      v21,
      0i64,
      -1,
      4,
      0i64,
      0i64);
  }
  v17 = pNode;
  v9 = pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
LABEL_27:
  pNode = (Scaleform::GFx::ASStringNode *)&v20;
  if ( v20.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v20.pFilters.pObject);
}

// File Line: 1159
// RVA: 0x9156A0
void __fastcall Scaleform::GFx::PlaceObject3Tag::Unpack(
        Scaleform::GFx::PlaceObject3Tag *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  char *pData; // r14
  _BYTE *v5; // r10
  Scaleform::GFx::Resource *v6; // rbx
  char v7; // si
  unsigned __int64 v8; // r8
  char v9; // r15
  unsigned int CurBitIndex; // r9d
  unsigned __int16 v11; // cx
  unsigned __int64 CurByteIndex; // r8
  char v13; // al
  unsigned __int16 v14; // cx
  unsigned __int16 v15; // cx
  char v16; // al
  unsigned __int16 v17; // cx
  Scaleform::Render::FilterSet *v18; // rax
  Scaleform::GFx::Resource *v19; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx
  char v21; // cl
  char v22; // dl
  char v23; // r14
  Scaleform::Render::FilterSet *v24; // rcx
  Scaleform::Render::FilterSet *v25; // rbx
  Scaleform::Render::FilterSet *v26; // rax
  Scaleform::Render::FilterSet *v27; // rax
  Scaleform::Render::RenderBuffer *v28; // rcx
  bool v29; // dl
  char v30; // al
  char v31; // al
  char v32; // si
  Scaleform::GFx::StreamContext ps; // [rsp+28h] [rbp-28h] BYREF

  pData = this->pData;
  v5 = this->pData;
  ps.pData = this->pData;
  ps.DataSize = -1i64;
  v6 = 0i64;
  ps.CurByteIndex = 0i64;
  ps.CurBitIndex = 0;
  v7 = this->pData[0];
  v8 = 1i64;
  if ( v7 < 0 )
    v8 = 9i64;
  ps.CurByteIndex = v8;
  ps.CurBitIndex = 0;
  v9 = pData[v8];
  ps.CurByteIndex = v8 + 1;
  CurBitIndex = 0;
  ps.CurBitIndex = 0;
  v11 = *(_WORD *)&pData[v8 + 1];
  CurByteIndex = v8 + 3;
  ps.CurByteIndex = CurByteIndex;
  data->Pos.Depth = v11;
  if ( (v9 & 8) != 0 )
  {
    data->Pos.Flags.Flags |= 0x100u;
    data->Pos.ClassName = &this->pData[CurByteIndex];
    ps.CurBitIndex = 0;
    do
    {
      v13 = pData[CurByteIndex++];
      ps.CurByteIndex = CurByteIndex;
    }
    while ( v13 );
  }
  if ( (v7 & 2) != 0 )
  {
    data->Pos.Flags.Flags |= 2u;
    CurBitIndex = 0;
    ps.CurBitIndex = 0;
    v14 = *(_WORD *)&pData[CurByteIndex];
    CurByteIndex += 2i64;
    ps.CurByteIndex = CurByteIndex;
    data->Pos.CharacterId.Id = v14;
  }
  if ( (v7 & 4) != 0 )
  {
    data->Pos.Flags.Flags |= 4u;
    Scaleform::GFx::StreamContext::ReadMatrix(&ps, &data->Pos.Matrix_1);
    CurBitIndex = ps.CurBitIndex;
    CurByteIndex = ps.CurByteIndex;
    v5 = ps.pData;
  }
  if ( (v7 & 8) != 0 )
  {
    data->Pos.Flags.Flags |= 8u;
    Scaleform::GFx::StreamContext::ReadCxformRgba(&ps, &data->Pos.ColorTransform);
    CurBitIndex = ps.CurBitIndex;
    CurByteIndex = ps.CurByteIndex;
    v5 = ps.pData;
  }
  if ( (v7 & 0x10) != 0 )
  {
    data->Pos.Flags.Flags |= 0x10u;
    if ( CurBitIndex )
      ps.CurByteIndex = ++CurByteIndex;
    CurBitIndex = 0;
    ps.CurBitIndex = 0;
    v15 = *(_WORD *)&v5[CurByteIndex];
    CurByteIndex += 2i64;
    ps.CurByteIndex = CurByteIndex;
    data->Pos.Ratio = (float)v15 * 0.000015259022;
  }
  if ( (v7 & 0x20) != 0 )
  {
    if ( CurBitIndex )
      ps.CurByteIndex = ++CurByteIndex;
    data->Name = &this->pData[CurByteIndex];
    CurBitIndex = 0;
    ps.CurBitIndex = 0;
    do
    {
      v16 = v5[CurByteIndex++];
      ps.CurByteIndex = CurByteIndex;
    }
    while ( v16 );
  }
  else
  {
    data->Name = 0i64;
  }
  if ( (v7 & 0x40) != 0 )
  {
    if ( CurBitIndex )
      ps.CurByteIndex = ++CurByteIndex;
    CurBitIndex = 0;
    ps.CurBitIndex = 0;
    v17 = *(_WORD *)&v5[CurByteIndex];
    CurByteIndex += 2i64;
    ps.CurByteIndex = CurByteIndex;
    data->Pos.ClipDepth = v17;
    data->Pos.Flags.Flags |= 0x40u;
  }
  if ( (v9 & 1) != 0 )
  {
    data->Pos.Flags.Flags |= 0x20u;
    v18 = (Scaleform::Render::FilterSet *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                            Scaleform::Memory::pGlobalHeap,
                                            56i64);
    if ( v18 )
    {
      Scaleform::Render::FilterSet::FilterSet(v18, 0i64);
      v6 = v19;
    }
    if ( (unsigned int)Scaleform::GFx::LoadFilters<Scaleform::GFx::StreamContext>(
                         &ps,
                         (Scaleform::Render::FilterSet *)v6) )
    {
      if ( v6 )
        Scaleform::Render::RenderBuffer::AddRef(v6);
      pObject = (Scaleform::Render::RenderBuffer *)data->Pos.pFilters.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      data->Pos.pFilters.pObject = (Scaleform::Render::FilterSet *)v6;
    }
    if ( v6 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6);
    v5 = ps.pData;
    CurByteIndex = ps.CurByteIndex;
    CurBitIndex = ps.CurBitIndex;
  }
  if ( (v9 & 2) != 0 )
  {
    data->Pos.Flags.Flags |= 0x80u;
    if ( CurBitIndex )
      ps.CurByteIndex = ++CurByteIndex;
    CurBitIndex = 0;
    ps.CurBitIndex = 0;
    v21 = v5[CurByteIndex++];
    ps.CurByteIndex = CurByteIndex;
    v22 = v21;
    if ( (unsigned __int8)(v21 - 1) > 0xDu )
      v22 = 1;
    data->Pos.BlendMode = v22;
  }
  if ( (v9 & 4) != 0 )
  {
    if ( CurBitIndex )
      ps.CurByteIndex = ++CurByteIndex;
    ps.CurBitIndex = 0;
    v23 = v5[CurByteIndex];
    ps.CurByteIndex = CurByteIndex + 1;
    v24 = data->Pos.pFilters.pObject;
    if ( v24 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v24);
    v25 = data->Pos.pFilters.pObject;
    if ( v23 == 1 )
    {
      if ( !v25 )
      {
        v26 = (Scaleform::Render::FilterSet *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                56i64,
                                                0i64);
        if ( v26 )
        {
          Scaleform::Render::FilterSet::FilterSet(v26, 0i64);
          v25 = v27;
        }
        else
        {
          v25 = 0i64;
        }
        if ( v25 )
          Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v25);
        v28 = (Scaleform::Render::RenderBuffer *)data->Pos.pFilters.pObject;
        if ( v28 )
          Scaleform::RefCountImpl::Release(v28);
        data->Pos.pFilters.pObject = v25;
      }
      v29 = 1;
    }
    else
    {
      if ( !v25 )
      {
LABEL_64:
        if ( v25 )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v25);
        pData = this->pData;
        v5 = ps.pData;
        CurByteIndex = ps.CurByteIndex;
        CurBitIndex = ps.CurBitIndex;
        goto LABEL_67;
      }
      v29 = 0;
    }
    Scaleform::Render::FilterSet::SetCacheAsBitmap(v25, v29);
    goto LABEL_64;
  }
LABEL_67:
  if ( (v9 & 0x20) != 0 )
  {
    if ( CurBitIndex )
      ps.CurByteIndex = ++CurByteIndex;
    ps.CurBitIndex = 0;
    v30 = v5[CurByteIndex];
    ps.CurByteIndex = CurByteIndex + 1;
    data->Pos.Visible = v30;
    data->Pos.Flags.Flags |= 0x200u;
  }
  if ( (v7 & 0x80) != 0 )
    ((void (__fastcall *)(Scaleform::GFx::PlaceObject3Tag *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *, Scaleform::GFx::StreamContext *, char *, __int64))this->vfptr[1].IsRemoveTag)(
      this,
      data,
      &ps,
      pData,
      -2i64);
  else
    data->pEventHandlers = 0i64;
  v31 = (unsigned __int8)v7 >> 1;
  v32 = v7 & 1;
  data->PlaceType = Place_Add;
  if ( (v31 & 1) != 0 )
  {
    if ( v32 )
      data->PlaceType = Place_Replace;
  }
  else
  {
    data->PlaceType = v32 != 0;
  }
}

// File Line: 1274
// RVA: 0x8B3560
void __fastcall Scaleform::GFx::PlaceObject2Tag::AddToTimelineSnapshot(
        Scaleform::GFx::PlaceObject2Tag *this,
        Scaleform::GFx::TimelineSnapshot *psnapshot,
        unsigned int frame)
{
  char v6; // si
  __int64 v7; // rax
  __int64 v8; // rdi
  unsigned __int16 v9; // dx
  char v10; // al
  char v11; // cl
  int v12; // r9d
  __int64 Size; // rdx
  Scaleform::GFx::TimelineSnapshot::SnapshotElement **Data; // r10
  __int64 v15; // r8
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v16; // rdi
  __int16 v17; // ax
  __int16 v18; // ax
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v19; // rax
  __int16 v20; // [rsp+40h] [rbp+8h] BYREF

  this->vfptr->Trace(this, "\n");
  v6 = 1;
  v7 = 1i64;
  if ( this->pData[0] < 0 )
    v7 = 9i64;
  v8 = 0i64;
  v9 = *(_WORD *)&this->pData[v7];
  v10 = this->pData[0];
  v11 = v10 & 1;
  if ( (v10 & 2) == 0 )
  {
    if ( v11 )
      goto LABEL_8;
LABEL_7:
    v6 = 0;
    goto LABEL_8;
  }
  if ( !v11 )
    goto LABEL_7;
  v6 = 2;
LABEL_8:
  v12 = v9;
  Size = psnapshot->SnapshotSortedArray.Data.Size;
  if ( Size <= 0 )
    goto LABEL_60;
  Data = psnapshot->SnapshotSortedArray.Data.Data;
  do
  {
    v15 = (Size >> 1) + v8;
    if ( v12 >= Data[v15]->Depth )
    {
      v8 = v15 + 1;
      Size += -1 - (Size >> 1);
    }
    else
    {
      Size >>= 1;
    }
  }
  while ( Size > 0 );
  if ( v8 && (v16 = Data[v8 - 1], v16->Depth == v12) && v16 && (v16->Flags & 2) == 0 )
  {
    if ( v6 == 1 )
    {
      ((void (__fastcall *)(Scaleform::GFx::PlaceObject2Tag *, __int16 *))this->vfptr[1].ExecuteWithPriority)(
        this,
        &v20);
      v18 = v20;
      if ( (v20 & 4) != 0 )
        v16->Tags.pMatrixTag = this;
      if ( (v18 & 8) != 0 )
        v16->Tags.pCxFormTag = this;
      if ( (v18 & 0x20) != 0 )
        v16->Tags.pFiltersTag = this;
      if ( (v18 & 0x80u) != 0 )
        v16->Tags.pBlendModeTag = this;
      if ( (v18 & 1) != 0 )
        v16->Tags.pDepthTag = this;
      if ( (v18 & 0x40) != 0 )
        v16->Tags.pClipDepthTag = this;
      if ( (v18 & 0x10) != 0 )
        v16->Tags.pRatioTag = this;
      if ( (v18 & 2) != 0 )
        v16->Tags.pCharIdTag = this;
      if ( (v18 & 0x100) != 0 )
        v16->Tags.pClassNameTag = this;
    }
    else if ( v6 == 2 )
    {
      if ( v16->PlaceType )
        v16->PlaceType = 2;
      ((void (__fastcall *)(Scaleform::GFx::PlaceObject2Tag *, __int16 *))this->vfptr[1].ExecuteWithPriority)(
        this,
        &v20);
      v17 = v20;
      if ( (v20 & 4) != 0 )
        v16->Tags.pMatrixTag = this;
      if ( (v17 & 8) != 0 )
        v16->Tags.pCxFormTag = this;
      if ( (v17 & 0x20) != 0 )
        v16->Tags.pFiltersTag = this;
      if ( (v17 & 0x80u) != 0 )
        v16->Tags.pBlendModeTag = this;
      if ( (v17 & 1) != 0 )
        v16->Tags.pDepthTag = this;
      if ( (v17 & 0x40) != 0 )
        v16->Tags.pClipDepthTag = this;
      if ( (v17 & 0x10) != 0 )
        v16->Tags.pRatioTag = this;
      if ( (v17 & 2) != 0 )
        v16->Tags.pCharIdTag = this;
      if ( (v17 & 0x100) != 0 )
        v16->Tags.pClassNameTag = this;
      v16->CreateFrame = frame;
    }
    else
    {
      v16->Tags.pClassNameTag = this;
      v16->Tags.pCharIdTag = this;
      v16->Tags.pRatioTag = this;
      v16->Tags.pClipDepthTag = this;
      v16->Tags.pDepthTag = this;
      v16->Tags.pBlendModeTag = this;
      v16->Tags.pFiltersTag = this;
      v16->Tags.pCxFormTag = this;
      v16->Tags.pMatrixTag = this;
      v16->Tags.pMainTag = this;
      v16->CreateFrame = frame;
    }
  }
  else
  {
LABEL_60:
    v19 = Scaleform::GFx::TimelineSnapshot::Add(psnapshot, v12);
    v19->PlaceType = v6;
    v19->Tags.pClassNameTag = this;
    v19->Tags.pCharIdTag = this;
    v19->Tags.pRatioTag = this;
    v19->Tags.pClipDepthTag = this;
    v19->Tags.pDepthTag = this;
    v19->Tags.pBlendModeTag = this;
    v19->Tags.pFiltersTag = this;
    v19->Tags.pCxFormTag = this;
    v19->Tags.pMatrixTag = this;
    v19->Tags.pMainTag = this;
    v19->CreateFrame = frame;
  }
}g = this;
    v19->Tags.pCxFormTag = this;
    v1

// File Line: 1348
// RVA: 0x8B3810
void __fastcall Scaleform::GFx::PlaceObject3Tag::AddToTimelineSnapshot(
        Scaleform::GFx::PlaceObject3Tag *this,
        Scaleform::GFx::TimelineSnapshot *psnapshot,
        unsigned int frame)
{
  char v6; // si
  __int64 v7; // rax
  __int64 v8; // rdi
  unsigned __int16 v9; // dx
  char v10; // al
  char v11; // cl
  int v12; // r9d
  __int64 Size; // rdx
  Scaleform::GFx::TimelineSnapshot::SnapshotElement **Data; // r10
  __int64 v15; // r8
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v16; // rdi
  __int16 v17; // ax
  __int16 v18; // ax
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v19; // rax
  __int16 v20; // [rsp+40h] [rbp+8h] BYREF

  this->vfptr->Trace(this, "\n");
  v6 = 1;
  v7 = 1i64;
  if ( this->pData[0] < 0 )
    v7 = 9i64;
  v8 = 0i64;
  v9 = *(_WORD *)&this->pData[v7 + 1];
  v10 = this->pData[0];
  v11 = v10 & 1;
  if ( (v10 & 2) == 0 )
  {
    if ( v11 )
      goto LABEL_8;
LABEL_7:
    v6 = 0;
    goto LABEL_8;
  }
  if ( !v11 )
    goto LABEL_7;
  v6 = 2;
LABEL_8:
  v12 = v9;
  Size = psnapshot->SnapshotSortedArray.Data.Size;
  if ( Size <= 0 )
    goto LABEL_60;
  Data = psnapshot->SnapshotSortedArray.Data.Data;
  do
  {
    v15 = (Size >> 1) + v8;
    if ( v12 >= Data[v15]->Depth )
    {
      v8 = v15 + 1;
      Size += -1 - (Size >> 1);
    }
    else
    {
      Size >>= 1;
    }
  }
  while ( Size > 0 );
  if ( v8 && (v16 = Data[v8 - 1], v16->Depth == v12) && v16 && (v16->Flags & 2) == 0 )
  {
    if ( v6 == 1 )
    {
      ((void (__fastcall *)(Scaleform::GFx::PlaceObject3Tag *, __int16 *))this->vfptr[1].ExecuteWithPriority)(
        this,
        &v20);
      v18 = v20;
      if ( (v20 & 4) != 0 )
        v16->Tags.pMatrixTag = this;
      if ( (v18 & 8) != 0 )
        v16->Tags.pCxFormTag = this;
      if ( (v18 & 0x20) != 0 )
        v16->Tags.pFiltersTag = this;
      if ( (v18 & 0x80u) != 0 )
        v16->Tags.pBlendModeTag = this;
      if ( (v18 & 1) != 0 )
        v16->Tags.pDepthTag = this;
      if ( (v18 & 0x40) != 0 )
        v16->Tags.pClipDepthTag = this;
      if ( (v18 & 0x10) != 0 )
        v16->Tags.pRatioTag = this;
      if ( (v18 & 2) != 0 )
        v16->Tags.pCharIdTag = this;
      if ( (v18 & 0x100) != 0 )
        v16->Tags.pClassNameTag = this;
    }
    else if ( v6 == 2 )
    {
      if ( v16->PlaceType )
        v16->PlaceType = 2;
      ((void (__fastcall *)(Scaleform::GFx::PlaceObject3Tag *, __int16 *))this->vfptr[1].ExecuteWithPriority)(
        this,
        &v20);
      v17 = v20;
      if ( (v20 & 4) != 0 )
        v16->Tags.pMatrixTag = this;
      if ( (v17 & 8) != 0 )
        v16->Tags.pCxFormTag = this;
      if ( (v17 & 0x20) != 0 )
        v16->Tags.pFiltersTag = this;
      if ( (v17 & 0x80u) != 0 )
        v16->Tags.pBlendModeTag = this;
      if ( (v17 & 1) != 0 )
        v16->Tags.pDepthTag = this;
      if ( (v17 & 0x40) != 0 )
        v16->Tags.pClipDepthTag = this;
      if ( (v17 & 0x10) != 0 )
        v16->Tags.pRatioTag = this;
      if ( (v17 & 2) != 0 )
        v16->Tags.pCharIdTag = this;
      if ( (v17 & 0x100) != 0 )
        v16->Tags.pClassNameTag = this;
      v16->CreateFrame = frame;
    }
    else
    {
      v16->Tags.pClassNameTag = this;
      v16->Tags.pCharIdTag = this;
      v16->Tags.pRatioTag = this;
      v16->Tags.pClipDepthTag = this;
      v16->Tags.pDepthTag = this;
      v16->Tags.pBlendModeTag = this;
      v16->Tags.pFiltersTag = this;
      v16->Tags.pCxFormTag = this;
      v16->Tags.pMatrixTag = this;
      v16->Tags.pMainTag = this;
      v16->CreateFrame = frame;
    }
  }
  else
  {
LABEL_60:
    v19 = Scaleform::GFx::TimelineSnapshot::Add(psnapshot, v12);
    v19->PlaceType = v6;
    v19->Tags.pClassNameTag = this;
    v19->Tags.pCharIdTag = this;
    v19->Tags.pRatioTag = this;
    v19->Tags.pClipDepthTag = this;
    v19->Tags.pDepthTag = this;
    v19->Tags.pBlendModeTag = this;
    v19->Tags.pFiltersTag = this;
    v19->Tags.pCxFormTag = this;
    v19->Tags.pMatrixTag = this;
    v19->Tags.pMainTag = this;
    v19->CreateFrame = frame;
  }
}g = this;
    v19->Tags.pCxFormTag = this;
  

// File Line: 1426
// RVA: 0x8F86A0
void __fastcall Scaleform::GFx::RemoveObjectTag::Read(
        Scaleform::GFx::RemoveObjectTag *this,
        Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  unsigned int DataSize; // eax
  __int64 Pos; // r9
  unsigned __int16 v7; // r8
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rbx
  unsigned int v9; // eax
  __int64 v10; // r9
  unsigned __int16 v11; // r8

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  DataSize = pAltStream->Stream.DataSize;
  pAltStream->Stream.UnusedBits = 0;
  if ( (int)(DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v7 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  this->Id = v7;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v9 = p_ProcessInfo->Stream.DataSize;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( (int)(v9 - p_ProcessInfo->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
  v10 = p_ProcessInfo->Stream.Pos;
  v11 = (unsigned __int8)p_ProcessInfo->Stream.pBuffer[v10] | ((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v10 + 1)] << 8);
  p_ProcessInfo->Stream.Pos = v10 + 2;
  this->Depth = v11;
}

// File Line: 1432
// RVA: 0x8CA380
void __fastcall Scaleform::GFx::RemoveObjectTag::Execute(
        Scaleform::GFx::RemoveObjectTag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  int Depth; // r8d
  Scaleform::GFx::ResourceId id; // [rsp+30h] [rbp+8h] BYREF

  Depth = this->Depth;
  id.Id = this->Id;
  Scaleform::GFx::DisplayList::RemoveDisplayObject(&m->mDisplayList, m, Depth, (Scaleform::GFx::ResourceId)&id);
}

// File Line: 1453
// RVA: 0x8F8630
void __fastcall Scaleform::GFx::RemoveObject2Tag::Read(
        Scaleform::GFx::RemoveObject2Tag *this,
        Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  unsigned int DataSize; // eax
  __int64 Pos; // r9
  unsigned __int16 v6; // r8

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  DataSize = pAltStream->Stream.DataSize;
  pAltStream->Stream.UnusedBits = 0;
  if ( (int)(DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  this->Depth = v6;
}

// File Line: 1458
// RVA: 0x8CA350
void __fastcall Scaleform::GFx::RemoveObject2Tag::Execute(
        Scaleform::GFx::RemoveObject2Tag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  int Depth; // r8d
  Scaleform::GFx::ResourceId id; // [rsp+30h] [rbp+8h] BYREF

  Depth = this->Depth;
  id.Id = 0x40000;
  Scaleform::GFx::DisplayList::RemoveDisplayObject(&m->mDisplayList, m, Depth, (Scaleform::GFx::ResourceId)&id);
}

// File Line: 1463
// RVA: 0x8B3BF0
void __fastcall Scaleform::GFx::RemoveObject2Tag::AddToTimelineSnapshot(
        Scaleform::GFx::RemoveObject2Tag *this,
        Scaleform::GFx::TimelineSnapshot *psnapshot,
        __int64 __formal)
{
  __int64 Size; // r8
  int Depth; // r11d
  __int64 v7; // r9
  Scaleform::GFx::TimelineSnapshot::SnapshotElement **Data; // r10
  __int64 v9; // rdx
  __int64 v10; // rax
  unsigned __int64 v11; // rdi
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *v12; // rbx
  __int64 v13; // rcx
  __int64 v14; // rax
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *v15; // rbx
  bool v16; // zf
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v17; // rax
  int v18; // ecx
  unsigned __int64 v19; // [rsp+40h] [rbp+8h] BYREF

  ((void (__fastcall *)(Scaleform::GFx::RemoveObject2Tag *, const char *, __int64))this->vfptr->Trace)(
    this,
    "\n",
    __formal);
  Size = psnapshot->SnapshotSortedArray.Data.Size;
  Depth = this->Depth;
  v7 = 0i64;
  if ( Size <= 0 )
    goto LABEL_9;
  Data = psnapshot->SnapshotSortedArray.Data.Data;
  do
  {
    v9 = (Size >> 1) + v7;
    if ( Depth >= Data[v9]->Depth )
    {
      v7 = v9 + 1;
      Size += -1 - (Size >> 1);
    }
    else
    {
      Size >>= 1;
    }
  }
  while ( Size > 0 );
  if ( !v7 || (v10 = (__int64)Data[v7 - 1], v11 = v7 - 1, *(_DWORD *)(v10 + 20) != Depth) )
  {
LABEL_9:
    v11 = v19;
    v10 = 0i64;
  }
  v19 = v10;
  if ( !v10 )
    goto LABEL_19;
  if ( *(_BYTE *)(v10 + 104) )
  {
    v12 = (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)psnapshot->SnapshotSortedArray.Data.Data[v11];
    v12->pNext[1].pNext = v12[1].pNext;
    v12[1].pNext->pNext = v12->pNext;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      &psnapshot->SnapshotSortedArray,
      v11);
    v12->pNext = psnapshot->SnapshotHeap.FirstEmptySlot;
    psnapshot->SnapshotHeap.FirstEmptySlot = v12;
    v19 = 0i64;
LABEL_19:
    if ( psnapshot->Direction == Direction_Forward )
    {
      v17 = Scaleform::GFx::TimelineSnapshot::Add(psnapshot, this->Depth);
      v18 = this->Depth;
      v19 = (unsigned __int64)v17;
      v17->Depth = v18;
      *(_BYTE *)(v19 + 104) = 3;
      *(_BYTE *)(v19 + 105) |= 2u;
    }
    return;
  }
  v13 = *(_QWORD *)(v10 + 24);
  if ( v13 )
  {
    if ( psnapshot->Direction == Direction_Forward )
    {
      v14 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 72i64))(v13);
      if ( v14 )
        ((void (__fastcall *)(Scaleform::GFx::RemoveObject2Tag *, unsigned __int64 *, __int64))this->vfptr[1].Execute)(
          this,
          &v19,
          v14);
    }
  }
  if ( !v19 )
    goto LABEL_19;
  v15 = (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)psnapshot->SnapshotSortedArray.Data.Data[v11];
  v15->pNext[1].pNext = v15[1].pNext;
  v15[1].pNext->pNext = v15->pNext;
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
    &psnapshot->SnapshotSortedArray,
    v11);
  v15->pNext = psnapshot->SnapshotHeap.FirstEmptySlot;
  v16 = v19 == 0;
  psnapshot->SnapshotHeap.FirstEmptySlot = v15;
  if ( v16 )
    goto LABEL_19;
}

// File Line: 1528
// RVA: 0x8CA3B0
void __fastcall Scaleform::GFx::SetBackgroundColorTag::Execute(
        Scaleform::GFx::SetBackgroundColorTag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  float v4; // xmm0_4
  float v5; // xmm0_4
  unsigned int Raw; // [rsp+38h] [rbp+10h] BYREF

  pMovieImpl = m->pASRoot->pMovieImpl;
  if ( (pMovieImpl->Flags & 0x20000) == 0 )
  {
    v4 = ((float (__fastcall *)(Scaleform::GFx::MovieImpl *))pMovieImpl->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[34].__vecDelDtor)(m->pASRoot->pMovieImpl)
       * 255.0;
    if ( v4 <= 0.0 )
      v5 = v4 - 0.5;
    else
      v5 = v4 + 0.5;
    this->Color.Channels.Alpha = (int)v5;
    Raw = this->Color.Raw;
    pMovieImpl->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[32].__vecDelDtor(
      pMovieImpl,
      (unsigned int)&Raw);
    pMovieImpl->Flags |= 0x20000u;
  }
}

