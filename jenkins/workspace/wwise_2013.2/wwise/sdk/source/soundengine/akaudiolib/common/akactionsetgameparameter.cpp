// File Line: 37
// RVA: 0xA96740
CAkActionSetGameParameter *__fastcall CAkActionSetGameParameter::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionSetGameParameter *result; // rax
  CAkActionSetGameParameter *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionSetGameParameter *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
  v5 = result;
  if ( result )
  {
    CAkActionSetValue::CAkActionSetValue((CAkActionSetValue *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionSetGameParameter::`vftable;
    *(_QWORD *)&v5->m_TargetValue.m_base = 0i64;
    v5->m_TargetValue.m_mod.m_max = 0.0;
    v5->m_eValueMeaning = 2;
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

// File Line: 63
// RVA: 0xA96850
void __fastcall CAkActionSetGameParameter::ExecSetValue(CAkActionSetGameParameter *this, CAkParameterNodeBase *__formal)
{
  CAkActionSetGameParameter *v2; // rbx
  int v3; // eax
  float v4; // xmm6_4
  float v5; // xmm6_4
  float v6; // xmm2_4
  TransParams in_transParams; // [rsp+50h] [rbp+8h]

  v2 = this;
  v3 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  v4 = v2->m_TargetValue.m_mod.m_max;
  in_transParams.TransitionTime = v3;
  v5 = v4 - v2->m_TargetValue.m_mod.m_min;
  v6 = 0.0;
  in_transParams.eFadeCurve = *((_BYTE *)&v2->0 + 54) & 0x1F;
  if ( v5 != 0.0 )
    v6 = (double)rand() * 0.00003051850947599719 * v5;
  CAkRTPCMgr::SetRTPCInternal(
    g_pRTPCMgr,
    v2->m_ulElementID,
    (float)(v6 + v2->m_TargetValue.m_mod.m_min) + v2->m_TargetValue.m_base,
    0i64,
    &in_transParams,
    v2->m_eValueMeaning);
}

// File Line: 70
// RVA: 0xA968E0
void __fastcall CAkActionSetGameParameter::ExecSetValue(CAkActionSetGameParameter *this, CAkParameterNodeBase *__formal, CAkRegisteredObj *in_pGameObj)
{
  CAkRegisteredObj *v3; // rdi
  CAkActionSetGameParameter *v4; // rbx
  float v5; // xmm2_4
  float v6; // xmm6_4
  TransParams in_transParams; // [rsp+50h] [rbp+8h]

  v3 = in_pGameObj;
  v4 = this;
  in_transParams.TransitionTime = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  v5 = 0.0;
  v6 = v4->m_TargetValue.m_mod.m_max - v4->m_TargetValue.m_mod.m_min;
  in_transParams.eFadeCurve = *((_BYTE *)&v4->0 + 54) & 0x1F;
  if ( v6 != 0.0 )
    v5 = (double)rand() * 0.00003051850947599719 * v6;
  CAkRTPCMgr::SetRTPCInternal(
    g_pRTPCMgr,
    v4->m_ulElementID,
    (float)(v5 + v4->m_TargetValue.m_mod.m_min) + v4->m_TargetValue.m_base,
    v3,
    &in_transParams,
    v4->m_eValueMeaning);
}

// File Line: 78
// RVA: 0xA967C0
void __fastcall CAkActionSetGameParameter::ExecResetValue(CAkActionSetGameParameter *this, CAkParameterNodeBase *__formal)
{
  CAkActionSetGameParameter *v2; // rbx
  int v3; // eax
  unsigned int v4; // edx
  TransParams in_transParams; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  v4 = v2->m_ulElementID;
  in_transParams.TransitionTime = v3;
  in_transParams.eFadeCurve = *((_BYTE *)&v2->0 + 54) & 0x1F;
  CAkRTPCMgr::ResetRTPCValue(g_pRTPCMgr, v4, 0i64, &in_transParams);
}

// File Line: 85
// RVA: 0xA96800
void __fastcall CAkActionSetGameParameter::ExecResetValue(CAkActionSetGameParameter *this, CAkParameterNodeBase *__formal, CAkRegisteredObj *in_pGameObj)
{
  CAkRegisteredObj *v3; // rdi
  CAkActionSetGameParameter *v4; // rbx
  int v5; // eax
  unsigned int v6; // edx
  TransParams in_transParams; // [rsp+30h] [rbp+8h]

  v3 = in_pGameObj;
  v4 = this;
  v5 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  v6 = v4->m_ulElementID;
  in_transParams.TransitionTime = v5;
  in_transParams.eFadeCurve = *((_BYTE *)&v4->0 + 54) & 0x1F;
  CAkRTPCMgr::ResetRTPCValue(g_pRTPCMgr, v6, v3, &in_transParams);
}

// File Line: 108
// RVA: 0xA96730
void __fastcall CAkActionStop::ActionType(CAkActionUseState *this, AkActionType in_ActionType)
{
  this->m_eActionType = in_ActionType;
}

// File Line: 119
// RVA: 0xA96980
signed __int64 __fastcall CAkActionSetGameParameter::SetActionSpecificParams(CAkActionSetGameParameter *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char *v3; // rax
  AkValueMeaning v4; // er8
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  signed __int64 result; // rax

  v3 = *io_rpData + 13;
  v4 = (unsigned __int8)**io_rpData;
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

