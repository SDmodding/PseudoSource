// File Line: 178
// RVA: 0x69BF90
void __fastcall UFG::DriverReactions::YellReactionBase(
        UFG::DriverReactions *this,
        UFG::DriverReactions::eVocalDriverReactionType reaction)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::ActorAudioComponent *v4; // rbx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimObjectCharacter *v6; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  float v9; // xmm0_4
  const char *v10; // r8

  if ( this->m_pVehAudComponent->m_eDriverType != eDriverType_Cop )
  {
    m_pSimObject = this->m_pVehAudComponent->m_pSimObject;
    v4 = 0i64;
    if ( m_pSimObject )
      m_pComponent = m_pSimObject->m_Components.p[30].m_pComponent;
    else
      m_pComponent = 0i64;
    v6 = (UFG::SimObjectCharacter *)m_pComponent[1].m_pSimObject;
    if ( v6 )
    {
      m_Flags = v6->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v6);
      }
      else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v6,
                                                          UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                          v6,
                                                          UFG::ActorAudioComponent::_TypeUID);
      }
      v4 = ComponentOfTypeHK;
    }
    v9 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
    if ( v4 && v9 < UFG::DriverReactions::sm_VocalReactionChance )
    {
      if ( reaction == eVocalDriverReactionType_BadDriver )
      {
        v10 = "bad_driver";
      }
      else
      {
        v10 = &customCaption;
        if ( reaction == eVocalDriverReactionType_TrafficJam )
          v10 = "traffic_jam";
      }
      if ( v4->m_isSpeakingCnt <= 0 || !v4->m_controller.m_pEvent )
        UFG::ActorAudioComponent::QueueSpeechExternalAmbient(v4, play_driver_reaction_27.mUID, v10, 0i64, 5u, 0, 0);
    }
  }
}

// File Line: 206
// RVA: 0x686CB0
void __fastcall UFG::DriverReactions::PlayCarAlarm(UFG::DriverReactions *this)
{
  if ( UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) < UFG::DriverReactions::sm_CarAlarmChance
    && this->m_pVehAudComponent->m_rateLimitedSpeed.m_targetValue < 1.0 )
  {
    UFG::AudioEntity::CreateAndPlayEvent(&this->m_pVehAudComponent->UFG::AudioEntity, 0x2861EDD7u, 0i64, 0, 0i64);
  }
}

// File Line: 214
// RVA: 0x683F00
void __fastcall UFG::DriverReactions::OnCollision(UFG::DriverReactions *this)
{
  if ( this->m_pVehAudComponent->m_eDriverType == eDriverType_Uninitialized )
  {
    UFG::DriverReactions::PlayCarAlarm(this);
  }
  else if ( UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) < 0.5 )
  {
    UFG::DriverReactions::YellReactionBase(this, eVocalDriverReactionType_BadDriver);
  }
}

// File Line: 318
// RVA: 0x683F60
void __fastcall UFG::PassengerReactions::OnCollision(UFG::PassengerReactions *this, unsigned int collisionMaterial)
{
  unsigned int v4; // eax
  UFG::PassengerReactions::eVocalPassengerReactionType v5; // edx

  v4 = _S19_5;
  if ( (_S19_5 & 1) == 0 )
  {
    _S19_5 |= 1u;
    UFG::qWiseSymbol::create_from_string(&object_car, "object_car");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__object_car__);
    v4 = _S19_5;
  }
  if ( (v4 & 2) == 0 )
  {
    _S19_5 = v4 | 2;
    UFG::qWiseSymbol::create_from_string(&object_bike, "object_bike");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__object_bike__);
    v4 = _S19_5;
  }
  if ( (v4 & 4) == 0 )
  {
    _S19_5 = v4 | 4;
    UFG::qWiseSymbol::create_from_string(&body_limb, "body_limb");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__body_limb__);
    v4 = _S19_5;
  }
  if ( (v4 & 8) == 0 )
  {
    _S19_5 = v4 | 8;
    UFG::qWiseSymbol::create_from_string(&body_whole_body, "body_whole_body");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__body_whole_body__);
    v4 = _S19_5;
  }
  if ( (v4 & 0x10) == 0 )
  {
    _S19_5 = v4 | 0x10;
    UFG::qWiseSymbol::create_from_string(&body_torso, "body_torso");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__body_torso__);
    v4 = _S19_5;
  }
  if ( (v4 & 0x20) == 0 )
  {
    _S19_5 = v4 | 0x20;
    UFG::qWiseSymbol::create_from_string(&body_head, "body_head");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__body_head__);
  }
  if ( collisionMaterial == body_whole_body.mUID
    || collisionMaterial == body_limb.mUID
    || collisionMaterial == body_head.mUID
    || collisionMaterial == body_torso.mUID )
  {
    v5 = 0x99BBBCDB;
    goto LABEL_21;
  }
  if ( collisionMaterial == object_car.mUID || collisionMaterial == object_bike.mUID )
  {
    v5 = 0xDAB74339;
LABEL_21:
    UFG::PassengerReactions::ReactionBase(this, v5);
  }
}

// File Line: 355
// RVA: 0x688680
void __fastcall UFG::PassengerReactions::ReactionBase(
        UFG::PassengerReactions *this,
        UFG::PassengerReactions::eVocalPassengerReactionType reaction)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimComponent *m_pComponent; // r13
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rsi
  unsigned int v6; // r14d
  __int64 v7; // rax
  unsigned int v8; // r15d
  int i; // ebp
  float v10; // xmm7_4
  int v11; // ecx
  __int64 v12; // rbx
  __int64 j; // rax
  int k; // eax
  UFG::SimObjectCharacter *v15; // rdi
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v18; // zf
  UFG::SimObjectGame *v19; // rcx
  __int16 v20; // cx
  UFG::ActorAudioComponent *v21; // rax
  UFG::ActorAudioComponent *v22; // rbx
  UFG::SimObjectCVBase *v23; // rcx
  __int16 v24; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfType; // rax
  char v26; // al
  float mSimTime_Temp; // xmm6_4
  char *ContextStringForReaction; // rax

  if ( this->m_pVehAudComponent->m_eDriverType != eDriverType_Cop )
  {
    m_pSimObject = this->m_pVehAudComponent->m_pSimObject;
    if ( m_pSimObject )
      m_pComponent = m_pSimObject->m_Components.p[30].m_pComponent;
    else
      m_pComponent = 0i64;
    p_m_BoundComponentHandles = &m_pComponent->m_BoundComponentHandles;
    v6 = 0;
    v7 = (__int64)&m_pComponent[1].m_BoundComponentHandles.mNode.mNext[-4];
    if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v7 != &m_pComponent->m_BoundComponentHandles )
    {
      do
      {
        ++v6;
        v7 = *(_QWORD *)(v7 + 72) - 64i64;
      }
      while ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v7 != p_m_BoundComponentHandles );
    }
    v8 = 0;
    for ( i = 0; i < v6; ++i )
    {
      v10 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
      if ( v8 < UFG::PassengerReactions::sm_maxNumPassengerReactions )
      {
        v11 = 0;
        v12 = (__int64)&m_pComponent[1].m_BoundComponentHandles.mNode.mNext[-4];
        for ( j = v12;
              (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)j != p_m_BoundComponentHandles;
              j = *(_QWORD *)(j + 72) - 64i64 )
        {
          ++v11;
        }
        if ( i < v11 )
        {
          for ( k = i; k > 0; v12 = *(_QWORD *)(v12 + 72) - 64i64 )
          {
            if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v12 == p_m_BoundComponentHandles )
              break;
            --k;
          }
          if ( !UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)v12) )
          {
            v15 = *(UFG::SimObjectCharacter **)(v12 + 40);
            if ( v15 )
            {
              m_Flags = v15->m_Flags;
              if ( (m_Flags & 0x4000) != 0 )
              {
                ComponentOfTypeHK = v15->m_Components.p[44].m_pComponent;
              }
              else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
              {
                ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      *(UFG::SimObjectGame **)(v12 + 40),
                                      UFG::CharacterOccupantComponent::_TypeUID);
              }
              else
              {
                v18 = (m_Flags & 0x1000) == 0;
                v19 = *(UFG::SimObjectGame **)(v12 + 40);
                ComponentOfTypeHK = v18
                                  ? UFG::SimObject::GetComponentOfType(v19, UFG::CharacterOccupantComponent::_TypeUID)
                                  : UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v19,
                                      UFG::CharacterOccupantComponent::_TypeUID);
              }
              if ( ComponentOfTypeHK && LODWORD(ComponentOfTypeHK[1].m_SafePointerList.mNode.mNext) != 13 )
              {
                v20 = v15->m_Flags;
                ++v8;
                if ( (v20 & 0x4000) != 0 )
                  v21 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v15);
                else
                  v21 = (UFG::ActorAudioComponent *)(v20 < 0 || (v20 & 0x2000) != 0 || (v20 & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v15,
                                                       UFG::ActorAudioComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       v15,
                                                       UFG::ActorAudioComponent::_TypeUID));
                v22 = v21;
                if ( v21 )
                {
                  v23 = (UFG::SimObjectCVBase *)v21->m_pSimObject;
                  if ( !v23
                    || ((v24 = v23->m_Flags, (v24 & 0x4000) != 0) || v24 < 0
                      ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v23))
                      : (v24 & 0x2000) != 0 || (v24 & 0x1000) != 0
                      ? (ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                           v23,
                                                                                           UFG::SimObjectCharacterPropertiesComponent::_TypeUID))
                      : (ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                                           v23,
                                                                                           UFG::SimObjectCharacterPropertiesComponent::_TypeUID)),
                        !ComponentOfType || (*((_BYTE *)ComponentOfType + 248) & 1) == 0) )
                  {
                    v26 = *((_BYTE *)v22 + 552);
                    if ( (v26 & 2) != 0 || (v26 & 1) != 0 )
                    {
                      UFG::ConversationManager::InterruptConversationsWithCharacter(
                        v15,
                        eInterruptType_Collision,
                        1,
                        0i64);
                    }
                    else if ( (v26 & 0x10) != 0 )
                    {
                      mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
                      if ( v10 < UFG::PassengerReactions::sm_passengerReactionChance
                        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - sLastReactionTime) > 15.0 )
                      {
                        ContextStringForReaction = UFG::PassengerReactions::GetContextStringForReaction(this, reaction);
                        if ( (v22->m_isSpeakingCnt <= 0 || !v22->m_controller.m_pEvent)
                          && !UFG::ActorAudioComponent::QueueSpeechExternalAmbient(
                                v22,
                                play_driving_27.mUID,
                                ContextStringForReaction,
                                0i64,
                                5u,
                                0,
                                0) )
                        {
                          UFG::ActorAudioComponent::PlayPanic(v22);
                        }
                        sLastReactionTime = mSimTime_Temp;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 431
// RVA: 0x67A200
char *__fastcall UFG::PassengerReactions::GetContextStringForReaction(
        UFG::PassengerReactions *this,
        UFG::PassengerReactions::eVocalPassengerReactionType reaction)
{
  char *result; // rax

  if ( reaction == eVocalPassengerReactionType_DriveHitPed )
    return "passenger_reaction";
  result = &customCaption;
  if ( reaction == eVocalPassengerReactionType_DriveCrazy )
    return "passenger_reaction";
  return result;
}

