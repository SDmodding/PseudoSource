// File Line: 25
// RVA: 0xA6FB20
void __fastcall CAkPBIAware::~CAkPBIAware(CAkPBIAware *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkPBIAware::`vftable';
  CAkIndexable::~CAkIndexable((CAkIndexable *)&this->vfptr);
}

// File Line: 35
// RVA: 0xA6FB30
void __fastcall CAkPBIAware::CreatePBI(CAkPBIAware *this, CAkSoundBase *in_pSound, CAkSource *in_pSource, AkPBIParams *in_rPBIParams, PriorityInfoCurrent *in_rPriority, CAkLimiter *in_pAMLimiter, CAkLimiter *in_pBusLimiter)
{
  CAkSoundBase *v7; // rsi
  AkPBIParams *v8; // rbx
  CAkSource *v9; // rdi
  CAkPBI *v10; // rax

  v7 = in_pSound;
  v8 = in_rPBIParams;
  v9 = in_pSource;
  v10 = (CAkPBI *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x218ui64);
  if ( v10 )
    CAkPBI::CAkPBI(
      v10,
      v7,
      v9,
      v8->pGameObj,
      &v8->userParams,
      &v8->playHistory,
      0,
      in_rPriority,
      v8->bTargetFeedback,
      0,
      in_pAMLimiter,
      in_pBusLimiter);
}

