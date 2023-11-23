// File Line: 19
// RVA: 0xE185C0
void __fastcall hkpPhysicsSystemWithContacts::~hkpPhysicsSystemWithContacts(hkpPhysicsSystemWithContacts *this)
{
  __int64 m_size; // rsi
  __int64 v2; // rbx
  int m_capacityAndFlags; // r8d

  m_size = this->m_contacts.m_size;
  v2 = 0i64;
  for ( this->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsSystemWithContacts::`vftable; v2 < m_size; ++v2 )
    hkReferencedObject::removeReference(this->m_contacts.m_data[v2]);
  m_capacityAndFlags = this->m_contacts.m_capacityAndFlags;
  this->m_contacts.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_contacts.m_data,
      8 * m_capacityAndFlags);
  this->m_contacts.m_data = 0i64;
  this->m_contacts.m_capacityAndFlags = 0x80000000;
  hkpPhysicsSystem::~hkpPhysicsSystem(this);
}

// File Line: 28
// RVA: 0xE18680
void __fastcall hkpPhysicsSystemWithContacts::copy(
        hkpPhysicsSystemWithContacts *this,
        hkpPhysicsSystemWithContacts *toCopy)
{
  __int64 m_size; // rcx
  hkpSerializedAgentNnEntry **m_data; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkpSerializedAgentNnEntry *v8; // rcx
  int v9; // [rsp+30h] [rbp+8h] BYREF

  hkpPhysicsSystem::copy(this, toCopy);
  if ( (this->m_contacts.m_capacityAndFlags & 0x3FFFFFFF) < toCopy->m_contacts.m_size )
  {
    if ( this->m_contacts.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_contacts.m_data,
        8 * this->m_contacts.m_capacityAndFlags);
    v9 = 8 * toCopy->m_contacts.m_size;
    this->m_contacts.m_data = (hkpSerializedAgentNnEntry **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                              &hkContainerHeapAllocator::s_alloc,
                                                              &v9);
    this->m_contacts.m_capacityAndFlags = v9 / 8;
  }
  m_size = toCopy->m_contacts.m_size;
  m_data = this->m_contacts.m_data;
  this->m_contacts.m_size = m_size;
  v6 = m_size;
  if ( (int)m_size > 0 )
  {
    v7 = (char *)((char *)toCopy->m_contacts.m_data - (char *)m_data);
    do
    {
      v8 = *(hkpSerializedAgentNnEntry **)((char *)m_data++ + (_QWORD)v7);
      *(m_data - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 35
// RVA: 0xE18670
hkpPhysicsSystem *__fastcall hkpPhysicsSystemWithContacts::clone(
        hkpPhysicsSystemWithContacts *this,
        hkpPhysicsSystem::CloneConstraintMode cloneMode)
{
  return 0i64;
}

// File Line: 42
// RVA: 0xE18750
void __fastcall hkpPhysicsSystemWithContacts::addContact(
        hkpPhysicsSystemWithContacts *this,
        hkpSerializedAgentNnEntry *c)
{
  if ( c )
  {
    hkReferencedObject::addReference(c);
    if ( this->m_contacts.m_size == (this->m_contacts.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_contacts.m_data, 8);
    this->m_contacts.m_data[this->m_contacts.m_size++] = c;
  }
}

// File Line: 51
// RVA: 0xE187C0
void __fastcall hkpPhysicsSystemWithContacts::removeContact(hkpPhysicsSystemWithContacts *this, int i)
{
  __int64 v4; // rsi
  __int64 v5; // rax

  v4 = i;
  hkReferencedObject::removeReference(this->m_contacts.m_data[v4]);
  v5 = --this->m_contacts.m_size;
  if ( (_DWORD)v5 != i )
    this->m_contacts.m_data[v4] = this->m_contacts.m_data[v5];
}

