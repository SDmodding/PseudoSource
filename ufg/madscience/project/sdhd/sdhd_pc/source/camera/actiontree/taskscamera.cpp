// File Line: 36
// RVA: 0x2E9E00
void __fastcall CameraChangeTask::Begin(CameraChangeTask *this, ActionContext *context)
{
  ActionContext *v2; // rsi
  CameraChangeTask *v3; // rbx
  UFG::GameCameraComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  ITrack *v6; // rax
  UFG::allocator::free_link *v7; // rax

  v2 = context;
  v3 = this;
  v4 = UFG::GetCurrentGameCamera();
  v5 = (UFG::SimComponent *)&v4->vfptr;
  if ( v4
    && (!UFG::SimComponent::IsType(
           (UFG::SimComponent *)&v4->vfptr,
           UFG::FollowCameraComponent::_FollowCameraComponentTypeUID)
     || LOBYTE(v3->m_Track[1].vfptr))
    && (!UFG::SimComponent::IsType(v5, UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID)
     || LOBYTE(v3->m_Track[1].vfptr) != 1) )
  {
    v6 = v3->m_Track;
    if ( LOBYTE(v6[1].vfptr) )
    {
      if ( LOBYTE(v6[1].vfptr) != 1 )
        return;
      v7 = UFG::qMalloc(0x50ui64, "CameraChangeTask", 0i64);
      if ( v7 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v7, "EVT_MOUNT_VEHICLE_CAMERA", &v2->mSimObject);
    }
    else
    {
      v7 = UFG::qMalloc(0x50ui64, "CameraChangeTask", 0i64);
      if ( v7 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v7, "EVT_DISMOUNT_VEHICLE_CAMERA", &v2->mSimObject);
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v7);
  }
}

// File Line: 68
// RVA: 0x2EA680
void __fastcall CameraShakeTask::Begin(CameraShakeTask *this, ActionContext *context)
{
  ActionContext *v2; // rdi
  CameraShakeTask *v3; // rsi
  UFG::GameCameraComponent *v4; // rbx
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // r9
  UFG::SimComponent *v7; // rax
  __int64 v8; // rax

  v2 = context;
  v3 = this;
  v4 = UFG::GetCurrentGameCamera();
  if ( v4 )
  {
    v5 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::GunComponent::_TypeUID);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::GunComponent::_TypeUID);
        else
          v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::GunComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::GunComponent::_TypeUID);
      }
      if ( v7 )
      {
        v8 = ((__int64 (__fastcall *)(UFG::GameCameraComponent *))v4->vfptr[41].__vecDelDtor)(v4);
        if ( !v8
          || *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v8 + 96) + 25i64) + *(_QWORD *)(v8 + 88) + 40) != v2->mSimObject.m_pPointer )
        {
          return;
        }
LABEL_20:
        UFG::GameCameraComponent::AddShakeAmplitude(v4, *(float *)&v3->m_Track[1].vfptr);
        return;
      }
    }
    if ( !BYTE4(v3->m_Track[1].vfptr)
      || UFG::IsAnyLocalPlayer(v2->mSimObject.m_pPointer)
      || !UFG::SimComponent::IsType(
            (UFG::SimComponent *)&v4->vfptr,
            UFG::FollowCameraComponent::_FollowCameraComponentTypeUID)
      && !UFG::SimComponent::IsType(
            (UFG::SimComponent *)&v4->vfptr,
            UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID) )
    {
      goto LABEL_20;
    }
  }
}

// File Line: 102
// RVA: 0x2EA550
void __fastcall CameraResetTask::Begin(CameraResetTask *this, ActionContext *context)
{
  CameraResetTask *v2; // rdi
  char v3; // bl
  char v4; // bp
  UFG::GameCameraComponent *v5; // rax
  UFG::SimComponent *v6; // rsi
  UFG::SimObject *v7; // rcx
  UFG::SimComponent *v8; // rax
  UFG::SimObject *v9; // rcx
  UFG::SimComponent *v10; // rax

  v2 = this;
  if ( UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer) )
  {
    v3 = 0;
    v4 = 0;
    if ( BYTE2(v2->m_Track[1].vfptr) )
    {
      v5 = UFG::GetCurrentGameCamera();
      v6 = (UFG::SimComponent *)&v5->vfptr;
      if ( v5 )
      {
        if ( UFG::SimComponent::IsType(
               (UFG::SimComponent *)&v5->vfptr,
               UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID) )
        {
          v4 = 1;
        }
        else
        {
          v3 = 0;
          if ( UFG::SimComponent::IsType(v6, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID) )
            v3 = 1;
        }
      }
    }
    if ( LOBYTE(v2->m_Track[1].vfptr) || v4 )
    {
      v7 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
      if ( v7 )
      {
        v8 = UFG::SimObject::GetComponentOfType(v7, UFG::ChaseCameraComponent::_TypeUID);
        if ( v8 )
          ((void (__fastcall *)(UFG::SimComponent *))v8->vfptr[14].__vecDelDtor)(v8);
      }
    }
    if ( BYTE1(v2->m_Track[1].vfptr) || v3 )
    {
      v9 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
      if ( v9 )
      {
        v10 = UFG::SimObject::GetComponentOfType(v9, UFG::FollowCameraComponent::_TypeUID);
        if ( v10 )
          ((void (__fastcall *)(UFG::SimComponent *))v10->vfptr[14].__vecDelDtor)(v10);
      }
    }
  }
}

// File Line: 135
// RVA: 0x2EA4D0
void __fastcall CameraRecoilTask::Begin(CameraRecoilTask *this, ActionContext *context)
{
  ActionContext *v2; // rdi
  CameraRecoilTask *v3; // rsi
  UFG::GameCameraComponent *v4; // rax
  UFG::GameCameraComponent *v5; // rbx
  __int64 v6; // rax
  unsigned int *v7; // rax
  __int128 v8; // xmm3
  __int128 v9; // xmm2
  __int128 v10; // xmm1

  v2 = context;
  v3 = this;
  v4 = UFG::GetCurrentGameCamera();
  v5 = v4;
  if ( v4 )
  {
    v6 = ((__int64 (__fastcall *)(UFG::GameCameraComponent *))v4->vfptr[41].__vecDelDtor)(v4);
    if ( v6 )
    {
      if ( *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v6 + 96) + 25i64) + *(_QWORD *)(v6 + 88) + 40) == v2->mSimObject.m_pPointer )
      {
        v7 = (unsigned int *)v3->m_Track;
        v8 = v7[16];
        v9 = v7[15];
        v10 = v7[14];
        ((void (__fastcall *)(UFG::GameCameraComponent *))v5->vfptr[40].__vecDelDtor)(v5);
      }
    }
  }
}

// File Line: 149
// RVA: 0x2E9F10
void __fastcall CameraCollisionGotoAngleTask::Begin(CameraCollisionGotoAngleTask *this, ActionContext *context)
{
  CameraCollisionGotoAngleTask *v2; // rdi
  UFG::GameCameraComponent *v3; // rax
  UFG::FollowCameraComponent *v4; // rbx
  bool v5; // al
  UFG::FollowCameraComponent *v6; // rcx

  v2 = this;
  v3 = UFG::GetCurrentGameCamera();
  v4 = (UFG::FollowCameraComponent *)v3;
  if ( v3 )
  {
    v5 = UFG::SimComponent::IsType(
           (UFG::SimComponent *)&v3->vfptr,
           UFG::FollowCameraComponent::_FollowCameraComponentTypeUID);
    v6 = 0i64;
    if ( v5 )
      v6 = v4;
    if ( v6 )
      UFG::FollowCameraComponent::GotoAngleCollisionQueue(v6, *(float *)&v2->m_Track[1].vfptr);
  }
}

// File Line: 163
// RVA: 0x2E9F60
void __fastcall CameraConstrainYawTask::Begin(CameraConstrainYawTask *this, ActionContext *context)
{
  CameraConstrainYawTask *v2; // rbx
  bool v3; // al
  UFG::SimObject *v4; // rcx
  UFG::SimComponent *v5; // rax
  float *v6; // rcx
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm4_4

  v2 = this;
  v3 = UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer);
  v2->mLocalPlayer = v3;
  if ( v3 )
  {
    v4 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
    if ( v4 )
    {
      v5 = UFG::SimObject::GetComponentOfType(v4, UFG::FollowCameraComponent::_TypeUID);
      if ( v5 )
      {
        v6 = (float *)v2->m_Track;
        v7 = v6[14];
        v8 = v6[15];
        v9 = v6[16];
        LOBYTE(v5[128].m_BoundComponentHandles.mNode.mPrev) = 1;
        *((float *)&v5[128].m_BoundComponentHandles.mNode.mPrev + 1) = (float)(v7 * 3.1415927) * 0.0055555557;
        *(float *)&v5[128].m_BoundComponentHandles.mNode.mNext = (float)(v8 * 3.1415927) * 0.0055555557;
        *((float *)&v5[128].m_BoundComponentHandles.mNode.mNext + 1) = (float)(v9 * 3.1415927) * 0.0055555557;
      }
    }
  }
}

// File Line: 182
// RVA: 0x2FE380
void __fastcall CameraConstrainYawTask::End(CameraConstrainYawTask *this)
{
  UFG::SimObject *v1; // rcx
  UFG::SimComponent *v2; // rax

  if ( this->mLocalPlayer )
  {
    v1 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
    if ( v1 )
    {
      v2 = UFG::SimObject::GetComponentOfType(v1, UFG::FollowCameraComponent::_TypeUID);
      if ( v2 )
        LOBYTE(v2[128].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
  }
}

// File Line: 196
// RVA: 0x2EA470
void __fastcall CameraIgnoreCollisionTask::Begin(CameraIgnoreCollisionTask *this, ActionContext *context)
{
  CameraIgnoreCollisionTask *v2; // rbx
  bool v3; // al
  ITrack *v4; // rax
  bool v5; // dl

  v2 = this;
  v3 = UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer);
  v2->mLocalPlayer = v3;
  if ( v3 )
  {
    v4 = v2->m_Track;
    v5 = LOBYTE(v4[1].vfptr) != 0;
    v2->mIgnoreCharacters = v5;
    v2->mIgnoreVehicles = BYTE1(v4[1].vfptr) != 0;
    if ( v5 )
      UFG::GameCameraComponent::SetCollisionIgnoreCharacters(1);
    if ( v2->mIgnoreVehicles )
      UFG::GameCameraComponent::SetCollisionIgnoreVehicles(1);
  }
}

// File Line: 215
// RVA: 0x2FE3D0
void __fastcall CameraIgnoreCollisionTask::End(CameraIgnoreCollisionTask *this)
{
  CameraIgnoreCollisionTask *v1; // rbx

  v1 = this;
  if ( this->mLocalPlayer )
  {
    if ( this->mIgnoreCharacters )
      UFG::GameCameraComponent::SetCollisionIgnoreCharacters(0);
    if ( v1->mIgnoreVehicles )
      UFG::GameCameraComponent::SetCollisionIgnoreVehicles(0);
  }
}

// File Line: 232
// RVA: 0x2DE220
void __fastcall CameraAnimationTask::CameraAnimationTask(CameraAnimationTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AnimatedCameraComponent> *v5; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::GameCameraComponent> *v6; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CameraAnimationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CameraAnimationTask::`vftable;
  v2 = &this->mController;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mController.m_pPointer = 0i64;
  v5 = &this->mAnimatedCameraComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->mAnimatedCameraComponent.m_pPointer = 0i64;
  v6 = &this->mPreviousCameraComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->mPreviousCameraComponent.m_pPointer = 0i64;
  if ( this->mController.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
}

// File Line: 237
// RVA: 0x2E9A70
void __fastcall CameraAnimationTask::Begin(CameraAnimationTask *this, ActionContext *context)
{
  ITrack *v2; // rdi
  ActionContext *v3; // rsi
  CameraAnimationTask *v4; // rbx
  UFG::SimObject *v5; // rcx
  UFG::SimComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AnimatedCameraComponent> *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::GameCameraComponent *v12; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::GameCameraComponent> *v13; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::SimObjectCharacter *v18; // rdx
  bool v19; // al
  float *v20; // rax
  AnimationNode *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v22; // rdx
  UFG::qSafePointer<AnimationNode,AnimationNode> *v23; // r8
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qList<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList,1,0> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v26; // rax
  AnimationNode *v27; // rcx
  UFG::SimObjectGame *v28; // rcx
  unsigned __int16 v29; // dx
  UFG::SimComponent *v30; // rax
  Creature *v31; // rdi
  NISManager *v32; // rax

  v2 = this->m_Track;
  v3 = context;
  v4 = this;
  this->mContext = context;
  v5 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v5 )
    v6 = UFG::SimObject::GetComponentOfType(v5, UFG::AnimatedCameraComponent::_TypeUID);
  else
    v6 = 0i64;
  v7 = &v4->mAnimatedCameraComponent;
  if ( v4->mAnimatedCameraComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v4->mAnimatedCameraComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v4->mAnimatedCameraComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mAnimatedCameraComponent.mPrev;
  }
  v4->mAnimatedCameraComponent.m_pPointer = v6;
  if ( v6 )
  {
    v10 = &v6->m_SafePointerList;
    v11 = v6->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v11;
    v4->mAnimatedCameraComponent.mNext = &v10->mNode;
    v10->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  if ( v4->mAnimatedCameraComponent.m_pPointer )
  {
    v12 = UFG::GetCurrentGameCamera();
    v13 = &v4->mPreviousCameraComponent;
    if ( v4->mPreviousCameraComponent.m_pPointer )
    {
      v14 = v13->mPrev;
      v15 = v4->mPreviousCameraComponent.mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v4->mPreviousCameraComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPreviousCameraComponent.mPrev;
    }
    v4->mPreviousCameraComponent.m_pPointer = (UFG::SimComponent *)&v12->vfptr;
    if ( v12 )
    {
      v16 = &v12->m_SafePointerList;
      v17 = v12->m_SafePointerList.mNode.mPrev;
      v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v13->mPrev = v17;
      v4->mPreviousCameraComponent.mNext = &v16->mNode;
      v16->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    }
    v18 = (UFG::SimObjectCharacter *)v3->mSimObject.m_pPointer;
    LODWORD(v4->mAnimatedCameraComponent.m_pPointer[22].vfptr) = HIDWORD(v4->m_Track[1].mResourceOwner);
    if ( !v18 )
      v18 = LocalPlayer;
    ((void (__fastcall *)(UFG::SimComponent *, UFG::SimObjectCharacter *, UFG::qSafePointer<UFG::SimComponent,UFG::GameCameraComponent> *))v4->mAnimatedCameraComponent.m_pPointer->vfptr[16].__vecDelDtor)(
      v4->mAnimatedCameraComponent.m_pPointer,
      v18,
      v13);
    LOBYTE(v4->mAnimatedCameraComponent.m_pPointer[22].m_SafePointerList.mNode.mNext) = BYTE5(v4->m_Track[2].mResourceOwner) != 0;
    BYTE1(v4->mAnimatedCameraComponent.m_pPointer[22].m_SafePointerList.mNode.mNext) = LOBYTE(v4->m_Track[2].m_TrackClassNameUID) != 0;
    BYTE2(v4->mAnimatedCameraComponent.m_pPointer[22].m_SafePointerList.mNode.mNext) = BYTE1(v4->m_Track[2].m_TrackClassNameUID) != 0;
    BYTE3(v4->mAnimatedCameraComponent.m_pPointer[22].m_SafePointerList.mNode.mNext) = BYTE2(v4->m_Track[2].m_TrackClassNameUID) != 0;
    BYTE4(v4->mAnimatedCameraComponent.m_pPointer[22].m_SafePointerList.mNode.mNext) = HIBYTE(v4->m_Track[2].mResourceOwner) != 0;
    if ( v4->m_Track[2].mDisable )
      goto LABEL_20;
    if ( UFG::Metrics::msInstance.mSimTimeScaleMax <= 1.0 )
    {
      UFG::Metrics::msInstance.mSimTimeScaleInGame = UFG::Metrics::msInstance.mSimTimeScaleMax;
      if ( UFG::Metrics::msInstance.mSimTimeScaleMax == 0.0 )
      {
        v19 = 1;
        goto LABEL_19;
      }
    }
    else
    {
      UFG::Metrics::msInstance.mSimTimeScaleInGame = 1.0;
    }
    v19 = 0;
LABEL_19:
    UFG::Metrics::msInstance.mSimPausedInGame = v19;
    UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
    bRestrictSimTimeScaleChange = 1;
LABEL_20:
    v20 = (float *)v4->m_Track;
    UFG::AnimatedCameraComponent::SetDofParameters(
      (UFG::AnimatedCameraComponent *)v4->mAnimatedCameraComponent.m_pPointer,
      v20[18],
      v20[19],
      v20[21],
      v20[20],
      v20[23],
      v20[22]);
    UFG::AttachCameraToView((UFG::BaseCameraComponent *)v4->mAnimatedCameraComponent.m_pPointer);
    v21 = UFG::AnimatedCameraComponent::Play(
            (UFG::AnimatedCameraComponent *)v4->mAnimatedCameraComponent.m_pPointer,
            (UFG::qSymbolUC *)&v2[2].mResourceOwner,
            *((float *)&v4->m_Track[1].vfptr + 1));
    v23 = &v4->mController;
    if ( v4->mController.m_pPointer )
    {
      v22 = v23->mPrev;
      v24 = v4->mController.mNext;
      v22->mNext = v24;
      v24->mPrev = v22;
      v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v23->mPrev;
      v4->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v4->mController.mPrev;
    }
    v4->mController.m_pPointer = v21;
    if ( v21 )
    {
      v25 = &v21->m_SafePointerList;
      v26 = v21->m_SafePointerList.mNode.mPrev;
      v26->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v23->mPrev;
      v23->mPrev = v26;
      v4->mController.mNext = &v25->mNode;
      v25->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v23->mPrev;
    }
    v27 = v4->mController.m_pPointer;
    if ( v27 )
    {
      LOBYTE(v22) = BYTE4(v4->m_Track[2].mResourceOwner) != 0;
      v27->vfptr[3].__vecDelDtor((Expression::IMemberMap *)&v27->vfptr, (unsigned int)v22);
      v4->mController.m_pPointer->vfptr[2].FindWithOldPath(
        (Expression::IMemberMap *)v4->mController.m_pPointer,
        (const char *)LOBYTE(v4->m_Track[1].vfptr));
      ((void (__fastcall *)(AnimationNode *, ActionContext *))v4->mController.m_pPointer->vfptr[2].GetResourceOwner)(
        v4->mController.m_pPointer,
        v4->mContext);
    }
    LOBYTE(v23) = 1;
    ((void (__fastcall *)(AnimationNode *, UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *, UFG::qSafePointer<AnimationNode,AnimationNode> *))v4->mController.m_pPointer->vfptr[1].GetClassNameUID)(
      v4->mController.m_pPointer,
      v22,
      v23);
    v28 = (UFG::SimObjectGame *)v4->mAnimatedCameraComponent.m_pPointer->m_pSimObject;
    if ( v28 )
    {
      v29 = v28->m_Flags;
      if ( (v29 >> 14) & 1 )
      {
        v30 = v28->m_Components.p[9].m_pComponent;
      }
      else if ( (v29 & 0x8000u) == 0 )
      {
        if ( (v29 >> 13) & 1 )
          v30 = v28->m_Components.p[8].m_pComponent;
        else
          v30 = (v29 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::BaseAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v28->vfptr, UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        v30 = v28->m_Components.p[9].m_pComponent;
      }
      if ( v30 )
      {
        v31 = *(Creature **)&v30[2].m_TypeUID;
        if ( v31 )
        {
          Creature::Update(*(Creature **)&v30[2].m_TypeUID, 0.0);
          Creature::UpdateTransforms(v31);
        }
        ((void (*)(void))v4->mAnimatedCameraComponent.m_pPointer->vfptr[15].__vecDelDtor)();
      }
    }
  }
  v32 = NISManager::GetInstance();
  NISManager::OnCameraAttached(v32, v4);
}

// File Line: 298
// RVA: 0x303DE0
bool __fastcall CameraAnimationTask::Update(CameraAnimationTask *this, float timeDelta)
{
  CameraAnimationTask *v2; // rbx
  bool v3; // al
  AnimationNode *v4; // rcx
  int v5; // edi

  v2 = this;
  if ( !this->m_Track[2].mDisable )
  {
    if ( UFG::Metrics::msInstance.mSimTimeScaleMax <= 1.0 )
    {
      UFG::Metrics::msInstance.mSimTimeScaleInGame = UFG::Metrics::msInstance.mSimTimeScaleMax;
      if ( UFG::Metrics::msInstance.mSimTimeScaleMax == 0.0 )
      {
        v3 = 1;
        goto LABEL_5;
      }
    }
    else
    {
      UFG::Metrics::msInstance.mSimTimeScaleInGame = 1.0;
    }
    v3 = 0;
LABEL_5:
    UFG::Metrics::msInstance.mSimPausedInGame = v3;
    UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
  }
  v4 = this->mController.m_pPointer;
  if ( !v4 )
    return 0;
  v5 = LOBYTE(v2->m_Track[1].vfptr);
  if ( v5 == 1 || v5 == 6 || !((unsigned __int8 (*)(void))v4->vfptr[1].SetResourceOwner)() )
    return 1;
  ((void (*)(void))v2->mController.m_pPointer->vfptr[1].GetResourceOwner)();
  return v5 == 2;
}

// File Line: 337
// RVA: 0x2FE1B0
void __fastcall CameraAnimationTask::End(CameraAnimationTask *this)
{
  CameraAnimationTrack *v1; // rbx
  CameraAnimationTask *v2; // rdi
  NISManager *v3; // rax
  UFG::SimComponent *v4; // rcx
  UFG::FollowCameraComponent *v5; // rbx
  ITrack *v6; // rax
  bool withVelocity; // si
  float v8; // xmm6_4
  float v9; // xmm7_4
  float orientRateMin; // xmm8_4
  float orientRateMax; // xmm9_4
  UFG::SimComponent *v12; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v14; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v16; // rax

  bRestrictSimTimeScaleChange = 0;
  v1 = (CameraAnimationTrack *)this->m_Track;
  v2 = this;
  v3 = NISManager::GetInstance();
  NISManager::OnCameraDetached(v3, v1);
  v4 = v2->mPreviousCameraComponent.m_pPointer;
  if ( v4 )
  {
    if ( UFG::SimComponent::IsType(v4, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID) )
      v5 = (UFG::FollowCameraComponent *)v2->mPreviousCameraComponent.m_pPointer;
    else
      v5 = 0i64;
    UFG::AttachCameraToView((UFG::BaseCameraComponent *)v2->mPreviousCameraComponent.m_pPointer);
    ((void (*)(void))v2->mPreviousCameraComponent.m_pPointer->vfptr[14].__vecDelDtor)();
    if ( v5 )
      UFG::FollowCameraComponent::UpdateLocalWorld(v5, 0.0);
    v6 = v2->m_Track;
    if ( BYTE6(v6[2].mResourceOwner) )
    {
      withVelocity = HIBYTE(v6[2].m_TrackClassNameUID) != 0;
      if ( v5 )
      {
        v8 = v6[1].mMasterRate.value;
        v9 = *(&v6[1].mMasterRate.value + 1);
        orientRateMin = v6[1].mTimeBegin;
        orientRateMax = v6[1].mTimeEnd;
        if ( v6[2].mBreakPoint )
        {
          UFG::FollowCameraComponent::GotoAngleSnap(v5, (float)(*(float *)&v6[2].vfptr * 3.1415927) * 0.0055555557, 1);
          UFG::FollowCameraComponent::GotoRiseSnap(v5, *((float *)&v2->m_Track[2].vfptr + 1));
        }
        UFG::FollowCameraComponent::TransitionFromBlendOrientation(
          v5,
          (UFG::BaseCameraComponent *)v2->mAnimatedCameraComponent.m_pPointer,
          v8,
          v9,
          orientRateMin,
          orientRateMax,
          withVelocity);
      }
      else
      {
        ((void (__fastcall *)(UFG::SimComponent *, UFG::SimComponent *, bool))v2->mPreviousCameraComponent.m_pPointer->vfptr[29].__vecDelDtor)(
          v2->mPreviousCameraComponent.m_pPointer,
          v2->mAnimatedCameraComponent.m_pPointer,
          withVelocity);
      }
    }
    ((void (*)(void))v2->mPreviousCameraComponent.m_pPointer->vfptr[15].__vecDelDtor)();
  }
  v12 = v2->mAnimatedCameraComponent.m_pPointer;
  if ( v12 )
  {
    v13 = v12[23].m_SafePointerList.mNode.mPrev;
    if ( v13 )
      ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, signed __int64))v13->mPrev->mNext)(
        v13,
        1i64);
    v14 = &v12[22].m_BoundComponentHandles.mNode.mNext;
    if ( v12[23].m_SafePointerList.mNode.mPrev )
    {
      v15 = *v14;
      v16 = v12[23].vfptr;
      v15->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v16;
      v16->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v15;
      *v14 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v14;
      v12[23].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&v12[22].m_BoundComponentHandles.mNode.mNext;
    }
    v12[23].m_SafePointerList.mNode.mPrev = 0i64;
  }
}

// File Line: 380
// RVA: 0x2F5730
void __fastcall SubjectSprintTask::Begin(SubjectSprintTask *this, ActionContext *context)
{
  SubjectSprintTask *v2; // rbx
  UFG::SimObjectCharacter *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterSubjectComponent *v5; // rax

  v2 = this;
  v3 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::CharacterSubjectComponent::_TypeUID);
    }
    if ( v5 )
      v5->mSprinting = LOBYTE(v2->m_Track[1].vfptr) != 0;
  }
}

// File Line: 386
// RVA: 0x2F4D30
void __fastcall SubjectElevationTask::Begin(SubjectElevationTask *this, ActionContext *context)
{
  SubjectElevationTask *v2; // rbx
  UFG::SimObjectCharacter *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterSubjectComponent *v5; // rax

  v2 = this;
  v3 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::CharacterSubjectComponent::_TypeUID);
    }
    if ( v5 )
      UFG::CharacterSubjectComponent::SetElevationLock(v5, LOBYTE(v2->m_Track[1].vfptr) != 0);
  }
}

// File Line: 393
// RVA: 0x2F4DD0
void __fastcall SubjectFallingAttackTask::Begin(SubjectFallingAttackTask *this, ActionContext *context)
{
  SubjectFallingAttackTask *v2; // rbx
  UFG::SimObjectCharacter *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterSubjectComponent *v5; // rax

  v2 = this;
  v3 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::CharacterSubjectComponent::_TypeUID);
    }
    if ( v5 )
      v5->mFallingAttack = LOBYTE(v2->m_Track[1].vfptr) != 0;
  }
}

// File Line: 400
// RVA: 0x2EA000
void __fastcall CameraDOFTask::Begin(CameraDOFTask *this, ActionContext *context)
{
  UFG::GameCameraComponent::BeginDOFOverride(
    *(float *)&this->m_Track[1].vfptr,
    *((float *)&this->m_Track[1].vfptr + 1),
    *(float *)&this->m_Track[1].mResourceOwner,
    *((float *)&this->m_Track[1].mResourceOwner + 1),
    *(float *)&this->m_Track[1].m_TrackClassNameUID,
    DOFOverridePriority_1);
}

// File Line: 412
// RVA: 0x2FE3C0
void __fastcall CameraDOFTask::End(CameraDOFTask *this)
{
  UFG::GameCameraComponent::EndDOFOverride(DOFOverridePriority_1);
}

// File Line: 421
// RVA: 0x2F54F0
void __fastcall SubjectFollowOverrideTask::Begin(SubjectFollowOverrideTask *this, ActionContext *context)
{
  ActionContext *v2; // rbp
  SubjectFollowOverrideTask *v3; // rsi
  int v4; // ebx
  bool v5; // r14
  bool v6; // al
  ITrack *v7; // rcx
  const char *v8; // r8
  UFG::SimObjectCharacter *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::CharacterSubjectComponent *v11; // rax
  UFG::CharacterSubjectComponent *v12; // rdi
  ITrack *v13; // rax
  UFG::qSymbol v14; // eax
  UFG::qSymbol v15; // eax
  UFG::qSymbol v16; // eax
  UFG::qString result; // [rsp+38h] [rbp-50h]
  UFG::qSymbol v18; // [rsp+90h] [rbp+8h]
  UFG::qSymbol v19; // [rsp+A0h] [rbp+18h]
  UFG::qSymbol *v20; // [rsp+A8h] [rbp+20h]

  v2 = context;
  v3 = this;
  v4 = 0;
  this->mActionContext = 0i64;
  this->mUniqueID = -1;
  v5 = BYTE5(this->m_Track[1].mResourceOwner) != 0;
  v6 = UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer);
  if ( v5 )
  {
    if ( !v6 )
      return;
  }
  else if ( v6 )
  {
    return;
  }
  v7 = v3->m_Track + 1;
  v8 = (char *)v7 + ((_QWORD)v7->vfptr & 0xFFFFFFFFFFFFFFFEui64);
  if ( !((_QWORD)v7->vfptr & 0xFFFFFFFFFFFFFFFEui64) )
    v8 = BinString::sEmptyString;
  UFG::qString::FormatEx(&result, "Cameras-%s", v8);
  if ( UFG::IsAnyLocalPlayer(v2->mSimObject.m_pPointer) )
    v9 = (UFG::SimObjectCharacter *)v2->mSimObject.m_pPointer;
  else
    v9 = UFG::GetLocalPlayer();
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v9);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
        v11 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v9->vfptr,
                                                  UFG::CharacterSubjectComponent::_TypeUID);
      else
        v11 = (UFG::CharacterSubjectComponent *)((v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v9->vfptr,
                                                                     UFG::CharacterSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::CharacterSubjectComponent::_TypeUID));
    }
    else
    {
      v11 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v9->vfptr,
                                                UFG::CharacterSubjectComponent::_TypeUID);
    }
    v12 = v11;
    if ( v11 )
    {
      v3->mActionContext = v2;
      v3->mUniqueID = SubjectFollowOverrideTask::gUniqueIDNext++;
      v13 = v3->m_Track;
      if ( BYTE4(v13[1].mResourceOwner) )
      {
        v12->mTypeOverrideFreeman = (int)v13[1].mResourceOwner;
        do
        {
          if ( v5 )
          {
            v20 = &v18;
            v14.mUID = (unsigned int)UFG::qSymbol::create_from_string(&v18, result.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(v12, v2, v4, v14, v3->mUniqueID);
          }
          else
          {
            v20 = &v19;
            v15.mUID = (unsigned int)UFG::qSymbol::create_from_string(&v19, result.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanNPC(v12, v2, v4, v15, v3->mUniqueID);
          }
          ++v4;
        }
        while ( v4 < 4 );
      }
      else
      {
        *(_QWORD *)&v19.mUID = &v18;
        v16.mUID = (unsigned int)UFG::qSymbol::create_from_string(&v18, result.mData);
        if ( v5 )
          UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(
            v12,
            v2,
            (int)v3->m_Track[1].mResourceOwner,
            v16,
            v3->mUniqueID);
        else
          UFG::CharacterSubjectComponent::SetContextOverrideFreemanNPC(
            v12,
            v2,
            (int)v3->m_Track[1].mResourceOwner,
            v16,
            v3->mUniqueID);
      }
    }
  }
  UFG::qString::~qString(&result);
}

// File Line: 462
// RVA: 0x300720
void __fastcall SubjectFollowOverrideTask::End(SubjectFollowOverrideTask *this)
{
  SubjectFollowOverrideTask *v1; // rbx
  ActionContext *v2; // rcx
  bool v3; // r14
  bool v4; // al
  UFG::SimObjectCharacter *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::CharacterSubjectComponent *v7; // rax
  UFG::CharacterSubjectComponent *v8; // rdi
  unsigned int v9; // esi
  char v10; // bp
  ITrack *v11; // rax
  int v12; // ebx
  UFG::qSymbol v13; // eax
  UFG::qSymbol v14; // eax
  int v15; // edx
  UFG::qSymbol v16; // eax
  UFG::qSymbol v17; // eax
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+8h]
  UFG::qWiseSymbol v19; // [rsp+78h] [rbp+10h]
  UFG::qWiseSymbol *v20; // [rsp+80h] [rbp+18h]

  v1 = this;
  v2 = this->mActionContext;
  if ( v2 )
  {
    v3 = BYTE5(v1->m_Track[1].mResourceOwner) != 0;
    v4 = UFG::IsAnyLocalPlayer(v2->mSimObject.m_pPointer);
    if ( v3 )
    {
      if ( !v4 )
        return;
    }
    else if ( v4 )
    {
      return;
    }
    v5 = (UFG::SimObjectCharacter *)(UFG::IsAnyLocalPlayer(v1->mActionContext->mSimObject.m_pPointer) ? v1->mActionContext->mSimObject.m_pPointer : UFG::GetLocalPlayer());
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v5);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
          v7 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v5->vfptr,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
        else
          v7 = (UFG::CharacterSubjectComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v5->vfptr,
                                                                     UFG::CharacterSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CharacterSubjectComponent::_TypeUID));
      }
      else
      {
        v7 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v5->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
      v8 = v7;
      if ( v7 )
      {
        v9 = v1->mUniqueID;
        v10 = 0;
        v11 = v1->m_Track;
        if ( BYTE4(v11[1].mResourceOwner) )
        {
          v12 = 0;
          while ( 1 )
          {
            if ( v3 )
            {
              if ( UFG::CharacterSubjectComponent::GetContextOverrideFreemanPlayer_ID(v8, v12) == v9 )
              {
                v20 = &result;
                v13.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
                UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(v8, 0i64, v12, v13, 0xFFFFFFFF);
LABEL_27:
                v10 = 1;
                goto LABEL_28;
              }
            }
            else if ( UFG::CharacterSubjectComponent::GetContextOverrideFreemanNPC_ID(v8, v12) == v9 )
            {
              v20 = &v19;
              v14.mUID = (unsigned int)UFG::qSymbol::qSymbol(&v19, 0xFFFFFFFF);
              UFG::CharacterSubjectComponent::SetContextOverrideFreemanNPC(v8, 0i64, v12, v14, 0xFFFFFFFF);
              goto LABEL_27;
            }
LABEL_28:
            if ( ++v12 >= 4 )
            {
              if ( v10 )
LABEL_36:
                v8->mTypeOverrideFreeman = -1;
              return;
            }
          }
        }
        UFG::CharacterSubjectComponent::GetContextOverride(v8, (UFG::qSymbol *)&v19, (int)v11[1].mResourceOwner);
        v15 = (int)v1->m_Track[1].mResourceOwner;
        if ( v3 )
        {
          if ( UFG::CharacterSubjectComponent::GetContextOverrideFreemanPlayer_ID(v8, v15) == v9 )
          {
            v20 = &result;
            v16.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(
              v8,
              0i64,
              (int)v1->m_Track[1].mResourceOwner,
              v16,
              0xFFFFFFFF);
            goto LABEL_36;
          }
        }
        else if ( UFG::CharacterSubjectComponent::GetContextOverrideFreemanNPC_ID(v8, v15) == v9 )
        {
          v20 = &result;
          v17.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideFreemanNPC(
            v8,
            0i64,
            (int)v1->m_Track[1].mResourceOwner,
            v17,
            0xFFFFFFFF);
          goto LABEL_36;
        }
      }
    }
  }
}

// File Line: 530
// RVA: 0x2F5130
void __fastcall SubjectFollowOverridePOITask::Begin(SubjectFollowOverridePOITask *this, ActionContext *context)
{
  ActionContext *v2; // r14
  SubjectFollowOverridePOITask *v3; // r15
  signed int v4; // edi
  bool v5; // al
  UFG::SimObject *v6; // rcx
  UFG::SimObjectCharacter *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::CharacterSubjectComponent *v9; // rax
  UFG::CharacterSubjectComponent *v10; // rsi
  ITrack *v11; // rcx
  const char *v12; // r8
  Expression::IMemberMap **v13; // rcx
  const char *v14; // r8
  UFG::SimObjectGame *v15; // rcx
  unsigned __int16 v16; // dx
  UFG::SimComponent *v17; // rdx
  UFG::SimComponent *v18; // rax
  UFG::SimObject *v19; // r12
  ITrack *v20; // rax
  UFG::qSymbol v21; // eax
  UFG::qSymbol v22; // eax
  int v23; // er8
  UFG::qSymbol override_right; // ebx
  UFG::qSymbol v25; // eax
  UFG::qSymbol v26; // ebx
  UFG::qSymbol v27; // eax
  ITrack *v28; // rax
  UFG::qSymbol v29; // eax
  UFG::qString result; // [rsp+40h] [rbp-29h]
  UFG::qString v31; // [rsp+68h] [rbp-1h]
  UFG::qSymbol v32; // [rsp+D0h] [rbp+67h]
  UFG::qSymbol *v33; // [rsp+E0h] [rbp+77h]
  UFG::qSymbol *v34; // [rsp+E8h] [rbp+7Fh]

  v2 = context;
  v3 = this;
  v4 = 0;
  this->mActionContext = 0i64;
  v5 = this->m_Track[1].mDisable != 0;
  v6 = context->mSimObject.m_pPointer;
  if ( v5 )
  {
    if ( !UFG::IsAnyLocalPlayer(v6) )
      return;
  }
  else if ( UFG::IsAnyLocalPlayer(v6) )
  {
    return;
  }
  if ( UFG::IsAnyLocalPlayer(v2->mSimObject.m_pPointer) )
    v7 = (UFG::SimObjectCharacter *)v2->mSimObject.m_pPointer;
  else
    v7 = UFG::GetLocalPlayer();
  if ( v7 )
  {
    v8 = v7->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v7);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v9 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v7->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      else
        v9 = (UFG::CharacterSubjectComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v7->vfptr,
                                                                   UFG::CharacterSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::CharacterSubjectComponent::_TypeUID));
    }
    else
    {
      v9 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v7->vfptr,
                                               UFG::CharacterSubjectComponent::_TypeUID);
    }
    v10 = v9;
    if ( v9 )
    {
      v3->mActionContext = v2;
      v11 = v3->m_Track + 1;
      v12 = (char *)v11 + ((_QWORD)v11->vfptr & 0xFFFFFFFFFFFFFFFEui64);
      if ( !((_QWORD)v11->vfptr & 0xFFFFFFFFFFFFFFFEui64) )
        v12 = BinString::sEmptyString;
      UFG::qString::FormatEx(&result, "Cameras-%s", v12);
      v13 = &v3->m_Track[1].mResourceOwner;
      v14 = (char *)v13 + ((unsigned __int64)*v13 & 0xFFFFFFFFFFFFFFFEui64);
      if ( !((unsigned __int64)*v13 & 0xFFFFFFFFFFFFFFFEui64) )
        v14 = BinString::sEmptyString;
      UFG::qString::FormatEx(&v31, "Cameras-%s", v14);
      v15 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
      if ( v15
        && ((v16 = v15->m_Flags, !((v16 >> 14) & 1)) ? ((v16 & 0x8000u) == 0 ? (!((v16 >> 13) & 1) ? (!((v16 >> 12) & 1) ? (v18 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                                v17 = v18) : (v17 = v15->m_Components.p[20].m_pComponent)) : (v17 = v15->m_Components.p[20].m_pComponent),
            v17) )
      {
        v19 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v17[1].m_Flags + 35i64)
                                 + *(_QWORD *)&v17[1].m_TypeUID
                                 + 40);
        v20 = v3->m_Track;
        if ( v19 )
        {
          if ( v20[1].mBreakPoint )
          {
            v10->mTypeOverrideFreeman = v20[1].m_TrackClassNameUID;
            v34 = &v32;
            do
            {
              override_right.mUID = (unsigned int)UFG::qSymbol::create_from_string(&v32, v31.mData);
              v25.mUID = (unsigned int)UFG::qSymbol::create_from_string((UFG::qSymbol *)&v33, result.mData);
              UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI(
                v10,
                v2,
                v19,
                v4++,
                v25,
                override_right);
            }
            while ( v4 < 4 );
          }
          else
          {
            v34 = &v32;
            v26.mUID = (unsigned int)UFG::qSymbol::create_from_string(&v32, v31.mData);
            v27.mUID = (unsigned int)UFG::qSymbol::create_from_string((UFG::qSymbol *)&v33, result.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI(
              v10,
              v2,
              v19,
              v3->m_Track[1].m_TrackClassNameUID,
              v27,
              v26);
          }
          goto LABEL_52;
        }
        if ( v20[1].mBreakPoint )
        {
          v10->mTypeOverrideFreeman = v20[1].m_TrackClassNameUID;
          v33 = &v32;
          do
          {
            v21.mUID = (unsigned int)UFG::qSymbol::create_from_string(&v32, result.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(v10, v2, v4++, v21, 0xFFFFFFFF);
          }
          while ( v4 < 4 );
          goto LABEL_52;
        }
        v33 = &v32;
        v22.mUID = (unsigned int)UFG::qSymbol::create_from_string(&v32, result.mData);
        v23 = v3->m_Track[1].m_TrackClassNameUID;
      }
      else
      {
        v28 = v3->m_Track;
        if ( v28[1].mBreakPoint )
        {
          v10->mTypeOverrideFreeman = v28[1].m_TrackClassNameUID;
          v33 = &v32;
          do
          {
            v29.mUID = (unsigned int)UFG::qSymbol::create_from_string(&v32, result.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(v10, v2, v4++, v29, 0xFFFFFFFF);
          }
          while ( v4 < 4 );
          goto LABEL_52;
        }
        v33 = &v32;
        v22.mUID = (unsigned int)UFG::qSymbol::create_from_string(&v32, result.mData);
        v23 = v3->m_Track[1].m_TrackClassNameUID;
      }
      UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(v10, v2, v23, v22, 0xFFFFFFFF);
LABEL_52:
      UFG::qString::~qString(&v31);
      UFG::qString::~qString(&result);
      return;
    }
  }
}

// File Line: 595
// RVA: 0x300580
void __fastcall SubjectFollowOverridePOITask::End(SubjectFollowOverridePOITask *this)
{
  SubjectFollowOverridePOITask *v1; // rsi
  ActionContext *v2; // rcx
  UFG::SimObject *v3; // rcx
  UFG::SimObjectCharacter *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::CharacterSubjectComponent *v6; // rax
  UFG::CharacterSubjectComponent *v7; // rdi
  bool v8; // zf
  int v9; // esi
  UFG::qSymbol override_right; // ebx
  UFG::qSymbol override_left; // eax
  UFG::qSymbol v12; // ebx
  UFG::qSymbol v13; // eax
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+8h]
  UFG::qWiseSymbol v15; // [rsp+68h] [rbp+10h]
  UFG::qWiseSymbol *v16; // [rsp+70h] [rbp+18h]
  UFG::qWiseSymbol *v17; // [rsp+78h] [rbp+20h]

  v1 = this;
  v2 = this->mActionContext;
  if ( v2 )
  {
    v3 = v2->mSimObject.m_pPointer;
    if ( v1->m_Track[1].mDisable )
    {
      if ( !UFG::IsAnyLocalPlayer(v3) )
        return;
    }
    else if ( UFG::IsAnyLocalPlayer(v3) )
    {
      return;
    }
    if ( UFG::IsAnyLocalPlayer(v1->mActionContext->mSimObject.m_pPointer) )
      v4 = (UFG::SimObjectCharacter *)v1->mActionContext->mSimObject.m_pPointer;
    else
      v4 = UFG::GetLocalPlayer();
    if ( v4 )
    {
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v4);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v4->vfptr,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v4->vfptr,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v4->vfptr,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
        }
      }
      else
      {
        v6 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
      v7 = v6;
      if ( v6 )
      {
        v6->mTypeOverrideFreeman = -1;
        v8 = v1->m_Track[1].mBreakPoint == 0;
        v16 = &result;
        v17 = &v15;
        if ( v8 )
        {
          v12.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          v13.mUID = (unsigned int)UFG::qSymbol::qSymbol(&v15, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI(
            v7,
            0i64,
            0i64,
            v1->m_Track[1].m_TrackClassNameUID,
            v13,
            v12);
        }
        else
        {
          v9 = 0;
          do
          {
            override_right.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
            override_left.mUID = (unsigned int)UFG::qSymbol::qSymbol(&v15, 0xFFFFFFFF);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI(
              v7,
              0i64,
              0i64,
              v9++,
              override_left,
              override_right);
          }
          while ( v9 < 4 );
        }
      }
    }
  }
}

// File Line: 625
// RVA: 0x2F4E70
void __fastcall SubjectFollowOverrideChooseTask::Begin(SubjectFollowOverrideChooseTask *this, ActionContext *context)
{
  ActionContext *v2; // rsi
  SubjectFollowOverrideChooseTask *v3; // r14
  int v4; // ebx
  bool v5; // al
  UFG::SimObject *v6; // rcx
  UFG::SimObjectCharacter *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::CharacterSubjectComponent *v9; // rax
  UFG::CharacterSubjectComponent *v10; // rdi
  ITrack *v11; // rcx
  const char *v12; // r8
  Expression::IMemberMap **v13; // rcx
  const char *v14; // r8
  unsigned int *v15; // rcx
  const char *v16; // rdx
  ExpressionParameterFloat *v17; // rcx
  const char *v18; // rdx
  ITrack *v19; // rax
  UFG::qSymbol left; // [rsp+40h] [rbp-59h]
  UFG::qSymbol v21; // [rsp+44h] [rbp-55h]
  UFG::qSymbol v22; // [rsp+48h] [rbp-51h]
  UFG::qSymbol v23; // [rsp+4Ch] [rbp-4Dh]
  UFG::qSymbol v24; // [rsp+50h] [rbp-49h]
  UFG::qSymbol *v25; // [rsp+58h] [rbp-41h]
  UFG::qSymbol *v26; // [rsp+60h] [rbp-39h]
  UFG::qSymbol *v27; // [rsp+68h] [rbp-31h]
  UFG::qSymbol *v28; // [rsp+70h] [rbp-29h]
  __int64 v29; // [rsp+78h] [rbp-21h]
  UFG::qString v30; // [rsp+80h] [rbp-19h]
  UFG::qString result; // [rsp+A8h] [rbp+Fh]
  UFG::qSymbol v32; // [rsp+100h] [rbp+67h]
  UFG::qSymbol v33; // [rsp+110h] [rbp+77h]
  UFG::qSymbol v34; // [rsp+118h] [rbp+7Fh]

  v29 = -2i64;
  v2 = context;
  v3 = this;
  v4 = 0;
  this->mActionContext = 0i64;
  v5 = BYTE5(this->m_Track[1].mMasterRate.expression.mOffset) != 0;
  v6 = context->mSimObject.m_pPointer;
  if ( v5 )
  {
    if ( !UFG::IsAnyLocalPlayer(v6) )
      return;
  }
  else if ( UFG::IsAnyLocalPlayer(v6) )
  {
    return;
  }
  if ( UFG::IsAnyLocalPlayer(v2->mSimObject.m_pPointer) )
    v7 = (UFG::SimObjectCharacter *)v2->mSimObject.m_pPointer;
  else
    v7 = UFG::GetLocalPlayer();
  if ( v7 )
  {
    v8 = v7->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v7);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v9 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v7->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      else
        v9 = (UFG::CharacterSubjectComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v7->vfptr,
                                                                   UFG::CharacterSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::CharacterSubjectComponent::_TypeUID));
    }
    else
    {
      v9 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v7->vfptr,
                                               UFG::CharacterSubjectComponent::_TypeUID);
    }
    v10 = v9;
    if ( v9 )
    {
      v3->mActionContext = v2;
      v11 = v3->m_Track + 1;
      v12 = (char *)v11 + ((_QWORD)v11->vfptr & 0xFFFFFFFFFFFFFFFEui64);
      if ( !((_QWORD)v11->vfptr & 0xFFFFFFFFFFFFFFFEui64) )
        v12 = BinString::sEmptyString;
      UFG::qString::FormatEx(&result, "Cameras-%s", v12);
      v13 = &v3->m_Track[1].mResourceOwner;
      v14 = (char *)v13 + ((unsigned __int64)*v13 & 0xFFFFFFFFFFFFFFFEui64);
      if ( !((unsigned __int64)*v13 & 0xFFFFFFFFFFFFFFFEui64) )
        v14 = BinString::sEmptyString;
      UFG::qString::FormatEx(&v30, "Cameras-%s", v14);
      UFG::qSymbol::create_from_string(&v21, result.mData);
      UFG::qSymbol::create_from_string(&v24, v30.mData);
      v15 = &v3->m_Track[1].m_TrackClassNameUID;
      v16 = (char *)v15 + (*(_QWORD *)v15 & 0xFFFFFFFFFFFFFFFEui64);
      if ( !(*(_QWORD *)v15 & 0xFFFFFFFFFFFFFFFEui64) )
        v16 = BinString::sEmptyString;
      UFG::qSymbol::create_from_string(&v23, v16);
      v17 = &v3->m_Track[1].mMasterRate;
      v18 = (char *)v17 + (v17->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( !(v17->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) )
        v18 = BinString::sEmptyString;
      UFG::qSymbol::create_from_string(&v22, v18);
      v19 = v3->m_Track;
      if ( BYTE4(v19[1].mMasterRate.expression.mOffset) )
      {
        v10->mTypeOverrideFreeman = v19[1].mMasterRate.expression.mOffset;
        v25 = &v32;
        v26 = &v33;
        v28 = &v34;
        v27 = &left;
        do
        {
          v32.mUID = v22.mUID;
          v33.mUID = v23.mUID;
          v34.mUID = v24.mUID;
          left.mUID = v21.mUID;
          UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerChoose(
            v10,
            v2,
            v4++,
            (UFG::qSymbol)&left,
            (UFG::qSymbol)&v34,
            (UFG::qSymbol)&v33,
            (UFG::qSymbol)&v32);
        }
        while ( v4 < 4 );
      }
      else
      {
        v27 = &v32;
        v28 = &v33;
        v26 = &v34;
        v25 = &left;
        v32.mUID = v22.mUID;
        v33.mUID = v23.mUID;
        v34.mUID = v24.mUID;
        left.mUID = v21.mUID;
        UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerChoose(
          v10,
          v2,
          v3->m_Track[1].mMasterRate.expression.mOffset,
          (UFG::qSymbol)&left,
          (UFG::qSymbol)&v34,
          (UFG::qSymbol)&v33,
          (UFG::qSymbol)&v32);
      }
      UFG::qString::~qString(&v30);
      UFG::qString::~qString(&result);
    }
  }
}

// File Line: 664
// RVA: 0x300390
void __fastcall SubjectFollowOverrideChooseTask::End(SubjectFollowOverrideChooseTask *this)
{
  SubjectFollowOverrideChooseTask *v1; // rbx
  ActionContext *v2; // rcx
  UFG::SimObject *v3; // rcx
  UFG::SimObjectCharacter *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::CharacterSubjectComponent *v6; // rax
  UFG::CharacterSubjectComponent *v7; // rdi
  int v8; // ebx
  UFG::qSymbol left; // [rsp+40h] [rbp-30h]
  __int64 v10; // [rsp+48h] [rbp-28h]
  UFG::qSymbol *v11; // [rsp+50h] [rbp-20h]
  UFG::qSymbol *v12; // [rsp+58h] [rbp-18h]
  UFG::qSymbol *v13; // [rsp+60h] [rbp-10h]
  UFG::qSymbol *v14; // [rsp+68h] [rbp-8h]
  UFG::qWiseSymbol result; // [rsp+90h] [rbp+20h]
  UFG::qSymbol v16; // [rsp+98h] [rbp+28h]
  UFG::qSymbol v17; // [rsp+A0h] [rbp+30h]
  UFG::qSymbol v18; // [rsp+A8h] [rbp+38h]

  v10 = -2i64;
  v1 = this;
  v2 = this->mActionContext;
  if ( v2 )
  {
    v3 = v2->mSimObject.m_pPointer;
    if ( BYTE5(v1->m_Track[1].mMasterRate.expression.mOffset) )
    {
      if ( !UFG::IsAnyLocalPlayer(v3) )
        return;
    }
    else if ( UFG::IsAnyLocalPlayer(v3) )
    {
      return;
    }
    if ( UFG::IsAnyLocalPlayer(v1->mActionContext->mSimObject.m_pPointer) )
      v4 = (UFG::SimObjectCharacter *)v1->mActionContext->mSimObject.m_pPointer;
    else
      v4 = UFG::GetLocalPlayer();
    if ( v4 )
    {
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v4);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v4->vfptr,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v4->vfptr,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v4->vfptr,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
        }
      }
      else
      {
        v6 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
      v7 = v6;
      if ( v6 )
      {
        UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
        v7->mTypeOverrideFreeman = -1;
        if ( BYTE4(v1->m_Track[1].mMasterRate.expression.mOffset) )
        {
          v8 = 0;
          v11 = &v16;
          v12 = &v17;
          v13 = &v18;
          v14 = &left;
          do
          {
            v16.mUID = result.mUID;
            v17.mUID = result.mUID;
            v18.mUID = result.mUID;
            left.mUID = result.mUID;
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerChoose(
              v7,
              0i64,
              v8++,
              (UFG::qSymbol)&left,
              (UFG::qSymbol)&v18,
              (UFG::qSymbol)&v17,
              (UFG::qSymbol)&v16);
          }
          while ( v8 < 4 );
        }
        else
        {
          v14 = &v16;
          v13 = &v17;
          v12 = &v18;
          v11 = &left;
          v16.mUID = result.mUID;
          v17.mUID = result.mUID;
          v18.mUID = result.mUID;
          left.mUID = result.mUID;
          UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerChoose(
            v7,
            0i64,
            v1->m_Track[1].mMasterRate.expression.mOffset,
            (UFG::qSymbol)&left,
            (UFG::qSymbol)&v18,
            (UFG::qSymbol)&v17,
            (UFG::qSymbol)&v16);
        }
      }
    }
  }
}

// File Line: 698
// RVA: 0x2EA040
void __fastcall CameraFollowGotoTask::Begin(CameraFollowGotoTask *this, ActionContext *context)
{
  ITrack *v2; // rax
  CameraFollowGotoTask *v3; // rbx
  UFG::SimObject *v4; // rcx
  ActionContext *v5; // rdi
  UFG::SimObjectCharacter *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::CharacterSubjectComponent *v8; // rax
  UFG::CharacterSubjectComponent *v9; // rdi
  ITrack *v10; // rax
  ITrack *v11; // rax
  ITrack *v12; // r9
  ITrack *v13; // rax
  UFG::SimObject *v14; // rcx
  UFG::FollowCameraComponent *v15; // rax
  ITrack *v16; // rax
  UFG::SimObject *v17; // rcx
  UFG::FollowCameraComponent *v18; // rax
  UFG::SimObject *v19; // rcx
  UFG::ChaseCameraComponent *v20; // rax

  v2 = this->m_Track;
  v3 = this;
  v4 = context->mSimObject.m_pPointer;
  v5 = context;
  if ( *((_BYTE *)&v2[1].mMasterRate.value + 6) )
  {
    if ( !UFG::IsAnyLocalPlayer(v4) )
      return;
  }
  else if ( UFG::IsAnyLocalPlayer(v4) )
  {
    return;
  }
  if ( UFG::IsAnyLocalPlayer(v5->mSimObject.m_pPointer) )
    v6 = (UFG::SimObjectCharacter *)v5->mSimObject.m_pPointer;
  else
    v6 = UFG::GetLocalPlayer();
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v6);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v8 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v6->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      else
        v8 = (UFG::CharacterSubjectComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v6->vfptr,
                                                                   UFG::CharacterSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterSubjectComponent::_TypeUID));
    }
    else
    {
      v8 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v6->vfptr,
                                               UFG::CharacterSubjectComponent::_TypeUID);
    }
    v9 = v8;
    if ( v8 )
    {
      v10 = v3->m_Track;
      if ( LOBYTE(v10[1].mMasterRate.value) && !BYTE1(v10[1].mMasterRate.value) )
        UFG::CharacterSubjectComponent::SetGotoRise(
          v9,
          *(float *)&v10[1].vfptr,
          *((float *)&v10[1].vfptr + 1),
          *(float *)&v10[1].mResourceOwner);
      v11 = v3->m_Track;
      if ( BYTE2(v11[1].mMasterRate.value) )
        UFG::CharacterSubjectComponent::SetGotoRadius(
          v9,
          *((float *)&v11[1].mResourceOwner + 1),
          *(float *)&v11[1].m_TrackClassNameUID,
          *(float *)&v11[1].mBreakPoint);
      v12 = v3->m_Track;
      if ( HIBYTE(v12[1].mMasterRate.value) && !*((_BYTE *)&v12[1].mMasterRate.value + 5) )
        UFG::CharacterSubjectComponent::SetGotoAngle(
          v9,
          *(float *)&v12[1].mMasterRate.text.mOffset,
          *((float *)&v12[1].mMasterRate.text.mOffset + 1),
          *(float *)&v12[1].mMasterRate.expression.mOffset,
          *((_BYTE *)&v12[1].mMasterRate.value + 4) != 0,
          *((_BYTE *)&v12[1].mMasterRate.value + 7) != 0,
          *((float *)&v12[1].mMasterRate.expression.mOffset + 1),
          LOBYTE(v12[1].mTimeBegin) != 0,
          BYTE1(v12[1].mTimeBegin) != 0);
      v13 = v3->m_Track;
      if ( LOBYTE(v13[1].mMasterRate.value) )
      {
        if ( BYTE1(v13[1].mMasterRate.value) )
        {
          v14 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
          if ( v14 )
          {
            v15 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                  v14,
                                                  UFG::FollowCameraComponent::_TypeUID);
            if ( v15 )
              UFG::FollowCameraComponent::GotoRiseSnap(v15, *(float *)&v3->m_Track[1].vfptr);
          }
        }
      }
      v16 = v3->m_Track;
      if ( HIBYTE(v16[1].mMasterRate.value) && *((_BYTE *)&v16[1].mMasterRate.value + 5) )
      {
        v17 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
        if ( v17 )
        {
          v18 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                v17,
                                                UFG::FollowCameraComponent::_TypeUID);
          if ( v18 )
            UFG::FollowCameraComponent::GotoAngleSnap(
              v18,
              (float)(*(float *)&v3->m_Track[1].mMasterRate.text.mOffset * 3.1415927) * 0.0055555557,
              *((_BYTE *)&v3->m_Track[1].mMasterRate.value + 4) != 0);
        }
        v19 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
        if ( v19 )
        {
          v20 = (UFG::ChaseCameraComponent *)UFG::SimObject::GetComponentOfType(
                                               v19,
                                               UFG::ChaseCameraComponent::_TypeUID);
          if ( v20 )
            UFG::ChaseCameraComponent::GotoAngleSnap(
              v20,
              (float)(*(float *)&v3->m_Track[1].mMasterRate.text.mOffset * 3.1415927) * 0.0055555557,
              *((_BYTE *)&v3->m_Track[1].mMasterRate.value + 4) != 0);
        }
      }
    }
  }
}

// File Line: 765
// RVA: 0x2EA2C0
void __fastcall CameraFollowTargetTask::Begin(CameraFollowTargetTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *v2; // rbx
  CameraFollowTargetTask *v3; // rbp
  __int64 v4; // rdi
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // cx
  UFG::CharacterAnimationComponent *v9; // rax
  UFG::CharacterAnimationComponent *v10; // rdi
  UFG::SimObject *v11; // rcx
  UFG::ScriptCameraComponent *v12; // rsi
  Creature *v13; // rdi
  int v14; // eax

  v2 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v3 = this;
  v4 = LODWORD(this->m_Track[1].vfptr);
  if ( (_DWORD)v4 != 1 )
  {
    if ( !v2 )
      return;
    v5 = v2->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v2->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v2->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v2->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v6 = v7;
    }
    else
    {
      v6 = v2->m_Components.p[20].m_pComponent;
    }
    if ( v6 )
      v2 = *(UFG::SimObjectCVBase **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + v4 + 8)
                                    + *(_QWORD *)&v6[1].m_TypeUID
                                    + 40);
  }
  if ( v2 )
  {
    v8 = v2->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v9 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v2);
      else
        v9 = (UFG::CharacterAnimationComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v2->vfptr,
                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
    }
    else
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
    }
    v10 = v9;
    if ( v9 )
    {
      v11 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
      if ( v11 )
      {
        v12 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                              v11,
                                              UFG::ScriptCameraComponent::_TypeUID);
        if ( v12 )
        {
          v13 = v10->mCreature;
          if ( v13->mPose.mRigHandle.mData
            && (v14 = Skeleton::GetBoneID(v13->mPose.mRigHandle.mUFGSkeleton, HIDWORD(v3->m_Track[1].vfptr)), v14 >= 0) )
          {
            UFG::ScriptCameraComponent::SetCameraCreature(v12, v13, v14);
          }
          else
          {
            UFG::ScriptCameraComponent::SetTarget(v12, v2->m_pTransformNodeComponent);
          }
        }
      }
    }
  }
}

// File Line: 814
// RVA: 0x2EA650
void __fastcall CameraSetSniperModeTask::Begin(CameraSetSniperModeTask *this, ActionContext *context)
{
  UFG::SimObject *v2; // rcx

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
    UFG::SimObject::GetComponentOfType(v2, UFG::FollowCameraComponent::_TypeUID);
}

