// File Line: 4
// RVA: 0x14D7520
__int64 UFG::_dynamic_initializer_for__player_is_escaping_by_vehicle_speed_threshold__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("player_is_escaping_by_vehicle_speed_threshold", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&player_is_escaping_by_vehicle_speed_threshold, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__player_is_escaping_by_vehicle_speed_threshold__);
}

// File Line: 5
// RVA: 0x14D91C0
__int64 UFG::_dynamic_initializer_for__surrender_vehicle_min_distance__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("surrender_vehicle_min_distance", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&surrender_vehicle_min_distance, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__surrender_vehicle_min_distance__);
}

// File Line: 6
// RVA: 0x14D9180
__int64 UFG::_dynamic_initializer_for__surrender_vehicle_max_distance__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("surrender_vehicle_max_distance", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&surrender_vehicle_max_distance, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__surrender_vehicle_max_distance__);
}

// File Line: 7
// RVA: 0x14D9240
__int64 UFG::_dynamic_initializer_for__vehicle_pursuit_min_time__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("vehicle_pursuit_min_time", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&vehicle_pursuit_min_time, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__vehicle_pursuit_min_time__);
}

// File Line: 8
// RVA: 0x14D9200
__int64 UFG::_dynamic_initializer_for__vehicle_pursuit_max_time__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("vehicle_pursuit_max_time", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&vehicle_pursuit_max_time, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__vehicle_pursuit_max_time__);
}

// File Line: 9
// RVA: 0x14D90F0
__int64 UFG::_dynamic_initializer_for__scanner_min_time__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("scanner_min_time", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&scanner_min_time, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__scanner_min_time__);
}

// File Line: 10
// RVA: 0x14D90B0
__int64 UFG::_dynamic_initializer_for__scanner_max_time__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("scanner_max_time", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&scanner_max_time, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__scanner_max_time__);
}

// File Line: 11
// RVA: 0x14D6F20
__int64 UFG::_dynamic_initializer_for__chance_pursuit_is_from_scanner__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("chance_pursuit_is_from_scanner", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&chance_pursuit_is_from_scanner, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__chance_pursuit_is_from_scanner__);
}

// File Line: 14
// RVA: 0x3EF950
float __fastcall UFG::RandomMinMax(float min, float max)
{
  float v2; // xmm6_4

  v2 = min;
  if ( min >= max )
    v2 = max;
  return UFG::qRandom(max - v2, &UFG::qDefaultSeed) + v2;
}

// File Line: 26
// RVA: 0x3EEE20
void __fastcall UFG::CopSystem::HandleHeatLevelChangeAudio(UFG::CopSystem *this, UFG::HeatLevelEnum oldHeatLevel, UFG::HeatLevelEnum newHeatLevel)
{
  UFG::HeatLevelEnum v3; // ebx
  unsigned __int16 v4; // dx
  UFG::ActorAudioComponent *v5; // rax
  const char *v6; // r8
  float outDistanceToPlayer; // [rsp+58h] [rbp+10h]
  UFG::SimObject *outClosestCop; // [rsp+68h] [rbp+20h]

  if ( newHeatLevel > oldHeatLevel )
  {
    v3 = newHeatLevel;
    if ( this->mFocusTargetContext.mIsOnFootRaw )
    {
      outClosestCop = 0i64;
      UFG::CopSystem::FindClosestHumanCopForAudio(this, &outClosestCop, &outDistanceToPlayer);
      if ( outClosestCop )
      {
        v4 = outClosestCop->m_Flags;
        if ( (v4 >> 14) & 1 )
        {
          v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>((UFG::SimObjectCharacter *)outClosestCop);
        }
        else if ( (v4 & 0x8000u) == 0 )
        {
          if ( (v4 >> 13) & 1 )
            v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)outClosestCop,
                                               UFG::ActorAudioComponent::_TypeUID);
          else
            v5 = (UFG::ActorAudioComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)outClosestCop,
                                                                 UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(outClosestCop, UFG::ActorAudioComponent::_TypeUID));
        }
        else
        {
          v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)outClosestCop,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
        if ( v5 )
        {
          if ( v3 == 1 || v3 == 2 )
          {
            v6 = "police_heat";
          }
          else if ( v3 == 3 )
          {
            v6 = "police_heat_3";
          }
          else
          {
            v6 = "police_heat_4";
            if ( v3 != 4 && v3 != 5 )
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
void __fastcall UFG::CopSystem::FindClosestHumanCopForAudio(UFG::CopSystem *this, UFG::SimObject **outClosestCop, float *outDistanceToPlayer)
{
  float *v3; // r15
  UFG::SimObject **v4; // r12
  UFG::CopSystem *v5; // rsi
  UFG::SimObject *v6; // r14
  unsigned int v7; // ebx
  float v8; // xmm6_4
  UFG::SimObject *v9; // rdi
  float *v10; // rbp

  v3 = outDistanceToPlayer;
  v4 = outClosestCop;
  v5 = this;
  if ( ((__int64 (*)(void))this->vfptr[18].__vecDelDtor)() )
  {
    v6 = 0i64;
    v7 = 0;
    v8 = FLOAT_100000_0;
    if ( v5->mHumans.size )
    {
      do
      {
        v9 = v5->mHumans.p[v7]->m_pSimObject;
        if ( v9 )
        {
          v10 = (float *)v9->m_pTransformNodeComponent;
          if ( v10 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v9->m_pTransformNodeComponent);
            if ( (float)((float)((float)((float)(v10[45] - v5->mFocusTargetPosition.y)
                                       * (float)(v10[45] - v5->mFocusTargetPosition.y))
                               + (float)((float)(v10[44] - v5->mFocusTargetPosition.x)
                                       * (float)(v10[44] - v5->mFocusTargetPosition.x)))
                       + (float)((float)(v10[46] - v5->mFocusTargetPosition.z)
                               * (float)(v10[46] - v5->mFocusTargetPosition.z))) < v8 )
            {
              v6 = v9;
              v8 = (float)((float)((float)(v10[45] - v5->mFocusTargetPosition.y)
                                 * (float)(v10[45] - v5->mFocusTargetPosition.y))
                         + (float)((float)(v10[44] - v5->mFocusTargetPosition.x)
                                 * (float)(v10[44] - v5->mFocusTargetPosition.x)))
                 + (float)((float)(v10[46] - v5->mFocusTargetPosition.z) * (float)(v10[46] - v5->mFocusTargetPosition.z));
            }
          }
        }
        ++v7;
      }
      while ( v7 < v5->mHumans.size );
    }
    if ( v4 )
      *v4 = v6;
    if ( v3 )
      *v3 = v8;
  }
}

// File Line: 121
// RVA: 0x3ED2E0
void __fastcall UFG::CopSystem::FindClosestVehicleCopForAudio(UFG::CopSystem *this, UFG::SimObject **outClosestCop, float *outDistanceToPlayer)
{
  float *v3; // r15
  UFG::SimObject **v4; // r12
  UFG::CopSystem *v5; // rsi
  UFG::SimObject *v6; // r14
  unsigned int v7; // ebx
  float v8; // xmm6_4
  UFG::SimObject *v9; // rdi
  float *v10; // rbp
  float v11; // xmm2_4

  v3 = outDistanceToPlayer;
  v4 = outClosestCop;
  v5 = this;
  if ( ((__int64 (*)(void))this->vfptr[18].__vecDelDtor)() )
  {
    v6 = 0i64;
    v7 = 0;
    v8 = FLOAT_100000_0;
    if ( v5->mVehicles.size )
    {
      do
      {
        v9 = v5->mVehicles.p[v7]->m_pSimObject;
        if ( v9 )
        {
          v10 = (float *)v9->m_pTransformNodeComponent;
          if ( v10 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v9->m_pTransformNodeComponent);
            v11 = (float)((float)((float)(v10[45] - v5->mFocusTargetPosition.y)
                                * (float)(v10[45] - v5->mFocusTargetPosition.y))
                        + (float)((float)(v10[44] - v5->mFocusTargetPosition.x)
                                * (float)(v10[44] - v5->mFocusTargetPosition.x)))
                + (float)((float)(v10[46] - v5->mFocusTargetPosition.z) * (float)(v10[46] - v5->mFocusTargetPosition.z));
            if ( v11 < v8 && v11 > 1.0 )
            {
              v6 = v9;
              v8 = (float)((float)((float)(v10[45] - v5->mFocusTargetPosition.y)
                                 * (float)(v10[45] - v5->mFocusTargetPosition.y))
                         + (float)((float)(v10[44] - v5->mFocusTargetPosition.x)
                                 * (float)(v10[44] - v5->mFocusTargetPosition.x)))
                 + (float)((float)(v10[46] - v5->mFocusTargetPosition.z) * (float)(v10[46] - v5->mFocusTargetPosition.z));
            }
          }
        }
        ++v7;
      }
      while ( v7 < v5->mVehicles.size );
    }
    if ( v4 )
      *v4 = v6;
    if ( v3 )
      *v3 = v8;
  }
}

// File Line: 159
// RVA: 0x3F0720
void __fastcall UFG::CopSystem::ShutdownAudio(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rbx

  v1 = this;
  if ( UFG::OneShotHandle::IsValid(&this->mDistantSirens) )
    UFG::OneShot::Stop(v1->mDistantSirens.m_pOneShot, 0x64u, 0);
  *(_QWORD *)&v1->mAudioHeatLevel.m_currentValue = 0i64;
}

// File Line: 170
// RVA: 0x3F0DD0
void __fastcall UFG::CopSystem::UpdateAudio(UFG::CopSystem *this, float deltaTime)
{
  float v2; // xmm7_4
  UFG::CopSystem *v3; // rdi
  float *v4; // rbx
  float v5; // xmm1_4
  float v6; // xmm2_4
  unsigned int v7; // eax
  float v8; // xmm6_4
  UFG::TiDo *v9; // rax
  float v10; // xmm7_4
  UFG::HeatLevelEnum v11; // eax
  bool v12; // zf
  bool v13; // sf
  float *v14; // rbx
  float *v15; // rax
  float v16; // xmm6_4
  float *v17; // rbx
  float *v18; // rbx
  float *v19; // rax
  float v20; // xmm0_4
  float *v21; // rbp
  float *v22; // r14
  __int64 v23; // rax
  __int64 v24; // rbx
  __m128 v25; // xmm6
  unsigned __int16 v26; // dx
  UFG::SimComponent *v27; // rax
  UFG::SimComponent *v28; // rbx
  UFG::SimObjectCharacter *v29; // rax
  unsigned __int16 v30; // dx
  UFG::ActorAudioComponent *v31; // rax
  float *v32; // rbx
  float *v33; // rax
  UFG::SimObject *outClosestCop; // [rsp+A0h] [rbp+8h]
  float outDistanceToPlayer; // [rsp+A8h] [rbp+10h]

  v2 = deltaTime;
  v3 = this;
  this->mAudioHeatLevel.m_riseRate = 3.0;
  this->mAudioHeatLevel.m_fallRate = 3.0;
  this->mAudioHeatLevel.m_targetValue = (float)(signed int)this->mHeatLevel;
  v4 = &this->mAudioHeatLevel.m_currentValue;
  v5 = this->mAudioHeatLevel.m_targetValue;
  if ( v5 < this->mAudioHeatLevel.m_currentValue )
    v6 = this->mAudioHeatLevel.m_fallRate;
  else
    v6 = this->mAudioHeatLevel.m_riseRate;
  UFG::qApproach(&this->mAudioHeatLevel.m_currentValue, v5, v6, v2);
  v7 = _S7_9;
  if ( !(_S7_9 & 1) )
  {
    _S7_9 |= 1u;
    heat_level.mUID = UFG::qWiseSymbolUIDFromString("heat_level", 0x811C9DC5);
    _((AMD_HD3D *)heat_level.mUID);
    atexit(UFG::CopSystem::UpdateAudio_::_2_::_dynamic_atexit_destructor_for__heat_level__);
    v7 = _S7_9;
  }
  if ( !(v7 & 2) )
  {
    _S7_9 = v7 | 2;
    play_distant_sirens.mUID = UFG::qWiseSymbolUIDFromString("play_distant_sirens", 0x811C9DC5);
    _((AMD_HD3D *)play_distant_sirens.mUID);
    atexit(UFG::CopSystem::UpdateAudio_::_2_::_dynamic_atexit_destructor_for__play_distant_sirens__);
  }
  if ( *v4 != last_heat_level )
  {
    if ( *v4 >= 1.0 && !UFG::OneShotHandle::IsValid(&v3->mDistantSirens) )
    {
      UFG::OneShotPool::GetOneShotHandle(&v3->mDistantSirens, &UFG::qMatrix44::msIdentity);
      if ( UFG::OneShotHandle::IsValid(&v3->mDistantSirens) )
        UFG::OneShot::Play(v3->mDistantSirens.m_pOneShot, play_distant_sirens.mUID);
    }
    if ( *v4 < 1.0 && UFG::OneShotHandle::IsValid(&v3->mDistantSirens) )
      UFG::OneShotHandle::StopAndRelease(&v3->mDistantSirens);
    v8 = *v4;
    v9 = UFG::TiDo::GetInstance();
    UFG::TiDo::SetWwiseRtpcValue(v9, heat_level.mUID, v8, 0xFFFFFFFFFFFFFFFFui64);
    last_heat_level = *v4;
  }
  v10 = v2 + v3->mAudioTimer;
  v3->mAudioTimer = v10;
  if ( !unk_14242F240 )
    goto LABEL_28;
  v11 = v3->mHeatLevel;
  v12 = v11 == 0;
  v13 = (signed int)v11 < 0;
  if ( v11 )
  {
LABEL_24:
    if ( !v13 && !v12 && v10 > v3->mAudioPursuitDelay )
    {
      v17 = UFG::qPropertySet::Get<float>(
              v3->mCopAudioConfig,
              (UFG::qSymbol *)&chance_pursuit_is_from_scanner.mUID,
              DEPTH_RECURSE);
      if ( UFG::qRandom(1.0, &UFG::qDefaultSeed) < *v17 )
      {
        UFG::PoliceScannerAudio::PlayScenario(&UFG::PoliceScannerAudio::sm_Instance, "Chase");
        v18 = UFG::qPropertySet::Get<float>(
                v3->mCopAudioConfig,
                (UFG::qSymbol *)&vehicle_pursuit_min_time.mUID,
                DEPTH_RECURSE);
        v19 = UFG::qPropertySet::Get<float>(
                v3->mCopAudioConfig,
                (UFG::qSymbol *)&vehicle_pursuit_max_time.mUID,
                DEPTH_RECURSE);
        v20 = UFG::RandomMinMax(*v18, *v19);
        v3->mAudioTimer = 0.0;
LABEL_62:
        v3->mAudioPursuitDelay = v20;
        return;
      }
    }
LABEL_28:
    if ( v3->mHeatLevel == HEATLEVEL_NONE )
      return;
    if ( v3->mAudioPursuitDelay > v3->mAudioTimer )
      return;
    if ( v3->mVehicles.size < 1 )
      return;
    v21 = UFG::qPropertySet::Get<float>(
            v3->mCopAudioConfig,
            (UFG::qSymbol *)&surrender_vehicle_min_distance.mUID,
            DEPTH_RECURSE);
    v22 = UFG::qPropertySet::Get<float>(
            v3->mCopAudioConfig,
            (UFG::qSymbol *)&surrender_vehicle_max_distance.mUID,
            DEPTH_RECURSE);
    v23 = ((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[18].__vecDelDtor)(v3);
    if ( !v23 )
      return;
    v24 = *(_QWORD *)(v23 + 88);
    UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v23 + 88));
    v25 = (__m128)*(unsigned int *)(v24 + 256);
    v25.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0])
                            + (float)(*(float *)(v24 + 260) * *(float *)(v24 + 260)))
                    + (float)(*(float *)(v24 + 264) * *(float *)(v24 + 264));
    if ( COERCE_FLOAT(_mm_sqrt_ps(v25)) < *UFG::qPropertySet::Get<float>(
                                             v3->mCopAudioConfig,
                                             (UFG::qSymbol *)&player_is_escaping_by_vehicle_speed_threshold.mUID,
                                             DEPTH_RECURSE) )
      return;
    outClosestCop = 0i64;
    outDistanceToPlayer = 0.0;
    UFG::CopSystem::FindClosestVehicleCopForAudio(v3, &outClosestCop, &outDistanceToPlayer);
    if ( outDistanceToPlayer > (float)(*v22 * *v22) || outDistanceToPlayer < (float)(*v21 * *v21) )
    {
      v20 = v3->mAudioPursuitDelay + 3.0;
      goto LABEL_62;
    }
    if ( !outClosestCop )
      return;
    v26 = outClosestCop->m_Flags;
    if ( (v26 >> 14) & 1 )
    {
      v27 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)outClosestCop,
              UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      if ( (v26 & 0x8000u) != 0 )
      {
        v28 = outClosestCop->m_Components.p[30].m_pComponent;
LABEL_46:
        if ( v28 )
        {
          if ( Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v28) )
          {
            v29 = (UFG::SimObjectCharacter *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v28);
            if ( v29 )
            {
              v30 = v29->m_Flags;
              if ( (v30 >> 14) & 1 )
              {
                v31 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v29);
              }
              else if ( (v30 & 0x8000u) == 0 )
              {
                if ( (v30 >> 13) & 1 )
                  v31 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v29->vfptr,
                                                      UFG::ActorAudioComponent::_TypeUID);
                else
                  v31 = (UFG::ActorAudioComponent *)((v30 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v29->vfptr,
                                                                         UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v29->vfptr, UFG::ActorAudioComponent::_TypeUID));
              }
              else
              {
                v31 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v29->vfptr,
                                                    UFG::ActorAudioComponent::_TypeUID);
              }
              if ( v31 )
                UFG::ActorAudioComponent::QueueSpeechExternalAmbient(
                  v31,
                  play_police_bullhorn_9.mUID,
                  "police_surrender_car",
                  0i64,
                  5u,
                  0,
                  0);
            }
          }
        }
        v32 = UFG::qPropertySet::Get<float>(
                v3->mCopAudioConfig,
                (UFG::qSymbol *)&vehicle_pursuit_min_time.mUID,
                DEPTH_RECURSE);
        v33 = UFG::qPropertySet::Get<float>(
                v3->mCopAudioConfig,
                (UFG::qSymbol *)&vehicle_pursuit_max_time.mUID,
                DEPTH_RECURSE);
        v20 = UFG::RandomMinMax(*v32, *v33);
        v3->mAudioTimer = 0.0;
        goto LABEL_62;
      }
      if ( (v26 >> 13) & 1 )
      {
        v27 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)outClosestCop,
                UFG::VehicleOccupantComponent::_TypeUID);
      }
      else if ( (v26 >> 12) & 1 )
      {
        v27 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)outClosestCop,
                UFG::VehicleOccupantComponent::_TypeUID);
      }
      else
      {
        v27 = UFG::SimObject::GetComponentOfType(outClosestCop, UFG::VehicleOccupantComponent::_TypeUID);
      }
    }
    v28 = v27;
    goto LABEL_46;
  }
  if ( v10 <= v3->mAudioScannerDelay )
  {
    v12 = 1;
    v13 = 0;
    goto LABEL_24;
  }
  UFG::PoliceScannerAudio::PlayScenario(&UFG::PoliceScannerAudio::sm_Instance, "Ambient_Chatter");
  v14 = UFG::qPropertySet::Get<float>(v3->mCopAudioConfig, (UFG::qSymbol *)&scanner_min_time.mUID, DEPTH_RECURSE);
  v15 = UFG::qPropertySet::Get<float>(v3->mCopAudioConfig, (UFG::qSymbol *)&scanner_max_time.mUID, DEPTH_RECURSE);
  v16 = *v14;
  if ( *v14 >= *v15 )
    v16 = *v15;
  v3->mAudioScannerDelay = UFG::qRandom(*v15 - v16, &UFG::qDefaultSeed) + v16;
  v3->mAudioTimer = 0.0;
}

