// File Line: 14
// RVA: 0xE34220
void __fastcall hkxEnvironment::hkxEnvironment(hkxEnvironment *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkxEnvironment::`vftable';
  this->m_variables.m_capacityAndFlags = 2147483648;
  this->m_variables.m_data = 0i64;
  this->m_variables.m_size = 0;
}

// File Line: 19
// RVA: 0xE34250
void __fastcall hkxEnvironment::hkxEnvironment(hkxEnvironment *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkxEnvironment::`vftable';
}

// File Line: 23
// RVA: 0xE34270
hkResult *__fastcall hkxEnvironment::setVariable(hkxEnvironment *this, hkResult *result, const char *name, const char *value)
{
  hkResult *v4; // rdi
  const char *v5; // rbx
  const char *v6; // r14
  hkxEnvironment *v7; // rbp
  int v8; // eax
  int v9; // esi
  signed __int64 v10; // r14
  hkStringPtr *v11; // rbx
  __int64 v12; // rcx
  signed __int64 v13; // rdx
  signed __int64 v14; // r8
  hkxEnvironment::Variable *v15; // rcx
  signed __int64 v16; // r8
  const char *v17; // rax
  hkStringPtr *v18; // rbx
  hkStringPtr strRef; // [rsp+20h] [rbp-18h]
  hkStringPtr v21; // [rsp+28h] [rbp-10h]

  v4 = result;
  v5 = value;
  v6 = name;
  v7 = this;
  v8 = hkxEnvironment::findVariableByName(this, name);
  v9 = v8;
  if ( v5 )
  {
    if ( v8 == -1 )
    {
      hkStringPtr::hkStringPtr(&strRef);
      hkStringPtr::hkStringPtr(&v21);
      hkStringPtr::operator=(&strRef, v6);
      hkStringPtr::operator=(&v21, v5);
      if ( v7->m_variables.m_size == (v7->m_variables.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_variables, 16);
      v18 = &v7->m_variables.m_data[v7->m_variables.m_size].m_name;
      if ( v18 )
      {
        hkStringPtr::hkStringPtr(v18, &strRef);
        hkStringPtr::hkStringPtr(v18 + 1, &v21);
      }
      ++v7->m_variables.m_size;
      hkStringPtr::~hkStringPtr(&v21);
      hkStringPtr::~hkStringPtr(&strRef);
    }
    else
    {
      hkStringPtr::operator=(&v7->m_variables.m_data[v8].m_value, v5);
    }
    goto LABEL_15;
  }
  if ( v8 != -1 )
  {
    v10 = v8;
    v11 = &v7->m_variables.m_data[v8].m_name;
    hkStringPtr::~hkStringPtr(v11 + 1);
    hkStringPtr::~hkStringPtr(v11);
    v12 = --v7->m_variables.m_size;
    if ( (_DWORD)v12 != v9 )
    {
      v13 = 2i64;
      v14 = 16 * v12;
      v15 = &v7->m_variables.m_data[v10];
      v16 = v14 - v10 * 16;
      do
      {
        v17 = *(const char **)((char *)&v15->m_name.m_stringAndFlag + v16);
        v15 = (hkxEnvironment::Variable *)((char *)v15 + 8);
        v15[-1].m_value.m_stringAndFlag = v17;
        --v13;
      }
      while ( v13 );
    }
LABEL_15:
    v4->m_enum = 0;
    return v4;
  }
  v4->m_enum = 1;
  return v4;
}

// File Line: 57
// RVA: 0xE34400
const char *__fastcall hkxEnvironment::getVariableValue(hkxEnvironment *this, const char *name)
{
  hkxEnvironment *v2; // rbx
  int v3; // eax
  const char *result; // rax

  v2 = this;
  v3 = hkxEnvironment::findVariableByName(this, name);
  if ( v3 == -1 )
    result = 0i64;
  else
    result = (const char *)((_QWORD)v2->m_variables.m_data[v3].m_value.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  return result;
}

// File Line: 73
// RVA: 0xE34440
void __fastcall hkxEnvironment::clear(hkxEnvironment *this)
{
  hkxEnvironment *v1; // rsi
  hkxEnvironment::Variable *v2; // rcx
  int v3; // edi
  hkStringPtr *v4; // rbx

  v1 = this;
  v2 = this->m_variables.m_data;
  v3 = v1->m_variables.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &v2[v3].m_name;
    do
    {
      hkStringPtr::~hkStringPtr(v4 + 1);
      hkStringPtr::~hkStringPtr(v4);
      v4 -= 2;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v1->m_variables.m_size = 0;
}

// File Line: 78
// RVA: 0xE34940
signed __int64 __fastcall hkxEnvironment::findVariableByName(hkxEnvironment *this, const char *name)
{
  int v2; // ebx
  const char *v3; // rbp
  hkxEnvironment *v4; // rsi
  __int64 v5; // rdi

  v2 = 0;
  v3 = name;
  v4 = this;
  if ( this->m_variables.m_size <= 0 )
    return 0xFFFFFFFFi64;
  v5 = 0i64;
  while ( (unsigned int)hkString::strCasecmp(
                          (const char *)((_QWORD)v4->m_variables.m_data[v5].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                          v3) )
  {
    ++v2;
    ++v5;
    if ( v2 >= v4->m_variables.m_size )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)v2;
}

// File Line: 91
// RVA: 0xE348F0
__int64 __fastcall hkxEnvironment::getNumVariables(hkxEnvironment *this)
{
  return (unsigned int)this->m_variables.m_size;
}

// File Line: 96
// RVA: 0xE34900
const char *__fastcall hkxEnvironment::getVariableName(hkxEnvironment *this, int i)
{
  return (const char *)((_QWORD)this->m_variables.m_data[i].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 101
// RVA: 0xE34920
const char *__fastcall hkxEnvironment::getVariableValue(hkxEnvironment *this, int i)
{
  return (const char *)((_QWORD)this->m_variables.m_data[i].m_value.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 106
// RVA: 0xE349C0
char __fastcall needsQuotes(const char *str)
{
  char v1; // al

  v1 = *str;
  if ( !*str )
    return 0;
  while ( v1 > 32 && v1 != 61 && v1 != 59 )
  {
    v1 = (str++)[1];
    if ( !v1 )
      return 0;
  }
  return 1;
}

// File Line: 119
// RVA: 0xE344A0
void __fastcall hkxEnvironment::convertToString(hkxEnvironment *this, hkStringBuf *result)
{
  hkxEnvironment *v2; // rsi
  hkStringBuf *v3; // rbp
  int v4; // ebx
  __int64 v5; // rdi
  hkxEnvironment::Variable *v6; // rax
  unsigned __int64 v7; // rdx
  const char *v8; // rdx

  v2 = this;
  v3 = result;
  hkStringBuf::clear(result);
  v4 = 0;
  if ( v2->m_variables.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v2->m_variables.m_data;
      v7 = (_QWORD)v6[v5].m_value.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64;
      needsQuotes((const char *)((_QWORD)v6[v5].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
      needsQuotes(v8);
      hkStringBuf::appendPrintf(v3, "%s%s%s=%s%s%s");
      if ( v4 < v2->m_variables.m_size - 1 )
        hkStringBuf::operator+=(v3, "; ");
      ++v4;
      ++v5;
    }
    while ( v4 < v2->m_variables.m_size );
  }
}

// File Line: 139
// RVA: 0xE34590
hkResult *__fastcall hkxEnvironment::interpretString(hkxEnvironment *this, hkResult *result, const char *str)
{
  hkxEnvironment *v3; // r13
  const char *v4; // r15
  hkResult *v5; // r14
  signed int v6; // edi
  int v7; // eax
  __int64 v8; // r9
  __int64 v9; // rsi
  __int64 v10; // r12
  signed int v11; // ecx
  char v12; // al
  signed int v13; // edx
  _DWORD *v14; // rax
  signed int v15; // ebx
  char *v16; // r9
  hkResult *v17; // rdx
  hkStringBuf *v18; // rax
  int v19; // er8
  hkOstream *v20; // rax
  hkOstream *v21; // rax
  int v22; // er9
  int v23; // ecx
  hkOstream *v24; // rax
  hkOstream *v25; // rax
  int v26; // er8
  char v28; // [rsp+20h] [rbp-E0h]
  char v29; // [rsp+21h] [rbp-DFh]
  hkErrStream v30; // [rsp+28h] [rbp-D8h]
  hkResult resulta; // [rsp+40h] [rbp-C0h]
  char v32; // [rsp+44h] [rbp-BCh]
  hkStringBuf v33; // [rsp+50h] [rbp-B0h]
  hkStringBuf v34; // [rsp+E0h] [rbp-20h]
  char buf; // [rsp+170h] [rbp+70h]
  char other; // [rsp+3B8h] [rbp+2B8h]
  char v37; // [rsp+3B9h] [rbp+2B9h]

  v3 = this;
  v34.m_string.m_data = v34.m_string.m_storage;
  v4 = str;
  v5 = result;
  v6 = 0;
  v33.m_string.m_data = v33.m_string.m_storage;
  v34.m_string.m_capacityAndFlags = -2147483520;
  v34.m_string.m_size = 1;
  v34.m_string.m_storage[0] = 0;
  v33.m_string.m_capacityAndFlags = -2147483520;
  v33.m_string.m_size = 1;
  v33.m_string.m_storage[0] = 0;
  v7 = hkString::strLen(str);
  v8 = 0i64;
  v9 = 0i64;
  v10 = v7;
  while ( 2 )
  {
    if ( v9 < v10 )
    {
      v12 = v4[v9];
      v11 = 4;
      if ( v12 <= 32 )
        v11 = 0;
      switch ( v12 )
      {
        case 34:
          v11 = 1;
          break;
        case 61:
          v11 = 2;
          break;
        case 59:
          v11 = 3;
          break;
      }
    }
    else
    {
      v11 = 5;
    }
    v13 = 6;
    v14 = &unk_141AB2264;
    v15 = 9;
    do
    {
      if ( *(v14 - 1) == v6 && *v14 == v11 )
      {
        v15 = v14[1];
        v13 = v14[2];
      }
      v14 += 4;
    }
    while ( (signed __int64)v14 < (signed __int64)"r parsing environment string: '" );
    switch ( v13 )
    {
      case 0:
        ++v9;
        goto $LN5_216;
      case 1:
        other = v4[v9];
        v37 = 0;
        hkStringBuf::operator+=(&v34, &other);
        goto LABEL_24;
      case 2:
        v28 = v4[v9];
        v29 = 0;
        hkStringBuf::operator+=(&v33, &v28);
        goto LABEL_24;
      case 3:
        v16 = v33.m_string.m_data;
        v17 = (hkResult *)&v32;
        goto LABEL_23;
      case 4:
        v16 = 0i64;
        v17 = &resulta;
LABEL_23:
        hkxEnvironment::setVariable(v3, v17, v34.m_string.m_data, v16);
        v18 = hkStringBuf::operator=(&v33, &customWorldMapCaption);
        hkStringBuf::operator=(&v34, v18);
LABEL_24:
        ++v9;
        v8 = 0i64;
        goto $LN5_216;
      case 5:
$LN5_216:
        v6 = v15;
        if ( v15 != 8 )
          continue;
        v19 = v33.m_string.m_capacityAndFlags;
        v5->m_enum = 0;
        v33.m_string.m_size = 0;
        if ( v19 >= 0 )
        {
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v33.m_string.m_data,
            v19 & 0x3FFFFFFF);
          v8 = 0i64;
        }
        v33.m_string.m_data = 0i64;
        v34.m_string.m_size = 0;
        goto LABEL_34;
      case 6:
        hkErrStream::hkErrStream(&v30, &buf, 512);
        v20 = hkOstream::operator<<((hkOstream *)&v30.vfptr, "Error parsing environment string: '");
        v21 = hkOstream::operator<<(v20, v4);
        hkOstream::operator<<(v21, "'");
        v22 = 308;
        v23 = -1413842815;
        break;
      default:
        hkErrStream::hkErrStream(&v30, &buf, 512);
        v24 = hkOstream::operator<<(
                (hkOstream *)&v30.vfptr,
                "Internal Error: Unknown action parsing environment string: '");
        v25 = hkOstream::operator<<(v24, v4);
        hkOstream::operator<<(v25, "'");
        v22 = 320;
        v23 = -1413873614;
        break;
    }
    break;
  }
  hkError::messageWarning(v23, &buf, "Environment\\hkxEnvironment.cpp", v22);
  hkOstream::~hkOstream((hkOstream *)&v30.vfptr);
  v26 = v33.m_string.m_capacityAndFlags;
  v33.m_string.m_size = 0;
  v5->m_enum = 1;
  if ( v26 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v33.m_string.m_data,
      v26 & 0x3FFFFFFF);
  v34.m_string.m_size = 0;
  v33.m_string.m_data = 0i64;
LABEL_34:
  v33.m_string.m_capacityAndFlags = 2147483648;
  if ( v34.m_string.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, char *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v34.m_string.m_data,
      v34.m_string.m_capacityAndFlags & 0x3FFFFFFF,
      v8);
  return v5;
}

