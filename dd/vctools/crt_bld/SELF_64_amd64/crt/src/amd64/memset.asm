// File Line: 54
// RVA: 0x12B0080
// local variable allocation has failed, the output may be wrong!
void *__cdecl memset(void *Dst, int Val, size_t Size)
{
  _QWORD *v3; // r11
  unsigned int v4; // ecx
  size_t v5; // r9
  unsigned __int64 v6; // r9
  size_t v7; // r9
  size_t i; // r9
  void *retaddr; // [rsp+0h] [rbp+0h] BYREF

  v3 = Dst;
  if ( Size >= 8 )
  {
    *(_QWORD *)&Val = (unsigned __int8)Val;
    if ( _bittest(&_favor, 1u) )
    {
      memset(Dst, Val, Size);
      return v3;
    }
    *(_QWORD *)&Val *= 0x101010101010101i64;
    if ( Size >= 0x40 )
    {
      v4 = -(int)Dst & 7;
      if ( v4 )
      {
        Size -= v4;
        *v3 = *(_QWORD *)&Val;
      }
      Dst = (char *)v3 + v4;
      v5 = Size;
      Size &= 0x3Fu;
      v6 = v5 >> 6;
      if ( v6 )
      {
        if ( v6 >= 0x1C00 )
        {
          do
          {
            _mm_stream_si32((int *)Dst, Val);
            _mm_stream_si32((int *)Dst + 2, Val);
            _mm_stream_si32((int *)Dst + 4, Val);
            Dst = (char *)Dst + 64;
            _mm_stream_si32((int *)Dst - 10, Val);
            _mm_stream_si32((int *)Dst - 8, Val);
            --v6;
            _mm_stream_si32((int *)Dst - 6, Val);
            _mm_stream_si32((int *)Dst - 4, Val);
            _mm_stream_si32((int *)Dst - 2, Val);
          }
          while ( v6 );
          _InterlockedOr8((volatile signed __int8 *)&retaddr, 0);
        }
        else
        {
          do
          {
            *(_QWORD *)Dst = *(_QWORD *)&Val;
            *((_QWORD *)Dst + 1) = *(_QWORD *)&Val;
            *((_QWORD *)Dst + 2) = *(_QWORD *)&Val;
            Dst = (char *)Dst + 64;
            *((_QWORD *)Dst - 5) = *(_QWORD *)&Val;
            *((_QWORD *)Dst - 4) = *(_QWORD *)&Val;
            --v6;
            *((_QWORD *)Dst - 3) = *(_QWORD *)&Val;
            *((_QWORD *)Dst - 2) = *(_QWORD *)&Val;
            *((_QWORD *)Dst - 1) = *(_QWORD *)&Val;
          }
          while ( v6 );
        }
      }
    }
    v7 = Size;
    Size &= 7u;
    for ( i = v7 >> 3; i; --i )
    {
      *(_QWORD *)Dst = *(_QWORD *)&Val;
      Dst = (char *)Dst + 8;
    }
  }
  for ( ; Size; --Size )
  {
    *(_BYTE *)Dst = Val;
    Dst = (char *)Dst + 1;
  }
  return v3;
}

