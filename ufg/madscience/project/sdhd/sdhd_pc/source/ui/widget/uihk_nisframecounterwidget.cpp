// File Line: 24
// RVA: 0x619540
void __fastcall UFG::UIHK_NISFrameCounterWidget::Update(UFG::UIHK_NISFrameCounterWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHK_NISFrameCounterWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // rdi
  bool v5; // si
  long double v6; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-38h]

  v3 = this;
  if ( this->mChanged )
  {
    this->mChanged = 0;
    if ( screen )
    {
      v4 = screen->mRenderable->m_movie.pObject;
      if ( v4 )
      {
        value.pObjectInterface = 0i64;
        value.Type = 0;
        v5 = this->mVisible;
        value.Type = 2;
        value.mValue.BValue = v5;
        Scaleform::GFx::Movie::SetVariable(v4, "mc_FrameCounter._visible", &value, 1i64);
        if ( v3->mVisible )
        {
          v6 = *(double *)&v3->mCaption.mData;
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 6;
          value.mValue.NValue = v6;
          Scaleform::GFx::Movie::SetVariable(v4, "mc_FrameCounter.counterText.text", &value, 1i64);
        }
        if ( ((unsigned int)value.Type >> 6) & 1 )
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            *(_QWORD *)&value.mValue.NValue);
      }
    }
  }
}

// File Line: 50
// RVA: 0x60C6B0
void __fastcall UFG::UIHK_NISFrameCounterWidget::SetVisible(UFG::UIHK_NISFrameCounterWidget *this, bool visible)
{
  bool v2; // zf

  v2 = this->mVisible == visible;
  this->mVisible = visible;
  this->mChanged |= !v2;
}

// File Line: 57
// RVA: 0x605620
void __fastcall UFG::UIHK_NISFrameCounterWidget::SetCaption(UFG::UIHK_NISFrameCounterWidget *this, const char *caption)
{
  UFG::UIHK_NISFrameCounterWidget *v2; // rbx

  v2 = this;
  UFG::qString::Set(&this->mCaption, caption);
  v2->mChanged = 1;
}

// File Line: 64
// RVA: 0x607330
void __fastcall UFG::UIHK_NISFrameCounterWidget::SetSceneTime(UFG::UIHK_NISFrameCounterWidget *this, float sceneTime)
{
  UFG::UIHK_NISFrameCounterWidget *v2; // rbx

  v2 = this;
  UFG::qString::Format(&this->mCaption, "%.2f", sceneTime);
  v2->mChanged = 1;
}

