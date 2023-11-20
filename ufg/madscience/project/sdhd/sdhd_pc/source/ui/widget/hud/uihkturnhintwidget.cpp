// File Line: 33
// RVA: 0x618380
void __fastcall UFG::UIHKTurnHintWidget::Update(UFG::UIHKTurnHintWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKTurnHintWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  const char *v4; // rsi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]
  UFG::qSymbol icon; // [rsp+98h] [rbp+10h]
  UFG::qSymbol *v7; // [rsp+A0h] [rbp+18h]

  if ( screen )
  {
    v2 = this;
    if ( this->mChanged )
    {
      this->mChanged = 0;
      v3 = screen->mRenderable->m_movie.pObject;
      if ( v3 )
      {
        if ( this->mShouldPlayIntro )
        {
          `eh vector constructor iterator'(
            &pargs,
            0x30ui64,
            1,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          v7 = &icon;
          icon.mUID = v2->mIcon.mUID;
          v4 = UFG::UIHKTurnHintWidget::GetIconName(v2, (__int64)&icon);
          if ( ((unsigned int)pargs.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
              pargs.pObjectInterface,
              &pargs,
              *(_QWORD *)&pargs.mValue.NValue);
            pargs.pObjectInterface = 0i64;
          }
          pargs.Type = 6;
          *(_QWORD *)&pargs.mValue.NValue = v4;
          v2->mShouldPlayIntro = 0;
          Scaleform::GFx::Movie::Invoke(v3, "TurnIndicator_Show", 0i64, &pargs, 1u);
          `eh vector destructor iterator'(
            &pargs,
            0x30ui64,
            1,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        }
        else if ( this->mShouldPlayOutro )
        {
          this->mShouldPlayOutro = 0;
          Scaleform::GFx::Movie::Invoke(v3, "TurnIndicator_Hide", 0i64, 0i64, 0);
        }
      }
    }
  }
}

// File Line: 62
// RVA: 0x60D260
void __fastcall UFG::UIHKTurnHintWidget::Show(UFG::UIHKTurnHintWidget *this, __int64 icon)
{
  unsigned int v2; // eax

  if ( this->mIcon.mUID != *(_DWORD *)icon || this->mVisible != 1 )
  {
    this->mShouldPlayOutro = 0;
    this->mChanged |= 1u;
    this->mShouldPlayIntro = 1;
    this->mIcon.mUID = *(_DWORD *)icon;
    this->mVisible = 1;
  }
  else
  {
    this->mChanged = this->mChanged;
    this->mShouldPlayIntro = 0;
    this->mShouldPlayOutro = 0;
    v2 = *(_DWORD *)icon;
    this->mVisible = 1;
    this->mIcon.mUID = v2;
  }
}

// File Line: 73
// RVA: 0x5ECC40
void __fastcall UFG::UIHKTurnHintWidget::Hide(UFG::UIHKTurnHintWidget *this)
{
  bool v1; // zf

  v1 = this->mVisible == 0;
  this->mShouldPlayIntro = 0;
  this->mVisible = 0;
  this->mChanged |= !v1;
  this->mShouldPlayOutro = !v1;
}

// File Line: 85
// RVA: 0x5E7CB0
const char *__fastcall UFG::UIHKTurnHintWidget::GetIconName(UFG::UIHKTurnHintWidget *this, __int64 icon)
{
  int v2; // eax
  const char *result; // rax
  bool v4; // zf

  v2 = *(_DWORD *)icon;
  if ( *(_DWORD *)icon == UITurnHintIcon_LEFT_TURN_13.mUID )
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

