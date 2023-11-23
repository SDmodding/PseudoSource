// File Line: 50
// RVA: 0x12D8048
__int64 __fastcall fptostr(char *buf, unsigned __int64 sizeInBytes, int digits, _strflt *pflt)
{
  char *mantissa; // rcx
  int *v6; // rax
  unsigned int v7; // ebx
  int v9; // eax
  char *v10; // rax
  char v11; // dl
  size_t v12; // rax

  mantissa = pflt->mantissa;
  if ( !buf || !sizeInBytes )
  {
    v6 = errno();
    v7 = 22;
LABEL_3:
    *v6 = v7;
    invalid_parameter_noinfo();
    return v7;
  }
  v9 = 0;
  *buf = 0;
  if ( digits > 0 )
    v9 = digits;
  if ( sizeInBytes <= v9 + 1 )
  {
    v6 = errno();
    v7 = 34;
    goto LABEL_3;
  }
  *buf = 48;
  v10 = buf + 1;
  while ( digits > 0 )
  {
    if ( *mantissa )
      v11 = *mantissa++;
    else
      v11 = 48;
    *v10++ = v11;
    --digits;
  }
  *v10 = 0;
  if ( digits >= 0 && *mantissa >= 53 )
  {
    while ( *--v10 == 57 )
      *v10 = 48;
    ++*v10;
  }
  if ( *buf == 49 )
  {
    ++pflt->decpt;
  }
  else
  {
    v12 = strlen(buf + 1);
    memmove(buf, buf + 1, v12 + 1);
  }
  return 0i64;
}

