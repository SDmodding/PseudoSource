// File Line: 43
// RVA: 0x6161F0
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::Update(UFG::UIHKPhoneTraceSignalBarWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKPhoneTraceSignalBarWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // r14
  UFG::UIHKPhoneTraceSignalBarWidget::eState v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  double v8; // xmm6_8
  int v9; // edi
  double v10; // xmm6_8
  char ptr; // [rsp+38h] [rbp-19h]
  __int64 v12; // [rsp+48h] [rbp-9h]
  unsigned int v13; // [rsp+50h] [rbp-1h]
  __int64 v14; // [rsp+58h] [rbp+7h]
  char v15; // [rsp+68h] [rbp+17h]
  __int64 v16; // [rsp+78h] [rbp+27h]
  unsigned int v17; // [rsp+80h] [rbp+2Fh]
  double v18; // [rsp+88h] [rbp+37h]

  v2 = this;
  if ( !this->mUpdate )
    return;
  this->mUpdate = 0;
  if ( !screen )
    return;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( !v3 )
    return;
  v4 = this->mState;
  if ( v4 == STATE_HIDE )
  {
    if ( v2->mVisible )
    {
      Scaleform::GFx::Movie::Invoke(v3, "TraceSignalBar_Hide", 0i64, 0i64, 0);
      v2->mVisible = 0;
    }
    return;
  }
  v5 = v4 - 1;
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
        if ( !v2->mTextureLoaded )
          goto LABEL_10;
        if ( !v2->mVisible )
        {
          UFG::UIHKPhoneTraceSignalBarWidget::Flash_Show(v2, screen);
          v2->mVisible = 1;
          v2->mState = 2;
        }
        return;
      }
      if ( !v2->mVisible )
      {
        UFG::UIHKPhoneTraceSignalBarWidget::Flash_Show(v2, screen);
        v2->mVisible = 1;
      }
      if ( UFG::UIHKScreenPhoneTraceMinigame::gPhoneTraceEnabled )
        return;
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v13 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v12 + 16i64))(v12, &ptr, v14);
        v12 = 0i64;
      }
      v13 = 2;
      LOBYTE(v14) = 0;
      Scaleform::GFx::Movie::Invoke(v3, "TraceSignalBar_SetCanTrace", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
      v2->mState = 2;
    }
    else
    {
      if ( !v2->mVisible )
      {
        UFG::UIHKPhoneTraceSignalBarWidget::Flash_Show(v2, screen);
        v2->mVisible = 1;
      }
      if ( !UFG::UIHKScreenPhoneTraceMinigame::gPhoneTraceEnabled )
        return;
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v13 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v12 + 16i64))(v12, &ptr, v14);
        v12 = 0i64;
      }
      v13 = 2;
      LOBYTE(v14) = 1;
      Scaleform::GFx::Movie::Invoke(v3, "TraceSignalBar_SetCanTrace", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
      v2->mState = 3;
    }
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    return;
  }
  if ( !v2->mTextureLoaded )
  {
LABEL_10:
    v2->mUpdate = 1;
    return;
  }
  if ( !v2->mVisible )
  {
    UFG::UIHKPhoneTraceSignalBarWidget::Flash_Show(v2, screen);
    v2->mVisible = 1;
  }
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v8 = (double)v2->mDistanceStrength;
  v9 = 0;
  if ( (v13 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v12 + 16i64))(v12, &ptr, v14);
    v12 = 0i64;
  }
  v13 = 5;
  v14 = *(_QWORD *)&v8;
  v10 = (double)v2->mDirectionStrength;
  if ( (v17 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v16 + 16i64))(
      v16,
      &v15,
      COERCE_DOUBLE(*(_QWORD *)&v18));
    v16 = 0i64;
  }
  v17 = 5;
  v18 = v10;
  Scaleform::GFx::Movie::Invoke(v3, "TraceSignalBar_Set", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  LOBYTE(v9) = UFG::UIHKScreenPhoneTraceMinigame::gPhoneTraceEnabled != 0;
  v2->mState = v9 + 2;
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}2->mState

// File Line: 135
// RVA: 0x609DC0
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::SetStrength(UFG::UIHKPhoneTraceSignalBarWidget *this, int distance, int direction)
{
  this->mState = 1;
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
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::Show(UFG::UIHKPhoneTraceSignalBarWidget *this, int initDistance, int initDirection)
{
  char *v3; // rbx
  UFG::UIHKPhoneTraceSignalBarWidget *v4; // rdi
  UFG::UIScreenTextureManager *v5; // rax
  const char *v6; // rbx
  UFG::UIScreenTextureManager *v7; // rax

  v3 = this->mTexturePack.mData;
  v4 = this;
  this->mDistanceStrength = initDistance;
  this->mDirectionStrength = initDirection;
  this->mState = 5;
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v5, v3);
  v6 = v4->mTexturePack.mData;
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v7,
    v6,
    DEFAULT_PRIORITY,
    UFG::UIHKPhoneTraceSignalBarWidget::TextureLoadedCallback,
    0i64);
}

// File Line: 161
// RVA: 0x5ECBF0
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::Hide(UFG::UIHKPhoneTraceSignalBarWidget *this)
{
  char *v1; // rbx
  UFG::UIHKPhoneTraceSignalBarWidget *v2; // rdi
  UFG::UIScreenTextureManager *v3; // rax

  v1 = this->mTexturePack.mData;
  v2 = this;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, v1);
  *(_WORD *)&v2->mUpdate = 1;
  v2->mState = 0;
}

// File Line: 191
// RVA: 0x612860
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKPhoneTraceSignalBarWidget *v2; // rax

  if ( UFG::UIHKScreenHud::mInstance )
  {
    v2 = UFG::UIHKScreenHud::TraceSignalBar;
    if ( UFG::UIHKScreenHud::TraceSignalBar )
    {
      *(_WORD *)&UFG::UIHKScreenHud::TraceSignalBar->mUpdate = 257;
      v2->mState = 4;
    }
  }
}

// File Line: 202
// RVA: 0x5E35A0
void __fastcall UFG::UIHKPhoneTraceSignalBarWidget::Flash_Show(UFG::UIHKPhoneTraceSignalBarWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKPhoneTraceSignalBarWidget *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  double v4; // xmm6_8
  double v5; // xmm6_8
  char ptr; // [rsp+40h] [rbp-78h]
  __int64 v7; // [rsp+50h] [rbp-68h]
  unsigned int v8; // [rsp+58h] [rbp-60h]
  double v9; // [rsp+60h] [rbp-58h]
  char v10; // [rsp+70h] [rbp-48h]
  __int64 v11; // [rsp+80h] [rbp-38h]
  unsigned int v12; // [rsp+88h] [rbp-30h]
  double v13; // [rsp+90h] [rbp-28h]

  if ( screen )
  {
    v2 = this;
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v4 = (double)v2->mDistanceStrength;
      if ( (v8 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v7 + 16i64))(
          v7,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v9));
        v7 = 0i64;
      }
      v8 = 5;
      v9 = v4;
      v5 = (double)v2->mDirectionStrength;
      if ( (v12 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
          v11,
          &v10,
          COERCE_DOUBLE(*(_QWORD *)&v13));
        v11 = 0i64;
      }
      v12 = 5;
      v13 = v5;
      Scaleform::GFx::Movie::Invoke(v3, "TraceSignalBar_Show", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

