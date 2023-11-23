// File Line: 67
// RVA: 0x1569D30
__int64 UFG::_dynamic_initializer_for__UIListSymbol_operation__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("operation", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UIListSymbol_operation, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__UIListSymbol_operation__);
}

// File Line: 89
// RVA: 0x5C8940
void __fastcall UFG::UIPropertySetMenu::UIPropertySetMenu(UFG::UIPropertySetMenu *this)
{
  UFG::UIPropertySetMenuData *p_mInitData; // rbx

  this->vfptr = (UFG::UIPropertySetMenuVtbl *)&UFG::UIPropertySetMenu::`vftable;
  p_mInitData = &this->mInitData;
  this->mInitData.vfptr = (UFG::UIPropertySetMenuDataVtbl *)&UFG::UIPropertySetMenuData::`vftable;
  this->mInitData.mScreen = 0i64;
  UFG::qString::qString(&this->mInitData.mPropertySetName);
  UFG::qString::qString(&p_mInitData->mPathToWidget);
  this->mState = -1;
  UFG::qString::qString(&this->mSelectedItem);
  UFG::qString::qString(&this->mSelectedSubItem);
  UFG::qString::qString(&this->mGameSetup);
  UFG::qString::qString(&this->mOperation);
  UFG::qString::qString(&this->mOpDependant);
  UFG::qString::qString(&this->mScriptFunc);
  this->mProgressionFlow.mUID = -1;
}

// File Line: 95
// RVA: 0x5CE110
void __fastcall UFG::UIPropertySetMenu::~UIPropertySetMenu(UFG::UIPropertySetMenu *this)
{
  UFG::UIPropertySetMenu *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::UIPropertySetMenuVtbl *)&UFG::UIPropertySetMenu::`vftable;
  UFG::qString::~qString(&this->mScriptFunc);
  UFG::qString::~qString(&v1->mOpDependant);
  UFG::qString::~qString(&v1->mOperation);
  UFG::qString::~qString(&v1->mGameSetup);
  UFG::qString::~qString(&v1->mSelectedSubItem);
  UFG::qString::~qString(&v1->mSelectedItem);
  v1 = (UFG::UIPropertySetMenu *)((char *)v1 + 16);
  v1->vfptr = (UFG::UIPropertySetMenuVtbl *)&UFG::UIPropertySetMenuData::`vftable;
  UFG::qString::~qString((UFG::qString *)&v1->mInitData.mPropertySetName.mData);
  UFG::qString::~qString((UFG::qString *)&v1->mInitData);
}

// File Line: 102
// RVA: 0x637AD0
void __fastcall UFG::UIPropertySetMenu::init(UFG::UIPropertySetMenu *this, UFG::UIPropertySetMenuData *initData)
{
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *PropertySet; // rax
  char *v7; // rax
  unsigned int v8; // eax
  unsigned int v9; // eax
  int mNumVisibleSlots; // ecx
  UFG::UIScreen *mScreen; // rbx
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-98h] BYREF
  __int64 v13; // [rsp+60h] [rbp-68h]
  UFG::qString v14; // [rsp+68h] [rbp-60h] BYREF
  UFG::qString v15; // [rsp+90h] [rbp-38h] BYREF
  UFG::qSymbol result; // [rsp+D0h] [rbp+8h] BYREF

  v13 = -2i64;
  this->mInitData.mScreen = initData->mScreen;
  UFG::qString::Set(
    &this->mInitData.mPropertySetName,
    initData->mPropertySetName.mData,
    initData->mPropertySetName.mLength,
    0i64,
    0);
  UFG::qString::Set(
    &this->mInitData.mPathToWidget,
    initData->mPathToWidget.mData,
    initData->mPathToWidget.mLength,
    0i64,
    0);
  pObject = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  v5 = UFG::qSymbol::create_from_string(&result, this->mInitData.mPropertySetName.mData);
  PropertySet = UFG::PropertySetManager::GetPropertySet(v5);
  this->mPSSetData = PropertySet;
  if ( PropertySet )
  {
    v7 = UFG::qPropertySet::Get<char const *>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)&UIListSymbol_numSlots,
           DEPTH_RECURSE);
    v8 = UFG::qToUInt32(v7, 0);
  }
  else
  {
    v8 = 1;
  }
  this->mNumVisibleSlots = v8;
  v9 = UFG::UIPropertySetMenu::populateMenu(this, this->mPSSetData);
  mNumVisibleSlots = this->mNumVisibleSlots;
  if ( v9 < mNumVisibleSlots )
    mNumVisibleSlots = v9;
  this->mNumVisibleSlots = mNumVisibleSlots;
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Number;
  pargs.mValue.NValue = (double)mNumVisibleSlots;
  UFG::qString::qString(&v15, "%s.SetNumVisualSlots", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(pObject, v15.mData, 0i64, &pargs, 1u);
  mScreen = this->mInitData.mScreen;
  UFG::qString::qString(&v14, "%s.Refresh", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(mScreen->mRenderable->m_movie.pObject, v14.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v14);
  UFG::qString::Set(&this->mSelectedSubItem, &customCaption);
  this->mState = STATE_INIT;
  this->vfptr->updateHelpbar(this);
  UFG::qString::~qString(&v15);
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 129
// RVA: 0x63AA20
void __fastcall UFG::UIPropertySetMenu::setSelectedMenuIndex(
        UFG::UIPropertySetMenu *this,
        UFG::UIScreen *screen,
        int val)
{
  Scaleform::GFx::Movie *MovieSafe; // rbx
  UFG::qString v6; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+60h] [rbp-38h] BYREF

  MovieSafe = UFG::UIScreen::getMovieSafe(screen);
  if ( MovieSafe )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)val;
    UFG::qString::qString(&v6, "%s.SetSelectedIndex", this->mInitData.mPathToWidget.mData);
    Scaleform::GFx::Movie::Invoke(MovieSafe, v6.mData, 0i64, &pargs, 1u);
    UFG::qString::~qString(&v6);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 145
// RVA: 0x62F230
char __fastcall UFG::UIPropertySetMenu::handleMessage(
        UFG::UIPropertySetMenu *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // rbp
  UFG::UIScreen *Overlay; // rax
  UFG::UIHKScreenGlobalOverlay *v8; // rcx
  const char *pString; // rdx
  UFG::UIPropertySetMenu::eMenuState mState; // eax
  const char *v11; // rdx
  Scaleform::GFx::Value v13; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "GlobalOverlay");
  if ( Overlay )
  {
    v8 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v8 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::HandleMessage(&v8->HelpBar, Overlay, msgId, msg);
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
    || msgId == UI_HASH_DPAD_DOWN_PRESSED_30
    || msgId == UI_HASH_DPAD_DOWN_REPEAT_30 )
  {
    UFG::UIPropertySetMenu::Flash_ScrollNext(this, this->mInitData.mScreen);
    return 1;
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_UP_30
    || msgId == UI_HASH_DPAD_UP_PRESSED_30
    || msgId == UI_HASH_DPAD_UP_REPEAT_30 )
  {
    UFG::UIPropertySetMenu::Flash_ScrollPrev(this, this->mInitData.mScreen);
    return 1;
  }
  if ( msgId == UI_HASH_MOUSE_MOVE_30 )
  {
    UFG::UIPropertySetMenu::Flash_HandleMouseMove(
      this,
      this->mInitData.mScreen,
      (float)SLODWORD(msg[1].vfptr),
      (float)SHIDWORD(msg[1].vfptr));
    return 1;
  }
  if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
  {
    UFG::UIPropertySetMenu::Flash_HandleMouseClick(
      this,
      this->mInitData.mScreen,
      (float)SLODWORD(msg[1].vfptr),
      (float)SHIDWORD(msg[1].vfptr));
    return 1;
  }
  if ( msgId == UI_HASH_MAIN_MENU_STATE_20 )
  {
    if ( this->mState != STATE_VOLUME )
      return 1;
    UFG::qString::qString((UFG::qString *)&v13, (UFG::qString *)&msg[1]);
    if ( (unsigned int)UFG::qStringCompare(*(const char **)&v13.Type, "MAINMENU", -1) )
    {
      if ( (unsigned int)UFG::qStringCompare(*(const char **)&v13.Type, "SUBMENU", -1) )
      {
LABEL_22:
        UFG::qString::~qString((UFG::qString *)&v13);
        return 1;
      }
      this->mState = STATE_BRIGHTNESS;
    }
    else
    {
      UFG::qString::Set(&this->mSelectedSubItem, &customCaption);
      this->mState = STATE_INIT;
    }
    this->vfptr->updateHelpbar(this);
    goto LABEL_22;
  }
  if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    {
      v13.pObjectInterface = 0i64;
      v13.Type = VT_Undefined;
      Scaleform::GFx::Movie::GetVariable(pObject, &v13, "gSelectedItem");
      if ( (v13.Type & 0x8F) == 6 )
      {
        if ( (v13.Type & 0x40) != 0 )
          pString = *v13.mValue.pStringManaged;
        else
          pString = v13.mValue.pString;
        UFG::qString::Set(&this->mSelectedItem, pString);
        mState = this->mState;
        if ( mState )
        {
          if ( mState == STATE_BRIGHTNESS )
          {
            Scaleform::GFx::Movie::GetVariable(pObject, &v13, "gSelectedSubItem");
            if ( (v13.Type & 0x40) != 0 )
              v11 = *v13.mValue.pStringManaged;
            else
              v11 = v13.mValue.pString;
            UFG::qString::Set(&this->mSelectedSubItem, v11);
            UFG::UIPropertySetMenu::getOptionDetails(
              this,
              this->mPSSetData,
              this->mSelectedItem.mData,
              this->mSelectedSubItem.mData);
          }
        }
        else if ( !UFG::UIPropertySetMenu::getOptionDetails(
                     this,
                     this->mPSSetData,
                     this->mSelectedItem.mData,
                     &customCaption) )
        {
          UFG::UIPropertySetMenu::populateSubMenu(this, this->mPSSetData, this->mSelectedItem.mData);
          UFG::UIPropertySetMenu::Flash_Refresh(this, this->mInitData.mScreen);
          this->vfptr->expandSubMenu(this);
        }
      }
      if ( (v13.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v13.pObjectInterface->vfptr->gap8[8])(
          v13.pObjectInterface,
          &v13,
          v13.mValue);
        v13.pObjectInterface = 0i64;
      }
      v13.Type = VT_Undefined;
      return 1;
    }
    if ( msgId != (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
      return 0;
  }
  if ( this->mState == STATE_BRIGHTNESS )
    this->vfptr->leaveSubMenu(this);
  return 1;
}

// File Line: 259
// RVA: 0x639130
__int64 __fastcall UFG::UIPropertySetMenu::populateMenu(UFG::UIPropertySetMenu *this, UFG::qPropertySet *data)
{
  unsigned int v3; // r15d
  UFG::qPropertyList *v5; // rax
  UFG::qPropertyList *v6; // r13
  unsigned int mNumElements; // r12d
  unsigned int i; // ebp
  char *ValuePtr; // rax
  UFG::qPropertySet *v10; // rsi
  char *v11; // rbx
  bool *v12; // rax
  char *v13; // rcx
  char v14; // r14
  const char *v15; // rdi
  __int64 v16; // rdx
  UFG::UIGfxTranslator *m_translator; // rcx
  char *v18; // rax
  char v20; // [rsp+68h] [rbp+10h] BYREF

  v3 = 0;
  this->vfptr->clear(this);
  if ( !data )
    return 0i64;
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         data,
         (UFG::qArray<unsigned long,0> *)&UIListSymbol_items,
         DEPTH_RECURSE);
  v6 = v5;
  if ( v5 )
  {
    mNumElements = v5->mNumElements;
    for ( i = 0; i < mNumElements; ++i )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, i);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v10 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v10 = 0i64;
      v11 = UFG::qPropertySet::Get<char const *>(
              v10,
              (UFG::qArray<unsigned long,0> *)&UIListSymbol_caption,
              DEPTH_RECURSE);
      if ( !UFG::qStringFindInsensitive(v11, "Debug") )
      {
        v20 = 1;
        v12 = UFG::qPropertySet::Get<bool>(v10, (UFG::qArray<unsigned long,0> *)&UIListSymbol_enabled, DEPTH_RECURSE);
        v13 = &v20;
        if ( v12 )
          v13 = (char *)v12;
        v14 = *v13;
        if ( UFG::ProgressionTracker::Instance()->mModeType == ModeType_Challenge
          && (UFG::qStringFindInsensitive(v11, "UPGRADES")
           || UFG::qStringFindInsensitive(v11, "SOCIALHUB")
           || UFG::qStringFindInsensitive(v11, "SAVE_LOAD")
           || UFG::qStringFindInsensitive(v11, "GAME_LOG")
           || UFG::qStringFindInsensitive(v11, "STATISTICS")
           || UFG::qStringFindInsensitive(v11, "UPGRADES")) )
        {
          v14 = 0;
        }
        if ( v11 )
        {
          if ( *v11 == 36 )
            ++v11;
          v16 = (unsigned int)UFG::qStringHashUpper32(v11, -1);
          m_translator = UFG::UIScreenManager::s_instance->m_translator;
          if ( !m_translator || (v15 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v16)) == 0i64 )
            v15 = v11;
        }
        else
        {
          v15 = 0i64;
        }
        v18 = UFG::qPropertySet::Get<char const *>(
                v10,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_platform,
                DEPTH_RECURSE);
        if ( this->vfptr->addItem(this, v15, v18, v14) )
          ++v3;
      }
    }
  }
  return v3;
}

// File Line: 354
// RVA: 0x156E030
__int64 UFG::_dynamic_initializer_for__gSym_GetSubMenuNames__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("get_submenu_names", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSym_GetSubMenuNames, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSym_GetSubMenuNames__);
}

// File Line: 357
// RVA: 0x639370
void __fastcall UFG::UIPropertySetMenu::populateScriptSubMenu(
        UFG::UIPropertySetMenu *this,
        ASymbol *scriptSubMenuName,
        UFG::qPropertySet *data,
        const char *subItemCaption)
{
  SSClass *v6; // rbx
  __int64 v7; // rax
  int *v8; // rcx
  int v9; // ebx
  __int64 v10; // rdi
  __int64 v11; // rdx
  __int64 v12; // rdi
  __int64 v13; // rsi
  const char *v14; // rbx
  _BOOL8 v15; // r8
  const char *v16; // rdx
  unsigned int v17; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  _DWORD *v19; // rcx
  SSInstance *v21; // [rsp+30h] [rbp-18h] BYREF
  __int64 v22; // [rsp+50h] [rbp+8h] BYREF

  v6 = SSBrain::get_class("GameConfigs");
  v21 = SSSymbol::as_instance(scriptSubMenuName);
  v7 = (__int64)v6->vfptr->get_metaclass(v6);
  (*(void (__fastcall **)(__int64, UFG::qStaticSymbol *, SSInstance **, __int64, __int64 *, _QWORD))(*(_QWORD *)(v7 + 8) + 104i64))(
    v7 + 8,
    &UFG::gSym_GetSubMenuNames,
    &v21,
    1i64,
    &v22,
    0i64);
  v8 = *(int **)(v22 + 32);
  v9 = *v8;
  v10 = *((_QWORD *)v8 + 1);
  v11 = (*v8 - 2) / 3u;
  if ( (unsigned int)v11 > 5 )
    v11 = 5i64;
  this->vfptr->initSubMenu(this, v11);
  if ( (unsigned int)(v9 - 1) > 2 )
  {
    v12 = v10 + 16;
    v13 = (v9 - 4) / 3u + 1;
    do
    {
      v14 = **(const char ***)(*(_QWORD *)v12 + 32i64);
      if ( !UFG::qStringFindInsensitive(v14, "Debug") )
      {
        if ( v14 )
        {
          if ( *v14 == 36 )
            ++v14;
          v17 = UFG::qStringHashUpper32(v14, -1);
          m_translator = UFG::UIScreenManager::s_instance->m_translator;
          if ( !m_translator || (v16 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v17)) == 0i64 )
            v16 = v14;
        }
        else
        {
          v16 = 0i64;
        }
        LOBYTE(v15) = 1;
        this->vfptr->addSubmenuItem(this, v16, v15);
      }
      v12 += 24i64;
      --v13;
    }
    while ( v13 );
  }
  v19 = (_DWORD *)v22;
  if ( (*(_DWORD *)(v22 + 16))-- == 1 )
  {
    v19[4] = 0x80000000;
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v19 + 112i64))(v19);
  }
}

// File Line: 399
// RVA: 0x6394F0
void __fastcall UFG::UIPropertySetMenu::populateSubMenu(
        UFG::UIPropertySetMenu *this,
        UFG::qPropertySet *data,
        const char *subItemCaption)
{
  UFG::qPropertyList *v6; // rax
  UFG::qPropertySet *PSItemByCaption; // rax
  UFG::qPropertySet *v8; // r15
  UFG::qSymbol *v9; // rax
  UFG::qPropertyList *v10; // r13
  char *v11; // rax
  unsigned int v12; // eax
  unsigned int mNumElements; // r14d
  unsigned int v14; // edi
  unsigned int v15; // ebx
  unsigned int v16; // esi
  char *ValuePtr; // rax
  UFG::qPropertySet *v18; // rcx
  char *v19; // rax
  unsigned int i; // ebp
  char *v21; // rax
  UFG::qPropertySet *v22; // rsi
  char *v23; // rbx
  bool *v24; // rax
  char *v25; // rcx
  char v26; // r15
  const char *v27; // rdi
  unsigned int v28; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  char *v30; // rax
  char v31; // [rsp+68h] [rbp+10h] BYREF
  UFG::qPropertySet *v32; // [rsp+78h] [rbp+20h]

  if ( data )
  {
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           data,
           (UFG::qArray<unsigned long,0> *)&UIListSymbol_items,
           DEPTH_RECURSE);
    if ( v6 )
    {
      PSItemByCaption = UFG::UIPropertySetMenu::FindPSItemByCaption(this, v6, subItemCaption);
      v8 = PSItemByCaption;
      v32 = PSItemByCaption;
      if ( PSItemByCaption )
      {
        v9 = UFG::qPropertySet::Get<UFG::qSymbol>(
               PSItemByCaption,
               (UFG::qArray<unsigned long,0> *)&UIListSymbol_scriptsubmenu,
               DEPTH_RECURSE);
        if ( v9 )
        {
          UFG::UIPropertySetMenu::populateScriptSubMenu(this, (ASymbol *)v9, data, subItemCaption);
        }
        else
        {
          v10 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                  v8,
                  (UFG::qArray<unsigned long,0> *)&UIListSymbol_submenu,
                  DEPTH_RECURSE);
          if ( v10 )
          {
            v11 = UFG::qPropertySet::Get<char const *>(
                    v8,
                    (UFG::qArray<unsigned long,0> *)&UIListSymbol_numSlots,
                    DEPTH_RECURSE);
            v12 = UFG::qToUInt32(v11, 0);
            mNumElements = v10->mNumElements;
            v14 = 0;
            v15 = 0;
            v16 = v12;
            if ( !mNumElements )
              goto LABEL_16;
            do
            {
              ValuePtr = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v15);
              if ( ValuePtr && *(_QWORD *)ValuePtr )
                v18 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
              else
                v18 = 0i64;
              v19 = UFG::qPropertySet::Get<char const *>(
                      v18,
                      (UFG::qArray<unsigned long,0> *)&UIListSymbol_caption,
                      DEPTH_RECURSE);
              if ( !UFG::qStringFindInsensitive(v19, "Debug") )
                ++v14;
              ++v15;
            }
            while ( v15 < mNumElements );
            if ( v16 >= v14 )
LABEL_16:
              v16 = v14;
            this->vfptr->initSubMenu(this, v16);
            for ( i = 0; i < mNumElements; ++i )
            {
              v21 = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, i);
              if ( v21 && *(_QWORD *)v21 )
                v22 = (UFG::qPropertySet *)&v21[*(_QWORD *)v21];
              else
                v22 = 0i64;
              v23 = UFG::qPropertySet::Get<char const *>(
                      v22,
                      (UFG::qArray<unsigned long,0> *)&UIListSymbol_caption,
                      DEPTH_RECURSE);
              if ( !UFG::qStringFindInsensitive(v23, "Debug") )
              {
                v31 = 1;
                v24 = UFG::qPropertySet::Get<bool>(
                        v8,
                        (UFG::qArray<unsigned long,0> *)&UIListSymbol_enabled,
                        DEPTH_RECURSE);
                v25 = &v31;
                if ( v24 )
                  v25 = (char *)v24;
                v26 = *v25;
                if ( v23 )
                {
                  if ( *v23 == 36 )
                    ++v23;
                  v28 = UFG::qStringHashUpper32(v23, -1);
                  m_translator = UFG::UIScreenManager::s_instance->m_translator;
                  if ( !m_translator
                    || (v27 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v28)) == 0i64 )
                  {
                    v27 = v23;
                  }
                }
                else
                {
                  v27 = 0i64;
                }
                v30 = UFG::qPropertySet::Get<char const *>(
                        v22,
                        (UFG::qArray<unsigned long,0> *)&UIListSymbol_platform,
                        DEPTH_RECURSE);
                this->vfptr->addSubmenuItem(this, v27, v30, v26);
                v8 = v32;
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 467
// RVA: 0x620BB0
bool __fastcall UFG::UIPropertySetMenu::getOptionDetailsScriptSubMenu(
        UFG::UIPropertySetMenu *this,
        ASymbol *scriptSubMenuName,
        UFG::qPropertySet *data,
        const char *itemCaption,
        const char *subItemCaption)
{
  SSClass *v7; // rbx
  __int64 v8; // rax
  _DWORD *v9; // rdx
  unsigned int v10; // edi
  __int64 v11; // rax
  _QWORD *v12; // r15
  unsigned int v13; // ebp
  const char *v14; // rbx
  const char *v15; // rax
  unsigned int v16; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  bool v18; // zf
  const char *v20; // rbp
  const char *v21; // r13
  const char *v22; // r12
  const char *v23; // r15
  UFG::UIScreen *mScreen; // rax
  unsigned int mScreenUID; // edi
  UFG::UIScreenManager *v26; // rbx
  unsigned int v27; // eax
  _DWORD *v28; // rcx
  __int64 v29; // [rsp+30h] [rbp-38h] BYREF
  SSInstance *v30; // [rsp+38h] [rbp-30h] BYREF

  v7 = SSBrain::get_class("GameConfigs");
  v30 = SSSymbol::as_instance(scriptSubMenuName);
  v8 = (__int64)v7->vfptr->get_metaclass(v7);
  (*(void (__fastcall **)(__int64, UFG::qStaticSymbol *, SSInstance **, __int64, __int64 *, _QWORD))(*(_QWORD *)(v8 + 8) + 104i64))(
    v8 + 8,
    &UFG::gSym_GetSubMenuNames,
    &v30,
    1i64,
    &v29,
    0i64);
  v9 = (_DWORD *)v29;
  v10 = 2;
  v11 = *(_QWORD *)(v29 + 32);
  v12 = *(_QWORD **)(v11 + 8);
  v13 = *(_DWORD *)v11 - 1;
  if ( v13 <= 2 )
  {
LABEL_12:
    v18 = v9[4]-- == 1;
    if ( v18 )
    {
      v9[4] = 0x80000000;
      (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v9 + 112i64))(v9);
    }
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v14 = **(const char ***)(v12[v10] + 32i64);
      if ( v14 )
      {
        if ( *v14 == 36 )
          ++v14;
        v16 = UFG::qStringHashUpper32(v14, -1);
        m_translator = UFG::UIScreenManager::s_instance->m_translator;
        if ( !m_translator || (v15 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v16)) == 0i64 )
          v15 = v14;
      }
      else
      {
        v15 = 0i64;
      }
      if ( !(unsigned int)UFG::qStringCompare(v15, subItemCaption, -1) )
        break;
      v10 += 3;
      if ( v10 >= v13 )
      {
        v9 = (_DWORD *)v29;
        goto LABEL_12;
      }
    }
    v20 = **(const char ***)(*v12 + 32i64);
    v21 = **(const char ***)(v12[1] + 32i64);
    v22 = **(const char ***)(v12[v10 + 1] + 32i64);
    v23 = **(const char ***)(v12[v10 + 2] + 32i64);
    if ( v20 )
    {
      mScreen = this->mInitData.mScreen;
      mScreenUID = -1;
      if ( mScreen )
        mScreenUID = mScreen->mScreenUID;
      v26 = UFG::UIScreenManager::s_instance;
      v27 = UFG::qStringHashUpper32(v20, -1);
      UFG::UIScreenManagerBase::queueMessage(v26, v27, mScreenUID);
    }
    if ( v22 )
      this->vfptr->setScriptFuncStr(this, v22);
    this->vfptr->setGameSetup(this, v21);
    this->vfptr->setOpDependant(this, v23);
    v28 = (_DWORD *)v29;
    v18 = (*(_DWORD *)(v29 + 16))-- == 1;
    if ( v18 )
    {
      v28[4] = 0x80000000;
      (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v28 + 112i64))(v28);
    }
    return v20 != 0i64;
  }
}

// File Line: 521
// RVA: 0x6208B0
bool __fastcall UFG::UIPropertySetMenu::getOptionDetails(
        UFG::UIPropertySetMenu *this,
        UFG::qPropertySet *data,
        const char *itemCaption,
        const char *subItemCaption)
{
  UFG::qPropertySet *PSItemByCaption; // rax
  UFG::qPropertyList *v9; // rax
  UFG::qPropertySet *v10; // rbx
  UFG::qSymbol *v11; // rax
  UFG::qPropertyList *v12; // rax
  UFG::qPropertySet *v13; // rax
  UFG::qPropertySet *v14; // rbx
  char *v15; // rbp
  char *v16; // r12
  char *v17; // r15
  char *v18; // r14
  UFG::UIScreen *v19; // rcx
  unsigned int v20; // esi
  UFG::UIScreenManager *v21; // rbx
  unsigned int v22; // eax
  const char *v23; // rdx
  bool v24; // zf
  char *v25; // r13
  char *v26; // r12
  char *v27; // r15
  char *v28; // rbp
  UFG::qSymbol *v29; // r14
  UFG::UIScreen *mScreen; // rcx
  unsigned int mScreenUID; // esi
  UFG::UIScreenManager *v32; // rbx
  unsigned int v33; // eax
  const char *v34; // rdx
  UFG::UIPropertySetMenuVtbl *vfptr; // rbx
  UFG::qStaticSymbol *DefaultFlow; // rax

  if ( data
    && (v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(
               data,
               (UFG::qArray<unsigned long,0> *)&UIListSymbol_items,
               DEPTH_RECURSE)) != 0i64 )
  {
    PSItemByCaption = UFG::UIPropertySetMenu::FindPSItemByCaption(this, v9, itemCaption);
    v10 = PSItemByCaption;
    if ( PSItemByCaption )
    {
      if ( (int)UFG::qStringLength(subItemCaption) <= 0 )
      {
        v25 = UFG::qPropertySet::Get<char const *>(
                v10,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_operation,
                DEPTH_RECURSE);
        v26 = UFG::qPropertySet::Get<char const *>(
                v10,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_gamesetup,
                DEPTH_RECURSE);
        v27 = UFG::qPropertySet::Get<char const *>(
                v10,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_scriptname,
                DEPTH_RECURSE);
        v28 = UFG::qPropertySet::Get<char const *>(
                v10,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_dependant,
                DEPTH_RECURSE);
        v29 = UFG::qPropertySet::Get<UFG::qSymbol>(
                v10,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_flow,
                DEPTH_RECURSE);
        if ( v25 )
        {
          mScreen = this->mInitData.mScreen;
          mScreenUID = -1;
          if ( mScreen )
            mScreenUID = mScreen->mScreenUID;
          v32 = UFG::UIScreenManager::s_instance;
          v33 = UFG::qStringHashUpper32(v25, -1);
          UFG::UIScreenManagerBase::queueMessage(v32, v33, mScreenUID);
        }
        if ( v26 )
          this->vfptr->setGameSetup(this, v26);
        if ( v27 )
          this->vfptr->setScriptFuncStr(this, v27);
        v34 = v28;
        if ( !v28 )
          v34 = &customCaption;
        this->vfptr->setOpDependant(this, v34);
        if ( v29 )
        {
          this->vfptr->setProgressionFlow(this, v29);
        }
        else
        {
          UFG::ProgressionTracker::Instance();
          vfptr = this->vfptr;
          DefaultFlow = UFG::ProgressionTracker::GetDefaultFlow();
          vfptr->setProgressionFlow(this, DefaultFlow);
        }
        v24 = v25 == 0i64;
      }
      else
      {
        v11 = UFG::qPropertySet::Get<UFG::qSymbol>(
                v10,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_scriptsubmenu,
                DEPTH_RECURSE);
        if ( v11 )
        {
          LOBYTE(PSItemByCaption) = UFG::UIPropertySetMenu::getOptionDetailsScriptSubMenu(
                                      this,
                                      v11,
                                      data,
                                      itemCaption,
                                      subItemCaption);
          return (char)PSItemByCaption;
        }
        v12 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                v10,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_submenu,
                DEPTH_RECURSE);
        if ( !v12 || (v13 = UFG::UIPropertySetMenu::FindPSItemByCaption(this, v12, subItemCaption), (v14 = v13) == 0i64) )
        {
          LOBYTE(PSItemByCaption) = 0;
          return (char)PSItemByCaption;
        }
        v15 = UFG::qPropertySet::Get<char const *>(
                v13,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_operation,
                DEPTH_RECURSE);
        v16 = UFG::qPropertySet::Get<char const *>(
                v14,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_gamesetup,
                DEPTH_RECURSE);
        v17 = UFG::qPropertySet::Get<char const *>(
                v14,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_scriptname,
                DEPTH_RECURSE);
        v18 = UFG::qPropertySet::Get<char const *>(
                v14,
                (UFG::qArray<unsigned long,0> *)&UIListSymbol_dependant,
                DEPTH_RECURSE);
        if ( v15 )
        {
          v19 = this->mInitData.mScreen;
          v20 = -1;
          if ( v19 )
            v20 = v19->mScreenUID;
          v21 = UFG::UIScreenManager::s_instance;
          v22 = UFG::qStringHashUpper32(v15, -1);
          UFG::UIScreenManagerBase::queueMessage(v21, v22, v20);
        }
        if ( v16 )
          this->vfptr->setGameSetup(this, v16);
        if ( v17 )
          this->vfptr->setScriptFuncStr(this, v17);
        v23 = v18;
        if ( !v18 )
          v23 = &customCaption;
        this->vfptr->setOpDependant(this, v23);
        v24 = v15 == 0i64;
      }
      LOBYTE(PSItemByCaption) = !v24;
    }
  }
  else
  {
    LOBYTE(PSItemByCaption) = 0;
  }
  return (char)PSItemByCaption;
}

// File Line: 614
// RVA: 0x61F2A0
void __fastcall UFG::UIPropertySetMenu::clear(UFG::UIPropertySetMenu *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::qString v2; // [rsp+28h] [rbp-30h] BYREF

  pObject = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v2, "%s.Clear", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(pObject, v2.mData, &customCaption);
  UFG::qString::~qString(&v2);
}

// File Line: 624
// RVA: 0x6385F0
void __fastcall UFG::UIPropertySetMenu::initSubMenu(UFG::UIPropertySetMenu *this, int numSlots)
{
  Scaleform::GFx::Movie *pObject; // rsi
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-98h] BYREF
  __int64 v6; // [rsp+60h] [rbp-68h]
  UFG::qString v7; // [rsp+68h] [rbp-60h] BYREF
  UFG::qString v8; // [rsp+90h] [rbp-38h] BYREF

  v6 = -2i64;
  pObject = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v8, "%s.ClearSubMenu", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(pObject, v8.mData, &customCaption);
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Number;
  pargs.mValue.NValue = (double)numSlots;
  UFG::qString::qString(&v7, "%s.SetNumVisualSubSlots", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(pObject, v7.mData, 0i64, &pargs, 1u);
  UFG::qString::~qString(&v7);
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Undefined;
  UFG::qString::~qString(&v8);
}

// File Line: 640
// RVA: 0x61DEA0
char __fastcall UFG::UIPropertySetMenu::addItem(
        UFG::UIPropertySetMenu *this,
        const char *caption,
        const char *platform,
        bool enabled)
{
  if ( platform && (unsigned int)UFG::qStringCompareInsensitive(platform, "pc", -1) )
    return 0;
  this->vfptr->addItem(this, caption, enabled);
  return 1;
}

// File Line: 666
// RVA: 0x61DD50
void __fastcall UFG::UIPropertySetMenu::addItem(UFG::UIPropertySetMenu *this, const char *caption, bool enabled)
{
  Scaleform::GFx::Movie *pObject; // rsi
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-98h] BYREF
  char v7[16]; // [rsp+60h] [rbp-68h] BYREF
  __int64 v8; // [rsp+70h] [rbp-58h]
  int v9; // [rsp+78h] [rbp-50h]
  __int64 v10; // [rsp+80h] [rbp-48h]
  __int64 v11; // [rsp+90h] [rbp-38h]
  UFG::qString v12; // [rsp+98h] [rbp-30h] BYREF

  v11 = -2i64;
  pObject = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v12, "%s.AddItem", this->mInitData.mPathToWidget.mData);
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = caption;
  if ( (v9 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v8 + 16i64))(v8, v7, v10);
    v8 = 0i64;
  }
  v9 = 2;
  LOBYTE(v10) = enabled;
  Scaleform::GFx::Movie::Invoke(pObject, v12.mData, 0i64, &ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v12);
}

// File Line: 684
// RVA: 0x61E0C0
char __fastcall UFG::UIPropertySetMenu::addSubmenuItem(
        UFG::UIPropertySetMenu *this,
        const char *caption,
        const char *platform,
        bool enabled)
{
  if ( platform && (unsigned int)UFG::qStringCompareInsensitive(platform, "pc", -1) )
    return 0;
  this->vfptr->addSubmenuItem(this, caption, enabled);
  return 1;
}

// File Line: 710
// RVA: 0x61DF70
void __fastcall UFG::UIPropertySetMenu::addSubmenuItem(UFG::UIPropertySetMenu *this, const char *caption, bool enabled)
{
  Scaleform::GFx::Movie *pObject; // rsi
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-98h] BYREF
  char v7[16]; // [rsp+60h] [rbp-68h] BYREF
  __int64 v8; // [rsp+70h] [rbp-58h]
  int v9; // [rsp+78h] [rbp-50h]
  __int64 v10; // [rsp+80h] [rbp-48h]
  __int64 v11; // [rsp+90h] [rbp-38h]
  UFG::qString v12; // [rsp+98h] [rbp-30h] BYREF

  v11 = -2i64;
  pObject = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v12, "%s.AddSubMenuItem", this->mInitData.mPathToWidget.mData);
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = caption;
  if ( (v9 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v8 + 16i64))(v8, v7, v10);
    v8 = 0i64;
  }
  v9 = 2;
  LOBYTE(v10) = enabled;
  Scaleform::GFx::Movie::Invoke(pObject, v12.mData, 0i64, &ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v12);
}

// File Line: 726
// RVA: 0x63A7D0
void __fastcall UFG::UIPropertySetMenu::setItemEnabled(UFG::UIPropertySetMenu *this, const char *caption, bool enabled)
{
  Scaleform::GFx::Movie *pObject; // rbp
  UFG::UIScreen *mScreen; // rbx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-C8h] BYREF
  char v9[16]; // [rsp+60h] [rbp-98h] BYREF
  __int64 v10; // [rsp+70h] [rbp-88h]
  int v11; // [rsp+78h] [rbp-80h]
  __int64 v12; // [rsp+80h] [rbp-78h]
  __int64 v13; // [rsp+90h] [rbp-68h]
  UFG::qString v14; // [rsp+98h] [rbp-60h] BYREF
  UFG::qString v15; // [rsp+C0h] [rbp-38h] BYREF

  v13 = -2i64;
  pObject = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v15, "%s.SetItemEnabled", this->mInitData.mPathToWidget.mData);
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = caption;
  if ( (v11 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v10 + 16i64))(v10, v9, v12);
    v10 = 0i64;
  }
  v11 = 2;
  LOBYTE(v12) = enabled;
  Scaleform::GFx::Movie::Invoke(pObject, v15.mData, 0i64, &ptr, 2u);
  mScreen = this->mInitData.mScreen;
  UFG::qString::qString(&v14, "%s.Refresh", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(mScreen->mRenderable->m_movie.pObject, v14.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v14);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v15);
}

// File Line: 744
// RVA: 0x639FF0
void __fastcall UFG::UIPropertySetMenu::removeItem(UFG::UIPropertySetMenu *this, const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rsi
  UFG::UIScreen *mScreen; // rbx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-98h] BYREF
  __int64 v7; // [rsp+60h] [rbp-68h]
  UFG::qString v8; // [rsp+68h] [rbp-60h] BYREF
  UFG::qString v9; // [rsp+90h] [rbp-38h] BYREF

  v7 = -2i64;
  pObject = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v9, "%s.RemoveItem", this->mInitData.mPathToWidget.mData);
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = caption;
  Scaleform::GFx::Movie::Invoke(pObject, v9.mData, 0i64, &ptr, 1u);
  mScreen = this->mInitData.mScreen;
  UFG::qString::qString(&v8, "%s.Refresh", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(mScreen->mRenderable->m_movie.pObject, v8.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v8);
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v9);
}

// File Line: 762
// RVA: 0x63A7C0
void __fastcall UFG::UIPropertySetMenu::setGameSetup(UFG::UIPropertySetMenu *this, const char *gameStr)
{
  UFG::qString::Set(&this->mGameSetup, gameStr);
}

// File Line: 769
// RVA: 0x63A980
void __fastcall UFG::UIPropertySetMenu::setOperation(UFG::UIPropertySetMenu *this, const char *cmdStr)
{
  UFG::qString::Set(&this->mOperation, cmdStr);
}

// File Line: 776
// RVA: 0x63A9A0
void __fastcall UFG::UIPropertySetMenu::setScriptFuncStr(UFG::UIPropertySetMenu *this, const char *cmdStr)
{
  UFG::qString::Set(&this->mScriptFunc, cmdStr);
}

// File Line: 783
// RVA: 0x63A970
void __fastcall UFG::UIPropertySetMenu::setOpDependant(UFG::UIPropertySetMenu *this, const char *cmdStr)
{
  UFG::qString::Set(&this->mOpDependant, cmdStr);
}

// File Line: 790
// RVA: 0x63A990
void __fastcall UFG::UIPropertySetMenu::setProgressionFlow(UFG::UIPropertySetMenu *this, UFG::qSymbol *flow)
{
  this->mProgressionFlow = (UFG::qSymbol)flow->mUID;
}

// File Line: 798
// RVA: 0x620180
void __fastcall UFG::UIPropertySetMenu::expandSubMenu(UFG::UIPropertySetMenu *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::qString v3; // [rsp+38h] [rbp-30h] BYREF

  pObject = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v3, "%s.EnterSubMenu", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(pObject, v3.mData, &customCaption);
  if ( UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
  this->mState = STATE_VOLUME;
  UFG::qString::~qString(&v3);
}

// File Line: 827
// RVA: 0x6388A0
void __fastcall UFG::UIPropertySetMenu::leaveSubMenu(UFG::UIPropertySetMenu *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::qString v3; // [rsp+38h] [rbp-30h] BYREF

  pObject = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v3, "%s.LeaveSubMenu", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(pObject, v3.mData, &customCaption);
  if ( UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
  this->mState = STATE_VOLUME;
  UFG::qString::~qString(&v3);
}

// File Line: 842
// RVA: 0x5D88C0
UFG::qPropertySet *__fastcall UFG::UIPropertySetMenu::FindPSItemByCaption(
        UFG::UIPropertySetMenu *this,
        UFG::qPropertyList *pList,
        const char *caption)
{
  unsigned int mNumElements; // ebp
  unsigned int v4; // esi
  char *ValuePtr; // rax
  UFG::qPropertySet *v8; // rdi
  char *v9; // rax
  const char *v10; // rbx
  unsigned int v11; // eax
  UFG::UIGfxTranslator *m_translator; // rcx

  mNumElements = pList->mNumElements;
  v4 = 0;
  if ( !mNumElements )
    return 0i64;
  while ( 1 )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(pList, 0x1Au, v4);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v8 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    else
      v8 = 0i64;
    v9 = UFG::qPropertySet::Get<char const *>(v8, (UFG::qArray<unsigned long,0> *)&UIListSymbol_caption, DEPTH_RECURSE);
    v10 = v9;
    if ( v9 )
    {
      if ( *v9 == 36 )
        v10 = v9 + 1;
      v11 = UFG::qStringHashUpper32(v10, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v9 = (char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v11)) == 0i64 )
        v9 = (char *)v10;
    }
    if ( !(unsigned int)UFG::qStringCompare(v9, caption, -1) )
      break;
    if ( ++v4 >= mNumElements )
      return 0i64;
  }
  return v8;
}

// File Line: 906
// RVA: 0x5DEA60
void __fastcall UFG::UIPropertySetMenu::Flash_Refresh(UFG::UIPropertySetMenu *this, UFG::UIScreen *screen)
{
  UFG::qString v3; // [rsp+38h] [rbp-30h] BYREF

  UFG::qString::qString(&v3, "%s.Refresh", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, v3.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v3);
}

// File Line: 913
// RVA: 0x5DEF80
void __fastcall UFG::UIPropertySetMenu::Flash_ScrollNext(UFG::UIPropertySetMenu *this, UFG::UIScreen *screen)
{
  UFG::qString v4; // [rsp+38h] [rbp-30h] BYREF

  if ( UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xB78DCE8u, 0i64, 0, 0i64);
  UFG::qString::qString(&v4, "%s.ScrollNext", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, v4.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v4);
}

// File Line: 926
// RVA: 0x5DF020
void __fastcall UFG::UIPropertySetMenu::Flash_ScrollPrev(UFG::UIPropertySetMenu *this, UFG::UIScreen *screen)
{
  UFG::qString v4; // [rsp+38h] [rbp-30h] BYREF

  if ( UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x593B70ABu, 0i64, 0, 0i64);
  UFG::qString::qString(&v4, "%s.ScrollPrev", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, v4.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v4);
}

// File Line: 939
// RVA: 0x5DB620
void __fastcall UFG::UIPropertySetMenu::Flash_HandleMouseMove(
        UFG::UIPropertySetMenu *this,
        UFG::UIScreen *screen,
        float mouseX,
        float mouseY)
{
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v6[16]; // [rsp+60h] [rbp-88h] BYREF
  __int64 v7; // [rsp+70h] [rbp-78h]
  int v8; // [rsp+78h] [rbp-70h]
  double v9; // [rsp+80h] [rbp-68h]
  __int64 v10; // [rsp+90h] [rbp-58h]
  UFG::qString v11; // [rsp+98h] [rbp-50h] BYREF

  v10 = -2i64;
  UFG::qString::qString(&v11, "%s.HandleMouseMove", this->mInitData.mPathToWidget.mData);
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
  if ( (v8 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v7 + 16i64))(v7, v6, COERCE_DOUBLE(*(_QWORD *)&v9));
    v7 = 0i64;
  }
  v8 = 5;
  v9 = mouseY;
  Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, v11.mData, 0i64, &ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v11);
}

// File Line: 952
// RVA: 0x5DB110
void __fastcall UFG::UIPropertySetMenu::Flash_HandleMouseClick(
        UFG::UIPropertySetMenu *this,
        UFG::UIScreen *screen,
        float mouseX,
        float mouseY)
{
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v6[16]; // [rsp+60h] [rbp-88h] BYREF
  __int64 v7; // [rsp+70h] [rbp-78h]
  int v8; // [rsp+78h] [rbp-70h]
  double v9; // [rsp+80h] [rbp-68h]
  __int64 v10; // [rsp+90h] [rbp-58h]
  UFG::qString v11; // [rsp+98h] [rbp-50h] BYREF

  v10 = -2i64;
  UFG::qString::qString(&v11, "%s.HandleMouseClick", this->mInitData.mPathToWidget.mData);
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
  if ( (v8 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v7 + 16i64))(v7, v6, COERCE_DOUBLE(*(_QWORD *)&v9));
    v7 = 0i64;
  }
  v8 = 5;
  v9 = mouseY;
  Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, v11.mData, 0i64, &ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v11);
}

// File Line: 965
// RVA: 0x62F580
char __fastcall UFG::UIPropertySetMenuMainNav::handleMessage(
        UFG::UIPropertySetMenuMainNav *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  if ( msgId == UI_HASH_RESTART_MISSION_20 )
  {
    UFG::GameCheats::RestartMission();
    return 1;
  }
  else if ( msgId == UI_HASH_RESTORE_CHECKPOINT_20 )
  {
    UFG::GameCheats::RestoreCheckpoint();
    return 1;
  }
  else if ( msgId == UI_HASH_CANCEL_MISSION_20 )
  {
    UFG::GameCheats::CancelMission();
    return 1;
  }
  else
  {
    return UFG::UIPropertySetMenu::handleMessage(this, msgId, msg);
  }
}

// File Line: 1315
// RVA: 0x6419E0
void __fastcall UFG::UIPropertySetMenuMainNav::updateHelpbar(UFG::UIPropertySetMenuMainNav *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // r15
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIHKHelpBarWidget *v3; // rsi
  unsigned int v4; // edi
  unsigned int v5; // ebx
  UFG::UIHKHelpBarWidget *p_HelpBar; // r12
  int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ebx
  bool v10; // al
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-B8h] BYREF

  v1 = &gGlobalOverlaySentinel;
  v2 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( this->mState == STATE_BRIGHTNESS )
  {
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v2 = &gGlobalOverlaySentinel;
    p_HelpBar = &v2->HelpBar;
    v7 = UI_HASH_BUTTON_BACK_PRESSED_30;
    v8 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
    v9 = UFG::qStringHash32("UIHKScreenMainMenu", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v9;
    *(_QWORD *)&data.priority = 0i64;
    *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$COMMON_ACCEPT_UPPERCASE");
    UFG::qString::Set((UFG::qString *)&data.Captions[0].mMagic, "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)&data.Captions[1].mMagic, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[2].mMagic, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[3].mMagic, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[4].mMagic, &customCaption);
    data.Icons[5].mMagic = v8;
    data.Icons[5].mLength = v7;
    data.Icons[5].mData = 0i64;
    *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
    UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
    UFG::qString::~qString((UFG::qString *)data.MessageIds);
    `eh vector destructor iterator(
      &data.Captions[5].mMagic,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
  }
  else
  {
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v2 = &gGlobalOverlaySentinel;
    v3 = &v2->HelpBar;
    v4 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
    v5 = UFG::qStringHash32("UIHKScreenMainMenu", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v5;
    *(_QWORD *)&data.priority = 0i64;
    *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$COMMON_ACCEPT_UPPERCASE");
    UFG::qString::Set((UFG::qString *)&data.Captions[0].mMagic, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[1].mMagic, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[2].mMagic, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[3].mMagic, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[4].mMagic, &customCaption);
    data.Icons[5].mMagic = v4;
    memset(&data.Icons[5].mLength, 0, 20);
    UFG::UIHKHelpBarWidget::Show(v3, &data);
    UFG::qString::~qString((UFG::qString *)data.MessageIds);
    `eh vector destructor iterator(
      &data.Captions[5].mMagic,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
  }
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  v10 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v1->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
  v1->HelpBar.mYOffset = -20.0;
  v1->HelpBar.mChanged |= v10;
}

