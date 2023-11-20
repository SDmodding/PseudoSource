// File Line: 28
// RVA: 0xA7F9E0
AK::CAkBusCtx *__fastcall AK::CAkBusCtx::GetParentCtx(AK::CAkBusCtx *this, AK::CAkBusCtx *result)
{
  CAkBus *v2; // rcx
  AK::CAkBusCtx *v3; // rbx
  CAkParameterNodeBase *v4; // rcx
  __int64 v5; // rax

  v2 = this->m_pBus;
  v3 = result;
  result->m_pBus = 0i64;
  if ( v2 )
  {
    v4 = v2->m_pBusOutputNode;
    if ( v4 )
    {
      v5 = ((__int64 (*)(void))v4->vfptr[7].Category)();
      if ( v5 )
        v3->m_pBus = (CAkBus *)v5;
    }
  }
  return v3;
}

// File Line: 47
// RVA: 0xA7FA50
CAkBus *__fastcall AK::CAkBusCtx::ID(AK::CAkBusCtx *this)
{
  CAkBus *result; // rax

  result = this->m_pBus;
  if ( this->m_pBus )
    result = (CAkBus *)result->key;
  return result;
}

// File Line: 59
// RVA: 0xA7FA20
void __fastcall AK::CAkBusCtx::GetVolume(AK::CAkBusCtx *this, BusVolumeType in_VolumeType)
{
  CAkBus *v2; // rcx

  v2 = this->m_pBus;
  if ( v2 || in_VolumeType == 1 && (v2 = g_MasterBusCtx.m_pBus) != 0i64 )
    CAkBus::GetBusEffectiveVolume(v2, in_VolumeType, AkPropID_BusVolume);
}

// File Line: 77
// RVA: 0xA7FA90
bool __fastcall AK::CAkBusCtx::IsTopBusCtx(AK::CAkBusCtx *this)
{
  JUMPOUT(this->m_pBus, 0i64, CAkBus::IsTopBus);
  return 0;
}

// File Line: 85
// RVA: 0xA7F950
CAkBus *__fastcall AK::CAkBusCtx::GetChannelConfig(AK::CAkBusCtx *this)
{
  CAkBus *result; // rax

  result = this->m_pBus;
  if ( this->m_pBus )
    result = (CAkBus *)result->m_uChannelConfig;
  return result;
}

// File Line: 96
// RVA: 0xA7F970
void __fastcall AK::CAkBusCtx::GetFX(AK::CAkBusCtx *this, __int64 in_uFXIndex, AkFXDesc *out_rFXInfo)
{
  CAkBus *v3; // rcx
  AkFXDesc *v4; // rbx
  CAkFxBase *v5; // rcx

  v3 = this->m_pBus;
  v4 = out_rFXInfo;
  if ( v3 )
  {
    ((void (__fastcall *)(CAkBus *, __int64, AkFXDesc *, _QWORD))v3->vfptr[14].__vecDelDtor)(
      v3,
      in_uFXIndex,
      out_rFXInfo,
      0i64);
  }
  else
  {
    v5 = out_rFXInfo->pFx.m_pT;
    out_rFXInfo->pFx.m_pT = 0i64;
    if ( v5 )
      ((void (__fastcall *)(CAkFxBase *, __int64))v5->vfptr->Release)(v5, in_uFXIndex);
    v4->bIsBypassed = 0;
  }
}

// File Line: 109
// RVA: 0xA7F9C0
void __fastcall AK::CAkBusCtx::GetFXDataID(AK::CAkBusCtx *this, __int64 in_uFXIndex, __int64 in_uDataIndex, unsigned int *out_rDataID)
{
  CAkBus *v4; // rcx

  v4 = this->m_pBus;
  if ( v4 )
    ((void (__fastcall *)(CAkBus *, __int64, __int64, unsigned int *))v4->vfptr[14].AddRef)(
      v4,
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
  CAkBus *v1; // rcx
  bool result; // al

  v1 = this->m_pBus;
  if ( v1 )
    result = ((__int64 (__fastcall *)(CAkBus *, _QWORD))v1->vfptr[14].Release)(v1, 0i64);
  else
    result = 0;
  return result;
}

// File Line: 129
// RVA: 0xA7FA60
bool __fastcall AK::CAkBusCtx::IsAuxBus(AK::CAkBusCtx *this)
{
  CAkBus *v1; // rcx
  bool result; // al

  v1 = this->m_pBus;
  if ( v1 )
    result = ((unsigned int (*)(void))v1->vfptr[3].Release)() == 12;
  else
    result = 0;
  return result;
}

