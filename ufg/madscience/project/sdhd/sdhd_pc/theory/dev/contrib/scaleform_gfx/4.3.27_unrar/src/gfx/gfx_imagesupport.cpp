// File Line: 108
// RVA: 0x89C1A0
void __fastcall Scaleform::GFx::`anonymous namespace'::Params::Params(Scaleform::GFx::Params *this, void **jin, unsigned int width, Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::ImageFormat v4; // er14
  unsigned int v5; // er13
  void **v6; // r15
  Scaleform::GFx::Params *v7; // r12

  v4 = format;
  v5 = width;
  v6 = jin;
  v7 = this;
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    (Scaleform::Render::ImageScanlineBufferImpl *)&this->SourceScanline.ReadFormat,
    Image_R8G8B8,
    width,
    Image_R8G8B8,
    this->SourceScanline.TempBuffer,
    0x800ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    (Scaleform::Render::ImageScanlineBufferImpl *)&v7->AlphaScanline.ReadFormat,
    Image_A8,
    v5,
    Image_A8,
    v7->AlphaScanline.TempBuffer,
    0x400ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    (Scaleform::Render::ImageScanlineBufferImpl *)&v7->ScanlineWithAlpha0.ReadFormat,
    Image_R8G8B8A8,
    v5 + 2,
    Image_R8G8B8A8,
    v7->ScanlineWithAlpha0.TempBuffer,
    0x800ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    (Scaleform::Render::ImageScanlineBufferImpl *)&v7->ScanlineWithAlpha1.ReadFormat,
    Image_R8G8B8A8,
    v5 + 2,
    Image_R8G8B8A8,
    v7->ScanlineWithAlpha1.TempBuffer,
    0x800ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    (Scaleform::Render::ImageScanlineBufferImpl *)&v7->ScanlineWithAlpha2.ReadFormat,
    Image_R8G8B8A8,
    v5 + 2,
    Image_R8G8B8A8,
    v7->ScanlineWithAlpha2.TempBuffer,
    0x800ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    (Scaleform::Render::ImageScanlineBufferImpl *)&v7->FinalScanline.ReadFormat,
    Image_R8G8B8A8,
    v5,
    v4,
    v7->FinalScanline.TempBuffer,
    0x1000ui64);
  v7->ZlibFile.pObject = 0i64;
  v7->Jin = v6;
  v7->Width = v5;
  v7->Success = 1;
  v7->ScanlineWithAlphas[0] = &v7->ScanlineWithAlpha0;
  v7->ScanlineWithAlphas[1] = &v7->ScanlineWithAlpha1;
  v7->ScanlineWithAlphas[2] = &v7->ScanlineWithAlpha2;
  memset(v7->ScanlineWithAlpha0.pReadScanline, 0, v7->ScanlineWithAlpha0.ReadScanlineSize);
}

// File Line: 117
// RVA: 0x914B60
void __fastcall Scaleform::GFx::UndoPremultiplyAlphaScanline(Scaleform::GFx::Params *params)
{
  char *v1; // rbp
  char *v2; // r15
  Scaleform::GFx::Params *v3; // rsi
  char *v4; // r14
  char *v5; // r12
  unsigned int v6; // ebx
  int v7; // edi
  unsigned __int8 v8; // r8
  unsigned int v9; // ecx
  unsigned int v10; // er10
  unsigned int v11; // er9
  unsigned int v12; // eax
  char v13; // dl
  char v14; // cl
  char v15; // dl
  char v16; // dl
  unsigned __int8 v17; // cl
  unsigned __int16 v18; // dx
  __int16 v19; // ax
  unsigned __int8 v20; // cl
  __int16 v21; // ax
  unsigned __int8 v22; // cl

  v1 = params->FinalScanline.pReadScanline;
  v2 = params->ScanlineWithAlphas[0]->pReadScanline;
  v3 = params;
  v4 = params->ScanlineWithAlphas[1]->pReadScanline;
  v5 = params->ScanlineWithAlphas[2]->pReadScanline;
  memmove(params->FinalScanline.pReadScanline, v4 + 4, params->FinalScanline.ReadScanlineSize);
  v6 = 0;
  if ( v3->Width )
  {
    v7 = 0;
    do
    {
      v8 = v1[v7 + 3];
      if ( v8 >= 0x10u )
      {
        v17 = v1[v7 + 3];
        v18 = GFx_UndoPremultiplyTable[v8];
        if ( (unsigned __int8)v1[v7] <= v8 )
          v17 = v1[v7];
        v19 = v17;
        v20 = v1[v7 + 3];
        v1[v7] = (unsigned __int16)(v18 * v19) >> 8;
        if ( (unsigned __int8)v1[v7 + 1] <= v8 )
          v20 = v1[v7 + 1];
        v21 = v20;
        v22 = v8;
        v1[v7 + 1] = (unsigned __int16)(v18 * v21) >> 8;
        if ( (unsigned __int8)v1[v7 + 2] <= v8 )
          v22 = v1[v7 + 2];
        v1[v7 + 2] = (unsigned __int16)(v18 * v22) >> 8;
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
               + ((unsigned int)(unsigned __int8)v5[v7 + 8] << 8))
              / v9;
          v11 = (((unsigned __int8)v4[v7 + 5] << 8)
               + ((unsigned __int8)v2[v7 + 5] << 8)
               + ((unsigned __int8)v5[v7 + 5] << 8)
               + ((unsigned __int8)v2[v7 + 1] << 8)
               + ((unsigned __int8)v4[v7 + 1] << 8)
               + ((unsigned __int8)v4[v7 + 9] << 8)
               + ((unsigned __int8)v5[v7 + 1] << 8)
               + ((unsigned __int8)v5[v7 + 9] << 8)
               + ((unsigned int)(unsigned __int8)v2[v7 + 9] << 8))
              / v9;
          v12 = (((unsigned __int8)v4[v7 + 6] << 8)
               + ((unsigned __int8)v2[v7 + 6] << 8)
               + ((unsigned __int8)v5[v7 + 6] << 8)
               + ((unsigned __int8)v2[v7 + 2] << 8)
               + ((unsigned __int8)v2[v7 + 10] << 8)
               + ((unsigned __int8)v4[v7 + 2] << 8)
               + ((unsigned __int8)v4[v7 + 10] << 8)
               + ((unsigned __int8)v5[v7 + 2] << 8)
               + ((unsigned int)(unsigned __int8)v5[v7 + 10] << 8))
              / v9;
          v13 = -1;
          v14 = v10;
          if ( v10 <= 0xFF )
            v13 = v14;
          v1[v7] = v13;
          v15 = -1;
          if ( v11 <= 0xFF )
            v15 = v11;
          v1[v7 + 1] = v15;
          v16 = -1;
          if ( v12 <= 0xFF )
            v16 = v12;
          v1[v7 + 2] = v16;
        }
      }
      ++v6;
      v7 += 4;
    }
    while ( v6 < v3->Width );
  }
}

// File Line: 319
// RVA: 0x91CC80
__int64 __fastcall Scaleform::GFx::ZlibDecodeColorMapped(Scaleform::GFx::ZlibDecodeParams *params, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  void *v4; // r12
  void (__fastcall *v5)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // r13
  Scaleform::GFx::ZlibDecodeParams *v6; // rdi
  int v7; // ebx
  unsigned int v8; // er15
  char *v9; // rsi
  char *v10; // rbx
  char *v11; // r14
  unsigned int v12; // ebp
  __int64 v13; // r9
  unsigned int v14; // eax
  char *v15; // r8
  unsigned __int8 v16; // bl
  Scaleform::Render::ImageScanlineBufferImpl v18; // [rsp+40h] [rbp-FE8h]
  char tempBuffer; // [rsp+80h] [rbp-FA8h]
  Scaleform::Render::ImageScanlineBufferImpl v20; // [rsp+380h] [rbp-CA8h]
  char v21; // [rsp+3C0h] [rbp-C68h]
  Scaleform::Render::ImageScanlineBufferImpl v22; // [rsp+7C0h] [rbp-868h]
  char v23; // [rsp+800h] [rbp-828h]
  Scaleform::Render::ImageData *v24; // [rsp+1038h] [rbp+10h]

  v24 = pdest;
  v4 = arg;
  v5 = copyScanline;
  v6 = params;
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v18,
    Image_R8G8B8,
    params->ColorTableSize,
    Image_R8G8B8,
    &tempBuffer,
    0x300ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v20,
    Image_A8,
    v6->Size.Width,
    Image_A8,
    &v21,
    0x400ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v22,
    Image_R8G8B8,
    v6->Size.Width,
    v6->Format,
    &v23,
    0x800ui64);
  v7 = 3 * v6->ColorTableSize;
  v8 = (v6->Size.Width + 3) & 0xFFFFFFFC;
  if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v6->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
         v6->ZlibFile.pObject,
         v18.pReadScanline,
         3 * v6->ColorTableSize) != v7 )
  {
LABEL_9:
    v16 = 0;
    goto LABEL_10;
  }
  v9 = v20.pReadScanline;
  v10 = v22.pReadScanline;
  v11 = v18.pReadScanline;
  v12 = 0;
  if ( v6->Size.Height )
  {
    while ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v6->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
              v6->ZlibFile.pObject,
              v9,
              v8) == v8 )
    {
      v13 = 0i64;
      if ( v6->Size.Width )
      {
        v14 = 2;
        do
        {
          v15 = &v11[2 * (unsigned __int8)v9[v13] + (unsigned __int8)v9[v13]];
          v10[v14 - 2] = *v15;
          v10[v14 - 1] = v15[1];
          v10[v14] = v15[2];
          v13 = (unsigned int)(v13 + 1);
          v14 += 3;
        }
        while ( (unsigned int)v13 < v6->Size.Width );
      }
      Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        &v22,
        &v24->pPlanes->pData[v12++ * v24->pPlanes->Pitch],
        0i64,
        v5,
        v4);
      if ( v12 >= v6->Size.Height )
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
__int64 __fastcall Scaleform::GFx::ZlibDecodeColorMappedAlpha(Scaleform::GFx::ZlibDecodeParams *params, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  void *v4; // r14
  Scaleform::GFx::ZlibDecodeParams *v5; // rdi
  signed int v6; // er15
  int v7; // er12
  char *v8; // r13
  unsigned int v9; // ebx
  unsigned int v10; // esi
  char *v11; // rbx
  char *v12; // r14
  __int64 v13; // r9
  unsigned int v14; // eax
  char *v15; // r8
  Scaleform::Render::ImageScanlineBuffer<2048> *v16; // rcx
  unsigned __int8 v17; // bl
  Scaleform::Render::ImageScanlineBufferImpl v19; // [rsp+40h] [rbp-C0h]
  char tempBuffer; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::Params paramsa; // [rsp+480h] [rbp+380h]
  unsigned int v22; // [rsp+3A80h] [rbp+3980h]
  Scaleform::Render::ImageData *v23; // [rsp+3A88h] [rbp+3988h]
  void (__fastcall *copyScanlinea)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // [rsp+3A90h] [rbp+3990h]
  void *v25; // [rsp+3A98h] [rbp+3998h]

  v25 = arg;
  copyScanlinea = copyScanline;
  v23 = pdest;
  v4 = arg;
  v5 = params;
  v6 = 1;
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v19,
    Image_R8G8B8A8,
    params->ColorTableSize,
    Image_R8G8B8A8,
    &tempBuffer,
    0x400ui64);
  Scaleform::GFx::`anonymous namespace'::Params::Params(&paramsa, 0i64, v5->Size.Width, v5->Format);
  v7 = 0;
  v8 = v19.pReadScanline;
  v9 = 4 * v5->ColorTableSize;
  v22 = (v5->Size.Width + 3) & 0xFFFFFFFC;
  if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v5->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
         v5->ZlibFile.pObject,
         v19.pReadScanline,
         v9) == v9 )
  {
    v10 = 0;
    if ( v5->Size.Height != -1 )
    {
      do
      {
        v11 = paramsa.ScanlineWithAlphas[v6]->pReadScanline;
        *(_DWORD *)v11 = 0;
        *(_DWORD *)&v11[4 * (v5->Size.Width + 1)] = 0;
        if ( v10 >= v5->Size.Height )
        {
          memset(v11, 0, paramsa.ScanlineWithAlphas[v6]->ReadScanlineSize);
        }
        else
        {
          v12 = paramsa.AlphaScanline.pReadScanline;
          if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v5->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
                 v5->ZlibFile.pObject,
                 paramsa.AlphaScanline.pReadScanline,
                 v22) != v22 )
            goto LABEL_18;
          v13 = 0i64;
          if ( v5->Size.Width )
          {
            v14 = 2;
            do
            {
              v15 = &v8[4 * (unsigned __int8)v12[v13]];
              v11[v14 + 2] = *v15;
              v11[v14 + 3] = v15[1];
              v11[v14 + 4] = v15[2];
              v11[v14 + 5] = v15[3];
              v13 = (unsigned int)(v13 + 1);
              v14 += 4;
            }
            while ( (unsigned int)v13 < v5->Size.Width );
          }
          v4 = v25;
        }
        if ( (unsigned int)++v7 >= 2 )
        {
          Scaleform::GFx::UndoPremultiplyAlphaScanline(&paramsa);
          Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
            (Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.FinalScanline.ReadFormat,
            &v23->pPlanes->pData[v23->pPlanes->Pitch * (v10 - 1)],
            0i64,
            copyScanlinea,
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
      while ( v10 < v5->Size.Height + 1 );
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
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.FinalScanline.ReadFormat);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.ScanlineWithAlpha2.ReadFormat);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.ScanlineWithAlpha1.ReadFormat);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.ScanlineWithAlpha0.ReadFormat);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.AlphaScanline.ReadFormat);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.SourceScanline.ReadFormat);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v19);
  return v17;
}

// File Line: 415
// RVA: 0x91D1B0
__int64 __fastcall Scaleform::GFx::ZlibDecodeRGB16(Scaleform::GFx::ZlibDecodeParams *params, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  void *v4; // r15
  void (__fastcall *v5)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // r12
  Scaleform::Render::ImageData *v6; // r13
  Scaleform::GFx::ZlibDecodeParams *v7; // rbx
  char *v8; // rbp
  unsigned int v9; // er14
  char *v10; // rdi
  unsigned int v11; // esi
  unsigned int v12; // er11
  __int64 v13; // r10
  unsigned int v14; // eax
  unsigned __int16 v15; // r9
  unsigned __int8 v16; // bl
  Scaleform::Render::ImageScanlineBufferImpl v18; // [rsp+40h] [rbp-18A8h]
  char tempBuffer; // [rsp+80h] [rbp-1868h]
  Scaleform::Render::ImageScanlineBufferImpl v20; // [rsp+880h] [rbp-1068h]
  char v21; // [rsp+8C0h] [rbp-1028h]

  v4 = arg;
  v5 = copyScanline;
  v6 = pdest;
  v7 = params;
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v18,
    Image_A8,
    2 * params->Size.Width,
    Image_A8,
    &tempBuffer,
    0x800ui64);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v20,
    Image_R8G8B8A8,
    v7->Size.Width,
    v7->Format,
    &v21,
    0x1000ui64);
  v8 = v18.pReadScanline;
  v9 = (2 * v7->Size.Width + 3) & 0xFFFFFFFC;
  v10 = v20.pReadScanline;
  v11 = 0;
  if ( v7->Size.Height )
  {
    while ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v7->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
              v7->ZlibFile.pObject,
              v8,
              v9) == v9 )
    {
      v12 = 0;
      if ( v7->Size.Width )
      {
        v13 = 0i64;
        v14 = 2;
        do
        {
          v15 = (unsigned __int8)v8[v13] | (unsigned __int16)((unsigned __int8)v8[(unsigned int)(v13 + 1)] << 8);
          v10[v14 - 2] = (v15 >> 7) & 0xF8;
          v10[v14 - 1] = (v15 >> 2) & 0xF8;
          v10[v14] = 8 * v15;
          v10[v14 + 1] = -1;
          ++v12;
          v13 = (unsigned int)(v13 + 2);
          v14 += 4;
        }
        while ( v12 < v7->Size.Width );
      }
      Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        &v20,
        &v6->pPlanes->pData[v11++ * v6->pPlanes->Pitch],
        0i64,
        v5,
        v4);
      if ( v11 >= v7->Size.Height )
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
__int64 __fastcall Scaleform::GFx::ZlibDecodeRGB24(Scaleform::GFx::ZlibDecodeParams *params, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  void *v4; // r13
  Scaleform::GFx::ZlibDecodeParams *v5; // r14
  char *v6; // rsi
  unsigned int v7; // er12
  unsigned int v8; // er15
  unsigned int v9; // ebp
  unsigned int v10; // eax
  char *v11; // rbx
  char v12; // r10
  char v13; // r8
  unsigned __int8 v14; // bl
  Scaleform::Render::ImageScanlineBufferImpl v16; // [rsp+40h] [rbp-1078h]
  char tempBuffer; // [rsp+80h] [rbp-1038h]
  Scaleform::Render::ImageData *v18; // [rsp+10C8h] [rbp+10h]
  void (__fastcall *copyScanlinea)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // [rsp+10D0h] [rbp+18h]

  copyScanlinea = copyScanline;
  v18 = pdest;
  v4 = arg;
  v5 = params;
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v16,
    Image_R8G8B8A8,
    params->Size.Width,
    params->Format,
    &tempBuffer,
    0x1000ui64);
  v6 = v16.pReadScanline;
  v7 = (4 * v5->Size.Width + 3) & 0xFFFFFFFC;
  v8 = 0;
  if ( v5->Size.Height )
  {
    while ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v5->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
              v5->ZlibFile.pObject,
              v6,
              v7) == v7 )
    {
      v9 = 0;
      if ( v5->Size.Width )
      {
        v10 = 2;
        do
        {
          v11 = &v6[v10];
          v12 = *v11;
          v13 = v6[v10 + 1];
          v6[v10 - 2] = v6[v10 - 1];
          v6[v10 - 1] = v12;
          *v11 = v13;
          v6[v10 + 1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < v5->Size.Width );
      }
      Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        &v16,
        &v18->pPlanes->pData[v8++ * v18->pPlanes->Pitch],
        0i64,
        copyScanlinea,
        v4);
      if ( v8 >= v5->Size.Height )
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
__int64 __fastcall Scaleform::GFx::ZlibDecodeRGBA(Scaleform::GFx::ZlibDecodeParams *params, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  void *scanlineArg; // rbx
  void (__fastcall *v5)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rdi
  Scaleform::Render::ImageData *v6; // r14
  Scaleform::GFx::ZlibDecodeParams *v7; // rsi
  signed int v8; // er12
  unsigned int v9; // er13
  char *v10; // rcx
  unsigned int v11; // ebx
  signed __int64 v12; // r14
  unsigned int v13; // er15
  unsigned int v14; // edi
  char v15; // bl
  char v16; // dl
  char v17; // al
  Scaleform::Render::ImageScanlineBuffer<2048> *v18; // rcx
  unsigned __int8 v19; // bl
  Scaleform::GFx::Params paramsa; // [rsp+40h] [rbp-C0h]
  int v22; // [rsp+3640h] [rbp+3540h]
  Scaleform::Render::ImageData *v23; // [rsp+3648h] [rbp+3548h]
  void (__fastcall *v24)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // [rsp+3650h] [rbp+3550h]
  void *v25; // [rsp+3658h] [rbp+3558h]

  v25 = arg;
  v24 = copyScanline;
  v23 = pdest;
  scanlineArg = arg;
  v5 = copyScanline;
  v6 = pdest;
  v7 = params;
  Scaleform::GFx::`anonymous namespace'::Params::Params(&paramsa, 0i64, params->Size.Width, params->Format);
  v8 = 1;
  v22 = 0;
  v9 = 0;
  if ( v7->Size.Height != -1 )
  {
    do
    {
      v10 = paramsa.ScanlineWithAlphas[v8]->pReadScanline;
      *(_DWORD *)v10 = 0;
      *(_DWORD *)&v10[4 * (v7->Size.Width + 1)] = 0;
      if ( v9 >= v7->Size.Height )
      {
        memset(v10, 0, paramsa.ScanlineWithAlphas[v8]->ReadScanlineSize);
      }
      else
      {
        v11 = 4 * v7->Size.Width;
        v12 = (signed __int64)(v10 + 4);
        if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v7->ZlibFile.pObject->vfptr[10].__vecDelDtor)(
               v7->ZlibFile.pObject,
               v10 + 4,
               v11) != v11 )
        {
          v19 = 0;
          goto LABEL_19;
        }
        v13 = 0;
        if ( v7->Size.Width )
        {
          v14 = 2;
          do
          {
            v15 = *(_BYTE *)(v14 - 2 + v12);
            v16 = *(_BYTE *)(v14 + v12);
            v17 = *(_BYTE *)(v14 + 1 + v12);
            *(_BYTE *)(v14 - 2 + v12) = *(_BYTE *)(v14 - 1 + v12);
            *(_BYTE *)(v14 - 1 + v12) = v16;
            *(_BYTE *)(v14 + v12) = v17;
            *(_BYTE *)(v14 + 1 + v12) = v15;
            ++v13;
            v14 += 4;
          }
          while ( v13 < v7->Size.Width );
          v5 = v24;
        }
        v6 = v23;
        scanlineArg = v25;
      }
      if ( (unsigned int)++v22 >= 2 )
      {
        Scaleform::GFx::UndoPremultiplyAlphaScanline(&paramsa);
        Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
          (Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.FinalScanline.ReadFormat,
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
    while ( v9 < v7->Size.Height + 1 );
  }
  v19 = 1;
LABEL_19:
  if ( paramsa.ZlibFile.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)paramsa.ZlibFile.pObject);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.FinalScanline.ReadFormat);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.ScanlineWithAlpha2.ReadFormat);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.ScanlineWithAlpha1.ReadFormat);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.ScanlineWithAlpha0.ReadFormat);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.AlphaScanline.ReadFormat);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl((Scaleform::Render::ImageScanlineBufferImpl *)&paramsa.SourceScanline.ReadFormat);
  return v19;
}

// File Line: 569
// RVA: 0x8C47F0
_BOOL8 __fastcall Scaleform::GFx::ZlibImageSource::Decode(Scaleform::GFx::ZlibImageSource *this, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  void *v4; // rsi
  void (__fastcall *v5)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rbp
  Scaleform::Render::ImageData *v6; // r14
  Scaleform::GFx::ZlibImageSource *v7; // rbx
  unsigned int v8; // er8
  Scaleform::File *v9; // r15
  bool v10; // bl
  bool v11; // al
  Scaleform::GFx::ZlibDecodeParams params; // [rsp+28h] [rbp-40h]

  v4 = arg;
  v5 = copyScanline;
  v6 = pdest;
  v7 = this;
  params.ZlibFile.pObject = 0i64;
  params.Format = this->Format;
  params.SrcFormat = this->BitmapFormatId;
  v8 = this->Size.Height;
  params.Size.Width = this->Size.Width;
  params.Size.Height = v8;
  v9 = (Scaleform::File *)this->Zlib.pObject->vfptr[1].__vecDelDtor(
                            (Scaleform::RefCountImplCore *)this->Zlib.pObject,
                            (unsigned int)this->pFile.pObject);
  params.ZlibFile.pObject = v9;
  params.ColorTableSize = v7->ColorTableSize;
  if ( params.SrcFormat )
  {
    switch ( params.SrcFormat )
    {
      case 1:
        v11 = Scaleform::GFx::ZlibDecodeRGB16(&params, v6, v5, v4);
        break;
      case 2:
        v11 = Scaleform::GFx::ZlibDecodeRGB24(&params, v6, v5, v4);
        break;
      case 3:
        v11 = Scaleform::GFx::ZlibDecodeColorMappedAlpha(&params, v6, v5, v4);
        break;
      case 4:
        v11 = Scaleform::GFx::ZlibDecodeRGBA(&params, v6, v5, v4);
        break;
      default:
        v10 = 0;
        goto LABEL_13;
    }
  }
  else
  {
    v11 = Scaleform::GFx::ZlibDecodeColorMapped(&params, v6, v5, v4);
  }
  v10 = v11;
LABEL_13:
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
  return v10;
}

// File Line: 580
// RVA: 0x8BF140
Scaleform::Render::RawImage *__fastcall Scaleform::GFx::ZlibImageSource::CreateCompatibleImage(Scaleform::GFx::ZlibImageSource *this, Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::ImageCreateArgs *v2; // r15
  Scaleform::GFx::ZlibImageSource *v3; // r14
  Scaleform::MemoryHeap *v4; // rcx
  Scaleform::GFx::MemoryBufferZlibImage *v5; // rbp
  Scaleform::File *file; // r12
  Scaleform::Render::ImageUpdateSync *sync; // rsi
  Scaleform::GFx::ZlibSupportBase *v8; // rdi
  Scaleform::Render::Size<unsigned long> *v9; // rbx
  Scaleform::Render::ImageFormat v10; // eax
  __int64 v11; // rax
  char v14; // [rsp+C8h] [rbp+20h]

  v2 = args;
  v3 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[11].__vecDelDtor)() )
    return Scaleform::Render::ImageSource::CreateCompatibleImage((Scaleform::Render::ImageSource *)&v3->vfptr, v2);
  v4 = Scaleform::Memory::pGlobalHeap;
  if ( v2->pHeap )
    v4 = v2->pHeap;
  v5 = (Scaleform::GFx::MemoryBufferZlibImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                                  v4,
                                                  104i64);
  if ( !v5 )
    return 0i64;
  file = v3->pFile.pObject;
  sync = v2->pUpdateSync;
  if ( !sync )
  {
    sync = (Scaleform::Render::ImageUpdateSync *)v2->pManager;
    if ( sync )
      sync += 2;
  }
  v8 = v3->Zlib.pObject;
  v9 = (Scaleform::Render::Size<unsigned long> *)v3->vfptr[5].__vecDelDtor(
                                                   (Scaleform::RefCountImplCore *)&v3->vfptr,
                                                   (unsigned int)&v14);
  v10 = ((unsigned int (__fastcall *)(Scaleform::GFx::ZlibImageSource *))v3->vfptr[4].__vecDelDtor)(v3);
  Scaleform::GFx::MemoryBufferZlibImage::MemoryBufferZlibImage(
    v5,
    v8,
    v10,
    v9,
    v3->BitmapFormatId,
    v3->ColorTableSize,
    v2->Use,
    sync,
    file,
    v3->FilePos,
    v3->FileLen);
  return (Scaleform::Render::RawImage *)v11;
}

// File Line: 593
// RVA: 0x8C4600
_BOOL8 __fastcall Scaleform::GFx::MemoryBufferZlibImage::Decode(Scaleform::GFx::MemoryBufferZlibImage *this, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  void *v4; // rsi
  void (__fastcall *v5)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // r14
  Scaleform::Render::ImageData *v6; // r15
  Scaleform::GFx::MemoryBufferZlibImage *v7; // r13
  Scaleform::GFx::ZlibImageSource::SourceBitmapDataFormat v8; // edi
  unsigned int v9; // ecx
  unsigned __int64 v10; // r12
  __int64 v11; // rbx
  bool v12; // al
  __int64 v13; // r8
  __int64 v14; // r9
  Scaleform::File *v15; // r12
  int v16; // edi
  int v17; // edi
  int v18; // edi
  bool v19; // bl
  bool v20; // al
  unsigned __int64 v21; // rdx
  Scaleform::GFx::ZlibDecodeParams params; // [rsp+28h] [rbp-58h]
  Scaleform::RefCountImplCore v24; // [rsp+48h] [rbp-38h]
  Scaleform::String v25; // [rsp+58h] [rbp-28h]
  __int64 v26; // [rsp+60h] [rbp-20h]
  int v27; // [rsp+68h] [rbp-18h]
  int v28; // [rsp+6Ch] [rbp-14h]
  bool v29; // [rsp+70h] [rbp-10h]

  v4 = arg;
  v5 = copyScanline;
  v6 = pdest;
  v7 = this;
  params.ZlibFile.pObject = 0i64;
  params.Format = this->Format;
  v8 = this->BitmapFormatId;
  params.SrcFormat = this->BitmapFormatId;
  v9 = this->Size.Height;
  params.Size.Width = v7->Size.Width;
  params.Size.Height = v9;
  v10 = v7->FileData.Data.Size;
  v11 = (__int64)v7->FileData.Data.Data;
  v24.RefCount = 1;
  v24.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::MemoryFile::`vftable';
  Scaleform::String::String(&v25, &customWorldMapCaption);
  v26 = v11;
  v27 = v10;
  v28 = 0;
  v12 = v11 && (signed int)v10 > 0;
  v29 = v12;
  v15 = (Scaleform::File *)v7->Zlib.pObject->vfptr[1].__vecDelDtor(
                             (Scaleform::RefCountImplCore *)&v7->Zlib.pObject->vfptr,
                             (unsigned int)&v24);
  params.ZlibFile.pObject = v15;
  params.ColorTableSize = v7->ColorTableSize;
  if ( v8 )
  {
    v16 = v8 - 1;
    if ( v16 )
    {
      v17 = v16 - 1;
      if ( v17 )
      {
        v18 = v17 - 1;
        if ( v18 )
        {
          if ( v18 != 1 )
          {
            v19 = 0;
            goto LABEL_17;
          }
          v20 = Scaleform::GFx::ZlibDecodeRGBA(&params, v6, v5, v4);
        }
        else
        {
          v20 = Scaleform::GFx::ZlibDecodeColorMappedAlpha(&params, v6, v5, v4);
        }
      }
      else
      {
        v20 = Scaleform::GFx::ZlibDecodeRGB24(&params, v6, v5, v4);
      }
    }
    else
    {
      v20 = Scaleform::GFx::ZlibDecodeRGB16(&params, v6, v5, v4);
    }
  }
  else
  {
    v20 = Scaleform::GFx::ZlibDecodeColorMapped(&params, v6, v5, v4);
  }
  v19 = v20;
LABEL_17:
  if ( v15 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v15);
  params.ZlibFile.pObject = 0i64;
  v21 = v25.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v25.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64, __int64, __int64, signed __int64, _QWORD, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v21,
      v13,
      v14,
      -2i64,
      *(_QWORD *)&params.Format,
      *(_QWORD *)&params.Size);
  Scaleform::RefCountImplCore::~RefCountImplCore(&v24);
  return v19;
}

