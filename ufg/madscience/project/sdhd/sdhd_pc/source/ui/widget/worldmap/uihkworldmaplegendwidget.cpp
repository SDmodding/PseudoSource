// File Line: 42
// RVA: 0x6191D0
void __fastcall UFG::UIHKWorldMapLegendWidget::Update(UFG::UIHKWorldMapLegendWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rdi
  UFG::UIHKWorldMapLegendWidget *v3; // rbx
  bool v4; // zf
  Scaleform::GFx::Movie *v5; // rcx
  Scaleform::GFx::Movie *v6; // rcx
  Scaleform::GFx::Movie *v7; // rcx

  if ( screen )
  {
    v2 = screen;
    v3 = this;
    if ( this->mChanged )
    {
      v4 = this->mToggleFadeIn == 0;
      this->mChanged = 0;
      if ( v4 )
      {
        if ( this->mToggleFadeOut )
        {
          this->mToggleFadeOut = 0;
          v6 = screen->mRenderable->m_movie.pObject;
          if ( v6 )
            Scaleform::GFx::Movie::Invoke(v6, "Legend_FadeOut", 0i64, 0i64, 0);
        }
        else if ( this->mToggleOpen )
        {
          v4 = this->mState == 5;
          this->mToggleOpen = 0;
          if ( v4 )
          {
            this->mState = 6;
            UFG::UIHKWorldMapLegendWidget::Flash_Close(this, screen);
          }
          else
          {
            this->mState = 4;
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
      if ( v3->mTerritoryMode )
      {
        v7 = v2->mRenderable->m_movie.pObject;
        if ( v7 )
          Scaleform::GFx::Movie::Invoke(v7, "Legend_Clear", 0i64, 0i64, 0);
      }
      UFG::UIHKWorldMapLegendWidget::Flash_SetTerritoryLegendVisible(v3, v2, v3->mTerritoryMode);
    }
  }
}

// File Line: 98
// RVA: 0x5D9F00
void __fastcall UFG::UIHKWorldMapLegendWidget::Flash_AddItem(UFG::UIHKWorldMapLegendWidget *this, UFG::UIScreen *screen, const char *icon, const char *caption)
{
  const char *v4; // rsi
  const char *v5; // rdi
  Scaleform::GFx::Movie *v6; // rbx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h]
  char v8; // [rsp+70h] [rbp-38h]
  __int64 v9; // [rsp+80h] [rbp-28h]
  unsigned int v10; // [rsp+88h] [rbp-20h]
  const char *v11; // [rsp+90h] [rbp-18h]

  v4 = caption;
  v5 = icon;
  v6 = screen->mRenderable->m_movie.pObject;
  if ( v6 )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v5;
    if ( (v10 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v9 + 16i64))(v9, &v8, v11);
      v9 = 0i64;
    }
    v10 = 6;
    v11 = v4;
    Scaleform::GFx::Movie::Invoke(v6, "Legend_AddItem", 0i64, &pargs, 2u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 143
// RVA: 0x612AD0
void __fastcall UFG::UIHKWorldMapLegendWidget::ToggleOpen(UFG::UIHKWorldMapLegendWidget *this)
{
  UFG::UIHKWorldMapLegendWidget *v1; // rbx
  bool v2; // zf

  v1 = this;
  if ( this->mState == 5 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xD15F2F68,
        0i64,
        0,
        0i64);
    v2 = v1->mState == 5;
  }
  else
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x9FA93572,
        0i64,
        0,
        0i64);
    v2 = v1->mState == 3;
  }
  if ( v2 )
    *(_WORD *)&v1->mChanged = 257;
}

// File Line: 212
// RVA: 0x5DE5D0
void __fastcall UFG::UIHKWorldMapLegendWidget::Flash_Open(UFG::UIHKWorldMapLegendWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rcx

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 )
    Scaleform::GFx::Movie::Invoke(v2, "Legend_Open", 0i64, 0i64, 0);
}

// File Line: 222
// RVA: 0x5DA4C0
void __fastcall UFG::UIHKWorldMapLegendWidget::Flash_Close(UFG::UIHKWorldMapLegendWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rcx

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 )
    Scaleform::GFx::Movie::Invoke(v2, "Legend_Close", 0i64, 0i64, 0);
}

// File Line: 253
// RVA: 0x5E1110
void __fastcall UFG::UIHKWorldMapLegendWidget::Flash_SetTerritoryLegendVisible(UFG::UIHKWorldMapLegendWidget *this, UFG::UIScreen *screen, bool visible)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = visible;
    Scaleform::GFx::Movie::SetVariable(v3, "legend_mc.inner.mc_TerritoryLegend._visible", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 265
// RVA: 0x5E02B0
void __fastcall UFG::UIHKWorldMapLegendWidget::Flash_SetLegendPageNumbers(UFG::UIHKWorldMapLegendWidget *this, UFG::UIScreen *screen, int pageNumber, int totalPageNumbers)
{
  int v4; // esi
  int v5; // edi
  Scaleform::GFx::Movie *v6; // rbx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h]
  char v8; // [rsp+70h] [rbp-38h]
  __int64 v9; // [rsp+80h] [rbp-28h]
  unsigned int v10; // [rsp+88h] [rbp-20h]
  double v11; // [rsp+90h] [rbp-18h]

  v4 = totalPageNumbers;
  v5 = pageNumber;
  v6 = screen->mRenderable->m_movie.pObject;
  if ( v6 )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v5;
    if ( (v10 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, &v8, COERCE_DOUBLE(*(_QWORD *)&v11));
      v9 = 0i64;
    }
    v10 = 5;
    v11 = (double)v4;
    Scaleform::GFx::Movie::Invoke(v6, "Legend_SetPageNumbers", 0i64, &pargs, 2u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

