// File Line: 35
// RVA: 0x6166A0
void __fastcall UFG::UIHKRaceTimerWidget::Update(UFG::UIHKRaceTimerWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx
  const char *v5; // rdx

  if ( screen )
  {
    if ( this->mTimeChanged )
    {
      UFG::UIHKRaceTimerWidget::Flash_SetTimer(this, screen);
      this->mTimeChanged = 0;
    }
    if ( this->mVisibilityChanged )
    {
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
      {
        v5 = "Race_LoadRaceHUD";
        if ( !this->mVisible )
          v5 = "Race_UnloadRaceHUD";
        Scaleform::GFx::Movie::Invoke(pObject, v5, 0i64, 0i64, 0);
      }
      this->mVisibilityChanged = 0;
    }
  }
}

// File Line: 55
// RVA: 0x60C650
void __fastcall UFG::UIHKRaceTimerWidget::SetVisible(UFG::UIHKRaceTimerWidget *this, bool visible)
{
  bool v2; // zf

  v2 = this->mVisible == visible;
  this->mVisible = visible;
  this->mVisibilityChanged |= !v2;
}

// File Line: 62
// RVA: 0x60A0C0
void __fastcall UFG::UIHKRaceTimerWidget::SetTime(
        UFG::UIHKRaceTimerWidget *this,
        unsigned int minutes,
        unsigned int seconds,
        unsigned int thousandths)
{
  this->mTimeChanged = 1;
  this->mMinutes = minutes;
  this->mSeconds = seconds;
  this->mThousandths = thousandths;
}

// File Line: 85
// RVA: 0x5E14B0
void __fastcall UFG::UIHKRaceTimerWidget::Flash_SetTimer(UFG::UIHKRaceTimerWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Value::ValueUnion v4; // xmm6_8
  double mSeconds; // xmm6_8
  double mThousandths; // xmm6_8
  Scaleform::GFx::Movie *pObject; // rcx
  Scaleform::GFx::Value ptr; // [rsp+28h] [rbp-59h] BYREF
  char v9[16]; // [rsp+58h] [rbp-29h] BYREF
  __int64 v10; // [rsp+68h] [rbp-19h]
  int v11; // [rsp+70h] [rbp-11h]
  double v12; // [rsp+78h] [rbp-9h]
  char v13[16]; // [rsp+88h] [rbp+7h] BYREF
  __int64 v14; // [rsp+98h] [rbp+17h]
  int v15; // [rsp+A0h] [rbp+1Fh]
  double v16; // [rsp+A8h] [rbp+27h]
  __int64 v17; // [rsp+B8h] [rbp+37h]

  v17 = -2i64;
  `eh vector constructor iterator(&ptr.8, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4.NValue = (double)(int)this->mMinutes;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue = v4;
  mSeconds = (double)(int)this->mSeconds;
  if ( (v11 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(v10, v9, COERCE_DOUBLE(*(_QWORD *)&v12));
    v10 = 0i64;
  }
  v11 = 5;
  v12 = mSeconds;
  mThousandths = (double)(int)this->mThousandths;
  if ( (v15 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v14 + 16i64))(v14, v13, COERCE_DOUBLE(*(_QWORD *)&v16));
    v14 = 0i64;
  }
  v15 = 5;
  v16 = mThousandths;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "Race_SetTimer", 0i64, &ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

