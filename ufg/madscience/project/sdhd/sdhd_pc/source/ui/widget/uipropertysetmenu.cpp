// File Line: 67
// RVA: 0x1569D30
__int64 UFG::_dynamic_initializer_for__UIListSymbol_operation__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("operation", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UIListSymbol_operation, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__UIListSymbol_operation__);
}

// File Line: 89
// RVA: 0x5C8940
void __fastcall UFG::UIPropertySetMenu::UIPropertySetMenu(UFG::UIPropertySetMenu *this)
{
  UFG::UIPropertySetMenu *v1; // rdi
  UFG::UIPropertySetMenuData *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::UIPropertySetMenuVtbl *)&UFG::UIPropertySetMenu::`vftable';
  v2 = &this->mInitData;
  *(_OWORD *)&v2->vfptr = (unsigned __int64)&UFG::UIPropertySetMenuData::`vftable';
  UFG::qString::qString(&this->mInitData.mPropertySetName);
  UFG::qString::qString(&v2->mPathToWidget);
  v1->mState = -1;
  UFG::qString::qString(&v1->mSelectedItem);
  UFG::qString::qString(&v1->mSelectedSubItem);
  UFG::qString::qString(&v1->mGameSetup);
  UFG::qString::qString(&v1->mOperation);
  UFG::qString::qString(&v1->mOpDependant);
  UFG::qString::qString(&v1->mScriptFunc);
  v1->mProgressionFlow.mUID = -1;
}

// File Line: 95
// RVA: 0x5CE110
void __fastcall UFG::UIPropertySetMenu::~UIPropertySetMenu(UFG::UIPropertySetMenu *this)
{
  UFG::UIPropertySetMenu *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::UIPropertySetMenuVtbl *)&UFG::UIPropertySetMenu::`vftable';
  UFG::qString::~qString(&this->mScriptFunc);
  UFG::qString::~qString(&v1->mOpDependant);
  UFG::qString::~qString(&v1->mOperation);
  UFG::qString::~qString(&v1->mGameSetup);
  UFG::qString::~qString(&v1->mSelectedSubItem);
  UFG::qString::~qString(&v1->mSelectedItem);
  v1 = (UFG::UIPropertySetMenu *)((char *)v1 + 16);
  v1->vfptr = (UFG::UIPropertySetMenuVtbl *)&UFG::UIPropertySetMenuData::`vftable';
  UFG::qString::~qString((UFG::qString *)((char *)&v1->mInitData.mPropertySetName + 24));
  UFG::qString::~qString((UFG::qString *)&v1->mInitData);
}

// File Line: 102
// RVA: 0x637AD0
void __fastcall UFG::UIPropertySetMenu::init(UFG::UIPropertySetMenu *this, UFG::UIPropertySetMenuData *initData)
{
  UFG::UIPropertySetMenuData *v2; // rbx
  UFG::UIPropertySetMenu *v3; // rdi
  Scaleform::GFx::Movie *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *v6; // rax
  char *v7; // rax
  signed int v8; // eax
  unsigned int v9; // eax
  signed int v10; // ecx
  UFG::UIScreen *v11; // rbx
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-98h]
  void *(__fastcall *v13)(UFG::UIPropertySetMenu *, unsigned int); // [rsp+60h] [rbp-68h]
  UFG::qString v14; // [rsp+68h] [rbp-60h]
  UFG::qString v15; // [rsp+90h] [rbp-38h]
  UFG::qSymbol result; // [rsp+D0h] [rbp+8h]

  v13 = (void *(__fastcall *)(UFG::UIPropertySetMenu *, unsigned int))-2i64;
  v2 = initData;
  v3 = this;
  this->mInitData.mScreen = initData->mScreen;
  UFG::qString::Set(
    &this->mInitData.mPropertySetName,
    initData->mPropertySetName.mData,
    initData->mPropertySetName.mLength,
    0i64,
    0);
  UFG::qString::Set(&v3->mInitData.mPathToWidget, v2->mPathToWidget.mData, v2->mPathToWidget.mLength, 0i64, 0);
  v4 = v3->mInitData.mScreen->mRenderable->m_movie.pObject;
  v5 = UFG::qSymbol::create_from_string(&result, v3->mInitData.mPropertySetName.mData);
  v6 = UFG::PropertySetManager::GetPropertySet(v5);
  v3->mPSSetData = v6;
  if ( v6 )
  {
    v7 = UFG::qPropertySet::Get<char const *>(v6, (UFG::qSymbol *)&UIListSymbol_numSlots.mUID, DEPTH_RECURSE);
    v8 = UFG::qToUInt32(v7, 0);
  }
  else
  {
    v8 = 1;
  }
  v3->mNumVisibleSlots = v8;
  v9 = UFG::UIPropertySetMenu::populateMenu(v3, v3->mPSSetData);
  v10 = v3->mNumVisibleSlots;
  if ( v9 < v10 )
    v10 = v9;
  v3->mNumVisibleSlots = v10;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 5;
  pargs.mValue.NValue = (double)v10;
  UFG::qString::qString(&v15, "%s.SetNumVisualSlots", v3->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v4, v15.mData, 0i64, &pargs, 1u);
  v11 = v3->mInitData.mScreen;
  UFG::qString::qString(&v14, "%s.Refresh", v3->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v11->mRenderable->m_movie.pObject, v14.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v14);
  UFG::qString::Set(&v3->mSelectedSubItem, &customWorldMapCaption);
  v3->mState = 0;
  v3->vfptr->updateHelpbar(v3);
  UFG::qString::~qString(&v15);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}

// File Line: 129
// RVA: 0x63AA20
void __fastcall UFG::UIPropertySetMenu::setSelectedMenuIndex(UFG::UIPropertySetMenu *this, UFG::UIScreen *screen, int val)
{
  int v3; // edi
  UFG::UIPropertySetMenu *v4; // rsi
  Scaleform::GFx::Movie *v5; // rbx
  UFG::qString v6; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::Value pargs; // [rsp+60h] [rbp-38h]

  v3 = val;
  v4 = this;
  v5 = UFG::UIScreen::getMovieSafe(screen);
  if ( v5 )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v3;
    UFG::qString::qString(&v6, "%s.SetSelectedIndex", v4->mInitData.mPathToWidget.mData);
    Scaleform::GFx::Movie::Invoke(v5, v6.mData, 0i64, &pargs, 1u);
    UFG::qString::~qString(&v6);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

// File Line: 145
// RVA: 0x62F230
char __fastcall UFG::UIPropertySetMenu::handleMessage(UFG::UIPropertySetMenu *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // edi
  UFG::UIPropertySetMenu *v5; // rbx
  Scaleform::GFx::Movie *v6; // rbp
  UFG::UIScreen *v7; // rax
  UFG::UIHKScreenGlobalOverlay *v8; // rcx
  const char *v9; // rdx
  UFG::UIPropertySetMenu::eMenuState v10; // eax
  const char *v11; // rdx
  UFG::qString v13; // [rsp+28h] [rbp-40h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  v7 = UFG::UIScreenManagerBase::getOverlay(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "GlobalOverlay");
  if ( v7 )
  {
    v8 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v8 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::HandleMessage(&v8->HelpBar, v7, v4, v3);
  }
  if ( v4 == UI_HASH_THUMBSTICK_LEFT_DOWN_30 || v4 == UI_HASH_DPAD_DOWN_PRESSED_30 || v4 == UI_HASH_DPAD_DOWN_REPEAT_30 )
  {
    UFG::UIPropertySetMenu::Flash_ScrollNext(v5, v5->mInitData.mScreen);
    return 1;
  }
  if ( v4 == UI_HASH_THUMBSTICK_LEFT_UP_30 || v4 == UI_HASH_DPAD_UP_PRESSED_30 || v4 == UI_HASH_DPAD_UP_REPEAT_30 )
  {
    UFG::UIPropertySetMenu::Flash_ScrollPrev(v5, v5->mInitData.mScreen);
    return 1;
  }
  if ( v4 == UI_HASH_MOUSE_MOVE_30 )
  {
    UFG::UIPropertySetMenu::Flash_HandleMouseMove(
      v5,
      v5->mInitData.mScreen,
      (float)SLODWORD(v3[1].vfptr),
      (float)SHIDWORD(v3[1].vfptr));
    return 1;
  }
  if ( v4 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
  {
    UFG::UIPropertySetMenu::Flash_HandleMouseClick(
      v5,
      v5->mInitData.mScreen,
      (float)SLODWORD(v3[1].vfptr),
      (float)SHIDWORD(v3[1].vfptr));
    return 1;
  }
  if ( v4 == UI_HASH_MAIN_MENU_STATE_20 )
  {
    if ( v5->mState != 2 )
      return 1;
    UFG::qString::qString(&v13, (UFG::qString *)&v3[1]);
    if ( (unsigned int)UFG::qStringCompare(v13.mData, "MAINMENU", -1) )
    {
      if ( (unsigned int)UFG::qStringCompare(v13.mData, "SUBMENU", -1) )
      {
LABEL_22:
        UFG::qString::~qString(&v13);
        return 1;
      }
      v5->mState = 1;
    }
    else
    {
      UFG::qString::Set(&v5->mSelectedSubItem, &customWorldMapCaption);
      v5->mState = 0;
    }
    v5->vfptr->updateHelpbar(v5);
    goto LABEL_22;
  }
  if ( v4 != UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( v4 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    {
      *(_QWORD *)&v13.mMagic = 0i64;
      LODWORD(v13.mData) = 0;
      Scaleform::GFx::Movie::GetVariable(v6, (Scaleform::GFx::Value *)&v13, "gSelectedItem");
      if ( ((_QWORD)v13.mData & 0x8F) == 6 )
      {
        if ( (LODWORD(v13.mData) >> 6) & 1 )
          v9 = **(const char ***)&v13.mStringHash32;
        else
          v9 = *(const char **)&v13.mStringHash32;
        UFG::qString::Set(&v5->mSelectedItem, v9);
        v10 = v5->mState;
        if ( v10 )
        {
          if ( v10 == 1 )
          {
            Scaleform::GFx::Movie::GetVariable(v6, (Scaleform::GFx::Value *)&v13, "gSelectedSubItem");
            if ( (LODWORD(v13.mData) >> 6) & 1 )
              v11 = **(const char ***)&v13.mStringHash32;
            else
              v11 = *(const char **)&v13.mStringHash32;
            UFG::qString::Set(&v5->mSelectedSubItem, v11);
            UFG::UIPropertySetMenu::getOptionDetails(
              v5,
              v5->mPSSetData,
              v5->mSelectedItem.mData,
              v5->mSelectedSubItem.mData);
          }
        }
        else if ( !UFG::UIPropertySetMenu::getOptionDetails(
                     v5,
                     v5->mPSSetData,
                     v5->mSelectedItem.mData,
                     &customWorldMapCaption) )
        {
          UFG::UIPropertySetMenu::populateSubMenu(v5, v5->mPSSetData, v5->mSelectedItem.mData);
          UFG::UIPropertySetMenu::Flash_Refresh(v5, v5->mInitData.mScreen);
          v5->vfptr->expandSubMenu(v5);
        }
      }
      if ( (LODWORD(v13.mData) >> 6) & 1 )
      {
        (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v13.mMagic + 16i64))(
          *(_QWORD *)&v13.mMagic,
          &v13,
          *(_QWORD *)&v13.mStringHash32);
        *(_QWORD *)&v13.mMagic = 0i64;
      }
      LODWORD(v13.mData) = 0;
      return 1;
    }
    if ( v4 != (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
      return 0;
  }
  if ( v5->mState == 1 )
    v5->vfptr->leaveSubMenu(v5);
  return 1;
}

// File Line: 259
// RVA: 0x639130
__int64 __fastcall UFG::UIPropertySetMenu::populateMenu(UFG::UIPropertySetMenu *this, UFG::qPropertySet *data)
{
  UFG::qPropertySet *v2; // rbx
  unsigned int v3; // er15
  UFG::qPropertyList *v5; // rax
  UFG::qPropertyList *v6; // r13
  unsigned int v7; // er12
  unsigned int v8; // ebp
  char *v9; // rax
  UFG::qPropertySet *v10; // rsi
  char *v11; // rbx
  bool *v12; // rax
  char *v13; // rcx
  char v14; // r14
  __int64 v15; // rdi
  __int64 v16; // rdx
  UFG::UIGfxTranslator *v17; // rcx
  char *v18; // rax
  UFG::UIPropertySetMenu *v19; // [rsp+60h] [rbp+8h]
  char v20; // [rsp+68h] [rbp+10h]

  v19 = this;
  v2 = data;
  v3 = 0;
  ((void (*)(void))this->vfptr->clear)();
  if ( !v2 )
    return 0i64;
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qSymbol *)&UIListSymbol_items.mUID, DEPTH_RECURSE);
  v6 = v5;
  if ( v5 )
  {
    v7 = v5->mNumElements;
    v8 = 0;
    if ( v7 )
    {
      do
      {
        v9 = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v8);
        if ( v9 && *(_QWORD *)v9 )
          v10 = (UFG::qPropertySet *)&v9[*(_QWORD *)v9];
        else
          v10 = 0i64;
        v11 = UFG::qPropertySet::Get<char const *>(v10, (UFG::qSymbol *)&UIListSymbol_caption.mUID, DEPTH_RECURSE);
        if ( !UFG::qStringFindInsensitive(v11, "Debug") )
        {
          v20 = 1;
          v12 = UFG::qPropertySet::Get<bool>(v10, (UFG::qSymbol *)&UIListSymbol_enabled.mUID, DEPTH_RECURSE);
          v13 = &v20;
          if ( v12 )
            v13 = (char *)v12;
          v14 = *v13;
          if ( UFG::ProgressionTracker::Instance()->mModeType == 2
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
            v16 = (unsigned int)UFG::qStringHashUpper32(v11, 0xFFFFFFFF);
            v17 = UFG::UIScreenManager::s_instance->m_translator;
            if ( !v17
              || (v15 = (__int64)v17->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v17->vfptr, v16)) == 0 )
            {
              v15 = (__int64)v11;
            }
          }
          else
          {
            v15 = 0i64;
          }
          v18 = UFG::qPropertySet::Get<char const *>(v10, (UFG::qSymbol *)&UIListSymbol_platform.mUID, DEPTH_RECURSE);
          if ( v19->vfptr->addItem(v19, (const char *)v15, v18, v14) )
            ++v3;
        }
        ++v8;
      }
      while ( v8 < v7 );
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gSym_GetSubMenuNames__);
}

// File Line: 357
// RVA: 0x639370
void __fastcall UFG::UIPropertySetMenu::populateScriptSubMenu(UFG::UIPropertySetMenu *this, UFG::qSymbol *scriptSubMenuName, UFG::qPropertySet *data, const char *subItemCaption)
{
  UFG::UIPropertySetMenu *v4; // r14
  UFG::qSymbol *v5; // rdi
  SSClass *v6; // rbx
  __int64 v7; // rax
  int *v8; // rcx
  int v9; // ebx
  __int64 v10; // rdi
  signed __int64 v11; // rdx
  signed __int64 v12; // rdi
  __int64 v13; // rsi
  const char *v14; // rbx
  _BOOL8 v15; // r8
  __int64 v16; // rdx
  unsigned int v17; // eax
  UFG::UIGfxTranslator *v18; // rcx
  _DWORD *v19; // rcx
  bool v20; // zf
  SSInstance *v21; // [rsp+30h] [rbp-18h]
  __int64 v22; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = scriptSubMenuName;
  v6 = SSBrain::get_class("GameConfigs");
  v21 = SSSymbol::as_instance((ASymbol *)v5);
  v7 = (__int64)v6->vfptr->get_metaclass((SSClassDescBase *)&v6->vfptr);
  (*(void (__fastcall **)(__int64, UFG::qStaticSymbol *, SSInstance **, signed __int64, __int64 *, _QWORD))(*(_QWORD *)(v7 + 8) + 104i64))(
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
  v4->vfptr->initSubMenu(v4, v11);
  if ( (unsigned int)(v9 - 1) > 2 )
  {
    v12 = v10 + 16;
    v13 = (v9 - 4) / 3u + 1;
    do
    {
      v14 = **(const char ***)(*(_QWORD *)v12 + 32i64);
      if ( !UFG::qStringFindInsensitive(**(const char ***)(*(_QWORD *)v12 + 32i64), "Debug") )
      {
        if ( v14 )
        {
          if ( *v14 == 36 )
            ++v14;
          v17 = UFG::qStringHashUpper32(v14, 0xFFFFFFFF);
          v18 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v18 || (v16 = (__int64)v18->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, v17)) == 0 )
            v16 = (__int64)v14;
        }
        else
        {
          v16 = 0i64;
        }
        LOBYTE(v15) = 1;
        v4->vfptr->addSubmenuItem(v4, (const char *)v16, v15);
      }
      v12 += 24i64;
      --v13;
    }
    while ( v13 );
  }
  v19 = (_DWORD *)v22;
  v20 = *(_DWORD *)(v22 + 16) == 1;
  --v19[4];
  if ( v20 )
  {
    v19[4] = 2147483648;
    (*(void (**)(void))(*(_QWORD *)v19 + 112i64))();
  }
}

// File Line: 399
// RVA: 0x6394F0
void __fastcall UFG::UIPropertySetMenu::populateSubMenu(UFG::UIPropertySetMenu *this, UFG::qPropertySet *data, const char *subItemCaption)
{
  UFG::qPropertySet *v3; // rbx
  const char *v4; // rdi
  UFG::UIPropertySetMenu *v5; // r12
  UFG::qPropertyList *v6; // rax
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *v8; // r15
  UFG::qSymbol *v9; // rax
  UFG::qPropertyList *v10; // r13
  char *v11; // rax
  unsigned int v12; // eax
  unsigned int v13; // er14
  unsigned int v14; // edi
  unsigned int v15; // ebx
  unsigned int v16; // esi
  char *v17; // rax
  UFG::qPropertySet *v18; // rcx
  char *v19; // rax
  unsigned int v20; // ebp
  char *v21; // rax
  UFG::qPropertySet *v22; // rsi
  char *v23; // rbx
  bool *v24; // rax
  char *v25; // rcx
  char v26; // r15
  __int64 v27; // rdi
  unsigned int v28; // eax
  UFG::UIGfxTranslator *v29; // rcx
  char *v30; // rax
  char v31; // [rsp+68h] [rbp+10h]
  UFG::qPropertySet *v32; // [rsp+78h] [rbp+20h]

  if ( data )
  {
    v3 = data;
    v4 = subItemCaption;
    v5 = this;
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(data, (UFG::qSymbol *)&UIListSymbol_items.mUID, DEPTH_RECURSE);
    if ( v6 )
    {
      v7 = UFG::UIPropertySetMenu::FindPSItemByCaption(v5, v6, v4);
      v8 = v7;
      v32 = v7;
      if ( v7 )
      {
        v9 = UFG::qPropertySet::Get<UFG::qSymbol>(v7, (UFG::qSymbol *)&UIListSymbol_scriptsubmenu.mUID, DEPTH_RECURSE);
        if ( v9 )
        {
          UFG::UIPropertySetMenu::populateScriptSubMenu(v5, v9, v3, v4);
        }
        else
        {
          v10 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                  v8,
                  (UFG::qSymbol *)&UIListSymbol_submenu.mUID,
                  DEPTH_RECURSE);
          if ( v10 )
          {
            v11 = UFG::qPropertySet::Get<char const *>(v8, (UFG::qSymbol *)&UIListSymbol_numSlots.mUID, DEPTH_RECURSE);
            v12 = UFG::qToUInt32(v11, 0);
            v13 = v10->mNumElements;
            v14 = 0;
            v15 = 0;
            v16 = v12;
            if ( !v13 )
              goto LABEL_36;
            do
            {
              v17 = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v15);
              if ( v17 && *(_QWORD *)v17 )
                v18 = (UFG::qPropertySet *)&v17[*(_QWORD *)v17];
              else
                v18 = 0i64;
              v19 = UFG::qPropertySet::Get<char const *>(v18, (UFG::qSymbol *)&UIListSymbol_caption.mUID, DEPTH_RECURSE);
              if ( !UFG::qStringFindInsensitive(v19, "Debug") )
                ++v14;
              ++v15;
            }
            while ( v15 < v13 );
            if ( v16 >= v14 )
LABEL_36:
              v16 = v14;
            v5->vfptr->initSubMenu(v5, v16);
            v20 = 0;
            if ( v13 )
            {
              do
              {
                v21 = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v20);
                if ( v21 && *(_QWORD *)v21 )
                  v22 = (UFG::qPropertySet *)&v21[*(_QWORD *)v21];
                else
                  v22 = 0i64;
                v23 = UFG::qPropertySet::Get<char const *>(
                        v22,
                        (UFG::qSymbol *)&UIListSymbol_caption.mUID,
                        DEPTH_RECURSE);
                if ( !UFG::qStringFindInsensitive(v23, "Debug") )
                {
                  v31 = 1;
                  v24 = UFG::qPropertySet::Get<bool>(v8, (UFG::qSymbol *)&UIListSymbol_enabled.mUID, DEPTH_RECURSE);
                  v25 = &v31;
                  if ( v24 )
                    v25 = (char *)v24;
                  v26 = *v25;
                  if ( v23 )
                  {
                    if ( *v23 == 36 )
                      ++v23;
                    v28 = UFG::qStringHashUpper32(v23, 0xFFFFFFFF);
                    v29 = UFG::UIScreenManager::s_instance->m_translator;
                    if ( !v29
                      || (v27 = (__int64)v29->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v29->vfptr, v28)) == 0 )
                    {
                      v27 = (__int64)v23;
                    }
                  }
                  else
                  {
                    v27 = 0i64;
                  }
                  v30 = UFG::qPropertySet::Get<char const *>(
                          v22,
                          (UFG::qSymbol *)&UIListSymbol_platform.mUID,
                          DEPTH_RECURSE);
                  v5->vfptr->addSubmenuItem(v5, (const char *)v27, v30, v26);
                  v8 = v32;
                }
                ++v20;
              }
              while ( v20 < v13 );
            }
          }
        }
      }
    }
  }
}

// File Line: 467
// RVA: 0x620BB0
bool __fastcall UFG::UIPropertySetMenu::getOptionDetailsScriptSubMenu(UFG::UIPropertySetMenu *this, UFG::qSymbol *scriptSubMenuName, UFG::qPropertySet *data, const char *itemCaption, const char *subItemCaption)
{
  UFG::UIPropertySetMenu *v5; // r14
  UFG::qSymbol *v6; // rdi
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
  UFG::UIGfxTranslator *v17; // rcx
  bool v18; // zf
  bool result; // al
  const char *v20; // rbp
  const char *v21; // r13
  const char *v22; // r12
  const char *v23; // r15
  UFG::UIScreen *v24; // rax
  unsigned int v25; // edi
  UFG::UIScreenManager *v26; // rbx
  unsigned int v27; // eax
  _DWORD *v28; // rcx
  __int64 v29; // [rsp+30h] [rbp-38h]
  SSInstance *v30; // [rsp+38h] [rbp-30h]

  v5 = this;
  v6 = scriptSubMenuName;
  v7 = SSBrain::get_class("GameConfigs");
  v30 = SSSymbol::as_instance((ASymbol *)v6);
  v8 = (__int64)v7->vfptr->get_metaclass((SSClassDescBase *)&v7->vfptr);
  (*(void (__fastcall **)(__int64, UFG::qStaticSymbol *, SSInstance **, signed __int64, __int64 *, _QWORD))(*(_QWORD *)(v8 + 8) + 104i64))(
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
      v9[4] = 2147483648;
      (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v9 + 112i64))(v9);
    }
    result = 0;
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
        v16 = UFG::qStringHashUpper32(v14, 0xFFFFFFFF);
        v17 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v17
          || (v15 = (const char *)v17->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v17->vfptr, v16)) == 0i64 )
        {
          v15 = v14;
        }
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
      v24 = v5->mInitData.mScreen;
      v25 = -1;
      if ( v24 )
        v25 = v24->mScreenUID;
      v26 = UFG::UIScreenManager::s_instance;
      v27 = UFG::qStringHashUpper32(v20, 0xFFFFFFFF);
      UFG::UIScreenManagerBase::queueMessage((UFG::UIScreenManagerBase *)&v26->vfptr, v27, v25);
    }
    if ( v22 )
      v5->vfptr->setScriptFuncStr(v5, v22);
    v5->vfptr->setGameSetup(v5, v21);
    v5->vfptr->setOpDependant(v5, v23);
    v28 = (_DWORD *)v29;
    v18 = *(_DWORD *)(v29 + 16) == 1;
    --v28[4];
    if ( v18 )
    {
      v28[4] = 2147483648;
      (*(void (**)(void))(*(_QWORD *)v28 + 112i64))();
    }
    result = v20 != 0i64;
  }
  return result;
}

// File Line: 521
// RVA: 0x6208B0
bool __fastcall UFG::UIPropertySetMenu::getOptionDetails(UFG::UIPropertySetMenu *this, UFG::qPropertySet *data, const char *itemCaption, const char *subItemCaption)
{
  const char *v4; // rbp
  const char *v5; // r14
  UFG::qPropertySet *v6; // rsi
  UFG::UIPropertySetMenu *v7; // rdi
  UFG::qPropertySet *v8; // rax
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
  char *v23; // rdx
  bool v24; // zf
  char *v25; // r13
  char *v26; // r12
  char *v27; // r15
  char *v28; // rbp
  UFG::qSymbol *v29; // r14
  UFG::UIScreen *v30; // rcx
  unsigned int v31; // esi
  UFG::UIScreenManager *v32; // rbx
  unsigned int v33; // eax
  char *v34; // rdx
  UFG::UIPropertySetMenuVtbl *v35; // rbx
  UFG::qStaticSymbol *v36; // rax

  v4 = subItemCaption;
  v5 = itemCaption;
  v6 = data;
  v7 = this;
  if ( data
    && (v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(data, (UFG::qSymbol *)&UIListSymbol_items.mUID, DEPTH_RECURSE)) != 0i64 )
  {
    v8 = UFG::UIPropertySetMenu::FindPSItemByCaption(v7, v9, v5);
    v10 = v8;
    if ( v8 )
    {
      if ( (signed int)UFG::qStringLength(v4) <= 0 )
      {
        v25 = UFG::qPropertySet::Get<char const *>(v10, (UFG::qSymbol *)&UIListSymbol_operation.mUID, DEPTH_RECURSE);
        v26 = UFG::qPropertySet::Get<char const *>(v10, (UFG::qSymbol *)&UIListSymbol_gamesetup.mUID, DEPTH_RECURSE);
        v27 = UFG::qPropertySet::Get<char const *>(v10, (UFG::qSymbol *)&UIListSymbol_scriptname.mUID, DEPTH_RECURSE);
        v28 = UFG::qPropertySet::Get<char const *>(v10, (UFG::qSymbol *)&UIListSymbol_dependant.mUID, DEPTH_RECURSE);
        v29 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qSymbol *)&UIListSymbol_flow.mUID, DEPTH_RECURSE);
        if ( v25 )
        {
          v30 = v7->mInitData.mScreen;
          v31 = -1;
          if ( v30 )
            v31 = v30->mScreenUID;
          v32 = UFG::UIScreenManager::s_instance;
          v33 = UFG::qStringHashUpper32(v25, 0xFFFFFFFF);
          UFG::UIScreenManagerBase::queueMessage((UFG::UIScreenManagerBase *)&v32->vfptr, v33, v31);
        }
        if ( v26 )
          v7->vfptr->setGameSetup(v7, v26);
        if ( v27 )
          v7->vfptr->setScriptFuncStr(v7, v27);
        v34 = v28;
        if ( !v28 )
          v34 = &customWorldMapCaption;
        v7->vfptr->setOpDependant(v7, v34);
        if ( v29 )
        {
          v7->vfptr->setProgressionFlow(v7, v29);
        }
        else
        {
          UFG::ProgressionTracker::Instance();
          v35 = v7->vfptr;
          v36 = UFG::ProgressionTracker::GetDefaultFlow();
          v35->setProgressionFlow(v7, (UFG::qSymbol *)&v36->mUID);
        }
        v24 = v25 == 0i64;
      }
      else
      {
        v11 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qSymbol *)&UIListSymbol_scriptsubmenu.mUID, DEPTH_RECURSE);
        if ( v11 )
        {
          LOBYTE(v8) = UFG::UIPropertySetMenu::getOptionDetailsScriptSubMenu(v7, v11, v6, v5, v4);
          return (char)v8;
        }
        v12 = UFG::qPropertySet::Get<UFG::qPropertyList>(v10, (UFG::qSymbol *)&UIListSymbol_submenu.mUID, DEPTH_RECURSE);
        if ( !v12 || (v13 = UFG::UIPropertySetMenu::FindPSItemByCaption(v7, v12, v4), (v14 = v13) == 0i64) )
        {
          LOBYTE(v8) = 0;
          return (char)v8;
        }
        v15 = UFG::qPropertySet::Get<char const *>(v13, (UFG::qSymbol *)&UIListSymbol_operation.mUID, DEPTH_RECURSE);
        v16 = UFG::qPropertySet::Get<char const *>(v14, (UFG::qSymbol *)&UIListSymbol_gamesetup.mUID, DEPTH_RECURSE);
        v17 = UFG::qPropertySet::Get<char const *>(v14, (UFG::qSymbol *)&UIListSymbol_scriptname.mUID, DEPTH_RECURSE);
        v18 = UFG::qPropertySet::Get<char const *>(v14, (UFG::qSymbol *)&UIListSymbol_dependant.mUID, DEPTH_RECURSE);
        if ( v15 )
        {
          v19 = v7->mInitData.mScreen;
          v20 = -1;
          if ( v19 )
            v20 = v19->mScreenUID;
          v21 = UFG::UIScreenManager::s_instance;
          v22 = UFG::qStringHashUpper32(v15, 0xFFFFFFFF);
          UFG::UIScreenManagerBase::queueMessage((UFG::UIScreenManagerBase *)&v21->vfptr, v22, v20);
        }
        if ( v16 )
          v7->vfptr->setGameSetup(v7, v16);
        if ( v17 )
          v7->vfptr->setScriptFuncStr(v7, v17);
        v23 = v18;
        if ( !v18 )
          v23 = &customWorldMapCaption;
        v7->vfptr->setOpDependant(v7, v23);
        v24 = v15 == 0i64;
      }
      LOBYTE(v8) = !v24;
      return (char)v8;
    }
  }
  else
  {
    LOBYTE(v8) = 0;
  }
  return (char)v8;
}

// File Line: 614
// RVA: 0x61F2A0
void __fastcall UFG::UIPropertySetMenu::clear(UFG::UIPropertySetMenu *this)
{
  Scaleform::GFx::Movie *v1; // rbx
  UFG::qString v2; // [rsp+28h] [rbp-30h]

  v1 = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v2, "%s.Clear", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v1, v2.mData, &customWorldMapCaption);
  UFG::qString::~qString(&v2);
}

// File Line: 624
// RVA: 0x6385F0
void __fastcall UFG::UIPropertySetMenu::initSubMenu(UFG::UIPropertySetMenu *this, int numSlots)
{
  int v2; // ebx
  UFG::UIPropertySetMenu *v3; // rdi
  Scaleform::GFx::Movie *v4; // rsi
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-98h]
  signed __int64 v6; // [rsp+60h] [rbp-68h]
  UFG::qString v7; // [rsp+68h] [rbp-60h]
  UFG::qString v8; // [rsp+90h] [rbp-38h]

  v6 = -2i64;
  v2 = numSlots;
  v3 = this;
  v4 = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v8, "%s.ClearSubMenu", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v4, v8.mData, &customWorldMapCaption);
  pargs.pObjectInterface = 0i64;
  pargs.Type = 5;
  pargs.mValue.NValue = (double)v2;
  UFG::qString::qString(&v7, "%s.SetNumVisualSubSlots", v3->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v4, v7.mData, 0i64, &pargs, 1u);
  UFG::qString::~qString(&v7);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 0;
  UFG::qString::~qString(&v8);
}

// File Line: 640
// RVA: 0x61DEA0
char __fastcall UFG::UIPropertySetMenu::addItem(UFG::UIPropertySetMenu *this, const char *caption, const char *platform, bool enabled)
{
  bool v4; // di
  const char *v5; // rsi
  UFG::UIPropertySetMenu *v6; // rbx

  v4 = enabled;
  v5 = caption;
  v6 = this;
  if ( platform && (unsigned int)UFG::qStringCompareInsensitive(platform, "pc", -1) )
    return 0;
  v6->vfptr->addItem(v6, v5, v4);
  return 1;
}

// File Line: 666
// RVA: 0x61DD50
void __fastcall UFG::UIPropertySetMenu::addItem(UFG::UIPropertySetMenu *this, const char *caption, bool enabled)
{
  bool v3; // di
  const char *v4; // rbx
  Scaleform::GFx::Movie *v5; // rsi
  char ptr; // [rsp+30h] [rbp-98h]
  __int64 v7; // [rsp+40h] [rbp-88h]
  unsigned int v8; // [rsp+48h] [rbp-80h]
  const char *v9; // [rsp+50h] [rbp-78h]
  char v10; // [rsp+60h] [rbp-68h]
  __int64 v11; // [rsp+70h] [rbp-58h]
  unsigned int v12; // [rsp+78h] [rbp-50h]
  __int64 v13; // [rsp+80h] [rbp-48h]
  __int64 v14; // [rsp+90h] [rbp-38h]
  UFG::qString v15; // [rsp+98h] [rbp-30h]

  v14 = -2i64;
  v3 = enabled;
  v4 = caption;
  v5 = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v15, "%s.AddItem", this->mInitData.mPathToWidget.mData);
  `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v8 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v7 + 16i64))(v7, &ptr, v9);
    v7 = 0i64;
  }
  v8 = 6;
  v9 = v4;
  if ( (v12 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, &v10, v13);
    v11 = 0i64;
  }
  v12 = 2;
  LOBYTE(v13) = v3;
  Scaleform::GFx::Movie::Invoke(v5, v15.mData, 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v15);
}

// File Line: 684
// RVA: 0x61E0C0
char __fastcall UFG::UIPropertySetMenu::addSubmenuItem(UFG::UIPropertySetMenu *this, const char *caption, const char *platform, bool enabled)
{
  bool v4; // di
  const char *v5; // rsi
  UFG::UIPropertySetMenu *v6; // rbx

  v4 = enabled;
  v5 = caption;
  v6 = this;
  if ( platform && (unsigned int)UFG::qStringCompareInsensitive(platform, "pc", -1) )
    return 0;
  v6->vfptr->addSubmenuItem(v6, v5, v4);
  return 1;
}

// File Line: 710
// RVA: 0x61DF70
void __fastcall UFG::UIPropertySetMenu::addSubmenuItem(UFG::UIPropertySetMenu *this, const char *caption, bool enabled)
{
  bool v3; // di
  const char *v4; // rbx
  Scaleform::GFx::Movie *v5; // rsi
  char ptr; // [rsp+30h] [rbp-98h]
  __int64 v7; // [rsp+40h] [rbp-88h]
  unsigned int v8; // [rsp+48h] [rbp-80h]
  const char *v9; // [rsp+50h] [rbp-78h]
  char v10; // [rsp+60h] [rbp-68h]
  __int64 v11; // [rsp+70h] [rbp-58h]
  unsigned int v12; // [rsp+78h] [rbp-50h]
  __int64 v13; // [rsp+80h] [rbp-48h]
  __int64 v14; // [rsp+90h] [rbp-38h]
  UFG::qString v15; // [rsp+98h] [rbp-30h]

  v14 = -2i64;
  v3 = enabled;
  v4 = caption;
  v5 = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v15, "%s.AddSubMenuItem", this->mInitData.mPathToWidget.mData);
  `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v8 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v7 + 16i64))(v7, &ptr, v9);
    v7 = 0i64;
  }
  v8 = 6;
  v9 = v4;
  if ( (v12 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, &v10, v13);
    v11 = 0i64;
  }
  v12 = 2;
  LOBYTE(v13) = v3;
  Scaleform::GFx::Movie::Invoke(v5, v15.mData, 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v15);
}

// File Line: 726
// RVA: 0x63A7D0
void __fastcall UFG::UIPropertySetMenu::setItemEnabled(UFG::UIPropertySetMenu *this, const char *caption, bool enabled)
{
  bool v3; // si
  const char *v4; // rbx
  UFG::UIPropertySetMenu *v5; // rdi
  Scaleform::GFx::Movie *v6; // rbp
  UFG::UIScreen *v7; // rbx
  char ptr; // [rsp+30h] [rbp-C8h]
  __int64 v9; // [rsp+40h] [rbp-B8h]
  unsigned int v10; // [rsp+48h] [rbp-B0h]
  const char *v11; // [rsp+50h] [rbp-A8h]
  char v12; // [rsp+60h] [rbp-98h]
  __int64 v13; // [rsp+70h] [rbp-88h]
  unsigned int v14; // [rsp+78h] [rbp-80h]
  __int64 v15; // [rsp+80h] [rbp-78h]
  __int64 v16; // [rsp+90h] [rbp-68h]
  UFG::qString v17; // [rsp+98h] [rbp-60h]
  UFG::qString v18; // [rsp+C0h] [rbp-38h]

  v16 = -2i64;
  v3 = enabled;
  v4 = caption;
  v5 = this;
  v6 = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v18, "%s.SetItemEnabled", this->mInitData.mPathToWidget.mData);
  `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v10 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v9 + 16i64))(v9, &ptr, v11);
    v9 = 0i64;
  }
  v10 = 6;
  v11 = v4;
  if ( (v14 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v13 + 16i64))(v13, &v12, v15);
    v13 = 0i64;
  }
  v14 = 2;
  LOBYTE(v15) = v3;
  Scaleform::GFx::Movie::Invoke(v6, v18.mData, 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  v7 = v5->mInitData.mScreen;
  UFG::qString::qString(&v17, "%s.Refresh", v5->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v7->mRenderable->m_movie.pObject, v17.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v17);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v18);
}

// File Line: 744
// RVA: 0x639FF0
void __fastcall UFG::UIPropertySetMenu::removeItem(UFG::UIPropertySetMenu *this, const char *caption)
{
  const char *v2; // rbx
  UFG::UIPropertySetMenu *v3; // rdi
  Scaleform::GFx::Movie *v4; // rsi
  UFG::UIScreen *v5; // rbx
  char ptr; // [rsp+30h] [rbp-98h]
  __int64 v7; // [rsp+40h] [rbp-88h]
  unsigned int v8; // [rsp+48h] [rbp-80h]
  const char *v9; // [rsp+50h] [rbp-78h]
  __int64 v10; // [rsp+60h] [rbp-68h]
  UFG::qString v11; // [rsp+68h] [rbp-60h]
  UFG::qString v12; // [rsp+90h] [rbp-38h]

  v10 = -2i64;
  v2 = caption;
  v3 = this;
  v4 = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v12, "%s.RemoveItem", this->mInitData.mPathToWidget.mData);
  `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v8 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v7 + 16i64))(v7, &ptr, v9);
    v7 = 0i64;
  }
  v8 = 6;
  v9 = v2;
  Scaleform::GFx::Movie::Invoke(v4, v12.mData, 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  v5 = v3->mInitData.mScreen;
  UFG::qString::qString(&v11, "%s.Refresh", v3->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v5->mRenderable->m_movie.pObject, v11.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v11);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v12);
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
  UFG::UIPropertySetMenu *v1; // rdi
  Scaleform::GFx::Movie *v2; // rbx
  UFG::qString v3; // [rsp+38h] [rbp-30h]

  v1 = this;
  v2 = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v3, "%s.EnterSubMenu", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v2, v3.mData, &customWorldMapCaption);
  if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xCCF5DDCu,
      0i64,
      0,
      0i64);
  v1->mState = 2;
  UFG::qString::~qString(&v3);
}

// File Line: 827
// RVA: 0x6388A0
void __fastcall UFG::UIPropertySetMenu::leaveSubMenu(UFG::UIPropertySetMenu *this)
{
  UFG::UIPropertySetMenu *v1; // rdi
  Scaleform::GFx::Movie *v2; // rbx
  UFG::qString v3; // [rsp+38h] [rbp-30h]

  v1 = this;
  v2 = this->mInitData.mScreen->mRenderable->m_movie.pObject;
  UFG::qString::qString(&v3, "%s.LeaveSubMenu", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v2, v3.mData, &customWorldMapCaption);
  if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xA4E5BFBD,
      0i64,
      0,
      0i64);
  v1->mState = 2;
  UFG::qString::~qString(&v3);
}

// File Line: 842
// RVA: 0x5D88C0
UFG::qPropertySet *__fastcall UFG::UIPropertySetMenu::FindPSItemByCaption(UFG::UIPropertySetMenu *this, UFG::qPropertyList *pList, const char *caption)
{
  unsigned int v3; // ebp
  unsigned int v4; // esi
  const char *v5; // r15
  UFG::qPropertyList *v6; // r14
  char *v7; // rax
  UFG::qPropertySet *v8; // rdi
  char *v9; // rax
  const char *v10; // rbx
  unsigned int v11; // eax
  UFG::UIGfxTranslator *v12; // rcx

  v3 = pList->mNumElements;
  v4 = 0;
  v5 = caption;
  v6 = pList;
  if ( !v3 )
    return 0i64;
  while ( 1 )
  {
    v7 = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v4);
    if ( v7 && *(_QWORD *)v7 )
      v8 = (UFG::qPropertySet *)&v7[*(_QWORD *)v7];
    else
      v8 = 0i64;
    v9 = UFG::qPropertySet::Get<char const *>(v8, (UFG::qSymbol *)&UIListSymbol_caption.mUID, DEPTH_RECURSE);
    v10 = v9;
    if ( v9 )
    {
      if ( *v9 == 36 )
        v10 = v9 + 1;
      v11 = UFG::qStringHashUpper32(v10, 0xFFFFFFFF);
      v12 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v12 || (v9 = (char *)v12->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, v11)) == 0i64 )
        v9 = (char *)v10;
    }
    if ( !(unsigned int)UFG::qStringCompare(v9, v5, -1) )
      break;
    if ( ++v4 >= v3 )
      return 0i64;
  }
  return v8;
}

// File Line: 906
// RVA: 0x5DEA60
void __fastcall UFG::UIPropertySetMenu::Flash_Refresh(UFG::UIPropertySetMenu *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rbx
  UFG::qString v3; // [rsp+38h] [rbp-30h]

  v2 = screen;
  UFG::qString::qString(&v3, "%s.Refresh", this->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v2->mRenderable->m_movie.pObject, v3.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v3);
}

// File Line: 913
// RVA: 0x5DEF80
void __fastcall UFG::UIPropertySetMenu::Flash_ScrollNext(UFG::UIPropertySetMenu *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rbx
  UFG::UIPropertySetMenu *v3; // rdi
  UFG::qString v4; // [rsp+38h] [rbp-30h]

  v2 = screen;
  v3 = this;
  if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xB78DCE8u,
      0i64,
      0,
      0i64);
  UFG::qString::qString(&v4, "%s.ScrollNext", v3->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v2->mRenderable->m_movie.pObject, v4.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v4);
}

// File Line: 926
// RVA: 0x5DF020
void __fastcall UFG::UIPropertySetMenu::Flash_ScrollPrev(UFG::UIPropertySetMenu *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rbx
  UFG::UIPropertySetMenu *v3; // rdi
  UFG::qString v4; // [rsp+38h] [rbp-30h]

  v2 = screen;
  v3 = this;
  if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x593B70ABu,
      0i64,
      0,
      0i64);
  UFG::qString::qString(&v4, "%s.ScrollPrev", v3->mInitData.mPathToWidget.mData);
  Scaleform::GFx::Movie::Invoke(v2->mRenderable->m_movie.pObject, v4.mData, 0i64, 0i64, 0);
  UFG::qString::~qString(&v4);
}

// File Line: 939
// RVA: 0x5DB620
void __fastcall UFG::UIPropertySetMenu::Flash_HandleMouseMove(UFG::UIPropertySetMenu *this, UFG::UIScreen *screen, float mouseX, float mouseY)
{
  UFG::UIScreen *v4; // rbx
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v6; // [rsp+40h] [rbp-A8h]
  unsigned int v7; // [rsp+48h] [rbp-A0h]
  double v8; // [rsp+50h] [rbp-98h]
  char v9; // [rsp+60h] [rbp-88h]
  __int64 v10; // [rsp+70h] [rbp-78h]
  unsigned int v11; // [rsp+78h] [rbp-70h]
  double v12; // [rsp+80h] [rbp-68h]
  __int64 v13; // [rsp+90h] [rbp-58h]
  UFG::qString v14; // [rsp+98h] [rbp-50h]

  v13 = -2i64;
  v4 = screen;
  UFG::qString::qString(&v14, "%s.HandleMouseMove", this->mInitData.mPathToWidget.mData);
  `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v7 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, &ptr, COERCE_DOUBLE(*(_QWORD *)&v8));
    v6 = 0i64;
  }
  v7 = 5;
  v8 = mouseX;
  if ( (v11 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(v10, &v9, COERCE_DOUBLE(*(_QWORD *)&v12));
    v10 = 0i64;
  }
  v11 = 5;
  v12 = mouseY;
  Scaleform::GFx::Movie::Invoke(v4->mRenderable->m_movie.pObject, v14.mData, 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v14);
}

// File Line: 952
// RVA: 0x5DB110
void __fastcall UFG::UIPropertySetMenu::Flash_HandleMouseClick(UFG::UIPropertySetMenu *this, UFG::UIScreen *screen, float mouseX, float mouseY)
{
  UFG::UIScreen *v4; // rbx
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v6; // [rsp+40h] [rbp-A8h]
  unsigned int v7; // [rsp+48h] [rbp-A0h]
  double v8; // [rsp+50h] [rbp-98h]
  char v9; // [rsp+60h] [rbp-88h]
  __int64 v10; // [rsp+70h] [rbp-78h]
  unsigned int v11; // [rsp+78h] [rbp-70h]
  double v12; // [rsp+80h] [rbp-68h]
  __int64 v13; // [rsp+90h] [rbp-58h]
  UFG::qString v14; // [rsp+98h] [rbp-50h]

  v13 = -2i64;
  v4 = screen;
  UFG::qString::qString(&v14, "%s.HandleMouseClick", this->mInitData.mPathToWidget.mData);
  `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v7 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, &ptr, COERCE_DOUBLE(*(_QWORD *)&v8));
    v6 = 0i64;
  }
  v7 = 5;
  v8 = mouseX;
  if ( (v11 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(v10, &v9, COERCE_DOUBLE(*(_QWORD *)&v12));
    v10 = 0i64;
  }
  v11 = 5;
  v12 = mouseY;
  Scaleform::GFx::Movie::Invoke(v4->mRenderable->m_movie.pObject, v14.mData, 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v14);
}

// File Line: 965
// RVA: 0x62F580
char __fastcall UFG::UIPropertySetMenuMainNav::handleMessage(UFG::UIPropertySetMenuMainNav *this, unsigned int msgId, UFG::UIMessage *msg)
{
  char result; // al

  if ( msgId == UI_HASH_RESTART_MISSION_20 )
  {
    UFG::GameCheats::RestartMission();
    result = 1;
  }
  else if ( msgId == UI_HASH_RESTORE_CHECKPOINT_20 )
  {
    UFG::GameCheats::RestoreCheckpoint();
    result = 1;
  }
  else if ( msgId == UI_HASH_CANCEL_MISSION_20 )
  {
    UFG::GameCheats::CancelMission();
    result = 1;
  }
  else
  {
    result = UFG::UIPropertySetMenu::handleMessage((UFG::UIPropertySetMenu *)&this->vfptr, msgId, msg);
  }
  return result;
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
  UFG::UIHKHelpBarWidget *v6; // r12
  int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ebx
  signed __int64 v10; // r14
  bool v11; // al
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-B8h]

  v1 = &gGlobalOverlaySentinel;
  v2 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( this->mState == 1 )
  {
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v2 = &gGlobalOverlaySentinel;
    v6 = &v2->HelpBar;
    v7 = UI_HASH_BUTTON_BACK_PRESSED_30;
    v8 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
    v9 = UFG::qStringHash32("UIHKScreenMainMenu", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v9;
    *(_QWORD *)&data.priority = 0i64;
    _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$COMMON_ACCEPT_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)data.Captions + 16), "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 16), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 16), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 16), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 16), &customWorldMapCaption);
    data.Icons[5].mMagic = v8;
    data.Icons[5].mLength = v7;
    data.Icons[5].mData = 0i64;
    *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
    UFG::UIHKHelpBarWidget::Show(v6, &data);
    UFG::qString::~qString((UFG::qString *)data.MessageIds);
    `eh vector destructor iterator'(
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
    _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$COMMON_ACCEPT_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)data.Captions + 16), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 16), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 16), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 16), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 16), &customWorldMapCaption);
    data.Icons[5].mMagic = v4;
    *(_OWORD *)&data.Icons[5].mLength = 0ui64;
    data.Icons[5].mStringHashUpper32 = 0;
    UFG::UIHKHelpBarWidget::Show(v3, &data);
    UFG::qString::~qString((UFG::qString *)data.MessageIds);
    `eh vector destructor iterator'(
      &data.Captions[5].mMagic,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
  }
  `eh vector destructor iterator'(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  v10 = (signed __int64)&v1->HelpBar;
  v11 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v1->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
  *(_DWORD *)(v10 + 612) = -1046478848;
  *(_BYTE *)(v10 + 1) |= v11;
}

