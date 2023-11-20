// File Line: 14
// RVA: 0xD8D440
void __fastcall hkpConstraintCallbackUtil_cleanupNullPointers(hkSmallArray<void *> *cleanupArray)
{
  int v1; // er10
  __int64 v2; // r11
  signed int v3; // er9
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
  hkpConstraintInstance *v1; // rbx
  int v2; // eax
  __int64 i; // rdi
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  hkpConstraintListener *v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  int v13; // er9
  signed __int64 v14; // r10
  signed int v15; // er8
  signed __int64 v16; // rdx

  v1 = constraint;
  v2 = constraint->m_listeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( v1->m_listeners.m_data[i] )
    {
      v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v5 = (_QWORD *)v4[1];
      if ( (unsigned __int64)v5 < v4[3] )
      {
        *v5 = "TtconAddCb";
        v6 = __rdtsc();
        v7 = (signed __int64)(v5 + 2);
        *(_DWORD *)(v7 - 8) = v6;
        v4[1] = v7;
      }
      v8 = v1->m_listeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintInstance *, _QWORD *))v8->vfptr->constraintAddedCallback)(
        v8,
        v1,
        v4);
      v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v10 = (_QWORD *)v9[1];
      if ( (unsigned __int64)v10 < v9[3] )
      {
        *v10 = "Et";
        v11 = __rdtsc();
        v12 = (signed __int64)(v10 + 2);
        *(_DWORD *)(v12 - 8) = v11;
        v9[1] = v12;
      }
    }
  }
  v13 = v1->m_listeners.m_size - 1;
  if ( v13 >= 0 )
  {
    v14 = v13;
    do
    {
      if ( !v1->m_listeners.m_data[v14] )
      {
        --v1->m_listeners.m_size;
        v15 = v13;
        if ( v13 < v1->m_listeners.m_size )
        {
          v16 = v14 * 8;
          do
          {
            ++v15;
            v16 += 8i64;
            *(hkpConstraintListener **)((char *)v1->m_listeners.m_data + v16 - 8) = *(hkpConstraintListener **)((char *)v1->m_listeners.m_data + v16);
          }
          while ( v15 < v1->m_listeners.m_size );
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
  hkpConstraintInstance *v1; // rbx
  int v2; // eax
  __int64 i; // rdi
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  hkpConstraintListener *v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  int v13; // er9
  signed __int64 v14; // r10
  signed int v15; // er8
  signed __int64 v16; // rdx

  v1 = constraint;
  v2 = constraint->m_listeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( v1->m_listeners.m_data[i] )
    {
      v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v5 = (_QWORD *)v4[1];
      if ( (unsigned __int64)v5 < v4[3] )
      {
        *v5 = "TtconRemCb";
        v6 = __rdtsc();
        v7 = (signed __int64)(v5 + 2);
        *(_DWORD *)(v7 - 8) = v6;
        v4[1] = v7;
      }
      v8 = v1->m_listeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintInstance *, _QWORD *))v8->vfptr->constraintRemovedCallback)(
        v8,
        v1,
        v4);
      v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v10 = (_QWORD *)v9[1];
      if ( (unsigned __int64)v10 < v9[3] )
      {
        *v10 = "Et";
        v11 = __rdtsc();
        v12 = (signed __int64)(v10 + 2);
        *(_DWORD *)(v12 - 8) = v11;
        v9[1] = v12;
      }
    }
  }
  v13 = v1->m_listeners.m_size - 1;
  if ( v13 >= 0 )
  {
    v14 = v13;
    do
    {
      if ( !v1->m_listeners.m_data[v14] )
      {
        --v1->m_listeners.m_size;
        v15 = v13;
        if ( v13 < v1->m_listeners.m_size )
        {
          v16 = v14 * 8;
          do
          {
            ++v15;
            v16 += 8i64;
            *(hkpConstraintListener **)((char *)v1->m_listeners.m_data + v16 - 8) = *(hkpConstraintListener **)((char *)v1->m_listeners.m_data + v16);
          }
          while ( v15 < v1->m_listeners.m_size );
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
  hkpConstraintInstance *v1; // rbx
  int v2; // eax
  __int64 i; // rdi
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  hkpConstraintListener *v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  int v13; // er9
  signed __int64 v14; // r10
  signed int v15; // er8
  signed __int64 v16; // rdx

  v1 = constraint;
  v2 = constraint->m_listeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( v1->m_listeners.m_data[i] )
    {
      v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v5 = (_QWORD *)v4[1];
      if ( (unsigned __int64)v5 < v4[3] )
      {
        *v5 = "TtconDeletedCb";
        v6 = __rdtsc();
        v7 = (signed __int64)(v5 + 2);
        *(_DWORD *)(v7 - 8) = v6;
        v4[1] = v7;
      }
      v8 = v1->m_listeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintInstance *, _QWORD *))v8->vfptr->constraintDeletedCallback)(
        v8,
        v1,
        v4);
      v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v10 = (_QWORD *)v9[1];
      if ( (unsigned __int64)v10 < v9[3] )
      {
        *v10 = "Et";
        v11 = __rdtsc();
        v12 = (signed __int64)(v10 + 2);
        *(_DWORD *)(v12 - 8) = v11;
        v9[1] = v12;
      }
    }
  }
  v13 = v1->m_listeners.m_size - 1;
  if ( v13 >= 0 )
  {
    v14 = v13;
    do
    {
      if ( !v1->m_listeners.m_data[v14] )
      {
        --v1->m_listeners.m_size;
        v15 = v13;
        if ( v13 < v1->m_listeners.m_size )
        {
          v16 = v14 * 8;
          do
          {
            ++v15;
            v16 += 8i64;
            *(hkpConstraintListener **)((char *)v1->m_listeners.m_data + v16 - 8) = *(hkpConstraintListener **)((char *)v1->m_listeners.m_data + v16);
          }
          while ( v15 < v1->m_listeners.m_size );
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
  hkpConstraintInstance *v1; // rbx
  hkpConstraintBrokenEvent *v2; // rsi
  int v3; // eax
  __int64 i; // rdi
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkpConstraintListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  int v14; // er9
  signed __int64 v15; // r10
  signed int v16; // er8
  signed __int64 v17; // rdx

  v1 = event->m_constraintInstance;
  v2 = event;
  v3 = v1->m_listeners.m_size - 1;
  for ( i = v3; i >= 0; --i )
  {
    if ( v1->m_listeners.m_data[i] )
    {
      v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v6 = (_QWORD *)v5[1];
      if ( (unsigned __int64)v6 < v5[3] )
      {
        *v6 = "TtconBrokenCb";
        v7 = __rdtsc();
        v8 = (signed __int64)(v6 + 2);
        *(_DWORD *)(v8 - 8) = v7;
        v5[1] = v8;
      }
      v9 = v1->m_listeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintBrokenEvent *, _QWORD *))v9->vfptr->constraintBreakingCallback)(
        v9,
        v2,
        v5);
      v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v11 = (_QWORD *)v10[1];
      if ( (unsigned __int64)v11 < v10[3] )
      {
        *v11 = "Et";
        v12 = __rdtsc();
        v13 = (signed __int64)(v11 + 2);
        *(_DWORD *)(v13 - 8) = v12;
        v10[1] = v13;
      }
    }
  }
  v14 = v1->m_listeners.m_size - 1;
  if ( v14 >= 0 )
  {
    v15 = v14;
    do
    {
      if ( !v1->m_listeners.m_data[v15] )
      {
        --v1->m_listeners.m_size;
        v16 = v14;
        if ( v14 < v1->m_listeners.m_size )
        {
          v17 = v15 * 8;
          do
          {
            ++v16;
            v17 += 8i64;
            *(hkpConstraintListener **)((char *)v1->m_listeners.m_data + v17 - 8) = *(hkpConstraintListener **)((char *)v1->m_listeners.m_data + v17);
          }
          while ( v16 < v1->m_listeners.m_size );
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
  hkpConstraintInstance *v1; // rbx
  hkpConstraintRepairedEvent *v2; // rsi
  int v3; // eax
  __int64 i; // rdi
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkpConstraintListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  int v14; // er9
  signed __int64 v15; // r10
  signed int v16; // er8
  signed __int64 v17; // rdx

  v1 = event->m_constraintInstance;
  v2 = event;
  v3 = v1->m_listeners.m_size - 1;
  for ( i = v3; i >= 0; --i )
  {
    if ( v1->m_listeners.m_data[i] )
    {
      v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v6 = (_QWORD *)v5[1];
      if ( (unsigned __int64)v6 < v5[3] )
      {
        *v6 = "TtconRepairedCb";
        v7 = __rdtsc();
        v8 = (signed __int64)(v6 + 2);
        *(_DWORD *)(v8 - 8) = v7;
        v5[1] = v8;
      }
      v9 = v1->m_listeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintRepairedEvent *, _QWORD *))v9->vfptr->constraintRepairedCallback)(
        v9,
        v2,
        v5);
      v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v11 = (_QWORD *)v10[1];
      if ( (unsigned __int64)v11 < v10[3] )
      {
        *v11 = "Et";
        v12 = __rdtsc();
        v13 = (signed __int64)(v11 + 2);
        *(_DWORD *)(v13 - 8) = v12;
        v10[1] = v13;
      }
    }
  }
  v14 = v1->m_listeners.m_size - 1;
  if ( v14 >= 0 )
  {
    v15 = v14;
    do
    {
      if ( !v1->m_listeners.m_data[v15] )
      {
        --v1->m_listeners.m_size;
        v16 = v14;
        if ( v14 < v1->m_listeners.m_size )
        {
          v17 = v15 * 8;
          do
          {
            ++v16;
            v17 += 8i64;
            *(hkpConstraintListener **)((char *)v1->m_listeners.m_data + v17 - 8) = *(hkpConstraintListener **)((char *)v1->m_listeners.m_data + v17);
          }
          while ( v16 < v1->m_listeners.m_size );
        }
      }
      --v15;
      --v14;
    }
    while ( v14 >= 0 );
  }
}

