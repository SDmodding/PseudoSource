// File Line: 22
// RVA: 0xA4FA00
AkDevice *__fastcall AkDevice::operator=(AkDevice *this, AkDevice *B)
{
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *m_pItems; // rdx

  this->pFinalMix = B->pFinalMix;
  this->pSink = B->pSink;
  this->pUserData = B->pUserData;
  this->uDeviceID = B->uDeviceID;
  this->uListeners = B->uListeners;
  this->puSpeakerAngles = B->puSpeakerAngles;
  this->uNumAngles = B->uNumAngles;
  this->fOneOverMinAngleBetweenSpeakers = B->fOneOverMinAngleBetweenSpeakers;
  this->ePanningRule = B->ePanningRule;
  m_pItems = this->m_mapConfig2PanPlane.m_pItems;
  if ( m_pItems )
  {
    this->m_mapConfig2PanPlane.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_mapConfig2PanPlane.m_pItems = 0i64;
    this->m_mapConfig2PanPlane.m_ulReserved = 0;
  }
  this->m_mapConfig2PanPlane.m_pItems = B->m_mapConfig2PanPlane.m_pItems;
  this->m_mapConfig2PanPlane.m_uLength = B->m_mapConfig2PanPlane.m_uLength;
  this->m_mapConfig2PanPlane.m_ulReserved = B->m_mapConfig2PanPlane.m_ulReserved;
  B->m_mapConfig2PanPlane.m_pItems = 0i64;
  *(_QWORD *)&B->m_mapConfig2PanPlane.m_uLength = 0i64;
  B->pFinalMix = 0i64;
  B->pSink = 0i64;
  B->pUserData = 0i64;
  B->puSpeakerAngles = 0i64;
  B->uNumAngles = 0;
  return this;
}

// File Line: 70
// RVA: 0xA4E380
AKRESULT __fastcall AkDevice::EnsurePanCacheExists(AkDevice *this, unsigned int in_uOutputConfig)
{
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *m_pItems; // rax
  unsigned int v3; // ebx
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v5; // r8
  AKRESULT PanCache; // r9d
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v7; // rcx
  unsigned int v8; // ebx
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v9; // rax

  m_pItems = this->m_mapConfig2PanPlane.m_pItems;
  v3 = in_uOutputConfig & 0xFFFFFFF7;
  v5 = &m_pItems[this->m_mapConfig2PanPlane.m_uLength];
  PanCache = AK_Success;
  if ( m_pItems == v5 )
    goto LABEL_6;
  do
  {
    if ( m_pItems->key == v3 )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v5 );
  if ( m_pItems == v5 || m_pItems == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)-8i64 )
LABEL_6:
    PanCache = AkDevice::CreatePanCache(this, v3);
  if ( (v3 & 4) == 0 || PanCache != AK_Success )
    return PanCache;
  v7 = this->m_mapConfig2PanPlane.m_pItems;
  v8 = v3 & 0xFFFFFFFB;
  v9 = &v7[this->m_mapConfig2PanPlane.m_uLength];
  if ( v7 == v9 )
    return AkDevice::CreatePanCache(this, v8);
  do
  {
    if ( v7->key == v8 )
      break;
    ++v7;
  }
  while ( v7 != v9 );
  if ( v7 == v9 || v7 == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)-8i64 )
    return AkDevice::CreatePanCache(this, v8);
  else
    return PanCache;
}

