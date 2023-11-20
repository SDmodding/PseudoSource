// File Line: 58
// RVA: 0x5C7240
void __fastcall UFG::UIHKScreenSaveLoad::UIHKScreenSaveLoad(UFG::UIHKScreenSaveLoad *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable';
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = 0;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSaveLoad::`vftable';
  this->mState = 0;
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
  UFG::UIHKScreenSaveLoad *v1; // rbx
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIHKHelpBarWidget *v3; // rdi
  unsigned int v4; // eax
  UFG::UIScreenTextureManager *v5; // rax
  UFG::UIScreenTextureManager *v6; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSaveLoad::`vftable';
  v2 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v2 = &gGlobalOverlaySentinel;
  v3 = &v2->HelpBar;
  v4 = UFG::qStringHash32("UIHKScreenSaveLoad", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v3, v4);
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v5, "SaveLoad");
  if ( UFG::UIHKScreenSaveLoad::m_bFromPauseMenu )
  {
    v6 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v6, "PauseMenu", 0i64);
  }
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 79
// RVA: 0x635BF0
void __fastcall UFG::UIHKScreenSaveLoad::init(UFG::UIHKScreenSaveLoad *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenSaveLoad *v2; // rdi
  UFG::UIScreenRenderable *v3; // rbx
  Scaleform::GFx::Movie *v4; // rbx
  bool v5; // si
  hkMemoryResourceContainer *v6; // rax
  double v7; // xmm6_8
  unsigned int v8; // esi
  hkMemoryResourceContainer *v9; // rax
  UFG::qString *v10; // rax
  UFG::qString *v11; // rbx
  UFG::qString *v12; // rax
  hkMemoryResourceContainer *v13; // rax
  Scaleform::GFx::Value v14; // [rsp+30h] [rbp-A8h]
  Scaleform::GFx::Value value; // [rsp+60h] [rbp-78h]
  Scaleform::GFx::Value v16; // [rsp+98h] [rbp-40h]
  char ptr; // [rsp+C8h] [rbp-10h]
  __int64 v18; // [rsp+D8h] [rbp+0h]
  unsigned int v19; // [rsp+E0h] [rbp+8h]
  __int64 v20; // [rsp+E8h] [rbp+10h]
  char v21; // [rsp+F8h] [rbp+20h]
  __int64 v22; // [rsp+108h] [rbp+30h]
  unsigned int v23; // [rsp+110h] [rbp+38h]
  double v24; // [rsp+118h] [rbp+40h]
  __int64 v25; // [rsp+128h] [rbp+50h]
  UFG::qString v26; // [rsp+130h] [rbp+58h]
  UFG::qString v27; // [rsp+158h] [rbp+80h]
  UFG::qString *v28; // [rsp+1C8h] [rbp+F0h]
  UFG::qString *v29; // [rsp+1D8h] [rbp+100h]

  v25 = -2i64;
  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v2->mState = 2;
  v3 = v2->mRenderable;
  if ( v3 )
  {
    v4 = v3->m_movie.pObject;
    if ( v4 )
    {
      *(_QWORD *)&value.Type = 0i64;
      value.mValue.IValue = 0;
      value.pObjectInterface = 0i64;
      value.Type = 0;
      v14.pObjectInterface = 0i64;
      v14.Type = 0;
      if ( UFG::UIHKScreenSaveLoad::mIsSave )
      {
        value.mValue.IValue = 6;
        value.DataAux = (unsigned __int64)"$SAVELOAD_SAVE_GAME";
        if ( ((unsigned int)value.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            v14.DataAux);
          value.pObjectInterface = 0i64;
        }
        value.Type = 2;
        LOBYTE(v14.DataAux) = 1;
        if ( ((unsigned int)v14.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v14.pObjectInterface->vfptr->gap8[8])(
            v14.pObjectInterface,
            &v14,
            *(_QWORD *)&v14.mValue.NValue);
          v14.pObjectInterface = 0i64;
        }
        v14.mValue.BValue = 0;
      }
      else
      {
        value.mValue.IValue = 6;
        value.DataAux = (unsigned __int64)"$SAVELOAD_LOAD_GAME";
        if ( ((unsigned int)value.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            v14.DataAux);
          value.pObjectInterface = 0i64;
        }
        value.Type = 2;
        LOBYTE(v14.DataAux) = 0;
        if ( ((unsigned int)v14.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v14.pObjectInterface->vfptr->gap8[8])(
            v14.pObjectInterface,
            &v14,
            *(_QWORD *)&v14.mValue.NValue);
          v14.pObjectInterface = 0i64;
        }
        v14.mValue.BValue = 1;
      }
      v14.Type = 2;
      Scaleform::GFx::Movie::SetVariable(
        v4,
        "mc_header.tf_header.text",
        (Scaleform::GFx::Value *)((char *)&value + 8),
        1i64);
      Scaleform::GFx::Movie::SetVariable(v4, "mc_cSave._visible", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(v4, "mc_cLoad._visible", &v14, 1i64);
      v16.pObjectInterface = 0i64;
      v16.Type = 2;
      v16.mValue.BValue = 0;
      Scaleform::GFx::Movie::SetVariable(v4, "mcStorageButton._visible", &v16, 1i64);
      `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v5 = UFG::UIHKScreenSaveLoad::mIsSave;
      if ( (v19 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v18 + 16i64))(v18, &ptr, v20);
        v18 = 0i64;
      }
      v19 = 2;
      LOBYTE(v20) = v5;
      v6 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
      v7 = (double)(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v6)
                  - 1);
      if ( (v23 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v22 + 16i64))(
          v22,
          &v21,
          COERCE_DOUBLE(*(_QWORD *)&v24));
        v22 = 0i64;
      }
      v23 = 5;
      v24 = v7;
      Scaleform::GFx::Movie::Invoke(v4, "init", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
      v8 = 0;
      v9 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
      if ( Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v9) )
      {
        v28 = &v26;
        v29 = &v27;
        do
        {
          UFG::qString::qString(&v26, "$COMMON_LOADING_UPPERCASE");
          v11 = v10;
          UFG::qString::qString(&v27, &customWorldMapCaption);
          UFG::UIHKScreenSaveLoad::SetSlotText(v2, v8++, v12, v11);
          v13 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
        }
        while ( v8 < Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v13) );
      }
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x688D286Au,
          0i64,
          0,
          0i64);
      UFG::UIHKScreenSaveLoad::UpdateHelpbar(v2);
      `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      if ( ((unsigned int)v16.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v16.pObjectInterface->vfptr->gap8[8])(
          v16.pObjectInterface,
          &v16,
          *(_QWORD *)&v16.mValue.NValue);
        v16.pObjectInterface = 0i64;
      }
      v16.Type = 0;
      if ( ((unsigned int)v14.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v14.pObjectInterface->vfptr->gap8[8])(
          v14.pObjectInterface,
          &v14,
          *(_QWORD *)&v14.mValue.NValue);
        v14.pObjectInterface = 0i64;
      }
      v14.Type = 0;
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          v14.DataAux);
        value.pObjectInterface = 0i64;
      }
      value.Type = 0;
      if ( ((unsigned int)value.mValue.IValue >> 6) & 1 )
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
  UFG::UIHKScreenSaveLoad *v2; // rbx
  AimConstraintMultiLink *v3; // rax
  int v4; // eax
  UFG::GameSaveLoad *v5; // rax
  UFG::GameSaveLoad *v6; // rax
  UFG::GameSaveLoad *v7; // rax
  UFG::GameSaveLoad *v8; // rax

  v2 = this;
  if ( !UFG::UIScreenManagerBase::getScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          this->mPopupDialogScreenUID) )
    v2->mPopupDialogScreenUID = -1;
  switch ( v2->mState )
  {
    case 2:
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
        UFG::UIHKScreenSaveLoad::UpdateSlotText(v2);
        v2->mState = 1;
      }
      break;
    case 4:
      v2->mElapsedCount = elapsed + v2->mElapsedCount;
      break;
    case 5:
      v2->mElapsedCount = elapsed + v2->mElapsedCount;
      v3 = (AimConstraintMultiLink *)UFG::GameSaveLoad::Instance();
      v4 = AimConstraintMultiLink::GetEffectorJoint(v3);
      if ( v2->mElapsedCount > 2.0 && v4 != 1 )
      {
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v2->mPopupDialogScreenUID);
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v2->mScreenUID);
        v2->mState = 9;
      }
      break;
  }
  UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
}

// File Line: 198
// RVA: 0x5F0B00
void __fastcall UFG::UIHKScreenSaveLoad::LoadHeaders(UFG::UIHKScreenSaveLoad *this)
{
  UFG::UIHKScreenSaveLoad *v1; // rbx
  UFG::GameSaveLoad *v2; // rax
  UFG::GameSaveLoad *v3; // rax

  v1 = this;
  v2 = UFG::GameSaveLoad::Instance();
  if ( (unsigned int)UFG::GameSaveLoad::GetOperation(v2) != 1 )
  {
    v3 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::LoadAllHeaders(v3);
  }
  UFG::UIHKScreenSaveLoad::UpdateSlotText(v1);
}

// File Line: 301
// RVA: 0x608070
void __fastcall UFG::UIHKScreenSaveLoad::SetSlotText(UFG::UIHKScreenSaveLoad *this, int iSlotNum, UFG::qString *szSlotDate, UFG::qString *szSlotTitle)
{
  UFG::qString *v4; // rdi
  UFG::qString *v5; // rsi
  int v6; // ebx
  Scaleform::GFx::Movie *v7; // r14
  __int64 v8; // rbx
  __int64 v9; // rbx
  char ptr; // [rsp+8h] [rbp-69h]
  __int64 v11; // [rsp+18h] [rbp-59h]
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-51h]
  double v13; // [rsp+28h] [rbp-49h]
  char v14; // [rsp+38h] [rbp-39h]
  __int64 v15; // [rsp+48h] [rbp-29h]
  unsigned int v16; // [rsp+50h] [rbp-21h]
  __int64 v17; // [rsp+58h] [rbp-19h]
  char v18; // [rsp+68h] [rbp-9h]
  __int64 v19; // [rsp+78h] [rbp+7h]
  unsigned int v20; // [rsp+80h] [rbp+Fh]
  __int64 v21; // [rsp+88h] [rbp+17h]
  __int64 v22; // [rsp+98h] [rbp+27h]

  v22 = -2i64;
  v4 = szSlotTitle;
  v5 = szSlotDate;
  v6 = iSlotNum;
  v7 = this->mRenderable->m_movie.pObject;
  pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
  `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( ((unsigned int)pDtor >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
      v11,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v13));
    v11 = 0i64;
  }
  LODWORD(pDtor) = 5;
  v13 = (double)v6;
  v8 = (__int64)v5->mData;
  if ( (v16 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
    v15 = 0i64;
  }
  v16 = 6;
  v17 = v8;
  v9 = (__int64)v4->mData;
  if ( (v20 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
    v19 = 0i64;
  }
  v20 = 6;
  v21 = v9;
  Scaleform::GFx::Movie::Invoke(v7, "SetSlot", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  Scaleform::GFx::Movie::Invoke(v7, "SlotList.Refresh", 0i64, 0i64, 0);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(v5);
  UFG::qString::~qString(v4);
}

// File Line: 317
// RVA: 0x61D190
void __fastcall UFG::UIHKScreenSaveLoad::UpdateSlotText(UFG::UIHKScreenSaveLoad *this)
{
  int v1; // ebx
  UFG::UIHKScreenSaveLoad *v2; // rdi
  unsigned int v3; // ebp
  hkMemoryResourceContainer *v4; // rax
  __int64 v5; // rsi
  hkMemoryResourceContainer *v6; // rax
  hkMemoryResourceContainer *v7; // rax
  UFG::GameSaveLoad *v8; // rax
  hkMemoryResourceContainer *v9; // rax
  UFG::GameSaveLoad *v10; // rax

  v1 = 0;
  v2 = this;
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
      v2->m_bHeadersLoaded &= *(unsigned int *)((char *)&UFG::GameSaveLoad::Instance()->mFlowSettings.m_Postfix.mMagic
                                              + v5) > 1;
      v6 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
    }
    while ( v3 < Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v6) );
  }
  v2->m_bHeadersLoaded &= UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[4].m_State > 1u;
  v7 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
  if ( Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v7) )
  {
    do
    {
      v8 = UFG::GameSaveLoad::Instance();
      UFG::UIHKScreenSaveLoad::UpdateSlotTextForHeader(v2, v1, &v8->m_GameSlotHeaderInfo[v1]);
      ++v1;
      v9 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
    }
    while ( v1 < (unsigned int)Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v9) );
  }
  v10 = UFG::GameSaveLoad::Instance();
  UFG::UIHKScreenSaveLoad::UpdateSlotTextForHeader(v2, 4, &v10->m_GameSlotHeaderInfo[4]);
}

// File Line: 344
// RVA: 0x61D280
void __fastcall UFG::UIHKScreenSaveLoad::UpdateSlotTextForHeader(UFG::UIHKScreenSaveLoad *this, int index, UFG::GameSaveLoad::tsSaveGameHeaderInfo *header)
{
  UFG::GameSaveLoad::tsSaveGameHeaderInfo *v3; // rbx
  __int64 v4; // rsi
  UFG::UIHKScreenSaveLoad *v5; // rdi
  UFG::qString *v6; // rax
  UFG::qString *v7; // rbx
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  UFG::qString *v10; // rax
  UFG::qString *v11; // rax
  const char *v12; // rdx
  UFG::qString *v13; // rax
  UFG::qString *v14; // rbx
  UFG::qString *v15; // rax
  UFG::qString *v16; // rax
  UFG::qString *v17; // rax
  UFG::qString *v18; // rax
  UFG::qString text; // [rsp+30h] [rbp-B8h]
  UFG::qString v20; // [rsp+58h] [rbp-90h]
  UFG::qString v21; // [rsp+98h] [rbp-50h]
  UFG::qString v22; // [rsp+C0h] [rbp-28h]
  UFG::qString v23; // [rsp+E8h] [rbp+0h]
  UFG::qString v24; // [rsp+110h] [rbp+28h]
  UFG::qString v25; // [rsp+138h] [rbp+50h]
  UFG::qString v26; // [rsp+160h] [rbp+78h]
  UFG::qString result; // [rsp+188h] [rbp+A0h]
  UFG::qString v28; // [rsp+1B0h] [rbp+C8h]
  UFG::qString v29; // [rsp+1D8h] [rbp+F0h]
  UFG::qString v30; // [rsp+200h] [rbp+118h]
  void *v31; // [rsp+248h] [rbp+160h]

  *(_QWORD *)&v20.mMagic = -2i64;
  v3 = header;
  v4 = index;
  v5 = this;
  if ( !this->m_bHeadersLoaded )
  {
    this->mSlotExists[index] = 0;
    if ( header->m_State & 0xFFFFFFFD )
    {
      v31 = &v20;
      UFG::qString::qString(&v20, "$COMMON_LOADING_UPPERCASE");
      v7 = v6;
      UFG::qString::qString(&text, &customWorldMapCaption);
    }
    else
    {
      v31 = &v20.mData;
      UFG::qString::qString((UFG::qString *)((char *)&v20 + 24), &customWorldMapCaption);
      v7 = v9;
      UFG::qString::qString(&v21, &customWorldMapCaption);
    }
    goto LABEL_16;
  }
  this->mSlotExists[index] = ((header->m_State - 3) & 0xFFFFFFFD) == 0;
  switch ( header->m_State )
  {
    case 1:
      v31 = &v28;
      UFG::qString::qString(&v28, "$COMMON_LOADING_UPPERCASE");
      v7 = v18;
      UFG::qString::qString(&v30, &customWorldMapCaption);
      goto LABEL_16;
    case 3:
      v31 = &v24;
      UFG::qString::qString(&v24, &customWorldMapCaption);
      v7 = v17;
      UFG::qString::qString(&v26, "$SAVELOAD_CORRUPTED_SLOT");
      goto LABEL_16;
    case 4:
      v31 = &v29;
      UFG::qString::qString(&v29, "$SAVELOAD_EMPTY_DATE");
      v7 = v16;
      UFG::qString::qString(&v23, "$SAVELOAD_EMPTY_DATE");
      goto LABEL_16;
  }
  if ( header->m_State != 5 )
  {
    v31 = &v21;
    UFG::qString::qString(&v21, &customWorldMapCaption);
    v7 = v10;
    UFG::qString::qString((UFG::qString *)((char *)&v20 + 24), &customWorldMapCaption);
LABEL_16:
    UFG::UIHKScreenSaveLoad::SetSlotText(v5, v4, v8, v7);
    return;
  }
  UFG::qString::qString(&v20);
  UFG::qString::qString(&text);
  v11 = UFG::UI::GetDateString(&result, v3->m_iTimeDateStamp, 1);
  UFG::qString::Set(&v20, v11->mData, v11->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  v12 = UFG::UI::LocalizeText(v3->m_szLastMissionStringID);
  if ( !v12 )
    v12 = v3->m_szLastMissionStringID;
  UFG::qString::Set(&text, v12);
  v5->mSlotExists[v4] = 1;
  v31 = &v22;
  UFG::qString::qString(&v22, &text);
  v14 = v13;
  UFG::qString::qString(&v25, &v20);
  UFG::UIHKScreenSaveLoad::SetSlotText(v5, v4, v15, v14);
  UFG::qString::~qString(&text);
  UFG::qString::~qString(&v20);
}

// File Line: 437
// RVA: 0x62AB10
bool __fastcall UFG::UIHKScreenSaveLoad::handleMessage(UFG::UIHKScreenSaveLoad *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r15
  unsigned int v4; // esi
  UFG::UIHKScreenSaveLoad *v5; // rdi
  Scaleform::GFx::Movie *v6; // rbx
  unsigned int v8; // er8
  UFG::UI *v9; // rcx
  UFG::GameSaveLoad *v10; // rax
  UFG::GameSaveLoad *v11; // rax
  unsigned int v12; // ebx
  const char *v13; // r8
  UFG::UIHKScreenSaveLoad *v14; // rcx
  UFG::UIScreen *v15; // rax
  UFG::UIHKScreenGlobalOverlay *v16; // rcx
  const char *v17; // rdx
  unsigned int v18; // ebx
  UFG::GameSaveLoad *v19; // rax
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-38h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = this->mRenderable->m_movie.pObject;
  if ( !v6 )
    return 0;
  if ( msgId == -1577309891 || msgId == 2134650328 || msgId == -339696135 )
    UFG::UIHKScreenSaveLoad::UpdateSlotText(this);
  switch ( v5->mState )
  {
    case 1:
      if ( v4 == UI_HASH_DPAD_DOWN_PRESSED_30
        || v4 == UI_HASH_DPAD_DOWN_REPEAT_30
        || v4 == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
      {
        if ( !v5->m_bHeadersLoaded )
          return 1;
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xEDB4A8C7,
            0i64,
            0,
            0i64);
        v17 = "ScrollDown";
        goto LABEL_84;
      }
      if ( v4 == UI_HASH_DPAD_UP_PRESSED_30 || v4 == UI_HASH_DPAD_UP_REPEAT_30 || v4 == UI_HASH_THUMBSTICK_LEFT_UP_30 )
      {
        if ( !v5->m_bHeadersLoaded )
          return 1;
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xEDB4A8C7,
            0i64,
            0,
            0i64);
        v17 = "ScrollUp";
LABEL_84:
        Scaleform::GFx::Movie::Invoke(v6, v17, 0i64, 0i64, 0);
        UFG::UIHKScreenSaveLoad::UpdateHelpbar(v5);
        return 1;
      }
      if ( v4 == UI_HASH_BUTTON_BACK_PRESSED_30 )
      {
        if ( v5->m_bHeadersLoaded == 1 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xA4E5BFBD,
              0i64,
              0,
              0i64);
          UFG::UIScreenManagerBase::queuePopScreen(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            v5->mScreenUID);
          v5->mState = 9;
        }
        return 1;
      }
      if ( v4 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( !v5->m_bHeadersLoaded )
          return 1;
        if ( UFG::UIHKScreenSaveLoad::mIsSave )
        {
          if ( !((UFG::HDDmanager::mInstance->m_eSaveLoadPermission >> 1) & 1) )
            return 1;
          v10 = UFG::GameSaveLoad::Instance();
          if ( !UFG::GameSaveLoad::IsSaveAvaliable(v10) )
            return 1;
          if ( UFG::UIHKScreenSaveLoad::mIsSave )
          {
LABEL_39:
            pval.pObjectInterface = 0i64;
            pval.Type = 0;
            Scaleform::GFx::Movie::GetVariable(v6, &pval, "SlotIndex");
            v12 = (signed int)pval.mValue.NValue;
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                0x4A3D1F6Cu,
                0i64,
                0,
                0i64);
            if ( UFG::UIHKScreenSaveLoad::mIsSave )
            {
              if ( v12 != 4 )
              {
                if ( UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[v12].m_State == 3 )
                {
                  v13 = "$SAVELOAD_TRC_OVERWRITE_CORRUPT_SAVE_FILE";
LABEL_53:
                  v14 = v5;
                  goto LABEL_54;
                }
                v14 = v5;
                if ( v5->mSlotExists[v12] )
                {
                  v13 = "$COMMON_TRC_OVERWRITE_SAVE_FILE";
LABEL_54:
                  UFG::UIScreenDialogBox::createYesNoDialog(
                    (UFG::UIScreen *)&v14->vfptr,
                    &customWorldMapCaption,
                    v13,
                    0,
                    1);
                  v5->mState = 3;
                  goto LABEL_55;
                }
                goto LABEL_50;
              }
            }
            else if ( v5->mSlotExists[v12] )
            {
              if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateFE_13 )
              {
                v13 = "$COMMON_TRC_LOAD_SAVE_FILE";
                goto LABEL_53;
              }
              v14 = v5;
LABEL_50:
              if ( UFG::UIHKScreenSaveLoad::StartSaveLoad(v14) )
                UFG::UIHKScreenSaveLoad::ShowPopup(v5);
              goto LABEL_55;
            }
LABEL_55:
            if ( ((unsigned int)pval.Type >> 6) & 1 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
                pval.pObjectInterface,
                &pval,
                *(_QWORD *)&pval.mValue.NValue);
              pval.pObjectInterface = 0i64;
            }
            pval.Type = 0;
            return 1;
          }
        }
        else if ( !(UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) )
        {
          return 1;
        }
        v11 = UFG::GameSaveLoad::Instance();
        if ( !UFG::GameSaveLoad::IsLoadAvaliable(v11) )
          return 1;
        goto LABEL_39;
      }
      if ( v4 == UI_HASH_SAVE_UNAVAILABLE_9 )
      {
        v5->mState = 6;
      }
      else if ( v4 == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
      {
        pval.pObjectInterface = 0i64;
        pval.Type = 0;
        Scaleform::GFx::Movie::GetVariable(v5->mRenderable->m_movie.pObject, &pval, "SlotIndex");
        if ( v5->mSlotExists[(signed int)pval.mValue.NValue] == 1 )
        {
          UFG::UIScreenDialogBox::createYesNoDialog(
            (UFG::UIScreen *)&v5->vfptr,
            &customWorldMapCaption,
            "$COMMON_TRC_DELETE_SAVE_FILE",
            0,
            1);
          v5->mState = 7;
        }
        else if ( UFG::HudAudio::m_instance )
        {
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xA4E5BFBD,
            0i64,
            0,
            0i64);
        }
        if ( ((unsigned int)pval.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
            pval.pObjectInterface,
            &pval,
            *(_QWORD *)&pval.mValue.NValue);
          pval.pObjectInterface = 0i64;
        }
        pval.Type = 0;
      }
      v15 = UFG::UIScreenManagerBase::getOverlay(
              (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
              "GlobalOverlay");
      if ( v15 )
      {
        v16 = UFG::UIHKScreenGlobalOverlay::mThis;
        if ( !UFG::UIHKScreenGlobalOverlay::mThis )
          v16 = &gGlobalOverlaySentinel;
        UFG::UIHKHelpBarWidget::HandleMessage(&v16->HelpBar, v15, v4, v3);
      }
      if ( v4 == UI_HASH_MOUSE_MOVE_30 )
      {
        UFG::UIHKScreenUpgrades::Flash_HandleMouseMove(
          (UFG::UIHKScreenUpgrades *)v5,
          (float)SLODWORD(v3[1].vfptr),
          (float)SHIDWORD(v3[1].vfptr));
      }
      else if ( v4 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
      {
        UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
          (UFG::UIHKScreenUpgrades *)v5,
          (float)SLODWORD(v3[1].vfptr),
          (float)SHIDWORD(v3[1].vfptr));
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    case 3:
      if ( v4 == UI_HASH_DIALOG_NO_30 )
      {
        v5->mState = 1;
        return 1;
      }
      if ( v4 != UI_HASH_DIALOG_YES_30 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      if ( UFG::UIHKScreenSaveLoad::StartSaveLoad(v5) )
        UFG::UIHKScreenSaveLoad::ShowPopup(v5);
      return 1;
    case 4:
      if ( v4 == 1552074461 || v4 == -663456200 )
      {
        if ( UFG::UIHKScreenSaveLoad::mOwner )
        {
          v8 = UFG::UIHKScreenSaveLoad::mOwner->mScreenUID;
          if ( UFG::UIHKScreenSaveLoad::mIsSave )
          {
            UFG::UIScreenManagerBase::queueMessage(
              (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
              UI_HASH_SAVE_COMPLETE_20,
              v8);
          }
          else
          {
            UFG::UIScreenManagerBase::queueMessage(
              (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
              UI_HASH_LOAD_COMPLETE_20,
              v8);
            UFG::UI::HandleGameCheckpointRestore(v9);
          }
          v5->mState = 5;
        }
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
      if ( v4 != 1323471633 && v4 != 2006712458 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      UFG::UIScreenManagerBase::queuePopScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        v5->mPopupDialogScreenUID);
      UFG::UIScreenManagerBase::queuePopScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        v5->mScreenUID);
      return 1;
    case 6:
      if ( v4 == UI_HASH_DIALOG_OK_30 )
      {
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v5->mScreenUID);
        v5->mState = 9;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    case 7:
      if ( v4 == UI_HASH_DIALOG_YES_30 )
      {
        pval.pObjectInterface = 0i64;
        pval.Type = 0;
        Scaleform::GFx::Movie::GetVariable(v5->mRenderable->m_movie.pObject, &pval, "SlotIndex");
        v18 = (signed int)pval.mValue.NValue;
        v19 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::DeleteGameData(v19, v18);
        v5->mState = 8;
        v5->mPopupDialogScreenUID = UFG::UIScreenDialogBox::createZeroButtonDialog(
                                      (UFG::UIScreen *)&v5->vfptr,
                                      &customWorldMapCaption,
                                      "$DELETING_SAVE_DATA",
                                      0,
                                      "DialogBox");
        if ( ((unsigned int)pval.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
            pval.pObjectInterface,
            &pval,
            *(_QWORD *)&pval.mValue.NValue);
          pval.pObjectInterface = 0i64;
        }
        pval.Type = 0;
      }
      else if ( v4 == UI_HASH_DIALOG_NO_30 )
      {
        v5->mState = 1;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    case 8:
      if ( v4 == UI_HASH_DELETE_GAME_COMPLETE_20 )
      {
        v5->m_bHeadersLoaded = 0;
        v5->mState = 1;
        UFG::UIHKScreenSaveLoad::LoadHeaders(v5);
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v5->mPopupDialogScreenUID);
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    default:
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
}  default:
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
}

// File Line: 801
// RVA: 0x6122F0
char __fastcall UFG::UIHKScreenSaveLoad::StartSaveLoad(UFG::UIHKScreenSaveLoad *this)
{
  UFG::UIHKScreenSaveLoad *v1; // rdi
  unsigned int v2; // ebx
  UFG::GameSaveLoad *v3; // rax
  char v4; // bl
  UFG::GameSaveLoad *v5; // rax
  unsigned int v6; // eax
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  v1 = this;
  if ( UFG::UIHKScreenSaveLoad::mIsSave )
  {
    if ( !((UFG::HDDmanager::mInstance->m_eSaveLoadPermission >> 1) & 1) )
      return 0;
  }
  else if ( !(UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) )
  {
    return 0;
  }
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(this->mRenderable->m_movie.pObject, &pval, "SlotIndex");
  v2 = (signed int)pval.mValue.NValue;
  if ( UFG::UIHKScreenSaveLoad::mIsSave )
  {
    v3 = UFG::GameSaveLoad::Instance();
    v4 = UFG::GameSaveLoad::SaveGameSlot(v3, (UFG::GameSaveLoad::eGameSlotNum)v2);
  }
  else
  {
    v5 = UFG::GameSaveLoad::Instance();
    v4 = UFG::GameSaveLoad::LoadGameSlot(v5, (UFG::GameSaveLoad::eGameSlotNum)v2);
    UFG::AudioEventPropertyManager::Reset();
    v6 = _S13_7;
    if ( !(_S13_7 & 1) )
    {
      _S13_7 |= 1u;
      stop_amb_sirens_approaching = UFG::TiDo::CalcWwiseUid("stop_amb_sirens_approaching");
      v6 = _S13_7;
    }
    if ( !(v6 & 2) )
    {
      _S13_7 = v6 | 2;
      stop_siren_approaching = UFG::TiDo::CalcWwiseUid("stop_siren_approaching");
      v6 = _S13_7;
    }
    if ( !(v6 & 4) )
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
  if ( v4 )
    v1->mState = 4;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  pval.Type = 0;
  return v4;
}

// File Line: 851
// RVA: 0x610EC0
void __fastcall UFG::UIHKScreenSaveLoad::ShowPopup(UFG::UIHKScreenSaveLoad *this)
{
  UFG::UIHKScreenSaveLoad *v1; // rbx
  bool v2; // r9
  const char *v3; // r8
  unsigned int v4; // eax

  v1 = this;
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
  v4 = UFG::UIScreenDialogBox::createZeroButtonDialog(
         (UFG::UIScreen *)&this->vfptr,
         &customWorldMapCaption,
         v3,
         v2,
         "DialogBox");
  v1->mElapsedCount = 0.0;
  v1->mPopupDialogScreenUID = v4;
}

// File Line: 872
// RVA: 0x639BB0
void __fastcall UFG::UIHKScreenSaveLoad::queueSaveLoadCommand(UFG::UIScreen *pOwner, bool bSave, bool bFromPauseMenu)
{
  UFG::UIScreen *v3; // rsi
  bool v4; // di
  bool v5; // bl
  UFG::UIScreenTextureManager *v6; // rax

  v3 = pOwner;
  v4 = bSave;
  v5 = bFromPauseMenu;
  if ( !UFG::UIScreenManagerBase::getScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "SaveLoad") )
  {
    UFG::UIHKScreenSaveLoad::mOwner = v3;
    UFG::UIHKScreenSaveLoad::mIsSave = v4;
    UFG::UIHKScreenSaveLoad::m_bFromPauseMenu = v5;
    v6 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v6, "SaveLoad", 0i64);
  }
}

// File Line: 886
// RVA: 0x61A930
void __fastcall UFG::UIHKScreenSaveLoad::UpdateHelpbar(UFG::UIHKScreenSaveLoad *this)
{
  Scaleform::GFx::Movie *v1; // rax
  signed int v2; // ebx
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
  signed __int64 v20; // rdi
  Scaleform::GFx::Value pval; // [rsp+20h] [rbp-D8h]
  __int64 v22; // [rsp+50h] [rbp-A8h]
  UFG::UIHKHelpBarData data; // [rsp+60h] [rbp-98h]

  v22 = -2i64;
  v1 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  if ( v1 )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    Scaleform::GFx::Movie::GetVariable(v1, &pval, "SlotIndex");
    v2 = (signed int)pval.mValue.NValue;
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = UFG::qStringHash32("UIHKScreenSaveLoad", 0xFFFFFFFF);
    data.alignment = 0;
    if ( !UFG::UIHKScreenSaveLoad::mIsSave || v2 != 4 )
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
      data.Buttons[v4] = 1;
      v7 = v4;
      UFG::qString::Set((UFG::qString *)&data.Buttons[10 * v4 + 4], "$COMMON_ACCEPT_UPPERCASE");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v7 + 5] + 32), &customWorldMapCaption);
      *(&data.Icons[5].mStringHash32 + v6) = v3;
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
    data.Buttons[v9] = 2;
    v12 = v9;
    UFG::qString::Set((UFG::qString *)&data.Buttons[10 * v9 + 4], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v12 + 5] + 32), &customWorldMapCaption);
    *(&data.Icons[5].mStringHash32 + v11) = v8;
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
    data.Buttons[v14] = 3;
    v17 = v14;
    UFG::qString::Set((UFG::qString *)&data.Buttons[10 * v14 + 4], "$SAVELOAD_DELETE_GAME");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v17 + 5] + 32), &customWorldMapCaption);
    *(&data.Icons[5].mStringHash32 + v16) = v13;
LABEL_19:
    v18 = &gGlobalOverlaySentinel;
    v19 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v19 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::Show(&v19->HelpBar, &data);
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
      v18 = UFG::UIHKScreenGlobalOverlay::mThis;
    v20 = (signed __int64)&v18->HelpBar;
    *(_BYTE *)(v20 + 1) |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v18->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
    *(_DWORD *)(v20 + 612) = -1046478848;
    UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
    `eh vector destructor iterator'(
      &data.Captions[5].mStringHash32,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator'(&data.Buttons[4], 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    if ( ((unsigned int)pval.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
  }
}

