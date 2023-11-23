// File Line: 48
// RVA: 0x9A53B0
char __fastcall Scaleform::Render::TGA::TGAFileImageSource::ReadHeader(
        Scaleform::Render::TGA::TGAFileImageSource *this,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::File *pObject; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::File *v6; // rcx
  Scaleform::RefCountImplCoreVtbl *v7; // rax
  Scaleform::File *v8; // rcx
  Scaleform::RefCountImplCoreVtbl *v9; // rax
  int v10; // r12d
  Scaleform::File *v11; // rcx
  int v12; // r15d
  Scaleform::RefCountImplCoreVtbl *v13; // rax
  Scaleform::Render::ImageFormat v14; // edi
  Scaleform::File *v15; // rcx
  Scaleform::RefCountImplCoreVtbl *v16; // rax
  Scaleform::File *v17; // rcx
  Scaleform::RefCountImplCoreVtbl *v18; // rax
  __int64 v19; // r14
  unsigned int v20; // esi
  __int64 v21; // rcx
  Scaleform::File *v22; // rcx
  Scaleform::File *v23; // rcx
  Scaleform::File *v24; // rcx
  Scaleform::File *v25; // rcx
  Scaleform::File *v26; // rcx
  Scaleform::RefCountImplCoreVtbl *v27; // rax
  Scaleform::File *v29; // rcx
  Scaleform::RefCountImplCoreVtbl *v30; // rax
  unsigned __int8 v31; // dl
  Scaleform::Render::ImageFormat SourceFormat; // eax
  bool v33; // r15
  Scaleform::Render::Palette *v34; // rax
  Scaleform::Render::Palette *v35; // rdx
  Scaleform::Render::Palette *v36; // rdi
  __int64 v37; // rsi
  Scaleform::File *v38; // rcx
  Scaleform::RefCountImplCoreVtbl *v39; // rax
  char *v40; // rdi
  Scaleform::File *v41; // rcx
  Scaleform::RefCountImplCoreVtbl *v42; // rax
  Scaleform::File *v43; // rcx
  Scaleform::RefCountImplCoreVtbl *v44; // rax
  char v45; // al
  Scaleform::File *v46; // rcx
  Scaleform::RefCountImplCoreVtbl *v47; // rax
  char v48; // [rsp+20h] [rbp-20h] BYREF
  char v49; // [rsp+21h] [rbp-1Fh] BYREF
  char v50; // [rsp+22h] [rbp-1Eh] BYREF
  char v51; // [rsp+23h] [rbp-1Dh] BYREF
  char v52; // [rsp+24h] [rbp-1Ch] BYREF
  char v53; // [rsp+25h] [rbp-1Bh] BYREF
  char v54[2]; // [rsp+26h] [rbp-1Ah] BYREF
  unsigned __int16 v55[2]; // [rsp+28h] [rbp-18h] BYREF
  unsigned __int16 v56; // [rsp+2Ch] [rbp-14h] BYREF
  unsigned __int16 v57[2]; // [rsp+30h] [rbp-10h] BYREF
  __int16 v58; // [rsp+34h] [rbp-Ch] BYREF
  __int16 v59[2]; // [rsp+38h] [rbp-8h] BYREF
  __int16 v60; // [rsp+3Ch] [rbp-4h] BYREF
  unsigned __int8 v61; // [rsp+80h] [rbp+40h] BYREF
  unsigned __int8 v62; // [rsp+90h] [rbp+50h] BYREF
  unsigned __int8 v63; // [rsp+98h] [rbp+58h] BYREF

  pObject = this->pFile.pObject;
  vfptr = pObject->vfptr;
  v54[0] = 0;
  ((void (__fastcall *)(Scaleform::File *, char *, __int64))vfptr[10].__vecDelDtor)(pObject, v54, 1i64);
  v6 = this->pFile.pObject;
  v7 = v6->vfptr;
  v61 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int8 *, __int64))v7[10].__vecDelDtor)(v6, &v61, 1i64);
  v8 = this->pFile.pObject;
  v9 = v8->vfptr;
  v10 = v61;
  v62 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int8 *, __int64))v9[10].__vecDelDtor)(v8, &v62, 1i64);
  v11 = this->pFile.pObject;
  v12 = v62;
  v13 = v11->vfptr;
  v14 = Image_B8G8R8A8;
  v58 = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v13[10].__vecDelDtor)(v11, &v58, 2i64);
  v15 = this->pFile.pObject;
  v16 = v15->vfptr;
  v55[0] = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int16 *, __int64))v16[10].__vecDelDtor)(v15, v55, 2i64);
  v17 = this->pFile.pObject;
  v18 = v17->vfptr;
  v19 = v55[0];
  v63 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int8 *, __int64))v18[10].__vecDelDtor)(v17, &v63, 1i64);
  v20 = v63;
  if ( v63 > 0x20u )
    return 0;
  v21 = 0x101000001i64;
  if ( !_bittest64(&v21, v63) )
    return 0;
  v22 = this->pFile.pObject;
  v59[0] = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v22->vfptr[10].__vecDelDtor)(v22, v59, 2i64);
  v23 = this->pFile.pObject;
  v60 = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v23->vfptr[10].__vecDelDtor)(v23, &v60, 2i64);
  v24 = this->pFile.pObject;
  v56 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int16 *, __int64))v24->vfptr[10].__vecDelDtor)(v24, &v56, 2i64);
  v25 = this->pFile.pObject;
  v57[0] = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int16 *, __int64))v25->vfptr[10].__vecDelDtor)(v25, v57, 2i64);
  v26 = this->pFile.pObject;
  v27 = v26->vfptr;
  v51 = 0;
  ((void (__fastcall *)(Scaleform::File *, char *, __int64))v27[10].__vecDelDtor)(v26, &v51, 1i64);
  this->Size.Width = v56;
  this->Size.Height = v57[0];
  if ( v10 )
  {
    if ( v10 != 1 || v12 != 1 )
      return 0;
  }
  else if ( v12 != 2 )
  {
    return 0;
  }
  v29 = this->pFile.pObject;
  v30 = v29->vfptr;
  v49 = 0;
  ((void (__fastcall *)(Scaleform::File *, char *, __int64))v30[10].__vecDelDtor)(v29, &v49, 1i64);
  v31 = v54[0];
  this->ImageDesc = v49;
  if ( v31 )
    this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[11].__vecDelDtor(this->pFile.pObject, v31);
  switch ( v51 )
  {
    case 8:
      this->SourceFormat = Image_P8;
      break;
    case 24:
      this->SourceFormat = Image_B8G8R8;
      break;
    case 32:
      this->SourceFormat = Image_B8G8R8A8;
      break;
    default:
      return 0;
  }
  if ( this->Format == Image_None )
  {
    SourceFormat = this->SourceFormat;
    if ( SourceFormat == Image_P8 )
    {
      if ( v20 < 0x20 )
        v14 = Image_B8G8R8;
      this->Format = v14;
    }
    else
    {
      this->Format = SourceFormat;
    }
  }
  if ( v10 == 1 )
  {
    v33 = v20 == 32;
    v34 = Scaleform::Render::Palette::Create(v19, v20 == 32, pheap);
    v35 = this->pColorMap.pObject;
    v36 = v34;
    if ( v35 && !_InterlockedDecrement(&v35->RefCount.Value) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    this->pColorMap.pObject = v36;
    if ( !v36 )
      return 0;
    if ( (_DWORD)v19 )
    {
      v37 = 8i64;
      do
      {
        v38 = this->pFile.pObject;
        v39 = v38->vfptr;
        v40 = (char *)this->pColorMap.pObject + v37;
        v52 = 0;
        ((void (__fastcall *)(Scaleform::File *, char *, __int64))v39[10].__vecDelDtor)(v38, &v52, 1i64);
        v41 = this->pFile.pObject;
        v42 = v41->vfptr;
        v50 = 0;
        ((void (__fastcall *)(Scaleform::File *, char *, __int64))v42[10].__vecDelDtor)(v41, &v50, 1i64);
        v43 = this->pFile.pObject;
        v44 = v43->vfptr;
        v53 = 0;
        ((void (__fastcall *)(Scaleform::File *, char *, __int64))v44[10].__vecDelDtor)(v43, &v53, 1i64);
        v40[2] = v53;
        v45 = v50;
        v40[3] = -1;
        v40[1] = v45;
        *v40 = v52;
        if ( v33 )
        {
          v46 = this->pFile.pObject;
          v47 = v46->vfptr;
          v48 = 0;
          ((void (__fastcall *)(Scaleform::File *, char *, __int64))v47[10].__vecDelDtor)(v46, &v48, 1i64);
          v40[3] = v48;
        }
        v37 += 4i64;
        --v19;
      }
      while ( v19 );
    }
  }
  this->FilePos = ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[5].__vecDelDtor)(this->pFile.pObject);
  return 1;
}

// File Line: 151
// RVA: 0x96BF30
char __fastcall Scaleform::Render::TGA::TGAFileImageSource::Decode(
        Scaleform::Render::TGA::TGAFileImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::File *pObject; // rcx
  char *v8; // rdx
  char v9; // r12
  unsigned int v10; // esi
  int v11; // r14d
  unsigned int ReadScanlineSize; // edi
  unsigned int v13; // ebp
  char *v14; // rdi
  Scaleform::Render::Palette *v15; // r9
  unsigned __int64 ConvertScanlineSize; // r8
  char *pReadScanline; // rdx
  Scaleform::Render::Palette *v18; // rax
  Scaleform::Render::Palette *v19; // rdx
  Scaleform::Render::ImageScanlineBufferImpl v21; // [rsp+40h] [rbp-1078h] BYREF
  char tempBuffer[4152]; // [rsp+80h] [rbp-1038h] BYREF
  unsigned int v23; // [rsp+10C0h] [rbp+8h]

  pObject = this->pFile.pObject;
  if ( !pObject
    || ((__int64 (__fastcall *)(Scaleform::File *, __int64, _QWORD))pObject->vfptr[15].__vecDelDtor)(
         pObject,
         this->FilePos,
         0i64) != this->FilePos )
  {
    return 0;
  }
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v21,
    this->SourceFormat,
    this->Size.Width,
    this->Format,
    tempBuffer,
    0x1000ui64);
  if ( v21.ReadFormat && v21.Width && (v8 = v21.pReadScanline) != 0i64 )
  {
    v9 = 1;
    if ( (this->ImageDesc & 0x20) != 0 )
    {
      v10 = 0;
      v11 = 1;
    }
    else
    {
      v10 = this->Size.Height - 1;
      v11 = -1;
    }
    ReadScanlineSize = v21.ReadScanlineSize;
    v23 = v21.ReadScanlineSize;
    v13 = 0;
    if ( this->Size.Height )
    {
      while ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[10].__vecDelDtor)(
                this->pFile.pObject,
                v8,
                ReadScanlineSize) == ReadScanlineSize )
      {
        v14 = &pdest->pPlanes->pData[v10 * pdest->pPlanes->Pitch];
        v15 = this->pColorMap.pObject;
        ConvertScanlineSize = v21.ReadScanlineSize;
        pReadScanline = v21.pReadScanline;
        if ( v21.pConvertFunc )
        {
          v21.pConvertFunc(v21.pConvertScanline, v21.pReadScanline, v21.ReadScanlineSize, v15, 0i64);
          v15 = 0i64;
          ConvertScanlineSize = v21.ConvertScanlineSize;
          pReadScanline = v21.pConvertScanline;
        }
        copyScanline(v14, pReadScanline, ConvertScanlineSize, v15, arg);
        ++v13;
        v10 += v11;
        if ( v13 >= this->Size.Height )
          goto LABEL_16;
        v8 = v21.pReadScanline;
        ReadScanlineSize = v23;
      }
      v9 = 0;
    }
LABEL_16:
    if ( this->Format == Image_P8 )
    {
      v18 = this->pColorMap.pObject;
      if ( v18 )
        _InterlockedExchangeAdd(&v18->RefCount.Value, 1u);
      v19 = pdest->pPalette.pObject;
      if ( v19 && !_InterlockedDecrement(&v19->RefCount.Value) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pdest->pPalette.pObject = this->pColorMap.pObject;
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
bool __fastcall Scaleform::Render::TGA::FileReader::MatchFormat(
        Scaleform::Render::TGA::FileReader *this,
        Scaleform::File *file,
        char *headerArg,
        unsigned __int64 headerArgSize)
{
  int v6; // edx
  unsigned __int8 v7; // r8
  unsigned __int8 v8; // bl
  int v9; // edi
  int v10; // esi
  __int64 v11; // rdx
  Scaleform::Render::FileHeaderReaderImpl v12; // [rsp+30h] [rbp-28h] BYREF
  char tempBuffer[32]; // [rsp+38h] [rbp-20h] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v12, file, headerArg, headerArgSize, tempBuffer, 0x12u);
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
  if ( v7 <= 0x20u )
  {
    v11 = 0x101000001i64;
    if ( _bittest64(&v11, v7) )
    {
      if ( ((v8 - 8) & 0xE7) == 0 && v8 != 16 && (v12.pHeader[17] & 0xC0) == 0 )
      {
        v9 = *((unsigned __int16 *)v12.pHeader + 6);
        v10 = *((unsigned __int16 *)v12.pHeader + 7);
        return ((int (__fastcall *)(Scaleform::File *))file->vfptr[6].__vecDelDtor)(file) >= v9 * v10 * (v8 >> 3) + 18;
      }
    }
  }
  return 0;
}

// File Line: 232
// RVA: 0x9A5930
Scaleform::Render::TGA::TGAFileImageSource *__fastcall Scaleform::Render::TGA::FileReader::ReadImageSource(
        Scaleform::Render::TGA::FileReader *this,
        Scaleform::File *file,
        Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::FileImageSource *v5; // rax
  Scaleform::Render::TGA::TGAFileImageSource *v6; // rbx
  Scaleform::MemoryHeap *pHeap; // rdx

  if ( !file || !((unsigned __int8 (__fastcall *)(Scaleform::File *))file->vfptr[2].__vecDelDtor)(file) )
    return 0i64;
  v5 = (Scaleform::Render::FileImageSource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                               Scaleform::Memory::pGlobalHeap,
                                               72i64);
  v6 = (Scaleform::Render::TGA::TGAFileImageSource *)v5;
  if ( v5 )
  {
    Scaleform::Render::FileImageSource::FileImageSource(v5, file, args->Format, 0i64);
    v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TGA::TGAFileImageSource::`vftable;
    v6->SourceFormat = Image_None;
    v6->ImageDesc = 0;
    v6->pColorMap.pObject = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
  {
    pHeap = Scaleform::Memory::pGlobalHeap;
    if ( args->pHeap )
      pHeap = args->pHeap;
    if ( !Scaleform::Render::TGA::TGAFileImageSource::ReadHeader(v6, pHeap) )
    {
      ((void (__fastcall *)(Scaleform::Render::TGA::TGAFileImageSource *))v6->vfptr[2].__vecDelDtor)(v6);
      return 0i64;
    }
  }
  return v6;
}

// File Line: 245
// RVA: 0x159C700
__int64 dynamic_initializer_for__Scaleform::Render::TGA::FileReader::Instance__()
{
  Scaleform::Render::TGA::FileReader::Instance.vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::TGA::FileReader::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::TGA::FileReader::Instance__);
}

