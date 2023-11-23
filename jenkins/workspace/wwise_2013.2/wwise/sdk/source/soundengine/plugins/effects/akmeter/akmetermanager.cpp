// File Line: 22
// RVA: 0xAF6010
void __fastcall CAkMeterManager::CAkMeterManager(CAkMeterManager *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  this->m_pAllocator = in_pAllocator;
  this->m_meters.m_ulNumListItems = 0;
  this->m_meters.m_pFirst = 0i64;
  this->m_meters.m_pLast = 0i64;
  CAkMeterManager::pInstance = this;
  AK::SoundEngine::AddBehavioralExtension(CAkMeterManager::BehavioralExtension);
}

// File Line: 28
// RVA: 0xAF6050
void __fastcall CAkMeterManager::~CAkMeterManager(CAkMeterManager *this)
{
  AK::SoundEngine::RemoveBehavioralExtension(CAkMeterManager::BehavioralExtension);
  this->m_meters.m_pFirst = 0i64;
  this->m_meters.m_pLast = 0i64;
  this->m_meters.m_ulNumListItems = 0;
  CAkMeterManager::pInstance = 0i64;
}

// File Line: 36
// RVA: 0xAF6100
void __fastcall CAkMeterManager::Execute(CAkMeterManager *this, bool in_bLastCall)
{
  unsigned __int64 v2; // rax
  __int64 v4; // rcx
  void *v5; // rsp
  CAkMeterFX *m_pFirst; // rdi
  void *v7; // rsp
  int v8; // r13d
  __int128 v9; // rax
  __int64 v10; // r14
  float fLastValue; // xmm6_4
  unsigned int m_uGameParamID; // r12d
  AK::IAkPluginVtbl *vfptr; // rax
  AK::IAkPluginMemAlloc *m_pAllocator; // rbx
  int v15; // ecx
  __int64 v16; // rax
  float v17; // xmm0_4
  __int64 i; // rbx
  unsigned int v19; // edx
  float v20; // xmm2_4
  int v21; // ebx
  __int128 v22; // [rsp+30h] [rbp+0h] BYREF
  __int128 v23; // [rsp+40h] [rbp+10h]
  TransParams in_transParams; // [rsp+90h] [rbp+60h] BYREF

  v2 = 8i64 * this->m_meters.m_ulNumListItems;
  v4 = v2 + 15;
  if ( v2 + 15 <= v2 )
    v4 = 0xFFFFFFFFFFFFFF0i64;
  v5 = alloca(v4 & 0xFFFFFFFFFFFFFFF0ui64);
  m_pFirst = this->m_meters.m_pFirst;
  v7 = alloca(v4 & 0xFFFFFFFFFFFFFFF0ui64);
  v8 = 0;
  *((_QWORD *)&v9 + 1) = 0i64;
  v10 = 0i64;
  while ( m_pFirst )
  {
    fLastValue = m_pFirst->m_state.fLastValue;
    m_uGameParamID = m_pFirst->m_uGameParamID;
    if ( m_pFirst->m_bTerminated )
    {
      *(_QWORD *)&v9 = m_pFirst->pNextItem;
      fLastValue = m_pFirst->m_fMin;
      v22 = v9;
      if ( m_pFirst == this->m_meters.m_pFirst )
        this->m_meters.m_pFirst = (CAkMeterFX *)v9;
      else
        *(_QWORD *)(*((_QWORD *)&v9 + 1) + 8i64) = v9;
      if ( m_pFirst == this->m_meters.m_pLast )
        this->m_meters.m_pLast = (CAkMeterFX *)*((_QWORD *)&v9 + 1);
      --this->m_meters.m_ulNumListItems;
      vfptr = m_pFirst->vfptr;
      m_pAllocator = this->m_pAllocator;
      v23 = v22;
      vfptr->__vecDelDtor(m_pFirst, 0);
      m_pAllocator->vfptr->Free(m_pAllocator, m_pFirst);
      *((_QWORD *)&v9 + 1) = *((_QWORD *)&v23 + 1);
      m_pFirst = (CAkMeterFX *)v23;
    }
    else
    {
      *((_QWORD *)&v9 + 1) = m_pFirst;
      m_pFirst = m_pFirst->pNextItem;
    }
    if ( m_uGameParamID )
    {
      v15 = 0;
      v16 = 0i64;
      if ( v10 > 0 )
      {
        while ( *((_DWORD *)&v22 + 2 * v16) != m_uGameParamID )
        {
          ++v16;
          ++v15;
          if ( v16 >= v10 )
            goto LABEL_20;
        }
        v17 = *((float *)&v22 + 2 * v16 + 1);
        if ( v17 <= fLastValue )
          v17 = fLastValue;
        *((float *)&v22 + 2 * v16 + 1) = v17;
      }
LABEL_20:
      if ( v15 == v8 )
      {
        *((float *)&v22 + 2 * v10 + 1) = fLastValue;
        *((_DWORD *)&v22 + 2 * v10) = m_uGameParamID;
        ++v8;
        ++v10;
      }
    }
  }
  for ( i = 0i64; i < v8; ++i )
  {
    v19 = *((_DWORD *)&v22 + 2 * i);
    v20 = *((float *)&v22 + 2 * i + 1);
    in_transParams.TransitionTime = 0;
    in_transParams.eFadeCurve = AkCurveInterpolation_Linear;
    CAkRTPCMgr::SetRTPCInternal(g_pRTPCMgr, v19, v20, 0i64, &in_transParams, AkValueMeaning_Independent);
  }
  if ( !this->m_meters.m_pFirst )
  {
    v21 = g_LEngineDefaultPoolId;
    AK::SoundEngine::RemoveBehavioralExtension(CAkMeterManager::BehavioralExtension);
    this->m_meters.m_pFirst = 0i64;
    this->m_meters.m_pLast = 0i64;
    this->m_meters.m_ulNumListItems = 0;
    CAkMeterManager::pInstance = 0i64;
    AK::MemoryMgr::Free(v21, this);
  }
}

// File Line: 112
// RVA: 0xAF6090
CAkMeterManager *__fastcall CAkMeterManager::Instance(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkMeterManager *result; // rax

  result = CAkMeterManager::pInstance;
  if ( !CAkMeterManager::pInstance )
  {
    result = (CAkMeterManager *)AK::MemoryMgr::Malloc(
                                  g_LEngineDefaultPoolId,
                                  (unsigned int)((_DWORD)CAkMeterManager::pInstance + 32));
    if ( result )
    {
      result->m_pAllocator = in_pAllocator;
      result->m_meters.m_ulNumListItems = 0;
      result->m_meters.m_pFirst = 0i64;
      result->m_meters.m_pLast = 0i64;
      CAkMeterManager::pInstance = result;
      AK::SoundEngine::AddBehavioralExtension(CAkMeterManager::BehavioralExtension);
      return CAkMeterManager::pInstance;
    }
  }
  return result;
}

