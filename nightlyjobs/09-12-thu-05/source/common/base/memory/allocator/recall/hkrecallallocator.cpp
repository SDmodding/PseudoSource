// File Line: 14
// RVA: 0xC7DBC0
void __fastcall hkRecallAllocator::hkRecallAllocator(hkRecallAllocator *this, hkMemoryAllocator *a)
{
  hkMemoryAllocator *v2; // rbx
  hkRecallAllocator *v3; // rdi

  v2 = a;
  v3 = this;
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkRecallAllocator::`vftable;
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
// RVA: 0xC7DC40
void __fastcall hkRecallAllocator::init(hkRecallAllocator *this, hkMemoryAllocator *a)
{
  this->m_alloc = a;
}

// File Line: 30
// RVA: 0xC7DC50
signed __int64 __fastcall hkRecallAllocator::blockAlloc(hkRecallAllocator *this, int numBytes)
{
  hkRecallAllocator *v2; // r14
  __int64 v3; // rsi
  unsigned int v4; // ebx
  __int64 v5; // rax
  __int64 v6; // rdx
  __int64 v7; // rdi
  bool v8; // zf
  bool v9; // sf
  unsigned __int8 v10; // of

  v2 = this;
  v3 = numBytes;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v4 = ((v3 + 15) & 0xFFFFFFF0) + 16;
  v5 = (*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&v2->m_alloc->vfptr->__vecDelDtor + 1))(v2->m_alloc, v4);
  *(_DWORD *)(v5 + 12) = v3;
  *(_DWORD *)(v5 + 8) = v4;
  *(_QWORD *)v5 = v2->m_head;
  v2->m_stats.m_allocated += (signed int)v4;
  v2->m_stats.m_inUse += v3;
  v6 = v2->m_stats.m_inUse;
  v7 = v5;
  v10 = __OFSUB__(v2->m_stats.m_peakInUse, v6);
  v8 = v2->m_stats.m_peakInUse == v6;
  v9 = v2->m_stats.m_peakInUse - v6 < 0;
  v2->m_head = (hkRecallAllocator::Header *)v5;
  if ( !((unsigned __int8)(v9 ^ v10) | v8) )
    v6 = v2->m_stats.m_peakInUse;
  v2->m_stats.m_peakInUse = v6;
  LeaveCriticalSection(&v2->m_criticalSection.m_section);
  return v7 + 16;
}

// File Line: 51
// RVA: 0xC7DCF0
void __fastcall hkRecallAllocator::blockFree(hkRecallAllocator *this, void *p, int numBytes)
{
  hkRecallAllocator *v3; // rdi
  __int64 v4; // rbp
  char *v5; // rsi
  __int64 v6; // rcx
  signed __int64 v7; // rdx
  __int64 *v8; // rax
  _QWORD *v9; // rcx
  hkMemoryAllocator *v10; // rcx
  hkRecallAllocator::Header *v11; // [rsp+20h] [rbp-18h]
  __int64 v12; // [rsp+28h] [rbp-10h]

  if ( p )
  {
    v3 = this;
    v4 = numBytes;
    v5 = (char *)p;
    EnterCriticalSection(&this->m_criticalSection.m_section);
    v6 = (__int64)v3->m_head;
    v7 = (signed __int64)(v5 - 16);
    v12 = -1i64;
    v8 = (__int64 *)&v11;
    v11 = (hkRecallAllocator::Header *)v6;
    if ( v6 )
    {
      while ( 1 )
      {
        v9 = (_QWORD *)*v8;
        if ( *v8 == v7 )
          break;
        v8 = (__int64 *)*v8;
        if ( !*v9 )
          goto LABEL_7;
      }
      *v8 = *(_QWORD *)v7;
      v3->m_stats.m_inUse -= v4;
      v10 = v3->m_alloc;
      v3->m_head = v11;
      v3->m_stats.m_allocated -= (signed int)(((v4 + 15) & 0xFFFFFFF0) + 16);
      v10->vfptr->blockFree(v10, (void *)v7, *(_DWORD *)(v7 + 8));
    }
LABEL_7:
    LeaveCriticalSection(&v3->m_criticalSection.m_section);
  }
}

// File Line: 92
// RVA: 0xC7DDC0
void __fastcall hkRecallAllocator::getMemoryStatistics(hkRecallAllocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  hkRecallAllocator *v2; // rbx
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

// File Line: 98
// RVA: 0xC7DE40
void __fastcall hkRecallAllocator::resetPeakMemoryStatistics(hkRecallAllocator *this)
{
  this->m_stats.m_peakInUse = this->m_stats.m_inUse;
}

// File Line: 103
// RVA: 0xC7DE30
__int64 __fastcall hkRecallAllocator::getAllocatedSize(hkRecallAllocator *this, const void *obj, int numBytes)
{
  return (unsigned int)numBytes;
}

