// File Line: 35
// RVA: 0xA95FC0
void __fastcall CAkActionMute::ExecSetValue(CAkActionMute *this, CAkParameterNodeBase *in_pNode)
{
  CAkIndexableVtbl *vfptr; // rdi
  unsigned int v4; // ebx
  unsigned int TransitionTime; // eax

  vfptr = in_pNode->vfptr;
  v4 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  TransitionTime = CAkAction::GetTransitionTime(this);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, _QWORD))vfptr[12].__vecDelDtor)(
    in_pNode,
    0i64,
    v4,
    TransitionTime);
}

// File Line: 39
// RVA: 0xA96010
void __fastcall CAkActionMute::ExecSetValue(
        CAkActionMute *this,
        CAkParameterNodeBase *in_pNode,
        CAkRegisteredObj *in_pGameObj)
{
  CAkIndexableVtbl *vfptr; // rdi
  unsigned int v5; // ebx
  unsigned int TransitionTime; // eax

  vfptr = in_pNode->vfptr;
  v5 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  TransitionTime = CAkAction::GetTransitionTime(this);
  ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, _QWORD, _QWORD))vfptr[12].__vecDelDtor)(
    in_pNode,
    in_pGameObj,
    v5,
    TransitionTime);
}

// File Line: 44
// RVA: 0xA95DB0
void __fastcall CAkActionMute::ExecResetValue(CAkActionMute *this, CAkParameterNodeBase *in_pNode)
{
  CAkIndexableVtbl *vfptr; // rdi
  unsigned int v4; // ebx
  unsigned int TransitionTime; // eax

  vfptr = in_pNode->vfptr;
  v4 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  TransitionTime = CAkAction::GetTransitionTime(this);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, _QWORD))vfptr[12].AddRef)(
    in_pNode,
    0i64,
    v4,
    TransitionTime);
}

// File Line: 48
// RVA: 0xA95E00
void __fastcall CAkActionMute::ExecResetValue(
        CAkActionMute *this,
        CAkParameterNodeBase *in_pNode,
        CAkRegisteredObj *in_pGameObj)
{
  CAkIndexableVtbl *vfptr; // rdi
  unsigned int v5; // ebx
  unsigned int TransitionTime; // eax

  vfptr = in_pNode->vfptr;
  v5 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  TransitionTime = CAkAction::GetTransitionTime(this);
  ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, _QWORD, _QWORD))vfptr[12].AddRef)(
    in_pNode,
    in_pGameObj,
    v5,
    TransitionTime);
}

// File Line: 53
// RVA: 0xA95EB0
void __fastcall CAkActionMute::ExecResetValueExcept(CAkActionMute *this, CAkParameterNodeBase *in_pNode)
{
  WwiseObjectIDext *m_pItems; // rax
  WwiseObjectIDext *v4; // r9
  CAkIndexableVtbl *vfptr; // rbx
  unsigned int v6; // edi
  unsigned int TransitionTime; // eax

  m_pItems = this->m_listElementException.m_pItems;
  v4 = &m_pItems[this->m_listElementException.m_uLength];
  if ( m_pItems == v4 )
  {
LABEL_5:
    vfptr = in_pNode->vfptr;
    v6 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
    TransitionTime = CAkAction::GetTransitionTime(this);
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD))vfptr[12].Release)(in_pNode, v6, TransitionTime);
  }
  else
  {
    while ( in_pNode->key != m_pItems->id || ((*((_BYTE *)in_pNode + 83) & 2) != 0) != m_pItems->bIsBus )
    {
      if ( ++m_pItems == v4 )
        goto LABEL_5;
    }
  }
}

// File Line: 66
// RVA: 0xA95F30
void __fastcall CAkActionMute::ExecResetValueExcept(
        CAkActionMute *this,
        CAkParameterNodeBase *in_pNode,
        CAkRegisteredObj *in_pGameObj)
{
  WwiseObjectIDext *m_pItems; // rax
  WwiseObjectIDext *v5; // r10
  CAkIndexableVtbl *vfptr; // rdi
  unsigned int v8; // ebx
  unsigned int TransitionTime; // eax

  m_pItems = this->m_listElementException.m_pItems;
  v5 = &m_pItems[this->m_listElementException.m_uLength];
  if ( m_pItems == v5 )
  {
LABEL_5:
    vfptr = in_pNode->vfptr;
    v8 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
    TransitionTime = CAkAction::GetTransitionTime(this);
    ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, _QWORD, _QWORD))vfptr[12].AddRef)(
      in_pNode,
      in_pGameObj,
      v8,
      TransitionTime);
  }
  else
  {
    while ( in_pNode->key != m_pItems->id || ((*((_BYTE *)in_pNode + 83) & 2) != 0) != m_pItems->bIsBus )
    {
      if ( ++m_pItems == v5 )
        goto LABEL_5;
    }
  }
}

// File Line: 79
// RVA: 0xA95E60
void __fastcall CAkActionMute::ExecResetValueAll(CAkActionMute *this, CAkParameterNodeBase *in_pNode)
{
  CAkIndexableVtbl *vfptr; // rbx
  unsigned int v4; // edi
  unsigned int TransitionTime; // eax

  vfptr = in_pNode->vfptr;
  v4 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  TransitionTime = CAkAction::GetTransitionTime(this);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD))vfptr[12].Release)(in_pNode, v4, TransitionTime);
}

// File Line: 84
// RVA: 0xA95D40
CAkActionMute *__fastcall CAkActionMute::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionMute *result; // rax
  CAkActionMute *v5; // rbx

  result = (CAkActionMute *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64);
  v5 = result;
  if ( result )
  {
    CAkActionSetValue::CAkActionSetValue(result, in_eActionType, in_ulID);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionMute::`vftable;
    CAkAction::AddToIndex(v5);
    return v5;
  }
  return result;
}

