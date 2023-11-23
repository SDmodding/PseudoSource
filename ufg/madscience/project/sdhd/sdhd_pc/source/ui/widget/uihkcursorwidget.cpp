// File Line: 30
// RVA: 0x5EB900
void __fastcall UFG::UIHKCursorWidget::HandleScreenInit(UFG::UIHKCursorWidget *this, UFG::UIScreen *screen)
{
  int m_height; // edx

  if ( screen )
  {
    if ( screen->mRenderable )
    {
      UFG::UIHKCursorWidget::SetMargin(this, screen, this->mMargin);
      m_height = screen->mRenderable->m_height;
      this->mPos.x = (float)screen->mRenderable->m_width * 0.5;
      this->mPos.y = (float)m_height * 0.5;
      UFG::UIHKCursorWidget::BoundPos(this);
    }
  }
}

// File Line: 46
// RVA: 0x613AE0
void __fastcall UFG::UIHKCursorWidget::Update(UFG::UIHKCursorWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rdi
  float v4; // xmm0_4
  UFG::InputActionData *v5; // rax
  float mAxisPositionX; // xmm2_4
  float mAxisPositionY; // xmm1_4
  UFG::InputActionData *v8; // rax
  float v9; // xmm2_4
  float v10; // xmm1_4
  bool v11; // al
  long double x; // xmm6_8
  Scaleform::GFx::Value::ValueUnion v13; // xmm6_8
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-48h] BYREF

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      v4 = UFG::UIHKTweakables::WorldMap_CursorSpeed;
      v5 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
      if ( v5 )
        mAxisPositionX = v5->mAxisPositionX;
      else
        mAxisPositionX = 0.0;
      if ( v5 )
        mAxisPositionY = v5->mAxisPositionY;
      else
        mAxisPositionY = 0.0;
      if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      {
        v4 = UFG::UIHKTweakables::WorldMap_MouseCursorSpeed;
        v8 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
        if ( v8 )
          mAxisPositionX = v8->mAxisPositionX;
        else
          mAxisPositionX = 0.0;
        if ( v8 )
          mAxisPositionY = v8->mAxisPositionY;
        else
          mAxisPositionY = 0.0;
      }
      v9 = mAxisPositionX * v4;
      v10 = mAxisPositionY * v4;
      if ( COERCE_FLOAT(LODWORD(v9) & _xmm) > 0.1 || (v11 = 0, COERCE_FLOAT(LODWORD(v10) & _xmm) > 0.1) )
        v11 = 1;
      this->mIsMoving = v11;
      this->mPos.x = v9 + this->mPos.x;
      this->mPos.y = v10 + this->mPos.y;
      UFG::UIHKCursorWidget::BoundPos(this);
      value.pObjectInterface = 0i64;
      value.Type = VT_Undefined;
      x = this->mPos.x;
      value.Type = VT_Number;
      value.mValue.NValue = x;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_Cursor._x", &value, 1i64);
      v13.NValue = this->mPos.y;
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Number;
      value.mValue = v13;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_Cursor._y", &value, 1i64);
      if ( (value.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
    }
  }
}

// File Line: 103
// RVA: 0x5D4390
void __fastcall UFG::UIHKCursorWidget::BoundPos(UFG::UIHKCursorWidget *this)
{
  float x; // xmm0_4
  float v2; // xmm1_4
  float v3; // xmm1_4
  float y; // xmm1_4
  float v5; // xmm2_4

  x = this->mPos.x;
  v2 = this->mMinLimit.x;
  if ( this->mPos.x >= v2 )
  {
    v3 = this->mMaxLimit.x;
    if ( x <= v3 )
    {
      this->mEdgePush.x = 0.0;
    }
    else
    {
      this->mPos.x = v3;
      this->mEdgePush.x = x - v3;
    }
  }
  else
  {
    this->mPos.x = v2;
    this->mEdgePush.x = x - v2;
  }
  y = this->mPos.y;
  v5 = this->mMinLimit.y;
  if ( y >= v5 && (v5 = this->mMaxLimit.y, y <= v5) )
  {
    this->mEdgePush.y = 0.0;
  }
  else
  {
    this->mPos.y = v5;
    this->mEdgePush.y = v5 - y;
  }
}

// File Line: 146
// RVA: 0x606240
void __fastcall UFG::UIHKCursorWidget::SetMargin(UFG::UIHKCursorWidget *this, UFG::UIScreen *screen, float margin)
{
  int v5; // edi
  float v6; // xmm0_4
  float mMargin; // xmm2_4
  UFG::ScreenPoint2f v8; // [rsp+30h] [rbp+8h]

  this->mMargin = margin;
  v5 = (int)((float (__fastcall *)(Scaleform::GFx::MovieDef *))screen->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceTypeCode)(screen->mRenderable->m_movieDef.pObject);
  v6 = ((float (__fastcall *)(Scaleform::GFx::MovieDef *))screen->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceReport)(screen->mRenderable->m_movieDef.pObject);
  mMargin = this->mMargin;
  v8.x = mMargin;
  v8.y = mMargin;
  this->mMinLimit = v8;
  v8.x = (float)v5 - mMargin;
  v8.y = (float)(int)v6 - mMargin;
  this->mMaxLimit = v8;
  UFG::UIHKCursorWidget::BoundPos(this);
}

