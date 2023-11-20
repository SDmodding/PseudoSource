// File Line: 12
// RVA: 0xE35690
void __fastcall hkxNode::~hkxNode(hkxNode *this)
{
  hkxNode *v1; // rbx
  hkStringPtr *v2; // rcx
  int v3; // er8
  int v4; // edi
  hkStringPtr *v5; // rsi
  int v6; // er8
  hkRefPtr<hkxNode> *v7; // rsi
  int v8; // eax
  __int64 i; // rdi
  hkReferencedObject *v10; // rcx
  int v11; // er8
  int v12; // er8
  hkReferencedObject *v13; // rcx

  v1 = this;
  v2 = &this->m_userProperties;
  v2[-14].m_stringAndFlag = (const char *)&hkxNode::`vftable';
  hkStringPtr::~hkStringPtr(v2);
  v3 = v1->m_linearKeyFrameHints.m_capacityAndFlags;
  v1->m_linearKeyFrameHints.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_linearKeyFrameHints.m_data,
      4 * v3);
  v1->m_linearKeyFrameHints.m_data = 0i64;
  v1->m_linearKeyFrameHints.m_capacityAndFlags = 2147483648;
  v4 = v1->m_annotations.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &v1->m_annotations.m_data[v4].m_description;
    do
    {
      hkStringPtr::~hkStringPtr(v5);
      v5 -= 2;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v6 = v1->m_annotations.m_capacityAndFlags;
  v1->m_annotations.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_annotations.m_data,
      16 * v6);
  v1->m_annotations.m_data = 0i64;
  v1->m_annotations.m_capacityAndFlags = 2147483648;
  v7 = v1->m_children.m_data;
  v8 = v1->m_children.m_size - 1;
  for ( i = v8; i >= 0; v7[i--].m_pntr = 0i64 )
  {
    v10 = (hkReferencedObject *)&v7[i].m_pntr->vfptr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = v1->m_children.m_capacityAndFlags;
  v1->m_children.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_children.m_data,
      8 * v11);
  v1->m_children.m_data = 0i64;
  v1->m_children.m_capacityAndFlags = 2147483648;
  v12 = v1->m_keyFrames.m_capacityAndFlags;
  v1->m_keyFrames.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_keyFrames.m_data,
      v12 << 6);
  v1->m_keyFrames.m_data = 0i64;
  v1->m_keyFrames.m_capacityAndFlags = 2147483648;
  v13 = v1->m_object.m_pntr;
  if ( v13 )
    hkReferencedObject::removeReference(v13);
  v1->m_object.m_pntr = 0i64;
  hkStringPtr::~hkStringPtr(&v1->m_name);
  hkxAttributeHolder::~hkxAttributeHolder((hkxAttributeHolder *)&v1->vfptr);
}

// File Line: 17
// RVA: 0xE35830
hkxNode *__fastcall hkxNode::findChildByName(hkxNode *this, const char *childName)
{
  const char *v2; // r14
  hkxNode *v3; // rsi
  int v5; // ebx
  __int64 v6; // rdi
  hkxNode *v7; // rbp

  v2 = childName;
  v3 = this;
  if ( !childName )
    return 0i64;
  v5 = 0;
  if ( this->m_children.m_size <= 0 )
    return 0i64;
  v6 = 0i64;
  while ( 1 )
  {
    v7 = v3->m_children.m_data[v6].m_pntr;
    if ( (_QWORD)v7->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( !(unsigned int)hkString::strCasecmp(
                            (const char *)((_QWORD)v7->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                            v2) )
        break;
    }
    ++v5;
    ++v6;
    if ( v5 >= v3->m_children.m_size )
      return 0i64;
  }
  return v7;
}

// File Line: 36
// RVA: 0xE358D0
hkxNode *__fastcall hkxNode::findDescendantByName(hkxNode *this, const char *name)
{
  hkxNode *v2; // rbp
  hkxNode *result; // rax
  int v4; // ebx
  __int64 v5; // rdi
  hkxNode *v6; // rsi
  char *namea; // [rsp+38h] [rbp+10h]

  namea = (char *)name;
  v2 = this;
  if ( !name )
    return 0i64;
  v4 = 0;
  if ( this->m_children.m_size > 0 )
  {
    v5 = 0i64;
    while ( 1 )
    {
      v6 = v2->m_children.m_data[v5].m_pntr;
      if ( (_QWORD)v6->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64 )
      {
        if ( !(unsigned int)hkString::strCasecmp(
                              (const char *)((_QWORD)v6->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                              name) )
          return v6;
        name = namea;
      }
      result = hkxNode::findDescendantByName(v6, name);
      if ( result )
        return result;
      ++v4;
      ++v5;
      if ( v4 >= v2->m_children.m_size )
        return 0i64;
      name = namea;
    }
  }
  return 0i64;
}

// File Line: 64
// RVA: 0xE35A20
hkResult *__fastcall hkxNode::getPathToNode(hkxNode *this, hkResult *result, hkxNode *theNode, hkArray<hkxNode const *,hkContainerHeapAllocator> *pathOut)
{
  hkxNode *v4; // r10
  hkArray<hkxNode const *,hkContainerHeapAllocator> *v5; // rdi
  hkResult *v6; // r8
  hkxNode *v7; // rbp
  int v8; // ebx
  hkResult *v9; // rax
  hkResultEnum v10; // eax
  __int64 v11; // rsi
  hkResult *v12; // rcx
  hkResult resulta; // [rsp+40h] [rbp+8h]
  hkResult *v14; // [rsp+48h] [rbp+10h]
  hkxNode *v15; // [rsp+50h] [rbp+18h]

  v15 = theNode;
  v14 = result;
  v4 = theNode;
  v5 = pathOut;
  v6 = result;
  v7 = this;
  if ( pathOut->m_size == (pathOut->m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, pathOut, 8);
    v6 = v14;
    v4 = v15;
  }
  v5->m_data[v5->m_size++] = v7;
  v8 = 0;
  if ( v7 == v4 )
  {
    v6->m_enum = 0;
    v9 = v6;
  }
  else
  {
    v10 = 1;
    if ( v7->m_children.m_size <= 0 )
    {
LABEL_9:
      --v5->m_size;
    }
    else
    {
      v11 = 0i64;
      while ( 1 )
      {
        v10 = hkxNode::getPathToNode(v7->m_children.m_data[v11].m_pntr, &resulta, v4, v5)->m_enum;
        if ( v10 == HK_SUCCESS )
          break;
        v4 = v15;
        ++v8;
        ++v11;
        if ( v8 >= v7->m_children.m_size )
          goto LABEL_9;
      }
    }
    v12 = v14;
    v14->m_enum = v10;
    v9 = v12;
  }
  return v9;
}

// File Line: 90
// RVA: 0xE35B70
hkRefVariant *__fastcall hkxNode::findVariantByObject(hkxNode *this, hkRefVariant *result, hkReferencedObject *object)
{
  hkxNode *v3; // rsi
  hkReferencedObject *v4; // rcx
  hkReferencedObject *v5; // rax
  hkRefVariant *v6; // rbp
  hkRefVariant *v7; // rax
  int v8; // ebx
  __int64 v9; // rdi
  hkReferencedObject *v10; // rcx
  hkRefVariant resulta; // [rsp+40h] [rbp+8h]
  hkReferencedObject *v12; // [rsp+50h] [rbp+18h]

  v12 = object;
  v3 = this;
  v4 = this->m_object.m_pntr;
  v5 = object;
  v6 = result;
  if ( v4 == object )
  {
    if ( v4 )
      hkReferencedObject::addReference(v4);
    v6->m_pntr = (hkReferencedObject *)v3->m_object;
    v7 = v6;
  }
  else
  {
    v8 = 0;
    if ( v3->m_children.m_size <= 0 )
    {
LABEL_9:
      v6->m_pntr = 0i64;
    }
    else
    {
      v9 = 0i64;
      while ( 1 )
      {
        hkxNode::findVariantByObject(v3->m_children.m_data[v9].m_pntr, &resulta, v5);
        if ( resulta.m_pntr )
          break;
        v5 = v12;
        ++v8;
        ++v9;
        if ( v8 >= v3->m_children.m_size )
          goto LABEL_9;
      }
      hkReferencedObject::addReference(resulta.m_pntr);
      v10 = resulta.m_pntr;
      v6->m_pntr = resulta.m_pntr;
      if ( v10 )
        hkReferencedObject::removeReference(v10);
    }
    v7 = v6;
  }
  return v7;
}

// File Line: 110
// RVA: 0xE35980
void __fastcall hkxNode::replaceAllObjects(hkxNode *this, hkReferencedObject *oldObject, hkReferencedObject *newObject)
{
  hkxNode *v3; // rbx
  hkReferencedObject *v4; // rcx
  hkReferencedObject *v5; // rsi
  hkReferencedObject *v6; // rax
  hkReferencedObject *v7; // rcx
  int v8; // edi
  __int64 v9; // rbp
  hkReferencedObject *v10; // [rsp+38h] [rbp+10h]

  v10 = oldObject;
  v3 = this;
  v4 = this->m_object.m_pntr;
  v5 = newObject;
  v6 = oldObject;
  if ( v4 == oldObject && v4 != newObject )
  {
    if ( newObject )
      hkReferencedObject::addReference(newObject);
    v7 = v3->m_object.m_pntr;
    if ( v7 )
      hkReferencedObject::removeReference(v7);
    v6 = v10;
    v3->m_object.m_pntr = v5;
  }
  v8 = 0;
  if ( v3->m_children.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      hkxNode::replaceAllObjects(v3->m_children.m_data[v9].m_pntr, v6, v5);
      v6 = v10;
      ++v8;
      ++v9;
    }
    while ( v8 < v3->m_children.m_size );
  }
}

// File Line: 123
// RVA: 0xE35B10
__int64 __fastcall hkxNode::getNumDescendants(hkxNode *this)
{
  int v1; // ebx
  int v2; // edi
  hkxNode *v3; // rbp
  __int64 v4; // rsi
  int v5; // eax

  v1 = this->m_children.m_size;
  v2 = 0;
  v3 = this;
  if ( v1 > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = hkxNode::getNumDescendants(v3->m_children.m_data[v4].m_pntr);
      ++v2;
      ++v4;
      v1 += v5;
    }
    while ( v2 < v3->m_children.m_size );
  }
  return (unsigned int)v1;
}

