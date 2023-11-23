// File Line: 30
// RVA: 0xEC455C
void __fastcall OSuite::ZUrl::ZUrl(OSuite::ZUrl *this)
{
  OSuite::ZString *p_m_sProtocol; // rcx

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::ZObject};
  p_m_sProtocol = &this->m_sProtocol;
  p_m_sProtocol[-1].m_pString = (OSuite::ZString::InternalString *)&OSuite::ZUrl::`vftable{for `OSuite::IHashable};
  OSuite::ZString::ZString(p_m_sProtocol);
  OSuite::ZString::ZString(&this->m_sHost);
  OSuite::ZString::ZString(&this->m_sFakeHost);
  OSuite::ZString::ZString(&this->m_sPath);
  OSuite::ZUrlParameters::ZUrlParameters(&this->m_urlParameters);
  this->m_nPort = -1;
  this->m_nHash = 0;
}

// File Line: 38
// RVA: 0xEC4280
void __fastcall OSuite::ZUrl::ZUrl(OSuite::ZUrl *this, OSuite::ZUrl *other)
{
  OSuite::ZString *p_m_sProtocol; // rcx

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::ZObject};
  p_m_sProtocol = &this->m_sProtocol;
  p_m_sProtocol[-1].m_pString = (OSuite::ZString::InternalString *)&OSuite::ZUrl::`vftable{for `OSuite::IHashable};
  OSuite::ZString::ZString(p_m_sProtocol);
  OSuite::ZString::ZString(&this->m_sHost);
  OSuite::ZString::ZString(&this->m_sFakeHost);
  OSuite::ZString::ZString(&this->m_sPath);
  OSuite::ZUrlParameters::ZUrlParameters(&this->m_urlParameters);
  OSuite::ZUrl::operator=(this, other);
}

// File Line: 46
// RVA: 0xEC44C4
void __fastcall OSuite::ZUrl::ZUrl(OSuite::ZUrl *this, OSuite::ZString *sPath)
{
  OSuite::ZString *p_m_sProtocol; // rcx
  const char *v5; // rax
  OSuite::ZUrl result; // [rsp+20h] [rbp-E8h] BYREF

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::ZObject};
  p_m_sProtocol = &this->m_sProtocol;
  p_m_sProtocol[-1].m_pString = (OSuite::ZString::InternalString *)&OSuite::ZUrl::`vftable{for `OSuite::IHashable};
  OSuite::ZString::ZString(p_m_sProtocol);
  OSuite::ZString::ZString(&this->m_sHost);
  OSuite::ZString::ZString(&this->m_sFakeHost);
  OSuite::ZString::ZString(&this->m_sPath);
  OSuite::ZUrlParameters::ZUrlParameters(&this->m_urlParameters);
  v5 = OSuite::ZString::c_str(sPath);
  OSuite::ZUrl::Parse(&result, v5);
  OSuite::ZUrl::operator=(this, &result);
  OSuite::ZUrl::~ZUrl(&result);
}

// File Line: 55
// RVA: 0xEC42EC
void __fastcall OSuite::ZUrl::ZUrl(OSuite::ZUrl *this, OSuite::ZUrl *that, OSuite::ZString *sPath)
{
  OSuite::ZString *p_m_sProtocol; // rcx
  const char *v7; // rax
  int IndexOf; // eax
  OSuite::ZString *v9; // rax
  const char *v10; // rax
  OSuite::ZString *p_result; // rcx
  OSuite::ZString *v12; // rax
  OSuite::ZString *v13; // rax
  const char *v14; // rax
  const char *v15; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-128h] BYREF
  OSuite::ZString v17; // [rsp+38h] [rbp-110h] BYREF
  OSuite::ZUrl other; // [rsp+50h] [rbp-F8h] BYREF

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::ZObject};
  p_m_sProtocol = &this->m_sProtocol;
  p_m_sProtocol[-1].m_pString = (OSuite::ZString::InternalString *)&OSuite::ZUrl::`vftable{for `OSuite::IHashable};
  OSuite::ZString::ZString(p_m_sProtocol);
  OSuite::ZString::ZString(&this->m_sHost);
  OSuite::ZString::ZString(&this->m_sFakeHost);
  OSuite::ZString::ZString(&this->m_sPath);
  OSuite::ZUrlParameters::ZUrlParameters(&this->m_urlParameters);
  this->m_nHash = 0;
  if ( OSuite::ZString::StartsWith(sPath, "http://") || OSuite::ZString::StartsWith(sPath, "https://") )
  {
    v15 = OSuite::ZString::c_str(sPath);
    OSuite::ZUrl::Parse(&other, v15);
    OSuite::ZUrl::operator=(this, &other);
    OSuite::ZUrl::~ZUrl(&other);
  }
  else
  {
    OSuite::ZString::operator=(&this->m_sProtocol, &that->m_sProtocol);
    OSuite::ZString::operator=(&this->m_sFakeHost, &that->m_sFakeHost);
    OSuite::ZString::operator=(&this->m_sHost, &that->m_sHost);
    this->m_nPort = that->m_nPort;
    if ( OSuite::ZString::CharAt(sPath, 0i64) == 47 )
    {
      v7 = OSuite::ZString::c_str(sPath);
      OSuite::ZUrl::ParsePath(this, v7);
    }
    else
    {
      IndexOf = OSuite::ZString::LastIndexOf(&this->m_sPath, 47);
      if ( IndexOf == -1 )
      {
        v9 = OSuite::operator+(&result, "/", sPath);
        v10 = OSuite::ZString::c_str(v9);
        OSuite::ZUrl::ParsePath(this, v10);
        p_result = &result;
      }
      else
      {
        v12 = OSuite::ZString::Slice(&this->m_sPath, &v17, 0i64, IndexOf + 1);
        v13 = OSuite::ZString::operator+(v12, &result, sPath);
        v14 = OSuite::ZString::c_str(v13);
        OSuite::ZUrl::ParsePath(this, v14);
        OSuite::ZString::~ZString(&result);
        p_result = &v17;
      }
      OSuite::ZString::~ZString(p_result);
    }
  }
}

// File Line: 92
// RVA: 0xEC45C0
void __fastcall OSuite::ZUrl::~ZUrl(OSuite::ZUrl *this)
{
  OSuite::ZUrlParameters *p_m_urlParameters; // rcx

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::ZObject};
  p_m_urlParameters = &this->m_urlParameters;
  p_m_urlParameters[-2].m_arrayParameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrl::`vftable{for `OSuite::IHashable};
  OSuite::ZUrlParameters::~ZUrlParameters(p_m_urlParameters);
  OSuite::ZString::~ZString(&this->m_sPath);
  OSuite::ZString::~ZString(&this->m_sFakeHost);
  OSuite::ZString::~ZString(&this->m_sHost);
  OSuite::ZString::~ZString(&this->m_sProtocol);
}

// File Line: 97
// RVA: 0xEC4610
OSuite::ZUrl *__fastcall OSuite::ZUrl::operator=(OSuite::ZUrl *this, OSuite::ZUrl *other)
{
  if ( this != other )
  {
    OSuite::ZString::operator=(&this->m_sProtocol, &other->m_sProtocol);
    OSuite::ZString::operator=(&this->m_sFakeHost, &other->m_sFakeHost);
    OSuite::ZString::operator=(&this->m_sHost, &other->m_sHost);
    OSuite::ZString::operator=(&this->m_sPath, &other->m_sPath);
    this->m_nPort = other->m_nPort;
    OSuite::ZUrlParameters::operator=(&this->m_urlParameters, &other->m_urlParameters);
    this->m_nHash = other->m_nHash;
  }
  return this;
}

// File Line: 120
// RVA: 0xEC4748
char __fastcall OSuite::ZUrl::operator bool(OSuite::ZUrl *this)
{
  char v2; // bl

  v2 = 0;
  if ( OSuite::ZString::operator bool(&this->m_sProtocol)
    && OSuite::ZString::operator bool(&this->m_sHost)
    && OSuite::ZString::operator bool(&this->m_sPath)
    && this->m_nPort != -1 )
  {
    return 1;
  }
  return v2;
}

// File Line: 126
// RVA: 0xEC468C
char __fastcall OSuite::ZUrl::operator==(OSuite::ZUrl *this, OSuite::ZUrl *other)
{
  unsigned int v4; // ebx
  char v6; // bl

  v4 = this->OSuite::IHashable::vfptr->ComputeHash(&this->OSuite::IHashable);
  if ( v4 != other->OSuite::IHashable::vfptr->ComputeHash(&other->OSuite::IHashable) )
    return 0;
  v6 = 0;
  if ( OSuite::ZString::operator==(&this->m_sProtocol, &other->m_sProtocol)
    && OSuite::ZString::operator==(&this->m_sFakeHost, &other->m_sFakeHost)
    && OSuite::ZString::operator==(&this->m_sHost, &other->m_sHost)
    && OSuite::ZString::operator==(&this->m_sPath, &other->m_sPath)
    && this->m_nPort == other->m_nPort
    && OSuite::ZUrlParameters::operator==(&this->m_urlParameters, &other->m_urlParameters) )
  {
    return 1;
  }
  return v6;
}

// File Line: 142
// RVA: 0xEC479C
bool __fastcall OSuite::ZUrl::operator<(OSuite::ZUrl *this, OSuite::ZUrl *other)
{
  OSuite::ZString *v5; // rax
  OSuite::ZString *v6; // rdi
  bool v7; // bl
  OSuite::ZString *p_m_sProtocol; // rdx
  OSuite::ZString *p_m_sFakeHost; // rcx
  OSuite::ZString *v10; // rax
  OSuite::ZString *v11; // rdi
  bool v12; // bl
  OSuite::ZString *v13; // rax
  OSuite::ZString *v14; // rdi
  bool v15; // bl
  OSuite::ZString *v16; // rax
  OSuite::ZString *v17; // rdi
  bool v18; // bl
  int m_nPort; // eax
  int v20; // ecx
  OSuite::ZString v21; // [rsp+20h] [rbp-48h] BYREF

  if ( this == other )
    return 0;
  OSuite::ZString::ZString(&v21, &other->m_sProtocol);
  v6 = v5;
  v7 = !OSuite::ZString::operator==(&this->m_sProtocol, v5);
  OSuite::ZString::~ZString(v6);
  if ( v7 )
  {
    p_m_sProtocol = &other->m_sProtocol;
    p_m_sFakeHost = &this->m_sProtocol;
    return OSuite::ZString::operator<(p_m_sFakeHost, p_m_sProtocol);
  }
  OSuite::ZString::ZString(&v21, &other->m_sFakeHost);
  v11 = v10;
  v12 = !OSuite::ZString::operator==(&this->m_sFakeHost, v10);
  OSuite::ZString::~ZString(v11);
  if ( v12 )
  {
    p_m_sProtocol = &other->m_sFakeHost;
    p_m_sFakeHost = &this->m_sFakeHost;
    return OSuite::ZString::operator<(p_m_sFakeHost, p_m_sProtocol);
  }
  OSuite::ZString::ZString(&v21, &other->m_sHost);
  v14 = v13;
  v15 = !OSuite::ZString::operator==(&this->m_sHost, v13);
  OSuite::ZString::~ZString(v14);
  if ( v15 )
  {
    p_m_sProtocol = &other->m_sHost;
    p_m_sFakeHost = &this->m_sHost;
    return OSuite::ZString::operator<(p_m_sFakeHost, p_m_sProtocol);
  }
  OSuite::ZString::ZString(&v21, &other->m_sPath);
  v17 = v16;
  v18 = !OSuite::ZString::operator==(&this->m_sPath, v16);
  OSuite::ZString::~ZString(v17);
  if ( v18 )
  {
    p_m_sProtocol = &other->m_sPath;
    p_m_sFakeHost = &this->m_sPath;
    return OSuite::ZString::operator<(p_m_sFakeHost, p_m_sProtocol);
  }
  m_nPort = this->m_nPort;
  v20 = other->m_nPort;
  if ( m_nPort == v20 )
    return OSuite::ZUrlParameters::operator<(&this->m_urlParameters, &other->m_urlParameters);
  else
    return m_nPort < v20;
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
  unsigned __int64 v4; // rax
  OSuite::ZString *v5; // rax
  OSuite::ZString resulta; // [rsp+20h] [rbp-58h] BYREF
  OSuite::ZStringBuilder v8; // [rsp+38h] [rbp-40h] BYREF

  v8.m_Chars.m_pList = 0i64;
  v4 = OSuite::ZString::Count(&this->m_sPath);
  OSuite::ZStringBuilder::ZStringBuilder(&v8, v4);
  OSuite::ZStringBuilder::Append(&v8, &this->m_sPath);
  v5 = OSuite::ZUrlParameters::ToString(&this->m_urlParameters, &resulta);
  OSuite::ZStringBuilder::Append(&v8, v5);
  OSuite::ZString::~ZString(&resulta);
  OSuite::ZStringBuilder::ToString(&v8, &resulta);
  OSuite::ZString::ZString(result, &resulta);
  OSuite::ZString::~ZString(&resulta);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v8);
  return result;
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
  OSuite::ZString *PathAndParameters; // rax
  OSuite::ZString resulta; // [rsp+20h] [rbp-50h] BYREF
  OSuite::ZStringBuilder v9; // [rsp+38h] [rbp-38h] BYREF

  if ( OSuite::ZUrl::operator bool(this) )
  {
    v9.m_Chars.m_pList = 0i64;
    OSuite::ZStringBuilder::ZStringBuilder(&v9, 0x28ui64);
    OSuite::ZStringBuilder::Append(&v9, &this->m_sProtocol);
    OSuite::ZStringBuilder::Append(&v9, "://", 3ui64);
    if ( bIncludeFakeHost && OSuite::ZString::operator bool(&this->m_sFakeHost) )
    {
      OSuite::ZStringBuilder::Append(&v9, &this->m_sFakeHost);
      OSuite::ZStringBuilder::Append(&v9, 33);
    }
    OSuite::ZStringBuilder::Append(&v9, &this->m_sHost);
    OSuite::ZStringBuilder::Append(&v9, 58);
    OSuite::ZStringBuilder::AppendInt(&v9, this->m_nPort);
    PathAndParameters = OSuite::ZUrl::GetPathAndParameters(this, &resulta);
    OSuite::ZStringBuilder::Append(&v9, PathAndParameters);
    OSuite::ZString::~ZString(&resulta);
    OSuite::ZStringBuilder::ToString(&v9, &resulta);
    OSuite::ZString::ZString(result, &resulta);
    OSuite::ZString::~ZString(&resulta);
    OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v9);
  }
  else
  {
    OSuite::ZString::ZString(result);
  }
  return result;
}

// File Line: 258
// RVA: 0xEC4B50
__int64 __fastcall OSuite::ZUrl::ComputeHash(OSuite::ZUrl *this)
{
  OSuite::ZString *p_m_sPath; // rbx
  unsigned int v3; // esi
  OSuite::ZString *p_m_sProtocol; // rcx
  unsigned int v5; // eax
  unsigned int v6; // esi
  OSuite::ZString *p_m_sHost; // rcx
  unsigned int v8; // eax
  unsigned int v9; // ebp
  OSuite::ZString *p_m_sFakeHost; // rcx
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // eax
  unsigned int v16; // eax

  p_m_sPath = 0i64;
  if ( !HIDWORD(this->m_urlParameters.m_arrayParameters.m_Comparer.vfptr) )
  {
    v3 = OSuite::FComputeHashBegin((_exception *)this);
    if ( this == (OSuite::ZUrl *)-8i64 )
      p_m_sProtocol = 0i64;
    else
      p_m_sProtocol = &this->m_sProtocol;
    v5 = ((__int64 (__fastcall *)(OSuite::ZString *))p_m_sProtocol->OSuite::ZObject::vfptr[1].__vecDelDtor)(p_m_sProtocol);
    v6 = OSuite::FComputeHashAdd(v3, v5);
    if ( this == (OSuite::ZUrl *)-32i64 )
      p_m_sHost = 0i64;
    else
      p_m_sHost = &this->m_sHost;
    v8 = ((__int64 (__fastcall *)(OSuite::ZString *))p_m_sHost->OSuite::ZObject::vfptr[1].__vecDelDtor)(p_m_sHost);
    v9 = OSuite::FComputeHashAdd(v6, v8);
    if ( OSuite::ZString::operator bool((OSuite::ZString *)&this->m_sHost.m_pString) )
    {
      p_m_sFakeHost = &this->m_sFakeHost;
      if ( this == (OSuite::ZUrl *)-56i64 )
        p_m_sFakeHost = 0i64;
      v11 = ((__int64 (__fastcall *)(OSuite::ZString *))p_m_sFakeHost->OSuite::ZObject::vfptr[1].__vecDelDtor)(p_m_sFakeHost);
      v9 = OSuite::FComputeHashAdd(v9, v11);
    }
    if ( this != (OSuite::ZUrl *)-80i64 )
      p_m_sPath = &this->m_sPath;
    v12 = ((__int64 (__fastcall *)(OSuite::ZString *))p_m_sPath->OSuite::ZObject::vfptr[1].__vecDelDtor)(p_m_sPath);
    v13 = OSuite::FComputeHashAdd(v9, v12);
    v14 = OSuite::FComputeHashAdd(v13, (unsigned int)this->m_urlParameters.m_arrayParameters.m_Comparer.vfptr);
    v15 = ((__int64 (__fastcall *)(OSuite::ZUrlParameters *))this->m_urlParameters.vfptr[1].__vecDelDtor)(&this->m_urlParameters);
    v16 = OSuite::FComputeHashAdd(v14, v15);
    HIDWORD(this->m_urlParameters.m_arrayParameters.m_Comparer.vfptr) = OSuite::FComputeHashEnd(v16) | 0x80000000;
  }
  return HIDWORD(this->m_urlParameters.m_arrayParameters.m_Comparer.vfptr);
}

// File Line: 300
// RVA: 0xEC4DE8
OSuite::ZUrl *__fastcall OSuite::ZUrl::Parse(OSuite::ZUrl *result, OSuite::ZString *sUrl)
{
  const char *v3; // rax

  v3 = OSuite::ZString::c_str(sUrl);
  OSuite::ZUrl::Parse(result, v3);
  return result;
}

// File Line: 311
// RVA: 0xEC4E10
OSuite::ZUrl *__fastcall OSuite::ZUrl::Parse(OSuite::ZUrl *result, const char *pszUrl)
{
  result->m_sProtocol.m_pString = 0i64;
  result->m_sHost.m_pString = 0i64;
  result->m_sFakeHost.m_pString = 0i64;
  result->m_sPath.m_pString = 0i64;
  result->m_urlParameters.m_parameters.m_pTop = 0i64;
  result->m_urlParameters.m_arrayParameters.m_pTop = 0i64;
  OSuite::ZUrl::ZUrl(result);
  OSuite::ZUrl::ParseUrl(result, pszUrl);
  return result;
}

// File Line: 355
// RVA: 0xEC4ECC
void __fastcall OSuite::ZUrl::ParseUrl(OSuite::ZUrl *this, const char *pszUrl)
{
  const char *v2; // rsi
  char *v4; // rax
  char *v5; // rbx
  OSuite::ZString *v6; // rax
  OSuite::ZString *v7; // rax
  OSuite::ZString *v8; // rax
  char v9; // cl
  char *v10; // rbx
  unsigned __int64 v11; // r12
  OSuite::ZString *v12; // rax
  char v13; // al
  OSuite::ZString *v14; // rax
  char v15; // al
  int v16; // ecx
  int v17; // ecx
  OSuite::ZString *v18; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-30h] BYREF
  OSuite::ZString v20; // [rsp+38h] [rbp-18h] BYREF

  this->m_nHash = 0;
  v2 = pszUrl;
  v4 = strstr(pszUrl, "://");
  v5 = v4;
  if ( v4 )
  {
    OSuite::ZString::ZString(&v20, v2, v4 - v2);
    v7 = OSuite::ZString::ToLower(v6, &result);
    OSuite::ZString::operator=(&this->m_sProtocol, v7);
    OSuite::ZString::~ZString(&result);
    OSuite::ZString::~ZString(&v20);
    v2 = v5 + 3;
    if ( !OSuite::ZString::operator==(&this->m_sProtocol, "http") )
    {
      if ( OSuite::ZString::operator==(&this->m_sProtocol, "https") )
        this->m_nPort = 443;
      goto LABEL_7;
    }
  }
  else
  {
    OSuite::ZString::ZString(&v20, "http", 4ui64);
    OSuite::ZString::operator=(&this->m_sProtocol, v8);
    OSuite::ZString::~ZString(&v20);
  }
  this->m_nPort = 80;
LABEL_7:
  v9 = *v2;
  v10 = (char *)v2;
  v11 = 0x8400800000000000ui64;
  while ( v9 && ((unsigned __int8)v9 > 0x3Fu || !_bittest64((const __int64 *)&v11, v9)) )
  {
    if ( v9 == 33 )
      goto LABEL_14;
    v9 = *++v10;
  }
  if ( *v10 != 33 )
    goto LABEL_19;
LABEL_14:
  OSuite::ZString::ZString(&v20, v2, v10 - v2);
  OSuite::ZString::operator=(&this->m_sFakeHost, v12);
  OSuite::ZString::~ZString(&v20);
  v2 = ++v10;
  while ( 1 )
  {
    v13 = *v10;
    if ( !*v10 || (unsigned __int8)v13 <= 0x3Fu && _bittest64((const __int64 *)&v11, v13) )
      break;
    ++v10;
  }
LABEL_19:
  OSuite::ZString::ZString(&v20, v2, v10 - v2);
  OSuite::ZString::operator=(&this->m_sHost, v14);
  OSuite::ZString::~ZString(&v20);
  if ( *v10 == 58 )
  {
    this->m_nPort = 0;
    v15 = *++v10;
    if ( !*v10 )
    {
LABEL_24:
      OSuite::ZString::ZString(&v20, "/", 1ui64);
      OSuite::ZString::operator=(&this->m_sPath, v18);
      OSuite::ZString::~ZString(&v20);
      OSuite::ZUrlParameters::Clear(&this->m_urlParameters);
      return;
    }
    do
    {
      if ( ((v15 - 47) & 0xEF) == 0 )
        break;
      v16 = 10 * this->m_nPort;
      this->m_nPort = v16;
      v17 = *v10++ + v16 - 48;
      this->m_nPort = v17;
      v15 = *v10;
    }
    while ( *v10 );
  }
  if ( !*v10 )
    goto LABEL_24;
  OSuite::ZUrl::ParsePath(this, v10);
}

// File Line: 424
// RVA: 0xEC4E60
void __fastcall OSuite::ZUrl::ParsePath(OSuite::ZUrl *this, char *pszUrl)
{
  char v2; // al
  const char *v4; // rbx
  OSuite::ZString *v5; // rax
  OSuite::ZString v6; // [rsp+20h] [rbp-28h] BYREF

  this->m_nHash = 0;
  v2 = *pszUrl;
  v4 = pszUrl;
  while ( v2 && v2 != 63 )
    v2 = *++v4;
  OSuite::ZString::ZString(&v6, pszUrl, v4 - pszUrl);
  OSuite::ZString::operator=(&this->m_sPath, v5);
  OSuite::ZString::~ZString(&v6);
  if ( *v4 == 63 )
    OSuite::ZUrlParameters::Parse(&this->m_urlParameters, v4 + 1);
}

