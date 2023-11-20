// File Line: 48
// RVA: 0x2DDEA0
void __fastcall AudioTaskSurfaceDetection::AudioTaskSurfaceDetection(AudioTaskSurfaceDetection *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AudioTrackSurfaceDetection>::`vftable';
  this->vfptr = (ITaskVtbl *)&AudioTaskSurfaceDetection::`vftable';
  this->mContext = 0i64;
  this->m_oneShot.m_pOneShot = 0i64;
}

// File Line: 58
// RVA: 0x301BE0
__int64 __fastcall AudioTaskSurfaceDetection::GetBestAudioPropertyValue(AudioTaskSurfaceDetection *this, unsigned __int64 uObjectMaterialHandleUID, unsigned __int64 uSurfaceMaterialHandleUID)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rdi
  unsigned int v5; // ebx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v8; // rcx
  const char *v9; // rax
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h]

  v3 = uSurfaceMaterialHandleUID;
  v4 = uObjectMaterialHandleUID;
  v5 = -1;
  if ( !uSurfaceMaterialHandleUID )
    goto LABEL_12;
  UFG::qReflectHandleBase::qReflectHandleBase(&v11);
  v7 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v6);
  v11.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, v3);
  if ( v11.mData )
    v5 = (unsigned int)v11.mData[1].mBaseNode.mChildren[0];
  UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
  if ( v5 == -1 )
  {
LABEL_12:
    if ( v4 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v11);
      v9 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v8);
      v11.mTypeUID = UFG::qStringHash64(v9, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, v4);
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
  AudioTaskSurfaceDetection *v1; // rsi
  unsigned int v2; // edi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::CharacterAnimationComponent *v4; // rax
  unsigned __int16 v5; // dx
  Creature *v6; // rbx
  UFG::qSymbolUC *v7; // rax
  int v8; // eax
  UFG::qVector3 start; // [rsp+30h] [rbp-A8h]
  UFG::qVector3 end; // [rsp+40h] [rbp-98h]
  __int64 v12; // [rsp+50h] [rbp-88h]
  UFG::ShapeCasterCollector sc; // [rsp+58h] [rbp-80h]
  UFG::qMatrix44 transform; // [rsp+90h] [rbp-48h]
  UFG::qSymbolUC result; // [rsp+E0h] [rbp+8h]

  v12 = -2i64;
  v1 = this;
  v2 = -1;
  v3 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v3->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v3->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
  }
  else
  {
    v4 = 0i64;
  }
  v6 = v4->mCreature;
  if ( v6 )
  {
    v7 = AudioTrackSurfaceDetection::GetBoneUID((AudioTrackSurfaceDetection *)v1->m_Track, &result);
    if ( v6->mPose.mRigHandle.mData )
      v8 = Skeleton::GetBoneID(v6->mPose.mRigHandle.mUFGSkeleton, v7->mUID);
    else
      v8 = -1;
    Creature::GetTransform(v6, v8, &transform);
    UFG::ShapeCasterCollector::ShapeCasterCollector(
      &sc,
      *((float *)&v1->m_Track[2].mMasterRate.text.mOffset + 1),
      0xCu,
      0);
    start.x = transform.v3.x - 0.1;
    start.y = transform.v3.y - 0.1;
    start.z = transform.v3.z - 0.1;
    end.x = (float)(transform.v3.x - 0.1) + 0.1;
    end.y = (float)(transform.v3.y - 0.1) + 0.1;
    end.z = (float)(transform.v3.z - 0.1) + 0.1;
    if ( UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem::mInstance, &sc, &start, &end) )
      v2 = AudioTaskSurfaceDetection::GetBestAudioPropertyValue(
             v1,
             (unsigned __int64)sc.mHitList.mNode.mNext[5].mNext,
             (unsigned __int64)sc.mHitList.mNode.mNext[6].mPrev);
    UFG::ShapeCasterCollector::~ShapeCasterCollector(&sc);
  }
  return v2;
}

// File Line: 142
// RVA: 0x2E98B0
void __fastcall AudioTaskSurfaceDetection::Begin(AudioTaskSurfaceDetection *this, ActionContext *context)
{
  AudioTaskSurfaceDetection *v2; // rbx
  unsigned int v3; // esi
  unsigned int v4; // ebp
  UFG::TransformNodeComponent *v5; // rdi

  v2 = this;
  this->mContext = context;
  v3 = AudioTaskSurfaceDetection::CastRay(this);
  if ( v3 == -1 )
    v3 = UFG::TidoGame::FindLatchedParkourObjectMaterial(v2->mContext->mSimObject.m_pPointer);
  v4 = v2->m_Track[1].mMasterRate.text.mOffset;
  if ( v4 )
  {
    v5 = (UFG::TransformNodeComponent *)v2->mContext->mSimObject.m_pPointer;
    if ( v5 )
      v5 = (UFG::TransformNodeComponent *)v5->mChildren.mNode.mNext;
    UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    UFG::OneShotPool::GetOneShotHandle(&v2->m_oneShot, &v5->mWorldTransform);
    if ( UFG::OneShotHandle::IsValid(&v2->m_oneShot) )
    {
      UFG::TidoGame::SetMaterial1((unsigned __int64)v2->m_oneShot.m_pOneShot, v3);
      UFG::OneShot::Play(v2->m_oneShot.m_pOneShot, v4);
    }
  }
  else
  {
    UFG::OneShotHandle::StopAndRelease(&v2->m_oneShot);
  }
}

// File Line: 178
// RVA: 0x303DB0
__int64 __fastcall AudioTaskSurfaceDetection::Update(AudioTaskSurfaceDetection *this, float timeDelta)
{
  bool v2; // al
  unsigned __int8 v3; // cl

  v2 = UFG::OneShotHandle::IsValid(&this->m_oneShot);
  v3 = 0;
  if ( v2 )
    v3 = 1;
  return v3;
}

// File Line: 215
// RVA: 0x2F20D0
void __fastcall PoliceScannerAudioEventTask::Begin(PoliceScannerAudioEventTask *this, ActionContext *action_context)
{
  PoliceScannerAudioEventTask *v2; // rdi
  UFG::SimObject *v3; // rbx
  int v4; // xmm1_4
  int v5; // xmm2_4

  v2 = this;
  if ( !LODWORD(this->m_Track[1].vfptr) )
  {
    v3 = action_context->mSimObject.m_pPointer;
    if ( v3 )
      v3 = (UFG::SimObject *)v3->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3);
    v4 = HIDWORD(v3[1].mNode.mChild[0]);
    v5 = (int)v3[1].mNode.mChild[1];
    unk_14242F140 = v3[1].mNode.mChild[0];
    unk_14242F144 = v4;
    unk_14242F14C = (_DWORD)FLOAT_1_0;
    unk_14242F148 = v5;
    UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&UFG::PoliceScannerAudio::sm_Instance.vfptr);
    UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 1);
  }
  if ( LODWORD(v2->m_Track[1].vfptr) == 1 )
    UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 0);
}

// File Line: 244
// RVA: 0x304380
bool __usercall DialogueTaskBase::Update@<al>(DialogueTaskBase *this@<rcx>, float timeDelta@<xmm1>, hkgpIndexedMeshDefinitions::Edge *a3@<rdx>)
{
  DialogueTaskBase *v3; // rbx
  bool result; // al
  UFG::SimObjectCharacter *v5; // rcx
  UFG::ActorAudioComponent *v6; // rax
  unsigned __int16 v7; // dx
  bool v8; // zf
  float v9; // xmm6_4

  v3 = this;
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a3) )
    return 0;
  v5 = (UFG::SimObjectCharacter *)v3->mContext->mSimObject.m_pPointer;
  if ( v5 )
  {
    v7 = v5->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v5);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v5->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v5->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v5->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v5->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
  }
  else
  {
    v6 = 0i64;
  }
  if ( !v3->mContext || !v6 )
    return 0;
  v8 = (*((_BYTE *)v3 + 20) & 1) == 0;
  v9 = timeDelta + v3->m_failTimer;
  v3->m_failTimer = v9;
  if ( !v8 )
    return v9 <= 1.5;
  if ( v6->m_isSpeakingCnt > 0 && v6->m_controller.m_pEvent )
  {
    result = 1;
    if ( v9 > 10.0 )
      result = 0;
  }
  else
  {
    result = 0;
    if ( v9 > 10.0 )
      result = 0;
  }
  return result;
}

// File Line: 301
// RVA: 0x2DF020
void __fastcall DialogueTask::DialogueTask(DialogueTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<DialogueTrack>::`vftable';
  this->vfptr = (DialogueTaskBaseVtbl *)&DialogueTaskBase::`vftable';
  this->m_failTimer = 0.0;
  *((_BYTE *)&this->40 + 20) &= 0xFEu;
  this->mContext = 0i64;
  this->vfptr = (ITaskVtbl *)&DialogueTask::`vftable'{for `Task<DialogueTrack>'};
  this->vfptr = (DialogueTaskBaseVtbl *)&DialogueTask::`vftable'{for `DialogueTaskBase'};
}

// File Line: 306
// RVA: 0x2ED730
void __fastcall DialogueTask::Begin(DialogueTask *this, ActionContext *context)
{
  ActionContext *v2; // rsi
  DialogueTask *v3; // rbp
  UFG::SimObjectCharacter *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::ActorAudioComponent *v6; // rax
  UFG::ActorAudioComponent *v7; // rbx
  ITrack *v8; // rcx
  unsigned int v9; // er15
  char *v10; // rax
  const char *v11; // rdi
  float v12; // xmm6_4
  char v13; // al
  hkResourceHandle *v14; // rcx
  const char *v15; // rax
  char *v16; // rax
  UFG::qString v17; // [rsp+48h] [rbp-D0h]
  char name; // [rsp+70h] [rbp-A8h]

  v2 = context;
  v3 = this;
  this->mContext = context;
  v4 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v4);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v4->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      else
        v6 = (UFG::ActorAudioComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v4->vfptr,
                                                             UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v4->vfptr,
                                                                                                     UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v4->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    v7 = v6;
    if ( v6
      && (float)(UFG::TidoGame::sm_DlgTagCutoffDist * UFG::TidoGame::sm_DlgTagCutoffDist) > UFG::AudioEntity::Distance2ToListener(
                                                                                              (UFG::AudioEntity *)&v6->vfptr,
                                                                                              0) )
    {
      v8 = v3->m_Track;
      v9 = HIDWORD(v8[1].mMasterRate.text.mOffset);
      DialogueTrackBase::GetTag((DialogueTrackBase *)&v8[1], 1, &name);
      v10 = UFG::qStringFind(&name, "_");
      v11 = v10 ? v10 + 1 : &name;
      v12 = *(float *)&v3->m_Track[1].mResourceOwner;
      if ( UFG::qRandom(100.0, &UFG::qDefaultSeed) < v12 )
      {
        if ( UFG::TidoGame::sm_debugDialogueState )
          UFG::AudioEntity::Distance2ToListener((UFG::AudioEntity *)&v7->vfptr, 0);
        v13 = UFG::ActorAudioComponent::QueueSpeechExternalAmbient(
                v7,
                v9,
                v11,
                0i64,
                HIDWORD(v3->m_Track[1].mResourceOwner),
                0,
                0);
        *((_BYTE *)&v3->40 + 20) &= 0xFEu;
        *((_BYTE *)&v3->40 + 20) |= v13 == 0;
        if ( *((_BYTE *)&v3->40 + 20) & 1 && UFG::TidoGame::sm_debugDialogueState )
        {
          UFG::qString::qString(&v17, &customWorldMapCaption);
          v14 = (hkResourceHandle *)v2->mActionController;
          if ( v14 )
          {
            v15 = (const char *)TargetVisibleInAIDataCondition::CreateClone(v14);
            UFG::qString::Set(&v17, v15);
          }
          v16 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2->mSimObject.m_pPointer->m_Name);
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
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<DialogueTrackPOI>::`vftable';
  this->vfptr = (DialogueTaskBaseVtbl *)&DialogueTaskBase::`vftable';
  this->m_failTimer = 0.0;
  *((_BYTE *)&this->40 + 20) &= 0xFEu;
  this->mContext = 0i64;
  this->vfptr = (ITaskVtbl *)&DialogueTaskPOI::`vftable'{for `Task<DialogueTrackPOI>'};
  this->vfptr = (DialogueTaskBaseVtbl *)&DialogueTaskPOI::`vftable'{for `DialogueTaskBase'};
}

// File Line: 386
// RVA: 0x2ED940
void __fastcall DialogueTaskPOI::Begin(DialogueTaskPOI *this, ActionContext *context)
{
  ActionContext *v2; // rsi
  DialogueTaskPOI *v3; // rdi
  UFG::SimObjectCharacter *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::ActorAudioComponent *v6; // rax
  UFG::ActorAudioComponent *v7; // rbx
  int v8; // eax
  UFG::qString *v9; // rax
  float v10; // xmm6_4
  char v11; // al
  char *v12; // rdi
  char *v13; // rbx
  __int64 v14; // rax
  UFG::qString v15; // [rsp+40h] [rbp-F8h]
  __int64 v16; // [rsp+68h] [rbp-D0h]
  UFG::qString result; // [rsp+70h] [rbp-C8h]
  char name; // [rsp+A0h] [rbp-98h]

  v16 = -2i64;
  v2 = context;
  v3 = this;
  this->mContext = context;
  v4 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v4);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v4->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      else
        v6 = (UFG::ActorAudioComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v4->vfptr,
                                                             UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v4->vfptr,
                                                                                                     UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v4->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    v7 = v6;
    if ( v6 )
    {
      DialogueTrackBase::GetTag((DialogueTrackBase *)&v3->m_Track[1], 1, &name);
      UFG::qString::qString(&v15, &name);
      v8 = UFG::qString::find(&v15, "_");
      v9 = UFG::qString::Substring(&v15, &result, v8 + 1, -1);
      UFG::qString::Set(&v15, v9->mData, v9->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      v10 = *(float *)&v3->m_Track[1].mResourceOwner;
      if ( UFG::qRandom(100.0, &UFG::qDefaultSeed) < v10 )
      {
        if ( UFG::TidoGame::sm_debugDialogueState )
          UFG::AudioEntity::Distance2ToListener((UFG::AudioEntity *)&v7->vfptr, 0);
        v11 = UFG::ActorAudioComponent::QueueSpeechExternalAmbient(
                v7,
                0,
                v15.mData,
                0i64,
                HIDWORD(v3->m_Track[1].mResourceOwner),
                0,
                0);
        *((_BYTE *)&v3->40 + 20) &= 0xFEu;
        *((_BYTE *)&v3->40 + 20) |= v11 == 0;
        if ( *((_BYTE *)&v3->40 + 20) & 1 )
        {
          if ( UFG::TidoGame::sm_debugDialogueState )
          {
            v12 = v15.mData;
            v13 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2->mSimObject.m_pPointer->m_Name);
            v14 = TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)v2->mActionController);
            UFG::qPrintf("Speech failed to play on %s \n\tat node: %s\n\tcontext: %s\n", v13, v14, v12);
          }
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
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<DialogueTrackWeaponImpact>::`vftable';
  this->vfptr = (DialogueTaskBaseVtbl *)&DialogueTaskBase::`vftable';
  this->m_failTimer = 0.0;
  *((_BYTE *)&this->40 + 20) &= 0xFEu;
  this->mContext = 0i64;
  this->vfptr = (ITaskVtbl *)&DialogueTaskWeaponImpact::`vftable'{for `Task<DialogueTrackWeaponImpact>'};
  this->vfptr = (DialogueTaskBaseVtbl *)&DialogueTaskWeaponImpact::`vftable'{for `DialogueTaskBase'};
}

// File Line: 475
// RVA: 0x149ECA0
__int64 dynamic_initializer_for__qwsDTags__()
{
  UFG::qWiseSymbol::create_from_string(&qwsDTags, "d_tags");
  return atexit(dynamic_atexit_destructor_for__qwsDTags__);
}

// File Line: 480
// RVA: 0x2EDB40
void __fastcall DialogueTaskWeaponImpact::Begin(DialogueTaskWeaponImpact *this, ActionContext *context)
{
  DialogueTaskWeaponImpact *v2; // rdi
  UFG::SimObjectCharacter *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::ActorAudioComponent *v5; // rax
  UFG::ActorAudioComponent *v6; // rbx
  ITrack *v7; // r9
  signed __int64 v8; // rcx
  signed __int64 v9; // r8
  __int64 v10; // rax
  unsigned int v11; // edx
  unsigned int v12; // eax
  float v13; // xmm6_4
  UFG::DialogArgList args; // [rsp+38h] [rbp-40h]

  v2 = this;
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
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      else
        v5 = (UFG::ActorAudioComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v3->vfptr,
                                                             UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v3->vfptr,
                                                                                                     UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    v6 = v5;
    if ( v5 )
    {
      args.vfptr = (UFG::DialogArgListVtbl *)&UFG::DialogArgList::`vftable';
      UFG::qMemSet(args.m_args, 0, 0x18u);
      args.m_nArgs = 0;
      args.m_uDialogEventId = qwsDTags.mUID;
      v7 = v2->m_Track;
      v8 = 72i64;
      v9 = 3i64;
      v10 = 0i64;
      do
      {
        v11 = *(_DWORD *)((char *)&v7->vfptr + v8);
        if ( v11 && (unsigned int)v10 < 6 )
        {
          args.m_args[v10] = v11;
          v10 = args.m_nArgs++ + 1;
        }
        v8 += 4i64;
        --v9;
      }
      while ( v9 );
      v12 = DialogueTaskWeaponImpact::GetWeaponTypeFromHitRecord(v2);
      if ( v12 && args.m_nArgs < 6 )
      {
        args.m_args[args.m_nArgs] = v12;
        ++args.m_nArgs;
      }
      v13 = *(float *)&v2->m_Track[1].vfptr;
      if ( UFG::qRandom(100.0, &UFG::qDefaultSeed) < v13 )
        UFG::ActorAudioComponent::QueueSpeech(v6, &args, 0i64, HIDWORD(v2->m_Track[1].vfptr), 0, 0);
    }
  }
}

// File Line: 524
// RVA: 0x3021D0
signed __int64 __fastcall DialogueTaskWeaponImpact::GetWeaponTypeFromHitRecord(DialogueTaskWeaponImpact *this)
{
  DialogueTaskWeaponImpact *v1; // rdi
  unsigned int v2; // ebx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  unsigned int v6; // edi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  UFG::PhysicsObjectProperties *v9; // rcx
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = 0;
  v3 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[15].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      v5 = v3->m_Components.p[15].m_pComponent;
    }
    if ( v5 )
    {
      v6 = findAttackMaterialUIDForAttacker(
             v1->mContext,
             *(UFG::SimObject **)&v5[3].m_TypeUID,
             HIDWORD(v5[3].m_BoundComponentHandles.mNode.mPrev));
      if ( v6 )
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v11);
        v8 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
        v11.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, v6);
        v9 = (UFG::PhysicsObjectProperties *)v11.mData;
        if ( v11.mData )
        {
          if ( !(_S10_2 & 1) )
          {
            _S10_2 |= 1u;
            AudioAttackMaterialProperty_0.mUID = UFG::qWiseSymbolUIDFromString(
                                                   "AudioAttackMaterialProperty",
                                                   0x811C9DC5);
            _((AMD_HD3D *)AudioAttackMaterialProperty_0.mUID);
            atexit(DialogueTaskWeaponImpact::GetWeaponTypeFromHitRecord_::_11_::_dynamic_atexit_destructor_for__AudioAttackMaterialProperty__);
            v9 = (UFG::PhysicsObjectProperties *)v11.mData;
          }
          v2 = UFG::PhysicsObjectProperties::GetAudioProperty(
                 v9,
                 (UFG::qWiseSymbol *)&AudioAttackMaterialProperty_0.mUID)->mUID;
        }
        UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
        if ( v2 > 0xA6387A05 )
        {
          if ( v2 == -958795327 )
            return 3312069844i64;
          if ( v2 == -446384847 )
            return 1988215150i64;
        }
        else
        {
          switch ( v2 )
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
bool __usercall DialogueTaskWeaponImpact::Update@<al>(DialogueTaskWeaponImpact *this@<rcx>, float timeDelta@<xmm1>, hkgpIndexedMeshDefinitions::Edge *a3@<rdx>)
{
  DialogueTaskWeaponImpact *v3; // rbx
  UFG::SimObjectCharacter *v4; // rcx
  UFG::ActorAudioComponent *v5; // rax
  unsigned __int16 v6; // dx
  bool result; // al

  v3 = this;
  result = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a3) )
  {
    v4 = (UFG::SimObjectCharacter *)v3->mContext->mSimObject.m_pPointer;
    if ( v4 )
    {
      v6 = v4->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v4);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
          v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v4->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        else
          v5 = (UFG::ActorAudioComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v4->vfptr,
                                                               UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::ActorAudioComponent::_TypeUID));
      }
      else
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v4->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v5 = 0i64;
    }
    if ( v3->mContext && v5 && v5->m_isSpeakingCnt > 0 && v5->m_controller.m_pEvent )
      result = 1;
  }
  return result;
}

// File Line: 635
// RVA: 0x2EAFE0
void __fastcall ConversationTaskCreate::Begin(ConversationTaskCreate *this, ActionContext *context)
{
  ITrack *v2; // rax
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::eConversationTopic v5; // er14
  ActionContext *v6; // rsi
  UFG::qSymbol *v7; // rbp
  unsigned __int16 v8; // r8
  UFG::SimComponent *v9; // rdx
  UFG::SimComponent *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax
  UFG::qPropertySet *v13; // rcx
  UFG::qPropertySet *v14; // rax
  UFG::SimObjectGame *v15; // rcx
  unsigned __int16 v16; // dx
  UFG::SimComponent *v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rdx
  UFG::SimObjectCharacter *v20; // rbx
  UFG::AmbientConversation *v21; // rax
  UFG::AmbientConversation *v22; // rdi

  v2 = this->m_Track;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = (UFG::eConversationTopic)v2[1].vfptr;
  v6 = context;
  v7 = 0i64;
  if ( v3 )
  {
    v8 = v3->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v9 = v10;
    }
    else
    {
      v9 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v9 )
    {
      v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v9[1].m_Flags + 34i64)
                      + *(_QWORD *)&v9[1].m_TypeUID
                      + 40);
      if ( v11 )
      {
        v12 = *(_QWORD *)(v11 + 80);
        if ( v12 )
        {
          v13 = *(UFG::qPropertySet **)(v12 + 144);
          if ( v13 )
          {
LABEL_19:
            v14 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                    v13,
                    (UFG::qSymbol *)&qSymbolX_propset_componentPOI.mUID,
                    DEPTH_RECURSE);
            v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
                   v14,
                   (UFG::qSymbol *)&qSymbol_ConversationTopic.mUID,
                   DEPTH_RECURSE);
            goto LABEL_20;
          }
          v13 = *(UFG::qPropertySet **)(v12 + 152);
        }
        else
        {
          v13 = 0i64;
        }
        if ( !v13 )
          goto LABEL_20;
        goto LABEL_19;
      }
    }
  }
LABEL_20:
  v15 = (UFG::SimObjectGame *)v6->mSimObject.m_pPointer;
  if ( v15 )
  {
    v16 = v15->m_Flags;
    if ( (v16 >> 14) & 1 )
    {
      v4 = v15->m_Components.p[20].m_pComponent;
    }
    else if ( (v16 & 0x8000u) == 0 )
    {
      if ( (v16 >> 13) & 1 )
      {
        v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v16 >> 12) & 1 )
      {
        v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v17 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v15->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v4 = v17;
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
    if ( !v20 && v5 == 23 )
      v20 = LocalPlayer;
  }
  v21 = UFG::ConversationManager::AddAmbientConversation(v6->mSimObject.m_pPointer->mNode.mUID);
  v22 = v21;
  if ( v21 )
  {
    if ( v7 )
      v21->m_topic = UFG::Conversation::LookupTopic(v7);
    else
      v21->m_topic = v5;
    UFG::AmbientConversation::SetupLines(v22, v6->mSimObject.m_pPointer, (UFG::SimObject *)&v20->vfptr);
  }
}    v21->m_topic = v5;
    UFG::AmbientConversation

// File Line: 699
// RVA: 0x2EAF50
void __fastcall ConversationTaskCleanup::Begin(ConversationTaskCleanup *this, ActionContext *context)
{
  UFG::SimObjectCharacter *v2; // rcx
  UFG::ActorAudioComponent *v3; // rax
  unsigned __int16 v4; // dx
  UFG::Conversation *v5; // rax
  _BOOL8 v6; // rdx

  v2 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v3 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v3 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
  }
  else
  {
    v3 = 0i64;
  }
  v5 = UFG::ActorAudioComponent::GetActiveAmbientConversation(v3);
  if ( v5 )
    UFG::Conversation::ForceFinish(v5, v6);
}

// File Line: 721
// RVA: 0x2EB200
void __fastcall ConversationTaskOperation::Begin(ConversationTaskOperation *this, ActionContext *context)
{
  int v2; // ecx
  UFG::SimObjectCharacter *v3; // rcx
  UFG::ActorAudioComponent *v4; // rax
  unsigned __int16 v5; // dx
  UFG::Conversation *v6; // rax
  UFG::SimObjectCharacter *v7; // rcx
  UFG::ActorAudioComponent *v8; // rax
  unsigned __int16 v9; // dx
  UFG::Conversation *v10; // rax

  v2 = (int)this->m_Track[1].vfptr;
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      v7 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
      if ( v7 )
      {
        v9 = v7->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v8 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v7);
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
            v8 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v7->vfptr,
                                               UFG::ActorAudioComponent::_TypeUID);
          else
            v8 = (UFG::ActorAudioComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v7->vfptr,
                                                                 UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::ActorAudioComponent::_TypeUID));
        }
        else
        {
          v8 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v7->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
      }
      else
      {
        v8 = 0i64;
      }
      v10 = UFG::ActorAudioComponent::GetActiveAmbientConversation(v8);
      if ( v10 )
      {
        if ( v10->m_type == 1 )
          UFG::Conversation::Stop(v10, 0);
      }
    }
  }
  else
  {
    v3 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
        else
        {
          v4 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v3->vfptr,
                                             UFG::ActorAudioComponent::_TypeUID);
        }
      }
      else
      {
        v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v4 = 0i64;
    }
    v6 = UFG::ActorAudioComponent::GetActiveAmbientConversation(v4);
    if ( v6 )
    {
      if ( v6->m_type == 1 )
        UFG::Conversation::Start(v6);
    }
  }
}

