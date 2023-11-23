// File Line: 108
// RVA: 0x89C1A0
void __fastcall Scaleform::GFx::`anonymous namespace::Params::Params(
        Scaleform::GFx::Params *this,
        void **jin,
        unsigned int width,
        Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->SourceScanline,
    Image_R8G8B8,
    width,
    Image_R8G8B8,
    this->SourceScanline.TempBuffer,
    0x800ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->AlphaScanline,
    Image_A8,
    width,
    Image_A8,
    this->AlphaScanline.TempBuffer,
    0x400ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->ScanlineWithAlpha0,
    Image_R8G8B8A8,
    width + 2,
    Image_R8G8B8A8,
    this->ScanlineWithAlpha0.TempBuffer,
    0x800ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->ScanlineWithAlpha1,
    Image_R8G8B8A8,
    width + 2,
    Image_R8G8B8A8,
    this->ScanlineWithAlpha1.TempBuffer,
    0x800ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->ScanlineWithAlpha2,
    Image_R8G8B8A8,
    width + 2,
    Image_R8G8B8A8,
    this->ScanlineWithAlpha2.TempBuffer,
    0x800ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->FinalScanline,
    Image_R8G8B8A8,
    width,
    format,
    this->FinalScanline.TempBuffer,
    0x1000ui64);
  this->ZlibFile.pObject = 0i64;
  this->Jin = jin;
  this->Width = width;
  this->Success = 1;
  this->ScanlineWithAlphas[0] = &this->ScanlineWithAlpha0;
  this->ScanlineWithAlphas[1] = &this->ScanlineWithAlpha1;
  this->ScanlineWithAlphas[2] = &this->ScanlineWithAlpha2;
  memset(this->ScanlineWithAlpha0.pReadScanline, 0, this->ScanlineWithAlpha0.ReadScanlineSize);
}

// File Line: 117
// RVA: 0x914B60
void __fastcall Scaleform::GFx::UndoPremultiplyAlphaScanline(Scaleform::GFx::Params *params)
{
  char *pReadScanline; // rbp
  char *v2; // r15
  char *v4; // r14
  char *v5; // r12
  unsigned int v6; // ebx
  int v7; // edi
  unsigned __int8 v8; // r8
  unsigned int v9; // ecx
  unsigned int v10; // r10d
  unsigned int v11; // r9d
  unsigned int v12; // eax
  char v13; // dl
  char v14; // dl
  char v15; // dl
  unsigned __int8 v16; // cl
  unsigned __int16 v17; // dx
  __int16 v18; // ax
  unsigned __int8 v19; // cl
  __int16 v20; // ax
  unsigned __int8 v21; // cl

  pReadScanline = params->FinalScanline.pReadScanline;
  v2 = params->ScanlineWithAlphas[0]->pReadScanline;
  v4 = params->ScanlineWithAlphas[1]->pReadScanline;
  v5 = params->ScanlineWithAlphas[2]->pReadScanline;
  memmove(pReadScanline, v4 + 4, params->FinalScanline.ReadScanlineSize);
  v6 = 0;
  if ( params->Width )
  {
    v7 = 0;
    do
    {
      v8 = pReadScanline[v7 + 3];
      if ( v8 >= 0x10u )
      {
        v16 = pReadScanline[v7 + 3];
        v17 = GFx_UndoPremultiplyTable[v8];
        if ( (unsigned __int8)pReadScanline[v7] <= v8 )
          v16 = pReadScanline[v7];
        v18 = v16;
        v19 = pReadScanline[v7 + 3];
        pReadScanline[v7] = (unsigned __int16)(v17 * v18) >> 8;
        if ( (unsigned __int8)pReadScanline[v7 + 1] <= v8 )
          v19 = pReadScanline[v7 + 1];
        v20 = v19;
        v21 = v8;
        pReadScanline[v7 + 1] = (unsigned __int16)(v17 * v20) >> 8;
        if ( (unsigned __int8)pReadScanline[v7 + 2] <= v8 )
          v21 = pReadScanline[v7 + 2];
        pReadScanline[v7 + 2] = (unsigned __int16)(v17 * v21) >> 8;
      }
      else
      {
        v9 = (unsigned __int8)v4[v7 + 7]
           + (unsigned __int8)v2[v7 + 7]
           + (unsigned __int8)v5[v7 + 7]
           + (unsigned __int8)v2[v7 + 3]
           + (unsigned __int8)v2[v7 + 11]
           + (unsigned __int8)v4[v7 + 3]
           + (unsigned __int8)v4[v7 + 11]
           + (unsigned __int8)v5[v7 + 3]
           + (unsigned __int8)v5[v7 + 11];
        if ( v9 )
        {
          v10 = (((unsigned __int8)v4[v7 + 8] << 8)
               + ((unsigned __int8)v5[v7] << 8)
               + ((unsigned __int8)v2[v7 + 4] << 8)
               + ((unsigned __int8)v5[v7 + 4] << 8)
               + ((unsigned __int8)v2[v7] << 8)
               + ((unsigned __int8)v2[v7 + 8] << 8)
               + ((unsigned __int8)v4[v7 + 4] << 8)
               + ((unsigned __int8)v4[v7] << 8)
               + ((unsigned __int8)v5[v7 + 8] << 8))
              / v9;
          v11 = (((unsigned __int8)v4[v7 + 5] << 8)
               + ((unsigned __int8)v2[v7 + 5] << 8)
               + ((unsigned __int8)v5[v7 + 5] << 8)
               + ((unsigned __int8)v2[v7 + 1] << 8)
               + ((unsigned __int8)v4[v7 + 1] << 8)
               + ((unsigned __int8)v4[v7 + 9] << 8)
               + ((unsigned __int8)v5[v7 + 1] << 8)
               + ((unsigned __int8)v5[v7 + 9] << 8)
               + ((unsigned __int8)v2[v7 + 9] << 8))
              / v9;
          v12 = (((unsigned __int8)v4[v7 + 6] << 8)
               + ((unsigned __int8)v2[v7 + 6] << 8)
               + ((unsigned __int8)v5[v7 + 6] << 8)
               + ((unsigned __int8)v2[v7 + 2] << 8)
               + ((unsigned __int8)v2[v7 + 10] << 8)
               + ((unsigned __int8)v4[v7 + 2] << 8)
               + ((unsigned __int8)v4[v7 + 10] << 8)
               + ((unsigned __int8)v5[v7 + 2] << 8)
               + ((unsigned __int8)v5[v7 + 10] << 8))
              / v9;
          v13 = -1;
          if ( v10 <= 0xFF )
            v13 = v10;
          pReadScanline[v7] = v13;
          v14 = -1;
          if ( v11 <= 0xFF )
            v14 = v11;
          pReadScanline[v7 + 1] = v14;
          v15 = -1;
          if ( v12 <= 0xFF )
            v15 = v12;
          pReadScanline[v7 + 2] = v15;
        }
      }
      ++v6;
      v7 += 4;
    }
    while ( v6 < params->Width );
  }
}

// File Line: 319
// RVA: 0x91CC80
__int64 __fastcall Scaleform::GFx::ZlibDecodeColorMapped(
        Scaleform::GFx::ZlibDecodeParams *params,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  unsigned int v7; // ebx
  unsigned int v8; // r15d
  char *pReadScanline; // rsi
  char *v10; // rbx
  char *v11; // r14
  unsigned int v12; // ebp
  __int64 v13; // r9
  unsigned int v14; // eax
  char *v15; // r8
  unsigned __int8 v16; // bl
  Scaleform::Render::ImageScanlineBufferImpl v18; // [rsp+40h] [rbp-FE8h] BYREF
  char tempBuffer[768]; // [rsp+80h] [rbp-FA8h] BYREF
  Scaleform::Render::ImageScanlineBufferImpl v20; // [rsp+380h] [rbp-CA8h] BYREF
  char v21[1024]; // [rsp+3C0h] [rbp-C68h] BYREF
  Scaleform::Render::ImageScanlineBufferImpl v22; // [rsp+7C0h] [rbp-868h] BYREF
  char v23[2048]; // [rsp+800h] [rbp-828h] BYREF

  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v18,
    Image_R8G8B8,
    params->ColorTableSize,
    Image_R8G8B8,
    tempBuffer,
    0x300ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v20,
    Image_A8,
    params->Size.Width,
    Image_A8,
    v21,
    0x400ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v22,
    Image_R8G8B8,
    params->Size.Width,
    params->Format,
    v23,
    0x800ui64);
  v7 = 3 * params->ColorTableSize;
  v8 = (params->Size.Width + 3) & 0xFFFFFFFC;
  if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))params->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
         params->ZlibFile.pObject,
         v18.pReadScanline,
         v7) != v7 )
  {
LABEL_9:
    v16 = 0;
    goto LABEL_10;
  }
  pReadScanline = v20.pReadScanline;
  v10 = v22.pReadScanline;
  v11 = v18.pReadScanline;
  v12 = 0;
  if ( params->Size.Height )
  {
    while ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))params->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
              params->ZlibFile.pObject,
              pReadScanline,
              v8) == v8 )
    {
      v13 = 0i64;
      if ( params->Size.Width )
      {
        v14 = 2;
        do
        {
          v15 = &v11[2 * (unsigned __int8)pReadScanline[v13] + (unsigned __int8)pReadScanline[v13]];
          v10[v14 - 2] = *v15;
          v10[v14 - 1] = v15[1];
          v10[v14] = v15[2];
          v13 = (unsigned int)(v13 + 1);
          v14 += 3;
        }
        while ( (unsigned int)v13 < params->Size.Width );
      }
      Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        &v22,
        &pdest->pPlanes->pData[v12++ * pdest->pPlanes->Pitch],
        0i64,
        copyScanline,
        arg);
      if ( v12 >= params->Size.Height )
        goto LABEL_8;
    }
    goto LABEL_9;
  }
LABEL_8:
  v16 = 1;
LABEL_10:
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v22);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v20);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v18);
  return v16;
}

// File Line: 355
// RVA: 0x91CEA0
__int64 __fastcall Scaleform::GFx::ZlibDecodeColorMappedAlpha(
        Scaleform::GFx::ZlibDecodeParams *params,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  void *v4; // r14
  int v6; // r15d
  int v7; // r12d
  char *pReadScanline; // r13
  unsigned int v9; // ebx
  unsigned int v10; // esi
  char *v11; // rbx
  char *v12; // r14
  __int64 v13; // r9
  unsigned int v14; // eax
  char *v15; // r8
  Scaleform::Render::ImageScanlineBuffer<2048> *v16; // rcx
  unsigned __int8 v17; // bl
  Scaleform::Render::ImageScanlineBufferImpl v19; // [rsp+40h] [rbp-C0h] BYREF
  char tempBuffer[1024]; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::Params paramsa; // [rsp+480h] [rbp+380h] BYREF
  unsigned int v22; // [rsp+3A80h] [rbp+3980h]

  v4 = arg;
  v6 = 1;
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v19,
    Image_R8G8B8A8,
    params->ColorTableSize,
    Image_R8G8B8A8,
    tempBuffer,
    0x400ui64);
  Scaleform::GFx::`anonymous namespace::Params::Params(&paramsa, 0i64, params->Size.Width, params->Format);
  v7 = 0;
  pReadScanline = v19.pReadScanline;
  v9 = 4 * params->ColorTableSize;
  v22 = (params->Size.Width + 3) & 0xFFFFFFFC;
  if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))params->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
         params->ZlibFile.pObject,
         v19.pReadScanline,
         v9) == v9 )
  {
    v10 = 0;
    if ( params->Size.Height != -1 )
    {
      do
      {
        v11 = paramsa.ScanlineWithAlphas[v6]->pReadScanline;
        *(_DWORD *)v11 = 0;
        *(_DWORD *)&v11[4 * (params->Size.Width + 1)] = 0;
        if ( v10 >= params->Size.Height )
        {
          memset(v11, 0, paramsa.ScanlineWithAlphas[v6]->ReadScanlineSize);
        }
        else
        {
          v12 = paramsa.AlphaScanline.pReadScanline;
          if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))params->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
                 params->ZlibFile.pObject,
                 paramsa.AlphaScanline.pReadScanline,
                 v22) != v22 )
            goto LABEL_18;
          v13 = 0i64;
          if ( params->Size.Width )
          {
            v14 = 2;
            do
            {
              v15 = &pReadScanline[4 * (unsigned __int8)v12[v13]];
              v11[v14 + 2] = *v15;
              v11[v14 + 3] = v15[1];
              v11[v14 + 4] = v15[2];
              v11[v14 + 5] = v15[3];
              v13 = (unsigned int)(v13 + 1);
              v14 += 4;
            }
            while ( (unsigned int)v13 < params->Size.Width );
          }
          v4 = arg;
        }
        if ( (unsigned int)++v7 >= 2 )
        {
          Scaleform::GFx::UndoPremultiplyAlphaScanline(&paramsa);
          Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
            &paramsa.FinalScanline,
            &pdest->pPlanes->pData[pdest->pPlanes->Pitch * (v10 - 1)],
            0i64,
            copyScanline,
            v4);
        }
        if ( v6 == 2 )
        {
          v16 = paramsa.ScanlineWithAlphas[2];
          paramsa.ScanlineWithAlphas[2] = paramsa.ScanlineWithAlphas[0];
          paramsa.ScanlineWithAlphas[0] = paramsa.ScanlineWithAlphas[1];
          paramsa.ScanlineWithAlphas[1] = v16;
        }
        else
        {
          ++v6;
        }
        ++v10;
      }
      while ( v10 < params->Size.Height + 1 );
    }
    v17 = 1;
  }
  else
  {
LABEL_18:
    v17 = 0;
  }
  if ( paramsa.ZlibFile.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)paramsa.ZlibFile.pObject);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.FinalScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.ScanlineWithAlpha2);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.ScanlineWithAlpha1);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.ScanlineWithAlpha0);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.AlphaScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.SourceScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v19);
  return v17;
}

// File Line: 415
// RVA: 0x91D1B0
__int64 __fastcall Scaleform::GFx::ZlibDecodeRGB16(
        Scaleform::GFx::ZlibDecodeParams *params,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  char *pReadScanline; // rbp
  unsigned int v9; // r14d
  char *v10; // rdi
  unsigned int v11; // esi
  unsigned int v12; // r11d
  __int64 v13; // r10
  unsigned int v14; // eax
  unsigned __int16 v15; // r9
  unsigned __int8 v16; // bl
  Scaleform::Render::ImageScanlineBufferImpl v18; // [rsp+40h] [rbp-18A8h] BYREF
  char tempBuffer[2048]; // [rsp+80h] [rbp-1868h] BYREF
  Scaleform::Render::ImageScanlineBufferImpl v20; // [rsp+880h] [rbp-1068h] BYREF
  char v21[4096]; // [rsp+8C0h] [rbp-1028h] BYREF

  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v18,
    Image_A8,
    2 * params->Size.Width,
    Image_A8,
    tempBuffer,
    0x800ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v20,
    Image_R8G8B8A8,
    params->Size.Width,
    params->Format,
    v21,
    0x1000ui64);
  pReadScanline = v18.pReadScanline;
  v9 = (2 * params->Size.Width + 3) & 0xFFFFFFFC;
  v10 = v20.pReadScanline;
  v11 = 0;
  if ( params->Size.Height )
  {
    while ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))params->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
              params->ZlibFile.pObject,
              pReadScanline,
              v9) == v9 )
    {
      v12 = 0;
      if ( params->Size.Width )
      {
        v13 = 0i64;
        v14 = 2;
        do
        {
          v15 = (unsigned __int8)pReadScanline[v13] | ((unsigned __int8)pReadScanline[(unsigned int)(v13 + 1)] << 8);
          v10[v14 - 2] = (v15 >> 7) & 0xF8;
          v10[v14 - 1] = (v15 >> 2) & 0xF8;
          v10[v14] = 8 * v15;
          v10[v14 + 1] = -1;
          ++v12;
          v13 = (unsigned int)(v13 + 2);
          v14 += 4;
        }
        while ( v12 < params->Size.Width );
      }
      Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        &v20,
        &pdest->pPlanes->pData[v11++ * pdest->pPlanes->Pitch],
        0i64,
        copyScanline,
        arg);
      if ( v11 >= params->Size.Height )
        goto LABEL_9;
    }
    v16 = 0;
  }
  else
  {
LABEL_9:
    v16 = 1;
  }
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v20);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v18);
  return v16;
}

// File Line: 448
// RVA: 0x91D390
__int64 __fastcall Scaleform::GFx::ZlibDecodeRGB24(
        Scaleform::GFx::ZlibDecodeParams *params,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  char *pReadScanline; // rsi
  unsigned int v7; // r12d
  unsigned int v8; // r15d
  unsigned int v9; // ebp
  unsigned int v10; // eax
  char *v11; // rbx
  char v12; // r10
  char v13; // r8
  unsigned __int8 v14; // bl
  Scaleform::Render::ImageScanlineBufferImpl v16; // [rsp+40h] [rbp-1078h] BYREF
  char tempBuffer[4152]; // [rsp+80h] [rbp-1038h] BYREF

  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v16,
    Image_R8G8B8A8,
    params->Size.Width,
    params->Format,
    tempBuffer,
    0x1000ui64);
  pReadScanline = v16.pReadScanline;
  v7 = (4 * params->Size.Width + 3) & 0xFFFFFFFC;
  v8 = 0;
  if ( params->Size.Height )
  {
    while ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))params->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
              params->ZlibFile.pObject,
              pReadScanline,
              v7) == v7 )
    {
      v9 = 0;
      if ( params->Size.Width )
      {
        v10 = 2;
        do
        {
          v11 = &pReadScanline[v10];
          v12 = *v11;
          v13 = pReadScanline[v10 + 1];
          pReadScanline[v10 - 2] = pReadScanline[v10 - 1];
          pReadScanline[v10 - 1] = v12;
          *v11 = v13;
          pReadScanline[v10 + 1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < params->Size.Width );
      }
      Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        &v16,
        &pdest->pPlanes->pData[v8++ * pdest->pPlanes->Pitch],
        0i64,
        copyScanline,
        arg);
      if ( v8 >= params->Size.Height )
        goto LABEL_9;
    }
    v14 = 0;
  }
  else
  {
LABEL_9:
    v14 = 1;
  }
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v16);
  return v14;
}

// File Line: 481
// RVA: 0x91D500
__int64 __fastcall Scaleform::GFx::ZlibDecodeRGBA(
        Scaleform::GFx::ZlibDecodeParams *params,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  void *scanlineArg; // rbx
  void (__fastcall *v5)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rdi
  Scaleform::Render::ImageData *v6; // r14
  int v8; // r12d
  unsigned int v9; // r13d
  char *pReadScanline; // rcx
  unsigned int v11; // ebx
  char *v12; // r14
  unsigned int v13; // r15d
  unsigned int v14; // edi
  char v15; // bl
  char v16; // dl
  char v17; // al
  Scaleform::Render::ImageScanlineBuffer<2048> *v18; // rcx
  unsigned __int8 v19; // bl
  Scaleform::GFx::Params paramsa; // [rsp+40h] [rbp-C0h] BYREF
  int v22; // [rsp+3640h] [rbp+3540h]

  scanlineArg = arg;
  v5 = copyScanline;
  v6 = pdest;
  Scaleform::GFx::`anonymous namespace::Params::Params(&paramsa, 0i64, params->Size.Width, params->Format);
  v8 = 1;
  v22 = 0;
  v9 = 0;
  if ( params->Size.Height != -1 )
  {
    do
    {
      pReadScanline = paramsa.ScanlineWithAlphas[v8]->pReadScanline;
      *(_DWORD *)pReadScanline = 0;
      *(_DWORD *)&pReadScanline[4 * (params->Size.Width + 1)] = 0;
      if ( v9 >= params->Size.Height )
      {
        memset(pReadScanline, 0, paramsa.ScanlineWithAlphas[v8]->ReadScanlineSize);
      }
      else
      {
        v11 = 4 * params->Size.Width;
        v12 = pReadScanline + 4;
        if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))params->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
               params->ZlibFile.pObject,
               pReadScanline + 4,
               v11) != v11 )
        {
          v19 = 0;
          goto LABEL_19;
        }
        v13 = 0;
        if ( params->Size.Width )
        {
          v14 = 2;
          do
          {
            v15 = v12[v14 - 2];
            v16 = v12[v14];
            v17 = v12[v14 + 1];
            v12[v14 - 2] = v12[v14 - 1];
            v12[v14 - 1] = v16;
            v12[v14] = v17;
            v12[v14 + 1] = v15;
            ++v13;
            v14 += 4;
          }
          while ( v13 < params->Size.Width );
          v5 = copyScanline;
        }
        v6 = pdest;
        scanlineArg = arg;
      }
      if ( (unsigned int)++v22 >= 2 )
      {
        Scaleform::GFx::UndoPremultiplyAlphaScanline(&paramsa);
        Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
          &paramsa.FinalScanline,
          &v6->pPlanes->pData[v6->pPlanes->Pitch * (v9 - 1)],
          0i64,
          v5,
          scanlineArg);
      }
      if ( v8 == 2 )
      {
        v18 = paramsa.ScanlineWithAlphas[2];
        paramsa.ScanlineWithAlphas[2] = paramsa.ScanlineWithAlphas[0];
        paramsa.ScanlineWithAlphas[0] = paramsa.ScanlineWithAlphas[1];
        paramsa.ScanlineWithAlphas[1] = v18;
      }
      else
      {
        ++v8;
      }
      ++v9;
    }
    while ( v9 < params->Size.Height + 1 );
  }
  v19 = 1;
LABEL_19:
  if ( paramsa.ZlibFile.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)paramsa.ZlibFile.pObject);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.FinalScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.ScanlineWithAlpha2);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.ScanlineWithAlpha1);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.ScanlineWithAlpha0);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.AlphaScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&paramsa.SourceScanline);
  return v19;
}

// File Line: 569
// RVA: 0x8C47F0
_BOOL8 __fastcall Scaleform::GFx::ZlibImageSource::Decode(
        Scaleform::GFx::ZlibImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  unsigned int Height; // r8d
  Scaleform::File *v9; // r15
  bool v10; // bl
  bool v11; // al
  Scaleform::GFx::ZlibDecodeParams params; // [rsp+28h] [rbp-40h] BYREF

  params.ZlibFile.pObject = 0i64;
  params.Format = this->Format;
  params.SrcFormat = this->BitmapFormatId;
  Height = this->Size.Height;
  params.Size.Width = this->Size.Width;
  params.Size.Height = Height;
  v9 = (Scaleform::File *)this->Zlib.pObject->vfptr[1].__vecDelDtor(this->Zlib.pObject, this->pFile.pObject);
  params.ZlibFile.pObject = v9;
  params.ColorTableSize = this->ColorTableSize;
  if ( params.SrcFormat )
  {
    switch ( params.SrcFormat )
    {
      case RGB16:
        v11 = Scaleform::GFx::ZlibDecodeRGB16(&params, pdest, copyScanline, arg);
        break;
      case RGB24:
        v11 = Scaleform::GFx::ZlibDecodeRGB24(&params, pdest, copyScanline, arg);
        break;
      case ColorMappedRGBA:
        v11 = Scaleform::GFx::ZlibDecodeColorMappedAlpha(&params, pdest, copyScanline, arg);
        break;
      case RGBA:
        v11 = Scaleform::GFx::ZlibDecodeRGBA(&params, pdest, copyScanline, arg);
        break;
      default:
        v10 = 0;
        goto LABEL_13;
    }
  }
  else
  {
    v11 = Scaleform::GFx::ZlibDecodeColorMapped(&params, pdest, copyScanline, arg);
  }
  v10 = v11;
LABEL_13:
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
  return v10;
}

// File Line: 580
// RVA: 0x8BF140
Scaleform::Render::RawImage *__fastcall Scaleform::GFx::ZlibImageSource::CreateCompatibleImage(
        Scaleform::GFx::ZlibImageSource *this,
        Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::MemoryHeap *pHeap; // rcx
  Scaleform::GFx::MemoryBufferZlibImage *v5; // rbp
  Scaleform::File *file; // r12
  Scaleform::Render::ImageUpdateSync *sync; // rsi
  Scaleform::GFx::Resource *pObject; // rdi
  Scaleform::Render::Size<unsigned long> *v9; // rbx
  Scaleform::Render::ImageFormat v10; // eax
  __int64 v11; // rax
  char v14; // [rsp+C8h] [rbp+20h] BYREF

  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::ZlibImageSource *))this->vfptr[11].__vecDelDtor)(this) )
    return Scaleform::Render::ImageSource::CreateCompatibleImage(this, args);
  pHeap = Scaleform::Memory::pGlobalHeap;
  if ( args->pHeap )
    pHeap = args->pHeap;
  v5 = (Scaleform::GFx::MemoryBufferZlibImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pHeap->vfptr->Alloc)(
                                                  pHeap,
                                                  104i64);
  if ( !v5 )
    return 0i64;
  file = this->pFile.pObject;
  sync = args->pUpdateSync;
  if ( !sync )
  {
    sync = (Scaleform::Render::ImageUpdateSync *)args->pManager;
    if ( sync )
      sync += 2;
  }
  pObject = (Scaleform::GFx::Resource *)this->Zlib.pObject;
  v9 = (Scaleform::Render::Size<unsigned long> *)this->vfptr[5].__vecDelDtor(this, &v14);
  v10 = ((unsigned int (__fastcall *)(Scaleform::GFx::ZlibImageSource *))this->vfptr[4].__vecDelDtor)(this);
  Scaleform::GFx::MemoryBufferZlibImage::MemoryBufferZlibImage(
    v5,
    pObject,
    v10,
    v9,
    this->BitmapFormatId,
    this->ColorTableSize,
    args->Use,
    sync,
    file,
    this->FilePos,
    this->FileLen);
  return (Scaleform::Render::RawImage *)v11;
}

// File Line: 593
// RVA: 0x8C4600
_BOOL8 __fastcall Scaleform::GFx::MemoryBufferZlibImage::Decode(
        Scaleform::GFx::MemoryBufferZlibImage *this,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::GFx::ZlibImageSource::SourceBitmapDataFormat BitmapFormatId; // edi
  unsigned int Height; // ecx
  unsigned __int64 Size; // r12
  char *Data; // rbx
  bool v12; // al
  Scaleform::File *v13; // r12
  __int32 v14; // edi
  __int32 v15; // edi
  __int32 v16; // edi
  bool v17; // bl
  bool v18; // al
  Scaleform::GFx::ZlibDecodeParams params; // [rsp+28h] [rbp-58h] BYREF
  Scaleform::RefCountImplCore v21; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::String v22; // [rsp+58h] [rbp-28h] BYREF
  char *v23; // [rsp+60h] [rbp-20h]
  int v24; // [rsp+68h] [rbp-18h]
  int v25; // [rsp+6Ch] [rbp-14h]
  bool v26; // [rsp+70h] [rbp-10h]

  params.ZlibFile.pObject = 0i64;
  params.Format = this->Format;
  BitmapFormatId = this->BitmapFormatId;
  params.SrcFormat = BitmapFormatId;
  Height = this->Size.Height;
  params.Size.Width = this->Size.Width;
  params.Size.Height = Height;
  Size = this->FileData.Data.Size;
  Data = this->FileData.Data.Data;
  v21.RefCount = 1;
  v21.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::MemoryFile::`vftable;
  Scaleform::String::String(&v22, &customCaption);
  v23 = Data;
  v24 = Size;
  v25 = 0;
  v12 = Data && (int)Size > 0;
  v26 = v12;
  v13 = (Scaleform::File *)this->Zlib.pObject->vfptr[1].__vecDelDtor(this->Zlib.pObject, &v21);
  params.ZlibFile.pObject = v13;
  params.ColorTableSize = this->ColorTableSize;
  if ( BitmapFormatId )
  {
    v14 = BitmapFormatId - 1;
    if ( v14 )
    {
      v15 = v14 - 1;
      if ( v15 )
      {
        v16 = v15 - 1;
        if ( v16 )
        {
          if ( v16 != 1 )
          {
            v17 = 0;
            goto LABEL_17;
          }
          v18 = Scaleform::GFx::ZlibDecodeRGBA(&params, pdest, copyScanline, arg);
        }
        else
        {
          v18 = Scaleform::GFx::ZlibDecodeColorMappedAlpha(&params, pdest, copyScanline, arg);
        }
      }
      else
      {
        v18 = Scaleform::GFx::ZlibDecodeRGB24(&params, pdest, copyScanline, arg);
      }
    }
    else
    {
      v18 = Scaleform::GFx::ZlibDecodeRGB16(&params, pdest, copyScanline, arg);
    }
  }
  else
  {
    v18 = Scaleform::GFx::ZlibDecodeColorMapped(&params, pdest, copyScanline, arg);
  }
  v17 = v18;
LABEL_17:
  if ( v13 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v13);
  params.ZlibFile.pObject = 0i64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::RefCountImplCore::~RefCountImplCore(&v21);
  return v17;
}

