// File Line: 32
// RVA: 0xA4D810
void __fastcall CAkAudioLibIndex::Init(CAkAudioLibIndex *this)
{
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *p_m_mapIDToPtr; // rax
  __int64 v2; // rdx
  __int64 v4; // r8
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v5; // rax
  __int64 v6; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v7; // rax
  __int64 v8; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v9; // rax
  __int64 v10; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v11; // rax
  __int64 v12; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v13; // rax
  __int64 v14; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v15; // rax
  __int64 v16; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v17; // rax
  __int64 v18; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v19; // rax
  __int64 v20; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v21; // rax
  __int64 v22; // rcx
  AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *v23; // rax

  p_m_mapIDToPtr = &this->m_idxAudioNode.m_mapIDToPtr;
  v2 = 24i64;
  this->m_idxAudioNode.m_mapIDToPtr.m_uiSize = 0;
  v4 = 24i64;
  do
  {
    p_m_mapIDToPtr->m_table[0] = 0i64;
    p_m_mapIDToPtr->m_table[1] = 0i64;
    p_m_mapIDToPtr->m_table[2] = 0i64;
    p_m_mapIDToPtr = (AkHashListBare<unsigned long,CAkIndexable,193,AkDefaultHashListBarePolicy<unsigned long,CAkIndexable> > *)((char *)p_m_mapIDToPtr + 64);
    p_m_mapIDToPtr[-1].m_table[189] = 0i64;
    p_m_mapIDToPtr[-1].m_table[190] = 0i64;
    p_m_mapIDToPtr[-1].m_table[191] = 0i64;
    p_m_mapIDToPtr[-1].m_table[192] = 0i64;
    *(_QWORD *)&p_m_mapIDToPtr[-1].m_uiSize = 0i64;
    --v4;
  }
  while ( v4 );
  p_m_mapIDToPtr->m_table[0] = 0i64;
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
  v7 = &this->m_idxCustomStates.m_mapIDToPtr;
  v8 = 24i64;
  this->m_idxCustomStates.m_mapIDToPtr.m_uiSize = 0;
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
  v9 = &this->m_idxEvents.m_mapIDToPtr;
  v10 = 24i64;
  this->m_idxEvents.m_mapIDToPtr.m_uiSize = 0;
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
  v11 = &this->m_idxActions.m_mapIDToPtr;
  v12 = 24i64;
  this->m_idxActions.m_mapIDToPtr.m_uiSize = 0;
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
  v13 = &this->m_idxLayers.m_mapIDToPtr;
  v14 = 24i64;
  this->m_idxLayers.m_mapIDToPtr.m_uiSize = 0;
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
  v15 = &this->m_idxAttenuations.m_mapIDToPtr;
  v16 = 24i64;
  this->m_idxAttenuations.m_mapIDToPtr.m_uiSize = 0;
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
  v17 = &this->m_idxDynamicSequences.m_mapIDToPtr;
  v18 = 24i64;
  this->m_idxDynamicSequences.m_mapIDToPtr.m_uiSize = 0;
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
  v19 = &this->m_idxDialogueEvents.m_mapIDToPtr;
  v20 = 24i64;
  this->m_idxDialogueEvents.m_mapIDToPtr.m_uiSize = 0;
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
  v21 = &this->m_idxFxShareSets.m_mapIDToPtr;
  v22 = 24i64;
  this->m_idxFxShareSets.m_mapIDToPtr.m_uiSize = 0;
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
  v23 = &this->m_idxFxCustom.m_mapIDToPtr;
  this->m_idxFxCustom.m_mapIDToPtr.m_uiSize = 0;
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
}m_table[192] = 0i64;
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
  CAkIndexable *i; // rsi
  __int64 v3; // rbx
  __int64 v4; // rdi
  int *v5; // rcx
  CAkIndexable *j; // rdi
  int *v7; // rcx

  EnterCriticalSection(&this->m_idxAudioNode.m_IndexLock.m_csLock);
  i = this->m_idxAudioNode.m_mapIDToPtr.m_table[0];
  LODWORD(v3) = 0;
  LODWORD(v4) = 0;
  if ( i )
  {
    do
    {
LABEL_6:
      v5 = (int *)i;
      for ( i = i->pNextItem; !i; i = this->m_idxAudioNode.m_mapIDToPtr.m_table[v4] )
      {
        v4 = (unsigned int)(v4 + 1);
        if ( (unsigned int)v4 >= 0xC1 )
          break;
      }
      if ( v5[4] < 0 )
        (*(void (__fastcall **)(int *))(*(_QWORD *)v5 + 16i64))(v5);
    }
    while ( i );
  }
  else
  {
    while ( 1 )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= 0xC1 )
        break;
      i = this->m_idxAudioNode.m_mapIDToPtr.m_table[v4];
      if ( i )
        goto LABEL_6;
    }
  }
  LeaveCriticalSection(&this->m_idxAudioNode.m_IndexLock.m_csLock);
  j = this->m_idxFxCustom.m_mapIDToPtr.m_table[0];
  if ( j )
  {
    do
    {
LABEL_17:
      v7 = (int *)j;
      for ( j = j->pNextItem; !j; j = this->m_idxFxCustom.m_mapIDToPtr.m_table[v3] )
      {
        v3 = (unsigned int)(v3 + 1);
        if ( (unsigned int)v3 >= 0xC1 )
          break;
      }
      if ( v7[4] < 0 )
        (*(void (__fastcall **)(int *))(*(_QWORD *)v7 + 16i64))(v7);
    }
    while ( j );
  }
  else
  {
    while ( 1 )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (unsigned int)v3 >= 0xC1 )
        break;
      j = this->m_idxFxCustom.m_mapIDToPtr.m_table[v3];
      if ( j )
        goto LABEL_17;
    }
  }
}

// File Line: 96
// RVA: 0xA4DAE0
void __fastcall CAkAudioLibIndex::ReleaseDynamicSequences(CAkAudioLibIndex *this)
{
  CAkIndexItem<CAkDynamicSequence *> *p_m_idxDynamicSequences; // rbp
  CAkIndexable *i; // rdi
  __int64 v3; // rbx
  unsigned int *v4; // rsi

  p_m_idxDynamicSequences = &this->m_idxDynamicSequences;
  EnterCriticalSection(&this->m_idxDynamicSequences.m_IndexLock.m_csLock);
  i = p_m_idxDynamicSequences->m_mapIDToPtr.m_table[0];
  LODWORD(v3) = 0;
  if ( i )
  {
    do
    {
LABEL_6:
      v4 = (unsigned int *)i;
      for ( i = i->pNextItem; !i; i = p_m_idxDynamicSequences->m_mapIDToPtr.m_table[v3] )
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
  else
  {
    while ( 1 )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (unsigned int)v3 >= 0xC1 )
        break;
      i = p_m_idxDynamicSequences->m_mapIDToPtr.m_table[v3];
      if ( i )
        goto LABEL_6;
    }
  }
  LeaveCriticalSection(&p_m_idxDynamicSequences->m_IndexLock.m_csLock);
}

// File Line: 112
// RVA: 0xA4D7F0
CAkParameterNodeBase *__fastcall CAkAudioLibIndex::GetNodePtrAndAddRef(
        CAkAudioLibIndex *this,
        unsigned int in_ID,
        AkNodeType in_NodeType)
{
  if ( in_NodeType )
    this = (CAkAudioLibIndex *)((char *)this + 1592);
  return (CAkParameterNodeBase *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                   (CAkIndexItem<CAkFxShareSet *> *)this,
                                   in_ID);
}

// File Line: 125
// RVA: 0xA4D7D0
CAkParameterNodeBase *__fastcall CAkAudioLibIndex::GetNodePtrAndAddRef(
        CAkAudioLibIndex *this,
        WwiseObjectIDext *in_rIDext)
{
  bool v2; // zf
  unsigned int id; // edx

  v2 = !in_rIDext->bIsBus;
  id = in_rIDext->id;
  if ( !v2 )
    this = (CAkAudioLibIndex *)((char *)this + 1592);
  return (CAkParameterNodeBase *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                   (CAkIndexItem<CAkFxShareSet *> *)this,
                                   id);
}

// File Line: 143
// RVA: 0xA4D7C0
CAkAudioLibIndex *__fastcall CAkAudioLibIndex::GetNodeLock(CAkAudioLibIndex *this, AkNodeType in_NodeType)
{
  CAkAudioLibIndex *result; // rax

  result = this;
  if ( in_NodeType )
    return (CAkAudioLibIndex *)&this->m_idxBusses;
  return result;
}

