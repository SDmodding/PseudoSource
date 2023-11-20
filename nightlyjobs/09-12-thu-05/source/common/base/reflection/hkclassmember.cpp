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
  hkClassMember *v1; // rbx
  unsigned int v2; // ecx
  __int64 v3; // rsi
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  hkClass *v7; // rax

  v1 = this;
  v2 = -1;
  v3 = (unsigned __int8)v1->m_type.m_storage;
  switch ( (signed __int64)((signed int)v3 - 1) )
  {
    case 0i64:
    case 1i64:
    case 2i64:
    case 3i64:
    case 4i64:
    case 5i64:
    case 6i64:
    case 7i64:
    case 8i64:
    case 9i64:
    case 10i64:
    case 11i64:
    case 12i64:
    case 13i64:
    case 14i64:
    case 15i64:
    case 16i64:
    case 17i64:
    case 19i64:
    case 20i64:
    case 21i64:
    case 25i64:
    case 26i64:
    case 27i64:
    case 28i64:
    case 29i64:
    case 31i64:
    case 32i64:
    case 33i64:
      if ( hkClassMember::getCstyleArraySize(v1) )
      {
        v4 = hkClassMember::getCstyleArraySize(v1);
        v5 = ClassMemberProperties[v3].m_size;
        v6 = v4;
      }
      else
      {
        v6 = 1;
        v5 = ClassMemberProperties[v3].m_size;
      }
      goto LABEL_13;
    case 23i64:
    case 30i64:
      if ( hkClassMember::getCstyleArraySize(v1) )
        v6 = hkClassMember::getCstyleArraySize(v1);
      else
        v6 = 1;
      v5 = ClassMemberProperties[(unsigned __int8)v1->m_subtype.m_storage].m_size;
      goto LABEL_13;
    case 24i64:
      if ( hkClassMember::getCstyleArraySize(v1) )
        v6 = hkClassMember::getCstyleArraySize(v1);
      else
        v6 = 1;
      v7 = hkClassMember::getStructClass(v1);
      v5 = hkClass::getObjectSize(v7);
LABEL_13:
      v2 = v6 * v5;
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
  result->m_bool = (this->m_flags.m_storage >> 9) & 1;
  return result;
}

// File Line: 205
// RVA: 0xC80440
__int64 __fastcall hkClassMember::getAlignment(hkClassMember *this)
{
  int v1; // eax
  hkClassMember *v2; // rdi
  int v3; // esi
  int v4; // ebx
  hkClassMember *v5; // rax
  hkClassMember *v6; // rax
  unsigned __int16 v7; // ax
  bool v9; // zf
  signed int v10; // eax

  v1 = (unsigned __int8)this->m_type.m_storage;
  v2 = this;
  if ( v1 == 24 || v1 == 31 )
    v1 = (unsigned __int8)this->m_subtype.m_storage;
  if ( v1 == 25 )
  {
    v3 = 1;
    v4 = 0;
    if ( (signed int)hkClass::getNumMembers(this->m_class) > 0 )
    {
      do
      {
        v5 = hkClass::getMember(v2->m_class, v4);
        if ( hkClassMember::getAlignment(v5) > v3 )
        {
          v6 = hkClass::getMember(v2->m_class, v4);
          v3 = hkClassMember::getAlignment(v6);
        }
        ++v4;
      }
      while ( v4 < (signed int)hkClass::getNumMembers(v2->m_class) );
    }
  }
  else
  {
    v3 = ClassMemberProperties[v1].m_align;
  }
  v7 = v2->m_flags.m_storage;
  if ( !(v7 & 0x980) )
    return (unsigned int)v3;
  if ( !(v7 & 0x800) )
  {
    v9 = (v7 & 0x100) == 0;
    v10 = 8;
    if ( !v9 )
      v10 = 16;
    if ( v10 > v3 )
      v3 = v10;
    return (unsigned int)v3;
  }
  if ( v3 < 32 )
    v3 = 32;
  return (unsigned int)v3;
}

// File Line: 242
// RVA: 0xC80D80
bool __fastcall isSimpleType(hkClassMember::Type type)
{
  unsigned __int64 v1; // rax
  signed __int64 v2; // rcx
  bool result; // al

  result = 0;
  if ( (unsigned int)type <= 0x21 )
  {
    v1 = type;
    v2 = 14764998655i64;
    if ( _bittest64(&v2, v1) )
      result = 1;
  }
  return result;
}

// File Line: 251
// RVA: 0xC80DB0
void __fastcall getSimpleTypeName(hkClassMember::Type type, int nelem, hkStringBuf *ret)
{
  if ( nelem )
    hkStringBuf::printf(ret, "%s[%i]", ClassMemberProperties[type].m_name, (unsigned int)nelem);
  else
    hkStringBuf::operator=(ret, ClassMemberProperties[type].m_name);
}

// File Line: 264
// RVA: 0xC80560
__int64 __fastcall hkClassMember::getTypeName(hkClassMember *this, char *buf, int bufLen)
{
  unsigned __int64 v3; // rbx
  hkClassMember *v4; // rdi
  hkClass *v5; // rcx
  int v6; // er14
  char *v7; // r15
  const char *v8; // rsi
  const char *v9; // rbp
  const char **v10; // rax
  signed __int64 v11; // rcx
  hkClass *v12; // rcx
  const char *v13; // rax
  unsigned __int64 v14; // rcx
  const char *v15; // r8
  signed __int64 v16; // rdx
  __int16 v17; // ax
  int v18; // ebx
  hkStringBuf ret; // [rsp+20h] [rbp-A8h]

  v3 = (unsigned __int8)this->m_type.m_storage;
  v4 = this;
  v5 = this->m_class;
  v6 = bufLen;
  v7 = buf;
  v8 = "unknown";
  if ( v5 )
    v9 = hkClass::getName(v5);
  else
    v9 = "unknown";
  v10 = &v4->m_enum->m_name;
  if ( v10 )
    v8 = *v10;
  ret.m_string.m_capacityAndFlags = -2147483520;
  ret.m_string.m_size = 1;
  ret.m_string.m_storage[0] = 0;
  ret.m_string.m_data = ret.m_string.m_storage;
  if ( (unsigned int)v3 <= 0x21 && (v11 = 14899216383i64, _bittest64(&v11, v3)) )
  {
    getSimpleTypeName((hkClassMember::Type)v3, v4->m_cArraySize, &ret);
  }
  else if ( (_DWORD)v3 == 20 )
  {
    v12 = v4->m_class;
    if ( v12 )
    {
      v13 = hkClass::getName(v12);
      hkStringBuf::printf(&ret, "struct %s*", v13);
    }
    else if ( v4->m_subtype.m_storage == 2 )
    {
      hkStringBuf::operator=(&ret, "char*");
    }
    else
    {
      hkStringBuf::operator=(&ret, "void*");
    }
  }
  else if ( ((_DWORD)v3 - 22) & 0xFFFFFFF3 || (_DWORD)v3 == 30 )
  {
    switch ( (_DWORD)v3 )
    {
      case 0x18:
        hkStringBuf::printf(&ret, "enum %s", v8);
        break;
      case 0x1F:
        hkStringBuf::printf(&ret, "flags %s", v8);
        break;
      case 0x19:
        v17 = v4->m_cArraySize;
        if ( v17 )
          hkStringBuf::printf(&ret, "struct %s[%i]", v9, (unsigned int)v17, ret.m_string.m_data);
        else
          hkStringBuf::printf(&ret, "struct %s", v9);
        break;
    }
  }
  else
  {
    v14 = (signed int)hkClassMember::getArrayType(v4);
    if ( (_DWORD)v3 == 22 )
    {
      v15 = "hkArray";
    }
    else
    {
      v15 = "hkRelArray";
      if ( (_DWORD)v3 == 26 )
        v15 = "hkSimpleArray";
    }
    if ( (unsigned int)v14 <= 0x21 && (v16 = 14764998655i64, _bittest64(&v16, v14)) )
    {
      hkStringBuf::printf(&ret, "%s&lt;%s&gt;", v15, ClassMemberProperties[v14].m_name, ret.m_string.m_data);
    }
    else if ( (_DWORD)v14 == 20 )
    {
      if ( v4->m_class )
        hkStringBuf::printf(&ret, "%s&lt;%s*&gt;", v15, v9, ret.m_string.m_data);
      else
        hkStringBuf::printf(&ret, "%s&lt;void*&gt;", v15);
    }
    else if ( (_DWORD)v14 == 25 )
    {
      hkStringBuf::printf(&ret, "%s&lt;struct %s&gt;", v15, v9, ret.m_string.m_data);
    }
  }
  hkString::strNcpy(v7, ret.m_string.m_data, v6);
  v18 = ret.m_string.m_size;
  ret.m_string.m_size = 0;
  if ( ret.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      ret.m_string.m_data,
      ret.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return (unsigned int)(v18 - 1);
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
  hkClassMember *v1; // rbx
  hkClass *v3; // rax

  v1 = this;
  if ( (unsigned int)hkClassMember::getArrayType(this) == 24 || (unsigned int)hkClassMember::getArrayType(v1) == 31 )
    return 0xFFFFFFFFi64;
  if ( (unsigned int)hkClassMember::getArrayType(v1) != 25 )
    return (unsigned int)ClassMemberProperties[(signed int)hkClassMember::getArrayType(v1)].m_size;
  v3 = hkClassMember::getStructClass(v1);
  return hkClass::getObjectSize(v3);
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
  JUMPOUT(this->m_attributes, 0i64, hkCustomAttributes::getAttribute);
  return 0i64;
}

// File Line: 422
// RVA: 0xC80940
signed __int64 __fastcall hkClassMember::getTypeOf(const char *name)
{
  const char *v1; // rbx
  char *v3; // rax
  char *v4; // rax
  unsigned int v5; // edi
  const char **v6; // rbx
  hkStringBuf v7; // [rsp+20h] [rbp-98h]

  v1 = name;
  if ( !hkString::strNcmp(name, "enum ", 5) )
    return 24i64;
  if ( !hkString::strNcmp(v1, "flags ", 6) )
    return 31i64;
  if ( !hkString::strNcmp(v1, "hkArray<", 8) )
    return 22i64;
  if ( !hkString::strNcmp(v1, "hkRelArray<", 11) )
    return 34i64;
  if ( !hkString::strNcmp(v1, "hkSimpleArray<", 14) )
    return 26i64;
  if ( !hkString::strNcmp(v1, "char*", 5) )
    return 29i64;
  if ( !hkString::strNcmp(v1, "hkStringPtr", 11) )
    return 33i64;
  v3 = hkString::strRchr(v1, 42);
  if ( v3 && !v3[1] )
    return 20i64;
  hkStringBuf::hkStringBuf(&v7, v1);
  v4 = hkString::strChr(v1, 91);
  if ( v4 )
    hkStringBuf::slice(&v7, 0, (_DWORD)v4 - (_DWORD)v1);
  v5 = 0;
  v6 = &ClassMemberProperties[0].m_name;
  while ( !(unsigned int)hkStringBuf::operator==(&v7, *v6) )
  {
    v6 += 3;
    ++v5;
    if ( (signed __int64)v6 >= (signed __int64)&ClassMemberProperties[35].m_name )
    {
      v5 = 0;
      break;
    }
  }
  v7.m_string.m_size = 0;
  if ( v7.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v7.m_string.m_data,
      v7.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v5;
}

// File Line: 474
// RVA: 0xC80B40
unsigned __int64 __fastcall hkClassMember::getSubtypeOf(const char *name)
{
  const char *v1; // rbx
  int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // ebx
  unsigned __int64 result; // rax
  int v6; // eax
  unsigned int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  char *v10; // rdi
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ebx
  hkStringBuf v14; // [rsp+20h] [rbp-98h]

  v1 = name;
  if ( !hkString::strNcmp(name, "hkArray<", 8) )
  {
    v2 = hkString::strLen(v1 + 8);
    hkStringBuf::hkStringBuf(&v14, v1 + 8, v2 - 1);
    v3 = hkClassMember::getTypeOf(v14.m_string.m_data);
    v14.m_string.m_size = 0;
    v4 = v3;
    if ( v14.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v14.m_string.m_data,
        v14.m_string.m_capacityAndFlags & 0x3FFFFFFF);
    return v4;
  }
  if ( !hkString::strNcmp(v1, "hkRelArray<", 11) )
  {
    v6 = hkString::strLen(v1 + 11);
    hkStringBuf::hkStringBuf(&v14, v1 + 11, v6 - 1);
    v7 = hkClassMember::getTypeOf(v14.m_string.m_data);
    v14.m_string.m_size = 0;
    v4 = v7;
    if ( v14.m_string.m_capacityAndFlags >= 0 )
    {
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v14.m_string.m_data,
        v14.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      return v4;
    }
    return v4;
  }
  if ( hkString::strNcmp(v1, "hkSimpleArray<", 14) )
  {
    result = (unsigned __int64)hkString::strChr(v1, 91);
    v10 = (char *)result;
    if ( result )
    {
      v11 = (unsigned __int64)hkString::strChr(v1, 93);
      hkStringBuf::hkStringBuf(&v14, v10 + 1, v11 - (_DWORD)v10 - 1);
      v12 = hkString::atoi(v14.m_string.m_data, 0);
      v14.m_string.m_size = 0;
      v13 = v12;
      if ( v14.m_string.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v14.m_string.m_data,
          v14.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      result = v13;
    }
  }
  else
  {
    v8 = hkString::strLen(v1 + 14);
    hkStringBuf::hkStringBuf(&v14, v1 + 14, v8 - 1);
    v9 = hkClassMember::getTypeOf(v14.m_string.m_data);
    v14.m_string.m_size = 0;
    v4 = v9;
    if ( v14.m_string.m_capacityAndFlags < 0 )
      return v4;
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v14.m_string.m_data,
      v14.m_string.m_capacityAndFlags & 0x3FFFFFFF);
    result = v4;
  }
  return result;
}

