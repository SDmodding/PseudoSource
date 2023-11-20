// File Line: 66
// RVA: 0x14E8EB0
__int64 dynamic_initializer_for__symWORLD_SPACE__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("WORLD_SPACE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symWORLD_SPACE, v0);
  return atexit(dynamic_atexit_destructor_for__symWORLD_SPACE__);
}

// File Line: 67
// RVA: 0x14E8E70
__int64 dynamic_initializer_for__symLOCAL_SPACE__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("LOCAL_SPACE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symLOCAL_SPACE, v0);
  return atexit(dynamic_atexit_destructor_for__symLOCAL_SPACE__);
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
void __fastcall PlayEffectBaseTask::playEffectBegin(PlayEffectBaseTask *this, ActionContext *pContext, PlayEffectBaseTrack *pTrack, const float fTimeBegin, const float fTimeEnd, UFG::SimObject *pSimObject)
{
  float v6; // xmm1_4
  int v7; // esi
  unsigned int v8; // er15
  float v9; // xmm0_4
  unsigned int v10; // eax
  PlayEffectBaseTrack *v11; // r14
  PlayEffectBaseTask *v12; // rdi
  float v13; // xmm1_4
  float v14; // xmm0_4
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
  unsigned __int16 v26; // cx
  UFG::CharacterAnimationComponent *v27; // rax
  Creature *v28; // rcx
  signed int v29; // eax
  bool v30; // r14
  unsigned __int16 v31; // cx
  UFG::SimComponent *v32; // rax
  Render::FXSimComponent *v33; // rsi
  unsigned __int16 v34; // cx
  UFG::CharacterAnimationComponent *v35; // rax
  Creature *v36; // rcx
  int v37; // edx
  unsigned int v38; // eax
  UFG::qMatrix44 *v39; // rax
  UFG::qMatrix44 *v40; // r8
  __int128 v41; // xmm2
  __int128 v42; // xmm1
  UFG::qVector4 v43; // xmm0
  UFG::qMatrix44 *v44; // rax
  __int128 v45; // xmm2
  __int128 v46; // xmm1
  UFG::qVector4 v47; // xmm0
  int v48; // esi
  int v49; // esi
  UFG::TransformNodeComponent *v50; // rbx
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm0_4
  UFG::TransformNodeComponent *v54; // rbx
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm0_4
  UFG::WorldEffectsManager *v58; // rbx
  UFG::SimObjectCharacter *v59; // rax
  UFG::qVector3 endPos; // [rsp+30h] [rbp-B8h]
  UFG::qVector3 startPos; // [rsp+40h] [rbp-A8h]
  UFG::qMatrix44 offset; // [rsp+50h] [rbp-98h]
  __int128 v63; // [rsp+98h] [rbp-50h]
  __int128 v64; // [rsp+A8h] [rbp-40h]
  UFG::qMatrix44 result; // [rsp+B8h] [rbp-30h]
  float v66; // [rsp+158h] [rbp+70h]
  UFG::SimObjectCVBase *v67; // [rsp+160h] [rbp+78h]

  v6 = pTrack->mTransform.v0.y;
  v7 = pTrack->mWorldEffectMode;
  v8 = pTrack->mEffectName.mUID;
  offset.v0.x = pTrack->mTransform.v0.x;
  v9 = pTrack->mTransform.v0.z;
  offset.v0.y = v6;
  v10 = pTrack->mAttachLimbName.mUID;
  v11 = pTrack;
  v12 = this;
  v13 = pTrack->mTransform.v0.w;
  offset.v0.z = v9;
  v14 = pTrack->mTransform.v1.x;
  offset.v0.w = v13;
  v15 = pTrack->mTransform.v1.y;
  offset.v1.x = v14;
  v16 = pTrack->mTransform.v1.z;
  offset.v1.y = v15;
  v17 = pTrack->mTransform.v1.w;
  offset.v1.z = v16;
  v18 = pTrack->mTransform.v2.x;
  offset.v1.w = v17;
  v19 = pTrack->mTransform.v2.y;
  offset.v2.x = v18;
  v20 = pTrack->mTransform.v2.z;
  offset.v2.y = v19;
  v21 = pTrack->mTransform.v2.w;
  offset.v2.z = v20;
  v22 = pTrack->mTransform.v3.x;
  offset.v2.w = v21;
  v23 = pTrack->mTransform.v3.y;
  offset.v1.z = v22;
  v24 = pTrack->mTransform.v3.z;
  offset.v1.w = v23;
  v25 = pTrack->mTransform.v3.w;
  offset.v2.x = v24;
  offset.v2.y = v25;
  if ( v10 == symWORLD_SPACE.mUID )
  {
    this->mBoneId = -3;
  }
  else if ( v10 == symLOCAL_SPACE.mUID )
  {
    this->mBoneId = -4;
  }
  else if ( v67 )
  {
    v26 = v67->m_Flags;
    if ( (v26 >> 14) & 1 )
    {
      v27 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v67);
    }
    else if ( (v26 & 0x8000u) == 0 )
    {
      if ( (v26 >> 13) & 1 )
        v27 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v67);
      else
        v27 = (UFG::CharacterAnimationComponent *)((v26 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v67->vfptr,
                                                                       UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v67->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
    }
    else
    {
      v27 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v67);
    }
    if ( v27 )
    {
      v28 = v27->mCreature;
      if ( v28 )
      {
        if ( v28->mPose.mRigHandle.mData )
          v29 = Skeleton::GetBoneID(v28->mPose.mRigHandle.mUFGSkeleton, v11->mAttachLimbName.mUID);
        else
          v29 = -1;
        v12->mBoneId = v29;
      }
    }
  }
  if ( v12->mBoneId == -1 )
    v12->mBoneId = 0;
  if ( v12->mBoneId == -3 )
  {
    if ( !v7 )
    {
      v40 = &offset;
      goto LABEL_66;
    }
    goto LABEL_55;
  }
  if ( v7 )
  {
LABEL_55:
    v48 = v7 - 1;
    if ( !v48 )
    {
      v58 = UFG::WorldEffectsManager::sInstance;
      v59 = UFG::GetLocalPlayer();
      v38 = UFG::WorldEffectsManager::StartWorldEffect(
              v58,
              v8,
              (UFG::SimObject *)&v59->vfptr,
              &offset,
              v66 - fTimeBegin);
      goto LABEL_67;
    }
    v49 = v48 - 1;
    if ( v49 )
    {
      if ( v49 == 1 )
      {
        if ( v67 )
        {
          v50 = v67->m_pTransformNodeComponent;
          if ( v50 )
          {
            v51 = UFG::WorldEffectsManager::sInstance->mPlayerPos.y;
            startPos.x = UFG::WorldEffectsManager::sInstance->mPlayerPos.x;
            v52 = UFG::WorldEffectsManager::sInstance->mPlayerPos.z;
            startPos.y = v51;
            startPos.z = v52;
            UFG::TransformNodeComponent::UpdateWorldTransform(v50);
            v53 = v50->mWorldTransform.v3.x;
            endPos.y = v50->mWorldTransform.v3.y;
            endPos.x = v53;
            endPos.z = v50->mWorldTransform.v3.z;
            v38 = UFG::WorldEffectsManager::StartWorldEffect(
                    UFG::WorldEffectsManager::sInstance,
                    v8,
                    &startPos,
                    &endPos,
                    &offset,
                    v66 - fTimeBegin);
            goto LABEL_67;
          }
        }
      }
    }
    else if ( v67 )
    {
      v54 = v67->m_pTransformNodeComponent;
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
        v38 = UFG::WorldEffectsManager::StartWorldEffect(
                UFG::WorldEffectsManager::sInstance,
                v8,
                &endPos,
                &startPos,
                &offset,
                v66 - fTimeBegin);
        goto LABEL_67;
      }
    }
    return;
  }
  v30 = v11->mAttachEffect != 0;
  if ( v67 )
  {
    v31 = v67->m_Flags;
    if ( (v31 >> 14) & 1 )
    {
      v32 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v67->vfptr,
              Render::FXSimComponent::_TypeUID);
    }
    else if ( (v31 & 0x8000u) == 0 )
    {
      if ( (v31 >> 13) & 1 )
        v32 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v67->vfptr,
                Render::FXSimComponent::_TypeUID);
      else
        v32 = (v31 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                  (UFG::SimObjectGame *)&v67->vfptr,
                                  Render::FXSimComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                        (UFG::SimObject *)&v67->vfptr,
                                                                        Render::FXSimComponent::_TypeUID);
    }
    else
    {
      v32 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v67->vfptr,
              Render::FXSimComponent::_TypeUID);
    }
    v33 = (Render::FXSimComponent *)v32;
    if ( v32 )
    {
      v34 = v67->m_Flags;
      if ( (v34 >> 14) & 1 )
      {
        v35 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v67);
      }
      else if ( (v34 & 0x8000u) == 0 )
      {
        if ( (v34 >> 13) & 1 )
          v35 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v67);
        else
          v35 = (UFG::CharacterAnimationComponent *)((v34 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v67->vfptr,
                                                                         UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v67->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
      }
      else
      {
        v35 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v67);
      }
      if ( v35 )
      {
        v36 = v35->mCreature;
        if ( v36 )
        {
          v37 = v12->mBoneId;
          if ( v37 == -4 )
          {
            if ( v30 )
            {
              v38 = Render::FXSimComponent::AttachEffect(v33, v8, 0, &offset);
LABEL_67:
              v12->mFXHandle = v38;
              return;
            }
            Creature::GetTransform(v36, (UFG::qMatrix44 *)((char *)&offset + 40));
            v39 = UFG::qMatrix44::operator*(&offset, &result, (UFG::qMatrix44 *)((char *)&offset + 40));
            v40 = (UFG::qMatrix44 *)((char *)&offset + 40);
            v41 = (__int128)v39->v2;
            v42 = (__int128)v39->v3;
            v43 = v39->v0;
            *(UFG::qVector4 *)&offset.v3.z = v39->v1;
            v63 = v41;
            *(UFG::qVector4 *)((char *)&offset.v2 + 8) = v43;
            v64 = v42;
          }
          else
          {
            if ( v30 )
            {
              v38 = Render::FXSimComponent::AttachEffect(v33, v8, v37, &offset);
              goto LABEL_67;
            }
            Creature::GetTransform(v36, v37, (UFG::qMatrix44 *)((char *)&offset + 40));
            v44 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)((char *)&offset + 40), &result, &offset);
            v40 = (UFG::qMatrix44 *)((char *)&offset + 40);
            v45 = (__int128)v44->v2;
            v46 = (__int128)v44->v3;
            v47 = v44->v0;
            *(UFG::qVector4 *)&offset.v3.z = v44->v1;
            v63 = v45;
            *(UFG::qVector4 *)((char *)&offset.v2 + 8) = v47;
            v64 = v46;
          }
LABEL_66:
          v38 = Render::FXManager::CreateEffect(&Render::gFXManager, v8, v40, 0xFFFFFFFF);
          goto LABEL_67;
        }
      }
    }
  }
}

// File Line: 264
// RVA: 0x403A10
void __fastcall PlayEffectBaseTask::playEffectEnd(PlayEffectBaseTask *this, ActionContext *pContext, PlayEffectBaseTrack *pTrack, const float fTimeBegin, const float fTimeEnd, UFG::SimObject *pSimObject)
{
  PlayEffectBaseTask *v6; // rbx
  unsigned int v7; // edx
  int v8; // eax
  bool v9; // di
  unsigned __int16 v10; // dx
  Render::FXSimComponent *v11; // rax

  v6 = this;
  if ( pTrack->mPlayToEnd )
    return;
  v7 = this->mFXHandle;
  if ( this->mFXHandle == -1 )
    return;
  v8 = pTrack->mWorldEffectMode;
  v9 = pTrack->mKillFxBuffer != 0;
  if ( !pTrack->mAttachEffect || this->mBoneId == -3 )
  {
    if ( !v8 )
      goto LABEL_19;
LABEL_25:
    if ( (unsigned int)(v8 - 1) <= 2 )
      UFG::WorldEffectsManager::EndWorldEffect(UFG::WorldEffectsManager::sInstance, v7);
    goto LABEL_20;
  }
  if ( v8 )
    goto LABEL_25;
  if ( !pSimObject
    || ((v10 = pSimObject->m_Flags, !((v10 >> 14) & 1)) ? ((v10 & 0x8000u) == 0 ? (!((v10 >> 13) & 1) ? (!((v10 >> 12) & 1) ? (v11 = (Render::FXSimComponent *)UFG::SimObject::GetComponentOfType(pSimObject, Render::FXSimComponent::_TypeUID)) : (v11 = (Render::FXSimComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObject, Render::FXSimComponent::_TypeUID))) : (v11 = (Render::FXSimComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObject, Render::FXSimComponent::_TypeUID))) : (v11 = (Render::FXSimComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObject, Render::FXSimComponent::_TypeUID))) : (v11 = (Render::FXSimComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObject, Render::FXSimComponent::_TypeUID)),
        !v11) )
  {
    v7 = v6->mFXHandle;
LABEL_19:
    Render::FXManager::KillEffect(&Render::gFXManager, v7, 0);
    goto LABEL_20;
  }
  Render::FXSimComponent::DetachEffect(v11, v6->mFXHandle, 0);
LABEL_20:
  if ( v9 )
    Render::ParticleEmitterManager::KillBuffersWithParent(&Render::gParticleEmitterManager, v6->mFXHandle);
  v6->mFXHandle = -1;
}

// File Line: 326
// RVA: 0x3FDB40
void __fastcall PlayEffectTask::PlayEffectTask(PlayEffectTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<PlayEffectTrack>::`vftable';
  *(_QWORD *)&this->mFXHandle = -1i64;
  this->mContext = 0i64;
  this->vfptr = (ITaskVtbl *)&PlayEffectTask::`vftable';
}

// File Line: 336
// RVA: 0x3FFB70
void __fastcall PlayEffectTask::Begin(PlayEffectTask *this, ActionContext *context)
{
  ITrack *v2; // rax
  PlayEffectBaseTrack *v3; // r8

  v2 = this->m_Track;
  this->mContext = context;
  if ( v2 )
    v3 = (PlayEffectBaseTrack *)&v2[1];
  else
    v3 = 0i64;
  PlayEffectBaseTask::playEffectBegin(
    (PlayEffectBaseTask *)&this->mFXHandle,
    context,
    v3,
    v2->mTimeBegin,
    v2->mTimeEnd,
    context->mSimObject.m_pPointer);
}

// File Line: 354
// RVA: 0x4005A0
void __fastcall PlayEffectTask::End(PlayEffectTask *this)
{
  ITrack *v1; // rax
  PlayEffectBaseTrack *v2; // r8

  v1 = this->m_Track;
  if ( v1 )
    v2 = (PlayEffectBaseTrack *)&v1[1];
  else
    v2 = 0i64;
  PlayEffectBaseTask::playEffectEnd(
    (PlayEffectBaseTask *)&this->mFXHandle,
    this->mContext,
    v2,
    v1->mTimeBegin,
    v1->mTimeEnd,
    this->mContext->mSimObject.m_pPointer);
}

// File Line: 386
// RVA: 0x3FF840
void __fastcall FootStepLeftEffectTask::Begin(FootStepLeftEffectTask *this, ActionContext *context)
{
  FootStepLeftEffectTask *v2; // rbp
  UFG::SimObjectCharacter *v3; // rcx
  __int64 v4; // rsi
  ActionContext *v5; // rdi
  UFG::ActorAudioComponent *v6; // rbx
  unsigned __int16 v7; // dx
  UFG::ActorAudioComponent *v8; // rax
  unsigned int v9; // esi
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::CharacterEffectsComponent *v12; // rax

  if ( context )
  {
    v2 = this;
    v3 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
    v4 = 0i64;
    v5 = context;
    if ( v3 )
    {
      v7 = v3->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v3);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
        else
        {
          v8 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v3->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
      }
      else
      {
        v8 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    if ( (signed int)audioEnum.m_enumLists.size > 0 )
      v4 = *((_QWORD *)audioEnum.m_enumLists.p + 4);
    v9 = *(_DWORD *)(*(_QWORD *)(v4 + 48) + 4i64 * LODWORD(v2->m_Track[1].vfptr));
    if ( v6
      && !UFG::TidoGame::sm_disableFootSteps
      && UFG::AudioEntity::Distance2ToListener((UFG::AudioEntity *)&v6->vfptr, 0) < (float)(UFG::TidoGame::sm_FootstepCutoffDist
                                                                                          * UFG::TidoGame::sm_FootstepCutoffDist) )
    {
      UFG::ActorAudioComponent::PlayFootstepLeft(v6, v9);
    }
    if ( !HIDWORD(v2->m_Track[1].vfptr) )
    {
      v10 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = (UFG::CharacterEffectsComponent *)v10->m_Components.p[38].m_pComponent;
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
          {
            v12 = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v10,
                                                      UFG::CharacterEffectsComponent::_TypeUID);
          }
          else if ( (v11 >> 12) & 1 )
          {
            v12 = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v10,
                                                      UFG::CharacterEffectsComponent::_TypeUID);
          }
          else
          {
            v12 = (UFG::CharacterEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v10->vfptr,
                                                      UFG::CharacterEffectsComponent::_TypeUID);
          }
        }
        else
        {
          v12 = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v10,
                                                    UFG::CharacterEffectsComponent::_TypeUID);
        }
        if ( v12 )
          UFG::CharacterEffectsComponent::HandleFootstep(v12, 0);
      }
    }
  }
}

// File Line: 411
// RVA: 0x3FF9D0
void __fastcall FootStepRightEffectTask::Begin(FootStepRightEffectTask *this, ActionContext *context)
{
  FootStepRightEffectTask *v2; // rbp
  UFG::SimObjectCharacter *v3; // rcx
  __int64 v4; // rsi
  ActionContext *v5; // rdi
  UFG::ActorAudioComponent *v6; // rbx
  unsigned __int16 v7; // dx
  UFG::ActorAudioComponent *v8; // rax
  unsigned int v9; // esi
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::CharacterEffectsComponent *v12; // rax

  if ( context )
  {
    v2 = this;
    v3 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
    v4 = 0i64;
    v5 = context;
    if ( v3 )
    {
      v7 = v3->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v3);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
        else
        {
          v8 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v3->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
      }
      else
      {
        v8 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    if ( (signed int)audioEnum.m_enumLists.size > 0 )
      v4 = *((_QWORD *)audioEnum.m_enumLists.p + 4);
    v9 = *(_DWORD *)(*(_QWORD *)(v4 + 48) + 4i64 * LODWORD(v2->m_Track[1].vfptr));
    if ( v6
      && !UFG::TidoGame::sm_disableFootSteps
      && UFG::AudioEntity::Distance2ToListener((UFG::AudioEntity *)&v6->vfptr, 0) < (float)(UFG::TidoGame::sm_FootstepCutoffDist
                                                                                          * UFG::TidoGame::sm_FootstepCutoffDist) )
    {
      UFG::ActorAudioComponent::PlayFootstepRight(v6, v9);
    }
    if ( !HIDWORD(v2->m_Track[1].vfptr) )
    {
      v10 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = (UFG::CharacterEffectsComponent *)v10->m_Components.p[38].m_pComponent;
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
          {
            v12 = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v10,
                                                      UFG::CharacterEffectsComponent::_TypeUID);
          }
          else if ( (v11 >> 12) & 1 )
          {
            v12 = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v10,
                                                      UFG::CharacterEffectsComponent::_TypeUID);
          }
          else
          {
            v12 = (UFG::CharacterEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v10->vfptr,
                                                      UFG::CharacterEffectsComponent::_TypeUID);
          }
        }
        else
        {
          v12 = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v10,
                                                    UFG::CharacterEffectsComponent::_TypeUID);
        }
        if ( v12 )
          UFG::CharacterEffectsComponent::HandleFootstep(v12, Foot_Right);
      }
    }
  }
}

// File Line: 435
// RVA: 0x3FECF0
bool __fastcall CollisionEffectTask::AppliesToPlayer(CollisionEffectTask *this, ActionContext *pContext, UFG::HitRecord *pHitRecord)
{
  UFG::SimObject *v3; // rbx
  bool result; // al

  v3 = pContext->mSimObject.m_pPointer;
  if ( UFG::IsAnyLocalPlayer(pHitRecord->mAttacker.m_pPointer) || (result = UFG::IsAnyLocalPlayer(v3)) != 0 )
    result = 1;
  return result;
}

// File Line: 448
// RVA: 0x14E7990
__int64 dynamic_initializer_for__AudioAttackMaterialProperty___0()
{
  AudioAttackMaterialProperty_1.mUID = UFG::qWiseSymbolUIDFromString("AudioAttackMaterialProperty", 0x811C9DC5);
  _((AMD_HD3D *)AudioAttackMaterialProperty_1.mUID);
  return atexit(dynamic_atexit_destructor_for__AudioAttackMaterialProperty___0);
}

// File Line: 451
// RVA: 0x3FF290
void __fastcall CollisionEffectTask::Begin(CollisionEffectTask *this, ActionContext *pContext)
{
  ActionContext *v2; // rbp
  CollisionEffectTask *v3; // r13
  ITrack *v4; // rax
  bool v5; // si
  bool v6; // r15
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rdi
  UFG::SimComponent *v10; // rax
  unsigned int v11; // er12
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v12; // rcx
  const char *v13; // rax
  unsigned int v14; // ebx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v15; // rcx
  const char *v16; // rax
  UFG::qReflectObject *v17; // rax
  unsigned int v18; // ebx
  unsigned int v19; // er14
  UFG::SimObjectCharacter *v20; // rcx
  unsigned __int16 v21; // dx
  UFG::ActorAudioComponent *v22; // rax
  UFG::ActorAudioComponent *v23; // rsi
  unsigned int v24; // esi
  UFG::SimObjectGame *v25; // rcx
  Render::FXSimComponent *fxComponent; // rbx
  unsigned __int16 v27; // dx
  UFG::SimComponent *v28; // rax
  UFG::SimObjectGame *v29; // rcx
  unsigned __int16 v30; // dx
  __int64 iBoneID; // [rsp+30h] [rbp-98h]
  UFG::qReflectHandleBase v32; // [rsp+48h] [rbp-80h]
  UFG::qReflectHandleBase v33; // [rsp+70h] [rbp-58h]

  v2 = pContext;
  v3 = this;
  v4 = this->m_Track;
  v5 = BYTE4(v4[1].vfptr) != 0;
  v6 = BYTE5(v4[1].vfptr) != 0;
  if ( BYTE4(v4[1].vfptr) || BYTE5(v4[1].vfptr) )
  {
    v7 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( v7 )
    {
      v8 = v7->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = v7->m_Components.p[15].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HitReactionComponent::_TypeUID);
        else
          v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::HitReactionComponent::_TypeUID);
        v9 = v10;
      }
      else
      {
        v9 = v7->m_Components.p[15].m_pComponent;
      }
      if ( v9 )
      {
        v11 = findAttackMaterialUIDForAttacker(
                v2,
                *(UFG::SimObject **)&v9[3].m_TypeUID,
                HIDWORD(v9[3].m_BoundComponentHandles.mNode.mPrev));
        if ( v11 )
        {
          if ( !BYTE3(v9[2].m_BoundComponentHandles.mNode.mNext) )
          {
            BYTE3(v9[2].m_BoundComponentHandles.mNode.mNext) = 1;
            UFG::qReflectHandleBase::qReflectHandleBase(&v33);
            v13 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v12);
            v33.mTypeUID = UFG::qStringHash64(v13, 0xFFFFFFFFFFFFFFFFui64);
            UFG::PhysicsPropertyManager::GetObjectProperties(
              (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v33,
              v11,
              1);
            if ( v33.mData )
            {
              v14 = CollisionEffectTrack::GetTargetMaterialUID((CollisionEffectTrack *)v3->m_Track);
              UFG::qReflectHandleBase::qReflectHandleBase(&v32);
              v16 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v15);
              v32.mTypeUID = UFG::qStringHash64(v16, 0xFFFFFFFFFFFFFFFFui64);
              UFG::PhysicsPropertyManager::GetObjectProperties(
                (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v32,
                v14,
                1);
              v17 = v32.mData;
              if ( v32.mData )
              {
                if ( v5 )
                {
                  v18 = UFG::PhysicsObjectProperties::GetAudioProperty(
                          (UFG::PhysicsObjectProperties *)v33.mData,
                          (UFG::qWiseSymbol *)&AudioAttackMaterialProperty_1.mUID)->mUID;
                  _((AMD_HD3D *)v18);
                  if ( v18 )
                  {
                    v19 = *(_DWORD *)(v32.mData[4].mBaseNode.mUID + 104);
                    if ( v19 != -1 )
                    {
                      v20 = (UFG::SimObjectCharacter *)v2->mSimObject.m_pPointer;
                      if ( v20 )
                      {
                        v21 = v20->m_Flags;
                        if ( (v21 >> 14) & 1 )
                        {
                          v22 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v20);
                        }
                        else if ( (v21 & 0x8000u) == 0 )
                        {
                          if ( (v21 >> 13) & 1 )
                            v22 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                (UFG::SimObjectGame *)&v20->vfptr,
                                                                UFG::ActorAudioComponent::_TypeUID);
                          else
                            v22 = (UFG::ActorAudioComponent *)((v21 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                   (UFG::SimObjectGame *)&v20->vfptr,
                                                                                   UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v20->vfptr, UFG::ActorAudioComponent::_TypeUID));
                        }
                        else
                        {
                          v22 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)&v20->vfptr,
                                                              UFG::ActorAudioComponent::_TypeUID);
                        }
                        v23 = v22;
                        if ( v22 )
                        {
                          UFG::ActorAudioComponent::PlayFightImpact(
                            v22,
                            v18,
                            v19,
                            (unsigned int)v9[3].m_BoundComponentHandles.mNode.mNext);
                          if ( CollisionEffectTask::AppliesToPlayer(
                                 v3,
                                 v2,
                                 (UFG::HitRecord *)&v9[2].m_BoundComponentHandles.mNode.mNext) )
                          {
                            UFG::ActorAudioComponent::PlayFightRumble(
                              v23,
                              v18,
                              v19,
                              (unsigned int)v9[3].m_BoundComponentHandles.mNode.mNext);
                          }
                        }
                      }
                    }
                  }
                  _((AMD_HD3D *)v18);
                  v17 = v32.mData;
                }
                if ( v6 )
                {
                  v24 = *(_DWORD *)(v17[4].mBaseNode.mUID + 108);
                  if ( v24 != -1 )
                  {
                    v25 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
                    if ( v25 )
                    {
                      v27 = v25->m_Flags;
                      if ( (v27 >> 14) & 1 )
                      {
                        v28 = UFG::SimObjectGame::GetComponentOfTypeHK(v25, Render::FXSimComponent::_TypeUID);
                      }
                      else if ( (v27 & 0x8000u) == 0 )
                      {
                        if ( (v27 >> 13) & 1 )
                        {
                          v28 = UFG::SimObjectGame::GetComponentOfTypeHK(v25, Render::FXSimComponent::_TypeUID);
                        }
                        else if ( (v27 >> 12) & 1 )
                        {
                          v28 = UFG::SimObjectGame::GetComponentOfTypeHK(v25, Render::FXSimComponent::_TypeUID);
                        }
                        else
                        {
                          v28 = UFG::SimObject::GetComponentOfType(
                                  (UFG::SimObject *)&v25->vfptr,
                                  Render::FXSimComponent::_TypeUID);
                        }
                      }
                      else
                      {
                        v28 = UFG::SimObjectGame::GetComponentOfTypeHK(v25, Render::FXSimComponent::_TypeUID);
                      }
                      fxComponent = (Render::FXSimComponent *)v28;
                    }
                    else
                    {
                      fxComponent = 0i64;
                    }
                    v29 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
                    if ( v29 )
                    {
                      v30 = v29->m_Flags;
                      if ( !((v30 >> 14) & 1) && (v30 & 0x8000u) == 0 && !((v30 >> 13) & 1) )
                      {
                        if ( (v30 >> 12) & 1 )
                          UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::BaseAnimationComponent::_TypeUID);
                        else
                          UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)&v29->vfptr,
                            UFG::BaseAnimationComponent::_TypeUID);
                      }
                    }
                    if ( fxComponent )
                    {
                      LODWORD(iBoneID) = v9[6].m_BoundComponentHandles.mNode.mPrev;
                      Render::ImpactManager::HandleHitRecordImpactEvent(
                        &Render::gImpactManager,
                        v11,
                        v24,
                        (UFG::qVector3 *)((char *)&v9[4].m_SafePointerList.mNode.mPrev + 4),
                        (UFG::qVector3 *)&v9[4].m_TypeUID,
                        fxComponent,
                        iBoneID,
                        (UFG::qVector3 *)((char *)&v9[6].m_BoundComponentHandles.mNode.mPrev + 4));
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
  ActionContext *v2; // r15
  EffectSurfaceCollisionTask *v3; // rbp
  ITrack *v4; // r8
  bool v5; // bl
  signed __int64 v6; // rax
  unsigned int v7; // er14
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v8; // rcx
  const char *v9; // rax
  unsigned int v10; // eax
  UFG::qVector3 vOutGroundNormal; // [rsp+58h] [rbp-60h]
  UFG::qVector3 vOutEffectPosition; // [rsp+68h] [rbp-50h]
  UFG::qReflectHandleBase v13; // [rsp+78h] [rbp-40h]
  unsigned __int64 uSurfaceMaterialHandleUID; // [rsp+C0h] [rbp+8h]
  unsigned __int64 uObjectMaterialHandleUID; // [rsp+D0h] [rbp+18h]

  v2 = pContext;
  v3 = this;
  v4 = this->m_Track;
  v5 = BYTE5(v4[1].mResourceOwner) != 0;
  if ( BYTE4(v4[1].mResourceOwner) || BYTE5(v4[1].mResourceOwner) )
  {
    v6 = (signed int)gAttackCollisionEnum.m_enumLists.size <= 0 ? 0i64 : *((_QWORD *)gAttackCollisionEnum.m_enumLists.p
                                                                         + 7);
    v7 = UFG::qStringHashUpper32(*(const char **)(*(_QWORD *)(v6 + 16) + 8i64 * LODWORD(v4[1].vfptr)), 0xFFFFFFFF);
    if ( v7 )
    {
      if ( EffectSurfaceCollisionTask::projectBoneOntoGround(
             v3,
             v2->mSimObject.m_pPointer,
             &vOutEffectPosition,
             &vOutGroundNormal,
             &uObjectMaterialHandleUID,
             &uSurfaceMaterialHandleUID)
        && (uSurfaceMaterialHandleUID || uObjectMaterialHandleUID) )
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v13);
        v9 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v8);
        v13.mTypeUID = UFG::qStringHash64(v9, 0xFFFFFFFFFFFFFFFFui64);
        UFG::PhysicsPropertyManager::GetObjectProperties(
          (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v13,
          v7,
          1);
        if ( v13.mData && v5 )
        {
          v10 = EffectSurfaceCollisionTask::GetBestEffectPropertyValue(
                  v3,
                  v2,
                  uObjectMaterialHandleUID,
                  uSurfaceMaterialHandleUID);
          if ( v10 != -1 )
            Render::ImpactManager::HandleImpactEvent(
              &Render::gImpactManager,
              v7,
              v10,
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
__int64 __fastcall EffectSurfaceCollisionTask::GetBestEffectPropertyValue(EffectSurfaceCollisionTask *this, ActionContext *pContext, unsigned __int64 uObjectMaterialHandleUID, unsigned __int64 uSurfaceMaterialHandleUID)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rdi
  unsigned int v6; // ebx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v9; // rcx
  const char *v10; // rax
  UFG::qReflectHandleBase v12; // [rsp+28h] [rbp-30h]

  v4 = uSurfaceMaterialHandleUID;
  v5 = uObjectMaterialHandleUID;
  v6 = -1;
  if ( !uSurfaceMaterialHandleUID )
    goto LABEL_12;
  UFG::qReflectHandleBase::qReflectHandleBase(&v12);
  v8 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v7);
  v12.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v12, v12.mTypeUID, v4);
  if ( v12.mData )
    v6 = HIDWORD(v12.mData[1].mBaseNode.mChildren[0]);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v12);
  if ( v6 == -1 )
  {
LABEL_12:
    if ( v5 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v12);
      v10 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v9);
      v12.mTypeUID = UFG::qStringHash64(v10, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v12, v12.mTypeUID, v5);
      if ( v12.mData )
        v6 = *(_DWORD *)(v12.mData[4].mBaseNode.mUID + 108);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v12);
    }
  }
  return v6;
}

// File Line: 654
// RVA: 0x403B40
char __fastcall EffectSurfaceCollisionTask::projectBoneOntoGround(EffectSurfaceCollisionTask *this, UFG::SimObject *pSimObj, UFG::qVector3 *vOutEffectPosition, UFG::qVector3 *vOutGroundNormal, unsigned __int64 *iOutObjectTypeHandleUID, unsigned __int64 *iOutSurfaceTypeHandleUID)
{
  UFG::qVector3 *v6; // rdi
  UFG::qVector3 *v7; // rsi
  EffectSurfaceCollisionTask *v8; // r14
  UFG::SimComponent *v9; // rax
  unsigned __int16 v10; // cx
  Creature *v11; // rbx
  UFG::qSymbolUC *v12; // rax
  int v13; // eax
  ITrack *v14; // rax
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  unsigned __int64 *v18; // rcx
  unsigned __int64 v19; // rax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-E0h]
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-D0h]
  UFG::RayCastData data; // [rsp+40h] [rbp-C0h]
  UFG::qMatrix44 transform; // [rsp+120h] [rbp+20h]
  UFG::qSymbolUC result; // [rsp+198h] [rbp+98h]

  v6 = vOutGroundNormal;
  v7 = vOutEffectPosition;
  v8 = this;
  if ( pSimObj )
  {
    v10 = pSimObj->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v9 = pSimObj->m_Components.p[9].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v9 = pSimObj->m_Components.p[8].m_pComponent;
      }
      else if ( (v10 >> 12) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)pSimObj,
               UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        v9 = UFG::SimObject::GetComponentOfType(pSimObj, UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v9 = pSimObj->m_Components.p[9].m_pComponent;
    }
  }
  else
  {
    v9 = 0i64;
  }
  v11 = *(Creature **)&v9[2].m_TypeUID;
  if ( !v11 )
    return 0;
  v12 = EffectSurfaceCollisionTrack::GetBoneUID((EffectSurfaceCollisionTrack *)v8->m_Track, &result);
  v13 = v11->mPose.mRigHandle.mData ? (unsigned int)Skeleton::GetBoneID(v11->mPose.mRigHandle.mUFGSkeleton, v12->mUID) : -1;
  Creature::GetTransform(v11, v13, &transform);
  v14 = v8->m_Track;
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
  v15 = *(float *)&v14[1].mResourceOwner * UFG::qVector3::msDirUp.x;
  v16 = *(float *)&v14[1].mResourceOwner * UFG::qVector3::msDirUp.y;
  rayEnd.z = transform.v3.z - (float)(*(float *)&v14[1].mResourceOwner * UFG::qVector3::msDirUp.z);
  rayEnd.x = transform.v3.x - v15;
  rayEnd.y = transform.v3.y - v16;
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0xCu);
  if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
    return 0;
  v17 = data.point.y;
  v18 = iOutObjectTypeHandleUID;
  v19 = data.mPhysicsObjectPropertyHandleUid;
  v7->x = data.point.x;
  v20 = data.point.z;
  v7->y = v17;
  v21 = data.normal.x;
  v7->z = v20;
  v22 = data.normal.y;
  v6->x = v21;
  v23 = data.normal.z;
  v6->y = v22;
  v6->z = v23;
  *v18 = v19;
  *iOutSurfaceTypeHandleUID = data.mPhysicsSurfacePropertyHandleUid;
  return 1;
}

// File Line: 706
// RVA: 0x3FFC40
void __fastcall RumbleTask::Begin(RumbleTask *this, ActionContext *context)
{
  AudioTaskSimple *v2; // rbx
  UFG::SimObjectCharacter *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::ActorAudioComponent *v5; // rax

  v2 = (AudioTaskSimple *)this;
  this->mContext = context;
  v3 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    if ( v5 )
    {
      if ( *((_BYTE *)v5 + 553) & 8 )
      {
        AudioTaskSimple::PlayOnActor(v2);
        v2->m_playOnActor = 1;
      }
    }
  }
}

// File Line: 780
// RVA: 0x400D30
void __fastcall AudioTaskSimple::PlayOnActor(AudioTaskSimple *this)
{
  AudioTaskSimple *v1; // rdi
  UFG::SimObjectCharacter *v2; // rcx
  UFG::ActorAudioComponent *v3; // rbx
  unsigned __int16 v4; // dx
  UFG::ActorAudioComponent *v5; // rax
  unsigned int v6; // esi
  ActionContext *v7; // rcx
  unsigned int material; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = (UFG::SimObjectCharacter *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    v3 = v5;
  }
  else
  {
    v3 = 0i64;
  }
  if ( (float)(UFG::TidoGame::sm_TagCutoffDist * UFG::TidoGame::sm_TagCutoffDist) > UFG::AudioEntity::Distance2ToListener(
                                                                                      (UFG::AudioEntity *)&v3->vfptr,
                                                                                      0)
    && v3->m_SFXEntity )
  {
    v6 = HIDWORD(v1->m_Track[1].vfptr);
    if ( v6 )
    {
      v7 = v1->mContext;
      material = 0;
      _((AMD_HD3D *)v7->mSimObject.m_pPointer);
      UFG::TidoGame::SetMaterial2((unsigned __int64)v3->m_SFXEntity, material);
      UFG::AudioEntity::CreateAndPlayEvent(v3->m_SFXEntity, v6, 0i64, 0, 0i64);
    }
  }
}

// File Line: 807
// RVA: 0x402170
char __fastcall RumbleTask::Update(RumbleTask *this, float timeDelta)
{
  char v2; // bp
  RumbleTask *v3; // rdi
  UFG::SimObject *v4; // rbx
  UFG::OneShot *v5; // rcx
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  UFG::SimObjectCharacter *v9; // rcx
  UFG::ActorAudioComponent *v10; // rbx
  unsigned __int16 v11; // dx
  UFG::ActorAudioComponent *v12; // rax
  UFG::AudioEntity *v13; // rcx
  bool v14; // zf
  char result; // al

  v2 = 0;
  v3 = this;
  if ( !this->m_playOnActor && UFG::OneShotHandle::IsValid(&this->m_oneShot) )
  {
    if ( v3->m_oneShot.m_pOneShot->m_controller.m_pEvent )
    {
      v4 = v3->mContext->mSimObject.m_pPointer;
      if ( v4 )
        v4 = (UFG::SimObject *)v4->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
      v5 = v3->m_oneShot.m_pOneShot;
      v6 = *(UFG::qVector4 *)&v4[1].m_SafePointerList.mNode.mNext;
      v7 = *(UFG::qVector4 *)&v4[1].m_SafePointerWithCallbackList.mNode.mNext;
      v8 = *(UFG::qVector4 *)v4[1].mNode.mChild;
      v5->m_WorldMatrix.v0 = *(UFG::qVector4 *)&v4[1].vfptr;
      v5->m_WorldMatrix.v1 = v6;
      v5->m_WorldMatrix.v2 = v7;
      v5->m_WorldMatrix.v3 = v8;
      UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&v5->vfptr);
      v2 = 1;
    }
    else
    {
      UFG::OneShotHandle::Release(&v3->m_oneShot);
    }
    return v2;
  }
  if ( !v3->m_playOnActor )
    return v2;
  v9 = (UFG::SimObjectCharacter *)v3->mContext->mSimObject.m_pPointer;
  if ( v9 )
  {
    v11 = v9->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v9);
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        v12 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v9->vfptr,
                                            UFG::ActorAudioComponent::_TypeUID);
      else
        v12 = (UFG::ActorAudioComponent *)((v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v9->vfptr,
                                                               UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v12 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v9->vfptr,
                                          UFG::ActorAudioComponent::_TypeUID);
    }
    v10 = v12;
  }
  else
  {
    v10 = 0i64;
  }
  v13 = v10->m_SFXEntity;
  if ( !v13 )
    return v2;
  v14 = UFG::AudioEntity::IsPlayingId(v13, HIDWORD(v3->m_Track[1].vfptr)) == 0;
  result = 1;
  if ( v14 )
    return v2;
  return result;
}

// File Line: 857
// RVA: 0x3FDE00
void __fastcall VisualTreatmentTask::VisualTreatmentTask(VisualTreatmentTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<VisualTreatmentTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&VisualTreatmentTask::`vftable';
  this->mContext = 0i64;
  this->mVisualTreatmentId = -1;
}

// File Line: 861
// RVA: 0x3FFDF0
void __fastcall VisualTreatmentTask::Begin(VisualTreatmentTask *this, ActionContext *context)
{
  ITrack *v2; // rax
  VisualTreatmentTask *v3; // rbx
  ITrack *v4; // rax
  __int64 v5; // rdi
  unsigned int v6; // eax

  v2 = this->m_Track;
  this->mContext = context;
  v3 = this;
  if ( !BYTE5(v2[1].mResourceOwner)
    || UFG::GetLocalPlayer() == (UFG::SimObjectCharacter *)this->mContext->mSimObject.m_pPointer )
  {
    v4 = v3->m_Track;
    v5 = LODWORD(v4[1].vfptr);
    v6 = UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(
           (int)v4[1].vfptr,
           BYTE6(v4[1].mResourceOwner) != 0,
           HIDWORD(v4[1].vfptr));
    v3->mVisualTreatmentId = v6;
    if ( v6 != -1 )
    {
      UFG::RenderWorld::AccumulationBufferPostEffect_SetEnable(0.1 < *(float *)&v3->m_Track[1].mResourceOwner);
      if ( (gVisualTreatmentEnum.m_enumLists.size & 0x80000000) != 0 )
        UFG::TidoGame::PlayVisualEffectAudio(0);
      else
        UFG::TidoGame::PlayVisualEffectAudio((*gVisualTreatmentEnum.m_enumLists.p)->m_enumNameHash.p[v5]);
    }
  }
}

// File Line: 883
// RVA: 0x400670
void __fastcall VisualTreatmentTask::End(VisualTreatmentTask *this)
{
  VisualTreatmentTask *v1; // rbx

  v1 = this;
  UFG::OnlineManager::Instance();
  if ( v1->mVisualTreatmentId != -1 )
  {
    UFG::RenderWorld::AccumulationBufferPostEffect_SetEnable(0);
    UFG::RenderWorld::VisualTreatmentPostEffect_StopVisualTreatment(
      v1->mVisualTreatmentId,
      *(float *)&v1->m_Track[1].m_TrackClassNameUID);
    if ( (gVisualTreatmentEnum.m_enumLists.size & 0x80000000) != 0 )
      UFG::TidoGame::StopVisualEffectAudio(0);
    else
      UFG::TidoGame::StopVisualEffectAudio((*gVisualTreatmentEnum.m_enumLists.p)->m_enumNameHash.p[LODWORD(v1->m_Track[1].vfptr)]);
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  unsigned int v4; // edx
  bool v5; // zf

  this->m_pContext = pContext;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( !((v3 >> 14) & 1) && (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = UFG::TargetingSystemBaseComponent::_TypeUID;
LABEL_6:
        UFG::SimObjectGame::GetComponentOfTypeHK(v2, v4);
        return;
      }
      v5 = ((v3 >> 12) & 1) == 0;
      v4 = UFG::TargetingSystemBaseComponent::_TypeUID;
      if ( !v5 )
        goto LABEL_6;
      UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
  }
}

// File Line: 929
// RVA: 0x4005F0
void __fastcall RimLightTargetTask::End(RimLightTargetTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  unsigned int v3; // edx
  bool v4; // zf

  v1 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( !((v2 >> 14) & 1) && (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = UFG::TargetingSystemBaseComponent::_TypeUID;
LABEL_6:
        UFG::SimObjectGame::GetComponentOfTypeHK(v1, v3);
        return;
      }
      v4 = ((v2 >> 12) & 1) == 0;
      v3 = UFG::TargetingSystemBaseComponent::_TypeUID;
      if ( !v4 )
        goto LABEL_6;
      UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
  }
}

// File Line: 944
// RVA: 0x3FFC20
void __fastcall RimLightTask::Begin(RimLightTask *this, ActionContext *pContext)
{
  this->m_pContext = pContext;
  UFG::RadarSystem::AddRimLight(UFG::RadarSystem::sInstance, pContext->mSimObject.m_pPointer);
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
  ApplyWetnessOrSweatTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rcx
  ITrack *v7; // rax
  float v8; // xmm2_4
  float v9; // xmm0_4

  v2 = this;
  this->m_pContext = pContext;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterLookComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID);
    }
    v6 = v5;
    if ( v5 )
    {
      v7 = v2->m_Track;
      v8 = *(float *)&v7[1].vfptr;
      v9 = *((float *)&v7[1].vfptr + 1);
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
  ApplyWetnessOrSweatTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rcx
  ITrack *v7; // rax
  float v8; // xmm2_4
  float v9; // xmm0_4
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 1;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID);
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterLookComponent::_TypeUID);
  }
  else
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID);
  }
  v6 = v5;
  if ( !v5 )
    return 1;
  v7 = v2->m_Track;
  v8 = *(float *)&v7[1].vfptr;
  v9 = *((float *)&v7[1].vfptr + 1);
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
  ApplyWetnessOrSweatTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterLookComponent::_TypeUID);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterLookComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterLookComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CharacterLookComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterLookComponent::_TypeUID);
    }
    if ( v4 )
    {
      if ( *(float *)&v1->m_Track[1].vfptr > -1.0 )
        LODWORD(v4[2].m_BoundComponentHandles.mNode.mNext) = -1082130432;
    }
  }
}

// File Line: 1027
// RVA: 0x3FFCE0
void __fastcall SetHighlightingModeTask::Begin(SetHighlightingModeTask *this, ActionContext *pContext)
{
  SetHighlightingModeTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rsi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rbx
  int v8; // edi
  int v9; // eax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CompositeLookComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CompositeLookComponent::_TypeUID);
      else
        v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CompositeLookComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CompositeLookComponent::_TypeUID);
    }
    else
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CompositeLookComponent::_TypeUID);
    }
    v7 = v6;
    if ( v6 )
    {
      v8 = LOBYTE(v2->m_Track[1].vfptr);
      v9 = (int)v6[1].m_BoundComponentHandles.mNode.mPrev;
      if ( v9 != v8 )
      {
        if ( v9 == 4 )
        {
          UFG::RadarSystem::RemoveCombatProp(UFG::RadarSystem::sInstance, v4->mSimObject.m_pPointer);
        }
        else if ( v9 == 1 )
        {
          UFG::RadarSystem::RemoveRimLight(UFG::RadarSystem::sInstance, v4->mSimObject.m_pPointer);
        }
        LODWORD(v7[1].m_BoundComponentHandles.mNode.mPrev) = v8;
        if ( v8 == 4 )
        {
          UFG::RadarSystem::AddCombatProp(UFG::RadarSystem::sInstance, v4->mSimObject.m_pPointer);
        }
        else if ( v8 == 1 )
        {
          UFG::RadarSystem::AddRimLight(UFG::RadarSystem::sInstance, v4->mSimObject.m_pPointer);
        }
      }
    }
  }
}

