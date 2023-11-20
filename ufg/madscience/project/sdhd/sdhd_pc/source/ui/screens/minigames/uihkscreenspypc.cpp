// File Line: 48
// RVA: 0x5C7600
void __fastcall UFG::UIHKScreenSpyPC::UIHKScreenSpyPC(UFG::UIHKScreenSpyPC *this)
{
  UFG::UIHKScreenSpyPC *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  hkgpIndexedMeshDefinitions::Edge *v3; // rdx
  hkgpIndexedMesh::EdgeBarrier *v4; // rcx
  unsigned int v5; // eax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = 0;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSpyPC::`vftable;
  this->mState = 0;
  UFG::PropertySetHandle::PropertySetHandle(&this->mProperties);
  v1->mCurrentTime = 0;
  *(_WORD *)&v1->mbLiveNeighborhood = 0;
  v1->mbTriadSensitive = 0;
  v1->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
  UFG::SetInputMode(IM_UI_ONLY, UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v4, v3) )
  {
    UFG::qWiseSymbol::create_from_string(&result, "mg_spy_cam");
    UFG::TiDo::LoadWwiseBank(&result);
    UFG::AudioListener::sm_pInstance->m_lockListenerPosition = 1;
    ((void (__fastcall *)(UFG::TiDo *, const char *, const char *))UFG::TiDo::m_pInstance->vfptr[1].UpdateListenerTriggerRegions)(
      UFG::TiDo::m_pInstance,
      "ms_minigames",
      "surveillance");
    v5 = UFG::TiDo::CalcWwiseUid("mute_rain");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v5, 0i64, 0, 0i64);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 66
// RVA: 0x5CCB50
void __fastcall UFG::UIHKScreenSpyPC::~UIHKScreenSpyPC(UFG::UIHKScreenSpyPC *this)
{
  UFG::UIHKScreenSpyPC *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  hkgpIndexedMesh::EdgeBarrier *v5; // rcx
  UFG::SimComponent *v6; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSpyPC::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v2, UFG::UIHKScreenSpyPC::gGridTexturePackFilename);
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "SpyPC");
  v1->mbTriadSensitive = 0;
  UFG::PropertySetHandle::Null(&v1->mProperties);
  UFG::SetInputMode(
    v1->mSavedControllerMode,
    UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v5, v4) )
  {
    if ( !(_S24_0 & 1) )
    {
      _S24_0 |= 1u;
      Set_State_minigame_mus_end_2.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_end", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_end_2.mUID);
      atexit(UFG::UIHKScreenSpyPC::_UIHKScreenSpyPC_::_4_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_end__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_end_2.mUID);
    UFG::qWiseSymbol::create_from_string(&result, "mg_spy_cam");
    UFG::TiDo::UnloadWwiseBank(&result);
    UFG::AudioListener::sm_pInstance->m_lockListenerPosition = 0;
    ((void (__fastcall *)(UFG::TiDo *, const char *, const char *))UFG::TiDo::m_pInstance->vfptr[1].UpdateListenerTriggerRegions)(
      UFG::TiDo::m_pInstance,
      "ms_minigames",
      "none");
    if ( LocalPlayer )
    {
      v6 = UFG::SimObject::GetComponentOfType(
             (UFG::SimObject *)&LocalPlayer->vfptr,
             UFG::CharacterLookComponent::_TypeUID);
      if ( v6 )
        HIDWORD(v6[2].m_BoundComponentHandles.mNode.mNext) = 0;
    }
    _((AMD_HD3D *)result.mUID);
  }
  UFG::PropertySetHandle::~PropertySetHandle(&v1->mProperties);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 94
// RVA: 0x6366A0
void __fastcall UFG::UIHKScreenSpyPC::init(UFG::UIHKScreenSpyPC *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenSpyPC *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  double v4; // xmm6_8
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx
  hkgpIndexedMesh::EdgeBarrier *v6; // rcx
  double v7; // xmm6_8
  bool v8; // bl
  bool v9; // bl
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-C8h]
  char ptr; // [rsp+60h] [rbp-98h]
  __int64 v12; // [rsp+70h] [rbp-88h]
  double v13; // [rsp+78h] [rbp-80h]
  Scaleform::GFx::Value v14; // [rsp+88h] [rbp-70h]
  char v15; // [rsp+B8h] [rbp-40h]
  __int64 v16; // [rsp+C8h] [rbp-30h]
  unsigned int v17; // [rsp+D0h] [rbp-28h]
  __int64 v18; // [rsp+D8h] [rbp-20h]
  __int64 v19; // [rsp+E8h] [rbp-10h]

  v19 = -2i64;
  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v2->mState = 1;
  v3 = v2->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4 = (double)(signed int)v2->mState;
  if ( (LODWORD(v13) >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v12 + 16i64))(
      v12,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v13));
    v12 = 0i64;
  }
  v13 = v4;
  `eh vector constructor iterator(&v14, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v7 = (double)(signed int)UFG::UIHKScreenSpyPC::GetDefaultNeighborhood(v2);
  if ( ((unsigned int)v14.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v14.pObjectInterface->vfptr->gap8[8])(
      v14.pObjectInterface,
      &v14,
      *(_QWORD *)&v14.mValue.NValue);
    v14.pObjectInterface = 0i64;
  }
  v14.Type = 5;
  v14.mValue.NValue = v7;
  v8 = v2->mbLiveNeighborhood;
  if ( (v17 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &v15, v18);
    v16 = 0i64;
  }
  v17 = 2;
  LOBYTE(v18) = v8;
  if ( v3 )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 0;
    v9 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pargs.Type = 2;
    pargs.mValue.BValue = v9;
    Scaleform::GFx::Movie::Invoke(v3, "Show_PCCtrls", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(v3, "setState", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    Scaleform::GFx::Movie::Invoke(v3, "setNeighborhood", 0i64, &v14, 2u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 0;
  }
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v6, v5) && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xF41B2F0D,
      0i64,
      0,
      0i64);
  `eh vector destructor iterator(&v14, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 127
// RVA: 0x5E7680
signed __int64 __fastcall UFG::UIHKScreenSpyPC::GetDefaultNeighborhood(UFG::UIHKScreenSpyPC *this)
{
  UFG::UIHKScreenSpyPC *v1; // rbx
  int v2; // esi
  Scaleform::GFx::Movie *v3; // r15
  UFG::qSymbol *v4; // rax
  UFG::qPropertySet *v5; // rax
  UFG::qPropertyList *v6; // rax
  UFG::qPropertyList *v7; // r13
  unsigned int v8; // er12
  unsigned int v9; // er14
  char *v10; // rax
  UFG::qPropertySet *v11; // rdi
  UFG::GameStatTracker *v12; // rax
  UFG::GameStatTracker *v13; // rax
  UFG::ProgressionTracker *v14; // rbx
  UFG::GameSlice *v15; // rbp
  bool v16; // al
  char *v17; // rbx
  double v18; // xmm6_8
  char ptr; // [rsp+40h] [rbp-78h]
  __int64 v21; // [rsp+50h] [rbp-68h]
  unsigned int v22; // [rsp+58h] [rbp-60h]
  double v23; // [rsp+60h] [rbp-58h]
  UFG::qSymbol name; // [rsp+C0h] [rbp+8h]
  UFG::qSymbol result; // [rsp+C8h] [rbp+10h]

  v1 = this;
  v2 = 0;
  v3 = this->mRenderable->m_movie.pObject;
  v4 = UFG::qSymbol::create_from_string(&name, "default-spycams-list");
  v5 = UFG::PropertySetManager::GetPropertySet(v4);
  UFG::PropertySetHandle::SetPropSet(&v1->mProperties, v5);
  UFG::PropertySetHandle::Bind(&v1->mProperties);
  v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v1->mProperties.mpPropSet,
         (UFG::qSymbol *)&SpyCamSymbol_List_1.mUID,
         DEPTH_RECURSE);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6->mNumElements;
    v9 = 0;
    if ( v8 )
    {
      do
      {
        v10 = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, v9);
        if ( v10 && *(_QWORD *)v10 )
          v11 = (UFG::qPropertySet *)&v10[*(_QWORD *)v10];
        else
          v11 = 0i64;
        if ( *UFG::qPropertySet::Get<bool>(v11, (UFG::qSymbol *)&SpyCamSymbol_TWSensitive_1.mUID, DEPTH_RECURSE) )
        {
          v12 = UFG::GameStatTracker::Instance();
          if ( UFG::GameStatTracker::GetStat(v12, Collectible_SpyCam, &v11->mName) )
          {
            name.mUID = UFG::qPropertySet::Get<UFG::qSymbol>(
                          v11,
                          (UFG::qSymbol *)&SpyCamSymbol_TWName_1.mUID,
                          DEPTH_RECURSE)->mUID;
            v13 = UFG::GameStatTracker::Instance();
            if ( UFG::GameStatTracker::GetStat(v13, Collectible_EnforcerUnlocked, &name) )
            {
              v14 = UFG::ProgressionTracker::Instance();
              v15 = UFG::ProgressionTracker::GetActiveMaster(v14);
              if ( v15 )
              {
                v16 = 1;
                if ( UFG::ProgressionTracker::IsRunningCriticalActiveMaster(v14) )
                {
                  v2 |= 1u;
                  if ( v15->mNode.mUID != UFG::qSymbol::create_from_string(&result, "C_PS2")->mUID )
                    v16 = 0;
                }
                if ( v2 & 1 )
                  v2 &= 0xFFFFFFFE;
                if ( v16 )
                {
                  v17 = UFG::qPropertySet::Get<char const *>(
                          v11,
                          (UFG::qSymbol *)&SpyCamSymbol_Neighborhood_1.mUID,
                          DEPTH_RECURSE);
                  `eh vector constructor iterator(
                    &ptr,
                    0x30ui64,
                    1,
                    (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
                  v18 = (double)(signed int)UFG::UIHKScreenSpyPC::GetNeighborhoodId(v17);
                  if ( (v22 >> 6) & 1 )
                  {
                    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v21 + 16i64))(
                      v21,
                      &ptr,
                      COERCE_DOUBLE(*(_QWORD *)&v23));
                    v21 = 0i64;
                  }
                  v22 = 5;
                  v23 = v18;
                  if ( v3 )
                    Scaleform::GFx::Movie::Invoke(v3, "setForTW", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
                  `eh vector destructor iterator(
                    &ptr,
                    0x30ui64,
                    1,
                    (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
                }
              }
            }
          }
        }
        ++v9;
      }
      while ( v9 < v8 );
    }
  }
  return 1i64;
}

// File Line: 184
// RVA: 0x5E83F0
signed __int64 __fastcall UFG::UIHKScreenSpyPC::GetNeighborhoodId(const char *neighborhood)
{
  const char *v1; // rbx
  int v3; // eax
  unsigned int v4; // ecx

  v1 = neighborhood;
  if ( !(unsigned int)UFG::qStringCompare(neighborhood, "CT", -1) )
    return 1i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "NP", -1) )
    return 2i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "AB", -1) )
    return 3i64;
  v3 = UFG::qStringCompare(v1, "KT", -1);
  v4 = 0;
  if ( !v3 )
    v4 = 4;
  return v4;
}

// File Line: 197
// RVA: 0x640050
void __usercall UFG::UIHKScreenSpyPC::update(UFG::UIHKScreenSpyPC *this@<rcx>, float elapsed@<xmm1>, __int64 a3@<rdx>)
{
  UFG::UIHKScreenSpyPC *v3; // rdi
  char v4; // bl
  UFG::qWiseSymbol *v5; // rax
  bool v6; // si
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+8h]

  v3 = this;
  v4 = 0;
  ((void (__cdecl *)(UFG::UIHKScreenSpyPC *, __int64))this->vfptr[1].__vecDelDtor)(this, a3);
  v6 = 0;
  if ( !v3->mbMusicPlay )
  {
    v5 = UFG::qWiseSymbol::create_from_string(&result, "mg_spy_cam");
    v4 = 1;
    if ( (unsigned __int8)UFG::TiDo::BankLoaded(v5->mUID) )
      v6 = 1;
  }
  if ( v4 & 1 )
    _((AMD_HD3D *)result.mUID);
  if ( v6 )
  {
    if ( !(_S25_2 & 1) )
    {
      _S25_2 |= 1u;
      Set_State_minigame_mus_start_2.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_start", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_start_2.mUID);
      atexit(UFG::UIHKScreenSpyPC::update_::_5_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_start__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_start_2.mUID);
    v3->mbMusicPlay = 1;
  }
  UFG::UIScreen::update((UFG::UIScreen *)&v3->vfptr, elapsed);
}

// File Line: 211
// RVA: 0x61D670
void __fastcall UFG::UIHKScreenSpyPC::UpdateTime(UFG::UIHKScreenSpyPC *this)
{
  UFG::UIHKScreenSpyPC *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdi
  UFG::TimeOfDayManager *v3; // rax
  unsigned int v4; // edx
  unsigned int v5; // ecx
  const char *v6; // rax
  char *v7; // rbx
  bool v8; // bl
  Scaleform::GFx::Value v9; // [rsp+28h] [rbp-39h]
  Scaleform::GFx::Value pargs; // [rsp+58h] [rbp-9h]
  __int64 v11; // [rsp+88h] [rbp+27h]
  UFG::qString result; // [rsp+90h] [rbp+2Fh]

  v11 = -2i64;
  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    v3 = UFG::TimeOfDayManager::GetInstance();
    v4 = (signed int)(float)(v3->m_SecondsSinceMidnight * 0.00027777778);
    v5 = (signed int)(float)((float)(v3->m_SecondsSinceMidnight - (float)((float)(signed int)v4 * 3600.0)) * 0.016666668);
    if ( v5 != v1->mCurrentTime )
    {
      v1->mCurrentTime = v5;
      v6 = "AM";
      if ( v4 > 0xC )
      {
        v4 -= 12;
        v6 = "PM";
      }
      UFG::qString::FormatEx(&result, "%02u:%02u %s", v4, v5, v6);
      pargs.pObjectInterface = 0i64;
      pargs.Type = 0;
      v7 = result.mData;
      pargs.Type = 6;
      *(_QWORD *)&pargs.mValue.NValue = v7;
      Scaleform::GFx::Movie::Invoke(v2, "SpyPC_SetTime", 0i64, &pargs, 1u);
      v9.pObjectInterface = 0i64;
      v9.Type = 0;
      v8 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
      v9.Type = 2;
      v9.mValue.BValue = v8;
      Scaleform::GFx::Movie::Invoke(v2, "Show_PCCtrls", 0i64, &v9, 1u);
      if ( ((unsigned int)v9.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v9.pObjectInterface->vfptr->gap8[8])(
          v9.pObjectInterface,
          &v9,
          *(_QWORD *)&v9.mValue.NValue);
        v9.pObjectInterface = 0i64;
      }
      v9.Type = 0;
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 0;
      UFG::qString::~qString(&result);
    }
  }
}

// File Line: 247
// RVA: 0x62C640
char __fastcall UFG::UIHKScreenSpyPC::handleMessage(UFG::UIHKScreenSpyPC *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r15
  unsigned int v4; // esi
  UFG::UIHKScreenSpyPC *v5; // r14
  UFG::UIHKScreenSpyPC::eState v6; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::Movie *v9; // rbx
  signed int v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // eax
  SSClass *v13; // rbx
  SSInstance *v14; // rcx
  const char *v15; // rdx
  unsigned int v16; // eax
  double v17; // xmm6_8
  UFG::UIScreenTextureManager *v18; // rax
  bool v19; // bl
  UFG::qSymbol *v20; // rax
  UFG::qPropertySet *v21; // rax
  UFG::qPropertyList *v22; // rax
  UFG::qPropertyList *v23; // r13
  unsigned int v24; // er12
  unsigned int v25; // er15
  char *v26; // rax
  UFG::qPropertySet *v27; // rbx
  char *v28; // rax
  int *v29; // rax
  ASymbol *v30; // r15
  ASymbol *v31; // r12
  UFG::GameStatTracker *v32; // rax
  bool v33; // al
  ASymbol *v34; // rcx
  unsigned int v35; // ebx
  SSClass *v36; // rax
  SSInstance *v37; // r15
  ASymbol *v38; // rax
  unsigned int v39; // eax
  UFG::UIScreenTextureManager *v40; // rax
  UFG::qString v41; // [rsp+10h] [rbp-41h]
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-19h]
  ASymbol result; // [rsp+B8h] [rbp+67h]
  UFG::UIMessage *v44; // [rsp+C8h] [rbp+77h]
  SSInstance *args_pp; // [rsp+D0h] [rbp+7Fh]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = this->mState;
  if ( v6 == 3 )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, msgId, msg);
  if ( msgId == UI_HASH_PLAYSOUND_20 )
  {
    UFG::qString::qString(&v41, (UFG::qString *)&msg[1]);
    v7 = UFG::TiDo::CalcWwiseUid(v41.mData);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v7, 0i64, 0, 0i64);
    UFG::qString::~qString(&v41);
    return 1;
  }
  v9 = v5->mRenderable->m_movie.pObject;
  if ( !v9 )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, msgId, msg);
  if ( v6 == 1 )
  {
    if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    {
      pval.pObjectInterface = 0i64;
      pval.Type = 0;
      Scaleform::GFx::Movie::GetVariable(v9, &pval, "currentAntenna");
      v10 = (signed int)pval.mValue.NValue;
      v11 = UFG::TiDo::CalcWwiseUid("Play_sp_accept");
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v11, 0i64, 0, 0i64);
      v5->mNeighborhood = v10;
      v5->mState = 2;
      UFG::UIHKScreenSpyPC::LoadNeighborhoodTexturePack(v5);
      if ( ((unsigned int)pval.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          *(_QWORD *)&pval.mValue.NValue);
        pval.pObjectInterface = 0i64;
      }
      pval.Type = 0;
      goto LABEL_78;
    }
    if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      v5->mFinished = 1;
      v12 = UFG::TiDo::CalcWwiseUid("Play_sp_back");
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v12, 0i64, 0, 0i64);
      v13 = SSBrain::get_class("SpyPC");
      ASymbol::create(&result, "_end_camera", 0xFFFFFFFF, ATerm_long);
      if ( LODWORD(v13[1].vfptr) )
        v14 = **(SSInstance ***)&v13[1].i_name.i_uid;
      else
        v14 = 0i64;
      args_pp = 0i64;
      SSInstance::coroutine_call(v14, &result, &args_pp, 0, 1, 0.0, 0i64, 0i64);
      goto LABEL_78;
    }
    if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xEDB4A8C7,
          0i64,
          0,
          0i64);
      v15 = "highlightNeighborhoodDown";
    }
    else
    {
      if ( msgId != UI_HASH_DPAD_UP_PRESSED_30 && msgId != UI_HASH_THUMBSTICK_LEFT_UP_30 )
        goto LABEL_78;
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xEDB4A8C7,
          0i64,
          0,
          0i64);
      v15 = "highlightNeighborhoodUp";
    }
    goto LABEL_77;
  }
  if ( v6 != 2 )
  {
LABEL_78:
    msg = v3;
    msgId = v4;
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, msgId, msg);
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
  {
    v15 = "highlightDown";
    goto LABEL_77;
  }
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    v15 = "highlightUp";
    goto LABEL_77;
  }
  if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    v15 = "highlightLeft";
    goto LABEL_77;
  }
  if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    v15 = "highlightRight";
LABEL_77:
    Scaleform::GFx::Movie::Invoke(v9, v15, 0i64, 0i64, 0);
    goto LABEL_78;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    v5->mState = 1;
    v16 = UFG::TiDo::CalcWwiseUid("Play_sp_back");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v16, 0i64, 0, 0i64);
    *(_QWORD *)&v41.mMagic = Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator(&pval, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v17 = (double)(signed int)v5->mState;
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    pval.Type = 5;
    pval.mValue.NValue = v17;
    Scaleform::GFx::Movie::Invoke(v9, "setState", 0i64, &pval, 1u);
    Scaleform::GFx::Movie::Invoke(v9, "resetNeighborhoodScreen", 0i64, 0i64, 0);
    v18 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v18, UFG::UIHKScreenSpyPC::gGridTexturePackFilename);
    `eh vector destructor iterator(&pval, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    goto LABEL_78;
  }
  if ( msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    goto LABEL_78;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::Invoke(v9, "confirmCameraStatus", 0i64, &customWorldMapCaption);
  Scaleform::GFx::Movie::GetVariable(v9, &pval, "selectedSlot");
  args_pp = (SSInstance *)(unsigned int)(signed int)pval.mValue.NValue;
  if ( (_DWORD)args_pp != -1 )
  {
    v20 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "default-spycams-list");
    v21 = UFG::PropertySetManager::GetPropertySet(v20);
    UFG::PropertySetHandle::SetPropSet(&v5->mProperties, v21);
    UFG::PropertySetHandle::Bind(&v5->mProperties);
    v22 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            v5->mProperties.mpPropSet,
            (UFG::qSymbol *)&SpyCamSymbol_List_1.mUID,
            DEPTH_RECURSE);
    v23 = v22;
    if ( v22 && (v24 = v22->mNumElements, v25 = 0, v24) )
    {
      while ( 1 )
      {
        v26 = UFG::qPropertyList::GetValuePtr(v23, 0x1Au, v25);
        if ( !v26 || (v27 = (UFG::qPropertySet *)&v26[*(_QWORD *)v26], !*(_QWORD *)v26) )
          v27 = 0i64;
        v28 = UFG::qPropertySet::Get<char const *>(
                v27,
                (UFG::qSymbol *)&SpyCamSymbol_Neighborhood_1.mUID,
                DEPTH_RECURSE);
        if ( !(unsigned int)UFG::qStringCompare(v28, v5->mCurrentNeighborhood, -1) )
        {
          v29 = UFG::qPropertySet::Get<long>(v27, (UFG::qSymbol *)&SpyCamSymbol_Index_1.mUID, DEPTH_RECURSE);
          if ( *v29 == (_DWORD)args_pp )
            break;
        }
        if ( ++v25 >= v24 )
          goto LABEL_59;
      }
    }
    else
    {
LABEL_59:
      v27 = 0i64;
    }
    v30 = (ASymbol *)UFG::qPropertySet::Get<UFG::qSymbol>(
                       v27,
                       (UFG::qSymbol *)&SpyCamSymbol_CameraMarker_1.mUID,
                       DEPTH_RECURSE);
    v31 = (ASymbol *)UFG::qPropertySet::Get<UFG::qSymbol>(
                       v27,
                       (UFG::qSymbol *)&SpyCamSymbol_TeleportMarker_1.mUID,
                       DEPTH_RECURSE);
    UFG::qPropertySet::Get<UFG::qSymbol>(v27, (UFG::qSymbol *)&SpyCamSymbol_SliceName_1.mUID, DEPTH_RECURSE);
    if ( *UFG::qPropertySet::Get<bool>(v27, (UFG::qSymbol *)&SpyCamSymbol_TWSensitive_1.mUID, DEPTH_RECURSE) )
    {
      result.i_uid = UFG::qPropertySet::Get<UFG::qSymbol>(
                       v27,
                       (UFG::qSymbol *)&SpyCamSymbol_TWName_1.mUID,
                       DEPTH_RECURSE)->mUID;
      v32 = UFG::GameStatTracker::Instance();
      v33 = UFG::GameStatTracker::GetStat(v32, Collectible_EnforcerUnlocked, (UFG::qSymbol *)&result);
      v34 = v30;
      if ( v33 )
      {
        v35 = 4;
        SSSymbol::as_instance(v30);
        SSSymbol::as_instance(v31);
        *(_QWORD *)&v41.mMagic = SSSymbol::as_instance(&result);
        v41.mData = (char *)SSBoolean::pool_new(1);
        v5->mbTriadSensitive = 1;
LABEL_65:
        v36 = SSBrain::get_class("SpyPC");
        if ( LODWORD(v36[1].vfptr) )
          v37 = **(SSInstance ***)&v36[1].i_name.i_uid;
        else
          v37 = 0i64;
        v38 = ASymbol::create(&result, "_start_camera", 0xFFFFFFFF, ATerm_long);
        SSInstance::coroutine_call(v37, v38, (SSInstance **)&v41, v35, 1, 0.0, 0i64, 0i64);
        v39 = UFG::TiDo::CalcWwiseUid("Play_sp_accept");
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            v39,
            0i64,
            0,
            0i64);
        v5->mState = 3;
        UFG::UIHK_NISOverlay::ShowCurtains(1.0, 0);
        v40 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueLoadAndPush(v40, "SpyCam", 0i64);
        if ( ((unsigned int)pval.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
            pval.pObjectInterface,
            &pval,
            *(_QWORD *)&pval.mValue.NValue);
          pval.pObjectInterface = 0i64;
        }
        pval.Type = 0;
        v3 = v44;
        goto LABEL_78;
      }
    }
    else
    {
      v34 = v30;
    }
    v35 = 2;
    SSSymbol::as_instance(v34);
    v41.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)SSSymbol::as_instance(v31);
    goto LABEL_65;
  }
  v19 = UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  pval.Type = 0;
  return v19;
}

// File Line: 466
// RVA: 0x5F0CA0
void __fastcall UFG::UIHKScreenSpyPC::LoadNeighborhoodTexturePack(UFG::UIHKScreenSpyPC *this)
{
  const char *v1; // rax
  UFG::UIScreenTextureManager *v2; // rax

  switch ( this->mNeighborhood )
  {
    case 1u:
      this->mCurrentNeighborhood = "CT";
      v1 = "Data\\UI\\CTCameras_texturepack.perm.bin";
      goto LABEL_9;
    case 2u:
      this->mCurrentNeighborhood = "NP";
      v1 = "Data\\UI\\NPCameras_texturepack.perm.bin";
      goto LABEL_9;
    case 3u:
      this->mCurrentNeighborhood = "AB";
      v1 = "Data\\UI\\ABCameras_texturepack.perm.bin";
      goto LABEL_9;
    case 4u:
      this->mCurrentNeighborhood = "KT";
      v1 = "Data\\UI\\KTCameras_texturepack.perm.bin";
LABEL_9:
      UFG::UIHKScreenSpyPC::gGridTexturePackFilename = v1;
      break;
  }
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v2,
    UFG::UIHKScreenSpyPC::gGridTexturePackFilename,
    DEFAULT_PRIORITY,
    UFG::UIHKScreenSpyPC::TextureLoadedCallback,
    "SpyPC");
}

// File Line: 498
// RVA: 0x612940
void __fastcall UFG::UIHKScreenSpyPC::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenSpyPC *v2; // rax

  v2 = (UFG::UIHKScreenSpyPC *)UFG::UIScreenManagerBase::getScreen(
                                 (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                 "SpyPC");
  if ( v2 )
    UFG::UIHKScreenSpyPC::HandleTextureLoaded(v2);
}

// File Line: 512
// RVA: 0x5EC240
void __fastcall UFG::UIHKScreenSpyPC::HandleTextureLoaded(UFG::UIHKScreenSpyPC *this)
{
  UFG::UIHKScreenSpyPC *v1; // rdi
  Scaleform::GFx::Movie *v2; // rbx
  double v3; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v3 = (double)(signed int)v1->mState;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = v3;
  if ( v2 )
    Scaleform::GFx::Movie::Invoke(v2, "setState", 0i64, &pargs, 1u);
  UFG::UIHKScreenSpyPC::processUnlockedCameras(v1);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 528
// RVA: 0x639780
void __fastcall UFG::UIHKScreenSpyPC::processUnlockedCameras(UFG::UIHKScreenSpyPC *this)
{
  UFG::UIHKScreenSpyPC *v1; // rbx
  int v2; // er14
  __int64 v3; // rdi
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::MapFloat *v5; // rax
  UFG::qSymbol *v6; // rax
  UFG::qPropertySet *v7; // rax
  UFG::qPropertyList *v8; // r13
  unsigned int v9; // er15
  __int64 *v10; // r12
  unsigned int v11; // ebx
  _DWORD *v12; // rsi
  char *v13; // rax
  UFG::qPropertySet *v14; // rdi
  char *v15; // rax
  signed int *v16; // rbx
  char *v17; // rsi
  double v18; // xmm6_8
  UFG::ProgressionTracker *v19; // rsi
  UFG::GameStatTracker *v20; // rax
  UFG::GameSlice *v21; // rbx
  bool v22; // al
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+38h] [rbp-C8h]
  Scaleform::GFx::Movie *v24; // [rsp+48h] [rbp-B8h]
  char ptr; // [rsp+50h] [rbp-B0h]
  __int64 v26; // [rsp+60h] [rbp-A0h]
  unsigned int v27; // [rsp+68h] [rbp-98h]
  double v28; // [rsp+70h] [rbp-90h]
  char v29; // [rsp+80h] [rbp-80h]
  __int64 v30; // [rsp+90h] [rbp-70h]
  unsigned int v31; // [rsp+98h] [rbp-68h]
  char *v32; // [rsp+A0h] [rbp-60h]
  char v33; // [rsp+B0h] [rbp-50h]
  __int64 v34; // [rsp+C0h] [rbp-40h]
  unsigned int v35; // [rsp+C8h] [rbp-38h]
  __int64 v36; // [rsp+D0h] [rbp-30h]
  char v37; // [rsp+E0h] [rbp-20h]
  __int64 v38; // [rsp+F0h] [rbp-10h]
  unsigned int v39; // [rsp+F8h] [rbp-8h]
  __int64 v40; // [rsp+100h] [rbp+0h]
  __int64 v41; // [rsp+110h] [rbp+10h]
  __int64 v42[6]; // [rsp+120h] [rbp+20h]
  UFG::UIHKScreenSpyPC *v43; // [rsp+250h] [rbp+150h]
  UFG::qSymbol name; // [rsp+258h] [rbp+158h]
  UFG::qSymbol v45; // [rsp+260h] [rbp+160h]
  __int64 v46; // [rsp+268h] [rbp+168h]

  v43 = this;
  v41 = -2i64;
  v1 = this;
  v2 = 0;
  v24 = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::Invoke(v24, "resetCameras", 0i64, 0i64, 0);
  v3 = 0i64;
  v4 = UFG::GameStatTracker::Instance();
  v5 = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBool(v4, Collectible_SpyCam);
  UFG::PersistentData::MapInt::GetIterator(v5, &result);
  while ( UFG::PersistentData::MapBool::Iterator::IsValid((UFG::PersistentData::MapBool::Iterator *)&result) )
  {
    if ( UFG::PersistentData::MapBool::Iterator::GetStatus((UFG::PersistentData::MapBool::Iterator *)&result) )
    {
      v42[v3] = (__int64)UFG::PersistentData::MapBool::Iterator::GetName((UFG::PersistentData::MapBool::Iterator *)&result);
      v3 = (unsigned int)(v3 + 1);
    }
    UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
  }
  v6 = UFG::qSymbol::create_from_string(&name, "default-spycams-list");
  v7 = UFG::PropertySetManager::GetPropertySet(v6);
  UFG::PropertySetHandle::SetPropSet(&v1->mProperties, v7);
  UFG::PropertySetHandle::Bind(&v1->mProperties);
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v1->mProperties.mpPropSet,
         (UFG::qSymbol *)&SpyCamSymbol_List_1.mUID,
         DEPTH_RECURSE);
  v9 = v8->mNumElements;
  if ( (_DWORD)v3 )
  {
    v10 = v42;
    v46 = (unsigned int)v3;
    do
    {
      v11 = 0;
      if ( v9 )
      {
        v12 = (_DWORD *)*v10;
        while ( 1 )
        {
          v13 = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v11);
          if ( v13 && *(_QWORD *)v13 )
            v14 = (UFG::qPropertySet *)&v13[*(_QWORD *)v13];
          else
            v14 = 0i64;
          if ( *v12 == v14->mName.mUID )
          {
            v15 = UFG::qPropertySet::Get<char const *>(
                    v14,
                    (UFG::qSymbol *)&SpyCamSymbol_Neighborhood_1.mUID,
                    DEPTH_RECURSE);
            if ( !(unsigned int)UFG::qStringCompare(v15, v43->mCurrentNeighborhood, -1) )
              break;
          }
          if ( ++v11 >= v9 )
            goto LABEL_39;
        }
        v16 = UFG::qPropertySet::Get<long>(v14, (UFG::qSymbol *)&SpyCamSymbol_Index_1.mUID, DEPTH_RECURSE);
        v17 = UFG::qPropertySet::Get<char const *>(v14, (UFG::qSymbol *)&SpyCamSymbol_Name_1.mUID, DEPTH_RECURSE);
        `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        v18 = (double)*v16;
        if ( (v27 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v26 + 16i64))(
            v26,
            &ptr,
            COERCE_DOUBLE(*(_QWORD *)&v28));
          v26 = 0i64;
        }
        v27 = 5;
        v28 = v18;
        if ( (v31 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v30 + 16i64))(v30, &v29, v32);
          v30 = 0i64;
        }
        v31 = 6;
        v32 = v17;
        if ( (v35 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v34 + 16i64))(v34, &v33, v36);
          v34 = 0i64;
        }
        v35 = 2;
        LOBYTE(v36) = 0;
        if ( (v39 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v38 + 16i64))(v38, &v37, v40);
          v38 = 0i64;
        }
        v39 = 2;
        LOBYTE(v40) = 0;
        v19 = UFG::ProgressionTracker::Instance();
        if ( *UFG::qPropertySet::Get<bool>(v14, (UFG::qSymbol *)&SpyCamSymbol_TWSensitive_1.mUID, DEPTH_RECURSE) )
        {
          name.mUID = UFG::qPropertySet::Get<UFG::qSymbol>(
                        v14,
                        (UFG::qSymbol *)&SpyCamSymbol_TWName_1.mUID,
                        DEPTH_RECURSE)->mUID;
          v20 = UFG::GameStatTracker::Instance();
          if ( UFG::GameStatTracker::GetStat(v20, Collectible_EnforcerUnlocked, &name) )
          {
            v21 = UFG::ProgressionTracker::GetActiveMaster(v19);
            if ( v21 )
            {
              v22 = 1;
              if ( UFG::ProgressionTracker::IsRunningCriticalActiveMaster(v19) )
              {
                v2 |= 1u;
                if ( v21->mNode.mUID != UFG::qSymbol::create_from_string(&v45, "C_PS2")->mUID )
                  v22 = 0;
              }
              if ( v2 & 1 )
                v2 &= 0xFFFFFFFE;
              if ( v22 )
              {
                if ( (v39 >> 6) & 1 )
                {
                  (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v38 + 16i64))(v38, &v37, v40);
                  v38 = 0i64;
                }
                v39 = 2;
                LOBYTE(v40) = 1;
              }
            }
          }
        }
        Scaleform::GFx::Movie::Invoke(v24, "addCameras", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
        `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
LABEL_39:
      ++v10;
      --v46;
    }
    while ( v46 );
  }
}

