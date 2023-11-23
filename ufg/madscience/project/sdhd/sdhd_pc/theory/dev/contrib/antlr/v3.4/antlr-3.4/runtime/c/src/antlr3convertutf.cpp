// File Line: 207
// RVA: 0x25C700
__int64 __fastcall ConvertUTF16toUTF8(
        const unsigned __int16 **sourceStart,
        const unsigned __int16 *sourceEnd,
        char **targetStart,
        char *targetEnd,
        ConversionFlags flags)
{
  const unsigned __int16 *v5; // r11
  char *v6; // r10
  unsigned int i; // ebx
  unsigned int v12; // eax
  const unsigned __int16 *v13; // r9
  int v14; // edx
  unsigned __int16 v15; // cx
  __int64 v16; // r8
  char *v17; // r10
  char v18; // cl
  char v19; // cl
  char v20; // cl
  __int64 result; // rax

  v5 = *sourceStart;
  v6 = *targetStart;
  for ( i = 0; v5 < sourceEnd; v6 = &v17[v16] )
  {
    v12 = *v5;
    v13 = v5++;
    if ( v12 - 55296 > 0x3FF )
    {
      if ( flags == strictConversion && v12 - 56320 <= 0x3FF )
      {
LABEL_31:
        --v5;
        i = 3;
        break;
      }
    }
    else
    {
      if ( v5 >= sourceEnd )
      {
        --v5;
        i = 1;
        break;
      }
      v14 = *v5;
      if ( (unsigned int)(v14 - 56320) > 0x3FF )
      {
        if ( flags == strictConversion )
          goto LABEL_31;
      }
      else
      {
        v12 = v14 + ((v12 - 55287) << 10);
        ++v5;
      }
    }
    if ( v12 < 0x80 )
    {
      v15 = 1;
      goto LABEL_19;
    }
    if ( v12 < 0x800 )
    {
      v15 = 2;
      goto LABEL_19;
    }
    if ( v12 >= 0x10000 )
    {
      if ( v12 < 0x110000 )
      {
        v15 = 4;
        goto LABEL_19;
      }
      v12 = 65533;
    }
    v15 = 3;
LABEL_19:
    v16 = v15;
    v17 = &v6[v15];
    if ( v17 > targetEnd )
    {
      v5 = v13;
      i = 2;
      v6 = &v17[-v15];
      break;
    }
    switch ( v15 )
    {
      case 1u:
        goto LABEL_27;
      case 2u:
        goto LABEL_26;
      case 3u:
        goto LABEL_25;
      case 4u:
        --v17;
        v18 = v12 & 0x3F | 0x80;
        v12 >>= 6;
        *v17 = v18;
LABEL_25:
        --v17;
        v19 = v12 & 0x3F | 0x80;
        v12 >>= 6;
        *v17 = v19;
LABEL_26:
        --v17;
        v20 = v12 & 0x3F | 0x80;
        v12 >>= 6;
        *v17 = v20;
LABEL_27:
        *--v17 = v12 | firstByteMark[v16];
        break;
    }
  }
  *sourceStart = v5;
  result = i;
  *targetStart = v6;
  return result;
}

