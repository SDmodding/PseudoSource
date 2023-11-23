// File Line: 42
// RVA: 0x6191D0
void __fastcall UFG::UIHKWorldMapLegendWidget::Update(UFG::UIHKWorldMapLegendWidget *this, UFG::UIScreen *screen)
{
  bool v4; // zf
  Scaleform::GFx::Movie *v5; // rcx
  Scaleform::GFx::Movie *pObject; // rcx
  Scaleform::GFx::Movie *v7; // rcx

  if ( screen && this->mChanged )
  {
    v4 = !this->mToggleFadeIn;
    this->mChanged = 0;
    if ( v4 )
    {
      if ( this->mToggleFadeOut )
      {
        this->mToggleFadeOut = 0;
        pObject = screen->mRenderable->m_movie.pObject;
        if ( pObject )
          Scaleform::GFx::Movie::Invoke(pObject, "Legend_FadeOut", 0i64, 0i64, 0);
      }
      else if ( this->mToggleOpen )
      {
        v4 = this->mState == STATE_ANIMATE_COMPLETE;
        this->mToggleOpen = 0;
        if ( v4 )
        {
          this->mState = NUM_STATES;
          UFG::UIHKWorldMapLegendWidget::Flash_Close(this, screen);
        }
        else
        {
          this->mState = STATE_INCOMPLETE;
          UFG::UIHKWorldMapLegendWidget::Flash_Open(this, screen);
        }
      }
    }
    else
    {
      this->mToggleFadeIn = 0;
      v5 = screen->mRenderable->m_movie.pObject;
      if ( v5 )
        Scaleform::GFx::Movie::Invoke(v5, "Legend_FadeIn", 0i64, 0i64, 0);
    }
    if ( this->mTerritoryMode )
    {
      v7 = screen->mRenderable->m_movie.pObject;
      if ( v7 )
        Scaleform::GFx::Movie::Invoke(v7, "Legend_Clear", 0i64, 0i64, 0);
    }
    UFG::UIHKWorldMapLegendWidget::Flash_SetTerritoryLegendVisible(this, screen, this->mTerritoryMode);
  }
}

// File Line: 98
// RVA: 0x5D9F00
void __fastcall UFG::UIHKWorldMapLegendWidget::Flash_AddItem(
        UFG::UIHKWorldMapLegendWidget *this,
        UFG::UIScreen *screen,
        const char *icon,
        const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h] BYREF
  char v8[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v9; // [rsp+80h] [rbp-28h]
  int v10; // [rsp+88h] [rbp-20h]
  const char *v11; // [rsp+90h] [rbp-18h]

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_String;
    pargs.mValue.pString = icon;
    if ( (v10 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v9 + 16i64))(v9, v8, v11);
      v9 = 0i64;
    }
    v10 = 6;
    v11 = caption;
    Scaleform::GFx::Movie::Invoke(pObject, "Legend_AddItem", 0i64, &pargs, 2u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 143
// RVA: 0x612AD0
void __fastcall UFG::UIHKWorldMapLegendWidget::ToggleOpen(UFG::UIHKWorldMapLegendWidget *this)
{
  bool v2; // zf

  if ( this->mState == STATE_ANIMATE_COMPLETE )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xD15F2F68, 0i64, 0, 0i64);
    v2 = this->mState == STATE_ANIMATE_COMPLETE;
  }
  else
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x9FA93572, 0i64, 0, 0i64);
    v2 = this->mState == STATE_COMPLETE;
  }
  if ( v2 )
    *(_WORD *)&this->mChanged = 257;
}

// File Line: 212
// RVA: 0x5DE5D0
void __fastcall UFG::UIHKWorldMapLegendWidget::Flash_Open(UFG::UIHKWorldMapLegendWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "Legend_Open", 0i64, 0i64, 0);
}

// File Line: 222
// RVA: 0x5DA4C0
void __fastcall UFG::UIHKWorldMapLegendWidget::Flash_Close(UFG::UIHKWorldMapLegendWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "Legend_Close", 0i64, 0i64, 0);
}

// File Line: 253
// RVA: 0x5E1110
void __fastcall UFG::UIHKWorldMapLegendWidget::Flash_SetTerritoryLegendVisible(
        UFG::UIHKWorldMapLegendWidget *this,
        UFG::UIScreen *screen,
        bool visible)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = visible;
    Scaleform::GFx::Movie::SetVariable(pObject, "legend_mc.inner.mc_TerritoryLegend._visible", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 265
// RVA: 0x5E02B0
void __fastcall UFG::UIHKWorldMapLegendWidget::Flash_SetLegendPageNumbers(
        UFG::UIHKWorldMapLegendWidget *this,
        UFG::UIScreen *screen,
        int pageNumber,
        int totalPageNumbers)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h] BYREF
  char v8[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v9; // [rsp+80h] [rbp-28h]
  int v10; // [rsp+88h] [rbp-20h]
  double v11; // [rsp+90h] [rbp-18h]

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)pageNumber;
    if ( (v10 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, v8, COERCE_DOUBLE(*(_QWORD *)&v11));
      v9 = 0i64;
    }
    v10 = 5;
    v11 = (double)totalPageNumbers;
    Scaleform::GFx::Movie::Invoke(pObject, "Legend_SetPageNumbers", 0i64, &pargs, 2u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

