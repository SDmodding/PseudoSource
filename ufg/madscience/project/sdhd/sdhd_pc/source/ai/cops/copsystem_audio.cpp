// File Line: 4
// RVA: 0x14D7520
__int64 UFG::_dynamic_initializer_for__player_is_escaping_by_vehicle_speed_threshold__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("player_is_escaping_by_vehicle_speed_threshold", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&player_is_escaping_by_vehicle_speed_threshold, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__player_is_escaping_by_vehicle_speed_threshold__);
}

// File Line: 5
// RVA: 0x14D91C0
__int64 UFG::_dynamic_initializer_for__surrender_vehicle_min_distance__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("surrender_vehicle_min_distance", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&surrender_vehicle_min_distance, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__surrender_vehicle_min_distance__);
}

// File Line: 6
// RVA: 0x14D9180
__int64 UFG::_dynamic_initializer_for__surrender_vehicle_max_distance__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("surrender_vehicle_max_distance", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&surrender_vehicle_max_distance, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__surrender_vehicle_max_distance__);
}

// File Line: 7
// RVA: 0x14D9240
__int64 UFG::_dynamic_initializer_for__vehicle_pursuit_min_time__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("vehicle_pursuit_min_time", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&vehicle_pursuit_min_time, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__vehicle_pursuit_min_time__);
}

// File Line: 8
// RVA: 0x14D9200
__int64 UFG::_dynamic_initializer_for__vehicle_pursuit_max_time__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("vehicle_pursuit_max_time", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&vehicle_pursuit_max_time, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__vehicle_pursuit_max_time__);
}

// File Line: 9
// RVA: 0x14D90F0
__int64 UFG::_dynamic_initializer_for__scanner_min_time__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("scanner_min_time", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&scanner_min_time, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__scanner_min_time__);
}

// File Line: 10
// RVA: 0x14D90B0
__int64 UFG::_dynamic_initializer_for__scanner_max_time__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("scanner_max_time", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&scanner_max_time, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__scanner_max_time__);
}

// File Line: 11
// RVA: 0x14D6F20
__int64 UFG::_dynamic_initializer_for__chance_pursuit_is_from_scanner__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("chance_pursuit_is_from_scanner", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&chance_pursuit_is_from_scanner, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__chance_pursuit_is_from_scanner__);
}

// File Line: 14
// RVA: 0x3EF950
float __fastcall UFG::RandomMinMax(float min, float max)
{
  float v2; // xmm6_4

  v2 = min;
  if ( min >= max )
    v2 = max;
  return UFG::qRandom(max - v2, (unsigned int *)&UFG::qDefaultSeed) + v2;
}

// File Line: 26
// RVA: 0x3EEE20
void __fastcall UFG::CopSystem::HandleHeatLevelChangeAudio(
        UFG::CopSystem *this,
        signed int oldHeatLevel,
        signed int newHeatLevel)
{
  signed __int16 m_Flags; // dx
  UFG::ActorAudioComponent *v5; // rax
  const char *v6; // r8
  float outDistanceToPlayer; // [rsp+58h] [rbp+10h] BYREF
  UFG::SimObject *outClosestCop; // [rsp+68h] [rbp+20h] BYREF

  if ( newHeatLevel > oldHeatLevel )
  {
    if ( this->mFocusTargetContext.mIsOnFootRaw )
    {
      outClosestCop = 0i64;
      UFG::CopSystem::FindClosestHumanCopForAudio(this, &outClosestCop, &outDistanceToPlayer);
      if ( outClosestCop )
      {
        m_Flags = outClosestCop->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
          v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>((UFG::SimObjectCharacter *)outClosestCop);
        else
          v5 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)outClosestCop,
                                              UFG::ActorAudioComponent::_TypeUID)
                                          : UFG::SimObject::GetComponentOfType(
                                              outClosestCop,
                                              UFG::ActorAudioComponent::_TypeUID));
        if ( v5 )
        {
          if ( newHeatLevel == 1 || newHeatLevel == 2 )
          {
            v6 = "police_heat";
          }
          else if ( newHeatLevel == 3 )
          {
            v6 = "police_heat_3";
          }
          else
          {
            v6 = "police_heat_4";
            if ( newHeatLevel != 4 && newHeatLevel != 5 )
              v6 = 0i64;
          }
          UFG::ActorAudioComponent::QueueSpeechExternalAmbient(
            v5,
            play_police_on_foot_heat_level_increase_9.mUID,
            v6,
            0i64,
            5u,
            0,
            0);
        }
      }
    }
    else if ( unk_14242F240 )
    {
      UFG::PoliceScannerAudio::OnHeatLevelIncrease(&UFG::PoliceScannerAudio::sm_Instance, newHeatLevel);
    }
  }
}

// File Line: 83
// RVA: 0x3ED1C0
void __fastcall UFG::CopSystem::FindClosestHumanCopForAudio(
        UFG::CopSystem *this,
        UFG::SimObject **outClosestCop,
        float *outDistanceToPlayer)
{
  UFG::SimObject *v6; // r14
  unsigned int v7; // ebx
  float i; // xmm6_4
  UFG::SimObject *m_pSimObject; // rdi
  float *m_pTransformNodeComponent; // rbp

  if ( ((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[18].__vecDelDtor)(this) )
  {
    v6 = 0i64;
    v7 = 0;
    for ( i = FLOAT_100000_0; v7 < this->mHumans.size; ++v7 )
    {
      m_pSimObject = this->mHumans.p[v7]->m_pSimObject;
      if ( m_pSimObject )
      {
        m_pTransformNodeComponent = (float *)m_pSimObject->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject->m_pTransformNodeComponent);
          if ( (float)((float)((float)((float)(m_pTransformNodeComponent[45] - this->mFocusTargetPosition.y)
                                     * (float)(m_pTransformNodeComponent[45] - this->mFocusTargetPosition.y))
                             + (float)((float)(m_pTransformNodeComponent[44] - this->mFocusTargetPosition.x)
                                     * (float)(m_pTransformNodeComponent[44] - this->mFocusTargetPosition.x)))
                     + (float)((float)(m_pTransformNodeComponent[46] - this->mFocusTargetPosition.z)
                             * (float)(m_pTransformNodeComponent[46] - this->mFocusTargetPosition.z))) < i )
          {
            v6 = m_pSimObject;
            i = (float)((float)((float)(m_pTransformNodeComponent[45] - this->mFocusTargetPosition.y)
                              * (float)(m_pTransformNodeComponent[45] - this->mFocusTargetPosition.y))
                      + (float)((float)(m_pTransformNodeComponent[44] - this->mFocusTargetPosition.x)
                              * (float)(m_pTransformNodeComponent[44] - this->mFocusTargetPosition.x)))
              + (float)((float)(m_pTransformNodeComponent[46] - this->mFocusTargetPosition.z)
                      * (float)(m_pTransformNodeComponent[46] - this->mFocusTargetPosition.z));
          }
        }
      }
    }
    if ( outClosestCop )
      *outClosestCop = v6;
    if ( outDistanceToPlayer )
      *outDistanceToPlayer = i;
  }
}

// File Line: 121
// RVA: 0x3ED2E0
void __fastcall UFG::CopSystem::FindClosestVehicleCopForAudio(
        UFG::CopSystem *this,
        UFG::SimObject **outClosestCop,
        float *outDistanceToPlayer)
{
  UFG::SimObject *v6; // r14
  unsigned int v7; // ebx
  float i; // xmm6_4
  UFG::SimObject *m_pSimObject; // rdi
  float *m_pTransformNodeComponent; // rbp
  float v11; // xmm2_4

  if ( ((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[18].__vecDelDtor)(this) )
  {
    v6 = 0i64;
    v7 = 0;
    for ( i = FLOAT_100000_0; v7 < this->mVehicles.size; ++v7 )
    {
      m_pSimObject = this->mVehicles.p[v7]->m_pSimObject;
      if ( m_pSimObject )
      {
        m_pTransformNodeComponent = (float *)m_pSimObject->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject->m_pTransformNodeComponent);
          v11 = (float)((float)((float)(m_pTransformNodeComponent[45] - this->mFocusTargetPosition.y)
                              * (float)(m_pTransformNodeComponent[45] - this->mFocusTargetPosition.y))
                      + (float)((float)(m_pTransformNodeComponent[44] - this->mFocusTargetPosition.x)
                              * (float)(m_pTransformNodeComponent[44] - this->mFocusTargetPosition.x)))
              + (float)((float)(m_pTransformNodeComponent[46] - this->mFocusTargetPosition.z)
                      * (float)(m_pTransformNodeComponent[46] - this->mFocusTargetPosition.z));
          if ( v11 < i && v11 > 1.0 )
          {
            v6 = m_pSimObject;
            i = (float)((float)((float)(m_pTransformNodeComponent[45] - this->mFocusTargetPosition.y)
                              * (float)(m_pTransformNodeComponent[45] - this->mFocusTargetPosition.y))
                      + (float)((float)(m_pTransformNodeComponent[44] - this->mFocusTargetPosition.x)
                              * (float)(m_pTransformNodeComponent[44] - this->mFocusTargetPosition.x)))
              + (float)((float)(m_pTransformNodeComponent[46] - this->mFocusTargetPosition.z)
                      * (float)(m_pTransformNodeComponent[46] - this->mFocusTargetPosition.z));
          }
        }
      }
    }
    if ( outClosestCop )
      *outClosestCop = v6;
    if ( outDistanceToPlayer )
      *outDistanceToPlayer = i;
  }
}

// File Line: 159
// RVA: 0x3F0720
void __fastcall UFG::CopSystem::ShutdownAudio(UFG::CopSystem *this)
{
  if ( UFG::OneShotHandle::IsValid(&this->mDistantSirens) )
    UFG::OneShot::Stop(this->mDistantSirens.m_pOneShot, 0x64u, 0);
  *(_QWORD *)&this->mAudioHeatLevel.m_currentValue = 0i64;
}

// File Line: 170
// RVA: 0x3F0DD0
void __fastcall UFG::CopSystem::UpdateAudio(UFG::CopSystem *this, float deltaTime)
{
  UFG::RateLimitedFloatNoMinMax *p_mAudioHeatLevel; // rbx
  float m_targetValue; // xmm1_4
  float m_fallRate; // xmm2_4
  unsigned int v7; // eax
  float m_currentValue; // xmm6_4
  UFG::TiDo *Instance; // rax
  float v10; // xmm7_4
  UFG::HeatLevelEnum mHeatLevel; // eax
  bool v12; // cc
  float *v13; // rbx
  float *v14; // rax
  float v15; // xmm6_4
  float *v16; // rbx
  float *v17; // rbx
  float *v18; // rax
  float v19; // xmm0_4
  float *v20; // rbp
  float *v21; // r14
  __int64 v22; // rax
  __int64 v23; // rbx
  __m128 v24; // xmm6
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCharacter *Texture; // rax
  __int16 v29; // dx
  UFG::ActorAudioComponent *ComponentOfType; // rax
  float *v31; // rbx
  float *v32; // rax
  UFG::SimObject *outClosestCop; // [rsp+A0h] [rbp+8h] BYREF
  float outDistanceToPlayer; // [rsp+A8h] [rbp+10h] BYREF

  this->mAudioHeatLevel.m_riseRate = 3.0;
  this->mAudioHeatLevel.m_fallRate = 3.0;
  this->mAudioHeatLevel.m_targetValue = (float)this->mHeatLevel;
  p_mAudioHeatLevel = &this->mAudioHeatLevel;
  m_targetValue = this->mAudioHeatLevel.m_targetValue;
  if ( m_targetValue < this->mAudioHeatLevel.m_currentValue )
    m_fallRate = this->mAudioHeatLevel.m_fallRate;
  else
    m_fallRate = this->mAudioHeatLevel.m_riseRate;
  UFG::qApproach(&this->mAudioHeatLevel.m_currentValue, m_targetValue, m_fallRate, deltaTime);
  v7 = _S7_9;
  if ( (_S7_9 & 1) == 0 )
  {
    _S7_9 |= 1u;
    heat_level.mUID = UFG::qWiseSymbolUIDFromString("heat_level", 0x811C9DC5);
    _((AMD_HD3D *)heat_level.mUID);
    atexit(UFG::CopSystem::UpdateAudio_::_2_::_dynamic_atexit_destructor_for__heat_level__);
    v7 = _S7_9;
  }
  if ( (v7 & 2) == 0 )
  {
    _S7_9 = v7 | 2;
    play_distant_sirens.mUID = UFG::qWiseSymbolUIDFromString("play_distant_sirens", 0x811C9DC5);
    _((AMD_HD3D *)play_distant_sirens.mUID);
    atexit(UFG::CopSystem::UpdateAudio_::_2_::_dynamic_atexit_destructor_for__play_distant_sirens__);
  }
  if ( p_mAudioHeatLevel->m_currentValue != last_heat_level )
  {
    if ( p_mAudioHeatLevel->m_currentValue >= 1.0 && !UFG::OneShotHandle::IsValid(&this->mDistantSirens) )
    {
      UFG::OneShotPool::GetOneShotHandle(&this->mDistantSirens, &UFG::qMatrix44::msIdentity);
      if ( UFG::OneShotHandle::IsValid(&this->mDistantSirens) )
        UFG::OneShot::Play(this->mDistantSirens.m_pOneShot, play_distant_sirens.mUID);
    }
    if ( p_mAudioHeatLevel->m_currentValue < 1.0 && UFG::OneShotHandle::IsValid(&this->mDistantSirens) )
      UFG::OneShotHandle::StopAndRelease(&this->mDistantSirens);
    m_currentValue = p_mAudioHeatLevel->m_currentValue;
    Instance = UFG::TiDo::GetInstance();
    UFG::TiDo::SetWwiseRtpcValue(Instance, heat_level.mUID, m_currentValue, 0xFFFFFFFFFFFFFFFFui64);
    last_heat_level = p_mAudioHeatLevel->m_currentValue;
  }
  v10 = deltaTime + this->mAudioTimer;
  this->mAudioTimer = v10;
  if ( !unk_14242F240 )
  {
LABEL_28:
    if ( this->mHeatLevel == HEATLEVEL_NONE )
      return;
    if ( this->mAudioPursuitDelay > this->mAudioTimer )
      return;
    if ( !this->mVehicles.size )
      return;
    v20 = UFG::qPropertySet::Get<float>(
            this->mCopAudioConfig,
            (UFG::qArray<unsigned long,0> *)&surrender_vehicle_min_distance,
            DEPTH_RECURSE);
    v21 = UFG::qPropertySet::Get<float>(
            this->mCopAudioConfig,
            (UFG::qArray<unsigned long,0> *)&surrender_vehicle_max_distance,
            DEPTH_RECURSE);
    v22 = ((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[18].__vecDelDtor)(this);
    if ( !v22 )
      return;
    v23 = *(_QWORD *)(v22 + 88);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v23);
    v24 = (__m128)*(unsigned int *)(v23 + 256);
    v24.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0])
                            + (float)(*(float *)(v23 + 260) * *(float *)(v23 + 260)))
                    + (float)(*(float *)(v23 + 264) * *(float *)(v23 + 264));
    if ( _mm_sqrt_ps(v24).m128_f32[0] < *UFG::qPropertySet::Get<float>(
                                           this->mCopAudioConfig,
                                           (UFG::qArray<unsigned long,0> *)&player_is_escaping_by_vehicle_speed_threshold,
                                           DEPTH_RECURSE) )
      return;
    outClosestCop = 0i64;
    outDistanceToPlayer = 0.0;
    UFG::CopSystem::FindClosestVehicleCopForAudio(this, &outClosestCop, &outDistanceToPlayer);
    if ( outDistanceToPlayer > (float)(*v21 * *v21) || outDistanceToPlayer < (float)(*v20 * *v20) )
    {
      v19 = this->mAudioPursuitDelay + 3.0;
      goto LABEL_60;
    }
    if ( !outClosestCop )
      return;
    m_Flags = outClosestCop->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      goto LABEL_42;
    if ( m_Flags < 0 )
    {
      m_pComponent = outClosestCop->m_Components.p[30].m_pComponent;
      goto LABEL_45;
    }
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_42:
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            (UFG::SimObjectGame *)outClosestCop,
                            UFG::VehicleOccupantComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(outClosestCop, UFG::VehicleOccupantComponent::_TypeUID);
    m_pComponent = ComponentOfTypeHK;
LABEL_45:
    if ( m_pComponent )
    {
      if ( Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent) )
      {
        Texture = (UFG::SimObjectCharacter *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent);
        if ( Texture )
        {
          v29 = Texture->m_Flags;
          if ( (v29 & 0x4000) != 0 )
          {
            ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(Texture);
          }
          else if ( v29 < 0 || (v29 & 0x2000) != 0 || (v29 & 0x1000) != 0 )
          {
            ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            Texture,
                                                            UFG::ActorAudioComponent::_TypeUID);
          }
          else
          {
            ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                            Texture,
                                                            UFG::ActorAudioComponent::_TypeUID);
          }
          if ( ComponentOfType )
            UFG::ActorAudioComponent::QueueSpeechExternalAmbient(
              ComponentOfType,
              play_police_bullhorn_9.mUID,
              "police_surrender_car",
              0i64,
              5u,
              0,
              0);
        }
      }
    }
    v31 = UFG::qPropertySet::Get<float>(
            this->mCopAudioConfig,
            (UFG::qArray<unsigned long,0> *)&vehicle_pursuit_min_time,
            DEPTH_RECURSE);
    v32 = UFG::qPropertySet::Get<float>(
            this->mCopAudioConfig,
            (UFG::qArray<unsigned long,0> *)&vehicle_pursuit_max_time,
            DEPTH_RECURSE);
    v19 = UFG::RandomMinMax(*v31, *v32);
    this->mAudioTimer = 0.0;
    goto LABEL_60;
  }
  mHeatLevel = this->mHeatLevel;
  v12 = mHeatLevel <= HEATLEVEL_NONE;
  if ( mHeatLevel )
  {
LABEL_24:
    if ( !v12 && v10 > this->mAudioPursuitDelay )
    {
      v16 = UFG::qPropertySet::Get<float>(
              this->mCopAudioConfig,
              (UFG::qArray<unsigned long,0> *)&chance_pursuit_is_from_scanner,
              DEPTH_RECURSE);
      if ( UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) < *v16 )
      {
        UFG::PoliceScannerAudio::PlayScenario(&UFG::PoliceScannerAudio::sm_Instance, "Chase");
        v17 = UFG::qPropertySet::Get<float>(
                this->mCopAudioConfig,
                (UFG::qArray<unsigned long,0> *)&vehicle_pursuit_min_time,
                DEPTH_RECURSE);
        v18 = UFG::qPropertySet::Get<float>(
                this->mCopAudioConfig,
                (UFG::qArray<unsigned long,0> *)&vehicle_pursuit_max_time,
                DEPTH_RECURSE);
        v19 = UFG::RandomMinMax(*v17, *v18);
        this->mAudioTimer = 0.0;
LABEL_60:
        this->mAudioPursuitDelay = v19;
        return;
      }
    }
    goto LABEL_28;
  }
  if ( v10 <= this->mAudioScannerDelay )
  {
    v12 = 1;
    goto LABEL_24;
  }
  UFG::PoliceScannerAudio::PlayScenario(&UFG::PoliceScannerAudio::sm_Instance, "Ambient_Chatter");
  v13 = UFG::qPropertySet::Get<float>(
          this->mCopAudioConfig,
          (UFG::qArray<unsigned long,0> *)&scanner_min_time,
          DEPTH_RECURSE);
  v14 = UFG::qPropertySet::Get<float>(
          this->mCopAudioConfig,
          (UFG::qArray<unsigned long,0> *)&scanner_max_time,
          DEPTH_RECURSE);
  v15 = *v13;
  if ( *v13 >= *v14 )
    v15 = *v14;
  this->mAudioScannerDelay = UFG::qRandom(*v14 - v15, (unsigned int *)&UFG::qDefaultSeed) + v15;
  this->mAudioTimer = 0.0;
}

