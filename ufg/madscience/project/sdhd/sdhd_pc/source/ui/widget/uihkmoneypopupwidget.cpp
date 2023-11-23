// File Line: 48
// RVA: 0x615290
void __fastcall UFG::UIHKMoneyPopupWidget::Update(
        UFG::UIHKMoneyPopupWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  int mMoney; // r15d
  UFG::GameStatTracker *v6; // rax
  int Stat; // esi
  int v8; // eax
  Scaleform::GFx::Movie *pObject; // rbp
  bool mLeaveOn; // r14
  Scaleform::GFx::Movie *v11; // rcx
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-50h] BYREF

  mMoney = this->mMoney;
  v6 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v6, Money);
  v8 = this->mMoney;
  if ( Stat != v8 )
    goto LABEL_4;
  if ( !this->mForceShow )
    return;
  if ( Stat != v8 )
  {
LABEL_4:
    this->mTimerActive = 1;
    this->mHideTimer = 6.0;
  }
  this->mForceShow = 0;
  this->mMoney = Stat;
  if ( this->mLeaveOnChanged )
  {
    this->mLeaveOnChanged = 0;
    if ( !screen )
      return;
    pObject = screen->mRenderable->m_movie.pObject;
    if ( !pObject )
      return;
    value.pObjectInterface = 0i64;
    value.Type = VT_Undefined;
    mLeaveOn = this->mLeaveOn;
    value.Type = VT_Boolean;
    value.mValue.BValue = mLeaveOn;
    Scaleform::GFx::Movie::SetVariable(pObject, "gMoneyStayOn", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Undefined;
  }
  if ( !this->mIsVisible )
  {
    if ( !this->mTryToHide )
      UFG::UIHKMoneyPopupWidget::Flash_Show(this, screen, mMoney, Stat);
    if ( !this->mIsVisible )
      goto LABEL_20;
  }
  if ( this->mTryToHide )
  {
    if ( screen )
    {
      v11 = screen->mRenderable->m_movie.pObject;
      if ( v11 )
      {
        this->mIsVisible = 0;
        Scaleform::GFx::Movie::Invoke(v11, "MoneyPopup_Hide", 0i64, 0i64, 0);
      }
    }
    *(_WORD *)&this->mLeaveOnChanged = 1;
    this->mLeaveOn = 0;
  }
  else
  {
LABEL_20:
    this->mTryToHide = 0;
  }
}

// File Line: 143
// RVA: 0x5E3280
void __fastcall UFG::UIHKMoneyPopupWidget::Flash_Show(
        UFG::UIHKMoneyPopupWidget *this,
        UFG::UIScreen *screen,
        int oldMoney,
        int newMoney)
{
  Scaleform::GFx::Movie *pObject; // rsi
  UFG::HudAudio *v7; // rcx
  unsigned int v8; // edx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h] BYREF
  char v10[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v11; // [rsp+80h] [rbp-28h]
  int v12; // [rsp+88h] [rbp-20h]
  double v13; // [rsp+90h] [rbp-18h]

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      this->mIsVisible = 1;
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
      pargs.mValue.NValue = (double)oldMoney;
      if ( (v12 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
          v11,
          v10,
          COERCE_DOUBLE(*(_QWORD *)&v13));
        v11 = 0i64;
      }
      v12 = 5;
      v13 = (double)newMoney;
      Scaleform::GFx::Movie::Invoke(pObject, "MoneyPopup_Show", 0i64, &pargs, 2u);
      if ( oldMoney >= newMoney )
      {
        if ( oldMoney <= newMoney )
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
          `eh vector destructor iterator(
            &pargs,
            0x30ui64,
            2,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          return;
        }
        v8 = -351352389;
      }
      UFG::AudioEntity::CreateAndPlayEvent(v7, v8, 0i64, 0, 0i64);
      goto LABEL_14;
    }
  }
}

