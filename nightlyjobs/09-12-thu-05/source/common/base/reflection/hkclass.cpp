// File Line: 47
// RVA: 0xC61C80
void __fastcall hkClass::hkClass(
        hkClass *this,
        const char *className,
        hkClass *parentClass,
        int objectSizeInBytes,
        hkClass **implementedInterfaces,
        int numImplementedInterfaces,
        hkClassEnum *declaredEnums,
        int numDeclaredEnums,
        hkClassMember *members,
        int numMembers,
        const void *defaults,
        hkCustomAttributes *attrs,
        unsigned int flags,
        int version)
{
  this->m_name = className;
  this->m_parent = parentClass;
  this->m_numImplementedInterfaces = numImplementedInterfaces;
  this->m_objectSize = objectSizeInBytes;
  this->m_declaredEnums = declaredEnums;
  this->m_numDeclaredEnums = numDeclaredEnums;
  this->m_declaredMembers = members;
  this->m_numDeclaredMembers = numMembers;
  this->m_defaults = defaults;
  this->m_attributes = attrs;
  this->m_flags.m_storage = flags;
  this->m_describedVersion = version;
}

// File Line: 63
// RVA: 0xC61CE0
const char *__fastcall hkClass::getName(hkClass *this)
{
  return this->m_name;
}

// File Line: 71
// RVA: 0xC61CF0
bool __fastcall hkClass::equals(hkClass *this, hkClass *other)
{
  const char *Name; // rbx
  const char *v4; // rax
  bool result; // al

  result = 0;
  if ( other )
  {
    Name = hkClass::getName(other);
    v4 = hkClass::getName(this);
    if ( !(unsigned int)hkString::strCmp(v4, Name) )
      return 1;
  }
  return result;
}

// File Line: 77
// RVA: 0xC61D40
hkClass *__fastcall hkClass::getParent(hkClass *this)
{
  return this->m_parent;
}

// File Line: 82
// RVA: 0xC61D50
hkClass *__fastcall hkClass::getParent(hkClass *this)
{
  return this->m_parent;
}

// File Line: 87
// RVA: 0xC61D60
__int64 __fastcall hkClass::getInheritanceDepth(hkClass *this)
{
  __int64 result; // rax

  for ( result = 0i64; this; result = (unsigned int)(result + 1) )
    this = this->m_parent;
  return result;
}

// File Line: 99
// RVA: 0xC61D90
hkBool *__fastcall hkClass::isSuperClass(hkClass *this, hkBool *result, hkClass *k)
{
  hkClass *Parent; // rbx
  const char *Name; // rdi
  const char *v7; // rax

  Parent = k;
  if ( k )
  {
    while ( 1 )
    {
      Name = hkClass::getName(this);
      v7 = hkClass::getName(Parent);
      if ( !(unsigned int)hkString::strCmp(v7, Name) )
        break;
      Parent = hkClass::getParent(Parent);
      if ( !Parent )
        goto LABEL_4;
    }
    result->m_bool = 1;
  }
  else
  {
LABEL_4:
    result->m_bool = 0;
  }
  return result;
}

// File Line: 124
// RVA: 0xC61E20
__int64 __fastcall hkClass::getNumInterfaces(hkClass *this)
{
  hkClass *m_parent; // rdx
  __int64 result; // rax

  m_parent = this->m_parent;
  for ( result = (unsigned int)this->m_numImplementedInterfaces; m_parent; m_parent = m_parent->m_parent )
    result = (unsigned int)(m_parent->m_numImplementedInterfaces + result);
  return result;
}

// File Line: 129
// RVA: 0xC61E10
hkClass *__fastcall hkClass::getInterface(hkClass *this, int i)
{
  return 0i64;
}

// File Line: 134
// RVA: 0xC61E50
hkClass *__fastcall hkClass::getDeclaredInterface(hkClass *this, int i)
{
  return 0i64;
}

// File Line: 139
// RVA: 0xC61E60
__int64 __fastcall hkClass::getNumDeclaredInterfaces(hkClass *this)
{
  return (unsigned int)this->m_numImplementedInterfaces;
}

// File Line: 144
// RVA: 0xC61F60
__int64 __fastcall hkClass::getNumEnums(hkClass *this)
{
  hkClass *m_parent; // rdx
  __int64 result; // rax

  m_parent = this->m_parent;
  for ( result = (unsigned int)this->m_numDeclaredEnums; m_parent; m_parent = m_parent->m_parent )
    result = (unsigned int)(m_parent->m_numDeclaredEnums + result);
  return result;
}

// File Line: 149
// RVA: 0xC61E70
hkClassEnum *__fastcall hkClass::getEnum(hkClass *this, int enumIndex)
{
  hkClass *v3; // rbx
  int v4; // edi

  v3 = this;
  v4 = enumIndex - hkClass::getNumEnums(this);
  if ( !v3 )
    return this->m_declaredEnums;
  while ( 1 )
  {
    v4 += v3->m_numDeclaredEnums;
    if ( v4 >= 0 )
      break;
    v3 = v3->m_parent;
    if ( !v3 )
      return this->m_declaredEnums;
  }
  return &v3->m_declaredEnums[v4];
}

// File Line: 168
// RVA: 0xC61EE0
hkClassEnum *__fastcall hkClass::getEnumByName(hkClass *this, const char *name)
{
  int v4; // ebx
  hkClassEnum *Enum; // rsi

  v4 = 0;
  if ( hkClass::getNumEnums(this) <= 0 )
    return 0i64;
  while ( 1 )
  {
    Enum = hkClass::getEnum(this, v4);
    if ( !(unsigned int)hkString::strCmp(Enum->m_name, name) )
      break;
    if ( ++v4 >= hkClass::getNumEnums(this) )
      return 0i64;
  }
  return Enum;
}

// File Line: 181
// RVA: 0xC61FB0
hkClassEnum *__fastcall hkClass::getDeclaredEnumByName(hkClass *this, const char *name)
{
  int v4; // ebx
  hkClassEnum *DeclaredEnum; // rsi

  v4 = 0;
  if ( hkClass::getNumDeclaredEnums(this) <= 0 )
    return 0i64;
  while ( 1 )
  {
    DeclaredEnum = hkClass::getDeclaredEnum(this, v4);
    if ( !(unsigned int)hkString::strCmp(DeclaredEnum->m_name, name) )
      break;
    if ( ++v4 >= hkClass::getNumDeclaredEnums(this) )
      return 0i64;
  }
  return DeclaredEnum;
}

// File Line: 194
// RVA: 0xC61F90
hkClassEnum *__fastcall hkClass::getDeclaredEnum(hkClass *this, int enumIndex)
{
  return &this->m_declaredEnums[enumIndex];
}

// File Line: 200
// RVA: 0xC62030
__int64 __fastcall hkClass::getNumDeclaredEnums(hkClass *this)
{
  return (unsigned int)this->m_numDeclaredEnums;
}

// File Line: 205
// RVA: 0xC621C0
__int64 __fastcall hkClass::getNumMembers(hkClass *this)
{
  hkClass *m_parent; // rdx
  __int64 result; // rax

  m_parent = this->m_parent;
  for ( result = (unsigned int)this->m_numDeclaredMembers; m_parent; m_parent = m_parent->m_parent )
    result = (unsigned int)(m_parent->m_numDeclaredMembers + result);
  return result;
}

// File Line: 210
// RVA: 0xC62040
hkClassMember *__fastcall hkClass::getMember(hkClass *this, int memberIndex)
{
  hkClass *v3; // rbx
  int v4; // edi

  v3 = this;
  v4 = memberIndex - hkClass::getNumMembers(this);
  if ( !v3 )
    return this->m_declaredMembers;
  while ( 1 )
  {
    v4 += v3->m_numDeclaredMembers;
    if ( v4 >= 0 )
      break;
    v3 = v3->m_parent;
    if ( !v3 )
      return this->m_declaredMembers;
  }
  return &v3->m_declaredMembers[v4];
}

// File Line: 229
// RVA: 0xC620B0
// attributes: thunk
hkClassMember *__fastcall hkClass::getMember(hkClass *this, int memberIndex)
{
  return ?getMember@hkClass@@QEBAAEBVhkClassMember@@H@Z(this, memberIndex);
}

// File Line: 235
// RVA: 0xC62310
__int64 __fastcall hkClass::getNumDeclaredMembers(hkClass *this)
{
  return (unsigned int)this->m_numDeclaredMembers;
}

// File Line: 240
// RVA: 0xC621F0
hkClassMember *__fastcall hkClass::getDeclaredMember(hkClass *this, int i)
{
  return &this->m_declaredMembers[i];
}

// File Line: 246
// RVA: 0xC62210
hkClassMember *__fastcall hkClass::getDeclaredMemberByName(hkClass *this, const char *name)
{
  int v4; // ebx
  hkClassMember *DeclaredMember; // rsi

  v4 = 0;
  if ( hkClass::getNumDeclaredMembers(this) <= 0 )
    return 0i64;
  while ( 1 )
  {
    DeclaredMember = hkClass::getDeclaredMember(this, v4);
    if ( !(unsigned int)hkString::strCmp(DeclaredMember->m_name, name) )
      break;
    if ( ++v4 >= hkClass::getNumDeclaredMembers(this) )
      return 0i64;
  }
  return DeclaredMember;
}

// File Line: 259
// RVA: 0xC620C0
hkClassMember *__fastcall hkClass::getMemberByName(hkClass *this, const char *name)
{
  int v4; // ebx
  hkClassMember *Member; // rsi

  v4 = 0;
  if ( hkClass::getNumMembers(this) <= 0 )
    return 0i64;
  while ( 1 )
  {
    Member = hkClass::getMember(this, v4);
    if ( !(unsigned int)hkString::strCmp(Member->m_name, name) )
      break;
    if ( ++v4 >= hkClass::getNumMembers(this) )
      return 0i64;
  }
  return Member;
}

// File Line: 272
// RVA: 0xC62140
__int64 __fastcall hkClass::getMemberIndexByName(hkClass *this, const char *name)
{
  unsigned int v4; // ebx
  hkClassMember *Member; // rax

  v4 = 0;
  if ( hkClass::getNumMembers(this) <= 0 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    Member = hkClass::getMember(this, v4);
    if ( !(unsigned int)hkString::strCmp(Member->m_name, name) )
      break;
    if ( (int)++v4 >= hkClass::getNumMembers(this) )
      return 0xFFFFFFFFi64;
  }
  return v4;
}

// File Line: 285
// RVA: 0xC62290
__int64 __fastcall hkClass::getDeclaredMemberIndexByName(hkClass *this, const char *name)
{
  unsigned int v4; // ebx
  hkClassMember *DeclaredMember; // rax

  v4 = 0;
  if ( hkClass::getNumDeclaredMembers(this) <= 0 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    DeclaredMember = hkClass::getDeclaredMember(this, v4);
    if ( !(unsigned int)hkString::strCmp(DeclaredMember->m_name, name) )
      break;
    if ( (int)++v4 >= hkClass::getNumDeclaredMembers(this) )
      return 0xFFFFFFFFi64;
  }
  return v4;
}

// File Line: 298
// RVA: 0xC62320
__int64 __fastcall hkClass::getObjectSize(hkClass *this)
{
  return (unsigned int)this->m_objectSize;
}

// File Line: 303
// RVA: 0xC62330
void __fastcall hkClass::setObjectSize(hkClass *this, int size)
{
  this->m_objectSize = size;
}

// File Line: 308
// RVA: 0xC62340
hkBool *__fastcall hkClass::hasVtable(hkClass *this, hkBool *result)
{
  hkClass *v3; // rbx
  hkClass *i; // rax

  v3 = this;
  for ( i = hkClass::getParent(this); i; i = hkClass::getParent(i) )
    v3 = i;
  result->m_bool = v3->m_numImplementedInterfaces != 0;
  return result;
}

// File Line: 321
// RVA: 0xC62800
unsigned int __fastcall hkClass::getSignature(hkClass *this, char signatureFlags)
{
  hkClass *Parent; // rbx
  bool v3; // di
  hkCrcStreamWriter<unsigned int,3988292384> w; // [rsp+20h] [rbp-28h] BYREF

  Parent = this;
  *(_DWORD *)&w.m_memSizeAndFlags = 0x1FFFF;
  w.m_crc = -1;
  v3 = (signatureFlags & 1) == 0;
  for ( w.vfptr = (hkBaseObjectVtbl *)&hkCrc32StreamWriter::`vftable; Parent; Parent = hkClass::getParent(Parent) )
  {
    hkClass::writeSignature(Parent, &w);
    if ( !v3 )
      break;
  }
  return hkCrcStreamWriter<unsigned int,3988292384>::getCrc(&w);
}

// File Line: 335
// RVA: 0xC62880
__int64 __fastcall hkClass::getDescribedVersion(hkClass *this)
{
  return (unsigned int)this->m_describedVersion;
}

// File Line: 346
// RVA: 0xC62B60
hkResult *__fastcall hkClass::retrieveMember(
        hkClass *this,
        hkResult *result,
        int memberIndex,
        const char **defaultOut,
        hkClassMember **memberOut)
{
  hkClass *v7; // rbx
  int v8; // edi
  int *m_defaults; // rcx
  __int64 v11; // rax
  const char *v12; // rax
  hkClassMember *v13; // rdx

  v7 = this;
  v8 = memberIndex - hkClass::getNumMembers(this);
  if ( v7 )
  {
    while ( 1 )
    {
      v8 += v7->m_numDeclaredMembers;
      if ( v8 >= 0 )
        break;
      v7 = v7->m_parent;
      if ( !v7 )
        goto LABEL_4;
    }
    m_defaults = (int *)v7->m_defaults;
    if ( m_defaults )
    {
      v11 = m_defaults[v8];
      if ( (int)v11 >= 0 )
      {
        v12 = (char *)m_defaults + v11;
        goto LABEL_11;
      }
      if ( (_DWORD)v11 == -2 )
      {
        v12 = s_defaultClassBuffer;
LABEL_11:
        *defaultOut = v12;
        v13 = &v7->m_declaredMembers[v8];
        result->m_enum = HK_SUCCESS;
        *memberOut = v13;
        return result;
      }
    }
  }
LABEL_4:
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 374
// RVA: 0xC62390
_BOOL8 __fastcall hkClass::hasDefault(hkClass *this, int memberIndex)
{
  void *defaultOut; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+60h] [rbp+18h] BYREF
  hkClassMember *memberOut; // [rsp+68h] [rbp+20h] BYREF

  return hkClass::retrieveMember(this, &result, memberIndex, (const void **)&defaultOut, &memberOut)->m_enum == HK_SUCCESS;
}

// File Line: 381
// RVA: 0xC623D0
_BOOL8 __fastcall hkClass::hasDeclaredDefault(hkClass *this, int declaredIndex)
{
  _DWORD *m_defaults; // r8
  int v3; // ecx
  _BOOL8 result; // rax

  m_defaults = this->m_defaults;
  result = 0;
  if ( m_defaults )
  {
    v3 = m_defaults[declaredIndex];
    if ( (int)(v3 + 0x80000000) < 0 || v3 == -2 )
      return 1;
  }
  return result;
}

// File Line: 388
// RVA: 0xC62470
void *__fastcall hkClass::getDefault(hkClass *this, int memberIndex)
{
  __int64 v2; // rbx
  hkClassMember *memberOut; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+60h] [rbp+18h] BYREF
  void *defaultOut; // [rsp+68h] [rbp+20h] BYREF

  v2 = 0i64;
  defaultOut = 0i64;
  hkClass::retrieveMember(this, &result, memberIndex, (const void **)&defaultOut, &memberOut);
  if ( result.m_enum == HK_SUCCESS )
    return defaultOut;
  return (void *)v2;
}

// File Line: 400
// RVA: 0xC62400
hkResult *__fastcall hkClass::getDefault(hkClass *this, hkResult *result, int memberIndex, hkStreamWriter *writer)
{
  hkBaseObjectVtbl *vfptr; // rbx
  unsigned int SizeInBytes; // eax
  void *defaultOut; // [rsp+30h] [rbp-18h] BYREF
  hkClassMember *memberOut; // [rsp+58h] [rbp+10h] BYREF

  defaultOut = 0i64;
  memberOut = 0i64;
  hkClass::retrieveMember(this, result, memberIndex, (const void **)&defaultOut, &memberOut);
  if ( result->m_enum == HK_SUCCESS )
  {
    vfptr = writer->vfptr;
    SizeInBytes = hkClassMember::getSizeInBytes(memberOut);
    ((void (__fastcall *)(hkStreamWriter *, void *, _QWORD))vfptr[2].__vecDelDtor)(writer, defaultOut, SizeInBytes);
  }
  return result;
}

// File Line: 413
// RVA: 0xC624C0
hkResult *__fastcall hkClass::getDeclaredDefault(
        hkClass *this,
        hkResult *result,
        int declaredIndex,
        hkStreamWriter *writer)
{
  int *m_defaults; // rdx
  __int64 v7; // rax
  const char *v9; // rdi
  hkBaseObjectVtbl *vfptr; // rbx
  unsigned int SizeInBytes; // eax

  m_defaults = (int *)this->m_defaults;
  if ( !m_defaults )
    goto LABEL_4;
  v7 = m_defaults[declaredIndex];
  if ( (int)v7 >= 0 )
  {
    v9 = (char *)m_defaults + v7;
  }
  else
  {
    if ( (_DWORD)v7 != -2 )
    {
LABEL_4:
      result->m_enum = HK_FAILURE;
      return result;
    }
    v9 = s_defaultClassBuffer;
  }
  vfptr = writer->vfptr;
  SizeInBytes = hkClassMember::getSizeInBytes(&this->m_declaredMembers[declaredIndex]);
  ((void (__fastcall *)(hkStreamWriter *, const char *, _QWORD))vfptr[2].__vecDelDtor)(writer, v9, SizeInBytes);
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 432
// RVA: 0xC62570
hkResult *__fastcall hkClass::getDefault(hkClass *this, hkResult *result, int memberIndex, hkTypedUnion *value)
{
  hkResultEnum v5; // ebx
  hkClassMember *v7; // rbp
  unsigned __int8 m_storage; // al
  hkClass *Class; // rax
  void *v10; // rcx
  hkClass *EnumClass; // rbx
  int EnumValue; // eax
  int v13; // ebp
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax
  void *v15; // rdx
  hkClassMember *v17; // [rsp+30h] [rbp-18h] BYREF
  void *memberAddress; // [rsp+58h] [rbp+10h] BYREF

  v5 = HK_SUCCESS;
  memberAddress = 0i64;
  v17 = 0i64;
  hkClass::retrieveMember(this, result, memberIndex, (const void **)&memberAddress, &v17);
  if ( result->m_enum == HK_SUCCESS )
  {
    v7 = v17;
    m_storage = v17->m_type.m_storage;
    if ( m_storage == 20 )
    {
      Class = hkClassMember::getClass(v17);
      v10 = memberAddress;
      value->m_type.m_storage = 20;
      value->m_elem.m_int64 = (__int64)v10;
      value->m_elem.m_variant.m_class = Class;
    }
    else if ( m_storage == 24 )
    {
      EnumClass = (hkClass *)hkClassMember::getEnumClass(v17);
      EnumValue = hkClassMember::getEnumValue(v7, memberAddress);
      value->m_type.m_storage = 24;
      value->m_elem.m_int32 = EnumValue;
      value->m_elem.m_variant.m_class = EnumClass;
    }
    else
    {
      v13 = m_storage;
      ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)m_storage);
      if ( ClassMemberTypeProperties->m_size > 0x40u )
      {
        v5 = HK_FAILURE;
      }
      else
      {
        v15 = memberAddress;
        value->m_type.m_storage = v13;
        hkString::memCpy(&value->m_elem, v15, ClassMemberTypeProperties->m_size);
      }
      result->m_enum = v5;
    }
  }
  return result;
}

// File Line: 458
// RVA: 0xC62650
const char *__fastcall hkClass::getDeclaredDefault(hkClass *this, int declaredIndex)
{
  int *m_defaults; // r8
  __int64 v3; // rcx

  m_defaults = (int *)this->m_defaults;
  if ( !m_defaults )
    return 0i64;
  v3 = m_defaults[declaredIndex];
  if ( (int)v3 >= 0 )
    return (char *)m_defaults + v3;
  if ( (_DWORD)v3 != -2 )
    return 0i64;
  return s_defaultClassBuffer;
}

// File Line: 472
// RVA: 0xC62690
hkResult *__fastcall hkClass::getDeclaredDefault(
        hkClass *this,
        hkResult *result,
        int declaredIndex,
        hkTypedUnion *value)
{
  char *m_defaults; // r9
  __int64 v7; // rdx
  __int64 *v8; // r15
  hkClassMember *v9; // rbp
  unsigned __int8 m_storage; // al
  hkClass *Class; // rax
  __int64 v12; // rcx
  hkResult *v13; // rax
  int v14; // edi
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax
  hkClass *EnumClass; // rdi
  int EnumValue; // eax

  m_defaults = (char *)this->m_defaults;
  if ( m_defaults && ((v7 = *(int *)&m_defaults[4 * declaredIndex], (int)(v7 + 0x80000000) < 0) || (_DWORD)v7 == -2) )
  {
    v8 = (__int64 *)s_defaultClassBuffer;
    if ( (_DWORD)v7 != -2 )
      v8 = (__int64 *)&m_defaults[v7];
    v9 = &this->m_declaredMembers[declaredIndex];
    m_storage = v9->m_type.m_storage;
    if ( m_storage == 20 )
    {
      Class = hkClassMember::getClass(&this->m_declaredMembers[declaredIndex]);
      v12 = *v8;
      value->m_elem.m_variant.m_class = Class;
      value->m_elem.m_int64 = v12;
      v13 = result;
      value->m_type.m_storage = 20;
      result->m_enum = HK_SUCCESS;
    }
    else if ( m_storage == 24 || m_storage == 31 )
    {
      EnumClass = (hkClass *)hkClassMember::getEnumClass(v9);
      EnumValue = hkClassMember::getEnumValue(v9, v8);
      value->m_elem.m_variant.m_class = EnumClass;
      value->m_elem.m_int32 = EnumValue;
      value->m_type.m_storage = 24;
      result->m_enum = HK_SUCCESS;
      return result;
    }
    else
    {
      v14 = m_storage;
      ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)m_storage);
      if ( ClassMemberTypeProperties->m_size > 0x40u )
      {
        v13 = result;
        result->m_enum = HK_FAILURE;
      }
      else
      {
        value->m_type.m_storage = v14;
        hkString::memCpy(&value->m_elem, v8, ClassMemberTypeProperties->m_size);
        v13 = result;
        result->m_enum = HK_SUCCESS;
      }
    }
  }
  else
  {
    v13 = result;
    result->m_enum = HK_FAILURE;
  }
  return v13;
}

// File Line: 505
// RVA: 0xC62890
void __fastcall hkClass::writeSignature(hkClass *this, hkStreamWriter *w)
{
  hkClass *v2; // rbp
  int i; // ebx
  __int64 v5; // rcx
  char *v6; // rdi
  __int64 v7; // rcx
  __int64 v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rax
  unsigned __int8 v11; // al
  __int16 v12; // si
  unsigned __int8 v13; // bl
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax
  __int16 m_size; // cx
  hkClass *Class; // rbx
  hkClassEnum *EnumClass; // rax
  int v18; // eax
  bool v19; // cc
  __int16 v20; // [rsp+20h] [rbp-98h]
  int v21; // [rsp+24h] [rbp-94h]
  __int64 v22; // [rsp+28h] [rbp-90h]
  hkOArchive v23; // [rsp+30h] [rbp-88h] BYREF
  __int64 v24; // [rsp+50h] [rbp-68h]
  __int64 v25; // [rsp+58h] [rbp-60h]
  char *src; // [rsp+60h] [rbp-58h]
  __int64 v27; // [rsp+80h] [rbp-38h]
  __int64 v28; // [rsp+88h] [rbp-30h]
  unsigned __int8 v31; // [rsp+D0h] [rbp+18h]
  unsigned __int8 v32; // [rsp+D8h] [rbp+20h]

  v2 = this;
  hkOArchive::hkOArchive(&v23, w, 0);
  hkOArchive::write32(&v23, v2->m_numImplementedInterfaces);
  for ( i = 0; i < v2->m_numDeclaredEnums; ++i )
    hkClassEnum::writeSignature(&v2->m_declaredEnums[i], w);
  hkOArchive::write32(&v23, v2->m_numDeclaredEnums);
  v21 = 0;
  if ( v2->m_numDeclaredMembers > 0 )
  {
    v5 = 0i64;
    v22 = 0i64;
    do
    {
      v6 = (char *)v2->m_declaredMembers + v5;
      v7 = *((_QWORD *)v6 + 3);
      v8 = *((_QWORD *)v6 + 1);
      src = *(char **)v6;
      v9 = *((_QWORD *)v6 + 2);
      v24 = v8;
      v25 = v9;
      v10 = *((_QWORD *)v6 + 4);
      v27 = v7;
      v28 = v10;
      v11 = v7;
      v32 = v7;
      if ( (_BYTE)v7 == 24 || (_BYTE)v7 == 31 )
      {
        ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)BYTE1(v7));
        v8 = v24;
        m_size = ClassMemberTypeProperties->m_size;
        v11 = v32;
        v12 = (8 * m_size) ^ WORD2(v27);
        v13 = 0;
      }
      else
      {
        v12 = WORD2(v27);
        v13 = BYTE1(v27);
      }
      v31 = v13;
      v20 = 0;
      if ( (v12 & 0x400) != 0 )
      {
        v12 ^= 0x400u;
        if ( v13 )
          v20 = v13;
        v13 = v11;
        v31 = v11;
        v32 = 19;
      }
      if ( v8 && v6[24] != 20 && v6[25] != 20 )
      {
        Class = hkClassMember::getClass((hkClassMember *)v6);
        if ( Class )
        {
          do
          {
            hkClass::writeSignature(Class, w);
            Class = hkClass::getParent(Class);
          }
          while ( Class );
          v2 = this;
        }
        v13 = v31;
      }
      if ( v25 )
      {
        EnumClass = hkClassMember::getEnumClass((hkClassMember *)v6);
        hkClassEnum::writeSignature(EnumClass, w);
      }
      v18 = hkString::strLen(src);
      hkOArchive::writeRaw(&v23, src, v18);
      hkOArchive::write16(&v23, v32);
      hkOArchive::write16(&v23, v13);
      if ( v20 )
        hkOArchive::write16(&v23, v20);
      hkOArchive::write16(&v23, SWORD1(v27));
      hkOArchive::write16(&v23, v12);
      v5 = v22 + 40;
      v19 = ++v21 < v2->m_numDeclaredMembers;
      v22 += 40i64;
    }
    while ( v19 );
  }
  hkOArchive::write32(&v23, v2->m_numDeclaredMembers);
  hkOArchive::~hkOArchive(&v23);
}

// File Line: 586
// RVA: 0xC62B20
hkVariant *__fastcall hkClass::getAttribute(hkClass *this, const char *id)
{
  hkCustomAttributes *m_attributes; // rcx

  m_attributes = this->m_attributes;
  if ( m_attributes )
    return hkCustomAttributes::getAttribute(m_attributes, id);
  else
    return 0i64;
}

// File Line: 591
// RVA: 0xC62B40
hkFlags<enum hkClass::FlagValues,unsigned int> *__fastcall hkClass::getFlags(hkClass *this)
{
  return &this->m_flags;
}

// File Line: 596
// RVA: 0xC62B50
hkFlags<enum hkClass::FlagValues,unsigned int> *__fastcall hkClass::getFlags(hkClass *this)
{
  return &this->m_flags;
}

