// File Line: 22
// RVA: 0x15DF3B0
__int64 dynamic_initializer_for__s_malloc__()
{
  return atexit(dynamic_atexit_destructor_for__s_malloc__);
}

// File Line: 25
// RVA: 0x1303450
_BOOL8 __fastcall compareClassAllocs(hkDefaultMemoryTracker::ClassAlloc *a, hkDefaultMemoryTracker::ClassAlloc *b)
{
  return a->m_ptr < b->m_ptr;
}

// File Line: 31
// RVA: 0x1303470
void __fastcall arrayBaseSwap_hkDefaultMemoryTracker::ClassAlloc_(hkArrayBase<hkDefaultMemoryTracker::ClassAlloc> *a, hkArrayBase<hkDefaultMemoryTracker::ClassAlloc> *b)
{
  hkDefaultMemoryTracker::ClassAlloc *v2; // rbx
  int v3; // er9
  int v4; // er8
  int v5; // er11
  int v6; // er10

  v2 = a->m_data;
  v3 = b->m_capacityAndFlags;
  v4 = b->m_size;
  v5 = a->m_size;
  v6 = a->m_capacityAndFlags;
  a->m_data = b->m_data;
  a->m_size = v4;
  a->m_capacityAndFlags = v3;
  b->m_data = v2;
  b->m_size = v5;
  b->m_capacityAndFlags = v6;
}

// File Line: 41
// RVA: 0x1303270
void __fastcall hkTrackerSnapshot::hkTrackerSnapshot(hkTrackerSnapshot *this)
{
  hkTrackerSnapshot *v1; // rbx

  v1 = this;
  this->m_mem = (hkMemoryAllocator *)&s_malloc;
  this->m_classAllocations.m_data = 0i64;
  this->m_classAllocations.m_size = 0;
  this->m_classAllocations.m_capacityAndFlags = 2147483648;
  hkMemorySnapshot::hkMemorySnapshot(&this->m_rawSnapshot, 0i64);
  v1->m_memSysStatistics.m_data = 0i64;
  v1->m_memSysStatistics.m_size = 0;
  v1->m_memSysStatistics.m_capacityAndFlags = 2147483648;
}

// File Line: 46
// RVA: 0x13032D0
void __fastcall hkTrackerSnapshot::hkTrackerSnapshot(hkTrackerSnapshot *this, hkMemoryAllocator *mem)
{
  hkTrackerSnapshot *v2; // rbx

  this->m_mem = mem;
  v2 = this;
  this->m_classAllocations.m_capacityAndFlags = 2147483648;
  this->m_classAllocations.m_data = 0i64;
  this->m_classAllocations.m_size = 0;
  hkMemorySnapshot::hkMemorySnapshot(&this->m_rawSnapshot, 0i64);
  v2->m_memSysStatistics.m_data = 0i64;
  v2->m_memSysStatistics.m_size = 0;
  v2->m_memSysStatistics.m_capacityAndFlags = 2147483648;
}

// File Line: 52
// RVA: 0x1303330
void __fastcall hkTrackerSnapshot::hkTrackerSnapshot(hkTrackerSnapshot *this, hkTrackerSnapshot *rhs)
{
  hkTrackerSnapshot *v2; // rdi
  hkTrackerSnapshot *v3; // rsi

  v2 = rhs;
  this->m_mem = rhs->m_mem;
  v3 = this;
  this->m_classAllocations.m_data = 0i64;
  this->m_classAllocations.m_size = 0;
  this->m_classAllocations.m_capacityAndFlags = 2147483648;
  hkMemorySnapshot::hkMemorySnapshot(&this->m_rawSnapshot, &rhs->m_rawSnapshot);
  v3->m_memSysStatistics.m_data = 0i64;
  v3->m_memSysStatistics.m_size = 0;
  v3->m_memSysStatistics.m_capacityAndFlags = 2147483648;
  hkArrayBase<hkDefaultMemoryTracker::ClassAlloc>::_append(
    &v3->m_classAllocations,
    v3->m_mem,
    v2->m_classAllocations.m_data,
    v2->m_classAllocations.m_size);
}

// File Line: 57
// RVA: 0x13033C0
void __fastcall hkTrackerSnapshot::~hkTrackerSnapshot(hkTrackerSnapshot *this)
{
  hkTrackerSnapshot *v1; // rbx
  hkMemoryAllocator *v2; // rcx
  int v3; // er8
  int v4; // er8
  hkMemoryAllocator *v5; // rcx

  v1 = this;
  v2 = this->m_mem;
  v3 = v1->m_classAllocations.m_capacityAndFlags;
  v1->m_classAllocations.m_size = 0;
  if ( v3 >= 0 )
    v2->vfptr->bufFree(v2, v1->m_classAllocations.m_data, 32 * v3);
  v1->m_classAllocations.m_data = 0i64;
  v1->m_classAllocations.m_capacityAndFlags = 2147483648;
  v4 = v1->m_memSysStatistics.m_capacityAndFlags;
  v5 = v1->m_mem;
  v1->m_memSysStatistics.m_size = 0;
  if ( v4 >= 0 )
    v5->vfptr->bufFree(v5, v1->m_memSysStatistics.m_data, v4 & 0x3FFFFFFF);
  v1->m_memSysStatistics.m_data = 0i64;
  v1->m_memSysStatistics.m_capacityAndFlags = 2147483648;
  hkMemorySnapshot::~hkMemorySnapshot(&v1->m_rawSnapshot);
}

// File Line: 63
// RVA: 0x1303240
void __fastcall hkTrackerSnapshot::swap(hkTrackerSnapshot *this, hkTrackerSnapshot *rhs)
{
  hkMemoryAllocator *v2; // rax
  hkMemoryAllocator *v3; // r8
  hkArrayBase<hkDefaultMemoryTracker::ClassAlloc> *v4; // rdx

  if ( this != rhs )
  {
    v2 = rhs->m_mem;
    v3 = this->m_mem;
    v4 = &rhs->m_classAllocations;
    this->m_mem = v2;
    *(_QWORD *)&v4[-1].m_size = v3;
    arrayBaseSwap_hkDefaultMemoryTracker::ClassAlloc_(&this->m_classAllocations, v4);
  }
}

// File Line: 74
// RVA: 0x1303210
void __fastcall hkTrackerSnapshot::orderClassAllocs(hkTrackerSnapshot *this)
{
  int v1; // er8

  v1 = this->m_classAllocations.m_size;
  if ( v1 > 1 )
    hkAlgorithm::quickSortRecursive<hkDefaultMemoryTracker::ClassAlloc,unsigned int (*)(hkDefaultMemoryTracker::ClassAlloc const &,hkDefaultMemoryTracker::ClassAlloc const &)>(
      this->m_classAllocations.m_data,
      0,
      v1 - 1,
      compareClassAllocs);
}

// File Line: 99
// RVA: 0x1302CF0
hkResult *__fastcall hkTrackerSnapshot::init(hkTrackerSnapshot *this, hkResult *result, hkMemorySystem *memorySystem, hkDefaultMemoryTracker *tracker)
{
  hkTrackerSnapshot *v4; // r15
  hkMemoryAllocator *v5; // rcx
  hkMemorySystem *v6; // r14
  int v7; // er8
  hkDefaultMemoryTracker *v8; // rsi
  hkResult *v9; // rbp
  hkClass *v10; // rax
  hkMemoryAllocator *v11; // rdx
  signed int *v12; // r8
  int v13; // er9
  int v14; // eax
  int v15; // eax
  __int64 v16; // rbx
  _QWORD **v17; // rax
  int v18; // er9
  int v19; // eax
  int v20; // eax
  __int64 v21; // r9
  signed int v22; // edx
  __int64 v23; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v24; // rax
  signed int v25; // ebx
  const char **v26; // r14
  int v27; // edx
  hkDefaultMemoryTracker::ClassAlloc *v28; // rcx
  __int64 v29; // r9
  __int64 v30; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v31; // rax
  signed int v32; // er8
  hkOstream v34; // [rsp+30h] [rbp-68h]
  hkStreamWriter sw; // [rsp+48h] [rbp-50h]
  signed int *v36; // [rsp+58h] [rbp-40h]
  hkMemoryAllocator *v37; // [rsp+60h] [rbp-38h]
  int v38; // [rsp+68h] [rbp-30h]
  int v39; // [rsp+6Ch] [rbp-2Ch]
  hkResult resulta; // [rsp+A0h] [rbp+8h]

  v4 = this;
  v5 = this->m_mem;
  v6 = memorySystem;
  v7 = v4->m_classAllocations.m_capacityAndFlags;
  v8 = tracker;
  v9 = result;
  v4->m_classAllocations.m_size = 0;
  if ( v7 >= 0 )
    v5->vfptr->bufFree(v5, v4->m_classAllocations.m_data, 32 * v7);
  v4->m_classAllocations.m_data = 0i64;
  v4->m_classAllocations.m_capacityAndFlags = 2147483648;
  if ( v8
    || (v8 = (hkDefaultMemoryTracker *)hkMemoryTracker::s_singleton) != 0i64
    && (v10 = hkMemoryTracker::s_singleton->vfptr->getClassType(hkMemoryTracker::s_singleton),
        hkClass::equals(&hkDefaultMemoryTrackerClass, v10)) )
  {
    if ( !v6 )
      v6 = hkMemorySystem::getInstance();
    hkMemorySnapshot::setAllocator(&v4->m_rawSnapshot, v4->m_mem);
    v6->vfptr->getMemorySnapshot(v6, &resulta, &v4->m_rawSnapshot);
    hkMemorySnapshot::sort(&v4->m_rawSnapshot);
    v11 = v4->m_mem;
    v12 = (signed int *)&v4->m_memSysStatistics;
    v13 = v4->m_memSysStatistics.m_size + 1;
    v38 = v4->m_memSysStatistics.m_size;
    *(_DWORD *)&sw.m_memSizeAndFlags = 0x1FFFF;
    sw.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable';
    v36 = (signed int *)&v4->m_memSysStatistics;
    v37 = v11;
    v39 = 1;
    v14 = v4->m_memSysStatistics.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v14 < v13 )
    {
      v15 = 2 * v14;
      if ( v13 < v15 )
        v13 = v15;
      hkArrayUtil::_reserve(&resulta, v11, v12, v13, 1);
      v12 = v36;
    }
    *(_BYTE *)(v12[2] + *(_QWORD *)v12) = 0;
    hkOstream::hkOstream(&v34, &sw);
    v6->vfptr->printStatistics(v6, &v34);
    hkOstream::~hkOstream(&v34);
    sw.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable';
    if ( !v39 )
    {
      v16 = (__int64)v36;
      if ( v36 )
      {
        v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v17[11] + 16i64))(v17[11], v16, 16i64);
      }
    }
    v18 = v8->m_classAllocMap.m_map.m_numElems & 0x7FFFFFFF;
    v19 = v4->m_classAllocations.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v19 < v18 )
    {
      v20 = 2 * v19;
      if ( v18 < v20 )
        v18 = v20;
      hkArrayUtil::_reserve(&resulta, v4->m_mem, &v4->m_classAllocations, v18, 32);
    }
    v4->m_classAllocations.m_size = 0;
    v21 = v8->m_classAllocMap.m_map.m_hashMod;
    v22 = 0;
    v23 = 0i64;
    if ( (signed int)v21 >= 0 )
    {
      v24 = v8->m_classAllocMap.m_map.m_elem;
      do
      {
        if ( v24->key != -1i64 )
          break;
        ++v23;
        ++v22;
        ++v24;
      }
      while ( v23 <= v21 );
    }
    v25 = v22;
    if ( v22 <= (signed int)v21 )
    {
      do
      {
        v26 = (const char **)v8->m_classAllocMap.m_map.m_elem[v25].val;
        if ( v4->m_classAllocations.m_size == (v4->m_classAllocations.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(v4->m_mem, &v4->m_classAllocations, 32);
        v27 = v25 + 1;
        v28 = &v4->m_classAllocations.m_data[v4->m_classAllocations.m_size++];
        v28->m_typeName = *v26;
        v28->m_size = (unsigned __int64)v26[1];
        v28->m_ptr = (void *)v26[2];
        *(_QWORD *)&v28->m_flags = v26[3];
        v29 = v8->m_classAllocMap.m_map.m_hashMod;
        v30 = v25 + 1;
        if ( v30 <= v29 )
        {
          v31 = &v8->m_classAllocMap.m_map.m_elem[v27];
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
      while ( v27 <= (signed int)v29 );
    }
    v32 = v4->m_classAllocations.m_size;
    if ( v32 > 1 )
      hkAlgorithm::quickSortRecursive<hkDefaultMemoryTracker::ClassAlloc,unsigned int (*)(hkDefaultMemoryTracker::ClassAlloc const &,hkDefaultMemoryTracker::ClassAlloc const &)>(
        v4->m_classAllocations.m_data,
        0,
        v32 - 1,
        compareClassAllocs);
    v9->m_enum = 0;
  }
  else
  {
    v9->m_enum = 1;
  }
  return v9;
}

// File Line: 240
// RVA: 0x1303010
hkResult *__fastcall hkTrackerSnapshot::checkConsistent(hkTrackerSnapshot *this, hkResult *result)
{
  __int64 v2; // rbp
  signed __int64 v3; // r9
  hkResult *v4; // rdi
  hkMemorySnapshot::Allocation *v5; // r8
  __int64 v6; // r15
  __int64 v7; // rsi
  int *v8; // r11
  signed int v9; // er9
  __int64 v10; // r8
  char *v11; // r10
  hkMemorySnapshot::Allocation *v12; // rax
  char *v13; // rdx

  v2 = this->m_rawSnapshot.m_allocations.m_size;
  v3 = 0i64;
  v4 = result;
  if ( (signed int)v2 - 1 > 0 )
  {
    v5 = this->m_rawSnapshot.m_allocations.m_data;
    do
    {
      if ( v5->m_start > v5[1].m_start )
      {
        result->m_enum = 1;
        return result;
      }
      ++v3;
      ++v5;
    }
    while ( v3 < (signed int)v2 - 1 );
  }
  v6 = this->m_classAllocations.m_size;
  v7 = 0i64;
  if ( v6 <= 0 )
  {
LABEL_18:
    v4->m_enum = 0;
    return v4;
  }
  v8 = &this->m_classAllocations.m_data->m_flags;
  while ( 1 )
  {
    if ( *(_BYTE *)v8 & 2 )
      goto LABEL_17;
    v9 = 0;
    v10 = 0i64;
    if ( (signed int)v2 > 0 )
      break;
LABEL_16:
    if ( v9 >= (signed int)v2 )
      goto LABEL_20;
LABEL_17:
    ++v7;
    v8 += 8;
    if ( v7 >= v6 )
      goto LABEL_18;
  }
  v11 = (char *)*((_QWORD *)v8 - 1);
  v12 = this->m_rawSnapshot.m_allocations.m_data;
  while ( 1 )
  {
    v13 = (char *)v12->m_start + v12->m_size;
    if ( v11 < v12->m_start )
      break;
    if ( v11 < v13 )
    {
      if ( &v11[*((_QWORD *)v8 - 2)] > v13 )
        break;
      goto LABEL_16;
    }
    ++v10;
    ++v9;
    ++v12;
    if ( v10 >= v2 )
      goto LABEL_16;
  }
LABEL_20:
  v4->m_enum = 1;
  return v4;
}

// File Line: 306
// RVA: 0x1303110
hkDefaultMemoryTracker::ClassAlloc *__fastcall hkTrackerSnapshot::findClassAllocation(hkTrackerSnapshot *this, const void *ptrIn)
{
  hkDefaultMemoryTracker::ClassAlloc *v2; // r10
  int v3; // ecx
  const void *v4; // r11
  int v5; // er9
  signed __int64 v6; // r8
  unsigned __int64 v7; // rdx

  v2 = this->m_classAllocations.m_data;
  v3 = this->m_classAllocations.m_size;
  v4 = ptrIn;
  if ( v3 <= 0 )
    return 0i64;
  while ( 1 )
  {
    v5 = v3 / 2;
    v6 = (signed __int64)&v2[v3 / 2];
    v7 = *(_QWORD *)(v6 + 16);
    if ( (unsigned __int64)v4 >= v7 )
      break;
    v3 /= 2;
LABEL_6:
    if ( v3 <= 0 )
      return 0i64;
  }
  if ( (unsigned __int64)v4 >= *(_QWORD *)(v6 + 8) + v7 )
  {
    v3 += -1 - v5;
    v2 += v5 + 1;
    goto LABEL_6;
  }
  return &v2[v3 / 2];
}

// File Line: 343
// RVA: 0x1303180
hkMemorySnapshot::Allocation *__fastcall hkTrackerSnapshot::findAllocationForClassAllocation(hkTrackerSnapshot *this, hkDefaultMemoryTracker::ClassAlloc *classAlloc)
{
  hkMemorySnapshot::Allocation *v2; // r10
  int v3; // ecx
  char *v4; // r11
  unsigned __int64 v5; // rbx
  __int64 v6; // r9
  signed __int64 v7; // rdx
  char *v8; // r8

  v2 = this->m_rawSnapshot.m_allocations.m_data;
  v3 = this->m_rawSnapshot.m_allocations.m_size;
  if ( v3 <= 0 )
    return 0i64;
  v4 = (char *)classAlloc->m_ptr;
  v5 = (unsigned __int64)&v4[classAlloc->m_size];
  while ( 1 )
  {
    v6 = v3 / 2;
    v7 = (signed __int64)&v2[v6];
    v8 = (char *)v2[v6].m_start;
    if ( v5 >= (unsigned __int64)v8 )
      break;
    v3 = v6;
LABEL_7:
    if ( v3 <= 0 )
      return 0i64;
  }
  if ( v4 >= &v8[*(signed int *)(v7 + 8)] )
  {
    v3 += -1 - v6;
    v2 += (signed int)v6 + 1;
    goto LABEL_7;
  }
  if ( v4 < v8 || v5 > (unsigned __int64)&v8[*(signed int *)(v7 + 8)] )
    return 0i64;
  return &v2[v6];
}

