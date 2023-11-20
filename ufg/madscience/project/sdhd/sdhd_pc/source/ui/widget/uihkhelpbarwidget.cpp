// File Line: 28
// RVA: 0x156DC10
__int64 UFG::_dynamic_initializer_for__gHelpBarSentinel__()
{
  UFG::UIHKHelpBarData::UIHKHelpBarData(&stru_142431488);
  unk_1424316D0 = 0;
  unk_1424316D4 = 0;
  UFG::qString::qString(&stru_1424316D8);
  unk_142431700 = -1;
  unk_142431704 = 0;
  return atexit(UFG::_dynamic_atexit_destructor_for__gHelpBarSentinel__);
}

// File Line: 36
// RVA: 0x5C4260
void __fastcall UFG::UIHKHelpBarData::UIHKHelpBarData(UFG::UIHKHelpBarData *this)
{
  UFG::UIHKHelpBarData *v1; // rdi
  signed __int64 v2; // rbx
  unsigned int *v3; // rax

  v1 = this;
  *(_QWORD *)&this->id = 0i64;
  this->alignment = 1;
  this->isWeaponPickup = 0;
  v2 = 6i64;
  `eh vector constructor iterator'(this->Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::qString);
  `eh vector constructor iterator'(v1->Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::qString);
  UFG::qString::qString(&v1->CustomTexturePack);
  v3 = v1->MessageIds;
  do
  {
    *(v3 - 126) = 0;
    *v3 = 0;
    ++v3;
    --v2;
  }
  while ( v2 );
}

// File Line: 46
// RVA: 0x5D1A10
void __fastcall UFG::UIHKHelpBarData::Add(UFG::UIHKHelpBarData *this, UFG::UI::eButtons button, const char *caption, unsigned int messageId)
{
  int v4; // er11
  unsigned int v5; // esi
  UFG::UIHKHelpBarData *v6; // rdi
  signed __int64 v7; // r10
  UFG::UI::eButtons *v8; // rax
  __int64 v9; // rbx

  v4 = 0;
  v5 = messageId;
  v6 = this;
  v7 = 0i64;
  v8 = this->Buttons;
  while ( *v8 )
  {
    ++v7;
    ++v4;
    ++v8;
    if ( v7 >= 6 )
      return;
  }
  v9 = v4;
  this->Buttons[v4] = button;
  UFG::qString::Set((UFG::qString *)this + v4 + 1i64, caption);
  UFG::qString::Set((UFG::qString *)v6 + v9 + 7, &customWorldMapCaption);
  v6->MessageIds[v9] = v5;
}

// File Line: 64
// RVA: 0x5CEF50
char __fastcall UFG::UIHKHelpBarData::operator==(UFG::UIHKHelpBarData *this, UFG::UIHKHelpBarData *rval)
{
  UFG::UIHKHelpBarData *v2; // rsi
  UFG::UIHKHelpBarData *v3; // rdi
  int v4; // ebx
  UFG::UI::eButtons *v5; // rcx
  signed __int64 v6; // rdx

  v2 = rval;
  v3 = this;
  if ( *(_QWORD *)&this->id != *(_QWORD *)&rval->id || this->alignment != rval->alignment )
    return 0;
  v4 = 0;
  v5 = this->Buttons;
  v6 = 0i64;
  do
  {
    if ( *v5 != *(UFG::UI::eButtons *)((char *)v5 + (char *)v2 - (char *)v3) )
      return 0;
    ++v6;
    ++v5;
  }
  while ( v6 < 6 );
  while ( !UFG::qString::operator!=((UFG::qString *)((char *)v3 + 8 * (5i64 * v4 + 5)), &v2->Captions[v4])
       && !UFG::qString::operator!=((UFG::qString *)v3 + v4 + 7i64, (UFG::qString *)v2 + v4 + 7i64) )
  {
    if ( ++v4 >= 6 )
      return 1;
  }
  return 0;
}

// File Line: 103
// RVA: 0x5C4320
void __fastcall UFG::UIHKHelpBarWidget::UIHKHelpBarWidget(UFG::UIHKHelpBarWidget *this)
{
  UFG::UIHKHelpBarWidget *v1; // rbx

  v1 = this;
  *(_WORD *)&this->mVisible = 0;
  this->mRemappable = 0;
  this->mData.p = 0i64;
  *(_QWORD *)&this->mData.size = 0i64;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&this->mOneFrameData);
  v1->mShowingInFlash = 0;
  v1->mYOffset = 0.0;
  UFG::qString::qString(&v1->mTexturePackName);
  v1->mIndexShowing = -1;
  *(_WORD *)&v1->mShowOneFrameActive = 0;
}

// File Line: 110
// RVA: 0x5C96C0
void __fastcall UFG::UIHKHelpBarWidget::~UIHKHelpBarWidget(UFG::UIHKHelpBarWidget *this)
{
  UFG::UIHKHelpBarWidget *v1; // rdi
  const char *v2; // rbx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIHKHelpBarData **v4; // rcx

  v1 = this;
  UFG::UIHKHelpBarWidget::ClearAll(this);
  v2 = v1->mTexturePackName.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, v2);
  UFG::qString::Set(&v1->mTexturePackName, &customWorldMapCaption);
  UFG::qString::~qString(&v1->mTexturePackName);
  UFG::qString::~qString(&v1->mOneFrameData.CustomTexturePack);
  `eh vector destructor iterator'(
    v1->mOneFrameData.Icons,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(
    v1->mOneFrameData.Captions,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  v4 = v1->mData.p;
  if ( v4 )
    operator delete[](v4);
  v1->mData.p = 0i64;
  *(_QWORD *)&v1->mData.size = 0i64;
}

// File Line: 117
// RVA: 0x5E68D0
UFG::UIHKHelpBarWidget *__fastcall UFG::UIHKHelpBarWidget::Get()
{
  UFG::UIHKScreenGlobalOverlay *v0; // rax

  v0 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v0 = &gGlobalOverlaySentinel;
  return &v0->HelpBar;
}

// File Line: 137
// RVA: 0x611B00
void __fastcall UFG::UIHKHelpBarWidget::Sort(UFG::UIHKHelpBarWidget *this)
{
  unsigned int v1; // esi
  UFG::UIHKHelpBarWidget *v2; // rbx
  __int64 v3; // r10
  unsigned int v4; // er11
  char v5; // di
  signed __int64 v6; // rax
  __int64 v7; // r9
  UFG::UIHKHelpBarData **v8; // rcx
  UFG::UIHKHelpBarData *v9; // r8

  v1 = this->mData.size;
  v2 = this;
  if ( v1 )
  {
    v3 = 0i64;
    v4 = 1;
    do
    {
      v5 = 0;
      if ( v4 >= v1 )
        break;
      v6 = v4;
      v7 = v1 - v4;
      do
      {
        if ( v2->mData.p[v3]->priority < v2->mData.p[v6]->priority )
        {
          v8 = v2->mData.p;
          v5 = 1;
          v9 = v8[v3];
          v8[v3] = v8[v6];
          v2->mData.p[v6] = v9;
        }
        ++v6;
        --v7;
      }
      while ( v7 );
      if ( !v5 )
        break;
      ++v4;
      ++v3;
    }
    while ( v4 - 1 < v1 );
  }
}

// File Line: 162
// RVA: 0x614510
void __fastcall UFG::UIHKHelpBarWidget::Update(UFG::UIHKHelpBarWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rsi
  UFG::UIHKHelpBarWidget *v3; // rbx
  int v4; // er8
  char v5; // r9
  signed __int64 v6; // rdi
  bool v7; // r10
  bool v8; // cl
  bool v9; // dl
  int v10; // eax
  bool v11; // al
  UFG::UIScreen *v12; // rdx
  UFG::UIHKHelpBarWidget *v13; // rcx

  v2 = screen;
  v3 = this;
  if ( this->mChanged )
    UFG::UIHKHelpBarWidget::Sort(this);
  v4 = v3->mData.size;
  v5 = 0;
  v6 = 0i64;
  if ( v4 )
    v6 = (signed __int64)v3->mData.p[v4 - 1];
  v7 = v3->mShowOneFrameActive;
  v8 = v3->mShowOneFrameFlag;
  v3->mChanged |= v7 != v8;
  v9 = v3->mChanged;
  if ( (!v6 || *(_DWORD *)(v6 + 4)) && (v8 || v7) )
  {
    if ( v3->mVisible != v8 || !v8 )
      v5 = 1;
    v3->mVisible = v8;
    v3->mShowOneFrameActive = v8;
    v3->mShowOneFrameFlag = 0;
    v6 = (signed __int64)&v3->mOneFrameData;
    v3->mIndexShowing = -1;
    v3->mChanged = v5 | v9;
  }
  else
  {
    v10 = v3->mIndexShowing;
    v3->mIndexShowing = v4;
    v3->mChanged = v9 || v10 != v4;
  }
  v11 = UFG::UIHKHelpBarWidget::mLocked > 0
     && !UFG::UIScreenManagerBase::getOverlay(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "Camera")
     && !UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "NISPause");
  if ( !v6 || v11 )
  {
    if ( !v3->mShowingInFlash )
      return;
    v12 = v2;
    v13 = v3;
  }
  else
  {
    v3->mVisible |= v3->mData.size != 0;
    if ( !v3->mChanged )
      return;
    v3->mChanged = 0;
    if ( *(_DWORD *)(v6 + 564) )
      UFG::UIHKHelpBarWidget::LoadIconTexturePack(v3, *(const char **)(v6 + 568));
    else
      UFG::UIHKHelpBarWidget::ReleaseIconTexturePack(v3);
    v12 = v2;
    v13 = v3;
    if ( v3->mVisible )
    {
      UFG::UIHKHelpBarWidget::Flash_Show(v3, v2, (UFG::UIHKHelpBarData *)v6);
      UFG::UIHKHelpBarWidget::Flash_SetYOffset(v3, v2, v3->mYOffset);
      UFG::UIHKHelpBarWidget::Flash_SetAlignment(v3, v2, *(UFG::UIHKHelpBarData::eAlignment *)(v6 + 8));
      return;
    }
  }
  UFG::UIHKHelpBarWidget::Flash_Hide(v13, v12);
}

// File Line: 239
// RVA: 0x5EA970
void __fastcall UFG::UIHKHelpBarWidget::HandleMessage(UFG::UIHKHelpBarWidget *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v4; // rsi
  unsigned int v5; // ebx
  UFG::UIScreen *v6; // rbp
  UFG::UIHKHelpBarWidget *v7; // rdi
  unsigned int v8; // eax
  unsigned int v9; // ecx
  UFG::UIHKHelpBarData *v10; // r8
  unsigned int v11; // edx

  v4 = msg;
  v5 = msgId;
  v6 = screen;
  v7 = this;
  if ( msgId == UI_HASH_GAME_UNLOADING_30 )
  {
    UFG::UIHKHelpBarWidget::ClearAll(this);
  }
  else if ( msgId == UI_HASH_INPUT_SWAPPED_30 )
  {
    this->mChanged = 1;
  }
  if ( v5 == UI_HASH_MOUSE_MOVE_30 )
  {
    UFG::UIHKHelpBarWidget::Flash_handleMouseMove(v7, v6, (float)SLODWORD(v4[1].vfptr), (float)SHIDWORD(v4[1].vfptr));
  }
  else if ( v5 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
  {
    UFG::UIHKHelpBarWidget::Flash_handleMouseClick(v7, v6, (float)SLODWORD(v4[1].vfptr), (float)SHIDWORD(v4[1].vfptr));
  }
  else if ( v5 == UI_HASH_MOUSE_SELECT_SLOT_20 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
    v8 = UFG::UI::GetFlashArgsInt(v4);
    v9 = v7->mData.size;
    if ( v9 )
    {
      v10 = v7->mData.p[v9 - 1];
      if ( v10 )
      {
        if ( v8 <= 5 )
        {
          v11 = v10->MessageIds[v8];
          if ( v11 )
            UFG::UIScreenManagerBase::queueMessage(
              (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
              v11,
              0xFFFFFFFF);
        }
      }
    }
  }
}

// File Line: 290
// RVA: 0x5E6290
void __fastcall UFG::UIHKHelpBarWidget::Flash_handleMouseMove(UFG::UIHKHelpBarWidget *this, UFG::UIScreen *screen, float mouseX, float mouseY)
{
  Scaleform::GFx::Movie *v4; // rbx
  char ptr; // [rsp+40h] [rbp-88h]
  __int64 v6; // [rsp+50h] [rbp-78h]
  unsigned int v7; // [rsp+58h] [rbp-70h]
  double v8; // [rsp+60h] [rbp-68h]
  char v9; // [rsp+70h] [rbp-58h]
  __int64 v10; // [rsp+80h] [rbp-48h]
  unsigned int v11; // [rsp+88h] [rbp-40h]
  double v12; // [rsp+90h] [rbp-38h]

  v4 = screen->mRenderable->m_movie.pObject;
  if ( v4 )
  {
    `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v7 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, &ptr, COERCE_DOUBLE(*(_QWORD *)&v8));
      v6 = 0i64;
    }
    v7 = 5;
    v8 = mouseX;
    if ( (v11 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(
        v10,
        &v9,
        COERCE_DOUBLE(*(_QWORD *)&v12));
      v10 = 0i64;
    }
    v11 = 5;
    v12 = mouseY;
    Scaleform::GFx::Movie::Invoke(v4, "HelpBar_handleMouseMove", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 304
// RVA: 0x5E6010
void __fastcall UFG::UIHKHelpBarWidget::Flash_handleMouseClick(UFG::UIHKHelpBarWidget *this, UFG::UIScreen *screen, float mouseX, float mouseY)
{
  Scaleform::GFx::Movie *v4; // rbx
  char ptr; // [rsp+40h] [rbp-88h]
  __int64 v6; // [rsp+50h] [rbp-78h]
  unsigned int v7; // [rsp+58h] [rbp-70h]
  double v8; // [rsp+60h] [rbp-68h]
  char v9; // [rsp+70h] [rbp-58h]
  __int64 v10; // [rsp+80h] [rbp-48h]
  unsigned int v11; // [rsp+88h] [rbp-40h]
  double v12; // [rsp+90h] [rbp-38h]

  v4 = screen->mRenderable->m_movie.pObject;
  if ( v4 )
  {
    `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v7 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, &ptr, COERCE_DOUBLE(*(_QWORD *)&v8));
      v6 = 0i64;
    }
    v7 = 5;
    v8 = mouseX;
    if ( (v11 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(
        v10,
        &v9,
        COERCE_DOUBLE(*(_QWORD *)&v12));
      v10 = 0i64;
    }
    v11 = 5;
    v12 = mouseY;
    Scaleform::GFx::Movie::Invoke(v4, "HelpBar_handleMouseClick", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 319
// RVA: 0x60CE80
void __fastcall UFG::UIHKHelpBarWidget::Show(UFG::UIHKHelpBarWidget *this, UFG::UIHKHelpBarData *data)
{
  UFG::UIHKHelpBarData *v2; // rdi
  UFG::UIHKHelpBarWidget *v3; // rbx
  UFG::UIHK_NISOverlay *v4; // rbp
  int v5; // er8
  unsigned int v6; // er9
  UFG::UIHKHelpBarData **v7; // r10
  unsigned int v8; // edx
  UFG::allocator::free_link *v9; // rax
  UFG::UIHKHelpBarData *v10; // rax
  UFG::UIHKHelpBarData *v11; // r15
  __int64 v12; // r13
  unsigned int v13; // esi
  unsigned int v14; // edi
  unsigned int v15; // edi
  unsigned __int64 v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::UIHKHelpBarData **v18; // r14
  unsigned int i; // er9
  float v20; // xmm0_4
  char v21; // t0

  v2 = data;
  v3 = this;
  *(_WORD *)&this->mVisible = 257;
  this->mRemappable = 0;
  v4 = 0i64;
  v5 = 0;
  v6 = this->mData.size;
  if ( v6 )
  {
    v7 = this->mData.p;
    v8 = data->id;
    while ( v7[v5]->id != v8 )
    {
      if ( ++v5 >= v6 )
        goto LABEL_7;
    }
    UFG::UIHKHelpBarData::operator=(v7[v5], v2);
  }
  else
  {
LABEL_7:
    v9 = UFG::qMalloc(0x248ui64, "UIHKHelpBarData", 0i64);
    if ( v9 )
    {
      UFG::UIHKHelpBarData::UIHKHelpBarData((UFG::UIHKHelpBarData *)v9);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    if ( v11 )
    {
      UFG::UIHKHelpBarData::operator=(v11, v2);
      v12 = v3->mData.size;
      v13 = v12 + 1;
      v14 = v3->mData.capacity;
      if ( (signed int)v12 + 1 > v14 )
      {
        if ( v14 )
          v15 = 2 * v14;
        else
          v15 = 1;
        for ( ; v15 < v13; v15 *= 2 )
          ;
        if ( v15 <= 2 )
          v15 = 2;
        if ( v15 - v13 > 0x10000 )
          v15 = v12 + 65537;
        if ( v15 != (_DWORD)v12 )
        {
          v16 = 8i64 * v15;
          if ( !is_mul_ok(v15, 8ui64) )
            v16 = -1i64;
          v17 = UFG::qMalloc(v16, "qArray.Add", 0i64);
          v18 = (UFG::UIHKHelpBarData **)v17;
          if ( v3->mData.p )
          {
            for ( i = 0; i < v3->mData.size; ++i )
              v17[i] = (UFG::allocator::free_link)v3->mData.p[i];
            operator delete[](v3->mData.p);
          }
          v3->mData.p = v18;
          v3->mData.capacity = v15;
        }
      }
      v3->mData.size = v13;
      v3->mData.p[v12] = v11;
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
        v4 = &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
      v20 = v3->mYOffset;
      v21 = v4->mActive;
      v3->mYOffset = -20.0;
      v3->mChanged |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v20 - -20.0) & _xmm) > 0.001;
    }
  }
}

// File Line: 360
// RVA: 0x611600
void __fastcall UFG::UIHKHelpBarWidget::ShowWithMessage(UFG::UIHKHelpBarWidget *this, unsigned int id, UFG::UIHKHelpBarData::ePriority priority, UFG::UIHKHelpBarData::eAlignment alignment, __int64 button0, const char *caption0, unsigned int messageId0, __int64 button1, const char *caption1, unsigned int messageId1, __int64 button2, const char *caption2, unsigned int messageId2, __int64 button3, const char *caption3, unsigned int messageId3, __int64 button4, const char *caption4, unsigned int messageId4, __int64 button5, const char *caption5)
{
  UFG::UIHKHelpBarData::eAlignment v21; // esi
  UFG::UIHKHelpBarData::ePriority v22; // edi
  unsigned int v23; // ebx
  UFG::UIHKHelpBarWidget *v24; // r14
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-C8h]
  UFG::UI::eButtons v26; // [rsp+2A8h] [rbp+1B0h]

  v21 = alignment;
  v22 = priority;
  v23 = id;
  v24 = this;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = v23;
  data.priority = v22;
  data.alignment = v21;
  data.Buttons[0] = v26;
  data.Buttons[1] = messageId0;
  data.Buttons[2] = messageId1;
  data.Buttons[3] = messageId2;
  data.Buttons[4] = messageId3;
  data.Buttons[5] = messageId4;
  UFG::qString::Set(data.Captions, (const char *)button0);
  UFG::qString::Set((UFG::qString *)((char *)data.Captions + 32), (const char *)button1);
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), (const char *)button2);
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 32), (const char *)button3);
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 32), (const char *)button4);
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 32), (const char *)button5);
  data.Icons[5].mStringHash32 = (unsigned int)caption0;
  data.Icons[5].mStringHashUpper32 = (unsigned int)caption1;
  data.MessageIds[0] = (unsigned int)caption2;
  data.MessageIds[1] = (unsigned int)caption3;
  data.MessageIds[2] = (unsigned int)caption4;
  data.MessageIds[3] = (unsigned int)caption5;
  UFG::UIHKHelpBarWidget::Show(v24, &data);
  UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
  `eh vector destructor iterator'(
    &data.Captions[5].mStringHash32,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 398
// RVA: 0x60D040
void __fastcall UFG::UIHKHelpBarWidget::Show(UFG::UIHKHelpBarWidget *this, unsigned int id, UFG::UIHKHelpBarData::ePriority priority, UFG::UIHKHelpBarData::eAlignment alignment, UFG::UI::eButtons button0, const char *caption0, UFG::UI::eButtons button1, const char *caption1, UFG::UI::eButtons button2, const char *caption2, UFG::UI::eButtons button3, const char *caption3, UFG::UI::eButtons button4, const char *caption4, UFG::UI::eButtons button5, const char *caption5)
{
  __int64 v16; // [rsp+20h] [rbp-98h]
  __int64 v17; // [rsp+38h] [rbp-80h]
  __int64 v18; // [rsp+50h] [rbp-68h]
  __int64 v19; // [rsp+68h] [rbp-50h]
  __int64 v20; // [rsp+80h] [rbp-38h]
  __int64 v21; // [rsp+98h] [rbp-20h]

  LODWORD(v21) = button5;
  LODWORD(v20) = button4;
  LODWORD(v19) = button3;
  LODWORD(v18) = button2;
  LODWORD(v17) = button1;
  LODWORD(v16) = button0;
  UFG::UIHKHelpBarWidget::ShowWithMessage(
    this,
    id,
    priority,
    alignment,
    v16,
    caption0,
    0,
    v17,
    caption1,
    0,
    v18,
    caption2,
    0,
    v19,
    caption3,
    0,
    v20,
    caption4,
    0,
    v21,
    caption5);
}

// File Line: 419
// RVA: 0x5ECAB0
void __fastcall UFG::UIHKHelpBarWidget::Hide(UFG::UIHKHelpBarWidget *this, unsigned int id)
{
  unsigned int v2; // er14
  UFG::UIHKHelpBarWidget *v3; // rbx
  unsigned int v4; // esi
  signed __int64 v5; // rbp
  UFG::UIHKHelpBarData *v6; // rdi
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
          `eh vector destructor iterator'(v6->Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
          `eh vector destructor iterator'(
            v6->Captions,
            0x28ui64,
            6,
            (void (__fastcall *)(void *))UFG::qString::~qString);
          operator delete[](v6);
        }
        v7 = v4 + 1;
        if ( v4 + 1 != v3->mData.size )
        {
          v8 = v5;
          do
          {
            *(UFG::UIHKHelpBarData **)((char *)v3->mData.p + v8 - 8) = *(UFG::UIHKHelpBarData **)((char *)v3->mData.p
                                                                                                + v8);
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

// File Line: 454
// RVA: 0x610D40
void __fastcall UFG::UIHKHelpBarWidget::ShowOneFrame(UFG::UIHKHelpBarWidget *this, UFG::UI::eButtons button0, const char *caption0, UFG::UI::eButtons button1, const char *caption1, UFG::UI::eButtons button2, const char *caption2, UFG::UI::eButtons button3, const char *caption3, UFG::UI::eButtons button4, const char *caption4, UFG::UI::eButtons button5, const char *caption5)
{
  UFG::UI::eButtons v13; // edi
  const char *v14; // rsi
  UFG::UI::eButtons v15; // ebx
  UFG::UIHKHelpBarWidget *v16; // rbp
  UFG::UIHKHelpBarData rval; // [rsp+30h] [rbp-258h]

  v13 = button1;
  v14 = caption0;
  v15 = button0;
  v16 = this;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&rval);
  rval.alignment = 1;
  rval.Buttons[0] = v15;
  rval.Buttons[1] = v13;
  rval.Buttons[2] = button2;
  rval.Buttons[3] = button3;
  rval.Buttons[4] = button4;
  rval.Buttons[5] = button5;
  UFG::qString::Set(rval.Captions, v14);
  UFG::qString::Set(&rval.Captions[1], caption1);
  UFG::qString::Set(&rval.Captions[2], caption2);
  UFG::qString::Set(&rval.Captions[3], caption3);
  UFG::qString::Set(&rval.Captions[4], caption4);
  UFG::qString::Set(&rval.Captions[5], caption5);
  v16->mShowOneFrameFlag = 1;
  v16->mChanged |= UFG::UIHKHelpBarData::operator==(&v16->mOneFrameData, &rval) == 0;
  UFG::UIHKHelpBarData::operator=(&v16->mOneFrameData, &rval);
  v16->mRemappable = 1;
  UFG::qString::~qString(&rval.CustomTexturePack);
  `eh vector destructor iterator'(rval.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(rval.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 485
// RVA: 0x5ED4A0
void __fastcall UFG::UIHKHelpBarWidget::IconTexturePackLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    UFG::UIHKScreenGlobalOverlay::mThis->HelpBar.mChanged = 1;
}

// File Line: 497
// RVA: 0x5F0BF0
void __fastcall UFG::UIHKHelpBarWidget::LoadIconTexturePack(UFG::UIHKHelpBarWidget *this, const char *texturePack)
{
  UFG::UIHKHelpBarWidget *v2; // rsi
  const char *v3; // rdi
  const char *v4; // rbx
  UFG::UIScreenTextureManager *v5; // rax
  UFG::UIScreenTextureManager *v6; // rax

  if ( texturePack )
  {
    v2 = this;
    v3 = texturePack;
    if ( (unsigned int)UFG::qStringCompare(this->mTexturePackName.mData, texturePack, -1) )
    {
      v4 = v2->mTexturePackName.mData;
      v5 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::ReleaseTexturePack(v5, v4);
      UFG::qString::Set(&v2->mTexturePackName, &customWorldMapCaption);
      UFG::qString::Set(&v2->mTexturePackName, v3);
      v6 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueTexturePackLoad(
        v6,
        v3,
        DEFAULT_PRIORITY,
        UFG::UIHKHelpBarWidget::IconTexturePackLoadedCallback,
        0i64);
    }
  }
}

// File Line: 513
// RVA: 0x600B80
void __fastcall UFG::UIHKHelpBarWidget::ReleaseIconTexturePack(UFG::UIHKHelpBarWidget *this)
{
  char *v1; // rbx
  UFG::UIHKHelpBarWidget *v2; // rdi
  UFG::UIScreenTextureManager *v3; // rax

  v1 = this->mTexturePackName.mData;
  v2 = this;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, v1);
  UFG::qString::Set(&v2->mTexturePackName, &customWorldMapCaption);
}

// File Line: 527
// RVA: 0x5F1C60
void UFG::UIHKHelpBarWidget::Lock(void)
{
  ++UFG::UIHKHelpBarWidget::mLocked;
}

// File Line: 533
// RVA: 0x613210
void UFG::UIHKHelpBarWidget::Unlock(void)
{
  int v0; // eax
  UFG::UIHKScreenGlobalOverlay *v1; // rax

  v0 = UFG::UIHKHelpBarWidget::mLocked;
  if ( UFG::UIHKHelpBarWidget::mLocked > 0 )
    v0 = UFG::UIHKHelpBarWidget::mLocked-- - 1;
  if ( v0 < 1 )
  {
    v1 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v1 = &gGlobalOverlaySentinel;
    v1->HelpBar.mChanged = 1;
  }
}

// File Line: 557
// RVA: 0x5D54E0
void __fastcall UFG::UIHKHelpBarWidget::ClearAll(UFG::UIHKHelpBarWidget *this)
{
  UFG::UIHKHelpBarWidget *v1; // rbx
  unsigned int v2; // eax
  __int64 v3; // rdi
  UFG::UIHKHelpBarData *v4; // rsi
  UFG::UIHKHelpBarData **v5; // rcx

  v1 = this;
  v2 = this->mData.size;
  if ( v2 >= 1 )
  {
    *(_WORD *)&this->mVisible = 256;
    v3 = 0i64;
    if ( v2 )
    {
      do
      {
        v4 = v1->mData.p[v3];
        if ( v4 )
        {
          UFG::qString::~qString(&v4->CustomTexturePack);
          `eh vector destructor iterator'(v4->Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
          `eh vector destructor iterator'(
            v4->Captions,
            0x28ui64,
            6,
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

// File Line: 575
// RVA: 0x5E22E0
void __fastcall UFG::UIHKHelpBarWidget::Flash_SetYOffset(UFG::UIHKHelpBarWidget *this, UFG::UIScreen *screen, float yoffset)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 5;
    pargs.mValue.NValue = yoffset;
    Scaleform::GFx::Movie::Invoke(v3, "HelpBar_YOffset", 0i64, &pargs, 1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

// File Line: 587
// RVA: 0x5DF120
void __fastcall UFG::UIHKHelpBarWidget::Flash_SetAlignment(UFG::UIHKHelpBarWidget *this, UFG::UIScreen *screen, UFG::UIHKHelpBarData::eAlignment alignment)
{
  Scaleform::GFx::Movie *v3; // rdi
  const char *v4; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    v4 = "LEFT";
    if ( alignment )
      v4 = "CENTER";
    pargs.pObjectInterface = 0i64;
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v4;
    Scaleform::GFx::Movie::Invoke(v3, "HelpBar_Align", 0i64, &pargs, 1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

// File Line: 609
// RVA: 0x5E2BE0
void __fastcall UFG::UIHKHelpBarWidget::Flash_Show(UFG::UIHKHelpBarWidget *this, UFG::UIScreen *screen, UFG::UIHKHelpBarData *data)
{
  UFG::UIHKHelpBarData *v3; // r13
  UFG::UIHKHelpBarWidget *v4; // rbx
  const char *v5; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  bool v7; // r12
  char *v8; // rbx
  signed __int64 v9; // rdi
  unsigned int *v10; // r14
  signed __int64 v11; // rbp
  char *v12; // rbx
  signed __int64 v13; // r15
  bool v14; // dl
  UFG::UI::eButtons v15; // esi
  UFG::UI::eButtons v16; // ecx
  unsigned int v17; // eax
  char *v18; // rdi
  char v19; // al
  char *v20; // rax
  __int64 v21; // rdi
  __int64 v22; // rdi
  bool v23; // di
  bool v24; // bl
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-4F8h]
  __int64 v26; // [rsp+60h] [rbp-4C8h]
  char ptr; // [rsp+70h] [rbp-4B8h]
  char v28; // [rsp+80h] [rbp-4A8h]
  char v29; // [rsp+B0h] [rbp-478h]
  UFG::UIHKHelpBarWidget *v30; // [rsp+530h] [rbp+8h]
  UFG::UIHKHelpBarData *v31; // [rsp+540h] [rbp+18h]
  Scaleform::GFx::Movie *v32; // [rsp+548h] [rbp+20h]

  if ( !data )
    return;
  v31 = data;
  v30 = this;
  v26 = -2i64;
  v3 = data;
  v4 = this;
  if ( !screen )
    return;
  v32 = screen->mRenderable->m_movie.pObject;
  if ( !v32 )
    return;
  v7 = 1;
  if ( data->CustomTexturePack.mLength )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mTexturePackName.mData, data->CustomTexturePack.mData, -1)
      || (v5 = v4->mTexturePackName.mData,
          v6 = UFG::UIScreenTextureManager::Instance(),
          !UFG::UIScreenTextureManager::IsTexturePackLoaded(v6, v5)) )
    {
      v7 = 0;
    }
  }
  `eh vector constructor iterator'(&ptr, 0x30ui64, 24, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v8 = &v28;
  v9 = 24i64;
  do
  {
    if ( (*((_DWORD *)v8 + 2) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**(_QWORD **)v8 + 16i64))(
        *(_QWORD *)v8,
        v8 - 16,
        *((_QWORD *)v8 + 2));
      *(_QWORD *)v8 = 0i64;
    }
    *((_DWORD *)v8 + 2) = 0;
    v8 += 48;
    --v9;
  }
  while ( v9 );
  v10 = v3->MessageIds;
  v11 = (signed __int64)&v3->Icons[0].mLength;
  v12 = &v29;
  v13 = 6i64;
  do
  {
    if ( !*(_DWORD *)(v11 - 240) && !*(_DWORD *)v11 )
      goto LABEL_36;
    v14 = v30->mRemappable;
    v15 = *(v10 - 126);
    v16 = *(v10 - 126);
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      if ( v14 )
      {
        v17 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(v16, 0);
        v18 = &customWorldMapCaption;
        if ( v17 != REMAP_ID_INVALID_2 )
        {
          v19 = UFG::UIHKScreenOptionsButtonMapping::GetKey(v17);
          v18 = (char *)UFG::KeyToTextureName(v19);
        }
        if ( *v18 )
          goto LABEL_25;
        v16 = v15;
      }
      v20 = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(v16);
    }
    else
    {
      v20 = UFG::UI::GetGamepadButtonTextureName(v16, v14);
    }
    v18 = v20;
LABEL_25:
    if ( (*((_DWORD *)v12 - 10) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**((_QWORD **)v12 - 6) + 16i64))(
        *((_QWORD *)v12 - 6),
        v12 - 64,
        *((_QWORD *)v12 - 4));
      *((_QWORD *)v12 - 6) = 0i64;
    }
    *((_DWORD *)v12 - 10) = 6;
    *((_QWORD *)v12 - 4) = v18;
    v21 = *(_QWORD *)(v11 - 236);
    if ( (*((_DWORD *)v12 + 2) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**(_QWORD **)v12 + 16i64))(
        *(_QWORD *)v12,
        v12 - 16,
        *((_QWORD *)v12 + 2));
      *(_QWORD *)v12 = 0i64;
    }
    *((_DWORD *)v12 + 2) = 6;
    *((_QWORD *)v12 + 2) = v21;
    if ( v7 )
    {
      v22 = *(_QWORD *)(v11 + 4);
      if ( (*((_DWORD *)v12 + 14) >> 6) & 1 )
      {
        (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**((_QWORD **)v12 + 6) + 16i64))(
          *((_QWORD *)v12 + 6),
          v12 + 32,
          *((_QWORD *)v12 + 8));
        *((_QWORD *)v12 + 6) = 0i64;
      }
      *((_DWORD *)v12 + 14) = 6;
      *((_QWORD *)v12 + 8) = v22;
    }
    v23 = *v10 != 0;
    if ( (*((_DWORD *)v12 + 26) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**((_QWORD **)v12 + 12) + 16i64))(
        *((_QWORD *)v12 + 12),
        v12 + 80,
        *((_QWORD *)v12 + 14));
      *((_QWORD *)v12 + 12) = 0i64;
    }
    *((_DWORD *)v12 + 26) = 2;
    v12[112] = v23;
LABEL_36:
    v12 += 192;
    ++v10;
    v11 += 40i64;
    --v13;
  }
  while ( v13 );
  value.pObjectInterface = 0i64;
  value.Type = 0;
  v24 = v31->isWeaponPickup;
  value.Type = 2;
  value.mValue.BValue = v24;
  Scaleform::GFx::Movie::SetVariable(v32, "mc_Helpbar.mIsWeaponPickup", &value, 1i64);
  Scaleform::GFx::Movie::Invoke(v32, "HelpBar_Show", 0i64, (Scaleform::GFx::Value *)&ptr, 0x18u);
  v30->mShowingInFlash = 1;
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 0;
  `eh vector destructor iterator'(&ptr, 0x30ui64, 24, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 662
// RVA: 0x5DB920
void __fastcall UFG::UIHKHelpBarWidget::Flash_Hide(UFG::UIHKHelpBarWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKHelpBarWidget *v2; // rdi
  Scaleform::GFx::Movie *v3; // rcx
  const char *v4; // rbx
  UFG::UIScreenTextureManager *v5; // rax

  v2 = this;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    Scaleform::GFx::Movie::Invoke(v3, "HelpBar_Hide", 0i64, 0i64, 0);
    v4 = v2->mTexturePackName.mData;
    v2->mShowingInFlash = 0;
    v5 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v5, v4);
    UFG::qString::Set(&v2->mTexturePackName, &customWorldMapCaption);
  }
}

