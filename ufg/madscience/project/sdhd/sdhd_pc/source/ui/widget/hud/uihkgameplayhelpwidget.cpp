// File Line: 31
// RVA: 0x156DB90
__int64 UFG::_dynamic_initializer_for__gGameplayHelpSentinel__()
{
  UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&stru_14208EBE8);
  unk_14208ECD0 = 0;
  unk_14208ECD4 = 0;
  UFG::qString::qString(&stru_14208ECD8);
  unk_14208ED00 = 0;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gGameplayHelpSentinel__);
}

// File Line: 39
// RVA: 0x5C3FA0
void __fastcall UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(UFG::UIHKGameplayHelpData *this)
{
  __int64 v2; // rbx
  UFG::UIHKGameplayHelpData::eChargeAnimState *ChargeAnimState; // rax

  *(_QWORD *)&this->id = 0i64;
  this->remapContext = RemapContext_OnFoot;
  this->isWeaponPickup = 0;
  v2 = 2i64;
  `eh vector constructor iterator(this->Captions, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::qString);
  `eh vector constructor iterator(this->Icons, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::qString);
  UFG::qString::qString(&this->CustomTexturePack);
  ChargeAnimState = this->ChargeAnimState;
  do
  {
    *((_DWORD *)ChargeAnimState - 42) = 0;
    *ChargeAnimState++ = CHARGE_ANIM_IDLE;
    --v2;
  }
  while ( v2 );
}

// File Line: 66
// RVA: 0x5D5050
void __fastcall UFG::UIHKGameplayHelpData::Clear(UFG::UIHKGameplayHelpData *this)
{
  UFG::UI::eButtons *Buttons; // rdi
  UFG::qString *Icons; // rbx
  __int64 v3; // rsi

  Buttons = this->Buttons;
  Icons = this->Icons;
  v3 = 2i64;
  this->remapContext = RemapContext_OnFoot;
  do
  {
    *Buttons = INVALID_BUTTON;
    UFG::qString::Set(Icons - 2, &customCaption);
    UFG::qString::Set(Icons++, &customCaption);
    ++Buttons;
    --v3;
  }
  while ( v3 );
}

// File Line: 92
// RVA: 0x5CEE80
char __fastcall UFG::UIHKGameplayHelpData::operator==(UFG::UIHKGameplayHelpData *this, UFG::UIHKGameplayHelpData *rval)
{
  int v5; // ebx
  UFG::UI::eButtons *Buttons; // rcx
  __int64 i; // rdx
  char *v8; // rdi
  char *v9; // rsi

  if ( this->remapContext != rval->remapContext )
    return 0;
  v5 = 0;
  Buttons = this->Buttons;
  for ( i = 0i64; i < 2; ++i )
  {
    if ( *Buttons != *(UFG::UI::eButtons *)((char *)Buttons + (char *)rval - (char *)this) )
      return 0;
    ++Buttons;
  }
  while ( 1 )
  {
    v8 = (char *)rval + 40 * v5;
    v9 = (char *)this + 40 * v5;
    if ( UFG::qString::operator!=((UFG::qString *)(v9 + 24), (UFG::qString *)(v8 + 24))
      || UFG::qString::operator!=((UFG::qString *)(v9 + 104), (UFG::qString *)(v8 + 104)) )
    {
      break;
    }
    if ( ++v5 >= 2 )
      return 1;
  }
  return 0;
}

// File Line: 122
// RVA: 0x5C4060
void __fastcall UFG::UIHKGameplayHelpWidget::UIHKGameplayHelpWidget(UFG::UIHKGameplayHelpWidget *this)
{
  *(_DWORD *)&this->mScriptVisible = 1;
  this->mData.p = 0i64;
  *(_QWORD *)&this->mData.size = 0i64;
  UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&this->mOneFrameData);
  this->mShowingInFlash = 0;
  this->mYOffset = 0.0;
  UFG::qString::qString(&this->mTexturePackName);
  *(_WORD *)&this->mShowOneFrameActive = 0;
}

// File Line: 129
// RVA: 0x5C9530
void __fastcall UFG::UIHKGameplayHelpWidget::~UIHKGameplayHelpWidget(UFG::UIHKGameplayHelpWidget *this)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIHKGameplayHelpData **p; // rcx

  UFG::UIHKGameplayHelpWidget::ClearAll(this);
  mData = this->mTexturePackName.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, mData);
  UFG::qString::Set(&this->mTexturePackName, &customCaption);
  UFG::qString::~qString(&this->mTexturePackName);
  UFG::qString::~qString(&this->mOneFrameData.CustomTexturePack);
  `eh vector destructor iterator(
    this->mOneFrameData.Icons,
    0x28ui64,
    2,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(
    this->mOneFrameData.Captions,
    0x28ui64,
    2,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  p = this->mData.p;
  if ( p )
    operator delete[](p);
  this->mData.p = 0i64;
  *(_QWORD *)&this->mData.size = 0i64;
}

// File Line: 136
// RVA: 0x5E68C0
UFG::UIHKGameplayHelpWidget *__fastcall UFG::UIHKGameplayHelpWidget::Get()
{
  return UFG::UIHKScreenHud::GameplayHelp;
}

// File Line: 149
// RVA: 0x613F20
void __fastcall UFG::UIHKGameplayHelpWidget::Update(UFG::UIHKGameplayHelpWidget *this, UFG::UIScreen *screen)
{
  unsigned int size; // r9d
  char v4; // dl
  UFG::UIHKGameplayHelpData *p_mOneFrameData; // rdi
  bool mShowOneFrameActive; // cl
  bool mShowOneFrameFlag; // al
  unsigned int v9; // eax
  bool mScriptVisible; // al
  char IconTexturePack; // bp

  size = this->mData.size;
  v4 = 0;
  p_mOneFrameData = 0i64;
  if ( size )
    p_mOneFrameData = this->mData.p[size - 1];
  mShowOneFrameActive = this->mShowOneFrameActive;
  if ( (mShowOneFrameActive || this->mShowOneFrameFlag)
    && (!p_mOneFrameData || p_mOneFrameData->priority < this->mOneFrameData.priority) )
  {
    p_mOneFrameData = &this->mOneFrameData;
  }
  mShowOneFrameFlag = this->mShowOneFrameFlag;
  if ( mShowOneFrameFlag || mShowOneFrameActive )
  {
    if ( this->mVisible != mShowOneFrameFlag || !mShowOneFrameFlag )
      v4 = 1;
    this->mChanged |= v4;
    this->mVisible = mShowOneFrameFlag;
    this->mShowOneFrameActive = mShowOneFrameFlag;
    this->mShowOneFrameFlag = 0;
  }
  if ( !p_mOneFrameData || UFG::UIHKGameplayHelpWidget::mLocked > 0 )
  {
    if ( !this->mShowingInFlash )
      return;
    goto LABEL_31;
  }
  this->mVisible |= size != 0;
  UFG::UIHKGameplayHelpWidget::UpdateGameplayButtonCharge(this, screen, &this->mOneFrameData);
  v9 = this->mData.size;
  if ( v9 )
    UFG::UIHKGameplayHelpWidget::UpdateGameplayButtonCharge(this, screen, this->mData.p[v9 - 1]);
  mScriptVisible = this->mScriptVisible;
  this->mVisible &= this->mScriptVisible;
  if ( !this->mScriptVisibleChanged )
    goto LABEL_21;
  this->mScriptVisibleChanged = 0;
  if ( !mScriptVisible )
  {
LABEL_31:
    UFG::UIHKGameplayHelpWidget::Flash_Hide(this, screen);
    return;
  }
  this->mChanged = 1;
LABEL_21:
  if ( this->mChanged )
  {
    this->mChanged = 0;
    IconTexturePack = 0;
    if ( p_mOneFrameData->CustomTexturePack.mLength )
      IconTexturePack = UFG::UIHKGameplayHelpWidget::LoadIconTexturePack(this, p_mOneFrameData->CustomTexturePack.mData);
    else
      UFG::UIHKGameplayHelpWidget::ReleaseIconTexturePack(this);
    if ( this->mVisible )
    {
      if ( !IconTexturePack )
      {
        UFG::UIHKGameplayHelpWidget::Flash_Show(this, screen, p_mOneFrameData);
        UFG::UIHKGameplayHelpWidget::Flash_SetYOffset(this, screen, this->mYOffset);
      }
    }
    else
    {
      UFG::UIHKGameplayHelpWidget::Flash_Hide(this, screen);
    }
  }
}

// File Line: 224
// RVA: 0x61A6D0
void __fastcall UFG::UIHKGameplayHelpWidget::UpdateGameplayButtonCharge(
        UFG::UIHKGameplayHelpWidget *this,
        UFG::UIScreen *screen,
        UFG::UIHKGameplayHelpData *data)
{
  UFG::UIHKGameplayHelpData::eChargeAnimState *ChargeAnimState; // rdi
  int i; // ebx

  if ( data )
  {
    ChargeAnimState = data->ChargeAnimState;
    for ( i = 0; i < 2; ++i )
    {
      if ( *ChargeAnimState == CHARGE_ANIM_SHOULD_PLAY )
      {
        *ChargeAnimState = CHARGE_ANIM_PLAYING;
        UFG::UIHKGameplayHelpWidget::Flash_PlayChargeAnim(this, screen, i);
      }
      else if ( *ChargeAnimState == CHARGE_ANIM_SHOULD_STOP )
      {
        *ChargeAnimState = CHARGE_ANIM_STOPPED;
        UFG::UIHKGameplayHelpWidget::Flash_StopChargeAnim(this, screen, i);
      }
      ++ChargeAnimState;
    }
  }
}

// File Line: 253
// RVA: 0x60CB20
void __fastcall UFG::UIHKGameplayHelpWidget::Show(UFG::UIHKGameplayHelpWidget *this, UFG::UIHKGameplayHelpData *data)
{
  UFG::UIHKGameplayHelpData *p_mOneFrameData; // rcx
  unsigned int size; // eax
  unsigned int v6; // edi
  bool v7; // al
  __int64 v8; // rdx
  unsigned int v9; // r8d
  UFG::UIHKGameplayHelpData *v10; // rcx
  UFG::allocator::free_link *v11; // rax
  UFG::UIHKGameplayHelpData *v12; // rax
  UFG::UIHKGameplayHelpData *v13; // r15
  unsigned int v14; // r9d
  unsigned int v15; // ebp
  int v16; // ecx
  UFG::UIHKGameplayHelpData **v17; // rdx
  unsigned int v18; // esi
  unsigned int capacity; // eax
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::UIHKGameplayHelpData **v22; // r14
  __int64 i; // r9
  __int64 v24; // r8
  __int64 v25; // r9
  UFG::UIHK_NISOverlay *p_NISOverlay; // rax
  float mYOffset; // xmm0_4

  p_mOneFrameData = 0i64;
  size = this->mData.size;
  if ( size )
    p_mOneFrameData = this->mData.p[size - 1];
  if ( (this->mShowOneFrameActive || this->mShowOneFrameFlag)
    && (!p_mOneFrameData || p_mOneFrameData->priority < this->mOneFrameData.priority) )
  {
    p_mOneFrameData = &this->mOneFrameData;
  }
  v6 = 1;
  v7 = !this->mVisible || p_mOneFrameData && !UFG::UIHKGameplayHelpData::operator==(p_mOneFrameData, data);
  this->mChanged |= v7;
  this->mVisible = 1;
  v8 = 0i64;
  v9 = this->mData.size;
  if ( v9 )
  {
    while ( 1 )
    {
      v10 = this->mData.p[v8];
      if ( v10->id == data->id )
        break;
      v8 = (unsigned int)(v8 + 1);
      if ( (unsigned int)v8 >= v9 )
        goto LABEL_19;
    }
    if ( v10->priority <= data->priority )
      UFG::UIHKGameplayHelpData::operator=(v10, data);
  }
  else
  {
LABEL_19:
    v11 = UFG::qMalloc(0xE8ui64, "UIHKGameplayHelpData", 0i64);
    if ( v11 )
    {
      UFG::UIHKGameplayHelpData::UIHKGameplayHelpData((UFG::UIHKGameplayHelpData *)v11);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    if ( v13 )
    {
      UFG::UIHKGameplayHelpData::operator=(v13, data);
      v14 = this->mData.size;
      v15 = v14;
      v16 = v14 - 1;
      if ( (int)(v14 - 1) >= 0 )
      {
        v17 = &this->mData.p[v16];
        do
        {
          if ( v13->priority <= (*v17)->priority )
            break;
          v15 = v16;
          --v17;
          --v16;
        }
        while ( v16 >= 0 );
      }
      v18 = v14 + 1;
      capacity = this->mData.capacity;
      if ( v14 + 1 > capacity )
      {
        if ( capacity )
          v6 = 2 * capacity;
        for ( ; v6 < v18; v6 *= 2 )
          ;
        if ( v6 <= 2 )
          v6 = 2;
        if ( v6 - v18 > 0x10000 )
          v6 = v14 + 65537;
        if ( v6 != v14 )
        {
          v20 = 8i64 * v6;
          if ( !is_mul_ok(v6, 8ui64) )
            v20 = -1i64;
          v21 = UFG::qMalloc(v20, "qArray.Insert", 0i64);
          v22 = (UFG::UIHKGameplayHelpData **)v21;
          if ( this->mData.p )
          {
            for ( i = 0i64; (unsigned int)i < this->mData.size; i = (unsigned int)(i + 1) )
              v21[i] = (UFG::allocator::free_link)this->mData.p[i];
            operator delete[](this->mData.p);
          }
          this->mData.p = v22;
          this->mData.capacity = v6;
        }
      }
      this->mData.size = v18;
      v24 = v18 - 1;
      if ( (unsigned int)v24 > v15 )
      {
        v25 = v24;
        do
        {
          v24 = (unsigned int)(v24 - 1);
          this->mData.p[v25--] = this->mData.p[v24];
        }
        while ( (unsigned int)v24 > v15 );
      }
      this->mData.p[v15] = v13;
      p_NISOverlay = (UFG::UIHK_NISOverlay *)UFG::UIHKScreenGlobalOverlay::mThis;
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
        p_NISOverlay = &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
      mYOffset = this->mYOffset;
      if ( p_NISOverlay->mActive )
      {
        mYOffset = mYOffset - -20.0;
        this->mYOffset = -20.0;
      }
      else
      {
        this->mYOffset = 0.0;
      }
      this->mChanged |= COERCE_FLOAT(LODWORD(mYOffset) & _xmm) > 0.001;
    }
  }
}     el

// File Line: 316
// RVA: 0x60CDB0
void __fastcall UFG::UIHKGameplayHelpWidget::Show(
        UFG::UIHKGameplayHelpWidget *this,
        unsigned int id,
        unsigned int priority,
        UFG::UI::eButtons button0,
        const char *caption0,
        UFG::UI::eButtons button1,
        const char *caption1)
{
  UFG::UIHKGameplayHelpData data; // [rsp+30h] [rbp-F8h] BYREF

  UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&data);
  data.id = id;
  data.Buttons[0] = button0;
  data.Buttons[1] = button1;
  UFG::qString::Set(data.Captions, caption0);
  UFG::qString::Set(&data.Captions[1], caption1);
  UFG::UIHKGameplayHelpWidget::Show(this, &data);
  UFG::qString::~qString(&data.CustomTexturePack);
  `eh vector destructor iterator(data.Icons, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 330
// RVA: 0x5EC9A0
void __fastcall UFG::UIHKGameplayHelpWidget::Hide(UFG::UIHKGameplayHelpWidget *this, unsigned int id)
{
  unsigned int v4; // esi
  __int64 v5; // rbp
  UFG::UIHKGameplayHelpData *v6; // rdi
  unsigned int v7; // edx
  __int64 v8; // r8
  unsigned int size; // eax

  v4 = 0;
  if ( this->mData.size )
  {
    v5 = 8i64;
    do
    {
      v6 = this->mData.p[v4];
      if ( v6->id == id )
      {
        if ( v6 )
        {
          UFG::qString::~qString(&v6->CustomTexturePack);
          `eh vector destructor iterator(v6->Icons, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
          `eh vector destructor iterator(
            v6->Captions,
            0x28ui64,
            2,
            (void (__fastcall *)(void *))UFG::qString::~qString);
          operator delete[](v6);
        }
        v7 = v4 + 1;
        if ( v4 + 1 != this->mData.size )
        {
          v8 = v5;
          do
          {
            *(UFG::UIHKGameplayHelpData **)((char *)this->mData.p + v8 - 8) = *(UFG::UIHKGameplayHelpData **)((char *)this->mData.p + v8);
            ++v7;
            v8 += 8i64;
          }
          while ( v7 != this->mData.size );
        }
        size = this->mData.size;
        if ( size > 1 )
          this->mData.size = size - 1;
        else
          this->mData.size = 0;
      }
      ++v4;
      v5 += 8i64;
    }
    while ( v4 < this->mData.size );
  }
  this->mVisible = this->mData.size != 0;
}

// File Line: 361
// RVA: 0x610CB0
void __fastcall UFG::UIHKGameplayHelpWidget::ShowOneFrame(
        UFG::UIHKGameplayHelpWidget *this,
        UFG::UIHKGameplayHelpData *data)
{
  char v3; // di
  unsigned int size; // eax
  UFG::UIHKGameplayHelpData *p_mOneFrameData; // rcx

  v3 = 0;
  size = this->mData.size;
  p_mOneFrameData = 0i64;
  if ( size )
    p_mOneFrameData = this->mData.p[size - 1];
  if ( (this->mShowOneFrameActive || this->mShowOneFrameFlag)
    && (!p_mOneFrameData || p_mOneFrameData->priority < this->mOneFrameData.priority) )
  {
    p_mOneFrameData = &this->mOneFrameData;
  }
  this->mShowOneFrameFlag = 1;
  if ( !p_mOneFrameData || !UFG::UIHKGameplayHelpData::operator==(p_mOneFrameData, data) )
    v3 = 1;
  this->mChanged |= v3;
  UFG::UIHKGameplayHelpData::operator=(&this->mOneFrameData, data);
}

// File Line: 394
// RVA: 0x5ED490
void __fastcall UFG::UIHKGameplayHelpWidget::IconTexturePackLoadedCallback(
        UFG::DataStreamer::Handle *handle,
        void *param)
{
  UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
}

// File Line: 421
// RVA: 0x5F0B40
char __fastcall UFG::UIHKGameplayHelpWidget::LoadIconTexturePack(
        UFG::UIHKGameplayHelpWidget *this,
        const char *texturePack)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  UFG::UIScreenTextureManager *v7; // rax

  if ( !texturePack || !(unsigned int)UFG::qStringCompare(this->mTexturePackName.mData, texturePack, -1) )
    return 0;
  mData = this->mTexturePackName.mData;
  v6 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v6, mData);
  UFG::qString::Set(&this->mTexturePackName, &customCaption);
  UFG::qString::Set(&this->mTexturePackName, texturePack);
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v7,
    texturePack,
    DEFAULT_PRIORITY,
    (UFG::qReflectInventoryBase *)UFG::UIHKGameplayHelpWidget::IconTexturePackLoadedCallback,
    0i64);
  return 1;
}

// File Line: 438
// RVA: 0x600B30
void __fastcall UFG::UIHKGameplayHelpWidget::ReleaseIconTexturePack(UFG::UIHKGameplayHelpWidget *this)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v3; // rax

  mData = this->mTexturePackName.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, mData);
  UFG::qString::Set(&this->mTexturePackName, &customCaption);
}

// File Line: 471
// RVA: 0x5D5400
void __fastcall UFG::UIHKGameplayHelpWidget::ClearAll(UFG::UIHKGameplayHelpWidget *this)
{
  __int64 v2; // rdi
  UFG::UIHKGameplayHelpData *v3; // rsi
  UFG::UIHKGameplayHelpData **p; // rcx

  *(_WORD *)&this->mVisible = 256;
  *(_WORD *)&this->mShowOneFrameActive = 0;
  UFG::UIHKGameplayHelpData::Clear(&this->mOneFrameData);
  if ( this->mData.size )
  {
    v2 = 0i64;
    do
    {
      v3 = this->mData.p[v2];
      if ( v3 )
      {
        UFG::qString::~qString(&v3->CustomTexturePack);
        `eh vector destructor iterator(v3->Icons, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
        `eh vector destructor iterator(v3->Captions, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
        operator delete[](v3);
      }
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < this->mData.size );
    p = this->mData.p;
    if ( p )
      operator delete[](p);
    this->mData.p = 0i64;
    *(_QWORD *)&this->mData.size = 0i64;
  }
}

// File Line: 493
// RVA: 0x5F3F50
void __fastcall UFG::UIHKGameplayHelpWidget::PlayButtonCharge(
        UFG::UIHKGameplayHelpWidget *this,
        unsigned int id,
        int index)
{
  unsigned int size; // eax
  UFG::UIHKGameplayHelpData *v5; // rdx

  if ( this->mOneFrameData.id == id )
    this->mOneFrameData.ChargeAnimState[index] = CHARGE_ANIM_SHOULD_PLAY;
  size = this->mData.size;
  if ( size )
  {
    v5 = this->mData.p[size - 1];
    if ( v5 )
    {
      if ( v5->id == id )
        v5->ChargeAnimState[index] = CHARGE_ANIM_SHOULD_PLAY;
    }
  }
}

// File Line: 507
// RVA: 0x612560
void __fastcall UFG::UIHKGameplayHelpWidget::StopButtonCharge(
        UFG::UIHKGameplayHelpWidget *this,
        unsigned int id,
        int index)
{
  unsigned int size; // eax
  UFG::UIHKGameplayHelpData *v5; // rdx

  if ( this->mOneFrameData.id == id )
    this->mOneFrameData.ChargeAnimState[index] = CHARGE_ANIM_SHOULD_STOP;
  size = this->mData.size;
  if ( size )
  {
    v5 = this->mData.p[size - 1];
    if ( v5 )
    {
      if ( v5->id == id )
        v5->ChargeAnimState[index] = CHARGE_ANIM_SHOULD_STOP;
    }
  }
}

// File Line: 521
// RVA: 0x5E2200
void __fastcall UFG::UIHKGameplayHelpWidget::Flash_SetYOffset(
        UFG::UIHKGameplayHelpWidget *this,
        UFG::UIScreen *screen,
        float yoffset)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Number;
    pargs.mValue.NValue = yoffset;
    Scaleform::GFx::Movie::Invoke(pObject, "GameplayHelp_YOffset", 0i64, &pargs, 1u);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 533
// RVA: 0x5E2760
void __fastcall UFG::UIHKGameplayHelpWidget::Flash_Show(
        UFG::UIHKGameplayHelpWidget *this,
        UFG::UIScreen *screen,
        UFG::UIHKGameplayHelpData *data)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  Scaleform::GFx::Value::ObjectInterface **p_pObjectInterface; // rbx
  __int64 v8; // rdi
  UFG::UI::eButtons *Buttons; // r15
  char **p_mData; // r14
  char *v11; // rbx
  __int64 v12; // r12
  unsigned int v13; // ecx
  char *v14; // rax
  char v15; // al
  char *v16; // rdi
  UFG::UI::eButtons v17; // esi
  UFG::UI::eButtons v18; // ecx
  unsigned int v19; // eax
  char Key; // al
  char *KeyboardButtonTextureNameNonRemappable; // rax
  __int64 v22; // rdi
  const char *v23; // rdi
  bool v24; // di
  bool isWeaponPickup; // bl
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-1F8h] BYREF
  __int64 v27; // [rsp+60h] [rbp-1C8h]
  Scaleform::GFx::Value ptr; // [rsp+70h] [rbp-1B8h] BYREF
  char v29; // [rsp+B0h] [rbp-178h] BYREF
  bool v30; // [rsp+240h] [rbp+18h]
  Scaleform::GFx::Movie *pObject; // [rsp+248h] [rbp+20h]

  if ( !data )
    return;
  v27 = -2i64;
  if ( !screen )
    return;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( !pObject )
    return;
  v30 = 1;
  if ( data->CustomTexturePack.mLength )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mTexturePackName.mData, data->CustomTexturePack.mData, -1)
      || (mData = this->mTexturePackName.mData,
          v6 = UFG::UIScreenTextureManager::Instance(),
          !UFG::UIScreenTextureManager::IsTexturePackLoaded(v6, mData)) )
    {
      v30 = 0;
    }
  }
  `eh vector constructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  p_pObjectInterface = &ptr.pObjectInterface;
  v8 = 8i64;
  do
  {
    if ( ((_DWORD)p_pObjectInterface[1] & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ObjectInterface **, Scaleform::GFx::Value::ObjectInterface *))&(*p_pObjectInterface)->vfptr->gap8[8])(
        *p_pObjectInterface,
        p_pObjectInterface - 2,
        p_pObjectInterface[2]);
      *p_pObjectInterface = 0i64;
    }
    *((_DWORD *)p_pObjectInterface + 2) = 0;
    p_pObjectInterface += 6;
    --v8;
  }
  while ( v8 );
  Buttons = data->Buttons;
  p_mData = &data->Icons[0].mData;
  v11 = &v29;
  v12 = 2i64;
  do
  {
    if ( !*((_DWORD *)p_mData - 21) && !*((_DWORD *)p_mData - 1) )
      goto LABEL_48;
    if ( !UFG::UIScreenManager::s_instance->m_translator->mIsAcceptButtonSwapped
      || (unsigned int)UFG::qStringCompare(*p_mData, "Icon_Vault", -1)
      && (unsigned int)UFG::qStringCompare(*p_mData, "Icon_Climb", -1)
      && (unsigned int)UFG::qStringCompare(*p_mData, "Icon_Jump", -1) )
    {
      v17 = *Buttons;
      v18 = *Buttons;
      if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      {
        v19 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(v18, data->remapContext);
        v16 = &customCaption;
        if ( v19 != REMAP_ID_INVALID_2 )
        {
          Key = UFG::UIHKScreenOptionsButtonMapping::GetKey(v19);
          v16 = (char *)UFG::KeyToTextureName(Key);
        }
        if ( *v16 )
        {
LABEL_38:
          if ( (*((_DWORD *)v11 - 10) & 0x40) == 0 )
            goto LABEL_39;
          goto LABEL_30;
        }
        KeyboardButtonTextureNameNonRemappable = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(v17);
      }
      else
      {
        KeyboardButtonTextureNameNonRemappable = UFG::UI::GetGamepadButtonTextureName(v18, 1);
      }
      v16 = KeyboardButtonTextureNameNonRemappable;
      goto LABEL_38;
    }
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      v13 = REMAP_ID_INVALID_2;
      if ( data->remapContext == RemapContext_OnFoot )
        v13 = REMAP_ID_GRAPPLE_2;
      v14 = &customCaption;
      if ( v13 != REMAP_ID_INVALID_2 )
      {
        v15 = UFG::UIHKScreenOptionsButtonMapping::GetKey(v13);
        v14 = (char *)UFG::KeyToTextureName(v15);
      }
      v16 = "BUTTON_BACKSPACE";
      if ( *v14 )
        v16 = v14;
    }
    else
    {
      v16 = "BUTTON_BACK";
    }
    if ( (*((_DWORD *)v11 - 10) & 0x40) == 0 )
      goto LABEL_39;
LABEL_30:
    (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**((_QWORD **)v11 - 6) + 16i64))(
      *((_QWORD *)v11 - 6),
      v11 - 64,
      *((_QWORD *)v11 - 4));
    *((_QWORD *)v11 - 6) = 0i64;
LABEL_39:
    *((_QWORD *)v11 - 4) = v16;
    *((_DWORD *)v11 - 10) = 6;
    v22 = (__int64)*(p_mData - 10);
    if ( (*((_DWORD *)v11 + 2) & 0x40) != 0 )
    {
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**(_QWORD **)v11 + 16i64))(
        *(_QWORD *)v11,
        v11 - 16,
        *((_QWORD *)v11 + 2));
      *(_QWORD *)v11 = 0i64;
    }
    *((_DWORD *)v11 + 2) = 6;
    *((_QWORD *)v11 + 2) = v22;
    if ( v30 )
    {
      v23 = *p_mData;
      if ( (*((_DWORD *)v11 + 14) & 0x40) != 0 )
      {
        (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**((_QWORD **)v11 + 6) + 16i64))(
          *((_QWORD *)v11 + 6),
          v11 + 32,
          *((_QWORD *)v11 + 8));
        *((_QWORD *)v11 + 6) = 0i64;
      }
      *((_DWORD *)v11 + 14) = 6;
      *((_QWORD *)v11 + 8) = v23;
    }
    v24 = (unsigned int)(*Buttons - 27) <= 7;
    if ( (*((_DWORD *)v11 + 26) & 0x40) != 0 )
    {
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**((_QWORD **)v11 + 12) + 16i64))(
        *((_QWORD *)v11 + 12),
        v11 + 80,
        *((_QWORD *)v11 + 14));
      *((_QWORD *)v11 + 12) = 0i64;
    }
    *((_DWORD *)v11 + 26) = 2;
    v11[112] = v24;
LABEL_48:
    v11 += 192;
    ++Buttons;
    p_mData += 5;
    --v12;
  }
  while ( v12 );
  value.pObjectInterface = 0i64;
  value.Type = VT_Undefined;
  isWeaponPickup = data->isWeaponPickup;
  value.Type = VT_Boolean;
  value.mValue.BValue = isWeaponPickup;
  Scaleform::GFx::Movie::SetVariable(pObject, "mc_GameplayHelp.mIsWeaponPickup", &value, 1i64);
  Scaleform::GFx::Movie::Invoke(pObject, "GameplayHelp_Show", 0i64, &ptr, 8u);
  if ( !this->mShowingInFlash )
  {
    ++UFG::UIHKHelpBarWidget::mLocked;
    this->mShowingInFlash = 1;
  }
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Undefined;
  `eh vector destructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 604
// RVA: 0x5DB860
void __fastcall UFG::UIHKGameplayHelpWidget::Flash_Hide(UFG::UIHKGameplayHelpWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx
  int v4; // eax
  UFG::UIHKScreenGlobalOverlay *v5; // rax
  char *mData; // rbx
  UFG::UIScreenTextureManager *v7; // rax

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "GameplayHelp_Hide", 0i64, 0i64, 0);
    if ( this->mShowingInFlash )
    {
      v4 = UFG::UIHKHelpBarWidget::mLocked;
      if ( UFG::UIHKHelpBarWidget::mLocked > 0 )
        v4 = --UFG::UIHKHelpBarWidget::mLocked;
      if ( v4 < 1 )
      {
        v5 = UFG::UIHKScreenGlobalOverlay::mThis;
        if ( !UFG::UIHKScreenGlobalOverlay::mThis )
          v5 = &gGlobalOverlaySentinel;
        v5->HelpBar.mChanged = 1;
      }
      this->mShowingInFlash = 0;
    }
    mData = this->mTexturePackName.mData;
    v7 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v7, mData);
    UFG::qString::Set(&this->mTexturePackName, &customCaption);
  }
}

// File Line: 622
// RVA: 0x5DE610
void __fastcall UFG::UIHKGameplayHelpWidget::Flash_PlayChargeAnim(
        UFG::UIHKGameplayHelpWidget *this,
        UFG::UIScreen *screen,
        int index)
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
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)index;
    Scaleform::GFx::Movie::Invoke(pObject, "GameplayHelp_PlayButtonCharge", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 636
// RVA: 0x5E5200
void __fastcall UFG::UIHKGameplayHelpWidget::Flash_StopChargeAnim(
        UFG::UIHKGameplayHelpWidget *this,
        UFG::UIScreen *screen,
        int index)
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
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)index;
    Scaleform::GFx::Movie::Invoke(pObject, "GameplayHelp_StopButtonCharge", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

