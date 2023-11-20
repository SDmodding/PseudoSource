// File Line: 384
// RVA: 0x989A20
signed __int64 __fastcall Scaleform::Render::PVR::PVRFileImageSource::GetMipmapCount(Scaleform::Render::PVR::PVRFileImageSource *this)
{
  signed __int64 result; // rax

  result = this->HeaderInfo.MipMapCount;
  if ( (unsigned int)result < 1 )
    result = 1i64;
  return result;
}

// File Line: 403
// RVA: 0x992440
bool __fastcall Scaleform::Render::PVR::Image_ParsePVRHeader(Scaleform::Render::PVR::PVRHeaderInfo *pinfo, const char *buf, const char **pdata)
{
  unsigned int v3; // eax
  Scaleform::Render::PVR::PVRHeaderInfo *v4; // r8
  unsigned int v5; // ecx
  int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // edx
  unsigned __int64 v10; // rax
  unsigned int v11; // ecx
  signed __int64 v12; // rax
  signed __int64 v13; // rax
  signed __int64 v14; // rax
  signed int v15; // ecx
  unsigned __int64 v17; // [rsp+10h] [rbp+10h]

  v3 = *(_DWORD *)buf;
  v4 = pinfo;
  if ( *(_DWORD *)buf == 1347834371 || v3 == 55727696 )
  {
    pinfo->Version = 1347834371;
    pinfo->pfFlags = *((_DWORD *)buf + 1);
    v10 = *((_QWORD *)buf + 1);
    pinfo->PVR3Format = v10;
    v17 = v10;
    pinfo->ColorSpace = *((_DWORD *)buf + 4);
    pinfo->ChannelType = *((_DWORD *)buf + 5);
    pinfo->Height = *((_DWORD *)buf + 6);
    pinfo->Width = *((_DWORD *)buf + 7);
    pinfo->Depth = *((_DWORD *)buf + 8);
    pinfo->NumSurfs = *((_DWORD *)buf + 9);
    pinfo->NumFases = *((_DWORD *)buf + 10);
    pinfo->MipMapCount = *((_DWORD *)buf + 11);
    v11 = *((_DWORD *)buf + 12);
    v4->Format = 0;
    v4->MetaDataSize = v11;
    if ( HIDWORD(v10) )
    {
      if ( (_BYTE)v10 == 114 )
      {
        if ( BYTE1(v17) == 103 && BYTE2(v17) == 98 )
        {
          if ( BYTE3(v17) == 97 )
          {
            if ( BYTE4(v10) == 8 && BYTE5(v17) == 8 && BYTE6(v10) == 8 && HIBYTE(v10) == 8 )
            {
$LN3_101:
              v4->Format = 1;
              LOBYTE(v6) = v4->Format != 0;
              return v6;
            }
          }
          else if ( !BYTE3(v17) && BYTE4(v10) == 8 && BYTE5(v17) == 8 && HIWORD(v10) == 8 )
          {
$LN2_106:
            v4->Format = 3;
            LOBYTE(v6) = v4->Format != 0;
            return v6;
          }
        }
      }
      else if ( (_BYTE)v10 == 97
             && !BYTE1(v17)
             && __PAIR__(BYTE2(v17), 0) == BYTE3(v17)
             && WORD2(v10) == 8
             && !BYTE6(v10) )
      {
        v15 = 0;
        if ( !HIBYTE(v10) )
          v15 = 9;
        v4->Format = v15;
      }
    }
    else
    {
      if ( !(_DWORD)v10 )
      {
        v4->Format = 56;
        return v4->Format != 0;
      }
      v12 = v10 - 1;
      if ( !v12 )
      {
        v4->Format = 57;
        LOBYTE(v6) = v4->Format != 0;
        return v6;
      }
      v13 = v12 - 1;
      if ( !v13 )
      {
        v4->Format = 54;
        LOBYTE(v6) = v4->Format != 0;
        return v6;
      }
      v14 = v13 - 1;
      if ( !v14 )
      {
        v4->Format = 55;
        LOBYTE(v6) = v4->Format != 0;
        return v6;
      }
      if ( v14 == 3 )
      {
$LN4_112:
        v4->Format = 58;
        LOBYTE(v6) = v4->Format != 0;
        return v6;
      }
    }
LABEL_42:
    LOBYTE(v6) = v4->Format != 0;
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
  v4->PVR = v5;
  v4->NumSurfs = *((_DWORD *)buf + 12);
  if ( v5 == 559044176 )
  {
    v7 = v4->pfFlags;
    v4->Format = 0;
    switch ( (unsigned __int8)v7 )
    {
      case 0xCu:
      case 0x18u:
        v8 = (v7 & 0x8000 | 0x1C0000) >> 15;
        v4->Format = v8;
        LOBYTE(v6) = v8 != 0;
        return v6;
      case 0xDu:
      case 0x19u:
        v9 = (v7 & 0x8000 | 0x1B0000) >> 15;
        v4->Format = v9;
        LOBYTE(v6) = v9 != 0;
        return v6;
      case 0x12u:
        goto $LN3_101;
      case 0x15u:
        goto $LN2_106;
      case 0x16u:
        LOBYTE(v6) = 1;
        v4->Format = 9;
        return v6;
      case 0x36u:
        goto $LN4_112;
      default:
        goto LABEL_42;
    }
    goto LABEL_42;
  }
  LOBYTE(v6) = 0;
  return v6;
}

// File Line: 516
// RVA: 0x96B3D0
char __fastcall Scaleform::Render::PVR::PVRFileImageSource::Decode(Scaleform::Render::PVR::PVRFileImageSource *this, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  Scaleform::Render::PVR::PVRFileImageSource *v4; // rbp
  Scaleform::File *v5; // rcx
  Scaleform::Render::ImageData *v6; // rdi
  __int64 v7; // rbx
  int v8; // esi
  Scaleform::Render::ImageFormat v9; // er10
  signed int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // eax
  signed __int64 v13; // rcx
  char *v14; // rdx
  int v15; // eax
  Scaleform::Render::ImagePlane p; // [rsp+30h] [rbp-28h]

  v4 = this;
  v5 = this->pFile.pObject;
  v6 = pdest;
  if ( !v5 )
    return 0;
  v7 = v4->FilePos;
  if ( ((__int64 (__fastcall *)(Scaleform::File *, __int64, _QWORD, void *))v5->vfptr[15].__vecDelDtor)(
         v5,
         v4->FilePos,
         0i64,
         arg) != v7 )
    return 0;
  if ( v4->HeaderInfo.Version == 1347834371 )
    ((void (__fastcall *)(Scaleform::File *, __int64, _QWORD))v4->pFile.pObject->vfptr[15].__vecDelDtor)(
      v4->pFile.pObject,
      v7 + v4->HeaderInfo.MetaDataSize,
      0i64);
  if ( v6->Flags & 1 )
  {
    v8 = 0;
    if ( v6->LevelCount )
    {
      while ( 1 )
      {
        v9 = v6->Format;
        *(_QWORD *)&p.Width = 0i64;
        p.Pitch = 0i64;
        p.DataSize = 0i64;
        p.pData = 0i64;
        if ( v9 & 0xFFF )
        {
          if ( (v9 & 0xFFF) == 200 )
            v10 = 3;
          else
            v10 = (v9 & 0xFFF) == 201 ? 4 : 1;
        }
        else
        {
          v10 = 0;
        }
        v11 = v6->RawPlaneCount;
        v12 = v8 * v10;
        if ( v12 >= v11 )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(&v6->pPlanes[v12 % v11], v9, v12 / v11, &p, v12 % v11);
          v14 = p.pData;
        }
        else
        {
          v13 = (signed __int64)&v6->pPlanes[v12];
          v14 = *(char **)(v13 + 24);
          p.DataSize = *(_QWORD *)(v13 + 16);
        }
        v15 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))v4->pFile.pObject->vfptr[10].__vecDelDtor)(
                v4->pFile.pObject,
                v14,
                LODWORD(p.DataSize));
        if ( v15 != LODWORD(p.DataSize) )
          break;
        if ( ++v8 >= (unsigned int)(unsigned __int8)v6->LevelCount )
          return 1;
      }
      return 0;
    }
    return 1;
  }
  if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v4->pFile.pObject->vfptr[10].__vecDelDtor)(
         v4->pFile.pObject,
         v6->pPlanes->pData,
         LODWORD(v6->pPlanes->DataSize)) == LODWORD(v6->pPlanes->DataSize) )
    return 1;
  return 0;
}

// File Line: 551
// RVA: 0x9A51B0
char __fastcall Scaleform::Render::PVR::PVRFileImageSource::ReadHeader(Scaleform::Render::PVR::PVRFileImageSource *this)
{
  Scaleform::Render::PVR::PVRFileImageSource *v1; // rbx
  unsigned int v3; // ecx
  char buf; // [rsp+20h] [rbp-108h]

  v1 = this;
  if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, signed __int64))this->pFile.pObject->vfptr[10].__vecDelDtor)(
         this->pFile.pObject,
         &buf,
         52i64) != 52
    || !Scaleform::Render::PVR::Image_ParsePVRHeader(&v1->HeaderInfo, &buf, 0i64) )
  {
    return 0;
  }
  if ( v1->Format == Image_None )
    v1->Format = v1->HeaderInfo.Format;
  v3 = v1->HeaderInfo.Height;
  v1->Size.Width = v1->HeaderInfo.Width;
  v1->Size.Height = v3;
  v1->FilePos = ((__int64 (*)(void))v1->pFile.pObject->vfptr[5].__vecDelDtor)();
  return 1;
}

// File Line: 566
// RVA: 0x99A5B0
bool __fastcall Scaleform::Render::PVR::FileReader::MatchFormat(Scaleform::Render::PVR::FileReader *this, Scaleform::File *file, char *headerArg, unsigned __int64 headerArgSize)
{
  bool result; // al
  int v5; // eax
  Scaleform::Render::FileHeaderReaderImpl v6; // [rsp+30h] [rbp-48h]
  char tempBuffer; // [rsp+38h] [rbp-40h]

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v6, file, headerArg, headerArgSize, &tempBuffer, 52);
  result = 0;
  if ( v6.pHeader )
  {
    if ( (v5 = *(_DWORD *)v6.pHeader, *(_DWORD *)v6.pHeader == 52) && *((_DWORD *)v6.pHeader + 11) == 559044176
      || v5 == 1347834371
      || v5 == 55727696 )
    {
      result = 1;
    }
  }
  return result;
}

// File Line: 581
// RVA: 0x9A57F0
Scaleform::Render::PVR::PVRFileImageSource *__fastcall Scaleform::Render::PVR::FileReader::ReadImageSource(Scaleform::Render::PVR::FileReader *this, Scaleform::File *file, Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::ImageCreateArgs *v3; // rsi
  Scaleform::File *v4; // rdi
  Scaleform::Render::FileImageSource *v5; // rax
  Scaleform::Render::PVR::PVRFileImageSource *v6; // rbx

  v3 = args;
  v4 = file;
  if ( file && ((unsigned __int8 (__fastcall *)(Scaleform::File *))file->vfptr[2].__vecDelDtor)(file) )
  {
    v5 = (Scaleform::Render::FileImageSource *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 160ui64,
                                                 0i64);
    v6 = (Scaleform::Render::PVR::PVRFileImageSource *)v5;
    if ( v5 )
    {
      Scaleform::Render::FileImageSource::FileImageSource(v5, v4, v3->Format, 0i64);
      v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::PVR::PVRFileImageSource::`vftable';
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
  Scaleform::Render::PVR::FileReader::Instance.vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::PVR::FileReader::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::PVR::FileReader::Instance__);
}

