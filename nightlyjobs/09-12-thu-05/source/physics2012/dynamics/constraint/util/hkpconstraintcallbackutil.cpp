// File Line: 14
// RVA: 0xD8D440
void __fastcall hkpConstraintCallbackUtil_cleanupNullPointers(hkSmallArray<void *> *cleanupArray)
{
  int v1; // r10d
  __int64 v2; // r11
  int v3; // r9d
  __int64 v4; // r8

  v1 = cleanupArray->m_size - 1;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      if ( !cleanupArray->m_data[v2] )
      {
        --cleanupArray->m_size;
        v3 = v1;
        if ( v1 < cleanupArray->m_size )
        {
          v4 = v2 * 8;
          do
          {
            ++v3;
            v4 += 8i64;
            *(void **)((char *)cleanupArray->m_data + v4 - 8) = *(void **)((char *)cleanupArray->m_data + v4);
          }
          while ( v3 < cleanupArray->m_size );
        }
      }
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
}

// File Line: 25
// RVA: 0xD8CD90
void __fastcall hkpConstraintCallbackUtil::fireConstraintAdded(hkpConstraintInstance *constraint)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  hkpConstraintListener *v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  int v13; // r9d
  __int64 v14; // r10
  int v15; // r8d
  __int64 v16; // rdx

  v2 = constraint->m_listeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( constraint->m_listeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v5 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v5 < Value[3] )
      {
        *v5 = "TtconAddCb";
        v6 = __rdtsc();
        v7 = v5 + 2;
        *((_DWORD *)v7 - 2) = v6;
        Value[1] = v7;
      }
      v8 = constraint->m_listeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintInstance *, LPVOID))v8->vfptr->constraintAddedCallback)(
        v8,
        constraint,
        Value);
      v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v10 = (_QWORD *)v9[1];
      if ( (unsigned __int64)v10 < v9[3] )
      {
        *v10 = "Et";
        v11 = __rdtsc();
        v12 = v10 + 2;
        *((_DWORD *)v12 - 2) = v11;
        v9[1] = v12;
      }
    }
  }
  v13 = constraint->m_listeners.m_size - 1;
  if ( v13 >= 0 )
  {
    v14 = v13;
    do
    {
      if ( !constraint->m_listeners.m_data[v14] )
      {
        --constraint->m_listeners.m_size;
        v15 = v13;
        if ( v13 < constraint->m_listeners.m_size )
        {
          v16 = v14 * 8;
          do
          {
            ++v15;
            v16 += 8i64;
            *(hkpConstraintListener **)((char *)constraint->m_listeners.m_data + v16 - 8) = *(hkpConstraintListener **)((char *)constraint->m_listeners.m_data + v16);
          }
          while ( v15 < constraint->m_listeners.m_size );
        }
      }
      --v14;
      --v13;
    }
    while ( v13 >= 0 );
  }
}

// File Line: 40
// RVA: 0xD8CEE0
void __fastcall hkpConstraintCallbackUtil::fireConstraintRemoved(hkpConstraintInstance *constraint)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  hkpConstraintListener *v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  int v13; // r9d
  __int64 v14; // r10
  int v15; // r8d
  __int64 v16; // rdx

  v2 = constraint->m_listeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( constraint->m_listeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v5 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v5 < Value[3] )
      {
        *v5 = "TtconRemCb";
        v6 = __rdtsc();
        v7 = v5 + 2;
        *((_DWORD *)v7 - 2) = v6;
        Value[1] = v7;
      }
      v8 = constraint->m_listeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintInstance *, LPVOID))v8->vfptr->constraintRemovedCallback)(
        v8,
        constraint,
        Value);
      v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v10 = (_QWORD *)v9[1];
      if ( (unsigned __int64)v10 < v9[3] )
      {
        *v10 = "Et";
        v11 = __rdtsc();
        v12 = v10 + 2;
        *((_DWORD *)v12 - 2) = v11;
        v9[1] = v12;
      }
    }
  }
  v13 = constraint->m_listeners.m_size - 1;
  if ( v13 >= 0 )
  {
    v14 = v13;
    do
    {
      if ( !constraint->m_listeners.m_data[v14] )
      {
        --constraint->m_listeners.m_size;
        v15 = v13;
        if ( v13 < constraint->m_listeners.m_size )
        {
          v16 = v14 * 8;
          do
          {
            ++v15;
            v16 += 8i64;
            *(hkpConstraintListener **)((char *)constraint->m_listeners.m_data + v16 - 8) = *(hkpConstraintListener **)((char *)constraint->m_listeners.m_data + v16);
          }
          while ( v15 < constraint->m_listeners.m_size );
        }
      }
      --v14;
      --v13;
    }
    while ( v13 >= 0 );
  }
}

// File Line: 55
// RVA: 0xD8D030
void __fastcall hkpConstraintCallbackUtil::fireConstraintDeleted(hkpConstraintInstance *constraint)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  hkpConstraintListener *v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  int v13; // r9d
  __int64 v14; // r10
  int v15; // r8d
  __int64 v16; // rdx

  v2 = constraint->m_listeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( constraint->m_listeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v5 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v5 < Value[3] )
      {
        *v5 = "TtconDeletedCb";
        v6 = __rdtsc();
        v7 = v5 + 2;
        *((_DWORD *)v7 - 2) = v6;
        Value[1] = v7;
      }
      v8 = constraint->m_listeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintInstance *, LPVOID))v8->vfptr->constraintDeletedCallback)(
        v8,
        constraint,
        Value);
      v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v10 = (_QWORD *)v9[1];
      if ( (unsigned __int64)v10 < v9[3] )
      {
        *v10 = "Et";
        v11 = __rdtsc();
        v12 = v10 + 2;
        *((_DWORD *)v12 - 2) = v11;
        v9[1] = v12;
      }
    }
  }
  v13 = constraint->m_listeners.m_size - 1;
  if ( v13 >= 0 )
  {
    v14 = v13;
    do
    {
      if ( !constraint->m_listeners.m_data[v14] )
      {
        --constraint->m_listeners.m_size;
        v15 = v13;
        if ( v13 < constraint->m_listeners.m_size )
        {
          v16 = v14 * 8;
          do
          {
            ++v15;
            v16 += 8i64;
            *(hkpConstraintListener **)((char *)constraint->m_listeners.m_data + v16 - 8) = *(hkpConstraintListener **)((char *)constraint->m_listeners.m_data + v16);
          }
          while ( v15 < constraint->m_listeners.m_size );
        }
      }
      --v14;
      --v13;
    }
    while ( v13 >= 0 );
  }
}

// File Line: 70
// RVA: 0xD8D180
void __fastcall hkpConstraintCallbackUtil::fireConstraintBroken(hkpConstraintBrokenEvent *event)
{
  hkpConstraintInstance *m_constraintInstance; // rbx
  int v3; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkpConstraintListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  int v14; // r9d
  __int64 v15; // r10
  int v16; // r8d
  __int64 v17; // rdx

  m_constraintInstance = event->m_constraintInstance;
  v3 = m_constraintInstance->m_listeners.m_size - 1;
  for ( i = v3; i >= 0; --i )
  {
    if ( m_constraintInstance->m_listeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v6 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v6 < Value[3] )
      {
        *v6 = "TtconBrokenCb";
        v7 = __rdtsc();
        v8 = v6 + 2;
        *((_DWORD *)v8 - 2) = v7;
        Value[1] = v8;
      }
      v9 = m_constraintInstance->m_listeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintBrokenEvent *, _QWORD *))v9->vfptr->constraintBreakingCallback)(
        v9,
        event,
        Value);
      v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v11 = (_QWORD *)v10[1];
      if ( (unsigned __int64)v11 < v10[3] )
      {
        *v11 = "Et";
        v12 = __rdtsc();
        v13 = v11 + 2;
        *((_DWORD *)v13 - 2) = v12;
        v10[1] = v13;
      }
    }
  }
  v14 = m_constraintInstance->m_listeners.m_size - 1;
  if ( v14 >= 0 )
  {
    v15 = v14;
    do
    {
      if ( !m_constraintInstance->m_listeners.m_data[v15] )
      {
        --m_constraintInstance->m_listeners.m_size;
        v16 = v14;
        if ( v14 < m_constraintInstance->m_listeners.m_size )
        {
          v17 = v15 * 8;
          do
          {
            ++v16;
            v17 += 8i64;
            *(hkpConstraintListener **)((char *)m_constraintInstance->m_listeners.m_data + v17 - 8) = *(hkpConstraintListener **)((char *)m_constraintInstance->m_listeners.m_data + v17);
          }
          while ( v16 < m_constraintInstance->m_listeners.m_size );
        }
      }
      --v15;
      --v14;
    }
    while ( v14 >= 0 );
  }
}

// File Line: 85
// RVA: 0xD8D2E0
void __fastcall hkpConstraintCallbackUtil::fireConstraintRepaired(hkpConstraintRepairedEvent *event)
{
  hkpConstraintInstance *m_constraintInstance; // rbx
  int v3; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkpConstraintListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  int v14; // r9d
  __int64 v15; // r10
  int v16; // r8d
  __int64 v17; // rdx

  m_constraintInstance = event->m_constraintInstance;
  v3 = m_constraintInstance->m_listeners.m_size - 1;
  for ( i = v3; i >= 0; --i )
  {
    if ( m_constraintInstance->m_listeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v6 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v6 < Value[3] )
      {
        *v6 = "TtconRepairedCb";
        v7 = __rdtsc();
        v8 = v6 + 2;
        *((_DWORD *)v8 - 2) = v7;
        Value[1] = v8;
      }
      v9 = m_constraintInstance->m_listeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintRepairedEvent *, _QWORD *))v9->vfptr->constraintRepairedCallback)(
        v9,
        event,
        Value);
      v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v11 = (_QWORD *)v10[1];
      if ( (unsigned __int64)v11 < v10[3] )
      {
        *v11 = "Et";
        v12 = __rdtsc();
        v13 = v11 + 2;
        *((_DWORD *)v13 - 2) = v12;
        v10[1] = v13;
      }
    }
  }
  v14 = m_constraintInstance->m_listeners.m_size - 1;
  if ( v14 >= 0 )
  {
    v15 = v14;
    do
    {
      if ( !m_constraintInstance->m_listeners.m_data[v15] )
      {
        --m_constraintInstance->m_listeners.m_size;
        v16 = v14;
        if ( v14 < m_constraintInstance->m_listeners.m_size )
        {
          v17 = v15 * 8;
          do
          {
            ++v16;
            v17 += 8i64;
            *(hkpConstraintListener **)((char *)m_constraintInstance->m_listeners.m_data + v17 - 8) = *(hkpConstraintListener **)((char *)m_constraintInstance->m_listeners.m_data + v17);
          }
          while ( v16 < m_constraintInstance->m_listeners.m_size );
        }
      }
      --v15;
      --v14;
    }
    while ( v14 >= 0 );
  }
}

