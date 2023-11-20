// File Line: 64
// RVA: 0x906C80
void __fastcall Scaleform::GFx::ExporterInfoImpl::SetData(Scaleform::GFx::ExporterInfoImpl *this, unsigned __int16 version, Scaleform::GFx::FileTypeConstants::FileFormatType format, const char *pname, const char *pprefix, unsigned int flags, Scaleform::Array<unsigned long,2,Scaleform::ArrayDefaultPolicy> *codeOffsets)
{
  Scaleform::GFx::ExporterInfoImpl *v7; // r15
  const char *v8; // rdi
  char *v9; // rdx
  const char *v10; // rsi
  unsigned __int64 v11; // rbx

  this->SI.Version = version;
  v7 = this;
  this->SI.Format = format;
  v8 = &customWorldMapCaption;
  v9 = &customWorldMapCaption;
  v10 = pname;
  if ( pprefix )
    v9 = (char *)pprefix;
  Scaleform::String::operator=(&this->Prefix, v9);
  if ( v10 )
    v8 = v10;
  Scaleform::String::operator=(&v7->SWFName, v8);
  v7->SI.pSWFName = (const char *)((v7->SWFName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v7->SI.pPrefix = (const char *)((v7->Prefix.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v7->SI.ExportFlags = flags;
  if ( codeOffsets )
  {
    Scaleform::ArrayData<unsigned long,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v7->CodeOffsets.Data,
      codeOffsets->Data.Size);
    v11 = 0i64;
    if ( v7->CodeOffsets.Data.Size )
    {
      do
      {
        ++v11;
        v7->CodeOffsets.Data.Data[v11 - 1] = codeOffsets->Data.Data[v11 - 1];
      }
      while ( v11 < v7->CodeOffsets.Data.Size );
    }
  }
  else
  {
    if ( v7->CodeOffsets.Data.Size && v7->CodeOffsets.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v7->CodeOffsets.Data.Data )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v7->CodeOffsets.Data.Data = 0i64;
      }
      v7->CodeOffsets.Data.Policy.Capacity = 0i64;
    }
    v7->CodeOffsets.Data.Size = 0i64;
  }
}

// File Line: 83
// RVA: 0x8FBA20
void __fastcall Scaleform::GFx::ExporterInfoImpl::ReadExporterInfoTag(Scaleform::GFx::ExporterInfoImpl *this, Scaleform::GFx::Stream *pin, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::Stream *v3; // rbx
  unsigned __int64 v4; // r15
  int v5; // er12
  __int64 v6; // r8
  unsigned __int16 v7; // r13
  __int64 v8; // r8
  __int64 v9; // r8
  __int64 v10; // rdx
  unsigned __int64 v11; // rcx
  __int64 v12; // rdx
  unsigned __int64 v13; // rcx
  __int64 v14; // r8
  unsigned __int16 v15; // r9
  __int64 v16; // r14
  __int64 v17; // r8
  int v18; // esi
  unsigned __int64 v19; // rdi
  unsigned __int64 v20; // r8
  int *v21; // rcx
  bool v22; // zf
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rsi
  const char *v25; // rdi
  const char *v26; // rdx
  __int64 v27; // r8
  __int64 v28; // r9
  unsigned __int64 v29; // rdi
  unsigned __int64 v30; // r8
  unsigned __int64 v31; // rdx
  unsigned __int64 v32; // rdx
  __int64 v33; // [rsp+20h] [rbp-69h]
  Scaleform::String v34; // [rsp+50h] [rbp-39h]
  __int64 v35; // [rsp+58h] [rbp-31h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v36; // [rsp+60h] [rbp-29h]
  Scaleform::String::InitStruct src; // [rsp+68h] [rbp-21h]
  Scaleform::GFx::Stream *v38; // [rsp+70h] [rbp-19h]
  Scaleform::String::InitStruct v39; // [rsp+78h] [rbp-11h]
  Scaleform::GFx::Stream *v40; // [rsp+80h] [rbp-9h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+88h] [rbp-1h]
  Scaleform::GFx::ExporterInfoImpl *v42; // [rsp+F0h] [rbp+67h]
  unsigned __int16 v43; // [rsp+F8h] [rbp+6Fh]
  Scaleform::String v44; // [rsp+108h] [rbp+7Fh]

  v42 = this;
  v35 = -2i64;
  v3 = pin;
  v4 = 0i64;
  v5 = 0;
  pin->UnusedBits = 0;
  if ( (signed int)(pin->DataSize - pin->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
  v6 = v3->Pos;
  v7 = (unsigned __int8)v3->pBuffer[v6] | (unsigned __int16)((unsigned __int8)v3->pBuffer[(unsigned int)(v6 + 1)] << 8);
  v3->Pos = v6 + 2;
  if ( v7 >= 0x10Au )
  {
    v3->UnusedBits = 0;
    if ( (signed int)(v3->DataSize - (v6 + 2)) < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(v3, 4);
    v8 = v3->Pos;
    v5 = (unsigned __int8)v3->pBuffer[v8] | (((unsigned __int8)v3->pBuffer[(unsigned int)(v8 + 1)] | (((unsigned __int8)v3->pBuffer[(unsigned int)(v8 + 2)] | ((unsigned __int8)v3->pBuffer[(unsigned int)(v8 + 3)] << 8)) << 8)) << 8);
    v3->Pos = v8 + 4;
  }
  v3->UnusedBits = 0;
  if ( (signed int)(v3->DataSize - v3->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 2);
  v9 = v3->Pos;
  v43 = (unsigned __int8)v3->pBuffer[v9] | (unsigned __int16)((unsigned __int8)v3->pBuffer[(unsigned int)(v9 + 1)] << 8);
  v3->Pos = v9 + 2;
  Scaleform::String::String(&v34);
  Scaleform::String::String(&v44);
  v3->UnusedBits = 0;
  if ( (signed int)(v3->DataSize - v3->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
  v10 = v3->Pos;
  v11 = (unsigned __int8)v3->pBuffer[v10];
  v3->Pos = v10 + 1;
  if ( (signed int)v11 > 0 )
  {
    src.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength::`2::StringReader::`vftable;
    v38 = v3;
    Scaleform::String::AssignString(&v34, &src, v11);
    src.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  }
  else
  {
    Scaleform::String::Clear(&v34);
  }
  v3->UnusedBits = 0;
  if ( (signed int)(v3->DataSize - v3->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
  v12 = v3->Pos;
  v13 = (unsigned __int8)v3->pBuffer[v12];
  v3->Pos = v12 + 1;
  if ( (signed int)v13 > 0 )
  {
    v39.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength::`2::StringReader::`vftable;
    v40 = v3;
    Scaleform::String::AssignString(&v44, &v39, v13);
    v39.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  }
  else
  {
    Scaleform::String::Clear(&v44);
  }
  v36 = &pheapAddr;
  pheapAddr.Data = 0i64;
  pheapAddr.Size = 0i64;
  pheapAddr.Policy.Capacity = 0i64;
  if ( v7 >= 0x401u )
  {
    v3->UnusedBits = 0;
    if ( (signed int)(v3->DataSize - v3->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v3, 2);
    v14 = v3->Pos;
    v15 = (unsigned __int8)v3->pBuffer[v14] | (unsigned __int16)((unsigned __int8)v3->pBuffer[(unsigned int)(v14 + 1)] << 8);
    v3->Pos = v14 + 2;
    if ( v15 > 0u )
    {
      v16 = v15;
      do
      {
        v3->UnusedBits = 0;
        if ( (signed int)(v3->DataSize - v3->Pos) < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(v3, 4);
        v17 = v3->Pos;
        v18 = (unsigned __int8)v3->pBuffer[v17] | (((unsigned __int8)v3->pBuffer[(unsigned int)(v17 + 1)] | (((unsigned __int8)v3->pBuffer[(unsigned int)(v17 + 2)] | ((unsigned __int8)v3->pBuffer[(unsigned int)(v17 + 3)] << 8)) << 8)) << 8);
        v3->Pos = v17 + 4;
        v19 = pheapAddr.Size + 1;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v19 > pheapAddr.Policy.Capacity )
          {
            v20 = v19 + (v19 >> 2);
            goto LABEL_31;
          }
        }
        else if ( v19 < pheapAddr.Policy.Capacity >> 1 )
        {
          v20 = pheapAddr.Size + 1;
LABEL_31:
          Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v20);
          goto LABEL_32;
        }
LABEL_32:
        pheapAddr.Size = v19;
        v21 = &pheapAddr.Data[v19 - 1];
        if ( v21 )
          *v21 = v18;
        --v16;
      }
      while ( v16 );
    }
  }
  LODWORD(v33) = (unsigned __int8)v7;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
    "  ExportInfo: tagType = %d, tool ver = %d.%d, imgfmt = %d, prefix = %s, swfname = %s, flags = 0x%X\n");
  v22 = (v34.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
  v23 = (v34.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12;
  v24 = (v44.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12;
  v42->SI.Version = v7;
  v42->SI.Format = v43;
  v25 = &customWorldMapCaption;
  v26 = &customWorldMapCaption;
  if ( !v22 )
    v26 = (const char *)v23;
  Scaleform::String::operator=(&v42->Prefix, v26);
  if ( v24 )
    v25 = (const char *)v24;
  Scaleform::String::operator=(&v42->SWFName, v25);
  v42->SI.pSWFName = (const char *)((v42->SWFName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v42->SI.pPrefix = (const char *)((v42->Prefix.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v42->SI.ExportFlags = v5;
  v29 = pheapAddr.Size;
  if ( pheapAddr.Size >= v42->CodeOffsets.Data.Size )
  {
    if ( pheapAddr.Size <= v42->CodeOffsets.Data.Policy.Capacity )
      goto LABEL_45;
    v30 = pheapAddr.Size + (pheapAddr.Size >> 2);
  }
  else
  {
    if ( pheapAddr.Size >= v42->CodeOffsets.Data.Policy.Capacity >> 1 )
      goto LABEL_45;
    v30 = pheapAddr.Size;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v42->CodeOffsets,
    &v42->CodeOffsets,
    v30);
LABEL_45:
  v42->CodeOffsets.Data.Size = v29;
  if ( v29 )
  {
    do
    {
      v42->CodeOffsets.Data.Data[v4] = pheapAddr.Data[v4];
      ++v4;
    }
    while ( v4 < v42->CodeOffsets.Data.Size );
  }
  if ( pheapAddr.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, int *, __int64, __int64, _DWORD))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      pheapAddr.Data,
      v27,
      v28,
      v33);
  v31 = v44.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v44.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64, __int64, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v31,
      v27,
      v28,
      v33);
  v32 = v34.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v34.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64, __int64, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v32,
      v27,
      v28,
      v33);
}

// File Line: 137
// RVA: 0x8E57A0
char __fastcall Scaleform::GFx::SWFProcessInfo::Initialize(Scaleform::GFx::SWFProcessInfo *this, Scaleform::File *pin, Scaleform::GFx::LogState *plog, Scaleform::GFx::ZlibSupportBase *zlib, Scaleform::GFx::ParseControl *pparseControl, bool parseMsg)
{
  Scaleform::GFx::ZlibSupportBase *v6; // r15
  Scaleform::GFx::LogState *v7; // rbp
  Scaleform::File *v8; // rbx
  Scaleform::GFx::SWFProcessInfo *v9; // rsi
  bool v10; // di
  int v11; // edx
  int v12; // ecx
  bool v13; // r12
  int v14; // eax
  Scaleform::GFx::ParseControl *v16; // r14
  const char *v17; // rdx
  __int64 v18; // rdi
  Scaleform::Log *v19; // rax
  __int64 v20; // r9
  unsigned __int16 v21; // r8
  __int64 v22; // r9
  unsigned __int16 v23; // r8
  char v24; // di
  unsigned int v25; // edi
  __int64 v26; // r9
  unsigned __int16 v27; // r8
  int v28; // edx
  __int64 v29; // r9
  unsigned __int16 v30; // r8
  Scaleform::GFx::TagInfo pTagInfo; // [rsp+38h] [rbp-40h]
  Scaleform::LogMessageId messageType; // [rsp+80h] [rbp+8h]
  __int64 v33; // [rsp+88h] [rbp+10h]

  v6 = zlib;
  v7 = plog;
  v8 = pin;
  v9 = this;
  this->FileStartPos = ((__int64 (__fastcall *)(Scaleform::File *))pin->vfptr[4].__vecDelDtor)(pin);
  v10 = 0;
  LODWORD(v33) = 0;
  ((void (__fastcall *)(Scaleform::File *, __int64 *, signed __int64))v8->vfptr[10].__vecDelDtor)(v8, &v33, 4i64);
  messageType.Id = 0;
  ((void (__fastcall *)(Scaleform::File *, Scaleform::LogMessageId *, signed __int64))v8->vfptr[10].__vecDelDtor)(
    v8,
    &messageType,
    4i64);
  v11 = messageType.Id;
  v9->Header.FileLength = messageType.Id;
  v9->FileEndPos = v11 + v9->FileStartPos;
  v9->NextActionBlock = 0;
  v12 = v33;
  v9->Header.Version = (unsigned int)v33 >> 24;
  v9->Header.SWFFlags = 0;
  v13 = (_BYTE)v12 == 67;
  v9->FileAttributes = 0;
  v14 = v12 & 0xFFFFFF;
  if ( (v12 & 0xFFFFFF) != 5461830 && v14 != 5461827 && v14 != 5785159 && v14 != 5785155 )
  {
    if ( v7 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v7->vfptr,
        "Loader read failed - file does not start with a SWF header");
    return 0;
  }
  if ( (v12 & 0xFF0000) == 5767168 )
    v9->Header.SWFFlags = 16;
  if ( (_BYTE)v12 == 67 )
    v9->Header.SWFFlags |= 1u;
  v16 = pparseControl;
  if ( v7 )
  {
    if ( pparseControl )
    {
      if ( pparseControl->ParseFlags & 1 )
      {
        v10 = parseMsg;
        if ( parseMsg )
        {
          messageType.Id = 20480;
          Scaleform::Log::LogMessageById(
            v7,
            (Scaleform::LogMessageId)&messageType,
            "SWF File version = %d, File length = %d\n");
        }
      }
    }
  }
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v8);
  v33 = (__int64)v8;
  if ( !v13 )
  {
LABEL_24:
    v19 = v7->pLog.pObject;
    if ( !v19 )
      v19 = Scaleform::Log::GetGlobalLog();
    Scaleform::GFx::Stream::Initialize(&v9->Stream, v8, v19, v16);
    Scaleform::GFx::Stream::ReadRect(&v9->Stream, &v9->Header.FrameRect);
    v9->Stream.UnusedBits = 0;
    if ( (signed int)(v9->Stream.DataSize - v9->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&v9->Stream, 2);
    v20 = v9->Stream.Pos;
    v21 = (unsigned __int8)v9->Stream.pBuffer[v20] | (unsigned __int16)((unsigned __int8)v9->Stream.pBuffer[(unsigned int)(v20 + 1)] << 8);
    v9->Stream.Pos = v20 + 2;
    v9->Header.FPS = (float)v21 * 0.00390625;
    v9->Stream.UnusedBits = 0;
    if ( (signed int)(v9->Stream.DataSize - v9->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&v9->Stream, 2);
    v22 = v9->Stream.Pos;
    v23 = (unsigned __int8)v9->Stream.pBuffer[v22] | (unsigned __int16)((unsigned __int8)v9->Stream.pBuffer[(unsigned int)(v22 + 1)] << 8);
    v9->Stream.Pos = v22 + 2;
    v9->Header.FrameCount = v23;
    if ( v9->Header.SWFFlags & 0x10 )
    {
      if ( v9->Stream.Pos + v9->Stream.FilePos - v9->Stream.DataSize < v9->FileEndPos )
      {
        if ( Scaleform::GFx::Stream::OpenTag(&v9->Stream) != 1000 )
        {
          v17 = "Loader read failed - no mExporterInfo tag in GFX file header";
          goto LABEL_35;
        }
        Scaleform::GFx::ExporterInfoImpl::ReadExporterInfoTag(&v9->Header.mExporterInfo, &v9->Stream, Tag_ExporterInfo);
        Scaleform::GFx::Stream::SetPosition(&v9->Stream, v9->Stream.TagStack[--v9->Stream.TagStackEntryCount]);
        v9->Stream.UnusedBits = 0;
      }
      if ( v9->Header.Version < 9
        || (v25 = v9->Stream.Pos + v9->Stream.FilePos - v9->Stream.DataSize, v25 >= v9->FileEndPos) )
      {
LABEL_54:
        v24 = 1;
        goto LABEL_55;
      }
      for ( ; (signed int)Scaleform::GFx::Stream::OpenTag(&v9->Stream, &pTagInfo) >= 1000; v9->Stream.UnusedBits = 0 )
        Scaleform::GFx::Stream::SetPosition(&v9->Stream, v9->Stream.TagStack[--v9->Stream.TagStackEntryCount]);
      if ( pTagInfo.TagType == 69 )
      {
        v9->Stream.UnusedBits = 0;
        if ( (signed int)(v9->Stream.DataSize - v9->Stream.Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&v9->Stream, 2);
        v26 = v9->Stream.Pos;
        v27 = (unsigned __int8)v9->Stream.pBuffer[v26] | (unsigned __int16)((unsigned __int8)v9->Stream.pBuffer[(unsigned int)(v26 + 1)] << 8);
        v9->Stream.Pos = v26 + 2;
        v9->FileAttributes = v27;
      }
      Scaleform::GFx::Stream::SetPosition(&v9->Stream, v9->Stream.TagStack[--v9->Stream.TagStackEntryCount]);
      v28 = v25;
    }
    else
    {
      if ( v9->Header.Version < 9 || v9->Stream.Pos + v9->Stream.FilePos - v9->Stream.DataSize >= v9->FileEndPos )
        goto LABEL_54;
      if ( Scaleform::GFx::Stream::OpenTag(&v9->Stream, &pTagInfo) == 69 )
      {
        v9->Stream.UnusedBits = 0;
        if ( (signed int)(v9->Stream.DataSize - v9->Stream.Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&v9->Stream, 2);
        v29 = v9->Stream.Pos;
        v30 = (unsigned __int8)v9->Stream.pBuffer[v29] | (unsigned __int16)((unsigned __int8)v9->Stream.pBuffer[(unsigned int)(v29 + 1)] << 8);
        v9->Stream.Pos = v29 + 2;
        v9->FileAttributes = v30;
      }
      Scaleform::GFx::Stream::SetPosition(&v9->Stream, v9->Stream.TagStack[--v9->Stream.TagStackEntryCount]);
      v28 = pTagInfo.TagOffset;
    }
    v9->Stream.UnusedBits = 0;
    Scaleform::GFx::Stream::SetPosition(&v9->Stream, v28);
    goto LABEL_54;
  }
  if ( v6 )
  {
    if ( v10 )
    {
      messageType.Id = 20480;
      Scaleform::Log::LogMessageById(v7, (Scaleform::LogMessageId)&messageType, "SWF file is compressed.\n");
    }
    v18 = (__int64)v6->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)v8);
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8);
    v8 = (Scaleform::File *)v18;
    v33 = v18;
    v9->FileEndPos = v9->Header.FileLength - 8;
    goto LABEL_24;
  }
  if ( v7 )
  {
    v17 = "Loader - unable to read compressed SWF data; GFxZlibState is not set.";
LABEL_35:
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v7->vfptr,
      v17);
  }
  v24 = 0;
LABEL_55:
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8);
  return v24;
}

// File Line: 286
// RVA: 0x89A410
void __fastcall Scaleform::GFx::LoaderTask::LoaderTask(Scaleform::GFx::LoaderTask *this, Scaleform::GFx::LoadStates *pls, Scaleform::GFx::Task::TaskId id)
{
  Scaleform::GFx::LoadStates *v3; // rdi
  Scaleform::GFx::LoaderTask *v4; // rbx

  v3 = pls;
  v4 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Task,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  this->ThisTaskId = id;
  this->CurrentState = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderTask::`vftable;
  if ( pls )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pls);
  v4->pLoadStates.pObject = v3;
  Scaleform::GFx::LoaderImpl::RegisterLoadProcess(v4->pLoadStates.pObject->pLoaderImpl.pObject, v4);
}

// File Line: 291
// RVA: 0x8A5D30
void __fastcall Scaleform::GFx::LoaderTask::~LoaderTask(Scaleform::GFx::LoaderTask *this)
{
  Scaleform::GFx::LoaderTask *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderTask::`vftable;
  Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(this->pLoadStates.pObject->pLoaderImpl.pObject, this);
  v2 = (Scaleform::Render::RenderBuffer *)v1->pLoadStates.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 301
// RVA: 0x899F60
void __fastcall Scaleform::GFx::LoaderImpl::LoaderImpl(Scaleform::GFx::LoaderImpl *this, Scaleform::GFx::ResourceLib *plib, bool debugHeap)
{
  bool v3; // bl
  Scaleform::GFx::ResourceLib *v4; // rsi
  Scaleform::GFx::LoaderImpl *v5; // rdi
  Scaleform::List<Scaleform::GFx::LoadProcessNode,Scaleform::GFx::LoadProcessNode> *v6; // rax
  Scaleform::GFx::ResourceWeakLib *v7; // rbx
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::GFx::StateBagImpl *v9; // rax
  Scaleform::GFx::StateBagImpl *v10; // rax
  Scaleform::GFx::StateBagImpl *v11; // rbx
  Scaleform::Render::RenderBuffer *v12; // rcx
  __int64 v13; // rax
  Scaleform::Log *v14; // rbx
  __int64 v15; // rax
  Scaleform::Render::RenderBuffer *v16; // rbx
  __int64 v17; // rax
  Scaleform::Render::RenderBuffer *v18; // rbx
  __int64 v19; // rax
  Scaleform::GFx::TextKeyMap *v20; // rcx
  Scaleform::Render::RenderBuffer *v21; // rbx
  signed __int64 v22; // [rsp+A8h] [rbp+20h]

  v3 = debugHeap;
  v4 = plib;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::`vftable;
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>};
  this->pStateBag.pObject = 0i64;
  this->pWeakResourceLib.pObject = 0i64;
  v6 = &this->LoadProcesses;
  v6->Root.pPrev = (Scaleform::GFx::LoadProcessNode *)v6;
  v6->Root.pNext = (Scaleform::GFx::LoadProcessNode *)v6;
  Scaleform::Lock::Lock(&this->LoadProcessesLock, 0);
  v5->DebugHeap = v3;
  v5->HttpFilesOpened.mHash.pTable = 0i64;
  if ( v4 )
  {
    v7 = v4->pWeakLib;
    if ( v7 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v4->pWeakLib);
    v8 = (Scaleform::Render::RenderBuffer *)v5->pWeakResourceLib.pObject;
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    v5->pWeakResourceLib.pObject = v7;
  }
  v9 = (Scaleform::GFx::StateBagImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                         Scaleform::Memory::pGlobalHeap,
                                         88i64);
  if ( v9 )
  {
    Scaleform::GFx::StateBagImpl::StateBagImpl(v9, 0i64);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = (Scaleform::Render::RenderBuffer *)v5->pStateBag.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v5->pStateBag.pObject = v11;
  if ( v11 )
  {
    v13 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            16i64);
    v14 = (Scaleform::Log *)v13;
    if ( v13 )
    {
      *(_QWORD *)v13 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v13 + 8) = 1;
      *(_QWORD *)v13 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v13 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v13 = &Scaleform::RefCountBase<Scaleform::Log,2>::`vftable;
      *(_QWORD *)v13 = &Scaleform::Log::`vftable;
    }
    else
    {
      v14 = 0i64;
    }
    Scaleform::GFx::StateBag::SetLog((Scaleform::GFx::StateBag *)&v5->pStateBag.pObject->vfptr, v14);
    if ( v14 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v14);
    v15 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            32i64);
    v16 = (Scaleform::Render::RenderBuffer *)v15;
    if ( v15 )
    {
      *(_QWORD *)v15 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v15 + 8) = 1;
      *(_QWORD *)v15 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v15 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v15 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v15 = &Scaleform::GFx::State::`vftable;
      *(_DWORD *)(v15 + 16) = 14;
      *(_QWORD *)v15 = &Scaleform::GFx::ImageCreator::`vftable;
      *(_QWORD *)(v15 + 24) = 0i64;
    }
    else
    {
      v16 = 0i64;
    }
    v5->pStateBag.pObject->vfptr->SetState(
      (Scaleform::GFx::StateBag *)&v5->pStateBag.pObject->vfptr,
      State_OrigNodeBounds|State_MaskNode,
      (Scaleform::GFx::State *)v16);
    if ( v16 )
      Scaleform::RefCountImpl::Release(v16);
    v17 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            64i64);
    v18 = (Scaleform::Render::RenderBuffer *)v17;
    if ( v17 )
    {
      *(_QWORD *)v17 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v17 + 8) = 1;
      *(_QWORD *)v17 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v17 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v17 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v17 = &Scaleform::GFx::State::`vftable;
      *(_DWORD *)(v17 + 16) = 25;
      *(_QWORD *)v17 = &Scaleform::GFx::Clipboard::`vftable;
      *(_QWORD *)(v17 + 24) = 0i64;
      *(_QWORD *)(v17 + 32) = 0i64;
      *(_QWORD *)(v17 + 40) = 0i64;
      *(_QWORD *)(v17 + 48) = 0i64;
      *(_QWORD *)(v17 + 56) = 0i64;
    }
    else
    {
      v18 = 0i64;
    }
    v5->pStateBag.pObject->vfptr->SetState(
      (Scaleform::GFx::StateBag *)&v5->pStateBag.pObject->vfptr,
      State_Internal_MaskOwner|0x10,
      (Scaleform::GFx::State *)v18);
    if ( v18 )
      Scaleform::RefCountImpl::Release(v18);
    v19 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            48i64);
    v20 = (Scaleform::GFx::TextKeyMap *)v19;
    if ( v19 )
    {
      *(_QWORD *)v19 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v19 + 8) = 1;
      *(_QWORD *)v19 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v19 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v19 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v19 = &Scaleform::GFx::State::`vftable;
      *(_DWORD *)(v19 + 16) = 26;
      *(_QWORD *)v19 = &Scaleform::GFx::TextKeyMap::`vftable;
      v22 = v19 + 24;
      *(_OWORD *)v22 = 0ui64;
      *(_QWORD *)(v22 + 16) = 0i64;
    }
    else
    {
      v20 = 0i64;
    }
    v21 = (Scaleform::Render::RenderBuffer *)Scaleform::GFx::TextKeyMap::InitWindowsKeyMap(v20);
    v5->pStateBag.pObject->vfptr->SetState(
      (Scaleform::GFx::StateBag *)&v5->pStateBag.pObject->vfptr,
      State_OrigNodeBounds|0x10,
      (Scaleform::GFx::State *)v21);
    if ( v21 )
      Scaleform::RefCountImpl::Release(v21);
  }
}

// File Line: 351
// RVA: 0x89A2F0
void __fastcall Scaleform::GFx::LoaderImpl::LoaderImpl(Scaleform::GFx::LoaderImpl *this, Scaleform::GFx::StateBag *pstates, Scaleform::GFx::ResourceLib *plib, bool debugHeap)
{
  bool v4; // bl
  Scaleform::GFx::ResourceLib *v5; // r14
  Scaleform::GFx::StateBag *v6; // rbp
  Scaleform::GFx::LoaderImpl *v7; // rdi
  Scaleform::GFx::Resource *v8; // rsi
  Scaleform::List<Scaleform::GFx::LoadProcessNode,Scaleform::GFx::LoadProcessNode> *v9; // rax
  Scaleform::GFx::ResourceWeakLib *v10; // rbx
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::Render::RenderBuffer *v12; // rcx

  v4 = debugHeap;
  v5 = plib;
  v6 = pstates;
  v7 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::`vftable;
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>};
  v8 = 0i64;
  this->pStateBag.pObject = 0i64;
  this->pWeakResourceLib.pObject = 0i64;
  v9 = &this->LoadProcesses;
  v9->Root.pPrev = (Scaleform::GFx::LoadProcessNode *)v9;
  v9->Root.pNext = (Scaleform::GFx::LoadProcessNode *)v9;
  Scaleform::Lock::Lock(&this->LoadProcessesLock, 0);
  v7->DebugHeap = v4;
  v7->HttpFilesOpened.mHash.pTable = 0i64;
  if ( v5 )
  {
    v10 = v5->pWeakLib;
    if ( v10 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v5->pWeakLib);
    v11 = (Scaleform::Render::RenderBuffer *)v7->pWeakResourceLib.pObject;
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    v7->pWeakResourceLib.pObject = v10;
  }
  if ( v6 )
    v8 = (Scaleform::GFx::Resource *)&v6[-2];
  if ( v8 )
    Scaleform::Render::RenderBuffer::AddRef(v8);
  v12 = (Scaleform::Render::RenderBuffer *)v7->pStateBag.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v7->pStateBag.pObject = (Scaleform::GFx::StateBagImpl *)v8;
}

// File Line: 359
// RVA: 0x8A5C90
void __fastcall Scaleform::GFx::LoaderImpl::~LoaderImpl(Scaleform::GFx::LoaderImpl *this)
{
  Scaleform::GFx::LoaderImpl *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>};
  Scaleform::GFx::LoaderImpl::CancelLoading(this);
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v1->HttpFilesOpened.mHash.pTable);
  Scaleform::Lock::~Lock(&v1->LoadProcessesLock.cs);
  v2 = (Scaleform::Render::RenderBuffer *)v1->pWeakResourceLib.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v3 = (Scaleform::Render::RenderBuffer *)v1->pStateBag.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v1->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::`vftable;
  v1->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 515
// RVA: 0x8C1050
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::CreateMovie(Scaleform::GFx::LoaderImpl *this, const char *pfilename, unsigned int loadConstants, unsigned __int64 memoryArena)
{
  unsigned int v4; // ebp
  const char *v5; // r14
  Scaleform::GFx::LoaderImpl *v6; // rbx
  Scaleform::String::DataDesc *v7; // rax
  Scaleform::GFx::MovieDefImpl *v8; // rsi
  Scaleform::GFx::LoadStates *v9; // rax
  Scaleform::GFx::LoadStates *v10; // rdi
  Scaleform::String src; // [rsp+30h] [rbp-58h]
  Scaleform::String v13; // [rsp+38h] [rbp-50h]
  bool (__fastcall *v14)(Scaleform::GFx::Value::ObjectInterface *, void *, const char *); // [rsp+40h] [rbp-48h]
  Scaleform::GFx::LoadStates *v15; // [rsp+48h] [rbp-40h]
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+50h] [rbp-38h]

  v14 = (bool (__fastcall *)(Scaleform::GFx::Value::ObjectInterface *, void *, const char *))-2i64;
  v4 = loadConstants;
  v5 = pfilename;
  v6 = this;
  v7 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                        Scaleform::Memory::pGlobalHeap,
                                        144ui64,
                                        0i64);
  v13.pData = v7;
  v8 = 0i64;
  if ( v7 )
  {
    Scaleform::GFx::LoadStates::LoadStates((Scaleform::GFx::LoadStates *)v7, v6, 0i64, 0i64);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v15 = v10;
  if ( v4 & 0x40 )
    v10->ThreadedLoading = 1;
  if ( v10->pWeakResourceLib.pObject )
  {
    Scaleform::String::String(&v13, &customWorldMapCaption);
    Scaleform::String::String(&src, v5);
    loc.Use = 0;
    Scaleform::String::String(&loc.FileName, &src);
    Scaleform::String::String(&loc.ParentPath, &v13);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v13.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v8 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v10, &loc, v4, 0i64);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
  return v8;
}

// File Line: 539
// RVA: 0x8FE590
void __fastcall Scaleform::GFx::LoaderImpl::RegisterLoadProcess(Scaleform::GFx::LoaderImpl *this, Scaleform::GFx::LoaderTask *ptask)
{
  Scaleform::GFx::LoaderTask *v2; // rsi
  Scaleform::GFx::LoaderImpl *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx
  __int64 v5; // rax
  Scaleform::GFx::LoadProcessNode *v6; // rdx

  v2 = ptask;
  v3 = this;
  v4 = &this->LoadProcessesLock.cs;
  EnterCriticalSection(&this->LoadProcessesLock.cs);
  v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
         Scaleform::Memory::pGlobalHeap,
         24i64);
  v6 = (Scaleform::GFx::LoadProcessNode *)v5;
  if ( v5 )
    *(_QWORD *)(v5 + 16) = v2;
  else
    v6 = 0i64;
  v6->pPrev = v3->LoadProcesses.Root.pPrev;
  v6->pNext = (Scaleform::GFx::LoadProcessNode *)&v3->LoadProcesses;
  v3->LoadProcesses.Root.pPrev->pNext = v6;
  v3->LoadProcesses.Root.pPrev = v6;
  LeaveCriticalSection(v4);
}

// File Line: 547
// RVA: 0x914AD0
void __fastcall Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(Scaleform::GFx::LoaderImpl *this, Scaleform::GFx::LoaderTask *ptask)
{
  Scaleform::GFx::LoaderTask *v2; // rsi
  Scaleform::GFx::LoaderImpl *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::GFx::LoadProcessNode *v5; // rdx
  signed __int64 v6; // rdi

  v2 = ptask;
  v3 = this;
  v4 = &this->LoadProcessesLock.cs;
  EnterCriticalSection(&this->LoadProcessesLock.cs);
  v5 = v3->LoadProcesses.Root.pNext;
  v6 = (signed __int64)&v3->LoadProcesses;
  if ( v5 != (Scaleform::GFx::LoadProcessNode *)v6 )
  {
    while ( v5->pTask != v2 )
    {
      v5 = v5->pNext;
      if ( v5 == (Scaleform::GFx::LoadProcessNode *)v6 )
        goto LABEL_6;
    }
    v5->pPrev->pNext = v5->pNext;
    v5->pNext->pPrev = v5->pPrev;
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
LABEL_6:
  LeaveCriticalSection(v4);
}

// File Line: 564
// RVA: 0x8B9750
void __fastcall Scaleform::GFx::LoaderImpl::CancelLoading(Scaleform::GFx::LoaderImpl *this)
{
  Scaleform::GFx::LoaderImpl *v1; // rsi
  Scaleform::GFx::LoadProcessNode *i; // rdi
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+50h] [rbp+8h]
  Scaleform::Lock *v4; // [rsp+58h] [rbp+10h]

  v1 = this;
  Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&this->pStateBag.pObject->vfptr, &result);
  if ( result.pObject )
  {
    v4 = &v1->LoadProcessesLock;
    EnterCriticalSection(&v1->LoadProcessesLock.cs);
    for ( i = v1->LoadProcesses.Root.pNext;
          i != (Scaleform::GFx::LoadProcessNode *)&v1->LoadProcesses;
          i = v1->LoadProcesses.Root.pNext )
    {
      i->pPrev->pNext = i->pNext;
      i->pNext->pPrev = i->pPrev;
      result.pObject->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)result.pObject, (unsigned int)i->pTask);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, i);
    }
    LeaveCriticalSection(&v1->LoadProcessesLock.cs);
  }
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 607
// RVA: 0x89B320
void __fastcall Scaleform::GFx::MovieImageLoadTask::MovieImageLoadTask(Scaleform::GFx::MovieImageLoadTask *this, Scaleform::GFx::MovieDataDef *pdef, Scaleform::GFx::MovieDefImpl *pdefImpl, Scaleform::File *pin, Scaleform::GFx::FileTypeConstants::FileFormatType format, Scaleform::GFx::LoadStates *pls)
{
  Scaleform::File *v6; // rsi
  Scaleform::GFx::MovieDefImpl *v7; // rdi
  Scaleform::GFx::MovieDataDef *v8; // rbp
  Scaleform::GFx::MovieImageLoadTask *v9; // rbx

  v6 = pin;
  v7 = pdefImpl;
  v8 = pdef;
  v9 = this;
  Scaleform::GFx::LoaderTask::LoaderTask((Scaleform::GFx::LoaderTask *)&this->vfptr, pls, Id_MovieImageLoad);
  v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieImageLoadTask::`vftable;
  if ( v8 )
    _InterlockedExchangeAdd(&v8->RefCount.Value, 1u);
  v9->pDef.pObject = v8;
  if ( v7 )
    _InterlockedExchangeAdd(&v7->RefCount.Value, 1u);
  v9->pDefImpl.pObject = v7;
  if ( v6 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v6);
  v9->pImageFile.pObject = v6;
  v9->ImageFormat = format;
  v9->pImageRes.pObject = 0i64;
}

// File Line: 610
// RVA: 0x8C9B70
void __fastcall Scaleform::GFx::MovieImageLoadTask::Execute(Scaleform::GFx::MovieImageLoadTask *this)
{
  Scaleform::GFx::MovieImageLoadTask *v1; // r14
  Scaleform::GFx::LoadStates *v2; // rdx
  Scaleform::MemoryHeap *pimageHeap; // rdi
  Scaleform::GFx::LogState *v4; // rax
  Scaleform::Log *plog; // rax
  Scaleform::Render::ImageSource *v6; // r15
  Scaleform::GFx::ImageResource *v7; // rax
  Scaleform::GFx::ImageResource *v8; // rax
  Scaleform::GFx::ImageResource *v9; // rsi
  Scaleform::GFx::ImageResource *v10; // rdi
  Scaleform::GFx::ResourceLibBase *v11; // rcx
  Scaleform::File *v12; // r13
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *v13; // rsi
  Scaleform::GFx::LogState *v14; // r12
  Scaleform::Log *v15; // r12
  Scaleform::GFx::ImageCreator *v16; // rsi
  Scaleform::GFx::ImageResource *v17; // rbp
  Scaleform::GFx::MovieDataDef *v18; // rdi
  unsigned int v19; // eax
  bool v20; // di
  Scaleform::GFx::MovieDataDef *v21; // rcx
  unsigned int v22; // ebx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v23; // rdi
  volatile unsigned int v24; // eax
  unsigned int v25; // edx
  Scaleform::GFx::ImageResource *v26; // rdi
  Scaleform::GFx::ResourceLibBase *v27; // rcx
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> result; // [rsp+88h] [rbp+10h]
  Scaleform::GFx::ImageResource *v29; // [rsp+90h] [rbp+18h]

  v1 = this;
  v2 = this->pLoadStates.pObject;
  pimageHeap = v2->pWeakResourceLib.pObject->pImageHeap.pObject;
  result.pObject = (Scaleform::GFx::ImageCreator *)v2->pWeakResourceLib.pObject->pImageHeap.pObject;
  v4 = v2->pLog.pObject;
  if ( v4 )
  {
    plog = v4->pLog.pObject;
    if ( !plog )
      plog = Scaleform::Log::GetGlobalLog();
  }
  else
  {
    plog = 0i64;
  }
  v6 = Scaleform::GFx::LoaderImpl::LoadBuiltinImage(
         v1->pImageFile.pObject,
         v1->ImageFormat,
         Use_Bitmap,
         v1->pLoadStates.pObject,
         plog,
         pimageHeap);
  if ( v6 )
  {
    v7 = (Scaleform::GFx::ImageResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))pimageHeap->vfptr->Alloc)(
                                            pimageHeap,
                                            104i64);
    v29 = v7;
    if ( v7 )
    {
      Scaleform::GFx::ImageResource::ImageResource(v7, v6, Use_Bitmap);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    v10 = v1->pImageRes.pObject;
    if ( v10 && !_InterlockedDecrement(&v10->RefCount.Value) )
    {
      v11 = v10->pLib;
      if ( v11 )
      {
        v11->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, (unsigned int)v10);
        v10->pLib = 0i64;
      }
      v10->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v10->vfptr, 1u);
    }
    v1->pImageRes.pObject = v9;
  }
  if ( !v1->pImageRes.pObject )
  {
    v25 = 4;
    goto LABEL_31;
  }
  v12 = v1->pImageFile.pObject;
  v13 = Scaleform::GFx::StateBag::GetImageCreator((Scaleform::GFx::StateBag *)&v1->pDefImpl.pObject->vfptr, &result);
  v14 = v1->pLoadStates.pObject->pLog.pObject;
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
  v16 = v13->pObject;
  v17 = v1->pImageRes.pObject;
  v18 = v1->pDef.pObject;
  v19 = ((__int64 (__fastcall *)(Scaleform::File *))v12->vfptr[6].__vecDelDtor)(v12);
  v20 = Scaleform::GFx::MovieDataDef::LoadTaskData::InitImageFileMovieDef(v18->pData.pObject, v19, v17, v16, v15, 1);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( v20 )
  {
    v21 = v1->pDef.pObject;
    v22 = v21->pData.pObject->Header.FileLength;
    v23 = v1->pDefImpl.pObject->pBindData.pObject;
    v24 = ((__int64 (*)(void))v21->vfptr[4].__vecDelDtor)();
    v23->BytesLoaded = v22;
    v23->BindingFrame = v24;
    v25 = 770;
LABEL_31:
    Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v1->pDefImpl.pObject->pBindData.pObject, v25);
    goto LABEL_32;
  }
  Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v1->pDefImpl.pObject->pBindData.pObject, 4u);
  v26 = v1->pImageRes.pObject;
  if ( v26 && !_InterlockedDecrement(&v26->RefCount.Value) )
  {
    v27 = v26->pLib;
    if ( v27 )
    {
      v27->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v27->vfptr, (unsigned int)v26);
      v26->pLib = 0i64;
    }
    v26->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v26->vfptr, 1u);
  }
  v1->pImageRes.pObject = 0i64;
LABEL_32:
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::ImageSource *))v6->vfptr[2].__vecDelDtor)(v6);
}

// File Line: 683
// RVA: 0x8C15B0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(Scaleform::GFx::LoadStates *pls, Scaleform::GFx::URLBuilder::LocationInfo *loc, unsigned int loadConstants, Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack)
{
  unsigned int v4; // er13
  Scaleform::GFx::URLBuilder::LocationInfo *v5; // rdi
  Scaleform::GFx::LoadStates *v6; // rbx
  Scaleform::GFx::URLBuilder *v7; // rcx
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v8; // r12
  Scaleform::GFx::MovieBindProcess *v9; // rsi
  Scaleform::Render::RenderBuffer *v10; // rdi
  Scaleform::Render::RenderBuffer *v11; // r14
  Scaleform::GFx::MovieDefBindStates *v12; // rax
  unsigned int v13; // ecx
  Scaleform::GFx::FileOpener *v14; // r15
  __int64 v15; // rax
  Scaleform::Render::RenderBuffer *v16; // rax
  Scaleform::String::DataDesc *v17; // rdx
  Scaleform::GFx::MovieDataDef::MovieDataType v18; // er12
  unsigned __int64 v19; // rbx
  Scaleform::GFx::MovieDataDef *v20; // rax
  Scaleform::GFx::MovieDataDef *v21; // rbx
  Scaleform::GFx::LoadStates *v22; // r12
  Scaleform::GFx::LoadProcess *v23; // rax
  Scaleform::Render::RenderBuffer **v24; // r9
  Scaleform::GFx::ResourceLibBase *v25; // rcx
  char v26; // al
  Scaleform::String::DataDesc *v27; // rdx
  Scaleform::GFx::MovieDefImpl *v28; // r12
  Scaleform::GFx::Resource *v29; // rax
  char *v30; // r8
  Scaleform::Render::RenderBuffer **v31; // r9
  Scaleform::String::DataDesc *v32; // rax
  Scaleform::String::DataDesc *v33; // rax
  Scaleform::GFx::TaskManager *v34; // rcx
  Scaleform::GFx::MovieImageLoadTask *v35; // rax
  Scaleform::GFx::MovieImageLoadTask *v36; // r12
  unsigned __int64 v37; // rcx
  Scaleform::GFx::ImageCreator *v38; // rbx
  __int64 v39; // rcx
  Scaleform::GFx::Resource *v40; // rbx
  Scaleform::GFx::ResourceLibBase *v41; // rcx
  Scaleform::String ppath; // [rsp+8h] [rbp-61h]
  Scaleform::String v44; // [rsp+10h] [rbp-59h]
  Scaleform::Render::RenderBuffer *v45; // [rsp+18h] [rbp-51h]
  Scaleform::GFx::ImageCreator *pimageCreator; // [rsp+20h] [rbp-49h]
  Scaleform::GFx::ImageCreator *v47; // [rsp+28h] [rbp-41h]
  Scaleform::Render::RenderBuffer *v48; // [rsp+30h] [rbp-39h]
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [rsp+38h] [rbp-31h]
  Scaleform::Render::RenderBuffer *v50; // [rsp+48h] [rbp-21h]
  Scaleform::String v51; // [rsp+50h] [rbp-19h]
  Scaleform::String v52; // [rsp+58h] [rbp-11h]
  void *v53; // [rsp+60h] [rbp-9h]
  Scaleform::GFx::ResourceKey result; // [rsp+68h] [rbp-1h]
  __int64 v55; // [rsp+78h] [rbp+Fh]
  Scaleform::MemoryHeap *v56; // [rsp+80h] [rbp+17h]
  Scaleform::String v57; // [rsp+C8h] [rbp+5Fh]
  char v58; // [rsp+D8h] [rbp+6Fh]
  Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStacka; // [rsp+E0h] [rbp+77h]
  unsigned __int64 v60; // [rsp+E8h] [rbp+7Fh]

  v55 = -2i64;
  v4 = loadConstants;
  v5 = loc;
  v6 = pls;
  Scaleform::String::String((Scaleform::String *)&phandle.8);
  v7 = v6->pBindStates.pObject->pURLBulider.pObject;
  if ( v7 )
    ((void (__fastcall *)(Scaleform::GFx::URLBuilder *, Scaleform::String *, Scaleform::GFx::URLBuilder::LocationInfo *))v7->vfptr[1].__vecDelDtor)(
      v7,
      &ppath,
      v5);
  else
    Scaleform::GFx::URLBuilder::DefaultBuildURL(&ppath, v5);
  phandle.State = 0;
  phandle.pResource = 0i64;
  pimageCreator = 0i64;
  v44.pData = 0i64;
  v8 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v6->pLog.pObject;
  v58 = 0;
  v9 = 0i64;
  v45 = 0i64;
  v10 = 0i64;
  v48 = 0i64;
  v11 = 0i64;
  v50 = 0i64;
  LODWORD(v51.pData) = 0;
  v12 = v6->pBindStates.pObject;
  if ( v12->pImagePackParams.pObject )
    v4 |= 0x11u;
  v13 = v4 >> 4;
  LOBYTE(v13) = ~(unsigned __int8)(v4 >> 4) & 1;
  LODWORD(v52.pData) = v13;
  v47 = 0i64;
  if ( (v4 & 0x80u) == 0 && v12->pImageCreator.pObject )
    v47 = v12->pImageCreator.pObject;
  v14 = v12->pFileOpener.pObject;
  if ( v14 )
    v15 = (__int64)v14->vfptr[2].__vecDelDtor(
                     (Scaleform::RefCountImplCore *)&v14->vfptr,
                     (ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  else
    v15 = 0i64;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(
    &result,
    (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    v15,
    v14,
    v47);
  if ( (unsigned int)Scaleform::GFx::ResourceWeakLib::BindResourceKey(v6->pWeakResourceLib.pObject, &phandle, &result) != 3 )
  {
    v29 = Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&phandle);
    v21 = (Scaleform::GFx::MovieDataDef *)v29;
    pimageCreator = (Scaleform::GFx::ImageCreator *)v29;
    if ( v29 )
    {
      LODWORD(v47) = v29[2].RefCount.Value;
      v22 = (Scaleform::GFx::LoadStates *)v57.pData;
      Scaleform::String::operator=(
        (Scaleform::String *)&v57.pData[6].RefCount,
        (const char *)((*(_QWORD *)&v29[2].pLib[4].RefCount & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( !Scaleform::GFx::URLBuilder::ExtractFilePath(&v22->RelativePath) )
        Scaleform::String::Clear(&v22->RelativePath);
LABEL_62:
      v31 = &v45;
      if ( (_DWORD)v47 != 1 )
        v31 = 0i64;
      v32 = (Scaleform::String::DataDesc *)Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
                                             v22,
                                             v21,
                                             v4,
                                             (Scaleform::GFx::MovieBindProcess **)v31,
                                             0,
                                             ploadStacka,
                                             v60);
      v27 = v32;
      v44.pData = v32;
      v9 = (Scaleform::GFx::MovieBindProcess *)v45;
      v26 = v58;
LABEL_65:
      if ( v27 )
      {
        if ( !v26 )
        {
LABEL_100:
          v28 = Scaleform::GFx::LoaderImpl::BindMovieAndWait(
                  (Scaleform::GFx::MovieDefImpl *)v44.pData,
                  v9,
                  v22,
                  v4,
                  ploadStacka);
          goto LABEL_101;
        }
        goto LABEL_68;
      }
    }
    else if ( v8 )
    {
      if ( phandle.State < 2 )
        v30 = &customWorldMapCaption;
      else
        v30 = (char *)((*(_QWORD *)&phandle.pResource[2].RefCount.Value & 0xFFFFFFFFFFFFFFFCui64) + 12);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(v8 + 3, "%s", v30);
    }
LABEL_66:
    v28 = 0i64;
    goto LABEL_101;
  }
  if ( Scaleform::GFx::URLBuilder::IsProtocol(&ppath)
    || (v16 = (Scaleform::Render::RenderBuffer *)Scaleform::GFx::LoadStates::OpenFile(
                                                   v6,
                                                   (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                                                   v4),
        v11 = v16,
        (v50 = v16) == 0i64) )
  {
    Scaleform::String::String(
      &v52,
      "Loader failed to open \"",
      (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
      "\"\n");
    Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
      phandle.pSlot,
      (const char *)((v52.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    v17 = v52.pData;
LABEL_50:
    if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v17 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v28 = 0i64;
    v21 = (Scaleform::GFx::MovieDataDef *)pimageCreator;
    v9 = (Scaleform::GFx::MovieBindProcess *)v45;
    v10 = v48;
    v11 = v50;
    goto LABEL_101;
  }
  LODWORD(v51.pData) = Scaleform::GFx::LoaderImpl::DetectFileFormat((Scaleform::File *)v16);
  switch ( LODWORD(v51.pData) )
  {
    case 2:
      if ( !_bittest((const signed int *)&v4, 0x13u) )
        goto $LN34_19;
      Scaleform::String::String(
        &v57,
        "Failed loading SWF file \"",
        (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        "\" - GFX file format expected");
      if ( v8 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          v8 + 3,
          "%s",
          (v57.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        phandle.pSlot,
        (const char *)((v57.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      v17 = v57.pData;
      goto LABEL_50;
    case 3:
$LN34_19:
      v18 = 1;
      goto LABEL_23;
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x1B:
      if ( !_bittest((const signed int *)&v4, 0x10u) )
        goto LABEL_47;
      v18 = 2;
LABEL_23:
      LODWORD(v47) = v18;
      v19 = ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      v56 = Scaleform::Memory::pGlobalHeap;
      v20 = (Scaleform::GFx::MovieDataDef *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              72i64);
      v53 = v20;
      if ( v20 )
        Scaleform::GFx::MovieDataDef::MovieDataDef(
          v20,
          &result,
          v18,
          (const char *)(v19 + 12),
          0i64,
          (v4 >> 28) & 1,
          v60);
      v21 = v20;
      pimageCreator = (Scaleform::GFx::ImageCreator *)v20;
      if ( !v20 )
        goto LABEL_44;
      v22 = (Scaleform::GFx::LoadStates *)v57.pData;
      Scaleform::GFx::LoadStates::SetRelativePathForDataDef((Scaleform::GFx::LoadStates *)v57.pData, v20);
      if ( (_DWORD)v47 != 1 )
      {
        v24 = 0i64;
        goto LABEL_40;
      }
      v23 = (Scaleform::GFx::LoadProcess *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             1056ui64,
                                             0i64);
      v53 = v23;
      if ( v23 )
        Scaleform::GFx::LoadProcess::LoadProcess(v23, v21, v22, v4);
      v10 = (Scaleform::Render::RenderBuffer *)v23;
      v48 = (Scaleform::Render::RenderBuffer *)v23;
      if ( !v23 )
      {
LABEL_34:
        v48 = 0i64;
        if ( !_InterlockedDecrement(&v21->RefCount.Value) )
        {
          v25 = v21->pLib;
          if ( v25 )
          {
            v25->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v25->vfptr, (unsigned int)v21);
            v21->pLib = 0i64;
          }
          v21->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v21->vfptr, 1u);
        }
        pimageCreator = 0i64;
LABEL_44:
        Scaleform::String::String(
          &v51,
          "Failed to load SWF file \"",
          (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          "\"\n");
        Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
          phandle.pSlot,
          (const char *)((v51.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v51.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v21 = (Scaleform::GFx::MovieDataDef *)pimageCreator;
        v9 = (Scaleform::GFx::MovieBindProcess *)v45;
        v10 = v48;
        v11 = v50;
        goto LABEL_66;
      }
      if ( !Scaleform::GFx::LoadProcess::BeginSWFLoading(v23, (Scaleform::File *)v11) )
      {
        Scaleform::RefCountImpl::Release(v10);
        goto LABEL_34;
      }
      if ( LOBYTE(v52.pData) )
      {
        v24 = &v45;
LABEL_40:
        v44.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
                                                     v22,
                                                     v21,
                                                     v4,
                                                     (Scaleform::GFx::MovieBindProcess **)v24,
                                                     1,
                                                     ploadStacka,
                                                     v60);
        v9 = (Scaleform::GFx::MovieBindProcess *)v45;
      }
      Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, (Scaleform::GFx::Resource *)&v21->vfptr);
      v26 = 1;
      v58 = 1;
      v27 = v44.pData;
      if ( LOBYTE(v52.pData) )
        goto LABEL_65;
      if ( !v44.pData )
        goto LABEL_62;
      break;
    default:
LABEL_47:
      Scaleform::String::String(
        &v44,
        "Unknown file format at URL \"",
        (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        "\"");
      if ( v8 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          v8 + 3,
          "%s",
          (v44.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        phandle.pSlot,
        (const char *)((v44.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      v17 = v44.pData;
      goto LABEL_50;
  }
LABEL_68:
  if ( (_DWORD)v47 == 1 )
  {
    v33 = (Scaleform::String::DataDesc *)v9;
    if ( v4 & 0x10 )
      v33 = 0i64;
    v57.pData = v33;
    if ( v33 )
      Scaleform::GFx::LoadProcess::SetBindProcess(
        (Scaleform::GFx::LoadProcess *)v10,
        (Scaleform::GFx::MovieBindProcess *)v33);
    if ( v9 )
      *(_QWORD *)&v10[18].Type = v9->pTempBindData;
    if ( v4 & 1
      || (v34 = v22->pTaskManager.pObject) == 0i64
      || !(unsigned __int8)v34->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v34->vfptr, (unsigned int)v10) )
    {
      v10->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, (unsigned int)v27);
    }
    if ( v57.pData )
    {
      if ( v9 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
      v9 = 0i64;
      v45 = 0i64;
    }
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    v10 = 0i64;
    v48 = 0i64;
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    v11 = 0i64;
    v50 = 0i64;
    goto LABEL_100;
  }
  v35 = (Scaleform::GFx::MovieImageLoadTask *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                Scaleform::Memory::pGlobalHeap,
                                                72i64);
  v53 = v35;
  if ( v35 )
    Scaleform::GFx::MovieImageLoadTask::MovieImageLoadTask(
      v35,
      v21,
      (Scaleform::GFx::MovieDefImpl *)v44.pData,
      (Scaleform::File *)v11,
      (Scaleform::GFx::FileTypeConstants::FileFormatType)v51.pData,
      v22);
  v36 = v35;
  v53 = v35;
  if ( !(v4 & 0x11)
    && (v37 = v57.pData[3].Size) != 0
    && (*(unsigned __int8 (__fastcall **)(unsigned __int64, Scaleform::GFx::MovieImageLoadTask *))(*(_QWORD *)v37 + 8i64))(
         v37,
         v35)
    || (((void (__fastcall *)(Scaleform::GFx::MovieImageLoadTask *))v36->vfptr[1].__vecDelDtor)(v36),
        v36->pImageRes.pObject) )
  {
    if ( v36 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v36);
    v22 = (Scaleform::GFx::LoadStates *)v57.pData;
    goto LABEL_100;
  }
  if ( v44.pData )
    Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v44.pData);
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v36);
  v28 = 0i64;
LABEL_101:
  if ( result.pKeyInterface )
    result.pKeyInterface->vfptr->Release(result.pKeyInterface, result.hKeyData);
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
  if ( v21 && !_InterlockedDecrement(&v21->RefCount.Value) )
  {
    v38 = pimageCreator;
    v39 = *(_QWORD *)&pimageCreator->SType;
    if ( v39 )
    {
      (*(void (__fastcall **)(__int64, Scaleform::GFx::ImageCreator *))(*(_QWORD *)v39 + 8i64))(v39, pimageCreator);
      *(_QWORD *)&v38->SType = 0i64;
    }
    v38->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v38->vfptr, 1u);
  }
  if ( phandle.State == 1 )
  {
    if ( !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
    {
      v40 = phandle.pResource;
      v41 = phandle.pResource->pLib;
      if ( v41 )
      {
        v41->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v41->vfptr, (unsigned int)phandle.pResource);
        v40->pLib = 0i64;
      }
      v40->vfptr->__vecDelDtor(v40, 1u);
    }
  }
  else if ( phandle.State >= 2 )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)phandle.pResource);
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return v28;
}

// File Line: 994
// RVA: 0x8C1E10
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(Scaleform::GFx::LoadStates *pls, Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *bytes, unsigned int loadConstants, Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack)
{
  unsigned int v4; // er14
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v5; // rsi
  Scaleform::GFx::LoadStates *v6; // r13
  __int64 v7; // r15
  Scaleform::Render::RenderBuffer *v8; // r12
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v9; // rdi
  Scaleform::Render::RenderBuffer *v10; // rbx
  Scaleform::MemoryFile *v11; // rax
  Scaleform::Render::RenderBuffer *v12; // rax
  unsigned __int64 v13; // rdx
  Scaleform::GFx::MovieDataDef::MovieDataType v14; // er15
  Scaleform::GFx::MovieDataDef *v15; // rax
  Scaleform::GFx::MovieDataDef *v16; // rax
  Scaleform::GFx::MovieDataDef *v17; // rdi
  Scaleform::String *v18; // r13
  Scaleform::GFx::LoadProcess *v19; // rax
  Scaleform::GFx::LoadStates *v20; // r13
  Scaleform::Render::RenderBuffer *v21; // rax
  Scaleform::Render::RenderBuffer **v22; // r9
  Scaleform::GFx::ResourceLibBase *v23; // rcx
  Scaleform::Render::RenderBuffer *v24; // rdi
  Scaleform::Render::RenderBuffer *v25; // r15
  Scaleform::GFx::TaskManager *v26; // rcx
  Scaleform::GFx::MovieImageLoadTask *v27; // rax
  Scaleform::String::DataDesc *v28; // r15
  Scaleform::GFx::MovieImageLoadTask *v29; // rdi
  Scaleform::GFx::TaskManager *v30; // rcx
  Scaleform::GFx::MovieDefImpl *v31; // r14
  __int64 v32; // rbx
  Scaleform::GFx::ResourceLibBase *v33; // rcx
  Scaleform::GFx::ResourceLib::ResourceSlot *v34; // rbx
  Scaleform::GFx::ResourceWeakLib *v35; // rcx
  Scaleform::Render::RenderBuffer *v37; // [rsp+40h] [rbp-88h]
  Scaleform::Render::RenderBuffer *v38; // [rsp+48h] [rbp-80h]
  Scaleform::GFx::ResourceKey result; // [rsp+50h] [rbp-78h]
  Scaleform::GFx::ResourceLib::ResourceSlot *v40; // [rsp+60h] [rbp-68h]
  char dest[8]; // [rsp+68h] [rbp-60h]
  Scaleform::GFx::MovieDataDef *v42; // [rsp+70h] [rbp-58h]
  void *v43; // [rsp+78h] [rbp-50h]
  Scaleform::String v44; // [rsp+128h] [rbp+60h]
  Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStacka; // [rsp+140h] [rbp+78h]
  unsigned __int64 v46; // [rsp+148h] [rbp+80h]

  v4 = loadConstants;
  v5 = bytes;
  v6 = pls;
  v7 = Scaleform::Timer::GetProfileTicks();
  Scaleform::SFsprintf(dest, 0x80ui64, "*Bytes@%p*", v7);
  v8 = 0i64;
  LODWORD(result.hKeyData) = 0;
  v40 = 0i64;
  v42 = 0i64;
  v9 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v6->pLog.pObject;
  v37 = 0i64;
  v10 = 0i64;
  v38 = 0i64;
  if ( v6->pBindStates.pObject->pImagePackParams.pObject )
    v4 |= 0x11u;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(&result, dest, v7, 0i64, 0i64);
  Scaleform::GFx::ResourceWeakLib::BindResourceKey(
    v6->pWeakResourceLib.pObject,
    (Scaleform::GFx::ResourceLib::BindHandle *)&result.hKeyData,
    &result);
  v11 = (Scaleform::MemoryFile *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                   Scaleform::Memory::pGlobalHeap,
                                   48i64);
  *(_QWORD *)dest = v11;
  if ( v11 )
  {
    Scaleform::MemoryFile::MemoryFile(v11, dest, v5->Data.Data, v5->Data.Size);
    v8 = v12;
  }
  v38 = v8;
  LODWORD(result.pKeyInterface) = Scaleform::GFx::LoaderImpl::DetectFileFormat((Scaleform::File *)v8);
  switch ( 0x40000000 )
  {
    case 2:
      if ( !_bittest((const signed int *)&v4, 0x13u) )
        goto $LN25_40;
      Scaleform::String::String(&v44, "Failed loading SWF file \"", dest, "\" - GFX file format expected");
      if ( v9 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          v9 + 3,
          "%s",
          (v44.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        v40,
        (const char *)((v44.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      v13 = v44.HeapTypeBits;
      goto LABEL_69;
    case 3:
$LN25_40:
      v14 = 1;
      goto LABEL_13;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 21:
    case 22:
    case 23:
    case 24:
      if ( !_bittest((const signed int *)&v4, 0x10u) )
        goto LABEL_66;
      v14 = 2;
LABEL_13:
      *(_QWORD *)dest = Scaleform::Memory::pGlobalHeap;
      v15 = (Scaleform::GFx::MovieDataDef *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              72i64);
      v43 = v15;
      if ( v15 )
      {
        Scaleform::GFx::MovieDataDef::MovieDataDef(v15, &result, v14, dest, 0i64, (v4 >> 28) & 1, v46);
        v17 = v16;
      }
      else
      {
        v17 = 0i64;
      }
      v42 = v17;
      if ( !v17 )
        goto LABEL_65;
      v18 = &v6->RelativePath;
      Scaleform::String::operator=(
        v18,
        (const char *)((v17->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( !Scaleform::GFx::URLBuilder::ExtractFilePath(v18) )
        Scaleform::String::Clear(v18);
      if ( v14 == 1 )
      {
        v19 = (Scaleform::GFx::LoadProcess *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               1056ui64,
                                               0i64);
        v43 = v19;
        v20 = (Scaleform::GFx::LoadStates *)v44.pData;
        if ( v19 )
        {
          Scaleform::GFx::LoadProcess::LoadProcess(v19, v17, (Scaleform::GFx::LoadStates *)v44.pData, v4);
          v10 = v21;
        }
        else
        {
          v10 = 0i64;
        }
        v38 = v10;
        if ( !v10 )
          goto LABEL_27;
        if ( !Scaleform::GFx::LoadProcess::BeginSWFLoading((Scaleform::GFx::LoadProcess *)v10, (Scaleform::File *)v8) )
        {
          Scaleform::RefCountImpl::Release(v10);
LABEL_27:
          v38 = 0i64;
          if ( !_InterlockedDecrement(&v17->RefCount.Value) )
          {
            v23 = v17->pLib;
            if ( v23 )
            {
              v23->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v23->vfptr, (unsigned int)v17);
              v17->pLib = 0i64;
            }
            v17->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v17->vfptr, 1u);
          }
          v42 = 0i64;
LABEL_65:
          Scaleform::String::String((Scaleform::String *)dest, "Failed to load SWF file \"", dest, "\"\n");
          Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
            v40,
            (const char *)((*(_QWORD *)dest & 0xFFFFFFFFFFFFFFFCui64) + 12));
          v13 = *(_QWORD *)dest;
LABEL_69:
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v13 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v10 = v38;
          goto LABEL_72;
        }
        v22 = &v37;
      }
      else
      {
        v22 = 0i64;
        v20 = (Scaleform::GFx::LoadStates *)v44.pData;
      }
      v44.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
                                                   v20,
                                                   v17,
                                                   v4,
                                                   (Scaleform::GFx::MovieBindProcess **)v22,
                                                   1,
                                                   ploadStacka,
                                                   v46);
      Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(v40, (Scaleform::GFx::Resource *)&v17->vfptr);
      if ( !v44.pData )
        goto LABEL_72;
      if ( v14 == 1 )
      {
        v24 = v37;
        v25 = v37;
        if ( v4 & 0x10 )
          v25 = 0i64;
        if ( v25 )
          Scaleform::GFx::LoadProcess::SetBindProcess(
            (Scaleform::GFx::LoadProcess *)v10,
            (Scaleform::GFx::MovieBindProcess *)v25);
        if ( v24 )
          *(Scaleform::Render::Size<unsigned long> *)&v10[18].Type = v24[1].BufferSize;
        if ( v4 & 1
          || (v26 = v20->pTaskManager.pObject) == 0i64
          || !(unsigned __int8)v26->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v26->vfptr, (unsigned int)v10) )
        {
          ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))v10->vfptr[1].__vecDelDtor)(v10);
        }
        if ( v25 )
        {
          if ( v24 )
            Scaleform::RefCountImpl::Release(v24);
          v25 = 0i64;
          v24 = 0i64;
          v37 = 0i64;
        }
        if ( v10 )
          Scaleform::RefCountImpl::Release(v10);
        v10 = v25;
        v38 = v25;
        if ( v8 )
          Scaleform::RefCountImpl::Release(v8);
        v38 = v25;
LABEL_64:
        v31 = Scaleform::GFx::LoaderImpl::BindMovieAndWait(
                (Scaleform::GFx::MovieDefImpl *)v44.pData,
                (Scaleform::GFx::MovieBindProcess *)v24,
                v20,
                v4,
                ploadStacka);
        goto LABEL_73;
      }
      v27 = (Scaleform::GFx::MovieImageLoadTask *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    72i64);
      v43 = v27;
      v28 = v44.pData;
      if ( v27 )
        Scaleform::GFx::MovieImageLoadTask::MovieImageLoadTask(
          v27,
          v17,
          (Scaleform::GFx::MovieDefImpl *)v44.pData,
          (Scaleform::File *)v8,
          (Scaleform::GFx::FileTypeConstants::FileFormatType)result.pKeyInterface,
          v20);
      v29 = v27;
      v43 = v27;
      if ( !(v4 & 0x11)
        && (v30 = v20->pTaskManager.pObject) != 0i64
        && (unsigned __int8)v30->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v30->vfptr, (unsigned int)v27)
        || (((void (__fastcall *)(Scaleform::GFx::MovieImageLoadTask *))v29->vfptr[1].__vecDelDtor)(v29),
            v29->pImageRes.pObject) )
      {
        if ( v29 )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v29);
        v24 = v37;
        goto LABEL_64;
      }
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v28);
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v29);
LABEL_72:
      v31 = 0i64;
      v24 = v37;
LABEL_73:
      if ( result.pKeyInterface )
        result.pKeyInterface->vfptr->Release(result.pKeyInterface, result.hKeyData);
      if ( v38 )
        Scaleform::RefCountImpl::Release(v38);
      if ( v10 )
        Scaleform::RefCountImpl::Release(v10);
      if ( v24 )
        Scaleform::RefCountImpl::Release(v24);
      if ( v42 && !_InterlockedDecrement(&v42->RefCount.Value) )
      {
        v32 = (__int64)v42;
        v33 = v42->pLib;
        if ( v33 )
        {
          v33->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v33->vfptr, (unsigned int)v42);
          *(_QWORD *)(v32 + 16) = 0i64;
        }
        (**(void (__fastcall ***)(__int64, signed __int64))v32)(v32, 1i64);
      }
      if ( LODWORD(result.hKeyData) == 1 )
      {
        if ( !_InterlockedDecrement(&v40->RefCount) )
        {
          v34 = v40;
          v35 = v40->pLib.pObject;
          if ( v35 )
          {
            v35->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v35->vfptr, (unsigned int)v40);
            v34->pLib.pObject = 0i64;
          }
          v34->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v34->vfptr, 1u);
        }
      }
      else if ( SLODWORD(result.hKeyData) >= 2 )
      {
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v40);
      }
      return v31;
    default:
LABEL_66:
      Scaleform::String::String((Scaleform::String *)&result, "Unknown file format at URL \"", dest, "\"");
      if ( v9 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          v9 + 3,
          "%s",
          ((_QWORD)result.pKeyInterface & 0xFFFFFFFFFFFFFFFCui64) + 12);
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        v40,
        (const char *)(((_QWORD)result.pKeyInterface & 0xFFFFFFFFFFFFFFFCui64) + 12));
      v13 = (unsigned __int64)result.pKeyInterface;
      goto LABEL_69;
  }
}

// File Line: 1224
// RVA: 0x8B70C0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::BindMovieAndWait(Scaleform::GFx::MovieDefImpl *pm, Scaleform::GFx::MovieBindProcess *pbp, Scaleform::GFx::LoadStates *pls, unsigned int loadConstants, Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack)
{
  char v5; // bp
  Scaleform::GFx::LoadStates *v6; // r14
  Scaleform::GFx::MovieBindProcess *v7; // rdi
  Scaleform::GFx::MovieDefImpl *v8; // rbx
  Scaleform::GFx::TaskManager *v9; // rcx
  Scaleform::GFx::LoaderImpl::LoadStackItem *v10; // rdi
  Scaleform::GFx::LoaderImpl::LoadStackItem *v11; // rax
  const char *v12; // rax
  const char *v13; // rax
  char *v14; // r8
  unsigned int v15; // edx
  Scaleform::GFx::ResourceLibBase *v16; // rcx
  Scaleform::StringBuffer v18; // [rsp+28h] [rbp-40h]

  v5 = loadConstants;
  v6 = pls;
  v7 = pbp;
  v8 = pm;
  if ( pbp )
  {
    if ( loadConstants & 1
      || (v9 = pls->pTaskManager.pObject) == 0i64
      || !((unsigned __int8 (__cdecl *)(Scaleform::GFx::TaskManager *))v9->vfptr[1].__vecDelDtor)(v9) )
    {
      ((void (__fastcall *)(Scaleform::GFx::MovieBindProcess *))v7->vfptr[1].__vecDelDtor)(v7);
    }
  }
  v10 = ploadStack;
  v11 = ploadStack;
  if ( ploadStack )
  {
    while ( v11->pDefImpl != v8 )
    {
      v11 = v11->pNext;
      if ( !v11 )
        goto LABEL_17;
    }
    if ( v11->pNext )
    {
      if ( v6->pLog.pObject )
      {
        Scaleform::StringBuffer::StringBuffer(&v18, Scaleform::Memory::pGlobalHeap);
        do
        {
          v12 = (const char *)((__int64 (__cdecl *)(Scaleform::GFx::MovieDefImpl *))v10->pDefImpl->vfptr[3].__vecDelDtor)(v10->pDefImpl);
          Scaleform::StringBuffer::AppendString(&v18, v12, -1i64);
          Scaleform::StringBuffer::AppendChar(&v18, 0xAu);
          v10 = v10->pNext;
        }
        while ( v10 );
        v13 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v8->vfptr[3].__vecDelDtor)(v8);
        Scaleform::StringBuffer::AppendString(&v18, v13, -1i64);
        v14 = &customWorldMapCaption;
        if ( v18.pData )
          v14 = v18.pData;
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v6->pLog.pObject->vfptr,
          "Recursive import detected. Import stack:\n%s",
          v14);
        Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v18);
      }
      goto LABEL_22;
    }
    return v8;
  }
LABEL_17:
  if ( v5 & 1 )
  {
    v15 = 512;
  }
  else
  {
    if ( !(v5 & 2) )
      return v8;
    v15 = 256;
  }
  if ( Scaleform::GFx::MovieDefImpl::BindTaskData::WaitForBindStateFlags(v8->pBindData.pObject, v15) )
    return v8;
LABEL_22:
  if ( _InterlockedExchangeAdd(&v8->RefCount.Value, 0xFFFFFFFF) == 1 )
  {
    v16 = v8->pLib;
    if ( v16 )
    {
      v16->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v16->vfptr, (unsigned int)v8);
      v8->pLib = 0i64;
    }
    v8->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v8->vfptr, 1u);
  }
  return 0i64;
}

// File Line: 1310
// RVA: 0x8C11D0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(Scaleform::GFx::LoadStates *pls, Scaleform::GFx::MovieDataDef *pmd, unsigned int loadConstants, Scaleform::GFx::MovieBindProcess **ppbindProcess, bool checkCreate, Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack, unsigned __int64 memoryArena)
{
  Scaleform::GFx::MovieBindProcess **v7; // r14
  unsigned int loadConstantFlags; // ebp
  Scaleform::GFx::MovieDataDef *v9; // r15
  Scaleform::GFx::LoadStates *v10; // rsi
  Scaleform::GFx::MovieDefBindStates *v11; // rdi
  Scaleform::String::DataDesc *v12; // rax
  Scaleform::GFx::MovieDefImpl *v13; // rax
  Scaleform::GFx::MovieDefImpl *v14; // rdi
  Scaleform::String::DataDesc *v15; // rax
  Scaleform::GFx::MovieBindProcess *v16; // rax
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v17; // rcx
  char *v18; // r8
  Scaleform::GFx::Resource *v19; // rbx
  Scaleform::GFx::ResourceLibBase *v20; // rcx
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [rsp+60h] [rbp-48h]
  Scaleform::GFx::ResourceKey k; // [rsp+70h] [rbp-38h]
  Scaleform::String v24; // [rsp+B0h] [rbp+8h]

  v7 = ppbindProcess;
  loadConstantFlags = loadConstants;
  v9 = pmd;
  v10 = pls;
  phandle.State = 0;
  phandle.pResource = 0i64;
  v11 = pls->pBindStates.pObject;
  Scaleform::GFx::MovieDefImpl::CreateMovieKey(&k, pmd, pls->pBindStates.pObject);
  if ( (unsigned int)Scaleform::GFx::ResourceWeakLib::BindResourceKey(v10->pWeakResourceLib.pObject, &phandle, &k) == 3 )
  {
    v12 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           112ui64,
                                           0i64);
    v24.pData = v12;
    if ( v12 )
    {
      Scaleform::GFx::MovieDefImpl::MovieDefImpl(
        (Scaleform::GFx::MovieDefImpl *)v12,
        v9,
        v11,
        v10->pLoaderImpl.pObject,
        loadConstantFlags,
        v10->pLoaderImpl.pObject->pStateBag.pObject,
        Scaleform::Memory::pGlobalHeap,
        0,
        memoryArena);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    if ( !v7
      || ((v15 = (Scaleform::String::DataDesc *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  96i64),
           (v24.pData = v15) == 0i64) ? (v16 = 0i64) : Scaleform::GFx::MovieBindProcess::MovieBindProcess(
                                                         (Scaleform::GFx::MovieBindProcess *)v15,
                                                         v10,
                                                         v14,
                                                         ploadStack),
          (*v7 = v16) != 0i64) )
    {
      if ( v14 )
      {
        Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, (Scaleform::GFx::Resource *)&v14->vfptr);
        goto LABEL_23;
      }
    }
    else if ( v14 )
    {
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v14->vfptr);
    }
    Scaleform::String::String(
      &v24,
      "Failed to bind SWF file \"",
      (const char *)((v9->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
      "\"\n");
    Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
      phandle.pSlot,
      (const char *)((v24.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v24.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
  else
  {
    v14 = (Scaleform::GFx::MovieDefImpl *)Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&phandle);
    if ( v14 )
      goto LABEL_23;
    v17 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v10->pLog.pObject;
    if ( v17 )
    {
      if ( phandle.State < 2 )
        v18 = &customWorldMapCaption;
      else
        v18 = (char *)((*(_QWORD *)&phandle.pResource[2].RefCount.Value & 0xFFFFFFFFFFFFFFFCui64) + 12);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(v17 + 3, "%s", v18);
    }
  }
  v14 = 0i64;
LABEL_23:
  if ( k.pKeyInterface )
    k.pKeyInterface->vfptr->Release(k.pKeyInterface, k.hKeyData);
  if ( phandle.State == 1 )
  {
    if ( !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
    {
      v19 = phandle.pResource;
      v20 = phandle.pResource->pLib;
      if ( v20 )
      {
        v20->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v20->vfptr, (unsigned int)phandle.pResource);
        v19->pLib = 0i64;
      }
      v19->vfptr->__vecDelDtor(v19, 1u);
    }
  }
  else if ( phandle.State >= 2 )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)phandle.pResource);
  }
  return v14;
}

// File Line: 1395
// RVA: 0x8C2480
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(Scaleform::GFx::LoadStates *pls, Scaleform::GFx::MovieDataDef *pmd, unsigned int loadConstants, unsigned __int64 memoryArena)
{
  unsigned __int64 v4; // r14
  unsigned int v5; // ebp
  Scaleform::GFx::MovieDataDef *v6; // rbx
  Scaleform::GFx::LoadStates *v7; // rsi
  Scaleform::GFx::MovieDefImpl *v8; // rdi
  Scaleform::GFx::MovieDefImpl *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rbx
  Scaleform::GFx::MovieBindProcess *ppbindProcess; // [rsp+88h] [rbp+10h]

  v4 = memoryArena;
  v5 = loadConstants;
  v6 = pmd;
  v7 = pls;
  if ( pmd )
  {
    Scaleform::String::operator=(
      &pls->RelativePath,
      (const char *)((pmd->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    if ( !Scaleform::GFx::URLBuilder::ExtractFilePath(&v7->RelativePath) )
      Scaleform::String::Clear(&v7->RelativePath);
  }
  v8 = 0i64;
  ppbindProcess = 0i64;
  v9 = Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(v7, v6, v5, &ppbindProcess, 0, 0i64, v4);
  v10 = (Scaleform::Render::RenderBuffer *)ppbindProcess;
  if ( v9 )
    v8 = Scaleform::GFx::LoaderImpl::BindMovieAndWait(v9, ppbindProcess, v7, v5, 0i64);
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  return v8;
}

// File Line: 1412
// RVA: 0x8CB2E0
signed __int64 __fastcall Scaleform::GFx::LoaderImpl::FileFormat2RenderImageFile(Scaleform::GFx::FileTypeConstants::FileFormatType format)
{
  signed __int64 result; // rax

  switch ( format )
  {
    case 10:
      result = 2i64;
      break;
    case 11:
      result = 4i64;
      break;
    case 13:
      result = 5i64;
      break;
    case 14:
      result = 3i64;
      break;
    case 21:
      result = 6i64;
      break;
    case 23:
      result = 11i64;
      break;
    case 24:
      result = 8i64;
      break;
    case 27:
      result = 7i64;
      break;
    default:
      result = 1i64;
      break;
  }
  return result;
}

// File Line: 1449
// RVA: 0x8E8280
Scaleform::Render::ImageSource *__fastcall Scaleform::GFx::LoaderImpl::LoadBuiltinImage(Scaleform::File *pfile, __int64 format, __int64 __formal, Scaleform::GFx::LoadStates *pls, Scaleform::Log *plog, Scaleform::MemoryHeap *pimageHeap)
{
  Scaleform::GFx::LoadStates *v6; // rbp
  Scaleform::GFx::FileTypeConstants::FileFormatType v7; // ebx
  Scaleform::File *v8; // r14
  Scaleform::Render::ImageSource *v9; // rdi
  __int64 v10; // rsi
  Scaleform::Render::ImageFileFormat v11; // er15
  Scaleform::Render::ImageSource *result; // rax
  Scaleform::GFx::ImageFileHandlerRegistry *v13; // rbx
  Scaleform::Render::ImageFileReader *v14; // rcx
  int v15; // [rsp+28h] [rbp-40h]
  Scaleform::MemoryHeap *v16; // [rsp+30h] [rbp-38h]
  __int64 v17; // [rsp+38h] [rbp-30h]
  __int64 v18; // [rsp+40h] [rbp-28h]
  int v19; // [rsp+48h] [rbp-20h]

  v6 = pls;
  v7 = (signed int)format;
  v8 = pfile;
  v9 = 0i64;
  v10 = ((__int64 (__fastcall *)(Scaleform::File *, __int64, __int64))pfile->vfptr[1].__vecDelDtor)(
          pfile,
          format,
          __formal);
  v11 = (unsigned int)Scaleform::GFx::LoaderImpl::FileFormat2RenderImageFile(v7);
  if ( v11 == 1 )
  {
    if ( plog )
      Scaleform::Log::LogMessage(plog, "Default image loader failed to load %s", v10);
    result = 0i64;
  }
  else
  {
    v13 = v6->pImageFileHandlerRegistry.pObject;
    if ( v13 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v6->pImageFileHandlerRegistry.pObject);
    if ( v13 )
    {
      v14 = Scaleform::Render::ImageFileHandlerRegistry::GetReader(
              (Scaleform::Render::ImageFileHandlerRegistry *)&v13->vfptr,
              v11);
      if ( v14 )
      {
        v15 = 0;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0;
        v16 = pimageHeap;
        v9 = (Scaleform::Render::ImageSource *)((__int64 (__fastcall *)(Scaleform::Render::ImageFileReader *, Scaleform::File *, int *))v14->vfptr[1].GetFormat)(
                                                 v14,
                                                 v8,
                                                 &v15);
      }
      else if ( plog )
      {
        Scaleform::Log::LogError(plog, "Cant load image %s - appropriate reader is not installed.", v10);
      }
    }
    else if ( plog )
    {
      Scaleform::Log::LogError(plog, "Image file handler registry is not installed - cant load image data");
    }
    if ( v13 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v13);
    result = v9;
  }
  return result;
}

// File Line: 1500
// RVA: 0x8C7200
__int64 __fastcall Scaleform::GFx::LoaderImpl::DetectFileFormat(Scaleform::File *pfile)
{
  Scaleform::File *v1; // rdi
  unsigned int v3; // eax
  Scaleform::RefCountImplCoreVtbl *v4; // r9
  unsigned int v5; // ebx
  unsigned int v6; // esi
  const char *v7; // rax
  const char *v8; // rax
  int v9; // [rsp+30h] [rbp+10h]

  v1 = pfile;
  if ( !pfile )
    return 0i64;
  v3 = ((__int64 (*)(void))pfile->vfptr[4].__vecDelDtor)();
  v4 = v1->vfptr;
  v5 = 1;
  v6 = v3;
  v9 = 0;
  if ( ((signed int (__fastcall *)(Scaleform::File *, int *, signed __int64))v4[10].__vecDelDtor)(v1, &v9, 4i64) > 0 )
  {
    switch ( (unsigned __int8)v9 )
    {
      case 0x34u:
        v1->vfptr[14].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 44u);
        if ( ((unsigned int (__fastcall *)(Scaleform::File *, int *, signed __int64))v1->vfptr[10].__vecDelDtor)(
               v1,
               &v9,
               3i64) == 3
          && (_BYTE)v9 == 80
          && BYTE1(v9) == 86
          && BYTE2(v9) == 82 )
        {
          v5 = 21;
        }
        break;
      case 0x43u:
      case 0x46u:
        if ( BYTE1(v9) == 87 )
        {
          if ( BYTE2(v9) == 83 )
            v5 = 2;
        }
        else if ( BYTE1(v9) == 70 && BYTE2(v9) == 88 )
        {
          v5 = 3;
        }
        break;
      case 0x44u:
        if ( BYTE1(v9) == 68 && BYTE2(v9) == 83 )
          v5 = 14;
        break;
      case 0x47u:
        if ( BYTE1(v9) == 73 )
        {
          if ( BYTE2(v9) == 70 && HIBYTE(v9) == 56 )
            v5 = 12;
        }
        else if ( BYTE1(v9) == 70 )
        {
          if ( BYTE2(v9) == 88 )
            v5 = 3;
        }
        else if ( BYTE1(v9) == 88 && HIWORD(v9) == 84 )
        {
          v5 = 24;
        }
        break;
      case 0x89u:
        if ( BYTE1(v9) == 80 && BYTE2(v9) == 78 && HIBYTE(v9) == 71 )
          v5 = 11;
        break;
      case 0xABu:
        if ( BYTE1(v9) == 75 && BYTE2(v9) == 84 && HIBYTE(v9) == 88 )
          v5 = 27;
        break;
      case 0xFFu:
        if ( BYTE1(v9) == -40 )
          v5 = 10;
        break;
      default:
        break;
    }
    ((void (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v1->vfptr[14].__vecDelDtor)(v1, v6, 0i64);
    if ( v5 == 1 )
    {
      v7 = (const char *)((__int64 (__fastcall *)(Scaleform::File *))v1->vfptr[1].__vecDelDtor)(v1);
      if ( v7 )
      {
        v8 = strrchr(v7, 46);
        if ( v8 )
        {
          if ( !Scaleform::String::CompareNoCase(v8, ".tga") )
            v5 = 13;
        }
      }
    }
  }
  return v5;
}

// File Line: 1582
// RVA: 0x8E75F0
char __fastcall Scaleform::GFx::LoaderImpl::IsProtocolImage(Scaleform::String *url, bool *bilinear, bool *sync)
{
  bool *v3; // rdi
  bool *v4; // rsi
  Scaleform::String *v5; // r14
  int v6; // er9
  __int64 v7; // rbx
  signed int v8; // ebp
  unsigned __int64 v9; // rcx
  char v10; // al
  bool v11; // zf
  bool v12; // r14
  Scaleform::String *v13; // rax
  bool v14; // r14
  Scaleform::String v16; // [rsp+20h] [rbp-38h]
  Scaleform::String v17; // [rsp+28h] [rbp-30h]
  __int64 v18; // [rsp+30h] [rbp-28h]
  Scaleform::String result; // [rsp+78h] [rbp+20h]

  v18 = -2i64;
  v3 = sync;
  v4 = bilinear;
  v5 = url;
  if ( Scaleform::String::GetLength(url) <= 6 )
    return 0;
  v6 = *(char *)((v5->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  if ( (unsigned int)(v6 - 65) <= 0x19 )
    v6 += 32;
  if ( v6 != 105 && v6 != 115 )
    return 0;
  v7 = 0i64;
  v8 = 0;
  if ( v6 == 115 )
    v8 = 1;
  Scaleform::String::ToLower(v5, &result);
  v9 = (Scaleform::String::Substring(&result, &v16, v8, v8 + 6)->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12;
  while ( 1 )
  {
    v10 = *(_BYTE *)(v9 + v7++);
    v11 = v10 == aImg_0[v7 - 1];
    if ( v10 != aImg_0[v7 - 1] )
      break;
    if ( v7 == 7 )
    {
      v11 = v10 == aImg_0[6];
      break;
    }
  }
  v12 = v11;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v16.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( !v12 )
  {
    v13 = Scaleform::String::Substring(&result, &v17, v8, v8 + 8);
    v14 = strcmp((const char *)((v13->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), "imgps://") == 0;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v17.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    if ( v14 )
    {
      if ( v4 )
        *v4 = 0;
      goto LABEL_22;
    }
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    return 0;
  }
  if ( v4 )
    *v4 = 1;
LABEL_22:
  if ( v3 )
    *v3 = v8 != 0;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return 1;
}

// File Line: 1706
// RVA: 0x8EEAF0
char __fastcall Scaleform::GFx::Translator::OnWordWrapping(Scaleform::GFx::Translator *this, Scaleform::GFx::Translator::LineFormatDesc *pdesc)
{
  unsigned int v2; // er10
  Scaleform::GFx::Translator::LineFormatDesc *v3; // rbx
  char result; // al
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rdi
  const wchar_t *v8; // r14
  unsigned __int64 v9; // rbp
  wchar_t *v10; // rsi
  signed int v11; // er14
  unsigned __int16 v12; // ax

  v2 = this->WWMode;
  v3 = pdesc;
  if ( !v2 )
    return 0;
  if ( v2 & 7 && pdesc->NumCharsInLine )
  {
    v5 = Scaleform::Render::Text::WordWrapHelper::FindWordWrapPos(
           v2,
           pdesc->ProposedWordWrapPoint,
           pdesc->pParaText,
           pdesc->ParaTextLen,
           pdesc->LineStartPos,
           pdesc->NumCharsInLine);
    if ( v5 == -1i64 )
      return 0;
    v3->ProposedWordWrapPoint = v5;
    result = 1;
  }
  else
  {
    if ( !(v2 & 8) )
      goto LABEL_17;
    v6 = pdesc->ProposedWordWrapPoint;
    if ( !v6 )
      goto LABEL_17;
    v7 = pdesc->NumCharsInLine;
    v8 = &pdesc->pParaText[pdesc->LineStartPos];
    v9 = 0i64;
    if ( (unsigned int)Scaleform::SFiswspace(v8[v6 - 1]) )
      v9 = v6;
    if ( v7 > v9 )
    {
      v10 = (wchar_t *)&v8[v7 - 1];
      v11 = 1065233;
      while ( 1 )
      {
        v12 = Scaleform::SFtowlower(*v10) - 97;
        if ( v12 <= 0x14u
          && _bittest(&v11, v12)
          && (float)((float)v3->pWidths[v7 - 1] + v3->DashSymbolWidth) < v3->VisibleRectWidth )
        {
          break;
        }
        --v7;
        --v10;
        if ( v7 <= v9 )
          goto LABEL_17;
      }
      v3->ProposedWordWrapPoint = v7;
      v3->UseHyphenation = 1;
      result = 1;
    }
    else
    {
LABEL_17:
      result = 0;
    }
  }
  return result;
}

// File Line: 1768
// RVA: 0x90B100
void __fastcall Scaleform::GFx::Translator::TranslateInfo::SetResult(Scaleform::GFx::Translator::TranslateInfo *this, const wchar_t *presultText, unsigned __int64 resultLen)
{
  unsigned __int64 v3; // rdi
  const wchar_t *v4; // rsi
  Scaleform::GFx::Translator::TranslateInfo *v5; // rbp

  if ( presultText )
  {
    v3 = resultLen;
    v4 = presultText;
    v5 = this;
    if ( resultLen == -1i64 )
      v3 = Scaleform::SFwcslen(presultText);
    Scaleform::WStringBuffer::Resize(v5->pResult, v3 + 1);
    Scaleform::SFwcsncpy(v5->pResult->pText, v3 + 1, v4, v3);
    v5->Flags |= 1u;
  }
}

// File Line: 1782
// RVA: 0x90B070
void __fastcall Scaleform::GFx::Translator::TranslateInfo::SetResult(Scaleform::GFx::Translator::TranslateInfo *this, const char *presultTextUTF8, unsigned __int64 resultUTF8Len)
{
  __int64 v3; // rbx
  const char *v4; // rsi
  Scaleform::GFx::Translator::TranslateInfo *v5; // rbp
  unsigned __int64 v6; // rdi

  if ( presultTextUTF8 )
  {
    v3 = resultUTF8Len;
    v4 = presultTextUTF8;
    v5 = this;
    if ( resultUTF8Len == -1i64 )
    {
      v3 = -1i64;
      do
        ++v3;
      while ( presultTextUTF8[v3] );
    }
    v6 = (signed int)((unsigned __int64)Scaleform::UTF8Util::GetLength(presultTextUTF8, -1i64) + 1);
    Scaleform::WStringBuffer::Resize(v5->pResult, v6);
    Scaleform::UTF8Util::DecodeStringSafe(v5->pResult->pText, v6, v4, v3);
    v5->Flags |= 1u;
  }
}

