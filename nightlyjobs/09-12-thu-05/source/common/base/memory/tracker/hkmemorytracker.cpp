// File Line: 33
// RVA: 0x1306490
hkDummyMemoryTrackerImpl *__fastcall hkMemoryTracker::getInstance()
{
  hkDummyMemoryTrackerImpl *result; // rax

  result = (hkDummyMemoryTrackerImpl *)hkMemoryTracker::s_singleton;
  if ( !hkMemoryTracker::s_singleton )
  {
    if ( (_S1_46 & 1) == 0 )
    {
      _S1_46 |= 1u;
      dummy.vfptr = (hkMemoryTrackerVtbl *)&hkDummyMemoryTrackerImpl::`vftable;
      atexit((int (__fastcall *)())hkMemoryTracker::getInstance_::_5_::_dynamic_atexit_destructor_for__dummy__);
    }
    return &dummy;
  }
  return result;
}

// File Line: 44
// RVA: 0x13064E0
void __fastcall hkMemoryTracker::setInstance(hkMemoryTracker *tracker)
{
  hkMemoryTracker::s_singleton = tracker;
}

// File Line: 49
// RVA: 0x1306300
hkMemoryTracker::TypeDefinition *__fastcall hkMemoryTracker::findTypeDefinition(
        hkMemoryTracker *this,
        hkSubString *name)
{
  int v3; // edi
  hkLifoAllocator *Value; // rax
  char *m_cur; // rbx
  int v7; // edi
  char *v8; // rcx
  hkMemoryTracker::TypeDefinition *v9; // rsi
  hkLifoAllocator *v10; // rax
  int v11; // r8d

  v3 = LODWORD(name->m_end) - LODWORD(name->m_start);
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v7 = (v3 + 128) & 0xFFFFFF80;
  v8 = &m_cur[v7];
  if ( v7 > Value->m_slabSize || v8 > Value->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v7);
  else
    Value->m_cur = v8;
  hkString::strNcpy(m_cur, name->m_start, LODWORD(name->m_end) - LODWORD(name->m_start));
  m_cur[LODWORD(name->m_end) - LODWORD(name->m_start)] = 0;
  v9 = this->vfptr->findTypeDefinition(this, m_cur);
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (v7 + 15) & 0xFFFFFFF0;
  if ( v7 > v10->m_slabSize || &m_cur[v11] != v10->m_cur || v10->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v10, m_cur, v11);
  else
    v10->m_cur = m_cur;
  return v9;
}

// File Line: 68
// RVA: 0x13063F0
hkBool *__fastcall hkMemoryTracker::isBasicType(hkMemoryTracker *this, hkBool *result, hkSubString *name)
{
  hkMemoryTracker::TypeDefinition *TypeDefinition; // rax

  TypeDefinition = hkMemoryTracker::findTypeDefinition(this, name);
  if ( TypeDefinition )
    result->m_bool = TypeDefinition->m_type == 0;
  else
    result->m_bool = 0;
  return result;
}

// File Line: 79
// RVA: 0x1306430
hkMemoryTracker::ClassDefinition *__fastcall hkMemoryTracker::findClassDefinition(
        hkMemoryTracker *this,
        hkSubString *name)
{
  hkMemoryTracker::ClassDefinition *result; // rax

  result = (hkMemoryTracker::ClassDefinition *)hkMemoryTracker::findTypeDefinition(this, name);
  if ( !result || result->m_type != 1 )
    return 0i64;
  return result;
}

// File Line: 89
// RVA: 0x1306460
hkMemoryTracker::ClassDefinition *__fastcall hkMemoryTracker::findClassDefinition(
        hkMemoryTracker *this,
        const char *name)
{
  hkMemoryTracker::ClassDefinition *result; // rax

  result = (hkMemoryTracker::ClassDefinition *)this->vfptr->findTypeDefinition(this, name);
  if ( !result || result->m_type != 1 )
    return 0i64;
  return result;
}

