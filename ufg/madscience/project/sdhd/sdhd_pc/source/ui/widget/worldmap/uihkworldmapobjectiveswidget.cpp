// File Line: 50
// RVA: 0x612B40
void __fastcall UFG::UIHKWorldMapObjectivesWidget::ToggleOpen(UFG::UIHKWorldMapObjectivesWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rsi
  UFG::UIHKWorldMapObjectivesWidget *v3; // rbx

  v2 = screen;
  v3 = this;
  if ( !this->mbToggleDisabled )
  {
    if ( this->mState > 1u )
    {
      if ( (unsigned int)(this->mState - 2) <= 1 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0x9FA93572,
            0i64,
            0,
            0i64);
        if ( (unsigned int)(v3->mState - 2) <= 1 )
        {
          v3->mState = 0;
          UFG::UIScreen::invoke(v2, "Objectives_Show");
        }
        *(_WORD *)&v3->mbIsHiding = 0;
      }
    }
    else
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xD15F2F68,
          0i64,
          0,
          0i64);
      if ( v3->mState <= 1u )
      {
        v3->mState = 2;
        UFG::UIScreen::invoke(v2, "Objectives_Hide");
      }
    }
  }
}

// File Line: 106
// RVA: 0x613070
void __fastcall UFG::UIHKWorldMapObjectivesWidget::UnHide(UFG::UIHKWorldMapObjectivesWidget *this, UFG::UIScreen *screen)
{
  bool v2; // zf
  UFG::UIHKWorldMapObjectivesWidget *v3; // rbx
  UFG::UIHKWorldMapObjectivesWidget::eState v4; // eax

  v2 = this->mbIsHiding == 0;
  v3 = this;
  this->mbToggleDisabled = 0;
  if ( !v2 )
  {
    v4 = this->mState;
    this->mbIsHiding = 0;
    if ( (unsigned int)(v4 - 2) <= 1 )
    {
      this->mState = 0;
      UFG::UIScreen::invoke(screen, "Objectives_Show");
    }
    *(_WORD *)&v3->mbIsHiding = 0;
  }
}

// File Line: 124
// RVA: 0x5DA270
void __fastcall UFG::UIHKWorldMapObjectivesWidget::Flash_AddObjective(UFG::UIHKWorldMapObjectivesWidget *this, UFG::UIScreen *screen, const char *name, bool completed)
{
  bool v4; // bp
  const char *v5; // rbx
  Scaleform::GFx::Movie *v6; // rsi
  __int64 v7; // rdi
  __int64 v8; // rdx
  UFG::UIGfxTranslator *v9; // rcx
  char ptr; // [rsp+40h] [rbp-68h]
  __int64 v11; // [rsp+50h] [rbp-58h]
  unsigned int v12; // [rsp+58h] [rbp-50h]
  __int64 v13; // [rsp+60h] [rbp-48h]
  char v14; // [rsp+70h] [rbp-38h]
  __int64 v15; // [rsp+80h] [rbp-28h]
  unsigned int v16; // [rsp+88h] [rbp-20h]
  __int64 v17; // [rsp+90h] [rbp-18h]

  v4 = completed;
  v5 = name;
  v6 = screen->mRenderable->m_movie.pObject;
  if ( v6 )
  {
    if ( name )
    {
      if ( *name == 36 )
        v5 = name + 1;
      v8 = (unsigned int)UFG::qStringHashUpper32(v5, 0xFFFFFFFF);
      v9 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v9 || (v7 = (__int64)v9->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, v8)) == 0 )
        v7 = (__int64)v5;
    }
    else
    {
      v7 = 0i64;
    }
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v12 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
      v11 = 0i64;
    }
    v12 = 6;
    v13 = v7;
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
      v15 = 0i64;
    }
    v16 = 2;
    LOBYTE(v17) = v4;
    Scaleform::GFx::Movie::Invoke(v6, "Objectives_AddObjective", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 141
// RVA: 0x5DA030
void __fastcall UFG::UIHKWorldMapObjectivesWidget::Flash_AddMission(UFG::UIHKWorldMapObjectivesWidget *this, UFG::UIScreen *screen, const char *name, const char *icon)
{
  const char *v4; // rbp
  const char *v5; // rbx
  Scaleform::GFx::Movie *v6; // rsi
  __int64 v7; // rdi
  __int64 v8; // rdx
  UFG::UIGfxTranslator *v9; // rcx
  char ptr; // [rsp+40h] [rbp-68h]
  __int64 v11; // [rsp+50h] [rbp-58h]
  unsigned int v12; // [rsp+58h] [rbp-50h]
  __int64 v13; // [rsp+60h] [rbp-48h]
  char v14; // [rsp+70h] [rbp-38h]
  __int64 v15; // [rsp+80h] [rbp-28h]
  unsigned int v16; // [rsp+88h] [rbp-20h]
  const char *v17; // [rsp+90h] [rbp-18h]

  v4 = icon;
  v5 = name;
  v6 = screen->mRenderable->m_movie.pObject;
  if ( v6 )
  {
    if ( name )
    {
      if ( *name == 36 )
        v5 = name + 1;
      v8 = (unsigned int)UFG::qStringHashUpper32(v5, 0xFFFFFFFF);
      v9 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v9 || (v7 = (__int64)v9->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, v8)) == 0 )
        v7 = (__int64)v5;
    }
    else
    {
      v7 = 0i64;
    }
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v12 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
      v11 = 0i64;
    }
    v12 = 6;
    v13 = v7;
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
      v15 = 0i64;
    }
    v16 = 6;
    v17 = v4;
    Scaleform::GFx::Movie::Invoke(v6, "Objectives_AddMission", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 158
// RVA: 0x5E1620
void __fastcall UFG::UIHKWorldMapObjectivesWidget::Flash_SetTitle(UFG::UIHKWorldMapObjectivesWidget *this, UFG::UIScreen *screen, const char *text)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = text;
    Scaleform::GFx::Movie::Invoke(v3, "Objectives_SetTitle", 0i64, &pargs, 1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

// File Line: 176
// RVA: 0x5DA3F0
void __fastcall UFG::UIHKWorldMapObjectivesWidget::Flash_CleanObjective(UFG::UIHKWorldMapObjectivesWidget *this, UFG::UIScreen *screen, int numObjectives)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 5;
    pargs.mValue.NValue = (double)numObjectives;
    Scaleform::GFx::Movie::Invoke(v3, "Objectives_CleanObjective", 0i64, &pargs, 1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

