// File Line: 45
// RVA: 0x2DDDB0
void __fastcall AudioTask::AudioTask(AudioTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AudioTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&AudioTask::`vftable';
  this->m_oneShot.m_pOneShot = 0i64;
  this->mContext = 0i64;
}

// File Line: 56
// RVA: 0x2E90E0
void __fastcall AudioTask::Begin(AudioTask *this, ActionContext *context)
{
  ActionContext *v2; // rdi
  AudioTask *v3; // rbp
  char v4; // bl
  bool v5; // al
  UFG::SimObjectCharacter *v6; // rcx
  UFG::TransformNodeComponent *v7; // r15
  unsigned __int16 v8; // dx
  UFG::ActorAudioComponent *v9; // rax
  UFG::ActorAudioComponent *v10; // rsi
  UFG::SimObjectGame *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::SimComponent *v13; // rax
  UFG::SimObject *v14; // rbx
  UFG::TransformNodeComponent *v15; // rbx
  ITrack *v16; // rax
  unsigned int v17; // er14
  float v18; // xmm6_4
  bool v19; // r12
  unsigned int v20; // edi
  UFG::AudioEntity *v21; // rcx
  ITrack *v22; // rax
  unsigned int v23; // ebx
  UFG::AudioEntity *v24; // rcx
  ITrack *v25; // rax
  unsigned int v26; // ebx
  UFG::AudioEntity *v27; // rcx
  ITrack *v28; // rax
  unsigned int v29; // edi
  unsigned int v30; // ebx
  UFG::TiDo *v31; // rax
  float v32; // xmm0_4
  UFG::OneShotHandle *v33; // rcx
  UFG::OneShot *v34; // r8
  unsigned int v35; // eax
  UFG::SimObject *v36; // rcx
  unsigned int material; // [rsp+80h] [rbp+8h]

  v2 = context;
  v3 = this;
  this->mContext = context;
  v4 = ((__int64 (*)(void))UFG::TiDo::m_pInstance->vfptr->HighSpeedMode)();
  v5 = UFG::TidoGame::MajorGunBattleMode();
  if ( (v4 || v5) && !BYTE1(v3->m_Track[2].mMasterRate.text.mOffset) )
    return;
  v6 = (UFG::SimObjectCharacter *)v3->mContext->mSimObject.m_pPointer;
  v7 = 0i64;
  if ( v6 )
  {
    v8 = v6->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v6);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v9 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v6->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      else
        v9 = (UFG::ActorAudioComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v6->vfptr,
                                                             UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v6->vfptr,
                                                                                                     UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v9 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v6->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    v10 = v9;
    if ( v9 )
      goto LABEL_82;
  }
  v11 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
  if ( !v11 )
  {
    v10 = 0i64;
    goto LABEL_29;
  }
  v12 = v11->m_Flags;
  if ( (v12 >> 14) & 1 )
  {
    v10 = (UFG::ActorAudioComponent *)v11->m_Components.p[40].m_pComponent;
  }
  else if ( (v12 & 0x8000u) == 0 )
  {
    if ( (v12 >> 13) & 1 )
      v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::HkAudioEntityComponent::_TypeUID);
    else
      v13 = (v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::HkAudioEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::HkAudioEntityComponent::_TypeUID);
    v10 = (UFG::ActorAudioComponent *)v13;
  }
  else
  {
    v10 = (UFG::ActorAudioComponent *)v11->m_Components.p[28].m_pComponent;
  }
  if ( v10 )
  {
LABEL_82:
    if ( (float)(UFG::TidoGame::sm_TagCutoffDist * UFG::TidoGame::sm_TagCutoffDist) <= UFG::AudioEntity::Distance2ToListener(
                                                                                         (UFG::AudioEntity *)&v10->vfptr,
                                                                                         0) )
      return;
  }
LABEL_29:
  if ( !LOBYTE(v3->m_Track[2].mMasterRate.text.mOffset) )
  {
    v14 = v3->mContext->mSimObject.m_pPointer;
    if ( v14 )
      v15 = v14->m_pTransformNodeComponent;
    else
      v15 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v15);
    UFG::OneShotPool::GetOneShotHandle(&v3->m_oneShot, &v15->mWorldTransform);
    if ( !UFG::OneShotHandle::IsValid(&v3->m_oneShot) )
      return;
    if ( (float)(UFG::TidoGame::sm_TagCutoffDist * UFG::TidoGame::sm_TagCutoffDist) <= UFG::AudioEntity::Distance2ToListener(
                                                                                         (UFG::AudioEntity *)&v3->m_oneShot.m_pOneShot->vfptr,
                                                                                         0) )
    {
      UFG::OneShotHandle::StopAndRelease(&v3->m_oneShot);
      return;
    }
  }
  v16 = v3->m_Track;
  v17 = v16[1].mMasterRate.text.mOffset;
  v18 = *(float *)&v16[2].mBreakPoint;
  v19 = 0;
  if ( HIDWORD(v16[1].mMasterRate.text.mOffset) )
  {
    v20 = HIDWORD(v16[1].mMasterRate.text.mOffset);
    if ( UFG::OneShotHandle::IsValid(&v3->m_oneShot) )
    {
      v21 = (UFG::AudioEntity *)&v3->m_oneShot.m_pOneShot->vfptr;
    }
    else
    {
      if ( !v10 )
        goto LABEL_42;
      v21 = (UFG::AudioEntity *)&v10->vfptr;
    }
    UFG::AudioEntity::SetRtpcValue(v21, v20, *(float *)&v3->m_Track[2].m_TrackClassNameUID);
  }
LABEL_42:
  v22 = v3->m_Track;
  if ( !LODWORD(v22[1].mMasterRate.expression.mOffset) )
    goto LABEL_48;
  v23 = v22[1].mMasterRate.expression.mOffset;
  v19 = v23 == -244037932;
  if ( UFG::OneShotHandle::IsValid(&v3->m_oneShot) )
  {
    v24 = (UFG::AudioEntity *)&v3->m_oneShot.m_pOneShot->vfptr;
  }
  else
  {
    if ( !v10 )
      goto LABEL_48;
    v24 = (UFG::AudioEntity *)&v10->vfptr;
  }
  UFG::AudioEntity::SetWwiseSwitch(v24, v23, (unsigned int)v3->m_Track[2].vfptr);
LABEL_48:
  v25 = v3->m_Track;
  if ( *((_DWORD *)&v25[1].mMasterRate.value + 1) )
  {
    v26 = *((_DWORD *)&v25[1].mMasterRate.value + 1);
    v19 = v26 == -244037932;
    if ( UFG::OneShotHandle::IsValid(&v3->m_oneShot) )
    {
      v27 = (UFG::AudioEntity *)&v3->m_oneShot.m_pOneShot->vfptr;
LABEL_53:
      UFG::AudioEntity::SetWwiseSwitch(v27, v26, HIDWORD(v3->m_Track[2].mResourceOwner));
      goto LABEL_54;
    }
    if ( v10 )
    {
      v27 = (UFG::AudioEntity *)&v10->vfptr;
      goto LABEL_53;
    }
  }
LABEL_54:
  v28 = v3->m_Track;
  if ( HIDWORD(v28[1].mMasterRate.expression.mOffset) )
  {
    v29 = HIDWORD(v28[1].mMasterRate.expression.mOffset);
    v30 = HIDWORD(v28[2].vfptr);
    v31 = UFG::TiDo::GetInstance();
    UFG::AudioEntity::SetWwiseState(v31, v29, v30);
  }
  if ( v17 )
  {
    v32 = UFG::qRandom(100.0, &UFG::qDefaultSeed);
    v33 = &v3->m_oneShot;
    if ( v32 >= v18 )
    {
      UFG::OneShotHandle::IsValid(v33);
    }
    else
    {
      material = 0;
      if ( UFG::OneShotHandle::IsValid(v33) )
      {
        v34 = v3->m_oneShot.m_pOneShot;
        _((AMD_HD3D *)v3->mContext->mSimObject.m_pPointer);
      }
      if ( UFG::OneShotHandle::IsValid(&v3->m_oneShot) && !v19 )
        UFG::TidoGame::SetMaterial2((unsigned __int64)v3->m_oneShot.m_pOneShot, material);
      v35 = _S9_5;
      if ( !(_S9_5 & 1) )
      {
        _S9_5 |= 1u;
        UFG::qWiseSymbol::create_from_string(&play_door_close, "play_door_close");
        atexit(AudioTask::Begin_::_55_::_dynamic_atexit_destructor_for__play_door_close__);
        v35 = _S9_5;
      }
      if ( !(v35 & 2) )
      {
        _S9_5 = v35 | 2;
        UFG::qWiseSymbol::create_from_string(&play_door_open, "play_door_open");
        atexit(AudioTask::Begin_::_55_::_dynamic_atexit_destructor_for__play_door_open__);
        v35 = _S9_5;
      }
      if ( v17 != play_door_open.mUID && v17 != play_door_close.mUID )
      {
        if ( !(v35 & 4) )
        {
          _S9_5 = v35 | 4;
          UFG::qWiseSymbol::create_from_string(&play_fighting_head_smash, "play_fighting_head_smash");
          atexit(AudioTask::Begin_::_58_::_dynamic_atexit_destructor_for__play_fighting_head_smash__);
        }
        if ( v17 == play_fighting_head_smash.mUID )
        {
          v36 = v3->mContext->mSimObject.m_pPointer;
          if ( v36 )
            v7 = v36->m_pTransformNodeComponent;
          UFG::TransformNodeComponent::UpdateWorldTransform(v7);
          UFG::TidoGame::PlayFightHeadSmash(
            (UFG::TidoGame *)UFG::TiDo::m_pInstance,
            (UFG::qVector3 *)&v7->mWorldTransform.v3);
        }
        else if ( UFG::OneShotHandle::IsValid(&v3->m_oneShot) )
        {
          UFG::OneShot::Play(v3->m_oneShot.m_pOneShot, v17);
        }
        else if ( v10 )
        {
          UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v10->vfptr, v17, 0i64, 0, 0i64);
        }
      }
    }
  }
}

// File Line: 215
// RVA: 0x303B20
char __fastcall AudioTask::Update(AudioTask *this, float timeDelta)
{
  AudioTask *v2; // rsi
  char result; // al
  ActionContext *v4; // rcx
  UFG::SimObjectCharacter *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::ActorAudioComponent *v7; // rax
  bool v8; // zf

  v2 = this;
  if ( UFG::OneShotHandle::IsValid(&this->m_oneShot) )
  {
    if ( v2->m_oneShot.m_pOneShot->m_controller.m_pEvent )
    {
      result = 1;
    }
    else
    {
      UFG::OneShotHandle::Release(&v2->m_oneShot);
      result = 0;
    }
  }
  else
  {
    v4 = v2->mContext;
    if ( !v4
      || (v5 = (UFG::SimObjectCharacter *)v4->mSimObject.m_pPointer) == 0i64
      || ((v6 = v5->m_Flags, !((v6 >> 14) & 1)) ? ((v6 & 0x8000u) == 0 ? (!((v6 >> 13) & 1) ? (!((v6 >> 12) & 1) ? (v7 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::ActorAudioComponent::_TypeUID)) : (v7 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v7 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v7 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v7 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v5)),
          !v7
       || (v8 = UFG::AudioEntity::IsPlayingId((UFG::AudioEntity *)&v7->vfptr, v2->m_Track[1].mMasterRate.text.mOffset) == 0,
           result = 1,
           v8)) )
    {
      result = 0;
    }
  }
  return result;
}

// File Line: 261
// RVA: 0x2FDFF0
void __fastcall AudioTask::End(AudioTask *this)
{
  ITrack *v1; // rax
  AudioTask *v2; // rbx
  UFG::OneShotHandle *v3; // rcx
  unsigned int v4; // esi
  ActionContext *v5; // rcx
  UFG::SimObjectCharacter *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::ActorAudioComponent *v8; // rax

  v1 = this->m_Track;
  v2 = this;
  v3 = &this->m_oneShot;
  v4 = LODWORD(v1[1].mMasterRate.value);
  if ( v4 )
  {
    if ( UFG::OneShotHandle::IsValid(v3) )
    {
      UFG::OneShot::Stop(v2->m_oneShot.m_pOneShot, 0x1388u, v4);
      UFG::OneShotHandle::Release(&v2->m_oneShot);
    }
    else
    {
      v5 = v2->mContext;
      if ( v5 )
      {
        v6 = (UFG::SimObjectCharacter *)v5->mSimObject.m_pPointer;
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
          if ( v8 )
            UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v8->vfptr, v4, 0i64, 0, 0i64);
        }
      }
    }
  }
  else if ( UFG::OneShotHandle::IsValid(v3) )
  {
    UFG::OneShot::Stop(v2->m_oneShot.m_pOneShot, 0x1388u, 0);
    UFG::OneShotHandle::Release(&v2->m_oneShot);
  }
}

// File Line: 326
// RVA: 0x2E9770
void __fastcall AudioTaskSimple::Begin(AudioTaskSimple *this, ActionContext *context)
{
  AudioTaskSimple *v2; // rdi
  char v3; // bl
  bool v4; // al
  UFG::SimObjectCharacter *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::ActorAudioComponent *v7; // rax

  this->mContext = context;
  v2 = this;
  v3 = ((__int64 (*)(void))UFG::TiDo::m_pInstance->vfptr->HighSpeedMode)();
  v4 = UFG::TidoGame::MajorGunBattleMode();
  if ( !v3 && !v4 || LOBYTE(v2->m_Track[1].mResourceOwner) )
  {
    v5 = (UFG::SimObjectCharacter *)v2->mContext->mSimObject.m_pPointer;
    if ( v5
      && ((v6 = v5->m_Flags, !((v6 >> 14) & 1)) ? ((v6 & 0x8000u) == 0 ? (!((v6 >> 13) & 1) ? (!((v6 >> 12) & 1) ? (v7 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::ActorAudioComponent::_TypeUID)) : (v7 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v7 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v7 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v5->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v7 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v5)),
          v7 && UFG::ActorAudioComponent::IsAlive(v7, 0)) )
    {
      AudioTaskSimple::PlayOnActor(v2);
      v2->m_playOnActor = 1;
    }
    else
    {
      AudioTaskSimple::PlayOnOneShot(v2);
      v2->m_playOnActor = 0;
    }
  }
}

// File Line: 379
// RVA: 0x302AF0
void __fastcall AudioTaskSimple::PlayOnOneShot(AudioTaskSimple *this)
{
  AudioTaskSimple *v1; // rdi
  UFG::SimObject *v2; // rsi
  UFG::TransformNodeComponent *v3; // rsi
  UFG::OneShotHandle *v4; // rbx
  UFG::qMatrix44 *v5; // rdx
  unsigned int v6; // esi
  ActionContext *v7; // rcx
  UFG::OneShotHandle v8; // r8
  unsigned int material; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = this->mContext->mSimObject.m_pPointer;
  if ( v2 && (v3 = v2->m_pTransformNodeComponent) != 0i64 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    v4 = &v1->m_oneShot;
    v5 = &v3->mWorldTransform;
  }
  else
  {
    v4 = &this->m_oneShot;
    v5 = &UFG::qMatrix44::msIdentity;
  }
  UFG::OneShotPool::GetOneShotHandle(v4, v5);
  if ( UFG::OneShotHandle::IsValid(v4) )
  {
    if ( UFG::AudioEntity::Distance2ToListener((UFG::AudioEntity *)&v4->m_pOneShot->vfptr, 0) < (float)(UFG::TidoGame::sm_TagCutoffDist * UFG::TidoGame::sm_TagCutoffDist) )
    {
      v6 = HIDWORD(v1->m_Track[1].vfptr);
      if ( v6 )
      {
        v7 = v1->mContext;
        v8.m_pOneShot = v4->m_pOneShot;
        material = 0;
        _((AMD_HD3D *)v7->mSimObject.m_pPointer);
        UFG::TidoGame::SetMaterial2((unsigned __int64)v4->m_pOneShot, material);
        UFG::OneShot::Play(v4->m_pOneShot, v6);
      }
    }
    else
    {
      UFG::OneShotHandle::StopAndRelease(v4);
    }
  }
}

// File Line: 450
// RVA: 0x303C30
char __fastcall AudioTaskSimple::Update(AudioTaskSimple *this, float timeDelta)
{
  AudioTaskSimple *v2; // rbx
  UFG::OneShotHandle *v3; // rdi
  UFG::SimObject *v4; // rcx
  UFG::TransformNodeComponent *v5; // rbx
  UFG::OneShotHandle v6; // rcx
  UFG::qVector4 v7; // xmm3
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  char result; // al
  ActionContext *v11; // rcx
  UFG::SimObjectCharacter *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::ActorAudioComponent *v14; // rax
  UFG::ActorAudioComponent *v15; // rcx
  ITrack *v16; // rax
  UFG::AudioEntity *v17; // rcx
  bool v18; // zf

  v2 = this;
  if ( this->m_playOnActor || (v3 = &this->m_oneShot, !UFG::OneShotHandle::IsValid(&this->m_oneShot)) )
  {
    if ( !v2->m_playOnActor )
      goto LABEL_26;
    v11 = v2->mContext;
    if ( !v11 )
      goto LABEL_26;
    v12 = (UFG::SimObjectCharacter *)v11->mSimObject.m_pPointer;
    if ( !v12 )
      goto LABEL_26;
    v13 = v12->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v14 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v12);
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
        v14 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v12->vfptr,
                                            UFG::ActorAudioComponent::_TypeUID);
      else
        v14 = (UFG::ActorAudioComponent *)((v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v12->vfptr,
                                                               UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v14 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v12->vfptr,
                                          UFG::ActorAudioComponent::_TypeUID);
    }
    v15 = v14;
    v16 = v2->m_Track;
    v17 = v15->m_SFXEntity;
    if ( !v17 || (v18 = UFG::AudioEntity::IsPlayingId(v17, HIDWORD(v16[1].vfptr)) == 0, result = 1, v18) )
LABEL_26:
      result = 0;
  }
  else if ( v3->m_pOneShot->m_controller.m_pEvent )
  {
    v4 = v2->mContext->mSimObject.m_pPointer;
    if ( v4 )
    {
      v5 = v4->m_pTransformNodeComponent;
      if ( v5 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v4->m_pTransformNodeComponent);
        v6.m_pOneShot = v3->m_pOneShot;
        v7 = v5->mWorldTransform.v1;
        v8 = v5->mWorldTransform.v2;
        v9 = v5->mWorldTransform.v3;
        v6.m_pOneShot->m_WorldMatrix.v0 = v5->mWorldTransform.v0;
        v6.m_pOneShot->m_WorldMatrix.v1 = v7;
        v6.m_pOneShot->m_WorldMatrix.v2 = v8;
        v6.m_pOneShot->m_WorldMatrix.v3 = v9;
        UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&v6.m_pOneShot->vfptr);
      }
    }
    result = 1;
  }
  else
  {
    UFG::OneShotHandle::Release(v3);
    result = 0;
  }
  return result;
}

// File Line: 501
// RVA: 0x2DDE50
void __fastcall AudioTaskSoundbankIO::AudioTaskSoundbankIO(AudioTaskSoundbankIO *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AudioTrackSoundbankIO>::`vftable';
  this->vfptr = (ITaskVtbl *)&AudioTaskSoundbankIO::`vftable';
}

// File Line: 511
// RVA: 0x2E9870
void __fastcall AudioTaskSoundbankIO::Begin(AudioTaskSoundbankIO *this, ActionContext *context)
{
  unsigned int v2; // edx
  UFG::qWiseSymbol *v3; // rax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h]

  v2 = this->m_Track[1].mMasterRate.text.mOffset;
  if ( v2 )
  {
    v3 = UFG::qSymbol::qSymbol(&result, v2);
    UFG::TiDo::LoadWwiseBank(v3);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 524
// RVA: 0x2FE120
void __fastcall AudioTaskSoundbankIO::End(AudioTaskSoundbankIO *this)
{
  unsigned int v1; // edx
  UFG::qWiseSymbol *v2; // rax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h]

  v1 = this->m_Track[1].mMasterRate.text.mOffset;
  if ( v1 )
  {
    v2 = UFG::qSymbol::qSymbol(&result, v1);
    UFG::TiDo::UnloadWwiseBank(v2);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 539
// RVA: 0x2DDE00
void __fastcall AudioTaskMusicState::AudioTaskMusicState(AudioTaskMusicState *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AudioTrackMusicState>::`vftable';
  this->vfptr = (ITaskVtbl *)&AudioTaskMusicState::`vftable';
}

// File Line: 549
// RVA: 0x2E95A0
void __fastcall AudioTaskMusicState::Begin(AudioTaskMusicState *this, ActionContext *context)
{
  AudioTaskMusicState *v2; // rdi
  ITrack *v3; // rcx
  const char *v4; // rdx
  UFG::qString *v5; // rax
  char v6; // bl
  Expression::IMemberMap **v7; // rcx
  const char *v8; // rcx
  unsigned int v9; // ebx
  Expression::IMemberMap **v10; // rdx
  const char *v11; // rcx
  unsigned int v12; // eax
  UFG::qString *v13; // rax
  char v14; // bl
  ITrack *v15; // rdx
  const char *v16; // rsi
  const char *v17; // rcx
  unsigned int v18; // ebx
  unsigned int v19; // eax
  ITrack *v20; // rcx
  const char *v21; // r8
  const char *v22; // r9
  UFG::qString v23; // [rsp+28h] [rbp-60h]
  UFG::qString result; // [rsp+50h] [rbp-38h]

  v2 = this;
  v3 = this->m_Track + 1;
  v4 = (char *)v3 + ((_QWORD)v3->vfptr & 0xFFFFFFFFFFFFFFFEui64);
  if ( !((_QWORD)v3->vfptr & 0xFFFFFFFFFFFFFFFEui64) )
    v4 = BinString::sEmptyString;
  UFG::qString::qString(&v23, v4);
  v5 = UFG::qString::ToLower(&v23, &result);
  v6 = UFG::qString::operator==(v5, "music_event");
  UFG::qString::~qString(&result);
  if ( v6 )
  {
    v7 = &v2->m_Track[1].mResourceOwner;
    if ( (unsigned __int64)*v7 & 0xFFFFFFFFFFFFFFFEui64 )
      v8 = (char *)v7 + ((unsigned __int64)*v7 & 0xFFFFFFFFFFFFFFFEui64);
    else
      v8 = BinString::sEmptyString;
    v9 = UFG::TiDo::CalcWwiseUid(v8);
    if ( v9 != AudioTaskMusicState::m_lastPlayEvent )
    {
      v10 = &v2->m_Track[1].mResourceOwner;
      if ( (unsigned __int64)*v10 & 0xFFFFFFFFFFFFFFFEui64 )
        v11 = (char *)v10 + ((unsigned __int64)*v10 & 0xFFFFFFFFFFFFFFFEui64);
      else
        v11 = BinString::sEmptyString;
      v12 = UFG::TiDo::CalcWwiseUid(v11);
      UFG::Music::MusicEvent(v12);
      AudioTaskMusicState::m_lastPlayEvent = v9;
    }
  }
  else
  {
    v13 = UFG::qString::ToLower(&v23, &result);
    v14 = UFG::qString::operator==(v13, "end_nis");
    UFG::qString::~qString(&result);
    if ( v14 )
    {
      AudioTaskMusicState::m_lastPlayEvent = 0;
    }
    else
    {
      v15 = v2->m_Track;
      v16 = BinString::sEmptyString;
      if ( (_QWORD)v15[1].mResourceOwner & 0xFFFFFFFFFFFFFFFEui64 )
        v17 = (char *)&v15[1].mResourceOwner + ((_QWORD)v15[1].mResourceOwner & 0xFFFFFFFFFFFFFFFEui64);
      else
        v17 = BinString::sEmptyString;
      if ( (_QWORD)v15[1].vfptr & 0xFFFFFFFFFFFFFFFEui64 )
        v16 = (char *)&v15[1] + ((_QWORD)v15[1].vfptr & 0xFFFFFFFFFFFFFFFEui64);
      v18 = UFG::TiDo::CalcWwiseUid(v17);
      v19 = UFG::TiDo::CalcWwiseUid(v16);
      UFG::Music::SetMusicState(v19, v18);
    }
  }
  v20 = v2->m_Track;
  v21 = BinString::sEmptyString;
  if ( (_QWORD)v20[1].mResourceOwner & 0xFFFFFFFFFFFFFFFEui64 )
    v22 = (char *)&v20[1].mResourceOwner + ((_QWORD)v20[1].mResourceOwner & 0xFFFFFFFFFFFFFFFEui64);
  else
    v22 = BinString::sEmptyString;
  if ( (_QWORD)v20[1].vfptr & 0xFFFFFFFFFFFFFFFEui64 )
    v21 = (char *)&v20[1] + ((_QWORD)v20[1].vfptr & 0xFFFFFFFFFFFFFFFEui64);
  UFG::qPrintf("%s, AudioTaskMusicState - (%s %s)\n", UFG::TidoGame::sm_timeStampStr.mData, v21, v22, -2i64);
  UFG::qString::~qString(&v23);
}

