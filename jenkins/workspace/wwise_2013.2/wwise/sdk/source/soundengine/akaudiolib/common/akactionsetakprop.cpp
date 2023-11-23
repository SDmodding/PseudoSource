// File Line: 33
// RVA: 0xA962C0
void __fastcall CAkActionSetAkProp::ExecSetValue(CAkActionSetAkProp *this, CAkParameterNodeBase *in_pNode)
{
  float v2; // xmm6_4
  float v3; // xmm7_4
  unsigned int m_eValueMeaning; // esi
  CAkIndexableVtbl *vfptr; // rdi
  int v8; // ebx
  float v9; // xmm7_4
  int TransitionTime; // eax

  v2 = this->m_TargetValue.m_mod.m_max - this->m_TargetValue.m_mod.m_min;
  v3 = 0.0;
  if ( v2 != 0.0 )
    v3 = (double)rand() * 0.00003051850947599719 * v2;
  m_eValueMeaning = (unsigned __int8)this->m_eValueMeaning;
  vfptr = in_pNode->vfptr;
  v8 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  v9 = (float)(v3 + this->m_TargetValue.m_mod.m_min) + this->m_TargetValue.m_base;
  TransitionTime = CAkAction::GetTransitionTime(this);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, _QWORD, _DWORD, int, int))vfptr[11].Release)(
    in_pNode,
    (unsigned __int8)this->m_ePropID,
    0i64,
    m_eValueMeaning,
    LODWORD(v9),
    v8,
    TransitionTime);
}

// File Line: 38
// RVA: 0xA96390
void __fastcall CAkActionSetAkProp::ExecSetValue(
        CAkActionSetAkProp *this,
        CAkParameterNodeBase *in_pNode,
        CAkRegisteredObj *in_pGameObj)
{
  float v3; // xmm0_4
  float v4; // xmm6_4

  v3 = 0.0;
  v4 = this->m_TargetValue.m_mod.m_max - this->m_TargetValue.m_mod.m_min;
  if ( v4 != 0.0 )
    v3 = (double)rand() * 0.00003051850947599719 * v4;
  CAkActionSetAkProp::ExecSetValueInternal(
    this,
    in_pNode,
    in_pGameObj,
    (AkValueMeaning)(unsigned __int8)this->m_eValueMeaning,
    (float)(v3 + this->m_TargetValue.m_mod.m_min) + this->m_TargetValue.m_base);
}

// File Line: 43
// RVA: 0xA96130
void __fastcall CAkActionSetAkProp::ExecResetValue(CAkActionSetAkProp *this, CAkParameterNodeBase *in_pNode)
{
  CAkIndexableVtbl *vfptr; // rbx
  unsigned int v4; // edi
  unsigned int TransitionTime; // eax

  vfptr = in_pNode->vfptr;
  v4 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  TransitionTime = CAkAction::GetTransitionTime(this);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, _QWORD))vfptr[11].Category)(
    in_pNode,
    (unsigned __int8)this->m_ePropID,
    v4,
    TransitionTime);
}

// File Line: 48
// RVA: 0xA96190
void __fastcall CAkActionSetAkProp::ExecResetValue(
        CAkActionSetAkProp *this,
        CAkParameterNodeBase *in_pNode,
        CAkRegisteredObj *in_pGameObj)
{
  CAkIndexableVtbl *vfptr; // rsi
  int v7; // edi
  int TransitionTime; // eax

  vfptr = in_pNode->vfptr;
  v7 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  TransitionTime = CAkAction::GetTransitionTime(this);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkRegisteredObj *, _QWORD, _DWORD, int, int))vfptr[11].Release)(
    in_pNode,
    (unsigned __int8)this->m_ePropID,
    in_pGameObj,
    0i64,
    0,
    v7,
    TransitionTime);
}

// File Line: 53
// RVA: 0xA96210
__int64 __fastcall UFG::CameraSubject::GrapplePosition(CAkBus *this, ActionParamsExcept *in_rAction)
{
  return ((__int64 (__fastcall *)(CAkBus *, ActionParamsExcept *))this->vfptr[4].AddRef)(this, in_rAction);
}

// File Line: 58
// RVA: 0xA96220
void __fastcall CAkActionSetAkProp::ExecResetValueExcept(CAkActionSetAkProp *this, CAkParameterNodeBase *in_pNode)
{
  WwiseObjectIDext *m_pItems; // rax
  WwiseObjectIDext *v3; // r9

  m_pItems = this->m_listElementException.m_pItems;
  v3 = &m_pItems[this->m_listElementException.m_uLength];
  if ( m_pItems == v3 )
  {
LABEL_5:
    ((void (__fastcall *)(CAkActionSetAkProp *, CAkParameterNodeBase *))this->vfptr[4].AddRef)(this, in_pNode);
  }
  else
  {
    while ( in_pNode->key != m_pItems->id || ((*((_BYTE *)in_pNode + 83) & 2) != 0) != m_pItems->bIsBus )
    {
      if ( ++m_pItems == v3 )
        goto LABEL_5;
    }
  }
}

// File Line: 72
// RVA: 0xA96270
void __fastcall CAkActionSetAkProp::ExecResetValueExcept(
        CAkActionSetAkProp *this,
        CAkParameterNodeBase *in_pNode,
        CAkRegisteredObj *in_pGameObj)
{
  WwiseObjectIDext *m_pItems; // rax
  WwiseObjectIDext *v4; // r10

  m_pItems = this->m_listElementException.m_pItems;
  v4 = &m_pItems[this->m_listElementException.m_uLength];
  if ( m_pItems == v4 )
  {
LABEL_5:
    ((void (__fastcall *)(CAkActionSetAkProp *, CAkParameterNodeBase *, CAkRegisteredObj *))this->vfptr[4].__vecDelDtor)(
      this,
      in_pNode,
      in_pGameObj);
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

// File Line: 85
// RVA: 0xA96420
void __fastcall CAkActionSetAkProp::ExecSetValueInternal(
        CAkActionSetAkProp *this,
        CAkParameterNodeBase *in_pNode,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_eMeaning,
        float in_fValue)
{
  CAkIndexableVtbl *vfptr; // rsi
  int v10; // edi
  int TransitionTime; // eax

  vfptr = in_pNode->vfptr;
  v10 = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  TransitionTime = CAkAction::GetTransitionTime(this);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkRegisteredObj *, _QWORD, _DWORD, int, int))vfptr[11].Release)(
    in_pNode,
    (unsigned __int8)this->m_ePropID,
    in_pGameObj,
    in_eMeaning,
    LODWORD(in_fValue),
    v10,
    TransitionTime);
}

// File Line: 90
// RVA: 0xA960B0
CAkActionSetAkProp *__fastcall CAkActionSetAkProp::Create(
        AkActionType in_eActionType,
        unsigned int in_ulID,
        AkPropID in_ePropID)
{
  char v5; // di
  CAkActionSetAkProp *result; // rax
  CAkActionSetAkProp *v7; // rbx

  v5 = in_ePropID;
  result = (CAkActionSetAkProp *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
  v7 = result;
  if ( result )
  {
    CAkActionSetValue::CAkActionSetValue(result, in_eActionType, in_ulID);
    v7->vfptr = (CAkIndexableVtbl *)&CAkActionSetAkProp::`vftable;
    *(_QWORD *)&v7->m_TargetValue.m_base = 0i64;
    v7->m_TargetValue.m_mod.m_max = 0.0;
    v7->m_eValueMeaning = 2;
    v7->m_ePropID = v5;
    CAkAction::AddToIndex(v7);
    return v7;
  }
  return result;
}

// File Line: 111
// RVA: 0xA964A0
__int64 __fastcall CAkActionSetAkProp::SetActionSpecificParams(
        CAkActionSetAkProp *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  char *v3; // rax
  char v4; // r8
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  __int64 result; // rax

  v3 = *io_rpData + 13;
  v4 = **io_rpData;
  *io_rpData = v3;
  v5 = *((float *)v3 - 3);
  v6 = *((float *)v3 - 2);
  v7 = *((float *)v3 - 1);
  result = 1i64;
  this->m_TargetValue.m_base = v5;
  this->m_TargetValue.m_mod.m_min = v6;
  this->m_TargetValue.m_mod.m_max = v7;
  this->m_eValueMeaning = v4;
  return result;
}

