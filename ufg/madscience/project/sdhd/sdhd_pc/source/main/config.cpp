// File Line: 43
// RVA: 0x14FA4E0
__int64 dynamic_initializer_for__StartTrack__()
{
  UFG::qString::qString(&StartTrack);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__StartTrack__);
}

// File Line: 123
// RVA: 0x14FA560
__int64 UFG::_dynamic_initializer_for__gSKU__()
{
  UFG::qString::qString(&UFG::gSKU);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSKU__);
}

// File Line: 141
// RVA: 0x14FA540
__int64 dynamic_initializer_for__gDebugResolution__()
{
  UFG::qString::qString(&gDebugResolution);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDebugResolution__);
}

// File Line: 152
// RVA: 0x41F4D0
void InitRunOptions(void)
{
  int v0; // ebx
  UFG::qBaseNodeRB *Value; // rax
  UFG::qBaseNodeRB *v2; // rax
  UFG::qBaseNodeRB *v3; // rax
  UFG::qBaseNodeRB *v4; // rax
  unsigned __int8 v5; // r13
  UFG::qBaseNodeRB *v6; // rax
  UFG::qBaseNodeRB *v7; // rbx
  UFG::qBaseNodeRB *v8; // rbx
  UFG::qBaseNodeRB *v9; // rbx
  UFG::qBaseNodeRB *v10; // rdi
  UFG::qBaseNodeRB *v11; // rsi
  UFG::qBaseNodeRB *v12; // r14
  UFG::qBaseNodeRB *v13; // r15
  UFG::qBaseNodeRB *v14; // r12
  UFG::qBaseNodeRB *v15; // rax
  unsigned __int8 v16; // di
  unsigned __int8 v17; // bl
  UFG::qBaseNodeRB *v18; // rax
  UFG::qBaseNodeRB *v19; // rax
  UFG::qBaseNodeRB *v20; // rax
  char v21; // al
  UFG::HotSwapFileManager *v22; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v29; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v30; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v31; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v32; // rax
  UFG::qString *k; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v35; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v36; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v37; // rax
  UFG::qString *m; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v39; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v40; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v41; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v42; // rax
  char key[40]; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qList<UFG::qString,UFG::qString,1,0> option_list; // [rsp+58h] [rbp-80h] BYREF
  UFG::qList<UFG::qString,UFG::qString,1,0> v45; // [rsp+68h] [rbp-70h] BYREF
  UFG::BuildLabOptions buildlab_options; // [rsp+78h] [rbp-60h] BYREF
  __int64 v47; // [rsp+188h] [rbp+B0h]
  UFG::qString v48; // [rsp+190h] [rbp+B8h] BYREF
  UFG::qString v49; // [rsp+1B8h] [rbp+E0h] BYREF
  UFG::qString v50; // [rsp+1E0h] [rbp+108h] BYREF
  UFG::qString v51; // [rsp+208h] [rbp+130h] BYREF
  unsigned __int8 v52; // [rsp+268h] [rbp+190h]

  v47 = -2i64;
  qmemcpy(key, "61726520796f75206d79206d6f6d6d793f", 34);
  UFG::BuildLabOptions::BuildLabOptions(
    (UFG::BuildLabOptions *)&buildlab_options.mDefaultsFilename,
    "UserOptions.xml",
    LOAD_PROJECT|LOAD_USER,
    key,
    0x22u);
  option_list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&option_list;
  v45.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v45;
  v45.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v45;
  buildlab_options.mProjectFilename.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&buildlab_options;
  option_list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&buildlab_options;
  v0 = 0;
  UFG::BuildLabOptions::GetNames(
    &buildlab_options,
    (UFG::qList<UFG::qString,UFG::qString,1,0> *)&option_list.mNode.mNext,
    "BuildPlatforms",
    "True",
    0i64);
  UFG::BuildLabOptions::GetNames(&buildlab_options, &option_list, "BuildConfigs", "True", 0i64);
  UFG::BuildLabOptions::GetNames(&buildlab_options, &v45, "World", "True", 0i64);
  UFG::BuildLabOptions::GetNames(
    &buildlab_options,
    (UFG::qList<UFG::qString,UFG::qString,1,0> *)&buildlab_options,
    "Audio",
    "True",
    0i64);
  if ( UFG::BuildLabOptions::GetValue(&buildlab_options, "ActivateConfig", 0) )
  {
    UFG::BuildLabOptions::GetValue(&buildlab_options, "PC Shaders", 0);
    g_bShowHelp = UFG::BuildLabOptions::GetValue(&buildlab_options, "ShowHelp", 0);
    UFG::gShowAIDataIssues = 1;
    UFG::SkookumMgr::msAutoBootIDE = UFG::BuildLabOptions::GetValue(&buildlab_options, "Auto-Boot Skookum IDE", 1);
    UFG::gAutoBootEditor = UFG::BuildLabOptions::GetValue(&buildlab_options, "Auto-Boot Editor", 0);
    Value = UFG::BuildLabOptions::GetValue(&buildlab_options, "SKU", "Super");
    UFG::qString::Set(&UFG::gSKU, (const char *)Value);
    g_FontName = (const char *)UFG::BuildLabOptions::GetValue(&buildlab_options, "FontName", 0i64);
    v2 = UFG::BuildLabOptions::GetValue(&buildlab_options, "UIBootMode", 0i64);
    UFG::qString::qString(&v48, (const char *)v2);
    UFG::gUIChunkFiles = UFG::BuildLabOptions::GetValue(&buildlab_options, "UIChunkFiles", 1);
    v3 = UFG::BuildLabOptions::GetValue(&buildlab_options, "StartTrack", 0i64);
    UFG::qString::Set(&StartTrack, (const char *)v3);
    UFG::gPublisherTweaker = UFG::BuildLabOptions::GetValue(&buildlab_options, "PublisherTweaker", 0);
    UFG::gMapTeleportEnable = UFG::BuildLabOptions::GetValue(&buildlab_options, "MapTeleportEnable", 0);
    UFG::gDebugUIMenuOptions = UFG::BuildLabOptions::GetValue(&buildlab_options, "DebugUIMenuOptions", 0);
    gShowMissionWorkState = UFG::BuildLabOptions::GetValue(&buildlab_options, "ShowMissionWorkState", 0);
    gShowWorldCoords = UFG::BuildLabOptions::GetValue(&buildlab_options, "ShowWorldCoords", 0);
    gShowFPS = UFG::BuildLabOptions::GetValue(&buildlab_options, "ShowFPS", 0);
    gShowCellNumber = UFG::BuildLabOptions::GetValue(&buildlab_options, "ShowCellNumber", 0);
    gShowNISName = UFG::BuildLabOptions::GetValue(&buildlab_options, "ShowNISName", 0);
    gCreateFinalBinDir = UFG::BuildLabOptions::GetValue(&buildlab_options, "CreateFinalBinDir", 1);
    gShowCL = UFG::BuildLabOptions::GetValue(&buildlab_options, "ShowCLNumber", 0);
    gShowMissionScore = UFG::BuildLabOptions::GetValue(&buildlab_options, "ShowMissionScore", 0);
    UFG::gCL_number = UFG::BuildLabOptions::GetValue(&buildlab_options, "Changelist", 1);
    gEnableNetPublisher = UFG::BuildLabOptions::GetValue(&buildlab_options, "EnableNetPublisher", 1);
    gDebugControllerPort = UFG::BuildLabOptions::GetValue(&buildlab_options, "DebugControllerPort", 1);
    gDemoVersion = UFG::BuildLabOptions::GetValue(&buildlab_options, "Demo", 0);
    UFG::CopSystem::msEnableByDefault = UFG::BuildLabOptions::GetValue(&buildlab_options, "EnableCopsByDefault", 1);
    v4 = UFG::BuildLabOptions::GetValue(&buildlab_options, "DirectGameSlice", 0i64);
    UFG::qString::Set(&gDirectGameSliceId, (const char *)v4);
    v5 = UFG::BuildLabOptions::GetValue(&buildlab_options, "EnableSound", 1);
    v52 = UFG::BuildLabOptions::GetValue(&buildlab_options, "EnableRumble", 1);
    UFG::gEnableAudioProfiler = UFG::BuildLabOptions::GetValue(&buildlab_options, "ProfileAudio", 1);
    UFG::gNoAudioPCK = UFG::BuildLabOptions::GetValue(&buildlab_options, "ForceNoAudioPackFile", 0);
    UFG::gClearMemoryOnFree = UFG::BuildLabOptions::GetValue(&buildlab_options, "ClearMemoryOnFree", 0);
    UFG::gPageBasedStompDetector = UFG::BuildLabOptions::GetValue(&buildlab_options, "PageBasedStompDetector", 0);
    UFG::gPerformExitGameMemoryCheck = UFG::BuildLabOptions::GetValue(
                                         &buildlab_options,
                                         "PerformExitGameMemoryCheck",
                                         0);
    gInvertDebugCameraV = UFG::BuildLabOptions::GetValue(&buildlab_options, "InvertDebugCamera", 0);
    gHostPort = UFG::BuildLabOptions::GetValue(&buildlab_options, "Project.Chatline.Server.PortNumber", 27100);
    v6 = UFG::BuildLabOptions::GetValue(&buildlab_options, "Environment", &customCaption);
    UFG::qString::Set(&gEnvironmentURL, (const char *)v6);
    LOBYTE(v0) = UFG::BuildLabOptions::GetValue(&buildlab_options, "KeyboardMouse", 1) == 0;
    UFG::InputSystem::msPCKeyboardSwapMode = v0;
    UFG::gUIBootModeSkipFE = UFG::qStringFind(v48.mData, "SKIP") != 0i64;
    UFG::gUIBootModeSkipFEFull = (unsigned int)UFG::qStringCompare(v48.mData, "SKIP-FullHK", -1) == 0;
    UFG::gUIBootModeSkipFEEmpty = (unsigned int)UFG::qStringCompare(v48.mData, "SKIP-EmptyHK", -1) == 0;
    v7 = UFG::BuildLabOptions::GetValue(&buildlab_options, "Username", 0i64);
    if ( (int)UFG::qStringLength((const char *)v7) > 0 && !gUserName.mLength )
      UFG::qString::Set(&gUserName, (const char *)v7);
    v8 = UFG::BuildLabOptions::GetValue(&buildlab_options, "Password", 0i64);
    if ( (int)UFG::qStringLength((const char *)v8) > 0 && !gLoginPassword.mLength )
      UFG::qString::Set(&gLoginPassword, (const char *)v8);
    if ( UFG::gAutoSmoketest )
    {
      UFG::gUIBootModeSkipFE = 1;
      UFG::gUIBootModeSkipFEFull = 0;
      UFG::gUIBootModeSkipFEEmpty = 0;
    }
    v9 = UFG::BuildLabOptions::GetValue(&buildlab_options, "Animation", "Final");
    v10 = UFG::BuildLabOptions::GetValue(&buildlab_options, "AnimationNIS", "Final");
    v11 = UFG::BuildLabOptions::GetValue(&buildlab_options, "Characters", "Final");
    v12 = UFG::BuildLabOptions::GetValue(&buildlab_options, "Vehicles", "Final");
    v13 = UFG::BuildLabOptions::GetValue(&buildlab_options, "UI", "Final");
    v14 = UFG::BuildLabOptions::GetValue(&buildlab_options, "Global", "Final");
    if ( !(unsigned int)UFG::qStringCompareInsensitive((const char *)v9, "FinalNoCache", -1)
      || !(unsigned int)UFG::qStringCompareInsensitive((const char *)v10, "FinalNoCache", -1)
      || !(unsigned int)UFG::qStringCompareInsensitive((const char *)v11, "FinalNoCache", -1)
      || !(unsigned int)UFG::qStringCompareInsensitive((const char *)v12, "FinalNoCache", -1)
      || !(unsigned int)UFG::qStringCompareInsensitive((const char *)v13, "FinalNoCache", -1)
      || !(unsigned int)UFG::qStringCompareInsensitive((const char *)v14, "FinalNoCache", -1) )
    {
      UFG::gBuildingBigFiles = 1;
    }
    v15 = UFG::BuildLabOptions::GetValue(&buildlab_options, "Subtitles");
    UFG::qString::qString(&v50, (const char *)v15);
    if ( UFG::qString::operator==(&v50, "Off") )
      UFG::SubtitleManager::SetSubtitleMode(eSubtitleMode_Off);
    if ( UFG::qString::operator==(&v50, "On") )
      UFG::SubtitleManager::SetSubtitleMode(eSubtitleMode_On);
    if ( UFG::qString::operator==(&v50, "Cantonese") )
      UFG::SubtitleManager::SetSubtitleMode(eSubtitleMode_Cantonese);
    v16 = UFG::BuildLabOptions::GetValue(&buildlab_options, "EnableAudioLowMemoryWarnings", 0);
    v17 = UFG::BuildLabOptions::GetValue(&buildlab_options, "EnableAudioPoolInfo", 0);
    _((AMD_HD3D *)v5);
    _((AMD_HD3D *)v52);
    _((AMD_HD3D *)v16);
    _((AMD_HD3D *)v17);
    v18 = UFG::BuildLabOptions::GetValue(&buildlab_options, "DVDEmulation");
    UFG::qString::qString(&v51, (const char *)v18);
    v19 = UFG::BuildLabOptions::GetValue(&buildlab_options, "Resolution", "1920x1880");
    UFG::qString::Set(&gDebugResolution, (const char *)v19);
    v20 = UFG::BuildLabOptions::GetValue(&buildlab_options, "OnScreenMetrics", "Off");
    UFG::qString::qString(&v49, (const char *)v20);
    if ( UFG::qString::operator==(&v49, "Off") )
    {
      UFG::gRenderInfo = 0;
LABEL_31:
      UFG::SimObjectUtility::ms_bTraceResetLogging = UFG::BuildLabOptions::GetValue(&buildlab_options, "SpewDebug", 0);
      UFG::HitReactionComponent::msSpewHitReactions = UFG::SimObjectUtility::ms_bTraceResetLogging;
      AnimationNode::ms_bShowAnimationErrors = UFG::BuildLabOptions::GetValue(
                                                 &buildlab_options,
                                                 "ShowAnimationErrors",
                                                 0);
      v21 = UFG::BuildLabOptions::GetValue(&buildlab_options, "EnableTraffic", 0);
      UFG::WheeledVehicleManager::EnableTrafficSpawningUpdates(v21);
      UFG::gEnableLogPlayer = UFG::BuildLabOptions::GetValue(&buildlab_options, "LogPlayer", 0);
      UFG::BigFileLogic::ProcessBuildOptions(&buildlab_options);
      v22 = UFG::HotSwapFileManager::Get();
      UFG::HotSwapFileManager::ProcessBuildLabOptions(v22, &buildlab_options, key, 0x22u);
      gForceLowRes = UFG::BuildLabOptions::GetValue(&buildlab_options, "ForceLowResTextures", 0);
      UFG::qString::~qString(&v49);
      UFG::qString::~qString(&v51);
      UFG::qString::~qString(&v50);
      UFG::qString::~qString(&v48);
      goto LABEL_32;
    }
    if ( UFG::qString::operator==(&v49, "Brief") )
    {
      UFG::gBriefInfo = 1;
    }
    else
    {
      if ( UFG::qString::operator==(&v49, "FX") )
      {
        UFG::gFXInfo = 1;
        goto LABEL_31;
      }
      UFG::gBriefInfo = 0;
    }
    UFG::gFXInfo = 0;
    UFG::gRenderInfo = 1;
    goto LABEL_31;
  }
LABEL_32:
  for ( i = (UFG::qString *)option_list.mNode.mPrev;
        (UFG::BuildLabOptions *)option_list.mNode.mPrev != &buildlab_options;
        i = (UFG::qString *)option_list.mNode.mPrev )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v26 = buildlab_options.mProjectFilename.mPrev;
  v27 = option_list.mNode.mPrev;
  buildlab_options.mProjectFilename.mPrev->mNext = option_list.mNode.mPrev;
  v27->mPrev = v26;
  buildlab_options.mProjectFilename.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&buildlab_options;
  option_list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&buildlab_options;
  for ( j = (UFG::qString *)v45.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)v45.mNode.mNext != &v45;
        j = (UFG::qString *)v45.mNode.mNext )
  {
    v29 = j->mPrev;
    v30 = j->mNext;
    v29->mNext = v30;
    v30->mPrev = v29;
    j->mPrev = j;
    j->mNext = j;
    UFG::qString::~qString(j);
    operator delete[](j);
  }
  v31 = v45.mNode.mPrev;
  v32 = v45.mNode.mNext;
  v45.mNode.mPrev->mNext = v45.mNode.mNext;
  v32->mPrev = v31;
  v45.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v45;
  v45.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v45;
  for ( k = (UFG::qString *)option_list.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)option_list.mNode.mNext != &option_list;
        k = (UFG::qString *)option_list.mNode.mNext )
  {
    v34 = k->mPrev;
    v35 = k->mNext;
    v34->mNext = v35;
    v35->mPrev = v34;
    k->mPrev = k;
    k->mNext = k;
    UFG::qString::~qString(k);
    operator delete[](k);
  }
  v36 = option_list.mNode.mPrev;
  v37 = option_list.mNode.mNext;
  option_list.mNode.mPrev->mNext = option_list.mNode.mNext;
  v37->mPrev = v36;
  option_list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&option_list;
  option_list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&option_list;
  for ( m = (UFG::qString *)v45.mNode.mPrev;
        (UFG::qNode<UFG::qString,UFG::qString> **)v45.mNode.mPrev != &option_list.mNode.mNext;
        m = (UFG::qString *)v45.mNode.mPrev )
  {
    v39 = m->mPrev;
    v40 = m->mNext;
    v39->mNext = v40;
    v40->mPrev = v39;
    m->mPrev = m;
    m->mNext = m;
    UFG::qString::~qString(m);
    operator delete[](m);
  }
  v41 = option_list.mNode.mNext;
  v42 = v45.mNode.mPrev;
  option_list.mNode.mNext->mNext = v45.mNode.mPrev;
  v42->mPrev = v41;
  option_list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&option_list.mNode.mNext;
  v45.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&option_list.mNode.mNext;
  UFG::BuildLabOptions::~BuildLabOptions(&buildlab_options);
}

// File Line: 435
// RVA: 0x41F460
void __fastcall InitConfig(const char *option_filename)
{
  UFG::qString::Set(&StartTrack, "TrackPark");
  UFG::gUIBootModeSkipFE = 0;
  UFG::gUIBootModeSkipFEFull = 0;
  UFG::gUIBootModeSkipFEEmpty = 0;
  UFG::qString::Set(&gDirectGameSliceId, &customCaption);
  UFG::HostInfo::Load((const char *)&stru_141787D48);
  InitRunOptions();
  if ( UFG::gAutoSmoketest )
    UFG::SetCL(UFG::gCL_number);
}

