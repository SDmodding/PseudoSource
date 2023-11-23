// File Line: 69
// RVA: 0x1559A90
__int64 dynamic_initializer_for__damage_intensity__()
{
  UFG::qWiseSymbol::create_from_string(&damage_intensity_0, "damage_intensity");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__damage_intensity__);
}

// File Line: 70
// RVA: 0x155A1C0
__int64 dynamic_initializer_for__medium__()
{
  UFG::qWiseSymbol::create_from_string(&medium_0, "medium");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__medium__);
}

// File Line: 90
// RVA: 0x59F3F0
void __fastcall UFG::HandleSubtitleEnd(unsigned int *subtitle)
{
  UFG::UIHKTextOverlay *Instance; // rax
  UFG::UIHKTextOverlay *v3; // rax
  UFG::UIHKTextOverlay *v4; // rax

  Instance = UFG::UIHKTextOverlay::getInstance();
  if ( UFG::UIHKTextOverlay::GetSubtitleAge(Instance, subtitle[1]) >= UFG::ActorAudioComponent::sm_minSubtitleLifetime )
  {
    v4 = UFG::UIHKTextOverlay::getInstance();
    UFG::UIHKTextOverlay::KillSubtitles(v4, subtitle[1]);
  }
  else
  {
    v3 = UFG::UIHKTextOverlay::getInstance();
    UFG::UIHKTextOverlay::ChangeSubtitleLifetime(v3, subtitle[1], UFG::ActorAudioComponent::sm_minSubtitleLifetime);
  }
  *(_QWORD *)subtitle = 0i64;
}

// File Line: 118
// RVA: 0x59B450
void __fastcall UFG::SubtitleCallback::Do(
        UFG::SubtitleCallback *this,
        UFG::AudioEvent *audioEvent,
        UFG::eAudioEventCallbackType type)
{
  unsigned int v4; // ebx
  unsigned int v5; // eax
  unsigned int v6; // ebx
  unsigned int v7; // eax
  unsigned int m_labelHash; // ebx
  unsigned int v9; // eax
  unsigned int v10; // eax

  if ( type == eAudioEventCallbackType_Marker )
  {
    if ( UFG::SubtitleCallback::mSubtitle1[0] )
    {
      if ( UFG::SubtitleCallback::mSubtitle2[0] )
      {
        UFG::HandleSubtitleEnd(UFG::SubtitleCallback::mSubtitle1);
        m_labelHash = audioEvent->m_markerCallbackInfo.m_labelHash;
        v9 = UFG::ActorAudioComponent::LookupAndShowSubtitleFromPropertySet(m_labelHash);
        if ( !UFG::SubtitleCallback::mSubtitle1[0] && v9 )
        {
          UFG::SubtitleCallback::mSubtitle1[0] = m_labelHash;
          dword_14242E4E4 = v9;
        }
      }
      else
      {
        v6 = audioEvent->m_markerCallbackInfo.m_labelHash;
        v7 = UFG::ActorAudioComponent::LookupAndShowSubtitleFromPropertySet(v6);
        if ( !UFG::SubtitleCallback::mSubtitle2[0] && v7 )
        {
          UFG::SubtitleCallback::mSubtitle2[0] = v6;
          dword_14242E4EC = v7;
        }
      }
    }
    else
    {
      v4 = audioEvent->m_markerCallbackInfo.m_labelHash;
      v5 = UFG::ActorAudioComponent::LookupAndShowSubtitleFromPropertySet(v4);
      if ( !UFG::SubtitleCallback::mSubtitle1[0] )
      {
        if ( v5 )
        {
          UFG::SubtitleCallback::mSubtitle1[0] = v4;
          dword_14242E4E4 = v5;
        }
      }
    }
  }
  else if ( type == eAudioEventCallbackType_End )
  {
    v10 = audioEvent->m_markerCallbackInfo.m_labelHash;
    if ( UFG::SubtitleCallback::mSubtitle1[0] == v10 )
    {
      UFG::HandleSubtitleEnd(UFG::SubtitleCallback::mSubtitle1);
    }
    else if ( UFG::SubtitleCallback::mSubtitle2[0] == v10 )
    {
      UFG::HandleSubtitleEnd(UFG::SubtitleCallback::mSubtitle2);
    }
  }
}

// File Line: 155
// RVA: 0x59B140
void __fastcall UFG::AACSubtitleCallback::Do(
        UFG::AACSubtitleCallback *this,
        UFG::AudioEvent *audioEvent,
        UFG::eAudioEventCallbackType type)
{
  UFG::AudioEntity *m_pEntity; // rdi
  unsigned int *p_m_regionCheckFrame; // rdi
  unsigned int v5; // ebx
  UFG::UIHKTextOverlay *Instance; // rax
  float SubtitleAge; // xmm0_4
  unsigned int v8; // ebx
  UFG::UIHKTextOverlay *v9; // rax
  UFG::UIHKTextOverlay *v10; // rax

  m_pEntity = audioEvent->m_pEntity;
  if ( m_pEntity )
  {
    p_m_regionCheckFrame = &m_pEntity[-1].m_regionCheckFrame;
    if ( p_m_regionCheckFrame )
    {
      if ( type == eAudioEventCallbackType_Marker )
      {
        p_m_regionCheckFrame[110] = UFG::ActorAudioComponent::LookupAndShowSubtitleFromPropertySet(audioEvent->m_markerCallbackInfo.m_labelHash);
      }
      else if ( type == eAudioEventCallbackType_End )
      {
        v5 = p_m_regionCheckFrame[110];
        Instance = UFG::UIHKTextOverlay::getInstance();
        SubtitleAge = UFG::UIHKTextOverlay::GetSubtitleAge(Instance, v5);
        v8 = p_m_regionCheckFrame[110];
        if ( SubtitleAge >= UFG::ActorAudioComponent::sm_minSubtitleLifetime )
        {
          v10 = UFG::UIHKTextOverlay::getInstance();
          UFG::UIHKTextOverlay::KillSubtitles(v10, v8);
        }
        else
        {
          v9 = UFG::UIHKTextOverlay::getInstance();
          UFG::UIHKTextOverlay::ChangeSubtitleLifetime(v9, v8, UFG::ActorAudioComponent::sm_minSubtitleLifetime);
        }
      }
    }
  }
}

// File Line: 203
// RVA: 0x59B290
void __fastcall UFG::SpeechControlCallback::Do(
        UFG::SpeechControlCallback *this,
        UFG::AudioEvent *audioEvent,
        UFG::eAudioEventCallbackType type)
{
  UFG::AudioEntity *m_pEntity; // rcx
  unsigned int *p_m_regionCheckFrame; // rcx
  UFG::SimObjectGame *v6; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float m_floatParameter; // xmm1_4
  bool v11; // sf
  unsigned int v12; // eax
  UFG::SimObjectGame *v13; // r8
  __int16 v14; // cx
  UFG::DialogueAnimationComponent *v15; // rax
  unsigned int v16; // eax

  m_pEntity = audioEvent->m_pEntity;
  if ( m_pEntity )
  {
    p_m_regionCheckFrame = &m_pEntity[-1].m_regionCheckFrame;
    if ( p_m_regionCheckFrame )
    {
      if ( type == eAudioEventCallbackType_Marker )
      {
        v6 = (UFG::SimObjectGame *)*((_QWORD *)p_m_regionCheckFrame + 5);
        if ( v6 )
        {
          m_Flags = v6->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = v6->m_Components.p[41].m_pComponent;
          }
          else
          {
            if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v6,
                                    UFG::DialogueAnimationComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v6, UFG::DialogueAnimationComponent::_TypeUID);
            m_pComponent = ComponentOfTypeHK;
          }
          if ( m_pComponent && audioEvent->m_markerCallbackInfo.m_labelHash )
          {
            m_floatParameter = audioEvent->m_markerCallbackInfo.m_floatParameter;
            if ( m_floatParameter > 0.0 )
            {
              *(float *)&m_pComponent[1].m_NameUID = m_floatParameter;
              m_pComponent[1].m_TypeUID = audioEvent->m_markerCallbackInfo.m_labelHash;
            }
          }
        }
      }
      else if ( type == eAudioEventCallbackType_End )
      {
        v11 = (--p_m_regionCheckFrame[111] & 0x80000000) != 0;
        v12 = p_m_regionCheckFrame[111];
        v13 = (UFG::SimObjectGame *)*((_QWORD *)p_m_regionCheckFrame + 5);
        if ( v11 )
          v12 = 0;
        p_m_regionCheckFrame[111] = v12;
        if ( v13 )
        {
          v14 = v13->m_Flags;
          if ( (v14 & 0x4000) != 0 )
            v15 = (UFG::DialogueAnimationComponent *)v13->m_Components.p[41].m_pComponent;
          else
            v15 = (UFG::DialogueAnimationComponent *)(v14 < 0 || (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0
                                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v13,
                                                        UFG::DialogueAnimationComponent::_TypeUID)
                                                    : UFG::SimObject::GetComponentOfType(
                                                        v13,
                                                        UFG::DialogueAnimationComponent::_TypeUID));
          if ( v15 )
            UFG::DialogueAnimationComponent::Stop(v15);
        }
      }
      else if ( type )
      {
        if ( type == eAudioEventCallbackType_DetachEntity )
        {
          v11 = (--p_m_regionCheckFrame[111] & 0x80000000) != 0;
          if ( v11 )
            p_m_regionCheckFrame[111] = 0;
        }
        else
        {
          v11 = (--p_m_regionCheckFrame[111] & 0x80000000) != 0;
          v16 = p_m_regionCheckFrame[111];
          if ( v11 )
            v16 = 0;
          p_m_regionCheckFrame[111] = v16;
        }
      }
    }
  }
}

// File Line: 324
// RVA: 0x1554CD0
__int64 dynamic_initializer_for__UFG::ActorAudioComponent::sm_dlgStateManager__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ActorAudioComponent::sm_dlgStateManager__);
}

// File Line: 339
// RVA: 0x1554AA0
__int64 dynamic_initializer_for__UFG::ActorAudioComponent::s_ActorAudioComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ActorAudioComponent::s_ActorAudioComponentList__);
}

// File Line: 340
// RVA: 0x59D740
__int64 __fastcall UFG::qReflectInventory<UFG::Editor::PrefabWindow>::GetClassSize(
        UFG::qReflectInventory<UFG::Editor::PrefabWindow> *this)
{
  return 560i64;
}

// File Line: 351
// RVA: 0x592920
void __fastcall UFG::ActorAudioComponent::ActorAudioComponent(
        UFG::ActorAudioComponent *this,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *mPrev; // rax
  UFG::SimObjectCharacter *m_pSimObject; // rbx
  unsigned int v5; // eax

  UFG::SimComponent::SimComponent(this, pSceneObj->m_NameUID);
  UFG::AudioEntity::AudioEntity(&this->UFG::AudioEntity);
  this->UFG::HkAudioEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HkAudioEntityComponent::UFG::AudioEntity::vfptr = (UFG::AudioEntityVtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::AudioEntity};
  UFG::SimComponent::AddType(
    this,
    UFG::HkAudioEntityComponent::_HkAudioEntityComponentTypeUID,
    "HkAudioEntityComponent");
  this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>::mPrev = &this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>;
  this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>::mNext = &this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>;
  this->UFG::HkAudioEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActorAudioComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HkAudioEntityComponent::UFG::AudioEntity::vfptr = (UFG::AudioEntityVtbl *)&UFG::ActorAudioComponent::`vftable{for `UFG::AudioEntity};
  this->m_controller.m_pEvent = 0i64;
  this->m_SFXEntity = 0i64;
  this->m_activeAmbientConversationId = 0;
  this->m_leftFootstep.m_pOneShot = 0i64;
  this->m_rightFootstep.m_pOneShot = 0i64;
  this->m_ambientContexts.m_nodes.p = 0i64;
  *(_QWORD *)&this->m_ambientContexts.m_nodes.size = 0i64;
  UFG::qArray<UFG::AmbientContextNode,0>::Reallocate(
    &this->m_ambientContexts.m_nodes,
    2u,
    "qArray.Reallocate(Constructor)");
  this->m_ambientContexts.m_nodes.size = 2;
  this->m_healthComponent.mPrev = &this->m_healthComponent;
  this->m_healthComponent.mNext = &this->m_healthComponent;
  this->m_healthComponent.m_pPointer = 0i64;
  this->m_transformNodeComponent.mPrev = &this->m_transformNodeComponent;
  this->m_transformNodeComponent.mNext = &this->m_transformNodeComponent;
  this->m_transformNodeComponent.m_pPointer = 0i64;
  this->m_simObjectCharacterPropertiesComponent.mPrev = &this->m_simObjectCharacterPropertiesComponent;
  this->m_simObjectCharacterPropertiesComponent.mNext = &this->m_simObjectCharacterPropertiesComponent;
  this->m_simObjectCharacterPropertiesComponent.m_pPointer = 0i64;
  mPrev = UFG::ActorAudioComponent::s_ActorAudioComponentList.mNode.mPrev;
  UFG::ActorAudioComponent::s_ActorAudioComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>;
  this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>::mNext = (UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *)&UFG::ActorAudioComponent::s_ActorAudioComponentList;
  UFG::ActorAudioComponent::s_ActorAudioComponentList.mNode.mPrev = &this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>;
  UFG::SimComponent::AddType(this, UFG::ActorAudioComponent::_ActorAudioComponentTypeUID, "ActorAudioComponent");
  UFG::ActorAudioComponent::ClearDataMembers(this);
  m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
  if ( m_pSimObject == UFG::GetLocalPlayer() )
    *((_BYTE *)this + 0x229) |= 8u;
  if ( !UFG::ActorAudioComponent::sm_copConfigPs )
  {
    if ( (_S16_4 & 1) == 0 )
    {
      _S16_4 |= 1u;
      v5 = UFG::qStringHash32("audio-copaudiocomponent", 0xFFFFFFFF);
      UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&copAudioComponentPsName, v5);
      atexit(UFG::ActorAudioComponent::ActorAudioComponent_::_5_::_dynamic_atexit_destructor_for__copAudioComponentPsName__);
    }
    UFG::ActorAudioComponent::sm_copConfigPs = UFG::PropertySetManager::CreateOrFindPropertySet(&copAudioComponentPsName);
  }
}

// File Line: 382
// RVA: 0x593A70
void __fastcall UFG::ActorAudioComponent::~ActorAudioComponent(UFG::ActorAudioComponent *this)
{
  UFG::AudioEntity *m_SFXEntity; // rcx
  UFG::AudioEntity *v3; // rcx
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *v4; // rdi
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *mPrev; // rcx
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *p_m_simObjectCharacterPropertiesComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_transformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent> *p_m_healthComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::AudioEvent *m_pEvent; // rcx
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *v23; // rdx
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *v24; // rax

  this->UFG::HkAudioEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActorAudioComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HkAudioEntityComponent::UFG::AudioEntity::vfptr = (UFG::AudioEntityVtbl *)&UFG::ActorAudioComponent::`vftable{for `UFG::AudioEntity};
  UFG::ActorAudioComponent::ClearDataMembers(this);
  m_SFXEntity = this->m_SFXEntity;
  if ( m_SFXEntity )
  {
    UFG::AudioEntity::Shutdown(m_SFXEntity);
    v3 = this->m_SFXEntity;
    if ( v3 )
      v3->vfptr->__vecDelDtor(v3, 1u);
    this->m_SFXEntity = 0i64;
  }
  if ( this == UFG::ActorAudioComponent::s_ActorAudioComponentpCurrentIterator )
    UFG::ActorAudioComponent::s_ActorAudioComponentpCurrentIterator = (UFG::ActorAudioComponent *)&this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>::mPrev[-24];
  v4 = &this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>;
  mPrev = this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>::mPrev;
  mNext = this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>::mPrev = &this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>;
  this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>::mNext = &this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>;
  p_m_simObjectCharacterPropertiesComponent = &this->m_simObjectCharacterPropertiesComponent;
  if ( this->m_simObjectCharacterPropertiesComponent.m_pPointer )
  {
    v8 = p_m_simObjectCharacterPropertiesComponent->mPrev;
    v9 = this->m_simObjectCharacterPropertiesComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_simObjectCharacterPropertiesComponent->mPrev = p_m_simObjectCharacterPropertiesComponent;
    this->m_simObjectCharacterPropertiesComponent.mNext = &this->m_simObjectCharacterPropertiesComponent;
  }
  this->m_simObjectCharacterPropertiesComponent.m_pPointer = 0i64;
  v10 = p_m_simObjectCharacterPropertiesComponent->mPrev;
  v11 = this->m_simObjectCharacterPropertiesComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_simObjectCharacterPropertiesComponent->mPrev = p_m_simObjectCharacterPropertiesComponent;
  this->m_simObjectCharacterPropertiesComponent.mNext = &this->m_simObjectCharacterPropertiesComponent;
  p_m_transformNodeComponent = &this->m_transformNodeComponent;
  if ( this->m_transformNodeComponent.m_pPointer )
  {
    v13 = p_m_transformNodeComponent->mPrev;
    v14 = this->m_transformNodeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_transformNodeComponent->mPrev = p_m_transformNodeComponent;
    this->m_transformNodeComponent.mNext = &this->m_transformNodeComponent;
  }
  this->m_transformNodeComponent.m_pPointer = 0i64;
  v15 = p_m_transformNodeComponent->mPrev;
  v16 = this->m_transformNodeComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_transformNodeComponent->mPrev = p_m_transformNodeComponent;
  this->m_transformNodeComponent.mNext = &this->m_transformNodeComponent;
  p_m_healthComponent = &this->m_healthComponent;
  if ( this->m_healthComponent.m_pPointer )
  {
    v18 = p_m_healthComponent->mPrev;
    v19 = this->m_healthComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_healthComponent->mPrev = p_m_healthComponent;
    this->m_healthComponent.mNext = &this->m_healthComponent;
  }
  this->m_healthComponent.m_pPointer = 0i64;
  v20 = p_m_healthComponent->mPrev;
  v21 = this->m_healthComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_m_healthComponent->mPrev = p_m_healthComponent;
  this->m_healthComponent.mNext = &this->m_healthComponent;
  UFG::AmbientContextManager::~AmbientContextManager(&this->m_ambientContexts);
  UFG::OneShotHandle::Release(&this->m_rightFootstep);
  UFG::OneShotHandle::Release(&this->m_leftFootstep);
  m_pEvent = this->m_controller.m_pEvent;
  if ( m_pEvent )
    UFG::AudioEvent::OnControllerDestroy(m_pEvent);
  v23 = v4->mPrev;
  v24 = this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>::mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  v4->mPrev = v4;
  this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>::mNext = &this->UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent>;
  this->UFG::HkAudioEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HkAudioEntityComponent::UFG::AudioEntity::vfptr = (UFG::AudioEntityVtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::AudioEntity};
  UFG::AudioEntity::~AudioEntity(&this->UFG::AudioEntity);
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 399
// RVA: 0x598A20
void __fastcall UFG::ActorAudioComponent::ClearDataMembers(UFG::ActorAudioComponent *this)
{
  unsigned int m_activeAmbientConversationId; // edx
  UFG::qBaseTreeRB *v3; // rax
  _BOOL8 v4; // rdx
  UFG::AudioEvent *m_pEvent; // rax
  unsigned int m_uPlayingId; // edi
  UFG::TiDo *Instance; // rax
  UFG::AudioEntity *m_SFXEntity; // rcx
  UFG::AudioEntity *v9; // rcx
  unsigned int v10; // edx

  m_activeAmbientConversationId = this->m_activeAmbientConversationId;
  if ( m_activeAmbientConversationId )
  {
    v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, m_activeAmbientConversationId);
    if ( v3 )
    {
      if ( v3 != (UFG::qBaseTreeRB *)8 )
        UFG::Conversation::ForceFinish((UFG::Conversation *)&v3[-1].mCount, v4);
    }
  }
  m_pEvent = this->m_controller.m_pEvent;
  this->m_activeAmbientConversationId = 0;
  if ( m_pEvent )
  {
    m_uPlayingId = m_pEvent->m_uPlayingId;
    m_pEvent->m_pController = 0i64;
    this->m_controller.m_pEvent = 0i64;
    if ( m_uPlayingId )
    {
      Instance = UFG::TiDo::GetInstance();
      UFG::TiDo::StopPlaying(Instance, m_uPlayingId);
    }
  }
  m_SFXEntity = this->m_SFXEntity;
  if ( m_SFXEntity )
  {
    UFG::AudioEntity::Shutdown(m_SFXEntity);
    v9 = this->m_SFXEntity;
    if ( v9 )
      v9->vfptr->__vecDelDtor(v9, 1u);
    this->m_SFXEntity = 0i64;
  }
  *((_BYTE *)this + 553) &= 0xC0u;
  v10 = effect_possessed_bypass;
  *((_BYTE *)this + 553) |= 0x40u;
  *((_BYTE *)this + 554) &= ~1u;
  *(_QWORD *)&this->m_curPlayingPriority = 0i64;
  *(_QWORD *)&this->m_subtitleId = 0i64;
  *((_BYTE *)this + 552) = 56;
  this->m_voiceProfile = 0i64;
  this->m_distance2ToListener = 0.0;
  UFG::AudioEntity::SetRtpcValue(&this->UFG::AudioEntity, v10, 0.94999999);
}

// File Line: 481
// RVA: 0x5AEAF0
void __fastcall UFG::ActorAudioComponent::Update(UFG::ActorAudioComponent *this, float delta_sec)
{
  UFG::SimComponent *m_pPointer; // rbx
  UFG::SimComponent *v5; // rax
  char v6; // dl
  char v7; // cl
  float v8; // xmm2_4
  UFG::SimComponent *v9; // rbx
  UFG::qVector4 v10; // xmm3
  UFG::qVector4 v11; // xmm2
  UFG::qVector4 m_BoundComponentHandles; // xmm1
  UFG::SimComponent *v13; // rbx
  UFG::AudioEntity *m_SFXEntity; // rcx
  UFG::qVector4 v15; // xmm3
  UFG::qVector4 v16; // xmm2
  UFG::qVector4 v17; // xmm1
  UFG::SimComponent *v18; // rbx
  UFG::OneShot *m_pOneShot; // rcx
  UFG::qVector4 v20; // xmm3
  UFG::qVector4 v21; // xmm2
  UFG::qVector4 v22; // xmm1
  UFG::SimComponent *v23; // rbx
  UFG::OneShot *v24; // rcx
  UFG::qVector4 v25; // xmm3
  UFG::qVector4 v26; // xmm2
  UFG::qVector4 v27; // xmm1
  bool v28; // al
  bool v29; // cl
  UFG::HealthComponent *v30; // rcx
  int m_fHealth; // esi
  unsigned __int8 IsKilled; // al
  unsigned __int8 v33; // bl
  bool v34; // cl
  float v35; // xmm1_4

  if ( UFG::AudioListener::sm_pInstance )
  {
    m_pPointer = this->m_transformNodeComponent.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
    this->m_distance2ToListener = UFG::AudioListener::GetDistance2From(
                                    UFG::AudioListener::sm_pInstance,
                                    (UFG::qVector3 *)&m_pPointer[2].m_BoundComponentHandles);
  }
  UFG::ActorAudioComponent::CheckInitialize(this);
  if ( this->m_bIsInitialized )
  {
    v5 = this->m_simObjectCharacterPropertiesComponent.m_pPointer;
    if ( v5 )
    {
      v6 = *((_BYTE *)this + 554);
      v7 = (__int64)v5[3].m_BoundComponentHandles.mNode.mNext & 1;
      if ( (v6 & 1) != v7 )
      {
        *((_BYTE *)this + 554) = v6 ^ (v7 ^ v6) & 1;
        if ( v7 )
          v8 = FLOAT_0_050000001;
        else
          v8 = FLOAT_0_94999999;
        UFG::AudioEntity::SetRtpcValue(&this->UFG::AudioEntity, effect_possessed_bypass, v8);
      }
    }
    v9 = this->m_transformNodeComponent.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
    v10 = *(UFG::qVector4 *)&v9[2].m_SafePointerList.mNode.mNext;
    v11 = *(UFG::qVector4 *)&v9[2].m_Flags;
    m_BoundComponentHandles = (UFG::qVector4)v9[2].m_BoundComponentHandles;
    this->m_WorldMatrix.v0 = *(UFG::qVector4 *)&v9[2].vfptr;
    this->m_WorldMatrix.v1 = v10;
    this->m_WorldMatrix.v2 = v11;
    this->m_WorldMatrix.v3 = m_BoundComponentHandles;
    UFG::AudioEntity::ForcePositionUpdate(&this->UFG::AudioEntity);
    if ( this->m_SFXEntity )
    {
      v13 = this->m_transformNodeComponent.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v13);
      m_SFXEntity = this->m_SFXEntity;
      v15 = *(UFG::qVector4 *)&v13[2].m_SafePointerList.mNode.mNext;
      v16 = *(UFG::qVector4 *)&v13[2].m_Flags;
      v17 = (UFG::qVector4)v13[2].m_BoundComponentHandles;
      m_SFXEntity->m_WorldMatrix.v0 = *(UFG::qVector4 *)&v13[2].vfptr;
      m_SFXEntity->m_WorldMatrix.v1 = v15;
      m_SFXEntity->m_WorldMatrix.v2 = v16;
      m_SFXEntity->m_WorldMatrix.v3 = v17;
      UFG::AudioEntity::ForcePositionUpdate(m_SFXEntity);
    }
    if ( UFG::OneShotHandle::IsValid(&this->m_leftFootstep) )
    {
      v18 = this->m_transformNodeComponent.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v18);
      m_pOneShot = this->m_leftFootstep.m_pOneShot;
      v20 = *(UFG::qVector4 *)&v18[2].m_SafePointerList.mNode.mNext;
      v21 = *(UFG::qVector4 *)&v18[2].m_Flags;
      v22 = (UFG::qVector4)v18[2].m_BoundComponentHandles;
      m_pOneShot->m_WorldMatrix.v0 = *(UFG::qVector4 *)&v18[2].vfptr;
      m_pOneShot->m_WorldMatrix.v1 = v20;
      m_pOneShot->m_WorldMatrix.v2 = v21;
      m_pOneShot->m_WorldMatrix.v3 = v22;
      UFG::AudioEntity::ForcePositionUpdate(m_pOneShot);
    }
    if ( UFG::OneShotHandle::IsValid(&this->m_rightFootstep) )
    {
      v23 = this->m_transformNodeComponent.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v23);
      v24 = this->m_rightFootstep.m_pOneShot;
      v25 = *(UFG::qVector4 *)&v23[2].m_SafePointerList.mNode.mNext;
      v26 = *(UFG::qVector4 *)&v23[2].m_Flags;
      v27 = (UFG::qVector4)v23[2].m_BoundComponentHandles;
      v24->m_WorldMatrix.v0 = *(UFG::qVector4 *)&v23[2].vfptr;
      v24->m_WorldMatrix.v1 = v25;
      v24->m_WorldMatrix.v2 = v26;
      v24->m_WorldMatrix.v3 = v27;
      UFG::AudioEntity::ForcePositionUpdate(v24);
    }
    UFG::ActorAudioComponent::UpdateAmbienceCounts(this);
    if ( (*((_BYTE *)this + 553) & 8) != 0 )
    {
      if ( !underwater )
      {
        if ( UFG::ActorAudioComponent::IsInWater(this, 1.5) )
        {
          underwater = 1;
          goto LABEL_24;
        }
        if ( !underwater )
        {
LABEL_24:
          UFG::FacialActionTreeComponent::sDisableFacialAnimationUpdate = (*((_BYTE *)this + 553) & 4) != 0;
          v30 = (UFG::HealthComponent *)this->m_healthComponent.m_pPointer;
          if ( v30 )
          {
            m_fHealth = (int)v30->m_fHealth;
            IsKilled = UFG::HealthComponent::GetIsKilled(v30);
            v33 = IsKilled;
            if ( m_fHealth >= 75 || IsKilled )
            {
              v34 = heart_beat_on;
              if ( heart_beat_on )
              {
                UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, 0x711B5A3Bu, 0i64, 0, 0i64);
                v34 = 0;
                heart_beat_on = 0;
              }
            }
            else
            {
              v34 = heart_beat_on;
            }
            if ( m_fHealth <= 70 && !v34 && !v33 )
            {
              UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, 0x5C176D09u, 0i64, 0, 0i64);
              heart_beat_on = 1;
            }
          }
          goto LABEL_34;
        }
      }
      v28 = UFG::ActorAudioComponent::IsInWater(this, 1.5);
      v29 = underwater;
      if ( !v28 )
        v29 = 0;
      underwater = v29;
      goto LABEL_24;
    }
  }
LABEL_34:
  if ( !this->m_bIsInitialized )
  {
    v35 = this->m_interiorCheckTimer - delta_sec;
    this->m_interiorCheckTimer = v35;
    if ( v35 <= 0.0 )
    {
      UFG::AudioTriggerRegion::CheckEntity(&this->UFG::AudioEntity);
      this->m_interiorCheckTimer = UFG::qRandom(5.0, (unsigned int *)&UFG::qDefaultSeed) + 50.0;
    }
  }
}

// File Line: 614
// RVA: 0x597C50
void __fastcall UFG::ActorAudioComponent::CheckInitialize(UFG::ActorAudioComponent *this)
{
  float v2; // xmm0_4
  bool v3; // al
  UFG::SimComponent *m_pPointer; // rcx
  bool v5; // cl
  bool v6; // dl
  unsigned int v7; // eax
  char *v8; // rax
  UFG::VoiceProfile *v9; // rcx
  UFG::allocator::free_link *v10; // rax
  char *v11; // rax
  char v12; // al
  UFG::VoiceProfile *m_voiceProfile; // rcx
  UFG::AudioEntity *m_SFXEntity; // rcx
  UFG::AudioEntity *v15; // rcx
  char dest[264]; // [rsp+30h] [rbp-108h] BYREF
  UFG::qWiseSymbol result; // [rsp+140h] [rbp+8h] BYREF
  UFG::qSymbol v18; // [rsp+148h] [rbp+10h] BYREF
  UFG::allocator::free_link *v19; // [rsp+150h] [rbp+18h]

  if ( (*((_BYTE *)this + 0x229) & 8) != 0 )
  {
    v2 = FLOAT_90000_0;
  }
  else if ( (*((_BYTE *)this + 0x228) & 0x20) != 0 )
  {
    v2 = FLOAT_1225_0;
  }
  else
  {
    v2 = FLOAT_4225_0;
  }
  v3 = v2 > this->m_distance2ToListener || (*((_BYTE *)this + 552) & 0x40) != 0;
  m_pPointer = this->m_healthComponent.m_pPointer;
  v5 = !m_pPointer
    || !BYTE4(m_pPointer[1].m_BoundComponentHandles.mNode.mPrev)
    || (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&m_pPointer[3].m_pSimObject) < 2.0;
  v6 = this->m_isSpeakingCnt > 0 && this->m_controller.m_pEvent;
  if ( this->m_bIsInitialized )
  {
    if ( !v3 || !v5 && !v6 || (v12 = *((_BYTE *)this + 552), v12 < 0) && (v12 & 0x40) == 0 )
    {
      m_voiceProfile = this->m_voiceProfile;
      if ( m_voiceProfile && UFG::VoiceProfile::BankRequiredForExertions(m_voiceProfile) )
        UFG::TiDo::UnloadWwiseBank(&this->m_voiceProfile->m_wwiseTagsUid);
      UFG::AudioEntity::ClearContainmentInfo(&this->UFG::AudioEntity);
      UFG::AudioEntity::ClearEnvironments(&this->UFG::AudioEntity, 0);
      UFG::AudioEntity::Shutdown(&this->UFG::AudioEntity);
      m_SFXEntity = this->m_SFXEntity;
      if ( m_SFXEntity )
      {
        UFG::AudioEntity::Shutdown(m_SFXEntity);
        v15 = this->m_SFXEntity;
        if ( v15 )
          v15->vfptr->__vecDelDtor(v15, 1u);
        this->m_SFXEntity = 0i64;
      }
    }
  }
  else if ( v3 && v5 && *((char *)this + 552) >= 0 || (*((_BYTE *)this + 552) & 0x40) != 0 )
  {
    (*(void (__fastcall **)(UFG::AudioEntity *, UFG::qSymbol *, UFG::qMatrix44 *))this->UFG::HkAudioEntityComponent::UFG::AudioEntity::vfptr->gap8)(
      &this->UFG::AudioEntity,
      &this->m_pSimObject->m_Name,
      &UFG::qMatrix44::msIdentity);
    if ( (_S17_5 & 1) != 0 )
    {
      v7 = effect_in_trunk;
    }
    else
    {
      _S17_5 |= 1u;
      v7 = UFG::TiDo::CalcWwiseUid("Effect_in_trunk");
      effect_in_trunk = v7;
    }
    UFG::AudioEntity::SetRtpcValue(&this->UFG::AudioEntity, v7, 0.0);
    UFG::ActorAudioComponent::GetVoiceProfile(this, &result, 0i64);
    if ( UFG::TidoGame::sm_dialogueTrace )
    {
      v8 = UFG::qWiseSymbol::as_cstr_dbg(&result);
      UFG::qPrintf("Assigning voice: %s\n", v8);
    }
    this->m_bIsDopplerEnabled = 0;
    v9 = this->m_voiceProfile;
    if ( v9 && UFG::VoiceProfile::BankRequiredForExertions(v9) )
      UFG::TiDo::LoadWwiseBank(&this->m_voiceProfile->m_wwiseTagsUid);
    v10 = UFG::qMalloc(0x140ui64, "ActorAudioComponent.SFXEntity", 0i64);
    v19 = v10;
    if ( v10 )
      UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)v10);
    this->m_SFXEntity = (UFG::AudioEntity *)v10;
    v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
    UFG::qSPrintf(dest, "%s__SFX", v11);
    UFG::qSymbol::create_from_string(&v18, dest);
    (*(void (__fastcall **)(UFG::AudioEntity *, UFG::qSymbol *, UFG::qMatrix44 *))this->m_SFXEntity->vfptr->gap8)(
      this->m_SFXEntity,
      &v18,
      &UFG::qMatrix44::msIdentity);
    UFG::AudioEntity::SetWwiseSwitch(this->m_SFXEntity, damage_intensity.mUID, medium.mUID);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 719
// RVA: 0x59B0E0
float __fastcall UFG::ActorAudioComponent::Distance2ToActor(
        UFG::ActorAudioComponent *this,
        UFG::ActorAudioComponent *target)
{
  if ( target )
    return (float)((float)((float)(target->m_WorldMatrix.v3.y - this->m_WorldMatrix.v3.y)
                         * (float)(target->m_WorldMatrix.v3.y - this->m_WorldMatrix.v3.y))
                 + (float)((float)(target->m_WorldMatrix.v3.x - this->m_WorldMatrix.v3.x)
                         * (float)(target->m_WorldMatrix.v3.x - this->m_WorldMatrix.v3.x)))
         + (float)((float)(target->m_WorldMatrix.v3.z - this->m_WorldMatrix.v3.z)
                 * (float)(target->m_WorldMatrix.v3.z - this->m_WorldMatrix.v3.z));
  else
    return FLOAT_N1_0;
}

// File Line: 732
// RVA: 0x5AFAA0
void __fastcall UFG::ActorAudioComponent::UpdateAmbienceCounts(UFG::ActorAudioComponent *this)
{
  UFG::SimComponent *m_pPointer; // rax
  float m_distance2ToListener; // xmm0_4
  UFG::TransformNodeComponent *v4; // rbx
  float v5; // xmm0_4
  char v6; // al

  m_pPointer = this->m_healthComponent.m_pPointer;
  if ( !m_pPointer
    || !BYTE4(m_pPointer[1].m_BoundComponentHandles.mNode.mPrev)
    || (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&m_pPointer[3].m_pSimObject) < 2.0 )
  {
    UFG::ActorAudioComponent::sm_numActivePeds = UFG::ActorAudioComponent::sm_numActivePeds + 1.0;
    if ( (_S18_5 & 1) == 0 )
    {
      _S18_5 |= 1u;
      pedProximity = UFG::ActorAudioComponent::sm_nearbyPedProximity * UFG::ActorAudioComponent::sm_nearbyPedProximity;
    }
    m_distance2ToListener = this->m_distance2ToListener;
    if ( m_distance2ToListener <= 0.000099999997
      || m_distance2ToListener >= pedProximity
      || (*((_BYTE *)this + 552) & 0x20) == 0
      || (*((_BYTE *)this + 553) & 4) != 0 )
    {
      *((_BYTE *)this + 552) &= ~4u;
    }
    else
    {
      v4 = (UFG::TransformNodeComponent *)this->m_transformNodeComponent.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v4->mWorldTransform.v3.z - UFG::AudioListener::sm_pInstance->m_triggerPosition.z) & _xmm) < UFG::ActorAudioComponent::sm_nearbyPedProximityVertical )
      {
        UFG::ActorAudioComponent::sm_numNearbyPeds = UFG::ActorAudioComponent::sm_numNearbyPeds + 1.0;
        *((_BYTE *)this + 552) |= 4u;
        if ( this->m_interiorCount )
          UFG::ActorAudioComponent::sm_numIndoorPeds = UFG::ActorAudioComponent::sm_numIndoorPeds + 1.0;
        else
          UFG::ActorAudioComponent::sm_numOutdoorPeds = UFG::ActorAudioComponent::sm_numOutdoorPeds + 1.0;
      }
    }
    if ( (*((_BYTE *)this + 553) & 4) != 0 )
      UFG::ActorAudioComponent::sm_numInCarPeds = UFG::ActorAudioComponent::sm_numInCarPeds + 1.0;
    v5 = this->m_distance2ToListener;
    if ( v5 > 0.000099999997 && v5 < pedProximity && (*((_BYTE *)this + 552) & 0x20) == 0 )
    {
      v6 = *((_BYTE *)this + 553);
      if ( (v6 & 4) == 0 && (v6 & 8) == 0 )
        UFG::ActorAudioComponent::sm_numNearbyNonAmbientPeds = UFG::ActorAudioComponent::sm_numNearbyNonAmbientPeds
                                                             + 1.0;
    }
  }
}

// File Line: 785
// RVA: 0x5A03C0
bool __fastcall UFG::ActorAudioComponent::IsAlive(UFG::ActorAudioComponent *this, bool instant)
{
  UFG::SimComponent *m_pPointer; // rax

  m_pPointer = this->m_healthComponent.m_pPointer;
  if ( !m_pPointer || !BYTE4(m_pPointer[1].m_BoundComponentHandles.mNode.mPrev) )
    return 1;
  if ( instant )
    return 0;
  return (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&m_pPointer[3].m_pSimObject) < 2.0;
}

// File Line: 809
// RVA: 0x5A36F0
void __fastcall UFG::ActorAudioComponent::OnAttach(UFG::ActorAudioComponent *this, UFG::SimObjectCVBase *object)
{
  bool IsAmbientPed; // al
  UFG::SimComponent *v5; // rdi
  UFG::SimComponent *m_pComponent; // r8
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent> *p_m_healthComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_transformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  signed __int16 v18; // cx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *p_m_simObjectCharacterPropertiesComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  float v24; // xmm1_4

  IsAmbientPed = UFG::TidoGame::CharacterIsAmbientPed(object);
  *((_BYTE *)this + 552) &= ~0x20u;
  v5 = 0i64;
  *((_BYTE *)this + 552) |= 32 * IsAmbientPed;
  if ( object )
  {
    m_Flags = object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = object->m_Components.p[6].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::HealthComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(object, UFG::HealthComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = object->m_Components.p[6].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_healthComponent = &this->m_healthComponent;
  if ( this->m_healthComponent.m_pPointer )
  {
    mPrev = p_m_healthComponent->mPrev;
    mNext = this->m_healthComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_healthComponent->mPrev = p_m_healthComponent;
    this->m_healthComponent.mNext = &this->m_healthComponent;
  }
  this->m_healthComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v12 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v12->mNext = p_m_healthComponent;
    p_m_healthComponent->mPrev = v12;
    this->m_healthComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_healthComponent;
  }
  m_pTransformNodeComponent = 0i64;
  if ( object )
    m_pTransformNodeComponent = object->m_pTransformNodeComponent;
  p_m_transformNodeComponent = &this->m_transformNodeComponent;
  if ( this->m_transformNodeComponent.m_pPointer )
  {
    v15 = p_m_transformNodeComponent->mPrev;
    v16 = this->m_transformNodeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    p_m_transformNodeComponent->mPrev = p_m_transformNodeComponent;
    this->m_transformNodeComponent.mNext = &this->m_transformNodeComponent;
  }
  this->m_transformNodeComponent.m_pPointer = m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    v17 = m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v17->mNext = p_m_transformNodeComponent;
    p_m_transformNodeComponent->mPrev = v17;
    this->m_transformNodeComponent.mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
    m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_transformNodeComponent;
  }
  if ( object )
  {
    v18 = object->m_Flags;
    if ( (v18 & 0x4000) != 0 || v18 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(object);
    }
    else if ( (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        object,
                                                                        UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                        object,
                                                                        UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    v5 = ComponentOfType;
  }
  p_m_simObjectCharacterPropertiesComponent = &this->m_simObjectCharacterPropertiesComponent;
  if ( this->m_simObjectCharacterPropertiesComponent.m_pPointer )
  {
    v21 = p_m_simObjectCharacterPropertiesComponent->mPrev;
    v22 = this->m_simObjectCharacterPropertiesComponent.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    p_m_simObjectCharacterPropertiesComponent->mPrev = p_m_simObjectCharacterPropertiesComponent;
    this->m_simObjectCharacterPropertiesComponent.mNext = &this->m_simObjectCharacterPropertiesComponent;
  }
  this->m_simObjectCharacterPropertiesComponent.m_pPointer = v5;
  if ( v5 )
  {
    v23 = v5->m_SafePointerList.mNode.mPrev;
    v23->mNext = p_m_simObjectCharacterPropertiesComponent;
    p_m_simObjectCharacterPropertiesComponent->mPrev = v23;
    this->m_simObjectCharacterPropertiesComponent.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = p_m_simObjectCharacterPropertiesComponent;
  }
  if ( !this->m_bIsInitialized )
  {
    v24 = this->m_interiorCheckTimer - 99999.0;
    this->m_interiorCheckTimer = v24;
    if ( v24 <= 0.0 )
    {
      UFG::AudioTriggerRegion::CheckEntity(&this->UFG::AudioEntity);
      this->m_interiorCheckTimer = UFG::qRandom(5.0, (unsigned int *)&UFG::qDefaultSeed) + 50.0;
    }
  }
}

// File Line: 825
// RVA: 0x5AA3F0
void __fastcall UFG::ActorAudioComponent::Reset(UFG::ActorAudioComponent *this)
{
  UFG::SimObjectCharacter *m_pSimObject; // rbx
  bool IsAmbientPed; // al
  float v4; // xmm1_4

  UFG::AudioEntity::Shutdown(&this->UFG::AudioEntity);
  UFG::ActorAudioComponent::ClearDataMembers(this);
  m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
  if ( m_pSimObject == UFG::GetLocalPlayer() )
    *((_BYTE *)this + 553) |= 8u;
  IsAmbientPed = UFG::TidoGame::CharacterIsAmbientPed((UFG::SimObjectCVBase *)this->m_pSimObject);
  *((_BYTE *)this + 552) &= ~0x20u;
  *((_BYTE *)this + 552) |= 32 * IsAmbientPed;
  if ( !this->m_bIsInitialized )
  {
    v4 = this->m_interiorCheckTimer - 999999.0;
    this->m_interiorCheckTimer = v4;
    if ( v4 <= 0.0 )
    {
      UFG::AudioTriggerRegion::CheckEntity(&this->UFG::AudioEntity);
      this->m_interiorCheckTimer = UFG::qRandom(5.0, (unsigned int *)&UFG::qDefaultSeed) + 50.0;
    }
  }
}

// File Line: 840
// RVA: 0x5ACC40
void __fastcall UFG::ActorAudioComponent::TeleportEventHandler(UFG::ActorAudioComponent *this, UFG::Event *this_event)
{
  float v3; // xmm1_4

  if ( !this->m_bIsInitialized )
  {
    v3 = this->m_interiorCheckTimer - 999999.0;
    this->m_interiorCheckTimer = v3;
    if ( v3 <= 0.0 )
    {
      UFG::AudioTriggerRegion::CheckEntity(&this->UFG::AudioEntity);
      this->m_interiorCheckTimer = UFG::qRandom(5.0, (unsigned int *)&UFG::qDefaultSeed) + 50.0;
    }
  }
}

// File Line: 857
// RVA: 0x5A39F0
void __fastcall UFG::ActorAudioComponent::OnDetach(UFG::ActorAudioComponent *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent> *p_m_healthComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_transformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  p_m_healthComponent = &this->m_healthComponent;
  if ( this->m_healthComponent.m_pPointer )
  {
    mPrev = p_m_healthComponent->mPrev;
    mNext = this->m_healthComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_healthComponent->mPrev = p_m_healthComponent;
    this->m_healthComponent.mNext = &this->m_healthComponent;
  }
  p_m_transformNodeComponent = &this->m_transformNodeComponent;
  this->m_healthComponent.m_pPointer = 0i64;
  if ( this->m_transformNodeComponent.m_pPointer )
  {
    v6 = p_m_transformNodeComponent->mPrev;
    v7 = p_m_transformNodeComponent->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_transformNodeComponent->mPrev = p_m_transformNodeComponent;
    p_m_transformNodeComponent->mNext = p_m_transformNodeComponent;
  }
  p_m_transformNodeComponent->m_pPointer = 0i64;
  UFG::ActorAudioComponent::ClearDataMembers(this);
  UFG::AudioEntity::Shutdown(&this->UFG::AudioEntity);
}

// File Line: 878
// RVA: 0x59DAD0
UFG::qWiseSymbol *__fastcall UFG::ActorAudioComponent::GetVoiceProfile(
        UFG::ActorAudioComponent *this,
        UFG::qWiseSymbol *result,
        UFG::SimObjectCharacter *target)
{
  char *v5; // rax
  int v6; // eax
  float v7; // xmm6_4
  UFG::SimComponent *m_pPointer; // rax
  char v9; // cl
  signed __int16 m_Flags; // cx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  AMD_HD3D *mUID; // rcx
  UFG::VoiceProfile *m_voiceProfile; // rax
  char *v14; // rax
  AMD_HD3D *v15; // rcx

  if ( !this->m_voiceProfile )
  {
    if ( !target )
    {
      if ( !UFG::TidoGame::GetVoiceId(this->m_pSimObject, &this->m_voiceProfile) )
      {
        v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
        UFG::qPrintf("WARNING: Could not assign voice to: %s  \n", v5);
      }
      *((_BYTE *)this + 553) ^= (*((_BYTE *)this + 553) ^ (!UFG::IsFemale((UFG::SimObjectCVBase *)this->m_pSimObject) << 6)) & 0x40;
      if ( (*((_BYTE *)this + 553) & 0x40) == 0 )
      {
        v6 = UFG::qRandom(2u, (unsigned int *)&UFG::qDefaultSeed);
        *((_BYTE *)this + 0x229) &= ~0x80u;
        *((_BYTE *)this + 0x229) |= (v6 >= 1) << 7;
      }
      *((_BYTE *)this + 554) &= ~1u;
      v7 = FLOAT_0_94999999;
      UFG::AudioEntity::SetRtpcValue(&this->UFG::AudioEntity, effect_possessed_bypass, 0.94999999);
      m_pPointer = this->m_simObjectCharacterPropertiesComponent.m_pPointer;
      if ( m_pPointer )
      {
        v9 = (__int64)m_pPointer[3].m_BoundComponentHandles.mNode.mNext & 1;
        *((_BYTE *)this + 554) &= ~1u;
        *((_BYTE *)this + 554) |= v9 & 1;
        if ( v9 )
          v7 = FLOAT_0_050000001;
        UFG::AudioEntity::SetRtpcValue(&this->UFG::AudioEntity, effect_possessed_bypass, v7);
      }
      goto LABEL_23;
    }
LABEL_12:
    m_Flags = target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(target);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        target,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                        target,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
    {
      UFG::ActorAudioComponent::GetVoiceProfile(ComponentOfTypeHK, result, 0i64);
    }
    else
    {
      mUID = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
      result->mUID = (unsigned int)mUID;
      _(mUID);
    }
    return result;
  }
  if ( target )
    goto LABEL_12;
LABEL_23:
  m_voiceProfile = this->m_voiceProfile;
  if ( m_voiceProfile )
  {
    v15 = (AMD_HD3D *)m_voiceProfile->m_wwiseVoiceUid.mUID;
  }
  else
  {
    if ( (*((_BYTE *)this + 553) & 2) == 0 )
    {
      v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
      UFG::qPrintf("Voice ID not assigned for : %s\n", v14);
    }
    *((_BYTE *)this + 553) |= 2u;
    v15 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  }
  result->mUID = (unsigned int)v15;
  _(v15);
  return result;
}

// File Line: 980
// RVA: 0x5AD430
void __fastcall UFG::ActorAudioComponent::TrySetupPanicDialog(UFG::ActorAudioComponent *this, UFG::DialogArgList *args)
{
  unsigned int v3; // edx
  __int64 v4; // rcx
  unsigned int m_nArgs; // r8d

  if ( UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled && UFG::AudioListener::sm_pInstance->m_highSpeedMode )
  {
    if ( (_S19_3 & 1) != 0 )
    {
      v3 = context_panic;
    }
    else
    {
      _S19_3 |= 1u;
      v3 = UFG::TiDo::CalcWwiseUid("panic");
      context_panic = v3;
    }
    v4 = 0i64;
    m_nArgs = args->m_nArgs;
    if ( m_nArgs )
    {
      while ( args->m_args[v4] != v3 )
      {
        v4 = (unsigned int)(v4 + 1);
        if ( (unsigned int)v4 >= m_nArgs )
          return;
      }
      args->m_uDialogEventId = -32124175;
    }
  }
}

// File Line: 1003
// RVA: 0x5AE4A0
void __fastcall UFG::ActorAudioComponent::TrySetupSocialDialog(
        UFG::ActorAudioComponent *this,
        UFG::DialogArgList *args)
{
  unsigned int v4; // eax
  char v5; // r14
  char v6; // al
  char v7; // bp
  UFG::SimObject *m_pSimObject; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v13; // rcx
  __int64 v14; // rax
  UFG::SimObjectCVBase *v15; // rbx

  v4 = _S20_1;
  if ( (_S20_1 & 1) == 0 )
  {
    _S20_1 |= 1u;
    gender_l_id = UFG::TiDo::CalcWwiseUid("gender_l");
    v4 = _S20_1;
  }
  if ( (v4 & 2) == 0 )
  {
    _S20_1 = v4 | 2;
    listener_id = UFG::TiDo::CalcWwiseUid("listener");
  }
  v5 = UFG::ArgumentSequencerBase::EventRequiresArgument(
         UFG::ArgumentSequencerBase::ms_instance,
         args->m_uDialogEventId,
         gender_l_id);
  v6 = UFG::ArgumentSequencerBase::EventRequiresArgument(
         UFG::ArgumentSequencerBase::ms_instance,
         args->m_uDialogEventId,
         listener_id);
  v7 = v6;
  if ( v5 || v6 )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        v11 = (UFG::SimObjectGame *)this->m_pSimObject;
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
      {
        v13 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 58i64);
        v14 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
        v15 = *(UFG::SimObjectCVBase **)(v13 + v14 + 40);
        if ( v15 )
        {
          if ( v7 )
            UFG::ActorAudioComponent::AddListenerArgument(this, *(UFG::SimObjectCharacter **)(v13 + v14 + 40), args);
          if ( v5 )
            UFG::ActorAudioComponent::AddGenderArgument(this, v15, args);
        }
      }
    }
  }
}

// File Line: 1041
// RVA: 0x5ADAB0
void __fastcall UFG::ActorAudioComponent::TrySetupPurchaseDialog(
        UFG::ActorAudioComponent *this,
        UFG::DialogArgList *args)
{
  unsigned int v3; // eax
  __int64 i; // rbx
  char *v5; // rsi
  UFG::SimComponent *m_pComponent; // rdx
  signed __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v9; // r8
  __int16 v10; // cx
  UFG::SimComponent *ComponentOfType; // rax

  v3 = _S21_1;
  if ( (_S21_1 & 1) == 0 )
  {
    _S21_1 |= 1u;
    context_purchase = UFG::TiDo::CalcWwiseUid("purchase");
    v3 = _S21_1;
  }
  if ( (v3 & 2) == 0 )
  {
    _S21_1 = v3 | 2;
    context_greet_shop = UFG::TiDo::CalcWwiseUid("greet_shop");
  }
  for ( i = 0i64; (unsigned int)i < args->m_nArgs; i = (unsigned int)(i + 1) )
  {
    v5 = (char *)args + 4 * i;
    if ( *((_DWORD *)v5 + 2) == context_greet_shop )
    {
      if ( LocalPlayer )
      {
        m_Flags = LocalPlayer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = LocalPlayer->m_Components.p[20].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  LocalPlayer,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                  LocalPlayer,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          m_pComponent = ComponentOfTypeHK;
        }
        else
        {
          m_pComponent = LocalPlayer->m_Components.p[20].m_pComponent;
        }
      }
      else
      {
        m_pComponent = 0i64;
      }
      v9 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 58i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v9 )
      {
        v10 = v9->m_Flags;
        if ( (v10 & 0x4000) != 0 )
        {
          ComponentOfType = v9->m_Components.p[39].m_pComponent;
        }
        else if ( v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
        {
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::InventoryComponent::_TypeUID);
        }
        else
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(v9, UFG::InventoryComponent::_TypeUID);
        }
        if ( ComponentOfType )
        {
          if ( *(_DWORD *)&ComponentOfType[14].m_Flags == 18 )
            *((_DWORD *)v5 + 2) = UFG::TiDo::CalcWwiseUid("greet_shop_eat");
        }
      }
    }
  }
}

// File Line: 1103
// RVA: 0x5ADC70
const char *__fastcall UFG::ActorAudioComponent::TrySetupSafehouseItemDialog(
        UFG::ActorAudioComponent *this,
        const char *context)
{
  const char *result; // rax
  bool v5; // bl
  bool v6; // si
  bool v7; // bp
  int v8; // eax
  UFG::SimObject *m_pSimObject; // r8
  bool v10; // di
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  bool v13; // zf
  UFG::SimObjectGame *v14; // rcx

  if ( (unsigned int)UFG::qStringCompare(context, "SHI", -1)
    && (unsigned int)UFG::qStringCompare(context, "SHISP", -1)
    && (unsigned int)UFG::qStringCompare(context, "SHINOMO", -1)
    && (unsigned int)UFG::qStringCompare(context, "SHIEL", -1)
    && (unsigned int)UFG::qStringCompare(context, "SHILF", -1) )
  {
    return context;
  }
  v5 = (unsigned int)UFG::qStringCompare(context, "SHISP", -1) == 0;
  v6 = (unsigned int)UFG::qStringCompare(context, "SHINOMO", -1) == 0;
  v7 = (unsigned int)UFG::qStringCompare(context, "SHIEL", -1) == 0;
  v8 = UFG::qStringCompare(context, "SHILF", -1);
  m_pSimObject = this->m_pSimObject;
  v10 = v8 == 0;
  if ( !m_pSimObject )
    return context;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[39].m_pComponent;
  }
  else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(
                     (UFG::SimObjectGame *)this->m_pSimObject,
                     UFG::InventoryComponent::_TypeUID);
  }
  else
  {
    v13 = (m_Flags & 0x1000) == 0;
    v14 = (UFG::SimObjectGame *)this->m_pSimObject;
    m_pComponent = v13
                 ? UFG::SimObject::GetComponentOfType(v14, UFG::InventoryComponent::_TypeUID)
                 : UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::InventoryComponent::_TypeUID);
  }
  if ( !m_pComponent )
    return context;
  switch ( *(_DWORD *)&m_pComponent[14].m_Flags )
  {
    case 0xA3:
      if ( v7 )
      {
        result = "shop_exit_low_NP_SH_01";
      }
      else if ( v6 )
      {
        result = "shop_no_money_NP_SH_01";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_NP_SH_01";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_NP_SH_01";
      }
      else
      {
        result = "shop_sale_complete_NP_SH_01";
      }
      break;
    case 0xA4:
      if ( v7 )
      {
        result = "shop_exit_low_NP_SH_02";
      }
      else if ( v6 )
      {
        result = "shop_no_money_NP_SH_02";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_NP_SH_02";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_NP_SH_02";
      }
      else
      {
        result = "shop_sale_complete_NP_SH_02";
      }
      break;
    case 0xA5:
      if ( v7 )
      {
        result = "shop_exit_low_NP_SH_03";
      }
      else if ( v6 )
      {
        result = "shop_no_money_NP_SH_03";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_NP_SH_03";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_NP_SH_03";
      }
      else
      {
        result = "shop_sale_complete_NP_SH_03";
      }
      break;
    case 0xA6:
      if ( v7 )
      {
        result = "shop_exit_low_NP_SH_04";
      }
      else if ( v6 )
      {
        result = "shop_no_money_NP_SH_04";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_NP_SH_04";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_NP_SH_04";
      }
      else
      {
        result = "shop_sale_complete_NP_SH_04";
      }
      break;
    case 0xA7:
      if ( v7 )
      {
        result = "shop_exit_low_NP_SH_05";
      }
      else if ( v6 )
      {
        result = "shop_no_money_NP_SH_05";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_NP_SH_05";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_NP_SH_05";
      }
      else
      {
        result = "shop_sale_complete_NP_SH_05";
      }
      break;
    case 0xA8:
      if ( v7 )
      {
        result = "shop_exit_low_CN_SH_01";
      }
      else if ( v6 )
      {
        result = "shop_no_money_CN_SH_01";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_CN_SH_01";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_CN_SH_01";
      }
      else
      {
        result = "shop_sale_complete_CN_SH_01";
      }
      break;
    case 0xA9:
      if ( v7 )
      {
        result = "shop_exit_low_CN_SH_02";
      }
      else if ( v6 )
      {
        result = "shop_no_money_CN_SH_02";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_CN_SH_02";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_CN_SH_02";
      }
      else
      {
        result = "shop_sale_complete_CN_SH_02";
      }
      break;
    case 0xAA:
      if ( v7 )
      {
        result = "shop_exit_low_CN_SH_03";
      }
      else if ( v6 )
      {
        result = "shop_no_money_CN_SH_03";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_CN_SH_03";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_CN_SH_03";
      }
      else
      {
        result = "shop_sale_complete_CN_SH_03";
      }
      break;
    case 0xAB:
      if ( v7 )
      {
        result = "shop_exit_low_CN_SH_04";
      }
      else if ( v6 )
      {
        result = "shop_no_money_CN_SH_04";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_CN_SH_04";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_CN_SH_04";
      }
      else
      {
        result = "shop_sale_complete_CN_SH_04";
      }
      break;
    case 0xAC:
      if ( v7 )
      {
        result = "shop_exit_low_CN_SH_05";
      }
      else if ( v6 )
      {
        result = "shop_no_money_CN_SH_05";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_CN_SH_05";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_CN_SH_05";
      }
      else
      {
        result = "shop_sale_complete_CN_SH_05";
      }
      break;
    case 0xAD:
      if ( v7 )
      {
        result = "shop_exit_low_AB_SH_01";
      }
      else if ( v6 )
      {
        result = "shop_no_money_AB_SH_01";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_AB_SH_01";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_AB_SH_01";
      }
      else
      {
        result = "shop_sale_complete_AB_SH_01";
      }
      break;
    case 0xAE:
      if ( v7 )
      {
        result = "shop_exit_low_AB_SH_02";
      }
      else if ( v6 )
      {
        result = "shop_no_money_AB_SH_02";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_AB_SH_02";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_AB_SH_02";
      }
      else
      {
        result = "shop_sale_complete_AB_SH_02";
      }
      break;
    case 0xAF:
      if ( v7 )
      {
        result = "shop_exit_low_AB_SH_03";
      }
      else if ( v6 )
      {
        result = "shop_no_money_AB_SH_03";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_AB_SH_03";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_AB_SH_03";
      }
      else
      {
        result = "shop_sale_complete_AB_SH_03";
      }
      break;
    case 0xB0:
      if ( v7 )
      {
        result = "shop_exit_low_AB_SH_04";
      }
      else if ( v6 )
      {
        result = "shop_no_money_AB_SH_04";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_AB_SH_04";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_AB_SH_04";
      }
      else
      {
        result = "shop_sale_complete_AB_SH_04";
      }
      break;
    case 0xB1:
      if ( v7 )
      {
        result = "shop_exit_low_AB_SH_05";
      }
      else if ( v6 )
      {
        result = "shop_no_money_AB_SH_05";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_AB_SH_05";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_AB_SH_05";
      }
      else
      {
        result = "shop_sale_complete_AB_SH_05";
      }
      break;
    case 0xB2:
      if ( v7 )
      {
        result = "shop_exit_low_KT_SH_01";
      }
      else if ( v6 )
      {
        result = "shop_no_money_KT_SH_01";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_KT_SH_01";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_KT_SH_01";
      }
      else
      {
        result = "shop_sale_complete_KT_SH_01";
      }
      break;
    case 0xB3:
      if ( v7 )
      {
        result = "shop_exit_low_KT_SH_02";
      }
      else if ( v6 )
      {
        result = "shop_no_money_KT_SH_02";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_KT_SH_02";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_KT_SH_02";
      }
      else
      {
        result = "shop_sale_complete_KT_SH_02";
      }
      break;
    case 0xB4:
      if ( v7 )
      {
        result = "shop_exit_low_KT_SH_03";
      }
      else if ( v6 )
      {
        result = "shop_no_money_KT_SH_03";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_KT_SH_03";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_KT_SH_03";
      }
      else
      {
        result = "shop_sale_complete_KT_SH_03";
      }
      break;
    case 0xB5:
      if ( v7 )
      {
        result = "shop_exit_low_KT_SH_04";
      }
      else if ( v6 )
      {
        result = "shop_no_money_KT_SH_04";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_KT_SH_04";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_KT_SH_04";
      }
      else
      {
        result = "shop_sale_complete_KT_SH_04";
      }
      break;
    case 0xB6:
      if ( v7 )
      {
        result = "shop_exit_low_KT_SH_05";
      }
      else if ( v6 )
      {
        result = "shop_no_money_KT_SH_05";
      }
      else if ( v10 )
      {
        result = "shop_not_enough_face_KT_SH_05";
      }
      else if ( v5 )
      {
        result = "shop_sales_pitch_KT_SH_05";
      }
      else
      {
        result = "shop_sale_complete_KT_SH_05";
      }
      break;
    default:
      return context;
  }
  return result;
}

// File Line: 1395
// RVA: 0x5AD060
const char *__fastcall UFG::ActorAudioComponent::TrySetupBeaconDialog(UFG::ActorAudioComponent *this, const char *ctx)
{
  bool v4; // bp
  bool v5; // di
  bool v6; // r15
  int v7; // eax
  UFG::SimObject *m_pSimObject; // r8
  bool v9; // bl
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  bool v12; // zf
  UFG::SimObjectGame *v13; // rcx
  const char *result; // rax
  UFG::qPropertySet *v15; // rax
  unsigned int mFlags; // eax

  v4 = this->m_pSimObject->mNode.mUID == 742779781;
  v5 = (unsigned int)UFG::qStringCompareInsensitive(ctx, "shop_sales_pitch", -1) == 0;
  v6 = (unsigned int)UFG::qStringCompareInsensitive(ctx, "shop_beacon", -1) == 0;
  v7 = UFG::qStringCompareInsensitive(ctx, "shop_sale_complete", -1);
  m_pSimObject = this->m_pSimObject;
  v9 = v7 == 0;
  if ( !m_pSimObject )
    return 0i64;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[39].m_pComponent;
  }
  else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(
                     (UFG::SimObjectGame *)this->m_pSimObject,
                     UFG::InventoryComponent::_TypeUID);
  }
  else
  {
    v12 = (m_Flags & 0x1000) == 0;
    v13 = (UFG::SimObjectGame *)this->m_pSimObject;
    m_pComponent = v12
                 ? UFG::SimObject::GetComponentOfType(v13, UFG::InventoryComponent::_TypeUID)
                 : UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::InventoryComponent::_TypeUID);
  }
  if ( !m_pComponent )
    return 0i64;
  switch ( *(_DWORD *)&m_pComponent[14].m_Flags )
  {
    case 0x12:
      if ( v5 )
      {
        result = "shop_sales_pitch_pork";
      }
      else if ( v9 )
      {
        result = "shop_sale_complete_pork";
      }
      else
      {
        result = "shop_beacon_pork";
      }
      break;
    case 0x13:
      if ( v5 )
      {
        result = "shop_sales_pitch_fish";
      }
      else if ( v9 )
      {
        result = "shop_sale_complete_fish";
      }
      else
      {
        result = "shop_beacon_fish";
      }
      break;
    case 0x14:
      if ( v5 )
      {
        result = "shop_sales_pitch_food_stick";
      }
      else if ( v9 )
      {
        result = "shop_sale_complete_food_stick";
      }
      else
      {
        result = "shop_beacon_food_stick";
      }
      break;
    case 0x15:
      if ( v5 )
      {
        result = "shop_sales_pitch_noodles";
      }
      else if ( v9 )
      {
        result = "shop_sale_complete_noodles";
      }
      else
      {
        result = "shop_beacon_noodles";
      }
      break;
    case 0x16:
      if ( v5 )
      {
        result = "shop_sales_pitch_duck";
      }
      else if ( v9 )
      {
        result = "shop_sale_complete_duck";
      }
      else
      {
        result = "shop_beacon_duck";
      }
      break;
    case 0x17:
      if ( v5 )
      {
        result = "shop_sales_pitch_fishballs";
      }
      else if ( v9 )
      {
        result = "shop_sale_complete_fishballs";
      }
      else
      {
        result = "shop_beacon_fishballs";
      }
      break;
    case 0x18:
      if ( v5 )
      {
        result = "shop_sales_pitch_squid";
      }
      else if ( v9 )
      {
        result = "shop_sale_complete_squid";
      }
      else
      {
        result = "shop_beacon_squid";
      }
      break;
    case 0x19:
      if ( v5 )
      {
        result = "shop_sales_pitch_waffle";
      }
      else if ( v9 )
      {
        result = "shop_sale_complete_waffle";
      }
      else
      {
        result = "shop_beacon_waffle";
      }
      break;
    case 0x1A:
      if ( v5 )
      {
        result = "shop_sales_pitch_ice_cream";
      }
      else if ( v9 )
      {
        result = "shop_sale_complete_ice_cream";
      }
      else
      {
        result = "shop_beacon_ice_cream";
      }
      break;
    case 0x1B:
      if ( v5 )
      {
        result = "shop_sales_pitch_711";
      }
      else if ( v9 )
      {
        result = "shop_sale_complete_711";
      }
      else
      {
        result = "shop_greet_enter_711";
      }
      break;
    case 0x1F:
      if ( v5 )
      {
        result = "shop_sales_pitch_apothecary";
      }
      else if ( v9 )
      {
        result = "shop_sale_complete_apothecary";
      }
      else
      {
        result = "shop_greet_enter_apothecary";
      }
      break;
    default:
      v15 = PropertyUtils::Get<UFG::qSymbol>(
              this->m_pSimObject->m_pSceneObj,
              (UFG::qArray<unsigned long,0> *)&SimSym_InventoryType);
      if ( !v15 )
        goto LABEL_76;
      mFlags = v15->mFlags;
      if ( qSymbol_Vehicle_18.mUID == mFlags )
        return "vehicle";
      if ( qSymbol_Boat_18.mUID == mFlags )
        return "boat";
      if ( qSymbol_Clothes_18.mUID == mFlags )
      {
        if ( v4 )
          result = "shop_beacon";
        else
          result = "shop_sales_pitch_clothes";
      }
      else
      {
LABEL_76:
        if ( v6 )
          result = "shop_beacon_generic";
        else
          result = ctx;
      }
      break;
  }
  return result;
}

// File Line: 1572
// RVA: 0x5AD4C0
void __fastcall UFG::ActorAudioComponent::TrySetupPoliceDialog(
        UFG::ActorAudioComponent *this,
        unsigned int eventId,
        unsigned int contextHash,
        const char **outContext,
        const char **outVoice)
{
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  UFG::SimObjectCharacter *v13; // rdi
  const char *v14; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *v17; // r14
  float x; // xmm6_4
  float y; // xmm8_4
  float z; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm8_4
  float v23; // xmm7_4
  float *v24; // rax
  __m128 x_low; // xmm2
  float v26; // xmm6_4
  char v27; // r14
  UFG::qStaticSymbol *v28; // rdx
  float *v29; // rbp
  UFG::SimComponent *m_pComponent; // rdx
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectProp *v33; // rcx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  __int16 v35; // dx
  bool v36; // r8
  const char *v37; // rax

  if ( !*outContext )
    return;
  v9 = _S22_1;
  if ( (_S22_1 & 1) == 0 )
  {
    _S22_1 |= 1u;
    police_surrender_hash = UFG::TiDo::CalcWwiseUid(police_surrender_string);
    v9 = _S22_1;
  }
  if ( (v9 & 2) == 0 )
  {
    _S22_1 = v9 | 2;
    police_surrender_foot_hash = UFG::TiDo::CalcWwiseUid(police_surrender_foot_string);
    v9 = _S22_1;
  }
  if ( (v9 & 4) == 0 )
  {
    _S22_1 = v9 | 4;
    police_surrender_gun_hash = UFG::TiDo::CalcWwiseUid(police_surrender_gun_string);
    v9 = _S22_1;
  }
  if ( (v9 & 8) == 0 )
  {
    _S22_1 = v9 | 8;
    police_surrender_interior_hash = UFG::TiDo::CalcWwiseUid(police_surrender_string);
    v9 = _S22_1;
  }
  if ( (v9 & 0x10) == 0 )
  {
    _S22_1 = v9 | 0x10;
    police_surrender_car_hash = UFG::TiDo::CalcWwiseUid(police_surrender_interior_string);
    v9 = _S22_1;
  }
  if ( (v9 & 0x20) == 0 )
  {
    _S22_1 = v9 | 0x20;
    police_surrender_boat_hash = UFG::TiDo::CalcWwiseUid(police_surrender_boat_string);
    v9 = _S22_1;
  }
  if ( (v9 & 0x40) == 0 )
  {
    _S22_1 = v9 | 0x40;
    police_heat_hash = UFG::TiDo::CalcWwiseUid(police_heat_string);
    v9 = _S22_1;
  }
  if ( (v9 & 0x80u) == 0 )
  {
    _S22_1 = v9 | 0x80;
    police_heat_2_hash = UFG::TiDo::CalcWwiseUid(police_heat_2_string);
    v9 = _S22_1;
  }
  if ( (v9 & 0x100) == 0 )
  {
    _S22_1 = v9 | 0x100;
    police_heat_3_hash = UFG::TiDo::CalcWwiseUid(police_heat_3_string);
    v9 = _S22_1;
  }
  if ( (v9 & 0x200) == 0 )
  {
    _S22_1 = v9 | 0x200;
    police_heat_4_hash = UFG::TiDo::CalcWwiseUid(police_heat_4_string);
    v9 = _S22_1;
  }
  if ( (v9 & 0x400) == 0 )
  {
    _S22_1 = v9 | 0x400;
    v10 = UFG::qStringHash32("player_is_escaping_on_foot_speed_threshold", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&player_is_escaping_on_foot_speed_threshold, v10);
    atexit(UFG::ActorAudioComponent::TrySetupPoliceDialog_::_5_::_dynamic_atexit_destructor_for__player_is_escaping_on_foot_speed_threshold__);
    v9 = _S22_1;
  }
  if ( (v9 & 0x800) == 0 )
  {
    _S22_1 = v9 | 0x800;
    v11 = UFG::qStringHash32("player_is_escaping_by_vehicle_speed_threshold", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&player_is_escaping_by_vehicle_speed_threshold_0, v11);
    atexit(UFG::ActorAudioComponent::TrySetupPoliceDialog_::_5_::_dynamic_atexit_destructor_for__player_is_escaping_by_vehicle_speed_threshold__);
    v9 = _S22_1;
  }
  if ( (v9 & 0x1000) == 0 )
  {
    _S22_1 = v9 | 0x1000;
    v12 = UFG::qStringHash32("surrender_foot_min_distance", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&surrender_foot_min_distance, v12);
    atexit(UFG::ActorAudioComponent::TrySetupPoliceDialog_::_5_::_dynamic_atexit_destructor_for__surrender_foot_min_distance__);
  }
  if ( eventId != dword_14208B638 && eventId != dword_14208B63C && eventId != dword_14208B640 )
  {
    *outContext = 0i64;
    return;
  }
  if ( contextHash == police_heat_hash
    || contextHash == police_heat_2_hash
    || contextHash == police_heat_3_hash
    || contextHash == police_heat_4_hash )
  {
    *outVoice = police_voice_donnie;
    return;
  }
  v13 = LocalPlayer;
  v14 = 0i64;
  m_pTransformNodeComponent = 0i64;
  if ( LocalPlayer )
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
  m_pSimObject = this->m_pSimObject;
  v17 = 0i64;
  if ( m_pSimObject )
    v17 = m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v17);
  x = v17->mWorldTransform.v3.x;
  y = v17->mWorldTransform.v3.y;
  z = v17->mWorldTransform.v3.z;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v21 = x - m_pTransformNodeComponent->mWorldTransform.v3.x;
  v22 = y - m_pTransformNodeComponent->mWorldTransform.v3.y;
  v23 = z - m_pTransformNodeComponent->mWorldTransform.v3.z;
  v24 = UFG::qPropertySet::Get<float>(
          UFG::ActorAudioComponent::sm_copConfigPs,
          (UFG::qArray<unsigned long,0> *)&surrender_foot_min_distance,
          DEPTH_RECURSE);
  if ( (float)((float)((float)(v22 * v22) + (float)(v21 * v21)) + (float)(v23 * v23)) < (float)(*v24 * *v24) )
    goto LABEL_71;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  x_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldVelocity.x);
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                            + (float)(m_pTransformNodeComponent->mWorldVelocity.y
                                    * m_pTransformNodeComponent->mWorldVelocity.y))
                    + (float)(m_pTransformNodeComponent->mWorldVelocity.z * m_pTransformNodeComponent->mWorldVelocity.z);
  LODWORD(v26) = _mm_sqrt_ps(x_low).m128_u32[0];
  if ( UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsDriver
    || UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsPassenger )
  {
    v27 = 1;
    v28 = &player_is_escaping_by_vehicle_speed_threshold_0;
  }
  else
  {
    v27 = 0;
    v28 = &player_is_escaping_on_foot_speed_threshold;
  }
  v29 = UFG::qPropertySet::Get<float>(
          UFG::ActorAudioComponent::sm_copConfigPs,
          (UFG::qArray<unsigned long,0> *)v28,
          DEPTH_RECURSE);
  if ( v13 )
  {
    m_Flags = v13->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v13->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = v13->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v33 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 25i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
  if ( v33 )
  {
    v35 = v33->m_Flags;
    if ( (v35 & 0x4000) == 0 && v35 >= 0 )
    {
      if ( (v35 & 0x2000) != 0 )
      {
        ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v33);
        goto LABEL_66;
      }
      if ( (v35 & 0x1000) == 0 )
      {
        ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v33,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        goto LABEL_66;
      }
    }
    ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v33,
                                                                   UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    goto LABEL_66;
  }
  ComponentOfType = 0i64;
LABEL_66:
  v36 = 0;
  if ( ComponentOfType )
    v36 = ComponentOfType->mWeaponTypeInfo->mFireModes[ComponentOfType->mFireMode]->mProjectileSpawnBoneName.mUID != UFG::gNullQSymbolUC.mUID;
  if ( v26 < *v29 )
  {
    if ( v36 )
      v14 = police_surrender_gun_string;
LABEL_71:
    *outContext = v14;
    return;
  }
  if ( v36 && UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) < 0.30000001 )
  {
    *outContext = police_surrender_gun_string;
  }
  else if ( UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) >= 0.5 )
  {
    *outContext = police_surrender_string;
  }
  else
  {
    v37 = police_surrender_foot_string;
    if ( v27 )
      v37 = police_surrender_car_string;
    *outContext = v37;
  }
}

// File Line: 1729
// RVA: 0x5AC470
void __fastcall UFG::ActorAudioComponent::SetupTaggedDialog(UFG::ActorAudioComponent *this, UFG::DialogArgList *args)
{
  unsigned int mUID; // ebx
  __int64 m_nArgs; // rax
  unsigned int v5; // ecx
  __int64 v6; // rax

  mUID = this->m_voiceProfile->m_wwiseTagsUid.mUID;
  _((AMD_HD3D *)mUID);
  if ( mUID )
  {
    m_nArgs = args->m_nArgs;
    if ( (unsigned int)m_nArgs < 6 )
    {
      args->m_args[m_nArgs] = mUID;
      ++args->m_nArgs;
    }
  }
  v5 = *(&stru_14242ED00.mUID + 4 * UFG::TaggedDialogueStateManager::m_stateIdx);
  if ( v5 )
  {
    v6 = args->m_nArgs;
    if ( (unsigned int)v6 < 6 )
    {
      args->m_args[v6] = v5;
      ++args->m_nArgs;
    }
  }
  _((AMD_HD3D *)mUID);
}

// File Line: 1746
// RVA: 0x5AC9F0
void __fastcall UFG::ActorAudioComponent::StopCurrentlyPlaying(UFG::ActorAudioComponent *this, bool force)
{
  UFG::AudioEvent *m_pEvent; // rcx
  unsigned int m_uPlayingId; // ebx
  UFG::TiDo *Instance; // rax

  if ( force || (*((_BYTE *)this + 552) & 8) != 0 )
  {
    m_pEvent = this->m_controller.m_pEvent;
    if ( m_pEvent )
    {
      if ( force )
      {
        m_uPlayingId = m_pEvent->m_uPlayingId;
        m_pEvent->m_pController = 0i64;
        this->m_controller.m_pEvent = 0i64;
        if ( m_uPlayingId )
        {
          Instance = UFG::TiDo::GetInstance();
          UFG::TiDo::StopPlaying(Instance, m_uPlayingId);
        }
      }
      else
      {
        UFG::AudioEvent::StopAndForget(m_pEvent, 500);
      }
    }
  }
}

// File Line: 1828
// RVA: 0x1559F20
signed __int64 UFG::_dynamic_initializer_for__hashPanic__()
{
  signed __int64 result; // rax

  result = UFG::TiDo::CalcWwiseUid("panic");
  hashPanic = result;
  return result;
}

// File Line: 1829
// RVA: 0x1559F40
signed __int64 UFG::_dynamic_initializer_for__hashScreamPain__()
{
  signed __int64 result; // rax

  result = UFG::TiDo::CalcWwiseUid("scream_pain");
  hashScreamPain = result;
  return result;
}

// File Line: 1830
// RVA: 0x1559F60
signed __int64 UFG::_dynamic_initializer_for__hashTags__()
{
  signed __int64 result; // rax

  result = UFG::TiDo::CalcWwiseUid("d_tags");
  hashTags = result;
  return result;
}

// File Line: 1833
// RVA: 0x5A6AC0
char __fastcall UFG::ActorAudioComponent::PlayPanic(UFG::ActorAudioComponent *this)
{
  unsigned int m_nArgs; // edx
  UFG::AudioEvent *m_pEvent; // rcx
  unsigned int v4; // r8d
  __int64 v5; // rcx
  unsigned int m_uDialogEventId; // ebx
  unsigned int mUID; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // edx
  UFG::AudioDialogEventController *p_m_controller; // rsi
  UFG::SimComponent *m_pPointer; // rax
  UFG::AudioEventCallbackObject *mFreeListHead; // rbx
  unsigned int v13; // eax
  int v14; // ebx
  UFG::DialogArgList args; // [rsp+28h] [rbp-28h] BYREF

  args.vfptr = (UFG::DialogArgListVtbl *)&UFG::DialogArgList::`vftable;
  UFG::qMemSet(args.m_args, 0, 0x18u);
  args.m_nArgs = 0;
  args.m_uDialogEventId = hashTags;
  if ( hashPanic )
  {
    args.m_args[args.m_nArgs] = hashPanic;
    m_nArgs = ++args.m_nArgs;
  }
  else
  {
    m_nArgs = args.m_nArgs;
  }
  if ( !this->m_bIsInitialized )
    return 0;
  if ( this->m_isSpeakingCnt <= 0 || (m_pEvent = this->m_controller.m_pEvent) == 0i64 )
  {
LABEL_10:
    if ( UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled && UFG::AudioListener::sm_pInstance->m_highSpeedMode )
    {
      if ( (_S19_3 & 1) != 0 )
      {
        v4 = context_panic;
      }
      else
      {
        _S19_3 |= 1u;
        v4 = UFG::TiDo::CalcWwiseUid("panic");
        context_panic = v4;
        m_nArgs = args.m_nArgs;
      }
      v5 = 0i64;
      if ( m_nArgs )
      {
        while ( args.m_args[v5] != v4 )
        {
          v5 = (unsigned int)(v5 + 1);
          if ( (unsigned int)v5 >= m_nArgs )
            goto LABEL_20;
        }
        args.m_uDialogEventId = -32124175;
      }
    }
LABEL_20:
    m_uDialogEventId = args.m_uDialogEventId;
    if ( args.m_uDialogEventId == -32124175 )
    {
      mUID = this->m_voiceProfile->m_wwiseTagsUid.mUID;
      _((AMD_HD3D *)mUID);
      if ( mUID )
      {
        v8 = args.m_nArgs;
        if ( args.m_nArgs < 6 )
        {
          args.m_args[args.m_nArgs] = mUID;
          v8 = ++args.m_nArgs;
        }
      }
      else
      {
        v8 = args.m_nArgs;
      }
      v9 = *(&stru_14242ED00.mUID + 4 * UFG::TaggedDialogueStateManager::m_stateIdx);
      if ( v9 && v8 < 6 )
      {
        args.m_args[v8] = v9;
        ++args.m_nArgs;
      }
      _((AMD_HD3D *)mUID);
    }
    else
    {
      UFG::ActorAudioComponent::TrySetupPurchaseDialog(this, &args);
      UFG::ActorAudioComponent::TrySetupSocialDialog(this, &args);
      if ( !m_uDialogEventId )
        return 0;
    }
    p_m_controller = &this->m_controller;
    if ( this->m_controller.m_pEvent )
      return 0;
    m_pPointer = this->m_healthComponent.m_pPointer;
    if ( m_pPointer )
    {
      if ( BYTE4(m_pPointer[1].m_BoundComponentHandles.mNode.mPrev)
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&m_pPointer[3].m_pSimObject) >= 2.0 )
      {
        return 0;
      }
    }
    UFG::AudioEntity::CreateDialogEvent(&this->UFG::AudioEntity, &this->m_controller, 0i64, 0i64);
    if ( !p_m_controller->m_pEvent )
      return 0;
    mFreeListHead = (UFG::AudioEventCallbackObject *)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
    if ( UFG::gAudioEventCallbackObjectPool.mFreeListHead )
    {
      UFG::gAudioEventCallbackObjectPool.mFreeListHead = *(char **)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
      v13 = UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated + 1;
      UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated = v13;
      if ( UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated <= v13 )
        UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated = v13;
    }
    else
    {
      UFG::qFixedAllocator::ReportFull(&UFG::gAudioEventCallbackObjectPool);
    }
    if ( mFreeListHead )
    {
      mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable;
      mFreeListHead->m_next = 0i64;
      mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::SpeechControlCallback::`vftable;
    }
    if ( p_m_controller->m_pEvent )
      UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, mFreeListHead);
    if ( p_m_controller->m_pEvent )
      UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, 0i64);
    v14 = UFG::AudioDialogEvent::Enqueue((UFG::AudioDialogEvent *)p_m_controller->m_pEvent, &args, 0);
    if ( (_S26_2 & 1) == 0 )
    {
      _S26_2 |= 1u;
      UFG::qWiseSymbol::create_from_string(&d_tags, "d_tags");
      atexit(UFG::ActorAudioComponent::PlaySpeech_::_10_::_dynamic_atexit_destructor_for__d_tags__);
    }
    if ( (*((_BYTE *)this + 553) & 8) == 0 )
    {
      if ( !v14 )
      {
LABEL_55:
        if ( p_m_controller->m_pEvent )
          UFG::AudioEvent::Destroy(p_m_controller->m_pEvent);
        *((_BYTE *)this + 553) |= 1u;
        return 0;
      }
      if ( args.m_uDialogEventId == d_tags.mUID )
        UFG::ConversationManager::InterruptConversationsWithCharacter(
          this->m_pSimObject,
          eInterruptType_HitReaction,
          1,
          0i64);
    }
    if ( v14 && UFG::AudioEventController::Play(&this->m_controller, 0) )
    {
      ++this->m_isSpeakingCnt;
      this->m_curPlayingPriority = 5;
      *((_BYTE *)this + 553) &= 0xEEu;
      return 1;
    }
    goto LABEL_55;
  }
  if ( this->m_curPlayingPriority < 5 )
  {
    if ( (*((_BYTE *)this + 552) & 8) != 0 )
    {
      UFG::AudioEvent::StopAndForget(m_pEvent, 500);
      m_nArgs = args.m_nArgs;
    }
    goto LABEL_10;
  }
  return 0;
}

// File Line: 1842
// RVA: 0x5A7360
char __fastcall UFG::ActorAudioComponent::PlayScreamPain(UFG::ActorAudioComponent *this)
{
  unsigned int m_nArgs; // edx
  UFG::AudioEvent *m_pEvent; // rcx
  unsigned int v4; // r8d
  __int64 v5; // rcx
  unsigned int m_uDialogEventId; // ebx
  unsigned int mUID; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // edx
  UFG::AudioDialogEventController *p_m_controller; // rsi
  UFG::SimComponent *m_pPointer; // rax
  UFG::AudioEventCallbackObject *mFreeListHead; // rbx
  unsigned int v13; // eax
  int v14; // ebx
  UFG::DialogArgList args; // [rsp+28h] [rbp-28h] BYREF

  args.vfptr = (UFG::DialogArgListVtbl *)&UFG::DialogArgList::`vftable;
  UFG::qMemSet(args.m_args, 0, 0x18u);
  args.m_nArgs = 0;
  args.m_uDialogEventId = hashTags;
  if ( hashScreamPain )
  {
    args.m_args[args.m_nArgs] = hashScreamPain;
    m_nArgs = ++args.m_nArgs;
  }
  else
  {
    m_nArgs = args.m_nArgs;
  }
  if ( !this->m_bIsInitialized )
    return 0;
  if ( this->m_isSpeakingCnt <= 0 || (m_pEvent = this->m_controller.m_pEvent) == 0i64 )
  {
LABEL_10:
    if ( UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled && UFG::AudioListener::sm_pInstance->m_highSpeedMode )
    {
      if ( (_S19_3 & 1) != 0 )
      {
        v4 = context_panic;
      }
      else
      {
        _S19_3 |= 1u;
        v4 = UFG::TiDo::CalcWwiseUid("panic");
        context_panic = v4;
        m_nArgs = args.m_nArgs;
      }
      v5 = 0i64;
      if ( m_nArgs )
      {
        while ( args.m_args[v5] != v4 )
        {
          v5 = (unsigned int)(v5 + 1);
          if ( (unsigned int)v5 >= m_nArgs )
            goto LABEL_20;
        }
        args.m_uDialogEventId = -32124175;
      }
    }
LABEL_20:
    m_uDialogEventId = args.m_uDialogEventId;
    if ( args.m_uDialogEventId == -32124175 )
    {
      mUID = this->m_voiceProfile->m_wwiseTagsUid.mUID;
      _((AMD_HD3D *)mUID);
      if ( mUID )
      {
        v8 = args.m_nArgs;
        if ( args.m_nArgs < 6 )
        {
          args.m_args[args.m_nArgs] = mUID;
          v8 = ++args.m_nArgs;
        }
      }
      else
      {
        v8 = args.m_nArgs;
      }
      v9 = *(&stru_14242ED00.mUID + 4 * UFG::TaggedDialogueStateManager::m_stateIdx);
      if ( v9 && v8 < 6 )
      {
        args.m_args[v8] = v9;
        ++args.m_nArgs;
      }
      _((AMD_HD3D *)mUID);
    }
    else
    {
      UFG::ActorAudioComponent::TrySetupPurchaseDialog(this, &args);
      UFG::ActorAudioComponent::TrySetupSocialDialog(this, &args);
      if ( !m_uDialogEventId )
        return 0;
    }
    p_m_controller = &this->m_controller;
    if ( this->m_controller.m_pEvent )
      return 0;
    m_pPointer = this->m_healthComponent.m_pPointer;
    if ( m_pPointer )
    {
      if ( BYTE4(m_pPointer[1].m_BoundComponentHandles.mNode.mPrev)
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&m_pPointer[3].m_pSimObject) >= 2.0 )
      {
        return 0;
      }
    }
    UFG::AudioEntity::CreateDialogEvent(&this->UFG::AudioEntity, &this->m_controller, 0i64, 0i64);
    if ( !p_m_controller->m_pEvent )
      return 0;
    mFreeListHead = (UFG::AudioEventCallbackObject *)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
    if ( UFG::gAudioEventCallbackObjectPool.mFreeListHead )
    {
      UFG::gAudioEventCallbackObjectPool.mFreeListHead = *(char **)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
      v13 = UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated + 1;
      UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated = v13;
      if ( UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated <= v13 )
        UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated = v13;
    }
    else
    {
      UFG::qFixedAllocator::ReportFull(&UFG::gAudioEventCallbackObjectPool);
    }
    if ( mFreeListHead )
    {
      mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable;
      mFreeListHead->m_next = 0i64;
      mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::SpeechControlCallback::`vftable;
    }
    if ( p_m_controller->m_pEvent )
      UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, mFreeListHead);
    if ( p_m_controller->m_pEvent )
      UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, 0i64);
    v14 = UFG::AudioDialogEvent::Enqueue((UFG::AudioDialogEvent *)p_m_controller->m_pEvent, &args, 0);
    if ( (_S26_2 & 1) == 0 )
    {
      _S26_2 |= 1u;
      UFG::qWiseSymbol::create_from_string(&d_tags, "d_tags");
      atexit(UFG::ActorAudioComponent::PlaySpeech_::_10_::_dynamic_atexit_destructor_for__d_tags__);
    }
    if ( (*((_BYTE *)this + 553) & 8) == 0 )
    {
      if ( !v14 )
      {
LABEL_55:
        if ( p_m_controller->m_pEvent )
          UFG::AudioEvent::Destroy(p_m_controller->m_pEvent);
        *((_BYTE *)this + 553) |= 1u;
        return 0;
      }
      if ( args.m_uDialogEventId == d_tags.mUID )
        UFG::ConversationManager::InterruptConversationsWithCharacter(
          this->m_pSimObject,
          eInterruptType_HitReaction,
          1,
          0i64);
    }
    if ( v14 && UFG::AudioEventController::Play(&this->m_controller, 0) )
    {
      ++this->m_isSpeakingCnt;
      this->m_curPlayingPriority = 5;
      *((_BYTE *)this + 553) &= 0xEEu;
      return 1;
    }
    goto LABEL_55;
  }
  if ( this->m_curPlayingPriority < 5 )
  {
    if ( (*((_BYTE *)this + 552) & 8) != 0 )
    {
      UFG::AudioEvent::StopAndForget(m_pEvent, 500);
      m_nArgs = args.m_nArgs;
    }
    goto LABEL_10;
  }
  return 0;
}

// File Line: 1880
// RVA: 0x5A8F60
char __fastcall UFG::ActorAudioComponent::QueueSpeechExternalMission(
        UFG::ActorAudioComponent *this,
        unsigned int eventID,
        const char *context,
        UFG::AudioEventCallbackObject *audioCallbacks,
        unsigned int priority,
        bool subtitle)
{
  unsigned int v9; // eax

  v9 = UFG::TiDo::CalcWwiseUid(context);
  return UFG::ActorAudioComponent::QueueSpeechExternalMission(this, eventID, v9, audioCallbacks, priority, subtitle);
}

// File Line: 1885
// RVA: 0x5A8E20
char __fastcall UFG::ActorAudioComponent::QueueSpeechExternalMission(
        UFG::ActorAudioComponent *this,
        unsigned int eventID,
        unsigned int fileId,
        UFG::AudioEventCallbackObject *audioCallbacks,
        unsigned int priority,
        bool subtitle)
{
  UFG::AudioEvent *m_pEvent; // rcx
  UFG::allocator::free_link *v12; // rax
  UFG::AudioEventExternalSourceInfo *v13; // rax
  UFG::AudioEventExternalSourceInfo *v14; // rsi
  UFG::ExternalSourceInfoNode *p; // rcx
  UFG::ExternalSourceInfoNode *v16; // rbx

  if ( !this->m_bIsInitialized )
    return 0;
  if ( this->m_isSpeakingCnt > 0 )
  {
    m_pEvent = this->m_controller.m_pEvent;
    if ( m_pEvent )
    {
      if ( priority <= this->m_curPlayingPriority )
        return 0;
      if ( (*((_BYTE *)this + 0x228) & 8) != 0 )
        UFG::AudioEvent::StopAndForget(m_pEvent, 500);
    }
  }
  UFG::TiDo::GetWwiseStreamFileSize(fileId);
  if ( ((eventID + 1) & 0xFFFFFFFE) == 0 )
    eventID = play_mission_22.mUID;
  v12 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x20ui64, "ExternalSourceInfo.QueueSpeech", 0i64, 1u);
  if ( v12 )
  {
    UFG::AudioEventExternalSourceInfo::AudioEventExternalSourceInfo((UFG::AudioEventExternalSourceInfo *)v12, 1u);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  p = v14->m_externals.p;
  p->m_externalSourceCookie = slot_1_22.mUID;
  v14->m_externals.p->m_fileId = fileId;
  v16 = v14->m_externals.p;
  v16->m_codecID = Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)p);
  UFG::TiDo::GetNameFromWwiseUid(fileId);
  return UFG::ActorAudioComponent::PlaySpeechExternal(this, eventID, priority, audioCallbacks, v14, subtitle);
}

// File Line: 1936
// RVA: 0x5A8930
char __fastcall UFG::ActorAudioComponent::QueueSpeechExternalAmbient(
        UFG::ActorAudioComponent *this,
        unsigned int eventId,
        const char *context,
        UFG::AudioEventCallbackObject *audioCallbacks,
        unsigned int priority,
        bool force,
        bool subtitle)
{
  unsigned int v12; // r12d
  UFG::AudioEvent *m_pEvent; // rcx
  unsigned int v14; // r8d
  unsigned int v15; // ecx
  unsigned int v16; // eax
  bool v17; // al
  char v18; // cl
  const char *v19; // rdx
  char *mData; // r14
  const char *v21; // rbx
  unsigned int v22; // r15d
  __int64 v23; // r14
  int v24; // edx
  signed int size; // r9d
  UFG::AmbientContextNode *p; // r8
  int m_lastIdx; // r8d
  signed int RandomVariation; // eax
  char v29; // bl
  char *v30; // rax
  __int64 v31; // rax
  __int64 v32; // rcx
  __int64 v33; // rbx
  UFG::qWiseSymbol result; // [rsp+40h] [rbp-C0h] BYREF
  char *outVoice; // [rsp+48h] [rbp-B8h] BYREF
  char *outContext[2]; // [rsp+50h] [rbp-B0h] BYREF
  char dest[232]; // [rsp+60h] [rbp-A0h] BYREF
  unsigned int contextHash; // [rsp+190h] [rbp+90h] BYREF

  outContext[1] = (char *)-2i64;
  if ( !this->m_bIsInitialized )
    return 0;
  v12 = priority;
  if ( this->m_isSpeakingCnt > 0 )
  {
    m_pEvent = this->m_controller.m_pEvent;
    if ( m_pEvent )
    {
      if ( priority <= this->m_curPlayingPriority )
        return 0;
      if ( (*((_BYTE *)this + 552) & 8) != 0 )
        UFG::AudioEvent::StopAndForget(m_pEvent, 500);
    }
  }
  v14 = UFG::TiDo::CalcWwiseUid(context);
  contextHash = v14;
  v15 = _S25_1;
  if ( (_S25_1 & 1) == 0 )
  {
    _S25_1 |= 1u;
    hashNone = UFG::TiDo::CalcWwiseUid("none");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( (v15 & 2) == 0 )
  {
    _S25_1 = v15 | 2;
    hashPanic_0 = UFG::TiDo::CalcWwiseUid("panic");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( (v15 & 4) == 0 )
  {
    _S25_1 = v15 | 4;
    hashPushed = UFG::TiDo::CalcWwiseUid("pushed");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( (v15 & 8) == 0 )
  {
    _S25_1 = v15 | 8;
    hashEBE = UFG::TiDo::CalcWwiseUid("event_big_exclaim");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( (v15 & 0x10) == 0 )
  {
    _S25_1 = v15 | 0x10;
    hashStartled = UFG::TiDo::CalcWwiseUid("startled");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( (v15 & 0x20) == 0 )
  {
    _S25_1 = v15 | 0x20;
    hashLookOutCar = UFG::TiDo::CalcWwiseUid("look_out_car");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( (v15 & 0x40) == 0 )
  {
    _S25_1 = v15 | 0x40;
    hashBadDriver = UFG::TiDo::CalcWwiseUid("bad_driver");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( (v15 & 0x80u) == 0 )
  {
    _S25_1 = v15 | 0x80;
    hashPassengerReaction = UFG::TiDo::CalcWwiseUid("passenger_reaction");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( (v15 & 0x100) == 0 )
  {
    _S25_1 = v15 | 0x100;
    hashOnResumeNpc = UFG::TiDo::CalcWwiseUid("on_resume_npc");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( (v15 & 0x200) != 0 )
  {
    v16 = hashOnResumePlayer;
  }
  else
  {
    _S25_1 = v15 | 0x200;
    v16 = UFG::TiDo::CalcWwiseUid("on_resume_player");
    hashOnResumePlayer = v16;
    v14 = contextHash;
  }
  if ( hashNone == v14 )
    return 0;
  v17 = v14 == hashBadDriver || v14 == hashPassengerReaction || v14 == hashOnResumeNpc || v14 == v16;
  if ( eventId == dword_14208B638 || eventId == dword_14208B63C || eventId == dword_14208B640 )
  {
    v18 = 1;
  }
  else
  {
    v18 = 0;
    if ( !v17
      && UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled
      && UFG::AudioListener::sm_pInstance->m_highSpeedMode )
    {
      if ( hashPanic_0 == v14 || hashPushed == v14 || hashEBE == v14 || hashStartled == v14 || v14 == hashLookOutCar )
        return UFG::ActorAudioComponent::PlayPanic(this);
      return 0;
    }
  }
  v19 = context;
  outContext[0] = (char *)context;
  mData = this->m_voiceProfile->m_subtitleSet.mData;
  outVoice = mData;
  if ( v18 )
  {
    UFG::ActorAudioComponent::TrySetupPoliceDialog(
      this,
      eventId,
      v14,
      (const char **)outContext,
      (const char **)&outVoice);
    v19 = outContext[0];
    if ( !outContext[0] )
      return 0;
    mData = outVoice;
  }
  if ( eventId == play_beacon_22.mUID || eventId == play_haggle_22.mUID )
    v19 = UFG::ActorAudioComponent::TrySetupBeaconDialog(this, context);
  v21 = UFG::ActorAudioComponent::TrySetupSafehouseItemDialog(this, v19);
  UFG::qSPrintf(dest, "%s.%s.001.", mData, v21);
  v22 = UFG::TiDo::CalcWwiseUid(dest);
  UFG::qWiseSymbol::create_from_string(&result, v21);
  v23 = 0i64;
  v24 = 0;
  size = this->m_ambientContexts.m_nodes.size;
  if ( size <= 0 )
    goto LABEL_62;
  p = this->m_ambientContexts.m_nodes.p;
  while ( p[v24].m_context.mUID != result.mUID )
  {
    if ( ++v24 >= size )
      goto LABEL_62;
  }
  if ( v24 < 0 )
LABEL_62:
    m_lastIdx = -1;
  else
    m_lastIdx = p[v24].m_lastIdx;
  RandomVariation = UFG::ExternalSourceUtil::GetRandomVariation(v22, &contextHash, m_lastIdx);
  if ( RandomVariation >= 0 )
  {
    UFG::AmbientContextManager::Set(&this->m_ambientContexts, &result, RandomVariation);
    if ( !eventId )
      eventId = play_ambient_22.mUID;
    v30 = (char *)UFG::qMemoryPool::Allocate(
                    &g_AudioComponentPool,
                    0x20ui64,
                    "ExternalSourceInfo.QueueSpeech",
                    0i64,
                    1u);
    outVoice = v30;
    if ( v30 )
    {
      UFG::AudioEventExternalSourceInfo::AudioEventExternalSourceInfo((UFG::AudioEventExternalSourceInfo *)v30, 1u);
      v23 = v31;
    }
    (*(UFG::qStaticWiseSymbol **)(v23 + 24))->mUID = slot_1_22.mUID;
    v32 = *(_QWORD *)(v23 + 24);
    *(_DWORD *)(v32 + 8) = contextHash;
    v33 = *(_QWORD *)(v23 + 24);
    *(_DWORD *)(v33 + 4) = Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)v32);
    v29 = UFG::ActorAudioComponent::PlaySpeechExternal(
            this,
            eventId,
            v12,
            audioCallbacks,
            (UFG::AudioEventExternalSourceInfo *)v23,
            subtitle);
  }
  else
  {
    UFG::qPrintf("Speech file not found: %u %s\n", contextHash, dest);
    v29 = 0;
  }
  _((AMD_HD3D *)result.mUID);
  return v29;
}

// File Line: 2055
// RVA: 0x5A7AE0
char __fastcall UFG::ActorAudioComponent::PlaySpeechExternal(
        UFG::ActorAudioComponent *this,
        unsigned int eventId,
        unsigned int priority,
        UFG::AudioEventCallbackObject *audioCallbacks,
        UFG::AudioEventExternalSourceInfo *info,
        bool subtitle)
{
  UFG::AudioDialogEventController *p_m_controller; // rdi
  UFG::AudioEventCallbackObject *mFreeListHead; // rbx
  unsigned int v11; // eax
  UFG::AudioEventCallbackObject *v12; // rbx
  unsigned int v13; // eax

  p_m_controller = &this->m_controller;
  UFG::AudioEntity::CreateEventA(&this->UFG::AudioEntity, eventId, &this->m_controller, 0i64, info);
  if ( p_m_controller->m_pEvent )
  {
    mFreeListHead = (UFG::AudioEventCallbackObject *)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
    if ( UFG::gAudioEventCallbackObjectPool.mFreeListHead )
    {
      UFG::gAudioEventCallbackObjectPool.mFreeListHead = *(char **)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
      v11 = UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated + 1;
      UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated = v11;
      if ( UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated <= v11 )
        UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated = v11;
    }
    else
    {
      UFG::qFixedAllocator::ReportFull(&UFG::gAudioEventCallbackObjectPool);
    }
    if ( mFreeListHead )
    {
      mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable;
      mFreeListHead->m_next = 0i64;
      mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::SpeechControlCallback::`vftable;
    }
    if ( p_m_controller->m_pEvent )
      UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, mFreeListHead);
    if ( p_m_controller->m_pEvent )
      UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, audioCallbacks);
    if ( subtitle )
    {
      v12 = (UFG::AudioEventCallbackObject *)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
      if ( UFG::gAudioEventCallbackObjectPool.mFreeListHead )
      {
        UFG::gAudioEventCallbackObjectPool.mFreeListHead = *(char **)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
        v13 = UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated + 1;
        UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated = v13;
        if ( UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated <= v13 )
          UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated = v13;
      }
      else
      {
        UFG::qFixedAllocator::ReportFull(&UFG::gAudioEventCallbackObjectPool);
      }
      if ( v12 )
      {
        v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable;
        v12->m_next = 0i64;
        v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AACSubtitleCallback::`vftable;
      }
      if ( p_m_controller->m_pEvent )
        UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, v12);
    }
    if ( p_m_controller->m_pEvent )
    {
      if ( p_m_controller->m_pEvent->vfptr->Play(p_m_controller->m_pEvent, 0) )
      {
        ++this->m_isSpeakingCnt;
        this->m_curPlayingPriority = priority;
        *((_BYTE *)this + 553) &= 0xEEu;
        return 1;
      }
      *((_BYTE *)p_m_controller->m_pEvent + 144) |= 4u;
      if ( p_m_controller->m_pEvent )
        p_m_controller->m_pEvent->m_pController = 0i64;
      p_m_controller->m_pEvent = 0i64;
    }
    if ( p_m_controller->m_pEvent )
      UFG::AudioEvent::Destroy(p_m_controller->m_pEvent);
    *((_BYTE *)this + 553) |= 1u;
  }
  return 0;
}

// File Line: 2120
// RVA: 0x5A88A0
char __fastcall UFG::ActorAudioComponent::QueueSpeech(
        UFG::ActorAudioComponent *this,
        UFG::DialogArgList *args,
        UFG::AudioEventCallbackObject *audioCallbacks,
        unsigned int priority,
        bool force,
        bool subtitle)
{
  UFG::AudioEvent *m_pEvent; // rcx

  if ( !this->m_bIsInitialized )
    return 0;
  if ( this->m_isSpeakingCnt > 0 )
  {
    m_pEvent = this->m_controller.m_pEvent;
    if ( m_pEvent )
    {
      if ( priority <= this->m_curPlayingPriority )
        return 0;
      if ( (*((_BYTE *)this + 552) & 8) != 0 )
        UFG::AudioEvent::StopAndForget(m_pEvent, 500);
    }
  }
  return UFG::ActorAudioComponent::PlaySpeech(this, args, audioCallbacks, priority, subtitle);
}

// File Line: 2147
// RVA: 0x5A7880
char __fastcall UFG::ActorAudioComponent::PlaySpeech(
        UFG::ActorAudioComponent *this,
        UFG::DialogArgList *args,
        UFG::AudioEventCallbackObject *audioCallbacks,
        unsigned int priority,
        bool subtitle)
{
  unsigned int m_uDialogEventId; // edi
  UFG::AudioDialogEventController *p_m_controller; // rsi
  UFG::SimComponent *m_pPointer; // rax
  UFG::AudioEventCallbackObject *mFreeListHead; // rdi
  unsigned int v13; // eax
  UFG::AudioEventCallbackObject *v14; // rax
  int v15; // edi

  UFG::ActorAudioComponent::TrySetupPanicDialog(this, args);
  m_uDialogEventId = args->m_uDialogEventId;
  if ( m_uDialogEventId == 0xFE15D2F1 )
  {
    UFG::ActorAudioComponent::SetupTaggedDialog(this, args);
LABEL_5:
    p_m_controller = &this->m_controller;
    if ( this->m_controller.m_pEvent )
      return 0;
    m_pPointer = this->m_healthComponent.m_pPointer;
    if ( m_pPointer )
    {
      if ( BYTE4(m_pPointer[1].m_BoundComponentHandles.mNode.mPrev)
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&m_pPointer[3].m_pSimObject) >= 2.0
        && priority < 0xA )
      {
        return 0;
      }
    }
    UFG::AudioEntity::CreateDialogEvent(&this->UFG::AudioEntity, &this->m_controller, 0i64, 0i64);
    if ( !p_m_controller->m_pEvent )
      return 0;
    mFreeListHead = (UFG::AudioEventCallbackObject *)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
    if ( UFG::gAudioEventCallbackObjectPool.mFreeListHead )
    {
      UFG::gAudioEventCallbackObjectPool.mFreeListHead = *(char **)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
      v13 = UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated + 1;
      UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated = v13;
      if ( UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated <= v13 )
        UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated = v13;
    }
    else
    {
      UFG::qFixedAllocator::ReportFull(&UFG::gAudioEventCallbackObjectPool);
    }
    if ( mFreeListHead )
    {
      mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable;
      mFreeListHead->m_next = 0i64;
      mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::SpeechControlCallback::`vftable;
    }
    if ( p_m_controller->m_pEvent )
      UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, mFreeListHead);
    if ( subtitle )
    {
      v14 = (UFG::AudioEventCallbackObject *)UFG::AACSubtitleCallback::operator new(
                                               0x10ui64,
                                               "ActorAudioComponent.SubtitleCallback");
      if ( v14 )
      {
        v14->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable;
        v14->m_next = 0i64;
        v14->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AACSubtitleCallback::`vftable;
      }
      if ( p_m_controller->m_pEvent )
        UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, v14);
    }
    if ( p_m_controller->m_pEvent )
      UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, audioCallbacks);
    v15 = UFG::AudioDialogEvent::Enqueue((UFG::AudioDialogEvent *)p_m_controller->m_pEvent, args, 0);
    if ( (_S26_2 & 1) == 0 )
    {
      _S26_2 |= 1u;
      UFG::qWiseSymbol::create_from_string(&d_tags, "d_tags");
      atexit(UFG::ActorAudioComponent::PlaySpeech_::_10_::_dynamic_atexit_destructor_for__d_tags__);
    }
    if ( (*((_BYTE *)this + 553) & 8) == 0 )
    {
      if ( !v15 )
      {
LABEL_35:
        if ( p_m_controller->m_pEvent )
          UFG::AudioEvent::Destroy(p_m_controller->m_pEvent);
        *((_BYTE *)this + 553) |= 1u;
        return 0;
      }
      if ( args->m_uDialogEventId == d_tags.mUID )
        UFG::ConversationManager::InterruptConversationsWithCharacter(
          this->m_pSimObject,
          eInterruptType_HitReaction,
          1,
          0i64);
    }
    if ( v15 && UFG::AudioEventController::Play(&this->m_controller, 0) )
    {
      ++this->m_isSpeakingCnt;
      this->m_curPlayingPriority = priority;
      *((_BYTE *)this + 553) &= 0xEEu;
      return 1;
    }
    goto LABEL_35;
  }
  UFG::ActorAudioComponent::TrySetupPurchaseDialog(this, args);
  UFG::ActorAudioComponent::TrySetupSocialDialog(this, args);
  if ( m_uDialogEventId )
    goto LABEL_5;
  return 0;
}

// File Line: 2226
// RVA: 0x59CE60
UFG::qWiseSymbol *__fastcall UFG::ActorAudioComponent::GetFootwearType(UFG::ActorAudioComponent *this)
{
  UFG::qWiseSymbol *result; // rax

  if ( (_S27_2 & 1) == 0 )
  {
    _S27_2 |= 1u;
    UFG::qSymbol::create_from_string(&shoesSymbol, "footwear_type");
    atexit(UFG::ActorAudioComponent::GetFootwearType_::_2_::_dynamic_atexit_destructor_for__shoesSymbol__);
  }
  result = PropertyUtils::Get<UFG::qWiseSymbol>(
             this->m_pSimObject->m_pSceneObj,
             (UFG::qArray<unsigned long,0> *)&shoesSymbol);
  if ( result )
    return (UFG::qWiseSymbol *)result->mUID;
  return result;
}

// File Line: 2244
// RVA: 0x596220
void __fastcall UFG::ActorAudioComponent::AddGenderArgument(
        UFG::ActorAudioComponent *this,
        UFG::SimObjectCVBase *simObject,
        UFG::DialogArgList *args)
{
  bool v4; // zf
  __int64 m_nArgs; // rax

  v4 = !UFG::IsFemale(simObject);
  m_nArgs = args->m_nArgs;
  if ( v4 )
  {
    if ( (unsigned int)m_nArgs < 6 )
    {
      args->m_args[m_nArgs] = 0xB976E27E;
      ++args->m_nArgs;
    }
  }
  else if ( (unsigned int)m_nArgs < 6 )
  {
    args->m_args[m_nArgs] = 0x83651CD5;
    ++args->m_nArgs;
  }
}

// File Line: 2259
// RVA: 0x5964D0
void __fastcall UFG::ActorAudioComponent::AddListenerArgument(
        UFG::ActorAudioComponent *this,
        UFG::SimObjectCharacter *simObject,
        UFG::DialogArgList *args)
{
  signed __int16 m_Flags; // cx
  UFG::ActorAudioComponent *v5; // rax
  unsigned int mUID; // ecx
  __int64 m_nArgs; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h] BYREF

  if ( simObject )
  {
    m_Flags = simObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(simObject);
    else
      v5 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          simObject,
                                          UFG::ActorAudioComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(
                                          simObject,
                                          UFG::ActorAudioComponent::_TypeUID));
    if ( v5 )
    {
      mUID = UFG::ActorAudioComponent::GetVoiceId(v5, &result)->mUID;
      if ( mUID )
      {
        m_nArgs = args->m_nArgs;
        if ( (unsigned int)m_nArgs < 6 )
        {
          args->m_args[m_nArgs] = mUID;
          ++args->m_nArgs;
        }
      }
      _((AMD_HD3D *)result.mUID);
    }
  }
}

// File Line: 2277
// RVA: 0x155A120
__int64 UFG::_dynamic_initializer_for__loc_footwear_type__()
{
  switchId.mUID = UFG::qWiseSymbolUIDFromString("loc_footwear_type", 0x811C9DC5);
  _((AMD_HD3D *)switchId.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__loc_footwear_type__);
}

// File Line: 2278
// RVA: 0x155A080
__int64 UFG::_dynamic_initializer_for__loc_footstep_type__()
{
  stru_14242F408.mUID = UFG::qWiseSymbolUIDFromString("loc_footstep_type", 0x811C9DC5);
  _((AMD_HD3D *)stru_14242F408.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__loc_footstep_type__);
}

// File Line: 2279
// RVA: 0x1559FD0
__int64 UFG::_dynamic_initializer_for__high_heel__()
{
  high_heel.mUID = UFG::qWiseSymbolUIDFromString("high_heel", 0x811C9DC5);
  _((AMD_HD3D *)high_heel.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__high_heel__);
}

// File Line: 2280
// RVA: 0x155CF20
__int64 UFG::_dynamic_initializer_for__sneaker__()
{
  sneaker.mUID = UFG::qWiseSymbolUIDFromString("sneaker", 0x811C9DC5);
  _((AMD_HD3D *)sneaker.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sneaker__);
}

// File Line: 2281
// RVA: 0x1559A20
__int64 UFG::_dynamic_initializer_for__barefoot__()
{
  barefoot.mUID = UFG::qWiseSymbolUIDFromString("barefoot", 0x811C9DC5);
  _((AMD_HD3D *)barefoot.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__barefoot__);
}

// File Line: 2282
// RVA: 0x1559B60
__int64 UFG::_dynamic_initializer_for__dress_shoe__()
{
  dress_shoe.mUID = UFG::qWiseSymbolUIDFromString("dress_shoe", 0x811C9DC5);
  _((AMD_HD3D *)dress_shoe.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__dress_shoe__);
}

// File Line: 2283
// RVA: 0x155A0D0
__int64 UFG::_dynamic_initializer_for__loc_footsteps_p__()
{
  stru_14242E938.mUID = UFG::qWiseSymbolUIDFromString("loc_footsteps_p", 0x811C9DC5);
  _((AMD_HD3D *)stru_14242E938.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__loc_footsteps_p__);
}

// File Line: 2284
// RVA: 0x1559800
__int64 UFG::_dynamic_initializer_for__WET_SWITCH__()
{
  WET_SWITCH.mUID = UFG::qWiseSymbolUIDFromString("WET_SWITCH", 0x811C9DC5);
  _((AMD_HD3D *)WET_SWITCH.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__WET_SWITCH__);
}

// File Line: 2285
// RVA: 0x1555460
__int64 UFG::_dynamic_initializer_for__FootwearUnderwear__()
{
  UFG::qSymbol::create_from_string(&FootwearUnderwear, "FootwearUnderwear");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__FootwearUnderwear__);
}

// File Line: 2286
// RVA: 0x1555590
__int64 UFG::_dynamic_initializer_for__S_GSP__()
{
  UFG::qSymbol::create_from_string(&S_GSP, "S_GSP");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__S_GSP__);
}

// File Line: 2289
// RVA: 0x59BD30
void __fastcall UFG::ActorAudioComponent::FightImpactCallback(
        UFG::ActorAudioComponent *this,
        UFG::eAudioEventCallbackType in_eType,
        UFG::AudioEvent *in_pEvent,
        void *in_pCallbackInfo)
{
  if ( in_eType == eAudioEventCallbackType_End )
    UFG::AudioEntity::SetWwiseSwitch(in_pEvent->m_pEntity, damage_intensity.mUID, medium.mUID);
}

// File Line: 2299
// RVA: 0x5A6310
void __fastcall UFG::ActorAudioComponent::PlayFootstepLeft(UFG::ActorAudioComponent *this, unsigned int stepId)
{
  if ( this->m_bIsInitialized && (!hardLimitFootsteps || !UFG::OneShotHandle::IsValid(&this->m_leftFootstep)) )
  {
    if ( UFG::OneShotHandle::IsValid(&this->m_leftFootstep)
      || (UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_transformNodeComponent.m_pPointer),
          UFG::OneShotPool::GetOneShotHandle(&this->m_leftFootstep, &this->m_WorldMatrix),
          UFG::OneShotHandle::IsValid(&this->m_leftFootstep)) )
    {
      UFG::ActorAudioComponent::PlayFootstep(this, stepId, &this->m_leftFootstep);
    }
  }
}

// File Line: 2322
// RVA: 0x5A63B0
void __fastcall UFG::ActorAudioComponent::PlayFootstepRight(UFG::ActorAudioComponent *this, unsigned int stepId)
{
  if ( this->m_bIsInitialized && (!hardLimitFootsteps || !UFG::OneShotHandle::IsValid(&this->m_rightFootstep)) )
  {
    if ( UFG::OneShotHandle::IsValid(&this->m_rightFootstep)
      || (UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_transformNodeComponent.m_pPointer),
          UFG::OneShotPool::GetOneShotHandle(&this->m_rightFootstep, &this->m_WorldMatrix),
          UFG::OneShotHandle::IsValid(&this->m_rightFootstep)) )
    {
      UFG::ActorAudioComponent::PlayFootstep(this, stepId, &this->m_rightFootstep);
    }
  }
}

// File Line: 2345
// RVA: 0x5A6120
void __fastcall UFG::ActorAudioComponent::PlayFootstep(
        UFG::ActorAudioComponent *this,
        unsigned int stepID,
        UFG::OneShotHandle *oneShot)
{
  bool v6; // r8
  bool v7; // cl
  unsigned int mUID; // esi
  UFG::GameStatTracker *v9; // rax
  UFG::PersistentData::ID *Stat; // rax
  unsigned int v11; // r8d
  unsigned int FootwearType; // eax
  char v13; // al
  unsigned int v14; // edx
  UFG::OneShot *m_pOneShot; // rcx
  unsigned int GroundSurfaceMaterial; // eax

  v6 = UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled && UFG::AudioListener::sm_pInstance->m_highSpeedMode;
  v7 = UFG::GunshotManager::ms_instance->m_numAiGunshots.m_currentValue >= 4.0
    && UFG::FacialActionTreeComponent::sDisableFacialAnimationUpdate;
  if ( stepID
    && ((*((_BYTE *)this + 553) & 8) != 0
     || !v6
     && UFG::ActorAudioComponent::sm_numPerFrameFootsteps < UFG::ActorAudioComponent::sm_maxPerFrameFootsteps
     && !v7) )
  {
    ++UFG::ActorAudioComponent::sm_numPerFrameFootsteps;
    if ( UFG::OneShotHandle::IsValid(oneShot) )
    {
      mUID = sneaker.mUID;
      if ( (*((_BYTE *)this + 553) & 8) != 0 )
      {
        v9 = UFG::GameStatTracker::Instance();
        Stat = UFG::GameStatTracker::GetStat(v9, CurrentFootwear);
        if ( Stat->mValue.mUID == FootwearUnderwear.mUID || Stat->mValue.mUID == S_GSP.mUID )
          v11 = barefoot.mUID;
        else
          v11 = sneaker.mUID;
      }
      else
      {
        FootwearType = (unsigned int)UFG::ActorAudioComponent::GetFootwearType(this);
        mUID = FootwearType;
        if ( FootwearType )
        {
          v11 = FootwearType;
        }
        else
        {
          v13 = *((_BYTE *)this + 553);
          if ( (v13 & 0x40) == 0 )
          {
            v14 = switchId.mUID;
            m_pOneShot = oneShot->m_pOneShot;
            if ( v13 >= 0 )
              v11 = dress_shoe.mUID;
            else
              v11 = high_heel.mUID;
LABEL_28:
            UFG::AudioEntity::SetWwiseSwitch(m_pOneShot, v14, v11);
            if ( UFG::ActorAudioComponent::IsInWater(this, 0.0) )
            {
              if ( (_S28_1 & 1) != 0 )
              {
                GroundSurfaceMaterial = water_uid;
              }
              else
              {
                _S28_1 |= 1u;
                GroundSurfaceMaterial = UFG::TiDo::CalcWwiseUid("surface_water");
                water_uid = GroundSurfaceMaterial;
              }
            }
            else
            {
              GroundSurfaceMaterial = UFG::TidoGame::FindGroundSurfaceMaterial(
                                        (UFG::SimObjectCharacter *)this->m_pSimObject,
                                        mUID);
            }
            UFG::TidoGame::SetSurfaceMaterial((unsigned __int64)oneShot->m_pOneShot, GroundSurfaceMaterial);
            UFG::AudioEntity::SetWwiseSwitch(oneShot->m_pOneShot, stru_14242F408.mUID, stepID);
            UFG::OneShot::Play(oneShot->m_pOneShot, stru_14242E938.mUID);
            return;
          }
          v11 = dress_shoe.mUID;
        }
      }
      v14 = switchId.mUID;
      m_pOneShot = oneShot->m_pOneShot;
      goto LABEL_28;
    }
  }
}

// File Line: 2415
// RVA: 0x5A5DE0
void __fastcall UFG::ActorAudioComponent::PlayFightImpact(
        UFG::ActorAudioComponent *this,
        unsigned int attack,
        unsigned int target,
        unsigned int intensity)
{
  UFG::AudioEntity *m_SFXEntity; // rcx
  UFG::AudioEntity *v8; // rcx
  __int64 v9; // [rsp+40h] [rbp-38h]
  UFG::AudioEventInitParams pInitParams; // [rsp+48h] [rbp-30h] BYREF

  m_SFXEntity = this->m_SFXEntity;
  if ( m_SFXEntity )
  {
    UFG::AudioEntity::SetWwiseSwitch(m_SFXEntity, 0x20F621E3u, attack);
    UFG::AudioEntity::SetWwiseSwitch(this->m_SFXEntity, 0xF17446D4, target);
    UFG::AudioEntity::SetWwiseSwitch(this->m_SFXEntity, 0x8A4FA224, intensity);
    v8 = this->m_SFXEntity;
    LODWORD(v9) = 0;
    pInitParams.m_EventCallbackUserData = 0i64;
    pInitParams.m_EventPlayEndCallback = (void (__fastcall *)(UFG::AudioEntity *, UFG::eAudioEventCallbackType, UFG::AudioEvent *, void *))UFG::ActorAudioComponent::FightImpactCallback;
    *(_QWORD *)pInitParams.gap8 = 4294967232i64;
    *(_QWORD *)&pInitParams.gap8[8] = v9;
    UFG::AudioEntity::CreateAndPlayEvent(v8, 0xA95B0394, &pInitParams, 0, 0i64);
  }
}

// File Line: 2457
// RVA: 0x5A6040
void __fastcall UFG::ActorAudioComponent::PlayFightRumble(
        UFG::ActorAudioComponent *this,
        unsigned int attack,
        unsigned int target,
        unsigned int intensity)
{
  if ( this->m_SFXEntity )
  {
    if ( (_S29 & 1) == 0 )
    {
      _S29 |= 1u;
      play_fight_rumble = UFG::TiDo::CalcWwiseUid("play_motion_fighting");
    }
    UFG::AudioEntity::SetWwiseSwitch(this->m_SFXEntity, 0x20F621E3u, attack);
    UFG::AudioEntity::SetWwiseSwitch(this->m_SFXEntity, 0xF17446D4, target);
    UFG::AudioEntity::SetWwiseSwitch(this->m_SFXEntity, 0x8A4FA224, intensity);
    if ( target != -1793093012 )
      UFG::AudioEntity::CreateAndPlayEvent(this->m_SFXEntity, play_fight_rumble, 0i64, 0, 0i64);
  }
}

// File Line: 2509
// RVA: 0x5A0530
bool __fastcall UFG::ActorAudioComponent::IsInWater(UFG::ActorAudioComponent *this, float depth)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterPhysicsComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  result = m_pSimObject
        && ((m_Flags = m_pSimObject->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(
                                  m_pSimObject,
                                  UFG::CharacterPhysicsComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pSimObject,
                                  UFG::CharacterPhysicsComponent::_TypeUID)),
             m_pComponent = (UFG::CharacterPhysicsComponent *)ComponentOfType)
          : (m_pComponent = (UFG::CharacterPhysicsComponent *)m_pSimObject->m_Components.p[27].m_pComponent),
            m_pComponent && UFG::CharacterPhysicsComponent::IsInWater(m_pComponent))
        && (float)(UFG::CharacterPhysicsComponent::GetWaterElevation(m_pComponent) - this->m_WorldMatrix.v3.z) > depth;
  return result;
}

// File Line: 2526
// RVA: 0x5A3040
__int64 __fastcall UFG::ActorAudioComponent::LookupAndShowSubtitleFromPropertySet(unsigned int uid)
{
  UFG::allocator::free_link *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  UFG::UIHKTextOverlay *Instance; // rax

  if ( (UFG::SubtitleManager::sm_subtitleMode == eSubtitleMode_On
     || UFG::SubtitleManager::sm_subtitleMode == eSubtitleMode_Cantonese && UFG::SubtitleManager::LabelIsCantonese(uid))
    && ((v2 = UFG::qMalloc(0xD0ui64, "UISubtitleMessage", 0i64)) == 0i64
      ? (v4 = 0i64)
      : (UFG::UISubtitleMessage::UISubtitleMessage((UFG::UISubtitleMessage *)v2, TYPE_SUBTITLE_TEXT, uid, 0i64), v4 = v3),
        *(_DWORD *)(v4 + 24) = 1097859072,
        (Instance = UFG::UIHKTextOverlay::getInstance()) != 0i64) )
  {
    return UFG::UIHKTextOverlay::QueueMessage(Instance, (UFG::UISubtitleMessage *)v4);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 2923
// RVA: 0x59CCD0
UFG::Conversation *__fastcall UFG::ActorAudioComponent::GetActiveAmbientConversation(UFG::ActorAudioComponent *this)
{
  unsigned int m_activeAmbientConversationId; // edx
  UFG::qBaseTreeRB *v2; // rax

  m_activeAmbientConversationId = this->m_activeAmbientConversationId;
  if ( m_activeAmbientConversationId
    && (v2 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, m_activeAmbientConversationId)) != 0i64 )
  {
    return (UFG::Conversation *)&v2[-1].mCount;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 2933
// RVA: 0x5A8700
UFG::ActorAudioComponent *__fastcall UFG::ActorAudioComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v7; // ebx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h] BYREF

  v3 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x230ui64, "ActorAudioComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::ActorAudioComponent::ActorAudioComponent((UFG::ActorAudioComponent *)v3, pSceneObj);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v7 = 40;
  else
    v7 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v9, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v9, v5, v7);
  UFG::SimObjectModifier::Close(&v9);
  UFG::SimObjectModifier::~SimObjectModifier(&v9);
  return (UFG::ActorAudioComponent *)v5;
}

// File Line: 2957
// RVA: 0x1559C00
signed __int64 UFG::_dynamic_initializer_for__effect_possessed_bypass__()
{
  signed __int64 result; // rax

  result = UFG::TiDo::CalcWwiseUid("effect_possessed_bypass");
  effect_possessed_bypass = result;
  return result;
}

// File Line: 2975
// RVA: 0x15548D0
__int64 dynamic_initializer_for__UFG::TaggedDialogueStateManager::m_states__()
{
  `eh vector constructor iterator(
    (char *)UFG::TaggedDialogueStateManager::m_states,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::TaggedDialogueState::TaggedDialogueState);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TaggedDialogueStateManager::m_states__);
}

// File Line: 2988
// RVA: 0x59F7E0
void UFG::TaggedDialogueStateManager::Init(void)
{
  UFG::qWiseSymbol *v0; // rax
  UFG::qWiseSymbol *v1; // rax
  UFG::qWiseSymbol *v2; // rax
  UFG::qWiseSymbol *v3; // rax
  UFG::qWiseSymbol *v4; // rax
  UFG::qWiseSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h] BYREF

  v0 = UFG::qWiseSymbol::create_from_string(&result, "a");
  UFG::qWiseSymbol::operator=(&stru_14242ED00, v0);
  _((AMD_HD3D *)result.mUID);
  v1 = UFG::qWiseSymbol::create_from_string(&result, "b");
  UFG::qWiseSymbol::operator=(&stru_14242ED10, v1);
  _((AMD_HD3D *)result.mUID);
  v2 = UFG::qWiseSymbol::create_from_string(&result, "c");
  UFG::qWiseSymbol::operator=(&stru_14242ED20, v2);
  _((AMD_HD3D *)result.mUID);
  v3 = UFG::qWiseSymbol::create_from_string(&result, "d_tagged_dialogue_thug_bank_a");
  UFG::qWiseSymbol::operator=(&bankId, v3);
  _((AMD_HD3D *)result.mUID);
  v4 = UFG::qWiseSymbol::create_from_string(&result, "d_tagged_dialogue_thug_bank_b");
  UFG::qWiseSymbol::operator=(&stru_14242ED14, v4);
  _((AMD_HD3D *)result.mUID);
  v5 = UFG::qWiseSymbol::create_from_string(&result, "d_tagged_dialogue_thug_bank_c");
  UFG::qWiseSymbol::operator=(&stru_14242ED24, v5);
  _((AMD_HD3D *)result.mUID);
  UFG::TaggedDialogueStateManager::m_stateIdx = 0;
  UFG::TiDo::LoadWwiseBank(&bankId);
  UFG::TaggedDialogueStateManager::sm_timeOfLastSwap = UFG::Metrics::msInstance.mSimTimeMSec;
}

// File Line: 3008
// RVA: 0x5A32E0
char __fastcall UFG::TaggedDialogueStateManager::MaybeChangeState(bool force)
{
  __int64 v2; // rbx

  if ( !force && UFG::Metrics::msInstance.mSimTimeMSec - UFG::TaggedDialogueStateManager::sm_timeOfLastSwap < 0x1D4C0
    || UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled && UFG::AudioListener::sm_pInstance->m_highSpeedMode )
  {
    return 0;
  }
  UFG::TaggedDialogueStateManager::sm_timeOfLastSwap = UFG::Metrics::msInstance.mSimTimeMSec;
  v2 = (int)UFG::qRandom(3u, (unsigned int *)&UFG::qDefaultSeed);
  if ( (_DWORD)v2 == UFG::TaggedDialogueStateManager::m_stateIdx )
    return 0;
  UFG::TiDo::UnloadWwiseBank(&bankId + 4 * UFG::TaggedDialogueStateManager::m_stateIdx);
  UFG::TaggedDialogueStateManager::m_stateIdx = v2;
  UFG::TiDo::LoadWwiseBank(&bankId + 4 * v2);
  return 1;
}

// File Line: 3055
// RVA: 0x5AA850
void __fastcall UFG::AmbientContextManager::Set(
        UFG::AmbientContextManager *this,
        UFG::qWiseSymbol *context,
        unsigned __int16 chosen_idx)
{
  unsigned __int16 v3; // r13
  unsigned int v4; // r15d
  __int64 size; // r11
  int v8; // r9d
  __int64 v9; // rcx
  unsigned int mUID; // edx
  UFG::AmbientContextNode *p; // rax
  unsigned int v12; // edi
  unsigned __int16 m_age; // bp
  UFG::AmbientContextNode *v14; // rbx
  __int64 v15; // r14
  __int64 v16; // rbx
  __int64 v17; // rcx

  v3 = UFG::Metrics::msFrameCount;
  v4 = 0;
  size = (int)this->m_nodes.size;
  v8 = 0;
  v9 = 0i64;
  if ( (int)size <= 0 )
    goto LABEL_5;
  mUID = context->mUID;
  p = this->m_nodes.p;
  while ( p->m_context.mUID != mUID )
  {
    ++v9;
    ++v8;
    ++p;
    if ( v9 >= size )
      goto LABEL_5;
  }
  if ( v8 < 0 )
  {
LABEL_5:
    v12 = 0;
    m_age = -1;
    if ( (int)size <= 0 )
    {
LABEL_10:
      v12 = v4;
    }
    else
    {
      while ( 1 )
      {
        v14 = this->m_nodes.p;
        if ( v14[v12].m_context.mUID == UFG::qWiseSymbol::get_null()->mUID )
          break;
        v15 = v12;
        if ( this->m_nodes.p[v15].m_age < m_age )
        {
          m_age = this->m_nodes.p[v15].m_age;
          v4 = v12;
        }
        if ( (signed int)++v12 >= (signed int)this->m_nodes.size )
          goto LABEL_10;
      }
    }
    v16 = v12;
    UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)&this->m_nodes.p[v16], context);
    this->m_nodes.p[v16].m_lastIdx = chosen_idx;
    this->m_nodes.p[v16].m_age = v3;
  }
  else
  {
    v17 = (unsigned int)v8;
    this->m_nodes.p[v17].m_lastIdx = chosen_idx;
    this->m_nodes.p[v17].m_age = v3;
  }
}

