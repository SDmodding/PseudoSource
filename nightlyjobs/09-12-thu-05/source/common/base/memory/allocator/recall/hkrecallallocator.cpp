// File Line: 14
// RVA: 0xC7DBC0
void __fastcall hkRecallAllocator::hkRecallAllocator(hkRecallAllocator *this, hkMemoryAllocator *a)
{
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkRecallAllocator::`vftable;
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
// RVA: 0xC7DC40
void __fastcall hkRecallAllocator::init(hkRecallAllocator *this, hkMemoryAllocator *a)
{
  this->m_alloc = a;
}

// File Line: 30
// RVA: 0xC7DC50
hkRecallAllocator::Header *__fastcall hkRecallAllocator::blockAlloc(hkRecallAllocator *this, int numBytes)
{
  __int64 v3; // rsi
  int v4; // ebx
  hkRecallAllocator::Header *v5; // rax
  __int64 m_inUse; // rdx
  hkRecallAllocator::Header *v7; // rdi
  bool v8; // cc

  v3 = numBytes;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v4 = ((v3 + 15) & 0xFFFFFFF0) + 16;
  v5 = (hkRecallAllocator::Header *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&this->m_alloc->vfptr->__vecDelDtor
                                     + 1))(
                                      this->m_alloc,
                                      (unsigned int)v4);
  v5->m_payloadSize = v3;
  v5->m_requestedSize = v4;
  v5->m_next = this->m_head;
  this->m_stats.m_allocated += v4;
  this->m_stats.m_inUse += v3;
  m_inUse = this->m_stats.m_inUse;
  v7 = v5;
  v8 = this->m_stats.m_peakInUse <= m_inUse;
  this->m_head = v5;
  if ( !v8 )
    m_inUse = this->m_stats.m_peakInUse;
  this->m_stats.m_peakInUse = m_inUse;
  LeaveCriticalSection(&this->m_criticalSection.m_section);
  return v7 + 1;
}

// File Line: 51
// RVA: 0xC7DCF0
void __fastcall hkRecallAllocator::blockFree(hkRecallAllocator *this, char *p, int numBytes)
{
  __int64 v4; // rbp
  hkRecallAllocator::Header *m_head; // rcx
  char *v7; // rdx
  __int64 *v8; // rax
  _QWORD *v9; // rcx
  hkMemoryAllocator *m_alloc; // rcx
  __int64 v11[3]; // [rsp+20h] [rbp-18h] BYREF

  if ( p )
  {
    v4 = numBytes;
    EnterCriticalSection(&this->m_criticalSection.m_section);
    m_head = this->m_head;
    v7 = p - 16;
    v11[1] = -1i64;
    v8 = v11;
    v11[0] = (__int64)m_head;
    if ( m_head )
    {
      while ( 1 )
      {
        v9 = (_QWORD *)*v8;
        if ( (char *)*v8 == v7 )
          break;
        v8 = (__int64 *)*v8;
        if ( !*v9 )
          goto LABEL_7;
      }
      *v8 = *(_QWORD *)v7;
      this->m_stats.m_inUse -= v4;
      m_alloc = this->m_alloc;
      this->m_head = (hkRecallAllocator::Header *)v11[0];
      this->m_stats.m_allocated -= (int)(((v4 + 15) & 0xFFFFFFF0) + 16);
      m_alloc->vfptr->blockFree(m_alloc, v7, *((_DWORD *)v7 + 2));
    }
LABEL_7:
    LeaveCriticalSection(&this->m_criticalSection.m_section);
  }
}

// File Line: 92
// RVA: 0xC7DDC0
void __fastcall hkRecallAllocator::getMemoryStatistics(hkRecallAllocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  EnterCriticalSection(&this->m_criticalSection.m_section);
  *u = this->m_stats;
  LeaveCriticalSection(&this->m_criticalSection.m_section);
}

// File Line: 98
// RVA: 0xC7DE40
void __fastcall hkRecallAllocator::resetPeakMemoryStatistics(hkRecallAllocator *this)
{
  this->m_stats.m_peakInUse = this->m_stats.m_inUse;
}

// File Line: 103
// RVA: 0xC7DE30
__int64 __fastcall hkRecallAllocator::getAllocatedSize(hkRecallAllocator *this, const void *obj, unsigned int numBytes)
{
  return numBytes;
}

