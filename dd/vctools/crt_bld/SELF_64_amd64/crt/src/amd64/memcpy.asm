// File Line: 102
// RVA: 0x12ADDD0
void *__cdecl memmove(void *Dst, const void *Src, size_t Size)
{
  bool v3; // cf
  unsigned __int8 v4; // zf
  void *v5; // r11
  const void *v6; // r10
  void *result; // rax
  size_t v9; // r9
  size_t v10; // r9
  char *v11; // r10
  __int16 v12; // cx
  int v13; // ecx
  int v14; // ecx
  char v15; // al
  __int16 v16; // cx
  int v17; // edx
  __int64 v18; // rcx
  __int64 v19; // rcx
  char v20; // al
  __int16 v21; // cx
  __int64 v22; // rdx
  __int64 v23; // rcx
  char v24; // al
  int v25; // ecx
  __int64 v26; // rdx
  __int16 v27; // ax
  int v28; // ecx
  __int64 v29; // rdx
  char v30; // r8
  __int16 v31; // ax
  int v32; // ecx
  __int64 v33; // rdx
  __int64 v34; // rax
  __int64 v35; // r10
  __int64 v36; // r10
  signed int v37; // eax
  signed int v38; // eax
  __int64 v39; // r10
  __int64 v40; // r10
  __int64 v41; // r9
  __int64 v42; // r10
  __int64 v43; // r10
  size_t v45; // r9
  size_t v46; // r9
  __int64 v47; // rax
  __int64 v48; // r10
  __int64 v49; // r10
  signed int v50; // eax
  signed int v51; // eax
  __int64 v52; // r10
  __int64 v53; // r10
  __int64 v54; // r9
  __int64 v55; // r10
  __int64 v56; // r10
  void *retaddr; // [rsp+0h] [rbp+0h]

  v5 = Dst;
  v6 = Src;
  if ( v3 | v4 )
  {
    v11 = (char *)Dst;
  }
  else
  {
    v3 = Src < Dst;
    _RDX = (_BYTE *)Src - (_BYTE *)Dst;
    if ( !v3 || (signed __int64)Dst >= (signed __int64)((signed __int64)v6 + Size) )
    {
      qmemcpy(Dst, v6, Size);
      return Dst;
    }
    _RCX = (int *)((char *)Dst + Size);
    if ( (unsigned __int8)_RCX & 7 )
    {
      if ( (unsigned __int8)_RCX & 1 )
      {
        _RCX = (int *)((char *)_RCX - 1);
        --Size;
        *(_BYTE *)_RCX = *((_BYTE *)_RCX + _RDX);
      }
      if ( (unsigned __int8)_RCX & 2 )
      {
        _RCX = (int *)((char *)_RCX - 2);
        Size -= 2i64;
        *(_WORD *)_RCX = *(_WORD *)((char *)_RCX + _RDX);
      }
      if ( (unsigned __int8)_RCX & 4 )
      {
        --_RCX;
        Size -= 4i64;
        *_RCX = *(int *)((char *)_RCX + _RDX);
      }
    }
    while ( 1 )
    {
      v45 = Size >> 5;
      if ( !(Size >> 5) )
        break;
      if ( v45 < 0x2000 || _RDX > 0xFFFFFFFFFFFFF000ui64 )
      {
        do
        {
          v47 = *(_QWORD *)((char *)_RCX + _RDX - 8);
          v48 = *(_QWORD *)((char *)_RCX + _RDX - 16);
          _RCX -= 8;
          *((_QWORD *)_RCX + 3) = v47;
          *((_QWORD *)_RCX + 2) = v48;
          v49 = *(_QWORD *)((char *)_RCX + _RDX);
          --v45;
          *((_QWORD *)_RCX + 1) = *(_QWORD *)((char *)_RCX + _RDX + 8);
          *(_QWORD *)_RCX = v49;
        }
        while ( v45 );
        Size &= 0x1Fu;
        break;
      }
      do
      {
        v50 = 32;
        do
        {
          _RCX -= 32;
          __asm
          {
            prefetchnta byte ptr [rdx+rcx]; Prefetch to L1 cache
            prefetchnta byte ptr [rdx+rcx+40h]; Prefetch to L1 cache
          }
          --v50;
        }
        while ( v50 );
        _RCX += 1024;
        v51 = 64;
        do
        {
          v52 = *(_QWORD *)((char *)_RCX + _RDX - 16);
          _mm_stream_si32(_RCX - 2, *(_QWORD *)((char *)_RCX + _RDX - 8));
          _mm_stream_si32(_RCX - 4, v52);
          v53 = *(_QWORD *)((char *)_RCX + _RDX - 32);
          _mm_stream_si32(_RCX - 6, *(_QWORD *)((char *)_RCX + _RDX - 24));
          _mm_stream_si32(_RCX - 8, v53);
          v54 = *(_QWORD *)((char *)_RCX + _RDX - 40);
          v55 = *(_QWORD *)((char *)_RCX + _RDX - 48);
          _RCX -= 16;
          _mm_stream_si32(_RCX + 6, v54);
          _mm_stream_si32(_RCX + 4, v55);
          v56 = *(_QWORD *)((char *)_RCX + _RDX);
          --v51;
          _mm_stream_si32(_RCX + 2, *(_QWORD *)((char *)_RCX + _RDX + 8));
          _mm_stream_si32(_RCX, v56);
        }
        while ( v51 );
        Size -= 4096i64;
      }
      while ( Size >= 0x1000 );
      _InterlockedOr8((volatile signed __int8 *)&retaddr, 0);
    }
    v46 = Size >> 3;
    if ( Size >> 3 )
    {
      do
      {
        _RCX -= 2;
        --v46;
        *(_QWORD *)_RCX = *(_QWORD *)((char *)_RCX + _RDX);
      }
      while ( v46 );
      Size &= 7u;
    }
    if ( !Size )
      return v5;
    Dst = (char *)_RCX - Size;
    v11 = (char *)Dst;
    Src = (char *)Dst + _RDX;
  }
  while ( 2 )
  {
    switch ( Size )
    {
      case 0ui64:
        result = v5;
        break;
      case 1ui64:
        *v11 = *(_BYTE *)Src;
        result = v5;
        break;
      case 2ui64:
        *(_WORD *)v11 = *(_WORD *)Src;
        result = v5;
        break;
      case 3ui64:
        v12 = *(_WORD *)((char *)Src + 1);
        *v11 = *(_BYTE *)Src;
        *(_WORD *)(v11 + 1) = v12;
        result = v5;
        break;
      case 4ui64:
        *(_DWORD *)v11 = *(_DWORD *)Src;
        result = v5;
        break;
      case 5ui64:
        v13 = *(_DWORD *)((char *)Src + 1);
        *v11 = *(_BYTE *)Src;
        *(_DWORD *)(v11 + 1) = v13;
        result = v5;
        break;
      case 6ui64:
        v14 = *(_DWORD *)((char *)Src + 2);
        *(_WORD *)v11 = *(_WORD *)Src;
        *(_DWORD *)(v11 + 2) = v14;
        result = v5;
        break;
      case 7ui64:
        v15 = *(_BYTE *)Src;
        v16 = *(_WORD *)((char *)Src + 1);
        v17 = *(_DWORD *)((char *)Src + 3);
        *v11 = v15;
        *(_WORD *)(v11 + 1) = v16;
        *(_DWORD *)(v11 + 3) = v17;
        result = v5;
        break;
      case 8ui64:
        *(_QWORD *)v11 = *(_QWORD *)Src;
        result = v5;
        break;
      case 9ui64:
        v18 = *(_QWORD *)((char *)Src + 1);
        *v11 = *(_BYTE *)Src;
        *(_QWORD *)(v11 + 1) = v18;
        result = v5;
        break;
      case 0xAui64:
        v19 = *(_QWORD *)((char *)Src + 2);
        *(_WORD *)v11 = *(_WORD *)Src;
        *(_QWORD *)(v11 + 2) = v19;
        result = v5;
        break;
      case 0xBui64:
        v20 = *(_BYTE *)Src;
        v21 = *(_WORD *)((char *)Src + 1);
        v22 = *(_QWORD *)((char *)Src + 3);
        *v11 = v20;
        *(_WORD *)(v11 + 1) = v21;
        *(_QWORD *)(v11 + 3) = v22;
        result = v5;
        break;
      case 0xCui64:
        v23 = *(_QWORD *)((char *)Src + 4);
        *(_DWORD *)v11 = *(_DWORD *)Src;
        *(_QWORD *)(v11 + 4) = v23;
        result = v5;
        break;
      case 0xDui64:
        v24 = *(_BYTE *)Src;
        v25 = *(_DWORD *)((char *)Src + 1);
        v26 = *(_QWORD *)((char *)Src + 5);
        *v11 = v24;
        *(_DWORD *)(v11 + 1) = v25;
        *(_QWORD *)(v11 + 5) = v26;
        result = v5;
        break;
      case 0xEui64:
        v27 = *(_WORD *)Src;
        v28 = *(_DWORD *)((char *)Src + 2);
        v29 = *(_QWORD *)((char *)Src + 6);
        *(_WORD *)v11 = v27;
        *(_DWORD *)(v11 + 2) = v28;
        *(_QWORD *)(v11 + 6) = v29;
        result = v5;
        break;
      case 0xFui64:
        v30 = *(_BYTE *)Src;
        v31 = *(_WORD *)((char *)Src + 1);
        v32 = *(_DWORD *)((char *)Src + 3);
        v33 = *(_QWORD *)((char *)Src + 7);
        *v11 = v30;
        *(_WORD *)(v11 + 1) = v31;
        *(_DWORD *)(v11 + 3) = v32;
        *(_QWORD *)(v11 + 7) = v33;
        result = v5;
        break;
      default:
        if ( (unsigned __int8)Dst & 7 )
        {
          if ( (unsigned __int8)Dst & 1 )
          {
            --Size;
            *(_BYTE *)Dst = *((_BYTE *)Dst + (_QWORD)Src);
            Dst = (char *)Dst + 1;
          }
          if ( (unsigned __int8)Dst & 2 )
          {
            Size -= 2i64;
            *(_WORD *)Dst = *(_WORD *)((char *)Dst + (_QWORD)Src);
            Dst = (char *)Dst + 2;
          }
          if ( (unsigned __int8)Dst & 4 )
          {
            Size -= 4i64;
            *(_DWORD *)Dst = *(_DWORD *)((char *)Dst + (_QWORD)Src);
            Dst = (char *)Dst + 4;
          }
        }
        while ( 1 )
        {
          v9 = Size >> 5;
          if ( !(Size >> 5) )
            break;
          if ( v9 < 0x2000 || (unsigned __int64)Src < 0x1000 )
          {
            do
            {
              v34 = *(_QWORD *)((char *)Dst + (_QWORD)Src);
              v35 = *(_QWORD *)((char *)Dst + (_QWORD)Src + 8);
              Dst = (char *)Dst + 32;
              *((_QWORD *)Dst - 4) = v34;
              *((_QWORD *)Dst - 3) = v35;
              v36 = *(_QWORD *)((char *)Dst + (_QWORD)Src - 8);
              --v9;
              *((_QWORD *)Dst - 2) = *(_QWORD *)((char *)Dst + (_QWORD)Src - 16);
              *((_QWORD *)Dst - 1) = v36;
            }
            while ( v9 );
            Size &= 0x1Fu;
            break;
          }
          do
          {
            v37 = 32;
            do
            {
              __asm
              {
                prefetchnta byte ptr [rdx+rcx]; Prefetch to L1 cache
                prefetchnta byte ptr [rdx+rcx+40h]; Prefetch to L1 cache
              }
              Dst = (char *)Dst + 128;
              --v37;
            }
            while ( v37 );
            Dst = (char *)Dst - 4096;
            v38 = 64;
            do
            {
              v39 = *(_QWORD *)((char *)Dst + (_QWORD)Src + 8);
              _mm_stream_si32((int *)Dst, *(_QWORD *)((char *)Dst + (_QWORD)Src));
              _mm_stream_si32((int *)Dst + 2, v39);
              v40 = *(_QWORD *)((char *)Dst + (_QWORD)Src + 24);
              _mm_stream_si32((int *)Dst + 4, *(_QWORD *)((char *)Dst + (_QWORD)Src + 16));
              _mm_stream_si32((int *)Dst + 6, v40);
              v41 = *(_QWORD *)((char *)Dst + (_QWORD)Src + 32);
              v42 = *(_QWORD *)((char *)Dst + (_QWORD)Src + 40);
              Dst = (char *)Dst + 64;
              _mm_stream_si32((int *)Dst - 8, v41);
              _mm_stream_si32((int *)Dst - 6, v42);
              v43 = *(_QWORD *)((char *)Dst + (_QWORD)Src - 8);
              --v38;
              _mm_stream_si32((int *)Dst - 4, *(_QWORD *)((char *)Dst + (_QWORD)Src - 16));
              _mm_stream_si32((int *)Dst - 2, v43);
            }
            while ( v38 );
            Size -= 4096i64;
          }
          while ( Size >= 0x1000 );
          _InterlockedOr8((volatile signed __int8 *)&retaddr, 0);
        }
        v10 = Size >> 3;
        if ( Size >> 3 )
        {
          do
          {
            *(_QWORD *)Dst = *(_QWORD *)((char *)Dst + (_QWORD)Src);
            Dst = (char *)Dst + 8;
            --v10;
          }
          while ( v10 );
          Size &= 7u;
        }
        if ( Size )
        {
          Src = (char *)Dst + (_QWORD)Src;
          v11 = (char *)Dst;
          continue;
        }
        result = v5;
        break;
    }
    break;
  }
  return result;
}

// File Line: 207
// RVA: 0x12ADEA3
MoveSmall

