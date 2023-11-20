// File Line: 195
// RVA: 0x12D0678
signed __int64 __fastcall XcptFilter(unsigned int xcptnum, _EXCEPTION_POINTERS *pxcptinfoptrs)
{
  _EXCEPTION_POINTERS *v2; // rsi
  unsigned int v3; // edi
  _tiddata *v4; // rax
  _tiddata *v5; // rbx
  void *v6; // rdx
  unsigned __int64 v7; // rcx
  void (__fastcall *v8)(_QWORD); // r8
  signed __int64 result; // rax
  void *v10; // rbp
  signed __int64 v11; // rdx
  int v12; // edi

  v2 = pxcptinfoptrs;
  v3 = xcptnum;
  v4 = getptd_noexit();
  v5 = v4;
  if ( !v4 )
    return 0i64;
  v6 = v4->_pxcptacttab;
  v7 = (unsigned __int64)v4->_pxcptacttab;
  do
  {
    if ( *(_DWORD *)v7 == v3 )
      break;
    v7 += 16i64;
  }
  while ( v7 < (unsigned __int64)v6 + 192 );
  if ( v7 >= (unsigned __int64)v6 + 192 || *(_DWORD *)v7 != v3 )
    v7 = 0i64;
  if ( !v7 )
    return 0i64;
  v8 = *(void (__fastcall **)(_QWORD))(v7 + 8);
  if ( !v8 )
    return 0i64;
  if ( v8 == (void (__fastcall *)(_QWORD))5 )
  {
    *(_QWORD *)(v7 + 8) = 0i64;
    result = 1i64;
  }
  else
  {
    if ( v8 != (void (__fastcall *)(_QWORD))1 )
    {
      v10 = v4->_tpxcptinfoptrs;
      v4->_tpxcptinfoptrs = v2;
      if ( *(_DWORD *)(v7 + 4) == 8 )
      {
        v11 = 48i64;
        do
        {
          v11 += 16i64;
          *(_QWORD *)((char *)v4->_pxcptacttab + v11 - 8) = 0i64;
        }
        while ( v11 < 192 );
        v12 = v4->_tfpecode;
        switch ( *(_DWORD *)v7 )
        {
          case 0xC000008E:
            v4->_tfpecode = 131;
            break;
          case 0xC0000090:
            v4->_tfpecode = 129;
            break;
          case 0xC0000091:
            v4->_tfpecode = 132;
            break;
          case 0xC0000093:
            v4->_tfpecode = 133;
            break;
          case 0xC000008D:
            v4->_tfpecode = 130;
            break;
          case 0xC000008F:
            v4->_tfpecode = 134;
            break;
          case 0xC0000092:
            v4->_tfpecode = 138;
            break;
          case 0xC00002B5:
            v4->_tfpecode = 141;
            break;
          case 0xC00002B4:
            v4->_tfpecode = 142;
            break;
        }
        ((void (__fastcall *)(signed __int64, _QWORD, void (__fastcall *)(_QWORD), _QWORD))v8)(
          8i64,
          (unsigned int)v4->_tfpecode,
          v8,
          0i64);
        v5->_tfpecode = v12;
      }
      else
      {
        *(_QWORD *)(v7 + 8) = 0i64;
        v8(*(unsigned int *)(v7 + 4));
      }
      v5->_tpxcptinfoptrs = v10;
    }
    result = 0xFFFFFFFFi64;
  }
  return result;
}

