// File Line: 130
// RVA: 0xC80D60
hkClassMember::TypeProperties *__fastcall hkClassMember::getClassMemberTypeProperties(hkClassMember::Type type)
{
  return &ClassMemberProperties[type];
}

// File Line: 135
// RVA: 0xC80310
__int64 __fastcall hkClassMember::getSizeInBytes(hkClassMember *this)
{
  unsigned int v2; // ecx
  __int64 m_storage; // rsi
  int CstyleArraySize; // eax
  int m_size; // ecx
  int v6; // edi
  hkClass *StructClass; // rax

  v2 = -1;
  m_storage = (unsigned __int8)this->m_type.m_storage;
  switch ( this->m_type.m_storage )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x20:
    case 0x21:
    case 0x22:
      if ( hkClassMember::getCstyleArraySize(this) )
      {
        CstyleArraySize = hkClassMember::getCstyleArraySize(this);
        m_size = ClassMemberProperties[m_storage].m_size;
        v6 = CstyleArraySize;
      }
      else
      {
        v6 = 1;
        m_size = ClassMemberProperties[m_storage].m_size;
      }
      goto LABEL_13;
    case 0x18:
    case 0x1F:
      if ( hkClassMember::getCstyleArraySize(this) )
        v6 = hkClassMember::getCstyleArraySize(this);
      else
        v6 = 1;
      m_size = ClassMemberProperties[(unsigned __int8)this->m_subtype.m_storage].m_size;
      goto LABEL_13;
    case 0x19:
      if ( hkClassMember::getCstyleArraySize(this) )
        v6 = hkClassMember::getCstyleArraySize(this);
      else
        v6 = 1;
      StructClass = hkClassMember::getStructClass(this);
      m_size = hkClass::getObjectSize(StructClass);
LABEL_13:
      v2 = v6 * m_size;
      break;
    default:
      return v2;
  }
  return v2;
}

// File Line: 200
// RVA: 0xC80540
hkBool *__fastcall hkClassMember::isNotOwner(hkClassMember *this, hkBool *result)
{
  result->m_bool = (this->m_flags.m_storage & 0x200) != 0;
  return result;
}

// File Line: 205
// RVA: 0xC80440
__int64 __fastcall hkClassMember::getAlignment(hkClassMember *this)
{
  int m_storage; // eax
  int Alignment; // esi
  int i; // ebx
  hkClassMember *Member; // rax
  hkClassMember *v6; // rax
  unsigned __int16 v7; // ax
  bool v9; // zf
  int v10; // eax

  m_storage = (unsigned __int8)this->m_type.m_storage;
  if ( m_storage == 24 || m_storage == 31 )
    m_storage = (unsigned __int8)this->m_subtype.m_storage;
  if ( m_storage == 25 )
  {
    Alignment = 1;
    for ( i = 0; i < (int)hkClass::getNumMembers(this->m_class); ++i )
    {
      Member = hkClass::getMember(this->m_class, i);
      if ( hkClassMember::getAlignment(Member) > Alignment )
      {
        v6 = hkClass::getMember(this->m_class, i);
        Alignment = hkClassMember::getAlignment(v6);
      }
    }
  }
  else
  {
    Alignment = ClassMemberProperties[m_storage].m_align;
  }
  v7 = this->m_flags.m_storage;
  if ( (v7 & 0x980) == 0 )
    return (unsigned int)Alignment;
  if ( (v7 & 0x800) == 0 )
  {
    v9 = (v7 & 0x100) == 0;
    v10 = 8;
    if ( !v9 )
      v10 = 16;
    if ( v10 > Alignment )
      return (unsigned int)v10;
    return (unsigned int)Alignment;
  }
  if ( Alignment < 32 )
    return 32;
  return (unsigned int)Alignment;
}

// File Line: 242
// RVA: 0xC80D80
bool __fastcall isSimpleType(unsigned int type)
{
  unsigned __int64 v1; // rax
  __int64 v2; // rcx
  bool result; // al

  result = 0;
  if ( type <= 0x21 )
  {
    v1 = (int)type;
    v2 = 0x3700FFFFFi64;
    if ( _bittest64(&v2, v1) )
      return 1;
  }
  return result;
}

// File Line: 251
// RVA: 0xC80DB0
void __fastcall getSimpleTypeName(hkClassMember::Type type, unsigned int nelem, hkStringBuf *ret)
{
  if ( nelem )
    hkStringBuf::printf(ret, "%s[%i]", ClassMemberProperties[type].m_name, nelem);
  else
    hkStringBuf::operator=(ret, ClassMemberProperties[type].m_name);
}

// File Line: 264
// RVA: 0xC80560
__int64 __fastcall hkClassMember::getTypeName(hkClassMember *this, char *buf, unsigned int bufLen)
{
  unsigned __int64 m_storage; // rbx
  hkClass *m_class; // rcx
  const char *m_name; // rsi
  const char *Name; // rbp
  hkClassEnum *m_enum; // rax
  __int64 v11; // rcx
  hkClass *v12; // rcx
  const char *v13; // rax
  unsigned __int64 ArrayType; // rcx
  const char *v15; // r8
  __int64 v16; // rdx
  __int16 m_cArraySize; // ax
  int m_size; // ebx
  hkStringBuf ret; // [rsp+20h] [rbp-A8h] BYREF

  m_storage = (unsigned __int8)this->m_type.m_storage;
  m_class = this->m_class;
  m_name = "unknown";
  if ( m_class )
    Name = hkClass::getName(m_class);
  else
    Name = "unknown";
  m_enum = this->m_enum;
  if ( m_enum )
    m_name = m_enum->m_name;
  ret.m_string.m_capacityAndFlags = -2147483520;
  ret.m_string.m_size = 1;
  ret.m_string.m_storage[0] = 0;
  ret.m_string.m_data = ret.m_string.m_storage;
  if ( (unsigned int)m_storage <= 0x21 && (v11 = 0x3780FFFFFi64, _bittest64(&v11, m_storage)) )
  {
    getSimpleTypeName((hkClassMember::Type)m_storage, this->m_cArraySize, &ret);
  }
  else if ( (_DWORD)m_storage == 20 )
  {
    v12 = this->m_class;
    if ( v12 )
    {
      v13 = hkClass::getName(v12);
      hkStringBuf::printf(&ret, "struct %s*", v13);
    }
    else if ( this->m_subtype.m_storage == 2 )
    {
      hkStringBuf::operator=(&ret, "char*");
    }
    else
    {
      hkStringBuf::operator=(&ret, "void*");
    }
  }
  else if ( (((_DWORD)m_storage - 22) & 0xFFFFFFF3) != 0 || (_DWORD)m_storage == 30 )
  {
    switch ( (_DWORD)m_storage )
    {
      case 0x18:
        hkStringBuf::printf(&ret, "enum %s", m_name);
        break;
      case 0x1F:
        hkStringBuf::printf(&ret, "flags %s", m_name);
        break;
      case 0x19:
        m_cArraySize = this->m_cArraySize;
        if ( m_cArraySize )
          hkStringBuf::printf(&ret, "struct %s[%i]", Name, (unsigned int)m_cArraySize);
        else
          hkStringBuf::printf(&ret, "struct %s", Name);
        break;
    }
  }
  else
  {
    ArrayType = (int)hkClassMember::getArrayType(this);
    if ( (_DWORD)m_storage == 22 )
    {
      v15 = "hkArray";
    }
    else
    {
      v15 = "hkRelArray";
      if ( (_DWORD)m_storage == 26 )
        v15 = "hkSimpleArray";
    }
    if ( (unsigned int)ArrayType <= 0x21 && (v16 = 0x3700FFFFFi64, _bittest64(&v16, ArrayType)) )
    {
      hkStringBuf::printf(&ret, "%s&lt;%s&gt;", v15, ClassMemberProperties[ArrayType].m_name);
    }
    else if ( (_DWORD)ArrayType == 20 )
    {
      if ( this->m_class )
        hkStringBuf::printf(&ret, "%s&lt;%s*&gt;", v15, Name);
      else
        hkStringBuf::printf(&ret, "%s&lt;void*&gt;", v15);
    }
    else if ( (_DWORD)ArrayType == 25 )
    {
      hkStringBuf::printf(&ret, "%s&lt;struct %s&gt;", v15, Name);
    }
  }
  hkString::strNcpy(buf, ret.m_string.m_data, bufLen);
  m_size = ret.m_string.m_size;
  ret.m_string.m_size = 0;
  if ( ret.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      ret.m_string.m_data,
      ret.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return (unsigned int)(m_size - 1);
}

// File Line: 346
// RVA: 0xC80300
__int64 __fastcall hkClassMember::getArrayType(hkClassMember *this)
{
  return (unsigned __int8)this->m_subtype.m_storage;
}

// File Line: 356
// RVA: 0xC80820
__int64 __fastcall hkClassMember::getArrayMemberSize(hkClassMember *this)
{
  hkClass *StructClass; // rax

  if ( (unsigned int)hkClassMember::getArrayType(this) == 24 || (unsigned int)hkClassMember::getArrayType(this) == 31 )
    return 0xFFFFFFFFi64;
  if ( (unsigned int)hkClassMember::getArrayType(this) != 25 )
    return (unsigned int)ClassMemberProperties[(int)hkClassMember::getArrayType(this)].m_size;
  StructClass = hkClassMember::getStructClass(this);
  return hkClass::getObjectSize(StructClass);
}

// File Line: 381
// RVA: 0xC80890
hkClass *__fastcall hkClassMember::getStructClass(hkClassMember *this)
{
  return this->m_class;
}

// File Line: 386
// RVA: 0xC808A0
hkClass *__fastcall hkClassMember::getClass(hkClassMember *this)
{
  return this->m_class;
}

// File Line: 391
// RVA: 0xC808B0
hkClassEnum *__fastcall hkClassMember::getEnumClass(hkClassMember *this)
{
  return this->m_enum;
}

// File Line: 396
// RVA: 0xC808C0
__int64 __fastcall hkClassMember::getCstyleArraySize(hkClassMember *this)
{
  return (unsigned int)this->m_cArraySize;
}

// File Line: 401
// RVA: 0xC808D0
hkClassEnum *__fastcall hkClassMember::getEnumType(hkClassMember *this)
{
  return this->m_enum;
}

// File Line: 407
// RVA: 0xC808E0
__int64 __fastcall hkClassMember::getEnumValue(hkClassMember *this, const void *memberAddress)
{
  return hkVariantDataUtil::getInt(
           (hkClassMember::Type)(unsigned __int8)this->m_type.m_storage,
           (hkClassMember::Type)(unsigned __int8)this->m_subtype.m_storage,
           memberAddress);
}

// File Line: 412
// RVA: 0xC80900
void __fastcall hkClassMember::setEnumValue(hkClassMember *this, void *memberAddress, int value)
{
  hkVariantDataUtil::setInt(
    (hkClassMember::Type)(unsigned __int8)this->m_type.m_storage,
    (hkClassMember::Type)(unsigned __int8)this->m_subtype.m_storage,
    memberAddress,
    value);
}

// File Line: 417
// RVA: 0xC80920
hkVariant *__fastcall hkClassMember::getAttribute(hkClassMember *this, const char *id)
{
  hkCustomAttributes *m_attributes; // rcx

  m_attributes = this->m_attributes;
  if ( m_attributes )
    return hkCustomAttributes::getAttribute(m_attributes, id);
  else
    return 0i64;
}

// File Line: 422
// RVA: 0xC80940
__int64 __fastcall hkClassMember::getTypeOf(const char *name)
{
  char *v3; // rax
  char *v4; // rax
  unsigned int v5; // edi
  const char **p_m_name; // rbx
  hkStringBuf v7; // [rsp+20h] [rbp-98h] BYREF

  if ( !hkString::strNcmp(name, "enum ", 5u) )
    return 24i64;
  if ( !hkString::strNcmp(name, "flags ", 6u) )
    return 31i64;
  if ( !hkString::strNcmp(name, "hkArray<", 8u) )
    return 22i64;
  if ( !hkString::strNcmp(name, "hkRelArray<", 0xBu) )
    return 34i64;
  if ( !hkString::strNcmp(name, "hkSimpleArray<", 0xEu) )
    return 26i64;
  if ( !hkString::strNcmp(name, "char*", 5u) )
    return 29i64;
  if ( !hkString::strNcmp(name, "hkStringPtr", 0xBu) )
    return 33i64;
  v3 = hkString::strRchr(name, 42);
  if ( v3 && !v3[1] )
    return 20i64;
  hkStringBuf::hkStringBuf(&v7, name);
  v4 = hkString::strChr(name, 91);
  if ( v4 )
    hkStringBuf::slice(&v7, 0, (_DWORD)v4 - (_DWORD)name);
  v5 = 0;
  p_m_name = &ClassMemberProperties[0].m_name;
  while ( !hkStringBuf::operator==(&v7, *p_m_name) )
  {
    p_m_name += 3;
    ++v5;
    if ( (__int64)p_m_name >= (__int64)&ClassMemberProperties[35].m_name )
    {
      v5 = 0;
      break;
    }
  }
  v7.m_string.m_size = 0;
  if ( v7.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v7.m_string.m_data,
      v7.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v5;
}

// File Line: 474
// RVA: 0xC80B40
char *__fastcall hkClassMember::getSubtypeOf(const char *name)
{
  int v2; // eax
  unsigned int TypeOf; // eax
  unsigned int v4; // ebx
  char *result; // rax
  int v6; // eax
  unsigned int v7; // eax
  int m_capacityAndFlags; // r8d
  int v9; // eax
  unsigned int v10; // eax
  char *v11; // rdi
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ebx
  hkStringBuf v15; // [rsp+20h] [rbp-98h] BYREF

  if ( !hkString::strNcmp(name, "hkArray<", 8u) )
  {
    v2 = hkString::strLen(name + 8);
    hkStringBuf::hkStringBuf(&v15, name + 8, v2 - 1);
    TypeOf = hkClassMember::getTypeOf(v15.m_string.m_data);
    v15.m_string.m_size = 0;
    v4 = TypeOf;
    if ( v15.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v15.m_string.m_data,
        v15.m_string.m_capacityAndFlags & 0x3FFFFFFF);
    return (char *)v4;
  }
  if ( !hkString::strNcmp(name, "hkRelArray<", 0xBu) )
  {
    v6 = hkString::strLen(name + 11);
    hkStringBuf::hkStringBuf(&v15, name + 11, v6 - 1);
    v7 = hkClassMember::getTypeOf(v15.m_string.m_data);
    m_capacityAndFlags = v15.m_string.m_capacityAndFlags;
    v15.m_string.m_size = 0;
    v4 = v7;
    if ( v15.m_string.m_capacityAndFlags >= 0 )
    {
LABEL_7:
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v15.m_string.m_data,
        m_capacityAndFlags & 0x3FFFFFFF);
      return (char *)v4;
    }
    return (char *)v4;
  }
  if ( !hkString::strNcmp(name, "hkSimpleArray<", 0xEu) )
  {
    v9 = hkString::strLen(name + 14);
    hkStringBuf::hkStringBuf(&v15, name + 14, v9 - 1);
    v10 = hkClassMember::getTypeOf(v15.m_string.m_data);
    m_capacityAndFlags = v15.m_string.m_capacityAndFlags;
    v15.m_string.m_size = 0;
    v4 = v10;
    if ( v15.m_string.m_capacityAndFlags >= 0 )
      goto LABEL_7;
    return (char *)v4;
  }
  result = hkString::strChr(name, 91);
  v11 = result;
  if ( result )
  {
    v12 = (unsigned int)hkString::strChr(name, 93);
    hkStringBuf::hkStringBuf(&v15, v11 + 1, v12 - (_DWORD)v11 - 1);
    v13 = hkString::atoi(v15.m_string.m_data, 0);
    v15.m_string.m_size = 0;
    v14 = v13;
    if ( v15.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v15.m_string.m_data,
        v15.m_string.m_capacityAndFlags & 0x3FFFFFFF);
    return (char *)v14;
  }
  return result;
}

