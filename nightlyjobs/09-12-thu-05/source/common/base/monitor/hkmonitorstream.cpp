// File Line: 15
// RVA: 0x15C75C0
__int64 dynamic_initializer_for__hkMonitorStream__m_instance__()
{
  hkMonitorStream__m_instance.m_slotID = TlsAlloc();
  return atexit(dynamic_atexit_destructor_for__hkMonitorStream__m_instance__);
}

// File Line: 24
// RVA: 0xC5C560
void hkMonitorStream::init(void)
{
  _QWORD **v0; // rax
  _QWORD *v1; // rbx

  v0 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v1 = (_QWORD *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v0[12] + 8i64))(v0[12], 40i64);
  TlsSetValue(hkMonitorStream__m_instance.m_slotID, v1);
  *((_BYTE *)v1 + 32) = 0;
  *v1 = 0i64;
  v1[2] = 0i64;
  v1[1] = 0i64;
  v1[3] = 0i64;
}

// File Line: 43
// RVA: 0xC5C5C0
void __fastcall hkMonitorStream::quit(hkMonitorStream *this)
{
  hkMonitorStream *v1; // rbx
  LPVOID v2; // rax
  char *v3; // rdi
  LPVOID v4; // rsi
  char *v5; // rbx
  _QWORD **v6; // rax
  _QWORD **v7; // rax

  v1 = this;
  v2 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = v1->m_start.m_storage;
  v4 = v2;
  if ( v1->m_start.m_storage && v1->m_isBufferAllocatedOnTheHeap.m_bool )
  {
    v5 = v1->m_capacity.m_storage;
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v6[12] + 32i64))(
      v6[12],
      v3,
      (unsigned int)((_DWORD)v5 - (_DWORD)v3));
  }
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, LPVOID, signed __int64))(*v7[12] + 16i64))(v7[12], v4, 40i64);
  TlsSetValue(hkMonitorStream__m_instance.m_slotID, 0i64);
}

// File Line: 58
// RVA: 0xC5C440
void __fastcall hkMonitorStream::resize(hkMonitorStream *this, int newSize)
{
  char *v2; // rbp
  char *v3; // rdi
  int v4; // esi
  hkMonitorStream *v5; // rbx
  _QWORD **v6; // rax
  _QWORD **v7; // rax
  __int64 v8; // rax
  __int64 v9; // rcx
  char *v10; // rax
  int v11; // [rsp+38h] [rbp+10h]

  v2 = this->m_capacity.m_storage;
  v3 = this->m_start.m_storage;
  v4 = newSize;
  v5 = this;
  if ( (char *)newSize != (char *)(this->m_capacity.m_storage - this->m_start.m_storage) )
  {
    if ( newSize <= 0 )
    {
      hkMonitorStream::quit(this);
    }
    else
    {
      if ( v3 )
      {
        if ( this->m_isBufferAllocatedOnTheHeap.m_bool )
        {
          v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v6[12] + 32i64))(
            v6[12],
            v3,
            (unsigned int)((_DWORD)v2 - (_DWORD)v3));
        }
      }
      v5->m_isBufferAllocatedOnTheHeap.m_bool = 1;
      v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v11 = v4;
      v8 = (*(__int64 (__fastcall **)(_QWORD *, int *))(*v7[12] + 24i64))(v7[12], &v11);
      v9 = v11;
      v5->m_start.m_storage = (char *)v8;
      v5->m_end.m_storage = (char *)v8;
      v10 = (char *)(v9 + v8);
      v5->m_capacity.m_storage = v10;
      v5->m_capacityMinus16.m_storage = v10 - 32;
    }
  }
}

// File Line: 93
// RVA: 0xC5C500
void __fastcall hkMonitorStream::setStaticBuffer(hkMonitorStream *this, char *buffer, int bufferSize)
{
  __int64 v3; // rsi
  char *v4; // rdi
  hkMonitorStream *v5; // rbx

  v3 = bufferSize;
  v4 = buffer;
  v5 = this;
  if ( this->m_isBufferAllocatedOnTheHeap.m_bool )
    hkMonitorStream::resize(this, 0);
  v5->m_isBufferAllocatedOnTheHeap.m_bool = 0;
  v5->m_capacity.m_storage = &v4[v3];
  v5->m_start.m_storage = v4;
  v5->m_capacityMinus16.m_storage = &v4[v3 - 32];
  v5->m_end.m_storage = v4;
}

// File Line: 109
// RVA: 0xC5C430
void __fastcall hkMonitorStream::reset(hkMonitorStream *this)
{
  this->m_end.m_storage = this->m_start.m_storage;
}

