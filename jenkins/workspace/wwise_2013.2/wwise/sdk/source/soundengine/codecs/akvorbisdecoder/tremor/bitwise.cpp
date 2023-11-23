// File Line: 37
// RVA: 0xABCB00
__int64 __fastcall oggpack_look(oggpack_buffer *b, int bits)
{
  unsigned __int8 *headptr; // r11
  int headbit; // r9d
  int v4; // r10d
  int v5; // r8d

  headptr = (unsigned __int8 *)b->headptr;
  headbit = b->headbit;
  v4 = b->headbit + bits;
  v5 = *headptr >> b->headbit;
  if ( v4 > 8 )
  {
    v5 |= headptr[1] << (8 - headbit);
    if ( v4 > 16 )
    {
      v5 |= headptr[2] << (16 - headbit);
      if ( v4 > 24 )
      {
        v5 |= headptr[3] << (24 - headbit);
        if ( v4 > 32 )
        {
          if ( headbit )
            v5 |= headptr[4] << (32 - headbit);
        }
      }
    }
  }
  return mask_3[bits] & v5;
}

// File Line: 67
// RVA: 0xABCAE0
void __fastcall oggpack_adv(oggpack_buffer *b, int bits)
{
  int v2; // edx

  v2 = b->headbit + bits;
  b->headbit = v2 & 7;
  b->headend -= v2 >> 3;
  b->headptr += (__int64)v2 >> 3;
}

// File Line: 78
// RVA: 0xABCBA0
__int64 __fastcall oggpack_read(oggpack_buffer *b, int bits)
{
  __int64 result; // rax
  int v5; // r9d

  result = oggpack_look(b, bits);
  v5 = bits + b->headbit;
  b->headbit = v5 & 7;
  b->headend -= v5 >> 3;
  b->headptr += (__int64)v5 >> 3;
  return result;
}

