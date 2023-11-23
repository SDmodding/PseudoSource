// File Line: 28
// RVA: 0xA7F9E0
AK::CAkBusCtx *__fastcall AK::CAkBusCtx::GetParentCtx(AK::CAkBusCtx *this, AK::CAkBusCtx *result)
{
  CAkBus *m_pBus; // rcx
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  CAkBus *v5; // rax

  m_pBus = this->m_pBus;
  result->m_pBus = 0i64;
  if ( m_pBus )
  {
    m_pBusOutputNode = m_pBus->m_pBusOutputNode;
    if ( m_pBusOutputNode )
    {
      v5 = (CAkBus *)((__int64 (__fastcall *)(CAkParameterNodeBase *))m_pBusOutputNode->vfptr[7].Category)(m_pBusOutputNode);
      if ( v5 )
        result->m_pBus = v5;
    }
  }
  return result;
}

// File Line: 47
// RVA: 0xA7FA50
CAkBus *__fastcall AK::CAkBusCtx::ID(AK::CAkBusCtx *this)
{
  CAkBus *result; // rax

  result = this->m_pBus;
  if ( this->m_pBus )
    return (CAkBus *)result->key;
  return result;
}

// File Line: 59
// RVA: 0xA7FA20
double __fastcall AK::CAkBusCtx::GetVolume(AK::CAkBusCtx *this, BusVolumeType in_VolumeType)
{
  CAkBus *m_pBus; // rcx
  double result; // xmm0_8

  m_pBus = this->m_pBus;
  if ( !m_pBus )
  {
    if ( in_VolumeType != BusVolumeType_IncludeEntireBusTree )
      return 0.0;
    m_pBus = g_MasterBusCtx.m_pBus;
    if ( !g_MasterBusCtx.m_pBus )
      return 0.0;
  }
  *(float *)&result = CAkBus::GetBusEffectiveVolume(m_pBus, in_VolumeType, AkPropID_BusVolume);
  return result;
}

// File Line: 77
// RVA: 0xA7FA90
bool __fastcall AK::CAkBusCtx::IsTopBusCtx(AK::CAkBusCtx *this)
{
  CAkBus *m_pBus; // rcx

  m_pBus = this->m_pBus;
  return m_pBus && CAkBus::IsTopBus(m_pBus);
}

// File Line: 85
// RVA: 0xA7F950
CAkBus *__fastcall AK::CAkBusCtx::GetChannelConfig(AK::CAkBusCtx *this)
{
  CAkBus *result; // rax

  result = this->m_pBus;
  if ( this->m_pBus )
    return (CAkBus *)result->m_uChannelConfig;
  return result;
}

// File Line: 96
// RVA: 0xA7F970
void __fastcall AK::CAkBusCtx::GetFX(AK::CAkBusCtx *this, __int64 in_uFXIndex, AkFXDesc *out_rFXInfo)
{
  CAkBus *m_pBus; // rcx
  CAkFxBase *m_pT; // rcx

  m_pBus = this->m_pBus;
  if ( m_pBus )
  {
    ((void (__fastcall *)(CAkBus *, __int64, AkFXDesc *, _QWORD))m_pBus->vfptr[14].__vecDelDtor)(
      m_pBus,
      in_uFXIndex,
      out_rFXInfo,
      0i64);
  }
  else
  {
    m_pT = out_rFXInfo->pFx.m_pT;
    out_rFXInfo->pFx.m_pT = 0i64;
    if ( m_pT )
      ((void (__fastcall *)(CAkFxBase *, __int64))m_pT->vfptr->Release)(m_pT, in_uFXIndex);
    out_rFXInfo->bIsBypassed = 0;
  }
}

// File Line: 109
// RVA: 0xA7F9C0
void __fastcall AK::CAkBusCtx::GetFXDataID(
        AK::CAkBusCtx *this,
        __int64 in_uFXIndex,
        __int64 in_uDataIndex,
        unsigned int *out_rDataID)
{
  CAkBus *m_pBus; // rcx

  m_pBus = this->m_pBus;
  if ( m_pBus )
    ((void (__fastcall *)(CAkBus *, __int64, __int64, unsigned int *))m_pBus->vfptr[14].AddRef)(
      m_pBus,
      in_uFXIndex,
      in_uDataIndex,
      out_rDataID);
  else
    *out_rDataID = -1;
}

// File Line: 121
// RVA: 0xA7F930
bool __fastcall AK::CAkBusCtx::GetBypassAllFX(AK::CAkBusCtx *this)
{
  CAkBus *m_pBus; // rcx

  m_pBus = this->m_pBus;
  if ( m_pBus )
    return ((__int64 (__fastcall *)(CAkBus *, _QWORD))m_pBus->vfptr[14].Release)(m_pBus, 0i64);
  else
    return 0;
}

// File Line: 129
// RVA: 0xA7FA60
bool __fastcall AK::CAkBusCtx::IsAuxBus(AK::CAkBusCtx *this)
{
  CAkBus *m_pBus; // rcx

  m_pBus = this->m_pBus;
  return m_pBus && m_pBus->vfptr[3].Release(m_pBus) == 12;
}

