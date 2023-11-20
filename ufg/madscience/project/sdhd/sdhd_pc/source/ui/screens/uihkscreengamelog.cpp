// File Line: 30
// RVA: 0x156B1D0
__int64 UFG::_dynamic_initializer_for__UI_HASH_E_COMBAT_TRAIN_TITLE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("E_COMBAT_TRAIN_TITLE", 0xFFFFFFFF);
  UI_HASH_E_COMBAT_TRAIN_TITLE = result;
  return result;
}

// File Line: 31
// RVA: 0x156AB70
__int64 UFG::_dynamic_initializer_for__UI_HASH_COMMON_TRC_PS3_PSN_SIGNED_OUT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("COMMON_TRC_PS3_PSN_SIGNED_OUT", 0xFFFFFFFF);
  UI_HASH_COMMON_TRC_PS3_PSN_SIGNED_OUT = result;
  return result;
}

// File Line: 32
// RVA: 0x156AB50
__int64 UFG::_dynamic_initializer_for__UI_HASH_COMMON_TRC_PS3_ETHERNET_CABLE_UNPLUGGED__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("COMMON_TRC_PS3_ETHERNET_CABLE_UNPLUGGED", 0xFFFFFFFF);
  UI_HASH_COMMON_TRC_PS3_ETHERNET_CABLE_UNPLUGGED = result;
  return result;
}

// File Line: 36
// RVA: 0x6207E0
UFG::GameLogManager *__fastcall UFG::GameLogManager::getInstance()
{
  if ( !(_S15_5 & 1) )
  {
    _S15_5 |= 1u;
    glManager.vfptr = (UFG::GameLogManagerVtbl *)&UFG::GameLogManager::`vftable;
    atexit(UFG::GameLogManager::getInstance_::_2_::_dynamic_atexit_destructor_for__glManager__);
  }
  return &glManager;
}

// File Line: 53
// RVA: 0x5E74C0
UFG::GameLogManager::cGameLogCircularArray *__fastcall UFG::GameLogManager::GetDataArray(UFG::GameLogManager *this)
{
  UFG::GameStatTracker *v1; // rax
  UFG::PersistentData::Binary *v2; // rax
  UFG::allocator::free_link *v4; // rax
  void *v5; // rax
  void *v6; // rbx
  UFG::GameStatTracker *v7; // rax
  UFG::PersistentData::Binary binary; // [rsp+28h] [rbp-20h]

  v1 = UFG::GameStatTracker::Instance();
  v2 = UFG::GameStatTracker::GetStat(v1, GameLog);
  if ( v2->mSize )
    return (UFG::GameLogManager::cGameLogCircularArray *)v2->mpBuffer;
  v4 = UFG::qMalloc(0x32Cui64, UFG::gGlobalNewName, 0i64);
  if ( v4 )
  {
    UFG::GameLogManager::cGameLogCircularArray::cGameLogCircularArray((UFG::GameLogManager::cGameLogCircularArray *)v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  binary.mpBuffer = v6;
  binary.mSize = 812;
  v7 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v7, GameLog, &binary);
  return (UFG::GameLogManager::cGameLogCircularArray *)v6;
}

// File Line: 75
// RVA: 0x5F1D10
void __fastcall UFG::GameLogManager::LogItem(UFG::GameLogManager *this, __int64 log_type, unsigned int string_hash)
{
  unsigned int v3; // ebx
  unsigned int *v4; // rsi
  UFG::GameLogManager::cGameLogCircularArray *v5; // rax
  UFG::GameLogManager::cGameLogCircularArray *v6; // rdi
  unsigned int v7; // ecx
  UFG::GameLogManager::sGameLogEntry obj; // [rsp+48h] [rbp+20h]

  v3 = string_hash;
  v4 = (unsigned int *)log_type;
  if ( string_hash != UI_HASH_E_COMBAT_TRAIN_TITLE
    && string_hash != UI_HASH_COMMON_TRC_PS3_PSN_SIGNED_OUT
    && string_hash != UI_HASH_COMMON_TRC_PS3_ETHERNET_CABLE_UNPLUGGED )
  {
    v5 = UFG::GameLogManager::GetDataArray(this);
    v6 = v5;
    if ( v5 )
    {
      if ( (unsigned int)UFG::GameLogManager::cGameLogCircularArray::Count(v5) >= 0x64 )
        UFG::GameLogManager::cGameLogCircularArray::RemoveHead(v6);
      v7 = *v4;
      obj.string_hash = v3;
      obj.type.mUID = v7;
      UFG::GameLogManager::cGameLogCircularArray::AddTail(v6, &obj);
    }
  }
}

// File Line: 103
// RVA: 0x5F1D90
void __fastcall UFG::GameLogManager::LogItem(UFG::GameLogManager *this, __int64 log_type, const char *text)
{
  const char *v3; // rbx
  unsigned int *v4; // rdi
  UFG::GameLogManager *v5; // rsi
  unsigned int v6; // eax
  UFG::UIGfxTranslator *v7; // rcx
  unsigned int v8; // er8
  UFG::qSymbol log_typea; // [rsp+50h] [rbp+18h]
  UFG::qSymbol *v10; // [rsp+58h] [rbp+20h]

  if ( text )
  {
    v3 = text;
    v4 = (unsigned int *)log_type;
    v5 = this;
    if ( (signed int)UFG::qStringLength(text) >= 1 )
    {
      if ( *v3 == 36 )
        ++v3;
      v6 = UFG::qStringHashUpper32(v3, 0xFFFFFFFF);
      v7 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v7 )
      {
        if ( v7->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, v6) )
        {
          v10 = &log_typea;
          log_typea.mUID = *v4;
          v8 = UFG::qStringHashUpper32(v3, 0xFFFFFFFF);
          UFG::GameLogManager::LogItem(v5, (__int64)&log_typea, v8);
        }
      }
    }
  }
}

// File Line: 132
// RVA: 0x5D4FC0
void __fastcall UFG::GameLogManager::Clear(UFG::GameLogManager *this)
{
  UFG::GameLogManager::cGameLogCircularArray *v1; // rax

  v1 = UFG::GameLogManager::GetDataArray(this);
  if ( v1 )
    *(_QWORD *)&v1->mHeadIndex = -1i64;
}

// File Line: 144
// RVA: 0x5E8230
void __fastcall UFG::GameLogManager::GetLogEntries(UFG::GameLogManager *this, UFG::qCircularArray<UFG::GameLogManager::sGameLogEntry const *> *list, __int64 log_type)
{
  _DWORD *v3; // r14
  UFG::qCircularArray<UFG::GameLogManager::sGameLogEntry const *> *v4; // rbx
  UFG::GameLogManager::cGameLogCircularArray *v5; // rax
  UFG::GameLogManager::cGameLogCircularArray *v6; // rsi
  int v7; // edi
  UFG::GameLogManager::sGameLogEntry *v8; // rax
  unsigned int v9; // edx
  int v10; // ecx
  unsigned int v11; // ecx
  int v12; // er8

  v3 = (_DWORD *)log_type;
  v4 = list;
  *(_QWORD *)&list->mHeadIndex = -1i64;
  v5 = UFG::GameLogManager::GetDataArray(this);
  v6 = v5;
  if ( v5 )
  {
    v7 = 0;
    if ( (signed int)UFG::GameLogManager::cGameLogCircularArray::Count(v5) > 0 )
    {
      do
      {
        if ( UFG::GameLogManager::cGameLogCircularArray::operator[](v6, v7)->type.mUID == *v3 )
        {
          v8 = UFG::GameLogManager::cGameLogCircularArray::operator[](v6, v7);
          v9 = v4->mHeadIndex;
          if ( v9 == -1 )
          {
            v10 = 0;
          }
          else
          {
            v11 = v4->mTailIndex;
            v10 = v9 <= v11 ? v11 - v9 + 1 : v4->mCapacity - v9 + v11 + 1;
          }
          v12 = v4->mCapacity;
          if ( v10 < v12 )
          {
            if ( v10 )
            {
              if ( v9 )
                v4->mHeadIndex = (v9 - 1) % v12;
              else
                v4->mHeadIndex = v12 - 1;
            }
            else
            {
              *(_QWORD *)&v4->mHeadIndex = 0i64;
            }
            v4->mData[v4->mHeadIndex] = v8;
          }
        }
        ++v7;
      }
      while ( v7 < (signed int)UFG::GameLogManager::cGameLogCircularArray::Count(v6) );
    }
  }
}

// File Line: 162
// RVA: 0x5E6A50
void __fastcall UFG::GameLogManager::GetAllLogEntries(UFG::GameLogManager *this, UFG::qCircularArray<UFG::GameLogManager::sGameLogEntry const *> *list)
{
  UFG::qCircularArray<UFG::GameLogManager::sGameLogEntry const *> *v2; // rbx
  UFG::GameLogManager::cGameLogCircularArray *v3; // rax
  UFG::GameLogManager::cGameLogCircularArray *v4; // rsi
  int v5; // edi
  UFG::GameLogManager::sGameLogEntry *v6; // rax
  unsigned int v7; // edx
  int v8; // ecx
  unsigned int v9; // ecx
  int v10; // er8

  v2 = list;
  *(_QWORD *)&list->mHeadIndex = -1i64;
  v3 = UFG::GameLogManager::GetDataArray(this);
  v4 = v3;
  if ( v3 )
  {
    v5 = 0;
    if ( (signed int)UFG::GameLogManager::cGameLogCircularArray::Count(v3) > 0 )
    {
      do
      {
        v6 = UFG::GameLogManager::cGameLogCircularArray::operator[](v4, v5);
        v7 = v2->mHeadIndex;
        if ( v7 == -1 )
        {
          v8 = 0;
        }
        else
        {
          v9 = v2->mTailIndex;
          if ( v7 <= v9 )
            v8 = v9 - v7 + 1;
          else
            v8 = v2->mCapacity - v7 + v9 + 1;
        }
        v10 = v2->mCapacity;
        if ( v8 < v10 )
        {
          if ( v8 )
          {
            if ( v7 )
              v2->mHeadIndex = (v7 - 1) % v10;
            else
              v2->mHeadIndex = v10 - 1;
          }
          else
          {
            *(_QWORD *)&v2->mHeadIndex = 0i64;
          }
          v2->mData[v2->mHeadIndex] = v6;
        }
        ++v5;
      }
      while ( v5 < (signed int)UFG::GameLogManager::cGameLogCircularArray::Count(v4) );
    }
  }
}

// File Line: 188
// RVA: 0x5C52E0
void __fastcall UFG::UIHKScreenGameLog::UIHKScreenGameLog(UFG::UIHKScreenGameLog *this)
{
  UFG::UIHKScreenGameLog *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  unsigned __int64 v3; // rax

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGameLog::`vftable;
  this->m_bShouldRefesh = 0;
  this->mCurrentTab = 0;
  this->m_aCurrentTabItems.mCapacity = 100;
  this->m_aCurrentTabItems.mpMemoryPool = 0i64;
  v3 = 800i64;
  if ( !is_mul_ok(0x64ui64, 8ui64) )
    v3 = -1i64;
  this->m_aCurrentTabItems.mData = (UFG::GameLogManager::sGameLogEntry **)UFG::qMalloc(
                                                                            v3,
                                                                            "qCircularArray::mData",
                                                                            0i64);
  *(_QWORD *)&v1->m_aCurrentTabItems.mHeadIndex = -1i64;
}

// File Line: 193
// RVA: 0x5CAB80
void __fastcall UFG::UIHKScreenGameLog::~UIHKScreenGameLog(UFG::UIHKScreenGameLog *this)
{
  UFG::UIHKScreenGameLog *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *v4; // rdi
  unsigned int v5; // eax
  UFG::qMemoryPool *v6; // rcx

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGameLog::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "GameLog");
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  v4 = &v3->HelpBar;
  v5 = UFG::qStringHash32("gamelog", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v4, v5);
  *(_QWORD *)&v1->m_aCurrentTabItems.mHeadIndex = -1i64;
  v6 = v1->m_aCurrentTabItems.mpMemoryPool;
  if ( v6 )
    UFG::qMemoryPool::Free(v6, v1->m_aCurrentTabItems.mData);
  else
    operator delete[](v1->m_aCurrentTabItems.mData);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 201
// RVA: 0x6318A0
void __fastcall UFG::UIHKScreenGameLog::init(UFG::UIHKScreenGameLog *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenGameLog *v2; // rsi
  unsigned int v3; // er14
  int v4; // ecx
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rbx
  unsigned int v8; // er14
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rbx
  UFG::UIHKScreenGlobalOverlay *v13; // rax
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h]
  __int64 v15; // [rsp+60h] [rbp-88h]
  int v16[2]; // [rsp+68h] [rbp-80h]
  UFG::UIHKHelpBarData dataa; // [rsp+70h] [rbp-78h]

  v15 = -2i64;
  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
  dataa.id = UFG::qStringHash32("gamelog", 0xFFFFFFFF);
  dataa.alignment = 0;
  v3 = UI_HASH_BUTTON_R1_PRESSED_30;
  v4 = 0;
  v5 = 0i64;
  while ( v16[v5] )
  {
    ++v4;
    if ( ++v5 >= 6 )
      goto LABEL_6;
  }
  v6 = v4;
  v16[v4] = 13;
  v7 = v4;
  UFG::qString::Set((UFG::qString *)&dataa.Buttons[10 * v4], "$HELPBAR_CHANGE_SECTION_UC");
  UFG::qString::Set((UFG::qString *)((char *)&dataa.Captions[v7 + 5] + 16), &customWorldMapCaption);
  *(&dataa.Icons[5].mMagic + v6) = v3;
LABEL_6:
  v8 = UI_HASH_BUTTON_BACK_PRESSED_30;
  v9 = 0;
  v10 = 0i64;
  while ( v16[v10] )
  {
    ++v9;
    if ( ++v10 >= 6 )
      goto LABEL_11;
  }
  v11 = v9;
  v16[v9] = 2;
  v12 = v9;
  UFG::qString::Set((UFG::qString *)&dataa.Buttons[10 * v9], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set((UFG::qString *)((char *)&dataa.Captions[v12 + 5] + 16), &customWorldMapCaption);
  *(&dataa.Icons[5].mMagic + v11) = v8;
LABEL_11:
  v13 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v13 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v13->HelpBar, &dataa);
  v2->m_Movie = v2->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 0;
  pargs.Type = 5;
  pargs.mValue.NValue = DOUBLE_100_0;
  Scaleform::GFx::Movie::Invoke(v2->m_Movie, "SetNumSlots", 0i64, &pargs, 1u);
  UFG::UIHKScreenGameLog::UpdateList(v2);
  v2->m_bShouldRefesh = 1;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 0;
  UFG::qString::~qString((UFG::qString *)dataa.MessageIds);
  `eh vector destructor iterator(
    &dataa.Captions[5].mMagic,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(dataa.Buttons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 224
// RVA: 0x63CD40
void __fastcall UFG::UIHKScreenGameLog::update(UFG::UIHKScreenGameLog *this, float elapsed)
{
  UFG::UIHKScreenGameLog *v2; // rbx

  v2 = this;
  UFG::UIScreen::update((UFG::UIScreen *)&this->vfptr, elapsed);
  if ( v2->m_bShouldRefesh )
  {
    v2->m_bShouldRefesh = 0;
    UFG::UIHKScreenGameLog::Refresh(v2);
  }
}

// File Line: 236
// RVA: 0x623060
bool __fastcall UFG::UIHKScreenGameLog::handleMessage(UFG::UIHKScreenGameLog *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // ebx
  UFG::UIHKScreenUpgrades *v5; // rdi
  UFG::UIScreen *v6; // rax
  UFG::UIHKScreenGlobalOverlay *v7; // rcx
  bool result; // al

  v3 = msg;
  v4 = msgId;
  v5 = (UFG::UIHKScreenUpgrades *)this;
  if ( msgId == UI_HASH_BUTTON_START_PRESSED_30 || msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xA4E5BFBD,
        0i64,
        0,
        0i64);
    result = 1;
  }
  else
  {
    if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30
      || msgId == UI_HASH_DPAD_UP_REPEAT_30 )
    {
      UFG::UIHKScreenGameLog::ScrollUp(this);
      return 1;
    }
    if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
      || msgId == UI_HASH_DPAD_DOWN_REPEAT_30 )
    {
      UFG::UIHKScreenGameLog::ScrollDown(this);
      return 1;
    }
    if ( msgId == UI_HASH_MOUSE_WHEEL_SCROLL_30 )
    {
      if ( SLODWORD(msg[1].mPrev) <= 0 )
        UFG::UIHKScreenGameLog::ScrollDown(this);
      else
        UFG::UIHKScreenGameLog::ScrollUp(this);
LABEL_12:
      v6 = UFG::UIScreenManagerBase::getOverlay(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             "GlobalOverlay");
      if ( v6 )
      {
        v7 = UFG::UIHKScreenGlobalOverlay::mThis;
        if ( !UFG::UIHKScreenGlobalOverlay::mThis )
          v7 = &gGlobalOverlaySentinel;
        UFG::UIHKHelpBarWidget::HandleMessage(&v7->HelpBar, v6, v4, v3);
        result = UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
      else if ( v4 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
      {
        UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(v5, (float)SLODWORD(v3[1].vfptr), (float)SHIDWORD(v3[1].vfptr));
        result = UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
      else
      {
        if ( v4 == UI_HASH_MOUSE_SELECT_SLOT_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xC415B16F,
              0i64,
              0,
              0i64);
          v5->mCursorYPos[3] = UFG::UI::GetFlashArgsInt(v3);
          UFG::UIHKScreenGameLog::UpdateList((UFG::UIHKScreenGameLog *)v5);
          UFG::UIHKScreenGameLog::Refresh((UFG::UIHKScreenGameLog *)v5);
        }
        result = UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
      return result;
    }
    if ( msgId == UI_HASH_BUTTON_L1_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xC415B16F,
          0i64,
          0,
          0i64);
      UFG::UIHKScreenGameLog::ScrollPrevTab((UFG::UIHKScreenGameLog *)v5);
      result = 1;
    }
    else
    {
      if ( msgId != UI_HASH_BUTTON_R1_PRESSED_30 )
        goto LABEL_12;
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xC415B16F,
          0i64,
          0,
          0i64);
      UFG::UIHKScreenGameLog::ScrollNextTab((UFG::UIHKScreenGameLog *)v5);
      result = 1;
    }
  }
  return result;
}

// File Line: 303
// RVA: 0x604430
void __fastcall UFG::UIHKScreenGameLog::ScrollUp(UFG::UIHKScreenGameLog *this)
{
  unsigned int v1; // er8
  UFG::UIHKScreenGameLog *v2; // rbx
  unsigned int v3; // edx
  int v4; // edx

  v1 = this->m_aCurrentTabItems.mHeadIndex;
  v2 = this;
  if ( v1 != -1 )
  {
    v3 = this->m_aCurrentTabItems.mTailIndex;
    v4 = v1 <= v3 ? v3 - v1 + 1 : this->m_aCurrentTabItems.mCapacity - v1 + v3 + 1;
    if ( v4 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x593B70ABu,
          0i64,
          0,
          0i64);
      Scaleform::GFx::Movie::Invoke(v2->m_Movie, "ScrollUp", 0i64, 0i64, 0);
    }
  }
}

// File Line: 313
// RVA: 0x603EA0
void __fastcall UFG::UIHKScreenGameLog::ScrollDown(UFG::UIHKScreenGameLog *this)
{
  unsigned int v1; // er8
  unsigned int v2; // edx
  int v3; // edx

  v1 = this->m_aCurrentTabItems.mHeadIndex;
  if ( v1 != -1 )
  {
    v2 = this->m_aCurrentTabItems.mTailIndex;
    if ( v1 <= v2 )
      v3 = v2 - v1 + 1;
    else
      v3 = this->m_aCurrentTabItems.mCapacity - v1 + v2 + 1;
    if ( v3 )
    {
      Scaleform::GFx::Movie::Invoke(this->m_Movie, "ScrollDown", 0i64, 0i64, 0);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xB78DCE8u,
          0i64,
          0,
          0i64);
    }
  }
}

// File Line: 323
// RVA: 0x61B000
void __fastcall UFG::UIHKScreenGameLog::UpdateList(UFG::UIHKScreenGameLog *this)
{
  UFG::UIHKScreenGameLog *v1; // rbx
  UFG::qCircularArray<UFG::GameLogManager::sGameLogEntry const *> *v2; // rdx
  UFG::qSymbol *v3; // r8
  unsigned int v4; // [rsp+40h] [rbp+8h]
  unsigned int v5; // [rsp+48h] [rbp+10h]
  UFG::qSymbol log_type; // [rsp+50h] [rbp+18h]
  UFG::qSymbol *v7; // [rsp+58h] [rbp+20h]

  v1 = this;
  if ( !(_S15_5 & 1) )
  {
    _S15_5 |= 1u;
    glManager.vfptr = (UFG::GameLogManagerVtbl *)&UFG::GameLogManager::`vftable;
    atexit(UFG::GameLogManager::getInstance_::_2_::_dynamic_atexit_destructor_for__glManager__);
  }
  switch ( v1->mCurrentTab )
  {
    case 1:
      v7 = &log_type;
      log_type.mUID = qSymbol_GameLogType_Hint_20.mUID;
      v2 = &v1->m_aCurrentTabItems;
      v3 = &log_type;
      break;
    case 2:
      v7 = (UFG::qSymbol *)&v5;
      v5 = qSymbol_GameLogType_Objective_20.mUID;
      v2 = &v1->m_aCurrentTabItems;
      v3 = (UFG::qSymbol *)&v5;
      break;
    case 3:
      v7 = (UFG::qSymbol *)&v4;
      v4 = qSymbol_GameLogType_RewardsUpgrades_20.mUID;
      v2 = &v1->m_aCurrentTabItems;
      v3 = (UFG::qSymbol *)&v4;
      break;
    default:
      UFG::GameLogManager::GetAllLogEntries(&glManager, &v1->m_aCurrentTabItems);
      return;
  }
  UFG::GameLogManager::GetLogEntries(&glManager, v2, (__int64)v3);
}

// File Line: 353
// RVA: 0x5FFC90
void __fastcall UFG::UIHKScreenGameLog::Refresh(UFG::UIHKScreenGameLog *this)
{
  UFG::UIHKScreenGameLog *v1; // rbx
  signed int i; // esi
  unsigned int v3; // edx
  int v4; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // er8
  int v7; // ecx
  unsigned int v8; // ecx
  int v9; // edx
  unsigned int v10; // er8
  signed int v11; // edx
  __int64 v12; // rdx
  UFG::UIGfxTranslator *v13; // rcx
  const char *v14; // rdi
  char ptr; // [rsp+28h] [rbp-19h]
  __int64 v16; // [rsp+38h] [rbp-9h]
  unsigned int v17; // [rsp+40h] [rbp-1h]
  double v18; // [rsp+48h] [rbp+7h]
  char v19; // [rsp+58h] [rbp+17h]
  __int64 v20; // [rsp+68h] [rbp+27h]
  unsigned int v21; // [rsp+70h] [rbp+2Fh]
  const char *v22; // [rsp+78h] [rbp+37h]

  v1 = this;
  Scaleform::GFx::Movie::Invoke(this->m_Movie, "GameLogList.Clear", 0i64, 0i64, 0);
  for ( i = 0; ; ++i )
  {
    v3 = v1->m_aCurrentTabItems.mHeadIndex;
    if ( v3 == -1 )
    {
      v4 = 0;
    }
    else
    {
      v5 = v1->m_aCurrentTabItems.mTailIndex;
      v4 = v3 <= v5 ? v5 - v3 + 1 : v1->m_aCurrentTabItems.mCapacity - v3 + v5 + 1;
    }
    if ( i >= v4 )
      break;
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v17 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v16 + 16i64))(
        v16,
        &ptr,
        COERCE_DOUBLE(*(_QWORD *)&v18));
      v16 = 0i64;
    }
    v17 = 5;
    v18 = (double)i;
    v6 = v1->m_aCurrentTabItems.mHeadIndex;
    if ( v6 == -1 )
    {
      v7 = 0;
    }
    else
    {
      v8 = v1->m_aCurrentTabItems.mTailIndex;
      if ( v6 <= v8 )
        v7 = v8 - v6 + 1;
      else
        v7 = v1->m_aCurrentTabItems.mCapacity - v6 + v8 + 1;
    }
    v9 = i % v7;
    if ( i % v7 >= 0 )
    {
      v11 = (v9 + v6) % v1->m_aCurrentTabItems.mCapacity;
    }
    else
    {
      v10 = v1->m_aCurrentTabItems.mTailIndex;
      if ( -v9 <= v10 + 1 )
        v11 = v10 + v9 + 1;
      else
        v11 = v9 + v1->m_aCurrentTabItems.mCapacity + v10 + 1;
    }
    v12 = v1->m_aCurrentTabItems.mData[v11]->string_hash;
    v13 = UFG::UIScreenManager::s_instance->m_translator;
    if ( v13
      && (v14 = (const char *)v13->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, v12)) != 0i64 )
    {
      if ( (v21 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v20 + 16i64))(v20, &v19, v22);
        v20 = 0i64;
      }
      v22 = v14;
    }
    else
    {
      if ( (v21 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v20 + 16i64))(v20, &v19, v22);
        v20 = 0i64;
      }
      v22 = "ERROR: Bad String Hash!";
    }
    v21 = 6;
    Scaleform::GFx::Movie::Invoke(v1->m_Movie, "AddSlot", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  Scaleform::GFx::Movie::Invoke(v1->m_Movie, "GameLog_Refresh", 0i64, 0i64, 0);
  UFG::UIHKScreenGameLog::Flash_SetSelectedTab(v1, v1->mCurrentTab);
}

// File Line: 379
// RVA: 0x5E0A90
void __fastcall UFG::UIHKScreenGameLog::Flash_SetSelectedTab(UFG::UIHKScreenGameLog *this, int index)
{
  int v2; // ebx
  Scaleform::GFx::Movie *v3; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = index;
  v3 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = (double)v2;
  Scaleform::GFx::Movie::Invoke(v3, "TabMenuWidgetList_JumpToItemIndex", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 389
// RVA: 0x6041B0
void __fastcall UFG::UIHKScreenGameLog::ScrollNextTab(UFG::UIHKScreenGameLog *this)
{
  int v1; // eax
  UFG::UIHKScreenGameLog *v2; // rbx

  v1 = ++this->mCurrentTab;
  v2 = this;
  if ( v1 >= 4 )
    v1 = 0;
  this->mCurrentTab = v1;
  UFG::UIHKScreenGameLog::UpdateList(this);
  UFG::UIHKScreenGameLog::Refresh(v2);
}

// File Line: 403
// RVA: 0x604380
void __fastcall UFG::UIHKScreenGameLog::ScrollPrevTab(UFG::UIHKScreenGameLog *this)
{
  UFG::UIHKScreenGameLog *v1; // rbx

  v1 = this;
  if ( this->mCurrentTab <= 0 )
    this->mCurrentTab = 4;
  --this->mCurrentTab;
  UFG::UIHKScreenGameLog::UpdateList(this);
  UFG::UIHKScreenGameLog::Refresh(v1);
}

// File Line: 418
// RVA: 0x5DAFD0
void __fastcall UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(UFG::UIHKScreenUpgrades *this, float mouseX, float mouseY)
{
  Scaleform::GFx::Movie *v3; // rbx
  char ptr; // [rsp+40h] [rbp-88h]
  __int64 v5; // [rsp+50h] [rbp-78h]
  unsigned int v6; // [rsp+58h] [rbp-70h]
  double v7; // [rsp+60h] [rbp-68h]
  char v8; // [rsp+70h] [rbp-58h]
  __int64 v9; // [rsp+80h] [rbp-48h]
  unsigned int v10; // [rsp+88h] [rbp-40h]
  double v11; // [rsp+90h] [rbp-38h]

  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v6 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v5 + 16i64))(v5, &ptr, COERCE_DOUBLE(*(_QWORD *)&v7));
      v5 = 0i64;
    }
    v6 = 5;
    v7 = mouseX;
    if ( (v10 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, &v8, COERCE_DOUBLE(*(_QWORD *)&v11));
      v9 = 0i64;
    }
    v10 = 5;
    v11 = mouseY;
    Scaleform::GFx::Movie::Invoke(v3, "HandleMouseClick", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

