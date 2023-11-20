// File Line: 22
// RVA: 0x617500
void __fastcall UFG::UIHKSecondaryTutorialWidget::Update(UFG::UIHKSecondaryTutorialWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHKSecondaryTutorialWidget *v3; // rbx
  __int32 v4; // ecx
  Scaleform::GFx::Movie *v5; // rcx

  v3 = this;
  v4 = this->mState - 1;
  if ( v4 )
  {
    if ( v4 == 2 )
    {
      if ( screen )
      {
        v5 = screen->mRenderable->m_movie.pObject;
        if ( v5 )
          Scaleform::GFx::Movie::Invoke(v5, "SecondaryTutorial_Hide", 0i64, 0i64, 0);
      }
      v3->mState = 0;
    }
  }
  else
  {
    UFG::UIHKSecondaryTutorialWidget::Flash_Show(v3, screen, v3->mCaption.mData);
    v3->mState = 2;
  }
}

// File Line: 49
// RVA: 0x60D240
void __fastcall UFG::UIHKSecondaryTutorialWidget::Show(UFG::UIHKSecondaryTutorialWidget *this, const char *caption)
{
  UFG::UIHKSecondaryTutorialWidget *v2; // rbx

  v2 = this;
  UFG::qString::Set(&this->mCaption, caption);
  v2->mState = 1;
}

// File Line: 56
// RVA: 0x5ECC30
void __fastcall UFG::UIHKSecondaryTutorialWidget::Hide(UFG::UIHKSecondaryTutorialWidget *this)
{
  if ( this->mState )
    this->mState = 3;
}

// File Line: 65
// RVA: 0x5E38D0
void __fastcall UFG::UIHKSecondaryTutorialWidget::Flash_Show(UFG::UIHKSecondaryTutorialWidget *this, UFG::UIScreen *screen, const char *caption)
{
  const char *v3; // rdi
  Scaleform::GFx::Movie *v4; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  if ( screen )
  {
    v3 = caption;
    v4 = screen->mRenderable->m_movie.pObject;
    if ( v4 )
    {
      `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 6;
      *(_QWORD *)&pargs.mValue.NValue = v3;
      Scaleform::GFx::Movie::Invoke(v4, "SecondaryTutorial_Show", 0i64, &pargs, 1u);
      `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

