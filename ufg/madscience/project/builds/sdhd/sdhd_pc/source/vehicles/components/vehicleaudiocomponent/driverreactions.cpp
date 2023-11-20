// File Line: 178
// RVA: 0x69BF90
void __fastcall UFG::DriverReactions::YellReactionBase(UFG::DriverReactions *this, UFG::DriverReactions::eVocalDriverReactionType reaction)
{
  UFG::DriverReactions::eVocalDriverReactionType v2; // edi
  UFG::SimObject *v3; // rax
  UFG::ActorAudioComponent *v4; // rbx
  UFG::SimComponent *v5; // rcx
  UFG::SimObjectCharacter *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::ActorAudioComponent *v8; // rax
  float v9; // xmm0_4
  const char *v10; // r8

  v2 = reaction;
  if ( this->m_pVehAudComponent->m_eDriverType != 5 )
  {
    v3 = this->m_pVehAudComponent->m_pSimObject;
    v4 = 0i64;
    if ( v3 )
      v5 = v3->m_Components.p[30].m_pComponent;
    else
      v5 = 0i64;
    v6 = (UFG::SimObjectCharacter *)v5[1].m_pSimObject;
    if ( v6 )
    {
      v7 = v6->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v6);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v6->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v6->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
        else
        {
          v8 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v6->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
      }
      else
      {
        v8 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v6->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      v4 = v8;
    }
    v9 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
    if ( v4 && v9 < UFG::DriverReactions::sm_VocalReactionChance )
    {
      if ( v2 == -376596737 )
      {
        v10 = "bad_driver";
      }
      else
      {
        v10 = &customWorldMapCaption;
        if ( v2 == 1086438772 )
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
  UFG::DriverReactions *v1; // rbx

  v1 = this;
  if ( UFG::qRandom(1.0, &UFG::qDefaultSeed) < UFG::DriverReactions::sm_CarAlarmChance
    && v1->m_pVehAudComponent->m_rateLimitedSpeed.m_targetValue < 1.0 )
  {
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v1->m_pVehAudComponent->vfptr, 0x2861EDD7u, 0i64, 0, 0i64);
  }
}

// File Line: 214
// RVA: 0x683F00
void __fastcall UFG::DriverReactions::OnCollision(UFG::DriverReactions *this)
{
  UFG::DriverReactions *v1; // rbx

  v1 = this;
  if ( this->m_pVehAudComponent->m_eDriverType == -1 )
  {
    UFG::DriverReactions::PlayCarAlarm(this);
  }
  else if ( UFG::qRandom(1.0, &UFG::qDefaultSeed) < 0.5 )
  {
    UFG::DriverReactions::YellReactionBase(v1, eVocalDriverReactionType_BadDriver);
  }
}

// File Line: 318
// RVA: 0x683F60
void __fastcall UFG::PassengerReactions::OnCollision(UFG::PassengerReactions *this, unsigned int collisionMaterial)
{
  unsigned int v2; // ebx
  UFG::PassengerReactions *v3; // rdi
  unsigned int v4; // eax
  UFG::PassengerReactions::eVocalPassengerReactionType v5; // edx

  v2 = collisionMaterial;
  v3 = this;
  v4 = _S19_5;
  if ( !(_S19_5 & 1) )
  {
    _S19_5 |= 1u;
    UFG::qWiseSymbol::create_from_string(&object_car, "object_car");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__object_car__);
    v4 = _S19_5;
  }
  if ( !(v4 & 2) )
  {
    _S19_5 = v4 | 2;
    UFG::qWiseSymbol::create_from_string(&object_bike, "object_bike");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__object_bike__);
    v4 = _S19_5;
  }
  if ( !(v4 & 4) )
  {
    _S19_5 = v4 | 4;
    UFG::qWiseSymbol::create_from_string(&body_limb, "body_limb");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__body_limb__);
    v4 = _S19_5;
  }
  if ( !(v4 & 8) )
  {
    _S19_5 = v4 | 8;
    UFG::qWiseSymbol::create_from_string(&body_whole_body, "body_whole_body");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__body_whole_body__);
    v4 = _S19_5;
  }
  if ( !(v4 & 0x10) )
  {
    _S19_5 = v4 | 0x10;
    UFG::qWiseSymbol::create_from_string(&body_torso, "body_torso");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__body_torso__);
    v4 = _S19_5;
  }
  if ( !(v4 & 0x20) )
  {
    _S19_5 = v4 | 0x20;
    UFG::qWiseSymbol::create_from_string(&body_head, "body_head");
    atexit(UFG::PassengerReactions::OnCollision_::_2_::_dynamic_atexit_destructor_for__body_head__);
  }
  if ( v2 == body_whole_body.mUID || v2 == body_limb.mUID || v2 == body_head.mUID || v2 == body_torso.mUID )
  {
    v5 = 0x99BBBCDB;
    goto LABEL_21;
  }
  if ( v2 == object_car.mUID || v2 == object_bike.mUID )
  {
    v5 = 0xDAB74339;
LABEL_21:
    UFG::PassengerReactions::ReactionBase(v3, v5);
  }
}

// File Line: 355
// RVA: 0x688680
void __fastcall UFG::PassengerReactions::ReactionBase(UFG::PassengerReactions *this, UFG::PassengerReactions::eVocalPassengerReactionType reaction)
{
  UFG::PassengerReactions *v2; // r12
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // r13
  signed __int64 v5; // rsi
  unsigned int v6; // er14
  signed __int64 v7; // rax
  unsigned int v8; // er15
  unsigned int v9; // ebp
  float v10; // xmm7_4
  int v11; // ecx
  signed __int64 v12; // rbx
  signed __int64 i; // rax
  int j; // eax
  UFG::SimObjectCharacter *v15; // rdi
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rax
  bool v18; // zf
  UFG::SimObjectGame *v19; // rcx
  unsigned __int16 v20; // cx
  UFG::ActorAudioComponent *v21; // rax
  UFG::ActorAudioComponent *v22; // rbx
  UFG::SimObjectCVBase *v23; // rcx
  unsigned __int16 v24; // dx
  UFG::SimObjectCharacterPropertiesComponent *v25; // rax
  char v26; // al
  float v27; // xmm6_4
  char *v28; // rax
  UFG::PassengerReactions::eVocalPassengerReactionType reactiona; // [rsp+B8h] [rbp+10h]

  reactiona = reaction;
  v2 = this;
  if ( this->m_pVehAudComponent->m_eDriverType != 5 )
  {
    v3 = this->m_pVehAudComponent->m_pSimObject;
    if ( v3 )
      v4 = v3->m_Components.p[30].m_pComponent;
    else
      v4 = 0i64;
    v5 = (signed __int64)&v4->m_BoundComponentHandles;
    v6 = 0;
    v7 = (signed __int64)&v4[1].m_BoundComponentHandles.mNode.mNext[-4];
    if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v7 != &v4->m_BoundComponentHandles )
    {
      do
      {
        ++v6;
        v7 = *(_QWORD *)(v7 + 72) - 64i64;
      }
      while ( v7 != v5 );
    }
    v8 = 0;
    v9 = 0;
    if ( v6 )
    {
      do
      {
        v10 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
        if ( v8 < UFG::PassengerReactions::sm_maxNumPassengerReactions )
        {
          v11 = 0;
          v12 = (signed __int64)&v4[1].m_BoundComponentHandles.mNode.mNext[-4];
          for ( i = v12; i != v5; i = *(_QWORD *)(i + 72) - 64i64 )
            ++v11;
          if ( (signed int)v9 < v11 )
          {
            for ( j = v9; j > 0; v12 = *(_QWORD *)(v12 + 72) - 64i64 )
            {
              if ( v12 == v5 )
                break;
              --j;
            }
            if ( !UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)v12) )
            {
              v15 = *(UFG::SimObjectCharacter **)(v12 + 40);
              if ( v15 )
              {
                v16 = v15->m_Flags;
                if ( (v16 >> 14) & 1 )
                {
                  v17 = v15->m_Components.p[44].m_pComponent;
                }
                else if ( (v16 & 0x8000u) == 0 )
                {
                  if ( (v16 >> 13) & 1 )
                  {
                    v17 = UFG::SimObjectGame::GetComponentOfTypeHK(
                            *(UFG::SimObjectGame **)(v12 + 40),
                            UFG::CharacterOccupantComponent::_TypeUID);
                  }
                  else
                  {
                    v18 = ((v16 >> 12) & 1) == 0;
                    v19 = *(UFG::SimObjectGame **)(v12 + 40);
                    v17 = v18 ? UFG::SimObject::GetComponentOfType(
                                  (UFG::SimObject *)&v19->vfptr,
                                  UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                 v19,
                                                                                 UFG::CharacterOccupantComponent::_TypeUID);
                  }
                }
                else
                {
                  v17 = UFG::SimObjectGame::GetComponentOfTypeHK(
                          *(UFG::SimObjectGame **)(v12 + 40),
                          UFG::CharacterOccupantComponent::_TypeUID);
                }
                if ( v17 && LODWORD(v17[1].m_SafePointerList.mNode.mNext) != 13 )
                {
                  v20 = v15->m_Flags;
                  ++v8;
                  if ( (v20 >> 14) & 1 )
                  {
                    v21 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v15);
                  }
                  else if ( (v20 & 0x8000u) == 0 )
                  {
                    if ( (v20 >> 13) & 1 )
                      v21 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v15->vfptr,
                                                          UFG::ActorAudioComponent::_TypeUID);
                    else
                      v21 = (UFG::ActorAudioComponent *)((v20 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v15->vfptr,
                                                                             UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::ActorAudioComponent::_TypeUID));
                  }
                  else
                  {
                    v21 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v15->vfptr,
                                                        UFG::ActorAudioComponent::_TypeUID);
                  }
                  v22 = v21;
                  if ( v21 )
                  {
                    v23 = (UFG::SimObjectCVBase *)v21->m_pSimObject;
                    if ( !v23
                      || ((v24 = v23->m_Flags, !((v24 >> 14) & 1)) ? ((v24 & 0x8000u) == 0 ? (!((v24 >> 13) & 1) ? (!((v24 >> 12) & 1) ? (v25 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v23->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID)) : (v25 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v23->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v25 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v23->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v25 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v23))) : (v25 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v23)),
                          !v25 || !(*((_BYTE *)v25 + 248) & 1)) )
                    {
                      v26 = *((_BYTE *)v22 + 552);
                      if ( v26 & 2 || v26 & 1 )
                      {
                        UFG::ConversationManager::InterruptConversationsWithCharacter(
                          (UFG::SimObject *)&v15->vfptr,
                          eInterruptType_Collision,
                          1,
                          0i64);
                      }
                      else if ( v26 & 0x10 )
                      {
                        v27 = UFG::Metrics::msInstance.mSimTime_Temp;
                        if ( v10 < UFG::PassengerReactions::sm_passengerReactionChance
                          && (float)(UFG::Metrics::msInstance.mSimTime_Temp - sLastReactionTime) > 15.0 )
                        {
                          v28 = UFG::PassengerReactions::GetContextStringForReaction(v2, reactiona);
                          if ( (v22->m_isSpeakingCnt <= 0 || !v22->m_controller.m_pEvent)
                            && !UFG::ActorAudioComponent::QueueSpeechExternalAmbient(
                                  v22,
                                  play_driving_27.mUID,
                                  v28,
                                  0i64,
                                  5u,
                                  0,
                                  0) )
                          {
                            UFG::ActorAudioComponent::PlayPanic(v22);
                          }
                          sLastReactionTime = v27;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        ++v9;
      }
      while ( v9 < v6 );
    }
  }
}

// File Line: 431
// RVA: 0x67A200
char *__fastcall UFG::PassengerReactions::GetContextStringForReaction(UFG::PassengerReactions *this, UFG::PassengerReactions::eVocalPassengerReactionType reaction)
{
  char *result; // rax

  if ( reaction == -1715749669 || (result = &customWorldMapCaption, reaction == -625523911) )
    result = "passenger_reaction";
  return result;
}

