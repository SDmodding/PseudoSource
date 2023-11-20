// File Line: 39
// RVA: 0xA97970
void __fastcall CAkActionActive::CAkActionActive(CAkActionActive *this, AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionActive *v3; // rbx

  v3 = this;
  CAkActionExcept::CAkActionExcept((CAkActionExcept *)&this->vfptr, in_eActionType, in_ulID);
  v3->vfptr = (CAkIndexableVtbl *)&CAkActionActive::`vftable';
  v3->m_bIsMasterResume = 0;
}

// File Line: 43
// RVA: 0xA979A0
void __fastcall CAkActionActive::~CAkActionActive(CAkActionActive *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkActionActive::`vftable';
  CAkActionExcept::~CAkActionExcept((CAkActionExcept *)&this->vfptr);
}

// File Line: 47
// RVA: 0xA97CF0
signed __int64 __fastcall CAkActionSetValue::SetActionParams(CAkActionSetValue *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  unsigned int *v3; // rsi
  char **v4; // rdi
  char v5; // r9
  CAkActionSetValue *v6; // rbx
  CAkIndexableVtbl *v7; // rax
  signed __int64 result; // rax

  v3 = io_rulDataSize;
  v4 = io_rpData;
  v5 = **io_rpData;
  v6 = this;
  ++*io_rpData;
  *((_BYTE *)&this->0 + 54) &= 0xE0u;
  v7 = this->vfptr;
  *((_BYTE *)&this->0 + 54) |= v5 & 0x1F;
  result = ((__int64 (*)(void))v7[2].Release)();
  if ( (_DWORD)result == 1 )
    result = CAkActionExcept::SetExceptParams((CAkActionExcept *)&v6->vfptr, v4, v3);
  return result;
}

// File Line: 61
// RVA: 0xA97C40
signed __int64 __fastcall CAkActionActive::Exec(CAkActionActive *this, ActionParamType in_eType, CAkRegisteredObj *in_pGameObj, unsigned int in_TargetPlayingID)
{
  unsigned int v4; // esi
  CAkRegisteredObj *v5; // rbp
  ActionParamType v6; // er14
  CAkActionActive *v7; // rbx
  CAkIndexable *v8; // rdi
  char v9; // r10
  int v10; // er9
  unsigned int v11; // ebx
  ActionParamType v13; // [rsp+20h] [rbp-38h]
  CAkRegisteredObj *v14; // [rsp+28h] [rbp-30h]
  unsigned int v15; // [rsp+30h] [rbp-28h]
  int v16; // [rsp+34h] [rbp-24h]
  int v17; // [rsp+38h] [rbp-20h]
  __int16 v18; // [rsp+3Ch] [rbp-1Ch]
  char v19; // [rsp+3Eh] [rbp-1Ah]

  v4 = in_TargetPlayingID;
  v5 = in_pGameObj;
  v6 = in_eType;
  v7 = this;
  v8 = CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
  if ( !v8 )
    return 15i64;
  v9 = v7->m_bIsMasterResume;
  v10 = *((_BYTE *)&v7->0 + 54) & 0x1F;
  v18 = 0;
  v13 = v6;
  v19 = v9;
  v14 = v5;
  v15 = v4;
  v17 = v10;
  v16 = CAkAction::GetTransitionTime((CAkAction *)&v7->vfptr);
  v11 = (__int64)v8->vfptr[4].__vecDelDtor(v8, (unsigned int)&v13);
  v8->vfptr->Release(v8);
  return v11;
}

// File Line: 88
// RVA: 0xA979F0
void __fastcall CAkActionActive::AllExec(CAkActionActive *this, ActionParamType in_eType, CAkRegisteredObj *in_pGameObj, unsigned int in_TargetPlayingID)
{
  CAkAudioLibIndex *v4; // r15
  CAkActionActive *v5; // r14
  unsigned int v6; // er12
  CAkRegisteredObj *v7; // rsi
  ActionParamType v8; // ebp
  CAkDynamicSequence *v9; // rdi
  __int64 v10; // rbx
  char v11; // al
  CAkBus *v12; // rax
  CAkBus *v13; // rbx
  CAkBus *v14; // rax
  CAkBus *v15; // rbx
  CAkFeedbackBus *v16; // rax
  CAkFeedbackBus *v17; // rbx
  ActionParamType v18; // [rsp+20h] [rbp-48h]
  CAkRegisteredObj *v19; // [rsp+28h] [rbp-40h]
  unsigned int v20; // [rsp+30h] [rbp-38h]
  int v21; // [rsp+34h] [rbp-34h]
  int v22; // [rsp+38h] [rbp-30h]
  char v23; // [rsp+3Ch] [rbp-2Ch]
  bool v24; // [rsp+3Dh] [rbp-2Bh]
  bool v25; // [rsp+3Eh] [rbp-2Ah]

  v4 = g_pIndex;
  v5 = this;
  v6 = in_TargetPlayingID;
  v7 = in_pGameObj;
  v8 = in_eType;
  EnterCriticalSection(&g_pIndex->m_idxDynamicSequences.m_IndexLock.m_csLock);
  v9 = (CAkDynamicSequence *)v4->m_idxDynamicSequences.m_mapIDToPtr.m_table[0];
  LODWORD(v10) = 0;
  if ( v9 )
    goto LABEL_19;
  while ( 1 )
  {
    v10 = (unsigned int)(v10 + 1);
    if ( (unsigned int)v10 >= 0xC1 )
      break;
    v9 = (CAkDynamicSequence *)v4->m_idxDynamicSequences.m_mapIDToPtr.m_table[v10];
    if ( v9 )
      goto LABEL_6;
  }
  if ( v9 )
  {
LABEL_19:
    do
    {
      do
      {
LABEL_6:
        CAkDynamicSequence::AllExec(v9, v8, v7);
        v9 = (CAkDynamicSequence *)v9->pNextItem;
      }
      while ( v9 );
      while ( 1 )
      {
        v10 = (unsigned int)(v10 + 1);
        if ( (unsigned int)v10 >= 0xC1 )
          break;
        v9 = (CAkDynamicSequence *)v4->m_idxDynamicSequences.m_mapIDToPtr.m_table[v10];
        if ( v9 )
          goto LABEL_6;
      }
    }
    while ( v9 );
  }
  LeaveCriticalSection(&v4->m_idxDynamicSequences.m_IndexLock.m_csLock);
  v25 = v5->m_bIsMasterResume;
  v11 = *((_BYTE *)&v5->0 + 54);
  v23 = 0;
  v18 = v8;
  v19 = v7;
  v22 = v11 & 0x1F;
  v20 = v6;
  v21 = CAkAction::GetTransitionTime((CAkAction *)&v5->vfptr);
  v24 = v7 == 0i64;
  v12 = CAkBus::GetPrimaryMasterBusAndAddRef();
  v13 = v12;
  if ( v12 )
  {
    v12->vfptr[4].__vecDelDtor((CAkIndexable *)&v12->vfptr, (unsigned int)&v18);
    v13->vfptr->Release((CAkIndexable *)&v13->vfptr);
  }
  v14 = CAkBus::GetSecondaryMasterBusAndAddRef();
  v15 = v14;
  if ( v14 )
  {
    v14->vfptr[4].__vecDelDtor((CAkIndexable *)&v14->vfptr, (unsigned int)&v18);
    v15->vfptr->Release((CAkIndexable *)&v15->vfptr);
  }
  v16 = CAkFeedbackBus::GetMasterMotionBusAndAddRef();
  v17 = v16;
  if ( v16 )
  {
    v16->vfptr[4].__vecDelDtor((CAkIndexable *)&v16->vfptr, (unsigned int)&v18);
    v17->vfptr->Release((CAkIndexable *)&v17->vfptr);
  }
}

// File Line: 131
// RVA: 0xA97B80
void __fastcall CAkActionActive::AllExecExcept(CAkActionActive *this, ActionParamType in_eType, CAkRegisteredObj *in_pGameObj, unsigned int in_TargetPlayingID)
{
  bool v4; // al
  char v5; // al
  CAkBus *v6; // rax
  CAkBus *v7; // rbx
  CAkBus *v8; // rax
  CAkBus *v9; // rbx
  CAkFeedbackBus *v10; // rax
  CAkFeedbackBus *v11; // rbx
  ActionParamType v12; // [rsp+20h] [rbp-38h]
  AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v13; // [rsp+28h] [rbp-30h]
  CAkRegisteredObj *v14; // [rsp+30h] [rbp-28h]
  unsigned int v15; // [rsp+38h] [rbp-20h]
  int v16; // [rsp+3Ch] [rbp-1Ch]
  int v17; // [rsp+40h] [rbp-18h]
  char v18; // [rsp+44h] [rbp-14h]
  bool v19; // [rsp+45h] [rbp-13h]

  v4 = this->m_bIsMasterResume;
  v18 = 0;
  v12 = in_eType;
  v19 = v4;
  v5 = *((_BYTE *)&this->0 + 54);
  v14 = in_pGameObj;
  v15 = in_TargetPlayingID;
  v17 = v5 & 0x1F;
  v13 = &this->m_listElementException;
  v16 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  v6 = CAkBus::GetPrimaryMasterBusAndAddRef();
  v7 = v6;
  if ( v6 )
  {
    ((void (__fastcall *)(CAkBus *, ActionParamType *))v6->vfptr[4].AddRef)(v6, &v12);
    v7->vfptr->Release((CAkIndexable *)&v7->vfptr);
  }
  v8 = CAkBus::GetSecondaryMasterBusAndAddRef();
  v9 = v8;
  if ( v8 )
  {
    ((void (__fastcall *)(CAkBus *, ActionParamType *))v8->vfptr[4].AddRef)(v8, &v12);
    v9->vfptr->Release((CAkIndexable *)&v9->vfptr);
  }
  v10 = CAkFeedbackBus::GetMasterMotionBusAndAddRef();
  v11 = v10;
  if ( v10 )
  {
    ((void (__fastcall *)(CAkFeedbackBus *, ActionParamType *))v10->vfptr[4].AddRef)(v10, &v12);
    v11->vfptr->Release((CAkIndexable *)&v11->vfptr);
  }
}

