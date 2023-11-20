// File Line: 32
// RVA: 0xA4D810
void __fastcall CAkAudioLibIndex::Init(CAkAudioLibIndex *this)
{
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v1; // rax
  signed __int64 v2; // rdx
  CAkAudioLibIndex *v3; // r9
  signed __int64 v4; // r8
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v5; // rax
  signed __int64 v6; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v7; // rax
  signed __int64 v8; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v9; // rax
  signed __int64 v10; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v11; // rax
  signed __int64 v12; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v13; // rax
  signed __int64 v14; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v15; // rax
  signed __int64 v16; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v17; // rax
  signed __int64 v18; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v19; // rax
  signed __int64 v20; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v21; // rax
  signed __int64 v22; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v23; // rax

  v1 = &this->m_idxAudioNode.m_mapIDToPtr;
  v2 = 24i64;
  this->m_idxAudioNode.m_mapIDToPtr.m_uiSize = 0;
  v3 = this;
  v4 = 24i64;
  do
  {
    v1->m_table[0] = 0i64;
    v1->m_table[1] = 0i64;
    v1->m_table[2] = 0i64;
    v1 = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)v1 + 64);
    v1[-1].m_table[189] = 0i64;
    v1[-1].m_table[190] = 0i64;
    v1[-1].m_table[191] = 0i64;
    v1[-1].m_table[192] = 0i64;
    *(_QWORD *)&v1[-1].m_uiSize = 0i64;
    --v4;
  }
  while ( v4 );
  v1->m_table[0] = 0i64;
  v5 = &this->m_idxBusses.m_mapIDToPtr;
  v6 = 24i64;
  v5->m_uiSize = 0;
  do
  {
    v5->m_table[0] = 0i64;
    v5->m_table[1] = 0i64;
    v5->m_table[2] = 0i64;
    v5 = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)v5 + 64);
    v5[-1].m_table[189] = 0i64;
    v5[-1].m_table[190] = 0i64;
    v5[-1].m_table[191] = 0i64;
    v5[-1].m_table[192] = 0i64;
    *(_QWORD *)&v5[-1].m_uiSize = 0i64;
    --v6;
  }
  while ( v6 );
  v5->m_table[0] = 0i64;
  v7 = &v3->m_idxCustomStates.m_mapIDToPtr;
  v8 = 24i64;
  v3->m_idxCustomStates.m_mapIDToPtr.m_uiSize = 0;
  do
  {
    v7->m_table[0] = 0i64;
    v7->m_table[1] = 0i64;
    v7->m_table[2] = 0i64;
    v7 = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)v7 + 64);
    v7[-1].m_table[189] = 0i64;
    v7[-1].m_table[190] = 0i64;
    v7[-1].m_table[191] = 0i64;
    v7[-1].m_table[192] = 0i64;
    *(_QWORD *)&v7[-1].m_uiSize = 0i64;
    --v8;
  }
  while ( v8 );
  v7->m_table[0] = 0i64;
  v9 = &v3->m_idxEvents.m_mapIDToPtr;
  v10 = 24i64;
  v3->m_idxEvents.m_mapIDToPtr.m_uiSize = 0;
  do
  {
    v9->m_table[0] = 0i64;
    v9->m_table[1] = 0i64;
    v9->m_table[2] = 0i64;
    v9 = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)v9 + 64);
    v9[-1].m_table[189] = 0i64;
    v9[-1].m_table[190] = 0i64;
    v9[-1].m_table[191] = 0i64;
    v9[-1].m_table[192] = 0i64;
    *(_QWORD *)&v9[-1].m_uiSize = 0i64;
    --v10;
  }
  while ( v10 );
  v9->m_table[0] = 0i64;
  v11 = &v3->m_idxActions.m_mapIDToPtr;
  v12 = 24i64;
  v3->m_idxActions.m_mapIDToPtr.m_uiSize = 0;
  do
  {
    v11->m_table[0] = 0i64;
    v11->m_table[1] = 0i64;
    v11->m_table[2] = 0i64;
    v11 = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)v11 + 64);
    v11[-1].m_table[189] = 0i64;
    v11[-1].m_table[190] = 0i64;
    v11[-1].m_table[191] = 0i64;
    v11[-1].m_table[192] = 0i64;
    *(_QWORD *)&v11[-1].m_uiSize = 0i64;
    --v12;
  }
  while ( v12 );
  v11->m_table[0] = 0i64;
  v13 = &v3->m_idxLayers.m_mapIDToPtr;
  v14 = 24i64;
  v3->m_idxLayers.m_mapIDToPtr.m_uiSize = 0;
  do
  {
    v13->m_table[0] = 0i64;
    v13->m_table[1] = 0i64;
    v13->m_table[2] = 0i64;
    v13 = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)v13 + 64);
    v13[-1].m_table[189] = 0i64;
    v13[-1].m_table[190] = 0i64;
    v13[-1].m_table[191] = 0i64;
    v13[-1].m_table[192] = 0i64;
    *(_QWORD *)&v13[-1].m_uiSize = 0i64;
    --v14;
  }
  while ( v14 );
  v13->m_table[0] = 0i64;
  v15 = &v3->m_idxAttenuations.m_mapIDToPtr;
  v16 = 24i64;
  v3->m_idxAttenuations.m_mapIDToPtr.m_uiSize = 0;
  do
  {
    v15->m_table[0] = 0i64;
    v15->m_table[1] = 0i64;
    v15->m_table[2] = 0i64;
    v15 = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)v15 + 64);
    v15[-1].m_table[189] = 0i64;
    v15[-1].m_table[190] = 0i64;
    v15[-1].m_table[191] = 0i64;
    v15[-1].m_table[192] = 0i64;
    *(_QWORD *)&v15[-1].m_uiSize = 0i64;
    --v16;
  }
  while ( v16 );
  v15->m_table[0] = 0i64;
  v17 = &v3->m_idxDynamicSequences.m_mapIDToPtr;
  v18 = 24i64;
  v3->m_idxDynamicSequences.m_mapIDToPtr.m_uiSize = 0;
  do
  {
    v17->m_table[0] = 0i64;
    v17->m_table[1] = 0i64;
    v17->m_table[2] = 0i64;
    v17 = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)v17 + 64);
    v17[-1].m_table[189] = 0i64;
    v17[-1].m_table[190] = 0i64;
    v17[-1].m_table[191] = 0i64;
    v17[-1].m_table[192] = 0i64;
    *(_QWORD *)&v17[-1].m_uiSize = 0i64;
    --v18;
  }
  while ( v18 );
  v17->m_table[0] = 0i64;
  v19 = &v3->m_idxDialogueEvents.m_mapIDToPtr;
  v20 = 24i64;
  v3->m_idxDialogueEvents.m_mapIDToPtr.m_uiSize = 0;
  do
  {
    v19->m_table[0] = 0i64;
    v19->m_table[1] = 0i64;
    v19->m_table[2] = 0i64;
    v19 = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)v19 + 64);
    v19[-1].m_table[189] = 0i64;
    v19[-1].m_table[190] = 0i64;
    v19[-1].m_table[191] = 0i64;
    v19[-1].m_table[192] = 0i64;
    *(_QWORD *)&v19[-1].m_uiSize = 0i64;
    --v20;
  }
  while ( v20 );
  v19->m_table[0] = 0i64;
  v21 = &v3->m_idxFxShareSets.m_mapIDToPtr;
  v22 = 24i64;
  v3->m_idxFxShareSets.m_mapIDToPtr.m_uiSize = 0;
  do
  {
    v21->m_table[0] = 0i64;
    v21->m_table[1] = 0i64;
    v21->m_table[2] = 0i64;
    v21 = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)v21 + 64);
    v21[-1].m_table[189] = 0i64;
    v21[-1].m_table[190] = 0i64;
    v21[-1].m_table[191] = 0i64;
    v21[-1].m_table[192] = 0i64;
    *(_QWORD *)&v21[-1].m_uiSize = 0i64;
    --v22;
  }
  while ( v22 );
  v21->m_table[0] = 0i64;
  v23 = &v3->m_idxFxCustom.m_mapIDToPtr;
  v3->m_idxFxCustom.m_mapIDToPtr.m_uiSize = 0;
  do
  {
    v23->m_table[0] = 0i64;
    v23->m_table[1] = 0i64;
    v23->m_table[2] = 0i64;
    v23 = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)v23 + 64);
    v23[-1].m_table[189] = 0i64;
    v23[-1].m_table[190] = 0i64;
    v23[-1].m_table[191] = 0i64;
    v23[-1].m_table[192] = 0i64;
    *(_QWORD *)&v23[-1].m_uiSize = 0i64;
    --v2;
  }
  while ( v2 );
  v23->m_table[0] = 0i64;
}table[192] = 0i64;
    *(_QWORD *)&v23[-1].m_uiSize = 0i64;
    --v2;
  }
  while ( v2 );
  v23->m_table[0] = 0i64;
}

// File Line: 62
// RVA: 0xA4DB90
void __fastcall CAkAudioLibIndex::ReleaseTempObjects(CAkAudioLibIndex *this)
{
  CAkAudioLibIndex *v1; // rbp
  CAkIndexable *i; // rsi
  __int64 v3; // rbx
  __int64 v4; // rdi
  CAkIndexable *v5; // rcx
  CAkIndexable *j; // rdi
  CAkIndexable *v7; // rcx

  v1 = this;
  EnterCriticalSection(&this->m_idxAudioNode.m_IndexLock.m_csLock);
  i = v1->m_idxAudioNode.m_mapIDToPtr.m_table[0];
  LODWORD(v3) = 0;
  LODWORD(v4) = 0;
  if ( i )
    goto LABEL_25;
  while ( 1 )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= 0xC1 )
      break;
    i = v1->m_idxAudioNode.m_mapIDToPtr.m_table[v4];
    if ( i )
      goto LABEL_6;
  }
  if ( i )
  {
LABEL_25:
    do
    {
LABEL_6:
      v5 = i;
      for ( i = i->pNextItem; !i; i = v1->m_idxAudioNode.m_mapIDToPtr.m_table[v4] )
      {
        v4 = (unsigned int)(v4 + 1);
        if ( (unsigned int)v4 >= 0xC1 )
          break;
      }
      if ( (v5->key & 0x80000000) != 0 )
        ((void (*)(void))v5->vfptr->Release)();
    }
    while ( i );
  }
  LeaveCriticalSection(&v1->m_idxAudioNode.m_IndexLock.m_csLock);
  j = v1->m_idxFxCustom.m_mapIDToPtr.m_table[0];
  if ( j )
    goto LABEL_26;
  while ( 1 )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= 0xC1 )
      break;
    j = v1->m_idxFxCustom.m_mapIDToPtr.m_table[v3];
    if ( j )
      goto LABEL_17;
  }
  if ( j )
  {
LABEL_26:
    do
    {
LABEL_17:
      v7 = j;
      for ( j = j->pNextItem; !j; j = v1->m_idxFxCustom.m_mapIDToPtr.m_table[v3] )
      {
        v3 = (unsigned int)(v3 + 1);
        if ( (unsigned int)v3 >= 0xC1 )
          break;
      }
      if ( (v7->key & 0x80000000) != 0 )
        ((void (*)(void))v7->vfptr->Release)();
    }
    while ( j );
  }
}

// File Line: 96
// RVA: 0xA4DAE0
void __fastcall CAkAudioLibIndex::ReleaseDynamicSequences(CAkAudioLibIndex *this)
{
  _RTL_CRITICAL_SECTION *v1; // rbp
  _RTL_CRITICAL_SECTION_DEBUG *i; // rdi
  __int64 v3; // rbx
  unsigned int *v4; // rsi

  v1 = &this->m_idxDynamicSequences.m_IndexLock.m_csLock;
  EnterCriticalSection(&this->m_idxDynamicSequences.m_IndexLock.m_csLock);
  i = v1[1].DebugInfo;
  LODWORD(v3) = 0;
  if ( i )
    goto LABEL_13;
  while ( 1 )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= 0xC1 )
      break;
    i = (_RTL_CRITICAL_SECTION_DEBUG *)*((_QWORD *)&v1[1].DebugInfo + v3);
    if ( i )
      goto LABEL_6;
  }
  if ( i )
  {
LABEL_13:
    do
    {
LABEL_6:
      v4 = (unsigned int *)&i->Type;
      for ( i = (_RTL_CRITICAL_SECTION_DEBUG *)i->CriticalSection;
            !i;
            i = (_RTL_CRITICAL_SECTION_DEBUG *)*((_QWORD *)&v1[1].DebugInfo + v3) )
      {
        v3 = (unsigned int)(v3 + 1);
        if ( (unsigned int)v3 >= 0xC1 )
          break;
      }
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v4[30]);
      (*(void (__fastcall **)(unsigned int *))(*(_QWORD *)v4 + 16i64))(v4);
    }
    while ( i );
  }
  LeaveCriticalSection(v1);
}

// File Line: 112
// RVA: 0xA4D7F0
CAkIndexable *__fastcall CAkAudioLibIndex::GetNodePtrAndAddRef(CAkAudioLibIndex *this, unsigned int in_ID, AkNodeType in_NodeType)
{
  if ( in_NodeType )
    this = (CAkAudioLibIndex *)((char *)this + 1592);
  return CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef((CAkIndexItem<CAkFxShareSet *> *)this, in_ID);
}

// File Line: 125
// RVA: 0xA4D7D0
CAkIndexable *__fastcall CAkAudioLibIndex::GetNodePtrAndAddRef(CAkAudioLibIndex *this, WwiseObjectIDext *in_rIDext)
{
  bool v2; // zf
  unsigned int v3; // edx

  v2 = in_rIDext->bIsBus == 0;
  v3 = in_rIDext->id;
  if ( !v2 )
    this = (CAkAudioLibIndex *)((char *)this + 1592);
  return CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef((CAkIndexItem<CAkFxShareSet *> *)this, v3);
}

// File Line: 143
// RVA: 0xA4D7C0
CAkAudioLibIndex *__fastcall CAkAudioLibIndex::GetNodeLock(CAkAudioLibIndex *this, AkNodeType in_NodeType)
{
  CAkAudioLibIndex *result; // rax

  result = this;
  if ( in_NodeType )
    result = (CAkAudioLibIndex *)((char *)this + 1592);
  return result;
}

