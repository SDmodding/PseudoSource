// File Line: 43
// RVA: 0x6161F0
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::Update(
        UFG::UIHKPhoneTraceSignalBarWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // r14
  UFG::UIHKPhoneTraceSignalBarWidget::eState mState; // ecx
  __int32 v5; // ecx
  __int32 v6; // ecx
  __int32 v7; // ecx
  Scaleform::GFx::Value::ValueUnion v8; // xmm6_8
  int v9; // edi
  double mDirectionStrength; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+38h] [rbp-19h] BYREF
  char v12[16]; // [rsp+68h] [rbp+17h] BYREF
  __int64 v13; // [rsp+78h] [rbp+27h]
  int v14; // [rsp+80h] [rbp+2Fh]
  double v15; // [rsp+88h] [rbp+37h]

  if ( !this->mUpdate )
    return;
  this->mUpdate = 0;
  if ( !screen )
    return;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( !pObject )
    return;
  mState = this->mState;
  if ( mState == STATE_HIDE )
  {
    if ( this->mVisible )
    {
      Scaleform::GFx::Movie::Invoke(pObject, "TraceSignalBar_Hide", 0i64, 0i64, 0);
      this->mVisible = 0;
    }
    return;
  }
  v5 = mState - 1;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( v7 )
      {
        if ( v7 != 1 )
          return;
        if ( !this->mTextureLoaded )
          goto LABEL_10;
        if ( !this->mVisible )
        {
          UFG::UIHKPhoneTraceSignalBarWidget::Flash_Show(this, screen);
          this->mVisible = 1;
          this->mState = STATE_LOOKING_FOR_SIGNAL;
        }
        return;
      }
      if ( !this->mVisible )
      {
        UFG::UIHKPhoneTraceSignalBarWidget::Flash_Show(this, screen);
        this->mVisible = 1;
      }
      if ( UFG::UIHKScreenPhoneTraceMinigame::gPhoneTraceEnabled )
        return;
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Boolean;
      ptr.mValue.BValue = 0;
      Scaleform::GFx::Movie::Invoke(pObject, "TraceSignalBar_SetCanTrace", 0i64, &ptr, 1u);
      this->mState = STATE_LOOKING_FOR_SIGNAL;
    }
    else
    {
      if ( !this->mVisible )
      {
        UFG::UIHKPhoneTraceSignalBarWidget::Flash_Show(this, screen);
        this->mVisible = 1;
      }
      if ( !UFG::UIHKScreenPhoneTraceMinigame::gPhoneTraceEnabled )
        return;
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Boolean;
      ptr.mValue.BValue = 1;
      Scaleform::GFx::Movie::Invoke(pObject, "TraceSignalBar_SetCanTrace", 0i64, &ptr, 1u);
      this->mState = STATE_FOUND_SIGNAL;
    }
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    return;
  }
  if ( !this->mTextureLoaded )
  {
LABEL_10:
    this->mUpdate = 1;
    return;
  }
  if ( !this->mVisible )
  {
    UFG::UIHKPhoneTraceSignalBarWidget::Flash_Show(this, screen);
    this->mVisible = 1;
  }
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v8.NValue = (double)this->mDistanceStrength;
  v9 = 0;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue = v8;
  mDirectionStrength = (double)this->mDirectionStrength;
  if ( (v14 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v13 + 16i64))(v13, v12, COERCE_DOUBLE(*(_QWORD *)&v15));
    v13 = 0i64;
  }
  v14 = 5;
  v15 = mDirectionStrength;
  Scaleform::GFx::Movie::Invoke(pObject, "TraceSignalBar_Set", 0i64, &ptr, 2u);
  LOBYTE(v9) = UFG::UIHKScreenPhoneTraceMinigame::gPhoneTraceEnabled;
  this->mState = v9 + 2;
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 135
// RVA: 0x609DC0
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::SetStrength(
        UFG::UIHKPhoneTraceSignalBarWidget *this,
        int distance,
        int direction)
{
  this->mState = STATE_SETTING;
  this->mDistanceStrength = distance;
  this->mDirectionStrength = direction;
  this->mUpdate = 1;
}

// File Line: 146
// RVA: 0x60C560
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::SetUpdate(UFG::UIHKPhoneTraceSignalBarWidget *this)
{
  this->mUpdate = 1;
}

// File Line: 152
// RVA: 0x60D1D0
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::Show(
        UFG::UIHKPhoneTraceSignalBarWidget *this,
        int initDistance,
        int initDirection)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v5; // rax
  char *v6; // rbx
  UFG::UIScreenTextureManager *v7; // rax

  mData = this->mTexturePack.mData;
  this->mDistanceStrength = initDistance;
  this->mDirectionStrength = initDirection;
  this->mState = STATE_WAITING_FOR_TEXTURE_LOAD;
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v5, mData);
  v6 = this->mTexturePack.mData;
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v7,
    v6,
    DEFAULT_PRIORITY,
    (UFG::qReflectInventoryBase *)UFG::UIHKPhoneTraceSignalBarWidget::TextureLoadedCallback,
    0i64);
}

// File Line: 161
// RVA: 0x5ECBF0
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::Hide(UFG::UIHKPhoneTraceSignalBarWidget *this)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v3; // rax

  mData = this->mTexturePack.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, mData);
  *(_WORD *)&this->mUpdate = 1;
  this->mState = STATE_HIDE;
}

// File Line: 191
// RVA: 0x612860
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::TextureLoadedCallback(
        UFG::DataStreamer::Handle *handle,
        void *param)
{
  UFG::UIHKPhoneTraceSignalBarWidget *v2; // rax

  if ( UFG::UIHKScreenHud::mInstance )
  {
    v2 = UFG::UIHKScreenHud::TraceSignalBar;
    if ( UFG::UIHKScreenHud::TraceSignalBar )
    {
      *(_WORD *)&UFG::UIHKScreenHud::TraceSignalBar->mUpdate = 257;
      v2->mState = STATE_PLAYING_INTRO;
    }
  }
}

// File Line: 202
// RVA: 0x5E35A0
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::Flash_Show(
        UFG::UIHKPhoneTraceSignalBarWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value::ValueUnion v4; // xmm6_8
  double mDirectionStrength; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-78h] BYREF
  char v7[16]; // [rsp+70h] [rbp-48h] BYREF
  __int64 v8; // [rsp+80h] [rbp-38h]
  int v9; // [rsp+88h] [rbp-30h]
  double v10; // [rsp+90h] [rbp-28h]

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v4.NValue = (double)this->mDistanceStrength;
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Number;
      ptr.mValue = v4;
      mDirectionStrength = (double)this->mDirectionStrength;
      if ( (v9 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v8 + 16i64))(
          v8,
          v7,
          COERCE_DOUBLE(*(_QWORD *)&v10));
        v8 = 0i64;
      }
      v9 = 5;
      v10 = mDirectionStrength;
      Scaleform::GFx::Movie::Invoke(pObject, "TraceSignalBar_Show", 0i64, &ptr, 2u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

