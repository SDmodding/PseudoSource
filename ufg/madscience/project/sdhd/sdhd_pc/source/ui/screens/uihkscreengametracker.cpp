// File Line: 47
// RVA: 0x156C250
__int64 UFG::_dynamic_initializer_for__UI_HASH_MOUSE_SELECT_SLOT_GT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("MOUSE_SELECT_SLOT_GT", 0xFFFFFFFF);
  UI_HASH_MOUSE_SELECT_SLOT_GT = result;
  return result;
}

// File Line: 51
// RVA: 0x5F19D0
void __fastcall UFG::UIHKScreenGameTracker::LoadTextures(void (__fastcall *callback)(UFG::DataStreamer::Handle *, void *), void *callbackParam)
{
  void *v2; // rbx
  void (__fastcall *v3)(UFG::DataStreamer::Handle *, void *); // rdi
  UFG::UIScreenTextureManager *v4; // rax
  UFG::UIScreenTextureManager *v5; // rax

  v2 = callbackParam;
  v3 = callback;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v4,
    UFG::UIHKScreenGameTracker::gTexturePackFilename,
    HIGH_PRIORITY,
    v3,
    v2);
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v5,
    UFG::UIHKScreenStats::gTexturePackFilename,
    HIGH_PRIORITY,
    v3,
    v2);
}

// File Line: 56
// RVA: 0x5D4080
__int64 __fastcall UFG::UIHKScreenGameTracker::AreTexturesLoaded()
{
  UFG::UIScreenTextureManager *v0; // rax
  _BOOL8 v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  v1 = UFG::UIScreenTextureManager::IsTexturePackLoaded(v0, UFG::UIHKScreenGameTracker::gTexturePackFilename);
  v2 = UFG::UIScreenTextureManager::Instance();
  return (unsigned __int8)v1 & UFG::UIScreenTextureManager::IsTexturePackLoaded(
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
  UFG::UIHKScreenGameTracker *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGameTracker::`vftable;
  UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "ITEMS");
  v1->m_eCurrentPage = 0;
  UFG::UIHKScreenGameTracker::m_iRowCollectedCount = 0;
  UFG::UIHKScreenGameTracker::m_iRowCount = 0;
  UFG::UIHKScreenGameTracker::mMovie = 0i64;
  v1->m_iPercentageCollected = 0;
}

// File Line: 96
// RVA: 0x631B00
void __usercall UFG::UIHKScreenGameTracker::init(UFG::UIHKScreenGameTracker *this@<rcx>, UFG::UICommandData *data@<rdx>, __int64 a3@<r12>, __int64 a4@<r13>, __int64 a5@<r14>, __int64 a6@<r15>, float a7@<xmm0>)
{
  UFG::UIHKScreenGameTracker *v7; // rbx
  UFG::UIScreenRenderable *v8; // rax

  v7 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v8 = v7->mRenderable;
  if ( v8 )
  {
    UFG::UIHKScreenGameTracker::mMovie = v8->m_movie.pObject;
    if ( UFG::UIHKScreenGameTracker::mMovie )
    {
      if ( UFG::UIHKScreenGameTracker::m_eMode )
      {
        if ( UFG::UIHKScreenGameTracker::m_eMode == 1 )
        {
          v7->m_eCurrentPage = 4;
        }
        else if ( UFG::UIHKScreenGameTracker::m_eMode == 2 )
        {
          v7->m_eCurrentPage = 7;
        }
      }
      else
      {
        v7->m_eCurrentPage = 0;
      }
      UFG::UIHKScreenGameTracker::PopulatePageTabs(v7, a3, a4, a5, a6);
      UFG::UIHKScreenGameTracker::PopulatePage(v7, a7);
      UFG::UIHKScreenGameTracker::ShowHelpBar(v7);
    }
  }
}

// File Line: 132
// RVA: 0x5FA070
void __usercall UFG::UIHKScreenGameTracker::PopulatePageTabs(UFG::UIHKScreenGameTracker *this@<rcx>, __int64 a2@<r12>, __int64 a3@<r13>, __int64 a4@<r14>, __int64 a5@<r15>)
{
  signed int v5; // ebx
  signed int v6; // edi
  const char *v7; // rax
  const char *v8; // rax
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-38h]
  char vars0; // [rsp+70h] [rbp+0h]
  __int64 anonymous3; // [rsp+78h] [rbp+8h]
  __int64 anonymous2; // [rsp+80h] [rbp+10h]
  __int64 anonymous1; // [rsp+88h] [rbp+18h]
  char *anonymous0; // [rsp+90h] [rbp+20h]

  anonymous0 = &vars0;
  anonymous1 = a2;
  anonymous2 = a3;
  anonymous3 = a4;
  *(_QWORD *)&vars0 = a5;
  v5 = 0;
  v6 = 3;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 0;
  if ( UFG::UIHKScreenGameTracker::m_eMode )
  {
    if ( UFG::UIHKScreenGameTracker::m_eMode == 1 )
    {
      v5 = 4;
      v6 = 6;
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 6;
      v7 = "$GAMETRACKER_ASSETS";
      goto LABEL_14;
    }
    if ( UFG::UIHKScreenGameTracker::m_eMode != 2 )
      goto LABEL_15;
    v5 = 7;
    v6 = 10;
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    v7 = "$GAMETRACKER_UPGRADES";
  }
  else
  {
    v5 = 0;
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    v7 = "$GAMETRACKER_COLLECTIBLES";
  }
  pargs.Type = 6;
LABEL_14:
  *(_QWORD *)&pargs.mValue.NValue = v7;
LABEL_15:
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "SetPageHeading", 0i64, &pargs, 1u);
  for ( ; v5 <= v6; ++v5 )
  {
    switch ( v5 )
    {
      case 0:
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        *(_QWORD *)&pargs.mValue.NValue = "$GAMETRACKER_ALL_COLLECTIBLES";
        goto LABEL_51;
      case 1:
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        *(_QWORD *)&pargs.mValue.NValue = "$GAMETRACKER_HEALTH_SHRINES";
        goto LABEL_51;
      case 2:
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        *(_QWORD *)&pargs.mValue.NValue = "$GAMETRACKER_SPY_CAMERAS";
        goto LABEL_51;
      case 3:
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_LOCKBOXES";
        goto LABEL_50;
      case 4:
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_ALL_ASSERTS";
        goto LABEL_50;
      case 5:
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_VEHICLES";
        goto LABEL_50;
      case 6:
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_OUTFITS";
        goto LABEL_50;
      case 7:
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_ALL_UPGRADES";
        goto LABEL_50;
      case 8:
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_OFFENSIVE_MOVES";
        goto LABEL_50;
      case 9:
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_DEFENSIVE_MOVES";
        goto LABEL_50;
      case 10:
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        v8 = "$GAMETRACKER_SHOOTING_MOVES";
LABEL_50:
        *(_QWORD *)&pargs.mValue.NValue = v8;
LABEL_51:
        pargs.Type = 6;
        break;
      default:
        break;
    }
    Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "TabMenuWidgetList_AddItem", 0i64, &pargs, 1u);
  }
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "TabMenuWidgetList_Refresh", 0i64, 0i64, 0);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}l **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.N

// File Line: 225
// RVA: 0x5F9FB0
void __usercall UFG::UIHKScreenGameTracker::PopulatePage(UFG::UIHKScreenGameTracker *this@<rcx>, float a2@<xmm0>)
{
  UFG::UIHKScreenGameTracker *v2; // rbx
  UFG::UIHKScreenGameTracker::eGameTrackerPage v3; // ecx
  UFG::UIHKScreenGameTracker::eGameTrackerPage v4; // ecx

  v2 = this;
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "StatList.Clear", 0i64, 0i64);
  UFG::UIHKScreenGameTracker::m_iRowCollectedCount = 0;
  UFG::UIHKScreenGameTracker::m_iRowCount = 0;
  v3 = v2->m_eCurrentPage;
  if ( (unsigned int)v3 <= 3 )
    UFG::UIHKScreenGameTracker::PopulateCollectibles(v3, a2);
  if ( (unsigned int)(v2->m_eCurrentPage - 4) <= 1 )
    UFG::UIHKScreenGameTracker::PopulateVehicles();
  if ( !((v2->m_eCurrentPage - 4) & 0xFFFFFFFD) )
    UFG::UIHKScreenGameTracker::PopulateClothing();
  v4 = v2->m_eCurrentPage;
  if ( (unsigned int)(v4 - 7) <= 3 )
    UFG::UIHKScreenGameTracker::PopulatePlayerMoves(v4);
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "Stats_Refresh", 0i64, 0i64);
  UFG::UIHKScreenGameTracker::UpdatePageTotal(v2);
  UFG::UIHKScreenGameTracker::SetPageIcon(v2, v2->m_eCurrentPage);
  UFG::UIHKScreenGameTracker::SetPageInfoText(v2, v2->m_eCurrentPage);
}

// File Line: 269
// RVA: 0x606B90
void __fastcall UFG::UIHKScreenGameTracker::SetPageInfoText(UFG::UIHKScreenGameTracker *this, UFG::UIHKScreenGameTracker::eGameTrackerPage ePage)
{
  UFG::UIHKScreenGameTracker::eGameTrackerPage v2; // ebx
  const char *v3; // rdx
  char *v4; // rbx
  UFG::qString v5; // [rsp+30h] [rbp-1h]
  Scaleform::GFx::Value pargs; // [rsp+58h] [rbp+27h]

  v2 = ePage;
  UFG::qString::qString((UFG::qString *)((char *)&v5 + 8));
  switch ( v2 )
  {
    case 0:
    case 4:
    case 7:
      v3 = &customWorldMapCaption;
      goto LABEL_11;
    case 1:
      v3 = "$GAMETRACKER_DESC_SHRINE";
      goto LABEL_11;
    case 2:
      v3 = "$GAMETRACKER_DESC_SPYCAM";
      goto LABEL_11;
    case 3:
      v3 = "$GAMETRACKER_DESC_LOCKBOX";
      goto LABEL_11;
    case 5:
      v3 = "$GAMETRACKER_DESC_VEHICLES";
      goto LABEL_11;
    case 6:
      v3 = "$GAMETRACKER_DESC_OUTFITS";
      goto LABEL_11;
    case 8:
      v3 = "$GAMETRACKER_DESC_OFFENSIVE_MOVES";
      goto LABEL_11;
    case 9:
      v3 = "$GAMETRACKER_DESC_DEFENSIVE_MOVES";
      goto LABEL_11;
    case 10:
      v3 = "$GAMETRACKER_DESC_SHOOTING_MOVES";
LABEL_11:
      UFG::qString::Set(&v5, v3);
      break;
    default:
      break;
  }
  pargs.pObjectInterface = 0i64;
  pargs.Type = 0;
  v4 = v5.mData;
  pargs.Type = 6;
  *(_QWORD *)&pargs.mValue.NValue = v4;
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "SetPageInfoText", 0i64, &pargs, 1u);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 0;
  UFG::qString::~qString(&v5);
}

// File Line: 321
// RVA: 0x6069B0
void __fastcall UFG::UIHKScreenGameTracker::SetPageIcon(UFG::UIHKScreenGameTracker *this, UFG::UIHKScreenGameTracker::eGameTrackerPage ePage)
{
  UFG::UIHKScreenGameTracker::eGameTrackerPage v2; // ebx
  UFG::UIHKScreenGameTracker *v3; // rdi
  const char *v4; // rdx
  char *v5; // rbx
  double v6; // xmm6_8
  UFG::qString v7; // [rsp+28h] [rbp-59h]
  char ptr; // [rsp+58h] [rbp-29h]
  __int64 v9; // [rsp+68h] [rbp-19h]
  unsigned int v10; // [rsp+70h] [rbp-11h]
  char *v11; // [rsp+78h] [rbp-9h]
  char v12; // [rsp+88h] [rbp+7h]
  __int64 v13; // [rsp+98h] [rbp+17h]
  unsigned int v14; // [rsp+A0h] [rbp+1Fh]
  double v15; // [rsp+A8h] [rbp+27h]
  __int64 v16; // [rsp+B8h] [rbp+37h]

  v16 = -2i64;
  v2 = ePage;
  v3 = this;
  UFG::qString::qString((UFG::qString *)((char *)&v7 + 8));
  switch ( v2 )
  {
    case 0:
      v4 = "ALL_COLLECTIBLES";
      goto LABEL_13;
    case 1:
      v4 = "SHRINE";
      goto LABEL_13;
    case 2:
      v4 = "SPYCAM";
      goto LABEL_13;
    case 3:
      v4 = "LOCKBOX";
      goto LABEL_13;
    case 4:
      v4 = "ALL_ASSETS";
      goto LABEL_13;
    case 5:
      v4 = "VEHICLES";
      goto LABEL_13;
    case 6:
      v4 = "OUTFITS";
      goto LABEL_13;
    case 7:
      v4 = "ALL_MOVES";
      goto LABEL_13;
    case 8:
      v4 = "OFFENSIVE_MOVES";
      goto LABEL_13;
    case 9:
      v4 = "DEFENSIVE_MOVES";
      goto LABEL_13;
    case 10:
      v4 = "SHOOTING_MOVES";
LABEL_13:
      UFG::qString::Set(&v7, v4);
      break;
    default:
      break;
  }
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v5 = v7.mData;
  if ( (v10 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v9 + 16i64))(v9, &ptr, v11);
    v9 = 0i64;
  }
  v10 = 6;
  v11 = v5;
  v6 = (double)v3->m_iPercentageCollected;
  if ( (v14 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v13 + 16i64))(
      v13,
      &v12,
      COERCE_DOUBLE(*(_QWORD *)&v15));
    v13 = 0i64;
  }
  v14 = 5;
  v15 = v6;
  Scaleform::GFx::Movie::Invoke(
    UFG::UIHKScreenGameTracker::mMovie,
    "SetPageIcon",
    0i64,
    (Scaleform::GFx::Value *)&ptr,
    2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v7);
}

// File Line: 376
// RVA: 0x5FA450
void __fastcall UFG::UIHKScreenGameTracker::PopulatePlayerMoves(UFG::UIHKScreenGameTracker::eGameTrackerPage ePage)
{
  UFG::UIHKScreenGameTracker::eGameTrackerPage v1; // er14
  UFG::GameStatTracker *v2; // rax
  int v3; // esi
  int v4; // ebx
  int v5; // edi
  char *v6; // r9
  bool v7; // r8
  char *v8; // rdx
  UFG::GameStatTracker *v9; // rax
  int v10; // esi
  int v11; // ebx
  int v12; // edi
  Scaleform::GFx::Value *v13; // rcx
  UFG::GameStatTracker *v14; // rax
  int v15; // esi
  int v16; // ebx
  int v17; // edi
  Scaleform::GFx::Value *v18; // rcx
  char ptr; // [rsp+30h] [rbp-A8h]
  __int64 v20; // [rsp+40h] [rbp-98h]
  unsigned int v21; // [rsp+48h] [rbp-90h]
  char *v22; // [rsp+50h] [rbp-88h]
  const char *v23; // [rsp+58h] [rbp-80h]
  char v24; // [rsp+60h] [rbp-78h]
  char v25; // [rsp+68h] [rbp-70h]
  __int64 v26; // [rsp+70h] [rbp-68h]
  __int64 v27; // [rsp+78h] [rbp-60h]
  unsigned int v28; // [rsp+80h] [rbp-58h]
  const char *v29; // [rsp+88h] [rbp-50h]
  Scaleform::GFx::Value pargs; // [rsp+98h] [rbp-40h]
  char v31; // [rsp+C8h] [rbp-10h]
  __int64 v32; // [rsp+D8h] [rbp+0h]
  unsigned int v33; // [rsp+E0h] [rbp+8h]
  const char *v34; // [rsp+E8h] [rbp+10h]
  char v35; // [rsp+F8h] [rbp+20h]
  __int64 v36; // [rsp+108h] [rbp+30h]
  unsigned int v37; // [rsp+110h] [rbp+38h]
  const char *v38; // [rsp+118h] [rbp+40h]
  __int64 v39; // [rsp+128h] [rbp+50h]
  char string; // [rsp+138h] [rbp+60h]
  UFG::UIHKScreenGameTracker::eGameTrackerPage v41; // [rsp+1E8h] [rbp+110h]

  v39 = -2i64;
  v1 = ePage;
  if ( (unsigned int)(ePage - 7) <= 1 )
  {
    v2 = UFG::GameStatTracker::Instance();
    v3 = UFG::GameStatTracker::GetStat(v2, StatueOffensiveStage);
    v4 = 0;
    do
    {
      v5 = v4 + 1;
      sprintf(&string, "$GAMETRACKER_OFFENSIVE_MOVE_%d", (unsigned int)(v4 + 1));
      if ( v4 >= v3 )
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
      UFG::UIHKScreenGameTracker::AddRow(&string, v8, v7, v6);
      ++v4;
    }
    while ( v5 < 5 );
  }
  if ( !((v1 - 7) & 0xFFFFFFFD) )
  {
    v9 = UFG::GameStatTracker::Instance();
    v10 = UFG::GameStatTracker::GetStat(v9, StatueDefensiveStage);
    v11 = 0;
    do
    {
      v12 = v11 + 1;
      sprintf(&string, "$GAMETRACKER_DEFENSIVE_MOVE_%d", (unsigned int)(v11 + 1));
      if ( v11 >= v10 )
      {
        `eh vector constructor iterator(&pargs, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 6;
        *(_QWORD *)&pargs.mValue.NValue = &string;
        if ( (v33 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v32 + 16i64))(v32, &v31, v34);
          v32 = 0i64;
        }
        v33 = 6;
        v34 = "$GAMETRACKER_UNKNOWN";
        if ( (v37 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v36 + 16i64))(v36, &v35, v38);
          v36 = 0i64;
        }
        v37 = 6;
        v38 = "Icon_Reward_Empty";
        if ( UFG::UIHKScreenGameTracker::mMovie )
          Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "AddSlot", 0i64, &pargs, 3u);
        ++UFG::UIHKScreenGameTracker::m_iRowCount;
        v13 = &pargs;
      }
      else
      {
        `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( (v21 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v20 + 16i64))(v20, &ptr, v22);
          v20 = 0i64;
        }
        v21 = 6;
        v22 = &string;
        if ( ((unsigned int)v27 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v26 + 16i64))(v26, &v24, v23);
          v26 = 0i64;
        }
        LODWORD(v27) = 6;
        v23 = "$GAMETRACKER_LEARNED";
        if ( (v28 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v27 + 16i64))(v27, &v25, v29);
          v27 = 0i64;
        }
        v28 = 6;
        v29 = "Icon_Reward_MeleeDefense";
        if ( UFG::UIHKScreenGameTracker::mMovie )
          Scaleform::GFx::Movie::Invoke(
            UFG::UIHKScreenGameTracker::mMovie,
            "AddSlot",
            0i64,
            (Scaleform::GFx::Value *)&ptr,
            3u);
        ++UFG::UIHKScreenGameTracker::m_iRowCount;
        ++UFG::UIHKScreenGameTracker::m_iRowCollectedCount;
        v13 = (Scaleform::GFx::Value *)&ptr;
      }
      `eh vector destructor iterator(v13, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      ++v11;
    }
    while ( v12 < 5 );
    v1 = v41;
  }
  if ( v1 == 7 || v1 == 10 )
  {
    v14 = UFG::GameStatTracker::Instance();
    v15 = UFG::GameStatTracker::GetStat(v14, GunplayUpgradeStage);
    v16 = 0;
    do
    {
      v17 = v16 + 1;
      sprintf(&string, "$GAMETRACKER_GUNPLAY_MOVE_%d", (unsigned int)(v16 + 1));
      if ( v16 >= v15 )
      {
        `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( (v21 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v20 + 16i64))(v20, &ptr, v22);
          v20 = 0i64;
        }
        v21 = 6;
        v22 = &string;
        if ( ((unsigned int)v27 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v26 + 16i64))(v26, &v24, v23);
          v26 = 0i64;
        }
        LODWORD(v27) = 6;
        v23 = "$GAMETRACKER_UNKNOWN";
        if ( (v28 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v27 + 16i64))(v27, &v25, v29);
          v27 = 0i64;
        }
        v28 = 6;
        v29 = "Icon_Reward_Empty";
        if ( UFG::UIHKScreenGameTracker::mMovie )
          Scaleform::GFx::Movie::Invoke(
            UFG::UIHKScreenGameTracker::mMovie,
            "AddSlot",
            0i64,
            (Scaleform::GFx::Value *)&ptr,
            3u);
        ++UFG::UIHKScreenGameTracker::m_iRowCount;
        v18 = (Scaleform::GFx::Value *)&ptr;
      }
      else
      {
        `eh vector constructor iterator(&pargs, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 6;
        *(_QWORD *)&pargs.mValue.NValue = &string;
        if ( (v33 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v32 + 16i64))(v32, &v31, v34);
          v32 = 0i64;
        }
        v33 = 6;
        v34 = "$GAMETRACKER_LEARNED";
        if ( (v37 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v36 + 16i64))(v36, &v35, v38);
          v36 = 0i64;
        }
        v37 = 6;
        v38 = "Icon_Reward_GunPlay";
        if ( UFG::UIHKScreenGameTracker::mMovie )
          Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "AddSlot", 0i64, &pargs, 3u);
        ++UFG::UIHKScreenGameTracker::m_iRowCount;
        ++UFG::UIHKScreenGameTracker::m_iRowCollectedCount;
        v18 = &pargs;
      }
      `eh vector destructor iterator(v18, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      ++v16;
    }
    while ( v17 < 5 );
  }
}meTracker::m_iRowCo

// File Line: 436
// RVA: 0x5F5BB0
void __usercall UFG::UIHKScreenGameTracker::PopulateCollectibles(UFG::UIHKScreenGameTracker::eGameTrackerPage ePage@<ecx>, float a2@<xmm0>)
{
  UFG::UIHKScreenGameTracker::eGameTrackerPage v2; // esi
  UFG::UIAmbientMapBlipManager *v3; // r15
  int v4; // er14
  int i; // edi
  UFG::UIAmbientMapBlipData *v6; // rax
  __int64 v7; // rbx
  UFG::qSymbol *v8; // rax
  UFG::qPropertySet *v9; // rax
  UFG::qPropertyList *v10; // r14
  UFG::GameStatTracker *v11; // rax
  UFG::PersistentData::MapBool *v12; // r15
  unsigned int v13; // esi
  unsigned int v14; // edi
  signed __int64 v15; // rbx
  char *v16; // rax
  UFG::qPropertySet *v17; // rcx
  char *v18; // rax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  signed int v22; // esi
  __int64 v23; // r14
  __int128 v24; // xmm0
  unsigned int v25; // eax
  UFG::UIGfxTranslator *v26; // rcx
  const char *v27; // rax
  signed int v28; // ebx
  signed int v29; // edi
  unsigned int v30; // er15
  char *v31; // rcx
  signed __int64 v32; // rdx
  char v33; // al
  Scaleform::GFx::Value *v34; // rcx
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-B8h]
  __int64 v36; // [rsp+30h] [rbp-A8h]
  __int64 v37; // [rsp+38h] [rbp-A0h]
  __int64 v38; // [rsp+40h] [rbp-98h]
  __int64 v39; // [rsp+48h] [rbp-90h]
  UFG::PropertySetHandle v40; // [rsp+50h] [rbp-88h]
  char ptr; // [rsp+60h] [rbp-78h]
  char v42; // [rsp+68h] [rbp-70h]
  __int64 v43; // [rsp+70h] [rbp-68h]
  __int64 v44; // [rsp+78h] [rbp-60h]
  unsigned int v45; // [rsp+80h] [rbp-58h]
  char *v46; // [rsp+88h] [rbp-50h]
  char v47; // [rsp+98h] [rbp-40h]
  __int64 v48; // [rsp+A8h] [rbp-30h]
  unsigned int v49; // [rsp+B0h] [rbp-28h]
  const char *v50; // [rsp+B8h] [rbp-20h]
  Scaleform::GFx::Value pargs; // [rsp+C8h] [rbp-10h]
  char v52; // [rsp+F8h] [rbp+20h]
  __int64 v53; // [rsp+108h] [rbp+30h]
  unsigned int v54; // [rsp+110h] [rbp+38h]
  char *v55; // [rsp+118h] [rbp+40h]
  char v56; // [rsp+128h] [rbp+50h]
  __int64 v57; // [rsp+138h] [rbp+60h]
  unsigned int v58; // [rsp+140h] [rbp+68h]
  const char *v59; // [rsp+148h] [rbp+70h]
  __int64 v60; // [rsp+158h] [rbp+80h]
  __int128 v61; // [rsp+168h] [rbp+90h]
  __int64 v62; // [rsp+178h] [rbp+A0h]
  __int16 v63; // [rsp+180h] [rbp+A8h]
  UFG::qString v64; // [rsp+1E8h] [rbp+110h]
  char v65; // [rsp+218h] [rbp+140h]
  UFG::qSymbol result; // [rsp+2D8h] [rbp+200h]

  v60 = -2i64;
  v2 = ePage;
  v3 = UFG::UIAmbientMapBlipManager::getInstance(a2);
  v38 = 0i64;
  v39 = 0i64;
  v36 = 0i64;
  v37 = 0i64;
  v4 = hkaMatrix<float>::Height((hkaMatrix<float> *)v3);
  for ( i = 0; i < v4; ++i )
  {
    v6 = UFG::UIAmbientMapBlipManager::GetBlipData(v3, i);
    if ( v6 )
    {
      if ( v6->mCollectibleType == 2 )
      {
        if ( (unsigned int)v2 <= 1 )
          goto LABEL_9;
      }
      else if ( v6->mCollectibleType == 3 && (v2 == 3 || v2 == PAGE_START_COLLECTIBLES) )
      {
LABEL_9:
        v7 = (signed int)v6->mZoneInfo;
        ++*((_DWORD *)&v38 + v7);
        if ( UFG::UIAmbientMapBlipData::IsCollected(v6) )
          ++*((_DWORD *)&v36 + v7);
        continue;
      }
    }
  }
  if ( !(v2 & 0xFFFFFFFD) )
  {
    v8 = UFG::qSymbol::create_from_string(&result, "default-spycams-list");
    v9 = UFG::PropertySetManager::GetPropertySet(v8);
    UFG::PropertySetHandle::PropertySetHandle(&v40, v9);
    UFG::PropertySetHandle::Bind(&v40);
    v10 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            v40.mpPropSet,
            (UFG::qSymbol *)&SpyCamSymbol_List_1.mUID,
            DEPTH_RECURSE);
    v11 = UFG::GameStatTracker::Instance();
    v12 = UFG::GameStatTracker::GetMapBool(v11, Collectible_SpyCam);
    if ( v10 )
    {
      v13 = v10->mNumElements;
      v14 = 0;
      v15 = 0i64;
      if ( v13 )
      {
        do
        {
          v16 = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v14);
          if ( v16 && *(_QWORD *)v16 )
            v17 = (UFG::qPropertySet *)&v16[*(_QWORD *)v16];
          else
            v17 = 0i64;
          result.mUID = v17->mName.mUID;
          v18 = PropertyUtils::Get<char const *>(v17, (UFG::qSymbol *)&SpyCamSymbol_Neighborhood_1.mUID, DEPTH_RECURSE);
          v19 = (unsigned __int64)UFG::UIHKScreenSpyPC::GetNeighborhoodId(v18) - 1;
          if ( v19 )
          {
            v20 = v19 - 1;
            if ( v20 )
            {
              v21 = v20 - 1;
              if ( v21 )
              {
                if ( v21 == 1 )
                  v15 = 2i64;
              }
              else
              {
                v15 = 0i64;
              }
            }
            else
            {
              v15 = 3i64;
            }
          }
          else
          {
            v15 = 1i64;
          }
          ++*((_DWORD *)&v38 + v15);
          if ( UFG::PersistentData::MapBool::GetStatus(v12, &result) )
            ++*((_DWORD *)&v36 + v15);
          ++v14;
        }
        while ( v14 < v13 );
      }
    }
    UFG::PropertySetHandle::Null(&v40);
    UFG::PropertySetHandle::~PropertySetHandle(&v40);
  }
  v22 = 0;
  v23 = 0i64;
  do
  {
    switch ( v22 )
    {
      case 0:
        v24 = *(_OWORD *)aGametrackerAbe;
        LODWORD(v62) = 1162167378;
        WORD2(v62) = 78;
        goto LABEL_40;
      case 1:
        v24 = *(_OWORD *)aGametrackerCen;
        LODWORD(v62) = 1279349332;
        BYTE4(v62) = 0;
        goto LABEL_40;
      case 2:
        v24 = *(_OWORD *)aGametrackerKen;
        v62 = 6291339972956144974i64;
        v63 = 78;
        goto LABEL_40;
      case 3:
        v24 = *(_OWORD *)aGametrackerNor;
        v62 = 23729974813935700i64;
LABEL_40:
        v61 = v24;
        break;
    }
    v25 = UFG::qStringHashUpper32("GAMETRACKER_SUMMARY_COLLECTED", 0xFFFFFFFF);
    v26 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v26
      || (v27 = (const char *)v26->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v26->vfptr, v25)) == 0i64 )
    {
      v27 = "GAMETRACKER_SUMMARY_COLLECTED";
    }
    v28 = 0;
    v29 = *(_DWORD *)((char *)&v38 + v23);
    if ( v29 > 0 )
      v28 = (signed int)(float)((float)((float)*(signed int *)((char *)&v36 + v23) / (float)v29) * 100.0);
    v30 = *(_DWORD *)((char *)&v36 + v23);
    LODWORD(pDtor) = v28;
    UFG::qString::qString(&v64, v27, v30, (unsigned int)v29, pDtor);
    v31 = v64.mData;
    v32 = &v65 - v64.mData;
    do
    {
      v33 = *v31;
      v31[v32] = *v31;
      ++v31;
    }
    while ( v33 );
    pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
    if ( v28 < 100 )
    {
      `eh vector constructor iterator(&pargs, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 6;
      *(_QWORD *)&pargs.mValue.NValue = &v61;
      if ( (v54 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v53 + 16i64))(v53, &v52, v55);
        v53 = 0i64;
      }
      v54 = 6;
      v55 = &v65;
      if ( (v58 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v57 + 16i64))(v57, &v56, v59);
        v57 = 0i64;
      }
      v58 = 6;
      v59 = "Icon_Reward_Empty";
      if ( UFG::UIHKScreenGameTracker::mMovie )
        Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "AddSlot", 0i64, &pargs, 3u);
      ++UFG::UIHKScreenGameTracker::m_iRowCount;
      v34 = &pargs;
    }
    else
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( ((unsigned int)v44 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, UFG::qPropertySet *))(*(_QWORD *)v43 + 16i64))(
          v43,
          &ptr,
          v40.mpPropSet);
        v43 = 0i64;
      }
      LODWORD(v44) = 6;
      v40.mpPropSet = (UFG::qPropertySet *)&v61;
      if ( (v45 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v44 + 16i64))(v44, &v42, v46);
        v44 = 0i64;
      }
      v45 = 6;
      v46 = &v65;
      if ( (v49 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v48 + 16i64))(v48, &v47, v50);
        v48 = 0i64;
      }
      v49 = 6;
      v50 = "Icon_Reward_DetectCamera";
      if ( UFG::UIHKScreenGameTracker::mMovie )
        Scaleform::GFx::Movie::Invoke(
          UFG::UIHKScreenGameTracker::mMovie,
          "AddSlot",
          0i64,
          (Scaleform::GFx::Value *)&ptr,
          3u);
      ++UFG::UIHKScreenGameTracker::m_iRowCount;
      v34 = (Scaleform::GFx::Value *)&ptr;
    }
    `eh vector destructor iterator(v34, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::UIHKScreenGameTracker::m_iRowCount = v29 + UFG::UIHKScreenGameTracker::m_iRowCount - 1;
    UFG::UIHKScreenGameTracker::m_iRowCollectedCount += v30;
    UFG::qString::~qString(&v64);
    ++v22;
    v23 += 4i64;
  }
  while ( v22 < 4 );
}

// File Line: 623
// RVA: 0x5FDC60
void UFG::UIHKScreenGameTracker::PopulateVehicles(void)
{
  UFG::StoreFrontTracker *v0; // rsi
  hkpCollidable *v1; // rdx
  hkpCollidable *v2; // r8
  hkpCollisionInput *v3; // r9
  UFG::StoreFront *v4; // rdi
  unsigned int v5; // ebx
  UFG::qPropertySet *v6; // rax
  char *v7; // rax
  char *v8; // rdx
  char v9; // cl
  char ptr; // [rsp+30h] [rbp-D0h]
  __int64 v11; // [rsp+40h] [rbp-C0h]
  unsigned int v12; // [rsp+48h] [rbp-B8h]
  char *v13; // [rsp+50h] [rbp-B0h]
  char v14; // [rsp+60h] [rbp-A0h]
  __int64 v15; // [rsp+70h] [rbp-90h]
  unsigned int v16; // [rsp+78h] [rbp-88h]
  const char *v17; // [rsp+80h] [rbp-80h]
  char v18; // [rsp+90h] [rbp-70h]
  __int64 v19; // [rsp+A0h] [rbp-60h]
  unsigned int v20; // [rsp+A8h] [rbp-58h]
  const char *v21; // [rsp+B0h] [rbp-50h]
  __int64 v22; // [rsp+C0h] [rbp-40h]
  char pRowTitle[96]; // [rsp+D0h] [rbp-30h]
  UFG::qSymbol storeName; // [rsp+190h] [rbp+90h]
  UFG::qSymbol result; // [rsp+198h] [rbp+98h]
  UFG::qSymbol *v26; // [rsp+1A0h] [rbp+A0h]

  v22 = -2i64;
  v0 = UFG::StoreFrontTracker::Instance();
  UFG::StoreFrontTracker::LoadStoreData(v0, InventoryType_Vehicle);
  UFG::qSymbol::create_from_string(&result, "GameTrackerVehicle");
  v26 = &storeName;
  storeName.mUID = result.mUID;
  UFG::StoreFrontTracker::SetCurrentStore(v0, InventoryType_Vehicle, (__int64)&storeName, 0i64, 0i64);
  v4 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v0, v1, v2, v3);
  v5 = 0;
  if ( (unsigned int)UFG::StoreFront::GetNumItems(v4) )
  {
    do
    {
      v6 = UFG::StoreFront::GetItem(v4, v5);
      v7 = PropertyUtils::Get<char const *>(v6, (UFG::qSymbol *)&UFG::StoreItemSymbol_Title.mUID, DEPTH_RECURSE);
      v8 = (char *)(pRowTitle - v7);
      do
      {
        v9 = *v7;
        v7[(_QWORD)v8] = *v7;
        ++v7;
      }
      while ( v9 );
      if ( UFG::StoreFront::IsOwned(v4, v5) )
      {
        `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( (v12 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
          v11 = 0i64;
        }
        v12 = 6;
        v13 = pRowTitle;
        if ( (v16 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
          v15 = 0i64;
        }
        v16 = 6;
        v17 = "$GAMETRACKER_OWNED";
        if ( (v20 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
          v19 = 0i64;
        }
        v20 = 6;
        v21 = "Icon_Reward_Vehicle";
        if ( UFG::UIHKScreenGameTracker::mMovie )
          Scaleform::GFx::Movie::Invoke(
            UFG::UIHKScreenGameTracker::mMovie,
            "AddSlot",
            0i64,
            (Scaleform::GFx::Value *)&ptr,
            3u);
        ++UFG::UIHKScreenGameTracker::m_iRowCount;
        ++UFG::UIHKScreenGameTracker::m_iRowCollectedCount;
        `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
      else
      {
        UFG::UIHKScreenGameTracker::AddRow(pRowTitle, "$GAMETRACKER_NOTOWNED", 0, "Icon_Reward_Empty");
      }
      ++v5;
    }
    while ( v5 < (unsigned int)UFG::StoreFront::GetNumItems(v4) );
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
  UFG::StoreFront *v5; // rsi
  UFG::qPropertySet *v6; // rbx
  char *v7; // rax
  char *v8; // rdx
  char v9; // cl
  char *v10; // r9
  bool v11; // r8
  char *v12; // rdx
  char pRowTitle[152]; // [rsp+40h] [rbp-98h]
  UFG::qSymbol storeName; // [rsp+E0h] [rbp+8h]
  UFG::qSymbol result; // [rsp+E8h] [rbp+10h]
  UFG::qSymbol *v16; // [rsp+F0h] [rbp+18h]

  v0 = UFG::StoreFrontTracker::Instance();
  UFG::StoreFrontTracker::LoadStoreData(v0, InventoryType_Clothing);
  UFG::qSymbol::create_from_string(&result, "GameTrackerClothing");
  v16 = &storeName;
  storeName.mUID = result.mUID;
  v1 = 0;
  UFG::StoreFrontTracker::SetCurrentStore(v0, InventoryType_Clothing, (__int64)&storeName, 0i64, 0i64);
  v5 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v0, v2, v3, v4);
  UFG::StoreFront::SetCurrentCategory(v5, Num_ItemCategories);
  if ( (unsigned int)UFG::StoreFront::GetNumItems(v5) )
  {
    do
    {
      v6 = UFG::StoreFront::GetItem(v5, v1);
      storeName.mUID = -1;
      UFG::qSymbol::set_from_cstr(&storeName, "P_JeansBaggy_TS00(Tint: 0)");
      v7 = PropertyUtils::Get<char const *>(v6, (UFG::qSymbol *)&UFG::StoreItemSymbol_Title.mUID, DEPTH_RECURSE);
      v8 = (char *)(pRowTitle - v7);
      do
      {
        v9 = *v7;
        v7[(_QWORD)v8] = *v7;
        ++v7;
      }
      while ( v9 );
      if ( UFG::StoreFront::IsOwned(v5, v1) )
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
    while ( v1 < (unsigned int)UFG::StoreFront::GetNumItems(v5) );
  }
  UFG::StoreFrontTracker::UnloadStoreData(v0);
}

// File Line: 701
// RVA: 0x5D2C00
void __fastcall UFG::UIHKScreenGameTracker::AddRow(char *pRowTitle, char *pRowStatus, bool bCollected, char *pIconImage)
{
  char *v4; // rsi
  bool v5; // di
  char *v6; // r14
  char *v7; // rbx
  char ptr; // [rsp+18h] [rbp-59h]
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-51h]
  __int64 v10; // [rsp+28h] [rbp-49h]
  unsigned int v11; // [rsp+30h] [rbp-41h]
  char *v12; // [rsp+38h] [rbp-39h]
  char v13; // [rsp+48h] [rbp-29h]
  __int64 v14; // [rsp+58h] [rbp-19h]
  unsigned int v15; // [rsp+60h] [rbp-11h]
  char *v16; // [rsp+68h] [rbp-9h]
  char v17; // [rsp+78h] [rbp+7h]
  __int64 v18; // [rsp+88h] [rbp+17h]
  unsigned int v19; // [rsp+90h] [rbp+1Fh]
  char *v20; // [rsp+98h] [rbp+27h]
  __int64 v21; // [rsp+A8h] [rbp+37h]

  v21 = -2i64;
  v4 = pIconImage;
  v5 = bCollected;
  v6 = pRowStatus;
  v7 = pRowTitle;
  pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
  `eh vector constructor iterator(&v11, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v11 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v10 + 16i64))(v10, &ptr, v12);
    v10 = 0i64;
  }
  v11 = 6;
  v12 = v7;
  if ( (v15 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v14 + 16i64))(v14, &v13, v16);
    v14 = 0i64;
  }
  v15 = 6;
  v16 = v6;
  if ( (v19 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v18 + 16i64))(v18, &v17, v20);
    v18 = 0i64;
  }
  v19 = 6;
  v20 = v4;
  if ( UFG::UIHKScreenGameTracker::mMovie )
    Scaleform::GFx::Movie::Invoke(
      UFG::UIHKScreenGameTracker::mMovie,
      "AddSlot",
      0i64,
      (Scaleform::GFx::Value *)&ptr,
      3u);
  ++UFG::UIHKScreenGameTracker::m_iRowCount;
  if ( v5 )
    ++UFG::UIHKScreenGameTracker::m_iRowCollectedCount;
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 723
// RVA: 0x61C8F0
void __fastcall UFG::UIHKScreenGameTracker::UpdatePageTotal(UFG::UIHKScreenGameTracker *this)
{
  UFG::UIHKScreenGameTracker *v1; // rbx
  unsigned int v2; // eax
  UFG::UIGfxTranslator *v3; // rcx
  const char *v4; // rdx
  unsigned int numArgs; // ST20_4
  char *v6; // rbx
  UFG::qString v7; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::Value pargs; // [rsp+60h] [rbp-38h]

  v1 = this;
  v2 = UFG::qStringHashUpper32("GAMETRACKER_TOTAL_COLLECTED", 0xFFFFFFFF);
  v3 = UFG::UIScreenManager::s_instance->m_translator;
  if ( !v3 || (v4 = (const char *)v3->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, v2)) == 0i64 )
    v4 = "GAMETRACKER_TOTAL_COLLECTED";
  v1->m_iPercentageCollected = 0;
  if ( UFG::UIHKScreenGameTracker::m_iRowCount > 0 )
    v1->m_iPercentageCollected = (signed int)(float)((float)((float)UFG::UIHKScreenGameTracker::m_iRowCollectedCount
                                                           / (float)UFG::UIHKScreenGameTracker::m_iRowCount)
                                                   * 100.0);
  numArgs = v1->m_iPercentageCollected;
  UFG::qString::qString(&v7, v4, (unsigned int)UFG::UIHKScreenGameTracker::m_iRowCollectedCount);
  pargs.pObjectInterface = 0i64;
  pargs.Type = 0;
  v6 = v7.mData;
  pargs.Type = 6;
  *(_QWORD *)&pargs.mValue.NValue = v6;
  Scaleform::GFx::Movie::Invoke(UFG::UIHKScreenGameTracker::mMovie, "SetTotalHeading", 0i64, &pargs, 1u);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 0;
  UFG::qString::~qString(&v7);
}

// File Line: 741
// RVA: 0x5F2800
void __fastcall UFG::UIHKScreenGameTracker::NextPage(UFG::UIHKScreenGameTracker *this)
{
  UFG::UIHKScreenGameTracker *v1; // rdi
  Scaleform::GFx::Movie *v2; // rbx
  unsigned int v3; // ecx
  int v4; // eax

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::Invoke(v2, "TabMenuWidgetList_ScrollNext", 0i64, 0i64, 0);
  Scaleform::GFx::Movie::Invoke(v2, "TabMenuWidgetList_UpdateSpacing", 0i64, 0i64, 0);
  v3 = v1->m_eCurrentPage;
  if ( v3 > 3 )
  {
    if ( v3 - 4 > 2 )
    {
      if ( v3 - 7 <= 3 )
      {
        v4 = v3 + 1;
        if ( (signed int)(v3 + 1) > 10 )
          v4 = 7;
        v1->m_eCurrentPage = v4;
      }
    }
    else
    {
      v1->m_eCurrentPage = v3 + 1;
      if ( (signed int)(v3 + 1) > 6 )
        v1->m_eCurrentPage = 4;
    }
  }
  else
  {
    v1->m_eCurrentPage = v3 + 1;
    if ( (signed int)(v3 + 1) > 3 )
      v1->m_eCurrentPage = 0;
  }
}

// File Line: 777
// RVA: 0x5FE310
void __fastcall UFG::UIHKScreenGameTracker::PrevPage(UFG::UIHKScreenGameTracker *this)
{
  UFG::UIHKScreenGameTracker *v1; // rdi
  Scaleform::GFx::Movie *v2; // rbx
  unsigned int v3; // ecx
  int v4; // eax

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::Invoke(v2, "TabMenuWidgetList_ScrollPrev", 0i64, 0i64, 0);
  Scaleform::GFx::Movie::Invoke(v2, "TabMenuWidgetList_UpdateSpacing", 0i64, 0i64, 0);
  v3 = v1->m_eCurrentPage;
  if ( v3 > 3 )
  {
    if ( v3 - 4 > 2 )
    {
      if ( v3 - 7 <= 3 )
      {
        v4 = v3 - 1;
        if ( (signed int)(v3 - 1) < 7 )
          v4 = 10;
        v1->m_eCurrentPage = v4;
      }
    }
    else
    {
      v1->m_eCurrentPage = v3 - 1;
      if ( (signed int)(v3 - 1) < 4 )
        v1->m_eCurrentPage = 6;
    }
  }
  else
  {
    v1->m_eCurrentPage = v3 - 1;
    if ( (signed int)(v3 - 1) < 0 )
      v1->m_eCurrentPage = 3;
  }
}

// File Line: 818
// RVA: 0x623300
bool __usercall UFG::UIHKScreenGameTracker::handleMessage@<al>(UFG::UIHKScreenGameTracker *this@<rcx>, unsigned int msgId@<edx>, UFG::UIMessage *msg@<r8>, float a4@<xmm0>)
{
  UFG::UIMessage *v4; // rbp
  unsigned int v5; // edi
  Scaleform::GFx::Movie *v6; // r14
  UFG::UIHKScreenGameTracker *v7; // rsi
  UFG::HudAudio *v9; // rcx
  const char *v10; // rdx
  UFG::UIScreen *v11; // rax
  UFG::UIHKScreenGlobalOverlay *v12; // rcx

  v4 = msg;
  v5 = msgId;
  v6 = this->mRenderable->m_movie.pObject;
  v7 = this;
  if ( !v6 )
    return 0;
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
    || msgId == UI_HASH_DPAD_DOWN_REPEAT_30 )
  {
    v9 = UFG::HudAudio::m_instance;
    goto LABEL_41;
  }
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30
    || msgId == UI_HASH_DPAD_UP_REPEAT_30 )
  {
    if ( UFG::HudAudio::m_instance )
    {
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x593B70ABu,
        0i64,
        0,
        0i64);
      v10 = "ScrollUp";
      goto LABEL_44;
    }
LABEL_13:
    v10 = "ScrollUp";
LABEL_44:
    Scaleform::GFx::Movie::Invoke(v6, v10, 0i64, 0i64, 0);
    return 1;
  }
  if ( msgId == UI_HASH_MOUSE_WHEEL_SCROLL_30 )
  {
    v9 = UFG::HudAudio::m_instance;
    if ( SLODWORD(msg[1].mPrev) > 0 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x593B70ABu,
          0i64,
          0,
          0i64);
      goto LABEL_13;
    }
LABEL_41:
    if ( v9 )
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v9->vfptr, 0xB78DCE8u, 0i64, 0, 0i64);
    v10 = "ScrollDown";
    goto LABEL_44;
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
    UFG::UIHKScreenGameTracker::HideHelpBar(v7);
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
    UFG::UIHKScreenGameTracker::NextPage(v7);
LABEL_32:
    UFG::UIHKScreenGameTracker::PopulatePage(v7, a4);
    goto LABEL_33;
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
    UFG::UIHKScreenGameTracker::PrevPage(v7);
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
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
    Scaleform::GFx::Movie::Invoke(v6, "TabMenuWidgetList_UpdateSpacing", 0i64, 0i64, 0);
    v7->m_eCurrentPage = UFG::UI::GetFlashArgsInt(v4);
    goto LABEL_32;
  }
LABEL_33:
  v11 = UFG::UIScreenManagerBase::getOverlay(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "GlobalOverlay");
  if ( v11 )
  {
    v12 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v12 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::HandleMessage(&v12->HelpBar, v11, v5, v4);
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v7->vfptr, v5, v4);
}

// File Line: 898
// RVA: 0x60E2C0
void __fastcall UFG::UIHKScreenGameTracker::ShowHelpBar(UFG::UIHKScreenGameTracker *this)
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
    v4 = UFG::qStringHash32("GAMETRACKER", 0xFFFFFFFF);
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

// File Line: 913
// RVA: 0x5ECFB0
void __fastcall UFG::UIHKScreenGameTracker::HideHelpBar(UFG::UIHKScreenGameTracker *this)
{
  UFG::UIHKHelpBarWidget *v1; // rbx
  unsigned int v2; // eax

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v1 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v2 = UFG::qStringHash32("GAMETRACKER", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v1, v2);
  }
}

