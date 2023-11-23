// File Line: 56
// RVA: 0x5AF840
void UFG::WorldAudioEmitterManager::Update(void)
{
  UFG::TiDo *Instance; // rax
  UFG::Audio3DListener *Listener; // rsi
  float mSimTime_Temp; // xmm9_4
  bool v3; // bp
  Render::SkinningCacheNode *Head; // rax
  UFG::AudioEmitterMarker *v5; // rbx
  UFG::qBaseNodeRB *p_mNode; // rdx
  UFG::qBaseTreeRB *Next; // rax
  UFG::qBaseNodeRB *p_mNULL; // rdi
  UFG::AudioEvent *m_pEvent; // rax
  float v10; // xmm8_4
  float v11; // xmm6_4
  float v12; // xmm7_4

  Instance = UFG::TiDo::GetInstance();
  Listener = UFG::TiDo::GetListener(Instance, 0);
  if ( (float)((float)((float)(Listener->m_matrix.v3.x * Listener->m_matrix.v3.x)
                     + (float)(Listener->m_matrix.v3.y * Listener->m_matrix.v3.y))
             + (float)(Listener->m_matrix.v3.z * Listener->m_matrix.v3.z)) >= 0.5
    && UFG::AudioListener::sm_pInstance )
  {
    v3 = (UFG::TimeOfDayManager::GetInstance(),
          mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp,
          UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled)
      && UFG::AudioListener::sm_pInstance->m_highSpeedMode
      || UFG::GunshotManager::ms_instance->m_numAiGunshots.m_currentValue >= 4.0
      && UFG::FacialActionTreeComponent::sDisableFacialAnimationUpdate;
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioEmitterMarker::msAudioEmitterMarkers);
    if ( Head )
    {
      v5 = (UFG::AudioEmitterMarker *)&Head[-3].mNode.8;
      if ( Head != (Render::SkinningCacheNode *)112 )
      {
        do
        {
          if ( v5 )
            p_mNode = &v5->UFG::qNodeRB<UFG::AudioEmitterMarker>::mNode;
          else
            p_mNode = 0i64;
          Next = UFG::qBaseTreeRB::GetNext(&UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree, p_mNode);
          if ( Next )
            p_mNULL = &Next[-2].mNULL;
          else
            p_mNULL = 0i64;
          if ( v5->m_eventId.mUID - 1 <= 0xFFFFFFFD )
          {
            m_pEvent = v5->m_contoller.m_pEvent;
            if ( m_pEvent && (*((_BYTE *)m_pEvent + 144) & 0x40) != 0 )
            {
              v10 = v5->m_CachedPosition.x - Listener->m_matrix.v3.x;
              v11 = v5->m_CachedPosition.y - Listener->m_matrix.v3.y;
              v12 = v5->m_CachedPosition.z - Listener->m_matrix.v3.z;
              UFG::TransformNodeComponent::UpdateWorldTransform(v5->mpXformNode);
              if ( (float)((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v12 * v12)) >= v5->m_falloffDiameter2 )
                UFG::AudioEmitterMarker::Stop(v5, 2000);
            }
            else if ( (*((_BYTE *)v5 + 200) & 2) == 0
                   && !v3
                   && (float)((float)((float)((float)(v5->m_CachedPosition.y - Listener->m_matrix.v3.y)
                                            * (float)(v5->m_CachedPosition.y - Listener->m_matrix.v3.y))
                                    + (float)((float)(v5->m_CachedPosition.x - Listener->m_matrix.v3.x)
                                            * (float)(v5->m_CachedPosition.x - Listener->m_matrix.v3.x)))
                            + (float)((float)(v5->m_CachedPosition.z - Listener->m_matrix.v3.z)
                                    * (float)(v5->m_CachedPosition.z - Listener->m_matrix.v3.z))) <= v5->m_falloffDiameter2 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v5->mpXformNode);
              if ( UFG::AudioEmitterMarker::Play(v5) )
                sNextTurnOnTime = UFG::WorldAudioEmitterManager::sm_turnOnDelay + mSimTime_Temp;
            }
          }
          v5 = (UFG::AudioEmitterMarker *)p_mNULL;
        }
        while ( p_mNULL );
      }
    }
  }
}

// File Line: 262
// RVA: 0x5AE630
void UFG::WorldAudioEmitterManager::TurnOffAllEmitters(void)
{
  UFG::qBaseTreeRB *i; // rax
  __int64 v1; // rbx
  void **v2; // [rsp+30h] [rbp+8h] BYREF

  v2 = &`UFG::WorldAudioEmitterManager::TurnOffAllEmitters::`2::TurnOffEmittersFunctor::`vftable;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioEmitterMarker::msAudioEmitterMarkers);
        ;
        i = UFG::qBaseTreeRB::GetNext(
              &UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree,
              (UFG::qBaseNodeRB *)(v1 + 112)) )
  {
    v1 = i ? (__int64)&i[-2].mNULL : 0i64;
    if ( !v1 )
      break;
    ((void (__fastcall *)(void ***, __int64))*v2)(&v2, v1);
  }
}

// File Line: 267
// RVA: 0x59B550
void __fastcall UFG::WorldAudioEmitterManager::TurnOffAllEmitters_::_2_::TurnOffEmittersFunctor::Do(
        UFG::AudioEmitterMarker *pAem,
        __int64 a2)
{
  UFG::AudioEmitterMarker::Stop((UFG::AudioEmitterMarker *)a2, 0);
  UFG::AudioEmitterMarker::Stop((UFG::AudioEmitterMarker *)a2, 0x7D0u);
  *(_BYTE *)(a2 + 200) |= 2u;
}

