// File Line: 22
// RVA: 0xA4FA00
AkDevice *__fastcall AkDevice::operator=(AkDevice *this, AkDevice *B)
{
  AkDevice *v2; // rbx
  AkDevice *v3; // rdi
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v4; // rdx

  v2 = B;
  this->pFinalMix = B->pFinalMix;
  v3 = this;
  this->pSink = B->pSink;
  this->pUserData = B->pUserData;
  this->uDeviceID = B->uDeviceID;
  this->uListeners = B->uListeners;
  this->puSpeakerAngles = B->puSpeakerAngles;
  this->uNumAngles = B->uNumAngles;
  this->fOneOverMinAngleBetweenSpeakers = B->fOneOverMinAngleBetweenSpeakers;
  this->ePanningRule = B->ePanningRule;
  v4 = this->m_mapConfig2PanPlane.m_pItems;
  if ( v4 )
  {
    this->m_mapConfig2PanPlane.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    v3->m_mapConfig2PanPlane.m_pItems = 0i64;
    v3->m_mapConfig2PanPlane.m_ulReserved = 0;
  }
  v3->m_mapConfig2PanPlane.m_pItems = v2->m_mapConfig2PanPlane.m_pItems;
  v3->m_mapConfig2PanPlane.m_uLength = v2->m_mapConfig2PanPlane.m_uLength;
  v3->m_mapConfig2PanPlane.m_ulReserved = v2->m_mapConfig2PanPlane.m_ulReserved;
  v2->m_mapConfig2PanPlane.m_pItems = 0i64;
  *(_QWORD *)&v2->m_mapConfig2PanPlane.m_uLength = 0i64;
  v2->pFinalMix = 0i64;
  v2->pSink = 0i64;
  v2->pUserData = 0i64;
  v2->puSpeakerAngles = 0i64;
  v2->uNumAngles = 0;
  return v3;
}

// File Line: 70
// RVA: 0xA4E380
AKRESULT __fastcall AkDevice::EnsurePanCacheExists(AkDevice *this, unsigned int in_uOutputConfig)
{
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v2; // rax
  unsigned int v3; // ebx
  AkDevice *v4; // rdi
  signed __int64 v5; // r8
  AKRESULT v6; // er9
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *v7; // rcx
  unsigned int v8; // ebx
  signed __int64 v9; // rax
  AKRESULT result; // eax

  v2 = this->m_mapConfig2PanPlane.m_pItems;
  v3 = in_uOutputConfig & 0xFFFFFFF7;
  v4 = this;
  v5 = (signed __int64)&v2[this->m_mapConfig2PanPlane.m_uLength];
  v6 = 1;
  if ( v2 == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v5 )
    goto LABEL_18;
  do
  {
    if ( v2->key == v3 )
      break;
    ++v2;
  }
  while ( v2 != (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v5 );
  if ( v2 == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v5
    || v2 == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)-8i64 )
  {
LABEL_18:
    v6 = AkDevice::CreatePanCache(this, v3);
  }
  if ( !(v3 & 4) || v6 != 1 )
    goto LABEL_19;
  v7 = v4->m_mapConfig2PanPlane.m_pItems;
  v8 = v3 & 0xFFFFFFFB;
  v9 = (signed __int64)&v7[v4->m_mapConfig2PanPlane.m_uLength];
  if ( v7 == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v9 )
    goto LABEL_20;
  do
  {
    if ( v7->key == v8 )
      break;
    ++v7;
  }
  while ( v7 != (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v9 );
  if ( v7 == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)v9
    || v7 == (MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *)-8i64 )
  {
LABEL_20:
    result = AkDevice::CreatePanCache(v4, v8);
  }
  else
  {
LABEL_19:
    result = v6;
  }
  return result;
}

