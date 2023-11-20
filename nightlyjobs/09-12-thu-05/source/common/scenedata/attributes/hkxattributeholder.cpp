// File Line: 14
// RVA: 0xE33E50
void __fastcall hkxAttributeHolder::hkxAttributeHolder(hkxAttributeHolder *this, hkxAttributeHolder *other)
{
  hkxAttributeHolder *v2; // r13
  __int64 v3; // rbp
  unsigned int v4; // er15
  hkxAttributeHolder *v5; // r12
  int v6; // er9
  int v7; // ebx
  hkxAttributeGroup *v8; // rdi
  hkxAttributeGroup *v9; // rbx
  signed __int64 v10; // rsi
  __int64 v11; // rdi
  hkxAttributeGroup *v12; // rdi
  hkxAttributeGroup *v13; // rbx
  __int64 v14; // rsi
  hkResult result; // [rsp+60h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = other;
  this->vfptr = (hkBaseObjectVtbl *)&hkxAttributeHolder::`vftable';
  this->m_attributeGroups.m_capacityAndFlags = 2147483648;
  this->m_attributeGroups.m_data = 0i64;
  this->m_attributeGroups.m_size = 0;
  v3 = other->m_attributeGroups.m_size;
  v4 = v3;
  v5 = this;
  if ( (signed int)v3 > 0 )
    v4 = 0;
  if ( (signed int)v3 > 0 )
  {
    v6 = v3;
    if ( (signed int)v3 < 0 )
      v6 = 0;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_attributeGroups,
      v6,
      24);
  }
  v7 = -1 - v3;
  if ( -1 - (signed int)v3 >= 0 )
  {
    v8 = &v5->m_attributeGroups.m_data[v3 + v7];
    do
    {
      hkxAttributeGroup::~hkxAttributeGroup(v8);
      --v8;
      --v7;
    }
    while ( v7 >= 0 );
  }
  v9 = v5->m_attributeGroups.m_data;
  if ( (signed int)v4 > 0 )
  {
    v10 = (char *)v2->m_attributeGroups.m_data - (char *)v9;
    v11 = v4;
    do
    {
      hkxAttributeGroup::operator=(v9, (hkxAttributeGroup *)((char *)v9 + v10));
      ++v9;
      --v11;
    }
    while ( v11 );
  }
  v12 = &v2->m_attributeGroups.m_data[v4];
  v13 = &v5->m_attributeGroups.m_data[v4];
  if ( (signed int)(v3 - v4) > 0 )
  {
    v14 = (unsigned int)v3 - v4;
    do
    {
      if ( v13 )
      {
        hkStringPtr::hkStringPtr(&v13->m_name);
        v13->m_attributes.m_data = 0i64;
        v13->m_attributes.m_size = 0;
        v13->m_attributes.m_capacityAndFlags = 2147483648;
        hkxAttributeGroup::operator=(v13, v12);
      }
      ++v12;
      ++v13;
      --v14;
    }
    while ( v14 );
  }
  v5->m_attributeGroups.m_size = v3;
}

// File Line: 19
// RVA: 0xE33FB0
void __fastcall hkxAttributeHolder::~hkxAttributeHolder(hkxAttributeHolder *this)
{
  hkxAttributeHolder *v1; // rsi
  int v2; // ebx
  hkxAttributeGroup *v3; // rcx
  int v4; // ebx
  hkxAttributeGroup *v5; // rdi
  int v6; // eax

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkxAttributeHolder::`vftable';
  v2 = this->m_attributeGroups.m_size;
  v3 = this->m_attributeGroups.m_data;
  v4 = v2 - 1;
  if ( v4 >= 0 )
  {
    v5 = &v3[v4];
    do
    {
      hkxAttributeGroup::~hkxAttributeGroup(v5);
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v6 = v1->m_attributeGroups.m_capacityAndFlags;
  v1->m_attributeGroups.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_attributeGroups.m_data,
      24 * (v6 & 0x3FFFFFFF));
  v1->m_attributeGroups.m_data = 0i64;
  v1->m_attributeGroups.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 25
// RVA: 0xE34050
hkxAttributeGroup *__fastcall hkxAttributeHolder::findAttributeGroupByName(hkxAttributeHolder *this, const char *name)
{
  const char *v2; // rbp
  hkxAttributeHolder *v3; // rsi
  int v5; // ebx
  __int64 v6; // rdi
  hkxAttributeGroup *v7; // r14

  v2 = name;
  v3 = this;
  if ( !name )
    return 0i64;
  v5 = 0;
  if ( this->m_attributeGroups.m_size <= 0 )
    return 0i64;
  v6 = 0i64;
  while ( 1 )
  {
    v7 = &v3->m_attributeGroups.m_data[v6];
    if ( (_QWORD)v7->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( !(unsigned int)hkString::strCasecmp(
                            (const char *)((_QWORD)v7->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                            v2) )
        break;
    }
    ++v5;
    ++v6;
    if ( v5 >= v3->m_attributeGroups.m_size )
      return 0i64;
  }
  return v7;
}

// File Line: 44
// RVA: 0xE34170
hkRefVariant *__fastcall hkxAttributeHolder::findAttributeVariantByName(hkxAttributeHolder *this, hkRefVariant *result, const char *name)
{
  const char *v3; // rbp
  hkRefVariant *v4; // rsi
  hkxAttributeHolder *v5; // rdi
  int v6; // ebx
  hkReferencedObject *v8; // rcx
  hkVariant v; // [rsp+20h] [rbp-28h]
  hkRefVariant resulta; // [rsp+60h] [rbp+18h]

  v3 = name;
  v4 = result;
  v5 = this;
  if ( name && (v6 = 0, this->m_attributeGroups.m_size > 0) )
  {
    while ( 1 )
    {
      hkxAttributeGroup::findAttributeVariantByName(&v5->m_attributeGroups.m_data[v6], &resulta, v3);
      if ( resulta.m_pntr )
        break;
      ++v6;
      resulta.m_pntr = 0i64;
      if ( v6 >= v5->m_attributeGroups.m_size )
        goto LABEL_5;
    }
    hkReferencedObject::addReference(resulta.m_pntr);
    v8 = resulta.m_pntr;
    v4->m_pntr = resulta.m_pntr;
    if ( v8 )
      hkReferencedObject::removeReference(v8);
  }
  else
  {
LABEL_5:
    v.m_object = 0i64;
    v.m_class = 0i64;
    hkRefVariant::hkRefVariant(v4, &v);
  }
  return v4;
}

// File Line: 60
// RVA: 0xE340E0
hkReferencedObject *__fastcall hkxAttributeHolder::findAttributeObjectByName(hkxAttributeHolder *this, const char *name, hkClass *type)
{
  hkClass *v3; // rdi
  hkReferencedObject *v5; // rcx
  hkClass *v6; // rax
  const char *v7; // rbx
  const char *v8; // rax
  int v9; // eax
  hkReferencedObject *v10; // rbx
  hkRefVariant result; // [rsp+38h] [rbp+10h]

  v3 = type;
  if ( !name )
    return 0i64;
  hkxAttributeHolder::findAttributeVariantByName(this, &result, name);
  v5 = result.m_pntr;
  if ( !result.m_pntr
    || v3
    && (v6 = hkRefVariant::getClass(&result),
        v7 = hkClass::getName(v6),
        v8 = hkClass::getName(v3),
        v9 = hkString::strCasecmp(v8, v7),
        v5 = result.m_pntr,
        v9) )
  {
    v10 = 0i64;
  }
  else
  {
    v10 = v5;
  }
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  return v10;
}

