// File Line: 29
// RVA: 0xA86F90
void __fastcall CAkTransition::CAkTransition(CAkTransition *this)
{
  this->m_UsersList.m_pItems = 0i64;
  *(_QWORD *)&this->m_UsersList.m_uLength = 0i64;
  *((_BYTE *)this + 64) &= 0xFCu;
  this->m_iNumUsers = 0;
  this->m_eState = NotRunning;
  this->m_fTimeRatio = 0.0;
  this->m_eTarget = 0x20000000i64;
}

// File Line: 45
// RVA: 0xA87370
void __fastcall CAkTransition::Term(CAkTransition *this)
{
  ITransitionable **m_pItems; // rdx

  m_pItems = this->m_UsersList.m_pItems;
  if ( m_pItems )
  {
    this->m_UsersList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_UsersList.m_pItems = 0i64;
    this->m_UsersList.m_ulReserved = 0;
  }
}

// File Line: 52
// RVA: 0xA87350
void __fastcall CAkTransition::Reset(CAkTransition *this)
{
  this->m_UsersList.m_uLength = 0;
  *((_BYTE *)this + 64) &= 0xFCu;
  this->m_iNumUsers = 0;
  this->m_eTarget = 0x20000000i64;
  this->m_eState = NotRunning;
  this->m_fTimeRatio = 0.0;
}

// File Line: 65
// RVA: 0xA86FC0
__int64 __fastcall CAkTransition::ComputeTransition(CAkTransition *this, unsigned int in_CurrentBufferTick)
{
  signed int m_uDurationInBufferTick; // r8d
  unsigned int m_uStartTimeInBufferTick; // ecx
  unsigned __int8 v5; // si
  float m_fTargetValue; // xmm6_4
  char v7; // cl
  float v8; // xmm2_4
  ITransitionable **m_pItems; // rbx

  m_uDurationInBufferTick = this->m_uDurationInBufferTick;
  m_uStartTimeInBufferTick = this->m_uStartTimeInBufferTick;
  v5 = 0;
  if ( in_CurrentBufferTick < m_uStartTimeInBufferTick + m_uDurationInBufferTick )
  {
    if ( in_CurrentBufferTick > m_uStartTimeInBufferTick )
      this->m_fTimeRatio = (float)(int)(in_CurrentBufferTick - m_uStartTimeInBufferTick)
                         / (float)m_uDurationInBufferTick;
    else
      this->m_fTimeRatio = 0.0;
    m_fTargetValue = AkInterpolation::InterpolateNoCheck(
                       this->m_fTimeRatio,
                       this->m_fStartValue,
                       this->m_fTargetValue,
                       this->m_eFadeCurve);
  }
  else
  {
    m_fTargetValue = this->m_fTargetValue;
    v5 = 1;
  }
  v7 = *((_BYTE *)this + 64);
  if ( (v7 & 1) != 0 )
  {
    v8 = (float)(COERCE_FLOAT((LODWORD(m_fTargetValue) & 0x7FFFFF) + 1065353216) - 1.0)
       / (float)(COERCE_FLOAT((LODWORD(m_fTargetValue) & 0x7FFFFF) + 1065353216) + 1.0);
    m_fTargetValue = (float)((float)((float)((float)((float)((float)(v8 * v8) * 0.33333334) + 1.0) * (float)(v8 * 2.0))
                                   + (float)((float)((float)(unsigned __int8)(LODWORD(m_fTargetValue) >> 23) - 127.0)
                                           * 0.69314718))
                           * 0.43429449)
                   * 20.0;
  }
  m_pItems = this->m_UsersList.m_pItems;
  this->m_fCurrentValue = m_fTargetValue;
  *((_BYTE *)this + 64) = v7 | 2;
  if ( m_pItems != &m_pItems[this->m_UsersList.m_uLength] )
  {
    do
    {
      ((void (__fastcall *)(ITransitionable *, __int64, ITransitionableVtbl *, _QWORD))(*m_pItems)->vfptr->TransUpdateValue)(
        *m_pItems,
        this->m_eTarget,
        (*m_pItems)->vfptr,
        v5);
      ++m_pItems;
    }
    while ( m_pItems != &this->m_UsersList.m_pItems[this->m_UsersList.m_uLength] );
  }
  return v5;
}

// File Line: 114
// RVA: 0xA87130
__int64 __fastcall CAkTransition::InitParameters(
        CAkTransition *this,
        TransitionParameters *in_Params,
        unsigned int in_CurrentBufferTick)
{
  float fStartValue; // xmm2_4
  float fTargetValue; // xmm1_4
  int v7; // edx
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  AkCurveInterpolation v11; // ecx
  AkCurveInterpolation eFadeCurve; // eax
  ITransitionable **v13; // r10
  int v14; // eax
  ITransitionable **m_pItems; // rax
  ITransitionable *pUser; // rdx
  ITransitionable **v17; // r8
  bool v18; // zf

  this->m_eTarget = in_Params->eTarget;
  *((_BYTE *)this + 64) ^= (in_Params->bdBs ^ *((_BYTE *)this + 64)) & 1;
  fStartValue = in_Params->fStartValue;
  fTargetValue = in_Params->fTargetValue;
  if ( in_Params->bdBs )
  {
    v7 = `AkMath::FastPow10::`4::`local static guard;
    v8 = fStartValue * 0.050000001;
    if ( v8 >= -37.0 )
    {
      if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
      {
        v9 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      }
      else
      {
        v9 = FLOAT_2_7866352e7;
        v7 = `AkMath::FastPow10::`4::`local static guard | 1;
        `AkMath::FastPow10::`4::`local static guard |= 1u;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      fStartValue = (float)((float)((float)((float)(COERCE_FLOAT(
                                                      ((int)(float)((float)(v8 * v9) + 1065353200.0) & 0x7FFFFF)
                                                    + 1065353216)
                                                  * 0.32518977)
                                          + 0.020805772)
                                  * COERCE_FLOAT(((int)(float)((float)(v8 * v9) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                          + 0.65304345)
                  * COERCE_FLOAT((int)(float)((float)(v8 * v9) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v9 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      fStartValue = 0.0;
    }
    v10 = fTargetValue * 0.050000001;
    if ( v10 >= -37.0 )
    {
      if ( (v7 & 1) == 0 )
      {
        v9 = FLOAT_2_7866352e7;
        `AkMath::FastPow10::`4::`local static guard = v7 | 1;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      fTargetValue = (float)((float)((float)((float)(COERCE_FLOAT(
                                                       ((int)(float)((float)(v10 * v9) + 1065353200.0) & 0x7FFFFF)
                                                     + 1065353216)
                                                   * 0.32518977)
                                           + 0.020805772)
                                   * COERCE_FLOAT(((int)(float)((float)(v10 * v9) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                           + 0.65304345)
                   * COERCE_FLOAT((int)(float)((float)(v10 * v9) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      fTargetValue = 0.0;
    }
  }
  this->m_fStartValue = fStartValue;
  this->m_fCurrentValue = fStartValue;
  this->m_fTargetValue = fTargetValue;
  if ( in_Params->bUseReciprocalCurve
    && fStartValue >= fTargetValue
    && (v11 = in_Params->eFadeCurve, ((v11 - 3) & 0xFFFFFFFD) != 0) )
  {
    eFadeCurve = 8 - v11;
  }
  else
  {
    eFadeCurve = in_Params->eFadeCurve;
  }
  this->m_eFadeCurve = eFadeCurve;
  this->m_uStartTimeInBufferTick = in_CurrentBufferTick;
  v13 = 0i64;
  v14 = (AkAudioLibSettings::g_msPerBufferTick + in_Params->lDuration - 1) / AkAudioLibSettings::g_msPerBufferTick;
  this->m_fTimeRatio = 0.0;
  this->m_uDurationInBufferTick = v14;
  m_pItems = this->m_UsersList.m_pItems;
  pUser = in_Params->pUser;
  v17 = &m_pItems[this->m_UsersList.m_uLength];
  v18 = m_pItems == v17;
  if ( m_pItems != v17 )
  {
    do
    {
      if ( *m_pItems == pUser )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v17 );
    v18 = m_pItems == v17;
  }
  if ( !v18 )
    v13 = m_pItems;
  if ( !v13 )
  {
    if ( !AkArray<CAkPBI *,CAkPBI *,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(&this->m_UsersList, pUser) )
      return 2i64;
    ++this->m_iNumUsers;
  }
  return 1i64;
}

