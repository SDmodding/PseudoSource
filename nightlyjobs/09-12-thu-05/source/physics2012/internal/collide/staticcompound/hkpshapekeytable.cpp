// File Line: 28
// RVA: 0xDF5390
__int64 __fastcall anonymous_namespace_::hashShapeKeyToListIndex(unsigned int key)
{
  return ((unsigned __int8)(key + 7) ^ (unsigned __int8)(key >> 6)) & 0x1F;
}

// File Line: 39
// RVA: 0xDF4CE0
void __fastcall hkpShapeKeyTable::Block::Block(hkpShapeKeyTable::Block *this)
{
  hkpShapeKeyTable::Block *v1; // rbx

  v1 = this;
  hkString::memSet(this, -1, 252);
  v1->m_next = 0i64;
}

// File Line: 45
// RVA: 0xDF4D20
void __fastcall hkpShapeKeyTable::Block::~Block(hkpShapeKeyTable::Block *this)
{
  hkpShapeKeyTable::Block *v1; // rcx

  v1 = this->m_next;
  if ( v1 )
    hkpShapeKeyTable::Block::`scalar deleting destructor'(v1, 1);
}

// File Line: 56
// RVA: 0xDF4D40
void __fastcall hkpShapeKeyTable::hkpShapeKeyTable(hkpShapeKeyTable *this)
{
  this->m_lists = 0i64;
  this->m_occupancyBitField = 0;
}

// File Line: 61
// RVA: 0xDF4D60
void __fastcall hkpShapeKeyTable::hkpShapeKeyTable(hkpShapeKeyTable *this, hkFinishLoadedObjectFlag flag)
{
  ;
}

// File Line: 66
// RVA: 0xDF4D70
void __fastcall hkpShapeKeyTable::~hkpShapeKeyTable(hkpShapeKeyTable *this)
{
  hkpShapeKeyTable::clear(this);
}

// File Line: 71
// RVA: 0xDF51B0
void __fastcall hkpShapeKeyTable::clear(hkpShapeKeyTable *this)
{
  hkpShapeKeyTable *v1; // rsi
  signed __int64 v2; // rbx
  hkpShapeKeyTable::Block *v3; // rdi
  _QWORD **v4; // rax
  hkpShapeKeyTable::Block *v5; // rbx
  hkMemoryAllocator **v6; // rax

  v1 = this;
  if ( this->m_lists )
  {
    v2 = 0i64;
    do
    {
      v3 = v1->m_lists[v2].m_next;
      if ( v3 )
      {
        hkpShapeKeyTable::Block::~Block(v1->m_lists[v2].m_next);
        v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpShapeKeyTable::Block *, signed __int64))(*v4[11] + 16i64))(
          v4[11],
          v3,
          272i64);
      }
      ++v2;
    }
    while ( v2 < 32 );
    v5 = v1->m_lists;
    v6 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::easyFree(v6[11], v5);
    v1->m_lists = 0i64;
    v1->m_occupancyBitField = 0;
  }
  else
  {
    this->m_occupancyBitField = 0;
  }
}

// File Line: 92
// RVA: 0xDF4D80
void __fastcall hkpShapeKeyTable::insert(hkpShapeKeyTable *this, unsigned int key)
{
  unsigned int v2; // edi
  hkpShapeKeyTable *v3; // r14
  hkMemoryAllocator **v4; // rax
  __int64 v5; // rbx
  signed __int64 v6; // rsi
  hkpShapeKeyTable::Block *v7; // rcx
  signed __int64 v8; // rbx
  unsigned int i; // esi
  _QWORD **v10; // rax
  hkpShapeKeyTable::Block *v11; // rax
  signed int v12; // ebp
  signed __int64 v13; // rax
  unsigned int v14; // ecx
  hkpShapeKeyTable::Block **v15; // rbx
  hkpShapeKeyTable::Block *v16; // rdi
  unsigned int v17; // ebx
  _QWORD **v18; // rax
  hkpShapeKeyTable::Block *v19; // rax

  v2 = key;
  v3 = this;
  if ( !this->m_lists )
  {
    v4 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = 0i64;
    v3->m_lists = (hkpShapeKeyTable::Block *)hkMemoryRouter::easyAlloc(v4[11], 8704);
    v6 = 32i64;
    do
    {
      v7 = &v3->m_lists[v5];
      if ( v7 )
        hkpShapeKeyTable::Block::Block(v7);
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  v3->m_occupancyBitField |= 1 << (((v2 + 7) ^ (v2 >> 6)) & 0x1F);
  v8 = (signed __int64)&v3->m_lists[((unsigned __int8)(v2 + 7) ^ (unsigned __int8)(v2 >> 6)) & 0x1F];
  for ( i = *(_DWORD *)(v8 + 248); v2 > i; i = *(_DWORD *)(v8 + 248) )
  {
    if ( !*(_QWORD *)(v8 + 256) )
    {
      v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v11 = (hkpShapeKeyTable::Block *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(
                                         v10[11],
                                         272i64);
      if ( v11 )
        hkpShapeKeyTable::Block::Block(v11);
      *(_QWORD *)(v8 + 256) = v11;
    }
    v8 = *(_QWORD *)(v8 + 256);
  }
  v12 = 0;
  v13 = 0i64;
  do
  {
    v14 = *(_DWORD *)(v8 + 4 * v13);
    if ( v14 == -1 )
    {
      *(_DWORD *)(v8 + 4i64 * v12) = v2;
      return;
    }
    if ( v14 == v2 )
      return;
    if ( v14 > v2 )
      break;
    ++v13;
    ++v12;
  }
  while ( v13 < 63 );
  if ( v12 < 62 )
    hkString::memMove((void *)(v8 + 4i64 * (v12 + 1)), (const void *)(v8 + 4i64 * v12), 4 * (62 - v12));
  v15 = (hkpShapeKeyTable::Block **)(v8 + 256);
  *((_DWORD *)v15 + v12 - 64) = v2;
  if ( *v15 )
  {
    while ( 1 )
    {
      v16 = *v15;
      v17 = i;
      i = v16->m_slots[62];
      hkString::memMove(&v16->m_slots[1], v16, 248);
      v16->m_slots[0] = v17;
      if ( i == -1 )
        break;
      v15 = &v16->m_next;
      if ( !v16->m_next )
      {
        v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v19 = (hkpShapeKeyTable::Block *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(
                                           v18[11],
                                           272i64);
        if ( v19 )
          hkpShapeKeyTable::Block::Block(v19);
        *v15 = v19;
        if ( !v19 )
          break;
      }
    }
  }
}

// File Line: 189
// RVA: 0xDF4F50
void __fastcall hkpShapeKeyTable::remove(hkpShapeKeyTable *this, unsigned int key)
{
  hkpShapeKeyTable *v2; // rsi
  unsigned __int8 v3; // bp
  unsigned __int64 v4; // r14
  hkpShapeKeyTable::Block *v5; // rbx
  int v6; // er9
  signed __int64 v7; // rax
  unsigned int v8; // ecx
  void **v9; // rdx
  hkpShapeKeyTable::Block *v10; // rax
  hkpShapeKeyTable::Block *v11; // rdi
  hkpShapeKeyTable::Block *v12; // rcx
  _QWORD **v13; // rax
  hkpShapeKeyTable::Block *v14; // rdi
  hkpShapeKeyTable::Block *v15; // rbx
  _QWORD **v16; // rax

  v2 = this;
  if ( this->m_lists )
  {
    v3 = ((key + 7) ^ (key >> 6)) & 0x1F;
    v4 = v3;
    v5 = &this->m_lists[v4];
    while ( key > v5->m_slots[62] )
    {
      v5 = v5->m_next;
      if ( !v5 )
        return;
    }
    v6 = 0;
    v7 = 0i64;
    while ( 1 )
    {
      v8 = v5->m_slots[v7];
      if ( v8 > key )
        break;
      if ( v8 != key )
      {
        ++v7;
        ++v6;
        if ( v7 < 63 )
          continue;
      }
      if ( v6 + 1 < 62 )
        hkString::memMove(&v5->m_slots[v6], &v5->m_slots[v6 + 1], 4 * (62 - v6));
      v9 = (void **)&v5->m_next;
      v10 = v5->m_next;
      if ( v10 )
        v5->m_slots[62] = v10->m_slots[0];
      else
        v5->m_slots[62] = -1;
      if ( *v9 )
      {
        while ( 1 )
        {
          v11 = v5;
          v5 = (hkpShapeKeyTable::Block *)*v9;
          hkString::memMove(*v9, (char *)*v9 + 4, 248);
          if ( v5->m_slots[0] == -1 )
            break;
          v9 = (void **)&v5->m_next;
          v12 = v5->m_next;
          if ( v12 )
            v5->m_slots[62] = v12->m_slots[0];
          else
            v5->m_slots[62] = -1;
          if ( !v12 )
            goto LABEL_23;
        }
        hkpShapeKeyTable::Block::~Block(v5);
        v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpShapeKeyTable::Block *, signed __int64))(*v13[11] + 16i64))(
          v13[11],
          v5,
          272i64);
        v11->m_next = 0i64;
      }
LABEL_23:
      v14 = v2->m_lists;
      if ( v2->m_lists[v4].m_slots[0] == -1 )
        v2->m_occupancyBitField &= ~(1 << v3);
      v15 = v14[v4].m_next;
      if ( v15 )
      {
        while ( v15->m_slots[0] != -1 )
          ;
        hkpShapeKeyTable::Block::~Block(v14[v4].m_next);
        v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpShapeKeyTable::Block *, signed __int64))(*v16[11] + 16i64))(
          v16[11],
          v15,
          272i64);
        v14[v4].m_next = 0i64;
      }
      if ( !v2->m_occupancyBitField )
        hkpShapeKeyTable::clear(v2);
      return;
    }
  }
}

// File Line: 307
// RVA: 0xDF5270
void __fastcall hkpShapeKeyTable::getDistribution(hkpShapeKeyTable *this, hkArray<int,hkContainerHeapAllocator> *counts)
{
  signed __int64 v2; // rsi
  hkArray<int,hkContainerHeapAllocator> *v3; // rbx
  int v4; // eax
  hkpShapeKeyTable *v5; // r14
  int v6; // eax
  int v7; // er9
  __int64 v8; // rdx
  int *v9; // rdi
  __int64 v10; // rcx
  __int64 v11; // rdi
  __int64 v12; // r10
  hkpShapeKeyTable::Block *i; // r9
  signed int v14; // edx
  unsigned int *v15; // rax
  signed __int64 v16; // r8
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = 32i64;
  v3 = counts;
  v4 = counts->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = this;
  if ( v4 < 32 )
  {
    v6 = 2 * v4;
    v7 = 32;
    if ( v6 > 32 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, counts, v7, 4);
  }
  v8 = v3->m_size;
  v9 = &v3->m_data[v8];
  v10 = 32 - (signed int)v8;
  if ( 32 - (signed int)v8 > 0 )
  {
    while ( v10 )
    {
      *v9 = 0;
      ++v9;
      --v10;
    }
  }
  v3->m_size = 32;
  if ( v5->m_lists )
  {
    v11 = 0i64;
    v12 = 0i64;
    do
    {
      for ( i = &v5->m_lists[v12]; i; i = i->m_next )
      {
        v14 = 0;
        v15 = &i->m_slots[2];
        v16 = 0i64;
        while ( *(v15 - 2) != -1 )
        {
          ++v3->m_data[v11];
          if ( *(v15 - 1) == -1 )
          {
            ++v14;
            break;
          }
          ++v3->m_data[v11];
          if ( *v15 == -1 )
          {
            v14 += 2;
            break;
          }
          v16 += 3i64;
          v15 += 3;
          ++v3->m_data[v11];
          v14 += 3;
          if ( v16 >= 63 )
            break;
        }
        if ( v14 < 63 )
          break;
      }
      ++v12;
      ++v11;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 341
// RVA: 0xDF5130
char __fastcall hkpShapeKeyTable::exists(hkpShapeKeyTable *this, unsigned int key)
{
  unsigned int v2; // er8
  unsigned int v3; // eax
  int v4; // edx
  hkpShapeKeyTable::Block *v5; // rax
  int v7; // er9
  int v8; // er10
  int v9; // edx
  unsigned int v10; // er11

  v2 = key;
  v3 = this->m_occupancyBitField;
  v4 = ((unsigned __int8)(key + 7) ^ (unsigned __int8)(key >> 6)) & 0x1F;
  if ( !_bittest((const signed int *)&v3, v4) )
    return 0;
  v5 = &this->m_lists[v4];
  while ( v2 > v5->m_slots[62] )
  {
    v5 = v5->m_next;
    if ( !v5 )
      return 0;
  }
  v7 = 0;
  v8 = 62;
  while ( 1 )
  {
    v9 = (v8 + v7) >> 1;
    v10 = v5->m_slots[v9];
    if ( v2 < v10 )
    {
      v8 = v9 - 1;
      goto LABEL_11;
    }
    if ( v2 == v10 )
      return 1;
    v7 = v9 + 1;
LABEL_11:
    if ( v7 > v8 )
      return 0;
  }
}

