// File Line: 14
// RVA: 0x12FE290
hkReferencedObject *__fastcall hkTraceStreamcreate()
{
  _QWORD **v0; // rax
  hkReferencedObject *result; // rax

  v0 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v0[11] + 8i64))(v0[11], 48i64);
  if ( !result )
    return 0i64;
  *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
  result->vfptr = (hkBaseObjectVtbl *)&hkTraceStream::`vftable';
  *(_DWORD *)(&result[2].m_referenceCount + 1) = 2147483648;
  result[2].vfptr = 0i64;
  *(_DWORD *)&result[2].m_memSizeAndFlags = 0;
  result[1].vfptr = 0i64;
  *(_DWORD *)&result[1].m_memSizeAndFlags = 0;
  return result;
}

// File Line: 20
// RVA: 0x12FE180
hkSingleton<hkTraceStream> *__fastcall hkSingleton<hkTraceStream>::operator=(hkSingleton<hkTraceStream> *this, hkSingleton<hkTraceStream> *other)
{
  return this;
}

// File Line: 26
// RVA: 0x12FE190
void hkTraceStream::printf(hkTraceStream *this, const char *title, const char *fmt, ...)
{
  int v3; // ebx
  const char *v4; // rsi
  hkTraceStream *v5; // rdi
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  char buf; // [rsp+20h] [rbp-418h]
  const char *v10; // [rsp+450h] [rbp+18h]
  va_list hkargs; // [rsp+458h] [rbp+20h]

  va_start(hkargs, fmt);
  v10 = fmt;
  v3 = 0;
  v4 = title;
  v5 = this;
  if ( this->m_titles.m_size <= 0 )
  {
LABEL_5:
    v6 = ++v5->m_counter;
    if ( v6 == 2051 )
      v5->m_counter = 2051;
    if ( v5->m_stream )
    {
      if ( *fmt == 35 )
      {
        hkString::sprintf(&buf, "%4i\t\t", v6);
        v7 = hkString::strLen(&buf);
        hkOstream::write(v5->m_stream, &buf, v7);
        fmt = v10 + 1;
      }
      hkString::vsnprintf(&buf, 1024, fmt, hkargs);
      v8 = hkString::strLen(&buf);
      hkOstream::write(v5->m_stream, &buf, v8);
    }
  }
  else
  {
    while ( (unsigned int)hkString::strCmp(v5->m_titles.m_data[v3].m_value, v4) )
    {
      if ( ++v3 >= v5->m_titles.m_size )
      {
        fmt = v10;
        goto LABEL_5;
      }
    }
  }
}

// File Line: 71
// RVA: 0x12FE280
void __fastcall hkTraceStream::dontPrintf(hkTraceStream *this, const char *title, const char *fmt)
{
  ;
}

