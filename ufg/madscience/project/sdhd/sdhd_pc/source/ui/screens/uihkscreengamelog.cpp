// File Line: 30
// RVA: 0x156B1D0
__int64 UFG::_dynamic_initializer_for__UI_HASH_E_COMBAT_TRAIN_TITLE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("E_COMBAT_TRAIN_TITLE", -1);
  UI_HASH_E_COMBAT_TRAIN_TITLE = result;
  return result;
}

// File Line: 31
// RVA: 0x156AB70
__int64 UFG::_dynamic_initializer_for__UI_HASH_COMMON_TRC_PS3_PSN_SIGNED_OUT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("COMMON_TRC_PS3_PSN_SIGNED_OUT", -1);
  UI_HASH_COMMON_TRC_PS3_PSN_SIGNED_OUT = result;
  return result;
}

// File Line: 32
// RVA: 0x156AB50
__int64 UFG::_dynamic_initializer_for__UI_HASH_COMMON_TRC_PS3_ETHERNET_CABLE_UNPLUGGED__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("COMMON_TRC_PS3_ETHERNET_CABLE_UNPLUGGED", -1);
  UI_HASH_COMMON_TRC_PS3_ETHERNET_CABLE_UNPLUGGED = result;
  return result;
}

// File Line: 36
// RVA: 0x6207E0
UFG::GameLogManager *__fastcall UFG::GameLogManager::getInstance()
{
  if ( (_S15_5 & 1) == 0 )
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
  UFG::PersistentData::Binary *Stat; // rax
  UFG::allocator::free_link *v4; // rax
  void *v5; // rax
  void *v6; // rbx
  UFG::GameStatTracker *v7; // rax
  UFG::PersistentData::Binary binary; // [rsp+28h] [rbp-20h] BYREF

  v1 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v1, GameLog);
  if ( Stat->mSize )
    return (UFG::GameLogManager::cGameLogCircularArray *)Stat->mpBuffer;
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
void __fastcall UFG::GameLogManager::LogItem(
        UFG::GameLogManager *this,
        unsigned int *log_type,
        unsigned int string_hash)
{
  UFG::GameLogManager::cGameLogCircularArray *DataArray; // rax
  UFG::GameLogManager::cGameLogCircularArray *v6; // rdi
  unsigned int v7; // ecx
  UFG::GameLogManager::sGameLogEntry obj; // [rsp+48h] [rbp+20h] BYREF

  if ( string_hash != UI_HASH_E_COMBAT_TRAIN_TITLE
    && string_hash != UI_HASH_COMMON_TRC_PS3_PSN_SIGNED_OUT
    && string_hash != UI_HASH_COMMON_TRC_PS3_ETHERNET_CABLE_UNPLUGGED )
  {
    DataArray = UFG::GameLogManager::GetDataArray(this);
    v6 = DataArray;
    if ( DataArray )
    {
      if ( (unsigned int)UFG::GameLogManager::cGameLogCircularArray::Count(DataArray) >= 0x64 )
        UFG::GameLogManager::cGameLogCircularArray::RemoveHead(v6);
      v7 = *log_type;
      obj.string_hash = string_hash;
      obj.type.mUID = v7;
      UFG::GameLogManager::cGameLogCircularArray::AddTail(v6, &obj);
    }
  }
}

// File Line: 103
// RVA: 0x5F1D90
void __fastcall UFG::GameLogManager::LogItem(UFG::GameLogManager *this, unsigned int *log_type, const char *text)
{
  const char *v3; // rbx
  unsigned int v6; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  unsigned int v8; // r8d
  UFG::qSymbol log_typea; // [rsp+50h] [rbp+18h] BYREF
  UFG::qSymbol *p_log_typea; // [rsp+58h] [rbp+20h]

  if ( text )
  {
    v3 = text;
    if ( (int)UFG::qStringLength(text) >= 1 )
    {
      if ( *v3 == 36 )
        ++v3;
      v6 = UFG::qStringHashUpper32(v3, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( m_translator )
      {
        if ( m_translator->vfptr[5].__vecDelDtor(m_translator, v6) )
        {
          p_log_typea = &log_typea;
          log_typea.mUID = *log_type;
          v8 = UFG::qStringHashUpper32(v3, -1);
          UFG::GameLogManager::LogItem(this, &log_typea.mUID, v8);
        }
      }
    }
  }
}

// File Line: 132
// RVA: 0x5D4FC0
void __fastcall UFG::GameLogManager::Clear(UFG::GameLogManager *this)
{
  UFG::GameLogManager::cGameLogCircularArray *DataArray; // rax

  DataArray = UFG::GameLogManager::GetDataArray(this);
  if ( DataArray )
    *(_QWORD *)&DataArray->mHeadIndex = -1i64;
}

// File Line: 144
// RVA: 0x5E8230
void __fastcall UFG::GameLogManager::GetLogEntries(
        UFG::GameLogManager *this,
        UFG::qCircularArray<UFG::GameLogManager::sGameLogEntry const *> *list,
        _DWORD *log_type)
{
  UFG::GameLogManager::cGameLogCircularArray *DataArray; // rax
  UFG::GameLogManager::cGameLogCircularArray *v6; // rsi
  int v7; // edi
  UFG::GameLogManager::cGameLogCircularArray *v8; // rax
  unsigned int mHeadIndex; // edx
  int v10; // ecx
  unsigned int mTailIndex; // ecx
  int mCapacity; // r8d

  *(_QWORD *)&list->mHeadIndex = -1i64;
  DataArray = UFG::GameLogManager::GetDataArray(this);
  v6 = DataArray;
  if ( DataArray )
  {
    v7 = 0;
    if ( (int)UFG::GameLogManager::cGameLogCircularArray::Count(DataArray) > 0 )
    {
      do
      {
        if ( UFG::GameLogManager::cGameLogCircularArray::operator[](v6, v7)->mData[0].type.mUID == *log_type )
        {
          v8 = UFG::GameLogManager::cGameLogCircularArray::operator[](v6, v7);
          mHeadIndex = list->mHeadIndex;
          if ( mHeadIndex == -1 )
          {
            v10 = 0;
          }
          else
          {
            mTailIndex = list->mTailIndex;
            v10 = mHeadIndex <= mTailIndex ? mTailIndex - mHeadIndex + 1 : list->mCapacity - mHeadIndex + mTailIndex + 1;
          }
          mCapacity = list->mCapacity;
          if ( v10 < mCapacity )
          {
            if ( v10 )
            {
              if ( mHeadIndex )
                list->mHeadIndex = (mHeadIndex - 1) % mCapacity;
              else
                list->mHeadIndex = mCapacity - 1;
            }
            else
            {
              *(_QWORD *)&list->mHeadIndex = 0i64;
            }
            list->mData[list->mHeadIndex] = (UFG::GameLogManager::sGameLogEntry *)v8;
          }
        }
        ++v7;
      }
      while ( v7 < (int)UFG::GameLogManager::cGameLogCircularArray::Count(v6) );
    }
  }
}

// File Line: 162
// RVA: 0x5E6A50
void __fastcall UFG::GameLogManager::GetAllLogEntries(
        UFG::GameLogManager *this,
        UFG::qCircularArray<UFG::GameLogManager::sGameLogEntry const *> *list)
{
  UFG::GameLogManager::cGameLogCircularArray *DataArray; // rax
  UFG::GameLogManager::cGameLogCircularArray *v4; // rsi
  int v5; // edi
  UFG::GameLogManager::cGameLogCircularArray *v6; // rax
  unsigned int mHeadIndex; // edx
  int v8; // ecx
  unsigned int mTailIndex; // ecx
  int mCapacity; // r8d

  *(_QWORD *)&list->mHeadIndex = -1i64;
  DataArray = UFG::GameLogManager::GetDataArray(this);
  v4 = DataArray;
  if ( DataArray )
  {
    v5 = 0;
    if ( (int)UFG::GameLogManager::cGameLogCircularArray::Count(DataArray) > 0 )
    {
      do
      {
        v6 = UFG::GameLogManager::cGameLogCircularArray::operator[](v4, v5);
        mHeadIndex = list->mHeadIndex;
        if ( mHeadIndex == -1 )
        {
          v8 = 0;
        }
        else
        {
          mTailIndex = list->mTailIndex;
          if ( mHeadIndex <= mTailIndex )
            v8 = mTailIndex - mHeadIndex + 1;
          else
            v8 = list->mCapacity - mHeadIndex + mTailIndex + 1;
        }
        mCapacity = list->mCapacity;
        if ( v8 < mCapacity )
        {
          if ( v8 )
          {
            if ( mHeadIndex )
              list->mHeadIndex = (mHeadIndex - 1) % mCapacity;
            else
              list->mHeadIndex = mCapacity - 1;
          }
          else
          {
            *(_QWORD *)&list->mHeadIndex = 0i64;
          }
          list->mData[list->mHeadIndex] = (UFG::GameLogManager::sGameLogEntry *)v6;
        }
        ++v5;
      }
      while ( v5 < (int)UFG::GameLogManager::cGameLogCircularArray::Count(v4) );
    }
  }
}

// File Line: 188
// RVA: 0x5C52E0
void __fastcall UFG::UIHKScreenGameLog::UIHKScreenGameLog(UFG::UIHKScreenGameLog *this)
{
  unsigned __int64 v2; // rax

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGameLog::`vftable;
  this->m_bShouldRefesh = 0;
  this->mCurrentTab = 0;
  this->m_aCurrentTabItems.mCapacity = 100;
  this->m_aCurrentTabItems.mpMemoryPool = 0i64;
  v2 = 800i64;
  if ( !is_mul_ok(0x64ui64, 8ui64) )
    v2 = -1i64;
  this->m_aCurrentTabItems.mData = (UFG::GameLogManager::sGameLogEntry **)UFG::qMalloc(
                                                                            v2,
                                                                            "qCircularArray::mData",
                                                                            0i64);
  *(_QWORD *)&this->m_aCurrentTabItems.mHeadIndex = -1i64;
}

// File Line: 193
// RVA: 0x5CAB80
void __fastcall UFG::UIHKScreenGameLog::~UIHKScreenGameLog(UFG::UIHKScreenGameLog *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v5; // eax
  UFG::qMemoryPool *mpMemoryPool; // rcx

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGameLog::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "GameLog");
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  p_HelpBar = &v3->HelpBar;
  v5 = UFG::qStringHash32("gamelog", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v5);
  *(_QWORD *)&this->m_aCurrentTabItems.mHeadIndex = -1i64;
  mpMemoryPool = this->m_aCurrentTabItems.mpMemoryPool;
  if ( mpMemoryPool )
    UFG::qMemoryPool::Free(mpMemoryPool, (char *)this->m_aCurrentTabItems.mData);
  else
    operator delete[](this->m_aCurrentTabItems.mData);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 201
// RVA: 0x6318A0
void __fastcall UFG::UIHKScreenGameLog::init(UFG::UIHKScreenGameLog *this, UFG::UICommandData *data)
{
  unsigned int v3; // r14d
  int v4; // ecx
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rbx
  unsigned int v8; // r14d
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rbx
  UFG::UIHKScreenGlobalOverlay *v13; // rax
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v15; // [rsp+60h] [rbp-88h]
  int v16[2]; // [rsp+68h] [rbp-80h]
  UFG::UIHKHelpBarData dataa; // [rsp+70h] [rbp-78h] BYREF

  v15 = -2i64;
  UFG::UIScreen::init(this, data);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
  dataa.id = UFG::qStringHash32("gamelog", 0xFFFFFFFF);
  dataa.alignment = ALIGN_LEFT;
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
  UFG::qString::Set((UFG::qString *)&dataa.Captions[v7 + 5].mMagic, &customCaption);
  dataa.MessageIds[v6 - 6] = v3;
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
  UFG::qString::Set((UFG::qString *)&dataa.Captions[v12 + 5].mMagic, &customCaption);
  dataa.MessageIds[v11 - 6] = v8;
LABEL_11:
  v13 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v13 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v13->HelpBar, &dataa);
  this->m_Movie = this->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Number;
  pargs.mValue.NValue = DOUBLE_100_0;
  Scaleform::GFx::Movie::Invoke(this->m_Movie, "SetNumSlots", 0i64, &pargs, 1u);
  UFG::UIHKScreenGameLog::UpdateList(this);
  this->m_bShouldRefesh = 1;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Undefined;
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
  UFG::UIScreen::update(this, elapsed);
  if ( this->m_bShouldRefesh )
  {
    this->m_bShouldRefesh = 0;
    UFG::UIHKScreenGameLog::Refresh(this);
  }
}

// File Line: 236
// RVA: 0x623060
bool __fastcall UFG::UIHKScreenGameLog::handleMessage(
        UFG::UIHKScreenGameLog *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIScreen *Overlay; // rax
  UFG::UIHKScreenGlobalOverlay *v7; // rcx

  if ( msgId == UI_HASH_BUTTON_START_PRESSED_30 || msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
    return 1;
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
      Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "GlobalOverlay");
      if ( Overlay )
      {
        v7 = UFG::UIHKScreenGlobalOverlay::mThis;
        if ( !UFG::UIHKScreenGlobalOverlay::mThis )
          v7 = &gGlobalOverlaySentinel;
        UFG::UIHKHelpBarWidget::HandleMessage(&v7->HelpBar, Overlay, msgId, msg);
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      else if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
      {
        UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
          (UFG::UIHKScreenUpgrades *)this,
          (float)SLODWORD(msg[1].vfptr),
          (float)SHIDWORD(msg[1].vfptr));
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      else
      {
        if ( msgId == UI_HASH_MOUSE_SELECT_SLOT_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
          this->mCurrentTab = UFG::UI::GetFlashArgsInt(msg);
          UFG::UIHKScreenGameLog::UpdateList(this);
          UFG::UIHKScreenGameLog::Refresh(this);
        }
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
    }
    if ( msgId == UI_HASH_BUTTON_L1_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
      UFG::UIHKScreenGameLog::ScrollPrevTab(this);
      return 1;
    }
    else
    {
      if ( msgId != UI_HASH_BUTTON_R1_PRESSED_30 )
        goto LABEL_12;
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
      UFG::UIHKScreenGameLog::ScrollNextTab(this);
      return 1;
    }
  }
}

// File Line: 303
// RVA: 0x604430
void __fastcall UFG::UIHKScreenGameLog::ScrollUp(UFG::UIHKScreenGameLog *this)
{
  unsigned int mHeadIndex; // r8d
  unsigned int mTailIndex; // edx

  mHeadIndex = this->m_aCurrentTabItems.mHeadIndex;
  if ( mHeadIndex != -1 )
  {
    mTailIndex = this->m_aCurrentTabItems.mTailIndex;
    if ( mHeadIndex <= mTailIndex
       ? mTailIndex - mHeadIndex + 1
       : this->m_aCurrentTabItems.mCapacity - mHeadIndex + mTailIndex + 1 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x593B70ABu, 0i64, 0, 0i64);
      Scaleform::GFx::Movie::Invoke(this->m_Movie, "ScrollUp", 0i64, 0i64, 0);
    }
  }
}

// File Line: 313
// RVA: 0x603EA0
void __fastcall UFG::UIHKScreenGameLog::ScrollDown(UFG::UIHKScreenGameLog *this)
{
  unsigned int mHeadIndex; // r8d
  unsigned int mTailIndex; // edx
  int v3; // edx

  mHeadIndex = this->m_aCurrentTabItems.mHeadIndex;
  if ( mHeadIndex != -1 )
  {
    mTailIndex = this->m_aCurrentTabItems.mTailIndex;
    if ( mHeadIndex <= mTailIndex )
      v3 = mTailIndex - mHeadIndex + 1;
    else
      v3 = this->m_aCurrentTabItems.mCapacity - mHeadIndex + mTailIndex + 1;
    if ( v3 )
    {
      Scaleform::GFx::Movie::Invoke(this->m_Movie, "ScrollDown", 0i64, 0i64, 0);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xB78DCE8u, 0i64, 0, 0i64);
    }
  }
}

// File Line: 323
// RVA: 0x61B000
void __fastcall UFG::UIHKScreenGameLog::UpdateList(UFG::UIHKScreenGameLog *this)
{
  UFG::qCircularArray<UFG::GameLogManager::sGameLogEntry const *> *p_m_aCurrentTabItems; // rdx
  UFG::qSymbol *p_mUID; // r8
  unsigned int v4; // [rsp+40h] [rbp+8h] BYREF
  unsigned int mUID; // [rsp+48h] [rbp+10h] BYREF
  UFG::qSymbol log_type; // [rsp+50h] [rbp+18h] BYREF
  UFG::qSymbol *p_log_type; // [rsp+58h] [rbp+20h]

  if ( (_S15_5 & 1) == 0 )
  {
    _S15_5 |= 1u;
    glManager.vfptr = (UFG::GameLogManagerVtbl *)&UFG::GameLogManager::`vftable;
    atexit(UFG::GameLogManager::getInstance_::_2_::_dynamic_atexit_destructor_for__glManager__);
  }
  switch ( this->mCurrentTab )
  {
    case 1:
      p_log_type = &log_type;
      log_type.mUID = qSymbol_GameLogType_Hint_20.mUID;
      p_m_aCurrentTabItems = &this->m_aCurrentTabItems;
      p_mUID = &log_type;
      break;
    case 2:
      p_log_type = (UFG::qSymbol *)&mUID;
      mUID = qSymbol_GameLogType_Objective_20.mUID;
      p_m_aCurrentTabItems = &this->m_aCurrentTabItems;
      p_mUID = (UFG::qSymbol *)&mUID;
      break;
    case 3:
      p_log_type = (UFG::qSymbol *)&v4;
      v4 = qSymbol_GameLogType_RewardsUpgrades_20.mUID;
      p_m_aCurrentTabItems = &this->m_aCurrentTabItems;
      p_mUID = (UFG::qSymbol *)&v4;
      break;
    default:
      UFG::GameLogManager::GetAllLogEntries(&glManager, &this->m_aCurrentTabItems);
      return;
  }
  UFG::GameLogManager::GetLogEntries(&glManager, p_m_aCurrentTabItems, p_mUID);
}

// File Line: 353
// RVA: 0x5FFC90
void __fastcall UFG::UIHKScreenGameLog::Refresh(UFG::UIHKScreenGameLog *this)
{
  int i; // esi
  unsigned int mHeadIndex; // edx
  int v4; // ecx
  unsigned int mTailIndex; // ecx
  unsigned int v6; // r8d
  int v7; // ecx
  unsigned int v8; // ecx
  int v9; // edx
  unsigned int v10; // r8d
  unsigned int v11; // edx
  __int64 string_hash; // rdx
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v14; // rdi
  Scaleform::GFx::Value ptr; // [rsp+28h] [rbp-19h] BYREF
  char v16[16]; // [rsp+58h] [rbp+17h] BYREF
  __int64 v17; // [rsp+68h] [rbp+27h]
  int v18; // [rsp+70h] [rbp+2Fh]
  const char *v19; // [rsp+78h] [rbp+37h]

  Scaleform::GFx::Movie::Invoke(this->m_Movie, "GameLogList.Clear", 0i64, 0i64, 0);
  for ( i = 0; ; ++i )
  {
    mHeadIndex = this->m_aCurrentTabItems.mHeadIndex;
    if ( mHeadIndex == -1 )
    {
      v4 = 0;
    }
    else
    {
      mTailIndex = this->m_aCurrentTabItems.mTailIndex;
      v4 = mHeadIndex <= mTailIndex
         ? mTailIndex - mHeadIndex + 1
         : this->m_aCurrentTabItems.mCapacity - mHeadIndex + mTailIndex + 1;
    }
    if ( i >= v4 )
      break;
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = (double)i;
    v6 = this->m_aCurrentTabItems.mHeadIndex;
    if ( v6 == -1 )
    {
      v7 = 0;
    }
    else
    {
      v8 = this->m_aCurrentTabItems.mTailIndex;
      if ( v6 <= v8 )
        v7 = v8 - v6 + 1;
      else
        v7 = this->m_aCurrentTabItems.mCapacity - v6 + v8 + 1;
    }
    v9 = i % v7;
    if ( i % v7 >= 0 )
    {
      v11 = (v9 + v6) % this->m_aCurrentTabItems.mCapacity;
    }
    else
    {
      v10 = this->m_aCurrentTabItems.mTailIndex;
      if ( -v9 <= v10 + 1 )
        v11 = v10 + v9 + 1;
      else
        v11 = v9 + this->m_aCurrentTabItems.mCapacity + v10 + 1;
    }
    string_hash = this->m_aCurrentTabItems.mData[v11]->string_hash;
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    if ( m_translator && (v14 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, string_hash)) != 0i64 )
    {
      if ( (v18 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v17 + 16i64))(v17, v16, v19);
        v17 = 0i64;
      }
      v19 = v14;
    }
    else
    {
      if ( (v18 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v17 + 16i64))(v17, v16, v19);
        v17 = 0i64;
      }
      v19 = "ERROR: Bad String Hash!";
    }
    v18 = 6;
    Scaleform::GFx::Movie::Invoke(this->m_Movie, "AddSlot", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  Scaleform::GFx::Movie::Invoke(this->m_Movie, "GameLog_Refresh", 0i64, 0i64, 0);
  UFG::UIHKScreenGameLog::Flash_SetSelectedTab(this, this->mCurrentTab);
}

// File Line: 379
// RVA: 0x5E0A90
void __fastcall UFG::UIHKScreenGameLog::Flash_SetSelectedTab(UFG::UIHKScreenGameLog *this, int index)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Number;
  pargs.mValue.NValue = (double)index;
  Scaleform::GFx::Movie::Invoke(pObject, "TabMenuWidgetList_JumpToItemIndex", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 389
// RVA: 0x6041B0
void __fastcall UFG::UIHKScreenGameLog::ScrollNextTab(UFG::UIHKScreenGameLog *this)
{
  int v1; // eax

  v1 = ++this->mCurrentTab;
  if ( v1 >= 4 )
    v1 = 0;
  this->mCurrentTab = v1;
  UFG::UIHKScreenGameLog::UpdateList(this);
  UFG::UIHKScreenGameLog::Refresh(this);
}

// File Line: 403
// RVA: 0x604380
void __fastcall UFG::UIHKScreenGameLog::ScrollPrevTab(UFG::UIHKScreenGameLog *this)
{
  if ( this->mCurrentTab <= 0 )
    this->mCurrentTab = 4;
  --this->mCurrentTab;
  UFG::UIHKScreenGameLog::UpdateList(this);
  UFG::UIHKScreenGameLog::Refresh(this);
}

// File Line: 418
// RVA: 0x5DAFD0
void __fastcall UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
        UFG::UIHKScreenUpgrades *this,
        float mouseX,
        float mouseY)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-88h] BYREF
  char v5[16]; // [rsp+70h] [rbp-58h] BYREF
  __int64 v6; // [rsp+80h] [rbp-48h]
  int v7; // [rsp+88h] [rbp-40h]
  double v8; // [rsp+90h] [rbp-38h]

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = mouseX;
    if ( (v7 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, v5, COERCE_DOUBLE(*(_QWORD *)&v8));
      v6 = 0i64;
    }
    v7 = 5;
    v8 = mouseY;
    Scaleform::GFx::Movie::Invoke(pObject, "HandleMouseClick", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

