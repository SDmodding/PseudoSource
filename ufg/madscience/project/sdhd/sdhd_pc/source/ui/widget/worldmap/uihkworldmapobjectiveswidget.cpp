// File Line: 50
// RVA: 0x612B40
void __fastcall UFG::UIHKWorldMapObjectivesWidget::ToggleOpen(
        UFG::UIHKWorldMapObjectivesWidget *this,
        UFG::UIScreen *screen)
{
  if ( !this->mbToggleDisabled )
  {
    if ( this->mState > (unsigned int)STATE_NORMAL )
    {
      if ( (unsigned int)(this->mState - 2) <= 1 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x9FA93572, 0i64, 0, 0i64);
        if ( (unsigned int)(this->mState - 2) <= 1 )
        {
          this->mState = STATE_INVALID;
          UFG::UIScreen::invoke(screen, "Objectives_Show");
        }
        *(_WORD *)&this->mbIsHiding = 0;
      }
    }
    else
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xD15F2F68, 0i64, 0, 0i64);
      if ( this->mState <= (unsigned int)STATE_NORMAL )
      {
        this->mState = STATE_DANGER;
        UFG::UIScreen::invoke(screen, "Objectives_Hide");
      }
    }
  }
}

// File Line: 106
// RVA: 0x613070
void __fastcall UFG::UIHKWorldMapObjectivesWidget::UnHide(
        UFG::UIHKWorldMapObjectivesWidget *this,
        UFG::UIScreen *screen)
{
  bool v2; // zf
  UFG::UIHKWorldMapObjectivesWidget::eState mState; // eax

  v2 = !this->mbIsHiding;
  this->mbToggleDisabled = 0;
  if ( !v2 )
  {
    mState = this->mState;
    this->mbIsHiding = 0;
    if ( (unsigned int)(mState - 2) <= 1 )
    {
      this->mState = STATE_INVALID;
      UFG::UIScreen::invoke(screen, "Objectives_Show");
    }
    *(_WORD *)&this->mbIsHiding = 0;
  }
}

// File Line: 124
// RVA: 0x5DA270
void __fastcall UFG::UIHKWorldMapObjectivesWidget::Flash_AddObjective(
        UFG::UIHKWorldMapObjectivesWidget *this,
        UFG::UIScreen *screen,
        const char *name,
        bool completed)
{
  const char *v5; // rbx
  Scaleform::GFx::Movie *pObject; // rsi
  Scaleform::GFx::Value::ValueUnion v7; // rdi
  __int64 v8; // rdx
  UFG::UIGfxTranslator *m_translator; // rcx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-68h] BYREF
  char v11[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v12; // [rsp+80h] [rbp-28h]
  int v13; // [rsp+88h] [rbp-20h]
  __int64 v14; // [rsp+90h] [rbp-18h]

  v5 = name;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    if ( name )
    {
      if ( *name == 36 )
        v5 = name + 1;
      v8 = (unsigned int)UFG::qStringHashUpper32(v5, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v7.pString = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v8)) == 0i64 )
        v7.pString = v5;
    }
    else
    {
      v7.pString = 0i64;
    }
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
    ptr.mValue = v7;
    if ( (v13 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v12 + 16i64))(v12, v11, v14);
      v12 = 0i64;
    }
    v13 = 2;
    LOBYTE(v14) = completed;
    Scaleform::GFx::Movie::Invoke(pObject, "Objectives_AddObjective", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 141
// RVA: 0x5DA030
void __fastcall UFG::UIHKWorldMapObjectivesWidget::Flash_AddMission(
        UFG::UIHKWorldMapObjectivesWidget *this,
        UFG::UIScreen *screen,
        const char *name,
        const char *icon)
{
  const char *v5; // rbx
  Scaleform::GFx::Movie *pObject; // rsi
  Scaleform::GFx::Value::ValueUnion v7; // rdi
  __int64 v8; // rdx
  UFG::UIGfxTranslator *m_translator; // rcx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-68h] BYREF
  char v11[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v12; // [rsp+80h] [rbp-28h]
  int v13; // [rsp+88h] [rbp-20h]
  const char *v14; // [rsp+90h] [rbp-18h]

  v5 = name;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    if ( name )
    {
      if ( *name == 36 )
        v5 = name + 1;
      v8 = (unsigned int)UFG::qStringHashUpper32(v5, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v7.pString = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v8)) == 0i64 )
        v7.pString = v5;
    }
    else
    {
      v7.pString = 0i64;
    }
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
    ptr.mValue = v7;
    if ( (v13 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v12 + 16i64))(v12, v11, v14);
      v12 = 0i64;
    }
    v13 = 6;
    v14 = icon;
    Scaleform::GFx::Movie::Invoke(pObject, "Objectives_AddMission", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 158
// RVA: 0x5E1620
void __fastcall UFG::UIHKWorldMapObjectivesWidget::Flash_SetTitle(
        UFG::UIHKWorldMapObjectivesWidget *this,
        UFG::UIScreen *screen,
        const char *text)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_String;
    pargs.mValue.pString = text;
    Scaleform::GFx::Movie::Invoke(pObject, "Objectives_SetTitle", 0i64, &pargs, 1u);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 176
// RVA: 0x5DA3F0
void __fastcall UFG::UIHKWorldMapObjectivesWidget::Flash_CleanObjective(
        UFG::UIHKWorldMapObjectivesWidget *this,
        UFG::UIScreen *screen,
        int numObjectives)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)numObjectives;
    Scaleform::GFx::Movie::Invoke(pObject, "Objectives_CleanObjective", 0i64, &pargs, 1u);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

