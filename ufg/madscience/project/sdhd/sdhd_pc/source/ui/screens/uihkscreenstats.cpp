// File Line: 43
// RVA: 0x1569E70
__int64 UFG::_dynamic_initializer_for__UIStatSymbol_category__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("category", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UIStatSymbol_category, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__UIStatSymbol_category__);
}

// File Line: 67
// RVA: 0x5E9490
signed __int64 __fastcall UFG::UIHKStatItem::GetStatCategoryEnum(const char *str)
{
  const char *v1; // rdi
  unsigned int v2; // ebx
  const char *v3; // rdx

  v1 = str;
  v2 = 0;
  while ( 1 )
  {
    if ( v2 )
    {
      switch ( v2 )
      {
        case 1u:
          v3 = "COMPLETION";
          break;
        case 2u:
          v3 = "WORLD";
          break;
        case 3u:
          v3 = "COMBAT";
          break;
        default:
          v3 = v2 == 4 ? "DEBUG_WEAPON" : "InvalidCategory";
          break;
      }
    }
    else
    {
      v3 = "ALL";
    }
    if ( UFG::qStringFind(v1, v3) )
      break;
    if ( (signed int)++v2 >= 5 )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

// File Line: 119
// RVA: 0x608D00
void __usercall UFG::UIHKScreenStats::SetStatValue(UFG::UIHKScreenStats *this@<rcx>, UFG::UIHKStatItem *item@<rdx>, UFG::qSymbol *statName@<r8>, UFG::qSymbol *statNameIndex@<r9>, float a5@<xmm0>)
{
  UFG::qSymbol *v5; // rsi
  UFG::qSymbol *v6; // rbx
  UFG::UIHKStatItem *v7; // rdi
  UFG::GameStat::Int32Stat v8; // er14
  UFG::GameStat::FloatStat v9; // ebp
  UFG::GameStat::MapInt32Stat v10; // eax
  UFG::GameStat::MapInt32Stat v11; // ebx
  UFG::GameStatTracker *v12; // rax
  UFG::GameStatTracker *v13; // rax
  UFG::GameStatTracker *v14; // rax
  UFG::PersistentData::MapInt *v15; // rax
  const char *v16; // rax
  UFG::GameStat::Int32RangedStat v17; // esi
  UFG::GameStat::MapBoolStat v18; // eax
  UFG::GameStat::MapBoolStat v19; // ebp
  UFG::GameStatTracker *v20; // rax
  unsigned int v21; // ebx
  UFG::GameStatTracker *v22; // rax
  unsigned int v23; // eax
  UFG::qString *v24; // rax
  UFG::GameStatTracker *v25; // rax
  UFG::PersistentData::MapBool *v26; // rax
  unsigned int v27; // ebx
  UFG::GameStatTracker *v28; // rax
  UFG::PersistentData::MapBool *v29; // rax
  unsigned int v30; // eax
  UFG::qString *v31; // rax
  UFG::GameStat::TimeStat v32; // er14
  UFG::GameStat::FloatStat v33; // esi
  UFG::GameStat::MapFloatStat v34; // eax
  UFG::GameStat::MapFloatStat v35; // ebp
  UFG::GameStatTracker *v36; // rax
  UFG::PersistentData::Time *v37; // rax
  UFG::GameStatTracker *v38; // rax
  UFG::GameStatTracker *v39; // rax
  UFG::qString *v40; // rax
  UFG::GameStat::StringStat v41; // ebx
  UFG::GameStatTracker *v42; // rax
  UFG::qString result; // [rsp+28h] [rbp-80h]
  UFG::qString v44; // [rsp+50h] [rbp-58h]
  UFG::qString v45; // [rsp+78h] [rbp-30h]

  v5 = statNameIndex;
  v6 = statName;
  v7 = item;
  switch ( item->mStatType )
  {
    case 0u:
    case 3u:
    case 5u:
    case 7u:
      v8 = (unsigned int)UFG::GameStat::GetInt32StatEnum(statName, 0);
      v9 = (unsigned int)UFG::GameStat::GetFloatStatEnum(v6, 0);
      v10 = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(v6, 0);
      v11 = v10;
      if ( v8 == 163 )
      {
        if ( v9 == 139 )
        {
          if ( !v5 || v10 == 47 )
          {
            v7->mStatType = 8;
            v16 = "FIX ME NUMBER";
            goto LABEL_33;
          }
          if ( v7->mStatType == StatType_Number )
            v7->mStatType = 1;
          v14 = UFG::GameStatTracker::Instance();
          v15 = UFG::GameStatTracker::GetMapInt(v14, v11);
          v7->mValue.mStatValueInt = UFG::PersistentData::MapInt::GetStatus(v15, v5);
        }
        else
        {
          if ( v7->mStatType == StatType_Number )
            v7->mStatType = 2;
          v13 = UFG::GameStatTracker::Instance();
          v7->mValue.mStatValueFloat = UFG::GameStatTracker::GetStat(v13, v9);
        }
      }
      else
      {
        if ( v7->mStatType == StatType_Number )
          v7->mStatType = 1;
        v12 = UFG::GameStatTracker::Instance();
        v7->mValue.mStatValueInt = UFG::GameStatTracker::GetStat(v12, v8);
      }
      return;
    case 4u:
      v17 = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(statName, 0);
      v18 = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(v6, 0);
      v19 = v18;
      if ( v17 == 7 )
      {
        if ( v18 == 93 )
        {
          v16 = "FIX ME NUM LIMIT";
          goto LABEL_33;
        }
        v25 = UFG::GameStatTracker::Instance();
        v26 = UFG::GameStatTracker::GetMapBool(v25, v19);
        v27 = UFG::PersistentData::MapBool::GetTrueCount(v26);
        v28 = UFG::GameStatTracker::Instance();
        v29 = UFG::GameStatTracker::GetMapBool(v28, v19);
        v30 = UFG::PersistentData::MapBool::GetCount(v29);
        v31 = UFG::qString::FormatEx(&v44, "%d / %d", v27, v30, -2i64);
        UFG::UIHKStatItem::SetString(v7, v31);
        UFG::qString::~qString(&v44);
      }
      else
      {
        v20 = UFG::GameStatTracker::Instance();
        v21 = UFG::GameStatTracker::GetStat(v20, v17);
        v22 = UFG::GameStatTracker::Instance();
        v23 = UFG::GameStatTracker::GetStatRange(v22, v17);
        v24 = UFG::qString::FormatEx(&result, "%d / %d", v21, v23, -2i64);
        UFG::UIHKStatItem::SetString(v7, v24);
        UFG::qString::~qString(&result);
      }
      return;
    case 6u:
      v32 = (unsigned int)UFG::GameStat::GetTimeStatEnum(statName, 0);
      v33 = (unsigned int)UFG::GameStat::GetFloatStatEnum(v6, 0);
      v34 = (unsigned int)UFG::GameStat::GetMapFloatStatEnum(v6, 0);
      v35 = v34;
      if ( v32 == 30 )
      {
        if ( v33 == 139 )
        {
          if ( v34 == 18 )
          {
LABEL_29:
            v16 = "FIX ME TIME";
            goto LABEL_33;
          }
          v39 = UFG::GameStatTracker::Instance();
          a5 = UFG::GameStatTracker::GetStat(v39, v35, &v7->mStatKey);
        }
        else
        {
          v38 = UFG::GameStatTracker::Instance();
          a5 = UFG::GameStatTracker::GetStat(v38, v33);
        }
      }
      else
      {
        v36 = UFG::GameStatTracker::Instance();
        v37 = UFG::GameStatTracker::GetTimeStat(v36, v32);
        UFG::PersistentData::Time::GetTotalTime(v37);
      }
      if ( a5 == -1.0 )
        goto LABEL_29;
      v40 = UFG::UIGfxTranslator::getLocalizedTime(
              UFG::UIScreenManager::s_instance->m_translator,
              &v45,
              a5 * 1000.0,
              eTS_SECONDS);
      UFG::UIHKStatItem::SetString(v7, v40);
      UFG::qString::~qString(&v45);
      return;
    case 8u:
      v41 = (unsigned int)UFG::GameStat::GetStringStatEnum(statName, 0);
      if ( v41 == 25 )
      {
        v16 = "FIX ME STRING";
LABEL_33:
        v7->mValue.mStatValueStr = v16;
      }
      else
      {
        v42 = UFG::GameStatTracker::Instance();
        v7->mValue.mStatValueStr = UFG::GameStatTracker::GetStat(v42, v41)->mData;
      }
      return;
    default:
      return;
  }
}

// File Line: 261
// RVA: 0x5F0E40
UFG::UIHKScreenStats::LoadStatItems

// File Line: 315
// RVA: 0x6106B0
void __fastcall UFG::UIHKScreenStats::ShowHelpBarWidget(UFG::UIHKScreenStats *this)
{
  UFG::UIHKHelpBarWidget *v1; // rbp
  unsigned int v2; // esi
  unsigned int v3; // edi
  unsigned int v4; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-258h]

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v1 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v2 = UI_HASH_BUTTON_BACK_PRESSED_30;
    v3 = UI_HASH_BUTTON_R1_PRESSED_30;
    v4 = UFG::qStringHash32("STATS", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v4;
    *(_QWORD *)&data.priority = 0i64;
    _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$HELPBAR_CHANGE_SECTION_UC");
    UFG::qString::Set(&data.Captions[1], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set(&data.Captions[2], &customWorldMapCaption);
    UFG::qString::Set(&data.Captions[3], &customWorldMapCaption);
    UFG::qString::Set(&data.Captions[4], &customWorldMapCaption);
    UFG::qString::Set(&data.Captions[5], &customWorldMapCaption);
    data.MessageIds[0] = v3;
    data.MessageIds[1] = v2;
    *(_QWORD *)&data.MessageIds[2] = 0i64;
    *(_QWORD *)&data.MessageIds[4] = 0i64;
    UFG::UIHKHelpBarWidget::Show(v1, &data);
    UFG::qString::~qString(&data.CustomTexturePack);
    `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
}

// File Line: 346
// RVA: 0x5C7800
void __fastcall UFG::UIHKScreenStats::UIHKScreenStats(UFG::UIHKScreenStats *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax
  UFG::qList<UFG::UIHKStatItem,UFG::UIHKStatItem,1,0> *v2; // [rsp+48h] [rbp+10h]

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenStats::`vftable;
  this->mPSSetData = 0i64;
  this->mCurrentCategory = 0;
  v2 = &this->mStatItems;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->mDOF);
}

// File Line: 353
// RVA: 0x5CCD50
void __fastcall UFG::UIHKScreenStats::~UIHKScreenStats(UFG::UIHKScreenStats *this)
{
  UFG::UIHKScreenStats *v1; // rdi
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKHelpBarWidget *v3; // rbx
  unsigned int v4; // eax
  UFG::qNode<UFG::UIHKStatItem,UFG::UIHKStatItem> *v5; // rcx
  UFG::qNode<UFG::UIHKStatItem,UFG::UIHKStatItem> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenStats::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Stats");
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v3 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v4 = UFG::qStringHash32("STATS", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v3, v4);
  }
  UFG::GameCameraComponent::EndDOFOverride(0);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->mStatItems);
  v5 = v1->mStatItems.mNode.mPrev;
  v6 = v1->mStatItems.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mStatItems.mNode.mPrev = &v1->mStatItems.mNode;
  v1->mStatItems.mNode.mNext = &v1->mStatItems.mNode;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 360
// RVA: 0x6369B0
void __fastcall UFG::UIHKScreenStats::init(UFG::UIHKScreenStats *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenStats *v2; // rsi
  UFG::UIScreenRenderable *v3; // rax
  Scaleform::GFx::Movie *v4; // r14
  signed int v5; // ebx
  const char *v6; // r8
  char *v7; // rdi
  UFG::qString result; // [rsp+20h] [rbp-11h]
  Scaleform::GFx::Value value; // [rsp+48h] [rbp+17h]

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = v2->mRenderable;
  if ( v3 )
  {
    v4 = v3->m_movie.pObject;
    if ( v4 )
    {
      UFG::GameStatAction::TemporaryData::Update();
      UFG::UIHKScreenStats::LoadStatItems(v2);
      value.pObjectInterface = 0i64;
      value.Type = 5;
      value.mValue.NValue = DOUBLE_5_0;
      Scaleform::GFx::Movie::SetVariable(v4, "gTabMenuWidgetList.NumSlots", &value, 1i64);
      v5 = 0;
      do
      {
        if ( v5 )
        {
          switch ( v5 )
          {
            case 1:
              v6 = "COMPLETION";
              break;
            case 2:
              v6 = "WORLD";
              break;
            case 3:
              v6 = "COMBAT";
              break;
            case 4:
              v6 = "DEBUG_WEAPON";
              break;
            default:
              v6 = "InvalidCategory";
              break;
          }
        }
        else
        {
          v6 = "ALL";
        }
        UFG::qString::FormatEx(&result, "$STATS_TITLE_%s", v6);
        v7 = result.mData;
        if ( ((unsigned int)value.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            *(_QWORD *)&value.mValue.NValue);
          value.pObjectInterface = 0i64;
        }
        value.Type = 6;
        *(_QWORD *)&value.mValue.NValue = v7;
        Scaleform::GFx::Movie::Invoke(v4, "TabMenuWidgetList_AddItem", 0i64, &value, 1u);
        UFG::qString::~qString(&result);
        ++v5;
      }
      while ( v5 < 5 );
      Scaleform::GFx::Movie::Invoke(v4, "TabMenuWidgetList_Refresh", 0i64, 0i64, 0);
      UFG::UIHKScreenStats::ShowHelpBarWidget(v2);
      UFG::UIHKScreenStats::PopulateList(v2, v2->mCurrentCategory);
      if ( ((unsigned int)value.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
    }
  }
}

// File Line: 408
// RVA: 0x5F94B0
void __fastcall UFG::UIHKScreenStats::PopulateList(UFG::UIHKScreenStats *this, int currentCategory)
{
  int v2; // esi
  UFG::UIHKScreenStats *v3; // rbx
  Scaleform::GFx::Movie *v4; // r15
  signed __int64 v5; // rdi
  signed __int64 i; // r14
  __int64 v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  char *v12; // rbx
  UFG::qString v13; // [rsp+30h] [rbp-D0h]
  char ptr; // [rsp+60h] [rbp-A0h]
  __int64 v15; // [rsp+70h] [rbp-90h]
  unsigned int v16; // [rsp+78h] [rbp-88h]
  __int64 v17; // [rsp+80h] [rbp-80h]
  char v18; // [rsp+90h] [rbp-70h]
  __int64 v19; // [rsp+A0h] [rbp-60h]
  unsigned int v20; // [rsp+A8h] [rbp-58h]
  char *v21; // [rsp+B0h] [rbp-50h]
  __int64 v22; // [rsp+C0h] [rbp-40h]
  UFG::qString v23; // [rsp+C8h] [rbp-38h]
  UFG::qString v24; // [rsp+F0h] [rbp-10h]
  UFG::qString v25; // [rsp+118h] [rbp+18h]
  UFG::qString v26; // [rsp+140h] [rbp+40h]

  v22 = -2i64;
  v2 = currentCategory;
  v3 = this;
  v4 = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "StatList_Clear", 0i64, 0i64, 0);
  v5 = (signed __int64)&v3->mStatItems.mNode.mNext[-1].mNext;
  for ( i = (signed __int64)&v3->mCurrentCategory; v5 != i; v5 = *(_QWORD *)(v5 + 16) - 8i64 )
  {
    if ( (!v2 || v2 == *(_DWORD *)(v5 + 108))
      && !UFG::qString::operator==((UFG::qString *)(v5 + 64), "$STATS_TOTAL_STAT_GAMES_PLAYED") )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v7 = *(_QWORD *)(v5 + 88);
      if ( (v16 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, &ptr, v17);
        v15 = 0i64;
      }
      v16 = 6;
      v17 = v7;
      UFG::qString::qString(&v13);
      switch ( *(_DWORD *)(v5 + 112) )
      {
        case 0:
        case 1:
        case 7:
          UFG::qString::qString(&v26, "%d", *(unsigned int *)(v5 + 120));
          UFG::qString::Set(&v13, *(const char **)(v8 + 24), *(_DWORD *)(v8 + 20), 0i64, 0);
          UFG::qString::~qString(&v26);
          break;
        case 2:
          UFG::qString::qString(&v23, "%4.2f", *(float *)(v5 + 120));
          UFG::qString::Set(&v13, *(const char **)(v9 + 24), *(_DWORD *)(v9 + 20), 0i64, 0);
          UFG::qString::~qString(&v23);
          break;
        case 3:
          UFG::qString::qString(&v25, "%4.2f%%", *(float *)(v5 + 120));
          UFG::qString::Set(&v13, *(const char **)(v10 + 24), *(_DWORD *)(v10 + 20), 0i64, 0);
          UFG::qString::~qString(&v25);
          break;
        case 4:
        case 6:
        case 8:
          UFG::qString::Set(&v13, *(const char **)(v5 + 120));
          break;
        case 5:
          UFG::qString::qString(&v24, "%6.2f km", *(float *)(v5 + 120));
          UFG::qString::Set(&v13, *(const char **)(v11 + 24), *(_DWORD *)(v11 + 20), 0i64, 0);
          UFG::qString::~qString(&v24);
          break;
        default:
          break;
      }
      v12 = v13.mData;
      if ( (v20 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
        v19 = 0i64;
      }
      v20 = 6;
      v21 = v12;
      Scaleform::GFx::Movie::Invoke(v4, "StatList_AddItem", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
      UFG::qString::~qString(&v13);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
  Scaleform::GFx::Movie::Invoke(v4, "Stats_Refresh", 0i64, 0i64, 0);
}

// File Line: 472
// RVA: 0x5DF0C0
void __fastcall UFG::UIHKScreenStats::Flash_ScrollUp(UFG::UIHKScreenStats *this)
{
  Scaleform::GFx::Movie *v1; // rbx

  v1 = this->mRenderable->m_movie.pObject;
  if ( v1 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x593B70ABu,
        0i64,
        0,
        0i64);
    Scaleform::GFx::Movie::Invoke(v1, "Stats_ScrollUp", 0i64, 0i64, 0);
  }
}

// File Line: 483
// RVA: 0x5DEF20
void __fastcall UFG::UIHKScreenStats::Flash_ScrollDown(UFG::UIHKScreenStats *this)
{
  Scaleform::GFx::Movie *v1; // rbx

  v1 = this->mRenderable->m_movie.pObject;
  if ( v1 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xB78DCE8u,
        0i64,
        0,
        0i64);
    Scaleform::GFx::Movie::Invoke(v1, "Stats_ScrollDown", 0i64, 0i64, 0);
  }
}

// File Line: 518
// RVA: 0x62D0E0
bool __fastcall UFG::UIHKScreenStats::handleMessage(UFG::UIHKScreenStats *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbp
  unsigned int v4; // ebx
  Scaleform::GFx::Movie *v5; // r14
  UFG::UIHKScreenStats *v6; // rdi
  bool result; // al
  const char *v8; // rdx
  bool v9; // sf
  UFG::UIScreen *v10; // rax
  UFG::UIHKScreenGlobalOverlay *v11; // rcx

  v3 = msg;
  v4 = msgId;
  v5 = this->mRenderable->m_movie.pObject;
  v6 = this;
  if ( !v5 )
    return 0;
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
    || msgId == UI_HASH_DPAD_DOWN_REPEAT_30 )
  {
    if ( v5 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xB78DCE8u,
          0i64,
          0,
          0i64);
      Scaleform::GFx::Movie::Invoke(v5, "Stats_ScrollDown", 0i64, 0i64, 0);
    }
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30
    || msgId == UI_HASH_DPAD_UP_REPEAT_30 )
  {
    goto LABEL_11;
  }
  if ( msgId == UI_HASH_MOUSE_WHEEL_SCROLL_30 )
  {
    if ( SLODWORD(msg[1].mPrev) <= 0 )
    {
      UFG::UIHKScreenStats::Flash_ScrollDown(this);
      return 1;
    }
LABEL_11:
    UFG::UIHKScreenStats::Flash_ScrollUp(this);
    return 1;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xA4E5BFBD,
        0i64,
        0,
        0i64);
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
    return 1;
  }
  if ( msgId == UI_HASH_BUTTON_R1_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
    v8 = "TabMenuWidgetList_ScrollNext";
    v6->mCurrentCategory = (v6->mCurrentCategory + 1) % 5;
  }
  else
  {
    if ( msgId != UI_HASH_BUTTON_L1_PRESSED_30 )
      goto LABEL_28;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
    v9 = v6->mCurrentCategory-- - 1 < 0;
    if ( v9 )
      v6->mCurrentCategory += 5;
    v8 = "TabMenuWidgetList_ScrollPrev";
  }
  Scaleform::GFx::Movie::Invoke(v5, v8, 0i64, 0i64, 0);
  Scaleform::GFx::Movie::Invoke(v5, "TabMenuWidgetList_UpdateSpacing", 0i64, 0i64, 0);
  UFG::UIHKScreenStats::PopulateList(v6, v6->mCurrentCategory);
LABEL_28:
  v10 = UFG::UIScreenManagerBase::getOverlay(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "GlobalOverlay");
  if ( v10 )
  {
    v11 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v11 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::HandleMessage(&v11->HelpBar, v10, v4, v3);
    result = UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v4, v3);
  }
  else if ( v4 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
  {
    UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
      (UFG::UIHKScreenUpgrades *)v6,
      (float)SLODWORD(v3[1].vfptr),
      (float)SHIDWORD(v3[1].vfptr));
    result = UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v4, v3);
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
      v6->mCurrentCategory = UFG::UI::GetFlashArgsInt(v3);
      Scaleform::GFx::Movie::Invoke(v5, "TabMenuWidgetList_UpdateSpacing", 0i64, 0i64, 0);
      UFG::UIHKScreenStats::PopulateList(v6, v6->mCurrentCategory);
    }
    result = UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v4, v3);
  }
  return result;
}

