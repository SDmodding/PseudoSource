// File Line: 24
// RVA: 0x5F4C20
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::Populate(
        UFG::UIHKWorldMapCollectiblesStatsWidget *this,
        UFG::UIScreen *screen)
{
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::GameStatTracker *v5; // rax
  UFG::PersistentData::MapBool *MapBool; // rax
  unsigned int TrueCount; // eax

  if ( screen )
  {
    mRenderable = screen->mRenderable;
    pObject = mRenderable->m_movie.pObject;
    if ( pObject )
    {
      UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateHealthShrine(this, mRenderable->m_movie.pObject);
      UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateLockbox(this, pObject);
      UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateSecurityCamera(this, pObject);
      v5 = UFG::GameStatTracker::Instance();
      MapBool = UFG::GameStatTracker::GetMapBool(v5, Collectible_Melee);
      TrueCount = UFG::PersistentData::MapBool::GetTrueCount(MapBool);
      UFG::UIHKWorldMapCollectiblesStatsWidget::Populate(this, pObject, "$MAP_COLLECTIBLES_MELEE", TrueCount, 11);
    }
  }
}

// File Line: 40
// RVA: 0x5E1EC0
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::Flash_SetVisible(
        UFG::UIHKWorldMapCollectiblesStatsWidget *this,
        UFG::UIScreen *screen,
        bool visible)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_Boolean;
      pargs.mValue.BValue = visible;
      Scaleform::GFx::Movie::Invoke(pObject, "SetCollectiblesStatsVisible", 0i64, &pargs, 1u);
      if ( (pargs.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
    }
  }
}

// File Line: 57
// RVA: 0x5F6F70
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateHealthShrine(
        UFG::UIHKWorldMapCollectiblesStatsWidget *this,
        Scaleform::GFx::Movie *movie)
{
  unsigned int v3; // esi
  int v4; // r14d
  __int64 i; // rdi
  UFG::GameStatTracker *v6; // rax
  UFG::PersistentData::MapBool *MapBool; // rbx
  unsigned int v8; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v10; // rax
  char *mData; // rbx
  UFG::GameStat::MapBoolStat stat[2]; // [rsp+18h] [rbp-59h]
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-51h]
  Scaleform::GFx::Value ptr; // [rsp+28h] [rbp-49h] BYREF
  char v15[16]; // [rsp+58h] [rbp-19h] BYREF
  __int64 v16; // [rsp+68h] [rbp-9h]
  int v17; // [rsp+70h] [rbp-1h]
  char *v18; // [rsp+78h] [rbp+7h]
  __int64 v19; // [rsp+88h] [rbp+17h]
  UFG::qString v20; // [rsp+90h] [rbp+1Fh] BYREF

  v19 = -2i64;
  stat[0] = Collectible_HealthShrineAB;
  stat[1] = Collectible_HealthShrineCN;
  pDtor = (void (__fastcall *)(void *))0x1A00000019i64;
  v3 = 0;
  v4 = 0;
  for ( i = 0i64; i < 4; ++i )
  {
    v6 = UFG::GameStatTracker::Instance();
    MapBool = UFG::GameStatTracker::GetMapBool(v6, stat[i]);
    v3 += UFG::PersistentData::MapBool::GetTrueCount(MapBool);
    v4 += UFG::PersistentData::MapBool::GetCount(MapBool);
  }
  UFG::qString::qString(&v20);
  v8 = UFG::qStringHashUpper32("MAP_COLLECTIBLES_HEALTH", -1);
  m_translator = UFG::UIScreenManager::s_instance->m_translator;
  if ( !m_translator || (v10 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v8)) == 0i64 )
    v10 = "MAP_COLLECTIBLES_HEALTH";
  LODWORD(pDtor) = v4;
  UFG::qString::Format(&v20, "%s: %d / %d", v10, v3, pDtor);
  pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
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
  ptr.mValue.pString = "$MAP_COLLECTIBLES_HEALTH";
  mData = v20.mData;
  if ( (v17 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
    v16 = 0i64;
  }
  v17 = 6;
  v18 = mData;
  Scaleform::GFx::Movie::Invoke(movie, "PopulateCollectiblesStats", 0i64, &ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v20);
}

// File Line: 82
// RVA: 0x5F9940
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateLockbox(
        UFG::UIHKWorldMapCollectiblesStatsWidget *this,
        Scaleform::GFx::Movie *movie)
{
  __int64 i; // r15
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::MapBool *MapBool; // rbx
  unsigned int TrueCount; // esi
  int Count; // r14d
  char *v8; // rbx
  const char *v9; // rdi
  unsigned int v10; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  __int64 v12; // rax
  const char *v13; // r8
  char *mData; // rbx
  Scaleform::GFx::Value ptr; // [rsp+18h] [rbp-79h] BYREF
  char v16[16]; // [rsp+48h] [rbp-49h] BYREF
  __int64 v17; // [rsp+58h] [rbp-39h]
  int v18; // [rsp+60h] [rbp-31h]
  char *v19; // [rsp+68h] [rbp-29h]
  char *str[4]; // [rsp+78h] [rbp-19h]
  UFG::qString v21; // [rsp+98h] [rbp+7h] BYREF
  __int64 v22; // [rsp+C0h] [rbp+2Fh]

  v22 = -2i64;
  ptr.Type = VT_Closure|0x10;
  *((_DWORD *)&ptr.Type + 1) = 28;
  ptr.mValue.IValue = 29;
  str[0] = "$MAP_COLLECTIBLES_LOCKBOXESAB";
  str[1] = "$MAP_COLLECTIBLES_LOCKBOXESCN";
  str[2] = "$MAP_COLLECTIBLES_LOCKBOXESKT";
  str[3] = "$MAP_COLLECTIBLES_LOCKBOXESNP";
  for ( i = 0i64; i < 4; ++i )
  {
    v4 = UFG::GameStatTracker::Instance();
    MapBool = UFG::GameStatTracker::GetMapBool(v4, (UFG::GameStat::MapBoolStat)*((_DWORD *)&ptr.Type + i));
    TrueCount = UFG::PersistentData::MapBool::GetTrueCount(MapBool);
    Count = UFG::PersistentData::MapBool::GetCount(MapBool);
    v8 = str[i];
    UFG::qString::qString(&v21);
    v9 = v8;
    if ( !v8 )
      goto LABEL_9;
    if ( *v8 == 36 )
      v9 = v8 + 1;
    if ( (v10 = UFG::qStringHashUpper32(v9, -1), (m_translator = UFG::UIScreenManager::s_instance->m_translator) != 0i64)
      && (v12 = (__int64)m_translator->vfptr[5].__vecDelDtor(m_translator, v10)) != 0
      || (v12 = (__int64)v9) != 0 )
    {
      v13 = (const char *)v12;
    }
    else
    {
LABEL_9:
      v13 = v8;
    }
    LODWORD(ptr.pNext) = Count;
    UFG::qString::Format(&v21, "%s: %d / %d", v13, TrueCount, ptr.pNext);
    ptr.pNext = (Scaleform::GFx::Value *)Scaleform::GFx::Value::~Value;
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
    ptr.mValue.pString = v8;
    mData = v21.mData;
    if ( (v18 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v17 + 16i64))(v17, v16, v19);
      v17 = 0i64;
    }
    v18 = 6;
    v19 = mData;
    Scaleform::GFx::Movie::Invoke(movie, "PopulateCollectiblesStats", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&v21);
  }
}

// File Line: 110
// RVA: 0x5FCD20
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateSecurityCamera(
        UFG::UIHKWorldMapCollectiblesStatsWidget *this,
        Scaleform::GFx::Movie *movie)
{
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::MapBool *MapBool; // rbx
  unsigned int TrueCount; // edi
  int total; // eax

  v4 = UFG::GameStatTracker::Instance();
  MapBool = UFG::GameStatTracker::GetMapBool(v4, Collectible_SpyCam);
  TrueCount = UFG::PersistentData::MapBool::GetTrueCount(MapBool);
  total = UFG::PersistentData::MapBool::GetCount(MapBool);
  UFG::UIHKWorldMapCollectiblesStatsWidget::Populate(this, movie, "$MAP_COLLECTIBLES_CAMERAS", TrueCount, total);
}

// File Line: 130
// RVA: 0x5F4A80
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::Populate(
        UFG::UIHKWorldMapCollectiblesStatsWidget *this,
        Scaleform::GFx::Movie *movie,
        const char *locTitle,
        unsigned int collected,
        int total)
{
  const char *v8; // rdi
  unsigned int v9; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v11; // r8
  char *mData; // rbx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-98h] BYREF
  char v14[16]; // [rsp+60h] [rbp-68h] BYREF
  __int64 v15; // [rsp+70h] [rbp-58h]
  int v16; // [rsp+78h] [rbp-50h]
  char *v17; // [rsp+80h] [rbp-48h]
  UFG::qString v18; // [rsp+90h] [rbp-38h] BYREF
  __int64 v19; // [rsp+B8h] [rbp-10h]

  v19 = -2i64;
  UFG::qString::qString(&v18);
  v8 = locTitle;
  if ( !locTitle )
    goto LABEL_8;
  if ( *locTitle == 36 )
    v8 = locTitle + 1;
  v9 = UFG::qStringHashUpper32(v8, -1);
  m_translator = UFG::UIScreenManager::s_instance->m_translator;
  if ( !m_translator || (v11 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v9)) == 0i64 )
    v11 = v8;
  if ( !v11 )
LABEL_8:
    v11 = locTitle;
  UFG::qString::Format(&v18, "%s: %d / %d", v11, collected, total);
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
  ptr.mValue.pString = locTitle;
  mData = v18.mData;
  if ( (v16 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v15 + 16i64))(v15, v14, v17);
    v15 = 0i64;
  }
  v16 = 6;
  v17 = mData;
  Scaleform::GFx::Movie::Invoke(movie, "PopulateCollectiblesStats", 0i64, &ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v18);
}

