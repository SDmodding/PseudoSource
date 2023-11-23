// File Line: 20
// RVA: 0xE1BC20
void __fastcall hkpTriggerVolume::addEvent(hkpTriggerVolume *this, hkpRigidBody *body, int m_operation)
{
  __int64 m_size; // rdx
  hkpTriggerVolume::EventInfo *v7; // r8

  if ( this->m_eventQueue.m_size == (this->m_eventQueue.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_eventQueue.m_data, 24);
  m_size = this->m_eventQueue.m_size;
  v7 = &this->m_eventQueue.m_data[m_size];
  this->m_eventQueue.m_size = m_size + 1;
  v7->m_body = body;
  v7->m_operation.m_storage = m_operation;
  v7->m_sortValue = this->m_sequenceNumber++ | ((unsigned __int64)body->m_uid << 32);
  hkReferencedObject::addReference(body);
}

