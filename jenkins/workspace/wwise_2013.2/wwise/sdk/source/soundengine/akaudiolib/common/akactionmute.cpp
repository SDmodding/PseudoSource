// File Line: 35
// RVA: 0xA95FC0
void __fastcall CAkActionMute::ExecSetValue(CAkActionMute *this, CAkParameterNodeBase *in_pNode)
{
  CAkIndexableVtbl *v2; // rdi
  CAkParameterNodeBase *v3; // rsi
  unsigned int v4; // ebx
  unsigned int v5; // eax

  v2 = in_pNode->vfptr;
  v3 = in_pNode;
  v4 = *((_BYTE *)&this->0 + 54) & 0x1F;
  v5 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, _QWORD))v2[12].__vecDelDtor)(v3, 0i64, v4, v5);
}

// File Line: 39
// RVA: 0xA96010
void __fastcall CAkActionMute::ExecSetValue(CAkActionMute *this, CAkParameterNodeBase *in_pNode, CAkRegisteredObj *in_pGameObj)
{
  CAkIndexableVtbl *v3; // rdi
  CAkRegisteredObj *v4; // rsi
  unsigned int v5; // ebx
  CAkParameterNodeBase *v6; // r14
  unsigned int v7; // eax

  v3 = in_pNode->vfptr;
  v4 = in_pGameObj;
  v5 = *((_BYTE *)&this->0 + 54) & 0x1F;
  v6 = in_pNode;
  v7 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, _QWORD, _QWORD))v3[12].__vecDelDtor)(v6, v4, v5, v7);
}

// File Line: 44
// RVA: 0xA95DB0
void __fastcall CAkActionMute::ExecResetValue(CAkActionMute *this, CAkParameterNodeBase *in_pNode)
{
  CAkIndexableVtbl *v2; // rdi
  CAkParameterNodeBase *v3; // rsi
  unsigned int v4; // ebx
  unsigned int v5; // eax

  v2 = in_pNode->vfptr;
  v3 = in_pNode;
  v4 = *((_BYTE *)&this->0 + 54) & 0x1F;
  v5 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, _QWORD))v2[12].AddRef)(v3, 0i64, v4, v5);
}

// File Line: 48
// RVA: 0xA95E00
void __fastcall CAkActionMute::ExecResetValue(CAkActionMute *this, CAkParameterNodeBase *in_pNode, CAkRegisteredObj *in_pGameObj)
{
  CAkIndexableVtbl *v3; // rdi
  CAkRegisteredObj *v4; // rsi
  unsigned int v5; // ebx
  CAkParameterNodeBase *v6; // r14
  unsigned int v7; // eax

  v3 = in_pNode->vfptr;
  v4 = in_pGameObj;
  v5 = *((_BYTE *)&this->0 + 54) & 0x1F;
  v6 = in_pNode;
  v7 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, _QWORD, _QWORD))v3[12].AddRef)(v6, v4, v5, v7);
}

// File Line: 53
// RVA: 0xA95EB0
void __fastcall CAkActionMute::ExecResetValueExcept(CAkActionMute *this, CAkParameterNodeBase *in_pNode)
{
  WwiseObjectIDext *v2; // rax
  CAkParameterNodeBase *v3; // rsi
  signed __int64 v4; // r9
  CAkIndexableVtbl *v5; // rbx
  unsigned int v6; // edi
  unsigned int v7; // eax

  v2 = this->m_listElementException.m_pItems;
  v3 = in_pNode;
  v4 = (signed __int64)&v2[this->m_listElementException.m_uLength];
  if ( v2 == (WwiseObjectIDext *)v4 )
  {
LABEL_5:
    v5 = in_pNode->vfptr;
    v6 = *((_BYTE *)&this->0 + 54) & 0x1F;
    v7 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD))v5[12].Release)(v3, v6, v7);
  }
  else
  {
    while ( in_pNode->key != v2->id || ((*((_BYTE *)in_pNode + 83) >> 1) & 1) != v2->bIsBus )
    {
      ++v2;
      if ( v2 == (WwiseObjectIDext *)v4 )
        goto LABEL_5;
    }
  }
}

// File Line: 66
// RVA: 0xA95F30
void __fastcall CAkActionMute::ExecResetValueExcept(CAkActionMute *this, CAkParameterNodeBase *in_pNode, CAkRegisteredObj *in_pGameObj)
{
  WwiseObjectIDext *v3; // rax
  CAkRegisteredObj *v4; // rbp
  signed __int64 v5; // r10
  CAkParameterNodeBase *v6; // rsi
  CAkIndexableVtbl *v7; // rdi
  unsigned int v8; // ebx
  unsigned int v9; // eax

  v3 = this->m_listElementException.m_pItems;
  v4 = in_pGameObj;
  v5 = (signed __int64)&v3[this->m_listElementException.m_uLength];
  v6 = in_pNode;
  if ( v3 == (WwiseObjectIDext *)v5 )
  {
LABEL_5:
    v7 = in_pNode->vfptr;
    v8 = *((_BYTE *)&this->0 + 54) & 0x1F;
    v9 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
    ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, _QWORD, _QWORD))v7[12].AddRef)(v6, v4, v8, v9);
  }
  else
  {
    while ( in_pNode->key != v3->id || ((*((_BYTE *)in_pNode + 83) >> 1) & 1) != v3->bIsBus )
    {
      ++v3;
      if ( v3 == (WwiseObjectIDext *)v5 )
        goto LABEL_5;
    }
  }
}

// File Line: 79
// RVA: 0xA95E60
void __fastcall CAkActionMute::ExecResetValueAll(CAkActionMute *this, CAkParameterNodeBase *in_pNode)
{
  CAkIndexableVtbl *v2; // rbx
  CAkParameterNodeBase *v3; // rsi
  unsigned int v4; // edi
  unsigned int v5; // eax

  v2 = in_pNode->vfptr;
  v3 = in_pNode;
  v4 = *((_BYTE *)&this->0 + 54) & 0x1F;
  v5 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD))v2[12].Release)(v3, v4, v5);
}

// File Line: 84
// RVA: 0xA95D40
CAkActionMute *__fastcall CAkActionMute::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionMute *result; // rax
  CAkActionMute *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionMute *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64);
  v5 = result;
  if ( result )
  {
    CAkActionSetValue::CAkActionSetValue((CAkActionSetValue *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionMute::`vftable;
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

