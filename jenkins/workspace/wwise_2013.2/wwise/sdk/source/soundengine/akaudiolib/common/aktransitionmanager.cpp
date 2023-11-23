// File Line: 31
// RVA: 0xA59330
void __fastcall CAkTransitionManager::CAkTransitionManager(CAkTransitionManager *this)
{
  this->m_ActiveTransitionsList_Fade.m_pItems = 0i64;
  *(_QWORD *)&this->m_ActiveTransitionsList_Fade.m_uLength = 0i64;
  this->m_ActiveTransitionsList_State.m_pItems = 0i64;
  *(_QWORD *)&this->m_ActiveTransitionsList_State.m_uLength = 0i64;
  this->m_uMaxNumTransitions = 0;
}

// File Line: 42
// RVA: 0xA59840
__int64 __fastcall CAkTransitionManager::Init(CAkTransitionManager *this, unsigned int in_uMaxNumTransitions)
{
  unsigned int v2; // edi
  CAkTransition **v4; // rax
  unsigned int m_uMaxNumTransitions; // edi
  CAkTransition **v6; // rax

  v2 = 255;
  if ( in_uMaxNumTransitions )
    v2 = in_uMaxNumTransitions;
  this->m_uMaxNumTransitions = v2;
  v4 = (CAkTransition **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v2);
  this->m_ActiveTransitionsList_Fade.m_pItems = v4;
  if ( !v4 )
    return 52i64;
  this->m_ActiveTransitionsList_Fade.m_ulReserved = v2;
  m_uMaxNumTransitions = this->m_uMaxNumTransitions;
  if ( this->m_uMaxNumTransitions )
  {
    v6 = (CAkTransition **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * m_uMaxNumTransitions);
    this->m_ActiveTransitionsList_State.m_pItems = v6;
    if ( !v6 )
      return 52i64;
    this->m_ActiveTransitionsList_State.m_ulReserved = m_uMaxNumTransitions;
  }
  return 1i64;
}

// File Line: 54
// RVA: 0xA59AC0
void __fastcall CAkTransitionManager::Term(CAkTransitionManager *this)
{
  CAkTransitionManager::TermList(this, &this->m_ActiveTransitionsList_Fade);
  CAkTransitionManager::TermList(this, &this->m_ActiveTransitionsList_State);
}

// File Line: 61
// RVA: 0xA59AF0
void __fastcall CAkTransitionManager::TermList(
        CAkTransitionManager *this,
        AkArray<CAkTransition *,CAkTransition *,ArrayPoolDefault,0,AkArrayAllocatorDefault> *in_rTransitionList)
{
  __int64 m_uLength; // rax
  CAkTransition **m_pItems; // rbx
  CAkTransition *v5; // rbp
  int v6; // esi
  CAkTransition **v7; // rdx

  m_uLength = in_rTransitionList->m_uLength;
  if ( (_DWORD)m_uLength )
  {
    m_pItems = in_rTransitionList->m_pItems;
    if ( in_rTransitionList->m_pItems != &in_rTransitionList->m_pItems[m_uLength] )
    {
      do
      {
        v5 = *m_pItems;
        CAkTransition::ComputeTransition(
          *m_pItems,
          (*m_pItems)->m_uStartTimeInBufferTick + (*m_pItems)->m_uDurationInBufferTick);
        CAkTransition::Term(v5);
        v6 = g_DefaultPoolId;
        _((AMD_HD3D *)v5);
        AK::MemoryMgr::Free(v6, v5);
        ++m_pItems;
      }
      while ( m_pItems != &in_rTransitionList->m_pItems[in_rTransitionList->m_uLength] );
    }
  }
  v7 = in_rTransitionList->m_pItems;
  if ( in_rTransitionList->m_pItems )
  {
    in_rTransitionList->m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v7);
    in_rTransitionList->m_pItems = 0i64;
    in_rTransitionList->m_ulReserved = 0;
  }
}

// File Line: 80
// RVA: 0xA593C0
CAkTransition *__fastcall CAkTransitionManager::AddTransitionToList(
        CAkTransitionManager *this,
        TransitionParameters *in_Params,
        CAkTransition **in_bStart,
        __int64 in_eTransitionCategory)
{
  char v4; // bp
  AkArray<CAkTransition *,CAkTransition *,ArrayPoolDefault,0,AkArrayAllocatorDefault> *p_m_ActiveTransitionsList_State; // rdi
  CAkTransition *v7; // rbx
  CAkTransition *v8; // rax
  CAkTransition *v9; // rax
  CAkTransition **m_pItems; // rax
  float m_fTimeRatio; // xmm1_4
  __int64 v12; // rdx
  CAkTransition **v13; // rax
  __int64 m_uLength; // rdx
  __int64 v15; // rcx
  __int64 v16; // rdx
  int v17; // edi

  v4 = (char)in_bStart;
  p_m_ActiveTransitionsList_State = &this->m_ActiveTransitionsList_State;
  if ( (_DWORD)in_eTransitionCategory != 1 )
    p_m_ActiveTransitionsList_State = &this->m_ActiveTransitionsList_Fade;
  v7 = 0i64;
  if ( p_m_ActiveTransitionsList_State->m_uLength >= this->m_uMaxNumTransitions
    || (v8 = (CAkTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64)) == 0i64
    || (CAkTransition::CAkTransition(v8), (v7 = v9) == 0i64) )
  {
    m_pItems = p_m_ActiveTransitionsList_State->m_pItems;
    m_fTimeRatio = FLOAT_N1_0;
    v12 = (__int64)&p_m_ActiveTransitionsList_State->m_pItems[p_m_ActiveTransitionsList_State->m_uLength];
    if ( p_m_ActiveTransitionsList_State->m_pItems == (CAkTransition **)v12 )
      goto LABEL_28;
    do
    {
      if ( (*m_pItems)->m_fTimeRatio > m_fTimeRatio )
      {
        v7 = *m_pItems;
        m_fTimeRatio = (*m_pItems)->m_fTimeRatio;
      }
      ++m_pItems;
    }
    while ( m_pItems != (CAkTransition **)v12 );
    if ( !v7 )
      goto LABEL_28;
    CAkTransition::ComputeTransition(v7, v7->m_uStartTimeInBufferTick + v7->m_uDurationInBufferTick);
    CAkTransition::Reset(v7);
    v13 = p_m_ActiveTransitionsList_State->m_pItems;
    m_uLength = p_m_ActiveTransitionsList_State->m_uLength;
    v15 = (__int64)&p_m_ActiveTransitionsList_State->m_pItems[m_uLength];
    if ( p_m_ActiveTransitionsList_State->m_pItems != (CAkTransition **)v15 )
    {
      do
      {
        if ( *v13 == v7 )
          break;
        ++v13;
      }
      while ( v13 != (CAkTransition **)v15 );
      if ( v13 != (CAkTransition **)v15 )
      {
        if ( (unsigned int)m_uLength > 1 )
          *v13 = *(CAkTransition **)(v15 - 8);
        --p_m_ActiveTransitionsList_State->m_uLength;
      }
    }
  }
  if ( CAkTransition::InitParameters(v7, in_Params, g_pAudioMgr->m_uBufferTick) == AK_Fail
    || (v16 = p_m_ActiveTransitionsList_State->m_uLength,
        (unsigned int)v16 >= p_m_ActiveTransitionsList_State->m_ulReserved)
    || (in_bStart = &p_m_ActiveTransitionsList_State->m_pItems[v16],
        p_m_ActiveTransitionsList_State->m_uLength = v16 + 1,
        !in_bStart) )
  {
    CAkTransition::Term(v7);
    v17 = g_DefaultPoolId;
    if ( v7 )
    {
      _((AMD_HD3D *)v7);
      AK::MemoryMgr::Free(v17, v7);
    }
    v7 = 0i64;
    goto LABEL_28;
  }
  *in_bStart = v7;
  if ( v4 )
    v7->m_eState = Running;
  if ( !v7 )
  {
LABEL_28:
    LOBYTE(in_eTransitionCategory) = 1;
    ((void (__fastcall *)(ITransitionable *, __int64, CAkTransition **, __int64))in_Params->pUser->vfptr->TransUpdateValue)(
      in_Params->pUser,
      in_Params->eTarget,
      in_bStart,
      in_eTransitionCategory);
  }
  return v7;
}

// File Line: 177
// RVA: 0xA59560
__int64 __fastcall CAkTransitionManager::AddTransitionUser(
        CAkTransitionManager *this,
        CAkTransition *in_pTransition,
        ITransitionable *in_pUser)
{
  ITransitionable **m_pItems; // rax
  ITransitionable **i; // r9
  ITransitionable **v6; // rdx

  m_pItems = in_pTransition->m_UsersList.m_pItems;
  for ( i = &m_pItems[in_pTransition->m_UsersList.m_uLength]; m_pItems != i; ++m_pItems )
  {
    if ( *m_pItems == in_pUser )
      break;
  }
  v6 = 0i64;
  if ( m_pItems != i )
    v6 = m_pItems;
  if ( v6 )
    return 28i64;
  if ( in_pTransition->m_iNumUsers == -1
    || !AkArray<CAkPBI *,CAkPBI *,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(
          &in_pTransition->m_UsersList,
          in_pUser) )
  {
    return 27i64;
  }
  ++in_pTransition->m_iNumUsers;
  return 1i64;
}

// File Line: 202
// RVA: 0xA598C0
bool __fastcall CAkTransitionManager::IsTerminated(CAkTransitionManager *this, CAkTransition *in_pTransition)
{
  return in_pTransition->m_eState == 5;
}

// File Line: 212
// RVA: 0xA59A50
__int64 __fastcall CAkTransitionManager::RemoveTransitionUser(
        CAkTransitionManager *this,
        CAkTransition *in_pTransition,
        ITransitionable *in_pUser)
{
  ITransitionable **m_pItems; // rcx
  __int64 m_uLength; // r10
  ITransitionable **v6; // rdx
  __int64 result; // rax
  bool v8; // zf

  m_pItems = in_pTransition->m_UsersList.m_pItems;
  m_uLength = in_pTransition->m_UsersList.m_uLength;
  v6 = &m_pItems[m_uLength];
  if ( m_pItems == v6 )
    return 29i64;
  while ( *m_pItems != in_pUser )
  {
    if ( ++m_pItems == v6 )
      return 29i64;
  }
  if ( (unsigned int)m_uLength > 1 )
    *m_pItems = *(v6 - 1);
  --in_pTransition->m_UsersList.m_uLength;
  v8 = in_pTransition->m_iNumUsers-- == 1;
  result = 1i64;
  if ( v8 )
    in_pTransition->m_eState = 6;
  return result;
}

// File Line: 263
// RVA: 0xA598D0
void __fastcall CAkTransitionManager::Pause(CAkTransitionManager *this, CAkTransition *in_pTransition)
{
  CAkTransition::State m_eState; // eax

  m_eState = in_pTransition->m_eState;
  if ( m_eState == Running )
  {
    in_pTransition->m_eState = Suspended;
  }
  else if ( m_eState == 4 )
  {
    in_pTransition->m_eState = Suspended|Running;
  }
}

// File Line: 284
// RVA: 0xA59AA0
void __fastcall CAkTransitionManager::Resume(CAkTransitionManager *this, CAkTransition *in_pTransition)
{
  CAkTransition::State m_eState; // eax

  m_eState = in_pTransition->m_eState;
  if ( m_eState == (Suspended|Running) )
  {
    in_pTransition->m_eState = 4;
  }
  else if ( m_eState == Suspended )
  {
    in_pTransition->m_eState = Running;
  }
}

// File Line: 310
// RVA: 0xA595E0
void __fastcall CAkTransitionManager::ChangeParameter(
        CAkTransitionManager *this,
        CAkTransition *in_pTransition,
        __int64 in_eTarget,
        float in_NewTarget,
        int in_NewDuration,
        AkCurveInterpolation in_eCurveType,
        AkValueMeaning in_eValueMeaning)
{
  char v7; // al
  __int64 m_eTarget; // r11
  int v9; // r10d
  float m_fCurrentValue; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  AkCurveInterpolation v19; // eax
  unsigned int m_uBufferTick; // r8d
  unsigned int v21; // eax
  unsigned int m_uStartTimeInBufferTick; // ecx
  unsigned int v23; // ecx

  v7 = *((_BYTE *)in_pTransition + 64);
  m_eTarget = in_pTransition->m_eTarget;
  v9 = in_eTarget;
  in_pTransition->m_eTarget = in_eTarget;
  if ( (v7 & 1) != 0 )
  {
    if ( (v7 & 2) != 0 )
    {
      m_fCurrentValue = in_pTransition->m_fCurrentValue;
      v11 = 0.0;
      in_pTransition->m_fStartValue = m_fCurrentValue;
      v12 = m_fCurrentValue * 0.050000001;
      if ( v12 >= -37.0 )
      {
        if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
        {
          v14 = *(float *)&`AkMath::FastPow10::`4::SCALE;
        }
        else
        {
          v14 = FLOAT_2_7866352e7;
          `AkMath::FastPow10::`4::`local static guard |= 1u;
          `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
        }
        v13 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                ((int)(float)((float)(v14 * v12) + 1065353200.0) & 0x7FFFFF)
                                              + 1065353216)
                                            * 0.32518977)
                                    + 0.020805772)
                            * COERCE_FLOAT(((int)(float)((float)(v14 * v12) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                    + 0.65304345)
            * COERCE_FLOAT((int)(float)((float)(v14 * v12) + 1065353200.0) & 0xFF800000);
      }
      else
      {
        v13 = 0.0;
      }
      v15 = in_NewTarget * 0.050000001;
      in_pTransition->m_fStartValue = v13;
      if ( v15 < -37.0 )
        goto LABEL_20;
      if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
      {
        v16 = v15 * *(float *)&`AkMath::FastPow10::`4::SCALE;
      }
      else
      {
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
        v16 = v15 * 27866352.0;
        `AkMath::FastPow10::`4::`local static guard |= 1u;
      }
    }
    else
    {
      v17 = in_NewTarget * 0.050000001;
      if ( v17 < -37.0 )
      {
        v11 = 0.0;
LABEL_20:
        if ( in_eValueMeaning == AkValueMeaning_Offset )
          v11 = v11 * in_pTransition->m_fTargetValue;
        in_pTransition->m_fTargetValue = v11;
        goto LABEL_28;
      }
      if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
      {
        v18 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      }
      else
      {
        v18 = FLOAT_2_7866352e7;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
        `AkMath::FastPow10::`4::`local static guard |= 1u;
      }
      v16 = v17 * v18;
    }
    v11 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)(v16 + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                        * 0.32518977)
                                + 0.020805772)
                        * COERCE_FLOAT(((int)(float)(v16 + 1065353200.0) & 0x7FFFFF) + 1065353216))
                + 0.65304345)
        * COERCE_FLOAT((int)(float)(v16 + 1065353200.0) & 0xFF800000);
    goto LABEL_20;
  }
  if ( (v7 & 2) != 0 )
    in_pTransition->m_fStartValue = in_pTransition->m_fCurrentValue;
  if ( in_eValueMeaning == AkValueMeaning_Offset )
    in_NewTarget = in_NewTarget + in_pTransition->m_fTargetValue;
  in_pTransition->m_fTargetValue = in_NewTarget;
LABEL_28:
  if ( in_pTransition->m_fTargetValue <= in_pTransition->m_fStartValue && ((in_eCurveType - 3) & 0xFFFFFFFD) != 0 )
    v19 = 8 - in_eCurveType;
  else
    v19 = in_eCurveType;
  in_pTransition->m_eFadeCurve = v19;
  m_uBufferTick = g_pAudioMgr->m_uBufferTick;
  v21 = (AkAudioLibSettings::g_msPerBufferTick + in_NewDuration - 1) / AkAudioLibSettings::g_msPerBufferTick;
  if ( m_eTarget == in_pTransition->m_eTarget && (v9 & 0xF000000) != 0 )
  {
    m_uStartTimeInBufferTick = in_pTransition->m_uStartTimeInBufferTick;
    in_pTransition->m_uLastBufferTickUpdated = m_uBufferTick;
    in_pTransition->m_uStartTimeInBufferTick = m_uBufferTick;
    v23 = in_pTransition->m_uDurationInBufferTick + m_uStartTimeInBufferTick - m_uBufferTick;
    if ( v21 < v23 )
      v23 = v21;
    in_pTransition->m_uDurationInBufferTick = v23;
  }
  else
  {
    in_pTransition->m_uDurationInBufferTick = v21;
    in_pTransition->m_uLastBufferTickUpdated = m_uBufferTick;
    in_pTransition->m_uStartTimeInBufferTick = m_uBufferTick;
  }
}

// File Line: 407
// RVA: 0xA59A20
void __fastcall CAkTransitionManager::ProcessTransitionsList(
        CAkTransitionManager *this,
        unsigned int in_CurrentBufferTick)
{
  CAkTransitionManager::ProcessTransitionsList(this, in_CurrentBufferTick, &this->m_ActiveTransitionsList_Fade);
  CAkTransitionManager::ProcessTransitionsList(this, in_CurrentBufferTick, &this->m_ActiveTransitionsList_State);
}

// File Line: 415
// RVA: 0xA598F0
void __fastcall CAkTransitionManager::ProcessTransitionsList(
        CAkTransitionManager *this,
        unsigned int in_CurrentBufferTick,
        AkArray<CAkTransition *,CAkTransition *,ArrayPoolDefault,0,AkArrayAllocatorDefault> *in_rTransitionList)
{
  CAkTransition **m_pItems; // rbx
  CAkTransition *v6; // rdi
  CAkTransition::State m_eState; // eax
  int v8; // esi
  unsigned int m_uLength; // eax
  unsigned int v10; // eax
  int v11; // esi

  m_pItems = in_rTransitionList->m_pItems;
  while ( m_pItems != &in_rTransitionList->m_pItems[in_rTransitionList->m_uLength] )
  {
    v6 = *m_pItems;
    m_eState = (*m_pItems)->m_eState;
    if ( m_eState == 6 )
    {
      CAkTransition::Term(*m_pItems);
      v8 = g_DefaultPoolId;
      _((AMD_HD3D *)v6);
      AK::MemoryMgr::Free(v8, v6);
      m_uLength = in_rTransitionList->m_uLength;
      if ( m_uLength > 1 )
        *m_pItems = in_rTransitionList->m_pItems[m_uLength - 1];
      --in_rTransitionList->m_uLength;
    }
    else
    {
      if ( m_eState == Suspended )
      {
        v6->m_uLastBufferTickUpdated = in_CurrentBufferTick;
        v6->m_eState = Suspended|Running;
      }
      else if ( m_eState == 4 )
      {
        v6->m_eState = Running;
        v6->m_uStartTimeInBufferTick += in_CurrentBufferTick - v6->m_uLastBufferTickUpdated;
      }
      if ( v6->m_eState == Running && CAkTransition::ComputeTransition(v6, in_CurrentBufferTick) )
      {
        CAkTransition::Term(v6);
        v10 = in_rTransitionList->m_uLength;
        if ( v10 > 1 )
          *m_pItems = in_rTransitionList->m_pItems[v10 - 1];
        --in_rTransitionList->m_uLength;
        v11 = g_DefaultPoolId;
        _((AMD_HD3D *)v6);
        AK::MemoryMgr::Free(v11, v6);
      }
      else
      {
        ++m_pItems;
      }
    }
  }
}

