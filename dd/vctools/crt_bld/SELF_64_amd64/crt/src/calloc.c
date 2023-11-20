// File Line: 46
// RVA: 0x12BC164
void *__fastcall calloc(unsigned __int64 num, unsigned __int64 size)
{
  void *v2; // rbx
  int errno_tmp; // [rsp+40h] [rbp+18h]

  errno_tmp = 0;
  v2 = calloc_impl(num, size, &errno_tmp);
  if ( !v2 && errno_tmp && errno() )
    *errno() = errno_tmp;
  return v2;
}

