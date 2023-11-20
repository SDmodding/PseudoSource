// File Line: 35
// RVA: 0x6166A0
void __fastcall UFG::UIHKRaceTimerWidget::Update(UFG::UIHKRaceTimerWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rdi
  UFG::UIHKRaceTimerWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // rcx
  const char *v5; // rdx

  if ( screen )
  {
    v2 = screen;
    v3 = this;
    if ( this->mTimeChanged )
    {
      UFG::UIHKRaceTimerWidget::Flash_SetTimer(this, screen);
      v3->mTimeChanged = 0;
    }
    if ( v3->mVisibilityChanged )
    {
      v4 = v2->mRenderable->m_movie.pObject;
      if ( v4 )
      {
        v5 = "Race_LoadRaceHUD";
        if ( !v3->mVisible )
          v5 = "Race_UnloadRaceHUD";
        Scaleform::GFx::Movie::Invoke(v4, v5, 0i64, 0i64, 0);
      }
      v3->mVisibilityChanged = 0;
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
void __fastcall UFG::UIHKRaceTimerWidget::SetTime(UFG::UIHKRaceTimerWidget *this, unsigned int minutes, unsigned int seconds, unsigned int thousandths)
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
  UFG::UIScreen *v2; // rdi
  UFG::UIHKRaceTimerWidget *v3; // rbx
  double v4; // xmm6_8
  double v5; // xmm6_8
  double v6; // xmm6_8
  Scaleform::GFx::Movie *v7; // rcx
  char ptr; // [rsp+28h] [rbp-59h]
  __int64 v9; // [rsp+30h] [rbp-51h]
  __int64 v10; // [rsp+38h] [rbp-49h]
  unsigned int v11; // [rsp+40h] [rbp-41h]
  double v12; // [rsp+48h] [rbp-39h]
  char v13; // [rsp+58h] [rbp-29h]
  __int64 v14; // [rsp+68h] [rbp-19h]
  unsigned int v15; // [rsp+70h] [rbp-11h]
  double v16; // [rsp+78h] [rbp-9h]
  char v17; // [rsp+88h] [rbp+7h]
  __int64 v18; // [rsp+98h] [rbp+17h]
  unsigned int v19; // [rsp+A0h] [rbp+1Fh]
  double v20; // [rsp+A8h] [rbp+27h]
  __int64 v21; // [rsp+B8h] [rbp+37h]

  v21 = -2i64;
  v2 = screen;
  v3 = this;
  `eh vector constructor iterator(&v9, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4 = (double)(signed int)v3->mMinutes;
  if ( (v11 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(
      v10,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v12));
    v10 = 0i64;
  }
  v11 = 5;
  v12 = v4;
  v5 = (double)(signed int)v3->mSeconds;
  if ( (v15 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v14 + 16i64))(
      v14,
      &v13,
      COERCE_DOUBLE(*(_QWORD *)&v16));
    v14 = 0i64;
  }
  v15 = 5;
  v16 = v5;
  v6 = (double)(signed int)v3->mThousandths;
  if ( (v19 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v18 + 16i64))(
      v18,
      &v17,
      COERCE_DOUBLE(*(_QWORD *)&v20));
    v18 = 0i64;
  }
  v19 = 5;
  v20 = v6;
  v7 = v2->mRenderable->m_movie.pObject;
  if ( v7 )
    Scaleform::GFx::Movie::Invoke(v7, "Race_SetTimer", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

