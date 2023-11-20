// File Line: 29
// RVA: 0xA86F90
void __fastcall CAkTransition::CAkTransition(CAkTransition *this)
{
  this->m_UsersList.m_pItems = 0i64;
  *(_QWORD *)&this->m_UsersList.m_uLength = 0i64;
  *((_BYTE *)this + 64) &= 0xFCu;
  this->m_iNumUsers = 0;
  this->m_eState = 0;
  this->m_fTimeRatio = 0.0;
  this->m_eTarget = 0x20000000i64;
}

// File Line: 45
// RVA: 0xA87370
void __fastcall CAkTransition::Term(CAkTransition *this)
{
  ITransitionable **v1; // rdx
  CAkTransition *v2; // rbx

  v1 = this->m_UsersList.m_pItems;
  v2 = this;
  if ( v1 )
  {
    this->m_UsersList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_UsersList.m_pItems = 0i64;
    v2->m_UsersList.m_ulReserved = 0;
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
  this->m_eState = 0;
  this->m_fTimeRatio = 0.0;
}

// File Line: 65
// RVA: 0xA86FC0
__int64 __fastcall CAkTransition::ComputeTransition(CAkTransition *this, unsigned int in_CurrentBufferTick)
{
  signed int v2; // er8
  CAkTransition *v3; // rdi
  unsigned int v4; // ecx
  unsigned __int8 v5; // si
  float v6; // xmm6_4
  char v7; // cl
  float v8; // xmm2_4
  ITransitionable **v9; // rbx

  v2 = this->m_uDurationInBufferTick;
  v3 = this;
  v4 = this->m_uStartTimeInBufferTick;
  v5 = 0;
  if ( in_CurrentBufferTick < v4 + v2 )
  {
    if ( in_CurrentBufferTick > v4 )
      v3->m_fTimeRatio = (float)(signed int)(in_CurrentBufferTick - v4) / (float)v2;
    else
      v3->m_fTimeRatio = 0.0;
    v6 = AkInterpolation::InterpolateNoCheck(v3->m_fTimeRatio, v3->m_fStartValue, v3->m_fTargetValue, v3->m_eFadeCurve);
  }
  else
  {
    v6 = v3->m_fTargetValue;
    v5 = 1;
  }
  v7 = *((_BYTE *)v3 + 64);
  if ( v7 & 1 )
  {
    v8 = (float)(COERCE_FLOAT((LODWORD(v6) & 0x7FFFFF) + 1065353216) - 1.0)
       / (float)(COERCE_FLOAT((LODWORD(v6) & 0x7FFFFF) + 1065353216) + 1.0);
    v6 = (float)((float)((float)((float)((float)((float)(v8 * v8) * 0.33333334) + 1.0) * (float)(v8 * 2.0))
                       + (float)((float)((float)(unsigned __int8)(LODWORD(v6) >> 23) - 127.0) * 0.69314718))
               * 0.43429449)
       * 20.0;
  }
  v9 = v3->m_UsersList.m_pItems;
  v3->m_fCurrentValue = v6;
  *((_BYTE *)v3 + 64) = v7 | 2;
  if ( v9 != &v9[v3->m_UsersList.m_uLength] )
  {
    do
    {
      ((void (__fastcall *)(ITransitionable *, __int64, ITransitionableVtbl *, _QWORD))(*v9)->vfptr->TransUpdateValue)(
        *v9,
        v3->m_eTarget,
        (*v9)->vfptr,
        v5);
      ++v9;
    }
    while ( v9 != &v3->m_UsersList.m_pItems[v3->m_UsersList.m_uLength] );
  }
  return v5;
}

// File Line: 114
// RVA: 0xA87130
signed __int64 __fastcall CAkTransition::InitParameters(CAkTransition *this, TransitionParameters *in_Params, unsigned int in_CurrentBufferTick)
{
  TransitionParameters *v3; // r9
  CAkTransition *v4; // rbx
  float v5; // xmm2_4
  float v6; // xmm1_4
  int v7; // edx
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  AkCurveInterpolation v11; // ecx
  int v12; // eax
  ITransitionable **v13; // r10
  int v14; // eax
  ITransitionable **v15; // rax
  ITransitionable *v16; // rdx
  signed __int64 v17; // r8
  bool v18; // zf

  v3 = in_Params;
  v4 = this;
  this->m_eTarget = in_Params->eTarget;
  *((_BYTE *)this + 64) ^= (in_Params->bdBs ^ *((_BYTE *)this + 64)) & 1;
  v5 = in_Params->fStartValue;
  v6 = in_Params->fTargetValue;
  if ( in_Params->bdBs )
  {
    v7 = `AkMath::FastPow10::`4::`local static guard;
    v8 = v5 * 0.050000001;
    if ( v8 >= -37.0 )
    {
      if ( `AkMath::FastPow10::`4::`local static guard & 1 )
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
      v5 = (float)((float)((float)((float)(COERCE_FLOAT(
                                             ((signed int)(float)((float)(v8 * v9) + 1065353200.0) & 0x7FFFFF)
                                           + 1065353216)
                                         * 0.32518977)
                                 + 0.020805772)
                         * COERCE_FLOAT(((signed int)(float)((float)(v8 * v9) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                 + 0.65304345)
         * COERCE_FLOAT((signed int)(float)((float)(v8 * v9) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v9 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      v5 = 0.0;
    }
    v10 = v6 * 0.050000001;
    if ( v10 >= -37.0 )
    {
      if ( !(v7 & 1) )
      {
        v9 = FLOAT_2_7866352e7;
        `AkMath::FastPow10::`4::`local static guard = v7 | 1;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v6 = (float)((float)((float)((float)(COERCE_FLOAT(
                                             ((signed int)(float)((float)(v10 * v9) + 1065353200.0) & 0x7FFFFF)
                                           + 1065353216)
                                         * 0.32518977)
                                 + 0.020805772)
                         * COERCE_FLOAT(((signed int)(float)((float)(v10 * v9) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                 + 0.65304345)
         * COERCE_FLOAT((signed int)(float)((float)(v10 * v9) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v6 = 0.0;
    }
  }
  this->m_fStartValue = v5;
  this->m_fCurrentValue = v5;
  this->m_fTargetValue = v6;
  if ( v3->bUseReciprocalCurve && v5 >= v6 && (v11 = v3->eFadeCurve, (v11 - 3) & 0xFFFFFFFD) )
    v12 = 8 - v11;
  else
    v12 = v3->eFadeCurve;
  v4->m_eFadeCurve = v12;
  v4->m_uStartTimeInBufferTick = in_CurrentBufferTick;
  v13 = 0i64;
  v14 = (AkAudioLibSettings::g_msPerBufferTick + v3->lDuration - 1) / AkAudioLibSettings::g_msPerBufferTick;
  v4->m_fTimeRatio = 0.0;
  v4->m_uDurationInBufferTick = v14;
  v15 = v4->m_UsersList.m_pItems;
  v16 = v3->pUser;
  v17 = (signed __int64)&v15[v4->m_UsersList.m_uLength];
  v18 = v15 == (ITransitionable **)v17;
  if ( v15 != (ITransitionable **)v17 )
  {
    do
    {
      if ( *v15 == v16 )
        break;
      ++v15;
    }
    while ( v15 != (ITransitionable **)v17 );
    v18 = v15 == (ITransitionable **)v17;
  }
  if ( !v18 )
    v13 = v15;
  if ( !v13 )
  {
    if ( !AkArray<CAkPBI *,CAkPBI *,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(&v4->m_UsersList, v16) )
      return 2i64;
    ++v4->m_iNumUsers;
  }
  return 1i64;
}

