// File Line: 121
// RVA: 0x95CA40
void __fastcall Scaleform::Render::DDS::DDSDescr::CalcShifts(Scaleform::Render::DDS::DDSDescr *this)
{
  unsigned int v1; // edx
  char v2; // r8
  Scaleform::Render::DDS::DDSDescr *v3; // r10
  char v4; // r9
  unsigned int v5; // ecx
  signed int v6; // edx
  unsigned int v7; // ecx
  signed int v8; // edx
  unsigned int v9; // ecx

  v1 = this->RBitMask;
  v2 = 0;
  v3 = this;
  v4 = 0;
  if ( v1 )
  {
    if ( v1 & 0xFFFFFF )
    {
      if ( (_WORD)v1 )
      {
        if ( !(_BYTE)v1 )
        {
          v1 >>= 8;
          v4 = 8;
        }
      }
      else
      {
        v1 >>= 16;
        v4 = 16;
      }
    }
    else
    {
      v1 >>= 24;
      v4 = 24;
    }
    for ( ; !(v1 & 1); ++v4 )
      v1 >>= 1;
  }
  this->ShiftR = v4;
  v5 = this->GBitMask;
  v6 = 0;
  if ( v5 )
  {
    if ( v5 & 0xFFFFFF )
    {
      if ( (_WORD)v5 )
      {
        if ( !(_BYTE)v5 )
        {
          v5 >>= 8;
          v6 = 8;
        }
      }
      else
      {
        v5 >>= 16;
        v6 = 16;
      }
    }
    else
    {
      v5 >>= 24;
      v6 = 24;
    }
    for ( ; !(v5 & 1); ++v6 )
      v5 >>= 1;
  }
  v7 = v3->BBitMask;
  v3->ShiftG = v6;
  v8 = 0;
  if ( v7 )
  {
    if ( v7 & 0xFFFFFF )
    {
      if ( (_WORD)v7 )
      {
        if ( !(_BYTE)v7 )
        {
          v7 >>= 8;
          v8 = 8;
        }
      }
      else
      {
        v7 >>= 16;
        v8 = 16;
      }
    }
    else
    {
      v7 >>= 24;
      v8 = 24;
    }
    for ( ; !(v7 & 1); ++v8 )
      v7 >>= 1;
  }
  v9 = v3->ABitMask;
  v3->ShiftB = v8;
  if ( v9 )
  {
    if ( v9 & 0xFFFFFF )
    {
      if ( (_WORD)v9 )
      {
        if ( !(_BYTE)v9 )
        {
          v9 >>= 8;
          v2 = 8;
        }
      }
      else
      {
        v9 >>= 16;
        v2 = 16;
      }
    }
    else
    {
      v9 >>= 24;
      v2 = 24;
    }
    for ( ; !(v9 & 1); ++v2 )
      v9 >>= 1;
  }
  v3->ShiftA = v2;
}

// File Line: 163
// RVA: 0x939B60
void __fastcall Scaleform::Render::DDS::DDSFileImageSource::DDSFileImageSource(Scaleform::Render::DDS::DDSFileImageSource *this, Scaleform::File *file, Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::DDS::DDSFileImageSource *v3; // rbx
  char v4; // al

  v3 = this;
  Scaleform::Render::FileImageSource::FileImageSource(
    (Scaleform::Render::FileImageSource *)&this->vfptr,
    file,
    format,
    0i64);
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DDS::DDSFileImageSource::`vftable';
  v3->ImageDesc = 0;
  *(_QWORD *)&v3->HeaderInfo.Width = 0i64;
  *(_QWORD *)&v3->HeaderInfo.Pitch = 0i64;
  *(_QWORD *)&v3->HeaderInfo.MipmapCount = 1i64;
  *(_QWORD *)&v3->HeaderInfo.DDSFmt.BBitMask = 0i64;
  *(_QWORD *)&v3->HeaderInfo.DDSFmt.RBitMask = 0i64;
  v4 = v3->HeaderInfo.DDSFmt.ShiftA;
  v3->HeaderInfo.DDSFmt.ShiftB = v4;
  v3->HeaderInfo.DDSFmt.ShiftG = v4;
  v3->HeaderInfo.DDSFmt.ShiftR = v4;
  v3->HeaderInfo.DDSFmt.HasAlpha = 0;
  v3->HeaderInfo.OppositeEndian = 0;
}

// File Line: 168
// RVA: 0x989A10
__int64 __fastcall Scaleform::Render::DDS::DDSFileImageSource::GetMipmapCount(Scaleform::Render::DDS::DDSFileImageSource *this)
{
  return this->HeaderInfo.MipmapCount;
}

// File Line: 183
// RVA: 0x9922B0
char __fastcall Scaleform::Render::DDS::Image_ParseDDSHeader(Scaleform::Render::DDS::DDSHeaderInfo *pinfo, const char *buf, const char **pdata)
{
  int v3; // er10
  const char **v4; // rbx
  const char *v5; // r9
  unsigned int v6; // eax
  int v7; // er8
  int v8; // edx
  unsigned int *v9; // r9
  unsigned int v10; // eax
  unsigned int v11; // eax

  v3 = *(_DWORD *)buf;
  v4 = pdata;
  v5 = buf;
  if ( *(_DWORD *)buf & 2 )
    pinfo->Height = *((_DWORD *)buf + 1);
  if ( v3 & 4 )
    pinfo->Width = *((_DWORD *)buf + 2);
  v6 = *((_DWORD *)buf + 3);
  if ( !(v3 & 8) )
  {
    if ( !_bittest(&v3, 0x13u) )
      goto LABEL_9;
    v6 = 4 * (v6 / pinfo->Height);
  }
  pinfo->Pitch = v6;
LABEL_9:
  if ( _bittest(&v3, 0x11u) )
    pinfo->MipmapCount = *((_DWORD *)buf + 5);
  if ( !_bittest(&v3, 0xCu) )
  {
    v9 = (unsigned int *)(buf + 100);
    goto LABEL_39;
  }
  if ( *((_DWORD *)buf + 17) != 32 )
    return 0;
  v7 = *((_DWORD *)buf + 18);
  v8 = *((_DWORD *)buf + 19);
  v9 = (unsigned int *)(v5 + 80);
  if ( !(v7 & 4) )
  {
    if ( !(v7 & 0x40) && !(v7 & 2) )
      goto LABEL_36;
    v10 = *v9;
    pinfo->DDSFmt.RGBBitCount = *v9;
    switch ( v10 )
    {
      case 8u:
        if ( v7 & 2 )
        {
          pinfo->Format = 9;
          goto LABEL_32;
        }
        break;
      case 0x18u:
        pinfo->Format = 3;
        goto LABEL_32;
      case 0x20u:
        pinfo->Format = 1;
LABEL_32:
        if ( !(v3 & 8) )
          pinfo->Pitch = pinfo->Width * (v10 >> 3);
        v11 = v9[1];
        v9 += 5;
        pinfo->DDSFmt.RBitMask = v11;
        pinfo->DDSFmt.GBitMask = *(v9 - 3);
        pinfo->DDSFmt.BBitMask = *(v9 - 2);
        if ( v7 & 1 )
        {
          pinfo->DDSFmt.ABitMask = *(v9 - 1);
          pinfo->DDSFmt.HasAlpha = 1;
        }
        goto LABEL_36;
    }
    return 0;
  }
  switch ( v8 )
  {
    case 894720068:
      pinfo->Format = 52;
      v9 += 5;
      break;
    case 861165636:
      pinfo->Format = 51;
      v9 += 5;
      break;
    case 827611204:
      pinfo->Format = 50;
      v9 += 5;
      break;
    default:
      if ( !((v8 - 844388420) & 0xFDFFFFFF) || v8 != 808540228 )
        return 0;
      pinfo->Format = 53;
      v9 += 5;
      break;
  }
LABEL_36:
  if ( pinfo->Format == Image_None )
    return 0;
LABEL_39:
  if ( v4 )
    *v4 = (const char *)(v9 + 5);
  return 1;
}

// File Line: 328
// RVA: 0x9A0370
char __fastcall Scaleform::Render::DDS::ProcessUDDSData(char *buffer, unsigned __int64 size, Scaleform::Render::ImageFormat format, Scaleform::Render::DDS::DDSDescr *ddsFmt)
{
  Scaleform::Render::DDS::DDSDescr *v4; // rbx
  char *v5; // rbp
  unsigned __int64 v6; // r11
  unsigned int v7; // eax
  __int64 v8; // rcx
  __int64 v9; // r9
  unsigned int v10; // er10
  unsigned __int64 v12; // r11
  signed int v13; // eax
  __int64 v14; // rdi
  unsigned int v15; // er10

  v4 = ddsFmt;
  v5 = buffer;
  if ( format != 3 )
  {
    if ( format == 1 && size )
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
    v10 = (unsigned __int8)v5[v6] | (((unsigned __int8)v5[v9] | ((unsigned __int8)v5[v8] << 8)) << 8);
    v5[(unsigned int)v8] = v10 >> v4->ShiftB;
    v5[v9] = v10 >> v4->ShiftG;
    v5[v6] = v10 >> v4->ShiftR;
    v6 = v7 - 1;
  }
  while ( v6 < size );
  return 1;
}

// File Line: 359
// RVA: 0x96AB20
char __fastcall Scaleform::Render::DDS::DDSFileImageSource::Decode(Scaleform::Render::DDS::DDSFileImageSource *this, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  Scaleform::Render::ImageData *v4; // r12
  Scaleform::Render::DDS::DDSFileImageSource *v5; // rdi
  Scaleform::File *v6; // rcx
  unsigned int v7; // esi
  unsigned int v8; // er14
  unsigned int v9; // edx
  signed int v10; // eax
  __int64 v11; // rax
  unsigned int v12; // ecx
  signed __int64 v13; // rax
  unsigned __int64 v14; // r13
  unsigned __int64 v15; // r15
  char *v16; // rdx
  unsigned int v17; // esi
  unsigned __int64 v18; // rcx
  Scaleform::Render::ImageFormat v19; // er8
  unsigned __int64 v20; // r8
  char *v21; // rdx
  unsigned int v23; // [rsp+30h] [rbp-D0h]
  char *v24; // [rsp+38h] [rbp-C8h]
  Scaleform::Render::ImagePlane p; // [rsp+40h] [rbp-C0h]
  __int64 v26; // [rsp+60h] [rbp-A0h]
  Scaleform::Render::ImageScanlineBufferImpl v27; // [rsp+70h] [rbp-90h]
  char tempBuffer; // [rsp+B0h] [rbp-50h]
  unsigned int v29; // [rsp+10F0h] [rbp+FF0h]
  void (__fastcall *v30)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // [rsp+1100h] [rbp+1000h]
  void *v31; // [rsp+1108h] [rbp+1008h]

  v31 = arg;
  v30 = copyScanline;
  v26 = -2i64;
  v4 = pdest;
  v5 = this;
  v6 = this->pFile.pObject;
  if ( !v6
    || ((__int64 (__fastcall *)(Scaleform::File *, __int64, _QWORD))v6->vfptr[15].__vecDelDtor)(v6, v5->FilePos, 0i64) != v5->FilePos )
  {
    return 0;
  }
  v7 = v5->Size.Width;
  v29 = v5->Size.Width;
  v8 = v5->Size.Height;
  v9 = 0;
  v23 = 0;
  if ( !v4->LevelCount )
    return 1;
  while ( 1 )
  {
    *(_QWORD *)&p.Width = 0i64;
    p.Pitch = 0i64;
    p.DataSize = 0i64;
    p.pData = 0i64;
    if ( !(v4->Flags & 1) )
    {
      Scaleform::Render::ImagePlane::GetMipLevel(v4->pPlanes, v4->Format, v9, &p, 0);
      v24 = p.pData;
      goto LABEL_16;
    }
    if ( v4->Format & 0xFFF )
    {
      if ( (v4->Format & 0xFFF) == 200 )
      {
        v10 = 3;
      }
      else if ( (v4->Format & 0xFFF) == 201 )
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
    v12 = v4->RawPlaneCount;
    if ( (unsigned int)v11 >= v12 )
    {
      Scaleform::Render::ImagePlane::GetMipLevel(
        &v4->pPlanes[(unsigned int)v11 % v12],
        v4->Format,
        (unsigned int)v11 / v12,
        &p,
        (unsigned int)v11 % v12);
      v24 = p.pData;
LABEL_16:
      v14 = p.Pitch;
      goto LABEL_17;
    }
    v13 = (signed __int64)&v4->pPlanes[v11];
    v14 = *(_QWORD *)(v13 + 8);
    v24 = *(char **)(v13 + 24);
LABEL_17:
    Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
      &v27,
      v5->HeaderInfo.Format,
      v7,
      v5->Format,
      &tempBuffer,
      0x1000ui64);
    v15 = SLODWORD(v27.ReadScanlineSize);
    if ( v27.ReadFormat == Image_None )
      break;
    if ( !v27.Width )
      break;
    v16 = v27.pReadScanline;
    if ( !v27.pReadScanline )
      break;
    v17 = 0;
    while ( 1 )
    {
      v18 = (v5->Format & 0xFFFu) - 50 > 3 ? (unsigned __int64)v8 : (unsigned __int64)(v8 + 3) >> 2;
      if ( v17 >= v18 )
        break;
      if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v5->pFile.pObject->vfptr[10].__vecDelDtor)(
             v5->pFile.pObject,
             v16,
             (unsigned int)v15) != (_DWORD)v15 )
        goto LABEL_39;
      v19 = v5->Format;
      if ( !((v19 - 1) & 0xFFFFFFFD) )
        Scaleform::Render::DDS::ProcessUDDSData(v27.pReadScanline, v15, v19, &v5->HeaderInfo.DDSFmt);
      v20 = v27.ReadScanlineSize;
      v21 = v27.pReadScanline;
      if ( v27.pConvertFunc )
      {
        ((void (__fastcall *)(char *, char *, unsigned __int64))v27.pConvertFunc)(
          v27.pConvertScanline,
          v27.pReadScanline,
          v27.ReadScanlineSize);
        v20 = v27.ConvertScanlineSize;
        v21 = v27.pConvertScanline;
      }
      v30(&v24[v14 * v17++], v21, v20, 0i64, v31);
      v16 = v27.pReadScanline;
    }
    v7 = v29 >> 1;
    if ( v29 >> 1 < 1 )
      v7 = 1;
    v29 = v7;
    v8 >>= 1;
    if ( v8 < 1 )
      v8 = 1;
    if ( v27.BuffersAllocated )
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v27.pReadScanline);
    v9 = v23 + 1;
    v23 = v9;
    if ( v9 >= (unsigned __int8)v4->LevelCount )
      return 1;
  }
LABEL_39:
  if ( v27.BuffersAllocated )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v27.pReadScanline);
  return 0;
}

// File Line: 399
// RVA: 0x9A50A0
char __fastcall Scaleform::Render::DDS::DDSFileImageSource::ReadHeader(Scaleform::Render::DDS::DDSFileImageSource *this)
{
  Scaleform::Render::DDS::DDSFileImageSource *v1; // rbx
  char result; // al
  Scaleform::File *v3; // rcx
  Scaleform::RefCountImplCoreVtbl *v4; // rax
  unsigned int v5; // ecx
  char buf; // [rsp+20h] [rbp-108h]
  int v7; // [rsp+130h] [rbp+8h]
  int v8; // [rsp+138h] [rbp+10h]

  v1 = this;
  ((void (__fastcall *)(Scaleform::File *, int *, signed __int64))this->pFile.pObject->vfptr[10].__vecDelDtor)(
    this->pFile.pObject,
    &v8,
    4i64);
  if ( v8 != 542327876 )
    return 0;
  v3 = v1->pFile.pObject;
  v4 = v3->vfptr;
  v7 = 0;
  ((void (__fastcall *)(Scaleform::File *, int *, signed __int64))v4[10].__vecDelDtor)(v3, &v7, 4i64);
  if ( v7 != 124
    || ((unsigned int (__fastcall *)(Scaleform::File *, char *, signed __int64))v1->pFile.pObject->vfptr[10].__vecDelDtor)(
         v1->pFile.pObject,
         &buf,
         120i64) != 120 )
  {
    return 0;
  }
  result = Scaleform::Render::DDS::Image_ParseDDSHeader(&v1->HeaderInfo, &buf, 0i64);
  if ( result )
  {
    if ( v1->HeaderInfo.Format == 53 )
      ((void (__fastcall *)(Scaleform::File *, signed __int64, signed __int64))v1->pFile.pObject->vfptr[14].__vecDelDtor)(
        v1->pFile.pObject,
        20i64,
        1i64);
    v1->HeaderInfo.OppositeEndian = 0;
    Scaleform::Render::DDS::DDSDescr::CalcShifts(&v1->HeaderInfo.DDSFmt);
    if ( v1->Format == Image_None )
      v1->Format = v1->HeaderInfo.Format;
    v5 = v1->HeaderInfo.Height;
    v1->Size.Width = v1->HeaderInfo.Width;
    v1->Size.Height = v5;
    v1->FilePos = ((__int64 (*)(void))v1->pFile.pObject->vfptr[5].__vecDelDtor)();
    result = 1;
  }
  return result;
}

// File Line: 436
// RVA: 0x99A560
bool __fastcall Scaleform::Render::DDS::FileReader::MatchFormat(Scaleform::Render::DDS::FileReader *this, Scaleform::File *file, char *headerArg, unsigned __int64 headerArgSize)
{
  Scaleform::Render::FileHeaderReaderImpl v5; // [rsp+30h] [rbp-18h]
  char tempBuffer; // [rsp+38h] [rbp-10h]

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v5, file, headerArg, headerArgSize, &tempBuffer, 4);
  return v5.pHeader && *v5.pHeader == 68 && v5.pHeader[1] == 68 && v5.pHeader[2] == 83 && v5.pHeader[3] == 32;
}

// File Line: 446
// RVA: 0x9A5760
Scaleform::Render::DDS::DDSFileImageSource *__fastcall Scaleform::Render::DDS::FileReader::ReadImageSource(Scaleform::Render::DDS::FileReader *this, Scaleform::File *file, Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::ImageCreateArgs *v3; // rdi
  Scaleform::File *v4; // rbx
  Scaleform::Render::DDS::DDSFileImageSource *v5; // rax
  Scaleform::Render::DDS::DDSFileImageSource *v6; // rax
  Scaleform::Render::DDS::DDSFileImageSource *v7; // rbx

  v3 = args;
  v4 = file;
  if ( file && ((unsigned __int8 (__fastcall *)(Scaleform::File *))file->vfptr[2].__vecDelDtor)(file) )
  {
    v5 = (Scaleform::Render::DDS::DDSFileImageSource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         112i64);
    if ( v5 )
    {
      Scaleform::Render::DDS::DDSFileImageSource::DDSFileImageSource(v5, v4, v3->Format);
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
  Scaleform::Render::DDS::FileReader::Instance.vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::DDS::FileReader::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::DDS::FileReader::Instance__);
}

