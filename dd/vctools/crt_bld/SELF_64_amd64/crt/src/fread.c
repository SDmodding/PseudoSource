// File Line: 84
// RVA: 0x12B49E8
unsigned __int64 __fastcall fread_s(
        _BYTE *buffer,
        size_t bufferSize,
        unsigned __int64 elementSize,
        unsigned __int64 count,
        _iobuf *stream)
{
  unsigned __int64 v9; // rdi

  if ( elementSize && count )
  {
    if ( stream )
    {
      lock_file(stream);
      v9 = fread_nolock_s(buffer, bufferSize, elementSize, count, stream);
      unlock_file(stream);
      return v9;
    }
    if ( bufferSize != -1i64 )
      memset(buffer, 0, bufferSize);
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  return 0i64;
}

// File Line: 111
// RVA: 0x1451DB9
fread_s$fin$0

// File Line: 127
// RVA: 0x12B47A8
unsigned __int64 __fastcall fread_nolock_s(
        _BYTE *buffer,
        size_t bufferSize,
        unsigned __int64 elementSize,
        unsigned __int64 num,
        _iobuf *stream)
{
  _BYTE *v8; // r15
  size_t v9; // r13
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // rsi
  unsigned int bufsiz; // ecx
  unsigned __int64 cnt; // r15
  __int64 v15; // rax
  _BYTE *v16; // r15
  int v17; // r15d
  unsigned __int64 v18; // rdx
  unsigned int v19; // r15d
  int v20; // eax
  unsigned int v21; // r8d
  int v22; // eax
  unsigned int v23; // [rsp+60h] [rbp+8h]
  _BYTE *dst; // [rsp+68h] [rbp+10h]
  unsigned __int64 v25; // [rsp+78h] [rbp+20h]

  v25 = num;
  v8 = buffer;
  dst = buffer;
  v9 = bufferSize;
  if ( !elementSize || !num )
    return 0i64;
  if ( !buffer )
    goto LABEL_4;
  if ( !stream || num > 0xFFFFFFFFFFFFFFFFui64 / elementSize )
  {
    if ( bufferSize != -1i64 )
    {
      memset(buffer, 0, bufferSize);
      num = v25;
    }
    if ( !stream || num > 0xFFFFFFFFFFFFFFFFui64 / elementSize )
    {
LABEL_4:
      *errno() = 22;
      goto LABEL_5;
    }
  }
  v11 = num * elementSize;
  v12 = num * elementSize;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsiz = stream->_bufsiz;
  else
    bufsiz = 4096;
  v23 = bufsiz;
  if ( !v11 )
    return num;
  while ( (stream->_flag & 0x10C) != 0 )
  {
    cnt = stream->_cnt;
    if ( !(_DWORD)cnt )
    {
      v8 = dst;
      break;
    }
    if ( (cnt & 0x80000000) != 0i64 )
      goto LABEL_47;
    if ( v12 < cnt )
      LODWORD(cnt) = v12;
    if ( (unsigned int)cnt > v9 )
      goto LABEL_44;
    memcpy_s(dst, v9, stream->_ptr, (unsigned int)cnt);
    stream->_cnt -= cnt;
    v15 = (unsigned int)cnt;
    v16 = dst;
    v12 -= v15;
    stream->_ptr += v15;
LABEL_24:
    bufsiz = v23;
    v8 = &v16[v15];
    v9 -= v15;
LABEL_41:
    dst = v8;
    if ( !v12 )
      return v25;
  }
  if ( v12 >= bufsiz )
  {
    if ( bufsiz )
    {
      if ( v12 <= 0x7FFFFFFF )
      {
        v17 = v12;
        v18 = v12 % bufsiz;
      }
      else
      {
        v17 = 0x7FFFFFFF;
        LODWORD(v18) = 0x7FFFFFFF % bufsiz;
      }
      v19 = v17 - v18;
    }
    else
    {
      v19 = v12;
      if ( v12 > 0x7FFFFFFF )
        v19 = 0x7FFFFFFF;
    }
    if ( v19 > v9 )
      goto LABEL_44;
    v20 = fileno(stream);
    v21 = v19;
    v16 = dst;
    LODWORD(v15) = read_nolock(v20, dst, v21);
    if ( !(_DWORD)v15 )
    {
      stream->_flag |= 0x10u;
      return (v11 - v12) / elementSize;
    }
    if ( (_DWORD)v15 == -1 )
    {
LABEL_47:
      stream->_flag |= 0x20u;
      return (v11 - v12) / elementSize;
    }
    v15 = (unsigned int)v15;
    v12 -= (unsigned int)v15;
    goto LABEL_24;
  }
  v22 = filbuf(stream);
  if ( v22 == -1 )
    return (v11 - v12) / elementSize;
  if ( v9 )
  {
    *v8 = v22;
    bufsiz = stream->_bufsiz;
    --v12;
    ++v8;
    --v9;
    v23 = bufsiz;
    goto LABEL_41;
  }
LABEL_44:
  if ( bufferSize != -1i64 )
    memset(buffer, 0, bufferSize);
  *errno() = 34;
LABEL_5:
  invalid_parameter_noinfo();
  return 0i64;
}

// File Line: 301
// RVA: 0x12B49C8
unsigned __int64 __fastcall fread(void *buffer, unsigned __int64 elementSize, unsigned __int64 count, _iobuf *stream)
{
  return fread_s(buffer, 0xFFFFFFFFFFFFFFFFui64, elementSize, count, stream);
}

