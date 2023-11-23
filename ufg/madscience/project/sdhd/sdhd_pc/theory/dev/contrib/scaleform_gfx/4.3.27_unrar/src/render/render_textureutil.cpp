// File Line: 26
// RVA: 0x9874B0
__int64 __fastcall Scaleform::Render::GetImageFormatRescaleType(int format)
{
  if ( format > 0 )
  {
    if ( format <= 2 )
      return 2i64;
    if ( format <= 4 )
      return 1i64;
    if ( format == 9 )
      return 4i64;
  }
  return 0i64;
}

// File Line: 45
// RVA: 0x9AA900
void __fastcall Scaleform::Render::RescaleImageData(
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData *src,
        Scaleform::Render::ResizeImageType resizeType)
{
  int LevelCount; // ecx
  unsigned int v6; // ebx
  __int64 v7; // rsi
  unsigned int RawPlaneCount; // ecx
  Scaleform::Render::ImagePlane *v9; // rcx
  int srcWidth; // r15d
  int srcHeight; // r12d
  char *pData; // r13
  unsigned int v13; // ecx
  Scaleform::Render::ImagePlane *v14; // rcx
  unsigned __int64 Pitch; // rax
  int Width; // edx
  int Height; // r8d
  char *v18; // rcx
  Scaleform::Render::ImagePlane p; // [rsp+50h] [rbp-19h] BYREF
  Scaleform::Render::ImagePlane v20; // [rsp+70h] [rbp+7h] BYREF
  unsigned int v21; // [rsp+D8h] [rbp+6Fh]

  if ( (src->Flags & 1) != 0 )
    LevelCount = (unsigned __int8)src->LevelCount;
  else
    LevelCount = 1;
  v6 = 0;
  v21 = LevelCount * src->RawPlaneCount;
  if ( v21 )
  {
    v7 = 0i64;
    do
    {
      RawPlaneCount = src->RawPlaneCount;
      memset(&p, 0, sizeof(p));
      memset(&v20, 0, sizeof(v20));
      if ( v6 >= RawPlaneCount )
      {
        Scaleform::Render::ImagePlane::GetMipLevel(
          &src->pPlanes[v6 % RawPlaneCount],
          src->Format,
          v6 / RawPlaneCount,
          &p,
          v6 % RawPlaneCount);
        pData = p.pData;
        srcHeight = p.Height;
        srcWidth = p.Width;
      }
      else
      {
        v9 = &src->pPlanes[v7];
        srcWidth = v9->Width;
        srcHeight = v9->Height;
        pData = v9->pData;
        p.Pitch = v9->Pitch;
      }
      v13 = dest->RawPlaneCount;
      if ( v6 >= v13 )
      {
        Scaleform::Render::ImagePlane::GetMipLevel(&dest->pPlanes[v6 % v13], dest->Format, v6 / v13, &v20, v6 % v13);
        v18 = v20.pData;
        Height = v20.Height;
        Width = v20.Width;
      }
      else
      {
        v14 = &dest->pPlanes[v7];
        Pitch = v14->Pitch;
        Width = v14->Width;
        Height = v14->Height;
        v18 = v14->pData;
        v20.Pitch = Pitch;
      }
      Scaleform::Render::ResizeImageBilinear(
        v18,
        Width,
        Height,
        v20.Pitch,
        pData,
        srcWidth,
        srcHeight,
        p.Pitch,
        resizeType);
      ++v6;
      ++v7;
    }
    while ( v6 < v21 );
  }
}

// File Line: 67
// RVA: 0x9634B0
void __fastcall Scaleform::Render::ConvertImagePlane(
        Scaleform::Render::ImagePlane *dplane,
        Scaleform::Render::ImagePlane *splane,
        Scaleform::Render::ImageFormat format,
        unsigned int formatPlaneIndex,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        Scaleform::Render::Palette *pcolorMap,
        void *scanlineArg)
{
  __int16 v9; // bx
  __int64 FormatBitsPerPixel; // rcx
  unsigned __int64 Height; // rbx
  char *pData; // rdi
  char *i; // rsi
  __int64 v14; // [rsp+60h] [rbp+8h]

  v9 = format;
  FormatBitsPerPixel = Scaleform::Render::ImageData::GetFormatBitsPerPixel(format, formatPlaneIndex);
  v14 = FormatBitsPerPixel;
  if ( (v9 & 0xFFFu) - 50 > 3 )
    Height = splane->Height;
  else
    Height = (unsigned __int64)(splane->Height + 3) >> 2;
  pData = splane->pData;
  for ( i = dplane->pData; Height; --Height )
  {
    copyScanline(i, pData, (FormatBitsPerPixel * (unsigned __int64)splane->Width) >> 3, pcolorMap, scanlineArg);
    pData += splane->Pitch;
    i += dplane->Pitch;
    FormatBitsPerPixel = v14;
  }
}

// File Line: 86
// RVA: 0x963240
void __fastcall Scaleform::Render::ConvertImageData(
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData *src,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *scanlineArg)
{
  Scaleform::Render::ImageData *v4; // rbx
  Scaleform::Render::ImageData *v5; // rbp
  int LevelCount; // eax
  __int32 v7; // edi
  unsigned int v8; // ecx
  unsigned int v9; // r14d
  unsigned int v10; // r9d
  unsigned int FormatBitsPerPixel; // eax
  __int64 v12; // rdx
  unsigned int RawPlaneCount; // ecx
  Scaleform::Render::ImagePlane *pPlanes; // rax
  unsigned __int64 Height; // rbx
  unsigned __int64 Pitch; // r13
  char *pData; // rsi
  unsigned int v18; // ecx
  Scaleform::Render::ImagePlane *v19; // rax
  unsigned __int64 v20; // r15
  char *v21; // rdi
  Scaleform::Render::Palette *pObject; // r12
  unsigned __int64 v23; // rbp
  unsigned int v24; // [rsp+30h] [rbp-A8h]
  unsigned int Width; // [rsp+34h] [rbp-A4h]
  __int64 v26; // [rsp+38h] [rbp-A0h]
  unsigned int v27; // [rsp+40h] [rbp-98h]
  unsigned int v28; // [rsp+44h] [rbp-94h]
  Scaleform::Render::ImagePlane p; // [rsp+48h] [rbp-90h] BYREF
  __int64 v30; // [rsp+68h] [rbp-70h]
  Scaleform::Render::ImagePlane v31; // [rsp+70h] [rbp-68h] BYREF

  v4 = src;
  v5 = dest;
  LevelCount = 1;
  v7 = src->Format & 0xFFF;
  if ( v7 )
  {
    if ( (src->Format & 0xFFF) == 200 )
    {
      v8 = 3;
    }
    else if ( (src->Format & 0xFFF) == 201 )
    {
      v8 = 4;
    }
    else
    {
      v8 = 1;
    }
  }
  else
  {
    v8 = 0;
  }
  if ( (src->Flags & 1) != 0 )
    LevelCount = (unsigned __int8)src->LevelCount;
  v9 = 0;
  v24 = 0;
  v10 = LevelCount * src->RawPlaneCount;
  v27 = v10;
  if ( v10 )
  {
    FormatBitsPerPixel = Scaleform::Render::ImageData::GetFormatBitsPerPixel(src->Format, v10 % v8);
    v12 = 0i64;
    v26 = 0i64;
    v30 = FormatBitsPerPixel;
    v28 = v7 - 50;
    do
    {
      RawPlaneCount = v4->RawPlaneCount;
      memset(&p, 0, sizeof(p));
      memset(&v31, 0, sizeof(v31));
      if ( v9 >= RawPlaneCount )
      {
        Scaleform::Render::ImagePlane::GetMipLevel(
          &v4->pPlanes[v9 % RawPlaneCount],
          v4->Format,
          v9 / RawPlaneCount,
          &p,
          v9 % RawPlaneCount);
        pData = p.pData;
        Pitch = p.Pitch;
        Height = p.Height;
        v12 = v26;
        Width = p.Width;
      }
      else
      {
        pPlanes = v4->pPlanes;
        Height = *(unsigned int *)((char *)&pPlanes->Height + v12);
        Pitch = *(unsigned __int64 *)((char *)&pPlanes->Pitch + v12);
        pData = *(char **)((char *)&pPlanes->pData + v12);
        Width = *(unsigned int *)((char *)&pPlanes->Width + v12);
      }
      v18 = v5->RawPlaneCount;
      if ( v9 >= v18 )
      {
        Scaleform::Render::ImagePlane::GetMipLevel(&v5->pPlanes[v9 % v18], v5->Format, v9 / v18, &v31, v9 % v18);
        v21 = v31.pData;
        v20 = v31.Pitch;
        v12 = v26;
      }
      else
      {
        v19 = v5->pPlanes;
        v20 = *(unsigned __int64 *)((char *)&v19->Pitch + v12);
        v21 = *(char **)((char *)&v19->pData + v12);
      }
      pObject = v5->pPalette.pObject;
      if ( v28 <= 3 )
        Height = (unsigned __int64)(unsigned int)(Height + 3) >> 2;
      if ( Height )
      {
        v23 = (v30 * (unsigned __int64)Width) >> 3;
        do
        {
          copyScanline(v21, pData, v23, pObject, scanlineArg);
          pData += Pitch;
          v21 += v20;
          --Height;
        }
        while ( Height );
        v9 = v24;
        v12 = v26;
        v5 = dest;
      }
      v4 = src;
      ++v9;
      v12 += 32i64;
      v24 = v9;
      v26 = v12;
    }
    while ( v9 < v27 );
  }
}

// File Line: 109
// RVA: 0x97F130
void __fastcall Scaleform::Render::GenerateMipLevel(
        Scaleform::Render::ImagePlane *dplane,
        Scaleform::Render::ImagePlane *splane,
        Scaleform::Render::ImageFormat format,
        unsigned int formatPlaneIndex)
{
  unsigned __int64 Pitch; // rsi
  unsigned __int64 v5; // r10
  Scaleform::Render::ImagePlane *v6; // rdi
  unsigned int Height; // ebx
  unsigned int Width; // ecx
  unsigned int v10; // r13d
  unsigned int v11; // r12d
  unsigned int v12; // eax
  unsigned int v13; // edx
  signed __int32 v14; // r8d
  unsigned int v15; // r9d
  char *v16; // r14
  unsigned __int64 v17; // r12
  int v18; // edi
  int v19; // edx
  unsigned int v20; // ebx
  unsigned int v21; // r11d
  int v22; // r10d
  unsigned __int8 *v23; // rdx
  unsigned int v24; // eax
  int v25; // ebp
  int v26; // edi
  int v27; // r11d
  unsigned __int8 *v28; // r10
  unsigned int v29; // ebx
  unsigned int v30; // r9d
  int v31; // eax
  unsigned int v32; // r8d
  int v33; // ecx
  int v34; // edx
  int v35; // ecx
  char *v36; // rdi
  char *v37; // r14
  signed __int32 v38; // r8d
  unsigned int v39; // ebp
  unsigned int v40; // r9d
  unsigned __int64 v41; // rcx
  int v42; // r8d
  unsigned int v43; // ebp
  unsigned int v44; // esi
  int v45; // ebx
  __int64 v46; // r8
  unsigned __int8 *v47; // r8
  int v48; // ecx
  unsigned int v49; // r9d
  int v50; // eax
  unsigned int v51; // edx
  char *pData; // rdi
  char *v53; // r13
  signed __int32 v54; // r8d
  unsigned int v55; // ebp
  unsigned int v56; // r9d
  unsigned __int64 v57; // r8
  int v58; // ecx
  unsigned int v59; // ebp
  unsigned int v60; // r14d
  int v61; // r10d
  unsigned __int64 v62; // rbx
  unsigned __int8 *v63; // rbx
  int v64; // ecx
  unsigned int v65; // r9d
  int v66; // eax
  unsigned int v67; // edx
  int v68; // [rsp+0h] [rbp-58h]
  unsigned int v69; // [rsp+4h] [rbp-54h]
  unsigned int v70; // [rsp+8h] [rbp-50h]
  unsigned int v71; // [rsp+Ch] [rbp-4Ch]
  unsigned int v72; // [rsp+10h] [rbp-48h]
  unsigned __int64 v73; // [rsp+18h] [rbp-40h]
  unsigned int v74; // [rsp+60h] [rbp+8h]
  signed __int32 v76; // [rsp+70h] [rbp+18h]

  Pitch = splane->Pitch;
  v5 = dplane->Pitch;
  v6 = splane;
  Height = splane->Height;
  Width = dplane->Width;
  v10 = (splane->Width << 10) / Width;
  v73 = v5;
  v11 = (Height << 10) / dplane->Height;
  v69 = v11;
  if ( splane->Width == 1 )
  {
    if ( Height != 1 )
    {
      pData = dplane->pData;
      v53 = splane->pData;
      v54 = format & 0xFFEFFFFF;
      if ( v54 > 0 )
      {
        if ( v54 <= 2 )
        {
          v59 = 0;
          v60 = (v11 - 1) >> 2;
          do
          {
            v61 = v60 & 0x3FF;
            v62 = (unsigned __int64)v60 >> 10;
            ++v59;
            v60 += v11;
            v63 = (unsigned __int8 *)&v53[Pitch * v62];
            v64 = (1023 - v61) * v63[Pitch];
            v65 = (v61 * v63[2] + (1023 - v61) * (unsigned int)v63[Pitch + 2]) >> 10;
            v66 = *v63;
            v67 = (v61 * v63[3] + (1023 - v61) * (unsigned int)v63[Pitch + 3]) >> 10;
            pData[1] = (v61 * v63[1] + (1023 - v61) * (unsigned int)v63[Pitch + 1]) >> 10;
            pData[2] = v65;
            pData[3] = v67;
            *pData = (unsigned int)(v61 * v66 + v64) >> 10;
            pData += v73;
          }
          while ( v59 < dplane->Height );
        }
        else if ( v54 == 9 || (unsigned int)(v54 - 200) <= 1 )
        {
          v55 = 0;
          v56 = (v11 - 1) >> 2;
          do
          {
            v57 = (unsigned __int64)v56 >> 10;
            v58 = v56 & 0x3FF;
            ++v55;
            v56 += v11;
            *pData = (v58 * (unsigned __int8)v53[Pitch * v57]
                    + (1023 - v58) * (unsigned int)(unsigned __int8)v53[Pitch * v57 + Pitch]) >> 10;
            pData += v5;
          }
          while ( v55 < dplane->Height );
        }
      }
    }
  }
  else
  {
    if ( Height != 1 )
    {
      v12 = ((splane->Height << 10) / dplane->Height - 1) >> 2;
      v13 = 0;
      v72 = 0;
      v74 = v12;
      v14 = format & 0xFFEFFFFF;
      v15 = (Height << 10) / dplane->Height;
      v76 = v14;
      while ( 1 )
      {
        v16 = &dplane->pData[v5 * v13];
        v17 = (unsigned __int64)&v6->pData[Pitch * ((unsigned __int64)v12 >> 10)];
        v18 = v12 & 0x3FF;
        v19 = 1023 - v18;
        v68 = 1023 - v18;
        if ( v14 > 0 )
          break;
LABEL_16:
        v6 = splane;
        v12 += v15;
        v13 = v72 + 1;
        v74 = v12;
        v72 = v13;
        if ( v13 >= dplane->Height )
          return;
      }
      if ( v14 <= 2 )
      {
        v70 = 0;
        v24 = (v10 - 1) >> 2;
        v71 = v24;
        if ( !Width )
        {
LABEL_15:
          v12 = v74;
          goto LABEL_16;
        }
        v25 = v18;
        do
        {
          v26 = v24 & 0x3FF;
          v16 += 4;
          v27 = 1023 - v26;
          v28 = (unsigned __int8 *)(v17 + 4 * (v24 >> 10));
          v29 = (v25 * (v26 * v28[1] + v27 * v28[5]) + v19 * (v27 * v28[Pitch + 5] + v26 * (unsigned int)v28[Pitch + 1])) >> 20;
          v30 = (v25 * (v26 * v28[2] + v27 * v28[6]) + v19 * (v27 * v28[Pitch + 6] + v26 * (unsigned int)v28[Pitch + 2])) >> 20;
          v31 = *v28;
          v32 = (v25 * (v26 * v28[3] + v27 * v28[7]) + v19 * (v27 * v28[Pitch + 7] + v26 * (unsigned int)v28[Pitch + 3])) >> 20;
          v33 = (1023 - v26) * v28[4];
          v34 = v68 * (v26 * v28[Pitch] + (1023 - v26) * v28[Pitch + 4]);
          *(v16 - 3) = v29;
          *(v16 - 2) = v30;
          *(v16 - 1) = v32;
          v35 = v26 * v31 + v33;
          v24 = v10 + v71;
          v71 += v10;
          *(v16 - 4) = (unsigned int)(v25 * v35 + v34) >> 20;
          Width = dplane->Width;
          ++v70;
          v19 = v68;
        }
        while ( v70 < dplane->Width );
      }
      else
      {
        if ( v14 != 9 )
        {
          v12 = v74;
          if ( (unsigned int)(v14 - 200) > 1 )
            goto LABEL_16;
        }
        v20 = 0;
        v21 = (v10 - 1) >> 2;
        if ( !Width )
          goto LABEL_16;
        do
        {
          v22 = v21 & 0x3FF;
          ++v20;
          v23 = (unsigned __int8 *)(v17 + ((unsigned __int64)v21 >> 10));
          v21 += v10;
          *v16++ = (v18 * (v22 * *v23 + (1023 - v22) * v23[1])
                  + (1023 - v18) * (v22 * v23[Pitch] + (1023 - v22) * (unsigned int)v23[Pitch + 1])) >> 20;
          Width = dplane->Width;
        }
        while ( v20 < dplane->Width );
      }
      v5 = v73;
      v15 = v69;
      v14 = v76;
      goto LABEL_15;
    }
    v36 = dplane->pData;
    v37 = splane->pData;
    v38 = format & 0xFFEFFFFF;
    if ( v38 > 0 )
    {
      if ( v38 <= 2 )
      {
        v43 = 0;
        v44 = (v10 - 1) >> 2;
        do
        {
          v45 = v44 & 0x3FF;
          ++v43;
          v46 = 4 * (v44 >> 10);
          v44 += v10;
          v47 = (unsigned __int8 *)&v37[v46];
          v36 += 4;
          v48 = (1023 - v45) * v47[4];
          v49 = (v45 * v47[2] + (1023 - v45) * (unsigned int)v47[6]) >> 10;
          v50 = *v47;
          v51 = (v45 * v47[3] + (1023 - v45) * (unsigned int)v47[7]) >> 10;
          *(v36 - 3) = (v45 * v47[1] + (1023 - v45) * (unsigned int)v47[5]) >> 10;
          *(v36 - 2) = v49;
          *(v36 - 1) = v51;
          *(v36 - 4) = (unsigned int)(v45 * v50 + v48) >> 10;
        }
        while ( v43 < dplane->Width );
      }
      else if ( v38 == 9 || (unsigned int)(v38 - 200) <= 1 )
      {
        v39 = 0;
        v40 = (v10 - 1) >> 2;
        do
        {
          v41 = (unsigned __int64)v40 >> 10;
          v42 = v40 & 0x3FF;
          ++v39;
          v40 += v10;
          *v36++ = (v42 * (unsigned __int8)v37[v41] + (1023 - v42) * (unsigned int)(unsigned __int8)v37[v41 + 1]) >> 10;
        }
        while ( v39 < dplane->Width );
      }
    }
  }
}- v42) * (unsigned int)(unsigned __int8)v37[v41 + 1]) >> 10;
        }
        while ( v39 < dplane->Width );
      }
    }
  }
}

// File Line: 286
// RVA: 0x928F30
void __fastcall Scaleform::Render::Image_CopyScanline32_SwapBR(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  const char *v4; // r9
  __int64 v5; // r10
  char *v6; // rax
  unsigned __int64 v7; // rdx
  char v8; // cl

  if ( size )
  {
    v4 = ps + 1;
    v5 = ps - pd;
    v6 = pd + 2;
    v7 = ((size - 1) >> 2) + 1;
    do
    {
      v8 = v4[1];
      v6 += 4;
      v4 += 4;
      *(v6 - 6) = v8;
      *(v6 - 5) = *(v4 - 4);
      *(v6 - 4) = v6[v5 - 6];
      *(v6 - 3) = *(v4 - 2);
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 297
// RVA: 0x9921A0
void __fastcall Scaleform::Render::Image_CopyScanline32_RGBA_ARGB(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  const char *v4; // r9
  __int64 v5; // r10
  char *v6; // rax
  unsigned __int64 v7; // rdx
  char v8; // cl

  if ( size )
  {
    v4 = ps + 1;
    v5 = ps - pd;
    v6 = pd + 2;
    v7 = ((size - 1) >> 2) + 1;
    do
    {
      v8 = v4[2];
      v6 += 4;
      v4 += 4;
      *(v6 - 6) = v8;
      *(v6 - 5) = v6[v5 - 6];
      *(v6 - 4) = *(v4 - 4);
      *(v6 - 3) = *(v4 - 3);
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 309
// RVA: 0x928ED0
void __fastcall Scaleform::Render::Image_CopyScanline24_SwapBR(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  const char *v4; // r10
  __int64 v5; // r11
  char *v6; // r9
  unsigned __int64 v7; // rdx
  char v8; // al

  if ( size )
  {
    v4 = ps + 1;
    v5 = ps - pd;
    v6 = pd + 2;
    v7 = (size - 1) / 3 + 1;
    do
    {
      v8 = v4[1];
      v6 += 3;
      v4 += 3;
      *(v6 - 5) = v8;
      *(v6 - 4) = *(v4 - 3);
      *(v6 - 3) = v6[v5 - 5];
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 321
// RVA: 0x928F80
void __fastcall Scaleform::Render::Image_CopyScanline24_Extend_RGB_RGBA(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  const char *v4; // r9
  char *v5; // rcx
  unsigned __int64 v6; // rdx
  char v7; // al
  char v8; // al

  if ( size )
  {
    v4 = ps + 2;
    v5 = pd + 2;
    v6 = (size - 1) / 3 + 1;
    do
    {
      v7 = *(v4 - 2);
      v5 += 4;
      v4 += 3;
      *(v5 - 6) = v7;
      *(v5 - 5) = *(v4 - 4);
      v8 = *(v4 - 3);
      *(v5 - 3) = -1;
      *(v5 - 4) = v8;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 333
// RVA: 0x928FE0
void __fastcall Scaleform::Render::Image_CopyScanline24_Extend_RGB_BGRA(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  const char *v4; // r9
  char *v5; // rcx
  unsigned __int64 v6; // rdx
  char v7; // al
  char v8; // al

  if ( size )
  {
    v4 = ps + 1;
    v5 = pd + 2;
    v6 = (size - 1) / 3 + 1;
    do
    {
      v7 = v4[1];
      v5 += 4;
      v4 += 3;
      *(v5 - 6) = v7;
      *(v5 - 5) = *(v4 - 3);
      v8 = *(v4 - 4);
      *(v5 - 3) = -1;
      *(v5 - 4) = v8;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 357
// RVA: 0x992140
void __fastcall Scaleform::Render::Image_CopyScanline24_Extend_RGB_ARGB(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  const char *v4; // r9
  char *v5; // rcx
  unsigned __int64 v6; // rdx
  char v7; // al

  if ( size )
  {
    v4 = ps + 2;
    v5 = pd + 2;
    v6 = (size - 1) / 3 + 1;
    do
    {
      *(v5 - 2) = -1;
      v5 += 4;
      *(v5 - 5) = *(v4 - 2);
      v7 = *(v4 - 1);
      v4 += 3;
      *(v5 - 4) = v7;
      *(v5 - 3) = *(v4 - 3);
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 378
// RVA: 0x992250
void __fastcall Scaleform::Render::Image_CopyScanline32_Retract_RGBA_RGB(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  char *v4; // r9
  const char *v5; // rcx
  unsigned __int64 v6; // rdx
  char v7; // al

  if ( size )
  {
    v4 = pd + 2;
    v5 = ps + 2;
    v6 = (size - 1) / 3 + 1;
    do
    {
      v7 = *(v5 - 2);
      v4 += 3;
      v5 += 4;
      *(v4 - 5) = v7;
      *(v4 - 4) = *(v5 - 5);
      *(v4 - 3) = *(v5 - 4);
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 388
// RVA: 0x9921F0
void __fastcall Scaleform::Render::Image_CopyScanline32_Retract_ARGB_RGB(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  char *v4; // r9
  const char *v5; // rcx
  unsigned __int64 v6; // rdx
  char v7; // al

  if ( size )
  {
    v4 = pd + 2;
    v5 = ps + 2;
    v6 = (size - 1) / 3 + 1;
    do
    {
      v7 = *(v5 - 1);
      v4 += 3;
      v5 += 4;
      *(v4 - 5) = v7;
      *(v4 - 4) = *(v5 - 4);
      *(v4 - 3) = *(v5 - 3);
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 399
// RVA: 0x929040
void __fastcall Scaleform::Render::Image_CopyScanline_BGRA_BGR(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  const char *v4; // rax
  char *v5; // r9
  unsigned __int64 v6; // rdx
  char v7; // cl

  if ( size )
  {
    v4 = ps + 2;
    v5 = pd + 2;
    v6 = ((size - 1) >> 2) + 1;
    do
    {
      v7 = *(v4 - 2);
      v5 += 3;
      v4 += 4;
      *(v5 - 5) = v7;
      *(v5 - 4) = *(v4 - 5);
      *(v5 - 3) = *(v4 - 4);
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 409
// RVA: 0x929090
void __fastcall Scaleform::Render::Image_CopyScanline_BGRA_RGB(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  const char *v4; // rax
  char *v5; // r9
  unsigned __int64 v6; // rdx
  char v7; // cl

  if ( size )
  {
    v4 = ps + 1;
    v5 = pd + 2;
    v6 = ((size - 1) >> 2) + 1;
    do
    {
      v7 = v4[1];
      v5 += 3;
      v4 += 4;
      *(v5 - 5) = v7;
      *(v5 - 4) = *(v4 - 4);
      *(v5 - 3) = *(v4 - 5);
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 421
// RVA: 0x9290E0
void __fastcall Scaleform::Render::Image_CopyScanline_BGRA_A(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  const char *v4; // rax
  unsigned __int64 v5; // r8
  char v6; // dl

  if ( size )
  {
    v4 = ps + 3;
    v5 = ((size - 1) >> 2) + 1;
    do
    {
      v6 = *v4;
      ++pd;
      v4 += 4;
      *(pd - 1) = v6;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 429
// RVA: 0x929120
void __fastcall Scaleform::Render::Image_CopyScanline_BGR_A_Avg(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  const char *v5; // r9
  unsigned __int64 v6; // r8
  int v7; // ecx
  int v8; // eax

  if ( size )
  {
    v5 = ps + 1;
    v6 = (size - 1) / 3 + 1;
    do
    {
      ++pd;
      v7 = *((unsigned __int8 *)v5 + 1) + *((unsigned __int8 *)v5 - 1);
      v8 = *(unsigned __int8 *)v5;
      v5 += 3;
      *(pd - 1) = (v8 + v7) / 3u;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 439
// RVA: 0x929180
void __fastcall Scaleform::Render::Image_CopyScanline_A_BGRA(
        char *pd,
        char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  char *v4; // rax

  if ( size )
  {
    v4 = pd + 2;
    do
    {
      *((_WORD *)v4 - 1) = -1;
      *v4 = -1;
      v4[1] = *ps;
      v4 += 4;
      ++ps;
      --size;
    }
    while ( size );
  }
}

// File Line: 451
// RVA: 0x9291B0
void __fastcall Scaleform::Render::Image_CopyScanline_A_BGR(
        char *pd,
        char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *__formal)
{
  char *v4; // rax
  char v5; // cl

  if ( size )
  {
    v4 = pd + 2;
    do
    {
      v5 = *ps;
      v4 += 3;
      ++ps;
      *(v4 - 5) = v5;
      *(v4 - 4) = *(ps - 1);
      *(v4 - 3) = *(ps - 1);
      --size;
    }
    while ( size );
  }
}

// File Line: 464
// RVA: 0x9291F0
void __fastcall Scaleform::Render::Image_CopyScanline_P_BGRA(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *colorMap)
{
  unsigned __int64 v4; // r11
  char *v6; // rcx
  __int64 v7; // rax

  v4 = size;
  if ( size )
  {
    v6 = pd + 2;
    do
    {
      v7 = *(unsigned __int8 *)ps;
      v6 += 4;
      ++ps;
      LODWORD(v7) = colorMap->Colors[v7].Raw;
      *((_WORD *)v6 - 3) = v7;
      *(v6 - 4) = BYTE2(v7);
      *(v6 - 3) = BYTE3(v7);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 476
// RVA: 0x929240
void __fastcall Scaleform::Render::Image_CopyScanline_P_RGBA(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *colorMap)
{
  char *v5; // rcx
  __int64 v6; // rax

  if ( size )
  {
    v5 = pd + 2;
    do
    {
      v6 = *(unsigned __int8 *)ps;
      v5 += 4;
      ++ps;
      LODWORD(v6) = colorMap->Colors[v6].Raw;
      *(v5 - 4) = v6;
      *(v5 - 6) = BYTE2(v6);
      *(v5 - 5) = BYTE1(v6);
      *(v5 - 3) = BYTE3(v6);
      --size;
    }
    while ( size );
  }
}

// File Line: 489
// RVA: 0x929290
void __fastcall Scaleform::Render::Image_CopyScanline_P_BGR(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *colorMap)
{
  unsigned __int64 v4; // r10
  char *v5; // rcx
  __int64 v6; // rax
  unsigned int Raw; // r8d

  v4 = size;
  if ( size )
  {
    v5 = pd + 2;
    do
    {
      v6 = *(unsigned __int8 *)ps;
      v5 += 3;
      ++ps;
      Raw = colorMap->Colors[v6].Raw;
      *(v5 - 5) = Raw;
      *(v5 - 3) = BYTE2(Raw);
      *(v5 - 4) = BYTE1(Raw);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 501
// RVA: 0x9292D0
void __fastcall Scaleform::Render::Image_CopyScanline_P_RGB(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *colorMap)
{
  char *v5; // rcx
  __int64 v6; // rax

  if ( size )
  {
    v5 = pd + 2;
    do
    {
      v6 = *(unsigned __int8 *)ps;
      v5 += 3;
      ++ps;
      LODWORD(v6) = colorMap->Colors[v6].Raw;
      *(v5 - 3) = v6;
      *(v5 - 5) = BYTE2(v6);
      *(v5 - 4) = BYTE1(v6);
      --size;
    }
    while ( size );
  }
}

// File Line: 513
// RVA: 0x928520
void __fastcall Scaleform::Render::Image_CopyScanline_P_A(
        char *pd,
        const char *ps,
        unsigned __int64 size,
        Scaleform::Render::Palette *colorMap)
{
  unsigned __int64 v4; // r10
  __int64 v5; // r11
  unsigned int Raw; // eax

  v4 = size;
  if ( size )
  {
    v5 = ps - pd;
    do
    {
      Raw = colorMap->Colors[(unsigned __int8)pd[v5]].Raw;
      if ( colorMap->HasAlphaFlag )
        *pd = HIBYTE(Raw);
      else
        *pd = ((unsigned __int8)Raw + BYTE1(Raw) + (unsigned int)BYTE2(Raw)) / 3;
      ++pd;
      --v4;
    }
    while ( v4 );
  }
}

