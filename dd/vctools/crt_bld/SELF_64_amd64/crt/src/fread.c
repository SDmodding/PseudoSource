// File Line: 84
// RVA: 0x12B49E8
unsigned __int64 __fastcall fread_s(void *buffer, unsigned __int64 bufferSize, unsigned __int64 elementSize, unsigned __int64 count, _iobuf *stream)
{
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // r15
  unsigned __int64 v7; // rdi
  void *v8; // r14
  unsigned __int64 v9; // rdi

  v5 = count;
  v6 = elementSize;
  v7 = bufferSize;
  v8 = buffer;
  if ( elementSize && count )
  {
    if ( stream )
    {
      lock_file(stream);
      v9 = fread_nolock_s(v8, v7, v6, v5, stream);
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
unsigned __int64 __fastcall fread_nolock_s(void *buffer, unsigned __int64 bufferSize, unsigned __int64 elementSize, unsigned __int64 num, _iobuf *stream)
{
  unsigned __int64 v5; // r14
  unsigned __int64 v6; // rbp
  void *v7; // r12
  _BYTE *v8; // r15
  unsigned __int64 v9; // r13
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // rsi
  unsigned int v13; // ecx
  unsigned __int64 v14; // r15
  __int64 v15; // rax
  _BYTE *v16; // r15
  signed int v17; // er15
  unsigned __int64 v18; // rdx
  unsigned int v19; // er15
  int v20; // eax
  unsigned int v21; // er8
  int v22; // eax
  int v23; // [rsp+60h] [rbp+8h]
  _BYTE *dst; // [rsp+68h] [rbp+10h]
  unsigned __int64 v25; // [rsp+78h] [rbp+20h]

  v25 = num;
  v5 = elementSize;
  v6 = bufferSize;
  v7 = buffer;
  v8 = buffer;
  dst = buffer;
  v9 = bufferSize;
  if ( !elementSize || !num )
    return 0i64;
  if ( !buffer )
    goto LABEL_53;
  if ( !stream || num > 0xFFFFFFFFFFFFFFFFui64 / elementSize )
  {
    if ( bufferSize != -1i64 )
    {
      memset(buffer, 0, bufferSize);
      num = v25;
    }
    if ( !stream || num > 0xFFFFFFFFFFFFFFFFui64 / v5 )
    {
LABEL_53:
      *errno() = 22;
      goto LABEL_5;
    }
  }
  v11 = num * v5;
  v12 = num * v5;
  if ( stream->_flag & 0x10C )
    v13 = stream->_bufsiz;
  else
    v13 = 4096;
  v23 = v13;
  if ( !v11 )
    return num;
  while ( stream->_flag & 0x10C )
  {
    v14 = stream->_cnt;
    if ( !(_DWORD)v14 )
    {
      v8 = dst;
      break;
    }
    if ( (v14 & 0x80000000) != 0i64 )
      goto LABEL_48;
    if ( v12 < v14 )
      LODWORD(v14) = v12;
    if ( (unsigned int)v14 > v9 )
      goto LABEL_45;
    memcpy_s(dst, v9, stream->_ptr, (unsigned int)v14);
    stream->_cnt -= v14;
    v15 = (unsigned int)v14;
    v16 = dst;
    v12 -= v15;
    stream->_ptr += v15;
LABEL_25:
    v13 = v23;
    v8 = &v16[v15];
    v9 -= v15;
LABEL_42:
    dst = v8;
    if ( !v12 )
      return v25;
  }
  if ( v12 >= v13 )
  {
    if ( v13 )
    {
      if ( v12 <= 0x7FFFFFFF )
      {
        v17 = v12;
        v18 = v12 % v13;
      }
      else
      {
        v17 = 0x7FFFFFFF;
        LODWORD(v18) = 0x7FFFFFFF % v13;
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
      goto LABEL_45;
    v20 = fileno(stream);
    v21 = v19;
    v16 = dst;
    LODWORD(v15) = read_nolock(v20, dst, v21);
    if ( !(_DWORD)v15 )
    {
      stream->_flag |= 0x10u;
      return (v11 - v12) / v5;
    }
    if ( (_DWORD)v15 == -1 )
    {
LABEL_48:
      stream->_flag |= 0x20u;
      return (v11 - v12) / v5;
    }
    v15 = (unsigned int)v15;
    v12 -= (unsigned int)v15;
    goto LABEL_25;
  }
  v22 = filbuf(stream);
  if ( v22 == -1 )
    return (v11 - v12) / v5;
  if ( v9 )
  {
    *v8 = v22;
    v13 = stream->_bufsiz;
    --v12;
    ++v8;
    --v9;
    v23 = stream->_bufsiz;
    goto LABEL_42;
  }
LABEL_45:
  if ( v6 != -1i64 )
    memset(v7, 0, v6);
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

