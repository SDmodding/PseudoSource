// File Line: 32
// RVA: 0xD88B80
void __fastcall worldCallbackUtil_cleanupNullPointers(hkArray<void *,hkContainerHeapAllocator> *cleanupArray)
{
  int v2; // r9d
  __int64 i; // r10
  void **v4; // rax
  int v5; // ecx
  __int64 v6; // rdx
  void *v7; // rcx

  v2 = cleanupArray->m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = &cleanupArray->m_data[i];
    if ( !*v4 )
    {
      v5 = 8 * (--cleanupArray->m_size - v2);
      if ( v5 > 0 )
      {
        v6 = ((unsigned int)(v5 - 1) >> 3) + 1;
        do
        {
          v7 = v4[1];
          *v4++ = v7;
          --v6;
        }
        while ( v6 );
      }
    }
    --v2;
  }
}

// File Line: 43
// RVA: 0xD88BF0
void __fastcall worldCallbackUtil_cleanupNullPointers_0(hkSmallArray<void *> *cleanupArray)
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

// File Line: 54
// RVA: 0xD85C70
void __fastcall hkpWorldCallbackUtil::fireActionAdded(hkpWorld *world, hkpAction *action)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpActionListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpActionListener **m_data; // rax
  bool v18; // zf
  hkpActionListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpActionListener *v22; // rcx

  v2 = world->m_actionListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_actionListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtactAddCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_actionListeners.m_data[i];
      ((void (__fastcall *)(hkpActionListener *, hkpAction *, LPVOID))v10->vfptr->actionAddedCallback)(
        v10,
        action,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_actionListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_actionListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_actionListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 69
// RVA: 0xD85DD0
void __fastcall hkpWorldCallbackUtil::fireActionRemoved(hkpWorld *world, hkpAction *action)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpActionListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpActionListener **m_data; // rax
  bool v18; // zf
  hkpActionListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpActionListener *v22; // rcx

  v2 = world->m_actionListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_actionListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtactRemCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_actionListeners.m_data[i];
      ((void (__fastcall *)(hkpActionListener *, hkpAction *, LPVOID))v10->vfptr->actionRemovedCallback)(
        v10,
        action,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_actionListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_actionListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_actionListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 85
// RVA: 0xD85F30
void __fastcall hkpWorldCallbackUtil::fireEntityAdded(hkpWorld *world, hkpEntity *entity)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpEntityListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpEntityListener **m_data; // rax
  bool v18; // zf
  hkpEntityListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpEntityListener *v22; // rcx

  v2 = world->m_entityListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_entityListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtentAddCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_entityListeners.m_data[i];
      ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, LPVOID))v10->vfptr->entityAddedCallback)(
        v10,
        entity,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_entityListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_entityListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_entityListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 101
// RVA: 0xD86090
void __fastcall hkpWorldCallbackUtil::fireEntityRemoved(hkpWorld *world, hkpEntity *entity)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpEntityListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpEntityListener **m_data; // rax
  bool v18; // zf
  hkpEntityListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpEntityListener *v22; // rcx

  v2 = world->m_entityListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_entityListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtentRemCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_entityListeners.m_data[i];
      ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, LPVOID))v10->vfptr->entityRemovedCallback)(
        v10,
        entity,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_entityListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_entityListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_entityListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 117
// RVA: 0xD861F0
void __fastcall hkpWorldCallbackUtil::fireEntityShapeSet(hkpWorld *world, hkpEntity *entity)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpEntityListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpEntityListener **m_data; // rax
  bool v18; // zf
  hkpEntityListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpEntityListener *v22; // rcx

  v2 = world->m_entityListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_entityListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtsetShapeCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_entityListeners.m_data[i];
      ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, LPVOID))v10->vfptr->entityShapeSetCallback)(
        v10,
        entity,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_entityListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_entityListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_entityListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 132
// RVA: 0xD86350
void __fastcall hkpWorldCallbackUtil::fireEntitySetMotionType(hkpWorld *world, hkpEntity *entity)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpEntityListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpEntityListener **m_data; // rax
  bool v18; // zf
  hkpEntityListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpEntityListener *v22; // rcx

  v2 = world->m_entityListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_entityListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtsetMotionTypeCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_entityListeners.m_data[i];
      ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, LPVOID))v10->vfptr->entitySetMotionTypeCallback)(
        v10,
        entity,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_entityListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_entityListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_entityListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 147
// RVA: 0xD864B0
void __fastcall hkpWorldCallbackUtil::firePhantomAdded(hkpWorld *world, hkpPhantom *Phantom)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpPhantomListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpPhantomListener **m_data; // rax
  bool v18; // zf
  hkpPhantomListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpPhantomListener *v22; // rcx

  v2 = world->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_phantomListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtphntAddCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_phantomListeners.m_data[i];
      ((void (__fastcall *)(hkpPhantomListener *, hkpPhantom *, LPVOID))v10->vfptr->phantomAddedCallback)(
        v10,
        Phantom,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_phantomListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_phantomListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_phantomListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 163
// RVA: 0xD86610
void __fastcall hkpWorldCallbackUtil::firePhantomRemoved(hkpWorld *world, hkpPhantom *Phantom)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpPhantomListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpPhantomListener **m_data; // rax
  bool v18; // zf
  hkpPhantomListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpPhantomListener *v22; // rcx

  v2 = world->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_phantomListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtphntRemCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_phantomListeners.m_data[i];
      ((void (__fastcall *)(hkpPhantomListener *, hkpPhantom *, LPVOID))v10->vfptr->phantomRemovedCallback)(
        v10,
        Phantom,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_phantomListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_phantomListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_phantomListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 179
// RVA: 0xD86770
void __fastcall hkpWorldCallbackUtil::firePhantomShapeSet(hkpWorld *world, hkpPhantom *Phantom)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpPhantomListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpPhantomListener **m_data; // rax
  bool v18; // zf
  hkpPhantomListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpPhantomListener *v22; // rcx

  v2 = world->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_phantomListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtsetShapeCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_phantomListeners.m_data[i];
      ((void (__fastcall *)(hkpPhantomListener *, hkpPhantom *, LPVOID))v10->vfptr->phantomShapeSetCallback)(
        v10,
        Phantom,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_phantomListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_phantomListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_phantomListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 194
// RVA: 0xD868D0
void __fastcall hkpWorldCallbackUtil::fireConstraintAdded(hkpWorld *world, hkpConstraintInstance *constraint)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpConstraintListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpConstraintListener **m_data; // rax
  bool v18; // zf
  hkpConstraintListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpConstraintListener *v22; // rcx

  v2 = world->m_constraintListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_constraintListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtconAddCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_constraintListeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintInstance *, LPVOID))v10->vfptr->constraintAddedCallback)(
        v10,
        constraint,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_constraintListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_constraintListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_constraintListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 209
// RVA: 0xD86A30
void __fastcall hkpWorldCallbackUtil::fireConstraintRemoved(hkpWorld *world, hkpConstraintInstance *constraint)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpConstraintListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpConstraintListener **m_data; // rax
  bool v18; // zf
  hkpConstraintListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpConstraintListener *v22; // rcx

  v2 = world->m_constraintListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_constraintListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtconRemCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_constraintListeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintInstance *, LPVOID))v10->vfptr->constraintRemovedCallback)(
        v10,
        constraint,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_constraintListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_constraintListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_constraintListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 224
// RVA: 0xD86B90
void __fastcall hkpWorldCallbackUtil::fireConstraintViolated(hkpWorld *world, hkpConstraintInstance *constraint)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpConstraintListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpConstraintListener **m_data; // rax
  bool v18; // zf
  hkpConstraintListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpConstraintListener *v22; // rcx

  v2 = world->m_constraintListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_constraintListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtconVioCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_constraintListeners.m_data[i];
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintInstance *, LPVOID))v10->vfptr->constraintViolatedCallback)(
        v10,
        constraint,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_constraintListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_constraintListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_constraintListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 239
// RVA: 0xD86CF0
void __fastcall hkpWorldCallbackUtil::fireConstraintBroken(hkpWorld *world, hkpConstraintBrokenEvent *event)
{
  int v2; // eax
  __int64 i; // rdi
  hkpConstraintListener *v6; // rsi
  _QWORD *Value; // r8
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  int v14; // r9d
  __int64 j; // r10
  hkpConstraintListener **m_data; // rax
  bool v17; // zf
  hkpConstraintListener **v18; // rax
  int v19; // ecx
  __int64 v20; // rdx
  hkpConstraintListener *v21; // rcx

  v2 = world->m_constraintListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v6 = world->m_constraintListeners.m_data[i];
    if ( v6 )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v8 = Value[1];
      if ( v8 < Value[3] )
      {
        *(_QWORD *)v8 = "TtconBrokenCb";
        v9 = __rdtsc();
        *(_DWORD *)(v8 + 8) = v9;
        Value[1] = v8 + 16;
      }
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintBrokenEvent *, LPVOID))v6->vfptr->constraintBreakingCallback)(
        v6,
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
  v14 = world->m_constraintListeners.m_size - 1;
  for ( j = v14; j >= 0; --j )
  {
    m_data = world->m_constraintListeners.m_data;
    v17 = m_data[j] == 0i64;
    v18 = &m_data[j];
    if ( v17 )
    {
      v19 = 8 * (--world->m_constraintListeners.m_size - v14);
      if ( v19 > 0 )
      {
        v20 = ((unsigned int)(v19 - 1) >> 3) + 1;
        do
        {
          v21 = v18[1];
          *v18++ = v21;
          --v20;
        }
        while ( v20 );
      }
    }
    --v14;
  }
}

// File Line: 255
// RVA: 0xD86E60
void __fastcall hkpWorldCallbackUtil::fireConstraintRepaired(hkpWorld *world, hkpConstraintRepairedEvent *event)
{
  int v2; // eax
  __int64 i; // rdi
  hkpConstraintListener *v6; // rsi
  _QWORD *Value; // r8
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  int v14; // r9d
  __int64 j; // r10
  hkpConstraintListener **m_data; // rax
  bool v17; // zf
  hkpConstraintListener **v18; // rax
  int v19; // ecx
  __int64 v20; // rdx
  hkpConstraintListener *v21; // rcx

  v2 = world->m_constraintListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v6 = world->m_constraintListeners.m_data[i];
    if ( v6 )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v8 = Value[1];
      if ( v8 < Value[3] )
      {
        *(_QWORD *)v8 = "TtconRepairedCb";
        v9 = __rdtsc();
        *(_DWORD *)(v8 + 8) = v9;
        Value[1] = v8 + 16;
      }
      ((void (__fastcall *)(hkpConstraintListener *, hkpConstraintRepairedEvent *, LPVOID))v6->vfptr->constraintRepairedCallback)(
        v6,
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
  v14 = world->m_constraintListeners.m_size - 1;
  for ( j = v14; j >= 0; --j )
  {
    m_data = world->m_constraintListeners.m_data;
    v17 = m_data[j] == 0i64;
    v18 = &m_data[j];
    if ( v17 )
    {
      v19 = 8 * (--world->m_constraintListeners.m_size - v14);
      if ( v19 > 0 )
      {
        v20 = ((unsigned int)(v19 - 1) >> 3) + 1;
        do
        {
          v21 = v18[1];
          *v18++ = v21;
          --v20;
        }
        while ( v20 );
      }
    }
    --v14;
  }
}

// File Line: 272
// RVA: 0xD86FD0
void __fastcall hkpWorldCallbackUtil::fireContactPointCallback(hkpWorld *world, hkpContactPointEvent *event)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpContactListener **m_data; // rax
  bool v18; // zf
  hkpContactListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpContactListener *v22; // rcx

  v2 = world->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_contactListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtcpCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_contactListeners.m_data[i];
      ((void (__fastcall *)(hkpContactListener *, hkpContactPointEvent *, LPVOID))v10->vfptr->contactPointCallback)(
        v10,
        event,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_contactListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_contactListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_contactListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 288
// RVA: 0xD87130
void __fastcall hkpWorldCallbackUtil::fireContactConstraintAddedCallback(hkpWorld *world, hkpCollisionEvent *event)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpContactListener **m_data; // rax
  bool v18; // zf
  hkpContactListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpContactListener *v22; // rcx

  v2 = world->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_contactListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtNewCollCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_contactListeners.m_data[i];
      ((void (__fastcall *)(hkpContactListener *, hkpCollisionEvent *, LPVOID))v10->vfptr->collisionAddedCallback)(
        v10,
        event,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_contactListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_contactListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_contactListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 303
// RVA: 0xD87290
void __fastcall hkpWorldCallbackUtil::fireContactConstraintRemovedCallback(hkpWorld *world, hkpCollisionEvent *event)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpContactListener **m_data; // rax
  bool v18; // zf
  hkpContactListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpContactListener *v22; // rcx

  v2 = world->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_contactListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtFinCollCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_contactListeners.m_data[i];
      ((void (__fastcall *)(hkpContactListener *, hkpCollisionEvent *, LPVOID))v10->vfptr->collisionRemovedCallback)(
        v10,
        event,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_contactListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_contactListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_contactListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 320
// RVA: 0xD88190
void __fastcall hkpWorldCallbackUtil::fireWorldDeleted(hkpWorld *world)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  hkpWorldDeletionListener *v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  int v13; // r9d
  __int64 j; // r10
  hkpWorldDeletionListener **m_data; // rax
  bool v16; // zf
  hkpWorldDeletionListener **v17; // rax
  int v18; // ecx
  __int64 v19; // rdx
  hkpWorldDeletionListener *v20; // rcx

  v2 = world->m_worldDeletionListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_worldDeletionListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v5 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v5 < Value[3] )
      {
        *v5 = "TtworldDelCb";
        v6 = __rdtsc();
        v7 = v5 + 2;
        *((_DWORD *)v7 - 2) = v6;
        Value[1] = v7;
      }
      v8 = world->m_worldDeletionListeners.m_data[i];
      ((void (__fastcall *)(hkpWorldDeletionListener *, hkpWorld *, LPVOID))v8->vfptr->worldDeletedCallback)(
        v8,
        world,
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
  v13 = world->m_worldDeletionListeners.m_size - 1;
  for ( j = v13; j >= 0; --j )
  {
    m_data = world->m_worldDeletionListeners.m_data;
    v16 = m_data[j] == 0i64;
    v17 = &m_data[j];
    if ( v16 )
    {
      v18 = 8 * (--world->m_worldDeletionListeners.m_size - v13);
      if ( v18 > 0 )
      {
        v19 = ((unsigned int)(v18 - 1) >> 3) + 1;
        do
        {
          v20 = v17[1];
          *v17++ = v20;
          --v19;
        }
        while ( v19 );
      }
    }
    --v13;
  }
}

// File Line: 338
// RVA: 0xD882F0
void __fastcall hkpWorldCallbackUtil::fireWorldRemoveAll(hkpWorld *world)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  hkpWorldDeletionListener *v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  int v13; // r9d
  __int64 j; // r10
  hkpWorldDeletionListener **m_data; // rax
  bool v16; // zf
  hkpWorldDeletionListener **v17; // rax
  int v18; // ecx
  __int64 v19; // rdx
  hkpWorldDeletionListener *v20; // rcx

  v2 = world->m_worldDeletionListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_worldDeletionListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v5 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v5 < Value[3] )
      {
        *v5 = "TtworldDelCb";
        v6 = __rdtsc();
        v7 = v5 + 2;
        *((_DWORD *)v7 - 2) = v6;
        Value[1] = v7;
      }
      v8 = world->m_worldDeletionListeners.m_data[i];
      ((void (__fastcall *)(hkpWorldDeletionListener *, hkpWorld *, LPVOID))v8->vfptr->worldRemoveAllCallback)(
        v8,
        world,
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
  v13 = world->m_worldDeletionListeners.m_size - 1;
  for ( j = v13; j >= 0; --j )
  {
    m_data = world->m_worldDeletionListeners.m_data;
    v16 = m_data[j] == 0i64;
    v17 = &m_data[j];
    if ( v16 )
    {
      v18 = 8 * (--world->m_worldDeletionListeners.m_size - v13);
      if ( v18 > 0 )
      {
        v19 = ((unsigned int)(v18 - 1) >> 3) + 1;
        do
        {
          v20 = v17[1];
          *v17++ = v20;
          --v19;
        }
        while ( v19 );
      }
    }
    --v13;
  }
}

// File Line: 356
// RVA: 0xD87850
void __fastcall hkpWorldCallbackUtil::fireIslandActivated(hkpWorld *world, hkpSimulationIsland *island)
{
  int v2; // eax
  __int64 i; // rbx
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpIslandActivationListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpIslandActivationListener **v17; // rcx
  int v18; // eax
  __int64 v19; // rdx
  hkpIslandActivationListener *v20; // rax
  int v21; // ebp
  __int64 v22; // r14
  hkpEntity::ExtendedListeners *m_extendedListeners; // rbx
  int v24; // eax
  __int64 k; // rdi
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  _QWORD *v33; // rcx
  int v34; // r9d
  __int64 v35; // r10
  int v36; // r8d
  __int64 v37; // rdx
  bool v38; // zf

  ++world->m_criticalOperationsLockCount;
  v2 = world->m_islandActivationListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_islandActivationListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtislActCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_islandActivationListeners.m_data[i];
      ((void (__fastcall *)(hkpIslandActivationListener *, hkpSimulationIsland *, LPVOID))v10->vfptr->islandActivatedCallback)(
        v10,
        island,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_islandActivationListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    v17 = &world->m_islandActivationListeners.m_data[j];
    if ( !*v17 )
    {
      v18 = 8 * (--world->m_islandActivationListeners.m_size - v15);
      if ( v18 > 0 )
      {
        v19 = ((unsigned int)(v18 - 1) >> 3) + 1;
        do
        {
          v20 = v17[1];
          *v17++ = v20;
          --v19;
        }
        while ( v19 );
      }
    }
    --v15;
  }
  v21 = 0;
  if ( island->m_entities.m_size > 0 )
  {
    v22 = 0i64;
    do
    {
      m_extendedListeners = island->m_entities.m_data[v22]->m_extendedListeners;
      if ( m_extendedListeners )
      {
        v24 = m_extendedListeners->m_activationListeners.m_size - 1;
        for ( k = v24; k >= 0; --k )
        {
          if ( m_extendedListeners->m_activationListeners.m_data[k] )
          {
            v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v27 = (_QWORD *)v26[1];
            if ( (unsigned __int64)v27 < v26[3] )
            {
              *v27 = "TtentActCb";
              v28 = __rdtsc();
              v29 = v27 + 2;
              *((_DWORD *)v29 - 2) = v28;
              v26[1] = v29;
            }
            ((void (__fastcall *)(hkpEntityActivationListener *, hkpEntity *, _QWORD *))m_extendedListeners->m_activationListeners.m_data[k]->vfptr->entityActivatedCallback)(
              m_extendedListeners->m_activationListeners.m_data[k],
              island->m_entities.m_data[v22],
              v26);
            v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v31 = (_QWORD *)v30[1];
            if ( (unsigned __int64)v31 < v30[3] )
            {
              *v31 = "Et";
              v32 = __rdtsc();
              v33 = v31 + 2;
              *((_DWORD *)v33 - 2) = v32;
              v30[1] = v33;
            }
          }
        }
        v34 = m_extendedListeners->m_activationListeners.m_size - 1;
        if ( v34 >= 0 )
        {
          v35 = v34;
          do
          {
            if ( !m_extendedListeners->m_activationListeners.m_data[v35] )
            {
              --m_extendedListeners->m_activationListeners.m_size;
              v36 = v34;
              if ( v34 < m_extendedListeners->m_activationListeners.m_size )
              {
                v37 = v35 * 8;
                do
                {
                  ++v36;
                  v37 += 8i64;
                  *(hkpEntityActivationListener **)((char *)m_extendedListeners->m_activationListeners.m_data + v37 - 8) = *(hkpEntityActivationListener **)((char *)m_extendedListeners->m_activationListeners.m_data + v37);
                }
                while ( v36 < m_extendedListeners->m_activationListeners.m_size );
              }
            }
            --v35;
            --v34;
          }
          while ( v34 >= 0 );
        }
      }
      ++v21;
      ++v22;
    }
    while ( v21 < island->m_entities.m_size );
  }
  v38 = world->m_criticalOperationsLockCount-- == 1;
  if ( v38 && !world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(world);
    if ( world->m_pendingOperationQueueCount == 1 )
    {
      if ( world->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(world);
    }
  }
}

// File Line: 402
// RVA: 0xD87B70
void __fastcall hkpWorldCallbackUtil::fireIslandDeactivated(hkpWorld *world, hkpSimulationIsland *island)
{
  int v2; // eax
  __int64 i; // rbx
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpIslandActivationListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpIslandActivationListener **v17; // rcx
  int v18; // eax
  __int64 v19; // rdx
  hkpIslandActivationListener *v20; // rax
  int v21; // ebp
  __int64 v22; // r14
  hkpEntity::ExtendedListeners *m_extendedListeners; // rbx
  int v24; // eax
  __int64 k; // rdi
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  _QWORD *v33; // rcx
  int v34; // r9d
  __int64 v35; // r10
  int v36; // r8d
  __int64 v37; // rdx
  bool v38; // zf

  ++world->m_criticalOperationsLockCount;
  v2 = world->m_islandActivationListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_islandActivationListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtislDeacCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_islandActivationListeners.m_data[i];
      ((void (__fastcall *)(hkpIslandActivationListener *, hkpSimulationIsland *, LPVOID))v10->vfptr->islandDeactivatedCallback)(
        v10,
        island,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_islandActivationListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    v17 = &world->m_islandActivationListeners.m_data[j];
    if ( !*v17 )
    {
      v18 = 8 * (--world->m_islandActivationListeners.m_size - v15);
      if ( v18 > 0 )
      {
        v19 = ((unsigned int)(v18 - 1) >> 3) + 1;
        do
        {
          v20 = v17[1];
          *v17++ = v20;
          --v19;
        }
        while ( v19 );
      }
    }
    --v15;
  }
  v21 = 0;
  if ( island->m_entities.m_size > 0 )
  {
    v22 = 0i64;
    do
    {
      m_extendedListeners = island->m_entities.m_data[v22]->m_extendedListeners;
      if ( m_extendedListeners )
      {
        v24 = m_extendedListeners->m_activationListeners.m_size - 1;
        for ( k = v24; k >= 0; --k )
        {
          if ( m_extendedListeners->m_activationListeners.m_data[k] )
          {
            v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v27 = (_QWORD *)v26[1];
            if ( (unsigned __int64)v27 < v26[3] )
            {
              *v27 = "TtentDeacCb";
              v28 = __rdtsc();
              v29 = v27 + 2;
              *((_DWORD *)v29 - 2) = v28;
              v26[1] = v29;
            }
            ((void (__fastcall *)(hkpEntityActivationListener *, hkpEntity *, _QWORD *))m_extendedListeners->m_activationListeners.m_data[k]->vfptr->entityDeactivatedCallback)(
              m_extendedListeners->m_activationListeners.m_data[k],
              island->m_entities.m_data[v22],
              v26);
            v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v31 = (_QWORD *)v30[1];
            if ( (unsigned __int64)v31 < v30[3] )
            {
              *v31 = "Et";
              v32 = __rdtsc();
              v33 = v31 + 2;
              *((_DWORD *)v33 - 2) = v32;
              v30[1] = v33;
            }
          }
        }
        v34 = m_extendedListeners->m_activationListeners.m_size - 1;
        if ( v34 >= 0 )
        {
          v35 = v34;
          do
          {
            if ( !m_extendedListeners->m_activationListeners.m_data[v35] )
            {
              --m_extendedListeners->m_activationListeners.m_size;
              v36 = v34;
              if ( v34 < m_extendedListeners->m_activationListeners.m_size )
              {
                v37 = v35 * 8;
                do
                {
                  ++v36;
                  v37 += 8i64;
                  *(hkpEntityActivationListener **)((char *)m_extendedListeners->m_activationListeners.m_data + v37 - 8) = *(hkpEntityActivationListener **)((char *)m_extendedListeners->m_activationListeners.m_data + v37);
                }
                while ( v36 < m_extendedListeners->m_activationListeners.m_size );
              }
            }
            --v35;
            --v34;
          }
          while ( v34 >= 0 );
        }
      }
      ++v21;
      ++v22;
    }
    while ( v21 < island->m_entities.m_size );
  }
  v38 = world->m_criticalOperationsLockCount-- == 1;
  if ( v38 && !world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(world);
    if ( world->m_pendingOperationQueueCount == 1 )
    {
      if ( world->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(world);
    }
  }
}

// File Line: 446
// RVA: 0xD873F0
void __fastcall hkpWorldCallbackUtil::firePostSimulationCallback(hkpWorld *world)
{
  int m_size; // esi
  int i; // edi
  int v4; // ecx
  int v5; // eax
  __int64 v6; // r14
  _QWORD *Value; // r8
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpWorldPostSimulationListener **m_data; // rax
  bool v18; // zf
  hkpWorldPostSimulationListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpWorldPostSimulationListener *v22; // rcx

  m_size = world->m_worldPostSimulationListeners.m_size;
  for ( i = m_size - 1; i >= 0; --i )
  {
    v4 = world->m_worldPostSimulationListeners.m_size;
    if ( m_size > v4 )
    {
      v5 = v4 - m_size;
      m_size = world->m_worldPostSimulationListeners.m_size;
      i += v5;
    }
    v6 = i;
    if ( world->m_worldPostSimulationListeners.m_data[v6] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v8 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v8 < Value[3] )
      {
        *v8 = "TtpostSimCb";
        v9 = __rdtsc();
        v10 = v8 + 2;
        *((_DWORD *)v10 - 2) = v9;
        Value[1] = v10;
      }
      ((void (__fastcall *)(hkpWorldPostSimulationListener *, hkpWorld *, _QWORD *))world->m_worldPostSimulationListeners.m_data[v6]->vfptr->postSimulationCallback)(
        world->m_worldPostSimulationListeners.m_data[v6],
        world,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_worldPostSimulationListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_worldPostSimulationListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_worldPostSimulationListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 484
// RVA: 0xD87570
void __fastcall hkpWorldCallbackUtil::firePostIntegrateCallback(hkpWorld *world, hkStepInfo *info)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpWorldPostIntegrateListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpWorldPostIntegrateListener **m_data; // rax
  bool v18; // zf
  hkpWorldPostIntegrateListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpWorldPostIntegrateListener *v22; // rcx

  v2 = world->m_worldPostIntegrateListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_worldPostIntegrateListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtpostIntCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_worldPostIntegrateListeners.m_data[i];
      v10->vfptr->postIntegrateCallback(v10, world, info);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_worldPostIntegrateListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_worldPostIntegrateListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_worldPostIntegrateListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 501
// RVA: 0xD876E0
void __fastcall hkpWorldCallbackUtil::firePostCollideCallback(hkpWorld *world, hkStepInfo *info)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpWorldPostCollideListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpWorldPostCollideListener **m_data; // rax
  bool v18; // zf
  hkpWorldPostCollideListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpWorldPostCollideListener *v22; // rcx

  v2 = world->m_worldPostCollideListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_worldPostCollideListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtpostCollCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_worldPostCollideListeners.m_data[i];
      v10->vfptr->postCollideCallback(v10, world, info);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_worldPostCollideListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_worldPostCollideListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_worldPostCollideListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 519
// RVA: 0xD87E90
void __fastcall hkpWorldCallbackUtil::fireIslandPostIntegrateCallback(
        hkpWorld *world,
        hkpSimulationIsland *island,
        hkStepInfo *info)
{
  int v3; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkpIslandPostIntegrateListener *v12; // rcx
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  int v17; // r9d
  __int64 j; // r10
  hkpIslandPostIntegrateListener **m_data; // rax
  bool v20; // zf
  hkpIslandPostIntegrateListener **v21; // rax
  int v22; // ecx
  __int64 v23; // rdx
  hkpIslandPostIntegrateListener *v24; // rcx

  v3 = world->m_islandPostIntegrateListeners.m_size - 1;
  for ( i = v3; i >= 0; --i )
  {
    if ( world->m_islandPostIntegrateListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v9 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v9 < Value[3] )
      {
        *v9 = "TtpostIntCb";
        v10 = __rdtsc();
        v11 = v9 + 2;
        *((_DWORD *)v11 - 2) = v10;
        Value[1] = v11;
      }
      v12 = world->m_islandPostIntegrateListeners.m_data[i];
      v12->vfptr->postIntegrateCallback(v12, island, info);
      v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v14 = (_QWORD *)v13[1];
      if ( (unsigned __int64)v14 < v13[3] )
      {
        *v14 = "Et";
        v15 = __rdtsc();
        v16 = v14 + 2;
        *((_DWORD *)v16 - 2) = v15;
        v13[1] = v16;
      }
    }
  }
  v17 = world->m_islandPostIntegrateListeners.m_size - 1;
  for ( j = v17; j >= 0; --j )
  {
    m_data = world->m_islandPostIntegrateListeners.m_data;
    v20 = m_data[j] == 0i64;
    v21 = &m_data[j];
    if ( v20 )
    {
      v22 = 8 * (--world->m_islandPostIntegrateListeners.m_size - v17);
      if ( v22 > 0 )
      {
        v23 = ((unsigned int)(v22 - 1) >> 3) + 1;
        do
        {
          v24 = v21[1];
          *v21++ = v24;
          --v23;
        }
        while ( v23 );
      }
    }
    --v17;
  }
}

// File Line: 537
// RVA: 0xD88010
void __fastcall hkpWorldCallbackUtil::fireIslandPostCollideCallback(
        hkpWorld *world,
        hkpSimulationIsland *island,
        hkStepInfo *info)
{
  int v3; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkpIslandPostCollideListener *v12; // rcx
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  int v17; // r9d
  __int64 j; // r10
  hkpIslandPostCollideListener **m_data; // rax
  bool v20; // zf
  hkpIslandPostCollideListener **v21; // rax
  int v22; // ecx
  __int64 v23; // rdx
  hkpIslandPostCollideListener *v24; // rcx

  v3 = world->m_islandPostCollideListeners.m_size - 1;
  for ( i = v3; i >= 0; --i )
  {
    if ( world->m_islandPostCollideListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v9 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v9 < Value[3] )
      {
        *v9 = "TtpostCollCb";
        v10 = __rdtsc();
        v11 = v9 + 2;
        *((_DWORD *)v11 - 2) = v10;
        Value[1] = v11;
      }
      v12 = world->m_islandPostCollideListeners.m_data[i];
      v12->vfptr->postCollideCallback(v12, island, info);
      v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v14 = (_QWORD *)v13[1];
      if ( (unsigned __int64)v14 < v13[3] )
      {
        *v14 = "Et";
        v15 = __rdtsc();
        v16 = v14 + 2;
        *((_DWORD *)v16 - 2) = v15;
        v13[1] = v16;
      }
    }
  }
  v17 = world->m_islandPostCollideListeners.m_size - 1;
  for ( j = v17; j >= 0; --j )
  {
    m_data = world->m_islandPostCollideListeners.m_data;
    v20 = m_data[j] == 0i64;
    v21 = &m_data[j];
    if ( v20 )
    {
      v22 = 8 * (--world->m_islandPostCollideListeners.m_size - v17);
      if ( v22 > 0 )
      {
        v23 = ((unsigned int)(v22 - 1) >> 3) + 1;
        do
        {
          v24 = v21[1];
          *v21++ = v24;
          --v23;
        }
        while ( v23 );
      }
    }
    --v17;
  }
}

// File Line: 554
// RVA: 0xD885B0
void __fastcall hkpWorldCallbackUtil::fireContactImpulseLimitBreached(
        hkpWorld *world,
        hkpContactImpulseLimitBreachedListenerInfo *breachedContacts,
        unsigned int numBreachedContacts)
{
  int v3; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkpContactImpulseLimitBreachedListener *v12; // rcx
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  int v17; // r9d
  __int64 j; // r10
  hkpContactImpulseLimitBreachedListener **m_data; // rax
  bool v20; // zf
  hkpContactImpulseLimitBreachedListener **v21; // rax
  int v22; // ecx
  __int64 v23; // rdx
  hkpContactImpulseLimitBreachedListener *v24; // rcx

  v3 = world->m_contactImpulseLimitBreachedListeners.m_size - 1;
  for ( i = v3; i >= 0; --i )
  {
    if ( world->m_contactImpulseLimitBreachedListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v9 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v9 < Value[3] )
      {
        *v9 = "TtimpLimitCb";
        v10 = __rdtsc();
        v11 = v9 + 2;
        *((_DWORD *)v11 - 2) = v10;
        Value[1] = v11;
      }
      v12 = world->m_contactImpulseLimitBreachedListeners.m_data[i];
      v12->vfptr->contactImpulseLimitBreachedCallback(v12, breachedContacts, numBreachedContacts);
      v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v14 = (_QWORD *)v13[1];
      if ( (unsigned __int64)v14 < v13[3] )
      {
        *v14 = "Et";
        v15 = __rdtsc();
        v16 = v14 + 2;
        *((_DWORD *)v16 - 2) = v15;
        v13[1] = v16;
      }
    }
  }
  v17 = world->m_contactImpulseLimitBreachedListeners.m_size - 1;
  for ( j = v17; j >= 0; --j )
  {
    m_data = world->m_contactImpulseLimitBreachedListeners.m_data;
    v20 = m_data[j] == 0i64;
    v21 = &m_data[j];
    if ( v20 )
    {
      v22 = 8 * (--world->m_contactImpulseLimitBreachedListeners.m_size - v17);
      if ( v22 > 0 )
      {
        v23 = ((unsigned int)(v22 - 1) >> 3) + 1;
        do
        {
          v24 = v21[1];
          *v21++ = v24;
          --v23;
        }
        while ( v23 );
      }
    }
    --v17;
  }
}

// File Line: 571
// RVA: 0xD88450
void __fastcall hkpWorldCallbackUtil::fireInactiveEntityMoved(hkpWorld *world, hkpEntity *entity)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpWorldPostSimulationListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpWorldPostSimulationListener **m_data; // rax
  bool v18; // zf
  hkpWorldPostSimulationListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpWorldPostSimulationListener *v22; // rcx

  v2 = world->m_worldPostSimulationListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_worldPostSimulationListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtentMvdCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_worldPostSimulationListeners.m_data[i];
      ((void (__fastcall *)(hkpWorldPostSimulationListener *, hkpEntity *, LPVOID))v10->vfptr->inactiveEntityMovedCallback)(
        v10,
        entity,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_worldPostSimulationListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_worldPostSimulationListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_worldPostSimulationListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 590
// RVA: 0xD88730
void __fastcall hkpWorldCallbackUtil::fireContactPointAdded(hkpWorld *world, hkpContactPointAddedEvent *event)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpContactListener **m_data; // rax
  bool v18; // zf
  hkpContactListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpContactListener *v22; // rcx

  event->m_callbackFiredFrom = 0i64;
  v2 = world->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_contactListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtcpAddCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_contactListeners.m_data[i];
      ((void (__fastcall *)(hkpContactListener *, hkpContactPointAddedEvent *, LPVOID))v10->vfptr->contactPointAddedCallback)(
        v10,
        event,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_contactListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_contactListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_contactListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 607
// RVA: 0xD888A0
void __fastcall hkpWorldCallbackUtil::fireContactPointRemoved(hkpWorld *world, hkpContactPointRemovedEvent *event)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpContactListener **m_data; // rax
  bool v18; // zf
  hkpContactListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpContactListener *v22; // rcx

  event->m_callbackFiredFrom = 0i64;
  v2 = world->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_contactListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtcpRemCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_contactListeners.m_data[i];
      ((void (__fastcall *)(hkpContactListener *, hkpContactPointRemovedEvent *, LPVOID))v10->vfptr->contactPointRemovedCallback)(
        v10,
        event,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_contactListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_contactListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_contactListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

// File Line: 624
// RVA: 0xD88A10
void __fastcall hkpWorldCallbackUtil::fireContactProcess(hkpWorld *world, hkpContactProcessEvent *event)
{
  int v2; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // r9d
  __int64 j; // r10
  hkpContactListener **m_data; // rax
  bool v18; // zf
  hkpContactListener **v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  hkpContactListener *v22; // rcx

  event->m_callbackFiredFrom = 0i64;
  v2 = world->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( world->m_contactListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtcpProcCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = world->m_contactListeners.m_data[i];
      ((void (__fastcall *)(hkpContactListener *, hkpContactProcessEvent *, LPVOID))v10->vfptr->contactProcessCallback)(
        v10,
        event,
        Value);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = v12 + 2;
        *((_DWORD *)v14 - 2) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = world->m_contactListeners.m_size - 1;
  for ( j = v15; j >= 0; --j )
  {
    m_data = world->m_contactListeners.m_data;
    v18 = m_data[j] == 0i64;
    v19 = &m_data[j];
    if ( v18 )
    {
      v20 = 8 * (--world->m_contactListeners.m_size - v15);
      if ( v20 > 0 )
      {
        v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
        do
        {
          v22 = v19[1];
          *v19++ = v22;
          --v21;
        }
        while ( v21 );
      }
    }
    --v15;
  }
}

