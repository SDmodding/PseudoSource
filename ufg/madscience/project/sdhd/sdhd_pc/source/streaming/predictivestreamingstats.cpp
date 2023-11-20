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
  UFG::PredictiveStreamingStats::PlayerInfo *v1; // rdi
  signed int v2; // eax
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // kr00_8
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rax

  v1 = this;
  if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
    v2 = 0;
  else
    v2 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
  v3 = v2;
  v5 = v2;
  v4 = 8i64 * v2;
  if ( !is_mul_ok(v5, 8ui64) )
    v4 = -1i64;
  this->m_PlayerWeaponInfo = (UFG::PredictiveStreamingStats::PlayerWeaponInfo *)UFG::qMalloc(
                                                                                  v4,
                                                                                  "PredictiveStreamingStats",
                                                                                  0i64);
  v6 = 12 * v3;
  if ( !is_mul_ok(v3, 0xCui64) )
    v6 = -1i64;
  v1->m_PlayerVehicleInfo = (UFG::PredictiveStreamingStats::PlayerVehicleInfo *)UFG::qMalloc(
                                                                                  v6,
                                                                                  "PredictiveStreamingStats",
                                                                                  0i64);
  v7 = 12 * v3;
  if ( !is_mul_ok(v3, 0xCui64) )
    v7 = -1i64;
  v1->m_PlayerBoatInfo = (UFG::PredictiveStreamingStats::PlayerVehicleInfo *)UFG::qMalloc(
                                                                               v7,
                                                                               "PredictiveStreamingStats",
                                                                               0i64);
}

// File Line: 126
// RVA: 0x3EA870
void __fastcall UFG::PredictiveStreamingStats::PlayerInfo::ResetInfo(UFG::PredictiveStreamingStats::PlayerInfo *this)
{
  signed __int64 v1; // r8
  UFG::PredictiveStreamingStats::PlayerInfo *v2; // r9
  signed int v3; // eax
  signed __int64 v4; // rdx
  signed __int64 v5; // r10
  __int64 v6; // rcx
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *v7; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v8; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v9; // rax
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *v10; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v11; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v12; // rax
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *v13; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v14; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v15; // rax
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *v16; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v17; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v18; // rax
  signed __int64 v19; // rcx
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *v20; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v21; // rax
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v22; // rax

  v1 = 0i64;
  v2 = this;
  if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
    v3 = 0;
  else
    v3 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
  v4 = v3;
  *(_WORD *)&this->m_bIsDriver = 0;
  if ( v3 >= 4i64 )
  {
    v5 = v3 - 3i64;
    v6 = 0i64;
    do
    {
      v7 = v2->m_PlayerWeaponInfo;
      v1 += 4i64;
      v6 += 4i64;
      v7[v1 - 4].m_fDistanceSquared = 3.4028235e38;
      *((_BYTE *)&v7[v1 - 3] - 4) = 0;
      v8 = v2->m_PlayerVehicleInfo;
      v8[v6 - 4].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v8[v6 - 3] - 2) = 2139095039;
      *((_WORD *)&v8[v6 - 3] - 2) = 0;
      v9 = v2->m_PlayerBoatInfo;
      v9[v6 - 4].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v9[v6 - 3] - 2) = 2139095039;
      *((_WORD *)&v9[v6 - 3] - 2) = 0;
      v10 = v2->m_PlayerWeaponInfo;
      v10[v1 - 3].m_fDistanceSquared = 3.4028235e38;
      *((_BYTE *)&v10[v1 - 2] - 4) = 0;
      v11 = v2->m_PlayerVehicleInfo;
      v11[v6 - 3].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v11[v6 - 2] - 2) = 2139095039;
      *((_WORD *)&v11[v6 - 2] - 2) = 0;
      v12 = v2->m_PlayerBoatInfo;
      v12[v6 - 3].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v12[v6 - 2] - 2) = 2139095039;
      *((_WORD *)&v12[v6 - 2] - 2) = 0;
      v13 = v2->m_PlayerWeaponInfo;
      v13[v1 - 2].m_fDistanceSquared = 3.4028235e38;
      *((_BYTE *)&v13[v1 - 1] - 4) = 0;
      v14 = v2->m_PlayerVehicleInfo;
      v14[v6 - 2].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v14[v6 - 1] - 2) = 2139095039;
      *((_WORD *)&v14[v6 - 1] - 2) = 0;
      v15 = v2->m_PlayerBoatInfo;
      v15[v6 - 2].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v15[v6 - 1] - 2) = 2139095039;
      *((_WORD *)&v15[v6 - 1] - 2) = 0;
      v16 = v2->m_PlayerWeaponInfo;
      v16[v1 - 1].m_fDistanceSquared = 3.4028235e38;
      *((_BYTE *)&v16[v1] - 4) = 0;
      v17 = v2->m_PlayerVehicleInfo;
      v17[v6 - 1].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v17[v6] - 2) = 2139095039;
      *((_WORD *)&v17[v6] - 2) = 0;
      v18 = v2->m_PlayerBoatInfo;
      v18[v6 - 1].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v18[v6] - 2) = 2139095039;
      *((_WORD *)&v18[v6] - 2) = 0;
    }
    while ( v1 < v5 );
  }
  if ( v1 < v4 )
  {
    v19 = v1;
    do
    {
      v20 = v2->m_PlayerWeaponInfo;
      ++v1;
      ++v19;
      v20[v1 - 1].m_fDistanceSquared = 3.4028235e38;
      *((_BYTE *)&v20[v1] - 4) = 0;
      v21 = v2->m_PlayerVehicleInfo;
      v21[v19 - 1].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v21[v19] - 2) = 2139095039;
      *((_WORD *)&v21[v19] - 2) = 0;
      v22 = v2->m_PlayerBoatInfo;
      v22[v19 - 1].m_fDistanceToDriverSide = 3.4028235e38;
      *((_DWORD *)&v22[v19] - 2) = 2139095039;
      *((_WORD *)&v22[v19] - 2) = 0;
    }
    while ( v1 < v4 );
  }
}

// File Line: 141
// RVA: 0x3E91B0
void __fastcall UFG::PredictiveStreamingStats::Init(UFG::PredictiveStreamingStats *this)
{
  UFG::PredictiveStreamingStats *v1; // rsi
  signed int v2; // eax
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // kr00_8
  _QWORD *v5; // rdi
  signed __int64 v6; // rbp
  signed int v7; // eax
  unsigned __int64 v8; // rbx
  _QWORD *v9; // rdi
  signed __int64 v10; // rbp
  signed int v11; // eax
  unsigned __int64 v12; // rbx
  signed __int64 v13; // rbx
  signed __int64 v14; // rdi
  signed int v15; // eax

  v1 = this;
  if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
    v2 = 0;
  else
    v2 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
  v4 = v2;
  v3 = 2i64 * v2;
  if ( !is_mul_ok(v4, 2ui64) )
    v3 = -1i64;
  this->m_WeaponInfo = (UFG::PredictiveStreamingStats::WeaponInfo *)UFG::qMalloc(v3, "PredictiveStreamingStats", 0i64);
  UFG::PredictiveStreamingStats::PlayerInfo::Init(&v1->m_PlayerInfo);
  v5 = &v1->m_VehicleInfo[0].m_bHasPassengerByWeaponType;
  v6 = 10i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v7 = 0;
    else
      v7 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    v8 = v7;
    *(v5 - 1) = UFG::qMalloc(v7, "PredictiveStreamingStats", 0i64);
    *v5 = UFG::qMalloc(v8, "PredictiveStreamingStats", 0i64);
    v5[1] = UFG::qMalloc(v8, "PredictiveStreamingStats", 0i64);
    v5 += 5;
    *(v5 - 3) = UFG::qMalloc(v8, "PredictiveStreamingStats", 0i64);
    --v6;
  }
  while ( v6 );
  v9 = &v1->m_BoatInfo[0].m_bHasPassengerByWeaponType;
  v10 = 7i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v11 = 0;
    else
      v11 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    v12 = v11;
    *(v9 - 1) = UFG::qMalloc(v11, "PredictiveStreamingStats", 0i64);
    *v9 = UFG::qMalloc(v12, "PredictiveStreamingStats", 0i64);
    v9[1] = UFG::qMalloc(v12, "PredictiveStreamingStats", 0i64);
    v9 += 5;
    *(v9 - 3) = UFG::qMalloc(v12, "PredictiveStreamingStats", 0i64);
    --v10;
  }
  while ( v10 );
  v13 = (signed __int64)v1->m_CharacterInfo;
  v14 = 43i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v15 = 0;
    else
      v15 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    v13 += 8i64;
    *(_QWORD *)(v13 - 8) = UFG::qMalloc(v15, "PredictiveStreamingStats", 0i64);
    --v14;
  }
  while ( v14 );
}

// File Line: 170
// RVA: 0x3EAA50
void __fastcall UFG::PredictiveStreamingStats::ResetInfo(UFG::PredictiveStreamingStats *this)
{
  UFG::PredictiveStreamingStats *v1; // rdi
  signed int v2; // ebx
  signed __int64 v3; // rcx
  signed __int64 v4; // rdx
  signed __int64 v5; // r9
  signed int v6; // eax
  signed __int64 v7; // rcx
  signed __int64 v8; // rax
  signed __int64 v9; // r9
  signed int v10; // ecx
  signed __int64 v11; // rdx
  void **v12; // rbx
  signed __int64 v13; // rdi
  unsigned int v14; // er8

  v1 = this;
  if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
    v2 = 0;
  else
    v2 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
  UFG::PredictiveStreamingStats::PlayerInfo::ResetInfo(&this->m_PlayerInfo);
  v3 = 0i64;
  if ( v2 > 0 )
  {
    do
      v1->m_WeaponInfo[++v3 - 1] = 0;
    while ( v3 < v2 );
  }
  v4 = (signed __int64)&v1->m_VehicleInfo[0].m_bTargetedForInteractionOnFootDriverSide;
  v5 = 10i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v6 = 0;
    else
      v6 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    v7 = 0i64;
    *(_DWORD *)(v4 - 2) = 0;
    if ( v6 > 0 )
    {
      do
      {
        *(_BYTE *)(++v7 + *(_QWORD *)(v4 + 6) - 1) = 0;
        *(_BYTE *)(v7 + *(_QWORD *)(v4 + 14) - 1) = 0;
        *(_BYTE *)(v7 + *(_QWORD *)(v4 + 22) - 1) = 0;
        *(_BYTE *)(v7 + *(_QWORD *)(v4 + 30) - 1) = 0;
      }
      while ( v7 < v6 );
    }
    v4 += 40i64;
    --v5;
  }
  while ( v5 );
  v8 = (signed __int64)&v1->m_BoatInfo[0].m_bTargetedForInteractionOnFootDriverSide;
  v9 = 7i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v10 = 0;
    else
      v10 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    v11 = 0i64;
    *(_DWORD *)(v8 - 2) = 0;
    if ( v10 > 0 )
    {
      do
      {
        *(_BYTE *)(++v11 + *(_QWORD *)(v8 + 6) - 1) = 0;
        *(_BYTE *)(v11 + *(_QWORD *)(v8 + 14) - 1) = 0;
        *(_BYTE *)(v11 + *(_QWORD *)(v8 + 22) - 1) = 0;
        *(_BYTE *)(v11 + *(_QWORD *)(v8 + 30) - 1) = 0;
      }
      while ( v11 < v10 );
    }
    v8 += 40i64;
    --v9;
  }
  while ( v9 );
  v12 = (void **)v1->m_CharacterInfo;
  v13 = 43i64;
  do
  {
    if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
      v14 = 0;
    else
      v14 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
    UFG::qMemSet(*v12, 0, v14);
    ++v12;
    --v13;
  }
  while ( v13 );
}

// File Line: 201
// RVA: 0x3EAE40
void __fastcall UFG::PredictiveStreamingStats::UpdateCachedInfo(UFG::PredictiveStreamingStats *this)
{
  UFG::PredictiveStreamingStats *v1; // rbx
  UFG::SimObjectCharacter *v2; // rax
  UFG::SimObjectCVBase *v3; // rcx
  UFG::TargetingSystemPedPlayerComponent *v4; // rax
  unsigned __int16 v5; // dx
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  unsigned int v8; // edx
  bool v9; // zf

  v1 = this;
  v2 = UFG::GetLocalPlayer();
  v3 = (UFG::SimObjectCVBase *)&v2->vfptr;
  v1->m_pPlayerSimObject = (UFG::SimObject *)&v2->vfptr;
  if ( v2 )
    v2 = (UFG::SimObjectCharacter *)v2->m_pTransformNodeComponent;
  v1->m_pPlayerTNC = (UFG::TransformNodeComponent *)v2;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v3->vfptr,
                                                         UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v3->vfptr,
                                                         UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v3->vfptr,
                                                         UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v3);
    }
  }
  else
  {
    v4 = 0i64;
  }
  v6 = (UFG::SimObjectGame *)v1->m_pPlayerSimObject;
  v1->m_pPlayerTSC = v4;
  if ( !v6 )
  {
    v1->m_pPlayerCOC = 0i64;
    return;
  }
  v7 = v6->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v1->m_pPlayerCOC = (UFG::CharacterOccupantComponent *)v6->m_Components.p[44].m_pComponent;
    return;
  }
  if ( (v7 & 0x8000u) != 0 || (v7 >> 13) & 1 )
  {
    v8 = UFG::CharacterOccupantComponent::_TypeUID;
LABEL_20:
    v1->m_pPlayerCOC = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v6, v8);
    return;
  }
  v9 = ((v7 >> 12) & 1) == 0;
  v8 = UFG::CharacterOccupantComponent::_TypeUID;
  if ( !v9 )
    goto LABEL_20;
  v1->m_pPlayerCOC = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v6->vfptr,
                                                          UFG::CharacterOccupantComponent::_TypeUID);
}

// File Line: 213
// RVA: 0x3EACE0
void __fastcall UFG::PredictiveStreamingStats::Update(UFG::PredictiveStreamingStats *this, const float fTimeDeltaS)
{
  UFG::PredictiveStreamingStats *v2; // rbx

  v2 = this;
  UFG::PredictiveStreamingStats::ResetInfo(this);
  UFG::PredictiveStreamingStats::UpdateCachedInfo(v2);
  UFG::PredictiveStreamingStats::UpdatePlayerVehicleInfo(v2);
  UFG::PredictiveStreamingStats::UpdatePlayerWeaponInfo(v2);
  UFG::PredictiveStreamingStats::UpdateWeaponInfo(v2);
  UFG::PredictiveStreamingStats::UpdateVehicleInfo(v2);
}

// File Line: 237
// RVA: 0x3EAF70
void __fastcall UFG::PredictiveStreamingStats::UpdatePlayerVehicleInfo(UFG::PredictiveStreamingStats *this)
{
  UFG::CharacterOccupantComponent *v1; // rdi
  UFG::PredictiveStreamingStats *v2; // rbx
  UFG::SimObjectCVBase *v3; // rax
  bool v4; // di
  bool v5; // si
  UFG::SimObjectVehiclePropertiesComponent *v6; // rax
  signed __int64 v7; // r8
  signed __int64 v8; // rdx
  signed __int64 v9; // rcx

  v1 = this->m_pPlayerCOC;
  v2 = this;
  if ( v1 )
  {
    v3 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(this->m_pPlayerCOC);
    if ( v3 )
    {
      v4 = v1->mTargetType == 4;
      v2->m_PlayerInfo.m_bIsDriver = v4;
      v5 = v4 == 0;
      v2->m_PlayerInfo.m_bIsPassenger = v4 == 0;
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v3);
      if ( v6 )
      {
        v7 = v6->m_eSimObjectVehicleType;
        v8 = v7;
        v2->m_PlayerInfo.m_PlayerVehicleInfo[v8].m_bIsDriver = v4;
        v2->m_PlayerInfo.m_PlayerVehicleInfo[v8].m_bIsPassenger = v5;
        if ( (_DWORD)v7 == 3 )
        {
          v9 = v6->m_eSimObjectBoatType;
          v2->m_PlayerInfo.m_PlayerBoatInfo[v9].m_bIsDriver = v4;
          v2->m_PlayerInfo.m_PlayerBoatInfo[v9].m_bIsPassenger = v5;
        }
      }
    }
  }
}

// File Line: 274
// RVA: 0x3EB010
void __fastcall UFG::PredictiveStreamingStats::UpdatePlayerWeaponInfo(UFG::PredictiveStreamingStats *this)
{
  UFG::PredictiveStreamingStats *v1; // rdi
  UFG::TransformNodeComponent *v2; // rcx
  UFG::TargetingSystemPedPlayerComponent *v3; // rbx
  unsigned __int8 *v4; // rsi
  UFG::TargetingSimObject *v5; // rbx
  UFG::SimObjectProp *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimObjectWeaponPropertiesComponent *v8; // rax
  UFG::SimObjectProp *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimObjectWeaponPropertiesComponent *v11; // rax
  UFG::SimObjectProp *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimObjectWeaponPropertiesComponent *v14; // rax

  v1 = this;
  v2 = this->m_pPlayerTNC;
  v3 = v1->m_pPlayerTSC;
  if ( v3 )
  {
    if ( v2 )
      UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v4 = (unsigned __int8 *)v3->m_pTargetingMap;
    v5 = v3->m_pTargets;
    v6 = (UFG::SimObjectProp *)v5[v4[25]].m_pTarget.m_pPointer;
    if ( v6 )
    {
      v7 = v6->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v6->vfptr,
                                                          UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
          v8 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v6);
        else
          v8 = (UFG::SimObjectWeaponPropertiesComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                              (UFG::SimObjectGame *)&v6->vfptr,
                                                                              UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
      }
      else
      {
        v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v6->vfptr,
                                                          UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
      if ( v8 )
        v1->m_PlayerInfo.m_PlayerWeaponInfo[v8->mWeaponTypeInfo->mFireModes[v8->mFireMode]->mSimObjectWeaponType].m_bOwned = 1;
    }
    v9 = (UFG::SimObjectProp *)v5[v4[50]].m_pTarget.m_pPointer;
    if ( v9 )
    {
      v10 = v9->m_Flags;
      if ( (v10 >> 14) & 1 )
      {
        v11 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v9->vfptr,
                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
      else if ( (v10 & 0x8000u) == 0 )
      {
        if ( (v10 >> 13) & 1 )
          v11 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v9);
        else
          v11 = (UFG::SimObjectWeaponPropertiesComponent *)((v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                (UFG::SimObjectGame *)&v9->vfptr,
                                                                                UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
      }
      else
      {
        v11 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v9->vfptr,
                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
      if ( v11 )
        v1->m_PlayerInfo.m_PlayerWeaponInfo[v11->mWeaponTypeInfo->mFireModes[v11->mFireMode]->mSimObjectWeaponType].m_bOwned = 1;
    }
    v12 = (UFG::SimObjectProp *)v5[v4[51]].m_pTarget.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v12->vfptr,
                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v12);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v12->vfptr,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        else
        {
          v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v12->vfptr,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
      }
      else
      {
        v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v12->vfptr,
                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
      if ( v14 )
        v1->m_PlayerInfo.m_PlayerWeaponInfo[v14->mWeaponTypeInfo->mFireModes[v14->mFireMode]->mSimObjectWeaponType].m_bOwned = 1;
    }
  }
}

// File Line: 329
// RVA: 0x3EBEB0
void __fastcall UFG::PredictiveStreamingStats::UpdateWeaponInfo(UFG::PredictiveStreamingStats *this)
{
  UFG::TransformNodeComponent *v1; // rbx
  UFG::TargetingSystemPedPlayerComponent *v2; // rdi
  UFG::SimObjectGame *v3; // r8
  float v4; // xmm6_4
  float v5; // xmm7_4
  UFG::SimObjectGame *v6; // rdx
  UFG::PredictiveStreamingStats *v7; // r15
  float v8; // xmm8_4
  UFG::SimObjectGame *v9; // r9
  unsigned __int8 *v10; // rcx
  UFG::TargetingSimObject *v11; // rdx
  UFG::qList<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent,1,0> *v12; // rax
  UFG::SimObjectGame *v13; // rbx
  UFG::qList<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent,1,0> *v14; // r12
  __int64 v15; // rsi
  float *v16; // rdi
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *v17; // rcx
  float v18; // xmm0_4
  UFG::PredictiveStreamingStats::WeaponInfo *v19; // r14
  unsigned __int16 v20; // cx
  UFG::SimComponent *v21; // rax
  UFG::TargetingSimObject *v22; // rbx
  signed __int64 v23; // rbp
  char v24; // cl
  UFG::TargetingSimObject *v25; // rdi
  UFG::SimObjectCVBase *v26; // rax
  unsigned __int16 v27; // dx
  UFG::SimObjectCharacterPropertiesComponent *v28; // rax
  UFG::SimObjectGame *v29; // [rsp+90h] [rbp+8h]
  UFG::SimObjectGame *v30; // [rsp+98h] [rbp+10h]
  UFG::SimObjectGame *v31; // [rsp+A0h] [rbp+18h]

  v1 = this->m_pPlayerTNC;
  v2 = this->m_pPlayerTSC;
  v3 = 0i64;
  v4 = UFG::qVector3::msZero.x;
  v5 = UFG::qVector3::msZero.y;
  v6 = 0i64;
  v7 = this;
  v29 = 0i64;
  v8 = UFG::qVector3::msZero.z;
  v9 = 0i64;
  v30 = 0i64;
  v31 = 0i64;
  if ( v1 && v2 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v1);
    v10 = (unsigned __int8 *)v2->m_pTargetingMap;
    v11 = v2->m_pTargets;
    v4 = v1->mWorldTransform.v3.x;
    v5 = v1->mWorldTransform.v3.y;
    v8 = v1->mWorldTransform.v3.z;
    v3 = (UFG::SimObjectGame *)v11[v10[25]].m_pTarget.m_pPointer;
    v29 = (UFG::SimObjectGame *)v11[v10[25]].m_pTarget.m_pPointer;
    v9 = (UFG::SimObjectGame *)v11[v10[50]].m_pTarget.m_pPointer;
    v30 = (UFG::SimObjectGame *)v11[v10[50]].m_pTarget.m_pPointer;
    v6 = (UFG::SimObjectGame *)v11[v10[51]].m_pTarget.m_pPointer;
    v31 = v6;
  }
  v12 = (UFG::qList<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent,1,0> *)&UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mNext[-10].mNext;
  if ( &UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mNext[-10].mNext != (UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> **)((char *)&UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList - 152) )
  {
    do
    {
      v13 = (UFG::SimObjectGame *)v12[2].mNode.mNext;
      v14 = (UFG::qList<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent,1,0> *)&v12[10].mNode.mPrev[-10].mNext;
      v15 = **((unsigned int **)&v12[11].mNode.mPrev->mNext + HIDWORD(v12[10].mNode.mNext));
      if ( v13 != v3 && v13 != v9 && v13 != v6 )
      {
        if ( v13 )
        {
          v16 = (float *)v13->m_pTransformNodeComponent;
          if ( v16 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v13->m_pTransformNodeComponent);
            v17 = v7->m_PlayerInfo.m_PlayerWeaponInfo;
            v18 = v17[v15].m_fDistanceSquared;
            if ( v18 >= (float)((float)((float)((float)(v4 - v16[44]) * (float)(v4 - v16[44]))
                                      + (float)((float)(v5 - v16[45]) * (float)(v5 - v16[45])))
                              + (float)((float)(v8 - v16[46]) * (float)(v8 - v16[46]))) )
              v18 = (float)((float)((float)(v4 - v16[44]) * (float)(v4 - v16[44]))
                          + (float)((float)(v5 - v16[45]) * (float)(v5 - v16[45])))
                  + (float)((float)(v8 - v16[46]) * (float)(v8 - v16[46]));
            v17[v15].m_fDistanceSquared = v18;
          }
        }
      }
      v19 = v7->m_WeaponInfo;
      if ( v13 )
      {
        v20 = v13->m_Flags;
        if ( (v20 >> 14) & 1 )
        {
          v21 = v13->m_Components.p[20].m_pComponent;
        }
        else if ( (v20 & 0x8000u) == 0 )
        {
          if ( (v20 >> 13) & 1 )
            v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v21 = (v20 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v13,
                                      UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v13->vfptr,
                                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v21 = v13->m_Components.p[20].m_pComponent;
        }
        if ( v21 )
        {
          v22 = (UFG::TargetingSimObject *)v21[1].m_BoundComponentHandles.mNode.mPrev;
          v23 = (signed __int64)&v21[1].m_pSimObject;
          if ( v22 != (UFG::TargetingSimObject *)&v21[1].m_pSimObject )
          {
            do
            {
              v24 = v22->m_eTargetType.mValue;
              v25 = (UFG::TargetingSimObject *)v22->mNext;
              if ( v24 == 17 || (unsigned __int8)(v24 - 42) <= 1u )
                v19[v15].m_bOwned = 1;
              if ( v24 == 17 )
              {
                v26 = (UFG::SimObjectCVBase *)UFG::TargetingSimObject::GetOwner(v22);
                if ( v26 )
                {
                  v27 = v26->m_Flags;
                  if ( (v27 >> 14) & 1 )
                  {
                    v28 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v26);
                  }
                  else if ( (v27 & 0x8000u) == 0 )
                  {
                    if ( (v27 >> 13) & 1 )
                      v28 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            (UFG::SimObjectGame *)&v26->vfptr,
                                                                            UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
                    else
                      v28 = (UFG::SimObjectCharacterPropertiesComponent *)((v27 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                               (UFG::SimObjectGame *)&v26->vfptr,
                                                                                               UFG::SimObjectCharacterPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v26->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
                  }
                  else
                  {
                    v28 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v26);
                  }
                  if ( v28 )
                    v7->m_CharacterInfo[v28->m_eCharacterType].m_bHasWeaponTypeEquipped[v15] = 1;
                }
              }
              if ( v22->m_eTargetType.mValue == 41 && v22->m_pTarget.m_pPointer )
              {
                if ( v22->m_bLock )
                  v19[v15].m_bTargetedForInteractionOnFoot = 1;
              }
              v22 = v25;
            }
            while ( v25 != (UFG::TargetingSimObject *)v23 );
          }
        }
      }
      v3 = v29;
      v9 = v30;
      v6 = v31;
      v12 = v14;
    }
    while ( v14 != (UFG::qList<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent,1,0> *)((char *)&UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList - 152) );
  }
}tWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList - 152) );
  }
}

// File Line: 427
// RVA: 0x3EB2B0
void __fastcall UFG::PredictiveStreamingStats::UpdateVehicleInfo(UFG::PredictiveStreamingStats *this)
{
  UFG::TransformNodeComponent *v1; // rdi
  UFG::PredictiveStreamingStats *v2; // rbx
  UFG::CharacterOccupantComponent *v3; // rcx
  UFG::VehicleOccupantComponent *v4; // r15
  UFG::qVector3 *v5; // rax
  float v6; // xmm11_4
  float v7; // xmm12_4
  float v8; // xmm13_4
  char *v9; // rax
  char *v10; // rdx
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v11; // rbp
  signed __int64 v12; // r13
  UFG::SimObjectCVBase *v13; // rdi
  UFG::TransformNodeComponent *v14; // r14
  UFG::TargetingSystemVehicleComponent *v15; // rax
  UFG::TargetingSystemVehicleComponent *v16; // rsi
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v17; // r12
  signed __int64 v18; // rdi
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm8_4
  float v22; // xmm7_4
  float v23; // xmm9_4
  float v24; // xmm10_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm4_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  UFG::TargetingSimObject *v32; // rdi
  signed __int64 v33; // r14
  signed __int64 v34; // r12
  signed __int64 v35; // rsi
  signed __int64 v36; // rax
  UFG::TargetingSimObject *v37; // r14
  UFG::SimObjectGame *v38; // rax
  unsigned __int16 v39; // dx
  UFG::SimComponent *v40; // rax
  signed __int64 v41; // rsi
  bool v42; // r15
  signed __int64 v43; // rbp
  UFG::TargetingSystemBaseComponent *v44; // rax
  UFG::TargetingSimObject *v45; // r14
  unsigned __int8 *v46; // rdi
  unsigned int v47; // er13
  unsigned int v48; // er12
  UFG::SimObjectProp *v49; // rcx
  unsigned __int16 v50; // dx
  UFG::SimObjectWeaponPropertiesComponent *v51; // rax
  UFG::SimObjectProp *v52; // rcx
  unsigned __int16 v53; // dx
  UFG::SimObjectWeaponPropertiesComponent *v54; // rax
  UFG::SimObjectProp *v55; // rcx
  unsigned __int16 v56; // dx
  UFG::SimObjectWeaponPropertiesComponent *v57; // rax
  __int64 v58; // rcx
  bool *v59; // rax
  char *v60; // rdi
  char *v61; // rdx
  __int64 v62; // rsi
  signed __int64 v63; // r15
  unsigned __int16 v64; // cx
  UFG::SimComponent *v65; // rax
  bool v66; // zf
  UFG::SimObjectGame *v67; // rcx
  unsigned __int8 *v68; // rbp
  __int64 v69; // r14
  int v70; // er12
  int v71; // er13
  UFG::SimObjectGame *v72; // rcx
  unsigned __int16 v73; // dx
  UFG::SimComponent *v74; // rax
  CAkChainCtx *v75; // rdi
  CAkScheduledItem *v76; // rax
  CAkScheduledItem *v77; // rax
  UFG::SimObjectGame *v78; // rcx
  unsigned __int16 v79; // dx
  UFG::SimComponent *v80; // rax
  CAkChainCtx *v81; // rdi
  CAkScheduledItem *v82; // rax
  CAkScheduledItem *v83; // rax
  UFG::SimObjectGame *v84; // rcx
  unsigned __int16 v85; // dx
  UFG::SimComponent *v86; // rax
  CAkChainCtx *v87; // rdi
  CAkScheduledItem *v88; // rax
  CAkScheduledItem *v89; // rax
  UFG::SimObjectCVBase *v90; // rdi
  unsigned __int16 v91; // cx
  UFG::SimObjectVehiclePropertiesComponent *v92; // rax
  UFG::SimObjectVehiclePropertiesComponent *v93; // rbp
  UFG::TransformNodeComponent *v94; // rdi
  signed __int64 v95; // rax
  __int64 v96; // r10
  signed __int64 v97; // rcx
  bool *v98; // rax
  bool *v99; // rax
  bool *v100; // rax
  bool *v101; // rax
  bool *v102; // rax
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v103; // [rsp+20h] [rbp-E8h]
  signed __int64 v104; // [rsp+28h] [rbp-E0h]
  UFG::VehicleOccupantComponent *v105; // [rsp+30h] [rbp-D8h]
  signed __int64 v106; // [rsp+38h] [rbp-D0h]
  int v107; // [rsp+110h] [rbp+8h]
  unsigned int v108; // [rsp+110h] [rbp+8h]
  int v109; // [rsp+110h] [rbp+8h]
  signed __int64 v110; // [rsp+118h] [rbp+10h]
  signed __int64 v111; // [rsp+128h] [rbp+20h]

  v1 = this->m_pPlayerTNC;
  v2 = this;
  v3 = this->m_pPlayerCOC;
  if ( v3 )
    v4 = UFG::CharacterOccupantComponent::GetCurrentVehicle(v3);
  else
    v4 = 0i64;
  v105 = v4;
  if ( v1 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v1);
    v5 = (UFG::qVector3 *)&v1->mWorldTransform.v3;
  }
  else
  {
    v5 = &UFG::qVector3::msZero;
  }
  v6 = v5->x;
  v7 = v5->y;
  v8 = v5->z;
  v9 = (char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mNext[-10].mNext;
  if ( &UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mNext[-10].mNext != (UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> **)((char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152) )
  {
    v10 = (char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152;
    do
    {
      v11 = (UFG::PredictiveStreamingStats::PlayerVehicleInfo *)*((signed int *)v9 + 43);
      v12 = *((signed int *)v9 + 42);
      v107 = *((_DWORD *)v9 + 43);
      v106 = *((_QWORD *)v9 + 20) - 152i64;
      v13 = (UFG::SimObjectCVBase *)*((_QWORD *)v9 + 5);
      if ( v13 )
      {
        v14 = (UFG::TransformNodeComponent *)v13->m_Components.p[2].m_pComponent;
        v15 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(v13);
        v16 = v15;
        if ( v14 && v15 )
        {
          if ( v13 != (UFG::SimObjectCVBase *)v4 )
          {
            v17 = v2->m_PlayerInfo.m_PlayerVehicleInfo;
            v18 = (signed __int64)v11;
            v11 = v2->m_PlayerInfo.m_PlayerBoatInfo;
            UFG::TransformNodeComponent::UpdateWorldTransform(v14);
            v19 = v14->mWorldTransform.v3.x;
            v20 = v14->mWorldTransform.v3.y;
            v21 = s_fDistanceToSideOfVehicleOfVehicle * v14->mWorldTransform.v1.z;
            v22 = v14->mWorldTransform.v3.z;
            v23 = s_fDistanceToSideOfVehicleOfVehicle * v14->mWorldTransform.v1.x;
            v24 = s_fDistanceToSideOfVehicleOfVehicle * v14->mWorldTransform.v1.y;
            v25 = v8 - (float)((float)(s_fDistanceToSideOfVehicleOfVehicle * v14->mWorldTransform.v1.z) + v22);
            v26 = v17[v12].m_fDistanceToPassengerSide;
            v27 = (float)((float)((float)(v7 - (float)(v24 + v20)) * (float)(v7 - (float)(v24 + v20)))
                        + (float)((float)(v6 - (float)(v23 + v19)) * (float)(v6 - (float)(v23 + v19))))
                + (float)(v25 * v25);
            if ( v26 >= v27 )
              v26 = (float)((float)((float)(v7 - (float)(v24 + v20)) * (float)(v7 - (float)(v24 + v20)))
                          + (float)((float)(v6 - (float)(v23 + v19)) * (float)(v6 - (float)(v23 + v19))))
                  + (float)(v25 * v25);
            v17[v12].m_fDistanceToPassengerSide = v26;
            v28 = v11[v18].m_fDistanceToPassengerSide;
            if ( v28 >= v27 )
              v28 = (float)((float)((float)(v7 - (float)(v24 + v20)) * (float)(v7 - (float)(v24 + v20)))
                          + (float)((float)(v6 - (float)(v23 + v19)) * (float)(v6 - (float)(v23 + v19))))
                  + (float)(v25 * v25);
            v11[v18].m_fDistanceToPassengerSide = v28;
            v29 = v17[v12].m_fDistanceToDriverSide;
            v30 = (float)((float)((float)(v7 - (float)(v20 - v24)) * (float)(v7 - (float)(v20 - v24)))
                        + (float)((float)(v6 - (float)(v19 - v23)) * (float)(v6 - (float)(v19 - v23))))
                + (float)((float)(v8 - (float)(v22 - v21)) * (float)(v8 - (float)(v22 - v21)));
            if ( v29 >= v30 )
              v29 = (float)((float)((float)(v7 - (float)(v20 - v24)) * (float)(v7 - (float)(v20 - v24)))
                          + (float)((float)(v6 - (float)(v19 - v23)) * (float)(v6 - (float)(v19 - v23))))
                  + (float)((float)(v8 - (float)(v22 - v21)) * (float)(v8 - (float)(v22 - v21)));
            v17[v12].m_fDistanceToDriverSide = v29;
            v31 = v11[v18].m_fDistanceToDriverSide;
            if ( v31 >= v30 )
              v31 = (float)((float)((float)(v7 - (float)(v20 - v24)) * (float)(v7 - (float)(v20 - v24)))
                          + (float)((float)(v6 - (float)(v19 - v23)) * (float)(v6 - (float)(v19 - v23))))
                  + (float)((float)(v8 - (float)(v22 - v21)) * (float)(v8 - (float)(v22 - v21)));
            v11[v18].m_fDistanceToDriverSide = v31;
            LODWORD(v11) = v107;
          }
          v32 = (UFG::TargetingSimObject *)v16->m_TargetedBy.mNode.mNext;
          v33 = (signed __int64)&v16->m_TargetedBy;
          v34 = (signed int)v11;
          v35 = v12;
          v111 = v12;
          v104 = (signed int)v11;
          v110 = v33;
          if ( v32 != (UFG::TargetingSimObject *)v33 )
          {
            v36 = v33;
            do
            {
              v37 = (UFG::TargetingSimObject *)v32->mNext;
              v103 = v32->mNext;
              if ( v32->m_eTargetType.mValue == 28 && v32->m_pTarget.m_pPointer && v32->m_bLock )
              {
                v38 = (UFG::SimObjectGame *)UFG::TargetingSimObject::GetOwner(v32);
                if ( v38 )
                {
                  v39 = v38->m_Flags;
                  if ( (v39 >> 14) & 1 )
                  {
                    v40 = v38->m_Components.p[44].m_pComponent;
                  }
                  else if ( (v39 & 0x8000u) == 0 )
                  {
                    if ( (v39 >> 13) & 1 )
                      v40 = UFG::SimObjectGame::GetComponentOfTypeHK(v38, UFG::CharacterOccupantComponent::_TypeUID);
                    else
                      v40 = (v39 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v38,
                                                UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                               (UFG::SimObject *)&v38->vfptr,
                                                                                               UFG::CharacterOccupantComponent::_TypeUID);
                  }
                  else
                  {
                    v40 = UFG::SimObjectGame::GetComponentOfTypeHK(v38, UFG::CharacterOccupantComponent::_TypeUID);
                  }
                  if ( v40 )
                  {
                    v41 = v35;
                    v42 = LODWORD(v40[1].m_SafePointerList.mNode.mNext) == 4;
                    v43 = v34;
                    v2->m_VehicleInfo[v41].m_bHasDriver |= v42;
                    v2->m_VehicleInfo[v41].m_bHasPassenger |= v42 == 0;
                    v2->m_BoatInfo[v34].m_bHasDriver |= v42;
                    v44 = v32->m_pTSBC;
                    v2->m_BoatInfo[v34].m_bHasPassenger |= v42 == 0;
                    if ( v44 )
                    {
                      v45 = v44->m_pTargets;
                      v46 = (unsigned __int8 *)v44->m_pTargetingMap;
                      v47 = 0;
                      v48 = 0;
                      v108 = 0;
                      v49 = (UFG::SimObjectProp *)v45[v46[25]].m_pTarget.m_pPointer;
                      if ( v49 )
                      {
                        v50 = v49->m_Flags;
                        if ( (v50 >> 14) & 1 )
                        {
                          v51 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v49->vfptr,
                                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                        }
                        else if ( (v50 & 0x8000u) == 0 )
                        {
                          if ( (v50 >> 13) & 1 )
                            v51 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v49);
                          else
                            v51 = (UFG::SimObjectWeaponPropertiesComponent *)((v50 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                                  (UFG::SimObjectGame *)&v49->vfptr,
                                                                                                  UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v49->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
                        }
                        else
                        {
                          v51 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v49->vfptr,
                                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                        }
                        if ( v51 )
                          v47 = v51->mWeaponTypeInfo->mFireModes[v51->mFireMode]->mSimObjectWeaponType;
                      }
                      v52 = (UFG::SimObjectProp *)v45[v46[50]].m_pTarget.m_pPointer;
                      if ( v52 )
                      {
                        v53 = v52->m_Flags;
                        if ( (v53 >> 14) & 1 )
                        {
                          v54 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v52->vfptr,
                                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                        }
                        else if ( (v53 & 0x8000u) == 0 )
                        {
                          if ( (v53 >> 13) & 1 )
                            v54 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v52);
                          else
                            v54 = (UFG::SimObjectWeaponPropertiesComponent *)((v53 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                                  (UFG::SimObjectGame *)&v52->vfptr,
                                                                                                  UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v52->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
                        }
                        else
                        {
                          v54 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v52->vfptr,
                                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                        }
                        if ( v54 )
                          v108 = v54->mWeaponTypeInfo->mFireModes[v54->mFireMode]->mSimObjectWeaponType;
                      }
                      v55 = (UFG::SimObjectProp *)v45[v46[51]].m_pTarget.m_pPointer;
                      if ( v55 )
                      {
                        v56 = v55->m_Flags;
                        if ( (v56 >> 14) & 1 )
                        {
                          v57 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v55->vfptr,
                                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                        }
                        else if ( (v56 & 0x8000u) == 0 )
                        {
                          if ( (v56 >> 13) & 1 )
                            v57 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v55);
                          else
                            v57 = (UFG::SimObjectWeaponPropertiesComponent *)((v56 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                                  (UFG::SimObjectGame *)&v55->vfptr,
                                                                                                  UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v55->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
                        }
                        else
                        {
                          v57 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v55->vfptr,
                                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                        }
                        if ( v57 )
                          v48 = v57->mWeaponTypeInfo->mFireModes[v57->mFireMode]->mSimObjectWeaponType;
                      }
                      v37 = (UFG::TargetingSimObject *)v103;
                      v58 = v48;
                      v34 = v104;
                      if ( v42 )
                      {
                        v2->m_VehicleInfo[v41].m_bHasDriverByWeaponType[v47] = 1;
                        v2->m_VehicleInfo[v41].m_bHasDriverByWeaponType[v108] = 1;
                        v2->m_VehicleInfo[v41].m_bHasDriverByWeaponType[v58] = 1;
                        v2->m_BoatInfo[v43].m_bHasDriverByWeaponType[v47] = 1;
                        v2->m_BoatInfo[v43].m_bHasDriverByWeaponType[v108] = 1;
                        v59 = v2->m_BoatInfo[v43].m_bHasDriverByWeaponType;
                      }
                      else
                      {
                        v2->m_VehicleInfo[v41].m_bHasPassengerByWeaponType[v47] = 1;
                        v2->m_VehicleInfo[v41].m_bHasPassengerByWeaponType[v108] = 1;
                        v2->m_VehicleInfo[v41].m_bHasPassengerByWeaponType[v58] = 1;
                        v2->m_BoatInfo[v43].m_bHasPassengerByWeaponType[v47] = 1;
                        v2->m_BoatInfo[v43].m_bHasPassengerByWeaponType[v108] = 1;
                        v59 = v2->m_BoatInfo[v43].m_bHasPassengerByWeaponType;
                      }
                      v59[v58] = 1;
                    }
                    v35 = v111;
                  }
                }
                v36 = v110;
              }
              v32 = v37;
            }
            while ( v37 != (UFG::TargetingSimObject *)v36 );
          }
        }
        v10 = (char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152;
      }
      v4 = v105;
      v9 = (char *)v106;
    }
    while ( (char *)v106 != v10 );
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
        if ( (v64 >> 14) & 1 )
        {
          v65 = *(UFG::SimComponent **)(*(_QWORD *)(v62 + 104) + 80i64);
        }
        else if ( (v64 & 0x8000u) == 0 )
        {
          if ( (v64 >> 13) & 1 )
          {
            v65 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    *((UFG::SimObjectGame **)v60 + 5),
                    UFG::AIScriptInterfaceComponent::_TypeUID);
          }
          else
          {
            v66 = ((v64 >> 12) & 1) == 0;
            v67 = (UFG::SimObjectGame *)*((_QWORD *)v60 + 5);
            v65 = v66 ? UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v67->vfptr,
                          UFG::AIScriptInterfaceComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         v67,
                                                                         UFG::AIScriptInterfaceComponent::_TypeUID);
          }
          v61 = (char *)&UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList - 120;
        }
        else
        {
          v65 = *(UFG::SimComponent **)(*(_QWORD *)(v62 + 104) + 80i64);
        }
        if ( v65 && BYTE2(v65[32].m_BoundComponentHandles.mNode.mPrev) & 1 )
        {
          v68 = (unsigned __int8 *)*((_QWORD *)v60 + 12);
          v69 = *((_QWORD *)v60 + 11);
          v70 = 0;
          v71 = 0;
          v109 = 0;
          v72 = *(UFG::SimObjectGame **)(56i64 * v68[25] + v69 + 40);
          if ( v72 )
          {
            v73 = v72->m_Flags;
            if ( (v73 >> 14) & 1 )
            {
              v74 = UFG::SimObjectGame::GetComponentOfTypeHK(v72, UFG::GunComponent::_TypeUID);
            }
            else if ( (v73 & 0x8000u) == 0 )
            {
              if ( (v73 >> 13) & 1 )
                v74 = UFG::SimObjectGame::GetComponentOfTypeHK(v72, UFG::GunComponent::_TypeUID);
              else
                v74 = (v73 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v72, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v72->vfptr, UFG::GunComponent::_TypeUID);
            }
            else
            {
              v74 = UFG::SimObjectGame::GetComponentOfTypeHK(v72, UFG::GunComponent::_TypeUID);
            }
            v75 = (CAkChainCtx *)v74;
            if ( v74 )
            {
              v76 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v74);
              if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)&v76[2].m_cmdStop.iRelativeTime
                                         + 8i64 * (unsigned int)v76[2].m_cmdPlay.fadeParams.iFadeOffset
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
            if ( (v79 >> 14) & 1 )
            {
              v80 = UFG::SimObjectGame::GetComponentOfTypeHK(v78, UFG::GunComponent::_TypeUID);
            }
            else if ( (v79 & 0x8000u) == 0 )
            {
              if ( (v79 >> 13) & 1 )
                v80 = UFG::SimObjectGame::GetComponentOfTypeHK(v78, UFG::GunComponent::_TypeUID);
              else
                v80 = (v79 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v78, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v78->vfptr, UFG::GunComponent::_TypeUID);
            }
            else
            {
              v80 = UFG::SimObjectGame::GetComponentOfTypeHK(v78, UFG::GunComponent::_TypeUID);
            }
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
            if ( (v85 >> 14) & 1 )
            {
              v86 = UFG::SimObjectGame::GetComponentOfTypeHK(v84, UFG::GunComponent::_TypeUID);
            }
            else if ( (v85 & 0x8000u) == 0 )
            {
              if ( (v85 >> 13) & 1 )
                v86 = UFG::SimObjectGame::GetComponentOfTypeHK(v84, UFG::GunComponent::_TypeUID);
              else
                v86 = (v85 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v84, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v84->vfptr, UFG::GunComponent::_TypeUID);
            }
            else
            {
              v86 = UFG::SimObjectGame::GetComponentOfTypeHK(v84, UFG::GunComponent::_TypeUID);
            }
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
                v109 = **(_DWORD **)(*(_QWORD *)&v89[2].m_cmdStop.iRelativeTime
                                   + 8i64 * (unsigned int)v89[2].m_cmdPlay.fadeParams.iFadeOffset
                                   + 8);
              }
            }
          }
          v90 = *(UFG::SimObjectCVBase **)(56i64 * v68[36] + v69 + 40);
          if ( v90 )
          {
            v91 = v90->m_Flags;
            if ( (v91 >> 14) & 1 )
            {
              v92 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v90);
            }
            else if ( (v91 & 0x8000u) == 0 )
            {
              if ( (v91 >> 13) & 1 )
                v92 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    (UFG::SimObjectGame *)&v90->vfptr,
                                                                    UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
              else
                v92 = (UFG::SimObjectVehiclePropertiesComponent *)((v91 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                       (UFG::SimObjectGame *)&v90->vfptr,
                                                                                       UFG::SimObjectVehiclePropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v90->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID));
            }
            else
            {
              v92 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v90);
            }
            v93 = v92;
            if ( v92 )
            {
              if ( v62 )
                v62 = *(_QWORD *)(v62 + 88);
              v94 = v90->m_pTransformNodeComponent;
              if ( v62 && v94 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(v94);
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v62);
                v95 = v93->m_eSimObjectVehicleType;
                v96 = v93->m_eSimObjectBoatType;
                v97 = v95;
                if ( (float)((float)((float)((float)(*(float *)(v62 + 180) - v94->mWorldTransform.v3.y)
                                           * v94->mWorldTransform.v1.y)
                                   + (float)((float)(*(float *)(v62 + 176) - v94->mWorldTransform.v3.x)
                                           * v94->mWorldTransform.v1.x))
                           + (float)((float)(*(float *)(v62 + 184) - v94->mWorldTransform.v3.z)
                                   * v94->mWorldTransform.v1.z)) <= 0.0 )
                {
                  v101 = v2->m_VehicleInfo[v95].m_bTargetedForInteractionDriverSideOnFootByWeaponType;
                  v2->m_VehicleInfo[v97].m_bTargetedForInteractionOnFootDriverSide = 1;
                  v101[v70] = 1;
                  v2->m_VehicleInfo[v97].m_bTargetedForInteractionDriverSideOnFootByWeaponType[v71] = 1;
                  v2->m_VehicleInfo[v97].m_bTargetedForInteractionDriverSideOnFootByWeaponType[v109] = 1;
                  v102 = v2->m_BoatInfo[v96].m_bTargetedForInteractionDriverSideOnFootByWeaponType;
                  v2->m_BoatInfo[v96].m_bTargetedForInteractionOnFootDriverSide = 1;
                  v102[v70] = 1;
                  v2->m_BoatInfo[v96].m_bTargetedForInteractionDriverSideOnFootByWeaponType[v71] = 1;
                  v100 = v2->m_BoatInfo[v96].m_bTargetedForInteractionDriverSideOnFootByWeaponType;
                }
                else
                {
                  v98 = v2->m_VehicleInfo[v95].m_bTargetedForInteractionPassengerSideOnFootByWeaponType;
                  v2->m_VehicleInfo[v97].m_bTargetedForInteractionOnFootPassengerSide = 1;
                  v98[v70] = 1;
                  v2->m_VehicleInfo[v97].m_bTargetedForInteractionPassengerSideOnFootByWeaponType[v71] = 1;
                  v2->m_VehicleInfo[v97].m_bTargetedForInteractionPassengerSideOnFootByWeaponType[v109] = 1;
                  v99 = v2->m_BoatInfo[v96].m_bTargetedForInteractionPassengerSideOnFootByWeaponType;
                  v2->m_BoatInfo[v96].m_bTargetedForInteractionOnFootPassengerSide = 1;
                  v99[v70] = 1;
                  v2->m_BoatInfo[v96].m_bTargetedForInteractionPassengerSideOnFootByWeaponType[v71] = 1;
                  v100 = v2->m_BoatInfo[v96].m_bTargetedForInteractionPassengerSideOnFootByWeaponType;
                }
                v100[v109] = 1;
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
  signed int v4; // edi
  Render::DebugDrawContext *v5; // r15
  __int64 v6; // r14
  const char *v7; // rax
  const char *v8; // rax
  int v9; // esi
  int v10; // edi
  __int64 v11; // rbx
  UFG::PredictiveStreamingStats::PlayerWeaponInfo *v12; // rcx
  __m128 v13; // xmm0
  float v14; // xmm0_4
  const char *v15; // rax
  __int64 v16; // rbx
  const char **v17; // rdi
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v18; // rdx
  __m128 v19; // xmm0
  float v20; // xmm2_4
  __m128 v21; // xmm0
  float v22; // xmm1_4
  const char *v23; // rcx
  const char *v24; // rax
  signed int v25; // er13
  int v26; // esi
  __int64 i; // rbx
  UFG::PredictiveStreamingStats::WeaponInfo *v28; // rcx
  const char *v29; // rdx
  const char *v30; // rax
  int v31; // esi
  signed __int64 v32; // rax
  int v33; // ebx
  signed int v34; // edx
  int v35; // ebx
  __int64 v36; // rdi
  __int64 v37; // r12
  signed __int64 v38; // r13
  signed __int64 v39; // rdi
  int v40; // er14
  int v41; // er14
  bool v42; // cl
  UFG::qColour *v43; // r9
  const char *format; // rax
  bool v45; // cl
  UFG::qColour *v46; // r9
  const char *v47; // rax
  bool v48; // cl
  UFG::qColour *v49; // r9
  const char *v50; // rax
  bool v51; // cl
  UFG::qColour *v52; // r9
  const char *v53; // rax
  bool v54; // bl
  float v55; // eax
  bool v56; // bl
  float v57; // eax
  int y; // [rsp+50h] [rbp-B0h]
  UFG::qColour colour; // [rsp+58h] [rbp-A8h]
  UFG::qColour v60; // [rsp+68h] [rbp-98h]
  __int64 v61; // [rsp+78h] [rbp-88h]
  EnumList<unsigned long> *v62; // [rsp+80h] [rbp-80h]
  UFG::qString v63; // [rsp+88h] [rbp-78h]
  UFG::qString v64; // [rsp+B0h] [rbp-50h]
  UFG::qString v65; // [rsp+D8h] [rbp-28h]
  __int64 v66; // [rsp+100h] [rbp+0h]
  UFG::qString v67; // [rsp+108h] [rbp+8h]
  UFG::PredictiveStreamingStats *v68; // [rsp+190h] [rbp+90h]
  signed int v69; // [rsp+1A0h] [rbp+A0h]
  bool v70; // [rsp+1A0h] [rbp+A0h]
  bool v71; // [rsp+1A0h] [rbp+A0h]
  signed int v72; // [rsp+1A8h] [rbp+A8h]

  v68 = this;
  v66 = -2i64;
  v2 = this;
  v3 = 60;
  if ( (UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size & 0x80000000) != 0 )
    v4 = 0;
  else
    v4 = (*UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p)->m_enumName.size;
  v72 = v4;
  if ( (signed int)UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size <= 0 )
    v62 = 0i64;
  else
    v62 = *UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p;
  v5 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v6 = v4;
  v61 = v4;
  if ( UFG::PredictiveStreamingStats::ms_bDrawAllDebug || UFG::PredictiveStreamingStats::ms_bDrawPlayerDebug )
  {
    Render::DebugDrawContext::DrawTextA(v5, 100, 60, &UFG::qColour::Green, "Player Debug");
    v7 = "N";
    if ( v2->m_PlayerInfo.m_bIsDriver )
      v7 = "Y";
    Render::DebugDrawContext::DrawTextA(v5, 100, 80, &UFG::qColour::White, "Is Driver: %s\n", v7);
    v8 = "N";
    if ( v2->m_PlayerInfo.m_bIsPassenger )
      v8 = "Y";
    Render::DebugDrawContext::DrawTextA(v5, 100, 90, &UFG::qColour::White, "Is Passenger: %s\n", v8);
    v69 = 110;
    Render::DebugDrawContext::DrawTextA(
      v5,
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
      goto LABEL_92;
    do
    {
      UFG::qString::qString(&v63, v62->m_enumName.p[v11]);
      UFG::qString::ReplaceString(&v63, "eSIM_OBJ_WEAPON_TYPE_", &customWorldMapCaption, 0);
      v12 = v2->m_PlayerInfo.m_PlayerWeaponInfo;
      v13 = (__m128)LODWORD(v12[v11].m_fDistanceSquared);
      if ( v13.m128_f32[0] >= 3.4028235e38 )
        v14 = FLOAT_N1_0;
      else
        LODWORD(v14) = (unsigned __int128)_mm_sqrt_ps(v13);
      v15 = "N";
      if ( v12[v11].m_bOwned )
        v15 = "Y";
      Render::DebugDrawContext::DrawTextA(v5, 100, v10, &UFG::qColour::White, "%-20s %10.3f %-10s", v63.mData, v14, v15);
      v10 += 10;
      UFG::qString::~qString(&v63);
      ++v11;
    }
    while ( v11 < v6 );
    v9 = 120;
    if ( v10 >= 110 )
LABEL_92:
      v69 = v10;
    Render::DebugDrawContext::DrawTextA(
      v5,
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
      UFG::qString::ReplaceString(&v63, "eSIM_OBJ_VEHICLE_TYPE_", &customWorldMapCaption, 0);
      v18 = v2->m_PlayerInfo.m_PlayerVehicleInfo;
      v19 = (__m128)LODWORD(v18[v16].m_fDistanceToPassengerSide);
      if ( v19.m128_f32[0] >= 3.4028235e38 )
        v20 = FLOAT_999999_0;
      else
        LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v19);
      v21 = (__m128)LODWORD(v18[v16].m_fDistanceToDriverSide);
      if ( v21.m128_f32[0] >= 3.4028235e38 )
        v22 = FLOAT_999999_0;
      else
        LODWORD(v22) = (unsigned __int128)_mm_sqrt_ps(v21);
      v23 = "N";
      if ( v18[v16].m_bIsPassenger )
        v23 = "Y";
      v24 = "N";
      if ( v18[v16].m_bIsDriver )
        v24 = "Y";
      Render::DebugDrawContext::DrawTextA(
        v5,
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
    while ( (signed __int64)v17 < (signed __int64)UFG::SimObjectCharacterBooleanEnumNames );
    v25 = v69;
    if ( v69 <= v9 )
      v25 = v9;
    v3 = v25 + 30;
    v6 = v61;
    if ( UFG::PredictiveStreamingStats::ms_bDrawAllDebug )
      goto LABEL_93;
  }
  if ( UFG::PredictiveStreamingStats::ms_bDrawWeaponDebug )
  {
LABEL_93:
    Render::DebugDrawContext::DrawTextA(v5, 100, v3, &UFG::qColour::Green, "Weapon Debug");
    Render::DebugDrawContext::DrawTextA(
      v5,
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
      UFG::qString::ReplaceString(&v63, "eSIM_OBJ_WEAPON_TYPE_", &customWorldMapCaption, 0);
      v28 = v2->m_WeaponInfo;
      v29 = "N";
      if ( v28[i].m_bTargetedForInteractionOnFoot )
        v29 = "Y";
      v30 = "N";
      if ( v28[i].m_bOwned )
        v30 = "Y";
      Render::DebugDrawContext::DrawTextA(v5, 100, v26, &UFG::qColour::White, "%-20s %-10s %-10s", v63.mData, v30, v29);
      v26 += 10;
      UFG::qString::~qString(&v63);
    }
    v3 = v26 + 30;
    if ( UFG::PredictiveStreamingStats::ms_bDrawAllDebug )
      goto LABEL_91;
  }
  if ( UFG::PredictiveStreamingStats::ms_bDrawVehicleDebug )
  {
LABEL_91:
    Render::DebugDrawContext::DrawTextA(v5, 100, v3, &UFG::qColour::Green, "Vehicle Debug");
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
        Render::DebugDrawContext::DrawTextA(v5, 200, v31, &UFG::qColour::Yellow, "DRIVER");
        Render::DebugDrawContext::DrawTextA(v5, 260, v31, &UFG::qColour::Yellow, "PASS");
        v35 = 380;
        if ( v72 > 0 )
        {
          v36 = (unsigned int)v72;
          v37 = (__int64)v62;
          do
          {
            UFG::qString::qString(&v67, **(const char ***)(v37 + 16));
            UFG::qString::ReplaceString(&v67, "eSIM_OBJ_WEAPON_TYPE_", &customWorldMapCaption, 0);
            Render::DebugDrawContext::DrawTextA(v5, v35, v31, &UFG::qColour::Yellow, "%s", v67.mData);
            v35 += 60;
            UFG::qString::~qString(&v67);
            --v36;
          }
          while ( v36 );
          v2 = v68;
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
        UFG::qString::ReplaceString(&v63, "eSIM_OBJ_VEHICLE_TYPE_", &customWorldMapCaption, 0);
        Render::DebugDrawContext::DrawTextA(v5, v40, v31, &UFG::qColour::Yellow, "%s-HAS", v63.mData);
        Render::DebugDrawContext::DrawTextA(v5, v40, v33, &UFG::qColour::Yellow, "%s-TGT", v63.mData);
        v41 = v40 + 100;
        v42 = v2->m_VehicleInfo[v38].m_bHasDriver;
        v43 = &UFG::qColour::White;
        if ( v42 )
          v43 = &UFG::qColour::Green;
        format = "N";
        if ( v42 )
          format = "Y";
        Render::DebugDrawContext::DrawTextA(v5, v41, v31, v43, format);
        v45 = v2->m_VehicleInfo[v38].m_bTargetedForInteractionOnFootDriverSide;
        v46 = &UFG::qColour::White;
        if ( v45 )
          v46 = &UFG::qColour::Green;
        v47 = "N";
        if ( v45 )
          v47 = "Y";
        Render::DebugDrawContext::DrawTextA(v5, v41, v33, v46, v47);
        v48 = v2->m_VehicleInfo[v38].m_bHasPassenger;
        v49 = &UFG::qColour::White;
        if ( v48 )
          v49 = &UFG::qColour::Green;
        v50 = "N";
        if ( v48 )
          v50 = "Y";
        Render::DebugDrawContext::DrawTextA(v5, v41 + 60, v31, v49, v50);
        v51 = v2->m_VehicleInfo[v38].m_bTargetedForInteractionOnFootPassengerSide;
        v52 = &UFG::qColour::White;
        if ( v51 )
          v52 = &UFG::qColour::Green;
        v53 = "N";
        if ( v51 )
          v53 = "Y";
        Render::DebugDrawContext::DrawTextA(v5, v41 + 60, v33, v52, v53);
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
          v55 = UFG::qColour::Green.a;
        }
        else
        {
          UFG::qString::Set(&v64, "Driver");
          colour.r = UFG::qColour::Blue.r;
          colour.g = UFG::qColour::Blue.g;
          colour.b = UFG::qColour::Blue.b;
          v55 = UFG::qColour::Blue.a;
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
        v55 = UFG::qColour::Red.a;
      }
      colour.a = v55;
LABEL_79:
      Render::DebugDrawContext::DrawTextA(v5, v40, v31, &colour, v64.mData);
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
      Render::DebugDrawContext::DrawTextA(v5, v40, y, &v60, v65.mData);
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

