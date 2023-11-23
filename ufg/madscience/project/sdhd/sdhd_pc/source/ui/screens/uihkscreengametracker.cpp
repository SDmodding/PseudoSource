// File Line: 47
// RVA: 0x156C250
__int64 UFG::_dynamic_initializer_for__UI_HASH_MOUSE_SELECT_SLOT_GT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("MOUSE_SELECT_SLOT_GT", -1);
  UI_HASH_MOUSE_SELECT_SLOT_GT = result;
  return result;
}

// File Line: 51
// RVA: 0x5F19D0
void __fastcall UFG::UIHKScreenGameTracker::LoadTextures(
        UFG::qReflectInventoryBase *callback,
        UFG::qReflectInventoryBase *callbackParam)
{
  UFG::UIScreenTextureManager *v4; // rax
  UFG::UIScreenTextureManager *v5; // rax

  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v4,
    UFG::UIHKScreenGameTracker::gTexturePackFilename,
    HIGH_PRIORITY,
    callback,
    callbackParam);
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v5,
    UFG::UIHKScreenStats::gTexturePackFilename,
    HIGH_PRIORITY,
    callback,
    callbackParam);
}

// File Line: 56
// RVA: 0x5D4080
__int64 __fastcall UFG::UIHKScreenGameTracker::AreTexturesLoaded()
{
  UFG::UIScreenTextureManager *v0; // rax
  bool IsTexturePackLoaded; // bl
  UFG::UIScreenTextureManager *v2; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  IsTexturePackLoaded = UFG::UIScreenTextureManager::IsTexturePackLoaded(
                          v0,
                          UFG::UIHKScreenGameTracker::gTexturePackFilename);
  v2 = UFG::UIScreenTextureManager::Instance();
  return IsTexturePackLoaded & (unsigned __int8)UFG::UIScreenTextureManager::IsTexturePackLoaded(
                                                  v2,
                                                  UFG::UIHKScreenStats::gTexturePackFilename);
}

// File Line: 63
// RVA: 0x600D40
void UFG::UIHKScreenGameTracker::ReleaseTextures(void)
{
  UFG::UIScreenTextureManager *v0; // rax
  UFG::UIScreenTextureManager *v1; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v0, UFG::UIHKScreenGameTracker::gTexturePackFilename);
  v1 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v1, UFG::UIHKScreenStats::gTexturePackFilename);
}

// File Line: 73
// RVA: 0x5C53B0
void __fastcall UFG::UIHKScreenGameTracker::UIHKScreenGameTracker(UFG::UIHKScreenGameTracker *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGameTracker::`vftable;
  UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "ITEMS");
  this->m_eCurrentPage = PAGE_START_COLLECTIBLES;
  UFG::UIHKScreenGameTracker::m_iRowCollectedCount = 0;
  UFG::UIHKScreenGameTracker::m_iRowCount = 0;
  UFG::UIHKScreenGameTracker::mMovie = 0i64;
  this->m_iPercentageCollected = 0;
}

// File Line: 96
// RVA: 0x631B00
void __fastcall UFG::UIHKScreenGameTracker::init(UFG::UIHKScreenGameTracker *this, UFG::UICommandData *data)
{
  UFG::UIScreenRenderable *mRenderable; // rax

  UFG::UIScreen::init(this, data);
  mRenderable = this->mRenderable;
  if ( mRenderable )
  {
    UFG::UIHKScreenGameTracker::mMovie = mRenderable->m_movie.pObject;
    if ( UFG::UIHKScreenGameTracker::mMovie )
    {
      if ( UFG::UIHKScreenGameTracker::m_eMode )
      {
        if ( UFG::UIHKScreenGameTracker::m_eMode == GT_MODE_ASSETS )
        {
          this->m_eCurrentPage = PAGE_START_ASSETS;
        }
        else if ( UFG::UIHKScreenGameTracker::m_eMode == GT_MODE_UPGRADES )
        {
          this->m_eCurrentPage = PAGE_START_UPGRADES;
        }
      }
      else
      {
        this->m_eCurrentPage = PAGE_START_COLLECTIBLES;
      }
      UFG::UIHKScreenGameTracker::PopulatePageTabs(this);
      UFG::UIHKScreenGameTracker::PopulatePage(this);
      UFG::UIHKScreenGameTracker::ShowHelpBar(this);
    }
  }
}

// File Line: 132
// RVA: 0x5FA070
void __fastcall UFG::UIHKScreenGameTracker::PopulatePageTabs(UFG::UIHKScreenGameTracker *this)
{
  __int64 v1; // r12
  __int64 v2; // r13
  __int64 v3; // r14
  __int64 v4; // r15
  int v5; // ebx
  int v6; // edi
  const char *v7; // rax
  const char *v8; // rax
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-38h] BYREF
  _QWORD vars0[5]; // [rsp+70h] [rbp+0h] BYREF

  vars0[4] = vars0;
  vars0[3] = v1;
  vars0[2] = v2;
  vars0[1] = v3;
  vars0[0] = v4;
  v5 = 0;
  v6 = 3;
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Undefined;
  if ( UFG::UIHKScreenGameTracker::m_eMode == GT_MODE_COLLECTIBLES )
  {
    v5 = 0;
    v7 = "$GAMETRACKER_COLLECTIBLES";
LABEL_7:
    pargs.Type = VT_String;
    goto LABEL_8;
  }
  if ( UFG::UIHKScreenGameTracker::m_eMode != GT_MODE_ASSETS )
  {
    if ( UFG::UIHKScreenGameTracker::m_eMode != GT_MODE_UPGRADES )
      goto LABEL_9;
    v5 = 7;
    v6 = 10;
    v7 = "$GAMETRACKER_UPGRADES";
    goto LABEL_7;
  }
  v5 = 4;
  v6 = 6;
  pargs.Type = VT_String;
  v7 = "$GAMETRACKER_ASSETS";
LABEL_8:
  pargs.mValue.pString = v7;
LABEL_9:
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "SetPageHeading", 0i64, &pargs, 1u);
  for ( ; v5 <= v6; ++v5 )
  {
    switch ( v5 )
    {
      case 0:
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.mValue.pString = "$GAMETRACKER_ALL_COLLECTIBLES";
        goto LABEL_45;
      case 1:
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.mValue.pString = "$GAMETRACKER_HEALTH_SHRINES";
        goto LABEL_45;
      case 2:
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.mValue.pString = "$GAMETRACKER_SPY_CAMERAS";
        goto LABEL_45;
      case 3:
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_LOCKBOXES";
        goto LABEL_44;
      case 4:
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_ALL_ASSERTS";
        goto LABEL_44;
      case 5:
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_VEHICLES";
        goto LABEL_44;
      case 6:
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_OUTFITS";
        goto LABEL_44;
      case 7:
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_ALL_UPGRADES";
        goto LABEL_44;
      case 8:
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_OFFENSIVE_MOVES";
        goto LABEL_44;
      case 9:
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_DEFENSIVE_MOVES";
        goto LABEL_44;
      case 10:
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_SHOOTING_MOVES";
LABEL_44:
        pargs.mValue.pString = v8;
LABEL_45:
        pargs.Type = VT_String;
        break;
      default:
        break;
    }
    Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "TabMenuWidgetList_AddItem", 0i64, &pargs, 1u);
  }
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "TabMenuWidgetList_Refresh", 0i64, 0i64, 0);
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 225
// RVA: 0x5F9FB0
void __fastcall UFG::UIHKScreenGameTracker::PopulatePage(UFG::UIHKScreenGameTracker *this)
{
  unsigned int m_eCurrentPage; // ecx
  UFG::UIHKScreenGameTracker::eGameTrackerPage v3; // ecx

  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "StatList.Clear", 0i64, 0i64);
  UFG::UIHKScreenGameTracker::m_iRowCollectedCount = 0;
  UFG::UIHKScreenGameTracker::m_iRowCount = 0;
  m_eCurrentPage = this->m_eCurrentPage;
  if ( m_eCurrentPage <= 3 )
    UFG::UIHKScreenGameTracker::PopulateCollectibles(m_eCurrentPage);
  if ( (unsigned int)(this->m_eCurrentPage - 4) <= 1 )
    UFG::UIHKScreenGameTracker::PopulateVehicles();
  if ( ((this->m_eCurrentPage - 4) & 0xFFFFFFFD) == 0 )
    UFG::UIHKScreenGameTracker::PopulateClothing();
  v3 = this->m_eCurrentPage;
  if ( (unsigned int)(v3 - 7) <= 3 )
    UFG::UIHKScreenGameTracker::PopulatePlayerMoves(v3);
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "Stats_Refresh", 0i64, 0i64);
  UFG::UIHKScreenGameTracker::UpdatePageTotal(this);
  UFG::UIHKScreenGameTracker::SetPageIcon(this, this->m_eCurrentPage);
  UFG::UIHKScreenGameTracker::SetPageInfoText(this, this->m_eCurrentPage);
}

// File Line: 269
// RVA: 0x606B90
void __fastcall UFG::UIHKScreenGameTracker::SetPageInfoText(
        UFG::UIHKScreenGameTracker *this,
        UFG::UIHKScreenGameTracker::eGameTrackerPage ePage)
{
  const char *v3; // rdx
  UFG::qString v4; // [rsp+30h] [rbp-1h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+58h] [rbp+27h] BYREF

  UFG::qString::qString((UFG::qString *)&v4.mNext);
  switch ( ePage )
  {
    case PAGE_START_COLLECTIBLES:
    case PAGE_START_ASSETS:
    case PAGE_START_UPGRADES:
      v3 = &customCaption;
      goto LABEL_11;
    case PAGE_COLLECTIBLES_HEALTH_SHRINES:
      v3 = "$GAMETRACKER_DESC_SHRINE";
      goto LABEL_11;
    case PAGE_COLLECTIBLES_SPY_CAMERAS:
      v3 = "$GAMETRACKER_DESC_SPYCAM";
      goto LABEL_11;
    case PAGE_COLLECTIBLES_LOCKBOXES:
      v3 = "$GAMETRACKER_DESC_LOCKBOX";
      goto LABEL_11;
    case PAGE_ASSETS_VEHICLES:
      v3 = "$GAMETRACKER_DESC_VEHICLES";
      goto LABEL_11;
    case PAGE_ASSETS_CLOTHING:
      v3 = "$GAMETRACKER_DESC_OUTFITS";
      goto LABEL_11;
    case PAGE_UPGRADES_OFFENSIVE_MOVES:
      v3 = "$GAMETRACKER_DESC_OFFENSIVE_MOVES";
      goto LABEL_11;
    case PAGE_UPGRADES_DEFENSIVE_MOVES:
      v3 = "$GAMETRACKER_DESC_DEFENSIVE_MOVES";
      goto LABEL_11;
    case PAGE_UPGRADES_SHOOTING_MOVES:
      v3 = "$GAMETRACKER_DESC_SHOOTING_MOVES";
LABEL_11:
      UFG::qString::Set(&v4, v3);
      break;
    default:
      break;
  }
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_String;
  pargs.mValue.pString = v4.mData;
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "SetPageInfoText", 0i64, &pargs, 1u);
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Undefined;
  UFG::qString::~qString(&v4);
}

// File Line: 321
// RVA: 0x6069B0
void __fastcall UFG::UIHKScreenGameTracker::SetPageIcon(
        UFG::UIHKScreenGameTracker *this,
        UFG::UIHKScreenGameTracker::eGameTrackerPage ePage)
{
  const char *v4; // rdx
  Scaleform::GFx::Value::ValueUnion v5; // rbx
  double m_iPercentageCollected; // xmm6_8
  UFG::qString v7; // [rsp+28h] [rbp-61h] BYREF
  Scaleform::GFx::Value v8; // [rsp+60h] [rbp-29h] BYREF
  char v9[16]; // [rsp+90h] [rbp+7h] BYREF
  __int64 v10; // [rsp+A0h] [rbp+17h]
  __int64 v11; // [rsp+A8h] [rbp+1Fh]
  double v12; // [rsp+B0h] [rbp+27h]
  __int64 v13; // [rsp+C0h] [rbp+37h]

  v13 = -2i64;
  UFG::qString::qString((UFG::qString *)&v7.mNext);
  switch ( ePage )
  {
    case PAGE_START_COLLECTIBLES:
      v4 = "ALL_COLLECTIBLES";
      goto LABEL_13;
    case PAGE_COLLECTIBLES_HEALTH_SHRINES:
      v4 = "SHRINE";
      goto LABEL_13;
    case PAGE_COLLECTIBLES_SPY_CAMERAS:
      v4 = "SPYCAM";
      goto LABEL_13;
    case PAGE_COLLECTIBLES_LOCKBOXES:
      v4 = "LOCKBOX";
      goto LABEL_13;
    case PAGE_START_ASSETS:
      v4 = "ALL_ASSETS";
      goto LABEL_13;
    case PAGE_ASSETS_VEHICLES:
      v4 = "VEHICLES";
      goto LABEL_13;
    case PAGE_ASSETS_CLOTHING:
      v4 = "OUTFITS";
      goto LABEL_13;
    case PAGE_START_UPGRADES:
      v4 = "ALL_MOVES";
      goto LABEL_13;
    case PAGE_UPGRADES_OFFENSIVE_MOVES:
      v4 = "OFFENSIVE_MOVES";
      goto LABEL_13;
    case PAGE_UPGRADES_DEFENSIVE_MOVES:
      v4 = "DEFENSIVE_MOVES";
      goto LABEL_13;
    case PAGE_UPGRADES_SHOOTING_MOVES:
      v4 = "SHOOTING_MOVES";
LABEL_13:
      UFG::qString::Set((UFG::qString *)&v7.mNext, v4);
      break;
    default:
      break;
  }
  `eh vector constructor iterator(&v8, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v5 = *(Scaleform::GFx::Value::ValueUnion *)&v7.mStringHash32;
  if ( (v8.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v8.pObjectInterface->vfptr->gap8[8])(
      v8.pObjectInterface,
      &v8,
      v8.mValue);
    v8.pObjectInterface = 0i64;
  }
  v8.Type = VT_String;
  v8.mValue = v5;
  m_iPercentageCollected = (double)this->m_iPercentageCollected;
  if ( (v11 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(v10, v9, COERCE_DOUBLE(*(_QWORD *)&v12));
    v10 = 0i64;
  }
  LODWORD(v11) = 5;
  v12 = m_iPercentageCollected;
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "SetPageIcon", 0i64, &v8, 2u);
  `eh vector destructor iterator(&v8, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString((UFG::qString *)&v7.mNext);
}

// File Line: 376
// RVA: 0x5FA450
void __fastcall UFG::UIHKScreenGameTracker::PopulatePlayerMoves(int ePage)
{
  int v1; // r14d
  UFG::GameStatTracker *v2; // rax
  int Stat; // esi
  int v4; // ebx
  int v5; // edi
  char *v6; // r9
  bool v7; // r8
  char *v8; // rdx
  UFG::GameStatTracker *v9; // rax
  int v10; // esi
  int v11; // ebx
  int v12; // edi
  Scaleform::GFx::Value *p_pargs; // rcx
  UFG::GameStatTracker *v14; // rax
  int v15; // esi
  int v16; // ebx
  int v17; // edi
  Scaleform::GFx::Value *p_ptr; // rcx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-A8h] BYREF
  char v20[8]; // [rsp+60h] [rbp-78h] BYREF
  char v21[8]; // [rsp+68h] [rbp-70h] BYREF
  __int64 v22; // [rsp+70h] [rbp-68h]
  __int64 v23; // [rsp+78h] [rbp-60h]
  int v24; // [rsp+80h] [rbp-58h]
  const char *v25; // [rsp+88h] [rbp-50h]
  Scaleform::GFx::Value pargs; // [rsp+98h] [rbp-40h] BYREF
  char v27[16]; // [rsp+C8h] [rbp-10h] BYREF
  __int64 v28; // [rsp+D8h] [rbp+0h]
  int v29; // [rsp+E0h] [rbp+8h]
  const char *v30; // [rsp+E8h] [rbp+10h]
  char v31[16]; // [rsp+F8h] [rbp+20h] BYREF
  __int64 v32; // [rsp+108h] [rbp+30h]
  int v33; // [rsp+110h] [rbp+38h]
  const char *v34; // [rsp+118h] [rbp+40h]
  __int64 v35; // [rsp+128h] [rbp+50h]
  char string[96]; // [rsp+138h] [rbp+60h] BYREF
  int v37; // [rsp+1E8h] [rbp+110h]

  v35 = -2i64;
  v1 = ePage;
  if ( (unsigned int)(ePage - 7) <= 1 )
  {
    v2 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v2, StatueOffensiveStage);
    v4 = 0;
    do
    {
      v5 = v4 + 1;
      sprintf(string, "$GAMETRACKER_OFFENSIVE_MOVE_%d", (unsigned int)(v4 + 1));
      if ( v4 >= Stat )
      {
        v6 = "Icon_Reward_Empty";
        v7 = 0;
        v8 = "$GAMETRACKER_UNKNOWN";
      }
      else
      {
        v6 = "Icon_Reward_MeleeOffense";
        v7 = 1;
        v8 = "$GAMETRACKER_LEARNED";
      }
      UFG::UIHKScreenGameTracker::AddRow(string, v8, v7, v6);
      ++v4;
    }
    while ( v5 < 5 );
  }
  if ( ((v1 - 7) & 0xFFFFFFFD) == 0 )
  {
    v9 = UFG::GameStatTracker::Instance();
    v10 = UFG::GameStatTracker::GetStat(v9, StatueDefensiveStage);
    v11 = 0;
    do
    {
      v12 = v11 + 1;
      sprintf(string, "$GAMETRACKER_DEFENSIVE_MOVE_%d", (unsigned int)(v11 + 1));
      if ( v11 >= v10 )
      {
        `eh vector constructor iterator(&pargs, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = VT_String;
        pargs.mValue.pString = string;
        if ( (v29 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v28 + 16i64))(v28, v27, v30);
          v28 = 0i64;
        }
        v29 = 6;
        v30 = "$GAMETRACKER_UNKNOWN";
        if ( (v33 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v32 + 16i64))(v32, v31, v34);
          v32 = 0i64;
        }
        v33 = 6;
        v34 = "Icon_Reward_Empty";
        if ( UFG::UIHKScreenGameTracker::mMovie )
          Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "AddSlot", 0i64, &pargs, 3u);
        ++UFG::UIHKScreenGameTracker::m_iRowCount;
        p_pargs = &pargs;
      }
      else
      {
        `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        ptr.Type = VT_String;
        ptr.mValue.pString = string;
        if ( (v23 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, unsigned __int64))(*(_QWORD *)v22 + 16i64))(v22, v20, ptr.DataAux);
          v22 = 0i64;
        }
        LODWORD(v23) = 6;
        ptr.DataAux = (unsigned __int64)"$GAMETRACKER_LEARNED";
        if ( (v24 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v23 + 16i64))(v23, v21, v25);
          v23 = 0i64;
        }
        v24 = 6;
        v25 = "Icon_Reward_MeleeDefense";
        if ( UFG::UIHKScreenGameTracker::mMovie )
          Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "AddSlot", 0i64, &ptr, 3u);
        ++UFG::UIHKScreenGameTracker::m_iRowCount;
        ++UFG::UIHKScreenGameTracker::m_iRowCollectedCount;
        p_pargs = &ptr;
      }
      `eh vector destructor iterator(p_pargs, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      ++v11;
    }
    while ( v12 < 5 );
    v1 = v37;
  }
  if ( v1 == 7 || v1 == 10 )
  {
    v14 = UFG::GameStatTracker::Instance();
    v15 = UFG::GameStatTracker::GetStat(v14, GunplayUpgradeStage);
    v16 = 0;
    do
    {
      v17 = v16 + 1;
      sprintf(string, "$GAMETRACKER_GUNPLAY_MOVE_%d", (unsigned int)(v16 + 1));
      if ( v16 >= v15 )
      {
        `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        ptr.Type = VT_String;
        ptr.mValue.pString = string;
        if ( (v23 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, unsigned __int64))(*(_QWORD *)v22 + 16i64))(v22, v20, ptr.DataAux);
          v22 = 0i64;
        }
        LODWORD(v23) = 6;
        ptr.DataAux = (unsigned __int64)"$GAMETRACKER_UNKNOWN";
        if ( (v24 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v23 + 16i64))(v23, v21, v25);
          v23 = 0i64;
        }
        v24 = 6;
        v25 = "Icon_Reward_Empty";
        if ( UFG::UIHKScreenGameTracker::mMovie )
          Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "AddSlot", 0i64, &ptr, 3u);
        ++UFG::UIHKScreenGameTracker::m_iRowCount;
        p_ptr = &ptr;
      }
      else
      {
        `eh vector constructor iterator(&pargs, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = VT_String;
        pargs.mValue.pString = string;
        if ( (v29 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v28 + 16i64))(v28, v27, v30);
          v28 = 0i64;
        }
        v29 = 6;
        v30 = "$GAMETRACKER_LEARNED";
        if ( (v33 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v32 + 16i64))(v32, v31, v34);
          v32 = 0i64;
        }
        v33 = 6;
        v34 = "Icon_Reward_GunPlay";
        if ( UFG::UIHKScreenGameTracker::mMovie )
          Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "AddSlot", 0i64, &pargs, 3u);
        ++UFG::UIHKScreenGameTracker::m_iRowCount;
        ++UFG::UIHKScreenGameTracker::m_iRowCollectedCount;
        p_ptr = &pargs;
      }
      `eh vector destructor iterator(p_ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      ++v16;
    }
    while ( v17 < 5 );
  }
}

// File Line: 436
// RVA: 0x5F5BB0
void __fastcall UFG::UIHKScreenGameTracker::PopulateCollectibles(unsigned int ePage)
{
  hkaMatrix<float> *Instance; // r15
  int v3; // r14d
  int i; // edi
  UFG::UIAmbientMapBlipData *BlipData; // rax
  __int64 mZoneInfo; // rbx
  UFG::qSymbol *v7; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v9; // r14
  UFG::GameStatTracker *v10; // rax
  UFG::PersistentData::MapBool *MapBool; // r15
  unsigned int mNumElements; // esi
  unsigned int v13; // edi
  __int64 j; // rbx
  char *ValuePtr; // rax
  UFG::qPropertySet *v16; // rcx
  char *v17; // rax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // esi
  __int64 v22; // r14
  __int128 v23; // xmm0
  unsigned int v24; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v26; // rax
  int v27; // ebx
  int v28; // edi
  unsigned int v29; // r15d
  char *mData; // rcx
  signed __int64 v31; // rdx
  char v32; // al
  Scaleform::GFx::Value *p_pargs; // rcx
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-B8h]
  __int64 v35[2]; // [rsp+30h] [rbp-A8h]
  __int64 v36[2]; // [rsp+40h] [rbp-98h]
  UFG::PropertySetHandle v37; // [rsp+50h] [rbp-88h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-78h] BYREF
  char v39[16]; // [rsp+98h] [rbp-40h] BYREF
  __int64 v40; // [rsp+A8h] [rbp-30h]
  int v41; // [rsp+B0h] [rbp-28h]
  const char *v42; // [rsp+B8h] [rbp-20h]
  Scaleform::GFx::Value pargs; // [rsp+C8h] [rbp-10h] BYREF
  char v44[16]; // [rsp+F8h] [rbp+20h] BYREF
  __int64 v45; // [rsp+108h] [rbp+30h]
  int v46; // [rsp+110h] [rbp+38h]
  char *v47; // [rsp+118h] [rbp+40h]
  char v48[16]; // [rsp+128h] [rbp+50h] BYREF
  __int64 v49; // [rsp+138h] [rbp+60h]
  int v50; // [rsp+140h] [rbp+68h]
  const char *v51; // [rsp+148h] [rbp+70h]
  __int64 v52; // [rsp+158h] [rbp+80h]
  __int128 v53; // [rsp+168h] [rbp+90h] BYREF
  char v54[16]; // [rsp+178h] [rbp+A0h] BYREF
  UFG::qString v55; // [rsp+1E8h] [rbp+110h] BYREF
  char v56[184]; // [rsp+218h] [rbp+140h] BYREF
  UFG::qSymbol result; // [rsp+2D8h] [rbp+200h] BYREF

  v52 = -2i64;
  Instance = (hkaMatrix<float> *)UFG::UIAmbientMapBlipManager::getInstance();
  v36[0] = 0i64;
  v36[1] = 0i64;
  v35[0] = 0i64;
  v35[1] = 0i64;
  v3 = hkaMatrix<float>::Height(Instance);
  for ( i = 0; i < v3; ++i )
  {
    BlipData = UFG::UIAmbientMapBlipManager::GetBlipData((UFG::UIAmbientMapBlipManager *)Instance, i);
    if ( BlipData )
    {
      if ( BlipData->mCollectibleType == COLLECTIBLE_HEALTH_SHRINE )
      {
        if ( ePage <= 1 )
          goto LABEL_9;
      }
      else if ( BlipData->mCollectibleType == COLLECTIBLE_LOCKBOX && (ePage == 3 || !ePage) )
      {
LABEL_9:
        mZoneInfo = BlipData->mZoneInfo;
        ++*((_DWORD *)v36 + mZoneInfo);
        if ( UFG::UIAmbientMapBlipData::IsCollected(BlipData) )
          ++*((_DWORD *)v35 + mZoneInfo);
      }
    }
  }
  if ( (ePage & 0xFFFFFFFD) == 0 )
  {
    v7 = UFG::qSymbol::create_from_string(&result, "default-spycams-list");
    PropertySet = UFG::PropertySetManager::GetPropertySet(v7);
    UFG::PropertySetHandle::PropertySetHandle(&v37, PropertySet);
    UFG::PropertySetHandle::Bind(&v37);
    v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           v37.mpPropSet,
           (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_List_1,
           DEPTH_RECURSE);
    v10 = UFG::GameStatTracker::Instance();
    MapBool = UFG::GameStatTracker::GetMapBool(v10, Collectible_SpyCam);
    if ( v9 )
    {
      mNumElements = v9->mNumElements;
      v13 = 0;
      for ( j = 0i64; v13 < mNumElements; ++v13 )
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, v13);
        if ( ValuePtr && *(_QWORD *)ValuePtr )
          v16 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
        else
          v16 = 0i64;
        result.mUID = v16->mName.mUID;
        v17 = PropertyUtils::Get<char const *>(
                v16,
                (UFG::qArray<unsigned long,0> *)&SpyCamSymbol_Neighborhood_1,
                DEPTH_RECURSE);
        v18 = UFG::UIHKScreenSpyPC::GetNeighborhoodId(v17) - 1;
        if ( v18 )
        {
          v19 = v18 - 1;
          if ( v19 )
          {
            v20 = v19 - 1;
            if ( v20 )
            {
              if ( v20 == 1 )
                j = 2i64;
            }
            else
            {
              j = 0i64;
            }
          }
          else
          {
            j = 3i64;
          }
        }
        else
        {
          j = 1i64;
        }
        ++*((_DWORD *)v36 + j);
        if ( UFG::PersistentData::MapBool::GetStatus(MapBool, &result) )
          ++*((_DWORD *)v35 + j);
      }
    }
    UFG::PropertySetHandle::Null(&v37);
    UFG::PropertySetHandle::~PropertySetHandle(&v37);
  }
  v21 = 0;
  v22 = 0i64;
  do
  {
    switch ( v21 )
    {
      case 0:
        v23 = *(_OWORD *)aGametrackerAbe;
        strcpy(v54, "RDEEN");
        goto LABEL_40;
      case 1:
        v23 = *(_OWORD *)aGametrackerCen;
        strcpy(v54, "TRAL");
        goto LABEL_40;
      case 2:
        v23 = *(_OWORD *)aGametrackerKen;
        strcpy(v54, "NEDY_TOWN");
        goto LABEL_40;
      case 3:
        v23 = *(_OWORD *)aGametrackerNor;
        strcpy(v54, "THPOINT");
LABEL_40:
        v53 = v23;
        break;
    }
    v24 = UFG::qStringHashUpper32("GAMETRACKER_SUMMARY_COLLECTED", -1);
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    if ( !m_translator || (v26 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v24)) == 0i64 )
      v26 = "GAMETRACKER_SUMMARY_COLLECTED";
    v27 = 0;
    v28 = *(_DWORD *)((char *)v36 + v22);
    if ( v28 > 0 )
      v27 = (int)(float)((float)((float)*(int *)((char *)v35 + v22) / (float)v28) * 100.0);
    v29 = *(_DWORD *)((char *)v35 + v22);
    LODWORD(pDtor) = v27;
    UFG::qString::qString(&v55, v26, v29, (unsigned int)v28, pDtor);
    mData = v55.mData;
    v31 = v56 - v55.mData;
    do
    {
      v32 = *mData;
      mData[v31] = *mData;
      ++mData;
    }
    while ( v32 );
    pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
    if ( v27 < 100 )
    {
      `eh vector constructor iterator(&pargs, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_String;
      pargs.mValue.pString = (const char *)&v53;
      if ( (v46 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v45 + 16i64))(v45, v44, v47);
        v45 = 0i64;
      }
      v46 = 6;
      v47 = v56;
      if ( (v50 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v49 + 16i64))(v49, v48, v51);
        v49 = 0i64;
      }
      v50 = 6;
      v51 = "Icon_Reward_Empty";
      if ( UFG::UIHKScreenGameTracker::mMovie )
        Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "AddSlot", 0i64, &pargs, 3u);
      ++UFG::UIHKScreenGameTracker::m_iRowCount;
      p_pargs = &pargs;
    }
    else
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, UFG::qPropertySet *))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          v37.mpPropSet);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      v37.mpPropSet = (UFG::qPropertySet *)&v53;
      if ( (ptr.mValue.BValue & 0x40) != 0 )
      {
        (*(void (__fastcall **)(_QWORD, $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *, unsigned __int64))(**(_QWORD **)&ptr.Type
                                                                                              + 16i64))(
          *(_QWORD *)&ptr.Type,
          &ptr.8,
          ptr.DataAux);
        *(_QWORD *)&ptr.Type = 0i64;
      }
      ptr.mValue.IValue = 6;
      ptr.DataAux = (unsigned __int64)v56;
      if ( (v41 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v40 + 16i64))(v40, v39, v42);
        v40 = 0i64;
      }
      v41 = 6;
      v42 = "Icon_Reward_DetectCamera";
      if ( UFG::UIHKScreenGameTracker::mMovie )
        Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "AddSlot", 0i64, &ptr, 3u);
      ++UFG::UIHKScreenGameTracker::m_iRowCount;
      p_pargs = &ptr;
    }
    `eh vector destructor iterator(p_pargs, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::UIHKScreenGameTracker::m_iRowCount = v28 + UFG::UIHKScreenGameTracker::m_iRowCount - 1;
    UFG::UIHKScreenGameTracker::m_iRowCollectedCount += v29;
    UFG::qString::~qString(&v55);
    ++v21;
    v22 += 4i64;
  }
  while ( v21 < 4 );
}

// File Line: 623
// RVA: 0x5FDC60
void UFG::UIHKScreenGameTracker::PopulateVehicles(void)
{
  UFG::StoreFrontTracker *v0; // rsi
  hkpCollidable *v1; // rdx
  hkpCollidable *v2; // r8
  hkpCollisionInput *v3; // r9
  UFG::StoreFront *ContactMgr; // rdi
  unsigned int i; // ebx
  UFG::qPropertySet *Item; // rax
  char *v7; // rax
  char *v8; // rdx
  char v9; // cl
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-D0h] BYREF
  char v11[16]; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v12; // [rsp+70h] [rbp-90h]
  int v13; // [rsp+78h] [rbp-88h]
  const char *v14; // [rsp+80h] [rbp-80h]
  char v15[16]; // [rsp+90h] [rbp-70h] BYREF
  __int64 v16; // [rsp+A0h] [rbp-60h]
  int v17; // [rsp+A8h] [rbp-58h]
  const char *v18; // [rsp+B0h] [rbp-50h]
  __int64 v19; // [rsp+C0h] [rbp-40h]
  char pRowTitle[96]; // [rsp+D0h] [rbp-30h] BYREF
  UFG::qSymbol storeName; // [rsp+190h] [rbp+90h] BYREF
  UFG::qSymbol result; // [rsp+198h] [rbp+98h] BYREF
  UFG::qSymbol *p_storeName; // [rsp+1A0h] [rbp+A0h]

  v19 = -2i64;
  v0 = UFG::StoreFrontTracker::Instance();
  UFG::StoreFrontTracker::LoadStoreData(v0, InventoryType_Vehicle);
  UFG::qSymbol::create_from_string(&result, "GameTrackerVehicle");
  p_storeName = &storeName;
  storeName.mUID = result.mUID;
  UFG::StoreFrontTracker::SetCurrentStore(v0, InventoryType_Vehicle, &storeName.mUID, 0i64, 0i64);
  ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v0, v1, v2, v3);
  for ( i = 0; i < (unsigned int)UFG::StoreFront::GetNumItems(ContactMgr); ++i )
  {
    Item = UFG::StoreFront::GetItem(ContactMgr, i);
    v7 = PropertyUtils::Get<char const *>(
           Item,
           (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Title,
           DEPTH_RECURSE);
    v8 = (char *)(pRowTitle - v7);
    do
    {
      v9 = *v7;
      v7[(_QWORD)v8] = *v7;
      ++v7;
    }
    while ( v9 );
    if ( UFG::StoreFront::IsOwned(ContactMgr, i) )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.mValue.pString = pRowTitle;
      if ( (v13 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v12 + 16i64))(v12, v11, v14);
        v12 = 0i64;
      }
      v13 = 6;
      v14 = "$GAMETRACKER_OWNED";
      if ( (v17 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
        v16 = 0i64;
      }
      v17 = 6;
      v18 = "Icon_Reward_Vehicle";
      if ( UFG::UIHKScreenGameTracker::mMovie )
        Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "AddSlot", 0i64, &ptr, 3u);
      ++UFG::UIHKScreenGameTracker::m_iRowCount;
      ++UFG::UIHKScreenGameTracker::m_iRowCollectedCount;
      `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
    else
    {
      UFG::UIHKScreenGameTracker::AddRow(pRowTitle, "$GAMETRACKER_NOTOWNED", 0, "Icon_Reward_Empty");
    }
  }
  UFG::StoreFrontTracker::UnloadStoreData(v0);
}

// File Line: 658
// RVA: 0x5F5A40
void UFG::UIHKScreenGameTracker::PopulateClothing(void)
{
  UFG::StoreFrontTracker *v0; // rbp
  unsigned int v1; // edi
  hkpCollidable *v2; // rdx
  hkpCollidable *v3; // r8
  hkpCollisionInput *v4; // r9
  UFG::StoreFront *ContactMgr; // rsi
  UFG::qPropertySet *Item; // rbx
  char *v7; // rax
  char *v8; // rdx
  char v9; // cl
  char *v10; // r9
  bool v11; // r8
  char *v12; // rdx
  char pRowTitle[152]; // [rsp+40h] [rbp-98h] BYREF
  UFG::qSymbol storeName; // [rsp+E0h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+E8h] [rbp+10h] BYREF
  UFG::qSymbol *p_storeName; // [rsp+F0h] [rbp+18h]

  v0 = UFG::StoreFrontTracker::Instance();
  UFG::StoreFrontTracker::LoadStoreData(v0, InventoryType_Clothing);
  UFG::qSymbol::create_from_string(&result, "GameTrackerClothing");
  p_storeName = &storeName;
  storeName.mUID = result.mUID;
  v1 = 0;
  UFG::StoreFrontTracker::SetCurrentStore(v0, InventoryType_Clothing, &storeName.mUID, 0i64, 0i64);
  ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v0, v2, v3, v4);
  UFG::StoreFront::SetCurrentCategory(ContactMgr, Num_ItemCategories);
  if ( (unsigned int)UFG::StoreFront::GetNumItems(ContactMgr) )
  {
    do
    {
      Item = UFG::StoreFront::GetItem(ContactMgr, v1);
      storeName.mUID = -1;
      UFG::qSymbol::set_from_cstr(&storeName, "P_JeansBaggy_TS00(Tint: 0)");
      v7 = PropertyUtils::Get<char const *>(
             Item,
             (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Title,
             DEPTH_RECURSE);
      v8 = (char *)(pRowTitle - v7);
      do
      {
        v9 = *v7;
        v7[(_QWORD)v8] = *v7;
        ++v7;
      }
      while ( v9 );
      if ( UFG::StoreFront::IsOwned(ContactMgr, v1) )
      {
        v10 = "Icon_Reward_Clothing";
        v11 = 1;
        v12 = "$GAMETRACKER_OWNED";
      }
      else
      {
        v10 = "Icon_Reward_Empty";
        v11 = 0;
        v12 = "$GAMETRACKER_NOTOWNED";
      }
      UFG::UIHKScreenGameTracker::AddRow(pRowTitle, v12, v11, v10);
      ++v1;
    }
    while ( v1 < (unsigned int)UFG::StoreFront::GetNumItems(ContactMgr) );
  }
  UFG::StoreFrontTracker::UnloadStoreData(v0);
}

// File Line: 701
// RVA: 0x5D2C00
void __fastcall UFG::UIHKScreenGameTracker::AddRow(
        char *pRowTitle,
        char *pRowStatus,
        bool bCollected,
        char *pIconImage)
{
  Scaleform::GFx::Value ptr; // [rsp+18h] [rbp-59h] BYREF
  char v9[16]; // [rsp+48h] [rbp-29h] BYREF
  __int64 v10; // [rsp+58h] [rbp-19h]
  int v11; // [rsp+60h] [rbp-11h]
  char *v12; // [rsp+68h] [rbp-9h]
  char v13[16]; // [rsp+78h] [rbp+7h] BYREF
  __int64 v14; // [rsp+88h] [rbp+17h]
  int v15; // [rsp+90h] [rbp+1Fh]
  char *v16; // [rsp+98h] [rbp+27h]
  __int64 v17; // [rsp+A8h] [rbp+37h]

  v17 = -2i64;
  ptr.pNext = (Scaleform::GFx::Value *)Scaleform::GFx::Value::~Value;
  `eh vector constructor iterator(&ptr.Type, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = pRowTitle;
  if ( (v11 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v10 + 16i64))(v10, v9, v12);
    v10 = 0i64;
  }
  v11 = 6;
  v12 = pRowStatus;
  if ( (v15 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v14 + 16i64))(v14, v13, v16);
    v14 = 0i64;
  }
  v15 = 6;
  v16 = pIconImage;
  if ( UFG::UIHKScreenGameTracker::mMovie )
    Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "AddSlot", 0i64, &ptr, 3u);
  ++UFG::UIHKScreenGameTracker::m_iRowCount;
  if ( bCollected )
    ++UFG::UIHKScreenGameTracker::m_iRowCollectedCount;
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 723
// RVA: 0x61C8F0
void __fastcall UFG::UIHKScreenGameTracker::UpdatePageTotal(UFG::UIHKScreenGameTracker *this)
{
  unsigned int v2; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v4; // rdx
  UFG::qString v5; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+60h] [rbp-38h] BYREF

  v2 = UFG::qStringHashUpper32("GAMETRACKER_TOTAL_COLLECTED", -1);
  m_translator = UFG::UIScreenManager::s_instance->m_translator;
  if ( !m_translator || (v4 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v2)) == 0i64 )
    v4 = "GAMETRACKER_TOTAL_COLLECTED";
  this->m_iPercentageCollected = 0;
  if ( UFG::UIHKScreenGameTracker::m_iRowCount > 0 )
    this->m_iPercentageCollected = (int)(float)((float)((float)UFG::UIHKScreenGameTracker::m_iRowCollectedCount
                                                      / (float)UFG::UIHKScreenGameTracker::m_iRowCount)
                                              * 100.0);
  UFG::qString::qString(&v5, v4, (unsigned int)UFG::UIHKScreenGameTracker::m_iRowCollectedCount);
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_String;
  pargs.mValue.pString = v5.mData;
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "SetTotalHeading", 0i64, &pargs, 1u);
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Undefined;
  UFG::qString::~qString(&v5);
}

// File Line: 741
// RVA: 0x5F2800
void __fastcall UFG::UIHKScreenGameTracker::NextPage(UFG::UIHKScreenGameTracker *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::UIHKScreenGameTracker::eGameTrackerPage m_eCurrentPage; // ecx
  UFG::UIHKScreenGameTracker::eGameTrackerPage v4; // eax

  pObject = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::Invoke(pObject, "TabMenuWidgetList_ScrollNext", 0i64, 0i64, 0);
  Scaleform::GFx::Movie::Invoke(pObject, "TabMenuWidgetList_UpdateSpacing", 0i64, 0i64, 0);
  m_eCurrentPage = this->m_eCurrentPage;
  if ( (unsigned int)m_eCurrentPage > PAGE_COLLECTIBLES_LOCKBOXES )
  {
    if ( (unsigned int)(m_eCurrentPage - 4) > 2 )
    {
      if ( (unsigned int)(m_eCurrentPage - 7) <= 3 )
      {
        v4 = m_eCurrentPage + 1;
        if ( m_eCurrentPage + 1 > 10 )
          v4 = PAGE_START_UPGRADES;
        this->m_eCurrentPage = v4;
      }
    }
    else
    {
      this->m_eCurrentPage = m_eCurrentPage + 1;
      if ( m_eCurrentPage + 1 > 6 )
        this->m_eCurrentPage = PAGE_START_ASSETS;
    }
  }
  else
  {
    this->m_eCurrentPage = m_eCurrentPage + 1;
    if ( m_eCurrentPage + 1 > 3 )
      this->m_eCurrentPage = PAGE_START_COLLECTIBLES;
  }
}

// File Line: 777
// RVA: 0x5FE310
void __fastcall UFG::UIHKScreenGameTracker::PrevPage(UFG::UIHKScreenGameTracker *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::UIHKScreenGameTracker::eGameTrackerPage m_eCurrentPage; // ecx
  UFG::UIHKScreenGameTracker::eGameTrackerPage v4; // eax

  pObject = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::Invoke(pObject, "TabMenuWidgetList_ScrollPrev", 0i64, 0i64, 0);
  Scaleform::GFx::Movie::Invoke(pObject, "TabMenuWidgetList_UpdateSpacing", 0i64, 0i64, 0);
  m_eCurrentPage = this->m_eCurrentPage;
  if ( (unsigned int)m_eCurrentPage > PAGE_COLLECTIBLES_LOCKBOXES )
  {
    if ( (unsigned int)(m_eCurrentPage - 4) > 2 )
    {
      if ( (unsigned int)(m_eCurrentPage - 7) <= 3 )
      {
        v4 = m_eCurrentPage - 1;
        if ( m_eCurrentPage - 1 < 7 )
          v4 = PAGE_UPGRADES_SHOOTING_MOVES;
        this->m_eCurrentPage = v4;
      }
    }
    else
    {
      this->m_eCurrentPage = m_eCurrentPage - 1;
      if ( m_eCurrentPage - 1 < 4 )
        this->m_eCurrentPage = PAGE_ASSETS_CLOTHING;
    }
  }
  else
  {
    this->m_eCurrentPage = m_eCurrentPage - 1;
    if ( m_eCurrentPage - 1 < 0 )
      this->m_eCurrentPage = PAGE_COLLECTIBLES_LOCKBOXES;
  }
}

// File Line: 818
// RVA: 0x623300
bool __fastcall UFG::UIHKScreenGameTracker::handleMessage(
        UFG::UIHKScreenGameTracker *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // r14
  UFG::HudAudio *v8; // rcx
  const char *v9; // rdx
  UFG::UIScreen *Overlay; // rax
  UFG::UIHKScreenGlobalOverlay *v11; // rcx

  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return 0;
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
    || msgId == UI_HASH_DPAD_DOWN_REPEAT_30 )
  {
    v8 = UFG::HudAudio::m_instance;
    goto LABEL_41;
  }
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30
    || msgId == UI_HASH_DPAD_UP_REPEAT_30 )
  {
    if ( UFG::HudAudio::m_instance )
    {
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x593B70ABu, 0i64, 0, 0i64);
      v9 = "ScrollUp";
      goto LABEL_44;
    }
LABEL_13:
    v9 = "ScrollUp";
LABEL_44:
    Scaleform::GFx::Movie::Invoke(pObject, v9, 0i64, 0i64, 0);
    return 1;
  }
  if ( msgId == UI_HASH_MOUSE_WHEEL_SCROLL_30 )
  {
    v8 = UFG::HudAudio::m_instance;
    if ( SLODWORD(msg[1].mPrev) > 0 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x593B70ABu, 0i64, 0, 0i64);
      goto LABEL_13;
    }
LABEL_41:
    if ( v8 )
      UFG::AudioEntity::CreateAndPlayEvent(v8, 0xB78DCE8u, 0i64, 0, 0i64);
    v9 = "ScrollDown";
    goto LABEL_44;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    UFG::UIHKScreenGameTracker::HideHelpBar(this);
    return 1;
  }
  if ( msgId == UI_HASH_BUTTON_R1_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
    UFG::UIHKScreenGameTracker::NextPage(this);
LABEL_32:
    UFG::UIHKScreenGameTracker::PopulatePage(this);
    goto LABEL_33;
  }
  if ( msgId == UI_HASH_BUTTON_L1_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
    UFG::UIHKScreenGameTracker::PrevPage(this);
    goto LABEL_32;
  }
  if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
  {
    UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
      (UFG::UIHKScreenUpgrades *)this,
      (float)SLODWORD(msg[1].vfptr),
      (float)SHIDWORD(msg[1].vfptr));
  }
  else if ( msgId == UI_HASH_MOUSE_SELECT_SLOT_GT )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
    Scaleform::GFx::Movie::Invoke(pObject, "TabMenuWidgetList_UpdateSpacing", 0i64, 0i64, 0);
    this->m_eCurrentPage = UFG::UI::GetFlashArgsInt(msg);
    goto LABEL_32;
  }
LABEL_33:
  Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "GlobalOverlay");
  if ( Overlay )
  {
    v11 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v11 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::HandleMessage(&v11->HelpBar, Overlay, msgId, msg);
  }
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 898
// RVA: 0x60E2C0
void __fastcall UFG::UIHKScreenGameTracker::ShowHelpBar(UFG::UIHKScreenGameTracker *this)
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
    v4 = UFG::qStringHash32("GAMETRACKER", 0xFFFFFFFF);
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

// File Line: 913
// RVA: 0x5ECFB0
void __fastcall UFG::UIHKScreenGameTracker::HideHelpBar(UFG::UIHKScreenGameTracker *this)
{
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v2; // eax

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v2 = UFG::qStringHash32("GAMETRACKER", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v2);
  }
}

