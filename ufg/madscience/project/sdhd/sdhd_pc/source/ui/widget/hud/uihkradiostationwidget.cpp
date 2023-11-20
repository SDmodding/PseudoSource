// File Line: 39
// RVA: 0x5C9DF0
void __fastcall UFG::UIHKRadioStationWidget::~UIHKRadioStationWidget(UFG::UIHKRadioStationWidget *this)
{
  UFG::UIHKRadioStationWidget *v1; // rdi
  char *v2; // rbx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIHKRadioStationData *v4; // rcx
  unsigned int *v5; // rbx
  UFG::UIHKRadioStationData *v6; // rcx
  unsigned int *v7; // rbx

  v1 = this;
  v2 = this->mLoadedTexturePack.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, v2);
  UFG::qString::Set(&v1->mLoadedTexturePack, &customWorldMapCaption);
  v1->mWaitingForTexture = 0;
  v4 = v1->mStationData.p;
  if ( v4 )
  {
    v5 = &v4[-1].texture.mStringHash32;
    `eh vector destructor iterator(
      v4,
      0x50ui64,
      v4[-1].texture.mStringHash32,
      (void (__fastcall *)(void *))UFG::UIHKRadioStationData::~UIHKRadioStationData);
    operator delete[](v5);
  }
  v1->mStationData.p = 0i64;
  *(_QWORD *)&v1->mStationData.size = 0i64;
  UFG::qString::~qString(&v1->mLoadedTexturePack);
  v6 = v1->mStationData.p;
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
  v1->mStationData.p = 0i64;
  *(_QWORD *)&v1->mStationData.size = 0i64;
}

// File Line: 46
// RVA: 0x5F2EF0
void __fastcall UFG::UIHKRadioStationWidget::OnRadioTurnedOff(UFG::UIHKRadioStationWidget *this)
{
  char *v1; // rbx
  UFG::UIHKRadioStationWidget *v2; // rdi
  UFG::UIScreenTextureManager *v3; // rax

  v1 = this->mLoadedTexturePack.mData;
  v2 = this;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, v1);
  UFG::qString::Set(&v2->mLoadedTexturePack, &customWorldMapCaption);
  v2->mWaitingForTexture = 0;
}

// File Line: 52
// RVA: 0x5FF110
void __fastcall UFG::UIHKRadioStationWidget::ReadStationList(UFG::UIHKRadioStationWidget *this)
{
  UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *v1; // rdi
  UFG::qArray<UFG::UIHKRadioStationData,0> *v2; // rsi
  __int64 v3; // rax
  __int64 v4; // rax
  __int64 v5; // r14
  unsigned int v6; // ebx
  unsigned int v7; // edx
  unsigned int v8; // edx
  UFG::qString *v9; // rbx
  UFG::qString v10; // [rsp+30h] [rbp-C8h]
  UFG::qString v11; // [rsp+58h] [rbp-A0h]
  __int64 v12; // [rsp+80h] [rbp-78h]
  UFG::qString v13; // [rsp+88h] [rbp-70h]
  UFG::qString v14; // [rsp+B0h] [rbp-48h]

  v12 = -2i64;
  v1 = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
  if ( &UFG::Radio::sm_stationList.mNode.mNext[-1].mNext != (UFG::qNode<UFG::RadioStation,UFG::RadioStation> **)((char *)&UFG::Radio::sm_stationList - 8) )
  {
    v2 = &this->mStationData;
    do
    {
      UFG::qString::qString(&v10);
      UFG::qString::qString(&v11);
      UFG::qString::qString(&v13, "img://%s", v1[11].mNode.mNext);
      UFG::qString::Set(&v11, *(const char **)(v3 + 24), *(_DWORD *)(v3 + 20), 0i64, 0);
      UFG::qString::~qString(&v13);
      UFG::qString::qString(&v14, "Data\\UI\\%s.perm.bin", v1[14].mNode.mPrev);
      UFG::qString::Set(&v10, *(const char **)(v4 + 24), *(_DWORD *)(v4 + 20), 0i64, 0);
      UFG::qString::~qString(&v14);
      v5 = v2->size;
      v6 = v5 + 1;
      v7 = v2->capacity;
      if ( (signed int)v5 + 1 > v7 )
      {
        if ( v7 )
          v8 = 2 * v7;
        else
          v8 = 1;
        for ( ; v8 < v6; v8 *= 2 )
          ;
        if ( v8 - v6 > 0x10000 )
          v8 = v5 + 65537;
        UFG::qArray<UFG::UIHKRadioStationData,0>::Reallocate(v2, v8, "qArray.Add");
      }
      v2->size = v6;
      v9 = &v2->p[v5].texturePack;
      UFG::qString::Set(v9, v10.mData, v10.mLength, 0i64, 0);
      UFG::qString::Set(v9 + 1, v11.mData, v11.mLength, 0i64, 0);
      UFG::qString::~qString(&v11);
      UFG::qString::~qString(&v10);
      v1 = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&v1[1].mNode.mPrev[-1].mNext;
    }
    while ( v1 != (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8) );
  }
}

// File Line: 65
// RVA: 0x616710
void __fastcall UFG::UIHKRadioStationWidget::Update(UFG::UIHKRadioStationWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // rdi
  UFG::UIHKRadioStationWidget *v4; // rbx
  float v5; // xmm0_4
  Scaleform::GFx::Movie *v6; // rcx
  float v7; // xmm6_4
  bool v8; // r8
  __int64 v9; // rax
  UFG::UIHKRadioStationData *v10; // r8

  v3 = screen;
  v4 = this;
  if ( this->mState == 2 )
  {
    v5 = elapsed + this->mTimeSinceLastInput;
    this->mTimeSinceLastInput = v5;
    if ( v5 > 4.0 )
    {
      v6 = screen->mRenderable->m_movie.pObject;
      if ( v6 )
        Scaleform::GFx::Movie::Invoke(v6, "mc_RadioStations.Deactivate", 0i64, 0i64, 0);
      v4->mState = 3;
    }
    if ( v4->mWaitingForTexture )
    {
      v7 = elapsed + v4->mWaitingForTextureTimer;
      v4->mWaitingForTextureTimer = v7;
      if ( v7 > 2.0 )
      {
        v4->mWaitingForTexture = 0;
        v4->mChanged = 1;
        UFG::UIHKRadioStationWidget::Flash_SetTexture(v4, v3, &customWorldMapCaption);
      }
    }
  }
  if ( v4->mChanged )
  {
    v8 = v4->mVisible;
    v4->mChanged = 0;
    UFG::UIHKRadioStationWidget::Flash_SetVisible(v4, v3, v8);
    if ( v4->mVisible )
    {
      if ( v4->mWaitingForTexture )
      {
        UFG::UIHKRadioStationWidget::Flash_SetTexture(v4, v3, &customWorldMapCaption);
      }
      else if ( v4->mShouldRefreshTextures )
      {
        v9 = v4->mCurrentStation;
        v10 = v4->mStationData.p;
        v4->mShouldRefreshTextures = 0;
        UFG::UIHKRadioStationWidget::Flash_SetTexture(v4, v3, v10[v9].texture.mData);
        if ( v4->mState == 1 )
        {
          UFG::UIHKRadioStationWidget::Flash_Intro(v4, v3);
          v4->mState = 2;
        }
      }
      UFG::UIHKRadioStationWidget::Flash_SetSongTitle(v4, v3);
      UFG::UIHKRadioStationWidget::Flash_SetStationName(v4, v3);
    }
  }
}

// File Line: 155
// RVA: 0x5EDFF0
bool __fastcall UFG::UIHKRadioStationWidget::IsActive(UFG::UIHKRadioStationWidget *this)
{
  return this->mState && this->mState != 3;
}

// File Line: 168
// RVA: 0x5D4C80
void __fastcall UFG::UIHKRadioStationWidget::ChangeStation(UFG::UIHKRadioStationWidget *this, unsigned int stationID)
{
  int v2; // er8
  int v3; // edx

  v2 = stationID - 1;
  v3 = this->mCurrentStation;
  this->mTimeSinceLastInput = 0.0;
  UFG::UIHKRadioStationWidget::LoadTextures(this, v3, v2);
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
  Scaleform::GFx::Movie *v2; // rcx

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 )
    Scaleform::GFx::Movie::Invoke(v2, "mc_RadioStations.Activate", 0i64, 0i64, 0);
}

// File Line: 208
// RVA: 0x5E1310
void __fastcall UFG::UIHKRadioStationWidget::Flash_SetTexture(UFG::UIHKRadioStationWidget *this, UFG::UIScreen *screen, const char *texture)
{
  const char *v3; // rdi
  Scaleform::GFx::Movie *v4; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v3 = texture;
  v4 = screen->mRenderable->m_movie.pObject;
  if ( v4 )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v3;
    Scaleform::GFx::Movie::Invoke(v4, "mc_RadioStations.SetTexture", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 222
// RVA: 0x5E0D10
void __fastcall UFG::UIHKRadioStationWidget::Flash_SetSongTitle(UFG::UIHKRadioStationWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rbx
  const char *v3; // rax
  const char *v4; // rax
  char *v5; // rdi
  UFG::qString v6; // [rsp+38h] [rbp-60h]
  char ptr; // [rsp+60h] [rbp-38h]
  __int64 v8; // [rsp+70h] [rbp-28h]
  unsigned int v9; // [rsp+78h] [rbp-20h]
  char *v10; // [rsp+80h] [rbp-18h]

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2
    && UFG::RadioFullyControlled::sm_playerRadio
    && UFG::RadioFullyControlled::GetCurrentlyPlayingSong(UFG::RadioFullyControlled::sm_playerRadio) )
  {
    v3 = UFG::RadioFullyControlled::GetCurrentlyPlayingSong(UFG::RadioFullyControlled::sm_playerRadio);
    v4 = UFG::UI::LocalizeText(v3);
    UFG::qString::qString(&v6, v4);
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v5 = v6.mData;
    if ( (v9 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v8 + 16i64))(v8, &ptr, v10);
      v8 = 0i64;
    }
    v9 = 6;
    v10 = v5;
    Scaleform::GFx::Movie::Invoke(v2, "mc_RadioStations.SetSongTitle", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&v6);
  }
}

// File Line: 246
// RVA: 0x5E0E40
void __fastcall UFG::UIHKRadioStationWidget::Flash_SetStationName(UFG::UIHKRadioStationWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rbx
  const char *v3; // rax
  char *v4; // rdi
  UFG::qString v5; // [rsp+38h] [rbp-60h]
  char ptr; // [rsp+60h] [rbp-38h]
  __int64 v7; // [rsp+70h] [rbp-28h]
  unsigned int v8; // [rsp+78h] [rbp-20h]
  char *v9; // [rsp+80h] [rbp-18h]

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 && UFG::RadioFullyControlled::sm_playerRadio )
  {
    v3 = UFG::UI::LocalizeText(UFG::RadioFullyControlled::sm_playerRadio->m_curStation->m_name);
    UFG::qString::qString(&v5, v3);
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v4 = v5.mData;
    if ( (v8 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v7 + 16i64))(v7, &ptr, v9);
      v7 = 0i64;
    }
    v8 = 6;
    v9 = v4;
    Scaleform::GFx::Movie::Invoke(v2, "mc_RadioStations.SetStationName", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&v5);
  }
}

// File Line: 267
// RVA: 0x5E1D20
void __fastcall UFG::UIHKRadioStationWidget::Flash_SetVisible(UFG::UIHKRadioStationWidget *this, UFG::UIScreen *screen, bool visible)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  if ( screen )
  {
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      value.pObjectInterface = 0i64;
      value.Type = 2;
      value.mValue.BValue = visible;
      Scaleform::GFx::Movie::SetVariable(v3, "mc_RadioStations._visible", &value, 1i64);
      if ( ((unsigned int)value.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
    }
  }
}

// File Line: 282
// RVA: 0x612890
void __fastcall UFG::UIHKRadioStationWidget::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenHud *v2; // rax
  UFG::UIHKRadioStationWidget::eState v3; // ecx

  v2 = UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    if ( (_DWORD)param == UFG::UIHKScreenHud::mInstance->RadioStationWidget.mCurrentStation )
    {
      v3 = UFG::UIHKScreenHud::mInstance->RadioStationWidget.mState;
      *(_WORD *)&UFG::UIHKScreenHud::mInstance->RadioStationWidget.mShouldRefreshTextures = 1;
      v2->RadioStationWidget.mChanged = 1;
      v2->RadioStationWidget.mTimeSinceLastInput = 0.0;
      if ( v3 == STATE_IDLE || v3 == 3 )
        v2->RadioStationWidget.mState = 1;
    }
  }
}

// File Line: 316
// RVA: 0x5F1870
void __fastcall UFG::UIHKRadioStationWidget::LoadTextures(UFG::UIHKRadioStationWidget *this, int oldStationIdx, int newStationIdx)
{
  void *v3; // rsi
  UFG::UIHKRadioStationWidget *v4; // rdi
  const char *v5; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  const char *v7; // rdi
  UFG::UIScreenTextureManager *v8; // rax
  UFG::UIHKRadioStationWidget::eState v9; // eax

  v3 = (void *)newStationIdx;
  v4 = this;
  if ( (unsigned int)UFG::qStringCompare(
                       this->mLoadedTexturePack.mData,
                       this->mStationData.p[newStationIdx].texturePack.mData,
                       -1) )
  {
    v5 = v4->mLoadedTexturePack.mData;
    v6 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v6, v5);
    UFG::qString::Set(
      &v4->mLoadedTexturePack,
      v4->mStationData.p[(unsigned int)v3].texturePack.mData,
      v4->mStationData.p[(unsigned int)v3].texturePack.mLength,
      0i64,
      0);
    v4->mCurrentStation = (unsigned int)v3;
    v4->mWaitingForTexture = 1;
    v4->mWaitingForTextureTimer = 0.0;
    v7 = v4->mLoadedTexturePack.mData;
    v8 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v8,
      v7,
      DEFAULT_PRIORITY,
      UFG::UIHKRadioStationWidget::TextureLoadedCallback,
      v3);
  }
  else if ( !v4->mWaitingForTexture && (_DWORD)v3 == v4->mCurrentStation )
  {
    v9 = v4->mState;
    *(_WORD *)&v4->mShouldRefreshTextures = 1;
    v4->mChanged = 1;
    v4->mTimeSinceLastInput = 0.0;
    if ( v9 == STATE_IDLE || v9 == 3 )
      v4->mState = 1;
  }
}

