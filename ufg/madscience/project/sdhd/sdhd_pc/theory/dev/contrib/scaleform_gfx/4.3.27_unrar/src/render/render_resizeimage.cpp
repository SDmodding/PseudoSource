// File Line: 256
// RVA: 0x99EDD0
void __fastcall Scaleform::Render::PixelFilterBilinearRGBA32(
        char *pDst,
        const char *pSrc1,
        const char *pSrc2,
        const char *pSrc3,
        const char *pSrc4,
        int xFract,
        int yFract)
{
  int v8; // r10d
  int v9; // eax
  int v10; // ebx
  int v11; // ebp
  int v12; // edi
  int v13; // r9d
  int v14; // r14d
  int v15; // eax
  int v16; // edi

  v8 = xFract * (256 - yFract);
  v9 = (256 - xFract) * (256 - yFract);
  v10 = yFract * (256 - xFract);
  v11 = v10 * *((unsigned __int8 *)pSrc3 + 1)
      + v8 * *((unsigned __int8 *)pSrc2 + 1)
      + v9 * *((unsigned __int8 *)pSrc1 + 1)
      + 0x8000;
  v12 = v10 * *((unsigned __int8 *)pSrc3 + 2)
      + v8 * *((unsigned __int8 *)pSrc2 + 2)
      + v9 * *((unsigned __int8 *)pSrc1 + 2)
      + 0x8000;
  v13 = v10 * *((unsigned __int8 *)pSrc3 + 3)
      + v8 * *((unsigned __int8 *)pSrc2 + 3)
      + v9 * *((unsigned __int8 *)pSrc1 + 3)
      + 0x8000;
  v14 = (yFract * xFract * *(unsigned __int8 *)pSrc4
       + v10 * *(unsigned __int8 *)pSrc3
       + v8 * *(unsigned __int8 *)pSrc2
       + v9 * *(unsigned __int8 *)pSrc1
       + 0x8000) >> 16;
  v15 = *((unsigned __int8 *)pSrc4 + 3);
  v16 = (yFract * xFract * *((unsigned __int8 *)pSrc4 + 2) + v12) >> 16;
  pDst[1] = (yFract * xFract * (unsigned int)*((unsigned __int8 *)pSrc4 + 1) + v11) >> 16;
  pDst[2] = v16;
  *pDst = v14;
  pDst[3] = (unsigned int)(yFract * xFract * v15 + v13) >> 16;
}

// File Line: 299
// RVA: 0x99ECD0
void __fastcall Scaleform::Render::PixelFilterBilinearRGB24(
        char *pDst,
        const char *pSrc1,
        const char *pSrc2,
        const char *pSrc3,
        const char *pSrc4,
        int xFract,
        int yFract)
{
  int v7; // r10d
  int v8; // eax
  int v9; // ebx
  int v10; // ebp
  int v11; // edi
  int v12; // r9d
  int v13; // eax
  int v14; // edi

  v7 = xFract * (256 - yFract);
  v8 = (256 - xFract) * (256 - yFract);
  v9 = yFract * (256 - xFract);
  v10 = v9 * *(unsigned __int8 *)pSrc3 + v7 * *(unsigned __int8 *)pSrc2 + v8 * *(unsigned __int8 *)pSrc1 + 0x8000;
  v11 = v9 * *((unsigned __int8 *)pSrc3 + 1)
      + v7 * *((unsigned __int8 *)pSrc2 + 1)
      + v8 * *((unsigned __int8 *)pSrc1 + 1)
      + 0x8000;
  v12 = v9 * *((unsigned __int8 *)pSrc3 + 2)
      + v7 * *((unsigned __int8 *)pSrc2 + 2)
      + v8 * *((unsigned __int8 *)pSrc1 + 2)
      + 0x8000;
  v13 = *((unsigned __int8 *)pSrc4 + 2);
  v14 = (yFract * xFract * *((unsigned __int8 *)pSrc4 + 1) + v11) >> 16;
  *pDst = (yFract * xFract * (unsigned int)*(unsigned __int8 *)pSrc4 + v10) >> 16;
  pDst[1] = v14;
  pDst[2] = (unsigned int)(yFract * xFract * v13 + v12) >> 16;
}

// File Line: 336
// RVA: 0x99EF10
void __fastcall Scaleform::Render::PixelFilterBilinearRGBtoRGBA32(
        char *pDst,
        const char *pSrc1,
        const char *pSrc2,
        const char *pSrc3,
        const char *pSrc4,
        int xFract,
        int yFract)
{
  int v7; // r10d
  int v8; // eax
  int v9; // ebx
  int v10; // ebp
  int v11; // edi
  int v12; // r9d
  int v13; // eax
  int v14; // edi

  v7 = xFract * (256 - yFract);
  v8 = (256 - xFract) * (256 - yFract);
  v9 = yFract * (256 - xFract);
  v10 = v9 * *(unsigned __int8 *)pSrc3 + v7 * *(unsigned __int8 *)pSrc2 + v8 * *(unsigned __int8 *)pSrc1 + 0x8000;
  v11 = v9 * *((unsigned __int8 *)pSrc3 + 1)
      + v7 * *((unsigned __int8 *)pSrc2 + 1)
      + v8 * *((unsigned __int8 *)pSrc1 + 1)
      + 0x8000;
  v12 = v9 * *((unsigned __int8 *)pSrc3 + 2)
      + v7 * *((unsigned __int8 *)pSrc2 + 2)
      + v8 * *((unsigned __int8 *)pSrc1 + 2)
      + 0x8000;
  v13 = *((unsigned __int8 *)pSrc4 + 2);
  v14 = (yFract * xFract * *((unsigned __int8 *)pSrc4 + 1) + v11) >> 16;
  *pDst = (yFract * xFract * (unsigned int)*(unsigned __int8 *)pSrc4 + v10) >> 16;
  pDst[1] = v14;
  pDst[3] = -1;
  pDst[2] = (unsigned int)(yFract * xFract * v13 + v12) >> 16;
}

// File Line: 349
// RVA: 0x99EC60
void __fastcall Scaleform::Render::PixelFilterBilinearGray8(
        char *pDst,
        const char *pSrc1,
        const char *pSrc2,
        const char *pSrc3,
        const char *pSrc4,
        int xFract,
        int yFract)
{
  *pDst = ((256 - xFract) * (256 - yFract) * *(unsigned __int8 *)pSrc1
         + yFract * (256 - xFract) * *(unsigned __int8 *)pSrc3
         + xFract * (256 - yFract) * *(unsigned __int8 *)pSrc2
         + yFract * xFract * (unsigned int)*(unsigned __int8 *)pSrc4
         + 0x8000) >> 16;
}

// File Line: 366
// RVA: 0x92D6B0
void __fastcall Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_int_int__(
        char *pDst,
        int dstWidth,
        unsigned int dstHeight,
        int dstPitch,
        int dstBpp,
        const char *pSrc,
        unsigned int srcWidth,
        int srcHeight,
        int srcPitch,
        int srcBpp,
        void (__fastcall *filter)(char *, const char *, const char *, const char *, const char *, int, int))
{
  __int64 v11; // rdi
  __int64 v12; // rsi
  __int64 v13; // rbx
  _DWORD *v14; // r15
  __int64 v15; // r14
  int v16; // r11d
  int v17; // r8d
  __int64 v18; // r9
  int v19; // ecx
  int v20; // ecx
  __int64 v21; // rdx
  int v22; // eax
  int v23; // ebx
  unsigned __int64 v24; // r8
  int v25; // edx
  int v26; // r10d
  int v27; // eax
  void (__fastcall *v28)(char *, const char *, const char *, const char *, const char *, int, int); // r13
  int v29; // r11d
  int v30; // edx
  int v31; // ecx
  int v32; // r12d
  const char *v33; // rsi
  int v34; // ecx
  const char *v35; // rbp
  char *v36; // rdi
  __int64 v37; // rbx
  int v38; // ecx
  const char *v39; // rsi
  const char *v40; // rbp
  __int64 v41; // r13
  int v42; // edx
  bool v43; // zf
  int v44; // [rsp+40h] [rbp-88h]
  int v45; // [rsp+44h] [rbp-84h]
  __int64 v47; // [rsp+50h] [rbp-78h]
  __int64 v48; // [rsp+70h] [rbp-58h]
  __int64 v49; // [rsp+78h] [rbp-50h]
  unsigned int v50; // [rsp+D0h] [rbp+8h]
  int v51; // [rsp+D8h] [rbp+10h] BYREF
  unsigned int v52; // [rsp+E0h] [rbp+18h]

  v52 = dstHeight;
  v11 = dstPitch;
  v12 = dstHeight;
  v13 = dstWidth;
  v14 = 0i64;
  v15 = dstWidth;
  if ( dstWidth )
  {
    v51 = 2;
    v14 = Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 4i64 * dstWidth, &v51);
  }
  v16 = srcWidth;
  v17 = (int)(srcWidth << 8) % (int)v13;
  v18 = (unsigned int)((int)(srcWidth << 8) / (int)v13);
  v19 = v17;
  if ( v17 <= 0 )
  {
    v17 += v13;
    v19 = v17;
    v18 = (unsigned int)(v18 - 1);
  }
  v20 = v19 - v13;
  v21 = 0i64;
  if ( (int)v13 > 0 )
  {
    v22 = (int)(srcWidth << 7) / (int)v13 - 128;
    do
    {
      v14[v21] = v22;
      v20 += v17;
      v22 += v18;
      if ( v20 > 0 )
      {
        v20 -= v13;
        ++v22;
      }
      ++v21;
    }
    while ( v21 < v13 );
  }
  v23 = srcHeight;
  v24 = (unsigned int)((srcHeight << 7) / (int)v12);
  v25 = (srcHeight << 8) % (int)v12;
  v45 = v25;
  v44 = (srcHeight << 8) / (int)v12;
  if ( v25 <= 0 )
  {
    v45 = v12 + v25;
    v25 += v12;
    v44 = (srcHeight << 8) / (int)v12 - 1;
  }
  srcWidth = v25 - v12;
  if ( (int)v12 > 0 )
  {
    LODWORD(v18) = v16 - 1;
    v50 = v16 - 1;
    v26 = srcBpp;
    v49 = srcBpp * (v16 - 1);
    v48 = v11;
    v27 = v24 - 128;
    v51 = v24 - 128;
    v47 = v12;
    v28 = filter;
    v29 = srcPitch;
    v24 = (unsigned __int64)pSrc;
    v30 = dstBpp;
    do
    {
      v31 = v27 >> 8;
      v32 = (unsigned __int8)v27;
      if ( v27 >> 8 >= 0 )
        v33 = (const char *)(v24 + v29 * v31);
      else
        v33 = (const char *)v24;
      v34 = v31 + 1;
      if ( v34 >= v23 )
        v34 = v23 - 1;
      v35 = (const char *)(v24 + v29 * v34);
      v36 = pDst;
      v37 = 0i64;
      if ( v15 > 0 )
      {
        while ( (int)v14[v37] >> 8 < 0 )
        {
          v28(v36, v33, v33, v35, v35, (unsigned __int8)v14[v37], v32);
          v30 = dstBpp;
          v36 += dstBpp;
          if ( ++v37 >= v15 )
            goto LABEL_24;
        }
        v30 = dstBpp;
LABEL_24:
        LODWORD(v18) = v50;
        v26 = srcBpp;
      }
      for ( ; v37 < v15; v26 = srcBpp )
      {
        v38 = (int)v14[v37] >> 8;
        if ( v38 >= (int)v18 )
          break;
        v28(
          v36,
          &v33[v26 * v38],
          &v33[v26 * (v38 + 1)],
          &v35[v26 * v38],
          &v35[v26 * (v38 + 1)],
          (unsigned __int8)v14[v37],
          v32);
        v30 = dstBpp;
        v36 += dstBpp;
        ++v37;
        LODWORD(v18) = v50;
      }
      v39 = &v33[v49];
      v40 = &v35[v49];
      if ( v37 < v15 )
      {
        v41 = v30;
        do
        {
          filter(v36, v39, v39, v40, v40, LOBYTE(v14[v37]), v32);
          v36 += v41;
          ++v37;
        }
        while ( v37 < v15 );
        v28 = filter;
      }
      v42 = v45 + srcWidth;
      srcWidth = v42;
      v27 = v44 + v51;
      v51 += v44;
      if ( v42 > 0 )
      {
        srcWidth = v42 - v52;
        v51 = ++v27;
      }
      pDst += v48;
      v43 = v47-- == 1;
      v30 = dstBpp;
      v18 = v50;
      v24 = (unsigned __int64)pSrc;
      v26 = srcBpp;
      v23 = srcHeight;
      v29 = srcPitch;
    }
    while ( !v43 );
  }
  if ( v14 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *, _DWORD *, unsigned __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v14,
      v24,
      v18);
}

// File Line: 464
// RVA: 0x9AC8C0
void __fastcall Scaleform::Render::ResizeImageBilinear(
        char *pDst,
        int dstWidth,
        int dstHeight,
        int dstPitch,
        const char *pSrc,
        int srcWidth,
        int srcHeight,
        int srcPitch,
        Scaleform::Render::ResizeImageType type)
{
  if ( dstWidth > 0 && dstHeight > 0 && srcWidth > 0 && srcHeight > 0 )
  {
    switch ( type )
    {
      case ResizeRgbToRgb:
        Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_int_int__(
          pDst,
          dstWidth,
          dstHeight,
          dstPitch,
          3,
          pSrc,
          srcWidth,
          srcHeight,
          srcPitch,
          3,
          Scaleform::Render::PixelFilterBilinearRGB24);
        break;
      case ResizeRgbaToRgba:
        Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_int_int__(
          pDst,
          dstWidth,
          dstHeight,
          dstPitch,
          4,
          pSrc,
          srcWidth,
          srcHeight,
          srcPitch,
          4,
          Scaleform::Render::PixelFilterBilinearRGBA32);
        break;
      case ResizeRgbToRgba:
        Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_int_int__(
          pDst,
          dstWidth,
          dstHeight,
          dstPitch,
          4,
          pSrc,
          srcWidth,
          srcHeight,
          srcPitch,
          3,
          Scaleform::Render::PixelFilterBilinearRGBtoRGBA32);
        break;
      case ResizeGray:
        Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_int_int__(
          pDst,
          dstWidth,
          dstHeight,
          dstPitch,
          1,
          pSrc,
          srcWidth,
          srcHeight,
          srcPitch,
          1,
          Scaleform::Render::PixelFilterBilinearGray8);
        break;
    }
  }
}

