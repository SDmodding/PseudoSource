// File Line: 43
// RVA: 0x1569E70
__int64 UFG::_dynamic_initializer_for__UIStatSymbol_category__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("category", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UIStatSymbol_category, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__UIStatSymbol_category__);
}

// File Line: 67
// RVA: 0x5E9490
__int64 __fastcall UFG::UIHKStatItem::GetStatCategoryEnum(const char *str)
{
  unsigned int v2; // ebx
  const char *v3; // rdx

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
    if ( UFG::qStringFind(str, v3) )
      break;
    if ( (int)++v2 >= 5 )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

// File Line: 119
// RVA: 0x608D00
void __fastcall UFG::UIHKScreenStats::SetStatValue(
        UFG::UIHKScreenStats *this,
        UFG::UIHKStatItem *item,
        UFG::qSymbol *statName,
        UFG::qSymbol *statNameIndex)
{
  UFG::GameStat::Int32Stat Int32StatEnum; // r14d
  UFG::GameStat::FloatStat FloatStatEnum; // ebp
  UFG::GameStat::MapInt32Stat MapInt32StatEnum; // eax
  UFG::GameStat::MapInt32Stat v10; // ebx
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rax
  UFG::GameStatTracker *v13; // rax
  UFG::PersistentData::MapInt *MapInt; // rax
  const char *v15; // rax
  UFG::GameStat::Int32RangedStat Int32RangedStatEnum; // esi
  UFG::GameStat::MapBoolStat MapBoolStatEnum; // eax
  UFG::GameStat::MapBoolStat v18; // ebp
  UFG::GameStatTracker *v19; // rax
  unsigned int Stat; // ebx
  UFG::GameStatTracker *v21; // rax
  unsigned int StatRange; // eax
  UFG::qString *v23; // rax
  UFG::GameStatTracker *v24; // rax
  UFG::PersistentData::MapBool *MapBool; // rax
  unsigned int TrueCount; // ebx
  UFG::GameStatTracker *v27; // rax
  UFG::PersistentData::MapBool *v28; // rax
  unsigned int Count; // eax
  UFG::qString *v30; // rax
  UFG::GameStat::TimeStat TimeStatEnum; // r14d
  UFG::GameStat::FloatStat v32; // esi
  UFG::GameStat::MapFloatStat MapFloatStatEnum; // eax
  UFG::GameStat::MapFloatStat v34; // ebp
  UFG::GameStatTracker *v35; // rax
  UFG::GameSnapshot *TimeStat; // rax
  double TotalTime; // xmm0_8
  UFG::GameStatTracker *v38; // rax
  UFG::GameStatTracker *v39; // rax
  UFG::qString *LocalizedTime; // rax
  UFG::GameStat::StringStat StringStatEnum; // ebx
  UFG::GameStatTracker *v42; // rax
  UFG::qString result; // [rsp+28h] [rbp-80h] BYREF
  UFG::qString v44; // [rsp+50h] [rbp-58h] BYREF
  UFG::qString v45; // [rsp+78h] [rbp-30h] BYREF

  switch ( item->mStatType )
  {
    case StatType_Number:
    case StatType_Percentage:
    case StatType_Distance:
    case StatType_Money:
      Int32StatEnum = (unsigned int)UFG::GameStat::GetInt32StatEnum(statName, 0);
      FloatStatEnum = (unsigned int)UFG::GameStat::GetFloatStatEnum(statName, 0);
      MapInt32StatEnum = (unsigned int)UFG::GameStat::GetMapInt32StatEnum(statName, 0);
      v10 = MapInt32StatEnum;
      if ( Int32StatEnum == Num_Int32_Stats )
      {
        if ( FloatStatEnum == Num_Float_Stats )
        {
          if ( !statNameIndex || MapInt32StatEnum == Num_MapInt32_Stats )
          {
            item->mStatType = StatType_String;
            v15 = "FIX ME NUMBER";
            goto LABEL_33;
          }
          if ( item->mStatType == StatType_Number )
            item->mStatType = StatType_Int;
          v13 = UFG::GameStatTracker::Instance();
          MapInt = UFG::GameStatTracker::GetMapInt(v13, v10);
          item->mValue.mStatValueInt = UFG::PersistentData::MapInt::GetStatus(MapInt, statNameIndex);
        }
        else
        {
          if ( item->mStatType == StatType_Number )
            item->mStatType = StatType_Float;
          v12 = UFG::GameStatTracker::Instance();
          item->mValue.mStatValueFloat = UFG::GameStatTracker::GetStat(v12, FloatStatEnum);
        }
      }
      else
      {
        if ( item->mStatType == StatType_Number )
          item->mStatType = StatType_Int;
        v11 = UFG::GameStatTracker::Instance();
        item->mValue.mStatValueInt = UFG::GameStatTracker::GetStat(v11, Int32StatEnum);
      }
      return;
    case StatType_NumberLimit:
      Int32RangedStatEnum = (unsigned int)UFG::GameStat::GetInt32RangedStatEnum(statName, 0);
      MapBoolStatEnum = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(statName, 0);
      v18 = MapBoolStatEnum;
      if ( Int32RangedStatEnum == Num_Int32Ranged_Stats )
      {
        if ( MapBoolStatEnum == Num_MapBool_Stats )
        {
          v15 = "FIX ME NUM LIMIT";
          goto LABEL_33;
        }
        v24 = UFG::GameStatTracker::Instance();
        MapBool = UFG::GameStatTracker::GetMapBool(v24, v18);
        TrueCount = UFG::PersistentData::MapBool::GetTrueCount(MapBool);
        v27 = UFG::GameStatTracker::Instance();
        v28 = UFG::GameStatTracker::GetMapBool(v27, v18);
        Count = UFG::PersistentData::MapBool::GetCount(v28);
        v30 = UFG::qString::FormatEx(&v44, "%d / %d", TrueCount, Count);
        UFG::UIHKStatItem::SetString(item, v30);
        UFG::qString::~qString(&v44);
      }
      else
      {
        v19 = UFG::GameStatTracker::Instance();
        Stat = UFG::GameStatTracker::GetStat(v19, Int32RangedStatEnum);
        v21 = UFG::GameStatTracker::Instance();
        StatRange = UFG::GameStatTracker::GetStatRange(v21, Int32RangedStatEnum);
        v23 = UFG::qString::FormatEx(&result, "%d / %d", Stat, StatRange);
        UFG::UIHKStatItem::SetString(item, v23);
        UFG::qString::~qString(&result);
      }
      return;
    case StatType_Time:
      TimeStatEnum = (unsigned int)UFG::GameStat::GetTimeStatEnum(statName, 0);
      v32 = (unsigned int)UFG::GameStat::GetFloatStatEnum(statName, 0);
      MapFloatStatEnum = (unsigned int)UFG::GameStat::GetMapFloatStatEnum(statName, 0);
      v34 = MapFloatStatEnum;
      if ( TimeStatEnum == Num_Time_Stats )
      {
        if ( v32 == Num_Float_Stats )
        {
          if ( MapFloatStatEnum == Num_MapFloat_Stats )
          {
LABEL_29:
            v15 = "FIX ME TIME";
            goto LABEL_33;
          }
          v39 = UFG::GameStatTracker::Instance();
          *(float *)&TotalTime = UFG::GameStatTracker::GetStat(v39, v34, &item->mStatKey);
        }
        else
        {
          v38 = UFG::GameStatTracker::Instance();
          *(float *)&TotalTime = UFG::GameStatTracker::GetStat(v38, v32);
        }
      }
      else
      {
        v35 = UFG::GameStatTracker::Instance();
        TimeStat = UFG::GameStatTracker::GetTimeStat(v35, TimeStatEnum);
        TotalTime = UFG::PersistentData::Time::GetTotalTime(TimeStat->mTimes);
      }
      if ( *(float *)&TotalTime == -1.0 )
        goto LABEL_29;
      LocalizedTime = UFG::UIGfxTranslator::getLocalizedTime(
                        UFG::UIScreenManager::s_instance->m_translator,
                        &v45,
                        *(float *)&TotalTime * 1000.0,
                        eTS_SECONDS);
      UFG::UIHKStatItem::SetString(item, LocalizedTime);
      UFG::qString::~qString(&v45);
      return;
    case StatType_String:
      StringStatEnum = (unsigned int)UFG::GameStat::GetStringStatEnum(statName, 0);
      if ( StringStatEnum == Num_String_Stats )
      {
        v15 = "FIX ME STRING";
LABEL_33:
        item->mValue.mStatValueStr = v15;
      }
      else
      {
        v42 = UFG::GameStatTracker::Instance();
        item->mValue.mStatValueStr = UFG::GameStatTracker::GetStat(v42, StringStatEnum)->mValue.mData;
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
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbp
  unsigned int v2; // esi
  unsigned int v3; // edi
  unsigned int v4; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-258h] BYREF

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v2 = UI_HASH_BUTTON_BACK_PRESSED_30;
    v3 = UI_HASH_BUTTON_R1_PRESSED_30;
    v4 = UFG::qStringHash32("STATS", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v4;
    *(_QWORD *)&data.priority = 0i64;
    *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$HELPBAR_CHANGE_SECTION_UC");
    UFG::qString::Set(&data.Captions[1], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set(&data.Captions[2], &customCaption);
    UFG::qString::Set(&data.Captions[3], &customCaption);
    UFG::qString::Set(&data.Captions[4], &customCaption);
    UFG::qString::Set(&data.Captions[5], &customCaption);
    data.MessageIds[0] = v3;
    data.MessageIds[1] = v2;
    *(_QWORD *)&data.MessageIds[2] = 0i64;
    *(_QWORD *)&data.MessageIds[4] = 0i64;
    UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
    UFG::qString::~qString(&data.CustomTexturePack);
    `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
}

// File Line: 346
// RVA: 0x5C7800
void __fastcall UFG::UIHKScreenStats::UIHKScreenStats(UFG::UIHKScreenStats *this)
{
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenStats::`vftable;
  this->mPSSetData = 0i64;
  this->mCurrentCategory = 0;
  this->mStatItems.mNode.mPrev = &this->mStatItems.mNode;
  this->mStatItems.mNode.mNext = &this->mStatItems.mNode;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->mDOF);
}

// File Line: 353
// RVA: 0x5CCD50
void __fastcall UFG::UIHKScreenStats::~UIHKScreenStats(UFG::UIHKScreenStats *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v4; // eax
  UFG::qNode<UFG::UIHKStatItem,UFG::UIHKStatItem> *mPrev; // rcx
  UFG::qNode<UFG::UIHKStatItem,UFG::UIHKStatItem> *mNext; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenStats::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Stats");
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v4 = UFG::qStringHash32("STATS", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v4);
  }
  UFG::GameCameraComponent::EndDOFOverride(DOFOverridePriority_0);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->mStatItems);
  mPrev = this->mStatItems.mNode.mPrev;
  mNext = this->mStatItems.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mStatItems.mNode.mPrev = &this->mStatItems.mNode;
  this->mStatItems.mNode.mNext = &this->mStatItems.mNode;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 360
// RVA: 0x6369B0
// positive sp value has been detected, the output may be wrong!
void __fastcall UFG::UIHKScreenStats::init(UFG::UIHKScreenStats *this, UFG::UICommandData *data)
{
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // r14
  int i; // ebx
  const char *v6; // r8
  char *mData; // rdi
  UFG::qString result; // [rsp+20h] [rbp-11h] BYREF
  Scaleform::GFx::Value value; // [rsp+48h] [rbp+17h] BYREF

  UFG::UIScreen::init(this, data);
  mRenderable = this->mRenderable;
  if ( mRenderable )
  {
    pObject = mRenderable->m_movie.pObject;
    if ( pObject )
    {
      UFG::GameStatAction::TemporaryData::Update();
      UFG::UIHKScreenStats::LoadStatItems(this);
      value.pObjectInterface = 0i64;
      value.Type = VT_Number;
      value.mValue.NValue = DOUBLE_5_0;
      Scaleform::GFx::Movie::SetVariable(pObject, "gTabMenuWidgetList.NumSlots", &value, 1i64);
      for ( i = 0; i < 5; ++i )
      {
        if ( i )
        {
          switch ( i )
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
        mData = result.mData;
        if ( (value.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            value.mValue);
          value.pObjectInterface = 0i64;
        }
        value.Type = VT_String;
        value.mValue.pString = mData;
        Scaleform::GFx::Movie::Invoke(pObject, "TabMenuWidgetList_AddItem", 0i64, &value, 1u);
        UFG::qString::~qString(&result);
      }
      Scaleform::GFx::Movie::Invoke(pObject, "TabMenuWidgetList_Refresh", 0i64, 0i64, 0);
      UFG::UIHKScreenStats::ShowHelpBarWidget(this);
      UFG::UIHKScreenStats::PopulateList(this, this->mCurrentCategory);
      if ( (value.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
    }
  }
}

// File Line: 408
// RVA: 0x5F94B0
void __fastcall UFG::UIHKScreenStats::PopulateList(UFG::UIHKScreenStats *this, int currentCategory)
{
  Scaleform::GFx::Movie *pObject; // r15
  int *p_mNext; // rdi
  int *i; // r14
  Scaleform::GFx::Value::ValueUnion v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  char *mData; // rbx
  UFG::qString v13; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-A0h] BYREF
  char v15[6]; // [rsp+90h] [rbp-70h] BYREF
  __int64 v16; // [rsp+A0h] [rbp-60h]
  int v17; // [rsp+A8h] [rbp-58h]
  char *v18; // [rsp+B0h] [rbp-50h]
  __int64 v19; // [rsp+C0h] [rbp-40h]
  UFG::qString v20; // [rsp+C8h] [rbp-38h] BYREF
  UFG::qString v21; // [rsp+F0h] [rbp-10h] BYREF
  UFG::qString v22; // [rsp+118h] [rbp+18h] BYREF
  UFG::qString v23; // [rsp+140h] [rbp+40h] BYREF

  v19 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::Invoke(pObject, "StatList_Clear", 0i64, 0i64, 0);
  p_mNext = (int *)&this->mStatItems.mNode.mNext[-1].mNext;
  for ( i = &this->mCurrentCategory; p_mNext != i; p_mNext = (int *)(*((_QWORD *)p_mNext + 2) - 8i64) )
  {
    if ( (!currentCategory || currentCategory == p_mNext[27])
      && !UFG::qString::operator==((UFG::qString *)(p_mNext + 16), "$STATS_TOTAL_STAT_GAMES_PLAYED") )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v7 = *(Scaleform::GFx::Value::ValueUnion *)(p_mNext + 22);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.mValue = v7;
      UFG::qString::qString(&v13);
      switch ( p_mNext[28] )
      {
        case 0:
        case 1:
        case 7:
          UFG::qString::qString(&v23, "%d", (unsigned int)p_mNext[30]);
          UFG::qString::Set(&v13, *(const char **)(v8 + 24), *(_DWORD *)(v8 + 20), 0i64, 0);
          UFG::qString::~qString(&v23);
          break;
        case 2:
          UFG::qString::qString(&v20, "%4.2f", *((float *)p_mNext + 30));
          UFG::qString::Set(&v13, *(const char **)(v9 + 24), *(_DWORD *)(v9 + 20), 0i64, 0);
          UFG::qString::~qString(&v20);
          break;
        case 3:
          UFG::qString::qString(&v22, "%4.2f%%", *((float *)p_mNext + 30));
          UFG::qString::Set(&v13, *(const char **)(v10 + 24), *(_DWORD *)(v10 + 20), 0i64, 0);
          UFG::qString::~qString(&v22);
          break;
        case 4:
        case 6:
        case 8:
          UFG::qString::Set(&v13, *((const char **)p_mNext + 15));
          break;
        case 5:
          UFG::qString::qString(&v21, "%6.2f km", *((float *)p_mNext + 30));
          UFG::qString::Set(&v13, *(const char **)(v11 + 24), *(_DWORD *)(v11 + 20), 0i64, 0);
          UFG::qString::~qString(&v21);
          break;
        default:
          break;
      }
      mData = v13.mData;
      if ( (v17 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
        v16 = 0i64;
      }
      v17 = 6;
      v18 = mData;
      Scaleform::GFx::Movie::Invoke(pObject, "StatList_AddItem", 0i64, &ptr, 2u);
      UFG::qString::~qString(&v13);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
  Scaleform::GFx::Movie::Invoke(pObject, "Stats_Refresh", 0i64, 0i64, 0);
}

// File Line: 472
// RVA: 0x5DF0C0
void __fastcall UFG::UIHKScreenStats::Flash_ScrollUp(UFG::UIHKScreenStats *this)
{
  Scaleform::GFx::Movie *pObject; // rbx

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x593B70ABu, 0i64, 0, 0i64);
    Scaleform::GFx::Movie::Invoke(pObject, "Stats_ScrollUp", 0i64, 0i64, 0);
  }
}

// File Line: 483
// RVA: 0x5DEF20
void __fastcall UFG::UIHKScreenStats::Flash_ScrollDown(UFG::UIHKScreenStats *this)
{
  Scaleform::GFx::Movie *pObject; // rbx

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xB78DCE8u, 0i64, 0, 0i64);
    Scaleform::GFx::Movie::Invoke(pObject, "Stats_ScrollDown", 0i64, 0i64, 0);
  }
}

// File Line: 518
// RVA: 0x62D0E0
bool __fastcall UFG::UIHKScreenStats::handleMessage(
        UFG::UIHKScreenStats *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // r14
  const char *v8; // rdx
  UFG::UIScreen *Overlay; // rax
  UFG::UIHKScreenGlobalOverlay *v11; // rcx

  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return 0;
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
    || msgId == UI_HASH_DPAD_DOWN_REPEAT_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xB78DCE8u, 0i64, 0, 0i64);
    Scaleform::GFx::Movie::Invoke(pObject, "Stats_ScrollDown", 0i64, 0i64, 0);
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
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    return 1;
  }
  if ( msgId == UI_HASH_BUTTON_R1_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
    v8 = "TabMenuWidgetList_ScrollNext";
    this->mCurrentCategory = (this->mCurrentCategory + 1) % 5;
  }
  else
  {
    if ( msgId != UI_HASH_BUTTON_L1_PRESSED_30 )
      goto LABEL_28;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
    if ( --this->mCurrentCategory < 0 )
      this->mCurrentCategory += 5;
    v8 = "TabMenuWidgetList_ScrollPrev";
  }
  Scaleform::GFx::Movie::Invoke(pObject, v8, 0i64, 0i64, 0);
  Scaleform::GFx::Movie::Invoke(pObject, "TabMenuWidgetList_UpdateSpacing", 0i64, 0i64, 0);
  UFG::UIHKScreenStats::PopulateList(this, this->mCurrentCategory);
LABEL_28:
  Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "GlobalOverlay");
  if ( Overlay )
  {
    v11 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v11 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::HandleMessage(&v11->HelpBar, Overlay, msgId, msg);
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
      this->mCurrentCategory = UFG::UI::GetFlashArgsInt(msg);
      Scaleform::GFx::Movie::Invoke(pObject, "TabMenuWidgetList_UpdateSpacing", 0i64, 0i64, 0);
      UFG::UIHKScreenStats::PopulateList(this, this->mCurrentCategory);
    }
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
}

