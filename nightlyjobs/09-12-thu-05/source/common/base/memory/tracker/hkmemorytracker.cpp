// File Line: 33
// RVA: 0x1306490
hkDummyMemoryTrackerImpl *__fastcall hkMemoryTracker::getInstance()
{
  hkDummyMemoryTrackerImpl *result; // rax

  result = (hkDummyMemoryTrackerImpl *)hkMemoryTracker::s_singleton;
  if ( !hkMemoryTracker::s_singleton )
  {
    if ( !(_S1_46 & 1) )
    {
      _S1_46 |= 1u;
      dummy.vfptr = (hkMemoryTrackerVtbl *)&hkDummyMemoryTrackerImpl::`vftable;
      atexit(hkMemoryTracker::getInstance_::_5_::_dynamic_atexit_destructor_for__dummy__);
    }
    result = &dummy;
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
hkMemoryTracker::TypeDefinition *__fastcall hkMemoryTracker::findTypeDefinition(hkMemoryTracker *this, hkSubString *name)
{
  hkMemoryTracker *v2; // r14
  int v3; // edi
  hkSubString *v4; // rsi
  hkLifoAllocator *v5; // rax
  char *v6; // rbx
  int v7; // edi
  char *v8; // rcx
  __int64 v9; // rsi
  hkLifoAllocator *v10; // rax
  int v11; // er8

  v2 = this;
  v3 = LODWORD(name->m_end) - LODWORD(name->m_start);
  v4 = name;
  v5 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (char *)v5->m_cur;
  v7 = (v3 + 128) & 0xFFFFFF80;
  v8 = &v6[v7];
  if ( v7 > v5->m_slabSize || v8 > v5->m_end )
    v6 = (char *)hkLifoAllocator::allocateFromNewSlab(v5, v7);
  else
    v5->m_cur = v8;
  hkString::strNcpy(v6, v4->m_start, LODWORD(v4->m_end) - LODWORD(v4->m_start));
  v6[LODWORD(v4->m_end) - LODWORD(v4->m_start)] = 0;
  v9 = (__int64)v2->vfptr->findTypeDefinition(v2, v6);
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (v7 + 15) & 0xFFFFFFF0;
  if ( v7 > v10->m_slabSize || &v6[v11] != v10->m_cur || v10->m_firstNonLifoEnd == v6 )
    hkLifoAllocator::slowBlockFree(v10, v6, v11);
  else
    v10->m_cur = v6;
  return (hkMemoryTracker::TypeDefinition *)v9;
}

// File Line: 68
// RVA: 0x13063F0
hkBool *__fastcall hkMemoryTracker::isBasicType(hkMemoryTracker *this, hkBool *result, hkSubString *name)
{
  hkBool *v3; // rbx
  hkMemoryTracker::TypeDefinition *v4; // rax

  v3 = result;
  v4 = hkMemoryTracker::findTypeDefinition(this, name);
  if ( v4 )
    v3->m_bool = v4->m_type == 0;
  else
    v3->m_bool = 0;
  return v3;
}

// File Line: 79
// RVA: 0x1306430
hkMemoryTracker::ClassDefinition *__fastcall hkMemoryTracker::findClassDefinition(hkMemoryTracker *this, hkSubString *name)
{
  hkMemoryTracker::ClassDefinition *result; // rax

  result = (hkMemoryTracker::ClassDefinition *)hkMemoryTracker::findTypeDefinition(this, name);
  if ( !result || result->m_type != 1 )
    result = 0i64;
  return result;
}

// File Line: 89
// RVA: 0x1306460
hkMemoryTracker::ClassDefinition *__fastcall hkMemoryTracker::findClassDefinition(hkMemoryTracker *this, const char *name)
{
  hkMemoryTracker::ClassDefinition *result; // rax

  result = (hkMemoryTracker::ClassDefinition *)this->vfptr->findTypeDefinition(this, name);
  if ( !result || result->m_type != 1 )
    result = 0i64;
  return result;
}

