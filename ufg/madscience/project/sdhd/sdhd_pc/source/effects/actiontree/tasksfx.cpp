// File Line: 66
// RVA: 0x14E8EB0
__int64 dynamic_initializer_for__symWORLD_SPACE__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("WORLD_SPACE", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symWORLD_SPACE, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symWORLD_SPACE__);
}

// File Line: 67
// RVA: 0x14E8E70
__int64 dynamic_initializer_for__symLOCAL_SPACE__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("LOCAL_SPACE", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symLOCAL_SPACE, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symLOCAL_SPACE__);
}

// File Line: 73
// RVA: 0x3FD9D0
void __fastcall FX::HardwareOcclusionQuery::HardwareOcclusionQuery(FX::HardwareOcclusionQuery *this)
{
  *(_QWORD *)&this->mQueryID = -1i64;
  this->mTarget = 0i64;
}

// File Line: 89
// RVA: 0x403460
void __fastcall PlayEffectBaseTask::playEffectBegin(
        PlayEffectBaseTask *this,
        ActionContext *pContext,
        PlayEffectBaseTrack *pTrack,
        const float fTimeBegin,
        float fTimeEnd,
        UFG::SimObject *pSimObject)
{
  float y; // xmm1_4
  int mWorldEffectMode; // esi
  unsigned int mUID; // r15d
  float z; // xmm0_4
  unsigned int v10; // eax
  float w; // xmm1_4
  float x; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  __int16 m_Flags; // cx
  UFG::CharacterAnimationComponent *v27; // rax
  Creature *mCreature; // rcx
  int BoneID; // eax
  bool v30; // r14
  __int16 v31; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  Render::FXSimComponent *v33; // rsi
  __int16 v34; // cx
  UFG::CharacterAnimationComponent *v35; // rax
  Creature *v36; // rcx
  int mBoneId; // edx
  unsigned int started; // eax
  UFG::qMatrix44 *v39; // rax
  UFG::qMatrix44 *p_offset_40; // r8
  UFG::qVector4 v41; // xmm2
  UFG::qVector4 v42; // xmm1
  UFG::qVector4 v43; // xmm0
  UFG::qMatrix44 *v44; // rax
  UFG::qVector4 v45; // xmm2
  UFG::qVector4 v46; // xmm1
  UFG::qVector4 v47; // xmm0
  int v48; // esi
  int v49; // esi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm0_4
  UFG::TransformNodeComponent *v54; // rbx
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm0_4
  UFG::WorldEffectsManager *v58; // rbx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::qVector3 endPos; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qVector3 startPos; // [rsp+40h] [rbp-A8h] BYREF
  _DWORD offset[6]; // [rsp+50h] [rbp-98h] BYREF
  float offset_24; // [rsp+68h] [rbp-80h]
  float offset_28; // [rsp+6Ch] [rbp-7Ch]
  float offset_32; // [rsp+70h] [rbp-78h]
  float offset_36; // [rsp+74h] [rbp-74h]
  UFG::qMatrix44 offset_40; // [rsp+78h] [rbp-70h] BYREF
  UFG::qMatrix44 result; // [rsp+B8h] [rbp-30h] BYREF
  float v69; // [rsp+158h] [rbp+70h]
  UFG::SimObjectCVBase *v70; // [rsp+160h] [rbp+78h]

  y = pTrack->mTransform.v0.y;
  mWorldEffectMode = pTrack->mWorldEffectMode;
  mUID = pTrack->mEffectName.mUID;
  offset[0] = LODWORD(pTrack->mTransform.v0.x);
  z = pTrack->mTransform.v0.z;
  *(float *)&offset[1] = y;
  v10 = pTrack->mAttachLimbName.mUID;
  w = pTrack->mTransform.v0.w;
  *(float *)&offset[2] = z;
  x = pTrack->mTransform.v1.x;
  *(float *)&offset[3] = w;
  v15 = pTrack->mTransform.v1.y;
  *(float *)&offset[4] = x;
  v16 = pTrack->mTransform.v1.z;
  *(float *)&offset[5] = v15;
  v17 = pTrack->mTransform.v1.w;
  offset_24 = v16;
  v18 = pTrack->mTransform.v2.x;
  offset_28 = v17;
  v19 = pTrack->mTransform.v2.y;
  offset_32 = v18;
  v20 = pTrack->mTransform.v2.z;
  offset_36 = v19;
  v21 = pTrack->mTransform.v2.w;
  offset_40.v0.x = v20;
  v22 = pTrack->mTransform.v3.x;
  offset_40.v0.y = v21;
  v23 = pTrack->mTransform.v3.y;
  offset_24 = v22;
  v24 = pTrack->mTransform.v3.z;
  offset_28 = v23;
  v25 = pTrack->mTransform.v3.w;
  offset_32 = v24;
  offset_36 = v25;
  if ( v10 == symWORLD_SPACE.mUID )
  {
    this->mBoneId = -3;
  }
  else if ( v10 == symLOCAL_SPACE.mUID )
  {
    this->mBoneId = -4;
  }
  else if ( v70 )
  {
    m_Flags = v70->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      v27 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v70);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      v27 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v70);
    }
    else
    {
      v27 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v70,
                                                   UFG::CharacterAnimationComponent::_TypeUID)
                                               : UFG::SimObject::GetComponentOfType(
                                                   v70,
                                                   UFG::CharacterAnimationComponent::_TypeUID));
    }
    if ( v27 )
    {
      mCreature = v27->mCreature;
      if ( mCreature )
      {
        if ( mCreature->mPose.mRigHandle.mData )
          BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, pTrack->mAttachLimbName.mUID);
        else
          BoneID = -1;
        this->mBoneId = BoneID;
      }
    }
  }
  if ( this->mBoneId == -1 )
    this->mBoneId = 0;
  if ( this->mBoneId == -3 )
  {
    if ( !mWorldEffectMode )
    {
      p_offset_40 = (UFG::qMatrix44 *)offset;
      goto LABEL_62;
    }
    goto LABEL_51;
  }
  if ( mWorldEffectMode )
  {
LABEL_51:
    v48 = mWorldEffectMode - 1;
    if ( !v48 )
    {
      v58 = UFG::WorldEffectsManager::sInstance;
      LocalPlayer = UFG::GetLocalPlayer();
      started = UFG::WorldEffectsManager::StartWorldEffect(
                  v58,
                  mUID,
                  LocalPlayer,
                  (UFG::qMatrix44 *)offset,
                  v69 - fTimeBegin);
      goto LABEL_63;
    }
    v49 = v48 - 1;
    if ( v49 )
    {
      if ( v49 == 1 )
      {
        if ( v70 )
        {
          m_pTransformNodeComponent = v70->m_pTransformNodeComponent;
          if ( m_pTransformNodeComponent )
          {
            v51 = UFG::WorldEffectsManager::sInstance->mPlayerPos.y;
            startPos.x = UFG::WorldEffectsManager::sInstance->mPlayerPos.x;
            v52 = UFG::WorldEffectsManager::sInstance->mPlayerPos.z;
            startPos.y = v51;
            startPos.z = v52;
            UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
            v53 = m_pTransformNodeComponent->mWorldTransform.v3.x;
            endPos.y = m_pTransformNodeComponent->mWorldTransform.v3.y;
            endPos.x = v53;
            endPos.z = m_pTransformNodeComponent->mWorldTransform.v3.z;
            started = UFG::WorldEffectsManager::StartWorldEffect(
                        UFG::WorldEffectsManager::sInstance,
                        mUID,
                        &startPos,
                        &endPos,
                        (UFG::qMatrix44 *)offset,
                        v69 - fTimeBegin);
            goto LABEL_63;
          }
        }
      }
    }
    else if ( v70 )
    {
      v54 = v70->m_pTransformNodeComponent;
      if ( v54 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v54);
        v55 = v54->mWorldTransform.v3.x;
        endPos.y = v54->mWorldTransform.v3.y;
        v56 = UFG::WorldEffectsManager::sInstance->mPlayerPos.y;
        endPos.x = v55;
        v57 = v54->mWorldTransform.v3.z;
        startPos.y = v56;
        endPos.z = v57;
        startPos.x = UFG::WorldEffectsManager::sInstance->mPlayerPos.x;
        startPos.z = UFG::WorldEffectsManager::sInstance->mPlayerPos.z;
        started = UFG::WorldEffectsManager::StartWorldEffect(
                    UFG::WorldEffectsManager::sInstance,
                    mUID,
                    &endPos,
                    &startPos,
                    (UFG::qMatrix44 *)offset,
                    v69 - fTimeBegin);
        goto LABEL_63;
      }
    }
    return;
  }
  v30 = pTrack->mAttachEffect != 0;
  if ( v70 )
  {
    v31 = v70->m_Flags;
    if ( (v31 & 0x4000) != 0 || v31 < 0 || (v31 & 0x2000) != 0 || (v31 & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v70, Render::FXSimComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v70, Render::FXSimComponent::_TypeUID);
    v33 = (Render::FXSimComponent *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      v34 = v70->m_Flags;
      if ( (v34 & 0x4000) != 0 || v34 < 0 )
      {
        v35 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v70);
      }
      else if ( (v34 & 0x2000) != 0 )
      {
        v35 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v70);
      }
      else
      {
        v35 = (UFG::CharacterAnimationComponent *)((v34 & 0x1000) != 0
                                                 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v70,
                                                     UFG::CharacterAnimationComponent::_TypeUID)
                                                 : UFG::SimObject::GetComponentOfType(
                                                     v70,
                                                     UFG::CharacterAnimationComponent::_TypeUID));
      }
      if ( v35 )
      {
        v36 = v35->mCreature;
        if ( v36 )
        {
          mBoneId = this->mBoneId;
          if ( mBoneId == -4 )
          {
            if ( v30 )
            {
              started = Render::FXSimComponent::AttachEffect(v33, mUID, 0, (UFG::qMatrix44 *)offset);
LABEL_63:
              this->mFXHandle = started;
              return;
            }
            Creature::GetTransform(v36, &offset_40);
            v39 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)offset, &result, &offset_40);
            p_offset_40 = &offset_40;
            v41 = v39->v2;
            v42 = v39->v3;
            v43 = v39->v0;
            offset_40.v1 = v39->v1;
            offset_40.v2 = v41;
            offset_40.v0 = v43;
            offset_40.v3 = v42;
          }
          else
          {
            if ( v30 )
            {
              started = Render::FXSimComponent::AttachEffect(v33, mUID, mBoneId, (UFG::qMatrix44 *)offset);
              goto LABEL_63;
            }
            Creature::GetTransform(v36, mBoneId, &offset_40);
            v44 = UFG::qMatrix44::operator*(&offset_40, &result, (UFG::qMatrix44 *)offset);
            p_offset_40 = &offset_40;
            v45 = v44->v2;
            v46 = v44->v3;
            v47 = v44->v0;
            offset_40.v1 = v44->v1;
            offset_40.v2 = v45;
            offset_40.v0 = v47;
            offset_40.v3 = v46;
          }
LABEL_62:
          started = Render::FXManager::CreateEffect(&Render::gFXManager, mUID, p_offset_40, 0xFFFFFFFF);
          goto LABEL_63;
        }
      }
    }
  }
}

// File Line: 264
// RVA: 0x403A10
void __fastcall PlayEffectBaseTask::playEffectEnd(
        PlayEffectBaseTask *this,
        ActionContext *pContext,
        PlayEffectBaseTrack *pTrack,
        const float fTimeBegin,
        float fTimeEnd,
        UFG::SimObjectGame *pSimObject)
{
  unsigned int mFXHandle; // edx
  int mWorldEffectMode; // eax
  bool v9; // di
  signed __int16 m_Flags; // dx
  Render::FXSimComponent *ComponentOfType; // rax

  if ( pTrack->mPlayToEnd )
    return;
  mFXHandle = this->mFXHandle;
  if ( this->mFXHandle == -1 )
    return;
  mWorldEffectMode = pTrack->mWorldEffectMode;
  v9 = pTrack->mKillFxBuffer != 0;
  if ( !pTrack->mAttachEffect || this->mBoneId == -3 )
  {
    if ( !mWorldEffectMode )
      goto LABEL_17;
LABEL_23:
    if ( (unsigned int)(mWorldEffectMode - 1) <= 2 )
      UFG::WorldEffectsManager::EndWorldEffect(UFG::WorldEffectsManager::sInstance, mFXHandle);
    goto LABEL_18;
  }
  if ( mWorldEffectMode )
    goto LABEL_23;
  if ( !pSimObject
    || ((m_Flags = pSimObject->m_Flags, (m_Flags & 0x4000) == 0)
     && m_Flags >= 0
     && (m_Flags & 0x2000) == 0
     && (m_Flags & 0x1000) == 0
      ? (ComponentOfType = (Render::FXSimComponent *)UFG::SimObject::GetComponentOfType(
                                                       pSimObject,
                                                       Render::FXSimComponent::_TypeUID))
      : (ComponentOfType = (Render::FXSimComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       pSimObject,
                                                       Render::FXSimComponent::_TypeUID)),
        !ComponentOfType) )
  {
    mFXHandle = this->mFXHandle;
LABEL_17:
    Render::FXManager::KillEffect(&Render::gFXManager, mFXHandle, FXKILLOPTION_DEFAULT);
    goto LABEL_18;
  }
  Render::FXSimComponent::DetachEffect(ComponentOfType, this->mFXHandle, FXKILLOPTION_DEFAULT);
LABEL_18:
  if ( v9 )
    Render::ParticleEmitterManager::KillBuffersWithParent(&Render::gParticleEmitterManager, this->mFXHandle);
  this->mFXHandle = -1;
}

// File Line: 326
// RVA: 0x3FDB40
void __fastcall PlayEffectTask::PlayEffectTask(PlayEffectTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<PlayEffectTrack>::`vftable;
  *(_QWORD *)&this->mFXHandle = -1i64;
  this->mContext = 0i64;
  this->vfptr = (ITaskVtbl *)&PlayEffectTask::`vftable;
}

// File Line: 336
// RVA: 0x3FFB70
void __fastcall PlayEffectTask::Begin(PlayEffectTask *this, ActionContext *context)
{
  ITrack *m_Track; // rax
  PlayEffectBaseTrack *v3; // r8

  m_Track = this->m_Track;
  this->mContext = context;
  if ( m_Track )
    v3 = (PlayEffectBaseTrack *)&m_Track[1];
  else
    v3 = 0i64;
  PlayEffectBaseTask::playEffectBegin(
    &this->PlayEffectBaseTask,
    context,
    v3,
    m_Track->mTimeBegin,
    m_Track->mTimeEnd,
    context->mSimObject.m_pPointer);
}

// File Line: 354
// RVA: 0x4005A0
void __fastcall PlayEffectTask::End(PlayEffectTask *this)
{
  ITrack *m_Track; // rax
  PlayEffectBaseTrack *v2; // r8

  m_Track = this->m_Track;
  if ( m_Track )
    v2 = (PlayEffectBaseTrack *)&m_Track[1];
  else
    v2 = 0i64;
  PlayEffectBaseTask::playEffectEnd(
    &this->PlayEffectBaseTask,
    this->mContext,
    v2,
    m_Track->mTimeBegin,
    m_Track->mTimeEnd,
    this->mContext->mSimObject.m_pPointer);
}

// File Line: 386
// RVA: 0x3FF840
void __fastcall FootStepLeftEffectTask::Begin(FootStepLeftEffectTask *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int64 v4; // rsi
  UFG::ActorAudioComponent *v6; // rbx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  unsigned int v9; // esi
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::CharacterEffectsComponent *m_pComponent; // rax

  if ( context )
  {
    m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
    v4 = 0i64;
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
      v6 = ComponentOfTypeHK;
    }
    else
    {
      v6 = 0i64;
    }
    if ( (int)audioEnum.m_enumLists.size > 0 )
      v4 = *((_QWORD *)audioEnum.m_enumLists.p + 4);
    v9 = *(_DWORD *)(*(_QWORD *)(v4 + 48) + 4i64 * LODWORD(this->m_Track[1].vfptr));
    if ( v6
      && !UFG::TidoGame::sm_disableFootSteps
      && UFG::AudioEntity::Distance2ToListener(&v6->UFG::AudioEntity, 0) < (float)(UFG::TidoGame::sm_FootstepCutoffDist
                                                                                 * UFG::TidoGame::sm_FootstepCutoffDist) )
    {
      UFG::ActorAudioComponent::PlayFootstepLeft(v6, v9);
    }
    if ( !HIDWORD(this->m_Track[1].vfptr) )
    {
      v10 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 & 0x4000) != 0 )
        {
          m_pComponent = (UFG::CharacterEffectsComponent *)v10->m_Components.p[38].m_pComponent;
        }
        else if ( v11 < 0 || (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
        {
          m_pComponent = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v10,
                                                             UFG::CharacterEffectsComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::CharacterEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                             v10,
                                                             UFG::CharacterEffectsComponent::_TypeUID);
        }
        if ( m_pComponent )
          UFG::CharacterEffectsComponent::HandleFootstep(m_pComponent, Foot_Left);
      }
    }
  }
}

// File Line: 411
// RVA: 0x3FF9D0
void __fastcall FootStepRightEffectTask::Begin(FootStepRightEffectTask *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int64 v4; // rsi
  UFG::ActorAudioComponent *v6; // rbx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  unsigned int v9; // esi
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::CharacterEffectsComponent *m_pComponent; // rax

  if ( context )
  {
    m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
    v4 = 0i64;
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
      v6 = ComponentOfTypeHK;
    }
    else
    {
      v6 = 0i64;
    }
    if ( (int)audioEnum.m_enumLists.size > 0 )
      v4 = *((_QWORD *)audioEnum.m_enumLists.p + 4);
    v9 = *(_DWORD *)(*(_QWORD *)(v4 + 48) + 4i64 * LODWORD(this->m_Track[1].vfptr));
    if ( v6
      && !UFG::TidoGame::sm_disableFootSteps
      && UFG::AudioEntity::Distance2ToListener(&v6->UFG::AudioEntity, 0) < (float)(UFG::TidoGame::sm_FootstepCutoffDist
                                                                                 * UFG::TidoGame::sm_FootstepCutoffDist) )
    {
      UFG::ActorAudioComponent::PlayFootstepRight(v6, v9);
    }
    if ( !HIDWORD(this->m_Track[1].vfptr) )
    {
      v10 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 & 0x4000) != 0 )
        {
          m_pComponent = (UFG::CharacterEffectsComponent *)v10->m_Components.p[38].m_pComponent;
        }
        else if ( v11 < 0 || (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
        {
          m_pComponent = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v10,
                                                             UFG::CharacterEffectsComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::CharacterEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                             v10,
                                                             UFG::CharacterEffectsComponent::_TypeUID);
        }
        if ( m_pComponent )
          UFG::CharacterEffectsComponent::HandleFootstep(m_pComponent, Foot_Right);
      }
    }
  }
}

// File Line: 435
// RVA: 0x3FECF0
bool __fastcall CollisionEffectTask::AppliesToPlayer(
        CollisionEffectTask *this,
        ActionContext *pContext,
        UFG::HitRecord *pHitRecord)
{
  UFG::SimObjectCharacter *m_pPointer; // rbx
  bool result; // al

  m_pPointer = (UFG::SimObjectCharacter *)pContext->mSimObject.m_pPointer;
  if ( UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)pHitRecord->mAttacker.m_pPointer) )
    return 1;
  result = UFG::IsAnyLocalPlayer(m_pPointer);
  if ( result )
    return 1;
  return result;
}

// File Line: 448
// RVA: 0x14E7990
__int64 dynamic_initializer_for__AudioAttackMaterialProperty___0()
{
  AudioAttackMaterialProperty_1.mUID = UFG::qWiseSymbolUIDFromString("AudioAttackMaterialProperty", 0x811C9DC5);
  _((AMD_HD3D *)AudioAttackMaterialProperty_1.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__AudioAttackMaterialProperty___0);
}

// File Line: 451
// RVA: 0x3FF290
void __fastcall CollisionEffectTask::Begin(CollisionEffectTask *this, ActionContext *pContext)
{
  ITrack *m_Track; // rax
  bool v5; // si
  bool v6; // r15
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *v10; // rax
  unsigned int AttackMaterialUIDForAttacker; // r12d
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v12; // rcx
  const char *TypeName; // rax
  unsigned int TargetMaterialUID; // ebx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v15; // rcx
  const char *v16; // rax
  UFG::qReflectObject *mData; // rax
  unsigned int mUID; // ebx
  unsigned int v19; // r14d
  UFG::SimObjectCharacter *v20; // rcx
  __int16 v21; // dx
  UFG::ActorAudioComponent *v22; // rax
  UFG::ActorAudioComponent *v23; // rsi
  unsigned int v24; // esi
  UFG::SimObjectGame *v25; // rcx
  Render::FXSimComponent *fxComponent; // rbx
  __int16 v27; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v29; // rcx
  __int16 v30; // dx
  float *iBoneID; // [rsp+30h] [rbp-98h]
  UFG::qReflectHandleBase v32; // [rsp+48h] [rbp-80h] BYREF
  UFG::qReflectHandleBase v33; // [rsp+70h] [rbp-58h] BYREF

  m_Track = this->m_Track;
  v5 = BYTE4(m_Track[1].vfptr) != 0;
  v6 = BYTE5(m_Track[1].vfptr) != 0;
  if ( WORD2(m_Track[1].vfptr) )
  {
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        v10 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
        m_pComponent = v10;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      if ( m_pComponent )
      {
        AttackMaterialUIDForAttacker = findAttackMaterialUIDForAttacker(
                                         pContext,
                                         *(UFG::SimObject **)&m_pComponent[3].m_TypeUID,
                                         HIDWORD(m_pComponent[3].m_BoundComponentHandles.mNode.mPrev));
        if ( AttackMaterialUIDForAttacker )
        {
          if ( !BYTE3(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) )
          {
            BYTE3(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) = 1;
            UFG::qReflectHandleBase::qReflectHandleBase(&v33);
            TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v12);
            v33.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
            UFG::PhysicsPropertyManager::GetObjectProperties(
              (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v33,
              AttackMaterialUIDForAttacker,
              1);
            if ( v33.mData )
            {
              TargetMaterialUID = CollisionEffectTrack::GetTargetMaterialUID((CollisionEffectTrack *)this->m_Track);
              UFG::qReflectHandleBase::qReflectHandleBase(&v32);
              v16 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v15);
              v32.mTypeUID = UFG::qStringHash64(v16, 0xFFFFFFFFFFFFFFFFui64);
              UFG::PhysicsPropertyManager::GetObjectProperties(
                (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v32,
                TargetMaterialUID,
                1);
              mData = v32.mData;
              if ( v32.mData )
              {
                if ( v5 )
                {
                  mUID = UFG::PhysicsObjectProperties::GetAudioProperty(
                           (UFG::PhysicsObjectProperties *)v33.mData,
                           &AudioAttackMaterialProperty_1)->mUID;
                  _((AMD_HD3D *)mUID);
                  if ( mUID )
                  {
                    v19 = *(_DWORD *)(v32.mData[4].mBaseNode.mUID + 104);
                    if ( v19 != -1 )
                    {
                      v20 = (UFG::SimObjectCharacter *)pContext->mSimObject.m_pPointer;
                      if ( v20 )
                      {
                        v21 = v20->m_Flags;
                        if ( (v21 & 0x4000) != 0 )
                          v22 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v20);
                        else
                          v22 = (UFG::ActorAudioComponent *)(v21 < 0 || (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0
                                                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v20,
                                                               UFG::ActorAudioComponent::_TypeUID)
                                                           : UFG::SimObject::GetComponentOfType(
                                                               v20,
                                                               UFG::ActorAudioComponent::_TypeUID));
                        v23 = v22;
                        if ( v22 )
                        {
                          UFG::ActorAudioComponent::PlayFightImpact(
                            v22,
                            mUID,
                            v19,
                            (unsigned int)m_pComponent[3].m_BoundComponentHandles.mNode.mNext);
                          if ( CollisionEffectTask::AppliesToPlayer(
                                 this,
                                 pContext,
                                 (UFG::HitRecord *)&m_pComponent[2].m_BoundComponentHandles.mNode.mNext) )
                          {
                            UFG::ActorAudioComponent::PlayFightRumble(
                              v23,
                              mUID,
                              v19,
                              (unsigned int)m_pComponent[3].m_BoundComponentHandles.mNode.mNext);
                          }
                        }
                      }
                    }
                  }
                  _((AMD_HD3D *)mUID);
                  mData = v32.mData;
                }
                if ( v6 )
                {
                  v24 = *(_DWORD *)(mData[4].mBaseNode.mUID + 108);
                  if ( v24 != -1 )
                  {
                    v25 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
                    if ( v25 )
                    {
                      v27 = v25->m_Flags;
                      if ( (v27 & 0x4000) != 0 || v27 < 0 || (v27 & 0x2000) != 0 || (v27 & 0x1000) != 0 )
                        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v25,
                                              Render::FXSimComponent::_TypeUID);
                      else
                        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v25, Render::FXSimComponent::_TypeUID);
                      fxComponent = (Render::FXSimComponent *)ComponentOfTypeHK;
                    }
                    else
                    {
                      fxComponent = 0i64;
                    }
                    v29 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
                    if ( v29 )
                    {
                      v30 = v29->m_Flags;
                      if ( (v30 & 0x4000) == 0 && v30 >= 0 && (v30 & 0x2000) == 0 )
                      {
                        if ( (v30 & 0x1000) != 0 )
                          UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::BaseAnimationComponent::_TypeUID);
                        else
                          UFG::SimObject::GetComponentOfType(v29, UFG::BaseAnimationComponent::_TypeUID);
                      }
                    }
                    if ( fxComponent )
                    {
                      LODWORD(iBoneID) = m_pComponent[6].m_BoundComponentHandles.mNode.mPrev;
                      Render::ImpactManager::HandleHitRecordImpactEvent(
                        &Render::gImpactManager,
                        AttackMaterialUIDForAttacker,
                        v24,
                        (UFG::qVector3 *)((char *)&m_pComponent[4].m_SafePointerList.mNode.mPrev + 4),
                        (UFG::qVector3 *)&m_pComponent[4].m_TypeUID,
                        fxComponent,
                        iBoneID,
                        (UFG::qVector3 *)((char *)&m_pComponent[6].m_BoundComponentHandles.mNode.mPrev + 4));
                    }
                  }
                }
              }
              UFG::qReflectHandleBase::~qReflectHandleBase(&v32);
            }
            UFG::qReflectHandleBase::~qReflectHandleBase(&v33);
          }
        }
      }
    }
  }
}

// File Line: 559
// RVA: 0x3FF6A0
void __fastcall EffectSurfaceCollisionTask::Begin(EffectSurfaceCollisionTask *this, ActionContext *pContext)
{
  ITrack *m_Track; // r8
  bool v5; // bl
  __int64 v6; // rax
  unsigned int v7; // r14d
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v8; // rcx
  const char *TypeName; // rax
  unsigned int BestEffectPropertyValue; // eax
  UFG::qVector3 vOutGroundNormal; // [rsp+58h] [rbp-60h] BYREF
  UFG::qVector3 vOutEffectPosition; // [rsp+68h] [rbp-50h] BYREF
  UFG::qReflectHandleBase v13; // [rsp+78h] [rbp-40h] BYREF
  unsigned __int64 uSurfaceMaterialHandleUID; // [rsp+C0h] [rbp+8h] BYREF
  unsigned __int64 uObjectMaterialHandleUID; // [rsp+D0h] [rbp+18h] BYREF

  m_Track = this->m_Track;
  v5 = BYTE5(m_Track[1].mResourceOwner) != 0;
  if ( WORD2(m_Track[1].mResourceOwner) )
  {
    v6 = (int)gAttackCollisionEnum.m_enumLists.size <= 0 ? 0i64 : *((_QWORD *)gAttackCollisionEnum.m_enumLists.p + 7);
    v7 = UFG::qStringHashUpper32(*(const char **)(*(_QWORD *)(v6 + 16) + 8i64 * LODWORD(m_Track[1].vfptr)), -1);
    if ( v7 )
    {
      if ( EffectSurfaceCollisionTask::projectBoneOntoGround(
             this,
             pContext->mSimObject.m_pPointer,
             &vOutEffectPosition,
             &vOutGroundNormal,
             &uObjectMaterialHandleUID,
             &uSurfaceMaterialHandleUID)
        && (uSurfaceMaterialHandleUID || uObjectMaterialHandleUID) )
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v13);
        TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v8);
        v13.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
        UFG::PhysicsPropertyManager::GetObjectProperties(
          (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v13,
          v7,
          1);
        if ( v13.mData && v5 )
        {
          BestEffectPropertyValue = EffectSurfaceCollisionTask::GetBestEffectPropertyValue(
                                      this,
                                      pContext,
                                      uObjectMaterialHandleUID,
                                      uSurfaceMaterialHandleUID);
          if ( BestEffectPropertyValue != -1 )
            Render::ImpactManager::HandleImpactEvent(
              &Render::gImpactManager,
              v7,
              BestEffectPropertyValue,
              &vOutEffectPosition,
              &vOutGroundNormal,
              &vOutGroundNormal,
              0i64,
              0,
              0i64);
        }
        UFG::qReflectHandleBase::~qReflectHandleBase(&v13);
      }
    }
  }
}

// File Line: 613
// RVA: 0x400940
__int64 __fastcall EffectSurfaceCollisionTask::GetBestEffectPropertyValue(
        EffectSurfaceCollisionTask *this,
        ActionContext *pContext,
        unsigned __int64 uObjectMaterialHandleUID,
        unsigned __int64 uSurfaceMaterialHandleUID)
{
  unsigned int v6; // ebx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v9; // rcx
  const char *v10; // rax
  UFG::qReflectHandleBase v12; // [rsp+28h] [rbp-30h] BYREF

  v6 = -1;
  if ( !uSurfaceMaterialHandleUID )
    goto LABEL_5;
  UFG::qReflectHandleBase::qReflectHandleBase(&v12);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v7);
  v12.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v12, v12.mTypeUID, uSurfaceMaterialHandleUID);
  if ( v12.mData )
    v6 = HIDWORD(v12.mData[1].mBaseNode.mChildren[0]);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v12);
  if ( v6 == -1 )
  {
LABEL_5:
    if ( uObjectMaterialHandleUID )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v12);
      v10 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v9);
      v12.mTypeUID = UFG::qStringHash64(v10, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v12, v12.mTypeUID, uObjectMaterialHandleUID);
      if ( v12.mData )
        v6 = *(_DWORD *)(v12.mData[4].mBaseNode.mUID + 108);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v12);
    }
  }
  return v6;
}

// File Line: 654
// RVA: 0x403B40
char __fastcall EffectSurfaceCollisionTask::projectBoneOntoGround(
        EffectSurfaceCollisionTask *this,
        UFG::SimObjectGame *pSimObj,
        UFG::qVector3 *vOutEffectPosition,
        UFG::qVector3 *vOutGroundNormal,
        unsigned __int64 *iOutObjectTypeHandleUID,
        unsigned __int64 *iOutSurfaceTypeHandleUID)
{
  UFG::SimComponent *m_pComponent; // rax
  signed __int16 m_Flags; // cx
  Creature *v11; // rbx
  UFG::qSymbolUC *BoneUID; // rax
  int v13; // eax
  ITrack *m_Track; // rax
  float v15; // xmm0_4
  float y; // xmm1_4
  unsigned __int64 *v17; // rcx
  unsigned __int64 mPhysicsObjectPropertyHandleUid; // rax
  float z; // xmm0_4
  float x; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-E0h] BYREF
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-D0h] BYREF
  UFG::RayCastData data; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qMatrix44 transform; // [rsp+120h] [rbp+20h] BYREF
  UFG::qSymbolUC result; // [rsp+198h] [rbp+98h] BYREF

  if ( pSimObj )
  {
    m_Flags = pSimObj->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pSimObj->m_Components.p[9].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = pSimObj->m_Components.p[8].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObj, UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pSimObj, UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = pSimObj->m_Components.p[9].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v11 = *(Creature **)&m_pComponent[2].m_TypeUID;
  if ( !v11 )
    return 0;
  BoneUID = EffectSurfaceCollisionTrack::GetBoneUID((EffectSurfaceCollisionTrack *)this->m_Track, &result);
  v13 = v11->mPose.mRigHandle.mData ? Skeleton::GetBoneID(v11->mPose.mRigHandle.mUFGSkeleton, BoneUID->mUID) : -1;
  Creature::GetTransform(v11, v13, &transform);
  m_Track = this->m_Track;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_extraInfo = -1;
  data.mOutput.m_shapeKeyIndex = 0;
  data.mOutput.m_shapeKeys[0] = -1;
  data.mOutput.m_rootCollidable = 0i64;
  LODWORD(data.mOutput.m_hitFraction) = (_DWORD)FLOAT_1_0;
  data.mDebugName = 0i64;
  data.mCollisionModelName.mUID = -1;
  rayStart.x = transform.v3.x + (float)(UFG::qVector3::msDirUp.x * kfRayOffset);
  rayStart.y = transform.v3.y + (float)(UFG::qVector3::msDirUp.y * kfRayOffset);
  rayStart.z = transform.v3.z + (float)(UFG::qVector3::msDirUp.z * kfRayOffset);
  v15 = *(float *)&m_Track[1].mResourceOwner;
  rayEnd.z = transform.v3.z - (float)(v15 * UFG::qVector3::msDirUp.z);
  rayEnd.x = transform.v3.x - (float)(v15 * UFG::qVector3::msDirUp.x);
  rayEnd.y = transform.v3.y - (float)(v15 * UFG::qVector3::msDirUp.y);
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0xCu);
  if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
    return 0;
  y = data.point.y;
  v17 = iOutObjectTypeHandleUID;
  mPhysicsObjectPropertyHandleUid = data.mPhysicsObjectPropertyHandleUid;
  vOutEffectPosition->x = data.point.x;
  z = data.point.z;
  vOutEffectPosition->y = y;
  x = data.normal.x;
  vOutEffectPosition->z = z;
  v21 = data.normal.y;
  vOutGroundNormal->x = x;
  v22 = data.normal.z;
  vOutGroundNormal->y = v21;
  vOutGroundNormal->z = v22;
  *v17 = mPhysicsObjectPropertyHandleUid;
  *iOutSurfaceTypeHandleUID = data.mPhysicsSurfacePropertyHandleUid;
  return 1;
}

// File Line: 706
// RVA: 0x3FFC40
void __fastcall RumbleTask::Begin(RumbleTask *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
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
    {
      if ( (*((_BYTE *)ComponentOfTypeHK + 553) & 8) != 0 )
      {
        AudioTaskSimple::PlayOnActor((AudioTaskSimple *)this);
        this->m_playOnActor = 1;
      }
    }
  }
}

// File Line: 780
// RVA: 0x400D30
void __fastcall AudioTaskSimple::PlayOnActor(AudioTaskSimple *this)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  UFG::ActorAudioComponent *v3; // rbx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  unsigned int vfptr_high; // esi

  m_pPointer = (UFG::SimObjectCharacter *)this->mContext->mSimObject.m_pPointer;
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
    v3 = ComponentOfTypeHK;
  }
  else
  {
    v3 = 0i64;
  }
  if ( (float)(UFG::TidoGame::sm_TagCutoffDist * UFG::TidoGame::sm_TagCutoffDist) > UFG::AudioEntity::Distance2ToListener(
                                                                                      &v3->UFG::AudioEntity,
                                                                                      0)
    && v3->m_SFXEntity )
  {
    vfptr_high = HIDWORD(this->m_Track[1].vfptr);
    if ( vfptr_high )
    {
      _((AMD_HD3D *)this->mContext->mSimObject.m_pPointer);
      UFG::TidoGame::SetMaterial2((unsigned __int64)v3->m_SFXEntity, 0);
      UFG::AudioEntity::CreateAndPlayEvent(v3->m_SFXEntity, vfptr_high, 0i64, 0, 0i64);
    }
  }
}

// File Line: 807
// RVA: 0x402170
char __fastcall RumbleTask::Update(RumbleTask *this, float timeDelta)
{
  char v2; // bp
  UFG::SimObject *m_pPointer; // rbx
  UFG::OneShot *m_pOneShot; // rcx
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  UFG::SimObjectCharacter *v9; // rcx
  UFG::ActorAudioComponent *v10; // rbx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *v12; // rax
  UFG::AudioEntity *m_SFXEntity; // rcx
  bool v14; // zf
  char result; // al

  v2 = 0;
  if ( !this->m_playOnActor && UFG::OneShotHandle::IsValid(&this->m_oneShot) )
  {
    if ( this->m_oneShot.m_pOneShot->m_controller.m_pEvent )
    {
      m_pPointer = this->mContext->mSimObject.m_pPointer;
      if ( m_pPointer )
        m_pPointer = (UFG::SimObject *)m_pPointer->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
      m_pOneShot = this->m_oneShot.m_pOneShot;
      v6 = *(UFG::qVector4 *)&m_pPointer[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
      v7 = *(UFG::qVector4 *)&m_pPointer[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
      v8 = *(UFG::qVector4 *)m_pPointer[1].mNode.mChild;
      m_pOneShot->m_WorldMatrix.v0 = *(UFG::qVector4 *)&m_pPointer[1].vfptr;
      m_pOneShot->m_WorldMatrix.v1 = v6;
      m_pOneShot->m_WorldMatrix.v2 = v7;
      m_pOneShot->m_WorldMatrix.v3 = v8;
      UFG::AudioEntity::ForcePositionUpdate(m_pOneShot);
      return 1;
    }
    else
    {
      UFG::OneShotHandle::Release(&this->m_oneShot);
    }
    return v2;
  }
  if ( !this->m_playOnActor )
    return v2;
  v9 = (UFG::SimObjectCharacter *)this->mContext->mSimObject.m_pPointer;
  if ( v9 )
  {
    m_Flags = v9->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v12 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v9);
    else
      v12 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v9,
                                           UFG::ActorAudioComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(v9, UFG::ActorAudioComponent::_TypeUID));
    v10 = v12;
  }
  else
  {
    v10 = 0i64;
  }
  m_SFXEntity = v10->m_SFXEntity;
  if ( !m_SFXEntity )
    return v2;
  v14 = !UFG::AudioEntity::IsPlayingId(m_SFXEntity, HIDWORD(this->m_Track[1].vfptr));
  result = 1;
  if ( v14 )
    return v2;
  return result;
}

// File Line: 857
// RVA: 0x3FDE00
void __fastcall VisualTreatmentTask::VisualTreatmentTask(VisualTreatmentTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<VisualTreatmentTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&VisualTreatmentTask::`vftable;
  this->mContext = 0i64;
  this->mVisualTreatmentId = -1;
}

// File Line: 861
// RVA: 0x3FFDF0
void __fastcall VisualTreatmentTask::Begin(VisualTreatmentTask *this, ActionContext *context)
{
  ITrack *m_Track; // rax
  ITrack *v4; // rax
  __int64 vfptr_low; // rdi
  unsigned int started; // eax

  m_Track = this->m_Track;
  this->mContext = context;
  if ( !BYTE5(m_Track[1].mResourceOwner) || UFG::GetLocalPlayer() == this->mContext->mSimObject.m_pPointer )
  {
    v4 = this->m_Track;
    vfptr_low = LODWORD(v4[1].vfptr);
    started = UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(
                (int)v4[1].vfptr,
                BYTE6(v4[1].mResourceOwner) != 0,
                HIDWORD(v4[1].vfptr));
    this->mVisualTreatmentId = started;
    if ( started != -1 )
    {
      UFG::RenderWorld::AccumulationBufferPostEffect_SetEnable(*(float *)&this->m_Track[1].mResourceOwner > 0.1);
      if ( (gVisualTreatmentEnum.m_enumLists.size & 0x80000000) != 0 )
        UFG::TidoGame::PlayVisualEffectAudio(0);
      else
        UFG::TidoGame::PlayVisualEffectAudio((*gVisualTreatmentEnum.m_enumLists.p)->m_enumNameHash.p[vfptr_low]);
    }
  }
}

// File Line: 883
// RVA: 0x400670
void __fastcall VisualTreatmentTask::End(VisualTreatmentTask *this)
{
  UFG::OnlineManager::Instance();
  if ( this->mVisualTreatmentId != -1 )
  {
    UFG::RenderWorld::AccumulationBufferPostEffect_SetEnable(0);
    UFG::RenderWorld::VisualTreatmentPostEffect_StopVisualTreatment(
      this->mVisualTreatmentId,
      *(float *)&this->m_Track[1].m_TrackClassNameUID);
    if ( (gVisualTreatmentEnum.m_enumLists.size & 0x80000000) != 0 )
      UFG::TidoGame::StopVisualEffectAudio(0);
    else
      UFG::TidoGame::StopVisualEffectAudio((*gVisualTreatmentEnum.m_enumLists.p)->m_enumNameHash.p[LODWORD(this->m_Track[1].vfptr)]);
  }
}

// File Line: 903
// RVA: 0x3FF690
void __fastcall DamageEffectTask::Begin(DamageEffectTask *this, ActionContext *pContext)
{
  UFG::RenderWorld::DamagePostEffect_OnDamage(*(float *)&this->m_Track[1].vfptr);
}

// File Line: 914
// RVA: 0x3FFBC0
void __fastcall RimLightTargetTask::Begin(RimLightTargetTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int v4; // edx
  bool v5; // zf

  this->m_pContext = pContext;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        v4 = UFG::TargetingSystemBaseComponent::_TypeUID;
LABEL_6:
        UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v4);
        return;
      }
      v5 = (m_Flags & 0x1000) == 0;
      v4 = UFG::TargetingSystemBaseComponent::_TypeUID;
      if ( !v5 )
        goto LABEL_6;
      UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
  }
}

// File Line: 929
// RVA: 0x4005F0
void __fastcall RimLightTargetTask::End(RimLightTargetTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int v3; // edx
  bool v4; // zf

  m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        v3 = UFG::TargetingSystemBaseComponent::_TypeUID;
LABEL_6:
        UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v3);
        return;
      }
      v4 = (m_Flags & 0x1000) == 0;
      v3 = UFG::TargetingSystemBaseComponent::_TypeUID;
      if ( !v4 )
        goto LABEL_6;
      UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
  }
}

// File Line: 944
// RVA: 0x3FFC20
void __fastcall RimLightTask::Begin(RimLightTask *this, ActionContext *pContext)
{
  this->m_pContext = pContext;
  UFG::RadarSystem::AddRimLight(
    UFG::RadarSystem::sInstance,
    (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)pContext->mSimObject.m_pPointer);
}

// File Line: 951
// RVA: 0x400650
void __fastcall RimLightTask::End(RimLightTask *this)
{
  UFG::RadarSystem::RemoveRimLight(UFG::RadarSystem::sInstance, this->m_pContext->mSimObject.m_pPointer);
}

// File Line: 959
// RVA: 0x3FF1D0
void __fastcall ApplyWetnessOrSweatTask::Begin(ApplyWetnessOrSweatTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v6; // rcx
  ITrack *m_Track; // rax
  float v8; // xmm2_4
  float v9; // xmm0_4

  this->m_pContext = pContext;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CharacterLookComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterLookComponent::_TypeUID);
    v6 = ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      m_Track = this->m_Track;
      v8 = *(float *)&m_Track[1].vfptr;
      v9 = *((float *)&m_Track[1].vfptr + 1);
      if ( v8 > -1.0 )
        *(float *)&v6[2].m_BoundComponentHandles.mNode.mNext = v8;
      if ( v9 > -1.0 )
        *((float *)&v6[2].m_BoundComponentHandles.mNode.mNext + 1) = v9;
    }
  }
}

// File Line: 978
// RVA: 0x401B70
bool __fastcall ApplyWetnessOrSweatTask::Update(ApplyWetnessOrSweatTask *this, float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v6; // rcx
  ITrack *m_Track; // rax
  float v8; // xmm2_4
  float v9; // xmm0_4
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 1;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CharacterLookComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterLookComponent::_TypeUID);
  v6 = ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 1;
  m_Track = this->m_Track;
  v8 = *(float *)&m_Track[1].vfptr;
  v9 = *((float *)&m_Track[1].vfptr + 1);
  if ( v8 > -1.0 )
    *(float *)&v6[2].m_BoundComponentHandles.mNode.mNext = v8;
  result = 1;
  if ( v9 > -1.0 )
    *((float *)&v6[2].m_BoundComponentHandles.mNode.mNext + 1) = v9;
  return result;
}

// File Line: 997
// RVA: 0x4004F0
void __fastcall ApplyWetnessOrSweatTask::End(ApplyWetnessOrSweatTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CharacterLookComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterLookComponent::_TypeUID);
    if ( ComponentOfTypeHK )
    {
      if ( *(float *)&this->m_Track[1].vfptr > -1.0 )
        LODWORD(ComponentOfTypeHK[2].m_BoundComponentHandles.mNode.mNext) = -1082130432;
    }
  }
}

// File Line: 1027
// RVA: 0x3FFCE0
void __fastcall SetHighlightingModeTask::Begin(SetHighlightingModeTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v7; // rbx
  int vfptr_low; // edi
  int mPrev; // eax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CompositeLookComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CompositeLookComponent::_TypeUID);
    v7 = ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      vfptr_low = LOBYTE(this->m_Track[1].vfptr);
      mPrev = (int)ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev;
      if ( mPrev != vfptr_low )
      {
        if ( mPrev == 4 )
        {
          UFG::RadarSystem::RemoveCombatProp(UFG::RadarSystem::sInstance, pContext->mSimObject.m_pPointer);
        }
        else if ( mPrev == 1 )
        {
          UFG::RadarSystem::RemoveRimLight(UFG::RadarSystem::sInstance, pContext->mSimObject.m_pPointer);
        }
        LODWORD(v7[1].m_BoundComponentHandles.mNode.mPrev) = vfptr_low;
        if ( vfptr_low == 4 )
        {
          UFG::RadarSystem::AddCombatProp(
            UFG::RadarSystem::sInstance,
            (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)pContext->mSimObject.m_pPointer);
        }
        else if ( vfptr_low == 1 )
        {
          UFG::RadarSystem::AddRimLight(
            UFG::RadarSystem::sInstance,
            (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)pContext->mSimObject.m_pPointer);
        }
      }
    }
  }
}

