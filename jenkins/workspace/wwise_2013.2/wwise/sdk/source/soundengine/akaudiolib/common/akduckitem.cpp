// File Line: 26
// RVA: 0xA97D70
__int64 __fastcall CAkDuckItem::Term(CAkDuckItem *this)
{
  CAkTransition *m_pvVolumeTransition; // rdx

  m_pvVolumeTransition = this->m_pvVolumeTransition;
  if ( m_pvVolumeTransition )
  {
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, m_pvVolumeTransition, this);
    this->m_pvVolumeTransition = 0i64;
  }
  return 1i64;
}

// File Line: 38
// RVA: 0xA97D50
__int64 __fastcall CAkDuckItem::Init(CAkDuckItem *this, CAkBus *in_pBusNode)
{
  this->m_pBusNode = in_pBusNode;
  this->m_pvVolumeTransition = 0i64;
  this->m_EffectiveVolumeOffset = 0.0;
  return 1i64;
}

// File Line: 47
// RVA: 0xA97DB0
void __fastcall CAkDuckItem::TransUpdateValue(
        CAkDuckItem *this,
        __int64 in_target,
        float in_fValue,
        bool in_bIsTerminated)
{
  float DuckedVolume; // xmm0_4
  CAkBus *m_pBusNode; // rcx
  float v9; // xmm6_4
  __int64 v10; // r8
  float v11; // xmm0_4

  DuckedVolume = CAkBus::GetDuckedVolume(this->m_pBusNode, (AkPropID)in_target);
  m_pBusNode = this->m_pBusNode;
  this->m_EffectiveVolumeOffset = in_fValue;
  v9 = DuckedVolume;
  v11 = CAkBus::GetDuckedVolume(m_pBusNode, (AkPropID)in_target);
  if ( in_bIsTerminated )
  {
    CAkBus::CheckDuck(this->m_pBusNode);
    this->m_pvVolumeTransition = 0i64;
  }
  if ( (float)(v11 - v9) != 0.0 )
    ((void (__fastcall *)(CAkBus *, _QWORD, __int64, _QWORD, _QWORD))this->m_pBusNode->vfptr[5].Release)(
      this->m_pBusNode,
      (unsigned int)g_AkPropRTPCID[in_target],
      v10,
      0i64,
      0i64);
}

