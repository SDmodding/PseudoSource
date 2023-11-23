// File Line: 13
// RVA: 0x157C9B0
signed __int64 UFG::_dynamic_initializer_for__Play_engine_blown_id__()
{
  signed __int64 result; // rax

  result = UFG::TiDo::CalcWwiseUid("Play_engine_blown");
  Play_engine_blown_id = result;
  return result;
}

// File Line: 16
// RVA: 0x667EC0
void __fastcall UFG::DamageModel::DamageModel(UFG::DamageModel *this, UFG::VehicleAudioComponent *component)
{
  int v3; // ebx
  UFG::SimObject *m_pSimObject; // rax
  UFG::PhysicsMoverInterface *m_pComponent; // rax
  UFG::SimObject *v6; // rax
  UFG::TransformNodeComponent *v7; // rsi
  float y; // xmm1_4
  float z; // xmm2_4
  bool *m_tireBlown; // rcx
  __int64 v11; // rdx
  __int64 v12; // r8
  UFG::PhysicsMoverInterface *m_mover; // rax

  v3 = 0;
  this->m_ecEngineSteam.m_pEvent = 0i64;
  this->m_ecEngineClank.m_pEvent = 0i64;
  this->m_ecDrivingOnRim.m_pEvent = 0i64;
  this->m_pVehAudComponent = component;
  m_pSimObject = component->m_pSimObject;
  if ( m_pSimObject )
    m_pComponent = (UFG::PhysicsMoverInterface *)m_pSimObject->m_Components.p[34].m_pComponent;
  else
    m_pComponent = 0i64;
  this->m_mover = m_pComponent;
  v6 = component->m_pSimObject;
  if ( v6 )
    v7 = (UFG::TransformNodeComponent *)v6->m_Components.p[2].m_pComponent;
  else
    v7 = 0i64;
  this->m_transformNode = v7;
  UFG::TransformNodeComponent::UpdateWorldTransform(v7);
  y = v7->mWorldTransform.v3.y;
  z = v7->mWorldTransform.v3.z;
  this->m_lastTireFlapPos.x = v7->mWorldTransform.v3.x;
  this->m_lastTireFlapPos.y = y;
  this->m_lastTireFlapPos.z = z;
  m_tireBlown = this->m_tireBlown;
  v11 = 160i64;
  v12 = 4i64;
  do
  {
    m_mover = this->m_mover;
    *m_tireBlown = v3++ < m_mover->mNumWheels
                && *(float *)((char *)&m_mover->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr + v11) >= 1.0;
    v11 += 4i64;
    ++m_tireBlown;
    --v12;
  }
  while ( v12 );
  this->m_engineBlown = this->m_mover->mDamageState.engineDamage >= 1.0;
  this->m_lastEngineDamage = -1.0;
}

// File Line: 44
// RVA: 0x66C750
void __fastcall UFG::DamageModel::~DamageModel(UFG::DamageModel *this)
{
  UFG::AudioEvent *m_pEvent; // rcx
  UFG::AudioEvent *v3; // rcx
  UFG::AudioEvent *v4; // rcx
  UFG::AudioEvent *v5; // rcx
  UFG::AudioEvent *v6; // rcx
  UFG::AudioEvent *v7; // rcx

  if ( this->m_ecEngineSteam.m_pEvent )
  {
    m_pEvent = this->m_ecEngineSteam.m_pEvent;
    if ( m_pEvent )
      UFG::AudioEvent::StopAndForget(m_pEvent, 250);
  }
  if ( this->m_ecEngineClank.m_pEvent )
  {
    v3 = this->m_ecEngineClank.m_pEvent;
    if ( v3 )
      UFG::AudioEvent::StopAndForget(v3, 250);
  }
  if ( this->m_ecDrivingOnRim.m_pEvent )
  {
    v4 = this->m_ecDrivingOnRim.m_pEvent;
    if ( v4 )
      UFG::AudioEvent::StopAndForget(v4, 250);
  }
  v5 = this->m_ecDrivingOnRim.m_pEvent;
  if ( v5 )
    UFG::AudioEvent::OnControllerDestroy(v5);
  v6 = this->m_ecEngineClank.m_pEvent;
  if ( v6 )
    UFG::AudioEvent::OnControllerDestroy(v6);
  v7 = this->m_ecEngineSteam.m_pEvent;
  if ( v7 )
    UFG::AudioEvent::OnControllerDestroy(v7);
}

// File Line: 67
// RVA: 0x67BE60
void __fastcall UFG::DamageModel::HandleDamagedTires(UFG::DamageModel *this)
{
  UFG::qPropertySet *mpPropertySet; // rdi
  char *MemImagePtr; // r13
  __int64 v4; // rbp
  int mNumWheels; // ecx
  __int64 v6; // rdx
  __int64 v7; // rdi
  __int64 v8; // rcx
  char v9; // r15
  char v10; // r14
  int v11; // esi
  UFG::PhysicsMoverInterface *m_mover; // rcx
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax
  UFG::PhysicsWheeledVehicle *v14; // rcx
  bool IsWheelOnGround; // al
  UFG::VehicleAudioComponent *m_pVehAudComponent; // rax
  __m128 y_low; // xmm2
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  UFG::VehicleAudioComponent *v21; // rcx
  UFG::AudioEvent *m_pEvent; // rcx

  mpPropertySet = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
  else
    MemImagePtr = 0i64;
  v4 = 160i64;
  mNumWheels = this->m_mover->mNumWheels;
  if ( mNumWheels > 4 )
    mNumWheels = 4;
  v6 = 0i64;
  v7 = mNumWheels;
  if ( mNumWheels > 0 )
  {
    v8 = 160i64;
    do
    {
      if ( *(float *)((char *)&this->m_mover->vfptr + v8) >= 1.0 && !this->m_tireBlown[v6] )
        this->m_tireBlown[v6] = 1;
      ++v6;
      v8 += 4i64;
    }
    while ( v6 < v7 );
  }
  v9 = 0;
  v10 = 0;
  v11 = 0;
  if ( v7 <= 0 )
    goto LABEL_31;
  do
  {
    m_mover = this->m_mover;
    v9 |= *(float *)((char *)&m_mover->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr + v4) >= 1.0;
    mPhysicsVehicle = m_mover->mPhysicsVehicle;
    if ( !mPhysicsVehicle )
      goto LABEL_18;
    v14 = 0i64;
    if ( (*((_BYTE *)mPhysicsVehicle + 604) & 7) != 0 )
      v14 = (UFG::PhysicsWheeledVehicle *)mPhysicsVehicle;
    if ( v14 )
      IsWheelOnGround = UFG::PhysicsWheeledVehicle::IsWheelOnGround(v14, v11);
    else
LABEL_18:
      IsWheelOnGround = 1;
    v10 |= IsWheelOnGround;
    ++v11;
    v4 += 4i64;
    --v7;
  }
  while ( v7 );
  if ( v9 && v10 )
  {
    m_pVehAudComponent = this->m_pVehAudComponent;
    y_low = (__m128)LODWORD(this->m_lastTireFlapPos.y);
    x = this->m_pVehAudComponent->m_WorldMatrix.v3.x;
    y = this->m_pVehAudComponent->m_WorldMatrix.v3.y;
    z = this->m_pVehAudComponent->m_WorldMatrix.v3.z;
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                              + (float)((float)(this->m_lastTireFlapPos.x - x) * (float)(this->m_lastTireFlapPos.x - x)))
                      + (float)((float)(this->m_lastTireFlapPos.z - z) * (float)(this->m_lastTireFlapPos.z - z));
    if ( _mm_sqrt_ps(y_low).m128_f32[0] > *((float *)MemImagePtr + 7) )
    {
      this->m_lastTireFlapPos.x = x;
      this->m_lastTireFlapPos.y = y;
      this->m_lastTireFlapPos.z = z;
      if ( m_pVehAudComponent->m_eDriverType <= (unsigned int)eDriverType_PlayerPassenger
        || m_pVehAudComponent->m_fDistance2ToListener < 400.0 )
      {
        UFG::AudioEntity::CreateAndPlayEvent(
          &m_pVehAudComponent->UFG::AudioEntity,
          *((_DWORD *)MemImagePtr + 8),
          0i64,
          0,
          0i64);
      }
    }
    if ( !this->m_ecDrivingOnRim.m_pEvent )
    {
      v21 = this->m_pVehAudComponent;
      if ( (this->m_pVehAudComponent->m_eDriverType <= (unsigned int)eDriverType_PlayerPassenger
         || v21->m_fDistance2ToListener < 400.0)
        && this->m_pVehAudComponent->m_rateLimitedSpeed.m_targetValue > 0.001 )
      {
        UFG::AudioEntity::CreateAndPlayEvent(
          &v21->UFG::AudioEntity,
          play_veh_tire_drive_rim_01.mUID,
          &this->m_ecDrivingOnRim,
          0i64,
          0,
          0i64);
      }
    }
  }
  else
  {
LABEL_31:
    m_pEvent = this->m_ecDrivingOnRim.m_pEvent;
    if ( m_pEvent && this->m_pVehAudComponent->m_rateLimitedSpeed.m_targetValue < 0.001 )
      UFG::AudioEvent::StopAndForget(m_pEvent, 100);
  }
}

// File Line: 132
// RVA: 0x67BC00
void __fastcall UFG::DamageModel::HandleDamagedEngine(UFG::DamageModel *this)
{
  UFG::AudioEvent *m_pEvent; // rcx
  UFG::AudioEvent *v3; // rcx
  float engineDamage; // xmm0_4
  UFG::AudioEvent *v5; // rcx
  float v6; // xmm2_4

  if ( this->m_mover->mDamageState.engineDamage < 0.5 )
  {
    m_pEvent = this->m_ecEngineSteam.m_pEvent;
    if ( m_pEvent )
      UFG::AudioEvent::StopAndForget(m_pEvent, 250);
    v3 = this->m_ecEngineClank.m_pEvent;
    if ( v3 )
      UFG::AudioEvent::StopAndForget(v3, 250);
  }
  engineDamage = this->m_mover->mDamageState.engineDamage;
  if ( engineDamage >= 0.5
    && engineDamage < 1.0
    && (*((_BYTE *)this->m_pVehAudComponent + 636) & 1) != 0
    && !this->m_ecEngineClank.m_pEvent )
  {
    if ( (_S13_8 & 1) == 0 )
    {
      _S13_8 |= 1u;
      play_engine_clank.mUID = UFG::qWiseSymbolUIDFromString("play_engine_clank", 0x811C9DC5);
      _((AMD_HD3D *)play_engine_clank.mUID);
      atexit(UFG::DamageModel::HandleDamagedEngine_::_20_::_dynamic_atexit_destructor_for__play_engine_clank__);
    }
    UFG::AudioEntity::CreateAndPlayEvent(
      &this->m_pVehAudComponent->UFG::AudioEntity,
      play_engine_clank.mUID,
      &this->m_ecEngineClank,
      0i64,
      0,
      0i64);
  }
  if ( this->m_mover->mDamageState.engineDamage >= 1.0 )
  {
    if ( !this->m_engineBlown )
    {
      UFG::AudioEntity::CreateAndPlayEvent(
        &this->m_pVehAudComponent->UFG::AudioEntity,
        Play_engine_blown_id,
        0i64,
        0,
        0i64);
      this->m_engineBlown = 1;
    }
    if ( this->m_pVehAudComponent->m_eDriverType == eDriverType_Player && !this->m_ecEngineSteam.m_pEvent )
    {
      if ( (_S13_8 & 2) == 0 )
      {
        _S13_8 |= 2u;
        play_steam.mUID = UFG::qWiseSymbolUIDFromString("play_steam", 0x811C9DC5);
        _((AMD_HD3D *)play_steam.mUID);
        atexit(UFG::DamageModel::HandleDamagedEngine_::_29_::_dynamic_atexit_destructor_for__play_steam__);
      }
      UFG::AudioEntity::CreateAndPlayEvent(
        &this->m_pVehAudComponent->UFG::AudioEntity,
        play_steam.mUID,
        &this->m_ecEngineSteam,
        0i64,
        0,
        0i64);
    }
  }
  if ( (*((_BYTE *)this->m_pVehAudComponent + 636) & 1) == 0 )
  {
    v5 = this->m_ecEngineClank.m_pEvent;
    if ( v5 )
      UFG::AudioEvent::StopAndForget(v5, 250);
  }
  if ( (_S13_8 & 4) == 0 )
  {
    _S13_8 |= 4u;
    engine_damage.mUID = UFG::qWiseSymbolUIDFromString("engine_damage", 0x811C9DC5);
    _((AMD_HD3D *)engine_damage.mUID);
    atexit(UFG::DamageModel::HandleDamagedEngine_::_35_::_dynamic_atexit_destructor_for__engine_damage__);
  }
  v6 = this->m_mover->mDamageState.engineDamage;
  if ( v6 != this->m_lastEngineDamage )
  {
    UFG::AudioEntity::SetRtpcValue(&this->m_pVehAudComponent->UFG::AudioEntity, engine_damage.mUID, v6);
    this->m_lastEngineDamage = this->m_mover->mDamageState.engineDamage;
  }
}

