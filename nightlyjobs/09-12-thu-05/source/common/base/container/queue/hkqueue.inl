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
  int v1; // edi
  int *v2; // rbx
  _QWORD **v3; // rax

  v1 = this->m_capacity;
  if ( v1 )
  {
    v2 = this->m_data;
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, int *, _QWORD))(*v3[11] + 16i64))(v3[11], v2, (unsigned int)(4 * v1));
  }
}

// File Line: 94
// RVA: 0xB5A9E0
void __fastcall hkQueue<int>::setCapacity(hkQueue<int> *this, int n)
{
  int v2; // eax
  int v3; // esi
  hkQueue<int> *v4; // rdi
  int v5; // eax
  _QWORD **v6; // rax
  int *v7; // rax
  int *v8; // r14
  int *v9; // rcx
  int v10; // er8
  signed int v11; // ebp
  __int64 v12; // rdx
  int v13; // ebx
  int *v14; // rdx
  int *v15; // rcx
  int v16; // er8
  int v17; // eax
  int v18; // ebp
  int *v19; // rbx
  _QWORD **v20; // rax

  v2 = this->m_capacity;
  v3 = n;
  v4 = this;
  if ( v2 < n )
  {
    v5 = 2 * v2;
    if ( v5 >= n )
      v3 = v5;
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (int *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v6[11] + 8i64))(v6[11], (unsigned int)(4 * v3));
    v8 = v7;
    if ( v7 )
    {
      v9 = v4->m_data;
      if ( v4->m_data )
      {
        v10 = v4->m_elementsInUse;
        if ( v10 )
        {
          v11 = v4->m_tail;
          v12 = v4->m_head;
          if ( v11 > (signed int)v12 )
          {
            v14 = &v9[v12];
            v16 = 4 * v10;
            v15 = v7;
          }
          else
          {
            v13 = v4->m_capacity - v12;
            hkString::memCpy(v7, &v9[v12], 4 * v13);
            v14 = v4->m_data;
            v15 = &v8[v13];
            v16 = 4 * v11;
          }
          hkString::memCpy(v15, v14, v16);
        }
        v17 = v4->m_elementsInUse;
        v4->m_head = 0;
        v4->m_tail = v17;
      }
    }
    v18 = v4->m_capacity;
    if ( v18 )
    {
      v19 = v4->m_data;
      v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, int *, _QWORD))(*v20[11] + 16i64))(v20[11], v19, (unsigned int)(4 * v18));
    }
    v4->m_data = v8;
    v4->m_capacity = v3;
  }
}

// File Line: 154
// RVA: 0xC64FE0
void __fastcall hkQueue<hkJobQueue::JobQueueEntry>::enqueue(hkQueue<hkJobQueue::JobQueueEntry> *this, hkJobQueue::JobQueueEntry *element)
{
  hkJobQueue::JobQueueEntry *v2; // rdi
  int v3; // edx
  hkQueue<hkJobQueue::JobQueueEntry> *v4; // rbx
  int v5; // edx
  hkJobQueue::JobQueueEntry *v6; // rcx
  signed __int64 v7; // rax
  hkJob v8; // xmm0

  v2 = element;
  v3 = this->m_capacity;
  v4 = this;
  if ( this->m_elementsInUse >= v3 )
  {
    if ( v3 )
      v5 = 2 * v3;
    else
      v5 = 8;
    hkQueue<hkJobQueue::JobQueueEntry>::setCapacity(this, v5);
  }
  if ( v4->m_tail == v4->m_capacity )
    v4->m_tail = 0;
  v6 = &v4->m_data[(signed __int64)v4->m_tail];
  if ( (LOBYTE(v4->m_data) | (unsigned __int8)v2) & 0xF )
  {
    memmove(v6, v2, 0x100ui64);
    ++v4->m_tail;
    ++v4->m_elementsInUse;
  }
  else
  {
    v7 = 2i64;
    do
    {
      v8 = v2->0;
      v6 = (hkJobQueue::JobQueueEntry *)((char *)v6 + 128);
      v2 = (hkJobQueue::JobQueueEntry *)((char *)v2 + 128);
      *(hkJob *)&v6[-1].m_data[112] = v8;
      *(_OWORD *)&v6[-1].m_data[128] = *(_OWORD *)&v2[-1].m_data[128];
      *(_OWORD *)&v6[-1].m_data[144] = *(_OWORD *)&v2[-1].m_data[144];
      *(_OWORD *)&v6[-1].m_data[160] = *(_OWORD *)&v2[-1].m_data[160];
      *(_OWORD *)&v6[-1].m_data[176] = *(_OWORD *)&v2[-1].m_data[176];
      *(_OWORD *)&v6[-1].m_data[192] = *(_OWORD *)&v2[-1].m_data[192];
      *(_OWORD *)&v6[-1].m_data[208] = *(_OWORD *)&v2[-1].m_data[208];
      *(_OWORD *)&v6[-1].m_data[224] = *(_OWORD *)&v2[-1].m_data[224];
      --v7;
    }
    while ( v7 );
    ++v4->m_tail;
    ++v4->m_elementsInUse;
  }
}

// File Line: 174
// RVA: 0xC650C0
void __fastcall hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(hkQueue<hkJobQueue::JobQueueEntry> *this, hkJobQueue::JobQueueEntry *element)
{
  hkJobQueue::JobQueueEntry *v2; // rbx
  int v3; // edx
  hkQueue<hkJobQueue::JobQueueEntry> *v4; // rdi
  int v5; // edx
  hkJobQueue::JobQueueEntry *v6; // rcx
  signed __int64 v7; // rax
  hkJob v8; // xmm0

  v2 = element;
  v3 = this->m_capacity;
  v4 = this;
  if ( this->m_elementsInUse >= v3 )
  {
    if ( v3 )
      v5 = 2 * v3;
    else
      v5 = 8;
    hkQueue<hkJobQueue::JobQueueEntry>::setCapacity(this, v5);
  }
  if ( !v4->m_head )
    v4->m_head = v4->m_capacity;
  v6 = &v4->m_data[(signed __int64)--v4->m_head];
  if ( (LOBYTE(v4->m_data) | (unsigned __int8)v2) & 0xF )
  {
    memmove(v6, v2, 0x100ui64);
    ++v4->m_elementsInUse;
  }
  else
  {
    v7 = 2i64;
    do
    {
      v8 = v2->0;
      v6 = (hkJobQueue::JobQueueEntry *)((char *)v6 + 128);
      v2 = (hkJobQueue::JobQueueEntry *)((char *)v2 + 128);
      *(hkJob *)&v6[-1].m_data[112] = v8;
      *(_OWORD *)&v6[-1].m_data[128] = *(_OWORD *)&v2[-1].m_data[128];
      *(_OWORD *)&v6[-1].m_data[144] = *(_OWORD *)&v2[-1].m_data[144];
      *(_OWORD *)&v6[-1].m_data[160] = *(_OWORD *)&v2[-1].m_data[160];
      *(_OWORD *)&v6[-1].m_data[176] = *(_OWORD *)&v2[-1].m_data[176];
      *(_OWORD *)&v6[-1].m_data[192] = *(_OWORD *)&v2[-1].m_data[192];
      *(_OWORD *)&v6[-1].m_data[208] = *(_OWORD *)&v2[-1].m_data[208];
      *(_OWORD *)&v6[-1].m_data[224] = *(_OWORD *)&v2[-1].m_data[224];
      --v7;
    }
    while ( v7 );
    ++v4->m_elementsInUse;
  }
}

