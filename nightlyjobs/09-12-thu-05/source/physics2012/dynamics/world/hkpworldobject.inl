// File Line: 16
// RVA: 0xD4F790
void __fastcall hkpWorldObject::~hkpWorldObject(hkpWorldObject *this)
{
  hkpWorldObject *v1; // rbx
  hkpShape *v2; // rcx
  int v3; // er8
  int v4; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldObject::`vftable;
  v2 = this->m_collidable.m_shape;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v3 = v1->m_properties.m_capacityAndFlags;
  v1->m_properties.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_properties.m_data,
      16 * v3);
  v1->m_properties.m_data = 0i64;
  v1->m_properties.m_capacityAndFlags = 2147483648;
  hkStringPtr::~hkStringPtr(&v1->m_name);
  v4 = v1->m_collidable.m_collisionEntries.m_capacityAndFlags;
  v1->m_collidable.m_collisionEntries.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_collidable.m_collisionEntries.m_data,
      16 * v4);
  v1->m_collidable.m_collisionEntries.m_data = 0i64;
  v1->m_collidable.m_collisionEntries.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 196
// RVA: 0xD63870
void __fastcall hkpWorldObject::copyProperties(hkpWorldObject *this, hkpWorldObject *otherObj)
{
  int v2; // edi
  hkArray<hkSimpleProperty,hkContainerHeapAllocator> *v3; // rbx
  hkpWorldObject *v4; // rbp
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // er9
  hkSimpleProperty *v9; // rcx
  char *v10; // r8
  __int64 v11; // rdx
  __int64 v12; // rax
  hkSimpleProperty *v13; // rax
  __int64 v14; // rdx
  char *v15; // r8
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = otherObj->m_properties.m_size;
  v3 = &this->m_properties;
  v4 = otherObj;
  v5 = otherObj->m_properties.m_size;
  if ( v2 > this->m_properties.m_size )
    v5 = this->m_properties.m_size;
  v6 = this->m_properties.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < v2 )
  {
    v7 = 2 * v6;
    v8 = otherObj->m_properties.m_size;
    if ( v2 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v8, 16);
  }
  v9 = v3->m_data;
  if ( v5 > 0 )
  {
    v10 = (char *)((char *)v4->m_properties.m_data - (char *)v9);
    v11 = v5;
    do
    {
      v12 = *(_QWORD *)((char *)&v9->m_key + (_QWORD)v10);
      ++v9;
      *(_QWORD *)&v9[-1].m_key = v12;
      v9[-1].m_value.m_data = *(_QWORD *)((char *)v9 + (_QWORD)v10 - 8);
      --v11;
    }
    while ( v11 );
  }
  v13 = &v3->m_data[v5];
  v14 = v2 - v5;
  if ( v2 - v5 > 0 )
  {
    v15 = (char *)((char *)v4->m_properties.m_data - (char *)v3->m_data);
    do
    {
      if ( v13 )
      {
        *(_QWORD *)&v13->m_key = *(_QWORD *)((char *)&v13->m_key + (_QWORD)v15);
        v13->m_value.m_data = *(unsigned __int64 *)((char *)&v13->m_value.m_data + (_QWORD)v15);
      }
      ++v13;
      --v14;
    }
    while ( v14 );
  }
  v3->m_size = v2;
}

