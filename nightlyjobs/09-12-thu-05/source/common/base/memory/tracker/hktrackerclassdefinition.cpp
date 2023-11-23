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
  hkTrackerTypeInit *i; // rbx

  for ( i = hkTrackerTypeInit::s_initLinkedList; i; i = i->m_next )
    tracker->vfptr->addTypeDefinition(tracker, i->m_definition);
}

