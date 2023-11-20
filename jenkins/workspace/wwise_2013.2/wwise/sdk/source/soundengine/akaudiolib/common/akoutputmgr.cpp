// File Line: 11
// RVA: 0x15BDF70
__int64 dynamic_initializer_for__CAkOutputMgr::m_Devices__()
{
  return atexit(dynamic_atexit_destructor_for__CAkOutputMgr::m_Devices__);
}

// File Line: 14
// RVA: 0xA4F8F0
void __fastcall AkDevice::~AkDevice(AkDevice *this)
{
  AkDevice *v1; // rdi
  CAkSink *v2; // rcx
  CAkSink *v3; // rbx
  int v4; // esi
  CAkVPLFinalMixNode *v5; // rbx
  int v6; // esi
  unsigned int *v7; // rdx
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v8; // rbx

  v1 = this;
  v2 = this->pSink;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Term)();
    v3 = v1->pSink;
    v4 = g_LEngineDefaultPoolId;
    if ( v3 )
    {
      v3->vfptr->__vecDelDtor(v1->pSink, 0);
      AK::MemoryMgr::Free(v4, v3);
    }
    v1->pSink = 0i64;
  }
  if ( v1->pFinalMix )
  {
    CAkVPLFinalMixNode::Term(v1->pFinalMix);
    v5 = v1->pFinalMix;
    v6 = g_LEngineDefaultPoolId;
    if ( v1->pFinalMix )
    {
      _((AMD_HD3D *)v1->pFinalMix);
      AK::MemoryMgr::Free(v6, v5);
    }
    v1->pFinalMix = 0i64;
  }
  v7 = v1->puSpeakerAngles;
  if ( v7 )
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v7);
  v8 = v1->m_mapConfig2PanPlane.m_pItems;
  if ( v8 != &v8[v1->m_mapConfig2PanPlane.m_uLength] )
  {
    do
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, v8->item);
      ++v8;
    }
    while ( v8 != &v1->m_mapConfig2PanPlane.m_pItems[v1->m_mapConfig2PanPlane.m_uLength] );
  }
  if ( v1->m_mapConfig2PanPlane.m_pItems )
  {
    v1->m_mapConfig2PanPlane.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1->m_mapConfig2PanPlane.m_pItems);
    v1->m_mapConfig2PanPlane.m_pItems = 0i64;
    v1->m_mapConfig2PanPlane.m_ulReserved = 0;
  }
}

// File Line: 46
// RVA: 0xA4FE50
void __fastcall AkDevice::PushData(AkDevice *this)
{
  CAkSink *v1; // rax
  AkDevice *v2; // rdi
  signed __int64 v3; // rbx
  CAkSinkVtbl *v4; // rax

  v1 = this->pSink;
  v2 = this;
  v3 = (signed __int64)&v1->m_MasterOut;
  v1->m_MasterOut.uValidFrames = 0;
  v1->m_MasterOut.uValidFrames = 0;
  CAkVPLFinalMixNode::GetResultingBuffer(this->pFinalMix, &v1->m_MasterOut);
  v4 = v2->pSink->vfptr;
  if ( *(_WORD *)(v3 + 18) )
    ((void (*)(void))v4->PassData)();
  else
    ((void (*)(void))v4->PassSilence)();
}

// File Line: 65
// RVA: 0xA50060
signed __int64 __fastcall AkDevice::SetSpeakerAngles(AkDevice *this, const float *in_pfSpeakerAngles, unsigned int in_uNumAngles)
{
  unsigned int v3; // er12
  AkDevice *v4; // rbx
  const float *v5; // r15
  unsigned __int64 v6; // rsi
  __int64 v7; // rdi
  unsigned int *v8; // r14
  signed __int64 v10; // rax
  void *v11; // rsp
  unsigned int i; // er9
  __int64 v13; // r8
  signed int v14; // edx
  unsigned int v15; // edi
  unsigned int *v16; // rdx
  signed int v17; // eax
  char Dst[32]; // [rsp+20h] [rbp+0h]
  unsigned int out_uMinAngleBetweenSpeakers; // [rsp+60h] [rbp+40h]

  v3 = in_uNumAngles;
  if ( this->uNumAngles > in_uNumAngles )
    v3 = this->uNumAngles;
  v4 = this;
  v5 = in_pfSpeakerAngles;
  v6 = 4i64 * v3;
  v7 = in_uNumAngles;
  v8 = (unsigned int *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 4i64 * v3);
  if ( !v8 )
    return 2i64;
  v10 = v6 + 15;
  if ( v6 + 15 <= v6 )
    v10 = 1152921504606846960i64;
  v11 = alloca(v10);
  if ( (_DWORD)v7 )
    memmove(Dst, v5, 4 * v7);
  for ( i = v7; i < v4->uNumAngles; *(float *)&Dst[4 * v13] = (float)((float)v14 * 360.0) * 0.001953125 )
  {
    v13 = i;
    v14 = v4->puSpeakerAngles[i++];
  }
  v15 = CAkSpeakerPan::SetSpeakerAngles((const float *)Dst, v7, v8, &out_uMinAngleBetweenSpeakers);
  if ( v15 == 1 )
  {
    v16 = v4->puSpeakerAngles;
    if ( v16 )
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v16);
    v17 = out_uMinAngleBetweenSpeakers;
    v4->puSpeakerAngles = v8;
    v4->uNumAngles = v3;
    v4->fOneOverMinAngleBetweenSpeakers = 1.0 / (float)v17;
  }
  else
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v8);
  }
  return v15;
}

// File Line: 111
// RVA: 0xA4FC50
signed __int64 __fastcall AkDevice::CreatePanCache(AkDevice *this, unsigned int in_uOutputConfig)
{
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v2; // rax
  unsigned int v3; // esi
  AkDevice *v4; // rbp
  signed __int64 v5; // rdi
  _QWORD *v6; // rdi
  MapStruct<unsigned __int64,AkVPL *> *v7; // rax
  CAkSpeakerPan::PanPair *v8; // rax
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v10; // rdi
  signed __int64 v11; // rax

  v2 = this->m_mapConfig2PanPlane.m_pItems;
  v3 = in_uOutputConfig;
  v4 = this;
  v5 = (signed __int64)&v2[this->m_mapConfig2PanPlane.m_uLength];
  if ( v2 == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v5 )
    goto LABEL_25;
  do
  {
    if ( v2->key == in_uOutputConfig )
      break;
    ++v2;
  }
  while ( v2 != (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v5 );
  if ( v2 == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v5 )
  {
LABEL_25:
    v6 = 0i64;
    goto LABEL_8;
  }
  v6 = &v2->item;
  if ( v2 == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)-8i64 )
  {
LABEL_8:
    v7 = AkArray<CAkRanSeqCntr::CntrInfoEntry,CAkRanSeqCntr::CntrInfoEntry const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<unsigned __int64,AkVPL *>,MapStruct<unsigned __int64,AkVPL *> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)&this->m_mapConfig2PanPlane);
    if ( v7 )
    {
      LODWORD(v7->key) = v3;
      v6 = &v7->item;
    }
    if ( !v6 )
      goto LABEL_15;
  }
  v8 = (CAkSpeakerPan::PanPair *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x808ui64);
  *v6 = v8;
  if ( v8 )
    CAkSpeakerPan::CreatePanCache(v3, v4->puSpeakerAngles, v8);
  if ( *v6 )
    return 1i64;
LABEL_15:
  v10 = v4->m_mapConfig2PanPlane.m_pItems;
  v11 = (signed __int64)&v10[v4->m_mapConfig2PanPlane.m_uLength];
  if ( v10 != (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v11 )
  {
    do
    {
      if ( v10->key == v3 )
        break;
      ++v10;
    }
    while ( v10 != (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v11 );
    if ( v10 != (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v11 )
    {
      if ( (unsigned __int64)v10 < v11 - 16 )
        qmemcpy(
          v10,
          &v10[1],
          8
        * (((((unsigned __int64)(v11 - 16 - (_QWORD)v10 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
      --v4->m_mapConfig2PanPlane.m_uLength;
    }
  }
  return 2i64;
}

// File Line: 129
// RVA: 0xA50330
void CAkOutputMgr::Term(void)
{
  AkDevice *v0; // rbx
  AkDevice *v1; // rdi

  v0 = CAkOutputMgr::m_Devices.m_pItems;
  if ( CAkOutputMgr::m_Devices.m_pItems )
  {
    v1 = &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength];
    if ( CAkOutputMgr::m_Devices.m_pItems != v1 )
    {
      do
      {
        AkDevice::~AkDevice(v0);
        ++v0;
      }
      while ( v0 != v1 );
      v0 = CAkOutputMgr::m_Devices.m_pItems;
    }
    CAkOutputMgr::m_Devices.m_uLength = 0;
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v0);
    CAkOutputMgr::m_Devices.m_pItems = 0i64;
    CAkOutputMgr::m_Devices.m_ulReserved = 0;
  }
}

// File Line: 134
// RVA: 0xA503B0
signed __int64 __fastcall CAkOutputMgr::_AddOutputDevice(unsigned __int64 in_uKey, AkOutputSettings *in_settings, AkSinkType in_eSinkType, unsigned int in_uDeviceInstance, unsigned int in_uListeners, void *in_pUserData)
{
  unsigned int v6; // er10
  unsigned int v7; // er11
  unsigned int v8; // er15
  AkSinkType v9; // er12
  AkOutputSettings *v10; // r13
  unsigned __int64 v11; // r14
  unsigned __int64 v12; // rbx
  AkDevice *v13; // rsi
  unsigned int v14; // edi
  AkDevice *v15; // rcx
  CAkSink *v16; // rax
  bool v17; // bl
  CAkBusFX *v18; // rax
  AkDevice *v19; // rdi
  AkDevice *v20; // rax
  unsigned __int64 v21; // rbx
  signed int v23; // ecx
  unsigned int v24; // edi
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  signed __int64 v27; // rcx
  void *v28; // rsp
  void *v29; // rsp
  AKRESULT v30; // edi
  float out_angles; // [rsp+20h] [rbp+0h]

  v6 = CAkOutputMgr::m_Devices.m_uLength;
  v7 = CAkOutputMgr::m_Devices.m_ulReserved;
  v8 = in_uDeviceInstance;
  v9 = in_eSinkType;
  v10 = in_settings;
  v11 = in_uKey;
  v12 = CAkOutputMgr::m_Devices.m_uLength;
  if ( CAkOutputMgr::m_Devices.m_uLength >= (unsigned __int64)CAkOutputMgr::m_Devices.m_ulReserved )
  {
    if ( !AkArray<AkDevice,AkDevice &,ArrayPoolLEngineDefault,1,AkArrayAllocatorDefault>::GrowArray(
            &CAkOutputMgr::m_Devices,
            1u) )
      return 52i64;
    v7 = CAkOutputMgr::m_Devices.m_ulReserved;
    v6 = CAkOutputMgr::m_Devices.m_uLength;
  }
  if ( v12 >= v7 )
    return 52i64;
  CAkOutputMgr::m_Devices.m_uLength = v6 + 1;
  v13 = &CAkOutputMgr::m_Devices.m_pItems[v6];
  if ( !v13 )
    return 52i64;
  v14 = 0;
  v15 = &CAkOutputMgr::m_Devices.m_pItems[v6];
  v13->m_mapConfig2PanPlane.m_pItems = 0i64;
  *(_QWORD *)&v13->m_mapConfig2PanPlane.m_uLength = 0i64;
  memset(v15, 0, 0x50ui64);
  v16 = CAkSink::Create(v10, v9, v8);
  v13->pSink = v16;
  v17 = v16 == 0i64;
  v18 = (CAkBusFX *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x540ui64);
  v13->pFinalMix = (CAkVPLFinalMixNode *)v18;
  if ( v18 )
    CAkBusFX::CAkBusFX(v18);
  if ( v17 || v13->pFinalMix == 0i64 )
  {
    v19 = &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength - 1];
    v20 = &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength - 1];
    if ( v20 < v19 )
    {
      do
      {
        v21 = (unsigned __int64)&v20[1];
        AkDevice::operator=(v20, v20 + 1);
        v20 = (AkDevice *)v21;
      }
      while ( v21 < (unsigned __int64)v19 );
    }
    AkDevice::~AkDevice(v19);
    --CAkOutputMgr::m_Devices.m_uLength;
    return 52i64;
  }
  v23 = 1587;
  do
  {
    ++v14;
    v23 &= v23 - 1;
  }
  while ( v23 );
  v24 = v14 >> 1;
  v25 = 4i64 * v24;
  v26 = v25 + 15;
  if ( v25 + 15 <= v25 )
    v26 = 1152921504606846960i64;
  v27 = v26 & 0xFFFFFFFFFFFFFFF0ui64;
  v28 = alloca(v27);
  v29 = alloca(v27);
  CAkSpeakerPan::GetDefaultSpeakerAngles(v13->pSink->m_SpeakersConfig, &out_angles);
  if ( (unsigned int)AkDevice::SetSpeakerAngles(v13, &out_angles, v24) != 1 )
    return 2i64;
  v13->uDeviceID = v11;
  v13->uListeners = in_uListeners;
  v13->pUserData = in_pUserData;
  v13->ePanningRule = v10->ePanningRule;
  CAkOutputMgr::SetListenersOnDevice(in_uListeners, v11);
  CAkListener::RouteListenersToDevice(in_uListeners, v11);
  v30 = CAkVPLFinalMixNode::Init(v13->pFinalMix, v13->pSink->m_SpeakersConfig);
  if ( v30 == 1 )
    CAkLEngine::ReevaluateBussesForDevice(v11, in_uListeners);
  return (unsigned int)v30;
}

// File Line: 189
// RVA: 0xA4FB80
AKRESULT __fastcall CAkOutputMgr::AddMainDevice(AkOutputSettings *in_outputSettings, AkSinkType in_eSinkType, unsigned int in_uListeners, void *in_pUserData)
{
  return CAkOutputMgr::_AddOutputDevice(0i64, in_outputSettings, in_eSinkType, 0, in_uListeners, in_pUserData);
}

// File Line: 194
// RVA: 0xA4FBB0
AKRESULT __fastcall CAkOutputMgr::AddOutputDevice(AkOutputSettings *in_settings, AkSinkType in_eSinkType, unsigned int in_uDeviceInstance, unsigned int in_uListeners, void *in_pUserData)
{
  AkOutputSettings *v5; // rdi
  unsigned __int64 v6; // r10
  AKRESULT result; // eax
  __int64 v8; // rax
  unsigned __int64 *v9; // rcx

  v5 = in_settings;
  v6 = (signed int)in_eSinkType | ((unsigned __int64)in_uDeviceInstance << 32);
  if ( !v6 )
    return 2;
  v8 = 0i64;
  if ( !CAkOutputMgr::m_Devices.m_uLength )
    goto LABEL_7;
  v9 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
  while ( *v9 != v6 )
  {
    v8 = (unsigned int)(v8 + 1);
    v9 += 10;
    if ( (unsigned int)v8 >= CAkOutputMgr::m_Devices.m_uLength )
      goto LABEL_7;
  }
  if ( &CAkOutputMgr::m_Devices.m_pItems[v8] )
    result = 1;
  else
LABEL_7:
    result = CAkOutputMgr::_AddOutputDevice(v6, v5, in_eSinkType, in_uDeviceInstance, in_uListeners, in_pUserData);
  return result;
}

// File Line: 210
// RVA: 0xA4FEB0
signed __int64 __fastcall CAkOutputMgr::RemoveOutputDevice(unsigned __int64 in_uDeviceID)
{
  AkDevice *v1; // rbx
  AkDevice *v2; // rdx
  unsigned int v4; // eax

  v1 = CAkOutputMgr::m_Devices.m_pItems;
  v2 = &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength];
  if ( CAkOutputMgr::m_Devices.m_pItems == v2 )
    return 2i64;
  while ( v1->uDeviceID != in_uDeviceID )
  {
    ++v1;
    if ( v1 == v2 )
      return 2i64;
  }
  CAkLEngine::ReevaluateBussesForDevice(in_uDeviceID, 0);
  v4 = CAkOutputMgr::m_Devices.m_uLength;
  if ( CAkOutputMgr::m_Devices.m_uLength > 1 )
  {
    AkDevice::~AkDevice(v1);
    AkDevice::operator=(v1, &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength - 1]);
    v4 = CAkOutputMgr::m_Devices.m_uLength;
  }
  CAkOutputMgr::m_Devices.m_uLength = v4 - 1;
  return 1i64;
}

// File Line: 226
// RVA: 0xA50000
signed __int64 __fastcall CAkOutputMgr::SetListenersOnDevice(unsigned int in_uListeners, unsigned __int64 in_uDeviceID)
{
  unsigned int v2; // er11
  __int64 v3; // rax
  unsigned __int64 *v4; // r8
  signed __int64 result; // rax
  __int64 v6; // rcx

  v2 = in_uListeners;
  CAkOutputMgr::m_Devices.m_pItems->uListeners &= ~in_uListeners;
  v3 = 0i64;
  if ( !CAkOutputMgr::m_Devices.m_uLength )
    return 2i64;
  v4 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
  while ( *v4 != in_uDeviceID )
  {
    v3 = (unsigned int)(v3 + 1);
    v4 += 10;
    if ( (unsigned int)v3 >= CAkOutputMgr::m_Devices.m_uLength )
      return 2i64;
  }
  v6 = v3;
  result = 1i64;
  CAkOutputMgr::m_Devices.m_pItems[v6].uListeners = v2;
  return result;
}

// File Line: 243
// RVA: 0xA4FF50
signed __int64 __fastcall CAkOutputMgr::ReplaceSink(unsigned __int64 in_uDeviceID, CAkSink *in_pSink)
{
  AkDevice *v2; // rbx
  CAkSink *v3; // rbp
  AkDevice *v4; // r8
  CAkSink *v6; // rdi
  int v7; // esi

  v2 = CAkOutputMgr::m_Devices.m_pItems;
  v3 = in_pSink;
  v4 = &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength];
  if ( CAkOutputMgr::m_Devices.m_pItems == v4 )
    return 2i64;
  while ( v2->uDeviceID != in_uDeviceID )
  {
    ++v2;
    if ( v2 == v4 )
      return 2i64;
  }
  ((void (*)(void))v2->pSink->vfptr->Term)();
  v6 = v2->pSink;
  v7 = g_LEngineDefaultPoolId;
  if ( v6 )
  {
    v6->vfptr->__vecDelDtor(v6, 0);
    AK::MemoryMgr::Free(v7, v6);
  }
  v2->pSink = v3;
  return 1i64;
}

// File Line: 259
// RVA: 0xA501B0
void __fastcall CAkOutputMgr::StartOutputCapture(const wchar_t *in_CaptureFileName)
{
  const wchar_t *v1; // rsi
  signed __int64 v2; // rbx
  unsigned __int64 v4; // rcx
  signed __int64 v5; // rcx
  void *v6; // rsp
  void *v7; // rsp
  signed __int64 v8; // rdi
  char *v9; // r15
  AkDevice *v10; // rbx
  char i; // di
  const wchar_t *v12; // rdx
  char Dst[16]; // [rsp+20h] [rbp+0h]

  v1 = in_CaptureFileName;
  v2 = -1i64;
  while ( in_CaptureFileName[v2++ + 1] != 0 )
    ;
  v4 = 2 * v2 + 19;
  if ( v4 <= 2 * v2 + 4 )
    v4 = 1152921504606846960i64;
  v5 = v4 & 0xFFFFFFFFFFFFFFF0ui64;
  v6 = alloca(v5);
  v7 = alloca(v5);
  v8 = 2 * v2;
  memmove(Dst, v1, 2 * v2);
  v9 = &Dst[2 * v2];
  *(_WORD *)&Dst[v8] = *(_WORD *)&Dst[v8 - 2];
  *(_WORD *)&Dst[v8 - 2] = *(_WORD *)&Dst[2 * v2 - 4];
  *(_WORD *)&Dst[2 * v2 - 4] = *(_WORD *)&Dst[2 * v2 - 6];
  *(_WORD *)&Dst[2 * v2 - 6] = *((_WORD *)v9 - 4);
  *(_WORD *)&Dst[v8 + 2] = 0;
  v10 = CAkOutputMgr::m_Devices.m_pItems;
  for ( i = 0; v10 != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength]; ++v10 )
  {
    if ( v10->uDeviceID )
    {
      ++i;
      v12 = (const wchar_t *)Dst;
      *((_WORD *)v9 - 4) = i + 48;
    }
    else
    {
      v12 = v1;
    }
    CAkSink::StartOutputCapture(v10->pSink, v12);
  }
}

// File Line: 285
// RVA: 0xA502E0
void CAkOutputMgr::StopOutputCapture(void)
{
  AkDevice *i; // rbx

  for ( i = CAkOutputMgr::m_Devices.m_pItems; i != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength]; ++i )
    CAkSink::StopOutputCapture(i->pSink);
}

