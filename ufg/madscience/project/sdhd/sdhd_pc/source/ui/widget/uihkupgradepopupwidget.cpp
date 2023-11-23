// File Line: 28
// RVA: 0x5C8240
void __fastcall UFG::UIHKUpgradePopupWidget::UIHKUpgradePopupWidget(UFG::UIHKUpgradePopupWidget *this)
{
  this->mState = STATE_HIDDEN;
  *(_WORD *)&this->mVisible = 0;
  this->mTextureLoaded = 0;
  this->mDisplayTime = 0.0;
  this->mMaxTime = 5.0;
  UFG::qString::qString(&this->mDescription, &customCaption);
  UFG::qString::qString(&this->mIcon, &customCaption);
  UFG::qString::qString(&this->mTexturePack, &customCaption);
}

// File Line: 33
// RVA: 0x6184D0
void __fastcall UFG::UIHKUpgradePopupWidget::Update(
        UFG::UIHKUpgradePopupWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  Scaleform::GFx::Movie *pObject; // rsi
  UFG::UIHKUpgradePopupWidget::eState mState; // ecx
  __int32 v6; // ecx
  char *mData; // r15
  char *v8; // r15
  char *v9; // r15
  char *v10; // r15
  Scaleform::GFx::Value ptr; // [rsp+28h] [rbp-19h] BYREF
  char v12[16]; // [rsp+58h] [rbp+17h] BYREF
  __int64 v13; // [rsp+68h] [rbp+27h]
  int v14; // [rsp+70h] [rbp+2Fh]
  char *v15; // [rsp+78h] [rbp+37h]

  if ( this->mUpdate )
  {
    this->mUpdate = 0;
    if ( screen )
    {
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
      {
        mState = this->mState;
        if ( mState )
        {
          v6 = mState - 1;
          if ( v6 )
          {
            if ( v6 == 1 )
            {
              this->mUpdate = 1;
              if ( this->mTextureLoaded )
              {
                if ( this->mVisible )
                {
                  this->mDisplayTime = elapsed + this->mDisplayTime;
                }
                else
                {
                  `eh vector constructor iterator(
                    &ptr,
                    0x30ui64,
                    2,
                    (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
                  mData = this->mIcon.mData;
                  if ( (ptr.Type & 0x40) != 0 )
                  {
                    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
                      ptr.pObjectInterface,
                      &ptr,
                      ptr.mValue);
                    ptr.pObjectInterface = 0i64;
                  }
                  ptr.Type = VT_String;
                  ptr.mValue.pString = mData;
                  v8 = this->mDescription.mData;
                  if ( (v14 & 0x40) != 0 )
                  {
                    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v13 + 16i64))(v13, v12, v15);
                    v13 = 0i64;
                  }
                  v14 = 6;
                  v15 = v8;
                  Scaleform::GFx::Movie::Invoke(pObject, "UpgradePopup_Show", 0i64, &ptr, 2u);
                  this->mDisplayTime = 0.0;
                  this->mVisible = 1;
                  `eh vector destructor iterator(
                    &ptr,
                    0x30ui64,
                    2,
                    (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
                }
                if ( this->mMaxTime < this->mDisplayTime )
                {
                  this->mState = STATE_HIDDEN;
                  UFG::UIHKUpgradePopupWidget::UnLoadTexturePack(this);
                }
              }
            }
          }
          else if ( this->mTextureLoaded )
          {
            if ( !this->mVisible )
            {
              `eh vector constructor iterator(
                &ptr,
                0x30ui64,
                2,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
              v9 = this->mIcon.mData;
              if ( (ptr.Type & 0x40) != 0 )
              {
                (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
                  ptr.pObjectInterface,
                  &ptr,
                  ptr.mValue);
                ptr.pObjectInterface = 0i64;
              }
              ptr.Type = VT_String;
              ptr.mValue.pString = v9;
              v10 = this->mDescription.mData;
              if ( (v14 & 0x40) != 0 )
              {
                (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v13 + 16i64))(v13, v12, v15);
                v13 = 0i64;
              }
              v14 = 6;
              v15 = v10;
              Scaleform::GFx::Movie::Invoke(pObject, "UpgradePopup_Show", 0i64, &ptr, 2u);
              this->mDisplayTime = 0.0;
              this->mVisible = 1;
              `eh vector destructor iterator(
                &ptr,
                0x30ui64,
                2,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
            }
          }
          else
          {
            this->mUpdate = 1;
          }
        }
        else if ( this->mVisible )
        {
          Scaleform::GFx::Movie::Invoke(pObject, "UpgradePopup_Hide", 0i64, 0i64, 0);
          this->mVisible = 0;
        }
      }
    }
  }
}

// File Line: 97
// RVA: 0x5D8AC0
void __fastcall UFG::UIHKUpgradePopupWidget::Flash(
        UFG::UIHKUpgradePopupWidget *this,
        const char *icon,
        const char *description)
{
  this->mUpdate = 1;
  UFG::qString::Set(&this->mIcon, icon);
  UFG::qString::Set(&this->mDescription, description);
  this->mDisplayTime = 0.0;
  this->mState = STATE_FLASHING;
  UFG::UIHKUpgradePopupWidget::LoadTexturePack(this, icon);
}

// File Line: 109
// RVA: 0x60D2A0
void __fastcall UFG::UIHKUpgradePopupWidget::Show(
        UFG::UIHKUpgradePopupWidget *this,
        const char *icon,
        const char *description)
{
  this->mUpdate = 1;
  UFG::qString::Set(&this->mIcon, icon);
  UFG::qString::Set(&this->mDescription, description);
  this->mState = STATE_SHOWING;
  UFG::UIHKUpgradePopupWidget::LoadTexturePack(this, icon);
}

// File Line: 120
// RVA: 0x5ECC60
void __fastcall UFG::UIHKUpgradePopupWidget::Hide(UFG::UIHKUpgradePopupWidget *this)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v3; // rax

  mData = this->mTexturePack.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, mData);
  *(_WORD *)&this->mUpdate = 1;
  this->mState = STATE_HIDDEN;
}

// File Line: 129
// RVA: 0x5F1590
void __fastcall UFG::UIHKUpgradePopupWidget::LoadTexturePack(UFG::UIHKUpgradePopupWidget *this, const char *icon)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v5; // rax
  __int64 v6; // rax
  char *v7; // rbx
  UFG::UIScreenTextureManager *v8; // rax
  UFG::qString v9; // [rsp+38h] [rbp-30h] BYREF

  mData = this->mTexturePack.mData;
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v5, mData);
  UFG::qString::qString(&v9, "Data\\UI\\%s_TexturePack.perm.bin", icon);
  UFG::qString::Set(&this->mTexturePack, *(const char **)(v6 + 24), *(_DWORD *)(v6 + 20), 0i64, 0);
  UFG::qString::~qString(&v9);
  v7 = this->mTexturePack.mData;
  v8 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v8,
    v7,
    DEFAULT_PRIORITY,
    (UFG::qReflectInventoryBase *)UFG::UIHKUpgradePopupWidget::TextureLoadedCallback,
    0i64);
}

// File Line: 137
// RVA: 0x6131A0
void __fastcall UFG::UIHKUpgradePopupWidget::UnLoadTexturePack(UFG::UIHKUpgradePopupWidget *this)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v3; // rax

  mData = this->mTexturePack.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, mData);
  this->mTextureLoaded = 0;
}

// File Line: 150
// RVA: 0x612970
void __fastcall UFG::UIHKUpgradePopupWidget::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  if ( UFG::UIHKScreenHud::mInstance )
  {
    if ( UFG::UIHKScreenHud::UpgradePopup )
      UFG::UIHKScreenHud::UpgradePopup->mTextureLoaded = 1;
  }
}

