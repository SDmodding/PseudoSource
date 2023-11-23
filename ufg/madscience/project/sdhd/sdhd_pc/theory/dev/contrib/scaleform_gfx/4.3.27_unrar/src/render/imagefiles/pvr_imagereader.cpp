// File Line: 384
// RVA: 0x989A20
__int64 __fastcall Scaleform::Render::PVR::PVRFileImageSource::GetMipmapCount(
        Scaleform::Render::PVR::PVRFileImageSource *this)
{
  __int64 result; // rax

  result = this->HeaderInfo.MipMapCount;
  if ( !(_DWORD)result )
    return 1i64;
  return result;
}

// File Line: 403
// RVA: 0x992440
bool __fastcall Scaleform::Render::PVR::Image_ParsePVRHeader(
        Scaleform::Render::PVR::PVRHeaderInfo *pinfo,
        const char *buf,
        const char **pdata)
{
  unsigned int v3; // eax
  unsigned int v5; // ecx
  int v6; // eax
  unsigned int pfFlags; // edx
  unsigned int v8; // edx
  unsigned int v9; // edx
  unsigned __int64 v10; // rax
  unsigned int v11; // ecx
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rax
  Scaleform::Render::ImageFormat v15; // ecx

  v3 = *(_DWORD *)buf;
  if ( *(_DWORD *)buf == 1347834371 || v3 == 55727696 )
  {
    pinfo->Version = 1347834371;
    pinfo->pfFlags = *((_DWORD *)buf + 1);
    v10 = *((_QWORD *)buf + 1);
    pinfo->PVR3Format = v10;
    pinfo->ColorSpace = *((_DWORD *)buf + 4);
    pinfo->ChannelType = *((_DWORD *)buf + 5);
    pinfo->Height = *((_DWORD *)buf + 6);
    pinfo->Width = *((_DWORD *)buf + 7);
    pinfo->Depth = *((_DWORD *)buf + 8);
    pinfo->NumSurfs = *((_DWORD *)buf + 9);
    pinfo->NumFases = *((_DWORD *)buf + 10);
    pinfo->MipMapCount = *((_DWORD *)buf + 11);
    v11 = *((_DWORD *)buf + 12);
    pinfo->Format = Image_None;
    pinfo->MetaDataSize = v11;
    if ( HIDWORD(v10) )
    {
      if ( (_BYTE)v10 == 114 )
      {
        if ( (unsigned __int16)((unsigned int)v10 >> 8) == 25191 )
        {
          if ( BYTE3(v10) == 97 )
          {
            if ( HIDWORD(v10) == 134744072 )
            {
$LN3_101:
              pinfo->Format = Image_R8G8B8A8;
              LOBYTE(v6) = pinfo->Format != Image_None;
              return v6;
            }
          }
          else if ( !BYTE3(v10) && HIDWORD(v10) == 526344 )
          {
$LN2_106:
            pinfo->Format = Image_R8G8B8;
            LOBYTE(v6) = pinfo->Format != Image_None;
            return v6;
          }
        }
      }
      else if ( (_BYTE)v10 == 97 && !(unsigned __int16)((unsigned int)v10 >> 8) && (unsigned int)(v10 >> 24) == 2048 )
      {
        v15 = Image_None;
        if ( !HIBYTE(v10) )
          v15 = Image_A8;
        pinfo->Format = v15;
      }
    }
    else
    {
      if ( !(_DWORD)v10 )
      {
        pinfo->Format = Image_PVRTC_RGB_2BPP;
        return pinfo->Format != Image_None;
      }
      v12 = v10 - 1;
      if ( !v12 )
      {
        pinfo->Format = Image_PVRTC_RGBA_2BPP;
        LOBYTE(v6) = pinfo->Format != Image_None;
        return v6;
      }
      v13 = v12 - 1;
      if ( !v13 )
      {
        pinfo->Format = Image_PVRTC_RGB_4BPP;
        LOBYTE(v6) = pinfo->Format != Image_None;
        return v6;
      }
      v14 = v13 - 1;
      if ( !v14 )
      {
        pinfo->Format = Image_PVRTC_RGBA_4BPP;
        LOBYTE(v6) = pinfo->Format != Image_None;
        return v6;
      }
      if ( v14 == 3 )
      {
$LN4_112:
        pinfo->Format = Image_ETC1_RGB_4BPP;
        LOBYTE(v6) = pinfo->Format != Image_None;
        return v6;
      }
    }
LABEL_34:
    LOBYTE(v6) = pinfo->Format != Image_None;
    return v6;
  }
  pinfo->HeaderSize = v3;
  pinfo->Height = *((_DWORD *)buf + 1);
  pinfo->Width = *((_DWORD *)buf + 2);
  pinfo->MipMapCount = *((_DWORD *)buf + 3);
  pinfo->pfFlags = *((_DWORD *)buf + 4);
  pinfo->TextureDataSize = *((_DWORD *)buf + 5);
  pinfo->BitCount = *((_DWORD *)buf + 6);
  pinfo->RBitMask = *((_DWORD *)buf + 7);
  pinfo->GBitMask = *((_DWORD *)buf + 8);
  pinfo->BBitMask = *((_DWORD *)buf + 9);
  pinfo->AlphaBitMask = *((_DWORD *)buf + 10);
  v5 = *((_DWORD *)buf + 11);
  pinfo->PVR = v5;
  pinfo->NumSurfs = *((_DWORD *)buf + 12);
  if ( v5 == 559044176 )
  {
    pfFlags = pinfo->pfFlags;
    pinfo->Format = Image_None;
    switch ( (char)pfFlags )
    {
      case 12:
      case 24:
        v8 = (pfFlags & 0x8000 | 0x1C0000) >> 15;
        pinfo->Format = v8;
        LOBYTE(v6) = v8 != 0;
        break;
      case 13:
      case 25:
        v9 = (pfFlags & 0x8000 | 0x1B0000) >> 15;
        pinfo->Format = v9;
        LOBYTE(v6) = v9 != 0;
        break;
      case 18:
        goto $LN3_101;
      case 21:
        goto $LN2_106;
      case 22:
        LOBYTE(v6) = 1;
        pinfo->Format = Image_A8;
        break;
      case 54:
        goto $LN4_112;
      default:
        goto LABEL_34;
    }
  }
  else
  {
    LOBYTE(v6) = 0;
  }
  return v6;
}

// File Line: 516
// RVA: 0x96B3D0
char __fastcall Scaleform::Render::PVR::PVRFileImageSource::Decode(
        Scaleform::Render::PVR::PVRFileImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::File *pObject; // rcx
  __int64 FilePos; // rbx
  int v8; // esi
  Scaleform::Render::ImageFormat Format; // r10d
  int v10; // eax
  unsigned int RawPlaneCount; // ecx
  unsigned int v12; // eax
  Scaleform::Render::ImagePlane *v13; // rcx
  char *pData; // rdx
  int v15; // eax
  Scaleform::Render::ImagePlane p; // [rsp+30h] [rbp-28h] BYREF

  pObject = this->pFile.pObject;
  if ( !pObject )
    return 0;
  FilePos = this->FilePos;
  if ( ((__int64 (__fastcall *)(Scaleform::File *, __int64, _QWORD, void *))pObject->vfptr[15].__vecDelDtor)(
         pObject,
         FilePos,
         0i64,
         arg) != FilePos )
    return 0;
  if ( this->HeaderInfo.Version == 1347834371 )
    ((void (__fastcall *)(Scaleform::File *, __int64, _QWORD))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[15].__vecDelDtor)(
      this->pFile.pObject,
      FilePos + this->HeaderInfo.MetaDataSize,
      0i64);
  if ( (pdest->Flags & 1) != 0 )
  {
    v8 = 0;
    if ( pdest->LevelCount )
    {
      while ( 1 )
      {
        Format = pdest->Format;
        memset(&p, 0, sizeof(p));
        if ( (Format & 0xFFF) != 0 )
        {
          if ( (Format & 0xFFF) == 200 )
            v10 = 3;
          else
            v10 = (Format & 0xFFF) == 201 ? 4 : 1;
        }
        else
        {
          v10 = 0;
        }
        RawPlaneCount = pdest->RawPlaneCount;
        v12 = v8 * v10;
        if ( v12 >= RawPlaneCount )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(
            &pdest->pPlanes[v12 % RawPlaneCount],
            Format,
            v12 / RawPlaneCount,
            &p,
            v12 % RawPlaneCount);
          pData = p.pData;
        }
        else
        {
          v13 = &pdest->pPlanes[v12];
          pData = v13->pData;
          p.DataSize = v13->DataSize;
        }
        v15 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[10].__vecDelDtor)(
                this->pFile.pObject,
                pData,
                LODWORD(p.DataSize));
        if ( v15 != LODWORD(p.DataSize) )
          break;
        if ( ++v8 >= (unsigned int)(unsigned __int8)pdest->LevelCount )
          return 1;
      }
      return 0;
    }
  }
  else if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[10].__vecDelDtor)(
              this->pFile.pObject,
              pdest->pPlanes->pData,
              LODWORD(pdest->pPlanes->DataSize)) != LODWORD(pdest->pPlanes->DataSize) )
  {
    return 0;
  }
  return 1;
}

// File Line: 551
// RVA: 0x9A51B0
char __fastcall Scaleform::Render::PVR::PVRFileImageSource::ReadHeader(
        Scaleform::Render::PVR::PVRFileImageSource *this)
{
  unsigned int Height; // ecx
  char buf[264]; // [rsp+20h] [rbp-108h] BYREF

  if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, __int64))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[10].__vecDelDtor)(
         this->pFile.pObject,
         buf,
         52i64) != 52
    || !Scaleform::Render::PVR::Image_ParsePVRHeader(&this->HeaderInfo, buf, 0i64) )
  {
    return 0;
  }
  if ( this->Format == Image_None )
    this->Format = this->HeaderInfo.Format;
  Height = this->HeaderInfo.Height;
  this->Size.Width = this->HeaderInfo.Width;
  this->Size.Height = Height;
  this->FilePos = ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[5].__vecDelDtor)(this->pFile.pObject);
  return 1;
}

// File Line: 566
// RVA: 0x99A5B0
bool __fastcall Scaleform::Render::PVR::FileReader::MatchFormat(
        Scaleform::Render::PVR::FileReader *this,
        Scaleform::File *file,
        char *headerArg,
        unsigned __int64 headerArgSize)
{
  bool result; // al
  int v5; // eax
  Scaleform::Render::FileHeaderReaderImpl v6; // [rsp+30h] [rbp-48h] BYREF
  char tempBuffer[64]; // [rsp+38h] [rbp-40h] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v6, file, headerArg, headerArgSize, tempBuffer, 0x34u);
  result = 0;
  if ( v6.pHeader )
  {
    v5 = *(_DWORD *)v6.pHeader;
    if ( *(_DWORD *)v6.pHeader == 52 && *((_DWORD *)v6.pHeader + 11) == 559044176 )
      return 1;
    if ( v5 == 1347834371 || v5 == 55727696 )
      return 1;
  }
  return result;
}

// File Line: 581
// RVA: 0x9A57F0
Scaleform::Render::PVR::PVRFileImageSource *__fastcall Scaleform::Render::PVR::FileReader::ReadImageSource(
        Scaleform::Render::PVR::FileReader *this,
        Scaleform::File *file,
        Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::FileImageSource *v5; // rax
  Scaleform::Render::PVR::PVRFileImageSource *v6; // rbx

  if ( file && ((unsigned __int8 (__fastcall *)(Scaleform::File *))file->vfptr[2].__vecDelDtor)(file) )
  {
    v5 = (Scaleform::Render::FileImageSource *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 160i64,
                                                 0i64);
    v6 = (Scaleform::Render::PVR::PVRFileImageSource *)v5;
    if ( v5 )
    {
      Scaleform::Render::FileImageSource::FileImageSource(v5, file, args->Format, 0i64);
      v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::PVR::PVRFileImageSource::`vftable;
      v6->ImageDesc = 0;
    }
    else
    {
      v6 = 0i64;
    }
    if ( !v6 || Scaleform::Render::PVR::PVRFileImageSource::ReadHeader(v6) )
      return v6;
    ((void (__fastcall *)(Scaleform::Render::PVR::PVRFileImageSource *))v6->vfptr[2].__vecDelDtor)(v6);
  }
  return 0i64;
}

// File Line: 596
// RVA: 0x159C660
__int64 dynamic_initializer_for__Scaleform::Render::PVR::FileReader::Instance__()
{
  Scaleform::Render::PVR::FileReader::Instance.vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::PVR::FileReader::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::PVR::FileReader::Instance__);
}

