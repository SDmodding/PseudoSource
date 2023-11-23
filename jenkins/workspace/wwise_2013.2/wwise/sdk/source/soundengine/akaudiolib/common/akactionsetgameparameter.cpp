// File Line: 37
// RVA: 0xA96740
CAkActionSetGameParameter *__fastcall CAkActionSetGameParameter::Create(
        AkActionType in_eActionType,
        unsigned int in_ulID)
{
  CAkActionSetGameParameter *result; // rax
  CAkActionSetGameParameter *v5; // rbx

  result = (CAkActionSetGameParameter *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
  v5 = result;
  if ( result )
  {
    CAkActionSetValue::CAkActionSetValue(result, in_eActionType, in_ulID);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionSetGameParameter::`vftable;
    *(_QWORD *)&v5->m_TargetValue.m_base = 0i64;
    v5->m_TargetValue.m_mod.m_max = 0.0;
    v5->m_eValueMeaning = AkValueMeaning_Offset;
    CAkAction::AddToIndex(v5);
    return v5;
  }
  return result;
}

// File Line: 63
// RVA: 0xA96850
void __fastcall CAkActionSetGameParameter::ExecSetValue(
        CAkActionSetGameParameter *this,
        CAkParameterNodeBase *__formal)
{
  int TransitionTime; // eax
  float m_max; // xmm6_4
  float v5; // xmm6_4
  float v6; // xmm2_4
  TransParams in_transParams; // [rsp+50h] [rbp+8h] BYREF

  TransitionTime = CAkAction::GetTransitionTime(this);
  m_max = this->m_TargetValue.m_mod.m_max;
  in_transParams.TransitionTime = TransitionTime;
  v5 = m_max - this->m_TargetValue.m_mod.m_min;
  v6 = 0.0;
  in_transParams.eFadeCurve = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  if ( v5 != 0.0 )
    v6 = (double)rand() * 0.00003051850947599719 * v5;
  CAkRTPCMgr::SetRTPCInternal(
    g_pRTPCMgr,
    this->m_ulElementID,
    (float)(v6 + this->m_TargetValue.m_mod.m_min) + this->m_TargetValue.m_base,
    0i64,
    &in_transParams,
    this->m_eValueMeaning);
}

// File Line: 70
// RVA: 0xA968E0
void __fastcall CAkActionSetGameParameter::ExecSetValue(
        CAkActionSetGameParameter *this,
        CAkParameterNodeBase *__formal,
        CAkRegisteredObj *in_pGameObj)
{
  float v5; // xmm2_4
  float v6; // xmm6_4
  TransParams in_transParams; // [rsp+50h] [rbp+8h] BYREF

  in_transParams.TransitionTime = CAkAction::GetTransitionTime(this);
  v5 = 0.0;
  v6 = this->m_TargetValue.m_mod.m_max - this->m_TargetValue.m_mod.m_min;
  in_transParams.eFadeCurve = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  if ( v6 != 0.0 )
    v5 = (double)rand() * 0.00003051850947599719 * v6;
  CAkRTPCMgr::SetRTPCInternal(
    g_pRTPCMgr,
    this->m_ulElementID,
    (float)(v5 + this->m_TargetValue.m_mod.m_min) + this->m_TargetValue.m_base,
    in_pGameObj,
    &in_transParams,
    this->m_eValueMeaning);
}

// File Line: 78
// RVA: 0xA967C0
void __fastcall CAkActionSetGameParameter::ExecResetValue(
        CAkActionSetGameParameter *this,
        CAkParameterNodeBase *__formal)
{
  int TransitionTime; // eax
  unsigned int m_ulElementID; // edx
  TransParams in_transParams; // [rsp+30h] [rbp+8h] BYREF

  TransitionTime = CAkAction::GetTransitionTime(this);
  m_ulElementID = this->m_ulElementID;
  in_transParams.TransitionTime = TransitionTime;
  in_transParams.eFadeCurve = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  CAkRTPCMgr::ResetRTPCValue(g_pRTPCMgr, m_ulElementID, 0i64, &in_transParams);
}

// File Line: 85
// RVA: 0xA96800
void __fastcall CAkActionSetGameParameter::ExecResetValue(
        CAkActionSetGameParameter *this,
        CAkParameterNodeBase *__formal,
        CAkRegisteredObj *in_pGameObj)
{
  int TransitionTime; // eax
  unsigned int m_ulElementID; // edx
  TransParams in_transParams; // [rsp+30h] [rbp+8h] BYREF

  TransitionTime = CAkAction::GetTransitionTime(this);
  m_ulElementID = this->m_ulElementID;
  in_transParams.TransitionTime = TransitionTime;
  in_transParams.eFadeCurve = *((_BYTE *)&this->CAkAction + 54) & 0x1F;
  CAkRTPCMgr::ResetRTPCValue(g_pRTPCMgr, m_ulElementID, in_pGameObj, &in_transParams);
}

// File Line: 108
// RVA: 0xA96730
void __fastcall CAkActionStop::ActionType(CAkActionUseState *this, AkActionType in_ActionType)
{
  this->m_eActionType = in_ActionType;
}

// File Line: 119
// RVA: 0xA96980
__int64 __fastcall CAkActionSetGameParameter::SetActionSpecificParams(
        CAkActionSetGameParameter *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  char *v3; // rax
  AkValueMeaning v4; // r8d
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  __int64 result; // rax

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

