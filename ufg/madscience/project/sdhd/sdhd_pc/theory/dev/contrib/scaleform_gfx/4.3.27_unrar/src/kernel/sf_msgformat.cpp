// File Line: 41
// RVA: 0x9A7460
__int64 __fastcall Scaleform::FmtResource::Reflect(
        Scaleform::FmtResource *this,
        Scaleform::FmtResource::TAttrs **attrs)
{
  *attrs = 0i64;
  return 0i64;
}

// File Line: 95
// RVA: 0x99DF60
void __fastcall Scaleform::SwitchFormatter::Parse(Scaleform::SwitchFormatter *this, Scaleform::StringDataPtr *str)
{
  const char *pStr; // rsi
  unsigned __int64 Size; // rbx
  int v4; // edx
  unsigned __int64 i; // rax
  char v7; // cl
  unsigned __int64 v8; // rcx
  const char *v9; // rdi
  int v10; // eax
  __int64 v11; // rdx
  unsigned __int64 v12; // r9
  __int64 v13; // rax
  Scaleform::StringDataPtr v14; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::StringDataPtr v15; // [rsp+30h] [rbp-28h]
  Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeRef key; // [rsp+40h] [rbp-18h] BYREF
  __int64 v17; // [rsp+60h] [rbp+8h]
  int v18; // [rsp+68h] [rbp+10h] BYREF

  pStr = str->pStr;
  Size = str->Size;
  v4 = 0;
  v18 = 0;
  v14 = (Scaleform::StringDataPtr)0i64;
  while ( 1 )
  {
    for ( i = 0i64; i < Size; ++i )
    {
      v7 = pStr[i];
      if ( !v7 )
        break;
      if ( v7 == 58 )
        break;
    }
    v8 = i + 1;
    v15.pStr = pStr;
    v15.Size = i;
    v14 = v15;
    v9 = pStr;
    if ( Size < i + 1 )
      v8 = Size;
    pStr += v8;
    Size -= v8;
    if ( v4 )
    {
      v11 = 4i64;
      key.pFirst = &v18;
      v12 = 5381i64;
      key.pSecond = &v14;
      do
      {
        v13 = *((unsigned __int8 *)&v17 + v11-- + 7);
        v12 = v13 + 65599 * v12;
      }
      while ( v11 );
      Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeAltHashF,Scaleform::AllocatorGH<int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF>>::add<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeRef>(
        &this->StringSet.mHash,
        &this->StringSet,
        &key,
        v12);
      v4 = 0;
      goto LABEL_16;
    }
    if ( !i || !v9 || !isdigit(*v9) )
      break;
    v10 = atol(v9);
    v4 = 1;
    v18 = v10;
LABEL_16:
    if ( !Size )
      return;
  }
  this->DefaultStrValue = v14;
}

// File Line: 131
// RVA: 0x963010
void __fastcall Scaleform::SwitchFormatter::Convert(Scaleform::SwitchFormatter *this)
{
  Scaleform::StringDataPtr *p_StrValue; // rdi
  __int64 Index; // rax
  char *v4; // rdx
  unsigned __int64 Size; // rax

  if ( !this->IsConverted )
  {
    p_StrValue = &this->StrValue;
    Index = Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeAltHashF,Scaleform::AllocatorGH<int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF>>::findIndexAlt<int>(
              &this->StringSet.mHash,
              &this->Value);
    if ( Index >= 0 && (v4 = (char *)&this->StringSet.mHash.pTable[2] + 40 * Index) != 0i64 )
    {
      if ( !p_StrValue )
      {
LABEL_8:
        this->IsConverted = 1;
        return;
      }
      p_StrValue->pStr = (const char *)*((_QWORD *)v4 + 1);
      Size = *((_QWORD *)v4 + 2);
    }
    else
    {
      p_StrValue->pStr = this->DefaultStrValue.pStr;
      Size = this->DefaultStrValue.Size;
    }
    p_StrValue->Size = Size;
    goto LABEL_8;
  }
}

// File Line: 146
// RVA: 0x98B170
Scaleform::StringDataPtr *__fastcall Scaleform::SwitchFormatter::GetResult(
        Scaleform::SwitchFormatter *this,
        Scaleform::StringDataPtr *result)
{
  *result = this->StrValue;
  return result;
}

// File Line: 171
// RVA: 0x94A5B0
void __fastcall Scaleform::Formatter::~Formatter(Scaleform::Formatter *this)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
}

// File Line: 247
// RVA: 0x9449D0
void __fastcall Scaleform::StrFormatter::StrFormatter(
        Scaleform::StrFormatter *this,
        Scaleform::MsgFormat *f,
        const char *v)
{
  unsigned __int64 v3; // rax

  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = f;
  this->IsConverted = 0;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::StrFormatter::`vftable;
  this->Value.pStr = v;
  if ( v )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( v[v3] );
  }
  else
  {
    v3 = 0i64;
  }
  this->Value.Size = v3;
}

// File Line: 253
// RVA: 0x944980
void __fastcall Scaleform::StrFormatter::StrFormatter(
        Scaleform::StrFormatter *this,
        Scaleform::MsgFormat *f,
        Scaleform::StringDataPtr *v)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = f;
  this->IsConverted = 0;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::StrFormatter::`vftable;
  this->Value = *v;
}

// File Line: 259
// RVA: 0x944910
void __fastcall Scaleform::StrFormatter::StrFormatter(
        Scaleform::StrFormatter *this,
        Scaleform::MsgFormat *f,
        Scaleform::String *v)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = f;
  this->IsConverted = 0;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::StrFormatter::`vftable;
  this->Value.pStr = (const char *)((v->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  this->Value.Size = *(_QWORD *)(v->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64;
}

// File Line: 263
// RVA: 0x99DE70
void __fastcall Scaleform::StrFormatter::Parse(Scaleform::StrFormatter *this, Scaleform::StringDataPtr *str)
{
  unsigned __int64 Size; // r9
  const char *pStr; // r10
  unsigned __int64 i; // rax
  char v7; // r8
  Scaleform::MsgFormat *pParentFmt; // rax
  Scaleform::LocaleProvider *pLocaleProvider; // rcx
  __int64 v10; // rax
  Scaleform::Formatter *v11; // rbx
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // r9
  const char *v14; // rdx
  const char *v15; // [rsp+20h] [rbp-48h] BYREF
  unsigned __int64 v16; // [rsp+28h] [rbp-40h]
  __int64 v17[3]; // [rsp+30h] [rbp-38h] BYREF
  __int64 v18[4]; // [rsp+48h] [rbp-20h] BYREF

  Size = str->Size;
  pStr = str->pStr;
  for ( i = 0i64; i < Size; ++i )
  {
    v7 = pStr[i];
    if ( !v7 )
      break;
    if ( v7 == 58 )
      break;
  }
  v16 = i;
  pParentFmt = this->pParentFmt;
  v15 = pStr;
  if ( pParentFmt )
  {
    pLocaleProvider = pParentFmt->pLocaleProvider;
    if ( pLocaleProvider )
    {
      v18[0] = (__int64)pParentFmt;
      v18[1] = (__int64)&v15;
      v18[2] = (__int64)v17;
      v10 = (__int64)pLocaleProvider->vfptr->MakeFormatter(pLocaleProvider, (Scaleform::FormatterFactory::Args *)v18);
      v11 = (Scaleform::Formatter *)v10;
      if ( v10 )
      {
        v12 = str->Size;
        v13 = v16 + 1;
        if ( v12 < v16 + 1 )
          v13 = str->Size;
        v14 = &str->pStr[v13];
        v17[1] = v12 - v13;
        v17[0] = (__int64)v14;
        if ( v12 != v13 )
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v10 + 16i64))(v10, v17);
        Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, v11, 1);
      }
    }
  }
}

// File Line: 299
// RVA: 0x963000
void __fastcall Scaleform::StrFormatter::Convert(Scaleform::StrFormatter *this)
{
  this->IsConverted = 1;
}

// File Line: 304
// RVA: 0x98B150
Scaleform::StringDataPtr *__fastcall Scaleform::StrFormatter::GetResult(
        Scaleform::StrFormatter *this,
        Scaleform::StringDataPtr *result)
{
  *result = this->Value;
  return result;
}

// File Line: 323
// RVA: 0x99CFB0
void __fastcall Scaleform::BoolFormatter::Parse(Scaleform::BoolFormatter *this, Scaleform::StringDataPtr *str)
{
  unsigned __int64 Size; // r9
  const char *pStr; // r10
  unsigned __int64 v4; // r8
  unsigned __int64 i; // rax
  char v8; // dl
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // r9
  const char *v11; // rdx
  unsigned __int64 j; // rax
  char v13; // cl
  char v14; // cl
  unsigned __int64 v15; // rax
  const char *v16; // rdx
  unsigned __int64 v17; // r9
  char v18; // al
  Scaleform::MsgFormat *pParentFmt; // rax
  Scaleform::LocaleProvider *pLocaleProvider; // rcx
  __int64 v21; // rax
  Scaleform::Formatter *v22; // rdi
  unsigned __int64 v23; // r8
  unsigned __int64 v24; // r9
  const char *v25; // rdx
  const char *v26; // [rsp+20h] [rbp-48h] BYREF
  unsigned __int64 v27; // [rsp+28h] [rbp-40h]
  __int64 v28[3]; // [rsp+30h] [rbp-38h] BYREF
  __int64 v29[4]; // [rsp+48h] [rbp-20h] BYREF

  Size = str->Size;
  pStr = str->pStr;
  v4 = 0i64;
  for ( i = 0i64; i < Size; ++i )
  {
    v8 = pStr[i];
    if ( !v8 )
      break;
    if ( v8 == 58 )
      break;
  }
  v26 = pStr;
  v27 = i;
  if ( pStr && i )
  {
    if ( *pStr == 115 && pStr[1] == 119 )
    {
      v9 = i + 1;
      if ( Size < v9 )
        v9 = Size;
      v10 = Size - v9;
      v11 = &pStr[v9];
      for ( j = 0i64; j < v10; ++j )
      {
        v13 = v11[j];
        if ( !v13 )
          break;
        if ( v13 == 58 )
          break;
      }
      v14 = *((_BYTE *)this + 24);
      this->result.pStr = v11;
      this->result.Size = j;
      if ( (v14 & 1) == 0 )
      {
        v15 = j + 1;
        if ( v10 < v15 )
          v15 = v10;
        v16 = &v11[v15];
        v17 = v10 - v15;
        if ( v17 )
        {
          do
          {
            v18 = v16[v4];
            if ( !v18 )
              break;
            if ( v18 == 58 )
              break;
            ++v4;
          }
          while ( v4 < v17 );
        }
        this->result.pStr = v16;
        this->result.Size = v4;
      }
      *((_BYTE *)this + 24) = v14 | 2;
    }
    else
    {
      pParentFmt = this->pParentFmt;
      pLocaleProvider = pParentFmt->pLocaleProvider;
      if ( pLocaleProvider )
      {
        v29[0] = (__int64)pParentFmt;
        v29[1] = (__int64)&v26;
        v29[2] = (__int64)v28;
        v21 = (__int64)pLocaleProvider->vfptr->MakeFormatter(pLocaleProvider, (Scaleform::FormatterFactory::Args *)v29);
        v22 = (Scaleform::Formatter *)v21;
        if ( v21 )
        {
          v23 = str->Size;
          v24 = v27 + 1;
          if ( v23 < v27 + 1 )
            v24 = str->Size;
          v25 = &str->pStr[v24];
          v28[1] = v23 - v24;
          v28[0] = (__int64)v25;
          if ( v23 != v24 )
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v21 + 16i64))(v21, v28);
          Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, v22, 1);
        }
      }
    }
  }
}

// File Line: 375
// RVA: 0x962B50
void __fastcall Scaleform::BoolFormatter::Convert(Scaleform::BoolFormatter *this)
{
  char v1; // al
  const char *v2; // rax
  unsigned __int64 v3; // [rsp+8h] [rbp-10h]

  if ( !this->IsConverted )
  {
    v1 = *((_BYTE *)this + 24);
    if ( (v1 & 2) == 0 )
    {
      if ( (v1 & 1) != 0 )
      {
        v2 = "true";
        v3 = 4i64;
      }
      else
      {
        v2 = "false";
        v3 = 5i64;
      }
      this->result.pStr = v2;
      this->result.Size = v3;
    }
    this->IsConverted = 1;
  }
}

// File Line: 386
// RVA: 0x98B0E0
Scaleform::StringDataPtr *__fastcall Scaleform::BoolFormatter::GetResult(
        Scaleform::BoolFormatter *this,
        Scaleform::StringDataPtr *result)
{
  *result = this->result;
  return result;
}

// File Line: 401
// RVA: 0x958D80
char *__fastcall Scaleform::AppendCharLeft(char *buff, unsigned __int64 buffSz, char *value_ptr, unsigned int ucs_char)
{
  char *v4; // rbx
  int v5; // eax
  __int64 pindex[3]; // [rsp+20h] [rbp-18h] BYREF

  v4 = value_ptr;
  if ( ucs_char )
  {
    if ( ucs_char > 0x7F )
    {
      if ( ucs_char > 0x7FF )
      {
        if ( ucs_char > 0xFFFF )
        {
          if ( ucs_char > 0x1FFFFF )
          {
            if ( ucs_char > 0x3FFFFFF )
            {
              v5 = 0;
              if ( ucs_char <= 0x7FFFFFFF )
                v5 = 6;
            }
            else
            {
              v5 = 5;
            }
          }
          else
          {
            v5 = 4;
          }
        }
        else
        {
          v5 = 3;
        }
      }
      else
      {
        v5 = 2;
      }
    }
    else
    {
      v5 = 1;
    }
    v4 = &value_ptr[-v5];
    if ( buff > v4 )
      return 0i64;
    pindex[0] = 0i64;
    Scaleform::UTF8Util::EncodeCharSafe(v4, buffSz, pindex, ucs_char);
  }
  return v4;
}

// File Line: 433
// RVA: 0x9A5E80
void __fastcall Scaleform::NumericBase::ReadPrintFormat(Scaleform::NumericBase *this, Scaleform::StringDataPtr *token)
{
  unsigned __int64 Size; // r8
  const char *pStr; // rdx
  unsigned __int64 v6; // rdx
  const char *v7; // rcx
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rdx
  const char *v10; // rcx
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rax
  __int64 v13; // rdx
  char Integer; // al
  unsigned __int64 v15; // rdx
  const char *v16; // rcx
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // rdx
  const char *v19; // rcx
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rdx
  const char *v22; // rcx
  unsigned __int64 v23; // rax
  Scaleform::StringDataPtr str; // [rsp+20h] [rbp-68h] BYREF
  Scaleform::StringDataPtr v25; // [rsp+30h] [rbp-58h] BYREF
  Scaleform::StringDataPtr v26; // [rsp+40h] [rbp-48h] BYREF
  Scaleform::StringDataPtr v27; // [rsp+50h] [rbp-38h] BYREF
  Scaleform::StringDataPtr v28; // [rsp+60h] [rbp-28h] BYREF
  Scaleform::StringDataPtr v29; // [rsp+70h] [rbp-18h] BYREF

  Size = token->Size;
  if ( Size )
  {
    pStr = token->pStr;
    if ( pStr )
    {
      switch ( *pStr )
      {
        case  :
          *((_BYTE *)this + 6) |= 2u;
          v9 = 1i64;
          if ( !token->Size )
            v9 = token->Size;
          token->pStr += v9;
          v10 = token->pStr;
          token->Size -= v9;
          v11 = token->Size;
          v25.pStr = v10;
          v25.Size = v11;
          Scaleform::NumericBase::ReadPrintFormat(this, &v25);
          break;
        case #:
          *((_BYTE *)this + 6) |= 8u;
          v18 = 1i64;
          if ( !token->Size )
            v18 = token->Size;
          token->pStr += v18;
          v19 = token->pStr;
          token->Size -= v18;
          v20 = token->Size;
          v27.pStr = v19;
          v27.Size = v20;
          Scaleform::NumericBase::ReadPrintFormat(this, &v27);
          break;
        case +:
          *((_BYTE *)this + 5) |= 0x80u;
          v15 = 1i64;
          if ( !token->Size )
            v15 = token->Size;
          token->pStr += v15;
          v16 = token->pStr;
          token->Size -= v15;
          v17 = token->Size;
          v26.pStr = v16;
          v26.Size = v17;
          Scaleform::NumericBase::ReadPrintFormat(this, &v26);
          break;
        case -:
          *((_BYTE *)this + 6) |= 4u;
          v6 = 1i64;
          if ( !token->Size )
            v6 = token->Size;
          token->pStr += v6;
          v7 = token->pStr;
          token->Size -= v6;
          v8 = token->Size;
          str.pStr = v7;
          str.Size = v8;
          Scaleform::NumericBase::ReadPrintFormat(this, &str);
          break;
        case .:
          *(_DWORD *)this &= 0xFFFFFFE0;
          v12 = token->Size;
          v13 = v12 != 0;
          token->pStr += v13;
          token->Size = v12 - v13;
          Integer = Scaleform::ReadInteger(token, *(_DWORD *)this & 0x1F, 58);
          *(_DWORD *)this &= 0xFFFFFFE0;
          *(_DWORD *)this |= Integer & 0x1F;
          break;
        case 0:
          *((_BYTE *)this + 4) &= 0xB0u;
          *((_BYTE *)this + 4) |= 0x30u;
          v21 = 1i64;
          if ( !token->Size )
            v21 = token->Size;
          token->pStr += v21;
          v22 = token->pStr;
          token->Size -= v21;
          v23 = token->Size;
          v28.pStr = v22;
          v28.Size = v23;
          Scaleform::NumericBase::ReadPrintFormat(this, &v28);
          break;
        default:
          v29.pStr = pStr;
          v29.Size = Size;
          Scaleform::NumericBase::ReadWidth(this, &v29);
          break;
      }
    }
  }
}

// File Line: 474
// RVA: 0x9A6170
void __fastcall Scaleform::NumericBase::ReadWidth(Scaleform::NumericBase *this, Scaleform::StringDataPtr *token)
{
  unsigned __int64 Size; // rax
  __int64 v5; // rbx
  char Integer; // al
  unsigned __int64 v7; // rcx
  __int64 v8; // rax
  char v9; // al

  Size = token->Size;
  if ( Size )
  {
    v5 = 0i64;
    while ( token->pStr[v5] != 46 )
    {
      if ( ++v5 >= Size )
      {
        v5 = -1i64;
        break;
      }
    }
    Integer = Scaleform::ReadInteger(token, (*(_DWORD *)this >> 5) & 0x1F, 58);
    *(_DWORD *)this &= 0xFFFFFC1F;
    *(_DWORD *)this |= 32 * (Integer & 0x1F);
    if ( v5 >= 0 )
    {
      *(_DWORD *)this &= 0xFFFFFFE0;
      v7 = token->Size;
      v8 = v7 != 0;
      token->pStr += v8;
      token->Size = v7 - v8;
      v9 = Scaleform::ReadInteger(token, *(_DWORD *)this & 0x1F, 58);
      *(_DWORD *)this &= 0xFFFFFFE0;
      *(_DWORD *)this |= v9 & 0x1F;
    }
  }
}

// File Line: 495
// RVA: 0x9BB050
void __fastcall Scaleform::NumericBase::ULongLong2String(
        Scaleform::NumericBase *this,
        char *buff,
        unsigned __int64 value,
        bool separator,
        unsigned int base)
{
  int v7; // r9d
  const char *v8; // rbx
  char *ValueStr; // r10
  unsigned __int64 v10; // rdx
  char v11; // al

  if ( !separator || base != 10 || (v7 = 3, (*((_BYTE *)this + 5) & 0x7F) == 0) )
    v7 = 1000;
  v8 = a01234567_0;
  if ( (*((_BYTE *)this + 6) & 1) == 0 )
    v8 = "0123456789abcdef";
  if ( base - 2 <= 0xE )
  {
    do
    {
      ValueStr = this->ValueStr;
      if ( buff == ValueStr )
        break;
      v10 = value % base;
      value /= base;
      if ( !v7 )
      {
        v7 = 3;
        v11 = 2 * *((_BYTE *)this + 5);
        this->ValueStr = ValueStr - 1;
        *(ValueStr - 1) = v11 >> 1;
      }
      --this->ValueStr;
      --v7;
      *this->ValueStr = v8[(unsigned __int8)v10];
    }
    while ( value );
  }
}

// File Line: 535
// RVA: 0x9BAFA0
void __fastcall Scaleform::NumericBase::ULong2String(
        Scaleform::NumericBase *this,
        char *buff,
        unsigned int value,
        bool separator,
        unsigned int base)
{
  int v7; // r9d
  const char *v8; // r11
  char *ValueStr; // r8
  unsigned int v10; // edx
  char *v11; // r8
  char v12; // al

  if ( !separator || base != 10 || (v7 = 3, (*((_BYTE *)this + 5) & 0x7F) == 0) )
    v7 = 1000;
  v8 = a01234567_0;
  if ( (*((_BYTE *)this + 6) & 1) == 0 )
    v8 = "0123456789abcdef";
  if ( base - 2 <= 0xE )
  {
    do
    {
      ValueStr = this->ValueStr;
      if ( buff == ValueStr )
        break;
      v10 = value % base;
      value /= base;
      if ( !v7 )
      {
        v11 = ValueStr - 1;
        v7 = 3;
        v12 = 2 * *((_BYTE *)this + 5);
        this->ValueStr = v11;
        *v11 = v12 >> 1;
      }
      --this->ValueStr;
      --v7;
      *this->ValueStr = v8[(unsigned __int8)v10];
    }
    while ( value );
  }
}

// File Line: 620
// RVA: 0x93E390
void __fastcall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, unsigned int v)
{
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = 0i64;
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase &= 0xFFFFFC21;
  *(_DWORD *)&this->Scaleform::NumericBase |= 0x21u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) &= 0xA0u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) |= 0x20u;
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = *((_BYTE *)&this->Scaleform::NumericBase + 6) & 0xF0 | 1;
  this->ValueStr = 0i64;
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::Formatter};
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::String::InitStruct};
  *((_DWORD *)this + 12) &= 0xFFFFFFEA;
  *((_DWORD *)this + 12) |= 0xAu;
  *((_BYTE *)this + 52) &= 0xFCu;
  this->Value = v;
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}

// File Line: 630
// RVA: 0x93E2E0
void __fastcall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, int v)
{
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = 0i64;
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase &= 0xFFFFFC21;
  *(_DWORD *)&this->Scaleform::NumericBase |= 0x21u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) &= 0xA0u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) |= 0x20u;
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = *((_BYTE *)&this->Scaleform::NumericBase + 6) & 0xF0 | 1;
  this->ValueStr = 0i64;
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::Formatter};
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::String::InitStruct};
  *((_DWORD *)this + 12) &= 0xFFFFFFEA;
  *((_DWORD *)this + 12) |= 0xAu;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0xFC | 1;
  this->Value = v;
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}

// File Line: 661
// RVA: 0x93E430
void __fastcall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, __int64 v)
{
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = 0i64;
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase &= 0xFFFFFC21;
  *(_DWORD *)&this->Scaleform::NumericBase |= 0x21u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) &= 0xA0u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) |= 0x20u;
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = *((_BYTE *)&this->Scaleform::NumericBase + 6) & 0xF0 | 1;
  this->ValueStr = 0i64;
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::Formatter};
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::String::InitStruct};
  *((_DWORD *)this + 12) &= 0xFFFFFFEA;
  *((_DWORD *)this + 12) |= 0xAu;
  *((_BYTE *)this + 52) &= ~1u;
  *((_BYTE *)this + 52) |= 2u;
  this->Value = v;
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}

// File Line: 673
// RVA: 0x93E190
void __fastcall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, Scaleform::MsgFormat *f, int v)
{
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = f;
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase &= 0xFFFFFC21;
  *(_DWORD *)&this->Scaleform::NumericBase |= 0x21u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) &= 0xA0u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) |= 0x20u;
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = *((_BYTE *)&this->Scaleform::NumericBase + 6) & 0xF0 | 1;
  this->ValueStr = 0i64;
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::Formatter};
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::String::InitStruct};
  *((_DWORD *)this + 12) &= 0xFFFFFFEA;
  *((_DWORD *)this + 12) |= 0xAu;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0xFC | 1;
  this->Value = v;
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}

// File Line: 706
// RVA: 0x93E240
void __fastcall Scaleform::LongFormatter::LongFormatter(
        Scaleform::LongFormatter *this,
        Scaleform::MsgFormat *f,
        unsigned int v)
{
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = f;
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase &= 0xFFFFFC21;
  *(_DWORD *)&this->Scaleform::NumericBase |= 0x21u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) &= 0xA0u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) |= 0x20u;
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = *((_BYTE *)&this->Scaleform::NumericBase + 6) & 0xF0 | 1;
  this->ValueStr = 0i64;
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::Formatter};
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::String::InitStruct};
  *((_DWORD *)this + 12) &= 0xFFFFFFEA;
  *((_DWORD *)this + 12) |= 0xAu;
  *((_BYTE *)this + 52) &= 0xFCu;
  this->Value = v;
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}

// File Line: 736
// RVA: 0x99D600
void __fastcall Scaleform::LongFormatter::Parse(Scaleform::LongFormatter *this, Scaleform::StringDataPtr *str)
{
  const char *pStr; // r9
  unsigned __int64 Size; // r8
  char *BuffPtr; // r14
  unsigned __int64 i; // rbx
  char v8; // al
  const char *v9; // rdi
  unsigned __int64 v10; // rax
  char v11; // al
  unsigned __int64 j; // rax
  char v13; // cl
  unsigned __int64 k; // rax
  char v15; // cl
  unsigned __int64 v16; // rcx
  const char *v17; // r9
  unsigned __int64 v18; // r8
  char v19; // al
  Scaleform::MsgFormat *v20; // rcx
  Scaleform::StackMemPool<512,8,Scaleform::MemPoolImmediateFree> *p_MemPool; // rcx
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rdx
  Scaleform::MemoryHeap *pHeap; // rcx
  int Value; // eax
  Scaleform::MsgFormat *pParentFmt; // rcx
  unsigned __int64 v27; // r8
  unsigned __int64 v28; // rdx
  Scaleform::StringDataPtr stra; // [rsp+20h] [rbp-69h] BYREF
  Scaleform::StringDataPtr v30; // [rsp+30h] [rbp-59h] BYREF
  Scaleform::StringDataPtr v31; // [rsp+40h] [rbp-49h] BYREF
  Scaleform::StringDataPtr v32; // [rsp+50h] [rbp-39h] BYREF
  Scaleform::StringDataPtr v33; // [rsp+60h] [rbp-29h] BYREF
  __int64 v34[3]; // [rsp+70h] [rbp-19h] BYREF
  __int64 v35; // [rsp+88h] [rbp-1h] BYREF
  char v36; // [rsp+90h] [rbp+7h]
  __int64 v37; // [rsp+98h] [rbp+Fh]
  __int64 v38; // [rsp+A0h] [rbp+17h]

  v38 = -2i64;
  pStr = str->pStr;
  stra.pStr = str->pStr;
  Size = str->Size;
  stra.Size = Size;
  BuffPtr = 0i64;
  if ( !Size )
    return;
  while ( 2 )
  {
    for ( i = 0i64; i < Size; ++i )
    {
      v8 = pStr[i];
      if ( !v8 )
        break;
      if ( v8 == 58 )
        break;
    }
    v9 = pStr;
    if ( !pStr || !i )
      return;
    v10 = i + 1;
    if ( Size < i + 1 )
      v10 = Size;
    stra.pStr = &pStr[v10];
    stra.Size = Size - v10;
    if ( isdigit(*pStr) )
    {
      v31.pStr = v9;
      v31.Size = i;
      Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, &v31);
      goto LABEL_40;
    }
    switch ( *v9 )
    {
      case  :
      case #:
      case +:
      case -:
      case .:
        v32.pStr = v9;
        v32.Size = i;
        Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, &v32);
        goto LABEL_40;
      case X:
        goto LABEL_22;
      case b:
        if ( !strncmp(v9, "base", 4ui64) )
        {
          v11 = Scaleform::ReadInteger(&stra, 10, 58);
          *((_DWORD *)this + 12) &= 0xFFFFFFE0;
          *((_DWORD *)this + 12) |= v11 & 0x1F;
        }
        goto LABEL_40;
      case o:
        *((_DWORD *)this + 12) &= 0xFFFFFFE8;
        *((_DWORD *)this + 12) |= 8u;
        for ( j = 0i64; j < stra.Size; ++j )
        {
          v13 = stra.pStr[j];
          if ( !v13 )
            break;
          if ( v13 == 58 )
            break;
        }
        v33.pStr = stra.pStr;
        v33.Size = j;
        Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, &v33);
        goto LABEL_40;
      case s:
        if ( v9[1] != 119 )
        {
          if ( !strncmp(v9, "sep", 3ui64) )
          {
            v16 = 0i64;
            v17 = stra.pStr;
            v18 = stra.Size;
            if ( stra.Size )
            {
              do
              {
                v19 = stra.pStr[v16];
                if ( !v19 )
                  break;
                if ( v19 == 58 )
                  break;
                ++v16;
              }
              while ( v16 < stra.Size );
              if ( v16 )
                *((_BYTE *)&this->Scaleform::NumericBase + 5) ^= (*stra.pStr ^ *((_BYTE *)&this->Scaleform::NumericBase
                                                                               + 5)) & 0x7F;
            }
            if ( v18 < v16 )
              v16 = v18;
            pStr = &v17[v16];
            stra.pStr = pStr;
            Size = v18 - v16;
            stra.Size = Size;
            goto LABEL_41;
          }
LABEL_40:
          Size = stra.Size;
          pStr = stra.pStr;
LABEL_41:
          if ( !Size )
            goto LABEL_55;
          continue;
        }
        p_MemPool = &this->pParentFmt->MemPool;
        if ( this->pParentFmt->MemPool.BuffSize < 0x48 )
        {
          pHeap = p_MemPool->pHeap;
          if ( !pHeap )
            pHeap = Scaleform::Memory::pGlobalHeap;
          BuffPtr = (char *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))pHeap->vfptr->Alloc)(
                              pHeap,
                              72i64,
                              8i64);
        }
        else
        {
          BuffPtr = this->pParentFmt->MemPool.BuffPtr;
          this->pParentFmt->MemPool.BuffPtr = (char *)(((unsigned __int64)(BuffPtr + 71) & 0xFFFFFFFFFFFFFFF8ui64) + 8);
          v22 = ((unsigned __int64)(BuffPtr + 71) & 0xFFFFFFFFFFFFFFF8ui64) - (_QWORD)p_MemPool;
          if ( v22 >= 0x200 )
            v23 = 0i64;
          else
            v23 = 512 - v22;
          p_MemPool->BuffSize = v23;
        }
        if ( BuffPtr )
        {
          Value = this->Value;
          pParentFmt = this->pParentFmt;
          *(_QWORD *)BuffPtr = &Scaleform::FmtResource::`vftable;
          *(_QWORD *)BuffPtr = &Scaleform::Formatter::`vftable;
          *((_QWORD *)BuffPtr + 1) = pParentFmt;
          BuffPtr[16] = 0;
          *(_QWORD *)BuffPtr = &Scaleform::SwitchFormatter::`vftable;
          *((_DWORD *)BuffPtr + 6) = Value;
          v31.pStr = BuffPtr + 32;
          *((_QWORD *)BuffPtr + 4) = 0i64;
          *((_QWORD *)BuffPtr + 5) = 0i64;
          *((_QWORD *)BuffPtr + 6) = 0i64;
          *((_QWORD *)BuffPtr + 7) = 0i64;
          *((_QWORD *)BuffPtr + 8) = 0i64;
        }
        else
        {
          BuffPtr = 0i64;
        }
        stra.pStr += stra.Size;
        stra.Size = 0i64;
LABEL_55:
        if ( BuffPtr )
        {
          v27 = i + 1;
          v28 = str->Size;
          if ( v28 < i + 1 )
            v27 = str->Size;
          v30.pStr = &str->pStr[v27];
          v30.Size = v28 - v27;
          if ( v28 != v27 )
            (*(void (__fastcall **)(char *, Scaleform::StringDataPtr *, unsigned __int64, const char *))(*(_QWORD *)BuffPtr + 16i64))(
              BuffPtr,
              &v30,
              v27,
              pStr);
          Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, (Scaleform::Formatter *)BuffPtr, 1);
        }
        return;
      case x:
        *((_BYTE *)&this->Scaleform::NumericBase + 6) &= ~1u;
LABEL_22:
        *((_DWORD *)this + 12) &= 0xFFFFFFF0;
        *((_DWORD *)this + 12) |= 0x10u;
        for ( k = 0i64; k < stra.Size; ++k )
        {
          v15 = stra.pStr[k];
          if ( !v15 )
            break;
          if ( v15 == 58 )
            break;
        }
        v30.pStr = stra.pStr;
        v30.Size = k;
        Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, &v30);
        goto LABEL_40;
      default:
        v20 = this->pParentFmt;
        if ( v20->pLocaleProvider )
        {
          v36 = 0;
          v37 = 0i64;
          v35 = this->Value;
          v34[0] = (__int64)v20;
          v34[1] = (__int64)&stra;
          v34[2] = (__int64)&v35;
          BuffPtr = (char *)v20->pLocaleProvider->vfptr->MakeFormatter(
                              v20->pLocaleProvider,
                              (Scaleform::FormatterFactory::Args *)v34);
        }
        goto LABEL_40;
    }
  }
}

// File Line: 830
// RVA: 0x962D10
void __fastcall Scaleform::LongFormatter::Convert(Scaleform::LongFormatter *this)
{
  char v2; // al
  unsigned __int64 i; // rcx
  __int64 Value; // rcx
  unsigned __int64 j; // rdx
  BOOL v6; // ecx
  int v7; // edx
  char v8; // cl
  char *ValueStr; // rdx
  char *v10; // rdi
  unsigned __int64 v11; // rax
  char *v12; // r14
  unsigned __int64 v13; // rax
  char *v14; // r14
  char v15; // al

  if ( !this->IsConverted )
  {
    if ( (*(_BYTE *)&this->Scaleform::NumericBase & 0x1F) != 0 || this->Value )
    {
      v2 = *((_BYTE *)this + 52);
      if ( (v2 & 2) != 0 )
      {
        Scaleform::NumericBase::ULongLong2String(
          &this->Scaleform::NumericBase,
          this->Buff,
          abs64(this->Value),
          1,
          *((_DWORD *)this + 12) & 0x1F);
      }
      else if ( (v2 & 1) != 0 )
      {
        Scaleform::NumericBase::ULong2String(
          &this->Scaleform::NumericBase,
          this->Buff,
          abs32(this->Value),
          1,
          *((_DWORD *)this + 12) & 0x1F);
      }
      else
      {
        Scaleform::NumericBase::ULong2String(
          &this->Scaleform::NumericBase,
          this->Buff,
          this->Value,
          1,
          *((_DWORD *)this + 12) & 0x1F);
      }
    }
    for ( i = (char *)this - this->ValueStr + 92;
          i < (*(_DWORD *)&this->Scaleform::NumericBase & 0x1Fu);
          *this->ValueStr = 48 )
    {
      --this->ValueStr;
      ++i;
    }
    if ( (*(_BYTE *)&this->Scaleform::NumericBase & 0x1F) == 0 )
    {
      *((_BYTE *)&this->Scaleform::NumericBase + 4) &= 0xA0u;
      *((_BYTE *)&this->Scaleform::NumericBase + 4) |= 0x20u;
    }
    Value = this->Value;
    if ( Value >= 0 )
    {
      v7 = *((_DWORD *)this + 12) & 0x1F;
      if ( ((v7 - 8) & 0xFFFFFFF7) == 0 )
      {
        if ( Value )
        {
          v8 = *((_BYTE *)&this->Scaleform::NumericBase + 6);
          if ( (v8 & 8) != 0 )
          {
            if ( v7 == 16 )
              *--this->ValueStr = (32 * ((v8 & 1) == 0)) | 0x58;
            *--this->ValueStr = 48;
          }
        }
      }
    }
    else
    {
      if ( (*((_BYTE *)&this->Scaleform::NumericBase + 4) & 0x7F) == 48 )
      {
        for ( j = (char *)this - this->ValueStr + 92; ; ++j )
        {
          v6 = *((char *)&this->Scaleform::NumericBase + 5) < 0
            || (*((_BYTE *)&this->Scaleform::NumericBase + 6) & 2) != 0;
          if ( j >= ((*(_DWORD *)&this->Scaleform::NumericBase >> 5) & 0x1Fu) - v6 )
            break;
          *--this->ValueStr = (char)(2 * *((_BYTE *)&this->Scaleform::NumericBase + 4)) >> 1;
        }
      }
      Scaleform::LongFormatter::AppendSignCharLeft(this, (__int64)this->Value < 0);
    }
    if ( (*((_BYTE *)&this->Scaleform::NumericBase + 6) & 2) != 0 && *((char *)&this->Scaleform::NumericBase + 5) >= 0 )
    {
      *((_BYTE *)&this->Scaleform::NumericBase + 4) &= 0xA0u;
      *((_BYTE *)&this->Scaleform::NumericBase + 4) |= 0x20u;
      if ( (*((_BYTE *)this + 52) & 1) != 0 && (__int64)this->Value >= 0 )
        *--this->ValueStr = 32;
    }
    ValueStr = this->ValueStr;
    v10 = (char *)((char *)this - ValueStr + 92);
    v11 = (*(_DWORD *)&this->Scaleform::NumericBase >> 5) & 0x1F;
    if ( (*((_BYTE *)&this->Scaleform::NumericBase + 6) & 4) != 0 )
    {
      if ( (unsigned __int64)v10 < v11 )
      {
        v12 = &this->Buff[-v11 + 28];
        memmove(v12, ValueStr, (char *)this - ValueStr + 92);
        v13 = (unsigned __int64)this->Scaleform::NumericBase;
        this->ValueStr = v12;
        v14 = &v12[(_QWORD)v10];
        if ( (unsigned __int64)v10 < ((v13 >> 5) & 0x1F) )
        {
          do
          {
            ++v10;
            *v14++ = (char)(2 * *((_BYTE *)&this->Scaleform::NumericBase + 4)) >> 1;
          }
          while ( (unsigned __int64)v10 < ((*(_DWORD *)&this->Scaleform::NumericBase >> 5) & 0x1Fu) );
        }
      }
    }
    else if ( (unsigned __int64)v10 < v11 )
    {
      do
      {
        v15 = *((_BYTE *)&this->Scaleform::NumericBase + 4);
        --this->ValueStr;
        ++v10;
        *this->ValueStr = (char)(2 * v15) >> 1;
      }
      while ( (unsigned __int64)v10 < ((*(_DWORD *)&this->Scaleform::NumericBase >> 5) & 0x1Fu) );
    }
    this->IsConverted = 1;
  }
}

// File Line: 940
// RVA: 0x98B6F0
signed __int64 __fastcall Scaleform::LongFormatter::GetSize(Scaleform::LongFormatter *this)
{
  return (char *)this - this->ValueStr + 92;
}

// File Line: 951
// RVA: 0x959160
void __fastcall Scaleform::LongFormatter::AppendSignCharLeft(Scaleform::LongFormatter *this, bool negative)
{
  Scaleform::MsgFormat *pParentFmt; // rcx
  Scaleform::LocaleProvider *pLocaleProvider; // rcx
  __int64 v6; // rax
  unsigned int v7; // r9d

  pParentFmt = this->pParentFmt;
  if ( pParentFmt && (pLocaleProvider = pParentFmt->pLocaleProvider) != 0i64 )
  {
    v6 = ((__int64 (__fastcall *)(Scaleform::LocaleProvider *))pLocaleProvider->vfptr[1].__vecDelDtor)(pLocaleProvider);
    if ( negative )
    {
      v7 = *(_DWORD *)(v6 + 36);
    }
    else
    {
      if ( *((char *)&this->Scaleform::NumericBase + 5) >= 0 )
        return;
      v7 = *(_DWORD *)(v6 + 32);
    }
    this->ValueStr = Scaleform::AppendCharLeft(this->Buff, 0x1Dui64, this->ValueStr, v7);
  }
  else if ( negative )
  {
    *--this->ValueStr = 45;
  }
  else if ( *((char *)&this->Scaleform::NumericBase + 5) < 0 )
  {
    *--this->ValueStr = 43;
  }
}

// File Line: 974
// RVA: 0x93B3B0
void __fastcall Scaleform::DoubleFormatter::DoubleFormatter(Scaleform::DoubleFormatter *this, long double v)
{
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = 0i64;
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase &= 0xFFFFFC21;
  *(_DWORD *)&this->Scaleform::NumericBase |= 0x21u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) &= 0xA0u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) |= 0x20u;
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = *((_BYTE *)&this->Scaleform::NumericBase + 6) & 0xF0 | 1;
  this->ValueStr = 0i64;
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::DoubleFormatter::`vftable{for `Scaleform::Formatter};
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::DoubleFormatter::`vftable{for `Scaleform::String::InitStruct};
  this->Type = FmtDecimal;
  this->Value = v;
  this->Len = 0i64;
  this->ValueStr = &this->Buff[347];
  this->Buff[347] = 0;
  *(_DWORD *)&this->Scaleform::NumericBase &= 0xFFFFFFE6;
  *(_DWORD *)&this->Scaleform::NumericBase |= 6u;
}

// File Line: 986
// RVA: 0x93B310
void __fastcall Scaleform::DoubleFormatter::DoubleFormatter(
        Scaleform::DoubleFormatter *this,
        Scaleform::MsgFormat *f,
        long double v)
{
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = f;
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase &= 0xFFFFFC21;
  *(_DWORD *)&this->Scaleform::NumericBase |= 0x21u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) &= 0xA0u;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) |= 0x20u;
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = *((_BYTE *)&this->Scaleform::NumericBase + 6) & 0xF0 | 1;
  this->ValueStr = 0i64;
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->Scaleform::Formatter::Scaleform::FmtResource::vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::DoubleFormatter::`vftable{for `Scaleform::Formatter};
  this->Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::DoubleFormatter::`vftable{for `Scaleform::String::InitStruct};
  this->Type = FmtDecimal;
  this->Value = v;
  this->Len = 0i64;
  this->ValueStr = &this->Buff[347];
  this->Buff[347] = 0;
  *(_DWORD *)&this->Scaleform::NumericBase &= 0xFFFFFFE6;
  *(_DWORD *)&this->Scaleform::NumericBase |= 6u;
}

// File Line: 994
// RVA: 0x99D140
void __fastcall Scaleform::DoubleFormatter::Parse(Scaleform::DoubleFormatter *this, Scaleform::StringDataPtr *str)
{
  const char *Size; // r8
  Scaleform::Formatter *BuffPtr; // r14
  unsigned __int64 i; // rbx
  char v7; // cl
  const char *v8; // rdi
  const char *v9; // rax
  const char *k; // rax
  char v11; // cl
  const char *j; // rax
  char v13; // cl
  const char *m; // rax
  char v15; // cl
  const char *v16; // rcx
  char v17; // dl
  Scaleform::MsgFormat *v18; // rcx
  double v19; // xmm0_8
  double v20; // xmm0_8
  Scaleform::StackMemPool<512,8,Scaleform::MemPoolImmediateFree> *p_MemPool; // rcx
  unsigned __int64 v22; // rdx
  unsigned __int64 v23; // rax
  Scaleform::MemoryHeap *pHeap; // rcx
  double Value; // xmm0_8
  double v26; // xmm0_8
  Scaleform::MsgFormat *pParentFmt; // rax
  unsigned __int64 v28; // r8
  unsigned __int64 v29; // rdx
  Scaleform::StringDataPtr v30; // [rsp+8h] [rbp-79h] BYREF
  Scaleform::StringDataPtr v31; // [rsp+18h] [rbp-69h] BYREF
  Scaleform::StringDataPtr v32; // [rsp+28h] [rbp-59h] BYREF
  Scaleform::StringDataPtr v33; // [rsp+38h] [rbp-49h] BYREF
  __int64 v34[3]; // [rsp+48h] [rbp-39h] BYREF
  __int64 v35; // [rsp+60h] [rbp-21h] BYREF
  char v36; // [rsp+68h] [rbp-19h]
  __int64 v37; // [rsp+70h] [rbp-11h]
  __int64 v38; // [rsp+78h] [rbp-9h]
  Scaleform::StackMemPool<512,8,Scaleform::MemPoolImmediateFree> *v39; // [rsp+F0h] [rbp+6Fh]
  Scaleform::Formatter *v40; // [rsp+F8h] [rbp+77h]
  Scaleform::MsgFormat **p_pParentFmt; // [rsp+100h] [rbp+7Fh]

  v38 = -2i64;
  v31.Size = (unsigned __int64)str->pStr;
  Size = (const char *)str->Size;
  v32.pStr = Size;
  BuffPtr = 0i64;
  if ( !Size )
    return;
  while ( 2 )
  {
    for ( i = 0i64; i < (unsigned __int64)Size; ++i )
    {
      v7 = *(_BYTE *)(v31.Size + i);
      if ( !v7 )
        break;
      if ( v7 == 58 )
        break;
    }
    v8 = (const char *)v31.Size;
    if ( !v31.Size || !i )
      return;
    v9 = (const char *)(i + 1);
    if ( (unsigned __int64)Size < i + 1 )
      v9 = Size;
    v31.Size += (unsigned __int64)v9;
    v32.pStr = (const char *)(Size - v9);
    if ( isdigit(*v8) )
    {
      Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, &v30);
      goto LABEL_44;
    }
    switch ( *v8 )
    {
      case  :
      case #:
      case +:
      case -:
      case .:
        v32.pStr = v8;
        v32.Size = i;
        Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, &v32);
        goto LABEL_44;
      case E:
        goto LABEL_20;
      case G:
        goto LABEL_26;
      case e:
        *((_BYTE *)&this->Scaleform::NumericBase + 6) &= ~1u;
LABEL_20:
        this->Type = FmtScientific;
        for ( j = 0i64; j < v32.pStr; ++j )
        {
          v13 = j[v31.Size];
          if ( !v13 )
            break;
          if ( v13 == 58 )
            break;
        }
        v33.pStr = (const char *)v31.Size;
        v33.Size = (unsigned __int64)j;
        Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, &v33);
        goto LABEL_44;
      case f:
        this->Type = FmtDecimal;
        for ( k = 0i64; k < v32.pStr; ++k )
        {
          v11 = k[v31.Size];
          if ( !v11 )
            break;
          if ( v11 == 58 )
            break;
        }
        v31.Size = (unsigned __int64)k;
        Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, &v31);
        goto LABEL_44;
      case g:
        *((_BYTE *)&this->Scaleform::NumericBase + 6) &= ~1u;
LABEL_26:
        this->Type = FmtSignificant;
        for ( m = 0i64; m < v32.pStr; ++m )
        {
          v15 = m[v31.Size];
          if ( !v15 )
            break;
          if ( v15 == 58 )
            break;
        }
        v32.Size = v31.Size;
        v33.pStr = m;
        Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, (Scaleform::StringDataPtr *)&v32.Size);
        goto LABEL_44;
      case s:
        if ( v8[1] != 119 )
        {
          if ( !strncmp(v8, "sep", 3ui64) )
          {
            v16 = 0i64;
            Size = v32.pStr;
            if ( !v32.pStr )
              goto LABEL_62;
            do
            {
              v17 = v16[v31.Size];
              if ( !v17 )
                break;
              if ( v17 == 58 )
                break;
              ++v16;
            }
            while ( v16 < v32.pStr );
            if ( v16 )
              *((_BYTE *)&this->Scaleform::NumericBase + 5) ^= (*(_BYTE *)v31.Size ^ *((_BYTE *)&this->Scaleform::NumericBase
                                                                                     + 5)) & 0x7F;
            goto LABEL_45;
          }
LABEL_44:
          Size = v32.pStr;
LABEL_45:
          if ( !Size )
            goto LABEL_62;
          continue;
        }
        p_MemPool = &this->pParentFmt->MemPool;
        v39 = p_MemPool;
        if ( p_MemPool->BuffSize < 0x48 )
        {
          pHeap = p_MemPool->pHeap;
          if ( !pHeap )
            pHeap = Scaleform::Memory::pGlobalHeap;
          BuffPtr = (Scaleform::Formatter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))pHeap->vfptr->Alloc)(
                                              pHeap,
                                              72i64,
                                              8i64);
        }
        else
        {
          BuffPtr = (Scaleform::Formatter *)p_MemPool->BuffPtr;
          p_MemPool->BuffPtr = (char *)(((unsigned __int64)(&BuffPtr[2].IsConverted + 7) & 0xFFFFFFFFFFFFFFF8ui64) + 8);
          v22 = ((unsigned __int64)(&BuffPtr[2].IsConverted + 7) & 0xFFFFFFFFFFFFFFF8ui64) - (_QWORD)p_MemPool;
          if ( v22 >= 0x200 )
            v23 = 0i64;
          else
            v23 = 512 - v22;
          p_MemPool->BuffSize = v23;
        }
        v40 = BuffPtr;
        if ( BuffPtr )
        {
          Value = this->Value;
          if ( Value <= 0.0 )
            v26 = Value - 0.5;
          else
            v26 = Value + 0.5;
          pParentFmt = this->pParentFmt;
          BuffPtr->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
          BuffPtr->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
          BuffPtr->pParentFmt = pParentFmt;
          BuffPtr->IsConverted = 0;
          BuffPtr->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::SwitchFormatter::`vftable;
          LODWORD(BuffPtr[1].vfptr) = (int)v26;
          p_pParentFmt = &BuffPtr[1].pParentFmt;
          v30.pStr = (const char *)&BuffPtr[1].pParentFmt;
          BuffPtr[1].pParentFmt = 0i64;
          *(_QWORD *)&BuffPtr[1].IsConverted = 0i64;
          BuffPtr[2].vfptr = 0i64;
          BuffPtr[2].pParentFmt = 0i64;
          *(_QWORD *)&BuffPtr[2].IsConverted = 0i64;
        }
        else
        {
          BuffPtr = 0i64;
        }
        v31.Size += (unsigned __int64)v32.pStr;
        v32.pStr = 0i64;
LABEL_62:
        if ( BuffPtr )
        {
          v28 = i + 1;
          v29 = str->Size;
          if ( v29 < i + 1 )
            v28 = str->Size;
          v32.Size = (unsigned __int64)&str->pStr[v28];
          v33.pStr = (const char *)(v29 - v28);
          if ( v29 != v28 )
            BuffPtr->vfptr[1].__vecDelDtor(BuffPtr, (unsigned int)&v32.Size);
          Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, BuffPtr, 1);
        }
        return;
      default:
        v18 = this->pParentFmt;
        if ( v18->pLocaleProvider )
        {
          v19 = this->Value;
          if ( v19 <= 0.0 )
            v20 = v19 - 0.5;
          else
            v20 = v19 + 0.5;
          v36 = 1;
          v37 = 0i64;
          v35 = (int)v20;
          v34[0] = (__int64)v18;
          v34[1] = (__int64)&v31.Size;
          v34[2] = (__int64)&v35;
          BuffPtr = v18->pLocaleProvider->vfptr->MakeFormatter(
                      v18->pLocaleProvider,
                      (Scaleform::FormatterFactory::Args *)v34);
        }
        goto LABEL_44;
    }
  }
} v34[2] = (__int64)&v35;
          BuffPtr = v18->pLocaleProvider->vfptr->MakeFormatter(
                      v18->pLocaleProvider,
         

// File Line: 1232
// RVA: 0x962BB0
void __fastcall Scaleform::DoubleFormatter::Convert(Scaleform::DoubleFormatter *this)
{
  Scaleform::DoubleFormatter::PresentationType Type; // ecx
  char v3; // dl
  __int32 v4; // ecx
  bool v5; // zf
  char *v6; // rcx
  char v7; // al
  unsigned int v8; // r9d
  unsigned __int64 v9; // rax
  char *ValueStr; // rax
  char *v11; // rax
  char format[2]; // [rsp+30h] [rbp-48h] BYREF
  char v13; // [rsp+32h] [rbp-46h] BYREF
  char v14; // [rsp+33h] [rbp-45h] BYREF
  char dest[40]; // [rsp+50h] [rbp-28h] BYREF

  if ( !this->IsConverted )
  {
    Type = this->Type;
    v3 = 32;
    if ( Type )
    {
      v4 = Type - 1;
      if ( v4 )
      {
        if ( v4 == 1 )
          v3 = (32 * ((*((_BYTE *)&this->Scaleform::NumericBase + 6) & 1) == 0)) | 0x47;
      }
      else
      {
        v3 = (32 * ((*((_BYTE *)&this->Scaleform::NumericBase + 6) & 1) == 0)) | 0x45;
      }
    }
    else
    {
      v3 = 102;
    }
    v5 = *((_BYTE *)&this->Scaleform::NumericBase + 5) >= 0;
    *(_WORD *)format = 9509;
    v6 = &v13;
    if ( !v5 )
    {
      v13 = 43;
      v6 = &v14;
    }
    v7 = *((_BYTE *)&this->Scaleform::NumericBase + 6);
    if ( (v7 & 8) != 0 )
      *v6++ = 35;
    if ( (v7 & 2) != 0 )
      *v6++ = 32;
    if ( (v7 & 4) != 0 )
      *v6++ = 45;
    if ( (*((_BYTE *)&this->Scaleform::NumericBase + 4) & 0x7F) == 48 )
      *v6++ = 48;
    v8 = (unsigned int)this->Scaleform::NumericBase;
    if ( ((v8 >> 5) & 0x1F) == 1 )
    {
      *(_WORD *)v6 = 9518;
      v6[2] = 100;
      v6[3] = v3;
      v6[4] = 0;
      Scaleform::SFsprintf(dest, 0x20ui64, format, v8 & 0x1F);
    }
    else
    {
      *(_DWORD *)v6 = 623797285;
      v6[4] = 100;
      v6[5] = v3;
      v6[6] = 0;
      Scaleform::SFsprintf(dest, 0x20ui64, format);
    }
    v9 = Scaleform::SFsprintf(this->Buff, 0x15Cui64, dest, this->Value);
    this->ValueStr = this->Buff;
    this->Len = v9;
    if ( this->Buff[0] )
    {
      while ( 1 )
      {
        ValueStr = this->ValueStr;
        if ( *ValueStr == 44 )
          break;
        v11 = ValueStr + 1;
        this->ValueStr = v11;
        if ( !*v11 )
          goto LABEL_26;
      }
      *ValueStr = 46;
    }
LABEL_26:
    this->ValueStr = this->Buff;
    this->IsConverted = 1;
  }
}

// File Line: 1361
// RVA: 0x98B100
Scaleform::StringDataPtr *__fastcall Scaleform::LongFormatter::GetResult(
        Scaleform::LongFormatter *this,
        Scaleform::StringDataPtr *result)
{
  unsigned __int64 v4; // rax
  char *ValueStr; // rcx

  v4 = ((__int64 (__fastcall *)(Scaleform::LongFormatter *))this->Scaleform::Formatter::Scaleform::FmtResource::vfptr[2].Reflect)(this);
  ValueStr = this->ValueStr;
  result->Size = v4;
  result->pStr = ValueStr;
  return result;
}

// File Line: 1366
// RVA: 0x98B6C0
SSExpressionBase *__fastcall Scaleform::GFx::MovieImpl::GetHeap(SSClosureInfoMethod *this)
{
  return this->i_expr_p;
}

// File Line: 1375
// RVA: 0x993F30
void __fastcall Scaleform::DoubleFormatter::InitString(Scaleform::LongFormatter *this, char *pbuffer, size_t size)
{
  if ( this[-1].Buff[24] )
    memmove(pbuffer, *(const void **)&this->IsConverted, size);
}

// File Line: 1457
// RVA: 0x94C860
void __fastcall Scaleform::ResourceFormatter::~ResourceFormatter(Scaleform::ResourceFormatter *this)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::ResourceFormatter::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
}

// File Line: 1471
// RVA: 0x99DD80
void __fastcall Scaleform::ResourceFormatter::Parse(Scaleform::ResourceFormatter *this, Scaleform::StringDataPtr *str)
{
  unsigned __int64 Size; // r9
  const char *pStr; // r10
  Scaleform::Formatter *v4; // rbx
  unsigned __int64 i; // r8
  char v8; // al
  Scaleform::MsgFormat *pParentFmt; // rax
  Scaleform::LocaleProvider *pLocaleProvider; // rcx
  __int64 v11; // rax
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // rax
  const char *v15; // [rsp+20h] [rbp-58h] BYREF
  unsigned __int64 v16; // [rsp+28h] [rbp-50h]
  __int128 v17; // [rsp+30h] [rbp-48h] BYREF
  __int128 v18; // [rsp+40h] [rbp-38h]
  __int64 v19[4]; // [rsp+50h] [rbp-28h] BYREF

  Size = str->Size;
  pStr = str->pStr;
  v4 = 0i64;
  v17 = 0ui64;
  for ( i = 0i64; i < Size; ++i )
  {
    v8 = pStr[i];
    if ( !v8 )
      break;
    if ( v8 == 58 )
      break;
  }
  pParentFmt = this->pParentFmt;
  v15 = pStr;
  v16 = i;
  pLocaleProvider = pParentFmt->pLocaleProvider;
  if ( pLocaleProvider )
  {
    v19[0] = (__int64)pParentFmt;
    v19[1] = (__int64)&v15;
    v19[2] = (__int64)&this->Value;
    v11 = (__int64)pLocaleProvider->vfptr->MakeFormatter(pLocaleProvider, (Scaleform::FormatterFactory::Args *)v19);
    i = v16;
    v4 = (Scaleform::Formatter *)v11;
  }
  v12 = str->Size;
  v13 = i + 1;
  if ( v12 < v13 )
    v13 = str->Size;
  v14 = v12 - v13;
  *(_QWORD *)&v18 = &str->pStr[v13];
  *((_QWORD *)&v18 + 1) = v14;
  v17 = v18;
  if ( v4 )
  {
    if ( v14 )
      v4->vfptr[1].__vecDelDtor(v4, (unsigned int)&v17);
    Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, v4, 1);
  }
}

// File Line: 1505
// RVA: 0x962F90
void __fastcall Scaleform::ResourceFormatter::Convert(Scaleform::ResourceFormatter *this)
{
  Scaleform::ResouceProvider *pRP; // rcx
  unsigned __int64 v3; // rax
  int v4; // [rsp+20h] [rbp-28h] BYREF
  __int64 v5; // [rsp+28h] [rbp-20h]
  __int64 v6[3]; // [rsp+30h] [rbp-18h] BYREF

  if ( !this->IsConverted )
  {
    pRP = this->pRP;
    v4 = 0;
    v5 = 0i64;
    if ( pRP )
    {
      pRP->vfptr->MakeString(pRP, (Scaleform::StringDataPtr *)v6, &this->Value, (Scaleform::FmtResource::TAttrs *)&v4);
      v3 = v6[1];
      this->Result.pStr = (const char *)v6[0];
      this->IsConverted = 1;
      this->Result.Size = v3;
    }
    else
    {
      this->Result.pStr = 0i64;
      this->IsConverted = 1;
      this->Result.Size = 0i64;
    }
  }
}

// File Line: 1514
// RVA: 0x98B130
Scaleform::StringDataPtr *__fastcall Scaleform::ResourceFormatter::GetResult(
        Scaleform::ResourceFormatter *this,
        Scaleform::StringDataPtr *result)
{
  *result = this->Result;
  return result;
}

// File Line: 1532
// RVA: 0x940000
void __fastcall Scaleform::MsgFormat::MsgFormat(Scaleform::MsgFormat *this, Scaleform::MsgFormat::Sink *r)
{
  char *v2; // rax

  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::MsgFormat::`vftable;
  *(_WORD *)&this->EscapeChar = 37;
  *(_DWORD *)&this->NonPosParamNum = -65536;
  this->StrSize = 0i64;
  this->pLocaleProvider = 0i64;
  this->Result = *r;
  this->Data.Size = 0i64;
  this->Data.DynamicArray.Data.Data = 0i64;
  this->Data.DynamicArray.Data.Size = 0i64;
  this->Data.DynamicArray.Data.Policy.Capacity = 0i64;
  this->MemPool.pHeap = 0i64;
  v2 = (char *)((((unsigned __int64)&this->MemPool.pHeap + 7) & 0xFFFFFFFFFFFFFFF8ui64) + 8);
  this->MemPool.BuffPtr = v2;
  this->MemPool.BuffSize = (char *)&this->MemPool - v2 + 520;
}

// File Line: 1542
// RVA: 0x94BA50
void __fastcall Scaleform::MsgFormat::~MsgFormat(Scaleform::MsgFormat *this)
{
  Scaleform::MsgFormat::StackArray<Scaleform::MsgFormat::fmt_record,16,Scaleform::ArrayPOD<Scaleform::MsgFormat::fmt_record,2,Scaleform::ArrayDefaultPolicy> > *p_Data; // r14
  unsigned __int64 Size; // rbp
  unsigned __int64 v4; // rdi
  __int64 v5; // rsi
  __int64 StaticArray; // rax
  __int64 v7; // rax
  void (__fastcall ***v8)(void *, _QWORD); // rbx

  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::MsgFormat::`vftable;
  p_Data = &this->Data;
  Size = this->Data.Size;
  v4 = 0i64;
  if ( Size )
  {
    v5 = 0i64;
    do
    {
      if ( v4 >= 0x10 )
        StaticArray = (__int64)&p_Data->DynamicArray.Data.Data[-16];
      else
        StaticArray = (__int64)p_Data->StaticArray;
      v7 = v5 + StaticArray;
      if ( *(_DWORD *)v7 == 2 )
      {
        if ( *(_BYTE *)(v7 + 16) )
        {
          v8 = *(void (__fastcall ****)(void *, _QWORD))(v7 + 8);
          if ( v8 )
          {
            (**v8)(v8, 0i64);
            if ( v8 < (void (__fastcall ***)(void *, _QWORD))this->MemPool.Buff
              || v8 >= (void (__fastcall ***)(void *, _QWORD))&this->MemPool.BuffPtr )
            {
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
            }
          }
        }
      }
      ++v4;
      v5 += 24i64;
    }
    while ( v4 < Size );
  }
  if ( p_Data->DynamicArray.Data.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
}

// File Line: 1564
// RVA: 0x954A70
void __fastcall Scaleform::MsgFormat::AddStringRecord(Scaleform::MsgFormat *this, Scaleform::StringDataPtr *str)
{
  const char *pStr; // rbp
  Scaleform::MsgFormat::StackArray<Scaleform::MsgFormat::fmt_record,16,Scaleform::ArrayPOD<Scaleform::MsgFormat::fmt_record,2,Scaleform::ArrayDefaultPolicy> > *p_Data; // rsi
  unsigned __int64 Size; // rax
  unsigned __int64 *v5; // rcx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // r8
  Scaleform::MsgFormat::fmt_record *Data; // rax
  Scaleform::MsgFormat::fmt_record *v10; // rdx
  unsigned __int64 v11; // [rsp+28h] [rbp-30h]
  unsigned __int64 v12; // [rsp+30h] [rbp-28h]

  pStr = str->pStr;
  p_Data = &this->Data;
  LOBYTE(v11) = str->Size;
  Size = this->Data.Size;
  LODWORD(v12) = 0;
  if ( Size < 0x10 )
  {
    v5 = &p_Data->Size + 3 * Size;
    v5[4] = v12;
    v5[5] = (unsigned __int64)pStr;
    v5[6] = v11;
    ++p_Data->Size;
    return;
  }
  v6 = this->Data.DynamicArray.Data.Size;
  v7 = v6 + 1;
  if ( v6 + 1 >= v6 )
  {
    if ( v7 > this->Data.DynamicArray.Data.Policy.Capacity )
    {
      v8 = v7 + (v7 >> 2);
      goto LABEL_8;
    }
  }
  else if ( v7 < this->Data.DynamicArray.Data.Policy.Capacity >> 1 )
  {
    v8 = v6 + 1;
LABEL_8:
    Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data.DynamicArray.Data,
      &this->Data.DynamicArray,
      v8);
  }
  Data = p_Data->DynamicArray.Data.Data;
  p_Data->DynamicArray.Data.Size = v7;
  v10 = &Data[v7];
  *(_QWORD *)&v10[-1].RecType = v12;
  v10[-1].RecValue.String.Str = pStr;
  *(_QWORD *)&v10[-1].RecValue.Formatter.Allocated = v11;
  ++p_Data->Size;
}

// File Line: 1584
// RVA: 0x99DA70
void __fastcall Scaleform::MsgFormat::Parse(Scaleform::MsgFormat *this, const char *fmt)
{
  char v2; // r13
  const char *v3; // rbx
  const char *v5; // rdi
  int v6; // esi
  char v7; // si
  int v8; // ecx
  char v9; // al
  char v10; // cl
  unsigned __int64 Size; // rax
  Scaleform::String::InitStructVtbl **v12; // rcx
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // r14
  unsigned __int64 v15; // r8
  Scaleform::MsgFormat::fmt_record *Data; // rax
  Scaleform::MsgFormat::fmt_record *v17; // rdx
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // r14
  Scaleform::String::InitStructVtbl **v20; // rcx
  const char *v21; // r14
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rsi
  unsigned __int64 v24; // r8
  Scaleform::MsgFormat::fmt_record *v25; // rax
  Scaleform::MsgFormat::fmt_record *v26; // rdx
  Scaleform::String::InitStructVtbl *v27; // [rsp+28h] [rbp-48h]
  Scaleform::StringDataPtr str; // [rsp+30h] [rbp-40h] BYREF
  Scaleform::StringDataPtr v29; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::String::InitStructVtbl *v30; // [rsp+50h] [rbp-20h]

  v2 = 0;
  v3 = fmt;
  v5 = fmt;
  v6 = 0;
  this->UnboundFmtrInd = -1;
  if ( !fmt )
    return;
  this->NonPosParamNum = 0;
  if ( !*fmt )
    return;
  do
  {
    if ( v6 )
    {
      if ( *v3 == 125 )
      {
        if ( v5 == v3 )
        {
LABEL_28:
          ++v3;
          v6 = 0;
          v5 = v3;
          continue;
        }
        v7 = -1;
        if ( isspace(*v5) )
        {
          do
            v8 = *++v5;
          while ( isspace(v8) );
        }
        if ( isdigit(*v5) )
        {
          v9 = atol(v5);
          v10 = *v5;
          v7 = v9;
          if ( *v5 )
          {
            while ( v10 != 58 && v10 != 125 )
            {
              v10 = *++v5;
              if ( !v10 )
                goto LABEL_17;
            }
            if ( *v5 == 58 )
              ++v5;
          }
        }
        else
        {
          ++this->NonPosParamNum;
        }
LABEL_17:
        BYTE1(v27) = v7;
        LODWORD(v30) = 1;
        LOBYTE(v27) = (_BYTE)v3 - (_BYTE)v5;
        Size = this->Data.Size;
        if ( Size < 0x10 )
        {
          v12 = &this->vfptr + 3 * Size;
          v12[12] = v30;
          v12[13] = (Scaleform::String::InitStructVtbl *)v5;
          v12[14] = v27;
          goto LABEL_26;
        }
        v13 = this->Data.DynamicArray.Data.Size;
        v14 = v13 + 1;
        if ( v13 + 1 >= v13 )
        {
          if ( v14 > this->Data.DynamicArray.Data.Policy.Capacity )
          {
            v15 = v14 + (v14 >> 2);
            goto LABEL_24;
          }
        }
        else if ( v14 < this->Data.DynamicArray.Data.Policy.Capacity >> 1 )
        {
          v15 = v13 + 1;
LABEL_24:
          Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &this->Data.DynamicArray.Data,
            &this->Data.DynamicArray,
            v15);
        }
        Data = this->Data.DynamicArray.Data.Data;
        this->Data.DynamicArray.Data.Size = v14;
        v17 = &Data[v14];
        *(_QWORD *)&v17[-1].RecType = v30;
        v17[-1].RecValue.String.Str = v5;
        *(_QWORD *)&v17[-1].RecValue.Formatter.Allocated = v27;
LABEL_26:
        ++this->Data.Size;
        if ( this->UnboundFmtrInd == 0xFFFF )
          this->UnboundFmtrInd = LOWORD(this->Data.Size) - 1;
        goto LABEL_28;
      }
      goto LABEL_31;
    }
    if ( v2 )
    {
      v2 = 0;
LABEL_31:
      ++v3;
      continue;
    }
    if ( *v3 == 123 )
    {
      if ( v5 != v3 )
      {
        str.pStr = v5;
        str.Size = v3 - v5;
        Scaleform::MsgFormat::AddStringRecord(this, &str);
      }
      ++v3;
      v6 = 1;
      v5 = v3;
    }
    else
    {
      if ( *v3 != (unsigned __int8)this->EscapeChar )
        goto LABEL_31;
      v21 = v3 + 1;
      if ( !v3[1] )
        goto LABEL_31;
      if ( v5 != v3 )
      {
        v29.pStr = v5;
        v29.Size = v3 - v5;
        Scaleform::MsgFormat::AddStringRecord(this, &v29);
      }
      ++v3;
      v5 = v21;
      v2 = 1;
    }
  }
  while ( *v3 );
  if ( !v6 && v5 != v3 )
  {
    v18 = this->Data.Size;
    LODWORD(v30) = 0;
    LOBYTE(v29.Size) = (_BYTE)v3 - (_BYTE)v5;
    v19 = v29.Size;
    if ( v18 < 0x10 )
    {
      v20 = &this->vfptr + 3 * v18;
      v20[12] = v30;
      v20[13] = (Scaleform::String::InitStructVtbl *)v5;
      v20[14] = (Scaleform::String::InitStructVtbl *)v19;
      goto LABEL_53;
    }
    v22 = this->Data.DynamicArray.Data.Size;
    v23 = v22 + 1;
    if ( v22 + 1 >= v22 )
    {
      if ( v23 > this->Data.DynamicArray.Data.Policy.Capacity )
      {
        v24 = v23 + (v23 >> 2);
LABEL_51:
        Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &this->Data.DynamicArray.Data,
          &this->Data.DynamicArray,
          v24);
      }
    }
    else if ( v23 < this->Data.DynamicArray.Data.Policy.Capacity >> 1 )
    {
      v24 = v22 + 1;
      goto LABEL_51;
    }
    v25 = this->Data.DynamicArray.Data.Data;
    this->Data.DynamicArray.Data.Size = v23;
    v26 = &v25[v23];
    *(_QWORD *)&v26[-1].RecType = v30;
    v26[-1].RecValue.String.Str = v5;
    *(_QWORD *)&v26[-1].RecValue.Formatter.Allocated = v19;
LABEL_53:
    ++this->Data.Size;
  }
}

// File Line: 1976
// RVA: 0x9AA7F0
bool __fastcall Scaleform::MsgFormat::ReplaceFormatter(
        Scaleform::MsgFormat *this,
        Scaleform::Formatter *oldf,
        Scaleform::Formatter *newf,
        bool allocated)
{
  unsigned __int64 Size; // rbx
  unsigned __int64 v5; // r10
  __int64 i; // r11
  Scaleform::MsgFormat::fmt_record *v8; // rdx
  bool result; // al
  __int64 v10; // [rsp+8h] [rbp-30h]
  __int64 v11; // [rsp+10h] [rbp-28h]

  Size = this->Data.Size;
  v5 = 0i64;
  if ( !Size )
    return 0;
  for ( i = -384i64; ; i += 24i64 )
  {
    v8 = v5 >= 0x10
       ? (Scaleform::MsgFormat::fmt_record *)((char *)this->Data.DynamicArray.Data.Data + i)
       : (Scaleform::MsgFormat::fmt_record *)((char *)&this->MemPool + i);
    if ( v8->RecType == eFmtType && v8->RecValue.Formatter.Formatter == oldf )
      break;
    if ( ++v5 >= Size )
      return 0;
  }
  LODWORD(v11) = 2;
  *(_QWORD *)&v8->RecType = v11;
  LOBYTE(v10) = allocated;
  v8->RecValue.String.Str = (const char *)newf;
  result = 1;
  *(_QWORD *)&v8->RecValue.Formatter.Allocated = v10;
  return result;
}

// File Line: 2002
// RVA: 0x99C430
char __fastcall Scaleform::MsgFormat::NextFormatter(Scaleform::MsgFormat *this)
{
  unsigned __int64 Size; // r11
  unsigned __int64 UnboundFmtrInd; // rdx
  char v3; // r10
  unsigned __int64 i; // r9
  Scaleform::MsgFormat::fmt_record *v5; // r8

  Size = this->Data.Size;
  UnboundFmtrInd = this->UnboundFmtrInd;
  v3 = 1;
  this->DataInd = -1i64;
  if ( UnboundFmtrInd >= Size )
    return 0;
  for ( i = UnboundFmtrInd - 16; ; ++i )
  {
    if ( UnboundFmtrInd >= 0x10 )
      v5 = &this->Data.DynamicArray.Data.Data[i];
    else
      v5 = (Scaleform::MsgFormat::fmt_record *)((char *)&this->MemPool + i * 24);
    if ( v5->RecType != eParamStrType )
    {
      if ( v3 )
        ++this->UnboundFmtrInd;
      goto LABEL_12;
    }
    if ( BYTE1(*(_QWORD *)&v5->RecValue.Formatter.Allocated) == this->FirstArgNum )
      break;
    if ( v3 )
      v3 = 0;
LABEL_12:
    if ( ++UnboundFmtrInd >= Size )
      return 0;
  }
  if ( v3 )
    ++this->UnboundFmtrInd;
  this->DataInd = UnboundFmtrInd;
  return 1;
}

// File Line: 2041
// RVA: 0x95AC90
void __fastcall Scaleform::MsgFormat::Bind(
        Scaleform::MsgFormat *this,
        Scaleform::Formatter *formatter,
        const bool allocated)
{
  unsigned __int64 DataInd; // r9
  Scaleform::MsgFormat::StackArray<Scaleform::MsgFormat::fmt_record,16,Scaleform::ArrayPOD<Scaleform::MsgFormat::fmt_record,2,Scaleform::ArrayDefaultPolicy> > *p_Data; // r10
  Scaleform::MsgFormat::fmt_record *v7; // rcx
  __int64 Str; // r8
  __int64 v9; // rdx
  __int64 v10; // rbx
  char *v11; // rcx
  Scaleform::FmtResourceVtbl *vfptr; // rax
  __int64 v13; // [rsp+20h] [rbp-38h] BYREF
  __int64 v14; // [rsp+28h] [rbp-30h]
  __int64 v15; // [rsp+30h] [rbp-28h]

  DataInd = this->DataInd;
  p_Data = &this->Data;
  if ( DataInd >= 0x10 )
    v7 = &this->Data.DynamicArray.Data.Data[DataInd - 16];
  else
    v7 = (Scaleform::MsgFormat::fmt_record *)&p_Data->StaticArray[16 * DataInd + 8 * DataInd];
  Str = (__int64)v7->RecValue.String.Str;
  v9 = *(_QWORD *)&v7->RecValue.Formatter.Allocated;
  LOBYTE(v14) = allocated;
  v10 = v14;
  LODWORD(v15) = 2;
  if ( DataInd >= 0x10 )
    v11 = (char *)&p_Data->DynamicArray.Data.Data[DataInd - 16];
  else
    v11 = &p_Data->StaticArray[16 * DataInd + 8 * DataInd];
  *(_QWORD *)v11 = v15;
  *((_QWORD *)v11 + 1) = formatter;
  *((_QWORD *)v11 + 2) = v10;
  if ( (_BYTE)v9 )
  {
    v14 = (unsigned __int8)v9;
    vfptr = formatter->vfptr;
    v13 = Str;
    vfptr[1].__vecDelDtor(formatter, (unsigned int)&v13);
  }
}

// File Line: 2065
// RVA: 0x95AD40
void __fastcall Scaleform::MsgFormat::BindNonPos(Scaleform::MsgFormat *this)
{
  Scaleform::LocaleProvider *pLocaleProvider; // rcx
  unsigned __int64 DataInd; // rdx
  Scaleform::MsgFormat::fmt_record *v4; // rcx
  __int64 Str; // r9
  __int64 v6; // r8
  __int64 v7; // r10
  Scaleform::MsgFormat::fmt_record *v8; // rcx
  __int64 v10; // [rsp+18h] [rbp-39h] BYREF
  __int64 v11; // [rsp+20h] [rbp-31h]
  __int64 v12[2]; // [rsp+38h] [rbp-19h] BYREF
  char v13; // [rsp+48h] [rbp-9h]
  __int64 v14; // [rsp+50h] [rbp-1h]
  __int64 v15; // [rsp+58h] [rbp+7h]
  __int64 v16; // [rsp+60h] [rbp+Fh]
  __int128 v17; // [rsp+68h] [rbp+17h]
  __int64 v18; // [rsp+78h] [rbp+27h]
  __int64 v19; // [rsp+88h] [rbp+37h]
  __int64 v20; // [rsp+90h] [rbp+3Fh]

  v19 = -2i64;
  LOBYTE(v11) = 1;
  v12[1] = (__int64)this;
  v13 = 0;
  v12[0] = (__int64)&Scaleform::ResourceFormatter::`vftable;
  v14 = 0i64;
  v15 = v11;
  v16 = 0i64;
  v18 = 0i64;
  v17 = 0ui64;
  pLocaleProvider = this->pLocaleProvider;
  if ( pLocaleProvider )
    *(_QWORD *)&v17 = pLocaleProvider->vfptr[1].MakeFormatter(pLocaleProvider, 0i64);
  if ( Scaleform::MsgFormat::NextFormatter(this) )
  {
    DataInd = this->DataInd;
    v4 = DataInd >= 0x10
       ? &this->Data.DynamicArray.Data.Data[DataInd - 16]
       : (Scaleform::MsgFormat::fmt_record *)&this->Data.StaticArray[24 * DataInd];
    Str = (__int64)v4->RecValue.String.Str;
    v6 = *(_QWORD *)&v4->RecValue.Formatter.Allocated;
    LOBYTE(v11) = 0;
    LODWORD(v20) = 2;
    v7 = v11;
    v8 = DataInd >= 0x10
       ? &this->Data.DynamicArray.Data.Data[DataInd - 16]
       : (Scaleform::MsgFormat::fmt_record *)&this->Data.StaticArray[24 * DataInd];
    *(_QWORD *)&v8->RecType = v20;
    v8->RecValue.String.Str = (const char *)v12;
    *(_QWORD *)&v8->RecValue.Formatter.Allocated = v7;
    if ( (_BYTE)v6 )
    {
      v10 = Str;
      v11 = (unsigned __int8)v6;
      (*(void (__fastcall **)(__int64 *, __int64 *))(v12[0] + 16))(v12, &v10);
    }
  }
  if ( this->NonPosParamNum-- == 1 )
    Scaleform::MsgFormat::MakeString(this);
  else
    Scaleform::MsgFormat::BindNonPos(this);
}

// File Line: 2080
// RVA: 0x971480
void __fastcall Scaleform::MsgFormat::Evaluate(Scaleform::MsgFormat *this, unsigned __int64 ind)
{
  char *v3; // r8
  char *v4; // rdi
  _BYTE *v5; // rdi
  char v6; // al
  unsigned __int64 Size; // rdx
  __int64 v8; // r8
  unsigned __int64 v9; // rax
  char v10; // cl
  unsigned __int64 v11; // rbx
  char *Data; // rcx
  char *v13; // rsi
  __int64 v14; // rsi
  __int64 v15; // rax
  __int64 v16; // rax
  Scaleform::StringDataPtr *v17; // rax
  __int64 v18; // rbx
  __int64 v19; // rax
  char *v20; // rax
  unsigned __int64 v21; // rcx
  const char *v22; // rax
  __int64 v23; // rax
  char v24; // al
  unsigned __int64 v25; // rbx
  unsigned __int64 v26; // rsi
  char *p_MemPool; // rax
  int v28; // ecx
  char *v29; // rcx
  Scaleform::StringDataPtr *v30; // rax
  __int64 v31; // rbx
  __int64 v32; // rax
  char *v33; // rax
  char *v34; // rax
  unsigned __int64 v35; // rcx
  const char *v36; // rax
  char v37; // al
  unsigned __int64 v38; // rbx
  unsigned __int64 v39; // rsi
  unsigned __int64 v40; // rax
  int v41; // ecx
  unsigned __int64 v42; // rcx
  Scaleform::StringDataPtr *v43; // rax
  __int64 v44; // rbx
  __int64 v45; // rax
  unsigned __int64 v46; // rax
  unsigned __int64 v47; // rax
  unsigned __int64 v48; // rcx
  const char *v49; // rax
  __int64 v50; // rax
  unsigned __int64 v51; // rsi
  int v52; // eax
  int v53; // eax
  char v54; // al
  unsigned __int64 v55; // r8
  char v56; // r9
  __int64 v57; // rcx
  char *v58; // rax
  Scaleform::MsgFormat *v59; // rcx
  const char *Str; // rbx
  unsigned __int64 v61; // rcx
  char *v62; // rax
  char *v63; // rbx
  Scaleform::MsgFormat::fmt_record *v64; // rax
  unsigned __int64 v65; // rcx
  char *v66; // rax
  unsigned __int64 inda; // [rsp+20h] [rbp-39h]
  unsigned __int64 indb; // [rsp+20h] [rbp-39h]
  unsigned __int64 indc; // [rsp+20h] [rbp-39h]
  __int64 v70; // [rsp+28h] [rbp-31h]
  __int64 v71; // [rsp+28h] [rbp-31h]
  __int64 v72; // [rsp+28h] [rbp-31h]
  Scaleform::StringDataPtr v73; // [rsp+30h] [rbp-29h] BYREF
  Scaleform::StringDataPtr v74; // [rsp+40h] [rbp-19h] BYREF
  __int64 v75[2]; // [rsp+50h] [rbp-9h] BYREF
  __int64 v76[2]; // [rsp+60h] [rbp+7h] BYREF
  char v77[16]; // [rsp+70h] [rbp+17h] BYREF
  char v78[24]; // [rsp+80h] [rbp+27h] BYREF
  char v81; // [rsp+D0h] [rbp+77h]
  char v82; // [rsp+D0h] [rbp+77h]
  char v83; // [rsp+D0h] [rbp+77h]
  char v84; // [rsp+D8h] [rbp+7Fh]

  if ( ind >= 0x10 )
    v3 = (char *)&this->Data.DynamicArray.Data.Data[ind - 16];
  else
    v3 = &this->Data.StaticArray[24 * ind];
  if ( *(_DWORD *)v3 != 2 )
    return;
  if ( ind >= 0x10 )
    v4 = (char *)&this->Data.DynamicArray.Data.Data[ind - 16];
  else
    v4 = &this->Data.StaticArray[24 * ind];
  v5 = (_BYTE *)*((_QWORD *)v4 + 1);
  v6 = (*(__int64 (__fastcall **)(_BYTE *))(*(_QWORD *)v5 + 48i64))(v5);
  v84 = v6;
  if ( !v6 )
    goto LABEL_120;
  Size = 0i64;
  v8 = 0xFFFFFFFFi64;
  if ( (v6 & 2) != 0 )
  {
    v9 = ind - 1;
    v10 = 0;
    inda = ind - 1;
    v81 = 0;
    if ( ind != 0x100000000i64 )
    {
      v11 = 24 * (ind - 17);
      v70 = 24 * (v9 - 16);
      while ( 1 )
      {
        if ( v10 )
          goto LABEL_38;
        if ( v9 >= 0x10 )
        {
          Data = (char *)this->Data.DynamicArray.Data.Data;
          v9 = inda;
        }
        else
        {
          Data = (char *)&this->MemPool;
        }
        Size = *(unsigned int *)&Data[v11];
        if ( (_DWORD)Size )
        {
          if ( (_DWORD)Size != 2 )
            goto LABEL_34;
          if ( v9 >= 0x10 )
            v13 = (char *)this->Data.DynamicArray.Data.Data + v11;
          else
            v13 = (char *)&this->MemPool + v11;
          v14 = *((_QWORD *)v13 + 1);
          if ( ((*(__int64 (__fastcall **)(__int64, unsigned __int64, Scaleform::MsgFormat *))(*(_QWORD *)v14 + 48i64))(
                  v14,
                  Size,
                  this) & 4) != 0 )
          {
            v75[0] = (__int64)"stub";
            v15 = *(_QWORD *)v5;
            v75[1] = 4i64;
            (*(void (__fastcall **)(_BYTE *, __int64 *))(v15 + 56))(v5, v75);
            v9 = inda;
            v10 = 1;
            v81 = 1;
          }
          else if ( ((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 48i64))(v14) & 8) != 0
                 && (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v14 + 88i64))(v14) == 2 )
          {
            v76[0] = (__int64)"stub";
            v16 = *(_QWORD *)v5;
            v76[1] = 4i64;
            (*(void (__fastcall **)(_BYTE *, __int64 *))(v16 + 56))(v5, v76);
            v9 = inda;
            v10 = 1;
            v81 = 1;
          }
          else
          {
            Scaleform::MsgFormat::Evaluate(this, inda);
            v17 = (Scaleform::StringDataPtr *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v14 + 32i64))(
                                                v14,
                                                v77);
            if ( Scaleform::IsSpace(v17) )
              goto LABEL_33;
            v18 = *(_QWORD *)v5;
            v19 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v14 + 32i64))(v14, v78);
            (*(void (__fastcall **)(_BYTE *, __int64))(v18 + 56))(v5, v19);
            v11 = v70;
            v9 = inda;
            v10 = 1;
            v81 = 1;
          }
        }
        else
        {
          if ( v9 >= 0x10 )
            v20 = (char *)this->Data.DynamicArray.Data.Data + v11;
          else
            v20 = (char *)&this->MemPool + v11;
          v21 = (unsigned __int8)v20[16];
          v22 = (const char *)*((_QWORD *)v20 + 1);
          v73.Size = v21;
          v74.Size = v21;
          v73.pStr = v22;
          v74.pStr = v22;
          if ( Scaleform::IsSpace(&v74) )
          {
LABEL_33:
            v9 = inda;
LABEL_34:
            v10 = v81;
            goto LABEL_35;
          }
          (*(void (__fastcall **)(_BYTE *, Scaleform::StringDataPtr *))(*(_QWORD *)v5 + 56i64))(v5, &v73);
          v9 = inda;
          v10 = 1;
          v81 = 1;
        }
LABEL_35:
        --v9;
        v11 -= 24i64;
        v8 = 0xFFFFFFFFi64;
        inda = v9;
        v70 = v11;
        if ( v9 == 0xFFFFFFFF )
        {
          if ( v10 )
            goto LABEL_38;
          break;
        }
      }
    }
    v23 = *(_QWORD *)v5;
    v73.pStr = 0i64;
    v73.Size = 0i64;
    (*(void (__fastcall **)(_BYTE *, Scaleform::StringDataPtr *, __int64))(v23 + 56))(v5, &v73, 0xFFFFFFFFi64);
    v8 = 0xFFFFFFFFi64;
  }
LABEL_38:
  if ( (v84 & 1) != 0 )
  {
    v24 = 0;
    v25 = ind - 1;
    v82 = 0;
    indb = ind - 1;
    if ( ind != 0x100000000i64 )
    {
      v26 = 24 * (ind - 17);
      while ( 1 )
      {
        if ( v24 )
          goto LABEL_58;
        Size = (unsigned __int64)this;
        p_MemPool = (char *)&this->MemPool;
        if ( v25 >= 0x10 )
          p_MemPool = (char *)this->Data.DynamicArray.Data.Data;
        v28 = *(_DWORD *)&p_MemPool[v26];
        if ( v28 )
        {
          if ( v28 != 2 )
            goto LABEL_54;
          v29 = (char *)&this->MemPool;
          if ( v25 >= 0x10 )
            v29 = (char *)this->Data.DynamicArray.Data.Data;
          v71 = *(_QWORD *)&v29[v26 + 8];
          (*(void (__fastcall **)(char *, Scaleform::MsgFormat *, __int64))(*(_QWORD *)v71 + 48i64))(v29, this, v8);
          Scaleform::MsgFormat::Evaluate(this, v25);
          v30 = (Scaleform::StringDataPtr *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v71 + 32i64))(
                                              v71,
                                              v78);
          if ( Scaleform::IsSpace(v30) )
            goto LABEL_54;
          v31 = *(_QWORD *)v5;
          v32 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v71 + 32i64))(v71, v77);
          (*(void (__fastcall **)(_BYTE *, __int64))(v31 + 56))(v5, v32);
          v25 = indb;
          v24 = 1;
          v82 = 1;
        }
        else
        {
          v33 = (char *)&this->MemPool;
          if ( v25 >= 0x10 )
            v33 = (char *)this->Data.DynamicArray.Data.Data;
          v34 = &v33[v26];
          v35 = (unsigned __int8)v34[16];
          v36 = (const char *)*((_QWORD *)v34 + 1);
          v74.Size = v35;
          v73.Size = v35;
          v74.pStr = v36;
          v73.pStr = v36;
          if ( Scaleform::IsSpace(&v73) )
          {
LABEL_54:
            v24 = v82;
            goto LABEL_55;
          }
          (*(void (__fastcall **)(_BYTE *, Scaleform::StringDataPtr *))(*(_QWORD *)v5 + 56i64))(v5, &v74);
          v24 = 1;
          v82 = 1;
        }
LABEL_55:
        --v25;
        v26 -= 24i64;
        indb = v25;
        if ( v25 == 0xFFFFFFFF )
        {
          if ( v24 )
            goto LABEL_58;
          break;
        }
      }
    }
    v73.pStr = 0i64;
    v73.Size = 0i64;
    (*(void (__fastcall **)(_BYTE *, Scaleform::StringDataPtr *, __int64))(*(_QWORD *)v5 + 56i64))(v5, &v73, v8);
  }
LABEL_58:
  if ( (v84 & 4) != 0 )
  {
    Size = (unsigned __int64)this;
    v37 = 0;
    v38 = ind + 1;
    v83 = 0;
    indc = ind + 1;
    v75[0] = this->Data.Size;
    if ( ind + 1 < v75[0] )
    {
      v39 = 24 * (ind - 15);
      while ( 1 )
      {
        if ( v37 )
          goto LABEL_80;
        v40 = Size + 480;
        if ( v38 >= 0x10 )
          v40 = *(_QWORD *)(Size + 72);
        v41 = *(_DWORD *)(v39 + v40);
        if ( !v41 )
          break;
        if ( v41 == 2 )
        {
          v42 = Size + 480;
          if ( v38 >= 0x10 )
            v42 = *(_QWORD *)(Size + 72);
          v72 = *(_QWORD *)(v39 + v42 + 8);
          (*(void (__fastcall **)(unsigned __int64, unsigned __int64, __int64))(*(_QWORD *)v72 + 48i64))(v42, Size, v8);
          Scaleform::MsgFormat::Evaluate(this, v38);
          v43 = (Scaleform::StringDataPtr *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v72 + 32i64))(
                                              v72,
                                              v78);
          if ( !Scaleform::IsSpace(v43) )
          {
            v44 = *(_QWORD *)v5;
            v45 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v72 + 32i64))(v72, v77);
            (*(void (__fastcall **)(_BYTE *, __int64))(v44 + 72))(v5, v45);
            v38 = indc;
            v37 = 1;
            v83 = 1;
LABEL_76:
            Size = (unsigned __int64)this;
            goto LABEL_77;
          }
          goto LABEL_75;
        }
        v37 = v83;
LABEL_77:
        ++v38;
        v39 += 24i64;
        indc = v38;
        if ( v38 >= v75[0] )
        {
          if ( v37 )
            goto LABEL_80;
          goto LABEL_79;
        }
      }
      v46 = Size + 480;
      if ( v38 >= 0x10 )
        v46 = *(_QWORD *)(Size + 72);
      v47 = v39 + v46;
      v48 = *(unsigned __int8 *)(v47 + 16);
      v49 = *(const char **)(v47 + 8);
      v74.Size = v48;
      v73.Size = v48;
      v74.pStr = v49;
      v73.pStr = v49;
      if ( !Scaleform::IsSpace(&v73) )
      {
        (*(void (__fastcall **)(_BYTE *, Scaleform::StringDataPtr *))(*(_QWORD *)v5 + 72i64))(v5, &v74);
        v37 = 1;
        v83 = 1;
        goto LABEL_76;
      }
LABEL_75:
      v37 = v83;
      goto LABEL_76;
    }
LABEL_79:
    v50 = *(_QWORD *)v5;
    v51 = 0i64;
    v73.pStr = 0i64;
    v73.Size = 0i64;
    (*(void (__fastcall **)(_BYTE *, Scaleform::StringDataPtr *, __int64))(v50 + 72))(v5, &v73, v8);
  }
  else
  {
LABEL_80:
    v51 = 0i64;
  }
  if ( (v84 & 8) == 0 )
    goto LABEL_120;
  v52 = (*(__int64 (__fastcall **)(_BYTE *))(*(_QWORD *)v5 + 88i64))(v5) - 1;
  if ( !v52 )
  {
    v51 = ind - 1;
    if ( ind == 0x100000000i64 )
      goto LABEL_120;
    v65 = 24 * (ind - 17);
    while ( 1 )
    {
      Size = (unsigned __int64)this;
      v66 = (char *)&this->MemPool;
      if ( v51 >= 0x10 )
        v66 = (char *)this->Data.DynamicArray.Data.Data;
      if ( *(_DWORD *)&v66[v65] == 2 )
        break;
      --v51;
      v65 -= 24i64;
      if ( v51 == 0xFFFFFFFF )
        goto LABEL_120;
    }
    if ( v51 < 0x10 )
    {
      v63 = &this->Data.StaticArray[24 * v51];
      goto LABEL_118;
    }
    v64 = this->Data.DynamicArray.Data.Data;
LABEL_117:
    v63 = (char *)&v64[v51 - 16];
    goto LABEL_118;
  }
  v53 = v52 - 1;
  if ( !v53 )
  {
    Size = this->Data.Size;
    v51 = ind + 1;
    if ( ind + 1 >= Size )
      goto LABEL_120;
    v61 = 24 * (ind - 15);
    while ( 1 )
    {
      v62 = (char *)&this->MemPool;
      if ( v51 >= 0x10 )
        v62 = (char *)this->Data.DynamicArray.Data.Data;
      if ( *(_DWORD *)&v62[v61] == 2 )
        break;
      ++v51;
      v61 += 24i64;
      if ( v51 >= Size )
        goto LABEL_120;
    }
    if ( v51 < 0x10 )
    {
      v63 = &this->Data.StaticArray[24 * v51];
LABEL_118:
      Str = (const char *)*((_QWORD *)v63 + 1);
      (*(void (__fastcall **)(const char *))(*(_QWORD *)Str + 48i64))(Str);
      v59 = this;
      goto LABEL_119;
    }
    v64 = this->Data.DynamicArray.Data.Data;
    goto LABEL_117;
  }
  if ( v53 != 1 )
    goto LABEL_120;
  v54 = (*(__int64 (__fastcall **)(_BYTE *))(*(_QWORD *)v5 + 96i64))(v5);
  LOBYTE(Size) = 0;
  v55 = this->Data.Size;
  v56 = v54;
  if ( !v55 )
    goto LABEL_120;
  v57 = -384i64;
  while ( 1 )
  {
    v58 = (char *)&this->MemPool;
    if ( v51 >= 0x10 )
      v58 = (char *)this->Data.DynamicArray.Data.Data;
    if ( *(_DWORD *)&v58[v57] != 2 )
      goto LABEL_92;
    if ( (_BYTE)Size == v56 )
      break;
    LOBYTE(Size) = Size + 1;
LABEL_92:
    ++v51;
    v57 += 24i64;
    if ( v51 >= v55 )
      goto LABEL_120;
  }
  v59 = this;
  if ( v51 >= 0x10 )
    Str = this->Data.DynamicArray.Data.Data[v51 - 16].RecValue.String.Str;
  else
    Str = *(const char **)&this->Data.StaticArray[24 * v51 + 8];
LABEL_119:
  Scaleform::MsgFormat::Evaluate(v59, v51);
  (*(void (__fastcall **)(_BYTE *, const char *))(*(_QWORD *)v5 + 104i64))(v5, Str);
LABEL_120:
  if ( !v5[16] )
    (*(void (__fastcall **)(_BYTE *, unsigned __int64))(*(_QWORD *)v5 + 24i64))(v5, Size);
}

// File Line: 2412
// RVA: 0x998FD0
void __fastcall Scaleform::MsgFormat::MakeString(Scaleform::MsgFormat *this)
{
  unsigned __int64 Size; // r12
  unsigned __int64 v2; // r15
  unsigned __int64 v4; // rbx
  __int64 v5; // r14
  __int64 v6; // rdi
  char *p_MemPool; // rbp
  char *v8; // rbp
  char *Data; // rax
  int v10; // ecx
  __int64 v11; // rcx
  __int64 v12; // rax
  Scaleform::MsgFormat::Sink::DataType Type; // ecx
  __int32 v14; // ecx
  char *pStr; // rbx
  unsigned __int64 StrSize; // rcx
  Scaleform::StringBuffer *pStrBuffer; // r12
  unsigned __int64 v18; // r13
  unsigned __int64 v19; // rcx
  char *pData; // r9
  __int64 v21; // rdx
  char *v22; // rax
  char *v23; // rbp
  char *v24; // rbp
  char *v25; // rax
  int v26; // ecx
  __int64 v27; // rcx
  size_t v28; // rbx
  const void *v29; // rbp
  unsigned __int64 v30; // rdi
  char *putf8str[7]; // [rsp+20h] [rbp-38h] BYREF

  Size = this->Data.Size;
  v2 = 0i64;
  this->StrSize = 0i64;
  v4 = 0i64;
  v5 = -384i64;
  if ( Size )
  {
    v6 = -384i64;
    do
    {
      p_MemPool = (char *)&this->MemPool;
      if ( v4 >= 0x10 )
        p_MemPool = (char *)this->Data.DynamicArray.Data.Data;
      v8 = &p_MemPool[v6];
      Data = (char *)&this->MemPool;
      if ( v4 >= 0x10 )
        Data = (char *)this->Data.DynamicArray.Data.Data;
      v10 = *(_DWORD *)&Data[v6];
      if ( v10 )
      {
        if ( v10 != 2 )
          goto LABEL_13;
        Scaleform::MsgFormat::Evaluate(this, v4);
        v11 = *((_QWORD *)v8 + 1);
        if ( !v11 )
          goto LABEL_13;
        v12 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 40i64))(v11);
      }
      else
      {
        v12 = (unsigned __int8)v8[16];
      }
      this->StrSize += v12;
LABEL_13:
      ++v4;
      v6 += 24i64;
    }
    while ( v4 < Size );
  }
  Type = this->Result.Type;
  if ( Type )
  {
    v14 = Type - 1;
    if ( v14 )
    {
      if ( v14 == 1 )
      {
        pStr = (char *)this->Result.SinkData.pStr;
        this->vfptr->InitString(this, pStr, this->Result.SinkData.DataPtr.Size);
        StrSize = this->StrSize;
        if ( this->Result.SinkData.DataPtr.Size - 1 < StrSize )
          StrSize = this->Result.SinkData.DataPtr.Size - 1;
        pStr[StrSize] = 0;
      }
    }
    else
    {
      pStrBuffer = this->Result.SinkData.pStrBuffer;
      v18 = this->Data.Size;
      v19 = this->StrSize + pStrBuffer->Size;
      if ( v19 >= pStrBuffer->BufferSize )
      {
        pData = pStrBuffer->pData;
        v21 = ~(pStrBuffer->GrowSize - 1) & (pStrBuffer->GrowSize + v19);
        pStrBuffer->BufferSize = v21;
        if ( pData )
          v22 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, pData, v21);
        else
          v22 = (char *)pStrBuffer->pHeap->vfptr->Alloc(pStrBuffer->pHeap, v21, 0i64);
        pStrBuffer->pData = v22;
      }
      if ( v18 )
      {
        do
        {
          v23 = (char *)&this->MemPool;
          if ( v2 >= 0x10 )
            v23 = (char *)this->Data.DynamicArray.Data.Data;
          v24 = &v23[v5];
          v25 = (char *)&this->MemPool;
          if ( v2 >= 0x10 )
            v25 = (char *)this->Data.DynamicArray.Data.Data;
          v26 = *(_DWORD *)&v25[v5];
          if ( v26 )
          {
            if ( v26 == 2 )
            {
              v27 = *((_QWORD *)v24 + 1);
              if ( v27 )
              {
                (*(void (__fastcall **)(__int64, char **))(*(_QWORD *)v27 + 32i64))(v27, putf8str);
                Scaleform::StringBuffer::AppendString(pStrBuffer, putf8str[0], (size_t)putf8str[1]);
              }
            }
          }
          else
          {
            v28 = (unsigned __int8)v24[16];
            v29 = (const void *)*((_QWORD *)v24 + 1);
            if ( v29 && v28 )
            {
              v30 = pStrBuffer->Size;
              Scaleform::StringBuffer::Resize(pStrBuffer, v30 + v28);
              memmove(&pStrBuffer->pData[v30], v29, v28);
            }
          }
          ++v2;
          v5 += 24i64;
        }
        while ( v2 < v18 );
      }
    }
  }
  else
  {
    Scaleform::String::AssignString(this->Result.SinkData.pStr, this, this->StrSize);
  }
}

// File Line: 2502
// RVA: 0x993F50
void __fastcall Scaleform::MsgFormat::InitString(Scaleform::MsgFormat *this, char *pbuffer, unsigned __int64 size)
{
  unsigned __int64 v3; // r12
  unsigned __int64 v4; // rbp
  __int64 v5; // rbx
  unsigned __int64 i; // rsi
  char *p_MemPool; // rdx
  char *v10; // rdx
  char *Data; // rax
  int v12; // ecx
  __int64 v13; // rcx
  size_t v14; // rdi
  const void *v15; // rdx
  __int64 v16[5]; // [rsp+20h] [rbp-28h] BYREF

  if ( size )
  {
    v3 = this->Data.Size;
    v4 = size;
    v5 = -384i64;
    for ( i = 0i64; ; ++i )
    {
      if ( i >= v3 )
        return;
      p_MemPool = (char *)&this->MemPool;
      if ( i >= 0x10 )
        p_MemPool = (char *)this->Data.DynamicArray.Data.Data;
      v10 = &p_MemPool[v5];
      Data = (char *)&this->MemPool;
      if ( i >= 0x10 )
        Data = (char *)this->Data.DynamicArray.Data.Data;
      v12 = *(_DWORD *)&Data[v5];
      if ( !v12 )
        break;
      if ( v12 == 2 )
      {
        v13 = *((_QWORD *)v10 + 1);
        if ( v13 )
        {
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v13 + 32i64))(v13, v16);
          v14 = v16[1];
          v15 = (const void *)v16[0];
LABEL_13:
          if ( v4 < v14 )
            v14 = v4;
          memmove(pbuffer, v15, v14);
          v4 -= v14;
          pbuffer += v14;
        }
      }
      v5 += 24i64;
      if ( !v4 )
        return;
    }
    v14 = (unsigned __int8)v10[16];
    v15 = (const void *)*((_QWORD *)v10 + 1);
    goto LABEL_13;
  }
}

// File Line: 2544
// RVA: 0x997E30
char __fastcall Scaleform::IsSpace(Scaleform::StringDataPtr *s)
{
  char *v1; // rbx
  int v2; // eax
  int v3; // ecx
  int v4; // ecx
  char *putf8Buffer; // [rsp+30h] [rbp+8h] BYREF

  v1 = (char *)&s->pStr[s->Size];
  putf8Buffer = (char *)s->pStr;
  if ( putf8Buffer == v1 )
    return 1;
  while ( 1 )
  {
    v2 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
    if ( !v2 )
      break;
    v3 = Scaleform::UnicodeSpaceBits[(unsigned __int64)(unsigned __int16)v2 >> 8];
    if ( !Scaleform::UnicodeSpaceBits[(unsigned __int64)(unsigned __int16)v2 >> 8] )
      break;
    if ( v3 != 1 )
    {
      v4 = Scaleform::UnicodeSpaceBits[v3 + ((unsigned __int8)v2 >> 4)];
      if ( !_bittest(&v4, v2 & 0xF) )
        break;
    }
    if ( putf8Buffer >= v1 )
      return 1;
  }
  return 0;
}

// File Line: 2578
// RVA: 0x9A5A10
int __fastcall Scaleform::ReadInteger(Scaleform::StringDataPtr *str, int defaultValue, char separator)
{
  unsigned __int64 Size; // r9
  const char *pStr; // rsi
  unsigned __int64 i; // rdi
  char v8; // al
  unsigned __int64 j; // rbx
  unsigned __int64 v10; // rax

  Size = str->Size;
  pStr = str->pStr;
  for ( i = 0i64; i < Size; ++i )
  {
    v8 = pStr[i];
    if ( !v8 )
      break;
    if ( v8 == separator )
      break;
  }
  if ( !i || !pStr || !isdigit(*pStr) )
    return defaultValue;
  for ( j = 1i64; j < i; ++j )
  {
    if ( !isdigit(pStr[j]) )
      break;
  }
  v10 = str->Size;
  if ( v10 < j )
    j = str->Size;
  str->pStr += j;
  str->Size = v10 - j;
  return atol(pStr);
}

// File Line: 2597
// RVA: 0x97AB30
void __fastcall Scaleform::MsgFormat::FinishFormatD(Scaleform::MsgFormat *this)
{
  if ( this->NonPosParamNum )
  {
    this->FirstArgNum = -1;
    Scaleform::MsgFormat::BindNonPos(this);
  }
  else
  {
    Scaleform::MsgFormat::MakeString(this);
  }
}

