// File Line: 30
// RVA: 0x618F40
void __fastcall UFG::UIHKWorldMapInfoPopupWidget::Update(UFG::UIHKWorldMapInfoPopupWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rdi
  __int32 v4; // ecx
  const char *v5; // rdx
  bool mVisible; // si
  Scaleform::GFx::Value::ValueUnion v7; // xmm6_8
  Scaleform::GFx::Value::ValueUnion v8; // xmm6_8
  const char *v9; // rsi
  const char *v10; // rbx
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-48h] BYREF

  if ( !screen )
    return;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( !pObject )
    return;
  if ( this->mCueAnimation )
  {
    this->mCueAnimation = 0;
    v4 = this->mState - 1;
    if ( v4 )
    {
      if ( v4 != 1 )
        goto LABEL_9;
      v5 = "InfoPopup_FadeOut";
    }
    else
    {
      v5 = "InfoPopup_FadeIn";
    }
    Scaleform::GFx::Movie::Invoke(pObject, v5, 0i64, 0i64, 0);
  }
LABEL_9:
  if ( this->mChanged )
  {
    this->mChanged = 0;
    value.pObjectInterface = 0i64;
    value.Type = VT_Undefined;
    mVisible = this->mVisible;
    value.Type = VT_Boolean;
    value.mValue.BValue = mVisible;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_InfoPopup._visible", &value, 1i64);
    if ( this->mVisible )
    {
      v7.NValue = this->mPosX;
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Number;
      value.mValue = v7;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_InfoPopup._x", &value, 1i64);
      v8.NValue = this->mPosY;
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Number;
      value.mValue = v8;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_InfoPopup._y", &value, 1i64);
      v9 = UFG::UI::LocalizeText(this->mTitleText.mData);
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_String;
      value.mValue.pString = v9;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_InfoPopup.inner.title.htmlText", &value, 1i64);
      v10 = UFG::UI::LocalizeText(this->mBodyText.mData);
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_String;
      value.mValue.pString = v10;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_InfoPopup.inner.body.htmlText", &value, 1i64);
      Scaleform::GFx::Movie::Invoke(pObject, "InfoPopup_SetWidth", 0i64, 0i64, 0);
    }
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

