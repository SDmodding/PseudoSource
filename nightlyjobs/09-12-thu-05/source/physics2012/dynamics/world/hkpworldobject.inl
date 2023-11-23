// File Line: 16
// RVA: 0xD4F790
void __fastcall hkpWorldObject::~hkpWorldObject(hkpWorldObject *this)
{
  hkpShape *m_shape; // rcx
  int m_capacityAndFlags; // r8d
  int v4; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldObject::`vftable;
  m_shape = this->m_collidable.m_shape;
  if ( m_shape )
    hkReferencedObject::removeReference(m_shape);
  m_capacityAndFlags = this->m_properties.m_capacityAndFlags;
  this->m_properties.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_properties.m_data,
      16 * m_capacityAndFlags);
  this->m_properties.m_data = 0i64;
  this->m_properties.m_capacityAndFlags = 0x80000000;
  hkStringPtr::~hkStringPtr(&this->m_name);
  v4 = this->m_collidable.m_collisionEntries.m_capacityAndFlags;
  this->m_collidable.m_collisionEntries.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_collidable.m_collisionEntries.m_data,
      16 * v4);
  this->m_collidable.m_collisionEntries.m_data = 0i64;
  this->m_collidable.m_collisionEntries.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 196
// RVA: 0xD63870
void __fastcall hkpWorldObject::copyProperties(hkpWorldObject *this, hkpWorldObject *otherObj)
{
  int m_size; // edi
  hkArray<hkSimpleProperty,hkContainerHeapAllocator> *p_m_properties; // rbx
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // r9d
  char *m_data; // rcx
  signed __int64 v10; // r8
  __int64 v11; // rdx
  __int64 v12; // rax
  hkSimpleProperty *v13; // rax
  __int64 v14; // rdx
  char *v15; // r8
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  m_size = otherObj->m_properties.m_size;
  p_m_properties = &this->m_properties;
  v5 = m_size;
  if ( m_size > this->m_properties.m_size )
    v5 = this->m_properties.m_size;
  v6 = this->m_properties.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < m_size )
  {
    v7 = 2 * v6;
    v8 = otherObj->m_properties.m_size;
    if ( m_size < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_properties->m_data, v8, 16);
  }
  m_data = (char *)p_m_properties->m_data;
  if ( v5 > 0 )
  {
    v10 = (char *)otherObj->m_properties.m_data - m_data;
    v11 = v5;
    do
    {
      v12 = *(_QWORD *)&m_data[v10];
      m_data += 16;
      *((_QWORD *)m_data - 2) = v12;
      *((_QWORD *)m_data - 1) = *(_QWORD *)&m_data[v10 - 8];
      --v11;
    }
    while ( v11 );
  }
  v13 = &p_m_properties->m_data[v5];
  v14 = m_size - v5;
  if ( m_size - v5 > 0 )
  {
    v15 = (char *)((char *)otherObj->m_properties.m_data - (char *)p_m_properties->m_data);
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
  p_m_properties->m_size = m_size;
}

