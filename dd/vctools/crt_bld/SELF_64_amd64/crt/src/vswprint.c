// File Line: 125
// RVA: 0x12C1D60
int __fastcall vsnwprintf_l(
        char *string,
        unsigned __int64 count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  int v7; // edi
  char *ptr; // rax
  _iobuf stream; // [rsp+20h] [rbp-30h] BYREF

  memset(&stream, 0, sizeof(stream));
  if ( format && (!count || string) )
  {
    stream._flag = 66;
    stream._base = string;
    stream._ptr = string;
    if ( count <= 0x3FFFFFFF )
      stream._cnt = 2 * count;
    else
      stream._cnt = 0x7FFFFFFF;
    result = woutput_l(&stream, format, plocinfo, ap);
    v7 = result;
    if ( string )
    {
      if ( --stream._cnt < 0 )
      {
        flsbuf(0, &stream);
        ptr = stream._ptr;
      }
      else
      {
        *stream._ptr = 0;
        ptr = ++stream._ptr;
      }
      if ( --stream._cnt < 0 )
        flsbuf(0, &stream);
      else
        *ptr = 0;
      return v7;
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

// File Line: 224
// RVA: 0x12C1D48
int __fastcall vsnwprintf(unsigned __int16 *string, unsigned __int64 count, const wchar_t *format, char *ap)
{
  return vsnwprintf_l(string, count, format, 0i64, ap);
}

