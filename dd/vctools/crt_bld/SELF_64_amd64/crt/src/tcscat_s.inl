// File Line: 13
// RVA: 0x12B912C
__int64 __fastcall strcat_s(char *_Dst, unsigned __int64 _SizeInBytes, char *_Src)
{
  char *v3; // r9
  int *v4; // rax
  unsigned int v5; // ebx
  __int64 v7; // rcx
  char v8; // al

  v3 = _Dst;
  if ( !_Dst || !_SizeInBytes )
    goto LABEL_5;
  if ( !_Src )
  {
    *_Dst = 0;
LABEL_5:
    v4 = errno();
    v5 = 22;
LABEL_6:
    *v4 = v5;
    invalid_parameter_noinfo();
    return v5;
  }
  do
  {
    if ( !*_Dst )
      break;
    ++_Dst;
    --_SizeInBytes;
  }
  while ( _SizeInBytes );
  if ( !_SizeInBytes )
  {
    *v3 = 0;
    goto LABEL_5;
  }
  v7 = _Dst - _Src;
  do
  {
    v8 = *_Src;
    _Src[v7] = *_Src;
    ++_Src;
    if ( !v8 )
      break;
    --_SizeInBytes;
  }
  while ( _SizeInBytes );
  if ( !_SizeInBytes )
  {
    *v3 = 0;
    v4 = errno();
    v5 = 34;
    goto LABEL_6;
  }
  return 0i64;
}

