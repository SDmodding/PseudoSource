// File Line: 50
// RVA: 0x1334248
signed __int64 __fastcall setvbuf(_iobuf *str, char *buffer, int type, unsigned __int64 size)
{
  char v4; // r15
  char *v5; // r14
  _iobuf *v6; // rbx
  unsigned int v7; // edi
  unsigned __int64 v8; // rsi
  int v9; // eax

  v4 = type;
  v5 = buffer;
  v6 = str;
  v7 = 0;
  if ( str && !(type & 0xFFFFFFBB) && type != 68 && (type & 0xFFFFFFBF || size - 2 <= 0x7FFFFFFD) )
  {
    v8 = size & 0xFFFFFFFFFFFFFFFEui64;
    lock_file(str);
    flush(v6);
    freebuf(v6);
    v6->_flag &= 0xFFFFC2F3;
    v9 = v6->_flag;
    if ( v4 & 4 )
    {
      v6->_flag = v9 | 4;
      v5 = (char *)&v6->_charbuf;
      LODWORD(v8) = 2;
    }
    else if ( v5 )
    {
      v6->_flag = v9 | 0x500;
    }
    else
    {
      v5 = (char *)malloc_crt(v8);
      if ( !v5 )
      {
        ++cflush;
        v7 = -1;
$done_9:
        unlock_file(v6);
        return v7;
      }
      v6->_flag |= 0x408u;
    }
    v6->_bufsiz = v8;
    v6->_base = v5;
    v6->_ptr = v5;
    v6->_cnt = 0;
    goto $done_9;
  }
  *errno() = 22;
  invalid_parameter_noinfo();
  return 0xFFFFFFFFi64;
}

// File Line: 150
// RVA: 0x1452429
setvbuf$fin$0

