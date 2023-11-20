// File Line: 31
// RVA: 0x156DB90
__int64 UFG::_dynamic_initializer_for__gGameplayHelpSentinel__()
{
  UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&stru_14208EBE8);
  unk_14208ECD0 = 0;
  unk_14208ECD4 = 0;
  UFG::qString::qString(&stru_14208ECD8);
  unk_14208ED00 = 0;
  return atexit(UFG::_dynamic_atexit_destructor_for__gGameplayHelpSentinel__);
}

// File Line: 39
// RVA: 0x5C3FA0
void __fastcall UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(UFG::UIHKGameplayHelpData *this)
{
  UFG::UIHKGameplayHelpData *v1; // rdi
  signed __int64 v2; // rbx
  UFG::UIHKGameplayHelpData::eChargeAnimState *v3; // rax

  v1 = this;
  *(_QWORD *)&this->id = 0i64;
  this->remapContext = 0;
  this->isWeaponPickup = 0;
  v2 = 2i64;
  `eh vector constructor iterator(this->Captions, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::qString);
  `eh vector constructor iterator(v1->Icons, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::qString);
  UFG::qString::qString(&v1->CustomTexturePack);
  v3 = v1->ChargeAnimState;
  do
  {
    *((_DWORD *)v3 - 42) = 0;
    *v3 = 0;
    ++v3;
    --v2;
  }
  while ( v2 );
}

// File Line: 66
// RVA: 0x5D5050
void __fastcall UFG::UIHKGameplayHelpData::Clear(UFG::UIHKGameplayHelpData *this)
{
  UFG::UI::eButtons *v1; // rdi
  UFG::qString *v2; // rbx
  signed __int64 v3; // rsi

  v1 = this->Buttons;
  v2 = this->Icons;
  v3 = 2i64;
  this->remapContext = 0;
  do
  {
    *v1 = 0;
    UFG::qString::Set(v2 - 2, &customWorldMapCaption);
    UFG::qString::Set(v2, &customWorldMapCaption);
    ++v2;
    ++v1;
    --v3;
  }
  while ( v3 );
}

// File Line: 92
// RVA: 0x5CEE80
char __fastcall UFG::UIHKGameplayHelpData::operator==(UFG::UIHKGameplayHelpData *this, UFG::UIHKGameplayHelpData *rval)
{
  UFG::UIHKGameplayHelpData *v2; // r15
  UFG::UIHKGameplayHelpData *v3; // r14
  int v5; // ebx
  UFG::UI::eButtons *v6; // rcx
  signed __int64 v7; // rdx
  signed __int64 v8; // rdi
  signed __int64 v9; // rsi

  v2 = rval;
  v3 = this;
  if ( this->remapContext != rval->remapContext )
    return 0;
  v5 = 0;
  v6 = this->Buttons;
  v7 = 0i64;
  do
  {
    if ( *v6 != *(UFG::UI::eButtons *)((char *)v6 + (char *)v2 - (char *)v3) )
      return 0;
    ++v7;
    ++v6;
  }
  while ( v7 < 2 );
  while ( 1 )
  {
    v8 = (signed __int64)v2 + 40 * v5;
    v9 = (signed __int64)v3 + 40 * v5;
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
  UFG::UIHKGameplayHelpWidget *v1; // rbx

  v1 = this;
  *(_DWORD *)&this->mScriptVisible = 1;
  this->mData.p = 0i64;
  *(_QWORD *)&this->mData.size = 0i64;
  UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&this->mOneFrameData);
  v1->mShowingInFlash = 0;
  v1->mYOffset = 0.0;
  UFG::qString::qString(&v1->mTexturePackName);
  *(_WORD *)&v1->mShowOneFrameActive = 0;
}

// File Line: 129
// RVA: 0x5C9530
void __fastcall UFG::UIHKGameplayHelpWidget::~UIHKGameplayHelpWidget(UFG::UIHKGameplayHelpWidget *this)
{
  UFG::UIHKGameplayHelpWidget *v1; // rdi
  const char *v2; // rbx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIHKGameplayHelpData **v4; // rcx

  v1 = this;
  UFG::UIHKGameplayHelpWidget::ClearAll(this);
  v2 = v1->mTexturePackName.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, v2);
  UFG::qString::Set(&v1->mTexturePackName, &customWorldMapCaption);
  UFG::qString::~qString(&v1->mTexturePackName);
  UFG::qString::~qString(&v1->mOneFrameData.CustomTexturePack);
  `eh vector destructor iterator(
    v1->mOneFrameData.Icons,
    0x28ui64,
    2,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(
    v1->mOneFrameData.Captions,
    0x28ui64,
    2,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  v4 = v1->mData.p;
  if ( v4 )
    operator delete[](v4);
  v1->mData.p = 0i64;
  *(_QWORD *)&v1->mData.size = 0i64;
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
  unsigned int v2; // er9
  UFG::UIScreen *v3; // rsi
  char v4; // dl
  UFG::UIHKGameplayHelpWidget *v5; // rbx
  UFG::UIHKGameplayHelpData *v6; // rdi
  bool v7; // cl
  bool v8; // al
  unsigned int v9; // eax
  bool v10; // al
  char v11; // bp

  v2 = this->mData.size;
  v3 = screen;
  v4 = 0;
  v5 = this;
  v6 = 0i64;
  if ( v2 )
    v6 = this->mData.p[v2 - 1];
  v7 = this->mShowOneFrameActive;
  if ( (v7 || v5->mShowOneFrameFlag) && (!v6 || v6->priority < v5->mOneFrameData.priority) )
    v6 = &v5->mOneFrameData;
  v8 = v5->mShowOneFrameFlag;
  if ( v8 || v7 )
  {
    if ( v5->mVisible != v8 || !v8 )
      v4 = 1;
    v5->mChanged |= v4;
    v5->mVisible = v8;
    v5->mShowOneFrameActive = v8;
    v5->mShowOneFrameFlag = 0;
  }
  if ( !v6 || UFG::UIHKGameplayHelpWidget::mLocked > 0 )
  {
    if ( !v5->mShowingInFlash )
      return;
    goto LABEL_31;
  }
  v5->mVisible |= v2 != 0;
  UFG::UIHKGameplayHelpWidget::UpdateGameplayButtonCharge(v5, v3, &v5->mOneFrameData);
  v9 = v5->mData.size;
  if ( v9 )
    UFG::UIHKGameplayHelpWidget::UpdateGameplayButtonCharge(v5, v3, v5->mData.p[v9 - 1]);
  v10 = v5->mScriptVisible;
  v5->mVisible &= v5->mScriptVisible;
  if ( !v5->mScriptVisibleChanged )
    goto LABEL_21;
  v5->mScriptVisibleChanged = 0;
  if ( !v10 )
  {
LABEL_31:
    UFG::UIHKGameplayHelpWidget::Flash_Hide(v5, v3);
    return;
  }
  v5->mChanged = 1;
LABEL_21:
  if ( v5->mChanged )
  {
    v5->mChanged = 0;
    v11 = 0;
    if ( v6->CustomTexturePack.mLength )
      v11 = UFG::UIHKGameplayHelpWidget::LoadIconTexturePack(v5, v6->CustomTexturePack.mData);
    else
      UFG::UIHKGameplayHelpWidget::ReleaseIconTexturePack(v5);
    if ( v5->mVisible )
    {
      if ( !v11 )
      {
        UFG::UIHKGameplayHelpWidget::Flash_Show(v5, v3, v6);
        UFG::UIHKGameplayHelpWidget::Flash_SetYOffset(v5, v3, v5->mYOffset);
      }
    }
    else
    {
      UFG::UIHKGameplayHelpWidget::Flash_Hide(v5, v3);
    }
  }
}

// File Line: 224
// RVA: 0x61A6D0
void __fastcall UFG::UIHKGameplayHelpWidget::UpdateGameplayButtonCharge(UFG::UIHKGameplayHelpWidget *this, UFG::UIScreen *screen, UFG::UIHKGameplayHelpData *data)
{
  UFG::UIScreen *v3; // rsi
  UFG::UIHKGameplayHelpData::eChargeAnimState *v4; // rdi
  UFG::UIHKGameplayHelpWidget *v5; // rbp
  int v6; // ebx

  if ( data )
  {
    v3 = screen;
    v4 = data->ChargeAnimState;
    v5 = this;
    v6 = 0;
    do
    {
      if ( *v4 == 1 )
      {
        *v4 = 3;
        UFG::UIHKGameplayHelpWidget::Flash_PlayChargeAnim(v5, v3, v6);
      }
      else if ( *v4 == 2 )
      {
        *v4 = 4;
        UFG::UIHKGameplayHelpWidget::Flash_StopChargeAnim(v5, v3, v6);
      }
      ++v6;
      ++v4;
    }
    while ( v6 < 2 );
  }
}

// File Line: 253
// RVA: 0x60CB20
void __fastcall UFG::UIHKGameplayHelpWidget::Show(UFG::UIHKGameplayHelpWidget *this, UFG::UIHKGameplayHelpData *data)
{
  UFG::UIHKGameplayHelpData *v2; // rsi
  UFG::UIHKGameplayHelpWidget *v3; // rbx
  UFG::UIHKGameplayHelpData *v4; // rcx
  unsigned int v5; // eax
  unsigned int v6; // edi
  bool v7; // al
  __int64 v8; // rdx
  unsigned int v9; // er8
  UFG::UIHKGameplayHelpData *v10; // rcx
  UFG::allocator::free_link *v11; // rax
  UFG::UIHKGameplayHelpData *v12; // rax
  UFG::UIHKGameplayHelpData *v13; // r15
  unsigned int v14; // er9
  unsigned int v15; // ebp
  int v16; // ecx
  signed __int64 v17; // rdx
  unsigned int v18; // esi
  unsigned int v19; // eax
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::UIHKGameplayHelpData **v22; // r14
  __int64 v23; // r9
  signed __int64 v24; // r8
  signed __int64 v25; // r9
  UFG::UIHKScreenGlobalOverlay *v26; // rax
  float v27; // xmm0_4

  v2 = data;
  v3 = this;
  v4 = 0i64;
  v5 = v3->mData.size;
  if ( v5 )
    v4 = v3->mData.p[v5 - 1];
  if ( (v3->mShowOneFrameActive || v3->mShowOneFrameFlag) && (!v4 || v4->priority < v3->mOneFrameData.priority) )
    v4 = &v3->mOneFrameData;
  v6 = 1;
  v7 = !v3->mVisible || v4 && !UFG::UIHKGameplayHelpData::operator==(v4, data);
  v3->mChanged |= v7;
  v3->mVisible = 1;
  v8 = 0i64;
  v9 = v3->mData.size;
  if ( v9 )
  {
    while ( 1 )
    {
      v10 = v3->mData.p[v8];
      if ( v10->id == v2->id )
        break;
      v8 = (unsigned int)(v8 + 1);
      if ( (unsigned int)v8 >= v9 )
        goto LABEL_19;
    }
    if ( v10->priority <= v2->priority )
      UFG::UIHKGameplayHelpData::operator=(v10, v2);
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
      UFG::UIHKGameplayHelpData::operator=(v13, v2);
      v14 = v3->mData.size;
      v15 = v14;
      v16 = v14 - 1;
      if ( (signed int)(v14 - 1) >= 0 )
      {
        v17 = (signed __int64)&v3->mData.p[v16];
        do
        {
          if ( v13->priority <= *(_DWORD *)(*(_QWORD *)v17 + 4i64) )
            break;
          v15 = v16;
          v17 -= 8i64;
          --v16;
        }
        while ( v16 >= 0 );
      }
      v18 = v14 + 1;
      v19 = v3->mData.capacity;
      if ( v14 + 1 > v19 )
      {
        if ( v19 )
          v6 = 2 * v19;
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
          if ( v3->mData.p )
          {
            v23 = 0i64;
            if ( v3->mData.size )
            {
              do
              {
                v21[v23] = (UFG::allocator::free_link)v3->mData.p[v23];
                v23 = (unsigned int)(v23 + 1);
              }
              while ( (unsigned int)v23 < v3->mData.size );
            }
            operator delete[](v3->mData.p);
          }
          v3->mData.p = v22;
          v3->mData.capacity = v6;
        }
      }
      v3->mData.size = v18;
      v24 = v18 - 1;
      if ( (unsigned int)v24 > v15 )
      {
        v25 = v24;
        do
        {
          v24 = (unsigned int)(v24 - 1);
          v3->mData.p[v25] = v3->mData.p[v24];
          --v25;
        }
        while ( (unsigned int)v24 > v15 );
      }
      v3->mData.p[v15] = v13;
      v26 = UFG::UIHKScreenGlobalOverlay::mThis;
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
        v26 = (UFG::UIHKScreenGlobalOverlay *)((char *)UFG::UIHKScreenGlobalOverlay::mThis + 408);
      v27 = v3->mYOffset;
      if ( v26->m_screenName[32] )
      {
        v27 = v27 - -20.0;
        v3->mYOffset = -20.0;
      }
      else
      {
        v3->mYOffset = 0.0;
      }
      v3->mChanged |= COERCE_FLOAT(LODWORD(v27) & _xmm) > 0.001;
    }
  }
}

// File Line: 316
// RVA: 0x60CDB0
void __fastcall UFG::UIHKGameplayHelpWidget::Show(UFG::UIHKGameplayHelpWidget *this, unsigned int id, unsigned int priority, UFG::UI::eButtons button0, const char *caption0, UFG::UI::eButtons button1, const char *caption1)
{
  UFG::UI::eButtons v7; // edi
  unsigned int v8; // ebx
  UFG::UIHKGameplayHelpWidget *v9; // rsi
  UFG::UIHKGameplayHelpData data; // [rsp+30h] [rbp-F8h]

  v7 = button0;
  v8 = id;
  v9 = this;
  UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&data);
  data.id = v8;
  data.Buttons[0] = v7;
  data.Buttons[1] = button1;
  UFG::qString::Set(data.Captions, caption0);
  UFG::qString::Set(&data.Captions[1], caption1);
  UFG::UIHKGameplayHelpWidget::Show(v9, &data);
  UFG::qString::~qString(&data.CustomTexturePack);
  `eh vector destructor iterator(data.Icons, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 330
// RVA: 0x5EC9A0
void __fastcall UFG::UIHKGameplayHelpWidget::Hide(UFG::UIHKGameplayHelpWidget *this, unsigned int id)
{
  unsigned int v2; // er14
  UFG::UIHKGameplayHelpWidget *v3; // rbx
  unsigned int v4; // esi
  signed __int64 v5; // rbp
  UFG::UIHKGameplayHelpData *v6; // rdi
  int v7; // edx
  signed __int64 v8; // r8
  unsigned int v9; // eax

  v2 = id;
  v3 = this;
  v4 = 0;
  if ( this->mData.size )
  {
    v5 = 8i64;
    do
    {
      v6 = v3->mData.p[v4];
      if ( v6->id == v2 )
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
        if ( v4 + 1 != v3->mData.size )
        {
          v8 = v5;
          do
          {
            *(UFG::UIHKGameplayHelpData **)((char *)v3->mData.p + v8 - 8) = *(UFG::UIHKGameplayHelpData **)((char *)v3->mData.p + v8);
            ++v7;
            v8 += 8i64;
          }
          while ( v7 != v3->mData.size );
        }
        v9 = v3->mData.size;
        if ( v9 > 1 )
          v3->mData.size = v9 - 1;
        else
          v3->mData.size = 0;
      }
      ++v4;
      v5 += 8i64;
    }
    while ( v4 < v3->mData.size );
  }
  v3->mVisible = v3->mData.size != 0;
}

// File Line: 361
// RVA: 0x610CB0
void __fastcall UFG::UIHKGameplayHelpWidget::ShowOneFrame(UFG::UIHKGameplayHelpWidget *this, UFG::UIHKGameplayHelpData *data)
{
  UFG::UIHKGameplayHelpWidget *v2; // rbx
  char v3; // di
  UFG::UIHKGameplayHelpData *v4; // rsi
  unsigned int v5; // eax
  UFG::UIHKGameplayHelpData *v6; // rcx

  v2 = this;
  v3 = 0;
  v4 = data;
  v5 = this->mData.size;
  v6 = 0i64;
  if ( v5 )
    v6 = v2->mData.p[v5 - 1];
  if ( (v2->mShowOneFrameActive || v2->mShowOneFrameFlag) && (!v6 || v6->priority < v2->mOneFrameData.priority) )
    v6 = &v2->mOneFrameData;
  v2->mShowOneFrameFlag = 1;
  if ( !v6 || !UFG::UIHKGameplayHelpData::operator==(v6, data) )
    v3 = 1;
  v2->mChanged |= v3;
  UFG::UIHKGameplayHelpData::operator=(&v2->mOneFrameData, v4);
}

// File Line: 394
// RVA: 0x5ED490
void __fastcall UFG::UIHKGameplayHelpWidget::IconTexturePackLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
}

// File Line: 421
// RVA: 0x5F0B40
char __fastcall UFG::UIHKGameplayHelpWidget::LoadIconTexturePack(UFG::UIHKGameplayHelpWidget *this, const char *texturePack)
{
  const char *v2; // rdi
  UFG::UIHKGameplayHelpWidget *v3; // rsi
  const char *v5; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  UFG::UIScreenTextureManager *v7; // rax

  v2 = texturePack;
  v3 = this;
  if ( !texturePack || !(unsigned int)UFG::qStringCompare(this->mTexturePackName.mData, texturePack, -1) )
    return 0;
  v5 = v3->mTexturePackName.mData;
  v6 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v6, v5);
  UFG::qString::Set(&v3->mTexturePackName, &customWorldMapCaption);
  UFG::qString::Set(&v3->mTexturePackName, v2);
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v7,
    v2,
    DEFAULT_PRIORITY,
    UFG::UIHKGameplayHelpWidget::IconTexturePackLoadedCallback,
    0i64);
  return 1;
}

// File Line: 438
// RVA: 0x600B30
void __fastcall UFG::UIHKGameplayHelpWidget::ReleaseIconTexturePack(UFG::UIHKGameplayHelpWidget *this)
{
  char *v1; // rbx
  UFG::UIHKGameplayHelpWidget *v2; // rdi
  UFG::UIScreenTextureManager *v3; // rax

  v1 = this->mTexturePackName.mData;
  v2 = this;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, v1);
  UFG::qString::Set(&v2->mTexturePackName, &customWorldMapCaption);
}

// File Line: 471
// RVA: 0x5D5400
void __fastcall UFG::UIHKGameplayHelpWidget::ClearAll(UFG::UIHKGameplayHelpWidget *this)
{
  UFG::UIHKGameplayHelpWidget *v1; // rbx
  unsigned int v2; // eax
  __int64 v3; // rdi
  UFG::UIHKGameplayHelpData *v4; // rsi
  UFG::UIHKGameplayHelpData **v5; // rcx

  v1 = this;
  *(_WORD *)&this->mVisible = 256;
  *(_WORD *)&this->mShowOneFrameActive = 0;
  UFG::UIHKGameplayHelpData::Clear(&this->mOneFrameData);
  v2 = v1->mData.size;
  if ( v2 >= 1 )
  {
    v3 = 0i64;
    if ( v2 )
    {
      do
      {
        v4 = v1->mData.p[v3];
        if ( v4 )
        {
          UFG::qString::~qString(&v4->CustomTexturePack);
          `eh vector destructor iterator(v4->Icons, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
          `eh vector destructor iterator(
            v4->Captions,
            0x28ui64,
            2,
            (void (__fastcall *)(void *))UFG::qString::~qString);
          operator delete[](v4);
        }
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < v1->mData.size );
    }
    v5 = v1->mData.p;
    if ( v5 )
      operator delete[](v5);
    v1->mData.p = 0i64;
    *(_QWORD *)&v1->mData.size = 0i64;
  }
}

// File Line: 493
// RVA: 0x5F3F50
void __fastcall UFG::UIHKGameplayHelpWidget::PlayButtonCharge(UFG::UIHKGameplayHelpWidget *this, unsigned int id, int index)
{
  unsigned int v3; // er10
  unsigned int v4; // eax
  UFG::UIHKGameplayHelpData *v5; // rdx

  v3 = id;
  if ( this->mOneFrameData.id == id )
    this->mOneFrameData.ChargeAnimState[index] = 1;
  v4 = this->mData.size;
  if ( v4 )
  {
    v5 = this->mData.p[v4 - 1];
    if ( v5 )
    {
      if ( v5->id == v3 )
        v5->ChargeAnimState[index] = 1;
    }
  }
}

// File Line: 507
// RVA: 0x612560
void __fastcall UFG::UIHKGameplayHelpWidget::StopButtonCharge(UFG::UIHKGameplayHelpWidget *this, unsigned int id, int index)
{
  unsigned int v3; // er10
  unsigned int v4; // eax
  UFG::UIHKGameplayHelpData *v5; // rdx

  v3 = id;
  if ( this->mOneFrameData.id == id )
    this->mOneFrameData.ChargeAnimState[index] = 2;
  v4 = this->mData.size;
  if ( v4 )
  {
    v5 = this->mData.p[v4 - 1];
    if ( v5 )
    {
      if ( v5->id == v3 )
        v5->ChargeAnimState[index] = 2;
    }
  }
}

// File Line: 521
// RVA: 0x5E2200
void __fastcall UFG::UIHKGameplayHelpWidget::Flash_SetYOffset(UFG::UIHKGameplayHelpWidget *this, UFG::UIScreen *screen, float yoffset)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 5;
    pargs.mValue.NValue = yoffset;
    Scaleform::GFx::Movie::Invoke(v3, "GameplayHelp_YOffset", 0i64, &pargs, 1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

// File Line: 533
// RVA: 0x5E2760
void __fastcall UFG::UIHKGameplayHelpWidget::Flash_Show(UFG::UIHKGameplayHelpWidget *this, UFG::UIScreen *screen, UFG::UIHKGameplayHelpData *data)
{
  UFG::UIHKGameplayHelpData *v3; // rbp
  UFG::UIHKGameplayHelpWidget *v4; // r13
  const char *v5; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  char *v7; // rbx
  signed __int64 v8; // rdi
  UFG::UI::eButtons *v9; // r15
  const char **v10; // r14
  char *v11; // rbx
  signed __int64 v12; // r12
  unsigned int v13; // ecx
  char *v14; // rax
  char v15; // al
  char *v16; // rdi
  UFG::UI::eButtons v17; // esi
  UFG::UI::eButtons v18; // ecx
  unsigned int v19; // eax
  char v20; // al
  char *v21; // rax
  __int64 v22; // rdi
  const char *v23; // rdi
  bool v24; // di
  bool v25; // bl
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-1F8h]
  __int64 v27; // [rsp+60h] [rbp-1C8h]
  char ptr; // [rsp+70h] [rbp-1B8h]
  char v29; // [rsp+80h] [rbp-1A8h]
  char v30; // [rsp+B0h] [rbp-178h]
  bool v31; // [rsp+240h] [rbp+18h]
  Scaleform::GFx::Movie *v32; // [rsp+248h] [rbp+20h]

  if ( !data )
    return;
  v27 = -2i64;
  v3 = data;
  v4 = this;
  if ( !screen )
    return;
  v32 = screen->mRenderable->m_movie.pObject;
  if ( !v32 )
    return;
  v31 = !data->CustomTexturePack.mLength
     || !(unsigned int)UFG::qStringCompare(this->mTexturePackName.mData, data->CustomTexturePack.mData, -1)
     && (v5 = v4->mTexturePackName.mData,
         v6 = UFG::UIScreenTextureManager::Instance(),
         UFG::UIScreenTextureManager::IsTexturePackLoaded(v6, v5));
  `eh vector constructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v7 = &v29;
  v8 = 8i64;
  do
  {
    if ( (*((_DWORD *)v7 + 2) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**(_QWORD **)v7 + 16i64))(
        *(_QWORD *)v7,
        v7 - 16,
        *((_QWORD *)v7 + 2));
      *(_QWORD *)v7 = 0i64;
    }
    *((_DWORD *)v7 + 2) = 0;
    v7 += 48;
    --v8;
  }
  while ( v8 );
  v9 = v3->Buttons;
  v10 = (const char **)&v3->Icons[0].mData;
  v11 = &v30;
  v12 = 2i64;
  do
  {
    if ( !*((_DWORD *)v10 - 21) && !*((_DWORD *)v10 - 1) )
      goto LABEL_49;
    if ( !UFG::UIScreenManager::s_instance->m_translator->mIsAcceptButtonSwapped
      || (unsigned int)UFG::qStringCompare(*v10, "Icon_Vault", -1)
      && (unsigned int)UFG::qStringCompare(*v10, "Icon_Climb", -1)
      && (unsigned int)UFG::qStringCompare(*v10, "Icon_Jump", -1) )
    {
      v17 = *v9;
      v18 = *v9;
      if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      {
        v19 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(v18, v3->remapContext);
        v16 = &customWorldMapCaption;
        if ( v19 != REMAP_ID_INVALID_2 )
        {
          v20 = UFG::UIHKScreenOptionsButtonMapping::GetKey(v19);
          v16 = (char *)UFG::KeyToTextureName(v20);
        }
        if ( *v16 )
          goto LABEL_38;
        v21 = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(v17);
      }
      else
      {
        v21 = UFG::UI::GetGamepadButtonTextureName(v18, 1);
      }
      v16 = v21;
LABEL_38:
      if ( (*((_DWORD *)v11 - 10) >> 6) & 1 )
      {
        (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**((_QWORD **)v11 - 6) + 16i64))(
          *((_QWORD *)v11 - 6),
          v11 - 64,
          *((_QWORD *)v11 - 4));
        *((_QWORD *)v11 - 6) = 0i64;
      }
      goto LABEL_40;
    }
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      v13 = REMAP_ID_INVALID_2;
      if ( v3->remapContext == RemapContext_OnFoot )
        v13 = REMAP_ID_GRAPPLE_2;
      v14 = &customWorldMapCaption;
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
    if ( (*((_DWORD *)v11 - 10) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**((_QWORD **)v11 - 6) + 16i64))(
        *((_QWORD *)v11 - 6),
        v11 - 64,
        *((_QWORD *)v11 - 4));
      *((_QWORD *)v11 - 6) = 0i64;
    }
LABEL_40:
    *((_QWORD *)v11 - 4) = v16;
    *((_DWORD *)v11 - 10) = 6;
    v22 = (__int64)*(v10 - 10);
    if ( (*((_DWORD *)v11 + 2) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**(_QWORD **)v11 + 16i64))(
        *(_QWORD *)v11,
        v11 - 16,
        *((_QWORD *)v11 + 2));
      *(_QWORD *)v11 = 0i64;
    }
    *((_DWORD *)v11 + 2) = 6;
    *((_QWORD *)v11 + 2) = v22;
    if ( v31 )
    {
      v23 = *v10;
      if ( (*((_DWORD *)v11 + 14) >> 6) & 1 )
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
    v24 = (unsigned int)(*v9 - 27) <= 7;
    if ( (*((_DWORD *)v11 + 26) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**((_QWORD **)v11 + 12) + 16i64))(
        *((_QWORD *)v11 + 12),
        v11 + 80,
        *((_QWORD *)v11 + 14));
      *((_QWORD *)v11 + 12) = 0i64;
    }
    *((_DWORD *)v11 + 26) = 2;
    v11[112] = v24;
LABEL_49:
    v11 += 192;
    ++v9;
    v10 += 5;
    --v12;
  }
  while ( v12 );
  value.pObjectInterface = 0i64;
  value.Type = 0;
  v25 = v3->isWeaponPickup;
  value.Type = 2;
  value.mValue.BValue = v25;
  Scaleform::GFx::Movie::SetVariable(v32, "mc_GameplayHelp.mIsWeaponPickup", &value, 1i64);
  Scaleform::GFx::Movie::Invoke(v32, "GameplayHelp_Show", 0i64, (Scaleform::GFx::Value *)&ptr, 8u);
  if ( !v4->mShowingInFlash )
  {
    ++UFG::UIHKHelpBarWidget::mLocked;
    v4->mShowingInFlash = 1;
  }
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 0;
  `eh vector destructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 604
// RVA: 0x5DB860
void __fastcall UFG::UIHKGameplayHelpWidget::Flash_Hide(UFG::UIHKGameplayHelpWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKGameplayHelpWidget *v2; // rdi
  Scaleform::GFx::Movie *v3; // rcx
  int v4; // eax
  UFG::UIHKScreenGlobalOverlay *v5; // rax
  const char *v6; // rbx
  UFG::UIScreenTextureManager *v7; // rax

  v2 = this;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    Scaleform::GFx::Movie::Invoke(v3, "GameplayHelp_Hide", 0i64, 0i64, 0);
    if ( v2->mShowingInFlash )
    {
      v4 = UFG::UIHKHelpBarWidget::mLocked;
      if ( UFG::UIHKHelpBarWidget::mLocked > 0 )
        v4 = UFG::UIHKHelpBarWidget::mLocked-- - 1;
      if ( v4 < 1 )
      {
        v5 = UFG::UIHKScreenGlobalOverlay::mThis;
        if ( !UFG::UIHKScreenGlobalOverlay::mThis )
          v5 = &gGlobalOverlaySentinel;
        v5->HelpBar.mChanged = 1;
      }
      v2->mShowingInFlash = 0;
    }
    v6 = v2->mTexturePackName.mData;
    v7 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v7, v6);
    UFG::qString::Set(&v2->mTexturePackName, &customWorldMapCaption);
  }
}

// File Line: 622
// RVA: 0x5DE610
void __fastcall UFG::UIHKGameplayHelpWidget::Flash_PlayChargeAnim(UFG::UIHKGameplayHelpWidget *this, UFG::UIScreen *screen, int index)
{
  int v3; // edi
  Scaleform::GFx::Movie *v4; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v3 = index;
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
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v3;
    Scaleform::GFx::Movie::Invoke(v4, "GameplayHelp_PlayButtonCharge", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 636
// RVA: 0x5E5200
void __fastcall UFG::UIHKGameplayHelpWidget::Flash_StopChargeAnim(UFG::UIHKGameplayHelpWidget *this, UFG::UIScreen *screen, int index)
{
  int v3; // edi
  Scaleform::GFx::Movie *v4; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v3 = index;
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
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v3;
    Scaleform::GFx::Movie::Invoke(v4, "GameplayHelp_StopButtonCharge", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

