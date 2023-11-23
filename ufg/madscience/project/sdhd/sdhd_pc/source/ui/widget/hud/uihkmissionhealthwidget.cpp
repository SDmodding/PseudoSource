// File Line: 29
// RVA: 0x614B50
void __fastcall UFG::UIHKMissionHealthWidget::Update(UFG::UIHKMissionHealthWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rdi
  bool mVisible; // si
  Scaleform::GFx::Value::ValueUnion v5; // xmm6_8
  char *mData; // rsi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-48h] BYREF

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_Undefined;
      if ( this->mVisibleChanged )
      {
        this->mVisibleChanged = 0;
        mVisible = this->mVisible;
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = VT_Boolean;
        pargs.mValue.BValue = mVisible;
        Scaleform::GFx::Movie::Invoke(pObject, "MissionHealth_SetVisible", 0i64, &pargs, 1u);
      }
      if ( this->mVisible && this->mChanged )
      {
        this->mChanged = 0;
        v5.NValue = this->mHealth;
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = VT_Number;
        pargs.mValue = v5;
        Scaleform::GFx::Movie::Invoke(pObject, "MissionHealth_SetHealth", 0i64, &pargs, 1u);
        mData = this->mCaption.mData;
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = VT_String;
        pargs.mValue.pString = mData;
        Scaleform::GFx::Movie::Invoke(pObject, "MissionHealth_SetCaption", 0i64, &pargs, 1u);
        if ( this->mSuccess )
          Scaleform::GFx::Movie::Invoke(pObject, "MissionHealth_Success", 0i64, 0i64, 0);
      }
      if ( (pargs.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
    }
  }
}

// File Line: 73
// RVA: 0x60C630
void __fastcall UFG::UIHKMissionHealthWidget::SetVisible(UFG::UIHKMissionHealthWidget *this, bool visible)
{
  bool v2; // zf

  v2 = this->mVisible == visible;
  this->mVisible = visible;
  this->mVisibleChanged |= !v2;
}

// File Line: 80
// RVA: 0x606230
void __fastcall UFG::UIHKMissionHealthWidget::SetHealth(UFG::UIHKMissionHealthWidget *this, float value)
{
  bool v2; // zf

  v2 = value == this->mHealth;
  this->mHealth = value;
  if ( !v2 )
    this->mChanged |= 1u;
}

// File Line: 87
// RVA: 0x605610
void __fastcall UFG::UIHKMissionHealthWidget::SetCaption(UFG::UIHKMissionHealthWidget *this, const char *caption)
{
  this->mChanged = 1;
  UFG::qString::Set(&this->mCaption, caption);
}

// File Line: 94
// RVA: 0x609F80
void __fastcall UFG::UIHKMissionHealthWidget::SetSuccess(UFG::UIHKMissionHealthWidget *this, bool success)
{
  bool v2; // zf

  v2 = this->mSuccess == success;
  this->mSuccess = success;
  this->mChanged |= !v2;
}

