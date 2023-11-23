// File Line: 48
// RVA: 0x5C7600
void __fastcall UFG::UIHKScreenSpyPC::UIHKScreenSpyPC(UFG::UIHKScreenSpyPC *this)
{
  hkgpIndexedMeshDefinitions::Edge *v2; // rdx
  hkgpIndexedMesh::EdgeBarrier *v3; // rcx
  unsigned int v4; // eax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h] BYREF

  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = eDIM_INVALID;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSpyPC::`vftable;
  this->mState = STATE_INVALID;
  UFG::PropertySetHandle::PropertySetHandle(&this->mProperties);
  this->mCurrentTime = 0;
  *(_WORD *)&this->mbLiveNeighborhood = 0;
  this->mbTriadSensitive = 0;
  this->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
  UFG::SetInputMode(IM_UI_ONLY, UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v3, v2) )
  {
    UFG::qWiseSymbol::create_from_string(&result, "mg_spy_cam");
    UFG::TiDo::LoadWwiseBank(&result);
    UFG::AudioListener::sm_pInstance->m_lockListenerPosition = 1;
    ((void (__fastcall *)(UFG::TiDo *, const char *, const char *))UFG::TiDo::m_pInstance->vfptr[1].UpdateListenerTriggerRegions)(
      UFG::TiDo::m_pInstance,
      "ms_minigames",
      "surveillance");
    v4 = UFG::TiDo::CalcWwiseUid("mute_rain");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v4, 0i64, 0, 0i64);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 66
// RVA: 0x5CCB50
void __fastcall UFG::UIHKScreenSpyPC::~UIHKScreenSpyPC(UFG::UIHKScreenSpyPC *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  hkgpIndexedMesh::EdgeBarrier *v5; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSpyPC::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v2, UFG::UIHKScreenSpyPC::gGridTexturePackFilename);
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "SpyPC");
  this->mbTriadSensitive = 0;
  UFG::PropertySetHandle::Null(&this->mProperties);
  UFG::SetInputMode(
    this->mSavedControllerMode,
    UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v5, v4) )
  {
    if ( (_S24_0 & 1) == 0 )
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
      ComponentOfType = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::CharacterLookComponent::_TypeUID);
      if ( ComponentOfType )
        HIDWORD(ComponentOfType[2].m_BoundComponentHandles.mNode.mNext) = 0;
    }
    _((AMD_HD3D *)result.mUID);
  }
  UFG::PropertySetHandle::~PropertySetHandle(&this->mProperties);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 94
// RVA: 0x6366A0
void __fastcall UFG::UIHKScreenSpyPC::init(UFG::UIHKScreenSpyPC *this, UFG::UICommandData *data)
{
  Scaleform::GFx::Movie *pObject; // rdi
  double mState; // xmm6_8
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx
  hkgpIndexedMesh::EdgeBarrier *v6; // rcx
  Scaleform::GFx::Value::ValueUnion v7; // xmm6_8
  bool mbLiveNeighborhood; // bl
  bool m_IsKeyboardController; // bl
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-C8h] BYREF
  char ptr[16]; // [rsp+60h] [rbp-98h] BYREF
  __int64 v12; // [rsp+70h] [rbp-88h]
  double v13; // [rsp+78h] [rbp-80h]
  Scaleform::GFx::Value v14; // [rsp+88h] [rbp-70h] BYREF
  char v15[16]; // [rsp+B8h] [rbp-40h] BYREF
  __int64 v16; // [rsp+C8h] [rbp-30h]
  int v17; // [rsp+D0h] [rbp-28h]
  __int64 v18; // [rsp+D8h] [rbp-20h]
  __int64 v19; // [rsp+E8h] [rbp-10h]

  v19 = -2i64;
  UFG::UIScreen::init(this, data);
  this->mState = STATE_NORMAL;
  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  mState = (double)(int)this->mState;
  if ( (LOBYTE(v13) & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v12 + 16i64))(v12, ptr, COERCE_DOUBLE(*(_QWORD *)&v13));
    v12 = 0i64;
  }
  v13 = mState;
  `eh vector constructor iterator(&v14, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v7.NValue = (double)(int)UFG::UIHKScreenSpyPC::GetDefaultNeighborhood(this);
  if ( (v14.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v14.pObjectInterface->vfptr->gap8[8])(
      v14.pObjectInterface,
      &v14,
      v14.mValue);
    v14.pObjectInterface = 0i64;
  }
  v14.Type = VT_Number;
  v14.mValue = v7;
  mbLiveNeighborhood = this->mbLiveNeighborhood;
  if ( (v17 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
    v16 = 0i64;
  }
  v17 = 2;
  LOBYTE(v18) = mbLiveNeighborhood;
  if ( pObject )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Undefined;
    m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = m_IsKeyboardController;
    Scaleform::GFx::Movie::Invoke(pObject, "Show_PCCtrls", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(pObject, "setState", 0i64, (Scaleform::GFx::Value *)ptr, 1u);
    Scaleform::GFx::Movie::Invoke(pObject, "setNeighborhood", 0i64, &v14, 2u);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Undefined;
  }
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v6, v5) && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xF41B2F0D, 0i64, 0, 0i64);
  `eh vector destructor iterator(&v14, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  `eh vector destructor iterator(ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 127
// RVA: 0x5E7680
__int64 __fastcall UFG::UIHKScreenSpyPC::GetDefaultNeighborhood(UFG::UIHKScreenSpyPC *this)
{
  int v2; // esi
  Scaleform::GFx::Movie *pObject; // r15
  UFG::qSymbol *v4; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v6; // rax
  UFG::qPropertyList *v7; // r13
  unsigned int mNumElements; // r12d
  unsigned int i; // r14d
  char *ValuePtr; // rax
  UFG::qPropertySet *v11; // rdi
  UFG::GameStatTracker *v12; // rax
  UFG::GameStatTracker *v13; // rax
  UFG::ProgressionTracker *v14; // rbx
  UFG::GameSlice *ActiveMaster; // rbp
  bool v16; // al
  char *v17; // rbx
  Scaleform::GFx::Value::ValueUnion v18; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-78h] BYREF
  UFG::qSymbol name; // [rsp+C0h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+C8h] [rbp+10h] BYREF

  v2 = 0;
  pObject = this->mRenderable->m_movie.pObject;
  v4 = UFG::qSymbol::create_from_string(&name, "default-spycams-list");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v4);
  UFG::PropertySetHandle::SetPropSet(&this->mProperties, PropertySet);
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         this->mProperties.mpPropSet,
         (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_List_1,
         DEPTH_RECURSE);
  v7 = v6;
  if ( v6 )
  {
    mNumElements = v6->mNumElements;
    for ( i = 0; i < mNumElements; ++i )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, i);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v11 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v11 = 0i64;
      if ( *UFG::qPropertySet::Get<bool>(
              v11,
              (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_TWSensitive_1,
              DEPTH_RECURSE) )
      {
        v12 = UFG::GameStatTracker::Instance();
        if ( UFG::GameStatTracker::GetStat(v12, Collectible_SpyCam, &v11->mName) )
        {
          name.mUID = UFG::qPropertySet::Get<UFG::qSymbol>(
                        v11,
                        (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_TWName_1,
                        DEPTH_RECURSE)->mUID;
          v13 = UFG::GameStatTracker::Instance();
          if ( UFG::GameStatTracker::GetStat(v13, Collectible_EnforcerUnlocked, &name) )
          {
            v14 = UFG::ProgressionTracker::Instance();
            ActiveMaster = UFG::ProgressionTracker::GetActiveMaster(v14);
            if ( ActiveMaster )
            {
              v16 = 1;
              if ( UFG::ProgressionTracker::IsRunningCriticalActiveMaster(v14) )
              {
                v2 |= 1u;
                if ( ActiveMaster->mNode.mUID != UFG::qSymbol::create_from_string(&result, "C_PS2")->mUID )
                  v16 = 0;
              }
              if ( (v2 & 1) != 0 )
                v2 &= ~1u;
              if ( v16 )
              {
                v17 = UFG::qPropertySet::Get<char const *>(
                        v11,
                        (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_Neighborhood_1,
                        DEPTH_RECURSE);
                `eh vector constructor iterator(
                  &ptr,
                  0x30ui64,
                  1,
                  (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
                v18.NValue = (double)(int)UFG::UIHKScreenSpyPC::GetNeighborhoodId(v17);
                if ( (ptr.Type & 0x40) != 0 )
                {
                  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
                    ptr.pObjectInterface,
                    &ptr,
                    ptr.mValue);
                  ptr.pObjectInterface = 0i64;
                }
                ptr.Type = VT_Number;
                ptr.mValue = v18;
                if ( pObject )
                  Scaleform::GFx::Movie::Invoke(pObject, "setForTW", 0i64, &ptr, 1u);
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
    }
  }
  return 1i64;
}

// File Line: 184
// RVA: 0x5E83F0
__int64 __fastcall UFG::UIHKScreenSpyPC::GetNeighborhoodId(const char *neighborhood)
{
  int v3; // eax
  unsigned int v4; // ecx

  if ( !(unsigned int)UFG::qStringCompare(neighborhood, "CT", -1) )
    return 1i64;
  if ( !(unsigned int)UFG::qStringCompare(neighborhood, "NP", -1) )
    return 2i64;
  if ( !(unsigned int)UFG::qStringCompare(neighborhood, "AB", -1) )
    return 3i64;
  v3 = UFG::qStringCompare(neighborhood, "KT", -1);
  v4 = 0;
  if ( !v3 )
    return 4;
  return v4;
}

// File Line: 197
// RVA: 0x640050
void __fastcall UFG::UIHKScreenSpyPC::update(UFG::UIHKScreenSpyPC *this, float elapsed)
{
  char v3; // bl
  UFG::qWiseSymbol *v4; // rax
  bool v5; // si
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+8h] BYREF

  v3 = 0;
  ((void (__fastcall *)(UFG::UIHKScreenSpyPC *))this->vfptr[1].__vecDelDtor)(this);
  v5 = 0;
  if ( !this->mbMusicPlay )
  {
    v4 = UFG::qWiseSymbol::create_from_string(&result, "mg_spy_cam");
    v3 = 1;
    if ( UFG::TiDo::BankLoaded(v4->mUID) )
      v5 = 1;
  }
  if ( (v3 & 1) != 0 )
    _((AMD_HD3D *)result.mUID);
  if ( v5 )
  {
    if ( (_S25_2 & 1) == 0 )
    {
      _S25_2 |= 1u;
      Set_State_minigame_mus_start_2.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_start", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_start_2.mUID);
      atexit(UFG::UIHKScreenSpyPC::update_::_5_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_start__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_start_2.mUID);
    this->mbMusicPlay = 1;
  }
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 211
// RVA: 0x61D670
void __fastcall UFG::UIHKScreenSpyPC::UpdateTime(UFG::UIHKScreenSpyPC *this)
{
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::TimeOfDayManager *Instance; // rax
  unsigned int v4; // edx
  unsigned int v5; // ecx
  const char *v6; // rax
  bool m_IsKeyboardController; // bl
  Scaleform::GFx::Value v8; // [rsp+28h] [rbp-39h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+58h] [rbp-9h] BYREF
  __int64 v10; // [rsp+88h] [rbp+27h]
  UFG::qString result; // [rsp+90h] [rbp+2Fh] BYREF

  v10 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Instance = UFG::TimeOfDayManager::GetInstance();
    v4 = (int)(float)(Instance->m_SecondsSinceMidnight * 0.00027777778);
    v5 = (int)(float)((float)(Instance->m_SecondsSinceMidnight - (float)((float)(int)v4 * 3600.0)) * 0.016666668);
    if ( v5 != this->mCurrentTime )
    {
      this->mCurrentTime = v5;
      v6 = "AM";
      if ( v4 > 0xC )
      {
        v4 -= 12;
        v6 = "PM";
      }
      UFG::qString::FormatEx(&result, "%02u:%02u %s", v4, v5, v6);
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_String;
      pargs.mValue.pString = result.mData;
      Scaleform::GFx::Movie::Invoke(pObject, "SpyPC_SetTime", 0i64, &pargs, 1u);
      v8.pObjectInterface = 0i64;
      v8.Type = VT_Undefined;
      m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
      v8.Type = VT_Boolean;
      v8.mValue.BValue = m_IsKeyboardController;
      Scaleform::GFx::Movie::Invoke(pObject, "Show_PCCtrls", 0i64, &v8, 1u);
      if ( (v8.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v8.pObjectInterface->vfptr->gap8[8])(
          v8.pObjectInterface,
          &v8,
          v8.mValue);
        v8.pObjectInterface = 0i64;
      }
      v8.Type = VT_Undefined;
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_Undefined;
      UFG::qString::~qString(&result);
    }
  }
}

// File Line: 247
// RVA: 0x62C640
char __fastcall UFG::UIHKScreenSpyPC::handleMessage(
        UFG::UIHKScreenSpyPC *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r15
  unsigned int v4; // esi
  UFG::UIHKScreenSpyPC::eState mState; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::UIHKScreenSpyPC::eNeighborhood NValue; // ebx
  unsigned int v11; // eax
  unsigned int v12; // eax
  SSClass *v13; // rbx
  SSInstance *v14; // rcx
  const char *v15; // rdx
  unsigned int v16; // eax
  Scaleform::GFx::Value::ValueUnion v17; // xmm6_8
  UFG::UIScreenTextureManager *v18; // rax
  bool v19; // bl
  UFG::qSymbol *v20; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v22; // rax
  UFG::qPropertyList *v23; // r13
  unsigned int mNumElements; // r12d
  unsigned int v25; // r15d
  char *ValuePtr; // rax
  UFG::qPropertySet *v27; // rbx
  char *v28; // rax
  int *v29; // rax
  UFG::qSymbol *v30; // r15
  UFG::qSymbol *v31; // r12
  UFG::GameStatTracker *v32; // rax
  bool Stat; // al
  ASymbol *v34; // rcx
  unsigned int v35; // ebx
  SSClass *v36; // rax
  SSInstance *v37; // r15
  ASymbol *v38; // rax
  unsigned int v39; // eax
  UFG::UIScreenTextureManager *v40; // rax
  UFG::qString v41; // [rsp+10h] [rbp-41h] BYREF
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-19h] BYREF
  ASymbol result; // [rsp+B8h] [rbp+67h] BYREF
  UFG::UIMessage *v44; // [rsp+C8h] [rbp+77h]
  SSInstance *args_pp; // [rsp+D0h] [rbp+7Fh] BYREF

  v3 = msg;
  v4 = msgId;
  mState = this->mState;
  if ( mState == STATE_COMPLETE )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  if ( msgId == UI_HASH_PLAYSOUND_20 )
  {
    UFG::qString::qString(&v41, (UFG::qString *)&msg[1]);
    v7 = UFG::TiDo::CalcWwiseUid(v41.mData);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v7, 0i64, 0, 0i64);
    UFG::qString::~qString(&v41);
    return 1;
  }
  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  if ( mState == STATE_NORMAL )
  {
    if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    {
      pval.pObjectInterface = 0i64;
      pval.Type = VT_Undefined;
      Scaleform::GFx::Movie::GetVariable(pObject, &pval, "currentAntenna");
      NValue = (int)pval.mValue.NValue;
      v11 = UFG::TiDo::CalcWwiseUid("Play_sp_accept");
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v11, 0i64, 0, 0i64);
      this->mNeighborhood = NValue;
      this->mState = STATE_DANGER;
      UFG::UIHKScreenSpyPC::LoadNeighborhoodTexturePack(this);
      if ( (pval.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          pval.mValue);
        pval.pObjectInterface = 0i64;
      }
      pval.Type = VT_Undefined;
      goto LABEL_78;
    }
    if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      this->mFinished = 1;
      v12 = UFG::TiDo::CalcWwiseUid("Play_sp_back");
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v12, 0i64, 0, 0i64);
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
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
      v15 = "highlightNeighborhoodDown";
    }
    else
    {
      if ( msgId != UI_HASH_DPAD_UP_PRESSED_30 && msgId != UI_HASH_THUMBSTICK_LEFT_UP_30 )
        goto LABEL_78;
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
      v15 = "highlightNeighborhoodUp";
    }
    goto LABEL_77;
  }
  if ( mState != STATE_DANGER )
  {
LABEL_78:
    msg = v3;
    msgId = v4;
    return UFG::UIScreen::handleMessage(this, msgId, msg);
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
    Scaleform::GFx::Movie::Invoke(pObject, v15, 0i64, 0i64, 0);
    goto LABEL_78;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    this->mState = STATE_NORMAL;
    v16 = UFG::TiDo::CalcWwiseUid("Play_sp_back");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v16, 0i64, 0, 0i64);
    *(_QWORD *)&v41.mMagic = Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator(&pval, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v17.NValue = (double)(int)this->mState;
    if ( (pval.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
      pval.pObjectInterface = 0i64;
    }
    pval.Type = VT_Number;
    pval.mValue = v17;
    Scaleform::GFx::Movie::Invoke(pObject, "setState", 0i64, &pval, 1u);
    Scaleform::GFx::Movie::Invoke(pObject, "resetNeighborhoodScreen", 0i64, 0i64, 0);
    v18 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v18, UFG::UIHKScreenSpyPC::gGridTexturePackFilename);
    `eh vector destructor iterator(&pval, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    goto LABEL_78;
  }
  if ( msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    goto LABEL_78;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::Invoke(pObject, "confirmCameraStatus", 0i64, &customCaption);
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "selectedSlot");
  args_pp = (SSInstance *)(unsigned int)(int)pval.mValue.NValue;
  if ( (_DWORD)args_pp != -1 )
  {
    v20 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "default-spycams-list");
    PropertySet = UFG::PropertySetManager::GetPropertySet(v20);
    UFG::PropertySetHandle::SetPropSet(&this->mProperties, PropertySet);
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v22 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            this->mProperties.mpPropSet,
            (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_List_1,
            DEPTH_RECURSE);
    v23 = v22;
    if ( v22 && (mNumElements = v22->mNumElements, v25 = 0, mNumElements) )
    {
      while ( 1 )
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v23, 0x1Au, v25);
        if ( !ValuePtr || (v27 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
          v27 = 0i64;
        v28 = UFG::qPropertySet::Get<char const *>(
                v27,
                (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_Neighborhood_1,
                DEPTH_RECURSE);
        if ( !(unsigned int)UFG::qStringCompare(v28, this->mCurrentNeighborhood, -1) )
        {
          v29 = UFG::qPropertySet::Get<long>(v27, (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_Index_1, DEPTH_RECURSE);
          if ( *v29 == (_DWORD)args_pp )
            break;
        }
        if ( ++v25 >= mNumElements )
          goto LABEL_59;
      }
    }
    else
    {
LABEL_59:
      v27 = 0i64;
    }
    v30 = UFG::qPropertySet::Get<UFG::qSymbol>(
            v27,
            (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_CameraMarker_1,
            DEPTH_RECURSE);
    v31 = UFG::qPropertySet::Get<UFG::qSymbol>(
            v27,
            (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_TeleportMarker_1,
            DEPTH_RECURSE);
    UFG::qPropertySet::Get<UFG::qSymbol>(v27, (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_SliceName_1, DEPTH_RECURSE);
    if ( *UFG::qPropertySet::Get<bool>(v27, (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_TWSensitive_1, DEPTH_RECURSE) )
    {
      result.i_uid = UFG::qPropertySet::Get<UFG::qSymbol>(
                       v27,
                       (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_TWName_1,
                       DEPTH_RECURSE)->mUID;
      v32 = UFG::GameStatTracker::Instance();
      Stat = UFG::GameStatTracker::GetStat(v32, Collectible_EnforcerUnlocked, (UFG::qSymbol *)&result);
      v34 = (ASymbol *)v30;
      if ( Stat )
      {
        v35 = 4;
        SSSymbol::as_instance((ASymbol *)v30);
        SSSymbol::as_instance((ASymbol *)v31);
        *(_QWORD *)&v41.mMagic = SSSymbol::as_instance(&result);
        v41.mData = (char *)SSBoolean::pool_new(1);
        this->mbTriadSensitive = 1;
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
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v39, 0i64, 0, 0i64);
        this->mState = STATE_COMPLETE;
        UFG::UIHK_NISOverlay::ShowCurtains(1.0, 0);
        v40 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueLoadAndPush(v40, "SpyCam", 0i64);
        if ( (pval.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
            pval.pObjectInterface,
            &pval,
            pval.mValue);
          pval.pObjectInterface = 0i64;
        }
        pval.Type = VT_Undefined;
        v3 = v44;
        goto LABEL_78;
      }
    }
    else
    {
      v34 = (ASymbol *)v30;
    }
    v35 = 2;
    SSSymbol::as_instance(v34);
    v41.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)SSSymbol::as_instance((ASymbol *)v31);
    goto LABEL_65;
  }
  v19 = UFG::UIScreen::handleMessage(this, v4, v3);
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  pval.Type = VT_Undefined;
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
    case CYLINDER:
      this->mCurrentNeighborhood = "CT";
      v1 = "Data\\UI\\CTCameras_texturepack.perm.bin";
      goto LABEL_9;
    case TRIANGLE:
      this->mCurrentNeighborhood = "NP";
      v1 = "Data\\UI\\NPCameras_texturepack.perm.bin";
      goto LABEL_9;
    case BOX:
      this->mCurrentNeighborhood = "AB";
      v1 = "Data\\UI\\ABCameras_texturepack.perm.bin";
      goto LABEL_9;
    case CAPSULE:
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
    (UFG::qReflectInventoryBase *)UFG::UIHKScreenSpyPC::TextureLoadedCallback,
    (UFG::qReflectInventoryBase *)"SpyPC");
}

// File Line: 498
// RVA: 0x612940
void __fastcall UFG::UIHKScreenSpyPC::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenSpyPC *Screen; // rax

  Screen = (UFG::UIHKScreenSpyPC *)UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SpyPC");
  if ( Screen )
    UFG::UIHKScreenSpyPC::HandleTextureLoaded(Screen);
}

// File Line: 512
// RVA: 0x5EC240
void __fastcall UFG::UIHKScreenSpyPC::HandleTextureLoaded(UFG::UIHKScreenSpyPC *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value::ValueUnion v3; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v3.NValue = (double)(int)this->mState;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Number;
  pargs.mValue = v3;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "setState", 0i64, &pargs, 1u);
  UFG::UIHKScreenSpyPC::processUnlockedCameras(this);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 528
// RVA: 0x639780
void __fastcall UFG::UIHKScreenSpyPC::processUnlockedCameras(UFG::UIHKScreenSpyPC *this)
{
  int v2; // r14d
  __int64 v3; // rdi
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::MapFloat *MapBool; // rax
  UFG::qSymbol *v6; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v8; // r13
  unsigned int mNumElements; // r15d
  __int64 *v10; // r12
  unsigned int v11; // ebx
  _DWORD *v12; // rsi
  char *ValuePtr; // rax
  UFG::qPropertySet *v14; // rdi
  char *v15; // rax
  int *v16; // rbx
  char *v17; // rsi
  Scaleform::GFx::Value::ValueUnion v18; // xmm6_8
  UFG::ProgressionTracker *v19; // rsi
  UFG::GameStatTracker *v20; // rax
  UFG::GameSlice *ActiveMaster; // rbx
  bool v22; // al
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+38h] [rbp-C8h] BYREF
  Scaleform::GFx::Movie *pObject; // [rsp+48h] [rbp-B8h]
  Scaleform::GFx::Value ptr; // [rsp+50h] [rbp-B0h] BYREF
  char v26[16]; // [rsp+80h] [rbp-80h] BYREF
  __int64 v27; // [rsp+90h] [rbp-70h]
  int v28; // [rsp+98h] [rbp-68h]
  char *v29; // [rsp+A0h] [rbp-60h]
  char v30[16]; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v31; // [rsp+C0h] [rbp-40h]
  int v32; // [rsp+C8h] [rbp-38h]
  __int64 v33; // [rsp+D0h] [rbp-30h]
  char v34[16]; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v35; // [rsp+F0h] [rbp-10h]
  int v36; // [rsp+F8h] [rbp-8h]
  __int64 v37; // [rsp+100h] [rbp+0h]
  __int64 v38; // [rsp+110h] [rbp+10h]
  __int64 v39[6]; // [rsp+120h] [rbp+20h] BYREF
  UFG::qSymbol name; // [rsp+258h] [rbp+158h] BYREF
  UFG::qSymbol v42; // [rsp+260h] [rbp+160h] BYREF
  __int64 v43; // [rsp+268h] [rbp+168h]

  v38 = -2i64;
  v2 = 0;
  pObject = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::Invoke(pObject, "resetCameras", 0i64, 0i64, 0);
  v3 = 0i64;
  v4 = UFG::GameStatTracker::Instance();
  MapBool = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBool(v4, Collectible_SpyCam);
  UFG::PersistentData::MapInt::GetIterator(MapBool, &result);
  while ( UFG::PersistentData::MapBool::Iterator::IsValid((UFG::PersistentData::MapBool::Iterator *)&result) )
  {
    if ( UFG::PersistentData::MapBool::Iterator::GetStatus((UFG::PersistentData::MapBool::Iterator *)&result) )
    {
      v39[v3] = (__int64)UFG::PersistentData::MapBool::Iterator::GetName((UFG::PersistentData::MapBool::Iterator *)&result);
      v3 = (unsigned int)(v3 + 1);
    }
    UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
  }
  v6 = UFG::qSymbol::create_from_string(&name, "default-spycams-list");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v6);
  UFG::PropertySetHandle::SetPropSet(&this->mProperties, PropertySet);
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         this->mProperties.mpPropSet,
         (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_List_1,
         DEPTH_RECURSE);
  mNumElements = v8->mNumElements;
  if ( (_DWORD)v3 )
  {
    v10 = v39;
    v43 = (unsigned int)v3;
    do
    {
      v11 = 0;
      if ( mNumElements )
      {
        v12 = (_DWORD *)*v10;
        while ( 1 )
        {
          ValuePtr = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v11);
          if ( ValuePtr && *(_QWORD *)ValuePtr )
            v14 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
          else
            v14 = 0i64;
          if ( *v12 == v14->mName.mUID )
          {
            v15 = UFG::qPropertySet::Get<char const *>(
                    v14,
                    (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_Neighborhood_1,
                    DEPTH_RECURSE);
            if ( !(unsigned int)UFG::qStringCompare(v15, this->mCurrentNeighborhood, -1) )
              break;
          }
          if ( ++v11 >= mNumElements )
            goto LABEL_39;
        }
        v16 = UFG::qPropertySet::Get<long>(v14, (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_Index_1, DEPTH_RECURSE);
        v17 = UFG::qPropertySet::Get<char const *>(
                v14,
                (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_Name_1,
                DEPTH_RECURSE);
        `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        v18.NValue = (double)*v16;
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        ptr.Type = VT_Number;
        ptr.mValue = v18;
        if ( (v28 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v27 + 16i64))(v27, v26, v29);
          v27 = 0i64;
        }
        v28 = 6;
        v29 = v17;
        if ( (v32 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v31 + 16i64))(v31, v30, v33);
          v31 = 0i64;
        }
        v32 = 2;
        LOBYTE(v33) = 0;
        if ( (v36 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v35 + 16i64))(v35, v34, v37);
          v35 = 0i64;
        }
        v36 = 2;
        LOBYTE(v37) = 0;
        v19 = UFG::ProgressionTracker::Instance();
        if ( *UFG::qPropertySet::Get<bool>(
                v14,
                (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_TWSensitive_1,
                DEPTH_RECURSE) )
        {
          name.mUID = UFG::qPropertySet::Get<UFG::qSymbol>(
                        v14,
                        (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_TWName_1,
                        DEPTH_RECURSE)->mUID;
          v20 = UFG::GameStatTracker::Instance();
          if ( UFG::GameStatTracker::GetStat(v20, Collectible_EnforcerUnlocked, &name) )
          {
            ActiveMaster = UFG::ProgressionTracker::GetActiveMaster(v19);
            if ( ActiveMaster )
            {
              v22 = 1;
              if ( UFG::ProgressionTracker::IsRunningCriticalActiveMaster(v19) )
              {
                v2 |= 1u;
                if ( ActiveMaster->mNode.mUID != UFG::qSymbol::create_from_string(&v42, "C_PS2")->mUID )
                  v22 = 0;
              }
              if ( (v2 & 1) != 0 )
                v2 &= ~1u;
              if ( v22 )
              {
                if ( (v36 & 0x40) != 0 )
                {
                  (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v35 + 16i64))(v35, v34, v37);
                  v35 = 0i64;
                }
                v36 = 2;
                LOBYTE(v37) = 1;
              }
            }
          }
        }
        Scaleform::GFx::Movie::Invoke(pObject, "addCameras", 0i64, &ptr, 4u);
        `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
LABEL_39:
      ++v10;
      --v43;
    }
    while ( v43 );
  }
}

