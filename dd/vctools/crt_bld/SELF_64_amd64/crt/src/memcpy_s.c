// File Line: 47
// RVA: 0x12B2AD0
signed __int64 __fastcall memcpy_s(void *dst, unsigned __int64 sizeInBytes, const void *src, unsigned __int64 count)
{
  unsigned __int64 v4; // rbx
  const void *v5; // rsi
  unsigned __int64 v6; // rdi
  int *v8; // rax
  unsigned int v9; // ebx

  v4 = count;
  v5 = src;
  v6 = sizeInBytes;
  if ( !count )
    return 0i64;
  if ( !dst )
    goto LABEL_15;
  if ( src && sizeInBytes >= count )
  {
    memmove(dst, src, count);
    return 0i64;
  }
  memset(dst, 0, sizeInBytes);
  if ( !v5 )
  {
LABEL_15:
    v8 = errno();
    v9 = 22;
LABEL_5:
    *v8 = v9;
    invalid_parameter_noinfo();
    return v9;
  }
  if ( v6 < v4 )
  {
    v8 = errno();
    v9 = 34;
    goto LABEL_5;
  }
  return 22i64;
}

