// File Line: 30
// RVA: 0x618F40
void __fastcall UFG::UIHKWorldMapInfoPopupWidget::Update(UFG::UIHKWorldMapInfoPopupWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKWorldMapInfoPopupWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  __int32 v4; // ecx
  const char *v5; // rdx
  bool v6; // si
  double v7; // xmm6_8
  double v8; // xmm6_8
  const char *v9; // rsi
  const char *v10; // rbx
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-48h]

  if ( !screen )
    return;
  v2 = this;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( !v3 )
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
    Scaleform::GFx::Movie::Invoke(v3, v5, 0i64, 0i64, 0);
  }
LABEL_9:
  if ( v2->mChanged )
  {
    v2->mChanged = 0;
    value.pObjectInterface = 0i64;
    value.Type = 0;
    v6 = v2->mVisible;
    value.Type = 2;
    value.mValue.BValue = v6;
    Scaleform::GFx::Movie::SetVariable(v3, "mc_InfoPopup._visible", &value, 1i64);
    if ( v2->mVisible )
    {
      v7 = v2->mPosX;
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 5;
      value.mValue.NValue = v7;
      Scaleform::GFx::Movie::SetVariable(v3, "mc_InfoPopup._x", &value, 1i64);
      v8 = v2->mPosY;
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 5;
      value.mValue.NValue = v8;
      Scaleform::GFx::Movie::SetVariable(v3, "mc_InfoPopup._y", &value, 1i64);
      v9 = UFG::UI::LocalizeText(v2->mTitleText.mData);
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 6;
      *(_QWORD *)&value.mValue.NValue = v9;
      Scaleform::GFx::Movie::SetVariable(v3, "mc_InfoPopup.inner.title.htmlText", &value, 1i64);
      v10 = UFG::UI::LocalizeText(v2->mBodyText.mData);
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 6;
      *(_QWORD *)&value.mValue.NValue = v10;
      Scaleform::GFx::Movie::SetVariable(v3, "mc_InfoPopup.inner.body.htmlText", &value, 1i64);
      Scaleform::GFx::Movie::Invoke(v3, "InfoPopup_SetWidth", 0i64, 0i64, 0);
    }
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

