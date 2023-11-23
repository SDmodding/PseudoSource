// File Line: 41
// RVA: 0x3E9030
void UFG::PredictiveStreamingStats::CreateInstance(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::PredictiveStreamingStats *v1; // rbx

  v0 = UFG::qMalloc(0x448ui64, "PredictiveStreamingStats", 0i64);
  v1 = (UFG::PredictiveStreamingStats *)v0;
  if ( v0 )
  {
    UFG::PredictiveStreamingStats::Init((UFG::PredictiveStreamingStats *)v0);
    UFG::PredictiveStreamingStats::ResetInfo(v1);
    UFG::PredictiveStreamingStats::ms_pInstance = v1;
  }
  else
  {
    UFG::PredictiveStreamingStats::ms_pInstance = 0i64;
  }
}

// File Line: 54
// RVA: 0x3E90E0
void UFG::PredictiveStreamingStats::DeleteInstance(void)
{
  operator delete[](UFG::PredictiveStreamingStats::ms_pInstance);
  UFG::PredictiveStreamingStats::ms_pInstance = 0i64;
}

// File Line: 117
// RVA: 0x3E9100
void __fastcall UFG::PredictiveStreamingStats::PlayerInfo::Init(UFG::PredictiveStreamingStats::PlayerInfo *this)
{
  signed int size; // eax
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // kr00_8
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rax

  if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
    size = 0;
  else
    size = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
  v3 = size;
  v5 = size;
  v4 = 8i64 * size;
  if ( !is_mul_ok(v5, 8ui64) )
    v4 = -1i64;
  this->m_PlayerWeaponInfo = (UFG::PredictiveStreamingStats::PlayerWeaponInfo *)UFG::qMalloc(
                                                                                  v4,
                                                                                  "PredictiveStreamingStats",
                                                                                  0i64);
  v6 = 12 * v3;
  if ( !is_mul_ok(v3, 0xCui64) )
    v6 = -1i64;
  this->m_PlayerVehicleInfo = (UFG::PredictiveStreamingStats::PlayerVehicleInfo *)UFG::qMalloc(
                                                                                    v6,
                                                                                    "PredictiveStreamingStats",
                                                                                    0i64);
  v7 = 12 * v3;
  if ( !is_mul_ok(v3, 0xCui64) )
    v7 = -1i64;
  this->m_PlayerBoatInfo = (UFG::PredictiveStreamingStats::PlayerVehicleInfo *)UFG::qMalloc(
                                                                                 v7,
                                                                                 "PredictiveStreamingStats",
                                                                                 0i64);
}

// File Line: 126
// RVA: 0x3EA870
void __fastcall UFG::PredictiveStreamingStats::PlayerInfo::ResetInfo(UFG::PredictiveStreamingStats::PlayerInfo *this)
{
  __int64 v1; // r8
  signed int size; // eax
  __int64 v4; // rdx
  __int64 v5; // r10
  __int64 v6; // rcx
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *m_PlayerWeaponInfo; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *m_PlayerVehicleInfo; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *m_PlayerBoatInfo; // rax
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *v10; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v11; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v12; // rax
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *v13; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v14; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v15; // rax
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *v16; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v17; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v18; // rax
  __int64 v19; // rcx
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *v20; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v21; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v22; // rax

  v1 = 0i64;
  if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
    size = 0;
  else
    size = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
  v4 = size;
  *(_WORD *)&this->m_bIsDriver = 0;
  if ( size >= 4i64 )
  {
    v5 = size - 3i64;
    v6 = 0i64;
    do
    {
      m_PlayerWeaponInfo = this->m_PlayerWeaponInfo;
      v1 += 4i64;
      v6 += 4i64;
      m_PlayerWeaponInfo[v1 - 4].m_fDistanceSquared = 3.4028235e38;
      *((_BYTE *)&m_PlayerWeaponInfo[v1 - 3] - 4) = 0;
      m_PlayerVehicleInfo = this->m_PlayerVehicleInfo;
      m_PlayerVehicleInfo[v6 - 4].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&m_PlayerVehicleInfo[v6 - 3] - 2) = 2139095039;
      *((_WORD *)&m_PlayerVehicleInfo[v6 - 3] - 2) = 0;
      m_PlayerBoatInfo = this->m_PlayerBoatInfo;
      m_PlayerBoatInfo[v6 - 4].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&m_PlayerBoatInfo[v6 - 3] - 2) = 2139095039;
      *((_WORD *)&m_PlayerBoatInfo[v6 - 3] - 2) = 0;
      v10 = this->m_PlayerWeaponInfo;
      v10[v1 - 3].m_fDistanceSquared = 3.4028235e38;
      *((_BYTE *)&v10[v1 - 2] - 4) = 0;
      v11 = this->m_PlayerVehicleInfo;
      v11[v6 - 3].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v11[v6 - 2] - 2) = 2139095039;
      *((_WORD *)&v11[v6 - 2] - 2) = 0;
      v12 = this->m_PlayerBoatInfo;
      v12[v6 - 3].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v12[v6 - 2] - 2) = 2139095039;
      *((_WORD *)&v12[v6 - 2] - 2) = 0;
      v13 = this->m_PlayerWeaponInfo;
      v13[v1 - 2].m_fDistanceSquared = 3.4028235e38;
      *((_BYTE *)&v13[v1 - 1] - 4) = 0;
      v14 = this->m_PlayerVehicleInfo;
      v14[v6 - 2].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v14[v6 - 1] - 2) = 2139095039;
      *((_WORD *)&v14[v6 - 1] - 2) = 0;
      v15 = this->m_PlayerBoatInfo;
      v15[v6 - 2].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v15[v6 - 1] - 2) = 2139095039;
      *((_WORD *)&v15[v6 - 1] - 2) = 0;
      v16 = this->m_PlayerWeaponInfo;
      v16[v1 - 1].m_fDistanceSquared = 3.4028235e38;
      v16[v1 - 1].m_bOwned = 0;
      v17 = this->m_PlayerVehicleInfo;
      v17[v6 - 1].m_fDistanceToDriverSide = 3.4028235e38;
      v17[v6 - 1].m_fDistanceToPassengerSide = 3.4028235e38;
      *(_WORD *)&v17[v6 - 1].m_bIsDriver = 0;
      v18 = this->m_PlayerBoatInfo;
      v18[v6 - 1].m_fDistanceToDriverSide = 3.4028235e38;
      v18[v6 - 1].m_fDistanceToPassengerSide = 3.4028235e38;
      *(_WORD *)&v18[v6 - 1].m_bIsDriver = 0;
    }
    while ( v1 < v5 );
  }
  if ( v1 < v4 )
  {
    v19 = v1;
    do
    {
      v20 = this->m_PlayerWeaponInfo;
      ++v1;
      ++v19;
      v20[v1 - 1].m_fDistanceSquared = 3.4028235e38;
      v20[v1 - 1].m_bOwned = 0;
      v21 = this->m_PlayerVehicleInfo;
      v21[v19 - 1].m_fDistanceToDriverSide = 3.4028235e38;
      v21[v19 - 1].m_fDistanceToPassengerSide = 3.4028235e38;
      *(_WORD *)&v21[v19 - 1].m_bIsDriver = 0;
      v22 = this->m_PlayerBoatInfo;
      v22[v19 - 1].m_fDistanceToDriverSide = 3.4028235e38;
      v22[v19 - 1].m_fDistanceToPassengerSide = 3.4028235e38;
      *(_WORD *)&v22[v19 - 1].m_bIsDriver = 0;
    }
    while ( v1 < v4 );
  }
}

// File Line: 141
// RVA: 0x3E91B0
void __fastcall UFG::PredictiveStreamingStats::Init(UFG::PredictiveStreamingStats *this)
{
  signed int size; // eax
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // kr00_8
  bool **p_m_bHasPassengerByWeaponType; // rdi
  __int64 v6; // rbp
  signed int v7; // eax
  unsigned __int64 v8; // rbx
  bool **v9; // rdi
  __int64 v10; // rbp
  signed int v11; // eax
  unsigned __int64 v12; // rbx
  UFG::PredictiveStreamingStats::CharacterInfo *m_CharacterInfo; // rbx
  __int64 v14; // rdi
  signed int v15; // eax

  if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
    size = 0;
  else
    size = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
  v4 = size;
  v3 = 2i64 * size;
  if ( !is_mul_ok(v4, 2ui64) )
    v3 = -1i64;
  this->m_WeaponInfo = (UFG::PredictiveStreamingStats::WeaponInfo *)UFG::qMalloc(v3, "PredictiveStreamingStats", 0i64);
  UFG::PredictiveStreamingStats::PlayerInfo::Init(&this->m_PlayerInfo);
  p_m_bHasPassengerByWeaponType = &this->m_VehicleInfo[0].m_bHasPassengerByWeaponType;
  v6 = 10i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v7 = 0;
    else
      v7 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    v8 = v7;
    *(p_m_bHasPassengerByWeaponType - 1) = (bool *)UFG::qMalloc(v7, "PredictiveStreamingStats", 0i64);
    *p_m_bHasPassengerByWeaponType = (bool *)UFG::qMalloc(v8, "PredictiveStreamingStats", 0i64);
    p_m_bHasPassengerByWeaponType[1] = (bool *)UFG::qMalloc(v8, "PredictiveStreamingStats", 0i64);
    p_m_bHasPassengerByWeaponType += 5;
    *(p_m_bHasPassengerByWeaponType - 3) = (bool *)UFG::qMalloc(v8, "PredictiveStreamingStats", 0i64);
    --v6;
  }
  while ( v6 );
  v9 = &this->m_BoatInfo[0].m_bHasPassengerByWeaponType;
  v10 = 7i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v11 = 0;
    else
      v11 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    v12 = v11;
    *(v9 - 1) = (bool *)UFG::qMalloc(v11, "PredictiveStreamingStats", 0i64);
    *v9 = (bool *)UFG::qMalloc(v12, "PredictiveStreamingStats", 0i64);
    v9[1] = (bool *)UFG::qMalloc(v12, "PredictiveStreamingStats", 0i64);
    v9 += 5;
    *(v9 - 3) = (bool *)UFG::qMalloc(v12, "PredictiveStreamingStats", 0i64);
    --v10;
  }
  while ( v10 );
  m_CharacterInfo = this->m_CharacterInfo;
  v14 = 43i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v15 = 0;
    else
      v15 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    ++m_CharacterInfo;
    m_CharacterInfo[-1].m_bHasWeaponTypeEquipped = (bool *)UFG::qMalloc(v15, "PredictiveStreamingStats", 0i64);
    --v14;
  }
  while ( v14 );
}

// File Line: 170
// RVA: 0x3EAA50
void __fastcall UFG::PredictiveStreamingStats::ResetInfo(UFG::PredictiveStreamingStats *this)
{
  signed int size; // ebx
  __int64 i; // rcx
  bool *p_m_bTargetedForInteractionOnFootDriverSide; // rdx
  __int64 v5; // r9
  signed int v6; // eax
  __int64 v7; // rcx
  bool *v8; // rax
  __int64 v9; // r9
  signed int v10; // ecx
  __int64 v11; // rdx
  UFG::PredictiveStreamingStats::CharacterInfo *m_CharacterInfo; // rbx
  __int64 v13; // rdi
  unsigned int v14; // r8d

  if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
    size = 0;
  else
    size = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
  UFG::PredictiveStreamingStats::PlayerInfo::ResetInfo(&this->m_PlayerInfo);
  for ( i = 0i64; i < size; this->m_WeaponInfo[i - 1] = 0 )
    ++i;
  p_m_bTargetedForInteractionOnFootDriverSide = &this->m_VehicleInfo[0].m_bTargetedForInteractionOnFootDriverSide;
  v5 = 10i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v6 = 0;
    else
      v6 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    v7 = 0i64;
    for ( *(_DWORD *)(p_m_bTargetedForInteractionOnFootDriverSide - 2) = 0;
          v7 < v6;
          *(_BYTE *)(v7 + *(_QWORD *)(p_m_bTargetedForInteractionOnFootDriverSide + 30) - 1) = 0 )
    {
      *(_BYTE *)(++v7 + *(_QWORD *)(p_m_bTargetedForInteractionOnFootDriverSide + 6) - 1) = 0;
      *(_BYTE *)(v7 + *(_QWORD *)(p_m_bTargetedForInteractionOnFootDriverSide + 14) - 1) = 0;
      *(_BYTE *)(v7 + *(_QWORD *)(p_m_bTargetedForInteractionOnFootDriverSide + 22) - 1) = 0;
    }
    p_m_bTargetedForInteractionOnFootDriverSide += 40;
    --v5;
  }
  while ( v5 );
  v8 = &this->m_BoatInfo[0].m_bTargetedForInteractionOnFootDriverSide;
  v9 = 7i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v10 = 0;
    else
      v10 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    v11 = 0i64;
    for ( *(_DWORD *)(v8 - 2) = 0; v11 < v10; *(_BYTE *)(v11 + *(_QWORD *)(v8 + 30) - 1) = 0 )
    {
      *(_BYTE *)(++v11 + *(_QWORD *)(v8 + 6) - 1) = 0;
      *(_BYTE *)(v11 + *(_QWORD *)(v8 + 14) - 1) = 0;
      *(_BYTE *)(v11 + *(_QWORD *)(v8 + 22) - 1) = 0;
    }
    v8 += 40;
    --v9;
  }
  while ( v9 );
  m_CharacterInfo = this->m_CharacterInfo;
  v13 = 43i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v14 = 0;
    else
      v14 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    UFG::qMemSet(m_CharacterInfo->m_bHasWeaponTypeEquipped, 0, v14);
    ++m_CharacterInfo;
    --v13;
  }
  while ( v13 );
}

// File Line: 201
// RVA: 0x3EAE40
void __fastcall UFG::PredictiveStreamingStats::UpdateCachedInfo(UFG::PredictiveStreamingStats *this)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObjectCVBase *v3; // rcx
  UFG::TargetingSystemPedPlayerComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  UFG::SimObjectGame *m_pPlayerSimObject; // rcx
  __int16 v7; // dx
  unsigned int v8; // edx
  bool v9; // zf

  LocalPlayer = UFG::GetLocalPlayer();
  v3 = LocalPlayer;
  this->m_pPlayerSimObject = LocalPlayer;
  if ( LocalPlayer )
    LocalPlayer = (UFG::SimObjectCharacter *)LocalPlayer->m_pTransformNodeComponent;
  this->m_pPlayerTNC = (UFG::TransformNodeComponent *)LocalPlayer;
  if ( v3 )
  {
    m_Flags = v3->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v3);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v3,
                                                                      UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v3,
                                                                      UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  m_pPlayerSimObject = (UFG::SimObjectGame *)this->m_pPlayerSimObject;
  this->m_pPlayerTSC = ComponentOfTypeHK;
  if ( !m_pPlayerSimObject )
  {
    this->m_pPlayerCOC = 0i64;
    return;
  }
  v7 = m_pPlayerSimObject->m_Flags;
  if ( (v7 & 0x4000) != 0 )
  {
    this->m_pPlayerCOC = (UFG::CharacterOccupantComponent *)m_pPlayerSimObject->m_Components.p[44].m_pComponent;
    return;
  }
  if ( v7 < 0 || (v7 & 0x2000) != 0 )
  {
    v8 = UFG::CharacterOccupantComponent::_TypeUID;
LABEL_18:
    this->m_pPlayerCOC = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPlayerSimObject,
                                                              v8);
    return;
  }
  v9 = (v7 & 0x1000) == 0;
  v8 = UFG::CharacterOccupantComponent::_TypeUID;
  if ( !v9 )
    goto LABEL_18;
  this->m_pPlayerCOC = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPlayerSimObject,
                                                            UFG::CharacterOccupantComponent::_TypeUID);
}

// File Line: 213
// RVA: 0x3EACE0
void __fastcall UFG::PredictiveStreamingStats::Update(UFG::PredictiveStreamingStats *this, const float fTimeDeltaS)
{
  UFG::PredictiveStreamingStats::ResetInfo(this);
  UFG::PredictiveStreamingStats::UpdateCachedInfo(this);
  UFG::PredictiveStreamingStats::UpdatePlayerVehicleInfo(this);
  UFG::PredictiveStreamingStats::UpdatePlayerWeaponInfo(this);
  UFG::PredictiveStreamingStats::UpdateWeaponInfo(this);
  UFG::PredictiveStreamingStats::UpdateVehicleInfo(this);
}

// File Line: 237
// RVA: 0x3EAF70
void __fastcall UFG::PredictiveStreamingStats::UpdatePlayerVehicleInfo(UFG::PredictiveStreamingStats *this)
{
  UFG::CharacterOccupantComponent *m_pPlayerCOC; // rdi
  UFG::SimObjectCVBase *CurrentVehicle; // rax
  bool v4; // di
  bool v5; // si
  UFG::SimObjectVehiclePropertiesComponent *v6; // rax
  __int64 m_eSimObjectVehicleType; // r8
  __int64 v8; // rdx
  __int64 m_eSimObjectBoatType; // rcx

  m_pPlayerCOC = this->m_pPlayerCOC;
  if ( m_pPlayerCOC )
  {
    CurrentVehicle = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(this->m_pPlayerCOC);
    if ( CurrentVehicle )
    {
      v4 = m_pPlayerCOC->mTargetType == eTARGET_TYPE_VEHICLE_DRIVER;
      this->m_PlayerInfo.m_bIsDriver = v4;
      v5 = !v4;
      this->m_PlayerInfo.m_bIsPassenger = !v4;
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(CurrentVehicle);
      if ( v6 )
      {
        m_eSimObjectVehicleType = v6->m_eSimObjectVehicleType;
        v8 = m_eSimObjectVehicleType;
        this->m_PlayerInfo.m_PlayerVehicleInfo[v8].m_bIsDriver = v4;
        this->m_PlayerInfo.m_PlayerVehicleInfo[v8].m_bIsPassenger = v5;
        if ( (_DWORD)m_eSimObjectVehicleType == 3 )
        {
          m_eSimObjectBoatType = v6->m_eSimObjectBoatType;
          this->m_PlayerInfo.m_PlayerBoatInfo[m_eSimObjectBoatType].m_bIsDriver = v4;
          this->m_PlayerInfo.m_PlayerBoatInfo[m_eSimObjectBoatType].m_bIsPassenger = v5;
        }
      }
    }
  }
}

// File Line: 274
// RVA: 0x3EB010
void __fastcall UFG::PredictiveStreamingStats::UpdatePlayerWeaponInfo(UFG::PredictiveStreamingStats *this)
{
  UFG::TransformNodeComponent *m_pPlayerTNC; // rcx
  UFG::TargetingSystemPedPlayerComponent *m_pPlayerTSC; // rbx
  unsigned __int8 *m_pTargetingMap; // rsi
  UFG::TargetingSimObject *m_pTargets; // rbx
  UFG::SimObjectProp *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectProp *v9; // rcx
  __int16 v10; // dx
  UFG::SimObjectWeaponPropertiesComponent *v11; // rax
  UFG::SimObjectProp *v12; // rcx
  __int16 v13; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax

  m_pPlayerTNC = this->m_pPlayerTNC;
  m_pPlayerTSC = this->m_pPlayerTSC;
  if ( m_pPlayerTSC )
  {
    if ( m_pPlayerTNC )
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pPlayerTNC);
    m_pTargetingMap = (unsigned __int8 *)m_pPlayerTSC->m_pTargetingMap;
    m_pTargets = m_pPlayerTSC->m_pTargets;
    m_pPointer = (UFG::SimObjectProp *)m_pTargets[m_pTargetingMap[25]].m_pTarget.m_pPointer;
    if ( !m_pPointer )
      goto LABEL_15;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      goto LABEL_11;
    if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(m_pPointer);
      goto LABEL_13;
    }
    if ( (m_Flags & 0x1000) != 0 )
LABEL_11:
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pPointer,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       m_pPointer,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_13:
    if ( ComponentOfTypeHK )
      this->m_PlayerInfo.m_PlayerWeaponInfo[ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[ComponentOfTypeHK->mFireMode]->mSimObjectWeaponType].m_bOwned = 1;
LABEL_15:
    v9 = (UFG::SimObjectProp *)m_pTargets[m_pTargetingMap[50]].m_pTarget.m_pPointer;
    if ( !v9 )
    {
LABEL_26:
      v12 = (UFG::SimObjectProp *)m_pTargets[m_pTargetingMap[51]].m_pTarget.m_pPointer;
      if ( !v12 )
        return;
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 || v13 < 0 )
        goto LABEL_33;
      if ( (v13 & 0x2000) != 0 )
      {
        ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v12);
        goto LABEL_35;
      }
      if ( (v13 & 0x1000) != 0 )
LABEL_33:
        ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v12,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      else
        ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v12,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_35:
      if ( ComponentOfType )
        this->m_PlayerInfo.m_PlayerWeaponInfo[ComponentOfType->mWeaponTypeInfo->mFireModes[ComponentOfType->mFireMode]->mSimObjectWeaponType].m_bOwned = 1;
      return;
    }
    v10 = v9->m_Flags;
    if ( (v10 & 0x4000) != 0 || v10 < 0 )
      goto LABEL_22;
    if ( (v10 & 0x2000) != 0 )
    {
      v11 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v9);
      goto LABEL_24;
    }
    if ( (v10 & 0x1000) != 0 )
LABEL_22:
      v11 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v9,
                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    else
      v11 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                         v9,
                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_24:
    if ( v11 )
      this->m_PlayerInfo.m_PlayerWeaponInfo[v11->mWeaponTypeInfo->mFireModes[v11->mFireMode]->mSimObjectWeaponType].m_bOwned = 1;
    goto LABEL_26;
  }
}

// File Line: 329
// RVA: 0x3EBEB0
void __fastcall UFG::PredictiveStreamingStats::UpdateWeaponInfo(UFG::PredictiveStreamingStats *this)
{
  UFG::TransformNodeComponent *m_pPlayerTNC; // rbx
  UFG::TargetingSystemPedPlayerComponent *m_pPlayerTSC; // rdi
  UFG::SimObjectGame *m_pPointer; // r8
  float x; // xmm6_4
  float y; // xmm7_4
  UFG::SimObjectGame *v6; // rdx
  float z; // xmm8_4
  UFG::SimObjectGame *v9; // r9
  unsigned __int8 *m_pTargetingMap; // rcx
  UFG::TargetingSimObject *m_pTargets; // rdx
  UFG::qList<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent,1,0> *p_mNext; // rax
  UFG::SimObjectGame *mNext; // rbx
  UFG::qList<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent,1,0> *v14; // r12
  __int64 v15; // rsi
  float *m_pTransformNodeComponent; // rdi
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *m_PlayerWeaponInfo; // rcx
  float m_fDistanceSquared; // xmm0_4
  UFG::PredictiveStreamingStats::WeaponInfo *m_WeaponInfo; // r14
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::TargetingSimObject *mPrev; // rbx
  UFG::SimObject **p_m_pSimObject; // rbp
  char mValue; // cl
  UFG::TargetingSimObject *v25; // rdi
  UFG::SimObjectCVBase *Owner; // rax
  __int16 v27; // dx
  UFG::SimObjectCharacterPropertiesComponent *v28; // rax
  UFG::SimObjectGame *v29; // [rsp+90h] [rbp+8h]
  UFG::SimObjectGame *v30; // [rsp+98h] [rbp+10h]
  UFG::SimObjectGame *v31; // [rsp+A0h] [rbp+18h]

  m_pPlayerTNC = this->m_pPlayerTNC;
  m_pPlayerTSC = this->m_pPlayerTSC;
  m_pPointer = 0i64;
  x = UFG::qVector3::msZero.x;
  y = UFG::qVector3::msZero.y;
  v6 = 0i64;
  v29 = 0i64;
  z = UFG::qVector3::msZero.z;
  v9 = 0i64;
  v30 = 0i64;
  v31 = 0i64;
  if ( m_pPlayerTNC && m_pPlayerTSC )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pPlayerTNC);
    m_pTargetingMap = (unsigned __int8 *)m_pPlayerTSC->m_pTargetingMap;
    m_pTargets = m_pPlayerTSC->m_pTargets;
    x = m_pPlayerTNC->mWorldTransform.v3.x;
    y = m_pPlayerTNC->mWorldTransform.v3.y;
    z = m_pPlayerTNC->mWorldTransform.v3.z;
    m_pPointer = (UFG::SimObjectGame *)m_pTargets[m_pTargetingMap[25]].m_pTarget.m_pPointer;
    v29 = m_pPointer;
    v9 = (UFG::SimObjectGame *)m_pTargets[m_pTargetingMap[50]].m_pTarget.m_pPointer;
    v30 = v9;
    v6 = (UFG::SimObjectGame *)m_pTargets[m_pTargetingMap[51]].m_pTarget.m_pPointer;
    v31 = v6;
  }
  p_mNext = (UFG::qList<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent,1,0> *)&UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mNext[-10].mNext;
  if ( &UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mNext[-10].mNext != (UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> **)((char *)&UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList - 152) )
  {
    do
    {
      mNext = (UFG::SimObjectGame *)p_mNext[2].mNode.mNext;
      v14 = (UFG::qList<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent,1,0> *)&p_mNext[10].mNode.mPrev[-10].mNext;
      v15 = **((unsigned int **)&p_mNext[11].mNode.mPrev->mNext + HIDWORD(p_mNext[10].mNode.mNext));
      if ( mNext != m_pPointer && mNext != v9 && mNext != v6 )
      {
        if ( mNext )
        {
          m_pTransformNodeComponent = (float *)mNext->m_pTransformNodeComponent;
          if ( m_pTransformNodeComponent )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(mNext->m_pTransformNodeComponent);
            m_PlayerWeaponInfo = this->m_PlayerInfo.m_PlayerWeaponInfo;
            m_fDistanceSquared = m_PlayerWeaponInfo[v15].m_fDistanceSquared;
            if ( m_fDistanceSquared >= (float)((float)((float)((float)(x - m_pTransformNodeComponent[44])
                                                             * (float)(x - m_pTransformNodeComponent[44]))
                                                     + (float)((float)(y - m_pTransformNodeComponent[45])
                                                             * (float)(y - m_pTransformNodeComponent[45])))
                                             + (float)((float)(z - m_pTransformNodeComponent[46])
                                                     * (float)(z - m_pTransformNodeComponent[46]))) )
              m_fDistanceSquared = (float)((float)((float)(x - m_pTransformNodeComponent[44])
                                                 * (float)(x - m_pTransformNodeComponent[44]))
                                         + (float)((float)(y - m_pTransformNodeComponent[45])
                                                 * (float)(y - m_pTransformNodeComponent[45])))
                                 + (float)((float)(z - m_pTransformNodeComponent[46])
                                         * (float)(z - m_pTransformNodeComponent[46]));
            m_PlayerWeaponInfo[v15].m_fDistanceSquared = m_fDistanceSquared;
          }
        }
      }
      m_WeaponInfo = this->m_WeaponInfo;
      if ( mNext )
      {
        m_Flags = mNext->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = mNext->m_Components.p[20].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                       ? UFG::SimObjectGame::GetComponentOfTypeHK(mNext, UFG::TargetingSystemBaseComponent::_TypeUID)
                       : UFG::SimObject::GetComponentOfType(mNext, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          m_pComponent = mNext->m_Components.p[20].m_pComponent;
        }
        if ( m_pComponent )
        {
          mPrev = (UFG::TargetingSimObject *)m_pComponent[1].m_BoundComponentHandles.mNode.mPrev;
          p_m_pSimObject = &m_pComponent[1].m_pSimObject;
          if ( mPrev != (UFG::TargetingSimObject *)&m_pComponent[1].m_pSimObject )
          {
            do
            {
              mValue = mPrev->m_eTargetType.mValue;
              v25 = (UFG::TargetingSimObject *)mPrev->mNext;
              if ( mValue == 17 || (unsigned __int8)(mValue - 42) <= 1u )
                m_WeaponInfo[v15].m_bOwned = 1;
              if ( mValue == 17 )
              {
                Owner = (UFG::SimObjectCVBase *)UFG::TargetingSimObject::GetOwner(mPrev);
                if ( Owner )
                {
                  v27 = Owner->m_Flags;
                  if ( (v27 & 0x4000) != 0 || v27 < 0 )
                    v28 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(Owner);
                  else
                    v28 = (UFG::SimObjectCharacterPropertiesComponent *)((v27 & 0x2000) != 0 || (v27 & 0x1000) != 0
                                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           Owner,
                                                                           UFG::SimObjectCharacterPropertiesComponent::_TypeUID)
                                                                       : UFG::SimObject::GetComponentOfType(
                                                                           Owner,
                                                                           UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
                  if ( v28 )
                    this->m_CharacterInfo[v28->m_eCharacterType].m_bHasWeaponTypeEquipped[v15] = 1;
                }
              }
              if ( mPrev->m_eTargetType.mValue == 41 && mPrev->m_pTarget.m_pPointer && mPrev->m_bLock )
                m_WeaponInfo[v15].m_bTargetedForInteractionOnFoot = 1;
              mPrev = v25;
            }
            while ( v25 != (UFG::TargetingSimObject *)p_m_pSimObject );
          }
        }
      }
      m_pPointer = v29;
      v9 = v30;
      v6 = v31;
      p_mNext = v14;
    }
    while ( v14 != (UFG::qList<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent,1,0> *)((char *)&UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList - 152) );
  }
}

// File Line: 427
// RVA: 0x3EB2B0
void __fastcall UFG::PredictiveStreamingStats::UpdateVehicleInfo(UFG::PredictiveStreamingStats *this)
{
  UFG::TransformNodeComponent *m_pPlayerTNC; // rdi
  UFG::CharacterOccupantComponent *m_pPlayerCOC; // rcx
  UFG::VehicleOccupantComponent *CurrentVehicle; // r15
  UFG::qVector3 *v5; // rax
  float x; // xmm11_4
  float y; // xmm12_4
  float z; // xmm13_4
  char *p_mNext; // rax
  char *v10; // rdx
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *m_PlayerBoatInfo; // rbp
  __int64 v12; // r13
  UFG::SimObjectCVBase *v13; // rdi
  UFG::TransformNodeComponent *m_pComponent; // r14
  UFG::TargetingSystemVehicleComponent *v15; // rax
  UFG::TargetingSystemVehicleComponent *v16; // rsi
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *m_PlayerVehicleInfo; // r12
  __int64 v18; // rdi
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm8_4
  float v22; // xmm7_4
  float v23; // xmm9_4
  float v24; // xmm10_4
  float v25; // xmm2_4
  float m_fDistanceToPassengerSide; // xmm0_4
  float v27; // xmm4_4
  float v28; // xmm0_4
  float m_fDistanceToDriverSide; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  UFG::TargetingSimObject *mNext; // rdi
  UFG::TargetingSimObject *p_m_TargetedBy; // r14
  __int64 v34; // r12
  __int64 v35; // rsi
  UFG::TargetingSimObject *v36; // rax
  UFG::TargetingSimObject *v37; // r14
  UFG::SimObjectGame *Owner; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *v40; // rax
  __int64 v41; // rsi
  bool v42; // r15
  __int64 v43; // rbp
  UFG::TargetingSystemBaseComponent *m_pTSBC; // rax
  UFG::TargetingSimObject *m_pTargets; // r14
  unsigned __int8 *m_pTargetingMap; // rdi
  unsigned int mSimObjectWeaponType; // r13d
  unsigned int v48; // r12d
  UFG::SimObjectProp *m_pPointer; // rcx
  __int16 v50; // dx
  UFG::SimObjectWeaponPropertiesComponent *v51; // rax
  UFG::SimObjectProp *v52; // rcx
  __int16 v53; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectProp *v55; // rcx
  __int16 v56; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  __int64 v58; // rcx
  bool *m_bHasDriverByWeaponType; // rax
  char *v60; // rdi
  char *v61; // rdx
  __int64 v62; // rsi
  __int64 v63; // r15
  __int16 v64; // cx
  UFG::SimComponent *v65; // rax
  bool v66; // zf
  UFG::SimObjectGame *v67; // rcx
  unsigned __int8 *v68; // rbp
  __int64 v69; // r14
  int v70; // r12d
  int v71; // r13d
  UFG::SimObjectGame *v72; // rcx
  __int16 v73; // dx
  UFG::SimComponent *v74; // rax
  CAkChainCtx *v75; // rdi
  CAkScheduledItem *SimObjectWeaponPropertiesComponent; // rax
  CAkScheduledItem *v77; // rax
  UFG::SimObjectGame *v78; // rcx
  __int16 v79; // dx
  UFG::SimComponent *v80; // rax
  CAkChainCtx *v81; // rdi
  CAkScheduledItem *v82; // rax
  CAkScheduledItem *v83; // rax
  UFG::SimObjectGame *v84; // rcx
  __int16 v85; // dx
  UFG::SimComponent *v86; // rax
  CAkChainCtx *v87; // rdi
  CAkScheduledItem *v88; // rax
  CAkScheduledItem *v89; // rax
  UFG::SimObjectCVBase *v90; // rdi
  __int16 v91; // cx
  UFG::SimObjectVehiclePropertiesComponent *v92; // rax
  UFG::SimObjectVehiclePropertiesComponent *v93; // rbp
  UFG::TransformNodeComponent *v94; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  __int64 m_eSimObjectVehicleType; // rax
  __int64 m_eSimObjectBoatType; // r10
  __int64 v98; // rcx
  bool *m_bTargetedForInteractionPassengerSideOnFootByWeaponType; // rax
  bool *v100; // rax
  bool *v101; // rax
  bool *m_bTargetedForInteractionDriverSideOnFootByWeaponType; // rax
  bool *v103; // rax
  UFG::TargetingSimObject *v104; // [rsp+20h] [rbp-E8h]
  __int64 v105; // [rsp+28h] [rbp-E0h]
  UFG::VehicleOccupantComponent *v106; // [rsp+30h] [rbp-D8h]
  __int64 v107; // [rsp+38h] [rbp-D0h]
  int v108; // [rsp+110h] [rbp+8h]
  unsigned int v109; // [rsp+110h] [rbp+8h]
  int v110; // [rsp+110h] [rbp+8h]
  UFG::TargetingSimObject *v111; // [rsp+118h] [rbp+10h]
  __int64 v112; // [rsp+128h] [rbp+20h]

  m_pPlayerTNC = this->m_pPlayerTNC;
  m_pPlayerCOC = this->m_pPlayerCOC;
  if ( m_pPlayerCOC )
    CurrentVehicle = UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pPlayerCOC);
  else
    CurrentVehicle = 0i64;
  v106 = CurrentVehicle;
  if ( m_pPlayerTNC )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pPlayerTNC);
    v5 = (UFG::qVector3 *)&m_pPlayerTNC->mWorldTransform.v3;
  }
  else
  {
    v5 = &UFG::qVector3::msZero;
  }
  x = v5->x;
  y = v5->y;
  z = v5->z;
  p_mNext = (char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mNext[-10].mNext;
  if ( &UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mNext[-10].mNext != (UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> **)((char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152) )
  {
    v10 = (char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152;
    do
    {
      m_PlayerBoatInfo = (UFG::PredictiveStreamingStats::PlayerVehicleInfo *)*((int *)p_mNext + 43);
      v12 = *((int *)p_mNext + 42);
      v108 = *((_DWORD *)p_mNext + 43);
      v107 = *((_QWORD *)p_mNext + 20) - 152i64;
      v13 = (UFG::SimObjectCVBase *)*((_QWORD *)p_mNext + 5);
      if ( v13 )
      {
        m_pComponent = (UFG::TransformNodeComponent *)v13->m_Components.p[2].m_pComponent;
        v15 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(v13);
        v16 = v15;
        if ( m_pComponent && v15 )
        {
          if ( v13 != (UFG::SimObjectCVBase *)CurrentVehicle )
          {
            m_PlayerVehicleInfo = this->m_PlayerInfo.m_PlayerVehicleInfo;
            v18 = (__int64)m_PlayerBoatInfo;
            m_PlayerBoatInfo = this->m_PlayerInfo.m_PlayerBoatInfo;
            UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
            v19 = m_pComponent->mWorldTransform.v3.x;
            v20 = m_pComponent->mWorldTransform.v3.y;
            v21 = s_fDistanceToSideOfVehicleOfVehicle * m_pComponent->mWorldTransform.v1.z;
            v22 = m_pComponent->mWorldTransform.v3.z;
            v23 = s_fDistanceToSideOfVehicleOfVehicle * m_pComponent->mWorldTransform.v1.x;
            v24 = s_fDistanceToSideOfVehicleOfVehicle * m_pComponent->mWorldTransform.v1.y;
            v25 = z - (float)(v21 + v22);
            m_fDistanceToPassengerSide = m_PlayerVehicleInfo[v12].m_fDistanceToPassengerSide;
            v27 = (float)((float)((float)(y - (float)(v24 + v20)) * (float)(y - (float)(v24 + v20)))
                        + (float)((float)(x - (float)(v23 + v19)) * (float)(x - (float)(v23 + v19))))
                + (float)(v25 * v25);
            if ( m_fDistanceToPassengerSide >= v27 )
              m_fDistanceToPassengerSide = (float)((float)((float)(y - (float)(v24 + v20))
                                                         * (float)(y - (float)(v24 + v20)))
                                                 + (float)((float)(x - (float)(v23 + v19))
                                                         * (float)(x - (float)(v23 + v19))))
                                         + (float)(v25 * v25);
            m_PlayerVehicleInfo[v12].m_fDistanceToPassengerSide = m_fDistanceToPassengerSide;
            v28 = m_PlayerBoatInfo[v18].m_fDistanceToPassengerSide;
            if ( v28 >= v27 )
              v28 = (float)((float)((float)(y - (float)(v24 + v20)) * (float)(y - (float)(v24 + v20)))
                          + (float)((float)(x - (float)(v23 + v19)) * (float)(x - (float)(v23 + v19))))
                  + (float)(v25 * v25);
            m_PlayerBoatInfo[v18].m_fDistanceToPassengerSide = v28;
            m_fDistanceToDriverSide = m_PlayerVehicleInfo[v12].m_fDistanceToDriverSide;
            v30 = (float)((float)((float)(y - (float)(v20 - v24)) * (float)(y - (float)(v20 - v24)))
                        + (float)((float)(x - (float)(v19 - v23)) * (float)(x - (float)(v19 - v23))))
                + (float)((float)(z - (float)(v22 - v21)) * (float)(z - (float)(v22 - v21)));
            if ( m_fDistanceToDriverSide >= v30 )
              m_fDistanceToDriverSide = (float)((float)((float)(y - (float)(v20 - v24)) * (float)(y - (float)(v20 - v24)))
                                              + (float)((float)(x - (float)(v19 - v23)) * (float)(x - (float)(v19 - v23))))
                                      + (float)((float)(z - (float)(v22 - v21)) * (float)(z - (float)(v22 - v21)));
            m_PlayerVehicleInfo[v12].m_fDistanceToDriverSide = m_fDistanceToDriverSide;
            v31 = m_PlayerBoatInfo[v18].m_fDistanceToDriverSide;
            if ( v31 >= v30 )
              v31 = (float)((float)((float)(y - (float)(v20 - v24)) * (float)(y - (float)(v20 - v24)))
                          + (float)((float)(x - (float)(v19 - v23)) * (float)(x - (float)(v19 - v23))))
                  + (float)((float)(z - (float)(v22 - v21)) * (float)(z - (float)(v22 - v21)));
            m_PlayerBoatInfo[v18].m_fDistanceToDriverSide = v31;
            LODWORD(m_PlayerBoatInfo) = v108;
          }
          mNext = (UFG::TargetingSimObject *)v16->m_TargetedBy.mNode.mNext;
          p_m_TargetedBy = (UFG::TargetingSimObject *)&v16->m_TargetedBy;
          v34 = (int)m_PlayerBoatInfo;
          v35 = v12;
          v112 = v12;
          v105 = (int)m_PlayerBoatInfo;
          v111 = p_m_TargetedBy;
          if ( mNext != p_m_TargetedBy )
          {
            v36 = p_m_TargetedBy;
            while ( 2 )
            {
              v37 = (UFG::TargetingSimObject *)mNext->mNext;
              v104 = v37;
              if ( mNext->m_eTargetType.mValue != 28 || !mNext->m_pTarget.m_pPointer || !mNext->m_bLock )
                goto LABEL_77;
              Owner = (UFG::SimObjectGame *)UFG::TargetingSimObject::GetOwner(mNext);
              if ( !Owner )
                goto LABEL_76;
              m_Flags = Owner->m_Flags;
              if ( (m_Flags & 0x4000) != 0 )
                v40 = Owner->m_Components.p[44].m_pComponent;
              else
                v40 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                    ? UFG::SimObjectGame::GetComponentOfTypeHK(Owner, UFG::CharacterOccupantComponent::_TypeUID)
                    : UFG::SimObject::GetComponentOfType(Owner, UFG::CharacterOccupantComponent::_TypeUID);
              if ( !v40 )
                goto LABEL_76;
              v41 = v35;
              v42 = LODWORD(v40[1].m_SafePointerList.mNode.mNext) == 4;
              v43 = v34;
              this->m_VehicleInfo[v41].m_bHasDriver |= v42;
              this->m_VehicleInfo[v41].m_bHasPassenger |= !v42;
              this->m_BoatInfo[v34].m_bHasDriver |= v42;
              m_pTSBC = mNext->m_pTSBC;
              this->m_BoatInfo[v34].m_bHasPassenger |= !v42;
              if ( !m_pTSBC )
                goto LABEL_75;
              m_pTargets = m_pTSBC->m_pTargets;
              m_pTargetingMap = (unsigned __int8 *)m_pTSBC->m_pTargetingMap;
              mSimObjectWeaponType = 0;
              v48 = 0;
              v109 = 0;
              m_pPointer = (UFG::SimObjectProp *)m_pTargets[m_pTargetingMap[25]].m_pTarget.m_pPointer;
              if ( !m_pPointer )
                goto LABEL_49;
              v50 = m_pPointer->m_Flags;
              if ( (v50 & 0x4000) == 0 && v50 >= 0 )
              {
                if ( (v50 & 0x2000) != 0 )
                {
                  v51 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(m_pPointer);
LABEL_47:
                  if ( v51 )
                    mSimObjectWeaponType = v51->mWeaponTypeInfo->mFireModes[v51->mFireMode]->mSimObjectWeaponType;
LABEL_49:
                  v52 = (UFG::SimObjectProp *)m_pTargets[m_pTargetingMap[50]].m_pTarget.m_pPointer;
                  if ( !v52 )
                    goto LABEL_60;
                  v53 = v52->m_Flags;
                  if ( (v53 & 0x4000) == 0 && v53 >= 0 )
                  {
                    if ( (v53 & 0x2000) != 0 )
                    {
                      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v52);
LABEL_58:
                      if ( ComponentOfTypeHK )
                        v109 = ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[ComponentOfTypeHK->mFireMode]->mSimObjectWeaponType;
LABEL_60:
                      v55 = (UFG::SimObjectProp *)m_pTargets[m_pTargetingMap[51]].m_pTarget.m_pPointer;
                      if ( !v55 )
                        goto LABEL_71;
                      v56 = v55->m_Flags;
                      if ( (v56 & 0x4000) == 0 && v56 >= 0 )
                      {
                        if ( (v56 & 0x2000) != 0 )
                        {
                          ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v55);
LABEL_69:
                          if ( ComponentOfType )
                            v48 = ComponentOfType->mWeaponTypeInfo->mFireModes[ComponentOfType->mFireMode]->mSimObjectWeaponType;
LABEL_71:
                          v37 = v104;
                          v58 = v48;
                          v34 = v105;
                          if ( v42 )
                          {
                            this->m_VehicleInfo[v41].m_bHasDriverByWeaponType[mSimObjectWeaponType] = 1;
                            this->m_VehicleInfo[v41].m_bHasDriverByWeaponType[v109] = 1;
                            this->m_VehicleInfo[v41].m_bHasDriverByWeaponType[v58] = 1;
                            this->m_BoatInfo[v43].m_bHasDriverByWeaponType[mSimObjectWeaponType] = 1;
                            this->m_BoatInfo[v43].m_bHasDriverByWeaponType[v109] = 1;
                            m_bHasDriverByWeaponType = this->m_BoatInfo[v43].m_bHasDriverByWeaponType;
                          }
                          else
                          {
                            this->m_VehicleInfo[v41].m_bHasPassengerByWeaponType[mSimObjectWeaponType] = 1;
                            this->m_VehicleInfo[v41].m_bHasPassengerByWeaponType[v109] = 1;
                            this->m_VehicleInfo[v41].m_bHasPassengerByWeaponType[v58] = 1;
                            this->m_BoatInfo[v43].m_bHasPassengerByWeaponType[mSimObjectWeaponType] = 1;
                            this->m_BoatInfo[v43].m_bHasPassengerByWeaponType[v109] = 1;
                            m_bHasDriverByWeaponType = this->m_BoatInfo[v43].m_bHasPassengerByWeaponType;
                          }
                          m_bHasDriverByWeaponType[v58] = 1;
LABEL_75:
                          v35 = v112;
LABEL_76:
                          v36 = v111;
LABEL_77:
                          mNext = v37;
                          if ( v37 == v36 )
                            goto LABEL_78;
                          continue;
                        }
                        if ( (v56 & 0x1000) == 0 )
                        {
                          ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                                         v55,
                                                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                          goto LABEL_69;
                        }
                      }
                      ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                     v55,
                                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                      goto LABEL_69;
                    }
                    if ( (v53 & 0x1000) == 0 )
                    {
                      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                                       v52,
                                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                      goto LABEL_58;
                    }
                  }
                  ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                   v52,
                                                                                   UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                  goto LABEL_58;
                }
                if ( (v50 & 0x1000) == 0 )
                {
                  v51 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                     m_pPointer,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                  goto LABEL_47;
                }
              }
              break;
            }
            v51 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               m_pPointer,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
            goto LABEL_47;
          }
        }
LABEL_78:
        v10 = (char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152;
      }
      CurrentVehicle = v106;
      p_mNext = (char *)v107;
    }
    while ( (char *)v107 != v10 );
  }
  v60 = (char *)&UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList.mNode.mNext[-8].mNext;
  v61 = (char *)&UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList - 120;
  if ( &UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList.mNode.mNext[-8].mNext != (UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> **)((char *)&UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList - 120) )
  {
    do
    {
      v62 = *((_QWORD *)v60 + 5);
      v63 = *((_QWORD *)v60 + 16) - 120i64;
      if ( v62 )
      {
        v64 = *(_WORD *)(v62 + 76);
        if ( (v64 & 0x4000) != 0 )
        {
          v65 = *(UFG::SimComponent **)(*(_QWORD *)(v62 + 104) + 80i64);
        }
        else if ( v64 >= 0 )
        {
          if ( (v64 & 0x2000) != 0 )
          {
            v65 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    *((UFG::SimObjectGame **)v60 + 5),
                    UFG::AIScriptInterfaceComponent::_TypeUID);
          }
          else
          {
            v66 = (v64 & 0x1000) == 0;
            v67 = (UFG::SimObjectGame *)*((_QWORD *)v60 + 5);
            v65 = v66
                ? UFG::SimObject::GetComponentOfType(v67, UFG::AIScriptInterfaceComponent::_TypeUID)
                : UFG::SimObjectGame::GetComponentOfTypeHK(v67, UFG::AIScriptInterfaceComponent::_TypeUID);
          }
          v61 = (char *)&UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList - 120;
        }
        else
        {
          v65 = *(UFG::SimComponent **)(*(_QWORD *)(v62 + 104) + 80i64);
        }
        if ( v65 && (BYTE2(v65[32].m_BoundComponentHandles.mNode.mPrev) & 1) != 0 )
        {
          v68 = (unsigned __int8 *)*((_QWORD *)v60 + 12);
          v69 = *((_QWORD *)v60 + 11);
          v70 = 0;
          v71 = 0;
          v110 = 0;
          v72 = *(UFG::SimObjectGame **)(56i64 * v68[25] + v69 + 40);
          if ( v72 )
          {
            v73 = v72->m_Flags;
            if ( (v73 & 0x4000) != 0 || v73 < 0 || (v73 & 0x2000) != 0 || (v73 & 0x1000) != 0 )
              v74 = UFG::SimObjectGame::GetComponentOfTypeHK(v72, UFG::GunComponent::_TypeUID);
            else
              v74 = UFG::SimObject::GetComponentOfType(v72, UFG::GunComponent::_TypeUID);
            v75 = (CAkChainCtx *)v74;
            if ( v74 )
            {
              SimObjectWeaponPropertiesComponent = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v74);
              if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)&SimObjectWeaponPropertiesComponent[2].m_cmdStop.iRelativeTime
                                         + 8i64
                                         * (unsigned int)SimObjectWeaponPropertiesComponent[2].m_cmdPlay.fadeParams.iFadeOffset
                                         + 8)
                             + 100i64) != UFG::gNullQSymbolUC.mUID )
              {
                v77 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v75);
                v70 = **(_DWORD **)(*(_QWORD *)&v77[2].m_cmdStop.iRelativeTime
                                  + 8i64 * (unsigned int)v77[2].m_cmdPlay.fadeParams.iFadeOffset
                                  + 8);
              }
            }
          }
          v78 = *(UFG::SimObjectGame **)(56i64 * v68[50] + v69 + 40);
          if ( v78 )
          {
            v79 = v78->m_Flags;
            if ( (v79 & 0x4000) != 0 || v79 < 0 || (v79 & 0x2000) != 0 || (v79 & 0x1000) != 0 )
              v80 = UFG::SimObjectGame::GetComponentOfTypeHK(v78, UFG::GunComponent::_TypeUID);
            else
              v80 = UFG::SimObject::GetComponentOfType(v78, UFG::GunComponent::_TypeUID);
            v81 = (CAkChainCtx *)v80;
            if ( v80 )
            {
              v82 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v80);
              if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)&v82[2].m_cmdStop.iRelativeTime
                                         + 8i64 * (unsigned int)v82[2].m_cmdPlay.fadeParams.iFadeOffset
                                         + 8)
                             + 100i64) != UFG::gNullQSymbolUC.mUID )
              {
                v83 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v81);
                v71 = **(_DWORD **)(*(_QWORD *)&v83[2].m_cmdStop.iRelativeTime
                                  + 8i64 * (unsigned int)v83[2].m_cmdPlay.fadeParams.iFadeOffset
                                  + 8);
              }
            }
          }
          v84 = *(UFG::SimObjectGame **)(56i64 * v68[51] + v69 + 40);
          if ( v84 )
          {
            v85 = v84->m_Flags;
            if ( (v85 & 0x4000) != 0 || v85 < 0 || (v85 & 0x2000) != 0 || (v85 & 0x1000) != 0 )
              v86 = UFG::SimObjectGame::GetComponentOfTypeHK(v84, UFG::GunComponent::_TypeUID);
            else
              v86 = UFG::SimObject::GetComponentOfType(v84, UFG::GunComponent::_TypeUID);
            v87 = (CAkChainCtx *)v86;
            if ( v86 )
            {
              v88 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v86);
              if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)&v88[2].m_cmdStop.iRelativeTime
                                         + 8i64 * (unsigned int)v88[2].m_cmdPlay.fadeParams.iFadeOffset
                                         + 8)
                             + 100i64) != UFG::gNullQSymbolUC.mUID )
              {
                v89 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v87);
                v110 = **(_DWORD **)(*(_QWORD *)&v89[2].m_cmdStop.iRelativeTime
                                   + 8i64 * (unsigned int)v89[2].m_cmdPlay.fadeParams.iFadeOffset
                                   + 8);
              }
            }
          }
          v90 = *(UFG::SimObjectCVBase **)(56i64 * v68[36] + v69 + 40);
          if ( v90 )
          {
            v91 = v90->m_Flags;
            if ( (v91 & 0x4000) != 0 || v91 < 0 )
            {
              v92 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v90);
            }
            else if ( (v91 & 0x2000) != 0 || (v91 & 0x1000) != 0 )
            {
              v92 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v90,
                                                                  UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
            }
            else
            {
              v92 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v90,
                                                                  UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
            }
            v93 = v92;
            if ( v92 )
            {
              v94 = *(UFG::TransformNodeComponent **)(v62 + 88);
              m_pTransformNodeComponent = v90->m_pTransformNodeComponent;
              if ( v94 )
              {
                if ( m_pTransformNodeComponent )
                {
                  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                  UFG::TransformNodeComponent::UpdateWorldTransform(v94);
                  m_eSimObjectVehicleType = v93->m_eSimObjectVehicleType;
                  m_eSimObjectBoatType = v93->m_eSimObjectBoatType;
                  v98 = m_eSimObjectVehicleType;
                  if ( (float)((float)((float)((float)(v94->mWorldTransform.v3.y
                                                     - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                             * m_pTransformNodeComponent->mWorldTransform.v1.y)
                                     + (float)((float)(v94->mWorldTransform.v3.x
                                                     - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                             * m_pTransformNodeComponent->mWorldTransform.v1.x))
                             + (float)((float)(v94->mWorldTransform.v3.z
                                             - m_pTransformNodeComponent->mWorldTransform.v3.z)
                                     * m_pTransformNodeComponent->mWorldTransform.v1.z)) <= 0.0 )
                  {
                    m_bTargetedForInteractionDriverSideOnFootByWeaponType = this->m_VehicleInfo[m_eSimObjectVehicleType].m_bTargetedForInteractionDriverSideOnFootByWeaponType;
                    this->m_VehicleInfo[v98].m_bTargetedForInteractionOnFootDriverSide = 1;
                    m_bTargetedForInteractionDriverSideOnFootByWeaponType[v70] = 1;
                    this->m_VehicleInfo[v98].m_bTargetedForInteractionDriverSideOnFootByWeaponType[v71] = 1;
                    this->m_VehicleInfo[v98].m_bTargetedForInteractionDriverSideOnFootByWeaponType[v110] = 1;
                    v103 = this->m_BoatInfo[m_eSimObjectBoatType].m_bTargetedForInteractionDriverSideOnFootByWeaponType;
                    this->m_BoatInfo[m_eSimObjectBoatType].m_bTargetedForInteractionOnFootDriverSide = 1;
                    v103[v70] = 1;
                    this->m_BoatInfo[m_eSimObjectBoatType].m_bTargetedForInteractionDriverSideOnFootByWeaponType[v71] = 1;
                    v101 = this->m_BoatInfo[m_eSimObjectBoatType].m_bTargetedForInteractionDriverSideOnFootByWeaponType;
                  }
                  else
                  {
                    m_bTargetedForInteractionPassengerSideOnFootByWeaponType = this->m_VehicleInfo[m_eSimObjectVehicleType].m_bTargetedForInteractionPassengerSideOnFootByWeaponType;
                    this->m_VehicleInfo[v98].m_bTargetedForInteractionOnFootPassengerSide = 1;
                    m_bTargetedForInteractionPassengerSideOnFootByWeaponType[v70] = 1;
                    this->m_VehicleInfo[v98].m_bTargetedForInteractionPassengerSideOnFootByWeaponType[v71] = 1;
                    this->m_VehicleInfo[v98].m_bTargetedForInteractionPassengerSideOnFootByWeaponType[v110] = 1;
                    v100 = this->m_BoatInfo[m_eSimObjectBoatType].m_bTargetedForInteractionPassengerSideOnFootByWeaponType;
                    this->m_BoatInfo[m_eSimObjectBoatType].m_bTargetedForInteractionOnFootPassengerSide = 1;
                    v100[v70] = 1;
                    this->m_BoatInfo[m_eSimObjectBoatType].m_bTargetedForInteractionPassengerSideOnFootByWeaponType[v71] = 1;
                    v101 = this->m_BoatInfo[m_eSimObjectBoatType].m_bTargetedForInteractionPassengerSideOnFootByWeaponType;
                  }
                  v101[v110] = 1;
                }
              }
            }
          }
          v61 = (char *)&UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList - 120;
        }
      }
      v60 = (char *)v63;
    }
    while ( (char *)v63 != v61 );
  }
}

// File Line: 688
// RVA: 0x3E9D70
void __fastcall UFG::PredictiveStreamingStats::RenderDebug(UFG::PredictiveStreamingStats *this, Render::View *pView)
{
  UFG::PredictiveStreamingStats *v2; // r12
  int v3; // esi
  signed int size; // edi
  Render::DebugDrawContext *Context; // r15
  __int64 v6; // r14
  const char *v7; // rax
  const char *v8; // rax
  int v9; // esi
  int v10; // edi
  __int64 v11; // rbx
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *m_PlayerWeaponInfo; // rcx
  __m128 m_fDistanceSquared_low; // xmm0
  float v14; // xmm0_4
  const char *v15; // rax
  __int64 v16; // rbx
  const char **v17; // rdi
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *m_PlayerVehicleInfo; // rdx
  __m128 m_fDistanceToPassengerSide_low; // xmm0
  float v20; // xmm2_4
  __m128 m_fDistanceToDriverSide_low; // xmm0
  float v22; // xmm1_4
  const char *v23; // rcx
  const char *v24; // rax
  int v25; // r13d
  int v26; // esi
  __int64 i; // rbx
  UFG::PredictiveStreamingStats::WeaponInfo *m_WeaponInfo; // rcx
  const char *v29; // rdx
  const char *v30; // rax
  int v31; // esi
  __int64 v32; // rax
  int v33; // ebx
  int v34; // edx
  int v35; // ebx
  __int64 v36; // rdi
  __int64 v37; // r12
  __int64 v38; // r13
  __int64 v39; // rdi
  int v40; // r14d
  int v41; // r14d
  bool m_bHasDriver; // cl
  UFG::qColour *v43; // r9
  const char *format; // rax
  bool m_bTargetedForInteractionOnFootDriverSide; // cl
  UFG::qColour *v46; // r9
  const char *v47; // rax
  bool m_bHasPassenger; // cl
  UFG::qColour *v49; // r9
  const char *v50; // rax
  bool m_bTargetedForInteractionOnFootPassengerSide; // cl
  UFG::qColour *v52; // r9
  const char *v53; // rax
  bool v54; // bl
  float a; // eax
  bool v56; // bl
  float v57; // eax
  int y; // [rsp+50h] [rbp-B0h]
  UFG::qColour colour; // [rsp+58h] [rbp-A8h] BYREF
  UFG::qColour v60; // [rsp+68h] [rbp-98h] BYREF
  __int64 v61; // [rsp+78h] [rbp-88h]
  EnumList<unsigned long> *v62; // [rsp+80h] [rbp-80h]
  UFG::qString v63; // [rsp+88h] [rbp-78h] BYREF
  UFG::qString v64; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qString v65; // [rsp+D8h] [rbp-28h] BYREF
  __int64 v66; // [rsp+100h] [rbp+0h]
  UFG::qString v67; // [rsp+108h] [rbp+8h] BYREF
  int v69; // [rsp+1A0h] [rbp+A0h]
  bool v70; // [rsp+1A0h] [rbp+A0h]
  bool v71; // [rsp+1A0h] [rbp+A0h]
  int v72; // [rsp+1A8h] [rbp+A8h]

  v66 = -2i64;
  v2 = this;
  v3 = 60;
  if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
    size = 0;
  else
    size = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
  v72 = size;
  if ( (int)UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size <= 0 )
    v62 = 0i64;
  else
    v62 = *UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v6 = size;
  v61 = size;
  if ( UFG::PredictiveStreamingStats::ms_bDrawAllDebug || UFG::PredictiveStreamingStats::ms_bDrawPlayerDebug )
  {
    Render::DebugDrawContext::DrawTextA(Context, 100, 60, &UFG::qColour::Green, "Player Debug");
    v7 = "N";
    if ( v2->m_PlayerInfo.m_bIsDriver )
      v7 = "Y";
    Render::DebugDrawContext::DrawTextA(Context, 100, 80, &UFG::qColour::White, "Is Driver: %s\n", v7);
    v8 = "N";
    if ( v2->m_PlayerInfo.m_bIsPassenger )
      v8 = "Y";
    Render::DebugDrawContext::DrawTextA(Context, 100, 90, &UFG::qColour::White, "Is Passenger: %s\n", v8);
    v69 = 110;
    Render::DebugDrawContext::DrawTextA(
      Context,
      100,
      110,
      &UFG::qColour::Yellow,
      "%-20s %10s %-10s",
      "Weapon",
      "Dist (m)",
      "Owned");
    v9 = 120;
    v10 = 120;
    v11 = 0i64;
    if ( v6 <= 0 )
      goto LABEL_21;
    do
    {
      UFG::qString::qString(&v63, v62->m_enumName.p[v11]);
      UFG::qString::ReplaceString(&v63, "eSIM_OBJ_WEAPON_TYPE_", &customCaption, 0);
      m_PlayerWeaponInfo = v2->m_PlayerInfo.m_PlayerWeaponInfo;
      m_fDistanceSquared_low = (__m128)LODWORD(m_PlayerWeaponInfo[v11].m_fDistanceSquared);
      if ( m_fDistanceSquared_low.m128_f32[0] >= 3.4028235e38 )
        v14 = FLOAT_N1_0;
      else
        LODWORD(v14) = _mm_sqrt_ps(m_fDistanceSquared_low).m128_u32[0];
      v15 = "N";
      if ( m_PlayerWeaponInfo[v11].m_bOwned )
        v15 = "Y";
      Render::DebugDrawContext::DrawTextA(
        Context,
        100,
        v10,
        &UFG::qColour::White,
        "%-20s %10.3f %-10s",
        v63.mData,
        v14,
        v15);
      v10 += 10;
      UFG::qString::~qString(&v63);
      ++v11;
    }
    while ( v11 < v6 );
    v9 = 120;
    if ( v10 >= 110 )
LABEL_21:
      v69 = v10;
    Render::DebugDrawContext::DrawTextA(
      Context,
      450,
      110,
      &UFG::qColour::Yellow,
      "%-10s %10s %10s %-12s %-12s",
      "Vehicle",
      "DistDriver",
      "DistPass",
      "IsDriver",
      "IsPass");
    v16 = 0i64;
    v17 = UFG::SimObjectVehicleTypeEnumNames;
    do
    {
      UFG::qString::qString(&v63, *v17);
      UFG::qString::ReplaceString(&v63, "eSIM_OBJ_VEHICLE_TYPE_", &customCaption, 0);
      m_PlayerVehicleInfo = v2->m_PlayerInfo.m_PlayerVehicleInfo;
      m_fDistanceToPassengerSide_low = (__m128)LODWORD(m_PlayerVehicleInfo[v16].m_fDistanceToPassengerSide);
      if ( m_fDistanceToPassengerSide_low.m128_f32[0] >= 3.4028235e38 )
        v20 = FLOAT_999999_0;
      else
        LODWORD(v20) = _mm_sqrt_ps(m_fDistanceToPassengerSide_low).m128_u32[0];
      m_fDistanceToDriverSide_low = (__m128)LODWORD(m_PlayerVehicleInfo[v16].m_fDistanceToDriverSide);
      if ( m_fDistanceToDriverSide_low.m128_f32[0] >= 3.4028235e38 )
        v22 = FLOAT_999999_0;
      else
        LODWORD(v22) = _mm_sqrt_ps(m_fDistanceToDriverSide_low).m128_u32[0];
      v23 = "N";
      if ( m_PlayerVehicleInfo[v16].m_bIsPassenger )
        v23 = "Y";
      v24 = "N";
      if ( m_PlayerVehicleInfo[v16].m_bIsDriver )
        v24 = "Y";
      Render::DebugDrawContext::DrawTextA(
        Context,
        450,
        v9,
        &UFG::qColour::White,
        "%-10s %10.3f %10.3f %-12s %-12s",
        v63.mData,
        v22,
        v20,
        v24,
        v23);
      v9 += 10;
      UFG::qString::~qString(&v63);
      ++v17;
      ++v16;
    }
    while ( (__int64)v17 < (__int64)UFG::SimObjectCharacterBooleanEnumNames );
    v25 = v69;
    if ( v69 <= v9 )
      v25 = v9;
    v3 = v25 + 30;
    v6 = v61;
    if ( UFG::PredictiveStreamingStats::ms_bDrawAllDebug )
      goto LABEL_91;
  }
  if ( UFG::PredictiveStreamingStats::ms_bDrawWeaponDebug )
  {
LABEL_91:
    Render::DebugDrawContext::DrawTextA(Context, 100, v3, &UFG::qColour::Green, "Weapon Debug");
    Render::DebugDrawContext::DrawTextA(
      Context,
      100,
      v3 + 20,
      &UFG::qColour::Yellow,
      "%-20s %-10s %-10s",
      "Weapon",
      "Owned",
      "Targeted");
    v26 = v3 + 30;
    for ( i = 0i64; i < v6; ++i )
    {
      UFG::qString::qString(&v63, v62->m_enumName.p[i]);
      UFG::qString::ReplaceString(&v63, "eSIM_OBJ_WEAPON_TYPE_", &customCaption, 0);
      m_WeaponInfo = v2->m_WeaponInfo;
      v29 = "N";
      if ( m_WeaponInfo[i].m_bTargetedForInteractionOnFoot )
        v29 = "Y";
      v30 = "N";
      if ( m_WeaponInfo[i].m_bOwned )
        v30 = "Y";
      Render::DebugDrawContext::DrawTextA(
        Context,
        100,
        v26,
        &UFG::qColour::White,
        "%-20s %-10s %-10s",
        v63.mData,
        v30,
        v29);
      v26 += 10;
      UFG::qString::~qString(&v63);
    }
    v3 = v26 + 30;
    if ( UFG::PredictiveStreamingStats::ms_bDrawAllDebug )
      goto LABEL_46;
  }
  if ( UFG::PredictiveStreamingStats::ms_bDrawVehicleDebug )
  {
LABEL_46:
    Render::DebugDrawContext::DrawTextA(Context, 100, v3, &UFG::qColour::Green, "Vehicle Debug");
    v31 = v3 + 20;
    v32 = 0i64;
    v61 = 0i64;
    v33 = v31 + 10;
    y = v31 + 10;
    v34 = v72;
    while ( 1 )
    {
      if ( !v32 )
      {
        Render::DebugDrawContext::DrawTextA(Context, 200, v31, &UFG::qColour::Yellow, "DRIVER");
        Render::DebugDrawContext::DrawTextA(Context, 260, v31, &UFG::qColour::Yellow, "PASS");
        v35 = 380;
        if ( v72 > 0 )
        {
          v36 = (unsigned int)v72;
          v37 = (__int64)v62;
          do
          {
            UFG::qString::qString(&v67, **(const char ***)(v37 + 16));
            UFG::qString::ReplaceString(&v67, "eSIM_OBJ_WEAPON_TYPE_", &customCaption, 0);
            Render::DebugDrawContext::DrawTextA(Context, v35, v31, &UFG::qColour::Yellow, "%s", v67.mData);
            v35 += 60;
            UFG::qString::~qString(&v67);
            --v36;
          }
          while ( v36 );
          v2 = this;
        }
        v31 += 10;
        v33 = y + 10;
        y += 10;
        v32 = v61;
        v34 = v72;
      }
      v38 = v32;
      v39 = 0i64;
      v40 = 100;
      if ( v34 > 0 )
        break;
LABEL_88:
      v31 += 20;
      v33 += 20;
      y = v33;
      v61 = ++v32;
      if ( v32 >= 10 )
        return;
    }
    while ( 1 )
    {
      if ( !v39 )
      {
        UFG::qString::qString(&v63, UFG::SimObjectVehicleTypeEnumNames[v32]);
        UFG::qString::ReplaceString(&v63, "eSIM_OBJ_VEHICLE_TYPE_", &customCaption, 0);
        Render::DebugDrawContext::DrawTextA(Context, v40, v31, &UFG::qColour::Yellow, "%s-HAS", v63.mData);
        Render::DebugDrawContext::DrawTextA(Context, v40, v33, &UFG::qColour::Yellow, "%s-TGT", v63.mData);
        v41 = v40 + 100;
        m_bHasDriver = v2->m_VehicleInfo[v38].m_bHasDriver;
        v43 = &UFG::qColour::White;
        if ( m_bHasDriver )
          v43 = &UFG::qColour::Green;
        format = "N";
        if ( m_bHasDriver )
          format = "Y";
        Render::DebugDrawContext::DrawTextA(Context, v41, v31, v43, format);
        m_bTargetedForInteractionOnFootDriverSide = v2->m_VehicleInfo[v38].m_bTargetedForInteractionOnFootDriverSide;
        v46 = &UFG::qColour::White;
        if ( m_bTargetedForInteractionOnFootDriverSide )
          v46 = &UFG::qColour::Green;
        v47 = "N";
        if ( m_bTargetedForInteractionOnFootDriverSide )
          v47 = "Y";
        Render::DebugDrawContext::DrawTextA(Context, v41, v33, v46, v47);
        m_bHasPassenger = v2->m_VehicleInfo[v38].m_bHasPassenger;
        v49 = &UFG::qColour::White;
        if ( m_bHasPassenger )
          v49 = &UFG::qColour::Green;
        v50 = "N";
        if ( m_bHasPassenger )
          v50 = "Y";
        Render::DebugDrawContext::DrawTextA(Context, v41 + 60, v31, v49, v50);
        m_bTargetedForInteractionOnFootPassengerSide = v2->m_VehicleInfo[v38].m_bTargetedForInteractionOnFootPassengerSide;
        v52 = &UFG::qColour::White;
        if ( m_bTargetedForInteractionOnFootPassengerSide )
          v52 = &UFG::qColour::Green;
        v53 = "N";
        if ( m_bTargetedForInteractionOnFootPassengerSide )
          v53 = "Y";
        Render::DebugDrawContext::DrawTextA(Context, v41 + 60, v33, v52, v53);
        v40 = v41 + 180;
        UFG::qString::~qString(&v63);
      }
      v54 = v2->m_VehicleInfo[v38].m_bHasDriverByWeaponType[v39];
      v70 = v2->m_VehicleInfo[v38].m_bHasPassengerByWeaponType[v39];
      UFG::qString::qString(&v64, "None");
      colour = UFG::qColour::White;
      if ( v54 )
      {
        if ( v70 )
        {
          UFG::qString::Set(&v64, "Both");
          colour.r = UFG::qColour::Green.r;
          colour.g = UFG::qColour::Green.g;
          colour.b = UFG::qColour::Green.b;
          a = UFG::qColour::Green.a;
        }
        else
        {
          UFG::qString::Set(&v64, "Driver");
          colour.r = UFG::qColour::Blue.r;
          colour.g = UFG::qColour::Blue.g;
          colour.b = UFG::qColour::Blue.b;
          a = UFG::qColour::Blue.a;
        }
      }
      else
      {
        if ( !v70 )
          goto LABEL_79;
        UFG::qString::Set(&v64, "Pass");
        colour.r = UFG::qColour::Red.r;
        colour.g = UFG::qColour::Red.g;
        colour.b = UFG::qColour::Red.b;
        a = UFG::qColour::Red.a;
      }
      colour.a = a;
LABEL_79:
      Render::DebugDrawContext::DrawTextA(Context, v40, v31, &colour, v64.mData);
      UFG::qString::~qString(&v64);
      v56 = v2->m_VehicleInfo[v38].m_bTargetedForInteractionDriverSideOnFootByWeaponType[v39];
      v71 = v2->m_VehicleInfo[v38].m_bTargetedForInteractionPassengerSideOnFootByWeaponType[v39];
      UFG::qString::qString(&v65, "None");
      v60 = UFG::qColour::White;
      if ( v56 )
      {
        if ( v71 )
        {
          UFG::qString::Set(&v65, "Both");
          v60.r = UFG::qColour::Green.r;
          v60.g = UFG::qColour::Green.g;
          v60.b = UFG::qColour::Green.b;
          v57 = UFG::qColour::Green.a;
        }
        else
        {
          UFG::qString::Set(&v65, "Driver");
          v60.r = UFG::qColour::Blue.r;
          v60.g = UFG::qColour::Blue.g;
          v60.b = UFG::qColour::Blue.b;
          v57 = UFG::qColour::Blue.a;
        }
        goto LABEL_85;
      }
      if ( v71 )
      {
        UFG::qString::Set(&v65, "Pass");
        v60.r = UFG::qColour::Red.r;
        v60.g = UFG::qColour::Red.g;
        v60.b = UFG::qColour::Red.b;
        v57 = UFG::qColour::Red.a;
LABEL_85:
        v60.a = v57;
      }
      v33 = y;
      Render::DebugDrawContext::DrawTextA(Context, v40, y, &v60, v65.mData);
      UFG::qString::~qString(&v65);
      v40 += 60;
      ++v39;
      v32 = v61;
      if ( v39 >= v72 )
      {
        v34 = v72;
        goto LABEL_88;
      }
    }
  }
}

