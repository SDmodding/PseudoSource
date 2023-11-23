// File Line: 22
// RVA: 0xC74B40
void __fastcall hkRefCountedProperties::hkRefCountedProperties(hkRefCountedProperties *this)
{
  this->m_entries.m_capacityAndFlags = 0x80000000;
  this->m_entries.m_data = 0i64;
  this->m_entries.m_size = 0;
}

// File Line: 28
// RVA: 0xC74B60
void __fastcall hkRefCountedProperties::hkRefCountedProperties(
        hkRefCountedProperties *this,
        hkRefCountedProperties *other)
{
  this->m_entries.m_capacityAndFlags = 0x80000000;
  this->m_entries.m_data = 0i64;
  this->m_entries.m_size = 0;
  hkArrayBase<hkRefCountedProperties::Entry>::_append(
    &this->m_entries,
    &hkContainerHeapAllocator::s_alloc,
    other->m_entries.m_data,
    other->m_entries.m_size);
}

// File Line: 37
// RVA: 0xC74BA0
void __fastcall hkRefCountedProperties::hkRefCountedProperties(
        hkRefCountedProperties *this,
        hkFinishLoadedObjectFlag flag)
{
  ;
}

// File Line: 43
// RVA: 0xC74BB0
void __fastcall hkRefCountedProperties::~hkRefCountedProperties(hkRefCountedProperties *this)
{
  int v1; // eax
  __int64 v3; // rdi
  hkRefCountedProperties::Entry *v4; // rbx
  int m_capacityAndFlags; // r8d

  v1 = this->m_entries.m_size - 1;
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
  m_capacityAndFlags = this->m_entries.m_capacityAndFlags;
  this->m_entries.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_entries.m_data,
      16 * m_capacityAndFlags);
  this->m_entries.m_data = 0i64;
  this->m_entries.m_capacityAndFlags = 0x80000000;
}

// File Line: 49
// RVA: 0xC74E80
void __fastcall hkRefCountedProperties::addPropertyInternal(
        hkRefCountedProperties *this,
        unsigned __int16 propertyKey,
        hkReferencedObject *propertyObject,
        hkRefCountedProperties::ReferenceCountHandling referenceHandling)
{
  int m_size; // ecx
  __int64 v9; // r8
  hkRefCountedProperties::Entry *v10; // rbx
  hkRefCountedProperties::Entry *v11; // rax
  hkReferencedObject *m_pntr; // rcx
  bool v13; // zf

  m_size = this->m_entries.m_size;
  v9 = m_size - 1;
  if ( m_size - 1 >= 0 )
  {
    v10 = &this->m_entries.m_data[m_size - 1];
    while ( v10->m_key != propertyKey )
    {
      --v10;
      if ( --v9 < 0 )
        goto LABEL_5;
    }
    if ( referenceHandling == REFERENCE_COUNT_INCREMENT && propertyObject )
      hkReferencedObject::addReference(propertyObject);
LABEL_15:
    m_pntr = v10->m_object.m_pntr;
    v13 = v10->m_object.m_pntr == 0i64;
    goto LABEL_18;
  }
LABEL_5:
  if ( m_size == (this->m_entries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_entries.m_data, 16);
  v11 = &this->m_entries.m_data[this->m_entries.m_size];
  if ( v11 )
  {
    v11->m_object.m_pntr = 0i64;
    *(_DWORD *)&v11->m_key = 0xFFFF;
  }
  v10 = &this->m_entries.m_data[this->m_entries.m_size++];
  v10->m_key = propertyKey;
  if ( referenceHandling == REFERENCE_COUNT_INCREMENT )
  {
    if ( propertyObject )
    {
      hkReferencedObject::addReference(propertyObject);
      m_pntr = v10->m_object.m_pntr;
      v13 = v10->m_object.m_pntr == 0i64;
      goto LABEL_18;
    }
    goto LABEL_15;
  }
  m_pntr = v10->m_object.m_pntr;
  if ( !v10->m_object.m_pntr )
    goto LABEL_20;
  v13 = m_pntr == propertyObject;
LABEL_18:
  if ( !v13 )
    hkReferencedObject::removeReference(m_pntr);
LABEL_20:
  v10->m_object.m_pntr = propertyObject;
}

// File Line: 87
// RVA: 0xC74C50
void __fastcall hkRefCountedProperties::removeProperty(hkRefCountedProperties *this, unsigned __int16 propertyKey)
{
  int v4; // ebx
  __int64 v5; // r8
  hkRefCountedProperties::Entry *m_data; // rbp
  unsigned __int16 *i; // rdx
  unsigned __int64 v8; // rsi
  hkReferencedObject *m_pntr; // rcx
  __int64 v10; // rcx
  __int64 v11; // rdx
  hkRefCountedProperties::Entry *v12; // rax
  char *v13; // r8
  __int64 v14; // rcx

  v4 = this->m_entries.m_size - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    m_data = this->m_entries.m_data;
    for ( i = &this->m_entries.m_data[v4].m_key; *i != propertyKey; i -= 8 )
    {
      --v4;
      if ( --v5 < 0 )
        return;
    }
    v8 = v4;
    m_pntr = m_data[v8].m_object.m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
    m_data[v8].m_object.m_pntr = 0i64;
    v10 = --this->m_entries.m_size;
    if ( (_DWORD)v10 != v4 )
    {
      v11 = 2i64;
      v12 = &this->m_entries.m_data[v8];
      v13 = (char *)((char *)&this->m_entries.m_data[v10] - (char *)v12);
      do
      {
        v14 = *(__int64 *)((char *)&v12->m_object.m_pntr + (_QWORD)v13);
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
void __fastcall hkRefCountedProperties::replaceProperty(
        hkRefCountedProperties *this,
        unsigned __int16 propertyKey,
        hkReferencedObject *newPropertyObject)
{
  int v5; // eax
  __int64 v7; // rsi
  __int64 v8; // rdi
  hkRefCountedProperties::Entry *m_data; // rbx
  hkReferencedObject *m_pntr; // rcx
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkErrStream v13; // [rsp+20h] [rbp-238h] BYREF
  char buf[536]; // [rsp+40h] [rbp-218h] BYREF

  v5 = this->m_entries.m_size - 1;
  v7 = v5;
  if ( v5 >= 0 )
  {
    v8 = v5;
    do
    {
      m_data = this->m_entries.m_data;
      if ( this->m_entries.m_data[v8].m_key == propertyKey )
      {
        if ( newPropertyObject )
          hkReferencedObject::addReference(newPropertyObject);
        m_pntr = m_data[v8].m_object.m_pntr;
        if ( m_pntr )
          hkReferencedObject::removeReference(m_pntr);
        m_data[v8].m_object.m_pntr = newPropertyObject;
      }
      --v8;
      --v7;
    }
    while ( v7 >= 0 );
  }
  hkErrStream::hkErrStream(&v13, buf, 512);
  v11 = hkOstream::operator<<(&v13, "Failed to locate key ");
  v12 = hkOstream::operator<<(v11, propertyKey);
  hkOstream::operator<<(v12, " among the existing properties!");
  hkError::messageWarning(0x1D11DAEDu, buf, "Types\\Properties\\hkRefCountedProperties.cpp", 112);
  hkOstream::~hkOstream(&v13);
}

// File Line: 121
// RVA: 0xC74E30
hkReferencedObject *__fastcall hkRefCountedProperties::accessProperty(
        hkRefCountedProperties *this,
        unsigned __int16 propertyKey)
{
  hkRefCountedProperties::Entry *m_data; // r11
  int v4; // r9d
  __int64 v5; // rcx
  unsigned __int16 *i; // rdx

  m_data = this->m_entries.m_data;
  v4 = this->m_entries.m_size - 1;
  v5 = v4;
  if ( v4 < 0 )
    return 0i64;
  for ( i = &m_data[v4].m_key; *i != propertyKey; i -= 8 )
  {
    --v4;
    if ( --v5 < 0 )
      return 0i64;
  }
  return m_data[v4].m_object.m_pntr;
}

