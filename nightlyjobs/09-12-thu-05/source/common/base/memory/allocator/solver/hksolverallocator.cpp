// File Line: 19
// RVA: 0xC62E60
void __fastcall hkSolverAllocator::hkSolverAllocator(hkSolverAllocator *this)
{
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkSolverAllocator::`vftable;
  this->m_bufferStart = 0i64;
  this->m_bufferEnd = 0i64;
  this->m_currentEnd = 0i64;
  this->m_numAllocatedBlocks = 0;
  this->m_peakUse = 0i64;
  this->m_freeElems.m_size = 0;
  this->m_freeElems.m_data = this->m_elemsBuf;
  this->m_freeElems.m_capacityAndFlags = -2147483584;
  hkCriticalSection::hkCriticalSection(&this->m_criticalSection, 0);
}

// File Line: 23
// RVA: 0xC62F50
void __fastcall hkSolverAllocator::~hkSolverAllocator(hkSolverAllocator *this)
{
  hkSolverAllocator *v1; // rbx
  _RTL_CRITICAL_SECTION *v2; // rcx

  v1 = this;
  v2 = &this->m_criticalSection.m_section;
  v2[-28].SpinCount = (unsigned __int64)&hkSolverAllocator::`vftable;
  DeleteCriticalSection(v2);
  hkMemoryAllocator::~hkMemoryAllocator((hkMemoryAllocator *)&v1->vfptr);
}

// File Line: 27
// RVA: 0xC62EC0
void __fastcall hkSolverAllocator::setBuffer(hkSolverAllocator *this, void *vbuffer, int bufferSize)
{
  hkSolverAllocator *v3; // rbp
  int v4; // esi
  char *v5; // rdi

  v3 = this;
  v4 = bufferSize;
  v5 = (char *)vbuffer;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v3->m_freeElems.m_size = 0;
  v3->m_freeElems.m_capacityAndFlags = -2147483584;
  if ( !v5 )
    v4 = 0;
  v3->m_freeElems.m_data = v3->m_elemsBuf;
  v3->m_numAllocatedBlocks = 0;
  v3->m_bufferStart = v5;
  v3->m_bufferEnd = &v5[v4];
  v3->m_currentEnd = v5;
  LeaveCriticalSection(&v3->m_criticalSection.m_section);
}

// File Line: 48
// RVA: 0xC62F90
void *__fastcall hkSolverAllocator::blockAlloc(hkSolverAllocator *this, int numBytes)
{
  int reqNumInOut; // [rsp+38h] [rbp+10h]

  if ( !numBytes )
    return 0i64;
  reqNumInOut = (numBytes + 127) & 0xFFFFFF80;
  return hkSolverAllocator::allocate(this, &reqNumInOut, 1);
}

// File Line: 65
// RVA: 0xC62FD0
void __fastcall hkSolverAllocator::blockFree(hkSolverAllocator *this, void *p, int numBytes)
{
  if ( p )
  {
    if ( numBytes )
      this->vfptr->bufFree((hkMemoryAllocator *)this, p, (numBytes + 127) & 0xFFFFFF80);
  }
}

// File Line: 73
// RVA: 0xC63000
void *__fastcall hkSolverAllocator::bufAlloc(hkSolverAllocator *this, int *reqNumInOut)
{
  return hkSolverAllocator::allocate(this, reqNumInOut, 0);
}

// File Line: 78
// RVA: 0xC632D0
char *__fastcall hkSolverAllocator::allocate(hkSolverAllocator *this, int *reqNumInOut, bool useExactSize)
{
  hkSolverAllocator *v3; // rdi
  bool v4; // r15
  int *v5; // r14
  int v6; // ecx
  __int64 v7; // r10
  signed int v8; // ebp
  signed int v9; // er11
  int v10; // eax
  hkSolverAllocator::Element *v11; // r9
  signed int *v12; // rdx
  signed __int64 v13; // r8
  char *v14; // rsi
  hkSolverAllocator::Element *v15; // rcx
  int v16; // edx
  __int64 v17; // rdx
  char *v18; // rax
  char *v19; // rax
  unsigned __int64 v20; // rax

  v3 = this;
  v4 = useExactSize;
  v5 = reqNumInOut;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v6 = v3->m_freeElems.m_size;
  v7 = *v5;
  v8 = -1;
  v9 = 0x7FFFFFF;
  if ( v3->m_numAllocatedBlocks + 1 >= 2 * (v3->m_freeElems.m_capacityAndFlags & 0x3FFFFFFF) - v6 )
    goto LABEL_26;
  v10 = v6 - 1;
  if ( v6 - 1 >= 0 )
  {
    v11 = v3->m_freeElems.m_data;
    v12 = &v11[v10].m_size;
    do
    {
      if ( *v12 >= (signed int)v7 && *v12 < v9 )
      {
        v9 = *v12;
        v8 = v10;
      }
      v12 -= 4;
      --v10;
    }
    while ( v10 >= 0 );
    if ( v8 >= 0 )
    {
      v13 = v8;
      v14 = v11[v13].m_start;
      if ( v4 && v9 != (_DWORD)v7 || 2 * v9 > 3 * (signed int)v7 && (signed int)v7 > 1024 )
      {
        v11[v13].m_size -= v7;
        v11[v13].m_start = &v14[v7];
      }
      else
      {
        *v5 = v11[v13].m_size;
        --v3->m_freeElems.m_size;
        v15 = &v3->m_freeElems.m_data[v13];
        v16 = 16 * (v3->m_freeElems.m_size - v8);
        if ( v16 > 0 )
        {
          v17 = ((unsigned int)(v16 - 1) >> 3) + 1;
          do
          {
            v18 = v15[1].m_start;
            v15 = (hkSolverAllocator::Element *)((char *)v15 + 8);
            *(_QWORD *)&v15[-1].m_size = v18;
            --v17;
          }
          while ( v17 );
        }
      }
      goto LABEL_20;
    }
  }
  if ( LODWORD(v3->m_bufferEnd) - LODWORD(v3->m_currentEnd) < (signed int)v7 )
  {
LABEL_26:
    v14 = 0i64;
    goto LABEL_23;
  }
  v14 = v3->m_currentEnd;
  v3->m_currentEnd = &v14[v7];
  *v5 = v7;
LABEL_20:
  v19 = v3->m_currentEnd;
  ++v3->m_numAllocatedBlocks;
  v20 = v19 - v3->m_bufferStart;
  if ( v20 > v3->m_peakUse )
    v3->m_peakUse = v20;
LABEL_23:
  LeaveCriticalSection(&v3->m_criticalSection.m_section);
  return v14;
}

// File Line: 160
// RVA: 0xC63010
void __fastcall hkSolverAllocator::bufFree(hkSolverAllocator *this, void *data, int size)
{
  hkSolverAllocator *v3; // rdi
  __int64 v4; // rbp
  char *v5; // rsi
  char *v6; // rax
  char *v7; // r11
  bool v8; // zf
  hkSolverAllocator::Element *v9; // r8
  __int64 v10; // rdx
  int v11; // eax
  hkSolverAllocator::Element *v12; // rax
  int v13; // er10
  int v14; // edx
  __int64 v15; // rcx
  hkSolverAllocator::Element *v16; // rax
  signed __int64 v17; // rcx
  hkSolverAllocator::Element *v18; // r8
  int v19; // er9
  hkSolverAllocator::Element *v20; // rax
  int v21; // ecx
  int v22; // eax
  signed __int64 v23; // rdx
  int v24; // er9
  __int64 v25; // rcx
  __int64 v26; // rax
  signed __int64 v27; // rcx
  signed __int64 v28; // r9
  signed __int64 v29; // r8
  signed __int64 v30; // r9
  hkSolverAllocator::Element *v31; // rcx
  hkSolverAllocator::Element *v32; // rdx
  __int64 v33; // [rsp+28h] [rbp-10h]

  v3 = this;
  v4 = size;
  v5 = (char *)data;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v6 = v3->m_currentEnd;
  --v3->m_numAllocatedBlocks;
  v7 = &v5[v4];
  if ( &v5[v4] == v6 )
  {
    v8 = v3->m_freeElems.m_size == 0;
    v3->m_currentEnd = &v6[-v4];
    if ( !v8 )
    {
      do
      {
        v9 = v3->m_freeElems.m_data;
        v10 = v3->m_freeElems.m_size;
        if ( &v9[(signed int)v10 - 1].m_start[v9[(signed int)v10 - 1].m_size] != v5 )
          break;
        v3->m_currentEnd = v9[v10 - 1].m_start;
        --v3->m_freeElems.m_size;
      }
      while ( v3->m_freeElems.m_size );
    }
  }
  else
  {
    v11 = v3->m_freeElems.m_size;
    if ( v11 )
    {
      v13 = v11 - 1;
      v14 = v11 - 1;
      v15 = v11 - 1;
      if ( v11 - 1 >= 0 )
      {
        v16 = &v3->m_freeElems.m_data[v13];
        do
        {
          if ( v16->m_start < v5 )
            break;
          --v14;
          --v16;
          --v15;
        }
        while ( v15 >= 0 );
      }
      if ( v14 < 0 || (v17 = v14, v18 = &v3->m_freeElems.m_data[v17], &v18->m_start[v18->m_size] != v5) )
      {
        if ( v14 >= v13 || (v27 = (signed __int64)&v3->m_freeElems.m_data[v14 + 1], *(char **)v27 != v7) )
        {
          ++v3->m_freeElems.m_size;
          LODWORD(v33) = v4;
          v28 = v3->m_freeElems.m_size - 1;
          if ( v28 > v14 + 1 )
          {
            v29 = v28;
            v30 = v28 - (v14 + 1);
            do
            {
              v31 = &v3->m_freeElems.m_data[v29];
              --v29;
              v31->m_start = v31[-1].m_start;
              *(_QWORD *)&v31->m_size = *(_QWORD *)&v31[-1].m_size;
              --v30;
            }
            while ( v30 );
          }
          v32 = &v3->m_freeElems.m_data[v14 + 1i64];
          v32->m_start = v5;
          *(_QWORD *)&v32->m_size = v33;
        }
        else
        {
          *(_DWORD *)(v27 + 8) += v4;
          *(_QWORD *)v27 = v5;
        }
      }
      else
      {
        v19 = v4 + v18->m_size;
        v18->m_size = v19;
        if ( v14 < v3->m_freeElems.m_size - 1 )
        {
          v20 = v3->m_freeElems.m_data;
          if ( v7 == v20[v17 + 1].m_start )
          {
            v21 = v20[v17 + 1].m_size;
            v22 = v14 + 1;
            v18->m_size = v19 + v21;
            --v3->m_freeElems.m_size;
            v23 = (signed __int64)&v3->m_freeElems.m_data[v14 + 1];
            v24 = 16 * (v3->m_freeElems.m_size - v22);
            if ( v24 > 0 )
            {
              v25 = ((unsigned int)(v24 - 1) >> 3) + 1;
              do
              {
                v26 = *(_QWORD *)(v23 + 16);
                v23 += 8i64;
                *(_QWORD *)(v23 - 8) = v26;
                --v25;
              }
              while ( v25 );
            }
          }
        }
      }
    }
    else
    {
      v3->m_freeElems.m_size = 1;
      v12 = v3->m_freeElems.m_data;
      v12->m_start = v5;
      v12->m_size = v4;
    }
  }
  LeaveCriticalSection(&v3->m_criticalSection.m_section);
} = v3->m_freeElems.m_data;
      v12->m_start = v5;
      v12->m_size = v4;
    }
  }
  LeaveCriticalSection

// File Line: 245
// RVA: 0xC63250
bool __fastcall hkSolverAllocator::canAllocSingleBlock(hkSolverAllocator *this, int numBytes)
{
  return numBytes <= LODWORD(this->m_bufferEnd) - LODWORD(this->m_bufferStart);
}

// File Line: 250
// RVA: 0xC63270
void __fastcall hkSolverAllocator::getMemoryStatistics(hkSolverAllocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  u->m_allocated = this->m_bufferEnd - this->m_bufferStart;
  u->m_available = this->m_bufferEnd - this->m_currentEnd;
  u->m_inUse = this->m_currentEnd - this->m_bufferStart;
  u->m_peakInUse = this->m_peakUse;
}

// File Line: 258
// RVA: 0xC632B0
void __fastcall hkSolverAllocator::resetPeakMemoryStatistics(hkSolverAllocator *this)
{
  this->m_peakUse = this->m_currentEnd - this->m_bufferStart;
}

