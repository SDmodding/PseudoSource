// File Line: 20
// RVA: 0xE1BC20
void __fastcall hkpTriggerVolume::addEvent(hkpTriggerVolume *this, hkpRigidBody *body, hkpTriggerVolume::Operation m_operation)
{
  hkpTriggerVolume::Operation v3; // ebp
  hkpRigidBody *v4; // rsi
  hkpTriggerVolume *v5; // rdi
  __int64 v6; // rdx
  signed __int64 v7; // r8

  v3 = m_operation;
  v4 = body;
  v5 = this;
  if ( this->m_eventQueue.m_size == (this->m_eventQueue.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_eventQueue, 24);
  v6 = v5->m_eventQueue.m_size;
  v7 = (signed __int64)&v5->m_eventQueue.m_data[v6];
  v5->m_eventQueue.m_size = v6 + 1;
  *(_QWORD *)(v7 + 8) = v4;
  *(_DWORD *)(v7 + 16) = v3;
  *(_QWORD *)v7 = v5->m_sequenceNumber++ | ((unsigned __int64)v4->m_uid << 32);
  hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
}

