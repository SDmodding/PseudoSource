// File Line: 24
// RVA: 0x5F4C20
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::Populate(UFG::UIHKWorldMapCollectiblesStatsWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreenRenderable *v2; // rax
  UFG::UIHKWorldMapCollectiblesStatsWidget *v3; // rdi
  Scaleform::GFx::Movie *v4; // rbx
  UFG::GameStatTracker *v5; // rax
  UFG::PersistentData::MapBool *v6; // rax
  int v7; // eax

  if ( screen )
  {
    v2 = screen->mRenderable;
    v3 = this;
    v4 = v2->m_movie.pObject;
    if ( v4 )
    {
      UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateHealthShrine(this, v2->m_movie.pObject);
      UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateLockbox(v3, v4);
      UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateSecurityCamera(v3, v4);
      v5 = UFG::GameStatTracker::Instance();
      v6 = UFG::GameStatTracker::GetMapBool(v5, Collectible_Melee);
      v7 = UFG::PersistentData::MapBool::GetTrueCount(v6);
      UFG::UIHKWorldMapCollectiblesStatsWidget::Populate(v3, v4, "$MAP_COLLECTIBLES_MELEE", v7, 11);
    }
  }
}

// File Line: 40
// RVA: 0x5E1EC0
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::Flash_SetVisible(UFG::UIHKWorldMapCollectiblesStatsWidget *this, UFG::UIScreen *screen, bool visible)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  if ( screen )
  {
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = 2;
      pargs.mValue.BValue = visible;
      Scaleform::GFx::Movie::Invoke(v3, "SetCollectiblesStatsVisible", 0i64, &pargs, 1u);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
    }
  }
}

// File Line: 57
// RVA: 0x5F6F70
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateHealthShrine(UFG::UIHKWorldMapCollectiblesStatsWidget *this, Scaleform::GFx::Movie *movie)
{
  Scaleform::GFx::Movie *v2; // r15
  unsigned int v3; // esi
  int v4; // er14
  signed __int64 v5; // rdi
  UFG::GameStatTracker *v6; // rax
  UFG::PersistentData::MapBool *v7; // rbx
  unsigned int v8; // eax
  UFG::UIGfxTranslator *v9; // rcx
  const char *v10; // rax
  char *v11; // rbx
  UFG::GameStat::MapBoolStat stat; // [rsp+18h] [rbp-59h]
  int v13; // [rsp+1Ch] [rbp-55h]
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-51h]
  char ptr; // [rsp+28h] [rbp-49h]
  __int64 v16; // [rsp+38h] [rbp-39h]
  unsigned int v17; // [rsp+40h] [rbp-31h]
  const char *v18; // [rsp+48h] [rbp-29h]
  char v19; // [rsp+58h] [rbp-19h]
  __int64 v20; // [rsp+68h] [rbp-9h]
  unsigned int v21; // [rsp+70h] [rbp-1h]
  char *v22; // [rsp+78h] [rbp+7h]
  __int64 v23; // [rsp+88h] [rbp+17h]
  UFG::qString v24; // [rsp+90h] [rbp+1Fh]

  v23 = -2i64;
  v2 = movie;
  stat = 23;
  v13 = 24;
  pDtor = (void (__fastcall *)(void *))111669149721i64;
  v3 = 0;
  v4 = 0;
  v5 = 0i64;
  do
  {
    v6 = UFG::GameStatTracker::Instance();
    v7 = UFG::GameStatTracker::GetMapBool(v6, (UFG::GameStat::MapBoolStat)*((_DWORD *)&stat + v5));
    v3 += UFG::PersistentData::MapBool::GetTrueCount(v7);
    v4 += UFG::PersistentData::MapBool::GetCount(v7);
    ++v5;
  }
  while ( v5 < 4 );
  UFG::qString::qString(&v24);
  v8 = UFG::qStringHashUpper32("MAP_COLLECTIBLES_HEALTH", 0xFFFFFFFF);
  v9 = UFG::UIScreenManager::s_instance->m_translator;
  if ( !v9 || (v10 = (const char *)v9->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, v8)) == 0i64 )
    v10 = "MAP_COLLECTIBLES_HEALTH";
  LODWORD(pDtor) = v4;
  UFG::qString::Format(&v24, "%s: %d / %d", v10, v3, pDtor);
  pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v17 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v16 + 16i64))(v16, &ptr, v18);
    v16 = 0i64;
  }
  v17 = 6;
  v18 = asc_1417ECED8;
  v11 = v24.mData;
  if ( (v21 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v20 + 16i64))(v20, &v19, v22);
    v20 = 0i64;
  }
  v21 = 6;
  v22 = v11;
  Scaleform::GFx::Movie::Invoke(v2, "PopulateCollectiblesStats", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v24);
}

// File Line: 82
// RVA: 0x5F9940
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateLockbox(UFG::UIHKWorldMapCollectiblesStatsWidget *this, Scaleform::GFx::Movie *movie)
{
  Scaleform::GFx::Movie *v2; // r12
  signed __int64 v3; // r15
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::MapBool *v5; // rbx
  unsigned int v6; // esi
  int v7; // er14
  char *v8; // rbx
  const char *v9; // rdi
  unsigned int v10; // eax
  UFG::UIGfxTranslator *v11; // rcx
  __int64 v12; // rax
  __int64 v13; // r8
  char *v14; // rbx
  char ptr; // [rsp+18h] [rbp-79h]
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-71h]
  __int64 v17; // [rsp+28h] [rbp-69h]
  UFG::GameStat::MapBoolStat stat; // [rsp+30h] [rbp-61h]
  int v19; // [rsp+34h] [rbp-5Dh]
  char *v20; // [rsp+38h] [rbp-59h]
  char v21; // [rsp+48h] [rbp-49h]
  __int64 v22; // [rsp+58h] [rbp-39h]
  unsigned int v23; // [rsp+60h] [rbp-31h]
  char *v24; // [rsp+68h] [rbp-29h]
  char *str; // [rsp+78h] [rbp-19h]
  const char *v26; // [rsp+80h] [rbp-11h]
  const char *v27; // [rsp+88h] [rbp-9h]
  const char *v28; // [rsp+90h] [rbp-1h]
  UFG::qString v29; // [rsp+98h] [rbp+7h]
  __int64 v30; // [rsp+C0h] [rbp+2Fh]

  v30 = -2i64;
  v2 = movie;
  stat = 27;
  v19 = 28;
  LODWORD(v20) = 29;
  str = "$MAP_COLLECTIBLES_LOCKBOXESAB";
  v26 = "$MAP_COLLECTIBLES_LOCKBOXESCN";
  v27 = "$MAP_COLLECTIBLES_LOCKBOXESKT";
  v28 = "$MAP_COLLECTIBLES_LOCKBOXESNP";
  v3 = 0i64;
  do
  {
    v4 = UFG::GameStatTracker::Instance();
    v5 = UFG::GameStatTracker::GetMapBool(v4, (UFG::GameStat::MapBoolStat)*((_DWORD *)&stat + v3));
    v6 = UFG::PersistentData::MapBool::GetTrueCount(v5);
    v7 = UFG::PersistentData::MapBool::GetCount(v5);
    v8 = (&str)[v3];
    UFG::qString::qString(&v29);
    v9 = v8;
    if ( !v8 )
      goto LABEL_17;
    if ( *v8 == 36 )
      v9 = v8 + 1;
    if ( (v10 = UFG::qStringHashUpper32(v9, 0xFFFFFFFF), (v11 = UFG::UIScreenManager::s_instance->m_translator) != 0i64)
      && (v12 = (__int64)v11->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, v10)) != 0
      || (v12 = (__int64)v9) != 0 )
    {
      v13 = v12;
    }
    else
    {
LABEL_17:
      v13 = (__int64)v8;
    }
    LODWORD(pDtor) = v7;
    UFG::qString::Format(&v29, "%s: %d / %d", v13, v6, pDtor);
    pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)stat >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v17 + 16i64))(v17, &ptr, v20);
      v17 = 0i64;
    }
    stat = 6;
    v20 = v8;
    v14 = v29.mData;
    if ( (v23 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v22 + 16i64))(v22, &v21, v24);
      v22 = 0i64;
    }
    v23 = 6;
    v24 = v14;
    Scaleform::GFx::Movie::Invoke(v2, "PopulateCollectiblesStats", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&v29);
    ++v3;
  }
  while ( v3 < 4 );
}

// File Line: 110
// RVA: 0x5FCD20
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::PopulateSecurityCamera(UFG::UIHKWorldMapCollectiblesStatsWidget *this, Scaleform::GFx::Movie *movie)
{
  Scaleform::GFx::Movie *v2; // rsi
  UFG::UIHKWorldMapCollectiblesStatsWidget *v3; // rbp
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::MapBool *v5; // rbx
  int v6; // edi
  int total; // eax

  v2 = movie;
  v3 = this;
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetMapBool(v4, Collectible_SpyCam);
  v6 = UFG::PersistentData::MapBool::GetTrueCount(v5);
  total = UFG::PersistentData::MapBool::GetCount(v5);
  UFG::UIHKWorldMapCollectiblesStatsWidget::Populate(v3, v2, "$MAP_COLLECTIBLES_CAMERAS", v6, total);
}

// File Line: 130
// RVA: 0x5F4A80
void __fastcall UFG::UIHKWorldMapCollectiblesStatsWidget::Populate(UFG::UIHKWorldMapCollectiblesStatsWidget *this, Scaleform::GFx::Movie *movie, const char *locTitle, int collected, int total)
{
  unsigned int v5; // esi
  const char *v6; // rbx
  Scaleform::GFx::Movie *v7; // rbp
  const char *v8; // rdi
  unsigned int v9; // eax
  UFG::UIGfxTranslator *v10; // rcx
  __int64 v11; // r8
  char *v12; // rbx
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-A8h]
  char ptr; // [rsp+30h] [rbp-98h]
  __int64 v15; // [rsp+40h] [rbp-88h]
  unsigned int v16; // [rsp+48h] [rbp-80h]
  const char *v17; // [rsp+50h] [rbp-78h]
  char v18; // [rsp+60h] [rbp-68h]
  __int64 v19; // [rsp+70h] [rbp-58h]
  unsigned int v20; // [rsp+78h] [rbp-50h]
  char *v21; // [rsp+80h] [rbp-48h]
  UFG::qString v22; // [rsp+90h] [rbp-38h]
  __int64 v23; // [rsp+B8h] [rbp-10h]

  v23 = -2i64;
  v5 = collected;
  v6 = locTitle;
  v7 = movie;
  UFG::qString::qString(&v22);
  v8 = v6;
  if ( !v6 )
    goto LABEL_16;
  if ( *v6 == 36 )
    v8 = v6 + 1;
  v9 = UFG::qStringHashUpper32(v8, 0xFFFFFFFF);
  v10 = UFG::UIScreenManager::s_instance->m_translator;
  if ( !v10 || (v11 = (__int64)v10->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, v9)) == 0 )
    v11 = (__int64)v8;
  if ( !v11 )
LABEL_16:
    v11 = (__int64)v6;
  LODWORD(pDtor) = total;
  UFG::qString::Format(&v22, "%s: %d / %d", v11, v5, pDtor);
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v16 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v15 + 16i64))(v15, &ptr, v17);
    v15 = 0i64;
  }
  v16 = 6;
  v17 = v6;
  v12 = v22.mData;
  if ( (v20 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
    v19 = 0i64;
  }
  v20 = 6;
  v21 = v12;
  Scaleform::GFx::Movie::Invoke(v7, "PopulateCollectiblesStats", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v22);
}

