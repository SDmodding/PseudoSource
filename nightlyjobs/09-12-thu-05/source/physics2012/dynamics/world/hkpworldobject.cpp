// File Line: 26
// RVA: 0xD55550
void __fastcall hkpWorldObject::hkpWorldObject(hkpWorldObject *this, hkFinishLoadedObjectFlag flag)
{
  char v2; // di
  hkpLinkedCollidable *p_m_collidable; // rbx

  v2 = (char)this;
  p_m_collidable = &this->m_collidable;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldObject::`vftable;
  if ( flag.m_finishing )
  {
    *(_DWORD *)&this->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs = 0;
    this->m_collidable.m_boundingVolumeData.m_childShapeAabbs = 0i64;
    this->m_collidable.m_boundingVolumeData.m_childShapeKeys = 0i64;
    this->m_collidable.m_boundingVolumeData.m_min[0] = 1;
    this->m_collidable.m_boundingVolumeData.m_max[0] = 0;
    this->m_collidable.m_broadPhaseHandle.m_ownerOffset = -36;
  }
  this->m_collidable.m_collisionEntries.m_data = 0i64;
  this->m_collidable.m_collisionEntries.m_size = 0;
  this->m_collidable.m_collisionEntries.m_capacityAndFlags = 0x80000000;
  this->m_multiThreadCheck.m_threadId = -15;
  this->m_multiThreadCheck.m_markCount = 0x8000;
  hkStringPtr::hkStringPtr(&this->m_name, flag);
  if ( flag.m_finishing )
    p_m_collidable->m_ownerOffset = v2 - (_BYTE)p_m_collidable;
}

// File Line: 38
// RVA: 0xD55490
void __fastcall hkpWorldObject::hkpWorldObject(hkpWorldObject *this, hkpShape *shape, int type)
{
  hkpLinkedCollidable *p_m_collidable; // rbx

  p_m_collidable = &this->m_collidable;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldObject::`vftable;
  this->m_world = 0i64;
  this->m_userData = 0i64;
  hkpLinkedCollidable::hkpLinkedCollidable(&this->m_collidable, shape, 0i64, type);
  this->m_multiThreadCheck.m_threadId = -15;
  this->m_multiThreadCheck.m_markCount = 0x8000;
  hkStringPtr::hkStringPtr(&this->m_name);
  this->m_properties.m_data = 0i64;
  this->m_properties.m_size = 0;
  this->m_properties.m_capacityAndFlags = 0x80000000;
  p_m_collidable->m_ownerOffset = (_BYTE)this - (_BYTE)p_m_collidable;
  if ( shape )
    hkReferencedObject::addReference(shape);
}

// File Line: 48
// RVA: 0xD55440
__int64 __fastcall hkpWorldObject::setShape(hkpWorldObject *this, hkpShape *shape)
{
  return 1i64;
}

// File Line: 76
// RVA: 0xD55450
__int64 __fastcall hkpWorldObject::updateShape(hkpWorldObject *this, hkpShapeModifier *shapeModifier)
{
  return 1i64;
}

// File Line: 83
// RVA: 0xD55190
void __fastcall hkpWorldObject::addProperty(hkpWorldObject *this, unsigned int key, hkSimplePropertyValue value)
{
  __int64 m_size; // r10
  __int64 v4; // r9
  hkSimpleProperty *v6; // rax
  hkArray<hkSimpleProperty,hkContainerHeapAllocator> *p_m_properties; // rbx
  __int64 v8; // rcx
  unsigned __int64 m_data; // [rsp+40h] [rbp+18h]

  m_data = value.m_data;
  m_size = this->m_properties.m_size;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    p_m_properties = &this->m_properties;
    if ( this->m_properties.m_size == (this->m_properties.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_properties->m_data, 16);
      value.m_data = m_data;
    }
    v8 = (__int64)&p_m_properties->m_data[p_m_properties->m_size++];
    *(hkSimplePropertyValue *)(v8 + 8) = value;
    *(_DWORD *)v8 = key;
  }
  else
  {
    v6 = this->m_properties.m_data;
    while ( v6->m_key != key )
    {
      ++v4;
      ++v6;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
}

// File Line: 101
// RVA: 0xD552E0
void __fastcall hkpWorldObject::setProperty(hkpWorldObject *this, unsigned int key, hkSimplePropertyValue value)
{
  __int64 m_size; // r11
  int v4; // r10d
  __int64 v6; // r9
  hkSimpleProperty *v7; // rax
  hkArray<hkSimpleProperty,hkContainerHeapAllocator> *p_m_properties; // rbx
  __int64 v9; // rcx
  unsigned __int64 m_data; // [rsp+40h] [rbp+18h]

  m_data = value.m_data;
  m_size = this->m_properties.m_size;
  v4 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    p_m_properties = &this->m_properties;
    if ( this->m_properties.m_size == (this->m_properties.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_properties->m_data, 16);
      value.m_data = m_data;
    }
    v9 = (__int64)&p_m_properties->m_data[p_m_properties->m_size++];
    *(hkSimplePropertyValue *)(v9 + 8) = value;
    *(_DWORD *)v9 = key;
  }
  else
  {
    v7 = this->m_properties.m_data;
    while ( v7->m_key != key )
    {
      ++v6;
      ++v4;
      ++v7;
      if ( v6 >= m_size )
        goto LABEL_5;
    }
    this->m_properties.m_data[v4].m_value = value;
  }
}

// File Line: 119
// RVA: 0xD55220
hkSimplePropertyValue *__fastcall hkpWorldObject::removeProperty(
        hkpWorldObject *this,
        hkSimplePropertyValue *result,
        unsigned int key)
{
  __int64 m_size; // rdx
  int v5; // r10d
  __int64 v6; // r9
  hkSimpleProperty *m_data; // rbx
  hkSimpleProperty *v8; // rax
  unsigned __int64 v10; // rax
  int v11; // r8d
  hkSimpleProperty *v12; // rcx
  int v13; // r8d
  __int64 v14; // r8
  unsigned __int64 v15; // rdx

  m_size = this->m_properties.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    result->m_data = 0i64;
    return result;
  }
  else
  {
    m_data = this->m_properties.m_data;
    v8 = m_data;
    while ( v8->m_key != key )
    {
      ++v6;
      ++v5;
      ++v8;
      if ( v6 >= m_size )
        goto LABEL_5;
    }
    v10 = m_data[v5].m_value.m_data;
    v11 = --this->m_properties.m_size;
    v12 = &m_data[v5];
    v13 = 16 * (v11 - v5);
    if ( v13 > 0 )
    {
      v14 = ((unsigned int)(v13 - 1) >> 3) + 1;
      do
      {
        v15 = *(_QWORD *)&v12[1].m_key;
        v12 = (hkSimpleProperty *)((char *)v12 + 8);
        v12[-1].m_value.m_data = v15;
        --v14;
      }
      while ( v14 );
    }
    result->m_data = v10;
    return result;
  }
}

// File Line: 141
// RVA: 0xD55390
void __fastcall hkpWorldObject::editProperty(
        hkpWorldObject *this,
        unsigned int key,
        hkSimplePropertyValue value,
        hkpWorldObject::MtChecks mtCheck)
{
  __int64 m_size; // r11
  int v5; // r10d
  __int64 v6; // r9
  hkSimpleProperty *m_data; // rcx
  hkSimpleProperty *i; // rax

  m_size = this->m_properties.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( m_size > 0 )
  {
    m_data = this->m_properties.m_data;
    for ( i = m_data; i->m_key != key; ++i )
    {
      ++v6;
      ++v5;
      if ( v6 >= m_size )
        return;
    }
    m_data[v5].m_value = value;
  }
}

// File Line: 162
// RVA: 0xD553E0
void __fastcall hkpWorldObject::lockProperty(hkpWorldObject *this, unsigned int key)
{
  hkpWorld *m_world; // rcx
  _RTL_CRITICAL_SECTION *p_m_section; // rcx

  m_world = this->m_world;
  if ( m_world )
  {
    p_m_section = &m_world->m_propertyMasterLock->m_section;
    if ( p_m_section )
      EnterCriticalSection(p_m_section);
  }
}

// File Line: 172
// RVA: 0xD55410
void __fastcall hkpWorldObject::unlockProperty(hkpWorldObject *this, unsigned int key)
{
  hkpWorld *m_world; // rcx
  _RTL_CRITICAL_SECTION *p_m_section; // rcx

  m_world = this->m_world;
  if ( m_world )
  {
    p_m_section = &m_world->m_propertyMasterLock->m_section;
    if ( p_m_section )
      LeaveCriticalSection(p_m_section);
  }
}

// File Line: 181
// RVA: 0xD55460
void __fastcall hkpWorldObject::markForWriteImpl(hkpWorldObject *this)
{
  ;
}

// File Line: 192
// RVA: 0xD55470
void __fastcall hkpWorldObject::checkReadWrite(hkpWorldObject *this)
{
  ;
}

// File Line: 197
// RVA: 0xD55480
void __fastcall hkpWorldObject::checkReadOnly(hkpWorldObject *this)
{
  ;
}

