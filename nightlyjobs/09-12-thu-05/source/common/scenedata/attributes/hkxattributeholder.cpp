// File Line: 14
// RVA: 0xE33E50
void __fastcall hkxAttributeHolder::hkxAttributeHolder(hkxAttributeHolder *this, hkxAttributeHolder *other)
{
  __int64 m_size; // rbp
  int v4; // r15d
  int v6; // ebx
  hkxAttributeGroup *v7; // rdi
  hkxAttributeGroup *m_data; // rbx
  char *v9; // rsi
  __int64 v10; // rdi
  hkxAttributeGroup *v11; // rdi
  hkxAttributeGroup *v12; // rbx
  __int64 v13; // rsi
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkxAttributeHolder::`vftable;
  this->m_attributeGroups.m_capacityAndFlags = 0x80000000;
  this->m_attributeGroups.m_data = 0i64;
  this->m_attributeGroups.m_size = 0;
  m_size = other->m_attributeGroups.m_size;
  v4 = m_size;
  if ( (int)m_size > 0 )
    v4 = 0;
  if ( (int)m_size > 0 )
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_attributeGroups.m_data,
      m_size,
      24);
  v6 = -1 - m_size;
  if ( -1 - (int)m_size >= 0 )
  {
    v7 = &this->m_attributeGroups.m_data[m_size + v6];
    do
    {
      hkxAttributeGroup::~hkxAttributeGroup(v7--);
      --v6;
    }
    while ( v6 >= 0 );
  }
  m_data = this->m_attributeGroups.m_data;
  if ( v4 > 0 )
  {
    v9 = (char *)((char *)other->m_attributeGroups.m_data - (char *)m_data);
    v10 = (unsigned int)v4;
    do
    {
      hkxAttributeGroup::operator=(m_data, (hkxAttributeGroup *)((char *)m_data + (_QWORD)v9));
      ++m_data;
      --v10;
    }
    while ( v10 );
  }
  v11 = &other->m_attributeGroups.m_data[v4];
  v12 = &this->m_attributeGroups.m_data[v4];
  if ( (int)m_size - v4 > 0 )
  {
    v13 = (unsigned int)(m_size - v4);
    do
    {
      if ( v12 )
      {
        hkStringPtr::hkStringPtr(&v12->m_name);
        v12->m_attributes.m_data = 0i64;
        v12->m_attributes.m_size = 0;
        v12->m_attributes.m_capacityAndFlags = 0x80000000;
        hkxAttributeGroup::operator=(v12, v11);
      }
      ++v11;
      ++v12;
      --v13;
    }
    while ( v13 );
  }
  this->m_attributeGroups.m_size = m_size;
}

// File Line: 19
// RVA: 0xE33FB0
void __fastcall hkxAttributeHolder::~hkxAttributeHolder(hkxAttributeHolder *this)
{
  int m_size; // ebx
  hkxAttributeGroup *m_data; // rcx
  int v4; // ebx
  hkxAttributeGroup *v5; // rdi
  int m_capacityAndFlags; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkxAttributeHolder::`vftable;
  m_size = this->m_attributeGroups.m_size;
  m_data = this->m_attributeGroups.m_data;
  v4 = m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &m_data[v4];
    do
    {
      hkxAttributeGroup::~hkxAttributeGroup(v5--);
      --v4;
    }
    while ( v4 >= 0 );
  }
  m_capacityAndFlags = this->m_attributeGroups.m_capacityAndFlags;
  this->m_attributeGroups.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_attributeGroups.m_data,
      24 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_attributeGroups.m_data = 0i64;
  this->m_attributeGroups.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 25
// RVA: 0xE34050
hkxAttributeGroup *__fastcall hkxAttributeHolder::findAttributeGroupByName(hkxAttributeHolder *this, const char *name)
{
  int v5; // ebx
  __int64 i; // rdi
  hkxAttributeGroup *v7; // r14

  if ( !name )
    return 0i64;
  v5 = 0;
  if ( this->m_attributeGroups.m_size <= 0 )
    return 0i64;
  for ( i = 0i64; ; ++i )
  {
    v7 = &this->m_attributeGroups.m_data[i];
    if ( ((unsigned __int64)v7->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != 0
      && !(unsigned int)hkString::strCasecmp(
                          (const char *)((unsigned __int64)v7->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                          name) )
    {
      break;
    }
    if ( ++v5 >= this->m_attributeGroups.m_size )
      return 0i64;
  }
  return v7;
}

// File Line: 44
// RVA: 0xE34170
hkRefVariant *__fastcall hkxAttributeHolder::findAttributeVariantByName(
        hkxAttributeHolder *this,
        hkRefVariant *result,
        const char *name)
{
  int v6; // ebx
  hkReferencedObject *m_pntr; // rcx
  hkVariant v; // [rsp+20h] [rbp-28h] BYREF
  hkRefVariant resulta; // [rsp+60h] [rbp+18h] BYREF

  if ( name && (v6 = 0, this->m_attributeGroups.m_size > 0) )
  {
    while ( 1 )
    {
      hkxAttributeGroup::findAttributeVariantByName(&this->m_attributeGroups.m_data[v6], &resulta, name);
      if ( resulta.m_pntr )
        break;
      ++v6;
      resulta.m_pntr = 0i64;
      if ( v6 >= this->m_attributeGroups.m_size )
        goto LABEL_5;
    }
    hkReferencedObject::addReference(resulta.m_pntr);
    m_pntr = resulta.m_pntr;
    result->m_pntr = resulta.m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  else
  {
LABEL_5:
    v.m_object = 0i64;
    v.m_class = 0i64;
    hkRefVariant::hkRefVariant(result, &v);
  }
  return result;
}

// File Line: 60
// RVA: 0xE340E0
hkReferencedObject *__fastcall hkxAttributeHolder::findAttributeObjectByName(
        hkxAttributeHolder *this,
        const char *name,
        hkClass *type)
{
  hkReferencedObject *m_pntr; // rcx
  hkClass *Class; // rax
  const char *v7; // rbx
  const char *v8; // rax
  int v9; // eax
  hkReferencedObject *v10; // rbx
  hkRefVariant result; // [rsp+38h] [rbp+10h] BYREF

  if ( !name )
    return 0i64;
  hkxAttributeHolder::findAttributeVariantByName(this, &result, name);
  m_pntr = result.m_pntr;
  if ( !result.m_pntr
    || type
    && (Class = hkRefVariant::getClass(&result),
        v7 = hkClass::getName(Class),
        v8 = hkClass::getName(type),
        v9 = hkString::strCasecmp(v8, v7),
        m_pntr = result.m_pntr,
        v9) )
  {
    v10 = 0i64;
  }
  else
  {
    v10 = m_pntr;
  }
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  return v10;
}

