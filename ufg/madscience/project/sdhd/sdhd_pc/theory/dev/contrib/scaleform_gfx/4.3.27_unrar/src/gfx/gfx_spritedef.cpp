// File Line: 44
// RVA: 0x8A7B00
void __fastcall Scaleform::GFx::SpriteDef::~SpriteDef(Scaleform::GFx::SpriteDef *this)
{
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v1; // rsi
  unsigned int v2; // ebp
  __int64 v3; // rbx
  signed __int64 v4; // rbx
  unsigned int i; // edi
  void (__fastcall ***v6)(_QWORD, _QWORD); // rcx

  v1 = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::SpriteDef::`vftable';
  v2 = 0;
  if ( this->Playlist.Data.Size )
  {
    v3 = 0i64;
    do
    {
      v4 = (signed __int64)&v1[7].pTable[v3];
      for ( i = 0; i < *(_DWORD *)(v4 + 8); ++i )
      {
        v6 = *(void (__fastcall ****)(_QWORD, _QWORD))(*(_QWORD *)v4 + 8i64 * i);
        (**v6)(v6, 0i64);
      }
      *(_QWORD *)v4 = 0i64;
      *(_DWORD *)(v4 + 8) = 0;
      v3 = ++v2;
    }
    while ( (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *)v2 < v1[8].pTable );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1[10].pTable);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1[7].pTable);
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear(v1 + 5);
  v1->pTable = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *)&Scaleform::GFx::CharacterDef::`vftable';
  v1->pTable = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *)&Scaleform::GFx::Resource::`vftable';
}

// File Line: 62
// RVA: 0x8B11D0
void __fastcall Scaleform::GFx::SpriteDef::AddFrameName(Scaleform::GFx::SpriteDef *this, Scaleform::String *name, Scaleform::GFx::LogState *plog)
{
  Scaleform::GFx::LogState *v3; // rdi
  __int64 v4; // r8
  Scaleform::String *v5; // rsi
  Scaleform::GFx::SpriteDef *v6; // rbx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v7; // rax
  unsigned __int64 v8; // r8
  __int64 v9; // rcx
  __int64 v10; // rdx
  char v11; // al
  __int64 v12; // rdx
  char v13; // al
  char v14; // al
  _QWORD v15[2]; // [rsp+20h] [rbp-28h]
  Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+30h] [rbp-18h]
  int v17; // [rsp+50h] [rbp+8h]

  v3 = plog;
  v4 = (unsigned int)this->LoadingFrame;
  v5 = name;
  v6 = this;
  if ( (signed int)v4 < 0 || (signed int)v4 >= this->FrameCount )
  {
    if ( v3 )
    {
      LODWORD(v15[0]) = this->FrameCount;
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v3->vfptr,
        "AddFrameName(%d, '%s') -- frame is out of range (frameCount = %d; skipping",
        v4,
        (name->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
        v15[0]);
    }
  }
  else
  {
    v7 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetAlt<Scaleform::String>(
           (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&this->NamedFrames.mHash.pTable,
           name);
    if ( v7 && v3 )
    {
      LODWORD(v15[0]) = v7->SizeMask;
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v3->vfptr,
        "AddFrameName(%d, '%s') -- frame name already assigned to frame %d; overriding",
        (unsigned int)v6->LoadingFrame,
        (v5->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
        v15[0]);
    }
    if ( Scaleform::String::GetLength(v5) )
    {
      v8 = v5->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
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
            v6->Flags |= 1u;
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
            v6->Flags |= 2u;
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
            v6->Flags |= 4u;
            break;
          }
        }
      }
    }
LABEL_19:
    v17 = v6->LoadingFrame;
    key.pSecond = (const unsigned int *)&v17;
    key.pFirst = v5;
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v6->NamedFrames.mHash.pTable,
      &v6->NamedFrames,
      &key);
  }
}

// File Line: 94
// RVA: 0x8F92B0
void __fastcall Scaleform::GFx::SpriteDef::Read(Scaleform::GFx::SpriteDef *this, Scaleform::GFx::LoadProcess *p, __int64 charId)
{
  unsigned __int16 *v3; // rdi
  Scaleform::GFx::LoadProcess *v4; // rsi
  Scaleform::GFx::SpriteDef *v5; // r13
  Scaleform::GFx::Stream *v6; // rbx
  __int64 v7; // rcx
  unsigned int v8; // ebp
  __int64 v9; // r9
  unsigned __int16 v10; // r8
  signed int v11; // eax
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,264>,Scaleform::ArrayDefaultPolicy> *v12; // r14
  __int64 v13; // r8
  __int64 v14; // r12
  Scaleform::GFx::LoadStates *v15; // r15
  Scaleform::GFx::ProgressHandler *v16; // r15
  int v17; // er14
  int v18; // ebp
  int v19; // esi
  Scaleform::GFx::TagType v20; // edi
  __int64 v21; // r8
  __int64 v22; // r8
  void (__fastcall *v23)(Scaleform::GFx::LoadProcess *, Scaleform::GFx::TagInfo *); // r8
  __int64 v24; // rax
  int v25; // edi
  signed int v26; // edx
  unsigned int v27; // eax
  int v28; // ecx
  __int64 v29; // rdx
  __int64 v30; // r8
  __int64 v31[2]; // [rsp+20h] [rbp-88h]
  Scaleform::GFx::TagInfo pTagInfo; // [rsp+38h] [rbp-70h]
  Scaleform::String v33; // [rsp+48h] [rbp-60h]
  Scaleform::GFx::TagType v34; // [rsp+50h] [rbp-58h]
  int v35; // [rsp+54h] [rbp-54h]
  int v36; // [rsp+58h] [rbp-50h]
  int v37; // [rsp+5Ch] [rbp-4Ch]
  unsigned int v38; // [rsp+B0h] [rbp+8h]
  Scaleform::GFx::LoadProcess *v39; // [rsp+B8h] [rbp+10h]
  unsigned __int16 *v40; // [rsp+C0h] [rbp+18h]
  Scaleform::String src; // [rsp+C8h] [rbp+20h]

  v40 = (unsigned __int16 *)charId;
  v39 = p;
  v3 = (unsigned __int16 *)charId;
  v4 = p;
  v5 = this;
  v6 = p->pAltStream;
  if ( !v6 )
    v6 = &p->ProcessInfo.Stream;
  v7 = v6->TagStackEntryCount - 1;
  if ( (unsigned int)v7 >= 2 )
    v8 = 0;
  else
    v8 = v6->TagStack[v7];
  v38 = v8;
  p->LoadState = 1;
  p->pTimelineDef = (Scaleform::GFx::TimelineIODef *)&v5->vfptr;
  v6->UnusedBits = 0;
  if ( (signed int)(v6->DataSize - v6->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v6, 2);
  v9 = v6->Pos;
  v10 = (unsigned __int8)v6->pBuffer[v9] | (unsigned __int16)((unsigned __int8)v6->pBuffer[(unsigned int)(v9 + 1)] << 8);
  v6->Pos = v9 + 2;
  v11 = v10;
  if ( (signed int)v10 < 1 )
    v11 = 1;
  v5->FrameCount = v11;
  v12 = &v5->Playlist.Data;
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,264>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v5->Playlist.Data,
    v11);
  v13 = (unsigned int)v5->FrameCount;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v6->vfptr,
    "  frames = %d\n");
  for ( v5->LoadingFrame = 0; v6->FilePos + v6->Pos - v6->DataSize < v8; v3 = v40 )
  {
    v14 = (unsigned int)Scaleform::GFx::Stream::OpenTag(v6, &pTagInfo);
    Scaleform::String::String(
      &src,
      (const char *)((v4->pLoadData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    v15 = v4->pLoadStates.pObject;
    if ( v15->pProgressHandler.pObject )
    {
      v16 = v15->pProgressHandler.pObject;
      v17 = pTagInfo.TagDataOffset;
      v18 = pTagInfo.TagLength;
      v19 = pTagInfo.TagOffset;
      v20 = pTagInfo.TagType;
      Scaleform::String::String(&v33, &src);
      v34 = v20;
      v35 = v19;
      v36 = v18;
      v37 = v17;
      LOBYTE(v21) = 1;
      ((void (__fastcall *)(Scaleform::GFx::ProgressHandler *, Scaleform::String *, __int64))v16->vfptr[2].__vecDelDtor)(
        v16,
        &v33,
        v21);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v33.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v12 = &v5->Playlist.Data;
      v8 = v38;
      v3 = v40;
      v4 = v39;
    }
    if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    if ( (_DWORD)v14 == 1 )
    {
      if ( v5->LoadingFrame == LODWORD(v5->Playlist.Data.Size) )
      {
        Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,264>,Scaleform::ArrayDefaultPolicy>::Resize(
          v12,
          v5->Playlist.Data.Size + 1);
        LODWORD(v31[0]) = v5->LoadingFrame + 1;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v6->vfptr,
          "An extra frame is found for sprite id = %d, framecnt = %d, actual frames = %d",
          *v3,
          (unsigned int)v5->FrameCount,
          v31[0]);
      }
      Scaleform::GFx::LoadProcess::CommitFrameTags(v4);
      v22 = *v3;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v6->vfptr,
        "  ShowFrame (sprite, char id = %d)\n");
      ++v5->LoadingFrame;
      goto LABEL_28;
    }
    if ( (unsigned int)v14 >= 0x5C )
    {
      v24 = (unsigned int)(v14 - 1000);
      if ( (unsigned int)v24 > 9 )
        goto LABEL_27;
      v23 = Scaleform::GFx::GFx_GFX_TagLoaderTable[v24];
    }
    else
    {
      v23 = Scaleform::GFx::SWF_TagLoaderTable[v14];
    }
    if ( v23 )
    {
      v23(v4, &pTagInfo);
      goto LABEL_28;
    }
LABEL_27:
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v6->vfptr,
      "*** no tag loader for type %d\n");
LABEL_28:
    v25 = v6->TagStack[--v6->TagStackEntryCount];
    v6->UnusedBits = 0;
    v26 = v6->FilePos;
    v27 = v6->DataSize;
    v28 = v6->FilePos - v27;
    if ( v25 < v28 || v25 >= v26 )
    {
      if ( (v6->ResyncFile || v6->Pos + v28 != v25)
        && ((signed int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v6->pInput.pObject->vfptr[14].__vecDelDtor)(
             v6->pInput.pObject,
             (unsigned int)v25,
             0i64) >= 0 )
      {
        v6->ResyncFile = 0;
        *(_QWORD *)&v6->Pos = 0i64;
        v6->FilePos = v25;
      }
    }
    else
    {
      v6->Pos = v25 + v27 - v26;
    }
    v6->UnusedBits = 0;
  }
  v29 = v4->LoadState;
  if ( v4->FrameTags[v29].Data.Size || !(_DWORD)v29 && v4->InitActionTags.Data.Size )
  {
    if ( v5->LoadingFrame == LODWORD(v5->Playlist.Data.Size) )
    {
      Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,264>,Scaleform::ArrayDefaultPolicy>::Resize(
        v12,
        v5->Playlist.Data.Size + 1);
      LODWORD(v31[0]) = v5->LoadingFrame + 1;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v6->vfptr,
        "An extra frame is found for sprite id = %d, framecnt = %d, actual frames = %d",
        *v3,
        (unsigned int)v5->FrameCount,
        v31[0]);
    }
    Scaleform::GFx::LoadProcess::CommitFrameTags(v4);
  }
  v4->LoadState = 0;
  v4->pTimelineDef = 0i64;
  v30 = *v3;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v6->vfptr,
    "  -- sprite END, char id = %d --\n");
}

// File Line: 196
// RVA: 0x8D8FC0
Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::SpriteDef::GetFrameLabels(Scaleform::GFx::SpriteDef *this, unsigned int frameNumber, Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *destArr)
{
  Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *v3; // r15
  unsigned int v4; // er12
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v5; // r10
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v6; // r9
  Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *v7; // r14
  unsigned __int64 v8; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v9; // rcx
  int v10; // esi
  __int64 v11; // rbx
  __int64 v12; // rdi
  __int64 v13; // rcx
  Scaleform::String *v14; // rbp
  Scaleform::String *v15; // rcx
  unsigned __int64 v16; // rcx
  _QWORD *v17; // rax
  __m128i v19; // [rsp+30h] [rbp-38h]

  v3 = destArr;
  v4 = frameNumber;
  v5 = &this->NamedFrames;
  v6 = this->NamedFrames.mHash.pTable;
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
    v19.m128i_i64[0] = (__int64)v5;
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
  if ( v10 )
    v7 = v3;
  return v7;
}

// File Line: 233
// RVA: 0x8B0270
Scaleform::GFx::TimelineSnapshot::SnapshotElement *__fastcall Scaleform::GFx::TimelineSnapshot::Add(Scaleform::GFx::TimelineSnapshot *this, int depth)
{
  int v2; // ebp
  Scaleform::GFx::TimelineSnapshot *v3; // rsi
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *result; // rax
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v5; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r10
  signed __int64 v8; // rcx
  unsigned __int64 v9; // r8
  unsigned __int64 v10; // r8

  v2 = depth;
  v3 = this;
  result = Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2>>::allocate((Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> > *)&this->SnapshotHeap.FirstPage);
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
    result->pPrev = v3->SnapshotList.Root.pPrev;
    result->pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)&v3->SnapshotList;
    v3->SnapshotList.Root.pPrev->pNext = result;
    v3->SnapshotList.Root.pPrev = result;
    result->Depth = v2;
    v7 = v3->SnapshotSortedArray.Data.Size;
    v8 = v7;
    while ( v8 > 0 )
    {
      v9 = (v8 >> 1) + v6;
      if ( v2 >= v3->SnapshotSortedArray.Data.Data[v9]->Depth )
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
      (Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy> *)&v3->SnapshotSortedArray,
      v7 + 1);
    v10 = v3->SnapshotSortedArray.Data.Size;
    if ( v6 < v10 - 1 )
      memmove(&v3->SnapshotSortedArray.Data.Data[v6 + 1], &v3->SnapshotSortedArray.Data.Data[v6], 8 * (v10 - v6) - 8);
    v3->SnapshotSortedArray.Data.Data[v6] = v5;
    result = v5;
  }
  return result;
}

// File Line: 263
// RVA: 0x8EB240
void __fastcall Scaleform::GFx::TimelineSnapshot::MakeSnapshot(Scaleform::GFx::TimelineSnapshot *this, Scaleform::GFx::TimelineDef *pdef, unsigned int startFrame, unsigned int endFrame)
{
  unsigned int v4; // ebp
  unsigned int v5; // edi
  Scaleform::GFx::TimelineDef *v6; // r14
  Scaleform::GFx::TimelineSnapshot *v7; // rsi
  __int64 v8; // rbx
  __int64 v9; // [rsp+20h] [rbp-18h]
  unsigned int v10; // [rsp+28h] [rbp-10h]

  if ( startFrame <= endFrame )
  {
    v4 = endFrame;
    v5 = startFrame;
    v6 = pdef;
    v7 = this;
    do
    {
      ((void (__fastcall *)(Scaleform::GFx::TimelineDef *, __int64 *, _QWORD))v6->vfptr[2].GetResourceReport)(
        v6,
        &v9,
        v5);
      v8 = 0i64;
      if ( v10 )
      {
        do
        {
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::TimelineSnapshot *, _QWORD))(**(_QWORD **)(v9 + 8 * v8) + 48i64))(
            *(_QWORD *)(v9 + 8 * v8),
            v7,
            v5);
          v8 = (unsigned int)(v8 + 1);
        }
        while ( (unsigned int)v8 < v10 );
      }
      ++v5;
    }
    while ( v5 <= v4 );
  }
}

// File Line: 282
// RVA: 0x8CADA0
void __fastcall Scaleform::GFx::TimelineSnapshot::ExecuteSnapshot(Scaleform::GFx::TimelineSnapshot *this, Scaleform::GFx::DisplayObjContainer *pdispObj)
{
  Scaleform::GFx::DisplayObjContainer *v2; // rsi
  int v3; // ebx
  Scaleform::List<Scaleform::GFx::TimelineSnapshot::SnapshotElement,Scaleform::GFx::TimelineSnapshot::SnapshotElement> *v4; // r14
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *i; // rdi
  Scaleform::GFx::ASStringManager *v6; // rax
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::ASStringManager *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int v17; // ST28_4
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString v19; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::ASString v20; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::ASString v21; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp-90h]
  Scaleform::Render::Cxform v23; // [rsp+80h] [rbp-80h]
  __int128 v24; // [rsp+A0h] [rbp-60h]
  __m128 v25; // [rsp+B0h] [rbp-50h]
  Scaleform::Render::RenderBuffer *v26; // [rsp+C0h] [rbp-40h]
  __int64 v27; // [rsp+C8h] [rbp-38h]
  int v28; // [rsp+D0h] [rbp-30h]
  __int64 v29; // [rsp+D8h] [rbp-28h]
  int v30; // [rsp+E0h] [rbp-20h]
  __int16 v31; // [rsp+E4h] [rbp-1Ch]
  __int64 v32; // [rsp+F0h] [rbp-10h]
  char *v33; // [rsp+F8h] [rbp-8h]
  __int64 v34; // [rsp+110h] [rbp+10h]
  Scaleform::Render::Cxform v35; // [rsp+120h] [rbp+20h]
  __int128 v36; // [rsp+140h] [rbp+40h]
  Scaleform::GFx::ASString v37[2]; // [rsp+150h] [rbp+50h]
  Scaleform::GFx::ASString v38; // [rsp+160h] [rbp+60h]
  Scaleform::GFx::ASString v39; // [rsp+168h] [rbp+68h]
  Scaleform::GFx::ASString v40; // [rsp+170h] [rbp+70h]
  __int64 v41; // [rsp+178h] [rbp+78h]
  int v42; // [rsp+180h] [rbp+80h]
  __int16 v43; // [rsp+184h] [rbp+84h]
  char *pstr; // [rsp+198h] [rbp+98h]
  char v45; // [rsp+1B0h] [rbp+B0h]
  Scaleform::Render::Cxform v46; // [rsp+1C0h] [rbp+C0h]
  __int128 v47; // [rsp+1E0h] [rbp+E0h]
  __m128 v48; // [rsp+1F0h] [rbp+F0h]
  __int128 v49; // [rsp+200h] [rbp+100h]
  int v50; // [rsp+210h] [rbp+110h]
  __int64 v51; // [rsp+218h] [rbp+118h]
  int v52; // [rsp+220h] [rbp+120h]
  __int16 v53; // [rsp+224h] [rbp+124h]
  Scaleform::GFx::ResourceId id; // [rsp+290h] [rbp+190h]
  Scaleform::GFx::ASStringNode *v55; // [rsp+2A0h] [rbp+1A0h]
  Scaleform::GFx::ASStringNode *v56; // [rsp+2A8h] [rbp+1A8h]

  v34 = -2i64;
  v2 = pdispObj;
  v3 = 0;
  v4 = &this->SnapshotList;
  if ( (Scaleform::List<Scaleform::GFx::TimelineSnapshot::SnapshotElement,Scaleform::GFx::TimelineSnapshot::SnapshotElement> *)this->SnapshotList.Root.pNext != &this->SnapshotList )
  {
    for ( i = this->SnapshotList.Root.pNext; ; i = i->pNext )
    {
      if ( i->PlaceType )
      {
        if ( i->PlaceType == 1 )
        {
          *(_QWORD *)&id.Id = &v46;
          Scaleform::Render::Cxform::Cxform(&v46);
          v47 = _xmm;
          v48 = _xmm;
          v49 = 0ui64;
          v50 = 0x40000;
          v52 = 0;
          v53 = 256;
          v51 = 0i64;
          Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(
            &i->Tags,
            (Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *)&v46);
          Scaleform::GFx::DisplayList::MoveDisplayObject(
            &v2->mDisplayList,
            (Scaleform::GFx::DisplayObjectBase *)&v2->vfptr,
            (Scaleform::GFx::CharPosInfo *)&v46);
          *(_QWORD *)&id.Id = &v46;
          v12 = (Scaleform::Render::RenderBuffer *)v49;
        }
        else
        {
          if ( i->PlaceType != 2 )
          {
            if ( i->PlaceType == 3 )
            {
              id.Id = 0x40000;
              Scaleform::GFx::DisplayList::RemoveDisplayObject(
                &v2->mDisplayList,
                (Scaleform::GFx::DisplayObjectBase *)&v2->vfptr,
                i->Depth,
                (Scaleform::GFx::ResourceId)&id);
            }
            goto LABEL_35;
          }
          *(_QWORD *)&id.Id = &v35;
          Scaleform::Render::Cxform::Cxform(&v35);
          v36 = _xmm;
          *(__m128 *)&v37[0].pNode = _xmm;
          v38.pNode = 0i64;
          LODWORD(v40.pNode) = 0x40000;
          v42 = 0;
          v39.pNode = 0i64;
          v43 = 256;
          v41 = 0i64;
          Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(
            &i->Tags,
            (Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *)&v35);
          v6 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v2->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
          if ( pstr )
          {
            v7 = Scaleform::GFx::ASStringManager::CreateString(v6, &v21, pstr);
            v3 |= 8u;
          }
          else
          {
            v7 = Scaleform::GFx::ASStringManager::CreateEmptyString(v6, &result);
            v3 |= 4u;
          }
          v55 = v7->pNode;
          ++v55->RefCount;
          if ( v3 & 8 )
          {
            v3 &= 0xFFFFFFF7;
            v8 = v21.pNode;
            v9 = v21.pNode->RefCount == 1;
            --v8->RefCount;
            if ( v9 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v8);
          }
          if ( v3 & 4 )
          {
            v3 &= 0xFFFFFFFB;
            v10 = result.pNode;
            v9 = result.pNode->RefCount == 1;
            --v10->RefCount;
            if ( v9 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v10);
          }
          ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::Render::Cxform *, Scaleform::GFx::ASStringNode **, char *))v2->vfptr[123].__vecDelDtor)(
            v2,
            &v35,
            &v55,
            &v45);
          v11 = v55;
          v9 = v55->RefCount == 1;
          --v11->RefCount;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v11);
          *(_QWORD *)&id.Id = &v35;
          v12 = (Scaleform::Render::RenderBuffer *)v38.pNode;
        }
      }
      else
      {
        *(_QWORD *)&id.Id = &v23;
        Scaleform::Render::Cxform::Cxform(&v23);
        v24 = _xmm;
        v25 = _xmm;
        v26 = 0i64;
        v28 = 0x40000;
        v30 = 0;
        v27 = 0i64;
        v31 = 256;
        v29 = 0i64;
        Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(
          &i->Tags,
          (Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *)&v23);
        v13 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v2->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
        if ( v33 )
        {
          v14 = Scaleform::GFx::ASStringManager::CreateString(v13, &v20, v33);
          v3 |= 2u;
        }
        else
        {
          v14 = Scaleform::GFx::ASStringManager::CreateEmptyString(v13, &v19);
          v3 |= 1u;
        }
        v56 = v14->pNode;
        ++v56->RefCount;
        if ( v3 & 2 )
        {
          v3 &= 0xFFFFFFFD;
          v15 = v20.pNode;
          v9 = v20.pNode->RefCount == 1;
          --v15->RefCount;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
        if ( v3 & 1 )
        {
          v3 &= 0xFFFFFFFE;
          v16 = v19.pNode;
          v9 = v19.pNode->RefCount == 1;
          --v16->RefCount;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        }
        i->Flags;
        v17 = i->CreateFrame;
        ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::Render::Cxform *, Scaleform::GFx::ASStringNode **, __int64))v2->vfptr[118].__vecDelDtor)(
          v2,
          &v23,
          &v56,
          v32);
        v18 = v56;
        v9 = v56->RefCount == 1;
        --v18->RefCount;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
        *(_QWORD *)&id.Id = &v23;
        v12 = v26;
      }
      if ( v12 )
        Scaleform::RefCountImpl::Release(v12);
LABEL_35:
      if ( i == v4->Root.pPrev )
        return;
    }
  }
}

// File Line: 345
// RVA: 0x915BA0
void __fastcall Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(Scaleform::GFx::TimelineSnapshot::SourceTags *this, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *v2; // rdi
  Scaleform::GFx::TimelineSnapshot::SourceTags *v3; // rbx
  Scaleform::GFx::GFxPlaceObjectBase *v4; // rcx
  Scaleform::GFx::GFxPlaceObjectBase *v5; // rcx
  signed __int64 v6; // rsi
  signed __int64 v7; // rax
  Scaleform::GFx::GFxPlaceObjectBase *v8; // rcx
  signed __int64 v9; // rax
  Scaleform::GFx::GFxPlaceObjectBase *v10; // rcx
  signed __int64 v11; // rax
  Scaleform::GFx::GFxPlaceObjectBase *v12; // rcx
  signed __int64 v13; // rax
  signed __int64 v14; // rax
  Scaleform::GFx::GFxPlaceObjectBase *v15; // rcx
  signed __int64 v16; // rax
  Scaleform::GFx::GFxPlaceObjectBase *v17; // rcx
  signed __int64 v18; // rax
  Scaleform::GFx::GFxPlaceObjectBase *v19; // rcx
  signed __int64 v20; // rax
  Scaleform::GFx::GFxPlaceObjectBase *v21; // rcx
  Scaleform::GFx::Resource *v22; // rcx
  Scaleform::Render::RenderBuffer *v23; // rcx
  __int128 ptr; // [rsp+40h] [rbp-518h]
  __int128 v25; // [rsp+50h] [rbp-508h]
  int v26; // [rsp+60h] [rbp-4F8h]
  int v27; // [rsp+64h] [rbp-4F4h]
  int v28; // [rsp+68h] [rbp-4F0h]
  int v29; // [rsp+6Ch] [rbp-4ECh]
  int v30; // [rsp+70h] [rbp-4E8h]
  int v31; // [rsp+74h] [rbp-4E4h]
  int v32; // [rsp+78h] [rbp-4E0h]
  int v33; // [rsp+7Ch] [rbp-4DCh]
  Scaleform::GFx::Resource *v34; // [rsp+80h] [rbp-4D8h]
  int v35; // [rsp+88h] [rbp-4D0h]
  int v36; // [rsp+8Ch] [rbp-4CCh]
  int v37[2]; // [rsp+90h] [rbp-4C8h]
  __int64 v38; // [rsp+98h] [rbp-4C0h]
  __int16 v39[2]; // [rsp+A0h] [rbp-4B8h]
  char v40[44]; // [rsp+A4h] [rbp-4B4h]
  char v41; // [rsp+D0h] [rbp-488h]
  char v42; // [rsp+160h] [rbp-3F8h]
  char v43; // [rsp+1F0h] [rbp-368h]
  char v44; // [rsp+280h] [rbp-2D8h]
  char v45; // [rsp+310h] [rbp-248h]
  char v46; // [rsp+3A0h] [rbp-1B8h]
  char v47; // [rsp+430h] [rbp-128h]
  char v48; // [rsp+4C0h] [rbp-98h]

  v2 = data;
  v3 = this;
  ((void (*)(void))this->pMainTag->vfptr[1].__vecDelDtor)();
  `eh vector constructor iterator'(
    &ptr,
    0x90ui64,
    9,
    (void (__fastcall *)(void *))Scaleform::GFx::GFxPlaceObjectBase::UnpackedData::UnpackedData);
  v4 = v3->pDepthTag;
  if ( v4 != v3->pMainTag )
  {
    v4->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v4->vfptr, (unsigned int)&ptr);
    v2->Pos.Depth = v36;
    v2->Pos.Flags.Flags |= 1u;
  }
  v5 = v3->pCharIdTag;
  v6 = 0i64;
  if ( v5 != v3->pMainTag )
  {
    if ( v3->pDepthTag == v5 )
    {
      v7 = 0i64;
    }
    else
    {
      v5->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v5->vfptr, (unsigned int)&v41);
      v7 = 1i64;
    }
    v2->Pos.CharacterId.Id = v37[36 * v7];
    v2->Pos.Flags.Flags |= 2u;
  }
  v8 = v3->pMatrixTag;
  if ( v8 != v3->pMainTag )
  {
    if ( v3->pDepthTag == v8 )
    {
      v9 = 0i64;
    }
    else if ( v3->pCharIdTag == v8 )
    {
      v9 = 1i64;
    }
    else
    {
      v8->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v8->vfptr, (unsigned int)&v42);
      v9 = 2i64;
    }
    LODWORD(v2->Pos.Matrix_1.M[0][0]) = *(&v26 + 36 * v9);
    LODWORD(v2->Pos.Matrix_1.M[0][1]) = *(&v27 + 36 * v9);
    LODWORD(v2->Pos.Matrix_1.M[0][2]) = *(&v28 + 36 * v9);
    LODWORD(v2->Pos.Matrix_1.M[0][3]) = *(&v29 + 36 * v9);
    LODWORD(v2->Pos.Matrix_1.M[1][0]) = *(&v30 + 36 * v9);
    LODWORD(v2->Pos.Matrix_1.M[1][1]) = *(&v31 + 36 * v9);
    LODWORD(v2->Pos.Matrix_1.M[1][2]) = *(&v32 + 36 * v9);
    LODWORD(v2->Pos.Matrix_1.M[1][3]) = *(&v33 + 36 * v9);
    v2->Pos.Flags.Flags |= 4u;
  }
  v10 = v3->pClassNameTag;
  if ( v10 != v3->pMainTag )
  {
    if ( v3->pDepthTag == v10 )
    {
      v11 = 0i64;
    }
    else if ( v3->pCharIdTag == v10 )
    {
      v11 = 1i64;
    }
    else if ( v3->pMatrixTag == v10 )
    {
      v11 = 2i64;
    }
    else
    {
      v10->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v10->vfptr, (unsigned int)&v43);
      v11 = 3i64;
    }
    v2->Pos.ClassName = (const char *)*(&v38 + 18 * v11);
    v2->Pos.Flags.Flags |= 0x100u;
  }
  v12 = v3->pCxFormTag;
  if ( v12 != v3->pMainTag )
  {
    if ( v3->pDepthTag == v12 )
    {
      v13 = 0i64;
    }
    else if ( v3->pCharIdTag == v12 )
    {
      v13 = 1i64;
    }
    else if ( v3->pMatrixTag == v12 )
    {
      v13 = 2i64;
    }
    else if ( v3->pClassNameTag == v12 )
    {
      v13 = 3i64;
    }
    else
    {
      v12->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v12->vfptr, (unsigned int)&v44);
      v13 = 4i64;
    }
    v14 = 18 * v13;
    *(_OWORD *)&v2->Pos.ColorTransform.M[0][0] = *(__int128 *)((char *)&ptr + 8 * v14);
    *(_OWORD *)&v2->Pos.ColorTransform.M[1][0] = *(__int128 *)((char *)&v25 + 8 * v14);
    v2->Pos.Flags.Flags |= 8u;
  }
  v15 = v3->pBlendModeTag;
  if ( v15 != v3->pMainTag )
  {
    if ( v3->pDepthTag == v15 )
    {
      v16 = 0i64;
    }
    else if ( v3->pCharIdTag == v15 )
    {
      v16 = 1i64;
    }
    else if ( v3->pMatrixTag == v15 )
    {
      v16 = 2i64;
    }
    else if ( v3->pClassNameTag == v15 )
    {
      v16 = 3i64;
    }
    else if ( v3->pCxFormTag == v15 )
    {
      v16 = 4i64;
    }
    else
    {
      v15->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v15->vfptr, (unsigned int)&v45);
      v16 = 5i64;
    }
    v2->Pos.BlendMode = v40[144 * v16];
    v2->Pos.Flags.Flags |= 0x80u;
  }
  v17 = v3->pClipDepthTag;
  if ( v17 != v3->pMainTag )
  {
    if ( v3->pDepthTag == v17 )
    {
      v18 = 0i64;
    }
    else if ( v3->pCharIdTag == v17 )
    {
      v18 = 1i64;
    }
    else if ( v3->pMatrixTag == v17 )
    {
      v18 = 2i64;
    }
    else if ( v3->pClassNameTag == v17 )
    {
      v18 = 3i64;
    }
    else if ( v3->pCxFormTag == v17 )
    {
      v18 = 4i64;
    }
    else if ( v3->pBlendModeTag == v17 )
    {
      v18 = 5i64;
    }
    else
    {
      v17->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v17->vfptr, (unsigned int)&v46);
      v18 = 6i64;
    }
    v2->Pos.ClipDepth = v39[72 * v18];
    v2->Pos.Flags.Flags |= 0x40u;
  }
  v19 = v3->pRatioTag;
  if ( v19 != v3->pMainTag )
  {
    if ( v3->pDepthTag == v19 )
    {
      v20 = 0i64;
    }
    else if ( v3->pCharIdTag == v19 )
    {
      v20 = 1i64;
    }
    else if ( v3->pMatrixTag == v19 )
    {
      v20 = 2i64;
    }
    else if ( v3->pClassNameTag == v19 )
    {
      v20 = 3i64;
    }
    else if ( v3->pCxFormTag == v19 )
    {
      v20 = 4i64;
    }
    else if ( v3->pBlendModeTag == v19 )
    {
      v20 = 5i64;
    }
    else if ( v3->pClipDepthTag == v19 )
    {
      v20 = 6i64;
    }
    else
    {
      v19->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v19->vfptr, (unsigned int)&v47);
      v20 = 7i64;
    }
    LODWORD(v2->Pos.Ratio) = *(&v35 + 36 * v20);
    v2->Pos.Flags.Flags |= 0x10u;
  }
  v21 = v3->pFiltersTag;
  if ( v21 != v3->pMainTag )
  {
    if ( v3->pDepthTag != v21 )
    {
      if ( v3->pCharIdTag == v21 )
      {
        v6 = 1i64;
      }
      else if ( v3->pMatrixTag == v21 )
      {
        v6 = 2i64;
      }
      else if ( v3->pClassNameTag == v21 )
      {
        v6 = 3i64;
      }
      else if ( v3->pCxFormTag == v21 )
      {
        v6 = 4i64;
      }
      else if ( v3->pBlendModeTag == v21 )
      {
        v6 = 5i64;
      }
      else if ( v3->pClipDepthTag == v21 )
      {
        v6 = 6i64;
      }
      else if ( v3->pRatioTag == v21 )
      {
        v6 = 7i64;
      }
      else
      {
        v21->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v21->vfptr, (unsigned int)&v48);
        v6 = 8i64;
      }
    }
    v22 = (&v34)[18 * v6];
    if ( v22 )
      Scaleform::Render::RenderBuffer::AddRef(v22);
    v23 = (Scaleform::Render::RenderBuffer *)v2->Pos.pFilters.pObject;
    if ( v23 )
      Scaleform::RefCountImpl::Release(v23);
    v2->Pos.pFilters.pObject = (Scaleform::Render::FilterSet *)(&v34)[18 * v6];
    v2->Pos.Flags.Flags |= 0x20u;
  }
  `eh vector destructor iterator'(
    &ptr,
    0x90ui64,
    9,
    (void (__fastcall *)(void *))Scaleform::GFx::GFxPlaceObjectBase::UnpackedData::~UnpackedData);
}ountImpl::Release(v23

// File Line: 447
// RVA: 0x8B3440
void __fastcall Scaleform::GFx::GFxPlaceObjectUnpacked::AddToTimelineSnapshot(Scaleform::GFx::GFxPlaceObjectUnpacked *this, Scaleform::GFx::TimelineSnapshot *psnapshot, unsigned int frame)
{
  Scaleform::GFx::TimelineSnapshot *v3; // rdi
  unsigned int v4; // esi
  Scaleform::GFx::GFxPlaceObjectUnpacked *v5; // rbx
  signed __int64 v6; // rcx
  int v7; // er10
  signed __int64 v8; // r9
  Scaleform::GFx::TimelineSnapshot::SnapshotElement **v9; // r11
  signed __int64 v10; // r8
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v11; // rcx
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v12; // rax

  v3 = psnapshot;
  v4 = frame;
  v5 = this;
  this->vfptr->Trace((Scaleform::GFx::ExecuteTag *)this, "\n");
  v6 = v3->SnapshotSortedArray.Data.Size;
  v7 = v5->Pos.Depth;
  v8 = 0i64;
  if ( v6 <= 0 )
    goto LABEL_15;
  v9 = v3->SnapshotSortedArray.Data.Data;
  do
  {
    v10 = (v6 >> 1) + v8;
    if ( v7 >= v9[v10]->Depth )
    {
      v8 = v10 + 1;
      v6 += -1 - (v6 >> 1);
    }
    else
    {
      v6 >>= 1;
    }
  }
  while ( v6 > 0 );
  if ( v8 && (v11 = v9[v8 - 1], v11->Depth == v7) && v11 && !(v11->Flags & 2) )
  {
    v11->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pMainTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->CreateFrame = v4;
    v11->Flags |= 1u;
  }
  else
  {
LABEL_15:
    v12 = Scaleform::GFx::TimelineSnapshot::Add(v3, v7);
    v12->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pMainTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->CreateFrame = v4;
    v12->PlaceType = 0;
    v12->Flags |= 1u;
  }
}

// File Line: 482
// RVA: 0x8B3AC0
void __fastcall Scaleform::GFx::PlaceObjectTag::AddToTimelineSnapshot(Scaleform::GFx::PlaceObjectTag *this, Scaleform::GFx::TimelineSnapshot *psnapshot, unsigned int frame)
{
  Scaleform::GFx::TimelineSnapshot *v3; // rdi
  unsigned int v4; // esi
  Scaleform::GFx::PlaceObjectTag *v5; // rbx
  signed __int64 v6; // rdx
  signed __int64 v7; // r9
  int v8; // er10
  Scaleform::GFx::TimelineSnapshot::SnapshotElement **v9; // r11
  signed __int64 v10; // r8
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v11; // rcx
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v12; // rax

  v3 = psnapshot;
  v4 = frame;
  v5 = this;
  this->vfptr->Trace((Scaleform::GFx::ExecuteTag *)this, "\n");
  v6 = v3->SnapshotSortedArray.Data.Size;
  v7 = 0i64;
  v8 = *(unsigned __int16 *)&v5->pData[2];
  if ( v6 <= 0 )
    goto LABEL_15;
  v9 = v3->SnapshotSortedArray.Data.Data;
  do
  {
    v10 = (v6 >> 1) + v7;
    if ( v8 >= v9[v10]->Depth )
    {
      v7 = v10 + 1;
      v6 += -1 - (v6 >> 1);
    }
    else
    {
      v6 >>= 1;
    }
  }
  while ( v6 > 0 );
  if ( v7 && (v11 = v9[v7 - 1], v11->Depth == v8) && v11 && !(v11->Flags & 2) )
  {
    v11->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->Tags.pMainTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v11->CreateFrame = v4;
    v11->Flags |= 1u;
  }
  else
  {
LABEL_15:
    v12 = Scaleform::GFx::TimelineSnapshot::Add(v3, v8);
    v12->PlaceType = 0;
    v12->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->Tags.pMainTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v12->CreateFrame = v4;
    v12->Flags |= 1u;
  }
}

// File Line: 527
// RVA: 0x8C95D0
void __fastcall Scaleform::GFx::GFxPlaceObjectUnpacked::Execute(Scaleform::GFx::GFxPlaceObjectUnpacked *this, Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::DisplayObjContainer *v2; // rdi
  Scaleform::GFx::GFxPlaceObjectUnpacked *v3; // rbx
  Scaleform::GFx::ASStringManager *v4; // rax
  signed int v5; // ST30_4
  signed int v6; // ST28_4
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]

  v2 = m;
  v3 = this;
  v4 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))m->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
  Scaleform::GFx::ASStringManager::CreateEmptyString(v4, &result);
  v5 = 4;
  v6 = -1;
  ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASString *, _QWORD, _QWORD, signed int, signed int, _QWORD, _QWORD))v2->vfptr[118].__vecDelDtor)(
    v2,
    &v3->Pos,
    &result,
    0i64,
    0i64,
    v6,
    v5,
    0i64,
    0i64);
  v7 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 578
// RVA: 0x8D8160
Scaleform::GFx::CharPosInfoFlags *__fastcall Scaleform::GFx::PlaceObjectTag::GetFlags(Scaleform::GFx::PlaceObjectTag *this, Scaleform::GFx::CharPosInfoFlags *result)
{
  result->Flags = (this->HasCxForm != 0 ? 8 : 0) | 7;
  return result;
}

// File Line: 594
// RVA: 0x8CA200
void __fastcall Scaleform::GFx::PlaceObjectTag::Execute(Scaleform::GFx::PlaceObjectTag *this, Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::DisplayObjContainer *v2; // rdi
  Scaleform::GFx::PlaceObjectTag *v3; // rbx
  Scaleform::GFx::ASStringManager *v4; // rax
  Scaleform::GFx::ASString *v5; // rax
  signed int v6; // ST30_4
  signed int v7; // ST28_4
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::Render::Cxform v10; // [rsp+60h] [rbp-98h]
  __int128 v11; // [rsp+80h] [rbp-78h]
  __m128 v12; // [rsp+90h] [rbp-68h]
  Scaleform::Render::RenderBuffer *v13; // [rsp+A0h] [rbp-58h]
  int v14; // [rsp+A8h] [rbp-50h]
  int v15; // [rsp+ACh] [rbp-4Ch]
  int v16; // [rsp+B0h] [rbp-48h]
  __int64 v17; // [rsp+B8h] [rbp-40h]
  int v18; // [rsp+C0h] [rbp-38h]
  __int16 v19; // [rsp+C4h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+100h] [rbp+8h]

  v2 = m;
  v3 = this;
  result.pNode = (Scaleform::GFx::ASStringNode *)&v10;
  Scaleform::Render::Cxform::Cxform(&v10);
  v11 = _xmm;
  v12 = _xmm;
  v13 = 0i64;
  v16 = 0x40000;
  v18 = 0;
  v14 = 0;
  v15 = 0;
  v19 = 256;
  v17 = 0i64;
  v3->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v3->vfptr, (unsigned int)&v10);
  v4 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v2->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
  v5 = Scaleform::GFx::ASStringManager::CreateEmptyString(v4, &result);
  v6 = 4;
  v7 = -1;
  ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, _QWORD, signed int, signed int, _QWORD, _QWORD))v2->vfptr[118].__vecDelDtor)(
    v2,
    &v10,
    v5,
    0i64,
    0i64,
    v7,
    v6,
    0i64,
    0i64);
  v8 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  result.pNode = (Scaleform::GFx::ASStringNode *)&v10;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
}

// File Line: 606
// RVA: 0x915AF0
void __fastcall Scaleform::GFx::PlaceObjectTag::Unpack(Scaleform::GFx::PlaceObjectTag *this, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  Scaleform::GFx::PlaceObjectTag *v2; // rbx
  __int16 v3; // ax
  __int16 v4; // r8
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *v5; // rdi
  Scaleform::Render::Matrix2x4<float> *v6; // rdx
  Scaleform::GFx::StreamContext v7; // [rsp+20h] [rbp-28h]

  v2 = this;
  data->Name = 0i64;
  data->pEventHandlers = 0i64;
  data->PlaceType = 0;
  data->Pos.Flags.Flags |= 2u;
  v3 = (unsigned __int8)this->pData[0];
  v4 = (unsigned __int8)this->pData[1];
  v7.CurBitIndex = 0;
  v5 = data;
  v6 = &data->Pos.Matrix_1;
  v7.pData = this->pData;
  v7.DataSize = -1i64;
  v7.CurByteIndex = 4i64;
  LODWORD(v6[1].M[1][0]) = (unsigned __int16)(v3 | (v4 << 8));
  HIWORD(v6[2].M[0][0]) |= 1u;
  LODWORD(v6[1].M[0][3]) = *(unsigned __int16 *)&this->pData[2];
  HIWORD(v6[2].M[0][0]) |= 4u;
  Scaleform::GFx::StreamContext::ReadMatrix(&v7, v6);
  if ( v2->HasCxForm )
  {
    v5->Pos.Flags.Flags |= 8u;
    Scaleform::GFx::StreamContext::ReadCxformRgb(&v7, &v5->Pos.ColorTransform);
  }
}

// File Line: 639
// RVA: 0x8A7210
void __fastcall Scaleform::GFx::PlaceObject2Tag::~PlaceObject2Tag(Scaleform::GFx::PlaceObject2Tag *this)
{
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::PlaceObject2Tag::`vftable';
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::ExecuteTag::`vftable';
}

// File Line: 747
// RVA: 0x8D8110
Scaleform::GFx::CharPosInfoFlags *__fastcall Scaleform::GFx::PlaceObject2Tag::GetFlags(Scaleform::GFx::PlaceObject2Tag *this, Scaleform::GFx::CharPosInfoFlags *result)
{
  result->Flags = this->pData[0] & 0x5F;
  return result;
}

// File Line: 777
// RVA: 0x8CA440
void __fastcall Scaleform::GFx::PlaceObject2Tag::ExecuteBase(Scaleform::GFx::PlaceObject2Tag *this, Scaleform::GFx::DisplayObjContainer *m, char version)
{
  char v3; // bl
  Scaleform::GFx::DisplayObjContainer *v4; // rsi
  Scaleform::GFx::PlaceObject2Tag *v5; // rdi
  Scaleform::GFx::ASStringManager *v6; // rax
  Scaleform::GFx::ASString *v7; // rax
  char v8; // bl
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringManager *v12; // rax
  Scaleform::GFx::ASString *v13; // rax
  char v14; // bl
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString v18; // [rsp+58h] [rbp-90h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp-88h]
  Scaleform::Render::Cxform v20; // [rsp+68h] [rbp-80h]
  __int128 v21; // [rsp+88h] [rbp-60h]
  __m128 v22; // [rsp+98h] [rbp-50h]
  Scaleform::Render::RenderBuffer *v23; // [rsp+A8h] [rbp-40h]
  int v24; // [rsp+B0h] [rbp-38h]
  int v25; // [rsp+B4h] [rbp-34h]
  int v26; // [rsp+B8h] [rbp-30h]
  __int64 v27; // [rsp+C0h] [rbp-28h]
  int v28; // [rsp+C8h] [rbp-20h]
  __int16 v29; // [rsp+CCh] [rbp-1Ch]
  __int64 v30; // [rsp+D8h] [rbp-10h]
  char *pstr; // [rsp+E0h] [rbp-8h]
  int v32; // [rsp+E8h] [rbp+0h]
  __int64 v33; // [rsp+F8h] [rbp+10h]
  char v34; // [rsp+100h] [rbp+18h]
  Scaleform::GFx::ASString v35; // [rsp+140h] [rbp+58h]

  v33 = -2i64;
  v3 = version;
  v4 = m;
  v5 = this;
  v35.pNode = (Scaleform::GFx::ASStringNode *)&v20.M[1][2];
  Scaleform::Render::Cxform::Cxform(&v20);
  v21 = _xmm;
  v22 = _xmm;
  v23 = 0i64;
  v26 = 0x40000;
  v28 = 0;
  v24 = 0;
  v25 = 0;
  v29 = 256;
  v27 = 0i64;
  Scaleform::GFx::PlaceObject2Tag::UnpackBase(v5, (Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *)&v20, v3);
  if ( v32 )
  {
    if ( v32 == 1 )
    {
      Scaleform::GFx::DisplayList::MoveDisplayObject(
        &v4->mDisplayList,
        (Scaleform::GFx::DisplayObjectBase *)&v4->vfptr,
        (Scaleform::GFx::CharPosInfo *)&v20);
      goto LABEL_27;
    }
    if ( v32 != 2 )
      goto LABEL_27;
    v6 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v4->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
    if ( pstr )
    {
      v7 = Scaleform::GFx::ASStringManager::CreateString(v6, (Scaleform::GFx::ASString *)&v20.M[0][2], pstr);
      v8 = 8;
    }
    else
    {
      v7 = Scaleform::GFx::ASStringManager::CreateEmptyString(v6, (Scaleform::GFx::ASString *)&v20);
      v8 = 4;
    }
    v35.pNode = v7->pNode;
    ++v35.pNode->RefCount;
    if ( v8 & 8 )
    {
      v8 &= 0xF7u;
      v9 = *(Scaleform::GFx::ASStringNode **)&v20.M[0][2];
      v10 = *(_DWORD *)(*(_QWORD *)&v20.M[0][2] + 24i64) == 1;
      --v9->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    }
    if ( v8 & 4 )
    {
      v11 = *(Scaleform::GFx::ASStringNode **)&v20.M[0][0];
      v10 = *(_DWORD *)(*(_QWORD *)&v20.M[0][0] + 24i64) == 1;
      --v11->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, char *))v4->vfptr[123].__vecDelDtor)(
      v4,
      &v20,
      &v35,
      &v34);
  }
  else
  {
    v12 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v4->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
    if ( pstr )
    {
      v13 = Scaleform::GFx::ASStringManager::CreateString(v12, &v18, pstr);
      v14 = 2;
    }
    else
    {
      v13 = Scaleform::GFx::ASStringManager::CreateEmptyString(v12, &result);
      v14 = 1;
    }
    v35.pNode = v13->pNode;
    ++v35.pNode->RefCount;
    if ( v14 & 2 )
    {
      v14 &= 0xFDu;
      v15 = v18.pNode;
      v10 = v18.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    if ( v14 & 1 )
    {
      v16 = result.pNode;
      v10 = result.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, __int64, _QWORD, signed int, signed int, _QWORD, _QWORD))v4->vfptr[118].__vecDelDtor)(
      v4,
      &v20,
      &v35,
      v30,
      0i64,
      -1,
      4,
      0i64,
      0i64);
  }
  v17 = v35.pNode;
  v10 = v35.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
LABEL_27:
  v35.pNode = (Scaleform::GFx::ASStringNode *)&v20;
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
}

// File Line: 831
// RVA: 0x8E2E30
__int64 __fastcall Scaleform::GFx::PlaceObject2Tag::HasEventHandlers(Scaleform::GFx::Stream *pin)
{
  unsigned int v1; // eax
  Scaleform::GFx::Stream *v2; // rbx
  __int64 v3; // rcx
  int v4; // er8
  unsigned __int8 v5; // si
  unsigned int v6; // edx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int v9; // eax
  int v10; // edi

  v1 = pin->DataSize;
  v2 = pin;
  pin->UnusedBits = 0;
  if ( (signed int)(v1 - pin->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(pin, 1);
  v3 = v2->Pos;
  v4 = v2->FilePos;
  v5 = v2->pBuffer[v3];
  v6 = v3 + 1;
  v7 = v2->DataSize;
  v8 = v2->FilePos;
  v2->Pos = v6;
  v2->UnusedBits = 0;
  v9 = v8 - v7;
  v10 = v9 + v6 - 1;
  if ( v10 < v9 || v10 >= v4 )
  {
    if ( (v2->ResyncFile || v9 + v6 != v10)
      && ((signed int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v2->pInput.pObject->vfptr[14].__vecDelDtor)(
           v2->pInput.pObject,
           (unsigned int)v10,
           0i64) >= 0 )
    {
      v2->ResyncFile = 0;
      v2->FilePos = v10;
      *(_QWORD *)&v2->Pos = 0i64;
    }
  }
  else
  {
    v2->Pos = v10 + v7 - v4;
  }
  return (unsigned int)v5 >> 7;
}

// File Line: 850
// RVA: 0x916260
Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::PlaceObject3Tag::UnpackEventHandlers(Scaleform::GFx::PlaceObject3Tag *this)
{
  Scaleform::GFx::PlaceObject3Tag *v1; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *result; // rax
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::Render::Cxform v4; // [rsp+30h] [rbp-98h]
  __int128 v5; // [rsp+50h] [rbp-78h]
  __m128 v6; // [rsp+60h] [rbp-68h]
  Scaleform::Render::RenderBuffer *v7; // [rsp+70h] [rbp-58h]
  int v8; // [rsp+78h] [rbp-50h]
  int v9; // [rsp+7Ch] [rbp-4Ch]
  int v10; // [rsp+80h] [rbp-48h]
  __int64 v11; // [rsp+88h] [rbp-40h]
  int v12; // [rsp+90h] [rbp-38h]
  __int16 v13; // [rsp+94h] [rbp-34h]
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v14; // [rsp+A0h] [rbp-28h]

  v1 = this;
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
    v1->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v1->vfptr, (unsigned int)&v4);
    v3 = v14;
    if ( v7 )
      Scaleform::RefCountImpl::Release(v7);
    result = v3;
  }
  return result;
}

// File Line: 868
// RVA: 0x916010
void __fastcall Scaleform::GFx::PlaceObject2Tag::UnpackBase(Scaleform::GFx::PlaceObject2Tag *this, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data, char version)
{
  char *v3; // r15
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *v4; // rbx
  char v5; // di
  Scaleform::GFx::PlaceObject2Tag *v6; // rsi
  unsigned __int64 v7; // rdx
  char v8; // r12
  const char *v9; // r9
  unsigned int v10; // er8
  __int16 v11; // ax
  __int16 v12; // cx
  signed __int64 v13; // rdx
  unsigned __int16 v14; // cx
  unsigned __int16 v15; // cx
  char v16; // al
  unsigned __int16 v17; // cx
  unsigned __int8 v18; // al
  char v19; // di
  signed int v20; // eax
  Scaleform::GFx::StreamContext v21; // [rsp+30h] [rbp-20h]

  v3 = this->pData;
  v4 = data;
  v21.CurByteIndex = 0i64;
  v21.CurBitIndex = 0;
  v21.DataSize = -1i64;
  v21.pData = this->pData;
  v5 = this->pData[0];
  v6 = this;
  v21.CurBitIndex = 0;
  v7 = 1i64;
  v8 = version;
  if ( v5 < 0 )
    v7 = 9i64;
  v9 = this->pData;
  v10 = 0;
  v21.CurByteIndex = v7;
  v11 = (unsigned __int8)v3[v7];
  v12 = (unsigned __int8)v3[v7 + 1];
  v13 = v7 + 2;
  v21.CurByteIndex = v13;
  v4->Pos.Depth = (unsigned __int16)(v11 | (v12 << 8));
  if ( v5 & 2 )
  {
    v4->Pos.Flags.Flags |= 2u;
    v21.CurBitIndex = 0;
    v14 = *(_WORD *)&v3[v13];
    v13 += 2i64;
    v21.CurByteIndex = v13;
    v4->Pos.CharacterId.Id = v14;
  }
  if ( v5 & 4 )
  {
    v4->Pos.Flags.Flags |= 4u;
    Scaleform::GFx::StreamContext::ReadMatrix(&v21, &v4->Pos.Matrix_1);
    v10 = v21.CurBitIndex;
    v13 = v21.CurByteIndex;
    v9 = v21.pData;
  }
  if ( v5 & 8 )
  {
    v4->Pos.Flags.Flags |= 8u;
    Scaleform::GFx::StreamContext::ReadCxformRgba(&v21, &v4->Pos.ColorTransform);
    v10 = v21.CurBitIndex;
    v13 = v21.CurByteIndex;
    v9 = v21.pData;
  }
  if ( v5 & 0x10 )
  {
    v4->Pos.Flags.Flags |= 0x10u;
    if ( v10 )
      v21.CurByteIndex = ++v13;
    v21.CurBitIndex = 0;
    v10 = 0;
    v15 = *(_WORD *)&v9[v13];
    v13 += 2i64;
    v21.CurByteIndex = v13;
    v4->Pos.Ratio = (float)v15 * 0.000015259022;
  }
  if ( v5 & 0x20 )
  {
    if ( v10 )
      v21.CurByteIndex = ++v13;
    v10 = 0;
    v21.CurBitIndex = 0;
    v4->Name = &v6->pData[v13];
    do
    {
      v16 = v9[v13++];
      v21.CurByteIndex = v13;
    }
    while ( v16 );
  }
  else
  {
    v4->Name = 0i64;
  }
  if ( v5 & 0x40 )
  {
    v4->Pos.Flags.Flags |= 0x40u;
    if ( v10 )
      v21.CurByteIndex = ++v13;
    v21.CurBitIndex = 0;
    v17 = *(_WORD *)&v9[v13];
    v21.CurByteIndex = v13 + 2;
    v4->Pos.ClipDepth = v17;
  }
  if ( v5 & 0x80 )
    ((void (__fastcall *)(Scaleform::GFx::PlaceObject2Tag *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *, Scaleform::GFx::StreamContext *, char *, char))v6->vfptr[1].IsRemoveTag)(
      v6,
      v4,
      &v21,
      v3,
      v8);
  else
    v4->pEventHandlers = 0i64;
  v18 = v5;
  v19 = v5 & 1;
  v4->PlaceType = 0;
  if ( (v18 >> 1) & 1 )
  {
    if ( v19 )
      v4->PlaceType = 2;
  }
  else
  {
    v20 = 0;
    if ( v19 )
      v20 = 1;
    v4->PlaceType = v20;
  }
}

// File Line: 936
// RVA: 0x8A7320
void __fastcall Scaleform::GFx::PlaceObject3Tag::~PlaceObject3Tag(Scaleform::GFx::PlaceObject3Tag *this)
{
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::PlaceObject3Tag::`vftable';
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::ExecuteTag::`vftable';
}

// File Line: 1075
// RVA: 0x8D8120
Scaleform::GFx::CharPosInfoFlags *__fastcall Scaleform::GFx::PlaceObject3Tag::GetFlags(Scaleform::GFx::PlaceObject3Tag *this, Scaleform::GFx::CharPosInfoFlags *result)
{
  char v2; // r8
  signed __int64 v3; // rax

  v2 = this->pData[0];
  v3 = 1i64;
  if ( v2 < 0 )
    v3 = 9i64;
  result->Flags = v2 & 0x5F | (unsigned __int8)(32 * (this->pData[v3] & 1 | 2 * (this->pData[v3] & 0xFE)));
  return result;
}

// File Line: 1108
// RVA: 0x8C9FA0
void __fastcall Scaleform::GFx::PlaceObject3Tag::Execute(Scaleform::GFx::PlaceObject3Tag *this, Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::DisplayObjContainer *v2; // rdi
  Scaleform::GFx::PlaceObject3Tag *v3; // rbx
  Scaleform::GFx::ASStringManager *v4; // rax
  Scaleform::GFx::ASString *v5; // rax
  char v6; // bl
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASStringManager *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  char v12; // bl
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString v16; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::ASString v17; // [rsp+60h] [rbp-A0h]
  Scaleform::Render::Cxform v18; // [rsp+70h] [rbp-90h]
  __int128 v19; // [rsp+90h] [rbp-70h]
  __m128 v20; // [rsp+A0h] [rbp-60h]
  Scaleform::Render::RenderBuffer *v21; // [rsp+B0h] [rbp-50h]
  int v22; // [rsp+B8h] [rbp-48h]
  int v23; // [rsp+BCh] [rbp-44h]
  int v24; // [rsp+C0h] [rbp-40h]
  __int64 v25; // [rsp+C8h] [rbp-38h]
  int v26; // [rsp+D0h] [rbp-30h]
  __int16 v27; // [rsp+D4h] [rbp-2Ch]
  __int64 v28; // [rsp+E0h] [rbp-20h]
  char *pstr; // [rsp+E8h] [rbp-18h]
  int v30; // [rsp+F0h] [rbp-10h]
  __int64 v31; // [rsp+100h] [rbp+0h]
  char v32; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::ASStringNode *v33; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::ASString v34; // [rsp+140h] [rbp+40h]
  Scaleform::GFx::ASString result; // [rsp+148h] [rbp+48h]

  v31 = -2i64;
  v2 = m;
  v3 = this;
  v33 = (Scaleform::GFx::ASStringNode *)&v18;
  Scaleform::Render::Cxform::Cxform(&v18);
  v19 = _xmm;
  v20 = _xmm;
  v21 = 0i64;
  v24 = 0x40000;
  v26 = 0;
  v22 = 0;
  v23 = 0;
  v27 = 256;
  v25 = 0i64;
  v3->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v3->vfptr, (unsigned int)&v18);
  if ( v30 )
  {
    if ( v30 == 1 )
    {
      Scaleform::GFx::DisplayList::MoveDisplayObject(
        &v2->mDisplayList,
        (Scaleform::GFx::DisplayObjectBase *)&v2->vfptr,
        (Scaleform::GFx::CharPosInfo *)&v18);
      goto LABEL_27;
    }
    if ( v30 != 2 )
      goto LABEL_27;
    v4 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v2->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
    if ( pstr )
    {
      v5 = Scaleform::GFx::ASStringManager::CreateString(v4, &v34, pstr);
      v6 = 8;
    }
    else
    {
      v5 = Scaleform::GFx::ASStringManager::CreateEmptyString(v4, &result);
      v6 = 4;
    }
    v33 = v5->pNode;
    ++v33->RefCount;
    if ( v6 & 8 )
    {
      v6 &= 0xF7u;
      v7 = v34.pNode;
      v8 = v34.pNode->RefCount == 1;
      --v7->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    }
    if ( v6 & 4 )
    {
      v9 = result.pNode;
      v8 = result.pNode->RefCount == 1;
      --v9->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::Render::Cxform *, Scaleform::GFx::ASStringNode **, char *))v2->vfptr[123].__vecDelDtor)(
      v2,
      &v18,
      &v33,
      &v32);
  }
  else
  {
    v10 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v2->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
    if ( pstr )
    {
      v11 = Scaleform::GFx::ASStringManager::CreateString(v10, &v17, pstr);
      v12 = 2;
    }
    else
    {
      v11 = Scaleform::GFx::ASStringManager::CreateEmptyString(v10, &v16);
      v12 = 1;
    }
    v33 = v11->pNode;
    ++v33->RefCount;
    if ( v12 & 2 )
    {
      v12 &= 0xFDu;
      v13 = v17.pNode;
      v8 = v17.pNode->RefCount == 1;
      --v13->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
    if ( v12 & 1 )
    {
      v14 = v16.pNode;
      v8 = v16.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::Render::Cxform *, Scaleform::GFx::ASStringNode **, __int64, _QWORD, signed int, signed int, _QWORD, _QWORD))v2->vfptr[118].__vecDelDtor)(
      v2,
      &v18,
      &v33,
      v28,
      0i64,
      -1,
      4,
      0i64,
      0i64);
  }
  v15 = v33;
  v8 = v33->RefCount == 1;
  --v15->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
LABEL_27:
  v33 = (Scaleform::GFx::ASStringNode *)&v18;
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
}

// File Line: 1159
// RVA: 0x9156A0
void __fastcall Scaleform::GFx::PlaceObject3Tag::Unpack(Scaleform::GFx::PlaceObject3Tag *this, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *v2; // rdi
  Scaleform::GFx::PlaceObject3Tag *v3; // r12
  char *v4; // r14
  const char *v5; // r10
  Scaleform::GFx::Resource *v6; // rbx
  unsigned __int8 v7; // si
  unsigned __int64 v8; // r8
  char v9; // r15
  unsigned __int64 v10; // r8
  __int64 v11; // r9
  unsigned __int16 v12; // cx
  signed __int64 v13; // r8
  char v14; // al
  unsigned __int16 v15; // cx
  unsigned __int16 v16; // cx
  char v17; // al
  unsigned __int16 v18; // cx
  Scaleform::Render::FilterSet *v19; // rax
  Scaleform::GFx::Resource *v20; // rax
  Scaleform::Render::RenderBuffer *v21; // rcx
  char v22; // cl
  char v23; // dl
  char v24; // r14
  Scaleform::GFx::Resource *v25; // rcx
  Scaleform::GFx::Resource *v26; // rbx
  Scaleform::Render::FilterSet *v27; // rax
  Scaleform::GFx::Resource *v28; // rax
  Scaleform::Render::RenderBuffer *v29; // rcx
  bool v30; // dl
  char v31; // al
  char v32; // al
  char v33; // si
  signed int v34; // eax
  signed __int64 v35; // [rsp+20h] [rbp-30h]
  Scaleform::GFx::StreamContext ps; // [rsp+28h] [rbp-28h]

  v35 = -2i64;
  v2 = data;
  v3 = this;
  v4 = this->pData;
  v5 = this->pData;
  ps.pData = this->pData;
  ps.DataSize = -1i64;
  v6 = 0i64;
  ps.CurByteIndex = 0i64;
  ps.CurBitIndex = 0;
  v7 = this->pData[0];
  v8 = 1i64;
  if ( (v7 & 0x80u) != 0 )
    v8 = 9i64;
  ps.CurByteIndex = v8;
  ps.CurBitIndex = 0;
  v9 = v4[v8];
  v10 = v8 + 1;
  ps.CurByteIndex = v10;
  v11 = 0i64;
  ps.CurBitIndex = 0;
  v12 = *(_WORD *)&v4[v10];
  v13 = v10 + 2;
  ps.CurByteIndex = v13;
  data->Pos.Depth = v12;
  if ( v9 & 8 )
  {
    data->Pos.Flags.Flags |= 0x100u;
    data->Pos.ClassName = &v3->pData[v13];
    ps.CurBitIndex = 0;
    do
    {
      v14 = v4[v13++];
      ps.CurByteIndex = v13;
    }
    while ( v14 );
  }
  if ( v7 & 2 )
  {
    data->Pos.Flags.Flags |= 2u;
    v11 = 0i64;
    ps.CurBitIndex = 0;
    v15 = *(_WORD *)&v4[v13];
    v13 += 2i64;
    ps.CurByteIndex = v13;
    data->Pos.CharacterId.Id = v15;
  }
  if ( v7 & 4 )
  {
    data->Pos.Flags.Flags |= 4u;
    Scaleform::GFx::StreamContext::ReadMatrix(&ps, &data->Pos.Matrix_1);
    v11 = ps.CurBitIndex;
    v13 = ps.CurByteIndex;
    v5 = ps.pData;
  }
  if ( v7 & 8 )
  {
    v2->Pos.Flags.Flags |= 8u;
    Scaleform::GFx::StreamContext::ReadCxformRgba(&ps, &v2->Pos.ColorTransform);
    v11 = ps.CurBitIndex;
    v13 = ps.CurByteIndex;
    v5 = ps.pData;
  }
  if ( v7 & 0x10 )
  {
    v2->Pos.Flags.Flags |= 0x10u;
    if ( (_DWORD)v11 )
      ps.CurByteIndex = ++v13;
    v11 = 0i64;
    ps.CurBitIndex = 0;
    v16 = *(_WORD *)&v5[v13];
    v13 += 2i64;
    ps.CurByteIndex = v13;
    v2->Pos.Ratio = (float)v16 * 0.000015259022;
  }
  if ( v7 & 0x20 )
  {
    if ( (_DWORD)v11 )
      ps.CurByteIndex = ++v13;
    v2->Name = &v3->pData[v13];
    v11 = 0i64;
    ps.CurBitIndex = 0;
    do
    {
      v17 = v5[v13++];
      ps.CurByteIndex = v13;
    }
    while ( v17 );
  }
  else
  {
    v2->Name = 0i64;
  }
  if ( v7 & 0x40 )
  {
    if ( (_DWORD)v11 )
      ps.CurByteIndex = ++v13;
    v11 = 0i64;
    ps.CurBitIndex = 0;
    v18 = *(_WORD *)&v5[v13];
    v13 += 2i64;
    ps.CurByteIndex = v13;
    v2->Pos.ClipDepth = v18;
    v2->Pos.Flags.Flags |= 0x40u;
  }
  if ( v9 & 1 )
  {
    v2->Pos.Flags.Flags |= 0x20u;
    v19 = (Scaleform::Render::FilterSet *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, _QWORD, __int64, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                            Scaleform::Memory::pGlobalHeap,
                                            56i64,
                                            0i64,
                                            v11,
                                            -2i64);
    if ( v19 )
    {
      Scaleform::Render::FilterSet::FilterSet(v19, 0i64);
      v6 = v20;
    }
    if ( (unsigned int)Scaleform::GFx::LoadFilters<Scaleform::GFx::StreamContext>(
                         &ps,
                         (Scaleform::Render::FilterSet *)v6) )
    {
      if ( v6 )
        Scaleform::Render::RenderBuffer::AddRef(v6);
      v21 = (Scaleform::Render::RenderBuffer *)v2->Pos.pFilters.pObject;
      if ( v21 )
        Scaleform::RefCountImpl::Release(v21);
      v2->Pos.pFilters.pObject = (Scaleform::Render::FilterSet *)v6;
    }
    if ( v6 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6);
    LODWORD(v6) = 0;
    v5 = ps.pData;
    v13 = ps.CurByteIndex;
    LODWORD(v11) = ps.CurBitIndex;
  }
  if ( v9 & 2 )
  {
    v2->Pos.Flags.Flags |= 0x80u;
    if ( (_DWORD)v11 )
      ps.CurByteIndex = ++v13;
    LODWORD(v11) = (_DWORD)v6;
    ps.CurBitIndex = (unsigned int)v6;
    v22 = v5[v13++];
    ps.CurByteIndex = v13;
    v23 = v22;
    if ( (unsigned __int8)(v22 - 1) > 0xDu )
      v23 = 1;
    v2->Pos.BlendMode = v23;
  }
  if ( v9 & 4 )
  {
    if ( (_DWORD)v11 )
      ps.CurByteIndex = ++v13;
    ps.CurBitIndex = (unsigned int)v6;
    v24 = v5[v13];
    ps.CurByteIndex = v13 + 1;
    v25 = (Scaleform::GFx::Resource *)v2->Pos.pFilters.pObject;
    if ( v25 )
      Scaleform::Render::RenderBuffer::AddRef(v25);
    v26 = (Scaleform::GFx::Resource *)v2->Pos.pFilters.pObject;
    if ( v24 == 1 )
    {
      if ( !v26 )
      {
        v27 = (Scaleform::Render::FilterSet *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                56ui64,
                                                0i64);
        if ( v27 )
        {
          Scaleform::Render::FilterSet::FilterSet(v27, 0i64);
          v26 = v28;
        }
        else
        {
          v26 = 0i64;
        }
        if ( v26 )
          Scaleform::Render::RenderBuffer::AddRef(v26);
        v29 = (Scaleform::Render::RenderBuffer *)v2->Pos.pFilters.pObject;
        if ( v29 )
          Scaleform::RefCountImpl::Release(v29);
        v2->Pos.pFilters.pObject = (Scaleform::Render::FilterSet *)v26;
      }
      v30 = 1;
    }
    else
    {
      if ( !v26 )
      {
LABEL_64:
        if ( v26 )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v26);
        v4 = v3->pData;
        v5 = ps.pData;
        v13 = ps.CurByteIndex;
        LODWORD(v11) = ps.CurBitIndex;
        goto LABEL_67;
      }
      v30 = 0;
    }
    Scaleform::Render::FilterSet::SetCacheAsBitmap((Scaleform::Render::FilterSet *)v26, v30);
    goto LABEL_64;
  }
LABEL_67:
  if ( v9 & 0x20 )
  {
    if ( (_DWORD)v11 )
      ps.CurByteIndex = ++v13;
    ps.CurBitIndex = 0;
    v31 = v5[v13];
    ps.CurByteIndex = v13 + 1;
    v2->Pos.Visible = v31;
    v2->Pos.Flags.Flags |= 0x200u;
  }
  if ( v7 & 0x80 )
    ((void (__fastcall *)(Scaleform::GFx::PlaceObject3Tag *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *, Scaleform::GFx::StreamContext *, char *, signed __int64))v3->vfptr[1].IsRemoveTag)(
      v3,
      v2,
      &ps,
      v4,
      v35);
  else
    v2->pEventHandlers = 0i64;
  v32 = v7 >> 1;
  v33 = v7 & 1;
  v2->PlaceType = 0;
  if ( v32 & 1 )
  {
    if ( v33 )
      v2->PlaceType = 2;
  }
  else
  {
    v34 = 0;
    if ( v33 )
      v34 = 1;
    v2->PlaceType = v34;
  }
}

// File Line: 1274
// RVA: 0x8B3560
void __fastcall Scaleform::GFx::PlaceObject2Tag::AddToTimelineSnapshot(Scaleform::GFx::PlaceObject2Tag *this, Scaleform::GFx::TimelineSnapshot *psnapshot, unsigned int frame)
{
  Scaleform::GFx::TimelineSnapshot *v3; // rbp
  unsigned int v4; // er14
  Scaleform::GFx::PlaceObject2Tag *v5; // rbx
  char v6; // si
  signed __int64 v7; // rax
  signed __int64 v8; // rdi
  unsigned __int16 v9; // dx
  unsigned __int8 v10; // al
  char v11; // cl
  int v12; // er9
  signed __int64 v13; // rdx
  Scaleform::GFx::TimelineSnapshot::SnapshotElement **v14; // r10
  signed __int64 v15; // r8
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v16; // rdi
  __int16 v17; // ax
  __int16 v18; // ax
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v19; // rax
  __int16 v20; // [rsp+40h] [rbp+8h]

  v3 = psnapshot;
  v4 = frame;
  v5 = this;
  this->vfptr->Trace((Scaleform::GFx::ExecuteTag *)this, "\n");
  v6 = 1;
  v7 = 1i64;
  if ( v5->pData[0] < 0 )
    v7 = 9i64;
  v8 = 0i64;
  v9 = *(_WORD *)&v5->pData[v7];
  v10 = v5->pData[0];
  v11 = v10 & 1;
  if ( !((v10 >> 1) & 1) )
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
  v13 = v3->SnapshotSortedArray.Data.Size;
  if ( v13 <= 0 )
    goto LABEL_63;
  v14 = v3->SnapshotSortedArray.Data.Data;
  do
  {
    v15 = (v13 >> 1) + v8;
    if ( v12 >= v14[v15]->Depth )
    {
      v8 = v15 + 1;
      v13 += -1 - (v13 >> 1);
    }
    else
    {
      v13 >>= 1;
    }
  }
  while ( v13 > 0 );
  if ( v8 && (v16 = v14[v8 - 1], v16->Depth == v12) && v16 && !(v16->Flags & 2) )
  {
    if ( v6 == 1 )
    {
      ((void (__fastcall *)(Scaleform::GFx::PlaceObject2Tag *, __int16 *))v5->vfptr[1].ExecuteWithPriority)(v5, &v20);
      v18 = v20;
      if ( ((unsigned __int8)v20 >> 2) & 1 )
        v16->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v18 >> 3) & 1 )
        v16->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v18 >> 5) & 1 )
        v16->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( (v18 & 0x80u) != 0 )
        v16->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( v18 & 1 )
        v16->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v18 >> 6) & 1 )
        v16->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v18 >> 4) & 1 )
        v16->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v18 >> 1) & 1 )
        v16->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( v18 & 0x100 )
        v16->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    }
    else if ( v6 == 2 )
    {
      if ( v16->PlaceType )
        v16->PlaceType = 2;
      ((void (__fastcall *)(Scaleform::GFx::PlaceObject2Tag *, __int16 *))v5->vfptr[1].ExecuteWithPriority)(v5, &v20);
      v17 = v20;
      if ( ((unsigned __int8)v20 >> 2) & 1 )
        v16->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v17 >> 3) & 1 )
        v16->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v17 >> 5) & 1 )
        v16->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( (v17 & 0x80u) != 0 )
        v16->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( v17 & 1 )
        v16->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v17 >> 6) & 1 )
        v16->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v17 >> 4) & 1 )
        v16->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v17 >> 1) & 1 )
        v16->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( v17 & 0x100 )
        v16->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->CreateFrame = v4;
    }
    else
    {
      v16->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pMainTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->CreateFrame = v4;
    }
  }
  else
  {
LABEL_63:
    v19 = Scaleform::GFx::TimelineSnapshot::Add(v3, v12);
    v19->PlaceType = v6;
    v19->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pMainTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->CreateFrame = v4;
  }
}

// File Line: 1348
// RVA: 0x8B3810
void __fastcall Scaleform::GFx::PlaceObject3Tag::AddToTimelineSnapshot(Scaleform::GFx::PlaceObject3Tag *this, Scaleform::GFx::TimelineSnapshot *psnapshot, unsigned int frame)
{
  Scaleform::GFx::TimelineSnapshot *v3; // rbp
  unsigned int v4; // er14
  Scaleform::GFx::PlaceObject3Tag *v5; // rbx
  char v6; // si
  signed __int64 v7; // rax
  signed __int64 v8; // rdi
  unsigned __int16 v9; // dx
  unsigned __int8 v10; // al
  char v11; // cl
  int v12; // er9
  signed __int64 v13; // rdx
  Scaleform::GFx::TimelineSnapshot::SnapshotElement **v14; // r10
  signed __int64 v15; // r8
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v16; // rdi
  __int16 v17; // ax
  __int16 v18; // ax
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v19; // rax
  __int16 v20; // [rsp+40h] [rbp+8h]

  v3 = psnapshot;
  v4 = frame;
  v5 = this;
  this->vfptr->Trace((Scaleform::GFx::ExecuteTag *)this, "\n");
  v6 = 1;
  v7 = 1i64;
  if ( v5->pData[0] < 0 )
    v7 = 9i64;
  v8 = 0i64;
  v9 = *(_WORD *)&v5->pData[v7 + 1];
  v10 = v5->pData[0];
  v11 = v10 & 1;
  if ( !((v10 >> 1) & 1) )
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
  v13 = v3->SnapshotSortedArray.Data.Size;
  if ( v13 <= 0 )
    goto LABEL_63;
  v14 = v3->SnapshotSortedArray.Data.Data;
  do
  {
    v15 = (v13 >> 1) + v8;
    if ( v12 >= v14[v15]->Depth )
    {
      v8 = v15 + 1;
      v13 += -1 - (v13 >> 1);
    }
    else
    {
      v13 >>= 1;
    }
  }
  while ( v13 > 0 );
  if ( v8 && (v16 = v14[v8 - 1], v16->Depth == v12) && v16 && !(v16->Flags & 2) )
  {
    if ( v6 == 1 )
    {
      ((void (__fastcall *)(Scaleform::GFx::PlaceObject3Tag *, __int16 *))v5->vfptr[1].ExecuteWithPriority)(v5, &v20);
      v18 = v20;
      if ( ((unsigned __int8)v20 >> 2) & 1 )
        v16->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v18 >> 3) & 1 )
        v16->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v18 >> 5) & 1 )
        v16->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( (v18 & 0x80u) != 0 )
        v16->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( v18 & 1 )
        v16->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v18 >> 6) & 1 )
        v16->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v18 >> 4) & 1 )
        v16->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v18 >> 1) & 1 )
        v16->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( v18 & 0x100 )
        v16->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    }
    else if ( v6 == 2 )
    {
      if ( v16->PlaceType )
        v16->PlaceType = 2;
      ((void (__fastcall *)(Scaleform::GFx::PlaceObject3Tag *, __int16 *))v5->vfptr[1].ExecuteWithPriority)(v5, &v20);
      v17 = v20;
      if ( ((unsigned __int8)v20 >> 2) & 1 )
        v16->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v17 >> 3) & 1 )
        v16->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v17 >> 5) & 1 )
        v16->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( (v17 & 0x80u) != 0 )
        v16->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( v17 & 1 )
        v16->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v17 >> 6) & 1 )
        v16->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v17 >> 4) & 1 )
        v16->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( ((unsigned __int8)v17 >> 1) & 1 )
        v16->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      if ( v17 & 0x100 )
        v16->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->CreateFrame = v4;
    }
    else
    {
      v16->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->Tags.pMainTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
      v16->CreateFrame = v4;
    }
  }
  else
  {
LABEL_63:
    v19 = Scaleform::GFx::TimelineSnapshot::Add(v3, v12);
    v19->PlaceType = v6;
    v19->Tags.pClassNameTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pCharIdTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pRatioTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pClipDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pDepthTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pBlendModeTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pFiltersTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pCxFormTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pMatrixTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->Tags.pMainTag = (Scaleform::GFx::GFxPlaceObjectBase *)&v5->vfptr;
    v19->CreateFrame = v4;
  }
}

// File Line: 1426
// RVA: 0x8F86A0
void __fastcall Scaleform::GFx::RemoveObjectTag::Read(Scaleform::GFx::RemoveObjectTag *this, Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::Stream *v2; // rbx
  Scaleform::GFx::LoadProcess *v3; // rdi
  Scaleform::GFx::RemoveObjectTag *v4; // rsi
  unsigned int v5; // eax
  __int64 v6; // r9
  unsigned __int16 v7; // r8
  Scaleform::GFx::Stream *v8; // rbx
  unsigned int v9; // eax
  __int64 v10; // r9
  unsigned __int16 v11; // r8

  v2 = p->pAltStream;
  v3 = p;
  v4 = this;
  if ( !v2 )
    v2 = &p->ProcessInfo.Stream;
  v5 = v2->DataSize;
  v2->UnusedBits = 0;
  if ( (signed int)(v5 - v2->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v2, 2);
  v6 = v2->Pos;
  v7 = (unsigned __int8)v2->pBuffer[v6] | (unsigned __int16)((unsigned __int8)v2->pBuffer[(unsigned int)(v6 + 1)] << 8);
  v2->Pos = v6 + 2;
  v4->Id = v7;
  v8 = v3->pAltStream;
  if ( !v8 )
    v8 = &v3->ProcessInfo.Stream;
  v9 = v8->DataSize;
  v8->UnusedBits = 0;
  if ( (signed int)(v9 - v8->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v8, 2);
  v10 = v8->Pos;
  v11 = (unsigned __int8)v8->pBuffer[v10] | (unsigned __int16)((unsigned __int8)v8->pBuffer[(unsigned int)(v10 + 1)] << 8);
  v8->Pos = v10 + 2;
  v4->Depth = v11;
}

// File Line: 1432
// RVA: 0x8CA380
void __fastcall Scaleform::GFx::RemoveObjectTag::Execute(Scaleform::GFx::RemoveObjectTag *this, Scaleform::GFx::DisplayObjContainer *m)
{
  int v2; // er8
  Scaleform::GFx::ResourceId id; // [rsp+30h] [rbp+8h]

  v2 = this->Depth;
  id.Id = this->Id;
  Scaleform::GFx::DisplayList::RemoveDisplayObject(
    &m->mDisplayList,
    (Scaleform::GFx::DisplayObjectBase *)&m->vfptr,
    v2,
    (Scaleform::GFx::ResourceId)&id);
}

// File Line: 1453
// RVA: 0x8F8630
void __fastcall Scaleform::GFx::RemoveObject2Tag::Read(Scaleform::GFx::RemoveObject2Tag *this, Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::Stream *v2; // rbx
  Scaleform::GFx::RemoveObject2Tag *v3; // rdi
  unsigned int v4; // eax
  __int64 v5; // r9
  unsigned __int16 v6; // r8

  v2 = p->pAltStream;
  v3 = this;
  if ( !v2 )
    v2 = &p->ProcessInfo.Stream;
  v4 = v2->DataSize;
  v2->UnusedBits = 0;
  if ( (signed int)(v4 - v2->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v2, 2);
  v5 = v2->Pos;
  v6 = (unsigned __int8)v2->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v2->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v2->Pos = v5 + 2;
  v3->Depth = v6;
}

// File Line: 1458
// RVA: 0x8CA350
void __fastcall Scaleform::GFx::RemoveObject2Tag::Execute(Scaleform::GFx::RemoveObject2Tag *this, Scaleform::GFx::DisplayObjContainer *m)
{
  int v2; // er8
  Scaleform::GFx::ResourceId id; // [rsp+30h] [rbp+8h]

  v2 = this->Depth;
  id.Id = 0x40000;
  Scaleform::GFx::DisplayList::RemoveDisplayObject(
    &m->mDisplayList,
    (Scaleform::GFx::DisplayObjectBase *)&m->vfptr,
    v2,
    (Scaleform::GFx::ResourceId)&id);
}

// File Line: 1463
// RVA: 0x8B3BF0
void __fastcall Scaleform::GFx::RemoveObject2Tag::AddToTimelineSnapshot(Scaleform::GFx::RemoveObject2Tag *this, Scaleform::GFx::TimelineSnapshot *psnapshot, __int64 __formal)
{
  Scaleform::GFx::TimelineSnapshot *v3; // rsi
  Scaleform::GFx::RemoveObject2Tag *v4; // r14
  signed __int64 v5; // r8
  int v6; // er11
  signed __int64 v7; // r9
  Scaleform::GFx::TimelineSnapshot::SnapshotElement **v8; // r10
  signed __int64 v9; // rdx
  __int64 v10; // rax
  unsigned __int64 v11; // rdi
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *v12; // rbx
  __int64 v13; // rcx
  __int64 v14; // rax
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *v15; // rbx
  bool v16; // zf
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v17; // rax
  int v18; // ecx
  unsigned __int64 v19; // [rsp+40h] [rbp+8h]

  v3 = psnapshot;
  v4 = this;
  ((void (__fastcall *)(Scaleform::GFx::RemoveObject2Tag *, const char *, __int64))this->vfptr->Trace)(
    this,
    "\n",
    __formal);
  v5 = v3->SnapshotSortedArray.Data.Size;
  v6 = v4->Depth;
  v7 = 0i64;
  if ( v5 <= 0 )
    goto LABEL_23;
  v8 = v3->SnapshotSortedArray.Data.Data;
  do
  {
    v9 = (v5 >> 1) + v7;
    if ( v6 >= v8[v9]->Depth )
    {
      v7 = v9 + 1;
      v5 += -1 - (v5 >> 1);
    }
    else
    {
      v5 >>= 1;
    }
  }
  while ( v5 > 0 );
  if ( !v7 || (v10 = (__int64)v8[v7 - 1], v11 = v7 - 1, *(_DWORD *)(v10 + 20) != v6) )
  {
LABEL_23:
    v11 = v19;
    v10 = 0i64;
  }
  v19 = v10;
  if ( !v10 )
    goto LABEL_19;
  if ( *(_BYTE *)(v10 + 104) )
  {
    v12 = (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)v3->SnapshotSortedArray.Data.Data[v11];
    v12->pNext[1].pNext = v12[1].pNext;
    v12[1].pNext->pNext = v12->pNext;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,Scaleform::AllocatorDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2>,Scaleform::ArrayDefaultPolicy> > *)&v3->SnapshotSortedArray.Data,
      v11);
    v12->pNext = v3->SnapshotHeap.FirstEmptySlot;
    v3->SnapshotHeap.FirstEmptySlot = v12;
    v19 = 0i64;
LABEL_19:
    if ( v3->Direction == Direction_Forward )
    {
      v17 = Scaleform::GFx::TimelineSnapshot::Add(v3, v4->Depth);
      v18 = v4->Depth;
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
    if ( v3->Direction == Direction_Forward )
    {
      v14 = (*(__int64 (**)(void))(*(_QWORD *)v13 + 72i64))();
      if ( v14 )
        ((void (__fastcall *)(Scaleform::GFx::RemoveObject2Tag *, unsigned __int64 *, __int64))v4->vfptr[1].Execute)(
          v4,
          &v19,
          v14);
    }
  }
  if ( !v19 )
    goto LABEL_19;
  v15 = (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)v3->SnapshotSortedArray.Data.Data[v11];
  v15->pNext[1].pNext = v15[1].pNext;
  v15[1].pNext->pNext = v15->pNext;
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
    (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,Scaleform::AllocatorDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2>,Scaleform::ArrayDefaultPolicy> > *)&v3->SnapshotSortedArray.Data,
    v11);
  v15->pNext = v3->SnapshotHeap.FirstEmptySlot;
  v16 = v19 == 0;
  v3->SnapshotHeap.FirstEmptySlot = v15;
  if ( v16 )
    goto LABEL_19;
}ySlot;
  v16 = v19 == 0

// File Line: 1528
// RVA: 0x8CA3B0
void __usercall Scaleform::GFx::SetBackgroundColorTag::Execute(Scaleform::GFx::SetBackgroundColorTag *this@<rcx>, Scaleform::GFx::DisplayObjContainer *m@<rdx>, float a3@<xmm0>)
{
  Scaleform::GFx::SetBackgroundColorTag *v3; // rdi
  Scaleform::GFx::MovieImpl *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm0_4
  unsigned int v7; // [rsp+38h] [rbp+10h]

  v3 = this;
  v4 = m->pASRoot->pMovieImpl;
  if ( !((v4->Flags >> 17) & 1) )
  {
    ((void (__fastcall *)(Scaleform::GFx::MovieImpl *))v4->vfptr[34].__vecDelDtor)(m->pASRoot->pMovieImpl);
    v5 = a3 * 255.0;
    if ( v5 <= 0.0 )
      v6 = v5 - 0.5;
    else
      v6 = v5 + 0.5;
    v3->Color.Channels.Alpha = (signed int)v6;
    v7 = v3->Color.Raw;
    v4->vfptr[32].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&v7);
    v4->Flags |= 0x20000u;
  }
}

