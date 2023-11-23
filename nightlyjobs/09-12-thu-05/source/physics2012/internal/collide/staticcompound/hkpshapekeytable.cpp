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
  hkString::memSet(this, -1, 0xFCu);
  this->m_next = 0i64;
}

// File Line: 45
// RVA: 0xDF4D20
void __fastcall hkpShapeKeyTable::Block::~Block(hkpShapeKeyTable::Block *this)
{
  hkpShapeKeyTable::Block *m_next; // rcx

  m_next = this->m_next;
  if ( m_next )
    hkpShapeKeyTable::Block::`scalar deleting destructor(m_next, 1);
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
// attributes: thunk
void __fastcall hkpShapeKeyTable::~hkpShapeKeyTable(hkpShapeKeyTable *this)
{
  hkpShapeKeyTable::clear(this);
}

// File Line: 71
// RVA: 0xDF51B0
void __fastcall hkpShapeKeyTable::clear(hkpShapeKeyTable *this)
{
  __int64 i; // rbx
  hkpShapeKeyTable::Block *m_next; // rdi
  _QWORD **Value; // rax
  hkpShapeKeyTable::Block *m_lists; // rbx
  hkMemoryAllocator **v6; // rax

  if ( this->m_lists )
  {
    for ( i = 0i64; i < 32; ++i )
    {
      m_next = this->m_lists[i].m_next;
      if ( m_next )
      {
        hkpShapeKeyTable::Block::~Block(this->m_lists[i].m_next);
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpShapeKeyTable::Block *, __int64))(*Value[11] + 16i64))(
          Value[11],
          m_next,
          272i64);
      }
    }
    m_lists = this->m_lists;
    v6 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::easyFree(v6[11], m_lists);
    this->m_lists = 0i64;
    this->m_occupancyBitField = 0;
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
  hkMemoryAllocator **Value; // rax
  __int64 v5; // rbx
  __int64 v6; // rsi
  hkpShapeKeyTable::Block *v7; // rcx
  hkpShapeKeyTable::Block *v8; // rbx
  unsigned int i; // esi
  _QWORD **v10; // rax
  hkpShapeKeyTable::Block *v11; // rax
  int v12; // ebp
  __int64 j; // rax
  unsigned int v14; // ecx
  hkpShapeKeyTable::Block **p_m_next; // rbx
  hkpShapeKeyTable::Block *v16; // rdi
  unsigned int v17; // ebx
  _QWORD **v18; // rax
  hkpShapeKeyTable::Block *v19; // rax

  if ( !this->m_lists )
  {
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = 0i64;
    this->m_lists = (hkpShapeKeyTable::Block *)hkMemoryRouter::easyAlloc(Value[11], 8704);
    v6 = 32i64;
    do
    {
      v7 = &this->m_lists[v5];
      if ( v7 )
        hkpShapeKeyTable::Block::Block(v7);
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  this->m_occupancyBitField |= 1 << (((key + 7) ^ (key >> 6)) & 0x1F);
  v8 = &this->m_lists[((unsigned __int8)(key + 7) ^ (unsigned __int8)(key >> 6)) & 0x1F];
  for ( i = v8->m_slots[62]; key > i; i = v8->m_slots[62] )
  {
    if ( !v8->m_next )
    {
      v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v11 = (hkpShapeKeyTable::Block *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v10[11] + 8i64))(v10[11], 272i64);
      if ( v11 )
        hkpShapeKeyTable::Block::Block(v11);
      v8->m_next = v11;
    }
    v8 = v8->m_next;
  }
  v12 = 0;
  for ( j = 0i64; j < 63; ++j )
  {
    v14 = v8->m_slots[j];
    if ( v14 == -1 )
    {
      v8->m_slots[v12] = key;
      return;
    }
    if ( v14 == key )
      return;
    if ( v14 > key )
      break;
    ++v12;
  }
  if ( v12 < 62 )
    hkString::memMove(&v8->m_slots[v12 + 1], &v8->m_slots[v12], 4 * (62 - v12));
  p_m_next = &v8->m_next;
  *((_DWORD *)p_m_next + v12 - 64) = key;
  if ( *p_m_next )
  {
    while ( 1 )
    {
      v16 = *p_m_next;
      v17 = i;
      i = v16->m_slots[62];
      hkString::memMove(&v16->m_slots[1], v16, 0xF8u);
      v16->m_slots[0] = v17;
      if ( i == -1 )
        break;
      p_m_next = &v16->m_next;
      if ( !v16->m_next )
      {
        v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v19 = (hkpShapeKeyTable::Block *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v18[11] + 8i64))(
                                           v18[11],
                                           272i64);
        if ( v19 )
          hkpShapeKeyTable::Block::Block(v19);
        *p_m_next = v19;
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
  unsigned __int8 v3; // bp
  unsigned __int64 v4; // r14
  hkpShapeKeyTable::Block *v5; // rbx
  int v6; // r9d
  __int64 v7; // rax
  unsigned int v8; // ecx
  void **p_m_next; // rdx
  hkpShapeKeyTable::Block *m_next; // rax
  hkpShapeKeyTable::Block *v11; // rdi
  hkpShapeKeyTable::Block *v12; // rcx
  _QWORD **Value; // rax
  hkpShapeKeyTable::Block *m_lists; // rdi
  hkpShapeKeyTable::Block *v15; // rbx
  _QWORD **v16; // rax

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
      p_m_next = (void **)&v5->m_next;
      m_next = v5->m_next;
      if ( m_next )
        v5->m_slots[62] = m_next->m_slots[0];
      else
        v5->m_slots[62] = -1;
      if ( *p_m_next )
      {
        while ( 1 )
        {
          v11 = v5;
          v5 = (hkpShapeKeyTable::Block *)*p_m_next;
          hkString::memMove(*p_m_next, (char *)*p_m_next + 4, 0xF8u);
          if ( v5->m_slots[0] == -1 )
            break;
          p_m_next = (void **)&v5->m_next;
          v12 = v5->m_next;
          if ( v12 )
            v5->m_slots[62] = v12->m_slots[0];
          else
            v5->m_slots[62] = -1;
          if ( !v12 )
            goto LABEL_23;
        }
        hkpShapeKeyTable::Block::~Block(v5);
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpShapeKeyTable::Block *, __int64))(*Value[11] + 16i64))(
          Value[11],
          v5,
          272i64);
        v11->m_next = 0i64;
      }
LABEL_23:
      m_lists = this->m_lists;
      if ( this->m_lists[v3].m_slots[0] == -1 )
        this->m_occupancyBitField &= ~(1 << v3);
      v15 = m_lists[v4].m_next;
      if ( v15 )
      {
        while ( v15->m_slots[0] != -1 )
          ;
        hkpShapeKeyTable::Block::~Block(m_lists[v4].m_next);
        v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpShapeKeyTable::Block *, __int64))(*v16[11] + 16i64))(v16[11], v15, 272i64);
        m_lists[v4].m_next = 0i64;
      }
      if ( !this->m_occupancyBitField )
        hkpShapeKeyTable::clear(this);
      return;
    }
  }
}

// File Line: 307
// RVA: 0xDF5270
void __fastcall hkpShapeKeyTable::getDistribution(
        hkpShapeKeyTable *this,
        hkArray<int,hkContainerHeapAllocator> *counts)
{
  __int64 v2; // rsi
  int v5; // r9d
  __int64 m_size; // rdx
  int *v7; // rdi
  __int64 v8; // rcx
  __int64 v9; // rdi
  __int64 v10; // r10
  hkpShapeKeyTable::Block *i; // r9
  int v12; // edx
  unsigned int *v13; // rax
  __int64 v14; // r8
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  v2 = 32i64;
  if ( (counts->m_capacityAndFlags & 0x3FFFFFFFu) < 0x20 )
  {
    v5 = 32;
    if ( 2 * (counts->m_capacityAndFlags & 0x3FFFFFFF) > 32 )
      v5 = 2 * (counts->m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&counts->m_data, v5, 4);
  }
  m_size = counts->m_size;
  v7 = &counts->m_data[m_size];
  v8 = 32 - (int)m_size;
  if ( 32 - (int)m_size > 0 )
  {
    while ( v8 )
    {
      *v7++ = 0;
      --v8;
    }
  }
  counts->m_size = 32;
  if ( this->m_lists )
  {
    v9 = 0i64;
    v10 = 0i64;
    do
    {
      for ( i = &this->m_lists[v10]; i; i = i->m_next )
      {
        v12 = 0;
        v13 = &i->m_slots[2];
        v14 = 0i64;
        while ( *(v13 - 2) != -1 )
        {
          ++counts->m_data[v9];
          if ( *(v13 - 1) == -1 )
          {
            ++v12;
            break;
          }
          ++counts->m_data[v9];
          if ( *v13 == -1 )
          {
            v12 += 2;
            break;
          }
          v14 += 3i64;
          v13 += 3;
          ++counts->m_data[v9];
          v12 += 3;
          if ( v14 >= 63 )
            break;
        }
        if ( v12 < 63 )
          break;
      }
      ++v10;
      ++v9;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 341
// RVA: 0xDF5130
char __fastcall hkpShapeKeyTable::exists(hkpShapeKeyTable *this, unsigned int key)
{
  unsigned int m_occupancyBitField; // eax
  int v4; // edx
  hkpShapeKeyTable::Block *v5; // rax
  int v7; // r9d
  int v8; // r10d
  int v9; // edx
  unsigned int v10; // r11d

  m_occupancyBitField = this->m_occupancyBitField;
  v4 = ((unsigned __int8)(key + 7) ^ (unsigned __int8)(key >> 6)) & 0x1F;
  if ( !_bittest((const int *)&m_occupancyBitField, v4) )
    return 0;
  v5 = &this->m_lists[v4];
  while ( key > v5->m_slots[62] )
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
    if ( key < v10 )
    {
      v8 = v9 - 1;
      goto LABEL_11;
    }
    if ( key == v10 )
      return 1;
    v7 = v9 + 1;
LABEL_11:
    if ( v7 > v8 )
      return 0;
  }
}

