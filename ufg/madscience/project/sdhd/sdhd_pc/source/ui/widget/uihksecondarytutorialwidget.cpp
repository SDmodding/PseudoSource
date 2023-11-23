// File Line: 22
// RVA: 0x617500
void __fastcall UFG::UIHKSecondaryTutorialWidget::Update(
        UFG::UIHKSecondaryTutorialWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  __int32 v4; // ecx
  Scaleform::GFx::Movie *pObject; // rcx

  v4 = this->mState - 1;
  if ( v4 )
  {
    if ( v4 == 2 )
    {
      if ( screen )
      {
        pObject = screen->mRenderable->m_movie.pObject;
        if ( pObject )
          Scaleform::GFx::Movie::Invoke(pObject, "SecondaryTutorial_Hide", 0i64, 0i64, 0);
      }
      this->mState = STATE_IDLE;
    }
  }
  else
  {
    UFG::UIHKSecondaryTutorialWidget::Flash_Show(this, screen, this->mCaption.mData);
    this->mState = STATE_PHONE_CONTACTS;
  }
}

// File Line: 49
// RVA: 0x60D240
void __fastcall UFG::UIHKSecondaryTutorialWidget::Show(UFG::UIHKSecondaryTutorialWidget *this, const char *caption)
{
  UFG::qString::Set(&this->mCaption, caption);
  this->mState = STATE_ROOT_MENU;
}

// File Line: 56
// RVA: 0x5ECC30
void __fastcall UFG::UIHKSecondaryTutorialWidget::Hide(UFG::UIHKSecondaryTutorialWidget *this)
{
  if ( this->mState )
    this->mState = STATE_TEXT_INBOX;
}

// File Line: 65
// RVA: 0x5E38D0
void __fastcall UFG::UIHKSecondaryTutorialWidget::Flash_Show(
        UFG::UIHKSecondaryTutorialWidget *this,
        UFG::UIScreen *screen,
        const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_String;
      pargs.mValue.pString = caption;
      Scaleform::GFx::Movie::Invoke(pObject, "SecondaryTutorial_Show", 0i64, &pargs, 1u);
      `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

