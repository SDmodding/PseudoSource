// File Line: 56
// RVA: 0x5AF840
void UFG::WorldAudioEmitterManager::Update(void)
{
  UFG::TiDo *v0; // rax
  UFG::Audio3DListener *v1; // rsi
  float v2; // xmm9_4
  bool v3; // bp
  Render::SkinningCacheNode *v4; // rax
  signed __int64 v5; // rbx
  UFG::qBaseNodeRB *v6; // rdx
  UFG::qBaseTreeRB *v7; // rax
  signed __int64 v8; // rdi
  __int64 v9; // rax
  float v10; // xmm8_4
  float v11; // xmm6_4
  float v12; // xmm7_4

  v0 = UFG::TiDo::GetInstance();
  v1 = UFG::TiDo::GetListener(v0, 0);
  if ( (float)((float)((float)(v1->m_matrix.v3.x * v1->m_matrix.v3.x) + (float)(v1->m_matrix.v3.y * v1->m_matrix.v3.y))
             + (float)(v1->m_matrix.v3.z * v1->m_matrix.v3.z)) >= 0.5
    && UFG::AudioListener::sm_pInstance )
  {
    v3 = (UFG::TimeOfDayManager::GetInstance(),
          v2 = UFG::Metrics::msInstance.mSimTime_Temp,
          UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled)
      && UFG::AudioListener::sm_pInstance->m_highSpeedMode
      || UFG::GunshotManager::ms_instance->m_numAiGunshots.m_currentValue >= 4.0
      && UFG::FacialActionTreeComponent::sDisableFacialAnimationUpdate;
    v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioEmitterMarker::msAudioEmitterMarkers);
    if ( v4 )
    {
      v5 = (signed __int64)&v4[-3].mNode.8;
      if ( v4 != (Render::SkinningCacheNode *)112 )
      {
        do
        {
          if ( v5 )
            v6 = (UFG::qBaseNodeRB *)(v5 + 112);
          else
            v6 = 0i64;
          v7 = UFG::qBaseTreeRB::GetNext(&UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree, v6);
          if ( v7 )
            v8 = (signed __int64)&v7[-2].mNULL;
          else
            v8 = 0i64;
          if ( (unsigned int)(*(_DWORD *)(v5 + 160) - 1) <= 0xFFFFFFFD )
          {
            v9 = *(_QWORD *)(v5 + 144);
            if ( v9 && (*(_BYTE *)(v9 + 144) >> 6) & 1 )
            {
              v10 = *(float *)(v5 + 188) - v1->m_matrix.v3.x;
              v11 = *(float *)(v5 + 192) - v1->m_matrix.v3.y;
              v12 = *(float *)(v5 + 196) - v1->m_matrix.v3.z;
              UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v5 + 104));
              if ( (float)((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v12 * v12)) >= *(float *)(v5 + 176) )
                UFG::AudioEmitterMarker::Stop((UFG::AudioEmitterMarker *)v5, 0x7D0u);
            }
            else if ( !(*(_BYTE *)(v5 + 200) & 2)
                   && !v3
                   && (float)((float)((float)((float)(*(float *)(v5 + 192) - v1->m_matrix.v3.y)
                                            * (float)(*(float *)(v5 + 192) - v1->m_matrix.v3.y))
                                    + (float)((float)(*(float *)(v5 + 188) - v1->m_matrix.v3.x)
                                            * (float)(*(float *)(v5 + 188) - v1->m_matrix.v3.x)))
                            + (float)((float)(*(float *)(v5 + 196) - v1->m_matrix.v3.z)
                                    * (float)(*(float *)(v5 + 196) - v1->m_matrix.v3.z))) <= *(float *)(v5 + 176) )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v5 + 104));
              if ( UFG::AudioEmitterMarker::Play((UFG::AudioEmitterMarker *)v5) )
                sNextTurnOnTime = UFG::WorldAudioEmitterManager::sm_turnOnDelay + v2;
            }
          }
          v5 = v8;
        }
        while ( v8 );
      }
    }
  }
}

// File Line: 262
// RVA: 0x5AE630
void UFG::WorldAudioEmitterManager::TurnOffAllEmitters(void)
{
  UFG::qBaseTreeRB *i; // rax
  signed __int64 v1; // rbx
  void **v2; // [rsp+30h] [rbp+8h]

  v2 = &`UFG::WorldAudioEmitterManager::TurnOffAllEmitters'::`2'::TurnOffEmittersFunctor::`vftable';
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioEmitterMarker::msAudioEmitterMarkers);
        ;
        i = UFG::qBaseTreeRB::GetNext(
              &UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree,
              (UFG::qBaseNodeRB *)(v1 + 112)) )
  {
    v1 = (signed __int64)(i ? &i[-2].mNULL : 0i64);
    if ( !v1 )
      break;
    ((void (__fastcall *)(void ***, signed __int64))*v2)(&v2, v1);
  }
}

// File Line: 267
// RVA: 0x59B550
void __fastcall UFG::WorldAudioEmitterManager::TurnOffAllEmitters_::_2_::TurnOffEmittersFunctor::Do(UFG::AudioEmitterMarker *pAem, UFG::AudioEmitterMarker *a2)
{
  UFG::AudioEmitterMarker *v2; // rbx

  v2 = a2;
  UFG::AudioEmitterMarker::Stop(a2, 0);
  UFG::AudioEmitterMarker::Stop(v2, 0x7D0u);
  *((_BYTE *)v2 + 200) |= 2u;
}

