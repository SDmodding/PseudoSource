// File Line: 11
// RVA: 0x15C7740
__int64 dynamic_initializer_for__s_defaultMallocAllocator__()
{
  return atexit(dynamic_atexit_destructor_for__s_defaultMallocAllocator__);
}

// File Line: 170
// RVA: 0xC819F0
void *__fastcall hkMallocAllocator::blockAlloc(hkMallocAllocator *this, int numBytes)
{
  if ( numBytes + _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_currentUsed, numBytes) > this->m_peakUse )
    this->m_peakUse = this->m_currentUsed;
  return aligned_malloc(numBytes, this->m_align);
}

// File Line: 181
// RVA: 0xC81A20
void __fastcall hkMallocAllocator::blockFree(hkMallocAllocator *this, void *p, int numBytes)
{
  _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_currentUsed, -numBytes);
  aligned_free(p);
}

// File Line: 188
// RVA: 0xC81A40
void __fastcall hkMallocAllocator::getMemoryStatistics(hkMallocAllocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  u->m_allocated = this->m_currentUsed;
  u->m_peakInUse = this->m_peakUse;
}

// File Line: 194
// RVA: 0xC81A70
void __fastcall hkMallocAllocator::resetPeakMemoryStatistics(hkMallocAllocator *this)
{
  this->m_peakUse = this->m_currentUsed;
}

// File Line: 199
// RVA: 0xC81A60
__int64 __fastcall hkMallocAllocator::getAllocatedSize(hkMallocAllocator *this, const void *obj, int numBytes)
{
  return (unsigned int)numBytes;
}

