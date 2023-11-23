// File Line: 33
// RVA: 0x618380
void __fastcall UFG::UIHKTurnHintWidget::Update(UFG::UIHKTurnHintWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rdi
  const char *IconName; // rsi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF
  UFG::qSymbol icon; // [rsp+98h] [rbp+10h] BYREF
  UFG::qSymbol *p_icon; // [rsp+A0h] [rbp+18h]

  if ( screen )
  {
    if ( this->mChanged )
    {
      this->mChanged = 0;
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
      {
        if ( this->mShouldPlayIntro )
        {
          `eh vector constructor iterator(
            &pargs,
            0x30ui64,
            1,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          p_icon = &icon;
          icon.mUID = this->mIcon.mUID;
          IconName = UFG::UIHKTurnHintWidget::GetIconName(this, (int *)&icon);
          if ( (pargs.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
              pargs.pObjectInterface,
              &pargs,
              pargs.mValue);
            pargs.pObjectInterface = 0i64;
          }
          pargs.Type = VT_String;
          pargs.mValue.pString = IconName;
          this->mShouldPlayIntro = 0;
          Scaleform::GFx::Movie::Invoke(pObject, "TurnIndicator_Show", 0i64, &pargs, 1u);
          `eh vector destructor iterator(
            &pargs,
            0x30ui64,
            1,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        }
        else if ( this->mShouldPlayOutro )
        {
          this->mShouldPlayOutro = 0;
          Scaleform::GFx::Movie::Invoke(pObject, "TurnIndicator_Hide", 0i64, 0i64, 0);
        }
      }
    }
  }
}

// File Line: 62
// RVA: 0x60D260
void __fastcall UFG::UIHKTurnHintWidget::Show(UFG::UIHKTurnHintWidget *this, unsigned int *icon)
{
  unsigned int v2; // eax

  if ( this->mIcon.mUID == *icon && this->mVisible )
  {
    this->mChanged = this->mChanged;
    this->mShouldPlayIntro = 0;
    this->mShouldPlayOutro = 0;
    v2 = *icon;
    this->mVisible = 1;
    this->mIcon.mUID = v2;
  }
  else
  {
    this->mShouldPlayOutro = 0;
    this->mChanged |= 1u;
    this->mShouldPlayIntro = 1;
    this->mIcon.mUID = *icon;
    this->mVisible = 1;
  }
}

// File Line: 73
// RVA: 0x5ECC40
void __fastcall UFG::UIHKTurnHintWidget::Hide(UFG::UIHKTurnHintWidget *this)
{
  bool v1; // zf

  v1 = !this->mVisible;
  this->mShouldPlayIntro = 0;
  this->mVisible = 0;
  this->mChanged |= !v1;
  this->mShouldPlayOutro = !v1;
}

// File Line: 85
// RVA: 0x5E7CB0
const char *__fastcall UFG::UIHKTurnHintWidget::GetIconName(UFG::UIHKTurnHintWidget *this, int *icon)
{
  int v2; // eax
  const char *result; // rax
  bool v4; // zf

  v2 = *icon;
  if ( *icon == UITurnHintIcon_LEFT_TURN_13.mUID )
    return "LeftTurn";
  if ( v2 == UITurnHintIcon_RIGHT_TURN_13.mUID )
    return "RightTurn";
  if ( v2 == UITurnHintIcon_U_TURN_LEFT_13.mUID )
    return "UTurnLeft";
  if ( v2 == UITurnHintIcon_U_TURN_RIGHT_13.mUID )
    return "UTurnRight";
  if ( v2 == UITurnHintIcon_ZIG_ZAG_13.mUID )
    return "ZigZag";
  v4 = v2 == UITurnHintIcon_NEXT_EXIT_13.mUID;
  result = "NextExit";
  if ( !v4 )
    return "LeftTurn";
  return result;
}

