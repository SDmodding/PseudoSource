// File Line: 14
// RVA: 0xC7D990
void __fastcall hkStatsAllocator::hkStatsAllocator(hkStatsAllocator *this, hkMemoryAllocator *a)
{
  hkMemoryAllocator *v2; // rbx
  hkStatsAllocator *v3; // rdi

  v2 = a;
  v3 = this;
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkStatsAllocator::`vftable';
  hkCriticalSection::hkCriticalSection(&this->m_criticalSection, 1000);
  v3->m_alloc = v2;
  v3->m_stats.m_inUse = -1i64;
  v3->m_stats.m_peakInUse = -1i64;
  v3->m_stats.m_allocated = 0i64;
  v3->m_stats.m_available = -1i64;
  v3->m_stats.m_totalAvailable = -1i64;
  v3->m_stats.m_largestBlock = -1i64;
  v3->m_stats.m_inUse = 0i64;
  v3->m_stats.m_peakInUse = 0i64;
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
  _RTL_CRITICAL_SECTION *v2; // rsi
  hkStatsAllocator *v3; // rbx
  __int64 v4; // rdi
  __int64 v5; // r8
  bool v6; // zf
  bool v7; // sf
  unsigned __int8 v8; // of
  hkMemoryAllocator *v9; // rcx
  __int64 v10; // rbx

  v2 = &this->m_criticalSection.m_section;
  v3 = this;
  v4 = numBytes;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v3->m_stats.m_allocated += v4;
  v5 = v3->m_stats.m_allocated;
  v8 = __OFSUB__(v3->m_stats.m_peakInUse, v5);
  v6 = v3->m_stats.m_peakInUse == v5;
  v7 = v3->m_stats.m_peakInUse - v5 < 0;
  v9 = v3->m_alloc;
  v3->m_stats.m_inUse = v5;
  if ( !((unsigned __int8)(v7 ^ v8) | v6) )
    v5 = v3->m_stats.m_peakInUse;
  v3->m_stats.m_peakInUse = v5;
  v10 = (*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&v9->vfptr->__vecDelDtor + 1))(v9, (unsigned int)v4);
  LeaveCriticalSection(v2);
  return v10;
}

// File Line: 40
// RVA: 0xC7DA90
void __fastcall hkStatsAllocator::blockFree(hkStatsAllocator *this, void *p, int numBytes)
{
  hkStatsAllocator *v3; // rbx
  __int64 v4; // rdi
  void *v5; // rsi
  hkMemoryAllocator *v6; // rcx

  v3 = this;
  v4 = numBytes;
  v5 = p;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v6 = v3->m_alloc;
  v3->m_stats.m_allocated -= v4;
  v6->vfptr->blockFree(v6, v5, v4);
  LeaveCriticalSection(&v3->m_criticalSection.m_section);
}

// File Line: 47
// RVA: 0xC7DAF0
void __fastcall hkStatsAllocator::getMemoryStatistics(hkStatsAllocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  hkStatsAllocator *v2; // rbx
  hkMemoryAllocator::MemoryStatistics *v3; // rsi

  v2 = this;
  v3 = u;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v3->m_allocated = v2->m_stats.m_allocated;
  v3->m_inUse = v2->m_stats.m_inUse;
  v3->m_peakInUse = v2->m_stats.m_peakInUse;
  v3->m_available = v2->m_stats.m_available;
  v3->m_totalAvailable = v2->m_stats.m_totalAvailable;
  v3->m_largestBlock = v2->m_stats.m_largestBlock;
  LeaveCriticalSection(&v2->m_criticalSection.m_section);
}

// File Line: 53
// RVA: 0xC7DB70
void __fastcall hkStatsAllocator::resetPeakMemoryStatistics(hkStatsAllocator *this)
{
  this->m_stats.m_peakInUse = this->m_stats.m_inUse;
}

// File Line: 58
// RVA: 0xC7DB60
__int64 __fastcall hkStatsAllocator::getAllocatedSize(hkStatsAllocator *this, const void *obj, int numBytes)
{
  return (unsigned int)numBytes;
}

