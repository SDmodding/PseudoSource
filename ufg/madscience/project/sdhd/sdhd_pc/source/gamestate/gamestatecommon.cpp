// File Line: 90
// RVA: 0x14E90D0
__int64 dynamic_initializer_for__UFG::GameStateDebug::PrintChannel__()
{
  UFG::qString::qString(&stru_14207B020);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::GameStateDebug::PrintChannel__);
}

// File Line: 205
// RVA: 0x411820
void __fastcall GameStateHKBase::OnPreUpdate(GameStateHKBase *this, float fRealTimeDelta)
{
  UFG::ObjectResourceManager *v4; // rax
  UFG::PartDatabase *v5; // rax
  UFG::UIScreenTextureManager *v6; // rax
  UFG *v7; // rcx
  AMD_HD3D *v8; // rcx
  AMD_HD3D *v9; // rcx
  bool IsProfiling; // al
  UFG::DebugGUIManager *v11; // rax
  UFG::GameStatTracker *v12; // rax
  UFG::ProgressionTracker *v13; // rax
  UFG::OnlineManager *v14; // rax
  UFG::OSuiteManager *v15; // rax
  UFG::OSuiteDBLogger *v16; // rax
  UFG::OSuiteLeaderboardManager *v17; // rax
  hkGeometryUtils::IVertices *v18; // rax
  int v19; // edx
  int v20; // r8d
  UFG::WebSystem *v21; // rax
  UFG::Camera *v22; // rdi
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::BaseCameraComponent *p_mCamera; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::BaseCameraComponent *v27; // rax
  _DWORD *p_mFOVOffset; // rax
  int v29; // xmm2_4
  int v30; // xmm1_4
  UFG::BaseCameraComponent *v31; // rax
  _DWORD *v32; // rax
  int v33; // xmm2_4
  int v34; // xmm1_4
  UFG::BaseCameraComponent *v35; // rax
  float *v36; // rax
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  UFG::GameStateVtbl *vfptr; // rax
  char v41; // si
  bool v42; // r14
  UFG::SimObjectCharacter *LocalPlayer; // rbx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *CurrentGameCamera; // rax
  __int64 v45; // rax
  float v46; // xmm1_4
  float v47; // xmm2_4
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **ActiveView; // rsi
  UFG::Editor::Camera *v49; // rbx
  UFG::BaseCameraComponent *v50; // rax
  float *v51; // rax
  float x; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  UFG::qVector3 *DirForward; // rax
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm1_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v60; // xmm1_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // xmm2_4
  float v64; // xmm5_4
  __m128 y_low; // xmm2
  float v66; // xmm0_4
  int CurrentState; // eax
  float m_SecondsSinceMidnight; // xmm6_4
  UFG::BaseCameraComponent *v69; // rcx
  UFG::qVector3 is_ingame; // [rsp+38h] [rbp-19h] BYREF
  UFG::qVector3 velocity; // [rsp+48h] [rbp-9h] BYREF
  UFG::qVector3 direction; // [rsp+58h] [rbp+7h] BYREF
  UFG::qVector3 camera_direction; // [rsp+68h] [rbp+17h] BYREF
  UFG::qVector3 result; // [rsp+78h] [rbp+27h] BYREF

  _((AMD_HD3D *)this);
  Render::ISoftbody::DeleteQueuedBuffers(&Render::gSoftbody);
  v4 = UFG::ObjectResourceManager::Instance();
  UFG::ObjectResourceManager::FlushResources(v4, 0);
  v5 = UFG::PartDatabase::Instance();
  UFG::PartDatabase::FlushParts(v5, 0);
  v6 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::Update(v6, fRealTimeDelta);
  UFG::qFileService(v7);
  _(v8);
  _(v9);
  IsProfiling = UFG::ProfileWizard::IsProfiling();
  _((AMD_HD3D *)IsProfiling);
  PoseTaskSubmission::BeginFrame();
  v11 = UFG::DebugGUIManager::Instance();
  UFG::DebugGUIManager::Update(v11, fRealTimeDelta);
  v12 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::Update(v12, fRealTimeDelta);
  v13 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::Update(v13, fRealTimeDelta);
  v14 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::Update(v14, fRealTimeDelta);
  UFG::DataSynchronizer::Update(fRealTimeDelta);
  v15 = UFG::OSuiteManager::Instance();
  UFG::OSuiteManager::Update(v15, fRealTimeDelta);
  v16 = UFG::OSuiteDBLogger::Instance();
  UFG::OSuiteDBLogger::Update(v16, fRealTimeDelta);
  v17 = UFG::OSuiteLeaderboardManager::Instance();
  UFG::OSuiteLeaderboardManager::Update(v17, fRealTimeDelta);
  v18 = (hkGeometryUtils::IVertices *)UFG::OSuiteMessenger::Instance();
  Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v18, v19, v20);
  v21 = UFG::WebSystem::Instance();
  UFG::WebSystem::Update(v21, fRealTimeDelta);
  v22 = 0i64;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mCamera = (UFG::BaseCameraComponent *)&mCurrentCamera->mCamera;
  else
    p_mCamera = 0i64;
  y = p_mCamera->mCamera.mView.v2.y;
  z = p_mCamera->mCamera.mView.v2.z;
  is_ingame.x = p_mCamera->mCamera.mView.v2.x;
  is_ingame.y = y;
  is_ingame.z = z;
  v27 = UFG::Director::Get()->mCurrentCamera;
  if ( v27 )
    p_mFOVOffset = (_DWORD *)&v27->mCamera.mFOVOffset;
  else
    p_mFOVOffset = 0i64;
  v29 = p_mFOVOffset[42] ^ _xmm[0];
  v30 = p_mFOVOffset[41] ^ _xmm[0];
  LODWORD(direction.x) = p_mFOVOffset[40] ^ _xmm[0];
  LODWORD(direction.y) = v30;
  LODWORD(direction.z) = v29;
  v31 = UFG::Director::Get()->mCurrentCamera;
  if ( v31 )
    v32 = (_DWORD *)&v31->mCamera.mFOVOffset;
  else
    v32 = 0i64;
  v33 = v32[42] ^ _xmm[0];
  v34 = v32[41] ^ _xmm[0];
  LODWORD(camera_direction.x) = v32[40] ^ _xmm[0];
  LODWORD(camera_direction.y) = v34;
  LODWORD(camera_direction.z) = v33;
  v35 = UFG::Director::Get()->mCurrentCamera;
  if ( v35 )
    v36 = &v35->mCamera.mFOVOffset;
  else
    v36 = 0i64;
  v37 = v36[149];
  v38 = v36[150];
  v39 = v36[148];
  vfptr = this->vfptr;
  v41 = 1;
  velocity.x = v39;
  velocity.y = v37;
  velocity.z = v38;
  v42 = vfptr->ModeIsSet(this, eGSM_DEBUG_CAM);
  if ( !NISManager::GetInstance() || NISManager::GetInstance()->mState == STATE_INVALID )
  {
    LocalPlayer = UFG::GetLocalPlayer();
    if ( v42 )
    {
      CurrentGameCamera = UFG::GetCurrentGameCamera();
      if ( CurrentGameCamera )
      {
        v45 = ((__int64 (__fastcall *)(UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *))CurrentGameCamera->mPrev[17].mNext)(CurrentGameCamera);
        v46 = *(float *)(v45 + 4);
        v47 = *(float *)(v45 + 8);
        is_ingame.x = *(float *)v45;
        is_ingame.y = v46;
        is_ingame.z = v47;
      }
      v41 = 0;
    }
    if ( UFG::GameEditor::IsActive() )
    {
      ActiveView = UFG::GameEditor::GetActiveView();
      v49 = (UFG::Editor::Camera *)ActiveView[10];
      if ( UFG::Editor::Camera::UsingGameCamera(v49) )
      {
        v50 = UFG::Director::Get()->mCurrentCamera;
        if ( v50 )
          v51 = &v50->mCamera.mFOVOffset;
        else
          v51 = 0i64;
        x = v51[44];
        v53 = v51[45];
        v54 = v51[46];
      }
      else
      {
        x = v49->mCamera.v3.x;
        v53 = v49->mCamera.v3.y;
        v54 = v49->mCamera.v3.z;
      }
      is_ingame.x = x;
      is_ingame.y = v53;
      is_ingame.z = v54;
      DirForward = UFG::Editor::Camera::GetDirForward((UFG::Editor::Camera *)ActiveView[10], &result);
      v56 = DirForward->y;
      v57 = DirForward->z;
      direction.x = DirForward->x;
      direction.y = v56;
      v58 = UFG::qVector3::msZero.y;
      velocity.x = UFG::qVector3::msZero.x;
      velocity.z = UFG::qVector3::msZero.z;
      direction.z = v57;
      goto LABEL_38;
    }
    if ( LocalPlayer && (UFG::SectionEditor::mUsePlayerAsSectionPOV || v41) )
    {
      m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v60 = up_offset.y + m_pTransformNodeComponent->mWorldTransform.v3.y;
      v61 = up_offset.z + m_pTransformNodeComponent->mWorldTransform.v3.z;
      is_ingame.x = up_offset.x + m_pTransformNodeComponent->mWorldTransform.v3.x;
      is_ingame.y = v60;
      is_ingame.z = v61;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v62 = m_pTransformNodeComponent->mWorldTransform.v0.y;
      v63 = m_pTransformNodeComponent->mWorldTransform.v0.z;
      direction.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
      direction.y = v62;
      direction.z = v63;
LABEL_37:
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v66 = m_pTransformNodeComponent->mWorldVelocity.x;
      v58 = m_pTransformNodeComponent->mWorldVelocity.y;
      velocity.z = m_pTransformNodeComponent->mWorldVelocity.z;
      velocity.x = v66;
LABEL_38:
      velocity.y = v58;
      goto LABEL_39;
    }
    if ( !UFG::IsCameraUsingHighZoom() )
    {
      if ( !LocalPlayer )
        goto LABEL_39;
      m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
      goto LABEL_37;
    }
    v64 = 0.0;
    y_low = (__m128)LODWORD(direction.y);
    y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(direction.x * direction.x))
                      + (float)(direction.z * direction.z);
    if ( y_low.m128_f32[0] != 0.0 )
      v64 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
    is_ingame.x = is_ingame.x + (float)((float)(direction.x * v64) * UFG::gSniperModeStreamingOffsetDistance);
    is_ingame.y = is_ingame.y + (float)((float)(direction.y * v64) * UFG::gSniperModeStreamingOffsetDistance);
  }
LABEL_39:
  CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  UFG::SectionChooser::AddPOV(
    &is_ingame,
    &direction,
    &camera_direction,
    &velocity,
    fRealTimeDelta,
    0i64,
    7,
    CurrentState == uidGameStateInGame_3);
  UFG::DataStreamer::Service(fRealTimeDelta);
  Render::StreamingLoopProcessQueuedOperations(0, 0);
  m_SecondsSinceMidnight = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
  v69 = UFG::Director::Get()->mCurrentCamera;
  if ( v69 )
    v22 = &v69->mCamera;
  UpdateSectionEffects((UFG::qVector3 *)&v22->mTransformation.v3, m_SecondsSinceMidnight);
}

// File Line: 404
// RVA: 0x411430
void __fastcall GameStateHKBase::OnPostUpdate(GameStateHKBase *this, float fRealTimeDelta)
{
  AMD_HD3D *v2; // rcx
  AMD_HD3D *v3; // rcx
  UFG::GameStatTracker *v4; // rax
  UFG::TiDo *Instance; // rax
  AMD_HD3D *v6; // rcx
  bool v7; // bl
  UFG::qSymbol parentSetName; // [rsp+70h] [rbp+18h] BYREF
  UFG::qSymbol result; // [rsp+78h] [rbp+20h] BYREF

  _((AMD_HD3D *)this);
  _(v2);
  _(v3);
  UFG::RenderWorld::UpdateViews(fRealTimeDelta);
  UFG::RenderWorld::Update(fRealTimeDelta);
  v4 = UFG::GameStatTracker::Instance();
  Render::DisplayCalibration::msBrightness = (float)((float)(int)UFG::GameStatTracker::GetStat(v4, Gamma) * 2.0)
                                           * 0.0099999998;
  if ( UFG::TiDo::GetIsInstantiated() )
  {
    Instance = UFG::TiDo::GetInstance();
    ((void (__fastcall *)(UFG::TiDo *))Instance->vfptr->UpdateFrame)(Instance);
  }
  _((AMD_HD3D *)UFG::HDDmanager::mInstance);
  _(v6);
  ADeferFunc::invoke_deferred();
  UFG::EventDispatcher::DispatchAllQueuedEvents(&UFG::EventDispatcher::mInstance);
  v7 = UFG::GetLocalPlayer() != 0i64;
  UFG::Simulation::DestroyQueuedSimObjects(&UFG::gSim);
  if ( v7 && !UFG::GetLocalPlayer() )
  {
    UFG::qSymbol::create_from_string(&result, "PlayerOne_Havok");
    UFG::qSymbol::create_from_string(&parentSetName, "object-physical-character-player");
    UFG::SpawnInfoInterface::SpawnObject(&result, &parentSetName, UnReferenced, 0i64, 0i64, 0i64);
    UFG::SkookumMgr::InvokeWorldCoroutine(&qSymbol__on_change_player, 0i64);
  }
  if ( (`Broadcaster::GetBroadcaster::`2::`local static guard & 1) == 0 )
  {
    `Broadcaster::GetBroadcaster::`2::`local static guard |= 1u;
    Broadcaster::Broadcaster(&`Broadcaster::GetBroadcaster::`2::singleton);
    atexit(`Broadcaster::GetBroadcaster::`2::`dynamic atexit destructor for singleton);
  }
  Broadcaster::Update(&`Broadcaster::GetBroadcaster::`2::singleton);
  UFG::RenderWorld::UpdateScreenShot();
}

