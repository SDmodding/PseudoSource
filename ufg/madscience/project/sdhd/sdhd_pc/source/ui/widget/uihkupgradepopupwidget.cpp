// File Line: 28
// RVA: 0x5C8240
void __fastcall UFG::UIHKUpgradePopupWidget::UIHKUpgradePopupWidget(UFG::UIHKUpgradePopupWidget *this)
{
  UFG::UIHKUpgradePopupWidget *v1; // rbx

  v1 = this;
  this->mState = 0;
  *(_WORD *)&this->mVisible = 0;
  this->mTextureLoaded = 0;
  this->mDisplayTime = 0.0;
  this->mMaxTime = 5.0;
  UFG::qString::qString(&this->mDescription, &customWorldMapCaption);
  UFG::qString::qString(&v1->mIcon, &customWorldMapCaption);
  UFG::qString::qString(&v1->mTexturePack, &customWorldMapCaption);
}

// File Line: 33
// RVA: 0x6184D0
void __fastcall UFG::UIHKUpgradePopupWidget::Update(UFG::UIHKUpgradePopupWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHKUpgradePopupWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // rsi
  UFG::UIHKUpgradePopupWidget::eState v5; // ecx
  int v6; // ecx
  __int64 v7; // r15
  __int64 v8; // r15
  __int64 v9; // r15
  __int64 v10; // r15
  char ptr; // [rsp+28h] [rbp-19h]
  __int64 v12; // [rsp+38h] [rbp-9h]
  unsigned int v13; // [rsp+40h] [rbp-1h]
  __int64 v14; // [rsp+48h] [rbp+7h]
  char v15; // [rsp+58h] [rbp+17h]
  __int64 v16; // [rsp+68h] [rbp+27h]
  unsigned int v17; // [rsp+70h] [rbp+2Fh]
  __int64 v18; // [rsp+78h] [rbp+37h]

  v3 = this;
  if ( this->mUpdate )
  {
    this->mUpdate = 0;
    if ( screen )
    {
      v4 = screen->mRenderable->m_movie.pObject;
      if ( v4 )
      {
        v5 = this->mState;
        if ( v5 )
        {
          v6 = v5 - 1;
          if ( v6 )
          {
            if ( v6 == 1 )
            {
              v3->mUpdate = 1;
              if ( v3->mTextureLoaded )
              {
                if ( v3->mVisible )
                {
                  v3->mDisplayTime = elapsed + v3->mDisplayTime;
                }
                else
                {
                  `eh vector constructor iterator(
                    &ptr,
                    0x30ui64,
                    2,
                    (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
                  v7 = (__int64)v3->mIcon.mData;
                  if ( (v13 >> 6) & 1 )
                  {
                    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v12 + 16i64))(v12, &ptr, v14);
                    v12 = 0i64;
                  }
                  v13 = 6;
                  v14 = v7;
                  v8 = (__int64)v3->mDescription.mData;
                  if ( (v17 >> 6) & 1 )
                  {
                    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &v15, v18);
                    v16 = 0i64;
                  }
                  v17 = 6;
                  v18 = v8;
                  Scaleform::GFx::Movie::Invoke(v4, "UpgradePopup_Show", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
                  v3->mDisplayTime = 0.0;
                  v3->mVisible = 1;
                  `eh vector destructor iterator(
                    &ptr,
                    0x30ui64,
                    2,
                    (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
                }
                if ( v3->mMaxTime < v3->mDisplayTime )
                {
                  v3->mState = 0;
                  UFG::UIHKUpgradePopupWidget::UnLoadTexturePack(v3);
                }
              }
            }
          }
          else if ( v3->mTextureLoaded )
          {
            if ( !v3->mVisible )
            {
              `eh vector constructor iterator(
                &ptr,
                0x30ui64,
                2,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
              v9 = (__int64)v3->mIcon.mData;
              if ( (v13 >> 6) & 1 )
              {
                (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v12 + 16i64))(v12, &ptr, v14);
                v12 = 0i64;
              }
              v13 = 6;
              v14 = v9;
              v10 = (__int64)v3->mDescription.mData;
              if ( (v17 >> 6) & 1 )
              {
                (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &v15, v18);
                v16 = 0i64;
              }
              v17 = 6;
              v18 = v10;
              Scaleform::GFx::Movie::Invoke(v4, "UpgradePopup_Show", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
              v3->mDisplayTime = 0.0;
              v3->mVisible = 1;
              `eh vector destructor iterator(
                &ptr,
                0x30ui64,
                2,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
            }
          }
          else
          {
            v3->mUpdate = 1;
          }
        }
        else if ( v3->mVisible )
        {
          Scaleform::GFx::Movie::Invoke(v4, "UpgradePopup_Hide", 0i64, 0i64, 0);
          v3->mVisible = 0;
        }
      }
    }
  }
}

// File Line: 97
// RVA: 0x5D8AC0
void __fastcall UFG::UIHKUpgradePopupWidget::Flash(UFG::UIHKUpgradePopupWidget *this, const char *icon, const char *description)
{
  UFG::UIHKUpgradePopupWidget *v3; // rsi
  const char *v4; // rbx
  const char *v5; // rdi

  v3 = this;
  this->mUpdate = 1;
  v4 = description;
  v5 = icon;
  UFG::qString::Set(&this->mIcon, icon);
  UFG::qString::Set(&v3->mDescription, v4);
  v3->mDisplayTime = 0.0;
  v3->mState = 2;
  UFG::UIHKUpgradePopupWidget::LoadTexturePack(v3, v5);
}

// File Line: 109
// RVA: 0x60D2A0
void __fastcall UFG::UIHKUpgradePopupWidget::Show(UFG::UIHKUpgradePopupWidget *this, const char *icon, const char *description)
{
  UFG::UIHKUpgradePopupWidget *v3; // rsi
  const char *v4; // rbx
  const char *v5; // rdi

  v3 = this;
  this->mUpdate = 1;
  v4 = description;
  v5 = icon;
  UFG::qString::Set(&this->mIcon, icon);
  UFG::qString::Set(&v3->mDescription, v4);
  v3->mState = 1;
  UFG::UIHKUpgradePopupWidget::LoadTexturePack(v3, v5);
}

// File Line: 120
// RVA: 0x5ECC60
void __fastcall UFG::UIHKUpgradePopupWidget::Hide(UFG::UIHKUpgradePopupWidget *this)
{
  char *v1; // rbx
  UFG::UIHKUpgradePopupWidget *v2; // rdi
  UFG::UIScreenTextureManager *v3; // rax

  v1 = this->mTexturePack.mData;
  v2 = this;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, v1);
  *(_WORD *)&v2->mUpdate = 1;
  v2->mState = 0;
}

// File Line: 129
// RVA: 0x5F1590
void __fastcall UFG::UIHKUpgradePopupWidget::LoadTexturePack(UFG::UIHKUpgradePopupWidget *this, const char *icon)
{
  const char *v2; // rdi
  UFG::UIHKUpgradePopupWidget *v3; // rsi
  char *v4; // rbx
  UFG::UIScreenTextureManager *v5; // rax
  __int64 v6; // rax
  const char *v7; // rbx
  UFG::UIScreenTextureManager *v8; // rax
  UFG::qString v9; // [rsp+38h] [rbp-30h]

  v2 = icon;
  v3 = this;
  v4 = this->mTexturePack.mData;
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v5, v4);
  UFG::qString::qString(&v9, "Data\\UI\\%s_TexturePack.perm.bin", v2);
  UFG::qString::Set(&v3->mTexturePack, *(const char **)(v6 + 24), *(_DWORD *)(v6 + 20), 0i64, 0);
  UFG::qString::~qString(&v9);
  v7 = v3->mTexturePack.mData;
  v8 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v8,
    v7,
    DEFAULT_PRIORITY,
    UFG::UIHKUpgradePopupWidget::TextureLoadedCallback,
    0i64);
}

// File Line: 137
// RVA: 0x6131A0
void __fastcall UFG::UIHKUpgradePopupWidget::UnLoadTexturePack(UFG::UIHKUpgradePopupWidget *this)
{
  char *v1; // rbx
  UFG::UIHKUpgradePopupWidget *v2; // rdi
  UFG::UIScreenTextureManager *v3; // rax

  v1 = this->mTexturePack.mData;
  v2 = this;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, v1);
  v2->mTextureLoaded = 0;
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

