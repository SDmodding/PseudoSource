// File Line: 121
// RVA: 0x95CA40
void __fastcall Scaleform::Render::DDS::DDSDescr::CalcShifts(Scaleform::Render::DDS::DDSDescr *this)
{
  unsigned int RBitMask; // edx
  char v2; // r8
  char v4; // r9
  unsigned int GBitMask; // ecx
  int v6; // edx
  unsigned int BBitMask; // ecx
  int v8; // edx
  unsigned int ABitMask; // ecx

  RBitMask = this->RBitMask;
  v2 = 0;
  v4 = 0;
  if ( RBitMask )
  {
    if ( (RBitMask & 0xFFFFFF) != 0 )
    {
      if ( (_WORD)RBitMask )
      {
        if ( !(_BYTE)RBitMask )
        {
          RBitMask >>= 8;
          v4 = 8;
        }
      }
      else
      {
        RBitMask >>= 16;
        v4 = 16;
      }
    }
    else
    {
      RBitMask >>= 24;
      v4 = 24;
    }
    for ( ; (RBitMask & 1) == 0; ++v4 )
      RBitMask >>= 1;
  }
  this->ShiftR = v4;
  GBitMask = this->GBitMask;
  v6 = 0;
  if ( GBitMask )
  {
    if ( (GBitMask & 0xFFFFFF) != 0 )
    {
      if ( (_WORD)GBitMask )
      {
        if ( !(_BYTE)GBitMask )
        {
          GBitMask >>= 8;
          v6 = 8;
        }
      }
      else
      {
        GBitMask >>= 16;
        v6 = 16;
      }
    }
    else
    {
      GBitMask >>= 24;
      v6 = 24;
    }
    for ( ; (GBitMask & 1) == 0; ++v6 )
      GBitMask >>= 1;
  }
  BBitMask = this->BBitMask;
  this->ShiftG = v6;
  v8 = 0;
  if ( BBitMask )
  {
    if ( (BBitMask & 0xFFFFFF) != 0 )
    {
      if ( (_WORD)BBitMask )
      {
        if ( !(_BYTE)BBitMask )
        {
          BBitMask >>= 8;
          v8 = 8;
        }
      }
      else
      {
        BBitMask >>= 16;
        v8 = 16;
      }
    }
    else
    {
      BBitMask >>= 24;
      v8 = 24;
    }
    for ( ; (BBitMask & 1) == 0; ++v8 )
      BBitMask >>= 1;
  }
  ABitMask = this->ABitMask;
  this->ShiftB = v8;
  if ( ABitMask )
  {
    if ( (ABitMask & 0xFFFFFF) != 0 )
    {
      if ( (_WORD)ABitMask )
      {
        if ( !(_BYTE)ABitMask )
        {
          ABitMask >>= 8;
          v2 = 8;
        }
      }
      else
      {
        ABitMask >>= 16;
        v2 = 16;
      }
    }
    else
    {
      ABitMask >>= 24;
      v2 = 24;
    }
    for ( ; (ABitMask & 1) == 0; ++v2 )
      ABitMask >>= 1;
  }
  this->ShiftA = v2;
}

// File Line: 163
// RVA: 0x939B60
void __fastcall Scaleform::Render::DDS::DDSFileImageSource::DDSFileImageSource(
        Scaleform::Render::DDS::DDSFileImageSource *this,
        Scaleform::File *file,
        Scaleform::Render::ImageFormat format)
{
  char ShiftA; // al

  Scaleform::Render::FileImageSource::FileImageSource(this, file, format, 0i64);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DDS::DDSFileImageSource::`vftable;
  this->ImageDesc = 0;
  *(_QWORD *)&this->HeaderInfo.Width = 0i64;
  *(_QWORD *)&this->HeaderInfo.Pitch = 0i64;
  *(_QWORD *)&this->HeaderInfo.MipmapCount = 1i64;
  *(_QWORD *)&this->HeaderInfo.DDSFmt.BBitMask = 0i64;
  *(_QWORD *)&this->HeaderInfo.DDSFmt.RBitMask = 0i64;
  ShiftA = this->HeaderInfo.DDSFmt.ShiftA;
  this->HeaderInfo.DDSFmt.ShiftB = ShiftA;
  this->HeaderInfo.DDSFmt.ShiftG = ShiftA;
  this->HeaderInfo.DDSFmt.ShiftR = ShiftA;
  this->HeaderInfo.DDSFmt.HasAlpha = 0;
  this->HeaderInfo.OppositeEndian = 0;
}

// File Line: 168
// RVA: 0x989A10
__int64 __fastcall Scaleform::Render::DDS::DDSFileImageSource::GetMipmapCount(
        Scaleform::Render::DDS::DDSFileImageSource *this)
{
  return this->HeaderInfo.MipmapCount;
}

// File Line: 183
// RVA: 0x9922B0
char __fastcall Scaleform::Render::DDS::Image_ParseDDSHeader(
        Scaleform::Render::DDS::DDSHeaderInfo *pinfo,
        const char *buf,
        const char **pdata)
{
  int v3; // r10d
  unsigned int v6; // eax
  int v7; // r8d
  int v8; // edx
  const char *v9; // r9
  unsigned int v10; // eax
  unsigned int v11; // eax

  v3 = *(_DWORD *)buf;
  if ( (*(_DWORD *)buf & 2) != 0 )
    pinfo->Height = *((_DWORD *)buf + 1);
  if ( (v3 & 4) != 0 )
    pinfo->Width = *((_DWORD *)buf + 2);
  v6 = *((_DWORD *)buf + 3);
  if ( (v3 & 8) == 0 )
  {
    if ( (v3 & 0x80000) == 0 )
      goto LABEL_9;
    v6 = 4 * (v6 / pinfo->Height);
  }
  pinfo->Pitch = v6;
LABEL_9:
  if ( (v3 & 0x20000) != 0 )
    pinfo->MipmapCount = *((_DWORD *)buf + 5);
  if ( (v3 & 0x1000) == 0 )
  {
    v9 = buf + 100;
    goto LABEL_39;
  }
  if ( *((_DWORD *)buf + 17) != 32 )
    return 0;
  v7 = *((_DWORD *)buf + 18);
  v8 = *((_DWORD *)buf + 19);
  v9 = buf + 80;
  if ( (v7 & 4) == 0 )
  {
    if ( (v7 & 0x40) == 0 && (v7 & 2) == 0 )
      goto LABEL_36;
    v10 = *(_DWORD *)v9;
    pinfo->DDSFmt.RGBBitCount = *(_DWORD *)v9;
    switch ( v10 )
    {
      case 8u:
        if ( (v7 & 2) != 0 )
        {
          pinfo->Format = Image_A8;
          goto LABEL_32;
        }
        break;
      case 0x18u:
        pinfo->Format = Image_R8G8B8;
        goto LABEL_32;
      case 0x20u:
        pinfo->Format = Image_R8G8B8A8;
LABEL_32:
        if ( (v3 & 8) == 0 )
          pinfo->Pitch = pinfo->Width * (v10 >> 3);
        v11 = *((_DWORD *)v9 + 1);
        v9 += 20;
        pinfo->DDSFmt.RBitMask = v11;
        pinfo->DDSFmt.GBitMask = *((_DWORD *)v9 - 3);
        pinfo->DDSFmt.BBitMask = *((_DWORD *)v9 - 2);
        if ( (v7 & 1) != 0 )
        {
          pinfo->DDSFmt.ABitMask = *((_DWORD *)v9 - 1);
          pinfo->DDSFmt.HasAlpha = 1;
        }
        goto LABEL_36;
    }
    return 0;
  }
  switch ( v8 )
  {
    case 894720068:
      pinfo->Format = Image_DXT5;
      v9 += 20;
      break;
    case 861165636:
      pinfo->Format = Image_DXT3;
      v9 += 20;
      break;
    case 827611204:
      pinfo->Format = Image_DXT1;
      v9 += 20;
      break;
    default:
      if ( ((v8 - 844388420) & 0xFDFFFFFF) == 0 || v8 != 808540228 )
        return 0;
      pinfo->Format = Image_BC7;
      v9 += 20;
      break;
  }
LABEL_36:
  if ( pinfo->Format == Image_None )
    return 0;
LABEL_39:
  if ( pdata )
    *pdata = v9 + 20;
  return 1;
}

// File Line: 328
// RVA: 0x9A0370
char __fastcall Scaleform::Render::DDS::ProcessUDDSData(
        char *buffer,
        unsigned __int64 size,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::DDS::DDSDescr *ddsFmt)
{
  unsigned __int64 v6; // r11
  unsigned int v7; // eax
  __int64 v8; // rcx
  __int64 v9; // r9
  unsigned int v10; // r10d
  unsigned __int64 v12; // r11
  int v13; // eax
  __int64 v14; // rdi
  unsigned int v15; // r10d

  if ( format != Image_R8G8B8 )
  {
    if ( format == Image_R8G8B8A8 && size )
    {
      v12 = 0i64;
      v13 = 1;
      do
      {
        v14 = (unsigned int)(v13 + 2);
        v15 = (unsigned __int8)buffer[v12] | (((unsigned __int8)buffer[v13] | (((unsigned __int8)buffer[v13 + 1] | ((unsigned __int8)buffer[v14] << 8)) << 8)) << 8);
        buffer[v13 + 1] = v15 >> ddsFmt->ShiftB;
        buffer[v13] = v15 >> ddsFmt->ShiftG;
        buffer[v12] = v15 >> ddsFmt->ShiftR;
        if ( ddsFmt->HasAlpha )
          buffer[v14] = v15 >> ddsFmt->ShiftA;
        else
          buffer[v14] = -1;
        v13 += 4;
        v12 = (unsigned int)(v13 - 1);
      }
      while ( v12 < size );
    }
    return 1;
  }
  if ( !size )
    return 1;
  v6 = 0i64;
  v7 = 1;
  do
  {
    v8 = v7 + 1;
    v9 = v7;
    v7 += 3;
    v10 = (unsigned __int8)buffer[v6] | (((unsigned __int8)buffer[v9] | ((unsigned __int8)buffer[v8] << 8)) << 8);
    buffer[(unsigned int)v8] = v10 >> ddsFmt->ShiftB;
    buffer[v9] = v10 >> ddsFmt->ShiftG;
    buffer[v6] = v10 >> ddsFmt->ShiftR;
    v6 = v7 - 1;
  }
  while ( v6 < size );
  return 1;
}

// File Line: 359
// RVA: 0x96AB20
char __fastcall Scaleform::Render::DDS::DDSFileImageSource::Decode(
        Scaleform::Render::DDS::DDSFileImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::File *pObject; // rcx
  unsigned int Width; // esi
  unsigned int Height; // r14d
  unsigned int v9; // edx
  int v10; // eax
  __int64 v11; // rax
  unsigned int RawPlaneCount; // ecx
  Scaleform::Render::ImagePlane *v13; // rax
  unsigned __int64 Pitch; // r13
  unsigned __int64 ReadScanlineSize_low; // r15
  char *pReadScanline; // rdx
  unsigned int i; // esi
  unsigned __int64 v18; // rcx
  Scaleform::Render::ImageFormat Format; // r8d
  unsigned __int64 ReadScanlineSize; // r8
  char *pConvertScanline; // rdx
  unsigned int v23; // [rsp+30h] [rbp-D0h]
  char *pData; // [rsp+38h] [rbp-C8h]
  Scaleform::Render::ImagePlane p; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v26; // [rsp+60h] [rbp-A0h]
  Scaleform::Render::ImageScanlineBufferImpl v27; // [rsp+70h] [rbp-90h] BYREF
  char tempBuffer[4144]; // [rsp+B0h] [rbp-50h] BYREF
  unsigned int v29; // [rsp+10F0h] [rbp+FF0h]

  v26 = -2i64;
  pObject = this->pFile.pObject;
  if ( !pObject
    || ((__int64 (__fastcall *)(Scaleform::File *, __int64, _QWORD))pObject->vfptr[15].__vecDelDtor)(
         pObject,
         this->FilePos,
         0i64) != this->FilePos )
  {
    return 0;
  }
  Width = this->Size.Width;
  v29 = Width;
  Height = this->Size.Height;
  v9 = 0;
  v23 = 0;
  if ( !pdest->LevelCount )
    return 1;
  while ( 1 )
  {
    memset(&p, 0, sizeof(p));
    if ( (pdest->Flags & 1) == 0 )
    {
      Scaleform::Render::ImagePlane::GetMipLevel(pdest->pPlanes, pdest->Format, v9, &p, 0);
      pData = p.pData;
      goto LABEL_16;
    }
    if ( (pdest->Format & 0xFFF) != 0 )
    {
      if ( (pdest->Format & 0xFFF) == 200 )
      {
        v10 = 3;
      }
      else if ( (pdest->Format & 0xFFF) == 201 )
      {
        v10 = 4;
      }
      else
      {
        v10 = 1;
      }
    }
    else
    {
      v10 = 0;
    }
    v11 = v9 * v10;
    RawPlaneCount = pdest->RawPlaneCount;
    if ( (unsigned int)v11 >= RawPlaneCount )
    {
      Scaleform::Render::ImagePlane::GetMipLevel(
        &pdest->pPlanes[(unsigned int)v11 % RawPlaneCount],
        pdest->Format,
        (unsigned int)v11 / RawPlaneCount,
        &p,
        (unsigned int)v11 % RawPlaneCount);
      pData = p.pData;
LABEL_16:
      Pitch = p.Pitch;
      goto LABEL_17;
    }
    v13 = &pdest->pPlanes[v11];
    Pitch = v13->Pitch;
    pData = v13->pData;
LABEL_17:
    Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
      &v27,
      this->HeaderInfo.Format,
      Width,
      this->Format,
      tempBuffer,
      0x1000ui64);
    ReadScanlineSize_low = SLODWORD(v27.ReadScanlineSize);
    if ( v27.ReadFormat == Image_None )
      break;
    if ( !v27.Width )
      break;
    pReadScanline = v27.pReadScanline;
    if ( !v27.pReadScanline )
      break;
    for ( i = 0; ; ++i )
    {
      v18 = (this->Format & 0xFFFu) - 50 > 3 ? Height : (unsigned __int64)(Height + 3) >> 2;
      if ( i >= v18 )
        break;
      if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[10].__vecDelDtor)(
             this->pFile.pObject,
             pReadScanline,
             (unsigned int)ReadScanlineSize_low) != (_DWORD)ReadScanlineSize_low )
        goto LABEL_39;
      Format = this->Format;
      if ( ((Format - 1) & 0xFFFFFFFD) == 0 )
        Scaleform::Render::DDS::ProcessUDDSData(
          v27.pReadScanline,
          ReadScanlineSize_low,
          Format,
          &this->HeaderInfo.DDSFmt);
      ReadScanlineSize = v27.ReadScanlineSize;
      pConvertScanline = v27.pReadScanline;
      if ( v27.pConvertFunc )
      {
        ((void (__fastcall *)(char *, char *, unsigned __int64))v27.pConvertFunc)(
          v27.pConvertScanline,
          v27.pReadScanline,
          v27.ReadScanlineSize);
        ReadScanlineSize = v27.ConvertScanlineSize;
        pConvertScanline = v27.pConvertScanline;
      }
      copyScanline(&pData[Pitch * i], pConvertScanline, ReadScanlineSize, 0i64, arg);
      pReadScanline = v27.pReadScanline;
    }
    Width = v29 >> 1;
    if ( !(v29 >> 1) )
      Width = 1;
    v29 = Width;
    Height >>= 1;
    if ( !Height )
      Height = 1;
    if ( v27.BuffersAllocated )
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v27.pReadScanline);
    v9 = v23 + 1;
    v23 = v9;
    if ( v9 >= (unsigned __int8)pdest->LevelCount )
      return 1;
  }
LABEL_39:
  if ( v27.BuffersAllocated )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v27.pReadScanline);
  return 0;
}

// File Line: 399
// RVA: 0x9A50A0
char __fastcall Scaleform::Render::DDS::DDSFileImageSource::ReadHeader(
        Scaleform::Render::DDS::DDSFileImageSource *this)
{
  char result; // al
  Scaleform::File *pObject; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  unsigned int Height; // ecx
  char buf[264]; // [rsp+20h] [rbp-108h] BYREF
  int v7; // [rsp+130h] [rbp+8h] BYREF
  int v8; // [rsp+138h] [rbp+10h] BYREF

  ((void (__fastcall *)(Scaleform::File *, int *, __int64))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[10].__vecDelDtor)(
    this->pFile.pObject,
    &v8,
    4i64);
  if ( v8 != 542327876 )
    return 0;
  pObject = this->pFile.pObject;
  vfptr = pObject->vfptr;
  v7 = 0;
  ((void (__fastcall *)(Scaleform::File *, int *, __int64))vfptr[10].__vecDelDtor)(pObject, &v7, 4i64);
  if ( v7 != 124
    || ((unsigned int (__fastcall *)(Scaleform::File *, char *, __int64))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[10].__vecDelDtor)(
         this->pFile.pObject,
         buf,
         120i64) != 120 )
  {
    return 0;
  }
  result = Scaleform::Render::DDS::Image_ParseDDSHeader(&this->HeaderInfo, buf, 0i64);
  if ( result )
  {
    if ( this->HeaderInfo.Format == Image_BC7 )
      ((void (__fastcall *)(Scaleform::File *, __int64, __int64))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[14].__vecDelDtor)(
        this->pFile.pObject,
        20i64,
        1i64);
    this->HeaderInfo.OppositeEndian = 0;
    Scaleform::Render::DDS::DDSDescr::CalcShifts(&this->HeaderInfo.DDSFmt);
    if ( this->Format == Image_None )
      this->Format = this->HeaderInfo.Format;
    Height = this->HeaderInfo.Height;
    this->Size.Width = this->HeaderInfo.Width;
    this->Size.Height = Height;
    this->FilePos = ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[5].__vecDelDtor)(this->pFile.pObject);
    return 1;
  }
  return result;
}

// File Line: 436
// RVA: 0x99A560
bool __fastcall Scaleform::Render::DDS::FileReader::MatchFormat(
        Scaleform::Render::DDS::FileReader *this,
        Scaleform::File *file,
        char *headerArg,
        unsigned __int64 headerArgSize)
{
  Scaleform::Render::FileHeaderReaderImpl v5; // [rsp+30h] [rbp-18h] BYREF
  char tempBuffer[16]; // [rsp+38h] [rbp-10h] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v5, file, headerArg, headerArgSize, tempBuffer, 4u);
  return v5.pHeader && *v5.pHeader == 68 && v5.pHeader[1] == 68 && v5.pHeader[2] == 83 && v5.pHeader[3] == 32;
}

// File Line: 446
// RVA: 0x9A5760
Scaleform::Render::DDS::DDSFileImageSource *__fastcall Scaleform::Render::DDS::FileReader::ReadImageSource(
        Scaleform::Render::DDS::FileReader *this,
        Scaleform::File *file,
        Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::DDS::DDSFileImageSource *v5; // rax
  Scaleform::Render::DDS::DDSFileImageSource *v6; // rax
  Scaleform::Render::DDS::DDSFileImageSource *v7; // rbx

  if ( file && ((unsigned __int8 (__fastcall *)(Scaleform::File *))file->vfptr[2].__vecDelDtor)(file) )
  {
    v5 = (Scaleform::Render::DDS::DDSFileImageSource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         112i64);
    if ( v5 )
    {
      Scaleform::Render::DDS::DDSFileImageSource::DDSFileImageSource(v5, file, args->Format);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    if ( !v7 || Scaleform::Render::DDS::DDSFileImageSource::ReadHeader(v7) )
      return v7;
    ((void (__fastcall *)(Scaleform::Render::DDS::DDSFileImageSource *))v7->vfptr[2].__vecDelDtor)(v7);
  }
  return 0i64;
}

// File Line: 461
// RVA: 0x159C610
__int64 dynamic_initializer_for__Scaleform::Render::DDS::FileReader::Instance__()
{
  Scaleform::Render::DDS::FileReader::Instance.vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::DDS::FileReader::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::DDS::FileReader::Instance__);
}

