// File Line: 237
// RVA: 0x86F470
void __fastcall Scaleform::GFx::GFx_FrameLabelLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rcx
  Scaleform::GFx::LogState *pObject; // r8
  Scaleform::StringDH v5; // [rsp+28h] [rbp-20h] BYREF

  Scaleform::StringDH::StringDH(&v5, p->pLoadData.pObject->pHeap);
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &v5);
  pObject = p->pLoadStates.pObject->pLog.pObject;
  if ( p->LoadState == LS_LoadingSprite )
    ((void (__fastcall *)(Scaleform::GFx::TimelineIODef *, Scaleform::StringDH *, Scaleform::GFx::LogState *))p->pTimelineDef->vfptr[4].GetKey)(
      p->pTimelineDef,
      &v5,
      pObject);
  else
    ((void (__fastcall *)(Scaleform::GFx::MovieDataDef::LoadTaskData *, Scaleform::StringDH *, Scaleform::GFx::LogState *))p->pLoadData.pObject->vfptr[1].__vecDelDtor)(
      p->pLoadData.pObject,
      &v5,
      pObject);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  Frame label: \"%s\"\n",
    (const char *)((v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 249
// RVA: 0x86C880
void __fastcall Scaleform::GFx::GFx_SetBackgroundColorLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SetBackgroundColorTag *v3; // rax
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rcx
  Scaleform::GFx::SetBackgroundColorTag *v5; // rsi
  int Blue; // [rsp+20h] [rbp-18h]

  v3 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::SetBackgroundColorTag>(p);
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v5 = v3;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  Scaleform::GFx::Stream::ReadRgb(&pAltStream->Stream, &v3->Color);
  Blue = (unsigned __int8)v5->Color.Channels.Blue;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  SetBackgroundColor: (%d %d %d)\n",
    (unsigned __int8)v5->Color.Channels.Red,
    (unsigned __int8)v5->Color.Channels.Green,
    Blue);
  Scaleform::GFx::LoadProcess::AddExecuteTag(p, v5);
}

// File Line: 263
// RVA: 0x86C910
void __fastcall Scaleform::GFx::GFx_JpegTablesLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadStates *pObject; // rax
  Scaleform::GFx::ImageFileHandlerRegistry *v5; // rdi
  __int64 v6; // rcx
  Scaleform::Render::JPEG::TablesHeader *v7; // rsi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx

  pObject = p->pLoadStates.pObject;
  v5 = pObject->pImageFileHandlerRegistry.pObject;
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pObject->pImageFileHandlerRegistry.pObject);
  if ( v5 )
  {
    if ( Scaleform::Render::ImageFileHandlerRegistry::GetReader(
           &v5->Scaleform::Render::ImageFileHandlerRegistry,
           ImageFile_JPEG) )
    {
      if ( tagInfo->TagLength > 0 )
      {
        v7 = (Scaleform::Render::JPEG::TablesHeader *)((__int64 (__fastcall *)(__int64, __int64))p->pLoadData.pObject->pHeap->vfptr->Alloc)(
                                                        v6,
                                                        32i64);
        if ( v7 )
        {
          Scaleform::Render::JPEG::ExtraData::ExtraData(v7, p->pLoadData.pObject->pHeap, tagInfo->TagLength);
          v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::JPEG::TablesHeader::`vftable;
        }
        else
        {
          v7 = 0i64;
        }
        pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !pAltStream )
          pAltStream = &p->ProcessInfo;
        Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, v7->Data, tagInfo->TagLength);
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v7);
        v9 = (Scaleform::Render::RenderBuffer *)p->pJpegTables.pObject;
        if ( v9 )
          Scaleform::RefCountImpl::Release(v9);
        p->pJpegTables.pObject = v7;
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
      }
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "Jpeg System is not installed - cant load jpeg image data");
    }
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Image file handler registry is not installed - cant load jpeg image data");
  }
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
}

// File Line: 297
// RVA: 0x86CB70
void __fastcall Scaleform::GFx::GFx_DefineBitsJpegLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r8
  unsigned __int16 v6; // r12
  Scaleform::Render::ImageSource *v7; // rbx
  Scaleform::GFx::LoadStates *pObject; // rax
  __int64 v9; // rbp
  Scaleform::Render::ImageFileReader *Reader; // r14
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rsi
  unsigned int v12; // eax
  Scaleform::Render::JPEG::TablesHeader *v13; // r15
  Scaleform::GFx::SWFProcessInfo *v14; // rsi
  unsigned int v15; // eax
  Scaleform::Render::JPEG::TablesHeader *v16; // r9
  unsigned int v17; // eax
  int v18; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+40h] [rbp-58h]
  __int64 v20; // [rsp+48h] [rbp-50h]
  __int64 v21; // [rsp+50h] [rbp-48h]
  int v22; // [rsp+58h] [rbp-40h]
  __int64 rid; // [rsp+A0h] [rbp+8h] BYREF
  Scaleform::Render::ImageSource *v24; // [rsp+B0h] [rbp+18h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v7 = 0i64;
  v24 = 0i64;
  pObject = p->pLoadStates.pObject;
  v9 = (__int64)pObject->pImageFileHandlerRegistry.pObject;
  if ( v9 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pObject->pImageFileHandlerRegistry.pObject);
  rid = v9;
  if ( v9 )
  {
    Reader = Scaleform::Render::ImageFileHandlerRegistry::GetReader(
               (Scaleform::Render::ImageFileHandlerRegistry *)(v9 + 24),
               ImageFile_JPEG);
    if ( Reader )
    {
      p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !p_ProcessInfo )
        p_ProcessInfo = &p->ProcessInfo;
      v12 = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))p_ProcessInfo->Stream.pInput.pObject->vfptr[14].__vecDelDtor)(
              p_ProcessInfo->Stream.pInput.pObject,
              p_ProcessInfo->Stream.Pos + p_ProcessInfo->Stream.FilePos - p_ProcessInfo->Stream.DataSize,
              0i64);
      if ( v12 != -1 )
      {
        *(_QWORD *)&p_ProcessInfo->Stream.Pos = 0i64;
        p_ProcessInfo->Stream.FilePos = v12;
      }
      v13 = p->pJpegTables.pObject;
      v18 = 0;
      pHeap = 0i64;
      v20 = 0i64;
      v21 = 0i64;
      v22 = 0;
      v14 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      pHeap = p->pLoadData.pObject->pHeap;
      if ( v13 )
      {
        if ( !v14 )
          v14 = &p->ProcessInfo;
        v15 = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v14->Stream.pInput.pObject->vfptr[14].__vecDelDtor)(
                v14->Stream.pInput.pObject,
                v14->Stream.Pos + v14->Stream.FilePos - v14->Stream.DataSize,
                0i64);
        if ( v15 != -1 )
        {
          *(_QWORD *)&v14->Stream.Pos = 0i64;
          v14->Stream.FilePos = v15;
        }
        v16 = v13;
      }
      else
      {
        if ( !v14 )
          v14 = &p->ProcessInfo;
        v17 = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v14->Stream.pInput.pObject->vfptr[14].__vecDelDtor)(
                v14->Stream.pInput.pObject,
                v14->Stream.Pos + v14->Stream.FilePos - v14->Stream.DataSize,
                0i64);
        if ( v17 != -1 )
        {
          *(_QWORD *)&v14->Stream.Pos = 0i64;
          v14->Stream.FilePos = v17;
        }
        v16 = 0i64;
      }
      v14->Stream.ResyncFile = 1;
      v24 = (Scaleform::Render::ImageSource *)((__int64 (__fastcall *)(Scaleform::Render::ImageFileReader *, Scaleform::File *, int *, Scaleform::Render::JPEG::TablesHeader *, _QWORD, _BYTE, __int64))Reader->vfptr[1].IsWriter)(
                                                Reader,
                                                v14->Stream.pInput.pObject,
                                                &v18,
                                                v16,
                                                tagInfo->TagLength - 2,
                                                0,
                                                -2i64);
      v7 = v24;
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "Jpeg System is not installed - cant load jpeg image data");
    }
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Image file handler registry is not installed - cant load jpeg image data");
  }
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
  LODWORD(rid) = v6;
  Scaleform::GFx::LoadProcess::AddImageResource(p, (Scaleform::GFx::ResourceId)&rid, v7);
  if ( v7 )
    ((void (__fastcall *)(Scaleform::Render::ImageSource *))v7->vfptr[2].__vecDelDtor)(v7);
}

// File Line: 360
// RVA: 0x86CE20
void __fastcall Scaleform::GFx::GFx_DefineBitsJpeg2Loader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r8
  unsigned __int16 v6; // r9
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rax
  int v8; // r15d
  Scaleform::Render::ImageSource *v9; // rbx
  Scaleform::GFx::LoadStates *pObject; // rax
  __int64 v11; // rbp
  Scaleform::Render::ImageFileReader *Reader; // r14
  Scaleform::GFx::SWFProcessInfo *v13; // rsi
  unsigned int v14; // eax
  int v15; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+40h] [rbp-48h]
  __int64 v17; // [rsp+48h] [rbp-40h]
  __int64 v18; // [rsp+50h] [rbp-38h]
  int v19; // [rsp+58h] [rbp-30h]
  __int64 rid; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::Render::ImageSource *v21; // [rsp+A0h] [rbp+18h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v8 = v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  GFx_DefineBitsJpeg2Loader: charid = %d pos = 0x%x\n",
    v6,
    p_ProcessInfo->Stream.Pos + p_ProcessInfo->Stream.FilePos - p_ProcessInfo->Stream.DataSize);
  v9 = 0i64;
  v21 = 0i64;
  pObject = p->pLoadStates.pObject;
  v11 = (__int64)pObject->pImageFileHandlerRegistry.pObject;
  if ( v11 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pObject->pImageFileHandlerRegistry.pObject);
  rid = v11;
  if ( v11 )
  {
    Reader = Scaleform::Render::ImageFileHandlerRegistry::GetReader(
               (Scaleform::Render::ImageFileHandlerRegistry *)(v11 + 24),
               ImageFile_JPEG);
    if ( Reader )
    {
      v15 = 0;
      pHeap = 0i64;
      v17 = 0i64;
      v18 = 0i64;
      v19 = 0;
      pHeap = p->pLoadData.pObject->pHeap;
      v13 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !v13 )
        v13 = &p->ProcessInfo;
      v14 = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v13->Stream.pInput.pObject->vfptr[14].__vecDelDtor)(
              v13->Stream.pInput.pObject,
              v13->Stream.Pos + v13->Stream.FilePos - v13->Stream.DataSize,
              0i64);
      if ( v14 != -1 )
      {
        *(_QWORD *)&v13->Stream.Pos = 0i64;
        v13->Stream.FilePos = v14;
      }
      v13->Stream.ResyncFile = 1;
      v9 = (Scaleform::Render::ImageSource *)((__int64 (__fastcall *)(Scaleform::Render::ImageFileReader *, Scaleform::File *, int *, _QWORD, _QWORD, char, __int64))Reader->vfptr[1].IsWriter)(
                                               Reader,
                                               v13->Stream.pInput.pObject,
                                               &v15,
                                               0i64,
                                               tagInfo->TagLength - 2,
                                               1,
                                               -2i64);
      v21 = v9;
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "Jpeg System is not installed - cant load jpeg image data");
    }
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Image file handler registry is not installed - cant load jpeg image data");
  }
  if ( v11 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v11);
  LODWORD(rid) = v8;
  Scaleform::GFx::LoadProcess::AddImageResource(p, (Scaleform::GFx::ResourceId)&rid, v9);
  if ( v9 )
    ((void (__fastcall *)(Scaleform::Render::ImageSource *))v9->vfptr[2].__vecDelDtor)(v9);
}

// File Line: 484
// RVA: 0x86D020
void __fastcall Scaleform::GFx::GFx_DefineBitsJpeg3Loader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdi
  __int64 Pos; // r8
  unsigned __int16 v6; // si
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rdi
  __int64 v8; // r8
  unsigned __int16 v9; // r9
  Scaleform::GFx::SWFProcessInfo *v10; // rcx
  unsigned int v11; // edi
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v12; // rsi
  Scaleform::GFx::SWFProcessInfo *v13; // rax
  int v14; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::ResourceId rid; // [rsp+60h] [rbp+8h] BYREF
  __int64 v16; // [rsp+68h] [rbp+10h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  Scaleform::GFx::LoadProcess::ReadU32(p);
  if ( tagInfo->TagType == Tag_DefineBitsJpeg4 )
  {
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
    v8 = p_ProcessInfo->Stream.Pos;
    v9 = (unsigned __int8)p_ProcessInfo->Stream.pBuffer[v8] | ((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v8 + 1)] << 8);
    p_ProcessInfo->Stream.Pos = v8 + 2;
    v10 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v10 )
      v10 = &p->ProcessInfo;
    v11 = v6;
    v12 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
    v14 = v9;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  GFx_DefineBitsJpeg4Loader: charid = %d pos = %d deblocking = %d\n",
      v11,
      v10->Stream.Pos + v10->Stream.FilePos - v10->Stream.DataSize,
      v14);
  }
  else
  {
    v13 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v13 )
      v13 = &p->ProcessInfo;
    v11 = v6;
    v12 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  GFx_DefineBitsJpeg3Loader: charid = %d pos = %d\n",
      v11,
      v13->Stream.Pos + v13->Stream.FilePos - v13->Stream.DataSize);
  }
  v16 = 0i64;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
    v12,
    "zlib or jpeglib are not linked - cant load jpeg+zipped image data!");
  rid.Id = v11;
  Scaleform::GFx::LoadProcess::AddImageResource(p, (Scaleform::GFx::ResourceId)&rid, 0i64);
}

// File Line: 565
// RVA: 0x86E4A0
void __fastcall Scaleform::GFx::GFx_DefineBitsLossless2Loader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r8
  unsigned __int16 v6; // r14
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rbx
  __int64 v8; // rcx
  unsigned __int8 v9; // bp
  Scaleform::GFx::SWFProcessInfo *v10; // rbx
  __int64 v11; // r8
  unsigned __int16 v12; // r15
  Scaleform::GFx::SWFProcessInfo *v13; // rbx
  __int64 v14; // r9
  unsigned __int16 v15; // r8
  int v16; // r12d
  int v17; // r13d
  Scaleform::Render::ImageSource *v18; // rbx
  Scaleform::GFx::Resource *pObject; // r14
  __int16 v20; // r15
  Scaleform::GFx::SWFProcessInfo *v21; // rax
  int v22; // ebp
  __int64 v23; // rsi
  Scaleform::File *UnderlyingFile; // rax
  Scaleform::GFx::SWFProcessInfo *v25; // rax
  int v26; // ebp
  __int64 v27; // rsi
  Scaleform::File *v28; // rax
  Scaleform::GFx::SWFProcessInfo *v29; // rax
  int v30; // ebp
  __int64 v31; // rsi
  Scaleform::File *v32; // rax
  __int16 v33; // r15
  Scaleform::GFx::SWFProcessInfo *v34; // rax
  int v35; // ebp
  __int64 v36; // rsi
  Scaleform::File *v37; // rax
  Scaleform::GFx::SWFProcessInfo *v38; // rax
  int v39; // ebp
  __int64 v40; // rsi
  Scaleform::File *v41; // rax
  Scaleform::GFx::SWFProcessInfo *v42; // rax
  int v43; // ebp
  __int64 v44; // rsi
  Scaleform::File *v45; // rax
  Scaleform::GFx::ResourceId rid; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::Render::ImageSource *v47; // [rsp+98h] [rbp+10h]
  __int64 v48; // [rsp+A0h] [rbp+18h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 1);
  v8 = p_ProcessInfo->Stream.Pos;
  v9 = p_ProcessInfo->Stream.pBuffer[v8];
  p_ProcessInfo->Stream.Pos = v8 + 1;
  v10 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v10 )
    v10 = &p->ProcessInfo;
  v10->Stream.UnusedBits = 0;
  if ( (signed int)(v10->Stream.DataSize - v10->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v10->Stream, 2);
  v11 = v10->Stream.Pos;
  v12 = (unsigned __int8)v10->Stream.pBuffer[v11] | ((unsigned __int8)v10->Stream.pBuffer[(unsigned int)(v11 + 1)] << 8);
  v10->Stream.Pos = v11 + 2;
  v13 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v13 )
    v13 = &p->ProcessInfo;
  v13->Stream.UnusedBits = 0;
  if ( (signed int)(v13->Stream.DataSize - v13->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v13->Stream, 2);
  v14 = v13->Stream.Pos;
  v15 = (unsigned __int8)v13->Stream.pBuffer[v14] | ((unsigned __int8)v13->Stream.pBuffer[(unsigned int)(v14 + 1)] << 8);
  v13->Stream.Pos = v14 + 2;
  v16 = v15;
  v17 = v12;
  rid.Id = v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  DefBitsLossless2: tagInfo.TagType = %d, id = %d, fmt = %d, w = %d, h = %d\n",
    (unsigned int)tagInfo->TagType,
    v6,
    v9,
    v12,
    v15);
  v18 = 0i64;
  v47 = 0i64;
  pObject = (Scaleform::GFx::Resource *)p->pLoadStates.pObject->pZlibSupport.pObject;
  if ( !pObject )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Error: GFxZlibState is not set - cant load zipped image data\n");
    goto LABEL_56;
  }
  if ( tagInfo->TagType == Tag_DefineBitsLossless )
  {
    switch ( v9 )
    {
      case 3u:
        v20 = (unsigned __int8)Scaleform::GFx::LoadProcess::ReadU8(p) + 1;
        v21 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !v21 )
          v21 = &p->ProcessInfo;
        v22 = tagInfo->TagLength + tagInfo->TagDataOffset + v21->Stream.DataSize - v21->Stream.FilePos - v21->Stream.Pos;
        v23 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v48 = v23;
        if ( v23 )
        {
          UnderlyingFile = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v23,
            UnderlyingFile,
            Image_R8G8B8,
            v22);
          *(_QWORD *)v23 = &Scaleform::GFx::ZlibImageSource::`vftable;
          Scaleform::Render::RenderBuffer::AddRef(pObject);
          *(_QWORD *)(v23 + 56) = pObject;
          *(_WORD *)(v23 + 64) = v20;
          *(_DWORD *)(v23 + 68) = 0;
          *(_DWORD *)(v23 + 20) = v17;
          *(_DWORD *)(v23 + 24) = v16;
          v18 = (Scaleform::Render::ImageSource *)v23;
        }
        break;
      case 4u:
        v25 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !v25 )
          v25 = &p->ProcessInfo;
        v26 = tagInfo->TagLength + tagInfo->TagDataOffset + v25->Stream.DataSize - v25->Stream.FilePos - v25->Stream.Pos;
        v27 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v48 = v27;
        if ( v27 )
        {
          v28 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v27,
            v28,
            Image_R8G8B8,
            v26);
          *(_QWORD *)v27 = &Scaleform::GFx::ZlibImageSource::`vftable;
          Scaleform::Render::RenderBuffer::AddRef(pObject);
          *(_QWORD *)(v27 + 56) = pObject;
          *(_WORD *)(v27 + 64) = 0;
          *(_DWORD *)(v27 + 68) = 1;
          *(_DWORD *)(v27 + 20) = v12;
          *(_DWORD *)(v27 + 24) = v16;
          v18 = (Scaleform::Render::ImageSource *)v27;
        }
        break;
      case 5u:
        v29 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !v29 )
          v29 = &p->ProcessInfo;
        v30 = tagInfo->TagLength + tagInfo->TagDataOffset + v29->Stream.DataSize - v29->Stream.FilePos - v29->Stream.Pos;
        v31 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v48 = v31;
        if ( v31 )
        {
          v32 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v31,
            v32,
            Image_R8G8B8,
            v30);
          *(_QWORD *)v31 = &Scaleform::GFx::ZlibImageSource::`vftable;
          Scaleform::Render::RenderBuffer::AddRef(pObject);
          *(_QWORD *)(v31 + 56) = pObject;
          *(_WORD *)(v31 + 64) = 0;
          *(_DWORD *)(v31 + 68) = 2;
          *(_DWORD *)(v31 + 20) = v12;
          *(_DWORD *)(v31 + 24) = v16;
          v18 = (Scaleform::Render::ImageSource *)v31;
        }
        break;
      default:
        goto LABEL_56;
    }
  }
  else
  {
    switch ( v9 )
    {
      case 3u:
        v33 = (unsigned __int8)Scaleform::GFx::LoadProcess::ReadU8(p) + 1;
        v34 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !v34 )
          v34 = &p->ProcessInfo;
        v35 = tagInfo->TagLength + tagInfo->TagDataOffset + v34->Stream.DataSize - v34->Stream.FilePos - v34->Stream.Pos;
        v36 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v48 = v36;
        if ( v36 )
        {
          v37 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v36,
            v37,
            Image_R8G8B8A8,
            v35);
          *(_QWORD *)v36 = &Scaleform::GFx::ZlibImageSource::`vftable;
          Scaleform::Render::RenderBuffer::AddRef(pObject);
          *(_QWORD *)(v36 + 56) = pObject;
          *(_WORD *)(v36 + 64) = v33;
          *(_DWORD *)(v36 + 68) = 3;
          *(_DWORD *)(v36 + 20) = v17;
          *(_DWORD *)(v36 + 24) = v16;
          v18 = (Scaleform::Render::ImageSource *)v36;
        }
        break;
      case 4u:
        v38 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !v38 )
          v38 = &p->ProcessInfo;
        v39 = tagInfo->TagLength + tagInfo->TagDataOffset + v38->Stream.DataSize - v38->Stream.FilePos - v38->Stream.Pos;
        v40 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v48 = v40;
        if ( v40 )
        {
          v41 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v40,
            v41,
            Image_R8G8B8A8,
            v39);
          *(_QWORD *)v40 = &Scaleform::GFx::ZlibImageSource::`vftable;
          Scaleform::Render::RenderBuffer::AddRef(pObject);
          *(_QWORD *)(v40 + 56) = pObject;
          *(_WORD *)(v40 + 64) = 0;
          *(_DWORD *)(v40 + 68) = 1;
          *(_DWORD *)(v40 + 20) = v12;
          *(_DWORD *)(v40 + 24) = v16;
          v18 = (Scaleform::Render::ImageSource *)v40;
        }
        break;
      case 5u:
        v42 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !v42 )
          v42 = &p->ProcessInfo;
        v43 = tagInfo->TagLength + tagInfo->TagDataOffset + v42->Stream.DataSize - v42->Stream.FilePos - v42->Stream.Pos;
        v44 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v48 = v44;
        if ( v44 )
        {
          v45 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(p);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v44,
            v45,
            Image_R8G8B8A8,
            v43);
          *(_QWORD *)v44 = &Scaleform::GFx::ZlibImageSource::`vftable;
          Scaleform::Render::RenderBuffer::AddRef(pObject);
          *(_QWORD *)(v44 + 56) = pObject;
          *(_WORD *)(v44 + 64) = 0;
          *(_DWORD *)(v44 + 68) = 4;
          *(_DWORD *)(v44 + 20) = v12;
          *(_DWORD *)(v44 + 24) = v16;
          v18 = (Scaleform::Render::ImageSource *)v44;
        }
        break;
      default:
        goto LABEL_56;
    }
  }
  v47 = v18;
LABEL_56:
  Scaleform::GFx::LoadProcess::AddImageResource(p, (Scaleform::GFx::ResourceId)&rid, v18);
  if ( v18 )
    ((void (__fastcall *)(Scaleform::Render::ImageSource *))v18->vfptr[2].__vecDelDtor)(v18);
}

// File Line: 671
// RVA: 0x86D2B0
void __fastcall Scaleform::GFx::GFx_DefineShapeLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r9
  unsigned __int16 v6; // r8
  unsigned int v7; // r14d
  __int64 v8; // rcx
  Scaleform::GFx::ShapeDataBase *v9; // rbx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rcx
  __int64 v11; // rcx
  Scaleform::GFx::SwfShapeCharacterDef *v12; // rax
  Scaleform::GFx::Resource *v13; // rax
  Scaleform::GFx::Resource *v14; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  char v16[72]; // [rsp+40h] [rbp-48h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+98h] [rbp+10h]
  void *v19; // [rsp+A0h] [rbp+18h]
  Scaleform::GFx::ShapeDataBase *v20; // [rsp+A8h] [rbp+20h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v7 = v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  ShapeLoader: id = %d\n",
    v6);
  pHeap = p->pLoadData.pObject->pHeap;
  v9 = (Scaleform::GFx::ShapeDataBase *)((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(v8, 80i64);
  v19 = v9;
  if ( v9 )
  {
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
    v9->RefCount = 1;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ShapeDataBase::`vftable;
    v9->Paths = 0i64;
    v9->Flags = 0;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable;
    v9[1].vfptr = 0i64;
    *(_QWORD *)&v9[1].RefCount = 0i64;
    v9[1].Paths = 0i64;
    *(_QWORD *)&v9[1].Flags = 0i64;
    v9[2].vfptr = 0i64;
    *(_QWORD *)&v9[2].RefCount = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  v20 = v9;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  ((void (__fastcall *)(Scaleform::GFx::ShapeDataBase *, Scaleform::GFx::LoadProcess *, _QWORD, _QWORD, char))v9->vfptr[15].__vecDelDtor)(
    v9,
    p,
    (unsigned int)tagInfo->TagType,
    tagInfo->TagLength
  + tagInfo->TagDataOffset
  - (p_ProcessInfo->Stream.Pos
   + p_ProcessInfo->Stream.FilePos
   - p_ProcessInfo->Stream.DataSize),
    1);
  pHeap = p->pLoadData.pObject->pHeap;
  v12 = (Scaleform::GFx::SwfShapeCharacterDef *)((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(
                                                  v11,
                                                  48i64);
  v19 = v12;
  if ( v12 )
  {
    Scaleform::GFx::SwfShapeCharacterDef::SwfShapeCharacterDef(v12, v9);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  bound rect:");
  ((void (__fastcall *)(Scaleform::GFx::Resource *, char *))v14->vfptr[1].GetResourceReport)(v14, v16);
  if ( p->LoadState == LS_LoadingRoot )
  {
    rid.Id = v7;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(p->pLoadData.pObject, (Scaleform::GFx::ResourceId)&rid, v14);
  }
  if ( !_InterlockedDecrement(&v14->RefCount.Value) )
  {
    pLib = v14->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v14);
      v14->pLib = 0i64;
    }
    v14->vfptr->__vecDelDtor(v14, 1u);
  }
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
}

// File Line: 696
// RVA: 0x86D4E0
void __fastcall Scaleform::GFx::GFx_DefineShapeMorphLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "ShapeMorphLoader failed due to SF_NO_MORPHING_SUPPORT macro");
}

// File Line: 719
// RVA: 0x86D700
void __fastcall Scaleform::GFx::GFx_DefineFontLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r9
  unsigned __int16 v6; // r8
  int v7; // r14d
  Scaleform::MemoryHeap *v8; // rcx
  Scaleform::GFx::FontData *v9; // rbx
  Scaleform::GFx::FontData *v10; // rax
  Scaleform::GFx::FontData *v11; // rax
  Scaleform::GFx::Resource *pResource; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceHandle result; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::MemoryHeap *rid; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::FontData *v16; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::FontData *v17; // [rsp+80h] [rbp+18h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v7 = v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  Font: id = %d\n",
    v6);
  v9 = 0i64;
  v16 = 0i64;
  if ( tagInfo->TagType == Tag_DefineCompactedFont )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Trying to load compacted font with SF_NO_COMPACTED_FONT_SUPPORT defined.");
  }
  else
  {
    rid = p->pLoadData.pObject->pHeap;
    v10 = (Scaleform::GFx::FontData *)rid->vfptr->Alloc(v8, 136ui64, 0i64);
    v17 = v10;
    if ( v10 )
    {
      Scaleform::GFx::FontData::FontData(v10);
      v9 = v11;
    }
    else
    {
      v9 = 0i64;
    }
    v16 = v9;
    Scaleform::GFx::FontData::Read(v9, p, tagInfo);
    LODWORD(rid) = v7;
    Scaleform::GFx::LoadProcess::AddFontDataResource(p, &result, (Scaleform::GFx::ResourceId)&rid, v9);
    if ( result.HType == RH_Pointer )
    {
      pResource = result.pResource;
      if ( result.pResource )
      {
        if ( !_InterlockedDecrement(&result.pResource->RefCount.Value) )
        {
          pLib = pResource->pLib;
          if ( pLib )
          {
            pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
            pResource->pLib = 0i64;
          }
          pResource->vfptr->__vecDelDtor(pResource, 1u);
        }
        v9 = v16;
      }
    }
  }
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
}

// File Line: 773
// RVA: 0x86D950
void __fastcall Scaleform::GFx::GFx_DebugIDLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  __int64 v3; // rbp
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // rdx
  int v6; // ecx
  char buf; // [rsp+60h] [rbp+18h] BYREF
  Scaleform::String v8; // [rsp+68h] [rbp+20h] BYREF

  Scaleform::String::String(&v8);
  v3 = 16i64;
  do
  {
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !pAltStream )
      pAltStream = &p->ProcessInfo;
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
    Pos = pAltStream->Stream.Pos;
    v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos];
    pAltStream->Stream.Pos = Pos + 1;
    itoa_s(v6, &buf, 3ui64, 16);
    Scaleform::String::AppendString(&v8, &buf, -1i64);
    --v3;
  }
  while ( v3 );
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8), 0xFFFFFFFF) == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 789
// RVA: 0x86DB30
void __fastcall Scaleform::GFx::GFx_DefineFontInfoLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  unsigned int DataSize; // eax
  __int64 Pos; // r9
  unsigned __int16 v7; // r8
  Scaleform::GFx::FontDataUseNode *volatile Value; // rax
  Scaleform::GFx::FontData *pObject; // rcx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rdx

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
  Value = p->pLoadData.pObject->BindData.pFonts.Value;
  if ( !Value )
    goto LABEL_8;
  while ( Value->Id.Id != v7 )
  {
    Value = Value->pNext.Value;
    if ( !Value )
      goto LABEL_8;
  }
  pObject = (Scaleform::GFx::FontData *)Value->pFontData.pObject;
  if ( pObject )
  {
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    Scaleform::GFx::FontData::ReadFontInfo(pObject, &p_ProcessInfo->Stream, tagInfo->TagType);
  }
  else
  {
LABEL_8:
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "GFx_DefineFontInfoLoader - cant find FontResource w/ id %d",
      v7);
  }
}

// File Line: 813
// RVA: 0x86DF60
void __fastcall Scaleform::GFx::GFx_PlaceObjectLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbp
  __int64 v4; // rax
  int v5; // edx
  unsigned __int64 v6; // rdi
  Scaleform::GFx::PlaceObjectTag *v7; // rax
  const char *pData; // rbx
  Scaleform::GFx::PlaceObjectTag *v9; // rsi
  Scaleform::GFx::StreamContext v10; // [rsp+20h] [rbp-48h] BYREF
  Scaleform::Render::Matrix2x4<float> pm; // [rsp+40h] [rbp-28h] BYREF

  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  PlaceObject\n");
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v4 = pAltStream->Stream.TagStackEntryCount - 1;
  if ( (unsigned int)v4 >= 2 )
    v5 = 0;
  else
    v5 = pAltStream->Stream.TagStack[v4];
  v6 = v5 - (pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize);
  v7 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObjectTag>(p, v6);
  pData = v7->pData;
  v9 = v7;
  Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, v7->pData, v6);
  v10.pData = pData;
  v10.DataSize = -1i64;
  v10.CurBitIndex = 0;
  v10.CurByteIndex = 4i64;
  Scaleform::GFx::StreamContext::ReadMatrix(&v10, &pm);
  v9->HasCxForm = v10.CurByteIndex < v6 - 1;
  Scaleform::GFx::LoadProcess::AddExecuteTag(p, v9);
}

// File Line: 826
// RVA: 0x86E1D0
void __fastcall Scaleform::GFx::GFx_PlaceObject2Loader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdi
  __int64 v4; // rax
  int v5; // edx
  unsigned __int64 v6; // rbp
  bool HasEventHandlers; // r14
  Scaleform::GFx::MovieDataDef::LoadTaskData *v8; // r8
  Scaleform::GFx::ASSupport *pObject; // rcx
  Scaleform::GFx::PlaceObject2Taga *v10; // rax
  Scaleform::GFx::PlaceObject2Taga *v11; // rsi
  char vfptr; // al

  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  PlaceObject2Tag\n");
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v4 = pAltStream->Stream.TagStackEntryCount - 1;
  if ( (unsigned int)v4 >= 2 )
    v5 = 0;
  else
    v5 = pAltStream->Stream.TagStack[v4];
  v6 = v5 - (pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize);
  HasEventHandlers = Scaleform::GFx::PlaceObject2Tag::HasEventHandlers(&pAltStream->Stream);
  if ( !HasEventHandlers || (v8 = p->pLoadData.pObject, v6 += 8i64, (v8->FileAttributes & 8) != 0) )
  {
    if ( p->pLoadData.pObject->Header.Version < 6u )
      v10 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject2Taga>(p, v6);
    else
      v10 = (Scaleform::GFx::PlaceObject2Taga *)Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject2Tag>(
                                                  p,
                                                  v6);
  }
  else
  {
    pObject = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( !pObject )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "GFx_PlaceObject2Loader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    v10 = (Scaleform::GFx::PlaceObject2Taga *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, unsigned __int64, _QWORD))pObject->vfptr[7].__vecDelDtor)(
                                                pObject,
                                                p,
                                                v6,
                                                LOBYTE(v8->Header.Version));
  }
  v11 = v10;
  if ( v10 )
  {
    if ( HasEventHandlers )
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, (char *)&v10[1], v6 - 8);
      vfptr = (char)v11[1].vfptr;
      *(_QWORD *)&v11->pData[1] = 0i64;
      v11->pData[0] = vfptr;
    }
    else
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, v10->pData, v6);
    }
    Scaleform::GFx::LoadProcess::AddExecuteTag(p, v11);
  }
}

// File Line: 868
// RVA: 0x86E300
void __fastcall Scaleform::GFx::GFx_PlaceObject3Loader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 v4; // rax
  int v5; // edx
  unsigned __int64 v6; // rbp
  bool HasEventHandlers; // r14
  Scaleform::GFx::ASSupport *pObject; // rcx
  Scaleform::GFx::PlaceObject3Tag *v9; // rax
  Scaleform::GFx::PlaceObject3Tag *v10; // rsi
  char vfptr; // al

  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  PlaceObject3Tag\n");
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v4 = pAltStream->Stream.TagStackEntryCount - 1;
  if ( (unsigned int)v4 >= 2 )
    v5 = 0;
  else
    v5 = pAltStream->Stream.TagStack[v4];
  v6 = v5 - (pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize);
  HasEventHandlers = Scaleform::GFx::PlaceObject2Tag::HasEventHandlers(&pAltStream->Stream);
  if ( !HasEventHandlers || (v6 += 8i64, (p->pLoadData.pObject->FileAttributes & 8) != 0) )
  {
    v9 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject3Tag>(p, v6);
  }
  else
  {
    pObject = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( !pObject )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "GFx_PlaceObject3Loader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    v9 = (Scaleform::GFx::PlaceObject3Tag *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, unsigned __int64))pObject->vfptr[8].__vecDelDtor)(
                                              pObject,
                                              p,
                                              v6);
  }
  v10 = v9;
  if ( v9 )
  {
    if ( HasEventHandlers )
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, (char *)&v9[1], v6 - 8);
      vfptr = (char)v10[1].vfptr;
      *(_QWORD *)&v10->pData[1] = 0i64;
      v10->pData[0] = vfptr;
    }
    else
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, v9->pData, v6);
    }
    Scaleform::GFx::LoadProcess::AddExecuteTag(p, v10);
  }
}

// File Line: 910
// RVA: 0x86EA80
void __fastcall Scaleform::GFx::GFx_SpriteLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r9
  unsigned __int16 v5; // r8
  unsigned int v6; // ebx
  __int64 v7; // rcx
  __int64 v8; // rax
  Scaleform::GFx::SpriteDef *v9; // rdi
  Scaleform::GFx::MovieDataDef *pDataDef_Unsafe; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rcx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  __int64 charId; // [rsp+60h] [rbp+8h] BYREF
  __int64 rid; // [rsp+70h] [rbp+18h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+78h] [rbp+20h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v6 = v5;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  sprite\n  char id = %d\n",
    v5);
  pHeap = p->pLoadData.pObject->pHeap;
  v8 = ((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(v7, 96i64);
  v9 = (Scaleform::GFx::SpriteDef *)v8;
  if ( v8 )
  {
    pDataDef_Unsafe = p->pDataDef_Unsafe;
    *(_QWORD *)v8 = &Scaleform::GFx::Resource::`vftable;
    *(_DWORD *)(v8 + 8) = 1;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)v8 = &Scaleform::GFx::CharacterDef::`vftable;
    *(_DWORD *)(v8 + 24) = 0x40000;
    *(_QWORD *)v8 = &Scaleform::GFx::TimelineDef::`vftable;
    *(_QWORD *)v8 = &Scaleform::GFx::TimelineIODef::`vftable;
    *(_QWORD *)v8 = &Scaleform::GFx::SpriteDef::`vftable;
    *(_QWORD *)(v8 + 32) = pDataDef_Unsafe;
    *(_QWORD *)(v8 + 40) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
    charId = v8 + 56;
    rid = v8 + 56;
    *(_QWORD *)(v8 + 56) = 0i64;
    *(_QWORD *)(v8 + 64) = 0i64;
    *(_QWORD *)(v8 + 72) = 0i64;
    *(_QWORD *)(v8 + 80) = 0i64;
    *(_BYTE *)(v8 + 88) = 0;
  }
  else
  {
    v9 = 0i64;
  }
  LODWORD(charId) = v6;
  Scaleform::GFx::SpriteDef::Read(v9, p, (Scaleform::GFx::ResourceId)&charId);
  pObject = p->pLoadData.pObject;
  v9->Id.Id = v6;
  LODWORD(rid) = v6;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(pObject, (Scaleform::GFx::ResourceId)&rid, v9);
  if ( !_InterlockedDecrement(&v9->RefCount.Value) )
  {
    pLib = v9->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v9);
      v9->pLib = 0i64;
    }
    v9->vfptr->__vecDelDtor(v9, 1u);
  }
}

// File Line: 942
// RVA: 0x86EDD0
void __fastcall Scaleform::GFx::GFx_RemoveObjectLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::ASSupport *pObject; // rcx
  Scaleform::GFx::RemoveObjectTag *v4; // rax
  Scaleform::GFx::RemoveObjectTag *v5; // rdi

  if ( (p->pLoadData.pObject->FileAttributes & 8) != 0 )
  {
    v4 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::RemoveObjectTag>(p);
  }
  else
  {
    pObject = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( !pObject )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "GFx_RemoveObjectLoader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    v4 = (Scaleform::GFx::RemoveObjectTag *)pObject->vfptr[9].__vecDelDtor(pObject, (unsigned int)p);
  }
  v5 = v4;
  if ( v4 )
  {
    v4->vfptr[1].__vecDelDtor(v4, (unsigned int)p);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  RemoveObject(%d, %d)\n",
      v5->Id,
      v5->Depth);
    Scaleform::GFx::LoadProcess::AddExecuteTag(p, v5);
  }
}

// File Line: 972
// RVA: 0x86EF70
void __fastcall Scaleform::GFx::GFx_RemoveObject2Loader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::ASSupport *pObject; // rcx
  Scaleform::GFx::RemoveObject2Tag *v4; // rax
  Scaleform::GFx::RemoveObject2Tag *v5; // rdi

  if ( (p->pLoadData.pObject->FileAttributes & 8) != 0 )
  {
    v4 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::RemoveObject2Tag>(p);
  }
  else
  {
    pObject = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( !pObject )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "GFx_PlaceObject3Loader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    v4 = (Scaleform::GFx::RemoveObject2Tag *)pObject->vfptr[10].__vecDelDtor(pObject, (unsigned int)p);
  }
  v5 = v4;
  if ( v4 )
  {
    v4->vfptr[1].__vecDelDtor(v4, (unsigned int)p);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  RemoveObject2(%d)\n",
      v5->Depth);
    Scaleform::GFx::LoadProcess::AddExecuteTag(p, v5);
  }
}

// File Line: 1002
// RVA: 0x86F1C0
void __fastcall Scaleform::GFx::GFx_ButtonCharacterLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r9
  unsigned __int16 v6; // r8
  unsigned int v7; // ebp
  __int64 v8; // rcx
  __int64 v9; // rax
  Scaleform::GFx::ButtonDef *v10; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceId rid; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+78h] [rbp+10h]
  __int64 v14; // [rsp+80h] [rbp+18h]
  __int64 v15; // [rsp+88h] [rbp+20h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v7 = v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  button GFxCharacter loader: CharId = %d\n",
    v6);
  pHeap = p->pLoadData.pObject->pHeap;
  v9 = ((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(v8, 96i64);
  v10 = (Scaleform::GFx::ButtonDef *)v9;
  v14 = v9;
  if ( v9 )
  {
    *(_QWORD *)v9 = &Scaleform::GFx::Resource::`vftable;
    *(_DWORD *)(v9 + 8) = 1;
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_QWORD *)v9 = &Scaleform::GFx::CharacterDef::`vftable;
    *(_DWORD *)(v9 + 24) = 0x40000;
    *(_QWORD *)v9 = &Scaleform::GFx::ButtonDef::`vftable;
    *(_QWORD *)(v9 + 32) = 0i64;
    *(_QWORD *)(v9 + 40) = 0i64;
    *(_QWORD *)(v9 + 48) = 0i64;
    v15 = v9 + 56;
    *(_QWORD *)(v9 + 56) = 0i64;
    *(_QWORD *)(v9 + 64) = 0i64;
    *(_QWORD *)(v9 + 72) = 0i64;
    *(_QWORD *)(v9 + 80) = 0i64;
    *(_BYTE *)(v9 + 88) = 0;
  }
  else
  {
    v10 = 0i64;
  }
  Scaleform::GFx::ButtonDef::Read(v10, p, tagInfo->TagType);
  if ( p->LoadState == LS_LoadingRoot )
  {
    rid.Id = v7;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(p->pLoadData.pObject, (Scaleform::GFx::ResourceId)&rid, v10);
  }
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
}

// File Line: 1037
// RVA: 0x870170
void __fastcall Scaleform::GFx::GFx_SetTabIndexLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  unsigned int DataSize; // eax
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rbx
  unsigned int v6; // eax

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  DataSize = pAltStream->Stream.DataSize;
  pAltStream->Stream.UnusedBits = 0;
  if ( (int)(DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  pAltStream->Stream.Pos += 2;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v6 = p_ProcessInfo->Stream.DataSize;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( (int)(v6 - p_ProcessInfo->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
  p_ProcessInfo->Stream.Pos += 2;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "SetTabIndex (unused) \n");
}

// File Line: 1053
// RVA: 0x86F610
void __fastcall Scaleform::GFx::GFx_ExportLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r9
  unsigned __int16 v5; // r8
  unsigned int v6; // ebx
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v7; // rsi
  __int64 v8; // r12
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rdi
  __int64 v10; // r8
  unsigned __int16 v11; // bx
  Scaleform::GFx::Stream *Stream; // rax
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // r15
  Scaleform::StringHashLH<Scaleform::GFx::ResourceHandle,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_Exports; // rsi
  unsigned __int64 v15; // r14
  __int64 v16; // rbx
  __int64 *v17; // rdi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 *v19; // rdi
  __int64 v20; // rbx
  __int64 v21; // rcx
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // r14
  __int64 v24; // rbx
  __int64 *v25; // rdi
  Scaleform::StringLH *v26; // rdx
  Scaleform::GFx::Resource *pResource; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::StringDH v29; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ResourceHandle phandle; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+48h] [rbp-28h] BYREF
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef v32; // [rsp+58h] [rbp-18h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+B0h] [rbp+40h] BYREF
  int v34; // [rsp+C0h] [rbp+50h] BYREF
  Scaleform::GFx::MovieDataDef::LoadTaskData *v35; // [rsp+C8h] [rbp+58h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v6 = v5;
  v7 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  export: count = %d\n",
    v5);
  if ( v6 )
  {
    v8 = v6;
    do
    {
      p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !p_ProcessInfo )
        p_ProcessInfo = &p->ProcessInfo;
      p_ProcessInfo->Stream.UnusedBits = 0;
      if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
      v10 = p_ProcessInfo->Stream.Pos;
      v11 = (unsigned __int8)p_ProcessInfo->Stream.pBuffer[v10] | ((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v10 + 1)] << 8);
      p_ProcessInfo->Stream.Pos = v10 + 2;
      Scaleform::StringDH::StringDH(&v29, p->pLoadData.pObject->pHeap);
      Stream = Scaleform::GFx::LoadProcess::GetStream(p);
      Scaleform::GFx::Stream::ReadString(Stream, &v29);
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)v7,
        "  export: id = %d, name = %s\n",
        v11,
        (const char *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      phandle.HType = RH_Pointer;
      phandle.pResource = 0i64;
      rid.Id = v11;
      if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
             p->pLoadData.pObject,
             &phandle,
             (Scaleform::GFx::ResourceId)&rid) )
      {
        v34 = v11;
        pObject = p->pLoadData.pObject;
        v35 = 0i64;
        if ( pObject->LoadState < LS_LoadFinished )
        {
          v35 = pObject;
          EnterCriticalSection(&pObject->ResourceLock.cs);
        }
        p_Exports = &pObject->Exports;
        if ( !pObject->Exports.mHash.pTable )
          goto LABEL_35;
        v15 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64) & p_Exports->mHash.pTable->SizeMask;
        v16 = v15;
        v17 = (__int64 *)(&p_Exports->mHash.pTable[2 * v15 + 1].EntryCount + v15);
        if ( *v17 == -2 || v17[1] != v15 )
          goto LABEL_35;
        while ( v17[1] != v15
             || Scaleform::String::CompareNoCase(
                  (const char *)((v17[2] & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  (const char *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
        {
          v16 = *v17;
          if ( *v17 == -1 )
            goto LABEL_35;
          v17 = (__int64 *)(&p_Exports->mHash.pTable[2 * v16 + 1].EntryCount + v16);
        }
        if ( v16 >= 0
          && pObject != (Scaleform::GFx::MovieDataDef::LoadTaskData *)-384i64
          && (pTable = p_Exports->mHash.pTable) != 0i64
          && v16 <= (signed __int64)pTable->SizeMask )
        {
          v19 = &pTable[2].SizeMask + 5 * v16;
          if ( phandle.HType == RH_Pointer && phandle.pResource )
            _InterlockedExchangeAdd(&phandle.pResource->RefCount.Value, 1u);
          if ( !*(_DWORD *)v19 )
          {
            v20 = v19[1];
            if ( v20 )
            {
              if ( !_InterlockedDecrement((volatile signed __int32 *)(v20 + 8)) )
              {
                v21 = *(_QWORD *)(v20 + 16);
                if ( v21 )
                {
                  (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v21 + 8i64))(v21, v20);
                  *(_QWORD *)(v20 + 16) = 0i64;
                }
                (**(void (__fastcall ***)(__int64, __int64))v20)(v20, 1i64);
              }
            }
          }
          *(_DWORD *)v19 = phandle.HType;
          v19[1] = (unsigned __int64)phandle.pResource;
        }
        else
        {
LABEL_35:
          key.pFirst = &v29;
          key.pSecond = &phandle;
          v22 = Scaleform::String::BernsteinHashFunctionCIS(
                  (const void *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  *(_QWORD *)(v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                  0x1505ui64);
          Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
            &pObject->Exports.mHash,
            &pObject->Exports,
            &key,
            v22);
        }
        if ( !p_Exports->mHash.pTable )
          goto LABEL_44;
        v23 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64) & p_Exports->mHash.pTable->SizeMask;
        v24 = v23;
        v25 = (__int64 *)(&p_Exports->mHash.pTable[2 * v23 + 1].EntryCount + v23);
        if ( *v25 == -2 || v25[1] != v23 )
          goto LABEL_44;
        while ( v25[1] != v23
             || Scaleform::String::CompareNoCase(
                  (const char *)((v25[2] & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  (const char *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
        {
          v24 = *v25;
          if ( *v25 == -1 )
            goto LABEL_44;
          v25 = (__int64 *)(&p_Exports->mHash.pTable[2 * v24 + 1].EntryCount + v24);
        }
        if ( v24 < 0 )
        {
LABEL_44:
          p_Exports = 0i64;
          v24 = 0i64;
        }
        v26 = (Scaleform::StringLH *)(&p_Exports->mHash.pTable[2 * v24 + 2].EntryCount + v24);
        v32.pFirst = (Scaleform::GFx::ResourceId *)&v34;
        v32.pSecond = v26;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
          &pObject->InvExports.mHash,
          &pObject->InvExports,
          &v32);
        if ( v35 )
          LeaveCriticalSection(&v35->ResourceLock.cs);
        v7 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
          v7,
          "Dont know how to export Resource %s",
          (const char *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      }
      if ( phandle.HType == RH_Pointer )
      {
        pResource = phandle.pResource;
        if ( phandle.pResource )
        {
          if ( !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
          {
            pLib = pResource->pLib;
            if ( pLib )
            {
              pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
              pResource->pLib = 0i64;
            }
            pResource->vfptr->__vecDelDtor(pResource, 1u);
          }
        }
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 1095
// RVA: 0x86FAC0
void __fastcall Scaleform::GFx::GFx_ImportLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rsi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rbx
  __int64 Pos; // r9
  unsigned __int16 v7; // r8
  __int64 v8; // r14
  const char *v9; // rdx
  Scaleform::GFx::ImportData *v10; // r15
  __int64 v11; // r8
  unsigned __int16 v12; // di
  Scaleform::GFx::Resource *pResource; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rcx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // rcx
  unsigned __int64 BytesLeft; // rdx
  char *pCurrent; // rdi
  Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *p_InitActionTags; // rbp
  unsigned __int64 Size; // rax
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // r8
  Scaleform::GFx::ExecuteTag **v23; // rcx
  Scaleform::GFx::ResourceHandle result; // [rsp+30h] [rbp-58h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::String v26; // [rsp+98h] [rbp+10h] BYREF
  Scaleform::String pstr; // [rsp+A0h] [rbp+18h] BYREF
  char *v28; // [rsp+A8h] [rbp+20h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  Scaleform::String::String(&pstr);
  Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &pstr);
  if ( tagInfo->TagType == Tag_Import2 )
  {
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
    p_ProcessInfo->Stream.Pos += 2;
  }
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v7 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v8 = v7;
  v9 = "  importAssets2: SourceUrl = %s, count = %d\n";
  if ( tagInfo->TagType != Tag_Import2 )
    v9 = "  importAssets: SourceUrl = %s, count = %d\n";
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    v9,
    (pstr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
    v7,
    -2i64);
  v10 = Scaleform::GFx::LoadProcess::AllocMovieDefClass<Scaleform::GFx::ImportData>(p);
  v10->Frame = p->pLoadData.pObject->LoadingFrame;
  Scaleform::String::operator=(&v10->SourceUrl, &pstr);
  if ( (int)v8 > 0 )
  {
    do
    {
      Scaleform::String::String(&v26);
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v11 = pAltStream->Stream.Pos;
      v12 = (unsigned __int8)pAltStream->Stream.pBuffer[v11] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v11 + 1)] << 8);
      pAltStream->Stream.Pos = v11 + 2;
      Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &v26);
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "  import: id = %d, name = %s\n",
        v12,
        (const char *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      rid.Id = v12;
      Scaleform::GFx::LoadProcess::AddNewResourceHandle(p, &result, (Scaleform::GFx::ResourceId)&rid);
      Scaleform::GFx::ImportData::AddSymbol(
        v10,
        (const char *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        v12,
        result.BindIndex);
      if ( result.HType == RH_Pointer )
      {
        pResource = result.pResource;
        if ( result.pResource )
        {
          if ( !_InterlockedDecrement(&result.pResource->RefCount.Value) )
          {
            pLib = pResource->pLib;
            if ( pLib )
            {
              pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
              pResource->pLib = 0i64;
            }
            pResource->vfptr->__vecDelDtor(pResource, 1u);
          }
        }
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      --v8;
    }
    while ( v8 );
  }
  v10->ImportIndex = p->ImportIndex++;
  if ( !p->pImportData )
    p->pImportData = v10;
  pObject = p->pLoadData.pObject;
  if ( pObject->BindData.pImports.Value )
    pObject->BindData.pImportsLast->pNext.Value = v10;
  else
    pObject->BindData.pImports.Value = v10;
  pObject->BindData.pImportsLast = v10;
  ++p->ImportDataCount;
  p_TagMemAllocator = &p->pLoadData.pObject->TagMemAllocator;
  BytesLeft = p->pLoadData.pObject->TagMemAllocator.BytesLeft;
  if ( BytesLeft < 0x10 )
  {
    pCurrent = (char *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 0x10ui64);
  }
  else
  {
    pCurrent = p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 16;
    p_TagMemAllocator->BytesLeft = BytesLeft - 16;
  }
  v28 = pCurrent;
  if ( pCurrent )
  {
    *(_QWORD *)pCurrent = &Scaleform::GFx::ExecuteTag::`vftable;
    *(_QWORD *)pCurrent = &Scaleform::GFx::GFxInitImportActions::`vftable;
    *((_DWORD *)pCurrent + 2) = 0;
  }
  else
  {
    pCurrent = 0i64;
  }
  *((_DWORD *)pCurrent + 2) = v10->ImportIndex;
  p_InitActionTags = &p->InitActionTags;
  Size = p_InitActionTags->Data.Size;
  v21 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v21 <= p_InitActionTags->Data.Policy.Capacity )
      goto LABEL_42;
    v22 = v21 + (v21 >> 2);
  }
  else
  {
    if ( v21 >= p_InitActionTags->Data.Policy.Capacity >> 1 )
      goto LABEL_42;
    v22 = Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
    &p_InitActionTags->Data,
    p_InitActionTags,
    v22);
LABEL_42:
  p_InitActionTags->Data.Size = v21;
  v23 = &p_InitActionTags->Data.Data[v21 - 1];
  if ( v23 )
    *v23 = (Scaleform::GFx::ExecuteTag *)pCurrent;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((pstr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 1155
// RVA: 0x870350
void __fastcall Scaleform::GFx::GFx_FileAttributesLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
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
  p->pLoadData.pObject->FileAttributes = v6;
}

// File Line: 1189
// RVA: 0x870200
void __fastcall Scaleform::GFx::GFx_MetadataLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rcx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rdx
  __int64 v5; // rsi
  __int64 v6; // rax
  int v7; // r8d
  int v8; // ebp
  char *v9; // r14
  Scaleform::GFx::SWFProcessInfo *v10; // rbx
  unsigned int DataSize; // eax
  __int64 Pos; // rdx
  char v13; // cl
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rbx
  char *v15; // rax
  int v16; // eax

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  p_ProcessInfo = &p->ProcessInfo;
  if ( pAltStream )
    p_ProcessInfo = pAltStream;
  v5 = 0i64;
  v6 = p_ProcessInfo->Stream.TagStackEntryCount - 1;
  if ( (unsigned int)v6 >= 2 )
    v7 = 0;
  else
    v7 = p_ProcessInfo->Stream.TagStack[v6];
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v8 = v7 + pAltStream->Stream.DataSize - pAltStream->Stream.FilePos - pAltStream->Stream.Pos;
  v9 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v8 + 1, 0i64);
  if ( v9 )
  {
    if ( v8 > 0 )
    {
      do
      {
        v10 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !v10 )
          v10 = &p->ProcessInfo;
        DataSize = v10->Stream.DataSize;
        v10->Stream.UnusedBits = 0;
        if ( (int)(DataSize - v10->Stream.Pos) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(&v10->Stream, 1);
        Pos = v10->Stream.Pos;
        ++v5;
        v13 = v10->Stream.pBuffer[Pos];
        v10->Stream.Pos = Pos + 1;
        v9[v5 - 1] = v13;
      }
      while ( v5 < v8 );
    }
    pObject = p->pLoadData.pObject;
    v15 = (char *)pObject->pHeap->vfptr->Alloc(pObject->pHeap, (unsigned int)v8, 0i64);
    pObject->pMetadata = v15;
    if ( v15 )
    {
      pObject->MetadataSize = v8;
      memmove(v15, v9, (unsigned int)v8);
    }
    v16 = 255;
    if ( v8 < 255 )
      v16 = v8;
    v9[v16] = 0;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  metadata: %s\n",
      v9);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
}

// File Line: 1235
// RVA: 0x8D4730
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::GFx_CreateImageFileResourceHandle(
        Scaleform::GFx::ResourceHandle *result,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::ResourceId *rid,
        const char *pimageFileName,
        const char *pimageExportName,
        unsigned __int16 bitmapFormat,
        unsigned __int16 targetWidth,
        unsigned __int16 targetHeight)
{
  Scaleform::GFx::ResourceFileInfo *v12; // rax
  __int64 v13; // rbx
  Scaleform::GFx::ExporterInfoImpl *p_mExporterInfo; // rax
  Scaleform::GFx::ResourceData *v15; // rax
  Scaleform::GFx::ResourceHandle *v16; // rax
  Scaleform::GFx::Resource *pResource; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceId rida[2]; // [rsp+28h] [rbp-50h] BYREF
  __int64 v21; // [rsp+30h] [rbp-48h]
  __int64 v22; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::ResourceHandle v23; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::ResourceData resulta; // [rsp+50h] [rbp-28h] BYREF

  v21 = -2i64;
  result->HType = RH_Pointer;
  result->pResource = 0i64;
  v12 = (Scaleform::GFx::ResourceFileInfo *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                              Scaleform::Memory::pGlobalHeap,
                                              56i64,
                                              0i64);
  v13 = (__int64)v12;
  *(_QWORD *)&rida[0].Id = v12;
  if ( v12 )
  {
    Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(v12);
    *(_QWORD *)v13 = &Scaleform::GFx::ImageFileInfo::`vftable;
    Scaleform::String::String((Scaleform::String *)(v13 + 48));
    *(_DWORD *)(v13 + 40) = 0;
    *(_DWORD *)(v13 + 44) = 1;
  }
  else
  {
    v13 = 0i64;
  }
  v22 = v13;
  if ( v13 )
  {
    Scaleform::String::operator=((Scaleform::String *)(v13 + 32), pimageFileName);
    Scaleform::String::operator=((Scaleform::String *)(v13 + 48), pimageExportName);
    p_mExporterInfo = &p->pLoadData.pObject->Header.mExporterInfo;
    if ( p_mExporterInfo->SI.Format == File_Unopened )
      p_mExporterInfo = 0i64;
    *(_QWORD *)(v13 + 24) = p_mExporterInfo;
    *(_DWORD *)(v13 + 16) = bitmapFormat;
    *(_WORD *)(v13 + 40) = targetWidth;
    *(_WORD *)(v13 + 42) = targetHeight;
    if ( (rid->Id & 0xFFF0000) == 393216 )
      *(_DWORD *)(v13 + 44) = 3;
    v15 = Scaleform::GFx::ImageFileResourceCreator::CreateImageFileResourceData(
            &resulta,
            (Scaleform::GFx::ImageFileInfo *)v13);
    rida[0] = (Scaleform::GFx::ResourceId)rid->Id;
    v16 = Scaleform::GFx::LoadProcess::AddDataResource(p, &v23, &rida[0].Id, v15);
    Scaleform::GFx::ResourceHandle::operator=(result, v16);
    if ( v23.HType == RH_Pointer )
    {
      pResource = v23.pResource;
      if ( v23.pResource )
      {
        if ( !_InterlockedDecrement(&v23.pResource->RefCount.Value) )
        {
          pLib = pResource->pLib;
          if ( pLib )
          {
            pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
            pResource->pLib = 0i64;
          }
          pResource->vfptr->__vecDelDtor(pResource, 1u);
        }
      }
    }
    if ( resulta.pInterface )
      resulta.pInterface->vfptr->Release(resulta.pInterface, resulta.hData);
  }
  if ( v13 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v13);
  return result;
}

// File Line: 1283
// RVA: 0x870CC0
void __fastcall Scaleform::GFx::GFx_DefineExternalImageLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rbx
  __int64 Pos; // r8
  unsigned int v6; // r14d
  Scaleform::GFx::SWFProcessInfo *v7; // rdi
  __int64 v8; // r8
  unsigned __int16 bitmapFormat; // r12
  Scaleform::GFx::SWFProcessInfo *v10; // rdi
  __int64 v11; // r8
  unsigned __int16 targetWidth; // r15
  Scaleform::GFx::SWFProcessInfo *v13; // rdi
  __int64 v14; // r8
  unsigned __int16 targetHeight; // r13
  __int64 v16; // rdx
  int v17; // ecx
  __int64 v18; // rdx
  int v19; // ecx
  Scaleform::GFx::Resource *pResource; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::String::InitStruct src; // [rsp+58h] [rbp-11h] BYREF
  Scaleform::GFx::SWFProcessInfo *v23; // [rsp+60h] [rbp-9h]
  Scaleform::String::InitStruct v24; // [rsp+68h] [rbp-1h] BYREF
  Scaleform::GFx::SWFProcessInfo *v25; // [rsp+70h] [rbp+7h]
  Scaleform::GFx::ResourceHandle result; // [rsp+78h] [rbp+Fh] BYREF
  Scaleform::String v27; // [rsp+D0h] [rbp+67h] BYREF
  unsigned int *rid; // [rsp+D8h] [rbp+6Fh] BYREF
  Scaleform::String v29; // [rsp+E0h] [rbp+77h] BYREF

  rid = (unsigned int *)tagInfo;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  p_ProcessInfo = &p->ProcessInfo;
  if ( pAltStream )
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  else
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
  Pos = pAltStream->Stream.Pos;
  v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 2)] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 3)] << 8)) << 8)) << 8);
  pAltStream->Stream.Pos = Pos + 4;
  v7 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v7 )
    v7 = &p->ProcessInfo;
  v7->Stream.UnusedBits = 0;
  if ( (signed int)(v7->Stream.DataSize - v7->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v7->Stream, 2);
  v8 = v7->Stream.Pos;
  bitmapFormat = (unsigned __int8)v7->Stream.pBuffer[v8] | ((unsigned __int8)v7->Stream.pBuffer[(unsigned int)(v8 + 1)] << 8);
  v7->Stream.Pos = v8 + 2;
  v10 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v10 )
    v10 = &p->ProcessInfo;
  v10->Stream.UnusedBits = 0;
  if ( (signed int)(v10->Stream.DataSize - v10->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v10->Stream, 2);
  v11 = v10->Stream.Pos;
  targetWidth = (unsigned __int8)v10->Stream.pBuffer[v11] | ((unsigned __int8)v10->Stream.pBuffer[(unsigned int)(v11 + 1)] << 8);
  v10->Stream.Pos = v11 + 2;
  v13 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v13 )
    v13 = &p->ProcessInfo;
  v13->Stream.UnusedBits = 0;
  if ( (signed int)(v13->Stream.DataSize - v13->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v13->Stream, 2);
  v14 = v13->Stream.Pos;
  targetHeight = (unsigned __int8)v13->Stream.pBuffer[v14] | ((unsigned __int8)v13->Stream.pBuffer[(unsigned int)(v14 + 1)] << 8);
  v13->Stream.Pos = v14 + 2;
  Scaleform::String::String(&v29);
  Scaleform::String::String(&v27);
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 1);
  v16 = p_ProcessInfo->Stream.Pos;
  v17 = (unsigned __int8)p_ProcessInfo->Stream.pBuffer[v16];
  p_ProcessInfo->Stream.Pos = v16 + 1;
  if ( v17 > 0 )
  {
    src.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength::`2::StringReader::`vftable;
    v23 = p_ProcessInfo;
    Scaleform::String::AssignString(&v29, &src, (unsigned int)v17);
    src.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  }
  else
  {
    Scaleform::String::Clear(&v29);
  }
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 1);
  v18 = p_ProcessInfo->Stream.Pos;
  v19 = (unsigned __int8)p_ProcessInfo->Stream.pBuffer[v18];
  p_ProcessInfo->Stream.Pos = v18 + 1;
  if ( v19 > 0 )
  {
    v24.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength::`2::StringReader::`vftable;
    v25 = p_ProcessInfo;
    Scaleform::String::AssignString(&v27, &v24, (unsigned int)v19);
    v24.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  }
  else
  {
    Scaleform::String::Clear(&v27);
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    &p_ProcessInfo->Stream,
    "  DefineExternalImage: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = %s, exp = %s, w = %d, h = %d\n",
    *rid,
    v6,
    bitmapFormat,
    (const char *)((v27.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    (const char *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    targetWidth,
    targetHeight);
  LODWORD(rid) = v6 & 0x9FFFF;
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &result,
    p,
    (Scaleform::GFx::ResourceId)&rid,
    (const char *)((v27.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    (const char *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    bitmapFormat,
    targetWidth,
    targetHeight);
  if ( result.HType == RH_Pointer )
  {
    pResource = result.pResource;
    if ( result.pResource )
    {
      if ( !_InterlockedDecrement(&result.pResource->RefCount.Value) )
      {
        pLib = pResource->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
          pResource->pLib = 0i64;
        }
        pResource->vfptr->__vecDelDtor(pResource, 1u);
      }
    }
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v27.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 1325
// RVA: 0x8721A0
void __fastcall Scaleform::GFx::GFx_DefineSubImageLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdi
  __int64 Pos; // r9
  unsigned __int16 v5; // r8
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rdi
  __int64 v7; // r9
  unsigned __int16 v8; // r8
  int v9; // r13d
  Scaleform::GFx::SWFProcessInfo *v10; // rdi
  __int64 v11; // r8
  unsigned __int16 v12; // r15
  Scaleform::GFx::SWFProcessInfo *v13; // rdi
  __int64 v14; // r8
  unsigned __int16 v15; // r14
  Scaleform::GFx::SWFProcessInfo *v16; // rdi
  __int64 v17; // r8
  unsigned __int16 v18; // bp
  Scaleform::GFx::SWFProcessInfo *v19; // rdi
  __int64 v20; // r8
  unsigned __int16 v21; // r12
  __int64 v22; // rdi
  Scaleform::GFx::Resource *pResource; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceData result; // [rsp+28h] [rbp-60h] BYREF
  Scaleform::GFx::ResourceHandle v26; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+90h] [rbp+8h] BYREF
  __int64 v28; // [rsp+A0h] [rbp+18h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  rid.Id = v5;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
  v7 = p_ProcessInfo->Stream.Pos;
  v8 = (unsigned __int8)p_ProcessInfo->Stream.pBuffer[v7] | ((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v7 + 1)] << 8);
  p_ProcessInfo->Stream.Pos = v7 + 2;
  v9 = v8;
  v10 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v10 )
    v10 = &p->ProcessInfo;
  v10->Stream.UnusedBits = 0;
  if ( (signed int)(v10->Stream.DataSize - v10->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v10->Stream, 2);
  v11 = v10->Stream.Pos;
  v12 = (unsigned __int8)v10->Stream.pBuffer[v11] | ((unsigned __int8)v10->Stream.pBuffer[(unsigned int)(v11 + 1)] << 8);
  v10->Stream.Pos = v11 + 2;
  v13 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v13 )
    v13 = &p->ProcessInfo;
  v13->Stream.UnusedBits = 0;
  if ( (signed int)(v13->Stream.DataSize - v13->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v13->Stream, 2);
  v14 = v13->Stream.Pos;
  v15 = (unsigned __int8)v13->Stream.pBuffer[v14] | ((unsigned __int8)v13->Stream.pBuffer[(unsigned int)(v14 + 1)] << 8);
  v13->Stream.Pos = v14 + 2;
  v16 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v16 )
    v16 = &p->ProcessInfo;
  v16->Stream.UnusedBits = 0;
  if ( (signed int)(v16->Stream.DataSize - v16->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v16->Stream, 2);
  v17 = v16->Stream.Pos;
  v18 = (unsigned __int8)v16->Stream.pBuffer[v17] | ((unsigned __int8)v16->Stream.pBuffer[(unsigned int)(v17 + 1)] << 8);
  v16->Stream.Pos = v17 + 2;
  v19 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v19 )
    v19 = &p->ProcessInfo;
  v19->Stream.UnusedBits = 0;
  if ( (signed int)(v19->Stream.DataSize - v19->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v19->Stream, 2);
  v20 = v19->Stream.Pos;
  v21 = (unsigned __int8)v19->Stream.pBuffer[v20] | ((unsigned __int8)v19->Stream.pBuffer[(unsigned int)(v20 + 1)] << 8);
  v19->Stream.Pos = v20 + 2;
  v22 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          48i64);
  v28 = v22;
  if ( v22 )
  {
    *(_QWORD *)v22 = &Scaleform::RefCountNTSImplCore::`vftable;
    *(_DWORD *)(v22 + 8) = 1;
    *(_QWORD *)v22 = &Scaleform::RefCountNTSImpl::`vftable;
    *(_QWORD *)v22 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::`vftable;
    *(_QWORD *)v22 = &Scaleform::RefCountBaseNTS<Scaleform::GFx::SubImageResourceInfo,2>::`vftable;
    *(_QWORD *)v22 = &Scaleform::GFx::SubImageResourceInfo::`vftable;
    *(_DWORD *)(v22 + 16) = 0x40000;
    *(_QWORD *)(v22 + 24) = 0i64;
    *(_QWORD *)(v22 + 32) = 0i64;
    *(_QWORD *)(v22 + 40) = 0i64;
  }
  else
  {
    v22 = 0i64;
  }
  v28 = v22;
  *(_DWORD *)(v22 + 16) = v9 | 0x90000;
  *(_DWORD *)(v22 + 32) = v12;
  *(_DWORD *)(v22 + 36) = v15;
  *(_DWORD *)(v22 + 40) = v18;
  *(_DWORD *)(v22 + 44) = v21;
  Scaleform::GFx::SubImageResourceCreator::CreateSubImageResourceData(
    &result,
    (Scaleform::GFx::SubImageResourceInfo *)v22);
  Scaleform::GFx::LoadProcess::AddDataResource(p, &v26, (Scaleform::GFx::ResourceId)&rid, &result);
  if ( v26.HType == RH_Pointer )
  {
    pResource = v26.pResource;
    if ( v26.pResource )
    {
      if ( !_InterlockedDecrement(&v26.pResource->RefCount.Value) )
      {
        pLib = pResource->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
          pResource->pLib = 0i64;
        }
        pResource->vfptr->__vecDelDtor(pResource, 1u);
      }
    }
  }
  if ( result.pInterface )
    result.pInterface->vfptr->Release(result.pInterface, result.hData);
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v22);
}

// File Line: 1481
// RVA: 0x871290
void __fastcall Scaleform::GFx::GFx_FontTextureInfoLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdi
  Scaleform::MemoryHeap *pHeap; // r13
  __int64 Pos; // r8
  unsigned int v7; // r12d
  __int64 v8; // r8
  unsigned __int16 bitmapFormat; // bx
  __int64 v10; // rdx
  int v11; // ecx
  __int64 v12; // r9
  unsigned __int16 v13; // r8
  __int64 v14; // r9
  unsigned __int16 v15; // r8
  int v16; // r15d
  __int64 v17; // rdx
  unsigned int v18; // ecx
  __int64 v19; // r9
  unsigned __int16 v20; // r8
  __int64 v21; // r9
  unsigned __int16 v22; // r8
  unsigned int v23; // r14d
  unsigned int v24; // esi
  __int64 v25; // r9
  __int64 v26; // r9
  __int64 v27; // r9
  __int64 v28; // r9
  __int64 v29; // r9
  __int64 v30; // r9
  int v31; // xmm6_4
  int v32; // xmm7_4
  int v33; // xmm8_4
  int v34; // xmm9_4
  float v35; // xmm10_4
  float v36; // xmm11_4
  Scaleform::GFx::Resource *pResource; // rax
  __int64 vfptr; // rbx
  Scaleform::Render::TextureGlyph *v39; // rbx
  __int64 v40; // rcx
  float v41; // xmm3_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  int v44; // xmm1_4
  __int64 v45; // r9
  unsigned __int16 v46; // r8
  __int64 v47; // rbx
  __int64 i; // r15
  __int64 v49; // r9
  unsigned __int16 v50; // r8
  Scaleform::GFx::FontDataUseNode *volatile Value; // rcx
  Scaleform::Render::Font *pObject; // rsi
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> *v53; // rax
  Scaleform::GFx::TextureGlyphData *v54; // rbx
  Scaleform::GFx::TextureGlyphData *v55; // rbx
  unsigned int v56; // eax
  Scaleform::GFx::TextureGlyphData *v57; // rax
  __int64 v58; // r9
  unsigned __int16 v59; // r8
  __int64 v60; // rsi
  __int64 v61; // r9
  unsigned __int16 v62; // r8
  unsigned int v63; // r14d
  __int64 v64; // r9
  unsigned __int16 v65; // r8
  unsigned __int64 Size; // rdi
  Scaleform::Render::TextureGlyph *Data; // rdx
  Scaleform::Render::TextureGlyph *v68; // rbx
  Scaleform::GFx::Resource *v69; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  char *pimageExportName; // [rsp+20h] [rbp-E0h]
  Scaleform::String v72; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+48h] [rbp-B8h] BYREF
  Scaleform::GFx::ResourceHandle result; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+70h] [rbp-90h] BYREF
  int v76; // [rsp+74h] [rbp-8Ch]
  int v77; // [rsp+78h] [rbp-88h]
  unsigned int v78; // [rsp+7Ch] [rbp-84h]
  int v79; // [rsp+80h] [rbp-80h]
  int v80; // [rsp+84h] [rbp-7Ch]
  Scaleform::GFx::ResourceId textureId; // [rsp+88h] [rbp-78h] BYREF
  Scaleform::RefCountImplCore v82; // [rsp+90h] [rbp-70h] BYREF
  __int64 v83; // [rsp+A0h] [rbp-60h]
  __int128 v84; // [rsp+B0h] [rbp-50h]
  float v85; // [rsp+C0h] [rbp-40h]
  int v86; // [rsp+C4h] [rbp-3Ch]
  unsigned int BindIndex; // [rsp+C8h] [rbp-38h]
  int targetWidth; // [rsp+D8h] [rbp-28h]
  int targetHeight; // [rsp+DCh] [rbp-24h]
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> *p_pheapAddr; // [rsp+E0h] [rbp-20h]
  Scaleform::MemoryHeap *v91; // [rsp+E8h] [rbp-18h]
  Scaleform::Render::TextureGlyph *v92; // [rsp+F0h] [rbp-10h]
  Scaleform::Render::TextureGlyph *v93; // [rsp+F8h] [rbp-8h]
  Scaleform::String::InitStruct src; // [rsp+100h] [rbp+0h] BYREF
  Scaleform::GFx::SWFProcessInfo *v95; // [rsp+108h] [rbp+8h]
  Scaleform::MemoryHeap *v96; // [rsp+110h] [rbp+10h]
  __int64 v97; // [rsp+118h] [rbp+18h]
  unsigned int v99; // [rsp+1D0h] [rbp+D0h]
  unsigned int v100; // [rsp+1D8h] [rbp+D8h]

  v97 = -2i64;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pHeap = p->pLoadData.pObject->pHeap;
  v91 = pHeap;
  v96 = pHeap;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
  Pos = pAltStream->Stream.Pos;
  v7 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 2)] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 3)] << 8)) << 8)) << 8);
  v78 = v7;
  pAltStream->Stream.Pos = Pos + 4;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - (Pos + 4)) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v8 = pAltStream->Stream.Pos;
  bitmapFormat = (unsigned __int8)pAltStream->Stream.pBuffer[v8] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v8 + 1)] << 8);
  pAltStream->Stream.Pos = v8 + 2;
  Scaleform::String::String(&v72);
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
  v10 = pAltStream->Stream.Pos;
  v11 = (unsigned __int8)pAltStream->Stream.pBuffer[v10];
  pAltStream->Stream.Pos = v10 + 1;
  if ( v11 > 0 )
  {
    src.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength::`2::StringReader::`vftable;
    v95 = pAltStream;
    Scaleform::String::AssignString(&v72, &src, (unsigned int)v11);
    src.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  }
  else
  {
    Scaleform::String::Clear(&v72);
  }
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v12 = pAltStream->Stream.Pos;
  v13 = (unsigned __int8)pAltStream->Stream.pBuffer[v12] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v12 + 1)] << 8);
  pAltStream->Stream.Pos = v12 + 2;
  targetWidth = v13;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - (v12 + 2)) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v14 = pAltStream->Stream.Pos;
  v15 = (unsigned __int8)pAltStream->Stream.pBuffer[v14] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v14 + 1)] << 8);
  pAltStream->Stream.Pos = v14 + 2;
  v16 = v15;
  targetHeight = v15;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - (v14 + 2)) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
  v17 = pAltStream->Stream.Pos;
  v18 = (unsigned __int8)pAltStream->Stream.pBuffer[v17];
  pAltStream->Stream.Pos = v17 + 1;
  v100 = v18;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - (v17 + 1)) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v19 = pAltStream->Stream.Pos;
  v20 = (unsigned __int8)pAltStream->Stream.pBuffer[v19] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v19 + 1)] << 8);
  pAltStream->Stream.Pos = v19 + 2;
  v99 = v20;
  if ( (pAltStream->Stream.ParseFlags & 1) != 0 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      &pAltStream->Stream,
      "  FontTextureInfo: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = %s, w = %d, h = %d\n",
      (unsigned int)tagInfo->TagType,
      v7,
      bitmapFormat,
      (const char *)((v72.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
      targetWidth,
      v16);
  rid.Id = v7;
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &result,
    p,
    (Scaleform::GFx::ResourceId)&rid,
    (const char *)((v72.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    &customCaption,
    bitmapFormat,
    targetWidth,
    targetHeight);
  p_pheapAddr = &pheapAddr;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v21 = pAltStream->Stream.Pos;
  v22 = (unsigned __int8)pAltStream->Stream.pBuffer[v21] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v21 + 1)] << 8);
  pAltStream->Stream.Pos = v21 + 2;
  v23 = v22;
  if ( (pAltStream->Stream.ParseFlags & 1) != 0 )
  {
    LODWORD(pimageExportName) = v22;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      &pAltStream->Stream,
      "  PadPixels = %d, nominal glyph size = %d, numTexGlyphs = %d\n",
      v100,
      v99,
      pimageExportName);
  }
  v24 = 0;
  if ( v23 )
  {
    do
    {
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v25 = pAltStream->Stream.Pos;
      v76 = (unsigned __int8)pAltStream->Stream.pBuffer[v25] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v25 + 1)] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v25 + 2)] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v25 + 3)] << 8)) << 8)) << 8);
      pAltStream->Stream.Pos = v25 + 4;
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - (v25 + 4)) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v26 = pAltStream->Stream.Pos;
      v79 = (unsigned __int8)pAltStream->Stream.pBuffer[v26] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v26 + 1)] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v26 + 2)] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v26 + 3)] << 8)) << 8)) << 8);
      pAltStream->Stream.Pos = v26 + 4;
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - (v26 + 4)) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v27 = pAltStream->Stream.Pos;
      v80 = (unsigned __int8)pAltStream->Stream.pBuffer[v27] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v27 + 1)] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v27 + 2)] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v27 + 3)] << 8)) << 8)) << 8);
      pAltStream->Stream.Pos = v27 + 4;
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - (v27 + 4)) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v28 = pAltStream->Stream.Pos;
      v77 = (unsigned __int8)pAltStream->Stream.pBuffer[v28] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v28 + 1)] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v28 + 2)] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v28 + 3)] << 8)) << 8)) << 8);
      pAltStream->Stream.Pos = v28 + 4;
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - (v28 + 4)) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v29 = pAltStream->Stream.Pos;
      LODWORD(v93) = (unsigned __int8)pAltStream->Stream.pBuffer[v29] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v29 + 1)] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v29 + 2)] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v29 + 3)] << 8)) << 8)) << 8);
      pAltStream->Stream.Pos = v29 + 4;
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - (v29 + 4)) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v30 = pAltStream->Stream.Pos;
      LODWORD(v92) = (unsigned __int8)pAltStream->Stream.pBuffer[v30] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v30 + 1)] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v30 + 2)] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v30 + 3)] << 8)) << 8)) << 8);
      pAltStream->Stream.Pos = v30 + 4;
      v31 = v76;
      v32 = v79;
      v33 = v80;
      v34 = v77;
      v35 = *(float *)&v93;
      v36 = *(float *)&v92;
      if ( (pAltStream->Stream.ParseFlags & 1) != 0 )
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          &pAltStream->Stream,
          "  TEXGLYPH[%d]: uvBnd.x1 = %f, uvBnd.y1 = %f, uvBnd.x2 = %f, uvBnd.y2 = %f\n",
          v24,
          v76,
          v79,
          v80,
          v77);
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          &pAltStream->Stream,
          "                uvOrigin.x = %f, uvOrigin.y = %f\n",
          v35,
          v36);
      }
      v82.RefCount = 1;
      v82.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureGlyph::`vftable;
      v83 = 0i64;
      v84 = 0i64;
      BindIndex = -1;
      if ( result.HType == RH_Index )
      {
        BindIndex = result.BindIndex;
      }
      else if ( result.HType == RH_Pointer
             && result.pResource
             && (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))result.pResource->vfptr->GetResourceTypeCode)(result.pResource) & 0xFF00) == 256 )
      {
        pResource = 0i64;
        if ( result.HType == RH_Pointer )
          pResource = result.pResource;
        vfptr = (__int64)pResource[1].vfptr;
        if ( vfptr )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)vfptr + 8i64))(vfptr);
        if ( v83 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v83 + 16i64))(v83);
        v83 = vfptr;
      }
      *(_QWORD *)&v84 = __PAIR64__(v32, v31);
      *((_QWORD *)&v84 + 1) = __PAIR64__(v34, v33);
      v85 = v35;
      v86 = LODWORD(v36);
      Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
      v39 = &pheapAddr.Data[pheapAddr.Size - 1];
      v92 = v39;
      v93 = v39;
      if ( v39 )
      {
        v39->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
        v39->RefCount = 1;
        v39->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
        v39->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
        v39->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::TextureGlyph,2>::`vftable;
        v39->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureGlyph::`vftable;
        v40 = v83;
        if ( v83 )
        {
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v83 + 8i64))(v83);
          v40 = v83;
        }
        v39->pImage.pObject = (Scaleform::Render::Image *)v40;
        v41 = *((float *)&v84 + 3);
        v42 = *((float *)&v84 + 2);
        v43 = *((float *)&v84 + 1);
        LODWORD(v39->UvBounds.x1) = v84;
        v39->UvBounds.y1 = v43;
        v39->UvBounds.x2 = v42;
        v39->UvBounds.y2 = v41;
        v44 = v86;
        v39->UvOrigin.x = v85;
        LODWORD(v39->UvOrigin.y) = v44;
        v39->BindIndex = BindIndex;
      }
      if ( v83 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v83 + 16i64))(v83);
      Scaleform::RefCountImplCore::~RefCountImplCore(&v82);
      ++v24;
    }
    while ( v24 < v23 );
    v7 = v78;
    pHeap = v91;
  }
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v45 = pAltStream->Stream.Pos;
  v46 = (unsigned __int8)pAltStream->Stream.pBuffer[v45] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v45 + 1)] << 8);
  pAltStream->Stream.Pos = v45 + 2;
  v47 = v46;
  if ( (pAltStream->Stream.ParseFlags & 1) != 0 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  NumFonts = %d\n", v46);
  if ( (_DWORD)v47 )
  {
    for ( i = v47; i; --i )
    {
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v49 = pAltStream->Stream.Pos;
      v50 = (unsigned __int8)pAltStream->Stream.pBuffer[v49] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v49 + 1)] << 8);
      pAltStream->Stream.Pos = v49 + 2;
      Value = p->pLoadData.pObject->BindData.pFonts.Value;
      if ( !Value )
        continue;
      while ( Value->Id.Id != v50 )
      {
        Value = Value->pNext.Value;
        if ( !Value )
          goto LABEL_96;
      }
      pObject = Value->pFontData.pObject;
      if ( !pObject )
        continue;
      v53 = (Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::Render::Font *))pObject->vfptr[11].__vecDelDtor)(Value->pFontData.pObject);
      v54 = (Scaleform::GFx::TextureGlyphData *)v53;
      if ( v53 )
        ++LODWORD(v53->Size);
      p_pheapAddr = v53;
      if ( !v53 )
      {
        v55 = (Scaleform::GFx::TextureGlyphData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pHeap->vfptr->Alloc)(
                                                    pHeap,
                                                    72i64);
        v91 = (Scaleform::MemoryHeap *)v55;
        if ( v55 )
        {
          v56 = ((__int64 (__fastcall *)(Scaleform::Render::Font *))pObject->vfptr[18].__vecDelDtor)(pObject);
          Scaleform::GFx::TextureGlyphData::TextureGlyphData(v55, v56, 1);
          v54 = v57;
        }
        else
        {
          v54 = 0i64;
        }
        p_pheapAddr = (Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> *)v54;
        if ( !v54 )
          goto LABEL_83;
        v54->PackTextureConfig.NominalSize = v99;
        v54->PackTextureConfig.PadPixels = v100;
        v54->PackTextureConfig.TextureWidth = targetWidth;
        v54->PackTextureConfig.TextureHeight = targetHeight;
        pObject->vfptr[12].__vecDelDtor(pObject, (unsigned int)v54);
      }
      textureId.Id = v7;
      Scaleform::GFx::TextureGlyphData::AddTexture(v54, (Scaleform::GFx::ResourceId)&textureId, &result);
LABEL_83:
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v58 = pAltStream->Stream.Pos;
      v59 = (unsigned __int8)pAltStream->Stream.pBuffer[v58] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v58 + 1)] << 8);
      pAltStream->Stream.Pos = v58 + 2;
      if ( v59 )
      {
        v60 = v59;
        do
        {
          pAltStream->Stream.UnusedBits = 0;
          if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v61 = pAltStream->Stream.Pos;
          v62 = (unsigned __int8)pAltStream->Stream.pBuffer[v61] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v61 + 1)] << 8);
          pAltStream->Stream.Pos = v61 + 2;
          v63 = v62;
          pAltStream->Stream.UnusedBits = 0;
          if ( (signed int)(pAltStream->Stream.DataSize - (v61 + 2)) < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v64 = pAltStream->Stream.Pos;
          v65 = (unsigned __int8)pAltStream->Stream.pBuffer[v64] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v64 + 1)] << 8);
          pAltStream->Stream.Pos = v64 + 2;
          if ( v54 )
            Scaleform::GFx::TextureGlyphData::AddTextureGlyph(v54, v63, &pheapAddr.Data[(unsigned __int64)v65]);
          --v60;
        }
        while ( v60 );
      }
      if ( v54 )
        Scaleform::RefCountNTSImpl::Release(v54);
LABEL_96:
      ;
    }
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "\n");
  Size = pheapAddr.Size;
  Data = pheapAddr.Data;
  v68 = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( pheapAddr.Size )
  {
    do
    {
      v68->vfptr->__vecDelDtor(v68, 0);
      --v68;
      --Size;
    }
    while ( Size );
    Data = pheapAddr.Data;
  }
  if ( Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( result.HType == RH_Pointer )
  {
    v69 = result.pResource;
    if ( result.pResource )
    {
      if ( !_InterlockedDecrement(&result.pResource->RefCount.Value) )
      {
        pLib = v69->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v69);
          v69->pLib = 0i64;
        }
        v69->vfptr->__vecDelDtor(v69, 1u);
      }
    }
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v72.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 1656
// RVA: 0x871F10
void __fastcall Scaleform::GFx::GFx_DefineExternalGradientImageLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r9
  unsigned __int16 v6; // r8
  unsigned int v7; // r14d
  __int64 v8; // r9
  unsigned __int16 bitmapFormat; // si
  __int64 v10; // r8
  unsigned __int16 v11; // bp
  __int64 v12; // rdx
  int v13; // ecx
  Scaleform::GFx::Resource *pResource; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::String::InitStruct src; // [rsp+48h] [rbp-50h] BYREF
  Scaleform::GFx::SWFProcessInfo *v17; // [rsp+50h] [rbp-48h]
  Scaleform::GFx::ResourceHandle result; // [rsp+58h] [rbp-40h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+A0h] [rbp+8h] BYREF
  Scaleform::String v20; // [rsp+A8h] [rbp+10h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v7 = v6 | 0x50000;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - (Pos + 2)) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v8 = pAltStream->Stream.Pos;
  bitmapFormat = (unsigned __int8)pAltStream->Stream.pBuffer[v8] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v8 + 1)] << 8);
  pAltStream->Stream.Pos = v8 + 2;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - (v8 + 2)) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v10 = pAltStream->Stream.Pos;
  v11 = (unsigned __int8)pAltStream->Stream.pBuffer[v10] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v10 + 1)] << 8);
  pAltStream->Stream.Pos = v10 + 2;
  Scaleform::String::String(&v20);
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
  v12 = pAltStream->Stream.Pos;
  v13 = (unsigned __int8)pAltStream->Stream.pBuffer[v12];
  pAltStream->Stream.Pos = v12 + 1;
  if ( v13 > 0 )
  {
    src.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength::`2::StringReader::`vftable;
    v17 = pAltStream;
    Scaleform::String::AssignString(&v20, &src, (unsigned int)v13);
    src.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  }
  else
  {
    Scaleform::String::Clear(&v20);
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    &pAltStream->Stream,
    "  DefineExternalGradientImage: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = %s, size = %d\n",
    (unsigned int)tagInfo->TagType,
    v7,
    bitmapFormat,
    (const char *)((v20.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    v11);
  rid.Id = v7;
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &result,
    p,
    (Scaleform::GFx::ResourceId)&rid,
    (const char *)((v20.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    &customCaption,
    bitmapFormat,
    0,
    0);
  if ( result.HType == RH_Pointer )
  {
    pResource = result.pResource;
    if ( result.pResource )
    {
      if ( !_InterlockedDecrement(&result.pResource->RefCount.Value) )
      {
        pLib = pResource->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
          pResource->pLib = 0i64;
        }
        pResource->vfptr->__vecDelDtor(pResource, 1u);
      }
    }
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v20.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 1697
// RVA: 0x872190
void __fastcall Scaleform::GFx::GFx_DefineGradientMapLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogWarning(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "Deprecated tag 1004 - DefineGradientMapLoader encountered, ignored");
}

// File Line: 1735
// RVA: 0x870920
void __fastcall Scaleform::GFx::GFx_Scale9GridLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r9
  unsigned __int16 v5; // r8
  unsigned int v6; // esi
  float y2; // xmm6_4
  float x2; // xmm7_4
  float y1; // xmm8_4
  float x1; // xmm9_4
  bool ResourceHandle; // al
  Scaleform::GFx::SpriteDef *pResource; // rbx
  Scaleform::GFx::ResourceHandle::HandleType HType; // edi
  Scaleform::GFx::Resource *v14; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::Render::Rect<float> pr; // [rsp+50h] [rbp-68h] BYREF
  Scaleform::GFx::ResourceHandle phandle; // [rsp+60h] [rbp-58h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+C0h] [rbp+8h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pr = 0i64;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v6 = v5;
  Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &pr);
  y2 = pr.y2;
  x2 = pr.x2;
  y1 = pr.y1;
  x1 = pr.x1;
  if ( (pAltStream->Stream.ParseFlags & 1) != 0 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Scale9GridLoader, id=%d, x1=%d, y1=%d, x2=%d, y2=%d\n",
      v6,
      (unsigned int)(int)pr.x1,
      (int)pr.y1,
      (int)pr.x2,
      (int)pr.y2);
  if ( x1 < x2 )
  {
    if ( y1 < y2 )
    {
      phandle.HType = RH_Pointer;
      phandle.pResource = 0i64;
      rid.Id = v6;
      ResourceHandle = Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                         p->pLoadData.pObject,
                         &phandle,
                         (Scaleform::GFx::ResourceId)&rid);
      pResource = (Scaleform::GFx::SpriteDef *)phandle.pResource;
      HType = phandle.HType;
      if ( ResourceHandle && phandle.HType == RH_Pointer && phandle.pResource )
      {
        if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))phandle.pResource->vfptr->GetResourceTypeCode)(phandle.pResource) & 0xFF00) == 33792 )
        {
          Scaleform::GFx::SpriteDef::SetScale9Grid(pResource, &pr);
        }
        else if ( (((__int64 (__fastcall *)(Scaleform::GFx::SpriteDef *))pResource->vfptr->GetResourceTypeCode)(pResource) & 0xFF00) == 33024 )
        {
          Scaleform::GFx::ButtonDef::SetScale9Grid((Scaleform::GFx::ButtonDef *)pResource, &pr);
        }
      }
      if ( HType == RH_Pointer && pResource && !_InterlockedDecrement(&pResource->RefCount.Value) )
      {
        v14 = phandle.pResource;
        pLib = phandle.pResource->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)phandle.pResource);
          v14->pLib = 0i64;
        }
        v14->vfptr->__vecDelDtor(v14, 1u);
      }
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogWarning(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "Scale9Grid for resource=%d has negative height %f",
        v6,
        (float)((float)(y2 - y1) * 0.050000001));
    }
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogWarning(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Scale9Grid for resource=%d has negative width %f",
      v6,
      (float)((float)(x2 - x1) * 0.050000001));
  }
}

// File Line: 1785
// RVA: 0x86F170
void __fastcall Scaleform::GFx::GFx_DoActionLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::ASSupport *pObject; // r9

  if ( (p->pLoadData.pObject->FileAttributes & 8) != 0 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "GFx_DoActionLoader - DoAction tag shouldnt appear in AS3 swf. Tag is skipped.");
  }
  else
  {
    pObject = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( pObject )
      ((void (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, Scaleform::GFx::TagInfo *))pObject->vfptr[11].__vecDelDtor)(
        pObject,
        p,
        tagInfo);
    else
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "GFx_DoActionLoader - AS2 support is not installed. Tag is skipped.");
  }
}

// File Line: 1800
// RVA: 0x8700A0
void __fastcall Scaleform::GFx::GFx_DoInitActionLoader(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::ASSupport *pObject; // r9

  if ( (p->pLoadData.pObject->FileAttributes & 8) != 0 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "GFx_DoInitActionLoader - DoInitAction tag shouldnt appear in AS3 swf. Tag is skipped.");
  }
  else
  {
    pObject = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( pObject )
      ((void (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, Scaleform::GFx::TagInfo *))pObject->vfptr[12].__vecDelDtor)(
        pObject,
        p,
        tagInfo);
    else
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "GFx_DoInitActionLoader - AS2 support is not installed. Tag is skipped.");
  }
}

// File Line: 1815
// RVA: 0x8726B0
void __fastcall Scaleform::GFx::GFx_DefineSceneAndFrameLabelData(
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 VU32; // r15
  unsigned int i; // r14d
  unsigned int v6; // esi
  unsigned int v7; // edi
  __int64 Pos; // rcx
  char v9; // dl
  unsigned int v10; // esi
  unsigned int v11; // edi
  __int64 v12; // rcx
  char v13; // dl
  int v14; // r15d
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *pObject; // r14
  __int64 Data; // r14
  unsigned int v17; // r12d
  unsigned int v18; // esi
  unsigned int v19; // edi
  __int64 v20; // rcx
  char v21; // dl
  unsigned int j; // r8d
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *v23; // rdx
  __int64 v24; // rcx
  unsigned int v25; // eax
  __int64 v26; // rdi
  Scaleform::StringDH v27; // [rsp+50h] [rbp-19h] BYREF
  Scaleform::StringDH v28; // [rsp+60h] [rbp-9h] BYREF
  Scaleform::StringDH v29; // [rsp+70h] [rbp+7h] BYREF
  unsigned int v30; // [rsp+80h] [rbp+17h]
  unsigned int v31; // [rsp+D0h] [rbp+67h]

  if ( !p->pLoadData.pObject->Scenes.pObject )
  {
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !pAltStream )
      pAltStream = &p->ProcessInfo;
    VU32 = (unsigned int)Scaleform::GFx::Stream::ReadVU32(&pAltStream->Stream);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  Scene and Frame Label Data, numscenes = %d\n",
      VU32);
    for ( i = 0; i < (unsigned int)VU32; ++i )
    {
      v6 = 0;
      v7 = 0;
      do
      {
        pAltStream->Stream.UnusedBits = 0;
        if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
        Pos = pAltStream->Stream.Pos;
        v9 = pAltStream->Stream.pBuffer[Pos];
        pAltStream->Stream.Pos = Pos + 1;
        v6 |= (v9 & 0x7F) << v7;
        v7 += 7;
      }
      while ( v7 < 0x20 && v9 < 0 );
      Scaleform::StringDH::StringDH(&v27, p->pLoadData.pObject->pHeap);
      Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &v27);
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "   Scene[%d] = { %d, \"%s\" }\n",
        i,
        v6,
        (const char *)((v27.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      Scaleform::GFx::MovieDataDef::LoadTaskData::AddScene(p->pLoadData.pObject, &v27, v6);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v27.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    v10 = 0;
    v11 = 0;
    do
    {
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
      v12 = pAltStream->Stream.Pos;
      v13 = pAltStream->Stream.pBuffer[v12];
      pAltStream->Stream.Pos = v12 + 1;
      v10 |= (v13 & 0x7F) << v11;
      v11 += 7;
    }
    while ( v11 < 0x20 && v13 < 0 );
    v31 = v10;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  frameLabelCount = %d\n",
      v10);
    v14 = 0;
    pObject = p->pLoadData.pObject->Scenes.pObject;
    if ( pObject && pObject->Data.Size )
      Data = (__int64)pObject->Data.Data;
    else
      Data = 0i64;
    v17 = 0;
    if ( v10 )
    {
      do
      {
        v18 = 0;
        v19 = 0;
        do
        {
          pAltStream->Stream.UnusedBits = 0;
          if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
          v20 = pAltStream->Stream.Pos;
          v21 = pAltStream->Stream.pBuffer[v20];
          pAltStream->Stream.Pos = v20 + 1;
          v18 |= (v21 & 0x7F) << v19;
          v19 += 7;
        }
        while ( v19 < 0x20 && v21 < 0 );
        Scaleform::StringDH::StringDH(&v28, p->pLoadData.pObject->pHeap);
        Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &v28);
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
          "   Label[%d] = { %d, \"%s\" }\n",
          v17,
          v18,
          (const char *)((v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        for ( j = v14 + 1; ; ++j )
        {
          v23 = p->pLoadData.pObject->Scenes.pObject;
          if ( !v23 )
            break;
          if ( j >= v23->Data.Size )
            break;
          v24 = (__int64)&v23->Data.Data[j];
          if ( !v24 )
            break;
          v25 = *(_DWORD *)(v24 + 16);
          if ( v18 < v25 )
            break;
          *(_DWORD *)(Data + 20) = v25;
          Data = v24;
          ++v14;
        }
        Scaleform::StringDH::CopyConstructHelper(&v29, &v28, *(Scaleform::MemoryHeap **)(Data + 8));
        v30 = v18;
        Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy> *)(Data + 24),
          *(const void **)(Data + 48),
          *(_QWORD *)(Data + 32) + 1i64);
        v26 = *(_QWORD *)(Data + 24) + 8 * (3i64 * *(_QWORD *)(Data + 32) - 3);
        if ( v26 )
        {
          Scaleform::StringDH::CopyConstructHelper((Scaleform::StringDH *)v26, &v29, v29.pHeap);
          *(_DWORD *)(v26 + 16) = v30;
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        ++v17;
      }
      while ( v17 < v31 );
    }
    *(_DWORD *)(Data + 20) = p->pLoadData.pObject->Header.FrameCount - *(_DWORD *)(Data + 16);
  }
}

// File Line: 1861
// RVA: 0x872B80
void __fastcall Scaleform::GFx::GFx_DefineBinaryData(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r10
  unsigned __int16 v5; // r9
  unsigned int v6; // ebp
  __int64 v7; // rcx
  __int64 v8; // rax
  Scaleform::GFx::Resource *v9; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceId rid; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+70h] [rbp+18h]
  __int64 v13; // [rsp+78h] [rbp+20h]

  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "Tag DefineBinaryData (87) is not supported, potentially TLF text fields are used. Switch to Classic Text.");
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  v6 = v5;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  DefineBinaryData: CharId = %d\n",
    v5);
  Scaleform::GFx::LoadProcess::ReadU32(p);
  pHeap = p->pLoadData.pObject->pHeap;
  v8 = ((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(v7, 96i64);
  v9 = (Scaleform::GFx::Resource *)v8;
  v13 = v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = &Scaleform::GFx::Resource::`vftable;
    *(_DWORD *)(v8 + 8) = 1;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)v8 = &Scaleform::GFx::CharacterDef::`vftable;
    *(_DWORD *)(v8 + 24) = 0x40000;
    *(_QWORD *)v8 = &Scaleform::GFx::ButtonDef::`vftable;
    *(_QWORD *)(v8 + 32) = 0i64;
    *(_QWORD *)(v8 + 40) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
    *(_QWORD *)(v8 + 56) = 0i64;
    *(_QWORD *)(v8 + 64) = 0i64;
    *(_QWORD *)(v8 + 72) = 0i64;
    *(_QWORD *)(v8 + 80) = 0i64;
    *(_BYTE *)(v8 + 88) = 0;
  }
  else
  {
    v9 = 0i64;
  }
  if ( p->LoadState == LS_LoadingRoot )
  {
    rid.Id = v6;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(p->pLoadData.pObject, (Scaleform::GFx::ResourceId)&rid, v9);
  }
  if ( v9 && !_InterlockedDecrement(&v9->RefCount.Value) )
  {
    pLib = v9->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v9);
      v9->pLib = 0i64;
    }
    v9->vfptr->__vecDelDtor(v9, 1u);
  }
}

