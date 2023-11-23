// File Line: 295
// RVA: 0x12C9200
__int64 __fastcall getSystemCP(unsigned int codepage)
{
  UINT OEMCP; // eax
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  fSystemSet = 0;
  switch ( codepage )
  {
    case 0xFFFFFFFE:
      fSystemSet = 1;
      OEMCP = GetOEMCP();
LABEL_5:
      codepage = OEMCP;
      break;
    case 0xFFFFFFFD:
      fSystemSet = 1;
      OEMCP = GetACP();
      goto LABEL_5;
    case 0xFFFFFFFC:
      fSystemSet = 1;
      codepage = v4.localeinfo.locinfo->lc_codepage;
      break;
  }
  if ( v4.updated )
    v4.ptd->_ownlocale &= ~2u;
  return codepage;
}

// File Line: 372
// RVA: 0x12C9280
void __fastcall setSBCS(threadmbcinfostruct *ptmbci)
{
  char *mbctype; // rbx
  __int64 v3; // rbp
  unsigned __int16 *mbulinfo; // rdi
  __int64 i; // rcx
  signed __int64 v6; // rdi
  char *mbcasemap; // rcx
  __int64 v8; // rdx

  mbctype = ptmbci->mbctype;
  v3 = 257i64;
  memset(ptmbci->mbctype, 0, sizeof(ptmbci->mbctype));
  mbulinfo = ptmbci->mbulinfo;
  *(_QWORD *)&ptmbci->mbcodepage = 0i64;
  ptmbci->mblocalename = 0i64;
  for ( i = 6i64; i; --i )
    *mbulinfo++ = 0;
  v6 = (char *)&_initialmbcinfo - (char *)ptmbci;
  do
  {
    *mbctype = mbctype[v6];
    ++mbctype;
    --v3;
  }
  while ( v3 );
  mbcasemap = ptmbci->mbcasemap;
  v8 = 256i64;
  do
  {
    *mbcasemap = mbcasemap[v6];
    ++mbcasemap;
    --v8;
  }
  while ( v8 );
}

// File Line: 411
// RVA: 0x12C9310
void __fastcall setSBUpLow(threadmbcinfostruct *ptmbci)
{
  __int64 v2; // rbx
  unsigned int v3; // eax
  char *v4; // rcx
  unsigned __int8 v5; // al
  char *LeadByte; // rdx
  unsigned int v7; // r8d
  __int64 i; // rcx
  unsigned __int16 *v9; // rdx
  char *j; // rcx
  char v11; // al
  unsigned int v12; // edx
  char *v13; // rcx
  char v14; // al
  _cpinfo CPInfo; // [rsp+50h] [rbp-B0h] BYREF
  char SrcStr[256]; // [rsp+70h] [rbp-90h] BYREF
  char DestStr[256]; // [rsp+170h] [rbp+70h] BYREF
  char v18[256]; // [rsp+270h] [rbp+170h] BYREF
  unsigned __int16 CharType[256]; // [rsp+370h] [rbp+270h] BYREF

  v2 = 256i64;
  if ( GetCPInfo(ptmbci->mbcodepage, &CPInfo) )
  {
    v3 = 0;
    v4 = SrcStr;
    do
      *v4++ = v3++;
    while ( v3 < 0x100 );
    v5 = CPInfo.LeadByte[0];
    SrcStr[0] = 32;
    LeadByte = CPInfo.LeadByte;
    while ( v5 )
    {
      v7 = (unsigned __int8)LeadByte[1];
      for ( i = v5; (unsigned int)i <= v7 && (unsigned int)i < 0x100; i = (unsigned int)(i + 1) )
        SrcStr[i] = 32;
      LeadByte += 2;
      v5 = *LeadByte;
    }
    _crtGetStringTypeA(0i64, 1u, SrcStr, 256, CharType, ptmbci->mbcodepage, 0);
    _crtLCMapStringA(0i64, ptmbci->mblocalename, 0x100u, SrcStr, 256, DestStr, 256, ptmbci->mbcodepage, 0);
    _crtLCMapStringA(0i64, ptmbci->mblocalename, 0x200u, SrcStr, 256, v18, 256, ptmbci->mbcodepage, 0);
    v9 = CharType;
    for ( j = &ptmbci->mbctype[1]; ; ++j )
    {
      if ( (*(_BYTE *)v9 & 1) != 0 )
      {
        *j |= 0x10u;
        v11 = j[DestStr - (char *)ptmbci - 25];
      }
      else
      {
        if ( (*(_BYTE *)v9 & 2) == 0 )
        {
          j[256] = 0;
          goto LABEL_18;
        }
        *j |= 0x20u;
        v11 = j[v18 - (char *)ptmbci - 25];
      }
      j[256] = v11;
LABEL_18:
      ++v9;
      if ( !--v2 )
        return;
    }
  }
  v12 = 0;
  v13 = &ptmbci->mbctype[1];
  do
  {
    if ( v12 - 97 + 32 <= 0x19 )
    {
      *v13 |= 0x10u;
      v14 = v12 + 32;
LABEL_25:
      v13[256] = v14;
      goto LABEL_27;
    }
    if ( v12 - 97 <= 0x19 )
    {
      *v13 |= 0x20u;
      v14 = v12 - 32;
      goto LABEL_25;
    }
    v13[256] = 0;
LABEL_27:
    ++v12;
    ++v13;
  }
  while ( v12 < 0x100 );
}

// File Line: 505
// RVA: 0x12C94F4
threadmbcinfostruct *__fastcall _updatetmbcinfo()
{
  _tiddata *v0; // rax
  _tiddata *v1; // rdi
  threadmbcinfostruct *ptmbcinfo; // rbx
  threadmbcinfostruct *pBlock; // [rsp+30h] [rbp+8h]

  v0 = getptd();
  v1 = v0;
  if ( (_globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo )
  {
    ptmbcinfo = v0->ptmbcinfo;
  }
  else
  {
    lock(13);
    ptmbcinfo = v1->ptmbcinfo;
    if ( ptmbcinfo != _ptmbcinfo )
    {
      if ( ptmbcinfo && !_InterlockedDecrement(&ptmbcinfo->refcount) && ptmbcinfo != &_initialmbcinfo )
        free(ptmbcinfo);
      v1->ptmbcinfo = _ptmbcinfo;
      pBlock = _ptmbcinfo;
      _InterlockedIncrement(&_ptmbcinfo->refcount);
      ptmbcinfo = pBlock;
    }
    unlock(13);
  }
  if ( !ptmbcinfo )
    amsg_exit(32);
  return ptmbcinfo;
}

// File Line: 537
// RVA: 0x14521D6
__updatetmbcinfo$fin$0

// File Line: 582
// RVA: 0x12C95B0
__int64 __fastcall setmbcp(unsigned int codepage)
{
  unsigned int v2; // r15d
  _tiddata *v3; // rsi
  threadmbcinfostruct *ptmbcinfo; // rbx
  int SystemCP; // r14d
  threadmbcinfostruct *v6; // rax
  threadmbcinfostruct *v7; // rbx
  int v8; // edi
  threadmbcinfostruct *v9; // rdx
  threadmbcinfostruct *v10; // rcx
  __int64 v11; // rax
  int v12; // eax
  threadmbcinfostruct *v13; // rcx
  int i; // edx
  int j; // edx

  v2 = -1;
  v3 = getptd();
  _updatetmbcinfo();
  ptmbcinfo = v3->ptmbcinfo;
  SystemCP = getSystemCP(codepage);
  if ( SystemCP == ptmbcinfo->mbcodepage )
  {
    return 0;
  }
  else
  {
    v6 = (threadmbcinfostruct *)malloc_crt(0x228ui64);
    v7 = v6;
    v8 = 0;
    if ( v6 )
    {
      v9 = v3->ptmbcinfo;
      v10 = v6;
      if ( (((unsigned __int8)v6 | (unsigned __int8)v9) & 0xF) != 0 )
      {
        memmove(v6, v9, 0x228ui64);
      }
      else
      {
        v11 = 4i64;
        do
        {
          *(_OWORD *)&v10->refcount = *(_OWORD *)&v9->refcount;
          *(_OWORD *)&v10->mbulinfo[2] = *(_OWORD *)&v9->mbulinfo[2];
          *(_OWORD *)&v10->mbctype[8] = *(_OWORD *)&v9->mbctype[8];
          *(_OWORD *)&v10->mbctype[24] = *(_OWORD *)&v9->mbctype[24];
          *(_OWORD *)&v10->mbctype[40] = *(_OWORD *)&v9->mbctype[40];
          *(_OWORD *)&v10->mbctype[56] = *(_OWORD *)&v9->mbctype[56];
          *(_OWORD *)&v10->mbctype[72] = *(_OWORD *)&v9->mbctype[72];
          v10 = (threadmbcinfostruct *)((char *)v10 + 128);
          *(_OWORD *)&v10[-1].mbcasemap[255] = *(_OWORD *)&v9->mbctype[88];
          v9 = (threadmbcinfostruct *)((char *)v9 + 128);
          --v11;
        }
        while ( v11 );
        *(_OWORD *)&v10->refcount = *(_OWORD *)&v9->refcount;
        *(_OWORD *)&v10->mbulinfo[2] = *(_OWORD *)&v9->mbulinfo[2];
        *(_QWORD *)&v10->mbctype[8] = *(_QWORD *)&v9->mbctype[8];
      }
      v7->refcount = 0;
      v12 = setmbcp_nolock(SystemCP, v7);
      v2 = v12;
      if ( v12 )
      {
        if ( v12 == -1 )
        {
          if ( v7 != &_initialmbcinfo )
            free(v7);
          *errno() = 22;
        }
      }
      else
      {
        if ( !_InterlockedDecrement(&v3->ptmbcinfo->refcount) )
        {
          v13 = v3->ptmbcinfo;
          if ( v13 != &_initialmbcinfo )
            free(v13);
        }
        v3->ptmbcinfo = v7;
        _InterlockedIncrement(&v7->refcount);
        if ( (v3->_ownlocale & 2) == 0 && (_globallocalestatus & 1) == 0 )
        {
          lock(13);
          _mbcodepage = v7->mbcodepage;
          _ismbcodepage = v7->ismbcodepage;
          _mblocalename = v7->mblocalename;
          for ( i = 0; i < 5; ++i )
            _mbulinfo[i] = v7->mbulinfo[i];
          for ( j = 0; j < 257; ++j )
            mbctype[j] = v7->mbctype[j];
          while ( v8 < 256 )
          {
            mbcasemap[v8] = v7->mbcasemap[v8];
            ++v8;
          }
          if ( !_InterlockedDecrement(&_ptmbcinfo->refcount) && _ptmbcinfo != &_initialmbcinfo )
            free(_ptmbcinfo);
          _ptmbcinfo = v7;
          _InterlockedIncrement(&v7->refcount);
          unlock(13);
        }
      }
    }
  }
  return v2;
}

// File Line: 694
// RVA: 0x12C980C
__int64 __fastcall setmbcp_nolock(unsigned int codepage, threadmbcinfostruct *ptmbci)
{
  const wchar_t *v3; // rsi
  UINT SystemCP; // edi
  unsigned int v5; // ebp
  code_page_info *v6; // rax
  char *i; // rdx
  unsigned int v8; // r8d
  unsigned int v9; // edi
  char *v10; // rax
  __int64 v11; // rcx
  char *v12; // rax
  __int64 v13; // rcx
  const wchar_t *v14; // rax
  unsigned __int16 *mbulinfo; // rdi
  __int64 j; // rcx
  __int64 v18; // r11
  char *v19; // r14
  __int64 v20; // rbp
  __int64 v21; // r11
  char *v22; // r9
  char *k; // rdx
  unsigned int v24; // r8d
  __int64 v25; // r10
  UINT v26; // edi
  UINT v27; // edi
  UINT v28; // edi
  unsigned __int16 *v29; // rcx
  __int64 v30; // rdx
  _cpinfo CPInfo; // [rsp+20h] [rbp-48h] BYREF

  v3 = 0i64;
  SystemCP = getSystemCP(codepage);
  if ( SystemCP )
  {
    v5 = 0;
    v6 = _rgcode_page_info;
    while ( v6->code_page != SystemCP )
    {
      ++v5;
      ++v6;
      if ( v5 >= 5 )
      {
        if ( SystemCP - 65000 > 1 && IsValidCodePage((unsigned __int16)SystemCP) )
        {
          if ( GetCPInfo(SystemCP, &CPInfo) )
          {
            memset(ptmbci->mbctype, 0, sizeof(ptmbci->mbctype));
            ptmbci->mbcodepage = SystemCP;
            ptmbci->mblocalename = 0i64;
            if ( CPInfo.MaxCharSize <= 1 )
            {
              ptmbci->ismbcodepage = 0;
            }
            else
            {
              for ( i = CPInfo.LeadByte; *i; i += 2 )
              {
                if ( !i[1] )
                  break;
                v8 = (unsigned __int8)*i;
                v9 = (unsigned __int8)i[1];
                if ( v8 <= v9 )
                {
                  v10 = &ptmbci->mbctype[v8 + 1];
                  v11 = v9 - v8 + 1;
                  do
                  {
                    *v10++ |= 4u;
                    --v11;
                  }
                  while ( v11 );
                }
              }
              v12 = &ptmbci->mbctype[2];
              v13 = 254i64;
              do
              {
                *v12++ |= 8u;
                --v13;
              }
              while ( v13 );
              switch ( ptmbci->mbcodepage )
              {
                case 0x3A4:
                  v14 = mb_locale_names[0];
                  break;
                case 0x3A8:
                  v14 = L"zh-CN";
                  break;
                case 0x3B5:
                  v14 = L"ko-KR";
                  break;
                case 0x3B6:
                  v14 = L"zh-TW";
                  break;
                default:
                  v14 = 0i64;
                  break;
              }
              ptmbci->mblocalename = v14;
              ptmbci->ismbcodepage = 1;
            }
            mbulinfo = ptmbci->mbulinfo;
            for ( j = 6i64; j; --j )
              *mbulinfo++ = 0;
            goto LABEL_54;
          }
          if ( fSystemSet )
            goto LABEL_2;
        }
        return 0xFFFFFFFFi64;
      }
    }
    memset(ptmbci->mbctype, 0, sizeof(ptmbci->mbctype));
    v18 = 3i64 * v5;
    v19 = _rgctypeflag;
    v20 = 4i64;
    v21 = 2 * v18;
    v22 = _rgcode_page_info[0].rgrange[v21];
    do
    {
      for ( k = v22; *k; k += 2 )
      {
        if ( !k[1] )
          break;
        v24 = (unsigned __int8)*k;
        if ( v24 <= (unsigned __int8)k[1] )
        {
          v25 = v24 + 1;
          do
          {
            if ( (unsigned int)v25 >= 0x101 )
              break;
            ++v24;
            ptmbci->mbctype[v25] |= *v19;
            v25 = (unsigned int)(v25 + 1);
          }
          while ( v24 <= (unsigned __int8)k[1] );
        }
      }
      v22 += 8;
      ++v19;
      --v20;
    }
    while ( v20 );
    ptmbci->mbcodepage = SystemCP;
    ptmbci->ismbcodepage = 1;
    v26 = SystemCP - 932;
    if ( v26 )
    {
      v27 = v26 - 4;
      if ( v27 )
      {
        v28 = v27 - 13;
        if ( v28 )
        {
          if ( v28 == 1 )
            v3 = L"zh-TW";
        }
        else
        {
          v3 = L"ko-KR";
        }
      }
      else
      {
        v3 = L"zh-CN";
      }
    }
    else
    {
      v3 = mb_locale_names[0];
    }
    ptmbci->mblocalename = v3;
    v29 = ptmbci->mbulinfo;
    v30 = 6i64;
    do
    {
      *v29 = *(unsigned __int16 *)((char *)v29 + (_QWORD)_rgcode_page_info + v21 * 8 - (_QWORD)ptmbci - 8);
      ++v29;
      --v30;
    }
    while ( v30 );
LABEL_54:
    setSBUpLow(ptmbci);
  }
  else
  {
LABEL_2:
    setSBCS(ptmbci);
  }
  return 0i64;
}

// File Line: 851
// RVA: 0x12C91D8
__int64 __fastcall _initmbctable()
{
  if ( !_mbctype_initialized )
  {
    setmbcp(-3);
    _mbctype_initialized = 1;
  }
  return 0i64;
}

