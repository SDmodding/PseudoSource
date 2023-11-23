// File Line: 16
// RVA: 0xE0A210
void __fastcall hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(hkQueue<hkpRigidBody *> *this)
{
  this->m_data = 0i64;
  *(_QWORD *)&this->m_capacity = 0i64;
  *(_QWORD *)&this->m_tail = 0i64;
}

// File Line: 34
// RVA: 0xB59D60
void __fastcall hkQueue<int>::~hkQueue<int>(hkQueue<int> *this)
{
  int m_capacity; // edi
  int *m_data; // rbx
  _QWORD **Value; // rax

  m_capacity = this->m_capacity;
  if ( m_capacity )
  {
    m_data = this->m_data;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, int *, _QWORD))(*Value[11] + 16i64))(
      Value[11],
      m_data,
      (unsigned int)(4 * m_capacity));
  }
}

// File Line: 94
// RVA: 0xB5A9E0
void __fastcall hkQueue<int>::setCapacity(hkQueue<int> *this, int n)
{
  int m_capacity; // eax
  int v3; // esi
  int v5; // eax
  _QWORD **Value; // rax
  int *v7; // rax
  int *v8; // r14
  int *m_data; // rcx
  int m_elementsInUse; // r8d
  int m_tail; // ebp
  __int64 m_head; // rdx
  int v13; // ebx
  int *v14; // rdx
  int *v15; // rcx
  int v16; // r8d
  int v17; // eax
  int v18; // ebp
  int *v19; // rbx
  _QWORD **v20; // rax

  m_capacity = this->m_capacity;
  v3 = n;
  if ( m_capacity < n )
  {
    v5 = 2 * m_capacity;
    if ( v5 >= n )
      v3 = v5;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (int *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(Value[11], (unsigned int)(4 * v3));
    v8 = v7;
    if ( v7 )
    {
      m_data = this->m_data;
      if ( this->m_data )
      {
        m_elementsInUse = this->m_elementsInUse;
        if ( m_elementsInUse )
        {
          m_tail = this->m_tail;
          m_head = this->m_head;
          if ( m_tail > (int)m_head )
          {
            v14 = &m_data[m_head];
            v16 = 4 * m_elementsInUse;
            v15 = v7;
          }
          else
          {
            v13 = this->m_capacity - m_head;
            hkString::memCpy(v7, &m_data[m_head], 4 * v13);
            v14 = this->m_data;
            v15 = &v8[v13];
            v16 = 4 * m_tail;
          }
          hkString::memCpy(v15, v14, v16);
        }
        v17 = this->m_elementsInUse;
        this->m_head = 0;
        this->m_tail = v17;
      }
    }
    v18 = this->m_capacity;
    if ( v18 )
    {
      v19 = this->m_data;
      v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, int *, _QWORD))(*v20[11] + 16i64))(v20[11], v19, (unsigned int)(4 * v18));
    }
    this->m_data = v8;
    this->m_capacity = v3;
  }
}

// File Line: 154
// RVA: 0xC64FE0
void __fastcall hkQueue<hkJobQueue::JobQueueEntry>::enqueue(
        hkQueue<hkJobQueue::JobQueueEntry> *this,
        hkJobQueue::JobQueueEntry *element)
{
  int m_capacity; // edx
  int v5; // edx
  hkJobQueue::JobQueueEntry *v6; // rcx
  __int64 v7; // rax
  hkJob v8; // xmm0

  m_capacity = this->m_capacity;
  if ( this->m_elementsInUse >= m_capacity )
  {
    if ( m_capacity )
      v5 = 2 * m_capacity;
    else
      v5 = 8;
    hkQueue<hkJobQueue::JobQueueEntry>::setCapacity(this, v5);
  }
  if ( this->m_tail == this->m_capacity )
    this->m_tail = 0;
  v6 = &this->m_data[(__int64)this->m_tail];
  if ( ((LOBYTE(this->m_data) | (unsigned __int8)element) & 0xF) != 0 )
  {
    memmove(v6, element, 0x100ui64);
    ++this->m_tail;
    ++this->m_elementsInUse;
  }
  else
  {
    v7 = 2i64;
    do
    {
      v8 = element->hkJob;
      v6 = (hkJobQueue::JobQueueEntry *)((char *)v6 + 128);
      element = (hkJobQueue::JobQueueEntry *)((char *)element + 128);
      *((hkJob *)v6 - 8) = v8;
      *(_OWORD *)&v6[-1].m_data[128] = *(_OWORD *)&element[-1].m_data[128];
      *(_OWORD *)&v6[-1].m_data[144] = *(_OWORD *)&element[-1].m_data[144];
      *(_OWORD *)&v6[-1].m_data[160] = *(_OWORD *)&element[-1].m_data[160];
      *(_OWORD *)&v6[-1].m_data[176] = *(_OWORD *)&element[-1].m_data[176];
      *(_OWORD *)&v6[-1].m_data[192] = *(_OWORD *)&element[-1].m_data[192];
      *(_OWORD *)&v6[-1].m_data[208] = *(_OWORD *)&element[-1].m_data[208];
      *(_OWORD *)&v6[-1].m_data[224] = *(_OWORD *)&element[-1].m_data[224];
      --v7;
    }
    while ( v7 );
    ++this->m_tail;
    ++this->m_elementsInUse;
  }
}

// File Line: 174
// RVA: 0xC650C0
void __fastcall hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(
        hkQueue<hkJobQueue::JobQueueEntry> *this,
        hkJobQueue::JobQueueEntry *element)
{
  int m_capacity; // edx
  int v5; // edx
  hkJobQueue::JobQueueEntry *v6; // rcx
  __int64 v7; // rax
  hkJob v8; // xmm0

  m_capacity = this->m_capacity;
  if ( this->m_elementsInUse >= m_capacity )
  {
    if ( m_capacity )
      v5 = 2 * m_capacity;
    else
      v5 = 8;
    hkQueue<hkJobQueue::JobQueueEntry>::setCapacity(this, v5);
  }
  if ( !this->m_head )
    this->m_head = this->m_capacity;
  v6 = &this->m_data[(__int64)--this->m_head];
  if ( ((LOBYTE(this->m_data) | (unsigned __int8)element) & 0xF) != 0 )
  {
    memmove(v6, element, 0x100ui64);
    ++this->m_elementsInUse;
  }
  else
  {
    v7 = 2i64;
    do
    {
      v8 = element->hkJob;
      v6 = (hkJobQueue::JobQueueEntry *)((char *)v6 + 128);
      element = (hkJobQueue::JobQueueEntry *)((char *)element + 128);
      *((hkJob *)v6 - 8) = v8;
      *(_OWORD *)&v6[-1].m_data[128] = *(_OWORD *)&element[-1].m_data[128];
      *(_OWORD *)&v6[-1].m_data[144] = *(_OWORD *)&element[-1].m_data[144];
      *(_OWORD *)&v6[-1].m_data[160] = *(_OWORD *)&element[-1].m_data[160];
      *(_OWORD *)&v6[-1].m_data[176] = *(_OWORD *)&element[-1].m_data[176];
      *(_OWORD *)&v6[-1].m_data[192] = *(_OWORD *)&element[-1].m_data[192];
      *(_OWORD *)&v6[-1].m_data[208] = *(_OWORD *)&element[-1].m_data[208];
      *(_OWORD *)&v6[-1].m_data[224] = *(_OWORD *)&element[-1].m_data[224];
      --v7;
    }
    while ( v7 );
    ++this->m_elementsInUse;
  }
}

