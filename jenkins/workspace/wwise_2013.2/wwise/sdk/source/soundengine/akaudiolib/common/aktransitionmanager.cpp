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
signed __int64 __fastcall CAkTransitionManager::Init(CAkTransitionManager *this, unsigned int in_uMaxNumTransitions)
{
  unsigned int v2; // edi
  CAkTransitionManager *v3; // rbx
  CAkTransition **v4; // rax
  unsigned int v5; // edi
  CAkTransition **v6; // rax

  v2 = 255;
  v3 = this;
  if ( in_uMaxNumTransitions )
    v2 = in_uMaxNumTransitions;
  this->m_uMaxNumTransitions = v2;
  if ( v2 )
  {
    v4 = (CAkTransition **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v2);
    v3->m_ActiveTransitionsList_Fade.m_pItems = v4;
    if ( !v4 )
      return 52i64;
    v3->m_ActiveTransitionsList_Fade.m_ulReserved = v2;
  }
  v5 = v3->m_uMaxNumTransitions;
  if ( v3->m_uMaxNumTransitions )
  {
    v6 = (CAkTransition **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v5);
    v3->m_ActiveTransitionsList_State.m_pItems = v6;
    if ( !v6 )
      return 52i64;
    v3->m_ActiveTransitionsList_State.m_ulReserved = v5;
  }
  return 1i64;
}

// File Line: 54
// RVA: 0xA59AC0
void __fastcall CAkTransitionManager::Term(CAkTransitionManager *this)
{
  CAkTransitionManager *v1; // rbx

  v1 = this;
  CAkTransitionManager::TermList(this, &this->m_ActiveTransitionsList_Fade);
  CAkTransitionManager::TermList(v1, &v1->m_ActiveTransitionsList_State);
}

// File Line: 61
// RVA: 0xA59AF0
void __fastcall CAkTransitionManager::TermList(CAkTransitionManager *this, AkArray<CAkTransition *,CAkTransition *,ArrayPoolDefault,0,AkArrayAllocatorDefault> *in_rTransitionList)
{
  __int64 v2; // rax
  AkArray<CAkTransition *,CAkTransition *,ArrayPoolDefault,0,AkArrayAllocatorDefault> *v3; // rdi
  CAkTransition **v4; // rbx
  CAkTransition *v5; // rbp
  int v6; // esi
  CAkTransition **v7; // rdx

  v2 = in_rTransitionList->m_uLength;
  v3 = in_rTransitionList;
  if ( (_DWORD)v2 )
  {
    v4 = in_rTransitionList->m_pItems;
    if ( in_rTransitionList->m_pItems != &in_rTransitionList->m_pItems[v2] )
    {
      do
      {
        v5 = *v4;
        CAkTransition::ComputeTransition(*v4, (*v4)->m_uStartTimeInBufferTick + (*v4)->m_uDurationInBufferTick);
        CAkTransition::Term(v5);
        v6 = g_DefaultPoolId;
        _((AMD_HD3D *)v5);
        AK::MemoryMgr::Free(v6, v5);
        ++v4;
      }
      while ( v4 != &v3->m_pItems[v3->m_uLength] );
    }
  }
  v7 = v3->m_pItems;
  if ( v3->m_pItems )
  {
    v3->m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v7);
    v3->m_pItems = 0i64;
    v3->m_ulReserved = 0;
  }
}

// File Line: 80
// RVA: 0xA593C0
CAkTransition *__fastcall CAkTransitionManager::AddTransitionToList(CAkTransitionManager *this, TransitionParameters *in_Params, __int64 in_bStart, __int64 in_eTransitionCategory)
{
  char v4; // bp
  TransitionParameters *v5; // rsi
  AkArray<CAkTransition *,CAkTransition *,ArrayPoolDefault,0,AkArrayAllocatorDefault> *v6; // rdi
  CAkTransition *v7; // rbx
  CAkTransition *v8; // rax
  CAkTransition *v9; // rax
  CAkTransition **v10; // rax
  float v11; // xmm1_4
  signed __int64 v12; // rdx
  CAkTransition **v13; // rax
  __int64 v14; // rdx
  signed __int64 v15; // rcx
  __int64 v16; // rdx
  int v17; // edi
  __int128 v18; // xmm2

  v4 = in_bStart;
  v5 = in_Params;
  v6 = &this->m_ActiveTransitionsList_State;
  if ( (_DWORD)in_eTransitionCategory != 1 )
    v6 = &this->m_ActiveTransitionsList_Fade;
  v7 = 0i64;
  if ( v6->m_uLength >= this->m_uMaxNumTransitions
    || (v8 = (CAkTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64)) == 0i64
    || (CAkTransition::CAkTransition(v8), (v7 = v9) == 0i64) )
  {
    v10 = v6->m_pItems;
    v11 = FLOAT_N1_0;
    v12 = (signed __int64)&v6->m_pItems[v6->m_uLength];
    if ( v6->m_pItems == (CAkTransition **)v12 )
      goto LABEL_28;
    do
    {
      if ( (*v10)->m_fTimeRatio > v11 )
      {
        v7 = *v10;
        v11 = (*v10)->m_fTimeRatio;
      }
      ++v10;
    }
    while ( v10 != (CAkTransition **)v12 );
    if ( !v7 )
      goto LABEL_28;
    CAkTransition::ComputeTransition(v7, v7->m_uStartTimeInBufferTick + v7->m_uDurationInBufferTick);
    CAkTransition::Reset(v7);
    v13 = v6->m_pItems;
    v14 = v6->m_uLength;
    v15 = (signed __int64)&v6->m_pItems[v14];
    if ( v6->m_pItems != (CAkTransition **)v15 )
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
        if ( (unsigned int)v14 > 1 )
          *v13 = *(CAkTransition **)(v15 - 8);
        --v6->m_uLength;
      }
    }
  }
  if ( CAkTransition::InitParameters(v7, v5, g_pAudioMgr->m_uBufferTick) == 2
    || (v16 = v6->m_uLength, (unsigned int)v16 >= v6->m_ulReserved)
    || (in_bStart = (__int64)&v6->m_pItems[v16], v6->m_uLength = v16 + 1, !in_bStart) )
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
  *(_QWORD *)in_bStart = v7;
  if ( v4 )
    v7->m_eState = 1;
  if ( !v7 )
  {
LABEL_28:
    v18 = LODWORD(v5->fTargetValue);
    LOBYTE(in_eTransitionCategory) = 1;
    ((void (__fastcall *)(ITransitionable *, __int64, __int64, __int64))v5->pUser->vfptr->TransUpdateValue)(
      v5->pUser,
      v5->eTarget,
      in_bStart,
      in_eTransitionCategory);
  }
  return v7;
}

// File Line: 177
// RVA: 0xA59560
signed __int64 __fastcall CAkTransitionManager::AddTransitionUser(CAkTransitionManager *this, CAkTransition *in_pTransition, ITransitionable *in_pUser)
{
  ITransitionable **v3; // rax
  CAkTransition *v4; // rbx
  signed __int64 i; // r9
  ITransitionable **v6; // rdx

  v3 = in_pTransition->m_UsersList.m_pItems;
  v4 = in_pTransition;
  for ( i = (signed __int64)&v3[in_pTransition->m_UsersList.m_uLength]; v3 != (ITransitionable **)i; ++v3 )
  {
    if ( *v3 == in_pUser )
      break;
  }
  v6 = 0i64;
  if ( v3 != (ITransitionable **)i )
    v6 = v3;
  if ( v6 )
    return 28i64;
  if ( v4->m_iNumUsers >= 0xFFu
    || !AkArray<CAkPBI *,CAkPBI *,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(&v4->m_UsersList, in_pUser) )
  {
    return 27i64;
  }
  ++v4->m_iNumUsers;
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
signed __int64 __fastcall CAkTransitionManager::RemoveTransitionUser(CAkTransitionManager *this, CAkTransition *in_pTransition, ITransitionable *in_pUser)
{
  ITransitionable **v3; // rcx
  __int64 v4; // r10
  CAkTransition *v5; // r9
  signed __int64 v6; // rdx
  signed __int64 result; // rax
  bool v8; // zf

  v3 = in_pTransition->m_UsersList.m_pItems;
  v4 = in_pTransition->m_UsersList.m_uLength;
  v5 = in_pTransition;
  v6 = (signed __int64)&v3[v4];
  if ( v3 == (ITransitionable **)v6 )
    return 29i64;
  while ( *v3 != in_pUser )
  {
    ++v3;
    if ( v3 == (ITransitionable **)v6 )
      return 29i64;
  }
  if ( (unsigned int)v4 > 1 )
    *v3 = *(ITransitionable **)(v6 - 8);
  --v5->m_UsersList.m_uLength;
  v8 = v5->m_iNumUsers-- == 1;
  result = 1i64;
  if ( v8 )
    v5->m_eState = 6;
  return result;
}

// File Line: 263
// RVA: 0xA598D0
void __fastcall CAkTransitionManager::Pause(CAkTransitionManager *this, CAkTransition *in_pTransition)
{
  CAkTransition::State v2; // eax

  v2 = in_pTransition->m_eState;
  if ( v2 == 1 )
  {
    in_pTransition->m_eState = 2;
  }
  else if ( v2 == 4 )
  {
    in_pTransition->m_eState = 3;
  }
}

// File Line: 284
// RVA: 0xA59AA0
void __fastcall CAkTransitionManager::Resume(CAkTransitionManager *this, CAkTransition *in_pTransition)
{
  CAkTransition::State v2; // eax

  v2 = in_pTransition->m_eState;
  if ( v2 == 3 )
  {
    in_pTransition->m_eState = 4;
  }
  else if ( v2 == 2 )
  {
    in_pTransition->m_eState = 1;
  }
}

// File Line: 310
// RVA: 0xA595E0
void __fastcall CAkTransitionManager::ChangeParameter(CAkTransitionManager *this, CAkTransition *in_pTransition, __int64 in_eTarget, float in_NewTarget, int in_NewDuration, AkCurveInterpolation in_eCurveType, AkValueMeaning in_eValueMeaning)
{
  char v7; // al
  __int64 v8; // r11
  int v9; // er10
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  __int32 v19; // eax
  unsigned int v20; // er8
  unsigned int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // ecx

  v7 = *((_BYTE *)in_pTransition + 64);
  v8 = in_pTransition->m_eTarget;
  v9 = in_eTarget;
  in_pTransition->m_eTarget = in_eTarget;
  if ( v7 & 1 )
  {
    if ( v7 & 2 )
    {
      v10 = in_pTransition->m_fCurrentValue;
      v11 = 0.0;
      in_pTransition->m_fStartValue = v10;
      v12 = v10 * 0.050000001;
      if ( v12 >= -37.0 )
      {
        if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
        {
          v14 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
        }
        else
        {
          v14 = FLOAT_2_7866352e7;
          `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
          `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
        }
        v13 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                ((signed int)(float)((float)(v14 * v12) + 1065353200.0) & 0x7FFFFF)
                                              + 1065353216)
                                            * 0.32518977)
                                    + 0.020805772)
                            * COERCE_FLOAT(((signed int)(float)((float)(v14 * v12) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                    + 0.65304345)
            * COERCE_FLOAT((signed int)(float)((float)(v14 * v12) + 1065353200.0) & 0xFF800000);
      }
      else
      {
        v13 = 0.0;
      }
      v15 = in_NewTarget * 0.050000001;
      in_pTransition->m_fStartValue = v13;
      if ( v15 < -37.0 )
        goto LABEL_20;
      if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
      {
        v16 = v15 * *(float *)&`AkMath::FastPow10'::`4'::SCALE;
      }
      else
      {
        `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
        v16 = v15 * 27866352.0;
        `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
      }
    }
    else
    {
      v17 = in_NewTarget * 0.050000001;
      if ( v17 < -37.0 )
      {
        v11 = 0.0;
LABEL_20:
        if ( in_eValueMeaning == 2 )
          v11 = v11 * in_pTransition->m_fTargetValue;
        in_pTransition->m_fTargetValue = v11;
        goto LABEL_28;
      }
      if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
      {
        v18 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
      }
      else
      {
        v18 = FLOAT_2_7866352e7;
        `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
        `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
      }
      v16 = v17 * v18;
    }
    v11 = (float)((float)((float)((float)(COERCE_FLOAT(((signed int)(float)(v16 + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                        * 0.32518977)
                                + 0.020805772)
                        * COERCE_FLOAT(((signed int)(float)(v16 + 1065353200.0) & 0x7FFFFF) + 1065353216))
                + 0.65304345)
        * COERCE_FLOAT((signed int)(float)(v16 + 1065353200.0) & 0xFF800000);
    goto LABEL_20;
  }
  if ( v7 & 2 )
    in_pTransition->m_fStartValue = in_pTransition->m_fCurrentValue;
  if ( in_eValueMeaning == 2 )
    in_NewTarget = in_NewTarget + in_pTransition->m_fTargetValue;
  in_pTransition->m_fTargetValue = in_NewTarget;
LABEL_28:
  if ( in_pTransition->m_fTargetValue <= in_pTransition->m_fStartValue && (in_eCurveType - 3) & 0xFFFFFFFD )
    v19 = 8 - in_eCurveType;
  else
    v19 = in_eCurveType;
  in_pTransition->m_eFadeCurve = v19;
  v20 = g_pAudioMgr->m_uBufferTick;
  v21 = (AkAudioLibSettings::g_msPerBufferTick + in_NewDuration - 1) / AkAudioLibSettings::g_msPerBufferTick;
  if ( v8 == in_pTransition->m_eTarget && v9 & 0xF000000 )
  {
    v22 = in_pTransition->m_uStartTimeInBufferTick;
    in_pTransition->m_uLastBufferTickUpdated = v20;
    in_pTransition->m_uStartTimeInBufferTick = v20;
    v23 = in_pTransition->m_uDurationInBufferTick + v22 - v20;
    if ( v21 < v23 )
      v23 = v21;
    in_pTransition->m_uDurationInBufferTick = v23;
  }
  else
  {
    in_pTransition->m_uDurationInBufferTick = v21;
    in_pTransition->m_uLastBufferTickUpdated = v20;
    in_pTransition->m_uStartTimeInBufferTick = v20;
  }
}

// File Line: 407
// RVA: 0xA59A20
void __fastcall CAkTransitionManager::ProcessTransitionsList(CAkTransitionManager *this, unsigned int in_CurrentBufferTick)
{
  unsigned int v2; // ebx
  CAkTransitionManager *v3; // rdi

  v2 = in_CurrentBufferTick;
  v3 = this;
  CAkTransitionManager::ProcessTransitionsList(this, in_CurrentBufferTick, &this->m_ActiveTransitionsList_Fade);
  CAkTransitionManager::ProcessTransitionsList(v3, v2, &v3->m_ActiveTransitionsList_State);
}

// File Line: 415
// RVA: 0xA598F0
void __fastcall CAkTransitionManager::ProcessTransitionsList(CAkTransitionManager *this, unsigned int in_CurrentBufferTick, AkArray<CAkTransition *,CAkTransition *,ArrayPoolDefault,0,AkArrayAllocatorDefault> *in_rTransitionList)
{
  CAkTransition **v3; // rbx
  AkArray<CAkTransition *,CAkTransition *,ArrayPoolDefault,0,AkArrayAllocatorDefault> *v4; // r14
  unsigned int v5; // ebp
  CAkTransition *v6; // rdi
  CAkTransition::State v7; // eax
  int v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // eax
  int v11; // esi

  v3 = in_rTransitionList->m_pItems;
  v4 = in_rTransitionList;
  v5 = in_CurrentBufferTick;
  while ( v3 != &v4->m_pItems[v4->m_uLength] )
  {
    v6 = *v3;
    v7 = (*v3)->m_eState;
    if ( v7 == 6 )
    {
      CAkTransition::Term(*v3);
      v8 = g_DefaultPoolId;
      _((AMD_HD3D *)v6);
      AK::MemoryMgr::Free(v8, v6);
      v9 = v4->m_uLength;
      if ( v9 > 1 )
        *v3 = v4->m_pItems[v9 - 1];
      --v4->m_uLength;
    }
    else
    {
      if ( v7 == 2 )
      {
        v6->m_uLastBufferTickUpdated = v5;
        v6->m_eState = 3;
      }
      else if ( v7 == 4 )
      {
        v6->m_eState = 1;
        v6->m_uStartTimeInBufferTick += v5 - v6->m_uLastBufferTickUpdated;
      }
      if ( v6->m_eState == 1 && CAkTransition::ComputeTransition(v6, v5) )
      {
        CAkTransition::Term(v6);
        v10 = v4->m_uLength;
        if ( v10 > 1 )
          *v3 = v4->m_pItems[v10 - 1];
        --v4->m_uLength;
        v11 = g_DefaultPoolId;
        _((AMD_HD3D *)v6);
        AK::MemoryMgr::Free(v11, v6);
      }
      else
      {
        ++v3;
      }
    }
  }
}

