// File Line: 15
// RVA: 0x15C75C0
__int64 dynamic_initializer_for__hkMonitorStream__m_instance__()
{
  hkMonitorStream__m_instance.m_slotID = TlsAlloc();
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__hkMonitorStream__m_instance__);
}

// File Line: 24
// RVA: 0xC5C560
void hkMonitorStream::init(void)
{
  _QWORD **Value; // rax
  _QWORD *v1; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v1 = (_QWORD *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[12] + 8i64))(Value[12], 40i64);
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
  LPVOID Value; // rax
  char *m_storage; // rdi
  LPVOID v4; // rsi
  char *v5; // rbx
  _QWORD **v6; // rax
  _QWORD **v7; // rax

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  m_storage = this->m_start.m_storage;
  v4 = Value;
  if ( this->m_start.m_storage && this->m_isBufferAllocatedOnTheHeap.m_bool )
  {
    v5 = this->m_capacity.m_storage;
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v6[12] + 32i64))(
      v6[12],
      m_storage,
      (unsigned int)((_DWORD)v5 - (_DWORD)m_storage));
  }
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, LPVOID, __int64))(*v7[12] + 16i64))(v7[12], v4, 40i64);
  TlsSetValue(hkMonitorStream__m_instance.m_slotID, 0i64);
}

// File Line: 58
// RVA: 0xC5C440
void __fastcall hkMonitorStream::resize(hkMonitorStream *this, int newSize)
{
  char *m_storage; // rbp
  char *v3; // rdi
  _QWORD **Value; // rax
  _QWORD **v7; // rax
  char *v8; // rax
  __int64 v9; // rcx
  char *v10; // rax
  int v11; // [rsp+38h] [rbp+10h] BYREF

  m_storage = this->m_capacity.m_storage;
  v3 = this->m_start.m_storage;
  if ( (char *)newSize != (char *)(m_storage - this->m_start.m_storage) )
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
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*Value[12] + 32i64))(
            Value[12],
            v3,
            (unsigned int)((_DWORD)m_storage - (_DWORD)v3));
        }
      }
      this->m_isBufferAllocatedOnTheHeap.m_bool = 1;
      v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v11 = newSize;
      v8 = (char *)(*(__int64 (__fastcall **)(_QWORD *, int *))(*v7[12] + 24i64))(v7[12], &v11);
      v9 = v11;
      this->m_start.m_storage = v8;
      this->m_end.m_storage = v8;
      v10 = &v8[v9];
      this->m_capacity.m_storage = v10;
      this->m_capacityMinus16.m_storage = v10 - 32;
    }
  }
}

// File Line: 93
// RVA: 0xC5C500
void __fastcall hkMonitorStream::setStaticBuffer(hkMonitorStream *this, char *buffer, int bufferSize)
{
  __int64 v3; // rsi

  v3 = bufferSize;
  if ( this->m_isBufferAllocatedOnTheHeap.m_bool )
    hkMonitorStream::resize(this, 0);
  this->m_isBufferAllocatedOnTheHeap.m_bool = 0;
  this->m_capacity.m_storage = &buffer[v3];
  this->m_start.m_storage = buffer;
  this->m_capacityMinus16.m_storage = &buffer[v3 - 32];
  this->m_end.m_storage = buffer;
}

// File Line: 109
// RVA: 0xC5C430
void __fastcall hkMonitorStream::reset(hkMonitorStream *this)
{
  this->m_end.m_storage = this->m_start.m_storage;
}

