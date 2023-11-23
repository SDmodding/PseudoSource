// File Line: 22
// RVA: 0x15DF3B0
__int64 dynamic_initializer_for__s_malloc__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__s_malloc__);
}

// File Line: 25
// RVA: 0x1303450
_BOOL8 __fastcall compareClassAllocs(hkDefaultMemoryTracker::ClassAlloc *a, hkDefaultMemoryTracker::ClassAlloc *b)
{
  return a->m_ptr < b->m_ptr;
}

// File Line: 31
// RVA: 0x1303470
void __fastcall arrayBaseSwap_hkDefaultMemoryTracker::ClassAlloc_(
        hkArrayBase<hkDefaultMemoryTracker::ClassAlloc> *a,
        hkArrayBase<hkDefaultMemoryTracker::ClassAlloc> *b)
{
  hkDefaultMemoryTracker::ClassAlloc *m_data; // rbx
  int m_capacityAndFlags; // r9d
  int m_size; // r8d
  int v5; // r11d
  int v6; // r10d

  m_data = a->m_data;
  m_capacityAndFlags = b->m_capacityAndFlags;
  m_size = b->m_size;
  v5 = a->m_size;
  v6 = a->m_capacityAndFlags;
  a->m_data = b->m_data;
  a->m_size = m_size;
  a->m_capacityAndFlags = m_capacityAndFlags;
  b->m_data = m_data;
  b->m_size = v5;
  b->m_capacityAndFlags = v6;
}

// File Line: 41
// RVA: 0x1303270
void __fastcall hkTrackerSnapshot::hkTrackerSnapshot(hkTrackerSnapshot *this)
{
  this->m_mem = &s_malloc;
  this->m_classAllocations.m_data = 0i64;
  this->m_classAllocations.m_size = 0;
  this->m_classAllocations.m_capacityAndFlags = 0x80000000;
  hkMemorySnapshot::hkMemorySnapshot(&this->m_rawSnapshot, 0i64);
  this->m_memSysStatistics.m_data = 0i64;
  this->m_memSysStatistics.m_size = 0;
  this->m_memSysStatistics.m_capacityAndFlags = 0x80000000;
}

// File Line: 46
// RVA: 0x13032D0
void __fastcall hkTrackerSnapshot::hkTrackerSnapshot(hkTrackerSnapshot *this, hkMemoryAllocator *mem)
{
  this->m_mem = mem;
  this->m_classAllocations.m_capacityAndFlags = 0x80000000;
  this->m_classAllocations.m_data = 0i64;
  this->m_classAllocations.m_size = 0;
  hkMemorySnapshot::hkMemorySnapshot(&this->m_rawSnapshot, 0i64);
  this->m_memSysStatistics.m_data = 0i64;
  this->m_memSysStatistics.m_size = 0;
  this->m_memSysStatistics.m_capacityAndFlags = 0x80000000;
}

// File Line: 52
// RVA: 0x1303330
void __fastcall hkTrackerSnapshot::hkTrackerSnapshot(hkTrackerSnapshot *this, hkTrackerSnapshot *rhs)
{
  this->m_mem = rhs->m_mem;
  this->m_classAllocations.m_data = 0i64;
  this->m_classAllocations.m_size = 0;
  this->m_classAllocations.m_capacityAndFlags = 0x80000000;
  hkMemorySnapshot::hkMemorySnapshot(&this->m_rawSnapshot, &rhs->m_rawSnapshot);
  this->m_memSysStatistics.m_data = 0i64;
  this->m_memSysStatistics.m_size = 0;
  this->m_memSysStatistics.m_capacityAndFlags = 0x80000000;
  hkArrayBase<hkDefaultMemoryTracker::ClassAlloc>::_append(
    &this->m_classAllocations,
    this->m_mem,
    rhs->m_classAllocations.m_data,
    rhs->m_classAllocations.m_size);
}

// File Line: 57
// RVA: 0x13033C0
void __fastcall hkTrackerSnapshot::~hkTrackerSnapshot(hkTrackerSnapshot *this)
{
  hkMemoryAllocator *m_mem; // rcx
  int m_capacityAndFlags; // r8d
  int v4; // r8d
  hkMemoryAllocator *v5; // rcx

  m_mem = this->m_mem;
  m_capacityAndFlags = this->m_classAllocations.m_capacityAndFlags;
  this->m_classAllocations.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_mem->vfptr->bufFree(m_mem, this->m_classAllocations.m_data, 32 * m_capacityAndFlags);
  this->m_classAllocations.m_data = 0i64;
  this->m_classAllocations.m_capacityAndFlags = 0x80000000;
  v4 = this->m_memSysStatistics.m_capacityAndFlags;
  v5 = this->m_mem;
  this->m_memSysStatistics.m_size = 0;
  if ( v4 >= 0 )
    v5->vfptr->bufFree(v5, this->m_memSysStatistics.m_data, v4 & 0x3FFFFFFF);
  this->m_memSysStatistics.m_data = 0i64;
  this->m_memSysStatistics.m_capacityAndFlags = 0x80000000;
  hkMemorySnapshot::~hkMemorySnapshot(&this->m_rawSnapshot);
}

// File Line: 63
// RVA: 0x1303240
void __fastcall hkTrackerSnapshot::swap(hkTrackerSnapshot *this, hkTrackerSnapshot *rhs)
{
  hkMemoryAllocator *m_mem; // rax
  hkMemoryAllocator *v3; // r8
  hkArrayBase<hkDefaultMemoryTracker::ClassAlloc> *p_m_classAllocations; // rdx

  if ( this != rhs )
  {
    m_mem = rhs->m_mem;
    v3 = this->m_mem;
    p_m_classAllocations = &rhs->m_classAllocations;
    this->m_mem = m_mem;
    *(_QWORD *)&p_m_classAllocations[-1].m_size = v3;
    arrayBaseSwap_hkDefaultMemoryTracker::ClassAlloc_(&this->m_classAllocations, p_m_classAllocations);
  }
}

// File Line: 74
// RVA: 0x1303210
void __fastcall hkTrackerSnapshot::orderClassAllocs(hkTrackerSnapshot *this)
{
  int m_size; // r8d

  m_size = this->m_classAllocations.m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkDefaultMemoryTracker::ClassAlloc,unsigned int (*)(hkDefaultMemoryTracker::ClassAlloc const &,hkDefaultMemoryTracker::ClassAlloc const &)>(
      this->m_classAllocations.m_data,
      0,
      m_size - 1,
      compareClassAllocs);
}

// File Line: 99
// RVA: 0x1302CF0
hkResult *__fastcall hkTrackerSnapshot::init(
        hkTrackerSnapshot *this,
        hkResult *result,
        hkMemorySystem *memorySystem,
        hkDefaultMemoryTracker *tracker)
{
  hkMemoryAllocator *m_mem; // rcx
  int m_capacityAndFlags; // r8d
  hkClass *v10; // rax
  hkMemoryAllocator *v11; // rdx
  hkArrayBase<char> *p_m_memSysStatistics; // r8
  int v13; // r9d
  int v14; // eax
  int v15; // eax
  hkArrayBase<char> *v16; // rbx
  _QWORD **Value; // rax
  int v18; // r9d
  int v19; // eax
  int v20; // eax
  __int64 m_hashMod; // r9
  int v22; // edx
  __int64 v23; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v25; // ebx
  const char **val; // r14
  int v27; // edx
  hkDefaultMemoryTracker::ClassAlloc *v28; // rcx
  __int64 v29; // r9
  __int64 v30; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v31; // rax
  int v32; // r8d
  hkOstream v34; // [rsp+30h] [rbp-68h] BYREF
  hkStreamWriter sw; // [rsp+48h] [rbp-50h] BYREF
  hkArrayBase<char> *v36; // [rsp+58h] [rbp-40h]
  hkMemoryAllocator *v37; // [rsp+60h] [rbp-38h]
  int m_size; // [rsp+68h] [rbp-30h]
  int v39; // [rsp+6Ch] [rbp-2Ch]
  hkResult resulta; // [rsp+A0h] [rbp+8h] BYREF

  m_mem = this->m_mem;
  m_capacityAndFlags = this->m_classAllocations.m_capacityAndFlags;
  this->m_classAllocations.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_mem->vfptr->bufFree(m_mem, this->m_classAllocations.m_data, 32 * m_capacityAndFlags);
  this->m_classAllocations.m_data = 0i64;
  this->m_classAllocations.m_capacityAndFlags = 0x80000000;
  if ( tracker
    || (tracker = (hkDefaultMemoryTracker *)hkMemoryTracker::s_singleton) != 0i64
    && (v10 = hkMemoryTracker::s_singleton->vfptr->getClassType(hkMemoryTracker::s_singleton),
        hkClass::equals(&hkDefaultMemoryTrackerClass, v10)) )
  {
    if ( !memorySystem )
      memorySystem = hkMemorySystem::getInstance();
    hkMemorySnapshot::setAllocator(&this->m_rawSnapshot, this->m_mem);
    memorySystem->vfptr->getMemorySnapshot(memorySystem, &resulta, &this->m_rawSnapshot);
    hkMemorySnapshot::sort(&this->m_rawSnapshot);
    v11 = this->m_mem;
    p_m_memSysStatistics = &this->m_memSysStatistics;
    v13 = this->m_memSysStatistics.m_size + 1;
    m_size = this->m_memSysStatistics.m_size;
    *(_DWORD *)&sw.m_memSizeAndFlags = 0x1FFFF;
    sw.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
    v36 = &this->m_memSysStatistics;
    v37 = v11;
    v39 = 1;
    v14 = this->m_memSysStatistics.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v14 < v13 )
    {
      v15 = 2 * v14;
      if ( v13 < v15 )
        v13 = v15;
      hkArrayUtil::_reserve(&resulta, v11, (const void **)&p_m_memSysStatistics->m_data, v13, 1);
      p_m_memSysStatistics = v36;
    }
    p_m_memSysStatistics->m_data[p_m_memSysStatistics->m_size] = 0;
    hkOstream::hkOstream(&v34, &sw);
    memorySystem->vfptr->printStatistics(memorySystem, &v34);
    hkOstream::~hkOstream(&v34);
    sw.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
    if ( !v39 )
    {
      v16 = v36;
      if ( v36 )
      {
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkArrayBase<char> *, __int64))(*Value[11] + 16i64))(Value[11], v16, 16i64);
      }
    }
    v18 = tracker->m_classAllocMap.m_map.m_numElems & 0x7FFFFFFF;
    v19 = this->m_classAllocations.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v19 < v18 )
    {
      v20 = 2 * v19;
      if ( v18 < v20 )
        v18 = v20;
      hkArrayUtil::_reserve(&resulta, this->m_mem, (const void **)&this->m_classAllocations.m_data, v18, 32);
    }
    this->m_classAllocations.m_size = 0;
    m_hashMod = tracker->m_classAllocMap.m_map.m_hashMod;
    v22 = 0;
    v23 = 0i64;
    if ( (int)m_hashMod >= 0 )
    {
      m_elem = tracker->m_classAllocMap.m_map.m_elem;
      do
      {
        if ( m_elem->key != -1i64 )
          break;
        ++v23;
        ++v22;
        ++m_elem;
      }
      while ( v23 <= m_hashMod );
    }
    v25 = v22;
    if ( v22 <= (int)m_hashMod )
    {
      do
      {
        val = (const char **)tracker->m_classAllocMap.m_map.m_elem[v25].val;
        if ( this->m_classAllocations.m_size == (this->m_classAllocations.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(this->m_mem, (const void **)&this->m_classAllocations.m_data, 32);
        v27 = v25 + 1;
        v28 = &this->m_classAllocations.m_data[this->m_classAllocations.m_size++];
        v28->m_typeName = *val;
        v28->m_size = (unsigned __int64)val[1];
        v28->m_ptr = (void *)val[2];
        *(_QWORD *)&v28->m_flags = val[3];
        v29 = tracker->m_classAllocMap.m_map.m_hashMod;
        v30 = v25 + 1;
        if ( v30 <= v29 )
        {
          v31 = &tracker->m_classAllocMap.m_map.m_elem[v27];
          do
          {
            if ( v31->key != -1i64 )
              break;
            ++v30;
            ++v27;
            ++v31;
          }
          while ( v30 <= v29 );
        }
        v25 = v27;
      }
      while ( v27 <= (int)v29 );
    }
    v32 = this->m_classAllocations.m_size;
    if ( v32 > 1 )
      hkAlgorithm::quickSortRecursive<hkDefaultMemoryTracker::ClassAlloc,unsigned int (*)(hkDefaultMemoryTracker::ClassAlloc const &,hkDefaultMemoryTracker::ClassAlloc const &)>(
        this->m_classAllocations.m_data,
        0,
        v32 - 1,
        compareClassAllocs);
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 240
// RVA: 0x1303010
hkResult *__fastcall hkTrackerSnapshot::checkConsistent(hkTrackerSnapshot *this, hkResult *result)
{
  __int64 m_size; // rbp
  __int64 v3; // r9
  hkMemorySnapshot::Allocation *m_data; // r8
  __int64 v6; // r15
  __int64 v7; // rsi
  int *p_m_flags; // r11
  int v9; // r9d
  __int64 v10; // r8
  char *v11; // r10
  hkMemorySnapshot::Allocation *v12; // rax
  char *v13; // rdx

  m_size = this->m_rawSnapshot.m_allocations.m_size;
  v3 = 0i64;
  if ( (int)m_size - 1 > 0 )
  {
    m_data = this->m_rawSnapshot.m_allocations.m_data;
    do
    {
      if ( m_data->m_start > m_data[1].m_start )
      {
        result->m_enum = HK_FAILURE;
        return result;
      }
      ++v3;
      ++m_data;
    }
    while ( v3 < (int)m_size - 1 );
  }
  v6 = this->m_classAllocations.m_size;
  v7 = 0i64;
  if ( v6 <= 0 )
  {
LABEL_18:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  p_m_flags = &this->m_classAllocations.m_data->m_flags;
  while ( 1 )
  {
    if ( (*(_BYTE *)p_m_flags & 2) != 0 )
      goto LABEL_17;
    v9 = 0;
    v10 = 0i64;
    if ( (int)m_size > 0 )
      break;
LABEL_16:
    if ( v9 >= (int)m_size )
      goto LABEL_20;
LABEL_17:
    ++v7;
    p_m_flags += 8;
    if ( v7 >= v6 )
      goto LABEL_18;
  }
  v11 = (char *)*((_QWORD *)p_m_flags - 1);
  v12 = this->m_rawSnapshot.m_allocations.m_data;
  while ( 1 )
  {
    v13 = (char *)v12->m_start + v12->m_size;
    if ( v11 < v12->m_start )
      break;
    if ( v11 < v13 )
    {
      if ( &v11[*((_QWORD *)p_m_flags - 2)] > v13 )
        break;
      goto LABEL_16;
    }
    ++v10;
    ++v9;
    ++v12;
    if ( v10 >= m_size )
      goto LABEL_16;
  }
LABEL_20:
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 306
// RVA: 0x1303110
hkDefaultMemoryTracker::ClassAlloc *__fastcall hkTrackerSnapshot::findClassAllocation(
        hkTrackerSnapshot *this,
        unsigned __int64 ptrIn)
{
  hkDefaultMemoryTracker::ClassAlloc *m_data; // r10
  int m_size; // ecx
  int v5; // r9d
  hkDefaultMemoryTracker::ClassAlloc *v6; // r8
  unsigned __int64 m_ptr; // rdx

  m_data = this->m_classAllocations.m_data;
  m_size = this->m_classAllocations.m_size;
  if ( m_size <= 0 )
    return 0i64;
  while ( 1 )
  {
    v5 = m_size / 2;
    v6 = &m_data[m_size / 2];
    m_ptr = (unsigned __int64)v6->m_ptr;
    if ( ptrIn >= m_ptr )
      break;
    m_size /= 2;
LABEL_6:
    if ( m_size <= 0 )
      return 0i64;
  }
  if ( ptrIn >= v6->m_size + m_ptr )
  {
    m_size += -1 - v5;
    m_data += v5 + 1;
    goto LABEL_6;
  }
  return &m_data[m_size / 2];
}

// File Line: 343
// RVA: 0x1303180
hkMemorySnapshot::Allocation *__fastcall hkTrackerSnapshot::findAllocationForClassAllocation(
        hkTrackerSnapshot *this,
        hkDefaultMemoryTracker::ClassAlloc *classAlloc)
{
  hkMemorySnapshot::Allocation *m_data; // r10
  int m_size; // ecx
  void *m_ptr; // r11
  unsigned __int64 v5; // rbx
  __int64 v6; // r9
  hkMemorySnapshot::Allocation *v7; // rdx
  unsigned __int64 m_start; // r8

  m_data = this->m_rawSnapshot.m_allocations.m_data;
  m_size = this->m_rawSnapshot.m_allocations.m_size;
  if ( m_size <= 0 )
    return 0i64;
  m_ptr = classAlloc->m_ptr;
  v5 = (unsigned __int64)m_ptr + classAlloc->m_size;
  while ( 1 )
  {
    v6 = m_size / 2;
    v7 = &m_data[v6];
    m_start = (unsigned __int64)v7->m_start;
    if ( (const void *)v5 >= v7->m_start )
      break;
    m_size /= 2;
LABEL_7:
    if ( m_size <= 0 )
      return 0i64;
  }
  if ( (unsigned __int64)m_ptr >= m_start + v7->m_size )
  {
    m_size += -1 - v6;
    m_data += (int)v6 + 1;
    goto LABEL_7;
  }
  if ( (unsigned __int64)m_ptr < m_start || v5 > m_start + v7->m_size )
    return 0i64;
  return &m_data[v6];
}

