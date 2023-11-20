// File Line: 19
// RVA: 0xE185C0
void __fastcall hkpPhysicsSystemWithContacts::~hkpPhysicsSystemWithContacts(hkpPhysicsSystemWithContacts *this)
{
  __int64 v1; // rsi
  __int64 v2; // rbx
  hkpPhysicsSystemWithContacts *v3; // rdi
  int v4; // er8

  v1 = this->m_contacts.m_size;
  v2 = 0i64;
  v3 = this;
  for ( this->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsSystemWithContacts::`vftable; v2 < v1; ++v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v3->m_contacts.m_data[v2]->vfptr);
  v4 = v3->m_contacts.m_capacityAndFlags;
  v3->m_contacts.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v3->m_contacts.m_data,
      8 * v4);
  v3->m_contacts.m_data = 0i64;
  v3->m_contacts.m_capacityAndFlags = 2147483648;
  hkpPhysicsSystem::~hkpPhysicsSystem((hkpPhysicsSystem *)&v3->vfptr);
}

// File Line: 28
// RVA: 0xE18680
void __fastcall hkpPhysicsSystemWithContacts::copy(hkpPhysicsSystemWithContacts *this, hkpPhysicsSystemWithContacts *toCopy)
{
  hkpPhysicsSystemWithContacts *v2; // rdi
  hkpPhysicsSystemWithContacts *v3; // rbx
  __int64 v4; // rcx
  hkpSerializedAgentNnEntry **v5; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkpSerializedAgentNnEntry *v8; // rcx
  int v9; // [rsp+30h] [rbp+8h]

  v2 = toCopy;
  v3 = this;
  hkpPhysicsSystem::copy((hkpPhysicsSystem *)&this->vfptr, (hkpPhysicsSystem *)&toCopy->vfptr);
  if ( (v3->m_contacts.m_capacityAndFlags & 0x3FFFFFFF) < v2->m_contacts.m_size )
  {
    if ( v3->m_contacts.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_contacts.m_data,
        8 * v3->m_contacts.m_capacityAndFlags);
    v9 = 8 * v2->m_contacts.m_size;
    v3->m_contacts.m_data = (hkpSerializedAgentNnEntry **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                            &v9);
    v3->m_contacts.m_capacityAndFlags = v9 / 8;
  }
  v4 = v2->m_contacts.m_size;
  v5 = v3->m_contacts.m_data;
  v3->m_contacts.m_size = v4;
  v6 = v4;
  if ( (signed int)v4 > 0 )
  {
    v7 = (char *)((char *)v2->m_contacts.m_data - (char *)v5);
    do
    {
      v8 = *(hkpSerializedAgentNnEntry **)((char *)v5 + (_QWORD)v7);
      ++v5;
      *(v5 - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 35
// RVA: 0xE18670
hkpPhysicsSystem *__fastcall hkpPhysicsSystemWithContacts::clone(hkpPhysicsSystemWithContacts *this, hkpPhysicsSystem::CloneConstraintMode cloneMode)
{
  return 0i64;
}

// File Line: 42
// RVA: 0xE18750
void __fastcall hkpPhysicsSystemWithContacts::addContact(hkpPhysicsSystemWithContacts *this, hkpSerializedAgentNnEntry *c)
{
  hkpPhysicsSystemWithContacts *v2; // rbx
  hkpSerializedAgentNnEntry *v3; // rdi

  if ( c )
  {
    v2 = this;
    v3 = c;
    hkReferencedObject::addReference((hkReferencedObject *)&c->vfptr);
    if ( v2->m_contacts.m_size == (v2->m_contacts.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_contacts, 8);
    v2->m_contacts.m_data[v2->m_contacts.m_size++] = v3;
  }
}

// File Line: 51
// RVA: 0xE187C0
void __fastcall hkpPhysicsSystemWithContacts::removeContact(hkpPhysicsSystemWithContacts *this, int i)
{
  hkpPhysicsSystemWithContacts *v2; // rdi
  int v3; // ebx
  signed __int64 v4; // rsi
  __int64 v5; // rax

  v2 = this;
  v3 = i;
  v4 = i;
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_contacts.m_data[i]->vfptr);
  v5 = --v2->m_contacts.m_size;
  if ( (_DWORD)v5 != v3 )
    v2->m_contacts.m_data[v4] = v2->m_contacts.m_data[v5];
}

