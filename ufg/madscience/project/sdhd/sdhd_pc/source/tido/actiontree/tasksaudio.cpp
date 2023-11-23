// File Line: 45
// RVA: 0x2DDDB0
void __fastcall AudioTask::AudioTask(AudioTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AudioTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AudioTask::`vftable;
  this->m_oneShot.m_pOneShot = 0i64;
  this->mContext = 0i64;
}

// File Line: 56
// RVA: 0x2E90E0
void __fastcall AudioTask::Begin(AudioTask *this, ActionContext *context)
{
  bool v4; // bl
  bool v5; // al
  UFG::SimObjectCharacter *m_pPointer; // rcx
  UFG::TransformNodeComponent *v7; // r15
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *v9; // rax
  UFG::ActorAudioComponent *m_pComponent; // rsi
  UFG::SimObjectGame *v11; // rcx
  __int16 v12; // dx
  UFG::SimComponent *v13; // rax
  UFG::SimObject *v14; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  ITrack *m_Track; // rax
  unsigned int mOffset; // r14d
  float v18; // xmm6_4
  bool v19; // r12
  unsigned int mOffset_high; // edi
  UFG::OneShot *m_pOneShot; // rcx
  ITrack *v22; // rax
  unsigned int v23; // ebx
  UFG::OneShot *v24; // rcx
  ITrack *v25; // rax
  unsigned int v26; // ebx
  UFG::OneShot *v27; // rcx
  ITrack *v28; // rax
  unsigned int v29; // edi
  unsigned int vfptr_high; // ebx
  UFG::TiDo *Instance; // rax
  float v32; // xmm0_4
  UFG::OneShotHandle *p_m_oneShot; // rcx
  unsigned int v34; // eax
  UFG::SimObject *v35; // rcx

  this->mContext = context;
  v4 = UFG::TiDo::m_pInstance->vfptr->HighSpeedMode(UFG::TiDo::m_pInstance);
  v5 = UFG::TidoGame::MajorGunBattleMode();
  if ( (v4 || v5) && !BYTE1(this->m_Track[2].mMasterRate.text.mOffset) )
    return;
  m_pPointer = (UFG::SimObjectCharacter *)this->mContext->mSimObject.m_pPointer;
  v7 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v9 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    else
      v9 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID));
    m_pComponent = v9;
    if ( v9 )
      goto LABEL_26;
  }
  v11 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v11 )
  {
    m_pComponent = 0i64;
    goto LABEL_27;
  }
  v12 = v11->m_Flags;
  if ( (v12 & 0x4000) != 0 )
  {
    m_pComponent = (UFG::ActorAudioComponent *)v11->m_Components.p[40].m_pComponent;
  }
  else if ( v12 >= 0 )
  {
    v13 = (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::HkAudioEntityComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v11, UFG::HkAudioEntityComponent::_TypeUID);
    m_pComponent = (UFG::ActorAudioComponent *)v13;
  }
  else
  {
    m_pComponent = (UFG::ActorAudioComponent *)v11->m_Components.p[28].m_pComponent;
  }
  if ( m_pComponent )
  {
LABEL_26:
    if ( (float)(UFG::TidoGame::sm_TagCutoffDist * UFG::TidoGame::sm_TagCutoffDist) <= UFG::AudioEntity::Distance2ToListener(
                                                                                         &m_pComponent->UFG::AudioEntity,
                                                                                         0) )
      return;
  }
LABEL_27:
  if ( !LOBYTE(this->m_Track[2].mMasterRate.text.mOffset) )
  {
    v14 = this->mContext->mSimObject.m_pPointer;
    if ( v14 )
      m_pTransformNodeComponent = v14->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    UFG::OneShotPool::GetOneShotHandle(&this->m_oneShot, &m_pTransformNodeComponent->mWorldTransform);
    if ( !UFG::OneShotHandle::IsValid(&this->m_oneShot) )
      return;
    if ( (float)(UFG::TidoGame::sm_TagCutoffDist * UFG::TidoGame::sm_TagCutoffDist) <= UFG::AudioEntity::Distance2ToListener(
                                                                                         this->m_oneShot.m_pOneShot,
                                                                                         0) )
    {
      UFG::OneShotHandle::StopAndRelease(&this->m_oneShot);
      return;
    }
  }
  m_Track = this->m_Track;
  mOffset = m_Track[1].mMasterRate.text.mOffset;
  v18 = *(float *)&m_Track[2].mBreakPoint;
  v19 = 0;
  if ( HIDWORD(m_Track[1].mMasterRate.text.mOffset) )
  {
    mOffset_high = HIDWORD(m_Track[1].mMasterRate.text.mOffset);
    if ( UFG::OneShotHandle::IsValid(&this->m_oneShot) )
    {
      m_pOneShot = this->m_oneShot.m_pOneShot;
    }
    else
    {
      if ( !m_pComponent )
        goto LABEL_40;
      m_pOneShot = (UFG::OneShot *)&m_pComponent->UFG::AudioEntity;
    }
    UFG::AudioEntity::SetRtpcValue(m_pOneShot, mOffset_high, *(float *)&this->m_Track[2].m_TrackClassNameUID);
  }
LABEL_40:
  v22 = this->m_Track;
  if ( !LODWORD(v22[1].mMasterRate.expression.mOffset) )
    goto LABEL_46;
  v23 = v22[1].mMasterRate.expression.mOffset;
  v19 = v23 == -244037932;
  if ( UFG::OneShotHandle::IsValid(&this->m_oneShot) )
  {
    v24 = this->m_oneShot.m_pOneShot;
  }
  else
  {
    if ( !m_pComponent )
      goto LABEL_46;
    v24 = (UFG::OneShot *)&m_pComponent->UFG::AudioEntity;
  }
  UFG::AudioEntity::SetWwiseSwitch(v24, v23, (unsigned int)this->m_Track[2].vfptr);
LABEL_46:
  v25 = this->m_Track;
  if ( *((_DWORD *)&v25[1].mMasterRate.value + 1) )
  {
    v26 = *((_DWORD *)&v25[1].mMasterRate.value + 1);
    v19 = v26 == -244037932;
    if ( UFG::OneShotHandle::IsValid(&this->m_oneShot) )
    {
      v27 = this->m_oneShot.m_pOneShot;
LABEL_51:
      UFG::AudioEntity::SetWwiseSwitch(v27, v26, HIDWORD(this->m_Track[2].mResourceOwner));
      goto LABEL_52;
    }
    if ( m_pComponent )
    {
      v27 = (UFG::OneShot *)&m_pComponent->UFG::AudioEntity;
      goto LABEL_51;
    }
  }
LABEL_52:
  v28 = this->m_Track;
  if ( HIDWORD(v28[1].mMasterRate.expression.mOffset) )
  {
    v29 = HIDWORD(v28[1].mMasterRate.expression.mOffset);
    vfptr_high = HIDWORD(v28[2].vfptr);
    Instance = UFG::TiDo::GetInstance();
    UFG::AudioEntity::SetWwiseState(Instance, v29, vfptr_high);
  }
  if ( mOffset )
  {
    v32 = UFG::qRandom(100.0, (unsigned int *)&UFG::qDefaultSeed);
    p_m_oneShot = &this->m_oneShot;
    if ( v32 >= v18 )
    {
      UFG::OneShotHandle::IsValid(p_m_oneShot);
    }
    else
    {
      if ( UFG::OneShotHandle::IsValid(p_m_oneShot) )
        _((AMD_HD3D *)this->mContext->mSimObject.m_pPointer);
      if ( UFG::OneShotHandle::IsValid(&this->m_oneShot) && !v19 )
        UFG::TidoGame::SetMaterial2((unsigned __int64)this->m_oneShot.m_pOneShot, 0);
      v34 = _S9_5;
      if ( (_S9_5 & 1) == 0 )
      {
        _S9_5 |= 1u;
        UFG::qWiseSymbol::create_from_string(&play_door_close, "play_door_close");
        atexit(AudioTask::Begin_::_55_::_dynamic_atexit_destructor_for__play_door_close__);
        v34 = _S9_5;
      }
      if ( (v34 & 2) == 0 )
      {
        _S9_5 = v34 | 2;
        UFG::qWiseSymbol::create_from_string(&play_door_open, "play_door_open");
        atexit(AudioTask::Begin_::_55_::_dynamic_atexit_destructor_for__play_door_open__);
        v34 = _S9_5;
      }
      if ( mOffset != play_door_open.mUID && mOffset != play_door_close.mUID )
      {
        if ( (v34 & 4) == 0 )
        {
          _S9_5 = v34 | 4;
          UFG::qWiseSymbol::create_from_string(&play_fighting_head_smash, "play_fighting_head_smash");
          atexit(AudioTask::Begin_::_58_::_dynamic_atexit_destructor_for__play_fighting_head_smash__);
        }
        if ( mOffset == play_fighting_head_smash.mUID )
        {
          v35 = this->mContext->mSimObject.m_pPointer;
          if ( v35 )
            v7 = v35->m_pTransformNodeComponent;
          UFG::TransformNodeComponent::UpdateWorldTransform(v7);
          UFG::TidoGame::PlayFightHeadSmash(
            (UFG::TidoGame *)UFG::TiDo::m_pInstance,
            (UFG::qVector3 *)&v7->mWorldTransform.v3);
        }
        else if ( UFG::OneShotHandle::IsValid(&this->m_oneShot) )
        {
          UFG::OneShot::Play(this->m_oneShot.m_pOneShot, mOffset);
        }
        else if ( m_pComponent )
        {
          UFG::AudioEntity::CreateAndPlayEvent(&m_pComponent->UFG::AudioEntity, mOffset, 0i64, 0, 0i64);
        }
      }
    }
  }
}

// File Line: 215
// RVA: 0x303B20
bool __fastcall AudioTask::Update(AudioTask *this, float timeDelta)
{
  bool result; // al
  ActionContext *mContext; // rcx
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *v7; // rax
  bool v8; // zf

  if ( UFG::OneShotHandle::IsValid(&this->m_oneShot) )
  {
    if ( this->m_oneShot.m_pOneShot->m_controller.m_pEvent )
    {
      return 1;
    }
    else
    {
      UFG::OneShotHandle::Release(&this->m_oneShot);
      return 0;
    }
  }
  else
  {
    mContext = this->mContext;
    if ( !mContext )
      return 0;
    m_pPointer = (UFG::SimObjectCharacter *)mContext->mSimObject.m_pPointer;
    if ( !m_pPointer )
      return 0;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v7 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    else
      v7 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID));
    if ( !v7 )
      return 0;
    v8 = !UFG::AudioEntity::IsPlayingId(&v7->UFG::AudioEntity, this->m_Track[1].mMasterRate.text.mOffset);
    result = 1;
    if ( v8 )
      return 0;
  }
  return result;
}

// File Line: 261
// RVA: 0x2FDFF0
void __fastcall AudioTask::End(AudioTask *this)
{
  ITrack *m_Track; // rax
  UFG::OneShotHandle *p_m_oneShot; // rcx
  unsigned int value_low; // esi
  ActionContext *mContext; // rcx
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax

  m_Track = this->m_Track;
  p_m_oneShot = &this->m_oneShot;
  value_low = LODWORD(m_Track[1].mMasterRate.value);
  if ( value_low )
  {
    if ( UFG::OneShotHandle::IsValid(p_m_oneShot) )
    {
      UFG::OneShot::Stop(this->m_oneShot.m_pOneShot, 0x1388u, value_low);
      UFG::OneShotHandle::Release(&this->m_oneShot);
    }
    else
    {
      mContext = this->mContext;
      if ( mContext )
      {
        m_pPointer = (UFG::SimObjectCharacter *)mContext->mSimObject.m_pPointer;
        if ( m_pPointer )
        {
          m_Flags = m_pPointer->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
          }
          else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::ActorAudioComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::ActorAudioComponent::_TypeUID);
          }
          if ( ComponentOfTypeHK )
            UFG::AudioEntity::CreateAndPlayEvent(&ComponentOfTypeHK->UFG::AudioEntity, value_low, 0i64, 0, 0i64);
        }
      }
    }
  }
  else if ( UFG::OneShotHandle::IsValid(p_m_oneShot) )
  {
    UFG::OneShot::Stop(this->m_oneShot.m_pOneShot, 0x1388u, 0);
    UFG::OneShotHandle::Release(&this->m_oneShot);
  }
}

// File Line: 326
// RVA: 0x2E9770
void __fastcall AudioTaskSimple::Begin(AudioTaskSimple *this, ActionContext *context)
{
  bool v3; // bl
  bool v4; // al
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfType; // rax

  this->mContext = context;
  v3 = UFG::TiDo::m_pInstance->vfptr->HighSpeedMode(UFG::TiDo::m_pInstance);
  v4 = UFG::TidoGame::MajorGunBattleMode();
  if ( !v3 && !v4 || LOBYTE(this->m_Track[1].mResourceOwner) )
  {
    m_pPointer = (UFG::SimObjectCharacter *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer
      && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
         ? (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::ActorAudioComponent::_TypeUID))
         : (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::ActorAudioComponent::_TypeUID)))
        : (ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer)),
          ComponentOfType && UFG::ActorAudioComponent::IsAlive(ComponentOfType, 0)) )
    {
      AudioTaskSimple::PlayOnActor(this);
      this->m_playOnActor = 1;
    }
    else
    {
      AudioTaskSimple::PlayOnOneShot(this);
      this->m_playOnActor = 0;
    }
  }
}

// File Line: 379
// RVA: 0x302AF0
void __fastcall AudioTaskSimple::PlayOnOneShot(AudioTaskSimple *this)
{
  UFG::SimObject *m_pPointer; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::OneShotHandle *p_m_oneShot; // rbx
  UFG::qMatrix44 *p_mWorldTransform; // rdx
  unsigned int vfptr_high; // esi

  m_pPointer = this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer && (m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent) != 0i64 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    p_m_oneShot = &this->m_oneShot;
    p_mWorldTransform = &m_pTransformNodeComponent->mWorldTransform;
  }
  else
  {
    p_m_oneShot = &this->m_oneShot;
    p_mWorldTransform = &UFG::qMatrix44::msIdentity;
  }
  UFG::OneShotPool::GetOneShotHandle(p_m_oneShot, p_mWorldTransform);
  if ( UFG::OneShotHandle::IsValid(p_m_oneShot) )
  {
    if ( UFG::AudioEntity::Distance2ToListener(p_m_oneShot->m_pOneShot, 0) < (float)(UFG::TidoGame::sm_TagCutoffDist
                                                                                   * UFG::TidoGame::sm_TagCutoffDist) )
    {
      vfptr_high = HIDWORD(this->m_Track[1].vfptr);
      if ( vfptr_high )
      {
        _((AMD_HD3D *)this->mContext->mSimObject.m_pPointer);
        UFG::TidoGame::SetMaterial2((unsigned __int64)p_m_oneShot->m_pOneShot, 0);
        UFG::OneShot::Play(p_m_oneShot->m_pOneShot, vfptr_high);
      }
    }
    else
    {
      UFG::OneShotHandle::StopAndRelease(p_m_oneShot);
    }
  }
}

// File Line: 450
// RVA: 0x303C30
bool __fastcall AudioTaskSimple::Update(AudioTaskSimple *this, float timeDelta)
{
  UFG::OneShotHandle *p_m_oneShot; // rdi
  UFG::SimObject *v4; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::OneShotHandle v6; // rcx
  UFG::qVector4 v7; // xmm3
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  bool result; // al
  ActionContext *mContext; // rcx
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *v14; // rax
  UFG::AudioEntity *m_SFXEntity; // rcx
  bool v16; // zf

  if ( this->m_playOnActor || (p_m_oneShot = &this->m_oneShot, !UFG::OneShotHandle::IsValid(&this->m_oneShot)) )
  {
    if ( !this->m_playOnActor )
      return 0;
    mContext = this->mContext;
    if ( !mContext )
      return 0;
    m_pPointer = (UFG::SimObjectCharacter *)mContext->mSimObject.m_pPointer;
    if ( !m_pPointer )
      return 0;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v14 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    else
      v14 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                           m_pPointer,
                                           UFG::ActorAudioComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(
                                           m_pPointer,
                                           UFG::ActorAudioComponent::_TypeUID));
    m_SFXEntity = v14->m_SFXEntity;
    if ( !m_SFXEntity )
      return 0;
    v16 = !UFG::AudioEntity::IsPlayingId(m_SFXEntity, HIDWORD(this->m_Track[1].vfptr));
    result = 1;
    if ( v16 )
      return 0;
  }
  else if ( p_m_oneShot->m_pOneShot->m_controller.m_pEvent )
  {
    v4 = this->mContext->mSimObject.m_pPointer;
    if ( v4 )
    {
      m_pTransformNodeComponent = v4->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v4->m_pTransformNodeComponent);
        v6.m_pOneShot = p_m_oneShot->m_pOneShot;
        v7 = m_pTransformNodeComponent->mWorldTransform.v1;
        v8 = m_pTransformNodeComponent->mWorldTransform.v2;
        v9 = m_pTransformNodeComponent->mWorldTransform.v3;
        v6.m_pOneShot->m_WorldMatrix.v0 = m_pTransformNodeComponent->mWorldTransform.v0;
        v6.m_pOneShot->m_WorldMatrix.v1 = v7;
        v6.m_pOneShot->m_WorldMatrix.v2 = v8;
        v6.m_pOneShot->m_WorldMatrix.v3 = v9;
        UFG::AudioEntity::ForcePositionUpdate(v6.m_pOneShot);
      }
    }
    return 1;
  }
  else
  {
    UFG::OneShotHandle::Release(p_m_oneShot);
    return 0;
  }
  return result;
}

// File Line: 501
// RVA: 0x2DDE50
void __fastcall AudioTaskSoundbankIO::AudioTaskSoundbankIO(AudioTaskSoundbankIO *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AudioTrackSoundbankIO>::`vftable;
  this->vfptr = (ITaskVtbl *)&AudioTaskSoundbankIO::`vftable;
}

// File Line: 511
// RVA: 0x2E9870
void __fastcall AudioTaskSoundbankIO::Begin(AudioTaskSoundbankIO *this, ActionContext *context)
{
  unsigned int mOffset; // edx
  UFG::qWiseSymbol *v3; // rax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h] BYREF

  mOffset = this->m_Track[1].mMasterRate.text.mOffset;
  if ( mOffset )
  {
    v3 = UFG::qSymbol::qSymbol(&result, mOffset);
    UFG::TiDo::LoadWwiseBank(v3);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 524
// RVA: 0x2FE120
void __fastcall AudioTaskSoundbankIO::End(AudioTaskSoundbankIO *this)
{
  unsigned int mOffset; // edx
  UFG::qWiseSymbol *v2; // rax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h] BYREF

  mOffset = this->m_Track[1].mMasterRate.text.mOffset;
  if ( mOffset )
  {
    v2 = UFG::qSymbol::qSymbol(&result, mOffset);
    UFG::TiDo::UnloadWwiseBank(v2);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 539
// RVA: 0x2DDE00
void __fastcall AudioTaskMusicState::AudioTaskMusicState(AudioTaskMusicState *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AudioTrackMusicState>::`vftable;
  this->vfptr = (ITaskVtbl *)&AudioTaskMusicState::`vftable;
}

// File Line: 549
// RVA: 0x2E95A0
void __fastcall AudioTaskMusicState::Begin(AudioTaskMusicState *this, ActionContext *context)
{
  ITrack *v3; // rcx
  const char *v4; // rdx
  UFG::qString *v5; // rax
  bool v6; // bl
  _QWORD *p_mResourceOwner; // rcx
  const char *v8; // rcx
  unsigned int v9; // ebx
  _QWORD *v10; // rdx
  const char *v11; // rcx
  unsigned int v12; // eax
  UFG::qString *v13; // rax
  bool v14; // bl
  ITrack *m_Track; // rdx
  const char *v16; // rsi
  const char *v17; // rcx
  unsigned int v18; // ebx
  unsigned int v19; // eax
  ITrack *v20; // rcx
  const char *v21; // r8
  const char *v22; // r9
  UFG::qString v23; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-38h] BYREF

  v3 = this->m_Track + 1;
  v4 = (char *)v3 + ((unsigned __int64)v3->vfptr & 0xFFFFFFFFFFFFFFFEui64);
  if ( ((unsigned __int64)v3->vfptr & 0xFFFFFFFFFFFFFFFEui64) == 0 )
    v4 = BinString::sEmptyString;
  UFG::qString::qString(&v23, v4);
  v5 = UFG::qString::ToLower(&v23, &result);
  v6 = UFG::qString::operator==(v5, "music_event");
  UFG::qString::~qString(&result);
  if ( v6 )
  {
    p_mResourceOwner = &this->m_Track[1].mResourceOwner;
    if ( (*p_mResourceOwner & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      v8 = (char *)p_mResourceOwner + (*p_mResourceOwner & 0xFFFFFFFFFFFFFFFEui64);
    else
      v8 = BinString::sEmptyString;
    v9 = UFG::TiDo::CalcWwiseUid(v8);
    if ( v9 != AudioTaskMusicState::m_lastPlayEvent )
    {
      v10 = &this->m_Track[1].mResourceOwner;
      if ( (*v10 & 0xFFFFFFFFFFFFFFFEui64) != 0 )
        v11 = (char *)v10 + (*v10 & 0xFFFFFFFFFFFFFFFEui64);
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
      m_Track = this->m_Track;
      v16 = BinString::sEmptyString;
      if ( ((unsigned __int64)m_Track[1].mResourceOwner & 0xFFFFFFFFFFFFFFFEui64) != 0 )
        v17 = (char *)&m_Track[1].mResourceOwner
            + ((unsigned __int64)m_Track[1].mResourceOwner & 0xFFFFFFFFFFFFFFFEui64);
      else
        v17 = BinString::sEmptyString;
      if ( ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64) != 0 )
        v16 = (char *)&m_Track[1] + ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64);
      v18 = UFG::TiDo::CalcWwiseUid(v17);
      v19 = UFG::TiDo::CalcWwiseUid(v16);
      UFG::Music::SetMusicState(v19, v18);
    }
  }
  v20 = this->m_Track;
  v21 = BinString::sEmptyString;
  if ( ((unsigned __int64)v20[1].mResourceOwner & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    v22 = (char *)&v20[1].mResourceOwner + ((unsigned __int64)v20[1].mResourceOwner & 0xFFFFFFFFFFFFFFFEui64);
  else
    v22 = BinString::sEmptyString;
  if ( ((unsigned __int64)v20[1].vfptr & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    v21 = (char *)&v20[1] + ((unsigned __int64)v20[1].vfptr & 0xFFFFFFFFFFFFFFFEui64);
  UFG::qPrintf("%s, AudioTaskMusicState - (%s %s)\n", UFG::TidoGame::sm_timeStampStr.mData, v21, v22);
  UFG::qString::~qString(&v23);
}

