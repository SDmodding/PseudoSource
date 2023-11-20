// File Line: 49
// RVA: 0xC56B90
void __fastcall memCopyBackwards_8_(void *dst, const void *src, int nbytes)
{
  char *v3; // r9
  __int64 v4; // rax
  unsigned __int64 v5; // r8
  signed __int64 v6; // rdx

  v3 = (char *)src;
  v4 = (unsigned int)((unsigned __int64)nbytes >> 3) - 1;
  if ( (unsigned int)nbytes >= 8 )
  {
    v5 = (unsigned __int64)(unsigned int)nbytes >> 3;
    do
    {
      v6 = 8 * v4;
      v4 = (unsigned int)(v4 - 1);
      *(_QWORD *)((char *)dst + v6) = *(_QWORD *)&v3[v6];
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
void __fastcall hkMemUtil::memSet(void *dst, const int c, int n)
{
  memset(dst, c, (unsigned int)n);
}

// File Line: 74
// RVA: 0xC56A00
void __fastcall hkMemUtil::memCpyBackwards(void *dst, const void *src, int nbytes)
{
  _BYTE *v3; // r9
  __int64 v4; // r10
  unsigned __int64 v5; // r11
  signed __int64 v6; // rcx
  unsigned __int64 v7; // rbx
  __int64 v8; // r10
  unsigned __int64 v9; // r11
  signed __int64 v10; // rcx
  unsigned __int64 v11; // rbx
  __int64 v12; // r10
  unsigned __int64 v13; // r11
  signed __int64 v14; // rcx
  unsigned __int64 v15; // rbx
  __int64 v16; // r10
  __int64 v17; // r11

  v3 = dst;
  if ( nbytes & 0xFFFFFFF8 && !(nbytes & 7) && !((unsigned __int8)dst & 7) && !((unsigned __int8)src & 7) )
  {
    v4 = (unsigned int)((unsigned __int64)nbytes >> 3) - 1;
    if ( (unsigned int)nbytes >= 8 )
    {
      v5 = (unsigned __int64)(unsigned int)nbytes >> 3;
      do
      {
        v6 = 8 * v4;
        v4 = (unsigned int)(v4 - 1);
        *(_QWORD *)&v3[v6] = *(_QWORD *)((char *)src + v6);
        --v5;
      }
      while ( v5 );
    }
    v7 = nbytes & 0xFFFFFFFFFFFFFFF8ui64;
    v3 += v7;
    src = (char *)src + v7;
    nbytes = 0;
  }
  if ( nbytes & 0xFFFFFFFC && !(nbytes & 3) && !((unsigned __int8)v3 & 3) && !((unsigned __int8)src & 3) )
  {
    v8 = (unsigned int)((unsigned __int64)nbytes >> 2) - 1;
    if ( (unsigned int)nbytes >= 4 )
    {
      v9 = (unsigned __int64)(unsigned int)nbytes >> 2;
      do
      {
        v10 = 4 * v8;
        v8 = (unsigned int)(v8 - 1);
        *(_DWORD *)&v3[v10] = *(_DWORD *)((char *)src + v10);
        --v9;
      }
      while ( v9 );
    }
    v11 = nbytes & 0xFFFFFFFFFFFFFFFCui64;
    v3 += v11;
    src = (char *)src + v11;
    nbytes = 0;
  }
  if ( nbytes & 0xFFFFFFFE && !(nbytes & 1) && !((unsigned __int8)v3 & 1) && !((unsigned __int8)src & 1) )
  {
    v12 = (unsigned int)((unsigned __int64)nbytes >> 1) - 1;
    if ( (unsigned int)nbytes >= 2 )
    {
      v13 = (unsigned __int64)(unsigned int)nbytes >> 1;
      do
      {
        v14 = 2 * v12;
        v12 = (unsigned int)(v12 - 1);
        *(_WORD *)&v3[v14] = *(_WORD *)((char *)src + v14);
        --v13;
      }
      while ( v13 );
    }
    v15 = nbytes & 0xFFFFFFFFFFFFFFFEui64;
    v3 += v15;
    src = (char *)src + v15;
    nbytes = 0;
  }
  v16 = (unsigned int)(nbytes - 1);
  if ( (unsigned int)nbytes >= 1 )
  {
    v17 = (unsigned int)nbytes;
    do
    {
      v3[v16] = *((_BYTE *)src + v16);
      v16 = (unsigned int)(v16 - 1);
      --v17;
    }
    while ( v17 );
  }
}

// File Line: 107
// RVA: 0xC56B60
void __fastcall hkMemUtil::memMove(void *dst, const void *src, int nbytes)
{
  JUMPOUT(dst, src, hkMemUtil::memCpyBackwards);
  if ( dst < src )
    memmove(dst, src, nbytes);
}

