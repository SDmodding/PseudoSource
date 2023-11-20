// File Line: 33
// RVA: 0x1567110
void dynamic_initializer_for__UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos__()
{
  UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos = UFG::qVector3::msZero;
}

// File Line: 37
// RVA: 0x5C6A00
void __fastcall UFG::UIHKScreenPhoneSignalMinigame::UIHKScreenPhoneSignalMinigame(UFG::UIHKScreenPhoneSignalMinigame *this)
{
  UFG::UIHKScreenPhoneSignalMinigame *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::SimComponent *v3; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // rdx
  UFG::TransformNodeComponent *v5; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  v3 = 0i64;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable;
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhoneSignalMinigame::`vftable;
  v4 = &this->mpPlayerTNC;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->mpPlayerTNC.m_pPointer = 0i64;
  if ( LocalPlayer )
    v5 = LocalPlayer->m_pTransformNodeComponent;
  else
    v5 = 0i64;
  if ( this->mpPlayerTNC.m_pPointer )
  {
    v6 = v4->mPrev;
    v7 = v4->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = (UFG::SimComponent *)&v5->vfptr;
  if ( v5 )
  {
    v8 = v5->m_SafePointerList.mNode.mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mPrev = v8;
    v4->mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  if ( LocalPlayer )
    v3 = UFG::SimObject::GetComponentOfType(
           (UFG::SimObject *)&LocalPlayer->vfptr,
           UFG::TargetingSystemPedPlayerComponent::_TypeUID);
  BYTE6(v3[54].m_SafePointerList.mNode.mPrev) = 1;
  UFG::SetInputMode_PDA_On(UFG::gActiveControllerNum);
  ++UFG::UIHKGameplayHelpWidget::mLocked;
  ++UFG::UIHK_PDAWidget::mInputLocked;
  UFG::ActivateInputSubMode(ISM_PHONE_SIGNAL, UFG::gActiveControllerNum);
  v1->mbMinigamePaused = 0;
}

// File Line: 51
// RVA: 0x5CBF50
void __fastcall UFG::UIHKScreenPhoneSignalMinigame::~UIHKScreenPhoneSignalMinigame(UFG::UIHKScreenPhoneSignalMinigame *this)
{
  UFG::UIHKScreenPhoneSignalMinigame *v1; // rdi
  UFG::UIScreenTextureManager *v2; // rax
  UFG::SimComponent *v3; // rax
  int v4; // eax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v5; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::SimComponent *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhoneSignalMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "PhoneSignalMinigame");
  if ( LocalPlayer )
  {
    v3 = UFG::SimObject::GetComponentOfType(
           (UFG::SimObject *)&LocalPlayer->vfptr,
           UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    if ( v3 )
      BYTE6(v3[54].m_SafePointerList.mNode.mPrev) = 0;
  }
  UFG::DeactivateInputSubMode(ISM_PHONE_SIGNAL, UFG::gActiveControllerNum);
  if ( UFG::UIHK_PDAWidget::mInputLocked )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v4 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v4 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
    if ( v4 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  v5 = &v1->mpPlayerTNC;
  if ( v1->mpPlayerTNC.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mpPlayerTNC.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mpPlayerTNC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpPlayerTNC.mPrev;
  }
  v1->mpPlayerTNC.m_pPointer = 0i64;
  v8 = v1->mpPlayerTNC.m_pPointer;
  if ( v8 )
    v8->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v8->vfptr, 1u);
  if ( v1->mpPlayerTNC.m_pPointer )
  {
    v9 = v5->mPrev;
    v10 = v1->mpPlayerTNC.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mpPlayerTNC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpPlayerTNC.mPrev;
  }
  v1->mpPlayerTNC.m_pPointer = 0i64;
  v11 = v5->mPrev;
  v12 = v1->mpPlayerTNC.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mpPlayerTNC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpPlayerTNC.mPrev;
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen((UFG::UIHKMinigameScreen *)&v1->vfptr);
}

// File Line: 67
// RVA: 0x6353E0
void __fastcall UFG::UIHKScreenScriptableList::init(UFG::UIHKScreenScriptableList *this, UFG::UICommandData *data)
{
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
}

// File Line: 73
// RVA: 0x63E7A0
void __fastcall UFG::UIHKScreenPhoneSignalMinigame::update(UFG::UIHKScreenPhoneSignalMinigame *this, float elapsed)
{
  UFG::UIHKScreenPhoneSignalMinigame *v2; // rdi
  Scaleform::GFx::Movie *v3; // rsi
  Scaleform::GFx::Movie *v4; // rdi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-48h]

  v2 = this;
  if ( this->mbMinigamePaused
    || UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr) )
  {
    v4 = v2->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = 0;
    if ( v4 )
      Scaleform::GFx::Movie::SetVariable(v4, "_root._visible", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
  else
  {
    v3 = v2->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = 1;
    if ( v3 )
      Scaleform::GFx::Movie::SetVariable(v3, "_root._visible", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 0;
    UFG::UIHKScreenPhoneSignalMinigame::calcArrowPresentation(v2, elapsed);
    UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
  }
}

// File Line: 111
// RVA: 0x6291E0
bool __fastcall UFG::UIHKScreenPhoneSignalMinigame::handleMessage(UFG::UIHKScreenPhoneSignalMinigame *this, __int64 msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbx
  UFG::UIScreenTextureManager *v4; // rax
  unsigned int v5; // eax
  unsigned int v6; // ebx
  UFG::Music *v7; // rdi
  float v8; // xmm0_4
  UFG::qString v10; // [rsp+38h] [rbp-30h]
  UFG::qWiseSymbol result; // [rsp+78h] [rbp+10h]

  v3 = msg;
  if ( (_DWORD)msgId == UI_HASH_SETFINISHED_20 )
  {
    UFG::UIScreenManagerBase::queuePopOverlay(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      "PhoneSignalMinigame");
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v4, "PhoneTraceMinigame", 0i64);
    return 1;
  }
  if ( (_DWORD)msgId == UI_HASH_PLAYSOUND_20 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)this,
            (hkgpIndexedMeshDefinitions::Edge *)msgId) )
    {
      UFG::qString::qString(&v10, (UFG::qString *)&v3[1]);
      v5 = UFG::TiDo::CalcWwiseUid(v10.mData);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v5, 0i64, 0, 0i64);
      UFG::qString::~qString(&v10);
    }
    return 1;
  }
  if ( (_DWORD)msgId == UI_HASH_MODIFYRTPC_20 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)this,
            (hkgpIndexedMeshDefinitions::Edge *)msgId) )
    {
      UFG::qString::qString(&v10, (UFG::qString *)&v3[1]);
      UFG::qWiseSymbol::create_from_string(&result, "minigame_progress");
      v6 = result.mUID;
      v7 = UFG::Music::sm_instance;
      v8 = UFG::qToFloat(v10.mData, 0.0);
      UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v7->vfptr, v6, v8);
      _((AMD_HD3D *)result.mUID);
      UFG::qString::~qString(&v10);
    }
    return 1;
  }
  if ( (_DWORD)msgId == UI_HASH_CLEANUPMINIGAME_20
    || (_DWORD)msgId == UI_HASH_QUIT_TO_MAIN_MENU_20
    || (_DWORD)msgId == UI_HASH_GAME_RESTART_20 )
  {
    UFG::UIScreenManagerBase::queuePopOverlay(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      "PhoneSignalMinigame");
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
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&this->vfptr, msgId, msg);
}

// File Line: 167
// RVA: 0x61E960
void __fastcall UFG::UIHKScreenPhoneSignalMinigame::calcArrowPresentation(UFG::UIHKScreenPhoneSignalMinigame *this, float elapsed)
{
  float v2; // xmm11_4
  UFG::UIHKScreenPhoneSignalMinigame *v3; // rdi
  float *v4; // rbx
  __m128 v5; // xmm3
  float v6; // xmm7_4
  __m128 v7; // xmm1
  float v8; // xmm12_4
  __m128 v9; // xmm2
  float v10; // xmm1_4
  float v11; // xmm9_4
  float v12; // xmm7_4
  UFG::SimComponent *v13; // rbx
  float v14; // xmm3_4
  __m128 v15; // xmm4
  __m128 v16; // xmm2
  float v17; // xmm1_4
  float v18; // xmm10_4
  float v19; // xmm10_4
  UFG::InputActionData *v20; // rcx
  char v21; // al
  bool v22; // bl
  Scaleform::GFx::Movie *v23; // rcx
  char ptr; // [rsp+30h] [rbp-C8h]
  __int64 v25; // [rsp+40h] [rbp-B8h]
  unsigned int v26; // [rsp+48h] [rbp-B0h]
  double v27; // [rsp+50h] [rbp-A8h]
  char v28; // [rsp+60h] [rbp-98h]
  __int64 v29; // [rsp+70h] [rbp-88h]
  double v30; // [rsp+78h] [rbp-80h]
  char v31; // [rsp+88h] [rbp-70h]
  __int64 v32; // [rsp+98h] [rbp-60h]
  unsigned int v33; // [rsp+A0h] [rbp-58h]
  double v34; // [rsp+A8h] [rbp-50h]
  char v35; // [rsp+B8h] [rbp-40h]
  __int64 v36; // [rsp+C8h] [rbp-30h]
  unsigned int v37; // [rsp+D0h] [rbp-28h]
  double v38; // [rsp+D8h] [rbp-20h]
  char v39; // [rsp+E8h] [rbp-10h]
  __int64 v40; // [rsp+F8h] [rbp+0h]
  unsigned int v41; // [rsp+100h] [rbp+8h]
  __int64 v42; // [rsp+108h] [rbp+10h]
  char v43; // [rsp+118h] [rbp+20h]
  __int64 v44; // [rsp+128h] [rbp+30h]
  unsigned int v45; // [rsp+130h] [rbp+38h]
  double v46; // [rsp+138h] [rbp+40h]
  __int64 v47; // [rsp+148h] [rbp+50h]

  v47 = -2i64;
  v2 = elapsed;
  v3 = this;
  v4 = (float *)this->mpPlayerTNC.m_pPointer;
  if ( v4 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mpPlayerTNC.m_pPointer);
    v9 = (__m128)LODWORD(UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.z);
    v5 = (__m128)LODWORD(UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.y);
    v5.m128_f32[0] = UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.y - v4[45];
    v6 = UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.x - v4[44];
    v7 = v5;
    v7.m128_f32[0] = (float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(v6 * v6);
    LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v7);
    v9.m128_f32[0] = (float)((float)(UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.z - v4[46])
                           * (float)(UFG::UIHKScreenPhoneSignalMinigame::mDestinationPos.z - v4[46]))
                   + v7.m128_f32[0];
    if ( v9.m128_f32[0] == 0.0 )
      v10 = 0.0;
    else
      v10 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
    v11 = v10 * v5.m128_f32[0];
    v12 = v6 * v10;
    v13 = v3->mpPlayerTNC.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->mpPlayerTNC.m_pPointer);
    v14 = *(float *)&v13[2].vfptr;
    v15 = (__m128)HIDWORD(v13[2].vfptr);
    v16 = v15;
    v16.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14))
                    + (float)(*(float *)&v13[2].m_SafePointerList.mNode.mPrev
                            * *(float *)&v13[2].m_SafePointerList.mNode.mPrev);
    if ( v16.m128_f32[0] == 0.0 )
      v17 = 0.0;
    else
      v17 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
    v18 = atan2f(v17 * v15.m128_f32[0], v17 * v14);
    v19 = (float)(v18 - atan2f(1.0, 0.0)) * 57.295776;
    v20 = UFG::ActionDef_UIAcceptReleased.mDataPerController[UFG::gActiveControllerNum];
    if ( !v20 || (v21 = 1, !v20->mActionTrue) )
      v21 = 0;
    v3->mbAButton = v21;
    `eh vector constructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v26 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v25 + 16i64))(
        v25,
        &ptr,
        COERCE_DOUBLE(*(_QWORD *)&v27));
      v25 = 0i64;
    }
    v26 = 5;
    v27 = v8;
    if ( (LODWORD(v30) >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v29 + 16i64))(
        v29,
        &v28,
        COERCE_DOUBLE(*(_QWORD *)&v30));
      v29 = 0i64;
    }
    v30 = v12;
    if ( (v33 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v32 + 16i64))(
        v32,
        &v31,
        COERCE_DOUBLE(*(_QWORD *)&v34));
      v32 = 0i64;
    }
    v33 = 5;
    v34 = v11;
    if ( (v37 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v36 + 16i64))(
        v36,
        &v35,
        COERCE_DOUBLE(*(_QWORD *)&v38));
      v36 = 0i64;
    }
    v37 = 5;
    v38 = v19;
    v22 = v3->mbAButton;
    if ( (v41 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v40 + 16i64))(v40, &v39, v42);
      v40 = 0i64;
    }
    v41 = 2;
    LOBYTE(v42) = v22;
    if ( (v45 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v44 + 16i64))(
        v44,
        &v43,
        COERCE_DOUBLE(*(_QWORD *)&v46));
      v44 = 0i64;
    }
    v45 = 5;
    v46 = v2;
    v23 = v3->mRenderable->m_movie.pObject;
    if ( v23 )
      Scaleform::GFx::Movie::Invoke(v23, "mainLoop", 0i64, (Scaleform::GFx::Value *)&ptr, 6u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

