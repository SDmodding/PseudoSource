// File Line: 97
// RVA: 0xA43D60
__int64 __fastcall AK::SoundEngine::Query::GetRTPCValue(
        unsigned int in_RTPCid,
        unsigned __int64 in_GameObj,
        float *out_rfValue,
        AK::SoundEngine::Query::RTPCValue_type *io_rValueType)
{
  CAkRegisteredObj *ObjAndAddref; // rdi
  bool RTPCValue; // r15
  int v10; // edx
  int v11; // ebx
  float DefaultValue; // xmm0_4
  AK::SoundEngine::Query::RTPCValue_type v13; // eax
  bool out_pbWasFound; // [rsp+30h] [rbp-38h] BYREF
  bool out_bGameObjectSpecificValue; // [rsp+88h] [rbp+20h] BYREF

  EnterCriticalSection(&g_csMain.m_csLock);
  if ( *io_rValueType == RTPCValue_Global )
  {
    in_GameObj = -1i64;
  }
  else if ( *io_rValueType != RTPCValue_GameObject )
  {
LABEL_9:
    DefaultValue = CAkRTPCMgr::GetDefaultValue(g_pRTPCMgr, in_RTPCid, &out_pbWasFound);
    v13 = RTPCValue_Unavailable;
    if ( out_pbWasFound )
      v13 = RTPCValue_Default;
    *out_rfValue = DefaultValue;
    *io_rValueType = v13;
    goto LABEL_12;
  }
  ObjAndAddref = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, in_GameObj);
  RTPCValue = CAkRTPCMgr::GetRTPCValue(g_pRTPCMgr, in_RTPCid, ObjAndAddref, out_rfValue, &out_bGameObjectSpecificValue);
  *io_rValueType = out_bGameObjectSpecificValue + 1;
  if ( ObjAndAddref )
  {
    v10 = *((_DWORD *)ObjAndAddref + 30) ^ (*((_DWORD *)ObjAndAddref + 30) ^ (*((_DWORD *)ObjAndAddref + 30) - 1)) & 0x3FFFFFFF;
    *((_DWORD *)ObjAndAddref + 30) = v10;
    if ( (v10 & 0x3FFFFFFF) == 0 )
    {
      v11 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj(ObjAndAddref);
      AK::MemoryMgr::Free(v11, ObjAndAddref);
    }
  }
  if ( !RTPCValue )
    goto LABEL_9;
LABEL_12:
  LeaveCriticalSection(&g_csMain.m_csLock);
  return 1i64;
}

// File Line: 213
// RVA: 0xA43E80
__int64 __fastcall AK::SoundEngine::Query::GetState(unsigned int in_StateGroup, unsigned int *out_rState)
{
  EnterCriticalSection(&g_csMain.m_csLock);
  *out_rState = CAkStateMgr::GetState(g_pStateMgr, in_StateGroup);
  LeaveCriticalSection(&g_csMain.m_csLock);
  return 1i64;
}

