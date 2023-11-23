// File Line: 11
// RVA: 0x15BDF70
__int64 dynamic_initializer_for__CAkOutputMgr::m_Devices__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkOutputMgr::m_Devices__);
}

// File Line: 14
// RVA: 0xA4F8F0
void __fastcall AkDevice::~AkDevice(AkDevice *this)
{
  CAkSink *pSink; // rcx
  CAkSink *v3; // rbx
  int v4; // esi
  CAkVPLFinalMixNode *pFinalMix; // rbx
  int v6; // esi
  unsigned int *puSpeakerAngles; // rdx
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *m_pItems; // rbx

  pSink = this->pSink;
  if ( pSink )
  {
    pSink->vfptr->Term(pSink);
    v3 = this->pSink;
    v4 = g_LEngineDefaultPoolId;
    if ( v3 )
    {
      v3->vfptr->__vecDelDtor(this->pSink, 0);
      AK::MemoryMgr::Free(v4, v3);
    }
    this->pSink = 0i64;
  }
  if ( this->pFinalMix )
  {
    CAkVPLFinalMixNode::Term(this->pFinalMix);
    pFinalMix = this->pFinalMix;
    v6 = g_LEngineDefaultPoolId;
    if ( this->pFinalMix )
    {
      _((AMD_HD3D *)this->pFinalMix);
      AK::MemoryMgr::Free(v6, pFinalMix);
    }
    this->pFinalMix = 0i64;
  }
  puSpeakerAngles = this->puSpeakerAngles;
  if ( puSpeakerAngles )
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, puSpeakerAngles);
  m_pItems = this->m_mapConfig2PanPlane.m_pItems;
  if ( m_pItems != &m_pItems[this->m_mapConfig2PanPlane.m_uLength] )
  {
    do
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems->item);
      ++m_pItems;
    }
    while ( m_pItems != &this->m_mapConfig2PanPlane.m_pItems[this->m_mapConfig2PanPlane.m_uLength] );
  }
  if ( this->m_mapConfig2PanPlane.m_pItems )
  {
    this->m_mapConfig2PanPlane.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_mapConfig2PanPlane.m_pItems);
    this->m_mapConfig2PanPlane.m_pItems = 0i64;
    this->m_mapConfig2PanPlane.m_ulReserved = 0;
  }
}

// File Line: 46
// RVA: 0xA4FE50
void __fastcall AkDevice::PushData(AkDevice *this)
{
  CAkSink *pSink; // rax
  AkPipelineBufferBase *p_m_MasterOut; // rbx
  CAkSinkVtbl *vfptr; // rax

  pSink = this->pSink;
  p_m_MasterOut = &pSink->m_MasterOut;
  pSink->m_MasterOut.uValidFrames = 0;
  pSink->m_MasterOut.uValidFrames = 0;
  CAkVPLFinalMixNode::GetResultingBuffer(this->pFinalMix, &pSink->m_MasterOut);
  vfptr = this->pSink->vfptr;
  if ( p_m_MasterOut->uValidFrames )
    ((void (*)(void))vfptr->PassData)();
  else
    ((void (*)(void))vfptr->PassSilence)();
}

// File Line: 65
// RVA: 0xA50060
__int64 __fastcall AkDevice::SetSpeakerAngles(
        AkDevice *this,
        const float *in_pfSpeakerAngles,
        unsigned int in_uNumAngles)
{
  unsigned int uNumAngles; // r12d
  unsigned __int64 v6; // rsi
  __int64 v7; // rdi
  char *v8; // r14
  __int64 v10; // rax
  void *v11; // rsp
  unsigned int i; // r9d
  __int64 v13; // r8
  int v14; // edx
  unsigned int v15; // edi
  unsigned int *puSpeakerAngles; // rdx
  signed int v17; // eax
  float Dst[8]; // [rsp+20h] [rbp+0h] BYREF
  unsigned int out_uMinAngleBetweenSpeakers; // [rsp+60h] [rbp+40h] BYREF

  uNumAngles = in_uNumAngles;
  if ( this->uNumAngles > in_uNumAngles )
    uNumAngles = this->uNumAngles;
  v6 = 4i64 * uNumAngles;
  v7 = in_uNumAngles;
  v8 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, v6);
  if ( !v8 )
    return 2i64;
  v10 = v6 + 15;
  if ( v6 + 15 <= v6 )
    v10 = 0xFFFFFFFFFFFFFF0i64;
  v11 = alloca(v10 & 0xFFFFFFFFFFFFFFF0ui64);
  if ( (_DWORD)v7 )
    memmove(Dst, in_pfSpeakerAngles, 4 * v7);
  for ( i = v7; i < this->uNumAngles; Dst[v13] = (float)((float)v14 * 360.0) * 0.001953125 )
  {
    v13 = i;
    v14 = this->puSpeakerAngles[i++];
  }
  v15 = CAkSpeakerPan::SetSpeakerAngles(Dst, v7, v8, &out_uMinAngleBetweenSpeakers);
  if ( v15 == 1 )
  {
    puSpeakerAngles = this->puSpeakerAngles;
    if ( puSpeakerAngles )
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, puSpeakerAngles);
    v17 = out_uMinAngleBetweenSpeakers;
    this->puSpeakerAngles = (unsigned int *)v8;
    this->uNumAngles = uNumAngles;
    this->fOneOverMinAngleBetweenSpeakers = 1.0 / (float)v17;
  }
  else
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v8);
  }
  return v15;
}

// File Line: 111
// RVA: 0xA4FC50
__int64 __fastcall AkDevice::CreatePanCache(AkDevice *this, unsigned int in_uOutputConfig)
{
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *m_pItems; // rax
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v5; // rdi
  _QWORD *p_item; // rdi
  MapStruct<unsigned __int64,AkVPL *> *v7; // rax
  CAkSpeakerPan::PanPair *v8; // rax
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v10; // rdi
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v11; // rax

  m_pItems = this->m_mapConfig2PanPlane.m_pItems;
  v5 = &m_pItems[this->m_mapConfig2PanPlane.m_uLength];
  if ( m_pItems == v5 )
    goto LABEL_7;
  do
  {
    if ( m_pItems->key == in_uOutputConfig )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v5 );
  if ( m_pItems == v5 )
  {
LABEL_7:
    p_item = 0i64;
    goto LABEL_8;
  }
  p_item = &m_pItems->item;
  if ( m_pItems == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)-8i64 )
  {
LABEL_8:
    v7 = AkArray<CAkRanSeqCntr::CntrInfoEntry,CAkRanSeqCntr::CntrInfoEntry const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<unsigned __int64,AkVPL *>,MapStruct<unsigned __int64,AkVPL *> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)&this->m_mapConfig2PanPlane);
    if ( v7 )
    {
      LODWORD(v7->key) = in_uOutputConfig;
      p_item = &v7->item;
    }
    if ( !p_item )
      goto LABEL_15;
  }
  v8 = (CAkSpeakerPan::PanPair *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x808ui64);
  *p_item = v8;
  if ( v8 )
    CAkSpeakerPan::CreatePanCache(in_uOutputConfig, this->puSpeakerAngles, v8);
  if ( *p_item )
    return 1i64;
LABEL_15:
  v10 = this->m_mapConfig2PanPlane.m_pItems;
  v11 = &v10[this->m_mapConfig2PanPlane.m_uLength];
  if ( v10 != v11 )
  {
    do
    {
      if ( v10->key == in_uOutputConfig )
        break;
      ++v10;
    }
    while ( v10 != v11 );
    if ( v10 != v11 )
    {
      if ( v10 < &v11[-1] )
        qmemcpy(
          v10,
          &v10[1],
          8
        * (((((unsigned __int64)((char *)&v11[-1] - (char *)v10 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
      --this->m_mapConfig2PanPlane.m_uLength;
    }
  }
  return 2i64;
}

// File Line: 129
// RVA: 0xA50330
void CAkOutputMgr::Term(void)
{
  AkDevice *m_pItems; // rbx
  AkDevice *v1; // rdi

  m_pItems = CAkOutputMgr::m_Devices.m_pItems;
  if ( CAkOutputMgr::m_Devices.m_pItems )
  {
    v1 = &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength];
    if ( CAkOutputMgr::m_Devices.m_pItems != v1 )
    {
      do
        AkDevice::~AkDevice(m_pItems++);
      while ( m_pItems != v1 );
      m_pItems = CAkOutputMgr::m_Devices.m_pItems;
    }
    CAkOutputMgr::m_Devices.m_uLength = 0;
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pItems);
    CAkOutputMgr::m_Devices.m_pItems = 0i64;
    CAkOutputMgr::m_Devices.m_ulReserved = 0;
  }
}

// File Line: 134
// RVA: 0xA503B0
__int64 __fastcall CAkOutputMgr::_AddOutputDevice(
        unsigned __int64 in_uKey,
        AkOutputSettings *in_settings,
        AkSinkType in_eSinkType,
        unsigned int in_uDeviceInstance,
        unsigned int in_uListeners,
        void *in_pUserData)
{
  unsigned int m_uLength; // r10d
  unsigned int m_ulReserved; // r11d
  unsigned __int64 v12; // rbx
  AkDevice *v13; // rsi
  unsigned int v14; // edi
  AkDevice *v15; // rcx
  CAkSink *v16; // rax
  bool v17; // bl
  CAkBusFX *v18; // rax
  AkDevice *v19; // rdi
  AkDevice *v20; // rax
  AkDevice *v21; // rbx
  int v23; // ecx
  unsigned int v24; // edi
  unsigned __int64 v25; // rax
  __int64 v26; // rcx
  signed __int64 v27; // rcx
  void *v28; // rsp
  void *v29; // rsp
  AKRESULT v30; // edi
  float out_angles[8]; // [rsp+20h] [rbp+0h] BYREF

  m_uLength = CAkOutputMgr::m_Devices.m_uLength;
  m_ulReserved = CAkOutputMgr::m_Devices.m_ulReserved;
  v12 = CAkOutputMgr::m_Devices.m_uLength;
  if ( CAkOutputMgr::m_Devices.m_uLength >= (unsigned __int64)CAkOutputMgr::m_Devices.m_ulReserved )
  {
    if ( !AkArray<AkDevice,AkDevice &,ArrayPoolLEngineDefault,1,AkArrayAllocatorDefault>::GrowArray(
            &CAkOutputMgr::m_Devices,
            1u) )
      return 52i64;
    m_ulReserved = CAkOutputMgr::m_Devices.m_ulReserved;
    m_uLength = CAkOutputMgr::m_Devices.m_uLength;
  }
  if ( v12 >= m_ulReserved )
    return 52i64;
  CAkOutputMgr::m_Devices.m_uLength = m_uLength + 1;
  v13 = &CAkOutputMgr::m_Devices.m_pItems[m_uLength];
  if ( !v13 )
    return 52i64;
  v14 = 0;
  v15 = &CAkOutputMgr::m_Devices.m_pItems[m_uLength];
  v13->m_mapConfig2PanPlane.m_pItems = 0i64;
  *(_QWORD *)&v13->m_mapConfig2PanPlane.m_uLength = 0i64;
  memset(v15, 0, sizeof(AkDevice));
  v16 = CAkSink::Create(in_settings, in_eSinkType, in_uDeviceInstance);
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
        v21 = v20 + 1;
        AkDevice::operator=(v20, v20 + 1);
        v20 = v21;
      }
      while ( v21 < v19 );
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
    v26 = 0xFFFFFFFFFFFFFF0i64;
  v27 = v26 & 0xFFFFFFFFFFFFFFF0ui64;
  v28 = alloca(v27);
  v29 = alloca(v27);
  CAkSpeakerPan::GetDefaultSpeakerAngles(v13->pSink->m_SpeakersConfig, out_angles);
  if ( (unsigned int)AkDevice::SetSpeakerAngles(v13, out_angles, v24) != 1 )
    return 2i64;
  v13->uDeviceID = in_uKey;
  v13->uListeners = in_uListeners;
  v13->pUserData = in_pUserData;
  v13->ePanningRule = in_settings->ePanningRule;
  CAkOutputMgr::SetListenersOnDevice(in_uListeners, in_uKey);
  CAkListener::RouteListenersToDevice(in_uListeners, in_uKey);
  v30 = CAkVPLFinalMixNode::Init(v13->pFinalMix, v13->pSink->m_SpeakersConfig);
  if ( v30 == AK_Success )
    CAkLEngine::ReevaluateBussesForDevice(in_uKey, in_uListeners);
  return (unsigned int)v30;
}

// File Line: 189
// RVA: 0xA4FB80
AKRESULT __fastcall CAkOutputMgr::AddMainDevice(
        AkOutputSettings *in_outputSettings,
        AkSinkType in_eSinkType,
        unsigned int in_uListeners,
        void *in_pUserData)
{
  return CAkOutputMgr::_AddOutputDevice(0i64, in_outputSettings, in_eSinkType, 0, in_uListeners, in_pUserData);
}

// File Line: 194
// RVA: 0xA4FBB0
AKRESULT __fastcall CAkOutputMgr::AddOutputDevice(
        AkOutputSettings *in_settings,
        AkSinkType in_eSinkType,
        unsigned int in_uDeviceInstance,
        unsigned int in_uListeners,
        void *in_pUserData)
{
  unsigned __int64 v6; // r10
  __int64 v8; // rax
  unsigned __int64 *i; // rcx

  v6 = (int)in_eSinkType | ((unsigned __int64)in_uDeviceInstance << 32);
  if ( !v6 )
    return 2;
  v8 = 0i64;
  if ( !CAkOutputMgr::m_Devices.m_uLength )
    return CAkOutputMgr::_AddOutputDevice(
             v6,
             in_settings,
             in_eSinkType,
             in_uDeviceInstance,
             in_uListeners,
             in_pUserData);
  for ( i = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID; *i != v6; i += 10 )
  {
    v8 = (unsigned int)(v8 + 1);
    if ( (unsigned int)v8 >= CAkOutputMgr::m_Devices.m_uLength )
      return CAkOutputMgr::_AddOutputDevice(
               v6,
               in_settings,
               in_eSinkType,
               in_uDeviceInstance,
               in_uListeners,
               in_pUserData);
  }
  if ( &CAkOutputMgr::m_Devices.m_pItems[v8] )
    return 1;
  else
    return CAkOutputMgr::_AddOutputDevice(
             v6,
             in_settings,
             in_eSinkType,
             in_uDeviceInstance,
             in_uListeners,
             in_pUserData);
}

// File Line: 210
// RVA: 0xA4FEB0
__int64 __fastcall CAkOutputMgr::RemoveOutputDevice(unsigned __int64 in_uDeviceID)
{
  AkDevice *m_pItems; // rbx
  AkDevice *v2; // rdx
  unsigned int m_uLength; // eax

  m_pItems = CAkOutputMgr::m_Devices.m_pItems;
  v2 = &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength];
  if ( CAkOutputMgr::m_Devices.m_pItems == v2 )
    return 2i64;
  while ( m_pItems->uDeviceID != in_uDeviceID )
  {
    if ( ++m_pItems == v2 )
      return 2i64;
  }
  CAkLEngine::ReevaluateBussesForDevice(in_uDeviceID, 0);
  m_uLength = CAkOutputMgr::m_Devices.m_uLength;
  if ( CAkOutputMgr::m_Devices.m_uLength > 1 )
  {
    AkDevice::~AkDevice(m_pItems);
    AkDevice::operator=(m_pItems, &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength - 1]);
    m_uLength = CAkOutputMgr::m_Devices.m_uLength;
  }
  CAkOutputMgr::m_Devices.m_uLength = m_uLength - 1;
  return 1i64;
}

// File Line: 226
// RVA: 0xA50000
__int64 __fastcall CAkOutputMgr::SetListenersOnDevice(unsigned int in_uListeners, unsigned __int64 in_uDeviceID)
{
  __int64 v3; // rax
  unsigned __int64 *i; // r8
  __int64 result; // rax
  __int64 v6; // rcx

  CAkOutputMgr::m_Devices.m_pItems->uListeners &= ~in_uListeners;
  v3 = 0i64;
  if ( !CAkOutputMgr::m_Devices.m_uLength )
    return 2i64;
  for ( i = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID; *i != in_uDeviceID; i += 10 )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= CAkOutputMgr::m_Devices.m_uLength )
      return 2i64;
  }
  v6 = v3;
  result = 1i64;
  CAkOutputMgr::m_Devices.m_pItems[v6].uListeners = in_uListeners;
  return result;
}

// File Line: 243
// RVA: 0xA4FF50
__int64 __fastcall CAkOutputMgr::ReplaceSink(unsigned __int64 in_uDeviceID, CAkSink *in_pSink)
{
  AkDevice *m_pItems; // rbx
  AkDevice *v4; // r8
  CAkSink *pSink; // rdi
  int v7; // esi

  m_pItems = CAkOutputMgr::m_Devices.m_pItems;
  v4 = &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength];
  if ( CAkOutputMgr::m_Devices.m_pItems == v4 )
    return 2i64;
  while ( m_pItems->uDeviceID != in_uDeviceID )
  {
    if ( ++m_pItems == v4 )
      return 2i64;
  }
  m_pItems->pSink->vfptr->Term(m_pItems->pSink);
  pSink = m_pItems->pSink;
  v7 = g_LEngineDefaultPoolId;
  if ( pSink )
  {
    pSink->vfptr->__vecDelDtor(pSink, 0);
    AK::MemoryMgr::Free(v7, pSink);
  }
  m_pItems->pSink = in_pSink;
  return 1i64;
}

// File Line: 259
// RVA: 0xA501B0
void __fastcall CAkOutputMgr::StartOutputCapture(const wchar_t *in_CaptureFileName)
{
  __int64 v2; // rbx
  unsigned __int64 v4; // rcx
  signed __int64 v5; // rcx
  void *v6; // rsp
  void *v7; // rsp
  __int64 v8; // rdi
  char *v9; // r15
  AkDevice *m_pItems; // rbx
  char i; // di
  const wchar_t *v12; // rdx
  char Dst[16]; // [rsp+20h] [rbp+0h] BYREF

  v2 = -1i64;
  while ( in_CaptureFileName[++v2] != 0 )
    ;
  v4 = 2 * v2 + 19;
  if ( v4 <= 2 * v2 + 4 )
    v4 = 0xFFFFFFFFFFFFFF0i64;
  v5 = v4 & 0xFFFFFFFFFFFFFFF0ui64;
  v6 = alloca(v5);
  v7 = alloca(v5);
  v8 = 2 * v2;
  memmove(Dst, in_CaptureFileName, 2 * v2);
  v9 = &Dst[2 * v2];
  *(_WORD *)&Dst[v8] = *(_WORD *)&Dst[v8 - 2];
  *(_WORD *)&Dst[v8 - 2] = *((_WORD *)v9 - 2);
  *((_WORD *)v9 - 2) = *((_WORD *)v9 - 3);
  *((_WORD *)v9 - 3) = *((_WORD *)v9 - 4);
  *(_WORD *)&Dst[v8 + 2] = 0;
  m_pItems = CAkOutputMgr::m_Devices.m_pItems;
  for ( i = 0; m_pItems != &CAkOutputMgr::m_Devices.m_pItems[CAkOutputMgr::m_Devices.m_uLength]; ++m_pItems )
  {
    if ( m_pItems->uDeviceID )
    {
      ++i;
      v12 = (const wchar_t *)Dst;
      *((_WORD *)v9 - 4) = i + 48;
    }
    else
    {
      v12 = in_CaptureFileName;
    }
    CAkSink::StartOutputCapture(m_pItems->pSink, v12);
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

