// File Line: 12
// RVA: 0xE35690
void __fastcall hkxNode::~hkxNode(hkxNode *this)
{
  hkStringPtr *p_m_userProperties; // rcx
  int m_capacityAndFlags; // r8d
  int v4; // edi
  hkStringPtr *p_m_description; // rsi
  int v6; // r8d
  hkRefPtr<hkxNode> *m_data; // rsi
  int v8; // eax
  __int64 i; // rdi
  hkReferencedObject *m_pntr; // rcx
  int v11; // r8d
  int v12; // r8d
  hkReferencedObject *v13; // rcx

  p_m_userProperties = &this->m_userProperties;
  p_m_userProperties[-14].m_stringAndFlag = (const char *)&hkxNode::`vftable;
  hkStringPtr::~hkStringPtr(p_m_userProperties);
  m_capacityAndFlags = this->m_linearKeyFrameHints.m_capacityAndFlags;
  this->m_linearKeyFrameHints.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_linearKeyFrameHints.m_data,
      4 * m_capacityAndFlags);
  this->m_linearKeyFrameHints.m_data = 0i64;
  this->m_linearKeyFrameHints.m_capacityAndFlags = 0x80000000;
  v4 = this->m_annotations.m_size - 1;
  if ( v4 >= 0 )
  {
    p_m_description = &this->m_annotations.m_data[v4].m_description;
    do
    {
      hkStringPtr::~hkStringPtr(p_m_description);
      p_m_description -= 2;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v6 = this->m_annotations.m_capacityAndFlags;
  this->m_annotations.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_annotations.m_data,
      16 * v6);
  this->m_annotations.m_data = 0i64;
  this->m_annotations.m_capacityAndFlags = 0x80000000;
  m_data = this->m_children.m_data;
  v8 = this->m_children.m_size - 1;
  for ( i = v8; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  v11 = this->m_children.m_capacityAndFlags;
  this->m_children.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_children.m_data,
      8 * v11);
  this->m_children.m_data = 0i64;
  this->m_children.m_capacityAndFlags = 0x80000000;
  v12 = this->m_keyFrames.m_capacityAndFlags;
  this->m_keyFrames.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_keyFrames.m_data,
      v12 << 6);
  this->m_keyFrames.m_data = 0i64;
  this->m_keyFrames.m_capacityAndFlags = 0x80000000;
  v13 = this->m_object.m_pntr;
  if ( v13 )
    hkReferencedObject::removeReference(v13);
  this->m_object.m_pntr = 0i64;
  hkStringPtr::~hkStringPtr(&this->m_name);
  hkxAttributeHolder::~hkxAttributeHolder(this);
}

// File Line: 17
// RVA: 0xE35830
hkxNode *__fastcall hkxNode::findChildByName(hkxNode *this, const char *childName)
{
  int v5; // ebx
  __int64 i; // rdi
  hkxNode *m_pntr; // rbp

  if ( !childName )
    return 0i64;
  v5 = 0;
  if ( this->m_children.m_size <= 0 )
    return 0i64;
  for ( i = 0i64; ; ++i )
  {
    m_pntr = this->m_children.m_data[i].m_pntr;
    if ( ((unsigned __int64)m_pntr->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != 0
      && !(unsigned int)hkString::strCasecmp(
                          (const char *)((unsigned __int64)m_pntr->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                          childName) )
    {
      break;
    }
    if ( ++v5 >= this->m_children.m_size )
      return 0i64;
  }
  return m_pntr;
}

// File Line: 36
// RVA: 0xE358D0
hkxNode *__fastcall hkxNode::findDescendantByName(hkxNode *this, char *name)
{
  hkxNode *result; // rax
  int v4; // ebx
  __int64 i; // rdi
  hkxNode *m_pntr; // rsi
  char *namea; // [rsp+38h] [rbp+10h]

  namea = name;
  if ( !name )
    return 0i64;
  v4 = 0;
  if ( this->m_children.m_size > 0 )
  {
    for ( i = 0i64; ; ++i )
    {
      m_pntr = this->m_children.m_data[i].m_pntr;
      if ( ((unsigned __int64)m_pntr->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      {
        if ( !(unsigned int)hkString::strCasecmp(
                              (const char *)((unsigned __int64)m_pntr->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                              name) )
          return m_pntr;
        name = namea;
      }
      result = hkxNode::findDescendantByName(m_pntr, name);
      if ( result )
        return result;
      if ( ++v4 >= this->m_children.m_size )
        return 0i64;
      name = namea;
    }
  }
  return 0i64;
}

// File Line: 64
// RVA: 0xE35A20
hkResult *__fastcall hkxNode::getPathToNode(
        hkxNode *this,
        hkResult *result,
        hkxNode *theNode,
        hkArray<hkxNode const *,hkContainerHeapAllocator> *pathOut)
{
  hkxNode *v4; // r10
  hkResult *v6; // r8
  int v8; // ebx
  hkResultEnum m_enum; // eax
  __int64 v11; // rsi
  hkResult *v12; // rcx
  hkResult resulta; // [rsp+40h] [rbp+8h] BYREF
  hkResult *v14; // [rsp+48h] [rbp+10h]
  hkxNode *v15; // [rsp+50h] [rbp+18h]

  v15 = theNode;
  v14 = result;
  v4 = theNode;
  v6 = result;
  if ( pathOut->m_size == (pathOut->m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pathOut->m_data, 8);
    v6 = v14;
    v4 = v15;
  }
  pathOut->m_data[pathOut->m_size++] = this;
  v8 = 0;
  if ( this == v4 )
  {
    v6->m_enum = HK_SUCCESS;
    return v6;
  }
  else
  {
    m_enum = HK_FAILURE;
    if ( this->m_children.m_size <= 0 )
    {
LABEL_9:
      --pathOut->m_size;
    }
    else
    {
      v11 = 0i64;
      while ( 1 )
      {
        m_enum = hkxNode::getPathToNode(this->m_children.m_data[v11].m_pntr, &resulta, v4, pathOut)->m_enum;
        if ( m_enum == HK_SUCCESS )
          break;
        v4 = v15;
        ++v8;
        ++v11;
        if ( v8 >= this->m_children.m_size )
          goto LABEL_9;
      }
    }
    v12 = v14;
    v14->m_enum = m_enum;
    return v12;
  }
}

// File Line: 90
// RVA: 0xE35B70
hkRefVariant *__fastcall hkxNode::findVariantByObject(hkxNode *this, hkRefVariant *result, hkReferencedObject *object)
{
  hkReferencedObject *m_pntr; // rcx
  hkReferencedObject *v5; // rax
  int v8; // ebx
  __int64 v9; // rdi
  hkReferencedObject *v10; // rcx
  hkRefVariant resulta; // [rsp+40h] [rbp+8h] BYREF
  hkReferencedObject *v12; // [rsp+50h] [rbp+18h]

  v12 = object;
  m_pntr = this->m_object.m_pntr;
  v5 = object;
  if ( m_pntr == object )
  {
    if ( m_pntr )
      hkReferencedObject::addReference(m_pntr);
    result->m_pntr = (hkReferencedObject *)this->m_object;
    return result;
  }
  else
  {
    v8 = 0;
    if ( this->m_children.m_size <= 0 )
    {
LABEL_9:
      result->m_pntr = 0i64;
    }
    else
    {
      v9 = 0i64;
      while ( 1 )
      {
        hkxNode::findVariantByObject(this->m_children.m_data[v9].m_pntr, &resulta, v5);
        if ( resulta.m_pntr )
          break;
        v5 = v12;
        ++v8;
        ++v9;
        resulta.m_pntr = 0i64;
        if ( v8 >= this->m_children.m_size )
          goto LABEL_9;
      }
      hkReferencedObject::addReference(resulta.m_pntr);
      v10 = resulta.m_pntr;
      result->m_pntr = resulta.m_pntr;
      if ( v10 )
        hkReferencedObject::removeReference(v10);
    }
    return result;
  }
}

// File Line: 110
// RVA: 0xE35980
void __fastcall hkxNode::replaceAllObjects(hkxNode *this, hkReferencedObject *oldObject, hkReferencedObject *newObject)
{
  hkReferencedObject *m_pntr; // rcx
  hkReferencedObject *v6; // rax
  hkReferencedObject *v7; // rcx
  int v8; // edi
  __int64 v9; // rbp

  m_pntr = this->m_object.m_pntr;
  v6 = oldObject;
  if ( m_pntr == oldObject && m_pntr != newObject )
  {
    if ( newObject )
      hkReferencedObject::addReference(newObject);
    v7 = this->m_object.m_pntr;
    if ( v7 )
      hkReferencedObject::removeReference(v7);
    v6 = oldObject;
    this->m_object.m_pntr = newObject;
  }
  v8 = 0;
  if ( this->m_children.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      hkxNode::replaceAllObjects(this->m_children.m_data[v9].m_pntr, v6, newObject);
      v6 = oldObject;
      ++v8;
      ++v9;
    }
    while ( v8 < this->m_children.m_size );
  }
}

// File Line: 123
// RVA: 0xE35B10
__int64 __fastcall hkxNode::getNumDescendants(hkxNode *this)
{
  int m_size; // ebx
  int v2; // edi
  __int64 v4; // rsi
  int NumDescendants; // eax

  m_size = this->m_children.m_size;
  v2 = 0;
  if ( m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      NumDescendants = hkxNode::getNumDescendants(this->m_children.m_data[v4].m_pntr);
      ++v2;
      ++v4;
      m_size += NumDescendants;
    }
    while ( v2 < this->m_children.m_size );
  }
  return (unsigned int)m_size;
}

