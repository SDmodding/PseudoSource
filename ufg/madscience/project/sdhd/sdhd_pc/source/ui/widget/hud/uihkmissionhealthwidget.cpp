// File Line: 29
// RVA: 0x614B50
void __fastcall UFG::UIHKMissionHealthWidget::Update(UFG::UIHKMissionHealthWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKMissionHealthWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  bool v4; // si
  double v5; // xmm6_8
  long double v6; // rsi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-48h]

  if ( screen )
  {
    v2 = this;
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = 0;
      if ( this->mVisibleChanged )
      {
        this->mVisibleChanged = 0;
        v4 = this->mVisible;
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 2;
        pargs.mValue.BValue = v4;
        Scaleform::GFx::Movie::Invoke(v3, "MissionHealth_SetVisible", 0i64, &pargs, 1u);
      }
      if ( v2->mVisible && v2->mChanged )
      {
        v2->mChanged = 0;
        v5 = v2->mHealth;
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 5;
        pargs.mValue.NValue = v5;
        Scaleform::GFx::Movie::Invoke(v3, "MissionHealth_SetHealth", 0i64, &pargs, 1u);
        v6 = *(double *)&v2->mCaption.mData;
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 6;
        pargs.mValue.NValue = v6;
        Scaleform::GFx::Movie::Invoke(v3, "MissionHealth_SetCaption", 0i64, &pargs, 1u);
        if ( v2->mSuccess )
          Scaleform::GFx::Movie::Invoke(v3, "MissionHealth_Success", 0i64, 0i64, 0);
      }
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
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

