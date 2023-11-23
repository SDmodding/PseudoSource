// File Line: 64
// RVA: 0x906C80
void __fastcall Scaleform::GFx::ExporterInfoImpl::SetData(
        Scaleform::GFx::ExporterInfoImpl *this,
        unsigned __int16 version,
        Scaleform::GFx::FileTypeConstants::FileFormatType format,
        const char *pname,
        const char *pprefix,
        unsigned int flags,
        Scaleform::Array<unsigned long,2,Scaleform::ArrayDefaultPolicy> *codeOffsets)
{
  const char *v8; // rdi
  const char *v9; // rdx
  unsigned __int64 i; // rbx

  this->SI.Version = version;
  this->SI.Format = format;
  v8 = &customCaption;
  v9 = &customCaption;
  if ( pprefix )
    v9 = pprefix;
  Scaleform::String::operator=(&this->Prefix, v9);
  if ( pname )
    v8 = pname;
  Scaleform::String::operator=(&this->SWFName, v8);
  this->SI.pSWFName = (const char *)((this->SWFName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  this->SI.pPrefix = (const char *)((this->Prefix.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  this->SI.ExportFlags = flags;
  if ( codeOffsets )
  {
    Scaleform::ArrayData<unsigned long,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->CodeOffsets.Data,
      codeOffsets->Data.Size);
    for ( i = 0i64; i < this->CodeOffsets.Data.Size; this->CodeOffsets.Data.Data[i - 1] = codeOffsets->Data.Data[i - 1] )
      ++i;
  }
  else
  {
    if ( this->CodeOffsets.Data.Size && (this->CodeOffsets.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( this->CodeOffsets.Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        this->CodeOffsets.Data.Data = 0i64;
      }
      this->CodeOffsets.Data.Policy.Capacity = 0i64;
    }
    this->CodeOffsets.Data.Size = 0i64;
  }
}

// File Line: 83
// RVA: 0x8FBA20
void __fastcall Scaleform::GFx::ExporterInfoImpl::ReadExporterInfoTag(
        Scaleform::GFx::ExporterInfoImpl *this,
        Scaleform::GFx::Stream *pin,
        Scaleform::GFx::TagType tagType)
{
  unsigned __int64 v4; // r15
  int v5; // r12d
  __int64 Pos; // r8
  unsigned __int16 v7; // r13
  __int64 v8; // r8
  __int64 v9; // r8
  __int64 v10; // rdx
  unsigned __int64 v11; // rcx
  __int64 v12; // rdx
  unsigned __int64 v13; // rcx
  __int64 v14; // r8
  unsigned __int16 v15; // r9
  __int64 i; // r14
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
  unsigned __int64 Size; // rdi
  unsigned __int64 v28; // r8
  Scaleform::String v29; // [rsp+50h] [rbp-39h] BYREF
  __int64 v30; // [rsp+58h] [rbp-31h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *p_pheapAddr; // [rsp+60h] [rbp-29h]
  Scaleform::String::InitStruct src; // [rsp+68h] [rbp-21h] BYREF
  Scaleform::GFx::Stream *v33; // [rsp+70h] [rbp-19h]
  Scaleform::String::InitStruct v34; // [rsp+78h] [rbp-11h] BYREF
  Scaleform::GFx::Stream *v35; // [rsp+80h] [rbp-9h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+88h] [rbp-1h] BYREF
  unsigned __int16 v38; // [rsp+F8h] [rbp+6Fh]
  Scaleform::String v39; // [rsp+108h] [rbp+7Fh] BYREF

  v30 = -2i64;
  v4 = 0i64;
  v5 = 0;
  pin->UnusedBits = 0;
  if ( (signed int)(pin->DataSize - pin->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
  Pos = pin->Pos;
  v7 = (unsigned __int8)pin->pBuffer[Pos] | ((unsigned __int8)pin->pBuffer[(unsigned int)(Pos + 1)] << 8);
  pin->Pos = Pos + 2;
  if ( v7 >= 0x10Au )
  {
    pin->UnusedBits = 0;
    if ( (signed int)(pin->DataSize - (Pos + 2)) < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(pin, 4);
    v8 = pin->Pos;
    v5 = (unsigned __int8)pin->pBuffer[v8] | (((unsigned __int8)pin->pBuffer[(unsigned int)(v8 + 1)] | (((unsigned __int8)pin->pBuffer[(unsigned int)(v8 + 2)] | ((unsigned __int8)pin->pBuffer[(unsigned int)(v8 + 3)] << 8)) << 8)) << 8);
    pin->Pos = v8 + 4;
  }
  pin->UnusedBits = 0;
  if ( (signed int)(pin->DataSize - pin->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
  v9 = pin->Pos;
  v38 = (unsigned __int8)pin->pBuffer[v9] | ((unsigned __int8)pin->pBuffer[(unsigned int)(v9 + 1)] << 8);
  pin->Pos = v9 + 2;
  Scaleform::String::String(&v29);
  Scaleform::String::String(&v39);
  pin->UnusedBits = 0;
  if ( (signed int)(pin->DataSize - pin->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(pin, 1);
  v10 = pin->Pos;
  v11 = (unsigned __int8)pin->pBuffer[v10];
  pin->Pos = v10 + 1;
  if ( (int)v11 > 0 )
  {
    src.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength::`2::StringReader::`vftable;
    v33 = pin;
    Scaleform::String::AssignString(&v29, &src, v11);
    src.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  }
  else
  {
    Scaleform::String::Clear(&v29);
  }
  pin->UnusedBits = 0;
  if ( (signed int)(pin->DataSize - pin->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(pin, 1);
  v12 = pin->Pos;
  v13 = (unsigned __int8)pin->pBuffer[v12];
  pin->Pos = v12 + 1;
  if ( (int)v13 > 0 )
  {
    v34.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength::`2::StringReader::`vftable;
    v35 = pin;
    Scaleform::String::AssignString(&v39, &v34, v13);
    v34.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  }
  else
  {
    Scaleform::String::Clear(&v39);
  }
  p_pheapAddr = &pheapAddr;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  if ( v7 >= 0x401u )
  {
    pin->UnusedBits = 0;
    if ( (signed int)(pin->DataSize - pin->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
    v14 = pin->Pos;
    v15 = (unsigned __int8)pin->pBuffer[v14] | ((unsigned __int8)pin->pBuffer[(unsigned int)(v14 + 1)] << 8);
    pin->Pos = v14 + 2;
    if ( v15 )
    {
      for ( i = v15; i; --i )
      {
        pin->UnusedBits = 0;
        if ( (signed int)(pin->DataSize - pin->Pos) < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(pin, 4);
        v17 = pin->Pos;
        v18 = (unsigned __int8)pin->pBuffer[v17] | (((unsigned __int8)pin->pBuffer[(unsigned int)(v17 + 1)] | (((unsigned __int8)pin->pBuffer[(unsigned int)(v17 + 2)] | ((unsigned __int8)pin->pBuffer[(unsigned int)(v17 + 3)] << 8)) << 8)) << 8);
        pin->Pos = v17 + 4;
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
          Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,Scaleform::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v20);
        }
        pheapAddr.Size = v19;
        v21 = &pheapAddr.Data[v19 - 1];
        if ( v21 )
          *v21 = v18;
      }
    }
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    pin,
    "  ExportInfo: tagType = %d, tool ver = %d.%d, imgfmt = %d, prefix = %s, swfname = %s, flags = 0x%X\n");
  v22 = (v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
  v23 = (v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12;
  v24 = (v39.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12;
  this->SI.Version = v7;
  this->SI.Format = v38;
  v25 = &customCaption;
  v26 = &customCaption;
  if ( !v22 )
    v26 = (const char *)v23;
  Scaleform::String::operator=(&this->Prefix, v26);
  if ( v24 )
    v25 = (const char *)v24;
  Scaleform::String::operator=(&this->SWFName, v25);
  this->SI.pSWFName = (const char *)((this->SWFName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  this->SI.pPrefix = (const char *)((this->Prefix.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  this->SI.ExportFlags = v5;
  Size = pheapAddr.Size;
  if ( pheapAddr.Size >= this->CodeOffsets.Data.Size )
  {
    if ( pheapAddr.Size <= this->CodeOffsets.Data.Policy.Capacity )
      goto LABEL_45;
    v28 = pheapAddr.Size + (pheapAddr.Size >> 2);
  }
  else
  {
    if ( pheapAddr.Size >= this->CodeOffsets.Data.Policy.Capacity >> 1 )
      goto LABEL_45;
    v28 = pheapAddr.Size;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,Scaleform::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&this->CodeOffsets,
    &this->CodeOffsets,
    v28);
LABEL_45:
  this->CodeOffsets.Data.Size = Size;
  if ( Size )
  {
    do
    {
      this->CodeOffsets.Data.Data[v4] = pheapAddr.Data[v4];
      ++v4;
    }
    while ( v4 < this->CodeOffsets.Data.Size );
  }
  if ( pheapAddr.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v39.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 137
// RVA: 0x8E57A0
char __fastcall Scaleform::GFx::SWFProcessInfo::Initialize(
        Scaleform::GFx::SWFProcessInfo *this,
        Scaleform::GFx::Resource *pin,
        Scaleform::GFx::LogState *plog,
        Scaleform::GFx::ZlibSupportBase *zlib,
        Scaleform::GFx::ParseControl *pparseControl,
        bool parseMsg)
{
  Scaleform::GFx::Resource *v8; // rbx
  bool v10; // di
  int Id; // edx
  int v12; // ecx
  __int64 v13; // r9
  bool v14; // r12
  int v15; // eax
  Scaleform::GFx::ParseControl *v17; // r14
  Scaleform::GFx::Resource *v18; // rdi
  Scaleform::Log *pObject; // rax
  __int64 Pos; // r9
  unsigned __int16 v21; // r8
  __int64 v22; // r9
  unsigned __int16 v23; // r8
  char v24; // di
  unsigned int v25; // edi
  __int64 v26; // r9
  unsigned __int16 v27; // r8
  int TagOffset; // edx
  __int64 v29; // r9
  unsigned __int16 v30; // r8
  Scaleform::GFx::TagInfo pTagInfo; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::LogMessageId messageType; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::Resource *v33; // [rsp+88h] [rbp+10h] BYREF

  v8 = pin;
  this->FileStartPos = ((__int64 (__fastcall *)(Scaleform::GFx::Resource *))pin->vfptr[1].__vecDelDtor)(pin);
  v10 = 0;
  LODWORD(v33) = 0;
  ((void (__fastcall *)(Scaleform::GFx::Resource *, Scaleform::GFx::Resource **, __int64))v8->vfptr[2].GetResourceTypeCode)(
    v8,
    &v33,
    4i64);
  messageType.Id = 0;
  ((void (__fastcall *)(Scaleform::GFx::Resource *, Scaleform::LogMessageId *, __int64))v8->vfptr[2].GetResourceTypeCode)(
    v8,
    &messageType,
    4i64);
  Id = messageType.Id;
  this->Header.FileLength = messageType.Id;
  this->FileEndPos = Id + this->FileStartPos;
  this->NextActionBlock = 0;
  v12 = (int)v33;
  v13 = (unsigned int)v33 >> 24;
  this->Header.Version = v13;
  this->Header.SWFFlags = 0;
  v14 = (_BYTE)v12 == 67;
  this->FileAttributes = 0;
  v15 = v12 & 0xFFFFFF;
  if ( (v12 & 0xFFFFFF) != 5461830 && v15 != 5461827 && v15 != 5785159 && v15 != 5785155 )
  {
    if ( plog )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "Loader read failed - file does not start with a SWF header");
    return 0;
  }
  if ( (v12 & 0xFF0000) == 5767168 )
    this->Header.SWFFlags = 16;
  if ( (_BYTE)v12 == 67 )
    this->Header.SWFFlags |= 1u;
  v17 = pparseControl;
  if ( plog )
  {
    if ( pparseControl )
    {
      if ( (pparseControl->ParseFlags & 1) != 0 )
      {
        v10 = parseMsg;
        if ( parseMsg )
        {
          messageType.Id = 20480;
          Scaleform::Log::LogMessageById(
            plog,
            (Scaleform::LogMessageId)&messageType,
            "SWF File version = %d, File length = %d\n",
            v13,
            Id);
        }
      }
    }
  }
  Scaleform::Render::RenderBuffer::AddRef(v8);
  v33 = v8;
  if ( v14 )
  {
    if ( !zlib )
    {
      if ( plog )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "Loader - unable to read compressed SWF data; GFxZlibState is not set.");
      goto LABEL_35;
    }
    if ( v10 )
    {
      messageType.Id = 20480;
      Scaleform::Log::LogMessageById(plog, (Scaleform::LogMessageId)&messageType, "SWF file is compressed.\n");
    }
    v18 = (Scaleform::GFx::Resource *)zlib->vfptr[1].__vecDelDtor(zlib, v8);
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8);
    v8 = v18;
    v33 = v18;
    this->FileEndPos = this->Header.FileLength - 8;
  }
  pObject = plog->pLog.pObject;
  if ( !pObject )
    pObject = Scaleform::Log::GetGlobalLog();
  Scaleform::GFx::Stream::Initialize(&this->Stream, (Scaleform::File *)v8, pObject, v17);
  Scaleform::GFx::Stream::ReadRect(&this->Stream, &this->Header.FrameRect);
  this->Stream.UnusedBits = 0;
  if ( (signed int)(this->Stream.DataSize - this->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&this->Stream, 2);
  Pos = this->Stream.Pos;
  v21 = (unsigned __int8)this->Stream.pBuffer[Pos] | ((unsigned __int8)this->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  this->Stream.Pos = Pos + 2;
  this->Header.FPS = (float)v21 * 0.00390625;
  this->Stream.UnusedBits = 0;
  if ( (signed int)(this->Stream.DataSize - this->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&this->Stream, 2);
  v22 = this->Stream.Pos;
  v23 = (unsigned __int8)this->Stream.pBuffer[v22] | ((unsigned __int8)this->Stream.pBuffer[(unsigned int)(v22 + 1)] << 8);
  this->Stream.Pos = v22 + 2;
  this->Header.FrameCount = v23;
  if ( (this->Header.SWFFlags & 0x10) == 0 )
  {
    if ( this->Header.Version < 9 || this->Stream.Pos + this->Stream.FilePos - this->Stream.DataSize >= this->FileEndPos )
      goto LABEL_53;
    if ( Scaleform::GFx::Stream::OpenTag(&this->Stream, &pTagInfo) == Tag_FileAttributes )
    {
      this->Stream.UnusedBits = 0;
      if ( (signed int)(this->Stream.DataSize - this->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&this->Stream, 2);
      v29 = this->Stream.Pos;
      v30 = (unsigned __int8)this->Stream.pBuffer[v29] | ((unsigned __int8)this->Stream.pBuffer[(unsigned int)(v29 + 1)] << 8);
      this->Stream.Pos = v29 + 2;
      this->FileAttributes = v30;
    }
    Scaleform::GFx::Stream::SetPosition(&this->Stream, this->Stream.TagStack[--this->Stream.TagStackEntryCount]);
    TagOffset = pTagInfo.TagOffset;
    goto LABEL_52;
  }
  if ( this->Stream.Pos + this->Stream.FilePos - this->Stream.DataSize >= this->FileEndPos )
  {
LABEL_36:
    if ( this->Header.Version < 9 )
      goto LABEL_53;
    v25 = this->Stream.Pos + this->Stream.FilePos - this->Stream.DataSize;
    if ( v25 >= this->FileEndPos )
      goto LABEL_53;
    for ( ; Scaleform::GFx::Stream::OpenTag(&this->Stream, &pTagInfo) >= Tag_ExporterInfo; this->Stream.UnusedBits = 0 )
      Scaleform::GFx::Stream::SetPosition(&this->Stream, this->Stream.TagStack[--this->Stream.TagStackEntryCount]);
    if ( pTagInfo.TagType == Tag_FileAttributes )
    {
      this->Stream.UnusedBits = 0;
      if ( (signed int)(this->Stream.DataSize - this->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&this->Stream, 2);
      v26 = this->Stream.Pos;
      v27 = (unsigned __int8)this->Stream.pBuffer[v26] | ((unsigned __int8)this->Stream.pBuffer[(unsigned int)(v26 + 1)] << 8);
      this->Stream.Pos = v26 + 2;
      this->FileAttributes = v27;
    }
    Scaleform::GFx::Stream::SetPosition(&this->Stream, this->Stream.TagStack[--this->Stream.TagStackEntryCount]);
    TagOffset = v25;
LABEL_52:
    this->Stream.UnusedBits = 0;
    Scaleform::GFx::Stream::SetPosition(&this->Stream, TagOffset);
LABEL_53:
    v24 = 1;
    goto LABEL_54;
  }
  if ( Scaleform::GFx::Stream::OpenTag(&this->Stream) == Tag_ExporterInfo )
  {
    Scaleform::GFx::ExporterInfoImpl::ReadExporterInfoTag(&this->Header.mExporterInfo, &this->Stream, Tag_ExporterInfo);
    Scaleform::GFx::Stream::SetPosition(&this->Stream, this->Stream.TagStack[--this->Stream.TagStackEntryCount]);
    this->Stream.UnusedBits = 0;
    goto LABEL_36;
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
    &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
    "Loader read failed - no mExporterInfo tag in GFX file header");
LABEL_35:
  v24 = 0;
LABEL_54:
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8);
  return v24;
}

// File Line: 286
// RVA: 0x89A410
void __fastcall Scaleform::GFx::LoaderTask::LoaderTask(
        Scaleform::GFx::LoaderTask *this,
        Scaleform::GFx::Resource *pls,
        Scaleform::GFx::Task::TaskId id)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Task,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  this->ThisTaskId = id;
  this->CurrentState = State_Stopped;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderTask::`vftable;
  if ( pls )
    Scaleform::Render::RenderBuffer::AddRef(pls);
  this->pLoadStates.pObject = (Scaleform::GFx::LoadStates *)pls;
  Scaleform::GFx::LoaderImpl::RegisterLoadProcess(this->pLoadStates.pObject->pLoaderImpl.pObject, this);
}

// File Line: 291
// RVA: 0x8A5D30
void __fastcall Scaleform::GFx::LoaderTask::~LoaderTask(Scaleform::GFx::LoaderTask *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderTask::`vftable;
  Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(this->pLoadStates.pObject->pLoaderImpl.pObject, this);
  pObject = (Scaleform::Render::RenderBuffer *)this->pLoadStates.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 301
// RVA: 0x899F60
void __fastcall Scaleform::GFx::LoaderImpl::LoaderImpl(
        Scaleform::GFx::LoaderImpl *this,
        Scaleform::GFx::ResourceLib *plib,
        bool debugHeap)
{
  Scaleform::GFx::ResourceWeakLib *pWeakLib; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::StateBagImpl *v8; // rax
  Scaleform::GFx::StateBagImpl *v9; // rax
  Scaleform::GFx::StateBagImpl *v10; // rbx
  Scaleform::Render::RenderBuffer *v11; // rcx
  __int64 v12; // rax
  Scaleform::Log *v13; // rbx
  __int64 v14; // rax
  Scaleform::GFx::State *v15; // rbx
  __int64 v16; // rax
  Scaleform::GFx::State *v17; // rbx
  __int64 v18; // rax
  Scaleform::GFx::TextKeyMap *v19; // rcx
  Scaleform::GFx::TextKeyMap *inited; // rbx

  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::`vftable;
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>};
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>};
  this->pStateBag.pObject = 0i64;
  this->pWeakResourceLib.pObject = 0i64;
  this->LoadProcesses.Root.pPrev = (Scaleform::GFx::LoadProcessNode *)&this->LoadProcesses;
  this->LoadProcesses.Root.pNext = (Scaleform::GFx::LoadProcessNode *)&this->LoadProcesses;
  Scaleform::Lock::Lock(&this->LoadProcessesLock, 0);
  this->DebugHeap = debugHeap;
  this->HttpFilesOpened.mHash.pTable = 0i64;
  if ( plib )
  {
    pWeakLib = plib->pWeakLib;
    if ( pWeakLib )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)plib->pWeakLib);
    pObject = (Scaleform::Render::RenderBuffer *)this->pWeakResourceLib.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pWeakResourceLib.pObject = pWeakLib;
  }
  v8 = (Scaleform::GFx::StateBagImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                         Scaleform::Memory::pGlobalHeap,
                                         88i64);
  if ( v8 )
  {
    Scaleform::GFx::StateBagImpl::StateBagImpl(v8, 0i64);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = (Scaleform::Render::RenderBuffer *)this->pStateBag.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  this->pStateBag.pObject = v10;
  if ( v10 )
  {
    v12 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            16i64);
    v13 = (Scaleform::Log *)v12;
    if ( v12 )
    {
      *(_QWORD *)v12 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v12 + 8) = 1;
      *(_QWORD *)v12 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v12 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v12 = &Scaleform::RefCountBase<Scaleform::Log,2>::`vftable;
      *(_QWORD *)v12 = &Scaleform::Log::`vftable;
    }
    else
    {
      v13 = 0i64;
    }
    Scaleform::GFx::StateBag::SetLog(&this->pStateBag.pObject->Scaleform::GFx::StateBag, v13);
    if ( v13 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v13);
    v14 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            32i64);
    v15 = (Scaleform::GFx::State *)v14;
    if ( v14 )
    {
      *(_QWORD *)v14 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v14 + 8) = 1;
      *(_QWORD *)v14 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v14 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v14 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v14 = &Scaleform::GFx::State::`vftable;
      *(_DWORD *)(v14 + 16) = 14;
      *(_QWORD *)v14 = &Scaleform::GFx::ImageCreator::`vftable;
      *(_QWORD *)(v14 + 24) = 0i64;
    }
    else
    {
      v15 = 0i64;
    }
    this->pStateBag.pObject->vfptr->SetState(
      &this->pStateBag.pObject->Scaleform::GFx::StateBag,
      State_OrigNodeBounds|State_MaskNode,
      v15);
    if ( v15 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v15);
    v16 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            64i64);
    v17 = (Scaleform::GFx::State *)v16;
    if ( v16 )
    {
      *(_QWORD *)v16 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v16 + 8) = 1;
      *(_QWORD *)v16 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v16 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v16 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v16 = &Scaleform::GFx::State::`vftable;
      *(_DWORD *)(v16 + 16) = 25;
      *(_QWORD *)v16 = &Scaleform::GFx::Clipboard::`vftable;
      *(_QWORD *)(v16 + 24) = 0i64;
      *(_QWORD *)(v16 + 32) = 0i64;
      *(_QWORD *)(v16 + 40) = 0i64;
      *(_QWORD *)(v16 + 48) = 0i64;
      *(_QWORD *)(v16 + 56) = 0i64;
    }
    else
    {
      v17 = 0i64;
    }
    this->pStateBag.pObject->vfptr->SetState(
      &this->pStateBag.pObject->Scaleform::GFx::StateBag,
      State_Internal_MaskOwner|0x10,
      v17);
    if ( v17 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v17);
    v18 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            48i64);
    v19 = (Scaleform::GFx::TextKeyMap *)v18;
    if ( v18 )
    {
      *(_QWORD *)v18 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v18 + 8) = 1;
      *(_QWORD *)v18 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v18 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v18 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v18 = &Scaleform::GFx::State::`vftable;
      *(_DWORD *)(v18 + 16) = 26;
      *(_QWORD *)v18 = &Scaleform::GFx::TextKeyMap::`vftable;
      *(_QWORD *)(v18 + 24) = 0i64;
      *(_QWORD *)(v18 + 32) = 0i64;
      *(_QWORD *)(v18 + 40) = 0i64;
    }
    else
    {
      v19 = 0i64;
    }
    inited = Scaleform::GFx::TextKeyMap::InitWindowsKeyMap(v19);
    this->pStateBag.pObject->vfptr->SetState(
      &this->pStateBag.pObject->Scaleform::GFx::StateBag,
      State_OrigNodeBounds|0x10,
      inited);
    if ( inited )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)inited);
  }
}

// File Line: 351
// RVA: 0x89A2F0
void __fastcall Scaleform::GFx::LoaderImpl::LoaderImpl(
        Scaleform::GFx::LoaderImpl *this,
        Scaleform::GFx::StateBag *pstates,
        Scaleform::GFx::ResourceLib *plib,
        bool debugHeap)
{
  Scaleform::GFx::Resource *v8; // rsi
  Scaleform::GFx::ResourceWeakLib *pWeakLib; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx

  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::`vftable;
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>};
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>};
  v8 = 0i64;
  this->pStateBag.pObject = 0i64;
  this->pWeakResourceLib.pObject = 0i64;
  this->LoadProcesses.Root.pPrev = (Scaleform::GFx::LoadProcessNode *)&this->LoadProcesses;
  this->LoadProcesses.Root.pNext = (Scaleform::GFx::LoadProcessNode *)&this->LoadProcesses;
  Scaleform::Lock::Lock(&this->LoadProcessesLock, 0);
  this->DebugHeap = debugHeap;
  this->HttpFilesOpened.mHash.pTable = 0i64;
  if ( plib )
  {
    pWeakLib = plib->pWeakLib;
    if ( pWeakLib )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)plib->pWeakLib);
    pObject = (Scaleform::Render::RenderBuffer *)this->pWeakResourceLib.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pWeakResourceLib.pObject = pWeakLib;
  }
  if ( pstates )
    v8 = (Scaleform::GFx::Resource *)&pstates[-2];
  if ( v8 )
    Scaleform::Render::RenderBuffer::AddRef(v8);
  v11 = (Scaleform::Render::RenderBuffer *)this->pStateBag.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  this->pStateBag.pObject = (Scaleform::GFx::StateBagImpl *)v8;
}

// File Line: 359
// RVA: 0x8A5C90
void __fastcall Scaleform::GFx::LoaderImpl::~LoaderImpl(Scaleform::GFx::LoaderImpl *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx

  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>};
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::StateBag};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LoaderImpl::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>};
  Scaleform::GFx::LoaderImpl::CancelLoading(this);
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::LoaderImpl::HttpFileCache>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>(&this->HttpFilesOpened.mHash);
  Scaleform::Lock::~Lock(&this->LoadProcessesLock.cs);
  pObject = (Scaleform::Render::RenderBuffer *)this->pWeakResourceLib.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (Scaleform::Render::RenderBuffer *)this->pStateBag.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::`vftable;
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 515
// RVA: 0x8C1050
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::CreateMovie(
        Scaleform::GFx::LoaderImpl *this,
        const char *pfilename,
        unsigned int loadConstants,
        unsigned __int64 memoryArena)
{
  Scaleform::String::DataDesc *v7; // rax
  Scaleform::GFx::MovieDefImpl *v8; // rsi
  Scaleform::GFx::LoadStates *v9; // rax
  Scaleform::GFx::LoadStates *v10; // rdi
  Scaleform::String src; // [rsp+30h] [rbp-58h] BYREF
  Scaleform::String v13; // [rsp+38h] [rbp-50h] BYREF
  __int64 v14; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::LoadStates *v15; // [rsp+48h] [rbp-40h]
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+50h] [rbp-38h] BYREF

  v14 = -2i64;
  v7 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                        Scaleform::Memory::pGlobalHeap,
                                        144i64,
                                        0i64);
  v13.pData = v7;
  v8 = 0i64;
  if ( v7 )
  {
    Scaleform::GFx::LoadStates::LoadStates(
      (Scaleform::GFx::LoadStates *)v7,
      (Scaleform::GFx::Resource *)this,
      0i64,
      0i64);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v15 = v10;
  if ( (loadConstants & 0x40) != 0 )
    v10->ThreadedLoading = 1;
  if ( v10->pWeakResourceLib.pObject )
  {
    Scaleform::String::String(&v13, &customCaption);
    Scaleform::String::String(&src, pfilename);
    loc.Use = File_Regular;
    Scaleform::String::String(&loc.FileName, &src);
    Scaleform::String::String(&loc.ParentPath, &v13);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v13.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v8 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v10, &loc, loadConstants, 0i64);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
  return v8;
}

// File Line: 539
// RVA: 0x8FE590
void __fastcall Scaleform::GFx::LoaderImpl::RegisterLoadProcess(
        Scaleform::GFx::LoaderImpl *this,
        Scaleform::GFx::LoaderTask *ptask)
{
  Scaleform::Lock *p_LoadProcessesLock; // rbx
  __int64 v5; // rax
  Scaleform::GFx::LoadProcessNode *v6; // rdx

  p_LoadProcessesLock = &this->LoadProcessesLock;
  EnterCriticalSection(&this->LoadProcessesLock.cs);
  v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
         Scaleform::Memory::pGlobalHeap,
         24i64);
  v6 = (Scaleform::GFx::LoadProcessNode *)v5;
  if ( v5 )
    *(_QWORD *)(v5 + 16) = ptask;
  else
    v6 = 0i64;
  v6->pPrev = this->LoadProcesses.Root.pPrev;
  v6->pNext = (Scaleform::GFx::LoadProcessNode *)&this->LoadProcesses;
  this->LoadProcesses.Root.pPrev->pNext = v6;
  this->LoadProcesses.Root.pPrev = v6;
  LeaveCriticalSection(&p_LoadProcessesLock->cs);
}

// File Line: 547
// RVA: 0x914AD0
void __fastcall Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(
        Scaleform::GFx::LoaderImpl *this,
        Scaleform::GFx::LoaderTask *ptask)
{
  Scaleform::Lock *p_LoadProcessesLock; // rbx
  Scaleform::GFx::LoadProcessNode *pNext; // rdx
  Scaleform::List<Scaleform::GFx::LoadProcessNode,Scaleform::GFx::LoadProcessNode> *p_LoadProcesses; // rdi

  p_LoadProcessesLock = &this->LoadProcessesLock;
  EnterCriticalSection(&this->LoadProcessesLock.cs);
  pNext = this->LoadProcesses.Root.pNext;
  p_LoadProcesses = &this->LoadProcesses;
  if ( pNext != (Scaleform::GFx::LoadProcessNode *)p_LoadProcesses )
  {
    while ( pNext->pTask != ptask )
    {
      pNext = pNext->pNext;
      if ( pNext == (Scaleform::GFx::LoadProcessNode *)p_LoadProcesses )
        goto LABEL_6;
    }
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->Scaleform::ListNode<Scaleform::GFx::LoadProcessNode>::$0861A8559105305CCDC6716106EB6AA5::pPrev = pNext->pPrev;
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
LABEL_6:
  LeaveCriticalSection(&p_LoadProcessesLock->cs);
}

// File Line: 564
// RVA: 0x8B9750
void __fastcall Scaleform::GFx::LoaderImpl::CancelLoading(Scaleform::GFx::LoaderImpl *this)
{
  Scaleform::GFx::LoaderImpl *i; // rdi
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::Lock *p_LoadProcessesLock; // [rsp+58h] [rbp+10h]

  Scaleform::GFx::StateBag::GetTaskManager(&this->pStateBag.pObject->Scaleform::GFx::StateBag, &result);
  if ( result.pObject )
  {
    p_LoadProcessesLock = &this->LoadProcessesLock;
    EnterCriticalSection(&this->LoadProcessesLock.cs);
    for ( i = (Scaleform::GFx::LoaderImpl *)this->LoadProcesses.Root.pNext;
          i != (Scaleform::GFx::LoaderImpl *)&this->LoadProcesses;
          i = (Scaleform::GFx::LoaderImpl *)this->LoadProcesses.Root.pNext )
    {
      i->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor = *(void *(__fastcall **)(Scaleform::RefCountImplCore *, unsigned int))&i->RefCount;
      **(_QWORD **)&i->RefCount = i->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
      result.pObject->vfptr[2].__vecDelDtor(result.pObject, (unsigned int)i->Scaleform::GFx::StateBag::vfptr);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, i);
    }
    LeaveCriticalSection(&this->LoadProcessesLock.cs);
  }
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 607
// RVA: 0x89B320
void __fastcall Scaleform::GFx::MovieImageLoadTask::MovieImageLoadTask(
        Scaleform::GFx::MovieImageLoadTask *this,
        Scaleform::GFx::MovieDataDef *pdef,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::Resource *pin,
        Scaleform::GFx::FileTypeConstants::FileFormatType format,
        Scaleform::GFx::Resource *pls)
{
  Scaleform::GFx::LoaderTask::LoaderTask(this, pls, Id_MovieImageLoad);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieImageLoadTask::`vftable;
  if ( pdef )
    _InterlockedExchangeAdd(&pdef->RefCount.Value, 1u);
  this->pDef.pObject = pdef;
  if ( pdefImpl )
    _InterlockedExchangeAdd(&pdefImpl->RefCount.Value, 1u);
  this->pDefImpl.pObject = pdefImpl;
  if ( pin )
    Scaleform::Render::RenderBuffer::AddRef(pin);
  this->pImageFile.pObject = (Scaleform::File *)pin;
  this->ImageFormat = format;
  this->pImageRes.pObject = 0i64;
}

// File Line: 610
// RVA: 0x8C9B70
void __fastcall Scaleform::GFx::MovieImageLoadTask::Execute(Scaleform::GFx::MovieImageLoadTask *this)
{
  Scaleform::GFx::LoadStates *pObject; // rdx
  Scaleform::GFx::ImageCreator *pimageHeap; // rdi
  Scaleform::GFx::LogState *v4; // rax
  Scaleform::Log *plog; // rax
  Scaleform::Render::ImageSource *BuiltinImage; // r15
  Scaleform::GFx::ImageResource *v7; // rax
  Scaleform::GFx::ImageResource *v8; // rax
  Scaleform::GFx::ImageResource *v9; // rsi
  Scaleform::GFx::ImageResource *v10; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::File *v12; // r13
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *ImageCreator; // rsi
  Scaleform::GFx::LogState *v14; // r12
  Scaleform::Log *GlobalLog; // r12
  Scaleform::GFx::ImageCreator *v16; // rsi
  Scaleform::GFx::ImageResource *v17; // rbp
  Scaleform::GFx::MovieDataDef *v18; // rdi
  unsigned int v19; // eax
  bool inited; // di
  Scaleform::GFx::MovieDataDef *v21; // rcx
  unsigned int FileLength; // ebx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v23; // rdi
  volatile unsigned int v24; // eax
  unsigned int v25; // edx
  Scaleform::GFx::ImageResource *v26; // rdi
  Scaleform::GFx::ResourceLibBase *v27; // rcx
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> result; // [rsp+88h] [rbp+10h] BYREF
  Scaleform::GFx::ImageResource *v29; // [rsp+90h] [rbp+18h]

  pObject = this->pLoadStates.pObject;
  pimageHeap = (Scaleform::GFx::ImageCreator *)pObject->pWeakResourceLib.pObject->pImageHeap.pObject;
  result.pObject = pimageHeap;
  v4 = pObject->pLog.pObject;
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
  BuiltinImage = Scaleform::GFx::LoaderImpl::LoadBuiltinImage(
                   this->pImageFile.pObject,
                   this->ImageFormat,
                   Use_Bitmap,
                   this->pLoadStates.pObject,
                   plog,
                   (Scaleform::MemoryHeap *)pimageHeap);
  if ( BuiltinImage )
  {
    v7 = (Scaleform::GFx::ImageResource *)pimageHeap->vfptr[10].__vecDelDtor(pimageHeap, 104u);
    v29 = v7;
    if ( v7 )
    {
      Scaleform::GFx::ImageResource::ImageResource(v7, BuiltinImage, Use_Bitmap);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    v10 = this->pImageRes.pObject;
    if ( v10 && !_InterlockedDecrement(&v10->RefCount.Value) )
    {
      pLib = v10->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v10);
        v10->pLib = 0i64;
      }
      v10->vfptr->__vecDelDtor(v10, 1u);
    }
    this->pImageRes.pObject = v9;
  }
  if ( !this->pImageRes.pObject )
  {
    v25 = 4;
    goto LABEL_31;
  }
  v12 = this->pImageFile.pObject;
  ImageCreator = Scaleform::GFx::StateBag::GetImageCreator(&this->pDefImpl.pObject->Scaleform::GFx::StateBag, &result);
  v14 = this->pLoadStates.pObject->pLog.pObject;
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
  v16 = ImageCreator->pObject;
  v17 = this->pImageRes.pObject;
  v18 = this->pDef.pObject;
  v19 = ((__int64 (__fastcall *)(Scaleform::File *))v12->vfptr[6].__vecDelDtor)(v12);
  inited = Scaleform::GFx::MovieDataDef::LoadTaskData::InitImageFileMovieDef(
             v18->pData.pObject,
             v19,
             v17,
             v16,
             GlobalLog,
             1);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( inited )
  {
    v21 = this->pDef.pObject;
    FileLength = v21->pData.pObject->Header.FileLength;
    v23 = this->pDefImpl.pObject->pBindData.pObject;
    v24 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieDataDef *))v21->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr[4].__vecDelDtor)(v21);
    v23->BytesLoaded = FileLength;
    v23->BindingFrame = v24;
    v25 = 770;
LABEL_31:
    Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(this->pDefImpl.pObject->pBindData.pObject, v25);
    goto LABEL_32;
  }
  Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(this->pDefImpl.pObject->pBindData.pObject, 4u);
  v26 = this->pImageRes.pObject;
  if ( v26 && !_InterlockedDecrement(&v26->RefCount.Value) )
  {
    v27 = v26->pLib;
    if ( v27 )
    {
      v27->vfptr[1].__vecDelDtor(v27, (unsigned int)v26);
      v26->pLib = 0i64;
    }
    v26->vfptr->__vecDelDtor(v26, 1u);
  }
  this->pImageRes.pObject = 0i64;
LABEL_32:
  if ( BuiltinImage )
    ((void (__fastcall *)(Scaleform::Render::ImageSource *))BuiltinImage->vfptr[2].__vecDelDtor)(BuiltinImage);
}

// File Line: 683
// RVA: 0x8C15B0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
        Scaleform::GFx::LoadStates *pls,
        Scaleform::GFx::URLBuilder::LocationInfo *loc,
        unsigned int loadConstants,
        Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack)
{
  Scaleform::GFx::URLBuilder *pObject; // rcx
  Scaleform::GFx::LogState *v8; // r12
  Scaleform::Render::RenderBuffer *v9; // rsi
  Scaleform::GFx::LoadProcess *v10; // rdi
  Scaleform::Render::RenderBuffer *v11; // r14
  Scaleform::GFx::MovieDefBindStates *v12; // rax
  unsigned int v13; // ecx
  Scaleform::GFx::Resource *v14; // r15
  __int64 v15; // rax
  Scaleform::Render::RenderBuffer *v16; // rax
  Scaleform::String::DataDesc *v17; // rdx
  Scaleform::GFx::MovieDataDef::MovieDataType v18; // r12d
  unsigned __int64 v19; // rbx
  Scaleform::GFx::MovieDataDef *v20; // rax
  Scaleform::GFx::MovieDataDef *v21; // rbx
  Scaleform::String::DataDesc *pData; // r12
  Scaleform::GFx::LoadProcess *v23; // rax
  Scaleform::Render::RenderBuffer **v24; // r9
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  char v26; // al
  Scaleform::String::DataDesc *MovieDefImpl; // rdx
  Scaleform::GFx::MovieDefImpl *v28; // r12
  Scaleform::GFx::Resource *v29; // rax
  const char *v30; // r8
  Scaleform::Render::RenderBuffer **v31; // r9
  Scaleform::String::DataDesc *v32; // rax
  unsigned __int64 Size; // rcx
  Scaleform::GFx::MovieImageLoadTask *v34; // rax
  Scaleform::GFx::MovieImageLoadTask *v35; // r12
  unsigned __int64 v36; // rcx
  Scaleform::GFx::ImageCreator *v37; // rbx
  __int64 v38; // rcx
  Scaleform::GFx::Resource *pResource; // rbx
  Scaleform::GFx::ResourceLibBase *v40; // rcx
  Scaleform::String ppath; // [rsp+8h] [rbp-61h] BYREF
  Scaleform::String v43; // [rsp+10h] [rbp-59h] BYREF
  Scaleform::Render::RenderBuffer *v44; // [rsp+18h] [rbp-51h] BYREF
  Scaleform::GFx::ImageCreator *pimageCreator; // [rsp+20h] [rbp-49h]
  Scaleform::GFx::ImageCreator *v46; // [rsp+28h] [rbp-41h]
  Scaleform::Render::RenderBuffer *v47; // [rsp+30h] [rbp-39h]
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [rsp+38h] [rbp-31h] BYREF
  Scaleform::Render::RenderBuffer *v49; // [rsp+48h] [rbp-21h]
  Scaleform::String v50; // [rsp+50h] [rbp-19h] BYREF
  Scaleform::String v51; // [rsp+58h] [rbp-11h] BYREF
  void *v52; // [rsp+60h] [rbp-9h]
  Scaleform::GFx::ResourceKey result; // [rsp+68h] [rbp-1h] BYREF
  __int64 v54; // [rsp+78h] [rbp+Fh]
  Scaleform::MemoryHeap *v55; // [rsp+80h] [rbp+17h]
  Scaleform::String v56; // [rsp+C8h] [rbp+5Fh] BYREF
  char v57; // [rsp+D8h] [rbp+6Fh]
  Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStacka; // [rsp+E0h] [rbp+77h]
  unsigned __int64 v59; // [rsp+E8h] [rbp+7Fh]

  v54 = -2i64;
  Scaleform::String::String((Scaleform::String *)&phandle.8);
  pObject = pls->pBindStates.pObject->pURLBulider.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::GFx::URLBuilder *, Scaleform::String *, Scaleform::GFx::URLBuilder::LocationInfo *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
      &ppath,
      loc);
  else
    Scaleform::GFx::URLBuilder::DefaultBuildURL(&ppath, loc);
  phandle.State = RS_Unbound;
  phandle.pResource = 0i64;
  pimageCreator = 0i64;
  v43.pData = 0i64;
  v8 = pls->pLog.pObject;
  v57 = 0;
  v9 = 0i64;
  v44 = 0i64;
  v10 = 0i64;
  v47 = 0i64;
  v11 = 0i64;
  v49 = 0i64;
  LODWORD(v50.pData) = 0;
  v12 = pls->pBindStates.pObject;
  if ( v12->pImagePackParams.pObject )
    loadConstants |= 0x11u;
  v13 = loadConstants >> 4;
  LOBYTE(v13) = (loadConstants & 0x10) == 0;
  LODWORD(v51.pData) = v13;
  v46 = 0i64;
  if ( (loadConstants & 0x80u) == 0 && v12->pImageCreator.pObject )
    v46 = v12->pImageCreator.pObject;
  v14 = (Scaleform::GFx::Resource *)v12->pFileOpener.pObject;
  if ( v14 )
    v15 = ((__int64 (__fastcall *)(Scaleform::GFx::Resource *, unsigned __int64))v14->vfptr->GetResourceTypeCode)(
            v14,
            (ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  else
    v15 = 0i64;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(
    &result,
    (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    v15,
    v14,
    v46);
  if ( (unsigned int)Scaleform::GFx::ResourceWeakLib::BindResourceKey(pls->pWeakResourceLib.pObject, &phandle, &result) != 3 )
  {
    v29 = Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&phandle);
    v21 = (Scaleform::GFx::MovieDataDef *)v29;
    pimageCreator = (Scaleform::GFx::ImageCreator *)v29;
    if ( v29 )
    {
      LODWORD(v46) = v29[2].RefCount.Value;
      pData = v56.pData;
      Scaleform::String::operator=(
        (Scaleform::String *)&v56.pData[6].RefCount,
        (const char *)((*(_QWORD *)&v29[2].pLib[4].RefCount & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( !Scaleform::GFx::URLBuilder::ExtractFilePath((Scaleform::String *)&pData[6].RefCount) )
        Scaleform::String::Clear((Scaleform::String *)&pData[6].RefCount);
LABEL_62:
      v31 = &v44;
      if ( (_DWORD)v46 != 1 )
        v31 = 0i64;
      MovieDefImpl = (Scaleform::String::DataDesc *)Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
                                                      (Scaleform::GFx::Resource *)pData,
                                                      v21,
                                                      loadConstants,
                                                      (Scaleform::GFx::MovieBindProcess **)v31,
                                                      0,
                                                      ploadStacka,
                                                      v59);
      v43.pData = MovieDefImpl;
      v9 = v44;
      v26 = v57;
LABEL_65:
      if ( MovieDefImpl )
      {
        if ( v26 )
        {
LABEL_68:
          if ( (_DWORD)v46 == 1 )
          {
            v32 = (Scaleform::String::DataDesc *)v9;
            if ( (loadConstants & 0x10) != 0 )
              v32 = 0i64;
            v56.pData = v32;
            if ( v32 )
              Scaleform::GFx::LoadProcess::SetBindProcess(v10, (Scaleform::GFx::MovieBindProcess *)v32);
            if ( v9 )
              v10->pTempBindData = (Scaleform::GFx::TempBindData *)v9[1].BufferSize;
            if ( (loadConstants & 1) != 0
              || (Size = pData[3].Size) == 0
              || !(*(unsigned __int8 (__fastcall **)(unsigned __int64, Scaleform::GFx::LoadProcess *))(*(_QWORD *)Size + 8i64))(
                    Size,
                    v10) )
            {
              v10->Scaleform::GFx::LoaderTask::Scaleform::GFx::Task::Scaleform::RefCountBase<Scaleform::GFx::Task,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor(
                v10,
                (unsigned int)MovieDefImpl);
            }
            if ( v56.pData )
            {
              if ( v9 )
                Scaleform::RefCountImpl::Release(v9);
              v9 = 0i64;
              v44 = 0i64;
            }
            if ( v10 )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
            v10 = 0i64;
            v47 = 0i64;
            if ( v11 )
              Scaleform::RefCountImpl::Release(v11);
            v11 = 0i64;
            v49 = 0i64;
          }
          else
          {
            v34 = (Scaleform::GFx::MovieImageLoadTask *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                          Scaleform::Memory::pGlobalHeap,
                                                          72i64);
            v52 = v34;
            if ( v34 )
              Scaleform::GFx::MovieImageLoadTask::MovieImageLoadTask(
                v34,
                v21,
                (Scaleform::GFx::MovieDefImpl *)v43.pData,
                (Scaleform::GFx::Resource *)v11,
                (Scaleform::GFx::FileTypeConstants::FileFormatType)v50.pData,
                (Scaleform::GFx::Resource *)pData);
            v35 = v34;
            v52 = v34;
            if ( (loadConstants & 0x11) != 0
              || (v36 = v56.pData[3].Size) == 0
              || !(*(unsigned __int8 (__fastcall **)(unsigned __int64, Scaleform::GFx::MovieImageLoadTask *))(*(_QWORD *)v36 + 8i64))(
                    v36,
                    v34) )
            {
              ((void (__fastcall *)(Scaleform::GFx::MovieImageLoadTask *))v35->vfptr[1].__vecDelDtor)(v35);
              if ( !v35->pImageRes.pObject )
              {
                if ( v43.pData )
                  Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v43.pData);
                Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v35);
                v28 = 0i64;
                goto LABEL_101;
              }
            }
            if ( v35 )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v35);
            pData = v56.pData;
          }
        }
        v28 = Scaleform::GFx::LoaderImpl::BindMovieAndWait(
                (Scaleform::GFx::MovieDefImpl *)v43.pData,
                (Scaleform::GFx::MovieBindProcess *)v9,
                (Scaleform::GFx::LoadStates *)pData,
                loadConstants,
                ploadStacka);
        goto LABEL_101;
      }
    }
    else if ( v8 )
    {
      if ( phandle.State < RS_WaitingResolve )
        v30 = &customCaption;
      else
        v30 = (const char *)((*(_QWORD *)&phandle.pResource[2].RefCount.Value & 0xFFFFFFFFFFFFFFFCui64) + 12);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        &v8->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "%s",
        v30);
    }
LABEL_66:
    v28 = 0i64;
    goto LABEL_101;
  }
  if ( !Scaleform::GFx::URLBuilder::IsProtocol(&ppath) )
  {
    v16 = (Scaleform::Render::RenderBuffer *)Scaleform::GFx::LoadStates::OpenFile(
                                               pls,
                                               (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                                               loadConstants);
    v11 = v16;
    v49 = v16;
    if ( v16 )
    {
      LODWORD(v50.pData) = Scaleform::GFx::LoaderImpl::DetectFileFormat((Scaleform::File *)v16);
      switch ( LODWORD(v50.pData) )
      {
        case 2:
          if ( (loadConstants & 0x80000) == 0 )
            goto $LN34_19;
          Scaleform::String::String(
            &v56,
            "Failed loading SWF file \"",
            (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
            "\" - GFX file format expected");
          if ( v8 )
            Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
              &v8->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
              "%s",
              (const char *)((v56.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
          Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
            phandle.pSlot,
            (const char *)((v56.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
          v17 = v56.pData;
          goto LABEL_50;
        case 3:
$LN34_19:
          v18 = MT_Flash;
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
          if ( (loadConstants & 0x10000) == 0 )
            goto LABEL_47;
          v18 = MT_Image;
LABEL_23:
          LODWORD(v46) = v18;
          v19 = ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
          v55 = Scaleform::Memory::pGlobalHeap;
          v20 = (Scaleform::GFx::MovieDataDef *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  72i64);
          v52 = v20;
          if ( v20 )
            Scaleform::GFx::MovieDataDef::MovieDataDef(
              v20,
              &result,
              v18,
              (const char *)(v19 + 12),
              0i64,
              (loadConstants & 0x10000000) != 0,
              v59);
          v21 = v20;
          pimageCreator = (Scaleform::GFx::ImageCreator *)v20;
          if ( !v20 )
            goto LABEL_44;
          pData = v56.pData;
          Scaleform::GFx::LoadStates::SetRelativePathForDataDef((Scaleform::GFx::LoadStates *)v56.pData, v20);
          if ( (_DWORD)v46 != 1 )
          {
            v24 = 0i64;
            goto LABEL_40;
          }
          v23 = (Scaleform::GFx::LoadProcess *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 1056i64,
                                                 0i64);
          v52 = v23;
          if ( v23 )
            Scaleform::GFx::LoadProcess::LoadProcess(v23, v21, (Scaleform::GFx::LoadStates *)pData, loadConstants);
          v10 = v23;
          v47 = (Scaleform::Render::RenderBuffer *)v23;
          if ( !v23 )
          {
LABEL_34:
            v47 = 0i64;
            if ( !_InterlockedDecrement(&v21->RefCount.Value) )
            {
              pLib = v21->pLib;
              if ( pLib )
              {
                pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v21);
                v21->pLib = 0i64;
              }
              v21->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(
                v21,
                1u);
            }
            pimageCreator = 0i64;
LABEL_44:
            Scaleform::String::String(
              &v50,
              "Failed to load SWF file \"",
              (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
              "\"\n");
            Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
              phandle.pSlot,
              (const char *)((v50.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v50.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v21 = (Scaleform::GFx::MovieDataDef *)pimageCreator;
            v9 = v44;
            v10 = (Scaleform::GFx::LoadProcess *)v47;
            v11 = v49;
            goto LABEL_66;
          }
          if ( !Scaleform::GFx::LoadProcess::BeginSWFLoading(v23, (Scaleform::File *)v11) )
          {
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
            goto LABEL_34;
          }
          if ( LOBYTE(v51.pData) )
          {
            v24 = &v44;
LABEL_40:
            v43.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
                                                         (Scaleform::GFx::Resource *)pData,
                                                         v21,
                                                         loadConstants,
                                                         (Scaleform::GFx::MovieBindProcess **)v24,
                                                         1,
                                                         ploadStacka,
                                                         v59);
            v9 = v44;
          }
          Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, v21);
          v26 = 1;
          v57 = 1;
          MovieDefImpl = v43.pData;
          if ( LOBYTE(v51.pData) )
            goto LABEL_65;
          if ( !v43.pData )
            goto LABEL_62;
          goto LABEL_68;
        default:
LABEL_47:
          Scaleform::String::String(
            &v43,
            "Unknown file format at URL \"",
            (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
            "\"");
          if ( v8 )
            Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
              &v8->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
              "%s",
              (const char *)((v43.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
          Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
            phandle.pSlot,
            (const char *)((v43.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
          v17 = v43.pData;
          goto LABEL_50;
      }
    }
  }
  Scaleform::String::String(
    &v51,
    "Loader failed to open \"",
    (const char *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    "\"\n");
  Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
    phandle.pSlot,
    (const char *)((v51.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  v17 = v51.pData;
LABEL_50:
  if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v17 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v28 = 0i64;
  v21 = (Scaleform::GFx::MovieDataDef *)pimageCreator;
  v9 = v44;
  v10 = (Scaleform::GFx::LoadProcess *)v47;
  v11 = v49;
LABEL_101:
  if ( result.pKeyInterface )
    result.pKeyInterface->vfptr->Release(result.pKeyInterface, result.hKeyData);
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  if ( v10 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  if ( v21 && !_InterlockedDecrement(&v21->RefCount.Value) )
  {
    v37 = pimageCreator;
    v38 = *(_QWORD *)&pimageCreator->SType;
    if ( v38 )
    {
      (*(void (__fastcall **)(__int64, Scaleform::GFx::ImageCreator *))(*(_QWORD *)v38 + 8i64))(v38, pimageCreator);
      *(_QWORD *)&v37->SType = 0i64;
    }
    v37->vfptr->__vecDelDtor(v37, 1u);
  }
  if ( phandle.State == RS_Available )
  {
    if ( !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
    {
      pResource = phandle.pResource;
      v40 = phandle.pResource->pLib;
      if ( v40 )
      {
        v40->vfptr[1].__vecDelDtor(v40, (unsigned int)phandle.pResource);
        pResource->pLib = 0i64;
      }
      pResource->vfptr->__vecDelDtor(pResource, 1u);
    }
  }
  else if ( phandle.State >= RS_WaitingResolve )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)phandle.pResource);
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v28;
}

// File Line: 994
// RVA: 0x8C1E10
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
        Scaleform::GFx::LoadStates *pls,
        Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *bytes,
        unsigned int loadConstants,
        Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack)
{
  const void *ProfileTicks; // r15
  Scaleform::Render::RenderBuffer *v8; // r12
  Scaleform::GFx::LogState *pObject; // rdi
  Scaleform::Render::RenderBuffer *v10; // rbx
  Scaleform::MemoryFile *v11; // rax
  Scaleform::Render::RenderBuffer *v12; // rax
  unsigned __int64 HeapTypeBits; // rdx
  Scaleform::GFx::MovieDataDef::MovieDataType v14; // r15d
  Scaleform::GFx::MovieDataDef *v15; // rax
  Scaleform::GFx::MovieDataDef *v16; // rax
  Scaleform::GFx::MovieDataDef *v17; // rdi
  Scaleform::String *p_RelativePath; // r13
  Scaleform::GFx::LoadProcess *v19; // rax
  Scaleform::GFx::Resource *pData; // r13
  Scaleform::Render::RenderBuffer *v21; // rax
  Scaleform::Render::RenderBuffer **v22; // r9
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::Render::RenderBuffer *v24; // rdi
  Scaleform::Render::RenderBuffer *v25; // r15
  Scaleform::GFx::ResourceVtbl *vfptr; // rcx
  Scaleform::GFx::MovieImageLoadTask *v27; // rax
  Scaleform::String::DataDesc *v28; // r15
  Scaleform::GFx::MovieImageLoadTask *v29; // rdi
  Scaleform::GFx::ResourceVtbl *v30; // rcx
  Scaleform::GFx::MovieDefImpl *v31; // r14
  __int64 v32; // rbx
  Scaleform::GFx::ResourceLibBase *v33; // rcx
  Scaleform::GFx::ResourceLib::ResourceSlot *v34; // rbx
  Scaleform::GFx::ResourceWeakLib *v35; // rcx
  Scaleform::Render::RenderBuffer *v37; // [rsp+40h] [rbp-88h] BYREF
  Scaleform::Render::RenderBuffer *v38; // [rsp+48h] [rbp-80h]
  Scaleform::GFx::ResourceKey result; // [rsp+50h] [rbp-78h] BYREF
  Scaleform::GFx::ResourceLib::ResourceSlot *v40; // [rsp+60h] [rbp-68h]
  char dest[8]; // [rsp+68h] [rbp-60h] BYREF
  Scaleform::GFx::MovieDataDef *v42; // [rsp+70h] [rbp-58h]
  void *v43; // [rsp+78h] [rbp-50h]
  Scaleform::String v44; // [rsp+128h] [rbp+60h] BYREF
  Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStacka; // [rsp+140h] [rbp+78h]
  unsigned __int64 v46; // [rsp+148h] [rbp+80h]

  ProfileTicks = (const void *)Scaleform::Timer::GetProfileTicks();
  Scaleform::SFsprintf(dest, 0x80ui64, "*Bytes@%p*", ProfileTicks);
  v8 = 0i64;
  LODWORD(result.hKeyData) = 0;
  v40 = 0i64;
  v42 = 0i64;
  pObject = pls->pLog.pObject;
  v37 = 0i64;
  v10 = 0i64;
  v38 = 0i64;
  if ( pls->pBindStates.pObject->pImagePackParams.pObject )
    loadConstants |= 0x11u;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(&result, dest, (__int64)ProfileTicks, 0i64, 0i64);
  Scaleform::GFx::ResourceWeakLib::BindResourceKey(
    pls->pWeakResourceLib.pObject,
    (Scaleform::GFx::ResourceLib::BindHandle *)&result.hKeyData,
    &result);
  v11 = (Scaleform::MemoryFile *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                   Scaleform::Memory::pGlobalHeap,
                                   48i64);
  *(_QWORD *)dest = v11;
  if ( v11 )
  {
    Scaleform::MemoryFile::MemoryFile(v11, dest, bytes->Data.Data, bytes->Data.Size);
    v8 = v12;
  }
  v38 = v8;
  LODWORD(result.pKeyInterface) = Scaleform::GFx::LoaderImpl::DetectFileFormat((Scaleform::File *)v8);
  switch ( 0x40000000u )
  {
    case 2u:
      if ( (loadConstants & 0x80000) == 0 )
        goto $LN25_40;
      Scaleform::String::String(&v44, "Failed loading SWF file \"", dest, "\" - GFX file format expected");
      if ( pObject )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "%s",
          (const char *)((v44.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        v40,
        (const char *)((v44.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      HeapTypeBits = v44.HeapTypeBits;
      goto LABEL_69;
    case 3u:
$LN25_40:
      v14 = MT_Flash;
      goto LABEL_13;
    case 0xAu:
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
    case 0x12u:
    case 0x13u:
    case 0x15u:
    case 0x16u:
    case 0x17u:
    case 0x18u:
      if ( (loadConstants & 0x10000) == 0 )
        goto LABEL_66;
      v14 = MT_Image;
LABEL_13:
      *(_QWORD *)dest = Scaleform::Memory::pGlobalHeap;
      v15 = (Scaleform::GFx::MovieDataDef *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              72i64);
      v43 = v15;
      if ( v15 )
      {
        Scaleform::GFx::MovieDataDef::MovieDataDef(
          v15,
          &result,
          v14,
          dest,
          0i64,
          (loadConstants & 0x10000000) != 0,
          v46);
        v17 = v16;
      }
      else
      {
        v17 = 0i64;
      }
      v42 = v17;
      if ( !v17 )
        goto LABEL_65;
      p_RelativePath = &pls->RelativePath;
      Scaleform::String::operator=(
        p_RelativePath,
        (const char *)((v17->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( !Scaleform::GFx::URLBuilder::ExtractFilePath(p_RelativePath) )
        Scaleform::String::Clear(p_RelativePath);
      if ( v14 == MT_Flash )
      {
        v19 = (Scaleform::GFx::LoadProcess *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               1056i64,
                                               0i64);
        v43 = v19;
        pData = (Scaleform::GFx::Resource *)v44.pData;
        if ( v19 )
        {
          Scaleform::GFx::LoadProcess::LoadProcess(v19, v17, (Scaleform::GFx::LoadStates *)v44.pData, loadConstants);
          v10 = v21;
        }
        else
        {
          v10 = 0i64;
        }
        v38 = v10;
        if ( !v10 )
        {
LABEL_27:
          v38 = 0i64;
          if ( !_InterlockedDecrement(&v17->RefCount.Value) )
          {
            pLib = v17->pLib;
            if ( pLib )
            {
              pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v17);
              v17->pLib = 0i64;
            }
            v17->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(
              v17,
              1u);
          }
          v42 = 0i64;
LABEL_65:
          Scaleform::String::String((Scaleform::String *)dest, "Failed to load SWF file \"", dest, "\"\n");
          Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
            v40,
            (const char *)((*(_QWORD *)dest & 0xFFFFFFFFFFFFFFFCui64) + 12));
          HeapTypeBits = *(_QWORD *)dest;
LABEL_69:
          if ( !_InterlockedDecrement((volatile signed __int32 *)((HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v10 = v38;
          goto LABEL_72;
        }
        if ( !Scaleform::GFx::LoadProcess::BeginSWFLoading((Scaleform::GFx::LoadProcess *)v10, (Scaleform::File *)v8) )
        {
          Scaleform::RefCountImpl::Release(v10);
          goto LABEL_27;
        }
        v22 = &v37;
      }
      else
      {
        v22 = 0i64;
        pData = (Scaleform::GFx::Resource *)v44.pData;
      }
      v44.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
                                                   pData,
                                                   v17,
                                                   loadConstants,
                                                   (Scaleform::GFx::MovieBindProcess **)v22,
                                                   1,
                                                   ploadStacka,
                                                   v46);
      Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(v40, v17);
      if ( !v44.pData )
        goto LABEL_72;
      if ( v14 == MT_Flash )
      {
        v24 = v37;
        v25 = v37;
        if ( (loadConstants & 0x10) != 0 )
          v25 = 0i64;
        if ( v25 )
          Scaleform::GFx::LoadProcess::SetBindProcess(
            (Scaleform::GFx::LoadProcess *)v10,
            (Scaleform::GFx::MovieBindProcess *)v25);
        if ( v24 )
          *(Scaleform::Render::Size<unsigned long> *)&v10[18].Type = v24[1].BufferSize;
        if ( (loadConstants & 1) != 0
          || (vfptr = pData[2].vfptr) == 0i64
          || !(*((unsigned __int8 (__fastcall **)(Scaleform::GFx::ResourceVtbl *, Scaleform::Render::RenderBuffer *))vfptr->__vecDelDtor
               + 1))(
                vfptr,
                v10) )
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
                (Scaleform::GFx::LoadStates *)pData,
                loadConstants,
                ploadStacka);
        goto LABEL_73;
      }
      v27 = (Scaleform::GFx::MovieImageLoadTask *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    72i64);
      v43 = v27;
      v28 = v44.pData;
      if ( v27 )
        Scaleform::GFx::MovieImageLoadTask::MovieImageLoadTask(
          v27,
          v17,
          (Scaleform::GFx::MovieDefImpl *)v44.pData,
          (Scaleform::GFx::Resource *)v8,
          (Scaleform::GFx::FileTypeConstants::FileFormatType)result.pKeyInterface,
          pData);
      v29 = v27;
      v43 = v27;
      if ( (loadConstants & 0x11) == 0
        && (v30 = pData[2].vfptr) != 0i64
        && (*((unsigned __int8 (__fastcall **)(Scaleform::GFx::ResourceVtbl *, Scaleform::GFx::MovieImageLoadTask *))v30->__vecDelDtor
            + 1))(
             v30,
             v27)
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
          v33->vfptr[1].__vecDelDtor(v33, (unsigned int)v42);
          *(_QWORD *)(v32 + 16) = 0i64;
        }
        (**(void (__fastcall ***)(__int64, __int64))v32)(v32, 1i64);
      }
      if ( LODWORD(result.hKeyData) == 1 )
      {
        if ( !_InterlockedDecrement(&v40->RefCount) )
        {
          v34 = v40;
          v35 = v40->pLib.pObject;
          if ( v35 )
          {
            v35->vfptr[1].__vecDelDtor(v35, (unsigned int)v40);
            v34->pLib.pObject = 0i64;
          }
          v34->vfptr->__vecDelDtor(v34, 1u);
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
      if ( pObject )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "%s",
          (const char *)(((unsigned __int64)result.pKeyInterface & 0xFFFFFFFFFFFFFFFCui64) + 12));
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        v40,
        (const char *)(((unsigned __int64)result.pKeyInterface & 0xFFFFFFFFFFFFFFFCui64) + 12));
      HeapTypeBits = (unsigned __int64)result.pKeyInterface;
      goto LABEL_69;
  }
}

// File Line: 1224
// RVA: 0x8B70C0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::BindMovieAndWait(
        Scaleform::GFx::MovieDefImpl *pm,
        Scaleform::GFx::MovieBindProcess *pbp,
        Scaleform::GFx::LoadStates *pls,
        char loadConstants,
        Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack)
{
  Scaleform::GFx::TaskManager *pObject; // rcx
  Scaleform::GFx::LoaderImpl::LoadStackItem *v10; // rdi
  Scaleform::GFx::LoaderImpl::LoadStackItem *v11; // rax
  const char *v12; // rax
  const char *v13; // rax
  char *pData; // r8
  unsigned int v15; // edx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::StringBuffer v18; // [rsp+28h] [rbp-40h] BYREF

  if ( pbp )
  {
    if ( (loadConstants & 1) != 0
      || (pObject = pls->pTaskManager.pObject) == 0i64
      || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::TaskManager *))pObject->vfptr[1].__vecDelDtor)(pObject) )
    {
      ((void (__fastcall *)(Scaleform::GFx::MovieBindProcess *))pbp->vfptr[1].__vecDelDtor)(pbp);
    }
  }
  v10 = ploadStack;
  v11 = ploadStack;
  if ( ploadStack )
  {
    while ( v11->pDefImpl != pm )
    {
      v11 = v11->pNext;
      if ( !v11 )
        goto LABEL_17;
    }
    if ( v11->pNext )
    {
      if ( pls->pLog.pObject )
      {
        Scaleform::StringBuffer::StringBuffer(&v18, Scaleform::Memory::pGlobalHeap);
        do
        {
          v12 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v10->pDefImpl->vfptr[3].__vecDelDtor)(v10->pDefImpl);
          Scaleform::StringBuffer::AppendString(&v18, v12, -1i64);
          Scaleform::StringBuffer::AppendChar(&v18, 0xAu);
          v10 = v10->pNext;
        }
        while ( v10 );
        v13 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))pm->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[3].__vecDelDtor)(pm);
        Scaleform::StringBuffer::AppendString(&v18, v13, -1i64);
        pData = &customCaption;
        if ( v18.pData )
          pData = v18.pData;
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &pls->pLog.pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "Recursive import detected. Import stack:\n%s",
          pData);
        Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v18);
      }
      goto LABEL_22;
    }
    return pm;
  }
LABEL_17:
  if ( (loadConstants & 1) != 0 )
  {
    v15 = 512;
  }
  else
  {
    if ( (loadConstants & 2) == 0 )
      return pm;
    v15 = 256;
  }
  if ( Scaleform::GFx::MovieDefImpl::BindTaskData::WaitForBindStateFlags(pm->pBindData.pObject, v15) )
    return pm;
LABEL_22:
  if ( _InterlockedExchangeAdd(&pm->RefCount.Value, 0xFFFFFFFF) == 1 )
  {
    pLib = pm->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pm);
      pm->pLib = 0i64;
    }
    pm->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(pm, 1i64);
  }
  return 0i64;
}

// File Line: 1310
// RVA: 0x8C11D0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(
        Scaleform::GFx::Resource *pls,
        Scaleform::GFx::MovieDataDef *pmd,
        unsigned int loadConstants,
        Scaleform::GFx::MovieBindProcess **ppbindProcess,
        bool checkCreate,
        Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack,
        unsigned __int64 memoryArena)
{
  Scaleform::GFx::MovieDefBindStates *pLib; // rdi
  Scaleform::String::DataDesc *v12; // rax
  Scaleform::GFx::MovieDefImpl *v13; // rax
  Scaleform::GFx::MovieDefImpl *v14; // rdi
  Scaleform::String::DataDesc *v15; // rax
  Scaleform::GFx::MovieBindProcess *v16; // rax
  Scaleform::GFx::LogState *vfptr; // rcx
  const char *v18; // r8
  Scaleform::GFx::Resource *pResource; // rbx
  Scaleform::GFx::ResourceLibBase *v20; // rcx
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [rsp+60h] [rbp-48h] BYREF
  Scaleform::GFx::ResourceKey k; // [rsp+70h] [rbp-38h] BYREF
  Scaleform::String v24; // [rsp+B0h] [rbp+8h] BYREF

  phandle.State = RS_Unbound;
  phandle.pResource = 0i64;
  pLib = (Scaleform::GFx::MovieDefBindStates *)pls->pLib;
  Scaleform::GFx::MovieDefImpl::CreateMovieKey(&k, pmd, pLib);
  if ( (unsigned int)Scaleform::GFx::ResourceWeakLib::BindResourceKey(
                       (Scaleform::GFx::ResourceWeakLib *)pls[3].pLib,
                       &phandle,
                       &k) == 3 )
  {
    v12 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           112i64,
                                           0i64);
    v24.pData = v12;
    if ( v12 )
    {
      Scaleform::GFx::MovieDefImpl::MovieDefImpl(
        (Scaleform::GFx::MovieDefImpl *)v12,
        pmd,
        (Scaleform::GFx::Resource *)pLib,
        (Scaleform::GFx::Resource *)pls[4].vfptr,
        loadConstants,
        (Scaleform::GFx::StateBagImpl *)pls[4].vfptr[1].__vecDelDtor,
        Scaleform::Memory::pGlobalHeap,
        0,
        memoryArena);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    if ( !ppbindProcess )
      goto LABEL_12;
    v15 = (Scaleform::String::DataDesc *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                           Scaleform::Memory::pGlobalHeap,
                                           96i64);
    v24.pData = v15;
    if ( v15 )
      Scaleform::GFx::MovieBindProcess::MovieBindProcess((Scaleform::GFx::MovieBindProcess *)v15, pls, v14, ploadStack);
    else
      v16 = 0i64;
    *ppbindProcess = v16;
    if ( v16 )
    {
LABEL_12:
      if ( v14 )
      {
        Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, v14);
        goto LABEL_23;
      }
    }
    else if ( v14 )
    {
      Scaleform::GFx::Resource::Release(v14);
    }
    Scaleform::String::String(
      &v24,
      "Failed to bind SWF file \"",
      (const char *)((pmd->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
      "\"\n");
    Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
      phandle.pSlot,
      (const char *)((v24.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v24.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  else
  {
    v14 = (Scaleform::GFx::MovieDefImpl *)Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&phandle);
    if ( v14 )
      goto LABEL_23;
    vfptr = (Scaleform::GFx::LogState *)pls[1].vfptr;
    if ( vfptr )
    {
      if ( phandle.State < RS_WaitingResolve )
        v18 = &customCaption;
      else
        v18 = (const char *)((*(_QWORD *)&phandle.pResource[2].RefCount.Value & 0xFFFFFFFFFFFFFFFCui64) + 12);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        &vfptr->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "%s",
        v18);
    }
  }
  v14 = 0i64;
LABEL_23:
  if ( k.pKeyInterface )
    k.pKeyInterface->vfptr->Release(k.pKeyInterface, k.hKeyData);
  if ( phandle.State == RS_Available )
  {
    if ( !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
    {
      pResource = phandle.pResource;
      v20 = phandle.pResource->pLib;
      if ( v20 )
      {
        v20->vfptr[1].__vecDelDtor(v20, (unsigned int)phandle.pResource);
        pResource->pLib = 0i64;
      }
      pResource->vfptr->__vecDelDtor(pResource, 1u);
    }
  }
  else if ( phandle.State >= RS_WaitingResolve )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)phandle.pResource);
  }
  return v14;
}

// File Line: 1395
// RVA: 0x8C2480
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
        Scaleform::GFx::Resource *pls,
        Scaleform::GFx::MovieDataDef *pmd,
        unsigned int loadConstants,
        unsigned __int64 memoryArena)
{
  Scaleform::GFx::MovieDefImpl *v8; // rdi
  Scaleform::GFx::MovieDefImpl *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rbx
  Scaleform::GFx::MovieBindProcess *ppbindProcess; // [rsp+88h] [rbp+10h] BYREF

  if ( pmd )
  {
    Scaleform::String::operator=(
      (Scaleform::String *)&pls[4].RefCount,
      (const char *)((pmd->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    if ( !Scaleform::GFx::URLBuilder::ExtractFilePath((Scaleform::String *)&pls[4].RefCount) )
      Scaleform::String::Clear((Scaleform::String *)&pls[4].RefCount);
  }
  v8 = 0i64;
  ppbindProcess = 0i64;
  v9 = Scaleform::GFx::LoaderImpl::CreateMovieDefImpl(pls, pmd, loadConstants, &ppbindProcess, 0, 0i64, memoryArena);
  v10 = (Scaleform::Render::RenderBuffer *)ppbindProcess;
  if ( v9 )
    v8 = Scaleform::GFx::LoaderImpl::BindMovieAndWait(
           v9,
           ppbindProcess,
           (Scaleform::GFx::LoadStates *)pls,
           loadConstants,
           0i64);
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  return v8;
}

// File Line: 1412
// RVA: 0x8CB2E0
__int64 __fastcall Scaleform::GFx::LoaderImpl::FileFormat2RenderImageFile(
        Scaleform::GFx::FileTypeConstants::FileFormatType format)
{
  __int64 result; // rax

  switch ( format )
  {
    case File_JPEG:
      result = 2i64;
      break;
    case File_PNG:
      result = 4i64;
      break;
    case File_TGA:
      result = 5i64;
      break;
    case File_DDS:
      result = 3i64;
      break;
    case File_PVR:
      result = 6i64;
      break;
    case File_SIF:
      result = 11i64;
      break;
    case File_GXT:
      result = 8i64;
      break;
    case File_KTX:
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
Scaleform::Render::ImageSource *__fastcall Scaleform::GFx::LoaderImpl::LoadBuiltinImage(
        Scaleform::File *pfile,
        __int64 format,
        __int64 __formal,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::Log *plog,
        Scaleform::MemoryHeap *pimageHeap)
{
  Scaleform::GFx::FileTypeConstants::FileFormatType v7; // ebx
  __int64 v9; // rdi
  const char *v10; // rsi
  Scaleform::Render::ImageFileFormat v11; // r15d
  Scaleform::GFx::ImageFileHandlerRegistry *pObject; // rbx
  Scaleform::Render::ImageFileReader *Reader; // rcx
  int v15; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::MemoryHeap *v16; // [rsp+30h] [rbp-38h]
  __int64 v17; // [rsp+38h] [rbp-30h]
  __int64 v18; // [rsp+40h] [rbp-28h]
  int v19; // [rsp+48h] [rbp-20h]

  v7 = (int)format;
  v9 = 0i64;
  v10 = (const char *)((__int64 (__fastcall *)(Scaleform::File *, __int64, __int64))pfile->vfptr[1].__vecDelDtor)(
                        pfile,
                        format,
                        __formal);
  v11 = (unsigned int)Scaleform::GFx::LoaderImpl::FileFormat2RenderImageFile(v7);
  if ( v11 == ImageFile_Unknown )
  {
    if ( plog )
      Scaleform::Log::LogMessage(plog, "Default image loader failed to load %s", v10);
    return 0i64;
  }
  else
  {
    pObject = pls->pImageFileHandlerRegistry.pObject;
    if ( pObject )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pls->pImageFileHandlerRegistry.pObject);
    if ( pObject )
    {
      Reader = Scaleform::Render::ImageFileHandlerRegistry::GetReader(
                 &pObject->Scaleform::Render::ImageFileHandlerRegistry,
                 v11);
      if ( Reader )
      {
        v15 = 0;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0;
        v16 = pimageHeap;
        v9 = ((__int64 (__fastcall *)(Scaleform::Render::ImageFileReader *, Scaleform::File *, int *))Reader->vfptr[1].GetFormat)(
               Reader,
               pfile,
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
    if ( pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pObject);
    return (Scaleform::Render::ImageSource *)v9;
  }
}

// File Line: 1500
// RVA: 0x8C7200
__int64 __fastcall Scaleform::GFx::LoaderImpl::DetectFileFormat(Scaleform::File *pfile)
{
  unsigned int v3; // eax
  Scaleform::RefCountImplCoreVtbl *vfptr; // r9
  unsigned int v5; // ebx
  unsigned int v6; // esi
  const char *v7; // rax
  const char *v8; // rax
  int v9; // [rsp+30h] [rbp+10h] BYREF

  if ( !pfile )
    return 0i64;
  v3 = ((__int64 (*)(void))pfile->vfptr[4].__vecDelDtor)();
  vfptr = pfile->vfptr;
  v5 = 1;
  v6 = v3;
  v9 = 0;
  if ( ((int (__fastcall *)(Scaleform::File *, int *, __int64))vfptr[10].__vecDelDtor)(pfile, &v9, 4i64) > 0 )
  {
    switch ( (char)v9 )
    {
      case 52:
        pfile->vfptr[14].__vecDelDtor(pfile, 44u);
        if ( ((unsigned int (__fastcall *)(Scaleform::File *, int *, __int64))pfile->vfptr[10].__vecDelDtor)(
               pfile,
               &v9,
               3i64) == 3
          && (_BYTE)v9 == 80
          && *(_WORD *)((char *)&v9 + 1) == 21078 )
        {
          v5 = 21;
        }
        break;
      case 67:
      case 70:
        if ( BYTE1(v9) == 87 )
        {
          if ( BYTE2(v9) == 83 )
            v5 = 2;
        }
        else if ( *(_WORD *)((char *)&v9 + 1) == 22598 )
        {
          v5 = 3;
        }
        break;
      case 68:
        if ( *(_WORD *)((char *)&v9 + 1) == 21316 )
          v5 = 14;
        break;
      case 71:
        if ( BYTE1(v9) == 73 )
        {
          if ( HIWORD(v9) == 14406 )
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
      case -119:
        if ( *(_WORD *)((char *)&v9 + 1) == 20048 && HIBYTE(v9) == 71 )
          v5 = 11;
        break;
      case -85:
        if ( *(_WORD *)((char *)&v9 + 1) == 21579 && HIBYTE(v9) == 88 )
          v5 = 27;
        break;
      case -1:
        if ( BYTE1(v9) == 0xD8 )
          v5 = 10;
        break;
      default:
        break;
    }
    ((void (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))pfile->vfptr[14].__vecDelDtor)(pfile, v6, 0i64);
    if ( v5 == 1 )
    {
      v7 = (const char *)((__int64 (__fastcall *)(Scaleform::File *))pfile->vfptr[1].__vecDelDtor)(pfile);
      if ( v7 )
      {
        v8 = strrchr(v7, 46);
        if ( v8 )
        {
          if ( !Scaleform::String::CompareNoCase(v8, ".tga") )
            return 13;
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
  int v6; // r9d
  __int64 v7; // rbx
  BOOL v8; // ebp
  unsigned __int64 v9; // rcx
  char v10; // al
  bool v11; // zf
  bool v12; // r14
  Scaleform::String *v13; // rax
  bool v14; // r14
  Scaleform::String v16; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::String v17; // [rsp+28h] [rbp-30h] BYREF
  __int64 v18; // [rsp+30h] [rbp-28h]
  Scaleform::String result; // [rsp+78h] [rbp+20h] BYREF

  v18 = -2i64;
  if ( Scaleform::String::GetLength(url) <= 6 )
    return 0;
  v6 = *(char *)((url->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  if ( (unsigned int)(v6 - 65) <= 0x19 )
    v6 += 32;
  if ( v6 != 105 && v6 != 115 )
    return 0;
  v7 = 0i64;
  v8 = v6 == 115;
  Scaleform::String::ToLower(url, &result);
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
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !v12 )
  {
    v13 = Scaleform::String::Substring(&result, &v17, v8, v8 + 8);
    v14 = strcmp((const char *)((v13->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), "imgps://") == 0;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v17.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( v14 )
    {
      if ( bilinear )
        *bilinear = 0;
      goto LABEL_20;
    }
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    return 0;
  }
  if ( bilinear )
    *bilinear = 1;
LABEL_20:
  if ( sync )
    *sync = v8;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return 1;
}

// File Line: 1706
// RVA: 0x8EEAF0
char __fastcall Scaleform::GFx::Translator::OnWordWrapping(
        Scaleform::GFx::Translator *this,
        Scaleform::GFx::Translator::LineFormatDesc *pdesc)
{
  unsigned int WWMode; // r10d
  unsigned __int64 WordWrapPos; // rax
  unsigned __int64 ProposedWordWrapPoint; // rsi
  unsigned __int64 NumCharsInLine; // rdi
  const wchar_t *v8; // r14
  unsigned __int64 v9; // rbp
  wchar_t *v10; // rsi
  int v11; // r14d
  unsigned __int16 v12; // ax

  WWMode = this->WWMode;
  if ( !WWMode )
    return 0;
  if ( (WWMode & 7) != 0 && pdesc->NumCharsInLine )
  {
    WordWrapPos = Scaleform::Render::Text::WordWrapHelper::FindWordWrapPos(
                    WWMode,
                    pdesc->ProposedWordWrapPoint,
                    pdesc->pParaText,
                    pdesc->ParaTextLen,
                    pdesc->LineStartPos,
                    pdesc->NumCharsInLine);
    if ( WordWrapPos == -1i64 )
      return 0;
    pdesc->ProposedWordWrapPoint = WordWrapPos;
    return 1;
  }
  else
  {
    if ( (WWMode & 8) == 0 )
      return 0;
    ProposedWordWrapPoint = pdesc->ProposedWordWrapPoint;
    if ( !ProposedWordWrapPoint )
      return 0;
    NumCharsInLine = pdesc->NumCharsInLine;
    v8 = &pdesc->pParaText[pdesc->LineStartPos];
    v9 = 0i64;
    if ( (unsigned int)Scaleform::SFiswspace(v8[ProposedWordWrapPoint - 1]) )
      v9 = ProposedWordWrapPoint;
    if ( NumCharsInLine > v9 )
    {
      v10 = (wchar_t *)&v8[NumCharsInLine - 1];
      v11 = 1065233;
      while ( 1 )
      {
        v12 = Scaleform::SFtowlower(*v10) - 97;
        if ( v12 <= 0x14u
          && _bittest(&v11, v12)
          && (float)((float)pdesc->pWidths[NumCharsInLine - 1] + pdesc->DashSymbolWidth) < pdesc->VisibleRectWidth )
        {
          break;
        }
        --NumCharsInLine;
        --v10;
        if ( NumCharsInLine <= v9 )
          return 0;
      }
      pdesc->ProposedWordWrapPoint = NumCharsInLine;
      pdesc->UseHyphenation = 1;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

// File Line: 1768
// RVA: 0x90B100
void __fastcall Scaleform::GFx::Translator::TranslateInfo::SetResult(
        Scaleform::GFx::Translator::TranslateInfo *this,
        const wchar_t *presultText,
        unsigned __int64 resultLen)
{
  unsigned __int64 v3; // rdi

  if ( presultText )
  {
    v3 = resultLen;
    if ( resultLen == -1i64 )
      v3 = Scaleform::SFwcslen(presultText);
    Scaleform::WStringBuffer::Resize(this->pResult, v3 + 1);
    Scaleform::SFwcsncpy(this->pResult->pText, v3 + 1, presultText, v3);
    this->Flags |= 1u;
  }
}

// File Line: 1782
// RVA: 0x90B070
void __fastcall Scaleform::GFx::Translator::TranslateInfo::SetResult(
        Scaleform::GFx::Translator::TranslateInfo *this,
        const char *presultTextUTF8,
        __int64 resultUTF8Len)
{
  __int64 v3; // rbx
  unsigned __int64 v6; // rdi

  if ( presultTextUTF8 )
  {
    v3 = resultUTF8Len;
    if ( resultUTF8Len == -1 )
    {
      v3 = -1i64;
      do
        ++v3;
      while ( presultTextUTF8[v3] );
    }
    v6 = (int)(Scaleform::UTF8Util::GetLength(presultTextUTF8, -1i64) + 1);
    Scaleform::WStringBuffer::Resize(this->pResult, v6);
    Scaleform::UTF8Util::DecodeStringSafe(this->pResult->pText, v6, presultTextUTF8, v3);
    this->Flags |= 1u;
  }
}

