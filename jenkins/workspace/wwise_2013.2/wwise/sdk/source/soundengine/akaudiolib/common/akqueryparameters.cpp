// File Line: 97
// RVA: 0xA43D60
signed __int64 __fastcall AK::SoundEngine::Query::GetRTPCValue(unsigned int in_RTPCid, unsigned __int64 in_GameObj, float *out_rfValue, AK::SoundEngine::Query::RTPCValue_type *io_rValueType)
{
  unsigned int v4; // er14
  AK::SoundEngine::Query::RTPCValue_type *v5; // rsi
  float *v6; // rbp
  signed __int64 v7; // rbx
  CAkRegisteredObj *v8; // rdi
  bool v9; // r15
  int v10; // edx
  int v11; // ebx
  float v12; // xmm0_4
  signed int v13; // eax
  bool out_pbWasFound; // [rsp+30h] [rbp-38h]
  bool out_bGameObjectSpecificValue; // [rsp+88h] [rbp+20h]

  v4 = in_RTPCid;
  v5 = io_rValueType;
  v6 = out_rfValue;
  v7 = in_GameObj;
  EnterCriticalSection(&g_csMain.m_csLock);
  if ( *v5 == 1 )
  {
    v7 = -1i64;
  }
  else if ( *v5 != 2 )
  {
LABEL_9:
    v12 = CAkRTPCMgr::GetDefaultValue(g_pRTPCMgr, v4, &out_pbWasFound);
    v13 = 3;
    if ( out_pbWasFound )
      v13 = 0;
    *v6 = v12;
    *v5 = v13;
    goto LABEL_12;
  }
  v8 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, v7);
  v9 = CAkRTPCMgr::GetRTPCValue(g_pRTPCMgr, v4, v8, v6, &out_bGameObjectSpecificValue);
  *v5 = (out_bGameObjectSpecificValue != 0) + 1;
  if ( v8 )
  {
    v10 = *((_DWORD *)v8 + 30) ^ (*((_DWORD *)v8 + 30) ^ (*((_DWORD *)v8 + 30) - 1)) & 0x3FFFFFFF;
    *((_DWORD *)v8 + 30) = v10;
    if ( !(v10 & 0x3FFFFFFF) )
    {
      v11 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj(v8);
      AK::MemoryMgr::Free(v11, v8);
    }
  }
  if ( !v9 )
    goto LABEL_9;
LABEL_12:
  LeaveCriticalSection(&g_csMain.m_csLock);
  return 1i64;
}

// File Line: 213
// RVA: 0xA43E80
signed __int64 __fastcall AK::SoundEngine::Query::GetState(unsigned int in_StateGroup, unsigned int *out_rState)
{
  unsigned int v2; // ebx
  unsigned int *v3; // rdi

  v2 = in_StateGroup;
  v3 = out_rState;
  EnterCriticalSection(&g_csMain.m_csLock);
  *v3 = CAkStateMgr::GetState(g_pStateMgr, v2);
  LeaveCriticalSection(&g_csMain.m_csLock);
  return 1i64;
}

