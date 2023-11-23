// File Line: 49
// RVA: 0xC56B90
void __fastcall memCopyBackwards_8_(char *dst, char *src, unsigned int nbytes)
{
  __int64 v4; // rax
  unsigned __int64 v5; // r8
  __int64 v6; // rdx

  v4 = (unsigned int)((unsigned __int64)(int)nbytes >> 3) - 1;
  if ( nbytes >= 8 )
  {
    v5 = (unsigned __int64)nbytes >> 3;
    do
    {
      v6 = 8 * v4;
      v4 = (unsigned int)(v4 - 1);
      *(_QWORD *)&dst[v6] = *(_QWORD *)&src[v6];
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 64
// RVA: 0xC569F0
void __fastcall hkMemUtil::memCpy(void *dst, const void *src, int nbytes)
{
  memmove(dst, src, nbytes);
}

// File Line: 69
// RVA: 0xC56B80
void __fastcall hkMemUtil::memSet(void *dst, int c, unsigned int n)
{
  memset(dst, c, n);
}

// File Line: 74
// RVA: 0xC56A00
void __fastcall hkMemUtil::memCpyBackwards(_BYTE *dst, _BYTE *src, unsigned int nbytes)
{
  _BYTE *v3; // r9
  __int64 v4; // r10
  unsigned __int64 v5; // r11
  __int64 v6; // rcx
  unsigned __int64 v7; // rbx
  __int64 v8; // r10
  unsigned __int64 v9; // r11
  __int64 v10; // rcx
  unsigned __int64 v11; // rbx
  __int64 v12; // r10
  unsigned __int64 v13; // r11
  __int64 v14; // rcx
  unsigned __int64 v15; // rbx
  __int64 v16; // r10
  __int64 v17; // r11

  v3 = dst;
  if ( (nbytes & 0xFFFFFFF8) != 0
    && (nbytes & 7) == 0
    && ((unsigned __int8)dst & 7) == 0
    && ((unsigned __int8)src & 7) == 0 )
  {
    v4 = (unsigned int)((unsigned __int64)(int)nbytes >> 3) - 1;
    if ( nbytes >= 8 )
    {
      v5 = (unsigned __int64)nbytes >> 3;
      do
      {
        v6 = 8 * v4;
        v4 = (unsigned int)(v4 - 1);
        *(_QWORD *)&v3[v6] = *(_QWORD *)&src[v6];
        --v5;
      }
      while ( v5 );
    }
    v7 = (int)nbytes & 0xFFFFFFFFFFFFFFF8ui64;
    v3 += v7;
    src += v7;
    nbytes = 0;
  }
  if ( (nbytes & 0xFFFFFFFC) != 0
    && (nbytes & 3) == 0
    && ((unsigned __int8)v3 & 3) == 0
    && ((unsigned __int8)src & 3) == 0 )
  {
    v8 = (unsigned int)((unsigned __int64)(int)nbytes >> 2) - 1;
    if ( nbytes >= 4 )
    {
      v9 = (unsigned __int64)nbytes >> 2;
      do
      {
        v10 = 4 * v8;
        v8 = (unsigned int)(v8 - 1);
        *(_DWORD *)&v3[v10] = *(_DWORD *)&src[v10];
        --v9;
      }
      while ( v9 );
    }
    v11 = (int)nbytes & 0xFFFFFFFFFFFFFFFCui64;
    v3 += v11;
    src += v11;
    nbytes = 0;
  }
  if ( (nbytes & 0xFFFFFFFE) != 0
    && (nbytes & 1) == 0
    && ((unsigned __int8)v3 & 1) == 0
    && ((unsigned __int8)src & 1) == 0 )
  {
    v12 = (unsigned int)((unsigned __int64)(int)nbytes >> 1) - 1;
    if ( nbytes >= 2 )
    {
      v13 = (unsigned __int64)nbytes >> 1;
      do
      {
        v14 = 2 * v12;
        v12 = (unsigned int)(v12 - 1);
        *(_WORD *)&v3[v14] = *(_WORD *)&src[v14];
        --v13;
      }
      while ( v13 );
    }
    v15 = (int)nbytes & 0xFFFFFFFFFFFFFFFEui64;
    v3 += v15;
    src += v15;
    nbytes = 0;
  }
  v16 = nbytes - 1;
  if ( nbytes )
  {
    v17 = nbytes;
    do
    {
      v3[v16] = src[v16];
      v16 = (unsigned int)(v16 - 1);
      --v17;
    }
    while ( v17 );
  }
}

// File Line: 107
// RVA: 0xC56B60
void __fastcall hkMemUtil::memMove(_BYTE *dst, _BYTE *src, int nbytes)
{
  if ( dst > src )
  {
    hkMemUtil::memCpyBackwards(dst, src, nbytes);
  }
  else if ( dst < src )
  {
    memmove(dst, src, nbytes);
  }
}

