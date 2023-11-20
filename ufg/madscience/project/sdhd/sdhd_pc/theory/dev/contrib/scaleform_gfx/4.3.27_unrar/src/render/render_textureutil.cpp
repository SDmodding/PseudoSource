// File Line: 26
// RVA: 0x9874B0
signed __int64 __fastcall Scaleform::Render::GetImageFormatRescaleType(Scaleform::Render::ImageFormat format)
{
  if ( (signed int)format > 0 )
  {
    if ( (signed int)format <= 2 )
      return 2i64;
    if ( (signed int)format <= 4 )
      return 1i64;
    if ( format == 9 )
      return 4i64;
  }
  return 0i64;
}

// File Line: 45
// RVA: 0x9AA900
void __fastcall Scaleform::Render::RescaleImageData(Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData *src, Scaleform::Render::ResizeImageType resizeType)
{
  Scaleform::Render::ImageData *v3; // rdi
  Scaleform::Render::ImageData *v4; // r14
  signed int v5; // ecx
  unsigned int v6; // ebx
  __int64 v7; // rsi
  unsigned int v8; // ecx
  Scaleform::Render::ImagePlane *v9; // rcx
  int srcWidth; // er15
  int srcHeight; // er12
  char *v12; // r13
  unsigned int v13; // ecx
  Scaleform::Render::ImagePlane *v14; // rcx
  unsigned __int64 v15; // rax
  int v16; // edx
  int v17; // er8
  char *v18; // rcx
  Scaleform::Render::ImagePlane p; // [rsp+50h] [rbp-19h]
  Scaleform::Render::ImagePlane v20; // [rsp+70h] [rbp+7h]
  unsigned int v21; // [rsp+D8h] [rbp+6Fh]
  Scaleform::Render::ResizeImageType type; // [rsp+E0h] [rbp+77h]

  type = resizeType;
  v3 = src;
  v4 = dest;
  if ( src->Flags & 1 )
    v5 = (unsigned __int8)src->LevelCount;
  else
    v5 = 1;
  v6 = 0;
  v21 = v5 * src->RawPlaneCount;
  if ( v21 )
  {
    v7 = 0i64;
    do
    {
      p.Pitch = 0i64;
      p.DataSize = 0i64;
      p.pData = 0i64;
      v20.Pitch = 0i64;
      v20.DataSize = 0i64;
      v20.pData = 0i64;
      v8 = v3->RawPlaneCount;
      *(_QWORD *)&p.Width = 0i64;
      *(_QWORD *)&v20.Width = 0i64;
      if ( v6 >= v8 )
      {
        Scaleform::Render::ImagePlane::GetMipLevel(&v3->pPlanes[v6 % v8], v3->Format, v6 / v8, &p, v6 % v8);
        v12 = p.pData;
        srcHeight = p.Height;
        srcWidth = p.Width;
      }
      else
      {
        v9 = &v3->pPlanes[v7];
        srcWidth = v9->Width;
        srcHeight = v9->Height;
        v12 = v9->pData;
        p.Pitch = v9->Pitch;
      }
      v13 = v4->RawPlaneCount;
      if ( v6 >= v13 )
      {
        Scaleform::Render::ImagePlane::GetMipLevel(&v4->pPlanes[v6 % v13], v4->Format, v6 / v13, &v20, v6 % v13);
        v18 = v20.pData;
        v17 = v20.Height;
        v16 = v20.Width;
      }
      else
      {
        v14 = &v4->pPlanes[v7];
        v15 = v14->Pitch;
        v16 = v14->Width;
        v17 = v14->Height;
        v18 = v14->pData;
        v20.Pitch = v15;
      }
      Scaleform::Render::ResizeImageBilinear(v18, v16, v17, v20.Pitch, v12, srcWidth, srcHeight, p.Pitch, type);
      ++v6;
      ++v7;
    }
    while ( v6 < v21 );
  }
}

// File Line: 67
// RVA: 0x9634B0
void __fastcall Scaleform::Render::ConvertImagePlane(Scaleform::Render::ImagePlane *dplane, Scaleform::Render::ImagePlane *splane, Scaleform::Render::ImageFormat format, unsigned int formatPlaneIndex, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), Scaleform::Render::Palette *pcolorMap, void *scanlineArg)
{
  Scaleform::Render::ImagePlane *v7; // rbp
  Scaleform::Render::ImagePlane *v8; // r14
  __int16 v9; // bx
  unsigned int v10; // eax
  __int64 v11; // rcx
  unsigned __int64 v12; // rbx
  const char *v13; // rdi
  char *i; // rsi
  __int64 v15; // [rsp+60h] [rbp+8h]

  v7 = splane;
  v8 = dplane;
  v9 = format;
  v10 = Scaleform::Render::ImageData::GetFormatBitsPerPixel(format, formatPlaneIndex);
  v11 = v10;
  v15 = v10;
  if ( (v9 & 0xFFFu) - 50 > 3 )
    v12 = v7->Height;
  else
    v12 = (unsigned __int64)(v7->Height + 3) >> 2;
  v13 = v7->pData;
  for ( i = v8->pData; v12; --v12 )
  {
    copyScanline(i, v13, v11 * (unsigned __int64)v7->Width >> 3, pcolorMap, scanlineArg);
    v13 += v7->Pitch;
    i += v8->Pitch;
    v11 = v15;
  }
}

// File Line: 86
// RVA: 0x963240
void __fastcall Scaleform::Render::ConvertImageData(Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData *src, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *scanlineArg)
{
  Scaleform::Render::ImageData *v4; // rbx
  Scaleform::Render::ImageData *v5; // rbp
  signed int v6; // eax
  __int32 v7; // edi
  unsigned int v8; // ecx
  unsigned int v9; // er14
  unsigned int v10; // er9
  unsigned int v11; // eax
  __int64 v12; // rdx
  unsigned int v13; // ecx
  Scaleform::Render::ImagePlane *v14; // rax
  unsigned __int64 v15; // rbx
  unsigned __int64 v16; // r13
  char *v17; // rsi
  unsigned int v18; // ecx
  Scaleform::Render::ImagePlane *v19; // rax
  unsigned __int64 v20; // r15
  char *v21; // rdi
  Scaleform::Render::Palette *v22; // r12
  unsigned __int64 v23; // rbp
  unsigned int v24; // [rsp+30h] [rbp-A8h]
  unsigned int v25; // [rsp+34h] [rbp-A4h]
  __int64 v26; // [rsp+38h] [rbp-A0h]
  unsigned int v27; // [rsp+40h] [rbp-98h]
  unsigned int v28; // [rsp+44h] [rbp-94h]
  Scaleform::Render::ImagePlane p; // [rsp+48h] [rbp-90h]
  __int64 v30; // [rsp+68h] [rbp-70h]
  Scaleform::Render::ImagePlane v31; // [rsp+70h] [rbp-68h]
  Scaleform::Render::ImageData *v32; // [rsp+E0h] [rbp+8h]
  Scaleform::Render::ImageData *v33; // [rsp+E8h] [rbp+10h]
  void (__fastcall *v34)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // [rsp+F0h] [rbp+18h]
  void *v35; // [rsp+F8h] [rbp+20h]

  v35 = scanlineArg;
  v34 = copyScanline;
  v33 = src;
  v32 = dest;
  v4 = src;
  v5 = dest;
  v6 = 1;
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
  if ( src->Flags & 1 )
    v6 = (unsigned __int8)src->LevelCount;
  v9 = 0;
  v24 = 0;
  v10 = v6 * src->RawPlaneCount;
  v27 = v10;
  if ( v10 )
  {
    v11 = Scaleform::Render::ImageData::GetFormatBitsPerPixel(src->Format, v10 % v8);
    v12 = 0i64;
    v26 = 0i64;
    v30 = v11;
    v28 = v7 - 50;
    do
    {
      v13 = v4->RawPlaneCount;
      *(_QWORD *)&p.Width = 0i64;
      p.Pitch = 0i64;
      p.DataSize = 0i64;
      p.pData = 0i64;
      *(_QWORD *)&v31.Width = 0i64;
      v31.Pitch = 0i64;
      v31.DataSize = 0i64;
      v31.pData = 0i64;
      if ( v9 >= v13 )
      {
        Scaleform::Render::ImagePlane::GetMipLevel(&v4->pPlanes[v9 % v13], v4->Format, v9 / v13, &p, v9 % v13);
        v17 = p.pData;
        v16 = p.Pitch;
        v15 = p.Height;
        v12 = v26;
        v25 = p.Width;
      }
      else
      {
        v14 = v4->pPlanes;
        v15 = *(unsigned int *)((char *)&v14->Height + v12);
        v16 = *(unsigned __int64 *)((char *)&v14->Pitch + v12);
        v17 = *(char **)((char *)&v14->pData + v12);
        v25 = *(unsigned int *)((char *)&v14->Width + v12);
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
      v22 = v5->pPalette.pObject;
      if ( v28 <= 3 )
        v15 = (unsigned __int64)(unsigned int)(v15 + 3) >> 2;
      if ( v15 )
      {
        v23 = v30 * (unsigned __int64)v25 >> 3;
        do
        {
          v34(v21, v17, v23, v22, v35);
          v17 += v16;
          v21 += v20;
          --v15;
        }
        while ( v15 );
        v9 = v24;
        v12 = v26;
        v5 = v32;
      }
      v4 = v33;
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
void __fastcall Scaleform::Render::GenerateMipLevel(Scaleform::Render::ImagePlane *dplane, Scaleform::Render::ImagePlane *splane, Scaleform::Render::ImageFormat format, unsigned int formatPlaneIndex)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // r10
  Scaleform::Render::ImagePlane *v6; // rdi
  unsigned int v7; // ebx
  Scaleform::Render::ImagePlane *v8; // r15
  unsigned int v9; // ecx
  unsigned int v10; // er11
  unsigned int v11; // er13
  unsigned int v12; // eax
  int v13; // eax
  unsigned int v14; // ett
  int v15; // er12
  unsigned int v16; // eax
  unsigned int v17; // edx
  signed __int32 v18; // er8
  int v19; // er9
  char *v20; // r14
  unsigned __int64 v21; // r12
  int v22; // edi
  int v23; // edx
  unsigned int v24; // ebx
  unsigned int v25; // er11
  int v26; // er10
  unsigned __int8 *v27; // rdx
  unsigned int v28; // eax
  int v29; // ebp
  int v30; // edi
  int v31; // er11
  unsigned __int8 *v32; // r10
  unsigned int v33; // ebx
  unsigned int v34; // er9
  int v35; // eax
  unsigned int v36; // er8
  int v37; // ecx
  int v38; // edx
  int v39; // ecx
  unsigned int v40; // edx
  bool v41; // cf
  char *v42; // rdi
  char *v43; // r14
  signed __int32 v44; // er8
  unsigned int v45; // ebp
  unsigned int v46; // er9
  unsigned __int64 v47; // rcx
  int v48; // er8
  unsigned int v49; // ebp
  unsigned int v50; // esi
  int v51; // ebx
  __int64 v52; // r8
  unsigned __int8 *v53; // r8
  int v54; // ecx
  unsigned int v55; // er9
  int v56; // eax
  unsigned int v57; // edx
  char *v58; // rdi
  char *v59; // r13
  signed __int32 v60; // er8
  unsigned int v61; // ebp
  unsigned int v62; // er9
  unsigned __int64 v63; // r8
  int v64; // ecx
  unsigned int v65; // ebp
  unsigned int v66; // er14
  int v67; // er10
  unsigned __int64 v68; // rbx
  unsigned __int8 *v69; // rbx
  int v70; // ecx
  unsigned int v71; // er9
  int v72; // eax
  unsigned int v73; // edx
  int v74; // [rsp+0h] [rbp-58h]
  int v75; // [rsp+4h] [rbp-54h]
  unsigned int v76; // [rsp+8h] [rbp-50h]
  unsigned int v77; // [rsp+Ch] [rbp-4Ch]
  unsigned int v78; // [rsp+10h] [rbp-48h]
  unsigned __int64 v79; // [rsp+18h] [rbp-40h]
  unsigned int v80; // [rsp+60h] [rbp+8h]
  Scaleform::Render::ImagePlane *v81; // [rsp+68h] [rbp+10h]
  signed __int32 v82; // [rsp+70h] [rbp+18h]

  v81 = splane;
  v4 = splane->Pitch;
  v5 = dplane->Pitch;
  v6 = splane;
  v7 = splane->Height;
  v8 = dplane;
  v9 = dplane->Width;
  v10 = v8->Height;
  v11 = (splane->Width << 10) / v9;
  v12 = splane->Height;
  v79 = v5;
  v14 = v12 << 10;
  v13 = (v12 << 10) / v10;
  v15 = v13;
  v75 = v14 / v10;
  if ( splane->Width == 1 )
  {
    if ( v7 != 1 )
    {
      v58 = v8->pData;
      v59 = splane->pData;
      v60 = format & 0xFFEFFFFF;
      if ( v60 > 0 )
      {
        if ( v60 <= 2 )
        {
          v65 = 0;
          v66 = (unsigned int)(v13 - 1) >> 2;
          if ( v10 )
          {
            do
            {
              v67 = v66 & 0x3FF;
              v68 = (unsigned __int64)v66 >> 10;
              ++v65;
              v66 += v15;
              v69 = (unsigned __int8 *)&v59[v4 * v68];
              v70 = (1023 - v67) * v69[v4];
              v71 = (v67 * v69[2] + (1023 - v67) * (unsigned int)v69[v4 + 2]) >> 10;
              v72 = *v69;
              v73 = (v67 * v69[3] + (1023 - v67) * (unsigned int)v69[v4 + 3]) >> 10;
              v58[1] = (v67 * v69[1] + (1023 - v67) * (unsigned int)v69[v4 + 1]) >> 10;
              v58[2] = v71;
              v58[3] = v73;
              *v58 = (unsigned int)(v67 * v72 + v70) >> 10;
              v58 += v79;
            }
            while ( v65 < v8->Height );
          }
        }
        else if ( v60 == 9 || (unsigned int)(v60 - 200) <= 1 )
        {
          v61 = 0;
          v62 = (unsigned int)(v13 - 1) >> 2;
          if ( v10 )
          {
            do
            {
              v63 = (unsigned __int64)v62 >> 10;
              v64 = v62 & 0x3FF;
              ++v61;
              v62 += v13;
              *v58 = (v64 * (unsigned __int8)v59[v4 * v63]
                    + (1023 - v64) * (unsigned int)(unsigned __int8)v59[v4 * v63 + v4]) >> 10;
              v58 += v5;
            }
            while ( v61 < v8->Height );
          }
        }
      }
    }
  }
  else if ( v7 == 1 )
  {
    v42 = v8->pData;
    v43 = splane->pData;
    v44 = format & 0xFFEFFFFF;
    if ( v44 > 0 )
    {
      if ( v44 <= 2 )
      {
        v49 = 0;
        v50 = (v11 - 1) >> 2;
        if ( v9 )
        {
          do
          {
            v51 = v50 & 0x3FF;
            ++v49;
            v52 = 4 * (v50 >> 10);
            v50 += v11;
            v53 = (unsigned __int8 *)&v43[v52];
            v42 += 4;
            v54 = (1023 - v51) * v53[4];
            v55 = (v51 * v53[2] + (1023 - v51) * (unsigned int)v53[6]) >> 10;
            v56 = *v53;
            v57 = (v51 * v53[3] + (1023 - v51) * (unsigned int)v53[7]) >> 10;
            *(v42 - 3) = (v51 * v53[1] + (1023 - v51) * (unsigned int)v53[5]) >> 10;
            *(v42 - 2) = v55;
            *(v42 - 1) = v57;
            *(v42 - 4) = (unsigned int)(v51 * v56 + v54) >> 10;
          }
          while ( v49 < v8->Width );
        }
      }
      else if ( v44 == 9 || (unsigned int)(v44 - 200) <= 1 )
      {
        v45 = 0;
        v46 = (v11 - 1) >> 2;
        if ( v9 )
        {
          do
          {
            v47 = (unsigned __int64)v46 >> 10;
            v48 = v46 & 0x3FF;
            ++v45;
            v46 += v11;
            *(++v42 - 1) = (v48 * (unsigned __int8)v43[v47] + (1023 - v48) * (unsigned int)(unsigned __int8)v43[v47 + 1]) >> 10;
          }
          while ( v45 < v8->Width );
        }
      }
    }
  }
  else
  {
    v16 = (unsigned int)(v13 - 1) >> 2;
    v17 = 0;
    v78 = 0;
    v80 = v16;
    if ( v10 )
    {
      v18 = format & 0xFFEFFFFF;
      v19 = v15;
      v82 = v18;
      while ( 1 )
      {
        v20 = &v8->pData[v5 * v17];
        v21 = (unsigned __int64)&v6->pData[v4 * ((unsigned __int64)v16 >> 10)];
        v22 = v16 & 0x3FF;
        v23 = 1023 - v22;
        v74 = 1023 - v22;
        if ( v18 > 0 )
          break;
LABEL_17:
        v6 = v81;
        v16 += v19;
        v17 = v78 + 1;
        v80 = v16;
        v78 = v17;
        if ( v17 >= v8->Height )
          return;
      }
      if ( v18 <= 2 )
      {
        v76 = 0;
        v28 = (v11 - 1) >> 2;
        v77 = (v11 - 1) >> 2;
        if ( !v9 )
        {
LABEL_16:
          v16 = v80;
          goto LABEL_17;
        }
        v29 = v22;
        do
        {
          v30 = v28 & 0x3FF;
          v20 += 4;
          v31 = 1023 - v30;
          v32 = (unsigned __int8 *)(v21 + 4 * (v28 >> 10));
          v33 = (v29 * (v30 * v32[1] + v31 * v32[5]) + v23 * (v31 * v32[v4 + 5] + v30 * (unsigned int)v32[v4 + 1])) >> 20;
          v34 = (v29 * (v30 * v32[2] + v31 * v32[6]) + v23 * (v31 * v32[v4 + 6] + v30 * (unsigned int)v32[v4 + 2])) >> 20;
          v35 = *v32;
          v36 = (v29 * (v30 * v32[3] + v31 * v32[7]) + v23 * (v31 * v32[v4 + 7] + v30 * (unsigned int)v32[v4 + 3])) >> 20;
          v37 = (1023 - v30) * v32[4];
          v38 = v74 * (v30 * v32[v4] + (1023 - v30) * v32[v4 + 4]);
          *(v20 - 3) = v33;
          *(v20 - 2) = v34;
          *(v20 - 1) = v36;
          v39 = v30 * v35 + v37;
          v28 = v11 + v77;
          v77 += v11;
          *(v20 - 4) = (unsigned int)(v29 * v39 + v38) >> 20;
          v9 = v8->Width;
          v40 = v76 + 1;
          v76 = v40;
          v41 = v40 < v8->Width;
          v23 = v74;
        }
        while ( v41 );
      }
      else
      {
        if ( v18 != 9 )
        {
          v16 = v80;
          if ( (unsigned int)(v18 - 200) > 1 )
            goto LABEL_17;
        }
        v24 = 0;
        v25 = (v11 - 1) >> 2;
        if ( !v9 )
          goto LABEL_17;
        do
        {
          v26 = v25 & 0x3FF;
          ++v24;
          v27 = (unsigned __int8 *)(v21 + ((unsigned __int64)v25 >> 10));
          v25 += v11;
          *(++v20 - 1) = (v22 * (v26 * *v27 + (1023 - v26) * v27[1])
                        + (1023 - v22) * (v26 * v27[v4] + (1023 - v26) * (unsigned int)v27[v4 + 1])) >> 20;
          v9 = v8->Width;
        }
        while ( v24 < v8->Width );
      }
      v5 = v79;
      v19 = v75;
      v18 = v82;
      goto LABEL_16;
    }
  }
}

// File Line: 286
// RVA: 0x928F30
void __fastcall Scaleform::Render::Image_CopyScanline32_SwapBR(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
{
  const char *v4; // r9
  signed __int64 v5; // r10
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
void __fastcall Scaleform::Render::Image_CopyScanline32_RGBA_ARGB(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
{
  const char *v4; // r9
  signed __int64 v5; // r10
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
void __fastcall Scaleform::Render::Image_CopyScanline24_SwapBR(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
{
  const char *v4; // r10
  signed __int64 v5; // r11
  char *v6; // r9
  unsigned __int64 v7; // rdx
  char v8; // al

  if ( size )
  {
    v4 = ps + 1;
    v5 = ps - pd;
    v6 = pd + 2;
    v7 = ((unsigned __int64)((size - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 1) + 1;
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
void __fastcall Scaleform::Render::Image_CopyScanline24_Extend_RGB_RGBA(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
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
    v6 = ((unsigned __int64)((size - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 1) + 1;
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
void __fastcall Scaleform::Render::Image_CopyScanline24_Extend_RGB_BGRA(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
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
    v6 = ((unsigned __int64)((size - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 1) + 1;
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
void __fastcall Scaleform::Render::Image_CopyScanline24_Extend_RGB_ARGB(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
{
  const char *v4; // r9
  char *v5; // rcx
  unsigned __int64 v6; // rdx
  char v7; // al

  if ( size )
  {
    v4 = ps + 2;
    v5 = pd + 2;
    v6 = ((unsigned __int64)((size - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 1) + 1;
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
void __fastcall Scaleform::Render::Image_CopyScanline32_Retract_RGBA_RGB(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
{
  char *v4; // r9
  const char *v5; // rcx
  unsigned __int64 v6; // rdx
  char v7; // al

  if ( size )
  {
    v4 = pd + 2;
    v5 = ps + 2;
    v6 = ((unsigned __int64)((size - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 1) + 1;
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
void __fastcall Scaleform::Render::Image_CopyScanline32_Retract_ARGB_RGB(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
{
  char *v4; // r9
  const char *v5; // rcx
  unsigned __int64 v6; // rdx
  char v7; // al

  if ( size )
  {
    v4 = pd + 2;
    v5 = ps + 2;
    v6 = ((unsigned __int64)((size - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 1) + 1;
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
void __fastcall Scaleform::Render::Image_CopyScanline_BGRA_BGR(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
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
void __fastcall Scaleform::Render::Image_CopyScanline_BGRA_RGB(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
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
void __fastcall Scaleform::Render::Image_CopyScanline_BGRA_A(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
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
void __fastcall Scaleform::Render::Image_CopyScanline_BGR_A_Avg(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
{
  char *v4; // r10
  const char *v5; // r9
  unsigned __int64 v6; // r8
  int v7; // ecx
  int v8; // eax

  v4 = pd;
  if ( size )
  {
    v5 = ps + 1;
    v6 = ((unsigned __int64)((size - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 1) + 1;
    do
    {
      ++v4;
      v7 = *((unsigned __int8 *)v5 + 1) + *((unsigned __int8 *)v5 - 1);
      v8 = *(unsigned __int8 *)v5;
      v5 += 3;
      *(v4 - 1) = (v8 + v7) / 3u;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 439
// RVA: 0x929180
void __fastcall Scaleform::Render::Image_CopyScanline_A_BGRA(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
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
void __fastcall Scaleform::Render::Image_CopyScanline_A_BGR(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *__formal)
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
void __fastcall Scaleform::Render::Image_CopyScanline_P_BGRA(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *colorMap)
{
  unsigned __int64 v4; // r11
  const char *v5; // r10
  char *v6; // rcx
  __int64 v7; // rax

  v4 = size;
  v5 = ps;
  if ( size )
  {
    v6 = pd + 2;
    do
    {
      v7 = *(unsigned __int8 *)v5;
      v6 += 4;
      ++v5;
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
void __fastcall Scaleform::Render::Image_CopyScanline_P_RGBA(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *colorMap)
{
  const char *v4; // r10
  char *v5; // rcx
  __int64 v6; // rax

  v4 = ps;
  if ( size )
  {
    v5 = pd + 2;
    do
    {
      v6 = *(unsigned __int8 *)v4;
      v5 += 4;
      ++v4;
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
void __fastcall Scaleform::Render::Image_CopyScanline_P_BGR(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *colorMap)
{
  unsigned __int64 v4; // r10
  char *v5; // rcx
  __int64 v6; // rax

  v4 = size;
  if ( size )
  {
    v5 = pd + 2;
    do
    {
      v6 = *(unsigned __int8 *)ps;
      v5 += 3;
      ++ps;
      LODWORD(v6) = colorMap->Colors[v6].Raw;
      *(v5 - 5) = v6;
      *(v5 - 3) = BYTE2(v6);
      *(v5 - 4) = BYTE1(v6);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 501
// RVA: 0x9292D0
void __fastcall Scaleform::Render::Image_CopyScanline_P_RGB(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *colorMap)
{
  const char *v4; // r10
  char *v5; // rcx
  __int64 v6; // rax

  v4 = ps;
  if ( size )
  {
    v5 = pd + 2;
    do
    {
      v6 = *(unsigned __int8 *)v4;
      v5 += 3;
      ++v4;
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
void __fastcall Scaleform::Render::Image_CopyScanline_P_A(char *pd, const char *ps, unsigned __int64 size, Scaleform::Render::Palette *colorMap)
{
  unsigned __int64 v4; // r10
  signed __int64 v5; // r11
  unsigned int v6; // eax

  v4 = size;
  if ( size )
  {
    v5 = ps - pd;
    do
    {
      v6 = colorMap->Colors[(unsigned __int8)pd[v5]].Raw;
      if ( colorMap->HasAlphaFlag )
        *pd = HIBYTE(v6);
      else
        *pd = ((unsigned __int8)v6 + BYTE1(v6) + (unsigned int)BYTE2(v6)) / 3;
      ++pd;
      --v4;
    }
    while ( v4 );
  }
}

