// File Line: 14
// RVA: 0xC7D990
void __fastcall hkStatsAllocator::hkStatsAllocator(hkStatsAllocator *this, hkMemoryAllocator *a)
{
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkStatsAllocator::`vftable;
  hkCriticalSection::hkCriticalSection(&this->m_criticalSection, 0x3E8u);
  this->m_alloc = a;
  this->m_stats.m_inUse = -1i64;
  this->m_stats.m_peakInUse = -1i64;
  this->m_stats.m_allocated = 0i64;
  this->m_stats.m_available = -1i64;
  this->m_stats.m_totalAvailable = -1i64;
  this->m_stats.m_largestBlock = -1i64;
  this->m_stats.m_inUse = 0i64;
  this->m_stats.m_peakInUse = 0i64;
}

// File Line: 24
// RVA: 0xC7DA10
void __fastcall hkStatsAllocator::init(hkStatsAllocator *this, hkMemoryAllocator *a)
{
  this->m_alloc = a;
}

// File Line: 30
// RVA: 0xC7DA20
__int64 __fastcall hkStatsAllocator::blockAlloc(hkStatsAllocator *this, int numBytes)
{
  hkCriticalSection *p_m_criticalSection; // rsi
  __int64 v4; // rdi
  __int64 m_allocated; // r8
  bool v6; // cc
  hkMemoryAllocator *m_alloc; // rcx
  __int64 v8; // rbx

  p_m_criticalSection = &this->m_criticalSection;
  v4 = numBytes;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  this->m_stats.m_allocated += v4;
  m_allocated = this->m_stats.m_allocated;
  v6 = this->m_stats.m_peakInUse <= m_allocated;
  m_alloc = this->m_alloc;
  this->m_stats.m_inUse = m_allocated;
  if ( !v6 )
    m_allocated = this->m_stats.m_peakInUse;
  this->m_stats.m_peakInUse = m_allocated;
  v8 = (*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&m_alloc->vfptr->__vecDelDtor + 1))(
         m_alloc,
         (unsigned int)v4);
  LeaveCriticalSection(&p_m_criticalSection->m_section);
  return v8;
}

// File Line: 40
// RVA: 0xC7DA90
void __fastcall hkStatsAllocator::blockFree(hkStatsAllocator *this, void *p, int numBytes)
{
  __int64 v4; // rdi
  hkMemoryAllocator *m_alloc; // rcx

  v4 = numBytes;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  m_alloc = this->m_alloc;
  this->m_stats.m_allocated -= v4;
  m_alloc->vfptr->blockFree(m_alloc, p, v4);
  LeaveCriticalSection(&this->m_criticalSection.m_section);
}

// File Line: 47
// RVA: 0xC7DAF0
void __fastcall hkStatsAllocator::getMemoryStatistics(hkStatsAllocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  EnterCriticalSection(&this->m_criticalSection.m_section);
  *u = this->m_stats;
  LeaveCriticalSection(&this->m_criticalSection.m_section);
}

// File Line: 53
// RVA: 0xC7DB70
void __fastcall hkStatsAllocator::resetPeakMemoryStatistics(hkStatsAllocator *this)
{
  this->m_stats.m_peakInUse = this->m_stats.m_inUse;
}

// File Line: 58
// RVA: 0xC7DB60
__int64 __fastcall hkStatsAllocator::getAllocatedSize(hkStatsAllocator *this, const void *obj, unsigned int numBytes)
{
  return numBytes;
}

