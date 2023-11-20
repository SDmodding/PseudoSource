// File Line: 18
// RVA: 0xD854B0
void __fastcall hkpEntityCallbackUtil_cleanupNullPointers(hkSmallArray<void *> *cleanupArray)
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

// File Line: 29
// RVA: 0xD84530
void __fastcall hkpEntityCallbackUtil::fireEntityAdded(hkpEntity *entity)
{
  hkpEntity::ExtendedListeners *v1; // rdi
  hkpEntity *v2; // rsi
  int v3; // eax
  __int64 i; // rbx
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkpEntityListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx

  v1 = entity->m_extendedListeners;
  v2 = entity;
  if ( v1 )
  {
    v3 = v1->m_entityListeners.m_size - 1;
    for ( i = v3; i >= 0; --i )
    {
      if ( v1->m_entityListeners.m_data[i] )
      {
        v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v6 = (_QWORD *)v5[1];
        if ( (unsigned __int64)v6 < v5[3] )
        {
          *v6 = "TtentAddCb";
          v7 = __rdtsc();
          v8 = (signed __int64)(v6 + 2);
          *(_DWORD *)(v8 - 8) = v7;
          v5[1] = v8;
        }
        v9 = v1->m_entityListeners.m_data[i];
        ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, _QWORD *))v9->vfptr->entityAddedCallback)(v9, v2, v5);
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
  }
}

// File Line: 49
// RVA: 0xD84630
void __fastcall hkpEntityCallbackUtil::fireEntityRemoved(hkpEntity *entity)
{
  hkpEntity::ExtendedListeners *v1; // rsi
  hkpEntity *v2; // rbx
  int v3; // eax
  __int64 i; // rdi
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkpEntityListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  signed __int64 v33; // rcx
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  signed __int64 v37; // rcx

  v1 = entity->m_extendedListeners;
  v2 = entity;
  if ( v1 )
  {
    v3 = v1->m_entityListeners.m_size - 1;
    for ( i = v3; i >= 0; --i )
    {
      if ( v1->m_entityListeners.m_data[i] )
      {
        v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v6 = (_QWORD *)v5[1];
        if ( (unsigned __int64)v6 < v5[3] )
        {
          *v6 = "TtentRemCb";
          v7 = __rdtsc();
          v8 = (signed __int64)(v6 + 2);
          *(_DWORD *)(v8 - 8) = v7;
          v5[1] = v8;
        }
        v9 = v1->m_entityListeners.m_data[i];
        ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, _QWORD *))v9->vfptr->entityRemovedCallback)(v9, v2, v5);
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
  }
  while ( v2->m_constraintsMaster.m_size )
  {
    v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v15 = (_QWORD *)v14[1];
    if ( (unsigned __int64)v15 < v14[3] )
    {
      *v15 = "TtentRemCb";
      v16 = __rdtsc();
      v17 = (signed __int64)(v15 + 2);
      *(_DWORD *)(v17 - 8) = v16;
      v14[1] = v17;
    }
    ((void (__fastcall *)(hkpConstraintInstance *, hkpEntity *, _QWORD *))v2->m_constraintsMaster.m_data->m_constraint->vfptr[2].__vecDelDtor)(
      v2->m_constraintsMaster.m_data->m_constraint,
      v2,
      v14);
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Et";
      v20 = __rdtsc();
      v21 = (signed __int64)(v19 + 2);
      *(_DWORD *)(v21 - 8) = v20;
      v18[1] = v21;
    }
  }
  hkpEntity::sortConstraintsSlavesDeterministically(v2);
  while ( v2->m_constraintsSlave.m_size )
  {
    v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v23 = (_QWORD *)v22[1];
    if ( (unsigned __int64)v23 < v22[3] )
    {
      *v23 = "TtentRemCb";
      v24 = __rdtsc();
      v25 = (signed __int64)(v23 + 2);
      *(_DWORD *)(v25 - 8) = v24;
      v22[1] = v25;
    }
    (*(void (__fastcall **)(hkpConstraintInstance *, hkpEntity *, _QWORD *))(**(_QWORD **)v2->m_constraintsSlave.m_data
                                                                           + 32i64))(
      *v2->m_constraintsSlave.m_data,
      v2,
      v22);
    v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v27 = (_QWORD *)v26[1];
    if ( (unsigned __int64)v27 < v26[3] )
    {
      *v27 = "Et";
      v28 = __rdtsc();
      v29 = (signed __int64)(v27 + 2);
      *(_DWORD *)(v29 - 8) = v28;
      v26[1] = v29;
    }
  }
  while ( v2->m_actions.m_size )
  {
    v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v31 = (_QWORD *)v30[1];
    if ( (unsigned __int64)v31 < v30[3] )
    {
      *v31 = "TtentRemCb";
      v32 = __rdtsc();
      v33 = (signed __int64)(v31 + 2);
      *(_DWORD *)(v33 - 8) = v32;
      v30[1] = v33;
    }
    (*(void (__fastcall **)(hkpAction *, hkpEntity *, _QWORD *))(**(_QWORD **)v2->m_actions.m_data + 48i64))(
      *v2->m_actions.m_data,
      v2,
      v30);
    v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v35 = (_QWORD *)v34[1];
    if ( (unsigned __int64)v35 < v34[3] )
    {
      *v35 = "Et";
      v36 = __rdtsc();
      v37 = (signed __int64)(v35 + 2);
      *(_DWORD *)(v37 - 8) = v36;
      v34[1] = v37;
    }
  }
}

// File Line: 106
// RVA: 0xD848E0
void __fastcall hkpEntityCallbackUtil::fireEntityShapeSet(hkpEntity *entity)
{
  hkpEntity::ExtendedListeners *v1; // rdi
  hkpEntity *v2; // rsi
  int v3; // eax
  __int64 i; // rbx
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkpEntityListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx

  v1 = entity->m_extendedListeners;
  v2 = entity;
  if ( v1 )
  {
    v3 = v1->m_entityListeners.m_size - 1;
    for ( i = v3; i >= 0; --i )
    {
      if ( v1->m_entityListeners.m_data[i] )
      {
        v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v6 = (_QWORD *)v5[1];
        if ( (unsigned __int64)v6 < v5[3] )
        {
          *v6 = "TtsetShapeCb";
          v7 = __rdtsc();
          v8 = (signed __int64)(v6 + 2);
          *(_DWORD *)(v8 - 8) = v7;
          v5[1] = v8;
        }
        v9 = v1->m_entityListeners.m_data[i];
        ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, _QWORD *))v9->vfptr->entityShapeSetCallback)(v9, v2, v5);
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
  }
}

// File Line: 122
// RVA: 0xD84AE0
void __fastcall hkpEntityCallbackUtil::fireEntitySetMotionType(hkpEntity *entity)
{
  hkpEntity::ExtendedListeners *v1; // rdi
  hkpEntity *v2; // rsi
  int v3; // eax
  __int64 i; // rbx
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkpEntityListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx

  v1 = entity->m_extendedListeners;
  v2 = entity;
  if ( v1 )
  {
    v3 = v1->m_entityListeners.m_size - 1;
    for ( i = v3; i >= 0; --i )
    {
      if ( v1->m_entityListeners.m_data[i] )
      {
        v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v6 = (_QWORD *)v5[1];
        if ( (unsigned __int64)v6 < v5[3] )
        {
          *v6 = "TtsetMotionTypeCb";
          v7 = __rdtsc();
          v8 = (signed __int64)(v6 + 2);
          *(_DWORD *)(v8 - 8) = v7;
          v5[1] = v8;
        }
        v9 = v1->m_entityListeners.m_data[i];
        ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, _QWORD *))v9->vfptr->entitySetMotionTypeCallback)(
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
  }
}

// File Line: 138
// RVA: 0xD849E0
void __fastcall hkpEntityCallbackUtil::fireEntityDeleted(hkpEntity *entity)
{
  hkpEntity::ExtendedListeners *v1; // rdi
  hkpEntity *v2; // rsi
  int v3; // eax
  __int64 i; // rbx
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkpEntityListener *v9; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx

  v1 = entity->m_extendedListeners;
  v2 = entity;
  if ( v1 )
  {
    v3 = v1->m_entityListeners.m_size - 1;
    for ( i = v3; i >= 0; --i )
    {
      if ( v1->m_entityListeners.m_data[i] )
      {
        v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v6 = (_QWORD *)v5[1];
        if ( (unsigned __int64)v6 < v5[3] )
        {
          *v6 = "TtentDelCb";
          v7 = __rdtsc();
          v8 = (signed __int64)(v6 + 2);
          *(_DWORD *)(v8 - 8) = v7;
          v5[1] = v8;
        }
        v9 = v1->m_entityListeners.m_data[i];
        ((void (__fastcall *)(hkpEntityListener *, hkpEntity *, _QWORD *))v9->vfptr->entityDeletedCallback)(v9, v2, v5);
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
  }
}

// File Line: 155
// RVA: 0xD84EC0
void __fastcall hkpEntityCallbackUtil::fireContactPointCallbackInternal(hkpEntity *entity, hkpContactPointEvent *event)
{
  int v2; // eax
  hkpContactPointEvent *v3; // rsi
  hkpEntity *v4; // rbx
  __int64 i; // rdi
  _QWORD *v6; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  int v15; // er9
  signed __int64 v16; // r10
  signed int v17; // er8
  signed __int64 v18; // rdx

  v2 = entity->m_contactListeners.m_size - 1;
  v3 = event;
  v4 = entity;
  for ( i = v2; i >= 0; --i )
  {
    if ( v4->m_contactListeners.m_data[i] )
    {
      v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)v6[1];
      if ( (unsigned __int64)v7 < v6[3] )
      {
        *v7 = "TtcpCb";
        v8 = __rdtsc();
        v9 = (signed __int64)(v7 + 2);
        *(_DWORD *)(v9 - 8) = v8;
        v6[1] = v9;
      }
      v10 = v4->m_contactListeners.m_data[i];
      ((void (__fastcall *)(hkpContactListener *, hkpContactPointEvent *, _QWORD *))v10->vfptr->contactPointCallback)(
        v10,
        v3,
        v6);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = (signed __int64)(v12 + 2);
        *(_DWORD *)(v14 - 8) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = v4->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !v4->m_contactListeners.m_data[v16] )
      {
        --v4->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < v4->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)v4->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)v4->m_contactListeners.m_data + v18);
          }
          while ( v17 < v4->m_contactListeners.m_size );
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
  hkpCollisionEvent *v3; // rsi
  hkpEntity *v4; // rbx
  __int64 i; // rdi
  _QWORD *v6; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  int v15; // er9
  signed __int64 v16; // r10
  signed int v17; // er8
  signed __int64 v18; // rdx

  v2 = entity->m_contactListeners.m_size - 1;
  v3 = event;
  v4 = entity;
  for ( i = v2; i >= 0; --i )
  {
    if ( v4->m_contactListeners.m_data[i] )
    {
      v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)v6[1];
      if ( (unsigned __int64)v7 < v6[3] )
      {
        *v7 = "TtNewCollCb";
        v8 = __rdtsc();
        v9 = (signed __int64)(v7 + 2);
        *(_DWORD *)(v9 - 8) = v8;
        v6[1] = v9;
      }
      v10 = v4->m_contactListeners.m_data[i];
      ((void (__fastcall *)(hkpContactListener *, hkpCollisionEvent *, _QWORD *))v10->vfptr->collisionAddedCallback)(
        v10,
        v3,
        v6);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = (signed __int64)(v12 + 2);
        *(_DWORD *)(v14 - 8) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = v4->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !v4->m_contactListeners.m_data[v16] )
      {
        --v4->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < v4->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)v4->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)v4->m_contactListeners.m_data + v18);
          }
          while ( v17 < v4->m_contactListeners.m_size );
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
void __fastcall hkpEntityCallbackUtil::fireContactConstraintRemovedCallback(hkpEntity *entity, hkpCollisionEvent *event)
{
  int v2; // eax
  hkpCollisionEvent *v3; // rsi
  hkpEntity *v4; // rbx
  __int64 i; // rdi
  _QWORD *v6; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  int v15; // er9
  signed __int64 v16; // r10
  signed int v17; // er8
  signed __int64 v18; // rdx

  v2 = entity->m_contactListeners.m_size - 1;
  v3 = event;
  v4 = entity;
  for ( i = v2; i >= 0; --i )
  {
    if ( v4->m_contactListeners.m_data[i] )
    {
      v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)v6[1];
      if ( (unsigned __int64)v7 < v6[3] )
      {
        *v7 = "TtFinCollCb";
        v8 = __rdtsc();
        v9 = (signed __int64)(v7 + 2);
        *(_DWORD *)(v9 - 8) = v8;
        v6[1] = v9;
      }
      v10 = v4->m_contactListeners.m_data[i];
      ((void (__fastcall *)(hkpContactListener *, hkpCollisionEvent *, _QWORD *))v10->vfptr->collisionRemovedCallback)(
        v10,
        v3,
        v6);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = (signed __int64)(v12 + 2);
        *(_DWORD *)(v14 - 8) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = v4->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !v4->m_contactListeners.m_data[v16] )
      {
        --v4->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < v4->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)v4->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)v4->m_contactListeners.m_data + v18);
          }
          while ( v17 < v4->m_contactListeners.m_size );
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
void __fastcall hkpEntityCallbackUtil::fireContactPointAddedInternal(hkpEntity *entity, hkpContactPointAddedEvent *event)
{
  int v2; // eax
  hkpContactPointAddedEvent *v3; // rsi
  __int64 v4; // rdi
  hkpEntity *i; // rbx
  _QWORD *v6; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  int v15; // er9
  signed __int64 v16; // r10
  signed int v17; // er8
  signed __int64 v18; // rdx

  event->m_callbackFiredFrom = entity;
  v2 = entity->m_contactListeners.m_size - 1;
  v3 = event;
  v4 = v2;
  for ( i = entity; v4 >= 0; --v4 )
  {
    if ( i->m_contactListeners.m_data[v4] )
    {
      v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)v6[1];
      if ( (unsigned __int64)v7 < v6[3] )
      {
        *v7 = "TtcpAddCb";
        v8 = __rdtsc();
        v9 = (signed __int64)(v7 + 2);
        *(_DWORD *)(v9 - 8) = v8;
        v6[1] = v9;
      }
      v10 = i->m_contactListeners.m_data[v4];
      ((void (__fastcall *)(hkpContactListener *, hkpContactPointAddedEvent *, _QWORD *))v10->vfptr->contactPointAddedCallback)(
        v10,
        v3,
        v6);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = (signed __int64)(v12 + 2);
        *(_DWORD *)(v14 - 8) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = i->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !i->m_contactListeners.m_data[v16] )
      {
        --i->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < i->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)i->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)i->m_contactListeners.m_data + v18);
          }
          while ( v17 < i->m_contactListeners.m_size );
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
void __fastcall hkpEntityCallbackUtil::fireContactPointRemovedInternal(hkpEntity *entity, hkpContactPointRemovedEvent *event)
{
  int v2; // eax
  hkpContactPointRemovedEvent *v3; // rsi
  __int64 v4; // rdi
  hkpEntity *i; // rbx
  _QWORD *v6; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  int v15; // er9
  signed __int64 v16; // r10
  signed int v17; // er8
  signed __int64 v18; // rdx

  event->m_callbackFiredFrom = entity;
  v2 = entity->m_contactListeners.m_size - 1;
  v3 = event;
  v4 = v2;
  for ( i = entity; v4 >= 0; --v4 )
  {
    if ( i->m_contactListeners.m_data[v4] )
    {
      v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)v6[1];
      if ( (unsigned __int64)v7 < v6[3] )
      {
        *v7 = "TtcpRemCb";
        v8 = __rdtsc();
        v9 = (signed __int64)(v7 + 2);
        *(_DWORD *)(v9 - 8) = v8;
        v6[1] = v9;
      }
      v10 = i->m_contactListeners.m_data[v4];
      ((void (__fastcall *)(hkpContactListener *, hkpContactPointRemovedEvent *, _QWORD *))v10->vfptr->contactPointRemovedCallback)(
        v10,
        v3,
        v6);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = (signed __int64)(v12 + 2);
        *(_DWORD *)(v14 - 8) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = i->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !i->m_contactListeners.m_data[v16] )
      {
        --i->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < i->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)i->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)i->m_contactListeners.m_data + v18);
          }
          while ( v17 < i->m_contactListeners.m_size );
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
  hkpContactProcessEvent *v3; // rsi
  __int64 v4; // rdi
  hkpEntity *i; // rbx
  _QWORD *v6; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  hkpContactListener *v10; // rcx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  int v15; // er9
  signed __int64 v16; // r10
  signed int v17; // er8
  signed __int64 v18; // rdx

  event->m_callbackFiredFrom = entity;
  v2 = entity->m_contactListeners.m_size - 1;
  v3 = event;
  v4 = v2;
  for ( i = entity; v4 >= 0; --v4 )
  {
    if ( i->m_contactListeners.m_data[v4] )
    {
      v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = (_QWORD *)v6[1];
      if ( (unsigned __int64)v7 < v6[3] )
      {
        *v7 = "TtcpProCb";
        v8 = __rdtsc();
        v9 = (signed __int64)(v7 + 2);
        *(_DWORD *)(v9 - 8) = v8;
        v6[1] = v9;
      }
      v10 = i->m_contactListeners.m_data[v4];
      ((void (__fastcall *)(hkpContactListener *, hkpContactProcessEvent *, _QWORD *))v10->vfptr->contactProcessCallback)(
        v10,
        v3,
        v6);
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = (_QWORD *)v11[1];
      if ( (unsigned __int64)v12 < v11[3] )
      {
        *v12 = "Et";
        v13 = __rdtsc();
        v14 = (signed __int64)(v12 + 2);
        *(_DWORD *)(v14 - 8) = v13;
        v11[1] = v14;
      }
    }
  }
  v15 = i->m_contactListeners.m_size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      if ( !i->m_contactListeners.m_data[v16] )
      {
        --i->m_contactListeners.m_size;
        v17 = v15;
        if ( v15 < i->m_contactListeners.m_size )
        {
          v18 = v16 * 8;
          do
          {
            ++v17;
            v18 += 8i64;
            *(hkpContactListener **)((char *)i->m_contactListeners.m_data + v18 - 8) = *(hkpContactListener **)((char *)i->m_contactListeners.m_data + v18);
          }
          while ( v17 < i->m_contactListeners.m_size );
        }
      }
      --v16;
      --v15;
    }
    while ( v15 >= 0 );
  }
}

