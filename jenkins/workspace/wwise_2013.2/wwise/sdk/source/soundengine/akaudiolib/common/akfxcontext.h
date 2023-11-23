// File Line: 114
// RVA: 0xA84FC0
__int64 __fastcall CAkInsertFXContext::GetPlayingID(CAkInsertFXContext *this)
{
  return this->m_pContext->m_UserParams.m_PlayingID;
}

// File Line: 116
// RVA: 0xA84E40
unsigned __int64 __fastcall CAkInsertFXContext::GetGameObjectID(CAkInsertFXContext *this)
{
  return this->m_pContext->m_pGameObj->m_GameObjID;
}

// File Line: 118
// RVA: 0xA85260
void __fastcall CAkInsertFXContext::GetPositioningType(
        CAkInsertFXContext *this,
        AkPannerType *out_ePanner,
        AkPositionSourceType *out_ePosSource)
{
  *out_ePanner = *((_BYTE *)this->m_pContext + 371) & 3;
  *out_ePosSource = (*((unsigned __int8 *)this->m_pContext + 371) >> 2) & 3;
}

// File Line: 120
// RVA: 0xA84F50
__int64 __fastcall CAkInsertFXContext::GetNumEmitterListenerPairs(CAkInsertFXContext *this)
{
  return CAkRegisteredObj::GetNumEmitterListenerPairs(this->m_pContext->m_pGameObj);
}

// File Line: 125
// RVA: 0xA84E20
__int64 __fastcall CAkInsertFXContext::GetEmitterListenerPair(
        CAkInsertFXContext *this,
        unsigned int in_uIndex,
        AkEmitterListenerPair *out_emitterListenerPair)
{
  return CAkPBI::GetEmitterListenerPair(this->m_pContext, in_uIndex, out_emitterListenerPair);
}

// File Line: 127
// RVA: 0xA84F70
__int64 __fastcall CAkInsertFXContext::GetNumGameObjectPositions(CAkInsertFXContext *this)
{
  CAkRegisteredObj *m_pGameObj; // rcx

  m_pGameObj = this->m_pContext->m_pGameObj;
  if ( (*((_BYTE *)&m_pGameObj->m_PosKeep.AkSoundPositionRef + 11) & 7) != 0 )
    return m_pGameObj->m_PosKeep.m_uNumPos;
  else
    return 1i64;
}

// File Line: 129
// RVA: 0xA84E60
__int64 __fastcall CAkInsertFXContext::GetGameObjectMultiPositionType(CAkInsertFXContext *this)
{
  return *((_BYTE *)&this->m_pContext->m_pGameObj->m_PosKeep.AkSoundPositionRef + 11) & 7;
}

// File Line: 131
// RVA: 0xA84EC0
float __fastcall CAkInsertFXContext::GetGameObjectScaling(CAkInsertFXContext *this)
{
  return this->m_pContext->m_pGameObj->m_fScalingFactor;
}

// File Line: 136
// RVA: 0xA84EA0
__int64 __fastcall CAkInsertFXContext::GetGameObjectPosition(
        CAkInsertFXContext *this,
        unsigned int in_uIndex,
        AkSoundPosition *out_position)
{
  return CAkPBI::GetGameObjectPosition(this->m_pContext, in_uIndex, out_position);
}

// File Line: 138
// RVA: 0xA84F20
__int64 __fastcall CAkInsertFXContext::GetListenerMask(CAkInsertFXContext *this)
{
  return (unsigned __int8)this->m_pContext->m_pGameObj->m_PosKeep.m_uListenerMask;
}

// File Line: 143
// RVA: 0xA84F00
__int64 __fastcall CAkInsertFXContext::GetListenerData(
        CAkInsertFXContext *this,
        char in_uListenerMask,
        AkListener *out_listener)
{
  return CAkPBI::GetListenerData(this->m_pContext, in_uListenerMask, out_listener);
}

// File Line: 170
// RVA: 0xA84F40
__int64 __fastcall CAkBusFXContext::GetMaxBufferLength(CAkSourceFXContext *this)
{
  return 1024i64;
}

// File Line: 196
// RVA: 0xA85250
void __fastcall CAkBusFXContext::GetPositioningType(
        CAkBusFXContext *this,
        AkPannerType *out_ePanner,
        AkPositionSourceType *out_ePosSource)
{
  *out_ePanner = Ak2D;
  *out_ePosSource = AkUserDef;
}

// File Line: 279
// RVA: 0xA84FD0
__int64 __fastcall CAkSourceFXContext::GetPlayingID(CAkSourceFXContext *this)
{
  return this->m_pContext->m_UserParams.m_PlayingID;
}

// File Line: 281
// RVA: 0xA84E50
unsigned __int64 __fastcall CAkSourceFXContext::GetGameObjectID(CAkSourceFXContext *this)
{
  return this->m_pContext->m_pGameObj->m_GameObjID;
}

// File Line: 283
// RVA: 0xA85290
void __fastcall CAkSourceFXContext::GetPositioningType(
        CAkSourceFXContext *this,
        AkPannerType *out_ePanner,
        AkPositionSourceType *out_ePosSource)
{
  *out_ePanner = *((_BYTE *)this->m_pContext + 371) & 3;
  *out_ePosSource = (*((unsigned __int8 *)this->m_pContext + 371) >> 2) & 3;
}

// File Line: 285
// RVA: 0xA84F60
__int64 __fastcall CAkSourceFXContext::GetNumEmitterListenerPairs(CAkSourceFXContext *this)
{
  return CAkRegisteredObj::GetNumEmitterListenerPairs(this->m_pContext->m_pGameObj);
}

// File Line: 290
// RVA: 0xA84E30
__int64 __fastcall CAkSourceFXContext::GetEmitterListenerPair(
        CAkSourceFXContext *this,
        unsigned int in_uIndex,
        AkEmitterListenerPair *out_emitterListenerPair)
{
  return CAkPBI::GetEmitterListenerPair(this->m_pContext, in_uIndex, out_emitterListenerPair);
}

// File Line: 292
// RVA: 0xA84F90
__int64 __fastcall CAkSourceFXContext::GetNumGameObjectPositions(CAkSourceFXContext *this)
{
  CAkRegisteredObj *m_pGameObj; // rcx

  m_pGameObj = this->m_pContext->m_pGameObj;
  if ( (*((_BYTE *)&m_pGameObj->m_PosKeep.AkSoundPositionRef + 11) & 7) != 0 )
    return m_pGameObj->m_PosKeep.m_uNumPos;
  else
    return 1i64;
}

// File Line: 294
// RVA: 0xA84E80
__int64 __fastcall CAkSourceFXContext::GetGameObjectMultiPositionType(CAkSourceFXContext *this)
{
  return *((_BYTE *)&this->m_pContext->m_pGameObj->m_PosKeep.AkSoundPositionRef + 11) & 7;
}

// File Line: 296
// RVA: 0xA84EE0
float __fastcall CAkSourceFXContext::GetGameObjectScaling(CAkSourceFXContext *this)
{
  return this->m_pContext->m_pGameObj->m_fScalingFactor;
}

// File Line: 301
// RVA: 0xA84EB0
__int64 __fastcall CAkSourceFXContext::GetGameObjectPosition(
        CAkSourceFXContext *this,
        unsigned int in_uIndex,
        AkSoundPosition *out_position)
{
  return CAkPBI::GetGameObjectPosition(this->m_pContext, in_uIndex, out_position);
}

// File Line: 303
// RVA: 0xA84F30
__int64 __fastcall CAkSourceFXContext::GetListenerMask(CAkSourceFXContext *this)
{
  return (unsigned __int8)this->m_pContext->m_pGameObj->m_PosKeep.m_uListenerMask;
}

// File Line: 308
// RVA: 0xA84F10
__int64 __fastcall CAkSourceFXContext::GetListenerData(
        CAkSourceFXContext *this,
        char in_uListenerMask,
        AkListener *out_listener)
{
  return CAkPBI::GetListenerData(this->m_pContext, in_uListenerMask, out_listener);
}

