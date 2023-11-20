// File Line: 90
// RVA: 0x14E90D0
__int64 dynamic_initializer_for__UFG::GameStateDebug::PrintChannel__()
{
  UFG::qString::qString(&stru_14207B020);
  return atexit(dynamic_atexit_destructor_for__UFG::GameStateDebug::PrintChannel__);
}

// File Line: 205
// RVA: 0x411820
void __fastcall GameStateHKBase::OnPreUpdate(GameStateHKBase *this, float fRealTimeDelta)
{
  GameStateHKBase *v2; // rbx
  float deltaTime; // xmm7_4
  UFG::ObjectResourceManager *v4; // rax
  UFG::PartDatabase *v5; // rax
  UFG::UIScreenTextureManager *v6; // rax
  UFG *v7; // rcx
  AMD_HD3D *v8; // rcx
  AMD_HD3D *v9; // rcx
  bool v10; // al
  UFG::DebugGUIManager *v11; // rax
  UFG::GameStatTracker *v12; // rax
  UFG::ProgressionTracker *v13; // rax
  UFG::OnlineManager *v14; // rax
  UFG::OSuiteManager *v15; // rax
  UFG::OSuiteDBLogger *v16; // rax
  UFG::OSuiteLeaderboardManager *v17; // rax
  hkGeometryUtils::IVertices *v18; // rax
  int v19; // edx
  int v20; // er8
  UFG::WebSystem *v21; // rax
  signed __int64 v22; // rdi
  UFG::BaseCameraComponent *v23; // rax
  UFG::BaseCameraComponent *v24; // rax
  float v25; // xmm1_4
  float v26; // xmm2_4
  UFG::BaseCameraComponent *v27; // rax
  _DWORD *v28; // rax
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
  UFG::GameStateVtbl *v40; // rax
  char v41; // si
  _BOOL8 v42; // r14
  UFG::SimObjectCharacter *v43; // rbx
  UFG::SimComponent *v44; // rax
  __int64 v45; // rax
  float v46; // xmm1_4
  float v47; // xmm2_4
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **v48; // rsi
  float *v49; // rbx
  UFG::BaseCameraComponent *v50; // rax
  float *v51; // rax
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  UFG::qVector3 *v55; // rax
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm1_4
  UFG::TransformNodeComponent *v59; // rbx
  float v60; // xmm1_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // xmm2_4
  __m128 v64; // xmm4
  float v65; // xmm5_4
  __m128 v66; // xmm2
  float v67; // xmm0_4
  int v68; // eax
  float v69; // xmm6_4
  UFG::BaseCameraComponent *v70; // rcx
  bool is_ingame[4]; // [rsp+38h] [rbp-19h]
  float v72; // [rsp+3Ch] [rbp-15h]
  float v73; // [rsp+40h] [rbp-11h]
  UFG::qVector3 velocity; // [rsp+48h] [rbp-9h]
  UFG::qVector3 direction; // [rsp+58h] [rbp+7h]
  UFG::qVector3 camera_direction; // [rsp+68h] [rbp+17h]
  UFG::qVector3 result; // [rsp+78h] [rbp+27h]

  v2 = this;
  deltaTime = fRealTimeDelta;
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
  v10 = UFG::ProfileWizard::IsProfiling();
  _((AMD_HD3D *)v10);
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
  v23 = UFG::Director::Get()->mCurrentCamera;
  if ( v23 )
    v24 = (UFG::BaseCameraComponent *)((char *)v23 + 80);
  else
    v24 = 0i64;
  v25 = v24->mCamera.mView.v2.y;
  v26 = v24->mCamera.mView.v2.z;
  *(float *)is_ingame = v24->mCamera.mView.v2.x;
  v72 = v25;
  v73 = v26;
  v27 = UFG::Director::Get()->mCurrentCamera;
  if ( v27 )
    v28 = (_DWORD *)&v27->mCamera.mFOVOffset;
  else
    v28 = 0i64;
  v29 = v28[42] ^ _xmm[0];
  v30 = v28[41] ^ _xmm[0];
  LODWORD(direction.x) = v28[40] ^ _xmm[0];
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
  v40 = v2->vfptr;
  v41 = 1;
  velocity.x = v39;
  velocity.y = v37;
  velocity.z = v38;
  v42 = v40->ModeIsSet((UFG::GameState *)&v2->vfptr, eGSM_DEBUG_CAM);
  if ( !NISManager::GetInstance() || NISManager::GetInstance()->mState == STATE_INVALID )
  {
    v43 = UFG::GetLocalPlayer();
    if ( (_BYTE)v42 )
    {
      v44 = UFG::GetCurrentGameCamera();
      if ( v44 )
      {
        v45 = ((__int64 (__fastcall *)(UFG::SimComponent *))v44->vfptr[35].__vecDelDtor)(v44);
        v46 = *(float *)(v45 + 4);
        v47 = *(float *)(v45 + 8);
        *(float *)is_ingame = *(float *)v45;
        v72 = v46;
        v73 = v47;
      }
      v41 = 0;
    }
    if ( (unsigned __int8)UFG::GameEditor::IsActive() )
    {
      v48 = UFG::GameEditor::GetActiveView();
      v49 = (float *)v48[10];
      if ( UFG::Editor::Camera::UsingGameCamera((UFG::Editor::Camera *)v48[10]) )
      {
        v50 = UFG::Director::Get()->mCurrentCamera;
        if ( v50 )
          v51 = &v50->mCamera.mFOVOffset;
        else
          v51 = 0i64;
        v52 = v51[44];
        v53 = v51[45];
        v54 = v51[46];
      }
      else
      {
        v52 = v49[44];
        v53 = v49[45];
        v54 = v49[46];
      }
      *(float *)is_ingame = v52;
      v72 = v53;
      v73 = v54;
      v55 = UFG::Editor::Camera::GetDirForward((UFG::Editor::Camera *)v48[10], &result);
      v56 = v55->y;
      v57 = v55->z;
      direction.x = v55->x;
      direction.y = v56;
      v58 = UFG::qVector3::msZero.y;
      velocity.x = UFG::qVector3::msZero.x;
      velocity.z = UFG::qVector3::msZero.z;
      direction.z = v57;
      goto LABEL_38;
    }
    if ( v43 && (UFG::SectionEditor::mUsePlayerAsSectionPOV || v41) )
    {
      v59 = v43->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v59);
      v60 = up_offset.y + v59->mWorldTransform.v3.y;
      v61 = up_offset.z + v59->mWorldTransform.v3.z;
      *(float *)is_ingame = up_offset.x + v59->mWorldTransform.v3.x;
      v72 = v60;
      v73 = v61;
      UFG::TransformNodeComponent::UpdateWorldTransform(v59);
      v62 = v59->mWorldTransform.v0.y;
      v63 = v59->mWorldTransform.v0.z;
      direction.x = v59->mWorldTransform.v0.x;
      direction.y = v62;
      direction.z = v63;
LABEL_37:
      UFG::TransformNodeComponent::UpdateWorldTransform(v59);
      v67 = v59->mWorldVelocity.x;
      v58 = v59->mWorldVelocity.y;
      velocity.z = v59->mWorldVelocity.z;
      velocity.x = v67;
LABEL_38:
      velocity.y = v58;
      goto LABEL_39;
    }
    if ( !UFG::IsCameraUsingHighZoom() )
    {
      if ( !v43 )
        goto LABEL_39;
      v59 = v43->m_pTransformNodeComponent;
      goto LABEL_37;
    }
    v64 = (__m128)LODWORD(direction.y);
    v65 = 0.0;
    v66 = v64;
    v66.m128_f32[0] = (float)((float)(v64.m128_f32[0] * v64.m128_f32[0]) + (float)(direction.x * direction.x))
                    + (float)(direction.z * direction.z);
    if ( v66.m128_f32[0] != 0.0 )
      v65 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v66));
    *(float *)is_ingame = *(float *)is_ingame
                        + (float)((float)(direction.x * v65) * UFG::gSniperModeStreamingOffsetDistance);
    v72 = v72 + (float)((float)(direction.y * v65) * UFG::gSniperModeStreamingOffsetDistance);
  }
LABEL_39:
  v68 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  UFG::SectionChooser::AddPOV(
    (UFG::qVector3 *)is_ingame,
    &direction,
    &camera_direction,
    &velocity,
    deltaTime,
    0i64,
    7u,
    v68 == uidGameStateInGame_3);
  UFG::DataStreamer::Service(deltaTime);
  Render::StreamingLoopProcessQueuedOperations(0, 0);
  v69 = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
  v70 = UFG::Director::Get()->mCurrentCamera;
  if ( v70 )
    v22 = (signed __int64)&v70->mCamera;
  UpdateSectionEffects((UFG::qVector3 *)(v22 + 176), v69);
}

// File Line: 404
// RVA: 0x411430
void __fastcall GameStateHKBase::OnPostUpdate(GameStateHKBase *this, float fRealTimeDelta)
{
  AMD_HD3D *v2; // rcx
  AMD_HD3D *v3; // rcx
  UFG::GameStatTracker *v4; // rax
  UFG::TiDo *v5; // rax
  AMD_HD3D *v6; // rcx
  bool v7; // bl
  UFG::qSymbol parentSetName; // [rsp+70h] [rbp+18h]
  UFG::qSymbol result; // [rsp+78h] [rbp+20h]

  _((AMD_HD3D *)this);
  _(v2);
  _(v3);
  UFG::RenderWorld::UpdateViews(fRealTimeDelta);
  UFG::RenderWorld::Update(fRealTimeDelta);
  v4 = UFG::GameStatTracker::Instance();
  Render::DisplayCalibration::msBrightness = (float)((float)(signed int)UFG::GameStatTracker::GetStat(v4, Gamma) * 2.0)
                                           * 0.0099999998;
  if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
  {
    v5 = UFG::TiDo::GetInstance();
    ((void (__fastcall *)(UFG::TiDo *))v5->vfptr->UpdateFrame)(v5);
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
    UFG::SpawnInfoInterface::SpawnObject(&result, &parentSetName, 0, 0i64, 0i64, 0i64);
    UFG::SkookumMgr::InvokeWorldCoroutine((UFG::qSymbol *)&qSymbol__on_change_player.mUID, 0i64);
  }
  if ( !(`Broadcaster::GetBroadcaster::`2::`local static guard & 1) )
  {
    `Broadcaster::GetBroadcaster::`2::`local static guard |= 1u;
    Broadcaster::Broadcaster(&`Broadcaster::GetBroadcaster::`2::singleton);
    atexit(`Broadcaster::GetBroadcaster::`2::`dynamic atexit destructor for singleton);
  }
  Broadcaster::Update(&`Broadcaster::GetBroadcaster::`2::singleton);
  UFG::RenderWorld::UpdateScreenShot();
}

