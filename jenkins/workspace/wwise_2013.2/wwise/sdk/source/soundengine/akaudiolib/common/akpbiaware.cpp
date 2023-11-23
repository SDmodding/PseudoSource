// File Line: 25
// RVA: 0xA6FB20
void __fastcall CAkPBIAware::~CAkPBIAware(CAkPBIAware *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkPBIAware::`vftable;
  CAkIndexable::~CAkIndexable(this);
}

// File Line: 35
// RVA: 0xA6FB30
void __fastcall CAkPBIAware::CreatePBI(
        CAkPBIAware *this,
        CAkSoundBase *in_pSound,
        CAkSource *in_pSource,
        AkPBIParams *in_rPBIParams,
        PriorityInfoCurrent *in_rPriority,
        CAkLimiter *in_pAMLimiter,
        CAkLimiter *in_pBusLimiter)
{
  CAkPBI *v10; // rax

  v10 = (CAkPBI *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x218ui64);
  if ( v10 )
    CAkPBI::CAkPBI(
      v10,
      in_pSound,
      in_pSource,
      in_rPBIParams->pGameObj,
      &in_rPBIParams->userParams,
      &in_rPBIParams->playHistory,
      0,
      in_rPriority,
      in_rPBIParams->bTargetFeedback,
      0,
      in_pAMLimiter,
      in_pBusLimiter);
}

