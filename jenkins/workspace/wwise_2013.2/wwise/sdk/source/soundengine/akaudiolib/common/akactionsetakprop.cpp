// File Line: 33
// RVA: 0xA962C0
void __fastcall CAkActionSetAkProp::ExecSetValue(CAkActionSetAkProp *this, CAkParameterNodeBase *in_pNode)
{
  float v2; // xmm6_4
  float v3; // xmm7_4
  CAkParameterNodeBase *v4; // r14
  CAkActionSetAkProp *v5; // rbp
  unsigned int v6; // esi
  CAkIndexableVtbl *v7; // rdi
  int v8; // ebx
  float v9; // xmm7_4
  int v10; // ST30_4
  int v11; // ST28_4
  float v12; // ST20_4

  v2 = this->m_TargetValue.m_mod.m_max - this->m_TargetValue.m_mod.m_min;
  v3 = 0.0;
  v4 = in_pNode;
  v5 = this;
  if ( v2 != 0.0 )
    v3 = (double)rand() * 0.00003051850947599719 * v2;
  v6 = (unsigned __int8)v5->m_eValueMeaning;
  v7 = v4->vfptr;
  v8 = *((_BYTE *)&v5->0 + 54) & 0x1F;
  v9 = (float)(v3 + v5->m_TargetValue.m_mod.m_min) + v5->m_TargetValue.m_base;
  v10 = CAkAction::GetTransitionTime((CAkAction *)&v5->vfptr);
  v11 = v8;
  v12 = v9;
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, _QWORD, float, int, int))v7[11].Release)(
    v4,
    (unsigned __int8)v5->m_ePropID,
    0i64,
    v6,
    COERCE_FLOAT(LODWORD(v12)),
    v11,
    v10);
}

// File Line: 38
// RVA: 0xA96390
void __fastcall CAkActionSetAkProp::ExecSetValue(CAkActionSetAkProp *this, CAkParameterNodeBase *in_pNode, CAkRegisteredObj *in_pGameObj)
{
  float v3; // xmm0_4
  float v4; // xmm6_4
  CAkRegisteredObj *v5; // rdi
  CAkParameterNodeBase *v6; // rsi
  CAkActionSetAkProp *v7; // rbx

  v3 = 0.0;
  v4 = this->m_TargetValue.m_mod.m_max - this->m_TargetValue.m_mod.m_min;
  v5 = in_pGameObj;
  v6 = in_pNode;
  v7 = this;
  if ( v4 != 0.0 )
    v3 = (double)rand() * 0.00003051850947599719 * v4;
  CAkActionSetAkProp::ExecSetValueInternal(
    v7,
    v6,
    v5,
    (AkValueMeaning)(unsigned __int8)v7->m_eValueMeaning,
    (float)(v3 + v7->m_TargetValue.m_mod.m_min) + v7->m_TargetValue.m_base);
}

// File Line: 43
// RVA: 0xA96130
void __fastcall CAkActionSetAkProp::ExecResetValue(CAkActionSetAkProp *this, CAkParameterNodeBase *in_pNode)
{
  CAkIndexableVtbl *v2; // rbx
  CAkParameterNodeBase *v3; // r14
  unsigned int v4; // edi
  CAkActionSetAkProp *v5; // rsi
  unsigned int v6; // eax

  v2 = in_pNode->vfptr;
  v3 = in_pNode;
  v4 = *((_BYTE *)&this->0 + 54) & 0x1F;
  v5 = this;
  v6 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, _QWORD))v2[11].Category)(
    v3,
    (unsigned __int8)v5->m_ePropID,
    v4,
    v6);
}

// File Line: 48
// RVA: 0xA96190
void __fastcall CAkActionSetAkProp::ExecResetValue(CAkActionSetAkProp *this, CAkParameterNodeBase *in_pNode, CAkRegisteredObj *in_pGameObj)
{
  CAkIndexableVtbl *v3; // rsi
  CAkRegisteredObj *v4; // rbp
  CAkParameterNodeBase *v5; // r14
  CAkActionSetAkProp *v6; // rbx
  int v7; // edi
  int v8; // ST30_4
  int v9; // ST28_4
  int v10; // ST20_4

  v3 = in_pNode->vfptr;
  v4 = in_pGameObj;
  v5 = in_pNode;
  v6 = this;
  v7 = *((_BYTE *)&this->0 + 54) & 0x1F;
  v8 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  v9 = v7;
  v10 = 0;
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkRegisteredObj *, _QWORD, int, int, int))v3[11].Release)(
    v5,
    (unsigned __int8)v6->m_ePropID,
    v4,
    0i64,
    v10,
    v9,
    v8);
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
  WwiseObjectIDext *v2; // rax
  signed __int64 v3; // r9

  v2 = this->m_listElementException.m_pItems;
  v3 = (signed __int64)&v2[this->m_listElementException.m_uLength];
  if ( v2 == (WwiseObjectIDext *)v3 )
  {
LABEL_5:
    ((void (__fastcall *)(CAkActionSetAkProp *, CAkParameterNodeBase *))this->vfptr[4].AddRef)(this, in_pNode);
  }
  else
  {
    while ( in_pNode->key != v2->id || ((*((_BYTE *)in_pNode + 83) >> 1) & 1) != v2->bIsBus )
    {
      ++v2;
      if ( v2 == (WwiseObjectIDext *)v3 )
        goto LABEL_5;
    }
  }
}

// File Line: 72
// RVA: 0xA96270
void __fastcall CAkActionSetAkProp::ExecResetValueExcept(CAkActionSetAkProp *this, CAkParameterNodeBase *in_pNode, CAkRegisteredObj *in_pGameObj)
{
  WwiseObjectIDext *v3; // rax
  signed __int64 v4; // r10

  v3 = this->m_listElementException.m_pItems;
  v4 = (signed __int64)&v3[this->m_listElementException.m_uLength];
  if ( v3 == (WwiseObjectIDext *)v4 )
  {
LABEL_5:
    ((void (__fastcall *)(CAkActionSetAkProp *, CAkParameterNodeBase *, CAkRegisteredObj *))this->vfptr[4].__vecDelDtor)(
      this,
      in_pNode,
      in_pGameObj);
  }
  else
  {
    while ( in_pNode->key != v3->id || ((*((_BYTE *)in_pNode + 83) >> 1) & 1) != v3->bIsBus )
    {
      ++v3;
      if ( v3 == (WwiseObjectIDext *)v4 )
        goto LABEL_5;
    }
  }
}

// File Line: 85
// RVA: 0xA96420
void __fastcall CAkActionSetAkProp::ExecSetValueInternal(CAkActionSetAkProp *this, CAkParameterNodeBase *in_pNode, CAkRegisteredObj *in_pGameObj, AkValueMeaning in_eMeaning, float in_fValue)
{
  CAkIndexableVtbl *v5; // rsi
  AkValueMeaning v6; // ebp
  CAkRegisteredObj *v7; // r14
  CAkParameterNodeBase *v8; // r15
  CAkActionSetAkProp *v9; // rbx
  int v10; // edi
  int v11; // ST30_4
  int v12; // ST28_4
  float v13; // ST20_4

  v5 = in_pNode->vfptr;
  v6 = in_eMeaning;
  v7 = in_pGameObj;
  v8 = in_pNode;
  v9 = this;
  v10 = *((_BYTE *)&this->0 + 54) & 0x1F;
  v11 = CAkAction::GetTransitionTime((CAkAction *)&this->vfptr);
  v12 = v10;
  v13 = in_fValue;
  ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkRegisteredObj *, _QWORD, float, int, int))v5[11].Release)(
    v8,
    (unsigned __int8)v9->m_ePropID,
    v7,
    (unsigned int)v6,
    COERCE_FLOAT(LODWORD(v13)),
    v12,
    v11);
}

// File Line: 90
// RVA: 0xA960B0
CAkActionSetAkProp *__fastcall CAkActionSetAkProp::Create(AkActionType in_eActionType, unsigned int in_ulID, AkPropID in_ePropID)
{
  AkActionType v3; // ebp
  unsigned int v4; // esi
  char v5; // di
  CAkActionSetAkProp *result; // rax
  CAkActionSetAkProp *v7; // rbx

  v3 = in_eActionType;
  v4 = in_ulID;
  v5 = in_ePropID;
  result = (CAkActionSetAkProp *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
  v7 = result;
  if ( result )
  {
    CAkActionSetValue::CAkActionSetValue((CAkActionSetValue *)&result->vfptr, v3, v4);
    v7->vfptr = (CAkIndexableVtbl *)&CAkActionSetAkProp::`vftable';
    *(_QWORD *)&v7->m_TargetValue.m_base = 0i64;
    v7->m_TargetValue.m_mod.m_max = 0.0;
    v7->m_eValueMeaning = 2;
    v7->m_ePropID = v5;
    CAkAction::AddToIndex((CAkAction *)&v7->vfptr);
    result = v7;
  }
  return result;
}

// File Line: 111
// RVA: 0xA964A0
signed __int64 __fastcall CAkActionSetAkProp::SetActionSpecificParams(CAkActionSetAkProp *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char *v3; // rax
  char v4; // r8
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  signed __int64 result; // rax

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

