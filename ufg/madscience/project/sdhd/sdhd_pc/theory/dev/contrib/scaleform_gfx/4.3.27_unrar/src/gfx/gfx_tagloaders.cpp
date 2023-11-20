// File Line: 237
// RVA: 0x86F470
void __fastcall Scaleform::GFx::GFx_FrameLabelLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rbx
  Scaleform::GFx::Stream *v3; // rcx
  Scaleform::GFx::LogState *v4; // r8
  Scaleform::StringDH v5; // [rsp+28h] [rbp-20h]

  v2 = p;
  Scaleform::StringDH::StringDH(&v5, p->pLoadData.pObject->pHeap);
  v3 = v2->pAltStream;
  if ( !v3 )
    v3 = &v2->ProcessInfo.Stream;
  Scaleform::GFx::Stream::ReadString(v3, (Scaleform::String *)&v5.0);
  v4 = v2->pLoadStates.pObject->pLog.pObject;
  if ( v2->LoadState == 1 )
    ((void (__fastcall *)(Scaleform::GFx::TimelineIODef *, Scaleform::StringDH *, Scaleform::GFx::LogState *))v2->pTimelineDef->vfptr[4].GetKey)(
      v2->pTimelineDef,
      &v5,
      v4);
  else
    ((void (__fastcall *)(Scaleform::GFx::MovieDataDef::LoadTaskData *, Scaleform::StringDH *, Scaleform::GFx::LogState *))v2->pLoadData.pObject->vfptr[1].__vecDelDtor)(
      v2->pLoadData.pObject,
      &v5,
      v4);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
    "  Frame label: \"%s\"\n",
    (v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 249
// RVA: 0x86C880
void __fastcall Scaleform::GFx::GFx_SetBackgroundColorLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rdi
  Scaleform::GFx::SetBackgroundColorTag *v3; // rax
  Scaleform::GFx::Stream *v4; // rcx
  Scaleform::GFx::SetBackgroundColorTag *v5; // rsi
  _QWORD v6[3]; // [rsp+20h] [rbp-18h]

  v2 = p;
  v3 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::SetBackgroundColorTag>(p);
  v4 = v2->pAltStream;
  v5 = v3;
  if ( !v4 )
    v4 = &v2->ProcessInfo.Stream;
  Scaleform::GFx::Stream::ReadRgb(v4, &v3->Color);
  LODWORD(v6[0]) = (unsigned __int8)v5->Color.Channels.Blue;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
    "  SetBackgroundColor: (%d %d %d)\n",
    (unsigned __int8)v5->Color.Channels.Red,
    (unsigned __int8)v5->Color.Channels.Green,
    v6[0]);
  Scaleform::GFx::LoadProcess::AddExecuteTag(v2, (Scaleform::GFx::ExecuteTag *)&v5->vfptr);
}

// File Line: 263
// RVA: 0x86C910
void __fastcall Scaleform::GFx::GFx_JpegTablesLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // rbp
  Scaleform::GFx::LoadProcess *v3; // rbx
  Scaleform::GFx::LoadStates *v4; // rax
  Scaleform::GFx::ImageFileHandlerRegistry *v5; // rdi
  __int64 v6; // rcx
  Scaleform::Render::JPEG::ExtraData *v7; // rsi
  Scaleform::GFx::Stream *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx

  v2 = tagInfo;
  v3 = p;
  v4 = p->pLoadStates.pObject;
  v5 = v4->pImageFileHandlerRegistry.pObject;
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v4->pImageFileHandlerRegistry.pObject);
  if ( v5 )
  {
    if ( Scaleform::Render::ImageFileHandlerRegistry::GetReader(
           (Scaleform::Render::ImageFileHandlerRegistry *)&v5->vfptr,
           ImageFile_JPEG) )
    {
      if ( v2->TagLength > 0 )
      {
        v7 = (Scaleform::Render::JPEG::ExtraData *)((__int64 (__fastcall *)(__int64, signed __int64))v3->pLoadData.pObject->pHeap->vfptr->Alloc)(
                                                     v6,
                                                     32i64);
        if ( v7 )
        {
          Scaleform::Render::JPEG::ExtraData::ExtraData(v7, v3->pLoadData.pObject->pHeap, v2->TagLength);
          v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::JPEG::TablesHeader::`vftable';
        }
        else
        {
          v7 = 0i64;
        }
        v8 = v3->pAltStream;
        if ( !v8 )
          v8 = &v3->ProcessInfo.Stream;
        Scaleform::GFx::Stream::ReadToBuffer(v8, v7->Data, v2->TagLength);
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v7);
        v9 = (Scaleform::Render::RenderBuffer *)v3->pJpegTables.pObject;
        if ( v9 )
          Scaleform::RefCountImpl::Release(v9);
        v3->pJpegTables.pObject = (Scaleform::Render::JPEG::TablesHeader *)v7;
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
      }
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v3->vfptr,
        "Jpeg System is not installed - can't load jpeg image data");
    }
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v3->vfptr,
      "Image file handler registry is not installed - can't load jpeg image data");
  }
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
}

// File Line: 297
// RVA: 0x86CB70
void __fastcall Scaleform::GFx::GFx_DefineBitsJpegLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // r13
  Scaleform::GFx::LoadProcess *v3; // rdi
  Scaleform::GFx::Stream *v4; // rbx
  __int64 v5; // r8
  unsigned __int16 v6; // r12
  Scaleform::Render::ImageSource *v7; // rbx
  Scaleform::GFx::LoadStates *v8; // rax
  __int64 v9; // rbp
  Scaleform::Render::ImageFileReader *v10; // r14
  signed __int64 v11; // rsi
  int v12; // eax
  Scaleform::Render::JPEG::TablesHeader *v13; // r15
  signed __int64 v14; // rsi
  int v15; // eax
  Scaleform::Render::JPEG::TablesHeader *v16; // r9
  int v17; // eax
  int v18; // [rsp+38h] [rbp-60h]
  Scaleform::MemoryHeap *v19; // [rsp+40h] [rbp-58h]
  __int64 v20; // [rsp+48h] [rbp-50h]
  __int64 v21; // [rsp+50h] [rbp-48h]
  int v22; // [rsp+58h] [rbp-40h]
  __int64 rid; // [rsp+A0h] [rbp+8h]
  Scaleform::Render::ImageSource *v24; // [rsp+B0h] [rbp+18h]

  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v5 = v4->Pos;
  v6 = (unsigned __int8)v4->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v4->Pos = v5 + 2;
  v7 = 0i64;
  v24 = 0i64;
  v8 = v3->pLoadStates.pObject;
  v9 = (__int64)v8->pImageFileHandlerRegistry.pObject;
  if ( v9 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v8->pImageFileHandlerRegistry.pObject);
  rid = v9;
  if ( v9 )
  {
    v10 = Scaleform::Render::ImageFileHandlerRegistry::GetReader(
            (Scaleform::Render::ImageFileHandlerRegistry *)(v9 + 24),
            ImageFile_JPEG);
    if ( v10 )
    {
      v11 = (signed __int64)v3->pAltStream;
      if ( !v11 )
        v11 = (signed __int64)&v3->ProcessInfo;
      v12 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))(**(_QWORD **)(v11 + 32) + 112i64))(
              *(_QWORD *)(v11 + 32),
              (unsigned int)(*(_DWORD *)(v11 + 76) + *(_DWORD *)(v11 + 84) - *(_DWORD *)(v11 + 80)),
              0i64);
      if ( v12 != -1 )
      {
        *(_QWORD *)(v11 + 76) = 0i64;
        *(_DWORD *)(v11 + 84) = v12;
      }
      v13 = v3->pJpegTables.pObject;
      v18 = 0;
      v19 = 0i64;
      v20 = 0i64;
      v21 = 0i64;
      v22 = 0;
      v14 = (signed __int64)v3->pAltStream;
      v19 = v3->pLoadData.pObject->pHeap;
      if ( v13 )
      {
        if ( !v14 )
          v14 = (signed __int64)&v3->ProcessInfo;
        v15 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))(**(_QWORD **)(v14 + 32) + 112i64))(
                *(_QWORD *)(v14 + 32),
                (unsigned int)(*(_DWORD *)(v14 + 76) + *(_DWORD *)(v14 + 84) - *(_DWORD *)(v14 + 80)),
                0i64);
        if ( v15 != -1 )
        {
          *(_QWORD *)(v14 + 76) = 0i64;
          *(_DWORD *)(v14 + 84) = v15;
        }
        v16 = v13;
      }
      else
      {
        if ( !v14 )
          v14 = (signed __int64)&v3->ProcessInfo;
        v17 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))(**(_QWORD **)(v14 + 32) + 112i64))(
                *(_QWORD *)(v14 + 32),
                (unsigned int)(*(_DWORD *)(v14 + 76) + *(_DWORD *)(v14 + 84) - *(_DWORD *)(v14 + 80)),
                0i64);
        if ( v17 != -1 )
        {
          *(_QWORD *)(v14 + 76) = 0i64;
          *(_DWORD *)(v14 + 84) = v17;
        }
        v16 = 0i64;
      }
      *(_BYTE *)(v14 + 88) = 1;
      v24 = (Scaleform::Render::ImageSource *)((__int64 (__fastcall *)(Scaleform::Render::ImageFileReader *, _QWORD, int *, Scaleform::Render::JPEG::TablesHeader *, _QWORD, _BYTE, signed __int64, _QWORD, Scaleform::MemoryHeap *, __int64, __int64, _QWORD))v10->vfptr[1].IsWriter)(
                                                v10,
                                                *(_QWORD *)(v14 + 32),
                                                &v18,
                                                v16,
                                                v2->TagLength - 2,
                                                0,
                                                -2i64,
                                                *(_QWORD *)&v18,
                                                v19,
                                                v20,
                                                v21,
                                                *(_QWORD *)&v22);
      v7 = v24;
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v3->vfptr,
        "Jpeg System is not installed - can't load jpeg image data");
    }
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v3->vfptr,
      "Image file handler registry is not installed - can't load jpeg image data");
  }
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
  LODWORD(rid) = v6;
  Scaleform::GFx::LoadProcess::AddImageResource(v3, (Scaleform::GFx::ResourceId)&rid, v7);
  if ( v7 )
    ((void (__fastcall *)(Scaleform::Render::ImageSource *))v7->vfptr[2].__vecDelDtor)(v7);
}

// File Line: 360
// RVA: 0x86CE20
void __fastcall Scaleform::GFx::GFx_DefineBitsJpeg2Loader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // r13
  Scaleform::GFx::LoadProcess *v3; // rdi
  Scaleform::GFx::Stream *v4; // rbx
  __int64 v5; // r8
  unsigned __int16 v6; // r9
  Scaleform::GFx::SWFProcessInfo *v7; // rax
  int v8; // er15
  Scaleform::Render::ImageSource *v9; // rbx
  Scaleform::GFx::LoadStates *v10; // rax
  __int64 v11; // rbp
  Scaleform::Render::ImageFileReader *v12; // r14
  signed __int64 v13; // rsi
  int v14; // eax
  int v15; // [rsp+38h] [rbp-50h]
  Scaleform::MemoryHeap *v16; // [rsp+40h] [rbp-48h]
  __int64 v17; // [rsp+48h] [rbp-40h]
  __int64 v18; // [rsp+50h] [rbp-38h]
  int v19; // [rsp+58h] [rbp-30h]
  __int64 rid; // [rsp+90h] [rbp+8h]
  Scaleform::Render::ImageSource *v21; // [rsp+A0h] [rbp+18h]

  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v5 = v4->Pos;
  v6 = (unsigned __int8)v4->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v4->Pos = v5 + 2;
  v7 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
  if ( !v7 )
    v7 = &v3->ProcessInfo;
  v8 = v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
    "  GFx_DefineBitsJpeg2Loader: charid = %d pos = 0x%x\n",
    v6,
    v7->Stream.Pos + v7->Stream.FilePos - v7->Stream.DataSize);
  v9 = 0i64;
  v21 = 0i64;
  v10 = v3->pLoadStates.pObject;
  v11 = (__int64)v10->pImageFileHandlerRegistry.pObject;
  if ( v11 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v10->pImageFileHandlerRegistry.pObject);
  rid = v11;
  if ( v11 )
  {
    v12 = Scaleform::Render::ImageFileHandlerRegistry::GetReader(
            (Scaleform::Render::ImageFileHandlerRegistry *)(v11 + 24),
            ImageFile_JPEG);
    if ( v12 )
    {
      v15 = 0;
      v16 = 0i64;
      v17 = 0i64;
      v18 = 0i64;
      v19 = 0;
      v16 = v3->pLoadData.pObject->pHeap;
      v13 = (signed __int64)v3->pAltStream;
      if ( !v13 )
        v13 = (signed __int64)&v3->ProcessInfo;
      v14 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))(**(_QWORD **)(v13 + 32) + 112i64))(
              *(_QWORD *)(v13 + 32),
              (unsigned int)(*(_DWORD *)(v13 + 76) + *(_DWORD *)(v13 + 84) - *(_DWORD *)(v13 + 80)),
              0i64);
      if ( v14 != -1 )
      {
        *(_QWORD *)(v13 + 76) = 0i64;
        *(_DWORD *)(v13 + 84) = v14;
      }
      *(_BYTE *)(v13 + 88) = 1;
      v9 = (Scaleform::Render::ImageSource *)((__int64 (__fastcall *)(Scaleform::Render::ImageFileReader *, _QWORD, int *, _QWORD, _QWORD, char, signed __int64, _QWORD, Scaleform::MemoryHeap *, __int64, __int64, _QWORD))v12->vfptr[1].IsWriter)(
                                               v12,
                                               *(_QWORD *)(v13 + 32),
                                               &v15,
                                               0i64,
                                               v2->TagLength - 2,
                                               1,
                                               -2i64,
                                               *(_QWORD *)&v15,
                                               v16,
                                               v17,
                                               v18,
                                               *(_QWORD *)&v19);
      v21 = v9;
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v3->vfptr,
        "Jpeg System is not installed - can't load jpeg image data");
    }
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v3->vfptr,
      "Image file handler registry is not installed - can't load jpeg image data");
  }
  if ( v11 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v11);
  LODWORD(rid) = v8;
  Scaleform::GFx::LoadProcess::AddImageResource(v3, (Scaleform::GFx::ResourceId)&rid, v9);
  if ( v9 )
    ((void (__fastcall *)(Scaleform::Render::ImageSource *))v9->vfptr[2].__vecDelDtor)(v9);
}

// File Line: 484
// RVA: 0x86D020
void __fastcall Scaleform::GFx::GFx_DefineBitsJpeg3Loader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // rbp
  Scaleform::GFx::LoadProcess *v3; // rbx
  Scaleform::GFx::Stream *v4; // rdi
  __int64 v5; // r8
  unsigned __int16 v6; // si
  Scaleform::GFx::Stream *v7; // rdi
  __int64 v8; // r8
  unsigned __int16 v9; // r9
  Scaleform::GFx::SWFProcessInfo *v10; // rcx
  unsigned int v11; // edi
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v12; // rsi
  Scaleform::GFx::SWFProcessInfo *v13; // rax
  _QWORD v14[2]; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::ResourceId rid; // [rsp+60h] [rbp+8h]
  __int64 v16; // [rsp+68h] [rbp+10h]

  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v5 = v4->Pos;
  v6 = (unsigned __int8)v4->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v4->Pos = v5 + 2;
  Scaleform::GFx::LoadProcess::ReadU32(v3);
  if ( v2->TagType == 90 )
  {
    v7 = v3->pAltStream;
    if ( !v7 )
      v7 = &v3->ProcessInfo.Stream;
    v7->UnusedBits = 0;
    if ( (signed int)(v7->DataSize - v7->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v7, 2);
    v8 = v7->Pos;
    v9 = (unsigned __int8)v7->pBuffer[v8] | (unsigned __int16)((unsigned __int8)v7->pBuffer[(unsigned int)(v8 + 1)] << 8);
    v7->Pos = v8 + 2;
    v10 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
    if ( !v10 )
      v10 = &v3->ProcessInfo;
    v11 = v6;
    v12 = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v3->vfptr;
    LODWORD(v14[0]) = v9;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
      "  GFx_DefineBitsJpeg4Loader: charid = %d pos = %d deblocking = %d\n",
      v11,
      v10->Stream.Pos + v10->Stream.FilePos - v10->Stream.DataSize,
      v14[0]);
  }
  else
  {
    v13 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
    if ( !v13 )
      v13 = &v3->ProcessInfo;
    v11 = v6;
    v12 = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v3->vfptr;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
      "  GFx_DefineBitsJpeg3Loader: charid = %d pos = %d\n",
      v11,
      v13->Stream.Pos + v13->Stream.FilePos - v13->Stream.DataSize);
  }
  v16 = 0i64;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
    v12,
    "zlib or jpeglib are not linked - can't load jpeg+zipped image data!");
  rid.Id = v11;
  Scaleform::GFx::LoadProcess::AddImageResource(v3, (Scaleform::GFx::ResourceId)&rid, 0i64);
}

// File Line: 565
// RVA: 0x86E4A0
void __fastcall Scaleform::GFx::GFx_DefineBitsLossless2Loader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  unsigned int *v2; // rsi
  Scaleform::GFx::LoadProcess *v3; // rdi
  Scaleform::GFx::Stream *v4; // rbx
  __int64 v5; // r8
  unsigned __int16 v6; // r14
  Scaleform::GFx::Stream *v7; // rbx
  __int64 v8; // rcx
  unsigned __int8 v9; // bp
  Scaleform::GFx::Stream *v10; // rbx
  __int64 v11; // r8
  unsigned __int16 v12; // r15
  Scaleform::GFx::Stream *v13; // rbx
  __int64 v14; // r9
  unsigned __int16 v15; // r8
  int v16; // er12
  int v17; // er13
  Scaleform::Render::ImageSource *v18; // rbx
  Scaleform::GFx::Resource *v19; // r14
  __int16 v20; // r15
  Scaleform::GFx::SWFProcessInfo *v21; // rax
  int v22; // ebp
  __int64 v23; // rsi
  Scaleform::File *v24; // rax
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
  __int64 v46; // [rsp+20h] [rbp-68h]
  __int64 v47; // [rsp+28h] [rbp-60h]
  _QWORD v48[2]; // [rsp+30h] [rbp-58h]
  Scaleform::GFx::ResourceId rid; // [rsp+90h] [rbp+8h]
  Scaleform::Render::ImageSource *v50; // [rsp+98h] [rbp+10h]
  __int64 v51; // [rsp+A0h] [rbp+18h]

  v2 = (unsigned int *)tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v5 = v4->Pos;
  v6 = (unsigned __int8)v4->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v4->Pos = v5 + 2;
  v7 = v3->pAltStream;
  if ( !v7 )
    v7 = &v3->ProcessInfo.Stream;
  v7->UnusedBits = 0;
  if ( (signed int)(v7->DataSize - v7->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v7, 1);
  v8 = v7->Pos;
  v9 = v7->pBuffer[v8];
  v7->Pos = v8 + 1;
  v10 = v3->pAltStream;
  if ( !v10 )
    v10 = &v3->ProcessInfo.Stream;
  v10->UnusedBits = 0;
  if ( (signed int)(v10->DataSize - v10->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v10, 2);
  v11 = v10->Pos;
  v12 = (unsigned __int8)v10->pBuffer[v11] | (unsigned __int16)((unsigned __int8)v10->pBuffer[(unsigned int)(v11 + 1)] << 8);
  v10->Pos = v11 + 2;
  v13 = v3->pAltStream;
  if ( !v13 )
    v13 = &v3->ProcessInfo.Stream;
  v13->UnusedBits = 0;
  if ( (signed int)(v13->DataSize - v13->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v13, 2);
  v14 = v13->Pos;
  v15 = (unsigned __int8)v13->pBuffer[v14] | (unsigned __int16)((unsigned __int8)v13->pBuffer[(unsigned int)(v14 + 1)] << 8);
  v13->Pos = v14 + 2;
  v16 = v15;
  v17 = v12;
  rid.Id = v6;
  LODWORD(v48[0]) = v15;
  LODWORD(v47) = v12;
  LODWORD(v46) = v9;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
    "  DefBitsLossless2: tagInfo.TagType = %d, id = %d, fmt = %d, w = %d, h = %d\n",
    *v2,
    v6,
    v46,
    v47,
    v48[0]);
  v18 = 0i64;
  v50 = 0i64;
  v19 = (Scaleform::GFx::Resource *)v3->pLoadStates.pObject->pZlibSupport.pObject;
  if ( !v19 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v3->vfptr,
      "Error: GFxZlibState is not set - can't load zipped image data\n");
    goto LABEL_56;
  }
  if ( *v2 == 20 )
  {
    switch ( v9 )
    {
      case 3u:
        v20 = (unsigned __int8)Scaleform::GFx::LoadProcess::ReadU8(v3) + 1;
        v21 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
        if ( !v21 )
          v21 = &v3->ProcessInfo;
        v22 = v2[2] + v2[3] + v21->Stream.DataSize - v21->Stream.FilePos - v21->Stream.Pos;
        v23 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v51 = v23;
        if ( v23 )
        {
          v24 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(v3);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v23,
            v24,
            Image_R8G8B8,
            v22);
          *(_QWORD *)v23 = &Scaleform::GFx::ZlibImageSource::`vftable';
          Scaleform::Render::RenderBuffer::AddRef(v19);
          *(_QWORD *)(v23 + 56) = v19;
          *(_WORD *)(v23 + 64) = v20;
          *(_DWORD *)(v23 + 68) = 0;
          *(_DWORD *)(v23 + 20) = v17;
          *(_DWORD *)(v23 + 24) = v16;
          v18 = (Scaleform::Render::ImageSource *)v23;
        }
        break;
      case 4u:
        v25 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
        if ( !v25 )
          v25 = &v3->ProcessInfo;
        v26 = v2[2] + v2[3] + v25->Stream.DataSize - v25->Stream.FilePos - v25->Stream.Pos;
        v27 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v51 = v27;
        if ( v27 )
        {
          v28 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(v3);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v27,
            v28,
            Image_R8G8B8,
            v26);
          *(_QWORD *)v27 = &Scaleform::GFx::ZlibImageSource::`vftable';
          Scaleform::Render::RenderBuffer::AddRef(v19);
          *(_QWORD *)(v27 + 56) = v19;
          *(_WORD *)(v27 + 64) = 0;
          *(_DWORD *)(v27 + 68) = 1;
          *(_DWORD *)(v27 + 20) = v12;
          *(_DWORD *)(v27 + 24) = v16;
          v18 = (Scaleform::Render::ImageSource *)v27;
        }
        break;
      case 5u:
        v29 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
        if ( !v29 )
          v29 = &v3->ProcessInfo;
        v30 = v2[2] + v2[3] + v29->Stream.DataSize - v29->Stream.FilePos - v29->Stream.Pos;
        v31 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v51 = v31;
        if ( v31 )
        {
          v32 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(v3);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v31,
            v32,
            Image_R8G8B8,
            v30);
          *(_QWORD *)v31 = &Scaleform::GFx::ZlibImageSource::`vftable';
          Scaleform::Render::RenderBuffer::AddRef(v19);
          *(_QWORD *)(v31 + 56) = v19;
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
        v33 = (unsigned __int8)Scaleform::GFx::LoadProcess::ReadU8(v3) + 1;
        v34 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
        if ( !v34 )
          v34 = &v3->ProcessInfo;
        v35 = v2[2] + v2[3] + v34->Stream.DataSize - v34->Stream.FilePos - v34->Stream.Pos;
        v36 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v51 = v36;
        if ( v36 )
        {
          v37 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(v3);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v36,
            v37,
            Image_R8G8B8A8,
            v35);
          *(_QWORD *)v36 = &Scaleform::GFx::ZlibImageSource::`vftable';
          Scaleform::Render::RenderBuffer::AddRef(v19);
          *(_QWORD *)(v36 + 56) = v19;
          *(_WORD *)(v36 + 64) = v33;
          *(_DWORD *)(v36 + 68) = 3;
          *(_DWORD *)(v36 + 20) = v17;
          *(_DWORD *)(v36 + 24) = v16;
          v18 = (Scaleform::Render::ImageSource *)v36;
        }
        break;
      case 4u:
        v38 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
        if ( !v38 )
          v38 = &v3->ProcessInfo;
        v39 = v2[2] + v2[3] + v38->Stream.DataSize - v38->Stream.FilePos - v38->Stream.Pos;
        v40 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v51 = v40;
        if ( v40 )
        {
          v41 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(v3);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v40,
            v41,
            Image_R8G8B8A8,
            v39);
          *(_QWORD *)v40 = &Scaleform::GFx::ZlibImageSource::`vftable';
          Scaleform::Render::RenderBuffer::AddRef(v19);
          *(_QWORD *)(v40 + 56) = v19;
          *(_WORD *)(v40 + 64) = 0;
          *(_DWORD *)(v40 + 68) = 1;
          *(_DWORD *)(v40 + 20) = v12;
          *(_DWORD *)(v40 + 24) = v16;
          v18 = (Scaleform::Render::ImageSource *)v40;
        }
        break;
      case 5u:
        v42 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
        if ( !v42 )
          v42 = &v3->ProcessInfo;
        v43 = v2[2] + v2[3] + v42->Stream.DataSize - v42->Stream.FilePos - v42->Stream.Pos;
        v44 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                Scaleform::Memory::pGlobalHeap,
                72i64);
        v51 = v44;
        if ( v44 )
        {
          v45 = Scaleform::GFx::LoadProcess::GetUnderlyingFile(v3);
          Scaleform::Render::FileImageSource::FileImageSource(
            (Scaleform::Render::FileImageSource *)v44,
            v45,
            Image_R8G8B8A8,
            v43);
          *(_QWORD *)v44 = &Scaleform::GFx::ZlibImageSource::`vftable';
          Scaleform::Render::RenderBuffer::AddRef(v19);
          *(_QWORD *)(v44 + 56) = v19;
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
  v50 = v18;
LABEL_56:
  Scaleform::GFx::LoadProcess::AddImageResource(v3, (Scaleform::GFx::ResourceId)&rid, v18);
  if ( v18 )
    ((void (__fastcall *)(Scaleform::Render::ImageSource *))v18->vfptr[2].__vecDelDtor)(v18);
}

// File Line: 671
// RVA: 0x86D2B0
void __fastcall Scaleform::GFx::GFx_DefineShapeLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // rdi
  Scaleform::GFx::LoadProcess *v3; // rbp
  Scaleform::GFx::Stream *v4; // rbx
  __int64 v5; // r9
  unsigned __int16 v6; // r8
  unsigned int v7; // er14
  __int64 v8; // rcx
  Scaleform::GFx::ShapeDataBase *v9; // rbx
  Scaleform::GFx::SWFProcessInfo *v10; // rcx
  __int64 v11; // rcx
  Scaleform::GFx::SwfShapeCharacterDef *v12; // rax
  Scaleform::GFx::Resource *v13; // rax
  Scaleform::GFx::Resource *v14; // rdi
  Scaleform::GFx::ResourceLibBase *v15; // rcx
  char v16; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::ResourceId rid; // [rsp+90h] [rbp+8h]
  Scaleform::MemoryHeap *v18; // [rsp+98h] [rbp+10h]
  void *v19; // [rsp+A0h] [rbp+18h]
  Scaleform::GFx::ShapeDataBase *v20; // [rsp+A8h] [rbp+20h]

  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v5 = v4->Pos;
  v6 = (unsigned __int8)v4->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v4->Pos = v5 + 2;
  v7 = v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
    "  ShapeLoader: id = %d\n",
    v6);
  v18 = v3->pLoadData.pObject->pHeap;
  v9 = (Scaleform::GFx::ShapeDataBase *)((__int64 (__fastcall *)(__int64, signed __int64))v18->vfptr->Alloc)(v8, 80i64);
  v19 = v9;
  if ( v9 )
  {
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
    v9->RefCount = 1;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable';
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable';
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable';
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ShapeDataBase::`vftable';
    v9->Paths = 0i64;
    v9->Flags = 0;
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable';
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
  v10 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
  if ( !v10 )
    v10 = &v3->ProcessInfo;
  ((void (__fastcall *)(Scaleform::GFx::ShapeDataBase *, Scaleform::GFx::LoadProcess *, _QWORD, _QWORD, char))v9->vfptr[15].__vecDelDtor)(
    v9,
    v3,
    (unsigned int)v2->TagType,
    v2->TagLength + v2->TagDataOffset - (v10->Stream.Pos + v10->Stream.FilePos - v10->Stream.DataSize),
    1);
  v18 = v3->pLoadData.pObject->pHeap;
  v12 = (Scaleform::GFx::SwfShapeCharacterDef *)((__int64 (__fastcall *)(__int64, signed __int64))v18->vfptr->Alloc)(
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
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
    "  bound rect:");
  ((void (__fastcall *)(Scaleform::GFx::Resource *, char *))v14->vfptr[1].GetResourceReport)(v14, &v16);
  if ( v3->LoadState == LS_LoadingRoot )
  {
    rid.Id = v7;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
      v3->pLoadData.pObject,
      (Scaleform::GFx::ResourceId)&rid,
      v14);
  }
  if ( !_InterlockedDecrement(&v14->RefCount.Value) )
  {
    v15 = v14->pLib;
    if ( v15 )
    {
      v15->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, (unsigned int)v14);
      v14->pLib = 0i64;
    }
    v14->vfptr->__vecDelDtor(v14, 1u);
  }
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
}

// File Line: 696
// RVA: 0x86D4E0
void __fastcall Scaleform::GFx::GFx_DefineShapeMorphLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
    (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->vfptr,
    "ShapeMorphLoader failed due to SF_NO_MORPHING_SUPPORT macro");
}

// File Line: 719
// RVA: 0x86D700
void __fastcall Scaleform::GFx::GFx_DefineFontLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // rsi
  Scaleform::GFx::LoadProcess *v3; // rdi
  Scaleform::GFx::Stream *v4; // rbx
  __int64 v5; // r9
  unsigned __int16 v6; // r8
  int v7; // er14
  Scaleform::MemoryHeap *v8; // rcx
  Scaleform::GFx::FontData *v9; // rbx
  Scaleform::GFx::FontData *v10; // rax
  Scaleform::GFx::FontData *v11; // rax
  Scaleform::GFx::Resource *v12; // rdi
  Scaleform::GFx::ResourceLibBase *v13; // rcx
  Scaleform::GFx::ResourceHandle result; // [rsp+28h] [rbp-40h]
  Scaleform::MemoryHeap *rid; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::FontData *v16; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::FontData *v17; // [rsp+80h] [rbp+18h]

  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v5 = v4->Pos;
  v6 = (unsigned __int8)v4->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v4->Pos = v5 + 2;
  v7 = v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
    "  Font: id = %d\n",
    v6);
  v9 = 0i64;
  v16 = 0i64;
  if ( v2->TagType == 1005 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v3->vfptr,
      "Trying to load compacted font with SF_NO_COMPACTED_FONT_SUPPORT defined.");
  }
  else
  {
    rid = v3->pLoadData.pObject->pHeap;
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
    Scaleform::GFx::FontData::Read(v9, v3, v2);
    LODWORD(rid) = v7;
    Scaleform::GFx::LoadProcess::AddFontDataResource(
      v3,
      &result,
      (Scaleform::GFx::ResourceId)&rid,
      (Scaleform::Render::Font *)&v9->vfptr);
    if ( result.HType == RH_Pointer )
    {
      v12 = result.pResource;
      if ( result.pResource )
      {
        if ( !_InterlockedDecrement(&result.pResource->RefCount.Value) )
        {
          v13 = v12->pLib;
          if ( v13 )
          {
            v13->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, (unsigned int)v12);
            v12->pLib = 0i64;
          }
          v12->vfptr->__vecDelDtor(v12, 1u);
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
  Scaleform::GFx::LoadProcess *v2; // rdi
  signed __int64 v3; // rbp
  Scaleform::GFx::Stream *v4; // rbx
  __int64 v5; // rdx
  int v6; // ecx
  char buf; // [rsp+60h] [rbp+18h]
  Scaleform::String v8; // [rsp+68h] [rbp+20h]

  v2 = p;
  Scaleform::String::String(&v8);
  v3 = 16i64;
  do
  {
    v4 = v2->pAltStream;
    if ( !v4 )
      v4 = &v2->ProcessInfo.Stream;
    v4->UnusedBits = 0;
    if ( (signed int)(v4->DataSize - v4->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(v4, 1);
    v5 = v4->Pos;
    v6 = (unsigned __int8)v4->pBuffer[v5];
    v4->Pos = v5 + 1;
    itoa_s(v6, &buf, 3ui64, 16);
    Scaleform::String::AppendString(&v8, &buf, -1i64);
    --v3;
  }
  while ( v3 );
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8), 0xFFFFFFFF) == 1 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 789
// RVA: 0x86DB30
void __fastcall Scaleform::GFx::GFx_DefineFontInfoLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::Stream *v2; // rbx
  Scaleform::GFx::TagInfo *v3; // rsi
  Scaleform::GFx::LoadProcess *v4; // rdi
  unsigned int v5; // eax
  __int64 v6; // r9
  unsigned __int16 v7; // r8
  Scaleform::GFx::FontDataUseNode *volatile v8; // rax
  Scaleform::GFx::FontData *v9; // rcx
  Scaleform::GFx::Stream *v10; // rdx

  v2 = p->pAltStream;
  v3 = tagInfo;
  v4 = p;
  if ( !v2 )
    v2 = &p->ProcessInfo.Stream;
  v5 = v2->DataSize;
  v2->UnusedBits = 0;
  if ( (signed int)(v5 - v2->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v2, 2);
  v6 = v2->Pos;
  v7 = (unsigned __int8)v2->pBuffer[v6] | (unsigned __int16)((unsigned __int8)v2->pBuffer[(unsigned int)(v6 + 1)] << 8);
  v2->Pos = v6 + 2;
  v8 = v4->pLoadData.pObject->BindData.pFonts.Value;
  if ( !v8 )
    goto LABEL_8;
  while ( v8->Id.Id != v7 )
  {
    v8 = v8->pNext.Value;
    if ( !v8 )
      goto LABEL_8;
  }
  v9 = (Scaleform::GFx::FontData *)v8->pFontData.pObject;
  if ( v9 )
  {
    v10 = v4->pAltStream;
    if ( !v10 )
      v10 = &v4->ProcessInfo.Stream;
    Scaleform::GFx::FontData::ReadFontInfo(v9, v10, v3->TagType);
  }
  else
  {
LABEL_8:
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v4->vfptr,
      "GFx_DefineFontInfoLoader - can't find FontResource w/ id %d");
  }
}

// File Line: 813
// RVA: 0x86DF60
void __fastcall Scaleform::GFx::GFx_PlaceObjectLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // r14
  Scaleform::GFx::Stream *v3; // rbp
  __int64 v4; // rax
  int v5; // edx
  unsigned __int64 v6; // rdi
  Scaleform::GFx::PlaceObjectTag *v7; // rax
  const char *v8; // rbx
  Scaleform::GFx::PlaceObjectTag *v9; // rsi
  Scaleform::GFx::StreamContext v10; // [rsp+20h] [rbp-48h]
  Scaleform::Render::Matrix2x4<float> pm; // [rsp+40h] [rbp-28h]

  v2 = p;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->vfptr,
    "  PlaceObject\n");
  v3 = v2->pAltStream;
  if ( !v3 )
    v3 = &v2->ProcessInfo.Stream;
  v4 = v3->TagStackEntryCount - 1;
  if ( (unsigned int)v4 >= 2 )
    v5 = 0;
  else
    v5 = v3->TagStack[v4];
  v6 = v5 - (v3->Pos + v3->FilePos - v3->DataSize);
  v7 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObjectTag>(v2, v6);
  v8 = v7->pData;
  v9 = v7;
  Scaleform::GFx::Stream::ReadToBuffer(v3, v7->pData, v6);
  v10.pData = v8;
  v10.DataSize = -1i64;
  v10.CurBitIndex = 0;
  v10.CurByteIndex = 4i64;
  Scaleform::GFx::StreamContext::ReadMatrix(&v10, &pm);
  v9->HasCxForm = v10.CurByteIndex < v6 - 1;
  Scaleform::GFx::LoadProcess::AddExecuteTag(v2, (Scaleform::GFx::ExecuteTag *)&v9->vfptr);
}

// File Line: 826
// RVA: 0x86E1D0
void __fastcall Scaleform::GFx::GFx_PlaceObject2Loader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rbx
  Scaleform::GFx::Stream *v3; // rdi
  __int64 v4; // rax
  int v5; // edx
  unsigned __int64 v6; // rbp
  bool v7; // r14
  Scaleform::GFx::MovieDataDef::LoadTaskData *v8; // r8
  Scaleform::GFx::ASSupport *v9; // rcx
  Scaleform::GFx::PlaceObject2Taga *v10; // rax
  Scaleform::GFx::PlaceObject2Taga *v11; // rsi
  char v12; // al

  v2 = p;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->vfptr,
    "  PlaceObject2Tag\n");
  v3 = v2->pAltStream;
  if ( !v3 )
    v3 = &v2->ProcessInfo.Stream;
  v4 = v3->TagStackEntryCount - 1;
  if ( (unsigned int)v4 >= 2 )
    v5 = 0;
  else
    v5 = v3->TagStack[v4];
  v6 = v5 - (v3->Pos + v3->FilePos - v3->DataSize);
  v7 = Scaleform::GFx::PlaceObject2Tag::HasEventHandlers(v3);
  if ( !v7 || (v8 = v2->pLoadData.pObject, v6 += 8i64, v8->FileAttributes & 8) )
  {
    if ( v2->pLoadData.pObject->Header.Version < 6u )
      v10 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject2Taga>(v2, v6);
    else
      v10 = (Scaleform::GFx::PlaceObject2Taga *)Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject2Tag>(
                                                  v2,
                                                  v6);
  }
  else
  {
    v9 = v2->pLoadStates.pObject->pAS2Support.pObject;
    if ( !v9 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v2->vfptr,
        "GFx_PlaceObject2Loader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    v10 = (Scaleform::GFx::PlaceObject2Taga *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, unsigned __int64, _QWORD))v9->vfptr[7].__vecDelDtor)(
                                                v9,
                                                v2,
                                                v6,
                                                LOBYTE(v8->Header.Version));
  }
  v11 = v10;
  if ( v10 )
  {
    if ( v7 )
    {
      Scaleform::GFx::Stream::ReadToBuffer(v3, (char *)&v10[1], v6 - 8);
      v12 = (char)v11[1].vfptr;
      *(_QWORD *)&v11->pData[1] = 0i64;
      v11->pData[0] = v12;
    }
    else
    {
      Scaleform::GFx::Stream::ReadToBuffer(v3, v10->pData, v6);
    }
    Scaleform::GFx::LoadProcess::AddExecuteTag(v2, (Scaleform::GFx::ExecuteTag *)&v11->vfptr);
  }
}

// File Line: 868
// RVA: 0x86E300
void __fastcall Scaleform::GFx::GFx_PlaceObject3Loader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rdi
  Scaleform::GFx::Stream *v3; // rbx
  __int64 v4; // rax
  int v5; // edx
  unsigned __int64 v6; // rbp
  bool v7; // r14
  Scaleform::GFx::ASSupport *v8; // rcx
  Scaleform::GFx::PlaceObject3Tag *v9; // rax
  Scaleform::GFx::PlaceObject3Tag *v10; // rsi
  char v11; // al

  v2 = p;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->vfptr,
    "  PlaceObject3Tag\n");
  v3 = v2->pAltStream;
  if ( !v3 )
    v3 = &v2->ProcessInfo.Stream;
  v4 = v3->TagStackEntryCount - 1;
  if ( (unsigned int)v4 >= 2 )
    v5 = 0;
  else
    v5 = v3->TagStack[v4];
  v6 = v5 - (v3->Pos + v3->FilePos - v3->DataSize);
  v7 = Scaleform::GFx::PlaceObject2Tag::HasEventHandlers(v3);
  if ( !v7 || (v6 += 8i64, v2->pLoadData.pObject->FileAttributes & 8) )
  {
    v9 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject3Tag>(v2, v6);
  }
  else
  {
    v8 = v2->pLoadStates.pObject->pAS2Support.pObject;
    if ( !v8 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v2->vfptr,
        "GFx_PlaceObject3Loader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    v9 = (Scaleform::GFx::PlaceObject3Tag *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, unsigned __int64))v8->vfptr[8].__vecDelDtor)(
                                              v8,
                                              v2,
                                              v6);
  }
  v10 = v9;
  if ( v9 )
  {
    if ( v7 )
    {
      Scaleform::GFx::Stream::ReadToBuffer(v3, (char *)&v9[1], v6 - 8);
      v11 = (char)v10[1].vfptr;
      *(_QWORD *)&v10->pData[1] = 0i64;
      v10->pData[0] = v11;
    }
    else
    {
      Scaleform::GFx::Stream::ReadToBuffer(v3, v9->pData, v6);
    }
    Scaleform::GFx::LoadProcess::AddExecuteTag(v2, (Scaleform::GFx::ExecuteTag *)&v10->vfptr);
  }
}

// File Line: 910
// RVA: 0x86EA80
void __fastcall Scaleform::GFx::GFx_SpriteLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rbp
  Scaleform::GFx::Stream *v3; // rbx
  __int64 v4; // r9
  unsigned __int16 v5; // r8
  int v6; // ebx
  __int64 v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rdi
  Scaleform::GFx::MovieDataDef *v10; // rcx
  int v11; // et1
  __int64 v12; // rax
  _QWORD *v13; // rax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v14; // rcx
  __int64 v15; // rcx
  _QWORD *charId; // [rsp+60h] [rbp+8h]
  __int64 rid; // [rsp+70h] [rbp+18h]
  Scaleform::MemoryHeap *v18; // [rsp+78h] [rbp+20h]

  v2 = p;
  v3 = p->pAltStream;
  if ( !v3 )
    v3 = &p->ProcessInfo.Stream;
  v3->UnusedBits = 0;
  if ( (signed int)(v3->DataSize - v3->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 2);
  v4 = v3->Pos;
  v5 = (unsigned __int8)v3->pBuffer[v4] | (unsigned __int16)((unsigned __int8)v3->pBuffer[(unsigned int)(v4 + 1)] << 8);
  v3->Pos = v4 + 2;
  v6 = v5;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
    "  sprite\n  char id = %d\n",
    v5);
  v18 = v2->pLoadData.pObject->pHeap;
  v8 = ((__int64 (__fastcall *)(__int64, signed __int64))v18->vfptr->Alloc)(v7, 96i64);
  v9 = v8;
  if ( v8 )
  {
    v10 = v2->pDataDef_Unsafe;
    *(_QWORD *)v8 = &Scaleform::GFx::Resource::`vftable';
    v11 = *(_DWORD *)(v8 + 8);
    v12 = *(unsigned int *)(v8 + 8);
    *(_DWORD *)(v9 + 8) = 1;
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_QWORD *)v9 = &Scaleform::GFx::CharacterDef::`vftable';
    *(_DWORD *)(v9 + 24) = 0x40000;
    *(_QWORD *)v9 = &Scaleform::GFx::TimelineDef::`vftable';
    *(_QWORD *)v9 = &Scaleform::GFx::TimelineIODef::`vftable';
    *(_QWORD *)v9 = &Scaleform::GFx::SpriteDef::`vftable';
    *(_QWORD *)(v9 + 32) = v10;
    *(_QWORD *)(v9 + 40) = 0i64;
    *(_QWORD *)(v9 + 48) = 0i64;
    v13 = (_QWORD *)(v9 + 56);
    charId = v13;
    rid = v9 + 56;
    *v13 = 0i64;
    v13[1] = 0i64;
    v13[2] = 0i64;
    *(_QWORD *)(v9 + 80) = 0i64;
    *(_BYTE *)(v9 + 88) = 0;
  }
  else
  {
    v9 = 0i64;
  }
  LODWORD(charId) = v6;
  Scaleform::GFx::SpriteDef::Read((Scaleform::GFx::SpriteDef *)v9, v2, (Scaleform::GFx::ResourceId)&charId);
  v14 = v2->pLoadData.pObject;
  *(_DWORD *)(v9 + 24) = v6;
  LODWORD(rid) = v6;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
    v14,
    (Scaleform::GFx::ResourceId)&rid,
    (Scaleform::GFx::Resource *)v9);
  if ( !_InterlockedDecrement((volatile signed __int32 *)(v9 + 8)) )
  {
    v15 = *(_QWORD *)(v9 + 16);
    if ( v15 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v15 + 8i64))(v15, v9);
      *(_QWORD *)(v9 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
  }
}

// File Line: 942
// RVA: 0x86EDD0
void __fastcall Scaleform::GFx::GFx_RemoveObjectLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rbx
  Scaleform::GFx::ASSupport *v3; // rcx
  Scaleform::GFx::RemoveObjectTag *v4; // rax
  Scaleform::GFx::RemoveObjectTag *v5; // rdi

  v2 = p;
  if ( p->pLoadData.pObject->FileAttributes & 8 )
  {
    v4 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::RemoveObjectTag>(p);
  }
  else
  {
    v3 = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( !v3 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v2->vfptr,
        "GFx_RemoveObjectLoader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    v4 = (Scaleform::GFx::RemoveObjectTag *)v3->vfptr[9].__vecDelDtor(
                                              (Scaleform::RefCountImplCore *)&v3->vfptr,
                                              (unsigned int)v2);
  }
  v5 = v4;
  if ( v4 )
  {
    v4->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v4->vfptr, (unsigned int)v2);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
      "  RemoveObject(%d, %d)\n",
      v5->Id,
      v5->Depth);
    Scaleform::GFx::LoadProcess::AddExecuteTag(v2, (Scaleform::GFx::ExecuteTag *)&v5->vfptr);
  }
}

// File Line: 972
// RVA: 0x86EF70
void __fastcall Scaleform::GFx::GFx_RemoveObject2Loader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rbx
  Scaleform::GFx::ASSupport *v3; // rcx
  Scaleform::GFx::RemoveObject2Tag *v4; // rax
  Scaleform::GFx::RemoveObject2Tag *v5; // rdi

  v2 = p;
  if ( p->pLoadData.pObject->FileAttributes & 8 )
  {
    v4 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::RemoveObject2Tag>(p);
  }
  else
  {
    v3 = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( !v3 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v2->vfptr,
        "GFx_PlaceObject3Loader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    v4 = (Scaleform::GFx::RemoveObject2Tag *)v3->vfptr[10].__vecDelDtor(
                                               (Scaleform::RefCountImplCore *)&v3->vfptr,
                                               (unsigned int)v2);
  }
  v5 = v4;
  if ( v4 )
  {
    v4->vfptr[1].__vecDelDtor((Scaleform::GFx::ExecuteTag *)&v4->vfptr, (unsigned int)v2);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
      "  RemoveObject2(%d)\n",
      v5->Depth);
    Scaleform::GFx::LoadProcess::AddExecuteTag(v2, (Scaleform::GFx::ExecuteTag *)&v5->vfptr);
  }
}

// File Line: 1002
// RVA: 0x86F1C0
void __fastcall Scaleform::GFx::GFx_ButtonCharacterLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // r14
  Scaleform::GFx::LoadProcess *v3; // rsi
  Scaleform::GFx::Stream *v4; // rbx
  __int64 v5; // r9
  unsigned __int16 v6; // r8
  unsigned int v7; // ebp
  __int64 v8; // rcx
  __int64 v9; // rax
  Scaleform::GFx::ButtonDef *v10; // rbx
  int v11; // et1
  __int64 v12; // rax
  Scaleform::ArrayLH<Scaleform::GFx::ButtonRecord,258,Scaleform::ArrayDefaultPolicy> *v13; // rax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258,Scaleform::ArrayDefaultPolicy> *v14; // rax
  Scaleform::GFx::ResourceLibBase *v15; // rcx
  Scaleform::GFx::ResourceId rid; // [rsp+70h] [rbp+8h]
  Scaleform::MemoryHeap *v17; // [rsp+78h] [rbp+10h]
  __int64 v18; // [rsp+80h] [rbp+18h]
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258,Scaleform::ArrayDefaultPolicy> *v19; // [rsp+88h] [rbp+20h]

  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v5 = v4->Pos;
  v6 = (unsigned __int8)v4->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v4->Pos = v5 + 2;
  v7 = v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
    "  button GFxCharacter loader: CharId = %d\n",
    v6);
  v17 = v3->pLoadData.pObject->pHeap;
  v9 = ((__int64 (__fastcall *)(__int64, signed __int64))v17->vfptr->Alloc)(v8, 96i64);
  v10 = (Scaleform::GFx::ButtonDef *)v9;
  v18 = v9;
  if ( v9 )
  {
    *(_QWORD *)v9 = &Scaleform::GFx::Resource::`vftable';
    v11 = *(_DWORD *)(v9 + 8);
    v12 = *(unsigned int *)(v9 + 8);
    v10->RefCount.Value = 1;
    v10->pLib = 0i64;
    v10->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable';
    v10->Id.Id = 0x40000;
    v10->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ButtonDef::`vftable';
    v13 = &v10->ButtonRecords;
    v13->Data.Data = 0i64;
    v13->Data.Size = 0i64;
    v13->Data.Policy.Capacity = 0i64;
    v14 = &v10->ButtonActions;
    v19 = v14;
    v14->Data.Data = 0i64;
    v14->Data.Size = 0i64;
    v14->Data.Policy.Capacity = 0i64;
    v10->pScale9Grid = 0i64;
    v10->Menu = 0;
  }
  else
  {
    v10 = 0i64;
  }
  Scaleform::GFx::ButtonDef::Read(v10, v3, v2->TagType);
  if ( v3->LoadState == LS_LoadingRoot )
  {
    rid.Id = v7;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
      v3->pLoadData.pObject,
      (Scaleform::GFx::ResourceId)&rid,
      (Scaleform::GFx::Resource *)&v10->vfptr);
  }
  if ( v10 && !_InterlockedDecrement(&v10->RefCount.Value) )
  {
    v15 = v10->pLib;
    if ( v15 )
    {
      v15->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, (unsigned int)v10);
      v10->pLib = 0i64;
    }
    v10->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v10->vfptr, 1u);
  }
}

// File Line: 1037
// RVA: 0x870170
void __fastcall Scaleform::GFx::GFx_SetTabIndexLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::Stream *v2; // rbx
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *v3; // rdi
  unsigned int v4; // eax
  Scaleform::GFx::Stream *v5; // rbx
  unsigned int v6; // eax

  v2 = p->pAltStream;
  v3 = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)p;
  if ( !v2 )
    v2 = &p->ProcessInfo.Stream;
  v4 = v2->DataSize;
  v2->UnusedBits = 0;
  if ( (signed int)(v4 - v2->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v2, 2);
  v2->Pos += 2;
  v5 = (Scaleform::GFx::Stream *)v3[131].vfptr;
  if ( !v5 )
    v5 = (Scaleform::GFx::Stream *)&v3[10];
  v6 = v5->DataSize;
  v5->UnusedBits = 0;
  if ( (signed int)(v6 - v5->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
  v5->Pos += 2;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(v3 + 4, "SetTabIndex (unused) \n");
}

// File Line: 1053
// RVA: 0x86F610
void __fastcall Scaleform::GFx::GFx_ExportLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // r13
  Scaleform::GFx::Stream *v3; // rbx
  __int64 v4; // r9
  unsigned __int16 v5; // r8
  unsigned int v6; // ebx
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *v7; // rsi
  __int64 v8; // r12
  Scaleform::GFx::Stream *v9; // rdi
  __int64 v10; // r8
  unsigned __int16 v11; // bx
  Scaleform::GFx::Stream *v12; // rax
  __int64 v13; // r15
  signed __int64 v14; // rsi
  unsigned __int64 v15; // r14
  signed __int64 v16; // rbx
  signed __int64 *v17; // rdi
  __int64 v18; // rcx
  signed __int64 v19; // rdi
  __int64 v20; // rbx
  __int64 v21; // rcx
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // r14
  signed __int64 v24; // rbx
  signed __int64 *v25; // rdi
  Scaleform::StringLH *v26; // rdx
  Scaleform::GFx::Resource *v27; // rbx
  Scaleform::GFx::ResourceLibBase *v28; // rcx
  signed __int64 v29; // [rsp+20h] [rbp-50h]
  Scaleform::StringDH v30; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::ResourceHandle phandle; // [rsp+38h] [rbp-38h]
  Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+48h] [rbp-28h]
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef v33; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::ResourceId rid; // [rsp+B0h] [rbp+40h]
  int v35; // [rsp+C0h] [rbp+50h]
  __int64 v36; // [rsp+C8h] [rbp+58h]

  v29 = -2i64;
  v2 = p;
  v3 = p->pAltStream;
  if ( !v3 )
    v3 = &p->ProcessInfo.Stream;
  v3->UnusedBits = 0;
  if ( (signed int)(v3->DataSize - v3->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 2);
  v4 = v3->Pos;
  v5 = (unsigned __int8)v3->pBuffer[v4] | (unsigned __int16)((unsigned __int8)v3->pBuffer[(unsigned int)(v4 + 1)] << 8);
  v3->Pos = v4 + 2;
  v6 = v5;
  v7 = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
    "  export: count = %d\n",
    v5);
  if ( v6 )
  {
    v8 = v6;
    do
    {
      v9 = v2->pAltStream;
      if ( !v9 )
        v9 = &v2->ProcessInfo.Stream;
      v9->UnusedBits = 0;
      if ( (signed int)(v9->DataSize - v9->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v9, 2);
      v10 = v9->Pos;
      v11 = (unsigned __int8)v9->pBuffer[v10] | (unsigned __int16)((unsigned __int8)v9->pBuffer[(unsigned int)(v10 + 1)] << 8);
      v9->Pos = v10 + 2;
      Scaleform::StringDH::StringDH(&v30, v2->pLoadData.pObject->pHeap);
      v12 = Scaleform::GFx::LoadProcess::GetStream(v2);
      Scaleform::GFx::Stream::ReadString(v12, (Scaleform::String *)&v30.0);
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        v7,
        "  export: id = %d, name = %s\n",
        v11,
        (v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
        v29);
      phandle.HType = 0;
      phandle.pResource = 0i64;
      rid.Id = v11;
      if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
             v2->pLoadData.pObject,
             &phandle,
             (Scaleform::GFx::ResourceId)&rid) )
      {
        v35 = v11;
        v13 = (__int64)v2->pLoadData.pObject;
        v36 = 0i64;
        if ( *(_DWORD *)(v13 + 228) < 2 )
        {
          v36 = v13;
          EnterCriticalSection((LPCRITICAL_SECTION)(v13 + 328));
        }
        v14 = v13 + 384;
        if ( !*(_QWORD *)(v13 + 384) )
          goto LABEL_35;
        v15 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64) & *(_QWORD *)(*(_QWORD *)v14 + 8i64);
        v16 = v15;
        v17 = (signed __int64 *)(*(_QWORD *)v14 + 8 * (v15 + 4 * v15 + 2));
        if ( *v17 == -2 || v17[1] != v15 )
          goto LABEL_35;
        while ( v17[1] != v15
             || Scaleform::String::CompareNoCase(
                  (const char *)((v17[2] & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  (const char *)((v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
        {
          v16 = *v17;
          if ( *v17 == -1 )
            goto LABEL_35;
          v17 = (signed __int64 *)(*(_QWORD *)v14 + 8 * (v16 + 4 * v16 + 2));
        }
        if ( v16 >= 0 && v13 != -384 && (v18 = *(_QWORD *)v14) != 0 && v16 <= *(_QWORD *)(v18 + 8) )
        {
          v19 = v18 + 40 * (v16 + 1);
          if ( phandle.HType == RH_Pointer && phandle.pResource )
            _InterlockedExchangeAdd(&phandle.pResource->RefCount.Value, 1u);
          if ( !*(_DWORD *)v19 )
          {
            v20 = *(_QWORD *)(v19 + 8);
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
                (**(void (__fastcall ***)(__int64, signed __int64))v20)(v20, 1i64);
              }
            }
          }
          *(Scaleform::GFx::ResourceHandle *)v19 = phandle;
        }
        else
        {
LABEL_35:
          key.pFirst = (Scaleform::String *)&v30;
          key.pSecond = &phandle;
          v22 = Scaleform::String::BernsteinHashFunctionCIS(
                  (const void *)((v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  *(_QWORD *)(v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                  0x1505ui64);
          Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
            (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)(v13 + 384),
            (void *)(v13 + 384),
            &key,
            v22);
        }
        if ( !*(_QWORD *)v14 )
          goto LABEL_44;
        v23 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64) & *(_QWORD *)(*(_QWORD *)v14 + 8i64);
        v24 = v23;
        v25 = (signed __int64 *)(*(_QWORD *)v14 + 8 * (v23 + 4 * v23 + 2));
        if ( *v25 == -2 || v25[1] != v23 )
          goto LABEL_44;
        while ( v25[1] != v23
             || Scaleform::String::CompareNoCase(
                  (const char *)((v25[2] & 0xFFFFFFFFFFFFFFFCui64) + 12),
                  (const char *)((v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
        {
          v24 = *v25;
          if ( *v25 == -1 )
            goto LABEL_44;
          v25 = (signed __int64 *)(*(_QWORD *)v14 + 8 * (v24 + 4 * v24 + 2));
        }
        if ( v24 < 0 )
        {
LABEL_44:
          v14 = 0i64;
          v24 = 0i64;
        }
        v26 = (Scaleform::StringLH *)(*(_QWORD *)v14 + 8 * (v24 + 4 * (v24 + 1)));
        v33.pFirst = (Scaleform::GFx::ResourceId *)&v35;
        v33.pSecond = v26;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF> > *)(v13 + 392),
          (void *)(v13 + 392),
          &v33);
        if ( v36 )
          LeaveCriticalSection((LPCRITICAL_SECTION)(v36 + 328));
        v7 = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr;
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
          (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)v7,
          "Don't know how to export Resource '%s'",
          (v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
      }
      if ( phandle.HType == RH_Pointer )
      {
        v27 = phandle.pResource;
        if ( phandle.pResource )
        {
          if ( !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
          {
            v28 = v27->pLib;
            if ( v28 )
            {
              v28->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v28->vfptr, (unsigned int)v27);
              v27->pLib = 0i64;
            }
            v27->vfptr->__vecDelDtor(v27, 1u);
          }
        }
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 1095
// RVA: 0x86FAC0
void __fastcall Scaleform::GFx::GFx_ImportLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // rdi
  Scaleform::GFx::LoadProcess *v3; // rbp
  Scaleform::GFx::Stream *v4; // rsi
  Scaleform::GFx::Stream *v5; // rbx
  __int64 v6; // r9
  unsigned __int16 v7; // r8
  __int64 v8; // r14
  const char *v9; // rdx
  Scaleform::GFx::ImportData *v10; // r15
  __int64 v11; // r8
  unsigned __int16 v12; // di
  Scaleform::GFx::Resource *v13; // rdi
  Scaleform::GFx::ResourceLibBase *v14; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v15; // rcx
  Scaleform::GFx::DataAllocator *v16; // rcx
  unsigned __int64 v17; // rdx
  char *v18; // rdi
  Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > *v19; // rbp
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // r8
  Scaleform::GFx::ExecuteTag **v23; // rcx
  Scaleform::GFx::ResourceHandle result; // [rsp+30h] [rbp-58h]
  Scaleform::GFx::ResourceId rid; // [rsp+90h] [rbp+8h]
  Scaleform::String v26; // [rsp+98h] [rbp+10h]
  Scaleform::String pstr; // [rsp+A0h] [rbp+18h]
  char *v28; // [rsp+A8h] [rbp+20h]

  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  Scaleform::String::String(&pstr);
  Scaleform::GFx::Stream::ReadString(v4, &pstr);
  if ( v2->TagType == 71 )
  {
    v5 = v3->pAltStream;
    if ( !v5 )
      v5 = &v3->ProcessInfo.Stream;
    v5->UnusedBits = 0;
    if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
    v5->Pos += 2;
  }
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v6 = v4->Pos;
  v7 = (unsigned __int8)v4->pBuffer[v6] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v6 + 1)] << 8);
  v4->Pos = v6 + 2;
  v8 = v7;
  v9 = "  importAssets2: SourceUrl = %s, count = %d\n";
  if ( v2->TagType != 71 )
    v9 = "  importAssets: SourceUrl = %s, count = %d\n";
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
    v9,
    (pstr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
    v7,
    -2i64);
  v10 = Scaleform::GFx::LoadProcess::AllocMovieDefClass<Scaleform::GFx::ImportData>(v3);
  v10->Frame = v3->pLoadData.pObject->LoadingFrame;
  Scaleform::String::operator=((Scaleform::String *)&v10->SourceUrl.0, &pstr);
  if ( (signed int)v8 > 0 )
  {
    do
    {
      Scaleform::String::String(&v26);
      v4->UnusedBits = 0;
      if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
      v11 = v4->Pos;
      v12 = (unsigned __int8)v4->pBuffer[v11] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v11 + 1)] << 8);
      v4->Pos = v11 + 2;
      Scaleform::GFx::Stream::ReadString(v4, &v26);
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
        "  import: id = %d, name = %s\n",
        v12,
        (v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
      rid.Id = v12;
      Scaleform::GFx::LoadProcess::AddNewResourceHandle(v3, &result, (Scaleform::GFx::ResourceId)&rid);
      Scaleform::GFx::ImportData::AddSymbol(
        v10,
        (const char *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        v12,
        result.BindIndex);
      if ( result.HType == RH_Pointer )
      {
        v13 = result.pResource;
        if ( result.pResource )
        {
          if ( !_InterlockedDecrement(&result.pResource->RefCount.Value) )
          {
            v14 = v13->pLib;
            if ( v14 )
            {
              v14->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, (unsigned int)v13);
              v13->pLib = 0i64;
            }
            v13->vfptr->__vecDelDtor(v13, 1u);
          }
        }
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      --v8;
    }
    while ( v8 );
  }
  v10->ImportIndex = v3->ImportIndex++;
  if ( !v3->pImportData )
    v3->pImportData = v10;
  v15 = v3->pLoadData.pObject;
  if ( v15->BindData.pImports.Value )
    v15->BindData.pImportsLast->pNext.Value = v10;
  else
    v15->BindData.pImports.Value = v10;
  v15->BindData.pImportsLast = v10;
  ++v3->ImportDataCount;
  v16 = &v3->pLoadData.pObject->TagMemAllocator;
  v17 = v3->pLoadData.pObject->TagMemAllocator.BytesLeft;
  if ( v17 < 0x10 )
  {
    v18 = (char *)Scaleform::GFx::DataAllocator::OverflowAlloc(v16, 0x10ui64);
  }
  else
  {
    v18 = v16->pCurrent;
    v16->pCurrent += 16;
    v16->BytesLeft = v17 - 16;
  }
  v28 = v18;
  if ( v18 )
  {
    *(_QWORD *)v18 = &Scaleform::GFx::ExecuteTag::`vftable';
    *(_QWORD *)v18 = &Scaleform::GFx::GFxInitImportActions::`vftable';
    *((_DWORD *)v18 + 2) = 0;
  }
  else
  {
    v18 = 0i64;
  }
  *((_DWORD *)v18 + 2) = v10->ImportIndex;
  v19 = (Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > *)&v3->InitActionTags.Data.Data;
  v20 = v19->Size;
  v21 = v20 + 1;
  if ( v20 + 1 >= v20 )
  {
    if ( v21 <= v19->Policy.Capacity )
      goto LABEL_42;
    v22 = v21 + (v21 >> 2);
  }
  else
  {
    if ( v21 >= v19->Policy.Capacity >> 1 )
      goto LABEL_42;
    v22 = v20 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
    v19,
    v19,
    v22);
LABEL_42:
  v19->Size = v21;
  v23 = &v19->Data[v21 - 1];
  if ( v23 )
    *v23 = (Scaleform::GFx::ExecuteTag *)v18;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((pstr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 1155
// RVA: 0x870350
void __fastcall Scaleform::GFx::GFx_FileAttributesLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::Stream *v2; // rbx
  Scaleform::GFx::LoadProcess *v3; // rdi
  unsigned int v4; // eax
  __int64 v5; // r9
  unsigned __int16 v6; // r8

  v2 = p->pAltStream;
  v3 = p;
  if ( !v2 )
    v2 = &p->ProcessInfo.Stream;
  v4 = v2->DataSize;
  v2->UnusedBits = 0;
  if ( (signed int)(v4 - v2->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v2, 2);
  v5 = v2->Pos;
  v6 = (unsigned __int8)v2->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v2->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v2->Pos = v5 + 2;
  v3->pLoadData.pObject->FileAttributes = v6;
}

// File Line: 1189
// RVA: 0x870200
void __fastcall Scaleform::GFx::GFx_MetadataLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *v2; // rdi
  Scaleform::GFx::Stream *v3; // rcx
  signed __int64 v4; // rdx
  signed __int64 v5; // rsi
  __int64 v6; // rax
  int v7; // er8
  int v8; // ebp
  char *v9; // r14
  Scaleform::GFx::Stream *v10; // rbx
  unsigned int v11; // eax
  __int64 v12; // rdx
  char v13; // cl
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>Vtbl *v14; // rbx
  bool (__fastcall *v15)(Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *); // rax
  signed int v16; // eax

  v2 = (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)p;
  v3 = p->pAltStream;
  v4 = (signed __int64)&v2[10];
  if ( v3 )
    v4 = (signed __int64)v3;
  v5 = 0i64;
  v6 = (unsigned int)(*(_DWORD *)(v4 + 72) - 1);
  if ( (unsigned int)v6 >= 2 )
    v7 = 0;
  else
    v7 = *(_DWORD *)(v4 + 4 * v6 + 64);
  if ( !v3 )
    v3 = (Scaleform::GFx::Stream *)&v2[10];
  v8 = v7 + v3->DataSize - v3->FilePos - v3->Pos;
  v9 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v8 + 1, 0i64);
  if ( v9 )
  {
    if ( v8 > 0 )
    {
      do
      {
        v10 = (Scaleform::GFx::Stream *)v2[131].vfptr;
        if ( !v10 )
          v10 = (Scaleform::GFx::Stream *)&v2[10];
        v11 = v10->DataSize;
        v10->UnusedBits = 0;
        if ( (signed int)(v11 - v10->Pos) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(v10, 1);
        v12 = v10->Pos;
        ++v5;
        v13 = v10->pBuffer[v12];
        v10->Pos = v12 + 1;
        v9[v5 - 1] = v13;
      }
      while ( v5 < v8 );
    }
    v14 = v2[7].vfptr;
    v15 = (bool (__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *))(*(__int64 (__fastcall **)(bool (__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *), _QWORD, _QWORD))(*(_QWORD *)v14[3].IsVerboseActionErrors + 80i64))(
                                                                                    v14[3].IsVerboseActionErrors,
                                                                                    (unsigned int)v8,
                                                                                    0i64);
    v14[13].IsVerboseActionErrors = v15;
    if ( v15 )
    {
      LODWORD(v14[14].__vecDelDtor) = v8;
      memmove(v15, v9, (unsigned int)v8);
    }
    v16 = 255;
    if ( v8 < 255 )
      v16 = v8;
    v9[v16] = 0;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(v2 + 4, "  metadata: %s\n", v9);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
}

// File Line: 1235
// RVA: 0x8D4730
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::GFx_CreateImageFileResourceHandle(Scaleform::GFx::ResourceHandle *result, Scaleform::GFx::LoadProcess *p, __int64 rid, const char *pimageFileName, const char *pimageExportName, unsigned __int16 bitmapFormat, unsigned __int16 targetWidth, unsigned __int16 targetHeight)
{
  const char *v8; // r14
  Scaleform::GFx::ResourceId *v9; // rdi
  Scaleform::GFx::LoadProcess *v10; // rbp
  Scaleform::GFx::ResourceHandle *v11; // rsi
  Scaleform::GFx::ResourceFileInfo *v12; // rax
  __int64 v13; // rbx
  Scaleform::GFx::ExporterInfoImpl *v14; // rax
  Scaleform::GFx::ResourceData *v15; // rax
  Scaleform::GFx::ResourceHandle *v16; // rax
  Scaleform::GFx::Resource *v17; // rdi
  Scaleform::GFx::ResourceLibBase *v18; // rcx
  Scaleform::GFx::ResourceId rida[2]; // [rsp+28h] [rbp-50h]
  __int64 v21; // [rsp+30h] [rbp-48h]
  __int64 v22; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::ResourceHandle v23; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::ResourceData resulta; // [rsp+50h] [rbp-28h]

  v21 = -2i64;
  v8 = pimageFileName;
  v9 = (Scaleform::GFx::ResourceId *)rid;
  v10 = p;
  v11 = result;
  result->HType = 0;
  result->pResource = 0i64;
  v12 = (Scaleform::GFx::ResourceFileInfo *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                              Scaleform::Memory::pGlobalHeap,
                                              56ui64,
                                              0i64);
  v13 = (__int64)v12;
  *(_QWORD *)&rida[0].Id = v12;
  if ( v12 )
  {
    Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(v12);
    *(_QWORD *)v13 = &Scaleform::GFx::ImageFileInfo::`vftable';
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
    Scaleform::String::operator=((Scaleform::String *)(v13 + 32), v8);
    Scaleform::String::operator=((Scaleform::String *)(v13 + 48), pimageExportName);
    v14 = &v10->pLoadData.pObject->Header.mExporterInfo;
    if ( v14->SI.Format == File_Unopened )
      v14 = 0i64;
    *(_QWORD *)(v13 + 24) = v14;
    *(_DWORD *)(v13 + 16) = bitmapFormat;
    *(_WORD *)(v13 + 40) = targetWidth;
    *(_WORD *)(v13 + 42) = targetHeight;
    if ( (v9->Id & 0xFFF0000) == 393216 )
      *(_DWORD *)(v13 + 44) = 3;
    v15 = Scaleform::GFx::ImageFileResourceCreator::CreateImageFileResourceData(
            &resulta,
            (Scaleform::GFx::ImageFileInfo *)v13);
    rida[0] = (Scaleform::GFx::ResourceId)v9->Id;
    v16 = Scaleform::GFx::LoadProcess::AddDataResource(v10, &v23, (__int64)rida, v15);
    Scaleform::GFx::ResourceHandle::operator=(v11, v16);
    if ( v23.HType == RH_Pointer )
    {
      v17 = v23.pResource;
      if ( v23.pResource )
      {
        if ( !_InterlockedDecrement(&v23.pResource->RefCount.Value) )
        {
          v18 = v17->pLib;
          if ( v18 )
          {
            v18->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, (unsigned int)v17);
            v17->pLib = 0i64;
          }
          v17->vfptr->__vecDelDtor(v17, 1u);
        }
      }
    }
    if ( resulta.pInterface )
      resulta.pInterface->vfptr->Release(resulta.pInterface, resulta.hData);
  }
  if ( v13 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v13);
  return v11;
}

// File Line: 1283
// RVA: 0x870CC0
void __fastcall Scaleform::GFx::GFx_DefineExternalImageLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rsi
  Scaleform::GFx::Stream *v3; // rdi
  Scaleform::GFx::Stream *v4; // rbx
  __int64 v5; // r8
  unsigned int v6; // er14
  Scaleform::GFx::Stream *v7; // rdi
  __int64 v8; // r8
  unsigned __int16 bitmapFormat; // r12
  Scaleform::GFx::Stream *v10; // rdi
  __int64 v11; // r8
  unsigned __int16 targetWidth; // r15
  Scaleform::GFx::Stream *v13; // rdi
  __int64 v14; // r8
  unsigned __int16 v15; // r13
  __int64 v16; // rdx
  unsigned int v17; // ecx
  __int64 v18; // rdx
  unsigned int v19; // ecx
  Scaleform::GFx::Resource *v20; // rdi
  Scaleform::GFx::ResourceLibBase *v21; // rcx
  char *pimageExportName; // [rsp+20h] [rbp-49h]
  __int64 targetHeight; // [rsp+38h] [rbp-31h]
  __int64 v24[2]; // [rsp+40h] [rbp-29h]
  Scaleform::String::InitStruct src; // [rsp+58h] [rbp-11h]
  Scaleform::GFx::Stream *v26; // [rsp+60h] [rbp-9h]
  Scaleform::String::InitStruct v27; // [rsp+68h] [rbp-1h]
  Scaleform::GFx::Stream *v28; // [rsp+70h] [rbp+7h]
  Scaleform::GFx::ResourceHandle result; // [rsp+78h] [rbp+Fh]
  Scaleform::String v30; // [rsp+D0h] [rbp+67h]
  Scaleform::GFx::TagInfo *rid; // [rsp+D8h] [rbp+6Fh]
  Scaleform::String v32; // [rsp+E0h] [rbp+77h]

  rid = tagInfo;
  v2 = p;
  v3 = p->pAltStream;
  v4 = &p->ProcessInfo.Stream;
  if ( v3 )
    v4 = p->pAltStream;
  else
    v3 = &p->ProcessInfo.Stream;
  v3->UnusedBits = 0;
  if ( (signed int)(v3->DataSize - v3->Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 4);
  v5 = v3->Pos;
  v6 = (unsigned __int8)v3->pBuffer[v5] | (((unsigned __int8)v3->pBuffer[(unsigned int)(v5 + 1)] | (((unsigned __int8)v3->pBuffer[(unsigned int)(v5 + 2)] | ((unsigned __int8)v3->pBuffer[(unsigned int)(v5 + 3)] << 8)) << 8)) << 8);
  v3->Pos = v5 + 4;
  v7 = v2->pAltStream;
  if ( !v7 )
    v7 = &v2->ProcessInfo.Stream;
  v7->UnusedBits = 0;
  if ( (signed int)(v7->DataSize - v7->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v7, 2);
  v8 = v7->Pos;
  bitmapFormat = (unsigned __int8)v7->pBuffer[v8] | (unsigned __int16)((unsigned __int8)v7->pBuffer[(unsigned int)(v8 + 1)] << 8);
  v7->Pos = v8 + 2;
  v10 = v2->pAltStream;
  if ( !v10 )
    v10 = &v2->ProcessInfo.Stream;
  v10->UnusedBits = 0;
  if ( (signed int)(v10->DataSize - v10->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v10, 2);
  v11 = v10->Pos;
  targetWidth = (unsigned __int8)v10->pBuffer[v11] | (unsigned __int16)((unsigned __int8)v10->pBuffer[(unsigned int)(v11 + 1)] << 8);
  v10->Pos = v11 + 2;
  v13 = v2->pAltStream;
  if ( !v13 )
    v13 = &v2->ProcessInfo.Stream;
  v13->UnusedBits = 0;
  if ( (signed int)(v13->DataSize - v13->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v13, 2);
  v14 = v13->Pos;
  v15 = (unsigned __int8)v13->pBuffer[v14] | (unsigned __int16)((unsigned __int8)v13->pBuffer[(unsigned int)(v14 + 1)] << 8);
  v13->Pos = v14 + 2;
  Scaleform::String::String(&v32);
  Scaleform::String::String(&v30);
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 1);
  v16 = v4->Pos;
  v17 = (unsigned __int8)v4->pBuffer[v16];
  v4->Pos = v16 + 1;
  if ( (signed int)v17 > 0 )
  {
    src.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength'::`2'::StringReader::`vftable';
    v26 = v4;
    Scaleform::String::AssignString(&v32, &src, v17);
    src.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
  }
  else
  {
    Scaleform::String::Clear(&v32);
  }
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 1);
  v18 = v4->Pos;
  v19 = (unsigned __int8)v4->pBuffer[v18];
  v4->Pos = v18 + 1;
  if ( (signed int)v19 > 0 )
  {
    v27.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength'::`2'::StringReader::`vftable';
    v28 = v4;
    Scaleform::String::AssignString(&v30, &v27, v19);
    v27.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
  }
  else
  {
    Scaleform::String::Clear(&v30);
  }
  LODWORD(v24[0]) = v15;
  LODWORD(targetHeight) = targetWidth;
  LODWORD(pimageExportName) = bitmapFormat;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
    "  DefineExternalImage: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', exp = '%s', w = %d, h = %d\n",
    (unsigned int)rid->TagType,
    v6,
    pimageExportName,
    (v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
    (v32.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
    targetHeight,
    v24[0]);
  LODWORD(rid) = v6 & 0x9FFFF;
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &result,
    v2,
    (Scaleform::GFx::ResourceId)&rid,
    (const char *)((v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    (const char *)((v32.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    bitmapFormat,
    targetWidth,
    v15);
  if ( result.HType == RH_Pointer )
  {
    v20 = result.pResource;
    if ( result.pResource )
    {
      if ( !_InterlockedDecrement(&result.pResource->RefCount.Value) )
      {
        v21 = v20->pLib;
        if ( v21 )
        {
          v21->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, (unsigned int)v20);
          v20->pLib = 0i64;
        }
        v20->vfptr->__vecDelDtor(v20, 1u);
      }
    }
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v32.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 1325
// RVA: 0x8721A0
void __fastcall Scaleform::GFx::GFx_DefineSubImageLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rbx
  Scaleform::GFx::Stream *v3; // rdi
  __int64 v4; // r9
  unsigned __int16 v5; // r8
  Scaleform::GFx::Stream *v6; // rdi
  __int64 v7; // r9
  unsigned __int16 v8; // r8
  int v9; // er13
  Scaleform::GFx::Stream *v10; // rdi
  __int64 v11; // r8
  unsigned __int16 v12; // r15
  Scaleform::GFx::Stream *v13; // rdi
  __int64 v14; // r8
  unsigned __int16 v15; // r14
  Scaleform::GFx::Stream *v16; // rdi
  __int64 v17; // r8
  unsigned __int16 v18; // bp
  Scaleform::GFx::Stream *v19; // rdi
  __int64 v20; // r8
  unsigned __int16 v21; // r12
  __int64 v22; // rdi
  Scaleform::GFx::Resource *v23; // rbx
  Scaleform::GFx::ResourceLibBase *v24; // rcx
  Scaleform::GFx::ResourceData result; // [rsp+28h] [rbp-60h]
  Scaleform::GFx::ResourceHandle v26; // [rsp+38h] [rbp-50h]
  Scaleform::GFx::ResourceId rid; // [rsp+90h] [rbp+8h]
  __int64 v28; // [rsp+A0h] [rbp+18h]

  v2 = p;
  v3 = p->pAltStream;
  if ( !v3 )
    v3 = &p->ProcessInfo.Stream;
  v3->UnusedBits = 0;
  if ( (signed int)(v3->DataSize - v3->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 2);
  v4 = v3->Pos;
  v5 = (unsigned __int8)v3->pBuffer[v4] | (unsigned __int16)((unsigned __int8)v3->pBuffer[(unsigned int)(v4 + 1)] << 8);
  v3->Pos = v4 + 2;
  rid.Id = v5;
  v6 = v2->pAltStream;
  if ( !v6 )
    v6 = &v2->ProcessInfo.Stream;
  v6->UnusedBits = 0;
  if ( (signed int)(v6->DataSize - v6->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v6, 2);
  v7 = v6->Pos;
  v8 = (unsigned __int8)v6->pBuffer[v7] | (unsigned __int16)((unsigned __int8)v6->pBuffer[(unsigned int)(v7 + 1)] << 8);
  v6->Pos = v7 + 2;
  v9 = v8;
  v10 = v2->pAltStream;
  if ( !v10 )
    v10 = &v2->ProcessInfo.Stream;
  v10->UnusedBits = 0;
  if ( (signed int)(v10->DataSize - v10->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v10, 2);
  v11 = v10->Pos;
  v12 = (unsigned __int8)v10->pBuffer[v11] | (unsigned __int16)((unsigned __int8)v10->pBuffer[(unsigned int)(v11 + 1)] << 8);
  v10->Pos = v11 + 2;
  v13 = v2->pAltStream;
  if ( !v13 )
    v13 = &v2->ProcessInfo.Stream;
  v13->UnusedBits = 0;
  if ( (signed int)(v13->DataSize - v13->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v13, 2);
  v14 = v13->Pos;
  v15 = (unsigned __int8)v13->pBuffer[v14] | (unsigned __int16)((unsigned __int8)v13->pBuffer[(unsigned int)(v14 + 1)] << 8);
  v13->Pos = v14 + 2;
  v16 = v2->pAltStream;
  if ( !v16 )
    v16 = &v2->ProcessInfo.Stream;
  v16->UnusedBits = 0;
  if ( (signed int)(v16->DataSize - v16->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v16, 2);
  v17 = v16->Pos;
  v18 = (unsigned __int8)v16->pBuffer[v17] | (unsigned __int16)((unsigned __int8)v16->pBuffer[(unsigned int)(v17 + 1)] << 8);
  v16->Pos = v17 + 2;
  v19 = v2->pAltStream;
  if ( !v19 )
    v19 = &v2->ProcessInfo.Stream;
  v19->UnusedBits = 0;
  if ( (signed int)(v19->DataSize - v19->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v19, 2);
  v20 = v19->Pos;
  v21 = (unsigned __int8)v19->pBuffer[v20] | (unsigned __int16)((unsigned __int8)v19->pBuffer[(unsigned int)(v20 + 1)] << 8);
  v19->Pos = v20 + 2;
  v22 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          48i64);
  v28 = v22;
  if ( v22 )
  {
    *(_QWORD *)v22 = &Scaleform::RefCountNTSImplCore::`vftable';
    *(_DWORD *)(v22 + 8) = 1;
    *(_QWORD *)v22 = &Scaleform::RefCountNTSImpl::`vftable';
    *(_QWORD *)v22 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::`vftable';
    *(_QWORD *)v22 = &Scaleform::RefCountBaseNTS<Scaleform::GFx::SubImageResourceInfo,2>::`vftable';
    *(_QWORD *)v22 = &Scaleform::GFx::SubImageResourceInfo::`vftable';
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
  Scaleform::GFx::LoadProcess::AddDataResource(v2, &v26, (Scaleform::GFx::ResourceId)&rid, &result);
  if ( v26.HType == RH_Pointer )
  {
    v23 = v26.pResource;
    if ( v26.pResource )
    {
      if ( !_InterlockedDecrement(&v26.pResource->RefCount.Value) )
      {
        v24 = v23->pLib;
        if ( v24 )
        {
          v24->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, (unsigned int)v23);
          v23->pLib = 0i64;
        }
        v23->vfptr->__vecDelDtor(v23, 1u);
      }
    }
  }
  if ( result.pInterface )
    result.pInterface->vfptr->Release(result.pInterface, result.hData);
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v22);
}

// File Line: 1481
// RVA: 0x871290
void __fastcall Scaleform::GFx::GFx_FontTextureInfoLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // rsi
  Scaleform::GFx::LoadProcess *v3; // r14
  Scaleform::GFx::Stream *v4; // rdi
  Scaleform::MemoryHeap *v5; // r13
  __int64 v6; // r8
  char *v7; // rdx
  unsigned int v8; // er12
  __int64 v9; // r8
  unsigned __int16 bitmapFormat; // bx
  __int64 v11; // rdx
  unsigned int v12; // ecx
  __int64 v13; // r9
  unsigned __int16 v14; // r8
  __int64 v15; // r9
  unsigned __int16 v16; // r8
  int v17; // er15
  __int64 v18; // rdx
  unsigned int v19; // ecx
  __int64 v20; // r9
  unsigned __int16 v21; // r8
  __int64 v22; // r9
  unsigned __int16 v23; // r8
  unsigned int v24; // er14
  unsigned int v25; // esi
  __int64 v26; // r9
  __int64 v27; // r9
  __int64 v28; // r9
  __int64 v29; // r9
  __int64 v30; // r9
  __int64 v31; // r9
  int v32; // xmm6_4
  int v33; // xmm7_4
  int v34; // xmm8_4
  int v35; // xmm9_4
  float v36; // xmm10_4
  float v37; // xmm11_4
  Scaleform::GFx::Resource *v38; // rax
  __int64 v39; // rbx
  Scaleform::Render::TextureGlyph *v40; // rbx
  __int64 v41; // rcx
  float v42; // xmm3_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  int v45; // xmm1_4
  __int64 v46; // r9
  unsigned __int16 v47; // r8
  __int64 v48; // rbx
  __int64 v49; // r15
  __int64 v50; // r9
  unsigned __int16 v51; // r8
  Scaleform::GFx::FontDataUseNode *volatile v52; // rcx
  Scaleform::Render::Font *v53; // rsi
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> *v54; // rax
  Scaleform::GFx::TextureGlyphData *v55; // rbx
  Scaleform::GFx::TextureGlyphData *v56; // rbx
  unsigned int v57; // eax
  Scaleform::GFx::TextureGlyphData *v58; // rax
  __int64 v59; // r9
  unsigned __int16 v60; // r8
  __int64 v61; // rsi
  __int64 v62; // r9
  unsigned __int16 v63; // r8
  unsigned int v64; // er14
  __int64 v65; // r9
  unsigned __int16 v66; // r8
  unsigned __int64 v67; // rdi
  Scaleform::Render::TextureGlyph *v68; // rdx
  Scaleform::Render::TextureGlyph *v69; // rbx
  Scaleform::GFx::Resource *v70; // rdi
  Scaleform::GFx::ResourceLibBase *v71; // rcx
  char *pimageExportName; // [rsp+20h] [rbp-E0h]
  char *pimageExportNamea; // [rsp+20h] [rbp-E0h]
  __int64 targetWidth; // [rsp+30h] [rbp-D0h]
  __int64 targetHeight; // [rsp+38h] [rbp-C8h]
  Scaleform::String v76; // [rsp+40h] [rbp-C0h]
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+48h] [rbp-B8h]
  Scaleform::GFx::ResourceHandle result; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::ResourceId rid; // [rsp+70h] [rbp-90h]
  int v80; // [rsp+74h] [rbp-8Ch]
  int v81; // [rsp+78h] [rbp-88h]
  int v82; // [rsp+7Ch] [rbp-84h]
  int v83; // [rsp+80h] [rbp-80h]
  int v84; // [rsp+84h] [rbp-7Ch]
  Scaleform::GFx::ResourceId textureId; // [rsp+88h] [rbp-78h]
  Scaleform::RefCountImplCore v86; // [rsp+90h] [rbp-70h]
  __int64 v87; // [rsp+A0h] [rbp-60h]
  __int128 v88; // [rsp+B0h] [rbp-50h]
  float v89; // [rsp+C0h] [rbp-40h]
  int v90; // [rsp+C4h] [rbp-3Ch]
  unsigned int v91; // [rsp+C8h] [rbp-38h]
  int v92; // [rsp+D8h] [rbp-28h]
  int v93; // [rsp+DCh] [rbp-24h]
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> *v94; // [rsp+E0h] [rbp-20h]
  Scaleform::MemoryHeap *v95; // [rsp+E8h] [rbp-18h]
  Scaleform::Render::TextureGlyph *v96; // [rsp+F0h] [rbp-10h]
  Scaleform::Render::TextureGlyph *v97; // [rsp+F8h] [rbp-8h]
  Scaleform::String::InitStruct src; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::Stream *v99; // [rsp+108h] [rbp+8h]
  Scaleform::MemoryHeap *v100; // [rsp+110h] [rbp+10h]
  __int64 v101; // [rsp+118h] [rbp+18h]
  Scaleform::GFx::LoadProcess *v102; // [rsp+1C0h] [rbp+C0h]
  unsigned int v103; // [rsp+1D0h] [rbp+D0h]
  unsigned int v104; // [rsp+1D8h] [rbp+D8h]

  v102 = p;
  v101 = -2i64;
  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v5 = p->pLoadData.pObject->pHeap;
  v95 = v5;
  v100 = v5;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 4);
  v6 = v4->Pos;
  v7 = v4->pBuffer;
  v8 = (unsigned __int8)v7[v6] | (((unsigned __int8)v7[(unsigned int)(v6 + 1)] | (((unsigned __int8)v7[(unsigned int)(v6 + 2)] | ((unsigned __int8)v7[(unsigned int)(v6 + 3)] << 8)) << 8)) << 8);
  v82 = (unsigned __int8)v7[v6] | (((unsigned __int8)v7[(unsigned int)(v6 + 1)] | (((unsigned __int8)v7[(unsigned int)(v6 + 2)] | ((unsigned __int8)v7[(unsigned int)(v6 + 3)] << 8)) << 8)) << 8);
  v4->Pos = v6 + 4;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - (v6 + 4)) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v9 = v4->Pos;
  bitmapFormat = (unsigned __int8)v4->pBuffer[v9] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v9 + 1)] << 8);
  v4->Pos = v9 + 2;
  Scaleform::String::String(&v76);
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 1);
  v11 = v4->Pos;
  v12 = (unsigned __int8)v4->pBuffer[v11];
  v4->Pos = v11 + 1;
  if ( (signed int)v12 > 0 )
  {
    src.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength'::`2'::StringReader::`vftable';
    v99 = v4;
    Scaleform::String::AssignString(&v76, &src, v12);
    src.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
  }
  else
  {
    Scaleform::String::Clear(&v76);
  }
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v13 = v4->Pos;
  v14 = (unsigned __int8)v4->pBuffer[v13] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v13 + 1)] << 8);
  v4->Pos = v13 + 2;
  v92 = v14;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - (v13 + 2)) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v15 = v4->Pos;
  v16 = (unsigned __int8)v4->pBuffer[v15] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v15 + 1)] << 8);
  v4->Pos = v15 + 2;
  v17 = v16;
  v93 = v16;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - (v15 + 2)) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 1);
  v18 = v4->Pos;
  v19 = (unsigned __int8)v4->pBuffer[v18];
  v4->Pos = v18 + 1;
  v104 = v19;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - (v18 + 1)) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v20 = v4->Pos;
  v21 = (unsigned __int8)v4->pBuffer[v20] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v20 + 1)] << 8);
  v4->Pos = v20 + 2;
  v103 = v21;
  if ( v4->ParseFlags & 1 )
  {
    LODWORD(targetHeight) = v17;
    LODWORD(targetWidth) = v92;
    LODWORD(pimageExportName) = bitmapFormat;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
      "  FontTextureInfo: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', w = %d, h = %d\n",
      (unsigned int)v2->TagType,
      v8,
      pimageExportName,
      (v76.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
      targetWidth,
      targetHeight);
  }
  rid.Id = v8;
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &result,
    v3,
    (Scaleform::GFx::ResourceId)&rid,
    (const char *)((v76.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    &customWorldMapCaption,
    bitmapFormat,
    v92,
    v93);
  v94 = &pheapAddr;
  pheapAddr.Data = 0i64;
  pheapAddr.Size = 0i64;
  pheapAddr.Policy.Capacity = 0i64;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v22 = v4->Pos;
  v23 = (unsigned __int8)v4->pBuffer[v22] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v22 + 1)] << 8);
  v4->Pos = v22 + 2;
  v24 = v23;
  if ( v4->ParseFlags & 1 )
  {
    LODWORD(pimageExportNamea) = v23;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
      "  PadPixels = %d, nominal glyph size = %d, numTexGlyphs = %d\n",
      v104,
      v103,
      pimageExportNamea);
  }
  v25 = 0;
  if ( v24 )
  {
    do
    {
      v4->UnusedBits = 0;
      if ( (signed int)(v4->DataSize - v4->Pos) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(v4, 4);
      v26 = v4->Pos;
      v80 = (unsigned __int8)v4->pBuffer[v26] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v26 + 1)] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v26 + 2)] | ((unsigned __int8)v4->pBuffer[(unsigned int)(v26 + 3)] << 8)) << 8)) << 8);
      v4->Pos = v26 + 4;
      v4->UnusedBits = 0;
      if ( (signed int)(v4->DataSize - (v26 + 4)) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(v4, 4);
      v27 = v4->Pos;
      v83 = (unsigned __int8)v4->pBuffer[v27] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v27 + 1)] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v27 + 2)] | ((unsigned __int8)v4->pBuffer[(unsigned int)(v27 + 3)] << 8)) << 8)) << 8);
      v4->Pos = v27 + 4;
      v4->UnusedBits = 0;
      if ( (signed int)(v4->DataSize - (v27 + 4)) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(v4, 4);
      v28 = v4->Pos;
      v84 = (unsigned __int8)v4->pBuffer[v28] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v28 + 1)] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v28 + 2)] | ((unsigned __int8)v4->pBuffer[(unsigned int)(v28 + 3)] << 8)) << 8)) << 8);
      v4->Pos = v28 + 4;
      v4->UnusedBits = 0;
      if ( (signed int)(v4->DataSize - (v28 + 4)) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(v4, 4);
      v29 = v4->Pos;
      v81 = (unsigned __int8)v4->pBuffer[v29] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v29 + 1)] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v29 + 2)] | ((unsigned __int8)v4->pBuffer[(unsigned int)(v29 + 3)] << 8)) << 8)) << 8);
      v4->Pos = v29 + 4;
      v4->UnusedBits = 0;
      if ( (signed int)(v4->DataSize - (v29 + 4)) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(v4, 4);
      v30 = v4->Pos;
      LODWORD(v97) = (unsigned __int8)v4->pBuffer[v30] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v30 + 1)] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v30 + 2)] | ((unsigned __int8)v4->pBuffer[(unsigned int)(v30 + 3)] << 8)) << 8)) << 8);
      v4->Pos = v30 + 4;
      v4->UnusedBits = 0;
      if ( (signed int)(v4->DataSize - (v30 + 4)) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(v4, 4);
      v31 = v4->Pos;
      LODWORD(v96) = (unsigned __int8)v4->pBuffer[v31] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v31 + 1)] | (((unsigned __int8)v4->pBuffer[(unsigned int)(v31 + 2)] | ((unsigned __int8)v4->pBuffer[(unsigned int)(v31 + 3)] << 8)) << 8)) << 8);
      v4->Pos = v31 + 4;
      v32 = v80;
      v33 = v83;
      v34 = v84;
      v35 = v81;
      v36 = *(float *)&v97;
      v37 = *(float *)&v96;
      if ( v4->ParseFlags & 1 )
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
          "  TEXGLYPH[%d]: uvBnd.x1 = %f, uvBnd.y1 = %f, uvBnd.x2 = %f, uvBnd.y2 = %f\n",
          v25,
          v80,
          v83,
          v84,
          v81);
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
          "                uvOrigin.x = %f, uvOrigin.y = %f\n",
          v36,
          v37);
      }
      v86.RefCount = 1;
      v86.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureGlyph::`vftable';
      v87 = 0i64;
      v88 = 0i64;
      v91 = -1;
      if ( result.HType == 1 )
      {
        v91 = result.BindIndex;
      }
      else if ( result.HType == RH_Pointer
             && result.pResource
             && (((__int64 (*)(void))result.pResource->vfptr->GetResourceTypeCode)() & 0xFF00) == 256 )
      {
        v38 = 0i64;
        if ( result.HType == RH_Pointer )
          v38 = result.pResource;
        v39 = (__int64)v38[1].vfptr;
        if ( v39 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v39 + 8i64))(v39);
        if ( v87 )
          (*(void (**)(void))(*(_QWORD *)v87 + 16i64))();
        v87 = v39;
      }
      *(_QWORD *)&v88 = __PAIR__(v33, v32);
      *((_QWORD *)&v88 + 1) = __PAIR__(v35, v34);
      v89 = v36;
      v90 = LODWORD(v37);
      Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
      v40 = &pheapAddr.Data[pheapAddr.Size - 1];
      v96 = &pheapAddr.Data[pheapAddr.Size - 1];
      v97 = &pheapAddr.Data[pheapAddr.Size - 1];
      if ( v40 )
      {
        v40->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
        v40->RefCount = 1;
        v40->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
        v40->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
        v40->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::TextureGlyph,2>::`vftable';
        v40->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureGlyph::`vftable';
        v41 = v87;
        if ( v87 )
        {
          (*(void (**)(void))(*(_QWORD *)v87 + 8i64))();
          v41 = v87;
        }
        v40->pImage.pObject = (Scaleform::Render::Image *)v41;
        v42 = *((float *)&v88 + 3);
        v43 = *((float *)&v88 + 2);
        v44 = *((float *)&v88 + 1);
        LODWORD(v40->UvBounds.x1) = v88;
        v40->UvBounds.y1 = v44;
        v40->UvBounds.x2 = v43;
        v40->UvBounds.y2 = v42;
        v45 = v90;
        v40->UvOrigin.x = v89;
        LODWORD(v40->UvOrigin.y) = v45;
        v40->BindIndex = v91;
      }
      if ( v87 )
        (*(void (**)(void))(*(_QWORD *)v87 + 16i64))();
      Scaleform::RefCountImplCore::~RefCountImplCore(&v86);
      ++v25;
    }
    while ( v25 < v24 );
    v8 = v82;
    v5 = v95;
  }
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v46 = v4->Pos;
  v47 = (unsigned __int8)v4->pBuffer[v46] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v46 + 1)] << 8);
  v4->Pos = v46 + 2;
  v48 = v47;
  if ( v4->ParseFlags & 1 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
      "  NumFonts = %d\n",
      v47);
  if ( (_DWORD)v48 )
  {
    v49 = v48;
    do
    {
      v4->UnusedBits = 0;
      if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
      v50 = v4->Pos;
      v51 = (unsigned __int8)v4->pBuffer[v50] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v50 + 1)] << 8);
      v4->Pos = v50 + 2;
      v52 = v102->pLoadData.pObject->BindData.pFonts.Value;
      if ( !v52 )
        goto LABEL_96;
      while ( v52->Id.Id != v51 )
      {
        v52 = v52->pNext.Value;
        if ( !v52 )
          goto LABEL_96;
      }
      v53 = v52->pFontData.pObject;
      if ( !v53 )
        goto LABEL_96;
      v54 = (Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v53->vfptr[11].__vecDelDtor)(v52->pFontData.pObject);
      v55 = (Scaleform::GFx::TextureGlyphData *)v54;
      if ( v54 )
        ++LODWORD(v54->Size);
      v94 = v54;
      if ( !v54 )
      {
        v56 = (Scaleform::GFx::TextureGlyphData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v5->vfptr->Alloc)(
                                                    v5,
                                                    72i64);
        v95 = (Scaleform::MemoryHeap *)v56;
        if ( v56 )
        {
          v57 = ((__int64 (__fastcall *)(Scaleform::Render::Font *))v53->vfptr[18].__vecDelDtor)(v53);
          Scaleform::GFx::TextureGlyphData::TextureGlyphData(v56, v57, 1);
          v55 = v58;
        }
        else
        {
          v55 = 0i64;
        }
        v94 = (Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> *)v55;
        if ( !v55 )
          goto LABEL_83;
        v55->PackTextureConfig.NominalSize = v103;
        v55->PackTextureConfig.PadPixels = v104;
        v55->PackTextureConfig.TextureWidth = v92;
        v55->PackTextureConfig.TextureHeight = v93;
        v53->vfptr[12].__vecDelDtor((Scaleform::RefCountImplCore *)&v53->vfptr, (unsigned int)v55);
      }
      textureId.Id = v8;
      Scaleform::GFx::TextureGlyphData::AddTexture(v55, (Scaleform::GFx::ResourceId)&textureId, &result);
LABEL_83:
      v4->UnusedBits = 0;
      if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
      v59 = v4->Pos;
      v60 = (unsigned __int8)v4->pBuffer[v59] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v59 + 1)] << 8);
      v4->Pos = v59 + 2;
      if ( v60 )
      {
        v61 = v60;
        do
        {
          v4->UnusedBits = 0;
          if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
          v62 = v4->Pos;
          v63 = (unsigned __int8)v4->pBuffer[v62] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v62 + 1)] << 8);
          v4->Pos = v62 + 2;
          v64 = v63;
          v4->UnusedBits = 0;
          if ( (signed int)(v4->DataSize - (v62 + 2)) < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
          v65 = v4->Pos;
          v66 = (unsigned __int8)v4->pBuffer[v65] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v65 + 1)] << 8);
          v4->Pos = v65 + 2;
          if ( v55 )
            Scaleform::GFx::TextureGlyphData::AddTextureGlyph(v55, v64, &pheapAddr.Data[(unsigned __int64)v66]);
          --v61;
        }
        while ( v61 );
      }
      if ( v55 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v55->vfptr);
LABEL_96:
      --v49;
    }
    while ( v49 );
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
    "\n");
  v67 = pheapAddr.Size;
  v68 = pheapAddr.Data;
  v69 = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( pheapAddr.Size )
  {
    do
    {
      v69->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v69->vfptr, 0);
      --v69;
      --v67;
    }
    while ( v67 );
    v68 = pheapAddr.Data;
  }
  if ( v68 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( result.HType == RH_Pointer )
  {
    v70 = result.pResource;
    if ( result.pResource )
    {
      if ( !_InterlockedDecrement(&result.pResource->RefCount.Value) )
      {
        v71 = v70->pLib;
        if ( v71 )
        {
          v71->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v71->vfptr, (unsigned int)v70);
          v70->pLib = 0i64;
        }
        v70->vfptr->__vecDelDtor(v70, 1u);
      }
    }
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v76.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}FFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 1656
// RVA: 0x871F10
void __fastcall Scaleform::GFx::GFx_DefineExternalGradientImageLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // r15
  Scaleform::GFx::LoadProcess *v3; // rdi
  Scaleform::GFx::Stream *v4; // rbx
  __int64 v5; // r9
  unsigned __int16 v6; // r8
  unsigned int v7; // er14
  __int64 v8; // r9
  unsigned __int16 bitmapFormat; // si
  __int64 v10; // r8
  unsigned __int16 v11; // bp
  __int64 v12; // rdx
  unsigned int v13; // ecx
  Scaleform::GFx::Resource *v14; // rdi
  Scaleform::GFx::ResourceLibBase *v15; // rcx
  char *pimageExportName; // [rsp+20h] [rbp-78h]
  __int64 targetWidth; // [rsp+30h] [rbp-68h]
  Scaleform::String::InitStruct src; // [rsp+48h] [rbp-50h]
  Scaleform::GFx::Stream *v19; // [rsp+50h] [rbp-48h]
  Scaleform::GFx::ResourceHandle result; // [rsp+58h] [rbp-40h]
  Scaleform::GFx::ResourceId rid; // [rsp+A0h] [rbp+8h]
  Scaleform::String v22; // [rsp+A8h] [rbp+10h]

  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v5 = v4->Pos;
  v6 = (unsigned __int8)v4->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v4->Pos = v5 + 2;
  v7 = v6 | 0x50000;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - (v5 + 2)) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v8 = v4->Pos;
  bitmapFormat = (unsigned __int8)v4->pBuffer[v8] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v8 + 1)] << 8);
  v4->Pos = v8 + 2;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - (v8 + 2)) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v10 = v4->Pos;
  v11 = (unsigned __int8)v4->pBuffer[v10] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v10 + 1)] << 8);
  v4->Pos = v10 + 2;
  Scaleform::String::String(&v22);
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 1);
  v12 = v4->Pos;
  v13 = (unsigned __int8)v4->pBuffer[v12];
  v4->Pos = v12 + 1;
  if ( (signed int)v13 > 0 )
  {
    src.vfptr = (Scaleform::String::InitStructVtbl *)`Scaleform::GFx::Stream::ReadStringWithLength'::`2'::StringReader::`vftable';
    v19 = v4;
    Scaleform::String::AssignString(&v22, &src, v13);
    src.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
  }
  else
  {
    Scaleform::String::Clear(&v22);
  }
  LODWORD(targetWidth) = v11;
  LODWORD(pimageExportName) = bitmapFormat;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
    "  DefineExternalGradientImage: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', size = %d\n",
    (unsigned int)v2->TagType,
    v7,
    pimageExportName,
    (v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
    targetWidth);
  rid.Id = v7;
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &result,
    v3,
    (Scaleform::GFx::ResourceId)&rid,
    (const char *)((v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    &customWorldMapCaption,
    bitmapFormat,
    0,
    0);
  if ( result.HType == RH_Pointer )
  {
    v14 = result.pResource;
    if ( result.pResource )
    {
      if ( !_InterlockedDecrement(&result.pResource->RefCount.Value) )
      {
        v15 = v14->pLib;
        if ( v15 )
        {
          v15->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, (unsigned int)v14);
          v14->pLib = 0i64;
        }
        v14->vfptr->__vecDelDtor(v14, 1u);
      }
    }
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 1697
// RVA: 0x872190
void __fastcall Scaleform::GFx::GFx_DefineGradientMapLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogWarning(
    (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->vfptr,
    "Deprecated tag 1004 - DefineGradientMapLoader encountered, ignored");
}

// File Line: 1735
// RVA: 0x870920
void __fastcall Scaleform::GFx::GFx_Scale9GridLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rdi
  Scaleform::GFx::Stream *v3; // rbx
  __int64 v4; // r9
  unsigned __int16 v5; // r8
  unsigned int v6; // esi
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  bool v11; // al
  Scaleform::GFx::SpriteDef *v12; // rbx
  Scaleform::GFx::ResourceHandle::HandleType v13; // edi
  Scaleform::GFx::Resource *v14; // rbx
  Scaleform::GFx::ResourceLibBase *v15; // rcx
  __int64 v16; // [rsp+20h] [rbp-98h]
  __int64 v17; // [rsp+28h] [rbp-90h]
  _QWORD v18[4]; // [rsp+30h] [rbp-88h]
  Scaleform::Render::Rect<float> pr; // [rsp+50h] [rbp-68h]
  Scaleform::GFx::ResourceHandle phandle; // [rsp+60h] [rbp-58h]
  Scaleform::GFx::ResourceId rid; // [rsp+C0h] [rbp+8h]

  v2 = p;
  v3 = p->pAltStream;
  if ( !v3 )
    v3 = &p->ProcessInfo.Stream;
  pr = 0i64;
  v3->UnusedBits = 0;
  if ( (signed int)(v3->DataSize - v3->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 2);
  v4 = v3->Pos;
  v5 = (unsigned __int8)v3->pBuffer[v4] | (unsigned __int16)((unsigned __int8)v3->pBuffer[(unsigned int)(v4 + 1)] << 8);
  v3->Pos = v4 + 2;
  v6 = v5;
  Scaleform::GFx::Stream::ReadRect(v3, &pr);
  v7 = pr.y2;
  v8 = pr.x2;
  v9 = pr.y1;
  v10 = pr.x1;
  if ( v3->ParseFlags & 1 )
  {
    LODWORD(v18[0]) = (signed int)pr.y2;
    LODWORD(v17) = (signed int)pr.x2;
    LODWORD(v16) = (signed int)pr.y1;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
      "Scale9GridLoader, id=%d, x1=%d, y1=%d, x2=%d, y2=%d\n",
      v6,
      (unsigned int)(signed int)pr.x1,
      v16,
      v17,
      v18[0]);
  }
  if ( v10 < v8 )
  {
    if ( v9 < v7 )
    {
      phandle.HType = 0;
      phandle.pResource = 0i64;
      rid.Id = v6;
      v11 = Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
              v2->pLoadData.pObject,
              &phandle,
              (Scaleform::GFx::ResourceId)&rid);
      v12 = (Scaleform::GFx::SpriteDef *)phandle.pResource;
      v13 = phandle.HType;
      if ( v11 && phandle.HType == RH_Pointer && phandle.pResource )
      {
        if ( (phandle.pResource->vfptr->GetResourceTypeCode(phandle.pResource) & 0xFF00) == 33792 )
        {
          Scaleform::GFx::SpriteDef::SetScale9Grid(v12, &pr);
        }
        else if ( (v12->vfptr->GetResourceTypeCode((Scaleform::GFx::Resource *)&v12->vfptr) & 0xFF00) == 33024 )
        {
          Scaleform::GFx::ButtonDef::SetScale9Grid((Scaleform::GFx::ButtonDef *)v12, &pr);
        }
      }
      if ( v13 == RH_Pointer && v12 && !_InterlockedDecrement(&v12->RefCount.Value) )
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
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogWarning(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v2->vfptr,
        "Scale9Grid for resource=%d has negative height %f",
        v6,
        (float)((float)(v7 - v9) * 0.050000001));
    }
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v2->vfptr,
      "Scale9Grid for resource=%d has negative width %f",
      v6,
      (float)((float)(v8 - v10) * 0.050000001));
  }
}

// File Line: 1785
// RVA: 0x86F170
void __fastcall Scaleform::GFx::GFx_DoActionLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::ASSupport *v2; // r9

  if ( p->pLoadData.pObject->FileAttributes & 8 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->vfptr,
      "GFx_DoActionLoader - DoAction tag shouldn't appear in AS3 swf. Tag is skipped.");
  }
  else
  {
    v2 = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( v2 )
      ((void (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, Scaleform::GFx::TagInfo *))v2->vfptr[11].__vecDelDtor)(
        v2,
        p,
        tagInfo);
    else
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->vfptr,
        "GFx_DoActionLoader - AS2 support is not installed. Tag is skipped.");
  }
}

// File Line: 1800
// RVA: 0x8700A0
void __fastcall Scaleform::GFx::GFx_DoInitActionLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::ASSupport *v2; // r9

  if ( p->pLoadData.pObject->FileAttributes & 8 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->vfptr,
      "GFx_DoInitActionLoader - DoInitAction tag shouldn't appear in AS3 swf. Tag is skipped.");
  }
  else
  {
    v2 = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( v2 )
      ((void (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, Scaleform::GFx::TagInfo *))v2->vfptr[12].__vecDelDtor)(
        v2,
        p,
        tagInfo);
    else
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->vfptr,
        "GFx_DoInitActionLoader - AS2 support is not installed. Tag is skipped.");
  }
}

// File Line: 1815
// RVA: 0x8726B0
void __fastcall Scaleform::GFx::GFx_DefineSceneAndFrameLabelData(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // r13
  Scaleform::GFx::Stream *v3; // rbx
  __int64 v4; // r15
  unsigned int v5; // er14
  unsigned int v6; // esi
  unsigned int v7; // edi
  __int64 v8; // rcx
  char v9; // dl
  unsigned int v10; // esi
  unsigned int v11; // edi
  __int64 v12; // rcx
  char v13; // dl
  int v14; // er15
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *v15; // r14
  signed __int64 v16; // r14
  unsigned int v17; // er12
  unsigned int v18; // esi
  unsigned int v19; // edi
  __int64 v20; // rcx
  char v21; // dl
  unsigned int i; // er8
  Scaleform::ArrayLH<Scaleform::GFx::MovieDataDef::SceneInfo,2,Scaleform::ArrayDefaultPolicy> *v23; // rdx
  signed __int64 v24; // rcx
  unsigned int v25; // eax
  signed __int64 v26; // rdi
  Scaleform::StringDH v27; // [rsp+50h] [rbp-19h]
  Scaleform::StringDH v28; // [rsp+60h] [rbp-9h]
  Scaleform::StringDH v29; // [rsp+70h] [rbp+7h]
  unsigned int v30; // [rsp+80h] [rbp+17h]
  unsigned int v31; // [rsp+D0h] [rbp+67h]

  v2 = p;
  if ( !p->pLoadData.pObject->Scenes.pObject )
  {
    v3 = p->pAltStream;
    if ( !v3 )
      v3 = &p->ProcessInfo.Stream;
    v4 = (unsigned int)Scaleform::GFx::Stream::ReadVU32(v3);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
      "  Scene and Frame Label Data, numscenes = %d\n",
      v4);
    v5 = 0;
    if ( (_DWORD)v4 )
    {
      do
      {
        v6 = 0;
        v7 = 0;
        do
        {
          v3->UnusedBits = 0;
          if ( (signed int)(v3->DataSize - v3->Pos) < 1 )
            Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
          v8 = v3->Pos;
          v9 = v3->pBuffer[v8];
          v3->Pos = v8 + 1;
          v6 |= (v9 & 0x7F) << v7;
          v7 += 7;
        }
        while ( v7 < 0x20 && v9 < 0 );
        Scaleform::StringDH::StringDH(&v27, v2->pLoadData.pObject->pHeap);
        Scaleform::GFx::Stream::ReadString(v3, (Scaleform::String *)&v27.0);
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
          "   Scene[%d] = { %d, \"%s\" }\n",
          v5,
          v6,
          (v27.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        Scaleform::GFx::MovieDataDef::LoadTaskData::AddScene(v2->pLoadData.pObject, (Scaleform::String *)&v27.0, v6);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v27.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        ++v5;
      }
      while ( v5 < (unsigned int)v4 );
    }
    v10 = 0;
    v11 = 0;
    do
    {
      v3->UnusedBits = 0;
      if ( (signed int)(v3->DataSize - v3->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
      v12 = v3->Pos;
      v13 = v3->pBuffer[v12];
      v3->Pos = v12 + 1;
      v10 |= (v13 & 0x7F) << v11;
      v11 += 7;
    }
    while ( v11 < 0x20 && v13 < 0 );
    v31 = v10;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
      "  frameLabelCount = %d\n",
      v10);
    v14 = 0;
    v15 = v2->pLoadData.pObject->Scenes.pObject;
    if ( v15 && v15->Data.Size > 0 )
      v16 = (signed __int64)v15->Data.Data;
    else
      v16 = 0i64;
    v17 = 0;
    if ( v10 )
    {
      do
      {
        v18 = 0;
        v19 = 0;
        do
        {
          v3->UnusedBits = 0;
          if ( (signed int)(v3->DataSize - v3->Pos) < 1 )
            Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
          v20 = v3->Pos;
          v21 = v3->pBuffer[v20];
          v3->Pos = v20 + 1;
          v18 |= (v21 & 0x7F) << v19;
          v19 += 7;
        }
        while ( v19 < 0x20 && v21 < 0 );
        Scaleform::StringDH::StringDH(&v28, v2->pLoadData.pObject->pHeap);
        Scaleform::GFx::Stream::ReadString(v3, (Scaleform::String *)&v28.0);
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
          "   Label[%d] = { %d, \"%s\" }\n",
          v17,
          v18,
          (v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        for ( i = v14 + 1; ; ++i )
        {
          v23 = v2->pLoadData.pObject->Scenes.pObject;
          if ( !v23 )
            break;
          if ( i >= v23->Data.Size )
            break;
          v24 = (signed __int64)&v23->Data.Data[i];
          if ( !v24 )
            break;
          v25 = *(_DWORD *)(v24 + 16);
          if ( v18 < v25 )
            break;
          *(_DWORD *)(v16 + 20) = v25;
          v16 = v24;
          ++v14;
        }
        Scaleform::StringDH::CopyConstructHelper(
          &v29,
          (Scaleform::String *)&v28.0,
          *(Scaleform::MemoryHeap **)(v16 + 8));
        v30 = v18;
        Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy> *)(v16 + 24),
          *(const void **)(v16 + 48),
          *(_QWORD *)(v16 + 32) + 1i64);
        v26 = *(_QWORD *)(v16 + 24) + 8 * (3i64 * *(_QWORD *)(v16 + 32) - 3);
        if ( v26 )
        {
          Scaleform::StringDH::CopyConstructHelper((Scaleform::StringDH *)v26, (Scaleform::String *)&v29.0, v29.pHeap);
          *(_DWORD *)(v26 + 16) = v30;
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v28.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        ++v17;
      }
      while ( v17 < v31 );
    }
    *(_DWORD *)(v16 + 20) = v2->pLoadData.pObject->Header.FrameCount - *(_DWORD *)(v16 + 16);
  }
}

// File Line: 1861
// RVA: 0x872B80
void __fastcall Scaleform::GFx::GFx_DefineBinaryData(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rsi
  Scaleform::GFx::Stream *v3; // rbx
  __int64 v4; // r10
  unsigned __int16 v5; // r9
  unsigned int v6; // ebp
  __int64 v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rbx
  int v10; // et1
  __int64 v11; // rax
  _QWORD *v12; // ST28_8
  _QWORD *v13; // ST30_8
  __int64 v14; // rcx
  Scaleform::GFx::ResourceId rid; // [rsp+60h] [rbp+8h]
  Scaleform::MemoryHeap *v16; // [rsp+70h] [rbp+18h]
  __int64 v17; // [rsp+78h] [rbp+20h]

  v2 = p;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
    (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->vfptr,
    "Tag 'DefineBinaryData' (87) is not supported, potentially 'TLF text' fields are used. Switch to 'Classic Text'.");
  v3 = v2->pAltStream;
  if ( !v3 )
    v3 = &v2->ProcessInfo.Stream;
  v3->UnusedBits = 0;
  if ( (signed int)(v3->DataSize - v3->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 2);
  v4 = v3->Pos;
  v5 = (unsigned __int8)v3->pBuffer[v4] | (unsigned __int16)((unsigned __int8)v3->pBuffer[(unsigned int)(v4 + 1)] << 8);
  v3->Pos = v4 + 2;
  v6 = v5;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
    "  DefineBinaryData: CharId = %d\n",
    v5);
  Scaleform::GFx::LoadProcess::ReadU32(v2);
  v16 = v2->pLoadData.pObject->pHeap;
  v8 = ((__int64 (__fastcall *)(__int64, signed __int64))v16->vfptr->Alloc)(v7, 96i64);
  v9 = v8;
  v17 = v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = &Scaleform::GFx::Resource::`vftable';
    v10 = *(_DWORD *)(v8 + 8);
    v11 = *(unsigned int *)(v8 + 8);
    *(_DWORD *)(v9 + 8) = 1;
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_QWORD *)v9 = &Scaleform::GFx::CharacterDef::`vftable';
    *(_DWORD *)(v9 + 24) = 0x40000;
    *(_QWORD *)v9 = &Scaleform::GFx::ButtonDef::`vftable';
    v12 = (_QWORD *)(v9 + 32);
    *v12 = 0i64;
    v12[1] = 0i64;
    v12[2] = 0i64;
    v13 = (_QWORD *)(v9 + 56);
    *v13 = 0i64;
    v13[1] = 0i64;
    v13[2] = 0i64;
    *(_QWORD *)(v9 + 80) = 0i64;
    *(_BYTE *)(v9 + 88) = 0;
  }
  else
  {
    v9 = 0i64;
  }
  if ( v2->LoadState == LS_LoadingRoot )
  {
    rid.Id = v6;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
      v2->pLoadData.pObject,
      (Scaleform::GFx::ResourceId)&rid,
      (Scaleform::GFx::Resource *)v9);
  }
  if ( v9 && !_InterlockedDecrement((volatile signed __int32 *)(v9 + 8)) )
  {
    v14 = *(_QWORD *)(v9 + 16);
    if ( v14 )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v14 + 8i64))(v14, v9);
      *(_QWORD *)(v9 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
  }
}

