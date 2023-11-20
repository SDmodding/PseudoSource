// File Line: 15
// RVA: 0x1309510
void __fastcall hkTrackerTypeInit::hkTrackerTypeInit(hkTrackerTypeInit *this, hkMemoryTracker::TypeDefinition *def)
{
  this->m_definition = def;
  this->m_next = hkTrackerTypeInit::s_initLinkedList;
  hkTrackerTypeInit::s_initLinkedList = this;
}

// File Line: 22
// RVA: 0x1309530
void __fastcall hkTrackerTypeInit::registerTypes(hkMemoryTracker *tracker)
{
  hkTrackerTypeInit *v1; // rbx
  hkMemoryTracker *i; // rdi

  v1 = hkTrackerTypeInit::s_initLinkedList;
  for ( i = tracker; v1; v1 = v1->m_next )
    i->vfptr->addTypeDefinition(i, v1->m_definition);
}

