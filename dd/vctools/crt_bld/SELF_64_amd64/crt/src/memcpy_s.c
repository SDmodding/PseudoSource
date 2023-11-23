// File Line: 47
// RVA: 0x12B2AD0
__int64 __fastcall memcpy_s(void *dst, size_t sizeInBytes, const void *src, size_t count)
{
  int *v8; // rax
  unsigned int v9; // ebx

  if ( !count )
    return 0i64;
  if ( !dst )
    goto LABEL_4;
  if ( src && sizeInBytes >= count )
  {
    memmove(dst, src, count);
    return 0i64;
  }
  memset(dst, 0, sizeInBytes);
  if ( !src )
  {
LABEL_4:
    v8 = errno();
    v9 = 22;
LABEL_5:
    *v8 = v9;
    invalid_parameter_noinfo();
    return v9;
  }
  if ( sizeInBytes < count )
  {
    v8 = errno();
    v9 = 34;
    goto LABEL_5;
  }
  return 22i64;
}

