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
  CAkMeterManager *v1; // rbx

  v1 = this;
  AK::SoundEngine::RemoveBehavioralExtension(CAkMeterManager::BehavioralExtension);
  v1->m_meters.m_pFirst = 0i64;
  v1->m_meters.m_pLast = 0i64;
  v1->m_meters.m_ulNumListItems = 0;
  CAkMeterManager::pInstance = 0i64;
}

// File Line: 36
// RVA: 0xAF6100
void __fastcall CAkMeterManager::Execute(CAkMeterManager *this, bool in_bLastCall)
{
  unsigned __int64 v2; // rax
  CAkMeterManager *v3; // r15
  signed __int64 v4; // rcx
  void *v5; // rsp
  CAkMeterFX *v6; // rdi
  void *v7; // rsp
  int v8; // er13
  __m128i v9; // ax
  __int64 v10; // r14
  float v11; // xmm6_4
  int v12; // er12
  AK::IAkPluginVtbl *v13; // rax
  AK::IAkPluginMemAlloc *v14; // rbx
  int v15; // ecx
  __int64 v16; // rax
  float v17; // xmm0_4
  signed __int64 v18; // rbx
  unsigned int v19; // edx
  float v20; // xmm2_4
  int v21; // ebx
  __m128i v22; // [rsp+30h] [rbp+0h]
  __int128 v23; // [rsp+40h] [rbp+10h]
  TransParams in_transParams; // [rsp+90h] [rbp+60h]

  v2 = 8i64 * this->m_meters.m_ulNumListItems;
  v3 = this;
  v4 = v2 + 15;
  if ( v2 + 15 <= v2 )
    v4 = 1152921504606846960i64;
  v5 = alloca(v4);
  v6 = v3->m_meters.m_pFirst;
  v7 = alloca(v4);
  v8 = 0;
  v9.m128i_i64[1] = 0i64;
  v10 = 0i64;
  while ( v6 )
  {
    v11 = v6->m_state.fLastValue;
    v12 = v6->m_uGameParamID;
    if ( v6->m_bTerminated )
    {
      v9.m128i_i64[0] = (__int64)v6->pNextItem;
      v11 = v6->m_fMin;
      v22 = v9;
      if ( v6 == v3->m_meters.m_pFirst )
        v3->m_meters.m_pFirst = (CAkMeterFX *)v9.m128i_i64[0];
      else
        *(_QWORD *)(v9.m128i_i64[1] + 8) = v9.m128i_i64[0];
      if ( v6 == v3->m_meters.m_pLast )
        v3->m_meters.m_pLast = (CAkMeterFX *)v9.m128i_i64[1];
      --v3->m_meters.m_ulNumListItems;
      v13 = v6->vfptr;
      v14 = v3->m_pAllocator;
      _mm_store_si128((__m128i *)&v23, v22);
      v13->__vecDelDtor((AK::IAkPlugin *)&v6->vfptr, 0);
      v14->vfptr->Free(v14, v6);
      v9.m128i_i64[1] = *((_QWORD *)&v23 + 1);
      v6 = (CAkMeterFX *)v23;
    }
    else
    {
      v9.m128i_i64[1] = (__int64)v6;
      v6 = v6->pNextItem;
    }
    if ( v12 )
    {
      v15 = 0;
      v16 = 0i64;
      if ( v10 > 0 )
      {
        while ( v22.m128i_i32[2 * v16] != v12 )
        {
          ++v16;
          ++v15;
          if ( v16 >= v10 )
            goto LABEL_20;
        }
        v17 = *(float *)&v22.m128i_i32[2 * v16 + 1];
        if ( v17 <= v11 )
          v17 = v11;
        *(float *)&v22.m128i_i32[2 * v16 + 1] = v17;
      }
LABEL_20:
      if ( v15 == v8 )
      {
        *(float *)&v22.m128i_i32[2 * v10 + 1] = v11;
        v22.m128i_i32[2 * v10] = v12;
        ++v8;
        ++v10;
      }
    }
  }
  v18 = 0i64;
  if ( v8 > 0 )
  {
    do
    {
      v19 = v22.m128i_u32[2 * v18];
      v20 = *(float *)&v22.m128i_i32[2 * v18 + 1];
      in_transParams.TransitionTime = 0;
      in_transParams.eFadeCurve = 4;
      CAkRTPCMgr::SetRTPCInternal(g_pRTPCMgr, v19, v20, 0i64, &in_transParams, AkValueMeaning_Independent);
      ++v18;
    }
    while ( v18 < v8 );
  }
  if ( !v3->m_meters.m_pFirst )
  {
    v21 = g_LEngineDefaultPoolId;
    AK::SoundEngine::RemoveBehavioralExtension(CAkMeterManager::BehavioralExtension);
    v3->m_meters.m_pFirst = 0i64;
    v3->m_meters.m_pLast = 0i64;
    v3->m_meters.m_ulNumListItems = 0;
    CAkMeterManager::pInstance = 0i64;
    AK::MemoryMgr::Free(v21, v3);
  }
}

// File Line: 112
// RVA: 0xAF6090
CAkMeterManager *__fastcall CAkMeterManager::Instance(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkMeterManager *result; // rax
  AK::IAkPluginMemAlloc *v2; // rbx

  result = CAkMeterManager::pInstance;
  v2 = in_pAllocator;
  if ( !CAkMeterManager::pInstance )
  {
    result = (CAkMeterManager *)AK::MemoryMgr::Malloc(
                                  g_LEngineDefaultPoolId,
                                  (unsigned int)((_DWORD)CAkMeterManager::pInstance + 32));
    if ( result )
    {
      result->m_pAllocator = v2;
      result->m_meters.m_ulNumListItems = 0;
      result->m_meters.m_pFirst = 0i64;
      result->m_meters.m_pLast = 0i64;
      CAkMeterManager::pInstance = result;
      AK::SoundEngine::AddBehavioralExtension(CAkMeterManager::BehavioralExtension);
      result = CAkMeterManager::pInstance;
    }
  }
  return result;
}

