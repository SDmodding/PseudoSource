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
  hkCriticalSection *p_m_criticalSection; // rcx

  p_m_criticalSection = &this->m_criticalSection;
  p_m_criticalSection[-28].m_section.SpinCount = (unsigned __int64)&hkSolverAllocator::`vftable;
  DeleteCriticalSection(&p_m_criticalSection->m_section);
  hkMemoryAllocator::~hkMemoryAllocator(this);
}

// File Line: 27
// RVA: 0xC62EC0
void __fastcall hkSolverAllocator::setBuffer(hkSolverAllocator *this, char *vbuffer, int bufferSize)
{
  EnterCriticalSection(&this->m_criticalSection.m_section);
  this->m_freeElems.m_size = 0;
  this->m_freeElems.m_capacityAndFlags = -2147483584;
  if ( !vbuffer )
    bufferSize = 0;
  this->m_freeElems.m_data = this->m_elemsBuf;
  this->m_numAllocatedBlocks = 0;
  this->m_bufferStart = vbuffer;
  this->m_bufferEnd = &vbuffer[bufferSize];
  this->m_currentEnd = vbuffer;
  LeaveCriticalSection(&this->m_criticalSection.m_section);
}

// File Line: 48
// RVA: 0xC62F90
void *__fastcall hkSolverAllocator::blockAlloc(hkSolverAllocator *this, int numBytes)
{
  int reqNumInOut; // [rsp+38h] [rbp+10h] BYREF

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
      this->vfptr->bufFree(this, p, (numBytes + 127) & 0xFFFFFF80);
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
  int m_size; // ecx
  __int64 v7; // r10
  int v8; // ebp
  int v9; // r11d
  int v10; // eax
  hkSolverAllocator::Element *m_data; // r9
  int *p_m_size; // rdx
  unsigned __int64 v13; // r8
  char *m_start; // rsi
  hkSolverAllocator::Element *v15; // rcx
  int v16; // edx
  __int64 v17; // rdx
  char *v18; // rax
  char *m_currentEnd; // rax
  unsigned __int64 v20; // rax

  EnterCriticalSection(&this->m_criticalSection.m_section);
  m_size = this->m_freeElems.m_size;
  v7 = *reqNumInOut;
  v8 = -1;
  v9 = 0x7FFFFFF;
  if ( this->m_numAllocatedBlocks + 1 >= 2 * (this->m_freeElems.m_capacityAndFlags & 0x3FFFFFFF) - m_size )
    goto LABEL_22;
  v10 = m_size - 1;
  if ( m_size - 1 >= 0 )
  {
    m_data = this->m_freeElems.m_data;
    p_m_size = &m_data[v10].m_size;
    do
    {
      if ( *p_m_size >= (int)v7 && *p_m_size < v9 )
      {
        v9 = *p_m_size;
        v8 = v10;
      }
      p_m_size -= 4;
      --v10;
    }
    while ( v10 >= 0 );
    if ( v8 >= 0 )
    {
      v13 = v8;
      m_start = m_data[v13].m_start;
      if ( (!useExactSize || v9 == (_DWORD)v7) && (2 * v9 <= 3 * (int)v7 || (int)v7 <= 1024) )
      {
        *reqNumInOut = m_data[v13].m_size;
        --this->m_freeElems.m_size;
        v15 = &this->m_freeElems.m_data[v13];
        v16 = 16 * (this->m_freeElems.m_size - v8);
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
      else
      {
        m_data[v13].m_size -= v7;
        m_data[v13].m_start = &m_start[v7];
      }
      goto LABEL_20;
    }
  }
  if ( LODWORD(this->m_bufferEnd) - LODWORD(this->m_currentEnd) < (int)v7 )
  {
LABEL_22:
    m_start = 0i64;
    goto LABEL_23;
  }
  m_start = this->m_currentEnd;
  this->m_currentEnd = &m_start[v7];
  *reqNumInOut = v7;
LABEL_20:
  m_currentEnd = this->m_currentEnd;
  ++this->m_numAllocatedBlocks;
  v20 = m_currentEnd - this->m_bufferStart;
  if ( v20 > this->m_peakUse )
    this->m_peakUse = v20;
LABEL_23:
  LeaveCriticalSection(&this->m_criticalSection.m_section);
  return m_start;
}

// File Line: 160
// RVA: 0xC63010
void __fastcall hkSolverAllocator::bufFree(hkSolverAllocator *this, char *data, int size)
{
  __int64 v4; // rbp
  char *m_currentEnd; // rax
  char *v7; // r11
  bool v8; // zf
  hkSolverAllocator::Element *m_data; // r8
  __int64 m_size; // rdx
  int v11; // eax
  hkSolverAllocator::Element *v12; // rax
  int v13; // r10d
  int v14; // edx
  __int64 v15; // rcx
  hkSolverAllocator::Element *v16; // rax
  unsigned __int64 v17; // rcx
  hkSolverAllocator::Element *v18; // r8
  int v19; // r9d
  hkSolverAllocator::Element *v20; // rax
  int v21; // ecx
  int v22; // eax
  hkSolverAllocator::Element *v23; // rdx
  int v24; // r9d
  __int64 v25; // rcx
  char *m_start; // rax
  hkSolverAllocator::Element *v27; // rcx
  __int64 v28; // r9
  __int64 v29; // r8
  __int64 v30; // r9
  hkSolverAllocator::Element *v31; // rcx
  hkSolverAllocator::Element *v32; // rdx
  __int64 v33; // [rsp+28h] [rbp-10h]

  v4 = size;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  m_currentEnd = this->m_currentEnd;
  --this->m_numAllocatedBlocks;
  v7 = &data[v4];
  if ( &data[v4] == m_currentEnd )
  {
    v8 = this->m_freeElems.m_size == 0;
    this->m_currentEnd = &m_currentEnd[-v4];
    if ( !v8 )
    {
      do
      {
        m_data = this->m_freeElems.m_data;
        m_size = this->m_freeElems.m_size;
        if ( &m_data[(int)m_size - 1].m_start[m_data[(int)m_size - 1].m_size] != data )
          break;
        this->m_currentEnd = m_data[m_size - 1].m_start;
        --this->m_freeElems.m_size;
      }
      while ( this->m_freeElems.m_size );
    }
  }
  else
  {
    v11 = this->m_freeElems.m_size;
    if ( v11 )
    {
      v13 = v11 - 1;
      v14 = v11 - 1;
      v15 = v11 - 1;
      if ( v11 - 1 >= 0 )
      {
        v16 = &this->m_freeElems.m_data[v13];
        do
        {
          if ( v16->m_start < data )
            break;
          --v14;
          --v16;
          --v15;
        }
        while ( v15 >= 0 );
      }
      if ( v14 >= 0 && (v17 = v14, v18 = &this->m_freeElems.m_data[v17], &v18->m_start[v18->m_size] == data) )
      {
        v19 = v4 + v18->m_size;
        v18->m_size = v19;
        if ( v14 < this->m_freeElems.m_size - 1 )
        {
          v20 = this->m_freeElems.m_data;
          if ( v7 == v20[v17 + 1].m_start )
          {
            v21 = v20[v17 + 1].m_size;
            v22 = v14 + 1;
            v18->m_size = v19 + v21;
            --this->m_freeElems.m_size;
            v23 = &this->m_freeElems.m_data[v14 + 1];
            v24 = 16 * (this->m_freeElems.m_size - v22);
            if ( v24 > 0 )
            {
              v25 = ((unsigned int)(v24 - 1) >> 3) + 1;
              do
              {
                m_start = v23[1].m_start;
                v23 = (hkSolverAllocator::Element *)((char *)v23 + 8);
                *(_QWORD *)&v23[-1].m_size = m_start;
                --v25;
              }
              while ( v25 );
            }
          }
        }
      }
      else if ( v14 < v13 && (v27 = &this->m_freeElems.m_data[v14 + 1], v27->m_start == v7) )
      {
        v27->m_size += v4;
        v27->m_start = data;
      }
      else
      {
        ++this->m_freeElems.m_size;
        LODWORD(v33) = v4;
        v28 = this->m_freeElems.m_size - 1;
        if ( v28 > v14 + 1 )
        {
          v29 = v28;
          v30 = v28 - (v14 + 1);
          do
          {
            v31 = &this->m_freeElems.m_data[v29--];
            v31->m_start = v31[-1].m_start;
            *(_QWORD *)&v31->m_size = *(_QWORD *)&v31[-1].m_size;
            --v30;
          }
          while ( v30 );
        }
        v32 = &this->m_freeElems.m_data[v14 + 1];
        v32->m_start = data;
        *(_QWORD *)&v32->m_size = v33;
      }
    }
    else
    {
      this->m_freeElems.m_size = 1;
      v12 = this->m_freeElems.m_data;
      v12->m_start = data;
      v12->m_size = v4;
    }
  }
  LeaveCriticalSection(&this->m_criticalSection.m_section);
}

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

