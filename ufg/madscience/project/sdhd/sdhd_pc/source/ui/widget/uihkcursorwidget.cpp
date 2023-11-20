// File Line: 30
// RVA: 0x5EB900
void __fastcall UFG::UIHKCursorWidget::HandleScreenInit(UFG::UIHKCursorWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rbx
  UFG::UIHKCursorWidget *v3; // rdi
  signed int v4; // edx

  if ( screen )
  {
    v2 = screen;
    v3 = this;
    if ( screen->mRenderable )
    {
      UFG::UIHKCursorWidget::SetMargin(this, screen, this->mMargin);
      v4 = v2->mRenderable->m_height;
      v3->mPos.x = (float)v2->mRenderable->m_width * 0.5;
      v3->mPos.y = (float)v4 * 0.5;
      UFG::UIHKCursorWidget::BoundPos(v3);
    }
  }
}

// File Line: 46
// RVA: 0x613AE0
void __fastcall UFG::UIHKCursorWidget::Update(UFG::UIHKCursorWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKCursorWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  float v4; // xmm0_4
  UFG::InputActionData *v5; // rax
  float v6; // xmm2_4
  float v7; // xmm1_4
  UFG::InputActionData *v8; // rax
  float v9; // xmm2_4
  float v10; // xmm1_4
  bool v11; // al
  long double v12; // xmm6_8
  double v13; // xmm6_8
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-48h]

  if ( screen )
  {
    v2 = this;
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      v4 = UFG::UIHKTweakables::WorldMap_CursorSpeed;
      v5 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
      if ( v5 )
        v6 = v5->mAxisPositionX;
      else
        v6 = 0.0;
      if ( v5 )
        v7 = v5->mAxisPositionY;
      else
        v7 = 0.0;
      if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      {
        v4 = UFG::UIHKTweakables::WorldMap_MouseCursorSpeed;
        v8 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
        if ( v8 )
          v6 = v8->mAxisPositionX;
        else
          v6 = 0.0;
        if ( v8 )
          v7 = v8->mAxisPositionY;
        else
          v7 = 0.0;
      }
      v9 = v6 * v4;
      v10 = v7 * v4;
      if ( COERCE_FLOAT(LODWORD(v9) & _xmm) > 0.1 || (v11 = 0, COERCE_FLOAT(LODWORD(v10) & _xmm) > 0.1) )
        v11 = 1;
      this->mIsMoving = v11;
      this->mPos.x = v9 + this->mPos.x;
      this->mPos.y = v10 + this->mPos.y;
      UFG::UIHKCursorWidget::BoundPos(this);
      value.pObjectInterface = 0i64;
      value.Type = 0;
      v12 = v2->mPos.x;
      value.Type = 5;
      value.mValue.NValue = v12;
      Scaleform::GFx::Movie::SetVariable(v3, "mc_Cursor._x", &value, 1i64);
      v13 = v2->mPos.y;
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 5;
      value.mValue.NValue = v13;
      Scaleform::GFx::Movie::SetVariable(v3, "mc_Cursor._y", &value, 1i64);
      if ( ((unsigned int)value.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
    }
  }
}

// File Line: 103
// RVA: 0x5D4390
void __fastcall UFG::UIHKCursorWidget::BoundPos(UFG::UIHKCursorWidget *this)
{
  float v1; // xmm0_4
  float v2; // xmm1_4
  float v3; // xmm1_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = this->mPos.x;
  v2 = this->mMinLimit.x;
  if ( this->mPos.x >= v2 )
  {
    v3 = this->mMaxLimit.x;
    if ( v1 <= v3 )
    {
      this->mEdgePush.x = 0.0;
    }
    else
    {
      this->mPos.x = v3;
      this->mEdgePush.x = v1 - v3;
    }
  }
  else
  {
    this->mPos.x = v2;
    this->mEdgePush.x = v1 - v2;
  }
  v4 = this->mPos.y;
  v5 = this->mMinLimit.y;
  if ( v4 >= v5 && (v5 = this->mMaxLimit.y, v4 <= v5) )
  {
    this->mEdgePush.y = 0.0;
  }
  else
  {
    this->mPos.y = v5;
    this->mEdgePush.y = v5 - v4;
  }
}

// File Line: 146
// RVA: 0x606240
void __usercall UFG::UIHKCursorWidget::SetMargin(UFG::UIHKCursorWidget *this@<rcx>, UFG::UIScreen *screen@<rdx>, float margin@<xmm2>, float a4@<xmm0>)
{
  UFG::UIHKCursorWidget *v4; // rsi
  UFG::UIScreen *v5; // rbx
  float v6; // xmm2_4
  UFG::ScreenPoint2f v7; // [rsp+30h] [rbp+8h]

  this->mMargin = margin;
  v4 = this;
  v5 = screen;
  ((void (*)(void))screen->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceTypeCode)();
  ((void (*)(void))v5->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceReport)();
  v6 = v4->mMargin;
  v7.x = v6;
  v7.y = v4->mMargin;
  v4->mMinLimit = v7;
  v7.x = (float)(signed int)a4 - v6;
  v7.y = (float)(signed int)a4 - v6;
  v4->mMaxLimit = v7;
  UFG::UIHKCursorWidget::BoundPos(v4);
}

