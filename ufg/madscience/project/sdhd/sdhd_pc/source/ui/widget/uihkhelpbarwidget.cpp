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
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gHelpBarSentinel__);
}

// File Line: 36
// RVA: 0x5C4260
void __fastcall UFG::UIHKHelpBarData::UIHKHelpBarData(UFG::UIHKHelpBarData *this)
{
  __int64 v2; // rbx
  unsigned int *MessageIds; // rax

  *(_QWORD *)&this->id = 0i64;
  this->alignment = ALIGN_RIGHT;
  this->isWeaponPickup = 0;
  v2 = 6i64;
  `eh vector constructor iterator(this->Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::qString);
  `eh vector constructor iterator(this->Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::qString);
  UFG::qString::qString(&this->CustomTexturePack);
  MessageIds = this->MessageIds;
  do
  {
    *(MessageIds - 126) = 0;
    *MessageIds++ = 0;
    --v2;
  }
  while ( v2 );
}

// File Line: 46
// RVA: 0x5D1A10
void __fastcall UFG::UIHKHelpBarData::Add(
        UFG::UIHKHelpBarData *this,
        UFG::UI::eButtons button,
        const char *caption,
        unsigned int messageId)
{
  int v4; // r11d
  __int64 v7; // r10
  UFG::UI::eButtons *i; // rax
  __int64 v9; // rbx

  v4 = 0;
  v7 = 0i64;
  for ( i = this->Buttons; *i; ++i )
  {
    ++v7;
    ++v4;
    if ( v7 >= 6 )
      return;
  }
  v9 = v4;
  this->Buttons[v4] = button;
  UFG::qString::Set(&this->Captions[v4], caption);
  UFG::qString::Set(&this->Icons[v9], &customCaption);
  this->MessageIds[v9] = messageId;
}

// File Line: 64
// RVA: 0x5CEF50
char __fastcall UFG::UIHKHelpBarData::operator==(UFG::UIHKHelpBarData *this, UFG::UIHKHelpBarData *rval)
{
  int v4; // ebx
  UFG::UI::eButtons *Buttons; // rcx
  __int64 i; // rdx

  if ( this->id != rval->id || this->priority != rval->priority || this->alignment != rval->alignment )
    return 0;
  v4 = 0;
  Buttons = this->Buttons;
  for ( i = 0i64; i < 6; ++i )
  {
    if ( *Buttons != *(UFG::UI::eButtons *)((char *)Buttons + (char *)rval - (char *)this) )
      return 0;
    ++Buttons;
  }
  while ( !UFG::qString::operator!=(&this->Captions[v4], &rval->Captions[v4])
       && !UFG::qString::operator!=(&this->Icons[v4], &rval->Icons[v4]) )
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
  *(_WORD *)&this->mVisible = 0;
  this->mRemappable = 0;
  this->mData.p = 0i64;
  *(_QWORD *)&this->mData.size = 0i64;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&this->mOneFrameData);
  this->mShowingInFlash = 0;
  this->mYOffset = 0.0;
  UFG::qString::qString(&this->mTexturePackName);
  this->mIndexShowing = -1;
  *(_WORD *)&this->mShowOneFrameActive = 0;
}

// File Line: 110
// RVA: 0x5C96C0
void __fastcall UFG::UIHKHelpBarWidget::~UIHKHelpBarWidget(UFG::UIHKHelpBarWidget *this)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIHKHelpBarData **p; // rcx

  UFG::UIHKHelpBarWidget::ClearAll(this);
  mData = this->mTexturePackName.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, mData);
  UFG::qString::Set(&this->mTexturePackName, &customCaption);
  UFG::qString::~qString(&this->mTexturePackName);
  UFG::qString::~qString(&this->mOneFrameData.CustomTexturePack);
  `eh vector destructor iterator(
    this->mOneFrameData.Icons,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(
    this->mOneFrameData.Captions,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  p = this->mData.p;
  if ( p )
    operator delete[](p);
  this->mData.p = 0i64;
  *(_QWORD *)&this->mData.size = 0i64;
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
  unsigned int size; // esi
  __int64 v3; // r10
  unsigned int v4; // r11d
  char v5; // di
  __int64 v6; // rax
  __int64 v7; // r9
  UFG::UIHKHelpBarData **p; // rcx
  UFG::UIHKHelpBarData *v9; // r8

  size = this->mData.size;
  if ( size )
  {
    v3 = 0i64;
    v4 = 1;
    do
    {
      v5 = 0;
      if ( v4 >= size )
        break;
      v6 = v4;
      v7 = size - v4;
      do
      {
        if ( this->mData.p[v3]->priority < this->mData.p[v6]->priority )
        {
          p = this->mData.p;
          v5 = 1;
          v9 = p[v3];
          p[v3] = p[v6];
          this->mData.p[v6] = v9;
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
    while ( v4 - 1 < size );
  }
}

// File Line: 162
// RVA: 0x614510
void __fastcall UFG::UIHKHelpBarWidget::Update(UFG::UIHKHelpBarWidget *this, UFG::UIScreen *screen)
{
  int size; // r8d
  char v5; // r9
  UFG::UIHKHelpBarData *p_mOneFrameData; // rdi
  char mShowOneFrameActive; // r10
  char mShowOneFrameFlag; // cl
  bool mChanged; // dl
  int mIndexShowing; // eax
  bool v11; // al
  UFG::UIScreen *v12; // rdx
  UFG::UIHKHelpBarWidget *v13; // rcx

  if ( this->mChanged )
    UFG::UIHKHelpBarWidget::Sort(this);
  size = this->mData.size;
  v5 = 0;
  p_mOneFrameData = 0i64;
  if ( size )
    p_mOneFrameData = this->mData.p[size - 1];
  mShowOneFrameActive = this->mShowOneFrameActive;
  mShowOneFrameFlag = this->mShowOneFrameFlag;
  this->mChanged |= mShowOneFrameActive != mShowOneFrameFlag;
  mChanged = this->mChanged;
  if ( (!p_mOneFrameData || p_mOneFrameData->priority) && (mShowOneFrameFlag || mShowOneFrameActive) )
  {
    if ( this->mVisible != mShowOneFrameFlag || !mShowOneFrameFlag )
      v5 = 1;
    this->mVisible = mShowOneFrameFlag;
    this->mShowOneFrameActive = mShowOneFrameFlag;
    this->mShowOneFrameFlag = 0;
    p_mOneFrameData = &this->mOneFrameData;
    this->mIndexShowing = -1;
    this->mChanged = v5 | mChanged;
  }
  else
  {
    mIndexShowing = this->mIndexShowing;
    this->mIndexShowing = size;
    this->mChanged = mChanged || mIndexShowing != size;
  }
  v11 = UFG::UIHKHelpBarWidget::mLocked > 0
     && !UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Camera")
     && !UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause");
  if ( !p_mOneFrameData || v11 )
  {
    if ( !this->mShowingInFlash )
      return;
    v12 = screen;
    v13 = this;
  }
  else
  {
    this->mVisible |= this->mData.size != 0;
    if ( !this->mChanged )
      return;
    this->mChanged = 0;
    if ( p_mOneFrameData->CustomTexturePack.mLength )
      UFG::UIHKHelpBarWidget::LoadIconTexturePack(this, p_mOneFrameData->CustomTexturePack.mData);
    else
      UFG::UIHKHelpBarWidget::ReleaseIconTexturePack(this);
    v12 = screen;
    v13 = this;
    if ( this->mVisible )
    {
      UFG::UIHKHelpBarWidget::Flash_Show(this, screen, p_mOneFrameData);
      UFG::UIHKHelpBarWidget::Flash_SetYOffset(this, screen, this->mYOffset);
      UFG::UIHKHelpBarWidget::Flash_SetAlignment(this, screen, p_mOneFrameData->alignment);
      return;
    }
  }
  UFG::UIHKHelpBarWidget::Flash_Hide(v13, v12);
}

// File Line: 239
// RVA: 0x5EA970
void __fastcall UFG::UIHKHelpBarWidget::HandleMessage(
        UFG::UIHKHelpBarWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  unsigned int FlashArgsInt; // eax
  unsigned int size; // ecx
  UFG::UIHKHelpBarData *v10; // r8
  unsigned int v11; // edx

  if ( msgId == UI_HASH_GAME_UNLOADING_30 )
  {
    UFG::UIHKHelpBarWidget::ClearAll(this);
  }
  else if ( msgId == UI_HASH_INPUT_SWAPPED_30 )
  {
    this->mChanged = 1;
  }
  if ( msgId == UI_HASH_MOUSE_MOVE_30 )
  {
    UFG::UIHKHelpBarWidget::Flash_handleMouseMove(
      this,
      screen,
      (float)SLODWORD(msg[1].vfptr),
      (float)SHIDWORD(msg[1].vfptr));
  }
  else if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
  {
    UFG::UIHKHelpBarWidget::Flash_handleMouseClick(
      this,
      screen,
      (float)SLODWORD(msg[1].vfptr),
      (float)SHIDWORD(msg[1].vfptr));
  }
  else if ( msgId == UI_HASH_MOUSE_SELECT_SLOT_20 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
    FlashArgsInt = UFG::UI::GetFlashArgsInt(msg);
    size = this->mData.size;
    if ( size )
    {
      v10 = this->mData.p[size - 1];
      if ( v10 )
      {
        if ( FlashArgsInt <= 5 )
        {
          v11 = v10->MessageIds[FlashArgsInt];
          if ( v11 )
            UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v11, 0xFFFFFFFF);
        }
      }
    }
  }
}

// File Line: 290
// RVA: 0x5E6290
void __fastcall UFG::UIHKHelpBarWidget::Flash_handleMouseMove(
        UFG::UIHKHelpBarWidget *this,
        UFG::UIScreen *screen,
        float mouseX,
        float mouseY)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-88h] BYREF
  char v6[16]; // [rsp+70h] [rbp-58h] BYREF
  __int64 v7; // [rsp+80h] [rbp-48h]
  int v8; // [rsp+88h] [rbp-40h]
  double v9; // [rsp+90h] [rbp-38h]

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = mouseX;
    if ( (v8 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v7 + 16i64))(v7, v6, COERCE_DOUBLE(*(_QWORD *)&v9));
      v7 = 0i64;
    }
    v8 = 5;
    v9 = mouseY;
    Scaleform::GFx::Movie::Invoke(pObject, "HelpBar_handleMouseMove", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 304
// RVA: 0x5E6010
void __fastcall UFG::UIHKHelpBarWidget::Flash_handleMouseClick(
        UFG::UIHKHelpBarWidget *this,
        UFG::UIScreen *screen,
        float mouseX,
        float mouseY)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-88h] BYREF
  char v6[16]; // [rsp+70h] [rbp-58h] BYREF
  __int64 v7; // [rsp+80h] [rbp-48h]
  int v8; // [rsp+88h] [rbp-40h]
  double v9; // [rsp+90h] [rbp-38h]

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = mouseX;
    if ( (v8 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v7 + 16i64))(v7, v6, COERCE_DOUBLE(*(_QWORD *)&v9));
      v7 = 0i64;
    }
    v8 = 5;
    v9 = mouseY;
    Scaleform::GFx::Movie::Invoke(pObject, "HelpBar_handleMouseClick", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 319
// RVA: 0x60CE80
void __fastcall UFG::UIHKHelpBarWidget::Show(UFG::UIHKHelpBarWidget *this, UFG::UIHKHelpBarData *data)
{
  int v4; // r8d
  unsigned int size; // r9d
  UFG::UIHKHelpBarData **p; // r10
  unsigned int id; // edx
  UFG::allocator::free_link *v8; // rax
  UFG::UIHKHelpBarData *v9; // rax
  UFG::UIHKHelpBarData *v10; // r15
  __int64 v11; // r13
  unsigned int v12; // esi
  unsigned int capacity; // edi
  unsigned int v14; // edi
  unsigned __int64 v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::UIHKHelpBarData **v17; // r14
  unsigned int i; // r9d
  float mYOffset; // xmm0_4

  *(_WORD *)&this->mVisible = 257;
  this->mRemappable = 0;
  v4 = 0;
  size = this->mData.size;
  if ( size )
  {
    p = this->mData.p;
    id = data->id;
    while ( p[v4]->id != id )
    {
      if ( ++v4 >= size )
        goto LABEL_7;
    }
    UFG::UIHKHelpBarData::operator=(p[v4], data);
  }
  else
  {
LABEL_7:
    v8 = UFG::qMalloc(0x248ui64, "UIHKHelpBarData", 0i64);
    if ( v8 )
    {
      UFG::UIHKHelpBarData::UIHKHelpBarData((UFG::UIHKHelpBarData *)v8);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    if ( v10 )
    {
      UFG::UIHKHelpBarData::operator=(v10, data);
      v11 = this->mData.size;
      v12 = v11 + 1;
      capacity = this->mData.capacity;
      if ( (int)v11 + 1 > capacity )
      {
        if ( capacity )
          v14 = 2 * capacity;
        else
          v14 = 1;
        for ( ; v14 < v12; v14 *= 2 )
          ;
        if ( v14 <= 2 )
          v14 = 2;
        if ( v14 - v12 > 0x10000 )
          v14 = v11 + 65537;
        if ( v14 != (_DWORD)v11 )
        {
          v15 = 8i64 * v14;
          if ( !is_mul_ok(v14, 8ui64) )
            v15 = -1i64;
          v16 = UFG::qMalloc(v15, "qArray.Add", 0i64);
          v17 = (UFG::UIHKHelpBarData **)v16;
          if ( this->mData.p )
          {
            for ( i = 0; i < this->mData.size; ++i )
              v16[i] = (UFG::allocator::free_link)this->mData.p[i];
            operator delete[](this->mData.p);
          }
          this->mData.p = v17;
          this->mData.capacity = v14;
        }
      }
      this->mData.size = v12;
      this->mData.p[v11] = v10;
      mYOffset = this->mYOffset;
      this->mYOffset = -20.0;
      this->mChanged |= COERCE_FLOAT(COERCE_UNSIGNED_INT(mYOffset - -20.0) & _xmm) > 0.001;
    }
  }
}

// File Line: 360
// RVA: 0x611600
void __fastcall UFG::UIHKHelpBarWidget::ShowWithMessage(
        UFG::UIHKHelpBarWidget *this,
        unsigned int id,
        UFG::UIHKHelpBarData::ePriority priority,
        UFG::UIHKHelpBarData::eAlignment alignment,
        const char *button0,
        const char *caption0,
        unsigned int messageId0,
        const char *button1,
        const char *caption1,
        unsigned int messageId1,
        const char *button2,
        const char *caption2,
        unsigned int messageId2,
        const char *button3,
        const char *caption3,
        unsigned int messageId3,
        const char *button4,
        const char *caption4,
        unsigned int messageId4,
        const char *button5,
        const char *caption5)
{
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-C8h] BYREF
  UFG::UI::eButtons v26; // [rsp+2A8h] [rbp+1B0h]

  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = id;
  data.priority = priority;
  data.alignment = alignment;
  data.Buttons[0] = v26;
  data.Buttons[1] = messageId0;
  data.Buttons[2] = messageId1;
  data.Buttons[3] = messageId2;
  data.Buttons[4] = messageId3;
  data.Buttons[5] = messageId4;
  UFG::qString::Set(data.Captions, button0);
  UFG::qString::Set((UFG::qString *)&data.Captions[0].mStringHash32, button1);
  UFG::qString::Set((UFG::qString *)&data.Captions[1].mStringHash32, button2);
  UFG::qString::Set((UFG::qString *)&data.Captions[2].mStringHash32, button3);
  UFG::qString::Set((UFG::qString *)&data.Captions[3].mStringHash32, button4);
  UFG::qString::Set((UFG::qString *)&data.Captions[4].mStringHash32, button5);
  data.Icons[5].mStringHash32 = (unsigned int)caption0;
  data.Icons[5].mStringHashUpper32 = (unsigned int)caption1;
  data.MessageIds[0] = (unsigned int)caption2;
  data.MessageIds[1] = (unsigned int)caption3;
  data.MessageIds[2] = (unsigned int)caption4;
  data.MessageIds[3] = (unsigned int)caption5;
  UFG::UIHKHelpBarWidget::Show(this, &data);
  UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
  `eh vector destructor iterator(
    &data.Captions[5].mStringHash32,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 398
// RVA: 0x60D040
void __fastcall UFG::UIHKHelpBarWidget::Show(
        UFG::UIHKHelpBarWidget *this,
        unsigned int id,
        UFG::UIHKHelpBarData::ePriority priority,
        UFG::UIHKHelpBarData::eAlignment alignment,
        UFG::UI::eButtons button0,
        const char *caption0,
        UFG::UI::eButtons button1,
        const char *caption1,
        UFG::UI::eButtons button2,
        const char *caption2,
        UFG::UI::eButtons button3,
        const char *caption3,
        UFG::UI::eButtons button4,
        const char *caption4,
        UFG::UI::eButtons button5,
        const char *caption5)
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
  unsigned int v4; // esi
  __int64 v5; // rbp
  UFG::UIHKHelpBarData *v6; // rdi
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
          `eh vector destructor iterator(v6->Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
          `eh vector destructor iterator(
            v6->Captions,
            0x28ui64,
            6,
            (void (__fastcall *)(void *))UFG::qString::~qString);
          operator delete[](v6);
        }
        v7 = v4 + 1;
        if ( v4 + 1 != this->mData.size )
        {
          v8 = v5;
          do
          {
            *(UFG::UIHKHelpBarData **)((char *)this->mData.p + v8 - 8) = *(UFG::UIHKHelpBarData **)((char *)this->mData.p
                                                                                                  + v8);
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

// File Line: 454
// RVA: 0x610D40
void __fastcall UFG::UIHKHelpBarWidget::ShowOneFrame(
        UFG::UIHKHelpBarWidget *this,
        UFG::UI::eButtons button0,
        const char *caption0,
        UFG::UI::eButtons button1,
        const char *caption1,
        UFG::UI::eButtons button2,
        const char *caption2,
        UFG::UI::eButtons button3,
        const char *caption3,
        UFG::UI::eButtons button4,
        const char *caption4,
        UFG::UI::eButtons button5,
        const char *caption5)
{
  UFG::UIHKHelpBarData rval; // [rsp+30h] [rbp-258h] BYREF

  UFG::UIHKHelpBarData::UIHKHelpBarData(&rval);
  rval.alignment = ALIGN_RIGHT;
  rval.Buttons[0] = button0;
  rval.Buttons[1] = button1;
  rval.Buttons[2] = button2;
  rval.Buttons[3] = button3;
  rval.Buttons[4] = button4;
  rval.Buttons[5] = button5;
  UFG::qString::Set(rval.Captions, caption0);
  UFG::qString::Set(&rval.Captions[1], caption1);
  UFG::qString::Set(&rval.Captions[2], caption2);
  UFG::qString::Set(&rval.Captions[3], caption3);
  UFG::qString::Set(&rval.Captions[4], caption4);
  UFG::qString::Set(&rval.Captions[5], caption5);
  this->mShowOneFrameFlag = 1;
  this->mChanged |= UFG::UIHKHelpBarData::operator==(&this->mOneFrameData, &rval) == 0;
  UFG::UIHKHelpBarData::operator=(&this->mOneFrameData, &rval);
  this->mRemappable = 1;
  UFG::qString::~qString(&rval.CustomTexturePack);
  `eh vector destructor iterator(rval.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(rval.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
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
  char *mData; // rbx
  UFG::UIScreenTextureManager *v5; // rax
  UFG::UIScreenTextureManager *v6; // rax

  if ( texturePack )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mTexturePackName.mData, texturePack, -1) )
    {
      mData = this->mTexturePackName.mData;
      v5 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::ReleaseTexturePack(v5, mData);
      UFG::qString::Set(&this->mTexturePackName, &customCaption);
      UFG::qString::Set(&this->mTexturePackName, texturePack);
      v6 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueTexturePackLoad(
        v6,
        texturePack,
        DEFAULT_PRIORITY,
        (UFG::qReflectInventoryBase *)UFG::UIHKHelpBarWidget::IconTexturePackLoadedCallback,
        0i64);
    }
  }
}

// File Line: 513
// RVA: 0x600B80
void __fastcall UFG::UIHKHelpBarWidget::ReleaseIconTexturePack(UFG::UIHKHelpBarWidget *this)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v3; // rax

  mData = this->mTexturePackName.mData;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v3, mData);
  UFG::qString::Set(&this->mTexturePackName, &customCaption);
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
    v0 = --UFG::UIHKHelpBarWidget::mLocked;
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
  __int64 v2; // rdi
  UFG::UIHKHelpBarData *v3; // rsi
  UFG::UIHKHelpBarData **p; // rcx

  if ( this->mData.size )
  {
    *(_WORD *)&this->mVisible = 256;
    v2 = 0i64;
    do
    {
      v3 = this->mData.p[v2];
      if ( v3 )
      {
        UFG::qString::~qString(&v3->CustomTexturePack);
        `eh vector destructor iterator(v3->Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
        `eh vector destructor iterator(v3->Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
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

// File Line: 575
// RVA: 0x5E22E0
void __fastcall UFG::UIHKHelpBarWidget::Flash_SetYOffset(
        UFG::UIHKHelpBarWidget *this,
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
    Scaleform::GFx::Movie::Invoke(pObject, "HelpBar_YOffset", 0i64, &pargs, 1u);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 587
// RVA: 0x5DF120
void __fastcall UFG::UIHKHelpBarWidget::Flash_SetAlignment(
        UFG::UIHKHelpBarWidget *this,
        UFG::UIScreen *screen,
        UFG::UIHKHelpBarData::eAlignment alignment)
{
  Scaleform::GFx::Movie *pObject; // rdi
  const char *v4; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    v4 = "LEFT";
    if ( alignment )
      v4 = "CENTER";
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_String;
    pargs.mValue.pString = v4;
    Scaleform::GFx::Movie::Invoke(pObject, "HelpBar_Align", 0i64, &pargs, 1u);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 609
// RVA: 0x5E2BE0
void __fastcall UFG::UIHKHelpBarWidget::Flash_Show(
        UFG::UIHKHelpBarWidget *this,
        UFG::UIScreen *screen,
        UFG::UIHKHelpBarData *data)
{
  char *mData; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  bool v7; // r12
  Scaleform::GFx::Value::ObjectInterface **p_pObjectInterface; // rbx
  __int64 v9; // rdi
  unsigned int *MessageIds; // r14
  int *p_mLength; // rbp
  char *v12; // rbx
  __int64 v13; // r15
  bool mRemappable; // dl
  UFG::UI::eButtons v15; // esi
  UFG::UI::eButtons v16; // ecx
  unsigned int v17; // eax
  char *v18; // rdi
  char Key; // al
  char *KeyboardButtonTextureNameNonRemappable; // rax
  __int64 v21; // rdi
  __int64 v22; // rdi
  bool v23; // di
  bool isWeaponPickup; // bl
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-4F8h] BYREF
  __int64 v26; // [rsp+60h] [rbp-4C8h]
  Scaleform::GFx::Value ptr; // [rsp+70h] [rbp-4B8h] BYREF
  char v28; // [rsp+B0h] [rbp-478h] BYREF
  Scaleform::GFx::Movie *pObject; // [rsp+548h] [rbp+20h]

  if ( !data )
    return;
  v26 = -2i64;
  if ( !screen )
    return;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( !pObject )
    return;
  v7 = 1;
  if ( data->CustomTexturePack.mLength )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mTexturePackName.mData, data->CustomTexturePack.mData, -1)
      || (mData = this->mTexturePackName.mData,
          v6 = UFG::UIScreenTextureManager::Instance(),
          !UFG::UIScreenTextureManager::IsTexturePackLoaded(v6, mData)) )
    {
      v7 = 0;
    }
  }
  `eh vector constructor iterator(&ptr, 0x30ui64, 24, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  p_pObjectInterface = &ptr.pObjectInterface;
  v9 = 24i64;
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
    --v9;
  }
  while ( v9 );
  MessageIds = data->MessageIds;
  p_mLength = &data->Icons[0].mLength;
  v12 = &v28;
  v13 = 6i64;
  do
  {
    if ( !*(p_mLength - 60) && !*p_mLength )
      goto LABEL_36;
    mRemappable = this->mRemappable;
    v15 = *(MessageIds - 126);
    v16 = v15;
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      if ( mRemappable )
      {
        v17 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(v15, RemapContext_OnFoot);
        v18 = &customCaption;
        if ( v17 != REMAP_ID_INVALID_2 )
        {
          Key = UFG::UIHKScreenOptionsButtonMapping::GetKey(v17);
          v18 = (char *)UFG::KeyToTextureName(Key);
        }
        if ( *v18 )
          goto LABEL_25;
        v16 = v15;
      }
      KeyboardButtonTextureNameNonRemappable = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(v16);
    }
    else
    {
      KeyboardButtonTextureNameNonRemappable = UFG::UI::GetGamepadButtonTextureName(v15, mRemappable);
    }
    v18 = KeyboardButtonTextureNameNonRemappable;
LABEL_25:
    if ( (*((_DWORD *)v12 - 10) & 0x40) != 0 )
    {
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**((_QWORD **)v12 - 6) + 16i64))(
        *((_QWORD *)v12 - 6),
        v12 - 64,
        *((_QWORD *)v12 - 4));
      *((_QWORD *)v12 - 6) = 0i64;
    }
    *((_DWORD *)v12 - 10) = 6;
    *((_QWORD *)v12 - 4) = v18;
    v21 = *(_QWORD *)(p_mLength - 59);
    if ( (*((_DWORD *)v12 + 2) & 0x40) != 0 )
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
      v22 = *(_QWORD *)(p_mLength + 1);
      if ( (*((_DWORD *)v12 + 14) & 0x40) != 0 )
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
    v23 = *MessageIds != 0;
    if ( (*((_DWORD *)v12 + 26) & 0x40) != 0 )
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
    ++MessageIds;
    p_mLength += 10;
    --v13;
  }
  while ( v13 );
  value.pObjectInterface = 0i64;
  value.Type = VT_Undefined;
  isWeaponPickup = data->isWeaponPickup;
  value.Type = VT_Boolean;
  value.mValue.BValue = isWeaponPickup;
  Scaleform::GFx::Movie::SetVariable(pObject, "mc_Helpbar.mIsWeaponPickup", &value, 1i64);
  Scaleform::GFx::Movie::Invoke(pObject, "HelpBar_Show", 0i64, &ptr, 0x18u);
  this->mShowingInFlash = 1;
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Undefined;
  `eh vector destructor iterator(&ptr, 0x30ui64, 24, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 662
// RVA: 0x5DB920
void __fastcall UFG::UIHKHelpBarWidget::Flash_Hide(UFG::UIHKHelpBarWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx
  char *mData; // rbx
  UFG::UIScreenTextureManager *v5; // rax

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "HelpBar_Hide", 0i64, 0i64, 0);
    mData = this->mTexturePackName.mData;
    this->mShowingInFlash = 0;
    v5 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v5, mData);
    UFG::qString::Set(&this->mTexturePackName, &customCaption);
  }
}

