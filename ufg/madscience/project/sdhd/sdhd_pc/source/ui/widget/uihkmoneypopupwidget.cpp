// File Line: 48
// RVA: 0x615290
void __fastcall UFG::UIHKMoneyPopupWidget::Update(UFG::UIHKMoneyPopupWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // rdi
  UFG::UIHKMoneyPopupWidget *v4; // rbx
  int v5; // er15
  UFG::GameStatTracker *v6; // rax
  int v7; // esi
  int v8; // eax
  Scaleform::GFx::Movie *v9; // rbp
  bool v10; // r14
  Scaleform::GFx::Movie *v11; // rcx
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-50h]

  v3 = screen;
  v4 = this;
  v5 = this->mMoney;
  v6 = UFG::GameStatTracker::Instance();
  v7 = UFG::GameStatTracker::GetStat(v6, Money);
  v8 = v4->mMoney;
  if ( v7 != v8 )
    goto LABEL_25;
  if ( !v4->mForceShow )
    return;
  if ( v7 != v8 )
  {
LABEL_25:
    v4->mTimerActive = 1;
    v4->mHideTimer = 6.0;
  }
  v4->mForceShow = 0;
  v4->mMoney = v7;
  if ( v4->mLeaveOnChanged )
  {
    v4->mLeaveOnChanged = 0;
    if ( !v3 )
      return;
    v9 = v3->mRenderable->m_movie.pObject;
    if ( !v9 )
      return;
    value.pObjectInterface = 0i64;
    value.Type = 0;
    v10 = v4->mLeaveOn;
    value.Type = 2;
    value.mValue.BValue = v10;
    Scaleform::GFx::Movie::SetVariable(v9, "gMoneyStayOn", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 0;
  }
  if ( !v4->mIsVisible )
  {
    if ( !v4->mTryToHide )
      UFG::UIHKMoneyPopupWidget::Flash_Show(v4, v3, v5, v7);
    if ( !v4->mIsVisible )
      goto LABEL_26;
  }
  if ( v4->mTryToHide )
  {
    if ( v3 )
    {
      v11 = v3->mRenderable->m_movie.pObject;
      if ( v11 )
      {
        v4->mIsVisible = 0;
        Scaleform::GFx::Movie::Invoke(v11, "MoneyPopup_Hide", 0i64, 0i64, 0);
      }
    }
    *(_WORD *)&v4->mLeaveOnChanged = 1;
    v4->mLeaveOn = 0;
  }
  else
  {
LABEL_26:
    v4->mTryToHide = 0;
  }
}

// File Line: 143
// RVA: 0x5E3280
void __fastcall UFG::UIHKMoneyPopupWidget::Flash_Show(UFG::UIHKMoneyPopupWidget *this, UFG::UIScreen *screen, int oldMoney, int newMoney)
{
  int v4; // edi
  int v5; // ebx
  Scaleform::GFx::Movie *v6; // rsi
  UFG::HudAudio *v7; // rcx
  unsigned int v8; // edx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h]
  char v10; // [rsp+70h] [rbp-38h]
  __int64 v11; // [rsp+80h] [rbp-28h]
  unsigned int v12; // [rsp+88h] [rbp-20h]
  double v13; // [rsp+90h] [rbp-18h]

  if ( screen )
  {
    v4 = newMoney;
    v5 = oldMoney;
    v6 = screen->mRenderable->m_movie.pObject;
    if ( v6 )
    {
      this->mIsVisible = 1;
      `eh vector constructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
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
      if ( (v12 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
          v11,
          &v10,
          COERCE_DOUBLE(*(_QWORD *)&v13));
        v11 = 0i64;
      }
      v12 = 5;
      v13 = (double)v4;
      Scaleform::GFx::Movie::Invoke(v6, "MoneyPopup_Show", 0i64, &pargs, 2u);
      if ( v5 >= v4 )
      {
        if ( v5 <= v4 )
          goto LABEL_14;
        v7 = UFG::HudAudio::m_instance;
        if ( !UFG::HudAudio::m_instance )
          goto LABEL_14;
        v8 = -1707768979;
      }
      else
      {
        v7 = UFG::HudAudio::m_instance;
        if ( !UFG::HudAudio::m_instance )
        {
LABEL_14:
          `eh vector destructor iterator'(
            &pargs,
            0x30ui64,
            2,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          return;
        }
        v8 = -351352389;
      }
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v7->vfptr, v8, 0i64, 0, 0i64);
      goto LABEL_14;
    }
  }
}

