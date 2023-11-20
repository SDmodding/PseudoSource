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
  UFG::DamageModel *v2; // rdi
  int v3; // ebx
  UFG::SimObject *v4; // rax
  UFG::PhysicsMoverInterface *v5; // rax
  UFG::SimObject *v6; // rax
  UFG::SimComponent *v7; // rsi
  float v8; // xmm1_4
  float v9; // xmm2_4
  bool *v10; // rcx
  signed __int64 v11; // rdx
  signed __int64 v12; // r8
  UFG::PhysicsMoverInterface *v13; // rax

  v2 = this;
  v3 = 0;
  this->m_ecEngineSteam.m_pEvent = 0i64;
  this->m_ecEngineClank.m_pEvent = 0i64;
  this->m_ecDrivingOnRim.m_pEvent = 0i64;
  this->m_pVehAudComponent = component;
  v4 = component->m_pSimObject;
  if ( v4 )
    v5 = (UFG::PhysicsMoverInterface *)v4->m_Components.p[34].m_pComponent;
  else
    v5 = 0i64;
  this->m_mover = v5;
  v6 = component->m_pSimObject;
  if ( v6 )
    v7 = v6->m_Components.p[2].m_pComponent;
  else
    v7 = 0i64;
  this->m_transformNode = (UFG::TransformNodeComponent *)v7;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
  v8 = *((float *)&v7[2].m_BoundComponentHandles.mNode.mPrev + 1);
  v9 = *(float *)&v7[2].m_BoundComponentHandles.mNode.mNext;
  v2->m_lastTireFlapPos.x = *(float *)&v7[2].m_BoundComponentHandles.mNode.mPrev;
  v2->m_lastTireFlapPos.y = v8;
  v2->m_lastTireFlapPos.z = v9;
  v10 = v2->m_tireBlown;
  v11 = 160i64;
  v12 = 4i64;
  do
  {
    v13 = v2->m_mover;
    if ( v3 >= v13->mNumWheels )
      *v10 = 0;
    else
      *v10 = 1.0 <= *(float *)((char *)&v13->vfptr + v11);
    ++v3;
    v11 += 4i64;
    ++v10;
    --v12;
  }
  while ( v12 );
  v2->m_engineBlown = v2->m_mover->mDamageState.engineDamage >= 1.0;
  v2->m_lastEngineDamage = -1.0;
}

// File Line: 44
// RVA: 0x66C750
void __fastcall UFG::DamageModel::~DamageModel(UFG::DamageModel *this)
{
  UFG::DamageModel *v1; // rbx
  UFG::AudioEvent *v2; // rcx
  UFG::AudioEvent *v3; // rcx
  UFG::AudioEvent *v4; // rcx
  UFG::AudioEvent *v5; // rcx
  UFG::AudioEvent *v6; // rcx
  UFG::AudioEvent *v7; // rcx

  v1 = this;
  if ( this->m_ecEngineSteam.m_pEvent )
  {
    v2 = this->m_ecEngineSteam.m_pEvent;
    if ( v2 )
      UFG::AudioEvent::StopAndForget(v2, 0xFAu);
  }
  if ( v1->m_ecEngineClank.m_pEvent )
  {
    v3 = v1->m_ecEngineClank.m_pEvent;
    if ( v3 )
      UFG::AudioEvent::StopAndForget(v3, 0xFAu);
  }
  if ( v1->m_ecDrivingOnRim.m_pEvent )
  {
    v4 = v1->m_ecDrivingOnRim.m_pEvent;
    if ( v4 )
      UFG::AudioEvent::StopAndForget(v4, 0xFAu);
  }
  v5 = v1->m_ecDrivingOnRim.m_pEvent;
  if ( v5 )
    UFG::AudioEvent::OnControllerDestroy(v5);
  v6 = v1->m_ecEngineClank.m_pEvent;
  if ( v6 )
    UFG::AudioEvent::OnControllerDestroy(v6);
  v7 = v1->m_ecEngineSteam.m_pEvent;
  if ( v7 )
    UFG::AudioEvent::OnControllerDestroy(v7);
}

// File Line: 67
// RVA: 0x67BE60
void __fastcall UFG::DamageModel::HandleDamagedTires(UFG::DamageModel *this)
{
  UFG::DamageModel *v1; // rbx
  UFG::qPropertySet *v2; // rdi
  char *v3; // r13
  signed __int64 v4; // rbp
  signed int v5; // ecx
  __int64 v6; // rdx
  __int64 v7; // rdi
  signed __int64 v8; // rcx
  char v9; // r15
  char v10; // r14
  int v11; // esi
  UFG::PhysicsMoverInterface *v12; // rcx
  UFG::PhysicsVehicle *v13; // rax
  UFG::PhysicsWheeledVehicle *v14; // rcx
  bool v15; // al
  UFG::VehicleAudioComponent *v16; // rax
  __m128 v17; // xmm2
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  UFG::VehicleAudioComponent *v21; // rcx
  UFG::AudioEvent *v22; // rcx

  v1 = this;
  v2 = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v2->mSchemaName.mUID) )
    v3 = UFG::qPropertySet::GetMemImagePtr(v2);
  else
    v3 = 0i64;
  v4 = 160i64;
  v5 = v1->m_mover->mNumWheels;
  if ( v5 > 4 )
    v5 = 4;
  v6 = 0i64;
  v7 = v5;
  if ( v5 > 0 )
  {
    v8 = 160i64;
    do
    {
      if ( *(float *)((char *)&v1->m_mover->vfptr + v8) >= 1.0 && !v1->m_tireBlown[v6] )
        v1->m_tireBlown[v6] = 1;
      ++v6;
      v8 += 4i64;
    }
    while ( v6 < v7 );
  }
  v9 = 0;
  v10 = 0;
  v11 = 0;
  if ( v7 <= 0 )
    goto LABEL_36;
  do
  {
    v12 = v1->m_mover;
    v9 |= 1.0 <= *(float *)((char *)&v12->vfptr + v4);
    v13 = v12->mPhysicsVehicle;
    if ( !v13 )
      goto LABEL_37;
    v14 = 0i64;
    if ( *((_BYTE *)v13 + 604) & 7 )
      v14 = (UFG::PhysicsWheeledVehicle *)v13;
    if ( v14 )
      v15 = UFG::PhysicsWheeledVehicle::IsWheelOnGround(v14, v11);
    else
LABEL_37:
      v15 = 1;
    v10 |= v15;
    ++v11;
    v4 += 4i64;
    --v7;
  }
  while ( v7 );
  if ( v9 && v10 )
  {
    v16 = v1->m_pVehAudComponent;
    v17 = (__m128)LODWORD(v1->m_lastTireFlapPos.y);
    v18 = v1->m_pVehAudComponent->m_WorldMatrix.v3.x;
    v19 = v1->m_pVehAudComponent->m_WorldMatrix.v3.y;
    v20 = v1->m_pVehAudComponent->m_WorldMatrix.v3.z;
    v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0] - v19) * (float)(v17.m128_f32[0] - v19))
                            + (float)((float)(v1->m_lastTireFlapPos.x - v18) * (float)(v1->m_lastTireFlapPos.x - v18)))
                    + (float)((float)(v1->m_lastTireFlapPos.z - v20) * (float)(v1->m_lastTireFlapPos.z - v20));
    if ( COERCE_FLOAT(_mm_sqrt_ps(v17)) > *((float *)v3 + 7) )
    {
      v1->m_lastTireFlapPos.x = v18;
      v1->m_lastTireFlapPos.y = v19;
      v1->m_lastTireFlapPos.z = v20;
      if ( v16->m_eDriverType <= 1 || v16->m_fDistance2ToListener < 400.0 )
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v16->vfptr, *((_DWORD *)v3 + 8), 0i64, 0, 0i64);
    }
    if ( !v1->m_ecDrivingOnRim.m_pEvent )
    {
      v21 = v1->m_pVehAudComponent;
      if ( (v1->m_pVehAudComponent->m_eDriverType <= 1 || v21->m_fDistance2ToListener < 400.0)
        && v1->m_pVehAudComponent->m_rateLimitedSpeed.m_targetValue > 0.001 )
      {
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&v21->vfptr,
          play_veh_tire_drive_rim_01.mUID,
          &v1->m_ecDrivingOnRim,
          0i64,
          0,
          0i64);
      }
    }
  }
  else
  {
LABEL_36:
    v22 = v1->m_ecDrivingOnRim.m_pEvent;
    if ( v22 && v1->m_pVehAudComponent->m_rateLimitedSpeed.m_targetValue < 0.001 )
      UFG::AudioEvent::StopAndForget(v22, 0x64u);
  }
}

// File Line: 132
// RVA: 0x67BC00
void __fastcall UFG::DamageModel::HandleDamagedEngine(UFG::DamageModel *this)
{
  UFG::DamageModel *v1; // rbx
  UFG::AudioEvent *v2; // rcx
  UFG::AudioEvent *v3; // rcx
  float v4; // xmm0_4
  UFG::AudioEvent *v5; // rcx
  float v6; // xmm2_4

  v1 = this;
  if ( this->m_mover->mDamageState.engineDamage < 0.5 )
  {
    v2 = this->m_ecEngineSteam.m_pEvent;
    if ( v2 )
      UFG::AudioEvent::StopAndForget(v2, 0xFAu);
    v3 = v1->m_ecEngineClank.m_pEvent;
    if ( v3 )
      UFG::AudioEvent::StopAndForget(v3, 0xFAu);
  }
  v4 = v1->m_mover->mDamageState.engineDamage;
  if ( v4 >= 0.5 && v4 < 1.0 && *((_BYTE *)v1->m_pVehAudComponent + 636) & 1 && !v1->m_ecEngineClank.m_pEvent )
  {
    if ( !(_S13_8 & 1) )
    {
      _S13_8 |= 1u;
      play_engine_clank.mUID = UFG::qWiseSymbolUIDFromString("play_engine_clank", 0x811C9DC5);
      _((AMD_HD3D *)play_engine_clank.mUID);
      atexit(UFG::DamageModel::HandleDamagedEngine_::_20_::_dynamic_atexit_destructor_for__play_engine_clank__);
    }
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&v1->m_pVehAudComponent->vfptr,
      play_engine_clank.mUID,
      &v1->m_ecEngineClank,
      0i64,
      0,
      0i64);
  }
  if ( v1->m_mover->mDamageState.engineDamage >= 1.0 )
  {
    if ( !v1->m_engineBlown )
    {
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&v1->m_pVehAudComponent->vfptr,
        Play_engine_blown_id,
        0i64,
        0,
        0i64);
      v1->m_engineBlown = 1;
    }
    if ( v1->m_pVehAudComponent->m_eDriverType == eDriverType_Player && !v1->m_ecEngineSteam.m_pEvent )
    {
      if ( !(_S13_8 & 2) )
      {
        _S13_8 |= 2u;
        play_steam.mUID = UFG::qWiseSymbolUIDFromString("play_steam", 0x811C9DC5);
        _((AMD_HD3D *)play_steam.mUID);
        atexit(UFG::DamageModel::HandleDamagedEngine_::_29_::_dynamic_atexit_destructor_for__play_steam__);
      }
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&v1->m_pVehAudComponent->vfptr,
        play_steam.mUID,
        &v1->m_ecEngineSteam,
        0i64,
        0,
        0i64);
    }
  }
  if ( !(*((_BYTE *)v1->m_pVehAudComponent + 636) & 1) )
  {
    v5 = v1->m_ecEngineClank.m_pEvent;
    if ( v5 )
      UFG::AudioEvent::StopAndForget(v5, 0xFAu);
  }
  if ( !(_S13_8 & 4) )
  {
    _S13_8 |= 4u;
    engine_damage.mUID = UFG::qWiseSymbolUIDFromString("engine_damage", 0x811C9DC5);
    _((AMD_HD3D *)engine_damage.mUID);
    atexit(UFG::DamageModel::HandleDamagedEngine_::_35_::_dynamic_atexit_destructor_for__engine_damage__);
  }
  v6 = v1->m_mover->mDamageState.engineDamage;
  if ( v6 != v1->m_lastEngineDamage )
  {
    UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v1->m_pVehAudComponent->vfptr, engine_damage.mUID, v6);
    v1->m_lastEngineDamage = v1->m_mover->mDamageState.engineDamage;
  }
}

