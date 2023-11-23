// File Line: 19
// RVA: 0x12BE160
__int64 __fastcall wsplitpath_s(
        const wchar_t *_Path,
        char *_Drive,
        unsigned __int64 _DriveSize,
        char *_Dir,
        unsigned __int64 _DirSize,
        unsigned __int16 *_Filename,
        unsigned __int64 _FilenameSize,
        unsigned __int16 *_Ext,
        unsigned __int64 _ExtSize)
{
  const wchar_t *v9; // rdi
  unsigned __int64 v11; // rsi
  int v12; // r9d
  __int64 v14; // rax
  const wchar_t *v15; // rbx
  wchar_t v16; // ax
  const wchar_t *v17; // rbp
  const wchar_t *v18; // rsi
  const wchar_t *v19; // rbx
  unsigned __int64 v20; // r9
  unsigned __int64 v21; // r9
  unsigned __int64 v22; // rbx
  unsigned __int64 v23; // rbx

  v9 = _Path;
  v11 = _DriveSize;
  v12 = 0;
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
  if ( _Dir )
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
    *(_WORD *)_Drive = 0;
  }
  v16 = *v9;
  v17 = 0i64;
  v18 = 0i64;
  v19 = v9;
  if ( !*v9 )
    goto LABEL_40;
  do
  {
    if ( v16 == 47 || v16 == 92 )
    {
      v17 = v19 + 1;
    }
    else if ( v16 == 46 )
    {
      v18 = v19;
    }
    v16 = *++v19;
  }
  while ( *v19 );
  if ( v17 )
  {
    if ( _Dir )
    {
      v20 = v17 - v9;
      if ( _DirSize <= v20 )
        goto LABEL_56;
      wcsncpy_s(_Dir, _DirSize, v9, v20);
    }
    v9 = v17;
  }
  else
  {
LABEL_40:
    if ( _Dir )
      *(_WORD *)_Dir = 0;
  }
  if ( !v18 || v18 < v9 )
  {
    if ( _Filename )
    {
      v23 = v19 - v9;
      if ( _FilenameSize <= v23 )
        goto LABEL_56;
      wcsncpy_s((char *)_Filename, _FilenameSize, v9, v23);
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
      wcsncpy_s((char *)_Ext, _ExtSize, v18, v22);
      return 0i64;
    }
    goto LABEL_56;
  }
  v21 = v18 - v9;
  if ( _FilenameSize > v21 )
  {
    wcsncpy_s((char *)_Filename, _FilenameSize, v9, v21);
    goto LABEL_47;
  }
LABEL_56:
  v12 = 0;
  v11 = _DriveSize;
$error_erange:
  if ( _Drive && v11 )
    *(_WORD *)_Drive = 0;
  if ( _Dir && _DirSize )
    *(_WORD *)_Dir = 0;
  if ( _Filename && _FilenameSize )
    *_Filename = 0;
  if ( _Ext && _ExtSize )
    *_Ext = 0;
  if ( !v9 || v12 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
  else
  {
    *errno() = 34;
    return 34i64;
  }
}

