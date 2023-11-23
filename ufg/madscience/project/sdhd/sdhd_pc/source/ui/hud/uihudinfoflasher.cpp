// File Line: 45
// RVA: 0x6208A0
UFG::UIHUDInfoFlasher *__fastcall UFG::UIHUDInfoFlasher::getInstance()
{
  return UFG::UIHUDInfoFlasher::mInstance;
}

// File Line: 133
// RVA: 0x63B2B0
void __fastcall UFG::UIHUDInfoFlasher::show(UFG::UIHUDInfoFlasher *this, UFG::InfoFlasherBase *new_flasher)
{
  UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *mPrev; // rax

  if ( new_flasher )
  {
    mPrev = this->mFlasherList.mNode.mPrev;
    mPrev->mNext = &new_flasher->UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase>;
    new_flasher->mPrev = mPrev;
    new_flasher->mNext = &this->mFlasherList.mNode;
    this->mFlasherList.mNode.mPrev = &new_flasher->UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase>;
  }
}

// File Line: 166
// RVA: 0x5C3AF0
void __fastcall UFG::InfoFlasherBase::InfoFlasherBase(
        UFG::InfoFlasherBase *this,
        const char *text,
        float displayTime,
        bool repeat,
        float repeatTime)
{
  this->mPrev = &this->UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase>;
  this->mNext = &this->UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase>;
  this->vfptr = (UFG::InfoFlasherBaseVtbl *)&UFG::InfoFlasherBase::`vftable;
  this->m_eState = STATE_IDLE;
  UFG::qString::qString(&this->m_sHintTxt, text);
  this->m_fDisplayTime = displayTime;
  this->m_bRepeatMsg = repeat;
  this->m_fRepeatTime = repeatTime;
  *(_QWORD *)&this->m_fTimerDisplay = 0i64;
  this->m_fHintReminderTimeout = 0.0;
  this->mGFxMovie.pObjectInterface = 0i64;
  this->mGFxMovie.Type = VT_Undefined;
}

// File Line: 171
// RVA: 0x5C9180
void __fastcall UFG::InfoFlasherBase::~InfoFlasherBase(UFG::InfoFlasherBase *this)
{
  UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *mPrev; // rcx
  UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase> *mNext; // rax

  this->vfptr = (UFG::InfoFlasherBaseVtbl *)&UFG::InfoFlasherBase::`vftable;
  if ( (this->mGFxMovie.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->mGFxMovie.pObjectInterface->vfptr->gap8[8])(
      this->mGFxMovie.pObjectInterface,
      &this->mGFxMovie,
      this->mGFxMovie.mValue);
    this->mGFxMovie.pObjectInterface = 0i64;
  }
  this->mGFxMovie.Type = VT_Undefined;
  UFG::qString::~qString(&this->m_sHintTxt);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase>;
  this->mNext = &this->UFG::qNode<UFG::InfoFlasherBase,UFG::InfoFlasherBase>;
}

// File Line: 183
// RVA: 0x63AB30
void __fastcall UFG::InfoFlasherBase::show(UFG::InfoFlasherBase *this, Scaleform::GFx::Movie *movie)
{
  float v3; // xmm0_4
  __int64 v4; // xmm1_8
  char *mData; // rdi
  __int64 v6; // rsi
  __int64 v7; // rdx
  UFG::UIGfxTranslator *m_translator; // rcx
  char v9[16]; // [rsp+40h] [rbp-B8h] BYREF
  __int64 v10; // [rsp+50h] [rbp-A8h]
  int v11; // [rsp+58h] [rbp-A0h]
  __int64 v12; // [rsp+60h] [rbp-98h]
  __int64 v13; // [rsp+70h] [rbp-88h]
  __int64 v14[26]; // [rsp+78h] [rbp-80h] BYREF
  __int16 v15; // [rsp+14Ch] [rbp+54h]

  v13 = -2i64;
  if ( (this->mGFxMovie.Type & 0x8F) != 1 )
  {
    memset(&v14[12], 0, 112);
    LODWORD(v14[12]) = 1065353216;
    HIDWORD(v14[14]) = 1065353216;
    LODWORD(v14[17]) = 1065353216;
    LODWORD(v14[18]) = 1065353216;
    HIDWORD(v14[20]) = 1065353216;
    LODWORD(v14[23]) = 1065353216;
    HIDWORD(v14[25]) = 1065353216;
    v15 = 0;
    this->mGFxMovie.pObjectInterface->vfptr->GetDisplayInfo(
      this->mGFxMovie.pObjectInterface,
      (void *)this->mGFxMovie.mValue.pString,
      (Scaleform::GFx::Value::DisplayInfo *)v14);
    v3 = this->vfptr->getX(this);
    v15 |= 1u;
    *(double *)v14 = v3;
    *(double *)&v4 = this->vfptr->getY(this);
    v15 |= 2u;
    v14[1] = v4;
    this->mGFxMovie.pObjectInterface->vfptr->SetDisplayInfo(
      this->mGFxMovie.pObjectInterface,
      (void *)this->mGFxMovie.mValue.pString,
      (Scaleform::GFx::Value::DisplayInfo *)v14);
    mData = this->m_sHintTxt.mData;
    if ( mData )
    {
      if ( *mData == 36 )
        ++mData;
      v7 = (unsigned int)UFG::qStringHashUpper32(mData, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v6 = (__int64)m_translator->vfptr[5].__vecDelDtor(m_translator, v7)) == 0 )
        v6 = (__int64)mData;
    }
    else
    {
      v6 = 0i64;
    }
    v10 = 0i64;
    v11 = 6;
    v12 = v6;
    this->mGFxMovie.pObjectInterface->vfptr->Invoke(
      this->mGFxMovie.pObjectInterface,
      (void *)this->mGFxMovie.mValue.pString,
      0i64,
      "Show",
      (Scaleform::GFx::Value *)v9,
      1ui64,
      (this->mGFxMovie.Type & 0x8F) == 10);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC7346121, 0i64, 0, 0i64);
    this->m_eState = STATE_PHONE_CONTACTS;
    if ( (v11 & 0x40) != 0 )
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v10 + 16i64))(v10, v9, v12);
  }
}

// File Line: 276
// RVA: 0x5C3B80
void __fastcall UFG::InfoFlasherRaidInfo::InfoFlasherRaidInfo(
        UFG::InfoFlasherRaidInfo *this,
        const char *caption,
        float duration,
        const char *rival_name,
        const char *icon_path)
{
  UFG::InfoFlasherBase::InfoFlasherBase(this, caption, duration, 0, 3.0);
  this->vfptr = (UFG::InfoFlasherBaseVtbl *)&UFG::InfoFlasherRaidInfo::`vftable;
  UFG::qString::qString(&this->mRivalName, rival_name);
  UFG::qString::qString(&this->mIconPath, icon_path);
}

// File Line: 280
// RVA: 0x63AD60
void __fastcall UFG::InfoFlasherRaidInfo::show(UFG::InfoFlasherRaidInfo *this, Scaleform::GFx::Movie *movie)
{
  float v3; // xmm0_4
  __int64 v4; // xmm1_8
  char *mData; // rdi
  char *v6; // rdi
  char *v7; // rdi
  char ptr[16]; // [rsp+40h] [rbp-B8h] BYREF
  __int64 v9; // [rsp+50h] [rbp-A8h]
  int v10; // [rsp+58h] [rbp-A0h]
  char *v11; // [rsp+60h] [rbp-98h]
  char v12[8]; // [rsp+70h] [rbp-88h] BYREF
  __int64 v13; // [rsp+78h] [rbp-80h]
  int v14; // [rsp+80h] [rbp-78h]
  char *v15; // [rsp+88h] [rbp-70h]
  char v16[16]; // [rsp+98h] [rbp-60h] BYREF
  __int64 v17; // [rsp+A8h] [rbp-50h]
  int v18; // [rsp+B0h] [rbp-48h]
  char *v19; // [rsp+B8h] [rbp-40h]
  __int64 v20; // [rsp+C8h] [rbp-30h]
  __int64 v21[26]; // [rsp+D8h] [rbp-20h] BYREF
  __int16 v22; // [rsp+1ACh] [rbp+B4h]

  v20 = -2i64;
  if ( (this->mGFxMovie.Type & 0x8F) != 1 )
  {
    memset(&v21[12], 0, 112);
    LODWORD(v21[12]) = 1065353216;
    HIDWORD(v21[14]) = 1065353216;
    LODWORD(v21[17]) = 1065353216;
    LODWORD(v21[18]) = 1065353216;
    HIDWORD(v21[20]) = 1065353216;
    LODWORD(v21[23]) = 1065353216;
    HIDWORD(v21[25]) = 1065353216;
    v22 = 0;
    this->mGFxMovie.pObjectInterface->vfptr->GetDisplayInfo(
      this->mGFxMovie.pObjectInterface,
      (void *)this->mGFxMovie.mValue.pString,
      (Scaleform::GFx::Value::DisplayInfo *)v21);
    v3 = this->vfptr->getX(this);
    v22 |= 1u;
    *(double *)v21 = v3;
    *(double *)&v4 = this->vfptr->getY(this);
    v22 |= 2u;
    v21[1] = v4;
    this->mGFxMovie.pObjectInterface->vfptr->SetDisplayInfo(
      this->mGFxMovie.pObjectInterface,
      (void *)this->mGFxMovie.mValue.pString,
      (Scaleform::GFx::Value::DisplayInfo *)v21);
    `eh vector constructor iterator(ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mData = this->m_sHintTxt.mData;
    if ( (v10 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v9 + 16i64))(v9, ptr, v11);
      v9 = 0i64;
    }
    v10 = 6;
    v11 = mData;
    v6 = this->mRivalName.mData;
    if ( (v14 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v13 + 16i64))(v13, v12, v15);
      v13 = 0i64;
    }
    v14 = 6;
    v15 = v6;
    v7 = this->mIconPath.mData;
    if ( (v18 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v17 + 16i64))(v17, v16, v19);
      v17 = 0i64;
    }
    v18 = 6;
    v19 = v7;
    this->mGFxMovie.pObjectInterface->vfptr->Invoke(
      this->mGFxMovie.pObjectInterface,
      (void *)this->mGFxMovie.mValue.pString,
      0i64,
      "Show",
      (Scaleform::GFx::Value *)ptr,
      3ui64,
      (this->mGFxMovie.Type & 0x8F) == 10);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC7346121, 0i64, 0, 0i64);
    this->m_eState = STATE_PHONE_CONTACTS;
    `eh vector destructor iterator(ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

