// File Line: 14
// RVA: 0xE34220
void __fastcall hkxEnvironment::hkxEnvironment(hkxEnvironment *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkxEnvironment::`vftable;
  this->m_variables.m_capacityAndFlags = 0x80000000;
  this->m_variables.m_data = 0i64;
  this->m_variables.m_size = 0;
}

// File Line: 19
// RVA: 0xE34250
void __fastcall hkxEnvironment::hkxEnvironment(hkxEnvironment *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkxEnvironment::`vftable;
}

// File Line: 23
// RVA: 0xE34270
hkResult *__fastcall hkxEnvironment::setVariable(
        hkxEnvironment *this,
        hkResult *result,
        const char *name,
        const char *value)
{
  int VariableByName; // eax
  int v9; // esi
  __int64 v10; // r14
  hkxEnvironment::Variable *v11; // rbx
  __int64 v12; // rcx
  __int64 v13; // rdx
  __int64 v14; // r8
  hkxEnvironment::Variable *v15; // rcx
  __int64 v16; // r8
  const char *v17; // rax
  hkxEnvironment::Variable *v18; // rbx
  hkStringPtr strRef; // [rsp+20h] [rbp-18h] BYREF
  hkStringPtr v21; // [rsp+28h] [rbp-10h] BYREF

  VariableByName = hkxEnvironment::findVariableByName(this, name);
  v9 = VariableByName;
  if ( value )
  {
    if ( VariableByName == -1 )
    {
      hkStringPtr::hkStringPtr(&strRef);
      hkStringPtr::hkStringPtr(&v21);
      hkStringPtr::operator=(&strRef, name);
      hkStringPtr::operator=(&v21, value);
      if ( this->m_variables.m_size == (this->m_variables.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_variables.m_data, 16);
      v18 = &this->m_variables.m_data[this->m_variables.m_size];
      if ( v18 )
      {
        hkStringPtr::hkStringPtr(&v18->m_name, &strRef);
        hkStringPtr::hkStringPtr(&v18->m_value, &v21);
      }
      ++this->m_variables.m_size;
      hkStringPtr::~hkStringPtr(&v21);
      hkStringPtr::~hkStringPtr(&strRef);
    }
    else
    {
      hkStringPtr::operator=(&this->m_variables.m_data[VariableByName].m_value, value);
    }
    goto LABEL_15;
  }
  if ( VariableByName != -1 )
  {
    v10 = VariableByName;
    v11 = &this->m_variables.m_data[v10];
    hkStringPtr::~hkStringPtr(&v11->m_value);
    hkStringPtr::~hkStringPtr(&v11->m_name);
    v12 = --this->m_variables.m_size;
    if ( (_DWORD)v12 != v9 )
    {
      v13 = 2i64;
      v14 = 16 * v12;
      v15 = &this->m_variables.m_data[v10];
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
    result->m_enum = HK_SUCCESS;
    return result;
  }
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 57
// RVA: 0xE34400
const char *__fastcall hkxEnvironment::getVariableValue(hkxEnvironment *this, const char *name)
{
  int VariableByName; // eax

  VariableByName = hkxEnvironment::findVariableByName(this, name);
  if ( VariableByName == -1 )
    return 0i64;
  else
    return (const char *)((unsigned __int64)this->m_variables.m_data[VariableByName].m_value.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 73
// RVA: 0xE34440
void __fastcall hkxEnvironment::clear(hkxEnvironment *this)
{
  hkxEnvironment::Variable *m_data; // rcx
  int v3; // edi
  hkStringPtr *p_m_name; // rbx

  m_data = this->m_variables.m_data;
  v3 = this->m_variables.m_size - 1;
  if ( v3 >= 0 )
  {
    p_m_name = &m_data[v3].m_name;
    do
    {
      hkStringPtr::~hkStringPtr(p_m_name + 1);
      hkStringPtr::~hkStringPtr(p_m_name);
      p_m_name -= 2;
      --v3;
    }
    while ( v3 >= 0 );
  }
  this->m_variables.m_size = 0;
}

// File Line: 78
// RVA: 0xE34940
__int64 __fastcall hkxEnvironment::findVariableByName(hkxEnvironment *this, const char *name)
{
  unsigned int v2; // ebx
  __int64 i; // rdi

  v2 = 0;
  if ( this->m_variables.m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = 0i64;
        (unsigned int)hkString::strCasecmp(
                        (const char *)((unsigned __int64)this->m_variables.m_data[i].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                        name);
        ++i )
  {
    if ( (signed int)++v2 >= this->m_variables.m_size )
      return 0xFFFFFFFFi64;
  }
  return v2;
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
  return (const char *)((unsigned __int64)this->m_variables.m_data[i].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 101
// RVA: 0xE34920
const char *__fastcall hkxEnvironment::getVariableValue(hkxEnvironment *this, int i)
{
  return (const char *)((unsigned __int64)this->m_variables.m_data[i].m_value.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 106
// RVA: 0xE349C0
char __fastcall needsQuotes(char *str)
{
  char v1; // al

  v1 = *str;
  if ( !*str )
    return 0;
  while ( v1 > 32 && v1 != 61 && v1 != 59 )
  {
    v1 = *++str;
    if ( !v1 )
      return 0;
  }
  return 1;
}

// File Line: 119
// RVA: 0xE344A0
void __fastcall hkxEnvironment::convertToString(hkxEnvironment *this, hkStringBuf *result)
{
  int v4; // ebx
  __int64 v5; // rdi
  const char *v6; // rdx
  bool v7; // al
  const char *v8; // rdx
  const char *v9; // r8
  const char *v10; // r9
  const char *v11; // rcx

  hkStringBuf::clear(result);
  v4 = 0;
  if ( this->m_variables.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      needsQuotes((const char *)((unsigned __int64)this->m_variables.m_data[v5].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
      v7 = needsQuotes(v6);
      v11 = &customCaption;
      if ( v7 )
        v11 = "\"";
      hkStringBuf::appendPrintf(result, "%s%s%s=%s%s%s", v9, v10, v9, v11, v8, v11);
      if ( v4 < this->m_variables.m_size - 1 )
        hkStringBuf::operator+=(result, "; ");
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_variables.m_size );
  }
}

// File Line: 139
// RVA: 0xE34590
hkResult *__fastcall hkxEnvironment::interpretString(hkxEnvironment *this, hkResult *result, const char *str)
{
  int v6; // edi
  __int64 v7; // rsi
  __int64 v8; // r12
  int v9; // ecx
  char v10; // al
  int v11; // edx
  _DWORD *v12; // rax
  int v13; // ebx
  char *m_data; // r9
  hkResult *p_resulta; // rdx
  hkStringBuf *v16; // rax
  int m_capacityAndFlags; // r8d
  hkOstream *v18; // rax
  hkOstream *v19; // rax
  int v20; // r9d
  unsigned int v21; // ecx
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  int v24; // r8d
  char v26[8]; // [rsp+20h] [rbp-E0h] BYREF
  hkErrStream v27; // [rsp+28h] [rbp-D8h] BYREF
  hkResult resulta; // [rsp+40h] [rbp-C0h] BYREF
  char v29; // [rsp+44h] [rbp-BCh] BYREF
  hkStringBuf v30; // [rsp+50h] [rbp-B0h] BYREF
  hkStringBuf v31; // [rsp+E0h] [rbp-20h] BYREF
  char buf[512]; // [rsp+170h] [rbp+70h] BYREF
  char other; // [rsp+3B8h] [rbp+2B8h] BYREF
  char v34; // [rsp+3B9h] [rbp+2B9h]

  v31.m_string.m_data = v31.m_string.m_storage;
  v6 = 0;
  v30.m_string.m_data = v30.m_string.m_storage;
  v31.m_string.m_capacityAndFlags = -2147483520;
  v31.m_string.m_size = 1;
  v31.m_string.m_storage[0] = 0;
  v30.m_string.m_capacityAndFlags = -2147483520;
  v30.m_string.m_size = 1;
  v30.m_string.m_storage[0] = 0;
  v7 = 0i64;
  v8 = (int)hkString::strLen(str);
  while ( 2 )
  {
    if ( v7 < v8 )
    {
      v10 = str[v7];
      v9 = 4;
      if ( v10 <= 32 )
        v9 = 0;
      switch ( v10 )
      {
        case ":
          v9 = 1;
          break;
        case =:
          v9 = 2;
          break;
        case ;:
          v9 = 3;
          break;
      }
    }
    else
    {
      v9 = 5;
    }
    v11 = 6;
    v12 = &unk_141AB2264;
    v13 = 9;
    do
    {
      if ( *(v12 - 1) == v6 && *v12 == v9 )
      {
        v13 = v12[1];
        v11 = v12[2];
      }
      v12 += 4;
    }
    while ( (__int64)v12 < (__int64)"r parsing environment string: " );
    switch ( v11 )
    {
      case 0:
        ++v7;
        goto $LN5_216;
      case 1:
        other = str[v7];
        v34 = 0;
        hkStringBuf::operator+=(&v31, &other);
        goto LABEL_24;
      case 2:
        v26[0] = str[v7];
        v26[1] = 0;
        hkStringBuf::operator+=(&v30, v26);
        goto LABEL_24;
      case 3:
        m_data = v30.m_string.m_data;
        p_resulta = (hkResult *)&v29;
        goto LABEL_23;
      case 4:
        m_data = 0i64;
        p_resulta = &resulta;
LABEL_23:
        hkxEnvironment::setVariable(this, p_resulta, v31.m_string.m_data, m_data);
        v16 = hkStringBuf::operator=(&v30, &customCaption);
        hkStringBuf::operator=(&v31, v16);
LABEL_24:
        ++v7;
        goto $LN5_216;
      case 5:
$LN5_216:
        v6 = v13;
        if ( v13 != 8 )
          continue;
        m_capacityAndFlags = v30.m_string.m_capacityAndFlags;
        result->m_enum = HK_SUCCESS;
        v30.m_string.m_size = 0;
        if ( m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v30.m_string.m_data,
            m_capacityAndFlags & 0x3FFFFFFF);
        v30.m_string.m_data = 0i64;
        v31.m_string.m_size = 0;
        break;
      case 6:
        hkErrStream::hkErrStream(&v27, buf, 512);
        v18 = hkOstream::operator<<(&v27, "Error parsing environment string: ");
        v19 = hkOstream::operator<<(v18, str);
        hkOstream::operator<<(v19, "");
        v20 = 308;
        v21 = -1413842815;
        goto LABEL_31;
      default:
        hkErrStream::hkErrStream(&v27, buf, 512);
        v22 = hkOstream::operator<<(&v27, "Internal Error: Unknown action parsing environment string: ");
        v23 = hkOstream::operator<<(v22, str);
        hkOstream::operator<<(v23, "");
        v20 = 320;
        v21 = -1413873614;
LABEL_31:
        hkError::messageWarning(v21, buf, "Environment\\hkxEnvironment.cpp", v20);
        hkOstream::~hkOstream(&v27);
        v24 = v30.m_string.m_capacityAndFlags;
        v30.m_string.m_size = 0;
        result->m_enum = HK_FAILURE;
        if ( v24 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v30.m_string.m_data,
            v24 & 0x3FFFFFFF);
        v31.m_string.m_size = 0;
        v30.m_string.m_data = 0i64;
        break;
    }
    break;
  }
  v30.m_string.m_capacityAndFlags = 0x80000000;
  if ( v31.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v31.m_string.m_data,
      v31.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return result;
}

