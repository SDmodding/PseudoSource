// File Line: 26
// RVA: 0xD55550
void __fastcall hkpWorldObject::hkpWorldObject(hkpWorldObject *this, hkFinishLoadedObjectFlag flag)
{
  char v2; // di
  hkpLinkedCollidable *v3; // rbx
  int v4; // [rsp+38h] [rbp+10h]

  v4 = flag.m_finishing;
  v2 = (char)this;
  v3 = &this->m_collidable;
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
  this->m_collidable.m_collisionEntries.m_capacityAndFlags = 2147483648;
  this->m_multiThreadCheck.m_threadId = -15;
  this->m_multiThreadCheck.m_markCount = -32768;
  hkStringPtr::hkStringPtr(&this->m_name, flag);
  if ( v4 )
    v3->m_ownerOffset = v2 - (_BYTE)v3;
}

// File Line: 38
// RVA: 0xD55490
void __fastcall hkpWorldObject::hkpWorldObject(hkpWorldObject *this, hkpShape *shape, hkpWorldObject::BroadPhaseType type)
{
  hkpLinkedCollidable *v3; // rbx
  hkpWorldObject *v4; // rdi
  hkpShape *v5; // rsi

  v3 = &this->m_collidable;
  v4 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldObject::`vftable;
  this->m_world = 0i64;
  this->m_userData = 0i64;
  v5 = shape;
  hkpLinkedCollidable::hkpLinkedCollidable(&this->m_collidable, shape, 0i64, type);
  v4->m_multiThreadCheck.m_threadId = -15;
  v4->m_multiThreadCheck.m_markCount = -32768;
  hkStringPtr::hkStringPtr(&v4->m_name);
  v4->m_properties.m_data = 0i64;
  v4->m_properties.m_size = 0;
  v4->m_properties.m_capacityAndFlags = 2147483648;
  v3->m_ownerOffset = (_BYTE)v4 - (_BYTE)v3;
  if ( v5 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
}

// File Line: 48
// RVA: 0xD55440
signed __int64 __fastcall hkpWorldObject::setShape(hkpWorldObject *this, hkpShape *shape)
{
  return 1i64;
}

// File Line: 76
// RVA: 0xD55450
signed __int64 __fastcall hkpWorldObject::updateShape(hkpWorldObject *this, hkpShapeModifier *shapeModifier)
{
  return 1i64;
}

// File Line: 83
// RVA: 0xD55190
void __fastcall hkpWorldObject::addProperty(hkpWorldObject *this, unsigned int key, hkSimplePropertyValue value)
{
  __int64 v3; // r10
  __int64 v4; // r9
  unsigned int v5; // edi
  hkSimpleProperty *v6; // rax
  hkArray<hkSimpleProperty,hkContainerHeapAllocator> *v7; // rbx
  signed __int64 v8; // rcx
  unsigned __int64 v9; // [rsp+40h] [rbp+18h]

  v9 = value.m_data;
  v3 = this->m_properties.m_size;
  v4 = 0i64;
  v5 = key;
  if ( v3 <= 0 )
  {
LABEL_5:
    v7 = &this->m_properties;
    if ( this->m_properties.m_size == (this->m_properties.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
      value.m_data = v9;
    }
    v8 = (signed __int64)&v7->m_data[v7->m_size++];
    *(hkSimplePropertyValue *)(v8 + 8) = value;
    *(_DWORD *)v8 = v5;
  }
  else
  {
    v6 = this->m_properties.m_data;
    while ( v6->m_key != key )
    {
      ++v4;
      ++v6;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
  }
}

// File Line: 101
// RVA: 0xD552E0
void __fastcall hkpWorldObject::setProperty(hkpWorldObject *this, unsigned int key, hkSimplePropertyValue value)
{
  __int64 v3; // r11
  int v4; // er10
  unsigned int v5; // edi
  __int64 v6; // r9
  hkSimpleProperty *v7; // rax
  hkArray<hkSimpleProperty,hkContainerHeapAllocator> *v8; // rbx
  signed __int64 v9; // rcx
  unsigned __int64 v10; // [rsp+40h] [rbp+18h]

  v10 = value.m_data;
  v3 = this->m_properties.m_size;
  v4 = 0;
  v5 = key;
  v6 = 0i64;
  if ( v3 <= 0 )
  {
LABEL_5:
    v8 = &this->m_properties;
    if ( this->m_properties.m_size == (this->m_properties.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 16);
      value.m_data = v10;
    }
    v9 = (signed __int64)&v8->m_data[v8->m_size++];
    *(hkSimplePropertyValue *)(v9 + 8) = value;
    *(_DWORD *)v9 = v5;
  }
  else
  {
    v7 = this->m_properties.m_data;
    while ( v7->m_key != key )
    {
      ++v6;
      ++v4;
      ++v7;
      if ( v6 >= v3 )
        goto LABEL_5;
    }
    this->m_properties.m_data[v4].m_value = value;
  }
}

// File Line: 119
// RVA: 0xD55220
hkSimplePropertyValue *__fastcall hkpWorldObject::removeProperty(hkpWorldObject *this, hkSimplePropertyValue *result, unsigned int key)
{
  hkSimplePropertyValue *v3; // r11
  __int64 v4; // rdx
  int v5; // er10
  __int64 v6; // r9
  hkSimpleProperty *v7; // rbx
  hkSimpleProperty *v8; // rax
  hkSimplePropertyValue *v9; // rax
  __int64 v10; // ST00_8
  unsigned __int64 v11; // rax
  int v12; // er8
  signed __int64 v13; // rcx
  int v14; // er8
  __int64 v15; // r8
  __int64 v16; // rdx

  v3 = result;
  v4 = this->m_properties.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( v4 <= 0 )
  {
LABEL_5:
    v3->m_data = 0i64;
    v9 = v3;
  }
  else
  {
    v7 = this->m_properties.m_data;
    v8 = this->m_properties.m_data;
    while ( v8->m_key != key )
    {
      ++v6;
      ++v5;
      ++v8;
      if ( v6 >= v4 )
        goto LABEL_5;
    }
    v10 = *(_QWORD *)&v7[v5].m_key;
    v11 = v7[v5].m_value.m_data;
    v12 = --this->m_properties.m_size;
    v13 = (signed __int64)&v7[v5];
    v14 = 16 * (v12 - v5);
    if ( v14 > 0 )
    {
      v15 = ((unsigned int)(v14 - 1) >> 3) + 1;
      do
      {
        v16 = *(_QWORD *)(v13 + 16);
        v13 += 8i64;
        *(_QWORD *)(v13 - 8) = v16;
        --v15;
      }
      while ( v15 );
    }
    v3->m_data = v11;
    v9 = v3;
  }
  return v9;
}

// File Line: 141
// RVA: 0xD55390
void __fastcall hkpWorldObject::editProperty(hkpWorldObject *this, unsigned int key, hkSimplePropertyValue value, hkpWorldObject::MtChecks mtCheck)
{
  __int64 v4; // r11
  int v5; // er10
  __int64 v6; // r9
  hkSimpleProperty *v7; // rcx
  hkSimpleProperty *v8; // rax

  v4 = this->m_properties.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( v4 > 0 )
  {
    v7 = this->m_properties.m_data;
    v8 = v7;
    while ( v8->m_key != key )
    {
      ++v6;
      ++v5;
      ++v8;
      if ( v6 >= v4 )
        return;
    }
    v7[v5].m_value = value;
  }
}

// File Line: 162
// RVA: 0xD553E0
void __fastcall hkpWorldObject::lockProperty(hkpWorldObject *this, unsigned int key)
{
  hkpWorld *v2; // rcx
  _RTL_CRITICAL_SECTION *v3; // rcx

  v2 = this->m_world;
  if ( v2 )
  {
    v3 = &v2->m_propertyMasterLock->m_section;
    if ( v3 )
      EnterCriticalSection(v3);
  }
}

// File Line: 172
// RVA: 0xD55410
void __fastcall hkpWorldObject::unlockProperty(hkpWorldObject *this, unsigned int key)
{
  hkpWorld *v2; // rcx
  _RTL_CRITICAL_SECTION *v3; // rcx

  v2 = this->m_world;
  if ( v2 )
  {
    v3 = &v2->m_propertyMasterLock->m_section;
    if ( v3 )
      LeaveCriticalSection(v3);
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

