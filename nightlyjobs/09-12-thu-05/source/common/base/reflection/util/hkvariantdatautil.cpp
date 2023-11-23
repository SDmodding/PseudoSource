// File Line: 23
// RVA: 0xC85850
__int64 __fastcall hkVariantDataUtil::calcElementSize(hkClassMember::Type type, hkClass *cls)
{
  if ( type == 25 )
    return hkClass::getObjectSize(cls);
  else
    return (unsigned int)hkClassMember::getClassMemberTypeProperties(type)->m_size;
}

// File Line: 28
// RVA: 0xC84EF0
float __fastcall hkVariantDataUtil::getReal(hkClassMember::Type type, __int16 *data)
{
  float result; // xmm0_4

  if ( type == (TYPE_NULL_CONTACT_MGR|0x8) )
    return *(float *)data;
  if ( type != 32 )
    return 0.0;
  LODWORD(result) = *data << 16;
  return result;
}

// File Line: 41
// RVA: 0xC84F20
void __fastcall hkVariantDataUtil::setReal(hkClassMember::Type type, float *data, float value)
{
  if ( type == (TYPE_NULL_CONTACT_MGR|0x8) )
  {
    *data = value;
  }
  else if ( type == 32 )
  {
    *(_WORD *)data = HIWORD(value);
  }
}

// File Line: 62
// RVA: 0xC84F50
void __fastcall hkVariantDataUtil::setHalf(hkClassMember::Type type, hkHalf *data, hkHalf value)
{
  if ( type == (TYPE_NULL_CONTACT_MGR|0x8) )
  {
    *(_DWORD *)&data->m_value = value.m_value << 16;
  }
  else if ( type == 32 )
  {
    data->m_value = value.m_value;
  }
}

// File Line: 83
// RVA: 0xC84F70
__int64 __fastcall hkVariantDataUtil::getInt(hkClassMember::Type type, __int64 *data)
{
  __int64 result; // rax

  switch ( type )
  {
    case 1:
    case 2:
    case 3:
      result = *(char *)data;
      break;
    case 4:
      result = *(unsigned __int8 *)data;
      break;
    case 5:
      result = *(__int16 *)data;
      break;
    case 6:
      result = *(unsigned __int16 *)data;
      break;
    case 7:
      result = *(int *)data;
      break;
    case 8:
      result = *(unsigned int *)data;
      break;
    case 9:
    case 10:
    case 30:
      result = *data;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 109
// RVA: 0xC85000
__int64 __fastcall hkVariantDataUtil::getInt(hkClassMember::Type type, hkClassMember::Type subType, __int64 *data)
{
  if ( type == 24 || type == (TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR|0x18) )
    type = subType;
  return hkVariantDataUtil::getInt(type, data);
}

// File Line: 122
// RVA: 0xC85020
void __fastcall hkVariantDataUtil::setInt(hkClassMember::Type type, bool *data, _BOOL8 value)
{
  switch ( type )
  {
    case 1:
      *data = value;
      break;
    case 2:
    case 3:
    case 4:
      *data = value;
      break;
    case 5:
    case 6:
      *(_WORD *)data = value;
      break;
    case 7:
    case 8:
      *(_DWORD *)data = value;
      break;
    case 9:
    case 10:
    case 30:
      *(_QWORD *)data = value;
      break;
    default:
      return;
  }
}

// File Line: 185
// RVA: 0xC850A0
void __fastcall hkVariantDataUtil::setInt(
        hkClassMember::Type type,
        hkClassMember::Type subType,
        bool *data,
        _BOOL8 value)
{
  if ( type == 24 || type == (TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR|0x18) )
    type = subType;
  hkVariantDataUtil::setInt(type, data, value);
}

// File Line: 203
// RVA: 0xC850D0
const char *__fastcall hkVariantDataUtil::getString(hkClassMember::Type type, const void *data)
{
  if ( type == 29 )
    return *(const char **)data;
  if ( type == 33 )
    return (const char *)(*(_QWORD *)data & 0xFFFFFFFFFFFFFFFEui64);
  return 0i64;
}

// File Line: 217
// RVA: 0xC850F0
void __fastcall hkVariantDataUtil::setString(hkClassMember::Type type, hkStringPtr *data, const char *value)
{
  if ( type == 29 )
  {
    data->m_stringAndFlag = value;
  }
  else if ( type == 33 )
  {
    hkStringPtr::operator=(data, value);
  }
}

// File Line: 238
// RVA: 0xC85120
hkBool *__fastcall hkVariantDataUtil::needsConstruction(
        hkBool *result,
        hkTypeInfoRegistry *infoReg,
        hkClassMember *mem)
{
  int m_storage; // ecx
  hkBaseObjectVtbl *vfptr; // rbx
  hkClass *Class; // rax
  const char *Name; // rax
  __int64 v10; // rax

  m_storage = (unsigned __int8)mem->m_type.m_storage;
  if ( ((m_storage - 20) & 0xFFFFFFFD) == 0 )
  {
LABEL_11:
    result->m_bool = 1;
    return result;
  }
  if ( m_storage != 25 )
  {
    if ( m_storage != 28 && m_storage != 33 )
    {
      result->m_bool = 0;
      return result;
    }
    goto LABEL_11;
  }
  vfptr = infoReg->vfptr;
  Class = hkClassMember::getClass(mem);
  Name = hkClass::getName(Class);
  v10 = ((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))vfptr[3].__first_virtual_table_function__)(
          infoReg,
          Name);
  if ( v10 && (*(_QWORD *)(v10 + 24) || *(_QWORD *)(v10 + 16)) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 262
// RVA: 0xC851E0
void __fastcall hkVariantDataUtil::newInstance(hkClass *cls, void *data)
{
  unsigned int ObjectSize; // eax
  hkBool result; // [rsp+40h] [rbp+18h] BYREF

  ObjectSize = hkClass::getObjectSize(cls);
  hkString::memSet(data, 0, ObjectSize);
  if ( hkClass::hasVtable(cls, &result)->m_bool )
  {
    *((_WORD *)data + 4) = hkClass::getObjectSize(cls);
    *((_WORD *)data + 5) = 1;
  }
}

// File Line: 280
// RVA: 0xC852A0
void __fastcall hkVariantDataUtil::finishObject(hkTypeInfoRegistry *infoReg, hkClass *cls, void *data)
{
  hkBaseObjectVtbl *vfptr; // rbx
  const char *Name; // rax
  hkTypeInfo *v7; // rax

  vfptr = infoReg->vfptr;
  Name = hkClass::getName(cls);
  v7 = (hkTypeInfo *)((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))vfptr[3].__first_virtual_table_function__)(
                       infoReg,
                       Name);
  if ( v7 )
  {
    if ( v7->m_finishLoadedObjectFunction )
      hkTypeInfo::finishLoadedObject(v7, data, 1u);
  }
}

// File Line: 293
// RVA: 0xC85300
void __fastcall hkVariantDataUtil::finishObjectWithoutTracker(hkTypeInfoRegistry *infoReg, hkClass *cls, void *data)
{
  hkBaseObjectVtbl *vfptr; // rbx
  const char *Name; // rax
  hkTypeInfo *v7; // rax

  vfptr = infoReg->vfptr;
  Name = hkClass::getName(cls);
  v7 = (hkTypeInfo *)((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))vfptr[3].__first_virtual_table_function__)(
                       infoReg,
                       Name);
  if ( v7 )
  {
    if ( v7->m_finishLoadedObjectFunction )
      hkTypeInfo::finishLoadedObjectWithoutTracker(v7, data, 1u);
  }
}

// File Line: 306
// RVA: 0xC85240
void __fastcall hkVariantDataUtil::deleteInstance(hkTypeInfoRegistry *infoReg, hkClass *cls, void *data)
{
  hkBaseObjectVtbl *vfptr; // rbx
  const char *Name; // rax
  hkTypeInfo *v7; // rax

  vfptr = infoReg->vfptr;
  Name = hkClass::getName(cls);
  v7 = (hkTypeInfo *)((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))vfptr[3].__first_virtual_table_function__)(
                       infoReg,
                       Name);
  if ( v7 )
  {
    if ( v7->m_finishLoadedObjectFunction )
      hkTypeInfo::cleanupLoadedObject(v7, data);
  }
}

// File Line: 316
// RVA: 0xC85360
void __fastcall hkVariantDataUtil::newArray(
        hkTypeInfoRegistry *infoReg,
        hkClass *cls,
        char *array,
        unsigned int size,
        int stride)
{
  hkBaseObjectVtbl *vfptr; // rdi
  const char *Name; // rax
  hkTypeInfo *v11; // rsi
  __int64 v12; // rdi
  unsigned int ObjectSize; // eax

  vfptr = infoReg->vfptr;
  Name = hkClass::getName(cls);
  v11 = (hkTypeInfo *)((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))vfptr[3].__first_virtual_table_function__)(
                        infoReg,
                        Name);
  if ( v11 && (int)size > 0 )
  {
    v12 = size;
    do
    {
      ObjectSize = hkClass::getObjectSize(cls);
      hkString::memSet(array, 0, ObjectSize);
      if ( v11->m_finishLoadedObjectFunction )
        hkTypeInfo::finishLoadedObjectWithoutTracker(v11, array, 1u);
      array += stride;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 338
// RVA: 0xC854F0
void __fastcall hkVariantDataUtil::finishObjectArray(
        hkTypeInfoRegistry *infoReg,
        hkClass *cls,
        char *array,
        unsigned int size,
        int stride)
{
  hkBaseObjectVtbl *vfptr; // rdi
  const char *Name; // rax
  __int64 v10; // rax
  hkTypeInfo *v11; // rsi
  __int64 v12; // rdi

  vfptr = infoReg->vfptr;
  Name = hkClass::getName(cls);
  v10 = ((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))vfptr[3].__first_virtual_table_function__)(
          infoReg,
          Name);
  v11 = (hkTypeInfo *)v10;
  if ( v10 && *(_QWORD *)(v10 + 16) && (int)size > 0 )
  {
    v12 = size;
    do
    {
      hkTypeInfo::finishLoadedObjectWithoutTracker(v11, array, 1u);
      array += stride;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 357
// RVA: 0xC85410
void __fastcall hkVariantDataUtil::newArray(
        hkTypeInfoRegistry *infoReg,
        hkClassMember::Type type,
        hkClass *cls,
        char *array,
        int size,
        int stride)
{
  hkStringPtr *v6; // rbx
  __int64 v7; // rdi
  __int64 v8; // rcx
  __int64 v9; // rcx

  v6 = (hkStringPtr *)array;
  switch ( type )
  {
    case 20:
      if ( size > 0 )
      {
        v9 = (unsigned int)size;
        do
        {
          v6->m_stringAndFlag = 0i64;
          v6 = (hkStringPtr *)((char *)v6 + stride);
          --v9;
        }
        while ( v9 );
      }
      break;
    case 25:
      hkVariantDataUtil::newArray(infoReg, cls, array, size, stride);
      break;
    case 28:
      if ( size > 0 )
      {
        v8 = (unsigned int)size;
        do
        {
          v6[1].m_stringAndFlag = 0i64;
          v6->m_stringAndFlag = 0i64;
          v6 = (hkStringPtr *)((char *)v6 + stride);
          --v8;
        }
        while ( v8 );
      }
      break;
    default:
      if ( type == 33 && size > 0 )
      {
        v7 = (unsigned int)size;
        do
        {
          if ( v6 )
            hkStringPtr::hkStringPtr(v6);
          v6 = (hkStringPtr *)((char *)v6 + stride);
          --v7;
        }
        while ( v7 );
      }
      break;
  }
}

// File Line: 402
// RVA: 0xC85580
void __fastcall hkVariantDataUtil::deleteArray(
        hkTypeInfoRegistry *infoReg,
        hkClass *cls,
        char *array,
        unsigned int size,
        int stride)
{
  hkBaseObjectVtbl *vfptr; // rdi
  const char *Name; // rax
  __int64 v10; // rax
  hkTypeInfo *v11; // rsi
  __int64 v12; // rdi

  vfptr = infoReg->vfptr;
  Name = hkClass::getName(cls);
  v10 = ((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))vfptr[3].__first_virtual_table_function__)(
          infoReg,
          Name);
  v11 = (hkTypeInfo *)v10;
  if ( v10 && *(_QWORD *)(v10 + 16) && (int)size > 0 )
  {
    v12 = size;
    do
    {
      hkTypeInfo::cleanupLoadedObject(v11, array);
      array += stride;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 419
// RVA: 0xC85610
void __fastcall hkVariantDataUtil::deleteArray(
        hkTypeInfoRegistry *infoReg,
        hkClassMember::Type type,
        hkClass *cls,
        char *array,
        int size,
        int stride)
{
  hkStringPtr *v6; // rbx
  __int64 v7; // rdi

  v6 = (hkStringPtr *)array;
  if ( type == 25 )
  {
    hkVariantDataUtil::deleteArray(infoReg, cls, array, size, stride);
  }
  else if ( type == 33 && size > 0 )
  {
    v7 = (unsigned int)size;
    do
    {
      hkStringPtr::~hkStringPtr(v6);
      v6 = (hkStringPtr *)((char *)v6 + stride);
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 444
// RVA: 0xC85690
void __fastcall hkVariantDataUtil::clearArray(
        hkTypeInfoRegistry *infoReg,
        void *arrayIn,
        hkClassMember::Type type,
        hkClass *cls)
{
  int stride; // eax

  if ( *((_DWORD *)arrayIn + 2) )
  {
    stride = hkVariantDataUtil::calcElementSize(type, cls);
    hkVariantDataUtil::deleteArray(infoReg, type, cls, *(char **)arrayIn, *((_DWORD *)arrayIn + 2), stride);
    *((_DWORD *)arrayIn + 2) = 0;
  }
}

// File Line: 460
// RVA: 0xC85700
void *__fastcall hkVariantDataUtil::setArraySize(
        hkTypeInfoRegistry *infoReg,
        const void **arrayIn,
        hkClassMember::Type type,
        hkClass *cls,
        int size)
{
  int v5; // esi
  int v6; // edi
  void *result; // rax
  int stride; // eax
  int v13; // ebp

  v5 = *((_DWORD *)arrayIn + 2);
  v6 = size;
  if ( v5 == size )
    return (void *)*arrayIn;
  stride = hkVariantDataUtil::calcElementSize(type, cls);
  v13 = stride;
  if ( v6 >= *((_DWORD *)arrayIn + 2) )
  {
    if ( (*((_DWORD *)arrayIn + 3) & 0x3FFFFFFF) < v6 )
      hkArrayUtil::_reserve((hkResult *)&size, &hkContainerHeapAllocator::s_alloc, arrayIn, v6, stride);
    hkVariantDataUtil::newArray(infoReg, type, cls, (char *)*arrayIn + v5 * v13, v6 - v5, v13);
  }
  else
  {
    hkVariantDataUtil::deleteArray(infoReg, type, cls, (char *)*arrayIn + v6 * stride, v5 - v6, stride);
  }
  result = (void *)*arrayIn;
  *((_DWORD *)arrayIn + 2) = v6;
  return result;
}

// File Line: 492
// RVA: 0xC857F0
__int64 __fastcall hkVariantDataUtil::getArraySize(unsigned int *arrayIn)
{
  return arrayIn[2];
}

// File Line: 498
// RVA: 0xC85800
void *__fastcall hkVariantDataUtil::reserveArray(
        const void **arrayIn,
        hkClassMember::Type type,
        hkClass *cls,
        int size)
{
  int sizeElem; // eax
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  sizeElem = hkVariantDataUtil::calcElementSize(type, cls);
  hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, arrayIn, size, sizeElem);
  return (void *)*arrayIn;
}

// File Line: 508
// RVA: 0xC85880
__int64 __fastcall hkVariantDataUtil::calcNumReals(hkClassMember::Type type, unsigned int tupleSize)
{
  __int64 result; // rax

  result = tupleSize;
  if ( (int)tupleSize <= 0 )
    result = 1i64;
  switch ( type )
  {
    case 11:
    case 32:
      return result;
    case 12:
    case 13:
      result = (unsigned int)(4 * result);
      break;
    case 14:
    case 15:
    case 16:
      result = (unsigned int)(12 * result);
      break;
    case 17:
    case 18:
      result = (unsigned int)(16 * result);
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 545
// RVA: 0xC85900
void __fastcall hkVariantDataUtil::setReals(
        hkClassMember::Type type,
        unsigned int tupleSize,
        const float *src,
        char *data,
        int numRealsIn)
{
  int v8; // eax
  int v9; // edx
  __int64 v10; // rcx
  char *v11; // r8
  const float *v12; // r9
  unsigned __int64 v13; // r10
  int v14; // xmm0_4
  float v15; // xmm0_4
  char *v16; // r8
  signed __int64 v17; // r9
  unsigned __int64 v18; // r10
  int v19; // eax
  signed __int64 v20; // rbx
  char *v21; // r8
  __int64 v22; // rdx
  int v23; // eax

  v8 = hkVariantDataUtil::calcNumReals(type, tupleSize);
  v9 = numRealsIn;
  if ( numRealsIn < 0 )
    v9 = v8;
  if ( v9 <= v8 )
  {
    v10 = 0i64;
    if ( type == 32 )
    {
      if ( v9 >= 4i64 )
      {
        v11 = data + 4;
        v12 = src + 2;
        v13 = ((unsigned __int64)(v9 - 4i64) >> 2) + 1;
        v10 = 4 * v13;
        do
        {
          v14 = *((_DWORD *)v12 - 2);
          v11 += 8;
          v12 += 4;
          *((_WORD *)v11 - 6) = HIWORD(v14);
          *((_WORD *)v11 - 5) = HIWORD(*((_DWORD *)v12 - 5));
          *((_WORD *)v11 - 4) = HIWORD(*((_DWORD *)v12 - 4));
          *((_WORD *)v11 - 3) = HIWORD(*((_DWORD *)v12 - 3));
          --v13;
        }
        while ( v13 );
      }
      for ( ; v10 < v9; *(_WORD *)&data[2 * v10 - 2] = HIWORD(v15) )
        v15 = src[v10++];
    }
    else
    {
      if ( v9 >= 4i64 )
      {
        v16 = data + 4;
        v17 = (char *)src - data;
        v18 = ((unsigned __int64)(v9 - 4i64) >> 2) + 1;
        v10 = 4 * v18;
        do
        {
          v19 = *(_DWORD *)&v16[v17 - 4];
          v16 += 16;
          *((_DWORD *)v16 - 5) = v19;
          *((_DWORD *)v16 - 4) = *(_DWORD *)&v16[v17 - 16];
          *((_DWORD *)v16 - 3) = *(_DWORD *)&v16[v17 - 12];
          *((_DWORD *)v16 - 2) = *(_DWORD *)&v16[v17 - 8];
          --v18;
        }
        while ( v18 );
      }
      if ( v10 < v9 )
      {
        v20 = (char *)src - data;
        v21 = &data[4 * v10];
        v22 = v9 - v10;
        do
        {
          v23 = *(_DWORD *)&v21[v20];
          v21 += 4;
          *((_DWORD *)v21 - 1) = v23;
          --v22;
        }
        while ( v22 );
      }
    }
  }
}

// File Line: 572
// RVA: 0xC85AA0
const float *__fastcall hkVariantDataUtil::getReals(
        hkClassMember::Type type,
        unsigned int tupleSize,
        char *data,
        hkArray<unsigned char,hkContainerHeapAllocator> *buffer)
{
  int v7; // eax
  __int64 v8; // rbp
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  char *m_data; // r11
  __int64 v15; // rdx
  char *v16; // rcx
  char *v17; // r8
  unsigned __int64 v18; // r9
  int v19; // eax
  int v20; // ecx
  hkResult result; // [rsp+30h] [rbp-18h] BYREF

  v7 = hkVariantDataUtil::calcNumReals(type, tupleSize);
  v8 = v7;
  if ( v7 <= 0 )
    return 0i64;
  if ( type != 32 )
    return (const float *)data;
  v10 = 4 * v7;
  v11 = buffer->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < 4 * (int)v8 )
  {
    v12 = 2 * v11;
    v13 = 4 * v8;
    if ( v10 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&buffer->m_data, v13, 1);
  }
  m_data = buffer->m_data;
  v15 = 0i64;
  buffer->m_size = v10;
  if ( v8 >= 4 )
  {
    v16 = m_data + 8;
    v17 = data + 4;
    v18 = ((unsigned __int64)(v8 - 4) >> 2) + 1;
    v15 = 4 * v18;
    do
    {
      v19 = *((__int16 *)v17 - 2);
      v16 += 16;
      v17 += 8;
      *((_DWORD *)v16 - 6) = v19 << 16;
      *((_DWORD *)v16 - 5) = *((__int16 *)v17 - 5) << 16;
      *((_DWORD *)v16 - 4) = *((__int16 *)v17 - 4) << 16;
      *((_DWORD *)v16 - 3) = *((__int16 *)v17 - 3) << 16;
      --v18;
    }
    while ( v18 );
  }
  for ( ; v15 < v8; *(_DWORD *)&m_data[4 * v15 - 4] = v20 << 16 )
    v20 = *(__int16 *)&data[2 * v15++];
  return (const float *)m_data;
}

// File Line: 597
// RVA: 0xC85BC0
void __fastcall hkVariantDataUtil::setObject(hkVariant *var, hkClassMember::Type type, hkVariant *data)
{
  if ( type == 20 )
  {
    data->m_object = var->m_object;
  }
  else if ( type == 28 )
  {
    *data = *var;
  }
}

// File Line: 625
// RVA: 0xC85C90
hkClass *__fastcall hkVariantDataUtil::findMostDerivedClass(
        const void *object,
        hkVtableClassRegistry *vtable,
        hkClassNameRegistry *classReg)
{
  hkClass *result; // rax
  hkBaseObjectVtbl *vfptr; // rbx
  const char *Name; // rax

  result = (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, const void *))vtable->vfptr[2].__first_virtual_table_function__)(
                        vtable,
                        object);
  if ( result )
  {
    vfptr = classReg->vfptr;
    Name = hkClass::getName(result);
    return (hkClass *)vfptr[2].__vecDelDtor(classReg, (unsigned int)Name);
  }
  return result;
}

// File Line: 635
// RVA: 0xC85CE0
hkVariant *__fastcall hkVariantDataUtil::getVariantWithMostDerivedClass(
        hkVariant *result,
        hkClass *klass,
        const void *object,
        hkVtableClassRegistry *vtable,
        hkClassNameRegistry *classReg)
{
  void *v5; // rsi
  hkClass *v10; // rbp
  hkClass *MostDerivedClass; // rax
  const char *Name; // rbx
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkOstream *v16; // rax
  hkErrStream v18; // [rsp+20h] [rbp-238h] BYREF
  char buf[512]; // [rsp+40h] [rbp-218h] BYREF
  hkBool v20; // [rsp+260h] [rbp+8h] BYREF

  v5 = 0i64;
  v10 = 0i64;
  if ( !klass || !object )
    goto LABEL_9;
  if ( !hkClass::hasVtable(klass, &v20)->m_bool )
  {
    v10 = klass;
    goto LABEL_8;
  }
  MostDerivedClass = hkVariantDataUtil::findMostDerivedClass(object, vtable, classReg);
  if ( MostDerivedClass )
  {
    v10 = MostDerivedClass;
LABEL_8:
    v5 = (void *)object;
LABEL_9:
    result->m_object = v5;
    result->m_class = v10;
    return result;
  }
  hkErrStream::hkErrStream(&v18, buf, 512);
  Name = hkClass::getName(klass);
  v13 = hkOstream::operator<<(&v18, "Could not find the most derived class for virtual object ");
  v14 = hkOstream::operator<<(v13, Name);
  v15 = hkOstream::operator<<(v14, " at ");
  v16 = hkOstream::operator<<(v15, object);
  hkOstream::operator<<(v16, ". The object is replaced with HK_NULL.");
  hkError::messageWarning(0x3476D70Fu, buf, "Reflection\\Util\\hkVariantDataUtil.cpp", 652);
  hkOstream::~hkOstream(&v18);
  result->m_object = 0i64;
  result->m_class = 0i64;
  return result;
}

// File Line: 666
// RVA: 0xC85BF0
hkVariant *__fastcall hkVariantDataUtil::getObject(
        hkVariant *result,
        hkClassMember::Type type,
        hkClass *cls,
        hkVtableClassRegistry *vtableReg,
        hkClassNameRegistry *classReg,
        const void **data)
{
  hkVariant *v8; // rax
  const void *v9; // r8
  hkVariant *p_resulta; // rcx
  hkVariant *VariantWithMostDerivedClass; // rax
  void *m_object; // rcx
  hkClass *m_class; // rax
  char v14; // [rsp+30h] [rbp-28h] BYREF
  hkVariant resulta; // [rsp+40h] [rbp-18h] BYREF

  switch ( type )
  {
    case 20:
      p_resulta = &resulta;
      v9 = *data;
      goto LABEL_8;
    case 25:
      v9 = data;
      p_resulta = (hkVariant *)&v14;
LABEL_8:
      VariantWithMostDerivedClass = hkVariantDataUtil::getVariantWithMostDerivedClass(
                                      p_resulta,
                                      cls,
                                      v9,
                                      vtableReg,
                                      classReg);
      m_object = VariantWithMostDerivedClass->m_object;
      m_class = VariantWithMostDerivedClass->m_class;
      result->m_object = m_object;
      result->m_class = m_class;
      return result;
    case 28:
      *result = *(hkVariant *)data;
      return result;
    default:
      v8 = result;
      result->m_object = 0i64;
      result->m_class = 0i64;
      break;
  }
  return v8;
}

// File Line: 693
// RVA: 0xC85E20
void __fastcall hkVariantDataUtil::setPointer(
        hkClass *cls,
        hkReferencedObject *obj,
        hkReferencedObject **dst,
        hkBool isReferenced)
{
  hkBool result; // [rsp+38h] [rbp+10h] BYREF
  char m_bool; // [rsp+48h] [rbp+20h]

  m_bool = isReferenced.m_bool;
  if ( hkClass::hasVtable(cls, &result)->m_bool && m_bool )
  {
    if ( obj )
      hkReferencedObject::addReference(obj);
    if ( *dst )
      hkReferencedObject::removeReference(*dst);
  }
  *dst = obj;
}

// File Line: 713
// RVA: 0xC85E80
unsigned __int64 __fastcall hkVariantDataUtil::calcBasicElementSize(hkClassMember::Type type, hkClass *klass)
{
  if ( type == 25 )
    return (int)hkClass::getObjectSize(klass);
  else
    return hkClassMember::getClassMemberTypeProperties(type)->m_size;
}

// File Line: 730
// RVA: 0xC85EB0
unsigned __int64 __fastcall hkVariantDataUtil::calcElementSize(
        hkClassMember::Type type,
        hkClassMember::Type subType,
        hkClass *klass,
        int tupleSize)
{
  __int64 v4; // rbx
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rcx

  v4 = tupleSize;
  if ( type == (TYPE_USER_CONTACT_MGR|TYPE_CONVEX_LIST_CONTACT_MGR|0x10) )
    return 16i64;
  if ( type == 24 || type == (TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR|0x18) )
    type = subType;
  v5 = hkVariantDataUtil::calcBasicElementSize(type, klass);
  v6 = v5;
  if ( (int)v4 > 0 )
    return v4 * v5;
  return v6;
}

// File Line: 760
// RVA: 0xC85F00
void __fastcall hkVariantDataUtil::convertTypeToInt32Array(
        hkClassMember::Type srcType,
        hkBool *srcIn,
        int *dst,
        int size)
{
  __int64 i; // rax
  int m_bool; // ecx
  __int64 j; // rax
  int v7; // ecx
  __int64 k; // rax
  int v9; // ecx
  __int64 m; // rax
  int v11; // ecx
  __int64 n; // rax
  int v13; // ecx

  switch ( srcType )
  {
    case 1:
      hkVariantDataUtil::convertBoolToTypeArray(srcIn, TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR, dst, size);
      break;
    case 2:
      for ( i = 0i64; i < size; dst[i - 1] = m_bool )
        m_bool = srcIn[i++].m_bool;
      break;
    case 3:
      for ( j = 0i64; j < size; dst[j - 1] = v7 )
        v7 = srcIn[j++].m_bool;
      break;
    case 4:
      for ( k = 0i64; k < size; dst[k - 1] = v9 )
        v9 = (unsigned __int8)srcIn[k++].m_bool;
      break;
    case 5:
      for ( m = 0i64; m < size; dst[m - 1] = v11 )
        v11 = *(__int16 *)&srcIn[2 * m++].m_bool;
      break;
    case 6:
      for ( n = 0i64; n < size; dst[n - 1] = v13 )
        v13 = *(unsigned __int16 *)&srcIn[2 * n++].m_bool;
      break;
    case 7:
    case 8:
      hkString::memCpy(dst, srcIn, 4 * size);
      break;
    case 9:
    case 10:
      hkVariantDataUtil::convertInt64ToTypeArray(
        (const __int64 *)&srcIn->m_bool,
        TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR,
        dst,
        size);
      break;
    default:
      return;
  }
}

// File Line: 804
// RVA: 0xC86050
void __fastcall hkVariantDataUtil::convertInt32ToTypeArray(
        const int *src,
        hkClassMember::Type dstType,
        hkBool *dstIn,
        int size)
{
  __int64 i; // rax
  char v6; // cl
  __int64 j; // rax
  char v8; // cl
  __int64 k; // rax
  char v10; // cl
  __int64 m; // rax
  __int16 v12; // cx
  __int64 n; // rax
  __int16 v14; // cx
  __int64 ii; // rax
  __int64 v16; // rcx
  __int64 jj; // rax
  __int64 v18; // rcx

  switch ( dstType )
  {
    case 1:
      hkVariantDataUtil::convertTypeToBoolArray(TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR, src, dstIn, size);
      break;
    case 2:
      for ( i = 0i64; i < size; dstIn[i - 1].m_bool = v6 )
        v6 = src[i++];
      break;
    case 3:
      for ( j = 0i64; j < size; dstIn[j - 1].m_bool = v8 )
        v8 = src[j++];
      break;
    case 4:
      for ( k = 0i64; k < size; dstIn[k - 1].m_bool = v10 )
        v10 = src[k++];
      break;
    case 5:
      for ( m = 0i64; m < size; *(_WORD *)&dstIn[2 * m - 2].m_bool = v12 )
        v12 = src[m++];
      break;
    case 6:
      for ( n = 0i64; n < size; *(_WORD *)&dstIn[2 * n - 2].m_bool = v14 )
        v14 = src[n++];
      break;
    case 7:
    case 8:
      hkString::memCpy(dstIn, src, 4 * size);
      break;
    case 9:
      for ( ii = 0i64; ii < size; *(_QWORD *)&dstIn[8 * ii - 8].m_bool = v16 )
        v16 = src[ii++];
      break;
    case 10:
      for ( jj = 0i64; jj < size; *(_QWORD *)&dstIn[8 * jj - 8].m_bool = v18 )
        v18 = src[jj++];
      break;
    default:
      return;
  }
}

// File Line: 844
// RVA: 0xC861F0
void __fastcall hkVariantDataUtil::convertUint32ToTypeArray(
        const unsigned int *src,
        hkClassMember::Type dstType,
        hkBool *dstIn,
        int size)
{
  __int64 i; // rax
  char v6; // cl
  __int64 j; // rax
  char v8; // cl
  __int64 k; // rax
  char v10; // cl
  __int64 m; // rax
  __int16 v12; // cx
  __int64 n; // rax
  __int16 v14; // cx
  __int64 ii; // rax
  __int64 v16; // rcx
  __int64 jj; // rax
  __int64 v18; // rcx

  switch ( dstType )
  {
    case 1:
      hkVariantDataUtil::convertTypeToBoolArray((hkClassMember::Type)8, src, dstIn, size);
      break;
    case 2:
      for ( i = 0i64; i < size; dstIn[i - 1].m_bool = v6 )
        v6 = src[i++];
      break;
    case 3:
      for ( j = 0i64; j < size; dstIn[j - 1].m_bool = v8 )
        v8 = src[j++];
      break;
    case 4:
      for ( k = 0i64; k < size; dstIn[k - 1].m_bool = v10 )
        v10 = src[k++];
      break;
    case 5:
      for ( m = 0i64; m < size; *(_WORD *)&dstIn[2 * m - 2].m_bool = v12 )
        v12 = src[m++];
      break;
    case 6:
      for ( n = 0i64; n < size; *(_WORD *)&dstIn[2 * n - 2].m_bool = v14 )
        v14 = src[n++];
      break;
    case 7:
    case 8:
      hkString::memCpy(dstIn, src, 4 * size);
      break;
    case 9:
      for ( ii = 0i64; ii < size; *(_QWORD *)&dstIn[8 * ii - 8].m_bool = v16 )
        v16 = src[ii++];
      break;
    case 10:
      for ( jj = 0i64; jj < size; *(_QWORD *)&dstIn[8 * jj - 8].m_bool = v18 )
        v18 = src[jj++];
      break;
    default:
      return;
  }
}

// File Line: 884
// RVA: 0xC86530
void __fastcall hkVariantDataUtil::convertTypeToBoolArray(
        hkClassMember::Type srcType,
        char *srcIn,
        hkBool *dst,
        unsigned int size)
{
  __int64 v4; // rsi
  hkBool *v5; // rbx
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax
  __int64 v8; // rdx
  __int64 v9; // rax
  bool v10; // cl
  __int64 v11; // rax
  bool v12; // cl
  __int64 v13; // rax
  bool v14; // cl
  char *v15; // rdi
  bool v16; // zf

  v4 = (int)size;
  v5 = dst;
  if ( srcType == TYPE_REPORT_CONTACT_MGR )
  {
    hkString::memCpy(dst, srcIn, size);
  }
  else
  {
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(srcType);
    v8 = v4;
    switch ( ClassMemberTypeProperties->m_size )
    {
      case 1:
        if ( (int)v4 > 0 )
        {
          v15 = (char *)(srcIn - (char *)v5);
          do
          {
            v16 = (v5++)[(_QWORD)v15].m_bool == 0;
            v5[-1].m_bool = !v16;
            --v8;
          }
          while ( v8 );
        }
        break;
      case 2:
        v13 = 0i64;
        if ( (int)v4 > 0 )
        {
          do
          {
            v14 = *(_WORD *)&srcIn[2 * v13++] != 0;
            v5[v13 - 1].m_bool = v14;
          }
          while ( v13 < v4 );
        }
        break;
      case 4:
        v11 = 0i64;
        if ( (int)v4 > 0 )
        {
          do
          {
            v12 = *(_DWORD *)&srcIn[4 * v11++] != 0;
            v5[v11 - 1].m_bool = v12;
          }
          while ( v11 < v4 );
        }
        break;
      case 8:
        v9 = 0i64;
        if ( (int)v4 > 0 )
        {
          do
          {
            v10 = *(_QWORD *)&srcIn[8 * v9++] != 0i64;
            v5[v9 - 1].m_bool = v10;
          }
          while ( v9 < v4 );
        }
        break;
    }
  }
}

// File Line: 939
// RVA: 0xC86660
void __fastcall hkVariantDataUtil::convertBoolToTypeArray(
        hkBool *src,
        hkClassMember::Type dstType,
        hkBool *dstIn,
        unsigned int size)
{
  __int64 v4; // rsi
  hkBool *v5; // rbx
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax
  __int64 v8; // rcx
  __int64 v9; // rdx
  _BOOL8 v10; // rax
  __int64 v11; // rdx
  BOOL v12; // eax
  __int64 v13; // rdx
  __int16 v14; // ax
  hkBool *v15; // rdi
  bool v16; // zf

  v4 = (int)size;
  v5 = dstIn;
  if ( dstType == TYPE_REPORT_CONTACT_MGR )
  {
    hkString::memCpy(dstIn, src, size);
  }
  else
  {
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(dstType);
    v8 = v4;
    switch ( ClassMemberTypeProperties->m_size )
    {
      case 1:
        if ( (int)v4 > 0 )
        {
          v15 = (hkBool *)(src - v5);
          do
          {
            v16 = (v5++)[(_QWORD)v15].m_bool == 0;
            v5[-1].m_bool = !v16;
            --v8;
          }
          while ( v8 );
        }
        break;
      case 2:
        v13 = 0i64;
        if ( (int)v4 > 0 )
        {
          do
          {
            v14 = src[v13++].m_bool != 0;
            *(_WORD *)&v5[2 * v13 - 2].m_bool = v14;
          }
          while ( v13 < v4 );
        }
        break;
      case 4:
        v11 = 0i64;
        if ( (int)v4 > 0 )
        {
          do
          {
            v12 = src[v11++].m_bool != 0;
            *(_DWORD *)&v5[4 * v11 - 4].m_bool = v12;
          }
          while ( v11 < v4 );
        }
        break;
      case 8:
        v9 = 0i64;
        if ( (int)v4 > 0 )
        {
          do
          {
            v10 = src[v9++].m_bool != 0;
            *(_QWORD *)&v5[8 * v9 - 8].m_bool = v10;
          }
          while ( v9 < v4 );
        }
        break;
    }
  }
}

// File Line: 993
// RVA: 0xC86390
void __fastcall hkVariantDataUtil::convertInt64ToTypeArray(
        const __int64 *src,
        hkClassMember::Type dstType,
        hkBool *dstIn,
        int size)
{
  __int64 i; // rax
  char v6; // cl
  __int64 j; // rax
  char v8; // cl
  __int64 k; // rax
  char v10; // cl
  __int64 m; // rax
  __int16 v12; // cx
  __int64 n; // rax
  __int16 v14; // cx
  __int64 ii; // rax
  int v16; // ecx
  __int64 jj; // rax
  int v18; // ecx

  switch ( dstType )
  {
    case 1:
      hkVariantDataUtil::convertTypeToBoolArray((hkClassMember::Type)9, src, dstIn, size);
      break;
    case 2:
      for ( i = 0i64; i < size; dstIn[i - 1].m_bool = v6 )
        v6 = src[i++];
      break;
    case 3:
      for ( j = 0i64; j < size; dstIn[j - 1].m_bool = v8 )
        v8 = src[j++];
      break;
    case 4:
      for ( k = 0i64; k < size; dstIn[k - 1].m_bool = v10 )
        v10 = src[k++];
      break;
    case 5:
      for ( m = 0i64; m < size; *(_WORD *)&dstIn[2 * m - 2].m_bool = v12 )
        v12 = src[m++];
      break;
    case 6:
      for ( n = 0i64; n < size; *(_WORD *)&dstIn[2 * n - 2].m_bool = v14 )
        v14 = src[n++];
      break;
    case 7:
      for ( ii = 0i64; ii < size; *(_DWORD *)&dstIn[4 * ii - 4].m_bool = v16 )
        v16 = src[ii++];
      break;
    case 8:
      for ( jj = 0i64; jj < size; *(_DWORD *)&dstIn[4 * jj - 4].m_bool = v18 )
        v18 = src[jj++];
      break;
    case 9:
    case 10:
      hkString::memCpy(dstIn, src, 8 * size);
      break;
    default:
      return;
  }
}

// File Line: 1033
// RVA: 0xC86790
void __fastcall hkVariantDataUtil::convertTypeToTypeArray(
        hkClassMember::Type srcType,
        hkBool *src,
        hkClassMember::Type dstType,
        hkBool *dst,
        int size)
{
  hkBool *v5; // rdi
  hkBool *v7; // rsi
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax
  int v10; // ebp
  hkClassMember::TypeProperties *v11; // rbx
  __int16 m_size; // cx
  __int16 v13; // ax
  int v14; // eax
  int v15; // ecx
  __int64 v16; // r13
  __int64 v17; // r12
  int v18; // ebx
  __int64 v19; // rcx
  hkBool *v20; // rdx
  hkBool *v21; // r8
  unsigned __int64 v22; // r9
  int v23; // eax
  int v24; // eax
  __int64 v25; // rcx
  hkBool *v26; // rdx
  hkBool *v27; // r8
  unsigned __int64 v28; // r9
  int v29; // xmm0_4
  int v30; // xmm0_4
  int dsta[74]; // [rsp+20h] [rbp-128h] BYREF

  v5 = dst;
  v7 = src;
  if ( srcType == dstType )
  {
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(srcType);
    hkString::memCpy(v5, v7, size * ClassMemberTypeProperties->m_size);
  }
  else
  {
    v10 = size;
    switch ( srcType )
    {
      case 1:
        hkVariantDataUtil::convertBoolToTypeArray(src, dstType, dst, size);
        break;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        if ( dstType == TYPE_REPORT_CONTACT_MGR )
        {
          hkVariantDataUtil::convertTypeToBoolArray(srcType, &src->m_bool, dst, size);
        }
        else
        {
          v11 = hkClassMember::getClassMemberTypeProperties(srcType);
          m_size = hkClassMember::getClassMemberTypeProperties(dstType)->m_size;
          v13 = v11->m_size;
          if ( v13 == m_size )
          {
            hkString::memCpy(v5, v7, size * v13);
          }
          else
          {
            v14 = v13 << 6;
            v15 = m_size << 6;
            if ( size > 0 )
            {
              v16 = v15;
              v17 = v14;
              do
              {
                v18 = 64;
                if ( v10 <= 64 )
                  v18 = v10;
                hkVariantDataUtil::convertTypeToInt32Array(srcType, v7, dsta, v18);
                hkVariantDataUtil::convertInt32ToTypeArray(dsta, dstType, v5, v18);
                v10 -= v18;
                v7 += v17;
                v5 += v16;
              }
              while ( v10 > 0 );
            }
          }
        }
        break;
      case 7:
        hkVariantDataUtil::convertInt32ToTypeArray((const int *)&src->m_bool, dstType, dst, size);
        break;
      case 8:
        hkVariantDataUtil::convertUint32ToTypeArray((const unsigned int *)src, dstType, dst, size);
        break;
      case 9:
      case 10:
        hkVariantDataUtil::convertInt64ToTypeArray((const __int64 *)&src->m_bool, dstType, dst, size);
        break;
      case 11:
        if ( dstType == 32 )
        {
          v25 = 0i64;
          if ( size >= 4i64 )
          {
            v26 = dst + 4;
            v27 = v7 + 8;
            v28 = ((unsigned __int64)(size - 4i64) >> 2) + 1;
            v25 = 4 * v28;
            do
            {
              v29 = *(_DWORD *)&v27[-8].m_bool;
              v26 += 8;
              v27 += 16;
              *(_WORD *)&v26[-12].m_bool = HIWORD(v29);
              *(_WORD *)&v26[-10].m_bool = HIWORD(*(_DWORD *)&v27[-20].m_bool);
              *(_WORD *)&v26[-8].m_bool = HIWORD(*(_DWORD *)&v27[-16].m_bool);
              *(_WORD *)&v26[-6].m_bool = HIWORD(*(_DWORD *)&v27[-12].m_bool);
              --v28;
            }
            while ( v28 );
          }
          for ( ; v25 < size; *(_WORD *)&v5[2 * v25 - 2].m_bool = HIWORD(v30) )
            v30 = *(_DWORD *)&v7[4 * v25++].m_bool;
        }
        break;
      case 32:
        if ( dstType == (TYPE_NULL_CONTACT_MGR|0x8) )
        {
          v19 = 0i64;
          if ( size >= 4i64 )
          {
            v20 = dst + 8;
            v21 = v7 + 4;
            v22 = ((unsigned __int64)(size - 4i64) >> 2) + 1;
            v19 = 4 * v22;
            do
            {
              v23 = *(__int16 *)&v21[-4].m_bool;
              v20 += 16;
              v21 += 8;
              *(_DWORD *)&v20[-24].m_bool = v23 << 16;
              *(_DWORD *)&v20[-20].m_bool = *(__int16 *)&v21[-10].m_bool << 16;
              *(_DWORD *)&v20[-16].m_bool = *(__int16 *)&v21[-8].m_bool << 16;
              *(_DWORD *)&v20[-12].m_bool = *(__int16 *)&v21[-6].m_bool << 16;
              --v22;
            }
            while ( v22 );
          }
          for ( ; v19 < size; *(_DWORD *)&v5[4 * v19 - 4].m_bool = v24 << 16 )
            v24 = *(__int16 *)&v7[2 * v19++].m_bool;
        }
        break;
      default:
        return;
    }
  }
}

// File Line: 1139
// RVA: 0xC86B10
void __fastcall hkVariantDataUtil::stridedCopy(
        char *src,
        int srcStride,
        _BYTE *dst,
        int dstStride,
        int eleSize,
        int size)
{
  _BYTE *v6; // rbx
  char *v7; // rdi
  __int64 v8; // rax
  __int128 v9; // xmm0
  __int64 v10; // rcx
  __int64 v11; // rax
  __int64 v12; // rcx
  int v13; // eax
  __int64 v14; // r15
  __int64 v15; // r14
  __int64 v16; // rbp
  __int64 v17; // rcx
  __int16 v18; // ax
  __int64 v19; // rcx
  char v20; // al

  v6 = dst;
  v7 = src;
  if ( eleSize == srcStride && eleSize == dstStride )
  {
    hkString::memCpy(dst, src, size * eleSize);
    return;
  }
  switch ( eleSize )
  {
    case 1:
      if ( size > 0 )
      {
        v19 = (unsigned int)size;
        do
        {
          v20 = *v7;
          v7 += srcStride;
          *v6 = v20;
          v6 += dstStride;
          --v19;
        }
        while ( v19 );
      }
      break;
    case 2:
      if ( (((unsigned __int8)dst | (unsigned __int8)((unsigned __int8)src | srcStride | dstStride)) & 1) != 0 )
        goto LABEL_24;
      if ( size > 0 )
      {
        v17 = (unsigned int)size;
        do
        {
          v18 = *(_WORD *)v7;
          v7 += srcStride;
          *(_WORD *)v6 = v18;
          v6 += dstStride;
          --v17;
        }
        while ( v17 );
      }
      break;
    case 4:
      if ( (((unsigned __int8)dst | (unsigned __int8)((unsigned __int8)src | srcStride | dstStride)) & 3) != 0 )
        goto LABEL_24;
      if ( size > 0 )
      {
        v12 = (unsigned int)size;
        do
        {
          v13 = *(_DWORD *)v7;
          v7 += srcStride;
          *(_DWORD *)v6 = v13;
          v6 += dstStride;
          --v12;
        }
        while ( v12 );
      }
      break;
    case 8:
      if ( (((unsigned __int8)dst | (unsigned __int8)((unsigned __int8)src | srcStride | dstStride)) & 7) == 0 )
      {
        if ( size > 0 )
        {
          v10 = (unsigned int)size;
          do
          {
            v11 = *(_QWORD *)v7;
            v7 += srcStride;
            *(_QWORD *)v6 = v11;
            v6 += dstStride;
            --v10;
          }
          while ( v10 );
        }
        return;
      }
LABEL_24:
      if ( size > 0 )
      {
        v14 = dstStride;
        v15 = srcStride;
        v16 = (unsigned int)size;
        do
        {
          hkString::memCpy(v6, v7, eleSize);
          v7 += v15;
          v6 += v14;
          --v16;
        }
        while ( v16 );
      }
      return;
    default:
      if ( eleSize == 16
        && (((unsigned __int8)dst | (unsigned __int8)((unsigned __int8)src | srcStride | dstStride)) & 0xF) == 0 )
      {
        v8 = (unsigned int)size;
        if ( size > 0 )
        {
          do
          {
            v9 = *(_OWORD *)v7;
            v7 += srcStride;
            *(_OWORD *)v6 = v9;
            v6 += dstStride;
            --v8;
          }
          while ( v8 );
        }
        return;
      }
      goto LABEL_24;
  }
}

// File Line: 1251
// RVA: 0xC86D00
void __fastcall hkVariantDataUtil::convertArray(hkStridedBasicArray *src, hkStridedBasicArray *dst)
{
  hkClassMember::Type m_type; // ecx
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax
  hkClassMember::TypeProperties *v6; // rbx
  hkClassMember::TypeProperties *v7; // rax
  int m_tupleSize; // ecx
  int m_size; // r14d
  int m_stride; // eax
  int eleSize; // r14d
  int v12; // ebp
  hkBool *v13; // r8
  int v14; // ebx
  hkBool *m_data; // rdx
  hkClassMember::Type v16; // ecx
  int v17; // eax
  hkBool *v18; // r9
  hkClassMember::Type v19; // r8d
  int v20; // ebx
  int v21; // edx
  char *v22; // rcx
  int size; // [rsp+28h] [rbp-30h]
  hkBool *array; // [rsp+30h] [rbp-28h] BYREF
  int v25; // [rsp+38h] [rbp-20h]
  int v26; // [rsp+3Ch] [rbp-1Ch]
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  if ( src->m_size > 0 )
  {
    m_type = src->m_type;
    if ( m_type == dst->m_type && src->m_tupleSize == dst->m_tupleSize )
    {
      ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(m_type);
      hkVariantDataUtil::stridedCopy(
        (char *)src->m_data,
        src->m_stride,
        (_BYTE *)dst->m_data,
        dst->m_stride,
        src->m_tupleSize * ClassMemberTypeProperties->m_size,
        src->m_size);
    }
    else
    {
      v6 = hkClassMember::getClassMemberTypeProperties(m_type);
      v7 = hkClassMember::getClassMemberTypeProperties(dst->m_type);
      m_tupleSize = src->m_tupleSize;
      m_size = v7->m_size;
      m_stride = src->m_stride;
      eleSize = dst->m_tupleSize * m_size;
      v12 = m_tupleSize * v6->m_size;
      if ( v12 == m_stride && eleSize == dst->m_stride )
      {
        hkVariantDataUtil::convertTypeToTypeArray(
          src->m_type,
          (hkBool *)src->m_data,
          dst->m_type,
          (hkBool *)dst->m_data,
          src->m_size * m_tupleSize);
      }
      else
      {
        v26 = 0x80000000;
        v13 = 0i64;
        array = 0i64;
        v25 = 0;
        if ( v12 == m_stride )
        {
          v14 = src->m_size * eleSize;
          if ( v14 > 0 )
          {
            hkArrayUtil::_reserve(
              &result,
              &hkContainerTempAllocator::s_alloc,
              (const void **)&array,
              src->m_size * eleSize,
              1);
            v13 = array;
          }
          m_data = (hkBool *)src->m_data;
          v16 = src->m_type;
          v17 = src->m_size * src->m_tupleSize;
          v18 = v13;
          v19 = dst->m_type;
          v25 = v14;
          hkVariantDataUtil::convertTypeToTypeArray(v16, m_data, v19, v18, v17);
          hkVariantDataUtil::stridedCopy(
            &array->m_bool,
            eleSize,
            (_BYTE *)dst->m_data,
            dst->m_stride,
            eleSize,
            src->m_size);
        }
        else
        {
          v20 = src->m_size * v12;
          if ( v20 > 0 )
          {
            hkArrayUtil::_reserve(
              &result,
              &hkContainerTempAllocator::s_alloc,
              (const void **)&array,
              src->m_size * v12,
              1);
            v13 = array;
          }
          v21 = src->m_stride;
          v22 = (char *)src->m_data;
          size = src->m_size;
          v25 = v20;
          hkVariantDataUtil::stridedCopy(v22, v21, v13, v12, v12, size);
          hkVariantDataUtil::convertTypeToTypeArray(
            src->m_type,
            array,
            dst->m_type,
            (hkBool *)dst->m_data,
            src->m_size * src->m_tupleSize);
        }
        v25 = 0;
        if ( v26 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, v26 & 0x3FFFFFFF);
      }
    }
  }
}

