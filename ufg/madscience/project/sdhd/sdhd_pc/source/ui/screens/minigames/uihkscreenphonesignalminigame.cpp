// File Line: 33
// RVA: 0x1567110
void dynamic_initializer_for__UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos__()
{
  UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos = UFG::qVector3::msZero;
}

// File Line: 37
// RVA: 0x5C6A00
void __fastcall UFG::UIHKScreenPhoneSignalMinigame::UIHKScreenPhoneSignalMinigame(
        UFG::UIHKScreenPhoneSignalMinigame *this)
{
  UFG::SimComponent *ComponentOfType; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpPlayerTNC; // rdx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  ComponentOfType = 0i64;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable;
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhoneSignalMinigame::`vftable;
  p_mpPlayerTNC = &this->mpPlayerTNC;
  this->mpPlayerTNC.mPrev = &this->mpPlayerTNC;
  this->mpPlayerTNC.mNext = &this->mpPlayerTNC;
  this->mpPlayerTNC.m_pPointer = 0i64;
  if ( LocalPlayer )
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  if ( this->mpPlayerTNC.m_pPointer )
  {
    mPrev = p_mpPlayerTNC->mPrev;
    mNext = p_mpPlayerTNC->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpPlayerTNC->mPrev = p_mpPlayerTNC;
    p_mpPlayerTNC->mNext = p_mpPlayerTNC;
  }
  p_mpPlayerTNC->m_pPointer = m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    v7 = m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v7->mNext = p_mpPlayerTNC;
    p_mpPlayerTNC->mPrev = v7;
    p_mpPlayerTNC->mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
    m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mpPlayerTNC;
  }
  if ( LocalPlayer )
    ComponentOfType = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::TargetingSystemPedPlayerComponent::_TypeUID);
  BYTE6(ComponentOfType[54].m_SafePointerList.mNode.mPrev) = 1;
  UFG::SetInputMode_PDA_On(UFG::gActiveControllerNum);
  ++UFG::UIHKGameplayHelpWidget::mLocked;
  ++UFG::UIHK_PDAWidget::mInputLocked;
  UFG::ActivateInputSubMode(ISM_PHONE_SIGNAL, UFG::gActiveControllerNum);
  this->mbMinigamePaused = 0;
}

// File Line: 51
// RVA: 0x5CBF50
void __fastcall UFG::UIHKScreenPhoneSignalMinigame::~UIHKScreenPhoneSignalMinigame(
        UFG::UIHKScreenPhoneSignalMinigame *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::SimComponent *ComponentOfType; // rax
  int v4; // eax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpPlayerTNC; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimComponent *m_pPointer; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhoneSignalMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "PhoneSignalMinigame");
  if ( LocalPlayer )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    if ( ComponentOfType )
      BYTE6(ComponentOfType[54].m_SafePointerList.mNode.mPrev) = 0;
  }
  UFG::DeactivateInputSubMode(ISM_PHONE_SIGNAL, UFG::gActiveControllerNum);
  if ( UFG::UIHK_PDAWidget::mInputLocked )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v4 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v4 = --UFG::UIHKGameplayHelpWidget::mLocked;
    if ( v4 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  p_mpPlayerTNC = &this->mpPlayerTNC;
  if ( this->mpPlayerTNC.m_pPointer )
  {
    mPrev = p_mpPlayerTNC->mPrev;
    mNext = this->mpPlayerTNC.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpPlayerTNC->mPrev = p_mpPlayerTNC;
    this->mpPlayerTNC.mNext = &this->mpPlayerTNC;
  }
  this->mpPlayerTNC.m_pPointer = 0i64;
  m_pPointer = this->mpPlayerTNC.m_pPointer;
  if ( m_pPointer )
    m_pPointer->vfptr->__vecDelDtor(m_pPointer, 1u);
  if ( this->mpPlayerTNC.m_pPointer )
  {
    v9 = p_mpPlayerTNC->mPrev;
    v10 = this->mpPlayerTNC.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    p_mpPlayerTNC->mPrev = p_mpPlayerTNC;
    this->mpPlayerTNC.mNext = &this->mpPlayerTNC;
  }
  this->mpPlayerTNC.m_pPointer = 0i64;
  v11 = p_mpPlayerTNC->mPrev;
  v12 = this->mpPlayerTNC.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  p_mpPlayerTNC->mPrev = p_mpPlayerTNC;
  this->mpPlayerTNC.mNext = &this->mpPlayerTNC;
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen(this);
}

// File Line: 67
// RVA: 0x6353E0
// attributes: thunk
void __fastcall UFG::UIHKScreenScriptableList::init(UFG::UIHKScreenScriptableList *this, UFG::UICommandData *data)
{
  UFG::UIScreen::init(this, data);
}

// File Line: 73
// RVA: 0x63E7A0
void __fastcall UFG::UIHKScreenPhoneSignalMinigame::update(UFG::UIHKScreenPhoneSignalMinigame *this, float elapsed)
{
  Scaleform::GFx::Movie *v3; // rsi
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-48h] BYREF

  if ( this->mbMinigamePaused || UFG::UIScreenManagerBase::getTopScreen(UFG::UIScreenManager::s_instance) )
  {
    pObject = this->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = 0;
    if ( pObject )
      Scaleform::GFx::Movie::SetVariable(pObject, "_root._visible", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
  else
  {
    v3 = this->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = 1;
    if ( v3 )
      Scaleform::GFx::Movie::SetVariable(v3, "_root._visible", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Undefined;
    UFG::UIHKScreenPhoneSignalMinigame::calcArrowPresentation(this, elapsed);
    UFG::UIScreen::update(this, elapsed);
  }
}

// File Line: 111
// RVA: 0x6291E0
bool __fastcall UFG::UIHKScreenPhoneSignalMinigame::handleMessage(
        UFG::UIHKScreenPhoneSignalMinigame *this,
        hkgpIndexedMeshDefinitions::Edge *msgId,
        UFG::UIMessage *msg)
{
  UFG::UIScreenTextureManager *v4; // rax
  unsigned int v5; // eax
  unsigned int mUID; // ebx
  UFG::Music *v7; // rdi
  float v8; // xmm0_4
  UFG::qString v10; // [rsp+38h] [rbp-30h] BYREF
  UFG::qWiseSymbol result; // [rsp+78h] [rbp+10h] BYREF

  if ( (_DWORD)msgId == UI_HASH_SETFINISHED_20 )
  {
    UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "PhoneSignalMinigame");
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v4, "PhoneTraceMinigame", 0i64);
    return 1;
  }
  if ( (_DWORD)msgId == UI_HASH_PLAYSOUND_20 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)this,
            msgId) )
    {
      UFG::qString::qString(&v10, (UFG::qString *)&msg[1]);
      v5 = UFG::TiDo::CalcWwiseUid(v10.mData);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v5, 0i64, 0, 0i64);
      UFG::qString::~qString(&v10);
    }
    return 1;
  }
  if ( (_DWORD)msgId == UI_HASH_MODIFYRTPC_20 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)this,
            msgId) )
    {
      UFG::qString::qString(&v10, (UFG::qString *)&msg[1]);
      UFG::qWiseSymbol::create_from_string(&result, "minigame_progress");
      mUID = result.mUID;
      v7 = UFG::Music::sm_instance;
      v8 = UFG::qToFloat(v10.mData, 0.0);
      UFG::AudioEntity::SetRtpcValue(v7, mUID, v8);
      _((AMD_HD3D *)result.mUID);
      UFG::qString::~qString(&v10);
    }
    return 1;
  }
  if ( (_DWORD)msgId == UI_HASH_CLEANUPMINIGAME_20
    || (_DWORD)msgId == UI_HASH_QUIT_TO_MAIN_MENU_20
    || (_DWORD)msgId == UI_HASH_GAME_RESTART_20 )
  {
    UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "PhoneSignalMinigame");
    return 1;
  }
  if ( (_DWORD)msgId == UI_HASH_GAME_PAUSE_20 )
  {
    this->mbMinigamePaused = 1;
  }
  else if ( (_DWORD)msgId == UI_HASH_GAME_UNPAUSE_20 )
  {
    this->mbMinigamePaused = 0;
  }
  return UFG::UIScreen::handleMessage(this, (unsigned int)msgId, msg);
}

// File Line: 167
// RVA: 0x61E960
void __fastcall UFG::UIHKScreenPhoneSignalMinigame::calcArrowPresentation(
        UFG::UIHKScreenPhoneSignalMinigame *this,
        float elapsed)
{
  float *m_pPointer; // rbx
  __m128 y_low; // xmm3
  float v6; // xmm7_4
  __m128 v7; // xmm1
  float v8; // xmm12_4
  __m128 z_low; // xmm2
  float v10; // xmm1_4
  float v11; // xmm9_4
  float v12; // xmm7_4
  UFG::SimComponent *v13; // rbx
  float v14; // xmm3_4
  __m128 vfptr_high; // xmm4
  __m128 v16; // xmm2
  float v17; // xmm1_4
  float v18; // xmm10_4
  float v19; // xmm10_4
  UFG::InputActionData *v20; // rcx
  bool v21; // al
  bool mbAButton; // bl
  Scaleform::GFx::Movie *pObject; // rcx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-C8h] BYREF
  char v25[16]; // [rsp+60h] [rbp-98h] BYREF
  __int64 v26; // [rsp+70h] [rbp-88h]
  double v27; // [rsp+78h] [rbp-80h]
  char v28[16]; // [rsp+88h] [rbp-70h] BYREF
  __int64 v29; // [rsp+98h] [rbp-60h]
  int v30; // [rsp+A0h] [rbp-58h]
  double v31; // [rsp+A8h] [rbp-50h]
  char v32[16]; // [rsp+B8h] [rbp-40h] BYREF
  __int64 v33; // [rsp+C8h] [rbp-30h]
  int v34; // [rsp+D0h] [rbp-28h]
  double v35; // [rsp+D8h] [rbp-20h]
  char v36[16]; // [rsp+E8h] [rbp-10h] BYREF
  __int64 v37; // [rsp+F8h] [rbp+0h]
  int v38; // [rsp+100h] [rbp+8h]
  __int64 v39; // [rsp+108h] [rbp+10h]
  char v40[16]; // [rsp+118h] [rbp+20h] BYREF
  __int64 v41; // [rsp+128h] [rbp+30h]
  int v42; // [rsp+130h] [rbp+38h]
  double v43; // [rsp+138h] [rbp+40h]
  __int64 v44; // [rsp+148h] [rbp+50h]

  v44 = -2i64;
  m_pPointer = (float *)this->mpPlayerTNC.m_pPointer;
  if ( m_pPointer )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mpPlayerTNC.m_pPointer);
    z_low = (__m128)LODWORD(UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.z);
    y_low = (__m128)LODWORD(UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.y);
    y_low.m128_f32[0] = UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.y - m_pPointer[45];
    v6 = UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.x - m_pPointer[44];
    v7 = y_low;
    v7.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v6 * v6);
    LODWORD(v8) = _mm_sqrt_ps(v7).m128_u32[0];
    z_low.m128_f32[0] = (float)((float)(UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.z - m_pPointer[46])
                              * (float)(UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.z - m_pPointer[46]))
                      + v7.m128_f32[0];
    if ( z_low.m128_f32[0] == 0.0 )
      v10 = 0.0;
    else
      v10 = 1.0 / _mm_sqrt_ps(z_low).m128_f32[0];
    v11 = v10 * y_low.m128_f32[0];
    v12 = v6 * v10;
    v13 = this->mpPlayerTNC.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v13);
    v14 = *(float *)&v13[2].vfptr;
    vfptr_high = (__m128)HIDWORD(v13[2].vfptr);
    v16 = vfptr_high;
    v16.m128_f32[0] = (float)((float)(vfptr_high.m128_f32[0] * vfptr_high.m128_f32[0]) + (float)(v14 * v14))
                    + (float)(*(float *)&v13[2].m_SafePointerList.mNode.mPrev
                            * *(float *)&v13[2].m_SafePointerList.mNode.mPrev);
    if ( v16.m128_f32[0] == 0.0 )
      v17 = 0.0;
    else
      v17 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
    v18 = atan2f(v17 * vfptr_high.m128_f32[0], v17 * v14);
    v19 = (float)(v18 - atan2f(1.0, 0.0)) * 57.295776;
    v20 = UFG::ActionDef_UIAcceptReleased.mDataPerController[UFG::gActiveControllerNum];
    if ( !v20 || (v21 = 1, !v20->mActionTrue) )
      v21 = 0;
    this->mbAButton = v21;
    `eh vector constructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = v8;
    if ( (LOBYTE(v27) & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v26 + 16i64))(
        v26,
        v25,
        COERCE_DOUBLE(*(_QWORD *)&v27));
      v26 = 0i64;
    }
    v27 = v12;
    if ( (v30 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v29 + 16i64))(
        v29,
        v28,
        COERCE_DOUBLE(*(_QWORD *)&v31));
      v29 = 0i64;
    }
    v30 = 5;
    v31 = v11;
    if ( (v34 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v33 + 16i64))(
        v33,
        v32,
        COERCE_DOUBLE(*(_QWORD *)&v35));
      v33 = 0i64;
    }
    v34 = 5;
    v35 = v19;
    mbAButton = this->mbAButton;
    if ( (v38 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v37 + 16i64))(v37, v36, v39);
      v37 = 0i64;
    }
    v38 = 2;
    LOBYTE(v39) = mbAButton;
    if ( (v42 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v41 + 16i64))(
        v41,
        v40,
        COERCE_DOUBLE(*(_QWORD *)&v43));
      v41 = 0i64;
    }
    v42 = 5;
    v43 = elapsed;
    pObject = this->mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "mainLoop", 0i64, &ptr, 6u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

