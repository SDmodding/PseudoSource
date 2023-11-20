// File Line: 41
// RVA: 0x9A7460
__int64 __fastcall Scaleform::FmtResource::Reflect(Scaleform::FmtResource *this, Scaleform::FmtResource::TAttrs **attrs)
{
  *attrs = 0i64;
  return 0i64;
}

// File Line: 95
// RVA: 0x99DF60
void __fastcall Scaleform::SwitchFormatter::Parse(Scaleform::SwitchFormatter *this, Scaleform::StringDataPtr *str)
{
  const char *v2; // rsi
  unsigned __int64 v3; // rbx
  signed int v4; // edx
  Scaleform::SwitchFormatter *v5; // rbp
  unsigned __int64 v6; // rax
  char v7; // cl
  signed __int64 v8; // rcx
  const char *v9; // rdi
  int v10; // eax
  signed __int64 v11; // rdx
  unsigned __int64 v12; // r9
  __int64 v13; // rax
  Scaleform::StringDataPtr v14; // [rsp+20h] [rbp-38h]
  __m128i v15; // [rsp+30h] [rbp-28h]
  Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeRef key; // [rsp+40h] [rbp-18h]
  __int64 v17; // [rsp+60h] [rbp+8h]
  int v18; // [rsp+68h] [rbp+10h]

  v2 = str->pStr;
  v3 = str->Size;
  v4 = 0;
  v18 = 0;
  v5 = this;
  v14 = (Scaleform::StringDataPtr)0i64;
  while ( 1 )
  {
    v6 = 0i64;
    if ( v3 )
    {
      do
      {
        v7 = v2[v6];
        if ( !v7 )
          break;
        if ( v7 == 58 )
          break;
        ++v6;
      }
      while ( v6 < v3 );
    }
    v8 = v6 + 1;
    v15.m128i_i64[0] = (__int64)v2;
    v15.m128i_i64[1] = v6;
    _mm_store_si128((__m128i *)&v14, v15);
    v9 = v2;
    if ( v3 < v6 + 1 )
      v8 = v3;
    v2 += v8;
    v3 -= v8;
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
        (Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeAltHashF,Scaleform::AllocatorGH<int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeHashF> > *)&v5->StringSet.mHash.pTable,
        &v5->StringSet,
        &key,
        v12);
      v4 = 0;
      goto LABEL_16;
    }
    if ( !v6 || !v9 || !isdigit(*v9) )
      break;
    v10 = atol(v9);
    v4 = 1;
    v18 = v10;
LABEL_16:
    if ( !v3 )
      return;
  }
  v5->DefaultStrValue = v14;
}

// File Line: 131
// RVA: 0x963010
void __fastcall Scaleform::SwitchFormatter::Convert(Scaleform::SwitchFormatter *this)
{
  Scaleform::SwitchFormatter *v1; // rbx
  Scaleform::StringDataPtr *v2; // rdi
  __int64 v3; // rax
  signed __int64 v4; // rdx
  unsigned __int64 v5; // rax

  v1 = this;
  if ( !this->IsConverted )
  {
    v2 = &this->StrValue;
    v3 = Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeAltHashF,Scaleform::AllocatorGH<int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF>>::findIndexAlt<int>(
           (Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeAltHashF,Scaleform::AllocatorGH<int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeHashF> > *)&this->StringSet.mHash.pTable,
           &this->Value);
    if ( v3 >= 0 && (v4 = (signed __int64)v1->StringSet.mHash.pTable + 8 * (5 * v3 + 4)) != 0 )
    {
      if ( !v2 )
      {
LABEL_8:
        v1->IsConverted = 1;
        return;
      }
      v2->pStr = *(const char **)(v4 + 8);
      v5 = *(_QWORD *)(v4 + 16);
    }
    else
    {
      v2->pStr = v1->DefaultStrValue.pStr;
      v5 = v1->DefaultStrValue.Size;
    }
    v2->Size = v5;
    goto LABEL_8;
  }
}

// File Line: 146
// RVA: 0x98B170
Scaleform::StringDataPtr *__fastcall Scaleform::SwitchFormatter::GetResult(Scaleform::SwitchFormatter *this, Scaleform::StringDataPtr *result)
{
  result->pStr = this->StrValue.pStr;
  result->Size = this->StrValue.Size;
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
void __fastcall Scaleform::StrFormatter::StrFormatter(Scaleform::StrFormatter *this, Scaleform::MsgFormat *f, const char *v)
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
void __fastcall Scaleform::StrFormatter::StrFormatter(Scaleform::StrFormatter *this, Scaleform::MsgFormat *f, Scaleform::StringDataPtr *v)
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
void __fastcall Scaleform::StrFormatter::StrFormatter(Scaleform::StrFormatter *this, Scaleform::MsgFormat *f, Scaleform::String *v)
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
  unsigned __int64 v2; // r9
  const char *v3; // r10
  unsigned __int64 v4; // rax
  Scaleform::StringDataPtr *v5; // rsi
  Scaleform::StrFormatter *v6; // rdi
  char v7; // r8
  Scaleform::MsgFormat *v8; // rax
  Scaleform::LocaleProvider *v9; // rcx
  __int64 v10; // rax
  Scaleform::Formatter *v11; // rbx
  unsigned __int64 v12; // r8
  __int64 v13; // r9
  __int64 v14; // rdx
  const char *v15; // [rsp+20h] [rbp-48h]
  unsigned __int64 v16; // [rsp+28h] [rbp-40h]
  __int64 v17; // [rsp+30h] [rbp-38h]
  unsigned __int64 v18; // [rsp+38h] [rbp-30h]
  Scaleform::MsgFormat *v19; // [rsp+48h] [rbp-20h]
  __int64 *v20; // [rsp+50h] [rbp-18h]
  __int64 *v21; // [rsp+58h] [rbp-10h]

  v2 = str->Size;
  v3 = str->pStr;
  v4 = 0i64;
  v5 = str;
  v6 = this;
  if ( v2 )
  {
    do
    {
      v7 = v3[v4];
      if ( !v7 )
        break;
      if ( v7 == 58 )
        break;
      ++v4;
    }
    while ( v4 < v2 );
  }
  v16 = v4;
  v8 = this->pParentFmt;
  v15 = v3;
  if ( v8 )
  {
    v9 = v8->pLocaleProvider;
    if ( v9 )
    {
      v19 = v8;
      v20 = (__int64 *)&v15;
      v21 = &v17;
      v10 = (__int64)v9->vfptr->MakeFormatter(
                       (Scaleform::FormatterFactory *)&v9->vfptr,
                       (Scaleform::FormatterFactory::Args *)&v19);
      v11 = (Scaleform::Formatter *)v10;
      if ( v10 )
      {
        v12 = v5->Size;
        v13 = v16 + 1;
        if ( v12 < v16 + 1 )
          v13 = v5->Size;
        v14 = (__int64)&v5->pStr[v13];
        v18 = v12 - v13;
        v17 = v14;
        if ( v12 != v13 )
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v10 + 16i64))(v10, &v17);
        Scaleform::MsgFormat::ReplaceFormatter(v6->pParentFmt, (Scaleform::Formatter *)&v6->vfptr, v11, 1);
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
Scaleform::StringDataPtr *__fastcall Scaleform::StrFormatter::GetResult(Scaleform::StrFormatter *this, Scaleform::StringDataPtr *result)
{
  result->pStr = this->Value.pStr;
  result->Size = this->Value.Size;
  return result;
}

// File Line: 323
// RVA: 0x99CFB0
void __fastcall Scaleform::BoolFormatter::Parse(Scaleform::BoolFormatter *this, Scaleform::StringDataPtr *str)
{
  unsigned __int64 v2; // r9
  const char *v3; // r10
  unsigned __int64 v4; // r8
  Scaleform::StringDataPtr *v5; // rsi
  Scaleform::BoolFormatter *v6; // rbx
  unsigned __int64 v7; // rax
  char v8; // dl
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // r9
  const char *v11; // rdx
  unsigned __int64 v12; // rax
  char v13; // cl
  char v14; // cl
  unsigned __int64 v15; // rax
  const char *v16; // rdx
  unsigned __int64 v17; // r9
  char v18; // al
  Scaleform::MsgFormat *v19; // rax
  Scaleform::LocaleProvider *v20; // rcx
  __int64 v21; // rax
  Scaleform::Formatter *v22; // rdi
  unsigned __int64 v23; // r8
  __int64 v24; // r9
  __int64 v25; // rdx
  const char *v26; // [rsp+20h] [rbp-48h]
  unsigned __int64 v27; // [rsp+28h] [rbp-40h]
  __int64 v28; // [rsp+30h] [rbp-38h]
  unsigned __int64 v29; // [rsp+38h] [rbp-30h]
  Scaleform::MsgFormat *v30; // [rsp+48h] [rbp-20h]
  __int64 *v31; // [rsp+50h] [rbp-18h]
  __int64 *v32; // [rsp+58h] [rbp-10h]

  v2 = str->Size;
  v3 = str->pStr;
  v4 = 0i64;
  v5 = str;
  v6 = this;
  v7 = 0i64;
  if ( v2 )
  {
    do
    {
      v8 = v3[v7];
      if ( !v8 )
        break;
      if ( v8 == 58 )
        break;
      ++v7;
    }
    while ( v7 < v2 );
  }
  v26 = v3;
  v27 = v7;
  if ( v3 && v7 )
  {
    if ( *v3 != 115 || v3[1] != 119 )
    {
      v19 = this->pParentFmt;
      v20 = v19->pLocaleProvider;
      if ( v20 )
      {
        v30 = v19;
        v31 = (__int64 *)&v26;
        v32 = &v28;
        v21 = (__int64)v20->vfptr->MakeFormatter(
                         (Scaleform::FormatterFactory *)&v20->vfptr,
                         (Scaleform::FormatterFactory::Args *)&v30);
        v22 = (Scaleform::Formatter *)v21;
        if ( v21 )
        {
          v23 = v5->Size;
          v24 = v27 + 1;
          if ( v23 < v27 + 1 )
            v24 = v5->Size;
          v25 = (__int64)&v5->pStr[v24];
          v29 = v23 - v24;
          v28 = v25;
          if ( v23 != v24 )
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v21 + 16i64))(v21, &v28);
          Scaleform::MsgFormat::ReplaceFormatter(v6->pParentFmt, (Scaleform::Formatter *)&v6->vfptr, v22, 1);
        }
      }
    }
    else
    {
      v9 = v7 + 1;
      if ( v2 < v9 )
        v9 = v2;
      v10 = v2 - v9;
      v11 = &v3[v9];
      v12 = 0i64;
      if ( v10 )
      {
        do
        {
          v13 = v11[v12];
          if ( !v13 )
            break;
          if ( v13 == 58 )
            break;
          ++v12;
        }
        while ( v12 < v10 );
      }
      v14 = *((_BYTE *)v6 + 24);
      v6->result.pStr = v11;
      v6->result.Size = v12;
      if ( !(v14 & 1) )
      {
        v15 = v12 + 1;
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
        v6->result.pStr = v16;
        v6->result.Size = v4;
      }
      *((_BYTE *)v6 + 24) = v14 | 2;
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
    if ( !(v1 & 2) )
    {
      if ( v1 & 1 )
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
Scaleform::StringDataPtr *__fastcall Scaleform::BoolFormatter::GetResult(Scaleform::BoolFormatter *this, Scaleform::StringDataPtr *result)
{
  result->pStr = this->result.pStr;
  result->Size = this->result.Size;
  return result;
}

// File Line: 401
// RVA: 0x958D80
char *__fastcall Scaleform::AppendCharLeft(char *buff, unsigned __int64 buffSz, char *value_ptr, unsigned int ucs_char)
{
  char *v4; // rbx
  signed int v5; // eax
  __int64 pindex; // [rsp+20h] [rbp-18h]

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
    pindex = 0i64;
    Scaleform::UTF8Util::EncodeCharSafe(v4, buffSz, &pindex, ucs_char);
  }
  return v4;
}

// File Line: 433
// RVA: 0x9A5E80
void __fastcall Scaleform::NumericBase::ReadPrintFormat(Scaleform::NumericBase *this, Scaleform::StringDataPtr *token)
{
  unsigned __int64 v2; // r8
  Scaleform::StringDataPtr *v3; // r9
  Scaleform::NumericBase *v4; // rbx
  const char *v5; // rdx
  signed __int64 v6; // rdx
  const char *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // rax
  unsigned __int64 v12; // rax
  signed __int64 v13; // rdx
  char v14; // al
  signed __int64 v15; // rdx
  __int64 v16; // rcx
  __int64 v17; // rax
  signed __int64 v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // rax
  signed __int64 v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // rax
  Scaleform::StringDataPtr str; // [rsp+20h] [rbp-68h]
  __int64 v25; // [rsp+30h] [rbp-58h]
  __int64 v26; // [rsp+38h] [rbp-50h]
  __int64 v27; // [rsp+40h] [rbp-48h]
  __int64 v28; // [rsp+48h] [rbp-40h]
  __int64 v29; // [rsp+50h] [rbp-38h]
  __int64 v30; // [rsp+58h] [rbp-30h]
  __int64 v31; // [rsp+60h] [rbp-28h]
  __int64 v32; // [rsp+68h] [rbp-20h]
  const char *v33; // [rsp+70h] [rbp-18h]
  unsigned __int64 v34; // [rsp+78h] [rbp-10h]

  v2 = token->Size;
  v3 = token;
  v4 = this;
  if ( v2 )
  {
    v5 = token->pStr;
    if ( v5 )
    {
      switch ( *v5 )
      {
        case 32:
          *((_BYTE *)this + 6) |= 2u;
          v9 = 1i64;
          if ( v3->Size < 1 )
            v9 = v3->Size;
          v3->pStr += v9;
          v10 = (__int64)v3->pStr;
          v3->Size -= v9;
          v11 = v3->Size;
          v25 = v10;
          v26 = v11;
          Scaleform::NumericBase::ReadPrintFormat(v4, (Scaleform::StringDataPtr *)&v25);
          break;
        case 35:
          *((_BYTE *)this + 6) |= 8u;
          v18 = 1i64;
          if ( v3->Size < 1 )
            v18 = v3->Size;
          v3->pStr += v18;
          v19 = (__int64)v3->pStr;
          v3->Size -= v18;
          v20 = v3->Size;
          v29 = v19;
          v30 = v20;
          Scaleform::NumericBase::ReadPrintFormat(v4, (Scaleform::StringDataPtr *)&v29);
          break;
        case 43:
          *((_BYTE *)this + 5) |= 0x80u;
          v15 = 1i64;
          if ( v3->Size < 1 )
            v15 = v3->Size;
          v3->pStr += v15;
          v16 = (__int64)v3->pStr;
          v3->Size -= v15;
          v17 = v3->Size;
          v27 = v16;
          v28 = v17;
          Scaleform::NumericBase::ReadPrintFormat(v4, (Scaleform::StringDataPtr *)&v27);
          break;
        case 45:
          *((_BYTE *)this + 6) |= 4u;
          v6 = 1i64;
          if ( v3->Size < 1 )
            v6 = v3->Size;
          v3->pStr += v6;
          v7 = v3->pStr;
          v3->Size -= v6;
          v8 = v3->Size;
          str.pStr = v7;
          str.Size = v8;
          Scaleform::NumericBase::ReadPrintFormat(v4, &str);
          break;
        case 46:
          *(_DWORD *)this &= 0xFFFFFFE0;
          v12 = v3->Size;
          v13 = 1i64;
          if ( v12 < 1 )
            v13 = v3->Size;
          v3->pStr += v13;
          v3->Size = v12 - v13;
          v14 = Scaleform::ReadInteger(v3, *(_DWORD *)this & 0x1F, 58);
          *(_DWORD *)v4 &= 0xFFFFFFE0;
          *(_DWORD *)v4 |= v14 & 0x1F;
          break;
        case 48:
          *((_BYTE *)this + 4) &= 0xB0u;
          *((_BYTE *)this + 4) |= 0x30u;
          v21 = 1i64;
          if ( v3->Size < 1 )
            v21 = v3->Size;
          v3->pStr += v21;
          v22 = (__int64)v3->pStr;
          v3->Size -= v21;
          v23 = v3->Size;
          v31 = v22;
          v32 = v23;
          Scaleform::NumericBase::ReadPrintFormat(v4, (Scaleform::StringDataPtr *)&v31);
          break;
        default:
          v33 = v5;
          v34 = v2;
          Scaleform::NumericBase::ReadWidth(this, (Scaleform::StringDataPtr *)&v33);
          break;
      }
    }
  }
}

// File Line: 474
// RVA: 0x9A6170
void __fastcall Scaleform::NumericBase::ReadWidth(Scaleform::NumericBase *this, Scaleform::StringDataPtr *token)
{
  unsigned __int64 v2; // rax
  Scaleform::StringDataPtr *v3; // rsi
  Scaleform::NumericBase *v4; // rdi
  signed __int64 v5; // rbx
  char v6; // al
  unsigned __int64 v7; // rcx
  signed __int64 v8; // rax
  char v9; // al

  v2 = token->Size;
  v3 = token;
  v4 = this;
  if ( v2 )
  {
    v5 = 0i64;
    if ( v2 )
    {
      while ( token->pStr[v5] != 46 )
      {
        if ( ++v5 >= v2 )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      v5 = -1i64;
    }
    v6 = Scaleform::ReadInteger(token, (*(_DWORD *)this >> 5) & 0x1F, 58);
    *(_DWORD *)v4 &= 0xFFFFFC1F;
    *(_DWORD *)v4 |= 32 * (v6 & 0x1F);
    if ( v5 >= 0 )
    {
      *(_DWORD *)v4 &= 0xFFFFFFE0;
      v7 = v3->Size;
      v8 = 1i64;
      if ( v7 < 1 )
        v8 = v3->Size;
      v3->pStr += v8;
      v3->Size = v7 - v8;
      v9 = Scaleform::ReadInteger(v3, *(_DWORD *)v4 & 0x1F, 58);
      *(_DWORD *)v4 &= 0xFFFFFFE0;
      *(_DWORD *)v4 |= v9 & 0x1F;
    }
  }
}

// File Line: 495
// RVA: 0x9BB050
void __fastcall Scaleform::NumericBase::ULongLong2String(Scaleform::NumericBase *this, char *buff, unsigned __int64 value, bool separator, unsigned int base)
{
  unsigned __int64 v5; // r11
  char *v6; // rsi
  signed int v7; // er9
  const char *v8; // rbx
  char *v9; // r10
  unsigned __int64 v10; // rdx
  char v11; // al

  v5 = value;
  v6 = buff;
  if ( !separator || base != 10 || (v7 = 3, !(*((_BYTE *)this + 5) & 0x7F)) )
    v7 = 1000;
  v8 = a01234567_0;
  if ( !(*((_BYTE *)this + 6) & 1) )
    v8 = "0123456789abcdef";
  if ( base - 2 <= 0xE )
  {
    do
    {
      v9 = this->ValueStr;
      if ( v6 == v9 )
        break;
      v10 = v5 % base;
      v5 /= base;
      if ( !v7 )
      {
        v7 = 3;
        v11 = 2 * *((_BYTE *)this + 5);
        this->ValueStr = v9 - 1;
        *(v9 - 1) = v11 >> 1;
      }
      --this->ValueStr;
      --v7;
      *this->ValueStr = v8[(unsigned __int8)v10];
    }
    while ( v5 );
  }
}

// File Line: 535
// RVA: 0x9BAFA0
void __fastcall Scaleform::NumericBase::ULong2String(Scaleform::NumericBase *this, char *buff, unsigned int value, bool separator, unsigned int base)
{
  unsigned int v5; // er10
  char *v6; // rdi
  signed int v7; // er9
  const char *v8; // r11
  char *v9; // r8
  unsigned int v10; // edx
  char *v11; // r8
  char v12; // al

  v5 = value;
  v6 = buff;
  if ( !separator || base != 10 || (v7 = 3, !(*((_BYTE *)this + 5) & 0x7F)) )
    v7 = 1000;
  v8 = a01234567_0;
  if ( !(*((_BYTE *)this + 6) & 1) )
    v8 = "0123456789abcdef";
  if ( base - 2 <= 0xE )
  {
    do
    {
      v9 = this->ValueStr;
      if ( v6 == v9 )
        break;
      v10 = v5 % base;
      v5 /= base;
      if ( !v7 )
      {
        v11 = v9 - 1;
        v7 = 3;
        v12 = 2 * *((_BYTE *)this + 5);
        this->ValueStr = v11;
        *v11 = v12 >> 1;
      }
      --this->ValueStr;
      --v7;
      *this->ValueStr = v8[(unsigned __int8)v10];
    }
    while ( v5 );
  }
}

// File Line: 620
// RVA: 0x93E390
void __fastcall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, unsigned int v)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = 0i64;
  this->IsConverted = 0;
  *(_DWORD *)&this->32 &= 0xFFFFFC21;
  *(_DWORD *)&this->32 |= 0x21u;
  *((_BYTE *)&this->32 + 4) &= 0xA0u;
  *((_BYTE *)&this->32 + 4) |= 0x20u;
  *((_BYTE *)&this->32 + 5) = 0;
  *((_BYTE *)&this->32 + 6) = *((_BYTE *)&this->32 + 6) & 0xF1 | 1;
  this->ValueStr = 0i64;
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::Formatter};
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::String::InitStruct};
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
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = 0i64;
  this->IsConverted = 0;
  *(_DWORD *)&this->32 &= 0xFFFFFC21;
  *(_DWORD *)&this->32 |= 0x21u;
  *((_BYTE *)&this->32 + 4) &= 0xA0u;
  *((_BYTE *)&this->32 + 4) |= 0x20u;
  *((_BYTE *)&this->32 + 5) = 0;
  *((_BYTE *)&this->32 + 6) = *((_BYTE *)&this->32 + 6) & 0xF1 | 1;
  this->ValueStr = 0i64;
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::Formatter};
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::String::InitStruct};
  *((_DWORD *)this + 12) &= 0xFFFFFFEA;
  *((_DWORD *)this + 12) |= 0xAu;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0xFD | 1;
  this->Value = v;
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}

// File Line: 661
// RVA: 0x93E430
void __fastcall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, unsigned __int64 v)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = 0i64;
  this->IsConverted = 0;
  *(_DWORD *)&this->32 &= 0xFFFFFC21;
  *(_DWORD *)&this->32 |= 0x21u;
  *((_BYTE *)&this->32 + 4) &= 0xA0u;
  *((_BYTE *)&this->32 + 4) |= 0x20u;
  *((_BYTE *)&this->32 + 5) = 0;
  *((_BYTE *)&this->32 + 6) = *((_BYTE *)&this->32 + 6) & 0xF1 | 1;
  this->ValueStr = 0i64;
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::Formatter};
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::String::InitStruct};
  *((_DWORD *)this + 12) &= 0xFFFFFFEA;
  *((_DWORD *)this + 12) |= 0xAu;
  *((_BYTE *)this + 52) &= 0xFEu;
  *((_BYTE *)this + 52) |= 2u;
  this->Value = v;
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}

// File Line: 673
// RVA: 0x93E190
void __fastcall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, Scaleform::MsgFormat *f, int v)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = f;
  this->IsConverted = 0;
  *(_DWORD *)&this->32 &= 0xFFFFFC21;
  *(_DWORD *)&this->32 |= 0x21u;
  *((_BYTE *)&this->32 + 4) &= 0xA0u;
  *((_BYTE *)&this->32 + 4) |= 0x20u;
  *((_BYTE *)&this->32 + 5) = 0;
  *((_BYTE *)&this->32 + 6) = *((_BYTE *)&this->32 + 6) & 0xF1 | 1;
  this->ValueStr = 0i64;
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::Formatter};
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::String::InitStruct};
  *((_DWORD *)this + 12) &= 0xFFFFFFEA;
  *((_DWORD *)this + 12) |= 0xAu;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0xFD | 1;
  this->Value = v;
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}

// File Line: 706
// RVA: 0x93E240
void __fastcall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, Scaleform::MsgFormat *f, unsigned int v)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = f;
  this->IsConverted = 0;
  *(_DWORD *)&this->32 &= 0xFFFFFC21;
  *(_DWORD *)&this->32 |= 0x21u;
  *((_BYTE *)&this->32 + 4) &= 0xA0u;
  *((_BYTE *)&this->32 + 4) |= 0x20u;
  *((_BYTE *)&this->32 + 5) = 0;
  *((_BYTE *)&this->32 + 6) = *((_BYTE *)&this->32 + 6) & 0xF1 | 1;
  this->ValueStr = 0i64;
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::Formatter};
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::LongFormatter::`vftable{for `Scaleform::String::InitStruct};
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
  Scaleform::StringDataPtr *v2; // r15
  Scaleform::LongFormatter *v3; // rsi
  const char *v4; // r9
  unsigned __int64 v5; // r8
  Scaleform::Formatter *v6; // r14
  unsigned __int64 v7; // rbx
  char v8; // al
  const char *v9; // rdi
  signed __int64 v10; // rax
  char v11; // al
  unsigned __int64 v12; // rax
  char v13; // cl
  unsigned __int64 v14; // rax
  char v15; // cl
  unsigned __int64 v16; // rcx
  const char *v17; // r9
  unsigned __int64 v18; // r8
  char v19; // al
  __int64 v20; // rcx
  signed __int64 v21; // rcx
  unsigned __int64 v22; // rax
  signed __int64 v23; // rdx
  Scaleform::MemoryHeap *v24; // rcx
  int v25; // eax
  Scaleform::MsgFormat *v26; // rcx
  signed __int64 v27; // r8
  unsigned __int64 v28; // rdx
  Scaleform::StringDataPtr stra; // [rsp+20h] [rbp-69h]
  const char *v30; // [rsp+30h] [rbp-59h]
  unsigned __int64 v31; // [rsp+38h] [rbp-51h]
  Scaleform::MsgFormat **v32; // [rsp+40h] [rbp-49h]
  unsigned __int64 v33; // [rsp+48h] [rbp-41h]
  const char *v34; // [rsp+50h] [rbp-39h]
  unsigned __int64 v35; // [rsp+58h] [rbp-31h]
  const char *v36; // [rsp+60h] [rbp-29h]
  unsigned __int64 v37; // [rsp+68h] [rbp-21h]
  __int64 v38; // [rsp+70h] [rbp-19h]
  Scaleform::StringDataPtr *v39; // [rsp+78h] [rbp-11h]
  __int64 *v40; // [rsp+80h] [rbp-9h]
  __int64 v41; // [rsp+88h] [rbp-1h]
  char v42; // [rsp+90h] [rbp+7h]
  __int64 v43; // [rsp+98h] [rbp+Fh]
  __int64 v44; // [rsp+A0h] [rbp+17h]

  v44 = -2i64;
  v2 = str;
  v3 = this;
  v4 = str->pStr;
  stra.pStr = str->pStr;
  v5 = str->Size;
  stra.Size = v5;
  v6 = 0i64;
  if ( !v5 )
    return;
  while ( 2 )
  {
    v7 = 0i64;
    if ( v5 )
    {
      do
      {
        v8 = v4[v7];
        if ( !v8 )
          break;
        if ( v8 == 58 )
          break;
        ++v7;
      }
      while ( v7 < v5 );
    }
    v9 = v4;
    if ( !v4 || !v7 )
      return;
    v10 = v7 + 1;
    if ( v5 < v7 + 1 )
      v10 = v5;
    stra.pStr = &v4[v10];
    stra.Size = v5 - v10;
    if ( isdigit(*v4) )
    {
      v32 = (Scaleform::MsgFormat **)v9;
      v33 = v7;
      Scaleform::NumericBase::ReadPrintFormat(&v3->32, (Scaleform::StringDataPtr *)&v32);
      goto LABEL_40;
    }
    switch ( *v9 )
    {
      case 32:
      case 35:
      case 43:
      case 45:
      case 46:
        v34 = v9;
        v35 = v7;
        Scaleform::NumericBase::ReadPrintFormat(&v3->32, (Scaleform::StringDataPtr *)&v34);
        goto LABEL_40;
      case 88:
        goto LABEL_22;
      case 98:
        if ( !strncmp(v9, "base", 4ui64) )
        {
          v11 = Scaleform::ReadInteger(&stra, 10, 58);
          *((_DWORD *)v3 + 12) &= 0xFFFFFFE0;
          *((_DWORD *)v3 + 12) |= v11 & 0x1F;
        }
        goto LABEL_40;
      case 111:
        *((_DWORD *)v3 + 12) &= 0xFFFFFFE8;
        *((_DWORD *)v3 + 12) |= 8u;
        v12 = 0i64;
        if ( stra.Size )
        {
          do
          {
            v13 = stra.pStr[v12];
            if ( !v13 )
              break;
            if ( v13 == 58 )
              break;
            ++v12;
          }
          while ( v12 < stra.Size );
        }
        v36 = stra.pStr;
        v37 = v12;
        Scaleform::NumericBase::ReadPrintFormat(&v3->32, (Scaleform::StringDataPtr *)&v36);
        goto LABEL_40;
      case 115:
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
                *((_BYTE *)&v3->32 + 5) ^= (*stra.pStr ^ *((_BYTE *)&v3->32 + 5)) & 0x7F;
            }
            if ( v18 < v16 )
              v16 = v18;
            v4 = &v17[v16];
            stra.pStr = v4;
            v5 = v18 - v16;
            stra.Size = v5;
            goto LABEL_41;
          }
LABEL_40:
          v5 = stra.Size;
          v4 = stra.pStr;
LABEL_41:
          if ( !v5 )
            goto LABEL_55;
          continue;
        }
        v21 = (signed __int64)&v3->pParentFmt->MemPool;
        if ( v3->pParentFmt->MemPool.BuffSize < 0x48 )
        {
          v24 = *(Scaleform::MemoryHeap **)v21;
          if ( !v24 )
            v24 = Scaleform::Memory::pGlobalHeap;
          v6 = (Scaleform::Formatter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, signed __int64))v24->vfptr->Alloc)(
                                         v24,
                                         72i64,
                                         8i64);
        }
        else
        {
          v6 = (Scaleform::Formatter *)v3->pParentFmt->MemPool.BuffPtr;
          v3->pParentFmt->MemPool.BuffPtr = (char *)(((unsigned __int64)(&v6[2].IsConverted + 7) & 0xFFFFFFFFFFFFFFF8ui64)
                                                   + 8);
          v22 = ((unsigned __int64)(&v6[2].IsConverted + 7) & 0xFFFFFFFFFFFFFFF8ui64) - v21;
          if ( v22 >= 0x200 )
            v23 = 0i64;
          else
            v23 = 512 - v22;
          *(_QWORD *)(v21 + 528) = v23;
        }
        if ( v6 )
        {
          v25 = v3->Value;
          v26 = v3->pParentFmt;
          v6->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
          v6->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
          v6->pParentFmt = v26;
          v6->IsConverted = 0;
          v6->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::SwitchFormatter::`vftable;
          LODWORD(v6[1].vfptr) = v25;
          v32 = &v6[1].pParentFmt;
          v6[1].pParentFmt = 0i64;
          *(_QWORD *)&v6[1].IsConverted = 0i64;
          v6[2].vfptr = 0i64;
          v6[2].pParentFmt = 0i64;
          *(_QWORD *)&v6[2].IsConverted = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        stra.pStr += stra.Size;
        stra.Size = 0i64;
LABEL_55:
        if ( v6 )
        {
          v27 = v7 + 1;
          v28 = v2->Size;
          if ( v28 < v7 + 1 )
            v27 = v2->Size;
          v30 = &v2->pStr[v27];
          v31 = v28 - v27;
          if ( v28 != v27 )
            ((void (__fastcall *)(Scaleform::Formatter *, const char **, signed __int64, const char *))v6->vfptr[1].__vecDelDtor)(
              v6,
              &v30,
              v27,
              v4);
          Scaleform::MsgFormat::ReplaceFormatter(v3->pParentFmt, (Scaleform::Formatter *)&v3->vfptr, v6, 1);
        }
        return;
      case 120:
        *((_BYTE *)&v3->32 + 6) &= 0xFEu;
LABEL_22:
        *((_DWORD *)v3 + 12) &= 0xFFFFFFF0;
        *((_DWORD *)v3 + 12) |= 0x10u;
        v14 = 0i64;
        if ( stra.Size )
        {
          do
          {
            v15 = stra.pStr[v14];
            if ( !v15 )
              break;
            if ( v15 == 58 )
              break;
            ++v14;
          }
          while ( v14 < stra.Size );
        }
        v30 = stra.pStr;
        v31 = v14;
        Scaleform::NumericBase::ReadPrintFormat(&v3->32, (Scaleform::StringDataPtr *)&v30);
        goto LABEL_40;
      default:
        v20 = (__int64)v3->pParentFmt;
        if ( *(_QWORD *)(v20 + 32) )
        {
          v42 = 0;
          v43 = 0i64;
          v41 = v3->Value;
          v38 = v20;
          v39 = &stra;
          v40 = &v41;
          v6 = (Scaleform::Formatter *)(*(__int64 (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)(v20 + 32) + 8i64))(
                                         *(_QWORD *)(v20 + 32),
                                         &v38);
        }
        goto LABEL_40;
    }
  }
} *(_QWORD *)(v20 + 32),
                                         &v38);
        }
        goto LABEL_40;
    }
  }
}

// File Line: 830
// RVA: 0x962D10
void __fastcall Scaleform::LongFormatter::Convert(Scaleform::LongFormatter *this)
{
  Scaleform::LongFormatter *v1; // rbx
  char v2; // al
  unsigned __int64 i; // rcx
  __int64 v4; // rcx
  unsigned __int64 v5; // rdx
  signed int v6; // ecx
  int v7; // edx
  char v8; // cl
  char *v9; // rdx
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rax
  char *v12; // r14
  unsigned __int64 v13; // rax
  char *v14; // r14
  char v15; // al

  v1 = this;
  if ( !this->IsConverted )
  {
    if ( *(_BYTE *)&this->32 & 0x1F || this->Value )
    {
      v2 = *((_BYTE *)this + 52);
      if ( v2 & 2 )
      {
        Scaleform::NumericBase::ULongLong2String(
          &this->32,
          this->Buff,
          abs(this->Value),
          1,
          *((_DWORD *)this + 12) & 0x1F);
      }
      else if ( v2 & 1 )
      {
        Scaleform::NumericBase::ULong2String(&this->32, this->Buff, abs(this->Value), 1, *((_DWORD *)this + 12) & 0x1F);
      }
      else
      {
        Scaleform::NumericBase::ULong2String(&this->32, this->Buff, this->Value, 1, *((_DWORD *)this + 12) & 0x1F);
      }
    }
    for ( i = (char *)v1 - v1->ValueStr + 92; i < (*(_DWORD *)&v1->32 & 0x1Fu); *v1->ValueStr = 48 )
    {
      --v1->ValueStr;
      ++i;
    }
    if ( !(*(_BYTE *)&v1->32 & 0x1F) )
    {
      *((_BYTE *)&v1->32 + 4) &= 0xA0u;
      *((_BYTE *)&v1->32 + 4) |= 0x20u;
    }
    v4 = v1->Value;
    if ( v4 >= 0 )
    {
      v7 = *((_DWORD *)v1 + 12) & 0x1F;
      if ( !((v7 - 8) & 0xFFFFFFF7) )
      {
        if ( v4 )
        {
          v8 = *((_BYTE *)&v1->32 + 6);
          if ( v8 & 8 )
          {
            if ( v7 == 16 )
              *--v1->ValueStr = 32 * (~v8 & 1) | 0x58;
            *--v1->ValueStr = 48;
          }
        }
      }
    }
    else
    {
      if ( (*((_BYTE *)&v1->32 + 4) & 0x7F) == 48 )
      {
        v5 = (char *)v1 - v1->ValueStr + 92;
        while ( 1 )
        {
          v6 = *((_BYTE *)&v1->32 + 5) < 0 || *((_BYTE *)&v1->32 + 6) & 2 ? 1 : 0;
          if ( v5 >= ((*(_DWORD *)&v1->32 >> 5) & 0x1Fu) - v6 )
            break;
          --v1->ValueStr;
          ++v5;
          *v1->ValueStr = (char)(2 * *((_BYTE *)&v1->32 + 4)) >> 1;
        }
      }
      Scaleform::LongFormatter::AppendSignCharLeft(v1, v1->Value < 0);
    }
    if ( *((_BYTE *)&v1->32 + 6) & 2 )
    {
      if ( *((_BYTE *)&v1->32 + 5) >= 0 )
      {
        *((_BYTE *)&v1->32 + 4) &= 0xA0u;
        *((_BYTE *)&v1->32 + 4) |= 0x20u;
        if ( *((_BYTE *)v1 + 52) & 1 )
        {
          if ( v1->Value >= 0 )
            *--v1->ValueStr = 32;
        }
      }
    }
    v9 = v1->ValueStr;
    v10 = (char *)v1 - v9 + 92;
    v11 = (*(_DWORD *)&v1->32 >> 5) & 0x1F;
    if ( *((_BYTE *)&v1->32 + 6) & 4 )
    {
      if ( v10 < v11 )
      {
        v12 = &v1->Buff[-v11 + 28];
        memmove(v12, v9, (char *)v1 - v9 + 92);
        v13 = (unsigned __int64)v1->32;
        v1->ValueStr = v12;
        v14 = &v12[v10];
        if ( v10 < ((v13 >> 5) & 0x1F) )
        {
          do
          {
            ++v10;
            *(++v14 - 1) = (char)(2 * *((_BYTE *)&v1->32 + 4)) >> 1;
          }
          while ( v10 < ((*(_DWORD *)&v1->32 >> 5) & 0x1Fu) );
        }
      }
    }
    else if ( v10 < v11 )
    {
      do
      {
        v15 = *((_BYTE *)&v1->32 + 4);
        --v1->ValueStr;
        ++v10;
        *v1->ValueStr = (char)(2 * v15) >> 1;
      }
      while ( v10 < ((*(_DWORD *)&v1->32 >> 5) & 0x1Fu) );
    }
    v1->IsConverted = 1;
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
  Scaleform::LongFormatter *v2; // rbx
  Scaleform::MsgFormat *v3; // rcx
  bool v4; // di
  Scaleform::LocaleProvider *v5; // rcx
  __int64 v6; // rax
  unsigned int v7; // er9

  v2 = this;
  v3 = this->pParentFmt;
  v4 = negative;
  if ( v3 && (v5 = v3->pLocaleProvider) != 0i64 )
  {
    v6 = ((__int64 (*)(void))v5->vfptr[1].__vecDelDtor)();
    if ( v4 )
    {
      v7 = *(_DWORD *)(v6 + 36);
    }
    else
    {
      if ( *((_BYTE *)&v2->32 + 5) >= 0 )
        return;
      v7 = *(_DWORD *)(v6 + 32);
    }
    v2->ValueStr = Scaleform::AppendCharLeft(v2->Buff, 0x1Dui64, v2->ValueStr, v7);
  }
  else if ( negative )
  {
    *--v2->ValueStr = 45;
  }
  else if ( *((_BYTE *)&v2->32 + 5) < 0 )
  {
    *--v2->ValueStr = 43;
  }
}

// File Line: 974
// RVA: 0x93B3B0
void __fastcall Scaleform::DoubleFormatter::DoubleFormatter(Scaleform::DoubleFormatter *this, long double v)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = 0i64;
  this->IsConverted = 0;
  *(_DWORD *)&this->32 &= 0xFFFFFC21;
  *(_DWORD *)&this->32 |= 0x21u;
  *((_BYTE *)&this->32 + 4) &= 0xA0u;
  *((_BYTE *)&this->32 + 4) |= 0x20u;
  *((_BYTE *)&this->32 + 5) = 0;
  *((_BYTE *)&this->32 + 6) = *((_BYTE *)&this->32 + 6) & 0xF1 | 1;
  this->ValueStr = 0i64;
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::DoubleFormatter::`vftable{for `Scaleform::Formatter};
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::DoubleFormatter::`vftable{for `Scaleform::String::InitStruct};
  this->Type = 0;
  this->Value = v;
  this->Len = 0i64;
  this->ValueStr = &this->Buff[347];
  this->Buff[347] = 0;
  *(_DWORD *)&this->32 &= 0xFFFFFFE6;
  *(_DWORD *)&this->32 |= 6u;
}

// File Line: 986
// RVA: 0x93B310
void __fastcall Scaleform::DoubleFormatter::DoubleFormatter(Scaleform::DoubleFormatter *this, Scaleform::MsgFormat *f, long double v)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
  this->pParentFmt = f;
  this->IsConverted = 0;
  *(_DWORD *)&this->32 &= 0xFFFFFC21;
  *(_DWORD *)&this->32 |= 0x21u;
  *((_BYTE *)&this->32 + 4) &= 0xA0u;
  *((_BYTE *)&this->32 + 4) |= 0x20u;
  *((_BYTE *)&this->32 + 5) = 0;
  *((_BYTE *)&this->32 + 6) = *((_BYTE *)&this->32 + 6) & 0xF1 | 1;
  this->ValueStr = 0i64;
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::DoubleFormatter::`vftable{for `Scaleform::Formatter};
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::DoubleFormatter::`vftable{for `Scaleform::String::InitStruct};
  this->Type = 0;
  this->Value = v;
  this->Len = 0i64;
  this->ValueStr = &this->Buff[347];
  this->Buff[347] = 0;
  *(_DWORD *)&this->32 &= 0xFFFFFFE6;
  *(_DWORD *)&this->32 |= 6u;
}

// File Line: 994
// RVA: 0x99D140
void __fastcall Scaleform::DoubleFormatter::Parse(Scaleform::DoubleFormatter *this, Scaleform::StringDataPtr *str)
{
  Scaleform::StringDataPtr *v2; // r15
  Scaleform::DoubleFormatter *v3; // rsi
  unsigned __int64 v4; // r8
  Scaleform::Formatter *v5; // r14
  char *v6; // rbx
  char v7; // cl
  char *v8; // rdi
  signed __int64 v9; // rax
  char *v10; // rax
  char v11; // cl
  unsigned __int64 v12; // rax
  char v13; // cl
  unsigned __int64 v14; // rax
  char v15; // cl
  unsigned __int64 v16; // rcx
  char v17; // dl
  __int64 v18; // rcx
  double v19; // xmm0_8
  double v20; // xmm0_8
  signed __int64 v21; // rcx
  unsigned __int64 v22; // rdx
  signed __int64 v23; // rax
  Scaleform::MemoryHeap *v24; // rcx
  double v25; // xmm0_8
  double v26; // xmm0_8
  Scaleform::MsgFormat *v27; // rax
  signed __int64 v28; // r8
  unsigned __int64 v29; // rdx
  Scaleform::MsgFormat **v30; // [rsp+8h] [rbp-79h]
  __int64 v31; // [rsp+18h] [rbp-69h]
  char *Str1; // [rsp+20h] [rbp-61h]
  unsigned __int64 v33; // [rsp+28h] [rbp-59h]
  char *v34; // [rsp+30h] [rbp-51h]
  char *v35; // [rsp+38h] [rbp-49h]
  unsigned __int64 v36; // [rsp+40h] [rbp-41h]
  __int64 v37; // [rsp+48h] [rbp-39h]
  char **v38; // [rsp+50h] [rbp-31h]
  __int64 *v39; // [rsp+58h] [rbp-29h]
  __int64 v40; // [rsp+60h] [rbp-21h]
  char v41; // [rsp+68h] [rbp-19h]
  __int64 v42; // [rsp+70h] [rbp-11h]
  __int64 v43; // [rsp+78h] [rbp-9h]
  __int64 v44; // [rsp+F0h] [rbp+6Fh]
  Scaleform::Formatter *v45; // [rsp+F8h] [rbp+77h]
  Scaleform::MsgFormat **v46; // [rsp+100h] [rbp+7Fh]

  v43 = -2i64;
  v2 = str;
  v3 = this;
  Str1 = (char *)str->pStr;
  v4 = str->Size;
  v33 = v4;
  v5 = 0i64;
  if ( !v4 )
    return;
  while ( 2 )
  {
    v6 = 0i64;
    if ( v4 )
    {
      do
      {
        v7 = v6[(_QWORD)Str1];
        if ( !v7 )
          break;
        if ( v7 == 58 )
          break;
        ++v6;
      }
      while ( (unsigned __int64)v6 < v4 );
    }
    v8 = Str1;
    if ( !Str1 || !v6 )
      return;
    v9 = (signed __int64)(v6 + 1);
    if ( v4 < (unsigned __int64)(v6 + 1) )
      v9 = v4;
    Str1 += v9;
    v33 = v4 - v9;
    if ( isdigit(*v8) )
    {
      Scaleform::NumericBase::ReadPrintFormat(&v3->32, (Scaleform::StringDataPtr *)&v30);
      goto LABEL_44;
    }
    switch ( *v8 )
    {
      case 32:
      case 35:
      case 43:
      case 45:
      case 46:
        v33 = (unsigned __int64)v8;
        v34 = v6;
        Scaleform::NumericBase::ReadPrintFormat(&v3->32, (Scaleform::StringDataPtr *)&v33);
        goto LABEL_44;
      case 69:
        goto LABEL_20;
      case 71:
        goto LABEL_26;
      case 101:
        *((_BYTE *)&v3->32 + 6) &= 0xFEu;
LABEL_20:
        v3->Type = 1;
        v12 = 0i64;
        if ( v33 )
        {
          do
          {
            v13 = Str1[v12];
            if ( !v13 )
              break;
            if ( v13 == 58 )
              break;
            ++v12;
          }
          while ( v12 < v33 );
        }
        v35 = Str1;
        v36 = v12;
        Scaleform::NumericBase::ReadPrintFormat(&v3->32, (Scaleform::StringDataPtr *)&v35);
        goto LABEL_44;
      case 102:
        v3->Type = 0;
        v10 = 0i64;
        if ( v33 )
        {
          do
          {
            v11 = v10[(_QWORD)Str1];
            if ( !v11 )
              break;
            if ( v11 == 58 )
              break;
            ++v10;
          }
          while ( (unsigned __int64)v10 < v33 );
        }
        Str1 = v10;
        Scaleform::NumericBase::ReadPrintFormat(&v3->32, (Scaleform::StringDataPtr *)&v31);
        goto LABEL_44;
      case 103:
        *((_BYTE *)&v3->32 + 6) &= 0xFEu;
LABEL_26:
        v3->Type = 2;
        v14 = 0i64;
        if ( v33 )
        {
          do
          {
            v15 = Str1[v14];
            if ( !v15 )
              break;
            if ( v15 == 58 )
              break;
            ++v14;
          }
          while ( v14 < v33 );
        }
        v34 = Str1;
        v35 = (char *)v14;
        Scaleform::NumericBase::ReadPrintFormat(&v3->32, (Scaleform::StringDataPtr *)&v34);
        goto LABEL_44;
      case 115:
        if ( v8[1] != 119 )
        {
          if ( !strncmp(v8, "sep", 3ui64) )
          {
            v16 = 0i64;
            v4 = v33;
            if ( !v33 )
              goto LABEL_62;
            do
            {
              v17 = Str1[v16];
              if ( !v17 )
                break;
              if ( v17 == 58 )
                break;
              ++v16;
            }
            while ( v16 < v33 );
            if ( v16 )
              *((_BYTE *)&v3->32 + 5) ^= (*Str1 ^ *((_BYTE *)&v3->32 + 5)) & 0x7F;
            goto LABEL_45;
          }
LABEL_44:
          v4 = v33;
LABEL_45:
          if ( !v4 )
            goto LABEL_62;
          continue;
        }
        v21 = (signed __int64)&v3->pParentFmt->MemPool;
        v44 = v21;
        if ( *(_QWORD *)(v21 + 528) < 0x48ui64 )
        {
          v24 = *(Scaleform::MemoryHeap **)v21;
          if ( !v24 )
            v24 = Scaleform::Memory::pGlobalHeap;
          v5 = (Scaleform::Formatter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, signed __int64))v24->vfptr->Alloc)(
                                         v24,
                                         72i64,
                                         8i64);
        }
        else
        {
          v5 = *(Scaleform::Formatter **)(v21 + 520);
          *(_QWORD *)(v21 + 520) = ((unsigned __int64)(&v5[2].IsConverted + 7) & 0xFFFFFFFFFFFFFFF8ui64) + 8;
          v22 = ((unsigned __int64)(&v5[2].IsConverted + 7) & 0xFFFFFFFFFFFFFFF8ui64) - v21;
          if ( v22 >= 0x200 )
            v23 = 0i64;
          else
            v23 = 512 - v22;
          *(_QWORD *)(v21 + 528) = v23;
        }
        v45 = v5;
        if ( v5 )
        {
          v25 = v3->Value;
          if ( v25 <= 0.0 )
            v26 = v25 - 0.5;
          else
            v26 = v25 + 0.5;
          v27 = v3->pParentFmt;
          v5->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
          v5->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::Formatter::`vftable;
          v5->pParentFmt = v27;
          v5->IsConverted = 0;
          v5->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::SwitchFormatter::`vftable;
          LODWORD(v5[1].vfptr) = (signed int)v26;
          v46 = &v5[1].pParentFmt;
          v30 = &v5[1].pParentFmt;
          v5[1].pParentFmt = 0i64;
          *(_QWORD *)&v5[1].IsConverted = 0i64;
          v5[2].vfptr = 0i64;
          v5[2].pParentFmt = 0i64;
          *(_QWORD *)&v5[2].IsConverted = 0i64;
        }
        else
        {
          v5 = 0i64;
        }
        Str1 += v33;
        v33 = 0i64;
LABEL_62:
        if ( v5 )
        {
          v28 = (signed __int64)(v6 + 1);
          v29 = v2->Size;
          if ( v29 < (unsigned __int64)(v6 + 1) )
            v28 = v2->Size;
          v34 = (char *)&v2->pStr[v28];
          v35 = (char *)(v29 - v28);
          if ( v29 != v28 )
            v5->vfptr[1].__vecDelDtor((Scaleform::FmtResource *)&v5->vfptr, (unsigned int)&v34);
          Scaleform::MsgFormat::ReplaceFormatter(v3->pParentFmt, (Scaleform::Formatter *)&v3->vfptr, v5, 1);
        }
        return;
      default:
        v18 = (__int64)v3->pParentFmt;
        if ( *(_QWORD *)(v18 + 32) )
        {
          v19 = v3->Value;
          if ( v19 <= 0.0 )
            v20 = v19 - 0.5;
          else
            v20 = v19 + 0.5;
          v41 = 1;
          v42 = 0i64;
          v40 = (signed int)v20;
          v37 = v18;
          v38 = &Str1;
          v39 = &v40;
          v5 = (Scaleform::Formatter *)(*(__int64 (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)(v18 + 32) + 8i64))(
                                         *(_QWORD *)(v18 + 32),
                                         &v37);
        }
        goto LABEL_44;
    }
  }
}         v5 = (Scaleform::Formatter *)(*(__int64 (__fastcall **)(_QWORD, __int64 *))(**(_QWORD **)(v18 + 32) + 8i64))(
                                         *(_QWORD *)(v18 + 32),
                                         &v37);
        }
        goto LAB

// File Line: 1232
// RVA: 0x962BB0
void __fastcall Scaleform::DoubleFormatter::Convert(Scaleform::DoubleFormatter *this)
{
  Scaleform::DoubleFormatter *v1; // rbx
  Scaleform::DoubleFormatter::PresentationType v2; // ecx
  char v3; // dl
  int v4; // ecx
  bool v5; // zf
  char *v6; // rcx
  char v7; // al
  unsigned int v8; // er9
  signed __int64 v9; // rax
  char *v10; // rax
  char *v11; // rax
  char format[2]; // [rsp+30h] [rbp-48h]
  char v13; // [rsp+32h] [rbp-46h]
  char v14; // [rsp+33h] [rbp-45h]
  char dest; // [rsp+50h] [rbp-28h]

  v1 = this;
  if ( !this->IsConverted )
  {
    v2 = this->Type;
    v3 = 32;
    if ( v2 )
    {
      v4 = v2 - 1;
      if ( v4 )
      {
        if ( v4 == 1 )
          v3 = 32 * (~*((_BYTE *)&v1->32 + 6) & 1) | 0x47;
      }
      else
      {
        v3 = 32 * (~*((_BYTE *)&v1->32 + 6) & 1) | 0x45;
      }
    }
    else
    {
      v3 = 102;
    }
    v5 = *((_BYTE *)&v1->32 + 5) >= 0;
    *(_WORD *)format = 9509;
    v6 = &v13;
    if ( !v5 )
    {
      v13 = 43;
      v6 = &v14;
    }
    v7 = *((_BYTE *)&v1->32 + 6);
    if ( v7 & 8 )
      *v6++ = 35;
    if ( v7 & 2 )
      *v6++ = 32;
    if ( v7 & 4 )
      *v6++ = 45;
    if ( (*((_BYTE *)&v1->32 + 4) & 0x7F) == 48 )
      *v6++ = 48;
    v8 = (unsigned int)v1->32;
    if ( ((v8 >> 5) & 0x1F) == 1 )
    {
      *(_WORD *)v6 = 9518;
      v6[2] = 100;
      v6[3] = v3;
      v6[4] = 0;
      Scaleform::SFsprintf(&dest, 0x20ui64, format, v8 & 0x1F);
    }
    else
    {
      *(_DWORD *)v6 = 623797285;
      v6[4] = 100;
      v6[5] = v3;
      v6[6] = 0;
      Scaleform::SFsprintf(&dest, 0x20ui64, format);
    }
    v9 = Scaleform::SFsprintf(v1->Buff, 0x15Cui64, &dest, v1->Value);
    v1->ValueStr = v1->Buff;
    v1->Len = v9;
    if ( v1->Buff[0] )
    {
      while ( 1 )
      {
        v10 = v1->ValueStr;
        if ( *v10 == 44 )
          break;
        v11 = v10 + 1;
        v1->ValueStr = v11;
        if ( !*v11 )
          goto LABEL_26;
      }
      *v10 = 46;
    }
LABEL_26:
    v1->ValueStr = v1->Buff;
    v1->IsConverted = 1;
  }
}

// File Line: 1361
// RVA: 0x98B100
Scaleform::StringDataPtr *__fastcall Scaleform::LongFormatter::GetResult(Scaleform::LongFormatter *this, Scaleform::StringDataPtr *result)
{
  Scaleform::StringDataPtr *v2; // rdi
  Scaleform::LongFormatter *v3; // rbx
  __int64 v4; // rax
  char *v5; // rcx

  v2 = result;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr[2].Reflect)();
  v5 = v3->ValueStr;
  v2->Size = v4;
  v2->pStr = v5;
  return v2;
}

// File Line: 1366
// RVA: 0x98B6C0
SSExpressionBase *__fastcall Scaleform::GFx::MovieImpl::GetHeap(SSClosureInfoMethod *this)
{
  return this->i_expr_p;
}

// File Line: 1375
// RVA: 0x993F30
void __fastcall Scaleform::DoubleFormatter::InitString(Scaleform::LongFormatter *this, char *pbuffer, unsigned __int64 size)
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
  unsigned __int64 v2; // r9
  const char *v3; // r10
  Scaleform::Formatter *v4; // rbx
  Scaleform::StringDataPtr *v5; // rsi
  Scaleform::ResourceFormatter *v6; // rdi
  unsigned __int64 v7; // r8
  char v8; // al
  Scaleform::MsgFormat *v9; // rax
  Scaleform::LocaleProvider *v10; // rcx
  __int64 v11; // rax
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // rax
  const char *v15; // [rsp+20h] [rbp-58h]
  unsigned __int64 v16; // [rsp+28h] [rbp-50h]
  __int128 v17; // [rsp+30h] [rbp-48h]
  __m128i v18; // [rsp+40h] [rbp-38h]
  Scaleform::MsgFormat *v19; // [rsp+50h] [rbp-28h]
  __int64 *v20; // [rsp+58h] [rbp-20h]
  Scaleform::ResourceFormatter::ValueType *v21; // [rsp+60h] [rbp-18h]

  v2 = str->Size;
  v3 = str->pStr;
  v4 = 0i64;
  v5 = str;
  v6 = this;
  v17 = 0ui64;
  v7 = 0i64;
  if ( v2 )
  {
    do
    {
      v8 = v3[v7];
      if ( !v8 )
        break;
      if ( v8 == 58 )
        break;
      ++v7;
    }
    while ( v7 < v2 );
  }
  v9 = this->pParentFmt;
  v15 = v3;
  v16 = v7;
  v10 = v9->pLocaleProvider;
  if ( v10 )
  {
    v19 = v9;
    v20 = (__int64 *)&v15;
    v21 = &v6->Value;
    v11 = (__int64)v10->vfptr->MakeFormatter(
                     (Scaleform::FormatterFactory *)&v10->vfptr,
                     (Scaleform::FormatterFactory::Args *)&v19);
    v7 = v16;
    v4 = (Scaleform::Formatter *)v11;
  }
  v12 = v5->Size;
  v13 = v7 + 1;
  if ( v12 < v13 )
    v13 = v5->Size;
  v14 = v12 - v13;
  v18.m128i_i64[0] = (__int64)&v5->pStr[v13];
  v18.m128i_i64[1] = v14;
  _mm_store_si128((__m128i *)&v17, v18);
  if ( v4 )
  {
    if ( v14 )
      v4->vfptr[1].__vecDelDtor((Scaleform::FmtResource *)&v4->vfptr, (unsigned int)&v17);
    Scaleform::MsgFormat::ReplaceFormatter(v6->pParentFmt, (Scaleform::Formatter *)&v6->vfptr, v4, 1);
  }
}

// File Line: 1505
// RVA: 0x962F90
void __fastcall Scaleform::ResourceFormatter::Convert(Scaleform::ResourceFormatter *this)
{
  Scaleform::ResourceFormatter *v1; // rbx
  Scaleform::ResouceProvider *v2; // rcx
  __int64 v3; // rax
  int v4; // [rsp+20h] [rbp-28h]
  __int64 v5; // [rsp+28h] [rbp-20h]
  const char *v6; // [rsp+30h] [rbp-18h]
  __int64 v7; // [rsp+38h] [rbp-10h]

  v1 = this;
  if ( !this->IsConverted )
  {
    v2 = this->pRP;
    v4 = 0;
    v5 = 0i64;
    if ( v2 )
    {
      ((void (__fastcall *)(Scaleform::ResouceProvider *, const char **, Scaleform::ResourceFormatter::ValueType *, int *, _QWORD, __int64))v2->vfptr->MakeString)(
        v2,
        &v6,
        &v1->Value,
        &v4,
        *(_QWORD *)&v4,
        v5);
      v3 = v7;
      v1->Result.pStr = v6;
      v1->IsConverted = 1;
      v1->Result.Size = v3;
    }
    else
    {
      v1->Result.pStr = 0i64;
      v1->IsConverted = 1;
      v1->Result.Size = 0i64;
    }
  }
}

// File Line: 1514
// RVA: 0x98B130
Scaleform::StringDataPtr *__fastcall Scaleform::ResourceFormatter::GetResult(Scaleform::ResourceFormatter *this, Scaleform::StringDataPtr *result)
{
  result->pStr = this->Result.pStr;
  result->Size = this->Result.Size;
  return result;
}

// File Line: 1532
// RVA: 0x940000
void __fastcall Scaleform::MsgFormat::MsgFormat(Scaleform::MsgFormat *this, Scaleform::MsgFormat::Sink *r)
{
  char *v2; // rax
  Scaleform::ArrayPOD<Scaleform::MsgFormat::fmt_record,2,Scaleform::ArrayDefaultPolicy> *v3; // [rsp+30h] [rbp+18h]

  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::MsgFormat::`vftable;
  *(_WORD *)&this->EscapeChar = 37;
  *(_DWORD *)&this->NonPosParamNum = -65536;
  this->StrSize = 0i64;
  this->pLocaleProvider = 0i64;
  *(_QWORD *)&this->Result.Type = *(_QWORD *)&r->Type;
  this->Result.SinkData = r->SinkData;
  this->Data.Size = 0i64;
  v3 = &this->Data.DynamicArray;
  *(_OWORD *)&v3->Data.Data = 0ui64;
  v3->Data.Policy.Capacity = 0i64;
  this->MemPool.pHeap = 0i64;
  v2 = (char *)((((unsigned __int64)&this->MemPool.pHeap + 7) & 0xFFFFFFFFFFFFFFF8ui64) + 8);
  this->MemPool.BuffPtr = v2;
  this->MemPool.BuffSize = (char *)&this->MemPool - v2 + 520;
}

// File Line: 1542
// RVA: 0x94BA50
void __fastcall Scaleform::MsgFormat::~MsgFormat(Scaleform::MsgFormat *this)
{
  Scaleform::MsgFormat *v1; // r15
  Scaleform::MsgFormat::StackArray<Scaleform::MsgFormat::fmt_record,16,Scaleform::ArrayPOD<Scaleform::MsgFormat::fmt_record,2,Scaleform::ArrayDefaultPolicy> > *v2; // r14
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // rdi
  __int64 v5; // rsi
  signed __int64 v6; // rax
  signed __int64 v7; // rax
  void (__fastcall ***v8)(void *, _QWORD); // rbx

  v1 = this;
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::MsgFormat::`vftable;
  v2 = &this->Data;
  v3 = this->Data.Size;
  v4 = 0i64;
  if ( v3 )
  {
    v5 = 0i64;
    do
    {
      if ( v4 >= 0x10 )
        v6 = (signed __int64)&v2->DynamicArray.Data.Data[-16];
      else
        v6 = (signed __int64)v2->StaticArray;
      v7 = v5 + v6;
      if ( *(_DWORD *)v7 == 2 )
      {
        if ( *(_BYTE *)(v7 + 16) )
        {
          v8 = *(void (__fastcall ****)(void *, _QWORD))(v7 + 8);
          if ( v8 )
          {
            (**v8)(v8, 0i64);
            if ( v8 < (void (__fastcall ***)(void *, _QWORD))v1->MemPool.Buff
              || v8 >= (void (__fastcall ***)(void *, _QWORD))&v1->MemPool.BuffPtr )
            {
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
            }
          }
        }
      }
      ++v4;
      v5 += 24i64;
    }
    while ( v4 < v3 );
  }
  if ( v2->DynamicArray.Data.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v1->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
}

// File Line: 1564
// RVA: 0x954A70
void __fastcall Scaleform::MsgFormat::AddStringRecord(Scaleform::MsgFormat *this, Scaleform::StringDataPtr *str)
{
  const char *v2; // rbp
  Scaleform::MsgFormat::StackArray<Scaleform::MsgFormat::fmt_record,16,Scaleform::ArrayPOD<Scaleform::MsgFormat::fmt_record,2,Scaleform::ArrayDefaultPolicy> > *v3; // rsi
  unsigned __int64 v4; // rax
  unsigned __int64 *v5; // rcx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // r8
  Scaleform::MsgFormat::fmt_record *v9; // rax
  signed __int64 v10; // rdx
  unsigned __int64 v11; // [rsp+28h] [rbp-30h]
  unsigned __int64 v12; // [rsp+30h] [rbp-28h]

  v2 = str->pStr;
  v3 = &this->Data;
  LOBYTE(v11) = str->Size;
  v4 = this->Data.Size;
  LODWORD(v12) = 0;
  if ( v4 < 0x10 )
  {
    v5 = &v3->Size + 3 * v4;
    v5[4] = v12;
    v5[5] = (unsigned __int64)v2;
    v5[6] = v11;
    ++v3->Size;
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
      (Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data.DynamicArray.Data.Data,
      &this->Data.DynamicArray,
      v8);
    goto LABEL_9;
  }
LABEL_9:
  v9 = v3->DynamicArray.Data.Data;
  v3->DynamicArray.Data.Size = v7;
  v10 = (signed __int64)&v9[v7];
  *(_QWORD *)(v10 - 24) = v12;
  *(_QWORD *)(v10 - 16) = v2;
  *(_QWORD *)(v10 - 8) = v11;
  ++v3->Size;
}

// File Line: 1584
// RVA: 0x99DA70
void __fastcall Scaleform::MsgFormat::Parse(Scaleform::MsgFormat *this, const char *fmt)
{
  char v2; // r13
  const char *v3; // rbx
  Scaleform::MsgFormat *v4; // r15
  const char *v5; // rdi
  signed int v6; // esi
  char v7; // si
  int v8; // ecx
  char v9; // al
  char v10; // cl
  unsigned __int64 v11; // rax
  Scaleform::String::InitStructVtbl **v12; // rcx
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // r14
  unsigned __int64 v15; // r8
  Scaleform::MsgFormat::fmt_record *v16; // rax
  signed __int64 v17; // rdx
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // r14
  Scaleform::String::InitStructVtbl **v20; // rcx
  signed __int64 v21; // r14
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rsi
  unsigned __int64 v24; // r8
  Scaleform::MsgFormat::fmt_record *v25; // rax
  signed __int64 v26; // rdx
  Scaleform::String::InitStructVtbl *v27; // [rsp+28h] [rbp-48h]
  Scaleform::StringDataPtr str; // [rsp+30h] [rbp-40h]
  Scaleform::StringDataPtr v29; // [rsp+40h] [rbp-30h]
  Scaleform::String::InitStructVtbl *v30; // [rsp+50h] [rbp-20h]

  v2 = 0;
  v3 = fmt;
  v4 = this;
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
      if ( v6 != 1 )
        continue;
      if ( *v3 == 125 )
      {
        if ( v5 == v3 )
          goto LABEL_29;
        v7 = -1;
        if ( isspace(*v5) )
        {
          do
            v8 = (v5++)[1];
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
              v10 = (v5++)[1];
              if ( !v10 )
                goto LABEL_18;
            }
            if ( *v5 == 58 )
              ++v5;
          }
        }
        else
        {
          ++v4->NonPosParamNum;
        }
LABEL_18:
        BYTE1(v27) = v7;
        LODWORD(v30) = 1;
        LOBYTE(v27) = (_BYTE)v3 - (_BYTE)v5;
        v11 = v4->Data.Size;
        if ( v11 < 0x10 )
        {
          v12 = &v4->vfptr + 3 * v11;
          v12[12] = v30;
          v12[13] = (Scaleform::String::InitStructVtbl *)v5;
          v12[14] = v27;
LABEL_27:
          ++v4->Data.Size;
          if ( v4->UnboundFmtrInd == -1 )
            v4->UnboundFmtrInd = LOWORD(v4->Data.Size) - 1;
LABEL_29:
          ++v3;
          v6 = 0;
          v5 = v3;
          continue;
        }
        v13 = v4->Data.DynamicArray.Data.Size;
        v14 = v13 + 1;
        if ( v13 + 1 >= v13 )
        {
          if ( v14 > v4->Data.DynamicArray.Data.Policy.Capacity )
          {
            v15 = v14 + (v14 >> 2);
LABEL_25:
            Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy> *)&v4->Data.DynamicArray.Data.Data,
              &v4->Data.DynamicArray,
              v15);
          }
        }
        else if ( v14 < v4->Data.DynamicArray.Data.Policy.Capacity >> 1 )
        {
          v15 = v13 + 1;
          goto LABEL_25;
        }
        v16 = v4->Data.DynamicArray.Data.Data;
        v4->Data.DynamicArray.Data.Size = v14;
        v17 = (signed __int64)&v16[v14];
        *(_QWORD *)(v17 - 24) = v30;
        *(_QWORD *)(v17 - 16) = v5;
        *(_QWORD *)(v17 - 8) = v27;
        goto LABEL_27;
      }
      goto LABEL_32;
    }
    if ( v2 )
    {
      v2 = 0;
LABEL_32:
      ++v3;
      continue;
    }
    if ( *v3 == 123 )
    {
      if ( v5 != v3 )
      {
        str.pStr = v5;
        str.Size = v3 - v5;
        Scaleform::MsgFormat::AddStringRecord(v4, &str);
      }
      ++v3;
      v6 = 1;
      v5 = v3;
    }
    else
    {
      if ( *v3 != (unsigned __int8)v4->EscapeChar )
        goto LABEL_32;
      v21 = (signed __int64)(v3 + 1);
      if ( !v3[1] )
        goto LABEL_32;
      if ( v5 != v3 )
      {
        v29.pStr = v5;
        v29.Size = v3 - v5;
        Scaleform::MsgFormat::AddStringRecord(v4, &v29);
      }
      ++v3;
      v5 = (const char *)v21;
      v2 = 1;
    }
  }
  while ( *v3 );
  if ( !v6 && v5 != v3 )
  {
    v18 = v4->Data.Size;
    LODWORD(v30) = 0;
    LOBYTE(v29.Size) = (_BYTE)v3 - (_BYTE)v5;
    v19 = v29.Size;
    if ( v18 < 0x10 )
    {
      v20 = &v4->vfptr + 3 * v18;
      v20[12] = v30;
      v20[13] = (Scaleform::String::InitStructVtbl *)v5;
      v20[14] = (Scaleform::String::InitStructVtbl *)v19;
      goto LABEL_54;
    }
    v22 = v4->Data.DynamicArray.Data.Size;
    v23 = v22 + 1;
    if ( v22 + 1 >= v22 )
    {
      if ( v23 > v4->Data.DynamicArray.Data.Policy.Capacity )
      {
        v24 = v23 + (v23 >> 2);
LABEL_52:
        Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy> *)&v4->Data.DynamicArray.Data.Data,
          &v4->Data.DynamicArray,
          v24);
      }
    }
    else if ( v23 < v4->Data.DynamicArray.Data.Policy.Capacity >> 1 )
    {
      v24 = v22 + 1;
      goto LABEL_52;
    }
    v25 = v4->Data.DynamicArray.Data.Data;
    v4->Data.DynamicArray.Data.Size = v23;
    v26 = (signed __int64)&v25[v23];
    *(_QWORD *)(v26 - 24) = v30;
    *(_QWORD *)(v26 - 16) = v5;
    *(_QWORD *)(v26 - 8) = v19;
LABEL_54:
    ++v4->Data.Size;
  }
}

// File Line: 1976
// RVA: 0x9AA7F0
char __fastcall Scaleform::MsgFormat::ReplaceFormatter(Scaleform::MsgFormat *this, Scaleform::Formatter *oldf, Scaleform::Formatter *newf, bool allocated)
{
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // r10
  Scaleform::Formatter *v6; // rdi
  signed __int64 v7; // r11
  Scaleform::MsgFormat::fmt_record *v8; // rdx
  char result; // al
  __int64 v10; // [rsp+8h] [rbp-30h]
  __int64 v11; // [rsp+10h] [rbp-28h]

  v4 = this->Data.Size;
  v5 = 0i64;
  v6 = oldf;
  if ( !v4 )
    return 0;
  v7 = -384i64;
  while ( 1 )
  {
    v8 = v5 >= 0x10 ? (Scaleform::MsgFormat::fmt_record *)((char *)this->Data.DynamicArray.Data.Data + v7) : (Scaleform::StackMemPool<512,8,Scaleform::MemPoolImmediateFree> *)((char *)&this->MemPool + v7);
    if ( v8->RecType == 2 && v8->RecValue.Formatter.Formatter == v6 )
      break;
    ++v5;
    v7 += 24i64;
    if ( v5 >= v4 )
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
  unsigned __int64 v1; // r11
  unsigned __int64 v2; // rdx
  char v3; // r10
  signed __int64 v4; // r9
  Scaleform::MsgFormat::fmt_record *v5; // r8
  const char *v6; // ST00_8

  v1 = this->Data.Size;
  v2 = this->UnboundFmtrInd;
  v3 = 1;
  this->DataInd = -1i64;
  if ( v2 >= v1 )
    return 0;
  v4 = v2 - 16;
  while ( 1 )
  {
    if ( v2 >= 0x10 )
      v5 = &this->Data.DynamicArray.Data.Data[v4];
    else
      v5 = (Scaleform::MsgFormat::fmt_record *)((char *)&this->MemPool + v4 * 24);
    if ( v5->RecType != 1 )
    {
      if ( v3 )
        ++this->UnboundFmtrInd;
      goto LABEL_12;
    }
    v6 = v5->RecValue.String.Str;
    if ( *(_WORD *)&v5->RecValue.Formatter.Allocated >> 8 == this->FirstArgNum )
      break;
    if ( v3 )
      v3 = 0;
LABEL_12:
    ++v2;
    ++v4;
    if ( v2 >= v1 )
      return 0;
  }
  if ( v3 )
    ++this->UnboundFmtrInd;
  this->DataInd = v2;
  return 1;
}

// File Line: 2041
// RVA: 0x95AC90
void __fastcall Scaleform::MsgFormat::Bind(Scaleform::MsgFormat *this, Scaleform::Formatter *formatter, const bool allocated)
{
  unsigned __int64 v3; // r9
  bool v4; // bl
  Scaleform::Formatter *v5; // r11
  Scaleform::MsgFormat::StackArray<Scaleform::MsgFormat::fmt_record,16,Scaleform::ArrayPOD<Scaleform::MsgFormat::fmt_record,2,Scaleform::ArrayDefaultPolicy> > *v6; // r10
  Scaleform::MsgFormat::fmt_record *v7; // rcx
  __int64 v8; // r8
  __int64 v9; // rdx
  __int64 v10; // rbx
  char *v11; // rcx
  Scaleform::FmtResourceVtbl *v12; // rax
  __int64 v13; // [rsp+20h] [rbp-38h]
  __int64 v14; // [rsp+28h] [rbp-30h]
  __int64 v15; // [rsp+30h] [rbp-28h]

  v3 = this->DataInd;
  v4 = allocated;
  v5 = formatter;
  v6 = &this->Data;
  if ( v3 >= 0x10 )
    v7 = &this->Data.DynamicArray.Data.Data[v3 - 16];
  else
    v7 = (Scaleform::MsgFormat::fmt_record *)(&v6->Size + v3 + 2 * (v3 + 2));
  v8 = (__int64)v7->RecValue.String.Str;
  v9 = *(_QWORD *)&v7->RecValue.Formatter.Allocated;
  LOBYTE(v14) = v4;
  v10 = v14;
  LODWORD(v15) = 2;
  if ( v3 >= 0x10 )
    v11 = (char *)&v6->DynamicArray.Data.Data[v3 - 16];
  else
    v11 = (char *)(&v6->Size + v3 + 2 * (v3 + 2));
  *(_QWORD *)v11 = v15;
  *((_QWORD *)v11 + 1) = v5;
  *((_QWORD *)v11 + 2) = v10;
  if ( (_BYTE)v9 )
  {
    v14 = (unsigned __int8)v9;
    v12 = v5->vfptr;
    v13 = v8;
    v12[1].__vecDelDtor((Scaleform::FmtResource *)&v5->vfptr, (unsigned int)&v13);
  }
}

// File Line: 2065
// RVA: 0x95AD40
void __fastcall Scaleform::MsgFormat::BindNonPos(Scaleform::MsgFormat *this)
{
  Scaleform::MsgFormat *v1; // rbx
  Scaleform::LocaleProvider *v2; // rcx
  unsigned __int64 v3; // rdx
  signed __int64 v4; // rcx
  __int64 v5; // r9
  __int64 v6; // r8
  __int64 v7; // r10
  Scaleform::MsgFormat::fmt_record *v8; // rcx
  bool v9; // zf
  __int64 v10; // [rsp+18h] [rbp-39h]
  __int64 v11; // [rsp+20h] [rbp-31h]
  void **v12; // [rsp+38h] [rbp-19h]
  Scaleform::MsgFormat *v13; // [rsp+40h] [rbp-11h]
  char v14; // [rsp+48h] [rbp-9h]
  __int64 v15; // [rsp+50h] [rbp-1h]
  __int64 v16; // [rsp+58h] [rbp+7h]
  __int64 v17; // [rsp+60h] [rbp+Fh]
  __int128 v18; // [rsp+68h] [rbp+17h]
  __int64 v19; // [rsp+78h] [rbp+27h]
  __int64 v20; // [rsp+88h] [rbp+37h]
  __int64 v21; // [rsp+90h] [rbp+3Fh]

  v20 = -2i64;
  v1 = this;
  LOBYTE(v11) = 1;
  v13 = this;
  v14 = 0;
  v12 = &Scaleform::ResourceFormatter::`vftable;
  v15 = 0i64;
  v16 = v11;
  v17 = 0i64;
  _mm_store_si128((__m128i *)&v18, (__m128i)0i64);
  v19 = 0i64;
  *(_QWORD *)&v18 = 0i64;
  v2 = this->pLocaleProvider;
  if ( v2 )
    *(_QWORD *)&v18 = v2->vfptr[1].MakeFormatter((Scaleform::FormatterFactory *)&v2->vfptr, 0i64);
  if ( Scaleform::MsgFormat::NextFormatter(v1) )
  {
    v3 = v1->DataInd;
    v4 = (signed __int64)(v3 >= 0x10 ? &v1->Data.DynamicArray.Data.Data[v3 - 16] : (Scaleform::MsgFormat *)((char *)v1 + 24 * (v3 + 4)));
    v5 = *(_QWORD *)(v4 + 8);
    v6 = *(_QWORD *)(v4 + 16);
    LOBYTE(v11) = 0;
    LODWORD(v21) = 2;
    v7 = v11;
    v8 = v3 >= 0x10 ? &v1->Data.DynamicArray.Data.Data[v3 - 16] : (Scaleform::MsgFormat *)((char *)v1 + 24 * (v3 + 4));
    *(_QWORD *)&v8->RecType = v21;
    v8->RecValue.String.Str = (const char *)&v12;
    *(_QWORD *)&v8->RecValue.Formatter.Allocated = v7;
    if ( (_BYTE)v6 )
    {
      v10 = v5;
      v11 = (unsigned __int8)v6;
      ((void (__fastcall *)(void ***, __int64 *))v12[2])(&v12, &v10);
    }
  }
  v9 = v1->NonPosParamNum-- == 1;
  if ( v9 )
    Scaleform::MsgFormat::MakeString(v1);
  else
    Scaleform::MsgFormat::BindNonPos(v1);
}

// File Line: 2080
// RVA: 0x971480
void __fastcall Scaleform::MsgFormat::Evaluate(Scaleform::MsgFormat *this, unsigned __int64 ind)
{
  unsigned __int64 v2; // rbx
  Scaleform::MsgFormat::fmt_record *v3; // r8
  Scaleform::MsgFormat::fmt_record *v4; // rdi
  char *v5; // rdi
  char v6; // al
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // r8
  __int64 v9; // r9
  unsigned __int64 v10; // rax
  char v11; // cl
  signed __int64 v12; // rbx
  signed __int64 v13; // rcx
  signed __int64 v14; // rsi
  __int64 v15; // rsi
  __int64 v16; // rax
  __int64 v17; // rax
  Scaleform::StringDataPtr *v18; // rax
  __int64 v19; // rbx
  __int64 v20; // rax
  signed __int64 v21; // rax
  __int64 v22; // rcx
  __int64 v23; // rax
  __int64 v24; // rax
  char v25; // al
  unsigned __int64 v26; // rbx
  signed __int64 v27; // rsi
  signed __int64 v28; // rax
  int v29; // ecx
  signed __int64 v30; // rcx
  Scaleform::StringDataPtr *v31; // rax
  __int64 v32; // rbx
  __int64 v33; // rax
  signed __int64 v34; // rax
  signed __int64 v35; // rax
  __int64 v36; // rcx
  __int64 v37; // rax
  char v38; // al
  unsigned __int64 v39; // rbx
  signed __int64 v40; // rsi
  signed __int64 v41; // rax
  int v42; // ecx
  signed __int64 v43; // rcx
  Scaleform::StringDataPtr *v44; // rax
  __int64 v45; // rbx
  __int64 v46; // rax
  signed __int64 v47; // rax
  signed __int64 v48; // rax
  __int64 v49; // rcx
  __int64 v50; // rax
  __int64 v51; // rax
  unsigned __int64 v52; // rsi
  int v53; // eax
  int v54; // eax
  unsigned __int8 v55; // al
  signed __int64 v56; // rcx
  signed __int64 v57; // rax
  Scaleform::MsgFormat *v58; // rcx
  const char *v59; // rbx
  signed __int64 v60; // rcx
  signed __int64 v61; // rax
  signed __int64 v62; // rbx
  Scaleform::MsgFormat::fmt_record *v63; // rax
  signed __int64 v64; // rcx
  signed __int64 v65; // rax
  signed __int64 inda; // [rsp+20h] [rbp-39h]
  unsigned __int64 indb; // [rsp+20h] [rbp-39h]
  unsigned __int64 indc; // [rsp+20h] [rbp-39h]
  signed __int64 v69; // [rsp+28h] [rbp-31h]
  __int64 v70; // [rsp+28h] [rbp-31h]
  __int64 v71; // [rsp+28h] [rbp-31h]
  __int64 v72; // [rsp+30h] [rbp-29h]
  __int64 v73; // [rsp+38h] [rbp-21h]
  __int64 v74; // [rsp+40h] [rbp-19h]
  __int64 v75; // [rsp+48h] [rbp-11h]
  const char *v76; // [rsp+50h] [rbp-9h]
  __int64 v77; // [rsp+58h] [rbp-1h]
  const char *v78; // [rsp+60h] [rbp+7h]
  __int64 v79; // [rsp+68h] [rbp+Fh]
  char v80; // [rsp+70h] [rbp+17h]
  char v81; // [rsp+80h] [rbp+27h]
  Scaleform::MsgFormat *v82; // [rsp+C0h] [rbp+67h]
  unsigned __int64 v83; // [rsp+C8h] [rbp+6Fh]
  char v84; // [rsp+D0h] [rbp+77h]
  char v85; // [rsp+D0h] [rbp+77h]
  char v86; // [rsp+D0h] [rbp+77h]
  char v87; // [rsp+D8h] [rbp+7Fh]

  v83 = ind;
  v82 = this;
  v2 = ind;
  if ( ind >= 0x10 )
    v3 = &this->Data.DynamicArray.Data.Data[ind - 16];
  else
    v3 = (Scaleform::MsgFormat::fmt_record *)((char *)this + 24 * (ind + 4));
  if ( v3->RecType != 2 )
    return;
  if ( ind >= 0x10 )
    v4 = &this->Data.DynamicArray.Data.Data[ind - 16];
  else
    v4 = (Scaleform::MsgFormat::fmt_record *)((char *)this + 24 * (ind + 4));
  v5 = (char *)v4->RecValue.String.Str;
  v6 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 48i64))(v5);
  v87 = v6;
  if ( !v6 )
    goto LABEL_120;
  v7 = 0i64;
  v8 = 0xFFFFFFFFi64;
  if ( v6 & 2 )
  {
    v10 = v2 - 1;
    v11 = 0;
    inda = v2 - 1;
    v84 = 0;
    if ( v2 != 0x100000000i64 )
    {
      v12 = 24 * (v2 - 17);
      v69 = 24 * (v10 - 16);
      while ( 1 )
      {
        if ( v11 )
          goto LABEL_38;
        if ( v10 >= 0x10 )
        {
          v13 = (signed __int64)v82->Data.DynamicArray.Data.Data;
          v10 = inda;
        }
        else
        {
          v13 = (signed __int64)&v82->MemPool;
        }
        v7 = *(unsigned int *)(v12 + v13);
        if ( (_DWORD)v7 )
        {
          if ( (_DWORD)v7 != 2 )
            goto LABEL_34;
          if ( v10 >= 0x10 )
            v14 = (signed __int64)v82->Data.DynamicArray.Data.Data + v12;
          else
            v14 = (signed __int64)&v82->MemPool + v12;
          v15 = *(_QWORD *)(v14 + 8);
          if ( (*(__int64 (__fastcall **)(__int64, unsigned __int64, Scaleform::MsgFormat *))(*(_QWORD *)v15 + 48i64))(
                 v15,
                 v7,
                 v82) & 4 )
          {
            v76 = "stub";
            v16 = *(_QWORD *)v5;
            v77 = 4i64;
            (*(void (__fastcall **)(char *, const char **))(v16 + 56))(v5, &v76);
            v10 = inda;
            v11 = 1;
            v84 = 1;
          }
          else if ( (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 48i64))(v15) & 8
                 && (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v15 + 88i64))(v15) == 2 )
          {
            v78 = "stub";
            v17 = *(_QWORD *)v5;
            v79 = 4i64;
            (*(void (__fastcall **)(char *, const char **))(v17 + 56))(v5, &v78);
            v10 = inda;
            v11 = 1;
            v84 = 1;
          }
          else
          {
            Scaleform::MsgFormat::Evaluate(v82, inda);
            v18 = (Scaleform::StringDataPtr *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v15 + 32i64))(
                                                v15,
                                                &v80);
            if ( Scaleform::IsSpace(v18) )
              goto LABEL_33;
            v19 = *(_QWORD *)v5;
            v20 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v15 + 32i64))(v15, &v81);
            (*(void (__fastcall **)(char *, __int64))(v19 + 56))(v5, v20);
            v12 = v69;
            v10 = inda;
            v11 = 1;
            v84 = 1;
          }
        }
        else
        {
          if ( v10 >= 0x10 )
            v21 = (signed __int64)v82->Data.DynamicArray.Data.Data + v12;
          else
            v21 = (signed __int64)&v82->MemPool + v12;
          v22 = *(unsigned __int8 *)(v21 + 16);
          v23 = *(_QWORD *)(v21 + 8);
          v73 = v22;
          v75 = v22;
          v72 = v23;
          v74 = v23;
          if ( Scaleform::IsSpace((Scaleform::StringDataPtr *)&v74) )
          {
LABEL_33:
            v10 = inda;
LABEL_34:
            v11 = v84;
            goto LABEL_35;
          }
          (*(void (__fastcall **)(char *, __int64 *))(*(_QWORD *)v5 + 56i64))(v5, &v72);
          v10 = inda;
          v11 = 1;
          v84 = 1;
        }
LABEL_35:
        --v10;
        v12 -= 24i64;
        v8 = 0xFFFFFFFFi64;
        inda = v10;
        v69 = v12;
        if ( v10 == 0xFFFFFFFF )
        {
          if ( v11 )
            goto LABEL_38;
          break;
        }
      }
    }
    v24 = *(_QWORD *)v5;
    v72 = 0i64;
    v73 = 0i64;
    (*(void (__fastcall **)(char *, __int64 *, signed __int64))(v24 + 56))(v5, &v72, 0xFFFFFFFFi64);
    v8 = 0xFFFFFFFFi64;
  }
LABEL_38:
  if ( v87 & 1 )
  {
    v25 = 0;
    v26 = v83 - 1;
    v85 = 0;
    indb = v83 - 1;
    if ( v83 != 0x100000000i64 )
    {
      v27 = 24 * (v83 - 17);
      while ( 1 )
      {
        if ( v25 )
          goto LABEL_58;
        v7 = (unsigned __int64)v82;
        v28 = (signed __int64)&v82->MemPool;
        if ( v26 >= 0x10 )
          v28 = (signed __int64)v82->Data.DynamicArray.Data.Data;
        v29 = *(_DWORD *)(v27 + v28);
        if ( v29 )
        {
          if ( v29 != 2 )
            goto LABEL_54;
          v30 = (signed __int64)&v82->MemPool;
          if ( v26 >= 0x10 )
            v30 = (signed __int64)v82->Data.DynamicArray.Data.Data;
          v70 = *(_QWORD *)(v27 + v30 + 8);
          (*(void (__fastcall **)(signed __int64, Scaleform::MsgFormat *, unsigned __int64))(*(_QWORD *)v70 + 48i64))(
            v30,
            v82,
            v8);
          Scaleform::MsgFormat::Evaluate(v82, v26);
          v31 = (Scaleform::StringDataPtr *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v70 + 32i64))(
                                              v70,
                                              &v81);
          if ( Scaleform::IsSpace(v31) )
            goto LABEL_54;
          v32 = *(_QWORD *)v5;
          v33 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v70 + 32i64))(v70, &v80);
          (*(void (__fastcall **)(char *, __int64))(v32 + 56))(v5, v33);
          v26 = indb;
          v25 = 1;
          v85 = 1;
        }
        else
        {
          v34 = (signed __int64)&v82->MemPool;
          if ( v26 >= 0x10 )
            v34 = (signed __int64)v82->Data.DynamicArray.Data.Data;
          v35 = v27 + v34;
          v36 = *(unsigned __int8 *)(v35 + 16);
          v37 = *(_QWORD *)(v35 + 8);
          v75 = v36;
          v73 = v36;
          v74 = v37;
          v72 = v37;
          if ( Scaleform::IsSpace((Scaleform::StringDataPtr *)&v72) )
          {
LABEL_54:
            v25 = v85;
            goto LABEL_55;
          }
          (*(void (__fastcall **)(char *, __int64 *))(*(_QWORD *)v5 + 56i64))(v5, &v74);
          v25 = 1;
          v85 = 1;
        }
LABEL_55:
        --v26;
        v27 -= 24i64;
        indb = v26;
        if ( v26 == 0xFFFFFFFF )
        {
          if ( v25 )
            goto LABEL_58;
          break;
        }
      }
    }
    v72 = 0i64;
    v73 = 0i64;
    (*(void (__fastcall **)(char *, __int64 *, unsigned __int64))(*(_QWORD *)v5 + 56i64))(v5, &v72, v8);
  }
LABEL_58:
  if ( v87 & 4 )
  {
    v7 = (unsigned __int64)v82;
    v38 = 0;
    v39 = v83 + 1;
    v86 = 0;
    indc = v83 + 1;
    v76 = (const char *)v82->Data.Size;
    if ( v83 + 1 < (unsigned __int64)v76 )
    {
      v40 = 24 * (v83 - 15);
      while ( 1 )
      {
        if ( v38 )
          goto LABEL_80;
        v41 = v7 + 480;
        if ( v39 >= 0x10 )
          v41 = *(_QWORD *)(v7 + 72);
        v42 = *(_DWORD *)(v40 + v41);
        if ( !v42 )
          break;
        if ( v42 == 2 )
        {
          v43 = v7 + 480;
          if ( v39 >= 0x10 )
            v43 = *(_QWORD *)(v7 + 72);
          v71 = *(_QWORD *)(v40 + v43 + 8);
          (*(void (__fastcall **)(signed __int64, unsigned __int64, unsigned __int64))(*(_QWORD *)v71 + 48i64))(
            v43,
            v7,
            v8);
          Scaleform::MsgFormat::Evaluate(v82, v39);
          v44 = (Scaleform::StringDataPtr *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v71 + 32i64))(
                                              v71,
                                              &v81);
          if ( !Scaleform::IsSpace(v44) )
          {
            v45 = *(_QWORD *)v5;
            v46 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v71 + 32i64))(v71, &v80);
            (*(void (__fastcall **)(char *, __int64))(v45 + 72))(v5, v46);
            v39 = indc;
            v38 = 1;
            v86 = 1;
LABEL_76:
            v7 = (unsigned __int64)v82;
            goto LABEL_77;
          }
          goto LABEL_75;
        }
        v38 = v86;
LABEL_77:
        ++v39;
        v40 += 24i64;
        indc = v39;
        if ( v39 >= (unsigned __int64)v76 )
        {
          if ( v38 )
            goto LABEL_80;
          goto LABEL_79;
        }
      }
      v47 = v7 + 480;
      if ( v39 >= 0x10 )
        v47 = *(_QWORD *)(v7 + 72);
      v48 = v40 + v47;
      v49 = *(unsigned __int8 *)(v48 + 16);
      v50 = *(_QWORD *)(v48 + 8);
      v75 = v49;
      v73 = v49;
      v74 = v50;
      v72 = v50;
      if ( !Scaleform::IsSpace((Scaleform::StringDataPtr *)&v72) )
      {
        (*(void (__fastcall **)(char *, __int64 *))(*(_QWORD *)v5 + 72i64))(v5, &v74);
        v38 = 1;
        v86 = 1;
        goto LABEL_76;
      }
LABEL_75:
      v38 = v86;
      goto LABEL_76;
    }
LABEL_79:
    v51 = *(_QWORD *)v5;
    v52 = 0i64;
    v72 = 0i64;
    v73 = 0i64;
    (*(void (__fastcall **)(char *, __int64 *, unsigned __int64))(v51 + 72))(v5, &v72, v8);
  }
  else
  {
LABEL_80:
    v52 = 0i64;
  }
  if ( !(v87 & 8) )
    goto LABEL_120;
  v53 = (unsigned __int64)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 88i64))(v5) - 1;
  if ( !v53 )
  {
    v8 = 0xFFFFFFFFi64;
    v52 = v83 - 1;
    if ( v83 == 0x100000000i64 )
      goto LABEL_120;
    v64 = 24 * (v83 - 17);
    while ( 1 )
    {
      v7 = (unsigned __int64)v82;
      v65 = (signed __int64)&v82->MemPool;
      if ( v52 >= 0x10 )
        v65 = (signed __int64)v82->Data.DynamicArray.Data.Data;
      if ( *(_DWORD *)(v64 + v65) == 2 )
        break;
      --v52;
      v64 -= 24i64;
      if ( v52 == 0xFFFFFFFF )
        goto LABEL_120;
    }
    if ( v52 < 0x10 )
    {
      v62 = (signed __int64)v82 + 24 * (v52 + 4);
      goto LABEL_118;
    }
    v63 = v82->Data.DynamicArray.Data.Data;
LABEL_117:
    v62 = (signed __int64)&v63[v52 - 16];
    goto LABEL_118;
  }
  v54 = v53 - 1;
  if ( !v54 )
  {
    v8 = (unsigned __int64)v82;
    v7 = v82->Data.Size;
    v52 = v83 + 1;
    if ( v83 + 1 >= v7 )
      goto LABEL_120;
    v60 = 24 * (v83 - 15);
    while ( 1 )
    {
      v61 = (signed __int64)&v82->MemPool;
      if ( v52 >= 0x10 )
        v61 = (signed __int64)v82->Data.DynamicArray.Data.Data;
      if ( *(_DWORD *)(v60 + v61) == 2 )
        break;
      ++v52;
      v60 += 24i64;
      if ( v52 >= v7 )
        goto LABEL_120;
    }
    if ( v52 < 0x10 )
    {
      v62 = (signed __int64)v82 + 24 * (v52 + 4);
LABEL_118:
      v59 = *(const char **)(v62 + 8);
      (*(void (__fastcall **)(const char *))(*(_QWORD *)v59 + 48i64))(v59);
      v58 = v82;
      goto LABEL_119;
    }
    v63 = v82->Data.DynamicArray.Data.Data;
    goto LABEL_117;
  }
  if ( v54 != 1 )
    goto LABEL_120;
  v55 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 96i64))(v5);
  LOBYTE(v7) = 0;
  v8 = v82->Data.Size;
  v9 = v55;
  if ( !v8 )
    goto LABEL_120;
  v56 = -384i64;
  while ( 1 )
  {
    v57 = (signed __int64)&v82->MemPool;
    if ( v52 >= 0x10 )
      v57 = (signed __int64)v82->Data.DynamicArray.Data.Data;
    if ( *(_DWORD *)(v56 + v57) != 2 )
      goto LABEL_92;
    if ( (_BYTE)v7 == (_BYTE)v9 )
      break;
    LOBYTE(v7) = v7 + 1;
LABEL_92:
    ++v52;
    v56 += 24i64;
    if ( v52 >= v8 )
      goto LABEL_120;
  }
  if ( v52 >= 0x10 )
  {
    v58 = v82;
    v59 = v82->Data.DynamicArray.Data.Data[v52 - 16].RecValue.String.Str;
  }
  else
  {
    v58 = v82;
    v59 = (const char *)*((_QWORD *)&v82->EscapeChar + 3 * (v52 + 4));
  }
LABEL_119:
  Scaleform::MsgFormat::Evaluate(v58, v52);
  (*(void (__fastcall **)(char *, const char *))(*(_QWORD *)v5 + 104i64))(v5, v59);
LABEL_120:
  if ( !v5[16] )
    (*(void (__fastcall **)(char *, unsigned __int64, unsigned __int64, __int64))(*(_QWORD *)v5 + 24i64))(
      v5,
      v7,
      v8,
      v9);
}

// File Line: 2412
// RVA: 0x998FD0
void __fastcall Scaleform::MsgFormat::MakeString(Scaleform::MsgFormat *this)
{
  unsigned __int64 v1; // r12
  unsigned __int64 v2; // r15
  Scaleform::MsgFormat *v3; // rsi
  unsigned __int64 v4; // rbx
  signed __int64 v5; // r14
  signed __int64 v6; // rdi
  signed __int64 v7; // rbp
  signed __int64 v8; // rbp
  signed __int64 v9; // rax
  int v10; // ecx
  __int64 v11; // rcx
  __int64 v12; // rax
  Scaleform::MsgFormat::Sink::DataType v13; // ecx
  int v14; // ecx
  Scaleform::String *v15; // rbx
  unsigned __int64 v16; // rcx
  Scaleform::String *v17; // r12
  unsigned __int64 v18; // r13
  unsigned __int64 v19; // rcx
  void *v20; // r9
  signed __int64 v21; // rdx
  void *v22; // rax
  signed __int64 v23; // rbp
  signed __int64 v24; // rbp
  signed __int64 v25; // rax
  int v26; // ecx
  __int64 v27; // rcx
  size_t v28; // rbx
  _BYTE *v29; // rbp
  Scaleform::String::DataDesc *v30; // rdi
  char *putf8str; // [rsp+20h] [rbp-38h]
  __int64 utf8StrSz; // [rsp+28h] [rbp-30h]

  v1 = this->Data.Size;
  v2 = 0i64;
  v3 = this;
  this->StrSize = 0i64;
  v4 = 0i64;
  v5 = -384i64;
  if ( v1 )
  {
    v6 = -384i64;
    do
    {
      v7 = (signed __int64)&v3->MemPool;
      if ( v4 >= 0x10 )
        v7 = (signed __int64)v3->Data.DynamicArray.Data.Data;
      v8 = v6 + v7;
      v9 = (signed __int64)&v3->MemPool;
      if ( v4 >= 0x10 )
        v9 = (signed __int64)v3->Data.DynamicArray.Data.Data;
      v10 = *(_DWORD *)(v6 + v9);
      if ( v10 )
      {
        if ( v10 != 2 )
          goto LABEL_13;
        Scaleform::MsgFormat::Evaluate(v3, v4);
        v11 = *(_QWORD *)(v8 + 8);
        if ( !v11 )
          goto LABEL_13;
        v12 = (*(__int64 (**)(void))(*(_QWORD *)v11 + 40i64))();
      }
      else
      {
        v12 = *(unsigned __int8 *)(v8 + 16);
      }
      v3->StrSize += v12;
LABEL_13:
      ++v4;
      v6 += 24i64;
    }
    while ( v4 < v1 );
  }
  v13 = v3->Result.Type;
  if ( v13 )
  {
    v14 = v13 - 1;
    if ( v14 )
    {
      if ( v14 == 1 )
      {
        v15 = v3->Result.SinkData.pStr;
        v3->vfptr->InitString(
          (Scaleform::String::InitStruct *)&v3->vfptr,
          (char *)v3->Result.SinkData.pStr,
          v3->Result.SinkData.DataPtr.Size);
        v16 = v3->StrSize;
        if ( v3->Result.SinkData.DataPtr.Size - 1 < v16 )
          v16 = v3->Result.SinkData.DataPtr.Size - 1;
        *((_BYTE *)&v15->pData + v16) = 0;
      }
    }
    else
    {
      v17 = v3->Result.SinkData.pStr;
      v18 = v3->Data.Size;
      v19 = v3->StrSize + v17[1].HeapTypeBits;
      if ( v19 >= v17[2].HeapTypeBits )
      {
        v20 = (void *)v17->HeapTypeBits;
        v21 = ~(v17[3].HeapTypeBits - 1) & (v17[3].HeapTypeBits + v19);
        v17[2].HeapTypeBits = v21;
        if ( v20 )
          v22 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v20, v21);
        else
          v22 = (void *)(*(__int64 (__fastcall **)(unsigned __int64, signed __int64, _QWORD))(v17[5].pData->Size + 80))(
                          v17[5].HeapTypeBits,
                          v21,
                          0i64);
        v17->HeapTypeBits = (unsigned __int64)v22;
      }
      if ( v18 )
      {
        do
        {
          v23 = (signed __int64)&v3->MemPool;
          if ( v2 >= 0x10 )
            v23 = (signed __int64)v3->Data.DynamicArray.Data.Data;
          v24 = v5 + v23;
          v25 = (signed __int64)&v3->MemPool;
          if ( v2 >= 0x10 )
            v25 = (signed __int64)v3->Data.DynamicArray.Data.Data;
          v26 = *(_DWORD *)(v5 + v25);
          if ( v26 )
          {
            if ( v26 == 2 )
            {
              v27 = *(_QWORD *)(v24 + 8);
              if ( v27 )
              {
                (*(void (__fastcall **)(__int64, char **))(*(_QWORD *)v27 + 32i64))(v27, &putf8str);
                Scaleform::StringBuffer::AppendString((Scaleform::StringBuffer *)v17, putf8str, utf8StrSz);
              }
            }
          }
          else
          {
            v28 = *(unsigned __int8 *)(v24 + 16);
            v29 = *(_BYTE **)(v24 + 8);
            if ( v29 && v28 )
            {
              if ( v28 == -1i64 )
              {
                do
                  ++v28;
                while ( v29[v28] );
              }
              v30 = v17[1].pData;
              Scaleform::StringBuffer::Resize((Scaleform::StringBuffer *)v17, (unsigned __int64)v30 + v28);
              memmove((char *)v30 + v17->HeapTypeBits, v29, v28);
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
    Scaleform::String::AssignString(v3->Result.SinkData.pStr, (Scaleform::String::InitStruct *)&v3->vfptr, v3->StrSize);
  }
}

// File Line: 2502
// RVA: 0x993F50
void __fastcall Scaleform::MsgFormat::InitString(Scaleform::MsgFormat *this, char *pbuffer, unsigned __int64 size)
{
  unsigned __int64 v3; // r12
  unsigned __int64 v4; // rbp
  signed __int64 v5; // rbx
  char *v6; // r14
  Scaleform::MsgFormat *v7; // r15
  unsigned __int64 v8; // rsi
  signed __int64 v9; // rdx
  signed __int64 v10; // rdx
  signed __int64 v11; // rax
  int v12; // ecx
  __int64 v13; // rcx
  size_t v14; // rdi
  const void *v15; // rdx
  const void *v16; // [rsp+20h] [rbp-28h]
  size_t v17; // [rsp+28h] [rbp-20h]

  if ( size )
  {
    v3 = this->Data.Size;
    v4 = size;
    v5 = -384i64;
    v6 = pbuffer;
    v7 = this;
    v8 = 0i64;
    while ( 1 )
    {
      if ( v8 >= v3 )
        return;
      v9 = (signed __int64)&v7->MemPool;
      if ( v8 >= 0x10 )
        v9 = (signed __int64)v7->Data.DynamicArray.Data.Data;
      v10 = v5 + v9;
      v11 = (signed __int64)&v7->MemPool;
      if ( v8 >= 0x10 )
        v11 = (signed __int64)v7->Data.DynamicArray.Data.Data;
      v12 = *(_DWORD *)(v5 + v11);
      if ( !v12 )
        break;
      if ( v12 == 2 )
      {
        v13 = *(_QWORD *)(v10 + 8);
        if ( v13 )
        {
          (*(void (__fastcall **)(__int64, const void **))(*(_QWORD *)v13 + 32i64))(v13, &v16);
          v14 = v17;
          v15 = v16;
LABEL_13:
          if ( v4 < v14 )
            v14 = v4;
          memmove(v6, v15, v14);
          v4 -= v14;
          v6 += v14;
          goto LABEL_16;
        }
      }
LABEL_16:
      ++v8;
      v5 += 24i64;
      if ( !v4 )
        return;
    }
    v14 = *(unsigned __int8 *)(v10 + 16);
    v15 = *(const void **)(v10 + 8);
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
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  v1 = (char *)&s->pStr[s->Size];
  putf8Buffer = (char *)s->pStr;
  if ( putf8Buffer == v1 )
    return 1;
  while ( 1 )
  {
    v2 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
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
  unsigned __int64 v3; // r9
  const char *v4; // rsi
  unsigned __int64 v5; // rdi
  int v6; // ebx
  Scaleform::StringDataPtr *v7; // r14
  char v8; // al
  unsigned __int64 i; // rbx
  unsigned __int64 v10; // rax

  v3 = str->Size;
  v4 = str->pStr;
  v5 = 0i64;
  v6 = defaultValue;
  v7 = str;
  if ( v3 )
  {
    do
    {
      v8 = v4[v5];
      if ( !v8 )
        break;
      if ( v8 == separator )
        break;
      ++v5;
    }
    while ( v5 < v3 );
  }
  if ( !v5 || !v4 || !isdigit(*v4) )
    return v6;
  for ( i = 1i64; i < v5; ++i )
  {
    if ( !isdigit(v4[i]) )
      break;
  }
  v10 = v7->Size;
  if ( v10 < i )
    i = v7->Size;
  v7->pStr += i;
  v7->Size = v10 - i;
  return atol(v4);
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

