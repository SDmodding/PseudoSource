// File Line: 48
// RVA: 0x9A53B0
char __fastcall Scaleform::Render::TGA::TGAFileImageSource::ReadHeader(Scaleform::Render::TGA::TGAFileImageSource *this, Scaleform::MemoryHeap *pheap)
{
  Scaleform::Render::TGA::TGAFileImageSource *v2; // rbx
  Scaleform::File *v3; // rcx
  Scaleform::MemoryHeap *v4; // r13
  Scaleform::RefCountImplCoreVtbl *v5; // rax
  Scaleform::File *v6; // rcx
  Scaleform::RefCountImplCoreVtbl *v7; // rax
  Scaleform::File *v8; // rcx
  Scaleform::RefCountImplCoreVtbl *v9; // rax
  int v10; // er12
  Scaleform::File *v11; // rcx
  int v12; // er15
  Scaleform::RefCountImplCoreVtbl *v13; // rax
  signed int v14; // edi
  Scaleform::File *v15; // rcx
  Scaleform::RefCountImplCoreVtbl *v16; // rax
  Scaleform::File *v17; // rcx
  Scaleform::RefCountImplCoreVtbl *v18; // rax
  __int64 v19; // r14
  unsigned int v20; // esi
  signed __int64 v21; // rcx
  Scaleform::File *v22; // rcx
  Scaleform::File *v23; // rcx
  Scaleform::File *v24; // rcx
  Scaleform::File *v25; // rcx
  Scaleform::File *v26; // rcx
  Scaleform::RefCountImplCoreVtbl *v27; // rax
  Scaleform::File *v29; // rcx
  Scaleform::RefCountImplCoreVtbl *v30; // rax
  unsigned __int8 v31; // dl
  Scaleform::Render::ImageFormat v32; // eax
  bool v33; // r15
  Scaleform::Render::Palette *v34; // rax
  volatile signed __int32 *v35; // rdx
  Scaleform::Render::Palette *v36; // rdi
  signed __int64 v37; // rsi
  Scaleform::File *v38; // rcx
  Scaleform::RefCountImplCoreVtbl *v39; // rax
  _BYTE *v40; // rdi
  Scaleform::File *v41; // rcx
  Scaleform::RefCountImplCoreVtbl *v42; // rax
  Scaleform::File *v43; // rcx
  Scaleform::RefCountImplCoreVtbl *v44; // rax
  char v45; // al
  Scaleform::File *v46; // rcx
  Scaleform::RefCountImplCoreVtbl *v47; // rax
  char v48; // [rsp+20h] [rbp-20h]
  char v49; // [rsp+21h] [rbp-1Fh]
  char v50; // [rsp+22h] [rbp-1Eh]
  char v51; // [rsp+23h] [rbp-1Dh]
  char v52; // [rsp+24h] [rbp-1Ch]
  char v53; // [rsp+25h] [rbp-1Bh]
  unsigned __int8 v54; // [rsp+26h] [rbp-1Ah]
  unsigned __int16 v55; // [rsp+28h] [rbp-18h]
  unsigned __int16 v56; // [rsp+2Ch] [rbp-14h]
  unsigned __int16 v57; // [rsp+30h] [rbp-10h]
  __int16 v58; // [rsp+34h] [rbp-Ch]
  __int16 v59; // [rsp+38h] [rbp-8h]
  __int16 v60; // [rsp+3Ch] [rbp-4h]
  unsigned __int8 v61; // [rsp+80h] [rbp+40h]
  unsigned __int8 v62; // [rsp+90h] [rbp+50h]
  unsigned __int8 v63; // [rsp+98h] [rbp+58h]

  v2 = this;
  v3 = this->pFile.pObject;
  v4 = pheap;
  v5 = v3->vfptr;
  v54 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int8 *, signed __int64))v5[10].__vecDelDtor)(v3, &v54, 1i64);
  v6 = v2->pFile.pObject;
  v7 = v6->vfptr;
  v61 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int8 *, signed __int64))v7[10].__vecDelDtor)(v6, &v61, 1i64);
  v8 = v2->pFile.pObject;
  v9 = v8->vfptr;
  v10 = v61;
  v62 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int8 *, signed __int64))v9[10].__vecDelDtor)(v8, &v62, 1i64);
  v11 = v2->pFile.pObject;
  v12 = v62;
  v13 = v11->vfptr;
  v14 = 2;
  v58 = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v13[10].__vecDelDtor)(v11, &v58, 2i64);
  v15 = v2->pFile.pObject;
  v16 = v15->vfptr;
  v55 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int16 *, signed __int64))v16[10].__vecDelDtor)(v15, &v55, 2i64);
  v17 = v2->pFile.pObject;
  v18 = v17->vfptr;
  v19 = v55;
  v63 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int8 *, signed __int64))v18[10].__vecDelDtor)(v17, &v63, 1i64);
  v20 = v63;
  if ( v63 > 0x20u )
    return 0;
  v21 = 4311744513i64;
  if ( !_bittest64(&v21, v63) )
    return 0;
  v22 = v2->pFile.pObject;
  v59 = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v22->vfptr[10].__vecDelDtor)(v22, &v59, 2i64);
  v23 = v2->pFile.pObject;
  v60 = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v23->vfptr[10].__vecDelDtor)(v23, &v60, 2i64);
  v24 = v2->pFile.pObject;
  v56 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int16 *, signed __int64))v24->vfptr[10].__vecDelDtor)(
    v24,
    &v56,
    2i64);
  v25 = v2->pFile.pObject;
  v57 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int16 *, signed __int64))v25->vfptr[10].__vecDelDtor)(
    v25,
    &v57,
    2i64);
  v26 = v2->pFile.pObject;
  v27 = v26->vfptr;
  v51 = 0;
  ((void (__fastcall *)(Scaleform::File *, char *, signed __int64))v27[10].__vecDelDtor)(v26, &v51, 1i64);
  v2->Size.Width = v56;
  v2->Size.Height = v57;
  if ( v10 )
  {
    if ( v10 != 1 || v12 != 1 )
      return 0;
  }
  else if ( v12 != 2 )
  {
    return 0;
  }
  v29 = v2->pFile.pObject;
  v30 = v29->vfptr;
  v49 = 0;
  ((void (__fastcall *)(Scaleform::File *, char *, signed __int64))v30[10].__vecDelDtor)(v29, &v49, 1i64);
  v31 = v54;
  v2->ImageDesc = v49;
  if ( v31 )
    v2->pFile.pObject->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)v2->pFile.pObject, v31);
  switch ( v51 )
  {
    case 8:
      v2->SourceFormat = 100;
      break;
    case 24:
      v2->SourceFormat = 4;
      break;
    case 32:
      v2->SourceFormat = 2;
      break;
    default:
      return 0;
  }
  if ( v2->Format == Image_None )
  {
    v32 = v2->SourceFormat;
    if ( v32 == 100 )
    {
      if ( v20 < 0x20 )
        v14 = 4;
      v2->Format = v14;
    }
    else
    {
      v2->Format = v32;
    }
  }
  if ( v10 == 1 )
  {
    v33 = v20 == 32;
    v34 = Scaleform::Render::Palette::Create(v19, v20 == 32, v4);
    v35 = &v2->pColorMap.pObject->RefCount.Value;
    v36 = v34;
    if ( v35 && !_InterlockedDecrement(v35) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v2->pColorMap.pObject = v36;
    if ( !v36 )
      return 0;
    if ( (_DWORD)v19 )
    {
      v37 = 8i64;
      do
      {
        v38 = v2->pFile.pObject;
        v39 = v38->vfptr;
        v40 = (char *)v2->pColorMap.pObject + v37;
        v52 = 0;
        ((void (__fastcall *)(Scaleform::File *, char *, signed __int64))v39[10].__vecDelDtor)(v38, &v52, 1i64);
        v41 = v2->pFile.pObject;
        v42 = v41->vfptr;
        v50 = 0;
        ((void (__fastcall *)(Scaleform::File *, char *, signed __int64))v42[10].__vecDelDtor)(v41, &v50, 1i64);
        v43 = v2->pFile.pObject;
        v44 = v43->vfptr;
        v53 = 0;
        ((void (__fastcall *)(Scaleform::File *, char *, signed __int64))v44[10].__vecDelDtor)(v43, &v53, 1i64);
        v40[2] = v53;
        v45 = v50;
        v40[3] = -1;
        v40[1] = v45;
        *v40 = v52;
        if ( v33 )
        {
          v46 = v2->pFile.pObject;
          v47 = v46->vfptr;
          v48 = 0;
          ((void (__fastcall *)(Scaleform::File *, char *, signed __int64))v47[10].__vecDelDtor)(v46, &v48, 1i64);
          v40[3] = v48;
        }
        v37 += 4i64;
        --v19;
      }
      while ( v19 );
    }
  }
  v2->FilePos = ((__int64 (*)(void))v2->pFile.pObject->vfptr[5].__vecDelDtor)();
  return 1;
}

// File Line: 151
// RVA: 0x96BF30
char __fastcall Scaleform::Render::TGA::TGAFileImageSource::Decode(Scaleform::Render::TGA::TGAFileImageSource *this, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  void *v4; // r13
  Scaleform::Render::ImageData *v5; // r15
  Scaleform::Render::TGA::TGAFileImageSource *v6; // rbx
  Scaleform::File *v7; // rcx
  char *v8; // rdx
  char v9; // r12
  unsigned int v10; // esi
  signed int v11; // er14
  unsigned int v12; // edi
  unsigned int v13; // ebp
  char *v14; // rdi
  Scaleform::Render::Palette *v15; // r9
  unsigned __int64 v16; // r8
  char *v17; // rdx
  volatile signed __int32 *v18; // rax
  volatile signed __int32 *v19; // rdx
  Scaleform::Render::ImageScanlineBufferImpl v21; // [rsp+40h] [rbp-1078h]
  char tempBuffer; // [rsp+80h] [rbp-1038h]
  unsigned int v23; // [rsp+10C0h] [rbp+8h]
  void (__fastcall *v24)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // [rsp+10D0h] [rbp+18h]

  v24 = copyScanline;
  v4 = arg;
  v5 = pdest;
  v6 = this;
  v7 = this->pFile.pObject;
  if ( !v7
    || ((__int64 (__fastcall *)(Scaleform::File *, __int64, _QWORD))v7->vfptr[15].__vecDelDtor)(v7, v6->FilePos, 0i64) != v6->FilePos )
  {
    return 0;
  }
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v21,
    v6->SourceFormat,
    v6->Size.Width,
    v6->Format,
    &tempBuffer,
    0x1000ui64);
  if ( v21.ReadFormat && v21.Width && (v8 = v21.pReadScanline) != 0i64 )
  {
    v9 = 1;
    if ( v6->ImageDesc & 0x20 )
    {
      v10 = 0;
      v11 = 1;
    }
    else
    {
      v10 = v6->Size.Height - 1;
      v11 = -1;
    }
    v12 = v21.ReadScanlineSize;
    v23 = v21.ReadScanlineSize;
    v13 = 0;
    if ( v6->Size.Height )
    {
      while ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v6->pFile.pObject->vfptr[10].__vecDelDtor)(
                v6->pFile.pObject,
                v8,
                v12) == v12 )
      {
        v14 = &v5->pPlanes->pData[v10 * v5->pPlanes->Pitch];
        v15 = v6->pColorMap.pObject;
        v16 = v21.ReadScanlineSize;
        v17 = v21.pReadScanline;
        if ( v21.pConvertFunc )
        {
          v21.pConvertFunc(v21.pConvertScanline, v21.pReadScanline, v21.ReadScanlineSize, v15, 0i64);
          v15 = 0i64;
          v16 = v21.ConvertScanlineSize;
          v17 = v21.pConvertScanline;
        }
        v24(v14, v17, v16, v15, v4);
        ++v13;
        v10 += v11;
        if ( v13 >= v6->Size.Height )
          goto LABEL_16;
        v8 = v21.pReadScanline;
        v12 = v23;
      }
      v9 = 0;
    }
LABEL_16:
    if ( v6->Format == 100 )
    {
      v18 = &v6->pColorMap.pObject->RefCount.Value;
      if ( v18 )
        _InterlockedExchangeAdd(v18, 1u);
      v19 = &v5->pPalette.pObject->RefCount.Value;
      if ( v19 && !_InterlockedDecrement(v19) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v5->pPalette.pObject = v6->pColorMap.pObject;
    }
  }
  else
  {
    v9 = 0;
  }
  if ( v21.BuffersAllocated )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21.pReadScanline);
  return v9;
}

// File Line: 198
// RVA: 0x99A660
bool __fastcall Scaleform::Render::TGA::FileReader::MatchFormat(Scaleform::Render::TGA::FileReader *this, Scaleform::File *file, char *headerArg, unsigned __int64 headerArgSize)
{
  Scaleform::File *v4; // r14
  int v6; // edx
  unsigned __int8 v7; // r8
  unsigned __int8 v8; // bl
  int v9; // edi
  int v10; // esi
  signed __int64 v11; // rdx
  Scaleform::Render::FileHeaderReaderImpl v12; // [rsp+30h] [rbp-28h]
  char tempBuffer; // [rsp+38h] [rbp-20h]

  v4 = file;
  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v12, file, headerArg, headerArgSize, &tempBuffer, 18);
  if ( !v12.pHeader )
    return 0;
  v6 = *((unsigned __int8 *)v12.pHeader + 2);
  v7 = v12.pHeader[7];
  v8 = v12.pHeader[16];
  if ( v12.pHeader[1] )
  {
    if ( v12.pHeader[1] != 1 || v6 != 1 )
      return 0;
  }
  else if ( v6 != 2 )
  {
    return 0;
  }
  if ( v7 > 0x20u )
    return 0;
  v11 = 4311744513i64;
  if ( !_bittest64(&v11, v7) || (v8 - 8) & 0xE7 || v8 == 16 || v12.pHeader[17] & 0xC0 )
    return 0;
  v9 = *((unsigned __int16 *)v12.pHeader + 6);
  v10 = *((unsigned __int16 *)v12.pHeader + 7);
  return ((signed int (__fastcall *)(Scaleform::File *))v4->vfptr[6].__vecDelDtor)(v4) >= (signed int)(v9 * v10 * ((unsigned int)v8 >> 3) + 18);
}

// File Line: 232
// RVA: 0x9A5930
Scaleform::Render::TGA::TGAFileImageSource *__fastcall Scaleform::Render::TGA::FileReader::ReadImageSource(Scaleform::Render::TGA::FileReader *this, Scaleform::File *file, Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::ImageCreateArgs *v3; // rsi
  Scaleform::File *v4; // rdi
  Scaleform::Render::FileImageSource *v5; // rax
  Scaleform::Render::TGA::TGAFileImageSource *v6; // rbx
  Scaleform::MemoryHeap *v7; // rdx

  v3 = args;
  v4 = file;
  if ( !file || !((unsigned __int8 (__fastcall *)(Scaleform::File *))file->vfptr[2].__vecDelDtor)(file) )
    return 0i64;
  v5 = (Scaleform::Render::FileImageSource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                               Scaleform::Memory::pGlobalHeap,
                                               72i64);
  v6 = (Scaleform::Render::TGA::TGAFileImageSource *)v5;
  if ( v5 )
  {
    Scaleform::Render::FileImageSource::FileImageSource(v5, v4, v3->Format, 0i64);
    v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TGA::TGAFileImageSource::`vftable;
    v6->SourceFormat = 0;
    v6->ImageDesc = 0;
    v6->pColorMap.pObject = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
  {
    v7 = Scaleform::Memory::pGlobalHeap;
    if ( v3->pHeap )
      v7 = v3->pHeap;
    if ( !Scaleform::Render::TGA::TGAFileImageSource::ReadHeader(v6, v7) )
    {
      ((void (__fastcall *)(Scaleform::Render::TGA::TGAFileImageSource *))v6->vfptr[2].__vecDelDtor)(v6);
      v6 = 0i64;
    }
  }
  return v6;
}

// File Line: 245
// RVA: 0x159C700
__int64 dynamic_initializer_for__Scaleform::Render::TGA::FileReader::Instance__()
{
  Scaleform::Render::TGA::FileReader::Instance.vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::TGA::FileReader::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::TGA::FileReader::Instance__);
}

