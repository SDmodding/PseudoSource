// File Line: 33
// RVA: 0x613360
void __fastcall UFG::UIHKActionButtonWidget::Update(UFG::UIHKActionButtonWidget *this, UFG::UIScreen *screen)
{
  bool mShowOneFrameFlag; // cl
  bool v5; // zf
  UFG::UI::eButtons mButton; // ecx
  unsigned int v7; // eax
  char *v8; // r8
  char Key; // al
  char *KeyboardButtonTextureNameNonRemappable; // rax
  Scaleform::GFx::Movie *pObject; // rcx

  mShowOneFrameFlag = this->mShowOneFrameFlag;
  if ( __PAIR16__(mShowOneFrameFlag, this->mShowOneFrameActive) )
  {
    v5 = this->mVisible == mShowOneFrameFlag;
    this->mShowOneFrameActive = mShowOneFrameFlag;
    this->mShowOneFrameFlag = 0;
    this->mVisible = mShowOneFrameFlag;
    this->mChanged |= !v5;
  }
  if ( this->mChanged )
  {
    v5 = !this->mVisible;
    this->mChanged = 0;
    if ( !v5 )
    {
      mButton = this->mButton;
      if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      {
        v7 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(mButton, RemapContext_OnFoot);
        v8 = &customCaption;
        if ( v7 != REMAP_ID_INVALID_2 )
        {
          Key = UFG::UIHKScreenOptionsButtonMapping::GetKey(v7);
          v8 = (char *)UFG::KeyToTextureName(Key);
        }
        if ( *v8 )
          goto LABEL_12;
        KeyboardButtonTextureNameNonRemappable = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(this->mButton);
      }
      else
      {
        KeyboardButtonTextureNameNonRemappable = UFG::UI::GetGamepadButtonTextureName(mButton, 1);
      }
      v8 = KeyboardButtonTextureNameNonRemappable;
LABEL_12:
      UFG::UIHKActionButtonWidget::Flash_Show(this, screen, (Scaleform::GFx::Value *)v8, this->mActionType.mData);
      return;
    }
    if ( screen )
    {
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
        Scaleform::GFx::Movie::Invoke(pObject, "ActionButton_Hide", 0i64, 0i64, 0);
    }
  }
}

// File Line: 58
// RVA: 0x60CA80
void __fastcall UFG::UIHKActionButtonWidget::Show(
        UFG::UIHKActionButtonWidget *this,
        const char *actionText,
        UFG::UI::eButtons button,
        const char *actionType)
{
  bool v6; // al
  bool mVisible; // zf

  v6 = this->mButton != button;
  this->mButton = button;
  this->mChanged |= v6;
  mVisible = this->mVisible;
  this->mVisible = 1;
  this->mChanged |= !mVisible;
  if ( !this->mChanged )
    this->mChanged |= (unsigned int)UFG::qStringCompare(this->mActionText.mData, actionText, -1) != 0;
  if ( this->mChanged && (UFG::qString::Set(&this->mActionText, actionText), this->mChanged)
    || (this->mChanged |= (unsigned int)UFG::qStringCompare(this->mActionType.mData, actionType, -1) != 0) )
  {
    UFG::qString::Set(&this->mActionType, actionType);
  }
}

// File Line: 86
// RVA: 0x5EC990
void __fastcall UFG::UIHKActionButtonWidget::Hide(UFG::UIHKActionButtonWidget *this)
{
  bool v1; // zf

  v1 = !this->mVisible;
  this->mVisible = 0;
  this->mChanged |= !v1;
}

// File Line: 97
// RVA: 0x610C90
void __fastcall UFG::UIHKActionButtonWidget::ShowOneFrame(
        UFG::UIHKActionButtonWidget *this,
        const char *actionText,
        UFG::UI::eButtons button,
        const char *actionType)
{
  UFG::UIHKActionButtonWidget::Show(this, actionText, button, actionType);
  this->mShowOneFrameFlag = 1;
}

// File Line: 106
// RVA: 0x6008A0
void __fastcall UFG::UIHKActionButtonWidget::RefreshOneFrame(UFG::UIHKActionButtonWidget *this)
{
  this->mShowOneFrameFlag = 1;
}

// File Line: 112
// RVA: 0x5E23C0
void __fastcall UFG::UIHKActionButtonWidget::Flash_Show(
        UFG::UIHKActionButtonWidget *this,
        UFG::UIScreen *screen,
        Scaleform::GFx::Value *icon,
        const char *actionType)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-81h] BYREF
  int v8; // [rsp+60h] [rbp-51h]
  const char *v9; // [rsp+68h] [rbp-49h]
  char v10[16]; // [rsp+78h] [rbp-39h] BYREF
  __int64 v11; // [rsp+88h] [rbp-29h]
  int v12; // [rsp+90h] [rbp-21h]
  __int64 v13; // [rsp+98h] [rbp-19h]
  char v14[16]; // [rsp+A8h] [rbp-9h] BYREF
  __int64 v15; // [rsp+B8h] [rbp+7h]
  int v16; // [rsp+C0h] [rbp+Fh]
  __int64 v17; // [rsp+C8h] [rbp+17h]
  __int64 v18; // [rsp+D8h] [rbp+27h]
  __int64 v19; // [rsp+128h] [rbp+77h]
  char v20; // [rsp+130h] [rbp+7Fh]

  if ( screen )
  {
    v18 = -2i64;
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.pNext);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.pNext = icon;
      if ( (v8 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, const char *))(*(_QWORD *)ptr.DataAux + 16i64))(
          ptr.DataAux,
          &ptr.Type,
          v9);
        ptr.DataAux = 0i64;
      }
      v8 = 6;
      v9 = actionType;
      if ( (v12 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, v10, v13);
        v11 = 0i64;
      }
      v12 = 6;
      v13 = v19;
      if ( (v16 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, v14, v17);
        v15 = 0i64;
      }
      v16 = 2;
      LOBYTE(v17) = v20;
      Scaleform::GFx::Movie::Invoke(pObject, "ActionButton_Show", 0i64, &ptr, 4u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

