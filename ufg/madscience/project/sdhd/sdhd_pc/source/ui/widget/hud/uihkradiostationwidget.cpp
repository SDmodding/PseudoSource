// File Line: 39
// RVA: 0x5C9DF0
void __fastcall UFG::UIHKRadioStationWidget::~UIHKRadioStationWidget(UFG::UIHKRadioStationWidget *this)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIHKRadioStationData *p; // rcx
  unsigned int *p_mStringHash32; // rbx
  UFG::UIHKRadioStationData *v6; // rcx
  unsigned int *v7; // rbx

  mData = this->mLoadedTexturePack.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, mData);
  UFG::qString::Set(&this->mLoadedTexturePack, &customCaption);
  this->mWaitingForTexture = 0;
  p = this->mStationData.p;
  if ( p )
  {
    p_mStringHash32 = &p[-1].texture.mStringHash32;
    `eh vector destructor iterator(
      p,
      0x50ui64,
      p[-1].texture.mStringHash32,
      (void (__fastcall *)(void *))UFG::UIHKRadioStationData::~UIHKRadioStationData);
    operator delete[](p_mStringHash32);
  }
  this->mStationData.p = 0i64;
  *(_QWORD *)&this->mStationData.size = 0i64;
  UFG::qString::~qString(&this->mLoadedTexturePack);
  v6 = this->mStationData.p;
  if ( v6 )
  {
    v7 = &v6[-1].texture.mStringHash32;
    `eh vector destructor iterator(
      v6,
      0x50ui64,
      v6[-1].texture.mStringHash32,
      (void (__fastcall *)(void *))UFG::UIHKRadioStationData::~UIHKRadioStationData);
    operator delete[](v7);
  }
  this->mStationData.p = 0i64;
  *(_QWORD *)&this->mStationData.size = 0i64;
}

// File Line: 46
// RVA: 0x5F2EF0
void __fastcall UFG::UIHKRadioStationWidget::OnRadioTurnedOff(UFG::UIHKRadioStationWidget *this)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v3; // rax

  mData = this->mLoadedTexturePack.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, mData);
  UFG::qString::Set(&this->mLoadedTexturePack, &customCaption);
  this->mWaitingForTexture = 0;
}

// File Line: 52
// RVA: 0x5FF110
void __fastcall UFG::UIHKRadioStationWidget::ReadStationList(UFG::UIHKRadioStationWidget *this)
{
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> **p_mNext; // rdi
  UFG::qArray<UFG::UIHKRadioStationData,0> *p_mStationData; // rsi
  __int64 v3; // rax
  __int64 v4; // rax
  __int64 size; // r14
  unsigned int v6; // ebx
  unsigned int capacity; // edx
  unsigned int v8; // edx
  UFG::qString *p_texturePack; // rbx
  UFG::qString v10; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qString v11; // [rsp+58h] [rbp-A0h] BYREF
  __int64 v12; // [rsp+80h] [rbp-78h]
  UFG::qString v13; // [rsp+88h] [rbp-70h] BYREF
  UFG::qString v14; // [rsp+B0h] [rbp-48h] BYREF

  v12 = -2i64;
  p_mNext = &UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
  if ( &UFG::Radio::sm_stationList.mNode.mNext[-1].mNext != (UFG::qNode<UFG::RadioStation,UFG::RadioStation> **)((char *)&UFG::Radio::sm_stationList - 8) )
  {
    p_mStationData = &this->mStationData;
    do
    {
      UFG::qString::qString(&v10);
      UFG::qString::qString(&v11);
      UFG::qString::qString(&v13, "img://%s", (const char *)p_mNext[23]);
      UFG::qString::Set(&v11, *(const char **)(v3 + 24), *(_DWORD *)(v3 + 20), 0i64, 0);
      UFG::qString::~qString(&v13);
      UFG::qString::qString(&v14, "Data\\UI\\%s.perm.bin", (const char *)p_mNext[28]);
      UFG::qString::Set(&v10, *(const char **)(v4 + 24), *(_DWORD *)(v4 + 20), 0i64, 0);
      UFG::qString::~qString(&v14);
      size = p_mStationData->size;
      v6 = size + 1;
      capacity = p_mStationData->capacity;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v8 = 2 * capacity;
        else
          v8 = 1;
        for ( ; v8 < v6; v8 *= 2 )
          ;
        if ( v8 - v6 > 0x10000 )
          v8 = size + 65537;
        UFG::qArray<UFG::UIHKRadioStationData,0>::Reallocate(p_mStationData, v8, "qArray.Add");
      }
      p_mStationData->size = v6;
      p_texturePack = &p_mStationData->p[size].texturePack;
      UFG::qString::Set(p_texturePack, v10.mData, v10.mLength, 0i64, 0);
      UFG::qString::Set(p_texturePack + 1, v11.mData, v11.mLength, 0i64, 0);
      UFG::qString::~qString(&v11);
      UFG::qString::~qString(&v10);
      p_mNext = &p_mNext[2][-1].mNext;
    }
    while ( p_mNext != (UFG::qNode<UFG::RadioStation,UFG::RadioStation> **)((char *)&UFG::Radio::sm_stationList - 8) );
  }
}

// File Line: 65
// RVA: 0x616710
void __fastcall UFG::UIHKRadioStationWidget::Update(
        UFG::UIHKRadioStationWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  float v5; // xmm0_4
  Scaleform::GFx::Movie *pObject; // rcx
  float v7; // xmm6_4
  bool mVisible; // r8
  __int64 mCurrentStation; // rax
  UFG::UIHKRadioStationData *p; // r8

  if ( this->mState == STATE_PHONE_CONTACTS )
  {
    v5 = elapsed + this->mTimeSinceLastInput;
    this->mTimeSinceLastInput = v5;
    if ( v5 > 4.0 )
    {
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
        Scaleform::GFx::Movie::Invoke(pObject, "mc_RadioStations.Deactivate", 0i64, 0i64, 0);
      this->mState = STATE_TEXT_INBOX;
    }
    if ( this->mWaitingForTexture )
    {
      v7 = elapsed + this->mWaitingForTextureTimer;
      this->mWaitingForTextureTimer = v7;
      if ( v7 > 2.0 )
      {
        this->mWaitingForTexture = 0;
        this->mChanged = 1;
        UFG::UIHKRadioStationWidget::Flash_SetTexture(this, screen, &customCaption);
      }
    }
  }
  if ( this->mChanged )
  {
    mVisible = this->mVisible;
    this->mChanged = 0;
    UFG::UIHKRadioStationWidget::Flash_SetVisible(this, screen, mVisible);
    if ( this->mVisible )
    {
      if ( this->mWaitingForTexture )
      {
        UFG::UIHKRadioStationWidget::Flash_SetTexture(this, screen, &customCaption);
      }
      else if ( this->mShouldRefreshTextures )
      {
        mCurrentStation = this->mCurrentStation;
        p = this->mStationData.p;
        this->mShouldRefreshTextures = 0;
        UFG::UIHKRadioStationWidget::Flash_SetTexture(this, screen, p[mCurrentStation].texture.mData);
        if ( this->mState == STATE_ROOT_MENU )
        {
          UFG::UIHKRadioStationWidget::Flash_Intro(this, screen);
          this->mState = STATE_PHONE_CONTACTS;
        }
      }
      UFG::UIHKRadioStationWidget::Flash_SetSongTitle(this, screen);
      UFG::UIHKRadioStationWidget::Flash_SetStationName(this, screen);
    }
  }
}

// File Line: 155
// RVA: 0x5EDFF0
bool __fastcall UFG::UIHKRadioStationWidget::IsActive(UFG::UIHKRadioStationWidget *this)
{
  return this->mState && this->mState != STATE_TEXT_INBOX;
}

// File Line: 168
// RVA: 0x5D4C80
void __fastcall UFG::UIHKRadioStationWidget::ChangeStation(UFG::UIHKRadioStationWidget *this, unsigned int stationID)
{
  int v2; // r8d
  int mCurrentStation; // edx

  v2 = stationID - 1;
  mCurrentStation = this->mCurrentStation;
  this->mTimeSinceLastInput = 0.0;
  UFG::UIHKRadioStationWidget::LoadTextures(this, mCurrentStation, v2);
}

// File Line: 182
// RVA: 0x5EB540
void __fastcall UFG::UIHKRadioStationWidget::HandleNewSong(UFG::UIHKRadioStationWidget *this)
{
  this->mChanged = 1;
}

// File Line: 188
// RVA: 0x5DE590
void __fastcall UFG::UIHKRadioStationWidget::Flash_Intro(UFG::UIHKRadioStationWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "mc_RadioStations.Activate", 0i64, 0i64, 0);
}

// File Line: 208
// RVA: 0x5E1310
void __fastcall UFG::UIHKRadioStationWidget::Flash_SetTexture(
        UFG::UIHKRadioStationWidget *this,
        UFG::UIScreen *screen,
        const char *texture)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_String;
    pargs.mValue.pString = texture;
    Scaleform::GFx::Movie::Invoke(pObject, "mc_RadioStations.SetTexture", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 222
// RVA: 0x5E0D10
void __fastcall UFG::UIHKRadioStationWidget::Flash_SetSongTitle(
        UFG::UIHKRadioStationWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  const char *CurrentlyPlayingSong; // rax
  const char *v4; // rax
  char *mData; // rdi
  UFG::qString v6; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-38h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject
    && UFG::RadioFullyControlled::sm_playerRadio
    && UFG::RadioFullyControlled::GetCurrentlyPlayingSong(UFG::RadioFullyControlled::sm_playerRadio) )
  {
    CurrentlyPlayingSong = UFG::RadioFullyControlled::GetCurrentlyPlayingSong(UFG::RadioFullyControlled::sm_playerRadio);
    v4 = UFG::UI::LocalizeText(CurrentlyPlayingSong);
    UFG::qString::qString(&v6, v4);
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mData = v6.mData;
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
    Scaleform::GFx::Movie::Invoke(pObject, "mc_RadioStations.SetSongTitle", 0i64, &ptr, 1u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&v6);
  }
}

// File Line: 246
// RVA: 0x5E0E40
void __fastcall UFG::UIHKRadioStationWidget::Flash_SetStationName(
        UFG::UIHKRadioStationWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  const char *v3; // rax
  char *mData; // rdi
  UFG::qString v5; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-38h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject && UFG::RadioFullyControlled::sm_playerRadio )
  {
    v3 = UFG::UI::LocalizeText(UFG::RadioFullyControlled::sm_playerRadio->m_curStation->m_name);
    UFG::qString::qString(&v5, v3);
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mData = v5.mData;
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
    Scaleform::GFx::Movie::Invoke(pObject, "mc_RadioStations.SetStationName", 0i64, &ptr, 1u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&v5);
  }
}

// File Line: 267
// RVA: 0x5E1D20
void __fastcall UFG::UIHKRadioStationWidget::Flash_SetVisible(
        UFG::UIHKRadioStationWidget *this,
        UFG::UIScreen *screen,
        bool visible)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      value.pObjectInterface = 0i64;
      value.Type = VT_Boolean;
      value.mValue.BValue = visible;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_RadioStations._visible", &value, 1i64);
      if ( (value.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
    }
  }
}

// File Line: 282
// RVA: 0x612890
void __fastcall UFG::UIHKRadioStationWidget::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenHud *v2; // rax
  UFG::UIHKRadioStationWidget::eState mState; // ecx

  v2 = UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    if ( (_DWORD)param == UFG::UIHKScreenHud::mInstance->RadioStationWidget.mCurrentStation )
    {
      mState = UFG::UIHKScreenHud::mInstance->RadioStationWidget.mState;
      *(_WORD *)&UFG::UIHKScreenHud::mInstance->RadioStationWidget.mShouldRefreshTextures = 1;
      v2->RadioStationWidget.mChanged = 1;
      v2->RadioStationWidget.mTimeSinceLastInput = 0.0;
      if ( mState == STATE_IDLE || mState == STATE_TEXT_INBOX )
        v2->RadioStationWidget.mState = STATE_ROOT_MENU;
    }
  }
}

// File Line: 316
// RVA: 0x5F1870
void __fastcall UFG::UIHKRadioStationWidget::LoadTextures(
        UFG::UIHKRadioStationWidget *this,
        int oldStationIdx,
        int newStationIdx)
{
  UFG::qReflectInventoryBase *v3; // rsi
  char *mData; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  char *v7; // rdi
  UFG::UIScreenTextureManager *v8; // rax
  UFG::UIHKRadioStationWidget::eState mState; // eax

  v3 = (UFG::qReflectInventoryBase *)newStationIdx;
  if ( (unsigned int)UFG::qStringCompare(
                       this->mLoadedTexturePack.mData,
                       this->mStationData.p[newStationIdx].texturePack.mData,
                       -1) )
  {
    mData = this->mLoadedTexturePack.mData;
    v6 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v6, mData);
    UFG::qString::Set(
      &this->mLoadedTexturePack,
      this->mStationData.p[(unsigned int)v3].texturePack.mData,
      this->mStationData.p[(unsigned int)v3].texturePack.mLength,
      0i64,
      0);
    this->mCurrentStation = (unsigned int)v3;
    this->mWaitingForTexture = 1;
    this->mWaitingForTextureTimer = 0.0;
    v7 = this->mLoadedTexturePack.mData;
    v8 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v8,
      v7,
      DEFAULT_PRIORITY,
      (UFG::qReflectInventoryBase *)UFG::UIHKRadioStationWidget::TextureLoadedCallback,
      v3);
  }
  else if ( !this->mWaitingForTexture && (_DWORD)v3 == this->mCurrentStation )
  {
    mState = this->mState;
    *(_WORD *)&this->mShouldRefreshTextures = 1;
    this->mChanged = 1;
    this->mTimeSinceLastInput = 0.0;
    if ( mState == STATE_IDLE || mState == STATE_TEXT_INBOX )
      this->mState = STATE_ROOT_MENU;
  }
}

