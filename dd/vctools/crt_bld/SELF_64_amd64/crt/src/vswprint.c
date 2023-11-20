// File Line: 125
// RVA: 0x12C1D60
int __fastcall vsnwprintf_l(unsigned __int16 *string, unsigned __int64 count, const wchar_t *format, localeinfo_struct *plocinfo, char *ap)
{
  unsigned __int64 v5; // rdi
  const wchar_t *v6; // rsi
  unsigned __int16 *v7; // rbx
  localeinfo_struct *v8; // r14
  int result; // eax
  int v10; // edi
  char *v11; // rax
  _iobuf stream; // [rsp+20h] [rbp-30h]

  stream._ptr = 0i64;
  v5 = count;
  v6 = format;
  v7 = string;
  v8 = plocinfo;
  memset(&stream._cnt, 0, 0x28ui64);
  if ( v6 && (!v5 || v7) )
  {
    stream._flag = 66;
    stream._base = (char *)v7;
    stream._ptr = (char *)v7;
    if ( v5 <= 0x3FFFFFFF )
      stream._cnt = 2 * v5;
    else
      stream._cnt = 0x7FFFFFFF;
    result = woutput_l(&stream, v6, v8, ap);
    v10 = result;
    if ( v7 )
    {
      if ( --stream._cnt < 0 )
      {
        flsbuf(0, &stream);
        v11 = stream._ptr;
      }
      else
      {
        *stream._ptr = 0;
        v11 = stream._ptr++ + 1;
      }
      if ( --stream._cnt < 0 )
        flsbuf(0, &stream);
      else
        *v11 = 0;
      result = v10;
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = -1;
  }
  return result;
}

// File Line: 224
// RVA: 0x12C1D48
int __fastcall vsnwprintf(unsigned __int16 *string, unsigned __int64 count, const wchar_t *format, char *ap)
{
  return vsnwprintf_l(string, count, format, 0i64, ap);
}

