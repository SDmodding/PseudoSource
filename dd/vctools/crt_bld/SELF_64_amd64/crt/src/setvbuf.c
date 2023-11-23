// File Line: 50
// RVA: 0x1334248
__int64 __fastcall setvbuf(_iobuf *str, char *buffer, int type, unsigned __int64 size)
{
  char v4; // r15
  unsigned int v7; // edi
  unsigned __int64 v8; // rsi
  int flag; // eax

  v4 = type;
  v7 = 0;
  if ( str && (type & 0xFFFFFFBB) == 0 && type != 68 && ((type & 0xFFFFFFBF) != 0 || size - 2 <= 0x7FFFFFFD) )
  {
    v8 = size & 0xFFFFFFFFFFFFFFFEui64;
    lock_file(str);
    flush(str);
    freebuf(str);
    str->_flag &= 0xFFFFC2F3;
    flag = str->_flag;
    if ( (v4 & 4) != 0 )
    {
      str->_flag = flag | 4;
      buffer = (char *)&str->_charbuf;
      LODWORD(v8) = 2;
    }
    else if ( buffer )
    {
      str->_flag = flag | 0x500;
    }
    else
    {
      buffer = (char *)malloc_crt(v8);
      if ( !buffer )
      {
        ++cflush;
        v7 = -1;
$done_9:
        unlock_file(str);
        return v7;
      }
      str->_flag |= 0x408u;
    }
    str->_bufsiz = v8;
    str->_base = buffer;
    str->_ptr = buffer;
    str->_cnt = 0;
    goto $done_9;
  }
  *errno() = 22;
  invalid_parameter_noinfo();
  return 0xFFFFFFFFi64;
}

// File Line: 150
// RVA: 0x1452429
setvbuf$fin$0

