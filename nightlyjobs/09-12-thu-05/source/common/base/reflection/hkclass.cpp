// File Line: 47
// RVA: 0xC61C80
void __fastcall hkClass::hkClass(hkClass *this, const char *className, hkClass *parentClass, int objectSizeInBytes, hkClass **implementedInterfaces, int numImplementedInterfaces, hkClassEnum *declaredEnums, int numDeclaredEnums, hkClassMember *members, int numMembers, const void *defaults, hkCustomAttributes *attrs, unsigned int flags, unsigned int version)
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
  hkClass *v2; // rdi
  const char *v3; // rbx
  const char *v4; // rax
  bool result; // al

  v2 = this;
  result = 0;
  if ( other )
  {
    v3 = hkClass::getName(other);
    v4 = hkClass::getName(v2);
    if ( !(unsigned int)hkString::strCmp(v4, v3) )
      result = 1;
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
  hkClass *v3; // rbx
  hkBool *v4; // rsi
  hkClass *v5; // rbp
  const char *v6; // rdi
  const char *v7; // rax

  v3 = k;
  v4 = result;
  v5 = this;
  if ( k )
  {
    while ( 1 )
    {
      v6 = hkClass::getName(v5);
      v7 = hkClass::getName(v3);
      if ( !(unsigned int)hkString::strCmp(v7, v6) )
        break;
      v3 = hkClass::getParent(v3);
      if ( !v3 )
        goto LABEL_4;
    }
    v4->m_bool = 1;
  }
  else
  {
LABEL_4:
    v4->m_bool = 0;
  }
  return v4;
}

// File Line: 124
// RVA: 0xC61E20
__int64 __fastcall hkClass::getNumInterfaces(hkClass *this)
{
  hkClass *v1; // rdx
  __int64 result; // rax

  v1 = this->m_parent;
  for ( result = (unsigned int)this->m_numImplementedInterfaces; v1; v1 = v1->m_parent )
    result = (unsigned int)(v1->m_numImplementedInterfaces + result);
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
  hkClass *v1; // rdx
  __int64 result; // rax

  v1 = this->m_parent;
  for ( result = (unsigned int)this->m_numDeclaredEnums; v1; v1 = v1->m_parent )
    result = (unsigned int)(v1->m_numDeclaredEnums + result);
  return result;
}

// File Line: 149
// RVA: 0xC61E70
hkClassEnum *__fastcall hkClass::getEnum(hkClass *this, int enumIndex)
{
  hkClass *v2; // rsi
  hkClass *v3; // rbx
  int v4; // edi

  v2 = this;
  v3 = this;
  v4 = enumIndex - hkClass::getNumEnums(this);
  if ( !v3 )
    return v2->m_declaredEnums;
  while ( 1 )
  {
    v4 += v3->m_numDeclaredEnums;
    if ( v4 >= 0 )
      break;
    v3 = v3->m_parent;
    if ( !v3 )
      return v2->m_declaredEnums;
  }
  return &v3->m_declaredEnums[v4];
}

// File Line: 168
// RVA: 0xC61EE0
hkClassEnum *__fastcall hkClass::getEnumByName(hkClass *this, const char *name)
{
  const char *v2; // rbp
  hkClass *v3; // rdi
  int v4; // ebx
  hkClassEnum *v5; // rsi

  v2 = name;
  v3 = this;
  v4 = 0;
  if ( hkClass::getNumEnums(this) <= 0 )
    return 0i64;
  while ( 1 )
  {
    v5 = hkClass::getEnum(v3, v4);
    if ( !(unsigned int)hkString::strCmp(v5->m_name, v2) )
      break;
    if ( ++v4 >= hkClass::getNumEnums(v3) )
      return 0i64;
  }
  return v5;
}

// File Line: 181
// RVA: 0xC61FB0
hkClassEnum *__fastcall hkClass::getDeclaredEnumByName(hkClass *this, const char *name)
{
  const char *v2; // rbp
  hkClass *v3; // rdi
  int v4; // ebx
  hkClassEnum *v5; // rsi

  v2 = name;
  v3 = this;
  v4 = 0;
  if ( hkClass::getNumDeclaredEnums(this) <= 0 )
    return 0i64;
  while ( 1 )
  {
    v5 = hkClass::getDeclaredEnum(v3, v4);
    if ( !(unsigned int)hkString::strCmp(v5->m_name, v2) )
      break;
    if ( ++v4 >= hkClass::getNumDeclaredEnums(v3) )
      return 0i64;
  }
  return v5;
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
  hkClass *v1; // rdx
  __int64 result; // rax

  v1 = this->m_parent;
  for ( result = (unsigned int)this->m_numDeclaredMembers; v1; v1 = v1->m_parent )
    result = (unsigned int)(v1->m_numDeclaredMembers + result);
  return result;
}

// File Line: 210
// RVA: 0xC62040
hkClassMember *__fastcall hkClass::getMember(hkClass *this, int memberIndex)
{
  hkClass *v2; // rsi
  hkClass *v3; // rbx
  int v4; // edi

  v2 = this;
  v3 = this;
  v4 = memberIndex - hkClass::getNumMembers(this);
  if ( !v3 )
    return v2->m_declaredMembers;
  while ( 1 )
  {
    v4 += v3->m_numDeclaredMembers;
    if ( v4 >= 0 )
      break;
    v3 = v3->m_parent;
    if ( !v3 )
      return v2->m_declaredMembers;
  }
  return &v3->m_declaredMembers[v4];
}

// File Line: 229
// RVA: 0xC620B0
hkClassMember *__fastcall hkClass::getMember(hkClass *this, int memberIndex)
{
  return hkClass::getMember(this, memberIndex);
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
  const char *v2; // rbp
  hkClass *v3; // rdi
  int v4; // ebx
  hkClassMember *v5; // rsi

  v2 = name;
  v3 = this;
  v4 = 0;
  if ( hkClass::getNumDeclaredMembers(this) <= 0 )
    return 0i64;
  while ( 1 )
  {
    v5 = hkClass::getDeclaredMember(v3, v4);
    if ( !(unsigned int)hkString::strCmp(v5->m_name, v2) )
      break;
    if ( ++v4 >= hkClass::getNumDeclaredMembers(v3) )
      return 0i64;
  }
  return v5;
}

// File Line: 259
// RVA: 0xC620C0
hkClassMember *__fastcall hkClass::getMemberByName(hkClass *this, const char *name)
{
  const char *v2; // rbp
  hkClass *v3; // rdi
  int v4; // ebx
  hkClassMember *v5; // rsi

  v2 = name;
  v3 = this;
  v4 = 0;
  if ( hkClass::getNumMembers(this) <= 0 )
    return 0i64;
  while ( 1 )
  {
    v5 = hkClass::getMember(v3, v4);
    if ( !(unsigned int)hkString::strCmp(v5->m_name, v2) )
      break;
    if ( ++v4 >= hkClass::getNumMembers(v3) )
      return 0i64;
  }
  return v5;
}

// File Line: 272
// RVA: 0xC62140
signed __int64 __fastcall hkClass::getMemberIndexByName(hkClass *this, const char *name)
{
  const char *v2; // rsi
  hkClass *v3; // rdi
  unsigned int v4; // ebx
  hkClassMember *v5; // rax

  v2 = name;
  v3 = this;
  v4 = 0;
  if ( hkClass::getNumMembers(this) <= 0 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v5 = hkClass::getMember(v3, v4);
    if ( !(unsigned int)hkString::strCmp(v5->m_name, v2) )
      break;
    if ( (signed int)++v4 >= hkClass::getNumMembers(v3) )
      return 0xFFFFFFFFi64;
  }
  return v4;
}

// File Line: 285
// RVA: 0xC62290
signed __int64 __fastcall hkClass::getDeclaredMemberIndexByName(hkClass *this, const char *name)
{
  const char *v2; // rsi
  hkClass *v3; // rdi
  unsigned int v4; // ebx
  hkClassMember *v5; // rax

  v2 = name;
  v3 = this;
  v4 = 0;
  if ( hkClass::getNumDeclaredMembers(this) <= 0 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v5 = hkClass::getDeclaredMember(v3, v4);
    if ( !(unsigned int)hkString::strCmp(v5->m_name, v2) )
      break;
    if ( (signed int)++v4 >= hkClass::getNumDeclaredMembers(v3) )
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
  hkBool *v2; // rdi
  hkClass *v3; // rbx
  hkClass *i; // rax

  v2 = result;
  v3 = this;
  for ( i = hkClass::getParent(this); i; i = hkClass::getParent(i) )
    v3 = i;
  v2->m_bool = v3->m_numImplementedInterfaces != 0;
  return v2;
}

// File Line: 321
// RVA: 0xC62800
unsigned int __fastcall hkClass::getSignature(hkClass *this, int signatureFlags)
{
  hkClass *v2; // rbx
  char v3; // di
  hkStreamWriter w; // [rsp+20h] [rbp-28h]
  int v6; // [rsp+30h] [rbp-18h]

  v2 = this;
  *(_DWORD *)&w.m_memSizeAndFlags = 0x1FFFF;
  v6 = -1;
  v3 = ~(_BYTE)signatureFlags & 1;
  for ( w.vfptr = (hkBaseObjectVtbl *)&hkCrc32StreamWriter::`vftable'; v2; v2 = hkClass::getParent(v2) )
  {
    hkClass::writeSignature(v2, &w);
    if ( !v3 )
      break;
  }
  return hkCrcStreamWriter<unsigned int,3988292384>::getCrc((hkCrcStreamWriter<unsigned int,3988292384> *)&w);
}

// File Line: 335
// RVA: 0xC62880
__int64 __fastcall hkClass::getDescribedVersion(hkClass *this)
{
  return (unsigned int)this->m_describedVersion;
}

// File Line: 346
// RVA: 0xC62B60
hkResult *__fastcall hkClass::retrieveMember(hkClass *this, hkResult *result, int memberIndex, const void **defaultOut, hkClassMember **memberOut)
{
  const void **v5; // r14
  hkResult *v6; // rsi
  hkClass *v7; // rbx
  int v8; // edi
  signed int *v10; // rcx
  __int64 v11; // rax
  const char *v12; // rax
  hkClassMember *v13; // rdx

  v5 = defaultOut;
  v6 = result;
  v7 = this;
  v8 = memberIndex - (unsigned __int64)hkClass::getNumMembers(this);
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
    v10 = (signed int *)v7->m_defaults;
    if ( v10 )
    {
      v11 = v10[v8];
      if ( (signed int)v11 >= 0 )
      {
        if ( (_DWORD)v11 == -2 )
          v12 = s_defaultClassBuffer;
        else
          v12 = (char *)v10 + v11;
        goto LABEL_13;
      }
      if ( (_DWORD)v11 == -2 )
      {
        v12 = s_defaultClassBuffer;
LABEL_13:
        *v5 = v12;
        v13 = &v7->m_declaredMembers[v8];
        v6->m_enum = 0;
        *memberOut = v13;
        return v6;
      }
    }
  }
LABEL_4:
  v6->m_enum = 1;
  return v6;
}

// File Line: 374
// RVA: 0xC62390
_BOOL8 __fastcall hkClass::hasDefault(hkClass *this, int memberIndex)
{
  void *defaultOut; // [rsp+30h] [rbp-18h]
  hkResult result; // [rsp+60h] [rbp+18h]
  hkClassMember *memberOut; // [rsp+68h] [rbp+20h]

  return hkClass::retrieveMember(this, &result, memberIndex, (const void **)&defaultOut, &memberOut)->m_enum == 0;
}

// File Line: 381
// RVA: 0xC623D0
_BOOL8 __fastcall hkClass::hasDeclaredDefault(hkClass *this, int declaredIndex)
{
  _DWORD *v2; // r8
  int v3; // ecx
  _BOOL8 result; // rax

  v2 = this->m_defaults;
  result = 0;
  if ( v2 )
  {
    v3 = v2[declaredIndex];
    if ( (signed int)(v3 + 2147483648) < 0 || v3 == -2 )
      result = 1;
  }
  return result;
}

// File Line: 388
// RVA: 0xC62470
void *__fastcall hkClass::getDefault(hkClass *this, int memberIndex)
{
  void *v2; // rbx
  hkClassMember *memberOut; // [rsp+30h] [rbp-18h]
  hkResult result; // [rsp+60h] [rbp+18h]
  void *defaultOut; // [rsp+68h] [rbp+20h]

  v2 = 0i64;
  defaultOut = 0i64;
  hkClass::retrieveMember(this, &result, memberIndex, (const void **)&defaultOut, &memberOut);
  if ( result.m_enum == HK_SUCCESS )
    v2 = defaultOut;
  return v2;
}

// File Line: 400
// RVA: 0xC62400
hkResult *__fastcall hkClass::getDefault(hkClass *this, hkResult *result, int memberIndex, hkStreamWriter *writer)
{
  hkStreamWriter *v4; // rsi
  hkResult *v5; // rdi
  hkBaseObjectVtbl *v6; // rbx
  unsigned int v7; // eax
  void *defaultOut; // [rsp+30h] [rbp-18h]
  hkClassMember *memberOut; // [rsp+58h] [rbp+10h]

  v4 = writer;
  defaultOut = 0i64;
  memberOut = 0i64;
  v5 = result;
  hkClass::retrieveMember(this, result, memberIndex, (const void **)&defaultOut, &memberOut);
  if ( v5->m_enum == HK_SUCCESS )
  {
    v6 = v4->vfptr;
    v7 = hkClassMember::getSizeInBytes(memberOut);
    ((void (__fastcall *)(hkStreamWriter *, void *, _QWORD))v6[2].__vecDelDtor)(v4, defaultOut, v7);
  }
  return v5;
}

// File Line: 413
// RVA: 0xC624C0
hkResult *__fastcall hkClass::getDeclaredDefault(hkClass *this, hkResult *result, __int64 declaredIndex, hkStreamWriter *writer)
{
  hkResult *v4; // rsi
  signed int *v5; // rdx
  hkStreamWriter *v6; // r14
  __int64 v7; // rax
  const char *v9; // rdi
  hkBaseObjectVtbl *v10; // rbx
  unsigned int v11; // eax

  v4 = result;
  v5 = (signed int *)this->m_defaults;
  v6 = writer;
  if ( !v5 )
    goto LABEL_4;
  declaredIndex = (signed int)declaredIndex;
  v7 = v5[(signed int)declaredIndex];
  if ( (signed int)v7 >= 0 )
  {
    if ( (_DWORD)v7 != -2 )
    {
      v9 = (char *)v5 + v7;
      goto LABEL_8;
    }
  }
  else if ( (_DWORD)v7 != -2 )
  {
LABEL_4:
    v4->m_enum = 1;
    return v4;
  }
  v9 = s_defaultClassBuffer;
LABEL_8:
  v10 = writer->vfptr;
  v11 = hkClassMember::getSizeInBytes(&this->m_declaredMembers[declaredIndex]);
  ((void (__fastcall *)(hkStreamWriter *, const char *, _QWORD))v10[2].__vecDelDtor)(v6, v9, v11);
  v4->m_enum = 0;
  return v4;
}

// File Line: 432
// RVA: 0xC62570
hkResult *__fastcall hkClass::getDefault(hkClass *this, hkResult *result, int memberIndex, hkTypedUnion *value)
{
  hkTypedUnion *v4; // rdi
  signed int v5; // ebx
  hkResult *v6; // rsi
  hkClassMember *v7; // rbp
  unsigned __int8 v8; // al
  hkClass *v9; // rax
  void *v10; // rcx
  hkClassEnum *v11; // rbx
  int v12; // eax
  int v13; // ebp
  hkClassMember::TypeProperties *v14; // rax
  void *v15; // rdx
  hkClassMember *v17; // [rsp+30h] [rbp-18h]
  void *memberAddress; // [rsp+58h] [rbp+10h]

  v4 = value;
  v5 = 0;
  v6 = result;
  memberAddress = 0i64;
  v17 = 0i64;
  hkClass::retrieveMember(this, result, memberIndex, (const void **)&memberAddress, &v17);
  if ( v6->m_enum == HK_SUCCESS )
  {
    v7 = v17;
    v8 = v17->m_type.m_storage;
    if ( v8 == 20 )
    {
      v9 = hkClassMember::getClass(v17);
      v10 = memberAddress;
      v4->m_type.m_storage = 20;
      v4->m_elem.m_int64 = (__int64)v10;
      v4->m_elem.m_variant.m_class = v9;
    }
    else if ( v8 == 24 )
    {
      v11 = hkClassMember::getEnumClass(v17);
      v12 = hkClassMember::getEnumValue(v7, memberAddress);
      v4->m_type.m_storage = 24;
      v4->m_elem.m_int32 = v12;
      v4->m_elem.m_variant.m_class = (hkClass *)v11;
    }
    else
    {
      v13 = v8;
      v14 = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)v8);
      if ( v14->m_size > 0x40u )
      {
        v5 = 1;
      }
      else
      {
        v15 = memberAddress;
        v4->m_type.m_storage = v13;
        hkString::memCpy(&v4->m_elem, v15, v14->m_size);
      }
      v6->m_enum = v5;
    }
  }
  return v6;
}

// File Line: 458
// RVA: 0xC62650
const char *__fastcall hkClass::getDeclaredDefault(hkClass *this, int declaredIndex)
{
  signed int *v2; // r8
  __int64 v3; // rcx

  v2 = (signed int *)this->m_defaults;
  if ( !v2 )
    return 0i64;
  v3 = v2[declaredIndex];
  if ( (signed int)v3 < 0 )
  {
    if ( (_DWORD)v3 != -2 )
      return 0i64;
    return s_defaultClassBuffer;
  }
  if ( (_DWORD)v3 == -2 )
    return s_defaultClassBuffer;
  return (char *)v2 + v3;
}

// File Line: 472
// RVA: 0xC62690
hkResult *__fastcall hkClass::getDeclaredDefault(hkClass *this, hkResult *result, __int64 declaredIndex, hkTypedUnion *value)
{
  hkTypedUnion *v4; // r14
  char *v5; // r9
  hkResult *v6; // rsi
  __int64 v7; // rdx
  const char *v8; // r15
  hkClassMember *v9; // rax
  hkClassMember *v10; // rbp
  unsigned __int8 v11; // al
  hkClass *v12; // rax
  __int64 v13; // rcx
  hkResult *v14; // rax
  int v15; // edi
  hkClassMember::TypeProperties *v16; // rax
  hkClassEnum *v17; // rdi
  int v18; // eax

  v4 = value;
  v5 = (char *)this->m_defaults;
  v6 = result;
  if ( v5
    && ((declaredIndex = (signed int)declaredIndex,
         v7 = *(signed int *)&v5[4 * (signed int)declaredIndex],
         (signed int)(v7 + 2147483648) < 0)
     || (_DWORD)v7 == -2) )
  {
    v8 = s_defaultClassBuffer;
    if ( (_DWORD)v7 != -2 )
      v8 = &v5[v7];
    v9 = this->m_declaredMembers;
    v10 = &v9[declaredIndex];
    v11 = v9[declaredIndex].m_type.m_storage;
    if ( v11 == 20 )
    {
      v12 = hkClassMember::getClass(v10);
      v13 = *(_QWORD *)v8;
      v4->m_elem.m_variant.m_class = v12;
      v4->m_elem.m_int64 = v13;
      v14 = v6;
      v4->m_type.m_storage = 20;
      v6->m_enum = 0;
    }
    else if ( v11 == 24 || v11 == 31 )
    {
      v17 = hkClassMember::getEnumClass(v10);
      v18 = hkClassMember::getEnumValue(v10, v8);
      v4->m_elem.m_variant.m_class = (hkClass *)v17;
      v4->m_elem.m_int32 = v18;
      v4->m_type.m_storage = 24;
      v6->m_enum = 0;
      v14 = v6;
    }
    else
    {
      v15 = v11;
      v16 = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)v11);
      if ( v16->m_size > 0x40u )
      {
        v14 = v6;
        v6->m_enum = 1;
      }
      else
      {
        v4->m_type.m_storage = v15;
        hkString::memCpy(&v4->m_elem, v8, v16->m_size);
        v14 = v6;
        v6->m_enum = 0;
      }
    }
  }
  else
  {
    v14 = v6;
    v6->m_enum = 1;
  }
  return v14;
}

// File Line: 505
// RVA: 0xC62890
void __fastcall hkClass::writeSignature(hkClass *this, hkStreamWriter *w)
{
  hkClass *v2; // rbp
  hkStreamWriter *v3; // rdi
  int i; // ebx
  signed __int64 v5; // rcx
  char *v6; // rdi
  __int64 v7; // rcx
  __int64 v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rax
  unsigned __int8 v11; // al
  __int16 v12; // si
  unsigned __int8 v13; // bl
  hkClassMember::TypeProperties *v14; // rax
  __int16 v15; // cx
  hkClass *v16; // rbx
  hkClassEnum *v17; // rax
  int v18; // eax
  bool v19; // sf
  unsigned __int8 v20; // of
  __int16 v21; // [rsp+20h] [rbp-98h]
  int v22; // [rsp+24h] [rbp-94h]
  __int64 v23; // [rsp+28h] [rbp-90h]
  hkOArchive v24; // [rsp+30h] [rbp-88h]
  __int64 v25; // [rsp+50h] [rbp-68h]
  __int64 v26; // [rsp+58h] [rbp-60h]
  char *src; // [rsp+60h] [rbp-58h]
  __int64 v28; // [rsp+80h] [rbp-38h]
  __int64 v29; // [rsp+88h] [rbp-30h]
  hkClass *v30; // [rsp+C0h] [rbp+8h]
  hkStreamWriter *wa; // [rsp+C8h] [rbp+10h]
  unsigned __int8 v32; // [rsp+D0h] [rbp+18h]
  unsigned __int8 v33; // [rsp+D8h] [rbp+20h]

  wa = w;
  v30 = this;
  v2 = this;
  v3 = w;
  hkOArchive::hkOArchive(&v24, w, 0);
  hkOArchive::write32(&v24, v2->m_numImplementedInterfaces);
  for ( i = 0; i < v2->m_numDeclaredEnums; ++i )
    hkClassEnum::writeSignature(&v2->m_declaredEnums[i], v3);
  hkOArchive::write32(&v24, v2->m_numDeclaredEnums);
  v22 = 0;
  if ( v2->m_numDeclaredMembers > 0 )
  {
    v5 = 0i64;
    v23 = 0i64;
    do
    {
      v6 = (char *)v2->m_declaredMembers + v5;
      v7 = *((_QWORD *)v6 + 3);
      v8 = *((_QWORD *)v6 + 1);
      src = *(char **)v6;
      v9 = *((_QWORD *)v6 + 2);
      v25 = v8;
      v26 = v9;
      v10 = *((_QWORD *)v6 + 4);
      v28 = v7;
      v29 = v10;
      v11 = v7;
      v33 = v7;
      if ( (_BYTE)v7 == 24 || (_BYTE)v7 == 31 )
      {
        v14 = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)BYTE1(v7));
        v8 = v25;
        v15 = v14->m_size;
        v11 = v33;
        v12 = 8 * v15 ^ WORD2(v28);
        v13 = 0;
      }
      else
      {
        v12 = WORD2(v28);
        v13 = BYTE1(v28);
      }
      v32 = v13;
      v21 = 0;
      if ( v12 & 0x400 )
      {
        v12 ^= 0x400u;
        if ( v13 )
          v21 = v13;
        v13 = v11;
        v32 = v11;
        v33 = 19;
      }
      if ( v8 && v6[24] != 20 && v6[25] != 20 )
      {
        v16 = hkClassMember::getClass((hkClassMember *)v6);
        if ( v16 )
        {
          do
          {
            hkClass::writeSignature(v16, wa);
            v16 = hkClass::getParent(v16);
          }
          while ( v16 );
          v2 = v30;
        }
        v13 = v32;
      }
      if ( v26 )
      {
        v17 = hkClassMember::getEnumClass((hkClassMember *)v6);
        hkClassEnum::writeSignature(v17, wa);
      }
      v18 = hkString::strLen(src);
      hkOArchive::writeRaw(&v24, src, v18);
      hkOArchive::write16(&v24, v33);
      hkOArchive::write16(&v24, v13);
      if ( v21 )
        hkOArchive::write16(&v24, v21);
      hkOArchive::write16(&v24, SWORD1(v28));
      hkOArchive::write16(&v24, v12);
      v5 = v23 + 40;
      v20 = __OFSUB__(v22 + 1, v2->m_numDeclaredMembers);
      v19 = v22++ + 1 - v2->m_numDeclaredMembers < 0;
      v23 += 40i64;
    }
    while ( v19 ^ v20 );
  }
  hkOArchive::write32(&v24, v2->m_numDeclaredMembers);
  hkOArchive::~hkOArchive(&v24);
}

// File Line: 586
// RVA: 0xC62B20
hkVariant *__fastcall hkClass::getAttribute(hkClass *this, const char *id)
{
  JUMPOUT(this->m_attributes, 0i64, hkCustomAttributes::getAttribute);
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

