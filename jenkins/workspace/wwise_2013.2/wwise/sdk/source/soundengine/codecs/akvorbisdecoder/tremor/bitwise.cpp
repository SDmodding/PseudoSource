// File Line: 37
// RVA: 0xABCB00
__int64 __fastcall oggpack_look(oggpack_buffer *b, int bits)
{
  unsigned __int8 *v2; // r11
  int v3; // er9
  int v4; // er10
  unsigned int v5; // er8

  v2 = (unsigned __int8 *)b->headptr;
  v3 = b->headbit;
  v4 = b->headbit + bits;
  v5 = (unsigned int)*v2 >> b->headbit;
  if ( v4 > 8 )
  {
    v5 |= v2[1] << (8 - v3);
    if ( v4 > 16 )
    {
      v5 |= v2[2] << (16 - v3);
      if ( v4 > 24 )
      {
        v5 |= v2[3] << (24 - v3);
        if ( v4 > 32 )
        {
          if ( v3 )
            v5 |= v2[4] << (32 - v3);
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
  b->headptr += (signed __int64)v2 >> 3;
}

// File Line: 78
// RVA: 0xABCBA0
__int64 __fastcall oggpack_read(oggpack_buffer *b, int bits)
{
  int v2; // ebx
  oggpack_buffer *v3; // rdi
  __int64 result; // rax
  int v5; // er9

  v2 = bits;
  v3 = b;
  result = oggpack_look(b, bits);
  v5 = v2 + v3->headbit;
  v3->headbit = v5 & 7;
  v3->headend -= v5 >> 3;
  v3->headptr += (signed __int64)v5 >> 3;
  return result;
}

