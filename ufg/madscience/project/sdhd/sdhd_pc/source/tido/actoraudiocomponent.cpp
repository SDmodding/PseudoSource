// File Line: 69
// RVA: 0x1559A90
__int64 dynamic_initializer_for__damage_intensity__()
{
  UFG::qWiseSymbol::create_from_string(&damage_intensity_0, "damage_intensity");
  return atexit(dynamic_atexit_destructor_for__damage_intensity__);
}

// File Line: 70
// RVA: 0x155A1C0
__int64 dynamic_initializer_for__medium__()
{
  UFG::qWiseSymbol::create_from_string(&medium_0, "medium");
  return atexit(dynamic_atexit_destructor_for__medium__);
}

// File Line: 90
// RVA: 0x59F3F0
void __fastcall UFG::HandleSubtitleEnd(unsigned int *subtitle)
{
  unsigned int *v1; // rbx
  UFG::UIHKTextOverlay *v2; // rax
  UFG::UIHKTextOverlay *v3; // rax
  UFG::UIHKTextOverlay *v4; // rax

  v1 = subtitle;
  v2 = UFG::UIHKTextOverlay::getInstance();
  if ( UFG::UIHKTextOverlay::GetSubtitleAge(v2, v1[1]) >= UFG::ActorAudioComponent::sm_minSubtitleLifetime )
  {
    v4 = UFG::UIHKTextOverlay::getInstance();
    UFG::UIHKTextOverlay::KillSubtitles(v4, v1[1]);
  }
  else
  {
    v3 = UFG::UIHKTextOverlay::getInstance();
    UFG::UIHKTextOverlay::ChangeSubtitleLifetime(v3, v1[1], UFG::ActorAudioComponent::sm_minSubtitleLifetime);
  }
  *(_QWORD *)v1 = 0i64;
}

// File Line: 118
// RVA: 0x59B450
void __fastcall UFG::SubtitleCallback::Do(UFG::SubtitleCallback *this, UFG::AudioEvent *audioEvent, UFG::eAudioEventCallbackType type)
{
  UFG::AudioEvent *v3; // rbx
  unsigned int v4; // ebx
  unsigned int v5; // eax
  unsigned int v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // eax

  v3 = audioEvent;
  if ( type == 3 )
  {
    if ( UFG::SubtitleCallback::mSubtitle1[0] )
    {
      if ( UFG::SubtitleCallback::mSubtitle2[0] )
      {
        UFG::HandleSubtitleEnd(UFG::SubtitleCallback::mSubtitle1);
        v8 = v3->m_markerCallbackInfo.m_labelHash;
        v9 = UFG::ActorAudioComponent::LookupAndShowSubtitleFromPropertySet(v8);
        if ( !UFG::SubtitleCallback::mSubtitle1[0] && v9 )
        {
          UFG::SubtitleCallback::mSubtitle1[0] = v8;
          dword_14242E4E4 = v9;
        }
      }
      else
      {
        v6 = audioEvent->m_markerCallbackInfo.m_labelHash;
        v7 = UFG::ActorAudioComponent::LookupAndShowSubtitleFromPropertySet(audioEvent->m_markerCallbackInfo.m_labelHash);
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
      v5 = UFG::ActorAudioComponent::LookupAndShowSubtitleFromPropertySet(audioEvent->m_markerCallbackInfo.m_labelHash);
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
  else if ( type == 2 )
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
void __fastcall UFG::AACSubtitleCallback::Do(UFG::AACSubtitleCallback *this, UFG::AudioEvent *audioEvent, UFG::eAudioEventCallbackType type)
{
  UFG::AudioEntity *v3; // rdi
  signed __int64 v4; // rdi
  unsigned int v5; // ebx
  UFG::UIHKTextOverlay *v6; // rax
  float v7; // xmm0_4
  unsigned int v8; // ebx
  UFG::UIHKTextOverlay *v9; // rax
  UFG::UIHKTextOverlay *v10; // rax

  v3 = audioEvent->m_pEntity;
  if ( v3 )
  {
    v4 = (signed __int64)&v3[-1].m_regionCheckFrame;
    if ( v4 )
    {
      if ( type == 3 )
      {
        *(_DWORD *)(v4 + 440) = UFG::ActorAudioComponent::LookupAndShowSubtitleFromPropertySet(audioEvent->m_markerCallbackInfo.m_labelHash);
      }
      else if ( type == 2 )
      {
        v5 = *(_DWORD *)(v4 + 440);
        v6 = UFG::UIHKTextOverlay::getInstance();
        v7 = UFG::UIHKTextOverlay::GetSubtitleAge(v6, v5);
        v8 = *(_DWORD *)(v4 + 440);
        if ( v7 >= UFG::ActorAudioComponent::sm_minSubtitleLifetime )
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
void __fastcall UFG::SpeechControlCallback::Do(UFG::SpeechControlCallback *this, UFG::AudioEvent *audioEvent, UFG::eAudioEventCallbackType type)
{
  UFG::AudioEntity *v3; // rcx
  UFG::AudioEvent *v4; // rbx
  signed __int64 v5; // rcx
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rcx
  UFG::SimComponent *v9; // rax
  float v10; // xmm1_4
  bool v11; // sf
  int v12; // eax
  UFG::SimObjectGame *v13; // r8
  unsigned __int16 v14; // cx
  UFG::DialogueAnimationComponent *v15; // rax
  int v16; // eax

  v3 = audioEvent->m_pEntity;
  v4 = audioEvent;
  if ( v3 )
  {
    v5 = (signed __int64)&v3[-1].m_regionCheckFrame;
    if ( v5 )
    {
      if ( type == 3 )
      {
        v6 = *(UFG::SimObjectGame **)(v5 + 40);
        if ( v6 )
        {
          v7 = v6->m_Flags;
          if ( (v7 >> 14) & 1 )
          {
            v8 = v6->m_Components.p[41].m_pComponent;
          }
          else
          {
            if ( (v7 & 0x8000u) == 0 )
            {
              if ( (v7 >> 13) & 1 )
              {
                v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::DialogueAnimationComponent::_TypeUID);
              }
              else if ( (v7 >> 12) & 1 )
              {
                v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::DialogueAnimationComponent::_TypeUID);
              }
              else
              {
                v9 = UFG::SimObject::GetComponentOfType(
                       (UFG::SimObject *)&v6->vfptr,
                       UFG::DialogueAnimationComponent::_TypeUID);
              }
            }
            else
            {
              v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::DialogueAnimationComponent::_TypeUID);
            }
            v8 = v9;
          }
          if ( v8 && v4->m_markerCallbackInfo.m_labelHash )
          {
            v10 = v4->m_markerCallbackInfo.m_floatParameter;
            if ( v10 > 0.0 )
            {
              *(float *)&v8[1].m_NameUID = v10;
              v8[1].m_TypeUID = v4->m_markerCallbackInfo.m_labelHash;
            }
          }
        }
      }
      else if ( type == 2 )
      {
        v11 = (*(_DWORD *)(v5 + 444))-- - 1 < 0;
        v12 = *(_DWORD *)(v5 + 444);
        v13 = *(UFG::SimObjectGame **)(v5 + 40);
        if ( v11 )
          v12 = 0;
        *(_DWORD *)(v5 + 444) = v12;
        if ( v13 )
        {
          v14 = v13->m_Flags;
          if ( (v14 >> 14) & 1 )
          {
            v15 = (UFG::DialogueAnimationComponent *)v13->m_Components.p[41].m_pComponent;
          }
          else if ( (v14 & 0x8000u) == 0 )
          {
            if ( (v14 >> 13) & 1 )
              v15 = (UFG::DialogueAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v13,
                                                         UFG::DialogueAnimationComponent::_TypeUID);
            else
              v15 = (UFG::DialogueAnimationComponent *)((v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            v13,
                                                                            UFG::DialogueAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::DialogueAnimationComponent::_TypeUID));
          }
          else
          {
            v15 = (UFG::DialogueAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v13,
                                                       UFG::DialogueAnimationComponent::_TypeUID);
          }
          if ( v15 )
            UFG::DialogueAnimationComponent::Stop(v15);
        }
      }
      else if ( type )
      {
        if ( type == 1 )
        {
          v11 = (*(_DWORD *)(v5 + 444))-- - 1 < 0;
          if ( v11 )
            *(_DWORD *)(v5 + 444) = 0;
        }
        else
        {
          v11 = (*(_DWORD *)(v5 + 444))-- - 1 < 0;
          v16 = *(_DWORD *)(v5 + 444);
          if ( v11 )
            v16 = 0;
          *(_DWORD *)(v5 + 444) = v16;
        }
      }
    }
  }
}

// File Line: 324
// RVA: 0x1554CD0
__int64 dynamic_initializer_for__UFG::ActorAudioComponent::sm_dlgStateManager__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ActorAudioComponent::sm_dlgStateManager__);
}

// File Line: 339
// RVA: 0x1554AA0
__int64 dynamic_initializer_for__UFG::ActorAudioComponent::s_ActorAudioComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ActorAudioComponent::s_ActorAudioComponentList__);
}

// File Line: 340
// RVA: 0x59D740
signed __int64 __fastcall UFG::qReflectInventory<UFG::Editor::PrefabWindow>::GetClassSize(UFG::qReflectInventory<UFG::Editor::PrefabWindow> *this)
{
  return 560i64;
}

// File Line: 351
// RVA: 0x592920
void __fastcall UFG::ActorAudioComponent::ActorAudioComponent(UFG::ActorAudioComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::ActorAudioComponent *v2; // rsi
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *v3; // rdi
  UFG::AmbientContextManager *v4; // rbx
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *v5; // rax
  UFG::SimObjectCharacter *v6; // rbx
  unsigned int v7; // eax
  UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent> *v8; // [rsp+58h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v9; // [rsp+58h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *v10; // [rsp+58h] [rbp+10h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, pSceneObj->m_NameUID);
  UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)&v2->vfptr);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HkAudioEntityComponent::`vftable'{for `UFG::SimComponent'};
  v2->vfptr = (UFG::AudioEntityVtbl *)&UFG::HkAudioEntityComponent::`vftable'{for `UFG::AudioEntity'};
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::HkAudioEntityComponent::_HkAudioEntityComponentTypeUID,
    "HkAudioEntityComponent");
  v3 = (UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActorAudioComponent::`vftable'{for `UFG::SimComponent'};
  v2->vfptr = (UFG::AudioEntityVtbl *)&UFG::ActorAudioComponent::`vftable'{for `UFG::AudioEntity'};
  v2->m_controller.m_pEvent = 0i64;
  v2->m_SFXEntity = 0i64;
  v2->m_activeAmbientConversationId = 0;
  v2->m_leftFootstep.m_pOneShot = 0i64;
  v2->m_rightFootstep.m_pOneShot = 0i64;
  v4 = &v2->m_ambientContexts;
  v4->m_nodes.p = 0i64;
  *(_QWORD *)&v4->m_nodes.size = 0i64;
  UFG::qArray<UFG::AmbientContextNode,0>::Reallocate(
    &v2->m_ambientContexts.m_nodes,
    2u,
    "qArray.Reallocate(Constructor)");
  v4->m_nodes.size = 2;
  v8 = &v2->m_healthComponent;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v2->m_healthComponent.m_pPointer = 0i64;
  v9 = &v2->m_transformNodeComponent;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v2->m_transformNodeComponent.m_pPointer = 0i64;
  v10 = &v2->m_simObjectCharacterPropertiesComponent;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v2->m_simObjectCharacterPropertiesComponent.m_pPointer = 0i64;
  v5 = UFG::ActorAudioComponent::s_ActorAudioComponentList.mNode.mPrev;
  UFG::ActorAudioComponent::s_ActorAudioComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *)&v2->mPrev;
  v3->mPrev = v5;
  v2->mNext = (UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *)&UFG::ActorAudioComponent::s_ActorAudioComponentList;
  UFG::ActorAudioComponent::s_ActorAudioComponentList.mNode.mPrev = (UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::ActorAudioComponent::_ActorAudioComponentTypeUID,
    "ActorAudioComponent");
  UFG::ActorAudioComponent::ClearDataMembers(v2);
  v6 = (UFG::SimObjectCharacter *)v2->m_pSimObject;
  if ( v6 == UFG::GetLocalPlayer() )
    *((_BYTE *)v2 + 0x229) |= 8u;
  if ( !UFG::ActorAudioComponent::sm_copConfigPs )
  {
    if ( !(_S16_4 & 1) )
    {
      _S16_4 |= 1u;
      v7 = UFG::qStringHash32("audio-copaudiocomponent", 0xFFFFFFFF);
      UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&copAudioComponentPsName, v7);
      atexit(UFG::ActorAudioComponent::ActorAudioComponent_::_5_::_dynamic_atexit_destructor_for__copAudioComponentPsName__);
    }
    UFG::ActorAudioComponent::sm_copConfigPs = UFG::PropertySetManager::CreateOrFindPropertySet((UFG::qSymbol *)&copAudioComponentPsName.mUID);
  }
}

// File Line: 382
// RVA: 0x593A70
void __fastcall UFG::ActorAudioComponent::~ActorAudioComponent(UFG::ActorAudioComponent *this)
{
  UFG::ActorAudioComponent *v1; // rbx
  UFG::AudioEntity *v2; // rcx
  UFG::AudioEntity *v3; // rcx
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *v4; // rdi
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *v5; // rcx
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::AudioEvent *v22; // rcx
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *v23; // rdx
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *v24; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActorAudioComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::ActorAudioComponent::`vftable'{for `UFG::AudioEntity'};
  UFG::ActorAudioComponent::ClearDataMembers(this);
  v2 = v1->m_SFXEntity;
  if ( v2 )
  {
    UFG::AudioEntity::Shutdown(v2);
    v3 = v1->m_SFXEntity;
    if ( v3 )
      v3->vfptr->__vecDelDtor(v3, 1u);
    v1->m_SFXEntity = 0i64;
  }
  if ( v1 == UFG::ActorAudioComponent::s_ActorAudioComponentpCurrentIterator )
    UFG::ActorAudioComponent::s_ActorAudioComponentpCurrentIterator = (UFG::ActorAudioComponent *)&v1->mPrev[-24];
  v4 = (UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *)&v1->mPrev;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mPrev = v4;
  v4->mNext = v4;
  v7 = &v1->m_simObjectCharacterPropertiesComponent;
  if ( v1->m_simObjectCharacterPropertiesComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_simObjectCharacterPropertiesComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_simObjectCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_simObjectCharacterPropertiesComponent.mPrev;
  }
  v1->m_simObjectCharacterPropertiesComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_simObjectCharacterPropertiesComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_simObjectCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_simObjectCharacterPropertiesComponent.mPrev;
  v12 = &v1->m_transformNodeComponent;
  if ( v1->m_transformNodeComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_transformNodeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_transformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_transformNodeComponent.mPrev;
  }
  v1->m_transformNodeComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_transformNodeComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_transformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_transformNodeComponent.mPrev;
  v17 = &v1->m_healthComponent;
  if ( v1->m_healthComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->m_healthComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->m_healthComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_healthComponent.mPrev;
  }
  v1->m_healthComponent.m_pPointer = 0i64;
  v20 = v17->mPrev;
  v21 = v1->m_healthComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v1->m_healthComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_healthComponent.mPrev;
  UFG::AmbientContextManager::~AmbientContextManager(&v1->m_ambientContexts);
  UFG::OneShotHandle::Release(&v1->m_rightFootstep);
  UFG::OneShotHandle::Release(&v1->m_leftFootstep);
  v22 = v1->m_controller.m_pEvent;
  if ( v22 )
    UFG::AudioEvent::OnControllerDestroy(v22);
  v23 = v4->mPrev;
  v24 = v1->mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  v4->mPrev = v4;
  v1->mNext = (UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *)&v1->mPrev;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HkAudioEntityComponent::`vftable'{for `UFG::SimComponent'};
  v1->vfptr = (UFG::AudioEntityVtbl *)&UFG::HkAudioEntityComponent::`vftable'{for `UFG::AudioEntity'};
  UFG::AudioEntity::~AudioEntity((UFG::AudioEntity *)&v1->vfptr);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 399
// RVA: 0x598A20
void __fastcall UFG::ActorAudioComponent::ClearDataMembers(UFG::ActorAudioComponent *this)
{
  unsigned int v1; // edx
  UFG::ActorAudioComponent *v2; // rbx
  UFG::qBaseTreeRB *v3; // rax
  _BOOL8 v4; // rdx
  UFG::AudioEvent *v5; // rax
  unsigned int v6; // edi
  UFG::TiDo *v7; // rax
  UFG::AudioEntity *v8; // rcx
  UFG::AudioEntity *v9; // rcx
  unsigned int v10; // edx

  v1 = this->m_activeAmbientConversationId;
  v2 = this;
  if ( v1 )
  {
    v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v1);
    if ( v3 )
    {
      if ( v3 != (UFG::qBaseTreeRB *)8 )
        UFG::Conversation::ForceFinish((UFG::Conversation *)&v3[-1].mCount, v4);
    }
  }
  v5 = v2->m_controller.m_pEvent;
  v2->m_activeAmbientConversationId = 0;
  if ( v5 )
  {
    v6 = v5->m_uPlayingId;
    v5->m_pController = 0i64;
    v2->m_controller.m_pEvent = 0i64;
    if ( v6 )
    {
      v7 = UFG::TiDo::GetInstance();
      UFG::TiDo::StopPlaying(v7, v6);
    }
  }
  v8 = v2->m_SFXEntity;
  if ( v8 )
  {
    UFG::AudioEntity::Shutdown(v8);
    v9 = v2->m_SFXEntity;
    if ( v9 )
      v9->vfptr->__vecDelDtor(v9, 1u);
    v2->m_SFXEntity = 0i64;
  }
  *((_BYTE *)v2 + 553) &= 0xC0u;
  v10 = effect_possessed_bypass;
  *((_BYTE *)v2 + 553) |= 0x40u;
  *((_BYTE *)v2 + 554) &= 0xFEu;
  *(_QWORD *)&v2->m_curPlayingPriority = 0i64;
  *(_QWORD *)&v2->m_subtitleId = 0i64;
  *((_BYTE *)v2 + 552) = 56;
  v2->m_voiceProfile = 0i64;
  v2->m_distance2ToListener = 0.0;
  UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v2->vfptr, v10, 0.94999999);
}

// File Line: 481
// RVA: 0x5AEAF0
void __fastcall UFG::ActorAudioComponent::Update(UFG::ActorAudioComponent *this, float delta_sec)
{
  UFG::ActorAudioComponent *v2; // rdi
  float v3; // xmm7_4
  UFG::SimComponent *v4; // rbx
  UFG::SimComponent *v5; // rax
  char v6; // dl
  char v7; // cl
  float v8; // xmm2_4
  UFG::SimComponent *v9; // rbx
  UFG::AudioEntity *v10; // rcx
  UFG::qVector4 v11; // xmm3
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::SimComponent *v14; // rbx
  UFG::AudioEntity *v15; // rcx
  UFG::qVector4 v16; // xmm3
  UFG::qVector4 v17; // xmm2
  UFG::qVector4 v18; // xmm1
  UFG::SimComponent *v19; // rbx
  UFG::OneShot *v20; // rcx
  UFG::qVector4 v21; // xmm3
  UFG::qVector4 v22; // xmm2
  UFG::qVector4 v23; // xmm1
  UFG::SimComponent *v24; // rbx
  UFG::OneShot *v25; // rcx
  UFG::qVector4 v26; // xmm3
  UFG::qVector4 v27; // xmm2
  UFG::qVector4 v28; // xmm1
  bool v29; // al
  bool v30; // cl
  UFG::HealthComponent *v31; // rcx
  signed int v32; // esi
  unsigned __int8 v33; // al
  unsigned __int8 v34; // bl
  bool v35; // cl
  float v36; // xmm1_4

  v2 = this;
  v3 = delta_sec;
  if ( UFG::AudioListener::sm_pInstance )
  {
    v4 = this->m_transformNodeComponent.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_transformNodeComponent.m_pPointer);
    v2->m_distance2ToListener = UFG::AudioListener::GetDistance2From(
                                  UFG::AudioListener::sm_pInstance,
                                  (UFG::qVector3 *)&v4[2].m_BoundComponentHandles);
  }
  UFG::ActorAudioComponent::CheckInitialize(v2);
  if ( v2->m_bIsInitialized )
  {
    v5 = v2->m_simObjectCharacterPropertiesComponent.m_pPointer;
    if ( v5 )
    {
      v6 = *((_BYTE *)v2 + 554);
      v7 = (_QWORD)v5[3].m_BoundComponentHandles.mNode.mNext & 1;
      if ( (v6 & 1) != v7 )
      {
        *((_BYTE *)v2 + 554) = v6 ^ (v7 ^ v6) & 1;
        if ( v7 )
          v8 = FLOAT_0_050000001;
        else
          v8 = FLOAT_0_94999999;
        UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v2->vfptr, effect_possessed_bypass, v8);
      }
    }
    v9 = v2->m_transformNodeComponent.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_transformNodeComponent.m_pPointer);
    v10 = (UFG::AudioEntity *)&v2->vfptr;
    v11 = *(UFG::qVector4 *)&v9[2].m_SafePointerList.mNode.mNext;
    v12 = *(UFG::qVector4 *)&v9[2].m_Flags;
    v13 = (UFG::qVector4)v9[2].m_BoundComponentHandles;
    v10->m_WorldMatrix.v0 = *(UFG::qVector4 *)&v9[2].vfptr;
    v10->m_WorldMatrix.v1 = v11;
    v10->m_WorldMatrix.v2 = v12;
    v10->m_WorldMatrix.v3 = v13;
    UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&v2->vfptr);
    if ( v2->m_SFXEntity )
    {
      v14 = v2->m_transformNodeComponent.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_transformNodeComponent.m_pPointer);
      v15 = v2->m_SFXEntity;
      v16 = *(UFG::qVector4 *)&v14[2].m_SafePointerList.mNode.mNext;
      v17 = *(UFG::qVector4 *)&v14[2].m_Flags;
      v18 = (UFG::qVector4)v14[2].m_BoundComponentHandles;
      v15->m_WorldMatrix.v0 = *(UFG::qVector4 *)&v14[2].vfptr;
      v15->m_WorldMatrix.v1 = v16;
      v15->m_WorldMatrix.v2 = v17;
      v15->m_WorldMatrix.v3 = v18;
      UFG::AudioEntity::ForcePositionUpdate(v15);
    }
    if ( UFG::OneShotHandle::IsValid(&v2->m_leftFootstep) )
    {
      v19 = v2->m_transformNodeComponent.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_transformNodeComponent.m_pPointer);
      v20 = v2->m_leftFootstep.m_pOneShot;
      v21 = *(UFG::qVector4 *)&v19[2].m_SafePointerList.mNode.mNext;
      v22 = *(UFG::qVector4 *)&v19[2].m_Flags;
      v23 = (UFG::qVector4)v19[2].m_BoundComponentHandles;
      v20->m_WorldMatrix.v0 = *(UFG::qVector4 *)&v19[2].vfptr;
      v20->m_WorldMatrix.v1 = v21;
      v20->m_WorldMatrix.v2 = v22;
      v20->m_WorldMatrix.v3 = v23;
      UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&v20->vfptr);
    }
    if ( UFG::OneShotHandle::IsValid(&v2->m_rightFootstep) )
    {
      v24 = v2->m_transformNodeComponent.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_transformNodeComponent.m_pPointer);
      v25 = v2->m_rightFootstep.m_pOneShot;
      v26 = *(UFG::qVector4 *)&v24[2].m_SafePointerList.mNode.mNext;
      v27 = *(UFG::qVector4 *)&v24[2].m_Flags;
      v28 = (UFG::qVector4)v24[2].m_BoundComponentHandles;
      v25->m_WorldMatrix.v0 = *(UFG::qVector4 *)&v24[2].vfptr;
      v25->m_WorldMatrix.v1 = v26;
      v25->m_WorldMatrix.v2 = v27;
      v25->m_WorldMatrix.v3 = v28;
      UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&v25->vfptr);
    }
    UFG::ActorAudioComponent::UpdateAmbienceCounts(v2);
    if ( *((_BYTE *)v2 + 553) & 8 )
    {
      if ( !underwater )
      {
        if ( UFG::ActorAudioComponent::IsInWater(v2, 1.5) )
        {
          underwater = 1;
          goto LABEL_24;
        }
        if ( !underwater )
        {
LABEL_24:
          UFG::FacialActionTreeComponent::sDisableFacialAnimationUpdate = (*((_BYTE *)v2 + 553) >> 2) & 1;
          v31 = (UFG::HealthComponent *)v2->m_healthComponent.m_pPointer;
          if ( v31 )
          {
            v32 = (signed int)v31->m_fHealth;
            v33 = UFG::HealthComponent::GetIsKilled(v31);
            v34 = v33;
            if ( v32 >= 75 || v33 )
            {
              v35 = heart_beat_on;
              if ( heart_beat_on )
              {
                UFG::AudioEntity::CreateAndPlayEvent(
                  (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
                  0x711B5A3Bu,
                  0i64,
                  0,
                  0i64);
                v35 = 0;
                heart_beat_on = 0;
              }
            }
            else
            {
              v35 = heart_beat_on;
            }
            if ( v32 <= 70 && !v35 && !v34 )
            {
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
                0x5C176D09u,
                0i64,
                0,
                0i64);
              heart_beat_on = 1;
            }
          }
          goto LABEL_34;
        }
      }
      v29 = UFG::ActorAudioComponent::IsInWater(v2, 1.5);
      v30 = underwater;
      if ( !v29 )
        v30 = 0;
      underwater = v30;
      goto LABEL_24;
    }
  }
LABEL_34:
  if ( !v2->m_bIsInitialized )
  {
    v36 = v2->m_interiorCheckTimer - v3;
    v2->m_interiorCheckTimer = v36;
    if ( v36 <= 0.0 )
    {
      UFG::AudioTriggerRegion::CheckEntity((UFG::AudioEntity *)&v2->vfptr);
      v2->m_interiorCheckTimer = UFG::qRandom(5.0, &UFG::qDefaultSeed) + 50.0;
    }
  }
}

// File Line: 614
// RVA: 0x597C50
void __fastcall UFG::ActorAudioComponent::CheckInitialize(UFG::ActorAudioComponent *this)
{
  UFG::ActorAudioComponent *v1; // rdi
  float v2; // xmm0_4
  bool v3; // al
  UFG::SimComponent *v4; // rcx
  bool v5; // cl
  bool v6; // dl
  unsigned int v7; // eax
  const char *v8; // rax
  UFG::VoiceProfile *v9; // rcx
  UFG::allocator::free_link *v10; // rax
  char *v11; // rax
  char v12; // al
  UFG::VoiceProfile *v13; // rcx
  UFG::AudioEntity *v14; // rcx
  UFG::AudioEntity *v15; // rcx
  char dest; // [rsp+30h] [rbp-108h]
  UFG::qWiseSymbol result; // [rsp+140h] [rbp+8h]
  UFG::qSymbol v18; // [rsp+148h] [rbp+10h]
  UFG::allocator::free_link *v19; // [rsp+150h] [rbp+18h]

  v1 = this;
  if ( *((_BYTE *)this + 0x229) & 8 )
  {
    v2 = FLOAT_90000_0;
  }
  else if ( *((_BYTE *)this + 0x228) & 0x20 )
  {
    v2 = FLOAT_1225_0;
  }
  else
  {
    v2 = FLOAT_4225_0;
  }
  v3 = v2 > this->m_distance2ToListener || *((_BYTE *)this + 552) & 0x40;
  v4 = this->m_healthComponent.m_pPointer;
  if ( v4 && BYTE4(v4[1].m_BoundComponentHandles.mNode.mPrev) )
    v5 = (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&v4[3].m_pSimObject) < 2.0;
  else
    v5 = 1;
  v6 = v1->m_isSpeakingCnt > 0 && v1->m_controller.m_pEvent;
  if ( v1->m_bIsInitialized )
  {
    if ( !v3 || !v5 && !v6 || (v12 = *((_BYTE *)v1 + 552), v12 < 0) && !(v12 & 0x40) )
    {
      v13 = v1->m_voiceProfile;
      if ( v13 && UFG::VoiceProfile::BankRequiredForExertions(v13) )
        UFG::TiDo::UnloadWwiseBank(&v1->m_voiceProfile->m_wwiseTagsUid);
      UFG::AudioEntity::ClearContainmentInfo((UFG::AudioEntity *)&v1->vfptr);
      UFG::AudioEntity::ClearEnvironments((UFG::AudioEntity *)&v1->vfptr, 0);
      UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&v1->vfptr);
      v14 = v1->m_SFXEntity;
      if ( v14 )
      {
        UFG::AudioEntity::Shutdown(v14);
        v15 = v1->m_SFXEntity;
        if ( v15 )
          v15->vfptr->__vecDelDtor(v15, 1u);
        v1->m_SFXEntity = 0i64;
      }
    }
  }
  else if ( v3 && v5 && *((_BYTE *)v1 + 552) >= 0 || *((_BYTE *)v1 + 552) & 0x40 )
  {
    (*(void (__fastcall **)(UFG::AudioEntityVtbl **, UFG::qSymbol *, UFG::qMatrix44 *))v1->vfptr->gap8)(
      &v1->vfptr,
      &v1->m_pSimObject->m_Name,
      &UFG::qMatrix44::msIdentity);
    if ( _S17_5 & 1 )
    {
      v7 = effect_in_trunk;
    }
    else
    {
      _S17_5 |= 1u;
      v7 = UFG::TiDo::CalcWwiseUid("Effect_in_trunk");
      effect_in_trunk = v7;
    }
    UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v1->vfptr, v7, 0.0);
    UFG::ActorAudioComponent::GetVoiceProfile(v1, &result, 0i64);
    if ( UFG::TidoGame::sm_dialogueTrace )
    {
      v8 = UFG::qWiseSymbol::as_cstr_dbg(&result);
      UFG::qPrintf("Assigning voice: %s\n", v8);
    }
    v1->m_bIsDopplerEnabled = 0;
    v9 = v1->m_voiceProfile;
    if ( v9 && UFG::VoiceProfile::BankRequiredForExertions(v9) )
      UFG::TiDo::LoadWwiseBank(&v1->m_voiceProfile->m_wwiseTagsUid);
    v10 = UFG::qMalloc(0x140ui64, "ActorAudioComponent.SFXEntity", 0i64);
    v19 = v10;
    if ( v10 )
      UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)v10);
    v1->m_SFXEntity = (UFG::AudioEntity *)v10;
    v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1->m_pSimObject->m_Name);
    UFG::qSPrintf(&dest, "%s__SFX", v11);
    UFG::qSymbol::create_from_string(&v18, &dest);
    (*(void (__fastcall **)(UFG::AudioEntity *, UFG::qSymbol *, UFG::qMatrix44 *))v1->m_SFXEntity->vfptr->gap8)(
      v1->m_SFXEntity,
      &v18,
      &UFG::qMatrix44::msIdentity);
    UFG::AudioEntity::SetWwiseSwitch(v1->m_SFXEntity, damage_intensity.mUID, medium.mUID);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 719
// RVA: 0x59B0E0
float __fastcall UFG::ActorAudioComponent::Distance2ToActor(UFG::ActorAudioComponent *this, UFG::ActorAudioComponent *target)
{
  float result; // xmm0_4

  if ( target )
    result = (float)((float)((float)(target->m_WorldMatrix.v3.y - this->m_WorldMatrix.v3.y)
                           * (float)(target->m_WorldMatrix.v3.y - this->m_WorldMatrix.v3.y))
                   + (float)((float)(target->m_WorldMatrix.v3.x - this->m_WorldMatrix.v3.x)
                           * (float)(target->m_WorldMatrix.v3.x - this->m_WorldMatrix.v3.x)))
           + (float)((float)(target->m_WorldMatrix.v3.z - this->m_WorldMatrix.v3.z)
                   * (float)(target->m_WorldMatrix.v3.z - this->m_WorldMatrix.v3.z));
  else
    result = FLOAT_N1_0;
  return result;
}

// File Line: 732
// RVA: 0x5AFAA0
void __fastcall UFG::ActorAudioComponent::UpdateAmbienceCounts(UFG::ActorAudioComponent *this)
{
  UFG::ActorAudioComponent *v1; // rdi
  UFG::SimComponent *v2; // rax
  float v3; // xmm0_4
  UFG::SimComponent *v4; // rbx
  float v5; // xmm0_4
  char v6; // al

  v1 = this;
  v2 = this->m_healthComponent.m_pPointer;
  if ( !v2
    || !BYTE4(v2[1].m_BoundComponentHandles.mNode.mPrev)
    || (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&v2[3].m_pSimObject) < 2.0 )
  {
    UFG::ActorAudioComponent::sm_numActivePeds = UFG::ActorAudioComponent::sm_numActivePeds + 1.0;
    if ( !(_S18_5 & 1) )
    {
      _S18_5 |= 1u;
      pedProximity = UFG::ActorAudioComponent::sm_nearbyPedProximity * UFG::ActorAudioComponent::sm_nearbyPedProximity;
    }
    v3 = this->m_distance2ToListener;
    if ( v3 <= 0.000099999997 || v3 >= pedProximity || !(*((_BYTE *)this + 552) & 0x20) || *((_BYTE *)this + 553) & 4 )
    {
      *((_BYTE *)this + 552) &= 0xFBu;
    }
    else
    {
      v4 = this->m_transformNodeComponent.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_transformNodeComponent.m_pPointer);
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                          *(float *)&v4[2].m_BoundComponentHandles.mNode.mNext
                        - UFG::AudioListener::sm_pInstance->m_triggerPosition.z) & _xmm) < UFG::ActorAudioComponent::sm_nearbyPedProximityVertical )
      {
        UFG::ActorAudioComponent::sm_numNearbyPeds = UFG::ActorAudioComponent::sm_numNearbyPeds + 1.0;
        *((_BYTE *)v1 + 552) |= 4u;
        if ( v1->m_interiorCount )
          UFG::ActorAudioComponent::sm_numIndoorPeds = UFG::ActorAudioComponent::sm_numIndoorPeds + 1.0;
        else
          UFG::ActorAudioComponent::sm_numOutdoorPeds = UFG::ActorAudioComponent::sm_numOutdoorPeds + 1.0;
      }
    }
    if ( *((_BYTE *)v1 + 553) & 4 )
      UFG::ActorAudioComponent::sm_numInCarPeds = UFG::ActorAudioComponent::sm_numInCarPeds + 1.0;
    v5 = v1->m_distance2ToListener;
    if ( v5 > 0.000099999997 && v5 < pedProximity && !(*((_BYTE *)v1 + 552) & 0x20) )
    {
      v6 = *((_BYTE *)v1 + 553);
      if ( !(v6 & 4) && !(v6 & 8) )
        UFG::ActorAudioComponent::sm_numNearbyNonAmbientPeds = UFG::ActorAudioComponent::sm_numNearbyNonAmbientPeds
                                                             + 1.0;
    }
  }
}

// File Line: 785
// RVA: 0x5A03C0
bool __fastcall UFG::ActorAudioComponent::IsAlive(UFG::ActorAudioComponent *this, bool instant)
{
  UFG::SimComponent *v2; // rax

  v2 = this->m_healthComponent.m_pPointer;
  if ( !v2 || !BYTE4(v2[1].m_BoundComponentHandles.mNode.mPrev) )
    return 1;
  if ( instant )
    return 0;
  return (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&v2[3].m_pSimObject) < 2.0;
}

// File Line: 809
// RVA: 0x5A36F0
void __fastcall UFG::ActorAudioComponent::OnAttach(UFG::ActorAudioComponent *this, UFG::SimObject *object)
{
  UFG::ActorAudioComponent *v2; // rsi
  UFG::SimObjectCVBase *v3; // rbx
  bool v4; // al
  UFG::SimObjectCharacterPropertiesComponent *v5; // rdi
  UFG::SimComponent *v6; // r8
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::TransformNodeComponent *v13; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  unsigned __int16 v18; // cx
  UFG::SimObjectCharacterPropertiesComponent *v19; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  float v24; // xmm1_4

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)object;
  v4 = UFG::TidoGame::CharacterIsAmbientPed(object);
  *((_BYTE *)v2 + 552) &= 0xDFu;
  v5 = 0i64;
  *((_BYTE *)v2 + 552) |= 32 * v4;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[6].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::HealthComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::HealthComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HealthComponent::_TypeUID);
      }
      v6 = v8;
    }
    else
    {
      v6 = v3->m_Components.p[6].m_pComponent;
    }
  }
  else
  {
    v6 = 0i64;
  }
  v9 = &v2->m_healthComponent;
  if ( v2->m_healthComponent.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v2->m_healthComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v2->m_healthComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_healthComponent.mPrev;
  }
  v2->m_healthComponent.m_pPointer = v6;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v12;
    v2->m_healthComponent.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  v13 = 0i64;
  if ( v3 )
    v13 = v3->m_pTransformNodeComponent;
  v14 = &v2->m_transformNodeComponent;
  if ( v2->m_transformNodeComponent.m_pPointer )
  {
    v15 = v14->mPrev;
    v16 = v2->m_transformNodeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
    v2->m_transformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_transformNodeComponent.mPrev;
  }
  v2->m_transformNodeComponent.m_pPointer = (UFG::SimComponent *)&v13->vfptr;
  if ( v13 )
  {
    v17 = v13->m_SafePointerList.mNode.mPrev;
    v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
    v14->mPrev = v17;
    v2->m_transformNodeComponent.mNext = &v13->m_SafePointerList.mNode;
    v13->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  }
  if ( v3 )
  {
    v18 = v3->m_Flags;
    if ( (v18 >> 14) & 1 )
    {
      v19 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
    }
    else if ( (v18 & 0x8000u) == 0 )
    {
      if ( (v18 >> 13) & 1 )
      {
        v19 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)&v3->vfptr,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else if ( (v18 >> 12) & 1 )
      {
        v19 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)&v3->vfptr,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        v19 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                              (UFG::SimObject *)&v3->vfptr,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v19 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
    }
    v5 = v19;
  }
  v20 = &v2->m_simObjectCharacterPropertiesComponent;
  if ( v2->m_simObjectCharacterPropertiesComponent.m_pPointer )
  {
    v21 = v20->mPrev;
    v22 = v2->m_simObjectCharacterPropertiesComponent.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->mPrev;
    v2->m_simObjectCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_simObjectCharacterPropertiesComponent.mPrev;
  }
  v2->m_simObjectCharacterPropertiesComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
  if ( v5 )
  {
    v23 = v5->m_SafePointerList.mNode.mPrev;
    v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->mPrev;
    v20->mPrev = v23;
    v2->m_simObjectCharacterPropertiesComponent.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->mPrev;
  }
  if ( !v2->m_bIsInitialized )
  {
    v24 = v2->m_interiorCheckTimer - 99999.0;
    v2->m_interiorCheckTimer = v24;
    if ( v24 <= 0.0 )
    {
      UFG::AudioTriggerRegion::CheckEntity((UFG::AudioEntity *)&v2->vfptr);
      v2->m_interiorCheckTimer = UFG::qRandom(5.0, &UFG::qDefaultSeed) + 50.0;
    }
  }
}

// File Line: 825
// RVA: 0x5AA3F0
void __fastcall UFG::ActorAudioComponent::Reset(UFG::ActorAudioComponent *this)
{
  UFG::ActorAudioComponent *v1; // rdi
  UFG::SimObjectCharacter *v2; // rbx
  bool v3; // al
  float v4; // xmm1_4

  v1 = this;
  UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&this->vfptr);
  UFG::ActorAudioComponent::ClearDataMembers(v1);
  v2 = (UFG::SimObjectCharacter *)v1->m_pSimObject;
  if ( v2 == UFG::GetLocalPlayer() )
    *((_BYTE *)v1 + 553) |= 8u;
  v3 = UFG::TidoGame::CharacterIsAmbientPed(v1->m_pSimObject);
  *((_BYTE *)v1 + 552) &= 0xDFu;
  *((_BYTE *)v1 + 552) |= 32 * v3;
  if ( !v1->m_bIsInitialized )
  {
    v4 = v1->m_interiorCheckTimer - 999999.0;
    v1->m_interiorCheckTimer = v4;
    if ( v4 <= 0.0 )
    {
      UFG::AudioTriggerRegion::CheckEntity((UFG::AudioEntity *)&v1->vfptr);
      v1->m_interiorCheckTimer = UFG::qRandom(5.0, &UFG::qDefaultSeed) + 50.0;
    }
  }
}

// File Line: 840
// RVA: 0x5ACC40
void __fastcall UFG::ActorAudioComponent::TeleportEventHandler(UFG::ActorAudioComponent *this, UFG::Event *this_event)
{
  UFG::ActorAudioComponent *v2; // rbx
  float v3; // xmm1_4

  v2 = this;
  if ( !this->m_bIsInitialized )
  {
    v3 = this->m_interiorCheckTimer - 999999.0;
    this->m_interiorCheckTimer = v3;
    if ( v3 <= 0.0 )
    {
      UFG::AudioTriggerRegion::CheckEntity((UFG::AudioEntity *)&this->vfptr);
      v2->m_interiorCheckTimer = UFG::qRandom(5.0, &UFG::qDefaultSeed) + 50.0;
    }
  }
}

// File Line: 857
// RVA: 0x5A39F0
void __fastcall UFG::ActorAudioComponent::OnDetach(UFG::ActorAudioComponent *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent> *v1; // r8
  UFG::ActorAudioComponent *v2; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = &this->m_healthComponent;
  v2 = this;
  if ( this->m_healthComponent.m_pPointer )
  {
    v3 = v1->mPrev;
    v4 = this->m_healthComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    this->m_healthComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_healthComponent.mPrev;
  }
  v5 = &this->m_transformNodeComponent;
  this->m_healthComponent.m_pPointer = 0i64;
  if ( this->m_transformNodeComponent.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v5->m_pPointer = 0i64;
  UFG::ActorAudioComponent::ClearDataMembers(v2);
  UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&v2->vfptr);
}

// File Line: 878
// RVA: 0x59DAD0
UFG::qWiseSymbol *__fastcall UFG::ActorAudioComponent::GetVoiceProfile(UFG::ActorAudioComponent *this, UFG::qWiseSymbol *result, UFG::SimObject *target)
{
  UFG::qWiseSymbol *v3; // rdi
  UFG::ActorAudioComponent *v4; // rbx
  char *v5; // rax
  signed int v6; // eax
  float v7; // xmm6_4
  UFG::SimComponent *v8; // rax
  char v9; // cl
  unsigned __int16 v10; // cx
  UFG::ActorAudioComponent *v11; // rax
  AMD_HD3D *v12; // rcx
  UFG::VoiceProfile *v13; // rax
  char *v14; // rax
  AMD_HD3D *v15; // rcx

  v3 = result;
  v4 = this;
  if ( !this->m_voiceProfile )
  {
    if ( !target )
    {
      if ( !(unsigned __int8)UFG::TidoGame::GetVoiceId(this->m_pSimObject, &this->m_voiceProfile) )
      {
        v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->m_pSimObject->m_Name);
        UFG::qPrintf("WARNING: Could not assign voice to: '%s'  \n", v5);
      }
      *((_BYTE *)v4 + 553) ^= (*((_BYTE *)v4 + 553) ^ ((UFG::IsFemale(v4->m_pSimObject) == 0) << 6)) & 0x40;
      if ( !(*((_BYTE *)v4 + 553) & 0x40) )
      {
        v6 = UFG::qRandom(2, &UFG::qDefaultSeed);
        *((_BYTE *)v4 + 0x229) &= 0x7Fu;
        *((_BYTE *)v4 + 0x229) |= (v6 >= 1) << 7;
      }
      *((_BYTE *)v4 + 554) &= 0xFEu;
      v7 = FLOAT_0_94999999;
      UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v4->vfptr, effect_possessed_bypass, 0.94999999);
      v8 = v4->m_simObjectCharacterPropertiesComponent.m_pPointer;
      if ( v8 )
      {
        v9 = (_QWORD)v8[3].m_BoundComponentHandles.mNode.mNext & 1;
        *((_BYTE *)v4 + 554) &= 0xFEu;
        *((_BYTE *)v4 + 554) |= v9 & 1;
        if ( v9 )
          v7 = FLOAT_0_050000001;
        UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v4->vfptr, effect_possessed_bypass, v7);
      }
      goto LABEL_24;
    }
LABEL_12:
    v10 = target->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>((UFG::SimObjectCharacter *)target);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)target,
                                            UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)target,
                                            UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v11 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(target, UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v11 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)target,
                                          UFG::ActorAudioComponent::_TypeUID);
    }
    if ( v11 )
    {
      UFG::ActorAudioComponent::GetVoiceProfile(v11, v3, 0i64);
    }
    else
    {
      v12 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
      v3->mUID = (unsigned int)v12;
      _(v12);
    }
    return v3;
  }
  if ( target )
    goto LABEL_12;
LABEL_24:
  v13 = v4->m_voiceProfile;
  if ( v13 )
  {
    v15 = (AMD_HD3D *)v13->m_wwiseVoiceUid.mUID;
  }
  else
  {
    if ( !(*((_BYTE *)v4 + 553) & 2) )
    {
      v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->m_pSimObject->m_Name);
      UFG::qPrintf("Voice ID not assigned for : %s\n", v14);
    }
    *((_BYTE *)v4 + 553) |= 2u;
    v15 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  }
  v3->mUID = (unsigned int)v15;
  _(v15);
  return v3;
}

// File Line: 980
// RVA: 0x5AD430
void __fastcall UFG::ActorAudioComponent::TrySetupPanicDialog(UFG::ActorAudioComponent *this, UFG::DialogArgList *args)
{
  UFG::DialogArgList *v2; // rbx
  unsigned int v3; // edx
  __int64 v4; // rcx
  unsigned int v5; // er8

  v2 = args;
  if ( UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled && UFG::AudioListener::sm_pInstance->m_highSpeedMode )
  {
    if ( _S19_3 & 1 )
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
    v5 = v2->m_nArgs;
    if ( v5 )
    {
      while ( v2->m_args[v4] != v3 )
      {
        v4 = (unsigned int)(v4 + 1);
        if ( (unsigned int)v4 >= v5 )
          return;
      }
      v2->m_uDialogEventId = -32124175;
    }
  }
}

// File Line: 1003
// RVA: 0x5AE4A0
void __fastcall UFG::ActorAudioComponent::TrySetupSocialDialog(UFG::ActorAudioComponent *this, UFG::DialogArgList *args)
{
  UFG::DialogArgList *v2; // rsi
  UFG::ActorAudioComponent *v3; // rdi
  unsigned int v4; // eax
  char v5; // r14
  char v6; // al
  char v7; // bp
  UFG::SimObject *v8; // r8
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rdx
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *v12; // rax
  signed __int64 v13; // rcx
  __int64 v14; // rax
  UFG::SimObject *v15; // rbx

  v2 = args;
  v3 = this;
  v4 = _S20_1;
  if ( !(_S20_1 & 1) )
  {
    _S20_1 |= 1u;
    gender_l_id = UFG::TiDo::CalcWwiseUid("gender_l");
    v4 = _S20_1;
  }
  if ( !(v4 & 2) )
  {
    _S20_1 = v4 | 2;
    listener_id = UFG::TiDo::CalcWwiseUid("listener");
  }
  v5 = UFG::ArgumentSequencerBase::EventRequiresArgument(
         UFG::ArgumentSequencerBase::ms_instance,
         v2->m_uDialogEventId,
         gender_l_id);
  v6 = UFG::ArgumentSequencerBase::EventRequiresArgument(
         UFG::ArgumentSequencerBase::ms_instance,
         v2->m_uDialogEventId,
         listener_id);
  v7 = v6;
  if ( v5 || v6 )
  {
    v8 = v3->m_pSimObject;
    if ( v8 )
    {
      v9 = v8->m_Flags;
      if ( (v9 >> 14) & 1 )
      {
        v10 = v8->m_Components.p[20].m_pComponent;
      }
      else if ( (v9 & 0x8000u) == 0 )
      {
        v11 = (UFG::SimObjectGame *)v3->m_pSimObject;
        if ( (v9 >> 13) & 1 )
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          v12 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                   v11,
                                   UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                    (UFG::SimObject *)&v11->vfptr,
                                                                                    UFG::TargetingSystemBaseComponent::_TypeUID);
        v10 = v12;
      }
      else
      {
        v10 = v8->m_Components.p[20].m_pComponent;
      }
      if ( v10 )
      {
        v13 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + 58i64);
        v14 = *(_QWORD *)&v10[1].m_TypeUID;
        v15 = *(UFG::SimObject **)(v13 + v14 + 40);
        if ( v15 )
        {
          if ( v7 )
            UFG::ActorAudioComponent::AddListenerArgument(v3, *(UFG::SimObject **)(v13 + v14 + 40), v2);
          if ( v5 )
            UFG::ActorAudioComponent::AddGenderArgument(v3, v15, v2);
        }
      }
    }
  }
}

// File Line: 1041
// RVA: 0x5ADAB0
void __fastcall UFG::ActorAudioComponent::TrySetupPurchaseDialog(UFG::ActorAudioComponent *this, UFG::DialogArgList *args)
{
  UFG::DialogArgList *v2; // rdi
  unsigned int v3; // eax
  __int64 v4; // rbx
  signed __int64 v5; // rsi
  UFG::SimComponent *v6; // rdx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // r8
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax

  v2 = args;
  v3 = _S21_1;
  if ( !(_S21_1 & 1) )
  {
    _S21_1 |= 1u;
    context_purchase = UFG::TiDo::CalcWwiseUid("purchase");
    v3 = _S21_1;
  }
  if ( !(v3 & 2) )
  {
    _S21_1 = v3 | 2;
    context_greet_shop = UFG::TiDo::CalcWwiseUid("greet_shop");
  }
  v4 = 0i64;
  if ( v2->m_nArgs )
  {
    do
    {
      v5 = (signed __int64)v2 + 4 * v4;
      if ( *(_DWORD *)(v5 + 8) == context_greet_shop )
      {
        if ( LocalPlayer )
        {
          v7 = LocalPlayer->m_Flags;
          if ( (v7 >> 14) & 1 )
          {
            v6 = LocalPlayer->m_Components.p[20].m_pComponent;
          }
          else if ( (v7 & 0x8000u) == 0 )
          {
            if ( (v7 >> 13) & 1 )
            {
              v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
                     (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                     UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else if ( (v7 >> 12) & 1 )
            {
              v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
                     (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                     UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else
            {
              v8 = UFG::SimObject::GetComponentOfType(
                     (UFG::SimObject *)&LocalPlayer->vfptr,
                     UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            v6 = v8;
          }
          else
          {
            v6 = LocalPlayer->m_Components.p[20].m_pComponent;
          }
        }
        else
        {
          v6 = 0i64;
        }
        v9 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + 58i64)
                                    + *(_QWORD *)&v6[1].m_TypeUID
                                    + 40);
        if ( v9 )
        {
          v10 = v9->m_Flags;
          if ( (v10 >> 14) & 1 )
          {
            v11 = v9->m_Components.p[39].m_pComponent;
          }
          else if ( (v10 & 0x8000u) == 0 )
          {
            if ( (v10 >> 13) & 1 )
            {
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::InventoryComponent::_TypeUID);
            }
            else if ( (v10 >> 12) & 1 )
            {
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::InventoryComponent::_TypeUID);
            }
            else
            {
              v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::InventoryComponent::_TypeUID);
            }
          }
          else
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::InventoryComponent::_TypeUID);
          }
          if ( v11 )
          {
            if ( *(_DWORD *)&v11[14].m_Flags == 18 )
              *(_DWORD *)(v5 + 8) = UFG::TiDo::CalcWwiseUid("greet_shop_eat");
          }
        }
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v2->m_nArgs );
  }
}

// File Line: 1103
// RVA: 0x5ADC70
const char *__fastcall UFG::ActorAudioComponent::TrySetupSafehouseItemDialog(UFG::ActorAudioComponent *this, const char *context)
{
  const char *v2; // r14
  UFG::ActorAudioComponent *v3; // r15
  const char *result; // rax
  bool v5; // bl
  bool v6; // si
  bool v7; // bp
  int v8; // eax
  UFG::SimObject *v9; // r8
  bool v10; // di
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rax
  bool v13; // zf
  UFG::SimObjectGame *v14; // rcx

  v2 = context;
  v3 = this;
  if ( (unsigned int)UFG::qStringCompare(context, "SHI", -1)
    && (unsigned int)UFG::qStringCompare(v2, "SHISP", -1)
    && (unsigned int)UFG::qStringCompare(v2, "SHINOMO", -1)
    && (unsigned int)UFG::qStringCompare(v2, "SHIEL", -1)
    && (unsigned int)UFG::qStringCompare(v2, "SHILF", -1) )
  {
    return v2;
  }
  v5 = (unsigned int)UFG::qStringCompare(v2, "SHISP", -1) == 0;
  v6 = (unsigned int)UFG::qStringCompare(v2, "SHINOMO", -1) == 0;
  v7 = (unsigned int)UFG::qStringCompare(v2, "SHIEL", -1) == 0;
  v8 = UFG::qStringCompare(v2, "SHILF", -1);
  v9 = v3->m_pSimObject;
  v10 = v8 == 0;
  if ( !v9 )
    return v2;
  v11 = v9->m_Flags;
  if ( (v11 >> 14) & 1 )
  {
    v12 = v9->m_Components.p[39].m_pComponent;
  }
  else if ( (v11 & 0x8000u) == 0 )
  {
    if ( (v11 >> 13) & 1 )
    {
      v12 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)v3->m_pSimObject,
              UFG::InventoryComponent::_TypeUID);
    }
    else
    {
      v13 = ((v11 >> 12) & 1) == 0;
      v14 = (UFG::SimObjectGame *)v3->m_pSimObject;
      v12 = v13 ? UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v14->vfptr, UFG::InventoryComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::InventoryComponent::_TypeUID);
    }
  }
  else
  {
    v12 = UFG::SimObjectGame::GetComponentOfTypeHK(
            (UFG::SimObjectGame *)v3->m_pSimObject,
            UFG::InventoryComponent::_TypeUID);
  }
  if ( !v12 )
    return v2;
  switch ( *(_DWORD *)&v12[14].m_Flags )
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
      return v2;
  }
  return result;
}

// File Line: 1395
// RVA: 0x5AD060
const char *__fastcall UFG::ActorAudioComponent::TrySetupBeaconDialog(UFG::ActorAudioComponent *this, const char *ctx)
{
  UFG::ActorAudioComponent *v2; // r14
  const char *v3; // rsi
  char v4; // bp
  bool v5; // di
  bool v6; // r15
  int v7; // eax
  UFG::SimObject *v8; // r8
  bool v9; // bl
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  bool v12; // zf
  UFG::SimObjectGame *v13; // rcx
  const char *result; // rax
  UFG::qPropertySet *v15; // rax
  unsigned int v16; // eax

  v2 = this;
  v3 = ctx;
  v4 = 0;
  if ( this->m_pSimObject->mNode.mUID == 742779781 )
    v4 = 1;
  v5 = (unsigned int)UFG::qStringCompareInsensitive(ctx, "shop_sales_pitch", -1) == 0;
  v6 = (unsigned int)UFG::qStringCompareInsensitive(v3, "shop_beacon", -1) == 0;
  v7 = UFG::qStringCompareInsensitive(v3, "shop_sale_complete", -1);
  v8 = v2->m_pSimObject;
  v9 = v7 == 0;
  if ( !v8 )
    return 0i64;
  v10 = v8->m_Flags;
  if ( (v10 >> 14) & 1 )
  {
    v11 = v8->m_Components.p[39].m_pComponent;
  }
  else if ( (v10 & 0x8000u) == 0 )
  {
    if ( (v10 >> 13) & 1 )
    {
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)v2->m_pSimObject,
              UFG::InventoryComponent::_TypeUID);
    }
    else
    {
      v12 = ((v10 >> 12) & 1) == 0;
      v13 = (UFG::SimObjectGame *)v2->m_pSimObject;
      v11 = v12 ? UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::InventoryComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::InventoryComponent::_TypeUID);
    }
  }
  else
  {
    v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
            (UFG::SimObjectGame *)v2->m_pSimObject,
            UFG::InventoryComponent::_TypeUID);
  }
  if ( !v11 )
    return 0i64;
  switch ( *(_DWORD *)&v11[14].m_Flags )
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
      v15 = PropertyUtils::Get<UFG::qSymbol>(v2->m_pSimObject->m_pSceneObj, (UFG::qSymbol *)&SimSym_InventoryType.mUID);
      if ( !v15 )
        goto LABEL_85;
      v16 = v15->mFlags;
      if ( qSymbol_Vehicle_18.mUID == v16 )
        return "vehicle";
      if ( qSymbol_Boat_18.mUID == v16 )
        return "boat";
      if ( qSymbol_Clothes_18.mUID == v16 )
      {
        if ( v4 )
          result = "shop_beacon";
        else
          result = "shop_sales_pitch_clothes";
      }
      else
      {
LABEL_85:
        if ( v6 )
          result = "shop_beacon_generic";
        else
          result = v3;
      }
      break;
  }
  return result;
}

// File Line: 1572
// RVA: 0x5AD4C0
void __fastcall UFG::ActorAudioComponent::TrySetupPoliceDialog(UFG::ActorAudioComponent *this, unsigned int eventId, unsigned int contextHash, const char **outContext, const char **outVoice)
{
  const char **v5; // rsi
  unsigned int v6; // ebx
  unsigned int v7; // edi
  UFG::ActorAudioComponent *v8; // r14
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  UFG::SimObjectCharacter *v13; // rdi
  const char *v14; // rbx
  UFG::TransformNodeComponent *v15; // rbp
  UFG::SimObject *v16; // rax
  UFG::TransformNodeComponent *v17; // r14
  float v18; // xmm6_4
  float v19; // xmm8_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm8_4
  float v23; // xmm7_4
  float *v24; // rax
  __m128 v25; // xmm2
  float v26; // xmm6_4
  char v27; // r14
  UFG::qStaticSymbol *v28; // rdx
  float *v29; // rbp
  UFG::SimComponent *v30; // rdx
  unsigned __int16 v31; // cx
  UFG::SimComponent *v32; // rax
  UFG::SimObjectProp *v33; // rcx
  UFG::SimObjectWeaponPropertiesComponent *v34; // rax
  unsigned __int16 v35; // dx
  char v36; // r8
  const char *v37; // rax

  v5 = outContext;
  v6 = contextHash;
  v7 = eventId;
  v8 = this;
  if ( *outContext )
  {
    v9 = _S22_1;
    if ( !(_S22_1 & 1) )
    {
      _S22_1 |= 1u;
      police_surrender_hash = UFG::TiDo::CalcWwiseUid(police_surrender_string);
      v9 = _S22_1;
    }
    if ( !(v9 & 2) )
    {
      _S22_1 = v9 | 2;
      police_surrender_foot_hash = UFG::TiDo::CalcWwiseUid(police_surrender_foot_string);
      v9 = _S22_1;
    }
    if ( !(v9 & 4) )
    {
      _S22_1 = v9 | 4;
      police_surrender_gun_hash = UFG::TiDo::CalcWwiseUid(police_surrender_gun_string);
      v9 = _S22_1;
    }
    if ( !(v9 & 8) )
    {
      _S22_1 = v9 | 8;
      police_surrender_interior_hash = UFG::TiDo::CalcWwiseUid(police_surrender_string);
      v9 = _S22_1;
    }
    if ( !(v9 & 0x10) )
    {
      _S22_1 = v9 | 0x10;
      police_surrender_car_hash = UFG::TiDo::CalcWwiseUid(police_surrender_interior_string);
      v9 = _S22_1;
    }
    if ( !(v9 & 0x20) )
    {
      _S22_1 = v9 | 0x20;
      police_surrender_boat_hash = UFG::TiDo::CalcWwiseUid(police_surrender_boat_string);
      v9 = _S22_1;
    }
    if ( !(v9 & 0x40) )
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
    if ( !_bittest((const signed int *)&v9, 8u) )
    {
      _S22_1 = v9 | 0x100;
      police_heat_3_hash = UFG::TiDo::CalcWwiseUid(police_heat_3_string);
      v9 = _S22_1;
    }
    if ( !_bittest((const signed int *)&v9, 9u) )
    {
      _S22_1 = v9 | 0x200;
      police_heat_4_hash = UFG::TiDo::CalcWwiseUid(police_heat_4_string);
      v9 = _S22_1;
    }
    if ( !_bittest((const signed int *)&v9, 0xAu) )
    {
      _S22_1 = v9 | 0x400;
      v10 = UFG::qStringHash32("player_is_escaping_on_foot_speed_threshold", 0xFFFFFFFF);
      UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&player_is_escaping_on_foot_speed_threshold, v10);
      atexit(UFG::ActorAudioComponent::TrySetupPoliceDialog_::_5_::_dynamic_atexit_destructor_for__player_is_escaping_on_foot_speed_threshold__);
      v9 = _S22_1;
    }
    if ( !_bittest((const signed int *)&v9, 0xBu) )
    {
      _S22_1 = v9 | 0x800;
      v11 = UFG::qStringHash32("player_is_escaping_by_vehicle_speed_threshold", 0xFFFFFFFF);
      UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&player_is_escaping_by_vehicle_speed_threshold_0, v11);
      atexit(UFG::ActorAudioComponent::TrySetupPoliceDialog_::_5_::_dynamic_atexit_destructor_for__player_is_escaping_by_vehicle_speed_threshold__);
      v9 = _S22_1;
    }
    if ( !_bittest((const signed int *)&v9, 0xCu) )
    {
      _S22_1 = v9 | 0x1000;
      v12 = UFG::qStringHash32("surrender_foot_min_distance", 0xFFFFFFFF);
      UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&surrender_foot_min_distance, v12);
      atexit(UFG::ActorAudioComponent::TrySetupPoliceDialog_::_5_::_dynamic_atexit_destructor_for__surrender_foot_min_distance__);
    }
    if ( v7 != dword_14208B638 && v7 != dword_14208B63C && v7 != dword_14208B640 )
    {
      *v5 = 0i64;
      return;
    }
    if ( v6 == police_heat_hash || v6 == police_heat_2_hash || v6 == police_heat_3_hash || v6 == police_heat_4_hash )
    {
      *outVoice = police_voice_donnie;
    }
    else
    {
      v13 = LocalPlayer;
      v14 = 0i64;
      v15 = 0i64;
      if ( LocalPlayer )
        v15 = LocalPlayer->m_pTransformNodeComponent;
      v16 = v8->m_pSimObject;
      v17 = 0i64;
      if ( v16 )
        v17 = v16->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v17);
      v18 = v17->mWorldTransform.v3.x;
      v19 = v17->mWorldTransform.v3.y;
      v20 = v17->mWorldTransform.v3.z;
      UFG::TransformNodeComponent::UpdateWorldTransform(v15);
      v21 = v18 - v15->mWorldTransform.v3.x;
      v22 = v19 - v15->mWorldTransform.v3.y;
      v23 = v20 - v15->mWorldTransform.v3.z;
      v24 = UFG::qPropertySet::Get<float>(
              UFG::ActorAudioComponent::sm_copConfigPs,
              (UFG::qSymbol *)&surrender_foot_min_distance.mUID,
              DEPTH_RECURSE);
      if ( (float)((float)((float)(v22 * v22) + (float)(v21 * v21)) + (float)(v23 * v23)) < (float)(*v24 * *v24) )
        goto LABEL_74;
      UFG::TransformNodeComponent::UpdateWorldTransform(v15);
      v25 = (__m128)LODWORD(v15->mWorldVelocity.x);
      v25.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0])
                              + (float)(v15->mWorldVelocity.y * v15->mWorldVelocity.y))
                      + (float)(v15->mWorldVelocity.z * v15->mWorldVelocity.z);
      LODWORD(v26) = (unsigned __int128)_mm_sqrt_ps(v25);
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
              (UFG::qSymbol *)&v28->mUID,
              DEPTH_RECURSE);
      if ( v13 )
      {
        v31 = v13->m_Flags;
        if ( (v31 >> 14) & 1 )
        {
          v30 = v13->m_Components.p[20].m_pComponent;
        }
        else if ( (v31 & 0x8000u) == 0 )
        {
          if ( (v31 >> 13) & 1 )
          {
            v32 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v13->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v31 >> 12) & 1 )
          {
            v32 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v13->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v32 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v13->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v30 = v32;
        }
        else
        {
          v30 = v13->m_Components.p[20].m_pComponent;
        }
      }
      else
      {
        v30 = 0i64;
      }
      v33 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v30[1].m_Flags + 25i64)
                                   + *(_QWORD *)&v30[1].m_TypeUID
                                   + 40);
      if ( v33 )
      {
        v35 = v33->m_Flags;
        if ( (v35 >> 14) & 1 )
        {
          v34 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v33->vfptr,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        else if ( (v35 & 0x8000u) == 0 )
        {
          if ( (v35 >> 13) & 1 )
          {
            v34 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v33);
          }
          else if ( (v35 >> 12) & 1 )
          {
            v34 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v33->vfptr,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          }
          else
          {
            v34 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v33->vfptr,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          }
        }
        else
        {
          v34 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v33->vfptr,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
      }
      else
      {
        v34 = 0i64;
      }
      v36 = 0;
      if ( v34 )
      {
        v36 = 0;
        if ( v34->mWeaponTypeInfo->mFireModes[v34->mFireMode]->mProjectileSpawnBoneName.mUID != UFG::gNullQSymbolUC.mUID )
          v36 = 1;
      }
      if ( v26 < *v29 )
      {
        if ( v36 )
          v14 = police_surrender_gun_string;
LABEL_74:
        *v5 = v14;
        return;
      }
      if ( v36 && UFG::qRandom(1.0, &UFG::qDefaultSeed) < 0.30000001 )
      {
        *v5 = police_surrender_gun_string;
      }
      else if ( UFG::qRandom(1.0, &UFG::qDefaultSeed) >= 0.5 )
      {
        *v5 = police_surrender_string;
      }
      else
      {
        v37 = police_surrender_foot_string;
        if ( v27 )
          v37 = police_surrender_car_string;
        *v5 = v37;
      }
    }
  }
}

// File Line: 1729
// RVA: 0x5AC470
void __fastcall UFG::ActorAudioComponent::SetupTaggedDialog(UFG::ActorAudioComponent *this, UFG::DialogArgList *args)
{
  UFG::DialogArgList *v2; // rdi
  unsigned int v3; // ebx
  __int64 v4; // rax
  unsigned int v5; // ecx
  __int64 v6; // rax

  v2 = args;
  v3 = this->m_voiceProfile->m_wwiseTagsUid.mUID;
  _((AMD_HD3D *)v3);
  if ( v3 )
  {
    v4 = v2->m_nArgs;
    if ( (unsigned int)v4 < 6 )
    {
      v2->m_args[v4] = v3;
      ++v2->m_nArgs;
    }
  }
  v5 = *(&stru_14242ED00.mUID + 4 * UFG::TaggedDialogueStateManager::m_stateIdx);
  if ( v5 )
  {
    v6 = v2->m_nArgs;
    if ( (unsigned int)v6 < 6 )
    {
      v2->m_args[v6] = v5;
      ++v2->m_nArgs;
    }
  }
  _((AMD_HD3D *)v3);
}

// File Line: 1746
// RVA: 0x5AC9F0
void __fastcall UFG::ActorAudioComponent::StopCurrentlyPlaying(UFG::ActorAudioComponent *this, bool force)
{
  UFG::ActorAudioComponent *v2; // rax
  UFG::AudioEvent *v3; // rcx
  unsigned int v4; // ebx
  UFG::TiDo *v5; // rax

  v2 = this;
  if ( force || *((_BYTE *)this + 552) & 8 )
  {
    v3 = this->m_controller.m_pEvent;
    if ( v3 )
    {
      if ( force )
      {
        v4 = v3->m_uPlayingId;
        v3->m_pController = 0i64;
        v2->m_controller.m_pEvent = 0i64;
        if ( v4 )
        {
          v5 = UFG::TiDo::GetInstance();
          UFG::TiDo::StopPlaying(v5, v4);
        }
      }
      else
      {
        UFG::AudioEvent::StopAndForget(v3, 0x1F4u);
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
  UFG::ActorAudioComponent *v1; // rdi
  unsigned int v2; // edx
  UFG::AudioEvent *v3; // rcx
  unsigned int v4; // er8
  __int64 v5; // rcx
  unsigned int v6; // ebx
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // edx
  UFG::AudioEvent **v10; // rsi
  UFG::SimComponent *v11; // rax
  UFG::AudioEventCallbackObject *v12; // rbx
  unsigned int v13; // eax
  int v14; // ebx
  UFG::DialogArgList args; // [rsp+28h] [rbp-28h]

  v1 = this;
  args.vfptr = (UFG::DialogArgListVtbl *)&UFG::DialogArgList::`vftable';
  UFG::qMemSet(args.m_args, 0, 0x18u);
  args.m_nArgs = 0;
  args.m_uDialogEventId = hashTags;
  if ( hashPanic )
  {
    v2 = args.m_nArgs;
    if ( args.m_nArgs < 6 )
    {
      args.m_args[args.m_nArgs] = hashPanic;
      v2 = args.m_nArgs++ + 1;
    }
  }
  else
  {
    v2 = args.m_nArgs;
  }
  if ( !v1->m_bIsInitialized )
    return 0;
  if ( v1->m_isSpeakingCnt <= 0 || (v3 = v1->m_controller.m_pEvent) == 0i64 )
  {
LABEL_11:
    if ( UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled && UFG::AudioListener::sm_pInstance->m_highSpeedMode )
    {
      if ( _S19_3 & 1 )
      {
        v4 = context_panic;
      }
      else
      {
        _S19_3 |= 1u;
        v4 = UFG::TiDo::CalcWwiseUid("panic");
        context_panic = v4;
        v2 = args.m_nArgs;
      }
      v5 = 0i64;
      if ( v2 )
      {
        while ( args.m_args[v5] != v4 )
        {
          v5 = (unsigned int)(v5 + 1);
          if ( (unsigned int)v5 >= v2 )
            goto LABEL_21;
        }
        args.m_uDialogEventId = -32124175;
      }
    }
LABEL_21:
    v6 = args.m_uDialogEventId;
    if ( args.m_uDialogEventId == -32124175 )
    {
      v7 = v1->m_voiceProfile->m_wwiseTagsUid.mUID;
      _((AMD_HD3D *)v7);
      if ( v7 )
      {
        v8 = args.m_nArgs;
        if ( args.m_nArgs < 6 )
        {
          args.m_args[args.m_nArgs] = v7;
          v8 = args.m_nArgs++ + 1;
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
      _((AMD_HD3D *)v7);
    }
    else
    {
      UFG::ActorAudioComponent::TrySetupPurchaseDialog(v1, &args);
      UFG::ActorAudioComponent::TrySetupSocialDialog(v1, &args);
      if ( !v6 )
        return 0;
    }
    v10 = &v1->m_controller.m_pEvent;
    if ( v1->m_controller.m_pEvent )
      return 0;
    v11 = v1->m_healthComponent.m_pPointer;
    if ( v11 )
    {
      if ( BYTE4(v11[1].m_BoundComponentHandles.mNode.mPrev)
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&v11[3].m_pSimObject) >= 2.0 )
      {
        return 0;
      }
    }
    UFG::AudioEntity::CreateDialogEvent(
      (UFG::AudioEntity *)&v1->vfptr,
      (UFG::AudioEventController *)&v1->m_controller.m_pEvent,
      0i64,
      0i64);
    if ( !*v10 )
      return 0;
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
      v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable';
      v12->m_next = 0i64;
      v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::SpeechControlCallback::`vftable';
    }
    if ( *v10 )
      UFG::AudioEvent::AddCallback(*v10, v12);
    if ( *v10 )
      UFG::AudioEvent::AddCallback(*v10, 0i64);
    v14 = UFG::AudioDialogEvent::Enqueue((UFG::AudioDialogEvent *)*v10, &args, 0);
    if ( !(_S26_2 & 1) )
    {
      _S26_2 |= 1u;
      UFG::qWiseSymbol::create_from_string(&d_tags, "d_tags");
      atexit(UFG::ActorAudioComponent::PlaySpeech_::_10_::_dynamic_atexit_destructor_for__d_tags__);
    }
    if ( !(*((_BYTE *)v1 + 553) & 8) )
    {
      if ( !v14 )
      {
LABEL_56:
        if ( *v10 )
          UFG::AudioEvent::Destroy(*v10);
        *((_BYTE *)v1 + 553) |= 1u;
        return 0;
      }
      if ( args.m_uDialogEventId == d_tags.mUID )
        UFG::ConversationManager::InterruptConversationsWithCharacter(
          v1->m_pSimObject,
          eInterruptType_HitReaction,
          1,
          0i64);
    }
    if ( v14 && UFG::AudioEventController::Play((UFG::AudioEventController *)&v1->m_controller.m_pEvent, 0) )
    {
      ++v1->m_isSpeakingCnt;
      v1->m_curPlayingPriority = 5;
      *((_BYTE *)v1 + 553) &= 0xEEu;
      return 1;
    }
    goto LABEL_56;
  }
  if ( v1->m_curPlayingPriority < 5 )
  {
    if ( *((_BYTE *)v1 + 552) & 8 )
    {
      UFG::AudioEvent::StopAndForget(v3, 0x1F4u);
      v2 = args.m_nArgs;
    }
    goto LABEL_11;
  }
  return 0;
}

// File Line: 1842
// RVA: 0x5A7360
char __fastcall UFG::ActorAudioComponent::PlayScreamPain(UFG::ActorAudioComponent *this)
{
  UFG::ActorAudioComponent *v1; // rdi
  unsigned int v2; // edx
  UFG::AudioEvent *v3; // rcx
  unsigned int v4; // er8
  __int64 v5; // rcx
  unsigned int v6; // ebx
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // edx
  UFG::AudioEvent **v10; // rsi
  UFG::SimComponent *v11; // rax
  UFG::AudioEventCallbackObject *v12; // rbx
  unsigned int v13; // eax
  int v14; // ebx
  UFG::DialogArgList args; // [rsp+28h] [rbp-28h]

  v1 = this;
  args.vfptr = (UFG::DialogArgListVtbl *)&UFG::DialogArgList::`vftable';
  UFG::qMemSet(args.m_args, 0, 0x18u);
  args.m_nArgs = 0;
  args.m_uDialogEventId = hashTags;
  if ( hashScreamPain )
  {
    v2 = args.m_nArgs;
    if ( args.m_nArgs < 6 )
    {
      args.m_args[args.m_nArgs] = hashScreamPain;
      v2 = args.m_nArgs++ + 1;
    }
  }
  else
  {
    v2 = args.m_nArgs;
  }
  if ( !v1->m_bIsInitialized )
    return 0;
  if ( v1->m_isSpeakingCnt <= 0 || (v3 = v1->m_controller.m_pEvent) == 0i64 )
  {
LABEL_11:
    if ( UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled && UFG::AudioListener::sm_pInstance->m_highSpeedMode )
    {
      if ( _S19_3 & 1 )
      {
        v4 = context_panic;
      }
      else
      {
        _S19_3 |= 1u;
        v4 = UFG::TiDo::CalcWwiseUid("panic");
        context_panic = v4;
        v2 = args.m_nArgs;
      }
      v5 = 0i64;
      if ( v2 )
      {
        while ( args.m_args[v5] != v4 )
        {
          v5 = (unsigned int)(v5 + 1);
          if ( (unsigned int)v5 >= v2 )
            goto LABEL_21;
        }
        args.m_uDialogEventId = -32124175;
      }
    }
LABEL_21:
    v6 = args.m_uDialogEventId;
    if ( args.m_uDialogEventId == -32124175 )
    {
      v7 = v1->m_voiceProfile->m_wwiseTagsUid.mUID;
      _((AMD_HD3D *)v7);
      if ( v7 )
      {
        v8 = args.m_nArgs;
        if ( args.m_nArgs < 6 )
        {
          args.m_args[args.m_nArgs] = v7;
          v8 = args.m_nArgs++ + 1;
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
      _((AMD_HD3D *)v7);
    }
    else
    {
      UFG::ActorAudioComponent::TrySetupPurchaseDialog(v1, &args);
      UFG::ActorAudioComponent::TrySetupSocialDialog(v1, &args);
      if ( !v6 )
        return 0;
    }
    v10 = &v1->m_controller.m_pEvent;
    if ( v1->m_controller.m_pEvent )
      return 0;
    v11 = v1->m_healthComponent.m_pPointer;
    if ( v11 )
    {
      if ( BYTE4(v11[1].m_BoundComponentHandles.mNode.mPrev)
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&v11[3].m_pSimObject) >= 2.0 )
      {
        return 0;
      }
    }
    UFG::AudioEntity::CreateDialogEvent(
      (UFG::AudioEntity *)&v1->vfptr,
      (UFG::AudioEventController *)&v1->m_controller.m_pEvent,
      0i64,
      0i64);
    if ( !*v10 )
      return 0;
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
      v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable';
      v12->m_next = 0i64;
      v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::SpeechControlCallback::`vftable';
    }
    if ( *v10 )
      UFG::AudioEvent::AddCallback(*v10, v12);
    if ( *v10 )
      UFG::AudioEvent::AddCallback(*v10, 0i64);
    v14 = UFG::AudioDialogEvent::Enqueue((UFG::AudioDialogEvent *)*v10, &args, 0);
    if ( !(_S26_2 & 1) )
    {
      _S26_2 |= 1u;
      UFG::qWiseSymbol::create_from_string(&d_tags, "d_tags");
      atexit(UFG::ActorAudioComponent::PlaySpeech_::_10_::_dynamic_atexit_destructor_for__d_tags__);
    }
    if ( !(*((_BYTE *)v1 + 553) & 8) )
    {
      if ( !v14 )
      {
LABEL_56:
        if ( *v10 )
          UFG::AudioEvent::Destroy(*v10);
        *((_BYTE *)v1 + 553) |= 1u;
        return 0;
      }
      if ( args.m_uDialogEventId == d_tags.mUID )
        UFG::ConversationManager::InterruptConversationsWithCharacter(
          v1->m_pSimObject,
          eInterruptType_HitReaction,
          1,
          0i64);
    }
    if ( v14 && UFG::AudioEventController::Play((UFG::AudioEventController *)&v1->m_controller.m_pEvent, 0) )
    {
      ++v1->m_isSpeakingCnt;
      v1->m_curPlayingPriority = 5;
      *((_BYTE *)v1 + 553) &= 0xEEu;
      return 1;
    }
    goto LABEL_56;
  }
  if ( v1->m_curPlayingPriority < 5 )
  {
    if ( *((_BYTE *)v1 + 552) & 8 )
    {
      UFG::AudioEvent::StopAndForget(v3, 0x1F4u);
      v2 = args.m_nArgs;
    }
    goto LABEL_11;
  }
  return 0;
}

// File Line: 1880
// RVA: 0x5A8F60
char __fastcall UFG::ActorAudioComponent::QueueSpeechExternalMission(UFG::ActorAudioComponent *this, unsigned int eventID, const char *context, UFG::AudioEventCallbackObject *audioCallbacks, unsigned int priority, bool subtitle)
{
  UFG::ActorAudioComponent *v6; // rsi
  UFG::AudioEventCallbackObject *v7; // rbx
  unsigned int v8; // edi
  unsigned int v9; // eax

  v6 = this;
  v7 = audioCallbacks;
  v8 = eventID;
  v9 = UFG::TiDo::CalcWwiseUid(context);
  return UFG::ActorAudioComponent::QueueSpeechExternalMission(v6, v8, v9, v7, priority, subtitle);
}

// File Line: 1885
// RVA: 0x5A8E20
char __fastcall UFG::ActorAudioComponent::QueueSpeechExternalMission(UFG::ActorAudioComponent *this, unsigned int eventID, unsigned int fileId, UFG::AudioEventCallbackObject *audioCallbacks, unsigned int priority, bool subtitle)
{
  UFG::AudioEventCallbackObject *v6; // r12
  unsigned int v7; // er15
  unsigned int v8; // ebp
  UFG::ActorAudioComponent *v9; // rdi
  UFG::AudioEvent *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  UFG::AudioEventExternalSourceInfo *v13; // rax
  UFG::AudioEventExternalSourceInfo *v14; // rsi
  UFG::ExternalSourceInfoNode *v15; // rcx
  UFG::ExternalSourceInfoNode *v16; // rbx

  v6 = audioCallbacks;
  v7 = fileId;
  v8 = eventID;
  v9 = this;
  if ( !this->m_bIsInitialized )
    return 0;
  if ( this->m_isSpeakingCnt > 0 )
  {
    v11 = this->m_controller.m_pEvent;
    if ( v11 )
    {
      if ( priority <= v9->m_curPlayingPriority )
        return 0;
      if ( *((_BYTE *)v9 + 0x228) & 8 )
        UFG::AudioEvent::StopAndForget(v11, 0x1F4u);
    }
  }
  UFG::TiDo::GetWwiseStreamFileSize(v7);
  if ( !((v8 + 1) & 0xFFFFFFFE) )
    v8 = play_mission_22.mUID;
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
  v15 = v14->m_externals.p;
  v15->m_externalSourceCookie = slot_1_22.mUID;
  v14->m_externals.p->m_fileId = v7;
  v16 = v14->m_externals.p;
  v16->m_codecID = Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)v15);
  UFG::TiDo::GetNameFromWwiseUid(v7);
  return UFG::ActorAudioComponent::PlaySpeechExternal(v9, v8, priority, v6, v14, subtitle);
}

// File Line: 1936
// RVA: 0x5A8930
char __fastcall UFG::ActorAudioComponent::QueueSpeechExternalAmbient(UFG::ActorAudioComponent *this, unsigned int eventId, const char *context, UFG::AudioEventCallbackObject *audioCallbacks, unsigned int priority, bool force, bool subtitle)
{
  UFG::AudioEventCallbackObject *v7; // r13
  char *v8; // rbx
  unsigned int v9; // esi
  UFG::ActorAudioComponent *v10; // rdi
  unsigned int v12; // er12
  UFG::AudioEvent *v13; // rcx
  unsigned int v14; // er8
  unsigned int v15; // ecx
  unsigned int v16; // eax
  bool v17; // al
  char v18; // cl
  char *v19; // rdx
  UFG::VoiceProfile *v20; // rax
  char *v21; // r14
  const char *v22; // rbx
  unsigned int v23; // er15
  __int64 v24; // r14
  int v25; // edx
  signed int v26; // er9
  UFG::AmbientContextNode *v27; // r8
  int v28; // er8
  signed int v29; // eax
  char v30; // bl
  char *v31; // rax
  __int64 v32; // rax
  __int64 v33; // rcx
  __int64 v34; // rbx
  UFG::qWiseSymbol result; // [rsp+40h] [rbp-C0h]
  char *outVoice; // [rsp+48h] [rbp-B8h]
  char *outContext; // [rsp+50h] [rbp-B0h]
  __int64 v38; // [rsp+58h] [rbp-A8h]
  char dest; // [rsp+60h] [rbp-A0h]
  unsigned int contextHash; // [rsp+190h] [rbp+90h]

  v38 = -2i64;
  v7 = audioCallbacks;
  v8 = (char *)context;
  v9 = eventId;
  v10 = this;
  if ( !this->m_bIsInitialized )
    return 0;
  v12 = priority;
  if ( this->m_isSpeakingCnt > 0 )
  {
    v13 = this->m_controller.m_pEvent;
    if ( v13 )
    {
      if ( priority <= v10->m_curPlayingPriority )
        return 0;
      if ( *((_BYTE *)v10 + 552) & 8 )
        UFG::AudioEvent::StopAndForget(v13, 0x1F4u);
    }
  }
  v14 = UFG::TiDo::CalcWwiseUid(v8);
  contextHash = v14;
  v15 = _S25_1;
  if ( !(_S25_1 & 1) )
  {
    _S25_1 |= 1u;
    hashNone = UFG::TiDo::CalcWwiseUid("none");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( !(v15 & 2) )
  {
    _S25_1 = v15 | 2;
    hashPanic_0 = UFG::TiDo::CalcWwiseUid("panic");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( !(v15 & 4) )
  {
    _S25_1 = v15 | 4;
    hashPushed = UFG::TiDo::CalcWwiseUid("pushed");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( !(v15 & 8) )
  {
    _S25_1 = v15 | 8;
    hashEBE = UFG::TiDo::CalcWwiseUid("event_big_exclaim");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( !(v15 & 0x10) )
  {
    _S25_1 = v15 | 0x10;
    hashStartled = UFG::TiDo::CalcWwiseUid("startled");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( !(v15 & 0x20) )
  {
    _S25_1 = v15 | 0x20;
    hashLookOutCar = UFG::TiDo::CalcWwiseUid("look_out_car");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( !(v15 & 0x40) )
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
  if ( !_bittest((const signed int *)&v15, 8u) )
  {
    _S25_1 = v15 | 0x100;
    hashOnResumeNpc = UFG::TiDo::CalcWwiseUid("on_resume_npc");
    v14 = contextHash;
    v15 = _S25_1;
  }
  if ( _bittest((const signed int *)&v15, 9u) )
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
  if ( v9 == dword_14208B638 || v9 == dword_14208B63C || v9 == dword_14208B640 )
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
        return UFG::ActorAudioComponent::PlayPanic(v10);
      return 0;
    }
  }
  v19 = v8;
  outContext = v8;
  v20 = v10->m_voiceProfile;
  v21 = v20->m_subtitleSet.mData;
  outVoice = v20->m_subtitleSet.mData;
  if ( v18 )
  {
    UFG::ActorAudioComponent::TrySetupPoliceDialog(v10, v9, v14, (const char **)&outContext, (const char **)&outVoice);
    v19 = outContext;
    if ( !outContext )
      return 0;
    v21 = outVoice;
  }
  if ( v9 == play_beacon_22.mUID || v9 == play_haggle_22.mUID )
    v19 = (char *)UFG::ActorAudioComponent::TrySetupBeaconDialog(v10, v8);
  v22 = UFG::ActorAudioComponent::TrySetupSafehouseItemDialog(v10, v19);
  UFG::qSPrintf(&dest, "%s.%s.001.", v21, v22);
  v23 = UFG::TiDo::CalcWwiseUid(&dest);
  UFG::qWiseSymbol::create_from_string(&result, v22);
  v24 = 0i64;
  v25 = 0;
  v26 = v10->m_ambientContexts.m_nodes.size;
  if ( v26 <= 0 )
    goto LABEL_62;
  v27 = v10->m_ambientContexts.m_nodes.p;
  while ( v27[v25].m_context.mUID != result.mUID )
  {
    if ( ++v25 >= v26 )
      goto LABEL_62;
  }
  if ( v25 < 0 )
LABEL_62:
    v28 = -1;
  else
    v28 = v27[v25].m_lastIdx;
  v29 = UFG::ExternalSourceUtil::GetRandomVariation(v23, &contextHash, v28);
  if ( v29 >= 0 )
  {
    UFG::AmbientContextManager::Set(&v10->m_ambientContexts, &result, v29);
    if ( !v9 )
      v9 = play_ambient_22.mUID;
    v31 = (char *)UFG::qMemoryPool::Allocate(
                    &g_AudioComponentPool,
                    0x20ui64,
                    "ExternalSourceInfo.QueueSpeech",
                    0i64,
                    1u);
    outVoice = v31;
    if ( v31 )
    {
      UFG::AudioEventExternalSourceInfo::AudioEventExternalSourceInfo((UFG::AudioEventExternalSourceInfo *)v31, 1u);
      v24 = v32;
    }
    (*(UFG::qStaticWiseSymbol **)(v24 + 24))->mUID = slot_1_22.mUID;
    v33 = *(_QWORD *)(v24 + 24);
    *(_DWORD *)(v33 + 8) = contextHash;
    v34 = *(_QWORD *)(v24 + 24);
    *(_DWORD *)(v34 + 4) = Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)v33);
    v30 = UFG::ActorAudioComponent::PlaySpeechExternal(
            v10,
            v9,
            v12,
            v7,
            (UFG::AudioEventExternalSourceInfo *)v24,
            subtitle);
  }
  else
  {
    UFG::qPrintf("Speech file not found: %u %s\n", contextHash, &dest);
    v30 = 0;
  }
  _((AMD_HD3D *)result.mUID);
  return v30;
}

// File Line: 2055
// RVA: 0x5A7AE0
char __fastcall UFG::ActorAudioComponent::PlaySpeechExternal(UFG::ActorAudioComponent *this, unsigned int eventId, unsigned int priority, UFG::AudioEventCallbackObject *audioCallbacks, UFG::AudioEventExternalSourceInfo *info, bool subtitle)
{
  UFG::AudioEventCallbackObject *v6; // r14
  unsigned int v7; // er15
  UFG::ActorAudioComponent *v8; // rsi
  UFG::AudioEvent **v9; // rdi
  UFG::AudioEventCallbackObject *v10; // rbx
  unsigned int v11; // eax
  UFG::AudioEventCallbackObject *v12; // rbx
  unsigned int v13; // eax

  v6 = audioCallbacks;
  v7 = priority;
  v8 = this;
  v9 = &this->m_controller.m_pEvent;
  UFG::AudioEntity::CreateEventA(
    (UFG::AudioEntity *)&this->vfptr,
    eventId,
    (UFG::AudioEventController *)&this->m_controller.m_pEvent,
    0i64,
    info);
  if ( *v9 )
  {
    v10 = (UFG::AudioEventCallbackObject *)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
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
    if ( v10 )
    {
      v10->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable';
      v10->m_next = 0i64;
      v10->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::SpeechControlCallback::`vftable';
    }
    if ( *v9 )
      UFG::AudioEvent::AddCallback(*v9, v10);
    if ( *v9 )
      UFG::AudioEvent::AddCallback(*v9, v6);
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
        v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable';
        v12->m_next = 0i64;
        v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AACSubtitleCallback::`vftable';
      }
      if ( *v9 )
        UFG::AudioEvent::AddCallback(*v9, v12);
    }
    if ( *v9 )
    {
      if ( (*v9)->vfptr->Play(*v9, 0) )
      {
        ++v8->m_isSpeakingCnt;
        v8->m_curPlayingPriority = v7;
        *((_BYTE *)v8 + 553) &= 0xEEu;
        return 1;
      }
      *((_BYTE *)*v9 + 144) |= 4u;
      if ( *v9 )
        (*v9)->m_pController = 0i64;
      *v9 = 0i64;
    }
    if ( *v9 )
      UFG::AudioEvent::Destroy(*v9);
    *((_BYTE *)v8 + 553) |= 1u;
  }
  return 0;
}

// File Line: 2120
// RVA: 0x5A88A0
char __fastcall UFG::ActorAudioComponent::QueueSpeech(UFG::ActorAudioComponent *this, UFG::DialogArgList *args, UFG::AudioEventCallbackObject *audioCallbacks, unsigned int priority, bool force, bool subtitle)
{
  unsigned int v6; // edi
  UFG::AudioEventCallbackObject *v7; // rsi
  UFG::DialogArgList *v8; // rbp
  UFG::ActorAudioComponent *v9; // rbx
  UFG::AudioEvent *v11; // rcx

  v6 = priority;
  v7 = audioCallbacks;
  v8 = args;
  v9 = this;
  if ( !this->m_bIsInitialized )
    return 0;
  if ( this->m_isSpeakingCnt > 0 )
  {
    v11 = this->m_controller.m_pEvent;
    if ( v11 )
    {
      if ( priority <= v9->m_curPlayingPriority )
        return 0;
      if ( *((_BYTE *)v9 + 552) & 8 )
        UFG::AudioEvent::StopAndForget(v11, 0x1F4u);
    }
  }
  return UFG::ActorAudioComponent::PlaySpeech(v9, v8, v7, v6, subtitle);
}

// File Line: 2147
// RVA: 0x5A7880
char __fastcall UFG::ActorAudioComponent::PlaySpeech(UFG::ActorAudioComponent *this, UFG::DialogArgList *args, UFG::AudioEventCallbackObject *audioCallbacks, unsigned int priority, bool subtitle)
{
  unsigned int v5; // er14
  UFG::AudioEventCallbackObject *v6; // r15
  UFG::DialogArgList *v7; // rbp
  UFG::ActorAudioComponent *v8; // rbx
  unsigned int v9; // edi
  UFG::AudioEvent **v10; // rsi
  UFG::SimComponent *v11; // rax
  UFG::AudioEventCallbackObject *v12; // rdi
  unsigned int v13; // eax
  UFG::AudioEventCallbackObject *v14; // rax
  int v15; // edi

  v5 = priority;
  v6 = audioCallbacks;
  v7 = args;
  v8 = this;
  UFG::ActorAudioComponent::TrySetupPanicDialog(this, args);
  v9 = v7->m_uDialogEventId;
  if ( v9 == 0xFE15D2F1 )
  {
    UFG::ActorAudioComponent::SetupTaggedDialog(v8, v7);
LABEL_5:
    v10 = &v8->m_controller.m_pEvent;
    if ( v8->m_controller.m_pEvent )
      return 0;
    v11 = v8->m_healthComponent.m_pPointer;
    if ( v11 )
    {
      if ( BYTE4(v11[1].m_BoundComponentHandles.mNode.mPrev)
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&v11[3].m_pSimObject) >= 2.0
        && v5 < 0xA )
      {
        return 0;
      }
    }
    UFG::AudioEntity::CreateDialogEvent(
      (UFG::AudioEntity *)&v8->vfptr,
      (UFG::AudioEventController *)&v8->m_controller.m_pEvent,
      0i64,
      0i64);
    if ( !*v10 )
      return 0;
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
      v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable';
      v12->m_next = 0i64;
      v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::SpeechControlCallback::`vftable';
    }
    if ( *v10 )
      UFG::AudioEvent::AddCallback(*v10, v12);
    if ( subtitle )
    {
      v14 = (UFG::AudioEventCallbackObject *)UFG::AACSubtitleCallback::operator new(
                                               0x10ui64,
                                               "ActorAudioComponent.SubtitleCallback");
      if ( v14 )
      {
        v14->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable';
        v14->m_next = 0i64;
        v14->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AACSubtitleCallback::`vftable';
      }
      if ( *v10 )
        UFG::AudioEvent::AddCallback(*v10, v14);
    }
    if ( *v10 )
      UFG::AudioEvent::AddCallback(*v10, v6);
    v15 = UFG::AudioDialogEvent::Enqueue((UFG::AudioDialogEvent *)*v10, v7, 0);
    if ( !(_S26_2 & 1) )
    {
      _S26_2 |= 1u;
      UFG::qWiseSymbol::create_from_string(&d_tags, "d_tags");
      atexit(UFG::ActorAudioComponent::PlaySpeech_::_10_::_dynamic_atexit_destructor_for__d_tags__);
    }
    if ( !(*((_BYTE *)v8 + 553) & 8) )
    {
      if ( !v15 )
      {
LABEL_35:
        if ( *v10 )
          UFG::AudioEvent::Destroy(*v10);
        *((_BYTE *)v8 + 553) |= 1u;
        return 0;
      }
      if ( v7->m_uDialogEventId == d_tags.mUID )
        UFG::ConversationManager::InterruptConversationsWithCharacter(
          v8->m_pSimObject,
          eInterruptType_HitReaction,
          1,
          0i64);
    }
    if ( v15 && UFG::AudioEventController::Play((UFG::AudioEventController *)&v8->m_controller.m_pEvent, 0) )
    {
      ++v8->m_isSpeakingCnt;
      v8->m_curPlayingPriority = v5;
      *((_BYTE *)v8 + 553) &= 0xEEu;
      return 1;
    }
    goto LABEL_35;
  }
  UFG::ActorAudioComponent::TrySetupPurchaseDialog(v8, v7);
  UFG::ActorAudioComponent::TrySetupSocialDialog(v8, v7);
  if ( v9 )
    goto LABEL_5;
  return 0;
}

// File Line: 2226
// RVA: 0x59CE60
UFG::qPropertySet *__fastcall UFG::ActorAudioComponent::GetFootwearType(UFG::ActorAudioComponent *this)
{
  UFG::ActorAudioComponent *v1; // rbx
  UFG::qPropertySet *result; // rax

  v1 = this;
  if ( !(_S27_2 & 1) )
  {
    _S27_2 |= 1u;
    UFG::qSymbol::create_from_string(&shoesSymbol, "footwear_type");
    atexit(UFG::ActorAudioComponent::GetFootwearType_::_2_::_dynamic_atexit_destructor_for__shoesSymbol__);
  }
  result = PropertyUtils::Get<UFG::qWiseSymbol>(v1->m_pSimObject->m_pSceneObj, &shoesSymbol);
  if ( result )
    result = (UFG::qPropertySet *)result->mFlags;
  return result;
}

// File Line: 2244
// RVA: 0x596220
void __fastcall UFG::ActorAudioComponent::AddGenderArgument(UFG::ActorAudioComponent *this, UFG::SimObject *simObject, UFG::DialogArgList *args)
{
  UFG::DialogArgList *v3; // rbx
  bool v4; // zf
  __int64 v5; // rax

  v3 = args;
  v4 = UFG::IsFemale(simObject) == 0;
  v5 = v3->m_nArgs;
  if ( v4 )
  {
    if ( (unsigned int)v5 < 6 )
    {
      v3->m_args[v5] = 0xB976E27E;
      ++v3->m_nArgs;
    }
  }
  else if ( (unsigned int)v5 < 6 )
  {
    v3->m_args[v5] = 0x83651CD5;
    ++v3->m_nArgs;
  }
}

// File Line: 2259
// RVA: 0x5964D0
void __fastcall UFG::ActorAudioComponent::AddListenerArgument(UFG::ActorAudioComponent *this, UFG::SimObject *simObject, UFG::DialogArgList *args)
{
  UFG::DialogArgList *v3; // rbx
  unsigned __int16 v4; // cx
  UFG::ActorAudioComponent *v5; // rax
  unsigned int v6; // ecx
  __int64 v7; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  if ( simObject )
  {
    v3 = args;
    v4 = simObject->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>((UFG::SimObjectCharacter *)simObject);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)simObject,
                                           UFG::ActorAudioComponent::_TypeUID);
      else
        v5 = (UFG::ActorAudioComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)simObject,
                                                             UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     simObject,
                                                                                                     UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)simObject,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = UFG::ActorAudioComponent::GetVoiceId(v5, &result)->mUID;
      if ( v6 )
      {
        v7 = v3->m_nArgs;
        if ( (unsigned int)v7 < 6 )
        {
          v3->m_args[v7] = v6;
          ++v3->m_nArgs;
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
  return atexit(UFG::_dynamic_atexit_destructor_for__loc_footwear_type__);
}

// File Line: 2278
// RVA: 0x155A080
__int64 UFG::_dynamic_initializer_for__loc_footstep_type__()
{
  stru_14242F408.mUID = UFG::qWiseSymbolUIDFromString("loc_footstep_type", 0x811C9DC5);
  _((AMD_HD3D *)stru_14242F408.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__loc_footstep_type__);
}

// File Line: 2279
// RVA: 0x1559FD0
__int64 UFG::_dynamic_initializer_for__high_heel__()
{
  high_heel.mUID = UFG::qWiseSymbolUIDFromString("high_heel", 0x811C9DC5);
  _((AMD_HD3D *)high_heel.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__high_heel__);
}

// File Line: 2280
// RVA: 0x155CF20
__int64 UFG::_dynamic_initializer_for__sneaker__()
{
  sneaker.mUID = UFG::qWiseSymbolUIDFromString("sneaker", 0x811C9DC5);
  _((AMD_HD3D *)sneaker.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__sneaker__);
}

// File Line: 2281
// RVA: 0x1559A20
__int64 UFG::_dynamic_initializer_for__barefoot__()
{
  barefoot.mUID = UFG::qWiseSymbolUIDFromString("barefoot", 0x811C9DC5);
  _((AMD_HD3D *)barefoot.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__barefoot__);
}

// File Line: 2282
// RVA: 0x1559B60
__int64 UFG::_dynamic_initializer_for__dress_shoe__()
{
  dress_shoe.mUID = UFG::qWiseSymbolUIDFromString("dress_shoe", 0x811C9DC5);
  _((AMD_HD3D *)dress_shoe.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__dress_shoe__);
}

// File Line: 2283
// RVA: 0x155A0D0
__int64 UFG::_dynamic_initializer_for__loc_footsteps_p__()
{
  stru_14242E938.mUID = UFG::qWiseSymbolUIDFromString("loc_footsteps_p", 0x811C9DC5);
  _((AMD_HD3D *)stru_14242E938.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__loc_footsteps_p__);
}

// File Line: 2284
// RVA: 0x1559800
__int64 UFG::_dynamic_initializer_for__WET_SWITCH__()
{
  WET_SWITCH.mUID = UFG::qWiseSymbolUIDFromString("WET_SWITCH", 0x811C9DC5);
  _((AMD_HD3D *)WET_SWITCH.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__WET_SWITCH__);
}

// File Line: 2285
// RVA: 0x1555460
__int64 UFG::_dynamic_initializer_for__FootwearUnderwear__()
{
  UFG::qSymbol::create_from_string(&FootwearUnderwear, "FootwearUnderwear");
  return atexit(UFG::_dynamic_atexit_destructor_for__FootwearUnderwear__);
}

// File Line: 2286
// RVA: 0x1555590
__int64 UFG::_dynamic_initializer_for__S_GSP__()
{
  UFG::qSymbol::create_from_string(&S_GSP, "S_GSP");
  return atexit(UFG::_dynamic_atexit_destructor_for__S_GSP__);
}

// File Line: 2289
// RVA: 0x59BD30
void __fastcall UFG::ActorAudioComponent::FightImpactCallback(UFG::ActorAudioComponent *this, UFG::eAudioEventCallbackType in_eType, UFG::AudioEvent *in_pEvent, void *in_pCallbackInfo)
{
  if ( in_eType == 2 )
    UFG::AudioEntity::SetWwiseSwitch(in_pEvent->m_pEntity, damage_intensity.mUID, medium.mUID);
}

// File Line: 2299
// RVA: 0x5A6310
void __fastcall UFG::ActorAudioComponent::PlayFootstepLeft(UFG::ActorAudioComponent *this, unsigned int stepId)
{
  unsigned int v2; // esi
  UFG::ActorAudioComponent *v3; // rbx

  v2 = stepId;
  v3 = this;
  if ( this->m_bIsInitialized && (!hardLimitFootsteps || !UFG::OneShotHandle::IsValid(&this->m_leftFootstep)) )
  {
    if ( UFG::OneShotHandle::IsValid(&v3->m_leftFootstep)
      || (UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->m_transformNodeComponent.m_pPointer),
          UFG::OneShotPool::GetOneShotHandle(&v3->m_leftFootstep, &v3->m_WorldMatrix),
          UFG::OneShotHandle::IsValid(&v3->m_leftFootstep)) )
    {
      UFG::ActorAudioComponent::PlayFootstep(v3, v2, &v3->m_leftFootstep);
    }
  }
}

// File Line: 2322
// RVA: 0x5A63B0
void __fastcall UFG::ActorAudioComponent::PlayFootstepRight(UFG::ActorAudioComponent *this, unsigned int stepId)
{
  unsigned int v2; // esi
  UFG::ActorAudioComponent *v3; // rbx

  v2 = stepId;
  v3 = this;
  if ( this->m_bIsInitialized && (!hardLimitFootsteps || !UFG::OneShotHandle::IsValid(&this->m_rightFootstep)) )
  {
    if ( UFG::OneShotHandle::IsValid(&v3->m_rightFootstep)
      || (UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->m_transformNodeComponent.m_pPointer),
          UFG::OneShotPool::GetOneShotHandle(&v3->m_rightFootstep, &v3->m_WorldMatrix),
          UFG::OneShotHandle::IsValid(&v3->m_rightFootstep)) )
    {
      UFG::ActorAudioComponent::PlayFootstep(v3, v2, &v3->m_rightFootstep);
    }
  }
}

// File Line: 2345
// RVA: 0x5A6120
void __fastcall UFG::ActorAudioComponent::PlayFootstep(UFG::ActorAudioComponent *this, unsigned int stepID, UFG::OneShotHandle *oneShot)
{
  unsigned __int64 *v3; // rbx
  unsigned int v4; // ebp
  UFG::ActorAudioComponent *v5; // rdi
  bool v6; // r8
  bool v7; // cl
  unsigned int v8; // esi
  UFG::GameStatTracker *v9; // rax
  unsigned int v10; // ecx
  unsigned int v11; // er8
  unsigned int v12; // eax
  char v13; // al
  unsigned int v14; // edx
  UFG::AudioEntity *v15; // rcx
  unsigned int v16; // eax

  v3 = (unsigned __int64 *)oneShot;
  v4 = stepID;
  v5 = this;
  v6 = UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled && UFG::AudioListener::sm_pInstance->m_highSpeedMode;
  v7 = UFG::GunshotManager::ms_instance->m_numAiGunshots.m_currentValue >= 4.0
    && UFG::FacialActionTreeComponent::sDisableFacialAnimationUpdate;
  if ( stepID != 0
    && (*((_BYTE *)v5 + 553) & 8
     || !v6
     && UFG::ActorAudioComponent::sm_numPerFrameFootsteps < UFG::ActorAudioComponent::sm_maxPerFrameFootsteps
     && !v7) )
  {
    ++UFG::ActorAudioComponent::sm_numPerFrameFootsteps;
    if ( UFG::OneShotHandle::IsValid((UFG::OneShotHandle *)v3) )
    {
      v8 = sneaker.mUID;
      if ( *((_BYTE *)v5 + 553) & 8 )
      {
        v9 = UFG::GameStatTracker::Instance();
        v10 = UFG::GameStatTracker::GetStat(v9, CurrentFootwear)->mValue.mUID;
        if ( v10 == FootwearUnderwear.mUID || v10 == S_GSP.mUID )
          v11 = barefoot.mUID;
        else
          v11 = sneaker.mUID;
      }
      else
      {
        v12 = (unsigned __int64)UFG::ActorAudioComponent::GetFootwearType(v5);
        v8 = v12;
        if ( v12 )
        {
          v11 = v12;
        }
        else
        {
          v13 = *((_BYTE *)v5 + 553);
          if ( !(v13 & 0x40) )
          {
            v14 = switchId.mUID;
            v15 = (UFG::AudioEntity *)*v3;
            if ( v13 >= 0 )
              v11 = dress_shoe.mUID;
            else
              v11 = high_heel.mUID;
LABEL_28:
            UFG::AudioEntity::SetWwiseSwitch(v15, v14, v11);
            if ( UFG::ActorAudioComponent::IsInWater(v5, 0.0) )
            {
              if ( _S28_1 & 1 )
              {
                v16 = water_uid;
              }
              else
              {
                _S28_1 |= 1u;
                v16 = UFG::TiDo::CalcWwiseUid("surface_water");
                water_uid = v16;
              }
            }
            else
            {
              v16 = UFG::TidoGame::FindGroundSurfaceMaterial(v5->m_pSimObject, v8);
            }
            UFG::TidoGame::SetSurfaceMaterial(*v3, v16);
            UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)*v3, stru_14242F408.mUID, v4);
            UFG::OneShot::Play((UFG::OneShot *)*v3, stru_14242E938.mUID);
            return;
          }
          v11 = dress_shoe.mUID;
        }
      }
      v14 = switchId.mUID;
      v15 = (UFG::AudioEntity *)*v3;
      goto LABEL_28;
    }
  }
}

// File Line: 2415
// RVA: 0x5A5DE0
void __fastcall UFG::ActorAudioComponent::PlayFightImpact(UFG::ActorAudioComponent *this, unsigned int attack, unsigned int target, unsigned int intensity)
{
  UFG::ActorAudioComponent *v4; // rbx
  UFG::AudioEntity *v5; // rcx
  unsigned int v6; // edi
  unsigned int v7; // esi
  UFG::AudioEntity *v8; // rcx
  __int64 v9; // [rsp+40h] [rbp-38h]
  UFG::AudioEventInitParams pInitParams; // [rsp+48h] [rbp-30h]

  v4 = this;
  v5 = this->m_SFXEntity;
  v6 = intensity;
  v7 = target;
  if ( v5 )
  {
    UFG::AudioEntity::SetWwiseSwitch(v5, 0x20F621E3u, attack);
    UFG::AudioEntity::SetWwiseSwitch(v4->m_SFXEntity, 0xF17446D4, v7);
    UFG::AudioEntity::SetWwiseSwitch(v4->m_SFXEntity, 0x8A4FA224, v6);
    v8 = v4->m_SFXEntity;
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
void __fastcall UFG::ActorAudioComponent::PlayFightRumble(UFG::ActorAudioComponent *this, unsigned int attack, unsigned int target, unsigned int intensity)
{
  unsigned int v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // ebp
  UFG::ActorAudioComponent *v7; // rbx

  v4 = intensity;
  v5 = target;
  v6 = attack;
  v7 = this;
  if ( this->m_SFXEntity )
  {
    if ( !(_S29 & 1) )
    {
      _S29 |= 1u;
      play_fight_rumble = UFG::TiDo::CalcWwiseUid("play_motion_fighting");
    }
    UFG::AudioEntity::SetWwiseSwitch(v7->m_SFXEntity, 0x20F621E3u, v6);
    UFG::AudioEntity::SetWwiseSwitch(v7->m_SFXEntity, 0xF17446D4, v5);
    UFG::AudioEntity::SetWwiseSwitch(v7->m_SFXEntity, 0x8A4FA224, v4);
    if ( v5 != -1793093012 )
      UFG::AudioEntity::CreateAndPlayEvent(v7->m_SFXEntity, play_fight_rumble, 0i64, 0, 0i64);
  }
}

// File Line: 2509
// RVA: 0x5A0530
bool __fastcall UFG::ActorAudioComponent::IsInWater(UFG::ActorAudioComponent *this, float depth)
{
  UFG::ActorAudioComponent *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterPhysicsComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID)),
                                                 v5 = (UFG::CharacterPhysicsComponent *)v6) : (v5 = (UFG::CharacterPhysicsComponent *)v3->m_Components.p[27].m_pComponent),
        v5 && UFG::CharacterPhysicsComponent::IsInWater(v5)) )
  {
    result = (float)(UFG::CharacterPhysicsComponent::GetWaterElevation(v5) - v2->m_WorldMatrix.v3.z) > depth;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 2526
// RVA: 0x5A3040
__int64 __fastcall UFG::ActorAudioComponent::LookupAndShowSubtitleFromPropertySet(unsigned int uid)
{
  unsigned int v1; // ebx
  UFG::allocator::free_link *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  UFG::UIHKTextOverlay *v5; // rax
  __int64 result; // rax

  v1 = uid;
  if ( (UFG::SubtitleManager::sm_subtitleMode == 2
     || UFG::SubtitleManager::sm_subtitleMode == 3 && UFG::SubtitleManager::LabelIsCantonese(uid))
    && ((v2 = UFG::qMalloc(0xD0ui64, "UISubtitleMessage", 0i64)) == 0i64 ? (v4 = 0i64) : (UFG::UISubtitleMessage::UISubtitleMessage(
                                                                                            (UFG::UISubtitleMessage *)v2,
                                                                                            0,
                                                                                            v1,
                                                                                            0i64),
                                                                                          v4 = v3),
        *(_DWORD *)(v4 + 24) = 1097859072,
        (v5 = UFG::UIHKTextOverlay::getInstance()) != 0i64) )
  {
    result = UFG::UIHKTextOverlay::QueueMessage(v5, (UFG::UISubtitleMessage *)v4);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 2923
// RVA: 0x59CCD0
UFG::Conversation *__fastcall UFG::ActorAudioComponent::GetActiveAmbientConversation(UFG::ActorAudioComponent *this)
{
  unsigned int v1; // edx
  UFG::qBaseTreeRB *v2; // rax
  UFG::Conversation *result; // rax

  v1 = this->m_activeAmbientConversationId;
  if ( v1 && (v2 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v1)) != 0i64 )
    result = (UFG::Conversation *)&v2[-1].mCount;
  else
    result = 0i64;
  return result;
}

// File Line: 2933
// RVA: 0x5A8700
UFG::SimComponent *__fastcall UFG::ActorAudioComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *v6; // rdx
  unsigned int v7; // ebx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x230ui64, "ActorAudioComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::ActorAudioComponent::ActorAudioComponent((UFG::ActorAudioComponent *)v3, v2);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v2->m_pSimObject;
  if ( (v6->m_Flags >> 14) & 1 )
    v7 = 40;
  else
    v7 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v9, v6, 1);
  UFG::SimObjectModifier::AttachComponent(&v9, v5, v7);
  UFG::SimObjectModifier::Close(&v9);
  UFG::SimObjectModifier::~SimObjectModifier(&v9);
  return v5;
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
  `eh vector constructor iterator'(
    UFG::TaggedDialogueStateManager::m_states,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::TaggedDialogueState::TaggedDialogueState);
  return atexit(dynamic_atexit_destructor_for__UFG::TaggedDialogueStateManager::m_states__);
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
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h]

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
  v2 = (signed int)UFG::qRandom(3, &UFG::qDefaultSeed);
  if ( (_DWORD)v2 == UFG::TaggedDialogueStateManager::m_stateIdx )
    return 0;
  UFG::TiDo::UnloadWwiseBank(&bankId + 4 * UFG::TaggedDialogueStateManager::m_stateIdx);
  UFG::TaggedDialogueStateManager::m_stateIdx = v2;
  UFG::TiDo::LoadWwiseBank(&bankId + 4 * v2);
  return 1;
}

// File Line: 3055
// RVA: 0x5AA850
void __fastcall UFG::AmbientContextManager::Set(UFG::AmbientContextManager *this, UFG::qWiseSymbol *context, unsigned int chosen_idx)
{
  unsigned __int16 v3; // r13
  unsigned int v4; // er15
  UFG::AmbientContextManager *v5; // rsi
  __int64 v6; // r11
  unsigned __int16 v7; // r12
  unsigned int v8; // er9
  __int64 v9; // rcx
  unsigned int v10; // edx
  UFG::AmbientContextNode *v11; // rax
  unsigned int v12; // edi
  unsigned __int16 v13; // bp
  UFG::AmbientContextNode *v14; // rbx
  signed __int64 v15; // r14
  signed __int64 v16; // rbx
  signed __int64 v17; // rcx
  UFG::qWiseSymbol *source; // [rsp+58h] [rbp+10h]

  source = context;
  v3 = UFG::Metrics::msFrameCount;
  v4 = 0;
  v5 = this;
  v6 = (signed int)this->m_nodes.size;
  v7 = chosen_idx;
  v8 = 0;
  v9 = 0i64;
  if ( (signed int)v6 <= 0 )
    goto LABEL_5;
  v10 = context->mUID;
  v11 = v5->m_nodes.p;
  while ( v11->m_context.mUID != v10 )
  {
    ++v9;
    ++v8;
    ++v11;
    if ( v9 >= v6 )
      goto LABEL_5;
  }
  if ( (v8 & 0x80000000) != 0 )
  {
LABEL_5:
    v12 = 0;
    v13 = -1;
    if ( (signed int)v6 <= 0 )
    {
LABEL_10:
      v12 = v4;
    }
    else
    {
      while ( 1 )
      {
        v14 = v5->m_nodes.p;
        v15 = v12;
        if ( v14[v15].m_context.mUID == UFG::qWiseSymbol::get_null()->mUID )
          break;
        if ( v5->m_nodes.p[v15].m_age < v13 )
        {
          v13 = v5->m_nodes.p[v15].m_age;
          v4 = v12;
        }
        if ( (signed int)++v12 >= (signed int)v5->m_nodes.size )
          goto LABEL_10;
      }
    }
    v16 = v12;
    UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)&v5->m_nodes.p[v16], source);
    v5->m_nodes.p[v16].m_lastIdx = v7;
    v5->m_nodes.p[v16].m_age = v3;
  }
  else
  {
    v17 = v8;
    v5->m_nodes.p[v17].m_lastIdx = chosen_idx;
    v5->m_nodes.p[v17].m_age = v3;
  }
}

