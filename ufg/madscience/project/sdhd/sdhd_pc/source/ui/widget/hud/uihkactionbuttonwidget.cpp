// File Line: 33
// RVA: 0x613360
void __fastcall UFG::UIHKActionButtonWidget::Update(UFG::UIHKActionButtonWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKActionButtonWidget *v2; // rbx
  bool v3; // cl
  UFG::UIScreen *v4; // rdi
  bool v5; // zf
  char *v6; // rbp
  UFG::UI::eButtons v7; // ecx
  unsigned int v8; // eax
  char *v9; // r8
  char v10; // al
  char *v11; // rax
  Scaleform::GFx::Movie *v12; // rcx

  v2 = this;
  v3 = this->mShowOneFrameFlag;
  v4 = screen;
  if ( v3 || v2->mShowOneFrameActive )
  {
    v5 = v2->mVisible == v3;
    v2->mShowOneFrameActive = v3;
    v2->mShowOneFrameFlag = 0;
    v2->mVisible = v3;
    v2->mChanged |= !v5;
  }
  if ( v2->mChanged )
  {
    v5 = v2->mVisible == 0;
    v2->mChanged = 0;
    if ( !v5 )
    {
      v6 = v2->mActionText.mData;
      v7 = v2->mButton;
      if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      {
        v8 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(v7, 0);
        v9 = &customWorldMapCaption;
        if ( v8 != REMAP_ID_INVALID_2 )
        {
          v10 = UFG::UIHKScreenOptionsButtonMapping::GetKey(v8);
          v9 = (char *)UFG::KeyToTextureName(v10);
        }
        if ( *v9 )
          goto LABEL_13;
        v11 = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(v2->mButton);
      }
      else
      {
        v11 = UFG::UI::GetGamepadButtonTextureName(v7, 1);
      }
      v9 = v11;
LABEL_13:
      UFG::UIHKActionButtonWidget::Flash_Show(v2, v4, v9, v2->mActionType.mData);
      return;
    }
    if ( screen )
    {
      v12 = screen->mRenderable->m_movie.pObject;
      if ( v12 )
        Scaleform::GFx::Movie::Invoke(v12, "ActionButton_Hide", 0i64, 0i64, 0);
    }
  }
}

// File Line: 58
// RVA: 0x60CA80
void __fastcall UFG::UIHKActionButtonWidget::Show(UFG::UIHKActionButtonWidget *this, const char *actionText, UFG::UI::eButtons button, const char *actionType)
{
  const char *v4; // rdi
  const char *v5; // rsi
  bool v6; // al
  UFG::UIHKActionButtonWidget *v7; // rbx
  bool v8; // zf

  v4 = actionType;
  v5 = actionText;
  v6 = this->mButton != button;
  v7 = this;
  this->mButton = button;
  this->mChanged |= v6;
  v8 = this->mVisible == 1;
  this->mVisible = 1;
  this->mChanged |= !v8;
  if ( !this->mChanged )
    this->mChanged |= (unsigned int)UFG::qStringCompare(this->mActionText.mData, actionText, -1) != 0;
  if ( v7->mChanged && (UFG::qString::Set(&v7->mActionText, v5), v7->mChanged)
    || (v7->mChanged |= (unsigned int)UFG::qStringCompare(v7->mActionType.mData, v4, -1) != 0) != 0 )
  {
    UFG::qString::Set(&v7->mActionType, v4);
  }
}

// File Line: 86
// RVA: 0x5EC990
void __fastcall UFG::UIHKActionButtonWidget::Hide(UFG::UIHKActionButtonWidget *this)
{
  bool v1; // zf

  v1 = this->mVisible == 0;
  this->mVisible = 0;
  this->mChanged |= !v1;
}

// File Line: 97
// RVA: 0x610C90
void __fastcall UFG::UIHKActionButtonWidget::ShowOneFrame(UFG::UIHKActionButtonWidget *this, const char *actionText, UFG::UI::eButtons button, const char *actionType)
{
  UFG::UIHKActionButtonWidget *v4; // rbx

  v4 = this;
  UFG::UIHKActionButtonWidget::Show(this, actionText, button, actionType);
  v4->mShowOneFrameFlag = 1;
}

// File Line: 106
// RVA: 0x6008A0
void __fastcall UFG::UIHKActionButtonWidget::RefreshOneFrame(UFG::UIHKActionButtonWidget *this)
{
  this->mShowOneFrameFlag = 1;
}

// File Line: 112
// RVA: 0x5E23C0
void __fastcall UFG::UIHKActionButtonWidget::Flash_Show(UFG::UIHKActionButtonWidget *this, UFG::UIScreen *screen, const char *icon, const char *actionType)
{
  const char *v4; // rsi
  const char *v5; // rdi
  Scaleform::GFx::Movie *v6; // rbx
  char ptr; // [rsp+30h] [rbp-81h]
  const char *v8; // [rsp+38h] [rbp-79h]
  __int64 v9; // [rsp+40h] [rbp-71h]
  unsigned int v10; // [rsp+48h] [rbp-69h]
  __int64 v11; // [rsp+58h] [rbp-59h]
  unsigned int v12; // [rsp+60h] [rbp-51h]
  const char *v13; // [rsp+68h] [rbp-49h]
  char v14; // [rsp+78h] [rbp-39h]
  __int64 v15; // [rsp+88h] [rbp-29h]
  unsigned int v16; // [rsp+90h] [rbp-21h]
  __int64 v17; // [rsp+98h] [rbp-19h]
  char v18; // [rsp+A8h] [rbp-9h]
  __int64 v19; // [rsp+B8h] [rbp+7h]
  unsigned int v20; // [rsp+C0h] [rbp+Fh]
  __int64 v21; // [rsp+C8h] [rbp+17h]
  __int64 v22; // [rsp+D8h] [rbp+27h]
  __int64 v23; // [rsp+128h] [rbp+77h]
  char v24; // [rsp+130h] [rbp+7Fh]

  if ( screen )
  {
    v22 = -2i64;
    v4 = actionType;
    v5 = icon;
    v6 = screen->mRenderable->m_movie.pObject;
    if ( v6 )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v10 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v9 + 16i64))(v9, &ptr, v8);
        v9 = 0i64;
      }
      v10 = 6;
      v8 = v5;
      if ( (v12 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, unsigned int *, const char *))(*(_QWORD *)v11 + 16i64))(v11, &v10, v13);
        v11 = 0i64;
      }
      v12 = 6;
      v13 = v4;
      if ( (v16 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
        v15 = 0i64;
      }
      v16 = 6;
      v17 = v23;
      if ( (v20 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
        v19 = 0i64;
      }
      v20 = 2;
      LOBYTE(v21) = v24;
      Scaleform::GFx::Movie::Invoke(v6, "ActionButton_Show", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

