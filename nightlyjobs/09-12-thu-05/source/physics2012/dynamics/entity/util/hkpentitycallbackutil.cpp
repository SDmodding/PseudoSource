// File Line: 18
// RVA: 0xD854B0
void __fastcall hkpEntityCallbackUtil_cleanupNullPointers(hkSmallArray<void *> *cleanupArray)
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

// File Line: 29
// RVA: 0xD84530
void __fastcall hkpEntityCallbackUtil::fireEntityAdded(hkpEntity *entity)
{
  hkpEntity::ExtendedListeners *m_extendedListeners; // rdi
  int v3; // eax
  __int64 i; // rbx
  _QWORD *Value; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkpEntityListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx

  m_extendedListeners = entity->m_extendedListeners;
  if ( m_extendedListeners )
  {
    v3 = m_extendedListeners->m_entityListeners.m_size - 1;
    for ( i = v3; i >= 0; --i )
    {
      if ( m_extendedListeners->m_entityListeners.m_data[i] )
      {
        Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v6 = (_QWORD *)Value[1];
        if ( (unsigned __int64)v6 < Value[3] )
        {
          *v6 = "TtentAddCb";
          v7 = __rdtsc();
          v8 = v6 + 2;
          *((_DWORD *)v8 - 2) = v7;
          Value[1] = v8;
        }
        v9 = m_extendedListeners->m_entityListeners.m_data[i];
        ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, _QWORD *))v9->vfptr->entityAddedCallback)(
          v9,
          entity,
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
  }
}

// File Line: 49
// RVA: 0xD84630
void __fastcall hkpEntityCallbackUtil::fireEntityRemoved(hkpEntity *entity)
{
  hkpEntity::ExtendedListeners *m_extendedListeners; // rsi
  int v3; // eax
  __int64 i; // rdi
  _QWORD *Value; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkpEntityListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  _QWORD *v33; // rcx
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  _QWORD *v37; // rcx

  m_extendedListeners = entity->m_extendedListeners;
  if ( m_extendedListeners )
  {
    v3 = m_extendedListeners->m_entityListeners.m_size - 1;
    for ( i = v3; i >= 0; --i )
    {
      if ( m_extendedListeners->m_entityListeners.m_data[i] )
      {
        Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v6 = (_QWORD *)Value[1];
        if ( (unsigned __int64)v6 < Value[3] )
        {
          *v6 = "TtentRemCb";
          v7 = __rdtsc();
          v8 = v6 + 2;
          *((_DWORD *)v8 - 2) = v7;
          Value[1] = v8;
        }
        v9 = m_extendedListeners->m_entityListeners.m_data[i];
        ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, _QWORD *))v9->vfptr->entityRemovedCallback)(
          v9,
          entity,
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
  }
  while ( entity->m_constraintsMaster.m_size )
  {
    v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v15 = (_QWORD *)v14[1];
    if ( (unsigned __int64)v15 < v14[3] )
    {
      *v15 = "TtentRemCb";
      v16 = __rdtsc();
      v17 = v15 + 2;
      *((_DWORD *)v17 - 2) = v16;
      v14[1] = v17;
    }
    ((void (__fastcall *)(hkpConstraintInstance *, hkpEntity *, _QWORD *))entity->m_constraintsMaster.m_data->m_constraint->vfptr[2].__vecDelDtor)(
      entity->m_constraintsMaster.m_data->m_constraint,
      entity,
      v14);
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Et";
      v20 = __rdtsc();
      v21 = v19 + 2;
      *((_DWORD *)v21 - 2) = v20;
      v18[1] = v21;
    }
  }
  hkpEntity::sortConstraintsSlavesDeterministically(entity);
  while ( entity->m_constraintsSlave.m_size )
  {
    v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v23 = (_QWORD *)v22[1];
    if ( (unsigned __int64)v23 < v22[3] )
    {
      *v23 = "TtentRemCb";
      v24 = __rdtsc();
      v25 = v23 + 2;
      *((_DWORD *)v25 - 2) = v24;
      v22[1] = v25;
    }
    (*(void (__fastcall **)(hkpConstraintInstance *, hkpEntity *, _QWORD *))(**(_QWORD **)entity->m_constraintsSlave.m_data
                                                                           + 32i64))(
      *entity->m_constraintsSlave.m_data,
      entity,
      v22);
    v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v27 = (_QWORD *)v26[1];
    if ( (unsigned __int64)v27 < v26[3] )
    {
      *v27 = "Et";
      v28 = __rdtsc();
      v29 = v27 + 2;
      *((_DWORD *)v29 - 2) = v28;
      v26[1] = v29;
    }
  }
  while ( entity->m_actions.m_size )
  {
    v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v31 = (_QWORD *)v30[1];
    if ( (unsigned __int64)v31 < v30[3] )
    {
      *v31 = "TtentRemCb";
      v32 = __rdtsc();
      v33 = v31 + 2;
      *((_DWORD *)v33 - 2) = v32;
      v30[1] = v33;
    }
    (*(void (__fastcall **)(hkpAction *, hkpEntity *, _QWORD *))(**(_QWORD **)entity->m_actions.m_data + 48i64))(
      *entity->m_actions.m_data,
      entity,
      v30);
    v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v35 = (_QWORD *)v34[1];
    if ( (unsigned __int64)v35 < v34[3] )
    {
      *v35 = "Et";
      v36 = __rdtsc();
      v37 = v35 + 2;
      *((_DWORD *)v37 - 2) = v36;
      v34[1] = v37;
    }
  }
}

// File Line: 106
// RVA: 0xD848E0
void __fastcall hkpEntityCallbackUtil::fireEntityShapeSet(hkpEntity *entity)
{
  hkpEntity::ExtendedListeners *m_extendedListeners; // rdi
  int v3; // eax
  __int64 i; // rbx
  _QWORD *Value; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkpEntityListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx

  m_extendedListeners = entity->m_extendedListeners;
  if ( m_extendedListeners )
  {
    v3 = m_extendedListeners->m_entityListeners.m_size - 1;
    for ( i = v3; i >= 0; --i )
    {
      if ( m_extendedListeners->m_entityListeners.m_data[i] )
      {
        Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v6 = (_QWORD *)Value[1];
        if ( (unsigned __int64)v6 < Value[3] )
        {
          *v6 = "TtsetShapeCb";
          v7 = __rdtsc();
          v8 = v6 + 2;
          *((_DWORD *)v8 - 2) = v7;
          Value[1] = v8;
        }
        v9 = m_extendedListeners->m_entityListeners.m_data[i];
        ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, _QWORD *))v9->vfptr->entityShapeSetCallback)(
          v9,
          entity,
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
  }
}

// File Line: 122
// RVA: 0xD84AE0
void __fastcall hkpEntityCallbackUtil::fireEntitySetMotionType(hkpEntity *entity)
{
  hkpEntity::ExtendedListeners *m_extendedListeners; // rdi
  int v3; // eax
  __int64 i; // rbx
  _QWORD *Value; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkpEntityListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx

  m_extendedListeners = entity->m_extendedListeners;
  if ( m_extendedListeners )
  {
    v3 = m_extendedListeners->m_entityListeners.m_size - 1;
    for ( i = v3; i >= 0; --i )
    {
      if ( m_extendedListeners->m_entityListeners.m_data[i] )
      {
        Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v6 = (_QWORD *)Value[1];
        if ( (unsigned __int64)v6 < Value[3] )
        {
          *v6 = "TtsetMotionTypeCb";
          v7 = __rdtsc();
          v8 = v6 + 2;
          *((_DWORD *)v8 - 2) = v7;
          Value[1] = v8;
        }
        v9 = m_extendedListeners->m_entityListeners.m_data[i];
        ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, _QWORD *))v9->vfptr->entitySetMotionTypeCallback)(
          v9,
          entity,
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
  }
}

// File Line: 138
// RVA: 0xD849E0
void __fastcall hkpEntityCallbackUtil::fireEntityDeleted(hkpEntity *entity)
{
  hkpEntity::ExtendedListeners *m_extendedListeners; // rdi
  int v3; // eax
  __int64 i; // rbx
  _QWORD *Value; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkpEntityListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx

  m_extendedListeners = entity->m_extendedListeners;
  if ( m_extendedListeners )
  {
    v3 = m_extendedListeners->m_entityListeners.m_size - 1;
    for ( i = v3; i >= 0; --i )
    {
      if ( m_extendedListeners->m_entityListeners.m_data[i] )
      {
        Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v6 = (_QWORD *)Value[1];
        if ( (unsigned __int64)v6 < Value[3] )
        {
          *v6 = "TtentDelCb";
          v7 = __rdtsc();
          v8 = v6 + 2;
          *((_DWORD *)v8 - 2) = v7;
          Value[1] = v8;
        }
        v9 = m_extendedListeners->m_entityListeners.m_data[i];
        ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, _QWORD *))v9->vfptr->entityDeletedCallback)(
          v9,
          entity,
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
  }
}

// File Line: 155
// RVA: 0xD84EC0
void __fastcall hkpEntityCallbackUtil::fireContactPointCallbackInternal(hkpEntity *entity, hkpContactPointEvent *event)
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
  __int64 v16; // r10
  int v17; // r8d
  __int64 v18; // rdx

  v2 = entity->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( entity->m_contactListeners.m_data[i] )
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
      v10 = entity->m_contactListeners.m_data[i];
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
  v15 = entity->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !entity->m_contactListeners.m_data[v16] )
      {
        --entity->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < entity->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18);
          }
          while ( v17 < entity->m_contactListeners.m_size );
        }
      }
      --v16;
      --v15;
    }
    while ( v15 >= 0 );
  }
}

// File Line: 171
// RVA: 0xD84BE0
void __fastcall hkpEntityCallbackUtil::fireContactConstraintAddedCallback(hkpEntity *entity, hkpCollisionEvent *event)
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
  __int64 v16; // r10
  int v17; // r8d
  __int64 v18; // rdx

  v2 = entity->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( entity->m_contactListeners.m_data[i] )
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
      v10 = entity->m_contactListeners.m_data[i];
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
  v15 = entity->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !entity->m_contactListeners.m_data[v16] )
      {
        --entity->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < entity->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18);
          }
          while ( v17 < entity->m_contactListeners.m_size );
        }
      }
      --v16;
      --v15;
    }
    while ( v15 >= 0 );
  }
}

// File Line: 186
// RVA: 0xD84D50
void __fastcall hkpEntityCallbackUtil::fireContactConstraintRemovedCallback(
        hkpEntity *entity,
        hkpCollisionEvent *event)
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
  __int64 v16; // r10
  int v17; // r8d
  __int64 v18; // rdx

  v2 = entity->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( entity->m_contactListeners.m_data[i] )
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
      v10 = entity->m_contactListeners.m_data[i];
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
  v15 = entity->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !entity->m_contactListeners.m_data[v16] )
      {
        --entity->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < entity->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18);
          }
          while ( v17 < entity->m_contactListeners.m_size );
        }
      }
      --v16;
      --v15;
    }
    while ( v15 >= 0 );
  }
}

// File Line: 203
// RVA: 0xD85030
void __fastcall hkpEntityCallbackUtil::fireContactPointAddedInternal(
        hkpEntity *entity,
        hkpContactPointAddedEvent *event)
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
  __int64 v16; // r10
  int v17; // r8d
  __int64 v18; // rdx

  event->m_callbackFiredFrom = entity;
  v2 = entity->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( entity->m_contactListeners.m_data[i] )
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
      v10 = entity->m_contactListeners.m_data[i];
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
  v15 = entity->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !entity->m_contactListeners.m_data[v16] )
      {
        --entity->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < entity->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18);
          }
          while ( v17 < entity->m_contactListeners.m_size );
        }
      }
      --v16;
      --v15;
    }
    while ( v15 >= 0 );
  }
}

// File Line: 221
// RVA: 0xD851B0
void __fastcall hkpEntityCallbackUtil::fireContactPointRemovedInternal(
        hkpEntity *entity,
        hkpContactPointRemovedEvent *event)
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
  __int64 v16; // r10
  int v17; // r8d
  __int64 v18; // rdx

  event->m_callbackFiredFrom = entity;
  v2 = entity->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( entity->m_contactListeners.m_data[i] )
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
      v10 = entity->m_contactListeners.m_data[i];
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
  v15 = entity->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !entity->m_contactListeners.m_data[v16] )
      {
        --entity->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < entity->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18);
          }
          while ( v17 < entity->m_contactListeners.m_size );
        }
      }
      --v16;
      --v15;
    }
    while ( v15 >= 0 );
  }
}

// File Line: 238
// RVA: 0xD85330
void __fastcall hkpEntityCallbackUtil::fireContactProcessInternal(hkpEntity *entity, hkpContactProcessEvent *event)
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
  __int64 v16; // r10
  int v17; // r8d
  __int64 v18; // rdx

  event->m_callbackFiredFrom = entity;
  v2 = entity->m_contactListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    if ( entity->m_contactListeners.m_data[i] )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v7 < Value[3] )
      {
        *v7 = "TtcpProCb";
        v8 = __rdtsc();
        v9 = v7 + 2;
        *((_DWORD *)v9 - 2) = v8;
        Value[1] = v9;
      }
      v10 = entity->m_contactListeners.m_data[i];
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
  v15 = entity->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !entity->m_contactListeners.m_data[v16] )
      {
        --entity->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < entity->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)entity->m_contactListeners.m_data + v18);
          }
          while ( v17 < entity->m_contactListeners.m_size );
        }
      }
      --v16;
      --v15;
    }
    while ( v15 >= 0 );
  }
}

