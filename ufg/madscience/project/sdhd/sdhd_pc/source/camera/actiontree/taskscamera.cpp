// File Line: 36
// RVA: 0x2E9E00
void __fastcall CameraChangeTask::Begin(CameraChangeTask *this, ActionContext *context)
{
  UFG::GameCameraComponent *CurrentGameCamera; // rax
  UFG::SimComponent *v5; // rdi
  ITrack *m_Track; // rax
  UFG::allocator::free_link *v7; // rax

  CurrentGameCamera = UFG::GetCurrentGameCamera();
  v5 = CurrentGameCamera;
  if ( CurrentGameCamera
    && (!UFG::SimComponent::IsType(CurrentGameCamera, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID)
     || LOBYTE(this->m_Track[1].vfptr))
    && (!UFG::SimComponent::IsType(v5, UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID)
     || LOBYTE(this->m_Track[1].vfptr) != 1) )
  {
    m_Track = this->m_Track;
    if ( LOBYTE(m_Track[1].vfptr) )
    {
      if ( LOBYTE(m_Track[1].vfptr) != 1 )
        return;
      v7 = UFG::qMalloc(0x50ui64, "CameraChangeTask", 0i64);
      if ( v7 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v7, "EVT_MOUNT_VEHICLE_CAMERA", &context->mSimObject);
    }
    else
    {
      v7 = UFG::qMalloc(0x50ui64, "CameraChangeTask", 0i64);
      if ( v7 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v7, "EVT_DISMOUNT_VEHICLE_CAMERA", &context->mSimObject);
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v7);
  }
}

// File Line: 68
// RVA: 0x2EA680
void __fastcall CameraShakeTask::Begin(CameraShakeTask *this, ActionContext *context)
{
  UFG::GameCameraComponent *CurrentGameCamera; // rbx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r9
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v8; // rax

  CurrentGameCamera = UFG::GetCurrentGameCamera();
  if ( CurrentGameCamera )
  {
    m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GunComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GunComponent::_TypeUID);
      if ( ComponentOfTypeHK )
      {
        v8 = ((__int64 (__fastcall *)(UFG::GameCameraComponent *))CurrentGameCamera->vfptr[41].__vecDelDtor)(CurrentGameCamera);
        if ( !v8
          || *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v8 + 96) + 25i64) + *(_QWORD *)(v8 + 88) + 40) != context->mSimObject.m_pPointer )
        {
          return;
        }
LABEL_18:
        UFG::GameCameraComponent::AddShakeAmplitude(CurrentGameCamera, *(float *)&this->m_Track[1].vfptr);
        return;
      }
    }
    if ( !BYTE4(this->m_Track[1].vfptr)
      || UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer)
      || !UFG::SimComponent::IsType(CurrentGameCamera, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID)
      && !UFG::SimComponent::IsType(CurrentGameCamera, UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID) )
    {
      goto LABEL_18;
    }
  }
}

// File Line: 102
// RVA: 0x2EA550
void __fastcall CameraResetTask::Begin(CameraResetTask *this, ActionContext *context)
{
  bool IsType; // bl
  char v4; // bp
  UFG::GameCameraComponent *CurrentGameCamera; // rax
  UFG::SimComponent *v6; // rsi
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v9; // rcx
  UFG::SimComponent *v10; // rax

  if ( UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer) )
  {
    IsType = 0;
    v4 = 0;
    if ( BYTE2(this->m_Track[1].vfptr) )
    {
      CurrentGameCamera = UFG::GetCurrentGameCamera();
      v6 = CurrentGameCamera;
      if ( CurrentGameCamera )
      {
        if ( UFG::SimComponent::IsType(CurrentGameCamera, UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID) )
          v4 = 1;
        else
          IsType = UFG::SimComponent::IsType(v6, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID);
      }
    }
    if ( LOBYTE(this->m_Track[1].vfptr) || v4 )
    {
      m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
      if ( m_pSimObject )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ChaseCameraComponent::_TypeUID);
        if ( ComponentOfType )
          ((void (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[14].__vecDelDtor)(ComponentOfType);
      }
    }
    if ( BYTE1(this->m_Track[1].vfptr) || IsType )
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
  UFG::GameCameraComponent *CurrentGameCamera; // rax
  UFG::GameCameraComponent *v4; // rbx
  __int64 v5; // rax

  CurrentGameCamera = UFG::GetCurrentGameCamera();
  v4 = CurrentGameCamera;
  if ( CurrentGameCamera )
  {
    v5 = ((__int64 (__fastcall *)(UFG::GameCameraComponent *))CurrentGameCamera->vfptr[41].__vecDelDtor)(CurrentGameCamera);
    if ( v5 )
    {
      if ( *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v5 + 96) + 25i64) + *(_QWORD *)(v5 + 88) + 40) == context->mSimObject.m_pPointer )
        ((void (__fastcall *)(UFG::GameCameraComponent *))v4->vfptr[40].__vecDelDtor)(v4);
    }
  }
}

// File Line: 149
// RVA: 0x2E9F10
void __fastcall CameraCollisionGotoAngleTask::Begin(CameraCollisionGotoAngleTask *this, ActionContext *context)
{
  UFG::GameCameraComponent *CurrentGameCamera; // rax
  UFG::FollowCameraComponent *v4; // rbx
  bool IsType; // al
  UFG::FollowCameraComponent *v6; // rcx

  CurrentGameCamera = UFG::GetCurrentGameCamera();
  v4 = (UFG::FollowCameraComponent *)CurrentGameCamera;
  if ( CurrentGameCamera )
  {
    IsType = UFG::SimComponent::IsType(CurrentGameCamera, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID);
    v6 = 0i64;
    if ( IsType )
      v6 = v4;
    if ( v6 )
      UFG::FollowCameraComponent::GotoAngleCollisionQueue(v6, *(float *)&this->m_Track[1].vfptr);
  }
}

// File Line: 163
// RVA: 0x2E9F60
void __fastcall CameraConstrainYawTask::Begin(CameraConstrainYawTask *this, ActionContext *context)
{
  bool IsAnyLocalPlayer; // al
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  float *m_Track; // rcx
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm4_4

  IsAnyLocalPlayer = UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer);
  this->mLocalPlayer = IsAnyLocalPlayer;
  if ( IsAnyLocalPlayer )
  {
    m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
    if ( m_pSimObject )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
      if ( ComponentOfType )
      {
        m_Track = (float *)this->m_Track;
        v7 = m_Track[14];
        v8 = m_Track[15];
        v9 = m_Track[16];
        LOBYTE(ComponentOfType[128].m_BoundComponentHandles.mNode.mPrev) = 1;
        *((float *)&ComponentOfType[128].m_BoundComponentHandles.mNode.mPrev + 1) = (float)(v7 * 3.1415927)
                                                                                  * 0.0055555557;
        *(float *)&ComponentOfType[128].m_BoundComponentHandles.mNode.mNext = (float)(v8 * 3.1415927) * 0.0055555557;
        *((float *)&ComponentOfType[128].m_BoundComponentHandles.mNode.mNext + 1) = (float)(v9 * 3.1415927)
                                                                                  * 0.0055555557;
      }
    }
  }
}

// File Line: 182
// RVA: 0x2FE380
void __fastcall CameraConstrainYawTask::End(CameraConstrainYawTask *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  if ( this->mLocalPlayer )
  {
    m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
    if ( m_pSimObject )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
      if ( ComponentOfType )
        LOBYTE(ComponentOfType[128].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
  }
}

// File Line: 196
// RVA: 0x2EA470
void __fastcall CameraIgnoreCollisionTask::Begin(CameraIgnoreCollisionTask *this, ActionContext *context)
{
  bool IsAnyLocalPlayer; // al
  ITrack *m_Track; // rax
  bool v5; // dl

  IsAnyLocalPlayer = UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer);
  this->mLocalPlayer = IsAnyLocalPlayer;
  if ( IsAnyLocalPlayer )
  {
    m_Track = this->m_Track;
    v5 = LOBYTE(m_Track[1].vfptr) != 0;
    this->mIgnoreCharacters = v5;
    this->mIgnoreVehicles = BYTE1(m_Track[1].vfptr) != 0;
    if ( v5 )
      UFG::GameCameraComponent::SetCollisionIgnoreCharacters(1);
    if ( this->mIgnoreVehicles )
      UFG::GameCameraComponent::SetCollisionIgnoreVehicles(1);
  }
}

// File Line: 215
// RVA: 0x2FE3D0
void __fastcall CameraIgnoreCollisionTask::End(CameraIgnoreCollisionTask *this)
{
  if ( this->mLocalPlayer )
  {
    if ( this->mIgnoreCharacters )
      UFG::GameCameraComponent::SetCollisionIgnoreCharacters(0);
    if ( this->mIgnoreVehicles )
      UFG::GameCameraComponent::SetCollisionIgnoreVehicles(0);
  }
}

// File Line: 232
// RVA: 0x2DE220
void __fastcall CameraAnimationTask::CameraAnimationTask(CameraAnimationTask *this)
{
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mController; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CameraAnimationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CameraAnimationTask::`vftable;
  p_mController = &this->mController;
  this->mController.mPrev = &this->mController;
  this->mController.mNext = &this->mController;
  this->mController.m_pPointer = 0i64;
  this->mAnimatedCameraComponent.mPrev = &this->mAnimatedCameraComponent;
  this->mAnimatedCameraComponent.mNext = &this->mAnimatedCameraComponent;
  this->mAnimatedCameraComponent.m_pPointer = 0i64;
  this->mPreviousCameraComponent.mPrev = &this->mPreviousCameraComponent;
  this->mPreviousCameraComponent.mNext = &this->mPreviousCameraComponent;
  this->mPreviousCameraComponent.m_pPointer = 0i64;
  if ( this->mController.m_pPointer )
  {
    mPrev = p_mController->mPrev;
    mNext = p_mController->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mController->mPrev = p_mController;
    p_mController->mNext = p_mController;
  }
  p_mController->m_pPointer = 0i64;
}

// File Line: 237
// RVA: 0x2E9A70
void __fastcall CameraAnimationTask::Begin(CameraAnimationTask *this, ActionContext *context)
{
  ITrack *m_Track; // rdi
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AnimatedCameraComponent> *p_mAnimatedCameraComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::GameCameraComponent *CurrentGameCamera; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::GameCameraComponent> *p_mPreviousCameraComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::SimObjectCharacter *m_pPointer; // rdx
  bool v19; // al
  float *v20; // rax
  AnimationNode *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v22; // rdx
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mController; // r8
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v26; // rax
  AnimationNode *v27; // rcx
  UFG::SimObjectGame *v28; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  Creature *v31; // rdi
  NISManager *Instance; // rax

  m_Track = this->m_Track;
  this->mContext = context;
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::AnimatedCameraComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  p_mAnimatedCameraComponent = &this->mAnimatedCameraComponent;
  if ( this->mAnimatedCameraComponent.m_pPointer )
  {
    mPrev = p_mAnimatedCameraComponent->mPrev;
    mNext = this->mAnimatedCameraComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAnimatedCameraComponent->mPrev = p_mAnimatedCameraComponent;
    this->mAnimatedCameraComponent.mNext = &this->mAnimatedCameraComponent;
  }
  this->mAnimatedCameraComponent.m_pPointer = ComponentOfType;
  if ( ComponentOfType )
  {
    p_mNode = &ComponentOfType->m_SafePointerList.mNode;
    v11 = ComponentOfType->m_SafePointerList.mNode.mPrev;
    v11->mNext = p_mAnimatedCameraComponent;
    p_mAnimatedCameraComponent->mPrev = v11;
    this->mAnimatedCameraComponent.mNext = p_mNode;
    p_mNode->mPrev = p_mAnimatedCameraComponent;
  }
  if ( this->mAnimatedCameraComponent.m_pPointer )
  {
    CurrentGameCamera = UFG::GetCurrentGameCamera();
    p_mPreviousCameraComponent = &this->mPreviousCameraComponent;
    if ( this->mPreviousCameraComponent.m_pPointer )
    {
      v14 = p_mPreviousCameraComponent->mPrev;
      v15 = this->mPreviousCameraComponent.mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      p_mPreviousCameraComponent->mPrev = p_mPreviousCameraComponent;
      this->mPreviousCameraComponent.mNext = &this->mPreviousCameraComponent;
    }
    this->mPreviousCameraComponent.m_pPointer = CurrentGameCamera;
    if ( CurrentGameCamera )
    {
      v16 = &CurrentGameCamera->m_SafePointerList.mNode;
      v17 = CurrentGameCamera->m_SafePointerList.mNode.UFG::BaseCameraComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v17->mNext = p_mPreviousCameraComponent;
      p_mPreviousCameraComponent->mPrev = v17;
      this->mPreviousCameraComponent.mNext = v16;
      v16->mPrev = p_mPreviousCameraComponent;
    }
    m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
    LODWORD(this->mAnimatedCameraComponent.m_pPointer[22].vfptr) = HIDWORD(this->m_Track[1].mResourceOwner);
    if ( !m_pPointer )
      m_pPointer = LocalPlayer;
    ((void (__fastcall *)(UFG::SimComponent *, UFG::SimObjectCharacter *, UFG::qSafePointer<UFG::SimComponent,UFG::GameCameraComponent> *))this->mAnimatedCameraComponent.m_pPointer->vfptr[16].__vecDelDtor)(
      this->mAnimatedCameraComponent.m_pPointer,
      m_pPointer,
      p_mPreviousCameraComponent);
    LOBYTE(this->mAnimatedCameraComponent.m_pPointer[22].m_SafePointerList.mNode.mNext) = BYTE5(this->m_Track[2].mResourceOwner) != 0;
    BYTE1(this->mAnimatedCameraComponent.m_pPointer[22].m_SafePointerList.mNode.mNext) = LOBYTE(this->m_Track[2].m_TrackClassNameUID) != 0;
    BYTE2(this->mAnimatedCameraComponent.m_pPointer[22].m_SafePointerList.mNode.mNext) = BYTE1(this->m_Track[2].m_TrackClassNameUID) != 0;
    BYTE3(this->mAnimatedCameraComponent.m_pPointer[22].m_SafePointerList.mNode.mNext) = BYTE2(this->m_Track[2].m_TrackClassNameUID) != 0;
    BYTE4(this->mAnimatedCameraComponent.m_pPointer[22].m_SafePointerList.mNode.mNext) = HIBYTE(this->m_Track[2].mResourceOwner) != 0;
    if ( this->m_Track[2].mDisable )
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
    v20 = (float *)this->m_Track;
    UFG::AnimatedCameraComponent::SetDofParameters(
      (UFG::AnimatedCameraComponent *)this->mAnimatedCameraComponent.m_pPointer,
      v20[18],
      v20[19],
      v20[21],
      v20[20],
      v20[23],
      v20[22]);
    UFG::AttachCameraToView((UFG::BaseCameraComponent *)this->mAnimatedCameraComponent.m_pPointer);
    v21 = UFG::AnimatedCameraComponent::Play(
            (UFG::AnimatedCameraComponent *)this->mAnimatedCameraComponent.m_pPointer,
            (UFG::qSymbolUC *)&m_Track[2].mResourceOwner,
            *((float *)&this->m_Track[1].vfptr + 1));
    p_mController = &this->mController;
    if ( this->mController.m_pPointer )
    {
      v22 = p_mController->mPrev;
      v24 = this->mController.mNext;
      v22->mNext = v24;
      v24->mPrev = v22;
      p_mController->mPrev = p_mController;
      this->mController.mNext = &this->mController;
    }
    this->mController.m_pPointer = v21;
    if ( v21 )
    {
      v25 = &v21->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode;
      v26 = v21->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode.UFG::qSafePointerNode<AnimationNode>::mPrev;
      v26->mNext = p_mController;
      p_mController->mPrev = v26;
      this->mController.mNext = v25;
      v25->mPrev = p_mController;
    }
    v27 = this->mController.m_pPointer;
    if ( v27 )
    {
      LOBYTE(v22) = BYTE4(this->m_Track[2].mResourceOwner) != 0;
      v27->PoseNode::Expression::IMemberMap::vfptr[3].__vecDelDtor(v27, (unsigned int)v22);
      this->mController.m_pPointer->vfptr[2].FindWithOldPath(
        this->mController.m_pPointer,
        (const char *)LOBYTE(this->m_Track[1].vfptr));
      ((void (__fastcall *)(AnimationNode *, ActionContext *))this->mController.m_pPointer->vfptr[2].GetResourceOwner)(
        this->mController.m_pPointer,
        this->mContext);
    }
    LOBYTE(p_mController) = 1;
    ((void (__fastcall *)(AnimationNode *, UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *, UFG::qSafePointer<AnimationNode,AnimationNode> *))this->mController.m_pPointer->vfptr[1].GetClassNameUID)(
      this->mController.m_pPointer,
      v22,
      p_mController);
    v28 = (UFG::SimObjectGame *)this->mAnimatedCameraComponent.m_pPointer->m_pSimObject;
    if ( v28 )
    {
      m_Flags = v28->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v28->m_Components.p[9].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          m_pComponent = v28->m_Components.p[8].m_pComponent;
        else
          m_pComponent = (m_Flags & 0x1000) != 0
                       ? UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::BaseAnimationComponent::_TypeUID)
                       : UFG::SimObject::GetComponentOfType(v28, UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        m_pComponent = v28->m_Components.p[9].m_pComponent;
      }
      if ( m_pComponent )
      {
        v31 = *(Creature **)&m_pComponent[2].m_TypeUID;
        if ( v31 )
        {
          Creature::Update(*(Creature **)&m_pComponent[2].m_TypeUID, 0.0);
          Creature::UpdateTransforms(v31);
        }
        ((void (__fastcall *)(UFG::SimComponent *))this->mAnimatedCameraComponent.m_pPointer->vfptr[15].__vecDelDtor)(this->mAnimatedCameraComponent.m_pPointer);
      }
    }
  }
  Instance = NISManager::GetInstance();
  NISManager::OnCameraAttached(Instance, this);
}

// File Line: 298
// RVA: 0x303DE0
bool __fastcall CameraAnimationTask::Update(CameraAnimationTask *this, float timeDelta)
{
  bool v3; // al
  AnimationNode *m_pPointer; // rcx
  int vfptr_low; // edi

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
  m_pPointer = this->mController.m_pPointer;
  if ( !m_pPointer )
    return 0;
  vfptr_low = LOBYTE(this->m_Track[1].vfptr);
  if ( vfptr_low == 1
    || vfptr_low == 6
    || !((unsigned __int8 (__fastcall *)(AnimationNode *))m_pPointer->PoseNode::Expression::IMemberMap::vfptr[1].SetResourceOwner)(m_pPointer) )
  {
    return 1;
  }
  this->mController.m_pPointer->vfptr[1].GetResourceOwner(this->mController.m_pPointer);
  return vfptr_low == 2;
}

// File Line: 337
// RVA: 0x2FE1B0
void __fastcall CameraAnimationTask::End(CameraAnimationTask *this)
{
  CameraAnimationTrack *m_Track; // rbx
  NISManager *Instance; // rax
  UFG::SimComponent *m_pPointer; // rcx
  UFG::FollowCameraComponent *v5; // rbx
  ITrack *v6; // rax
  bool withVelocity; // si
  float value; // xmm6_4
  float v9; // xmm7_4
  float orientRateMin; // xmm8_4
  float orientRateMax; // xmm9_4
  UFG::SimComponent *v12; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **p_mNext; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax

  bRestrictSimTimeScaleChange = 0;
  m_Track = (CameraAnimationTrack *)this->m_Track;
  Instance = NISManager::GetInstance();
  NISManager::OnCameraDetached(Instance, m_Track);
  m_pPointer = this->mPreviousCameraComponent.m_pPointer;
  if ( m_pPointer )
  {
    if ( UFG::SimComponent::IsType(m_pPointer, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID) )
      v5 = (UFG::FollowCameraComponent *)this->mPreviousCameraComponent.m_pPointer;
    else
      v5 = 0i64;
    UFG::AttachCameraToView((UFG::BaseCameraComponent *)this->mPreviousCameraComponent.m_pPointer);
    ((void (__fastcall *)(UFG::SimComponent *))this->mPreviousCameraComponent.m_pPointer->vfptr[14].__vecDelDtor)(this->mPreviousCameraComponent.m_pPointer);
    if ( v5 )
      UFG::FollowCameraComponent::UpdateLocalWorld(v5, 0.0);
    v6 = this->m_Track;
    if ( BYTE6(v6[2].mResourceOwner) )
    {
      withVelocity = HIBYTE(v6[2].m_TrackClassNameUID) != 0;
      if ( v5 )
      {
        value = v6[1].mMasterRate.value;
        v9 = *(&v6[1].mMasterRate.value + 1);
        orientRateMin = v6[1].mTimeBegin;
        orientRateMax = v6[1].mTimeEnd;
        if ( v6[2].mBreakPoint )
        {
          UFG::FollowCameraComponent::GotoAngleSnap(v5, (float)(*(float *)&v6[2].vfptr * 3.1415927) * 0.0055555557, 1);
          UFG::FollowCameraComponent::GotoRiseSnap(v5, *((float *)&this->m_Track[2].vfptr + 1));
        }
        UFG::FollowCameraComponent::TransitionFromBlendOrientation(
          v5,
          (UFG::BaseCameraComponent *)this->mAnimatedCameraComponent.m_pPointer,
          value,
          v9,
          orientRateMin,
          orientRateMax,
          withVelocity);
      }
      else
      {
        ((void (__fastcall *)(UFG::SimComponent *, UFG::SimComponent *, bool))this->mPreviousCameraComponent.m_pPointer->vfptr[29].__vecDelDtor)(
          this->mPreviousCameraComponent.m_pPointer,
          this->mAnimatedCameraComponent.m_pPointer,
          withVelocity);
      }
    }
    ((void (__fastcall *)(UFG::SimComponent *))this->mPreviousCameraComponent.m_pPointer->vfptr[15].__vecDelDtor)(this->mPreviousCameraComponent.m_pPointer);
  }
  v12 = this->mAnimatedCameraComponent.m_pPointer;
  if ( v12 )
  {
    mPrev = v12[23].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
      ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, __int64))mPrev->mPrev->mNext)(
        mPrev,
        1i64);
    p_mNext = &v12[22].m_BoundComponentHandles.mNode.mNext;
    if ( v12[23].m_SafePointerList.mNode.mPrev )
    {
      v15 = *p_mNext;
      vfptr = v12[23].vfptr;
      v15->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)vfptr;
      vfptr->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v15;
      *p_mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)p_mNext;
      v12[23].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&v12[22].m_BoundComponentHandles.mNode.mNext;
    }
    v12[23].m_SafePointerList.mNode.mPrev = 0i64;
  }
}

// File Line: 380
// RVA: 0x2F5730
void __fastcall SubjectSprintTask::Begin(SubjectSprintTask *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(m_pPointer);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->mSprinting = LOBYTE(this->m_Track[1].vfptr) != 0;
  }
}

// File Line: 386
// RVA: 0x2F4D30
void __fastcall SubjectElevationTask::Begin(SubjectElevationTask *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(m_pPointer);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      UFG::CharacterSubjectComponent::SetElevationLock(ComponentOfTypeHK, LOBYTE(this->m_Track[1].vfptr) != 0);
  }
}

// File Line: 393
// RVA: 0x2F4DD0
void __fastcall SubjectFallingAttackTask::Begin(SubjectFallingAttackTask *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(m_pPointer);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->mFallingAttack = LOBYTE(this->m_Track[1].vfptr) != 0;
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
  int v4; // ebx
  bool v5; // r14
  bool IsAnyLocalPlayer; // al
  ITrack *v7; // rcx
  const char *v8; // r8
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *v11; // rax
  UFG::CharacterSubjectComponent *v12; // rdi
  ITrack *m_Track; // rax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  UFG::qString result; // [rsp+38h] [rbp-50h] BYREF
  UFG::qSymbol v18; // [rsp+90h] [rbp+8h] BYREF
  UFG::qSymbol *v19; // [rsp+A0h] [rbp+18h] BYREF
  UFG::qSymbol *v20; // [rsp+A8h] [rbp+20h]

  v4 = 0;
  this->mActionContext = 0i64;
  this->mUniqueID = -1;
  v5 = BYTE5(this->m_Track[1].mResourceOwner) != 0;
  IsAnyLocalPlayer = UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer);
  if ( v5 )
  {
    if ( !IsAnyLocalPlayer )
      return;
  }
  else if ( IsAnyLocalPlayer )
  {
    return;
  }
  v7 = this->m_Track + 1;
  v8 = (char *)v7 + ((unsigned __int64)v7->vfptr & 0xFFFFFFFFFFFFFFFEui64);
  if ( ((unsigned __int64)v7->vfptr & 0xFFFFFFFFFFFFFFFEui64) == 0 )
    v8 = BinString::sEmptyString;
  UFG::qString::FormatEx(&result, "Cameras-%s", v8);
  if ( UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer) )
    m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  else
    m_pPointer = UFG::GetLocalPlayer();
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v11 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(m_pPointer);
    else
      v11 = (UFG::CharacterSubjectComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::CharacterSubjectComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::CharacterSubjectComponent::_TypeUID));
    v12 = v11;
    if ( v11 )
    {
      this->mActionContext = context;
      this->mUniqueID = SubjectFollowOverrideTask::gUniqueIDNext++;
      m_Track = this->m_Track;
      if ( BYTE4(m_Track[1].mResourceOwner) )
      {
        v12->mTypeOverrideFreeman = (int)m_Track[1].mResourceOwner;
        do
        {
          if ( v5 )
          {
            v20 = &v18;
            v14 = (unsigned int)UFG::qSymbol::create_from_string(&v18, result.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(
              v12,
              context,
              v4,
              (UFG::qSymbol)v14,
              this->mUniqueID);
          }
          else
          {
            v20 = (UFG::qSymbol *)&v19;
            v15 = (unsigned int)UFG::qSymbol::create_from_string((UFG::qSymbol *)&v19, result.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanNPC(
              v12,
              context,
              v4,
              (UFG::qSymbol)v15,
              this->mUniqueID);
          }
          ++v4;
        }
        while ( v4 < 4 );
      }
      else
      {
        v19 = &v18;
        v16 = (unsigned int)UFG::qSymbol::create_from_string(&v18, result.mData);
        if ( v5 )
          UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(
            v12,
            context,
            (int)this->m_Track[1].mResourceOwner,
            (UFG::qSymbol)v16,
            this->mUniqueID);
        else
          UFG::CharacterSubjectComponent::SetContextOverrideFreemanNPC(
            v12,
            context,
            (int)this->m_Track[1].mResourceOwner,
            (UFG::qSymbol)v16,
            this->mUniqueID);
      }
    }
  }
  UFG::qString::~qString(&result);
}      (UFG::qSymbol)v16,
            this->mUniqueID);
      }
    }
  }
  UFG::qString::~qString(&resul

// File Line: 462
// RVA: 0x300720
void __fastcall SubjectFollowOverrideTask::End(SubjectFollowOverrideTask *this)
{
  ActionContext *mActionContext; // rcx
  bool v3; // r14
  bool IsAnyLocalPlayer; // al
  UFG::SimObjectCharacter *v5; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *v7; // rax
  UFG::CharacterSubjectComponent *v8; // rdi
  unsigned int mUniqueID; // esi
  char v10; // bp
  ITrack *m_Track; // rax
  int v12; // ebx
  unsigned int v13; // eax
  unsigned int v14; // eax
  int mResourceOwner; // edx
  unsigned int v16; // eax
  unsigned int v17; // eax
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+8h] BYREF
  UFG::qWiseSymbol v19; // [rsp+78h] [rbp+10h] BYREF
  UFG::qWiseSymbol *p_result; // [rsp+80h] [rbp+18h]

  mActionContext = this->mActionContext;
  if ( mActionContext )
  {
    v3 = BYTE5(this->m_Track[1].mResourceOwner) != 0;
    IsAnyLocalPlayer = UFG::IsAnyLocalPlayer(mActionContext->mSimObject.m_pPointer);
    if ( v3 )
    {
      if ( !IsAnyLocalPlayer )
        return;
    }
    else if ( IsAnyLocalPlayer )
    {
      return;
    }
    v5 = UFG::IsAnyLocalPlayer(this->mActionContext->mSimObject.m_pPointer)
       ? (UFG::SimObjectCharacter *)this->mActionContext->mSimObject.m_pPointer
       : UFG::GetLocalPlayer();
    if ( v5 )
    {
      m_Flags = v5->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        v7 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v5);
      else
        v7 = (UFG::CharacterSubjectComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                              ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v5,
                                                  UFG::CharacterSubjectComponent::_TypeUID)
                                              : UFG::SimObject::GetComponentOfType(
                                                  v5,
                                                  UFG::CharacterSubjectComponent::_TypeUID));
      v8 = v7;
      if ( v7 )
      {
        mUniqueID = this->mUniqueID;
        v10 = 0;
        m_Track = this->m_Track;
        if ( BYTE4(m_Track[1].mResourceOwner) )
        {
          v12 = 0;
          while ( 1 )
          {
            if ( v3 )
            {
              if ( UFG::CharacterSubjectComponent::GetContextOverrideFreemanPlayer_ID(v8, v12) == mUniqueID )
              {
                p_result = &result;
                v13 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
                UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(
                  v8,
                  0i64,
                  v12,
                  (UFG::qSymbol)v13,
                  0xFFFFFFFF);
LABEL_26:
                v10 = 1;
              }
            }
            else if ( UFG::CharacterSubjectComponent::GetContextOverrideFreemanNPC_ID(v8, v12) == mUniqueID )
            {
              p_result = &v19;
              v14 = (unsigned int)UFG::qSymbol::qSymbol(&v19, 0xFFFFFFFF);
              UFG::CharacterSubjectComponent::SetContextOverrideFreemanNPC(v8, 0i64, v12, (UFG::qSymbol)v14, 0xFFFFFFFF);
              goto LABEL_26;
            }
            if ( ++v12 >= 4 )
            {
              if ( v10 )
LABEL_35:
                v8->mTypeOverrideFreeman = -1;
              return;
            }
          }
        }
        UFG::CharacterSubjectComponent::GetContextOverride(v8, (UFG::qSymbol *)&v19, (int)m_Track[1].mResourceOwner);
        mResourceOwner = (int)this->m_Track[1].mResourceOwner;
        if ( v3 )
        {
          if ( UFG::CharacterSubjectComponent::GetContextOverrideFreemanPlayer_ID(v8, mResourceOwner) == mUniqueID )
          {
            p_result = &result;
            v16 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(
              v8,
              0i64,
              (int)this->m_Track[1].mResourceOwner,
              (UFG::qSymbol)v16,
              0xFFFFFFFF);
            goto LABEL_35;
          }
        }
        else if ( UFG::CharacterSubjectComponent::GetContextOverrideFreemanNPC_ID(v8, mResourceOwner) == mUniqueID )
        {
          p_result = &result;
          v17 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideFreemanNPC(
            v8,
            0i64,
            (int)this->m_Track[1].mResourceOwner,
            (UFG::qSymbol)v17,
            0xFFFFFFFF);
          goto LABEL_35;
        }
      }
    }
  }
}

// File Line: 530
// RVA: 0x2F5130
void __fastcall SubjectFollowOverridePOITask::Begin(SubjectFollowOverridePOITask *this, ActionContext *context)
{
  int v4; // edi
  bool v5; // al
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObjectCharacter *LocalPlayer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *v9; // rax
  UFG::CharacterSubjectComponent *v10; // rsi
  ITrack *v11; // rcx
  const char *v12; // r8
  _QWORD *p_mResourceOwner; // rcx
  const char *v14; // r8
  UFG::SimObjectGame *v15; // rcx
  __int16 v16; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v19; // r12
  ITrack *m_Track; // rax
  unsigned int v21; // eax
  unsigned int override_right; // ebx
  unsigned int v23; // eax
  unsigned int v24; // ebx
  unsigned int v25; // eax
  ITrack *v26; // rax
  unsigned int v27; // eax
  unsigned int v28; // eax
  UFG::qString result; // [rsp+40h] [rbp-29h] BYREF
  UFG::qString v30; // [rsp+68h] [rbp-1h] BYREF
  UFG::qSymbol v31; // [rsp+D0h] [rbp+67h] BYREF
  UFG::qSymbol *v32; // [rsp+E0h] [rbp+77h] BYREF
  UFG::qSymbol *v33; // [rsp+E8h] [rbp+7Fh]

  v4 = 0;
  this->mActionContext = 0i64;
  v5 = this->m_Track[1].mDisable != 0;
  m_pPointer = context->mSimObject.m_pPointer;
  if ( v5 )
  {
    if ( !UFG::IsAnyLocalPlayer(m_pPointer) )
      return;
  }
  else if ( UFG::IsAnyLocalPlayer(m_pPointer) )
  {
    return;
  }
  if ( UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer) )
    LocalPlayer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  else
    LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v9 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer);
    else
      v9 = (UFG::CharacterSubjectComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                LocalPlayer,
                                                UFG::CharacterSubjectComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                LocalPlayer,
                                                UFG::CharacterSubjectComponent::_TypeUID));
    v10 = v9;
    if ( v9 )
    {
      this->mActionContext = context;
      v11 = this->m_Track + 1;
      v12 = (char *)v11 + ((unsigned __int64)v11->vfptr & 0xFFFFFFFFFFFFFFFEui64);
      if ( ((unsigned __int64)v11->vfptr & 0xFFFFFFFFFFFFFFFEui64) == 0 )
        v12 = BinString::sEmptyString;
      UFG::qString::FormatEx(&result, "Cameras-%s", v12);
      p_mResourceOwner = &this->m_Track[1].mResourceOwner;
      v14 = (char *)p_mResourceOwner + (*p_mResourceOwner & 0xFFFFFFFFFFFFFFFEui64);
      if ( (*p_mResourceOwner & 0xFFFFFFFFFFFFFFFEui64) == 0 )
        v14 = BinString::sEmptyString;
      UFG::qString::FormatEx(&v30, "Cameras-%s", v14);
      v15 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v15
        && ((v16 = v15->m_Flags, (v16 & 0x4000) == 0)
          ? (v16 >= 0
           ? ((v16 & 0x2000) != 0 || (v16 & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     v15,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v15, UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = v15->m_Components.p[20].m_pComponent))
          : (m_pComponent = v15->m_Components.p[20].m_pComponent),
            m_pComponent) )
      {
        v19 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 35i64)
                                 + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                 + 40);
        m_Track = this->m_Track;
        if ( v19 )
        {
          if ( m_Track[1].mBreakPoint )
          {
            v10->mTypeOverrideFreeman = m_Track[1].m_TrackClassNameUID;
            v33 = &v31;
            do
            {
              override_right = (unsigned int)UFG::qSymbol::create_from_string(&v31, v30.mData);
              v23 = (unsigned int)UFG::qSymbol::create_from_string((UFG::qSymbol *)&v32, result.mData);
              UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI(
                v10,
                context,
                v19,
                v4++,
                (UFG::qSymbol)v23,
                (UFG::qSymbol)override_right);
            }
            while ( v4 < 4 );
          }
          else
          {
            v33 = &v31;
            v24 = (unsigned int)UFG::qSymbol::create_from_string(&v31, v30.mData);
            v25 = (unsigned int)UFG::qSymbol::create_from_string((UFG::qSymbol *)&v32, result.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI(
              v10,
              context,
              v19,
              this->m_Track[1].m_TrackClassNameUID,
              (UFG::qSymbol)v25,
              (UFG::qSymbol)v24);
          }
          goto LABEL_49;
        }
        if ( m_Track[1].mBreakPoint )
        {
          v10->mTypeOverrideFreeman = m_Track[1].m_TrackClassNameUID;
          v32 = &v31;
          do
          {
            v21 = (unsigned int)UFG::qSymbol::create_from_string(&v31, result.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(
              v10,
              context,
              v4++,
              (UFG::qSymbol)v21,
              0xFFFFFFFF);
          }
          while ( v4 < 4 );
          goto LABEL_49;
        }
      }
      else
      {
        v26 = this->m_Track;
        if ( v26[1].mBreakPoint )
        {
          v10->mTypeOverrideFreeman = v26[1].m_TrackClassNameUID;
          v32 = &v31;
          do
          {
            v27 = (unsigned int)UFG::qSymbol::create_from_string(&v31, result.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(
              v10,
              context,
              v4++,
              (UFG::qSymbol)v27,
              0xFFFFFFFF);
          }
          while ( v4 < 4 );
          goto LABEL_49;
        }
      }
      v32 = &v31;
      v28 = (unsigned int)UFG::qSymbol::create_from_string(&v31, result.mData);
      UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(
        v10,
        context,
        this->m_Track[1].m_TrackClassNameUID,
        (UFG::qSymbol)v28,
        0xFFFFFFFF);
LABEL_49:
      UFG::qString::~qString(&v30);
      UFG::qString::~qString(&result);
    }
  }
}

// File Line: 595
// RVA: 0x300580
void __fastcall SubjectFollowOverridePOITask::End(SubjectFollowOverridePOITask *this)
{
  ActionContext *mActionContext; // rcx
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObjectCharacter *LocalPlayer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *ComponentOfTypeHK; // rax
  UFG::CharacterSubjectComponent *v7; // rdi
  bool v8; // zf
  int i; // esi
  unsigned int override_right; // ebx
  unsigned int override_left; // eax
  unsigned int v12; // ebx
  unsigned int v13; // eax
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+8h] BYREF
  UFG::qWiseSymbol v15; // [rsp+68h] [rbp+10h] BYREF
  UFG::qWiseSymbol *p_result; // [rsp+70h] [rbp+18h]
  UFG::qWiseSymbol *v17; // [rsp+78h] [rbp+20h]

  mActionContext = this->mActionContext;
  if ( mActionContext )
  {
    m_pPointer = mActionContext->mSimObject.m_pPointer;
    if ( this->m_Track[1].mDisable )
    {
      if ( !UFG::IsAnyLocalPlayer(m_pPointer) )
        return;
    }
    else if ( UFG::IsAnyLocalPlayer(m_pPointer) )
    {
      return;
    }
    if ( UFG::IsAnyLocalPlayer(this->mActionContext->mSimObject.m_pPointer) )
      LocalPlayer = (UFG::SimObjectCharacter *)this->mActionContext->mSimObject.m_pPointer;
    else
      LocalPlayer = UFG::GetLocalPlayer();
    if ( LocalPlayer )
    {
      m_Flags = LocalPlayer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer);
      }
      else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                LocalPlayer,
                                                                UFG::CharacterSubjectComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                                LocalPlayer,
                                                                UFG::CharacterSubjectComponent::_TypeUID);
      }
      v7 = ComponentOfTypeHK;
      if ( ComponentOfTypeHK )
      {
        ComponentOfTypeHK->mTypeOverrideFreeman = -1;
        v8 = this->m_Track[1].mBreakPoint == 0;
        p_result = &result;
        v17 = &v15;
        if ( v8 )
        {
          v12 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          v13 = (unsigned int)UFG::qSymbol::qSymbol(&v15, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI(
            v7,
            0i64,
            0i64,
            this->m_Track[1].m_TrackClassNameUID,
            (UFG::qSymbol)v13,
            (UFG::qSymbol)v12);
        }
        else
        {
          for ( i = 0; i < 4; ++i )
          {
            override_right = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
            override_left = (unsigned int)UFG::qSymbol::qSymbol(&v15, 0xFFFFFFFF);
            UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI(
              v7,
              0i64,
              0i64,
              i,
              (UFG::qSymbol)override_left,
              (UFG::qSymbol)override_right);
          }
        }
      }
    }
  }
}

// File Line: 625
// RVA: 0x2F4E70
void __fastcall SubjectFollowOverrideChooseTask::Begin(SubjectFollowOverrideChooseTask *this, ActionContext *context)
{
  int v4; // ebx
  bool v5; // al
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObjectCharacter *LocalPlayer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *v9; // rax
  UFG::CharacterSubjectComponent *v10; // rdi
  ITrack *v11; // rcx
  const char *v12; // r8
  _QWORD *p_mResourceOwner; // rcx
  const char *v14; // r8
  unsigned int *p_m_TrackClassNameUID; // rcx
  const char *v16; // rdx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  const char *v18; // rdx
  ITrack *m_Track; // rax
  UFG::qSymbol left; // [rsp+40h] [rbp-59h] BYREF
  UFG::qSymbol v21; // [rsp+44h] [rbp-55h] BYREF
  UFG::qSymbol v22; // [rsp+48h] [rbp-51h] BYREF
  UFG::qSymbol v23; // [rsp+4Ch] [rbp-4Dh] BYREF
  UFG::qSymbol v24; // [rsp+50h] [rbp-49h] BYREF
  UFG::qSymbol *v25; // [rsp+58h] [rbp-41h]
  UFG::qSymbol *v26; // [rsp+60h] [rbp-39h]
  UFG::qSymbol *p_left; // [rsp+68h] [rbp-31h]
  UFG::qSymbol *v28; // [rsp+70h] [rbp-29h]
  __int64 v29; // [rsp+78h] [rbp-21h]
  UFG::qString v30; // [rsp+80h] [rbp-19h] BYREF
  UFG::qString result; // [rsp+A8h] [rbp+Fh] BYREF
  UFG::qSymbol v32; // [rsp+100h] [rbp+67h] BYREF
  UFG::qSymbol v33; // [rsp+110h] [rbp+77h] BYREF
  UFG::qSymbol v34; // [rsp+118h] [rbp+7Fh] BYREF

  v29 = -2i64;
  v4 = 0;
  this->mActionContext = 0i64;
  v5 = BYTE5(this->m_Track[1].mMasterRate.expression.mOffset) != 0;
  m_pPointer = context->mSimObject.m_pPointer;
  if ( v5 )
  {
    if ( !UFG::IsAnyLocalPlayer(m_pPointer) )
      return;
  }
  else if ( UFG::IsAnyLocalPlayer(m_pPointer) )
  {
    return;
  }
  if ( UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer) )
    LocalPlayer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  else
    LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v9 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer);
    else
      v9 = (UFG::CharacterSubjectComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                LocalPlayer,
                                                UFG::CharacterSubjectComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                LocalPlayer,
                                                UFG::CharacterSubjectComponent::_TypeUID));
    v10 = v9;
    if ( v9 )
    {
      this->mActionContext = context;
      v11 = this->m_Track + 1;
      v12 = (char *)v11 + ((unsigned __int64)v11->vfptr & 0xFFFFFFFFFFFFFFFEui64);
      if ( ((unsigned __int64)v11->vfptr & 0xFFFFFFFFFFFFFFFEui64) == 0 )
        v12 = BinString::sEmptyString;
      UFG::qString::FormatEx(&result, "Cameras-%s", v12);
      p_mResourceOwner = &this->m_Track[1].mResourceOwner;
      v14 = (char *)p_mResourceOwner + (*p_mResourceOwner & 0xFFFFFFFFFFFFFFFEui64);
      if ( (*p_mResourceOwner & 0xFFFFFFFFFFFFFFFEui64) == 0 )
        v14 = BinString::sEmptyString;
      UFG::qString::FormatEx(&v30, "Cameras-%s", v14);
      UFG::qSymbol::create_from_string(&v21, result.mData);
      UFG::qSymbol::create_from_string(&v24, v30.mData);
      p_m_TrackClassNameUID = &this->m_Track[1].m_TrackClassNameUID;
      v16 = (char *)p_m_TrackClassNameUID + (*(_QWORD *)p_m_TrackClassNameUID & 0xFFFFFFFFFFFFFFFEui64);
      if ( (*(_QWORD *)p_m_TrackClassNameUID & 0xFFFFFFFFFFFFFFFEui64) == 0 )
        v16 = BinString::sEmptyString;
      UFG::qSymbol::create_from_string(&v23, v16);
      p_mMasterRate = &this->m_Track[1].mMasterRate;
      v18 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) == 0 )
        v18 = BinString::sEmptyString;
      UFG::qSymbol::create_from_string(&v22, v18);
      m_Track = this->m_Track;
      if ( BYTE4(m_Track[1].mMasterRate.expression.mOffset) )
      {
        v10->mTypeOverrideFreeman = m_Track[1].mMasterRate.expression.mOffset;
        v25 = &v32;
        v26 = &v33;
        v28 = &v34;
        p_left = &left;
        do
        {
          v32.mUID = v22.mUID;
          v33.mUID = v23.mUID;
          v34.mUID = v24.mUID;
          left.mUID = v21.mUID;
          UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerChoose(
            v10,
            context,
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
        p_left = &v32;
        v28 = &v33;
        v26 = &v34;
        v25 = &left;
        v32.mUID = v22.mUID;
        v33.mUID = v23.mUID;
        v34.mUID = v24.mUID;
        left.mUID = v21.mUID;
        UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerChoose(
          v10,
          context,
          this->m_Track[1].mMasterRate.expression.mOffset,
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
  ActionContext *mActionContext; // rcx
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObjectCharacter *LocalPlayer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *ComponentOfTypeHK; // rax
  UFG::CharacterSubjectComponent *v7; // rdi
  int v8; // ebx
  UFG::qSymbol left; // [rsp+40h] [rbp-30h] BYREF
  __int64 v10; // [rsp+48h] [rbp-28h]
  UFG::qSymbol *v11; // [rsp+50h] [rbp-20h]
  UFG::qSymbol *v12; // [rsp+58h] [rbp-18h]
  UFG::qSymbol *v13; // [rsp+60h] [rbp-10h]
  UFG::qSymbol *p_left; // [rsp+68h] [rbp-8h]
  UFG::qWiseSymbol result; // [rsp+90h] [rbp+20h] BYREF
  UFG::qSymbol v16; // [rsp+98h] [rbp+28h] BYREF
  UFG::qSymbol v17; // [rsp+A0h] [rbp+30h] BYREF
  UFG::qSymbol v18; // [rsp+A8h] [rbp+38h] BYREF

  v10 = -2i64;
  mActionContext = this->mActionContext;
  if ( mActionContext )
  {
    m_pPointer = mActionContext->mSimObject.m_pPointer;
    if ( BYTE5(this->m_Track[1].mMasterRate.expression.mOffset) )
    {
      if ( !UFG::IsAnyLocalPlayer(m_pPointer) )
        return;
    }
    else if ( UFG::IsAnyLocalPlayer(m_pPointer) )
    {
      return;
    }
    if ( UFG::IsAnyLocalPlayer(this->mActionContext->mSimObject.m_pPointer) )
      LocalPlayer = (UFG::SimObjectCharacter *)this->mActionContext->mSimObject.m_pPointer;
    else
      LocalPlayer = UFG::GetLocalPlayer();
    if ( LocalPlayer )
    {
      m_Flags = LocalPlayer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer);
      }
      else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                LocalPlayer,
                                                                UFG::CharacterSubjectComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                                LocalPlayer,
                                                                UFG::CharacterSubjectComponent::_TypeUID);
      }
      v7 = ComponentOfTypeHK;
      if ( ComponentOfTypeHK )
      {
        UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
        v7->mTypeOverrideFreeman = -1;
        if ( BYTE4(this->m_Track[1].mMasterRate.expression.mOffset) )
        {
          v8 = 0;
          v11 = &v16;
          v12 = &v17;
          v13 = &v18;
          p_left = &left;
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
          p_left = &v16;
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
            this->m_Track[1].mMasterRate.expression.mOffset,
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
  ITrack *m_Track; // rax
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObjectCharacter *LocalPlayer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *v8; // rax
  UFG::CharacterSubjectComponent *v9; // rdi
  ITrack *v10; // rax
  ITrack *v11; // rax
  ITrack *v12; // r9
  ITrack *v13; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::FollowCameraComponent *ComponentOfType; // rax
  ITrack *v16; // rax
  UFG::SimObject *v17; // rcx
  UFG::FollowCameraComponent *v18; // rax
  UFG::SimObject *v19; // rcx
  UFG::ChaseCameraComponent *v20; // rax

  m_Track = this->m_Track;
  m_pPointer = context->mSimObject.m_pPointer;
  if ( *((_BYTE *)&m_Track[1].mMasterRate.value + 6) )
  {
    if ( !UFG::IsAnyLocalPlayer(m_pPointer) )
      return;
  }
  else if ( UFG::IsAnyLocalPlayer(m_pPointer) )
  {
    return;
  }
  if ( UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer) )
    LocalPlayer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  else
    LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v8 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer);
    else
      v8 = (UFG::CharacterSubjectComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                LocalPlayer,
                                                UFG::CharacterSubjectComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                LocalPlayer,
                                                UFG::CharacterSubjectComponent::_TypeUID));
    v9 = v8;
    if ( v8 )
    {
      v10 = this->m_Track;
      if ( LOBYTE(v10[1].mMasterRate.value) && !BYTE1(v10[1].mMasterRate.value) )
        UFG::CharacterSubjectComponent::SetGotoRise(
          v9,
          *(float *)&v10[1].vfptr,
          *((float *)&v10[1].vfptr + 1),
          *(float *)&v10[1].mResourceOwner);
      v11 = this->m_Track;
      if ( BYTE2(v11[1].mMasterRate.value) )
        UFG::CharacterSubjectComponent::SetGotoRadius(
          v9,
          *((float *)&v11[1].mResourceOwner + 1),
          *(float *)&v11[1].m_TrackClassNameUID,
          *(float *)&v11[1].mBreakPoint);
      v12 = this->m_Track;
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
      v13 = this->m_Track;
      if ( LOBYTE(v13[1].mMasterRate.value) )
      {
        if ( BYTE1(v13[1].mMasterRate.value) )
        {
          m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
          if ( m_pSimObject )
          {
            ComponentOfType = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pSimObject,
                                                              UFG::FollowCameraComponent::_TypeUID);
            if ( ComponentOfType )
              UFG::FollowCameraComponent::GotoRiseSnap(ComponentOfType, *(float *)&this->m_Track[1].vfptr);
          }
        }
      }
      v16 = this->m_Track;
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
              (float)(*(float *)&this->m_Track[1].mMasterRate.text.mOffset * 3.1415927) * 0.0055555557,
              *((_BYTE *)&this->m_Track[1].mMasterRate.value + 4) != 0);
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
              (float)(*(float *)&this->m_Track[1].mMasterRate.text.mOffset * 3.1415927) * 0.0055555557,
              *((_BYTE *)&this->m_Track[1].mMasterRate.value + 4) != 0);
        }
      }
    }
  }
}

// File Line: 765
// RVA: 0x2EA2C0
void __fastcall CameraFollowTargetTask::Begin(CameraFollowTargetTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rbx
  __int64 vfptr_low; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v8; // cx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  UFG::CharacterAnimationComponent *v10; // rdi
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *v12; // rsi
  Creature *mCreature; // rdi
  int BoneID; // eax

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  vfptr_low = LODWORD(this->m_Track[1].vfptr);
  if ( (_DWORD)vfptr_low != 1 )
  {
    if ( !m_pPointer )
      return;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
      m_pPointer = *(UFG::SimObjectCVBase **)(56i64
                                            * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + vfptr_low + 8)
                                            + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                            + 40);
  }
  if ( m_pPointer )
  {
    v8 = m_pPointer->m_Flags;
    if ( (v8 & 0x4000) != 0 || v8 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (v8 & 0x2000) != 0 )
    {
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else if ( (v8 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
    v10 = ComponentOfType;
    if ( ComponentOfType )
    {
      m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
      if ( m_pSimObject )
      {
        v12 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                              m_pSimObject,
                                              UFG::ScriptCameraComponent::_TypeUID);
        if ( v12 )
        {
          mCreature = v10->mCreature;
          if ( mCreature->mPose.mRigHandle.mData
            && (BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, HIDWORD(this->m_Track[1].vfptr)),
                BoneID >= 0) )
          {
            UFG::ScriptCameraComponent::SetCameraCreature(v12, mCreature, BoneID);
          }
          else
          {
            UFG::ScriptCameraComponent::SetTarget(v12, m_pPointer->m_pTransformNodeComponent);
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
  UFG::SimObject *m_pSimObject; // rcx

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
    UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
}

