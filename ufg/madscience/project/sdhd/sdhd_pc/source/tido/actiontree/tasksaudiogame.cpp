// File Line: 48
// RVA: 0x2DDEA0
void __fastcall AudioTaskSurfaceDetection::AudioTaskSurfaceDetection(AudioTaskSurfaceDetection *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AudioTrackSurfaceDetection>::`vftable;
  this->vfptr = (ITaskVtbl *)&AudioTaskSurfaceDetection::`vftable;
  this->mContext = 0i64;
  this->m_oneShot.m_pOneShot = 0i64;
}

// File Line: 58
// RVA: 0x301BE0
__int64 __fastcall AudioTaskSurfaceDetection::GetBestAudioPropertyValue(
        AudioTaskSurfaceDetection *this,
        unsigned __int64 uObjectMaterialHandleUID,
        unsigned __int64 uSurfaceMaterialHandleUID)
{
  unsigned int v5; // ebx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v8; // rcx
  const char *v9; // rax
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h] BYREF

  v5 = -1;
  if ( !uSurfaceMaterialHandleUID )
    goto LABEL_5;
  UFG::qReflectHandleBase::qReflectHandleBase(&v11);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v6);
  v11.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, uSurfaceMaterialHandleUID);
  if ( v11.mData )
    v5 = (unsigned int)v11.mData[1].mBaseNode.mChildren[0];
  UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
  if ( v5 == -1 )
  {
LABEL_5:
    if ( uObjectMaterialHandleUID )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v11);
      v9 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v8);
      v11.mTypeUID = UFG::qStringHash64(v9, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, uObjectMaterialHandleUID);
      if ( v11.mData )
        v5 = *(_DWORD *)(v11.mData[4].mBaseNode.mUID + 104);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
    }
  }
  return v5;
}

// File Line: 101
// RVA: 0x2FD3E0
__int64 __fastcall AudioTaskSurfaceDetection::CastRay(AudioTaskSurfaceDetection *this)
{
  unsigned int BestAudioPropertyValue; // edi
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  Creature *mCreature; // rbx
  UFG::qSymbolUC *BoneUID; // rax
  int BoneID; // eax
  UFG::qVector3 start; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qVector3 end; // [rsp+40h] [rbp-98h] BYREF
  __int64 v12; // [rsp+50h] [rbp-88h]
  UFG::ShapeCasterCollector sc; // [rsp+58h] [rbp-80h] BYREF
  UFG::qMatrix44 transform; // [rsp+90h] [rbp-48h] BYREF
  UFG::qSymbolUC result; // [rsp+E0h] [rbp+8h] BYREF

  v12 = -2i64;
  BestAudioPropertyValue = -1;
  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  mCreature = ComponentOfTypeHK->mCreature;
  if ( mCreature )
  {
    BoneUID = AudioTrackSurfaceDetection::GetBoneUID((AudioTrackSurfaceDetection *)this->m_Track, &result);
    if ( mCreature->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, BoneUID->mUID);
    else
      BoneID = -1;
    Creature::GetTransform(mCreature, BoneID, &transform);
    UFG::ShapeCasterCollector::ShapeCasterCollector(
      &sc,
      *((float *)&this->m_Track[2].mMasterRate.text.mOffset + 1),
      0xCu,
      PhantomBehaviour_Simple);
    start.x = transform.v3.x - 0.1;
    start.y = transform.v3.y - 0.1;
    start.z = transform.v3.z - 0.1;
    end.x = (float)(transform.v3.x - 0.1) + 0.1;
    end.y = (float)(transform.v3.y - 0.1) + 0.1;
    end.z = (float)(transform.v3.z - 0.1) + 0.1;
    if ( UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem::mInstance, &sc, &start, &end) )
      BestAudioPropertyValue = AudioTaskSurfaceDetection::GetBestAudioPropertyValue(
                                 this,
                                 (unsigned __int64)sc.mHitList.mNode.mNext[5].mNext,
                                 (unsigned __int64)sc.mHitList.mNode.mNext[6].mPrev);
    UFG::ShapeCasterCollector::~ShapeCasterCollector(&sc);
  }
  return BestAudioPropertyValue;
}

// File Line: 142
// RVA: 0x2E98B0
void __fastcall AudioTaskSurfaceDetection::Begin(AudioTaskSurfaceDetection *this, ActionContext *context)
{
  unsigned int LatchedParkourObjectMaterial; // esi
  unsigned int mOffset; // ebp
  UFG::TransformNodeComponent *m_pPointer; // rdi

  this->mContext = context;
  LatchedParkourObjectMaterial = AudioTaskSurfaceDetection::CastRay(this);
  if ( LatchedParkourObjectMaterial == -1 )
    LatchedParkourObjectMaterial = UFG::TidoGame::FindLatchedParkourObjectMaterial(this->mContext->mSimObject.m_pPointer);
  mOffset = this->m_Track[1].mMasterRate.text.mOffset;
  if ( mOffset )
  {
    m_pPointer = (UFG::TransformNodeComponent *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
      m_pPointer = (UFG::TransformNodeComponent *)m_pPointer->mChildren.mNode.mNext;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pPointer);
    UFG::OneShotPool::GetOneShotHandle(&this->m_oneShot, &m_pPointer->mWorldTransform);
    if ( UFG::OneShotHandle::IsValid(&this->m_oneShot) )
    {
      UFG::TidoGame::SetMaterial1((unsigned __int64)this->m_oneShot.m_pOneShot, LatchedParkourObjectMaterial);
      UFG::OneShot::Play(this->m_oneShot.m_pOneShot, mOffset);
    }
  }
  else
  {
    UFG::OneShotHandle::StopAndRelease(&this->m_oneShot);
  }
}

// File Line: 178
// RVA: 0x303DB0
_BOOL8 __fastcall AudioTaskSurfaceDetection::Update(AudioTaskSurfaceDetection *this, float timeDelta)
{
  return UFG::OneShotHandle::IsValid(&this->m_oneShot);
}

// File Line: 215
// RVA: 0x2F20D0
void __fastcall PoliceScannerAudioEventTask::Begin(PoliceScannerAudioEventTask *this, ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // rbx
  int v4; // xmm1_4
  int v5; // xmm2_4

  if ( !LODWORD(this->m_Track[1].vfptr) )
  {
    m_pPointer = action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
      m_pPointer = (UFG::SimObject *)m_pPointer->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
    v4 = HIDWORD(m_pPointer[1].mNode.mChild[0]);
    v5 = (int)m_pPointer[1].mNode.mChild[1];
    unk_14242F140 = m_pPointer[1].mNode.mChild[0];
    unk_14242F144 = v4;
    unk_14242F14C = (_DWORD)FLOAT_1_0;
    unk_14242F148 = v5;
    UFG::AudioEntity::ForcePositionUpdate(&UFG::PoliceScannerAudio::sm_Instance);
    UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 1);
  }
  if ( LODWORD(this->m_Track[1].vfptr) == 1 )
    UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 0);
}

// File Line: 244
// RVA: 0x304380
bool __fastcall DialogueTaskBase::Update(DialogueTaskBase *this, float timeDelta)
{
  hkgpIndexedMeshDefinitions::Edge *v2; // rdx
  bool result; // al
  UFG::SimObjectCharacter *m_pPointer; // rcx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  bool v8; // zf
  float v9; // xmm6_4

  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, v2) )
    return 0;
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
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  if ( !this->mContext || !ComponentOfTypeHK )
    return 0;
  v8 = (*((_BYTE *)this + 20) & 1) == 0;
  v9 = timeDelta + this->m_failTimer;
  this->m_failTimer = v9;
  if ( !v8 )
    return v9 <= 1.5;
  if ( ComponentOfTypeHK->m_isSpeakingCnt > 0 && ComponentOfTypeHK->m_controller.m_pEvent )
    return v9 <= 10.0;
  result = 0;
  if ( v9 > 10.0 )
    return 0;
  return result;
}

// File Line: 301
// RVA: 0x2DF020
void __fastcall DialogueTask::DialogueTask(DialogueTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->Task<DialogueTrack>::ITask::vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->Task<DialogueTrack>::ITask::vfptr = (ITaskVtbl *)&Task<DialogueTrack>::`vftable;
  this->DialogueTaskBase::vfptr = (DialogueTaskBaseVtbl *)&DialogueTaskBase::`vftable;
  this->m_failTimer = 0.0;
  *((_BYTE *)&this->DialogueTaskBase + 20) &= ~1u;
  this->mContext = 0i64;
  this->Task<DialogueTrack>::ITask::vfptr = (ITaskVtbl *)&DialogueTask::`vftable{for `Task<DialogueTrack>};
  this->DialogueTaskBase::vfptr = (DialogueTaskBaseVtbl *)&DialogueTask::`vftable{for `DialogueTaskBase};
}

// File Line: 306
// RVA: 0x2ED730
void __fastcall DialogueTask::Begin(DialogueTask *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::ActorAudioComponent *v6; // rax
  UFG::ActorAudioComponent *v7; // rbx
  ITrack *m_Track; // rcx
  unsigned int mOffset_high; // r15d
  char *v10; // rax
  const char *v11; // rdi
  float v12; // xmm6_4
  char v13; // al
  ActionController *mActionController; // rcx
  const char *Clone; // rax
  char *v16; // rax
  UFG::qString v17; // [rsp+48h] [rbp-D0h] BYREF
  char name[144]; // [rsp+70h] [rbp-A8h] BYREF

  this->mContext = context;
  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v6 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    else
      v6 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID));
    v7 = v6;
    if ( v6
      && (float)(UFG::TidoGame::sm_DlgTagCutoffDist * UFG::TidoGame::sm_DlgTagCutoffDist) > UFG::AudioEntity::Distance2ToListener(
                                                                                              &v6->UFG::AudioEntity,
                                                                                              0) )
    {
      m_Track = this->m_Track;
      mOffset_high = HIDWORD(m_Track[1].mMasterRate.text.mOffset);
      DialogueTrackBase::GetTag((DialogueTrackBase *)&m_Track[1], 1, name);
      v10 = UFG::qStringFind(name, "_");
      v11 = v10 ? v10 + 1 : name;
      v12 = *(float *)&this->m_Track[1].mResourceOwner;
      if ( UFG::qRandom(100.0, (unsigned int *)&UFG::qDefaultSeed) < v12 )
      {
        if ( UFG::TidoGame::sm_debugDialogueState )
          UFG::AudioEntity::Distance2ToListener(&v7->UFG::AudioEntity, 0);
        v13 = UFG::ActorAudioComponent::QueueSpeechExternalAmbient(
                v7,
                mOffset_high,
                v11,
                0i64,
                HIDWORD(this->m_Track[1].mResourceOwner),
                0,
                0);
        *((_BYTE *)&this->DialogueTaskBase + 20) &= ~1u;
        *((_BYTE *)&this->DialogueTaskBase + 20) |= v13 == 0;
        if ( (*((_BYTE *)&this->DialogueTaskBase + 20) & 1) != 0 && UFG::TidoGame::sm_debugDialogueState )
        {
          UFG::qString::qString(&v17, &customCaption);
          mActionController = context->mActionController;
          if ( mActionController )
          {
            Clone = (const char *)TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)mActionController);
            UFG::qString::Set(&v17, Clone);
          }
          v16 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&context->mSimObject.m_pPointer->m_Name);
          UFG::qPrintf("Speech failed to play on %s \n\tat node: %s\n\t context: %s\n", v16, v17.mData, v11);
          UFG::qString::~qString(&v17);
        }
      }
    }
  }
}

// File Line: 380
// RVA: 0x2DF090
void __fastcall DialogueTaskPOI::DialogueTaskPOI(DialogueTaskPOI *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->Task<DialogueTrackPOI>::ITask::vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->Task<DialogueTrackPOI>::ITask::vfptr = (ITaskVtbl *)&Task<DialogueTrackPOI>::`vftable;
  this->DialogueTaskBase::vfptr = (DialogueTaskBaseVtbl *)&DialogueTaskBase::`vftable;
  this->m_failTimer = 0.0;
  *((_BYTE *)&this->DialogueTaskBase + 20) &= ~1u;
  this->mContext = 0i64;
  this->Task<DialogueTrackPOI>::ITask::vfptr = (ITaskVtbl *)&DialogueTaskPOI::`vftable{for `Task<DialogueTrackPOI>};
  this->DialogueTaskBase::vfptr = (DialogueTaskBaseVtbl *)&DialogueTaskPOI::`vftable{for `DialogueTaskBase};
}

// File Line: 386
// RVA: 0x2ED940
void __fastcall DialogueTaskPOI::Begin(DialogueTaskPOI *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::ActorAudioComponent *v6; // rax
  UFG::ActorAudioComponent *v7; // rbx
  int v8; // eax
  UFG::qString *v9; // rax
  float v10; // xmm6_4
  char v11; // al
  char *mData; // rdi
  char *v13; // rbx
  const char *Clone; // rax
  UFG::qString v15; // [rsp+40h] [rbp-F8h] BYREF
  __int64 v16; // [rsp+68h] [rbp-D0h]
  UFG::qString result; // [rsp+70h] [rbp-C8h] BYREF
  char name[144]; // [rsp+A0h] [rbp-98h] BYREF

  v16 = -2i64;
  this->mContext = context;
  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v6 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    else
      v6 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID));
    v7 = v6;
    if ( v6 )
    {
      DialogueTrackBase::GetTag((DialogueTrackBase *)&this->m_Track[1], 1, name);
      UFG::qString::qString(&v15, name);
      v8 = UFG::qString::find(&v15, "_");
      v9 = UFG::qString::Substring(&v15, &result, v8 + 1, -1);
      UFG::qString::Set(&v15, v9->mData, v9->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      v10 = *(float *)&this->m_Track[1].mResourceOwner;
      if ( UFG::qRandom(100.0, (unsigned int *)&UFG::qDefaultSeed) < v10 )
      {
        if ( UFG::TidoGame::sm_debugDialogueState )
          UFG::AudioEntity::Distance2ToListener(&v7->UFG::AudioEntity, 0);
        v11 = UFG::ActorAudioComponent::QueueSpeechExternalAmbient(
                v7,
                0,
                v15.mData,
                0i64,
                HIDWORD(this->m_Track[1].mResourceOwner),
                0,
                0);
        *((_BYTE *)&this->DialogueTaskBase + 20) &= ~1u;
        *((_BYTE *)&this->DialogueTaskBase + 20) |= v11 == 0;
        if ( (*((_BYTE *)&this->DialogueTaskBase + 20) & 1) != 0 && UFG::TidoGame::sm_debugDialogueState )
        {
          mData = v15.mData;
          v13 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&context->mSimObject.m_pPointer->m_Name);
          Clone = (const char *)TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)context->mActionController);
          UFG::qPrintf("Speech failed to play on %s \n\tat node: %s\n\tcontext: %s\n", v13, Clone, mData);
        }
      }
      UFG::qString::~qString(&v15);
    }
  }
}

// File Line: 470
// RVA: 0x2DF100
void __fastcall DialogueTaskWeaponImpact::DialogueTaskWeaponImpact(DialogueTaskWeaponImpact *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->Task<DialogueTrackWeaponImpact>::ITask::vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->Task<DialogueTrackWeaponImpact>::ITask::vfptr = (ITaskVtbl *)&Task<DialogueTrackWeaponImpact>::`vftable;
  this->DialogueTaskBase::vfptr = (DialogueTaskBaseVtbl *)&DialogueTaskBase::`vftable;
  this->m_failTimer = 0.0;
  *((_BYTE *)&this->DialogueTaskBase + 20) &= ~1u;
  this->mContext = 0i64;
  this->Task<DialogueTrackWeaponImpact>::ITask::vfptr = (ITaskVtbl *)&DialogueTaskWeaponImpact::`vftable{for `Task<DialogueTrackWeaponImpact>};
  this->DialogueTaskBase::vfptr = (DialogueTaskBaseVtbl *)&DialogueTaskWeaponImpact::`vftable{for `DialogueTaskBase};
}

// File Line: 475
// RVA: 0x149ECA0
__int64 dynamic_initializer_for__qwsDTags__()
{
  UFG::qWiseSymbol::create_from_string(&qwsDTags, "d_tags");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__qwsDTags__);
}

// File Line: 480
// RVA: 0x2EDB40
void __fastcall DialogueTaskWeaponImpact::Begin(DialogueTaskWeaponImpact *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *v5; // rax
  UFG::ActorAudioComponent *v6; // rbx
  ITrack *m_Track; // r9
  __int64 v8; // rcx
  __int64 v9; // r8
  __int64 v10; // rax
  unsigned int v11; // edx
  unsigned int WeaponTypeFromHitRecord; // eax
  float v13; // xmm6_4
  UFG::DialogArgList args; // [rsp+38h] [rbp-40h] BYREF

  this->mContext = context;
  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    else
      v5 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID));
    v6 = v5;
    if ( v5 )
    {
      args.vfptr = (UFG::DialogArgListVtbl *)&UFG::DialogArgList::`vftable;
      UFG::qMemSet(args.m_args, 0, 0x18u);
      args.m_nArgs = 0;
      args.m_uDialogEventId = qwsDTags.mUID;
      m_Track = this->m_Track;
      v8 = 72i64;
      v9 = 3i64;
      v10 = 0i64;
      do
      {
        v11 = *(_DWORD *)((char *)&m_Track->vfptr + v8);
        if ( v11 && (unsigned int)v10 < 6 )
        {
          args.m_args[v10] = v11;
          v10 = ++args.m_nArgs;
        }
        v8 += 4i64;
        --v9;
      }
      while ( v9 );
      WeaponTypeFromHitRecord = DialogueTaskWeaponImpact::GetWeaponTypeFromHitRecord(this);
      if ( WeaponTypeFromHitRecord && args.m_nArgs < 6 )
        args.m_args[args.m_nArgs++] = WeaponTypeFromHitRecord;
      v13 = *(float *)&this->m_Track[1].vfptr;
      if ( UFG::qRandom(100.0, (unsigned int *)&UFG::qDefaultSeed) < v13 )
        UFG::ActorAudioComponent::QueueSpeech(v6, &args, 0i64, HIDWORD(this->m_Track[1].vfptr), 0, 0);
    }
  }
}

// File Line: 524
// RVA: 0x3021D0
__int64 __fastcall DialogueTaskWeaponImpact::GetWeaponTypeFromHitRecord(DialogueTaskWeaponImpact *this)
{
  unsigned int mUID; // ebx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int AttackMaterialUIDForAttacker; // edi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  UFG::PhysicsObjectProperties *mData; // rcx
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h] BYREF

  mUID = 0;
  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    if ( m_pComponent )
    {
      AttackMaterialUIDForAttacker = findAttackMaterialUIDForAttacker(
                                       this->mContext,
                                       *(UFG::SimObject **)&m_pComponent[3].m_TypeUID,
                                       HIDWORD(m_pComponent[3].m_BoundComponentHandles.mNode.mPrev));
      if ( AttackMaterialUIDForAttacker )
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v11);
        TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
        v11.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, AttackMaterialUIDForAttacker);
        mData = (UFG::PhysicsObjectProperties *)v11.mData;
        if ( v11.mData )
        {
          if ( (_S10_2 & 1) == 0 )
          {
            _S10_2 |= 1u;
            AudioAttackMaterialProperty_0.mUID = UFG::qWiseSymbolUIDFromString(
                                                   "AudioAttackMaterialProperty",
                                                   0x811C9DC5);
            _((AMD_HD3D *)AudioAttackMaterialProperty_0.mUID);
            atexit(DialogueTaskWeaponImpact::GetWeaponTypeFromHitRecord_::_11_::_dynamic_atexit_destructor_for__AudioAttackMaterialProperty__);
            mData = (UFG::PhysicsObjectProperties *)v11.mData;
          }
          mUID = UFG::PhysicsObjectProperties::GetAudioProperty(mData, &AudioAttackMaterialProperty_0)->mUID;
        }
        UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
        if ( mUID > 0xA6387A05 )
        {
          if ( mUID == -958795327 )
            return 3312069844i64;
          if ( mUID == -446384847 )
            return 1988215150i64;
        }
        else
        {
          switch ( mUID )
          {
            case 0xA6387A05:
              return 1834895853i64;
            case 0x2054ED49u:
              return 915214409i64;
            case 0x5E77F4D1u:
              return 1834895853i64;
            case 0x93B87551:
              return 2732206793i64;
          }
        }
      }
    }
  }
  return 0i64;
}

// File Line: 601
// RVA: 0x3044C0
bool __fastcall DialogueTaskWeaponImpact::Update(DialogueTaskWeaponImpact *this, float timeDelta)
{
  hkgpIndexedMeshDefinitions::Edge *v2; // rdx
  UFG::SimObjectCharacter *m_pPointer; // rcx
  UFG::ActorAudioComponent *v5; // rax
  __int16 m_Flags; // dx
  bool result; // al

  result = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, v2) )
  {
    m_pPointer = (UFG::SimObjectCharacter *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
      else
        v5 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                        ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                            m_pPointer,
                                            UFG::ActorAudioComponent::_TypeUID)
                                        : UFG::SimObject::GetComponentOfType(
                                            m_pPointer,
                                            UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v5 = 0i64;
    }
    if ( this->mContext && v5 && v5->m_isSpeakingCnt > 0 && v5->m_controller.m_pEvent )
      return 1;
  }
  return result;
}

// File Line: 635
// RVA: 0x2EAFE0
void __fastcall ConversationTaskCreate::Begin(ConversationTaskCreate *this, ActionContext *context)
{
  ITrack *m_Track; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::eConversationTopic vfptr; // r14d
  UFG::qSymbol *v7; // rbp
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax
  UFG::qPropertySet *v13; // rcx
  UFG::qPropertySet *v14; // rax
  UFG::SimObjectGame *v15; // rcx
  __int16 v16; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v18; // rcx
  __int64 v19; // rdx
  UFG::SimObjectCharacter *v20; // rbx
  UFG::AmbientConversation *v21; // rax
  UFG::AmbientConversation *v22; // rdi

  m_Track = this->m_Track;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  vfptr = (UFG::eConversationTopic)m_Track[1].vfptr;
  v7 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v10 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v10;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                      + *(_QWORD *)&m_pComponent[1].m_TypeUID
                      + 40);
      if ( v11 )
      {
        v12 = *(_QWORD *)(v11 + 80);
        if ( v12 )
        {
          v13 = *(UFG::qPropertySet **)(v12 + 144);
          if ( v13 )
          {
LABEL_18:
            v14 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                    v13,
                    (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_componentPOI,
                    DEPTH_RECURSE);
            v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
                   v14,
                   (UFG::qArray<unsigned long,0> *)&qSymbol_ConversationTopic,
                   DEPTH_RECURSE);
            goto LABEL_19;
          }
          v13 = *(UFG::qPropertySet **)(v12 + 152);
        }
        else
        {
          v13 = 0i64;
        }
        if ( !v13 )
          goto LABEL_19;
        goto LABEL_18;
      }
    }
  }
LABEL_19:
  v15 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v15 )
  {
    v16 = v15->m_Flags;
    if ( (v16 & 0x4000) != 0 )
    {
      v4 = v15->m_Components.p[20].m_pComponent;
    }
    else if ( v16 >= 0 )
    {
      if ( (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v15, UFG::TargetingSystemBaseComponent::_TypeUID);
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = v15->m_Components.p[20].m_pComponent;
    }
  }
  v18 = *(_QWORD *)&v4[1].m_Flags;
  v19 = *(_QWORD *)&v4[1].m_TypeUID;
  v20 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(v18 + 47) + v19 + 40);
  if ( !v20 )
  {
    v20 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(v18 + 58) + v19 + 40);
    if ( !v20 && vfptr == eConversationTopic_Greet )
      v20 = LocalPlayer;
  }
  v21 = UFG::ConversationManager::AddAmbientConversation(context->mSimObject.m_pPointer->mNode.mUID);
  v22 = v21;
  if ( v21 )
  {
    if ( v7 )
      v21->m_topic = UFG::Conversation::LookupTopic(v7);
    else
      v21->m_topic = vfptr;
    UFG::AmbientConversation::SetupLines(v22, context->mSimObject.m_pPointer, v20);
  }
}

// File Line: 699
// RVA: 0x2EAF50
void __fastcall ConversationTaskCleanup::Begin(ConversationTaskCleanup *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  UFG::Conversation *ActiveAmbientConversation; // rax
  _BOOL8 v6; // rdx

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
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  ActiveAmbientConversation = UFG::ActorAudioComponent::GetActiveAmbientConversation(ComponentOfTypeHK);
  if ( ActiveAmbientConversation )
    UFG::Conversation::ForceFinish(ActiveAmbientConversation, v6);
}

// File Line: 721
// RVA: 0x2EB200
void __fastcall ConversationTaskOperation::Begin(ConversationTaskOperation *this, ActionContext *context)
{
  int vfptr; // ecx
  UFG::SimObjectCharacter *v3; // rcx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  __int16 v5; // dx
  UFG::Conversation *v6; // rax
  UFG::SimObjectCharacter *m_pPointer; // rcx
  UFG::ActorAudioComponent *v8; // rax
  __int16 m_Flags; // dx
  UFG::Conversation *ActiveAmbientConversation; // rax

  vfptr = (int)this->m_Track[1].vfptr;
  if ( vfptr )
  {
    if ( vfptr == 1 )
    {
      m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
          v8 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
        else
          v8 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                              m_pPointer,
                                              UFG::ActorAudioComponent::_TypeUID)
                                          : UFG::SimObject::GetComponentOfType(
                                              m_pPointer,
                                              UFG::ActorAudioComponent::_TypeUID));
      }
      else
      {
        v8 = 0i64;
      }
      ActiveAmbientConversation = UFG::ActorAudioComponent::GetActiveAmbientConversation(v8);
      if ( ActiveAmbientConversation )
      {
        if ( ActiveAmbientConversation->m_type == eConversationType_Ambient )
          UFG::Conversation::Stop(ActiveAmbientConversation, 0);
      }
    }
  }
  else
  {
    v3 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 & 0x4000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v3);
      }
      else if ( v5 < 0 || (v5 & 0x2000) != 0 || (v5 & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v3,
                                                          UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                          v3,
                                                          UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfTypeHK = 0i64;
    }
    v6 = UFG::ActorAudioComponent::GetActiveAmbientConversation(ComponentOfTypeHK);
    if ( v6 )
    {
      if ( v6->m_type == eConversationType_Ambient )
        UFG::Conversation::Start(v6);
    }
  }
}

