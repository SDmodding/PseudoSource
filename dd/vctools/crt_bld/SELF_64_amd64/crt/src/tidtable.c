// File Line: 58
// RVA: 0x12C3A00
__int64 _get_flsindex()
{
  return _flsindex;
}

// File Line: 88
// RVA: 0x12C3CDC
signed __int64 __fastcall mtinit()
{
  _tiddata *v0; // rax
  _tiddata *v1; // rbx
  DWORD v2; // eax
  signed __int64 result; // rax

  init_pointers();
  if ( mtinitlocks()
    && (_flsindex = _crtFlsAlloc(freefls), _flsindex != -1)
    && (v0 = (_tiddata *)calloc_crt(1ui64, 0x470ui64), (v1 = v0) != 0i64)
    && _crtFlsSetValue(_flsindex, v0) )
  {
    initptd(v1, 0i64);
    v2 = GetCurrentThreadId();
    v1->_thandle = -1i64;
    v1->_tid = v2;
    result = 1i64;
  }
  else
  {
    mtterm();
    result = 0i64;
  }
  return result;
}

// File Line: 160
// RVA: 0x12C3D5C
__int64 mtterm()
{
  if ( _flsindex != -1 )
  {
    _crtFlsFree(_flsindex);
    _flsindex = -1;
  }
  return mtdeletelocks();
}

// File Line: 203
// RVA: 0x12C3C20
void __fastcall initptd(_tiddata *ptd, threadlocaleinfostruct *ptloci)
{
  threadlocaleinfostruct *v2; // rdi
  _tiddata *v3; // rbx

  v2 = ptloci;
  v3 = ptd;
  ptd->_pxcptacttab = XcptActTab;
  ptd->_terrno = 0;
  ptd->_holdrand = 1;
  ptd->_ownlocale = 1;
  ptd->_setloc_data._cachein[0] = 67;
  ptd->_setloc_data._cacheout[0] = 67;
  ptd->ptmbcinfo = &_initialmbcinfo;
  lock(13);
  _InterlockedIncrement(&v3->ptmbcinfo->refcount);
  unlock(13);
  lock(12);
  v3->ptlocinfo = v2;
  if ( !v2 )
    v3->ptlocinfo = _ptlocinfo;
  _addlocaleref(v3->ptlocinfo);
  unlock(12);
}

// File Line: 268
// RVA: 0x12C3B9C
_tiddata *__fastcall getptd_noexit()
{
  DWORD v0; // edi
  _tiddata *v1; // rbx
  _tiddata *v2; // rax
  DWORD v3; // eax

  v0 = GetLastError();
  v1 = (_tiddata *)_crtFlsGetValue(_flsindex);
  if ( !v1 )
  {
    v2 = (_tiddata *)calloc_crt(1ui64, 0x470ui64);
    v1 = v2;
    if ( v2 )
    {
      if ( _crtFlsSetValue(_flsindex, v2) )
      {
        initptd(v1, 0i64);
        v3 = GetCurrentThreadId();
        v1->_thandle = -1i64;
        v1->_tid = v3;
      }
      else
      {
        free(v1);
        v1 = 0i64;
      }
    }
  }
  SetLastError(v0);
  return v1;
}

// File Line: 334
// RVA: 0x12C3B78
_tiddata *__fastcall getptd()
{
  _tiddata *result; // rax

  result = getptd_noexit();
  if ( !result )
    amsg_exit(16);
  return result;
}

// File Line: 368
// RVA: 0x12C3A08
void __fastcall freefls(void *data)
{
  void *v1; // rbx
  void *v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx
  void *v7; // rcx
  void *v8; // rcx
  _XCPT_ACTION *v9; // rcx
  threadmbcinfostruct *v10; // rcx
  threadlocaleinfostruct *v11; // rdi

  if ( data )
  {
    v1 = data;
    v2 = (void *)*((_QWORD *)data + 7);
    if ( v2 )
      free(v2);
    v3 = (void *)*((_QWORD *)v1 + 9);
    if ( v3 )
      free(v3);
    v4 = (void *)*((_QWORD *)v1 + 11);
    if ( v4 )
      free(v4);
    v5 = (void *)*((_QWORD *)v1 + 13);
    if ( v5 )
      free(v5);
    v6 = (void *)*((_QWORD *)v1 + 14);
    if ( v6 )
      free(v6);
    v7 = (void *)*((_QWORD *)v1 + 15);
    if ( v7 )
      free(v7);
    v8 = (void *)*((_QWORD *)v1 + 16);
    if ( v8 )
      free(v8);
    v9 = (_XCPT_ACTION *)*((_QWORD *)v1 + 20);
    if ( v9 != XcptActTab )
      free(v9);
    lock(13);
    v10 = (threadmbcinfostruct *)*((_QWORD *)v1 + 23);
    if ( v10 && !_InterlockedDecrement(&v10->refcount) && v10 != &_initialmbcinfo )
      free(v10);
    unlock(13);
    lock(12);
    v11 = (threadlocaleinfostruct *)*((_QWORD *)v1 + 24);
    if ( v11 )
    {
      _removelocaleref(*((threadlocaleinfostruct **)v1 + 24));
      if ( v11 != _ptlocinfo && v11 != &_initiallocinfo && !v11->refcount )
        _freetlocinfo(v11);
    }
    unlock(12);
    free(v1);
  }
}

// File Line: 411
// RVA: 0x1451F96
_initptd$fin$1

// File Line: 427
// RVA: 0x1451FAF
_initptd$fin$0

// File Line: 458
// RVA: 0x12C3B3C
void __fastcall freeptd(_tiddata *ptd)
{
  _tiddata *v1; // rbx
  DWORD v2; // ecx
  _tiddata *v3; // rax

  v1 = ptd;
  v2 = _flsindex;
  if ( _flsindex != -1 )
  {
    if ( !v1 )
    {
      v3 = (_tiddata *)_crtFlsGetValue(_flsindex);
      v2 = _flsindex;
      v1 = v3;
    }
    _crtFlsSetValue(v2, 0i64);
    freefls(v1);
  }
}

