// File Line: 24
// RVA: 0x619540
void __fastcall UFG::UIHK_NISFrameCounterWidget::Update(
        UFG::UIHK_NISFrameCounterWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  Scaleform::GFx::Movie *pObject; // rdi
  bool mVisible; // si
  char *mData; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-38h] BYREF

  if ( this->mChanged )
  {
    this->mChanged = 0;
    if ( screen )
    {
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
      {
        value.pObjectInterface = 0i64;
        value.Type = VT_Undefined;
        mVisible = this->mVisible;
        value.Type = VT_Boolean;
        value.mValue.BValue = mVisible;
        Scaleform::GFx::Movie::SetVariable(pObject, "mc_FrameCounter._visible", &value, 1i64);
        if ( this->mVisible )
        {
          mData = this->mCaption.mData;
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_String;
          value.mValue.pString = mData;
          Scaleform::GFx::Movie::SetVariable(pObject, "mc_FrameCounter.counterText.text", &value, 1i64);
        }
        if ( (value.Type & 0x40) != 0 )
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            value.mValue);
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
  UFG::qString::Set(&this->mCaption, caption);
  this->mChanged = 1;
}

// File Line: 64
// RVA: 0x607330
void __fastcall UFG::UIHK_NISFrameCounterWidget::SetSceneTime(UFG::UIHK_NISFrameCounterWidget *this, float sceneTime)
{
  UFG::qString::Format(&this->mCaption, "%.2f", sceneTime);
  this->mChanged = 1;
}

