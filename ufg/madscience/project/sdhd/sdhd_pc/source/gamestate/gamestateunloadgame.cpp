// File Line: 50
// RVA: 0x14F2030
__int64 dynamic_initializer_for__set_state_global_main_menu__()
{
  set_state_global_main_menu.mUID = UFG::qWiseSymbolUIDFromString("set_state_global_main_menu", 0x811C9DC5);
  _((AMD_HD3D *)set_state_global_main_menu.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__set_state_global_main_menu__);
}

// File Line: 72
// RVA: 0x410C90
void __fastcall UFG::GameStateUnloadGame::OnEnter(UFG::GameStateUnloadGame *this, float deltaSeconds)
{
  UFG::GameEditor *v2; // rcx
  UFG::TiDo *Instance; // rax
  UFG::TiDo *v4; // rax
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h] BYREF

  if ( UFG::GameEditor::IsActive() )
    UFG::GameEditor::Deactivate(v2);
  UFG::RenderWorld::SetRenderWorld(0);
  UFG::qWiseSymbol::create_from_string(&result, "loadfinish");
  UFG::qWiseSymbol::operator=(&stru_14207B268, &result);
  if ( byte_14207B260 != 1 )
  {
    UFG::qWiseSymbol::operator=(&stru_14207B264, &set_state_global_main_menu);
    if ( (_BYTE)word_14207B26C )
    {
      if ( byte_14207B260 && UFG::TiDo::GetIsInstantiated() )
      {
        Instance = UFG::TiDo::GetInstance();
        Instance->vfptr->LoadingGameEnd(Instance, &stru_14207B268);
      }
      if ( (_BYTE)word_14207B26C )
      {
        UFG::qWiseSymbol::operator=(&stru_14207B264, &set_state_global_main_menu);
        if ( UFG::TiDo::GetIsInstantiated() )
        {
          v4 = UFG::TiDo::GetInstance();
          v4->vfptr->LoadingGameStart(v4, &stru_14207B264);
        }
      }
    }
    byte_14207B260 = 1;
  }
  UFG::UIHK_NISOverlay::ShowCurtains(0.0, 1);
  _((AMD_HD3D *)result.mUID);
}

// File Line: 86
// RVA: 0x4133D0
void __fastcall UFG::GameStateUnloadGame::OnUpdate(UFG::GameStateUnloadGame *this, float deltaSeconds)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::ObjectResourceManager *v3; // rax
  UFG::CopSystem *v4; // rax
  UFG::SimObjectCharacter *v5; // rbx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rax
  UFG::SimObject *v8; // rcx
  UFG::SimComponent *v9; // rax
  UFG::GameStatTracker *v10; // rax
  UFG *v11; // rcx
  UFG::RadarSystem *v12; // rax
  UFG *v13; // rcx

  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_GAME_UNLOADING_14, 0xFFFFFFFF);
  UFG::RenderWorld::SetRenderWorld(0);
  v2 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::UnloadGraph(v2);
  v3 = UFG::ObjectResourceManager::Instance();
  UFG::ObjectResourceManager::ReleaseAllAmbientPreloads(v3);
  v4 = UFG::CopSystem::Instance();
  ((void (__fastcall *)(UFG::CopSystem *))v4->vfptr[2].__vecDelDtor)(v4);
  v5 = LocalPlayer;
  if ( LocalPlayer )
  {
    UFG::SimObjectUtility::ReinitializeSimObject(LocalPlayer, 1, 0);
    m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
    if ( m_pSimObject )
    {
      ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pSimObject,
                                                        UFG::ScriptCameraComponent::_TypeUID);
      if ( ComponentOfType )
      {
        UFG::ScriptCameraComponent::ReleaseCamera(ComponentOfType, 0);
        UFG::ColourCubeArray::Remove(&UFG::ColourCubeMgr::mActiveColourCubes, UFG::TSCamera::gCCTVColourCubeUID);
      }
    }
    v8 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
    if ( v8 )
    {
      v9 = UFG::SimObject::GetComponentOfType(v8, UFG::FollowCameraComponent::_TypeUID);
      if ( v9 )
        v9->vfptr[16].__vecDelDtor(v9, (unsigned int)v5);
    }
  }
  v10 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::Reset(v10, 0);
  UFG::SkookumMgr::EndScene();
  UFG::PedSpawnManager::DeInit(UFG::gpPedSpawnManager);
  UFG::ObjectResourceManager::Instance()->mEntityStates[0].mUpdateRequired = 1;
  UnloadCurrentLocation();
  UFG::CloseSim(v11);
  UFG::UIMapBlipManager::Clear(UFG::UIHKScreenHud::mIconManager);
  UFG::ActionTreeComponentBase::DeleteAllMemory();
  v12 = UFG::RadarSystem::Instance();
  UFG::RadarSystem::Clear(v12);
  UFG::PhysicsSystem::ResetScene((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, FullReset);
  SetUpCameraForFERender(v13);
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateFE_3);
}

// File Line: 169
// RVA: 0x410F90
void __fastcall UFG::GameStateUnloadGame::OnExit(UFG::GameStateUnloadGame *this, float deltaSeconds)
{
  UFG::qWiseSymbol *null; // rax
  UFG::TiDo *Instance; // rax
  UFG::UI *v4; // rcx
  UFG *v5; // rcx
  UFG *v6; // rcx

  UFG::qWiseSymbol::operator=(&stru_14207B268, &set_state_global_main_menu);
  null = UFG::qWiseSymbol::get_null();
  if ( byte_14207B260 )
  {
    UFG::qWiseSymbol::operator=(&stru_14207B264, null);
    if ( (_BYTE)word_14207B26C && byte_14207B260 && UFG::TiDo::GetIsInstantiated() )
    {
      Instance = UFG::TiDo::GetInstance();
      Instance->vfptr->LoadingGameEnd(Instance, &stru_14207B268);
    }
    byte_14207B260 = 0;
  }
  UFG::UIHK_NISOverlay::HideCurtains(2.5, 1);
  UFG::UI::ResetGameplayInput(v4);
  UFG::PhysicsSystem::FlushWorldBoundaries((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance);
  UFG::StreamPool_ClearAllCachedData(v5);
  UFG::MemoryUtil_DumpUnmarked("UNLOAD_GAME OnExit");
  UFG::MemoryUtil_MarkAllPools(v6);
  ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(UFG::TiDo::m_pInstance, 2i64);
}

// File Line: 200
// RVA: 0x411630
void __fastcall UFG::GameStateUnloadGame::OnPostUpdate(UFG::GameStateUnloadGame *this, float deltaSeconds)
{
  UFG::ObjectResourceManager *v2; // rax
  UFG::PartDatabase *v3; // rax

  v2 = UFG::ObjectResourceManager::Instance();
  UFG::ObjectResourceManager::FlushResources(v2, 1);
  v3 = UFG::PartDatabase::Instance();
  UFG::PartDatabase::FlushParts(v3, 1);
  UFG::DataStreamer::Service(deltaSeconds);
}

