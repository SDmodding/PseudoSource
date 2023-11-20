// File Line: 19
// RVA: 0x12BE160
signed __int64 __fastcall wsplitpath_s(const wchar_t *_Path, unsigned __int16 *_Drive, unsigned __int64 _DriveSize, unsigned __int16 *_Dir, unsigned __int64 _DirSize, unsigned __int16 *_Filename, unsigned __int64 _FilenameSize, unsigned __int16 *_Ext, unsigned __int64 _ExtSize)
{
  const wchar_t *v9; // rdi
  unsigned __int16 *v10; // r13
  unsigned __int64 v11; // rsi
  signed int v12; // er9
  unsigned __int16 *v13; // r12
  signed __int64 v14; // rax
  const wchar_t *v15; // rbx
  wchar_t v16; // ax
  signed __int64 v17; // rbp
  const wchar_t *v18; // rsi
  const wchar_t *v19; // rbx
  unsigned __int64 v20; // r9
  unsigned __int64 v21; // r9
  unsigned __int64 v22; // rbx
  unsigned __int64 v23; // rbx
  signed __int64 result; // rax
  unsigned __int64 v25; // [rsp+70h] [rbp+18h]

  v25 = _DriveSize;
  v9 = _Path;
  v10 = _Dir;
  v11 = _DriveSize;
  v12 = 0;
  v13 = _Drive;
  if ( !_Path )
    goto $error_einval;
  if ( _Drive )
  {
    if ( !_DriveSize )
      goto $error_einval;
  }
  else if ( _DriveSize )
  {
$error_einval:
    v12 = 1;
    goto $error_erange;
  }
  if ( v10 )
  {
    if ( !_DirSize )
      goto $error_einval;
  }
  else if ( _DirSize )
  {
    goto $error_einval;
  }
  if ( _Filename )
  {
    if ( !_FilenameSize )
      goto $error_einval;
  }
  else if ( _FilenameSize )
  {
    goto $error_einval;
  }
  if ( _Ext )
  {
    if ( !_ExtSize )
      goto $error_einval;
  }
  else if ( _ExtSize )
  {
    goto $error_einval;
  }
  v14 = 1i64;
  v15 = _Path;
  do
  {
    if ( !*v15 )
      break;
    ++v15;
    --v14;
  }
  while ( v14 );
  if ( *v15 == 58 )
  {
    if ( _Drive )
    {
      if ( _DriveSize < 3 )
        goto $error_erange;
      wcsncpy_s(_Drive, _DriveSize, _Path, 2ui64);
    }
    v9 = v15 + 1;
  }
  else if ( _Drive )
  {
    *_Drive = 0;
  }
  v16 = *v9;
  v17 = 0i64;
  v18 = 0i64;
  v19 = v9;
  if ( !*v9 )
    goto LABEL_75;
  do
  {
    if ( v16 == 47 || v16 == 92 )
    {
      v17 = (signed __int64)(v19 + 1);
    }
    else if ( v16 == 46 )
    {
      v18 = v19;
    }
    ++v19;
    v16 = *v19;
  }
  while ( *v19 );
  if ( v17 )
  {
    if ( v10 )
    {
      v20 = (v17 - (signed __int64)v9) >> 1;
      if ( _DirSize <= v20 )
        goto LABEL_56;
      wcsncpy_s(v10, _DirSize, v9, v20);
    }
    v9 = (const wchar_t *)v17;
  }
  else
  {
LABEL_75:
    if ( v10 )
      *v10 = 0;
  }
  if ( !v18 || v18 < v9 )
  {
    if ( _Filename )
    {
      v23 = v19 - v9;
      if ( _FilenameSize <= v23 )
        goto LABEL_56;
      wcsncpy_s(_Filename, _FilenameSize, v9, v23);
    }
    if ( _Ext )
      *_Ext = 0;
    return 0i64;
  }
  if ( !_Filename )
  {
LABEL_47:
    if ( !_Ext )
      return 0i64;
    v22 = v19 - v18;
    if ( _ExtSize > v22 )
    {
      wcsncpy_s(_Ext, _ExtSize, v18, v22);
      return 0i64;
    }
    goto LABEL_56;
  }
  v21 = v18 - v9;
  if ( _FilenameSize > v21 )
  {
    wcsncpy_s(_Filename, _FilenameSize, v9, v21);
    goto LABEL_47;
  }
LABEL_56:
  v12 = 0;
  v11 = v25;
$error_erange:
  if ( v13 && v11 )
    *v13 = 0;
  if ( v10 && _DirSize > 0 )
    *v10 = 0;
  if ( _Filename && _FilenameSize > 0 )
    *_Filename = 0;
  if ( _Ext && _ExtSize > 0 )
    *_Ext = 0;
  if ( !v9 || v12 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 22i64;
  }
  else
  {
    *errno() = 34;
    result = 34i64;
  }
  return result;
}

