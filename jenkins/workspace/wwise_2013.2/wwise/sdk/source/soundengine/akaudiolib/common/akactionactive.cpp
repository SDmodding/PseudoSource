// File Line: 39
// RVA: 0xA97970
void __fastcall CAkActionActive::CAkActionActive(
        CAkActionActive *this,
        AkActionType in_eActionType,
        unsigned int in_ulID)
{
  CAkActionExcept::CAkActionExcept(this, in_eActionType, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkActionActive::`vftable;
  this->m_bIsMasterResume = 0;
}

// File Line: 43
// RVA: 0xA979A0
void __fastcall CAkActionActive::~CAkActionActive(CAkActionActive *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkActionActive::`vftable;
  CAkActionExcept::~CAkActionExcept(this);
}

// File Line: 47
// RVA: 0xA97CF0
__int64 __fastcall CAkActionSetValue::SetActionParams(
        CAkActionSetValue *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  char v5; // r9
  CAkIndexableVtbl *vfptr; // rax
  __int64 result; // rax

  v5 = *(*io_rpData)++;
  *((_BYTE *)&this->CAkAction + 54) &= 0xE0u;
  vfptr = this->vfptr;
  *((_BYTE *)&this->CAkAction + 54) |= v5 & 0x1F;
  result = ((__int64 (*)(void))vfptr[2].Release)();
  if ( (_DWORD)result == 1 )
    return CAkActionExcept::SetExceptParams(this, io_rpData, io_rulDataSize);
  return result;
}

// File Line: 61
// RVA: 0xA97C40
__int64 __fastcall CAkActionActive::Exec(
        CAkActionActive *this,
        ActionParamType in_eType,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_TargetPlayingID)
{
  CAkParameterNodeBase *v8; // rdi
  bool m_bIsMasterResume; // r10
  int v10; // r9d
  unsigned int v11; // ebx
  ActionParamType v13; // [rsp+20h] [rbp-38h] BYREF
  CAkRegisteredObj *v14; // [rsp+28h] [rbp-30h]
  unsigned int v15; // [rsp+30h] [rbp-28h]
  int TransitionTime; // [rsp+34h] [rbp-24h]
  int v17; // [rsp+38h] [rbp-20h]
  __int16 v18; // [rsp+3Ch] [rbp-1Ch]
  bool v19; // [rsp+3Eh] [rbp-1Ah]

  v8 = CAkAction::GetAndRefTarget(this);
  if ( !v8 )
    return 15i64;
  m_bIsMasterResume = this->m_bIsMasterResume;
  v10 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  v18 = 0;
  v13 = in_eType;
  v19 = m_bIsMasterResume;
  v14 = in_pGameObj;
  v15 = in_TargetPlayingID;
  v17 = v10;
  TransitionTime = CAkAction::GetTransitionTime(this);
  v11 = (unsigned int)v8->vfptr[4].__vecDelDtor(v8, (unsigned int)&v13);
  v8->vfptr->Release(v8);
  return v11;
}

// File Line: 88
// RVA: 0xA979F0
void __fastcall CAkActionActive::AllExec(
        CAkActionActive *this,
        ActionParamType in_eType,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_TargetPlayingID)
{
  CAkAudioLibIndex *v4; // r15
  CAkDynamicSequence *pNextItem; // rdi
  __int64 v10; // rbx
  char v11; // al
  CAkBus *PrimaryMasterBusAndAddRef; // rax
  CAkBus *v13; // rbx
  CAkBus *SecondaryMasterBusAndAddRef; // rax
  CAkBus *v15; // rbx
  CAkFeedbackBus *MasterMotionBusAndAddRef; // rax
  CAkFeedbackBus *v17; // rbx
  ActionParamType v18; // [rsp+20h] [rbp-48h] BYREF
  CAkRegisteredObj *v19; // [rsp+28h] [rbp-40h]
  unsigned int v20; // [rsp+30h] [rbp-38h]
  int TransitionTime; // [rsp+34h] [rbp-34h]
  int v22; // [rsp+38h] [rbp-30h]
  char v23; // [rsp+3Ch] [rbp-2Ch]
  bool v24; // [rsp+3Dh] [rbp-2Bh]
  bool m_bIsMasterResume; // [rsp+3Eh] [rbp-2Ah]

  v4 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxDynamicSequences.m_IndexLock.m_csLock);
  pNextItem = (CAkDynamicSequence *)v4->m_idxDynamicSequences.m_mapIDToPtr.m_table[0];
  LODWORD(v10) = 0;
  if ( pNextItem )
  {
    do
    {
LABEL_6:
      CAkDynamicSequence::AllExec(pNextItem, in_eType, in_pGameObj);
      pNextItem = (CAkDynamicSequence *)pNextItem->pNextItem;
    }
    while ( pNextItem );
    while ( 1 )
    {
      v10 = (unsigned int)(v10 + 1);
      if ( (unsigned int)v10 >= 0xC1 )
        break;
      pNextItem = (CAkDynamicSequence *)v4->m_idxDynamicSequences.m_mapIDToPtr.m_table[v10];
      if ( pNextItem )
        goto LABEL_6;
    }
  }
  else
  {
    while ( 1 )
    {
      v10 = (unsigned int)(v10 + 1);
      if ( (unsigned int)v10 >= 0xC1 )
        break;
      pNextItem = (CAkDynamicSequence *)v4->m_idxDynamicSequences.m_mapIDToPtr.m_table[v10];
      if ( pNextItem )
        goto LABEL_6;
    }
  }
  LeaveCriticalSection(&v4->m_idxDynamicSequences.m_IndexLock.m_csLock);
  m_bIsMasterResume = this->m_bIsMasterResume;
  v11 = *((_BYTE *)&this->CAkAction + 54);
  v23 = 0;
  v18 = in_eType;
  v19 = in_pGameObj;
  v22 = v11 & 0x1F;
  v20 = in_TargetPlayingID;
  TransitionTime = CAkAction::GetTransitionTime(this);
  v24 = in_pGameObj == 0i64;
  PrimaryMasterBusAndAddRef = CAkBus::GetPrimaryMasterBusAndAddRef();
  v13 = PrimaryMasterBusAndAddRef;
  if ( PrimaryMasterBusAndAddRef )
  {
    PrimaryMasterBusAndAddRef->vfptr[4].__vecDelDtor(PrimaryMasterBusAndAddRef, (unsigned int)&v18);
    v13->vfptr->Release(v13);
  }
  SecondaryMasterBusAndAddRef = CAkBus::GetSecondaryMasterBusAndAddRef();
  v15 = SecondaryMasterBusAndAddRef;
  if ( SecondaryMasterBusAndAddRef )
  {
    SecondaryMasterBusAndAddRef->vfptr[4].__vecDelDtor(SecondaryMasterBusAndAddRef, (unsigned int)&v18);
    v15->vfptr->Release(v15);
  }
  MasterMotionBusAndAddRef = CAkFeedbackBus::GetMasterMotionBusAndAddRef();
  v17 = MasterMotionBusAndAddRef;
  if ( MasterMotionBusAndAddRef )
  {
    MasterMotionBusAndAddRef->vfptr[4].__vecDelDtor(MasterMotionBusAndAddRef, (unsigned int)&v18);
    v17->vfptr->Release(v17);
  }
}

// File Line: 131
// RVA: 0xA97B80
void __fastcall CAkActionActive::AllExecExcept(
        CAkActionActive *this,
        ActionParamType in_eType,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_TargetPlayingID)
{
  bool m_bIsMasterResume; // al
  char v5; // al
  CAkBus *PrimaryMasterBusAndAddRef; // rax
  CAkBus *v7; // rbx
  CAkBus *SecondaryMasterBusAndAddRef; // rax
  CAkBus *v9; // rbx
  CAkFeedbackBus *MasterMotionBusAndAddRef; // rax
  CAkFeedbackBus *v11; // rbx
  ActionParamType v12; // [rsp+20h] [rbp-38h] BYREF
  AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *p_m_listElementException; // [rsp+28h] [rbp-30h]
  CAkRegisteredObj *v14; // [rsp+30h] [rbp-28h]
  unsigned int v15; // [rsp+38h] [rbp-20h]
  int TransitionTime; // [rsp+3Ch] [rbp-1Ch]
  int v17; // [rsp+40h] [rbp-18h]
  char v18; // [rsp+44h] [rbp-14h]
  bool v19; // [rsp+45h] [rbp-13h]

  m_bIsMasterResume = this->m_bIsMasterResume;
  v18 = 0;
  v12 = in_eType;
  v19 = m_bIsMasterResume;
  v5 = *((_BYTE *)&this->CAkAction + 54);
  v14 = in_pGameObj;
  v15 = in_TargetPlayingID;
  v17 = v5 & 0x1F;
  p_m_listElementException = &this->m_listElementException;
  TransitionTime = CAkAction::GetTransitionTime(this);
  PrimaryMasterBusAndAddRef = CAkBus::GetPrimaryMasterBusAndAddRef();
  v7 = PrimaryMasterBusAndAddRef;
  if ( PrimaryMasterBusAndAddRef )
  {
    ((void (__fastcall *)(CAkBus *, ActionParamType *))PrimaryMasterBusAndAddRef->vfptr[4].AddRef)(
      PrimaryMasterBusAndAddRef,
      &v12);
    v7->vfptr->Release(v7);
  }
  SecondaryMasterBusAndAddRef = CAkBus::GetSecondaryMasterBusAndAddRef();
  v9 = SecondaryMasterBusAndAddRef;
  if ( SecondaryMasterBusAndAddRef )
  {
    ((void (__fastcall *)(CAkBus *, ActionParamType *))SecondaryMasterBusAndAddRef->vfptr[4].AddRef)(
      SecondaryMasterBusAndAddRef,
      &v12);
    v9->vfptr->Release(v9);
  }
  MasterMotionBusAndAddRef = CAkFeedbackBus::GetMasterMotionBusAndAddRef();
  v11 = MasterMotionBusAndAddRef;
  if ( MasterMotionBusAndAddRef )
  {
    ((void (__fastcall *)(CAkFeedbackBus *, ActionParamType *))MasterMotionBusAndAddRef->vfptr[4].AddRef)(
      MasterMotionBusAndAddRef,
      &v12);
    v11->vfptr->Release(v11);
  }
}

