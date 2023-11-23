// File Line: 58
// RVA: 0x5C7240
void __fastcall UFG::UIHKScreenSaveLoad::UIHKScreenSaveLoad(UFG::UIHKScreenSaveLoad *this)
{
  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = eDIM_INVALID;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSaveLoad::`vftable;
  this->mState = STATE_INIT;
  this->m_iSlotCount = 0;
  this->m_bHeadersLoaded = 0;
  this->mElapsedCount = 0.0;
  this->mPopupDialogScreenUID = -1;
  UFG::qMemSet(this->mSlotExists, 0, 8u);
}

// File Line: 66
// RVA: 0x5CC660
void __fastcall UFG::UIHKScreenSaveLoad::~UIHKScreenSaveLoad(UFG::UIHKScreenSaveLoad *this)
{
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v4; // eax
  UFG::UIScreenTextureManager *v5; // rax
  UFG::UIScreenTextureManager *v6; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSaveLoad::`vftable;
  v2 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v2 = &gGlobalOverlaySentinel;
  p_HelpBar = &v2->HelpBar;
  v4 = UFG::qStringHash32("UIHKScreenSaveLoad", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v4);
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v5, "SaveLoad");
  if ( UFG::UIHKScreenSaveLoad::m_bFromPauseMenu )
  {
    v6 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v6, "PauseMenu", 0i64);
  }
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 79
// RVA: 0x635BF0
void __fastcall UFG::UIHKScreenSaveLoad::init(UFG::UIHKScreenSaveLoad *this, UFG::UICommandData *data)
{
  UFG::UIScreenRenderable *mRenderable; // rbx
  Scaleform::GFx::Movie *pObject; // rbx
  bool v5; // si
  hkMemoryResourceContainer *v6; // rax
  double v7; // xmm6_8
  unsigned int v8; // esi
  hkMemoryResourceContainer *v9; // rax
  UFG::qString *v10; // rax
  UFG::qString *v11; // rbx
  UFG::qString *v12; // rax
  hkMemoryResourceContainer *v13; // rax
  Scaleform::GFx::Value v14; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::GFx::Value value; // [rsp+60h] [rbp-78h] BYREF
  Scaleform::GFx::Value v16; // [rsp+98h] [rbp-40h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+C8h] [rbp-10h] BYREF
  char v18[16]; // [rsp+F8h] [rbp+20h] BYREF
  __int64 v19; // [rsp+108h] [rbp+30h]
  int v20; // [rsp+110h] [rbp+38h]
  double v21; // [rsp+118h] [rbp+40h]
  __int64 v22; // [rsp+128h] [rbp+50h]
  UFG::qString v23; // [rsp+130h] [rbp+58h] BYREF
  UFG::qString v24; // [rsp+158h] [rbp+80h] BYREF
  UFG::qString *v25; // [rsp+1C8h] [rbp+F0h]
  UFG::qString *v26; // [rsp+1D8h] [rbp+100h]

  v22 = -2i64;
  UFG::UIScreen::init(this, data);
  this->mState = STATE_VOLUME;
  mRenderable = this->mRenderable;
  if ( mRenderable )
  {
    pObject = mRenderable->m_movie.pObject;
    if ( pObject )
    {
      *((_DWORD *)&value.Type + 1) = 0;
      value.pObjectInterface = 0i64;
      value.Type = VT_Undefined;
      v14.pObjectInterface = 0i64;
      v14.Type = VT_Undefined;
      value.mValue.IValue = 6;
      if ( UFG::UIHKScreenSaveLoad::mIsSave )
      {
        value.DataAux = (unsigned __int64)"$SAVELOAD_SAVE_GAME";
        value.Type = VT_Boolean;
        LOBYTE(v14.DataAux) = 1;
        v14.mValue.BValue = 0;
      }
      else
      {
        value.DataAux = (unsigned __int64)"$SAVELOAD_LOAD_GAME";
        value.Type = VT_Boolean;
        LOBYTE(v14.DataAux) = 0;
        v14.mValue.BValue = 1;
      }
      v14.Type = VT_Boolean;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_header.tf_header.text", (Scaleform::GFx::Value *)&value.8, 1i64);
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_cSave._visible", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_cLoad._visible", &v14, 1i64);
      v16.pObjectInterface = 0i64;
      v16.Type = VT_Boolean;
      v16.mValue.BValue = 0;
      Scaleform::GFx::Movie::SetVariable(pObject, "mcStorageButton._visible", &v16, 1i64);
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v5 = UFG::UIHKScreenSaveLoad::mIsSave;
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Boolean;
      ptr.mValue.BValue = v5;
      v6 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
      v7 = (double)(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v6)
                  - 1);
      if ( (v20 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v19 + 16i64))(
          v19,
          v18,
          COERCE_DOUBLE(*(_QWORD *)&v21));
        v19 = 0i64;
      }
      v20 = 5;
      v21 = v7;
      Scaleform::GFx::Movie::Invoke(pObject, "init", 0i64, &ptr, 2u);
      v8 = 0;
      v9 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
      if ( Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v9) )
      {
        v25 = &v23;
        v26 = &v24;
        do
        {
          UFG::qString::qString(&v23, "$COMMON_LOADING_UPPERCASE");
          v11 = v10;
          UFG::qString::qString(&v24, &customCaption);
          UFG::UIHKScreenSaveLoad::SetSlotText(this, v8++, v12, v11);
          v13 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
        }
        while ( v8 < Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v13) );
      }
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x688D286Au, 0i64, 0, 0i64);
      UFG::UIHKScreenSaveLoad::UpdateHelpbar(this);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      if ( (v16.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v16.pObjectInterface->vfptr->gap8[8])(
          v16.pObjectInterface,
          &v16,
          v16.mValue);
        v16.pObjectInterface = 0i64;
      }
      v16.Type = VT_Undefined;
      if ( (v14.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v14.pObjectInterface->vfptr->gap8[8])(
          v14.pObjectInterface,
          &v14,
          v14.mValue);
        v14.pObjectInterface = 0i64;
      }
      v14.Type = VT_Undefined;
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          v14.DataAux);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Undefined;
      if ( (value.mValue.BValue & 0x40) != 0 )
        (*(void (__fastcall **)(_QWORD, $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *, unsigned __int64))(**(_QWORD **)&value.Type
                                                                                              + 16i64))(
          *(_QWORD *)&value.Type,
          &value.8,
          value.DataAux);
    }
  }
}

// File Line: 148
// RVA: 0x63F950
void __fastcall UFG::UIHKScreenSaveLoad::update(UFG::UIHKScreenSaveLoad *this, float elapsed)
{
  AimConstraintMultiLink *v3; // rax
  int EffectorJoint; // eax
  UFG::GameSaveLoad *v5; // rax
  UFG::GameSaveLoad *v6; // rax
  UFG::GameSaveLoad *v7; // rax
  UFG::GameSaveLoad *v8; // rax

  if ( !UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, this->mPopupDialogScreenUID) )
    this->mPopupDialogScreenUID = -1;
  switch ( this->mState )
  {
    case STATE_VOLUME:
      v5 = UFG::GameSaveLoad::Instance();
      if ( !(unsigned int)UFG::GameSaveLoad::GetOperation(v5)
        || (v6 = UFG::GameSaveLoad::Instance(), (unsigned int)UFG::GameSaveLoad::GetOperation(v6) == 1) )
      {
        v7 = UFG::GameSaveLoad::Instance();
        if ( (unsigned int)UFG::GameSaveLoad::GetOperation(v7) != 1 )
        {
          v8 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::LoadAllHeaders(v8);
        }
        UFG::UIHKScreenSaveLoad::UpdateSlotText(this);
        this->mState = STATE_BRIGHTNESS;
      }
      break;
    case NUM_CALIBRATION_STATES:
      this->mElapsedCount = elapsed + this->mElapsedCount;
      break;
    case NUM_CALIBRATION_STATES|STATE_BRIGHTNESS:
      this->mElapsedCount = elapsed + this->mElapsedCount;
      v3 = (AimConstraintMultiLink *)UFG::GameSaveLoad::Instance();
      EffectorJoint = AimConstraintMultiLink::GetEffectorJoint(v3);
      if ( this->mElapsedCount > 2.0 && EffectorJoint != 1 )
      {
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mPopupDialogScreenUID);
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
        this->mState = 9;
      }
      break;
  }
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 198
// RVA: 0x5F0B00
void __fastcall UFG::UIHKScreenSaveLoad::LoadHeaders(UFG::UIHKScreenSaveLoad *this)
{
  UFG::GameSaveLoad *v2; // rax
  UFG::GameSaveLoad *v3; // rax

  v2 = UFG::GameSaveLoad::Instance();
  if ( (unsigned int)UFG::GameSaveLoad::GetOperation(v2) != 1 )
  {
    v3 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::LoadAllHeaders(v3);
  }
  UFG::UIHKScreenSaveLoad::UpdateSlotText(this);
}

// File Line: 301
// RVA: 0x608070
void __fastcall UFG::UIHKScreenSaveLoad::SetSlotText(
        UFG::UIHKScreenSaveLoad *this,
        int iSlotNum,
        UFG::qString *szSlotDate,
        UFG::qString *szSlotTitle)
{
  Scaleform::GFx::Movie *pObject; // r14
  char *mData; // rbx
  char *v9; // rbx
  Scaleform::GFx::Value ptr; // [rsp+8h] [rbp-69h] BYREF
  char v11[16]; // [rsp+38h] [rbp-39h] BYREF
  __int64 v12; // [rsp+48h] [rbp-29h]
  int v13; // [rsp+50h] [rbp-21h]
  char *v14; // [rsp+58h] [rbp-19h]
  char v15[16]; // [rsp+68h] [rbp-9h] BYREF
  __int64 v16; // [rsp+78h] [rbp+7h]
  int v17; // [rsp+80h] [rbp+Fh]
  char *v18; // [rsp+88h] [rbp+17h]
  __int64 v19; // [rsp+98h] [rbp+27h]

  v19 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  *(_QWORD *)&ptr.Type = Scaleform::GFx::Value::~Value;
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue.NValue = (double)iSlotNum;
  mData = szSlotDate->mData;
  if ( (v13 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v12 + 16i64))(v12, v11, v14);
    v12 = 0i64;
  }
  v13 = 6;
  v14 = mData;
  v9 = szSlotTitle->mData;
  if ( (v17 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
    v16 = 0i64;
  }
  v17 = 6;
  v18 = v9;
  Scaleform::GFx::Movie::Invoke(pObject, "SetSlot", 0i64, &ptr, 3u);
  Scaleform::GFx::Movie::Invoke(pObject, "SlotList.Refresh", 0i64, 0i64, 0);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(szSlotDate);
  UFG::qString::~qString(szSlotTitle);
}

// File Line: 317
// RVA: 0x61D190
void __fastcall UFG::UIHKScreenSaveLoad::UpdateSlotText(UFG::UIHKScreenSaveLoad *this)
{
  int v1; // ebx
  unsigned int v3; // ebp
  hkMemoryResourceContainer *v4; // rax
  __int64 v5; // rsi
  hkMemoryResourceContainer *v6; // rax
  hkMemoryResourceContainer *v7; // rax
  UFG::GameSaveLoad *v8; // rax
  hkMemoryResourceContainer *v9; // rax
  UFG::GameSaveLoad *v10; // rax

  v1 = 0;
  v3 = 0;
  this->m_bHeadersLoaded = 1;
  v4 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
  if ( Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v4) )
  {
    v5 = 0i64;
    do
    {
      v5 += 80i64;
      ++v3;
      this->m_bHeadersLoaded &= *(unsigned int *)((char *)&UFG::GameSaveLoad::Instance()->mFlowSettings.m_Postfix.mMagic
                                                + v5) > 1;
      v6 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
    }
    while ( v3 < Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v6) );
  }
  this->m_bHeadersLoaded &= UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[4].m_State > (unsigned int)SAVE_GAME_HEADER_STATE_LOADING;
  v7 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
  if ( Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v7) )
  {
    do
    {
      v8 = UFG::GameSaveLoad::Instance();
      UFG::UIHKScreenSaveLoad::UpdateSlotTextForHeader(this, v1, &v8->m_GameSlotHeaderInfo[v1]);
      ++v1;
      v9 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
    }
    while ( v1 < (unsigned int)Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v9) );
  }
  v10 = UFG::GameSaveLoad::Instance();
  UFG::UIHKScreenSaveLoad::UpdateSlotTextForHeader(this, 4, &v10->m_GameSlotHeaderInfo[4]);
}

// File Line: 344
// RVA: 0x61D280
void __fastcall UFG::UIHKScreenSaveLoad::UpdateSlotTextForHeader(
        UFG::UIHKScreenSaveLoad *this,
        int index,
        UFG::GameSaveLoad::tsSaveGameHeaderInfo *header)
{
  __int64 v4; // rsi
  UFG::qString *v6; // rax
  UFG::qString *v7; // rbx
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  UFG::qString *v10; // rax
  UFG::qString *DateString; // rax
  char *m_szLastMissionStringID; // rdx
  UFG::qString *v13; // rax
  UFG::qString *v14; // rbx
  UFG::qString *v15; // rax
  UFG::qString *v16; // rax
  UFG::qString *v17; // rax
  UFG::qString *v18; // rax
  UFG::qString text; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qString v20; // [rsp+58h] [rbp-90h] BYREF
  UFG::qString v21; // [rsp+98h] [rbp-50h] BYREF
  UFG::qString v22; // [rsp+C0h] [rbp-28h] BYREF
  UFG::qString v23; // [rsp+E8h] [rbp+0h] BYREF
  UFG::qString v24; // [rsp+110h] [rbp+28h] BYREF
  UFG::qString v25; // [rsp+138h] [rbp+50h] BYREF
  UFG::qString v26; // [rsp+160h] [rbp+78h] BYREF
  UFG::qString result; // [rsp+188h] [rbp+A0h] BYREF
  UFG::qString v28; // [rsp+1B0h] [rbp+C8h] BYREF
  UFG::qString v29; // [rsp+1D8h] [rbp+F0h] BYREF
  UFG::qString v30; // [rsp+200h] [rbp+118h] BYREF
  void *p_mData; // [rsp+248h] [rbp+160h]

  *(_QWORD *)&v20.mMagic = -2i64;
  v4 = index;
  if ( !this->m_bHeadersLoaded )
  {
    this->mSlotExists[index] = 0;
    if ( (header->m_State & 0xFFFFFFFD) != 0 )
    {
      p_mData = &v20;
      UFG::qString::qString(&v20, "$COMMON_LOADING_UPPERCASE");
      v7 = v6;
      UFG::qString::qString(&text, &customCaption);
    }
    else
    {
      p_mData = &v20.mData;
      UFG::qString::qString((UFG::qString *)&v20.mData, &customCaption);
      v7 = v9;
      UFG::qString::qString(&v21, &customCaption);
    }
    goto LABEL_16;
  }
  this->mSlotExists[index] = ((header->m_State - 3) & 0xFFFFFFFD) == 0;
  switch ( header->m_State )
  {
    case SAVE_GAME_HEADER_STATE_LOADING:
      p_mData = &v28;
      UFG::qString::qString(&v28, "$COMMON_LOADING_UPPERCASE");
      v7 = v18;
      UFG::qString::qString(&v30, &customCaption);
      goto LABEL_16;
    case SAVE_GAME_HEADER_STATE_CORRUPT:
      p_mData = &v24;
      UFG::qString::qString(&v24, &customCaption);
      v7 = v17;
      UFG::qString::qString(&v26, "$SAVELOAD_CORRUPTED_SLOT");
      goto LABEL_16;
    case SAVE_GAME_HEADER_STATE_EMPTY:
      p_mData = &v29;
      UFG::qString::qString(&v29, "$SAVELOAD_EMPTY_DATE");
      v7 = v16;
      UFG::qString::qString(&v23, "$SAVELOAD_EMPTY_DATE");
      goto LABEL_16;
  }
  if ( header->m_State != SAVE_GAME_HEADER_STATE_VALID )
  {
    p_mData = &v21;
    UFG::qString::qString(&v21, &customCaption);
    v7 = v10;
    UFG::qString::qString((UFG::qString *)&v20.mData, &customCaption);
LABEL_16:
    UFG::UIHKScreenSaveLoad::SetSlotText(this, v4, v8, v7);
    return;
  }
  UFG::qString::qString(&v20);
  UFG::qString::qString(&text);
  DateString = UFG::UI::GetDateString(&result, header->m_iTimeDateStamp, 1);
  UFG::qString::Set(&v20, DateString->mData, DateString->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  m_szLastMissionStringID = (char *)UFG::UI::LocalizeText(header->m_szLastMissionStringID);
  if ( !m_szLastMissionStringID )
    m_szLastMissionStringID = header->m_szLastMissionStringID;
  UFG::qString::Set(&text, m_szLastMissionStringID);
  this->mSlotExists[v4] = 1;
  p_mData = &v22;
  UFG::qString::qString(&v22, &text);
  v14 = v13;
  UFG::qString::qString(&v25, &v20);
  UFG::UIHKScreenSaveLoad::SetSlotText(this, v4, v15, v14);
  UFG::qString::~qString(&text);
  UFG::qString::~qString(&v20);
}

// File Line: 437
// RVA: 0x62AB10
bool __fastcall UFG::UIHKScreenSaveLoad::handleMessage(
        UFG::UIHKScreenSaveLoad *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // rbx
  unsigned int mScreenUID; // r8d
  UFG::UI *v9; // rcx
  UFG::GameSaveLoad *v10; // rax
  UFG::GameSaveLoad *v11; // rax
  int NValue; // ebx
  const char *v13; // r8
  UFG::UIHKScreenSaveLoad *v14; // rcx
  UFG::UIScreen *Overlay; // rax
  UFG::UIHKScreenGlobalOverlay *v16; // rcx
  const char *v17; // rdx
  __int32 v18; // ebx
  UFG::GameSaveLoad *v19; // rax
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-38h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return 0;
  if ( msgId == -1577309891 || msgId == 2134650328 || msgId == -339696135 )
    UFG::UIHKScreenSaveLoad::UpdateSlotText(this);
  switch ( this->mState )
  {
    case 1:
      if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
        || msgId == UI_HASH_DPAD_DOWN_REPEAT_30
        || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
      {
        if ( !this->m_bHeadersLoaded )
          return 1;
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
        v17 = "ScrollDown";
        goto LABEL_84;
      }
      if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
        || msgId == UI_HASH_DPAD_UP_REPEAT_30
        || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
      {
        if ( !this->m_bHeadersLoaded )
          return 1;
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
        v17 = "ScrollUp";
LABEL_84:
        Scaleform::GFx::Movie::Invoke(pObject, v17, 0i64, 0i64, 0);
        UFG::UIHKScreenSaveLoad::UpdateHelpbar(this);
        return 1;
      }
      if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
      {
        if ( this->m_bHeadersLoaded )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
          UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
          this->mState = 9;
        }
        return 1;
      }
      if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( !this->m_bHeadersLoaded )
          return 1;
        if ( UFG::UIHKScreenSaveLoad::mIsSave )
        {
          if ( (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 2) == 0 )
            return 1;
          v10 = UFG::GameSaveLoad::Instance();
          if ( !UFG::GameSaveLoad::IsSaveAvaliable(v10) )
            return 1;
          if ( UFG::UIHKScreenSaveLoad::mIsSave )
          {
LABEL_39:
            pval.pObjectInterface = 0i64;
            pval.Type = VT_Undefined;
            Scaleform::GFx::Movie::GetVariable(pObject, &pval, "SlotIndex");
            NValue = (int)pval.mValue.NValue;
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
            if ( UFG::UIHKScreenSaveLoad::mIsSave )
            {
              if ( NValue != 4 )
              {
                if ( UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[NValue].m_State == SAVE_GAME_HEADER_STATE_CORRUPT )
                {
                  v13 = "$SAVELOAD_TRC_OVERWRITE_CORRUPT_SAVE_FILE";
LABEL_53:
                  v14 = this;
                  goto LABEL_54;
                }
                v14 = this;
                if ( this->mSlotExists[NValue] )
                {
                  v13 = "$COMMON_TRC_OVERWRITE_SAVE_FILE";
LABEL_54:
                  UFG::UIScreenDialogBox::createYesNoDialog(v14, &customCaption, v13, 0, 1);
                  this->mState = STATE_UISCALE;
                  goto LABEL_55;
                }
                goto LABEL_50;
              }
            }
            else if ( this->mSlotExists[NValue] )
            {
              if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateFE_13 )
              {
                v13 = "$COMMON_TRC_LOAD_SAVE_FILE";
                goto LABEL_53;
              }
              v14 = this;
LABEL_50:
              if ( UFG::UIHKScreenSaveLoad::StartSaveLoad(v14) )
                UFG::UIHKScreenSaveLoad::ShowPopup(this);
            }
LABEL_55:
            if ( (pval.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
                pval.pObjectInterface,
                &pval,
                pval.mValue);
              pval.pObjectInterface = 0i64;
            }
            pval.Type = VT_Undefined;
            return 1;
          }
        }
        else if ( (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) == 0 )
        {
          return 1;
        }
        v11 = UFG::GameSaveLoad::Instance();
        if ( !UFG::GameSaveLoad::IsLoadAvaliable(v11) )
          return 1;
        goto LABEL_39;
      }
      if ( msgId == UI_HASH_SAVE_UNAVAILABLE_9 )
      {
        this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
      }
      else if ( msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
      {
        pval.pObjectInterface = 0i64;
        pval.Type = VT_Undefined;
        Scaleform::GFx::Movie::GetVariable(this->mRenderable->m_movie.pObject, &pval, "SlotIndex");
        if ( this->mSlotExists[(int)pval.mValue.NValue] )
        {
          UFG::UIScreenDialogBox::createYesNoDialog(this, &customCaption, "$COMMON_TRC_DELETE_SAVE_FILE", 0, 1);
          this->mState = NUM_CALIBRATION_STATES|STATE_UISCALE;
        }
        else if ( UFG::HudAudio::m_instance )
        {
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
        }
        if ( (pval.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
            pval.pObjectInterface,
            &pval,
            pval.mValue);
          pval.pObjectInterface = 0i64;
        }
        pval.Type = VT_Undefined;
      }
      Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "GlobalOverlay");
      if ( Overlay )
      {
        v16 = UFG::UIHKScreenGlobalOverlay::mThis;
        if ( !UFG::UIHKScreenGlobalOverlay::mThis )
          v16 = &gGlobalOverlaySentinel;
        UFG::UIHKHelpBarWidget::HandleMessage(&v16->HelpBar, Overlay, msgId, msg);
      }
      if ( msgId == UI_HASH_MOUSE_MOVE_30 )
      {
        UFG::UIHKScreenUpgrades::Flash_HandleMouseMove(
          (UFG::UIHKScreenUpgrades *)this,
          (float)SLODWORD(msg[1].vfptr),
          (float)SHIDWORD(msg[1].vfptr));
      }
      else if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
      {
        UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
          (UFG::UIHKScreenUpgrades *)this,
          (float)SLODWORD(msg[1].vfptr),
          (float)SHIDWORD(msg[1].vfptr));
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case 3:
      if ( msgId == UI_HASH_DIALOG_NO_30 )
      {
        this->mState = STATE_BRIGHTNESS;
        return 1;
      }
      if ( msgId != UI_HASH_DIALOG_YES_30 )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      if ( UFG::UIHKScreenSaveLoad::StartSaveLoad(this) )
        UFG::UIHKScreenSaveLoad::ShowPopup(this);
      return 1;
    case 4:
      if ( msgId == 1552074461 || msgId == -663456200 )
      {
        if ( UFG::UIHKScreenSaveLoad::mOwner )
        {
          mScreenUID = UFG::UIHKScreenSaveLoad::mOwner->mScreenUID;
          if ( UFG::UIHKScreenSaveLoad::mIsSave )
          {
            UFG::UIScreenManagerBase::queueMessage(
              UFG::UIScreenManager::s_instance,
              UI_HASH_SAVE_COMPLETE_20,
              mScreenUID);
          }
          else
          {
            UFG::UIScreenManagerBase::queueMessage(
              UFG::UIScreenManager::s_instance,
              UI_HASH_LOAD_COMPLETE_20,
              mScreenUID);
            UFG::UI::HandleGameCheckpointRestore(v9);
          }
          this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
        }
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      if ( msgId != 1323471633 && msgId != 2006712458 )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mPopupDialogScreenUID);
      UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
      return 1;
    case 6:
      if ( msgId == UI_HASH_DIALOG_OK_30 )
      {
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
        this->mState = 9;
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case 7:
      if ( msgId == UI_HASH_DIALOG_YES_30 )
      {
        pval.pObjectInterface = 0i64;
        pval.Type = VT_Undefined;
        Scaleform::GFx::Movie::GetVariable(this->mRenderable->m_movie.pObject, &pval, "SlotIndex");
        v18 = (int)pval.mValue.NValue;
        v19 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::DeleteGameData(v19, v18);
        this->mState = 8;
        this->mPopupDialogScreenUID = UFG::UIScreenDialogBox::createZeroButtonDialog(
                                        this,
                                        &customCaption,
                                        "$DELETING_SAVE_DATA",
                                        0,
                                        "DialogBox");
        if ( (pval.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
            pval.pObjectInterface,
            &pval,
            pval.mValue);
          pval.pObjectInterface = 0i64;
        }
        pval.Type = VT_Undefined;
      }
      else if ( msgId == UI_HASH_DIALOG_NO_30 )
      {
        this->mState = STATE_BRIGHTNESS;
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case 8:
      if ( msgId == UI_HASH_DELETE_GAME_COMPLETE_20 )
      {
        this->m_bHeadersLoaded = 0;
        this->mState = STATE_BRIGHTNESS;
        UFG::UIHKScreenSaveLoad::LoadHeaders(this);
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mPopupDialogScreenUID);
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    default:
      return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
}

// File Line: 801
// RVA: 0x6122F0
char __fastcall UFG::UIHKScreenSaveLoad::StartSaveLoad(UFG::UIHKScreenSaveLoad *this)
{
  __int32 NValue; // ebx
  UFG::GameSaveLoad *v3; // rax
  char GameSlot; // bl
  UFG::GameSaveLoad *v5; // rax
  unsigned int v6; // eax
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  if ( UFG::UIHKScreenSaveLoad::mIsSave )
  {
    if ( (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 2) == 0 )
      return 0;
  }
  else if ( (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) == 0 )
  {
    return 0;
  }
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(this->mRenderable->m_movie.pObject, &pval, "SlotIndex");
  NValue = (int)pval.mValue.NValue;
  if ( UFG::UIHKScreenSaveLoad::mIsSave )
  {
    v3 = UFG::GameSaveLoad::Instance();
    GameSlot = UFG::GameSaveLoad::SaveGameSlot(v3, NValue);
  }
  else
  {
    v5 = UFG::GameSaveLoad::Instance();
    GameSlot = UFG::GameSaveLoad::LoadGameSlot(v5, (UFG::GameSaveLoad::eGameSlotNum)NValue);
    UFG::AudioEventPropertyManager::Reset();
    v6 = _S13_7;
    if ( (_S13_7 & 1) == 0 )
    {
      _S13_7 |= 1u;
      stop_amb_sirens_approaching = UFG::TiDo::CalcWwiseUid("stop_amb_sirens_approaching");
      v6 = _S13_7;
    }
    if ( (v6 & 2) == 0 )
    {
      _S13_7 = v6 | 2;
      stop_siren_approaching = UFG::TiDo::CalcWwiseUid("stop_siren_approaching");
      v6 = _S13_7;
    }
    if ( (v6 & 4) == 0 )
    {
      _S13_7 = v6 | 4;
      stop_siren_approaching_quiet = UFG::TiDo::CalcWwiseUid("stop_siren_approaching_quiet");
    }
    UFG::TiDo::GetInstance();
    UFG::TiDo::PostGlobalEvent(stop_amb_sirens_approaching);
    UFG::TiDo::GetInstance();
    UFG::TiDo::PostGlobalEvent(stop_siren_approaching);
    UFG::TiDo::GetInstance();
    UFG::TiDo::PostGlobalEvent(stop_siren_approaching_quiet);
  }
  if ( GameSlot )
    this->mState = NUM_CALIBRATION_STATES;
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  pval.Type = VT_Undefined;
  return GameSlot;
}

// File Line: 851
// RVA: 0x610EC0
void __fastcall UFG::UIHKScreenSaveLoad::ShowPopup(UFG::UIHKScreenSaveLoad *this)
{
  bool v2; // r9
  const char *v3; // r8
  unsigned int ZeroButtonDialog; // eax

  if ( UFG::UIHKScreenSaveLoad::mIsSave )
  {
    v2 = 0;
    v3 = "$SAVING_POPUP_PC";
  }
  else
  {
    v2 = UFG::UIHKScreenSaveLoad::m_bFromPauseMenu;
    v3 = "$LOADING_POPUP";
  }
  ZeroButtonDialog = UFG::UIScreenDialogBox::createZeroButtonDialog(this, &customCaption, v3, v2, "DialogBox");
  this->mElapsedCount = 0.0;
  this->mPopupDialogScreenUID = ZeroButtonDialog;
}

// File Line: 872
// RVA: 0x639BB0
void __fastcall UFG::UIHKScreenSaveLoad::queueSaveLoadCommand(UFG::UIScreen *pOwner, bool bSave, bool bFromPauseMenu)
{
  UFG::UIScreenTextureManager *v6; // rax

  if ( !UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SaveLoad") )
  {
    UFG::UIHKScreenSaveLoad::mOwner = pOwner;
    UFG::UIHKScreenSaveLoad::mIsSave = bSave;
    UFG::UIHKScreenSaveLoad::m_bFromPauseMenu = bFromPauseMenu;
    v6 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v6, "SaveLoad", 0i64);
  }
}

// File Line: 886
// RVA: 0x61A930
void __fastcall UFG::UIHKScreenSaveLoad::UpdateHelpbar(UFG::UIHKScreenSaveLoad *this)
{
  Scaleform::GFx::Movie *MovieSafe; // rax
  int NValue; // ebx
  unsigned int v3; // esi
  int v4; // ecx
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rbx
  unsigned int v8; // esi
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rbx
  unsigned int v13; // esi
  int v14; // ecx
  __int64 v15; // rax
  __int64 v16; // rdi
  __int64 v17; // rbx
  UFG::UIHKScreenGlobalOverlay *v18; // rbx
  UFG::UIHKScreenGlobalOverlay *v19; // rax
  Scaleform::GFx::Value pval; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v21; // [rsp+50h] [rbp-B0h]
  UFG::UIHKHelpBarData data; // [rsp+60h] [rbp-A0h] BYREF

  v21 = -2i64;
  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  if ( MovieSafe )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(MovieSafe, &pval, "SlotIndex");
    NValue = (int)pval.mValue.NValue;
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = UFG::qStringHash32("UIHKScreenSaveLoad", 0xFFFFFFFF);
    data.alignment = ALIGN_LEFT;
    if ( !UFG::UIHKScreenSaveLoad::mIsSave || NValue != 4 )
    {
      v3 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
      v4 = 0;
      v5 = 0i64;
      while ( data.Buttons[v5] )
      {
        ++v4;
        if ( ++v5 >= 6 )
          goto LABEL_9;
      }
      v6 = v4;
      data.Buttons[v4] = ACCEPT_BUTTON;
      v7 = v4;
      UFG::qString::Set(&data.Captions[v4], "$COMMON_ACCEPT_UPPERCASE");
      UFG::qString::Set(&data.Icons[v7], &customCaption);
      data.MessageIds[v6] = v3;
    }
LABEL_9:
    v8 = UI_HASH_BUTTON_BACK_PRESSED_30;
    v9 = 0;
    v10 = 0i64;
    while ( data.Buttons[v10] )
    {
      ++v9;
      if ( ++v10 >= 6 )
        goto LABEL_14;
    }
    v11 = v9;
    data.Buttons[v9] = BACK_BUTTON;
    v12 = v9;
    UFG::qString::Set(&data.Captions[v9], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set(&data.Icons[v12], &customCaption);
    data.MessageIds[v11] = v8;
LABEL_14:
    v13 = UI_HASH_BUTTON_BUTTON1_PRESSED_30;
    v14 = 0;
    v15 = 0i64;
    while ( data.Buttons[v15] )
    {
      ++v14;
      if ( ++v15 >= 6 )
        goto LABEL_19;
    }
    v16 = v14;
    data.Buttons[v14] = BUTTON1_BUTTON;
    v17 = v14;
    UFG::qString::Set(&data.Captions[v14], "$SAVELOAD_DELETE_GAME");
    UFG::qString::Set(&data.Icons[v17], &customCaption);
    data.MessageIds[v16] = v13;
LABEL_19:
    v18 = &gGlobalOverlaySentinel;
    v19 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v19 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::Show(&v19->HelpBar, &data);
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
      v18 = UFG::UIHKScreenGlobalOverlay::mThis;
    v18->HelpBar.mChanged |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v18->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
    v18->HelpBar.mYOffset = -20.0;
    UFG::qString::~qString(&data.CustomTexturePack);
    `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    if ( (pval.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
  }
}

