// File Line: 22
// RVA: 0xC74B40
void __fastcall hkRefCountedProperties::hkRefCountedProperties(hkRefCountedProperties *this)
{
  this->m_entries.m_capacityAndFlags = 2147483648;
  this->m_entries.m_data = 0i64;
  this->m_entries.m_size = 0;
}

// File Line: 28
// RVA: 0xC74B60
void __fastcall hkRefCountedProperties::hkRefCountedProperties(hkRefCountedProperties *this, hkRefCountedProperties *other)
{
  this->m_entries.m_capacityAndFlags = 2147483648;
  this->m_entries.m_data = 0i64;
  this->m_entries.m_size = 0;
  hkArrayBase<hkRefCountedProperties::Entry>::_append(
    (hkArrayBase<hkRefCountedProperties::Entry> *)&this->m_entries.m_data,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    other->m_entries.m_data,
    other->m_entries.m_size);
}

// File Line: 37
// RVA: 0xC74BA0
void __fastcall hkRefCountedProperties::hkRefCountedProperties(hkRefCountedProperties *this, hkFinishLoadedObjectFlag flag)
{
  ;
}

// File Line: 43
// RVA: 0xC74BB0
void __fastcall hkRefCountedProperties::~hkRefCountedProperties(hkRefCountedProperties *this)
{
  int v1; // eax
  hkRefCountedProperties *v2; // rsi
  __int64 v3; // rdi
  hkRefCountedProperties::Entry *v4; // rbx
  int v5; // er8

  v1 = this->m_entries.m_size - 1;
  v2 = this;
  v3 = v1;
  if ( v1 >= 0 )
  {
    v4 = &this->m_entries.m_data[v1];
    do
    {
      if ( v4->m_object.m_pntr )
        hkReferencedObject::removeReference(v4->m_object.m_pntr);
      v4->m_object.m_pntr = 0i64;
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = v2->m_entries.m_capacityAndFlags;
  v2->m_entries.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_entries.m_data,
      16 * v5);
  v2->m_entries.m_data = 0i64;
  v2->m_entries.m_capacityAndFlags = 2147483648;
}

// File Line: 49
// RVA: 0xC74E80
void __fastcall hkRefCountedProperties::addPropertyInternal(hkRefCountedProperties *this, unsigned __int16 propertyKey, hkReferencedObject *propertyObject, hkRefCountedProperties::ReferenceCountHandling referenceHandling)
{
  hkRefCountedProperties *v4; // rsi
  int v5; // ecx
  hkReferencedObject *v6; // rdi
  hkRefCountedProperties::ReferenceCountHandling v7; // er14
  unsigned __int16 v8; // bp
  __int64 v9; // r8
  signed __int64 v10; // rbx
  signed __int64 v11; // rax
  hkReferencedObject *v12; // rcx
  bool v13; // zf

  v4 = this;
  v5 = this->m_entries.m_size;
  v6 = propertyObject;
  v7 = referenceHandling;
  v8 = propertyKey;
  v9 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    v10 = (signed __int64)&v4->m_entries.m_data[v5 - 1];
    while ( *(_WORD *)(v10 + 8) != propertyKey )
    {
      v10 -= 16i64;
      if ( --v9 < 0 )
        goto LABEL_5;
    }
    if ( referenceHandling == REFERENCE_COUNT_INCREMENT && v6 )
      hkReferencedObject::addReference(v6);
LABEL_15:
    v12 = *(hkReferencedObject **)v10;
    v13 = *(_QWORD *)v10 == 0i64;
    goto LABEL_18;
  }
LABEL_5:
  if ( v5 == (v4->m_entries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
  v11 = (signed __int64)&v4->m_entries.m_data[v4->m_entries.m_size];
  if ( v11 )
  {
    *(_QWORD *)v11 = 0i64;
    *(_DWORD *)(v11 + 8) = 0xFFFF;
  }
  v10 = (signed __int64)&v4->m_entries.m_data[v4->m_entries.m_size++];
  *(_WORD *)(v10 + 8) = v8;
  if ( v7 == REFERENCE_COUNT_INCREMENT )
  {
    if ( v6 )
    {
      hkReferencedObject::addReference(v6);
      v12 = *(hkReferencedObject **)v10;
      v13 = *(_QWORD *)v10 == 0i64;
      goto LABEL_18;
    }
    goto LABEL_15;
  }
  v12 = *(hkReferencedObject **)v10;
  if ( !*(_QWORD *)v10 )
    goto LABEL_20;
  v13 = v12 == v6;
LABEL_18:
  if ( !v13 )
    hkReferencedObject::removeReference(v12);
LABEL_20:
  *(_QWORD *)v10 = v6;
}

// File Line: 87
// RVA: 0xC74C50
void __fastcall hkRefCountedProperties::removeProperty(hkRefCountedProperties *this, unsigned __int16 propertyKey)
{
  unsigned __int16 v2; // r9
  hkRefCountedProperties *v3; // rdi
  int v4; // ebx
  __int64 v5; // r8
  hkRefCountedProperties::Entry *v6; // rbp
  unsigned __int16 *v7; // rdx
  signed __int64 v8; // rsi
  hkReferencedObject *v9; // rcx
  __int64 v10; // rcx
  signed __int64 v11; // rdx
  hkRefCountedProperties::Entry *v12; // rax
  signed __int64 v13; // r8
  __int64 v14; // rcx

  v2 = propertyKey;
  v3 = this;
  v4 = this->m_entries.m_size - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = this->m_entries.m_data;
    v7 = &this->m_entries.m_data[v4].m_key;
    while ( *v7 != v2 )
    {
      --v4;
      v7 -= 8;
      if ( --v5 < 0 )
        return;
    }
    v8 = v4;
    v9 = v6[v8].m_object.m_pntr;
    if ( v9 )
      hkReferencedObject::removeReference(v9);
    v6[v8].m_object.m_pntr = 0i64;
    v10 = --v3->m_entries.m_size;
    if ( (_DWORD)v10 != v4 )
    {
      v11 = 2i64;
      v12 = &v3->m_entries.m_data[v8];
      v13 = (char *)&v3->m_entries.m_data[v10] - (char *)v12;
      do
      {
        v14 = *(__int64 *)((char *)&v12->m_object.m_pntr + v13);
        v12 = (hkRefCountedProperties::Entry *)((char *)v12 + 8);
        *(_QWORD *)&v12[-1].m_key = v14;
        --v11;
      }
      while ( v11 );
    }
  }
}

// File Line: 102
// RVA: 0xC74D20
void __fastcall hkRefCountedProperties::replaceProperty(hkRefCountedProperties *this, unsigned __int16 propertyKey, hkReferencedObject *newPropertyObject)
{
  hkReferencedObject *v3; // rbp
  unsigned __int16 v4; // r15
  int v5; // eax
  hkRefCountedProperties *v6; // r14
  __int64 v7; // rsi
  signed __int64 v8; // rdi
  hkRefCountedProperties::Entry *v9; // rbx
  hkReferencedObject *v10; // rcx
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkErrStream v13; // [rsp+20h] [rbp-238h]
  char buf; // [rsp+40h] [rbp-218h]

  v3 = newPropertyObject;
  v4 = propertyKey;
  v5 = this->m_entries.m_size - 1;
  v6 = this;
  v7 = v5;
  if ( v5 >= 0 )
  {
    v8 = v5;
    do
    {
      v9 = v6->m_entries.m_data;
      if ( v6->m_entries.m_data[v8].m_key == v4 )
      {
        if ( v3 )
          hkReferencedObject::addReference(v3);
        v10 = v9[v8].m_object.m_pntr;
        if ( v10 )
          hkReferencedObject::removeReference(v10);
        v9[v8].m_object.m_pntr = v3;
      }
      --v8;
      --v7;
    }
    while ( v7 >= 0 );
  }
  hkErrStream::hkErrStream(&v13, &buf, 512);
  v11 = hkOstream::operator<<((hkOstream *)&v13.vfptr, "Failed to locate key ");
  v12 = hkOstream::operator<<(v11, v4, (int)v11);
  hkOstream::operator<<(v12, " among the existing properties!");
  hkError::messageWarning(487709421, &buf, "Types\\Properties\\hkRefCountedProperties.cpp", 112);
  hkOstream::~hkOstream((hkOstream *)&v13.vfptr);
}

// File Line: 121
// RVA: 0xC74E30
hkReferencedObject *__fastcall hkRefCountedProperties::accessProperty(hkRefCountedProperties *this, unsigned __int16 propertyKey)
{
  hkRefCountedProperties::Entry *v2; // r11
  unsigned __int16 v3; // r10
  int v4; // er9
  __int64 v5; // rcx
  unsigned __int16 *v6; // rdx

  v2 = this->m_entries.m_data;
  v3 = propertyKey;
  v4 = this->m_entries.m_size - 1;
  v5 = v4;
  if ( v4 < 0 )
    return 0i64;
  v6 = &v2[v4].m_key;
  while ( *v6 != v3 )
  {
    --v4;
    v6 -= 8;
    if ( --v5 < 0 )
      return 0i64;
  }
  return v2[v4].m_object.m_pntr;
}

