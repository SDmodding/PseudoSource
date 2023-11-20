// File Line: 30
// RVA: 0xEC455C
void __fastcall OSuite::ZUrl::ZUrl(OSuite::ZUrl *this)
{
  OSuite::ZUrl *v1; // rbx
  OSuite::ZString *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::ZObject};
  v2 = &this->m_sProtocol;
  v2[-1].m_pString = (OSuite::ZString::InternalString *)&OSuite::ZUrl::`vftable{for `OSuite::IHashable};
  OSuite::ZString::ZString(v2);
  OSuite::ZString::ZString(&v1->m_sHost);
  OSuite::ZString::ZString(&v1->m_sFakeHost);
  OSuite::ZString::ZString(&v1->m_sPath);
  OSuite::ZUrlParameters::ZUrlParameters(&v1->m_urlParameters);
  v1->m_nPort = -1;
  v1->m_nHash = 0;
}

// File Line: 38
// RVA: 0xEC4280
void __fastcall OSuite::ZUrl::ZUrl(OSuite::ZUrl *this, OSuite::ZUrl *other)
{
  OSuite::ZUrl *v2; // rdi
  OSuite::ZUrl *v3; // rbx
  OSuite::ZString *v4; // rcx

  v2 = this;
  v3 = other;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::ZObject};
  v4 = &this->m_sProtocol;
  v4[-1].m_pString = (OSuite::ZString::InternalString *)&OSuite::ZUrl::`vftable{for `OSuite::IHashable};
  OSuite::ZString::ZString(v4);
  OSuite::ZString::ZString(&v2->m_sHost);
  OSuite::ZString::ZString(&v2->m_sFakeHost);
  OSuite::ZString::ZString(&v2->m_sPath);
  OSuite::ZUrlParameters::ZUrlParameters(&v2->m_urlParameters);
  OSuite::ZUrl::operator=(v2, v3);
}

// File Line: 46
// RVA: 0xEC44C4
void __fastcall OSuite::ZUrl::ZUrl(OSuite::ZUrl *this, OSuite::ZString *sPath)
{
  OSuite::ZUrl *v2; // rdi
  OSuite::ZString *v3; // rbx
  OSuite::ZString *v4; // rcx
  const char *v5; // rax
  OSuite::ZUrl result; // [rsp+20h] [rbp-E8h]

  v2 = this;
  v3 = sPath;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::ZObject};
  v4 = &this->m_sProtocol;
  v4[-1].m_pString = (OSuite::ZString::InternalString *)&OSuite::ZUrl::`vftable{for `OSuite::IHashable};
  OSuite::ZString::ZString(v4);
  OSuite::ZString::ZString(&v2->m_sHost);
  OSuite::ZString::ZString(&v2->m_sFakeHost);
  OSuite::ZString::ZString(&v2->m_sPath);
  OSuite::ZUrlParameters::ZUrlParameters(&v2->m_urlParameters);
  v5 = OSuite::ZString::c_str(v3);
  OSuite::ZUrl::Parse(&result, v5);
  OSuite::ZUrl::operator=(v2, &result);
  OSuite::ZUrl::~ZUrl(&result);
}

// File Line: 55
// RVA: 0xEC42EC
void __fastcall OSuite::ZUrl::ZUrl(OSuite::ZUrl *this, OSuite::ZUrl *that, OSuite::ZString *sPath)
{
  OSuite::ZUrl *v3; // rbx
  OSuite::ZString *v4; // rdi
  OSuite::ZString *v5; // rcx
  OSuite::ZUrl *v6; // rsi
  const char *v7; // rax
  int v8; // eax
  OSuite::ZString *v9; // rax
  const char *v10; // rax
  OSuite::ZString *v11; // rcx
  OSuite::ZString *v12; // rax
  OSuite::ZString *v13; // rax
  const char *v14; // rax
  const char *v15; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-128h]
  OSuite::ZString v17; // [rsp+38h] [rbp-110h]
  OSuite::ZUrl other; // [rsp+50h] [rbp-F8h]

  v3 = this;
  v4 = sPath;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::ZObject};
  v5 = &this->m_sProtocol;
  v5[-1].m_pString = (OSuite::ZString::InternalString *)&OSuite::ZUrl::`vftable{for `OSuite::IHashable};
  v6 = that;
  OSuite::ZString::ZString(v5);
  OSuite::ZString::ZString(&v3->m_sHost);
  OSuite::ZString::ZString(&v3->m_sFakeHost);
  OSuite::ZString::ZString(&v3->m_sPath);
  OSuite::ZUrlParameters::ZUrlParameters(&v3->m_urlParameters);
  v3->m_nHash = 0;
  if ( OSuite::ZString::StartsWith(v4, "http://") || OSuite::ZString::StartsWith(v4, "https://") )
  {
    v15 = OSuite::ZString::c_str(v4);
    OSuite::ZUrl::Parse(&other, v15);
    OSuite::ZUrl::operator=(v3, &other);
    OSuite::ZUrl::~ZUrl(&other);
  }
  else
  {
    OSuite::ZString::operator=(&v3->m_sProtocol, &v6->m_sProtocol);
    OSuite::ZString::operator=(&v3->m_sFakeHost, &v6->m_sFakeHost);
    OSuite::ZString::operator=(&v3->m_sHost, &v6->m_sHost);
    v3->m_nPort = v6->m_nPort;
    if ( OSuite::ZString::CharAt(v4, 0i64) == 47 )
    {
      v7 = OSuite::ZString::c_str(v4);
      OSuite::ZUrl::ParsePath(v3, v7);
    }
    else
    {
      v8 = OSuite::ZString::LastIndexOf(&v3->m_sPath, 47);
      if ( v8 == -1 )
      {
        v9 = OSuite::operator+(&result, "/", v4);
        v10 = OSuite::ZString::c_str(v9);
        OSuite::ZUrl::ParsePath(v3, v10);
        v11 = &result;
      }
      else
      {
        v12 = OSuite::ZString::Slice(&v3->m_sPath, &v17, 0i64, v8 + 1);
        v13 = OSuite::ZString::operator+(v12, &result, v4);
        v14 = OSuite::ZString::c_str(v13);
        OSuite::ZUrl::ParsePath(v3, v14);
        OSuite::ZString::~ZString(&result);
        v11 = &v17;
      }
      OSuite::ZString::~ZString(v11);
    }
  }
}

// File Line: 92
// RVA: 0xEC45C0
void __fastcall OSuite::ZUrl::~ZUrl(OSuite::ZUrl *this)
{
  OSuite::ZUrl *v1; // rbx
  OSuite::ZUrlParameters *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::ZObject};
  v2 = &this->m_urlParameters;
  v2[-2].m_arrayParameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::IHashable};
  OSuite::ZUrlParameters::~ZUrlParameters(v2);
  OSuite::ZString::~ZString(&v1->m_sPath);
  OSuite::ZString::~ZString(&v1->m_sFakeHost);
  OSuite::ZString::~ZString(&v1->m_sHost);
  OSuite::ZString::~ZString(&v1->m_sProtocol);
}

// File Line: 97
// RVA: 0xEC4610
OSuite::ZUrl *__fastcall OSuite::ZUrl::operator=(OSuite::ZUrl *this, OSuite::ZUrl *other)
{
  OSuite::ZUrl *v2; // rdi
  OSuite::ZUrl *v3; // rbx

  v2 = other;
  v3 = this;
  if ( this != other )
  {
    OSuite::ZString::operator=(&this->m_sProtocol, &other->m_sProtocol);
    OSuite::ZString::operator=(&v3->m_sFakeHost, &v2->m_sFakeHost);
    OSuite::ZString::operator=(&v3->m_sHost, &v2->m_sHost);
    OSuite::ZString::operator=(&v3->m_sPath, &v2->m_sPath);
    v3->m_nPort = v2->m_nPort;
    OSuite::ZUrlParameters::operator=(&v3->m_urlParameters, &v2->m_urlParameters);
    v3->m_nHash = v2->m_nHash;
  }
  return v3;
}

// File Line: 120
// RVA: 0xEC4748
char __fastcall OSuite::ZUrl::operator bool(OSuite::ZUrl *this)
{
  OSuite::ZUrl *v1; // rdi
  char v2; // bl

  v1 = this;
  v2 = 0;
  if ( OSuite::ZString::operator bool(&this->m_sProtocol)
    && OSuite::ZString::operator bool(&v1->m_sHost)
    && OSuite::ZString::operator bool(&v1->m_sPath)
    && v1->m_nPort != -1 )
  {
    v2 = 1;
  }
  return v2;
}

// File Line: 126
// RVA: 0xEC468C
char __fastcall OSuite::ZUrl::operator==(OSuite::ZUrl *this, OSuite::ZUrl *other)
{
  OSuite::ZUrl *v2; // rbp
  OSuite::ZUrl *v3; // rsi
  int v4; // ebx
  char v6; // bl

  v2 = this;
  v3 = other;
  v4 = ((__int64 (*)(void))this->vfptr->ComputeHash)();
  if ( v4 != v3->vfptr->ComputeHash((OSuite::IHashable *)&v3->vfptr) )
    return 0;
  v6 = 0;
  if ( OSuite::ZString::operator==(&v2->m_sProtocol, &v3->m_sProtocol)
    && OSuite::ZString::operator==(&v2->m_sFakeHost, &v3->m_sFakeHost)
    && OSuite::ZString::operator==(&v2->m_sHost, &v3->m_sHost)
    && OSuite::ZString::operator==(&v2->m_sPath, &v3->m_sPath)
    && v2->m_nPort == v3->m_nPort
    && OSuite::ZUrlParameters::operator==(&v2->m_urlParameters, &v3->m_urlParameters) )
  {
    v6 = 1;
  }
  return v6;
}

// File Line: 142
// RVA: 0xEC479C
bool __fastcall OSuite::ZUrl::operator<(OSuite::ZUrl *this, OSuite::ZUrl *other)
{
  OSuite::ZUrl *v2; // rbp
  OSuite::ZUrl *v3; // rsi
  bool result; // al
  OSuite::ZString *v5; // rax
  OSuite::ZString *v6; // rdi
  bool v7; // bl
  OSuite::ZString *v8; // rdx
  OSuite::ZString *v9; // rcx
  OSuite::ZString *v10; // rax
  OSuite::ZString *v11; // rdi
  bool v12; // bl
  OSuite::ZString *v13; // rax
  OSuite::ZString *v14; // rdi
  bool v15; // bl
  OSuite::ZString *v16; // rax
  OSuite::ZString *v17; // rdi
  bool v18; // bl
  int v19; // eax
  int v20; // ecx
  OSuite::ZString v21; // [rsp+20h] [rbp-48h]

  v2 = other;
  v3 = this;
  if ( this == other )
    return 0;
  OSuite::ZString::ZString(&v21, &other->m_sProtocol);
  v6 = v5;
  v7 = OSuite::ZString::operator==(&v3->m_sProtocol, v5) == 0;
  OSuite::ZString::~ZString(v6);
  if ( v7 )
  {
    v8 = &v2->m_sProtocol;
    v9 = &v3->m_sProtocol;
    return OSuite::ZString::operator<(v9, v8);
  }
  OSuite::ZString::ZString(&v21, &v2->m_sFakeHost);
  v11 = v10;
  v12 = OSuite::ZString::operator==(&v3->m_sFakeHost, v10) == 0;
  OSuite::ZString::~ZString(v11);
  if ( v12 )
  {
    v8 = &v2->m_sFakeHost;
    v9 = &v3->m_sFakeHost;
    return OSuite::ZString::operator<(v9, v8);
  }
  OSuite::ZString::ZString(&v21, &v2->m_sHost);
  v14 = v13;
  v15 = OSuite::ZString::operator==(&v3->m_sHost, v13) == 0;
  OSuite::ZString::~ZString(v14);
  if ( v15 )
  {
    v8 = &v2->m_sHost;
    v9 = &v3->m_sHost;
    return OSuite::ZString::operator<(v9, v8);
  }
  OSuite::ZString::ZString(&v21, &v2->m_sPath);
  v17 = v16;
  v18 = OSuite::ZString::operator==(&v3->m_sPath, v16) == 0;
  OSuite::ZString::~ZString(v17);
  if ( v18 )
  {
    v8 = &v2->m_sPath;
    v9 = &v3->m_sPath;
    return OSuite::ZString::operator<(v9, v8);
  }
  v19 = v3->m_nPort;
  v20 = v2->m_nPort;
  if ( v19 == v20 )
    result = OSuite::ZUrlParameters::operator<(&v3->m_urlParameters, &v2->m_urlParameters);
  else
    result = v19 < v20;
  return result;
}

// File Line: 198
// RVA: 0xEC4C5C
OSuite::ZString *__fastcall OSuite::ZUrl::GetPath(OSuite::ZUrl *this)
{
  return &this->m_sPath;
}

// File Line: 208
// RVA: 0xEC4C64
OSuite::ZString *__fastcall OSuite::ZUrl::GetPathAndParameters(OSuite::ZUrl *this, OSuite::ZString *result)
{
  OSuite::ZUrl *v2; // rdi
  OSuite::ZString *v3; // rsi
  unsigned __int64 v4; // rax
  OSuite::ZString *v5; // rax
  OSuite::ZString resulta; // [rsp+20h] [rbp-58h]
  OSuite::ZStringBuilder v8; // [rsp+38h] [rbp-40h]

  v8.m_Chars.m_pList = 0i64;
  v2 = this;
  v3 = result;
  v4 = OSuite::ZString::Count(&this->m_sPath);
  OSuite::ZStringBuilder::ZStringBuilder(&v8, v4);
  OSuite::ZStringBuilder::Append(&v8, &v2->m_sPath);
  v5 = OSuite::ZUrlParameters::ToString(&v2->m_urlParameters, &resulta);
  OSuite::ZStringBuilder::Append(&v8, v5);
  OSuite::ZString::~ZString(&resulta);
  OSuite::ZStringBuilder::ToString(&v8, &resulta);
  OSuite::ZString::ZString(v3, &resulta);
  OSuite::ZString::~ZString(&resulta);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v8);
  return v3;
}

// File Line: 223
// RVA: 0xEC4D2C
__int64 __fastcall OSuite::ZUrl::GetPort(OSuite::ZUrl *this)
{
  return (unsigned int)this->m_nPort;
}

// File Line: 234
// RVA: 0xEC5158
OSuite::ZString *__fastcall OSuite::ZUrl::ToString(OSuite::ZUrl *this, OSuite::ZString *result, bool bIncludeFakeHost)
{
  bool v3; // si
  OSuite::ZString *v4; // rdi
  OSuite::ZUrl *v5; // rbx
  OSuite::ZString *v6; // rax
  OSuite::ZString resulta; // [rsp+20h] [rbp-50h]
  OSuite::ZStringBuilder v9; // [rsp+38h] [rbp-38h]

  v3 = bIncludeFakeHost;
  v4 = result;
  v5 = this;
  if ( OSuite::ZUrl::operator bool(this) )
  {
    v9.m_Chars.m_pList = 0i64;
    OSuite::ZStringBuilder::ZStringBuilder(&v9, 0x28ui64);
    OSuite::ZStringBuilder::Append(&v9, &v5->m_sProtocol);
    OSuite::ZStringBuilder::Append(&v9, "://", 3ui64);
    if ( v3 && OSuite::ZString::operator bool(&v5->m_sFakeHost) )
    {
      OSuite::ZStringBuilder::Append(&v9, &v5->m_sFakeHost);
      OSuite::ZStringBuilder::Append(&v9, 33);
    }
    OSuite::ZStringBuilder::Append(&v9, &v5->m_sHost);
    OSuite::ZStringBuilder::Append(&v9, 58);
    OSuite::ZStringBuilder::AppendInt(&v9, v5->m_nPort);
    v6 = OSuite::ZUrl::GetPathAndParameters(v5, &resulta);
    OSuite::ZStringBuilder::Append(&v9, v6);
    OSuite::ZString::~ZString(&resulta);
    OSuite::ZStringBuilder::ToString(&v9, &resulta);
    OSuite::ZString::ZString(v4, &resulta);
    OSuite::ZString::~ZString(&resulta);
    OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v9);
  }
  else
  {
    OSuite::ZString::ZString(v4);
  }
  return v4;
}

// File Line: 258
// RVA: 0xEC4B50
__int64 __fastcall OSuite::ZUrl::ComputeHash(OSuite::ZUrl *this)
{
  signed __int64 v1; // rbx
  OSuite::ZUrl *v2; // rdi
  unsigned int v3; // esi
  signed __int64 v4; // rcx
  unsigned int v5; // eax
  unsigned int v6; // esi
  signed __int64 v7; // rcx
  unsigned int v8; // eax
  unsigned int v9; // ebp
  signed __int64 v10; // rcx
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // eax
  unsigned int v16; // eax

  v1 = 0i64;
  v2 = this;
  if ( !HIDWORD(this->m_urlParameters.m_arrayParameters.m_Comparer.vfptr) )
  {
    v3 = OSuite::FComputeHashBegin((_exception *)this);
    if ( v2 == (OSuite::ZUrl *)-8i64 )
      v4 = 0i64;
    else
      v4 = (signed __int64)&v2->m_sProtocol;
    v5 = (*(__int64 (**)(void))(*(_QWORD *)v4 + 8i64))();
    v6 = OSuite::FComputeHashAdd(v3, v5);
    if ( v2 == (OSuite::ZUrl *)-32i64 )
      v7 = 0i64;
    else
      v7 = (signed __int64)&v2->m_sHost;
    v8 = (*(__int64 (**)(void))(*(_QWORD *)v7 + 8i64))();
    v9 = OSuite::FComputeHashAdd(v6, v8);
    if ( OSuite::ZString::operator bool((OSuite::ZString *)((char *)&v2->m_sHost + 16)) )
    {
      v10 = (signed __int64)&v2->m_sFakeHost;
      if ( v2 == (OSuite::ZUrl *)-56i64 )
        v10 = 0i64;
      v11 = (*(__int64 (**)(void))(*(_QWORD *)v10 + 8i64))();
      v9 = OSuite::FComputeHashAdd(v9, v11);
    }
    if ( v2 != (OSuite::ZUrl *)-80i64 )
      v1 = (signed __int64)&v2->m_sPath;
    v12 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v1 + 8i64))(v1);
    v13 = OSuite::FComputeHashAdd(v9, v12);
    v14 = OSuite::FComputeHashAdd(v13, (unsigned int)v2->m_urlParameters.m_arrayParameters.m_Comparer.vfptr);
    v15 = ((__int64 (*)(void))v2->m_urlParameters.vfptr[1].__vecDelDtor)();
    v16 = OSuite::FComputeHashAdd(v14, v15);
    HIDWORD(v2->m_urlParameters.m_arrayParameters.m_Comparer.vfptr) = OSuite::FComputeHashEnd(v16) | 0x80000000;
  }
  return HIDWORD(v2->m_urlParameters.m_arrayParameters.m_Comparer.vfptr);
}

// File Line: 300
// RVA: 0xEC4DE8
OSuite::ZUrl *__fastcall OSuite::ZUrl::Parse(OSuite::ZUrl *result, OSuite::ZString *sUrl)
{
  OSuite::ZUrl *v2; // rbx
  const char *v3; // rax

  v2 = result;
  v3 = OSuite::ZString::c_str(sUrl);
  OSuite::ZUrl::Parse(v2, v3);
  return v2;
}

// File Line: 311
// RVA: 0xEC4E10
OSuite::ZUrl *__fastcall OSuite::ZUrl::Parse(OSuite::ZUrl *result, const char *pszUrl)
{
  const char *v2; // rbx
  OSuite::ZUrl *v3; // rdi

  v2 = pszUrl;
  v3 = result;
  result->m_sProtocol.m_pString = 0i64;
  result->m_sHost.m_pString = 0i64;
  result->m_sFakeHost.m_pString = 0i64;
  result->m_sPath.m_pString = 0i64;
  result->m_urlParameters.m_parameters.m_pTop = 0i64;
  result->m_urlParameters.m_arrayParameters.m_pTop = 0i64;
  OSuite::ZUrl::ZUrl(result);
  OSuite::ZUrl::ParseUrl(v3, v2);
  return v3;
}

// File Line: 355
// RVA: 0xEC4ECC
void __fastcall OSuite::ZUrl::ParseUrl(OSuite::ZUrl *this, const char *pszUrl)
{
  const char *v2; // rsi
  OSuite::ZUrl *v3; // rdi
  char *v4; // rax
  char *v5; // rbx
  OSuite::ZString *v6; // rax
  OSuite::ZString *v7; // rax
  OSuite::ZString *v8; // rax
  char v9; // cl
  const char *v10; // rbx
  signed __int64 v11; // r12
  OSuite::ZString *v12; // rax
  char v13; // al
  OSuite::ZString *v14; // rax
  char v15; // al
  int v16; // ecx
  int v17; // ecx
  OSuite::ZString *v18; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-30h]
  OSuite::ZString v20; // [rsp+38h] [rbp-18h]

  this->m_nHash = 0;
  v2 = pszUrl;
  v3 = this;
  v4 = strstr(pszUrl, "://");
  v5 = v4;
  if ( v4 )
  {
    OSuite::ZString::ZString(&v20, v2, v4 - v2);
    v7 = OSuite::ZString::ToLower(v6, &result);
    OSuite::ZString::operator=(&v3->m_sProtocol, v7);
    OSuite::ZString::~ZString(&result);
    OSuite::ZString::~ZString(&v20);
    v2 = v5 + 3;
    if ( !OSuite::ZString::operator==(&v3->m_sProtocol, "http") )
    {
      if ( OSuite::ZString::operator==(&v3->m_sProtocol, "https") )
        v3->m_nPort = 443;
      goto LABEL_7;
    }
  }
  else
  {
    OSuite::ZString::ZString(&v20, "http", 4ui64);
    OSuite::ZString::operator=(&v3->m_sProtocol, v8);
    OSuite::ZString::~ZString(&v20);
  }
  v3->m_nPort = 80;
LABEL_7:
  v9 = *v2;
  v10 = v2;
  v11 = -8935000923214708736i64;
  while ( v9 && ((unsigned __int8)v9 > 0x3Fu || !_bittest64(&v11, v9)) )
  {
    if ( v9 == 33 )
      goto LABEL_14;
    v9 = *++v10;
  }
  if ( *v10 != 33 )
    goto LABEL_19;
LABEL_14:
  OSuite::ZString::ZString(&v20, v2, v10 - v2);
  OSuite::ZString::operator=(&v3->m_sFakeHost, v12);
  OSuite::ZString::~ZString(&v20);
  v2 = ++v10;
  while ( 1 )
  {
    v13 = *v10;
    if ( !*v10 || (unsigned __int8)v13 <= 0x3Fu && _bittest64(&v11, v13) )
      break;
    ++v10;
  }
LABEL_19:
  OSuite::ZString::ZString(&v20, v2, v10 - v2);
  OSuite::ZString::operator=(&v3->m_sHost, v14);
  OSuite::ZString::~ZString(&v20);
  if ( *v10 == 58 )
  {
    v3->m_nPort = 0;
    v15 = *++v10;
    if ( !*v10 )
    {
LABEL_24:
      OSuite::ZString::ZString(&v20, "/", 1ui64);
      OSuite::ZString::operator=(&v3->m_sPath, v18);
      OSuite::ZString::~ZString(&v20);
      OSuite::ZUrlParameters::Clear(&v3->m_urlParameters);
      return;
    }
    do
    {
      if ( !((v15 - 47) & 0xEF) )
        break;
      v16 = 10 * v3->m_nPort;
      v3->m_nPort = v16;
      v17 = *v10++ + v16 - 48;
      v3->m_nPort = v17;
      v15 = *v10;
    }
    while ( *v10 );
  }
  if ( !*v10 )
    goto LABEL_24;
  OSuite::ZUrl::ParsePath(v3, v10);
}

// File Line: 424
// RVA: 0xEC4E60
void __fastcall OSuite::ZUrl::ParsePath(OSuite::ZUrl *this, const char *pszUrl)
{
  char v2; // al
  OSuite::ZUrl *v3; // rdi
  const char *v4; // rbx
  OSuite::ZString *v5; // rax
  OSuite::ZString v6; // [rsp+20h] [rbp-28h]

  this->m_nHash = 0;
  v2 = *pszUrl;
  v3 = this;
  v4 = pszUrl;
  while ( v2 && v2 != 63 )
    v2 = *++v4;
  OSuite::ZString::ZString(&v6, pszUrl, v4 - pszUrl);
  OSuite::ZString::operator=(&v3->m_sPath, v5);
  OSuite::ZString::~ZString(&v6);
  if ( *v4 == 63 )
    OSuite::ZUrlParameters::Parse(&v3->m_urlParameters, v4 + 1);
}

