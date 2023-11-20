// File Line: 23
// RVA: 0xC85850
__int64 __fastcall hkVariantDataUtil::calcElementSize(hkClassMember::Type type, hkClass *cls)
{
  __int64 result; // rax

  if ( type == 25 )
    result = hkClass::getObjectSize(cls);
  else
    result = (unsigned int)hkClassMember::getClassMemberTypeProperties(type)->m_size;
  return result;
}

// File Line: 28
// RVA: 0xC84EF0
float __fastcall hkVariantDataUtil::getReal(hkClassMember::Type type, const void *data)
{
  float result; // xmm0_4

  if ( type == 11 )
    return *(float *)data;
  if ( type != 32 )
    return 0.0;
  LODWORD(result) = *(signed __int16 *)data << 16;
  return result;
}

// File Line: 41
// RVA: 0xC84F20
void __fastcall hkVariantDataUtil::setReal(hkClassMember::Type type, void *data, float value)
{
  if ( type == 11 )
  {
    *(float *)data = value;
  }
  else if ( type == 32 )
  {
    *(_WORD *)data = HIWORD(value);
  }
}

// File Line: 62
// RVA: 0xC84F50
void __fastcall hkVariantDataUtil::setHalf(hkClassMember::Type type, void *data, hkHalf value)
{
  if ( type == 11 )
  {
    *(_DWORD *)data = value.m_value << 16;
  }
  else if ( type == 32 )
  {
    *(hkHalf *)data = value;
  }
}

// File Line: 83
// RVA: 0xC84F70
__int64 __fastcall hkVariantDataUtil::getInt(hkClassMember::Type type, const void *data)
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
      result = *(signed __int16 *)data;
      break;
    case 6:
      result = *(unsigned __int16 *)data;
      break;
    case 7:
      result = *(signed int *)data;
      break;
    case 8:
      result = *(unsigned int *)data;
      break;
    case 9:
    case 10:
    case 30:
      result = *(_QWORD *)data;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 109
// RVA: 0xC85000
__int64 __fastcall hkVariantDataUtil::getInt(hkClassMember::Type type, hkClassMember::Type subType, const void *data)
{
  if ( type == 24 || type == 31 )
    type = subType;
  return hkVariantDataUtil::getInt(type, data);
}

// File Line: 122
// RVA: 0xC85020
void __fastcall hkVariantDataUtil::setInt(hkClassMember::Type type, void *data, __int64 value)
{
  switch ( type )
  {
    case 1:
      *(_BYTE *)data = value != 0;
      break;
    case 2:
    case 3:
    case 4:
      *(_BYTE *)data = value;
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
void __fastcall hkVariantDataUtil::setInt(hkClassMember::Type type, hkClassMember::Type subType, void *data, __int64 value)
{
  if ( type == 24 || type == 31 )
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
void __fastcall hkVariantDataUtil::setString(hkClassMember::Type type, void *data, const char *value)
{
  if ( type == 29 )
  {
    *(_QWORD *)data = value;
  }
  else if ( type == 33 )
  {
    hkStringPtr::operator=((hkStringPtr *)data, value);
  }
}

// File Line: 238
// RVA: 0xC85120
hkBool *__fastcall hkVariantDataUtil::needsConstruction(hkBool *result, hkTypeInfoRegistry *infoReg, hkClassMember *mem)
{
  hkBool *v3; // rdi
  int v4; // ecx
  hkTypeInfoRegistry *v5; // rsi
  hkBool *v6; // rax
  hkBaseObjectVtbl *v7; // rbx
  hkClass *v8; // rax
  const char *v9; // rax
  __int64 v10; // rax

  v3 = result;
  v4 = (unsigned __int8)mem->m_type.m_storage;
  v5 = infoReg;
  if ( !((v4 - 20) & 0xFFFFFFFD) )
  {
LABEL_11:
    v3->m_bool = 1;
    return v3;
  }
  if ( v4 != 25 )
  {
    if ( v4 != 28 && v4 != 33 )
    {
      v3->m_bool = 0;
      return v3;
    }
    goto LABEL_11;
  }
  v7 = infoReg->vfptr;
  v8 = hkClassMember::getClass(mem);
  v9 = hkClass::getName(v8);
  v10 = ((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))v7[3].__first_virtual_table_function__)(v5, v9);
  if ( v10 && (*(_QWORD *)(v10 + 24) || *(_QWORD *)(v10 + 16)) )
  {
    v3->m_bool = 1;
    v6 = v3;
  }
  else
  {
    v3->m_bool = 0;
    v6 = v3;
  }
  return v6;
}

// File Line: 262
// RVA: 0xC851E0
void __fastcall hkVariantDataUtil::newInstance(hkClass *cls, void *data)
{
  _WORD *v2; // rbx
  hkClass *v3; // rdi
  int v4; // eax
  hkBool result; // [rsp+40h] [rbp+18h]

  v2 = data;
  v3 = cls;
  v4 = hkClass::getObjectSize(cls);
  hkString::memSet(v2, 0, v4);
  if ( hkClass::hasVtable(v3, &result)->m_bool )
  {
    v2[4] = hkClass::getObjectSize(v3);
    v2[5] = 1;
  }
}

// File Line: 280
// RVA: 0xC852A0
void __fastcall hkVariantDataUtil::finishObject(hkTypeInfoRegistry *infoReg, hkClass *cls, void *data)
{
  hkBaseObjectVtbl *v3; // rbx
  hkTypeInfoRegistry *v4; // rdi
  void *v5; // rsi
  const char *v6; // rax
  hkTypeInfo *v7; // rax

  v3 = infoReg->vfptr;
  v4 = infoReg;
  v5 = data;
  v6 = hkClass::getName(cls);
  v7 = (hkTypeInfo *)((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))v3[3].__first_virtual_table_function__)(
                       v4,
                       v6);
  if ( v7 )
  {
    if ( v7->m_finishLoadedObjectFunction )
      hkTypeInfo::finishLoadedObject(v7, v5, 1);
  }
}

// File Line: 293
// RVA: 0xC85300
void __fastcall hkVariantDataUtil::finishObjectWithoutTracker(hkTypeInfoRegistry *infoReg, hkClass *cls, void *data)
{
  hkBaseObjectVtbl *v3; // rbx
  hkTypeInfoRegistry *v4; // rdi
  void *v5; // rsi
  const char *v6; // rax
  hkTypeInfo *v7; // rax

  v3 = infoReg->vfptr;
  v4 = infoReg;
  v5 = data;
  v6 = hkClass::getName(cls);
  v7 = (hkTypeInfo *)((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))v3[3].__first_virtual_table_function__)(
                       v4,
                       v6);
  if ( v7 )
  {
    if ( v7->m_finishLoadedObjectFunction )
      hkTypeInfo::finishLoadedObjectWithoutTracker(v7, v5, 1);
  }
}

// File Line: 306
// RVA: 0xC85240
void __fastcall hkVariantDataUtil::deleteInstance(hkTypeInfoRegistry *infoReg, hkClass *cls, void *data)
{
  hkBaseObjectVtbl *v3; // rbx
  hkTypeInfoRegistry *v4; // rdi
  void *v5; // rsi
  const char *v6; // rax
  hkTypeInfo *v7; // rax

  v3 = infoReg->vfptr;
  v4 = infoReg;
  v5 = data;
  v6 = hkClass::getName(cls);
  v7 = (hkTypeInfo *)((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))v3[3].__first_virtual_table_function__)(
                       v4,
                       v6);
  if ( v7 )
  {
    if ( v7->m_finishLoadedObjectFunction )
      hkTypeInfo::cleanupLoadedObject(v7, v5);
  }
}

// File Line: 316
// RVA: 0xC85360
void __fastcall hkVariantDataUtil::newArray(hkTypeInfoRegistry *infoReg, hkClass *cls, void *array, int size, int stride)
{
  hkBaseObjectVtbl *v5; // rdi
  hkTypeInfoRegistry *v6; // rsi
  int v7; // er14
  char *v8; // rbx
  hkClass *v9; // r15
  const char *v10; // rax
  hkTypeInfo *v11; // rsi
  __int64 v12; // rdi
  int v13; // eax

  v5 = infoReg->vfptr;
  v6 = infoReg;
  v7 = size;
  v8 = (char *)array;
  v9 = cls;
  v10 = hkClass::getName(cls);
  v11 = (hkTypeInfo *)((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))v5[3].__first_virtual_table_function__)(
                        v6,
                        v10);
  if ( v11 && v7 > 0 )
  {
    v12 = (unsigned int)v7;
    do
    {
      v13 = hkClass::getObjectSize(v9);
      hkString::memSet(v8, 0, v13);
      if ( v11->m_finishLoadedObjectFunction )
        hkTypeInfo::finishLoadedObjectWithoutTracker(v11, v8, 1);
      v8 += stride;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 338
// RVA: 0xC854F0
void __fastcall hkVariantDataUtil::finishObjectArray(hkTypeInfoRegistry *infoReg, hkClass *cls, void *array, int size, int stride)
{
  hkBaseObjectVtbl *v5; // rdi
  hkTypeInfoRegistry *v6; // rsi
  int v7; // er14
  char *v8; // rbx
  const char *v9; // rax
  __int64 v10; // rax
  hkTypeInfo *v11; // rsi
  __int64 v12; // rdi

  v5 = infoReg->vfptr;
  v6 = infoReg;
  v7 = size;
  v8 = (char *)array;
  v9 = hkClass::getName(cls);
  v10 = ((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))v5[3].__first_virtual_table_function__)(v6, v9);
  v11 = (hkTypeInfo *)v10;
  if ( v10 && *(_QWORD *)(v10 + 16) && v7 > 0 )
  {
    v12 = (unsigned int)v7;
    do
    {
      hkTypeInfo::finishLoadedObjectWithoutTracker(v11, v8, 1);
      v8 += stride;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 357
// RVA: 0xC85410
void __fastcall hkVariantDataUtil::newArray(hkTypeInfoRegistry *infoReg, hkClassMember::Type type, hkClass *cls, void *array, int size, int stride)
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
void __fastcall hkVariantDataUtil::deleteArray(hkTypeInfoRegistry *infoReg, hkClass *cls, void *array, int size, int stride)
{
  hkBaseObjectVtbl *v5; // rdi
  hkTypeInfoRegistry *v6; // rsi
  int v7; // er14
  char *v8; // rbx
  const char *v9; // rax
  __int64 v10; // rax
  hkTypeInfo *v11; // rsi
  __int64 v12; // rdi

  v5 = infoReg->vfptr;
  v6 = infoReg;
  v7 = size;
  v8 = (char *)array;
  v9 = hkClass::getName(cls);
  v10 = ((__int64 (__fastcall *)(hkTypeInfoRegistry *, const char *))v5[3].__first_virtual_table_function__)(v6, v9);
  v11 = (hkTypeInfo *)v10;
  if ( v10 && *(_QWORD *)(v10 + 16) && v7 > 0 )
  {
    v12 = (unsigned int)v7;
    do
    {
      hkTypeInfo::cleanupLoadedObject(v11, v8);
      v8 += stride;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 419
// RVA: 0xC85610
void __fastcall hkVariantDataUtil::deleteArray(hkTypeInfoRegistry *infoReg, hkClassMember::Type type, hkClass *cls, void *array, int size, int stride)
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
void __fastcall hkVariantDataUtil::clearArray(hkTypeInfoRegistry *infoReg, void *arrayIn, hkClassMember::Type type, hkClass *cls)
{
  hkClass *v4; // rdi
  hkClassMember::Type v5; // esi
  void *v6; // rbx
  hkTypeInfoRegistry *v7; // rbp
  int stride; // eax

  v4 = cls;
  v5 = type;
  v6 = arrayIn;
  v7 = infoReg;
  if ( *((_DWORD *)arrayIn + 2) )
  {
    stride = hkVariantDataUtil::calcElementSize(type, cls);
    hkVariantDataUtil::deleteArray(v7, v5, v4, *(void **)v6, *((_DWORD *)v6 + 2), stride);
    *((_DWORD *)v6 + 2) = 0;
  }
}

// File Line: 460
// RVA: 0xC85700
void *__fastcall hkVariantDataUtil::setArraySize(hkTypeInfoRegistry *infoReg, void *arrayIn, hkClassMember::Type type, hkClass *cls, int size)
{
  int v5; // esi
  int v6; // edi
  hkClass *v7; // r14
  hkClassMember::Type v8; // er15
  _DWORD *v9; // rbx
  hkTypeInfoRegistry *v10; // r12
  void *result; // rax
  int stride; // eax
  int v13; // ebp

  v5 = *((_DWORD *)arrayIn + 2);
  v6 = size;
  v7 = cls;
  v8 = type;
  v9 = arrayIn;
  v10 = infoReg;
  if ( v5 == size )
    return *(void **)arrayIn;
  stride = hkVariantDataUtil::calcElementSize(type, cls);
  v13 = stride;
  if ( v6 >= v9[2] )
  {
    if ( (v9[3] & 0x3FFFFFFF) < v6 )
      hkArrayUtil::_reserve(
        (hkResult *)&size,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v9,
        v6,
        stride);
    hkVariantDataUtil::newArray(v10, v8, v7, (void *)(*(_QWORD *)v9 + v5 * v13), v6 - v5, v13);
  }
  else
  {
    hkVariantDataUtil::deleteArray(v10, v8, v7, (void *)(*(_QWORD *)v9 + v6 * stride), v5 - v6, stride);
  }
  result = *(void **)v9;
  v9[2] = v6;
  return result;
}

// File Line: 492
// RVA: 0xC857F0
__int64 __fastcall hkVariantDataUtil::getArraySize(void *arrayIn)
{
  return *((unsigned int *)arrayIn + 2);
}

// File Line: 498
// RVA: 0xC85800
void *__fastcall hkVariantDataUtil::reserveArray(void *arrayIn, hkClassMember::Type type, hkClass *cls, int size)
{
  void *v4; // rdi
  int v5; // ebx
  int sizeElem; // eax
  hkResult result; // [rsp+40h] [rbp+8h]

  v4 = arrayIn;
  v5 = size;
  sizeElem = hkVariantDataUtil::calcElementSize(type, cls);
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v5, sizeElem);
  return *(void **)v4;
}

// File Line: 508
// RVA: 0xC85880
signed __int64 __fastcall hkVariantDataUtil::calcNumReals(hkClassMember::Type type, int tupleSize)
{
  signed __int64 result; // rax

  result = (unsigned int)tupleSize;
  if ( tupleSize <= 0 )
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
void __fastcall hkVariantDataUtil::setReals(hkClassMember::Type type, int tupleSize, const float *src, void *data, int numRealsIn)
{
  char *v5; // rdi
  const float *v6; // rbx
  hkClassMember::Type v7; // esi
  signed int v8; // eax
  signed __int64 v9; // rdx
  signed __int64 v10; // rcx
  signed __int64 v11; // r8
  signed __int64 v12; // r9
  unsigned __int64 v13; // r10
  int v14; // xmm0_4
  float v15; // xmm0_4
  signed __int64 v16; // r8
  signed __int64 v17; // r9
  unsigned __int64 v18; // r10
  int v19; // eax
  signed __int64 v20; // rbx
  signed __int64 v21; // r8
  signed __int64 v22; // rdx
  int v23; // eax

  v5 = (char *)data;
  v6 = src;
  v7 = type;
  v8 = hkVariantDataUtil::calcNumReals(type, tupleSize);
  LODWORD(v9) = numRealsIn;
  if ( numRealsIn < 0 )
    LODWORD(v9) = v8;
  if ( (signed int)v9 <= v8 )
  {
    v10 = 0i64;
    v9 = (signed int)v9;
    if ( v7 == 32 )
    {
      if ( v9 >= 4 )
      {
        v11 = (signed __int64)(v5 + 4);
        v12 = (signed __int64)(v6 + 2);
        v13 = ((unsigned __int64)(v9 - 4) >> 2) + 1;
        v10 = 4 * v13;
        do
        {
          v14 = *(_DWORD *)(v12 - 8);
          v11 += 8i64;
          v12 += 16i64;
          *(_WORD *)(v11 - 12) = HIWORD(v14);
          *(_WORD *)(v11 - 10) = *(_DWORD *)(v12 - 20) >> 16;
          *(_WORD *)(v11 - 8) = *(_DWORD *)(v12 - 16) >> 16;
          *(_WORD *)(v11 - 6) = *(_DWORD *)(v12 - 12) >> 16;
          --v13;
        }
        while ( v13 );
      }
      for ( ; v10 < v9; *(_WORD *)&v5[2 * v10 - 2] = HIWORD(v15) )
        v15 = v6[v10++];
    }
    else
    {
      if ( v9 >= 4 )
      {
        v16 = (signed __int64)(v5 + 4);
        v17 = (char *)v6 - v5;
        v18 = ((unsigned __int64)(v9 - 4) >> 2) + 1;
        v10 = 4 * v18;
        do
        {
          v19 = *(_DWORD *)(v16 + v17 - 4);
          v16 += 16i64;
          *(_DWORD *)(v16 - 20) = v19;
          *(_DWORD *)(v16 - 16) = *(_DWORD *)(v17 + v16 - 16);
          *(_DWORD *)(v16 - 12) = *(_DWORD *)(v17 + v16 - 12);
          *(_DWORD *)(v16 - 8) = *(_DWORD *)(v16 + v17 - 8);
          --v18;
        }
        while ( v18 );
      }
      if ( v10 < v9 )
      {
        v20 = (char *)v6 - v5;
        v21 = (signed __int64)&v5[4 * v10];
        v22 = v9 - v10;
        do
        {
          v23 = *(_DWORD *)(v20 + v21);
          v21 += 4i64;
          *(_DWORD *)(v21 - 4) = v23;
          --v22;
        }
        while ( v22 );
      }
    }
  }
}

// File Line: 572
// RVA: 0xC85AA0
const float *__fastcall hkVariantDataUtil::getReals(hkClassMember::Type type, int tupleSize, const void *data, hkArray<unsigned char,hkContainerHeapAllocator> *buffer)
{
  hkArray<unsigned char,hkContainerHeapAllocator> *v4; // rsi
  char *v5; // rbx
  hkClassMember::Type v6; // edi
  int v7; // eax
  signed __int64 v8; // rbp
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // er9
  char *v14; // r11
  signed __int64 v15; // rdx
  signed __int64 v16; // rcx
  signed __int64 v17; // r8
  unsigned __int64 v18; // r9
  int v19; // eax
  int v20; // ecx
  hkResult result; // [rsp+30h] [rbp-18h]

  v4 = buffer;
  v5 = (char *)data;
  v6 = type;
  v7 = hkVariantDataUtil::calcNumReals(type, tupleSize);
  v8 = v7;
  if ( v7 <= 0 )
    return 0i64;
  if ( v6 != 32 )
    return (const float *)v5;
  v10 = 4 * v8;
  v11 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < 4 * (signed int)v8 )
  {
    v12 = 2 * v11;
    v13 = 4 * v8;
    if ( v10 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v13, 1);
  }
  v14 = v4->m_data;
  v15 = 0i64;
  v4->m_size = v10;
  if ( v8 >= 4 )
  {
    v16 = (signed __int64)(v14 + 8);
    v17 = (signed __int64)(v5 + 4);
    v18 = ((unsigned __int64)(v8 - 4) >> 2) + 1;
    v15 = 4 * v18;
    do
    {
      v19 = *(signed __int16 *)(v17 - 4);
      v16 += 16i64;
      v17 += 8i64;
      *(_DWORD *)(v16 - 24) = v19 << 16;
      *(_DWORD *)(v16 - 20) = *(signed __int16 *)(v17 - 10) << 16;
      *(_DWORD *)(v16 - 16) = *(signed __int16 *)(v17 - 8) << 16;
      *(_DWORD *)(v16 - 12) = *(signed __int16 *)(v17 - 6) << 16;
      --v18;
    }
    while ( v18 );
  }
  for ( ; v15 < v8; *(_DWORD *)&v14[4 * v15 - 4] = v20 << 16 )
    v20 = *(signed __int16 *)&v5[2 * v15++];
  return (const float *)v14;
}

// File Line: 597
// RVA: 0xC85BC0
void __fastcall hkVariantDataUtil::setObject(hkVariant *var, hkClassMember::Type type, void *data)
{
  if ( type == 20 )
  {
    *(_QWORD *)data = var->m_object;
  }
  else if ( type == 28 )
  {
    *(hkVariant *)data = *var;
  }
}

// File Line: 625
// RVA: 0xC85C90
hkClass *__fastcall hkVariantDataUtil::findMostDerivedClass(const void *object, hkVtableClassRegistry *vtable, hkClassNameRegistry *classReg)
{
  hkClassNameRegistry *v3; // rdi
  hkClass *result; // rax
  hkBaseObjectVtbl *v5; // rbx
  const char *v6; // rax

  v3 = classReg;
  result = (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, const void *))vtable->vfptr[2].__first_virtual_table_function__)(
                        vtable,
                        object);
  if ( result )
  {
    v5 = v3->vfptr;
    v6 = hkClass::getName(result);
    result = (hkClass *)v5[2].__vecDelDtor((hkBaseObject *)&v3->vfptr, (unsigned int)v6);
  }
  return result;
}

// File Line: 635
// RVA: 0xC85CE0
hkVariant *__fastcall hkVariantDataUtil::getVariantWithMostDerivedClass(hkVariant *result, hkClass *klass, const void *object, hkVtableClassRegistry *vtable, hkClassNameRegistry *classReg)
{
  void *v5; // rsi
  hkVtableClassRegistry *v6; // r15
  const void *v7; // rdi
  hkClass *v8; // rbx
  hkVariant *v9; // r14
  hkClass *v10; // rbp
  hkClass *v11; // rax
  const char *v12; // rbx
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkOstream *v16; // rax
  hkErrStream v18; // [rsp+20h] [rbp-238h]
  char buf; // [rsp+40h] [rbp-218h]
  __int64 v20; // [rsp+260h] [rbp+8h]

  v5 = 0i64;
  v6 = vtable;
  v7 = object;
  v8 = klass;
  v9 = result;
  v10 = 0i64;
  if ( !klass || !object )
    goto LABEL_9;
  if ( !hkClass::hasVtable(klass, (hkBool *)&v20)->m_bool )
  {
    v10 = v8;
    goto LABEL_8;
  }
  v11 = hkVariantDataUtil::findMostDerivedClass(v7, v6, classReg);
  if ( v11 )
  {
    v10 = v11;
LABEL_8:
    v5 = (void *)v7;
LABEL_9:
    v9->m_object = v5;
    v9->m_class = v10;
    return v9;
  }
  hkErrStream::hkErrStream(&v18, &buf, 512);
  v12 = hkClass::getName(v8);
  v13 = hkOstream::operator<<((hkOstream *)&v18.vfptr, "Could not find the most derived class for virtual object ");
  v14 = hkOstream::operator<<(v13, v12);
  v15 = hkOstream::operator<<(v14, " at ");
  v16 = hkOstream::operator<<(v15, v7, (int)v15);
  hkOstream::operator<<(v16, ". The object is replaced with HK_NULL.");
  hkError::messageWarning(880203535, &buf, "Reflection\\Util\\hkVariantDataUtil.cpp", 652);
  hkOstream::~hkOstream((hkOstream *)&v18.vfptr);
  v9->m_object = 0i64;
  v9->m_class = 0i64;
  return v9;
}

// File Line: 666
// RVA: 0xC85BF0
hkVariant *__fastcall hkVariantDataUtil::getObject(hkVariant *result, hkClassMember::Type type, hkClass *cls, hkVtableClassRegistry *vtableReg, hkClassNameRegistry *classReg, const void *data)
{
  hkClass *v6; // r10
  hkVariant *v7; // rbx
  hkVariant *v8; // rax
  void *v9; // r8
  hkVariant *v10; // rcx
  hkVariant *v11; // rax
  void *v12; // rcx
  hkClass *v13; // rax
  char v14; // [rsp+30h] [rbp-28h]
  hkVariant resulta; // [rsp+40h] [rbp-18h]

  v6 = cls;
  v7 = result;
  switch ( type )
  {
    case 20:
      v10 = &resulta;
      v9 = *(void **)data;
      goto LABEL_8;
    case 25:
      v9 = (void *)data;
      v10 = (hkVariant *)&v14;
LABEL_8:
      v11 = hkVariantDataUtil::getVariantWithMostDerivedClass(v10, v6, v9, vtableReg, classReg);
      v12 = v11->m_object;
      v13 = v11->m_class;
      v7->m_object = v12;
      v7->m_class = v13;
      return v7;
    case 28:
      result->m_object = *(void **)data;
      result->m_class = (hkClass *)*((_QWORD *)data + 1);
      v8 = result;
      break;
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
void __fastcall hkVariantDataUtil::setPointer(hkClass *cls, void *obj, void **dst, hkBool isReferenced)
{
  hkReferencedObject *v4; // rbx
  void **v5; // rdi
  hkBool result; // [rsp+38h] [rbp+10h]
  char v7; // [rsp+48h] [rbp+20h]

  v7 = isReferenced.m_bool;
  v4 = (hkReferencedObject *)obj;
  v5 = dst;
  if ( hkClass::hasVtable(cls, &result)->m_bool && v7 )
  {
    if ( v4 )
      hkReferencedObject::addReference(v4);
    if ( *v5 )
      hkReferencedObject::removeReference((hkReferencedObject *)*v5);
  }
  *v5 = v4;
}

// File Line: 713
// RVA: 0xC85E80
unsigned __int64 __fastcall hkVariantDataUtil::calcBasicElementSize(hkClassMember::Type type, hkClass *klass)
{
  unsigned __int64 result; // rax

  if ( type == 25 )
    result = (signed int)hkClass::getObjectSize(klass);
  else
    result = hkClassMember::getClassMemberTypeProperties(type)->m_size;
  return result;
}

// File Line: 730
// RVA: 0xC85EB0
unsigned __int64 __fastcall hkVariantDataUtil::calcElementSize(hkClassMember::Type type, hkClassMember::Type subType, hkClass *klass, int tupleSize)
{
  __int64 v4; // rbx
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rcx

  v4 = tupleSize;
  if ( type == 22 )
    return 16i64;
  if ( type == 24 || type == 31 )
    type = subType;
  v5 = hkVariantDataUtil::calcBasicElementSize(type, klass);
  v6 = v5;
  if ( (signed int)v4 > 0 )
    v6 = v4 * v5;
  return v6;
}

// File Line: 760
// RVA: 0xC85F00
void __fastcall hkVariantDataUtil::convertTypeToInt32Array(hkClassMember::Type srcType, const void *srcIn, int *dst, int size)
{
  signed __int64 v4; // rax
  int v5; // ecx
  signed __int64 v6; // rax
  int v7; // ecx
  signed __int64 v8; // rax
  int v9; // ecx
  signed __int64 v10; // rax
  int v11; // ecx
  signed __int64 v12; // rax
  int v13; // ecx

  switch ( srcType )
  {
    case 1:
      hkVariantDataUtil::convertBoolToTypeArray((hkBool *)srcIn, TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR, dst, size);
      break;
    case 2:
      v4 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v5 = *((char *)srcIn + v4++);
          dst[v4 - 1] = v5;
        }
        while ( v4 < size );
      }
      break;
    case 3:
      v6 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v7 = *((char *)srcIn + v6++);
          dst[v6 - 1] = v7;
        }
        while ( v6 < size );
      }
      break;
    case 4:
      v8 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v9 = *((unsigned __int8 *)srcIn + v8++);
          dst[v8 - 1] = v9;
        }
        while ( v8 < size );
      }
      break;
    case 5:
      v10 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v11 = *((signed __int16 *)srcIn + v10++);
          dst[v10 - 1] = v11;
        }
        while ( v10 < size );
      }
      break;
    case 6:
      v12 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v13 = *((unsigned __int16 *)srcIn + v12++);
          dst[v12 - 1] = v13;
        }
        while ( v12 < size );
      }
      break;
    case 7:
    case 8:
      hkString::memCpy(dst, srcIn, 4 * size);
      break;
    case 9:
    case 10:
      hkVariantDataUtil::convertInt64ToTypeArray(
        (const __int64 *)srcIn,
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
void __fastcall hkVariantDataUtil::convertInt32ToTypeArray(const int *src, hkClassMember::Type dstType, void *dstIn, int size)
{
  const int *v4; // rbx
  signed __int64 v5; // rax
  char v6; // cl
  signed __int64 v7; // rax
  char v8; // cl
  signed __int64 v9; // rax
  char v10; // cl
  signed __int64 v11; // rax
  __int16 v12; // cx
  signed __int64 v13; // rax
  __int16 v14; // cx
  signed __int64 v15; // rax
  __int64 v16; // rcx
  signed __int64 v17; // rax
  __int64 v18; // rcx

  v4 = src;
  switch ( dstType )
  {
    case 1:
      hkVariantDataUtil::convertTypeToBoolArray(TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR, src, (hkBool *)dstIn, size);
      break;
    case 2:
      v5 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v6 = v4[v5++];
          *((char *)dstIn + v5 - 1) = v6;
        }
        while ( v5 < size );
      }
      break;
    case 3:
      v7 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v8 = v4[v7++];
          *((char *)dstIn + v7 - 1) = v8;
        }
        while ( v7 < size );
      }
      break;
    case 4:
      v9 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v10 = v4[v9++];
          *((char *)dstIn + v9 - 1) = v10;
        }
        while ( v9 < size );
      }
      break;
    case 5:
      v11 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v12 = v4[v11++];
          *((_WORD *)dstIn + v11 - 1) = v12;
        }
        while ( v11 < size );
      }
      break;
    case 6:
      v13 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v14 = v4[v13++];
          *((_WORD *)dstIn + v13 - 1) = v14;
        }
        while ( v13 < size );
      }
      break;
    case 7:
    case 8:
      hkString::memCpy(dstIn, src, 4 * size);
      break;
    case 9:
      v15 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v16 = v4[v15++];
          *((_QWORD *)dstIn + v15 - 1) = v16;
        }
        while ( v15 < size );
      }
      break;
    case 10:
      v17 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v18 = v4[v17++];
          *((_QWORD *)dstIn + v17 - 1) = v18;
        }
        while ( v17 < size );
      }
      break;
    default:
      return;
  }
}

// File Line: 844
// RVA: 0xC861F0
void __fastcall hkVariantDataUtil::convertUint32ToTypeArray(const unsigned int *src, hkClassMember::Type dstType, void *dstIn, int size)
{
  const unsigned int *v4; // rbx
  signed __int64 v5; // rax
  char v6; // cl
  signed __int64 v7; // rax
  char v8; // cl
  signed __int64 v9; // rax
  char v10; // cl
  signed __int64 v11; // rax
  __int16 v12; // cx
  signed __int64 v13; // rax
  __int16 v14; // cx
  signed __int64 v15; // rax
  __int64 v16; // rcx
  signed __int64 v17; // rax
  __int64 v18; // rcx

  v4 = src;
  switch ( dstType )
  {
    case 1:
      hkVariantDataUtil::convertTypeToBoolArray((hkClassMember::Type)8, src, (hkBool *)dstIn, size);
      break;
    case 2:
      v5 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v6 = v4[v5++];
          *((char *)dstIn + v5 - 1) = v6;
        }
        while ( v5 < size );
      }
      break;
    case 3:
      v7 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v8 = v4[v7++];
          *((char *)dstIn + v7 - 1) = v8;
        }
        while ( v7 < size );
      }
      break;
    case 4:
      v9 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v10 = v4[v9++];
          *((char *)dstIn + v9 - 1) = v10;
        }
        while ( v9 < size );
      }
      break;
    case 5:
      v11 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v12 = v4[v11++];
          *((_WORD *)dstIn + v11 - 1) = v12;
        }
        while ( v11 < size );
      }
      break;
    case 6:
      v13 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v14 = v4[v13++];
          *((_WORD *)dstIn + v13 - 1) = v14;
        }
        while ( v13 < size );
      }
      break;
    case 7:
    case 8:
      hkString::memCpy(dstIn, src, 4 * size);
      break;
    case 9:
      v15 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v16 = v4[v15++];
          *((_QWORD *)dstIn + v15 - 1) = v16;
        }
        while ( v15 < size );
      }
      break;
    case 10:
      v17 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v18 = v4[v17++];
          *((_QWORD *)dstIn + v17 - 1) = v18;
        }
        while ( v17 < size );
      }
      break;
    default:
      return;
  }
}

// File Line: 884
// RVA: 0xC86530
void __fastcall hkVariantDataUtil::convertTypeToBoolArray(hkClassMember::Type srcType, const void *srcIn, hkBool *dst, int size)
{
  __int64 v4; // rsi
  hkBool *v5; // rbx
  _BYTE *v6; // rdi
  hkClassMember::TypeProperties *v7; // rax
  __int64 v8; // rdx
  __int64 v9; // rax
  bool v10; // cl
  __int64 v11; // rax
  bool v12; // cl
  __int64 v13; // rax
  bool v14; // cl
  signed __int64 v15; // rdi
  bool v16; // zf

  v4 = size;
  v5 = dst;
  v6 = srcIn;
  if ( srcType == 1 )
  {
    hkString::memCpy(dst, srcIn, size);
  }
  else
  {
    v7 = hkClassMember::getClassMemberTypeProperties(srcType);
    v8 = v4;
    switch ( v7->m_size )
    {
      case 1:
        if ( (signed int)v4 > 0 )
        {
          v15 = v6 - (_BYTE *)v5;
          do
          {
            v16 = (v5++)[v15].m_bool == 0;
            v5[-1].m_bool = !v16;
            --v8;
          }
          while ( v8 );
        }
        break;
      case 2:
        v13 = 0i64;
        if ( (signed int)v4 > 0 )
        {
          do
          {
            v14 = *(_WORD *)&v6[2 * v13++] != 0;
            v5[v13 - 1].m_bool = v14;
          }
          while ( v13 < v4 );
        }
        break;
      case 4:
        v11 = 0i64;
        if ( (signed int)v4 > 0 )
        {
          do
          {
            v12 = *(_DWORD *)&v6[4 * v11++] != 0;
            v5[v11 - 1].m_bool = v12;
          }
          while ( v11 < v4 );
        }
        break;
      case 8:
        v9 = 0i64;
        if ( (signed int)v4 > 0 )
        {
          do
          {
            v10 = *(_QWORD *)&v6[8 * v9++] != 0i64;
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
void __fastcall hkVariantDataUtil::convertBoolToTypeArray(hkBool *src, hkClassMember::Type dstType, void *dstIn, int size)
{
  __int64 v4; // rsi
  hkBool *v5; // rbx
  hkBool *v6; // rdi
  hkClassMember::TypeProperties *v7; // rax
  __int64 v8; // rcx
  __int64 v9; // rdx
  _BOOL8 v10; // rax
  __int64 v11; // rdx
  BOOL v12; // eax
  __int64 v13; // rdx
  __int16 v14; // ax
  signed __int64 v15; // rdi
  bool v16; // zf

  v4 = size;
  v5 = (hkBool *)dstIn;
  v6 = src;
  if ( dstType == 1 )
  {
    hkString::memCpy(dstIn, src, size);
  }
  else
  {
    v7 = hkClassMember::getClassMemberTypeProperties(dstType);
    v8 = v4;
    switch ( v7->m_size )
    {
      case 1:
        if ( (signed int)v4 > 0 )
        {
          v15 = v6 - v5;
          do
          {
            v16 = (v5++)[v15].m_bool == 0;
            v5[-1].m_bool = !v16;
            --v8;
          }
          while ( v8 );
        }
        break;
      case 2:
        v13 = 0i64;
        if ( (signed int)v4 > 0 )
        {
          do
          {
            v14 = v6[v13++].m_bool != 0;
            *(_WORD *)&v5[2 * v13 - 2].m_bool = v14;
          }
          while ( v13 < v4 );
        }
        break;
      case 4:
        v11 = 0i64;
        if ( (signed int)v4 > 0 )
        {
          do
          {
            v12 = v6[v11++].m_bool != 0;
            *(_DWORD *)&v5[4 * v11 - 4].m_bool = v12;
          }
          while ( v11 < v4 );
        }
        break;
      case 8:
        v9 = 0i64;
        if ( (signed int)v4 > 0 )
        {
          do
          {
            v10 = v6[v9++].m_bool != 0;
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
void __fastcall hkVariantDataUtil::convertInt64ToTypeArray(const __int64 *src, hkClassMember::Type dstType, void *dstIn, int size)
{
  const __int64 *v4; // rbx
  signed __int64 v5; // rax
  char v6; // cl
  signed __int64 v7; // rax
  char v8; // cl
  signed __int64 v9; // rax
  char v10; // cl
  signed __int64 v11; // rax
  __int16 v12; // cx
  signed __int64 v13; // rax
  __int16 v14; // cx
  signed __int64 v15; // rax
  int v16; // ecx
  signed __int64 v17; // rax
  int v18; // ecx

  v4 = src;
  switch ( dstType )
  {
    case 1:
      hkVariantDataUtil::convertTypeToBoolArray((hkClassMember::Type)9, src, (hkBool *)dstIn, size);
      break;
    case 2:
      v5 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v6 = v4[v5++];
          *((char *)dstIn + v5 - 1) = v6;
        }
        while ( v5 < size );
      }
      break;
    case 3:
      v7 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v8 = v4[v7++];
          *((char *)dstIn + v7 - 1) = v8;
        }
        while ( v7 < size );
      }
      break;
    case 4:
      v9 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v10 = v4[v9++];
          *((char *)dstIn + v9 - 1) = v10;
        }
        while ( v9 < size );
      }
      break;
    case 5:
      v11 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v12 = v4[v11++];
          *((_WORD *)dstIn + v11 - 1) = v12;
        }
        while ( v11 < size );
      }
      break;
    case 6:
      v13 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v14 = v4[v13++];
          *((_WORD *)dstIn + v13 - 1) = v14;
        }
        while ( v13 < size );
      }
      break;
    case 7:
      v15 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v16 = v4[v15++];
          *((_DWORD *)dstIn + v15 - 1) = v16;
        }
        while ( v15 < size );
      }
      break;
    case 8:
      v17 = 0i64;
      if ( size > 0 )
      {
        do
        {
          v18 = v4[v17++];
          *((_DWORD *)dstIn + v17 - 1) = v18;
        }
        while ( v17 < size );
      }
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
void __usercall hkVariantDataUtil::convertTypeToTypeArray(hkClassMember::Type srcType@<ecx>, const void *src@<rdx>, hkClassMember::Type dstType@<r8d>, void *dst@<r9>, __int64 a5@<rbp>, int size)
{
  char *v6; // rdi
  hkClassMember::Type v7; // er14
  char *v8; // rsi
  hkClassMember::Type v9; // er15
  hkClassMember::TypeProperties *v10; // rax
  int v11; // ebp
  hkClassMember::TypeProperties *v12; // rbx
  __int16 v13; // cx
  __int16 v14; // ax
  int v15; // eax
  int v16; // ecx
  __int64 v17; // r13
  __int64 v18; // r12
  int v19; // ebx
  signed __int64 v20; // rcx
  char *v21; // rdx
  signed __int64 v22; // r8
  unsigned __int64 v23; // r9
  int v24; // eax
  int v25; // eax
  signed __int64 v26; // rcx
  char *v27; // rdx
  signed __int64 v28; // r8
  unsigned __int64 v29; // r9
  int v30; // xmm0_4
  int v31; // xmm0_4
  int dsta; // [rsp+20h] [rbp-128h]
  int v33; // [rsp+150h] [rbp+8h]
  __int64 v34; // [rsp+158h] [rbp+10h]

  v6 = (char *)dst;
  v7 = dstType;
  v8 = (char *)src;
  v9 = srcType;
  if ( srcType == dstType )
  {
    v10 = hkClassMember::getClassMemberTypeProperties(srcType);
    hkString::memCpy(v6, v8, size * v10->m_size);
  }
  else
  {
    v34 = a5;
    v11 = size;
    switch ( srcType )
    {
      case 1:
        hkVariantDataUtil::convertBoolToTypeArray((hkBool *)src, dstType, dst, size);
        break;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        if ( dstType == 1 )
        {
          hkVariantDataUtil::convertTypeToBoolArray(srcType, src, (hkBool *)dst, size);
        }
        else
        {
          v12 = hkClassMember::getClassMemberTypeProperties(srcType);
          v13 = hkClassMember::getClassMemberTypeProperties(v7)->m_size;
          v14 = v12->m_size;
          if ( v14 == v13 )
          {
            hkString::memCpy(v6, v8, size * v14);
          }
          else
          {
            v15 = v14 << 6;
            v16 = v13 << 6;
            if ( size > 0 )
            {
              v17 = v16;
              v18 = v15;
              do
              {
                v19 = 64;
                if ( v11 <= 64 )
                  v19 = v11;
                hkVariantDataUtil::convertTypeToInt32Array(v9, v8, &dsta, v19);
                hkVariantDataUtil::convertInt32ToTypeArray(&dsta, v7, v6, v19);
                v11 -= v19;
                v8 += v18;
                v6 += v17;
              }
              while ( v11 > 0 );
            }
          }
        }
        break;
      case 7:
        hkVariantDataUtil::convertInt32ToTypeArray((const int *)src, dstType, dst, size);
        break;
      case 8:
        hkVariantDataUtil::convertUint32ToTypeArray((const unsigned int *)src, dstType, dst, size);
        break;
      case 9:
      case 10:
        hkVariantDataUtil::convertInt64ToTypeArray((const __int64 *)src, dstType, dst, size);
        break;
      case 11:
        if ( dstType == 32 )
        {
          v26 = 0i64;
          if ( size >= 4i64 )
          {
            v27 = (char *)dst + 4;
            v28 = (signed __int64)(v8 + 8);
            v29 = ((unsigned __int64)(size - 4i64) >> 2) + 1;
            v26 = 4 * v29;
            do
            {
              v30 = *(_DWORD *)(v28 - 8);
              v27 += 8;
              v28 += 16i64;
              *((_WORD *)v27 - 6) = HIWORD(v30);
              *((_WORD *)v27 - 5) = *(_DWORD *)(v28 - 20) >> 16;
              *((_WORD *)v27 - 4) = *(_DWORD *)(v28 - 16) >> 16;
              *((_WORD *)v27 - 3) = *(_DWORD *)(v28 - 12) >> 16;
              --v29;
            }
            while ( v29 );
          }
          for ( ; v26 < size; *(_WORD *)&v6[2 * v26 - 2] = HIWORD(v31) )
          {
            v31 = *(_DWORD *)&v8[4 * v26++];
            v33 = v31;
          }
        }
        break;
      case 32:
        if ( dstType == 11 )
        {
          v20 = 0i64;
          if ( size >= 4i64 )
          {
            v21 = (char *)dst + 8;
            v22 = (signed __int64)(v8 + 4);
            v23 = ((unsigned __int64)(size - 4i64) >> 2) + 1;
            v20 = 4 * v23;
            do
            {
              v24 = *(signed __int16 *)(v22 - 4);
              v21 += 16;
              v22 += 8i64;
              *((_DWORD *)v21 - 6) = v24 << 16;
              *((_DWORD *)v21 - 5) = *(signed __int16 *)(v22 - 10) << 16;
              *((_DWORD *)v21 - 4) = *(signed __int16 *)(v22 - 8) << 16;
              *((_DWORD *)v21 - 3) = *(signed __int16 *)(v22 - 6) << 16;
              --v23;
            }
            while ( v23 );
          }
          for ( ; v20 < size; *(_DWORD *)&v6[4 * v20 - 4] = v25 << 16 )
            v25 = *(signed __int16 *)&v8[2 * v20++];
        }
        break;
      default:
        return;
    }
  }
}

// File Line: 1139
// RVA: 0xC86B10
void __fastcall hkVariantDataUtil::stridedCopy(const void *src, int srcStride, void *dst, int dstStride, int eleSize, int size)
{
  __m128i *v6; // rbx
  char *v7; // rdi
  __int64 v8; // rax
  __m128i v9; // xmm0
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

  v6 = (__m128i *)dst;
  v7 = (char *)src;
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
          LOBYTE(v6->m128i_i64[0]) = v20;
          v6 = (__m128i *)((char *)v6 + dstStride);
          --v19;
        }
        while ( v19 );
      }
      break;
    case 2:
      if ( ((unsigned __int8)dst | (unsigned __int8)((unsigned __int8)src | srcStride | dstStride)) & 1 )
        goto LABEL_24;
      if ( size > 0 )
      {
        v17 = (unsigned int)size;
        do
        {
          v18 = *(_WORD *)v7;
          v7 += srcStride;
          LOWORD(v6->m128i_i64[0]) = v18;
          v6 = (__m128i *)((char *)v6 + dstStride);
          --v17;
        }
        while ( v17 );
      }
      break;
    case 4:
      if ( ((unsigned __int8)dst | (unsigned __int8)((unsigned __int8)src | srcStride | dstStride)) & 3 )
        goto LABEL_24;
      if ( size > 0 )
      {
        v12 = (unsigned int)size;
        do
        {
          v13 = *(_DWORD *)v7;
          v7 += srcStride;
          LODWORD(v6->m128i_i64[0]) = v13;
          v6 = (__m128i *)((char *)v6 + dstStride);
          --v12;
        }
        while ( v12 );
      }
      break;
    case 8:
      if ( !(((unsigned __int8)dst | (unsigned __int8)((unsigned __int8)src | srcStride | dstStride)) & 7) )
      {
        if ( size > 0 )
        {
          v10 = (unsigned int)size;
          do
          {
            v11 = *(_QWORD *)v7;
            v7 += srcStride;
            v6->m128i_i64[0] = v11;
            v6 = (__m128i *)((char *)v6 + dstStride);
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
          v6 = (__m128i *)((char *)v6 + v14);
          --v16;
        }
        while ( v16 );
      }
      return;
    default:
      if ( eleSize == 16
        && !(((unsigned __int8)dst | (unsigned __int8)((unsigned __int8)src | srcStride | dstStride)) & 0xF) )
      {
        v8 = (unsigned int)size;
        if ( size > 0 )
        {
          do
          {
            v9 = *(__m128i *)v7;
            v7 += srcStride;
            _mm_store_si128(v6, v9);
            v6 = (__m128i *)((char *)v6 + dstStride);
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
  hkStridedBasicArray *v2; // rsi
  hkStridedBasicArray *v3; // rdi
  hkClassMember::Type v4; // ecx
  hkClassMember::TypeProperties *v5; // rax
  hkClassMember::TypeProperties *v6; // rbx
  hkClassMember::TypeProperties *v7; // rax
  int v8; // ecx
  int v9; // er14
  int v10; // eax
  int eleSize; // er14
  __int64 v12; // rbp
  void *v13; // r8
  int v14; // ebx
  int v15; // er9
  void *v16; // rdx
  hkClassMember::Type v17; // ecx
  int v18; // eax
  void *v19; // r9
  hkClassMember::Type v20; // er8
  int v21; // ebx
  int v22; // er9
  int v23; // edx
  void *v24; // rcx
  int size; // ST28_4
  void *array; // [rsp+30h] [rbp-28h]
  int v27; // [rsp+38h] [rbp-20h]
  int v28; // [rsp+3Ch] [rbp-1Ch]
  hkResult result; // [rsp+60h] [rbp+8h]

  v2 = dst;
  v3 = src;
  if ( src->m_size > 0 )
  {
    v4 = src->m_type;
    if ( __PAIR__(v3->m_tupleSize, v4) == *(_QWORD *)&dst->m_type )
    {
      v5 = hkClassMember::getClassMemberTypeProperties(v4);
      hkVariantDataUtil::stridedCopy(
        v3->m_data,
        v3->m_stride,
        v2->m_data,
        v2->m_stride,
        v3->m_tupleSize * v5->m_size,
        v3->m_size);
    }
    else
    {
      v6 = hkClassMember::getClassMemberTypeProperties(v4);
      v7 = hkClassMember::getClassMemberTypeProperties(v2->m_type);
      v8 = v3->m_tupleSize;
      v9 = v7->m_size;
      v10 = v3->m_stride;
      eleSize = v2->m_tupleSize * v9;
      v12 = (unsigned int)(v8 * v6->m_size);
      if ( (_DWORD)v12 != v10 || eleSize != v2->m_stride )
      {
        v28 = 2147483648;
        v13 = 0i64;
        array = 0i64;
        v27 = 0;
        if ( (_DWORD)v12 == v10 )
        {
          v14 = v3->m_size * eleSize;
          if ( v14 > 0 )
          {
            v15 = v3->m_size * eleSize;
            if ( v14 < 0 )
              v15 = 0;
            hkArrayUtil::_reserve(
              &result,
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
              &array,
              v15,
              1);
            v13 = array;
          }
          v16 = v3->m_data;
          v17 = v3->m_type;
          v18 = v3->m_size * v3->m_tupleSize;
          v19 = v13;
          v20 = v2->m_type;
          v27 = v14;
          hkVariantDataUtil::convertTypeToTypeArray(v17, v16, v20, v19, v12, v18);
          hkVariantDataUtil::stridedCopy(array, eleSize, v2->m_data, v2->m_stride, eleSize, v3->m_size);
        }
        else
        {
          v21 = v3->m_size * v12;
          if ( v21 > 0 )
          {
            v22 = v3->m_size * v12;
            if ( v21 < 0 )
              v22 = 0;
            hkArrayUtil::_reserve(
              &result,
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
              &array,
              v22,
              1);
            v13 = array;
          }
          v23 = v3->m_stride;
          v24 = v3->m_data;
          size = v3->m_size;
          v27 = v21;
          hkVariantDataUtil::stridedCopy(v24, v23, v13, v12, v12, size);
          hkVariantDataUtil::convertTypeToTypeArray(
            v3->m_type,
            array,
            v2->m_type,
            v2->m_data,
            v12,
            v3->m_size * v3->m_tupleSize);
        }
        v27 = 0;
        if ( v28 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            array,
            v28 & 0x3FFFFFFF);
      }
      else
      {
        hkVariantDataUtil::convertTypeToTypeArray(v3->m_type, v3->m_data, v2->m_type, v2->m_data, v12, v3->m_size * v8);
      }
    }
  }
}

